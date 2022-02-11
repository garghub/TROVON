static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 ) ;
F_4 ( V_4 ) ;
}
static inline int F_5 ( int V_6 )
{
int V_7 , V_8 ;
V_7 = V_9 / V_6 ;
V_8 = V_9 % V_6 ;
if ( ( ( V_8 * 2 ) >= V_6 ) && ( V_6 != 110 ) )
V_7 ++ ;
return V_7 ;
}
static inline int F_6 ( struct V_10 * V_11 ,
unsigned char V_12 ,
T_1 V_6 , T_1 V_13 )
{
int V_7 = F_5 ( V_6 ) ;
T_1 V_14 = ( ( T_1 ) ( V_13 << 8 ) | ( T_1 ) ( V_12 ) ) ;
return F_7 ( V_11 , F_8 ( V_11 , 0 ) ,
V_15 , 0x40 ,
V_7 , V_14 , NULL , 0 , V_16 ) ;
}
static inline int F_9 ( struct V_10 * V_11 ,
T_2 V_17 , T_1 V_18 , T_1 V_14 )
{
return F_7 ( V_11 , F_8 ( V_11 , 0 ) ,
V_17 , 0x40 , V_18 , V_14 ,
NULL , 0 , V_16 ) ;
}
static inline int F_10 ( struct V_10 * V_11 , T_2 * V_18 )
{
T_1 V_19 = ( ( T_1 ) ( V_18 [ 1 ] << 8 ) | ( T_1 ) ( V_18 [ 0 ] ) ) ;
return F_9 ( V_11 , V_20 , V_19 , 0 ) ;
}
static inline int F_11 ( struct V_10 * V_11 , T_2 * V_18 )
{
return F_7 ( V_11 , F_12 ( V_11 , 0 ) ,
V_20 , 0xc0 , 0 , 0 ,
V_18 , 3 , V_16 ) ;
}
static inline int F_13 ( struct V_10 * V_11 ,
T_2 V_21 ,
T_2 V_22 ,
T_2 * V_18 )
{
return F_7 ( V_11 , F_12 ( V_11 , 0 ) ,
V_23 , 0xc0 , V_22 ,
V_21 , V_18 , sizeof( * V_18 ) , V_16 ) ;
}
static inline int F_14 ( struct V_10 * V_11 ,
T_2 V_21 , T_2 V_22 , T_1 V_18 )
{
T_1 V_24 = ( V_18 << 8 ) | V_22 ;
return F_7 ( V_11 , F_8 ( V_11 , 0 ) ,
V_23 , 0x40 , V_24 , V_21 ,
NULL , 0 , V_16 ) ;
}
static inline int F_15 ( struct V_25 * V_26 ,
unsigned int V_27 , unsigned int V_28 )
{
struct V_29 * V_30 = V_26 -> V_30 ;
struct V_10 * V_11 = V_30 -> V_2 -> V_11 ;
unsigned V_31 ;
int V_32 ;
if ( ( ( V_27 | V_28 ) & ( V_33 | V_34 ) ) == 0 ) {
F_16 ( & V_30 -> V_11 ,
L_1 ) ;
return 0 ;
}
V_28 &= ~ V_27 ;
V_31 = 0 ;
if ( V_27 & V_33 )
V_31 |= V_35 ;
if ( V_27 & V_34 )
V_31 |= V_36 ;
V_32 = F_14 ( V_11 , V_26 -> V_37 , V_38 ,
V_31 ) ;
if ( V_32 < 0 )
F_17 ( & V_30 -> V_11 ,
L_2 ,
V_32 ) ;
return V_32 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_39 V_40 ;
int V_41 ;
for ( V_41 = 0 ; V_40 = V_42 [ V_41 ] , V_40 . V_43 != 0 ; V_41 ++ ) {
if ( V_40 . V_43 == F_19 ( V_2 -> V_11 -> V_44 . V_45 ) )
return V_40 . V_46 ;
}
F_17 ( & V_2 -> V_11 -> V_11 ,
L_3 ) ;
return 1 ;
}
static void F_20 ( struct V_47 * V_48 ,
struct V_29 * V_30 ,
struct V_49 * V_50 )
{
struct V_10 * V_11 = V_30 -> V_2 -> V_11 ;
struct V_25 * V_26 ;
struct V_49 * V_51 = & V_48 -> V_51 ;
T_1 V_52 ;
unsigned int V_53 = V_51 -> V_54 ;
T_1 V_55 = 0 ;
int V_32 ;
V_26 = F_21 ( V_30 ) ;
if ( V_53 & V_56 ) {
if ( V_53 & V_57 )
V_55 |= V_58 ;
else
V_55 |= V_59 ;
}
switch ( V_53 & V_60 ) {
case V_61 :
V_55 |= V_62 ;
break;
case V_63 :
V_55 |= V_64 ;
break;
case V_65 :
V_55 |= V_66 ;
break;
default:
case V_67 :
V_55 |= V_68 ;
break;
}
V_52 = F_22 ( V_48 ) ;
if ( ! V_52 )
V_52 = 9600 ;
V_32 = F_6 ( V_11 , V_26 -> V_37 , V_52 ,
V_55 ) ;
if ( V_32 < 0 )
F_17 ( & V_30 -> V_11 , L_4 ,
V_69 , V_32 ) ;
if ( V_53 & V_70 )
V_32 = F_9 ( V_11 , V_71 ,
V_72 ,
V_26 -> V_37 ) ;
else
V_32 = F_9 ( V_11 , V_71 ,
0 , V_26 -> V_37 ) ;
if ( V_32 < 0 )
F_17 ( & V_30 -> V_11 , L_5 ,
V_69 , V_32 ) ;
if ( F_23 ( V_48 ) || F_24 ( V_48 ) ) {
T_1 V_19 = ( ( T_1 ) ( F_25 ( V_48 ) << 8 ) | ( T_1 ) ( F_26 ( V_48 ) ) ) ;
V_32 = F_9 ( V_11 , V_73 ,
V_19 , V_26 -> V_37 ) ;
} else
V_32 = F_9 ( V_11 , V_73 ,
0 , V_26 -> V_37 ) ;
if ( V_32 < 0 )
F_17 ( & V_30 -> V_11 , L_6 ,
V_69 , V_32 ) ;
}
static int F_27 ( struct V_47 * V_48 , struct V_29 * V_30 )
{
struct V_1 * V_2 ;
struct V_25 * V_26 ;
T_2 * V_18 ;
T_1 V_37 ;
int V_32 ;
unsigned long V_74 ;
V_37 = ( T_1 ) ( V_30 -> V_75 - V_30 -> V_2 -> V_76 ) ;
V_2 = V_30 -> V_2 ;
V_26 = F_21 ( V_30 ) ;
V_32 = F_9 ( V_2 -> V_11 , V_77 ,
V_78 , V_37 ) ;
if ( V_32 < 0 ) {
F_17 ( & V_30 -> V_11 ,
L_7 ,
V_69 , V_37 , V_32 ) ;
return V_32 ;
}
V_18 = F_28 ( 2 , V_79 ) ;
if ( ! V_18 )
return - V_80 ;
V_32 = F_7 ( V_2 -> V_11 ,
F_12 ( V_2 -> V_11 , 0 ) ,
V_81 ,
0xc0 , 0 ,
V_37 , V_18 , 2 , V_16 ) ;
if ( V_32 < 0 ) {
F_17 ( & V_30 -> V_11 , L_8 , V_69 ,
V_32 ) ;
F_4 ( V_18 ) ;
return V_32 ;
}
F_29 ( & V_26 -> V_82 , V_74 ) ;
V_26 -> V_83 = V_18 [ 0 ] ;
V_26 -> V_84 = V_18 [ 1 ] ;
F_30 ( & V_26 -> V_82 , V_74 ) ;
F_4 ( V_18 ) ;
V_32 = F_6 ( V_2 -> V_11 , V_37 ,
V_85 , V_68 ) ;
if ( V_32 < 0 ) {
F_17 ( & V_30 -> V_11 ,
L_9 ,
V_69 , V_30 -> V_75 , V_37 ) ;
return V_32 ;
}
V_26 -> V_86 = true ;
V_26 -> V_37 = ( T_2 ) V_37 ;
if ( V_48 )
F_20 ( V_48 , V_30 , & V_48 -> V_51 ) ;
return 0 ;
}
static void F_31 ( struct V_29 * V_30 )
{
struct V_1 * V_2 ;
struct V_25 * V_26 ;
unsigned long V_74 ;
int V_41 ;
V_2 = V_30 -> V_2 ;
V_26 = F_21 ( V_30 ) ;
V_26 -> V_86 = false ;
F_29 ( & V_26 -> V_87 , V_74 ) ;
F_32 ( V_26 -> V_88 ) ;
V_26 -> V_89 = false ;
F_30 ( & V_26 -> V_87 , V_74 ) ;
F_33 ( & V_30 -> V_2 -> V_90 ) ;
if ( V_30 -> V_2 -> V_91 ) {
F_34 ( & V_30 -> V_2 -> V_90 ) ;
return;
}
V_41 = F_7 ( V_2 -> V_11 ,
F_12 ( V_2 -> V_11 , 0 ) ,
V_92 , 0x40 , 1 ,
V_26 -> V_37 , NULL , 0 , V_16 ) ;
if ( V_41 < 0 )
F_17 ( & V_30 -> V_11 , L_10 ,
V_69 , V_41 ) ;
V_41 = F_7 ( V_2 -> V_11 ,
F_12 ( V_2 -> V_11 , 0 ) ,
V_92 , 0x40 , 0 ,
V_26 -> V_37 , NULL , 0 , V_16 ) ;
if ( V_41 < 0 )
F_17 ( & V_30 -> V_11 , L_11 ,
V_69 , V_41 ) ;
V_41 = F_7 ( V_2 -> V_11 ,
F_8 ( V_2 -> V_11 , 0 ) ,
V_81 ,
0x40 , 0 ,
V_26 -> V_37 , NULL , 0 , V_16 ) ;
if ( V_41 < 0 )
F_17 ( & V_30 -> V_11 , L_12 ,
V_69 , V_41 ) ;
F_34 ( & V_30 -> V_2 -> V_90 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_32 ( V_4 -> V_5 ) ;
}
static int F_36 ( struct V_29 * V_30 ,
struct V_93 T_3 * V_94 )
{
struct V_93 V_95 ;
if ( ! V_94 )
return - V_96 ;
memset ( & V_95 , 0 , sizeof( V_95 ) ) ;
V_95 . line = V_30 -> V_2 -> V_76 ;
V_95 . V_30 = 0 ;
V_95 . V_97 = 0 ;
V_95 . V_74 = V_98 | V_99 ;
V_95 . V_100 = V_30 -> V_101 ;
V_95 . V_102 = 9600 ;
V_95 . V_103 = 5 * V_104 ;
V_95 . V_105 = 30 * V_104 ;
if ( F_37 ( V_94 , & V_95 , sizeof( * V_94 ) ) )
return - V_96 ;
return 0 ;
}
static int F_38 ( struct V_29 * V_30 , unsigned int V_106 )
{
struct V_25 * V_107 = F_21 ( V_30 ) ;
struct V_108 V_109 , V_110 ;
unsigned long V_74 ;
F_29 ( & V_107 -> V_82 , V_74 ) ;
V_109 = V_107 -> V_111 ;
F_30 ( & V_107 -> V_82 , V_74 ) ;
while ( 1 ) {
F_39 ( V_107 -> V_112 ,
( ( V_107 -> V_111 . V_113 != V_109 . V_113 ) ||
( V_107 -> V_111 . V_114 != V_109 . V_114 ) ||
( V_107 -> V_111 . V_115 != V_109 . V_115 ) ||
( V_107 -> V_111 . V_116 != V_109 . V_116 ) ) ) ;
if ( F_40 ( V_117 ) )
return - V_118 ;
F_29 ( & V_107 -> V_82 , V_74 ) ;
V_110 = V_107 -> V_111 ;
F_30 ( & V_107 -> V_82 , V_74 ) ;
if ( ( V_109 . V_113 == V_110 . V_113 ) &&
( V_109 . V_114 == V_110 . V_114 ) &&
( V_109 . V_115 == V_110 . V_115 ) &&
( V_109 . V_116 == V_110 . V_116 ) )
return - V_119 ;
if ( ( V_106 & V_120 && ( V_109 . V_113 != V_110 . V_113 ) ) ||
( V_106 & V_121 && ( V_109 . V_114 != V_110 . V_114 ) ) ||
( V_106 & V_122 && ( V_109 . V_115 != V_110 . V_115 ) ) ||
( V_106 & V_123 && ( V_109 . V_116 != V_110 . V_116 ) ) )
return 0 ;
}
return 0 ;
}
static int F_41 ( struct V_47 * V_48 ,
struct V_124 * V_111 )
{
struct V_29 * V_30 = V_48 -> V_125 ;
struct V_25 * V_107 = F_21 ( V_30 ) ;
struct V_108 V_126 = V_107 -> V_111 ;
V_111 -> V_116 = V_126 . V_116 ;
V_111 -> V_114 = V_126 . V_114 ;
V_111 -> V_113 = V_126 . V_113 ;
V_111 -> V_115 = V_126 . V_115 ;
V_111 -> V_127 = V_126 . V_127 ;
V_111 -> V_128 = V_126 . V_128 ;
V_111 -> V_129 = V_126 . V_129 ;
V_111 -> V_130 = V_126 . V_130 ;
V_111 -> V_131 = V_126 . V_131 ;
V_111 -> V_132 = V_126 . V_132 ;
V_111 -> V_133 = V_126 . V_133 ;
return 0 ;
}
static int F_42 ( struct V_47 * V_48 ,
unsigned int V_134 , unsigned long V_106 )
{
struct V_29 * V_30 = V_48 -> V_125 ;
switch ( V_134 ) {
case V_135 :
return F_36 ( V_30 ,
(struct V_93 T_3 * ) V_106 ) ;
case V_136 :
return F_38 ( V_30 , V_106 ) ;
default:
break;
}
return - V_137 ;
}
static void F_43 ( struct V_29 * V_30 , unsigned char * V_138 )
{
switch ( * V_138 ) {
case V_139 :
F_44 ( V_30 , V_138 + 1 ) ;
break;
case V_140 :
F_45 ( V_30 , V_138 + 1 ) ;
break;
}
}
static void F_46 ( struct V_29 * V_30 ,
unsigned char * V_138 )
{
int V_141 ;
V_141 = ( int ) ( * V_138 ) + ( int ) ( * ( V_138 + 1 ) << 4 ) ;
}
static void F_47 ( struct V_29 * V_30 , unsigned char * V_138 )
{
return;
}
void F_48 ( struct V_142 * V_142 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_29 * V_30 ;
struct V_25 * V_26 ;
struct V_47 * V_48 ;
bool V_143 ;
unsigned char * V_138 ;
int V_41 ;
unsigned char V_144 ;
int V_145 = V_142 -> V_146 ;
if ( ! V_145 )
return;
V_138 = V_142 -> V_147 ;
V_48 = NULL ;
V_2 = V_142 -> V_148 ;
V_4 = F_2 ( V_2 ) ;
V_30 = V_2 -> V_30 [ V_4 -> V_149 ] ;
V_26 = F_21 ( V_30 ) ;
if ( V_26 -> V_86 )
V_48 = F_49 ( & V_30 -> V_30 ) ;
for ( V_41 = 0 ; V_41 < V_142 -> V_146 ; V_41 ++ ) {
V_138 = ( unsigned char * ) V_142 -> V_147 + V_41 ;
if ( ( V_41 <= ( V_145 - 3 ) ) &&
( * V_138 == V_150 ) &&
( * ( V_138 + 1 ) == V_150 ) ) {
V_143 = false ;
switch ( * ( V_138 + 2 ) ) {
case V_139 :
case V_140 :
if ( V_41 > ( V_145 - 4 ) ) {
F_50 ( & V_30 -> V_11 ,
L_13 ,
V_69 ) ;
break;
}
F_43 ( V_30 , V_138 + 2 ) ;
V_41 += 3 ;
V_143 = true ;
break;
case V_151 :
if ( V_41 > ( V_145 - 5 ) ) {
F_50 ( & V_30 -> V_11 ,
L_14 ,
V_69 ) ;
break;
}
F_46 ( V_30 , V_138 + 3 ) ;
V_41 += 4 ;
V_143 = true ;
break;
case V_152 :
if ( V_41 > ( V_145 - 4 ) ) {
F_50 ( & V_30 -> V_11 ,
L_15 ,
V_69 ) ;
break;
}
if ( V_48 ) {
F_51 ( V_48 ) ;
F_52 ( V_48 ) ;
}
V_144 = * ( V_138 + 3 ) ;
if ( V_144 > V_2 -> V_46 ) {
F_17 ( & V_30 -> V_11 ,
L_16 ,
V_69 , V_144 ) ;
break;
}
V_4 -> V_149 = V_144 ;
V_30 = V_2 -> V_30 [ V_4 -> V_149 ] ;
V_26 = F_21 ( V_30 ) ;
if ( V_26 -> V_86 )
V_48 = F_49 ( & V_30 -> V_30 ) ;
else
V_48 = NULL ;
V_41 += 3 ;
V_143 = true ;
break;
case V_153 :
case V_154 :
F_47 ( V_30 , V_138 + 2 ) ;
V_41 += 2 ;
V_143 = true ;
break;
case V_155 :
F_53 ( V_48 , 2 ) ;
F_54 ( V_48 , V_138 , 2 ) ;
V_41 += 2 ;
V_143 = true ;
break;
default:
F_50 ( & V_30 -> V_11 ,
L_17 ,
V_69 , * ( V_138 + 2 ) ) ;
break;
}
if ( V_143 )
continue;
}
if ( V_48 ) {
F_53 ( V_48 , 1 ) ;
F_54 ( V_48 , V_138 , 1 ) ;
}
}
if ( V_48 ) {
F_51 ( V_48 ) ;
F_52 ( V_48 ) ;
}
}
static void F_55 ( struct V_142 * V_142 )
{
struct V_29 * V_30 ;
struct V_25 * V_26 ;
V_30 = V_142 -> V_148 ;
V_26 = F_21 ( V_30 ) ;
F_56 ( & V_26 -> V_87 ) ;
V_26 -> V_89 = false ;
F_57 ( V_30 ) ;
F_58 ( & V_26 -> V_87 ) ;
}
static void F_59 ( struct V_142 * V_142 )
{
struct V_1 * V_2 = V_142 -> V_148 ;
int V_32 ;
if ( V_142 -> V_32 ) {
F_50 ( & V_2 -> V_11 -> V_11 ,
L_18 , V_69 ,
V_142 -> V_32 ) ;
return;
}
F_48 ( V_142 ) ;
V_32 = F_60 ( V_142 , V_156 ) ;
if ( V_32 != 0 )
F_17 ( & V_2 -> V_11 -> V_11 ,
L_19 ,
V_69 , V_32 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_29 * V_157 ;
struct V_3 * V_4 ;
int V_32 ;
V_157 = V_2 -> V_30 [ 0 ] ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 = F_62 ( 0 , V_79 ) ;
if ( ! V_4 -> V_5 ) {
F_17 ( & V_2 -> V_11 -> V_11 , L_20 ) ;
return - V_80 ;
}
F_63 ( V_4 -> V_5 , V_2 -> V_11 ,
F_64 ( V_2 -> V_11 ,
V_157 -> V_158 ) ,
V_4 -> V_159 ,
sizeof( V_4 -> V_159 ) ,
F_59 , V_2 ) ;
V_32 = F_60 ( V_4 -> V_5 , V_79 ) ;
if ( V_32 != 0 ) {
F_17 ( & V_2 -> V_11 -> V_11 ,
L_21 , V_69 , V_32 ) ;
F_3 ( V_4 -> V_5 ) ;
return V_32 ;
}
return 0 ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_32 ;
V_32 = F_7 ( V_2 -> V_11 , F_12 ( V_2 -> V_11 , 0 ) ,
0xc2 , 0x40 , 0x8000 , 0 , NULL , 0 ,
V_16 ) ;
if ( V_32 < 0 ) {
F_17 ( & V_2 -> V_11 -> V_11 ,
L_22 , V_69 , V_32 ) ;
return V_32 ;
}
V_4 = F_28 ( sizeof( * V_4 ) , V_79 ) ;
if ( ! V_4 ) {
F_17 ( & V_2 -> V_11 -> V_11 , L_23 , V_69 ) ;
return - V_80 ;
}
F_66 ( V_2 , V_4 ) ;
V_32 = F_61 ( V_2 ) ;
if ( V_32 != 0 )
goto V_160;
return 0 ;
V_160:
F_4 ( V_4 ) ;
return V_32 ;
}
static int F_67 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_25 * V_26 ;
T_2 V_161 ;
V_26 = F_28 ( sizeof( * V_26 ) , V_79 ) ;
if ( ! V_26 )
return - V_80 ;
F_68 ( & V_26 -> V_82 ) ;
F_68 ( & V_26 -> V_87 ) ;
F_69 ( & V_26 -> V_112 ) ;
V_26 -> V_30 = V_30 ;
V_26 -> V_88 = F_62 ( 0 , V_79 ) ;
if ( ! V_26 -> V_88 ) {
F_4 ( V_26 ) ;
return - V_80 ;
}
V_161 = V_2 -> V_30 [ 0 ] -> V_162 ;
F_63 ( V_26 -> V_88 , V_2 -> V_11 ,
F_70 ( V_2 -> V_11 , V_161 ) ,
V_26 -> V_163 ,
sizeof( V_26 -> V_163 ) ,
F_55 , V_30 ) ;
F_71 ( V_30 , V_26 ) ;
return 0 ;
}
static int F_72 ( struct V_29 * V_30 )
{
struct V_25 * V_26 ;
V_26 = F_21 ( V_30 ) ;
F_3 ( V_26 -> V_88 ) ;
F_4 ( V_26 ) ;
return 0 ;
}
static int F_73 ( struct V_47 * V_48 )
{
struct V_29 * V_30 = V_48 -> V_125 ;
struct V_10 * V_11 = V_30 -> V_2 -> V_11 ;
struct V_25 * V_26 = F_21 ( V_30 ) ;
T_2 * V_40 ;
int V_164 ;
V_40 = F_28 ( 2 , V_79 ) ;
if ( ! V_40 )
return - V_80 ;
V_164 = F_13 ( V_11 , V_26 -> V_37 , V_38 , V_40 ) ;
if ( V_164 < 0 )
goto V_165;
V_164 = F_13 ( V_11 , V_26 -> V_37 , V_166 , V_40 + 1 ) ;
if ( V_164 < 0 )
goto V_165;
V_164 = ( V_40 [ 0 ] & V_35 ? V_33 : 0 ) |
( V_40 [ 0 ] & V_36 ? V_34 : 0 ) |
( V_40 [ 1 ] & V_167 ? V_123 : 0 ) |
( V_40 [ 1 ] & V_168 ? V_169 : 0 ) |
( V_40 [ 1 ] & V_170 ? V_171 : 0 ) |
( V_40 [ 1 ] & V_172 ? V_121 : 0 ) ;
V_165:
F_4 ( V_40 ) ;
return V_164 ;
}
static int F_74 ( struct V_47 * V_48 ,
unsigned int V_27 , unsigned int V_28 )
{
struct V_25 * V_26 ;
V_26 = F_21 ( V_48 -> V_125 ) ;
return F_15 ( V_26 , V_27 , V_28 ) ;
}
static void F_75 ( struct V_47 * V_48 , int V_173 )
{
struct V_29 * V_30 = V_48 -> V_125 ;
struct V_25 * V_26 ;
int V_32 ;
T_1 V_174 ;
V_26 = F_21 ( V_30 ) ;
if ( ! V_26 -> V_86 ) {
F_17 ( & V_30 -> V_11 ,
L_24 , V_69 ) ;
return;
}
V_174 = ( V_173 == - 1 ) ? 1 : 0 ;
V_32 = F_9 ( V_30 -> V_2 -> V_11 , V_175 ,
V_174 , V_26 -> V_37 ) ;
if ( V_32 < 0 )
F_50 ( & V_30 -> V_11 ,
L_25 , V_69 ,
V_32 ) ;
}
static void F_76 ( struct V_29 * V_30 , int V_176 )
{
struct V_10 * V_11 = V_30 -> V_2 -> V_11 ;
struct V_25 * V_26 = F_21 ( V_30 ) ;
F_33 ( & V_30 -> V_2 -> V_90 ) ;
if ( ! V_30 -> V_2 -> V_91 ) {
if ( ! V_176 && F_14 ( V_11 , V_26 -> V_37 ,
V_38 , 0 ) < 0 )
F_50 ( & V_30 -> V_11 , L_26 ) ;
if ( V_176 )
F_15 ( V_26 , V_33 | V_34 , 0 ) ;
else
F_15 ( V_26 , 0 , V_33 | V_34 ) ;
}
F_34 ( & V_30 -> V_2 -> V_90 ) ;
}
static void F_45 ( struct V_29 * V_30 , unsigned char * V_138 )
{
struct V_25 * V_26 ;
T_2 V_177 = ( T_2 ) * V_138 ;
unsigned long V_74 ;
V_26 = F_21 ( V_30 ) ;
F_29 ( & V_26 -> V_82 , V_74 ) ;
V_26 -> V_84 = V_177 ;
F_30 ( & V_26 -> V_82 , V_74 ) ;
if ( V_177 & V_178 ) {
if ( V_177 & V_179 )
V_26 -> V_111 . V_116 ++ ;
if ( V_177 & V_180 )
V_26 -> V_111 . V_114 ++ ;
if ( V_177 & V_181 )
V_26 -> V_111 . V_115 ++ ;
if ( V_177 & V_182 )
V_26 -> V_111 . V_113 ++ ;
F_77 ( & V_26 -> V_112 ) ;
}
}
static void F_44 ( struct V_29 * V_30 , unsigned char * V_138 )
{
struct V_25 * V_26 ;
struct V_108 * V_111 ;
unsigned long V_74 ;
T_2 V_183 = ( T_2 ) * V_138 ;
V_26 = F_21 ( V_30 ) ;
if ( V_183 & V_184 )
V_183 &= ( T_2 ) ( V_185 | V_184 ) ;
F_29 ( & V_26 -> V_82 , V_74 ) ;
V_26 -> V_83 = V_183 ;
F_30 ( & V_26 -> V_82 , V_74 ) ;
V_111 = & V_26 -> V_111 ;
if ( V_183 & V_186 ) {
if ( V_183 & V_184 )
V_111 -> V_132 ++ ;
if ( V_183 & V_185 )
V_111 -> V_130 ++ ;
if ( V_183 & V_187 )
V_111 -> V_131 ++ ;
if ( V_183 & V_188 )
V_111 -> V_129 ++ ;
}
}
static int F_78 ( struct V_47 * V_48 )
{
struct V_29 * V_30 = V_48 -> V_125 ;
struct V_25 * V_26 ;
unsigned long V_74 = 0 ;
int V_164 ;
V_26 = F_21 ( V_30 ) ;
F_29 ( & V_26 -> V_87 , V_74 ) ;
if ( V_26 -> V_89 )
V_164 = 0 ;
else
V_164 = V_189 - V_190 ;
F_30 ( & V_26 -> V_87 , V_74 ) ;
return V_164 ;
}
static int F_79 ( struct V_47 * V_48 ,
struct V_29 * V_30 ,
const unsigned char * V_191 , int V_192 )
{
struct V_25 * V_26 ;
struct V_142 * V_88 ;
unsigned char * V_18 ;
unsigned long V_74 ;
int V_32 ;
int V_193 = 0 ;
V_26 = F_21 ( V_30 ) ;
if ( V_26 -> V_88 == NULL ) {
F_17 ( & V_30 -> V_11 , L_27 , V_69 ) ;
return 0 ;
}
V_88 = V_26 -> V_88 ;
V_192 = F_80 ( V_192 , V_189 - V_190 ) ;
V_18 = V_88 -> V_147 ;
F_29 ( & V_26 -> V_87 , V_74 ) ;
if ( V_26 -> V_89 == true ) {
F_17 ( & V_30 -> V_11 , L_28 ) ;
goto V_194;
}
* V_18 ++ = V_150 ;
* V_18 ++ = V_150 ;
* V_18 ++ = V_26 -> V_37 ;
F_81 ( V_192 , V_18 ) ;
V_18 += 2 ;
memcpy ( V_18 , V_191 , V_192 ) ;
V_88 -> V_195 = V_192 + V_190 ;
V_32 = F_60 ( V_88 , V_156 ) ;
if ( V_32 == 0 ) {
V_26 -> V_89 = true ;
V_193 += V_192 ;
}
V_194:
F_30 ( & V_26 -> V_87 , V_74 ) ;
return V_193 ;
}
