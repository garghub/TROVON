static void F_1 ( struct V_1 * V_2 )
{
F_2 ( ! V_2 || ! V_2 -> V_3 ) ;
V_2 -> V_3 -> V_4 ( V_2 -> V_5 ) ;
}
static int F_3 ( struct V_6 * V_7 ,
unsigned int V_8 , T_1 V_9 ,
T_2 * V_10 , T_3 V_11 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
T_3 V_18 ;
union V_19 * V_20 ;
union V_19 V_21 ;
struct V_22 * V_23 ;
T_1 * V_24 ;
unsigned int * V_25 ;
int V_26 ;
F_2 ( ! V_7 || ! V_7 -> V_23 || ! V_10 || ! V_11 ) ;
V_23 = V_7 -> V_23 ;
V_18 = sizeof( struct V_12 ) +
sizeof( struct V_14 ) ;
V_26 = V_23 -> V_27 . V_28 ( V_23 ,
V_18 / sizeof( T_2 ) ,
& V_25 ) ;
if ( V_26 != 0 ) {
F_4 ( L_1 ) ;
return V_26 ;
}
memset ( V_25 , 0 , V_18 ) ;
V_15 = (struct V_14 * ) ( V_25 ) ;
V_15 -> V_29 . V_30 = 3 ;
V_15 -> V_29 . V_31 = V_32 ;
V_15 -> V_29 . type = V_33 ;
V_20 = (union V_19 * ) & V_9 ;
V_15 -> V_34 . V_35 = V_20 -> V_36 . V_37 >> 2 ;
V_15 -> V_38 . V_39 = V_20 -> V_36 . V_40 ;
V_15 -> V_41 = ( 1 << 23 ) | ( 1 << 31 ) |
( ( V_11 / sizeof( T_2 ) ) & 0xfffff ) ;
V_15 -> V_42 . V_8 = V_8 ;
V_13 = (struct V_12 * ) ( V_25 +
( sizeof( struct V_14 ) /
sizeof( unsigned int ) ) ) ;
V_26 = F_5 ( V_7 -> V_2 , sizeof( T_1 ) ,
& V_17 ) ;
if ( V_26 != 0 ) {
F_4 ( L_2 ) ;
V_23 -> V_27 . V_43 ( V_23 ) ;
return V_26 ;
}
V_24 = ( T_1 * ) V_17 -> V_44 ;
* V_24 = V_45 ;
V_13 -> V_29 . V_31 = V_46 ;
V_13 -> V_29 . type = V_33 ;
V_13 -> V_29 . V_30 = sizeof( struct V_12 ) /
sizeof( unsigned int ) - 2 ;
V_13 -> V_34 . V_47 = V_48 ;
V_13 -> V_34 . V_49 =
V_50 ;
V_13 -> V_34 . V_51 = V_52 ;
V_13 -> V_34 . V_53 = 0 ;
V_13 -> V_34 . V_54 = 1 ;
V_21 . V_55 = V_17 -> V_56 ;
V_13 -> V_57 . V_58 = V_21 . V_36 . V_37 >> 2 ;
V_13 -> V_59 = V_21 . V_36 . V_40 ;
V_13 -> V_38 . V_60 =
V_61 ;
V_13 -> V_38 . V_62 =
V_63 ;
V_13 -> V_38 . V_64 =
V_65 ;
V_13 -> V_66 = V_67 ;
V_23 -> V_27 . V_68 ( V_23 ) ;
V_26 = F_6 (
( unsigned int * ) V_24 ,
V_67 , 1500 ) ;
F_7 ( V_7 -> V_2 , V_17 ) ;
return V_26 ;
}
static int F_8 ( struct V_6 * V_7 )
{
F_2 ( ! V_7 ) ;
V_7 -> V_23 = NULL ;
return 0 ;
}
static int F_9 ( struct V_6 * V_7 )
{
struct V_69 V_70 ;
unsigned int V_71 ;
struct V_22 * V_23 = NULL ;
int V_26 ;
F_2 ( ! V_7 || ! V_7 -> V_72 || ! V_7 -> V_2 ) ;
V_26 = F_10 ( V_7 -> V_72 , V_7 -> V_2 , NULL ,
& V_70 , 0 , V_73 ,
& V_71 ) ;
if ( V_26 ) {
F_4 ( L_3 ) ;
return V_26 ;
}
F_11 ( L_4 , V_71 ) ;
V_23 = F_12 ( V_7 -> V_72 , V_71 ) ;
if ( V_23 == NULL ) {
F_4 ( L_5 ) ;
F_13 ( V_7 -> V_72 , V_71 ) ;
return - V_74 ;
}
V_7 -> V_23 = V_23 ;
return V_26 ;
}
static int F_14 ( struct V_6 * V_7 )
{
F_2 ( ! V_7 || ! V_7 -> V_2 ) ;
F_1 ( V_7 -> V_2 ) ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 )
{
int V_26 ;
F_2 ( ! V_7 || ! V_7 -> V_72 || ! V_7 -> V_23 ) ;
V_26 = F_13 ( V_7 -> V_72 ,
V_7 -> V_23 -> V_75 -> V_70 . V_76 ) ;
V_7 -> V_23 = NULL ;
return V_26 ;
}
static void F_16 (
const struct V_77 * V_78 ,
union V_79 * V_80 ,
union V_81 * V_82 ,
union V_83 * V_84 ,
unsigned int V_85 , unsigned int V_86 )
{
union V_19 V_21 ;
F_2 ( ! V_78 || ! V_80 || ! V_82 || ! V_84 ) ;
V_21 . V_55 = 0 ;
V_80 -> V_87 = 0 ;
V_82 -> V_87 = 0 ;
V_84 -> V_87 = 0 ;
if ( V_78 -> V_88 != NULL )
V_84 -> V_89 . V_90 =
( T_2 ) ( V_78 -> V_88 [ V_85 ] &
V_91 ) ;
else
V_84 -> V_89 . V_90 = V_91 ;
V_21 . V_55 = ( unsigned long long ) V_78 -> V_92 [ V_85 ] ;
V_80 -> V_89 . V_21 = V_21 . V_36 . V_40 &
V_93 ;
V_82 -> V_89 . V_21 =
( V_21 . V_36 . V_37 >> V_94 ) ;
V_84 -> V_89 . V_95 = V_78 -> V_96 [ V_85 ] ;
V_84 -> V_89 . V_86 = ( T_2 ) V_86 ;
V_84 -> V_87 |= V_97 ;
F_11 ( L_6 , L_7 , V_84 -> V_89 . V_90 ) ;
F_11 ( L_6 , L_8 ,
V_80 -> V_89 . V_21 ) ;
F_11 ( L_6 , L_9 ,
V_82 -> V_89 . V_21 ) ;
}
static int F_17 ( struct V_6 * V_7 ,
struct V_77 * V_78 )
{
union V_79 V_80 ;
union V_81 V_82 ;
union V_83 V_84 ;
struct V_98 * V_99 ;
unsigned int V_100 ;
F_2 ( ! V_7 || ! V_7 -> V_2 || ! V_78 ) ;
V_99 = F_18 ( V_7 -> V_2 ,
V_78 -> V_101 ) ;
if ( ! V_99 ) {
F_4 ( L_10 ) ;
return - V_74 ;
}
V_80 . V_87 = 0 ;
V_82 . V_87 = 0 ;
V_84 . V_87 = 0 ;
if ( ( V_78 -> V_102 > V_103 ) ||
( V_78 -> V_102 == 0 ) ) {
F_4 ( L_11 ) ;
return - V_104 ;
}
if ( ( V_78 -> V_96 == NULL ) ||
( V_78 -> V_92 == NULL ) ) {
F_4 ( L_12 ) ;
return - V_104 ;
}
for ( V_100 = 0 ; V_100 < V_78 -> V_102 ; V_100 ++ ) {
F_16 ( V_78 , & V_80 , & V_82 ,
& V_84 , V_100 , V_99 -> V_105 . V_86 ) ;
F_11 ( L_13 , L_14 ) ;
F_11 ( L_6 , L_15 , V_100 ) ;
F_11 ( L_6 , L_16 , V_99 -> V_105 . V_86 ) ;
F_11 ( L_6 , L_17 ,
V_82 . V_89 . V_21 ) ;
F_11 ( L_6 , L_18 ,
V_80 . V_89 . V_21 ) ;
F_11 ( L_6 , L_18 ,
V_80 . V_89 . V_21 ) ;
F_11 ( L_6 , L_19 ,
V_84 . V_89 . V_90 ) ;
F_11 ( L_6 , L_20 ,
V_84 . V_89 . V_95 ) ;
F_11 ( L_6 , L_21 ,
V_84 . V_89 . V_86 ) ;
F_11 ( L_6 , L_22 ,
V_84 . V_89 . V_53 ) ;
F_11 ( L_13 , L_14 ) ;
V_99 -> V_2 -> V_3 -> V_106 (
V_7 -> V_2 -> V_5 ,
V_100 ,
V_84 . V_87 ,
V_80 . V_87 ,
V_82 . V_87 ) ;
}
return 0 ;
}
static int F_19 ( struct V_6 * V_7 ,
struct V_77 * V_78 )
{
struct V_107 * V_108 ;
union V_79 V_80 ;
union V_81 V_82 ;
union V_83 V_84 ;
struct V_16 * V_17 ;
unsigned int V_109 ;
T_2 * V_110 ;
unsigned int V_100 ;
int V_26 ;
T_3 V_111 = sizeof( struct V_107 ) * 4 ;
unsigned int V_86 = 0 ;
F_2 ( ! V_7 || ! V_7 -> V_2 || ! V_78 ) ;
V_80 . V_87 = 0 ;
V_82 . V_87 = 0 ;
V_84 . V_87 = 0 ;
if ( ( V_78 -> V_102 > V_103 ) ||
( V_78 -> V_102 == 0 ) ) {
F_4 ( L_11 ) ;
return - V_104 ;
}
if ( ( NULL == V_78 -> V_96 ) ||
( NULL == V_78 -> V_92 ) ) {
F_4 ( L_12 ) ;
return - V_104 ;
}
V_26 = F_5 ( V_7 -> V_2 , V_111 , & V_17 ) ;
if ( V_26 != 0 ) {
F_4 ( L_2 ) ;
return V_26 ;
}
V_110 = V_17 -> V_44 ;
memset ( V_110 , 0 , V_111 ) ;
V_108 = (struct V_107 * ) ( V_110 ) ;
V_108 [ 0 ] . V_29 . V_30 = 1 ;
V_108 [ 0 ] . V_29 . V_31 = V_112 ;
V_108 [ 0 ] . V_29 . type = V_33 ;
V_108 [ 0 ] . V_34 . V_113 = V_114 ;
V_108 [ 0 ] . V_34 . V_115 = 1 ;
V_108 [ 1 ] . V_116 = V_108 [ 0 ] . V_116 ;
V_108 [ 1 ] . V_34 . V_115 = 0 ;
V_108 [ 2 ] . V_116 = V_108 [ 0 ] . V_116 ;
V_108 [ 2 ] . V_34 . V_115 = 0 ;
V_108 [ 3 ] . V_116 = V_108 [ 0 ] . V_116 ;
V_108 [ 3 ] . V_34 . V_113 = V_114 ;
V_108 [ 3 ] . V_34 . V_115 = 1 ;
for ( V_100 = 0 ; V_100 < V_78 -> V_102 ; V_100 ++ ) {
F_16 ( V_78 ,
& V_80 ,
& V_82 ,
& V_84 ,
V_100 ,
V_86 ) ;
F_11 ( L_13 , L_14 ) ;
F_11 ( L_6 , L_15 , V_100 ) ;
F_11 ( L_6 , L_16 , V_86 ) ;
F_11 ( L_23 , L_24 ,
V_78 -> V_92 ) ;
F_11 ( L_25 , L_26 ,
V_78 -> V_92 [ V_100 ] ) ;
F_11 ( L_6 , L_17 ,
V_82 . V_89 . V_21 ) ;
F_11 ( L_6 , L_18 ,
V_80 . V_89 . V_21 ) ;
F_11 ( L_6 , L_19 ,
V_84 . V_89 . V_90 ) ;
F_11 ( L_6 , L_20 ,
V_84 . V_89 . V_95 ) ;
F_11 ( L_6 , L_21 ,
V_84 . V_89 . V_86 ) ;
F_11 ( L_6 , L_22 ,
V_84 . V_89 . V_53 ) ;
F_11 ( L_13 , L_14 ) ;
V_109 =
V_7 -> V_2 -> V_3 -> V_117 (
V_7 -> V_2 -> V_5 ,
V_100 ,
V_118 ) ;
V_109 /= sizeof( T_2 ) ;
V_108 [ 0 ] . V_34 . V_119 =
V_109 - V_120 ;
V_108 [ 0 ] . V_121 [ 0 ] = V_84 . V_87 ;
V_109 =
V_7 -> V_2 -> V_3 -> V_117 (
V_7 -> V_2 -> V_5 ,
V_100 ,
V_122 ) ;
V_109 /= sizeof( T_2 ) ;
V_108 [ 1 ] . V_34 . V_119 =
V_109 - V_120 ;
V_108 [ 1 ] . V_121 [ 0 ] = V_80 . V_87 ;
V_109 =
V_7 -> V_2 -> V_3 -> V_117 (
V_7 -> V_2 -> V_5 ,
V_100 ,
V_123 ) ;
V_109 /= sizeof( T_2 ) ;
V_108 [ 2 ] . V_34 . V_119 =
V_109 - V_120 ;
V_108 [ 2 ] . V_121 [ 0 ] = V_82 . V_87 ;
if ( V_78 -> V_92 [ V_100 ] > 0 )
V_84 . V_89 . V_124 = 1 ;
else
V_84 . V_89 . V_124 = 0 ;
V_109 =
V_7 -> V_2 -> V_3 -> V_117 (
V_7 -> V_2 -> V_5 ,
V_100 ,
V_118 ) ;
V_109 /= sizeof( T_2 ) ;
V_108 [ 3 ] . V_34 . V_119 =
V_109 - V_120 ;
V_108 [ 3 ] . V_121 [ 0 ] = V_84 . V_87 ;
V_26 = F_3 (
V_7 ,
V_78 -> V_101 -> V_8 ,
V_17 -> V_56 ,
V_110 ,
V_111 ) ;
if ( V_26 != 0 ) {
F_4 ( L_27 ) ;
break;
}
}
F_7 ( V_7 -> V_2 , V_17 ) ;
return V_26 ;
}
static int F_20 (
struct V_125 * V_126 ,
union V_127 * V_128 ,
union V_129 * V_130 )
{
int V_26 = 0 ;
union V_127 V_131 ;
union V_129 V_132 ;
struct V_133 * V_134 ;
F_2 ( ! V_126 || ! V_128 || ! V_130 ) ;
V_131 . V_87 = 0 ;
V_132 . V_87 = 0 ;
V_134 = & V_126 -> V_135 . V_136 . V_137 ;
switch ( V_126 -> V_95 ) {
case V_138 :
V_131 . V_139 . V_140 = 1 ;
V_131 . V_139 . V_141 = V_134 -> V_142 . V_143 ;
V_131 . V_139 . V_144 = V_134 -> V_142 . V_145 ;
V_131 . V_139 . V_95 = V_146 ;
V_132 . V_139 . V_147 = V_134 -> V_142 . V_148 ;
V_132 . V_139 . V_149 = V_134 -> V_142 . V_150 ;
V_132 . V_139 . V_151 = V_134 -> V_142 . V_152 ;
break;
case V_153 :
V_132 . V_139 . V_154 = 1 ;
V_132 . V_139 . V_155 = 1 ;
V_132 . V_139 . V_156 = 1 ;
V_131 . V_139 . V_95 = V_157 ;
break;
case V_158 :
V_131 . V_139 . V_140 = 1 ;
V_131 . V_139 . V_95 = V_157 ;
V_132 . V_139 . V_147 = V_134 -> V_142 . V_148 ;
V_132 . V_139 . V_149 = V_134 -> V_142 . V_150 ;
V_132 . V_139 . V_151 = V_134 -> V_142 . V_152 ;
break;
default:
return - V_104 ;
}
switch ( V_126 -> V_159 ) {
case V_160 :
V_131 . V_139 . V_161 = V_162 ;
break;
case V_163 :
V_131 . V_139 . V_161 = V_164 ;
break;
case V_165 :
V_131 . V_139 . V_161 = V_166 ;
break;
case V_167 :
V_131 . V_139 . V_161 = V_168 ;
break;
case V_169 :
if ( V_126 -> V_170 < V_171 ) {
V_131 . V_139 . V_161 = V_172 ;
V_131 . V_139 . V_173 = V_126 -> V_170 ;
} else {
V_26 = - V_104 ;
}
break;
default:
V_26 = - V_104 ;
break;
}
if ( V_26 == 0 ) {
* V_128 = V_131 ;
* V_130 = V_132 ;
}
return V_26 ;
}
static int F_21 ( struct V_6 * V_7 ,
struct V_125 * V_126 )
{
int V_26 ;
union V_127 V_131 ;
union V_129 V_132 ;
struct V_16 * V_17 ;
T_2 * V_110 ;
struct V_107 * V_108 ;
T_3 V_111 = sizeof( struct V_107 ) * 3 ;
F_2 ( ! V_7 || ! V_126 ) ;
V_131 . V_87 = 0 ;
V_26 = F_20 ( V_126 , & V_131 ,
& V_132 ) ;
if ( V_26 ) {
F_4 ( L_28 ) ;
return V_26 ;
}
V_131 . V_139 . V_174 = 0 ;
F_11 ( L_29 , L_14 ) ;
F_11 ( L_30 , V_126 -> V_95 ) ;
F_11 ( L_31 , V_126 -> V_159 ) ;
F_11 ( L_32 , V_126 -> V_170 ) ;
F_11 ( L_33 ,
V_126 -> V_135 . V_136 . V_137 . V_175 ) ;
F_11 ( L_34 ) ;
F_11 ( L_35 , V_131 . V_89 . V_140 ) ;
F_11 ( L_36 , V_131 . V_89 . V_161 ) ;
F_11 ( L_37 , V_131 . V_89 . V_76 ) ;
F_11 ( L_38 , V_131 . V_89 . V_141 ) ;
F_11 ( L_39 , V_131 . V_89 . V_95 ) ;
F_11 ( L_40 , V_131 . V_89 . V_174 ) ;
F_11 ( L_41 , V_131 . V_89 . V_144 ) ;
F_11 ( L_42 ,
V_132 . V_89 . V_156 ) ;
F_11 ( L_43 ,
V_132 . V_89 . V_151 ) ;
F_11 ( L_44 ,
V_132 . V_89 . V_155 ) ;
F_11 ( L_45 , V_132 . V_89 . V_149 ) ;
F_11 ( L_46 , V_132 . V_89 . V_147 ) ;
F_11 ( L_47 ,
V_132 . V_89 . V_154 ) ;
F_11 ( L_29 , L_14 ) ;
V_26 = F_5 ( V_7 -> V_2 , V_111 , & V_17 ) ;
if ( V_26 != 0 ) {
F_4 ( L_2 ) ;
return V_26 ;
}
V_110 = V_17 -> V_44 ;
memset ( V_110 , 0 , V_111 ) ;
V_108 = (struct V_107 * ) V_110 ;
V_108 [ 0 ] . V_29 . V_30 = 1 ;
V_108 [ 0 ] . V_29 . V_31 = V_176 ;
V_108 [ 0 ] . V_29 . type = V_33 ;
V_108 [ 0 ] . V_34 . V_119 =
V_177 / ( sizeof( T_2 ) ) -
V_178 ;
V_108 [ 0 ] . V_34 . V_115 = 0 ;
V_108 [ 0 ] . V_121 [ 0 ] = V_132 . V_87 ;
V_108 [ 1 ] . V_29 . V_30 = 1 ;
V_108 [ 1 ] . V_29 . V_31 = V_112 ;
V_108 [ 1 ] . V_29 . type = V_33 ;
V_108 [ 1 ] . V_34 . V_119 = V_179 / ( sizeof( T_2 ) ) -
V_120 ;
V_108 [ 1 ] . V_34 . V_113 = V_180 ;
V_108 [ 1 ] . V_34 . V_115 = 1 ;
V_108 [ 1 ] . V_121 [ 0 ] = V_131 . V_87 ;
V_132 . V_87 = 0 ;
V_132 . V_139 . V_154 = 1 ;
V_132 . V_139 . V_156 = 1 ;
V_132 . V_139 . V_155 = 1 ;
V_108 [ 2 ] . V_116 = V_108 [ 0 ] . V_116 ;
V_108 [ 2 ] . V_34 . V_119 =
V_177 / ( sizeof( T_2 ) ) -
V_178 ;
V_108 [ 2 ] . V_34 . V_115 = 0 ;
V_108 [ 2 ] . V_121 [ 0 ] = V_132 . V_87 ;
V_26 = F_3 (
V_7 ,
V_126 -> V_101 -> V_8 ,
V_17 -> V_56 ,
V_110 ,
V_111 ) ;
if ( V_26 != 0 )
F_4 ( L_27 ) ;
F_7 ( V_7 -> V_2 , V_17 ) ;
return V_26 ;
}
static int F_22 ( struct V_6 * V_7 ,
struct V_125 * V_126 )
{
int V_26 ;
union V_127 V_131 ;
union V_129 V_132 ;
struct V_98 * V_99 ;
F_2 ( ! V_7 || ! V_7 -> V_2 || ! V_126 ) ;
V_131 . V_87 = 0 ;
V_99 = F_18 ( V_7 -> V_2 , V_126 -> V_101 ) ;
if ( ! V_99 ) {
F_4 ( L_10 ) ;
return - V_74 ;
}
V_26 = F_20 ( V_126 , & V_131 ,
& V_132 ) ;
if ( V_26 ) {
F_4 ( L_28 ) ;
return V_26 ;
}
V_131 . V_139 . V_174 = V_99 -> V_105 . V_86 ;
F_11 ( L_29 , L_14 ) ;
F_11 ( L_30 , V_126 -> V_95 ) ;
F_11 ( L_31 , V_126 -> V_159 ) ;
F_11 ( L_32 , V_126 -> V_170 ) ;
F_11 ( L_33 ,
V_126 -> V_135 . V_136 . V_137 . V_175 ) ;
F_11 ( L_48 , V_99 -> V_105 . V_86 ) ;
F_11 ( L_35 , V_131 . V_89 . V_140 ) ;
F_11 ( L_36 , V_131 . V_89 . V_161 ) ;
F_11 ( L_37 , V_131 . V_89 . V_76 ) ;
F_11 ( L_38 , V_131 . V_89 . V_141 ) ;
F_11 ( L_39 , V_131 . V_89 . V_95 ) ;
F_11 ( L_40 , V_131 . V_89 . V_174 ) ;
F_11 ( L_41 , V_131 . V_89 . V_144 ) ;
F_11 ( L_42 ,
V_132 . V_89 . V_156 ) ;
F_11 ( L_43 ,
V_132 . V_89 . V_151 ) ;
F_11 ( L_44 ,
V_132 . V_89 . V_155 ) ;
F_11 ( L_45 , V_132 . V_89 . V_149 ) ;
F_11 ( L_46 , V_132 . V_89 . V_147 ) ;
F_11 ( L_47 ,
V_132 . V_89 . V_154 ) ;
F_11 ( L_29 , L_14 ) ;
return V_7 -> V_2 -> V_3 -> V_181 ( V_7 -> V_2 -> V_5 ,
V_132 . V_87 ,
V_131 . V_87 ) ;
}
int F_23 ( struct V_1 * V_2 , struct V_182 * V_183 )
{
int V_26 = 0 ;
unsigned int V_86 ;
union V_127 V_131 ;
union V_129 V_132 ;
struct V_98 * V_99 ;
struct V_125 V_126 ;
int V_184 ;
int V_185 = 8 ;
int V_186 = 15 ;
V_185 = F_24 ( V_2 -> V_187 . V_188 ) - 1 ;
V_184 = V_2 -> V_187 . V_188 >> V_185 ;
V_186 = V_185 + F_25 ( V_184 ) ;
V_131 . V_87 = 0 ;
V_26 = 0 ;
V_126 . V_95 = V_153 ;
V_126 . V_159 = V_165 ;
F_11 ( L_49 ) ;
for ( V_86 = V_185 ; V_86 <= V_186 ; V_86 ++ ) {
if ( V_2 -> V_3 -> V_189
( V_2 -> V_5 , V_86 ) ) {
if ( V_2 -> V_3 -> V_189
( V_2 -> V_5 , V_86 ) == V_183 -> V_8 ) {
F_11 ( L_50 ,
V_86 , V_183 -> V_8 ) ;
break;
}
}
}
if ( V_86 > V_186 ) {
F_4 ( L_51 , V_183 -> V_8 ) ;
return - V_74 ;
}
V_99 = F_18 ( V_2 , V_183 ) ;
if ( ! V_99 )
return - V_74 ;
V_26 = F_20 ( & V_126 , & V_131 ,
& V_132 ) ;
if ( V_26 != 0 )
return - V_104 ;
V_131 . V_139 . V_174 = V_86 ;
V_2 -> V_3 -> V_181 ( V_2 -> V_5 ,
V_132 . V_87 ,
V_131 . V_87 ) ;
return 0 ;
}
void F_26 ( struct V_6 * V_190 , struct V_1 * V_191 ,
enum V_192 type )
{
F_2 ( ! V_190 || ! V_191 ) ;
V_190 -> V_2 = V_191 ;
V_190 -> V_23 = NULL ;
V_190 -> type = type ;
V_190 -> V_72 = NULL ;
switch ( type ) {
case V_193 :
V_190 -> V_194 = F_8 ;
V_190 -> V_195 = F_14 ;
V_190 -> V_196 = F_22 ;
V_190 -> V_197 = F_17 ;
break;
case V_198 :
default:
V_190 -> V_194 = F_9 ;
V_190 -> V_195 = F_15 ;
V_190 -> V_196 = F_21 ;
V_190 -> V_197 = F_19 ;
break;
}
}
