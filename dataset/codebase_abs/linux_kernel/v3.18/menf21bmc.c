static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
V_3 = F_2 ( V_2 , V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_3 == 0x00 ) {
F_3 ( & V_2 -> V_6 ,
L_1 ) ;
V_4 = F_4 ( V_2 , V_7 ) ;
if ( V_4 < 0 )
return V_4 ;
}
return 0 ;
}
static int
F_5 ( struct V_1 * V_2 , const struct V_8 * V_9 )
{
int V_10 , V_11 , V_12 ;
int V_4 ;
V_4 = F_6 ( V_2 -> V_13 ,
V_14 |
V_15 |
V_16 ) ;
if ( ! V_4 )
return - V_17 ;
V_10 = F_7 ( V_2 , V_18 ) ;
if ( V_10 < 0 ) {
F_8 ( & V_2 -> V_6 , L_2 ) ;
return V_10 ;
}
V_11 = F_7 ( V_2 , V_19 ) ;
if ( V_11 < 0 ) {
F_8 ( & V_2 -> V_6 , L_3 ) ;
return V_11 ;
}
V_12 = F_7 ( V_2 , V_20 ) ;
if ( V_12 < 0 ) {
F_8 ( & V_2 -> V_6 , L_4 ) ;
return V_12 ;
}
F_3 ( & V_2 -> V_6 , L_5 ,
V_10 , V_11 , V_12 ) ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 ) {
F_8 ( & V_2 -> V_6 , L_6 ) ;
return V_4 ;
}
V_4 = F_9 ( & V_2 -> V_6 , 0 , V_21 ,
F_10 ( V_21 ) , NULL , 0 , NULL ) ;
if ( V_4 < 0 ) {
F_8 ( & V_2 -> V_6 , L_7 ) ;
return V_4 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
F_12 ( & V_2 -> V_6 ) ;
return 0 ;
}
