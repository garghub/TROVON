void F_1 ( T_1 V_1 )
{
V_2 = V_1 ;
}
void F_2 ( unsigned int V_3 , unsigned int V_4 )
{
unsigned long V_5 ;
F_3 ( V_5 ) ;
V_6 = ( V_6 & ~ V_3 ) | ( V_4 & V_3 ) ;
F_4 ( V_5 ) ;
}
static void F_5 ( struct V_7 * V_8 )
{
int V_9 = ( V_8 -> V_10 - F_6 ( 0 ) ) ;
V_11 = ( V_12 &= ~ ( 1 << V_9 ) ) ;
}
static void F_7 ( struct V_7 * V_8 )
{
int V_9 = ( V_8 -> V_10 - F_6 ( 0 ) ) ;
V_13 &= ~ ( 1 << V_9 ) ;
V_11 = ( V_12 |= ( 1 << V_9 ) ) ;
}
static void F_8 ( unsigned int V_10 , struct V_14 * V_15 )
{
unsigned long V_16 = V_13 & V_12 ;
do {
V_15 -> V_7 . V_17 -> V_18 ( & V_15 -> V_7 ) ;
if ( F_9 ( V_16 ) ) {
V_10 = F_6 ( 0 ) + F_10 ( V_16 ) ;
F_11 ( V_10 ) ;
}
V_16 = V_13 & V_12 ;
} while ( V_16 );
}
static void T_2 F_12 ( void )
{
int V_10 ;
F_13 () ;
for ( V_10 = F_6 ( 0 ) ; V_10 <= V_19 ; V_10 ++ ) {
F_14 ( V_10 , & V_20 ,
V_21 ) ;
F_15 ( V_10 , V_22 | V_23 ) ;
}
F_16 ( F_17 ( 0 ) , F_8 ) ;
F_18 ( F_17 ( 0 ) , V_24 ) ;
}
static void F_19 ( void )
{
V_11 = V_12 ;
}
static int T_2 F_20 ( void )
{
if ( F_21 () ) {
F_22 ( & V_25 ) ;
return 0 ;
}
return - V_26 ;
}
static int F_23 ( void )
{
return ( V_27 & ( 1 << 9 ) ) == 0 ;
}
static int F_24 ( void )
{
return 0 ;
}
static void F_25 ( T_3 V_28 )
{
static const unsigned V_29 = 1 << 11 ;
F_2 ( V_29 , ( V_28 == V_30 ) ? 0 : V_29 ) ;
}
static void F_26 ( unsigned long V_31 )
{
unsigned long V_5 ;
F_3 ( V_5 ) ;
V_13 &= ~ ( 1 << 0 ) ;
F_4 ( V_5 ) ;
if ( V_13 & ( 1 << 0 ) )
F_27 ( & V_32 , V_33 + V_34 ) ;
else {
( void ) F_28 ( V_35 , ( void * ) V_31 ) ;
F_29 ( V_35 ) ;
}
}
static T_4 F_30 ( int V_10 , void * V_31 )
{
F_31 ( V_10 ) ;
F_27 ( & V_32 , V_33 + V_34 ) ;
return F_28 ( V_10 , V_31 ) ;
}
static int F_32 ( struct V_36 * V_37 ,
T_5 V_38 ,
void * V_31 )
{
F_28 = V_38 ;
F_33 ( & V_32 ) ;
V_32 . V_31 = ( unsigned long ) V_31 ;
return F_34 ( V_35 , F_30 ,
0 , L_1 , V_31 ) ;
}
static int F_35 ( struct V_36 * V_37 )
{
return ( V_27 & ( 1 << 2 ) ) != 0 ;
}
static void F_36 ( struct V_36 * V_37 , void * V_31 )
{
F_37 ( V_35 , V_31 ) ;
F_38 ( & V_32 ) ;
}
static void F_39 ( struct V_36 * V_37 , int V_39 )
{
unsigned long V_5 ;
F_3 ( V_5 ) ;
if ( V_39 & V_40 ) {
V_6 &= ~ ( 1 << 4 ) ;
} else if ( V_39 & V_41 ) {
V_6 |= 1 << 4 ;
}
F_40 ( V_37 , V_39 ) ;
F_4 ( V_5 ) ;
}
static void T_2 F_41 ( void )
{
int V_42 = ( V_43 & 1 ) ;
F_42 ( F_43 ( V_44 ) ) ;
F_44 ( NULL ) ;
F_45 ( NULL ) ;
F_46 ( NULL ) ;
F_47 ( L_2 , NULL , L_3 , NULL ) ;
F_48 ( & V_45 ) ;
F_49 ( NULL , & V_46 ) ;
F_50 ( & V_47 ) ;
F_51 ( & V_48 ) ;
F_52 ( NULL ) ;
V_49 [ 0 ] . V_50 = V_49 [ 1 ] . V_50 =
( F_53 ( V_51 ) & 1 ) ? 2 : 4 ;
F_54 ( V_52 L_4 ,
V_42 ? L_5 : L_6 , V_42 ) ;
V_49 [ V_42 ^ 1 ] . V_53 = L_7 ;
V_49 [ V_42 ] . V_53 = L_8 ;
( void ) F_55 ( V_54 , F_56 ( V_54 ) ) ;
F_57 ( 1 , & V_55 ) ;
F_58 ( V_56 , F_56 ( V_56 ) ) ;
}
static void T_2 F_59 ( void )
{
F_60 () ;
F_61 ( V_57 , F_56 ( V_57 ) ) ;
V_58 |= V_59 ;
}
static void F_62 ( struct V_60 * V_61 ,
enum V_62 V_63 )
{
struct V_64 * V_65 = F_63 ( V_61 ,
struct V_64 , V_61 ) ;
T_3 V_66 = V_67 ;
if ( V_63 != V_68 )
V_66 |= V_65 -> V_3 ;
else
V_66 &= ~ V_65 -> V_3 ;
V_67 = V_66 ;
}
static enum V_62 F_64 ( struct V_60 * V_61 )
{
struct V_64 * V_65 = F_63 ( V_61 ,
struct V_64 , V_61 ) ;
T_3 V_66 = V_67 ;
return ( V_66 & V_65 -> V_3 ) ? V_69 : V_68 ;
}
static int T_2 F_65 ( void )
{
int V_70 ;
if ( ! F_21 () )
return - V_26 ;
V_67 |= 0xff ;
for ( V_70 = 0 ; V_70 < F_56 ( V_71 ) ; V_70 ++ ) {
struct V_64 * V_65 ;
V_65 = F_66 ( sizeof( * V_65 ) , V_72 ) ;
if ( ! V_65 )
break;
V_65 -> V_61 . V_53 = V_71 [ V_70 ] . V_53 ;
V_65 -> V_61 . V_73 = F_62 ;
V_65 -> V_61 . V_74 = F_64 ;
V_65 -> V_61 . V_75 = V_71 [ V_70 ] . V_76 ;
V_65 -> V_3 = F_67 ( V_70 ) ;
if ( F_68 ( NULL , & V_65 -> V_61 ) < 0 ) {
F_69 ( V_65 ) ;
break;
}
}
return 0 ;
}
