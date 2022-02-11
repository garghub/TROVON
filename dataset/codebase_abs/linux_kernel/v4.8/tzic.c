static int F_1 ( unsigned int V_1 , unsigned int type )
{
unsigned int V_2 , V_3 , V_4 ;
V_2 = V_1 >> 5 ;
if ( F_2 ( V_2 >= 4 ) )
return - V_5 ;
V_3 = 1U << ( V_1 & 0x1F ) ;
V_4 = F_3 ( V_6 + F_4 ( V_2 ) ) | V_3 ;
if ( type )
V_4 &= ~ V_3 ;
F_5 ( V_4 , V_6 + F_4 ( V_2 ) ) ;
return 0 ;
}
static void F_6 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_7 ( V_8 ) ;
int V_11 = V_8 -> V_1 >> 5 ;
F_5 ( V_10 -> V_12 , V_6 + F_8 ( V_11 ) ) ;
}
static void F_9 ( struct V_7 * V_8 )
{
int V_11 = V_8 -> V_1 >> 5 ;
F_5 ( F_3 ( V_6 + F_10 ( V_11 ) ) ,
V_6 + F_8 ( V_11 ) ) ;
}
static T_1 void F_11 ( int V_11 , unsigned int V_13 )
{
struct V_9 * V_10 ;
struct V_14 * V_15 ;
V_10 = F_12 ( L_1 , 1 , V_13 , V_6 ,
V_16 ) ;
V_10 -> V_17 = & V_18 ;
V_10 -> V_19 = F_13 ( 32 ) ;
V_15 = V_10 -> V_20 ;
V_15 -> V_21 . V_22 = V_23 ;
V_15 -> V_21 . V_24 = V_25 ;
V_15 -> V_21 . V_26 = V_27 ;
V_15 -> V_21 . V_28 = F_6 ;
V_15 -> V_21 . V_29 = F_9 ;
V_15 -> V_30 . V_31 = F_14 ( V_11 ) ;
V_15 -> V_30 . V_32 = F_10 ( V_11 ) ;
F_15 ( V_10 , F_13 ( 32 ) , 0 , V_33 , 0 ) ;
}
static void T_2 F_16 ( struct V_34 * V_30 )
{
T_3 V_35 ;
int V_36 , V_37 , V_38 ;
do {
V_38 = 0 ;
for ( V_36 = 0 ; V_36 < 4 ; V_36 ++ ) {
V_35 = F_3 ( V_6 + F_17 ( V_36 ) ) &
F_3 ( V_6 + F_4 ( V_36 ) ) ;
while ( V_35 ) {
V_38 = 1 ;
V_37 = F_18 ( V_35 ) - 1 ;
F_19 ( V_39 , V_37 + V_36 * 32 , V_30 ) ;
V_35 &= ~ ( 1 << V_37 ) ;
}
}
} while ( V_38 );
}
static int T_1 F_20 ( struct V_40 * V_41 , struct V_40 * V_42 )
{
int V_43 ;
int V_36 ;
V_6 = F_21 ( V_41 , 0 ) ;
F_22 ( ! V_6 ) ;
V_36 = F_3 ( V_6 + V_44 ) ;
F_5 ( 0x80010001 , V_6 + V_44 ) ;
F_5 ( 0x1f , V_6 + V_45 ) ;
F_5 ( 0x02 , V_6 + V_46 ) ;
for ( V_36 = 0 ; V_36 < 4 ; V_36 ++ )
F_5 ( 0xFFFFFFFF , V_6 + F_4 ( V_36 ) ) ;
for ( V_36 = 0 ; V_36 < 4 ; V_36 ++ )
F_5 ( 0xFFFFFFFF , V_6 + F_14 ( V_36 ) ) ;
V_43 = F_23 ( - 1 , 0 , V_47 , F_24 () ) ;
F_22 ( V_43 < 0 ) ;
V_39 = F_25 ( V_41 , V_47 , V_43 , 0 ,
& V_48 , NULL ) ;
F_22 ( ! V_39 ) ;
for ( V_36 = 0 ; V_36 < 4 ; V_36 ++ , V_43 += 32 )
F_11 ( V_36 , V_43 ) ;
F_26 ( F_16 ) ;
#ifdef F_27
F_28 ( V_49 ) ;
#endif
F_29 ( L_2 ) ;
return 0 ;
}
int F_30 ( void )
{
unsigned int V_36 ;
F_5 ( 1 , V_6 + V_50 ) ;
if ( F_2 ( F_3 ( V_6 + V_50 ) == 0 ) )
return - V_51 ;
for ( V_36 = 0 ; V_36 < 4 ; V_36 ++ )
F_5 ( F_3 ( V_6 + F_10 ( V_36 ) ) ,
V_6 + F_8 ( V_36 ) ) ;
return 0 ;
}
