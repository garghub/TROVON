void F_1 ( struct V_1 * V_2 , enum V_3 type )
{
enum V_4 V_5 ;
unsigned long V_6 ;
switch ( type ) {
case V_7 :
V_5 = V_8 ;
break;
case V_9 :
V_5 = V_10 ;
break;
case V_11 :
V_5 = V_12 ;
break;
default:
F_2 ( 1 , L_1 , V_13 , type ) ;
return;
}
F_3 () ;
V_6 = F_4 ( F_5 ( V_2 ) ) | V_2 -> V_14 ;
F_6 () ;
F_7 ( V_5 , 0 , V_6 ) ;
F_8 () ;
}
void F_9 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
unsigned int V_19 , V_20 ;
T_1 V_21 ;
T_2 V_22 ;
unsigned long V_23 ;
V_20 = F_10 ( V_18 ) ;
V_19 = F_11 ( V_18 ) ;
V_22 = ( V_19 << 16 ) | V_20 ;
V_21 = F_12 ( V_18 ) ;
F_13 ( V_23 ) ;
F_14 ( V_24 , V_22 ) ;
F_14 ( V_25 , V_26 | F_5 ( & V_16 -> V_2 ) ) ;
asm volatile("tlbsx 0, %[eaddr]\n" : : [eaddr] "r" (eaddr));
V_22 = F_15 ( V_27 ) ;
if ( V_22 & V_28 ) {
F_14 ( V_27 , V_22 & ~ V_28 ) ;
asm volatile("tlbwe");
}
F_14 ( V_25 , 0 ) ;
F_14 ( V_29 , 0 ) ;
F_16 () ;
F_17 ( V_23 ) ;
}
void F_18 ( struct V_15 * V_16 )
{
unsigned long V_23 ;
F_13 ( V_23 ) ;
F_14 ( V_25 , V_26 | F_5 ( & V_16 -> V_2 ) ) ;
asm volatile("tlbilxlpid");
F_14 ( V_25 , 0 ) ;
F_17 ( V_23 ) ;
}
void F_19 ( struct V_1 * V_2 , T_2 V_30 )
{
V_2 -> V_31 . V_30 = V_30 ;
}
void F_20 ( struct V_1 * V_2 , T_2 V_32 )
{
}
static void F_21 ( struct V_1 * V_2 , int V_33 )
{
struct V_15 * V_16 = F_22 ( V_2 ) ;
F_23 ( V_2 , V_33 ) ;
F_14 ( V_34 , F_5 ( V_2 ) ) ;
F_14 ( V_35 , V_2 -> V_31 . V_36 ) ;
F_14 ( V_37 , V_2 -> V_14 ) ;
F_14 ( V_38 , V_2 -> V_31 . V_39 ) ;
V_2 -> V_31 . V_40 = V_41 | ( F_5 ( V_2 ) << V_42 ) ;
V_2 -> V_31 . V_43 = V_2 -> V_31 . V_40 ;
F_14 ( V_44 , V_2 -> V_31 . V_40 ) ;
F_14 ( V_45 , V_2 -> V_31 . V_43 ) ;
F_14 ( V_46 , V_2 -> V_31 . V_47 ) ;
F_14 ( V_48 , V_2 -> V_31 . V_49 [ V_50 ] ) ;
F_14 ( V_51 , V_2 -> V_31 . V_49 [ V_52 ] ) ;
F_14 ( V_53 , ( unsigned long ) V_2 -> V_31 . V_54 -> V_55 ) ;
F_14 ( V_56 , ( unsigned long ) V_2 -> V_31 . V_54 -> V_57 ) ;
F_14 ( V_58 , ( unsigned long ) V_2 -> V_31 . V_54 -> V_59 ) ;
F_14 ( V_60 , ( unsigned long ) V_2 -> V_31 . V_54 -> V_61 ) ;
F_14 ( V_62 , V_2 -> V_31 . V_54 -> V_63 ) ;
F_14 ( V_64 , V_2 -> V_31 . V_54 -> V_65 ) ;
F_14 ( V_66 , V_2 -> V_31 . V_67 ) ;
F_14 ( V_68 , V_2 -> V_31 . V_54 -> V_69 ) ;
F_14 ( V_70 , V_2 -> V_31 . V_54 -> V_71 ) ;
if ( V_2 -> V_31 . V_72 != F_15 ( V_73 ) ||
F_24 ( V_74 ) [ F_5 ( V_2 ) ] != V_2 ) {
F_18 ( V_16 ) ;
F_24 ( V_74 ) [ F_5 ( V_2 ) ] = V_2 ;
}
}
static void F_25 ( struct V_1 * V_2 )
{
V_2 -> V_31 . V_40 = F_15 ( V_44 ) ;
V_2 -> V_31 . V_43 = F_15 ( V_45 ) ;
V_2 -> V_31 . V_54 -> V_55 = F_15 ( V_53 ) ;
V_2 -> V_31 . V_54 -> V_57 = F_15 ( V_56 ) ;
V_2 -> V_31 . V_54 -> V_59 = F_15 ( V_58 ) ;
V_2 -> V_31 . V_54 -> V_61 = F_15 ( V_60 ) ;
V_2 -> V_31 . V_54 -> V_63 = F_15 ( V_62 ) ;
V_2 -> V_31 . V_54 -> V_65 = F_15 ( V_64 ) ;
V_2 -> V_31 . V_67 = F_15 ( V_66 ) ;
V_2 -> V_31 . V_54 -> V_69 = F_15 ( V_68 ) ;
V_2 -> V_31 . V_54 -> V_71 = F_15 ( V_70 ) ;
V_2 -> V_31 . V_72 = F_15 ( V_73 ) ;
F_26 ( V_2 ) ;
}
int F_27 ( void )
{
int V_75 ;
if ( strcmp ( V_76 -> V_77 , L_2 ) == 0 )
V_75 = 0 ;
else if ( strcmp ( V_76 -> V_77 , L_3 ) == 0 )
V_75 = 0 ;
#ifdef F_28
else if ( strcmp ( V_76 -> V_77 , L_4 ) == 0 )
V_75 = 0 ;
#endif
else
V_75 = - V_78 ;
return V_75 ;
}
int F_29 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_22 ( V_2 ) ;
V_2 -> V_31 . V_36 = V_79 | V_80 | \
V_81 ;
#ifdef F_30
V_2 -> V_31 . V_36 |= V_82 ;
#endif
V_2 -> V_31 . V_39 = V_83 | V_84 ;
V_2 -> V_31 . V_85 = F_15 ( V_86 ) ;
V_16 -> V_87 = F_15 ( V_88 ) ;
V_2 -> V_31 . V_89 = V_90 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_91 * V_92 )
{
struct V_15 * V_16 = F_22 ( V_2 ) ;
V_92 -> V_93 . V_94 . V_95 |= V_96 | V_97 |
V_98 ;
V_92 -> V_93 . V_94 . V_99 = V_100 ;
V_92 -> V_93 . V_94 . V_101 . V_102 . V_95 = 0 ;
V_92 -> V_93 . V_94 . V_101 . V_102 . V_87 = V_16 -> V_87 ;
V_92 -> V_93 . V_94 . V_101 . V_102 . V_103 = V_16 -> V_103 ;
V_92 -> V_93 . V_94 . V_101 . V_102 . V_104 = V_16 -> V_104 ;
F_32 ( V_2 , V_92 ) ;
V_92 -> V_93 . V_94 . V_105 [ 3 ] =
V_2 -> V_31 . V_49 [ V_106 ] ;
V_92 -> V_93 . V_94 . V_105 [ 4 ] = V_2 -> V_31 . V_49 [ V_107 ] ;
V_92 -> V_93 . V_94 . V_105 [ 5 ] = V_2 -> V_31 . V_49 [ V_108 ] ;
return F_33 ( V_2 , V_92 ) ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_91 * V_92 )
{
struct V_15 * V_16 = F_22 ( V_2 ) ;
int V_109 ;
if ( V_92 -> V_93 . V_94 . V_99 == V_100 ) {
V_16 -> V_87 = V_92 -> V_93 . V_94 . V_101 . V_102 . V_87 ;
V_16 -> V_103 = V_92 -> V_93 . V_94 . V_101 . V_102 . V_103 ;
V_16 -> V_104 = V_92 -> V_93 . V_94 . V_101 . V_102 . V_104 ;
}
V_109 = F_35 ( V_2 , V_92 ) ;
if ( V_109 < 0 )
return V_109 ;
if ( ! ( V_92 -> V_93 . V_94 . V_95 & V_110 ) )
return 0 ;
if ( V_92 -> V_93 . V_94 . V_95 & V_97 ) {
V_2 -> V_31 . V_49 [ V_106 ] =
V_92 -> V_93 . V_94 . V_105 [ 3 ] ;
}
if ( V_92 -> V_93 . V_94 . V_95 & V_98 ) {
V_2 -> V_31 . V_49 [ V_107 ] =
V_92 -> V_93 . V_94 . V_105 [ 4 ] ;
V_2 -> V_31 . V_49 [ V_108 ] =
V_92 -> V_93 . V_94 . V_105 [ 5 ] ;
}
return F_36 ( V_2 , V_92 ) ;
}
static int F_37 ( struct V_1 * V_2 , T_3 V_111 ,
union V_112 * V_22 )
{
int V_75 = 0 ;
switch ( V_111 ) {
case V_113 :
* V_22 = F_38 ( V_111 , V_2 -> V_31 . V_114 ) ;
break;
default:
V_75 = F_39 ( V_2 , V_111 , V_22 ) ;
}
return V_75 ;
}
static int F_40 ( struct V_1 * V_2 , T_3 V_111 ,
union V_112 * V_22 )
{
int V_75 = 0 ;
switch ( V_111 ) {
case V_113 :
V_2 -> V_31 . V_114 = F_41 ( V_111 , * V_22 ) ;
break;
default:
V_75 = F_42 ( V_2 , V_111 , V_22 ) ;
}
return V_75 ;
}
static struct V_1 * F_43 ( struct V_115 * V_115 ,
unsigned int V_111 )
{
struct V_15 * V_16 ;
struct V_1 * V_2 ;
int V_116 ;
V_16 = F_44 ( V_117 , V_118 ) ;
if ( ! V_16 ) {
V_116 = - V_119 ;
goto V_120;
}
V_2 = & V_16 -> V_2 ;
V_2 -> V_31 . V_72 = 0xffffffff ;
V_116 = F_45 ( V_2 , V_115 , V_111 ) ;
if ( V_116 )
goto V_121;
V_116 = F_46 ( V_16 ) ;
if ( V_116 )
goto V_122;
V_2 -> V_31 . V_54 = ( void * ) F_47 ( V_118 | V_123 ) ;
if ( ! V_2 -> V_31 . V_54 )
goto V_124;
return V_2 ;
V_124:
F_48 ( V_16 ) ;
V_122:
F_49 ( V_2 ) ;
V_121:
F_50 ( V_117 , V_16 ) ;
V_120:
return F_51 ( V_116 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_22 ( V_2 ) ;
F_53 ( ( unsigned long ) V_2 -> V_31 . V_54 ) ;
F_48 ( V_16 ) ;
F_49 ( V_2 ) ;
F_50 ( V_117 , V_16 ) ;
}
static int F_54 ( struct V_115 * V_115 )
{
int V_125 ;
V_125 = F_55 () ;
if ( V_125 < 0 )
return V_125 ;
if ( V_126 == 2 )
V_125 <<= 1 ;
V_115 -> V_31 . V_125 = V_125 ;
return 0 ;
}
static void F_56 ( struct V_115 * V_115 )
{
int V_125 = V_115 -> V_31 . V_125 ;
if ( V_126 == 2 )
V_125 >>= 1 ;
F_57 ( V_125 ) ;
}
static int T_4 F_58 ( void )
{
int V_75 ;
V_75 = F_59 () ;
if ( V_75 )
goto V_127;
F_60 ( V_128 / V_126 ) ;
F_61 ( 0 ) ;
V_75 = F_62 ( NULL , sizeof( struct V_15 ) , 0 , V_129 ) ;
if ( V_75 )
goto V_127;
V_130 . V_131 = V_129 ;
V_132 = & V_130 ;
V_127:
return V_75 ;
}
static void T_5 F_63 ( void )
{
V_132 = NULL ;
F_64 () ;
}
