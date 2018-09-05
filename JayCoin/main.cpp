//
//  Block.cpp
//  BlockChainExample
//
//  Created by Jon on 1/10/18.
//  Copyright © 2018 Crypto Enthusiasts. All rights reserved.
//
//  Se incluye este fuente en control de versiones Github test 001
//  Se incluye este fuente en control de versiones Github test 002
//

#include <iostream>
#include <ctime>
#include <vector>

#include "include\TransactionData.h"
#include "include\Block.h"
#include "include\Blockchain.h"

using namespace std;

int main()
{
    // Start Blockchain
    Blockchain awesomeCoin;

    // Data for first block
    time_t data1Time;
    TransactionData data1(1.5, "Joe", "Sally", time(&data1Time));
    awesomeCoin.addBlock(data1);

    time_t data2Time;
    TransactionData data2(0.2233, "Martha", "Fred", time(&data2Time));
    awesomeCoin.addBlock(data2);

    // Let's see what's in the awesomeCoin blockchain!
    awesomeCoin.printChain();

    // Is it valid?
    printf("\nIs chain still valid? %d\n", awesomeCoin.isChainValid());

    // Someone's getting sneaky
    Block *hackBlock = awesomeCoin.getLatestBlock();
    hackBlock->data.amount = 10000; // Oh yeah!
    hackBlock->data.receiverKey = "Jon"; // mwahahahaha!

    // Let's look at data
    awesomeCoin.printChain();

    // Awww! Why is it not valid?
    printf("\nIs chain still valid? %d\n", awesomeCoin.isChainValid());

    return 0;
}
