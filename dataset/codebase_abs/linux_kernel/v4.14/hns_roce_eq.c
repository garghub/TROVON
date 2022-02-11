static void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( ( V_2 -> V_4 & V_5 ) |
( V_3 << V_2 -> V_6 ) , V_2 -> V_7 ) ;
F_3 () ;
}
static struct V_8 * F_4 ( struct V_1 * V_2 , T_1 V_9 )
{
unsigned long V_10 = ( V_9 & ( V_2 -> V_11 - 1 ) ) *
V_12 ;
return (struct V_8 * ) ( ( V_13 * )
( V_2 -> V_14 [ V_10 / V_15 ] . V_16 ) +
V_10 % V_15 ) ;
}
static struct V_8 * F_5 ( struct V_1 * V_2 )
{
struct V_8 * V_17 = F_4 ( V_2 , V_2 -> V_4 ) ;
return ( F_6 ( V_17 -> V_18 , V_19 ) ^
! ! ( V_2 -> V_4 & V_2 -> V_11 ) ) ? V_17 : NULL ;
}
static void F_7 ( struct V_20 * V_21 ,
struct V_8 * V_17 , int V_22 )
{
struct V_23 * V_24 = & V_21 -> V_25 -> V_24 ;
F_8 ( V_24 , L_1 ) ;
switch ( F_9 ( V_17 -> V_18 , V_26 ,
V_27 ) ) {
case V_28 :
F_8 ( V_24 , L_2 , V_22 ) ;
break;
case V_29 :
F_8 ( V_24 , L_3 , V_22 ) ;
break;
case V_30 :
F_8 ( V_24 , L_4 , V_22 ) ;
break;
case V_31 :
F_8 ( V_24 , L_5 , V_22 ) ;
break;
case V_32 :
F_8 ( V_24 , L_6 , V_22 ) ;
break;
case V_33 :
F_8 ( V_24 , L_7 , V_22 ) ;
break;
case V_34 :
F_8 ( V_24 , L_8 , V_22 ) ;
break;
default:
break;
}
}
static void F_10 ( struct V_20 * V_21 ,
struct V_8 * V_17 ,
int V_22 )
{
struct V_23 * V_24 = & V_21 -> V_25 -> V_24 ;
F_8 ( V_24 , L_9 ) ;
switch ( F_9 ( V_17 -> V_18 , V_26 ,
V_27 ) ) {
case V_35 :
F_8 ( V_24 , L_10 , V_22 ) ;
break;
case V_36 :
F_8 ( V_24 , L_11 , V_22 ) ;
break;
case V_37 :
F_8 ( V_24 , L_12 , V_22 ) ;
break;
case V_38 :
F_11 ( V_24 , L_13 , V_22 ) ;
break;
case V_39 :
F_8 ( V_24 , L_14 , V_22 ) ;
break;
case V_40 :
F_8 ( V_24 , L_15 , V_22 ) ;
break;
case V_41 :
F_8 ( V_24 , L_16 , V_22 ) ;
break;
default:
break;
}
}
static void F_12 ( struct V_20 * V_21 ,
struct V_8 * V_17 ,
int V_42 )
{
struct V_23 * V_24 = & V_21 -> V_25 -> V_24 ;
int V_43 ;
int V_22 ;
V_22 = F_9 ( V_17 -> V_44 . V_45 . V_46 ,
V_47 ,
V_48 ) ;
V_43 = F_9 ( V_17 -> V_44 . V_45 . V_46 ,
V_49 ,
V_50 ) ;
if ( V_22 <= 1 )
V_22 = V_51 * V_22 + V_43 ;
switch ( V_42 ) {
case V_52 :
F_8 ( V_24 , L_17
L_18 , V_22 , V_43 ) ;
break;
case V_53 :
F_7 ( V_21 , V_17 , V_22 ) ;
break;
case V_54 :
F_10 ( V_21 , V_17 , V_22 ) ;
break;
default:
break;
}
F_13 ( V_21 , V_22 , V_42 ) ;
}
static void F_14 ( struct V_20 * V_21 ,
struct V_8 * V_17 ,
int V_42 )
{
struct V_23 * V_24 = & V_21 -> V_25 -> V_24 ;
T_1 V_55 ;
V_55 = F_15 ( F_9 ( V_17 -> V_44 . V_56 . V_57 ,
V_58 ,
V_59 ) ) ;
switch ( V_42 ) {
case V_60 :
F_8 ( V_24 , L_19 , V_55 ) ;
break;
case V_61 :
F_8 ( V_24 , L_20 , V_55 ) ;
break;
case V_62 :
F_8 ( V_24 , L_21 , V_55 ) ;
break;
default:
break;
}
F_16 ( V_21 , V_55 , V_42 ) ;
}
static void F_17 ( struct V_20 * V_21 ,
struct V_8 * V_17 )
{
struct V_23 * V_24 = & V_21 -> V_25 -> V_24 ;
switch ( F_9 ( V_17 -> V_18 , V_26 ,
V_27 ) ) {
case V_63 :
F_8 ( V_24 , L_22 ) ;
break;
case V_64 :
F_8 ( V_24 , L_23 ) ;
break;
case V_65 :
F_8 ( V_24 , L_24 ) ;
break;
case V_66 :
F_8 ( V_24 , L_25 ) ;
break;
case V_67 :
F_8 ( V_24 , L_26 ) ;
break;
case V_68 :
F_8 ( V_24 , L_24 ) ;
break;
default:
break;
}
}
static int F_18 ( struct V_20 * V_21 , struct V_1 * V_2 )
{
struct V_23 * V_24 = & V_21 -> V_25 -> V_24 ;
struct V_8 * V_17 ;
int V_69 = 0 ;
int V_42 ;
while ( ( V_17 = F_5 ( V_2 ) ) ) {
F_19 ( V_24 , L_27 , V_17 ,
F_9 ( V_17 -> V_18 ,
V_70 ,
V_71 ) ) ;
F_20 () ;
V_42 = F_9 ( V_17 -> V_18 ,
V_70 ,
V_71 ) ;
switch ( V_42 ) {
case V_72 :
F_8 ( V_24 , L_28 ) ;
break;
case V_73 :
F_8 ( V_24 , L_29 ) ;
break;
case V_74 :
F_8 ( V_24 , L_30 ) ;
break;
case V_75 :
F_8 ( V_24 , L_31 ) ;
break;
case V_52 :
case V_53 :
case V_54 :
F_12 ( V_21 , V_17 , V_42 ) ;
break;
case V_76 :
case V_77 :
case V_78 :
F_8 ( V_24 , L_32 ) ;
break;
case V_60 :
case V_61 :
case V_62 :
F_14 ( V_21 , V_17 , V_42 ) ;
break;
case V_79 :
F_8 ( V_24 , L_33 ) ;
break;
case V_80 :
F_21 ( V_21 ,
F_22 ( V_17 -> V_44 . V_81 . V_82 ) ,
V_17 -> V_44 . V_81 . V_83 ,
F_23 ( V_17 -> V_44 . V_81 . V_84
) ) ;
break;
case V_85 :
F_17 ( V_21 , V_17 ) ;
break;
case V_86 :
F_8 ( V_24 , L_34 ,
F_9 ( V_17 -> V_44 . V_87 . V_88 ,
V_89 ,
V_90 ) ) ;
break;
default:
F_8 ( V_24 , L_35 ,
V_42 , V_2 -> V_91 , V_2 -> V_4 ) ;
break;
}
V_2 -> V_4 ++ ;
V_69 = 1 ;
if ( V_2 -> V_4 > 2 * V_21 -> V_92 . V_93 - 1 ) {
F_8 ( V_24 , L_36
) ;
V_2 -> V_4 = 0 ;
}
}
F_1 ( V_2 , 0 ) ;
return V_69 ;
}
static struct V_94 * F_24 ( struct V_1 * V_2 , T_1 V_9 )
{
unsigned long V_10 = ( V_9 & ( V_2 -> V_11 - 1 ) ) *
V_95 ;
return (struct V_94 * ) ( ( V_13 * )
( V_2 -> V_14 [ V_10 / V_15 ] . V_16 ) +
V_10 % V_15 ) ;
}
static struct V_94 * F_25 ( struct V_1 * V_2 )
{
struct V_94 * V_88 = F_24 ( V_2 , V_2 -> V_4 ) ;
return ( ! ! ( F_6 ( V_88 -> V_88 . V_96 ,
V_97 ) ) ) ^
( ! ! ( V_2 -> V_4 & V_2 -> V_11 ) ) ? V_88 : NULL ;
}
static int F_26 ( struct V_20 * V_21 , struct V_1 * V_2 )
{
struct V_94 * V_88 ;
int V_98 = 0 ;
T_1 V_55 ;
while ( ( V_88 = F_25 ( V_2 ) ) ) {
F_20 () ;
V_55 = F_9 ( V_88 -> V_88 . V_96 ,
V_99 ,
V_100 ) ;
F_27 ( V_21 , V_55 ) ;
++ V_2 -> V_4 ;
V_98 = 1 ;
if ( V_2 -> V_4 > 2 * V_21 -> V_92 . V_101 [ V_2 -> V_91 ] - 1 ) {
F_8 ( & V_2 -> V_21 -> V_25 -> V_24 ,
L_36 ) ;
V_2 -> V_4 = 0 ;
}
}
F_1 ( V_2 , 0 ) ;
return V_98 ;
}
static int F_28 ( struct V_20 * V_21 ,
struct V_1 * V_2 )
{
struct V_23 * V_24 = & V_2 -> V_21 -> V_25 -> V_24 ;
int V_102 = 0 ;
T_1 V_103 ;
T_1 V_104 ;
T_1 V_105 ;
T_1 V_106 ;
T_1 V_107 ;
T_1 V_108 ;
int V_109 = 0 ;
V_106 = F_29 ( V_21 , V_110 ) ;
if ( F_6 ( V_106 ,
V_111 ) == 1 ) {
F_8 ( V_24 , L_37 ) ;
V_103 = F_29 ( V_21 , V_112 ) ;
F_30 ( V_103 ,
V_113 ,
V_114 ) ;
F_31 ( V_21 , V_112 , V_103 ) ;
V_105 = F_29 ( V_21 , V_115 ) ;
F_30 ( V_105 ,
V_116 , 1 ) ;
F_31 ( V_21 , V_115 , V_105 ) ;
V_103 = F_29 ( V_21 , V_112 ) ;
F_30 ( V_103 ,
V_113 ,
V_117 ) ;
F_31 ( V_21 , V_112 , V_103 ) ;
}
for ( V_109 = 0 ; V_109 < V_21 -> V_92 . V_118 ; V_109 ++ ) {
V_107 = F_29 ( V_21 , V_119 +
V_109 * V_120 ) ;
if ( F_6 ( V_107 ,
V_121 ) == 1 ) {
F_8 ( V_24 , L_38 , V_109 ) ;
V_102 ++ ;
V_108 = F_29 ( V_21 ,
V_122 +
V_109 * V_120 ) ;
F_30 ( V_108 ,
V_123 ,
V_114 ) ;
F_31 ( V_21 , V_122 +
V_109 * V_120 , V_108 ) ;
V_104 = F_29 ( V_21 ,
V_124 +
V_109 * V_120 ) ;
F_30 ( V_104 ,
V_125 ,
1 ) ;
F_31 ( V_21 , V_124 +
V_109 * V_120 , V_104 ) ;
V_108 = F_29 ( V_21 ,
V_122 +
V_109 * V_120 ) ;
F_30 ( V_108 ,
V_123 ,
V_117 ) ;
F_31 ( V_21 , V_122 +
V_109 * V_120 , V_108 ) ;
}
}
F_8 ( V_24 , L_39 ,
F_29 ( V_21 , V_126 ) ,
F_29 ( V_21 , V_127 ) ,
F_29 ( V_21 , V_128 ) ) ;
F_8 ( V_24 , L_40 ,
F_29 ( V_21 , V_129 ) ,
F_29 ( V_21 , V_130 ) ,
F_29 ( V_21 , V_131 ) ) ;
return V_102 ;
}
static int F_32 ( struct V_20 * V_21 , struct V_1 * V_2 )
{
int V_132 = 0 ;
if ( F_33 ( V_2 -> V_133 == V_134 ) )
V_132 = F_26 ( V_21 , V_2 ) ;
else if ( F_33 ( V_2 -> V_133 == V_135 ) )
V_132 = F_18 ( V_21 , V_2 ) ;
else
V_132 = F_28 ( V_21 , V_2 ) ;
return V_132 ;
}
static T_2 F_34 ( int V_136 , void * V_137 )
{
int V_138 = 0 ;
struct V_1 * V_2 = V_137 ;
struct V_20 * V_21 = V_2 -> V_21 ;
V_138 = F_32 ( V_21 , V_2 ) ;
return F_35 ( V_138 ) ;
}
static void F_36 ( struct V_20 * V_21 , int V_139 ,
int V_140 )
{
void T_3 * V_141 = V_21 -> V_142 . V_143 [ V_139 ] ;
T_1 V_144 ;
V_144 = F_37 ( V_141 ) ;
if ( V_140 )
F_38 ( V_144 ,
V_145 ,
V_146 ,
V_147 ) ;
else
F_38 ( V_144 ,
V_145 ,
V_146 ,
V_148 ) ;
F_39 ( V_144 , V_141 ) ;
}
static int F_40 ( struct V_20 * V_21 ,
struct V_1 * V_2 )
{
void T_3 * V_141 = V_21 -> V_142 . V_143 [ V_2 -> V_91 ] ;
struct V_23 * V_24 = & V_21 -> V_25 -> V_24 ;
T_4 V_149 ;
T_1 V_150 = 0 ;
T_1 V_151 = 0 ;
T_1 V_152 = 0 ;
int V_153 = 0 ;
int V_154 ;
int V_109 ;
V_153 = ( F_41 ( V_2 -> V_11 * V_2 -> V_155 ) +
V_15 - 1 ) / V_15 ;
if ( ( V_2 -> V_11 * V_2 -> V_155 ) > V_15 ) {
F_11 ( V_24 , L_41 ,
( V_2 -> V_11 * V_2 -> V_155 ) , V_15 ,
V_153 ) ;
return - V_156 ;
}
V_2 -> V_14 = F_42 ( V_153 , sizeof( * V_2 -> V_14 ) , V_157 ) ;
if ( ! V_2 -> V_14 )
return - V_158 ;
for ( V_109 = 0 ; V_109 < V_153 ; ++ V_109 ) {
V_2 -> V_14 [ V_109 ] . V_16 = F_43 ( V_24 , V_15 ,
& V_149 ,
V_157 ) ;
if ( ! V_2 -> V_14 [ V_109 ] . V_16 ) {
V_154 = - V_158 ;
goto V_159;
}
V_2 -> V_14 [ V_109 ] . V_160 = V_149 ;
memset ( V_2 -> V_14 [ V_109 ] . V_16 , 0 , V_15 ) ;
}
V_2 -> V_4 = 0 ;
F_38 ( V_152 ,
V_145 ,
V_146 ,
V_148 ) ;
F_38 ( V_152 ,
V_161 ,
V_162 ,
V_2 -> V_6 ) ;
F_39 ( V_152 , V_141 ) ;
F_39 ( ( T_1 ) ( V_2 -> V_14 [ 0 ] . V_160 >> 12 ) , ( V_13 * ) V_141 + 4 ) ;
F_38 ( V_151 , V_163 ,
V_164 ,
V_2 -> V_14 [ 0 ] . V_160 >> 44 ) ;
F_38 ( V_151 ,
V_165 ,
V_166 , 0 ) ;
F_39 ( V_151 , ( V_13 * ) V_141 + 8 ) ;
F_38 ( V_150 ,
V_167 ,
V_168 , 0 ) ;
F_39 ( V_150 , ( V_13 * ) V_141 + 0xc ) ;
return 0 ;
V_159:
for ( V_109 = V_109 - 1 ; V_109 >= 0 ; V_109 -- )
F_44 ( V_24 , V_15 , V_2 -> V_14 [ V_109 ] . V_16 ,
V_2 -> V_14 [ V_109 ] . V_160 ) ;
F_45 ( V_2 -> V_14 ) ;
return V_154 ;
}
static void F_46 ( struct V_20 * V_21 ,
struct V_1 * V_2 )
{
int V_109 = 0 ;
int V_169 = ( F_41 ( V_2 -> V_155 * V_2 -> V_11 ) +
V_15 - 1 ) / V_15 ;
if ( ! V_2 -> V_14 )
return;
for ( V_109 = 0 ; V_109 < V_169 ; ++ V_109 )
F_44 ( & V_21 -> V_25 -> V_24 , V_15 ,
V_2 -> V_14 [ V_109 ] . V_16 , V_2 -> V_14 [ V_109 ] . V_160 ) ;
F_45 ( V_2 -> V_14 ) ;
}
static void F_47 ( struct V_20 * V_21 )
{
int V_109 = 0 ;
T_1 V_170 ;
int V_171 = 0 ;
V_170 = F_29 ( V_21 , V_112 ) ;
F_30 ( V_170 , V_113 ,
V_171 ) ;
F_30 ( V_170 , V_172 , V_171 ) ;
F_31 ( V_21 , V_112 , V_170 ) ;
for ( V_109 = 0 ; V_109 < V_21 -> V_92 . V_118 ; V_109 ++ ) {
F_31 ( V_21 , V_122 +
V_109 * V_120 , V_171 ) ;
}
}
static void F_48 ( struct V_20 * V_21 )
{
F_31 ( V_21 , V_173 ,
V_174 ) ;
F_31 ( V_21 , V_175 ,
V_176 ) ;
}
int F_49 ( struct V_20 * V_21 )
{
struct V_177 * V_142 = & V_21 -> V_142 ;
struct V_23 * V_24 = & V_21 -> V_25 -> V_24 ;
struct V_1 * V_2 = NULL ;
int V_139 = 0 ;
int V_154 = 0 ;
int V_109 = 0 ;
int V_178 = 0 ;
V_139 = V_21 -> V_92 . V_118 + V_21 -> V_92 . V_179 ;
V_142 -> V_2 = F_42 ( V_139 , sizeof( * V_142 -> V_2 ) , V_157 ) ;
if ( ! V_142 -> V_2 )
return - V_158 ;
V_142 -> V_143 = F_42 ( V_139 , sizeof( * V_142 -> V_143 ) ,
V_157 ) ;
if ( ! V_142 -> V_143 ) {
V_154 = - V_158 ;
goto V_180;
}
for ( V_109 = 0 ; V_109 < V_139 ; V_109 ++ ) {
V_2 = & V_142 -> V_2 [ V_109 ] ;
V_2 -> V_21 = V_21 ;
V_2 -> V_91 = V_109 ;
V_2 -> V_136 = V_21 -> V_136 [ V_109 ] ;
V_2 -> V_181 = V_182 ;
if ( V_109 < V_21 -> V_92 . V_118 ) {
V_142 -> V_143 [ V_109 ] = V_21 -> V_183 +
V_119 +
V_184 * V_109 ;
V_2 -> V_133 = V_134 ;
V_2 -> V_7 = V_21 -> V_183 +
V_185 +
V_184 * V_109 ;
V_2 -> V_11 = V_21 -> V_92 . V_101 [ V_109 ] ;
V_2 -> V_6 = F_50 ( V_2 -> V_11 ) ;
V_2 -> V_155 = sizeof( struct V_94 ) ;
} else {
V_142 -> V_143 [ V_109 ] = V_21 -> V_183 +
V_110 ;
V_2 -> V_133 = V_135 ;
V_2 -> V_7 = V_21 -> V_183 +
V_186 ;
V_2 -> V_11 = V_21 -> V_92 . V_93 ;
V_2 -> V_6 = F_50 ( V_2 -> V_11 ) ;
V_2 -> V_155 = sizeof( struct V_8 ) ;
}
}
F_47 ( V_21 ) ;
F_48 ( V_21 ) ;
for ( V_109 = 0 ; V_109 < V_139 ; V_109 ++ ) {
V_154 = F_40 ( V_21 , & V_142 -> V_2 [ V_109 ] ) ;
if ( V_154 ) {
F_11 ( V_24 , L_42 ) ;
goto V_187;
}
}
for ( V_178 = 0 ; V_178 < V_139 ; V_178 ++ ) {
V_154 = F_51 ( V_142 -> V_2 [ V_178 ] . V_136 , F_34 ,
0 , V_21 -> V_188 [ V_178 ] , V_142 -> V_2 + V_178 ) ;
if ( V_154 ) {
F_11 ( V_24 , L_43 ) ;
goto V_189;
}
}
for ( V_109 = 0 ; V_109 < V_139 ; V_109 ++ )
F_36 ( V_21 , V_109 , V_190 ) ;
return 0 ;
V_189:
for ( V_178 = V_178 - 1 ; V_178 >= 0 ; V_178 -- )
F_52 ( V_142 -> V_2 [ V_178 ] . V_136 , V_142 -> V_2 + V_178 ) ;
V_187:
for ( V_109 = V_109 - 1 ; V_109 >= 0 ; V_109 -- )
F_46 ( V_21 , & V_142 -> V_2 [ V_109 ] ) ;
F_45 ( V_142 -> V_143 ) ;
V_180:
F_45 ( V_142 -> V_2 ) ;
return V_154 ;
}
void F_53 ( struct V_20 * V_21 )
{
int V_109 ;
int V_139 ;
struct V_177 * V_142 = & V_21 -> V_142 ;
V_139 = V_21 -> V_92 . V_118 + V_21 -> V_92 . V_179 ;
for ( V_109 = 0 ; V_109 < V_139 ; V_109 ++ ) {
F_36 ( V_21 , V_109 , V_191 ) ;
F_52 ( V_142 -> V_2 [ V_109 ] . V_136 , V_142 -> V_2 + V_109 ) ;
F_46 ( V_21 , & V_142 -> V_2 [ V_109 ] ) ;
}
F_45 ( V_142 -> V_143 ) ;
F_45 ( V_142 -> V_2 ) ;
}
