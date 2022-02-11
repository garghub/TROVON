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
V_5 = F_4 ( V_4 , L_3 ,
V_12 | V_13 |
V_14 ,
& V_15 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_5 ( & V_15 ,
F_6 ( V_16 ) ,
V_16 ) ;
if ( V_5 )
return V_5 ;
F_7 ( V_4 , & V_15 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_9 ( & V_4 -> V_17 , L_4 ) ;
return F_2 ( V_4 , V_18 , 0 ,
V_11 , 0 ) ;
}
static int F_10 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = & V_23 ;
int V_5 ;
V_22 -> V_24 = & V_20 -> V_24 ;
V_5 = F_11 ( & V_20 -> V_24 , V_22 ) ;
if ( V_5 )
F_12 ( & V_20 -> V_24 , L_5 ,
V_5 ) ;
return V_5 ;
}
