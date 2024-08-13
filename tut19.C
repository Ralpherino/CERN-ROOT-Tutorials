void tut19()
{
  TCanvas *c1 = new TCanvas();
  
  TProfile *hprof = new TProfile("hprof","Histogram",100,0,10,"S");
  
  TRandom3 *rand = new TRandom3();
  for(int i=0; i<1000; i++)
  {
     hprof->Fill(rand->Rndm()*10,rand->Rndm());
  }
  hprof->Draw();
}
