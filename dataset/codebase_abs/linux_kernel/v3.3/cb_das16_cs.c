static const struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
if ( V_8 [ V_6 ] . V_9 == V_5 -> V_10 )
return V_8 + V_6 ;
}
F_2 ( V_3 -> V_11 , L_1 ) ;
return NULL ;
}
static int F_3 ( struct V_2 * V_3 ,
struct V_12 * V_13 )
{
struct V_4 * V_5 ;
struct V_14 * V_15 ;
int V_16 ;
int V_6 ;
F_2 ( V_3 -> V_11 , L_2 , V_3 -> V_17 ) ;
V_5 = V_18 ;
if ( ! V_5 )
return - V_19 ;
V_3 -> V_20 = V_5 -> V_21 [ 0 ] -> V_22 ;
F_2 ( V_3 -> V_11 , L_3 , V_3 -> V_20 ) ;
F_2 ( V_3 -> V_11 , L_4 ) ;
for ( V_6 = 0 ; V_6 < 48 ; V_6 += 2 )
F_2 ( V_3 -> V_11 , L_5 , F_4 ( V_3 -> V_20 + V_6 ) ) ;
V_16 = F_5 ( V_5 -> V_23 , V_24 ,
V_25 , L_6 , V_3 ) ;
if ( V_16 < 0 )
return V_16 ;
V_3 -> V_23 = V_5 -> V_23 ;
F_2 ( V_3 -> V_11 , L_7 , V_3 -> V_23 ) ;
V_3 -> V_26 = F_1 ( V_3 , V_5 ) ;
if ( ! V_3 -> V_26 )
return - V_19 ;
V_3 -> V_27 = V_28 -> V_29 ;
if ( F_6 ( V_3 , sizeof( struct V_30 ) ) < 0 )
return - V_31 ;
if ( F_7 ( V_3 , 4 ) < 0 )
return - V_31 ;
V_15 = V_3 -> V_32 + 0 ;
V_3 -> V_33 = V_15 ;
V_15 -> type = V_34 ;
V_15 -> V_35 = V_36 | V_37 | V_38 | V_39 ;
V_15 -> V_40 = 16 ;
V_15 -> V_41 = 0xffff ;
V_15 -> V_42 = & V_43 ;
V_15 -> V_44 = 16 ;
V_15 -> V_45 = V_46 ;
V_15 -> V_47 = V_48 ;
V_15 -> V_49 = V_50 ;
V_15 = V_3 -> V_32 + 1 ;
if ( V_28 -> V_51 ) {
V_15 -> type = V_52 ;
V_15 -> V_35 = V_53 ;
V_15 -> V_40 = V_28 -> V_51 ;
V_15 -> V_41 = 0xffff ;
V_15 -> V_42 = & V_54 ;
V_15 -> V_55 = & V_56 ;
V_15 -> V_45 = & V_57 ;
}
V_15 = V_3 -> V_32 + 2 ;
if ( 1 ) {
V_15 -> type = V_58 ;
V_15 -> V_35 = V_36 | V_53 ;
V_15 -> V_40 = 8 ;
V_15 -> V_41 = 1 ;
V_15 -> V_42 = & V_59 ;
V_15 -> V_60 = V_61 ;
V_15 -> V_62 = V_63 ;
} else {
V_15 -> type = V_64 ;
}
V_15 = V_3 -> V_32 + 3 ;
if ( 0 ) {
V_15 -> type = V_65 ;
V_15 -> V_35 = V_36 | V_53 ;
V_15 -> V_40 = 1 ;
V_15 -> V_41 = 0xff ;
V_15 -> V_42 = & V_66 ;
V_15 -> V_45 = V_67 ;
V_15 -> V_62 = V_68 ;
} else {
V_15 -> type = V_64 ;
}
return 1 ;
}
static int F_8 ( struct V_2 * V_3 )
{
F_2 ( V_3 -> V_11 , L_8 , V_3 -> V_17 ) ;
if ( V_3 -> V_23 )
F_9 ( V_3 -> V_23 , V_3 ) ;
return 0 ;
}
static T_1 V_24 ( int V_23 , void * V_69 )
{
return V_70 ;
}
static int V_46 ( struct V_2 * V_3 ,
struct V_14 * V_15 ,
struct V_71 * V_72 , unsigned int * V_73 )
{
int V_6 ;
int V_74 ;
int V_75 ;
int V_76 ;
int V_77 ;
static int V_78 [] = { 0x800 , 0x000 , 0x100 , 0x200 } ;
V_77 = F_10 ( V_72 -> V_79 ) ;
V_75 = F_11 ( V_72 -> V_79 ) ;
V_76 = F_12 ( V_72 -> V_79 ) ;
F_13 ( V_77 , V_3 -> V_20 + 2 ) ;
V_80 -> V_81 &= ~ 0xf320 ;
V_80 -> V_81 |= ( V_75 == V_82 ) ? 0 : 0x0020 ;
F_13 ( V_80 -> V_81 , V_3 -> V_20 + 4 ) ;
V_80 -> V_83 &= ~ 0xff00 ;
V_80 -> V_83 |= V_78 [ V_76 ] ;
F_13 ( V_80 -> V_83 , V_3 -> V_20 + 6 ) ;
for ( V_6 = 0 ; V_6 < V_72 -> V_84 ; V_6 ++ ) {
F_13 ( 0 , V_3 -> V_20 ) ;
#define F_14 1000
for ( V_74 = 0 ; V_74 < F_14 ; V_74 ++ ) {
if ( F_4 ( V_3 -> V_20 + 4 ) & 0x0080 )
break;
}
if ( V_74 == F_14 ) {
F_2 ( V_3 -> V_11 , L_9 ) ;
return - V_85 ;
}
V_73 [ V_6 ] = ( unsigned short ) F_4 ( V_3 -> V_20 + 0 ) ;
}
return V_6 ;
}
static int V_48 ( struct V_2 * V_3 , struct V_14 * V_15 )
{
return - V_86 ;
}
static int V_50 ( struct V_2 * V_3 ,
struct V_14 * V_15 ,
struct V_87 * V_88 )
{
int V_89 = 0 ;
int V_90 ;
V_90 = V_88 -> V_91 ;
V_88 -> V_91 &= V_92 ;
if ( ! V_88 -> V_91 || V_90 != V_88 -> V_91 )
V_89 ++ ;
V_90 = V_88 -> V_93 ;
V_88 -> V_93 &= V_94 | V_95 ;
if ( ! V_88 -> V_93 || V_90 != V_88 -> V_93 )
V_89 ++ ;
V_90 = V_88 -> V_96 ;
V_88 -> V_96 &= V_94 | V_95 ;
if ( ! V_88 -> V_96 || V_90 != V_88 -> V_96 )
V_89 ++ ;
V_90 = V_88 -> V_97 ;
V_88 -> V_97 &= V_98 ;
if ( ! V_88 -> V_97 || V_90 != V_88 -> V_97 )
V_89 ++ ;
V_90 = V_88 -> V_99 ;
V_88 -> V_99 &= V_98 | V_100 ;
if ( ! V_88 -> V_99 || V_90 != V_88 -> V_99 )
V_89 ++ ;
if ( V_89 )
return 1 ;
if ( V_88 -> V_93 != V_94 &&
V_88 -> V_93 != V_95 )
V_89 ++ ;
if ( V_88 -> V_96 != V_94 && V_88 -> V_96 != V_95 )
V_89 ++ ;
if ( V_88 -> V_99 != V_98 && V_88 -> V_99 != V_100 )
V_89 ++ ;
if ( V_89 )
return 2 ;
if ( V_88 -> V_101 != 0 ) {
V_88 -> V_101 = 0 ;
V_89 ++ ;
}
#define F_15 10000
#define F_16 1000000000
if ( V_88 -> V_93 == V_94 ) {
if ( V_88 -> V_102 < F_15 ) {
V_88 -> V_102 = F_15 ;
V_89 ++ ;
}
if ( V_88 -> V_102 > F_16 ) {
V_88 -> V_102 = F_16 ;
V_89 ++ ;
}
} else {
if ( V_88 -> V_102 > 9 ) {
V_88 -> V_102 = 9 ;
V_89 ++ ;
}
}
if ( V_88 -> V_96 == V_94 ) {
if ( V_88 -> V_103 < F_15 ) {
V_88 -> V_103 = F_15 ;
V_89 ++ ;
}
if ( V_88 -> V_103 > F_16 ) {
V_88 -> V_103 = F_16 ;
V_89 ++ ;
}
} else {
if ( V_88 -> V_103 > 9 ) {
V_88 -> V_103 = 9 ;
V_89 ++ ;
}
}
if ( V_88 -> V_104 != V_88 -> V_105 ) {
V_88 -> V_104 = V_88 -> V_105 ;
V_89 ++ ;
}
if ( V_88 -> V_99 == V_98 ) {
if ( V_88 -> V_106 > 0x00ffffff ) {
V_88 -> V_106 = 0x00ffffff ;
V_89 ++ ;
}
} else {
if ( V_88 -> V_106 != 0 ) {
V_88 -> V_106 = 0 ;
V_89 ++ ;
}
}
if ( V_89 )
return 3 ;
if ( V_88 -> V_93 == V_94 ) {
unsigned int V_107 = 0 , V_108 = 0 ;
V_90 = V_88 -> V_102 ;
F_17 ( 100 , & V_107 , & V_108 ,
& V_88 -> V_102 ,
V_88 -> V_109 & V_110 ) ;
if ( V_90 != V_88 -> V_102 )
V_89 ++ ;
}
if ( V_88 -> V_96 == V_94 ) {
unsigned int V_107 = 0 , V_108 = 0 ;
V_90 = V_88 -> V_103 ;
F_17 ( 100 , & V_107 , & V_108 ,
& V_88 -> V_102 ,
V_88 -> V_109 & V_110 ) ;
if ( V_90 != V_88 -> V_103 )
V_89 ++ ;
if ( V_88 -> V_93 == V_94 &&
V_88 -> V_102 <
V_88 -> V_103 * V_88 -> V_104 ) {
V_88 -> V_102 =
V_88 -> V_103 * V_88 -> V_104 ;
V_89 ++ ;
}
}
if ( V_89 )
return 4 ;
return 0 ;
}
static int V_56 ( struct V_2 * V_3 ,
struct V_14 * V_15 ,
struct V_71 * V_72 , unsigned int * V_73 )
{
int V_6 ;
int V_77 = F_10 ( V_72 -> V_79 ) ;
unsigned short V_81 ;
unsigned short V_69 ;
int V_111 ;
for ( V_6 = 0 ; V_6 < V_72 -> V_84 ; V_6 ++ ) {
V_80 -> V_112 [ V_77 ] = V_73 [ V_6 ] ;
V_69 = V_73 [ V_6 ] ;
F_13 ( V_80 -> V_81 , V_3 -> V_20 + 4 ) ;
F_18 ( 1 ) ;
V_81 = V_80 -> V_81 & ~ 0xf ;
if ( V_77 )
V_81 |= 0x0001 ;
else
V_81 |= 0x0008 ;
F_13 ( V_81 , V_3 -> V_20 + 4 ) ;
F_18 ( 1 ) ;
for ( V_111 = 15 ; V_111 >= 0 ; V_111 -- ) {
int V_113 = ( V_69 >> V_111 ) & 0x1 ;
V_113 <<= 1 ;
F_13 ( V_81 | V_113 | 0x0000 , V_3 -> V_20 + 4 ) ;
F_18 ( 1 ) ;
F_13 ( V_81 | V_113 | 0x0004 , V_3 -> V_20 + 4 ) ;
F_18 ( 1 ) ;
}
F_13 ( V_81 | 0x9 , V_3 -> V_20 + 4 ) ;
}
return V_6 ;
}
static int V_57 ( struct V_2 * V_3 ,
struct V_14 * V_15 ,
struct V_71 * V_72 , unsigned int * V_73 )
{
int V_6 ;
int V_77 = F_10 ( V_72 -> V_79 ) ;
for ( V_6 = 0 ; V_6 < V_72 -> V_84 ; V_6 ++ )
V_73 [ V_6 ] = V_80 -> V_112 [ V_77 ] ;
return V_6 ;
}
static int V_61 ( struct V_2 * V_3 ,
struct V_14 * V_15 ,
struct V_71 * V_72 , unsigned int * V_73 )
{
if ( V_72 -> V_84 != 2 )
return - V_86 ;
if ( V_73 [ 0 ] ) {
V_15 -> V_114 &= ~ V_73 [ 0 ] ;
V_15 -> V_114 |= V_73 [ 0 ] & V_73 [ 1 ] ;
F_13 ( V_15 -> V_114 , V_3 -> V_20 + 16 ) ;
}
V_73 [ 1 ] = F_4 ( V_3 -> V_20 + 16 ) ;
return 2 ;
}
static int V_63 ( struct V_2 * V_3 ,
struct V_14 * V_15 ,
struct V_71 * V_72 , unsigned int * V_73 )
{
int V_77 = F_10 ( V_72 -> V_79 ) ;
int V_115 ;
if ( V_77 < 4 )
V_115 = 0x0f ;
else
V_115 = 0xf0 ;
switch ( V_73 [ 0 ] ) {
case V_116 :
V_15 -> V_117 |= V_115 ;
break;
case V_118 :
V_15 -> V_117 &= V_115 ;
break;
case V_119 :
V_73 [ 1 ] =
( V_15 -> V_117 & ( 1 << V_77 ) ) ? V_120 : V_121 ;
return V_72 -> V_84 ;
break;
default:
return - V_86 ;
break;
}
V_80 -> V_83 &= ~ 0x00c0 ;
V_80 -> V_83 |= ( V_15 -> V_117 & 0xf0 ) ? 0x0080 : 0 ;
V_80 -> V_83 |= ( V_15 -> V_117 & 0x0f ) ? 0x0040 : 0 ;
F_13 ( V_80 -> V_83 , V_3 -> V_20 + 6 ) ;
return V_72 -> V_84 ;
}
static int V_67 ( struct V_2 * V_3 ,
struct V_14 * V_15 ,
struct V_71 * V_72 , unsigned int * V_73 )
{
return - V_86 ;
}
static int V_68 ( struct V_2 * V_3 ,
struct V_14 * V_15 ,
struct V_71 * V_72 ,
unsigned int * V_73 )
{
return - V_86 ;
}
static int F_19 ( struct V_4 * V_5 )
{
struct V_122 * V_123 ;
F_2 ( & V_5 -> V_3 , L_10 ) ;
V_123 = F_20 ( sizeof( struct V_122 ) , V_124 ) ;
if ( ! V_123 )
return - V_31 ;
V_123 -> V_5 = V_5 ;
V_5 -> V_125 = V_123 ;
V_18 = V_5 ;
F_21 ( V_5 ) ;
return 0 ;
}
static void F_22 ( struct V_4 * V_5 )
{
F_2 ( & V_5 -> V_3 , L_11 ) ;
( (struct V_122 * ) V_5 -> V_125 ) -> V_126 = 1 ;
F_23 ( V_5 ) ;
F_24 ( V_5 -> V_125 ) ;
}
static int F_25 ( struct V_4 * V_127 ,
void * V_128 )
{
if ( V_127 -> V_129 == 0 )
return - V_86 ;
return F_26 ( V_127 ) ;
}
static void F_21 ( struct V_4 * V_5 )
{
int V_16 ;
F_2 ( & V_5 -> V_3 , L_12 ) ;
V_5 -> V_130 |= V_131 | V_132 ;
V_16 = F_27 ( V_5 , F_25 , NULL ) ;
if ( V_16 ) {
F_28 ( & V_5 -> V_3 , L_13 ) ;
goto V_133;
}
if ( ! V_5 -> V_23 )
goto V_133;
V_16 = F_29 ( V_5 ) ;
if ( V_16 )
goto V_133;
return;
V_133:
F_23 ( V_5 ) ;
}
static void F_23 ( struct V_4 * V_5 )
{
F_2 ( & V_5 -> V_3 , L_14 ) ;
F_30 ( V_5 ) ;
}
static int F_31 ( struct V_4 * V_5 )
{
struct V_122 * V_123 = V_5 -> V_125 ;
V_123 -> V_126 = 1 ;
return 0 ;
}
static int F_32 ( struct V_4 * V_5 )
{
struct V_122 * V_123 = V_5 -> V_125 ;
V_123 -> V_126 = 0 ;
return 0 ;
}
static int T_2 F_33 ( void )
{
F_34 ( & V_134 ) ;
return 0 ;
}
static void T_3 F_35 ( void )
{
F_36 ( L_15 ) ;
F_37 ( & V_134 ) ;
}
int T_2 F_38 ( void )
{
int V_16 ;
V_16 = F_33 () ;
if ( V_16 < 0 )
return V_16 ;
return F_39 ( & V_135 ) ;
}
void T_3 F_40 ( void )
{
F_35 () ;
F_41 ( & V_135 ) ;
}
static int T_2 F_42 ( void )
{
return F_39 ( & V_135 ) ;
}
static void T_3 F_43 ( void )
{
F_41 ( & V_135 ) ;
}
