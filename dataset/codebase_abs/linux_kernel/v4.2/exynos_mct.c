static void F_1 ( unsigned int V_1 , unsigned long V_2 )
{
unsigned long V_3 ;
T_1 V_4 ;
T_1 V_5 ;
F_2 ( V_1 , V_6 + V_2 ) ;
if ( F_3 ( V_2 >= F_4 ( 0 ) ) ) {
V_3 = ( V_2 & V_7 ) + V_8 ;
switch ( V_2 & ~ V_7 ) {
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
static T_2 F_8 ( void )
{
unsigned int V_24 , V_25 ;
T_1 V_26 = F_5 ( V_6 + V_19 ) ;
do {
V_25 = V_26 ;
V_24 = F_5 ( V_6 + V_17 ) ;
V_26 = F_5 ( V_6 + V_19 ) ;
} while ( V_25 != V_26 );
return ( ( V_27 ) V_25 << 32 ) | V_24 ;
}
static T_1 T_3 F_9 ( void )
{
return F_5 ( V_6 + V_17 ) ;
}
static V_27 F_10 ( struct V_28 * V_29 )
{
return F_9 () ;
}
static void F_11 ( struct V_28 * V_29 )
{
F_7 () ;
}
static T_2 T_3 F_12 ( void )
{
return F_9 () ;
}
static T_4 F_13 ( void )
{
F_14 ( sizeof( T_4 ) != sizeof( T_1 ) ,
L_2 ) ;
return F_9 () ;
}
static void T_5 F_15 ( void )
{
F_7 () ;
V_30 . V_31 = & F_13 ;
V_30 . V_32 = V_33 ;
F_16 ( & V_30 ) ;
if ( F_17 ( & V_34 , V_33 ) )
F_6 ( L_3 , V_34 . V_35 ) ;
F_18 ( F_12 , 32 , V_33 ) ;
}
static void F_19 ( void )
{
unsigned int V_36 ;
V_36 = F_5 ( V_6 + V_12 ) ;
V_36 &= ~ ( V_37 | V_38 ) ;
F_1 ( V_36 , V_12 ) ;
F_1 ( 0 , V_39 ) ;
}
static void F_20 ( enum V_40 V_41 ,
unsigned long V_42 )
{
unsigned int V_36 ;
V_27 V_43 ;
V_36 = F_5 ( V_6 + V_12 ) ;
if ( V_41 == V_44 ) {
V_36 |= V_38 ;
F_1 ( V_42 , V_16 ) ;
}
V_43 = F_8 () + V_42 ;
F_1 ( ( T_1 ) V_43 , V_14 ) ;
F_1 ( ( T_1 ) ( V_43 >> 32 ) , V_15 ) ;
F_1 ( 0x1 , V_39 ) ;
V_36 |= V_37 ;
F_1 ( V_36 , V_12 ) ;
}
static int F_21 ( unsigned long V_42 ,
struct V_45 * V_46 )
{
F_20 ( V_46 -> V_41 , V_42 ) ;
return 0 ;
}
static void F_22 ( enum V_40 V_41 ,
struct V_45 * V_46 )
{
unsigned long V_47 ;
F_19 () ;
switch ( V_41 ) {
case V_44 :
V_47 =
( ( ( unsigned long long ) V_48 / V_21 * V_46 -> V_49 ) >> V_46 -> V_50 ) ;
F_20 ( V_41 , V_47 ) ;
break;
case V_51 :
case V_52 :
case V_53 :
case V_54 :
break;
}
}
static T_6 F_23 ( int V_55 , void * V_56 )
{
struct V_45 * V_46 = V_56 ;
F_1 ( 0x1 , V_57 ) ;
V_46 -> V_58 ( V_46 ) ;
return V_59 ;
}
static void F_24 ( void )
{
V_60 . V_61 = F_25 ( 0 ) ;
F_26 ( & V_60 , V_33 ,
0xf , 0xffffffff ) ;
F_27 ( V_62 [ V_63 ] , & V_64 ) ;
}
static void F_28 ( struct V_65 * V_66 )
{
unsigned long V_67 ;
unsigned long V_4 = V_68 | V_69 ;
unsigned long V_2 = V_66 -> V_70 + V_9 ;
V_67 = F_5 ( V_6 + V_2 ) ;
if ( V_67 & V_4 ) {
V_67 &= ~ V_4 ;
F_1 ( V_67 , V_2 ) ;
}
}
static void F_29 ( unsigned long V_42 ,
struct V_65 * V_66 )
{
unsigned long V_67 ;
F_28 ( V_66 ) ;
V_67 = ( 1 << 31 ) | V_42 ;
F_1 ( V_67 , V_66 -> V_70 + V_10 ) ;
F_1 ( 0x1 , V_66 -> V_70 + V_71 ) ;
V_67 = F_5 ( V_6 + V_66 -> V_70 + V_9 ) ;
V_67 |= V_68 | V_69 |
V_72 ;
F_1 ( V_67 , V_66 -> V_70 + V_9 ) ;
}
static int F_30 ( unsigned long V_42 ,
struct V_45 * V_46 )
{
struct V_65 * V_66 = F_31 ( & V_73 ) ;
F_29 ( V_42 , V_66 ) ;
return 0 ;
}
static inline void F_32 ( enum V_40 V_41 ,
struct V_45 * V_46 )
{
struct V_65 * V_66 = F_31 ( & V_73 ) ;
unsigned long V_47 ;
F_28 ( V_66 ) ;
switch ( V_41 ) {
case V_44 :
V_47 =
( ( ( unsigned long long ) V_48 / V_21 * V_46 -> V_49 ) >> V_46 -> V_50 ) ;
F_29 ( V_47 , V_66 ) ;
break;
case V_51 :
case V_52 :
case V_53 :
case V_54 :
break;
}
}
static void F_33 ( struct V_65 * V_66 )
{
struct V_45 * V_46 = & V_66 -> V_46 ;
if ( V_46 -> V_41 != V_44 )
F_28 ( V_66 ) ;
if ( F_5 ( V_6 + V_66 -> V_70 + V_74 ) & 1 )
F_1 ( 0x1 , V_66 -> V_70 + V_74 ) ;
}
static T_6 F_34 ( int V_55 , void * V_56 )
{
struct V_65 * V_66 = V_56 ;
struct V_45 * V_46 = & V_66 -> V_46 ;
F_33 ( V_66 ) ;
V_46 -> V_58 ( V_46 ) ;
return V_59 ;
}
static int F_35 ( struct V_45 * V_46 )
{
struct V_65 * V_66 ;
unsigned int V_75 = F_36 () ;
V_66 = F_37 ( V_46 , struct V_65 , V_46 ) ;
V_66 -> V_70 = F_4 ( V_75 ) ;
snprintf ( V_66 -> V_35 , sizeof( V_66 -> V_35 ) , L_4 , V_75 ) ;
V_46 -> V_35 = V_66 -> V_35 ;
V_46 -> V_61 = F_25 ( V_75 ) ;
V_46 -> V_76 = F_30 ;
V_46 -> V_77 = F_32 ;
V_46 -> V_78 = V_79 | V_80 ;
V_46 -> V_81 = 450 ;
F_1 ( V_82 , V_66 -> V_70 + V_11 ) ;
if ( V_83 == V_84 ) {
if ( V_46 -> V_55 == - 1 )
return - V_85 ;
F_38 ( V_46 -> V_55 , F_25 ( V_75 ) ) ;
F_39 ( V_46 -> V_55 ) ;
} else {
F_40 ( V_62 [ V_86 ] , 0 ) ;
}
F_26 ( V_46 , V_33 / ( V_82 + 1 ) ,
0xf , 0x7fffffff ) ;
return 0 ;
}
static void F_41 ( struct V_45 * V_46 )
{
V_46 -> V_77 ( V_52 , V_46 ) ;
if ( V_83 == V_84 ) {
if ( V_46 -> V_55 != - 1 )
F_42 ( V_46 -> V_55 ) ;
} else {
F_43 ( V_62 [ V_86 ] ) ;
}
}
static int F_44 ( struct V_87 * V_88 ,
unsigned long V_89 , void * V_90 )
{
struct V_65 * V_66 ;
switch ( V_89 & ~ V_91 ) {
case V_92 :
V_66 = F_31 ( & V_73 ) ;
F_35 ( & V_66 -> V_46 ) ;
break;
case V_93 :
V_66 = F_31 ( & V_73 ) ;
F_41 ( & V_66 -> V_46 ) ;
break;
}
return V_94 ;
}
static void T_5 F_45 ( struct V_95 * V_96 , void T_7 * V_70 )
{
int V_97 , V_75 ;
struct V_65 * V_66 = F_31 ( & V_73 ) ;
struct V_98 * V_99 , * V_100 ;
V_100 = V_96 ? F_46 ( V_96 , L_5 ) :
F_47 ( NULL , L_5 ) ;
if ( F_48 ( V_100 ) )
F_6 ( L_6 , V_101 ) ;
V_33 = F_49 ( V_100 ) ;
V_99 = V_96 ? F_46 ( V_96 , L_7 ) : F_47 ( NULL , L_7 ) ;
if ( F_48 ( V_99 ) )
F_6 ( L_8 , V_101 ) ;
F_50 ( V_99 ) ;
V_6 = V_70 ;
if ( ! V_6 )
F_6 ( L_9 , V_101 ) ;
if ( V_83 == V_102 ) {
V_97 = F_51 ( V_62 [ V_86 ] ,
F_34 , L_10 ,
& V_73 ) ;
F_52 ( V_97 , L_11 ,
V_62 [ V_86 ] , V_97 ) ;
} else {
F_53 (cpu) {
int V_103 = V_62 [ V_86 + V_75 ] ;
struct V_65 * V_104 =
F_54 ( & V_73 , V_75 ) ;
V_104 -> V_46 . V_55 = - 1 ;
F_55 ( V_103 , V_105 ) ;
if ( F_56 ( V_103 ,
F_34 ,
V_106 | V_107 ,
V_104 -> V_35 , V_104 ) ) {
F_57 ( L_12 ,
V_75 ) ;
continue;
}
V_104 -> V_46 . V_55 = V_103 ;
}
}
V_97 = F_58 ( & V_108 ) ;
if ( V_97 )
goto V_109;
F_35 ( & V_66 -> V_46 ) ;
return;
V_109:
F_59 ( V_62 [ V_86 ] , & V_73 ) ;
}
static void T_5 F_60 ( struct V_95 * V_96 , unsigned int V_110 )
{
T_1 V_111 , V_5 ;
V_83 = V_110 ;
V_62 [ V_63 ] = F_61 ( V_96 , V_63 ) ;
#ifdef F_62
V_111 = F_63 ( V_96 ) ;
#else
V_111 = 0 ;
#endif
for ( V_5 = V_86 ; V_5 < V_111 ; V_5 ++ )
V_62 [ V_5 ] = F_61 ( V_96 , V_5 ) ;
F_45 ( V_96 , F_64 ( V_96 , 0 ) ) ;
F_15 () ;
F_24 () ;
}
static void T_5 F_65 ( struct V_95 * V_96 )
{
return F_60 ( V_96 , V_84 ) ;
}
static void T_5 F_66 ( struct V_95 * V_96 )
{
return F_60 ( V_96 , V_102 ) ;
}
