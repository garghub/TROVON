static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 | V_4 | V_5 | V_6 ) ;
V_2 -> V_7 [ V_8 ] . V_9 = V_10 ;
V_2 -> V_7 [ V_8 ] . V_11 = L_1 ;
V_2 -> V_7 [ V_12 ] . V_9 = V_13 ;
V_2 -> V_7 [ V_12 ] . V_11 = L_2 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_2 ( V_14 ) ;
}
static void
F_4 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
long V_17 = F_5 () ;
V_16 -> V_18 = ! V_16 -> V_18 ;
V_16 -> V_19 = 1 ;
V_16 -> V_20 = 1 ;
if ( ( V_17 & ( V_21 | V_22 ) ) ==
( V_21 | V_22 ) ) {
V_16 -> V_23 = 0 ;
V_16 -> V_24 = 0 ;
} else {
V_16 -> V_23 = 1 ;
V_16 -> V_24 = 0 ;
}
}
static int
F_6 ( struct V_1 * V_2 ,
const T_1 * V_16 )
{
unsigned long V_25 ;
F_7 ( V_25 ) ;
switch ( V_16 -> V_26 ) {
case 0 :
F_2 ( V_3 | V_4 | V_5 | V_6 ) ;
break;
case 33 :
F_2 ( V_3 | V_6 ) ;
F_8 ( V_4 | V_5 ) ;
break;
case 50 :
F_2 ( V_4 | V_6 ) ;
F_8 ( V_3 | V_5 ) ;
break;
default:
F_9 ( V_27 L_3 ,
V_28 , V_16 -> V_26 ) ;
F_2 ( V_3 | V_4 | V_5 | V_6 ) ;
F_10 ( V_25 ) ;
return - 1 ;
}
F_10 ( V_25 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_8 ( V_14 ) ;
}
int F_12 ( struct V_29 * V_30 )
{
int V_31 = - V_32 ;
if ( F_13 () )
V_31 = F_14 ( V_30 , & V_33 , 1 , 1 ) ;
return V_31 ;
}
