#include <iostream>
#include <cstdlib>

using namespace std;

enum en_winner {computer = 1, player = 2, draw = 3};
enum en_game_choice {stone = 1, paper = 2, scissor = 3};

struct st_round_info
{
    short round_number = 0;
    en_game_choice player_choice;
    en_game_choice computer_choice;
    en_winner round_winner;
    string round_winner_name;
};

struct st_full_game_results
{
    short game_rounds = 0;
    short player_winning_times = 0;
    short computer_winning_times = 0;
    short draw_times = 0;
    en_winner final_winner;
    string final_winner_name;
};

int random_number(int from, int to)
{
    int ran_num = rand() % (to - from + 1) + from;
    return ran_num;
}

short read_rounds_number()
{
    short number = 0;
    do
    {
        cout << "How many rounds you want to play? [1 to 10].  ";
        cin >> number;
    } while (number < 1 || number > 10);
    return number;
}

string winner_name(en_winner winner)
{
    string winners[3] = {"computer", "player", "draw"};
    return winners[winner - 1];
}

string game_choice(en_game_choice choice)
{
    string game[3] = {"stone", "paper", "scissor"};
    return game[choice - 1];
}

en_game_choice computer_choice(short number)
{
    return (en_game_choice) number;
}

en_game_choice player_choice()
{
    short choice = 0;
    do
    {
        cout << "Your choice: [1]stone, [2]paper, [3]scissor?  ";
        cin >> choice;
    } while (choice < 1 || choice > 3);
    return (en_game_choice) choice;
}

en_winner round_winner(st_round_info round_info)
{
    if (round_info.computer_choice == round_info.player_choice)
    {
        return en_winner::draw;
    }
    switch (round_info.computer_choice)
    {
        case en_game_choice::stone: // stone > scissor.
        if (round_info.player_choice == en_game_choice::scissor)
        {
            return en_winner::computer;
            break;
        }
        case en_game_choice::paper: // paper > stone.
        if (round_info.player_choice == en_game_choice::stone)
        {
            return en_winner::computer;
            break;
        }
        case en_game_choice::scissor:// scissor > paper.
        if (round_info.player_choice == en_game_choice::paper)
        {
            return en_winner::computer;
            break;
        }
    }
    // player wins if reached here.
    return en_winner::player;
}

void get_winner_color(en_winner winner)
{
    switch (winner)
    {
        case en_winner::computer:
        system("color 4F"); // turn color to red.
        cout << "\a";
        break;
        case en_winner::player:
        system("color 2F"); // turn color to green.
        break;
        default:
        system("color 6F"); // turn the color to yellow.
    }
}

en_winner final_game_winner (st_full_game_results game_results)
{
    if (game_results.computer_winning_times > game_results.player_winning_times)
    {
        return en_winner::computer;
    }
    else if (game_results.player_winning_times > game_results.computer_winning_times)
    {
        return en_winner::player;
    }
    return en_winner::draw;
}

st_full_game_results fill_game_results(short round_numbers, short computer_winning, short player_winning, short draw)
{
    st_full_game_results game_results;
    game_results.game_rounds = round_numbers;
    game_results.player_winning_times = player_winning;
    game_results.computer_winning_times = computer_winning;
    game_results.draw_times = draw;
    game_results.final_winner = final_game_winner(game_results);
    game_results.final_winner_name = winner_name(game_results.final_winner);

    return game_results;
}

void show_round_result(st_round_info round_info)
{
    cout << "\n____________[Round " << round_info.round_number << "]____________\n";
    cout << "Player choice    : " << game_choice(round_info.player_choice) << "\n";
    cout << "Computer choice  : " << game_choice(round_info.computer_choice) << "\n";
    cout << "Round winner     : " << round_info.round_winner_name << "\n";
    cout << "_________________________________\n\n";
}

st_full_game_results play_game(short game_rounds)
{
    short round_numbers = 0, computer_winning = 0, player_winning = 0, draw = 0;
    st_round_info round_info;

    for (int round = 1; round <= game_rounds; round++)
    {
        cout << "\nRound [" << round << "] begins :\n";
        round_info.round_number = round;
        round_info.player_choice = player_choice();
        round_info.computer_choice = computer_choice(random_number(1, 3));
        round_info.round_winner = round_winner(round_info);
        round_info.round_winner_name = winner_name(round_info.round_winner);

        get_winner_color(round_info.round_winner);
        show_round_result(round_info);

        if (round_info.round_winner == en_winner::computer)
        {
            computer_winning++;
        }
        else if (round_info.round_winner == en_winner::player)
        {
            player_winning++;
        }
        else 
        {
            draw++;
        }
    }

    return fill_game_results(round_numbers, computer_winning, player_winning, draw);
}

string tabs(int tabs_number)
{
    string tab = "";
    for (int i = 1 ; i <= tabs_number; i++)
    {
        tab = tab + "\t";
    }
    return tab;
}

void show_game_over_screen()
{
    cout << tabs(2) << "________________________________________\n";
    cout << "\n" << tabs(2) << "        +++ G A M E  O V E R +++        \n";
    cout << tabs(2) << "________________________________________\n";
}

void show_game_results(st_full_game_results game_results)
{
    cout << tabs(2) << "_____________[Game results]_____________\n";
    cout << tabs(2) << "Game rounds         : " << game_results.game_rounds << "\n";
    cout << tabs(2) << "Player won times    : " << game_results.player_winning_times << "\n";
    cout << tabs(2) << "Computer won times  : " << game_results.computer_winning_times << "\n";
    cout << tabs(2) << "Draw times          : " << game_results.draw_times << "\n";
    cout << tabs(2) << "Final winner        : " << game_results.final_winner_name << "\n";
    cout << tabs(2) << "________________________________________" << endl;
}

void reset_game()
{
    system("cls"); // clear the system.
    system("color 0F"); // turn colot to black.
}

void start_game()
{
    char play_again = 'y';
    do
    {
        reset_game();
        st_full_game_results game_results = play_game(read_rounds_number());
        show_game_over_screen();
        show_game_results(game_results);

        cout << tabs(2) << "Do you want to play again? [Y/N]    ";
        cin >> play_again;
    } while (play_again == 'y' || play_again == 'Y');
}

int main()
{
    srand((unsigned)time(NULL));

    start_game();

    return 0;
}

/*
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

enum en_stone_paper_scissor { stone = 1, paper = 2, scissor = 3 };

int read_positive_number(string message)
{
    int number = 0;
    do
    {
        cout << message << endl;
        cin >> number;
    } while (number <= 0);
    return number;
}

int random_number(int from, int to)
{
    int ran_num = rand() % (to - from + 1) + from;
    return ran_num;
}

string game_choice(short number)
{
    switch (number)
    {
    case en_stone_paper_scissor::stone:
        return "stone";
        break;
    case en_stone_paper_scissor::paper:
        return "paper";
        break;
    default:
        return "scissor";
    }
}

string round_winner(string computer, string player, short& draw, short& computer_winning, short& palyer_winning)
{
    if (player == "scissor" && computer == "stone" || player == "stone" && computer == "paper" || player == "paper" && computer == "scissor")
    {
        computer_winning++;
        system("Color 4f");
        return "[computer wins]\a";
    }
    else if (computer == "scissor" && player == "stone" || computer == "stone" && player == "paper" || computer == "paper" && player == "scissor")
    {
        palyer_winning++;
        system("Color 2f");
        return "[Player wins]";
    }
    else
    {
        draw++;
        system("Color 6f");
        return "[No winner]";
    }
}

void print_round(short& draw, short& computer_winning, short& palyer_winning, short round_number)
{
    cout << "Round " << round_number << " begins:\n";
    string player = game_choice(read_positive_number("Your choice: [1]stone, [2]paper, [3]scissor"));;
    string computer = game_choice(random_number(1, 3));
    cout << "________ Round [" << round_number << "] ________\n";
    cout << "player   choice: " << player << "\n";
    cout << "Computer choice: " << computer << "\n";
    cout << "Round winner   : " << round_winner(computer, player, draw, computer_winning, palyer_winning) << "\n";
    cout << "___________________________" << endl;
}

void reset_game(short& draw, short& computer_winning, short& palyer_winning, int& total_round_numbers)
{
    computer_winning = 0;
    palyer_winning = 0;
    draw = 0;
    total_round_numbers = 0;
    system("Color 0f");
}

string final_winner(short computer_winning, short palyer_winning, short draw)
{
    if (computer_winning > palyer_winning && computer_winning >= draw)
    {
        return "Computer";
    }
    else if (palyer_winning > computer_winning && palyer_winning >= draw)
    {
        return "Player";
    }
    else
    {
        return "[No winner]";
    }
}

void print_game_result(int total_round_numbers, short computer_winning, short palyer_winning, short draw)
{
    cout << "\n\t\t_____________________________________________\n";
    cout << "\t\t          +++ G A M E   O V E R +++          \n";
    cout << "\t\t_____________________________________________\n";
    cout << "\t\t_________________[ Game Result ]_____________\n";
    cout << "\t\tGame Rounds            : " << total_round_numbers << "\n";
    cout << "\t\tPlayer winning times   : " << palyer_winning << "\n";
    cout << "\t\tComputer winning times : " << computer_winning << "\n";
    cout << "\t\tDraw times             : " << draw << "\n";
    cout << "\t\tFinal winner           : " << final_winner(computer_winning, palyer_winning, draw) << "\n";
    cout << "\t\t_____________________________________________\n" << endl;
}

bool play_again()
{
    char yes_no;
    cout << "Do you want to play again? Y/N\n";
    cin >> yes_no;

    if (yes_no == 'y' || yes_no == 'Y')
    {
        return true;
    }
    return false;
}
void start_the_game(int total_round_numbers, short draw, short computer_winning, short player_winning)
{
    do
    {
        reset_game(draw, computer_winning, player_winning, total_round_numbers);
        total_round_numbers = read_positive_number("How many rounds you want to play?");
        for (int i = 1; i <= total_round_numbers; i++)
        {
            print_round(draw, computer_winning, player_winning, i);
        }
        print_game_result(total_round_numbers, computer_winning, player_winning, draw);
    } while (play_again());
}

int main()
{
    srand((unsigned)time(NULL));

    int total_round_numbers = 0;
    short draw = 0, computer_winning = 0, player_winning = 0;

    start_the_game(total_round_numbers, draw, computer_winning, player_winning);

    return 0;
}
*/