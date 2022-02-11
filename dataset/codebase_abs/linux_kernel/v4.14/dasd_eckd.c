static int
F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_4 |
V_5 | V_6 ) ;
if ( V_3 ) {
F_3 ( V_7 , V_2 , L_1 ,
L_2
L_3 ) ;
return V_3 ;
}
V_3 = F_4 ( V_2 , & V_8 ) ;
return V_3 ;
}
static int
F_5 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , & V_8 ) ;
}
static inline unsigned int
F_7 ( unsigned int V_9 , unsigned int V_10 )
{
int V_11 = V_9 % V_10 ;
return ( V_11 ? V_9 - V_11 + V_10 : V_9 ) ;
}
static inline unsigned int
F_8 ( unsigned int V_12 , unsigned int V_13 )
{
return ( V_12 + ( V_13 - 1 ) ) / V_13 ;
}
static unsigned int
F_9 ( struct V_14 * V_15 ,
unsigned int V_16 , unsigned int V_17 )
{
int V_18 , V_19 ;
switch ( V_15 -> V_20 ) {
case 0x3380 :
if ( V_16 )
return 1499 / ( 15 + 7 + F_8 ( V_16 + 12 , 32 ) +
F_8 ( V_17 + 12 , 32 ) ) ;
else
return 1499 / ( 15 + F_8 ( V_17 + 12 , 32 ) ) ;
case 0x3390 :
V_18 = F_8 ( V_17 + 6 , 232 ) + 1 ;
if ( V_16 ) {
V_19 = F_8 ( V_16 + 6 , 232 ) + 1 ;
return 1729 / ( 10 + 9 + F_8 ( V_16 + 6 * V_19 , 34 ) +
9 + F_8 ( V_17 + 6 * V_18 , 34 ) ) ;
} else
return 1729 / ( 10 + 9 + F_8 ( V_17 + 6 * V_18 , 34 ) ) ;
case 0x9345 :
V_18 = F_8 ( V_17 + 6 , 232 ) + 1 ;
if ( V_16 ) {
V_19 = F_8 ( V_16 + 6 , 232 ) + 1 ;
return 1420 / ( 18 + 7 + F_8 ( V_16 + 6 * V_19 , 34 ) +
F_8 ( V_17 + 6 * V_18 , 34 ) ) ;
} else
return 1420 / ( 18 + 7 + F_8 ( V_17 + 6 * V_18 , 34 ) ) ;
}
return 0 ;
}
static void F_10 ( struct V_21 * V_22 , T_1 V_23 , T_2 V_24 )
{
V_22 -> V_23 = ( V_25 ) V_23 ;
V_22 -> V_24 = V_23 >> 16 ;
V_22 -> V_24 <<= 4 ;
V_22 -> V_24 |= V_24 ;
}
static int F_11 ( struct V_26 * V_27 , struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
int V_34 ;
if ( ! V_33 -> V_35 . V_36 . V_37 )
return 0 ;
V_29 -> V_38 |= 0x08 ;
V_29 -> V_38 |= 0x02 ;
V_34 = F_12 ( & V_29 -> V_39 ) ;
if ( V_34 == - V_40 || V_34 == - V_41 )
V_34 = 0 ;
if ( V_27 ) {
V_27 -> V_42 = sizeof( struct V_28 ) ;
V_27 -> V_43 |= V_44 ;
}
return V_34 ;
}
static int
F_13 ( struct V_26 * V_27 , struct V_28 * V_29 , unsigned int V_45 ,
unsigned int V_46 , int V_47 , struct V_30 * V_31 ,
int V_48 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
T_3 V_49 , V_50 , V_51 ;
T_4 V_52 , V_53 ;
int V_34 = 0 ;
if ( V_27 ) {
V_27 -> V_54 = V_55 ;
V_27 -> V_43 = 0 ;
V_27 -> V_42 = 16 ;
V_27 -> V_56 = ( T_1 ) F_14 ( V_29 ) ;
}
memset ( V_29 , 0 , sizeof( struct V_28 ) ) ;
switch ( V_47 ) {
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
V_29 -> V_65 . V_66 = 0x1 ;
V_29 -> V_67 . V_68 = V_33 -> V_69 . V_68 ;
break;
case V_70 :
V_29 -> V_65 . V_66 = 0x1 ;
V_29 -> V_67 . V_68 = V_71 ;
break;
case V_72 :
case V_73 :
V_29 -> V_65 . V_66 = 0x1 ;
V_29 -> V_67 . V_68 = V_33 -> V_69 . V_68 ;
V_29 -> V_74 = 0 ;
break;
case V_75 :
case V_76 :
case V_77 :
case V_78 :
V_29 -> V_65 . V_66 = 0x02 ;
V_29 -> V_67 . V_68 = V_33 -> V_69 . V_68 ;
V_34 = F_11 ( V_27 , V_29 , V_31 ) ;
break;
case V_79 :
case V_80 :
V_29 -> V_67 . V_68 = V_71 ;
V_34 = F_11 ( V_27 , V_29 , V_31 ) ;
break;
case V_81 :
case V_82 :
case V_83 :
V_29 -> V_65 . V_66 = 0x3 ;
V_29 -> V_65 . V_84 = 0x1 ;
V_29 -> V_67 . V_68 = V_71 ;
V_34 = F_11 ( V_27 , V_29 , V_31 ) ;
break;
case V_85 :
V_29 -> V_65 . V_66 = 0x03 ;
V_29 -> V_67 . V_68 = V_33 -> V_69 . V_68 ;
V_29 -> V_74 = 0 ;
break;
case V_86 :
V_29 -> V_65 . V_66 = 0x02 ;
V_29 -> V_67 . V_68 = V_33 -> V_69 . V_68 ;
V_29 -> V_74 = V_48 ;
V_34 = F_11 ( V_27 , V_29 , V_31 ) ;
break;
default:
F_15 ( & V_31 -> V_2 -> V_87 ,
L_4 , V_47 ) ;
break;
}
V_29 -> V_67 . V_88 = 0x3 ;
if ( ( V_33 -> V_35 . V_89 == 0x2105 ||
V_33 -> V_35 . V_89 == 0x2107 ||
V_33 -> V_35 . V_89 == 0x1750 )
&& ! ( V_33 -> V_90 && V_45 < 2 ) )
V_29 -> V_38 |= 0x40 ;
V_49 = V_33 -> V_35 . V_91 ;
V_52 = V_45 / V_49 ;
V_50 = V_45 % V_49 ;
V_53 = V_46 / V_49 ;
V_51 = V_46 % V_49 ;
if ( V_29 -> V_67 . V_68 == V_92 ||
V_29 -> V_67 . V_68 == V_93 ) {
if ( V_53 + V_33 -> V_69 . V_94 < V_33 -> V_95 )
V_53 += V_33 -> V_69 . V_94 ;
else
V_53 = ( V_33 -> V_95 - 1 ) ;
}
F_10 ( & V_29 -> V_96 , V_52 , V_50 ) ;
F_10 ( & V_29 -> V_97 , V_53 , V_51 ) ;
return V_34 ;
}
static void F_16 ( struct V_26 * V_27 , struct V_98 * V_29 ,
unsigned int V_45 , unsigned int V_99 ,
int V_42 , int V_47 , struct V_30 * V_31 ,
unsigned int V_100 , unsigned int V_101 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
int V_102 ;
int V_18 , V_103 ;
if ( V_27 ) {
V_27 -> V_54 = V_104 ;
V_27 -> V_43 = 0 ;
if ( V_47 == V_85 )
V_27 -> V_42 = 22 ;
else
V_27 -> V_42 = 20 ;
V_27 -> V_56 = ( T_1 ) F_14 ( V_29 ) ;
}
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_102 = 0 ;
if ( V_99 ) {
switch ( V_33 -> V_35 . V_20 ) {
case 0x3390 :
V_18 = F_8 ( V_100 + 6 , 232 ) ;
V_103 = 9 + F_8 ( V_100 + 6 * ( V_18 + 1 ) , 34 ) ;
V_102 = ( 49 + ( V_99 - 1 ) * ( 10 + V_103 ) ) / 8 ;
break;
case 0x3380 :
V_103 = 7 + F_8 ( V_100 + 12 , 32 ) ;
V_102 = ( 39 + ( V_99 - 1 ) * ( 8 + V_103 ) ) / 7 ;
break;
}
}
V_29 -> V_102 = V_102 ;
V_29 -> V_42 = V_42 ;
switch ( V_47 ) {
case V_82 :
V_29 -> V_68 . V_105 = 0x3 ;
V_29 -> V_68 . V_68 = 0x03 ;
break;
case V_57 :
V_29 -> V_68 . V_105 = 0x3 ;
V_29 -> V_68 . V_68 = 0x16 ;
break;
case V_83 :
V_29 -> V_68 . V_105 = 0x1 ;
V_29 -> V_68 . V_68 = 0x03 ;
V_29 -> V_42 ++ ;
break;
case V_58 :
V_29 -> V_68 . V_105 = 0x3 ;
V_29 -> V_68 . V_68 = 0x16 ;
V_29 -> V_42 ++ ;
break;
case V_75 :
case V_76 :
case V_77 :
case V_78 :
V_29 -> V_106 . V_107 = 0x1 ;
V_29 -> V_108 = V_100 ;
V_29 -> V_68 . V_68 = 0x01 ;
break;
case V_79 :
case V_80 :
V_29 -> V_106 . V_107 = 0x1 ;
V_29 -> V_108 = V_100 ;
V_29 -> V_68 . V_68 = 0x03 ;
break;
case V_85 :
V_29 -> V_68 . V_105 = 0x0 ;
V_29 -> V_68 . V_68 = 0x3F ;
V_29 -> V_109 = 0x11 ;
V_29 -> V_108 = 0 ;
V_29 -> V_110 = 0x02 ;
if ( V_29 -> V_42 > 8 ) {
V_29 -> V_111 [ 0 ] = 0xFF ;
V_29 -> V_111 [ 1 ] = 0xFF ;
V_29 -> V_111 [ 1 ] <<= ( 16 - V_42 ) ;
} else {
V_29 -> V_111 [ 0 ] = 0xFF ;
V_29 -> V_111 [ 0 ] <<= ( 8 - V_42 ) ;
V_29 -> V_111 [ 1 ] = 0x00 ;
}
V_29 -> V_102 = 0xFF ;
break;
case V_86 :
V_29 -> V_106 . V_107 = 0x1 ;
V_29 -> V_108 = V_100 ;
V_29 -> V_68 . V_68 = 0x3F ;
V_29 -> V_109 = 0x23 ;
break;
case V_59 :
case V_60 :
case V_63 :
case V_64 :
V_29 -> V_106 . V_107 = 0x1 ;
V_29 -> V_108 = V_100 ;
V_29 -> V_68 . V_68 = 0x06 ;
break;
case V_61 :
case V_62 :
V_29 -> V_106 . V_107 = 0x1 ;
V_29 -> V_108 = V_100 ;
V_29 -> V_68 . V_68 = 0x16 ;
break;
case V_70 :
V_29 -> V_68 . V_68 = 0x06 ;
break;
case V_72 :
V_29 -> V_68 . V_105 = 0x1 ;
V_29 -> V_68 . V_68 = 0x0C ;
V_29 -> V_110 = 0 ;
V_29 -> V_102 = 0xFF ;
break;
case V_73 :
V_29 -> V_106 . V_107 = 0x1 ;
V_29 -> V_108 = V_101 ;
V_29 -> V_68 . V_68 = 0x0C ;
break;
case V_81 :
V_29 -> V_108 = V_100 ;
V_29 -> V_106 . V_107 = 0x1 ;
V_29 -> V_68 . V_68 = 0x0b ;
break;
default:
F_17 ( V_112 , V_31 ,
L_5 , V_47 ) ;
F_18 () ;
}
F_10 ( & V_29 -> V_113 ,
V_45 / V_33 -> V_35 . V_91 ,
V_45 % V_33 -> V_35 . V_91 ) ;
V_29 -> V_114 . V_23 = V_29 -> V_113 . V_23 ;
V_29 -> V_114 . V_24 = V_29 -> V_113 . V_24 ;
V_29 -> V_114 . V_115 = V_99 ;
}
static int F_19 ( struct V_26 * V_27 , struct V_116 * V_117 ,
unsigned int V_45 , unsigned int V_46 , int V_47 ,
struct V_30 * V_118 , struct V_30 * V_119 ,
unsigned int V_120 , unsigned int V_99 , int V_42 ,
unsigned int V_48 , unsigned int V_101 )
{
struct V_32 * V_121 , * V_122 ;
struct V_98 * V_123 ;
struct V_28 * V_124 ;
int V_34 = 0 ;
V_121 = V_118 -> V_33 ;
V_122 = V_119 -> V_33 ;
V_124 = & V_117 -> F_13 ;
V_123 = & V_117 -> V_125 ;
V_27 -> V_54 = V_126 ;
V_27 -> V_43 = 0 ;
if ( V_47 == V_85 ) {
V_27 -> V_42 = sizeof( * V_117 ) + 2 ;
V_27 -> V_56 = ( T_1 ) F_14 ( V_117 ) ;
memset ( V_117 , 0 , sizeof( * V_117 ) + 2 ) ;
} else {
V_27 -> V_42 = sizeof( * V_117 ) ;
V_27 -> V_56 = ( T_1 ) F_14 ( V_117 ) ;
memset ( V_117 , 0 , sizeof( * V_117 ) ) ;
}
if ( V_120 > 1 ) {
F_17 ( V_112 , V_118 ,
L_6 , V_120 ) ;
F_18 () ;
return - V_127 ;
}
V_117 -> V_120 = V_120 ;
V_117 -> V_128 = V_121 -> V_129 -> V_130 ;
V_117 -> V_131 = V_121 -> V_129 -> V_132 ;
V_117 -> V_133 . F_13 = 1 ;
if ( V_122 -> V_134 . type != V_135 ) {
V_117 -> V_133 . V_136 = 1 ;
if ( V_122 -> V_134 . type == V_137 )
V_117 -> V_133 . V_138 = 1 ;
}
V_34 = F_13 ( NULL , V_124 , V_45 , V_46 , V_47 , V_118 , V_48 ) ;
if ( V_124 -> V_38 & 0x08 && V_124 -> V_38 & 0x02 )
V_117 -> V_133 . V_139 = 1 ;
if ( V_120 == 1 ) {
F_16 ( NULL , V_123 , V_45 , V_99 , V_42 , V_47 ,
V_118 , V_48 , V_101 ) ;
}
return V_34 ;
}
static int F_20 ( struct V_26 * V_27 , struct V_116 * V_117 ,
unsigned int V_45 , unsigned int V_46 , int V_47 ,
struct V_30 * V_118 , struct V_30 * V_119 )
{
return F_19 ( V_27 , V_117 , V_45 , V_46 , V_47 , V_118 , V_119 ,
0 , 0 , 0 , 0 , 0 ) ;
}
static void
V_125 ( struct V_26 * V_27 , struct V_140 * V_29 , unsigned int V_45 ,
unsigned int V_99 , int V_141 , int V_47 ,
struct V_30 * V_31 , int V_100 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
int V_102 ;
int V_18 , V_103 ;
F_17 ( V_142 , V_31 ,
L_7 ,
V_45 , V_99 , V_141 , V_47 , V_100 ) ;
V_27 -> V_54 = V_143 ;
V_27 -> V_43 = 0 ;
V_27 -> V_42 = 16 ;
V_27 -> V_56 = ( T_1 ) F_14 ( V_29 ) ;
memset ( V_29 , 0 , sizeof( struct V_140 ) ) ;
V_102 = 0 ;
if ( V_99 ) {
switch ( V_33 -> V_35 . V_20 ) {
case 0x3390 :
V_18 = F_8 ( V_100 + 6 , 232 ) ;
V_103 = 9 + F_8 ( V_100 + 6 * ( V_18 + 1 ) , 34 ) ;
V_102 = ( 49 + ( V_99 - 1 ) * ( 10 + V_103 ) ) / 8 ;
break;
case 0x3380 :
V_103 = 7 + F_8 ( V_100 + 12 , 32 ) ;
V_102 = ( 39 + ( V_99 - 1 ) * ( 8 + V_103 ) ) / 7 ;
break;
}
}
V_29 -> V_102 = V_102 ;
V_29 -> V_42 = V_141 ;
switch ( V_47 ) {
case V_82 :
V_29 -> V_68 . V_105 = 0x3 ;
V_29 -> V_68 . V_68 = 0x03 ;
break;
case V_57 :
V_29 -> V_68 . V_105 = 0x3 ;
V_29 -> V_68 . V_68 = 0x16 ;
break;
case V_83 :
V_29 -> V_68 . V_105 = 0x1 ;
V_29 -> V_68 . V_68 = 0x03 ;
V_29 -> V_42 ++ ;
break;
case V_58 :
V_29 -> V_68 . V_105 = 0x3 ;
V_29 -> V_68 . V_68 = 0x16 ;
V_29 -> V_42 ++ ;
break;
case V_75 :
case V_76 :
case V_77 :
case V_78 :
V_29 -> V_106 . V_144 = 0x1 ;
V_29 -> V_108 = V_100 ;
V_29 -> V_68 . V_68 = 0x01 ;
break;
case V_79 :
case V_80 :
V_29 -> V_106 . V_144 = 0x1 ;
V_29 -> V_108 = V_100 ;
V_29 -> V_68 . V_68 = 0x03 ;
break;
case V_59 :
case V_60 :
case V_63 :
case V_64 :
V_29 -> V_106 . V_144 = 0x1 ;
V_29 -> V_108 = V_100 ;
V_29 -> V_68 . V_68 = 0x06 ;
break;
case V_61 :
case V_62 :
V_29 -> V_106 . V_144 = 0x1 ;
V_29 -> V_108 = V_100 ;
V_29 -> V_68 . V_68 = 0x16 ;
break;
case V_70 :
V_29 -> V_68 . V_68 = 0x06 ;
break;
case V_81 :
V_29 -> V_108 = V_100 ;
V_29 -> V_106 . V_144 = 0x1 ;
V_29 -> V_68 . V_68 = 0x0b ;
break;
default:
F_17 ( V_112 , V_31 , L_8
L_9 , V_47 ) ;
}
F_10 ( & V_29 -> V_113 ,
V_45 / V_33 -> V_35 . V_91 ,
V_45 % V_33 -> V_35 . V_91 ) ;
V_29 -> V_114 . V_23 = V_29 -> V_113 . V_23 ;
V_29 -> V_114 . V_24 = V_29 -> V_113 . V_24 ;
V_29 -> V_114 . V_115 = V_99 ;
}
static inline int
F_21 ( int V_145 , int V_146 )
{
if ( V_146 < 3 )
return 1 ;
if ( V_146 < V_145 )
return 0 ;
if ( V_146 < 2 * V_145 )
return 1 ;
return 0 ;
}
static inline int
F_22 ( int V_146 )
{
if ( V_146 < 3 )
return V_147 [ V_146 ] ;
return V_148 ;
}
static void F_23 ( struct V_32 * V_33 )
{
int V_42 ;
struct V_149 * V_134 ;
V_134 = & V_33 -> V_134 ;
memset ( V_134 , 0 , sizeof( struct V_149 ) ) ;
memcpy ( V_134 -> V_150 , V_33 -> V_129 -> V_151 ,
sizeof( V_134 -> V_150 ) - 1 ) ;
F_24 ( V_134 -> V_150 , sizeof( V_134 -> V_150 ) - 1 ) ;
memcpy ( V_134 -> V_152 , V_33 -> V_129 -> V_153 ,
sizeof( V_134 -> V_152 ) - 1 ) ;
F_24 ( V_134 -> V_152 , sizeof( V_134 -> V_152 ) - 1 ) ;
V_134 -> V_154 = V_33 -> V_155 -> V_156 ;
V_134 -> V_157 = V_33 -> V_129 -> V_130 ;
if ( V_33 -> V_158 ) {
V_134 -> type = V_33 -> V_158 -> V_159 ;
if ( V_134 -> type == V_160 )
V_134 -> V_161 = V_33 -> V_158 -> V_161 ;
} else {
V_134 -> type = V_135 ;
}
if ( V_33 -> V_162 ) {
for ( V_42 = 0 ; V_42 < 16 ; V_42 ++ ) {
sprintf ( V_134 -> V_163 + 2 * V_42 , L_10 ,
V_33 -> V_162 -> V_164 [ V_42 ] ) ;
}
}
}
static int F_25 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
unsigned long V_43 ;
if ( ! V_33 )
return - V_165 ;
if ( ! V_33 -> V_129 || ! V_33 -> V_155 )
return - V_165 ;
F_26 ( F_27 ( V_31 -> V_2 ) , V_43 ) ;
F_23 ( V_33 ) ;
F_28 ( F_27 ( V_31 -> V_2 ) , V_43 ) ;
return 0 ;
}
static int F_29 ( struct V_30 * V_31 , struct V_149 * V_134 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
unsigned long V_43 ;
if ( V_33 ) {
F_26 ( F_27 ( V_31 -> V_2 ) , V_43 ) ;
* V_134 = V_33 -> V_134 ;
F_28 ( F_27 ( V_31 -> V_2 ) , V_43 ) ;
return 0 ;
}
return - V_127 ;
}
static int F_30 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
struct V_149 V_166 ;
F_23 ( V_33 ) ;
F_29 ( V_31 , & V_166 ) ;
return memcmp ( & V_166 , & V_33 -> V_134 , sizeof( struct V_149 ) ) ;
}
static void F_31 ( struct V_30 * V_31 ,
struct V_167 * V_168 ,
T_2 * V_169 ,
T_2 V_170 )
{
struct V_26 * V_27 ;
V_169 [ 0 ] = 0xE5 ;
V_169 [ 1 ] = 0xF1 ;
V_169 [ 2 ] = 0x4B ;
V_169 [ 3 ] = 0xF0 ;
V_27 = V_168 -> V_171 ;
V_27 -> V_54 = V_172 ;
V_27 -> V_43 = 0 ;
V_27 -> V_56 = ( T_1 ) ( V_173 ) V_169 ;
V_27 -> V_42 = V_174 ;
V_168 -> V_175 = V_176 ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_178 = NULL ;
V_168 -> V_179 = 10 * V_180 ;
V_168 -> V_170 = V_170 ;
V_168 -> V_181 = 256 ;
V_168 -> V_182 = F_32 () ;
V_168 -> V_183 = V_184 ;
F_33 ( V_185 , & V_168 -> V_43 ) ;
}
static void F_34 ( struct V_167 * V_168 , void * V_29 )
{
struct V_26 * V_27 ;
T_2 * V_169 ;
if ( V_168 -> V_183 != V_186 ) {
V_27 = V_168 -> V_171 ;
V_169 = ( T_2 * ) ( ( V_173 ) V_27 -> V_56 ) ;
memset ( V_169 , 0 , sizeof( * V_169 ) ) ;
V_169 [ 0 ] = 0xE5 ;
V_169 [ 1 ] = 0xF1 ;
V_169 [ 2 ] = 0x4B ;
V_169 [ 3 ] = 0xF0 ;
}
F_35 ( V_168 , V_29 ) ;
}
static int F_36 ( struct V_30 * V_31 ,
struct V_167 * V_168 ,
T_2 * V_169 ,
T_2 V_170 )
{
struct V_187 * V_187 ;
int V_34 ;
V_187 = F_37 ( V_31 -> V_2 , V_188 ) ;
if ( ! V_187 || V_187 -> V_47 != V_172 )
return - V_40 ;
F_31 ( V_31 , V_168 , V_169 , V_170 ) ;
F_38 ( V_189 , & V_168 -> V_43 ) ;
F_33 ( V_190 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 5 ;
V_168 -> V_191 = F_34 ;
V_34 = F_39 ( V_168 ) ;
return V_34 ;
}
static int F_40 ( struct V_30 * V_31 ,
void * * V_169 ,
int * V_192 , T_2 V_170 )
{
struct V_187 * V_187 ;
char * V_193 = NULL ;
int V_3 ;
struct V_167 * V_168 ;
V_187 = F_37 ( V_31 -> V_2 , V_188 ) ;
if ( ! V_187 || V_187 -> V_47 != V_172 ) {
V_3 = - V_40 ;
goto V_194;
}
V_193 = F_41 ( V_174 , V_195 | V_196 ) ;
if ( ! V_193 ) {
V_3 = - V_197 ;
goto V_194;
}
V_168 = F_42 ( V_176 , 1 ,
0 ,
V_31 ) ;
if ( F_43 ( V_168 ) ) {
F_17 ( V_7 , V_31 , L_1 ,
L_11 ) ;
V_3 = - V_197 ;
goto V_194;
}
F_31 ( V_31 , V_168 , V_193 , V_170 ) ;
V_168 -> V_191 = F_34 ;
V_3 = F_44 ( V_168 ) ;
F_45 ( V_168 , V_168 -> V_177 ) ;
if ( V_3 )
goto V_194;
* V_192 = V_174 ;
* V_169 = V_193 ;
return 0 ;
V_194:
F_46 ( V_193 ) ;
* V_169 = NULL ;
* V_192 = 0 ;
return V_3 ;
}
static int F_47 ( struct V_32 * V_33 )
{
struct V_198 * V_158 ;
int V_199 , V_42 ;
V_33 -> V_129 = NULL ;
V_33 -> V_158 = NULL ;
V_33 -> V_162 = NULL ;
V_33 -> V_155 = NULL ;
V_42 = V_33 -> V_200 / sizeof( struct V_198 ) ;
V_158 = (struct V_198 * ) V_33 -> V_201 ;
for ( V_199 = 0 ; V_199 < V_42 ; ++ V_199 ) {
if ( V_158 -> V_43 . V_202 == 1 && V_158 -> V_120 == 1 )
V_33 -> V_158 = V_158 ;
else if ( V_158 -> V_43 . V_202 == 1 && V_158 -> V_120 == 4 )
V_33 -> V_162 = (struct V_203 * ) V_158 ;
else if ( V_158 -> V_43 . V_202 == 2 )
V_33 -> V_155 = (struct V_204 * ) V_158 ;
else if ( V_158 -> V_43 . V_202 == 3 && V_158 -> V_205 == 1 )
V_33 -> V_129 = (struct V_206 * ) V_158 ;
V_158 ++ ;
}
if ( ! V_33 -> V_129 || ! V_33 -> V_155 ) {
V_33 -> V_129 = NULL ;
V_33 -> V_158 = NULL ;
V_33 -> V_162 = NULL ;
V_33 -> V_155 = NULL ;
return - V_127 ;
}
return 0 ;
}
static unsigned char F_48 ( void * V_201 , int V_200 )
{
struct V_204 * V_155 ;
int V_199 , V_42 , V_207 ;
V_42 = V_200 / sizeof( * V_155 ) ;
V_155 = (struct V_204 * ) V_201 ;
V_207 = 0 ;
for ( V_199 = 0 ; V_199 < V_42 ; ++ V_199 ) {
if ( V_155 -> V_43 . V_202 == 2 ) {
V_207 = 1 ;
break;
}
V_155 ++ ;
}
if ( V_207 )
return ( ( char * ) V_155 ) [ 18 ] & 0x07 ;
else
return 0 ;
}
static void F_49 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
int V_199 ;
V_33 -> V_201 = NULL ;
V_33 -> V_200 = 0 ;
for ( V_199 = 0 ; V_199 < 8 ; V_199 ++ ) {
F_46 ( V_31 -> V_208 [ V_199 ] . V_201 ) ;
V_31 -> V_208 [ V_199 ] . V_201 = NULL ;
V_31 -> V_208 [ V_199 ] . V_209 = 0 ;
V_31 -> V_208 [ V_199 ] . V_154 = 0 ;
V_31 -> V_208 [ V_199 ] . V_210 = 0 ;
}
}
static int F_50 ( struct V_30 * V_31 )
{
void * V_201 ;
int V_200 , V_211 ;
int V_34 , V_212 , V_213 ;
T_2 V_170 , V_214 ;
struct V_32 * V_33 , V_215 ;
struct V_149 * V_134 ;
char V_216 [ 60 ] , V_217 [ 60 ] ;
struct V_218 * V_219 ;
struct V_220 V_221 ;
V_33 = V_31 -> V_33 ;
V_214 = F_51 ( V_31 -> V_2 ) ;
F_52 ( V_31 -> V_2 , & V_221 ) ;
V_211 = 0 ;
V_212 = 0 ;
for ( V_170 = 0x80 ; V_170 ; V_170 >>= 1 ) {
if ( ! ( V_170 & V_214 ) )
continue;
V_34 = F_40 ( V_31 , & V_201 ,
& V_200 , V_170 ) ;
if ( V_34 && V_34 != - V_40 ) {
F_3 ( V_7 , V_31 -> V_2 ,
L_12
L_13 , V_34 ) ;
return V_34 ;
}
if ( V_201 == NULL ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_14
L_15 ) ;
F_53 ( V_31 , V_214 ) ;
continue;
}
if ( ! V_211 ) {
F_49 ( V_31 ) ;
V_33 -> V_201 = V_201 ;
V_33 -> V_200 = V_200 ;
if ( F_47 ( V_33 ) ) {
V_33 -> V_201 = NULL ;
V_33 -> V_200 = 0 ;
F_46 ( V_201 ) ;
continue;
}
V_213 = F_54 ( V_170 ) ;
V_31 -> V_208 [ V_213 ] . V_201 = V_201 ;
V_31 -> V_208 [ V_213 ] . V_209 = V_221 . V_209 ;
V_31 -> V_208 [ V_213 ] . V_154 = V_221 . V_154 ;
V_219 = F_55 ( V_31 -> V_2 , V_213 ) ;
if ( V_219 )
V_31 -> V_208 [ V_213 ] . V_210 = V_219 -> V_210 ;
F_46 ( V_219 ) ;
F_25 ( V_31 ) ;
V_211 ++ ;
} else {
V_215 . V_201 = V_201 ;
V_215 . V_200 = V_174 ;
if ( F_47 (
& V_215 ) ) {
V_215 . V_201 = NULL ;
V_215 . V_200 = 0 ;
F_46 ( V_201 ) ;
continue;
}
if ( F_30 (
V_31 , & V_215 ) ) {
V_134 = & V_215 . V_134 ;
if ( strlen ( V_134 -> V_163 ) > 0 )
snprintf ( V_216 ,
sizeof( V_216 ) ,
L_16 ,
V_134 -> V_150 , V_134 -> V_152 ,
V_134 -> V_154 , V_134 -> V_157 ,
V_134 -> V_163 ) ;
else
snprintf ( V_216 ,
sizeof( V_216 ) ,
L_17 ,
V_134 -> V_150 , V_134 -> V_152 ,
V_134 -> V_154 ,
V_134 -> V_157 ) ;
V_134 = & V_33 -> V_134 ;
if ( strlen ( V_134 -> V_163 ) > 0 )
snprintf ( V_217 ,
sizeof( V_217 ) ,
L_16 ,
V_134 -> V_150 , V_134 -> V_152 ,
V_134 -> V_154 , V_134 -> V_157 ,
V_134 -> V_163 ) ;
else
snprintf ( V_217 ,
sizeof( V_217 ) ,
L_17 ,
V_134 -> V_150 , V_134 -> V_152 ,
V_134 -> V_154 ,
V_134 -> V_157 ) ;
F_15 ( & V_31 -> V_2 -> V_87 ,
L_18
L_19
L_20 , V_170 ,
V_216 , V_217 ) ;
V_212 = - V_127 ;
F_56 ( V_31 , V_170 ) ;
continue;
}
V_213 = F_54 ( V_170 ) ;
V_31 -> V_208 [ V_213 ] . V_201 = V_201 ;
V_31 -> V_208 [ V_213 ] . V_209 = V_221 . V_209 ;
V_31 -> V_208 [ V_213 ] . V_154 = V_221 . V_154 ;
V_219 = F_55 ( V_31 -> V_2 , V_213 ) ;
if ( V_219 )
V_31 -> V_208 [ V_213 ] . V_210 = V_219 -> V_210 ;
F_46 ( V_219 ) ;
V_215 . V_201 = NULL ;
V_215 . V_200 = 0 ;
}
switch ( F_48 ( V_201 , V_200 ) ) {
case 0x02 :
F_57 ( V_31 , V_170 ) ;
break;
case 0x03 :
F_58 ( V_31 , V_170 ) ;
break;
}
if ( ! F_59 ( V_31 ) ) {
F_60 ( V_31 , V_170 ) ;
F_61 ( V_31 ) ;
} else {
F_53 ( V_31 , V_170 ) ;
}
}
return V_212 ;
}
static T_4 F_62 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
int V_222 , V_223 , V_224 ;
int V_225 , V_226 ;
if ( V_227 )
return 0 ;
V_222 = V_228 . V_229 ;
V_223 = V_33 -> V_155 -> V_230 [ 7 ] & 0x04 ;
V_224 = V_33 -> V_231 . V_232 [ 40 ] & 0x80 ;
V_225 = V_222 && V_223 && V_224 ;
if ( ! V_225 )
return 0 ;
V_226 = F_63 ( V_31 -> V_2 , 0 ) ;
if ( V_226 < 0 ) {
F_64 ( & V_31 -> V_2 -> V_87 , L_21 ) ;
return 0 ;
} else {
return ( T_4 ) V_226 * V_233 ;
}
}
static int F_65 ( struct V_30 * V_31 , T_2 V_170 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
int V_226 ;
T_4 V_234 ;
if ( V_33 -> V_234 ) {
V_226 = F_63 ( V_31 -> V_2 , V_170 ) ;
if ( ( V_226 < 0 ) ) {
F_64 ( & V_31 -> V_2 -> V_87 ,
L_22
L_23 ,
V_226 , V_170 ) ;
return V_226 ;
}
V_234 = ( T_4 ) V_226 * V_233 ;
if ( V_234 < V_33 -> V_234 ) {
F_64 ( & V_31 -> V_2 -> V_87 ,
L_24
L_25
L_26 , V_234 , V_170 ,
V_33 -> V_234 ) ;
return - V_41 ;
}
}
return 0 ;
}
static int F_66 ( struct V_30 * V_31 ,
struct V_235 * V_29 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
T_2 V_170 , V_214 = F_59 ( V_31 ) ;
int V_34 = - V_165 ;
for ( V_170 = 0x80 ; V_170 ; V_170 >>= 1 ) {
if ( ! ( V_170 & V_214 ) )
continue;
memset ( & V_29 -> V_169 , 0 , sizeof( V_29 -> V_169 ) ) ;
memset ( & V_29 -> V_168 , 0 , sizeof( V_29 -> V_168 ) ) ;
V_29 -> V_168 . V_171 = & V_29 -> V_27 ;
V_34 = F_36 ( V_31 , & V_29 -> V_168 ,
V_29 -> V_169 ,
V_170 ) ;
if ( V_34 ) {
if ( V_34 == - V_40 )
continue;
F_3 ( V_7 , V_31 -> V_2 ,
L_27
L_28 , V_34 ) ;
break;
}
memcpy ( V_33 -> V_201 , V_29 -> V_169 ,
V_174 ) ;
if ( F_47 ( V_33 ) ) {
V_34 = - V_165 ;
} else
break;
}
if ( ! V_34 )
V_34 = F_25 ( V_31 ) ;
return V_34 ;
}
static void F_67 ( struct V_236 * V_237 )
{
struct V_235 * V_29 ;
struct V_30 * V_31 ;
struct V_32 V_215 ;
struct V_149 * V_134 ;
T_2 V_238 [ V_174 ] ;
T_2 V_170 , V_214 , V_239 , V_240 , V_241 , V_242 , V_243 ;
unsigned long V_43 ;
char V_244 [ 60 ] ;
int V_34 ;
V_29 = F_68 ( V_237 , struct V_235 , V_245 ) ;
V_31 = V_29 -> V_31 ;
if ( F_69 ( V_246 , & V_31 -> V_43 ) ) {
F_70 ( V_237 ) ;
return;
}
if ( F_71 ( V_247 , & V_31 -> V_43 ) ) {
F_70 ( V_237 ) ;
return;
}
V_214 = 0 ;
V_239 = 0 ;
V_240 = 0 ;
V_241 = 0 ;
V_242 = 0 ;
V_243 = 0 ;
for ( V_170 = 0x80 ; V_170 ; V_170 >>= 1 ) {
if ( ! ( V_170 & V_29 -> V_248 ) )
continue;
memset ( & V_29 -> V_169 , 0 , sizeof( V_29 -> V_169 ) ) ;
memset ( & V_29 -> V_168 , 0 , sizeof( V_29 -> V_168 ) ) ;
V_29 -> V_168 . V_171 = & V_29 -> V_27 ;
V_34 = F_36 ( V_31 , & V_29 -> V_168 ,
V_29 -> V_169 ,
V_170 ) ;
if ( ! V_34 ) {
switch ( F_48 ( V_29 -> V_169 ,
V_174 )
) {
case 0x02 :
V_239 |= V_170 ;
break;
case 0x03 :
V_240 |= V_170 ;
break;
}
V_214 |= V_170 ;
} else if ( V_34 == - V_40 ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_29
L_30 ) ;
V_214 |= V_170 ;
} else if ( V_34 == - V_249 ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_31
L_32 ) ;
V_241 |= V_170 ;
} else {
F_64 ( & V_31 -> V_2 -> V_87 ,
L_33
L_34 , V_34 , V_170 ) ;
continue;
}
if ( F_65 ( V_31 , V_170 ) ) {
V_214 &= ~ V_170 ;
V_239 &= ~ V_170 ;
V_240 &= ~ V_170 ;
V_242 |= V_170 ;
continue;
}
memcpy ( & V_238 , V_29 -> V_169 ,
V_174 ) ;
V_215 . V_201 = ( void * ) & V_238 ;
V_215 . V_200 = V_174 ;
if ( F_47 ( & V_215 ) ) {
V_215 . V_201 = NULL ;
V_215 . V_200 = 0 ;
continue;
}
if ( F_59 ( V_31 ) &&
F_30 ( V_31 , & V_215 ) ) {
if ( F_66 ( V_31 , V_29 ) ||
F_30 (
V_31 , & V_215 ) ) {
V_134 = & V_215 . V_134 ;
if ( strlen ( V_134 -> V_163 ) > 0 )
snprintf ( V_244 , sizeof( V_244 ) ,
L_16 ,
V_134 -> V_150 , V_134 -> V_152 ,
V_134 -> V_154 , V_134 -> V_157 ,
V_134 -> V_163 ) ;
else
snprintf ( V_244 , sizeof( V_244 ) ,
L_17 ,
V_134 -> V_150 , V_134 -> V_152 ,
V_134 -> V_154 ,
V_134 -> V_157 ) ;
F_15 ( & V_31 -> V_2 -> V_87 ,
L_35
L_36
L_37 ,
V_170 , V_244 ) ;
V_214 &= ~ V_170 ;
V_239 &= ~ V_170 ;
V_240 &= ~ V_170 ;
V_243 |= V_170 ;
continue;
}
}
F_26 ( F_27 ( V_31 -> V_2 ) , V_43 ) ;
if ( ! F_59 ( V_31 ) && V_214 ) {
F_60 ( V_31 , V_214 ) ;
F_61 ( V_31 ) ;
} else {
F_53 ( V_31 , V_214 ) ;
}
F_57 ( V_31 , V_239 ) ;
F_58 ( V_31 , V_240 ) ;
F_72 ( V_31 , V_241 ) ;
F_56 ( V_31 , V_243 ) ;
F_73 ( V_31 , V_242 ) ;
F_28 ( F_27 ( V_31 -> V_2 ) , V_43 ) ;
}
F_38 ( V_247 , & V_31 -> V_43 ) ;
F_74 ( V_31 ) ;
if ( V_29 -> V_250 )
F_75 ( & V_251 ) ;
else
F_46 ( V_29 ) ;
}
static int F_76 ( struct V_30 * V_31 , T_2 V_170 )
{
struct V_235 * V_29 ;
V_29 = F_77 ( sizeof( * V_29 ) , V_252 | V_196 ) ;
if ( ! V_29 ) {
if ( F_78 ( & V_251 ) ) {
V_29 = V_253 ;
V_29 -> V_250 = 1 ;
} else
return - V_197 ;
} else {
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_29 -> V_250 = 0 ;
}
F_79 ( & V_29 -> V_245 , F_67 ) ;
F_80 ( V_31 ) ;
V_29 -> V_31 = V_31 ;
V_29 -> V_248 = V_170 ;
F_70 ( & V_29 -> V_245 ) ;
return 0 ;
}
static void F_81 ( struct V_30 * V_31 , T_2 V_254 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
unsigned long V_43 ;
if ( ! V_33 -> V_234 )
V_33 -> V_234 = F_62 ( V_31 ) ;
F_26 ( F_27 ( V_31 -> V_2 ) , V_43 ) ;
F_82 ( V_31 , V_254 ? : F_83 ( V_31 ) ) ;
F_84 ( V_31 ) ;
F_28 ( F_27 ( V_31 -> V_2 ) , V_43 ) ;
}
static int F_85 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_255 * V_256 ;
struct V_257 * V_231 ;
struct V_167 * V_168 ;
struct V_26 * V_27 ;
int V_34 ;
memset ( & V_33 -> V_231 , 0 , sizeof( struct V_257 ) ) ;
V_168 = F_42 ( V_176 , 1 + 1 ,
( sizeof( struct V_255 ) +
sizeof( struct V_257 ) ) ,
V_31 ) ;
if ( F_43 ( V_168 ) ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 , L_38
L_39 ) ;
return F_86 ( V_168 ) ;
}
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_178 = NULL ;
V_168 -> V_181 = 256 ;
V_168 -> V_179 = 10 * V_180 ;
V_256 = (struct V_255 * ) V_168 -> V_29 ;
memset ( V_256 , 0 , sizeof( struct V_255 ) ) ;
V_256 -> V_258 = V_259 ;
V_256 -> V_260 = 0x41 ;
V_27 = V_168 -> V_171 ;
V_27 -> V_54 = V_261 ;
V_27 -> V_42 = sizeof( struct V_255 ) ;
V_27 -> V_43 |= V_262 ;
V_27 -> V_56 = ( T_1 ) ( V_173 ) V_256 ;
V_231 = (struct V_257 * ) ( V_256 + 1 ) ;
memset ( V_231 , 0 , sizeof( struct V_257 ) ) ;
V_27 ++ ;
V_27 -> V_54 = V_263 ;
V_27 -> V_42 = sizeof( struct V_257 ) ;
V_27 -> V_56 = ( T_1 ) ( V_173 ) V_231 ;
V_168 -> V_182 = F_32 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_44 ( V_168 ) ;
if ( V_34 == 0 ) {
V_256 = (struct V_255 * ) V_168 -> V_29 ;
V_231 = (struct V_257 * ) ( V_256 + 1 ) ;
memcpy ( & V_33 -> V_231 , V_231 ,
sizeof( struct V_257 ) ) ;
} else
F_64 ( & V_31 -> V_2 -> V_87 , L_40
L_41 , V_34 ) ;
F_45 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static struct V_167 * F_87 ( struct V_30 * V_31 ,
int V_264 )
{
struct V_167 * V_168 ;
struct V_265 * V_266 ;
struct V_26 * V_27 ;
V_168 = F_42 ( V_176 , 1 ,
sizeof( struct V_265 ) ,
V_31 ) ;
if ( F_43 ( V_168 ) ) {
F_17 ( V_7 , V_31 , L_1 ,
L_42 ) ;
return V_168 ;
}
V_266 = (struct V_265 * ) V_168 -> V_29 ;
V_266 -> V_258 = V_267 ;
V_266 -> V_260 = 0xc0 ;
if ( V_264 ) {
V_266 -> V_260 |= 0x08 ;
V_266 -> V_268 [ 0 ] = 0x88 ;
}
V_27 = V_168 -> V_171 ;
V_27 -> V_54 = V_261 ;
V_27 -> V_56 = ( T_1 ) ( V_173 ) V_266 ;
V_27 -> V_42 = 66 ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_178 = NULL ;
V_168 -> V_181 = 256 ;
V_168 -> V_179 = 10 * V_180 ;
V_168 -> V_182 = F_32 () ;
V_168 -> V_183 = V_184 ;
return V_168 ;
}
static int
F_88 ( struct V_30 * V_31 , int V_264 ,
unsigned long V_43 )
{
struct V_167 * V_168 ;
int V_34 ;
V_168 = F_87 ( V_31 , V_264 ) ;
if ( F_43 ( V_168 ) )
return F_86 ( V_168 ) ;
V_168 -> V_43 |= V_43 ;
V_34 = F_44 ( V_168 ) ;
if ( ! V_34 )
F_89 () ;
else if ( V_168 -> V_269 == - V_249 )
V_34 = - V_249 ;
F_45 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int F_90 ( struct V_30 * V_31 ,
unsigned long V_43 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
int V_264 , V_34 ;
if ( V_33 -> V_134 . type == V_160 ||
V_33 -> V_134 . type == V_137 )
return 0 ;
if ( V_270 || V_271 )
V_264 = 0 ;
else
V_264 = 1 ;
V_34 = F_88 ( V_31 , V_264 , V_43 ) ;
F_3 ( V_7 , V_31 -> V_2 , L_43
L_44 , V_33 -> V_134 . V_154 , V_34 ) ;
return V_34 ;
}
static void F_91 ( struct V_236 * V_237 )
{
struct V_30 * V_31 = F_68 ( V_237 , struct V_30 ,
V_272 ) ;
unsigned long V_43 = 0 ;
F_33 ( V_273 , & V_43 ) ;
if ( F_90 ( V_31 , V_43 )
== - V_249 ) {
F_70 ( & V_31 -> V_272 ) ;
return;
}
F_74 ( V_31 ) ;
}
static void F_92 ( struct V_30 * V_31 )
{
F_80 ( V_31 ) ;
if ( F_69 ( V_274 , & V_31 -> V_43 ) ||
V_31 -> V_275 < V_276 ) {
F_74 ( V_31 ) ;
return;
}
if ( ! F_70 ( & V_31 -> V_272 ) )
F_74 ( V_31 ) ;
}
static int
F_93 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_277 * V_178 ;
struct V_149 V_278 ;
int V_34 , V_199 ;
int V_279 ;
unsigned long V_280 ;
F_79 ( & V_31 -> V_272 , F_91 ) ;
F_79 ( & V_31 -> V_281 , V_282 ) ;
if ( ! F_94 ( V_31 -> V_2 ) ) {
F_64 ( & V_31 -> V_2 -> V_87 ,
L_45 ) ;
return - V_283 ;
}
if ( ! F_95 ( V_31 -> V_2 ) ) {
F_96 ( & V_31 -> V_2 -> V_87 ,
L_46 ) ;
}
if ( ! V_33 ) {
V_33 = F_41 ( sizeof( * V_33 ) , V_195 | V_196 ) ;
if ( ! V_33 ) {
F_64 ( & V_31 -> V_2 -> V_87 ,
L_47
L_48 ) ;
return - V_197 ;
}
V_31 -> V_33 = V_33 ;
} else {
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
}
V_33 -> V_284 = - 1 ;
V_33 -> V_69 . V_68 = V_285 ;
V_33 -> V_69 . V_94 = 0 ;
V_34 = F_50 ( V_31 ) ;
if ( V_34 )
goto V_286;
V_31 -> V_287 = V_288 ;
V_31 -> V_289 = V_290 ;
V_31 -> V_291 = V_292 ;
V_31 -> V_293 = V_294 ;
if ( V_33 -> V_155 ) {
V_280 = 1 ;
for ( V_199 = 0 ; V_199 < V_33 -> V_155 -> V_295 . V_280 ; V_199 ++ )
V_280 = 10 * V_280 ;
V_280 = V_280 * V_33 -> V_155 -> V_295 . V_296 ;
if ( V_280 != 0 && V_280 <= V_297 )
V_31 -> V_287 = V_280 ;
}
F_29 ( V_31 , & V_278 ) ;
if ( V_278 . type == V_135 ) {
V_178 = F_97 () ;
if ( F_43 ( V_178 ) ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_49
L_50 ) ;
V_34 = F_86 ( V_178 ) ;
goto V_286;
}
V_31 -> V_178 = V_178 ;
V_178 -> V_298 = V_31 ;
}
V_34 = F_98 ( V_31 ) ;
if ( V_34 )
goto V_299;
F_90 ( V_31 , 0 ) ;
V_34 = F_50 ( V_31 ) ;
if ( V_34 )
goto V_300;
F_85 ( V_31 ) ;
V_34 = F_99 ( V_31 , V_176 ,
& V_33 -> V_35 , 64 ) ;
if ( V_34 ) {
F_3 ( V_7 , V_31 -> V_2 ,
L_51 , V_34 ) ;
goto V_300;
}
if ( ( V_31 -> V_231 & V_301 ) &&
! ( V_33 -> V_35 . V_36 . V_302 ) ) {
F_15 ( & V_31 -> V_2 -> V_87 , L_52
L_53 ) ;
V_34 = - V_127 ;
goto V_300;
}
if ( V_33 -> V_35 . V_303 == V_304 &&
V_33 -> V_35 . V_305 )
V_33 -> V_95 = V_33 -> V_35 . V_305 ;
else
V_33 -> V_95 = V_33 -> V_35 . V_303 ;
V_33 -> V_234 = F_62 ( V_31 ) ;
V_279 = F_100 ( V_31 ) ;
if ( V_279 )
F_33 ( V_306 , & V_31 -> V_43 ) ;
F_96 ( & V_31 -> V_2 -> V_87 , L_54
L_55 ,
V_33 -> V_35 . V_20 ,
V_33 -> V_35 . V_307 ,
V_33 -> V_35 . V_89 ,
V_33 -> V_35 . V_308 . V_309 ,
V_33 -> V_95 ,
V_33 -> V_35 . V_91 ,
V_33 -> V_35 . V_310 ,
V_279 ? L_56 : L_57 ) ;
return 0 ;
V_300:
F_101 ( V_31 ) ;
V_299:
F_102 ( V_31 -> V_178 ) ;
V_31 -> V_178 = NULL ;
V_286:
F_46 ( V_33 -> V_201 ) ;
F_46 ( V_31 -> V_33 ) ;
V_31 -> V_33 = NULL ;
return V_34 ;
}
static void F_103 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
int V_199 ;
F_101 ( V_31 ) ;
V_33 -> V_129 = NULL ;
V_33 -> V_158 = NULL ;
V_33 -> V_162 = NULL ;
V_33 -> V_155 = NULL ;
V_33 -> V_200 = 0 ;
for ( V_199 = 0 ; V_199 < 8 ; V_199 ++ ) {
F_46 ( V_31 -> V_208 [ V_199 ] . V_201 ) ;
if ( ( T_2 * ) V_31 -> V_208 [ V_199 ] . V_201 ==
V_33 -> V_201 ) {
V_33 -> V_201 = NULL ;
V_33 -> V_200 = 0 ;
}
V_31 -> V_208 [ V_199 ] . V_201 = NULL ;
V_31 -> V_208 [ V_199 ] . V_209 = 0 ;
V_31 -> V_208 [ V_199 ] . V_154 = 0 ;
V_31 -> V_208 [ V_199 ] . V_210 = 0 ;
}
F_46 ( V_33 -> V_201 ) ;
V_33 -> V_201 = NULL ;
}
static struct V_167 *
F_104 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_311 * V_312 ;
struct V_140 * V_313 ;
struct V_167 * V_168 ;
struct V_26 * V_27 ;
int V_314 , V_315 ;
int V_199 ;
V_314 = 8 ;
V_315 = sizeof( struct V_28 ) + 2 * sizeof( struct V_140 ) ;
V_168 = F_42 ( V_176 , V_314 , V_315 , V_31 ) ;
if ( F_43 ( V_168 ) )
return V_168 ;
V_27 = V_168 -> V_171 ;
F_13 ( V_27 ++ , V_168 -> V_29 , 0 , 2 ,
V_70 , V_31 , 0 ) ;
V_313 = V_168 -> V_29 + sizeof( struct V_28 ) ;
V_27 [ - 1 ] . V_43 |= V_262 ;
V_125 ( V_27 ++ , V_313 ++ , 0 , 0 , 4 ,
V_70 , V_31 , 0 ) ;
V_312 = V_33 -> V_316 ;
for ( V_199 = 0 ; V_199 < 4 ; V_199 ++ ) {
V_27 [ - 1 ] . V_43 |= V_262 ;
V_27 -> V_54 = V_70 ;
V_27 -> V_43 = 0 ;
V_27 -> V_42 = 8 ;
V_27 -> V_56 = ( T_1 ) ( V_173 ) V_312 ;
V_27 ++ ;
V_312 ++ ;
}
V_27 [ - 1 ] . V_43 |= V_262 ;
V_125 ( V_27 ++ , V_313 ++ , 2 , 0 , 1 ,
V_70 , V_31 , 0 ) ;
V_27 [ - 1 ] . V_43 |= V_262 ;
V_27 -> V_54 = V_70 ;
V_27 -> V_43 = 0 ;
V_27 -> V_42 = 8 ;
V_27 -> V_56 = ( T_1 ) ( V_173 ) V_312 ;
V_168 -> V_178 = NULL ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_181 = 255 ;
V_168 -> V_182 = F_32 () ;
V_168 -> V_183 = V_184 ;
return V_168 ;
}
static int F_105 ( struct V_167 * V_317 )
{
char * V_318 ;
if ( V_317 -> V_183 == V_186 )
return V_319 ;
else if ( V_317 -> V_183 == V_320 ||
V_317 -> V_183 == V_321 ) {
V_318 = F_106 ( & V_317 -> V_322 ) ;
if ( V_318 && ( V_318 [ 1 ] & V_323 ) )
return V_324 ;
else
return V_325 ;
} else
return V_325 ;
}
static void F_107 ( struct V_167 * V_317 ,
void * V_29 )
{
struct V_30 * V_31 = V_317 -> V_119 ;
struct V_32 * V_33 = V_31 -> V_33 ;
V_33 -> V_284 = F_105 ( V_317 ) ;
F_45 ( V_317 , V_31 ) ;
F_108 ( V_31 ) ;
}
static int F_109 ( struct V_277 * V_178 )
{
struct V_167 * V_317 ;
V_317 = F_104 ( V_178 -> V_298 ) ;
if ( F_43 ( V_317 ) )
return F_86 ( V_317 ) ;
V_317 -> V_191 = F_107 ;
V_317 -> V_326 = NULL ;
V_317 -> V_179 = 5 * V_180 ;
F_38 ( V_189 , & V_317 -> V_43 ) ;
V_317 -> V_181 = 0 ;
F_110 ( V_317 ) ;
return - V_249 ;
}
static int F_111 ( struct V_277 * V_178 )
{
struct V_30 * V_31 = V_178 -> V_298 ;
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_311 * V_316 ;
unsigned int V_327 , V_145 ;
int V_183 , V_199 ;
struct V_167 * V_317 ;
V_183 = V_33 -> V_284 ;
V_33 -> V_284 = - 1 ;
if ( V_183 == V_325 ) {
V_317 = F_104 ( V_31 ) ;
F_44 ( V_317 ) ;
V_183 = F_105 ( V_317 ) ;
F_45 ( V_317 , V_31 ) ;
}
if ( V_31 -> V_231 & V_301 ) {
V_178 -> V_328 = V_329 ;
V_145 = V_330 ;
V_178 -> V_331 = 3 ;
goto V_332;
}
if ( V_183 == V_324 ) {
F_64 ( & V_31 -> V_2 -> V_87 , L_58 ) ;
return - V_333 ;
} else if ( V_183 == V_325 ) {
F_15 ( & V_31 -> V_2 -> V_87 ,
L_59
L_60 ) ;
return - V_283 ;
}
V_33 -> V_90 = 1 ;
V_316 = NULL ;
for ( V_199 = 0 ; V_199 < 3 ; V_199 ++ ) {
if ( V_33 -> V_316 [ V_199 ] . V_16 != 4 ||
V_33 -> V_316 [ V_199 ] . V_17 != F_22 ( V_199 ) - 4 ||
V_33 -> V_316 [ V_199 ] . V_23 != 0 ||
V_33 -> V_316 [ V_199 ] . V_24 != V_334 [ V_199 ] ||
V_33 -> V_316 [ V_199 ] . V_115 != V_335 [ V_199 ] ) {
V_33 -> V_90 = 0 ;
break;
}
}
if ( V_199 == 3 )
V_316 = & V_33 -> V_316 [ 4 ] ;
if ( V_33 -> V_90 == 0 ) {
for ( V_199 = 0 ; V_199 < 5 ; V_199 ++ ) {
if ( ( V_33 -> V_316 [ V_199 ] . V_16 != 0 ) ||
( V_33 -> V_316 [ V_199 ] . V_17 !=
V_33 -> V_316 [ 0 ] . V_17 ) ||
V_33 -> V_316 [ V_199 ] . V_23 != 0 ||
V_33 -> V_316 [ V_199 ] . V_24 != V_334 [ V_199 ] ||
V_33 -> V_316 [ V_199 ] . V_115 != V_335 [ V_199 ] )
break;
}
if ( V_199 == 5 )
V_316 = & V_33 -> V_316 [ 0 ] ;
} else {
if ( V_33 -> V_316 [ 3 ] . V_115 == 1 )
F_64 ( & V_31 -> V_2 -> V_87 ,
L_61 ) ;
}
if ( V_316 != NULL && V_316 -> V_16 == 0 ) {
if ( F_112 ( V_316 -> V_17 ) == 0 )
V_178 -> V_328 = V_316 -> V_17 ;
}
if ( V_178 -> V_328 == 0 ) {
F_64 ( & V_31 -> V_2 -> V_87 ,
L_62 ) ;
return - V_333 ;
}
V_178 -> V_331 = 0 ;
for ( V_327 = 512 ; V_327 < V_178 -> V_328 ; V_327 = V_327 << 1 )
V_178 -> V_331 ++ ;
V_145 = F_9 ( & V_33 -> V_35 , 0 , V_178 -> V_328 ) ;
V_332:
V_178 -> V_336 = ( V_33 -> V_95 *
V_33 -> V_35 . V_91 *
V_145 ) ;
F_96 ( & V_31 -> V_2 -> V_87 ,
L_63
L_64 , ( V_178 -> V_328 >> 10 ) ,
( ( V_33 -> V_95 *
V_33 -> V_35 . V_91 *
V_145 * ( V_178 -> V_328 >> 9 ) ) >> 1 ) ,
( ( V_145 * V_178 -> V_328 ) >> 10 ) ,
V_33 -> V_90 ?
L_65 : L_66 ) ;
return 0 ;
}
static int F_113 ( struct V_277 * V_178 )
{
struct V_32 * V_33 = V_178 -> V_298 -> V_33 ;
if ( V_33 -> V_284 < 0 )
return F_109 ( V_178 ) ;
else
return F_111 ( V_178 ) ;
}
static int F_114 ( struct V_30 * V_31 )
{
return F_115 ( V_31 ) ;
}
static int F_116 ( struct V_30 * V_31 )
{
F_117 ( & V_31 -> V_337 ) ;
F_117 ( & V_31 -> V_272 ) ;
return 0 ;
}
static int F_118 ( struct V_30 * V_31 )
{
return F_119 ( V_31 ) ;
}
static int
F_120 ( struct V_277 * V_178 , struct V_338 * V_22 )
{
struct V_32 * V_33 = V_178 -> V_298 -> V_33 ;
if ( F_112 ( V_178 -> V_328 ) == 0 ) {
V_22 -> V_339 = F_9 ( & V_33 -> V_35 ,
0 , V_178 -> V_328 ) ;
}
V_22 -> V_340 = V_33 -> V_35 . V_303 ;
V_22 -> V_49 = V_33 -> V_35 . V_91 ;
return 0 ;
}
static struct V_167 *
F_121 ( struct V_30 * V_298 , struct V_341 * V_342 ,
int V_264 , struct V_311 * V_343 ,
int V_344 )
{
struct V_32 * V_345 ;
struct V_30 * V_119 = NULL ;
struct V_346 * V_347 = NULL ;
struct V_167 * V_168 ;
struct V_348 * V_348 ;
int V_349 ;
int V_42 ;
int V_34 ;
int V_199 ;
if ( V_264 )
V_119 = F_122 ( V_298 ) ;
if ( ! V_119 )
V_119 = V_298 ;
V_345 = V_119 -> V_33 ;
V_42 = V_344 * ( V_342 -> V_350 - V_342 -> V_351 + 1 ) ;
V_349 = F_123 ( 0 , V_42 , 0 ) ;
V_168 = F_42 ( V_176 , 0 , V_349 , V_119 ) ;
if ( F_43 ( V_168 ) )
return V_168 ;
V_345 -> V_42 ++ ;
V_348 = F_124 ( V_168 -> V_29 , V_349 , V_352 , 0 , V_42 , 0 ) ;
if ( F_43 ( V_348 ) ) {
V_34 = - V_127 ;
goto V_353;
}
V_168 -> V_171 = F_125 ( V_348 ) ;
V_34 = F_126 ( V_348 , V_342 -> V_351 , V_342 -> V_350 ,
V_354 , V_298 , V_119 , 0 , V_42 ,
sizeof( struct V_311 ) ,
V_42 * sizeof( struct V_311 ) , 0 , V_344 ) ;
if ( V_34 )
goto V_353;
for ( V_199 = 0 ; V_199 < V_42 ; V_199 ++ ) {
V_347 = F_127 ( V_348 , 0 , V_343 ++ ,
sizeof( struct V_311 ) ) ;
if ( F_43 ( V_347 ) ) {
V_34 = - V_127 ;
goto V_353;
}
}
V_347 -> V_43 |= V_355 ;
F_128 ( V_348 ) ;
V_168 -> V_356 = 1 ;
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_118 = V_298 ;
V_168 -> V_181 = V_119 -> V_289 ;
V_168 -> V_179 = V_119 -> V_287 * V_180 ;
V_168 -> V_182 = F_32 () ;
V_168 -> V_183 = V_184 ;
F_33 ( V_357 , & V_168 -> V_43 ) ;
F_33 ( V_358 , & V_168 -> V_43 ) ;
return V_168 ;
V_353:
F_45 ( V_168 , V_119 ) ;
return F_129 ( V_34 ) ;
}
static struct V_167 *
F_130 ( struct V_30 * V_298 , struct V_341 * V_342 ,
int V_264 , struct V_311 * V_343 , int V_344 )
{
struct V_32 * V_345 ;
struct V_32 * V_359 ;
struct V_30 * V_119 = NULL ;
struct V_167 * V_168 ;
struct V_26 * V_27 ;
void * V_29 ;
int V_314 , V_315 ;
int V_360 ;
int V_42 ;
int V_199 ;
if ( V_264 )
V_119 = F_122 ( V_298 ) ;
if ( ! V_119 )
V_119 = V_298 ;
V_345 = V_119 -> V_33 ;
V_359 = V_298 -> V_33 ;
V_42 = V_344 * ( V_342 -> V_350 - V_342 -> V_351 + 1 ) ;
V_360 = V_359 -> V_231 . V_232 [ 8 ] & 0x01 ;
if ( V_360 ) {
V_314 = 1 ;
V_315 = sizeof( struct V_116 ) ;
} else {
V_314 = 2 ;
V_315 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) ;
}
V_314 += V_42 ;
V_168 = F_42 ( V_176 , V_314 , V_315 ,
V_119 ) ;
if ( F_43 ( V_168 ) )
return V_168 ;
V_345 -> V_42 ++ ;
V_29 = V_168 -> V_29 ;
V_27 = V_168 -> V_171 ;
if ( V_360 ) {
F_19 ( V_27 ++ , V_29 , V_342 -> V_351 , V_342 -> V_350 ,
V_70 , V_298 , V_119 , 1 , 0 ,
V_42 , 0 , 0 ) ;
} else {
F_13 ( V_27 ++ , V_29 , V_342 -> V_351 , V_342 -> V_350 ,
V_70 , V_119 , 0 ) ;
V_29 += sizeof( struct V_28 ) ;
V_27 [ - 1 ] . V_43 |= V_262 ;
V_125 ( V_27 ++ , V_29 , V_342 -> V_351 , 0 , V_42 ,
V_70 , V_298 , 0 ) ;
}
for ( V_199 = 0 ; V_199 < V_42 ; V_199 ++ ) {
V_27 [ - 1 ] . V_43 |= V_262 ;
V_27 -> V_54 = V_70 ;
V_27 -> V_43 = V_44 ;
V_27 -> V_42 = 8 ;
V_27 -> V_56 = ( T_1 ) ( V_173 ) V_343 ;
V_27 ++ ;
V_343 ++ ;
}
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_118 = V_298 ;
V_168 -> V_181 = V_290 ;
V_168 -> V_179 = V_119 -> V_287 * V_180 ;
V_168 -> V_182 = F_32 () ;
V_168 -> V_183 = V_184 ;
F_33 ( V_361 , & V_168 -> V_43 ) ;
return V_168 ;
}
static struct V_167 *
F_131 ( struct V_30 * V_298 ,
struct V_341 * V_342 ,
int V_264 )
{
struct V_32 * V_359 ;
struct V_32 * V_345 ;
struct V_30 * V_119 = NULL ;
struct V_167 * V_362 ;
struct V_311 * V_363 ;
struct V_21 V_364 ;
struct V_26 * V_27 ;
void * V_29 ;
int V_344 ;
int V_314 , V_315 ;
int V_199 , V_365 ;
int V_366 = 0 ;
int V_367 ;
int V_368 ;
int V_360 ;
if ( V_264 )
V_119 = F_122 ( V_298 ) ;
if ( ! V_119 )
V_119 = V_298 ;
V_345 = V_119 -> V_33 ;
V_359 = V_298 -> V_33 ;
V_344 = F_9 ( & V_359 -> V_35 , 0 , V_342 -> V_48 ) ;
V_368 = V_342 -> V_350 - V_342 -> V_351 + 1 ;
if ( V_342 -> V_366 & 0x10 ) {
V_367 = 0 ;
V_366 = V_342 -> V_366 & ~ 0x10 ;
} else {
V_367 = 1 ;
V_366 = V_342 -> V_366 ;
}
V_360 = V_359 -> V_231 . V_232 [ 8 ] & 0x01 ;
switch ( V_366 ) {
case 0x00 :
case 0x08 :
V_314 = 2 + ( V_344 * V_368 ) ;
if ( V_360 )
V_315 = sizeof( struct V_116 ) +
sizeof( struct V_140 ) +
V_344 * V_368 * sizeof( struct V_311 ) ;
else
V_315 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
V_344 * V_368 * sizeof( struct V_311 ) ;
break;
case 0x01 :
case 0x09 :
V_314 = 2 + V_344 * V_368 ;
if ( V_360 )
V_315 = sizeof( struct V_116 ) +
sizeof( struct V_140 ) +
sizeof( struct V_311 ) +
V_344 * V_368 * sizeof( struct V_311 ) ;
else
V_315 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
sizeof( struct V_311 ) +
V_344 * V_368 * sizeof( struct V_311 ) ;
break;
case 0x04 :
case 0x0c :
V_314 = 3 ;
if ( V_360 )
V_315 = sizeof( struct V_116 ) +
sizeof( struct V_140 ) +
sizeof( struct V_311 ) ;
else
V_315 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
sizeof( struct V_311 ) ;
break;
default:
F_64 ( & V_119 -> V_2 -> V_87 ,
L_67 ,
V_342 -> V_366 ) ;
return F_129 ( - V_127 ) ;
}
V_362 = F_42 ( V_176 , V_314 ,
V_315 , V_119 ) ;
if ( F_43 ( V_362 ) )
return V_362 ;
V_345 -> V_42 ++ ;
V_29 = V_362 -> V_29 ;
V_27 = V_362 -> V_171 ;
switch ( V_366 & ~ 0x08 ) {
case 0x00 :
if ( V_360 ) {
F_20 ( V_27 ++ , (struct V_116 * ) V_29 ,
V_342 -> V_351 , V_342 -> V_350 ,
V_79 , V_298 , V_119 ) ;
if ( V_367 )
( (struct V_116 * ) V_29 )
-> F_13 . V_38 |= 0x04 ;
V_29 += sizeof( struct V_116 ) ;
} else {
F_13 ( V_27 ++ , (struct V_28 * ) V_29 ,
V_342 -> V_351 , V_342 -> V_350 ,
V_79 , V_119 , 0 ) ;
if ( V_367 )
( (struct V_28 * ) V_29 )
-> V_38 |= 0x04 ;
V_29 += sizeof( struct V_28 ) ;
}
V_27 [ - 1 ] . V_43 |= V_262 ;
V_125 ( V_27 ++ , (struct V_140 * ) V_29 ,
V_342 -> V_351 , 0 , V_344 * V_368 ,
V_79 , V_298 ,
V_342 -> V_48 ) ;
V_29 += sizeof( struct V_140 ) ;
break;
case 0x01 :
if ( V_360 ) {
F_20 ( V_27 ++ , (struct V_116 * ) V_29 ,
V_342 -> V_351 , V_342 -> V_350 ,
V_83 ,
V_298 , V_119 ) ;
V_29 += sizeof( struct V_116 ) ;
} else {
F_13 ( V_27 ++ , (struct V_28 * ) V_29 ,
V_342 -> V_351 , V_342 -> V_350 ,
V_83 , V_119 , 0 ) ;
V_29 += sizeof( struct V_28 ) ;
}
V_27 [ - 1 ] . V_43 |= V_262 ;
V_125 ( V_27 ++ , (struct V_140 * ) V_29 ,
V_342 -> V_351 , 0 , V_344 * V_368 + 1 ,
V_83 , V_298 ,
V_298 -> V_178 -> V_328 ) ;
V_29 += sizeof( struct V_140 ) ;
break;
case 0x04 :
if ( V_360 ) {
F_20 ( V_27 ++ , (struct V_116 * ) V_29 ,
V_342 -> V_351 , V_342 -> V_350 ,
V_79 , V_298 , V_119 ) ;
V_29 += sizeof( struct V_116 ) ;
} else {
F_13 ( V_27 ++ , (struct V_28 * ) V_29 ,
V_342 -> V_351 , V_342 -> V_350 ,
V_79 , V_119 , 0 ) ;
V_29 += sizeof( struct V_28 ) ;
}
V_27 [ - 1 ] . V_43 |= V_262 ;
V_125 ( V_27 ++ , (struct V_140 * ) V_29 ,
V_342 -> V_351 , 0 , 1 ,
V_79 , V_298 , 8 ) ;
V_29 += sizeof( struct V_140 ) ;
break;
}
for ( V_365 = 0 ; V_365 < V_368 ; V_365 ++ ) {
F_10 ( & V_364 ,
( V_342 -> V_351 + V_365 ) /
V_359 -> V_35 . V_91 ,
( V_342 -> V_351 + V_365 ) %
V_359 -> V_35 . V_91 ) ;
if ( V_366 & 0x01 ) {
V_363 = (struct V_311 * ) V_29 ;
V_29 += sizeof( struct V_311 ) ;
V_363 -> V_23 = V_364 . V_23 ;
V_363 -> V_24 = V_364 . V_24 ;
V_363 -> V_115 = 0 ;
V_363 -> V_16 = 0 ;
V_363 -> V_17 = 8 ;
V_27 [ - 1 ] . V_43 |= V_262 ;
V_27 -> V_54 = V_83 ;
V_27 -> V_43 = V_44 ;
V_27 -> V_42 = 8 ;
V_27 -> V_56 = ( T_1 ) ( V_173 ) V_363 ;
V_27 ++ ;
}
if ( ( V_366 & ~ 0x08 ) & 0x04 ) {
V_363 = (struct V_311 * ) V_29 ;
V_29 += sizeof( struct V_311 ) ;
V_363 -> V_23 = V_364 . V_23 ;
V_363 -> V_24 = V_364 . V_24 ;
V_363 -> V_115 = 1 ;
V_363 -> V_16 = 0 ;
V_363 -> V_17 = 0 ;
V_27 [ - 1 ] . V_43 |= V_262 ;
V_27 -> V_54 = V_79 ;
V_27 -> V_43 = V_44 ;
V_27 -> V_42 = 8 ;
V_27 -> V_56 = ( T_1 ) ( V_173 ) V_363 ;
} else {
for ( V_199 = 0 ; V_199 < V_344 ; V_199 ++ ) {
V_363 = (struct V_311 * ) V_29 ;
V_29 += sizeof( struct V_311 ) ;
V_363 -> V_23 = V_364 . V_23 ;
V_363 -> V_24 = V_364 . V_24 ;
V_363 -> V_115 = V_199 + 1 ;
V_363 -> V_16 = 0 ;
V_363 -> V_17 = V_342 -> V_48 ;
if ( ( V_366 & 0x08 ) &&
V_364 . V_23 == 0 && V_364 . V_24 == 0 ) {
if ( V_199 < 3 ) {
V_363 -> V_16 = 4 ;
V_363 -> V_17 = V_147 [ V_199 ] - 4 ;
}
}
if ( ( V_366 & 0x08 ) &&
V_364 . V_23 == 0 && V_364 . V_24 == 1 ) {
V_363 -> V_16 = 44 ;
V_363 -> V_17 = V_148 - 44 ;
}
V_27 [ - 1 ] . V_43 |= V_262 ;
if ( V_199 != 0 || V_365 == 0 )
V_27 -> V_54 =
V_79 ;
else
V_27 -> V_54 =
V_80 ;
V_27 -> V_43 = V_44 ;
V_27 -> V_42 = 8 ;
V_27 -> V_56 = ( T_1 ) ( V_173 ) V_363 ;
V_27 ++ ;
}
}
}
V_362 -> V_119 = V_119 ;
V_362 -> V_177 = V_119 ;
V_362 -> V_118 = V_298 ;
V_362 -> V_181 = 256 ;
V_362 -> V_179 = V_119 -> V_287 * V_180 ;
V_362 -> V_182 = F_32 () ;
V_362 -> V_183 = V_184 ;
return V_362 ;
}
static struct V_167 *
F_132 ( struct V_30 * V_298 ,
struct V_341 * V_342 , int V_264 ,
int V_225 , struct V_311 * V_343 , int V_344 )
{
struct V_167 * V_369 ;
if ( ! V_343 ) {
V_369 = F_131 ( V_298 , V_342 , V_264 ) ;
} else {
if ( V_225 )
V_369 = F_121 ( V_298 , V_342 ,
V_264 ,
V_343 , V_344 ) ;
else
V_369 = F_130 ( V_298 , V_342 , V_264 ,
V_343 , V_344 ) ;
}
return V_369 ;
}
static int F_133 ( struct V_30 * V_298 ,
struct V_341 * V_342 )
{
struct V_32 * V_33 = V_298 -> V_33 ;
if ( V_342 -> V_351 >=
( V_33 -> V_95 * V_33 -> V_35 . V_91 ) ) {
F_64 ( & V_298 -> V_2 -> V_87 ,
L_68 ,
V_342 -> V_351 ) ;
return - V_127 ;
}
if ( V_342 -> V_350 >=
( V_33 -> V_95 * V_33 -> V_35 . V_91 ) ) {
F_64 ( & V_298 -> V_2 -> V_87 ,
L_69 ,
V_342 -> V_350 ) ;
return - V_127 ;
}
if ( V_342 -> V_351 > V_342 -> V_350 ) {
F_64 ( & V_298 -> V_2 -> V_87 ,
L_70 ,
V_342 -> V_351 ) ;
return - V_127 ;
}
if ( F_112 ( V_342 -> V_48 ) != 0 ) {
F_64 ( & V_298 -> V_2 -> V_87 ,
L_71 ,
V_342 -> V_48 ) ;
return - V_127 ;
}
return 0 ;
}
static int F_134 ( struct V_30 * V_298 ,
struct V_341 * V_342 ,
int V_264 , int V_225 ,
struct V_311 * V_343 , int V_344 ,
struct V_322 * V_322 )
{
struct V_32 * V_33 = V_298 -> V_33 ;
struct V_167 * V_168 , * V_370 ;
struct V_371 V_372 ;
struct V_30 * V_31 ;
char * V_318 = NULL ;
int V_373 , V_374 , V_375 ;
int V_376 , V_377 ;
int V_34 ;
V_34 = F_133 ( V_298 , V_342 ) ;
if ( V_34 )
return V_34 ;
F_135 ( & V_372 ) ;
V_373 = V_342 -> V_351 ;
V_374 = V_342 -> V_350 ;
if ( ! V_225 && V_343 != NULL ) {
V_375 = 1 ;
} else if ( V_225 && V_343 != NULL ) {
V_375 = V_378 / V_344 ;
} else {
V_375 = V_378 /
F_9 ( & V_33 -> V_35 , 0 , V_342 -> V_48 ) ;
}
do {
V_377 = 0 ;
while ( V_342 -> V_351 <= V_374 ) {
V_376 = V_342 -> V_350 - V_342 -> V_351 + 1 ;
if ( V_376 > V_375 ) {
V_342 -> V_350 =
V_342 -> V_351 + V_375 - 1 ;
}
V_168 = F_132 ( V_298 , V_342 ,
V_264 , V_225 ,
V_343 , V_344 ) ;
if ( F_43 ( V_168 ) ) {
V_34 = F_86 ( V_168 ) ;
if ( V_34 == - V_197 ) {
if ( F_136 ( & V_372 ) )
goto V_379;
V_377 = 1 ;
break;
}
goto V_353;
}
F_137 ( & V_168 -> V_380 , & V_372 ) ;
if ( V_343 ) {
V_376 = V_342 -> V_350 - V_342 -> V_351 + 1 ;
V_343 += V_344 * V_376 ;
}
V_342 -> V_351 = V_342 -> V_350 + 1 ;
V_342 -> V_350 = V_374 ;
}
V_34 = F_138 ( & V_372 ) ;
V_353:
F_139 (cqr, n, &format_queue, blocklist) {
V_31 = V_168 -> V_119 ;
V_33 = V_31 -> V_33 ;
if ( V_168 -> V_183 == V_321 ) {
if ( V_343 && V_322 ) {
V_318 = F_106 ( & V_168 -> V_322 ) ;
memcpy ( V_322 , & V_168 -> V_322 , sizeof( * V_322 ) ) ;
}
V_34 = - V_283 ;
}
F_140 ( & V_168 -> V_380 ) ;
F_45 ( V_168 , V_31 ) ;
V_33 -> V_42 -- ;
}
if ( V_34 && V_34 != - V_283 )
goto V_379;
if ( V_34 == - V_283 ) {
if ( V_318 &&
( V_318 [ 1 ] & V_323 ||
V_318 [ 1 ] & V_381 ) )
V_377 = 1 ;
else
goto V_379;
}
} while ( V_377 );
V_379:
V_342 -> V_351 = V_373 ;
V_342 -> V_350 = V_374 ;
return V_34 ;
}
static int F_141 ( struct V_30 * V_298 ,
struct V_341 * V_342 , int V_264 )
{
return F_134 ( V_298 , V_342 , V_264 , 0 , NULL ,
0 , NULL ) ;
}
static int F_142 ( struct V_311 * V_343 , int V_382 ,
int V_383 )
{
int V_24 ;
int V_199 ;
V_24 = V_343 [ V_382 ] . V_24 ;
for ( V_199 = V_382 ; V_199 < V_383 ; V_199 ++ ) {
if ( V_199 > V_382 ) {
if ( ( V_343 [ V_199 ] . V_24 == V_24 &&
V_343 [ V_199 ] . V_115 == 1 ) ||
V_343 [ V_199 ] . V_24 != V_24 ||
V_343 [ V_199 ] . V_115 == 0 )
break;
}
}
return V_199 - V_382 ;
}
static void F_143 ( struct V_311 * V_343 ,
struct V_384 * V_385 ,
int V_386 , int V_387 ,
int V_91 , int V_225 )
{
struct V_21 V_22 ;
int V_388 ;
int V_42 = 0 ;
int V_389 ;
int V_48 ;
int V_213 = 0 ;
int V_199 , V_365 ;
int V_16 ;
V_389 = V_385 -> V_390 . V_350 - V_385 -> V_390 . V_351 + 1 ;
V_388 = V_389 * V_386 ;
for ( V_199 = V_385 -> V_390 . V_351 ; V_199 <= V_385 -> V_390 . V_350 ; V_199 ++ ) {
if ( V_225 ) {
while ( V_343 [ V_213 ] . V_115 == 0 &&
V_343 [ V_213 ] . V_17 == 0 ) {
if ( V_213 ++ > V_388 )
break;
}
} else {
if ( V_199 != V_385 -> V_390 . V_351 )
V_213 += V_386 - V_42 ;
}
F_10 ( & V_22 , V_199 / V_91 , V_199 % V_91 ) ;
V_42 = F_142 ( V_343 , V_213 , V_213 + V_386 ) ;
if ( V_42 < V_387 ) {
V_385 -> V_391 = V_392 ;
break;
}
if ( V_42 > V_387 ) {
V_385 -> V_391 = V_393 ;
break;
}
for ( V_365 = 0 ; V_365 < V_42 ; V_365 ++ , V_213 ++ ) {
V_48 = V_385 -> V_390 . V_48 ;
V_16 = 0 ;
if ( ( V_385 -> V_390 . V_366 & 0x08 ) &&
V_22 . V_23 == 0 && V_22 . V_24 == 0 ) {
if ( V_365 < 3 ) {
V_48 = V_147 [ V_365 ] - 4 ;
V_16 = 4 ;
}
}
if ( ( V_385 -> V_390 . V_366 & 0x08 ) &&
V_22 . V_23 == 0 && V_22 . V_24 == 1 ) {
V_48 = V_148 - 44 ;
V_16 = 44 ;
}
if ( V_343 [ V_213 ] . V_17 != V_48 ) {
V_385 -> V_391 = V_394 ;
goto V_379;
}
if ( V_343 [ V_213 ] . V_16 != V_16 ) {
V_385 -> V_391 = V_395 ;
goto V_379;
}
if ( V_343 [ V_213 ] . V_23 != V_22 . V_23 ||
V_343 [ V_213 ] . V_24 != V_22 . V_24 ||
V_343 [ V_213 ] . V_115 != ( V_365 + 1 ) ) {
V_385 -> V_391 = V_396 ;
goto V_379;
}
}
}
V_379:
if ( ! V_385 -> V_391 ) {
V_199 -- ;
V_213 -- ;
}
V_385 -> V_397 = V_199 ;
V_385 -> V_398 = V_42 ;
V_385 -> V_399 = V_343 [ V_213 ] . V_115 ;
V_385 -> V_48 = V_343 [ V_213 ] . V_17 ;
V_385 -> V_400 = V_343 [ V_213 ] . V_16 ;
}
static int F_144 ( struct V_30 * V_298 ,
struct V_384 * V_385 ,
int V_264 )
{
struct V_32 * V_33 = V_298 -> V_33 ;
struct V_311 * V_343 ;
struct V_322 V_322 ;
int V_386 , V_387 ;
int V_401 ;
int V_91 ;
int V_389 ;
int V_225 = 0 ;
int V_34 ;
V_91 = V_33 -> V_35 . V_91 ;
V_386 = F_9 ( & V_33 -> V_35 , 0 , 512 ) + 1 ;
V_387 = F_9 ( & V_33 -> V_35 , 0 , V_385 -> V_390 . V_48 ) ;
V_389 = V_385 -> V_390 . V_350 - V_385 -> V_390 . V_351 + 1 ;
V_401 = V_389 * V_386 * sizeof( struct V_311 ) ;
V_343 = F_41 ( V_401 , V_195 | V_196 ) ;
if ( ! V_343 )
return - V_197 ;
if ( ( V_33 -> V_231 . V_232 [ 40 ] & 0x04 ) &&
V_401 <= V_33 -> V_234 )
V_225 = 1 ;
V_34 = F_134 ( V_298 , & V_385 -> V_390 , V_264 ,
V_225 , V_343 , V_386 , & V_322 ) ;
if ( V_34 && V_34 != - V_283 )
goto V_379;
if ( V_34 == - V_283 ) {
if ( V_225 && F_145 ( & V_322 . V_402 ) == 0x40 ) {
V_225 = 0 ;
V_34 = F_134 ( V_298 , & V_385 -> V_390 ,
V_264 , V_225 ,
V_343 , V_386 ,
& V_322 ) ;
if ( V_34 )
goto V_379;
} else {
goto V_379;
}
}
F_143 ( V_343 , V_385 , V_386 , V_387 ,
V_91 , V_225 ) ;
V_379:
F_46 ( V_343 ) ;
return V_34 ;
}
static void F_146 ( struct V_167 * V_168 )
{
if ( V_168 -> V_181 < 0 ) {
V_168 -> V_183 = V_321 ;
return;
}
V_168 -> V_183 = V_184 ;
if ( V_168 -> V_178 && ( V_168 -> V_119 != V_168 -> V_178 -> V_298 ) ) {
F_147 ( V_168 ) ;
V_168 -> V_119 = V_168 -> V_178 -> V_298 ;
V_168 -> V_170 = F_59 ( V_168 -> V_178 -> V_298 ) ;
}
}
static T_5
F_148 ( struct V_167 * V_168 )
{
struct V_30 * V_31 = (struct V_30 * ) V_168 -> V_119 ;
struct V_1 * V_2 = V_31 -> V_2 ;
switch ( V_2 -> V_403 . V_89 ) {
case 0x3990 :
case 0x2105 :
case 0x2107 :
case 0x1750 :
return V_404 ;
case 0x9343 :
case 0x3880 :
default:
return V_405 ;
}
}
static T_5
F_149 ( struct V_167 * V_168 )
{
return V_406 ;
}
static void F_150 ( struct V_30 * V_31 ,
struct V_167 * V_168 ,
struct V_322 * V_322 )
{
char V_65 ;
char * V_318 = NULL ;
struct V_32 * V_33 = V_31 -> V_33 ;
V_65 = V_407 | V_408 | V_409 ;
if ( ( F_151 ( & V_322 -> V_402 ) & V_65 ) == V_65 ) {
if ( ! V_31 -> V_178 && V_33 -> V_410 &&
V_31 -> V_275 == V_276 &&
! F_69 ( V_274 , & V_31 -> V_43 ) &&
! F_69 ( V_246 , & V_31 -> V_43 ) ) {
F_152 ( V_31 ) ;
}
F_153 ( V_31 ) ;
return;
}
V_318 = F_106 ( V_322 ) ;
if ( ! V_318 )
return;
if ( ( V_318 [ 27 ] & V_411 ) && ( V_318 [ 7 ] == 0x0D ) &&
( F_151 ( & V_322 -> V_402 ) & V_412 ) ) {
if ( F_71 ( V_413 , & V_31 -> V_43 ) ) {
F_17 ( V_7 , V_31 , L_1 ,
L_72 ) ;
return;
}
V_318 = F_106 ( V_322 ) ;
if ( ! V_318 ) {
F_17 ( V_7 , V_31 , L_1 ,
L_73 ) ;
F_38 ( V_413 , & V_31 -> V_43 ) ;
return;
}
V_33 -> V_414 = V_318 [ 8 ] ;
F_17 ( V_415 , V_31 , L_74 ,
L_75 ,
V_33 -> V_414 ) ;
F_80 ( V_31 ) ;
if ( ! F_70 ( & V_31 -> V_281 ) )
F_74 ( V_31 ) ;
return;
}
if ( ! V_168 && ! ( V_318 [ 27 ] & V_411 ) &&
( ( V_318 [ 6 ] & V_416 ) == V_416 ) ) {
F_154 ( V_31 , V_318 ) ;
return;
}
if ( V_31 -> V_178 && ( V_318 [ 27 ] & V_411 ) &&
( V_318 [ 7 ] == 0x3F ) &&
( F_151 ( & V_322 -> V_402 ) & V_412 ) &&
F_69 ( V_417 , & V_31 -> V_43 ) ) {
if ( V_31 -> V_231 & V_418 )
F_33 ( V_419 , & V_31 -> V_43 ) ;
F_38 ( V_417 , & V_31 -> V_43 ) ;
F_15 ( & V_31 -> V_2 -> V_87 ,
L_76 ) ;
}
}
static struct V_167 * F_155 (
struct V_30 * V_119 ,
struct V_277 * V_178 ,
struct V_420 * V_421 ,
T_6 V_422 ,
T_6 V_423 ,
T_6 V_424 ,
T_6 V_425 ,
unsigned int V_426 ,
unsigned int V_427 ,
unsigned int V_145 ,
unsigned int V_48 )
{
struct V_32 * V_33 ;
unsigned long * V_428 ;
struct V_140 * V_313 ;
struct V_167 * V_168 ;
struct V_26 * V_27 ;
struct V_429 V_430 ;
struct V_431 V_432 ;
char * V_433 ;
unsigned int V_434 ;
int V_42 , V_435 , V_314 , V_315 ;
T_6 V_146 ;
unsigned char V_47 , V_436 ;
int V_360 ;
struct V_30 * V_118 ;
V_118 = V_178 -> V_298 ;
V_33 = V_118 -> V_33 ;
if ( F_156 ( V_421 ) == V_437 )
V_47 = V_60 ;
else if ( F_156 ( V_421 ) == V_438 )
V_47 = V_76 ;
else
return F_129 ( - V_127 ) ;
V_42 = 0 ;
V_435 = 0 ;
F_157 (bv, req, iter) {
if ( V_432 . V_439 & ( V_48 - 1 ) )
return F_129 ( - V_127 ) ;
V_42 += V_432 . V_439 >> ( V_178 -> V_331 + 9 ) ;
if ( F_158 ( F_159 ( V_432 . V_440 ) , V_432 . V_439 ) )
V_435 += V_432 . V_439 >> ( V_178 -> V_331 + 9 ) ;
}
if ( V_42 != V_423 - V_422 + 1 )
return F_129 ( - V_127 ) ;
V_360 = V_33 -> V_231 . V_232 [ 8 ] & 0x01 ;
if ( V_360 ) {
V_314 = 2 + V_42 ;
V_315 = sizeof( struct V_116 ) +
sizeof( struct V_140 ) +
V_435 * sizeof( unsigned long ) ;
} else {
V_314 = 2 + V_42 ;
V_315 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
V_435 * sizeof( unsigned long ) ;
}
if ( V_33 -> V_90 && V_422 < 2 * V_145 ) {
if ( V_423 >= 2 * V_145 )
V_42 = 2 * V_145 - V_422 ;
V_314 += V_42 ;
V_315 += V_42 * sizeof( struct V_140 ) ;
}
V_168 = F_42 ( V_176 , V_314 , V_315 ,
V_119 ) ;
if ( F_43 ( V_168 ) )
return V_168 ;
V_27 = V_168 -> V_171 ;
if ( V_360 ) {
if ( F_20 ( V_27 ++ , V_168 -> V_29 , V_424 ,
V_425 , V_47 , V_118 , V_119 ) == - V_249 ) {
F_45 ( V_168 , V_119 ) ;
return F_129 ( - V_249 ) ;
}
V_428 = ( unsigned long * ) ( V_168 -> V_29 +
sizeof( struct V_116 ) ) ;
} else {
if ( F_13 ( V_27 ++ , V_168 -> V_29 , V_424 ,
V_425 , V_47 , V_118 , 0 ) == - V_249 ) {
F_45 ( V_168 , V_119 ) ;
return F_129 ( - V_249 ) ;
}
V_428 = ( unsigned long * ) ( V_168 -> V_29 +
sizeof( struct V_28 ) ) ;
}
V_313 = (struct V_140 * ) ( V_428 + V_435 ) ;
V_146 = V_422 ;
if ( V_33 -> V_90 == 0 || V_146 > 2 * V_145 ) {
V_27 [ - 1 ] . V_43 |= V_262 ;
V_125 ( V_27 ++ , V_313 ++ , V_424 , V_426 + 1 ,
V_423 - V_146 + 1 , V_47 , V_118 , V_48 ) ;
}
F_157 (bv, req, iter) {
V_433 = F_159 ( V_432 . V_440 ) + V_432 . V_441 ;
if ( V_442 ) {
char * V_443 = F_160 ( V_442 ,
V_196 | V_444 ) ;
if ( V_443 && F_156 ( V_421 ) == V_438 )
memcpy ( V_443 + V_432 . V_441 , V_433 , V_432 . V_439 ) ;
if ( V_443 )
V_433 = V_443 + V_432 . V_441 ;
}
for ( V_434 = 0 ; V_434 < V_432 . V_439 ; V_434 += V_48 ) {
T_6 V_445 = V_146 ;
unsigned int V_446 = F_161 ( V_445 , V_145 ) ;
V_436 = V_47 ;
V_42 = V_48 ;
if ( V_33 -> V_90 && V_146 < 2 * V_145 ) {
if ( F_21 ( V_145 , V_146 ) ) {
V_436 |= 0x8 ;
V_42 = F_22 ( V_146 ) ;
if ( V_42 < V_48 &&
F_156 ( V_421 ) == V_437 )
memset ( V_433 + V_42 , 0xe5 ,
V_48 - V_42 ) ;
}
V_27 [ - 1 ] . V_43 |= V_262 ;
V_125 ( V_27 ++ , V_313 ++ ,
V_445 , V_446 + 1 ,
1 , V_436 , V_118 , V_42 ) ;
}
if ( V_33 -> V_90 && V_146 == 2 * V_145 ) {
V_27 [ - 1 ] . V_43 |= V_262 ;
V_125 ( V_27 ++ , V_313 ++ ,
V_445 , V_446 + 1 ,
V_423 - V_146 + 1 ,
V_47 , V_118 , V_42 ) ;
}
V_27 [ - 1 ] . V_43 |= V_262 ;
V_27 -> V_54 = V_436 ;
V_27 -> V_42 = V_42 ;
if ( F_158 ( V_433 , V_48 ) ) {
V_27 -> V_56 = ( T_1 ) ( V_173 ) V_428 ;
V_27 -> V_43 = V_447 ;
V_428 = F_162 ( V_428 , V_433 , V_48 ) ;
} else {
V_27 -> V_56 = ( T_1 ) ( V_173 ) V_433 ;
V_27 -> V_43 = 0 ;
}
V_27 ++ ;
V_433 += V_48 ;
V_146 ++ ;
}
}
if ( F_163 ( V_421 ) ||
V_178 -> V_298 -> V_231 & V_448 )
F_33 ( V_273 , & V_168 -> V_43 ) ;
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_178 = V_178 ;
V_168 -> V_179 = V_119 -> V_287 * V_180 ;
V_168 -> V_170 = F_164 ( V_119 ) ;
V_168 -> V_181 = V_119 -> V_289 ;
V_168 -> V_182 = F_32 () ;
V_168 -> V_183 = V_184 ;
return V_168 ;
}
static struct V_167 * F_165 (
struct V_30 * V_119 ,
struct V_277 * V_178 ,
struct V_420 * V_421 ,
T_6 V_422 ,
T_6 V_423 ,
T_6 V_424 ,
T_6 V_425 ,
unsigned int V_426 ,
unsigned int V_427 ,
unsigned int V_145 ,
unsigned int V_48 )
{
unsigned long * V_428 ;
struct V_167 * V_168 ;
struct V_26 * V_27 ;
struct V_429 V_430 ;
struct V_431 V_432 ;
char * V_433 , * V_449 ;
unsigned int V_435 , V_314 , V_315 ;
unsigned int V_101 ;
T_6 V_146 ;
unsigned char V_47 ;
struct V_30 * V_118 ;
unsigned int V_389 , V_42 , V_450 ;
unsigned int V_451 , V_452 , V_453 , V_454 ;
unsigned char V_455 , V_456 ;
T_6 V_445 ;
unsigned int V_446 ;
V_118 = V_178 -> V_298 ;
if ( F_156 ( V_421 ) == V_437 )
V_47 = V_73 ;
else if ( F_156 ( V_421 ) == V_438 )
V_47 = V_86 ;
else
return F_129 ( - V_127 ) ;
V_435 = V_423 - V_422 + 1 ;
V_389 = V_425 - V_424 + 1 ;
V_314 = 1 + V_389 ;
V_315 = sizeof( struct V_116 ) + V_435 * sizeof( unsigned long ) ;
V_168 = F_42 ( V_176 , V_314 , V_315 ,
V_119 ) ;
if ( F_43 ( V_168 ) )
return V_168 ;
V_27 = V_168 -> V_171 ;
if ( V_424 == V_425 )
V_101 = V_427 - V_426 + 1 ;
else
V_101 = V_427 + 1 ;
V_101 *= V_48 ;
if ( F_19 ( V_27 ++ , V_168 -> V_29 , V_424 ,
V_425 , V_47 , V_118 , V_119 ,
1 , V_426 + 1 ,
V_389 , V_48 ,
V_101 ) == - V_249 ) {
F_45 ( V_168 , V_119 ) ;
return F_129 ( - V_249 ) ;
}
V_428 = ( unsigned long * ) ( V_168 -> V_29 + sizeof( struct V_116 ) ) ;
V_146 = V_422 ;
V_455 = 1 ;
V_456 = 0 ;
V_454 = 0 ;
V_449 = NULL ;
V_451 = 0 ;
F_157 (bv, req, iter) {
V_433 = F_159 ( V_432 . V_440 ) + V_432 . V_441 ;
V_452 = V_432 . V_439 ;
while ( V_452 ) {
if ( V_455 ) {
V_445 = V_146 ;
V_446 = F_161 ( V_445 , V_145 ) ;
V_450 = V_145 - V_446 ;
V_42 = F_166 ( ( V_423 - V_146 + 1 ) ,
( T_6 ) V_450 ) ;
V_454 = V_42 * V_48 ;
V_27 [ - 1 ] . V_43 |= V_262 ;
V_27 -> V_54 = V_47 ;
V_27 -> V_42 = V_454 ;
V_27 -> V_56 = ( T_1 ) ( V_173 ) V_428 ;
V_27 -> V_43 = V_447 ;
V_27 ++ ;
V_146 += V_42 ;
V_455 = 0 ;
if ( ! V_449 )
V_449 = V_433 ;
}
if ( ! V_449 ) {
if ( F_14 ( V_433 ) & ( V_457 - 1 ) ) {
F_45 ( V_168 , V_119 ) ;
return F_129 ( - V_458 ) ;
} else
V_449 = V_433 ;
}
if ( ( V_449 + V_451 ) != V_433 ) {
F_45 ( V_168 , V_119 ) ;
return F_129 ( - V_458 ) ;
}
V_453 = F_166 ( V_452 , V_454 ) ;
V_452 -= V_453 ;
V_433 += V_453 ;
V_451 += V_453 ;
V_454 -= V_453 ;
if ( ! ( F_14 ( V_449 + V_451 ) & ( V_457 - 1 ) ) )
V_456 = 1 ;
if ( ! V_454 ) {
V_455 = 1 ;
V_456 = 1 ;
}
if ( V_456 ) {
V_428 = F_162 ( V_428 , V_449 ,
V_451 ) ;
V_449 = NULL ;
V_451 = 0 ;
V_456 = 0 ;
}
}
}
if ( F_163 ( V_421 ) ||
V_178 -> V_298 -> V_231 & V_448 )
F_33 ( V_273 , & V_168 -> V_43 ) ;
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_178 = V_178 ;
V_168 -> V_179 = V_119 -> V_287 * V_180 ;
V_168 -> V_170 = F_164 ( V_119 ) ;
V_168 -> V_181 = V_119 -> V_289 ;
V_168 -> V_182 = F_32 () ;
V_168 -> V_183 = V_184 ;
return V_168 ;
}
static int F_126 ( struct V_348 * V_348 ,
unsigned int V_45 , unsigned int V_46 , int V_47 ,
struct V_30 * V_118 ,
struct V_30 * V_119 ,
unsigned int V_99 , int V_42 ,
unsigned int V_48 ,
unsigned int V_459 ,
unsigned int V_101 ,
unsigned int V_145 )
{
struct V_116 V_117 ;
struct V_32 * V_121 , * V_122 ;
struct V_28 * V_124 ;
struct V_98 * V_123 ;
struct V_460 * V_460 ;
T_4 V_52 , V_53 ;
T_3 V_49 , V_50 , V_51 ;
T_7 V_461 ;
int V_34 = 0 ;
int V_102 = 0 ;
int V_18 , V_103 ;
V_121 = V_118 -> V_33 ;
V_122 = V_119 -> V_33 ;
V_124 = & V_117 . F_13 ;
V_123 = & V_117 . V_125 ;
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
V_117 . V_120 = 1 ;
V_117 . V_128 = V_121 -> V_129 -> V_130 ;
V_117 . V_131 = V_121 -> V_129 -> V_132 ;
V_117 . V_133 . F_13 = 1 ;
if ( V_122 -> V_134 . type != V_135 ) {
V_117 . V_133 . V_136 = 1 ;
if ( V_122 -> V_134 . type == V_137 )
V_117 . V_133 . V_138 = 1 ;
}
switch ( V_47 ) {
case V_73 :
V_124 -> V_65 . V_66 = 0x1 ;
V_124 -> V_67 . V_68 = V_121 -> V_69 . V_68 ;
V_124 -> V_74 = V_48 ;
V_124 -> V_38 |= 0x42 ;
V_123 -> V_68 . V_105 = 0x0 ;
V_123 -> V_68 . V_68 = 0x0C ;
V_123 -> V_106 . V_462 = 0x01 ;
V_461 = V_463 ;
break;
case V_86 :
V_124 -> V_65 . V_66 = 0x02 ;
V_124 -> V_67 . V_68 = V_121 -> V_69 . V_68 ;
V_124 -> V_74 = V_48 ;
V_34 = F_11 ( NULL , V_124 , V_118 ) ;
V_124 -> V_38 |= 0x42 ;
V_123 -> V_68 . V_105 = 0x0 ;
V_123 -> V_68 . V_68 = 0x3F ;
V_123 -> V_109 = 0x23 ;
V_123 -> V_106 . V_462 = 0x2 ;
if ( V_124 -> V_38 & 0x08 && V_124 -> V_38 & 0x02 )
V_117 . V_133 . V_139 = 1 ;
V_461 = V_126 ;
break;
case V_354 :
V_124 -> V_65 . V_66 = 0x1 ;
V_124 -> V_67 . V_68 = V_71 ;
V_124 -> V_38 |= 0x42 ;
V_124 -> V_74 = V_48 ;
V_123 -> V_68 . V_105 = 0x2 ;
V_123 -> V_68 . V_68 = 0x16 ;
V_123 -> V_106 . V_462 = 0x01 ;
V_461 = V_463 ;
break;
default:
F_17 ( V_112 , V_118 ,
L_77 , V_47 ) ;
F_18 () ;
break;
}
if ( V_34 )
return V_34 ;
V_124 -> V_67 . V_88 = 0x3 ;
V_49 = V_121 -> V_35 . V_91 ;
V_52 = V_45 / V_49 ;
V_50 = V_45 % V_49 ;
V_53 = V_46 / V_49 ;
V_51 = V_46 % V_49 ;
if ( V_124 -> V_67 . V_68 == V_92 ||
V_124 -> V_67 . V_68 == V_93 ) {
if ( V_53 + V_121 -> V_69 . V_94 < V_121 -> V_95 )
V_53 += V_121 -> V_69 . V_94 ;
else
V_53 = ( V_121 -> V_95 - 1 ) ;
}
F_10 ( & V_124 -> V_96 , V_52 , V_50 ) ;
F_10 ( & V_124 -> V_97 , V_53 , V_51 ) ;
V_124 -> V_464 = 0x20 ;
V_124 -> V_465 = V_145 ;
if ( V_99 ) {
switch ( V_121 -> V_35 . V_20 ) {
case 0x3390 :
V_18 = F_8 ( V_48 + 6 , 232 ) ;
V_103 = 9 + F_8 ( V_48 + 6 * ( V_18 + 1 ) , 34 ) ;
V_102 = ( 49 + ( V_99 - 1 ) * ( 10 + V_103 ) ) / 8 ;
break;
case 0x3380 :
V_103 = 7 + F_8 ( V_48 + 12 , 32 ) ;
V_102 = ( 39 + ( V_99 - 1 ) * ( 8 + V_103 ) ) / 7 ;
break;
}
}
if ( V_47 == V_354 ) {
V_123 -> V_106 . V_107 = 0 ;
V_123 -> V_106 . V_466 = 0 ;
V_123 -> V_102 = 0xff ;
} else {
V_123 -> V_106 . V_107 = 1 ;
V_123 -> V_106 . V_466 = 1 ;
V_123 -> V_102 = V_102 ;
}
V_123 -> V_106 . V_467 = 1 ;
V_123 -> V_108 = V_101 ;
V_123 -> V_468 = V_47 ;
V_123 -> V_42 = V_42 ;
F_10 ( & V_123 -> V_113 , V_52 , V_50 ) ;
V_123 -> V_114 . V_23 = V_123 -> V_113 . V_23 ;
V_123 -> V_114 . V_24 = V_123 -> V_113 . V_24 ;
V_123 -> V_114 . V_115 = V_99 ;
V_460 = F_167 ( V_348 , V_461 , 0 ,
& V_117 , sizeof( V_117 ) , V_459 ) ;
return F_168 ( V_460 ) ;
}
static struct V_167 * F_169 (
struct V_30 * V_119 ,
struct V_277 * V_178 ,
struct V_420 * V_421 ,
T_6 V_422 ,
T_6 V_423 ,
T_6 V_424 ,
T_6 V_425 ,
unsigned int V_426 ,
unsigned int V_427 ,
unsigned int V_145 ,
unsigned int V_48 )
{
struct V_167 * V_168 ;
struct V_429 V_430 ;
struct V_431 V_432 ;
char * V_433 ;
unsigned int V_389 , V_469 ;
unsigned char V_47 ;
struct V_30 * V_118 ;
unsigned int V_101 ;
struct V_348 * V_348 ;
struct V_346 * V_347 = NULL ;
int V_470 ;
T_8 V_349 ;
T_7 V_471 ;
unsigned int V_452 , V_453 , V_454 ;
unsigned char V_455 ;
T_6 V_146 , V_445 ;
unsigned int V_472 ;
unsigned int V_42 , V_450 ;
int V_3 ;
V_118 = V_178 -> V_298 ;
if ( F_156 ( V_421 ) == V_437 ) {
V_47 = V_73 ;
V_470 = V_352 ;
} else if ( F_156 ( V_421 ) == V_438 ) {
V_47 = V_86 ;
V_470 = V_473 ;
} else
return F_129 ( - V_127 ) ;
V_389 = V_425 - V_424 + 1 ;
V_469 = 0 ;
F_157 (bv, req, iter) {
++ V_469 ;
}
if ( F_156 ( V_421 ) == V_438 )
V_469 += ( V_425 - V_424 ) ;
V_349 = F_123 ( 0 , V_469 , 0 ) ;
V_168 = F_42 ( V_176 , 0 , V_349 , V_119 ) ;
if ( F_43 ( V_168 ) )
return V_168 ;
if ( V_424 == V_425 )
V_101 = V_427 - V_426 + 1 ;
else
V_101 = V_427 + 1 ;
V_101 *= V_48 ;
V_348 = F_124 ( V_168 -> V_29 , V_349 , V_470 , 0 , V_469 , 0 ) ;
if ( F_43 ( V_348 ) ) {
V_3 = - V_127 ;
goto V_194;
}
V_168 -> V_171 = F_125 ( V_348 ) ;
if ( F_126 ( V_348 , V_424 , V_425 ,
V_47 , V_118 , V_119 ,
V_426 + 1 ,
V_389 , V_48 ,
( V_423 - V_422 + 1 ) * V_48 ,
V_101 , V_145 ) == - V_249 ) {
V_3 = - V_249 ;
goto V_194;
}
V_454 = 0 ;
if ( F_156 ( V_421 ) == V_438 ) {
V_455 = 1 ;
V_146 = V_422 ;
F_157 (bv, req, iter) {
V_433 = F_159 ( V_432 . V_440 ) + V_432 . V_441 ;
V_452 = V_432 . V_439 ;
while ( V_452 ) {
if ( V_455 ) {
V_445 = V_146 ;
V_472 = F_161 ( V_445 , V_145 ) ;
V_450 = V_145 - V_472 ;
V_42 = F_166 ( ( V_423 - V_146 + 1 ) ,
( T_6 ) V_450 ) ;
V_454 = V_42 * V_48 ;
V_146 += V_42 ;
V_455 = 0 ;
}
V_453 = F_166 ( V_452 , V_454 ) ;
V_452 -= V_453 ;
V_454 -= V_453 ;
if ( ! V_454 ) {
V_455 = 1 ;
V_471 = V_474 ;
} else
V_471 = 0 ;
V_347 = F_127 ( V_348 , V_471 ,
V_433 , V_453 ) ;
if ( F_43 ( V_347 ) ) {
V_3 = - V_127 ;
goto V_194;
}
V_433 += V_453 ;
}
}
} else {
F_157 (bv, req, iter) {
V_433 = F_159 ( V_432 . V_440 ) + V_432 . V_441 ;
V_347 = F_127 ( V_348 , 0x00 ,
V_433 , V_432 . V_439 ) ;
if ( F_43 ( V_347 ) ) {
V_3 = - V_127 ;
goto V_194;
}
}
}
V_347 -> V_43 |= V_355 ;
V_347 -> V_43 &= ~ V_474 ;
F_128 ( V_348 ) ;
if ( F_163 ( V_421 ) ||
V_178 -> V_298 -> V_231 & V_448 )
F_33 ( V_273 , & V_168 -> V_43 ) ;
V_168 -> V_356 = 1 ;
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_178 = V_178 ;
V_168 -> V_179 = V_119 -> V_287 * V_180 ;
V_168 -> V_170 = F_164 ( V_119 ) ;
V_168 -> V_181 = V_119 -> V_289 ;
V_168 -> V_182 = F_32 () ;
V_168 -> V_183 = V_184 ;
return V_168 ;
V_194:
F_45 ( V_168 , V_119 ) ;
return F_129 ( V_3 ) ;
}
static struct V_167 * F_170 ( struct V_30 * V_119 ,
struct V_277 * V_178 ,
struct V_420 * V_421 )
{
int V_475 , V_476 ;
int V_360 ;
int V_477 ;
struct V_32 * V_33 ;
struct V_30 * V_118 ;
T_6 V_422 , V_423 ;
T_6 V_424 , V_425 ;
unsigned int V_426 , V_427 ;
unsigned int V_145 , V_48 ;
int V_478 ;
unsigned int V_479 ;
struct V_167 * V_168 ;
V_118 = V_178 -> V_298 ;
V_33 = V_118 -> V_33 ;
V_48 = V_178 -> V_328 ;
V_145 = F_9 ( & V_33 -> V_35 , 0 , V_48 ) ;
if ( V_145 == 0 )
return F_129 ( - V_127 ) ;
V_422 = V_424 = F_171 ( V_421 ) >> V_178 -> V_331 ;
V_426 = F_161 ( V_424 , V_145 ) ;
V_423 = V_425 =
( F_171 ( V_421 ) + F_172 ( V_421 ) - 1 ) >> V_178 -> V_331 ;
V_427 = F_161 ( V_425 , V_145 ) ;
V_478 = ( V_33 -> V_90 && V_422 < 2 * V_145 ) ;
V_477 = V_33 -> V_231 . V_232 [ 40 ] & 0x20 ;
V_479 = F_173 ( V_421 ) ;
if ( V_479 % V_48 )
return F_129 ( - V_127 ) ;
if ( F_156 ( V_421 ) == V_438 )
V_479 += ( V_425 - V_424 ) * 4 ;
V_475 = V_33 -> V_231 . V_232 [ 9 ] & 0x20 ;
V_476 = V_33 -> V_231 . V_232 [ 12 ] & 0x40 ;
V_360 = V_33 -> V_231 . V_232 [ 8 ] & 0x01 ;
V_168 = NULL ;
if ( V_478 || V_442 ) {
} else if ( ( V_479 <= V_33 -> V_234 )
&& ( V_477 || ( V_424 == V_425 ) ) ) {
V_168 = F_169 ( V_119 , V_178 , V_421 ,
V_422 , V_423 ,
V_424 , V_425 ,
V_426 , V_427 ,
V_145 , V_48 ) ;
if ( F_43 ( V_168 ) && ( F_86 ( V_168 ) != - V_249 ) &&
( F_86 ( V_168 ) != - V_197 ) )
V_168 = NULL ;
} else if ( V_360 &&
( ( ( F_156 ( V_421 ) == V_437 ) && V_475 ) ||
( ( F_156 ( V_421 ) == V_438 ) && V_476 ) ) ) {
V_168 = F_165 ( V_119 , V_178 , V_421 ,
V_422 , V_423 ,
V_424 , V_425 ,
V_426 , V_427 ,
V_145 , V_48 ) ;
if ( F_43 ( V_168 ) && ( F_86 ( V_168 ) != - V_249 ) &&
( F_86 ( V_168 ) != - V_197 ) )
V_168 = NULL ;
}
if ( ! V_168 )
V_168 = F_155 ( V_119 , V_178 , V_421 ,
V_422 , V_423 ,
V_424 , V_425 ,
V_426 , V_427 ,
V_145 , V_48 ) ;
return V_168 ;
}
static struct V_167 * F_174 ( struct V_30 * V_119 ,
struct V_277 * V_178 ,
struct V_420 * V_421 )
{
T_6 V_480 , V_481 , V_482 ;
unsigned int V_452 , V_454 ;
unsigned int V_435 , V_314 , V_315 ;
T_6 V_424 , V_425 , V_339 ;
struct V_32 * V_359 ;
struct V_30 * V_118 ;
struct V_429 V_430 ;
struct V_167 * V_168 ;
unsigned int V_426 ;
unsigned int V_389 ;
unsigned long * V_428 ;
unsigned int V_483 ;
unsigned char V_47 ;
struct V_431 V_432 ;
struct V_26 * V_27 ;
int V_360 ;
void * V_29 ;
char * V_433 ;
V_480 = F_171 ( V_421 ) % V_484 ;
V_481 = ( F_171 ( V_421 ) + F_172 ( V_421 ) ) %
V_484 ;
V_482 = ( V_484 - V_481 ) %
V_484 ;
V_118 = V_178 -> V_298 ;
if ( ( V_480 || V_482 ) &&
( F_156 ( V_421 ) == V_438 ) ) {
F_17 ( V_112 , V_118 ,
L_78 ,
V_480 , V_482 , V_421 ) ;
return F_129 ( - V_127 ) ;
}
V_424 = F_171 ( V_421 ) / V_484 ;
V_425 = ( F_171 ( V_421 ) + F_172 ( V_421 ) - 1 ) /
V_484 ;
V_389 = V_425 - V_424 + 1 ;
V_426 = 0 ;
if ( F_156 ( V_421 ) == V_437 )
V_47 = V_72 ;
else if ( F_156 ( V_421 ) == V_438 )
V_47 = V_85 ;
else
return F_129 ( - V_127 ) ;
V_435 = V_389 * V_330 ;
V_359 = V_118 -> V_33 ;
V_360 = V_359 -> V_231 . V_232 [ 8 ] & 0x01 ;
if ( V_360 ) {
V_314 = 1 + V_389 ;
V_483 = sizeof( struct V_116 ) + 2 ;
} else {
V_314 = 2 + V_389 ;
V_483 = sizeof( struct V_28 ) +
sizeof( struct V_98 ) + 2 ;
}
V_483 = F_175 ( V_483 , 8 ) ;
V_315 = V_483 + V_435 * sizeof( unsigned long ) ;
V_168 = F_42 ( V_176 , V_314 ,
V_315 , V_119 ) ;
if ( F_43 ( V_168 ) )
return V_168 ;
V_27 = V_168 -> V_171 ;
V_29 = V_168 -> V_29 ;
if ( V_360 ) {
F_19 ( V_27 ++ , V_29 , V_424 , V_425 , V_47 , V_118 ,
V_119 , 1 , V_426 + 1 , V_389 , 0 , 0 ) ;
} else {
F_13 ( V_27 ++ , V_29 , V_424 , V_425 , V_47 , V_118 , 0 ) ;
V_27 [ - 1 ] . V_43 |= V_262 ;
V_29 += sizeof( struct V_28 ) ;
F_16 ( V_27 ++ , V_29 , V_424 , V_426 + 1 ,
V_389 , V_47 , V_118 , 0 , 0 ) ;
}
V_428 = ( unsigned long * ) ( V_168 -> V_29 + V_483 ) ;
V_454 = 0 ;
if ( V_480 ) {
V_27 [ - 1 ] . V_43 |= V_262 ;
V_27 -> V_54 = V_47 ;
V_27 -> V_42 = 57326 ;
V_454 = 65536 - V_480 * 512 ;
V_27 -> V_56 = ( T_1 ) ( V_173 ) V_428 ;
V_27 -> V_43 |= V_447 ;
V_27 -> V_43 |= V_44 ;
V_27 ++ ;
for ( V_339 = 0 ; V_339 < V_480 ; V_339 += 8 )
V_428 = F_162 ( V_428 , V_485 , V_486 ) ;
}
F_157 (bv, req, iter) {
V_433 = F_159 ( V_432 . V_440 ) + V_432 . V_441 ;
V_452 = V_432 . V_439 ;
if ( V_47 == V_72 )
memset ( V_433 , 0 , V_452 ) ;
if ( ! V_454 ) {
V_27 [ - 1 ] . V_43 |= V_262 ;
V_27 -> V_54 = V_47 ;
V_27 -> V_42 = 57326 ;
V_454 = 65536 ;
V_27 -> V_56 = ( T_1 ) ( V_173 ) V_428 ;
V_27 -> V_43 |= V_447 ;
V_27 -> V_43 |= V_44 ;
V_27 ++ ;
}
V_454 -= V_452 ;
V_428 = F_162 ( V_428 , V_433 , V_452 ) ;
}
for ( V_339 = 0 ; V_339 < V_482 ; V_339 += 8 )
V_428 = F_162 ( V_428 , V_485 , V_486 ) ;
if ( F_163 ( V_421 ) ||
V_178 -> V_298 -> V_231 & V_448 )
F_33 ( V_273 , & V_168 -> V_43 ) ;
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_178 = V_178 ;
V_168 -> V_179 = V_119 -> V_287 * V_180 ;
V_168 -> V_170 = F_164 ( V_119 ) ;
V_168 -> V_181 = V_119 -> V_289 ;
V_168 -> V_182 = F_32 () ;
V_168 -> V_183 = V_184 ;
return V_168 ;
}
static int
F_176 ( struct V_167 * V_168 , struct V_420 * V_421 )
{
struct V_32 * V_33 ;
struct V_26 * V_27 ;
struct V_429 V_430 ;
struct V_431 V_432 ;
char * V_433 , * V_56 ;
unsigned int V_48 , V_145 , V_434 ;
T_6 V_146 ;
int V_183 ;
if ( ! V_442 )
goto V_379;
V_33 = V_168 -> V_178 -> V_298 -> V_33 ;
V_48 = V_168 -> V_178 -> V_328 ;
V_145 = F_9 ( & V_33 -> V_35 , 0 , V_48 ) ;
V_146 = F_171 ( V_421 ) >> V_168 -> V_178 -> V_331 ;
V_27 = V_168 -> V_171 ;
V_27 ++ ;
if ( V_33 -> V_90 == 0 || V_146 > 2 * V_145 )
V_27 ++ ;
F_157 (bv, req, iter) {
V_433 = F_159 ( V_432 . V_440 ) + V_432 . V_441 ;
for ( V_434 = 0 ; V_434 < V_432 . V_439 ; V_434 += V_48 ) {
if ( V_33 -> V_90 && V_146 <= 2 * V_145 )
V_27 ++ ;
if ( V_433 ) {
if ( V_27 -> V_43 & V_447 )
V_56 = * ( ( char * * ) ( ( V_173 ) V_27 -> V_56 ) ) ;
else
V_56 = ( char * ) ( ( V_173 ) V_27 -> V_56 ) ;
if ( V_433 != V_56 ) {
if ( F_156 ( V_421 ) == V_437 )
memcpy ( V_433 , V_56 , V_432 . V_439 ) ;
F_177 ( V_442 ,
( void * ) ( ( V_173 ) V_56 & V_487 ) ) ;
}
V_433 = NULL ;
}
V_27 ++ ;
V_146 ++ ;
}
}
V_379:
V_183 = V_168 -> V_183 == V_186 ;
F_45 ( V_168 , V_168 -> V_177 ) ;
return V_183 ;
}
void F_147 ( struct V_167 * V_168 )
{
struct V_26 * V_27 ;
struct V_116 * V_117 ;
struct V_488 * V_488 ;
struct V_489 * V_489 ;
struct V_460 * V_460 ;
if ( V_168 -> V_356 == 1 ) {
V_488 = V_168 -> V_171 ;
V_489 = F_178 ( V_488 ) ;
V_460 = (struct V_460 * ) & V_489 -> V_490 [ 0 ] ;
V_117 = (struct V_116 * ) & V_460 -> V_491 [ 0 ] ;
V_117 -> V_133 . V_136 = 0 ;
V_117 -> V_133 . V_138 = 0 ;
} else {
V_27 = V_168 -> V_171 ;
V_117 = V_168 -> V_29 ;
if ( V_27 -> V_54 == V_126 ) {
V_117 -> V_133 . V_136 = 0 ;
V_117 -> V_133 . V_138 = 0 ;
}
}
}
static struct V_167 * F_179 ( struct V_30 * V_298 ,
struct V_277 * V_178 ,
struct V_420 * V_421 )
{
struct V_32 * V_33 ;
struct V_30 * V_119 ;
unsigned long V_43 ;
struct V_167 * V_168 ;
V_119 = F_122 ( V_298 ) ;
if ( ! V_119 )
V_119 = V_298 ;
V_33 = V_119 -> V_33 ;
if ( V_33 -> V_42 >= V_492 )
return F_129 ( - V_493 ) ;
F_26 ( F_27 ( V_119 -> V_2 ) , V_43 ) ;
V_33 -> V_42 ++ ;
if ( ( V_298 -> V_231 & V_301 ) )
V_168 = F_174 ( V_119 , V_178 , V_421 ) ;
else
V_168 = F_170 ( V_119 , V_178 , V_421 ) ;
if ( F_43 ( V_168 ) )
V_33 -> V_42 -- ;
F_28 ( F_27 ( V_119 -> V_2 ) , V_43 ) ;
return V_168 ;
}
static int F_180 ( struct V_167 * V_168 ,
struct V_420 * V_421 )
{
struct V_32 * V_33 ;
unsigned long V_43 ;
F_26 ( F_27 ( V_168 -> V_177 -> V_2 ) , V_43 ) ;
V_33 = V_168 -> V_177 -> V_33 ;
V_33 -> V_42 -- ;
F_28 ( F_27 ( V_168 -> V_177 -> V_2 ) , V_43 ) ;
return F_176 ( V_168 , V_421 ) ;
}
static int
F_181 ( struct V_30 * V_31 ,
struct V_494 * V_495 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
V_495 -> V_496 = 2 ;
V_495 -> V_497 = V_33 -> V_90 ? 0 : 1 ;
V_495 -> V_120 = V_33 -> V_90 ? V_498 : V_499 ;
V_495 -> V_500 = sizeof( V_33 -> V_35 ) ;
memcpy ( V_495 -> V_501 , & V_33 -> V_35 ,
sizeof( V_33 -> V_35 ) ) ;
V_495 -> V_502 = F_166 ( ( unsigned long ) V_33 -> V_200 ,
sizeof( V_495 -> V_503 ) ) ;
memcpy ( V_495 -> V_503 , V_33 -> V_201 ,
V_495 -> V_502 ) ;
return 0 ;
}
static int
F_182 ( struct V_30 * V_31 )
{
struct V_167 * V_168 ;
int V_34 ;
struct V_26 * V_27 ;
int V_504 ;
if ( ! F_183 ( V_505 ) )
return - V_41 ;
V_504 = 0 ;
V_168 = F_42 ( V_176 , 1 , 32 , V_31 ) ;
if ( F_43 ( V_168 ) ) {
F_184 ( & V_506 ) ;
V_504 = 1 ;
V_168 = & V_507 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_507 -> V_27 , 0 ,
sizeof( V_507 -> V_27 ) ) ;
V_168 -> V_171 = & V_507 -> V_27 ;
V_168 -> V_29 = & V_507 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_27 = V_168 -> V_171 ;
V_27 -> V_54 = V_508 ;
V_27 -> V_43 |= V_44 ;
V_27 -> V_42 = 32 ;
V_27 -> V_56 = ( T_1 ) ( V_173 ) V_168 -> V_29 ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
F_38 ( V_189 , & V_168 -> V_43 ) ;
F_33 ( V_273 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 2 ;
V_168 -> V_179 = 2 * V_180 ;
V_168 -> V_182 = F_32 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_39 ( V_168 ) ;
if ( ! V_34 )
F_38 ( V_417 , & V_31 -> V_43 ) ;
if ( V_504 )
F_75 ( & V_506 ) ;
else
F_45 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_185 ( struct V_30 * V_31 )
{
struct V_167 * V_168 ;
int V_34 ;
struct V_26 * V_27 ;
int V_504 ;
if ( ! F_183 ( V_505 ) )
return - V_41 ;
V_504 = 0 ;
V_168 = F_42 ( V_176 , 1 , 32 , V_31 ) ;
if ( F_43 ( V_168 ) ) {
F_184 ( & V_506 ) ;
V_504 = 1 ;
V_168 = & V_507 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_507 -> V_27 , 0 ,
sizeof( V_507 -> V_27 ) ) ;
V_168 -> V_171 = & V_507 -> V_27 ;
V_168 -> V_29 = & V_507 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_27 = V_168 -> V_171 ;
V_27 -> V_54 = V_509 ;
V_27 -> V_43 |= V_44 ;
V_27 -> V_42 = 32 ;
V_27 -> V_56 = ( T_1 ) ( V_173 ) V_168 -> V_29 ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
F_38 ( V_189 , & V_168 -> V_43 ) ;
F_33 ( V_273 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 2 ;
V_168 -> V_179 = 2 * V_180 ;
V_168 -> V_182 = F_32 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_39 ( V_168 ) ;
if ( ! V_34 )
F_33 ( V_417 , & V_31 -> V_43 ) ;
if ( V_504 )
F_75 ( & V_506 ) ;
else
F_45 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_186 ( struct V_30 * V_31 )
{
struct V_167 * V_168 ;
int V_34 ;
struct V_26 * V_27 ;
int V_504 ;
if ( ! F_183 ( V_505 ) )
return - V_41 ;
V_504 = 0 ;
V_168 = F_42 ( V_176 , 1 , 32 , V_31 ) ;
if ( F_43 ( V_168 ) ) {
F_184 ( & V_506 ) ;
V_504 = 1 ;
V_168 = & V_507 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_507 -> V_27 , 0 ,
sizeof( V_507 -> V_27 ) ) ;
V_168 -> V_171 = & V_507 -> V_27 ;
V_168 -> V_29 = & V_507 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_27 = V_168 -> V_171 ;
V_27 -> V_54 = V_510 ;
V_27 -> V_43 |= V_44 ;
V_27 -> V_42 = 32 ;
V_27 -> V_56 = ( T_1 ) ( V_173 ) V_168 -> V_29 ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
F_38 ( V_189 , & V_168 -> V_43 ) ;
F_33 ( V_273 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 2 ;
V_168 -> V_179 = 2 * V_180 ;
V_168 -> V_182 = F_32 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_39 ( V_168 ) ;
if ( ! V_34 )
F_33 ( V_417 , & V_31 -> V_43 ) ;
if ( V_504 )
F_75 ( & V_506 ) ;
else
F_45 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int F_187 ( struct V_30 * V_31 ,
void T_9 * V_511 )
{
struct V_167 * V_168 ;
int V_34 ;
struct V_26 * V_27 ;
int V_504 ;
struct V_512 V_513 ;
if ( ! F_183 ( V_505 ) )
return - V_41 ;
if ( F_188 ( & V_513 , V_511 , sizeof( V_513 ) ) )
return - V_514 ;
V_504 = 0 ;
V_168 = F_42 ( V_176 , 1 ,
sizeof( struct V_515 ) , V_31 ) ;
if ( F_43 ( V_168 ) ) {
F_184 ( & V_506 ) ;
V_504 = 1 ;
V_168 = & V_507 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_507 -> V_27 , 0 ,
sizeof( V_507 -> V_27 ) ) ;
V_168 -> V_171 = & V_507 -> V_27 ;
V_168 -> V_29 = & V_507 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_27 = V_168 -> V_171 ;
V_27 -> V_54 = V_516 ;
V_27 -> V_43 |= V_44 ;
V_27 -> V_42 = 12 ;
V_27 -> V_56 = ( T_1 ) ( V_173 ) V_168 -> V_29 ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
F_38 ( V_189 , & V_168 -> V_43 ) ;
F_33 ( V_273 , & V_168 -> V_43 ) ;
F_33 ( V_190 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 5 ;
V_168 -> V_179 = 10 * V_180 ;
V_168 -> V_182 = F_32 () ;
V_168 -> V_183 = V_184 ;
V_168 -> V_170 = V_513 . V_517 ;
V_34 = F_39 ( V_168 ) ;
if ( ! V_34 && V_513 . V_517 && ( V_168 -> V_170 != V_513 . V_517 ) )
V_34 = - V_283 ;
if ( ! V_34 ) {
V_513 . V_29 = * ( (struct V_515 * ) V_168 -> V_29 ) ;
if ( F_189 ( V_511 , & V_513 , sizeof( V_513 ) ) )
V_34 = - V_514 ;
}
if ( V_504 )
F_75 ( & V_506 ) ;
else
F_45 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_190 ( struct V_30 * V_31 , void T_9 * V_511 )
{
struct V_255 * V_256 ;
struct V_518 * V_519 ;
struct V_167 * V_168 ;
struct V_26 * V_27 ;
int V_34 ;
V_168 = F_42 ( V_176 , 1 + 1 ,
( sizeof( struct V_255 ) +
sizeof( struct V_518 ) ) ,
V_31 ) ;
if ( F_43 ( V_168 ) ) {
F_17 ( V_7 , V_31 , L_1 ,
L_79 ) ;
return F_86 ( V_168 ) ;
}
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_181 = 0 ;
F_38 ( V_189 , & V_168 -> V_43 ) ;
V_168 -> V_179 = 10 * V_180 ;
V_256 = (struct V_255 * ) V_168 -> V_29 ;
memset ( V_256 , 0 , sizeof( struct V_255 ) ) ;
V_256 -> V_258 = V_259 ;
V_256 -> V_260 = 0x01 ;
V_256 -> V_520 [ 1 ] = 0x01 ;
V_27 = V_168 -> V_171 ;
V_27 -> V_54 = V_261 ;
V_27 -> V_42 = sizeof( struct V_255 ) ;
V_27 -> V_43 |= V_262 ;
V_27 -> V_56 = ( T_1 ) ( V_173 ) V_256 ;
V_519 = (struct V_518 * ) ( V_256 + 1 ) ;
memset ( V_519 , 0 , sizeof( struct V_518 ) ) ;
V_27 ++ ;
V_27 -> V_54 = V_263 ;
V_27 -> V_42 = sizeof( struct V_518 ) ;
V_27 -> V_56 = ( T_1 ) ( V_173 ) V_519 ;
V_168 -> V_182 = F_32 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_44 ( V_168 ) ;
if ( V_34 == 0 ) {
V_256 = (struct V_255 * ) V_168 -> V_29 ;
V_519 = (struct V_518 * ) ( V_256 + 1 ) ;
if ( F_189 ( V_511 , V_519 ,
sizeof( struct V_518 ) ) )
V_34 = - V_514 ;
}
F_45 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_191 ( struct V_30 * V_31 , void T_9 * V_511 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_521 V_69 = V_33 -> V_69 ;
int V_34 ;
if ( ! F_183 ( V_505 ) )
return - V_41 ;
if ( ! V_511 )
return - V_127 ;
V_34 = 0 ;
if ( F_189 ( V_511 , ( long * ) & V_69 ,
sizeof( struct V_521 ) ) )
V_34 = - V_514 ;
return V_34 ;
}
static int
F_192 ( struct V_30 * V_31 , void T_9 * V_511 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_521 V_69 ;
if ( ! F_183 ( V_505 ) )
return - V_41 ;
if ( ! V_511 )
return - V_127 ;
if ( F_188 ( & V_69 , V_511 , sizeof( struct V_521 ) ) )
return - V_514 ;
V_33 -> V_69 = V_69 ;
F_96 ( & V_31 -> V_2 -> V_87 ,
L_80 ,
V_33 -> V_69 . V_68 , V_33 -> V_69 . V_94 ) ;
return 0 ;
}
static int F_193 ( struct V_30 * V_31 , void T_9 * V_511 )
{
struct V_522 V_513 ;
char * V_523 , * V_524 ;
struct V_167 * V_168 ;
struct V_26 * V_27 ;
char V_525 , V_526 ;
int V_34 ;
if ( ! F_183 ( V_505 ) && ! F_183 ( V_527 ) )
return - V_41 ;
V_525 = V_526 = 0 ;
V_34 = - V_514 ;
if ( F_188 ( & V_513 , V_511 , sizeof( V_513 ) ) )
goto V_379;
if ( F_194 () ) {
V_34 = - V_127 ;
if ( ( V_513 . V_523 >> 32 ) != 0 )
goto V_379;
if ( ( V_513 . V_524 >> 32 ) != 0 )
goto V_379;
V_513 . V_523 &= 0x7fffffffULL ;
V_513 . V_524 &= 0x7fffffffULL ;
}
V_523 = F_41 ( V_513 . V_528 , V_195 | V_196 ) ;
V_524 = F_41 ( V_513 . V_529 , V_195 | V_196 ) ;
if ( ! V_523 || ! V_524 ) {
V_34 = - V_197 ;
goto V_530;
}
V_34 = - V_514 ;
if ( F_188 ( V_523 ,
( void T_9 * ) ( unsigned long ) V_513 . V_523 ,
V_513 . V_528 ) )
goto V_530;
V_525 = V_523 [ 0 ] ;
V_526 = V_523 [ 1 ] ;
V_168 = F_42 ( V_176 , 2 , 0 , V_31 ) ;
if ( F_43 ( V_168 ) ) {
F_17 ( V_7 , V_31 , L_1 ,
L_79 ) ;
V_34 = F_86 ( V_168 ) ;
goto V_530;
}
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_181 = 3 ;
V_168 -> V_179 = 10 * V_180 ;
V_168 -> V_182 = F_32 () ;
V_168 -> V_183 = V_184 ;
V_27 = V_168 -> V_171 ;
V_27 -> V_54 = V_261 ;
V_27 -> V_42 = V_513 . V_528 ;
V_27 -> V_43 |= V_262 ;
V_27 -> V_56 = ( T_1 ) ( V_173 ) V_523 ;
V_27 ++ ;
V_27 -> V_54 = V_263 ;
V_27 -> V_42 = V_513 . V_529 ;
V_27 -> V_43 = V_44 ;
V_27 -> V_56 = ( T_1 ) ( V_173 ) V_524 ;
V_34 = F_44 ( V_168 ) ;
if ( V_34 )
goto V_531;
V_34 = - V_514 ;
if ( F_189 ( ( void T_9 * ) ( unsigned long ) V_513 . V_524 ,
V_524 , V_513 . V_529 ) )
goto V_531;
V_34 = 0 ;
V_531:
F_45 ( V_168 , V_168 -> V_177 ) ;
V_530:
F_46 ( V_524 ) ;
F_46 ( V_523 ) ;
V_379:
F_17 ( V_7 , V_31 ,
L_81 ,
( int ) V_525 , ( int ) V_526 , V_34 ) ;
return V_34 ;
}
static int
F_195 ( struct V_277 * V_178 , unsigned int V_47 , void T_9 * V_511 )
{
struct V_30 * V_31 = V_178 -> V_298 ;
switch ( V_47 ) {
case V_532 :
return F_191 ( V_31 , V_511 ) ;
case V_533 :
return F_192 ( V_31 , V_511 ) ;
case V_534 :
return F_190 ( V_31 , V_511 ) ;
case V_535 :
return F_182 ( V_31 ) ;
case V_536 :
return F_185 ( V_31 ) ;
case V_537 :
return F_186 ( V_31 ) ;
case V_538 :
return F_187 ( V_31 , V_511 ) ;
case V_539 :
return F_193 ( V_31 , V_511 ) ;
default:
return - V_540 ;
}
}
static int
F_196 ( struct V_26 * V_541 , struct V_26 * V_542 , char * V_543 )
{
int V_544 , V_42 ;
char * V_545 ;
V_544 = 0 ;
while ( V_541 <= V_542 ) {
V_544 += sprintf ( V_543 + V_544 , V_546
L_82 ,
V_541 , ( ( int * ) V_541 ) [ 0 ] , ( ( int * ) V_541 ) [ 1 ] ) ;
if ( V_541 -> V_43 & V_447 )
V_545 = ( char * ) * ( ( V_173 * ) ( V_173 ) V_541 -> V_56 ) ;
else
V_545 = ( char * ) ( ( V_173 ) V_541 -> V_56 ) ;
for ( V_42 = 0 ; V_42 < V_541 -> V_42 && V_42 < 32 ; V_42 ++ ) {
if ( V_42 % 8 == 0 ) V_544 += sprintf ( V_543 + V_544 , L_83 ) ;
if ( V_42 % 4 == 0 ) V_544 += sprintf ( V_543 + V_544 , L_83 ) ;
V_544 += sprintf ( V_543 + V_544 , L_10 , V_545 [ V_42 ] ) ;
}
V_544 += sprintf ( V_543 + V_544 , L_84 ) ;
V_541 ++ ;
}
return V_544 ;
}
static void
F_197 ( struct V_30 * V_31 , struct V_322 * V_322 ,
char * V_547 )
{
T_10 * V_318 ;
T_10 * V_548 ;
V_318 = ( T_10 * ) F_106 ( V_322 ) ;
V_548 = ( T_10 * ) & V_322 -> V_402 ;
if ( V_318 ) {
F_17 ( V_549 , V_31 , L_85
L_86 ,
V_547 , * V_548 , * ( ( T_4 * ) ( V_548 + 1 ) ) ,
V_318 [ 0 ] , V_318 [ 1 ] , V_318 [ 2 ] , V_318 [ 3 ] ) ;
} else {
F_17 ( V_549 , V_31 , L_87 ,
V_547 , * V_548 , * ( ( T_4 * ) ( V_548 + 1 ) ) ,
L_88 ) ;
}
}
static void F_198 ( struct V_30 * V_31 ,
struct V_167 * V_421 , struct V_322 * V_322 )
{
char * V_543 ;
struct V_26 * V_550 , * V_551 , * V_552 , * V_541 , * V_542 ;
int V_544 , V_553 , V_554 ;
V_543 = ( char * ) F_199 ( V_252 ) ;
if ( V_543 == NULL ) {
F_17 ( V_7 , V_31 , L_1 ,
L_89 ) ;
return;
}
V_544 = sprintf ( V_543 , V_546
L_90 ,
F_200 ( & V_31 -> V_2 -> V_87 ) ) ;
V_544 += sprintf ( V_543 + V_544 , V_546
L_91
L_92 ,
V_421 , F_201 ( & V_322 -> V_402 ) , F_202 ( & V_322 -> V_402 ) ,
F_203 ( & V_322 -> V_402 ) , F_204 ( & V_322 -> V_402 ) ,
F_151 ( & V_322 -> V_402 ) , F_145 ( & V_322 -> V_402 ) ,
V_421 ? V_421 -> V_269 : 0 ) ;
V_544 += sprintf ( V_543 + V_544 , V_546
L_93 ,
F_200 ( & V_31 -> V_2 -> V_87 ) ,
( void * ) ( V_173 ) V_322 -> V_402 . V_47 . V_555 ) ;
if ( V_322 -> V_556 . V_557 . V_558 . V_559 ) {
for ( V_553 = 0 ; V_553 < 4 ; V_553 ++ ) {
V_544 += sprintf ( V_543 + V_544 , V_546
L_94 ,
( 8 * V_553 ) , ( ( 8 * V_553 ) + 7 ) ) ;
for ( V_554 = 0 ; V_554 < 8 ; V_554 ++ ) {
V_544 += sprintf ( V_543 + V_544 , L_95 ,
V_322 -> V_560 [ 8 * V_553 + V_554 ] ) ;
}
V_544 += sprintf ( V_543 + V_544 , L_84 ) ;
}
if ( V_322 -> V_560 [ 27 ] & V_411 ) {
sprintf ( V_543 + V_544 , V_546
L_96
L_97 ,
V_322 -> V_560 [ 7 ] >> 4 , V_322 -> V_560 [ 7 ] & 0x0f ,
V_322 -> V_560 [ 1 ] & 0x10 ? L_57 : L_98 ) ;
} else {
sprintf ( V_543 + V_544 , V_546
L_99
L_100 ,
V_322 -> V_560 [ 6 ] & 0x0f , V_322 -> V_560 [ 22 ] >> 4 ) ;
}
} else {
sprintf ( V_543 + V_544 , V_546
L_101 ) ;
}
F_205 ( V_561 L_1 , V_543 ) ;
if ( V_421 ) {
V_550 = V_421 -> V_171 ;
for ( V_551 = V_550 ; V_551 -> V_43 & ( V_262 | V_562 ) ; V_551 ++ ) ;
V_542 = F_166 ( V_550 + 6 , V_551 ) ;
V_544 = sprintf ( V_543 , V_546
L_102 , V_421 ) ;
F_196 ( V_550 , V_542 , V_543 + V_544 ) ;
F_205 ( V_561 L_1 , V_543 ) ;
V_544 = 0 ;
V_541 = ++ V_542 ;
V_552 = (struct V_26 * ) ( V_173 )
V_322 -> V_402 . V_47 . V_555 ;
if ( V_541 < V_552 - 2 ) {
V_541 = V_552 - 2 ;
V_544 += sprintf ( V_543 , V_546 L_103 ) ;
}
V_542 = F_166 ( V_552 + 1 , V_551 ) ;
V_544 += F_196 ( V_541 , V_542 , V_543 + V_544 ) ;
V_541 = V_383 ( V_541 , ++ V_542 ) ;
if ( V_541 < V_551 - 1 ) {
V_541 = V_551 - 1 ;
V_544 += sprintf ( V_543 + V_544 , V_546 L_103 ) ;
}
V_544 += F_196 ( V_541 , V_551 , V_543 + V_544 ) ;
if ( V_544 > 0 )
F_205 ( V_561 L_1 , V_543 ) ;
}
F_206 ( ( unsigned long ) V_543 ) ;
}
static void F_207 ( struct V_30 * V_31 ,
struct V_167 * V_421 , struct V_322 * V_322 )
{
char * V_543 ;
int V_544 , V_553 , V_554 , V_563 ;
struct V_564 * V_564 ;
T_7 * V_318 , * V_565 ;
V_543 = ( char * ) F_199 ( V_252 ) ;
if ( V_543 == NULL ) {
F_17 ( V_7 , V_31 , L_104 ,
L_105 ) ;
return;
}
V_544 = sprintf ( V_543 , V_546
L_90 ,
F_200 ( & V_31 -> V_2 -> V_87 ) ) ;
V_544 += sprintf ( V_543 + V_544 , V_546
L_91
L_106 ,
V_421 , F_201 ( & V_322 -> V_402 ) , F_202 ( & V_322 -> V_402 ) ,
F_203 ( & V_322 -> V_402 ) , F_204 ( & V_322 -> V_402 ) ,
F_151 ( & V_322 -> V_402 ) , F_145 ( & V_322 -> V_402 ) ,
V_322 -> V_402 . V_566 . V_567 ,
( V_322 -> V_402 . V_566 . V_568 << 7 ) | V_322 -> V_402 . V_566 . V_569 ,
V_421 ? V_421 -> V_269 : 0 ) ;
V_544 += sprintf ( V_543 + V_544 , V_546
L_107 ,
F_200 ( & V_31 -> V_2 -> V_87 ) ,
( void * ) ( V_173 ) V_322 -> V_402 . V_566 . V_488 ) ;
V_564 = NULL ;
V_318 = NULL ;
if ( V_322 -> V_402 . V_566 . V_488 && ( V_322 -> V_402 . V_566 . V_567 & 0x01 ) )
V_564 = F_208 (
(struct V_488 * ) ( unsigned long ) V_322 -> V_402 . V_566 . V_488 ) ;
if ( V_564 ) {
V_544 += sprintf ( V_543 + V_544 , V_546
L_108 , V_564 -> V_108 ) ;
V_544 += sprintf ( V_543 + V_544 , V_546
L_109 , V_564 -> V_43 ) ;
V_544 += sprintf ( V_543 + V_544 , V_546
L_110 , V_564 -> V_570 ) ;
V_544 += sprintf ( V_543 + V_544 , V_546
L_111 , V_564 -> V_42 ) ;
V_563 = V_564 -> V_42 - 28 ;
V_544 += sprintf ( V_543 + V_544 , V_546
L_112 , V_563 ) ;
switch ( V_564 -> V_43 & 0x07 ) {
case 1 :
V_544 += sprintf ( V_543 + V_544 , V_546
L_113 ,
V_564 -> V_571 . V_572 . V_573 ) ;
V_544 += sprintf ( V_543 + V_544 , V_546
L_114 ,
V_564 -> V_571 . V_572 . V_574 ) ;
V_544 += sprintf ( V_543 + V_544 , V_546
L_115 ,
V_564 -> V_571 . V_572 . V_575 ) ;
V_544 += sprintf ( V_543 + V_544 , V_546
L_116 ,
V_564 -> V_571 . V_572 . V_576 ) ;
V_544 += sprintf ( V_543 + V_544 , V_546
L_117 ,
V_564 -> V_571 . V_572 . V_577 ) ;
V_318 = V_564 -> V_571 . V_572 . V_318 ;
break;
case 2 :
V_544 += sprintf ( V_543 + V_544 , V_546
L_118 , V_564 -> V_571 . V_578 . V_34 ) ;
for ( V_553 = 0 ; V_553 < 2 ; V_553 ++ ) {
V_544 += sprintf ( V_543 + V_544 , V_546
L_119 ,
( 8 * V_553 ) , ( ( 8 * V_553 ) + 7 ) ) ;
V_565 = V_564 -> V_571 . V_578 . V_565 ;
for ( V_554 = 0 ; V_554 < 8 ; V_554 ++ ) {
V_544 += sprintf ( V_543 + V_544 , L_95 ,
V_565 [ 8 * V_553 + V_554 ] ) ;
}
V_544 += sprintf ( V_543 + V_544 , L_84 ) ;
}
V_318 = V_564 -> V_571 . V_578 . V_318 ;
break;
case 3 :
V_544 += sprintf ( V_543 + V_544 , V_546
L_120 ) ;
break;
}
if ( V_318 ) {
for ( V_553 = 0 ; V_553 < 4 ; V_553 ++ ) {
V_544 += sprintf ( V_543 + V_544 , V_546
L_94 ,
( 8 * V_553 ) , ( ( 8 * V_553 ) + 7 ) ) ;
for ( V_554 = 0 ; V_554 < 8 ; V_554 ++ ) {
V_544 += sprintf ( V_543 + V_544 , L_95 ,
V_318 [ 8 * V_553 + V_554 ] ) ;
}
V_544 += sprintf ( V_543 + V_544 , L_84 ) ;
}
if ( V_318 [ 27 ] & V_411 ) {
sprintf ( V_543 + V_544 , V_546
L_96
L_97 ,
V_318 [ 7 ] >> 4 , V_318 [ 7 ] & 0x0f ,
V_318 [ 1 ] & 0x10 ? L_57 : L_98 ) ;
} else {
sprintf ( V_543 + V_544 , V_546
L_99
L_100 ,
V_318 [ 6 ] & 0x0f , V_318 [ 22 ] >> 4 ) ;
}
} else {
sprintf ( V_543 + V_544 , V_546
L_101 ) ;
}
} else {
sprintf ( V_543 + V_544 , V_546
L_121 ) ;
}
F_205 ( V_561 L_1 , V_543 ) ;
F_206 ( ( unsigned long ) V_543 ) ;
}
static void F_209 ( struct V_30 * V_31 ,
struct V_167 * V_421 , struct V_322 * V_322 )
{
T_7 * V_318 = F_106 ( V_322 ) ;
if ( F_210 ( & V_322 -> V_402 ) ) {
if ( V_318 && ( V_318 [ 1 ] & V_381 ) &&
F_69 ( V_357 , & V_421 -> V_43 ) )
return;
if ( F_145 ( & V_322 -> V_402 ) == 0x40 &&
F_69 ( V_358 , & V_421 -> V_43 ) )
return;
F_207 ( V_31 , V_421 , V_322 ) ;
} else {
if ( V_318 && V_318 [ 0 ] & V_579 &&
F_69 ( V_580 , & V_421 -> V_43 ) )
return;
if ( V_318 && V_318 [ 1 ] & V_323 &&
F_69 ( V_361 , & V_421 -> V_43 ) )
return;
F_198 ( V_31 , V_421 , V_322 ) ;
}
}
static int F_211 ( struct V_30 * V_31 )
{
F_119 ( V_31 ) ;
F_101 ( V_31 ) ;
return 0 ;
}
static int F_212 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_14 V_581 ;
int V_34 ;
struct V_149 V_278 ;
unsigned long V_43 ;
unsigned long V_582 = 0 ;
V_34 = F_50 ( V_31 ) ;
if ( V_34 ) {
F_3 ( V_7 , V_31 -> V_2 ,
L_122 , V_34 ) ;
goto V_353;
}
F_29 ( V_31 , & V_278 ) ;
V_34 = F_25 ( V_31 ) ;
F_26 ( F_27 ( V_31 -> V_2 ) , V_43 ) ;
if ( memcmp ( & V_33 -> V_134 , & V_278 , sizeof( struct V_149 ) ) != 0 )
F_15 ( & V_31 -> V_2 -> V_87 , L_123
L_124 ) ;
F_28 ( F_27 ( V_31 -> V_2 ) , V_43 ) ;
if ( V_34 )
goto V_353;
V_34 = F_98 ( V_31 ) ;
if ( V_34 )
goto V_353;
F_33 ( V_273 , & V_582 ) ;
F_90 ( V_31 , V_582 ) ;
V_34 = F_50 ( V_31 ) ;
if ( V_34 ) {
F_3 ( V_7 , V_31 -> V_2 ,
L_122 , V_34 ) ;
goto V_299;
}
F_85 ( V_31 ) ;
V_34 = F_99 ( V_31 , V_176 ,
& V_581 , 64 ) ;
if ( V_34 ) {
F_3 ( V_7 , V_31 -> V_2 ,
L_51 , V_34 ) ;
goto V_299;
}
F_26 ( F_27 ( V_31 -> V_2 ) , V_43 ) ;
memcpy ( & V_33 -> V_35 , & V_581 , sizeof( V_581 ) ) ;
F_28 ( F_27 ( V_31 -> V_2 ) , V_43 ) ;
F_115 ( V_31 ) ;
return 0 ;
V_299:
F_101 ( V_31 ) ;
V_353:
return - 1 ;
}
static int F_213 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
int V_34 , V_583 ;
char V_244 [ 60 ] ;
struct V_149 V_134 ;
unsigned long V_43 ;
F_119 ( V_31 ) ;
F_26 ( F_27 ( V_31 -> V_2 ) , V_43 ) ;
V_583 = V_33 -> V_134 . V_161 ;
F_28 ( F_27 ( V_31 -> V_2 ) , V_43 ) ;
V_34 = F_50 ( V_31 ) ;
if ( V_34 )
goto V_353;
V_34 = F_25 ( V_31 ) ;
if ( V_34 )
goto V_353;
F_214 ( V_31 ) ;
F_29 ( V_31 , & V_134 ) ;
if ( V_583 != V_134 . V_161 ) {
if ( strlen ( V_134 . V_163 ) > 0 )
snprintf ( V_244 , sizeof( V_244 ) ,
L_16 , V_134 . V_150 , V_134 . V_152 ,
V_134 . V_154 , V_134 . V_161 , V_134 . V_163 ) ;
else
snprintf ( V_244 , sizeof( V_244 ) ,
L_17 , V_134 . V_150 , V_134 . V_152 ,
V_134 . V_154 , V_134 . V_161 ) ;
F_96 ( & V_31 -> V_2 -> V_87 ,
L_125
L_126 , V_244 ) ;
}
return 0 ;
V_353:
return - 1 ;
}
static int F_215 ( struct V_30 * V_31 ,
struct V_584 * V_585 ,
T_2 V_586 )
{
struct V_584 * V_587 ;
struct V_255 * V_256 ;
struct V_167 * V_168 ;
struct V_26 * V_27 ;
int V_34 ;
V_168 = F_42 ( V_176 , 1 + 1 ,
( sizeof( struct V_255 ) +
sizeof( struct V_584 ) ) ,
V_31 ) ;
if ( F_43 ( V_168 ) ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_127 ) ;
return F_86 ( V_168 ) ;
}
V_168 -> V_170 = V_586 ;
V_377:
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_178 = NULL ;
V_168 -> V_179 = 10 * V_180 ;
F_33 ( V_185 , & V_168 -> V_43 ) ;
F_38 ( V_189 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 256 ;
V_256 = (struct V_255 * ) V_168 -> V_29 ;
memset ( V_256 , 0 , sizeof( struct V_255 ) ) ;
V_256 -> V_258 = V_259 ;
V_256 -> V_260 = 0x03 ;
V_27 = V_168 -> V_171 ;
V_27 -> V_54 = V_261 ;
V_27 -> V_42 = sizeof( struct V_255 ) ;
V_27 -> V_43 |= V_262 ;
V_27 -> V_43 |= V_44 ;
V_27 -> V_56 = ( T_1 ) ( V_173 ) V_256 ;
V_587 = (struct V_584 * ) ( V_256 + 1 ) ;
memset ( V_587 , 0 , sizeof( struct V_584 ) ) ;
V_27 ++ ;
V_27 -> V_54 = V_263 ;
V_27 -> V_42 = sizeof( struct V_584 ) ;
V_27 -> V_43 |= V_44 ;
V_27 -> V_56 = ( T_1 ) ( V_173 ) V_587 ;
V_168 -> V_182 = F_32 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_39 ( V_168 ) ;
if ( V_34 == 0 ) {
V_256 = (struct V_255 * ) V_168 -> V_29 ;
V_587 = (struct V_584 * )
( V_256 + 1 ) ;
memcpy ( V_585 , V_587 ,
sizeof( struct V_584 ) ) ;
} else if ( V_168 -> V_170 ) {
V_168 -> V_170 = 0 ;
goto V_377;
} else
F_3 ( V_7 , V_31 -> V_2 ,
L_128
, V_34 ) ;
F_45 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int F_216 ( struct V_30 * V_31 ,
struct V_588 * V_29 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_588 * V_589 ;
struct V_255 * V_256 ;
struct V_167 * V_168 ;
struct V_26 * V_27 ;
int V_34 ;
if ( ! V_31 -> V_178 && V_33 -> V_410 -> V_590 == V_591 )
return - V_40 ;
if ( ! ( V_33 -> V_231 . V_232 [ 14 ] & 0x80 ) )
return - V_40 ;
V_168 = F_42 ( V_176 , 1 + 1 ,
sizeof( struct V_255 ) + 1 ,
V_31 ) ;
if ( F_43 ( V_168 ) ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_127 ) ;
return F_86 ( V_168 ) ;
}
V_589 = F_41 ( sizeof( * V_589 ) , V_195 | V_196 ) ;
if ( ! V_589 ) {
F_45 ( V_168 , V_31 ) ;
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_129 ) ;
return - V_197 ;
}
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_178 = NULL ;
V_168 -> V_181 = 256 ;
V_168 -> V_179 = 10 * V_180 ;
V_256 = (struct V_255 * ) V_168 -> V_29 ;
memset ( V_256 , 0 , sizeof( struct V_255 ) ) ;
V_256 -> V_258 = V_259 ;
V_256 -> V_260 = V_592 ;
V_256 -> V_593 = V_33 -> V_129 -> V_132 ;
V_256 -> V_594 = V_33 -> V_129 -> V_130 ;
V_27 = V_168 -> V_171 ;
V_27 -> V_54 = V_261 ;
V_27 -> V_42 = sizeof( struct V_255 ) ;
V_27 -> V_43 |= V_262 ;
V_27 -> V_43 |= V_44 ;
V_27 -> V_56 = ( T_1 ) ( V_173 ) V_256 ;
V_27 ++ ;
V_27 -> V_54 = V_263 ;
V_27 -> V_42 = sizeof( struct V_588 ) ;
V_27 -> V_43 |= V_44 ;
V_27 -> V_56 = ( T_1 ) ( V_173 ) V_589 ;
V_168 -> V_182 = F_32 () ;
V_168 -> V_183 = V_184 ;
F_217 ( V_580 , & V_168 -> V_43 ) ;
V_34 = F_218 ( V_168 ) ;
if ( V_34 == 0 ) {
* V_29 = * V_589 ;
} else {
F_3 ( V_7 , V_31 -> V_2 ,
L_130 ,
V_34 ) ;
V_34 = - V_40 ;
}
F_45 ( V_168 , V_168 -> V_177 ) ;
F_46 ( V_589 ) ;
return V_34 ;
}
static int F_219 ( struct V_30 * V_31 )
{
struct V_588 * V_595 ;
struct V_596 * V_597 ;
struct V_598 * V_495 ;
int V_42 = 0 ;
int V_34 , V_199 ;
V_595 = F_41 ( sizeof( * V_595 ) , V_599 ) ;
if ( ! V_595 ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_131 ) ;
return - V_197 ;
}
V_34 = F_216 ( V_31 , V_595 ) ;
if ( V_34 ) {
F_46 ( V_595 ) ;
return V_34 ;
}
V_495 = (struct V_598 * )
V_595 -> V_600 ;
for ( V_199 = 0 ; V_199 < V_495 -> V_601 ; V_199 ++ ) {
V_597 = (struct V_596 * )
( V_495 -> V_597 + V_199 * V_495 -> V_602 ) ;
if ( V_597 -> V_603 & V_604 )
V_42 ++ ;
}
F_46 ( V_595 ) ;
return V_42 ;
}
static int F_220 ( struct V_30 * V_31 , struct V_605 * V_606 )
{
struct V_588 * V_595 ;
struct V_596 * V_597 ;
struct V_598 * V_495 ;
char V_607 [ 9 ] = L_57 ;
int V_34 , V_199 , V_365 ;
V_595 = F_41 ( sizeof( * V_595 ) , V_599 ) ;
if ( ! V_595 ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_131 ) ;
return - V_197 ;
}
V_34 = F_216 ( V_31 , V_595 ) ;
if ( V_34 ) {
F_46 ( V_595 ) ;
return V_34 ;
}
V_495 = (struct V_598 * )
V_595 -> V_600 ;
for ( V_199 = 0 ; V_199 < V_495 -> V_601 ; V_199 ++ ) {
V_597 = (struct V_596 * )
( V_495 -> V_597 + V_199 * V_495 -> V_602 ) ;
F_221 ( V_606 , L_132 ) ;
for ( V_365 = 0 ; V_365 < 11 ; V_365 ++ )
F_222 ( V_606 , L_10 , V_597 -> V_608 [ V_365 ] ) ;
F_223 ( V_606 , '\n' ) ;
F_222 ( V_606 , L_133 , V_597 -> V_603 ) ;
memcpy ( & V_607 , & V_597 -> V_609 , sizeof( V_607 ) - 1 ) ;
F_24 ( V_607 , sizeof( V_607 ) ) ;
F_222 ( V_606 , L_134 , V_607 ) ;
F_222 ( V_606 , L_135 , V_597 -> V_610 ) ;
F_222 ( V_606 , L_136 , ( unsigned long )
V_597 -> V_611 ) ;
}
F_46 ( V_595 ) ;
return 0 ;
}
static int
F_224 ( struct V_30 * V_31 , int V_612 ,
T_1 V_613 , T_2 V_586 )
{
struct V_614 * V_615 ;
int V_213 = F_54 ( V_586 ) ;
struct V_167 * V_168 ;
struct V_26 * V_27 ;
int V_34 ;
V_168 = F_42 ( V_176 , 1 ,
sizeof( struct V_614 ) ,
V_31 ) ;
if ( F_43 ( V_168 ) ) {
F_17 ( V_7 , V_31 , L_1 ,
L_137 ) ;
return F_86 ( V_168 ) ;
}
V_615 = (struct V_614 * ) V_168 -> V_29 ;
V_615 -> V_258 = V_616 ;
V_615 -> V_617 = V_612 ;
V_615 -> V_210 = V_31 -> V_208 [ V_213 ] . V_210 ;
V_615 -> V_613 = V_613 ;
V_615 -> V_209 = V_31 -> V_208 [ V_213 ] . V_209 ;
V_615 -> V_154 = V_31 -> V_208 [ V_213 ] . V_154 ;
V_27 = V_168 -> V_171 ;
V_27 -> V_54 = V_261 ;
V_27 -> V_56 = ( T_1 ) ( V_173 ) V_615 ;
V_27 -> V_43 = V_44 ;
V_27 -> V_42 = sizeof( struct V_614 ) ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_178 = NULL ;
V_168 -> V_181 = 256 ;
V_168 -> V_179 = 10 * V_180 ;
V_168 -> V_182 = F_32 () ;
V_168 -> V_183 = V_184 ;
F_33 ( V_185 , & V_168 -> V_43 ) ;
V_34 = F_44 ( V_168 ) ;
F_45 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static struct V_618 * F_225 ( struct V_30 * V_31 ,
T_2 V_586 ,
struct V_619 * V_620 )
{
struct V_618 * V_201 ;
int V_208 , V_213 ;
if ( V_620 -> V_621 == 0 )
goto V_379;
for ( V_208 = 0x80 , V_213 = 0 ; V_208 ; V_208 >>= 1 , V_213 ++ ) {
V_201 = V_31 -> V_208 [ V_213 ] . V_201 ;
if ( V_201 -> V_155 . V_621 ==
V_620 -> V_621 )
return V_201 ;
}
V_379:
return V_31 -> V_208 [ F_54 ( V_586 ) ] . V_201 ;
}
static int F_226 ( struct V_30 * V_31 , T_2 V_586 ,
struct V_619 * V_620 )
{
struct V_618 * V_622 ;
unsigned long V_623 = 0 , V_65 = 0 ;
struct V_618 * V_201 ;
unsigned int V_213 , V_208 ;
char * V_624 , * V_155 ;
char * V_625 , * V_129 ;
int V_626 = 0 ;
if ( ! V_620 -> V_627 ||
! ( V_620 -> V_628 [ 0 ] | V_620 -> V_628 [ 1 ] | V_620 -> V_628 [ 2 ] ) )
return V_586 ;
V_622 = F_225 ( V_31 , V_586 , V_620 ) ;
V_213 = 8 - F_227 ( V_620 -> V_627 ) ;
V_625 = ( char * ) & V_622 -> V_629 [ V_213 ] ;
V_624 = ( char * ) & V_622 -> V_155 ;
V_65 = V_620 -> V_628 [ 2 ] ;
V_65 |= V_620 -> V_628 [ 1 ] << 8 ;
V_65 |= V_620 -> V_628 [ 0 ] << 16 ;
for ( V_208 = 0 ; V_208 < 8 ; V_208 ++ ) {
V_623 = V_65 ;
V_201 = V_31 -> V_208 [ V_208 ] . V_201 ;
V_213 = 8 - F_227 ( V_620 -> V_627 ) ;
V_129 = ( char * ) & V_201 -> V_629 [ V_213 ] ;
if ( memcmp ( V_625 , V_129 , sizeof( * V_129 ) ) != 0 )
continue;
V_155 = ( char * ) & V_201 -> V_155 ;
while ( V_623 ) {
V_213 = F_227 ( V_623 ) - 1 ;
if ( memcmp ( & V_624 [ 31 - V_213 ] , & V_155 [ 31 - V_213 ] , 1 )
!= 0 )
break;
F_38 ( V_213 , & V_623 ) ;
}
if ( V_623 )
continue;
V_626 |= 0x80 >> V_208 ;
}
return V_626 ;
}
static void F_228 ( struct V_30 * V_31 ,
unsigned long V_630 , int V_631 )
{
int V_213 ;
while ( V_630 ) {
V_213 = 8 - F_227 ( V_630 ) ;
if ( V_631 == V_632 )
F_229 ( L_138 ,
V_31 -> V_208 [ V_213 ] . V_209 ,
V_31 -> V_208 [ V_213 ] . V_210 ) ;
else if ( V_631 == V_633 )
F_230 ( L_139 ,
V_31 -> V_208 [ V_213 ] . V_209 ,
V_31 -> V_208 [ V_213 ] . V_210 ) ;
F_38 ( 7 - V_213 , & V_630 ) ;
}
}
static int F_231 ( struct V_30 * V_31 , T_2 V_586 ,
struct V_619 * V_620 )
{
unsigned long V_626 ;
V_626 = F_226 ( V_31 , V_586 , V_620 ) ;
if ( ! ( F_59 ( V_31 ) & V_626 ) )
return 0 ;
if ( ! ( F_59 ( V_31 ) & ~ V_626 ) ) {
return - V_127 ;
}
F_232 ( V_31 , V_626 ) ;
F_233 ( V_31 , V_626 ) ;
return V_626 ;
}
static int F_234 ( struct V_30 * V_31 , T_2 V_586 ,
struct V_619 * V_620 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_634 * V_635 , * V_636 ;
struct V_30 * V_87 , * V_370 ;
unsigned long V_630 = 0 ;
unsigned long V_43 ;
int V_626 ;
F_139 (dev, n, &private->lcu->active_devices,
alias_list) {
F_26 ( F_27 ( V_87 -> V_2 ) , V_43 ) ;
V_626 = F_231 ( V_87 , V_586 , V_620 ) ;
F_28 ( F_27 ( V_87 -> V_2 ) , V_43 ) ;
if ( V_626 < 0 )
goto V_353;
V_630 |= V_626 ;
}
F_139 (dev, n, &private->lcu->inactive_devices,
alias_list) {
F_26 ( F_27 ( V_87 -> V_2 ) , V_43 ) ;
V_626 = F_231 ( V_87 , V_586 , V_620 ) ;
F_28 ( F_27 ( V_87 -> V_2 ) , V_43 ) ;
if ( V_626 < 0 )
goto V_353;
V_630 |= V_626 ;
}
F_139 (pavgroup, tempgroup,
&private->lcu->grouplist, group) {
F_139 (dev, n, &pavgroup->baselist,
alias_list) {
F_26 ( F_27 ( V_87 -> V_2 ) , V_43 ) ;
V_626 = F_231 ( V_87 , V_586 , V_620 ) ;
F_28 (
F_27 ( V_87 -> V_2 ) , V_43 ) ;
if ( V_626 < 0 )
goto V_353;
V_630 |= V_626 ;
}
F_139 (dev, n, &pavgroup->aliaslist,
alias_list) {
F_26 ( F_27 ( V_87 -> V_2 ) , V_43 ) ;
V_626 = F_231 ( V_87 , V_586 , V_620 ) ;
F_28 (
F_27 ( V_87 -> V_2 ) , V_43 ) ;
if ( V_626 < 0 )
goto V_353;
V_630 |= V_626 ;
}
}
F_228 ( V_31 , V_630 , V_632 ) ;
return 0 ;
V_353:
return V_626 ;
}
static int F_235 ( struct V_30 * V_31 , T_2 V_586 ,
struct V_619 * V_620 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_634 * V_635 , * V_636 ;
struct V_30 * V_87 , * V_370 ;
unsigned long V_630 = 0 ;
int V_626 ;
F_139 (dev, n,
&private->lcu->active_devices,
alias_list) {
V_626 = F_226 ( V_87 , V_586 , V_620 ) ;
V_630 |= V_626 ;
if ( ! ( F_59 ( V_87 ) & V_626 ) ) {
F_72 ( V_87 , V_626 ) ;
F_84 ( V_87 ) ;
}
}
F_139 (dev, n,
&private->lcu->inactive_devices,
alias_list) {
V_626 = F_226 ( V_87 , V_586 , V_620 ) ;
V_630 |= V_626 ;
if ( ! ( F_59 ( V_87 ) & V_626 ) ) {
F_72 ( V_87 , V_626 ) ;
F_84 ( V_87 ) ;
}
}
F_139 (pavgroup, tempgroup,
&private->lcu->grouplist,
group) {
F_139 (dev, n,
&pavgroup->baselist,
alias_list) {
V_626 = F_226 ( V_87 , V_586 , V_620 ) ;
V_630 |= V_626 ;
if ( ! ( F_59 ( V_87 ) & V_626 ) ) {
F_72 ( V_87 , V_626 ) ;
F_84 ( V_87 ) ;
}
}
F_139 (dev, n,
&pavgroup->aliaslist,
alias_list) {
V_626 = F_226 ( V_87 , V_586 , V_620 ) ;
V_630 |= V_626 ;
if ( ! ( F_59 ( V_87 ) & V_626 ) ) {
F_72 ( V_87 , V_626 ) ;
F_84 ( V_87 ) ;
}
}
}
F_228 ( V_31 , V_630 , V_633 ) ;
return 0 ;
}
static void F_236 ( struct V_30 * V_31 , void * V_585 ,
T_2 V_586 )
{
struct V_619 * V_620 = V_585 ;
int V_612 ;
F_17 ( V_7 , V_31 ,
L_140 ,
( ( T_10 * ) V_620 ) [ 0 ] , ( ( T_10 * ) V_620 ) [ 1 ] , ( ( T_10 * ) V_620 ) [ 2 ] ,
( ( T_4 * ) V_620 ) [ 3 ] ) ;
if ( V_620 -> V_637 == V_632 ) {
if ( F_234 ( V_31 , V_586 , V_620 ) )
V_612 = V_638 ;
else
V_612 = V_639 ;
} else if ( V_620 -> V_637 == V_633 ) {
F_235 ( V_31 , V_586 , V_620 ) ;
V_612 = V_639 ;
} else
V_612 = V_640 ;
F_224 ( V_31 , V_612 ,
V_620 -> V_613 , V_586 ) ;
F_17 ( V_7 , V_31 ,
L_141 , V_612 ,
V_620 -> V_613 ) ;
V_31 -> V_641 -> V_642 ( V_31 , V_586 ) ;
}
static void F_237 ( struct V_236 * V_237 )
{
struct V_643 * V_29 ;
struct V_584 * V_585 ;
struct V_30 * V_31 ;
int V_34 ;
V_29 = F_68 ( V_237 , struct V_643 , V_245 ) ;
V_31 = V_29 -> V_31 ;
V_585 = F_41 ( sizeof( * V_585 ) , V_195 ) ;
if ( ! V_585 ) {
F_17 ( V_7 , V_31 , L_1 ,
L_142 ) ;
goto V_379;
}
V_34 = F_215 ( V_31 , V_585 , V_29 -> V_586 ) ;
if ( V_34 )
goto V_379;
if ( V_585 -> V_108 == V_644 &&
V_585 -> V_120 == V_645 )
F_236 ( V_31 , V_585 , V_29 -> V_586 ) ;
V_379:
F_74 ( V_31 ) ;
F_46 ( V_585 ) ;
F_46 ( V_29 ) ;
}
static int F_238 ( struct V_30 * V_31 , T_2 V_586 )
{
struct V_643 * V_29 ;
V_29 = F_41 ( sizeof( * V_29 ) , V_252 ) ;
if ( ! V_29 )
return - V_197 ;
F_79 ( & V_29 -> V_245 , F_237 ) ;
F_80 ( V_31 ) ;
V_29 -> V_31 = V_31 ;
V_29 -> V_586 = V_586 ;
F_70 ( & V_29 -> V_245 ) ;
return 0 ;
}
static int F_239 ( struct V_30 * V_31 , T_2 V_586 )
{
if ( ~ V_586 & F_59 ( V_31 ) ) {
F_73 ( V_31 , V_586 ) ;
F_232 ( V_31 , V_586 ) ;
F_15 ( & V_31 -> V_2 -> V_87 ,
L_143 ,
V_586 ) ;
return 1 ;
}
return 0 ;
}
static void F_240 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
F_15 ( & V_31 -> V_2 -> V_87 ,
L_144 ) ;
V_33 -> V_234 = 0 ;
}
static int F_241 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
return V_33 -> V_234 ? 1 : 0 ;
}
static void F_242 ( struct V_30 * V_31 ,
struct V_322 * V_322 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
if ( ! V_33 -> V_234 ) {
F_17 ( V_7 , V_31 , L_1 ,
L_145 ) ;
return;
}
if ( V_322 -> V_402 . V_566 . V_569 == V_646 ) {
F_240 ( V_31 ) ;
} else if ( V_322 -> V_402 . V_566 . V_569 == V_647 ) {
if ( F_239 ( V_31 , V_322 -> V_556 . V_648 . V_586 ) )
return;
F_240 ( V_31 ) ;
F_82 ( V_31 ,
F_243 ( V_31 ) ) ;
}
F_244 ( V_31 , V_649 ) ;
F_245 ( V_31 ) ;
}
static int T_11
F_246 ( void )
{
int V_3 ;
F_247 ( V_8 . V_650 , 4 ) ;
V_507 = F_77 ( sizeof( * V_507 ) ,
V_195 | V_196 ) ;
if ( ! V_507 )
return - V_197 ;
V_253 = F_77 ( sizeof( * V_253 ) ,
V_195 | V_196 ) ;
if ( ! V_253 ) {
F_46 ( V_507 ) ;
return - V_197 ;
}
V_485 = ( void * ) F_248 ( V_195 ) ;
if ( ! V_485 ) {
F_46 ( V_253 ) ;
F_46 ( V_507 ) ;
return - V_197 ;
}
V_3 = F_249 ( & V_651 ) ;
if ( ! V_3 )
F_250 () ;
else {
F_46 ( V_253 ) ;
F_46 ( V_507 ) ;
F_206 ( ( unsigned long ) V_485 ) ;
}
return V_3 ;
}
static void T_12
F_251 ( void )
{
F_252 ( & V_651 ) ;
F_46 ( V_253 ) ;
F_46 ( V_507 ) ;
F_206 ( ( unsigned long ) V_485 ) ;
}
