static T_1 F_1 ( struct V_1 V_2 )
{
unsigned char V_3 = V_2 . V_4 & 0xf ;
unsigned char V_5 = V_2 . V_4 >> 4 ;
unsigned char V_6 = V_2 . V_6 & 3 ;
if ( V_2 . V_7 & V_8 )
return V_9 | ( V_2 . V_10 >> 4 ) ;
else
return ( V_5 << V_11 ) | ( V_6 << 4 ) | V_3 ;
}
static void F_2 ( struct V_12 * V_13 )
{
}
static void F_3 ( struct V_12 * V_13 )
{
}
static void F_4 ( struct V_12 * V_13 )
{
struct V_14 * V_14 = F_5 ( & V_15 ) ;
F_6 ( & V_14 -> V_16 -> V_10 , V_14 -> V_17 [ -- V_14 -> V_18 ] ) ;
F_7 ( V_14 -> V_18 < 0 ) ;
}
static void F_8 ( struct V_12 * V_13 )
{
}
static void F_9 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = F_10 ( V_20 ) ;
struct V_23 T_2 * V_24 =
( void T_2 * ) F_11 ( V_20 ) ;
unsigned int V_25 = F_12 ( V_20 ) ;
unsigned int V_26 = ( V_25 & 0xffffff00 ) | V_27 ;
unsigned long V_2 , V_28 ;
int V_29 ;
for (; ; ) {
V_2 = F_13 ( & V_24 -> V_30 ) ;
if ( V_2 == 0 )
break;
V_28 = V_2 & V_31 ;
if ( V_28 )
F_6 ( & V_24 -> V_30 , V_28 ) ;
for ( V_29 = 63 ; V_29 >= 0 ; V_29 -- )
if ( V_2 & ( 0x8000000000000000UL >> V_29 ) ) {
unsigned int V_32 =
F_14 ( V_33 ,
V_26 | V_29 ) ;
if ( V_32 )
F_15 ( V_32 ) ;
}
V_28 = V_2 & ~ V_31 ;
if ( V_28 )
F_6 ( & V_24 -> V_30 , V_28 ) ;
}
V_22 -> V_34 ( & V_20 -> V_12 ) ;
}
static unsigned int F_16 ( void )
{
struct V_1 V_35 ;
struct V_14 * V_14 ;
unsigned int V_36 ;
V_14 = F_5 ( & V_15 ) ;
* ( unsigned long * ) & V_35 =
F_13 ( ( V_37 T_2 * ) & V_14 -> V_16 -> V_38 ) ;
if ( ! ( V_35 . V_7 & V_39 ) )
return 0 ;
V_36 = F_14 ( V_33 , F_1 ( V_35 ) ) ;
if ( ! V_36 )
return 0 ;
V_14 -> V_17 [ ++ V_14 -> V_18 ] = V_35 . V_10 ;
F_7 ( V_14 -> V_18 > 15 ) ;
return V_36 ;
}
void F_17 ( void )
{
F_6 ( & F_5 ( & V_15 ) -> V_16 -> V_10 , 0xff ) ;
}
T_3 F_18 ( int V_40 )
{
return F_19 ( V_15 , V_40 ) . V_41 ;
}
static inline int F_20 ( int V_42 )
{
return V_9 + 0xf - V_42 ;
}
void F_21 ( int V_40 , int V_42 )
{
F_6 ( & F_19 ( V_15 , V_40 ) . V_16 -> V_43 , ( 0xf - V_42 ) << 4 ) ;
}
static void F_22 ( int V_42 )
{
int V_36 ;
V_36 = F_23 ( V_33 , F_20 ( V_42 ) ) ;
if ( ! V_36 ) {
F_24 ( V_44
L_1 , V_45 [ V_42 ] ) ;
return;
}
if ( F_25 ( V_36 , V_42 ) )
F_26 ( V_36 ) ;
}
void F_27 ( void )
{
F_22 ( V_46 ) ;
F_22 ( V_47 ) ;
F_22 ( V_48 ) ;
F_22 ( V_49 ) ;
}
static int F_28 ( struct V_50 * V_51 , struct V_52 * V_5 ,
enum V_53 V_54 )
{
return F_29 ( V_5 ,
L_2 ) ;
}
static int F_30 ( struct V_50 * V_51 , unsigned int V_36 ,
T_1 V_55 )
{
switch ( V_55 & V_56 ) {
case V_9 :
F_31 ( V_36 , & V_57 , V_58 ) ;
break;
case V_27 :
F_31 ( V_36 , & V_59 ,
V_60 ) ;
break;
default:
F_31 ( V_36 , & V_57 , V_60 ) ;
}
return 0 ;
}
static int F_32 ( struct V_50 * V_51 , struct V_52 * V_61 ,
const T_4 * V_62 , unsigned int V_63 ,
T_1 * V_64 , unsigned int * V_65 )
{
unsigned int V_5 , V_66 , V_3 , V_6 ;
const T_4 * V_67 ;
if ( ! F_29 ( V_61 ,
L_2 ) )
return - V_68 ;
if ( V_63 != 1 )
return - V_68 ;
V_67 = F_33 ( V_61 , L_3 , NULL ) ;
if ( V_67 == NULL || * V_67 != 1 )
return - V_68 ;
V_5 = V_62 [ 0 ] >> 24 ;
V_66 = ( V_62 [ 0 ] >> 16 ) & 0xff ;
V_6 = ( V_62 [ 0 ] >> 8 ) & 0xff ;
V_3 = V_62 [ 0 ] & 0xff ;
if ( V_5 > 1 )
return - V_69 ;
* V_64 = ( V_5 << V_11 ) ;
if ( V_3 == V_70 && V_6 == 1 )
* V_64 |= V_27 | V_66 ;
else
* V_64 |= V_71 |
( V_6 << V_72 ) | V_3 ;
* V_65 = V_73 ;
return 0 ;
}
static void T_5 F_34 ( unsigned int V_74 , unsigned long V_75 ,
struct V_52 * V_5 )
{
struct V_14 * V_14 = & F_19 ( V_15 , V_74 ) ;
V_14 -> V_16 = F_35 ( V_75 , sizeof( struct V_76 ) ) ;
F_7 ( V_14 -> V_16 == NULL ) ;
V_14 -> V_41 = ( ( V_74 & 2 ) << 3 ) | ( ( V_74 & 1 ) ? 0xf : 0xe ) ;
V_14 -> V_17 [ 0 ] = 0xff ;
V_14 -> V_5 = F_36 ( V_5 ) ;
F_6 ( & V_14 -> V_16 -> V_10 , 0 ) ;
F_24 ( V_77 L_4 ,
V_74 , V_14 -> V_41 , V_5 -> V_78 ) ;
}
static int T_5 F_37 ( void )
{
struct V_52 * V_79 ;
struct V_80 V_81 , V_82 ;
unsigned int V_5 , V_29 , V_83 = 0 ;
struct V_23 T_2 * V_24 ;
const T_4 * V_84 ;
for ( V_79 = NULL ;
( V_79 = F_38 ( V_79 , L_5 ) ) != NULL ; ) {
if ( ! F_29 ( V_79 ,
L_2 ) )
continue;
V_84 = F_33 ( V_79 , L_6 , NULL ) ;
if ( V_84 == NULL ) {
F_24 ( V_85 L_7 ) ;
F_39 ( V_79 ) ;
return - V_68 ;
}
if ( F_40 ( V_79 , 0 , & V_81 ) ||
F_40 ( V_79 , 1 , & V_82 ) ) {
F_24 ( V_85 L_8 ) ;
F_39 ( V_79 ) ;
return - V_68 ;
}
V_83 ++ ;
F_34 ( V_84 [ 0 ] , V_81 . V_86 , V_79 ) ;
F_34 ( V_84 [ 1 ] , V_82 . V_86 , V_79 ) ;
V_5 = V_84 [ 0 ] >> 1 ;
V_24 = F_41 ( V_84 [ 0 ] ) ;
V_29 = V_5 << V_11 ;
V_29 |= 1 << V_72 ;
V_29 |= V_70 ;
V_29 = F_23 ( V_33 , V_29 ) ;
if ( ! V_29 )
continue;
F_42 ( V_29 , ( void V_87 * ) V_24 ) ;
F_43 ( V_29 , F_9 ) ;
F_6 ( & V_24 -> V_88 ,
( 1 << 12 ) |
( V_5 << 4 ) |
V_89 ) ;
F_6 ( & V_24 -> V_30 , 0xfffffffffffffffful ) ;
}
if ( V_83 )
return 0 ;
else
return - V_68 ;
}
void T_5 F_44 ( void )
{
V_33 = F_45 ( NULL , V_90 , & V_91 ,
NULL ) ;
F_7 ( V_33 == NULL ) ;
F_46 ( V_33 ) ;
if ( F_37 () < 0 )
F_47 ( L_9 ) ;
V_92 . V_93 = F_16 ;
F_17 () ;
}
void F_48 ( int V_40 , int V_94 , int V_95 )
{
struct V_23 T_2 * V_96 = F_41 ( V_40 ) ;
V_37 V_88 = 0 ;
int V_5 = V_40 >> 1 ;
V_88 |= F_49 ( V_95 ) |
F_50 ( V_5 ) ;
if ( V_94 == 0 )
V_88 |= F_51 ( V_97 ) ;
else
V_88 |= F_51 ( V_98 ) ;
F_6 ( & V_96 -> V_88 , V_88 ) ;
}
