static void F_1 ( unsigned int V_1 , unsigned long V_2 )
{
unsigned long V_3 ;
T_1 V_4 ;
T_1 V_5 ;
F_2 ( V_1 , V_6 + V_2 ) ;
if ( F_3 ( V_2 >= F_4 ( 0 ) ) ) {
V_3 = ( V_2 & ~ V_7 ) + V_8 ;
switch ( V_2 & V_7 ) {
case V_9 :
V_4 = 1 << 3 ;
break;
case V_10 :
V_4 = 1 << 1 ;
break;
case V_11 :
V_4 = 1 << 0 ;
break;
default:
return;
}
} else {
switch ( V_2 ) {
case V_12 :
V_3 = V_13 ;
V_4 = 1 << 16 ;
break;
case V_14 :
V_3 = V_13 ;
V_4 = 1 << 0 ;
break;
case V_15 :
V_3 = V_13 ;
V_4 = 1 << 1 ;
break;
case V_16 :
V_3 = V_13 ;
V_4 = 1 << 2 ;
break;
case V_17 :
V_3 = V_18 ;
V_4 = 1 << 0 ;
break;
case V_19 :
V_3 = V_18 ;
V_4 = 1 << 1 ;
break;
default:
return;
}
}
for ( V_5 = 0 ; V_5 < V_20 / 1000 * V_21 ; V_5 ++ )
if ( F_5 ( V_6 + V_3 ) & V_4 ) {
F_2 ( V_4 , V_6 + V_3 ) ;
return;
}
F_6 ( L_1 , V_1 , V_2 ) ;
}
static void F_7 ( void )
{
T_1 V_22 ;
V_22 = F_5 ( V_6 + V_12 ) ;
V_22 |= V_23 ;
F_1 ( V_22 , V_12 ) ;
}
static T_2 T_3 F_8 ( void )
{
unsigned int V_24 , V_25 ;
T_1 V_26 = F_5 ( V_6 + V_19 ) ;
do {
V_25 = V_26 ;
V_24 = F_5 ( V_6 + V_17 ) ;
V_26 = F_5 ( V_6 + V_19 ) ;
} while ( V_25 != V_26 );
return ( ( T_2 ) V_25 << 32 ) | V_24 ;
}
static T_2 F_9 ( struct V_27 * V_28 )
{
return F_8 () ;
}
static void F_10 ( struct V_27 * V_28 )
{
F_7 () ;
}
static T_4 T_3 F_11 ( void )
{
return F_8 () ;
}
static T_5 F_12 ( void )
{
return F_8 () ;
}
static void T_6 F_13 ( void )
{
F_7 () ;
V_29 . V_30 = & F_12 ;
V_29 . V_31 = V_32 ;
F_14 ( & V_29 ) ;
if ( F_15 ( & V_33 , V_32 ) )
F_6 ( L_2 , V_33 . V_34 ) ;
F_16 ( F_11 , 64 , V_32 ) ;
}
static void F_17 ( void )
{
unsigned int V_35 ;
V_35 = F_5 ( V_6 + V_12 ) ;
V_35 &= ~ ( V_36 | V_37 ) ;
F_1 ( V_35 , V_12 ) ;
F_1 ( 0 , V_38 ) ;
}
static void F_18 ( enum V_39 V_40 ,
unsigned long V_41 )
{
unsigned int V_35 ;
T_2 V_42 ;
V_35 = F_5 ( V_6 + V_12 ) ;
if ( V_40 == V_43 ) {
V_35 |= V_37 ;
F_1 ( V_41 , V_16 ) ;
}
V_42 = F_9 ( & V_33 ) + V_41 ;
F_1 ( ( T_1 ) V_42 , V_14 ) ;
F_1 ( ( T_1 ) ( V_42 >> 32 ) , V_15 ) ;
F_1 ( 0x1 , V_38 ) ;
V_35 |= V_36 ;
F_1 ( V_35 , V_12 ) ;
}
static int F_19 ( unsigned long V_41 ,
struct V_44 * V_45 )
{
F_18 ( V_45 -> V_40 , V_41 ) ;
return 0 ;
}
static void F_20 ( enum V_39 V_40 ,
struct V_44 * V_45 )
{
unsigned long V_46 ;
F_17 () ;
switch ( V_40 ) {
case V_43 :
V_46 =
( ( ( unsigned long long ) V_47 / V_21 * V_45 -> V_48 ) >> V_45 -> V_49 ) ;
F_18 ( V_40 , V_46 ) ;
break;
case V_50 :
case V_51 :
case V_52 :
case V_53 :
break;
}
}
static T_7 F_21 ( int V_54 , void * V_55 )
{
struct V_44 * V_45 = V_55 ;
F_1 ( 0x1 , V_56 ) ;
V_45 -> V_57 ( V_45 ) ;
return V_58 ;
}
static void F_22 ( void )
{
V_59 . V_60 = F_23 ( 0 ) ;
F_24 ( & V_59 , V_32 ,
0xf , 0xffffffff ) ;
F_25 ( V_61 [ V_62 ] , & V_63 ) ;
}
static void F_26 ( struct V_64 * V_65 )
{
unsigned long V_66 ;
unsigned long V_4 = V_67 | V_68 ;
unsigned long V_2 = V_65 -> V_69 + V_9 ;
V_66 = F_5 ( V_6 + V_2 ) ;
if ( V_66 & V_4 ) {
V_66 &= ~ V_4 ;
F_1 ( V_66 , V_2 ) ;
}
}
static void F_27 ( unsigned long V_41 ,
struct V_64 * V_65 )
{
unsigned long V_66 ;
F_26 ( V_65 ) ;
V_66 = ( 1 << 31 ) | V_41 ;
F_1 ( V_66 , V_65 -> V_69 + V_10 ) ;
F_1 ( 0x1 , V_65 -> V_69 + V_70 ) ;
V_66 = F_5 ( V_6 + V_65 -> V_69 + V_9 ) ;
V_66 |= V_67 | V_68 |
V_71 ;
F_1 ( V_66 , V_65 -> V_69 + V_9 ) ;
}
static int F_28 ( unsigned long V_41 ,
struct V_44 * V_45 )
{
struct V_64 * V_65 = F_29 ( & V_72 ) ;
F_27 ( V_41 , V_65 ) ;
return 0 ;
}
static inline void F_30 ( enum V_39 V_40 ,
struct V_44 * V_45 )
{
struct V_64 * V_65 = F_29 ( & V_72 ) ;
unsigned long V_46 ;
F_26 ( V_65 ) ;
switch ( V_40 ) {
case V_43 :
V_46 =
( ( ( unsigned long long ) V_47 / V_21 * V_45 -> V_48 ) >> V_45 -> V_49 ) ;
F_27 ( V_46 , V_65 ) ;
break;
case V_50 :
case V_51 :
case V_52 :
case V_53 :
break;
}
}
static int F_31 ( struct V_64 * V_65 )
{
struct V_44 * V_45 = & V_65 -> V_45 ;
if ( V_45 -> V_40 != V_43 )
F_26 ( V_65 ) ;
if ( F_5 ( V_6 + V_65 -> V_69 + V_73 ) & 1 ) {
F_1 ( 0x1 , V_65 -> V_69 + V_73 ) ;
return 1 ;
} else {
return 0 ;
}
}
static T_7 F_32 ( int V_54 , void * V_55 )
{
struct V_64 * V_65 = V_55 ;
struct V_44 * V_45 = & V_65 -> V_45 ;
F_31 ( V_65 ) ;
V_45 -> V_57 ( V_45 ) ;
return V_58 ;
}
static int F_33 ( struct V_44 * V_45 )
{
struct V_64 * V_65 ;
unsigned int V_74 = F_34 () ;
V_65 = F_35 ( V_45 , struct V_64 , V_45 ) ;
V_65 -> V_69 = F_4 ( V_74 ) ;
snprintf ( V_65 -> V_34 , sizeof( V_65 -> V_34 ) , L_3 , V_74 ) ;
V_45 -> V_34 = V_65 -> V_34 ;
V_45 -> V_60 = F_23 ( V_74 ) ;
V_45 -> V_75 = F_28 ;
V_45 -> V_76 = F_30 ;
V_45 -> V_77 = V_78 | V_79 ;
V_45 -> V_80 = 450 ;
F_1 ( V_81 , V_65 -> V_69 + V_11 ) ;
if ( V_82 == V_83 ) {
V_45 -> V_54 = V_61 [ V_84 + V_74 ] ;
if ( F_36 ( V_45 -> V_54 , F_32 ,
V_85 | V_86 ,
V_45 -> V_34 , V_65 ) ) {
F_37 ( L_4 ,
V_45 -> V_54 ) ;
return - V_87 ;
}
F_38 ( V_61 [ V_84 + V_74 ] , F_23 ( V_74 ) ) ;
} else {
F_39 ( V_61 [ V_84 ] , 0 ) ;
}
F_24 ( V_45 , V_32 / ( V_81 + 1 ) ,
0xf , 0x7fffffff ) ;
return 0 ;
}
static void F_40 ( struct V_44 * V_45 )
{
V_45 -> V_76 ( V_51 , V_45 ) ;
if ( V_82 == V_83 )
F_41 ( V_45 -> V_54 , F_29 ( & V_72 ) ) ;
else
F_42 ( V_61 [ V_84 ] ) ;
}
static int F_43 ( struct V_88 * V_89 ,
unsigned long V_90 , void * V_91 )
{
struct V_64 * V_65 ;
switch ( V_90 & ~ V_92 ) {
case V_93 :
V_65 = F_29 ( & V_72 ) ;
F_33 ( & V_65 -> V_45 ) ;
break;
case V_94 :
V_65 = F_29 ( & V_72 ) ;
F_40 ( & V_65 -> V_45 ) ;
break;
}
return V_95 ;
}
static void T_6 F_44 ( struct V_96 * V_97 , void T_8 * V_69 )
{
int V_98 ;
struct V_64 * V_65 = F_29 ( & V_72 ) ;
struct V_99 * V_100 , * V_101 ;
V_101 = V_97 ? F_45 ( V_97 , L_5 ) :
F_46 ( NULL , L_5 ) ;
if ( F_47 ( V_101 ) )
F_6 ( L_6 , V_102 ) ;
V_32 = F_48 ( V_101 ) ;
V_100 = V_97 ? F_45 ( V_97 , L_7 ) : F_46 ( NULL , L_7 ) ;
if ( F_47 ( V_100 ) )
F_6 ( L_8 , V_102 ) ;
F_49 ( V_100 ) ;
V_6 = V_69 ;
if ( ! V_6 )
F_6 ( L_9 , V_102 ) ;
if ( V_82 == V_103 ) {
V_98 = F_50 ( V_61 [ V_84 ] ,
F_32 , L_10 ,
& V_72 ) ;
F_51 ( V_98 , L_11 ,
V_61 [ V_84 ] , V_98 ) ;
} else {
F_52 ( V_61 [ V_84 ] , F_23 ( 0 ) ) ;
}
V_98 = F_53 ( & V_104 ) ;
if ( V_98 )
goto V_105;
F_33 ( & V_65 -> V_45 ) ;
return;
V_105:
F_54 ( V_61 [ V_84 ] , & V_72 ) ;
}
void T_6 F_55 ( void T_8 * V_69 , int V_106 , int V_107 , int V_108 )
{
V_61 [ V_62 ] = V_106 ;
V_61 [ V_84 ] = V_107 ;
V_61 [ V_109 ] = V_108 ;
V_82 = V_83 ;
F_44 ( NULL , V_69 ) ;
F_13 () ;
F_22 () ;
}
static void T_6 F_56 ( struct V_96 * V_97 , unsigned int V_110 )
{
T_1 V_111 , V_5 ;
V_82 = V_110 ;
V_61 [ V_62 ] = F_57 ( V_97 , V_62 ) ;
#ifdef F_58
V_111 = F_59 ( V_97 ) ;
#else
V_111 = 0 ;
#endif
for ( V_5 = V_84 ; V_5 < V_111 ; V_5 ++ )
V_61 [ V_5 ] = F_57 ( V_97 , V_5 ) ;
F_44 ( V_97 , F_60 ( V_97 , 0 ) ) ;
F_13 () ;
F_22 () ;
}
static void T_6 F_61 ( struct V_96 * V_97 )
{
return F_56 ( V_97 , V_83 ) ;
}
static void T_6 F_62 ( struct V_96 * V_97 )
{
return F_56 ( V_97 , V_103 ) ;
}
