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
V_62 -> V_103 = F_32 ( NULL , V_100 , & V_99 ,
V_104 , V_105 ) ;
if ( ! V_62 -> V_103 )
return - V_106 ;
V_98 = F_32 ( NULL , V_21 * sizeof( struct V_97 ) ,
& V_95 , V_104 , V_105 ) ;
if ( ! V_98 ) {
F_33 ( NULL , V_100 , V_62 -> V_103 , V_99 ,
V_105 ) ;
return - V_106 ;
}
V_62 -> V_99 = V_99 ;
V_62 -> V_95 = V_95 ;
V_62 -> V_98 = V_98 ;
for ( V_102 = 0 ; V_102 < V_21 ; V_102 ++ ) {
V_98 -> V_98 . V_107 = V_99 + V_102 * V_101 ;
V_98 -> V_98 . V_108 = V_109 | V_101 ;
V_98 -> V_98 . V_110 = ( V_102 == V_21 - 1 ) ?
V_95 : V_95 + ( V_102 + 1 ) * sizeof( struct V_97 ) ;
V_98 ++ ;
}
F_34 ( NULL , V_62 -> V_98 , V_21 * sizeof( struct V_97 ) ,
V_111 ) ;
V_62 -> V_112 = V_21 ;
return 0 ;
}
static void F_35 ( struct V_61 * V_62 )
{
F_33 ( NULL , V_62 -> V_112 * sizeof( struct V_97 ) ,
V_62 -> V_98 , V_62 -> V_95 , V_105 ) ;
F_33 ( NULL , V_100 , V_62 -> V_103 , V_62 -> V_99 ,
V_105 ) ;
}
static int F_36 ( struct V_113 * V_58 ,
struct V_114 * V_115 )
{
int V_47 ;
V_47 = F_37 ( V_58 , F_38 ( V_115 ) ) ;
if ( V_47 < 0 )
return V_47 ;
return 0 ;
}
static int F_39 ( struct V_113 * V_58 )
{
return F_40 ( V_58 ) ;
}
static int F_41 ( struct V_113 * V_58 )
{
struct V_116 * V_117 = V_58 -> V_117 ;
struct V_3 * V_4 = F_42 ( V_58 ) ;
int V_47 ;
V_117 -> V_118 = V_119 ;
V_47 = F_31 ( & V_4 -> V_54 ) ;
if ( V_47 )
return V_47 ;
return 0 ;
}
static int F_43 ( struct V_113 * V_58 )
{
struct V_3 * V_4 = F_42 ( V_58 ) ;
F_35 ( & V_4 -> V_54 ) ;
return 0 ;
}
static int F_44 ( struct V_113 * V_58 )
{
struct V_3 * V_4 = F_42 ( V_58 ) ;
struct V_116 * V_117 = V_58 -> V_117 ;
struct V_61 * V_54 = & V_4 -> V_54 ;
V_54 -> V_76 = V_117 -> V_120 ;
V_54 -> V_121 = F_22 ( V_54 , V_117 -> V_63 ) ;
memset ( & V_54 -> V_122 , 0 , sizeof( V_54 -> V_122 ) ) ;
V_54 -> V_122 . V_123 = V_100 ;
V_54 -> V_122 . V_124 = F_45 ( V_58 ) ;
V_54 -> V_58 = V_58 ;
F_25 ( V_4 ) ;
return 0 ;
}
static int F_46 ( struct V_113 * V_58 , int V_125 )
{
struct V_3 * V_4 = F_42 ( V_58 ) ;
switch ( V_125 ) {
case V_126 :
V_4 -> V_54 . V_122 . V_127 = V_4 -> V_54 . V_99 ;
V_4 -> V_54 . V_122 . V_128 = 0 ;
V_58 -> V_129 -> V_130 ( V_58 ) ;
F_27 ( V_4 ) ;
break;
case V_131 :
F_29 ( V_4 ) ;
break;
default:
return - V_40 ;
}
return 0 ;
}
static T_5
F_47 ( struct V_113 * V_58 )
{
struct V_3 * V_4 = F_42 ( V_58 ) ;
struct V_61 * V_54 = & V_4 -> V_54 ;
return F_48 ( V_58 , & V_54 -> V_122 ,
V_54 -> V_55 . V_55 -> V_132 ) ;
}
static void F_49 ( struct V_113 * V_58 ,
struct V_133 * V_134 , T_6 V_135 )
{
struct V_3 * V_4 = F_42 ( V_58 ) ;
unsigned char * V_136 = V_4 -> V_54 . V_103 + V_134 -> V_128 ;
memcpy ( V_136 , V_58 -> V_117 -> V_137 + V_134 -> V_138 , V_135 ) ;
F_34 ( NULL , V_136 , V_135 , V_111 ) ;
}
static int F_50 ( struct V_113 * V_58 )
{
struct V_3 * V_4 = F_42 ( V_58 ) ;
struct V_61 * V_54 = & V_4 -> V_54 ;
V_54 -> V_122 . V_139 = V_100 / 2 ;
return F_51 ( V_58 ,
& V_54 -> V_122 ,
F_49 ) ;
}
static int F_52 ( struct V_113 * V_58 )
{
struct V_116 * V_117 = V_58 -> V_117 ;
struct V_3 * V_4 = F_42 ( V_58 ) ;
struct V_61 * V_60 = & V_4 -> V_60 ;
int V_47 ;
V_117 -> V_118 = V_119 ;
V_47 = F_31 ( V_60 ) ;
if ( V_47 )
return V_47 ;
return 0 ;
}
static int F_53 ( struct V_113 * V_58 )
{
struct V_3 * V_4 = F_42 ( V_58 ) ;
F_35 ( & V_4 -> V_60 ) ;
return 0 ;
}
static int F_54 ( struct V_113 * V_58 )
{
struct V_3 * V_4 = F_42 ( V_58 ) ;
struct V_116 * V_117 = V_58 -> V_117 ;
struct V_61 * V_60 = & V_4 -> V_60 ;
V_60 -> V_76 = V_117 -> V_120 ;
V_60 -> V_121 = F_22 ( V_60 , V_117 -> V_63 ) ;
memset ( & V_60 -> V_122 , 0 , sizeof( V_60 -> V_122 ) ) ;
V_60 -> V_122 . V_123 = V_100 ;
V_60 -> V_122 . V_139 = V_100 / 2 ;
V_60 -> V_122 . V_124 = F_45 ( V_58 ) ;
V_60 -> V_58 = V_58 ;
F_26 ( V_4 ) ;
return 0 ;
}
static int F_55 ( struct V_113 * V_58 , int V_125 )
{
struct V_3 * V_4 = F_42 ( V_58 ) ;
switch ( V_125 ) {
case V_126 :
V_4 -> V_60 . V_122 . V_127 = V_4 -> V_60 . V_99 ;
V_4 -> V_60 . V_122 . V_128 = 0 ;
F_56 ( V_140 L_1 , V_4 -> V_60 . V_99 ) ;
F_28 ( V_4 ) ;
break;
case V_131 :
F_30 ( V_4 ) ;
break;
default:
return - V_40 ;
}
return 0 ;
}
static T_5
F_57 ( struct V_113 * V_58 )
{
struct V_3 * V_4 = F_42 ( V_58 ) ;
struct V_61 * V_60 = & V_4 -> V_60 ;
return F_58 ( V_58 , & V_60 -> V_122 ,
V_60 -> V_55 . V_55 -> V_132 ) ;
}
static void F_59 ( struct V_113 * V_58 ,
struct V_133 * V_134 , T_6 V_135 )
{
struct V_3 * V_4 = F_42 ( V_58 ) ;
unsigned char * V_136 = V_4 -> V_60 . V_103 + V_134 -> V_128 ;
F_34 ( NULL , V_136 , V_135 , V_141 ) ;
memcpy ( V_58 -> V_117 -> V_137 + V_134 -> V_138 , V_136 , V_135 ) ;
}
static int F_60 ( struct V_113 * V_58 )
{
struct V_3 * V_4 = F_42 ( V_58 ) ;
struct V_61 * V_60 = & V_4 -> V_60 ;
return F_61 ( V_58 ,
& V_60 -> V_122 ,
F_59 ) ;
}
static int F_62 ( struct V_3 * V_4 )
{
struct V_142 * V_143 ;
int V_47 ;
V_47 = F_63 ( V_4 -> V_48 , L_2 , 0 , 1 , 1 , & V_143 ) ;
if ( V_47 < 0 )
return V_47 ;
V_143 -> V_144 = V_4 ;
strcpy ( V_143 -> V_145 , L_3 ) ;
F_64 ( V_143 , V_146 ,
& V_147 ) ;
F_64 ( V_143 , V_148 ,
& V_149 ) ;
F_65 ( V_143 , V_150 ,
F_66 ( V_104 ) ,
0 , 1024 * 1024 ) ;
return 0 ;
}
static int F_67 ( struct V_151 * V_152 )
{
struct V_3 * V_4 = V_152 -> V_153 ;
F_68 ( V_154 , V_4 ) ;
F_69 ( V_4 ) ;
return 0 ;
}
static void F_70 ( struct V_61 * V_62 , struct V_155 * V_156 ,
int V_157 )
{
V_62 -> V_55 . V_85 = V_157 ;
V_62 -> V_55 . V_55 = & V_156 -> V_158 [ V_157 ] ;
}
static int F_71 ( struct V_3 * V_4 )
{
unsigned short V_159 , V_160 , V_161 ;
unsigned short V_162 ;
F_3 ( 0 , & V_4 -> V_9 -> V_163 ) ;
F_3 ( V_164 | V_165 ,
& V_4 -> V_9 -> V_163 ) ;
F_8 ( V_4 , V_166 , V_167 ) ;
V_162 = F_1 ( & V_4 -> V_9 -> V_162 ) ;
if ( V_162 & V_168 )
return - V_169 ;
V_159 = ( V_162 & V_170 ) >> 12 ;
V_160 = ( V_162 & V_171 ) >> 4 ;
V_161 = ( V_162 & V_172 ) ;
F_56 ( V_173 L_4 ,
V_159 , V_160 , V_161 ) ;
return 0 ;
}
static int F_72 ( struct V_174 * V_48 , struct V_3 * * V_175 )
{
struct V_3 * V_4 ;
struct V_155 * V_156 = V_176 ;
int V_47 ;
V_4 = F_73 ( sizeof( struct V_3 ) , V_104 ) ;
if ( ! V_4 )
return - V_106 ;
V_4 -> V_48 = V_48 ;
if ( F_74 ( V_154 , F_20 , V_177 ,
L_3 , V_4 ) ) {
F_56 ( V_178 L_5 , V_154 ) ;
F_69 ( V_4 ) ;
return - V_179 ;
}
V_4 -> V_9 = (struct V_7 * ) V_156 -> V_180 [ 0 ] ;
V_4 -> V_181 = (struct V_182 * ) V_156 -> V_180 [ 1 ] ;
V_4 -> V_183 = (struct V_184 * ) V_156 -> V_180 [ 2 ] ;
V_4 -> V_185 = (struct V_186 * ) V_156 -> V_180 [ 3 ] ;
if ( F_71 ( V_4 ) < 0 ) {
F_69 ( V_4 ) ;
return - V_169 ;
}
F_70 ( & V_4 -> V_54 , V_156 , 0 ) ;
F_70 ( & V_4 -> V_60 , V_156 , 1 ) ;
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
V_156 -> V_187 [ V_4 -> V_54 . V_55 . V_85 ] [ 0 ] = 0x8208844 ;
V_156 -> V_187 [ V_4 -> V_60 . V_55 . V_85 ] [ 0 ] = 0x8208844 ;
V_47 = F_76 ( V_48 , V_188 , V_4 , & V_189 ) ;
if ( V_47 < 0 ) {
F_68 ( V_154 , V_4 ) ;
F_69 ( V_4 ) ;
return V_47 ;
}
* V_175 = V_4 ;
return 0 ;
}
static int F_77 ( struct V_190 * V_191 )
{
struct V_174 * V_48 ;
struct V_3 * V_192 ;
int V_47 ;
V_47 = F_78 ( & V_191 -> V_193 , V_157 , V_194 , V_195 , 0 , & V_48 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_72 ( V_48 , & V_192 ) ;
if ( V_47 < 0 ) {
F_79 ( V_48 ) ;
return V_47 ;
}
V_47 = F_62 ( V_192 ) ;
if ( V_47 < 0 ) {
F_79 ( V_48 ) ;
return V_47 ;
}
V_47 = F_17 ( V_192 ) ;
if ( V_47 < 0 ) {
F_79 ( V_48 ) ;
return V_47 ;
}
strcpy ( V_48 -> V_196 , L_2 ) ;
strcpy ( V_48 -> V_197 , L_2 ) ;
sprintf ( V_48 -> V_198 , L_6 ,
V_48 -> V_197 ,
V_154 ) ;
V_47 = F_80 ( V_48 ) ;
if ( V_47 < 0 ) {
F_79 ( V_48 ) ;
return V_47 ;
}
F_81 ( V_191 , V_48 ) ;
return 0 ;
}
static int F_82 ( struct V_190 * V_191 )
{
struct V_174 * V_48 = F_83 ( V_191 ) ;
F_79 ( V_48 ) ;
return 0 ;
}
