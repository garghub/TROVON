static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 | V_4 | V_5 | V_6 ) ;
V_2 -> V_7 . V_8 = V_9 ;
return F_3 ( V_2 , V_10 , F_4 ( V_10 ) ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_10 , F_4 ( V_10 ) ) ;
F_2 ( V_11 ) ;
}
static void
F_7 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
unsigned long V_14 = V_15 ;
long V_16 = F_8 () ;
V_13 -> V_17 = ( ( V_14 & V_18 ) == 0 ) ? 1 : 0 ;
V_13 -> V_19 = ( V_14 & V_20 ) ? 1 : 0 ;
V_13 -> V_21 = 1 ;
V_13 -> V_22 = 1 ;
V_13 -> V_23 = 0 ;
if ( ( V_16 & ( V_24 | V_25 ) ) ==
( V_24 | V_25 ) ) {
V_13 -> V_26 = 0 ;
V_13 -> V_27 = 0 ;
} else {
V_13 -> V_26 = 1 ;
V_13 -> V_27 = 0 ;
}
}
static int
F_9 ( struct V_1 * V_2 ,
const T_1 * V_13 )
{
unsigned long V_28 ;
F_10 ( V_28 ) ;
switch ( V_13 -> V_29 ) {
case 0 :
F_2 ( V_3 | V_4 | V_5 | V_6 ) ;
break;
case 33 :
F_2 ( V_3 | V_6 ) ;
F_11 ( V_4 | V_5 ) ;
break;
case 50 :
F_2 ( V_4 | V_6 ) ;
F_11 ( V_3 | V_5 ) ;
break;
default:
F_12 ( V_30 L_1 ,
V_31 , V_13 -> V_29 ) ;
F_2 ( V_3 | V_4 | V_5 | V_6 ) ;
F_13 ( V_28 ) ;
return - 1 ;
}
F_13 ( V_28 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_15 ( V_2 , V_10 , F_4 ( V_10 ) ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_10 , F_4 ( V_10 ) ) ;
F_11 ( V_11 ) ;
}
int T_2 F_18 ( struct V_32 * V_33 )
{
int V_34 = - V_35 ;
if ( F_19 () )
V_34 = F_20 ( V_33 , & V_36 , 1 , 1 ) ;
return V_34 ;
}
