static void F_1 ( unsigned int V_1 , void * V_2 )
{
void T_1 * V_3 ;
T_2 V_4 ;
T_2 V_5 ;
F_2 ( V_1 , V_2 ) ;
if ( F_3 ( V_2 >= F_4 ( 0 ) ) ) {
T_2 V_6 = ( T_2 ) V_2 & V_7 ;
switch ( ( T_2 ) V_2 & ~ V_7 ) {
case ( T_2 ) V_8 :
V_3 = ( void T_1 * ) V_6 + V_9 ;
V_4 = 1 << 3 ;
break;
case ( T_2 ) V_10 :
V_3 = ( void T_1 * ) V_6 + V_9 ;
V_4 = 1 << 1 ;
break;
case ( T_2 ) V_11 :
V_3 = ( void T_1 * ) V_6 + V_9 ;
V_4 = 1 << 0 ;
break;
default:
return;
}
} else {
switch ( ( T_2 ) V_2 ) {
case ( T_2 ) V_12 :
V_3 = V_13 ;
V_4 = 1 << 16 ;
break;
case ( T_2 ) V_14 :
V_3 = V_13 ;
V_4 = 1 << 0 ;
break;
case ( T_2 ) V_15 :
V_3 = V_13 ;
V_4 = 1 << 1 ;
break;
case ( T_2 ) V_16 :
V_3 = V_13 ;
V_4 = 1 << 2 ;
break;
case ( T_2 ) V_17 :
V_3 = V_18 ;
V_4 = 1 << 0 ;
break;
case ( T_2 ) V_19 :
V_3 = V_18 ;
V_4 = 1 << 1 ;
break;
default:
return;
}
}
for ( V_5 = 0 ; V_5 < V_20 / 1000 * V_21 ; V_5 ++ )
if ( F_5 ( V_3 ) & V_4 ) {
F_2 ( V_4 , V_3 ) ;
return;
}
F_6 ( L_1 , V_1 , ( T_2 ) V_2 ) ;
}
static void F_7 ( T_2 V_22 , T_2 V_23 )
{
T_2 V_24 ;
F_1 ( V_23 , V_17 ) ;
F_1 ( V_22 , V_19 ) ;
V_24 = F_5 ( V_12 ) ;
V_24 |= V_25 ;
F_1 ( V_24 , V_12 ) ;
}
static T_3 F_8 ( struct V_26 * V_27 )
{
unsigned int V_23 , V_22 ;
T_2 V_28 = F_5 ( V_19 ) ;
do {
V_22 = V_28 ;
V_23 = F_5 ( V_17 ) ;
V_28 = F_5 ( V_19 ) ;
} while ( V_22 != V_28 );
return ( ( T_3 ) V_22 << 32 ) | V_23 ;
}
static void F_9 ( struct V_26 * V_27 )
{
F_7 ( 0 , 0 ) ;
}
static void T_4 F_10 ( void )
{
F_7 ( 0 , 0 ) ;
if ( F_11 ( & V_29 , V_30 ) )
F_6 ( L_2 , V_29 . V_31 ) ;
}
static void F_12 ( void )
{
unsigned int V_32 ;
V_32 = F_5 ( V_12 ) ;
V_32 &= ~ ( V_33 | V_34 ) ;
F_1 ( V_32 , V_12 ) ;
F_1 ( 0 , V_35 ) ;
}
static void F_13 ( enum V_36 V_37 ,
unsigned long V_38 )
{
unsigned int V_32 ;
T_3 V_39 ;
V_32 = F_5 ( V_12 ) ;
if ( V_37 == V_40 ) {
V_32 |= V_34 ;
F_1 ( V_38 , V_16 ) ;
}
V_39 = F_8 ( & V_29 ) + V_38 ;
F_1 ( ( T_2 ) V_39 , V_14 ) ;
F_1 ( ( T_2 ) ( V_39 >> 32 ) , V_15 ) ;
F_1 ( 0x1 , V_35 ) ;
V_32 |= V_33 ;
F_1 ( V_32 , V_12 ) ;
}
static int F_14 ( unsigned long V_38 ,
struct V_41 * V_42 )
{
F_13 ( V_42 -> V_37 , V_38 ) ;
return 0 ;
}
static void F_15 ( enum V_36 V_37 ,
struct V_41 * V_42 )
{
unsigned long V_43 ;
F_12 () ;
switch ( V_37 ) {
case V_40 :
V_43 =
( ( ( unsigned long long ) V_44 / V_21 * V_42 -> V_45 ) >> V_42 -> V_46 ) ;
F_13 ( V_37 , V_43 ) ;
break;
case V_47 :
case V_48 :
case V_49 :
case V_50 :
break;
}
}
static T_5 F_16 ( int V_51 , void * V_52 )
{
struct V_41 * V_42 = V_52 ;
F_1 ( 0x1 , V_53 ) ;
V_42 -> V_54 ( V_42 ) ;
return V_55 ;
}
static void F_17 ( void )
{
V_56 . V_57 = F_18 ( 0 ) ;
F_19 ( & V_56 , V_30 ,
0xf , 0xffffffff ) ;
if ( F_20 () )
F_21 ( V_58 , & V_59 ) ;
else
F_21 ( V_60 , & V_59 ) ;
}
static void F_22 ( struct V_61 * V_62 )
{
unsigned long V_63 ;
unsigned long V_4 = V_64 | V_65 ;
void T_1 * V_2 = V_62 -> V_6 + V_8 ;
V_63 = F_5 ( V_2 ) ;
if ( V_63 & V_4 ) {
V_63 &= ~ V_4 ;
F_1 ( V_63 , V_2 ) ;
}
}
static void F_23 ( unsigned long V_38 ,
struct V_61 * V_62 )
{
unsigned long V_63 ;
F_22 ( V_62 ) ;
V_63 = ( 1 << 31 ) | V_38 ;
F_1 ( V_63 , V_62 -> V_6 + V_10 ) ;
F_1 ( 0x1 , V_62 -> V_6 + V_66 ) ;
V_63 = F_5 ( V_62 -> V_6 + V_8 ) ;
V_63 |= V_64 | V_65 |
V_67 ;
F_1 ( V_63 , V_62 -> V_6 + V_8 ) ;
}
static int F_24 ( unsigned long V_38 ,
struct V_41 * V_42 )
{
struct V_61 * V_62 = F_25 ( & V_68 ) ;
F_23 ( V_38 , V_62 ) ;
return 0 ;
}
static inline void F_26 ( enum V_36 V_37 ,
struct V_41 * V_42 )
{
struct V_61 * V_62 = F_25 ( & V_68 ) ;
unsigned long V_43 ;
F_22 ( V_62 ) ;
switch ( V_37 ) {
case V_40 :
V_43 =
( ( ( unsigned long long ) V_44 / V_21 * V_42 -> V_45 ) >> V_42 -> V_46 ) ;
F_23 ( V_43 , V_62 ) ;
break;
case V_47 :
case V_48 :
case V_49 :
case V_50 :
break;
}
}
static int F_27 ( struct V_61 * V_62 )
{
struct V_41 * V_42 = V_62 -> V_42 ;
if ( V_42 -> V_37 != V_40 )
F_22 ( V_62 ) ;
if ( F_5 ( V_62 -> V_6 + V_69 ) & 1 ) {
F_1 ( 0x1 , V_62 -> V_6 + V_69 ) ;
return 1 ;
} else {
return 0 ;
}
}
static T_5 F_28 ( int V_51 , void * V_52 )
{
struct V_61 * V_62 = V_52 ;
struct V_41 * V_42 = V_62 -> V_42 ;
F_27 ( V_62 ) ;
V_42 -> V_54 ( V_42 ) ;
return V_55 ;
}
static int T_6 F_29 ( struct V_41 * V_42 )
{
struct V_61 * V_62 ;
unsigned int V_70 = F_30 () ;
int V_71 ;
V_62 = F_25 ( & V_68 ) ;
V_62 -> V_42 = V_42 ;
V_62 -> V_6 = F_4 ( V_70 ) ;
sprintf ( V_62 -> V_31 , L_3 , V_70 ) ;
V_42 -> V_31 = V_62 -> V_31 ;
V_42 -> V_57 = F_18 ( V_70 ) ;
V_42 -> V_72 = F_24 ;
V_42 -> V_73 = F_26 ;
V_42 -> V_74 = V_75 | V_76 ;
V_42 -> V_77 = 450 ;
F_19 ( V_42 , V_30 / ( V_78 + 1 ) ,
0xf , 0x7fffffff ) ;
F_1 ( V_78 , V_62 -> V_6 + V_11 ) ;
if ( V_79 == V_80 ) {
if ( V_70 == 0 ) {
V_71 = F_31 () ? V_81 :
V_82 ;
V_83 . V_52 = V_62 ;
V_42 -> V_51 = V_71 ;
F_21 ( V_71 , & V_83 ) ;
} else {
V_71 = F_31 () ? V_84 :
V_85 ;
V_86 . V_52 = V_62 ;
V_42 -> V_51 = V_71 ;
F_21 ( V_71 , & V_86 ) ;
F_32 ( V_71 , F_18 ( 1 ) ) ;
}
} else {
F_33 ( V_87 , 0 ) ;
}
return 0 ;
}
static void F_34 ( struct V_41 * V_42 )
{
unsigned int V_70 = F_30 () ;
V_42 -> V_73 ( V_48 , V_42 ) ;
if ( V_79 == V_80 )
if ( V_70 == 0 )
F_35 ( V_42 -> V_51 , & V_83 ) ;
else
F_35 ( V_42 -> V_51 , & V_86 ) ;
else
F_36 ( V_87 ) ;
}
static void T_4 F_37 ( void )
{
struct V_88 * V_89 ;
V_89 = F_38 ( NULL , L_4 ) ;
V_30 = F_39 ( V_89 ) ;
#ifdef F_40
if ( V_79 == V_90 ) {
int V_91 ;
V_91 = F_41 ( V_87 ,
F_28 , L_5 ,
& V_68 ) ;
F_42 ( V_91 , L_6 ,
V_87 , V_91 ) ;
}
F_43 ( & V_92 ) ;
#endif
}
void T_4 F_44 ( void )
{
if ( F_45 () ) {
F_46 () ;
return;
}
if ( ( F_31 () ) || ( F_20 () ) )
V_79 = V_80 ;
else
V_79 = V_90 ;
F_37 () ;
F_10 () ;
F_17 () ;
}
