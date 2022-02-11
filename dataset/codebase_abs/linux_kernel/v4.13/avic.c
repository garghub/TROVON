static int F_1 ( unsigned int V_1 , unsigned int type )
{
unsigned int V_2 ;
if ( V_1 >= V_3 )
return - V_4 ;
if ( V_1 < V_3 / 2 ) {
V_2 = F_2 ( V_5 + V_6 ) & ~ ( 1 << V_1 ) ;
F_3 ( V_2 | ( ! ! type << V_1 ) , V_5 + V_6 ) ;
} else {
V_1 -= V_3 / 2 ;
V_2 = F_2 ( V_5 + V_7 ) & ~ ( 1 << V_1 ) ;
F_3 ( V_2 | ( ! ! type << V_1 ) , V_5 + V_7 ) ;
}
return 0 ;
}
static void F_4 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
int V_15 = V_9 -> V_1 >> 5 ;
V_16 [ V_15 ] = F_2 ( V_5 + V_13 -> V_17 . V_18 ) ;
F_3 ( V_11 -> V_19 , V_5 + V_13 -> V_17 . V_18 ) ;
}
static void F_6 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
int V_15 = V_9 -> V_1 >> 5 ;
F_3 ( V_16 [ V_15 ] , V_5 + V_13 -> V_17 . V_18 ) ;
}
static T_1 void F_7 ( int V_15 , unsigned int V_20 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
V_11 = F_8 ( L_1 , 1 , V_20 , V_5 ,
V_21 ) ;
V_11 -> V_22 = & V_23 ;
V_11 -> V_24 = F_9 ( 32 ) ;
V_13 = V_11 -> V_14 ;
V_13 -> V_25 . V_26 = V_27 ;
V_13 -> V_25 . V_28 = V_29 ;
V_13 -> V_25 . V_30 = V_27 ;
V_13 -> V_25 . V_31 = V_32 ;
V_13 -> V_25 . V_33 = F_4 ;
V_13 -> V_25 . V_34 = F_6 ;
V_13 -> V_17 . V_18 = ! V_15 ? V_35 : V_36 ;
V_13 -> V_17 . V_37 = V_13 -> V_17 . V_18 ;
F_10 ( V_11 , F_9 ( 32 ) , 0 , V_38 , 0 ) ;
}
static void T_2 F_11 ( struct V_39 * V_17 )
{
T_3 V_40 ;
do {
V_40 = F_2 ( V_5 + V_41 ) >> 16 ;
if ( V_40 == 0xffff )
break;
F_12 ( V_42 , V_40 , V_17 ) ;
} while ( 1 );
}
void T_1 F_13 ( void T_4 * V_43 )
{
struct V_44 * V_45 ;
int V_46 ;
int V_47 ;
V_5 = V_43 ;
F_3 ( 0 , V_5 + V_48 ) ;
F_3 ( 0x1f , V_5 + V_49 ) ;
F_3 ( 0 , V_5 + V_36 ) ;
F_3 ( 0 , V_5 + V_35 ) ;
F_3 ( 0 , V_5 + V_7 ) ;
F_3 ( 0 , V_5 + V_6 ) ;
V_46 = F_14 ( - 1 , 0 , V_3 , F_15 () ) ;
F_16 ( V_46 < 0 ) ;
V_45 = F_17 ( NULL , NULL , L_2 ) ;
V_42 = F_18 ( V_45 , V_3 , V_46 , 0 ,
& V_50 , NULL ) ;
F_16 ( ! V_42 ) ;
for ( V_47 = 0 ; V_47 < V_3 / 32 ; V_47 ++ , V_46 += 32 )
F_7 ( V_47 , V_46 ) ;
for ( V_47 = 0 ; V_47 < 8 ; V_47 ++ )
F_3 ( 0 , V_5 + F_19 ( V_47 ) ) ;
F_20 ( F_11 ) ;
#ifdef F_21
F_22 ( V_51 ) ;
#endif
F_23 ( V_52 L_3 ) ;
}
