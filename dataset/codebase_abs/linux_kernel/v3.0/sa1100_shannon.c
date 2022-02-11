static int F_1 ( struct V_1 * V_2 )
{
V_3 &= ~ ( V_4 | V_5 |
V_6 | V_7 ) ;
V_8 &= ~ ( V_4 | V_5 |
V_6 | V_7 ) ;
V_2 -> V_9 . V_10 = V_2 -> V_11 ? V_12 : V_13 ;
return F_2 ( V_2 , V_14 , F_3 ( V_14 ) ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_14 , F_3 ( V_14 ) ) ;
}
static void
F_6 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
unsigned long V_17 = V_18 ;
switch ( V_2 -> V_11 ) {
case 0 :
V_16 -> V_19 = ( V_17 & V_4 ) ? 0 : 1 ;
V_16 -> V_20 = ( V_17 & V_6 ) ? 1 : 0 ;
V_16 -> V_21 = 0 ;
V_16 -> V_22 = 1 ;
V_16 -> V_23 = 1 ;
V_16 -> V_24 = 1 ;
V_16 -> V_25 = 0 ;
break;
case 1 :
V_16 -> V_19 = ( V_17 & V_5 ) ? 0 : 1 ;
V_16 -> V_20 = ( V_17 & V_7 ) ? 1 : 0 ;
V_16 -> V_21 = 0 ;
V_16 -> V_22 = 1 ;
V_16 -> V_23 = 1 ;
V_16 -> V_24 = 1 ;
V_16 -> V_25 = 0 ;
break;
}
}
static int
F_7 ( struct V_1 * V_2 ,
const T_1 * V_16 )
{
switch ( V_16 -> V_26 ) {
case 0 :
F_8 ( V_27 L_1 , V_28 ) ;
break;
case 50 :
F_8 ( V_27 L_2 , V_28 ) ;
case 33 :
break;
default:
F_8 ( V_29 L_3 ,
V_28 , V_16 -> V_26 ) ;
return - 1 ;
}
F_8 ( V_27 L_4 , V_28 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_14 , F_3 ( V_14 ) ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_12 ( V_2 , V_14 , F_3 ( V_14 ) ) ;
}
int T_2 F_13 ( struct V_30 * V_31 )
{
int V_32 = - V_33 ;
if ( F_14 () )
V_32 = F_15 ( V_31 , & V_34 , 0 , 2 ) ;
return V_32 ;
}
