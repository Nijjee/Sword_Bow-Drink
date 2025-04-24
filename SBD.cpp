#include <iostream>
class ITakeble { public: virtual void takeThis() = 0; };
class IThrowable { public: virtual void throwThis() = 0; };
class IExamineble { public:	virtual void examineThis() = 0; };
class IUseble { public: virtual void useIt() = 0; };
class Atack { public:virtual void atacking() = 0; };

class Item { protected: int price; };
class Weapon { protected: std::string material, damage, hit; };
class Human { protected: short hp; int lvl; };


					   class Sword :public ITakeble, public IThrowable, public IExamineble, public Item, public IUseble, public Weapon, public Atack {
					   public:
						   Sword() {
							   hit = "������� �����";
							   material = "������";
							   price = 10;
							   damage = 20;
						   }
						   Sword(std::string material, std::string damage, int price) {
							   hit = "������� �����";
							   this->material = material;
							   this->damage = damage;
							   this->price = price;
						   }

						   void takeThis() override {
							   std::cout << "����� ��� �� \"" << material << "\"\n";
						   }
						   void throwThis() override {
							   std::cout << "��������� ��� �� \"" << material << "\"\n";
						   }
						   void examineThis() override {
							   std::cout << "������ ���� �� \"" << material << "\":\n"
								   << "���������: \'" << price << "\' �������\n"
								   << "���� �� ����: \'" << damage << "\'";
						   }
						   void useIt() override {
							   std::cout << hit << std::endl;
						   }
						   void atacking() override {
							   std::cout << "������ ���� \"" << damage << "\"\n";
						   }
					   };
					   class Bow :public ITakeble, public IThrowable, public IExamineble, public Item, public IUseble, public Weapon {
					   public:
						   Bow() {
							   hit = "���������� �� ����";
							   material = "������";
							   price = 15;
							   damage = 10;
						   }
						   void takeThis() override {
							   std::cout << "����� ��� �� \"" << material << "\"\n";
						   }
						   void throwThis() override {
							   std::cout << "��������� ��� �� \"" << material << "\"\n";
						   }
						   void examineThis() override {
							   std::cout << "������ ���a �� \"" << material << "\":\n"
								   << "���������: \'" << price << "\' �������\n"
								   << "���� �� ����: \'" << damage << "\'";
						   }
						   void useIt() override {
							   std::cout << hit << std::endl;
						   }
					   };
					   class Potion :public ITakeble, public IThrowable, public IExamineble, public Item, public IUseble {
					   private: std::string type_potion;
					   public:
						   Potion() {
							   price = 40;
							   type_potion = "�����������";
						   }
						   void takeThis() override {
							   std::cout << "����� ����� \"" << type_potion << "\"\n";
						   }
						   void throwThis() override {
							   std::cout << "��������� ����� \"" << type_potion << "\"\n";
						   }
						   void examineThis() override {
							   std::cout << "������ ����� \"" << type_potion << "\":\n"
								   << "���������: \'" << price << "\' �������\n";
						   }
						   void useIt() override {
							   std::cout << "�� ������ ����� \"" << type_potion << "\"\n";
						   }
					   };

					   class Player :public Sword, public Bow, public Potion, public Human {
					   public:
						   Player() {
							   hp = 100;
							   lvl = 10;
						   }
						   void takeSomething(std::shared_ptr<ITakeble> something) { something->takeThis(); }
						   void useSomething(std::shared_ptr<IUseble> something) { something->useIt(); }
						   void examineSomething(std::shared_ptr<IExamineble> something) { something->examineThis(); }
						   void atack(std::shared_ptr<Atack> atackEnemy) {
							   std::cout << "����� ������ ���������� ";
							   atackEnemy->atacking();
						   }
						   void throwSomething(std::shared_ptr<IThrowable> something) { something->throwThis(); }
					   };
					   class Enemy :public Sword, public Bow, public Potion, public Human {
					   public:
						   Enemy() {
							   hp = 100;
							   lvl = 7;
						   }
						   void takeSomething(std::shared_ptr<ITakeble> something) { something->takeThis(); }
						   void useSomething(std::shared_ptr<IUseble> something) { something->useIt(); }
						   void examineSomething(std::shared_ptr<IExamineble> something) { something->examineThis(); }
						   void throwSomething(std::shared_ptr<IThrowable> something) { something->throwThis(); }
					   };


					   int main() {
						   system("chcp 1251");
						   system("cls");
						   Player player;
						   Enemy enemy;
						   std::shared_ptr<Sword>sword = std::make_shared<Sword>();
						   std::shared_ptr<Bow>bow = std::make_shared<Bow>();
						   std::shared_ptr<Potion>potion = std::make_shared<Potion>();
						   player.takeSomething(sword);
						   player.useSomething(sword);
						   player.examineSomething(sword);
						   player.atack(sword);
						   player.throwSomething(sword);
						   std::cout << std::endl;
						   player.takeSomething(bow);
						   player.useSomething(bow);
						   player.examineSomething(bow);
						   player.throwSomething(bow);
						   std::cout << std::endl;
						   player.takeSomething(potion);
						   player.useSomething(potion);
						   player.examineSomething(potion);
						   player.throwSomething(potion);
						   std::cout << std::endl;

						   return 0;
					   }