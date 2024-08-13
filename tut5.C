void tut5()

{
  TRandom *rand = new TRandom2();
  
  TH1F *hist = new TH1F("hist","Histogram", 100, 0, 100);
  
  for (int i=0; i<3; i++)
  
  {
    double r = rand->Rndm();
    cout << r << endl;
    hist->Fill(r);
  }
  TCanvas *c1 = new TCanvas();
  hist-> GetYaxis()->SetRange(0,200);
  hist->Draw();
}
