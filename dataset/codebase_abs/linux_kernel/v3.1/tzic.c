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
V_9 -> V_14 = F_1 ;
V_9 -> V_15 = F_8 ( 32 ) ;
V_16 [ V_12 ] = & V_9 -> V_17 ;
V_11 = V_9 -> V_18 ;
V_11 -> V_19 . V_20 = V_21 ;
V_11 -> V_19 . V_22 = V_23 ;
V_11 -> V_19 . V_24 = V_25 ;
V_11 -> V_26 . V_27 = F_9 ( V_12 ) ;
V_11 -> V_26 . V_28 = F_10 ( V_12 ) ;
F_11 ( V_9 , F_8 ( 32 ) , 0 , V_29 , 0 ) ;
}
void T_1 F_12 ( void T_2 * V_30 )
{
int V_31 ;
V_6 = V_30 ;
V_31 = F_3 ( V_6 + V_32 ) ;
F_5 ( 0x80010001 , V_6 + V_32 ) ;
F_5 ( 0x1f , V_6 + V_33 ) ;
F_5 ( 0x02 , V_6 + V_34 ) ;
for ( V_31 = 0 ; V_31 < 4 ; V_31 ++ )
F_5 ( 0xFFFFFFFF , V_6 + F_4 ( V_31 ) ) ;
for ( V_31 = 0 ; V_31 < 4 ; V_31 ++ )
F_5 ( 0xFFFFFFFF , V_6 + F_9 ( V_31 ) ) ;
for ( V_31 = 0 ; V_31 < V_35 ; V_31 += 32 )
F_6 ( V_31 ) ;
#ifdef F_13
F_14 () ;
#endif
F_15 ( L_2 ) ;
}
int F_16 ( int V_36 )
{
unsigned int V_31 , V_37 ;
F_5 ( 1 , V_6 + V_38 ) ;
if ( F_2 ( F_3 ( V_6 + V_38 ) == 0 ) )
return - V_39 ;
for ( V_31 = 0 ; V_31 < 4 ; V_31 ++ ) {
V_37 = V_36 ? F_3 ( V_6 + F_10 ( V_31 ) ) :
* V_16 [ V_31 ] ;
F_5 ( V_37 , V_6 + F_17 ( V_31 ) ) ;
}
return 0 ;
}
