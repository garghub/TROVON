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
if ( V_7 -> V_17 -> V_23 -> V_24 ) {
F_7 ( L_1 ) ;
V_7 -> V_17 -> V_23 -> V_24 ( V_7 -> V_17 -> V_25 ) ;
}
F_4 ( 0 , V_7 -> V_19 + V_9 ) ;
return 0 ;
}
int F_8 ( struct V_5 * V_6 )
{
int V_26 = 0 ;
struct V_1 * V_27 ;
int * V_28 ;
struct V_8 * V_7 = F_2 ( V_6 ) ;
struct V_29 * V_23 = V_7 -> V_17 -> V_23 ;
int V_12 , V_30 ;
if ( ! V_23 )
return 0 ;
V_27 = F_9 () ;
if ( V_27 == NULL )
return - V_31 ;
if ( V_23 -> V_32 )
V_28 = V_23 -> V_32 ;
else
V_28 = V_7 -> V_33 ;
V_27 -> V_34 = L_2 ;
V_27 -> V_35 = & F_1 ;
V_27 -> V_36 = & F_5 ;
V_27 -> V_37 = & F_6 ;
snprintf ( V_27 -> V_38 , V_39 , L_3 , V_23 -> V_40 ) ;
V_27 -> V_7 = V_6 ;
V_27 -> V_41 = V_28 ;
V_27 -> V_42 = V_23 -> V_42 ;
V_27 -> V_43 = V_7 -> V_44 ;
V_26 = F_10 ( V_27 ) ;
if ( V_26 != 0 ) {
F_11 ( L_4 , V_27 -> V_34 ) ;
goto V_45;
}
V_7 -> V_11 = V_27 ;
V_30 = 0 ;
for ( V_12 = 0 ; V_12 < V_46 ; V_12 ++ ) {
struct V_47 * V_48 = V_27 -> V_49 [ V_12 ] ;
if ( V_48 ) {
int V_50 = 0 ;
char V_51 [ 4 ] ;
char * V_52 ;
if ( ( V_23 -> V_32 == NULL ) &&
( V_23 -> V_53 > 0 ) ) {
V_28 [ V_12 ] = V_23 -> V_53 ;
V_48 -> V_41 = V_23 -> V_53 ;
}
if ( ( V_7 -> V_17 -> V_40 == V_23 -> V_40 ) &&
( V_7 -> V_17 -> V_54 == - 1 ) )
V_7 -> V_17 -> V_54 = V_12 ;
V_50 = ( V_7 -> V_17 -> V_40 == V_23 -> V_40 ) &&
( V_7 -> V_17 -> V_54 == V_12 ) ;
switch ( V_48 -> V_41 ) {
case V_55 :
V_52 = L_5 ;
break;
case V_56 :
V_52 = L_6 ;
break;
default:
sprintf ( V_51 , L_7 , V_48 -> V_41 ) ;
V_52 = V_51 ;
break;
}
F_12 ( L_8 ,
V_6 -> V_34 , V_48 -> V_57 , V_12 ,
V_52 , F_13 ( & V_48 -> V_58 ) ,
V_50 ? L_9 : L_10 ) ;
V_30 = 1 ;
}
}
if ( ! V_30 )
F_14 ( L_11 , V_6 -> V_34 ) ;
return 0 ;
V_45:
F_15 ( V_27 ) ;
return V_26 ;
}
int F_16 ( struct V_5 * V_6 )
{
struct V_8 * V_7 = F_2 ( V_6 ) ;
F_17 ( V_7 -> V_11 ) ;
V_7 -> V_11 -> V_7 = NULL ;
F_15 ( V_7 -> V_11 ) ;
V_7 -> V_11 = NULL ;
return 0 ;
}
