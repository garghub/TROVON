int
F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * * V_5 )
{
if ( V_3 == V_6 ) {
return F_2 ( & V_7 , V_2 , V_3 ,
0x00000040 , true , V_5 ) ;
} else
if ( V_3 == V_8 ) {
return F_2 ( & V_7 , V_2 , V_3 ,
0x00000080 , true , V_5 ) ;
} else
if ( V_3 == V_9 ) {
return F_2 ( & V_7 , V_2 , V_3 ,
0x00200000 , true , V_5 ) ;
}
return - V_10 ;
}
