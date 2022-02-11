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
static T_1 void F_6 ( unsigned int V_7 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
int V_12 = V_7 >> 5 ;
V_9 = F_7 ( L_1 , 1 , V_7 , V_6 ,
V_13 ) ;
V_9 -> V_14 = & V_15 ;
V_9 -> V_16 = F_8 ( 32 ) ;
V_17 [ V_12 ] = & V_9 -> V_18 ;
V_11 = V_9 -> V_19 ;
V_11 -> V_20 . V_21 = V_22 ;
V_11 -> V_20 . V_23 = V_24 ;
V_11 -> V_20 . V_25 = V_26 ;
V_11 -> V_27 . V_28 = F_9 ( V_12 ) ;
V_11 -> V_27 . V_29 = F_10 ( V_12 ) ;
F_11 ( V_9 , F_8 ( 32 ) , 0 , V_30 , 0 ) ;
}
T_2 void T_3 F_12 ( struct V_31 * V_27 )
{
T_4 V_32 ;
int V_33 , V_34 , V_35 ;
do {
V_35 = 0 ;
for ( V_33 = 0 ; V_33 < 4 ; V_33 ++ ) {
V_32 = F_3 ( V_6 + F_13 ( V_33 ) ) &
F_3 ( V_6 + F_4 ( V_33 ) ) ;
while ( V_32 ) {
V_35 = 1 ;
V_34 = F_14 ( V_32 ) - 1 ;
F_15 ( V_34 + V_33 * 32 , V_27 ) ;
V_32 &= ~ ( 1 << V_34 ) ;
}
}
} while ( V_35 );
}
void T_1 F_16 ( void T_5 * V_36 )
{
int V_33 ;
V_6 = V_36 ;
V_33 = F_3 ( V_6 + V_37 ) ;
F_5 ( 0x80010001 , V_6 + V_37 ) ;
F_5 ( 0x1f , V_6 + V_38 ) ;
F_5 ( 0x02 , V_6 + V_39 ) ;
for ( V_33 = 0 ; V_33 < 4 ; V_33 ++ )
F_5 ( 0xFFFFFFFF , V_6 + F_4 ( V_33 ) ) ;
for ( V_33 = 0 ; V_33 < 4 ; V_33 ++ )
F_5 ( 0xFFFFFFFF , V_6 + F_9 ( V_33 ) ) ;
for ( V_33 = 0 ; V_33 < V_40 ; V_33 += 32 )
F_6 ( V_33 ) ;
#ifdef F_17
F_18 () ;
#endif
F_19 ( L_2 ) ;
}
int F_20 ( int V_41 )
{
unsigned int V_33 , V_42 ;
F_5 ( 1 , V_6 + V_43 ) ;
if ( F_2 ( F_3 ( V_6 + V_43 ) == 0 ) )
return - V_44 ;
for ( V_33 = 0 ; V_33 < 4 ; V_33 ++ ) {
V_42 = V_41 ? F_3 ( V_6 + F_10 ( V_33 ) ) :
* V_17 [ V_33 ] ;
F_5 ( V_42 , V_6 + F_21 ( V_33 ) ) ;
}
return 0 ;
}
