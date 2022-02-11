static int F_1 ( unsigned int V_1 , unsigned int type )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
unsigned int V_4 ;
V_1 = V_3 -> V_5 ;
if ( V_1 >= V_6 )
return - V_7 ;
if ( V_1 < V_6 / 2 ) {
V_4 = F_3 ( V_8 + V_9 ) & ~ ( 1 << V_1 ) ;
F_4 ( V_4 | ( ! ! type << V_1 ) , V_8 + V_9 ) ;
} else {
V_1 -= V_6 / 2 ;
V_4 = F_3 ( V_8 + V_10 ) & ~ ( 1 << V_1 ) ;
F_4 ( V_4 | ( ! ! type << V_1 ) , V_8 + V_10 ) ;
}
return 0 ;
}
static void F_5 ( struct V_2 * V_3 )
{
struct V_11 * V_12 = F_6 ( V_3 ) ;
struct V_13 * V_14 = V_12 -> V_15 ;
int V_16 = V_3 -> V_5 >> 5 ;
V_17 [ V_16 ] = F_3 ( V_8 + V_14 -> V_18 . V_19 ) ;
F_4 ( V_12 -> V_20 , V_8 + V_14 -> V_18 . V_19 ) ;
}
static void F_7 ( struct V_2 * V_3 )
{
struct V_11 * V_12 = F_6 ( V_3 ) ;
struct V_13 * V_14 = V_12 -> V_15 ;
int V_16 = V_3 -> V_5 >> 5 ;
F_4 ( V_17 [ V_16 ] , V_8 + V_14 -> V_18 . V_19 ) ;
}
static T_1 void F_8 ( int V_16 , unsigned int V_21 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 ;
V_12 = F_9 ( L_1 , 1 , V_21 , V_8 ,
V_22 ) ;
V_12 -> V_23 = & V_24 ;
V_12 -> V_25 = F_10 ( 32 ) ;
V_14 = V_12 -> V_15 ;
V_14 -> V_26 . V_27 = V_28 ;
V_14 -> V_26 . V_29 = V_30 ;
V_14 -> V_26 . V_31 = V_28 ;
V_14 -> V_26 . V_32 = V_33 ;
V_14 -> V_26 . V_34 = F_5 ;
V_14 -> V_26 . V_35 = F_7 ;
V_14 -> V_18 . V_19 = ! V_16 ? V_36 : V_37 ;
V_14 -> V_18 . V_38 = V_14 -> V_18 . V_19 ;
F_11 ( V_12 , F_10 ( 32 ) , 0 , V_39 , 0 ) ;
}
static void T_2 F_12 ( struct V_40 * V_18 )
{
T_3 V_41 ;
do {
V_41 = F_3 ( V_8 + V_42 ) >> 16 ;
if ( V_41 == 0xffff )
break;
F_13 ( V_43 , V_41 , V_18 ) ;
} while ( 1 );
}
void T_1 F_14 ( void T_4 * V_44 )
{
struct V_45 * V_46 ;
int V_47 ;
int V_48 ;
V_8 = V_44 ;
F_4 ( 0 , V_8 + V_49 ) ;
F_4 ( 0x1f , V_8 + V_50 ) ;
F_4 ( 0 , V_8 + V_37 ) ;
F_4 ( 0 , V_8 + V_36 ) ;
F_4 ( 0 , V_8 + V_10 ) ;
F_4 ( 0 , V_8 + V_9 ) ;
V_47 = F_15 ( - 1 , 0 , V_6 , F_16 () ) ;
F_17 ( V_47 < 0 ) ;
V_46 = F_18 ( NULL , NULL , L_2 ) ;
V_43 = F_19 ( V_46 , V_6 , V_47 , 0 ,
& V_51 , NULL ) ;
F_17 ( ! V_43 ) ;
for ( V_48 = 0 ; V_48 < V_6 / 32 ; V_48 ++ , V_47 += 32 )
F_8 ( V_48 , V_47 ) ;
for ( V_48 = 0 ; V_48 < 8 ; V_48 ++ )
F_4 ( 0 , V_8 + F_20 ( V_48 ) ) ;
F_21 ( F_12 ) ;
#ifdef F_22
F_23 ( V_52 ) ;
#endif
F_24 ( V_53 L_3 ) ;
}
