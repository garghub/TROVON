static void F_1 ( enum V_1 V_2 , const char * V_3 )
{
if ( ! V_4 )
return;
F_2 ( 0 , V_4 + V_5 ) ;
F_2 ( V_6 ,
V_4 + V_7 ) ;
F_2 ( V_8 ,
V_4 + V_9 ) ;
F_2 ( V_10 ,
V_4 + V_11 ) ;
while ( 1 ) {
F_3 ( 5 ) ;
F_2 ( V_8 ,
V_4 + V_9 ) ;
}
}
static int F_4 ( struct V_12 * V_13 )
{
V_4 = F_5 ( V_13 -> V_14 . V_15 , 0 ) ;
if ( ! V_4 ) {
F_6 ( 1 , L_1 ) ;
return - V_16 ;
}
V_17 = F_1 ;
return 0 ;
}
