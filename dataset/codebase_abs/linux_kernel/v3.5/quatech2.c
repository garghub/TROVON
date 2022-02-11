static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( F_3 ( V_2 ) ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ )
F_2 ( F_4 ( V_2 -> V_5 [ V_3 ] ) ) ;
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
struct V_29 * V_5 = V_26 -> V_5 ;
struct V_10 * V_11 = V_5 -> V_2 -> V_11 ;
unsigned V_30 ;
int V_31 ;
if ( ( ( V_27 | V_28 ) & ( V_32 | V_33 ) ) == 0 ) {
F_16 ( & V_5 -> V_11 ,
L_1 ) ;
return 0 ;
}
V_28 &= ~ V_27 ;
V_30 = 0 ;
if ( V_27 & V_32 )
V_30 |= V_34 ;
if ( V_27 & V_33 )
V_30 |= V_35 ;
V_31 = F_14 ( V_11 , V_26 -> V_36 , V_37 ,
V_30 ) ;
if ( V_31 < 0 )
F_17 ( & V_5 -> V_11 ,
L_2 ,
V_31 ) ;
return V_31 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_38 V_39 ;
int V_3 ;
for ( V_3 = 0 ; V_39 = V_40 [ V_3 ] , V_39 . V_41 != 0 ; V_3 ++ ) {
if ( V_39 . V_41 == F_19 ( V_2 -> V_11 -> V_42 . V_43 ) )
return V_39 . V_4 ;
}
F_17 ( & V_2 -> V_11 -> V_11 ,
L_3 ) ;
return 1 ;
}
static void F_20 ( struct V_44 * V_45 ,
struct V_29 * V_5 ,
struct V_46 * V_47 )
{
struct V_10 * V_11 = V_5 -> V_2 -> V_11 ;
struct V_25 * V_26 ;
struct V_46 * V_48 = V_45 -> V_48 ;
T_1 V_49 ;
unsigned int V_50 = V_48 -> V_51 ;
T_1 V_52 = 0 ;
int V_31 ;
V_26 = F_4 ( V_5 ) ;
if ( V_50 & V_53 ) {
if ( V_50 & V_54 )
V_52 |= V_55 ;
else
V_52 |= V_56 ;
}
switch ( V_50 & V_57 ) {
case V_58 :
V_52 |= V_59 ;
break;
case V_60 :
V_52 |= V_61 ;
break;
case V_62 :
V_52 |= V_63 ;
break;
default:
case V_64 :
V_52 |= V_65 ;
break;
}
V_49 = F_21 ( V_45 ) ;
if ( ! V_49 )
V_49 = 9600 ;
V_31 = F_6 ( V_11 , V_26 -> V_36 , V_49 ,
V_52 ) ;
if ( V_31 < 0 )
F_17 ( & V_5 -> V_11 , L_4 ,
V_66 , V_31 ) ;
if ( V_50 & V_67 )
V_31 = F_9 ( V_11 , V_68 ,
V_69 ,
V_26 -> V_36 ) ;
else
V_31 = F_9 ( V_11 , V_68 ,
0 , V_26 -> V_36 ) ;
if ( V_31 < 0 )
F_17 ( & V_5 -> V_11 , L_5 ,
V_66 , V_31 ) ;
if ( F_22 ( V_45 ) || F_23 ( V_45 ) ) {
T_1 V_19 = ( ( T_1 ) ( F_24 ( V_45 ) << 8 ) | ( T_1 ) ( F_25 ( V_45 ) ) ) ;
V_31 = F_9 ( V_11 , V_70 ,
V_19 , V_26 -> V_36 ) ;
} else
V_31 = F_9 ( V_11 , V_70 ,
0 , V_26 -> V_36 ) ;
if ( V_31 < 0 )
F_17 ( & V_5 -> V_11 , L_6 ,
V_66 , V_31 ) ;
}
static int F_26 ( struct V_44 * V_45 , struct V_29 * V_5 )
{
struct V_1 * V_2 ;
struct V_71 * V_72 ;
struct V_25 * V_26 ;
T_2 * V_18 ;
T_1 V_36 ;
int V_31 ;
unsigned long V_73 ;
V_36 = ( T_1 ) ( V_5 -> V_74 - V_5 -> V_2 -> V_75 ) ;
V_2 = V_5 -> V_2 ;
V_26 = F_4 ( V_5 ) ;
V_72 = F_3 ( V_2 ) ;
V_31 = F_9 ( V_2 -> V_11 , V_76 ,
V_77 , V_36 ) ;
if ( V_31 < 0 ) {
F_17 ( & V_5 -> V_11 ,
L_7 ,
V_66 , V_36 , V_31 ) ;
return V_31 ;
}
V_18 = F_27 ( 2 , V_78 ) ;
if ( ! V_18 )
return - V_79 ;
V_31 = F_7 ( V_2 -> V_11 ,
F_12 ( V_2 -> V_11 , 0 ) ,
V_80 ,
0xc0 , 0 ,
V_36 , V_18 , 2 , V_16 ) ;
if ( V_31 < 0 ) {
F_17 ( & V_5 -> V_11 , L_8 , V_66 ,
V_31 ) ;
F_2 ( V_18 ) ;
return V_31 ;
}
F_28 ( & V_26 -> V_81 , V_73 ) ;
V_26 -> V_82 = V_18 [ 0 ] ;
V_26 -> V_83 = V_18 [ 1 ] ;
F_29 ( & V_26 -> V_81 , V_73 ) ;
F_2 ( V_18 ) ;
V_31 = F_6 ( V_2 -> V_11 , V_36 ,
V_84 , V_65 ) ;
if ( V_31 < 0 ) {
F_17 ( & V_5 -> V_11 ,
L_9 ,
V_66 , V_5 -> V_74 , V_36 ) ;
return V_31 ;
}
V_26 -> V_85 = true ;
V_26 -> V_36 = ( T_2 ) V_36 ;
if ( V_45 )
F_20 ( V_45 , V_5 , V_45 -> V_48 ) ;
return 0 ;
}
static void F_30 ( struct V_29 * V_5 )
{
struct V_1 * V_2 ;
struct V_71 * V_72 ;
struct V_25 * V_26 ;
unsigned long V_73 ;
int V_3 ;
V_2 = V_5 -> V_2 ;
V_72 = F_3 ( V_2 ) ;
V_26 = F_4 ( V_5 ) ;
V_26 -> V_85 = false ;
F_28 ( & V_26 -> V_86 , V_73 ) ;
if ( V_26 -> V_87 -> V_31 == - V_88 )
F_31 ( V_26 -> V_87 ) ;
V_26 -> V_89 = false ;
F_29 ( & V_26 -> V_86 , V_73 ) ;
V_3 = F_7 ( V_2 -> V_11 ,
F_12 ( V_2 -> V_11 , 0 ) ,
V_90 , 0x40 , 1 ,
V_26 -> V_36 , NULL , 0 , V_16 ) ;
if ( V_3 < 0 )
F_17 ( & V_5 -> V_11 , L_10 ,
V_66 , V_3 ) ;
V_3 = F_7 ( V_2 -> V_11 ,
F_12 ( V_2 -> V_11 , 0 ) ,
V_90 , 0x40 , 0 ,
V_26 -> V_36 , NULL , 0 , V_16 ) ;
if ( V_3 < 0 )
F_17 ( & V_5 -> V_11 , L_11 ,
V_66 , V_3 ) ;
V_3 = F_7 ( V_2 -> V_11 ,
F_8 ( V_2 -> V_11 , 0 ) ,
V_80 ,
0x40 , 0 ,
V_26 -> V_36 , NULL , 0 , V_16 ) ;
if ( V_3 < 0 )
F_17 ( & V_5 -> V_11 , L_12 ,
V_66 , V_3 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_71 * V_72 = F_3 ( V_2 ) ;
struct V_25 * V_26 ;
int V_3 ;
if ( V_72 -> V_91 -> V_31 == - V_88 )
F_31 ( V_72 -> V_91 ) ;
F_33 ( V_72 -> V_91 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
V_26 = F_4 ( V_2 -> V_5 [ V_3 ] ) ;
if ( V_26 -> V_87 -> V_31 == - V_88 )
F_31 ( V_26 -> V_87 ) ;
F_33 ( V_26 -> V_87 ) ;
}
}
static int F_34 ( struct V_29 * V_5 ,
struct V_92 T_3 * V_93 )
{
struct V_92 V_94 ;
if ( ! V_93 )
return - V_95 ;
memset ( & V_94 , 0 , sizeof( V_94 ) ) ;
V_94 . line = V_5 -> V_2 -> V_75 ;
V_94 . V_5 = 0 ;
V_94 . V_96 = 0 ;
V_94 . V_73 = V_97 | V_98 ;
V_94 . V_99 = V_5 -> V_100 ;
V_94 . V_101 = 9600 ;
V_94 . V_102 = 5 * V_103 ;
V_94 . V_104 = 30 * V_103 ;
if ( F_35 ( V_93 , & V_94 , sizeof( * V_93 ) ) )
return - V_95 ;
return 0 ;
}
static int F_36 ( struct V_29 * V_5 , unsigned int V_105 )
{
struct V_25 * V_106 = F_4 ( V_5 ) ;
struct V_107 V_108 , V_109 ;
unsigned long V_73 ;
F_28 ( & V_106 -> V_81 , V_73 ) ;
V_108 = V_106 -> V_110 ;
F_29 ( & V_106 -> V_81 , V_73 ) ;
while ( 1 ) {
F_37 ( V_106 -> V_111 ,
( ( V_106 -> V_110 . V_112 != V_108 . V_112 ) ||
( V_106 -> V_110 . V_113 != V_108 . V_113 ) ||
( V_106 -> V_110 . V_114 != V_108 . V_114 ) ||
( V_106 -> V_110 . V_115 != V_108 . V_115 ) ) ) ;
if ( F_38 ( V_116 ) )
return - V_117 ;
F_28 ( & V_106 -> V_81 , V_73 ) ;
V_109 = V_106 -> V_110 ;
F_29 ( & V_106 -> V_81 , V_73 ) ;
if ( ( V_108 . V_112 == V_109 . V_112 ) &&
( V_108 . V_113 == V_109 . V_113 ) &&
( V_108 . V_114 == V_109 . V_114 ) &&
( V_108 . V_115 == V_109 . V_115 ) )
return - V_118 ;
if ( ( V_105 & V_119 && ( V_108 . V_112 != V_109 . V_112 ) ) ||
( V_105 & V_120 && ( V_108 . V_113 != V_109 . V_113 ) ) ||
( V_105 & V_121 && ( V_108 . V_114 != V_109 . V_114 ) ) ||
( V_105 & V_122 && ( V_108 . V_115 != V_109 . V_115 ) ) )
return 0 ;
}
return 0 ;
}
static int F_39 ( struct V_44 * V_45 ,
struct V_123 * V_110 )
{
struct V_29 * V_5 = V_45 -> V_124 ;
struct V_25 * V_106 = F_4 ( V_5 ) ;
struct V_107 V_125 = V_106 -> V_110 ;
V_110 -> V_115 = V_125 . V_115 ;
V_110 -> V_113 = V_125 . V_113 ;
V_110 -> V_112 = V_125 . V_112 ;
V_110 -> V_114 = V_125 . V_114 ;
V_110 -> V_126 = V_125 . V_126 ;
V_110 -> V_127 = V_125 . V_127 ;
V_110 -> V_128 = V_125 . V_128 ;
V_110 -> V_129 = V_125 . V_129 ;
V_110 -> V_130 = V_125 . V_130 ;
V_110 -> V_131 = V_125 . V_131 ;
V_110 -> V_132 = V_125 . V_132 ;
return 0 ;
}
static int F_40 ( struct V_44 * V_45 ,
unsigned int V_133 , unsigned long V_105 )
{
struct V_29 * V_5 = V_45 -> V_124 ;
switch ( V_133 ) {
case V_134 :
return F_34 ( V_5 ,
(struct V_92 T_3 * ) V_105 ) ;
case V_135 :
return F_36 ( V_5 , V_105 ) ;
default:
break;
}
return - V_136 ;
}
static void F_41 ( struct V_29 * V_5 , unsigned char * V_137 )
{
switch ( * V_137 ) {
case V_138 :
F_42 ( V_5 , V_137 + 1 ) ;
break;
case V_139 :
F_43 ( V_5 , V_137 + 1 ) ;
break;
}
}
static void F_44 ( struct V_29 * V_5 ,
unsigned char * V_137 )
{
int V_140 ;
V_140 = ( int ) ( * V_137 ) + ( int ) ( * ( V_137 + 1 ) << 4 ) ;
}
static void F_45 ( struct V_29 * V_5 , unsigned char * V_137 )
{
return;
}
void F_46 ( struct V_141 * V_141 )
{
struct V_1 * V_2 ;
struct V_71 * V_72 ;
struct V_29 * V_5 ;
struct V_25 * V_26 ;
struct V_44 * V_45 ;
bool V_142 ;
unsigned char * V_137 ;
int V_3 ;
unsigned char V_143 ;
int V_144 = V_141 -> V_145 ;
if ( ! V_144 )
return;
V_137 = V_141 -> V_146 ;
V_45 = NULL ;
V_2 = V_141 -> V_147 ;
V_72 = F_3 ( V_2 ) ;
V_5 = V_2 -> V_5 [ V_72 -> V_148 ] ;
V_26 = F_4 ( V_5 ) ;
if ( V_26 -> V_85 )
V_45 = F_47 ( & V_5 -> V_5 ) ;
for ( V_3 = 0 ; V_3 < V_141 -> V_145 ; V_3 ++ ) {
V_137 = ( unsigned char * ) V_141 -> V_146 + V_3 ;
if ( ( V_3 <= ( V_144 - 3 ) ) &&
( * V_137 == V_149 ) &&
( * ( V_137 + 1 ) == V_149 ) ) {
V_142 = false ;
switch ( * ( V_137 + 2 ) ) {
case V_138 :
case V_139 :
if ( V_3 > ( V_144 - 4 ) ) {
F_48 ( & V_5 -> V_11 ,
L_13 ,
V_66 ) ;
break;
}
F_41 ( V_5 , V_137 + 2 ) ;
V_3 += 3 ;
V_142 = true ;
break;
case V_150 :
if ( V_3 > ( V_144 - 5 ) ) {
F_48 ( & V_5 -> V_11 ,
L_14 ,
V_66 ) ;
break;
}
F_44 ( V_5 , V_137 + 3 ) ;
V_3 += 4 ;
V_142 = true ;
break;
case V_151 :
if ( V_3 > ( V_144 - 4 ) ) {
F_48 ( & V_5 -> V_11 ,
L_15 ,
V_66 ) ;
break;
}
if ( V_45 ) {
F_49 ( V_45 ) ;
F_50 ( V_45 ) ;
}
V_143 = * ( V_137 + 3 ) ;
if ( V_143 > V_2 -> V_4 ) {
F_17 ( & V_5 -> V_11 ,
L_16 ,
V_66 , V_143 ) ;
break;
}
V_72 -> V_148 = V_143 ;
V_5 = V_2 -> V_5 [ V_72 -> V_148 ] ;
V_26 = F_4 ( V_5 ) ;
if ( V_26 -> V_85 )
V_45 = F_47 ( & V_5 -> V_5 ) ;
else
V_45 = NULL ;
V_3 += 3 ;
V_142 = true ;
break;
case V_152 :
case V_153 :
F_45 ( V_5 , V_137 + 2 ) ;
V_3 += 2 ;
V_142 = true ;
break;
case V_154 :
F_51 ( V_45 , 2 ) ;
F_52 ( V_45 , V_137 , 2 ) ;
V_3 += 2 ;
V_142 = true ;
break;
default:
F_48 ( & V_5 -> V_11 ,
L_17 ,
V_66 , * ( V_137 + 2 ) ) ;
break;
}
if ( V_142 )
continue;
}
if ( V_45 ) {
F_51 ( V_45 , 1 ) ;
F_52 ( V_45 , V_137 , 1 ) ;
}
}
if ( V_45 ) {
F_49 ( V_45 ) ;
F_50 ( V_45 ) ;
}
}
static void F_53 ( struct V_141 * V_141 )
{
struct V_29 * V_5 ;
struct V_25 * V_26 ;
V_5 = V_141 -> V_147 ;
V_26 = F_4 ( V_5 ) ;
F_54 ( & V_26 -> V_86 ) ;
V_26 -> V_89 = false ;
F_55 ( V_5 ) ;
F_56 ( & V_26 -> V_86 ) ;
}
static void F_57 ( struct V_141 * V_141 )
{
struct V_1 * V_2 = V_141 -> V_147 ;
int V_31 ;
if ( V_141 -> V_31 ) {
F_48 ( & V_2 -> V_11 -> V_11 ,
L_18 , V_66 ,
V_141 -> V_31 ) ;
return;
}
F_46 ( V_141 ) ;
V_31 = F_58 ( V_141 , V_155 ) ;
if ( V_31 != 0 )
F_17 ( & V_2 -> V_11 -> V_11 ,
L_19 ,
V_66 , V_31 ) ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_29 * V_5 ;
struct V_29 * V_156 ;
struct V_71 * V_72 ;
struct V_25 * V_26 ;
int V_157 , V_31 ;
V_156 = V_2 -> V_5 [ 0 ] ;
V_72 = F_3 ( V_2 ) ;
V_72 -> V_91 = F_60 ( 0 , V_78 ) ;
if ( ! V_72 -> V_91 ) {
F_17 ( & V_2 -> V_11 -> V_11 , L_20 ) ;
return - V_79 ;
}
F_61 ( V_72 -> V_91 , V_2 -> V_11 ,
F_62 ( V_2 -> V_11 ,
V_156 -> V_158 ) ,
V_72 -> V_159 ,
sizeof( V_72 -> V_159 ) ,
F_57 , V_2 ) ;
for ( V_157 = 0 ; V_157 < V_2 -> V_4 ; V_157 ++ ) {
V_5 = V_2 -> V_5 [ V_157 ] ;
V_26 = F_4 ( V_5 ) ;
V_26 -> V_87 = F_60 ( 0 , V_78 ) ;
if ( ! V_26 -> V_87 ) {
F_17 ( & V_2 -> V_11 -> V_11 ,
L_21 ,
V_157 ) ;
return - V_79 ;
}
F_61 ( V_26 -> V_87 ,
V_2 -> V_11 ,
F_63 ( V_2 -> V_11 ,
V_156 ->
V_160 ) ,
V_26 -> V_161 ,
sizeof( V_26 -> V_161 ) ,
F_53 , V_5 ) ;
}
V_31 = F_58 ( V_72 -> V_91 , V_78 ) ;
if ( V_31 != 0 ) {
F_17 ( & V_2 -> V_11 -> V_11 ,
L_22 , V_66 , V_31 ) ;
return V_31 ;
}
return 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_71 * V_72 ;
struct V_25 * V_26 ;
int V_31 , V_157 ;
V_31 = F_7 ( V_2 -> V_11 , F_12 ( V_2 -> V_11 , 0 ) ,
0xc2 , 0x40 , 0x8000 , 0 , NULL , 0 ,
V_16 ) ;
if ( V_31 < 0 ) {
F_17 ( & V_2 -> V_11 -> V_11 ,
L_23 , V_66 , V_31 ) ;
return V_31 ;
}
V_72 = F_27 ( sizeof( * V_72 ) , V_78 ) ;
if ( ! V_72 ) {
F_17 ( & V_2 -> V_11 -> V_11 , L_24 , V_66 ) ;
return - V_79 ;
}
F_65 ( V_2 , V_72 ) ;
for ( V_157 = 0 ; V_157 < V_2 -> V_4 ; V_157 ++ ) {
V_26 = F_27 ( sizeof( * V_26 ) , V_78 ) ;
if ( ! V_26 ) {
F_17 ( & V_2 -> V_11 -> V_11 ,
L_25 , V_66 ,
sizeof( * V_26 ) ) ;
V_157 -- ;
V_31 = - V_79 ;
goto V_162;
}
F_66 ( & V_26 -> V_81 ) ;
F_66 ( & V_26 -> V_86 ) ;
F_67 ( & V_26 -> V_111 ) ;
V_26 -> V_5 = V_2 -> V_5 [ V_157 ] ;
F_68 ( V_2 -> V_5 [ V_157 ] , V_26 ) ;
}
V_31 = F_59 ( V_2 ) ;
if ( V_31 != 0 )
goto V_162;
return 0 ;
V_162:
for (; V_157 >= 0 ; V_157 -- ) {
V_26 = F_4 ( V_2 -> V_5 [ V_157 ] ) ;
F_2 ( V_26 ) ;
}
F_2 ( V_72 ) ;
return V_31 ;
}
static int F_69 ( struct V_44 * V_45 )
{
struct V_29 * V_5 = V_45 -> V_124 ;
struct V_10 * V_11 = V_5 -> V_2 -> V_11 ;
struct V_25 * V_26 = F_4 ( V_5 ) ;
T_2 * V_39 ;
int V_163 ;
V_39 = F_27 ( 2 , V_78 ) ;
if ( ! V_39 )
return - V_79 ;
V_163 = F_13 ( V_11 , V_26 -> V_36 , V_37 , V_39 ) ;
if ( V_163 < 0 )
goto V_164;
V_163 = F_13 ( V_11 , V_26 -> V_36 , V_165 , V_39 + 1 ) ;
if ( V_163 < 0 )
goto V_164;
V_163 = ( V_39 [ 0 ] & V_34 ? V_32 : 0 ) |
( V_39 [ 0 ] & V_35 ? V_33 : 0 ) |
( V_39 [ 1 ] & V_166 ? V_122 : 0 ) |
( V_39 [ 1 ] & V_167 ? V_168 : 0 ) |
( V_39 [ 1 ] & V_169 ? V_170 : 0 ) |
( V_39 [ 1 ] & V_171 ? V_120 : 0 ) ;
V_164:
F_2 ( V_39 ) ;
return V_163 ;
}
static int F_70 ( struct V_44 * V_45 ,
unsigned int V_27 , unsigned int V_28 )
{
struct V_25 * V_26 ;
V_26 = F_4 ( V_45 -> V_124 ) ;
return F_15 ( V_26 , V_27 , V_28 ) ;
}
static void F_71 ( struct V_44 * V_45 , int V_172 )
{
struct V_29 * V_5 = V_45 -> V_124 ;
struct V_25 * V_26 ;
int V_31 ;
T_1 V_173 ;
V_26 = F_4 ( V_5 ) ;
if ( ! V_26 -> V_85 ) {
F_17 ( & V_5 -> V_11 ,
L_26 , V_66 ) ;
return;
}
V_173 = ( V_172 == - 1 ) ? 1 : 0 ;
V_31 = F_9 ( V_5 -> V_2 -> V_11 , V_174 ,
V_173 , V_26 -> V_36 ) ;
if ( V_31 < 0 )
F_48 ( & V_5 -> V_11 ,
L_27 , V_66 ,
V_31 ) ;
}
static void F_72 ( struct V_29 * V_5 , int V_175 )
{
struct V_10 * V_11 = V_5 -> V_2 -> V_11 ;
struct V_25 * V_26 = F_4 ( V_5 ) ;
F_73 ( & V_5 -> V_2 -> V_176 ) ;
if ( ! V_5 -> V_2 -> V_177 ) {
if ( ! V_175 && F_14 ( V_11 , V_26 -> V_36 ,
V_37 , 0 ) < 0 )
F_48 ( & V_5 -> V_11 , L_28 ) ;
if ( V_175 )
F_15 ( V_26 , V_32 | V_33 , 0 ) ;
else
F_15 ( V_26 , 0 , V_32 | V_33 ) ;
}
F_74 ( & V_5 -> V_2 -> V_176 ) ;
}
static void F_43 ( struct V_29 * V_5 , unsigned char * V_137 )
{
struct V_25 * V_26 ;
T_2 V_178 = ( T_2 ) * V_137 ;
unsigned long V_73 ;
V_26 = F_4 ( V_5 ) ;
F_28 ( & V_26 -> V_81 , V_73 ) ;
V_26 -> V_83 = V_178 ;
F_29 ( & V_26 -> V_81 , V_73 ) ;
if ( V_178 & V_179 ) {
if ( V_178 & V_180 )
V_26 -> V_110 . V_115 ++ ;
if ( V_178 & V_181 )
V_26 -> V_110 . V_113 ++ ;
if ( V_178 & V_182 )
V_26 -> V_110 . V_114 ++ ;
if ( V_178 & V_183 )
V_26 -> V_110 . V_112 ++ ;
F_75 ( & V_26 -> V_111 ) ;
}
}
static void F_42 ( struct V_29 * V_5 , unsigned char * V_137 )
{
struct V_25 * V_26 ;
struct V_107 * V_110 ;
unsigned long V_73 ;
T_2 V_184 = ( T_2 ) * V_137 ;
V_26 = F_4 ( V_5 ) ;
if ( V_184 & V_185 )
V_184 &= ( T_2 ) ( V_186 | V_185 ) ;
F_28 ( & V_26 -> V_81 , V_73 ) ;
V_26 -> V_82 = V_184 ;
F_29 ( & V_26 -> V_81 , V_73 ) ;
V_110 = & V_26 -> V_110 ;
if ( V_184 & V_187 ) {
if ( V_184 & V_185 )
V_110 -> V_131 ++ ;
if ( V_184 & V_186 )
V_110 -> V_129 ++ ;
if ( V_184 & V_188 )
V_110 -> V_130 ++ ;
if ( V_184 & V_189 )
V_110 -> V_128 ++ ;
}
}
static int F_76 ( struct V_44 * V_45 )
{
struct V_29 * V_5 = V_45 -> V_124 ;
struct V_25 * V_26 ;
unsigned long V_73 = 0 ;
int V_163 ;
V_26 = F_4 ( V_5 ) ;
F_28 ( & V_26 -> V_86 , V_73 ) ;
if ( V_26 -> V_89 )
V_163 = 0 ;
else
V_163 = V_190 - V_191 ;
F_29 ( & V_26 -> V_86 , V_73 ) ;
return V_163 ;
}
static int F_77 ( struct V_44 * V_45 ,
struct V_29 * V_5 ,
const unsigned char * V_192 , int V_193 )
{
struct V_25 * V_26 ;
struct V_141 * V_87 ;
unsigned char * V_18 ;
unsigned long V_73 ;
int V_31 ;
int V_194 = 0 ;
V_26 = F_4 ( V_5 ) ;
if ( V_26 -> V_87 == NULL ) {
F_17 ( & V_5 -> V_11 , L_29 , V_66 ) ;
return 0 ;
}
V_87 = V_26 -> V_87 ;
V_193 = F_78 ( V_193 , V_190 - V_191 ) ;
V_18 = V_87 -> V_146 ;
F_28 ( & V_26 -> V_86 , V_73 ) ;
if ( V_26 -> V_89 == true ) {
F_79 ( V_195 L_30 ) ;
goto V_196;
}
* V_18 ++ = V_149 ;
* V_18 ++ = V_149 ;
* V_18 ++ = V_26 -> V_36 ;
F_80 ( V_193 , V_18 ) ;
V_18 += 2 ;
memcpy ( V_18 , V_192 , V_193 ) ;
V_87 -> V_197 = V_193 + V_191 ;
V_31 = F_58 ( V_87 , V_155 ) ;
if ( V_31 == 0 ) {
V_26 -> V_89 = true ;
V_194 += V_193 ;
}
V_196:
F_29 ( & V_26 -> V_86 , V_73 ) ;
return V_194 ;
}
