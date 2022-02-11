static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_7 = F_2 ( V_6 ) ;
unsigned int V_9 = V_7 -> V_10 -> V_11 . V_12 ;
unsigned int V_13 = V_7 -> V_10 -> V_11 . V_14 ;
int V_14 ;
T_1 V_15 = ( ( ( V_3 << 11 ) & ( 0x0000F800 ) ) |
( ( V_4 << 6 ) & ( 0x000007C0 ) ) ) ;
V_15 |= V_16 | ( ( V_7 -> V_17 -> V_18 & 7 ) << 2 ) ;
do {} while ( ( ( F_3 ( V_7 -> V_19 + V_9 ) ) & V_16 ) == 1 );
F_4 ( V_15 , V_7 -> V_19 + V_9 ) ;
do {} while ( ( ( F_3 ( V_7 -> V_19 + V_9 ) ) & V_16 ) == 1 );
V_14 = ( int ) F_3 ( V_7 -> V_19 + V_13 ) ;
return V_14 ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 , int V_4 ,
T_1 V_20 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_7 = F_2 ( V_6 ) ;
unsigned int V_9 = V_7 -> V_10 -> V_11 . V_12 ;
unsigned int V_13 = V_7 -> V_10 -> V_11 . V_14 ;
T_1 V_21 =
( ( ( V_3 << 11 ) & ( 0x0000F800 ) ) | ( ( V_4 << 6 ) & ( 0x000007C0 ) ) )
| V_22 ;
V_21 |= V_16 | ( ( V_7 -> V_17 -> V_18 & 7 ) << 2 ) ;
do {} while ( ( ( F_3 ( V_7 -> V_19 + V_9 ) ) & V_16 ) == 1 );
F_4 ( V_20 , V_7 -> V_19 + V_13 ) ;
F_4 ( V_21 , V_7 -> V_19 + V_9 ) ;
do {} while ( ( ( F_3 ( V_7 -> V_19 + V_9 ) ) & V_16 ) == 1 );
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_7 = F_2 ( V_6 ) ;
unsigned int V_9 = V_7 -> V_10 -> V_11 . V_12 ;
if ( V_7 -> V_23 ) {
F_7 ( L_1 ) ;
V_7 -> V_23 ( V_7 -> V_17 -> V_24 ) ;
}
F_4 ( 0 , V_7 -> V_19 + V_9 ) ;
return 0 ;
}
int F_8 ( struct V_5 * V_6 )
{
int V_25 = 0 ;
struct V_1 * V_26 ;
int * V_27 ;
struct V_8 * V_7 = F_2 ( V_6 ) ;
int V_12 , V_28 ;
V_26 = F_9 () ;
if ( V_26 == NULL )
return - V_29 ;
V_27 = F_10 ( sizeof( int ) * V_30 , V_31 ) ;
if ( V_27 == NULL ) {
V_25 = - V_29 ;
goto V_32;
}
if ( V_7 -> V_33 != - 1 )
V_27 [ V_7 -> V_33 ] = V_7 -> V_34 ;
V_26 -> V_35 = L_2 ;
V_26 -> V_36 = & F_1 ;
V_26 -> V_37 = & F_5 ;
V_26 -> V_38 = & F_6 ;
snprintf ( V_26 -> V_39 , V_40 , L_3 , V_7 -> V_17 -> V_41 ) ;
V_26 -> V_7 = V_6 ;
V_26 -> V_42 = V_27 ;
V_26 -> V_43 = V_7 -> V_43 ;
V_26 -> V_44 = V_7 -> V_45 ;
V_25 = F_11 ( V_26 ) ;
if ( V_25 != 0 ) {
F_12 ( L_4 , V_26 -> V_35 ) ;
goto V_46;
}
V_7 -> V_11 = V_26 ;
V_28 = 0 ;
for ( V_12 = 0 ; V_12 < 32 ; V_12 ++ ) {
struct V_47 * V_48 = V_26 -> V_49 [ V_12 ] ;
if ( V_48 ) {
if ( V_7 -> V_33 == - 1 ) {
V_7 -> V_33 = V_12 ;
V_48 -> V_42 = V_7 -> V_34 ;
V_27 [ V_12 ] = V_7 -> V_34 ;
}
F_13 ( L_5 ,
V_6 -> V_35 , V_48 -> V_50 , V_12 ,
V_48 -> V_42 , F_14 ( & V_48 -> V_51 ) ,
( V_12 == V_7 -> V_33 ) ? L_6 : L_7 ) ;
V_28 = 1 ;
}
}
if ( ! V_28 )
F_15 ( L_8 , V_6 -> V_35 ) ;
return 0 ;
V_46:
F_16 ( V_27 ) ;
V_32:
F_16 ( V_26 ) ;
return V_25 ;
}
int F_17 ( struct V_5 * V_6 )
{
struct V_8 * V_7 = F_2 ( V_6 ) ;
F_18 ( V_7 -> V_11 ) ;
V_7 -> V_11 -> V_7 = NULL ;
F_16 ( V_7 -> V_11 ) ;
return 0 ;
}
