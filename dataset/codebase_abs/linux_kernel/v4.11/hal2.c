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
default:
return - V_40 ;
}
V_29 -> V_22 . integer . V_22 [ 0 ] = V_31 ;
V_29 -> V_22 . integer . V_22 [ 1 ] = V_32 ;
return 0 ;
}
static int F_16 ( struct V_16 * V_17 ,
struct V_28 * V_29 )
{
struct V_3 * V_4 = F_15 ( V_17 ) ;
T_1 V_41 , V_42 ;
int V_31 , V_32 ;
V_31 = V_29 -> V_22 . integer . V_22 [ 0 ] ;
V_32 = V_29 -> V_22 . integer . V_22 [ 1 ] ;
switch ( ( int ) V_17 -> V_24 ) {
case V_25 :
V_41 = F_5 ( V_4 , V_33 ) ;
V_42 = V_41 & ~ ( V_43 | V_44 | V_34 ) ;
if ( V_31 | V_32 ) {
V_31 = 31 - V_31 ;
V_32 = 31 - V_32 ;
V_42 |= ( V_31 << V_35 ) ;
V_42 |= ( V_32 << V_36 ) ;
} else
V_42 |= V_43 | V_44 | V_34 ;
F_10 ( V_4 , V_33 , V_42 ) ;
break;
case V_27 :
V_41 = F_5 ( V_4 , V_37 ) ;
V_42 = V_41 & ~ ( V_45 | V_46 ) ;
V_42 |= ( V_31 << V_38 ) ;
V_42 |= ( V_32 << V_39 ) ;
F_10 ( V_4 , V_37 , V_42 ) ;
break;
default:
return - V_40 ;
}
return V_41 != V_42 ;
}
static int F_17 ( struct V_3 * V_4 )
{
int V_47 ;
F_10 ( V_4 , V_33 ,
V_43 | V_44 | V_34 ) ;
F_10 ( V_4 , V_37 , 0 ) ;
V_47 = F_18 ( V_4 -> V_48 ,
F_19 ( & V_49 , V_4 ) ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_18 ( V_4 -> V_48 ,
F_19 ( & V_50 , V_4 ) ) ;
if ( V_47 < 0 )
return V_47 ;
return 0 ;
}
static T_3 F_20 ( int V_51 , void * V_52 )
{
struct V_3 * V_4 = V_52 ;
T_3 V_6 = V_53 ;
if ( V_4 -> V_54 . V_55 . V_55 -> V_56 & V_57 ) {
F_21 ( V_4 -> V_54 . V_58 ) ;
V_6 = V_59 ;
}
if ( V_4 -> V_60 . V_55 . V_55 -> V_56 & V_57 ) {
F_21 ( V_4 -> V_60 . V_58 ) ;
V_6 = V_59 ;
}
return V_6 ;
}
static int F_22 ( struct V_61 * V_62 , unsigned int V_63 )
{
unsigned short V_64 ;
if ( 44100 % V_63 < 48000 % V_63 ) {
V_64 = 4 * 44100 / V_63 ;
V_62 -> V_65 = 44100 ;
} else {
V_64 = 4 * 48000 / V_63 ;
V_62 -> V_65 = 48000 ;
}
V_62 -> V_66 = 4 ;
V_62 -> V_64 = V_64 ;
V_63 = 4 * V_62 -> V_65 / V_64 ;
return V_63 ;
}
static void F_23 ( struct V_3 * V_4 )
{
unsigned int V_65 = V_4 -> V_54 . V_65 ;
int V_66 = V_4 -> V_54 . V_66 ;
int V_64 = V_4 -> V_54 . V_64 ;
F_8 ( V_4 , V_67 , ( V_65 == 44100 ) ? 1 : 0 ) ;
F_10 ( V_4 , V_68 ,
( ( 0xffff & ( V_66 - V_64 - 1 ) ) << 16 ) | V_66 ) ;
}
static void F_24 ( struct V_3 * V_4 )
{
unsigned int V_65 = V_4 -> V_60 . V_65 ;
int V_66 = V_4 -> V_60 . V_66 ;
int V_64 = V_4 -> V_60 . V_64 ;
F_8 ( V_4 , V_69 , ( V_65 == 44100 ) ? 1 : 0 ) ;
F_10 ( V_4 , V_70 ,
( ( 0xffff & ( V_66 - V_64 - 1 ) ) << 16 ) | V_66 ) ;
}
static void F_25 ( struct V_3 * V_4 )
{
unsigned int V_71 , V_72 , V_73 , V_74 ;
struct V_75 * V_55 = & V_4 -> V_54 . V_55 ;
V_74 = 2 * V_4 -> V_54 . V_76 ;
V_73 = ( V_74 * 2 ) >> 1 ;
V_71 = 0 ;
V_72 = ( V_74 * 4 ) >> 3 ;
V_55 -> V_77 = V_78 | V_79 |
( V_73 << 8 ) | ( V_71 << 16 ) | ( V_72 << 24 ) ;
V_55 -> V_55 -> V_56 = V_79 ;
F_12 ( V_4 , V_80 , V_81 ) ;
F_23 ( V_4 ) ;
F_12 ( V_4 , V_82 , V_83 ) ;
F_11 ( V_4 , V_84 , ( 1 << V_55 -> V_85 ) ) ;
F_8 ( V_4 , V_86 , ( V_55 -> V_85 << V_87 )
| ( 1 << V_88 )
| ( V_4 -> V_54 . V_76 << V_89 ) ) ;
}
static void F_26 ( struct V_3 * V_4 )
{
unsigned int V_71 , V_72 , V_73 , V_74 ;
struct V_75 * V_55 = & V_4 -> V_60 . V_55 ;
V_74 = 2 * V_4 -> V_60 . V_76 ;
V_73 = ( V_74 * 2 ) >> 1 ;
V_71 = ( 4 * 4 ) >> 3 ;
V_72 = ( 4 * 4 + V_74 * 4 ) >> 3 ;
V_55 -> V_77 = V_78 | V_90 | V_79 |
( V_73 << 8 ) | ( V_71 << 16 ) | ( V_72 << 24 ) ;
V_55 -> V_55 -> V_56 = V_79 ;
F_12 ( V_4 , V_80 , V_91 ) ;
F_24 ( V_4 ) ;
F_12 ( V_4 , V_82 , V_92 ) ;
F_11 ( V_4 , V_84 , ( 1 << V_55 -> V_85 ) ) ;
F_8 ( V_4 , V_93 , ( V_55 -> V_85 << V_87 )
| ( 2 << V_88 )
| ( V_4 -> V_60 . V_76 << V_89 ) ) ;
}
static void F_27 ( struct V_3 * V_4 )
{
struct V_75 * V_55 = & V_4 -> V_54 . V_55 ;
V_55 -> V_55 -> V_94 = V_4 -> V_54 . V_95 ;
V_55 -> V_55 -> V_56 = V_55 -> V_77 | V_96 ;
F_11 ( V_4 , V_80 , V_81 ) ;
}
static void F_28 ( struct V_3 * V_4 )
{
struct V_75 * V_55 = & V_4 -> V_60 . V_55 ;
V_55 -> V_55 -> V_94 = V_4 -> V_60 . V_95 ;
V_55 -> V_55 -> V_56 = V_55 -> V_77 | V_96 ;
F_11 ( V_4 , V_80 , V_91 ) ;
}
static inline void F_29 ( struct V_3 * V_4 )
{
V_4 -> V_54 . V_55 . V_55 -> V_56 = V_79 ;
}
static inline void F_30 ( struct V_3 * V_4 )
{
V_4 -> V_60 . V_55 . V_55 -> V_56 = V_79 ;
}
static int F_31 ( struct V_61 * V_62 )
{
struct V_97 * V_98 ;
T_4 V_95 , V_99 ;
int V_21 = V_100 / V_101 ;
int V_102 ;
V_62 -> V_103 = F_32 ( NULL , V_100 ,
& V_99 , V_104 ) ;
if ( ! V_62 -> V_103 )
return - V_105 ;
V_98 = F_32 ( NULL , V_21 * sizeof( struct V_97 ) ,
& V_95 , V_104 ) ;
if ( ! V_98 ) {
F_33 ( NULL , V_100 ,
V_62 -> V_103 , V_99 ) ;
return - V_105 ;
}
V_62 -> V_99 = V_99 ;
V_62 -> V_95 = V_95 ;
V_62 -> V_98 = V_98 ;
for ( V_102 = 0 ; V_102 < V_21 ; V_102 ++ ) {
V_98 -> V_98 . V_106 = V_99 + V_102 * V_101 ;
V_98 -> V_98 . V_107 = V_108 | V_101 ;
V_98 -> V_98 . V_109 = ( V_102 == V_21 - 1 ) ?
V_95 : V_95 + ( V_102 + 1 ) * sizeof( struct V_97 ) ;
V_98 ++ ;
}
F_34 ( NULL , V_62 -> V_98 , V_21 * sizeof( struct V_97 ) ,
V_110 ) ;
V_62 -> V_111 = V_21 ;
return 0 ;
}
static void F_35 ( struct V_61 * V_62 )
{
F_33 ( NULL , V_62 -> V_111 * sizeof( struct V_97 ) ,
V_62 -> V_98 , V_62 -> V_95 ) ;
F_33 ( NULL , V_100 , V_62 -> V_103 ,
V_62 -> V_99 ) ;
}
static int F_36 ( struct V_112 * V_58 ,
struct V_113 * V_114 )
{
int V_47 ;
V_47 = F_37 ( V_58 , F_38 ( V_114 ) ) ;
if ( V_47 < 0 )
return V_47 ;
return 0 ;
}
static int F_39 ( struct V_112 * V_58 )
{
return F_40 ( V_58 ) ;
}
static int F_41 ( struct V_112 * V_58 )
{
struct V_115 * V_116 = V_58 -> V_116 ;
struct V_3 * V_4 = F_42 ( V_58 ) ;
int V_47 ;
V_116 -> V_117 = V_118 ;
V_47 = F_31 ( & V_4 -> V_54 ) ;
if ( V_47 )
return V_47 ;
return 0 ;
}
static int F_43 ( struct V_112 * V_58 )
{
struct V_3 * V_4 = F_42 ( V_58 ) ;
F_35 ( & V_4 -> V_54 ) ;
return 0 ;
}
static int F_44 ( struct V_112 * V_58 )
{
struct V_3 * V_4 = F_42 ( V_58 ) ;
struct V_115 * V_116 = V_58 -> V_116 ;
struct V_61 * V_54 = & V_4 -> V_54 ;
V_54 -> V_76 = V_116 -> V_119 ;
V_54 -> V_120 = F_22 ( V_54 , V_116 -> V_63 ) ;
memset ( & V_54 -> V_121 , 0 , sizeof( V_54 -> V_121 ) ) ;
V_54 -> V_121 . V_122 = V_100 ;
V_54 -> V_121 . V_123 = F_45 ( V_58 ) ;
V_54 -> V_58 = V_58 ;
F_25 ( V_4 ) ;
return 0 ;
}
static int F_46 ( struct V_112 * V_58 , int V_124 )
{
struct V_3 * V_4 = F_42 ( V_58 ) ;
switch ( V_124 ) {
case V_125 :
V_4 -> V_54 . V_121 . V_126 = V_4 -> V_54 . V_99 ;
V_4 -> V_54 . V_121 . V_127 = 0 ;
V_58 -> V_128 -> V_129 ( V_58 ) ;
F_27 ( V_4 ) ;
break;
case V_130 :
F_29 ( V_4 ) ;
break;
default:
return - V_40 ;
}
return 0 ;
}
static T_5
F_47 ( struct V_112 * V_58 )
{
struct V_3 * V_4 = F_42 ( V_58 ) ;
struct V_61 * V_54 = & V_4 -> V_54 ;
return F_48 ( V_58 , & V_54 -> V_121 ,
V_54 -> V_55 . V_55 -> V_131 ) ;
}
static void F_49 ( struct V_112 * V_58 ,
struct V_132 * V_133 , T_6 V_134 )
{
struct V_3 * V_4 = F_42 ( V_58 ) ;
unsigned char * V_135 = V_4 -> V_54 . V_103 + V_133 -> V_127 ;
memcpy ( V_135 , V_58 -> V_116 -> V_136 + V_133 -> V_137 , V_134 ) ;
F_34 ( NULL , V_135 , V_134 , V_110 ) ;
}
static int F_50 ( struct V_112 * V_58 )
{
struct V_3 * V_4 = F_42 ( V_58 ) ;
struct V_61 * V_54 = & V_4 -> V_54 ;
V_54 -> V_121 . V_138 = V_100 / 2 ;
F_51 ( V_58 ,
& V_54 -> V_121 ,
F_49 ) ;
return 0 ;
}
static int F_52 ( struct V_112 * V_58 )
{
struct V_115 * V_116 = V_58 -> V_116 ;
struct V_3 * V_4 = F_42 ( V_58 ) ;
struct V_61 * V_60 = & V_4 -> V_60 ;
int V_47 ;
V_116 -> V_117 = V_118 ;
V_47 = F_31 ( V_60 ) ;
if ( V_47 )
return V_47 ;
return 0 ;
}
static int F_53 ( struct V_112 * V_58 )
{
struct V_3 * V_4 = F_42 ( V_58 ) ;
F_35 ( & V_4 -> V_60 ) ;
return 0 ;
}
static int F_54 ( struct V_112 * V_58 )
{
struct V_3 * V_4 = F_42 ( V_58 ) ;
struct V_115 * V_116 = V_58 -> V_116 ;
struct V_61 * V_60 = & V_4 -> V_60 ;
V_60 -> V_76 = V_116 -> V_119 ;
V_60 -> V_120 = F_22 ( V_60 , V_116 -> V_63 ) ;
memset ( & V_60 -> V_121 , 0 , sizeof( V_60 -> V_121 ) ) ;
V_60 -> V_121 . V_122 = V_100 ;
V_60 -> V_121 . V_138 = V_100 / 2 ;
V_60 -> V_121 . V_123 = F_45 ( V_58 ) ;
V_60 -> V_58 = V_58 ;
F_26 ( V_4 ) ;
return 0 ;
}
static int F_55 ( struct V_112 * V_58 , int V_124 )
{
struct V_3 * V_4 = F_42 ( V_58 ) ;
switch ( V_124 ) {
case V_125 :
V_4 -> V_60 . V_121 . V_126 = V_4 -> V_60 . V_99 ;
V_4 -> V_60 . V_121 . V_127 = 0 ;
F_56 ( V_139 L_1 , V_4 -> V_60 . V_99 ) ;
F_28 ( V_4 ) ;
break;
case V_130 :
F_30 ( V_4 ) ;
break;
default:
return - V_40 ;
}
return 0 ;
}
static T_5
F_57 ( struct V_112 * V_58 )
{
struct V_3 * V_4 = F_42 ( V_58 ) ;
struct V_61 * V_60 = & V_4 -> V_60 ;
return F_58 ( V_58 , & V_60 -> V_121 ,
V_60 -> V_55 . V_55 -> V_131 ) ;
}
static void F_59 ( struct V_112 * V_58 ,
struct V_132 * V_133 , T_6 V_134 )
{
struct V_3 * V_4 = F_42 ( V_58 ) ;
unsigned char * V_135 = V_4 -> V_60 . V_103 + V_133 -> V_127 ;
F_34 ( NULL , V_135 , V_134 , V_140 ) ;
memcpy ( V_58 -> V_116 -> V_136 + V_133 -> V_137 , V_135 , V_134 ) ;
}
static int F_60 ( struct V_112 * V_58 )
{
struct V_3 * V_4 = F_42 ( V_58 ) ;
struct V_61 * V_60 = & V_4 -> V_60 ;
F_61 ( V_58 ,
& V_60 -> V_121 ,
F_59 ) ;
return 0 ;
}
static int F_62 ( struct V_3 * V_4 )
{
struct V_141 * V_142 ;
int V_47 ;
V_47 = F_63 ( V_4 -> V_48 , L_2 , 0 , 1 , 1 , & V_142 ) ;
if ( V_47 < 0 )
return V_47 ;
V_142 -> V_143 = V_4 ;
strcpy ( V_142 -> V_144 , L_3 ) ;
F_64 ( V_142 , V_145 ,
& V_146 ) ;
F_64 ( V_142 , V_147 ,
& V_148 ) ;
F_65 ( V_142 , V_149 ,
F_66 ( V_104 ) ,
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
static void F_70 ( struct V_61 * V_62 , struct V_154 * V_155 ,
int V_156 )
{
V_62 -> V_55 . V_85 = V_156 ;
V_62 -> V_55 . V_55 = & V_155 -> V_157 [ V_156 ] ;
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
static int F_72 ( struct V_173 * V_48 , struct V_3 * * V_174 )
{
struct V_3 * V_4 ;
struct V_154 * V_155 = V_175 ;
int V_47 ;
V_4 = F_73 ( sizeof( struct V_3 ) , V_104 ) ;
if ( ! V_4 )
return - V_105 ;
V_4 -> V_48 = V_48 ;
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
F_70 ( & V_4 -> V_54 , V_155 , 0 ) ;
F_70 ( & V_4 -> V_60 , V_155 , 1 ) ;
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
V_155 -> V_186 [ V_4 -> V_54 . V_55 . V_85 ] [ 0 ] = 0x8208844 ;
V_155 -> V_186 [ V_4 -> V_60 . V_55 . V_85 ] [ 0 ] = 0x8208844 ;
V_47 = F_76 ( V_48 , V_187 , V_4 , & V_188 ) ;
if ( V_47 < 0 ) {
F_68 ( V_153 , V_4 ) ;
F_69 ( V_4 ) ;
return V_47 ;
}
* V_174 = V_4 ;
return 0 ;
}
static int F_77 ( struct V_189 * V_190 )
{
struct V_173 * V_48 ;
struct V_3 * V_191 ;
int V_47 ;
V_47 = F_78 ( & V_190 -> V_192 , V_156 , V_193 , V_194 , 0 , & V_48 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_72 ( V_48 , & V_191 ) ;
if ( V_47 < 0 ) {
F_79 ( V_48 ) ;
return V_47 ;
}
V_47 = F_62 ( V_191 ) ;
if ( V_47 < 0 ) {
F_79 ( V_48 ) ;
return V_47 ;
}
V_47 = F_17 ( V_191 ) ;
if ( V_47 < 0 ) {
F_79 ( V_48 ) ;
return V_47 ;
}
strcpy ( V_48 -> V_195 , L_2 ) ;
strcpy ( V_48 -> V_196 , L_2 ) ;
sprintf ( V_48 -> V_197 , L_6 ,
V_48 -> V_196 ,
V_153 ) ;
V_47 = F_80 ( V_48 ) ;
if ( V_47 < 0 ) {
F_79 ( V_48 ) ;
return V_47 ;
}
F_81 ( V_190 , V_48 ) ;
return 0 ;
}
static int F_82 ( struct V_189 * V_190 )
{
struct V_173 * V_48 = F_83 ( V_190 ) ;
F_79 ( V_48 ) ;
return 0 ;
}
