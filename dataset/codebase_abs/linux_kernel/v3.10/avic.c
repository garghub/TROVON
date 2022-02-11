static int F_1 ( unsigned char V_1 , unsigned char V_2 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
unsigned int V_5 ;
unsigned int V_6 = 0x0F << V_1 % 8 * 4 ;
V_1 = V_4 -> V_7 ;
if ( V_1 >= V_8 )
return - V_9 ;
V_5 = F_3 ( V_10 + F_4 ( V_1 / 8 ) ) ;
V_5 &= ~ V_6 ;
V_5 |= V_2 & V_6 ;
F_5 ( V_5 , V_10 + F_4 ( V_1 / 8 ) ) ;
return 0 ;
}
static int F_6 ( unsigned int V_1 , unsigned int type )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
unsigned int V_11 ;
V_1 = V_4 -> V_7 ;
if ( V_1 >= V_8 )
return - V_9 ;
if ( V_1 < V_8 / 2 ) {
V_11 = F_3 ( V_10 + V_12 ) & ~ ( 1 << V_1 ) ;
F_5 ( V_11 | ( ! ! type << V_1 ) , V_10 + V_12 ) ;
} else {
V_1 -= V_8 / 2 ;
V_11 = F_3 ( V_10 + V_13 ) & ~ ( 1 << V_1 ) ;
F_5 ( V_11 | ( ! ! type << V_1 ) , V_10 + V_13 ) ;
}
return 0 ;
}
static void F_7 ( struct V_3 * V_4 )
{
struct V_14 * V_15 = F_8 ( V_4 ) ;
struct V_16 * V_17 = V_15 -> V_18 ;
int V_19 = V_4 -> V_7 >> 5 ;
V_20 [ V_19 ] = F_3 ( V_10 + V_17 -> V_21 . V_6 ) ;
F_5 ( V_15 -> V_22 , V_10 + V_17 -> V_21 . V_6 ) ;
}
static void F_9 ( struct V_3 * V_4 )
{
struct V_14 * V_15 = F_8 ( V_4 ) ;
struct V_16 * V_17 = V_15 -> V_18 ;
int V_19 = V_4 -> V_7 >> 5 ;
F_5 ( V_20 [ V_19 ] , V_10 + V_17 -> V_21 . V_6 ) ;
}
static T_1 void F_10 ( int V_19 , unsigned int V_23 )
{
struct V_14 * V_15 ;
struct V_16 * V_17 ;
V_15 = F_11 ( L_1 , 1 , V_23 , V_10 ,
V_24 ) ;
V_15 -> V_25 = & V_26 ;
V_15 -> V_27 = F_12 ( 32 ) ;
V_17 = V_15 -> V_18 ;
V_17 -> V_28 . V_29 = V_30 ;
V_17 -> V_28 . V_31 = V_32 ;
V_17 -> V_28 . V_33 = V_30 ;
V_17 -> V_28 . V_34 = V_35 ;
V_17 -> V_28 . V_36 = F_7 ;
V_17 -> V_28 . V_37 = F_9 ;
V_17 -> V_21 . V_6 = ! V_19 ? V_38 : V_39 ;
V_17 -> V_21 . V_40 = V_17 -> V_21 . V_6 ;
F_13 ( V_15 , F_12 ( 32 ) , 0 , V_41 , 0 ) ;
}
T_2 void T_3 F_14 ( struct V_42 * V_21 )
{
T_4 V_43 ;
do {
V_43 = F_3 ( V_10 + V_44 ) >> 16 ;
if ( V_43 == 0xffff )
break;
F_15 ( F_16 ( V_45 , V_43 ) , V_21 ) ;
} while ( 1 );
}
void T_1 F_17 ( void T_5 * V_46 )
{
struct V_47 * V_48 ;
int V_49 ;
int V_50 ;
V_10 = V_46 ;
F_5 ( 0 , V_10 + V_51 ) ;
F_5 ( 0x1f , V_10 + V_52 ) ;
F_5 ( 0 , V_10 + V_39 ) ;
F_5 ( 0 , V_10 + V_38 ) ;
F_5 ( 0 , V_10 + V_13 ) ;
F_5 ( 0 , V_10 + V_12 ) ;
V_49 = F_18 ( - 1 , 0 , V_8 , F_19 () ) ;
F_20 ( V_49 < 0 ) ;
V_48 = F_21 ( NULL , NULL , L_2 ) ;
V_45 = F_22 ( V_48 , V_8 , V_49 , 0 ,
& V_53 , NULL ) ;
F_20 ( ! V_45 ) ;
for ( V_50 = 0 ; V_50 < V_8 / 32 ; V_50 ++ , V_49 += 32 )
F_10 ( V_50 , V_49 ) ;
for ( V_50 = 0 ; V_50 < 8 ; V_50 ++ )
F_5 ( 0 , V_10 + F_4 ( V_50 ) ) ;
#ifdef F_23
F_24 ( V_54 ) ;
#endif
F_25 ( V_55 L_3 ) ;
}
