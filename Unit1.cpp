//---------------------------------------------------------------------------

#include <vcl.h>
#include <jpeg.hpp>
#include <stdio.h>
#include <string>
#include <time.h>
#include <stdlib.h>
#pragma hdrstop

#include "Unit1.h"

//color: red = 1, blue = 2, green = 3, purple = 4
//CoubSum - сумма чисел правого и левого кубика
//MovesLeft - сколько осталось ходов
//DoubleMoves - Сколько подряд выпало дублей
//fields - массив полей, которыми обладает игрок
typedef
        struct PlayerProfile {
        //char *name;
        AnsiString name;
        int cash, color, CoubSum, MovesLeft, DoubleMoves;
        int fields[28], CurrentField;
        int amountoffields;
        struct PlayerProfile *next;
        } player;

typedef
         struct Fields {                   
                char name[30];
                int cost, number;
                int pay, star1, star2, star3, star4, BigStar;
                int players, owner;
        } F;

const int StartMoney = 15000;
const int Lap = 2000, LapBonus = 1000;
int AmountOfPlayers = 0, HideGroupBox = 0;
F field[40];
player *pl, *head;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMonopoly *Monopoly;
//---------------------------------------------------------------------------
__fastcall TMonopoly::TMonopoly(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void ShowButtons() {
        Monopoly -> BitBtn1 -> Show();
        Monopoly -> Chat -> Show();
        Monopoly -> Chat -> Show();
        Monopoly -> StartGameButton -> Show();
        Monopoly -> AddPlayer1 -> Show();
        Monopoly -> SendMessageButton -> Show();
        Monopoly -> SendMessageButton -> Enabled = false;
        Monopoly -> Edit1 -> Show();
        Monopoly -> Edit1 -> Enabled = false;
        Monopoly -> Chat -> Lines -> Text = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        Monopoly -> Chanel -> Show();
        Monopoly -> HugoBoss -> Show();
        Monopoly -> Mercedes -> Show();
        Monopoly -> Adidas -> Show();
        Monopoly -> Puma -> Show();
        Monopoly -> Lacoste -> Show();
        Monopoly -> Vk -> Show();
        Monopoly -> Rovio -> Show();
        Monopoly -> Facebook -> Show();
        Monopoly -> Twitter -> Show();
        Monopoly -> Audi -> Show();
        Monopoly -> CocaCola -> Show();
        Monopoly -> Fanta -> Show();
        Monopoly -> Pepsi -> Show();
        Monopoly -> BritishAirways -> Show();
        Monopoly -> AmericanAirlines -> Show();
        Monopoly -> Lufthansa -> Show();
        Monopoly -> Ford -> Show();
        Monopoly -> McDonalds -> Show();
        Monopoly -> KFC -> Show();
        Monopoly -> RockstarGames -> Show();
        Monopoly -> BurgerKing -> Show();
        Monopoly -> Novotel -> Show();
        Monopoly -> Radisson -> Show();
        Monopoly -> HolidayInn -> Show();
        Monopoly -> LandRover -> Show();
        Monopoly -> Apple -> Show();
        Monopoly -> Nokia -> Show();
}

void HideButtons() {
        Monopoly -> BitBtn1 -> Hide();
        Monopoly -> Chat -> Hide();
        Monopoly -> AddPlayer1 -> Hide();
        Monopoly -> AddPlayer2 -> Hide();
        Monopoly -> AddPlayer3 -> Hide();
        Monopoly -> AddPlayer4 -> Hide();
        Monopoly -> Player1Shape -> Hide();
        Monopoly -> Player2Shape -> Hide();
        Monopoly -> Player3Shape -> Hide();
        Monopoly -> Player4Shape -> Hide();
        Monopoly -> GroupBox1 -> Hide();
        Monopoly -> GroupBox2 -> Hide();
        Monopoly -> Panel15 -> Hide();
        Monopoly -> Panel16 -> Hide();
        Monopoly -> SendMessageButton -> Hide();
        Monopoly -> Edit1 -> Hide();
        Monopoly -> Chanel -> Hide();
        Monopoly -> HugoBoss -> Hide();
        Monopoly -> Mercedes -> Hide();
        Monopoly -> Adidas -> Hide();
        Monopoly -> Puma -> Hide();
        Monopoly -> Lacoste -> Hide();
        Monopoly -> Vk -> Hide();
        Monopoly -> Rovio -> Hide();
        Monopoly -> Facebook -> Hide();
        Monopoly -> Twitter -> Hide();
        Monopoly -> Audi -> Hide();
        Monopoly -> CocaCola -> Hide();
        Monopoly -> Fanta -> Hide();
        Monopoly -> Pepsi -> Hide();
        Monopoly -> BritishAirways -> Hide();
        Monopoly -> AmericanAirlines -> Hide();
        Monopoly -> Lufthansa -> Hide();
        Monopoly -> Ford -> Hide();
        Monopoly -> McDonalds -> Hide();
        Monopoly -> KFC -> Hide();
        Monopoly -> RockstarGames -> Hide();
        Monopoly -> BurgerKing -> Hide();
        Monopoly -> Novotel -> Hide();
        Monopoly -> Radisson -> Hide();
        Monopoly -> HolidayInn -> Hide();
        Monopoly -> LandRover -> Hide();
        Monopoly -> Apple -> Hide();
        Monopoly -> Nokia -> Hide();
        Monopoly -> Player1 -> Hide();
        Monopoly -> Player2 -> Hide();
        Monopoly -> Player3 -> Hide();
        Monopoly -> Player4 -> Hide();
        Monopoly -> Panel1 -> Hide();
        Monopoly -> Panel2 -> Hide();
        Monopoly -> Panel3 -> Hide();
        Monopoly -> Panel4 -> Hide();
        Monopoly -> Label3 -> Hide();
        Monopoly -> GroupBox3 -> Hide();
}

void ShowFields() {
        Monopoly -> Image1 -> Show();
        Monopoly -> Image2 -> Show();
        Monopoly -> Image3 -> Show();
        Monopoly -> Image4 -> Show();
        Monopoly -> Image5 -> Show();
        Monopoly -> Image6 -> Show();
        Monopoly -> Image7 -> Show();
        Monopoly -> Image8 -> Show();
        Monopoly -> Image9 -> Show();
        Monopoly -> Image10 -> Show();
        Monopoly -> Image11 -> Show();
        Monopoly -> Image12 -> Show();
        Monopoly -> Image13 -> Show();
        Monopoly -> Image14 -> Show();
        Monopoly -> Image15 -> Show();
        Monopoly -> Image16 -> Show();
        Monopoly -> Image17 -> Show();
        Monopoly -> Image18 -> Show();
        Monopoly -> Image19 -> Show();
        Monopoly -> Image20 -> Show();
        Monopoly -> Image21 -> Show();
        Monopoly -> Image22 -> Show();
        Monopoly -> Image23 -> Show();
        Monopoly -> Image24 -> Show();
        Monopoly -> Image25 -> Show();
        Monopoly -> Image26 -> Show();
        Monopoly -> Image27 -> Show();
        Monopoly -> Image28 -> Show();
        Monopoly -> Image29 -> Show();
        Monopoly -> Image30 -> Show();
        Monopoly -> Image31 -> Show();
        Monopoly -> Image32 -> Show();
        Monopoly -> Image33 -> Show();
        Monopoly -> Image34 -> Show();
        Monopoly -> Image35 -> Show();
        Monopoly -> Image36 -> Show();
        Monopoly -> Image37 -> Show();
        Monopoly -> Image38 -> Show();
        Monopoly -> Image39 -> Show();
        Monopoly -> Image40 -> Show();
}

void HideFields() {
        Monopoly -> Image1 -> Hide();
        Monopoly -> Image2 -> Hide();
        Monopoly -> Image3 -> Hide();
        Monopoly -> Image4 -> Hide();
        Monopoly -> Image5 -> Hide();
        Monopoly -> Image6 -> Hide();
        Monopoly -> Image7 -> Hide();
        Monopoly -> Image8 -> Hide();
        Monopoly -> Image9 -> Hide();
        Monopoly -> Image10 -> Hide();
        Monopoly -> Image11 -> Hide();
        Monopoly -> Image12 -> Hide();
        Monopoly -> Image13 -> Hide();
        Monopoly -> Image14 -> Hide();
        Monopoly -> Image15 -> Hide();
        Monopoly -> Image16 -> Hide();
        Monopoly -> Image17 -> Hide();
        Monopoly -> Image18 -> Hide();
        Monopoly -> Image19 -> Hide();
        Monopoly -> Image20 -> Hide();
        Monopoly -> Image21 -> Hide();
        Monopoly -> Image22 -> Hide();
        Monopoly -> Image23 -> Hide();
        Monopoly -> Image24 -> Hide();
        Monopoly -> Image25 -> Hide();
        Monopoly -> Image26 -> Hide();
        Monopoly -> Image27 -> Hide();
        Monopoly -> Image28 -> Hide();
        Monopoly -> Image29 -> Hide();
        Monopoly -> Image30 -> Hide();
        Monopoly -> Image31 -> Hide();
        Monopoly -> Image32 -> Hide();
        Monopoly -> Image33 -> Hide();
        Monopoly -> Image34 -> Hide();
        Monopoly -> Image35 -> Hide();
        Monopoly -> Image36 -> Hide();
        Monopoly -> Image37 -> Hide();
        Monopoly -> Image38 -> Hide();
        Monopoly -> Image39 -> Hide();
        Monopoly -> Image40 -> Hide();
}

int GetRandomNumber(void) {
        int result = 0;             
	result = 1 + (rand() % 6);
        return result;
}

void ColorPlayer() {
        if (pl -> color == 1) Monopoly -> Player1 -> Color = clRed;
        else if (pl -> color == 2) Monopoly -> Player2 -> Color = clBlue;
        else if (pl -> color == 3) Monopoly -> Player3 -> Color = clLime;
        else Monopoly -> Player4 -> Color = clPurple;
}

void ReadFromFile(F *field, char *path) {
        int count = 0;
        FILE* f = fopen(path, "r");
        while (!(feof(f))){
                fscanf(f, "%s %d %d %d %d %d %d %d %d", field[count].name, &field[count].cost, &field[count].number, &field[count].pay, &field[count].star1, &field[count].star2, &field[count].star3, &field[count].star4, &field[count].BigStar);
                field[count].players = 0;
                field[count].owner = 0;
                count++;
        }
        fclose(f);
}

void ViewInChat(int LeftCoub, int RightCoub) {
        const int jail = 10, gotojail = 30, jackpot = 20;     
        AnsiString str;
        str = field[pl -> CurrentField].name;
        Monopoly -> Chat -> Lines -> Add(AnsiString(pl -> name) + " выбрасывает " + AnsiString(LeftCoub) + ":" + AnsiString(RightCoub));

        if ((field[pl -> CurrentField].cost != 0) && (pl -> CurrentField != 4) && (pl -> CurrentField != 36)) {
                if ((field[pl -> CurrentField].owner != 0) && (field[pl -> CurrentField].owner != pl -> color)) Monopoly -> Chat -> Lines -> Add(AnsiString(pl -> name) + " попадает на " + str + " и должен заплатить аренду " + AnsiString(field[pl -> CurrentField].pay) + "k");
                else if ((field[pl -> CurrentField].owner != 0) && (field[pl -> CurrentField].owner == pl -> color)) Monopoly -> Chat -> Lines -> Add(AnsiString(pl -> name) + " попадает на своё поле и ничего не платит");
                else Monopoly -> Chat -> Lines -> Add(AnsiString(pl -> name) + " попадает на " + str + " и задумывается о покупке");
        } else if ((pl -> CurrentField == 4) || (pl -> CurrentField == 36)) Monopoly -> Chat -> Lines -> Add(AnsiString(pl -> name) + " попадает на Налог и должен заплатить " + AnsiString(field[pl -> CurrentField].cost) + "k");
        else if ((pl -> CurrentField == 2) || (pl -> CurrentField == 7) || (pl -> CurrentField == 17) || (pl -> CurrentField == 22) || (pl -> CurrentField == 33) || (pl -> CurrentField == 38)) Monopoly -> Chat -> Lines -> Add(AnsiString(pl -> name) + " попадает на поле " + str);
        else if (pl -> CurrentField == jail) Monopoly -> Chat -> Lines -> Add(AnsiString(pl -> name) + " попадает на экскурсию в тюрьму");
        else if (pl -> CurrentField == gotojail) Monopoly -> Chat -> Lines -> Add(AnsiString(pl -> name) + " отправляется в тюрьму за мошенничество");
        else if (pl -> CurrentField == jackpot) Monopoly -> Chat -> Lines -> Add(AnsiString(pl -> name) + " попадает на Джекпот и может попытать удачу ");
        else ShowMessage("что-то не то");
}

void DrawCoubes(int LeftCoub, int RightCoub) {
        switch (LeftCoub) {
                case 1: Monopoly -> Coub1 -> Picture -> LoadFromFile("images/BMP/Coub/1.bmp");
                        break;
                case 2: Monopoly -> Coub1 -> Picture -> LoadFromFile("images/BMP/Coub/2.bmp");
                        break;
                case 3: Monopoly -> Coub1 -> Picture -> LoadFromFile("images/BMP/Coub/3.bmp");
                        break;
                case 4: Monopoly -> Coub1 -> Picture -> LoadFromFile("images/BMP/Coub/4.bmp");
                        break;
                case 5: Monopoly -> Coub1 -> Picture -> LoadFromFile("images/BMP/Coub/5.bmp");
                        break;
                case 6: Monopoly -> Coub1 -> Picture -> LoadFromFile("images/BMP/Coub/6.bmp");
                        break;
        }
        switch (RightCoub) {
                case 1: Monopoly -> Coub2 -> Picture -> LoadFromFile("images/BMP/Coub/1.bmp");
                        break;
                case 2: Monopoly -> Coub2 -> Picture -> LoadFromFile("images/BMP/Coub/2.bmp");
                        break;
                case 3: Monopoly -> Coub2 -> Picture -> LoadFromFile("images/BMP/Coub/3.bmp");
                        break;
                case 4: Monopoly -> Coub2 -> Picture -> LoadFromFile("images/BMP/Coub/4.bmp");
                        break;
                case 5: Monopoly -> Coub2 -> Picture -> LoadFromFile("images/BMP/Coub/5.bmp");
                        break;
                case 6: Monopoly -> Coub2 -> Picture -> LoadFromFile("images/BMP/Coub/6.bmp");
                        break;
        }
}

void ShowMoney() {
        switch (pl -> color) {
                case 1: Monopoly -> Player1Money -> Caption = "$" + IntToStr(pl -> cash) + "k";
                        break;
                case 2: Monopoly -> Player2Money -> Caption = "$" + IntToStr(pl -> cash) + "k";
                        break;
                case 3: Monopoly -> Player3Money -> Caption = "$" + IntToStr(pl -> cash) + "k";
                        break;
                case 4: Monopoly -> Player4Money -> Caption = "$" + IntToStr(pl -> cash) + "k";
                        break;
                }
}

void NextPlayer() {
        if (pl -> MovesLeft == 0) {
                Monopoly -> Player1 -> Color = clSilver;
                Monopoly -> Player2 -> Color = clSilver;
                Monopoly -> Player3 -> Color = clSilver;
                Monopoly -> Player4 -> Color = clSilver;
                HideGroupBox = 1;
                if (pl -> next == NULL) {
                        pl = head;
                }
                pl = pl -> next;
                ColorPlayer();
                Monopoly -> GroupBox2 -> Hide();
        }
}

void MovePlayer(int X, int Y) {
        switch (pl -> color) {
                case 1: Monopoly -> Player1Shape -> Top = Y;
                        Monopoly -> Player1Shape -> Left = X;
                        break;
                case 2: Monopoly -> Player2Shape -> Top = Y;
                        Monopoly -> Player2Shape -> Left = X;
                        break;
                case 3: Monopoly -> Player3Shape -> Top = Y;
                        Monopoly -> Player3Shape -> Left = X;
                        break;
                case 4: Monopoly -> Player4Shape -> Top = Y;
                        Monopoly -> Player4Shape -> Left = X;
                        break;
        }
}

int PlayJackpod() {
        int result = GetRandomNumber();
        switch (result) {
                case 1: Monopoly -> Coub1 -> Picture -> LoadFromFile("images/BMP/Coub/1.bmp");
                        break;
                case 2: Monopoly -> Coub1 -> Picture -> LoadFromFile("images/BMP/Coub/2.bmp");
                        break;
                case 3: Monopoly -> Coub1 -> Picture -> LoadFromFile("images/BMP/Coub/3.bmp");
                        break;
                case 4: Monopoly -> Coub1 -> Picture -> LoadFromFile("images/BMP/Coub/4.bmp");
                        break;
                case 5: Monopoly -> Coub1 -> Picture -> LoadFromFile("images/BMP/Coub/5.bmp");
                        break;
                case 6: Monopoly -> Coub1 -> Picture -> LoadFromFile("images/BMP/Coub/6.bmp");
                        break;
        }
        return result;
}

void HidePanels() {
        Monopoly -> Panel1 -> Hide();
        Monopoly -> Panel2 -> Hide();
        Monopoly -> Panel3 -> Hide();
        Monopoly -> Panel4 -> Hide();
}

void AddPlayerToList() {
        AmountOfPlayers++;
        pl -> next = (struct PlayerProfile*)malloc(sizeof(struct PlayerProfile));
        pl = pl -> next;
        pl -> cash = StartMoney;
        pl -> CoubSum = 0;
        pl -> amountoffields = 0;
        pl -> MovesLeft = 1;
        pl -> DoubleMoves = 0;
        pl -> CurrentField = 0;
        pl -> next = NULL;
}

void __fastcall TMonopoly::StartGameButtonClick(TObject *Sender)
{
        ShowButtons();
        ShowFields();
        StartGameButton -> Hide();
}
//---------------------------------------------------------------------------

void __fastcall TMonopoly::FormCreate(TObject *Sender)
{
        char *path = "Fields.txt";
        ReadFromFile(field, path);
        HideButtons();
        HideFields();
}
//---------------------------------------------------------------------------


void __fastcall TMonopoly::AddPlayer1Click(TObject *Sender)
{
        Player1 -> Show();
        Image41 -> Show();
}
//---------------------------------------------------------------------------

//color: red = 1, blue = 2, green = 3, purple = 4
//CoubSum - сумма чисел правого и левого кубика
//MovesLeft - сколько осталось ходов
//DoubleMoves - Сколько подряд выпало дублей
//fields - массив полей, которыми обладает игрок
void __fastcall TMonopoly::Player1ReadyClick(TObject *Sender)
{
        if (Player1Nickname -> Text.Length() != 0) {
                head = (struct PlayerProfile*)malloc(sizeof(struct PlayerProfile));
                pl = head;
                pl -> next = NULL;

                AddPlayerToList();
                pl -> color = 1;
                pl -> name = Player1Nickname -> Text.c_str();
                Player1Name -> Caption = Player1Nickname -> Text;
                Player1Money -> Caption = "$" + IntToStr(pl -> cash) + "k";
                Player1Nickname -> Hide();
                Player1Ready -> Hide();
                Player1Money -> Show();
                Player2 -> Show();
        } else ShowMessage("Вы не написали ник");
}
//---------------------------------------------------------------------------


void __fastcall TMonopoly::Player2ReadyClick(TObject *Sender)
{
        if (Player2Nickname -> Text.Length() != 0) {
                AddPlayerToList();
                pl -> color = 2;
                pl -> name = Player2Nickname -> Text.c_str();
                Player2Name -> Caption = Player2Nickname -> Text;
                Player2Money -> Caption = "$" + IntToStr(pl -> cash) + "k";
                Player2Nickname -> Hide();
                Player2Ready -> Hide();
                Player2Money -> Show();
                Player3 -> Show();
        } else ShowMessage("Вы не написали ник");
}
//---------------------------------------------------------------------------

void __fastcall TMonopoly::Player3ReadyClick(TObject *Sender)
{
        if (Player3Nickname -> Text.Length() != 0) {
                AddPlayerToList();
                pl -> color = 3;
                pl -> name = Player3Nickname -> Text.c_str();
                Player3Name -> Caption = Player3Nickname -> Text;
                Player3Money -> Caption = "$" + IntToStr(pl -> cash) + "k";
                Player3Nickname -> Hide();
                Player3Ready -> Hide();
                Player3Money -> Show();
                Player4 -> Show();
        } else ShowMessage("Вы не написали ник");
}
//---------------------------------------------------------------------------

void __fastcall TMonopoly::Player4ReadyClick(TObject *Sender)
{
        if (Player4Nickname -> Text.Length() != 0) {
                AddPlayerToList();
                pl -> color = 4;
                pl -> name = Player4Nickname -> Text.c_str();
                Player4Name -> Caption = Player4Nickname -> Text;
                Player4Money -> Caption = "$" + IntToStr(pl -> cash) + "k";
                Player4Nickname -> Hide();
                Player4Ready -> Hide();                                     
                Player4Money -> Show();

        } else ShowMessage("Вы не написали ник");
}
//---------------------------------------------------------------------------

void __fastcall TMonopoly::BitBtn2Click(TObject *Sender)
{
        const int deltaX = 53, deltaY = 53;
        const int YTop = 63, XRight = 1015, YBottom = 645, XLeft = 432;
        const int XTop = 512, YRight = 140, XBottom = 936, YLeft = 565;
        const int jail = 10, jackpot = 20, gotojail = 30, start = 0;
        int X = 0, Y = 0;
        int LeftCoub = 0, RightCoub = 0;
        int RandomNumber = 0;
        int more = 0;

        HideGroupBox = 0;
        HidePanels();
        GroupBox1 -> Hide();
        srand(time(NULL));
        LeftCoub = GetRandomNumber();
	RightCoub = GetRandomNumber();
        DrawCoubes(LeftCoub, RightCoub);   //Загрузка кубиков
     //--------------------------------
        //BitBtn1 -> Hide();             //Кнопка Начать игру
        Panel15 -> Show();             //Левый кубик
        Panel16 -> Show();             //Правый кубик
        Timer1 -> Enabled = true;
     //--------------------------------
        pl -> CoubSum = LeftCoub + RightCoub;
        if (LeftCoub == RightCoub) {
                pl -> DoubleMoves++;
                pl -> MovesLeft = 1;
        } else {
                pl -> MovesLeft = 0;
                pl -> DoubleMoves = 0;
        }

        pl -> CurrentField += pl -> CoubSum;
        if (pl -> CurrentField >= 40) {             //Если начнётся новый круг
                more = 1;                           //Для вывода сообщения о прохождении круга в правильном порядке
                pl -> CurrentField %= 40;
                pl -> cash += Lap;
                ViewInChat(LeftCoub, RightCoub);    //Вывод сообщения о прохождении круга
                Chat -> Lines -> Add(AnsiString(pl -> name) + " получает " + IntToStr(Lap) + "k" + " за пройденный круг");
                if (pl -> CurrentField == 0) {
                        Chat -> Lines -> Add(AnsiString(pl -> name) + " получает бонус " + IntToStr(LapBonus) + "k");
                        pl -> cash += LapBonus;
                }
                ShowMoney();                                   //Отрисовка денег
        }

        if (more == 0) ViewInChat(LeftCoub, RightCoub);        //Если круг не был пересечён, то выводится сообщение в обычном порядке
        if ((pl -> CurrentField > start) && (pl -> CurrentField < jail)) {
                Y = YTop;
                X = XTop;
                switch (pl -> CurrentField) {
                        case 1: X = XTop;
                                break;
                        case 2: X += deltaX;
                                break;
                        case 3: X += 2 * deltaX;
                                break;
                        case 4: X += 3 * deltaX;
                                break;
                        case 5: X += 4 * deltaX;
                                break;
                        case 6: X += 5 * deltaX;
                                break;
                        case 7: X += 6 * deltaX;
                                break;
                        case 8: X += 7 * deltaX;
                                break;
                        case 9: X += 8 * deltaX;
                                break;
                }
        } else if ((pl -> CurrentField > jail) && (pl -> CurrentField < jackpot)) {
                X = XRight;
                Y = YRight;
                switch (pl -> CurrentField) {
                        case 11: Y = YRight;
                                break;
                        case 12: Y += deltaY;
                                break;
                        case 13: Y += 2 * deltaY;
                                break;
                        case 14: Y += 3 * deltaY;
                                break;
                        case 15: Y += 4 * deltaY;
                                break;
                        case 16: Y += 5 * deltaY;
                                break;
                        case 17: Y += 6 * deltaY;
                                break;
                        case 18: Y += 7 * deltaY;
                                break;
                        case 19: Y += 8 * deltaY;
                                break;
                }
        } else if ((pl -> CurrentField > jackpot) && (pl -> CurrentField < gotojail)) {
                Y = YBottom;
                X = XBottom;
                switch (pl -> CurrentField) {
                        case 21: X = XBottom;
                                break;
                        case 22: X -=  deltaX;
                                break;
                        case 23: X -=  2 * deltaX;
                                break;
                        case 24: X -=  3 * deltaX;
                                break;
                        case 25: X -=  4 * deltaX;
                                break;
                        case 26: X -=  5 * deltaX;
                                break;
                        case 27: X -=  6 * deltaX;
                                break;
                        case 28: X -=  7 * deltaX;
                                break;
                        case 29: X -=  8 * deltaX;
                                break;
                }
        } else if ((pl -> CurrentField > gotojail) && (pl -> CurrentField < start + 40)) {
                X = XLeft;
                Y = YLeft;
                switch (pl -> CurrentField) {
                        case 31: Y = YLeft;
                                break;
                        case 32: Y -= deltaY;
                                break;
                        case 33: Y -= 2 * deltaY;
                                break;
                        case 34: Y -= 3 * deltaY;
                                break;
                        case 35: Y -= 4 * deltaY;
                                break;
                        case 36: Y -= 5 * deltaY;
                                break;
                        case 37: Y -= 6 * deltaY;
                                break;
                        case 38: Y -= 7 * deltaY;
                                break;
                        case 39: Y -= 8 * deltaY;
                                break;
                }
        } else if (pl -> CurrentField == start) {
                switch (pl -> color) {
                        case 1: X = 456;
                                Y = 39;
                                break;
                        case 2: X = 456;
                                Y = 88;
                                break;
                        case 3: X = 408;
                                Y = 88;
                                break;
                        case 4: X = 408;
                                Y = 39;
                                break;
                }
        } else if (pl -> CurrentField == jail) {
                switch (pl -> color) {
                        case 1: X = XRight + 28;
                                Y = YTop - 32;
                                break;
                        case 2: X = 1048;
                                Y = 80;
                                break;
                        case 3: X = 1024;
                                Y = 56;
                                break;
                        case 4: X = 992;
                                Y = 23;
                                break;
                }
        } else if (pl -> CurrentField == jackpot) {
                switch (pl -> color) {
                        case 1: X = 1040;
                                Y = 615;
                                break;
                        case 2: X = 1040;
                                Y = 664;
                                break;
                        case 3: X = 1024;
                                Y = 664;
                                break;
                        case 4: X = 1024;
                                Y = 615;
                                break;
                }
        } else if (pl -> CurrentField == gotojail) {
                pl -> CurrentField = jail;
                switch (pl -> color) {
                        case 1: X = 984;
                                Y = 87;
                                break;
                        case 2: X = 976;
                                Y = 48;
                                break;
                        case 3: X = 1024;
                                Y = 96;
                                break;
                        case 4: X = 1008;
                                Y = 71;
                                break;
                }
        }
        MovePlayer(X, Y);                         

//==============================================================================
        if ((field[pl -> CurrentField].cost != 0) && (pl -> CurrentField != 4) && (pl -> CurrentField != 36)) {
                if ((field[pl -> CurrentField].owner != 0) && (field[pl -> CurrentField].owner != pl -> color)) {
                        if ((pl -> CurrentField == 12) || (pl -> CurrentField == 28)) {
                                field[pl -> CurrentField].pay *= pl -> CoubSum;
                        }
                        if (pl -> cash - field[pl -> CurrentField].pay >= 0) BitBtn3 -> Enabled = true;
                        else BitBtn3 -> Enabled = false;
                        BitBtn3 -> Caption = "Заплатить " + AnsiString(field[pl -> CurrentField].pay) + "k";
                        BitBtn3 -> Width = 441;
                        BitBtn4 -> Hide();
                } else if ((field[pl -> CurrentField].owner != 0) && (field[pl -> CurrentField].owner == pl -> color)) NextPlayer();
                else {
                        BitBtn3 -> Caption = "Заплатить " + AnsiString(field[pl -> CurrentField].cost) + "k";
                        if (pl -> cash - field[pl -> CurrentField].cost >= 0) BitBtn3 -> Enabled = true;
                        else BitBtn3 -> Enabled = false;
                }
        } else if ((pl -> CurrentField == 4) || (pl -> CurrentField == 36)) {
                BitBtn3 -> Caption = "Заплатить " + IntToStr(field[pl -> CurrentField].cost) + "k";
                BitBtn3 -> Width = 441;
                BitBtn4 -> Hide();
                if (pl -> cash - field[pl -> CurrentField].cost >= 0) BitBtn3 -> Enabled = true;
                else BitBtn3 -> Enabled = false;
        } else if ((pl -> CurrentField == 2) || (pl -> CurrentField == 7) || (pl -> CurrentField == 17) || (pl -> CurrentField == 22) || (pl -> CurrentField == 33) || (pl -> CurrentField == 38)) {
                //поле шанс
                RandomNumber = rand() % 2;
                        switch (RandomNumber) {
                                case 0: field[pl -> CurrentField].pay = 1000;
                                        pl -> cash += field[pl -> CurrentField].pay;
                                        Chat -> Lines -> Add(AnsiString(pl -> name) + " получает " + AnsiString(field[pl -> CurrentField].pay) + "k от банка");
                                        ShowMoney();
                                        NextPlayer();
                                        HideGroupBox = 1;
                                        break;
                                case 1: field[pl -> CurrentField].pay = 1000;
                                        Chat -> Lines -> Add(AnsiString(pl -> name) + " должен заплатить банку " + IntToStr(field[pl -> CurrentField].pay) + "k");
                                        BitBtn3 -> Caption = "Заплатить " + IntToStr(field[pl -> CurrentField].pay) + "k";
                                        BitBtn3 -> Width = 441;
                                        BitBtn4 -> Hide();
                                        if (pl -> cash - field[pl -> CurrentField].pay >= 0) BitBtn3 -> Enabled = true;
                                        else BitBtn3 -> Enabled = false;
                                        GroupBox2 -> Show();                       
                                        break;                               
                                default: ShowMessage("kek, smth wrong!!!");
                                         break;
                        }
        } else if (pl -> CurrentField == jail) {
                //ничего особенного, вывести сообщение и т.д.
                NextPlayer();
        } else if (pl -> CurrentField == gotojail) {
                //переход в тюрьму
                pl -> MovesLeft = 0;
                pl -> DoubleMoves = 0;
                NextPlayer();
        } else if (pl -> CurrentField == jackpot) {
                GroupBox3 -> Show();
        }

}
//---------------------------------------------------------------------------

void __fastcall TMonopoly::BitBtn1Click(TObject *Sender)
{
        if (AmountOfPlayers > 1) {
                GroupBox1 -> Show();
                Player1Shape -> Show();
                Player2Shape -> Show();
                Player3Shape -> Show();
                Player4Shape -> Show();
                Panel1 -> Enabled = true;
                Panel2 -> Enabled = true;
                Panel3 -> Enabled = true;
                Panel4 -> Enabled = true;
                if (AmountOfPlayers == 2) {
                        Player3Shape -> Hide();
                        Player4Shape -> Hide();
                        Panel3 -> Enabled = false;
                        Panel4 -> Enabled = false;
                } else if (AmountOfPlayers == 3) {
                        Player4Shape -> Hide();
                        Panel4 -> Enabled = false;
                }

                SendMessageButton -> Enabled = true;
                Edit1 -> Enabled = true;
                if (AmountOfPlayers == 2) Player3 -> Hide();
                else if (AmountOfPlayers == 3) Player4 -> Hide();
                pl = head;
                pl = pl -> next;
                ColorPlayer();
                BitBtn1 -> Hide();
        } else ShowMessage("Для игры необходимо минимум 2 игрока");
}
//---------------------------------------------------------------------------

void __fastcall TMonopoly::SendMessageButtonClick(TObject *Sender)
{
        if ((Edit1 -> Text.Length() != 0) && (pl != NULL)) {
                Chat -> Lines -> Text = Chat -> Lines -> Text + pl -> name + ": " + Edit1 -> Text;
                Chat ->Perform(WM_VSCROLL, SB_BOTTOM, SB_THUMBTRACK);
                Edit1 -> Clear();
        }                                        
}
//--------------------------------------------------------------------------
void __fastcall TMonopoly::Timer1Timer(TObject *Sender)
{
        Timer1 -> Enabled = false;
        Panel15 -> Hide();              
        Panel16 -> Hide();
        GroupBox1 -> Show();
        if ((field[pl -> CurrentField].cost != 0) && (HideGroupBox == 0)) {
                GroupBox2 -> Show();
        }
}
//---------------------------------------------------------------------------
void __fastcall TMonopoly::BitBtn3Click(TObject *Sender)
{
        player *temp;
        int tempnumber = 0, tempcolor = 0, money = 0;
        HideGroupBox = 0;
        AnsiString str;
        HidePanels();
        str = field[pl -> CurrentField].name;
        if ((field[pl -> CurrentField].owner == 0) && (pl -> CurrentField != 2) && (pl -> CurrentField != 4) && (pl -> CurrentField != 7) && (pl -> CurrentField != 17) && (pl -> CurrentField != 22) && (pl -> CurrentField != 33) && (pl -> CurrentField != 36) && (pl -> CurrentField != 38)) {
                pl -> cash -= field[pl -> CurrentField].cost;
                field[pl -> CurrentField].owner = pl -> color;
                        switch (pl -> CurrentField) {
                                case 1:
                                        Chanel -> Caption = AnsiString(field[pl -> CurrentField].pay) + "k";
                                        Chanel -> Font -> Color = clWhite;
                                        switch (pl -> color) {
                                                case 1: Chanel -> Color = clRed;
                                                        break;
                                                case 2: Chanel -> Color = clBlue;
                                                        break;
                                                case 3: Chanel -> Color = clLime;
                                                        break;
                                                case 4: Chanel -> Color = clPurple;
                                                        break;
                                        }
                                        break;
                                case 3: HugoBoss -> Caption = AnsiString(field[pl -> CurrentField].pay) + "k";
                                        HugoBoss -> Font -> Color = clWhite;
                                        switch (pl -> color) {
                                                case 1: HugoBoss -> Color = clRed;
                                                        break;
                                                case 2: HugoBoss -> Color = clBlue;
                                                        break;
                                                case 3: HugoBoss -> Color = clLime;
                                                        break;
                                                case 4: HugoBoss -> Color = clPurple;
                                                        break;
                                        }
                                        break;
                                case 5: Mercedes -> Caption = AnsiString(field[pl -> CurrentField].pay) + "k";
                                        Mercedes -> Font -> Color = clWhite;
                                        switch (pl -> color) {
                                                case 1: Mercedes -> Color = clRed;
                                                        break;
                                                case 2: Mercedes -> Color = clBlue;
                                                        break;
                                                case 3: Mercedes -> Color = clLime;
                                                        break;
                                                case 4: Mercedes -> Color = clPurple;
                                                        break;
                                        }
                                        break;
                                case 6: Adidas -> Caption = AnsiString(field[pl -> CurrentField].pay) + "k";
                                        Adidas -> Font -> Color = clWhite;
                                        switch (pl -> color) {
                                                case 1: Adidas -> Color = clRed;
                                                        break;
                                                case 2: Adidas -> Color = clBlue;
                                                        break;
                                                case 3: Adidas -> Color = clLime;
                                                        break;
                                                case 4: Adidas -> Color = clPurple;
                                                        break;
                                        }
                                        break;
                                case 8: Puma -> Caption = AnsiString(field[pl -> CurrentField].pay) + "k";
                                        Puma -> Font -> Color = clWhite;
                                        switch (pl -> color) {
                                                case 1: Puma -> Color = clRed;
                                                        break;
                                                case 2: Puma -> Color = clBlue;
                                                        break;
                                                case 3: Puma -> Color = clLime;
                                                        break;
                                                case 4: Puma -> Color = clPurple;
                                                        break;
                                        }
                                        break;
                                case 9: Lacoste -> Caption = AnsiString(field[pl -> CurrentField].pay) + "k";
                                        Lacoste -> Font -> Color = clWhite;
                                        switch (pl -> color) {
                                                case 1: Lacoste -> Color = clRed;
                                                        break;
                                                case 2: Lacoste -> Color = clBlue;
                                                        break;
                                                case 3: Lacoste -> Color = clLime;
                                                        break;
                                                case 4: Lacoste -> Color = clPurple;
                                                        break;
                                        }
                                        break;
                                case 11: Vk -> Caption = AnsiString(field[pl -> CurrentField].pay) + "k";
                                         Vk -> Font -> Color = clWhite;
                                         switch (pl -> color) {
                                                case 1: Vk -> Color = clRed;
                                                        break;
                                                case 2: Vk -> Color = clBlue;
                                                        break;
                                                case 3: Vk -> Color = clLime;
                                                        break;
                                                case 4: Vk -> Color = clPurple;
                                                        break;
                                        }
                                        break;
                                case 12: Rovio -> Caption = "x" + AnsiString(field[pl -> CurrentField].pay);
                                         Rovio -> Font -> Color = clWhite;
                                         switch (pl -> color) {
                                                case 1: Rovio -> Color = clRed;
                                                        break;
                                                case 2: Rovio -> Color = clBlue;
                                                        break;
                                                case 3: Rovio -> Color = clLime;
                                                        break;
                                                case 4: Rovio -> Color = clPurple;
                                                        break;
                                        }
                                        break;
                                case 13: Facebook -> Caption = AnsiString(field[pl -> CurrentField].pay) + "k";
                                         Facebook -> Font -> Color = clWhite;
                                         switch (pl -> color) {
                                                case 1: Facebook -> Color = clRed;
                                                        break;
                                                case 2: Facebook -> Color = clBlue;
                                                        break;
                                                case 3: Facebook -> Color = clLime;
                                                        break;
                                                case 4: Facebook -> Color = clPurple;
                                                        break;
                                        }
                                        break;
                                case 14: Twitter -> Caption = AnsiString(field[pl -> CurrentField].pay) + "k";
                                         Twitter -> Font -> Color = clWhite;
                                         switch (pl -> color) {
                                                case 1: Twitter -> Color = clRed;
                                                        break;
                                                case 2: Twitter -> Color = clBlue;
                                                        break;
                                                case 3: Twitter -> Color = clLime;
                                                        break;
                                                case 4: Twitter -> Color = clPurple;
                                                        break;
                                        }
                                        break;
                                case 15: Audi -> Caption = AnsiString(field[pl -> CurrentField].pay) + "k";
                                         Audi -> Font -> Color = clWhite;
                                         switch (pl -> color) {
                                                case 1: Audi -> Color = clRed;
                                                        break;
                                                case 2: Audi -> Color = clBlue;
                                                        break;
                                                case 3: Audi -> Color = clLime;
                                                        break;
                                                case 4: Audi -> Color = clPurple;
                                                        break;
                                        }
                                        break;
                                case 16: CocaCola -> Caption = AnsiString(field[pl -> CurrentField].pay) + "k";
                                         CocaCola -> Font -> Color = clWhite;
                                         switch (pl -> color) {
                                                case 1: CocaCola -> Color = clRed;
                                                        break;
                                                case 2: CocaCola -> Color = clBlue;
                                                        break;
                                                case 3: CocaCola -> Color = clLime;
                                                        break;
                                                case 4: CocaCola -> Color = clPurple;
                                                        break;
                                        }
                                        break;
                                case 18: Fanta -> Caption = AnsiString(field[pl -> CurrentField].pay) + "k";
                                         Fanta -> Font -> Color = clWhite;
                                         switch (pl -> color) {
                                                case 1: Fanta -> Color = clRed;
                                                        break;
                                                case 2: Fanta -> Color = clBlue;
                                                        break;
                                                case 3: Fanta -> Color = clLime;
                                                        break;
                                                case 4: Fanta -> Color = clPurple;
                                                        break;
                                        }
                                        break;
                                case 19: Pepsi -> Caption = AnsiString(field[pl -> CurrentField].pay) + "k";
                                         Pepsi -> Font -> Color = clWhite;
                                         switch (pl -> color) {
                                                case 1: Pepsi -> Color = clRed;
                                                        break;
                                                case 2: Pepsi -> Color = clBlue;
                                                        break;
                                                case 3: Pepsi -> Color = clLime;
                                                        break;
                                                case 4: Pepsi -> Color = clPurple;
                                                        break;
                                        }
                                        break;
                                case 21: BritishAirways -> Caption = AnsiString(field[pl -> CurrentField].pay) + "k";
                                         BritishAirways -> Font -> Color = clWhite;
                                         switch (pl -> color) {
                                                case 1: BritishAirways -> Color = clRed;
                                                        break;
                                                case 2: BritishAirways -> Color = clBlue;
                                                        break;
                                                case 3: BritishAirways -> Color = clLime;
                                                        break;
                                                case 4: BritishAirways -> Color = clPurple;
                                                        break;
                                        }
                                        break;
                                case 23: AmericanAirlines -> Caption = AnsiString(field[pl -> CurrentField].pay) + "k";
                                         AmericanAirlines -> Font -> Color = clWhite;
                                         switch (pl -> color) {
                                                case 1: AmericanAirlines -> Color = clRed;
                                                        break;
                                                case 2: AmericanAirlines -> Color = clBlue;
                                                        break;
                                                case 3: AmericanAirlines -> Color = clLime;
                                                        break;
                                                case 4: AmericanAirlines -> Color = clPurple;
                                                        break;
                                        }
                                        break;
                                case 24: Lufthansa -> Caption = AnsiString(field[pl -> CurrentField].pay) + "k";
                                         Lufthansa -> Font -> Color = clWhite;
                                         switch (pl -> color) {
                                                case 1: Lufthansa -> Color = clRed;
                                                        break;
                                                case 2: Lufthansa -> Color = clBlue;
                                                        break;
                                                case 3: Lufthansa -> Color = clLime;
                                                        break;
                                                case 4: Lufthansa -> Color = clPurple;
                                                        break;
                                        }
                                        break;
                                case 25: Ford -> Caption = AnsiString(field[pl -> CurrentField].pay) + "k";
                                         Ford -> Font -> Color = clWhite;
                                         switch (pl -> color) {
                                                case 1: Ford -> Color = clRed;
                                                        break;
                                                case 2: Ford -> Color = clBlue;
                                                        break;
                                                case 3: Ford -> Color = clLime;
                                                        break;
                                                case 4: Ford -> Color = clPurple;
                                                        break;
                                        }
                                        break;
                                case 26: McDonalds -> Caption = AnsiString(field[pl -> CurrentField].pay) + "k";
                                         McDonalds -> Font -> Color = clWhite;
                                         switch (pl -> color) {
                                                case 1: McDonalds -> Color = clRed;
                                                        break;
                                                case 2: McDonalds -> Color = clBlue;
                                                        break;
                                                case 3: McDonalds -> Color = clLime;
                                                        break;
                                                case 4: McDonalds -> Color = clPurple;
                                                        break;
                                        }
                                        break;
                                case 27: KFC -> Caption = AnsiString(field[pl -> CurrentField].pay) + "k";
                                         KFC -> Font -> Color = clWhite;
                                         switch (pl -> color) {
                                                case 1: KFC -> Color = clRed;
                                                        break;
                                                case 2: KFC -> Color = clBlue;
                                                        break;
                                                case 3: KFC -> Color = clLime;
                                                        break;
                                                case 4: KFC -> Color = clPurple;
                                                        break;
                                        }
                                        break;
                                case 28: RockstarGames -> Caption = "x" + AnsiString(field[pl -> CurrentField].pay);
                                         RockstarGames -> Font -> Color = clWhite;
                                         switch (pl -> color) {
                                                case 1: RockstarGames -> Color = clRed;
                                                        break;
                                                case 2: RockstarGames -> Color = clBlue;
                                                        break;
                                                case 3: RockstarGames -> Color = clLime;
                                                        break;
                                                case 4: RockstarGames -> Color = clPurple;
                                                        break;
                                        }
                                        break;
                                case 29: BurgerKing -> Caption = AnsiString(field[pl -> CurrentField].pay) + "k";
                                         BurgerKing -> Font -> Color = clWhite;
                                         switch (pl -> color) {
                                                case 1: BurgerKing -> Color = clRed;
                                                        break;
                                                case 2: BurgerKing -> Color = clBlue;
                                                        break;
                                                case 3: BurgerKing -> Color = clLime;
                                                        break;
                                                case 4: BurgerKing -> Color = clPurple;
                                                        break;
                                        }
                                        break;
                                case 31: Novotel -> Caption = AnsiString(field[pl -> CurrentField].pay) + "k";
                                         Novotel -> Font -> Color = clWhite;
                                         switch (pl -> color) {
                                                case 1: Novotel -> Color = clRed;
                                                        break;
                                                case 2: Novotel -> Color = clBlue;
                                                        break;
                                                case 3: Novotel -> Color = clLime;
                                                        break;
                                                case 4: Novotel -> Color = clPurple;
                                                        break;
                                        }
                                        break;
                                case 32: Radisson -> Caption = AnsiString(field[pl -> CurrentField].pay) + "k";
                                         Radisson -> Font -> Color = clWhite;
                                         switch (pl -> color) {
                                                case 1: Radisson -> Color = clRed;
                                                        break;
                                                case 2: Radisson -> Color = clBlue;
                                                        break;
                                                case 3: Radisson -> Color = clLime;
                                                        break;
                                                case 4: Radisson -> Color = clPurple;
                                                        break;
                                        }
                                        break;
                                case 34: HolidayInn -> Caption = AnsiString(field[pl -> CurrentField].pay) + "k";
                                         HolidayInn -> Font -> Color = clWhite;
                                         switch (pl -> color) {
                                                case 1: HolidayInn -> Color = clRed;
                                                        break;
                                                case 2: HolidayInn -> Color = clBlue;
                                                        break;
                                                case 3: HolidayInn -> Color = clLime;
                                                        break;
                                                case 4: HolidayInn -> Color = clPurple;
                                                        break;
                                        }
                                        break;
                                case 35: LandRover -> Caption = AnsiString(field[pl -> CurrentField].pay) + "k";
                                         LandRover -> Font -> Color = clWhite;
                                         switch (pl -> color) {
                                                case 1: LandRover -> Color = clRed;
                                                        break;
                                                case 2: LandRover -> Color = clBlue;
                                                        break;
                                                case 3: LandRover -> Color = clLime;
                                                        break;
                                                case 4: LandRover -> Color = clPurple;
                                                        break;
                                        }
                                        break;
                                case 37: Apple -> Caption = AnsiString(field[pl -> CurrentField].pay) + "k";
                                         Apple -> Font -> Color = clWhite;
                                         switch (pl -> color) {
                                                case 1: Apple -> Color = clRed;
                                                        break;
                                                case 2: Apple -> Color = clBlue;
                                                        break;
                                                case 3: Apple -> Color = clLime;
                                                        break;
                                                case 4: Apple -> Color = clPurple;
                                                        break;
                                        }
                                        break;
                                case 39: Nokia -> Caption = AnsiString(field[pl -> CurrentField].pay) + "k";
                                         Nokia -> Font -> Color = clWhite;
                                         switch (pl -> color) {
                                                case 1: Nokia -> Color = clRed;
                                                        break;
                                                case 2: Nokia -> Color = clBlue;
                                                        break;
                                                case 3: Nokia -> Color = clLime;
                                                        break;
                                                case 4: Nokia -> Color = clPurple;
                                                        break;
                                        }
                                        break;
                        }
        Chat -> Lines -> Add(AnsiString(pl -> name) + " покупает " + str + " за " + AnsiString(field[pl -> CurrentField].cost) + "k");
        } else if ((pl -> CurrentField == 4) || (pl -> CurrentField == 36)){
                pl -> cash -= field[pl -> CurrentField].cost;
                Chat -> Lines -> Add(AnsiString(pl -> name) + " заплатил налог " + AnsiString(field[pl -> CurrentField].cost) + "k");
        } else if ((pl -> color != field[pl -> CurrentField].owner) && (field[pl -> CurrentField].owner != 0)) {
                pl -> cash -= field[pl -> CurrentField].pay;
                Chat -> Lines -> Add(AnsiString(pl -> name) + " заплатил аренду " + AnsiString(field[pl -> CurrentField].pay) + "k");
                money = field[pl -> CurrentField].pay;
                tempcolor = pl -> color;
                tempnumber = field[pl -> CurrentField].owner;
                for (int i = 0; i <= AmountOfPlayers - 1; i++) {
                        if (tempcolor == tempnumber) {
                                pl -> cash += money;
                                switch (pl -> color) {
                                        case 1: Player1Money -> Caption = "$" + IntToStr(pl -> cash) + "k";
                                                break;
                                        case 2: Player2Money -> Caption = "$" + IntToStr(pl -> cash) + "k";
                                                break;
                                        case 3: Player3Money -> Caption = "$" + IntToStr(pl -> cash) + "k";
                                                break;
                                        case 4: Player4Money -> Caption = "$" + IntToStr(pl -> cash) + "k";
                                                break;
                                }
                        }
                        if (pl -> next == NULL) {
                                pl = head;
                        }
                        pl = pl -> next;
                        tempcolor = pl -> color;
                }
        } else if ((pl -> CurrentField == 2) || (pl -> CurrentField == 7) || (pl -> CurrentField == 17) || (pl -> CurrentField == 22) || (pl -> CurrentField == 33) || (pl -> CurrentField == 38)) {
                pl -> cash -= field[pl -> CurrentField].pay;
                Chat -> Lines -> Add(AnsiString(pl -> name) + " заплатил " + AnsiString(field[pl -> CurrentField].pay) + "k банку ");
        }
                switch (pl -> color) {
                        case 1: Player1Money -> Caption = "$" + IntToStr(pl -> cash) + "k";
                                break;
                        case 2: Player2Money -> Caption = "$" + IntToStr(pl -> cash) + "k";
                                break;
                        case 3: Player3Money -> Caption = "$" + IntToStr(pl -> cash) + "k";
                                break;
                        case 4: Player4Money -> Caption = "$" + IntToStr(pl -> cash) + "k";
                                break;
                }
                GroupBox2 -> Hide();

                if (pl -> MovesLeft == 0) {
                        Player1 -> Color = clSilver;
                        Player2 -> Color = clSilver;
                        Player3 -> Color = clSilver;
                        Player4 -> Color = clSilver;
                        if (pl -> next == NULL) {
                                pl = head;
                        }
                        pl = pl -> next;
                        ColorPlayer();
                        GroupBox1 -> Show();
                }
                BitBtn3 -> Width = 209;
                BitBtn4 -> Show();
                GroupBox2 -> Hide();
}
//---------------------------------------------------------------------------

void __fastcall TMonopoly::BitBtn4Click(TObject *Sender)
{
        HideGroupBox = 0;
        GroupBox2 -> Hide();
        NextPlayer();
}

void __fastcall TMonopoly::Player2Click(TObject *Sender)
{
                if ((pl -> color == 2) && (pl != NULL)) {
                        Panel2 -> Show();
                }
}
//---------------------------------------------------------------------------

void __fastcall TMonopoly::Player1Click(TObject *Sender)
{
        if (AmountOfPlayers > 1) {
                if ((pl -> color == 1) && (pl != NULL)) {
                        Panel1 -> Show();
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TMonopoly::Player3Click(TObject *Sender)
{
        if (AmountOfPlayers > 1) {
                if ((pl -> color == 3) && (pl != NULL)) {
                        Panel3 -> Show();
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TMonopoly::Player4Click(TObject *Sender)
{
        if (AmountOfPlayers > 1) {
                if ((pl -> color == 4) && (pl != NULL)) {
                        Panel4 -> Show();
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TMonopoly::FormClick(TObject *Sender)
{
        HidePanels();
}
//---------------------------------------------------------------------------

void __fastcall TMonopoly::BitBtn5Click(TObject *Sender)
{
        player *DeleteAdress;
        DeleteAdress = pl;
        pl = head;
        while (pl -> next != DeleteAdress) {
                if (pl -> next == NULL) pl = head;
                pl = pl -> next;
        }
        pl -> next = DeleteAdress -> next;
        free(DeleteAdress);
        AmountOfPlayers--;
        AddPlayer1 -> Hide();
        Panel1 -> Hide();
        Player1 -> Hide();
        Player1Shape -> Hide();
        ColorPlayer();
        if (AmountOfPlayers == 1) {
                HideButtons();
                HideFields();
                Label3 -> Show();
                Label3 -> Caption = AnsiString(pl -> name) + " ЗАНЯЛ 1 МЕСТО";
        } else NextPlayer();
}
//---------------------------------------------------------------------------

void __fastcall TMonopoly::BitBtn6Click(TObject *Sender)
{
        player *DeleteAdress;
        DeleteAdress = pl;
        pl = head;
        while (pl -> next != DeleteAdress) {
                if (pl -> next == NULL) pl = head;
                pl = pl -> next;
        }                                      
        pl -> next = DeleteAdress -> next;
        free(DeleteAdress);
        AmountOfPlayers--;       
        Panel2 -> Hide();
        Player2 -> Hide();        
        Player2Shape -> Hide();
        ColorPlayer();
        if (AmountOfPlayers == 1) {
                HideButtons();
                HideFields();
                Label3 -> Show();
                Label3 -> Caption = AnsiString(pl -> name) + " ЗАНЯЛ 1 МЕСТО";
        } else NextPlayer();
}
//---------------------------------------------------------------------------

void __fastcall TMonopoly::BitBtn7Click(TObject *Sender)
{
        player *DeleteAdress;
        DeleteAdress = pl;
        pl = head;
        while (pl -> next != DeleteAdress) {
                if (pl -> next == NULL) pl = head;
                pl = pl -> next;
        }
        pl -> next = DeleteAdress -> next;
        free(DeleteAdress);
        AmountOfPlayers--;
        Panel3 -> Hide();
        Player3 -> Hide();
        Player3Shape -> Hide();  
        ColorPlayer();
        if (AmountOfPlayers == 1) {
                HideButtons();
                HideFields();
                Label3 -> Show();
                Label3 -> Caption = AnsiString(pl -> name) + " ЗАНЯЛ 1 МЕСТО";
        } else NextPlayer();
}
//---------------------------------------------------------------------------

void __fastcall TMonopoly::BitBtn8Click(TObject *Sender)
{
        player *DeleteAdress;
        DeleteAdress = pl;
        pl = head;
        while (pl -> next != DeleteAdress) {
                if (pl -> next == NULL) pl = head;
                pl = pl -> next;
        }
        pl -> next = DeleteAdress -> next;
        free(DeleteAdress);
        AmountOfPlayers--;
        Panel4 -> Hide();
        Player4 -> Hide();
        Player4Shape -> Hide();
        ColorPlayer();
        if (AmountOfPlayers == 1) {
                HideButtons();
                HideFields();
                Label3 -> Show();
                Label3 -> Caption = AnsiString(pl -> name) + " ЗАНЯЛ 1 МЕСТО";
        } else NextPlayer();
}
//---------------------------------------------------------------------------

void __fastcall TMonopoly::BitBtn9Click(TObject *Sender)
{
        const int prize = 6000, price = 1000;            
        int MyNumber = 0, GuessNumber;
        if ((RadioButton1 -> Checked) || (RadioButton2 -> Checked) || (RadioButton3 -> Checked) || (RadioButton4 -> Checked) || (RadioButton5 -> Checked) || (RadioButton6 -> Checked)) {
                GroupBox3 -> Hide();
                if (RadioButton1 -> Checked) MyNumber = 1;
                else if (RadioButton2 -> Checked) MyNumber = 2;
                else if (RadioButton3 -> Checked) MyNumber = 3;
                else if (RadioButton4 -> Checked) MyNumber = 4;
                else if (RadioButton5 -> Checked) MyNumber = 5;
                else if (RadioButton6 -> Checked) MyNumber = 6;
                pl -> cash -= price;
                Chat -> Lines -> Add(AnsiString(pl -> name) + " поставил на " + AnsiString(MyNumber) + " 1000k" );
                GuessNumber = PlayJackpod();
                if (MyNumber == GuessNumber) {
                        Chat -> Lines -> Add("Выпадает " + AnsiString(GuessNumber) + " и " + AnsiString(pl -> name) + " выигрывает 6000k");
                        pl -> cash += prize;
                } else Chat -> Lines -> Add("Выпадает " + AnsiString(GuessNumber) + " и " + AnsiString(pl -> name) + " ничего не выигрывает...");
                ShowMoney();
        } else ShowMessage("Выберите значение кубика");
        RadioButton1 -> Checked = false;
        RadioButton2 -> Checked = false;
        RadioButton3 -> Checked = false;
        RadioButton4 -> Checked = false;
        RadioButton5 -> Checked = false;
        RadioButton6 -> Checked = false;
        NextPlayer();
}
//---------------------------------------------------------------------------


void __fastcall TMonopoly::BitBtn10Click(TObject *Sender)
{
        HideGroupBox = 0;
        NextPlayer();
}
//---------------------------------------------------------------------------

