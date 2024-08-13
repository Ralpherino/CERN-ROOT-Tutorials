void tut3()
{
    TH1F *hist = new TH1F("hist", "Histogram", 6, 1, 7);
    
    fstream file;
    file.open("data.txt", ios::in);
    
    double value; 
    
    while(1)
    {
        file >> value;
        hist -> Fill(value);
        if(file.eof()) break;
    }
   
    
    hist->GetXaxis()->SetTitle("X Axis");
    hist->GetYaxis()->SetTitle("Y Axis");
    
    
    
    TCanvas *c1 =  new TCanvas();    
    hist->Draw();
      
}
