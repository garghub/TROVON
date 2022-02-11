static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = V_5 ;
return F_2 ( V_2 , V_6 , F_3 ( V_6 ) ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_6 , F_3 ( V_6 ) ) ;
}
static void
F_6 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
unsigned long V_9 = V_10 ;
V_8 -> V_11 = ( V_9 & V_12 ) ? 0 : 1 ;
V_8 -> V_13 = ( V_9 & V_14 ) ? 1 : 0 ;
V_8 -> V_15 = ( V_9 & V_16 ) ? 1 : 0 ;
V_8 -> V_17 = ( V_9 & V_18 ) ? 1 : 0 ;
V_8 -> V_19 = 0 ;
V_8 -> V_20 = 1 ;
V_8 -> V_21 = 0 ;
}
static int
F_7 ( struct V_1 * V_2 , const T_1 * V_8 )
{
unsigned int V_22 ;
switch ( V_8 -> V_23 ) {
case 0 :
V_22 = 0 ;
break;
case 50 :
F_8 ( V_24 L_1 ,
V_25 ) ;
case 33 :
V_22 = V_26 ;
break;
default:
F_8 ( V_27 L_2 , V_25 ,
V_8 -> V_23 ) ;
return - 1 ;
}
if ( V_8 -> V_28 & V_29 )
V_22 |= V_30 ;
F_9 ( V_30 | V_26 , V_22 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_11 ( V_31 ) ;
F_12 ( V_2 , V_6 , F_3 ( V_6 ) ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_14 ( V_2 , V_6 , F_3 ( V_6 ) ) ;
F_15 ( V_31 | V_30 ) ;
}
int T_2 F_16 ( struct V_32 * V_33 )
{
int V_34 = - V_35 ;
if ( F_17 () && ! F_18 () )
V_34 = F_19 ( V_33 , & V_36 , 1 , 1 ) ;
return V_34 ;
}
