static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( * V_2 -> V_5 ) ;
F_3 ( L_1 , V_6 ) ;
F_4 ( V_4 ) ;
}
static inline int F_5 ( struct V_7 * V_8 ,
T_1 V_9 , T_2 V_10 , T_2 V_11 )
{
return F_6 ( V_8 , F_7 ( V_8 , 0 ) ,
V_9 , 0x40 , V_10 , V_11 ,
NULL , 0 , 300 ) ;
}
static inline int F_8 ( struct V_7 * V_8 , T_1 * V_10 )
{
T_2 V_12 = ( ( T_2 ) ( V_10 [ 1 ] << 8 ) | ( T_2 ) ( V_10 [ 0 ] ) ) ;
return F_5 ( V_8 , V_13 , V_12 , 0 ) ;
}
static inline int F_9 ( struct V_7 * V_8 , T_1 * V_10 )
{
return F_6 ( V_8 , F_10 ( V_8 , 0 ) ,
V_13 , 0xc0 , 0 , 0 ,
V_10 , 3 , 300 ) ;
}
static inline int F_11 ( struct V_7 * V_8 ,
unsigned short V_14 ,
unsigned short V_15 ,
T_1 * V_10 )
{
return F_6 ( V_8 , F_10 ( V_8 , 0 ) ,
V_16 , 0xc0 , V_15 ,
V_14 , V_10 , sizeof( * V_10 ) , 300 ) ;
}
static inline int F_12 ( struct V_7 * V_8 ,
unsigned short V_14 ,
unsigned short V_15 ,
T_2 V_10 )
{
T_2 V_17 = ( V_10 << 8 ) | V_15 ;
return F_6 ( V_8 , F_7 ( V_8 , 0 ) ,
V_16 , 0x40 , V_17 , V_14 ,
NULL , 0 , 300 ) ;
}
static inline int F_13 ( struct V_7 * V_8 , unsigned int V_18 ,
unsigned int V_19 )
{
unsigned V_20 ;
int V_21 ;
if ( ( ( V_18 | V_19 ) & ( V_22 | V_23 ) ) == 0 ) {
F_3 ( L_2 , V_6 ) ;
return 0 ;
}
V_19 &= ~ V_18 ;
V_20 = 0 ;
if ( V_18 & V_22 )
V_20 |= V_24 ;
if ( V_18 & V_23 )
V_20 |= V_25 ;
V_21 = F_12 ( V_8 , 0 , V_26 , V_20 ) ;
if ( V_21 < 0 )
F_3 ( L_3 , V_6 ) ;
return V_21 ;
}
static int F_14 ( struct V_7 * V_8 )
{
T_1 * V_10 ;
int V_21 = 0 ;
F_3 ( L_1 , V_6 ) ;
V_10 = F_15 ( 3 , V_27 ) ;
if ( ! V_10 )
return - V_28 ;
V_21 = F_9 ( V_8 , V_10 ) ;
if ( V_21 < 0 ) {
F_3 ( L_4 , V_6 , V_21 ) ;
goto V_29;
}
V_10 [ 1 ] &= ~ V_30 ;
V_21 = F_8 ( V_8 , V_10 ) ;
if ( V_21 < 0 ) {
F_3 ( L_5 , V_6 , V_21 ) ;
goto V_29;
}
V_21 = F_5 ( V_8 , V_31 , 128 , 0 ) ;
if ( V_21 < 0 ) {
F_3 ( L_6 , V_6 , V_21 ) ;
goto V_29;
}
V_21 = F_5 ( V_8 , V_32 , V_33 , 0 ) ;
if ( V_21 < 0 ) {
F_3 ( L_7 , V_6 , V_21 ) ;
goto V_29;
}
V_21 = F_9 ( V_8 , V_10 ) ;
if ( V_21 < 0 ) {
F_3 ( L_4 , V_6 , V_21 ) ;
goto V_29;
}
V_10 [ 0 ] &= ~ ( V_34 | V_35 ) ;
V_10 [ 0 ] |= V_36 ;
V_10 [ 1 ] &= ~ ( V_37 ) ;
V_10 [ 1 ] |= V_38 ;
V_21 = F_8 ( V_8 , V_10 ) ;
if ( V_21 < 0 ) {
F_3 ( L_5 , V_6 , V_21 ) ;
goto V_29;
}
V_29: F_4 ( V_10 ) ;
return V_21 ;
}
static void F_16 ( struct V_39 * V_40 ,
struct V_41 * V_5 ,
struct V_42 * V_43 )
{
struct V_7 * V_8 = V_5 -> V_2 -> V_8 ;
struct V_42 * V_44 = V_40 -> V_44 ;
T_2 V_45 , V_46 , V_47 ;
unsigned int V_48 = V_44 -> V_49 ;
T_2 V_20 = 0 ;
int V_21 ;
F_3 ( L_1 , V_6 ) ;
if ( V_48 & V_50 ) {
if ( V_48 & V_51 )
V_20 |= V_52 ;
else
V_20 |= V_53 ;
}
switch ( V_48 & V_54 ) {
case V_55 :
V_20 |= V_56 ;
break;
case V_57 :
V_20 |= V_58 ;
break;
case V_59 :
V_20 |= V_60 ;
break;
default:
case V_61 :
V_20 |= V_62 ;
break;
}
V_45 = F_17 ( V_40 ) ;
if ( ! V_45 )
V_45 = 9600 ;
F_3 ( L_8 , V_6 , V_45 ) ;
V_46 = V_63 / V_45 ;
V_47 = V_63 % V_45 ;
if ( ( ( V_47 * 2 ) >= V_45 ) && ( V_45 != 110 ) )
V_46 ++ ;
V_20 = V_20 << 8 ;
V_21 = F_5 ( V_8 , V_64 , V_46 , V_20 ) ;
if ( V_21 < 0 )
F_3 ( L_9 , V_6 ) ;
if ( V_48 & V_65 )
V_21 = F_5 ( V_8 , V_66 ,
V_67 , 0 ) ;
else
V_21 = F_5 ( V_8 , V_66 ,
0 , 0 ) ;
if ( V_21 < 0 )
F_3 ( L_10 , V_6 ) ;
if ( F_18 ( V_40 ) || F_19 ( V_40 ) ) {
T_2 V_12 = ( ( T_2 ) ( F_20 ( V_40 ) << 8 ) | ( T_2 ) ( F_21 ( V_40 ) ) ) ;
V_21 = F_5 ( V_8 , V_68 ,
V_12 , 0 ) ;
} else
V_21 = F_5 ( V_8 , V_68 ,
0 , 0 ) ;
if ( V_21 < 0 )
F_3 ( L_11 , V_6 ) ;
}
static int F_22 ( struct V_39 * V_40 , struct V_41 * V_5 )
{
struct V_7 * V_8 = V_5 -> V_2 -> V_8 ;
struct V_3 * V_4 = F_2 ( V_5 ) ;
T_1 * V_10 ;
int V_21 ;
unsigned long V_69 ;
F_3 ( L_12 , V_6 , V_5 -> V_70 ) ;
V_10 = F_15 ( 2 , V_27 ) ;
if ( ! V_10 )
return - V_28 ;
V_21 = F_6 ( V_8 , F_10 ( V_8 , 0 ) ,
V_71 ,
V_72 , 0x01 ,
0 , V_10 , 2 , 300 ) ;
if ( V_21 < 0 ) {
F_3 ( L_13 , V_6 , V_21 ) ;
F_4 ( V_10 ) ;
return V_21 ;
}
F_23 ( & V_4 -> V_73 , V_69 ) ;
V_4 -> V_74 = V_10 [ 0 ] ;
V_4 -> V_75 = V_10 [ 1 ] ;
F_24 ( & V_4 -> V_73 , V_69 ) ;
F_4 ( V_10 ) ;
V_21 = F_5 ( V_8 , V_64 , 0x30 , 0x0300 ) ;
if ( V_21 < 0 )
F_3 ( L_9 , V_6 ) ;
if ( V_40 )
F_16 ( V_40 , V_5 , V_40 -> V_44 ) ;
return F_25 ( V_40 , V_5 ) ;
}
static void F_26 ( struct V_41 * V_5 )
{
F_3 ( L_1 , V_6 ) ;
F_27 ( V_5 ) ;
}
static int F_28 ( struct V_41 * V_5 ,
struct V_76 T_3 * V_77 )
{
struct V_76 V_78 ;
if ( ! V_77 )
return - V_79 ;
memset ( & V_78 , 0 , sizeof( V_78 ) ) ;
V_78 . line = V_5 -> V_2 -> V_80 ;
V_78 . V_5 = 0 ;
V_78 . V_81 = 0 ;
V_78 . V_69 = V_82 | V_83 ;
V_78 . V_84 = V_5 -> V_85 ;
V_78 . V_86 = 9600 ;
V_78 . V_87 = 5 * V_88 ;
V_78 . V_89 = 30 * V_88 ;
if ( F_29 ( V_77 , & V_78 , sizeof( * V_77 ) ) )
return - V_79 ;
return 0 ;
}
static int F_30 ( struct V_41 * V_5 , unsigned int V_90 )
{
struct V_3 * V_4 = F_2 ( V_5 ) ;
struct V_91 V_92 , V_93 ;
unsigned long V_69 ;
F_23 ( & V_4 -> V_73 , V_69 ) ;
V_92 = V_4 -> V_94 ;
F_24 ( & V_4 -> V_73 , V_69 ) ;
while ( 1 ) {
F_31 ( V_4 -> V_95 ,
( ( V_4 -> V_94 . V_96 != V_92 . V_96 ) ||
( V_4 -> V_94 . V_97 != V_92 . V_97 ) ||
( V_4 -> V_94 . V_98 != V_92 . V_98 ) ||
( V_4 -> V_94 . V_99 != V_92 . V_99 ) ) ) ;
if ( F_32 ( V_100 ) )
return - V_101 ;
F_23 ( & V_4 -> V_73 , V_69 ) ;
V_93 = V_4 -> V_94 ;
F_24 ( & V_4 -> V_73 , V_69 ) ;
if ( ( V_92 . V_96 == V_93 . V_96 ) &&
( V_92 . V_97 == V_93 . V_97 ) &&
( V_92 . V_98 == V_93 . V_98 ) &&
( V_92 . V_99 == V_93 . V_99 ) )
return - V_102 ;
if ( ( V_90 & V_103 && ( V_92 . V_96 != V_93 . V_96 ) ) ||
( V_90 & V_104 && ( V_92 . V_97 != V_93 . V_97 ) ) ||
( V_90 & V_105 && ( V_92 . V_98 != V_93 . V_98 ) ) ||
( V_90 & V_106 && ( V_92 . V_99 != V_93 . V_99 ) ) )
return 0 ;
}
return 0 ;
}
static int F_33 ( struct V_39 * V_40 ,
struct V_107 * V_94 )
{
struct V_41 * V_5 = V_40 -> V_108 ;
struct V_3 * V_4 = F_2 ( V_5 ) ;
struct V_91 V_109 = V_4 -> V_94 ;
V_94 -> V_99 = V_109 . V_99 ;
V_94 -> V_97 = V_109 . V_97 ;
V_94 -> V_96 = V_109 . V_96 ;
V_94 -> V_98 = V_109 . V_98 ;
V_94 -> V_110 = V_109 . V_110 ;
V_94 -> V_111 = V_109 . V_111 ;
V_94 -> V_112 = V_109 . V_112 ;
V_94 -> V_113 = V_109 . V_113 ;
V_94 -> V_114 = V_109 . V_114 ;
V_94 -> V_115 = V_109 . V_115 ;
V_94 -> V_116 = V_109 . V_116 ;
return 0 ;
}
static int F_34 ( struct V_39 * V_40 ,
unsigned int V_117 , unsigned long V_90 )
{
struct V_41 * V_5 = V_40 -> V_108 ;
F_3 ( L_14 , V_6 , V_117 ) ;
switch ( V_117 ) {
case V_118 :
return F_28 ( V_5 ,
(struct V_76 T_3 * ) V_90 ) ;
case V_119 :
return F_30 ( V_5 , V_90 ) ;
default:
break;
}
F_3 ( L_15 , V_6 ) ;
return - V_120 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_41 * V_5 = * V_2 -> V_5 ;
F_3 ( L_1 , V_6 ) ;
V_4 = F_15 ( sizeof( * V_4 ) , V_27 ) ;
if ( ! V_4 ) {
F_36 ( & V_5 -> V_8 , L_16 , V_6 ,
sizeof( * V_4 ) ) ;
return - V_28 ;
}
F_37 ( & V_4 -> V_73 ) ;
F_38 ( & V_4 -> V_95 ) ;
F_39 ( V_5 , V_4 ) ;
return F_14 ( V_2 -> V_8 ) ;
}
static int F_40 ( struct V_39 * V_40 )
{
struct V_41 * V_5 = V_40 -> V_108 ;
struct V_7 * V_8 = V_5 -> V_2 -> V_8 ;
T_1 * V_121 ;
int V_122 ;
F_3 ( L_17 , V_6 ) ;
V_121 = F_15 ( 2 , V_27 ) ;
if ( ! V_121 )
return - V_28 ;
V_122 = F_11 ( V_8 , 0 , V_26 , V_121 ) ;
if ( V_122 < 0 )
goto V_123;
V_122 = F_11 ( V_8 , 0 , V_124 , V_121 + 1 ) ;
if ( V_122 < 0 )
goto V_123;
V_122 = ( V_121 [ 0 ] & V_24 ? V_22 : 0 ) |
( V_121 [ 0 ] & V_25 ? V_23 : 0 ) |
( V_121 [ 1 ] & V_125 ? V_106 : 0 ) |
( V_121 [ 1 ] & V_126 ? V_127 : 0 ) |
( V_121 [ 1 ] & V_128 ? V_129 : 0 ) |
( V_121 [ 1 ] & V_130 ? V_104 : 0 ) ;
V_123:
F_4 ( V_121 ) ;
return V_122 ;
}
static int F_41 ( struct V_39 * V_40 ,
unsigned int V_18 , unsigned int V_19 )
{
struct V_41 * V_5 = V_40 -> V_108 ;
struct V_7 * V_8 = V_5 -> V_2 -> V_8 ;
F_3 ( L_17 , V_6 ) ;
return F_13 ( V_8 , V_18 , V_19 ) ;
}
static void F_42 ( struct V_41 * V_5 , int V_131 )
{
struct V_7 * V_8 = V_5 -> V_2 -> V_8 ;
F_3 ( L_17 , V_6 ) ;
F_43 ( & V_5 -> V_2 -> V_132 ) ;
if ( ! V_5 -> V_2 -> V_133 ) {
if ( ! V_131 &&
F_12 ( V_8 , 0 , V_26 , 0 ) < 0 )
F_36 ( & V_5 -> V_8 , L_18 ) ;
if ( V_131 )
F_44 ( V_8 , V_22 | V_23 ) ;
else
F_45 ( V_8 , V_22 | V_23 ) ;
}
F_46 ( & V_5 -> V_2 -> V_132 ) ;
}
static void F_47 ( struct V_41 * V_5 , T_1 V_134 )
{
struct V_3 * V_4 = F_2 ( V_5 ) ;
unsigned long V_69 ;
F_23 ( & V_4 -> V_73 , V_69 ) ;
V_4 -> V_75 = V_134 ;
F_24 ( & V_4 -> V_73 , V_69 ) ;
if ( V_134 & V_135 ) {
if ( V_134 & V_136 )
V_4 -> V_94 . V_99 ++ ;
if ( V_134 & V_137 )
V_4 -> V_94 . V_97 ++ ;
if ( V_134 & V_138 )
V_4 -> V_94 . V_98 ++ ;
if ( V_134 & V_139 )
V_4 -> V_94 . V_96 ++ ;
F_48 ( & V_4 -> V_95 ) ;
}
}
static void F_49 ( struct V_41 * V_5 , T_1 V_140 ,
char * V_141 )
{
struct V_3 * V_4 = F_2 ( V_5 ) ;
unsigned long V_69 ;
F_23 ( & V_4 -> V_73 , V_69 ) ;
V_4 -> V_74 = V_140 ;
F_24 ( & V_4 -> V_73 , V_69 ) ;
* V_141 = V_142 ;
if ( V_140 & V_143 ) {
if ( V_140 & V_144 ) {
V_4 -> V_94 . V_115 ++ ;
* V_141 = V_145 ;
F_50 ( V_5 ) ;
}
if ( V_140 & V_146 ) {
V_4 -> V_94 . V_114 ++ ;
if ( * V_141 == V_142 )
* V_141 = V_147 ;
}
if ( V_140 & V_148 ) {
V_4 -> V_94 . V_112 ++ ;
if ( * V_141 == V_142 )
* V_141 = V_149 ;
}
if ( V_140 & V_150 ) {
V_4 -> V_94 . V_113 ++ ;
if ( * V_141 == V_142 )
* V_141 = V_151 ;
}
}
}
static int F_51 ( struct V_152 * V_152 ,
struct V_39 * V_40 )
{
struct V_41 * V_5 = V_152 -> V_153 ;
char * V_154 = ( char * ) V_152 -> V_155 ;
char V_156 = V_142 ;
T_4 V_157 = V_152 -> V_158 ;
int V_159 ;
char * V_160 ;
F_3 ( L_12 , V_6 , V_5 -> V_70 ) ;
if ( ( V_157 >= 4 ) &&
( V_154 [ 0 ] == 0x1b ) && ( V_154 [ 1 ] == 0x1b ) &&
( ( V_154 [ 2 ] == 0x00 ) || ( V_154 [ 2 ] == 0x01 ) ) ) {
if ( V_154 [ 2 ] == 0x00 ) {
F_49 ( V_5 , V_154 [ 3 ] , & V_156 ) ;
if ( V_156 == V_151 )
F_52 ( V_40 , 0 , V_151 ) ;
}
if ( V_154 [ 2 ] == 0x01 )
F_47 ( V_5 , V_154 [ 3 ] ) ;
V_157 -= 4 ;
V_160 = V_154 + 4 ;
} else
V_160 = V_154 ;
if ( ! V_157 )
return 0 ;
if ( V_5 -> V_5 . V_161 && V_5 -> V_162 ) {
for ( V_159 = 0 ; V_159 < V_157 ; V_159 ++ , V_160 ++ ) {
if ( ! F_53 ( V_5 , * V_160 ) )
F_52 ( V_40 , * V_160 , V_156 ) ;
}
} else
F_54 ( V_40 , V_160 , V_156 , V_157 ) ;
return V_157 ;
}
static void F_55 ( struct V_152 * V_152 )
{
struct V_41 * V_5 = V_152 -> V_153 ;
struct V_39 * V_40 ;
int V_163 ;
F_3 ( L_1 , V_6 ) ;
V_40 = F_56 ( & V_5 -> V_5 ) ;
if ( ! V_40 )
return;
V_163 = F_51 ( V_152 , V_40 ) ;
if ( V_163 )
F_57 ( V_40 ) ;
F_58 ( V_40 ) ;
}
