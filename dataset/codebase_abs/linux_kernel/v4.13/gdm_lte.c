static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_2 -> V_5 & V_6 )
return - V_7 ;
return 0 ;
}
static void F_6 ( void * V_8 )
{
struct V_9 * V_9 = V_8 ;
if ( F_7 ( V_9 -> V_10 ) )
F_8 ( V_9 -> V_10 ) ;
}
static int F_9 ( struct V_11 * V_12 , struct V_9 * V_9 , int V_13 )
{
int V_14 ;
V_14 = F_10 ( V_12 ) ;
if ( V_14 == V_15 ) {
V_9 -> V_16 . V_17 ++ ;
} else {
V_9 -> V_16 . V_18 ++ ;
V_9 -> V_16 . V_19 += V_12 -> V_20 + V_21 ;
}
return 0 ;
}
static int F_11 ( struct V_11 * V_22 , T_1 V_13 )
{
struct V_9 * V_9 = F_12 ( V_22 -> V_2 ) ;
struct V_11 * V_23 ;
struct V_24 V_25 ;
struct V_26 V_27 ;
struct V_28 * V_29 ;
struct V_28 * V_30 ;
struct V_31 {
T_2 V_32 [ V_33 ] ;
T_2 V_34 [ 4 ] ;
T_2 V_35 [ V_33 ] ;
T_2 V_36 [ 4 ] ;
};
struct V_31 * V_37 ;
struct V_31 * V_38 ;
T_2 V_39 [ 60 ] ;
void * V_40 ;
T_1 V_41 ;
if ( F_13 ( ( (struct V_24 * ) V_22 -> V_42 ) -> V_43 ) == V_44 ) {
memcpy ( & V_27 , V_22 -> V_42 , sizeof( struct V_26 ) ) ;
V_40 = & V_27 ;
V_41 = V_45 ;
} else {
memcpy ( & V_25 , V_22 -> V_42 , sizeof( struct V_24 ) ) ;
V_40 = & V_25 ;
V_41 = V_21 ;
}
V_29 = (struct V_28 * ) ( V_22 -> V_42 + V_41 ) ;
V_37 = (struct V_31 * ) ( V_22 -> V_42 + V_41 +
sizeof( struct V_28 ) ) ;
V_30 = (struct V_28 * ) V_39 ;
V_38 = (struct V_31 * ) ( V_39 + sizeof( struct V_28 ) ) ;
memcpy ( V_30 , V_29 , sizeof( struct V_28 ) ) ;
V_30 -> V_46 = F_14 ( V_47 ) ;
V_38 -> V_32 [ 0 ] = V_37 -> V_32 [ 0 ] ;
V_38 -> V_32 [ 1 ] = V_37 -> V_32 [ 1 ] ;
memcpy ( & V_38 -> V_32 [ 2 ] , & V_37 -> V_36 [ 0 ] , 4 ) ;
memcpy ( & V_38 -> V_34 [ 0 ] , & V_37 -> V_36 [ 0 ] , 4 ) ;
memcpy ( & V_38 -> V_35 [ 0 ] , & V_37 -> V_32 [ 0 ] , 6 ) ;
memcpy ( & V_38 -> V_36 [ 0 ] , & V_37 -> V_34 [ 0 ] , 4 ) ;
memcpy ( V_40 , V_40 + V_33 , V_33 ) ;
memcpy ( V_40 + V_33 , V_9 -> V_48 , V_33 ) ;
V_23 = F_15 ( V_22 -> V_20 ) ;
if ( ! V_23 )
return - V_49 ;
F_16 ( V_23 , V_50 ) ;
F_17 ( V_23 , V_40 , V_41 ) ;
F_17 ( V_23 , V_30 , sizeof( struct V_28 ) ) ;
F_17 ( V_23 , V_38 , sizeof( struct V_31 ) ) ;
V_23 -> V_51 = ( (struct V_24 * ) V_40 ) -> V_43 ;
V_23 -> V_2 = V_22 -> V_2 ;
F_18 ( V_23 ) ;
F_19 ( V_23 , V_21 ) ;
F_9 ( V_23 , V_9 , V_13 ) ;
return 0 ;
}
static T_3 F_20 ( struct V_52 * V_53 , T_4 * V_54 , int V_20 )
{
unsigned short * V_55 = V_54 ;
T_5 V_56 = 0 ;
int V_57 ;
union {
struct {
T_2 V_58 [ 16 ] ;
T_2 V_59 [ 16 ] ;
T_1 V_60 ;
T_2 V_61 [ 3 ] ;
T_2 V_62 ;
} V_63 V_64 ;
T_4 V_65 [ 20 ] ;
} V_66 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
memcpy ( & V_66 . V_63 . V_58 , & V_53 -> V_67 . V_68 . V_69 , 16 ) ;
memcpy ( & V_66 . V_63 . V_59 , & V_53 -> V_70 . V_68 . V_69 , 16 ) ;
V_66 . V_63 . V_60 = F_21 ( V_53 -> V_71 ) ;
V_66 . V_63 . V_62 = V_53 -> V_72 ;
V_55 = ( T_4 * ) & V_66 ;
for ( V_57 = 0 ; V_57 < F_22 ( V_66 . V_65 ) ; V_57 ++ )
V_56 = F_23 ( V_56 , F_24 (
( V_73 T_3 ) V_66 . V_65 [ V_57 ] ) ) ;
V_55 = V_54 ;
while ( V_20 > 1 ) {
V_56 = F_23 ( V_56 , F_24 ( ( V_73 T_3 ) * V_55 ++ ) ) ;
V_20 -= 2 ;
}
return F_25 ( V_56 ) ;
}
static int F_26 ( struct V_11 * V_22 , T_1 V_13 )
{
struct V_9 * V_9 = F_12 ( V_22 -> V_2 ) ;
struct V_11 * V_23 ;
struct V_24 V_25 ;
struct V_26 V_27 ;
struct V_74 {
T_2 V_75 [ 16 ] ;
T_2 type ;
T_2 V_76 ;
T_2 V_77 [ 6 ] ;
};
struct V_74 V_78 ;
struct V_79 {
T_2 V_75 [ 16 ] ;
};
struct V_79 * V_80 ;
struct V_52 * V_81 ;
struct V_52 V_82 ;
struct V_83 * V_84 ;
struct V_83 V_85 ;
void * V_40 ;
T_1 V_41 ;
if ( F_13 ( ( (struct V_24 * ) V_22 -> V_42 ) -> V_43 ) == V_44 ) {
memcpy ( & V_27 , V_22 -> V_42 , sizeof( struct V_26 ) ) ;
if ( F_13 ( V_27 . V_86 ) != V_87 )
return - 1 ;
V_40 = & V_27 ;
V_41 = V_45 ;
} else {
memcpy ( & V_25 , V_22 -> V_42 , sizeof( struct V_24 ) ) ;
if ( F_13 ( V_25 . V_43 ) != V_87 )
return - 1 ;
V_40 = & V_25 ;
V_41 = V_21 ;
}
V_81 = (struct V_52 * ) ( V_22 -> V_42 + V_41 ) ;
if ( V_81 -> V_88 != 6 || V_81 -> V_72 != V_89 )
return - 1 ;
V_84 = (struct V_83 * ) ( V_22 -> V_42 + V_41 +
sizeof( struct V_52 ) ) ;
if ( V_84 -> V_90 == V_91 ) {
return - 1 ;
} else if ( V_84 -> V_90 == V_92 ) {
T_2 V_93 [ sizeof( struct V_83 ) +
sizeof( struct V_74 ) ] ;
T_2 V_94 [ 16 ] = { 0 ,} ;
if ( memcmp ( V_81 -> V_67 . V_68 . V_69 , V_94 , 16 ) == 0 )
return 0 ;
V_85 . V_90 = V_95 ;
V_85 . V_96 = 0 ;
V_85 . V_97 = 0 ;
V_85 . V_98 . V_99 [ 0 ] = F_27 ( 0x60000000 ) ;
V_80 = (struct V_79 * )
( V_22 -> V_42 + V_41 +
sizeof( struct V_52 ) + sizeof( struct V_83 ) ) ;
memcpy ( & V_78 . V_75 , V_80 -> V_75 , 16 ) ;
V_78 . type = 0x02 ;
V_78 . V_76 = 1 ;
V_78 . V_77 [ 0 ] = 0x00 ;
V_78 . V_77 [ 1 ] = 0x0a ;
V_78 . V_77 [ 2 ] = 0x3b ;
V_78 . V_77 [ 3 ] = 0xaf ;
V_78 . V_77 [ 4 ] = 0x63 ;
V_78 . V_77 [ 5 ] = 0xc7 ;
memcpy ( & V_82 , V_81 , sizeof( struct V_52 ) ) ;
memcpy ( V_82 . V_67 . V_68 . V_69 , & V_78 . V_75 , 16 ) ;
memcpy ( V_82 . V_70 . V_68 . V_69 ,
V_81 -> V_67 . V_68 . V_69 , 16 ) ;
V_82 . V_71 = F_14 ( sizeof( struct V_83 ) +
sizeof( struct V_74 ) ) ;
memcpy ( V_93 , & V_85 , sizeof( struct V_83 ) ) ;
memcpy ( V_93 + sizeof( struct V_83 ) , & V_78 ,
sizeof( struct V_74 ) ) ;
V_85 . V_97 = F_20 ( & V_82 ,
( T_4 * ) V_93 , sizeof( V_93 ) ) ;
} else {
return - 1 ;
}
memcpy ( V_40 , V_40 + V_33 , V_33 ) ;
memcpy ( V_40 + V_33 , V_9 -> V_48 , V_33 ) ;
V_23 = F_15 ( V_22 -> V_20 ) ;
if ( ! V_23 )
return - V_49 ;
F_16 ( V_23 , V_50 ) ;
F_17 ( V_23 , V_40 , V_41 ) ;
F_17 ( V_23 , & V_82 , sizeof( struct V_52 ) ) ;
F_17 ( V_23 , & V_85 , sizeof( struct V_83 ) ) ;
F_17 ( V_23 , & V_78 , sizeof( struct V_74 ) ) ;
V_23 -> V_51 = ( (struct V_24 * ) V_40 ) -> V_43 ;
V_23 -> V_2 = V_22 -> V_2 ;
F_18 ( V_23 ) ;
F_19 ( V_23 , V_21 ) ;
F_9 ( V_23 , V_9 , V_13 ) ;
return 0 ;
}
static T_6 F_28 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_9 * V_9 = F_12 ( V_2 ) ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
struct V_100 * V_101 ;
struct V_52 * V_53 ;
int V_102 ;
void * V_103 ;
T_1 V_13 ;
V_13 = 0x00000010 | V_9 -> V_104 ;
V_25 = (struct V_24 * ) V_12 -> V_42 ;
if ( F_13 ( V_25 -> V_43 ) == V_44 ) {
V_27 = (struct V_26 * ) V_12 -> V_42 ;
V_102 = F_13 ( V_27 -> V_86 ) ;
V_103 = V_12 -> V_42 + V_45 ;
V_13 |= V_105 ;
} else {
V_102 = F_13 ( V_25 -> V_43 ) ;
V_103 = V_12 -> V_42 + V_21 ;
}
switch ( V_102 ) {
case V_106 :
V_13 |= V_107 ;
break;
case V_108 :
V_13 |= V_109 ;
V_101 = V_103 ;
if ( V_101 -> V_51 == V_110 ) {
struct V_111 * V_112 =
V_103 + sizeof( struct V_100 ) ;
if ( F_13 ( V_112 -> V_113 ) == 67 || F_13 ( V_112 -> V_113 ) == 68 )
V_13 |= V_114 ;
}
break;
case V_87 :
V_13 |= V_115 ;
V_53 = V_103 ;
if ( V_53 -> V_72 == V_89 ) {
struct V_83 * V_116 =
V_103 + sizeof( struct V_52 ) ;
if ( V_116 -> V_90 == V_92 )
V_13 |= V_117 ;
} else if ( V_53 -> V_72 == V_110 ) {
struct V_111 * V_112 =
V_103 + sizeof( struct V_52 ) ;
if ( F_13 ( V_112 -> V_113 ) == 546 || F_13 ( V_112 -> V_113 ) == 547 )
V_13 |= V_114 ;
}
break;
default:
break;
}
return V_13 ;
}
static int F_29 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
struct V_9 * V_9 = F_12 ( V_2 ) ;
T_1 V_13 ;
void * V_118 ;
int V_119 ;
int V_120 ;
int V_14 = 0 ;
V_13 = F_28 ( V_2 , V_12 ) ;
if ( V_13 == 0 ) {
F_30 ( V_2 , L_1 ) ;
return - 1 ;
}
if ( V_13 & V_107 ) {
if ( F_11 ( V_12 , V_13 ) == 0 ) {
F_31 ( V_12 ) ;
return 0 ;
}
}
if ( V_13 & V_117 ) {
if ( F_26 ( V_12 , V_13 ) == 0 ) {
F_31 ( V_12 ) ;
return 0 ;
}
}
if ( V_13 & V_105 ) {
struct V_26 * V_27 = (struct V_26 * ) V_12 -> V_42 ;
V_9 -> V_121 = F_13 ( V_27 -> V_122 ) & V_123 ;
V_118 = V_12 -> V_42 + ( V_45 - V_21 ) ;
V_119 = V_12 -> V_20 - ( V_45 - V_21 ) ;
} else {
V_9 -> V_121 = 0 ;
V_118 = V_12 -> V_42 ;
V_119 = V_12 -> V_20 ;
}
if ( V_13 & V_117 )
V_13 = V_117 ;
if ( ! ( V_13 & V_114 ) )
V_13 &= V_124 ;
V_14 = sscanf ( V_2 -> V_125 , L_2 , & V_120 ) ;
if ( V_14 != 1 ) {
F_31 ( V_12 ) ;
return - V_126 ;
}
V_14 = V_9 -> V_127 -> V_128 ( V_9 -> V_127 -> V_129 ,
V_118 , V_119 ,
V_9 -> V_130 . V_131 , 0 ,
F_6 , V_9 , V_120 ,
V_13 ) ;
if ( V_14 == V_132 || V_14 == V_133 ) {
F_4 ( V_2 ) ;
if ( V_14 == V_132 )
V_14 = 0 ;
else
V_14 = - V_134 ;
} else if ( V_14 == V_135 ) {
V_14 = - V_136 ;
}
if ( V_14 ) {
V_9 -> V_16 . V_137 ++ ;
} else {
V_9 -> V_16 . V_138 ++ ;
V_9 -> V_16 . V_139 += V_119 ;
}
F_31 ( V_12 ) ;
return 0 ;
}
static struct V_140 * F_32 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_12 ( V_2 ) ;
return & V_9 -> V_16 ;
}
static int F_33 ( struct V_1 * V_2 , char * V_141 , int V_20 )
{
struct V_9 * V_9 = F_12 ( V_2 ) ;
struct V_142 * V_143 = (struct V_142 * ) V_141 ;
int V_120 ;
int V_14 ;
V_14 = sscanf ( V_2 -> V_125 , L_2 , & V_120 ) ;
if ( V_14 != 1 )
return - V_126 ;
return F_34 ( V_144 . V_145 , V_120 , 0 , V_141 ,
F_35 (
V_9 -> V_127 -> V_146 (
V_9 -> V_127 -> V_129 ) , V_143 -> V_20 )
+ V_147 ) ;
}
static void F_36 ( struct V_1 * V_2 , T_4 type ,
void * V_148 , int V_20 )
{
struct V_9 * V_9 = F_12 ( V_2 ) ;
V_9 -> V_127 -> V_149 ( V_9 -> V_127 -> V_129 , V_148 , V_20 , NULL ,
NULL ) ;
}
int F_37 ( void )
{
if ( V_144 . V_150 == 0 )
V_144 . V_145 = F_38 ( V_151 , F_36 ) ;
if ( V_144 . V_145 ) {
V_144 . V_150 ++ ;
return 0 ;
}
F_39 ( L_3 ) ;
return - 1 ;
}
void F_40 ( void )
{
if ( V_144 . V_145 && -- V_144 . V_150 == 0 ) {
F_41 ( V_144 . V_145 -> V_152 ) ;
V_144 . V_145 = NULL ;
}
}
static int F_42 ( T_1 V_13 )
{
T_2 V_153 ;
V_153 = ( T_2 ) ( V_13 & 0x0000000f ) ;
if ( V_153 >= V_154 )
return - V_126 ;
return V_153 ;
}
static void F_43 ( struct V_1 * V_2 , char * V_141 ,
int V_20 , int V_155 )
{
T_1 V_13 ;
struct V_9 * V_9 ;
struct V_11 * V_12 ;
struct V_24 V_25 ;
struct V_26 V_27 ;
void * V_40 ;
T_1 V_41 ;
char V_156 = 0 ;
V_13 = V_155 & V_124 ;
V_9 = F_12 ( V_2 ) ;
if ( V_155 & V_114 ) {
if ( V_155 & V_109 ) {
struct V_157 {
T_2 V_158 ;
T_2 V_159 ;
T_2 V_160 ;
T_2 V_161 ;
T_1 V_162 ;
T_4 V_163 ;
T_4 V_5 ;
#define F_44 0x8000
T_1 V_164 ;
T_1 V_165 ;
T_1 V_166 ;
T_1 V_167 ;
T_2 V_168 [ 16 ] ;
T_2 V_169 [ 64 ] ;
T_2 V_170 [ 128 ] ;
T_1 V_171 ;
} V_64 ;
void * V_172 = V_141 + sizeof( struct V_100 ) +
sizeof( struct V_111 ) +
F_45 ( struct V_157 , V_168 ) ;
F_46 ( V_9 -> V_173 , V_172 ) ;
}
}
if ( V_9 -> V_121 > 0 ) {
V_40 = ( void * ) & V_27 ;
V_41 = V_45 ;
} else {
V_40 = ( void * ) & V_25 ;
V_41 = V_21 ;
}
F_46 ( V_40 , V_9 -> V_173 ) ;
memcpy ( V_40 + V_33 , V_9 -> V_48 , V_33 ) ;
V_27 . V_122 = F_14 ( V_9 -> V_121 ) ;
V_27 . V_174 = F_14 ( V_44 ) ;
if ( V_13 == V_107 ) {
V_25 . V_43 = F_14 ( V_106 ) ;
V_27 . V_86 = F_14 ( V_106 ) ;
} else {
V_156 = V_141 [ 0 ] >> 4 ;
if ( V_156 == V_175 ) {
V_25 . V_43 = F_14 ( V_108 ) ;
V_27 . V_86 = F_14 ( V_108 ) ;
} else if ( V_156 == V_176 ) {
V_25 . V_43 = F_14 ( V_87 ) ;
V_27 . V_86 = F_14 ( V_87 ) ;
} else {
F_30 ( V_2 , L_4 , V_156 ) ;
return;
}
}
V_12 = F_15 ( V_20 + V_41 + V_50 ) ;
if ( ! V_12 )
return;
F_16 ( V_12 , V_50 ) ;
F_17 ( V_12 , V_40 , V_41 ) ;
F_17 ( V_12 , V_141 , V_20 ) ;
V_12 -> V_51 = ( (struct V_24 * ) V_40 ) -> V_43 ;
V_12 -> V_2 = V_2 ;
F_18 ( V_12 ) ;
F_19 ( V_12 , V_21 ) ;
F_9 ( V_12 , V_9 , V_13 ) ;
}
static void F_47 ( struct V_127 * V_127 , char * V_141 , int V_20 )
{
struct V_1 * V_2 ;
struct V_177 * V_177 = (struct V_177 * ) V_141 ;
struct V_178 * V_178 = NULL ;
struct V_179 * V_180 = V_127 -> V_146 ( V_127 -> V_129 ) ;
T_2 * V_42 = ( T_2 * ) V_177 -> V_42 ;
T_4 V_57 = 0 ;
T_4 V_181 ;
T_4 V_182 ;
T_4 V_183 ;
T_1 V_13 ;
int V_153 ;
V_182 = F_35 ( V_180 , V_177 -> V_20 ) ;
V_181 = F_35 ( V_180 , V_177 -> V_181 ) ;
for ( V_57 = 0 ; V_57 < V_181 ; V_57 ++ ) {
V_178 = (struct V_178 * ) V_42 ;
V_183 = F_35 ( V_180 , V_178 -> V_183 ) ;
V_182 = F_35 ( V_180 , V_178 -> V_20 ) ;
V_13 = F_48 ( V_180 , V_178 -> V_13 ) ;
if ( V_183 != V_184 ) {
F_39 ( L_5 , V_183 ) ;
return;
}
if ( V_182 < 12 ) {
F_39 ( L_6 , V_182 ) ;
return;
}
V_153 = F_42 ( V_13 ) ;
if ( V_153 < 0 ) {
F_39 ( L_7 , V_13 ) ;
return;
}
V_2 = V_127 -> V_2 [ V_153 ] ;
F_43 ( V_2 , ( char * ) V_178 -> V_42 ,
( int ) ( V_182 - 12 ) , V_13 ) ;
V_42 += ( ( V_182 + 3 ) & 0xfffc ) + V_147 ;
}
}
static void F_49 ( struct V_1 * V_2 , char * V_141 , int V_20 )
{
struct V_9 * V_9 = F_12 ( V_2 ) ;
struct V_185 * V_130 = (struct V_185 * ) V_141 ;
if ( V_130 -> V_186 ) {
V_9 -> V_130 . V_186 = V_130 -> V_186 ;
V_9 -> V_130 . V_131 = F_48 (
V_9 -> V_127 -> V_146 (
V_9 -> V_127 -> V_129 ) ,
V_130 -> V_131 ) ;
V_9 -> V_130 . V_13 = F_48 (
V_9 -> V_127 -> V_146 (
V_9 -> V_127 -> V_129 ) ,
V_130 -> V_13 ) ;
F_50 ( V_2 , L_8 ,
V_9 -> V_130 . V_13 ) ;
} else {
memset ( & V_9 -> V_130 , 0x00 , sizeof( struct V_130 ) ) ;
F_50 ( V_2 , L_9 ) ;
}
}
static int F_51 ( struct V_127 * V_127 , char * V_141 , int V_20 )
{
struct V_142 * V_143 = (struct V_142 * ) V_141 ;
struct V_185 * V_130 = (struct V_185 * ) V_141 ;
struct V_179 * V_180 = V_127 -> V_146 ( V_127 -> V_129 ) ;
struct V_178 * V_178 ;
struct V_1 * V_2 ;
int V_14 = 0 ;
T_4 V_183 ;
T_1 V_13 ;
int V_153 ;
if ( ! V_20 )
return V_14 ;
V_183 = F_35 ( V_180 , V_143 -> V_183 ) ;
V_2 = V_127 -> V_2 [ 0 ] ;
if ( ! V_2 )
return 0 ;
switch ( V_183 ) {
case V_184 :
V_178 = (struct V_178 * ) V_143 -> V_42 ;
V_13 = F_48 ( V_180 , V_178 -> V_13 ) ;
V_153 = F_42 ( V_13 ) ;
if ( V_153 < 0 )
return V_153 ;
V_2 = V_127 -> V_2 [ V_153 ] ;
F_43 ( V_2 , V_143 -> V_42 , V_20 , V_13 ) ;
break;
case V_187 :
F_47 ( V_127 , V_141 , V_20 ) ;
break;
case V_188 :
F_50 ( V_2 , L_10 ,
( (struct V_189 * ) V_141 ) -> V_190
? L_11 : L_12 ) ;
break;
case V_191 :
V_130 = (struct V_185 * ) V_141 ;
V_13 = F_48 ( V_180 , V_130 -> V_13 ) ;
V_153 = F_42 ( V_13 ) ;
if ( V_153 < 0 )
return V_153 ;
V_2 = V_127 -> V_2 [ V_153 ] ;
F_49 ( V_2 , V_141 , V_20 ) ;
default:
V_14 = F_33 ( V_2 , V_141 , V_20 ) ;
break;
}
return V_14 ;
}
static int F_52 ( void * V_8 , void * V_42 , int V_20 , int V_192 )
{
struct V_127 * V_127 = V_8 ;
return F_51 ( V_127 , V_42 , V_20 ) ;
}
void F_53 ( struct V_127 * V_127 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_193 ; V_57 ++ )
V_127 -> V_194 ( V_127 -> V_129 ,
F_52 , V_127 , V_195 ) ;
}
static void F_54 ( T_2 * V_196 , T_2 * V_197 , T_2 * V_198 ,
T_2 * V_199 , T_2 V_153 )
{
if ( ! V_199 )
F_46 ( V_196 , V_200 ) ;
else
F_46 ( V_196 , V_199 ) ;
V_196 [ V_33 - 1 ] += V_153 ;
F_55 ( V_197 ) ;
memcpy ( V_197 , V_196 , 3 ) ;
F_46 ( V_198 , V_196 ) ;
}
static void F_56 ( T_2 * V_199 )
{
if ( F_57 ( V_199 ) || ( V_199 [ 0 ] & 0x01 ) ) {
F_39 ( L_13 ) ;
memcpy ( V_199 , V_200 , 6 ) ;
}
}
int F_58 ( struct V_127 * V_127 ,
struct V_201 * V_2 , T_2 * V_199 )
{
struct V_9 * V_9 ;
struct V_1 * V_202 ;
char V_203 [ 16 ] ;
int V_14 = 0 ;
T_2 V_153 ;
F_56 ( V_199 ) ;
for ( V_153 = 0 ; V_153 < V_154 ; V_153 ++ ) {
sprintf ( V_203 , L_14 , V_153 ) ;
V_202 = F_59 ( sizeof( struct V_9 ) , V_203 ,
V_204 , V_205 ) ;
if ( ! V_202 ) {
F_39 ( L_15 ) ;
V_14 = - V_49 ;
goto V_206;
}
V_202 -> V_207 = & V_208 ;
V_202 -> V_5 &= ~ V_209 ;
V_202 -> V_210 = V_211 ;
V_9 = F_12 ( V_202 ) ;
memset ( V_9 , 0 , sizeof( struct V_9 ) ) ;
V_9 -> V_10 = V_202 ;
V_9 -> V_127 = V_127 ;
V_9 -> V_104 = V_153 ;
F_54 (
V_202 -> V_196 ,
V_9 -> V_48 ,
V_9 -> V_173 ,
V_199 ,
V_153 ) ;
F_60 ( V_202 , V_2 ) ;
F_61 ( V_202 , & V_212 ) ;
V_14 = F_62 ( V_202 ) ;
if ( V_14 )
goto V_206;
F_63 ( V_202 ) ;
V_127 -> V_2 [ V_153 ] = V_202 ;
}
return 0 ;
V_206:
F_64 ( V_127 ) ;
return V_14 ;
}
void F_64 ( struct V_127 * V_127 )
{
struct V_1 * V_202 ;
int V_153 ;
for ( V_153 = 0 ; V_153 < V_154 ; V_153 ++ ) {
V_202 = V_127 -> V_2 [ V_153 ] ;
if ( ! V_202 )
continue;
F_65 ( V_202 ) ;
F_66 ( V_202 ) ;
}
}
