static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int * V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 , V_3 ) ;
if ( V_5 >= 0 )
* V_4 = V_2 -> V_6 [ V_5 ] . V_7 ;
return V_5 ;
}
static int F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 , V_3 ) ;
if ( V_5 < 0 )
return F_4 ( V_2 , V_3 , V_4 ) ;
V_2 -> V_6 [ V_5 ] . V_7 = V_4 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
unsigned int V_8 ;
int V_5 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_9 ; V_8 ++ ) {
V_5 = F_6 ( V_2 , V_2 -> V_6 [ V_8 ] . V_3 ,
V_2 -> V_6 [ V_8 ] . V_7 ) ;
if ( V_5 < 0 )
return V_5 ;
F_7 ( V_2 -> V_10 , L_1 ,
V_2 -> V_6 [ V_8 ] . V_3 ,
V_2 -> V_6 [ V_8 ] . V_7 ) ;
}
return 0 ;
}
