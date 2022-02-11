static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
T_1 V_5 , int V_6 , unsigned int V_7 )
{
struct V_8 V_9 ;
const struct V_8 * V_10 ;
if ( V_5 == V_11 )
F_2 ( V_2 , L_1 ) ;
else
F_2 ( V_2 , L_2 ) ;
if ( V_6 )
goto V_12;
V_10 = F_3 ( V_4 , V_7 , sizeof( V_9 ) , & V_9 ) ;
if ( V_10 == NULL ) {
F_2 ( V_2 , L_3 , V_4 -> V_13 - V_7 ) ;
return 1 ;
}
F_2 ( V_2 , L_4 , F_4 ( V_10 -> V_14 ) , F_4 ( V_10 -> V_15 ) ,
F_4 ( V_10 -> V_13 ) ) ;
V_12:
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
T_1 V_5 , int V_6 , unsigned int V_7 ,
unsigned int V_16 )
{
struct V_17 V_18 ;
const struct V_17 * V_19 ;
F_2 ( V_2 , L_5 ) ;
if ( V_6 )
return 0 ;
V_19 = F_3 ( V_4 , V_7 , sizeof( V_18 ) , & V_18 ) ;
if ( V_19 == NULL ) {
F_2 ( V_2 , L_3 , V_4 -> V_13 - V_7 ) ;
return 1 ;
}
F_2 ( V_2 , L_6 , F_4 ( V_19 -> V_14 ) , F_4 ( V_19 -> V_15 ) ) ;
if ( V_16 & V_20 )
F_2 ( V_2 , L_7 , F_6 ( V_19 -> V_21 ) , F_6 ( V_19 -> V_22 ) ) ;
F_2 ( V_2 , L_8 , F_4 ( V_19 -> V_23 ) ) ;
F_2 ( V_2 , L_9 , ( V_24 ) ( F_6 ( F_7 ( V_19 ) &
V_25 ) >> 22 ) ) ;
if ( V_19 -> V_26 )
F_2 ( V_2 , L_10 ) ;
if ( V_19 -> V_27 )
F_2 ( V_2 , L_11 ) ;
if ( V_19 -> V_28 )
F_2 ( V_2 , L_12 ) ;
if ( V_19 -> V_29 )
F_2 ( V_2 , L_13 ) ;
if ( V_19 -> V_30 )
F_2 ( V_2 , L_14 ) ;
if ( V_19 -> V_31 )
F_2 ( V_2 , L_15 ) ;
if ( V_19 -> V_32 )
F_2 ( V_2 , L_16 ) ;
if ( V_19 -> V_33 )
F_2 ( V_2 , L_17 ) ;
F_2 ( V_2 , L_18 , F_4 ( V_19 -> V_34 ) ) ;
if ( ( V_16 & V_35 ) && V_19 -> V_36 * 4 > sizeof( struct V_17 ) ) {
V_24 V_37 [ 60 - sizeof( struct V_17 ) ] ;
const V_24 * V_38 ;
unsigned int V_39 ;
unsigned int V_40 = V_19 -> V_36 * 4 - sizeof( struct V_17 ) ;
V_38 = F_3 ( V_4 , V_7 + sizeof( struct V_17 ) ,
V_40 , V_37 ) ;
if ( V_38 == NULL ) {
F_2 ( V_2 , L_19 ) ;
return 1 ;
}
F_2 ( V_2 , L_20 ) ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ )
F_2 ( V_2 , L_21 , V_38 [ V_39 ] ) ;
F_2 ( V_2 , L_22 ) ;
}
return 0 ;
}
static void F_8 ( struct V_1 * V_2 ,
const struct V_41 * V_42 ,
const struct V_3 * V_4 ,
unsigned int V_43 )
{
struct V_44 V_45 ;
const struct V_44 * V_46 ;
unsigned int V_16 ;
if ( V_42 -> type == V_47 )
V_16 = V_42 -> V_48 . log . V_16 ;
else
V_16 = V_49 ;
V_46 = F_3 ( V_4 , V_43 , sizeof( V_45 ) , & V_45 ) ;
if ( V_46 == NULL ) {
F_2 ( V_2 , L_23 ) ;
return;
}
F_2 ( V_2 , L_24 ,
& V_46 -> V_50 , & V_46 -> V_51 ) ;
F_2 ( V_2 , L_25 ,
F_4 ( V_46 -> V_52 ) , V_46 -> V_53 & V_54 ,
V_46 -> V_53 & V_55 , V_46 -> V_56 , F_4 ( V_46 -> V_57 ) ) ;
if ( F_4 ( V_46 -> V_58 ) & V_59 )
F_2 ( V_2 , L_26 ) ;
if ( F_4 ( V_46 -> V_58 ) & V_60 )
F_2 ( V_2 , L_27 ) ;
if ( F_4 ( V_46 -> V_58 ) & V_61 )
F_2 ( V_2 , L_28 ) ;
if ( F_4 ( V_46 -> V_58 ) & V_62 )
F_2 ( V_2 , L_29 , F_4 ( V_46 -> V_58 ) & V_62 ) ;
if ( ( V_16 & V_63 ) &&
V_46 -> V_64 * 4 > sizeof( struct V_44 ) ) {
const unsigned char * V_38 ;
unsigned char V_37 [ 4 * 15 - sizeof( struct V_44 ) ] ;
unsigned int V_39 , V_40 ;
V_40 = V_46 -> V_64 * 4 - sizeof( struct V_44 ) ;
V_38 = F_3 ( V_4 , V_43 + sizeof( V_45 ) ,
V_40 , V_37 ) ;
if ( V_38 == NULL ) {
F_2 ( V_2 , L_23 ) ;
return;
}
F_2 ( V_2 , L_20 ) ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ )
F_2 ( V_2 , L_21 , V_38 [ V_39 ] ) ;
F_2 ( V_2 , L_22 ) ;
}
switch ( V_46 -> V_65 ) {
case V_66 :
if ( F_5 ( V_2 , V_4 , V_46 -> V_65 ,
F_4 ( V_46 -> V_58 ) & V_62 ,
V_43 + V_46 -> V_64 * 4 , V_16 ) )
return;
break;
case V_11 :
case V_67 :
if ( F_1 ( V_2 , V_4 , V_46 -> V_65 ,
F_4 ( V_46 -> V_58 ) & V_62 ,
V_43 + V_46 -> V_64 * 4 ) )
return;
break;
case V_68 : {
struct V_69 V_70 ;
const struct V_69 * V_71 ;
static const T_2 V_72 [ V_73 + 1 ]
= { [ V_74 ] = 4 ,
[ V_75 ]
= 8 + sizeof( struct V_44 ) ,
[ V_76 ]
= 8 + sizeof( struct V_44 ) ,
[ V_77 ]
= 8 + sizeof( struct V_44 ) ,
[ V_78 ] = 4 ,
[ V_79 ]
= 8 + sizeof( struct V_44 ) ,
[ V_80 ]
= 8 + sizeof( struct V_44 ) ,
[ V_81 ] = 20 ,
[ V_82 ] = 20 ,
[ V_83 ] = 12 ,
[ V_84 ] = 12 } ;
F_2 ( V_2 , L_30 ) ;
if ( F_4 ( V_46 -> V_58 ) & V_62 )
break;
V_71 = F_3 ( V_4 , V_43 + V_46 -> V_64 * 4 ,
sizeof( V_70 ) , & V_70 ) ;
if ( V_71 == NULL ) {
F_2 ( V_2 , L_3 ,
V_4 -> V_13 - V_43 - V_46 -> V_64 * 4 ) ;
break;
}
F_2 ( V_2 , L_31 , V_71 -> type , V_71 -> V_85 ) ;
if ( V_71 -> type <= V_73 &&
V_72 [ V_71 -> type ] &&
V_4 -> V_13 - V_43 - V_46 -> V_64 * 4 < V_72 [ V_71 -> type ] ) {
F_2 ( V_2 , L_3 ,
V_4 -> V_13 - V_43 - V_46 -> V_64 * 4 ) ;
break;
}
switch ( V_71 -> type ) {
case V_74 :
case V_78 :
F_2 ( V_2 , L_32 ,
F_4 ( V_71 -> V_86 . V_87 . V_57 ) ,
F_4 ( V_71 -> V_86 . V_87 . V_88 ) ) ;
break;
case V_80 :
F_2 ( V_2 , L_33 ,
F_6 ( V_71 -> V_86 . V_89 ) >> 24 ) ;
break;
case V_77 :
F_2 ( V_2 , L_34 , & V_71 -> V_86 . V_89 ) ;
case V_75 :
case V_76 :
case V_79 :
if ( ! V_43 ) {
F_2 ( V_2 , L_35 ) ;
F_8 ( V_2 , V_42 , V_4 ,
V_43 + V_46 -> V_64 * 4 + sizeof( V_70 ) ) ;
F_2 ( V_2 , L_36 ) ;
}
if ( V_71 -> type == V_75 &&
V_71 -> V_85 == V_90 )
F_2 ( V_2 , L_37 , F_4 ( V_71 -> V_86 . V_91 . V_92 ) ) ;
}
break;
}
case V_93 : {
struct V_94 V_95 ;
const struct V_94 * V_96 ;
if ( F_4 ( V_46 -> V_58 ) & V_62 )
break;
F_2 ( V_2 , L_38 ) ;
V_96 = F_3 ( V_4 , V_43 + V_46 -> V_64 * 4 ,
sizeof( V_95 ) , & V_95 ) ;
if ( V_96 == NULL ) {
F_2 ( V_2 , L_3 ,
V_4 -> V_13 - V_43 - V_46 -> V_64 * 4 ) ;
break;
}
F_2 ( V_2 , L_39 , F_6 ( V_96 -> V_97 ) ) ;
break;
}
case V_98 : {
struct V_99 V_100 ;
const struct V_99 * V_101 ;
F_2 ( V_2 , L_40 ) ;
if ( F_4 ( V_46 -> V_58 ) & V_62 )
break;
V_101 = F_3 ( V_4 , V_43 + V_46 -> V_64 * 4 ,
sizeof( V_100 ) , & V_100 ) ;
if ( V_101 == NULL ) {
F_2 ( V_2 , L_3 ,
V_4 -> V_13 - V_43 - V_46 -> V_64 * 4 ) ;
break;
}
F_2 ( V_2 , L_39 , F_6 ( V_101 -> V_97 ) ) ;
break;
}
default:
F_2 ( V_2 , L_41 , V_46 -> V_65 ) ;
}
if ( ( V_16 & V_102 ) && ! V_43 && V_4 -> V_103 ) {
F_9 ( & V_4 -> V_103 -> V_104 ) ;
if ( V_4 -> V_103 -> V_105 && V_4 -> V_103 -> V_105 -> V_106 )
F_2 ( V_2 , L_42 ,
V_4 -> V_103 -> V_105 -> V_106 -> V_107 -> V_108 ,
V_4 -> V_103 -> V_105 -> V_106 -> V_107 -> V_109 ) ;
F_10 ( & V_4 -> V_103 -> V_104 ) ;
}
if ( ! V_43 && V_4 -> V_110 )
F_2 ( V_2 , L_43 , V_4 -> V_110 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
const struct V_41 * V_42 ,
const struct V_3 * V_4 )
{
struct V_111 * V_112 = V_4 -> V_112 ;
unsigned int V_16 = 0 ;
if ( V_42 -> type == V_47 )
V_16 = V_42 -> V_48 . log . V_16 ;
if ( ! ( V_16 & V_113 ) )
goto V_114;
switch ( V_112 -> type ) {
case V_115 :
F_2 ( V_2 , L_44 ,
F_12 ( V_4 ) -> V_116 , F_12 ( V_4 ) -> V_117 ,
F_4 ( F_12 ( V_4 ) -> V_118 ) ) ;
return;
default:
break;
}
V_114:
F_2 ( V_2 , L_45 ) ;
if ( V_112 -> V_119 &&
V_4 -> V_120 != V_4 -> V_121 ) {
const unsigned char * V_122 = F_13 ( V_4 ) ;
unsigned int V_39 ;
F_2 ( V_2 , L_46 , * V_122 ++ ) ;
for ( V_39 = 1 ; V_39 < V_112 -> V_119 ; V_39 ++ , V_122 ++ )
F_2 ( V_2 , L_47 , * V_122 ) ;
}
F_2 ( V_2 , L_48 ) ;
}
static void
F_14 ( struct V_1 * V_2 ,
V_24 V_123 ,
unsigned int V_124 ,
const struct V_3 * V_4 ,
const struct V_111 * V_125 ,
const struct V_111 * V_12 ,
const struct V_41 * V_126 ,
const char * V_127 )
{
F_2 ( V_2 , L_49 , V_126 -> V_48 . log . V_128 ,
V_127 ,
V_125 ? V_125 -> V_129 : L_50 ,
V_12 ? V_12 -> V_129 : L_50 ) ;
#ifdef F_15
if ( V_4 -> V_130 ) {
const struct V_111 * V_131 ;
const struct V_111 * V_132 ;
V_131 = V_4 -> V_130 -> V_131 ;
if ( V_131 && V_125 != V_131 )
F_2 ( V_2 , L_51 , V_131 -> V_129 ) ;
V_132 = V_4 -> V_130 -> V_132 ;
if ( V_132 && V_12 != V_132 )
F_2 ( V_2 , L_52 , V_132 -> V_129 ) ;
}
#endif
}
static void
F_16 ( V_24 V_123 ,
unsigned int V_124 ,
const struct V_3 * V_4 ,
const struct V_111 * V_125 ,
const struct V_111 * V_12 ,
const struct V_41 * V_126 ,
const char * V_127 )
{
struct V_1 * V_2 = F_17 () ;
if ( ! V_126 )
V_126 = & V_133 ;
F_14 ( V_2 , V_123 , V_124 , V_4 , V_125 , V_12 , V_126 , V_127 ) ;
if ( V_125 != NULL )
F_11 ( V_2 , V_126 , V_4 ) ;
F_8 ( V_2 , V_126 , V_4 , 0 ) ;
F_18 ( V_2 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
const struct V_41 * V_42 ,
const struct V_3 * V_4 , unsigned int V_134 ,
int V_135 )
{
V_24 V_136 ;
int V_6 ;
struct V_137 V_138 ;
const struct V_137 * V_46 ;
unsigned int V_139 ;
unsigned int V_140 = 0 ;
unsigned int V_16 ;
if ( V_42 -> type == V_47 )
V_16 = V_42 -> V_48 . log . V_16 ;
else
V_16 = V_49 ;
V_46 = F_3 ( V_4 , V_134 , sizeof( V_138 ) , & V_138 ) ;
if ( V_46 == NULL ) {
F_2 ( V_2 , L_23 ) ;
return;
}
F_2 ( V_2 , L_53 , & V_46 -> V_50 , & V_46 -> V_51 ) ;
F_2 ( V_2 , L_54 ,
F_4 ( V_46 -> V_141 ) + sizeof( struct V_137 ) ,
( F_6 ( * ( V_142 * ) V_46 ) & 0x0ff00000 ) >> 20 ,
V_46 -> V_143 ,
( F_6 ( * ( V_142 * ) V_46 ) & 0x000fffff ) ) ;
V_6 = 0 ;
V_139 = V_134 + sizeof( struct V_137 ) ;
V_136 = V_46 -> V_144 ;
while ( V_136 != V_145 && F_20 ( V_136 ) ) {
struct V_146 V_147 ;
const struct V_146 * V_148 ;
V_148 = F_3 ( V_4 , V_139 , sizeof( V_147 ) , & V_147 ) ;
if ( V_148 == NULL ) {
F_2 ( V_2 , L_23 ) ;
return;
}
if ( V_16 & V_63 )
F_2 ( V_2 , L_55 ) ;
switch ( V_136 ) {
case V_149 : {
struct V_150 V_151 ;
const struct V_150 * V_152 ;
F_2 ( V_2 , L_56 ) ;
V_152 = F_3 ( V_4 , V_139 , sizeof( V_151 ) ,
& V_151 ) ;
if ( V_152 == NULL ) {
F_2 ( V_2 , L_57 ) ;
return;
}
F_2 ( V_2 , L_58 , F_4 ( V_152 -> V_58 ) & 0xFFF8 ) ;
if ( V_152 -> V_58 & F_21 ( 0x0001 ) )
F_2 ( V_2 , L_59 ) ;
F_2 ( V_2 , L_60 , F_6 ( V_152 -> V_153 ) ) ;
if ( F_4 ( V_152 -> V_58 ) & 0xFFF8 )
V_6 = 1 ;
V_140 = 8 ;
break;
}
case V_154 :
case V_155 :
case V_156 :
if ( V_6 ) {
if ( V_16 & V_63 )
F_2 ( V_2 , L_61 ) ;
return;
}
V_140 = F_22 ( V_148 ) ;
break;
case V_93 :
if ( V_16 & V_63 ) {
struct V_94 V_95 ;
const struct V_94 * V_96 ;
F_2 ( V_2 , L_62 ) ;
if ( V_6 ) {
F_2 ( V_2 , L_61 ) ;
return;
}
V_96 = F_3 ( V_4 , V_139 , sizeof( V_95 ) ,
& V_95 ) ;
if ( V_96 == NULL ) {
F_2 ( V_2 , L_63 ,
V_4 -> V_13 - V_139 ) ;
return;
}
F_2 ( V_2 , L_39 , F_6 ( V_96 -> V_97 ) ) ;
}
V_140 = ( V_148 -> V_140 + 2 ) << 2 ;
break;
case V_98 :
if ( V_16 & V_63 ) {
struct V_99 V_100 ;
const struct V_99 * V_101 ;
F_2 ( V_2 , L_64 ) ;
if ( V_6 ) {
F_2 ( V_2 , L_61 ) ;
return;
}
V_101 = F_3 ( V_4 , V_139 , sizeof( V_100 ) ,
& V_100 ) ;
if ( V_101 == NULL ) {
F_2 ( V_2 , L_63 ,
V_4 -> V_13 - V_139 ) ;
return;
}
F_2 ( V_2 , L_65 , F_6 ( V_101 -> V_97 ) ) ;
}
return;
default:
F_2 ( V_2 , L_66 , V_136 ) ;
return;
}
if ( V_16 & V_63 )
F_2 ( V_2 , L_22 ) ;
V_136 = V_148 -> V_144 ;
V_139 += V_140 ;
}
switch ( V_136 ) {
case V_66 :
if ( F_5 ( V_2 , V_4 , V_136 , V_6 , V_139 ,
V_16 ) )
return;
break;
case V_11 :
case V_67 :
if ( F_1 ( V_2 , V_4 , V_136 , V_6 , V_139 ) )
return;
break;
case V_157 : {
struct V_158 V_159 ;
const struct V_158 * V_160 ;
F_2 ( V_2 , L_67 ) ;
if ( V_6 )
break;
V_160 = F_3 ( V_4 , V_139 , sizeof( V_159 ) , & V_159 ) ;
if ( V_160 == NULL ) {
F_2 ( V_2 , L_3 , V_4 -> V_13 - V_139 ) ;
return;
}
F_2 ( V_2 , L_31 , V_160 -> V_161 , V_160 -> V_162 ) ;
switch ( V_160 -> V_161 ) {
case V_163 :
case V_164 :
F_2 ( V_2 , L_32 ,
F_4 ( V_160 -> V_165 ) ,
F_4 ( V_160 -> V_166 ) ) ;
break;
case V_167 :
case V_168 :
case V_169 :
break;
case V_170 :
F_2 ( V_2 , L_68 , F_6 ( V_160 -> V_171 ) ) ;
case V_172 :
case V_173 :
case V_174 :
if ( V_135 ) {
F_2 ( V_2 , L_35 ) ;
F_19 ( V_2 , V_42 , V_4 ,
V_139 + sizeof( V_159 ) , 0 ) ;
F_2 ( V_2 , L_36 ) ;
}
if ( V_160 -> V_161 == V_173 )
F_2 ( V_2 , L_37 , F_6 ( V_160 -> V_175 ) ) ;
}
break;
}
default:
F_2 ( V_2 , L_41 , V_136 ) ;
}
if ( ( V_16 & V_102 ) && V_135 && V_4 -> V_103 ) {
F_9 ( & V_4 -> V_103 -> V_104 ) ;
if ( V_4 -> V_103 -> V_105 && V_4 -> V_103 -> V_105 -> V_106 )
F_2 ( V_2 , L_42 ,
V_4 -> V_103 -> V_105 -> V_106 -> V_107 -> V_108 ,
V_4 -> V_103 -> V_105 -> V_106 -> V_107 -> V_109 ) ;
F_10 ( & V_4 -> V_103 -> V_104 ) ;
}
if ( ! V_135 && V_4 -> V_110 )
F_2 ( V_2 , L_43 , V_4 -> V_110 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
const struct V_41 * V_42 ,
const struct V_3 * V_4 )
{
struct V_111 * V_112 = V_4 -> V_112 ;
unsigned int V_16 = 0 ;
if ( V_42 -> type == V_47 )
V_16 = V_42 -> V_48 . log . V_16 ;
if ( ! ( V_16 & V_113 ) )
goto V_114;
switch ( V_112 -> type ) {
case V_115 :
F_2 ( V_2 , L_44 ,
F_12 ( V_4 ) -> V_116 , F_12 ( V_4 ) -> V_117 ,
F_4 ( F_12 ( V_4 ) -> V_118 ) ) ;
return;
default:
break;
}
V_114:
F_2 ( V_2 , L_45 ) ;
if ( V_112 -> V_119 &&
V_4 -> V_120 != V_4 -> V_121 ) {
const unsigned char * V_122 = F_13 ( V_4 ) ;
unsigned int V_13 = V_112 -> V_119 ;
unsigned int V_39 ;
if ( V_112 -> type == V_176 ) {
V_122 -= V_177 ;
if ( V_122 < V_4 -> V_178 )
V_122 = NULL ;
}
if ( V_122 != NULL ) {
F_2 ( V_2 , L_46 , * V_122 ++ ) ;
for ( V_39 = 1 ; V_39 < V_13 ; V_39 ++ )
F_2 ( V_2 , L_47 , * V_122 ++ ) ;
}
F_2 ( V_2 , L_48 ) ;
if ( V_112 -> type == V_176 ) {
const struct V_44 * V_179 =
(struct V_44 * ) F_13 ( V_4 ) ;
F_2 ( V_2 , L_69 , & V_179 -> V_50 ,
& V_179 -> V_51 ) ;
}
} else
F_2 ( V_2 , L_48 ) ;
}
static void
F_24 ( V_24 V_123 ,
unsigned int V_124 ,
const struct V_3 * V_4 ,
const struct V_111 * V_125 ,
const struct V_111 * V_12 ,
const struct V_41 * V_126 ,
const char * V_127 )
{
struct V_1 * V_2 = F_17 () ;
if ( ! V_126 )
V_126 = & V_133 ;
F_14 ( V_2 , V_123 , V_124 , V_4 , V_125 , V_12 , V_126 , V_127 ) ;
if ( V_125 != NULL )
F_23 ( V_2 , V_126 , V_4 ) ;
F_19 ( V_2 , V_126 , V_4 , F_25 ( V_4 ) , 1 ) ;
F_18 ( V_2 ) ;
}
static unsigned int
F_26 ( struct V_3 * V_4 , const struct V_180 * V_181 )
{
const struct V_182 * V_126 = V_181 -> V_183 ;
struct V_41 V_184 ;
V_184 . type = V_47 ;
V_184 . V_48 . log . V_128 = V_126 -> V_128 ;
V_184 . V_48 . log . V_16 = V_126 -> V_16 ;
if ( V_181 -> V_185 == V_186 )
F_16 ( V_186 , V_181 -> V_124 , V_4 , V_181 -> V_125 ,
V_181 -> V_12 , & V_184 , V_126 -> V_127 ) ;
#if F_27 ( V_187 )
else if ( V_181 -> V_185 == V_188 )
F_24 ( V_188 , V_181 -> V_124 , V_4 , V_181 -> V_125 ,
V_181 -> V_12 , & V_184 , V_126 -> V_127 ) ;
#endif
else
F_28 ( 1 ) ;
return V_189 ;
}
static int F_29 ( const struct V_190 * V_181 )
{
const struct V_182 * V_126 = V_181 -> V_183 ;
if ( V_181 -> V_185 != V_186 && V_181 -> V_185 != V_188 )
return - V_191 ;
if ( V_126 -> V_128 >= 8 ) {
F_30 ( L_70 , V_126 -> V_128 ) ;
return - V_191 ;
}
if ( V_126 -> V_127 [ sizeof( V_126 -> V_127 ) - 1 ] != '\0' ) {
F_30 ( L_71 ) ;
return - V_191 ;
}
return 0 ;
}
static int T_3 F_31 ( void )
{
int V_192 ;
V_192 = F_32 ( V_193 , F_33 ( V_193 ) ) ;
if ( V_192 < 0 )
return V_192 ;
F_34 ( V_186 , & V_194 ) ;
#if F_27 ( V_187 )
F_34 ( V_188 , & V_195 ) ;
#endif
return 0 ;
}
static void T_4 F_35 ( void )
{
F_36 ( & V_194 ) ;
#if F_27 ( V_187 )
F_36 ( & V_195 ) ;
#endif
F_37 ( V_193 , F_33 ( V_193 ) ) ;
}
