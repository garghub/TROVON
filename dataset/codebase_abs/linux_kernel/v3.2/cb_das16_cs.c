static const struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
if ( V_8 [ V_6 ] . V_9 == V_5 -> V_10 )
return V_8 + V_6 ;
}
F_2 ( L_1 ) ;
return NULL ;
}
static int F_3 ( struct V_2 * V_3 ,
struct V_11 * V_12 )
{
struct V_4 * V_5 ;
struct V_13 * V_14 ;
int V_15 ;
int V_6 ;
F_2 ( L_2 , V_3 -> V_16 ) ;
V_5 = V_17 ;
if ( ! V_5 )
return - V_18 ;
V_3 -> V_19 = V_5 -> V_20 [ 0 ] -> V_21 ;
F_2 ( L_3 , V_3 -> V_19 ) ;
F_2 ( L_4 ) ;
for ( V_6 = 0 ; V_6 < 48 ; V_6 += 2 )
F_2 ( L_5 , F_4 ( V_3 -> V_19 + V_6 ) ) ;
F_2 ( L_6 ) ;
V_15 = F_5 ( V_5 -> V_22 , V_23 ,
V_24 , L_7 , V_3 ) ;
if ( V_15 < 0 )
return V_15 ;
V_3 -> V_22 = V_5 -> V_22 ;
F_2 ( L_8 , V_3 -> V_22 ) ;
V_3 -> V_25 = F_1 ( V_3 , V_5 ) ;
if ( ! V_3 -> V_25 )
return - V_18 ;
V_3 -> V_26 = V_27 -> V_28 ;
if ( F_6 ( V_3 , sizeof( struct V_29 ) ) < 0 )
return - V_30 ;
if ( F_7 ( V_3 , 4 ) < 0 )
return - V_30 ;
V_14 = V_3 -> V_31 + 0 ;
V_3 -> V_32 = V_14 ;
V_14 -> type = V_33 ;
V_14 -> V_34 = V_35 | V_36 | V_37 | V_38 ;
V_14 -> V_39 = 16 ;
V_14 -> V_40 = 0xffff ;
V_14 -> V_41 = & V_42 ;
V_14 -> V_43 = 16 ;
V_14 -> V_44 = V_45 ;
V_14 -> V_46 = V_47 ;
V_14 -> V_48 = V_49 ;
V_14 = V_3 -> V_31 + 1 ;
if ( V_27 -> V_50 ) {
V_14 -> type = V_51 ;
V_14 -> V_34 = V_52 ;
V_14 -> V_39 = V_27 -> V_50 ;
V_14 -> V_40 = 0xffff ;
V_14 -> V_41 = & V_53 ;
V_14 -> V_54 = & V_55 ;
V_14 -> V_44 = & V_56 ;
}
V_14 = V_3 -> V_31 + 2 ;
if ( 1 ) {
V_14 -> type = V_57 ;
V_14 -> V_34 = V_35 | V_52 ;
V_14 -> V_39 = 8 ;
V_14 -> V_40 = 1 ;
V_14 -> V_41 = & V_58 ;
V_14 -> V_59 = V_60 ;
V_14 -> V_61 = V_62 ;
} else {
V_14 -> type = V_63 ;
}
V_14 = V_3 -> V_31 + 3 ;
if ( 0 ) {
V_14 -> type = V_64 ;
V_14 -> V_34 = V_35 | V_52 ;
V_14 -> V_39 = 1 ;
V_14 -> V_40 = 0xff ;
V_14 -> V_41 = & V_65 ;
V_14 -> V_44 = V_66 ;
V_14 -> V_61 = V_67 ;
} else {
V_14 -> type = V_63 ;
}
F_2 ( L_9 ) ;
return 1 ;
}
static int F_8 ( struct V_2 * V_3 )
{
F_2 ( L_10 , V_3 -> V_16 ) ;
if ( V_3 -> V_22 )
F_9 ( V_3 -> V_22 , V_3 ) ;
return 0 ;
}
static T_1 V_23 ( int V_22 , void * V_68 )
{
return V_69 ;
}
static int V_45 ( struct V_2 * V_3 ,
struct V_13 * V_14 ,
struct V_70 * V_71 , unsigned int * V_72 )
{
int V_6 ;
int V_73 ;
int V_74 ;
int V_75 ;
int V_76 ;
static int V_77 [] = { 0x800 , 0x000 , 0x100 , 0x200 } ;
V_76 = F_10 ( V_71 -> V_78 ) ;
V_74 = F_11 ( V_71 -> V_78 ) ;
V_75 = F_12 ( V_71 -> V_78 ) ;
F_13 ( V_76 , V_3 -> V_19 + 2 ) ;
V_79 -> V_80 &= ~ 0xf320 ;
V_79 -> V_80 |= ( V_74 == V_81 ) ? 0 : 0x0020 ;
F_13 ( V_79 -> V_80 , V_3 -> V_19 + 4 ) ;
V_79 -> V_82 &= ~ 0xff00 ;
V_79 -> V_82 |= V_77 [ V_75 ] ;
F_13 ( V_79 -> V_82 , V_3 -> V_19 + 6 ) ;
for ( V_6 = 0 ; V_6 < V_71 -> V_83 ; V_6 ++ ) {
F_13 ( 0 , V_3 -> V_19 ) ;
#define F_14 1000
for ( V_73 = 0 ; V_73 < F_14 ; V_73 ++ ) {
if ( F_4 ( V_3 -> V_19 + 4 ) & 0x0080 )
break;
}
if ( V_73 == F_14 ) {
F_2 ( L_11 ) ;
return - V_84 ;
}
V_72 [ V_6 ] = ( unsigned short ) F_4 ( V_3 -> V_19 + 0 ) ;
}
return V_6 ;
}
static int V_47 ( struct V_2 * V_3 , struct V_13 * V_14 )
{
return - V_85 ;
}
static int V_49 ( struct V_2 * V_3 ,
struct V_13 * V_14 ,
struct V_86 * V_87 )
{
int V_88 = 0 ;
int V_89 ;
V_89 = V_87 -> V_90 ;
V_87 -> V_90 &= V_91 ;
if ( ! V_87 -> V_90 || V_89 != V_87 -> V_90 )
V_88 ++ ;
V_89 = V_87 -> V_92 ;
V_87 -> V_92 &= V_93 | V_94 ;
if ( ! V_87 -> V_92 || V_89 != V_87 -> V_92 )
V_88 ++ ;
V_89 = V_87 -> V_95 ;
V_87 -> V_95 &= V_93 | V_94 ;
if ( ! V_87 -> V_95 || V_89 != V_87 -> V_95 )
V_88 ++ ;
V_89 = V_87 -> V_96 ;
V_87 -> V_96 &= V_97 ;
if ( ! V_87 -> V_96 || V_89 != V_87 -> V_96 )
V_88 ++ ;
V_89 = V_87 -> V_98 ;
V_87 -> V_98 &= V_97 | V_99 ;
if ( ! V_87 -> V_98 || V_89 != V_87 -> V_98 )
V_88 ++ ;
if ( V_88 )
return 1 ;
if ( V_87 -> V_92 != V_93 &&
V_87 -> V_92 != V_94 )
V_88 ++ ;
if ( V_87 -> V_95 != V_93 && V_87 -> V_95 != V_94 )
V_88 ++ ;
if ( V_87 -> V_98 != V_97 && V_87 -> V_98 != V_99 )
V_88 ++ ;
if ( V_88 )
return 2 ;
if ( V_87 -> V_100 != 0 ) {
V_87 -> V_100 = 0 ;
V_88 ++ ;
}
#define F_15 10000
#define F_16 1000000000
if ( V_87 -> V_92 == V_93 ) {
if ( V_87 -> V_101 < F_15 ) {
V_87 -> V_101 = F_15 ;
V_88 ++ ;
}
if ( V_87 -> V_101 > F_16 ) {
V_87 -> V_101 = F_16 ;
V_88 ++ ;
}
} else {
if ( V_87 -> V_101 > 9 ) {
V_87 -> V_101 = 9 ;
V_88 ++ ;
}
}
if ( V_87 -> V_95 == V_93 ) {
if ( V_87 -> V_102 < F_15 ) {
V_87 -> V_102 = F_15 ;
V_88 ++ ;
}
if ( V_87 -> V_102 > F_16 ) {
V_87 -> V_102 = F_16 ;
V_88 ++ ;
}
} else {
if ( V_87 -> V_102 > 9 ) {
V_87 -> V_102 = 9 ;
V_88 ++ ;
}
}
if ( V_87 -> V_103 != V_87 -> V_104 ) {
V_87 -> V_103 = V_87 -> V_104 ;
V_88 ++ ;
}
if ( V_87 -> V_98 == V_97 ) {
if ( V_87 -> V_105 > 0x00ffffff ) {
V_87 -> V_105 = 0x00ffffff ;
V_88 ++ ;
}
} else {
if ( V_87 -> V_105 != 0 ) {
V_87 -> V_105 = 0 ;
V_88 ++ ;
}
}
if ( V_88 )
return 3 ;
if ( V_87 -> V_92 == V_93 ) {
unsigned int V_106 = 0 , V_107 = 0 ;
V_89 = V_87 -> V_101 ;
F_17 ( 100 , & V_106 , & V_107 ,
& V_87 -> V_101 ,
V_87 -> V_108 & V_109 ) ;
if ( V_89 != V_87 -> V_101 )
V_88 ++ ;
}
if ( V_87 -> V_95 == V_93 ) {
unsigned int V_106 = 0 , V_107 = 0 ;
V_89 = V_87 -> V_102 ;
F_17 ( 100 , & V_106 , & V_107 ,
& V_87 -> V_101 ,
V_87 -> V_108 & V_109 ) ;
if ( V_89 != V_87 -> V_102 )
V_88 ++ ;
if ( V_87 -> V_92 == V_93 &&
V_87 -> V_101 <
V_87 -> V_102 * V_87 -> V_103 ) {
V_87 -> V_101 =
V_87 -> V_102 * V_87 -> V_103 ;
V_88 ++ ;
}
}
if ( V_88 )
return 4 ;
return 0 ;
}
static int V_55 ( struct V_2 * V_3 ,
struct V_13 * V_14 ,
struct V_70 * V_71 , unsigned int * V_72 )
{
int V_6 ;
int V_76 = F_10 ( V_71 -> V_78 ) ;
unsigned short V_80 ;
unsigned short V_68 ;
int V_110 ;
for ( V_6 = 0 ; V_6 < V_71 -> V_83 ; V_6 ++ ) {
V_79 -> V_111 [ V_76 ] = V_72 [ V_6 ] ;
V_68 = V_72 [ V_6 ] ;
F_13 ( V_79 -> V_80 , V_3 -> V_19 + 4 ) ;
F_18 ( 1 ) ;
V_80 = V_79 -> V_80 & ~ 0xf ;
if ( V_76 )
V_80 |= 0x0001 ;
else
V_80 |= 0x0008 ;
F_13 ( V_80 , V_3 -> V_19 + 4 ) ;
F_18 ( 1 ) ;
for ( V_110 = 15 ; V_110 >= 0 ; V_110 -- ) {
int V_112 = ( V_68 >> V_110 ) & 0x1 ;
V_112 <<= 1 ;
F_13 ( V_80 | V_112 | 0x0000 , V_3 -> V_19 + 4 ) ;
F_18 ( 1 ) ;
F_13 ( V_80 | V_112 | 0x0004 , V_3 -> V_19 + 4 ) ;
F_18 ( 1 ) ;
}
F_13 ( V_80 | 0x9 , V_3 -> V_19 + 4 ) ;
}
return V_6 ;
}
static int V_56 ( struct V_2 * V_3 ,
struct V_13 * V_14 ,
struct V_70 * V_71 , unsigned int * V_72 )
{
int V_6 ;
int V_76 = F_10 ( V_71 -> V_78 ) ;
for ( V_6 = 0 ; V_6 < V_71 -> V_83 ; V_6 ++ )
V_72 [ V_6 ] = V_79 -> V_111 [ V_76 ] ;
return V_6 ;
}
static int V_60 ( struct V_2 * V_3 ,
struct V_13 * V_14 ,
struct V_70 * V_71 , unsigned int * V_72 )
{
if ( V_71 -> V_83 != 2 )
return - V_85 ;
if ( V_72 [ 0 ] ) {
V_14 -> V_113 &= ~ V_72 [ 0 ] ;
V_14 -> V_113 |= V_72 [ 0 ] & V_72 [ 1 ] ;
F_13 ( V_14 -> V_113 , V_3 -> V_19 + 16 ) ;
}
V_72 [ 1 ] = F_4 ( V_3 -> V_19 + 16 ) ;
return 2 ;
}
static int V_62 ( struct V_2 * V_3 ,
struct V_13 * V_14 ,
struct V_70 * V_71 , unsigned int * V_72 )
{
int V_76 = F_10 ( V_71 -> V_78 ) ;
int V_114 ;
if ( V_76 < 4 )
V_114 = 0x0f ;
else
V_114 = 0xf0 ;
switch ( V_72 [ 0 ] ) {
case V_115 :
V_14 -> V_116 |= V_114 ;
break;
case V_117 :
V_14 -> V_116 &= V_114 ;
break;
case V_118 :
V_72 [ 1 ] =
( V_14 -> V_116 & ( 1 << V_76 ) ) ? V_119 : V_120 ;
return V_71 -> V_83 ;
break;
default:
return - V_85 ;
break;
}
V_79 -> V_82 &= ~ 0x00c0 ;
V_79 -> V_82 |= ( V_14 -> V_116 & 0xf0 ) ? 0x0080 : 0 ;
V_79 -> V_82 |= ( V_14 -> V_116 & 0x0f ) ? 0x0040 : 0 ;
F_13 ( V_79 -> V_82 , V_3 -> V_19 + 6 ) ;
return V_71 -> V_83 ;
}
static int V_66 ( struct V_2 * V_3 ,
struct V_13 * V_14 ,
struct V_70 * V_71 , unsigned int * V_72 )
{
return - V_85 ;
}
static int V_67 ( struct V_2 * V_3 ,
struct V_13 * V_14 ,
struct V_70 * V_71 ,
unsigned int * V_72 )
{
return - V_85 ;
}
static int F_19 ( struct V_4 * V_5 )
{
struct V_121 * V_122 ;
F_20 ( & V_5 -> V_3 , L_12 ) ;
V_122 = F_21 ( sizeof( struct V_121 ) , V_123 ) ;
if ( ! V_122 )
return - V_30 ;
V_122 -> V_5 = V_5 ;
V_5 -> V_124 = V_122 ;
V_17 = V_5 ;
F_22 ( V_5 ) ;
return 0 ;
}
static void F_23 ( struct V_4 * V_5 )
{
F_20 ( & V_5 -> V_3 , L_13 ) ;
( (struct V_121 * ) V_5 -> V_124 ) -> V_125 = 1 ;
F_24 ( V_5 ) ;
F_25 ( V_5 -> V_124 ) ;
}
static int F_26 ( struct V_4 * V_126 ,
void * V_127 )
{
if ( V_126 -> V_128 == 0 )
return - V_85 ;
return F_27 ( V_126 ) ;
}
static void F_22 ( struct V_4 * V_5 )
{
int V_15 ;
F_20 ( & V_5 -> V_3 , L_14 ) ;
V_5 -> V_129 |= V_130 | V_131 ;
V_15 = F_28 ( V_5 , F_26 , NULL ) ;
if ( V_15 ) {
F_29 ( & V_5 -> V_3 , L_15 ) ;
goto V_132;
}
if ( ! V_5 -> V_22 )
goto V_132;
V_15 = F_30 ( V_5 ) ;
if ( V_15 )
goto V_132;
return;
V_132:
F_24 ( V_5 ) ;
}
static void F_24 ( struct V_4 * V_5 )
{
F_20 ( & V_5 -> V_3 , L_16 ) ;
F_31 ( V_5 ) ;
}
static int F_32 ( struct V_4 * V_5 )
{
struct V_121 * V_122 = V_5 -> V_124 ;
V_122 -> V_125 = 1 ;
return 0 ;
}
static int F_33 ( struct V_4 * V_5 )
{
struct V_121 * V_122 = V_5 -> V_124 ;
V_122 -> V_125 = 0 ;
return 0 ;
}
static int T_2 F_34 ( void )
{
F_35 ( & V_133 ) ;
return 0 ;
}
static void T_3 F_36 ( void )
{
F_37 ( L_17 ) ;
F_38 ( & V_133 ) ;
}
int T_2 F_39 ( void )
{
int V_15 ;
V_15 = F_34 () ;
if ( V_15 < 0 )
return V_15 ;
return F_40 ( & V_134 ) ;
}
void T_3 F_41 ( void )
{
F_36 () ;
F_42 ( & V_134 ) ;
}
static int T_2 F_43 ( void )
{
return F_40 ( & V_134 ) ;
}
static void T_3 F_44 ( void )
{
F_42 ( & V_134 ) ;
}
