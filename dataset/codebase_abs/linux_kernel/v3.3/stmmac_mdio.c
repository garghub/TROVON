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
#if F_7 ( V_23 )
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_7 = F_2 ( V_6 ) ;
unsigned int V_9 = V_7 -> V_10 -> V_11 . V_12 ;
if ( V_7 -> V_17 -> V_24 -> V_25 ) {
F_8 ( L_1 ) ;
V_7 -> V_17 -> V_24 -> V_25 ( V_7 -> V_17 -> V_26 ) ;
}
F_4 ( 0 , V_7 -> V_19 + V_9 ) ;
#endif
return 0 ;
}
int F_9 ( struct V_5 * V_6 )
{
int V_27 = 0 ;
struct V_1 * V_28 ;
int * V_29 ;
struct V_8 * V_7 = F_2 ( V_6 ) ;
struct V_30 * V_24 = V_7 -> V_17 -> V_24 ;
int V_12 , V_31 ;
if ( ! V_24 )
return 0 ;
V_28 = F_10 () ;
if ( V_28 == NULL )
return - V_32 ;
if ( V_24 -> V_33 )
V_29 = V_24 -> V_33 ;
else
V_29 = V_7 -> V_34 ;
V_28 -> V_35 = L_2 ;
V_28 -> V_36 = & F_1 ;
V_28 -> V_37 = & F_5 ;
V_28 -> V_38 = & F_6 ;
snprintf ( V_28 -> V_39 , V_40 , L_3 ,
V_28 -> V_35 , V_24 -> V_41 ) ;
V_28 -> V_7 = V_6 ;
V_28 -> V_42 = V_29 ;
V_28 -> V_43 = V_24 -> V_43 ;
V_28 -> V_44 = V_7 -> V_45 ;
V_27 = F_11 ( V_28 ) ;
if ( V_27 != 0 ) {
F_12 ( L_4 , V_28 -> V_35 ) ;
goto V_46;
}
V_7 -> V_11 = V_28 ;
V_31 = 0 ;
for ( V_12 = 0 ; V_12 < V_47 ; V_12 ++ ) {
struct V_48 * V_49 = V_28 -> V_50 [ V_12 ] ;
if ( V_49 ) {
int V_51 = 0 ;
char V_52 [ 4 ] ;
char * V_53 ;
if ( ( V_24 -> V_33 == NULL ) &&
( V_24 -> V_54 > 0 ) ) {
V_29 [ V_12 ] = V_24 -> V_54 ;
V_49 -> V_42 = V_24 -> V_54 ;
}
if ( ( V_7 -> V_17 -> V_41 == V_24 -> V_41 ) &&
( V_7 -> V_17 -> V_55 == - 1 ) )
V_7 -> V_17 -> V_55 = V_12 ;
V_51 = ( V_7 -> V_17 -> V_41 == V_24 -> V_41 ) &&
( V_7 -> V_17 -> V_55 == V_12 ) ;
switch ( V_49 -> V_42 ) {
case V_56 :
V_53 = L_5 ;
break;
case V_57 :
V_53 = L_6 ;
break;
default:
sprintf ( V_52 , L_7 , V_49 -> V_42 ) ;
V_53 = V_52 ;
break;
}
F_13 ( L_8 ,
V_6 -> V_35 , V_49 -> V_58 , V_12 ,
V_53 , F_14 ( & V_49 -> V_59 ) ,
V_51 ? L_9 : L_10 ) ;
V_31 = 1 ;
}
}
if ( ! V_31 )
F_15 ( L_11 , V_6 -> V_35 ) ;
return 0 ;
V_46:
F_16 ( V_28 ) ;
return V_27 ;
}
int F_17 ( struct V_5 * V_6 )
{
struct V_8 * V_7 = F_2 ( V_6 ) ;
F_18 ( V_7 -> V_11 ) ;
V_7 -> V_11 -> V_7 = NULL ;
F_16 ( V_7 -> V_11 ) ;
V_7 -> V_11 = NULL ;
return 0 ;
}
