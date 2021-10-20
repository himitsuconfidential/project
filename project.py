from random import random
class Stock:
    def __init__(self, name, price, profit, voltality):
        self.name = name
        self.price = price
        self.profit = profit
        self.voltality = voltality
        
stock = Stock('stockABC',50,1,3)#stock_name, current price, mean move, voltality move
class Player_status:
    def __init__(self, name, year, cash, inventory):
        self.name = name
        self.year = year
        self.cash = cash
        self.inventory = inventory

player = Player_status(name='you', year=0, cash=1000, inventory=0)
def buy_stock(volumn):
    
    if player.inventory + volumn <0:
        print('invalid trade: you dont have enough stock to sell')
    elif player.cash - volumn*stock.price <0:
        print('invalid trade: you dont have enough money to buy')
    else:
        player.cash -= volumn*stock.price
        player.inventory += volumn

def main():

    

    command = ''
    while command != 'q':
        show_stock()
        command = input('what do you want to do?')
        if command == 'b':
            volumn = int(input('how many stock do you want to buy'))
            
            buy_stock(volumn)
            show_inventory()
        elif command == 's':
            volumn = int(input('how many stock do you want to sell'))
            buy_stock(-volumn)
            
            show_inventory()
        elif command == 'z':
            sleep()
        
def show_stock():
    print('\n++++++Year', player.year ,'++++++')
    print("stock","current price",sep='\t')
    print(stock.name, stock.price, sep='\t')
    print('=======================')
    print('q:leave, z:sleep, b: buy stock, s: sell stock')
    
def show_inventory():
    print('your have cash ', player.cash)
    print('your have ' , player.inventory, ' unit of stock, each worth $' ,stock.price)

def sleep():
    player.year += 1
    stock.price += (random()-0.5)*stock.voltality+stock.profit
    


main()



