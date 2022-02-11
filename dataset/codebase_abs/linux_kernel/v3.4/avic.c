static int F_1 ( unsigned char V_1 , unsigned char V_2 )
{
unsigned int V_3 ;
unsigned int V_4 = 0x0F << V_1 % 8 * 4 ;
if ( V_1 >= V_5 )
return - V_6 ;
V_3 = F_2 ( V_7 + F_3 ( V_1 / 8 ) ) ;
V_3 &= ~ V_4 ;
V_3 |= V_2 & V_4 ;
F_4 ( V_3 , V_7 + F_3 ( V_1 / 8 ) ) ;
return 0 ;
}
static int F_5 ( unsigned int V_1 , unsigned int type )
{
unsigned int V_8 ;
if ( V_1 >= V_5 )
return - V_6 ;
if ( V_1 < V_5 / 2 ) {
V_8 = F_2 ( V_7 + V_9 ) & ~ ( 1 << V_1 ) ;
F_4 ( V_8 | ( ! ! type << V_1 ) , V_7 + V_9 ) ;
} else {
V_1 -= V_5 / 2 ;
V_8 = F_2 ( V_7 + V_10 ) & ~ ( 1 << V_1 ) ;
F_4 ( V_8 | ( ! ! type << V_1 ) , V_7 + V_10 ) ;
}
return 0 ;
}
static void F_6 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_7 ( V_12 ) ;
struct V_15 * V_16 = V_14 -> V_17 ;
int V_18 = V_14 -> V_19 >> 5 ;
V_20 [ V_18 ] = F_2 ( V_7 + V_16 -> V_21 . V_4 ) ;
F_4 ( V_14 -> V_22 , V_7 + V_16 -> V_21 . V_4 ) ;
}
static void F_8 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_7 ( V_12 ) ;
struct V_15 * V_16 = V_14 -> V_17 ;
int V_18 = V_14 -> V_19 >> 5 ;
F_4 ( V_20 [ V_18 ] , V_7 + V_16 -> V_21 . V_4 ) ;
}
static T_1 void F_9 ( unsigned int V_23 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
int V_18 = V_23 >> 5 ;
V_14 = F_10 ( L_1 , 1 , V_23 , V_7 ,
V_24 ) ;
V_14 -> V_25 = & V_26 ;
V_14 -> V_27 = F_11 ( 32 ) ;
V_16 = V_14 -> V_17 ;
V_16 -> V_28 . V_29 = V_30 ;
V_16 -> V_28 . V_31 = V_32 ;
V_16 -> V_28 . V_33 = V_30 ;
V_16 -> V_28 . V_34 = V_35 ;
V_16 -> V_28 . V_36 = F_6 ;
V_16 -> V_28 . V_37 = F_8 ;
V_16 -> V_21 . V_4 = ! V_18 ? V_38 : V_39 ;
V_16 -> V_21 . V_40 = V_16 -> V_21 . V_4 ;
F_12 ( V_14 , F_11 ( 32 ) , 0 , V_41 , 0 ) ;
}
T_2 void T_3 F_13 ( struct V_42 * V_21 )
{
T_4 V_43 ;
do {
V_43 = F_2 ( V_7 + V_44 ) >> 16 ;
if ( V_43 == 0xffff )
break;
F_14 ( V_43 , V_21 ) ;
} while ( 1 );
}
void T_1 F_15 ( void T_5 * V_45 )
{
int V_46 ;
V_7 = V_45 ;
F_4 ( 0 , V_7 + V_47 ) ;
F_4 ( 0x1f , V_7 + V_48 ) ;
F_4 ( 0 , V_7 + V_39 ) ;
F_4 ( 0 , V_7 + V_38 ) ;
F_4 ( 0 , V_7 + V_10 ) ;
F_4 ( 0 , V_7 + V_9 ) ;
for ( V_46 = 0 ; V_46 < V_5 ; V_46 += 32 )
F_9 ( V_46 ) ;
for ( V_46 = 0 ; V_46 < 8 ; V_46 ++ )
F_4 ( 0 , V_7 + F_3 ( V_46 ) ) ;
#ifdef F_16
F_17 () ;
#endif
F_18 ( V_49 L_2 ) ;
}
