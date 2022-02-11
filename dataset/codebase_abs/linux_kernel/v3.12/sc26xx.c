static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_2 -> line * 0x20 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_2 -> line * 0x20 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_6 , int V_7 )
{
struct V_8 * V_9 ;
int line = V_6 -> line ;
V_6 -= line ;
V_9 = F_6 ( V_6 , struct V_8 , V_6 [ 0 ] ) ;
V_9 -> V_10 |= V_7 << ( line * 4 ) ;
F_7 ( V_6 , V_11 , V_9 -> V_10 ) ;
}
static void F_8 ( struct V_1 * V_6 , int V_7 )
{
struct V_8 * V_9 ;
int line = V_6 -> line ;
V_6 -= line ;
V_9 = F_6 ( V_6 , struct V_8 , V_6 [ 0 ] ) ;
V_9 -> V_10 &= ~ ( V_7 << ( line * 4 ) ) ;
F_7 ( V_6 , V_11 , V_9 -> V_10 ) ;
}
static bool F_9 ( struct V_1 * V_6 )
{
struct V_12 * V_13 = NULL ;
int V_14 = 10000 ;
unsigned char V_15 ;
char V_16 ;
T_1 V_17 ;
if ( V_6 -> V_18 != NULL )
V_13 = & V_6 -> V_18 -> V_6 ;
while ( V_14 -- > 0 ) {
V_17 = F_10 ( V_6 , V_19 ) ;
if ( ! ( V_17 & V_20 ) )
break;
V_15 = F_10 ( V_6 , V_21 ) ;
V_16 = V_22 ;
V_6 -> V_23 . V_24 ++ ;
if ( F_11 ( V_17 & ( V_25 | V_26 |
V_27 | V_28 ) ) ) {
if ( V_17 & V_25 ) {
V_17 &= ~ ( V_27 | V_26 ) ;
V_6 -> V_23 . V_29 ++ ;
if ( F_12 ( V_6 ) )
continue;
} else if ( V_17 & V_27 )
V_6 -> V_23 . V_30 ++ ;
else if ( V_17 & V_26 )
V_6 -> V_23 . V_31 ++ ;
if ( V_17 & V_28 )
V_6 -> V_23 . V_32 ++ ;
V_17 &= V_6 -> V_33 ;
if ( V_17 & V_25 )
V_16 = V_34 ;
else if ( V_17 & V_27 )
V_16 = V_35 ;
else if ( V_17 & V_26 )
V_16 = V_36 ;
}
if ( F_13 ( V_6 , V_15 ) )
continue;
if ( V_17 & V_6 -> V_37 )
continue;
F_14 ( V_13 , V_15 , V_16 ) ;
}
return ! ! V_13 ;
}
static void F_15 ( struct V_1 * V_6 )
{
struct V_38 * V_39 ;
if ( ! V_6 -> V_18 )
return;
V_39 = & V_6 -> V_18 -> V_39 ;
if ( F_16 ( V_39 ) || F_17 ( V_6 ) ) {
F_8 ( V_6 , V_40 ) ;
return;
}
while ( ! F_16 ( V_39 ) ) {
if ( ! ( F_10 ( V_6 , V_19 ) & V_41 ) )
break;
F_18 ( V_6 , V_42 , V_39 -> V_43 [ V_39 -> V_44 ] ) ;
V_39 -> V_44 = ( V_39 -> V_44 + 1 ) & ( V_45 - 1 ) ;
V_6 -> V_23 . V_46 ++ ;
}
if ( F_19 ( V_39 ) < V_47 )
F_20 ( V_6 ) ;
}
static T_2 F_21 ( int V_48 , void * V_49 )
{
struct V_8 * V_9 = V_49 ;
unsigned long V_50 ;
bool V_51 ;
T_1 V_52 ;
F_22 ( & V_9 -> V_6 [ 0 ] . V_53 , V_50 ) ;
V_51 = false ;
V_52 = F_23 ( & V_9 -> V_6 [ 0 ] , V_54 ) ;
if ( V_52 & V_55 )
F_15 ( & V_9 -> V_6 [ 0 ] ) ;
if ( V_52 & V_56 )
V_51 = F_9 ( & V_9 -> V_6 [ 0 ] ) ;
F_24 ( & V_9 -> V_6 [ 0 ] . V_53 ) ;
if ( V_51 )
F_25 ( & V_9 -> V_6 [ 0 ] . V_18 -> V_6 ) ;
F_26 ( & V_9 -> V_6 [ 1 ] . V_53 ) ;
V_51 = false ;
if ( V_52 & V_57 )
F_15 ( & V_9 -> V_6 [ 1 ] ) ;
if ( V_52 & V_58 )
V_51 = F_9 ( & V_9 -> V_6 [ 1 ] ) ;
F_27 ( & V_9 -> V_6 [ 1 ] . V_53 , V_50 ) ;
if ( V_51 )
F_25 ( & V_9 -> V_6 [ 1 ] . V_18 -> V_6 ) ;
return V_59 ;
}
static unsigned int F_28 ( struct V_1 * V_6 )
{
return ( F_10 ( V_6 , V_19 ) & V_41 ) ? V_60 : 0 ;
}
static void F_29 ( struct V_1 * V_6 , unsigned int V_61 )
{
struct V_8 * V_9 ;
int line = V_6 -> line ;
V_6 -= line ;
V_9 = F_6 ( V_6 , struct V_8 , V_6 [ 0 ] ) ;
if ( V_9 -> V_62 [ line ] ) {
if ( V_61 & V_63 )
F_7 ( V_6 , V_64 , V_9 -> V_62 [ line ] ) ;
else
F_7 ( V_6 , V_65 , V_9 -> V_62 [ line ] ) ;
}
if ( V_9 -> V_66 [ line ] ) {
if ( V_61 & V_67 )
F_7 ( V_6 , V_64 , V_9 -> V_66 [ line ] ) ;
else
F_7 ( V_6 , V_65 , V_9 -> V_66 [ line ] ) ;
}
}
static unsigned int F_30 ( struct V_1 * V_6 )
{
struct V_8 * V_9 ;
int line = V_6 -> line ;
unsigned int V_61 = V_68 | V_69 | V_70 ;
T_1 V_71 ;
V_6 -= line ;
V_9 = F_6 ( V_6 , struct V_8 , V_6 [ 0 ] ) ;
V_71 = F_23 ( V_6 , V_72 ) ^ 0xff ;
if ( V_9 -> V_73 [ line ] ) {
V_61 &= ~ V_68 ;
V_61 |= V_71 & V_9 -> V_73 [ line ] ? V_68 : 0 ;
}
if ( V_9 -> V_74 [ line ] ) {
V_61 &= ~ V_69 ;
V_61 |= V_71 & V_9 -> V_74 [ line ] ? V_69 : 0 ;
}
if ( V_9 -> V_75 [ line ] ) {
V_61 &= ~ V_70 ;
V_61 |= V_71 & V_9 -> V_75 [ line ] ? V_70 : 0 ;
}
if ( V_9 -> V_76 [ line ] ) {
V_61 &= ~ V_77 ;
V_61 |= V_71 & V_9 -> V_76 [ line ] ? V_77 : 0 ;
}
return V_61 ;
}
static void F_31 ( struct V_1 * V_6 )
{
return;
}
static void F_32 ( struct V_1 * V_6 )
{
struct V_38 * V_39 = & V_6 -> V_18 -> V_39 ;
while ( ! F_16 ( V_39 ) ) {
if ( ! ( F_10 ( V_6 , V_19 ) & V_41 ) ) {
F_5 ( V_6 , V_40 ) ;
break;
}
F_18 ( V_6 , V_42 , V_39 -> V_43 [ V_39 -> V_44 ] ) ;
V_39 -> V_44 = ( V_39 -> V_44 + 1 ) & ( V_45 - 1 ) ;
V_6 -> V_23 . V_46 ++ ;
}
}
static void F_33 ( struct V_1 * V_6 )
{
}
static void F_34 ( struct V_1 * V_6 )
{
}
static void F_35 ( struct V_1 * V_6 , int V_78 )
{
if ( V_78 == - 1 )
F_18 ( V_6 , V_79 , V_80 ) ;
else
F_18 ( V_6 , V_79 , V_81 ) ;
}
static int F_36 ( struct V_1 * V_6 )
{
F_8 ( V_6 , V_40 | V_82 ) ;
F_7 ( V_6 , V_83 , 0 ) ;
F_18 ( V_6 , V_79 , V_84 ) ;
F_18 ( V_6 , V_79 , V_85 ) ;
F_18 ( V_6 , V_79 , V_86 | V_87 ) ;
F_5 ( V_6 , V_82 ) ;
return 0 ;
}
static void F_37 ( struct V_1 * V_6 )
{
F_8 ( V_6 , V_40 | V_82 ) ;
F_18 ( V_6 , V_79 , V_88 | V_89 ) ;
}
static void F_38 ( struct V_1 * V_6 , struct V_90 * V_91 ,
struct V_90 * V_92 )
{
unsigned int V_93 = F_39 ( V_6 , V_91 , V_92 , 0 , 4000000 ) ;
unsigned int V_94 = F_40 ( V_6 , V_93 ) ;
unsigned int V_95 , V_96 ;
unsigned long V_50 ;
T_1 V_97 , V_98 , V_99 ;
F_22 ( & V_6 -> V_53 , V_50 ) ;
while ( ( F_10 ( V_6 , V_19 ) & ( ( 1 << 3 ) | ( 1 << 2 ) ) ) != 0xc )
F_41 ( 2 ) ;
F_18 ( V_6 , V_79 , V_88 | V_89 ) ;
V_95 = V_91 -> V_100 ;
V_96 = V_91 -> V_101 ;
V_6 -> V_33 = V_28 ;
if ( V_95 & V_102 )
V_6 -> V_33 |= V_27 | V_26 ;
if ( V_95 & ( V_103 | V_104 ) )
V_6 -> V_33 |= V_25 ;
V_6 -> V_37 = 0 ;
if ( V_95 & V_105 )
V_6 -> V_37 |= V_25 ;
if ( ( V_96 & V_106 ) == 0 )
V_6 -> V_37 |= V_25 | V_26 |
V_27 | V_28 ;
switch ( V_96 & V_107 ) {
case V_108 :
V_97 = 0x00 ;
break;
case V_109 :
V_97 = 0x01 ;
break;
case V_110 :
V_97 = 0x02 ;
break;
default:
case V_111 :
V_97 = 0x03 ;
break;
}
V_98 = 0x07 ;
if ( V_96 & V_112 )
V_98 = 0x0f ;
if ( V_96 & V_113 ) {
if ( V_96 & V_114 )
V_97 |= ( 1 << 2 ) ;
} else
V_97 |= ( 2 << 3 ) ;
switch ( V_93 ) {
case 50 :
V_99 = 0x00 ;
break;
case 110 :
V_99 = 0x11 ;
break;
case 134 :
V_99 = 0x22 ;
break;
case 200 :
V_99 = 0x33 ;
break;
case 300 :
V_99 = 0x44 ;
break;
case 600 :
V_99 = 0x55 ;
break;
case 1200 :
V_99 = 0x66 ;
break;
case 2400 :
V_99 = 0x88 ;
break;
case 4800 :
V_99 = 0x99 ;
break;
default:
case 9600 :
V_99 = 0xbb ;
break;
case 19200 :
V_99 = 0xcc ;
break;
}
F_18 ( V_6 , V_79 , V_115 ) ;
F_18 ( V_6 , V_116 , V_97 ) ;
F_18 ( V_6 , V_116 , V_98 ) ;
F_7 ( V_6 , V_117 , 0x80 ) ;
F_18 ( V_6 , V_118 , V_99 ) ;
F_18 ( V_6 , V_79 , V_84 ) ;
F_18 ( V_6 , V_79 , V_85 ) ;
F_18 ( V_6 , V_79 , V_86 | V_87 ) ;
while ( ( F_10 ( V_6 , V_19 ) & ( ( 1 << 3 ) | ( 1 << 2 ) ) ) != 0xc )
F_41 ( 2 ) ;
F_42 ( V_6 , V_96 ,
( V_6 -> V_119 / ( 16 * V_94 ) ) ) ;
F_27 ( & V_6 -> V_53 , V_50 ) ;
}
static const char * F_43 ( struct V_1 * V_6 )
{
return L_1 ;
}
static void F_44 ( struct V_1 * V_6 )
{
}
static int F_45 ( struct V_1 * V_6 )
{
return 0 ;
}
static void F_46 ( struct V_1 * V_6 , int V_50 )
{
}
static int F_47 ( struct V_1 * V_6 , struct V_120 * V_121 )
{
return - V_122 ;
}
static void F_48 ( struct V_1 * V_6 , char V_123 )
{
unsigned long V_50 ;
int V_14 = 1000000 ;
F_22 ( & V_6 -> V_53 , V_50 ) ;
while ( V_14 -- > 0 ) {
if ( F_10 ( V_6 , V_19 ) & V_41 ) {
F_18 ( V_6 , V_42 , V_123 ) ;
break;
}
F_41 ( 2 ) ;
}
F_27 ( & V_6 -> V_53 , V_50 ) ;
}
static void F_49 ( struct V_124 * V_125 , const char * V_126 , unsigned V_127 )
{
struct V_1 * V_6 = V_128 ;
int V_129 ;
for ( V_129 = 0 ; V_129 < V_127 ; V_129 ++ ) {
if ( * V_126 == '\n' )
F_48 ( V_6 , '\r' ) ;
F_48 ( V_6 , * V_126 ++ ) ;
}
}
static int T_3 F_50 ( struct V_124 * V_125 , char * V_130 )
{
struct V_1 * V_6 = V_128 ;
int V_93 = 9600 ;
int V_131 = 8 ;
int V_30 = 'n' ;
int V_132 = 'n' ;
if ( V_6 -> type != V_133 )
return - 1 ;
F_51 ( V_134 L_2 , V_125 -> V_135 ) ;
if ( V_130 )
F_52 ( V_130 , & V_93 , & V_30 , & V_131 , & V_132 ) ;
return F_53 ( V_6 , V_125 , V_93 , V_30 , V_131 , V_132 ) ;
}
static T_1 F_54 ( unsigned int V_50 , unsigned int V_136 )
{
unsigned int V_137 = ( V_50 >> V_136 ) & 15 ;
return V_137 ? ( 1 << ( V_137 - 1 ) ) : 0 ;
}
static void F_55 ( struct V_8 * V_9 ,
int line , unsigned int V_138 )
{
V_9 -> V_62 [ line ] = F_54 ( V_138 , 0 ) ;
V_9 -> V_66 [ line ] = F_54 ( V_138 , 4 ) ;
V_9 -> V_73 [ line ] = F_54 ( V_138 , 8 ) ;
V_9 -> V_74 [ line ] = F_54 ( V_138 , 12 ) ;
V_9 -> V_75 [ line ] = F_54 ( V_138 , 16 ) ;
V_9 -> V_76 [ line ] = F_54 ( V_138 , 20 ) ;
}
static int F_56 ( struct V_139 * V_140 )
{
struct V_141 * V_142 ;
struct V_8 * V_9 ;
unsigned int * V_143 = F_57 ( & V_140 -> V_140 ) ;
int V_144 ;
V_142 = F_58 ( V_140 , V_145 , 0 ) ;
if ( ! V_142 )
return - V_146 ;
V_9 = F_59 ( sizeof *V_9 , V_147 ) ;
if ( F_11 ( ! V_9 ) )
return - V_148 ;
V_9 -> V_6 [ 0 ] . line = 0 ;
V_9 -> V_6 [ 0 ] . V_149 = & V_150 ;
V_9 -> V_6 [ 0 ] . type = V_133 ;
V_9 -> V_6 [ 0 ] . V_119 = ( 29491200 / 16 ) ;
V_9 -> V_6 [ 0 ] . V_151 = V_142 -> V_152 ;
V_9 -> V_6 [ 0 ] . V_4 = F_60 ( V_9 -> V_6 [ 0 ] . V_151 , 0x40 ) ;
V_9 -> V_6 [ 0 ] . V_153 = V_154 ;
V_9 -> V_6 [ 0 ] . V_48 = F_61 ( V_140 , 0 ) ;
V_9 -> V_6 [ 0 ] . V_140 = & V_140 -> V_140 ;
F_55 ( V_9 , 0 , V_143 [ 0 ] ) ;
V_128 = & V_9 -> V_6 [ 0 ] ;
V_9 -> V_6 [ 1 ] . line = 1 ;
V_9 -> V_6 [ 1 ] . V_149 = & V_150 ;
V_9 -> V_6 [ 1 ] . type = V_133 ;
V_9 -> V_6 [ 1 ] . V_119 = ( 29491200 / 16 ) ;
V_9 -> V_6 [ 1 ] . V_151 = V_9 -> V_6 [ 0 ] . V_151 ;
V_9 -> V_6 [ 1 ] . V_4 = V_9 -> V_6 [ 0 ] . V_4 ;
V_9 -> V_6 [ 1 ] . V_153 = V_154 ;
V_9 -> V_6 [ 1 ] . V_48 = V_9 -> V_6 [ 0 ] . V_48 ;
V_9 -> V_6 [ 1 ] . V_140 = & V_140 -> V_140 ;
F_55 ( V_9 , 1 , V_143 [ 1 ] ) ;
V_144 = F_62 ( & V_155 ) ;
if ( V_144 )
goto V_156;
V_155 . V_157 -> V_158 = V_155 . V_159 ;
V_144 = F_63 ( & V_155 , & V_9 -> V_6 [ 0 ] ) ;
if ( V_144 )
goto V_160;
V_144 = F_63 ( & V_155 , & V_9 -> V_6 [ 1 ] ) ;
if ( V_144 )
goto V_161;
V_144 = F_64 ( V_9 -> V_6 [ 0 ] . V_48 , F_21 , 0 , L_3 , V_9 ) ;
if ( V_144 )
goto V_162;
F_65 ( V_140 , V_9 ) ;
return 0 ;
V_162:
F_66 ( & V_155 , & V_9 -> V_6 [ 1 ] ) ;
V_161:
F_66 ( & V_155 , & V_9 -> V_6 [ 0 ] ) ;
V_160:
F_67 ( & V_155 ) ;
V_156:
F_68 ( V_9 ) ;
V_128 = NULL ;
return V_144 ;
}
static int T_4 F_69 ( struct V_139 * V_140 )
{
struct V_8 * V_9 = F_70 ( V_140 ) ;
F_71 ( V_9 -> V_6 [ 0 ] . V_48 , V_9 ) ;
F_66 ( & V_155 , & V_9 -> V_6 [ 0 ] ) ;
F_66 ( & V_155 , & V_9 -> V_6 [ 1 ] ) ;
F_67 ( & V_155 ) ;
F_68 ( V_9 ) ;
V_128 = NULL ;
return 0 ;
}
