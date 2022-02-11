static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
int V_11 ;
V_11 = F_2 ( V_10 , V_12
| V_13
| V_14 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_2 ( V_9 , V_12
| V_13
| V_14 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_3 ( struct V_5 * V_6 )
{
struct V_15 * V_16 = V_6 -> V_16 ;
int V_11 ;
V_11 = F_4 ( V_16 , V_17 ,
V_18 , V_19 ,
V_20 ) ;
if ( V_11 < 0 ) {
F_5 ( L_1 , V_11 ) ;
return V_11 ;
}
V_11 = F_4 ( V_16 , V_21 , 0 ,
V_22 , 0 ) ;
if ( V_11 < 0 ) {
F_5 ( L_2 , V_11 ) ;
return V_11 ;
}
V_11 = F_6 ( V_16 , L_3 ,
V_23 | V_24 |
V_25 ,
& V_26 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_7 ( & V_26 ,
F_8 ( V_27 ) ,
V_27 ) ;
if ( V_11 )
return V_11 ;
F_9 ( V_16 , & V_26 ) ;
return 0 ;
}
static int F_10 ( struct V_28 * V_29 )
{
F_11 ( V_29 , L_4 ) ;
return F_4 ( V_29 -> V_16 , V_30 , 0 ,
V_22 , 0 ) ;
}
static T_1 int F_12 ( struct V_31 * V_32 )
{
struct V_33 * V_34 = & V_35 ;
int V_11 ;
V_34 -> V_36 = & V_32 -> V_36 ;
V_11 = F_13 ( V_34 ) ;
if ( V_11 ) {
F_14 ( & V_32 -> V_36 , L_5 ,
V_11 ) ;
return V_11 ;
}
return 0 ;
}
static int T_2 F_15 ( struct V_31 * V_32 )
{
struct V_33 * V_34 = F_16 ( V_32 ) ;
F_17 ( V_34 ) ;
return 0 ;
}
