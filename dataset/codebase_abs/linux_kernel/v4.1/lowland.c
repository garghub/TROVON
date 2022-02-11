static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
V_5 = F_2 ( V_4 , V_6 ,
V_7 , V_8 ,
V_9 ) ;
if ( V_5 < 0 ) {
F_3 ( L_1 , V_5 ) ;
return V_5 ;
}
V_5 = F_2 ( V_4 , V_10 , 0 ,
V_11 , 0 ) ;
if ( V_5 < 0 ) {
F_3 ( L_2 , V_5 ) ;
return V_5 ;
}
V_5 = F_4 ( V_2 -> V_12 , L_3 , V_13 |
V_14 | V_15 ,
& V_16 , V_17 ,
F_5 ( V_17 ) ) ;
if ( V_5 )
return V_5 ;
F_6 ( V_4 , & V_16 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_8 ( & V_4 -> V_18 , L_4 ) ;
return F_2 ( V_4 , V_19 , 0 ,
V_11 , 0 ) ;
}
static int F_9 ( struct V_20 * V_21 )
{
struct V_22 * V_12 = & V_23 ;
int V_5 ;
V_12 -> V_24 = & V_21 -> V_24 ;
V_5 = F_10 ( & V_21 -> V_24 , V_12 ) ;
if ( V_5 )
F_11 ( & V_21 -> V_24 , L_5 ,
V_5 ) ;
return V_5 ;
}
