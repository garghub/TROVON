static struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( sizeof( struct V_1 ) , V_3 ) ;
if ( ! V_2 )
return NULL ;
F_3 ( & V_2 -> V_4 ) ;
F_4 ( & V_2 -> V_5 ) ;
V_2 -> V_6 = V_7 ;
return V_2 ;
}
static struct V_8 * F_5 ( struct V_1 * V_9 ,
T_1 V_10 ,
T_1 V_11 )
{
struct V_8 * V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
unsigned long V_17 ;
V_12 = F_2 ( sizeof( struct V_8 ) , V_3 ) ;
if ( ! V_12 )
return NULL ;
F_6 ( & V_12 -> V_18 ) ;
V_14 = & V_12 -> V_19 ;
V_14 -> V_20 = V_10 ;
V_14 -> V_11 = V_11 ;
V_16 = & V_14 -> V_21 . V_22 ;
V_16 -> V_23 = F_7 ( & V_9 -> V_24 ) ;
F_8 ( & V_9 -> V_4 , V_17 ) ;
F_9 ( & V_12 -> V_25 , & V_9 -> V_5 ) ;
F_10 ( & V_9 -> V_4 , V_17 ) ;
return V_12 ;
}
static void F_11 ( struct V_1 * V_9 ,
struct V_8 * V_26 )
{
unsigned long V_17 ;
F_8 ( & V_9 -> V_4 , V_17 ) ;
F_12 ( & V_26 -> V_25 ) ;
F_10 ( & V_9 -> V_4 , V_17 ) ;
F_13 ( V_26 ) ;
}
static void F_14 ( struct V_27 * V_28 ,
struct V_13 * V_14 )
{
struct V_29 * V_30 ;
struct V_31 * V_29 ;
V_29 = F_15 ( V_28 ) ;
V_30 = V_29 -> V_32 ;
switch ( V_14 -> V_20 ) {
case V_33 :
F_16 ( V_30 , L_1
L_2
L_3
L_4 ,
V_14 -> V_11 ,
V_14 -> V_21 . V_34 . V_35 ,
V_14 -> V_21 . V_34 . V_36 ,
V_14 -> V_21 . V_34 . V_37 ,
V_14 -> V_21 . V_34 . V_38 ,
V_14 -> V_21 . V_34 . V_39 ,
V_14 -> V_21 . V_34 . V_40 ,
V_14 -> V_21 . V_34 . V_41 ) ;
break;
case V_42 :
F_16 ( V_30 , L_5
L_6
L_7
L_8 ,
V_14 -> V_11 ,
V_14 -> V_21 . V_43 . V_23 ,
V_14 -> V_21 . V_43 . V_44 ,
V_14 -> V_21 . V_43 . V_45 ,
V_14 -> V_21 . V_43 . V_46 ,
V_14 -> V_21 . V_43 . V_47 ,
V_14 -> V_21 . V_43 . V_48 ,
V_14 -> V_21 . V_43 .
V_49 ,
V_14 -> V_21 . V_43 .
V_50 ) ;
break;
case V_51 :
F_16 ( V_30 , L_9
L_10
L_11 ,
V_14 -> V_11 ,
V_14 -> V_21 . V_52 . V_23 ,
V_14 -> V_21 . V_52 . V_44 ,
V_14 -> V_21 . V_52 .
V_53 ,
V_14 -> V_21 . V_52 .
V_54 ) ;
break;
case V_55 :
F_16 ( V_30 ,
L_12 ,
V_14 -> V_11 ,
V_14 -> V_21 . V_56 . V_23 ,
V_14 -> V_21 . V_56 . V_44 ) ;
break;
case V_57 :
F_16 ( V_30 , L_13
L_14 ,
V_14 -> V_11 ,
V_14 -> V_21 . V_58 . V_44 ,
V_14 -> V_21 . V_58 . V_59 ,
V_14 -> V_21 . V_58 . V_60 ) ;
break;
default:
F_16 ( V_30 , L_15 ,
V_14 -> V_20 ,
V_14 -> V_11 ) ;
break;
}
}
static int F_17 ( struct V_1 * V_9 ,
struct V_8 * V_26 )
{
int V_61 ;
struct V_62 * V_63 ;
V_63 = & V_26 -> V_34 ;
V_63 -> V_64 = false ;
V_63 -> V_65 = V_26 -> V_19 . V_11 ;
V_63 -> V_66 = 1 ;
V_63 -> V_67 [ 0 ] . V_68 = F_18 ( & V_26 -> V_19 ) >>
V_69 ;
V_63 -> V_67 [ 0 ] . V_70 = V_26 -> V_19 . V_11 ;
V_63 -> V_67 [ 0 ] . V_71 =
( unsigned long ) & V_26 -> V_19 & ( V_72 - 1 ) ;
if ( V_63 -> V_67 [ 0 ] . V_71 + V_63 -> V_67 [ 0 ] . V_70 > V_72 ) {
V_63 -> V_66 ++ ;
V_63 -> V_67 [ 0 ] . V_70 = V_72 -
V_63 -> V_67 [ 0 ] . V_71 ;
V_63 -> V_67 [ 1 ] . V_68 = F_18 ( ( void * ) & V_26 -> V_19
+ V_63 -> V_67 [ 0 ] . V_70 ) >> V_69 ;
V_63 -> V_67 [ 1 ] . V_71 = 0 ;
V_63 -> V_67 [ 1 ] . V_70 = V_26 -> V_19 . V_11 -
V_63 -> V_67 [ 0 ] . V_70 ;
}
V_63 -> V_73 . V_74 . V_75 = NULL ;
V_61 = F_19 ( V_9 -> V_76 -> V_9 , V_63 ) ;
return V_61 ;
}
static void F_20 ( struct V_1 * V_77 ,
struct V_8 * V_12 )
{
T_1 V_78 ;
struct V_79 * V_52 ;
V_52 = & V_12 -> V_80 . V_21 . V_52 ;
if ( V_52 -> V_44 == V_81 &&
V_52 -> V_53 == sizeof( T_1 ) ) {
memcpy ( & V_78 , ( void * ) ( ( unsigned long ) V_52 +
V_52 -> V_54 ) , sizeof( T_1 ) ) ;
V_77 -> V_82 = V_78 != 0 ;
}
}
static void F_21 ( struct V_1 * V_9 ,
struct V_13 * V_83 )
{
struct V_8 * V_12 = NULL ;
bool V_84 = false ;
unsigned long V_17 ;
struct V_29 * V_32 ;
V_32 = V_9 -> V_76 -> V_32 ;
F_8 ( & V_9 -> V_4 , V_17 ) ;
F_22 (request, &dev->req_list, list_ent) {
if ( V_12 -> V_19 . V_21 . V_85 . V_23
== V_83 -> V_21 . V_43 . V_23 ) {
V_84 = true ;
break;
}
}
F_10 ( & V_9 -> V_4 , V_17 ) ;
if ( V_84 ) {
if ( V_83 -> V_11 <=
sizeof( struct V_13 ) + V_86 ) {
memcpy ( & V_12 -> V_80 , V_83 ,
V_83 -> V_11 ) ;
if ( V_12 -> V_19 . V_20 ==
V_87 && V_12 -> V_19 . V_21 .
V_88 . V_89 == V_90 )
F_20 ( V_9 , V_12 ) ;
} else {
F_23 ( V_32 ,
L_16
L_17 ,
V_83 -> V_11 ,
sizeof( struct V_13 ) ) ;
if ( V_83 -> V_20 ==
V_91 ) {
V_12 -> V_80 . V_21 . V_92 .
V_44 = V_93 ;
} else {
V_12 -> V_80 . V_21 .
V_43 . V_44 =
V_93 ;
}
}
F_24 ( & V_12 -> V_18 ) ;
} else {
F_23 ( V_32 ,
L_18
L_19 ,
V_83 -> V_21 . V_43 . V_23 ,
V_83 -> V_20 ) ;
}
}
static void F_25 ( struct V_1 * V_9 ,
struct V_13 * V_83 )
{
struct V_94 * V_95 =
& V_83 -> V_21 . V_58 ;
if ( V_95 -> V_44 == V_96 ) {
F_26 (
V_9 -> V_76 -> V_9 , 1 ) ;
} else if ( V_95 -> V_44 == V_97 ) {
F_26 (
V_9 -> V_76 -> V_9 , 0 ) ;
} else {
}
}
static inline void * F_27 ( struct V_98 * V_99 , T_1 type )
{
struct V_100 * V_101 ;
int V_70 ;
if ( V_99 -> V_40 == 0 )
return NULL ;
V_101 = (struct V_100 * ) ( ( V_102 ) V_99 +
V_99 -> V_40 ) ;
V_70 = V_99 -> V_41 ;
while ( V_70 > 0 ) {
if ( V_101 -> type == type )
return ( void * ) ( ( V_102 ) V_101 + V_101 -> V_103 ) ;
V_70 -= V_101 -> V_104 ;
V_101 = (struct V_100 * ) ( ( V_102 ) V_101 + V_101 -> V_104 ) ;
}
return NULL ;
}
static void F_28 ( struct V_1 * V_9 ,
struct V_13 * V_21 ,
struct V_62 * V_34 )
{
struct V_98 * V_105 ;
T_1 V_35 ;
struct V_106 * V_107 ;
struct V_108 * V_109 ;
V_105 = & V_21 -> V_21 . V_34 ;
V_35 = V_110 + V_105 -> V_35 ;
V_34 -> V_65 -= V_35 ;
if ( V_34 -> V_65 < V_105 -> V_36 ) {
F_23 ( V_9 -> V_76 -> V_32 , L_20
L_21
L_22 ,
V_34 -> V_65 , V_105 -> V_36 ) ;
return;
}
V_34 -> V_65 = V_105 -> V_36 ;
V_34 -> V_111 = ( void * ) ( ( unsigned long ) V_34 -> V_111 + V_35 ) ;
V_34 -> V_64 = true ;
V_107 = F_27 ( V_105 , V_112 ) ;
if ( V_107 ) {
V_34 -> V_113 = V_114 | V_107 -> V_115 |
( V_107 -> V_116 << V_117 ) ;
} else {
V_34 -> V_113 = 0 ;
}
V_109 = F_27 ( V_105 , V_118 ) ;
F_29 ( V_9 -> V_76 -> V_9 , V_34 , V_109 ) ;
}
int F_30 ( struct V_27 * V_9 ,
struct V_62 * V_34 )
{
struct V_31 * V_76 = F_15 ( V_9 ) ;
struct V_1 * V_119 ;
struct V_13 * V_14 ;
struct V_29 * V_32 ;
int V_61 = 0 ;
if ( ! V_76 ) {
V_61 = - V_120 ;
goto exit;
}
V_32 = V_76 -> V_32 ;
if ( ! V_76 -> V_121 ) {
F_23 ( V_32 , L_23
L_24 ) ;
V_61 = - V_122 ;
goto exit;
}
V_119 = (struct V_1 * ) V_76 -> V_121 ;
if ( V_119 -> V_6 == V_7 ) {
F_23 ( V_32 , L_25
L_26 ) ;
V_61 = - V_122 ;
goto exit;
}
V_14 = V_34 -> V_111 ;
F_14 ( V_9 , V_14 ) ;
switch ( V_14 -> V_20 ) {
case V_33 :
F_28 ( V_119 , V_14 , V_34 ) ;
break;
case V_42 :
case V_51 :
case V_55 :
F_21 ( V_119 , V_14 ) ;
break;
case V_57 :
F_25 ( V_119 , V_14 ) ;
break;
default:
F_23 ( V_32 ,
L_27 ,
V_14 -> V_20 ,
V_14 -> V_11 ) ;
break;
}
exit:
if ( V_61 != 0 )
V_34 -> V_44 = V_123 ;
return V_61 ;
}
static int F_31 ( struct V_1 * V_9 , T_1 V_89 ,
void * V_124 , T_1 * V_125 )
{
struct V_8 * V_12 ;
T_1 V_126 = * V_125 ;
struct V_127 * V_128 ;
struct V_79 * V_52 ;
int V_61 = 0 ;
int V_129 ;
if ( ! V_124 )
return - V_120 ;
* V_125 = 0 ;
V_12 = F_5 ( V_9 , V_87 ,
F_32 ( struct V_127 ) ) ;
if ( ! V_12 ) {
V_61 = - V_130 ;
goto V_131;
}
V_128 = & V_12 -> V_19 . V_21 . V_88 ;
V_128 -> V_89 = V_89 ;
V_128 -> V_54 = sizeof( struct V_127 ) ;
V_128 -> V_53 = 0 ;
V_128 -> V_132 = 0 ;
V_61 = F_17 ( V_9 , V_12 ) ;
if ( V_61 != 0 )
goto V_131;
V_129 = F_33 ( & V_12 -> V_18 , 5 * V_133 ) ;
if ( V_129 == 0 ) {
V_61 = - V_134 ;
goto V_131;
}
V_52 = & V_12 -> V_80 . V_21 . V_52 ;
if ( V_52 -> V_53 > V_126 ) {
V_61 = - 1 ;
goto V_131;
}
memcpy ( V_124 ,
( void * ) ( ( unsigned long ) V_52 +
V_52 -> V_54 ) ,
V_52 -> V_53 ) ;
* V_125 = V_52 -> V_53 ;
V_131:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return V_61 ;
}
static int F_34 ( struct V_1 * V_9 )
{
T_1 V_104 = V_135 ;
return F_31 ( V_9 ,
V_136 ,
V_9 -> V_137 , & V_104 ) ;
}
int F_35 ( struct V_27 * V_138 , char * V_139 )
{
struct V_31 * V_140 = F_15 ( V_138 ) ;
struct V_1 * V_77 = V_140 -> V_121 ;
struct V_29 * V_32 = V_140 -> V_32 ;
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_141 * V_142 ;
T_2 * V_143 , * V_144 ;
struct V_145 * V_56 ;
char V_146 [ 2 * V_135 + 1 ] ;
T_1 V_147 = sizeof( struct V_141 ) +
2 * V_148 + 4 * V_135 ;
int V_61 , V_129 ;
V_12 = F_5 ( V_77 , V_149 ,
F_32 ( struct V_15 ) + V_147 ) ;
if ( ! V_12 )
return - V_130 ;
V_16 = & V_12 -> V_19 . V_21 . V_22 ;
V_16 -> V_89 = V_150 ;
V_16 -> V_53 = V_147 ;
V_16 -> V_54 = sizeof( struct V_15 ) ;
V_16 -> V_132 = 0 ;
V_142 = (struct V_141 * ) ( ( V_102 ) V_16 +
V_16 -> V_54 ) ;
V_142 -> V_151 =
sizeof( struct V_141 ) ;
V_142 -> V_152 = 2 * V_148 ;
V_142 -> V_153 = V_154 ;
V_142 -> V_155 =
V_142 -> V_151 + V_142 -> V_152 ;
V_142 -> V_156 = 4 * V_135 ;
V_143 = ( T_2 * ) ( ( V_102 ) V_142 + V_142 -> V_151 ) ;
V_144 = ( T_2 * ) ( ( V_102 ) V_142 + V_142 -> V_155 ) ;
V_61 = F_36 ( V_157 , V_148 , V_158 ,
V_143 , V_148 ) ;
if ( V_61 < 0 )
goto V_131;
snprintf ( V_146 , 2 * V_135 + 1 , L_28 , V_139 ) ;
V_61 = F_36 ( V_146 , 2 * V_135 , V_158 ,
V_144 , 2 * V_135 ) ;
if ( V_61 < 0 )
goto V_131;
V_61 = F_17 ( V_77 , V_12 ) ;
if ( V_61 != 0 )
goto V_131;
V_129 = F_33 ( & V_12 -> V_18 , 5 * V_133 ) ;
if ( V_129 == 0 ) {
F_23 ( V_32 , L_29 ) ;
return - V_159 ;
} else {
V_56 = & V_12 -> V_80 . V_21 . V_56 ;
if ( V_56 -> V_44 != V_81 ) {
F_23 ( V_32 , L_30 ,
V_56 -> V_44 ) ;
V_61 = - V_120 ;
}
}
V_131:
F_11 ( V_77 , V_12 ) ;
return V_61 ;
}
int F_37 ( struct V_27 * V_138 ,
struct V_160 * V_161 )
{
struct V_31 * V_140 = F_15 ( V_138 ) ;
struct V_1 * V_77 = V_140 -> V_121 ;
struct V_29 * V_32 = V_140 -> V_32 ;
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_160 * V_162 ;
struct V_145 * V_56 ;
T_1 V_147 = sizeof( struct V_160 ) ;
int V_61 , V_129 ;
T_1 V_163 = V_140 -> V_164 ;
if ( V_163 <= V_165 ) {
V_147 = V_166 ;
V_161 -> V_167 = 0 ;
V_161 -> V_168 = 0 ;
}
V_12 = F_5 ( V_77 , V_149 ,
F_32 ( struct V_15 ) + V_147 ) ;
if ( ! V_12 )
return - V_130 ;
V_16 = & V_12 -> V_19 . V_21 . V_22 ;
V_16 -> V_89 = V_169 ;
V_16 -> V_53 = V_147 ;
V_16 -> V_54 = sizeof( struct V_15 ) ;
V_16 -> V_132 = 0 ;
V_162 = (struct V_160 * ) ( ( V_102 ) V_16 +
V_16 -> V_54 ) ;
* V_162 = * V_161 ;
V_162 -> V_170 . type = V_171 ;
V_162 -> V_170 . V_172 = V_173 ;
V_162 -> V_170 . V_104 = V_147 ;
V_61 = F_17 ( V_77 , V_12 ) ;
if ( V_61 != 0 )
goto V_131;
V_129 = F_33 ( & V_12 -> V_18 , 5 * V_133 ) ;
if ( V_129 == 0 ) {
F_23 ( V_32 , L_31 ) ;
return - V_159 ;
} else {
V_56 = & V_12 -> V_80 . V_21 . V_56 ;
if ( V_56 -> V_44 != V_81 ) {
F_23 ( V_32 , L_32 ,
V_56 -> V_44 ) ;
V_61 = - V_120 ;
}
}
V_131:
F_11 ( V_77 , V_12 ) ;
return V_61 ;
}
static int F_38 ( struct V_1 * V_9 )
{
T_1 V_104 = sizeof( T_1 ) ;
T_1 V_78 ;
int V_61 ;
V_61 = F_31 ( V_9 ,
V_90 ,
& V_78 , & V_104 ) ;
return V_61 ;
}
int F_39 ( struct V_1 * V_9 , T_1 V_174 )
{
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_145 * V_56 ;
T_1 V_44 ;
int V_61 , V_129 ;
struct V_29 * V_32 ;
V_32 = V_9 -> V_76 -> V_32 ;
V_12 = F_5 ( V_9 , V_149 ,
F_32 ( struct V_15 ) +
sizeof( T_1 ) ) ;
if ( ! V_12 ) {
V_61 = - V_130 ;
goto V_131;
}
V_16 = & V_12 -> V_19 . V_21 . V_22 ;
V_16 -> V_89 = V_175 ;
V_16 -> V_53 = sizeof( T_1 ) ;
V_16 -> V_54 = sizeof( struct V_15 ) ;
memcpy ( ( void * ) ( unsigned long ) V_16 + sizeof( struct V_15 ) ,
& V_174 , sizeof( T_1 ) ) ;
V_61 = F_17 ( V_9 , V_12 ) ;
if ( V_61 != 0 )
goto V_131;
V_129 = F_33 ( & V_12 -> V_18 , 5 * V_133 ) ;
if ( V_129 == 0 ) {
F_23 ( V_32 ,
L_29 ) ;
V_61 = - V_134 ;
goto exit;
} else {
V_56 = & V_12 -> V_80 . V_21 . V_56 ;
V_44 = V_56 -> V_44 ;
}
V_131:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
exit:
return V_61 ;
}
static int F_40 ( struct V_1 * V_9 )
{
struct V_8 * V_12 ;
struct V_176 * V_177 ;
struct V_178 * V_43 ;
T_1 V_44 ;
int V_61 , V_129 ;
V_12 = F_5 ( V_9 , V_179 ,
F_32 ( struct V_176 ) ) ;
if ( ! V_12 ) {
V_61 = - V_130 ;
goto V_131;
}
V_177 = & V_12 -> V_19 . V_21 . V_85 ;
V_177 -> V_45 = V_180 ;
V_177 -> V_46 = V_181 ;
V_177 -> V_48 = 0x4000 ;
V_9 -> V_6 = V_182 ;
V_61 = F_17 ( V_9 , V_12 ) ;
if ( V_61 != 0 ) {
V_9 -> V_6 = V_7 ;
goto V_131;
}
V_129 = F_33 ( & V_12 -> V_18 , 5 * V_133 ) ;
if ( V_129 == 0 ) {
V_61 = - V_134 ;
goto V_131;
}
V_43 = & V_12 -> V_80 . V_21 . V_43 ;
V_44 = V_43 -> V_44 ;
if ( V_44 == V_81 ) {
V_9 -> V_6 = V_183 ;
V_61 = 0 ;
} else {
V_9 -> V_6 = V_7 ;
V_61 = - V_120 ;
}
V_131:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return V_61 ;
}
static void F_41 ( struct V_1 * V_9 )
{
struct V_8 * V_12 ;
struct V_184 * V_185 ;
struct V_31 * V_140 = V_9 -> V_76 ;
struct V_27 * V_138 = V_140 -> V_9 ;
V_102 V_17 ;
V_12 = F_5 ( V_9 , V_186 ,
F_32 ( struct V_184 ) ) ;
if ( ! V_12 )
goto V_131;
V_185 = & V_12 -> V_19 . V_21 . V_187 ;
V_185 -> V_23 = F_7 ( & V_9 -> V_24 ) ;
F_17 ( V_9 , V_12 ) ;
V_9 -> V_6 = V_7 ;
V_131:
F_8 ( & V_138 -> V_188 -> V_189 , V_17 ) ;
V_140 -> V_190 = true ;
F_10 ( & V_138 -> V_188 -> V_189 , V_17 ) ;
V_18 ( V_140 -> V_191 ,
F_42 ( & V_140 -> V_192 ) == 0 ) ;
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return;
}
static int F_43 ( struct V_1 * V_9 )
{
int V_61 ;
if ( V_9 -> V_6 != V_183 )
return 0 ;
V_61 = F_39 ( V_9 ,
V_193 |
V_194 |
V_195 ) ;
if ( V_61 == 0 )
V_9 -> V_6 = V_196 ;
return V_61 ;
}
static int F_44 ( struct V_1 * V_9 )
{
int V_61 ;
if ( V_9 -> V_6 != V_196 )
return 0 ;
V_61 = F_39 ( V_9 , 0 ) ;
if ( V_61 == 0 )
V_9 -> V_6 = V_183 ;
return V_61 ;
}
int F_45 ( struct V_27 * V_9 ,
void * V_197 )
{
int V_61 ;
struct V_31 * V_29 ;
struct V_1 * V_1 ;
struct V_198 * V_199 = V_197 ;
struct V_160 V_200 ;
V_1 = F_1 () ;
if ( ! V_1 )
return - V_122 ;
V_61 = F_46 ( V_9 , V_197 ) ;
if ( V_61 != 0 ) {
F_13 ( V_1 ) ;
return V_61 ;
}
V_29 = F_15 ( V_9 ) ;
V_29 -> V_121 = V_1 ;
V_1 -> V_76 = V_29 ;
V_61 = F_40 ( V_1 ) ;
if ( V_61 != 0 ) {
F_47 ( V_9 ) ;
return V_61 ;
}
V_61 = F_34 ( V_1 ) ;
if ( V_61 != 0 ) {
F_47 ( V_9 ) ;
return V_61 ;
}
memcpy ( V_199 -> V_201 , V_1 -> V_137 , V_135 ) ;
memset ( & V_200 , 0 , sizeof( struct V_160 ) ) ;
V_200 . V_202 = V_203 ;
V_200 . V_204 = V_203 ;
V_200 . V_167 = V_203 ;
V_200 . V_205 = V_203 ;
V_200 . V_168 = V_203 ;
V_200 . V_206 = V_207 ;
V_61 = F_37 ( V_9 , & V_200 ) ;
if ( V_61 )
goto V_208;
F_38 ( V_1 ) ;
V_199 -> V_82 = V_1 -> V_82 ;
F_48 ( & V_9 -> V_2 , L_33 ,
V_1 -> V_137 ,
V_199 -> V_82 ? L_34 : L_35 ) ;
return V_61 ;
V_208:
F_47 ( V_9 ) ;
return V_61 ;
}
void F_47 ( struct V_27 * V_9 )
{
struct V_31 * V_76 = F_15 ( V_9 ) ;
struct V_1 * V_119 = V_76 -> V_121 ;
F_41 ( V_119 ) ;
F_13 ( V_119 ) ;
V_76 -> V_121 = NULL ;
F_49 ( V_9 ) ;
}
int F_50 ( struct V_27 * V_9 )
{
struct V_31 * V_29 = F_15 ( V_9 ) ;
if ( ! V_29 )
return - V_120 ;
return F_43 ( V_29 -> V_121 ) ;
}
int F_51 ( struct V_27 * V_9 )
{
struct V_31 * V_140 = F_15 ( V_9 ) ;
if ( ! V_140 )
return - V_120 ;
return F_44 ( V_140 -> V_121 ) ;
}
