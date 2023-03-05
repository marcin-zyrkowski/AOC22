#include<bits/stdc++.h>


using namespace std;

struct Monkey
{
    enum oper_e {eSUM, eMUL};
    
    Monkey(int a_number) : number(a_number) 
    {
        cout << "constructing Monkey: " << a_number << endl;
    };

    void set_operation(int v, oper_e a_operation) noexcept
    {
        operation_operand = v;
        if (a_operation == Monkey::eMUL)
        {
            operation = [operation_operand = this->operation_operand
            , self_operation = this->self_operation](int old_level)
            {
                if (self_operation)
                {
                    return old_level * old_level;
                }
                return old_level * operation_operand;
            };
            
        }
        else if (a_operation == Monkey::eSUM)
        {
            auto sumka = [operation_operand = this->operation_operand
            , self_operation = this->self_operation](int old_level) 
            {
                if (self_operation)
                {
                    return old_level * old_level;
                }                
                return old_level + operation_operand;
            };

            operation = sumka;
        }
    }

    void set_test_operand(int v) noexcept
    {
        test_operand = v;
    }

    void add_item(int v)
    {
        worry_level.push_back(v);
    }

    void set_monkeys_to_throw(int if_true, int if_false) noexcept
    {
        monkey_to_throw_if_true = if_true;
        monkey_to_throw_if_false = if_false;
    }

    void set_self_operation() noexcept
    {
        self_operation = true;
    }

    void turn(std::function<void(int,int)> throw_to_monkey)
    {
        cout << "Monkey " << number << ":" << endl;
        while (!worry_level.empty())
        {
            inspected++;
            int level = worry_level.front();
            worry_level.pop_front();
            cout << "\tMonkey inspects an item with a worry level of " << level << endl;
            level = operation(level);
            cout << "\t\tWorry level is bla bla to " << level << endl;
            level /= 3;
            cout << "\t\tMonkey gets bored with item. Worry level is divided by 3 to " << level << endl;
            if (0 == level%test_operand)
            {
                //level /= test_operand;
                cout << "\t\tCurrent worry level is divisible by " << test_operand << endl;
                cout << "\t\tItem with worry level " << level << " is thrown to monkey " << monkey_to_throw_if_true << endl;
                throw_to_monkey(monkey_to_throw_if_true, level);
            }
            else
            {
                cout << "\t\tCurrent worry level is not divisible by " << test_operand << endl;
                cout << "\t\tItem with worry level " << level << " is thrown to monkey " << monkey_to_throw_if_false << endl;
                throw_to_monkey(monkey_to_throw_if_false, level);
            }
        }
    }

    void print_levels() const
    {
        cout << "Monkey " << number << ": ";
        for (auto level : worry_level)
        {
            cout << level << ", ";
        }
        cout << " inspected: " << inspected << endl;
    }

    int get_inspected() const noexcept
    {
        return inspected;
    }

    private:
        int number {0};
        std::deque<int> worry_level {};
        std::function<int(int)> operation;
        int operation_operand {0};
        bool self_operation {false};
        int test_operand {0};
        int monkey_to_throw_if_true {0};
        int monkey_to_throw_if_false {0};
        int inspected{0};

};

void print_levels(std::vector<Monkey>& monkeys)
{
    for (const auto& monkey : monkeys)
    {
        monkey.print_levels();
    }
}

void print_sorted_inspected(std::vector<Monkey>& monkeys)
{
    std::list<int> inspections{};
    for (const auto& monkey : monkeys)
    {
        inspections.push_back(monkey.get_inspected());
    }
    inspections.sort();
    for (auto v : inspections)
    {
        cout << v << ", ";
    }
    cout << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    //freopen("input_example.txt", "r", stdin);

    std::vector<Monkey> monkeys {};

    auto throw_to_monkey = [&] (int monkey, int level) {
        monkeys[monkey].add_item(level);
    };

    string s;
    while(getline(cin, s))
    {
        if (s.find("Monkey") != std::string::npos) 
        {
            // Monkey 0:
            string temp = s.substr(7);
            temp = temp.substr(0, temp.find(":"));
            int number = stoi(temp);
            monkeys.push_back(Monkey(number));

            //   Starting items: 79, 98
            getline(cin, s);
            temp = s.substr(18);
            char* token;
            char delims[] = ", ";
            token = strtok(const_cast<char*>(temp.c_str()), delims);
            while (token != NULL)
            {
                monkeys[number].add_item(atoi(token));
                token = strtok(NULL, delims);
            }
            //   Operation: new = old * 19
            getline(cin, s);
            int operation_operand = 0;
            temp = s.substr(25);
            if ("old" == temp)
            {
                monkeys[number].set_self_operation();
            }
            else 
            {
                operation_operand = stoi(temp);
            }
            
            if (s.find("+") != std::string::npos)
            {
                monkeys[number].set_operation(operation_operand, Monkey::eSUM);
            }
            else
            {
                monkeys[number].set_operation(operation_operand, Monkey::eMUL);
            }
            //   Test: divisible by 23
            getline(cin, s);
            int test_operand = stoi(s.substr(21));
            monkeys[number].set_test_operand(test_operand);
            //     If true: throw to monkey 2
            //     If false: throw to monkey 3
            getline(cin, s);
            int if_true = stoi(s.substr(29));
            getline(cin, s);
            int if_false = stoi(s.substr(30));
            monkeys[number].set_monkeys_to_throw(if_true, if_false);
        }
    }

    for (size_t i = 0; i < 20; i++)
    {
        for (auto& monkey : monkeys)
        {
            monkey.turn(throw_to_monkey);
        }
        print_levels(monkeys);
    }
    print_sorted_inspected(monkeys);
    return 0;
}