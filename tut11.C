void tut11()
{
    TH1F *hist = new TH1F("hist", "Histogram", 100, 0, 15);
    
    TRandom2 *rand = new TRandom2(3);
    
    fstream file;
    file.open("data.txt", ios::out);
    
    for(int i=0; i<1000; i++)
    {
       double r = rand->Gaus(5,1);
       file << r << endl;       
    }
    
    file.close();
    
    file.open("data.txt", ios::in);
        
    double value; 
    
    while(1)
    {
        file >> value;
        hist -> Fill(value);
        if(file.eof()) break;
    }
   
    hist->SetFillColor(kGreen-9);
    hist->GetXaxis()->SetTitle("Distribution");
    hist->GetYaxis()->SetTitle("Entries");
    hist->GetXaxis()->SetTitleSize(0.05);
    hist->GetYaxis()->SetTitleSize(0.05);
    hist->GetXaxis()->SetLabelSize(0.05);
    hist->GetYaxis()->SetLabelSize(0.05);
    
    
    TF1 *fit = new TF1 ("fit", "gaus", 0, 15);
    fit->SetParameter(0,45);
    fit->SetParameter(1,5);
    fit->SetParameter(2,1);
    fit->SetLineWidth(2);
    fit->SetLineColor(kBlue);
    
    TCanvas *c1 =  new TCanvas();  
    c1->SetGridx();
    c1->SetGridy(); 
    c1->SetTickx();
    c1->SetTicky(); 
    hist->SetStats(0);
    hist->Draw();
    hist->Fit("fit","R");
    
    
    TLegend *leg = new TLegend(0.5, 0.6, 0.8, 0.8);
    leg->AddEntry(hist, "Measured Data", "l");
    leg->AddEntry(fit, "Fit Function", "f");
    leg->Draw();
    leg->SetBorderSize(0);
    
    TLine *l = new TLine(0,20,15,20);
    l->SetLineWidth(2);
    l->SetLineColor(kOrange);
    l->Draw();
    
    double x0=6.3;
    int bin = hist->FindBin(x0);
    double y0 = hist->GetBinContent(bin);
    
    TArrow *arr = new TArrow(10, 30, x0, y0);
    arr->SetLineWidth(2);
    arr->SetArrowSize(0.02);
    arr->SetLineColor(kBlue);
    arr->Draw();
    
    TLatex *t = new TLatex(10, 30, "Important Point");
    t->Draw();
        
    double mean = fit->GetParameter(1);
    double sigma = fit->GetParameter(2);
    
    cout << mean/sigma << endl;
}
