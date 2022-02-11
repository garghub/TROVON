static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( * V_2 -> V_5 ) ;
F_3 ( V_4 ) ;
}
static inline int F_4 ( struct V_6 * V_7 ,
T_1 V_8 , T_2 V_9 , T_2 V_10 )
{
return F_5 ( V_7 , F_6 ( V_7 , 0 ) ,
V_8 , 0x40 , V_9 , V_10 ,
NULL , 0 , 300 ) ;
}
static inline int F_7 ( struct V_6 * V_7 , T_1 * V_9 )
{
T_2 V_11 = ( ( T_2 ) ( V_9 [ 1 ] << 8 ) | ( T_2 ) ( V_9 [ 0 ] ) ) ;
return F_4 ( V_7 , V_12 , V_11 , 0 ) ;
}
static inline int F_8 ( struct V_6 * V_7 , T_1 * V_9 )
{
return F_5 ( V_7 , F_9 ( V_7 , 0 ) ,
V_12 , 0xc0 , 0 , 0 ,
V_9 , 3 , 300 ) ;
}
static inline int F_10 ( struct V_6 * V_7 ,
unsigned short V_13 ,
unsigned short V_14 ,
T_1 * V_9 )
{
return F_5 ( V_7 , F_9 ( V_7 , 0 ) ,
V_15 , 0xc0 , V_14 ,
V_13 , V_9 , sizeof( * V_9 ) , 300 ) ;
}
static inline int F_11 ( struct V_6 * V_7 ,
unsigned short V_13 ,
unsigned short V_14 ,
T_2 V_9 )
{
T_2 V_16 = ( V_9 << 8 ) | V_14 ;
return F_5 ( V_7 , F_6 ( V_7 , 0 ) ,
V_15 , 0x40 , V_16 , V_13 ,
NULL , 0 , 300 ) ;
}
static inline int F_12 ( struct V_6 * V_7 , unsigned int V_17 ,
unsigned int V_18 )
{
unsigned V_19 ;
int V_20 ;
if ( ( ( V_17 | V_18 ) & ( V_21 | V_22 ) ) == 0 ) {
F_13 ( L_1 , V_23 ) ;
return 0 ;
}
V_18 &= ~ V_17 ;
V_19 = 0 ;
if ( V_17 & V_21 )
V_19 |= V_24 ;
if ( V_17 & V_22 )
V_19 |= V_25 ;
V_20 = F_11 ( V_7 , 0 , V_26 , V_19 ) ;
if ( V_20 < 0 )
F_13 ( L_2 , V_23 ) ;
return V_20 ;
}
static int F_14 ( struct V_6 * V_7 )
{
T_1 * V_9 ;
int V_20 = 0 ;
V_9 = F_15 ( 3 , V_27 ) ;
if ( ! V_9 )
return - V_28 ;
V_20 = F_8 ( V_7 , V_9 ) ;
if ( V_20 < 0 ) {
F_13 ( L_3 , V_23 , V_20 ) ;
goto V_29;
}
V_9 [ 1 ] &= ~ V_30 ;
V_20 = F_7 ( V_7 , V_9 ) ;
if ( V_20 < 0 ) {
F_13 ( L_4 , V_23 , V_20 ) ;
goto V_29;
}
V_20 = F_4 ( V_7 , V_31 , 128 , 0 ) ;
if ( V_20 < 0 ) {
F_13 ( L_5 , V_23 , V_20 ) ;
goto V_29;
}
V_20 = F_4 ( V_7 , V_32 , V_33 , 0 ) ;
if ( V_20 < 0 ) {
F_13 ( L_6 , V_23 , V_20 ) ;
goto V_29;
}
V_20 = F_8 ( V_7 , V_9 ) ;
if ( V_20 < 0 ) {
F_13 ( L_3 , V_23 , V_20 ) ;
goto V_29;
}
V_9 [ 0 ] &= ~ ( V_34 | V_35 ) ;
V_9 [ 0 ] |= V_36 ;
V_9 [ 1 ] &= ~ ( V_37 ) ;
V_9 [ 1 ] |= V_38 ;
V_20 = F_7 ( V_7 , V_9 ) ;
if ( V_20 < 0 ) {
F_13 ( L_4 , V_23 , V_20 ) ;
goto V_29;
}
V_29: F_3 ( V_9 ) ;
return V_20 ;
}
static void F_16 ( struct V_39 * V_40 ,
struct V_41 * V_5 ,
struct V_42 * V_43 )
{
struct V_6 * V_7 = V_5 -> V_2 -> V_7 ;
struct V_42 * V_44 = V_40 -> V_44 ;
T_2 V_45 , V_46 , V_47 ;
unsigned int V_48 = V_44 -> V_49 ;
T_2 V_19 = 0 ;
int V_20 ;
if ( V_48 & V_50 ) {
if ( V_48 & V_51 )
V_19 |= V_52 ;
else
V_19 |= V_53 ;
}
switch ( V_48 & V_54 ) {
case V_55 :
V_19 |= V_56 ;
break;
case V_57 :
V_19 |= V_58 ;
break;
case V_59 :
V_19 |= V_60 ;
break;
default:
case V_61 :
V_19 |= V_62 ;
break;
}
V_45 = F_17 ( V_40 ) ;
if ( ! V_45 )
V_45 = 9600 ;
F_13 ( L_7 , V_23 , V_45 ) ;
V_46 = V_63 / V_45 ;
V_47 = V_63 % V_45 ;
if ( ( ( V_47 * 2 ) >= V_45 ) && ( V_45 != 110 ) )
V_46 ++ ;
V_19 = V_19 << 8 ;
V_20 = F_4 ( V_7 , V_64 , V_46 , V_19 ) ;
if ( V_20 < 0 )
F_13 ( L_8 , V_23 ) ;
if ( V_48 & V_65 )
V_20 = F_4 ( V_7 , V_66 ,
V_67 , 0 ) ;
else
V_20 = F_4 ( V_7 , V_66 ,
0 , 0 ) ;
if ( V_20 < 0 )
F_13 ( L_9 , V_23 ) ;
if ( F_18 ( V_40 ) || F_19 ( V_40 ) ) {
T_2 V_11 = ( ( T_2 ) ( F_20 ( V_40 ) << 8 ) | ( T_2 ) ( F_21 ( V_40 ) ) ) ;
V_20 = F_4 ( V_7 , V_68 ,
V_11 , 0 ) ;
} else
V_20 = F_4 ( V_7 , V_68 ,
0 , 0 ) ;
if ( V_20 < 0 )
F_13 ( L_10 , V_23 ) ;
}
static int F_22 ( struct V_39 * V_40 , struct V_41 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_2 -> V_7 ;
struct V_3 * V_4 = F_2 ( V_5 ) ;
T_1 * V_9 ;
int V_20 ;
unsigned long V_69 ;
V_9 = F_15 ( 2 , V_27 ) ;
if ( ! V_9 )
return - V_28 ;
V_20 = F_5 ( V_7 , F_9 ( V_7 , 0 ) ,
V_70 ,
V_71 , 0x01 ,
0 , V_9 , 2 , 300 ) ;
if ( V_20 < 0 ) {
F_13 ( L_11 , V_23 , V_20 ) ;
F_3 ( V_9 ) ;
return V_20 ;
}
F_23 ( & V_4 -> V_72 , V_69 ) ;
V_4 -> V_73 = V_9 [ 0 ] ;
V_4 -> V_74 = V_9 [ 1 ] ;
F_24 ( & V_4 -> V_72 , V_69 ) ;
F_3 ( V_9 ) ;
V_20 = F_4 ( V_7 , V_64 , 0x30 , 0x0300 ) ;
if ( V_20 < 0 )
F_13 ( L_8 , V_23 ) ;
if ( V_40 )
F_16 ( V_40 , V_5 , V_40 -> V_44 ) ;
return F_25 ( V_40 , V_5 ) ;
}
static void F_26 ( struct V_41 * V_5 )
{
F_27 ( V_5 ) ;
}
static int F_28 ( struct V_41 * V_5 ,
struct V_75 T_3 * V_76 )
{
struct V_75 V_77 ;
if ( ! V_76 )
return - V_78 ;
memset ( & V_77 , 0 , sizeof( V_77 ) ) ;
V_77 . line = V_5 -> V_2 -> V_79 ;
V_77 . V_5 = 0 ;
V_77 . V_80 = 0 ;
V_77 . V_69 = V_81 | V_82 ;
V_77 . V_83 = V_5 -> V_84 ;
V_77 . V_85 = 9600 ;
V_77 . V_86 = 5 * V_87 ;
V_77 . V_88 = 30 * V_87 ;
if ( F_29 ( V_76 , & V_77 , sizeof( * V_76 ) ) )
return - V_78 ;
return 0 ;
}
static int F_30 ( struct V_41 * V_5 , unsigned int V_89 )
{
struct V_3 * V_4 = F_2 ( V_5 ) ;
struct V_90 V_91 , V_92 ;
unsigned long V_69 ;
F_23 ( & V_4 -> V_72 , V_69 ) ;
V_91 = V_4 -> V_93 ;
F_24 ( & V_4 -> V_72 , V_69 ) ;
while ( 1 ) {
F_31 ( V_4 -> V_94 ,
( ( V_4 -> V_93 . V_95 != V_91 . V_95 ) ||
( V_4 -> V_93 . V_96 != V_91 . V_96 ) ||
( V_4 -> V_93 . V_97 != V_91 . V_97 ) ||
( V_4 -> V_93 . V_98 != V_91 . V_98 ) ) ) ;
if ( F_32 ( V_99 ) )
return - V_100 ;
F_23 ( & V_4 -> V_72 , V_69 ) ;
V_92 = V_4 -> V_93 ;
F_24 ( & V_4 -> V_72 , V_69 ) ;
if ( ( V_91 . V_95 == V_92 . V_95 ) &&
( V_91 . V_96 == V_92 . V_96 ) &&
( V_91 . V_97 == V_92 . V_97 ) &&
( V_91 . V_98 == V_92 . V_98 ) )
return - V_101 ;
if ( ( V_89 & V_102 && ( V_91 . V_95 != V_92 . V_95 ) ) ||
( V_89 & V_103 && ( V_91 . V_96 != V_92 . V_96 ) ) ||
( V_89 & V_104 && ( V_91 . V_97 != V_92 . V_97 ) ) ||
( V_89 & V_105 && ( V_91 . V_98 != V_92 . V_98 ) ) )
return 0 ;
}
return 0 ;
}
static int F_33 ( struct V_39 * V_40 ,
struct V_106 * V_93 )
{
struct V_41 * V_5 = V_40 -> V_107 ;
struct V_3 * V_4 = F_2 ( V_5 ) ;
struct V_90 V_108 = V_4 -> V_93 ;
V_93 -> V_98 = V_108 . V_98 ;
V_93 -> V_96 = V_108 . V_96 ;
V_93 -> V_95 = V_108 . V_95 ;
V_93 -> V_97 = V_108 . V_97 ;
V_93 -> V_109 = V_108 . V_109 ;
V_93 -> V_110 = V_108 . V_110 ;
V_93 -> V_111 = V_108 . V_111 ;
V_93 -> V_112 = V_108 . V_112 ;
V_93 -> V_113 = V_108 . V_113 ;
V_93 -> V_114 = V_108 . V_114 ;
V_93 -> V_115 = V_108 . V_115 ;
return 0 ;
}
static int F_34 ( struct V_39 * V_40 ,
unsigned int V_116 , unsigned long V_89 )
{
struct V_41 * V_5 = V_40 -> V_107 ;
F_13 ( L_12 , V_23 , V_116 ) ;
switch ( V_116 ) {
case V_117 :
return F_28 ( V_5 ,
(struct V_75 T_3 * ) V_89 ) ;
case V_118 :
return F_30 ( V_5 , V_89 ) ;
default:
break;
}
F_13 ( L_13 , V_23 ) ;
return - V_119 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_41 * V_5 = * V_2 -> V_5 ;
V_4 = F_15 ( sizeof( * V_4 ) , V_27 ) ;
if ( ! V_4 ) {
F_36 ( & V_5 -> V_7 , L_14 , V_23 ,
sizeof( * V_4 ) ) ;
return - V_28 ;
}
F_37 ( & V_4 -> V_72 ) ;
F_38 ( & V_4 -> V_94 ) ;
F_39 ( V_5 , V_4 ) ;
return F_14 ( V_2 -> V_7 ) ;
}
static int F_40 ( struct V_39 * V_40 )
{
struct V_41 * V_5 = V_40 -> V_107 ;
struct V_6 * V_7 = V_5 -> V_2 -> V_7 ;
T_1 * V_120 ;
int V_121 ;
V_120 = F_15 ( 2 , V_27 ) ;
if ( ! V_120 )
return - V_28 ;
V_121 = F_10 ( V_7 , 0 , V_26 , V_120 ) ;
if ( V_121 < 0 )
goto V_122;
V_121 = F_10 ( V_7 , 0 , V_123 , V_120 + 1 ) ;
if ( V_121 < 0 )
goto V_122;
V_121 = ( V_120 [ 0 ] & V_24 ? V_21 : 0 ) |
( V_120 [ 0 ] & V_25 ? V_22 : 0 ) |
( V_120 [ 1 ] & V_124 ? V_105 : 0 ) |
( V_120 [ 1 ] & V_125 ? V_126 : 0 ) |
( V_120 [ 1 ] & V_127 ? V_128 : 0 ) |
( V_120 [ 1 ] & V_129 ? V_103 : 0 ) ;
V_122:
F_3 ( V_120 ) ;
return V_121 ;
}
static int F_41 ( struct V_39 * V_40 ,
unsigned int V_17 , unsigned int V_18 )
{
struct V_41 * V_5 = V_40 -> V_107 ;
struct V_6 * V_7 = V_5 -> V_2 -> V_7 ;
return F_12 ( V_7 , V_17 , V_18 ) ;
}
static void F_42 ( struct V_41 * V_5 , int V_130 )
{
struct V_6 * V_7 = V_5 -> V_2 -> V_7 ;
F_43 ( & V_5 -> V_2 -> V_131 ) ;
if ( ! V_5 -> V_2 -> V_132 ) {
if ( ! V_130 &&
F_11 ( V_7 , 0 , V_26 , 0 ) < 0 )
F_36 ( & V_5 -> V_7 , L_15 ) ;
if ( V_130 )
F_44 ( V_7 , V_21 | V_22 ) ;
else
F_45 ( V_7 , V_21 | V_22 ) ;
}
F_46 ( & V_5 -> V_2 -> V_131 ) ;
}
static void F_47 ( struct V_41 * V_5 , T_1 V_133 )
{
struct V_3 * V_4 = F_2 ( V_5 ) ;
unsigned long V_69 ;
F_23 ( & V_4 -> V_72 , V_69 ) ;
V_4 -> V_74 = V_133 ;
F_24 ( & V_4 -> V_72 , V_69 ) ;
if ( V_133 & V_134 ) {
if ( V_133 & V_135 )
V_4 -> V_93 . V_98 ++ ;
if ( V_133 & V_136 )
V_4 -> V_93 . V_96 ++ ;
if ( V_133 & V_137 )
V_4 -> V_93 . V_97 ++ ;
if ( V_133 & V_138 )
V_4 -> V_93 . V_95 ++ ;
F_48 ( & V_4 -> V_94 ) ;
}
}
static void F_49 ( struct V_41 * V_5 , T_1 V_139 ,
char * V_140 )
{
struct V_3 * V_4 = F_2 ( V_5 ) ;
unsigned long V_69 ;
F_23 ( & V_4 -> V_72 , V_69 ) ;
V_4 -> V_73 = V_139 ;
F_24 ( & V_4 -> V_72 , V_69 ) ;
* V_140 = V_141 ;
if ( V_139 & V_142 ) {
if ( V_139 & V_143 ) {
V_4 -> V_93 . V_114 ++ ;
* V_140 = V_144 ;
F_50 ( V_5 ) ;
}
if ( V_139 & V_145 ) {
V_4 -> V_93 . V_113 ++ ;
if ( * V_140 == V_141 )
* V_140 = V_146 ;
}
if ( V_139 & V_147 ) {
V_4 -> V_93 . V_111 ++ ;
if ( * V_140 == V_141 )
* V_140 = V_148 ;
}
if ( V_139 & V_149 ) {
V_4 -> V_93 . V_112 ++ ;
if ( * V_140 == V_141 )
* V_140 = V_150 ;
}
}
}
static int F_51 ( struct V_151 * V_151 ,
struct V_39 * V_40 )
{
struct V_41 * V_5 = V_151 -> V_152 ;
char * V_153 = ( char * ) V_151 -> V_154 ;
char V_155 = V_141 ;
T_4 V_156 = V_151 -> V_157 ;
int V_158 ;
char * V_159 ;
if ( ( V_156 >= 4 ) &&
( V_153 [ 0 ] == 0x1b ) && ( V_153 [ 1 ] == 0x1b ) &&
( ( V_153 [ 2 ] == 0x00 ) || ( V_153 [ 2 ] == 0x01 ) ) ) {
if ( V_153 [ 2 ] == 0x00 ) {
F_49 ( V_5 , V_153 [ 3 ] , & V_155 ) ;
if ( V_155 == V_150 )
F_52 ( V_40 , 0 , V_150 ) ;
}
if ( V_153 [ 2 ] == 0x01 )
F_47 ( V_5 , V_153 [ 3 ] ) ;
V_156 -= 4 ;
V_159 = V_153 + 4 ;
} else
V_159 = V_153 ;
if ( ! V_156 )
return 0 ;
if ( V_5 -> V_5 . V_160 && V_5 -> V_161 ) {
for ( V_158 = 0 ; V_158 < V_156 ; V_158 ++ , V_159 ++ ) {
if ( ! F_53 ( V_5 , * V_159 ) )
F_52 ( V_40 , * V_159 , V_155 ) ;
}
} else
F_54 ( V_40 , V_159 , V_155 , V_156 ) ;
return V_156 ;
}
static void F_55 ( struct V_151 * V_151 )
{
struct V_41 * V_5 = V_151 -> V_152 ;
struct V_39 * V_40 ;
int V_162 ;
V_40 = F_56 ( & V_5 -> V_5 ) ;
if ( ! V_40 )
return;
V_162 = F_51 ( V_151 , V_40 ) ;
if ( V_162 )
F_57 ( V_40 ) ;
F_58 ( V_40 ) ;
}
