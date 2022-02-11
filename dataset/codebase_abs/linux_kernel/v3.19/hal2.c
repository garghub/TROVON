static inline T_1 F_1 ( T_1 * V_1 )
{
return F_2 ( V_1 ) ;
}
static inline void F_3 ( T_1 V_2 , T_1 * V_1 )
{
F_4 ( V_2 , V_1 ) ;
}
static T_1 F_5 ( struct V_3 * V_4 , T_2 V_5 )
{
T_1 V_6 ;
struct V_7 * V_8 = V_4 -> V_9 ;
F_3 ( F_6 ( V_5 ) , & V_8 -> V_10 ) ;
F_7 ( V_8 ) ;
V_6 = F_1 ( & V_8 -> V_11 ) & 0xffff ;
F_3 ( F_6 ( V_5 ) | 0x1 , & V_8 -> V_10 ) ;
F_7 ( V_8 ) ;
V_6 |= ( F_1 ( & V_8 -> V_11 ) & 0xffff ) << 16 ;
return V_6 ;
}
static void F_8 ( struct V_3 * V_4 , T_2 V_5 , T_2 V_2 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
F_3 ( V_2 , & V_8 -> V_11 ) ;
F_3 ( 0 , & V_8 -> V_12 ) ;
F_3 ( 0 , & V_8 -> V_13 ) ;
F_3 ( 0 , & V_8 -> V_14 ) ;
F_3 ( F_9 ( V_5 ) , & V_8 -> V_10 ) ;
F_7 ( V_8 ) ;
}
static void F_10 ( struct V_3 * V_4 , T_2 V_5 , T_1 V_2 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
F_3 ( V_2 & 0xffff , & V_8 -> V_11 ) ;
F_3 ( V_2 >> 16 , & V_8 -> V_12 ) ;
F_3 ( 0 , & V_8 -> V_13 ) ;
F_3 ( 0 , & V_8 -> V_14 ) ;
F_3 ( F_9 ( V_5 ) , & V_8 -> V_10 ) ;
F_7 ( V_8 ) ;
}
static void F_11 ( struct V_3 * V_4 , T_2 V_5 , T_2 V_15 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
F_3 ( F_6 ( V_5 ) , & V_8 -> V_10 ) ;
F_7 ( V_8 ) ;
F_3 ( ( F_1 ( & V_8 -> V_11 ) & 0xffff ) | V_15 , & V_8 -> V_11 ) ;
F_3 ( 0 , & V_8 -> V_12 ) ;
F_3 ( 0 , & V_8 -> V_13 ) ;
F_3 ( 0 , & V_8 -> V_14 ) ;
F_3 ( F_9 ( V_5 ) , & V_8 -> V_10 ) ;
F_7 ( V_8 ) ;
}
static void F_12 ( struct V_3 * V_4 , T_2 V_5 , T_2 V_15 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
F_3 ( F_6 ( V_5 ) , & V_8 -> V_10 ) ;
F_7 ( V_8 ) ;
F_3 ( ( F_1 ( & V_8 -> V_11 ) & 0xffff ) & ~ V_15 , & V_8 -> V_11 ) ;
F_3 ( 0 , & V_8 -> V_12 ) ;
F_3 ( 0 , & V_8 -> V_13 ) ;
F_3 ( 0 , & V_8 -> V_14 ) ;
F_3 ( F_9 ( V_5 ) , & V_8 -> V_10 ) ;
F_7 ( V_8 ) ;
}
static int F_13 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
V_19 -> type = V_20 ;
V_19 -> V_21 = 2 ;
V_19 -> V_22 . integer . V_23 = 0 ;
switch ( ( int ) V_17 -> V_24 ) {
case V_25 :
V_19 -> V_22 . integer . V_26 = 31 ;
break;
case V_27 :
V_19 -> V_22 . integer . V_26 = 15 ;
break;
}
return 0 ;
}
static int F_14 ( struct V_16 * V_17 ,
struct V_28 * V_29 )
{
struct V_3 * V_4 = F_15 ( V_17 ) ;
T_1 V_30 ;
int V_31 , V_32 ;
switch ( ( int ) V_17 -> V_24 ) {
case V_25 :
V_30 = F_5 ( V_4 , V_33 ) ;
if ( V_30 & V_34 ) {
V_31 = 0 ;
V_32 = 0 ;
} else {
V_31 = 31 - ( ( V_30 >> V_35 ) & 31 ) ;
V_32 = 31 - ( ( V_30 >> V_36 ) & 31 ) ;
}
break;
case V_27 :
V_30 = F_5 ( V_4 , V_37 ) ;
V_31 = ( V_30 >> V_38 ) & 15 ;
V_32 = ( V_30 >> V_39 ) & 15 ;
break;
}
V_29 -> V_22 . integer . V_22 [ 0 ] = V_31 ;
V_29 -> V_22 . integer . V_22 [ 1 ] = V_32 ;
return 0 ;
}
static int F_16 ( struct V_16 * V_17 ,
struct V_28 * V_29 )
{
struct V_3 * V_4 = F_15 ( V_17 ) ;
T_1 V_40 , V_41 ;
int V_31 , V_32 ;
V_31 = V_29 -> V_22 . integer . V_22 [ 0 ] ;
V_32 = V_29 -> V_22 . integer . V_22 [ 1 ] ;
switch ( ( int ) V_17 -> V_24 ) {
case V_25 :
V_40 = F_5 ( V_4 , V_33 ) ;
V_41 = V_40 & ~ ( V_42 | V_43 | V_34 ) ;
if ( V_31 | V_32 ) {
V_31 = 31 - V_31 ;
V_32 = 31 - V_32 ;
V_41 |= ( V_31 << V_35 ) ;
V_41 |= ( V_32 << V_36 ) ;
} else
V_41 |= V_42 | V_43 | V_34 ;
F_10 ( V_4 , V_33 , V_41 ) ;
break;
case V_27 :
V_40 = F_5 ( V_4 , V_37 ) ;
V_41 = V_40 & ~ ( V_44 | V_45 ) ;
V_41 |= ( V_31 << V_38 ) ;
V_41 |= ( V_32 << V_39 ) ;
F_10 ( V_4 , V_37 , V_41 ) ;
break;
}
return V_40 != V_41 ;
}
static int F_17 ( struct V_3 * V_4 )
{
int V_46 ;
F_10 ( V_4 , V_33 ,
V_42 | V_43 | V_34 ) ;
F_10 ( V_4 , V_37 , 0 ) ;
V_46 = F_18 ( V_4 -> V_47 ,
F_19 ( & V_48 , V_4 ) ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_18 ( V_4 -> V_47 ,
F_19 ( & V_49 , V_4 ) ) ;
if ( V_46 < 0 )
return V_46 ;
return 0 ;
}
static T_3 F_20 ( int V_50 , void * V_51 )
{
struct V_3 * V_4 = V_51 ;
T_3 V_6 = V_52 ;
if ( V_4 -> V_53 . V_54 . V_54 -> V_55 & V_56 ) {
F_21 ( V_4 -> V_53 . V_57 ) ;
V_6 = V_58 ;
}
if ( V_4 -> V_59 . V_54 . V_54 -> V_55 & V_56 ) {
F_21 ( V_4 -> V_59 . V_57 ) ;
V_6 = V_58 ;
}
return V_6 ;
}
static int F_22 ( struct V_60 * V_61 , unsigned int V_62 )
{
unsigned short V_63 ;
if ( 44100 % V_62 < 48000 % V_62 ) {
V_63 = 4 * 44100 / V_62 ;
V_61 -> V_64 = 44100 ;
} else {
V_63 = 4 * 48000 / V_62 ;
V_61 -> V_64 = 48000 ;
}
V_61 -> V_65 = 4 ;
V_61 -> V_63 = V_63 ;
V_62 = 4 * V_61 -> V_64 / V_63 ;
return V_62 ;
}
static void F_23 ( struct V_3 * V_4 )
{
unsigned int V_64 = V_4 -> V_53 . V_64 ;
int V_65 = V_4 -> V_53 . V_65 ;
int V_63 = V_4 -> V_53 . V_63 ;
F_8 ( V_4 , V_66 , ( V_64 == 44100 ) ? 1 : 0 ) ;
F_10 ( V_4 , V_67 ,
( ( 0xffff & ( V_65 - V_63 - 1 ) ) << 16 ) | V_65 ) ;
}
static void F_24 ( struct V_3 * V_4 )
{
unsigned int V_64 = V_4 -> V_59 . V_64 ;
int V_65 = V_4 -> V_59 . V_65 ;
int V_63 = V_4 -> V_59 . V_63 ;
F_8 ( V_4 , V_68 , ( V_64 == 44100 ) ? 1 : 0 ) ;
F_10 ( V_4 , V_69 ,
( ( 0xffff & ( V_65 - V_63 - 1 ) ) << 16 ) | V_65 ) ;
}
static void F_25 ( struct V_3 * V_4 )
{
unsigned int V_70 , V_71 , V_72 , V_73 ;
struct V_74 * V_54 = & V_4 -> V_53 . V_54 ;
V_73 = 2 * V_4 -> V_53 . V_75 ;
V_72 = ( V_73 * 2 ) >> 1 ;
V_70 = 0 ;
V_71 = ( V_73 * 4 ) >> 3 ;
V_54 -> V_76 = V_77 | V_78 |
( V_72 << 8 ) | ( V_70 << 16 ) | ( V_71 << 24 ) ;
V_54 -> V_54 -> V_55 = V_78 ;
F_12 ( V_4 , V_79 , V_80 ) ;
F_23 ( V_4 ) ;
F_12 ( V_4 , V_81 , V_82 ) ;
F_11 ( V_4 , V_83 , ( 1 << V_54 -> V_84 ) ) ;
F_8 ( V_4 , V_85 , ( V_54 -> V_84 << V_86 )
| ( 1 << V_87 )
| ( V_4 -> V_53 . V_75 << V_88 ) ) ;
}
static void F_26 ( struct V_3 * V_4 )
{
unsigned int V_70 , V_71 , V_72 , V_73 ;
struct V_74 * V_54 = & V_4 -> V_59 . V_54 ;
V_73 = 2 * V_4 -> V_59 . V_75 ;
V_72 = ( V_73 * 2 ) >> 1 ;
V_70 = ( 4 * 4 ) >> 3 ;
V_71 = ( 4 * 4 + V_73 * 4 ) >> 3 ;
V_54 -> V_76 = V_77 | V_89 | V_78 |
( V_72 << 8 ) | ( V_70 << 16 ) | ( V_71 << 24 ) ;
V_54 -> V_54 -> V_55 = V_78 ;
F_12 ( V_4 , V_79 , V_90 ) ;
F_24 ( V_4 ) ;
F_12 ( V_4 , V_81 , V_91 ) ;
F_11 ( V_4 , V_83 , ( 1 << V_54 -> V_84 ) ) ;
F_8 ( V_4 , V_92 , ( V_54 -> V_84 << V_86 )
| ( 2 << V_87 )
| ( V_4 -> V_59 . V_75 << V_88 ) ) ;
}
static void F_27 ( struct V_3 * V_4 )
{
struct V_74 * V_54 = & V_4 -> V_53 . V_54 ;
V_54 -> V_54 -> V_93 = V_4 -> V_53 . V_94 ;
V_54 -> V_54 -> V_55 = V_54 -> V_76 | V_95 ;
F_11 ( V_4 , V_79 , V_80 ) ;
}
static void F_28 ( struct V_3 * V_4 )
{
struct V_74 * V_54 = & V_4 -> V_59 . V_54 ;
V_54 -> V_54 -> V_93 = V_4 -> V_59 . V_94 ;
V_54 -> V_54 -> V_55 = V_54 -> V_76 | V_95 ;
F_11 ( V_4 , V_79 , V_90 ) ;
}
static inline void F_29 ( struct V_3 * V_4 )
{
V_4 -> V_53 . V_54 . V_54 -> V_55 = V_78 ;
}
static inline void F_30 ( struct V_3 * V_4 )
{
V_4 -> V_59 . V_54 . V_54 -> V_55 = V_78 ;
}
static int F_31 ( struct V_60 * V_61 )
{
struct V_96 * V_97 ;
T_4 V_94 , V_98 ;
int V_21 = V_99 / V_100 ;
int V_101 ;
V_61 -> V_102 = F_32 ( NULL , V_99 ,
& V_98 , V_103 ) ;
if ( ! V_61 -> V_102 )
return - V_104 ;
V_97 = F_32 ( NULL , V_21 * sizeof( struct V_96 ) ,
& V_94 , V_103 ) ;
if ( ! V_97 ) {
F_33 ( NULL , V_99 ,
V_61 -> V_102 , V_98 ) ;
return - V_104 ;
}
V_61 -> V_98 = V_98 ;
V_61 -> V_94 = V_94 ;
V_61 -> V_97 = V_97 ;
for ( V_101 = 0 ; V_101 < V_21 ; V_101 ++ ) {
V_97 -> V_97 . V_105 = V_98 + V_101 * V_100 ;
V_97 -> V_97 . V_106 = V_107 | V_100 ;
V_97 -> V_97 . V_108 = ( V_101 == V_21 - 1 ) ?
V_94 : V_94 + ( V_101 + 1 ) * sizeof( struct V_96 ) ;
V_97 ++ ;
}
F_34 ( NULL , V_61 -> V_97 , V_21 * sizeof( struct V_96 ) ,
V_109 ) ;
V_61 -> V_110 = V_21 ;
return 0 ;
}
static void F_35 ( struct V_60 * V_61 )
{
F_33 ( NULL , V_61 -> V_110 * sizeof( struct V_96 ) ,
V_61 -> V_97 , V_61 -> V_94 ) ;
F_33 ( NULL , V_99 , V_61 -> V_102 ,
V_61 -> V_98 ) ;
}
static int F_36 ( struct V_111 * V_57 ,
struct V_112 * V_113 )
{
int V_46 ;
V_46 = F_37 ( V_57 , F_38 ( V_113 ) ) ;
if ( V_46 < 0 )
return V_46 ;
return 0 ;
}
static int F_39 ( struct V_111 * V_57 )
{
return F_40 ( V_57 ) ;
}
static int F_41 ( struct V_111 * V_57 )
{
struct V_114 * V_115 = V_57 -> V_115 ;
struct V_3 * V_4 = F_42 ( V_57 ) ;
int V_46 ;
V_115 -> V_116 = V_117 ;
V_46 = F_31 ( & V_4 -> V_53 ) ;
if ( V_46 )
return V_46 ;
return 0 ;
}
static int F_43 ( struct V_111 * V_57 )
{
struct V_3 * V_4 = F_42 ( V_57 ) ;
F_35 ( & V_4 -> V_53 ) ;
return 0 ;
}
static int F_44 ( struct V_111 * V_57 )
{
struct V_3 * V_4 = F_42 ( V_57 ) ;
struct V_114 * V_115 = V_57 -> V_115 ;
struct V_60 * V_53 = & V_4 -> V_53 ;
V_53 -> V_75 = V_115 -> V_118 ;
V_53 -> V_119 = F_22 ( V_53 , V_115 -> V_62 ) ;
memset ( & V_53 -> V_120 , 0 , sizeof( V_53 -> V_120 ) ) ;
V_53 -> V_120 . V_121 = V_99 ;
V_53 -> V_120 . V_122 = F_45 ( V_57 ) ;
V_53 -> V_57 = V_57 ;
F_25 ( V_4 ) ;
return 0 ;
}
static int F_46 ( struct V_111 * V_57 , int V_123 )
{
struct V_3 * V_4 = F_42 ( V_57 ) ;
switch ( V_123 ) {
case V_124 :
V_4 -> V_53 . V_120 . V_125 = V_4 -> V_53 . V_98 ;
V_4 -> V_53 . V_120 . V_126 = 0 ;
V_57 -> V_127 -> V_128 ( V_57 ) ;
F_27 ( V_4 ) ;
break;
case V_129 :
F_29 ( V_4 ) ;
break;
default:
return - V_130 ;
}
return 0 ;
}
static T_5
F_47 ( struct V_111 * V_57 )
{
struct V_3 * V_4 = F_42 ( V_57 ) ;
struct V_60 * V_53 = & V_4 -> V_53 ;
return F_48 ( V_57 , & V_53 -> V_120 ,
V_53 -> V_54 . V_54 -> V_131 ) ;
}
static void F_49 ( struct V_111 * V_57 ,
struct V_132 * V_133 , T_6 V_134 )
{
struct V_3 * V_4 = F_42 ( V_57 ) ;
unsigned char * V_135 = V_4 -> V_53 . V_102 + V_133 -> V_126 ;
memcpy ( V_135 , V_57 -> V_115 -> V_136 + V_133 -> V_137 , V_134 ) ;
F_34 ( NULL , V_135 , V_134 , V_109 ) ;
}
static int F_50 ( struct V_111 * V_57 )
{
struct V_3 * V_4 = F_42 ( V_57 ) ;
struct V_60 * V_53 = & V_4 -> V_53 ;
V_53 -> V_120 . V_138 = V_99 / 2 ;
F_51 ( V_57 ,
& V_53 -> V_120 ,
F_49 ) ;
return 0 ;
}
static int F_52 ( struct V_111 * V_57 )
{
struct V_114 * V_115 = V_57 -> V_115 ;
struct V_3 * V_4 = F_42 ( V_57 ) ;
struct V_60 * V_59 = & V_4 -> V_59 ;
int V_46 ;
V_115 -> V_116 = V_117 ;
V_46 = F_31 ( V_59 ) ;
if ( V_46 )
return V_46 ;
return 0 ;
}
static int F_53 ( struct V_111 * V_57 )
{
struct V_3 * V_4 = F_42 ( V_57 ) ;
F_35 ( & V_4 -> V_59 ) ;
return 0 ;
}
static int F_54 ( struct V_111 * V_57 )
{
struct V_3 * V_4 = F_42 ( V_57 ) ;
struct V_114 * V_115 = V_57 -> V_115 ;
struct V_60 * V_59 = & V_4 -> V_59 ;
V_59 -> V_75 = V_115 -> V_118 ;
V_59 -> V_119 = F_22 ( V_59 , V_115 -> V_62 ) ;
memset ( & V_59 -> V_120 , 0 , sizeof( V_59 -> V_120 ) ) ;
V_59 -> V_120 . V_121 = V_99 ;
V_59 -> V_120 . V_138 = V_99 / 2 ;
V_59 -> V_120 . V_122 = F_45 ( V_57 ) ;
V_59 -> V_57 = V_57 ;
F_26 ( V_4 ) ;
return 0 ;
}
static int F_55 ( struct V_111 * V_57 , int V_123 )
{
struct V_3 * V_4 = F_42 ( V_57 ) ;
switch ( V_123 ) {
case V_124 :
V_4 -> V_59 . V_120 . V_125 = V_4 -> V_59 . V_98 ;
V_4 -> V_59 . V_120 . V_126 = 0 ;
F_56 ( V_139 L_1 , V_4 -> V_59 . V_98 ) ;
F_28 ( V_4 ) ;
break;
case V_129 :
F_30 ( V_4 ) ;
break;
default:
return - V_130 ;
}
return 0 ;
}
static T_5
F_57 ( struct V_111 * V_57 )
{
struct V_3 * V_4 = F_42 ( V_57 ) ;
struct V_60 * V_59 = & V_4 -> V_59 ;
return F_58 ( V_57 , & V_59 -> V_120 ,
V_59 -> V_54 . V_54 -> V_131 ) ;
}
static void F_59 ( struct V_111 * V_57 ,
struct V_132 * V_133 , T_6 V_134 )
{
struct V_3 * V_4 = F_42 ( V_57 ) ;
unsigned char * V_135 = V_4 -> V_59 . V_102 + V_133 -> V_126 ;
F_34 ( NULL , V_135 , V_134 , V_140 ) ;
memcpy ( V_57 -> V_115 -> V_136 + V_133 -> V_137 , V_135 , V_134 ) ;
}
static int F_60 ( struct V_111 * V_57 )
{
struct V_3 * V_4 = F_42 ( V_57 ) ;
struct V_60 * V_59 = & V_4 -> V_59 ;
F_61 ( V_57 ,
& V_59 -> V_120 ,
F_59 ) ;
return 0 ;
}
static int F_62 ( struct V_3 * V_4 )
{
struct V_141 * V_142 ;
int V_46 ;
V_46 = F_63 ( V_4 -> V_47 , L_2 , 0 , 1 , 1 , & V_142 ) ;
if ( V_46 < 0 )
return V_46 ;
V_142 -> V_143 = V_4 ;
strcpy ( V_142 -> V_144 , L_3 ) ;
F_64 ( V_142 , V_145 ,
& V_146 ) ;
F_64 ( V_142 , V_147 ,
& V_148 ) ;
F_65 ( V_142 , V_149 ,
F_66 ( V_103 ) ,
0 , 1024 * 1024 ) ;
return 0 ;
}
static int F_67 ( struct V_150 * V_151 )
{
struct V_3 * V_4 = V_151 -> V_152 ;
F_68 ( V_153 , V_4 ) ;
F_69 ( V_4 ) ;
return 0 ;
}
static void F_70 ( struct V_60 * V_61 , struct V_154 * V_155 ,
int V_156 )
{
V_61 -> V_54 . V_84 = V_156 ;
V_61 -> V_54 . V_54 = & V_155 -> V_157 [ V_156 ] ;
}
static int F_71 ( struct V_3 * V_4 )
{
unsigned short V_158 , V_159 , V_160 ;
unsigned short V_161 ;
F_3 ( 0 , & V_4 -> V_9 -> V_162 ) ;
F_3 ( V_163 | V_164 ,
& V_4 -> V_9 -> V_162 ) ;
F_8 ( V_4 , V_165 , V_166 ) ;
V_161 = F_1 ( & V_4 -> V_9 -> V_161 ) ;
if ( V_161 & V_167 )
return - V_168 ;
V_158 = ( V_161 & V_169 ) >> 12 ;
V_159 = ( V_161 & V_170 ) >> 4 ;
V_160 = ( V_161 & V_171 ) ;
F_56 ( V_172 L_4 ,
V_158 , V_159 , V_160 ) ;
return 0 ;
}
static int F_72 ( struct V_173 * V_47 , struct V_3 * * V_174 )
{
struct V_3 * V_4 ;
struct V_154 * V_155 = V_175 ;
int V_46 ;
V_4 = F_73 ( sizeof( struct V_3 ) , V_103 ) ;
if ( ! V_4 )
return - V_104 ;
V_4 -> V_47 = V_47 ;
if ( F_74 ( V_153 , F_20 , V_176 ,
L_3 , V_4 ) ) {
F_56 ( V_177 L_5 , V_153 ) ;
F_69 ( V_4 ) ;
return - V_178 ;
}
V_4 -> V_9 = (struct V_7 * ) V_155 -> V_179 [ 0 ] ;
V_4 -> V_180 = (struct V_181 * ) V_155 -> V_179 [ 1 ] ;
V_4 -> V_182 = (struct V_183 * ) V_155 -> V_179 [ 2 ] ;
V_4 -> V_184 = (struct V_185 * ) V_155 -> V_179 [ 3 ] ;
if ( F_71 ( V_4 ) < 0 ) {
F_69 ( V_4 ) ;
return - V_168 ;
}
F_70 ( & V_4 -> V_53 , V_155 , 0 ) ;
F_70 ( & V_4 -> V_59 , V_155 , 1 ) ;
#define F_75 ((0 << HPC3_DMACFG_D3R_SHIFT) | \
(2 << HPC3_DMACFG_D4R_SHIFT) | \
(2 << HPC3_DMACFG_D5R_SHIFT) | \
(0 << HPC3_DMACFG_D3W_SHIFT) | \
(2 << HPC3_DMACFG_D4W_SHIFT) | \
(2 << HPC3_DMACFG_D5W_SHIFT) | \
HPC3_DMACFG_DS16 | \
HPC3_DMACFG_EVENHI | \
HPC3_DMACFG_RTIME | \
(8 << HPC3_DMACFG_BURST_SHIFT) | \
HPC3_DMACFG_DRQLIVE)
V_155 -> V_186 [ V_4 -> V_53 . V_54 . V_84 ] [ 0 ] = 0x8208844 ;
V_155 -> V_186 [ V_4 -> V_59 . V_54 . V_84 ] [ 0 ] = 0x8208844 ;
V_46 = F_76 ( V_47 , V_187 , V_4 , & V_188 ) ;
if ( V_46 < 0 ) {
F_68 ( V_153 , V_4 ) ;
F_69 ( V_4 ) ;
return V_46 ;
}
* V_174 = V_4 ;
return 0 ;
}
static int F_77 ( struct V_189 * V_190 )
{
struct V_173 * V_47 ;
struct V_3 * V_191 ;
int V_46 ;
V_46 = F_78 ( & V_190 -> V_192 , V_156 , V_193 , V_194 , 0 , & V_47 ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_72 ( V_47 , & V_191 ) ;
if ( V_46 < 0 ) {
F_79 ( V_47 ) ;
return V_46 ;
}
V_46 = F_62 ( V_191 ) ;
if ( V_46 < 0 ) {
F_79 ( V_47 ) ;
return V_46 ;
}
V_46 = F_17 ( V_191 ) ;
if ( V_46 < 0 ) {
F_79 ( V_47 ) ;
return V_46 ;
}
strcpy ( V_47 -> V_195 , L_2 ) ;
strcpy ( V_47 -> V_196 , L_2 ) ;
sprintf ( V_47 -> V_197 , L_6 ,
V_47 -> V_196 ,
V_153 ) ;
V_46 = F_80 ( V_47 ) ;
if ( V_46 < 0 ) {
F_79 ( V_47 ) ;
return V_46 ;
}
F_81 ( V_190 , V_47 ) ;
return 0 ;
}
static int F_82 ( struct V_189 * V_190 )
{
struct V_173 * V_47 = F_83 ( V_190 ) ;
F_79 ( V_47 ) ;
return 0 ;
}
