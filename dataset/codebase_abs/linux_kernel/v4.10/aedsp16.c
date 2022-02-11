static int T_1 F_1 ( int V_1 )
{
int V_2 = V_3 ;
unsigned char V_4 = 0 ;
F_2 ( ( L_1 , V_1 ) ) ;
do {
V_4 = F_3 ( V_1 + V_5 ) ;
} while ( ! ( V_4 & 0x80 ) && V_2 -- );
if ( V_4 & 0x80 ) {
F_2 ( ( L_2 ) ) ;
return TRUE ;
}
F_2 ( ( L_3 ) ) ;
return FALSE ;
}
static int T_1 F_4 ( int V_1 )
{
int V_6 ;
F_5 ( ( L_4 , V_1 ) ) ;
if ( F_1 ( V_1 ) == FALSE ) {
F_5 ( ( L_3 ) ) ;
return - 1 ;
}
V_6 = F_3 ( V_1 + V_7 ) ;
F_5 ( ( L_5 , V_6 , V_6 ) ) ;
return V_6 ;
}
static int T_1 F_6 ( int V_1 )
{
return ( ( F_4 ( V_1 ) == 0xaa ) ? TRUE : FALSE ) ;
}
static int T_1 F_7 ( int V_1 )
{
F_5 ( ( L_6 ) ) ;
F_8 ( 1 , ( V_1 + V_8 ) ) ;
F_9 ( 10 ) ;
F_8 ( 0 , ( V_1 + V_8 ) ) ;
F_9 ( 10 ) ;
F_9 ( 10 ) ;
if ( F_6 ( V_1 ) == TRUE ) {
F_5 ( ( L_2 ) ) ;
return TRUE ;
} else
F_5 ( ( L_3 ) ) ;
return FALSE ;
}
static int T_1 F_10 ( int V_1 , int V_9 )
{
unsigned char V_4 ;
int V_2 = V_10 ;
F_5 ( ( L_7 , V_1 , V_9 ) ) ;
do {
V_4 = F_3 ( V_1 + V_11 ) ;
if ( ! ( V_4 & 0x80 ) ) {
F_8 ( V_9 , V_1 + V_12 ) ;
F_5 ( ( L_2 ) ) ;
return 0 ;
}
} while ( V_2 -- );
F_5 ( ( L_8 ) ) ;
F_11 ( L_9 , V_9 ) ;
return - 1 ;
}
void T_1 F_12 ( void ) {
F_5 ( ( L_10 , V_13 . V_14 ) ) ;
F_5 ( ( L_11 , V_13 . V_15 ? L_12 : L_13 ) ) ;
F_5 ( ( L_14 , V_13 . V_16 ) ) ;
F_5 ( ( L_15 , V_13 . V_17 ) ) ;
F_5 ( ( L_16 , ( V_13 . V_18 != 4 ) ? L_12 : L_13 ) ) ;
F_5 ( ( L_17 , V_13 . V_19 ) ) ;
}
static void T_1 F_13 ( void ) {
F_5 ( ( L_18 , V_20 [ 0 ] , V_20 [ 1 ] ) ) ;
V_13 . V_14 = F_14 ( V_20 [ 0 ] ) ;
V_13 . V_15 = F_15 ( V_20 [ 0 ] ) ;
V_13 . V_16 = F_16 ( V_20 [ 0 ] ) ;
V_13 . V_17 = F_17 ( V_20 [ 0 ] ) ;
V_13 . V_18 = F_18 ( V_20 [ 1 ] ) ;
V_13 . V_19 = F_19 ( V_20 [ 1 ] ) ;
#if F_20 ( V_21 ) || F_20 ( V_22 )
F_11 ( L_19 ) ;
F_12 () ;
#endif
V_13 . V_14 = V_23 . V_24 ;
V_13 . V_16 = V_23 . V_25 ;
V_13 . V_17 = V_23 . V_26 ;
#if F_20 ( V_27 )
V_13 . V_15 = V_27 ;
#endif
#if F_20 ( V_28 )
V_13 . V_18 = V_28 ;
#endif
#if F_20 ( V_29 )
V_13 . V_19 = V_29 ;
#endif
#if F_20 ( V_22 )
F_5 ( ( L_20 ) ) ;
F_12 () ;
#endif
F_5 ( ( L_2 ) ) ;
}
static void T_1 F_21 ( void ) {
F_5 ( ( L_21 , V_20 [ 0 ] , V_20 [ 1 ] ) ) ;
V_20 [ 0 ] = 0 ;
V_20 [ 1 ] = 0 ;
V_20 [ 0 ] |= 0x20 ;
F_22 ( V_20 [ 0 ] , V_13 . V_14 ) ;
F_23 ( V_20 [ 0 ] , V_13 . V_16 ) ;
F_24 ( V_20 [ 0 ] , V_13 . V_17 ) ;
F_25 ( V_20 [ 0 ] , V_13 . V_15 ) ;
F_26 ( V_20 [ 1 ] , V_13 . V_18 ) ;
F_27 ( V_20 [ 1 ] , V_13 . V_19 ) ;
#if F_20 ( V_22 )
F_12 () ;
#endif
F_5 ( ( L_21 , V_20 [ 0 ] , V_20 [ 1 ] ) ) ;
F_5 ( ( L_2 ) ) ;
}
static int T_1 F_28 ( int V_1 ) {
F_5 ( ( L_22 ) ) ;
if ( F_10 ( V_1 , V_30 ) ) {
F_11 ( L_23 , V_30 ) ;
F_5 ( ( L_3 ) ) ;
return FALSE ;
}
if ( F_10 ( V_1 , V_31 ) ) {
F_11 ( L_23 , V_31 ) ;
F_5 ( ( L_3 ) ) ;
return FALSE ;
}
if ( F_10 ( V_1 , V_20 [ 0 ] ) ) {
F_11 ( L_24 , V_20 [ 0 ] ) ;
F_5 ( ( L_3 ) ) ;
return FALSE ;
}
if ( F_10 ( V_1 , V_20 [ 1 ] ) ) {
F_11 ( L_24 , V_20 [ 1 ] ) ;
F_5 ( ( L_3 ) ) ;
return FALSE ;
}
if ( F_10 ( V_1 , V_32 ) ) {
F_11 ( L_23 , V_32 ) ;
F_5 ( ( L_3 ) ) ;
return FALSE ;
}
F_5 ( ( L_2 ) ) ;
return TRUE ;
}
static int T_1 F_29 ( int V_1 ) {
F_5 ( ( L_25 ) ) ;
if ( F_10 ( V_1 , V_33 ) ) {
F_11 ( L_23 , V_33 ) ;
F_5 ( ( L_3 ) ) ;
return FALSE ;
}
if ( ( V_20 [ 0 ] = F_4 ( V_1 ) ) == - 1 ) {
F_11 ( L_26 ,
V_33 ) ;
F_5 ( ( L_3 ) ) ;
return FALSE ;
}
if ( ( V_20 [ 1 ] = F_4 ( V_1 ) ) == - 1 ) {
F_11 ( L_26 ,
V_33 ) ;
F_5 ( ( L_3 ) ) ;
return FALSE ;
}
if ( F_4 ( V_1 ) == - 1 ) {
F_11 ( L_26 ,
V_33 ) ;
F_5 ( ( L_3 ) ) ;
return FALSE ;
}
F_5 ( ( L_2 ) ) ;
return TRUE ;
}
static int T_1 F_30 ( int V_1 ) {
int V_34 , V_35 ;
if ( F_10 ( V_1 , V_36 ) ) {
F_11 ( L_23 , V_36 ) ;
return FALSE ;
}
V_34 = 7 ;
if ( V_13 . V_18 != 2 )
V_34 = 0x0F ;
if ( ( V_13 . V_18 == 4 ) ||
( V_13 . V_18 == 3 ) )
V_34 &= ~ 2 ;
if ( V_13 . V_19 == 0 )
V_34 &= ~ 2 ;
if ( V_13 . V_17 == 0 )
V_34 &= ~ 1 ;
if ( F_10 ( V_1 , V_34 ) ) {
F_11 ( L_27 ) ;
return FALSE ;
}
if ( F_10 ( V_1 , 0 ) ) {
F_11 ( L_27 ) ;
return FALSE ;
}
if ( V_13 . V_18 == 3 ) {
if ( F_10 ( V_1 , V_37 ) ) {
F_11 ( L_23 , V_37 ) ;
return FALSE ;
}
if ( ( V_35 = F_4 ( V_1 ) ) == - 1 ) {
F_11 ( L_26
, V_37 ) ;
return FALSE ;
}
V_35 &= 0x7F ;
if ( F_10 ( V_1 , V_38 ) ) {
F_11 ( L_23 , V_38 ) ;
return FALSE ;
}
if ( F_10 ( V_1 , V_35 ) ) {
F_11 ( L_28 ) ;
return FALSE ;
}
}
return TRUE ;
}
static int T_1 F_31 ( int V_1 ) {
if ( F_10 ( V_1 , V_39 ) ) {
F_11 ( L_23 , V_39 ) ;
return FALSE ;
}
if ( F_10 ( V_1 , V_40 ) ) {
F_11 ( L_29 ) ;
return FALSE ;
}
return TRUE ;
}
static int T_1 F_32 ( int V_1 )
{
F_5 ( ( L_30 ) ) ;
F_33 ( 10 ) ;
if ( F_10 ( V_1 , V_41 ) ) {
F_11 ( L_31 ,
V_41 ) ;
F_5 ( ( L_3 ) ) ;
return FALSE ;
}
F_33 ( 10 ) ;
if ( F_31 ( V_1 ) == FALSE )
return FALSE ;
F_8 ( V_42 , V_23 . V_25 ) ;
F_5 ( ( L_2 ) ) ;
return TRUE ;
}
static int T_1 F_34 ( int V_1 ) {
int V_2 = V_43 ;
#if F_20 ( V_44 )
int V_35 = 0 ;
if ( F_29 ( V_1 ) == FALSE ) {
F_11 ( L_32 ) ;
return FALSE ;
}
if ( F_10 ( V_1 , V_37 ) ) {
F_11 ( L_23 , V_37 ) ;
return FALSE ;
}
if ( ( V_35 = F_4 ( V_1 ) ) == - 1 ) {
F_11 ( L_26 ,
V_37 ) ;
return FALSE ;
}
#endif
do {
if ( F_10 ( V_1 , V_45 ) ) {
F_11 ( L_23 , V_45 ) ;
return FALSE ;
}
F_33 ( 10 ) ;
} while ( ( F_1 ( V_1 ) == FALSE ) && V_2 -- );
if ( F_4 ( V_1 ) == - 1 ) {
F_11 ( L_26 ,
V_45 ) ;
return FALSE ;
}
#if ! F_20 ( V_44 )
if ( F_10 ( V_1 , V_31 ) ) {
F_11 ( L_23 , V_31 ) ;
return FALSE ;
}
#endif
if ( F_31 ( V_1 ) == FALSE )
return FALSE ;
#if F_20 ( V_44 )
if ( F_10 ( V_1 , V_38 ) ) {
F_11 ( L_23 , V_38 ) ;
return FALSE ;
}
if ( F_10 ( V_1 , V_35 ) ) {
F_11 ( L_24 , V_35 ) ;
return FALSE ;
}
if ( F_10 ( V_1 , V_46 ) ) {
F_11 ( L_23 , V_46 ) ;
return FALSE ;
}
if ( F_10 ( V_1 , V_47 [ 0 ] ) ) {
F_11 ( L_24 , V_47 [ 0 ] ) ;
return FALSE ;
}
if ( F_10 ( V_1 , V_47 [ 1 ] ) ) {
F_11 ( L_24 , V_47 [ 1 ] ) ;
return FALSE ;
}
if ( F_28 ( V_1 ) == FALSE ) {
F_11 ( L_33 ) ;
return FALSE ;
}
if ( F_10 ( V_1 , V_31 ) ) {
F_11 ( L_23 , V_31 ) ;
return FALSE ;
}
#if F_20 ( V_48 )
if ( F_31 ( V_1 ) == FALSE )
return FALSE ;
#endif
#endif
return TRUE ;
}
static int T_1 F_35 ( int V_1 ) {
if ( F_10 ( V_1 , V_39 ) ) {
F_11 ( L_23 , V_39 ) ;
return FALSE ;
}
if ( F_10 ( V_1 , 0x0A ) ) {
F_11 ( L_34 ) ;
return FALSE ;
}
return TRUE ;
}
static int T_1 F_36 ( int V_1 )
{
int V_49 = 0 ;
int V_4 ;
F_5 ( ( L_35 ) ) ;
if ( F_10 ( V_23 . V_24 , V_50 ) ) {
F_11 ( L_23 , V_50 ) ;
F_5 ( ( L_36 ) ) ;
return FALSE ;
}
do {
if ( ( V_4 = F_4 ( V_1 ) ) == - 1 ) {
F_5 ( ( L_36 ) ) ;
return FALSE ;
}
V_47 [ V_49 ++ ] = V_4 ;
} while ( V_49 < V_51 );
sprintf ( V_52 , L_37 , V_47 [ 0 ] , V_47 [ 1 ] ) ;
F_5 ( ( L_2 ) ) ;
return TRUE ;
}
static int T_1 F_37 ( int V_1 )
{
int V_49 = 0 ;
int V_4 ;
F_5 ( ( L_38 ) ) ;
if ( F_10 ( V_23 . V_24 , V_53 ) ) {
F_11 ( L_23 , V_53 ) ;
F_5 ( ( L_36 ) ) ;
return FALSE ;
}
do {
if ( ( V_4 = F_4 ( V_1 ) ) == - 1 ) {
if ( V_49 )
break;
else {
F_5 ( ( L_36 ) ) ;
return FALSE ;
}
}
V_54 [ V_49 ++ ] = V_4 ;
} while ( V_49 < V_55 );
F_5 ( ( L_2 ) ) ;
return TRUE ;
}
static void T_1 F_38 ( void )
{
int V_56 = 0 ;
memset ( V_54 , 0 , V_55 + 1 ) ;
memset ( V_52 , 0 , V_57 + 1 ) ;
for ( V_56 = 0 ; V_58 [ V_56 ] . V_59 ; V_56 ++ )
if ( V_58 [ V_56 ] . V_35 == V_23 . V_60 ) {
V_40 |= V_58 [ V_56 ] . V_59 ;
V_42 |= V_58 [ V_56 ] . V_59 ;
}
for ( V_56 = 0 ; V_61 [ V_56 ] . V_59 ; V_56 ++ )
if ( V_61 [ V_56 ] . V_59 == V_23 . V_62 )
V_40 |= V_61 [ V_56 ] . V_59 ;
for ( V_56 = 0 ; V_63 [ V_56 ] . V_59 ; V_56 ++ )
if ( V_63 [ V_56 ] . V_35 == V_23 . V_64 ) {
V_40 |= V_63 [ V_56 ] . V_59 ;
V_42 |= V_63 [ V_56 ] . V_59 ;
}
}
static int T_1 F_39 ( void )
{
F_38 () ;
if ( F_7 ( V_23 . V_24 ) == FALSE ) {
F_11 ( L_39 ) ;
return FALSE ;
}
if ( F_37 ( V_23 . V_24 ) == FALSE ) {
F_11 ( L_40 ) ;
return FALSE ;
}
if ( strcmp ( L_41 , V_54 ) )
F_11 ( L_42 ) ;
if ( F_36 ( V_23 . V_24 ) == FALSE ) {
F_11 ( L_43 ) ;
return FALSE ;
}
if ( F_35 ( V_23 . V_24 ) == FALSE ) {
F_11 ( L_34 ) ;
return FALSE ;
}
#if F_20 ( V_44 )
if ( F_29 ( V_23 . V_24 ) == FALSE ) {
F_11 ( L_32 ) ;
return FALSE ;
}
F_13 () ;
F_21 () ;
if ( F_28 ( V_23 . V_24 ) == FALSE ) {
F_11 ( L_33 ) ;
return FALSE ;
}
if ( F_30 ( V_23 . V_24 ) == FALSE ) {
F_11 ( L_44 ) ;
return FALSE ;
}
#endif
if ( F_34 ( V_23 . V_24 ) == FALSE ) {
F_11 ( L_45 ) ;
return FALSE ;
}
if ( V_23 . V_25 != - 1 ) {
if ( V_23 . V_65 & V_66 ) {
if ( F_32 ( V_23 . V_24 ) == FALSE ) {
F_11 ( L_46
L_47 ) ;
return FALSE ;
}
}
}
#if ! F_20 ( V_67 ) || F_20 ( V_21 ) || F_20 ( V_22 )
F_11 ( L_48 ,
V_68 , V_54 ,
V_52 ) ;
if ( V_23 . V_26 != - 1 ) {
if ( V_23 . V_65 & V_69 ) {
F_11 ( L_49 ) ;
if ( ( V_23 . V_65 & V_66 ) ||
( V_23 . V_65 & V_70 ) )
F_11 ( L_50 ) ;
}
}
if ( V_23 . V_25 == - 1 ) {
if ( V_23 . V_65 & V_70 ) {
F_11 ( L_51 ) ;
if ( V_23 . V_65 & V_66 )
F_11 ( L_50 ) ;
}
}
if ( V_23 . V_25 != - 1 )
if ( V_23 . V_65 & V_66 )
F_11 ( L_52 ) ;
F_11 ( L_53 ) ;
#endif
F_33 ( 10 ) ;
return TRUE ;
}
static int T_1 F_40 ( void )
{
F_5 ( ( L_54 ) ) ;
if ( V_23 . V_65 & V_66 )
return FALSE ;
if ( V_23 . V_65 & V_70 )
return FALSE ;
V_23 . V_65 |= V_70 ;
F_5 ( ( L_55 ) ) ;
return TRUE ;
}
static void F_41 ( void )
{
F_5 ( ( L_56 ) ) ;
V_23 . V_65 &= ~ V_70 ;
F_5 ( ( L_55 ) ) ;
}
static int T_1 F_42 ( void )
{
F_5 ( ( L_57 ) ) ;
if ( V_23 . V_65 & V_70 )
return FALSE ;
if ( V_23 . V_65 & V_66 )
return FALSE ;
if ( ! ( V_23 . V_65 & V_69 ) ) {
if ( ! F_43 ( V_23 . V_24 , V_71 ,
L_58 ) ) {
F_11 (
L_59 ) ;
return FALSE ;
}
}
V_23 . V_65 |= V_66 ;
F_5 ( ( L_55 ) ) ;
return TRUE ;
}
static void F_44 ( void )
{
F_5 ( ( L_60 ) ) ;
if ( ( ! ( V_23 . V_65 & V_69 ) ) &&
( V_23 . V_65 & V_66 ) ) {
F_45 ( V_23 . V_24 , V_71 ) ;
F_5 ( ( L_61 ) ) ;
}
V_23 . V_65 &= ~ V_66 ;
F_5 ( ( L_55 ) ) ;
}
static int T_1 F_46 ( void )
{
F_5 ( ( L_62 ) ) ;
if ( V_23 . V_65 & V_69 )
return FALSE ;
if ( ! ( V_23 . V_65 & ( V_66 | V_70 ) ) ) {
if ( ! F_43 ( V_23 . V_24 , V_71 ,
L_58 ) ) {
F_11 (
L_59 ) ;
return FALSE ;
}
}
V_23 . V_65 |= V_69 ;
F_5 ( ( L_55 ) ) ;
return TRUE ;
}
static void F_47 ( void )
{
F_5 ( ( L_63 ) ) ;
if ( ( ! ( V_23 . V_65 & ( V_66 | V_70 ) ) ) &&
( V_23 . V_65 & V_69 ) ) {
F_45 ( V_23 . V_24 , V_71 ) ;
F_5 ( ( L_61 ) ) ;
}
V_23 . V_65 &= ~ V_69 ;
F_5 ( ( L_55 ) ) ;
}
static int T_1 F_48 ( void )
{
int V_72 = FALSE ;
F_5 ( ( L_64 ,
V_23 . V_24 , V_23 . V_60 , V_23 . V_64 , V_23 . V_62 ) ) ;
if ( V_23 . V_25 == - 1 ) {
if ( F_40 () == FALSE ) {
F_41 () ;
} else {
V_72 = TRUE ;
}
}
if ( V_23 . V_26 != - 1 ) {
if ( F_46 () == FALSE ) {
F_47 () ;
} else {
V_72 = TRUE ;
}
}
if ( V_23 . V_25 != - 1 ) {
if ( F_42 () == FALSE ) {
F_44 () ;
} else {
V_72 = TRUE ;
}
}
if ( V_72 )
V_72 = F_39 () ;
return V_72 ;
}
static void T_2 F_49 ( void )
{
if ( V_23 . V_25 != - 1 )
F_44 () ;
else
F_41 () ;
if ( V_23 . V_26 != - 1 )
F_47 () ;
}
static int T_1 F_50 ( void ) {
F_11 ( L_65 ) ;
if ( V_73 == - 1 || V_64 == - 1 || V_60 == - 1 ) {
F_11 ( V_74 L_66 ) ;
return - V_75 ;
}
V_23 . V_24 = V_73 ;
V_23 . V_60 = V_60 ;
V_23 . V_64 = V_64 ;
V_23 . V_25 = V_25 ;
V_23 . V_26 = V_26 ;
V_23 . V_62 = V_62 ;
if ( F_48 () == FALSE ) {
F_11 ( V_76 L_67 ) ;
return - V_75 ;
}
return 0 ;
}
static void T_2 F_51 ( void ) {
F_49 () ;
}
static int T_1 F_52 ( char * V_77 )
{
int V_78 [ 7 ] ;
V_77 = F_53 ( V_77 , F_54 ( V_78 ) , V_78 ) ;
V_73 = V_78 [ 1 ] ;
V_60 = V_78 [ 2 ] ;
V_64 = V_78 [ 3 ] ;
V_25 = V_78 [ 4 ] ;
V_26 = V_78 [ 5 ] ;
V_62 = V_78 [ 6 ] ;
return 1 ;
}
