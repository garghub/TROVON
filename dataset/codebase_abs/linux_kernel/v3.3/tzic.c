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
int V_11 = V_10 -> V_12 >> 5 ;
F_5 ( V_10 -> V_13 , V_6 + F_8 ( V_11 ) ) ;
}
static void F_9 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_7 ( V_8 ) ;
int V_11 = V_10 -> V_12 >> 5 ;
F_5 ( F_3 ( V_6 + F_10 ( V_11 ) ) ,
V_6 + F_8 ( V_11 ) ) ;
}
static T_1 void F_11 ( unsigned int V_14 )
{
struct V_9 * V_10 ;
struct V_15 * V_16 ;
int V_11 = V_14 >> 5 ;
V_10 = F_12 ( L_1 , 1 , V_14 , V_6 ,
V_17 ) ;
V_10 -> V_18 = & V_19 ;
V_10 -> V_20 = F_13 ( 32 ) ;
V_16 = V_10 -> V_21 ;
V_16 -> V_22 . V_23 = V_24 ;
V_16 -> V_22 . V_25 = V_26 ;
V_16 -> V_22 . V_27 = V_28 ;
V_16 -> V_22 . V_29 = F_6 ;
V_16 -> V_22 . V_30 = F_9 ;
V_16 -> V_31 . V_32 = F_14 ( V_11 ) ;
V_16 -> V_31 . V_33 = F_10 ( V_11 ) ;
F_15 ( V_10 , F_13 ( 32 ) , 0 , V_34 , 0 ) ;
}
T_2 void T_3 F_16 ( struct V_35 * V_31 )
{
T_4 V_36 ;
int V_37 , V_38 , V_39 ;
do {
V_39 = 0 ;
for ( V_37 = 0 ; V_37 < 4 ; V_37 ++ ) {
V_36 = F_3 ( V_6 + F_17 ( V_37 ) ) &
F_3 ( V_6 + F_4 ( V_37 ) ) ;
while ( V_36 ) {
V_39 = 1 ;
V_38 = F_18 ( V_36 ) - 1 ;
F_19 ( V_38 + V_37 * 32 , V_31 ) ;
V_36 &= ~ ( 1 << V_38 ) ;
}
}
} while ( V_39 );
}
void T_1 F_20 ( void T_5 * V_40 )
{
int V_37 ;
V_6 = V_40 ;
V_37 = F_3 ( V_6 + V_41 ) ;
F_5 ( 0x80010001 , V_6 + V_41 ) ;
F_5 ( 0x1f , V_6 + V_42 ) ;
F_5 ( 0x02 , V_6 + V_43 ) ;
for ( V_37 = 0 ; V_37 < 4 ; V_37 ++ )
F_5 ( 0xFFFFFFFF , V_6 + F_4 ( V_37 ) ) ;
for ( V_37 = 0 ; V_37 < 4 ; V_37 ++ )
F_5 ( 0xFFFFFFFF , V_6 + F_14 ( V_37 ) ) ;
for ( V_37 = 0 ; V_37 < V_44 ; V_37 += 32 )
F_11 ( V_37 ) ;
#ifdef F_21
F_22 () ;
#endif
F_23 ( L_2 ) ;
}
int F_24 ( void )
{
unsigned int V_37 ;
F_5 ( 1 , V_6 + V_45 ) ;
if ( F_2 ( F_3 ( V_6 + V_45 ) == 0 ) )
return - V_46 ;
for ( V_37 = 0 ; V_37 < 4 ; V_37 ++ )
F_5 ( F_3 ( V_6 + F_10 ( V_37 ) ) ,
V_6 + F_8 ( V_37 ) ) ;
return 0 ;
}
