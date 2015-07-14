//  main.cpp
//  GARA Score
//  Created by Number Twenty Eight on 8/3/14.
//  Copyright (c) 2014 Güez S. All rights reserved.

#include <iostream>  

double getAverage(double* myArray, int myArrayLength){
    double sum = 0;
    for (int i = 0; i < myArrayLength; i++) {
        sum += myArray[i];
    }
    return sum / myArrayLength;
}


int main(int argc, const char * argv[])
{

    // Welcome message
    std::cout << "WELCOME TO THE GARA SCORE CALCULATOR\n" << "*********************\n" << std::endl;
    
    // Background information
    std::cout << "This program offers a tool to assess a music artist's pop culture relavance.\n" << "*********************\n" << std::endl;
    
    // PART I
    // USER VARIABLE INPUT
    std::cout << "Please enter your...\n" << std::endl;
    std::cout << "NAME: ";
    std::string userName;
    std::getline(std::cin, userName);
    
    std::cout << "NUMBER OF WEEKLY RADIO SPINS: ";
    double weeklyRadioSpins;
    std::cin >> weeklyRadioSpins;
    if (weeklyRadioSpins > 8944.444){
        weeklyRadioSpins = 8944.444;
    }
    
    std::cout << "NUMBER OF YOUTUBE/VEVO VIEWERS: ";
    double youtubeAgg;
    std::cin >> youtubeAgg;
    if (youtubeAgg > 1005555.556){
        youtubeAgg = 1005555.556;
    }
    
    std::cout << "NUMBER OF RECORDS SOLD: ";
    double recordSales;
    std::cin >> recordSales;
    if (recordSales > 19937500.000){
        recordSales = 19937500.000;
    }
    
LOOP1:std::cout << "\nAre you signed to a major label with distribution in place, (1 = Y, 0 = N)?: ";
    int hasDeal = 0;
    std::cin >> hasDeal;
    if (hasDeal > 1){
        std::cout << "\nPLEASE ENTER EITHER '1' FOR 'YES' OR '0' FOR 'NO'!!!\n";
        goto LOOP1;
    }

    
    // BILLBOARD ALGORITHM
    double *pointer = NULL;
    std::cout << "\nHow many songs do you currently have on the BILLBOARD charts?: ";
    int input;
    std::cin >> input;
    
    pointer = new double[input];
    
    int temp;
    
    for (int counter = 0; counter < input; counter++) {
        std::cout << "CHART POSITION " << counter+1 << ": #";
        std::cin >> temp;
        pointer[counter] = temp;
    }
    
    double average = getAverage(pointer, input);
    std::cout << "AVERAGE CHART POSITION:  " << average << std::endl;
    
    double wtd_chartAverage;
    
    if (average <= 10) {
        wtd_chartAverage = 8.333;
    }
    else if (average > 10 && average <= 20){
        wtd_chartAverage = 7.333;
    }
    else if (average > 20 && average <= 40){
        wtd_chartAverage = 6.333;
    }
    else if (average > 40 && average <= 100){
        wtd_chartAverage = 5.333;
    }
    else if (average > 100 && average <= 200){
        wtd_chartAverage = 4.333;
    }
    else{
        wtd_chartAverage = 0;
    }
    
    delete []pointer;
    
    std::cout << "\nNUMBER OF TWITTER FOLLOWERS: ";
    double twitterFollowers;
    std::cin >> twitterFollowers;
    if (twitterFollowers > 4888888.889){
        twitterFollowers = 4888888.889;
    }
    
    std::cout << "NUMBER OF FACEBOOK LIKES: ";
    double facebookLikes;
    std::cin >> facebookLikes;
    if (facebookLikes > 17222222.222) {
        facebookLikes = 17222222.222;
    }
    
    std::cout << "NUMBER OF SOUNDCLOUD FOLLOWERS: ";
    double soundcloudFollowers;
    std::cin >> soundcloudFollowers;
    if (soundcloudFollowers > 641111.111) {
        soundcloudFollowers = 641111.111;
    }
    std::cout << "NUMBER OF ANNUAL VENUE SHOWS: ";
    double venueShows;
    std::cin >> venueShows;
    if (venueShows > 29.889){
        venueShows = 29.889;
    }
    
    std::cout << "NUMBER OF PRESS ARTICLES (IN LAST 12 MONTHS): ";
    double pressArticles;
    std::cin >> pressArticles;
    if (pressArticles > 13.889) {
        pressArticles = 13.889;
    }
    
    std::cout << "NUMBER OF TELEVISION APPEARANCES (IN LAST 12 MONTHS): ";
    double tvAppearances;
    std::cin >> tvAppearances;
    if (tvAppearances > 10.778) {
        tvAppearances = 10.778;
    }
    
    std::cout << "NUMBER OF PAID PRODUCT ENDORSEMENTS: ";
    double productEndorsements;
    std::cin >> productEndorsements;
    if (productEndorsements > 2.111) {
        productEndorsements = 2.111;
    }
    
    std::cout << "NUMBER OF ARTIST CO-SIGNS: ";
    double artistCosigns;
    std::cin >> artistCosigns;
    if (artistCosigns > 2.111) {
        artistCosigns = 2.111;
    }
    
    //  PART IIA
    //  ALOGRITHM CALCULATION
    //  (ITEMIZED)
    
    std::cout << "\nThe itemized GARA SCORE (not shown to user) is as follows: " << std::endl;
    
    double wtd_weeklyRadioSpins = (((weeklyRadioSpins / 8944.444) * 100) * .15);
    std::cout << "\nRADIO SPIN SCORE: " << wtd_weeklyRadioSpins << " out of 15.000" << std::endl;
    
    double wtd_youtubeAgg = (((youtubeAgg / 1005555.556) * 100) * .16333);
    std::cout << "YOUTUBE/VEVO SCORE: " << wtd_youtubeAgg << " out of 16.333" << std::endl;
    
    double wtd_recordSales = (((recordSales / 19937500.000) * 100) * .16556);
    std::cout << "RECORD SALES SCORE: " << wtd_recordSales << " out of 16.556" << std::endl;
    
    // Insert code to calculate weight chart score (must go over logic)
    std::cout << "BILLBOARD SCORE: " << wtd_chartAverage << " out of 8.333" << std::endl;

    double wtd_twitterFollowers = (((twitterFollowers / 4888888.889) * 100) * .08667);
    std::cout << "TWITTER SCORE: " << wtd_twitterFollowers << " out of 8.667" << std::endl;
    
    double wtd_facebookLikes = (((facebookLikes / 17222222.222) * 100) * .05444);
    std::cout << "FACEBOOK SCORE: " << wtd_facebookLikes << " out of 5.444" << std::endl;
    
    double wtd_soundcloudFollowers = (((soundcloudFollowers / 641111.111) * 100) * .05778);
    std::cout << "SOUNDCLOUD SCORE: " << wtd_soundcloudFollowers << " out of 5.778" << std::endl;
    
    double wtd_venueShows = (((venueShows / 29.889) * 100) * .06000);
    std::cout << "LIVE PERFORMANCE SCORE: " << wtd_venueShows << " out of 6.000" << std::endl;
    
    double wtd_pressArticles = (((pressArticles / 13.889) * 100) * .05000);
    std::cout << "PRESS SCORE: " << wtd_pressArticles << " out of 5.000" << std::endl;
    
    double wtd_tvAppearances = (((tvAppearances / 10.778) * 100) * .10333);
    std::cout << "TV APPEARANCE SCORE: " << wtd_tvAppearances << " out of 10.333" << std::endl;
    
    double wtd_productEndorsements = (((productEndorsements / 2.111) * 100) * .01889);
    std::cout << "PRODUCT ENDORSEMENT SCORE: " << wtd_productEndorsements << " out of 1.889" << std::endl;
    
    double wtd_artistCosigns = (((artistCosigns / 2.111) * 100) * .006670);
    std::cout << "ARTIST CO-SIGN SCORE: " << wtd_artistCosigns << " out of .667" << std::endl;
    
    //  PART IIB
    //  ALOGRITHM CALCULATION
    //  (TOTAL)
    
    //  Don't forget to add the chart position variable once the logic is sorted out above
    double totalGARAScore = (wtd_weeklyRadioSpins + wtd_youtubeAgg + wtd_recordSales + wtd_chartAverage +wtd_twitterFollowers + wtd_facebookLikes + wtd_soundcloudFollowers + wtd_venueShows + wtd_pressArticles + wtd_tvAppearances + wtd_productEndorsements + wtd_artistCosigns);
    std::cout << "\n" << userName << "," << "YOUR FINAL G-SCORE IS... " << std::endl;
    
    if (hasDeal == 1){
        std::cout << "\n********************* " << (totalGARAScore * 8) << "/800" << " *********************" << std::endl;
    }
    else
        std::cout << "\n********************* " << ((totalGARAScore * 8) * 1.618) << "/800" << " *********************" << std::endl;

    return 0;
}

