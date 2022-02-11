static T_1 F_1 ( struct V_1 * V_1 , T_1 V_2 , int V_3 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
switch ( V_3 ) {
case V_9 :
break;
case V_10 :
V_2 += V_1 -> V_11 ;
break;
case V_12 :
V_2 += V_8 -> V_13 ;
break;
default:
return - V_14 ;
}
if ( V_2 >= 0 && V_2 <= V_8 -> V_13 )
return V_1 -> V_11 = V_2 ;
return - V_14 ;
}
static int F_2 ( struct V_15 * V_15 , struct V_1 * V_1 )
{
int V_16 = F_3 ( V_15 ) ;
int V_17 = V_16 >> 1 ;
int V_18 = 0 ;
struct V_7 * V_8 ;
struct V_4 * V_5 ;
struct V_15 * V_19 ;
F_4 ( V_20 , L_1 ) ;
if ( ( V_1 -> V_21 & V_22 ) && ( V_16 & 1 ) )
return - V_23 ;
F_5 ( & V_24 ) ;
V_8 = F_6 ( NULL , V_17 ) ;
if ( F_7 ( V_8 ) ) {
V_18 = F_8 ( V_8 ) ;
goto V_25;
}
if ( V_8 -> type == V_26 ) {
F_9 ( V_8 ) ;
V_18 = - V_27 ;
goto V_25;
}
V_19 = F_10 ( V_28 -> V_29 , V_17 ) ;
if ( ! V_19 ) {
F_9 ( V_8 ) ;
V_18 = - V_30 ;
goto V_25;
}
if ( V_19 -> V_31 & V_32 ) {
V_19 -> V_33 = V_8 ;
V_19 -> V_34 = V_35 ;
V_19 -> V_36 . V_37 = V_8 -> V_37 ;
F_11 ( V_19 ) ;
}
V_1 -> V_38 = V_19 -> V_39 ;
if ( ( V_1 -> V_21 & V_22 ) && ! ( V_8 -> V_40 & V_41 ) ) {
F_12 ( V_19 ) ;
F_9 ( V_8 ) ;
V_18 = - V_23 ;
goto V_25;
}
V_5 = F_13 ( sizeof( * V_5 ) , V_42 ) ;
if ( ! V_5 ) {
F_12 ( V_19 ) ;
F_9 ( V_8 ) ;
V_18 = - V_30 ;
goto V_25;
}
V_5 -> V_43 = V_19 ;
V_5 -> V_8 = V_8 ;
V_1 -> V_6 = V_5 ;
V_25:
F_14 ( & V_24 ) ;
return V_18 ;
}
static int F_15 ( struct V_15 * V_15 , struct V_1 * V_1 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
F_4 ( V_20 , L_2 ) ;
if ( ( V_1 -> V_21 & V_22 ) && V_8 -> V_44 )
V_8 -> V_44 ( V_8 ) ;
F_12 ( V_5 -> V_43 ) ;
F_9 ( V_8 ) ;
V_1 -> V_6 = NULL ;
F_16 ( V_5 ) ;
return 0 ;
}
static T_2 F_17 ( struct V_1 * V_1 , char T_3 * V_45 , T_4 V_46 , T_1 * V_47 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
T_4 V_48 = 0 ;
T_4 V_49 = 0 ;
int V_18 = 0 ;
int V_50 ;
T_4 V_13 = V_46 ;
char * V_51 ;
F_4 ( V_20 , L_3 ) ;
if ( * V_47 + V_46 > V_8 -> V_13 )
V_46 = V_8 -> V_13 - * V_47 ;
if ( ! V_46 )
return 0 ;
V_51 = F_18 ( V_8 , & V_13 ) ;
if ( ! V_51 )
return - V_30 ;
while ( V_46 ) {
V_50 = F_19 ( T_4 , V_46 , V_13 ) ;
switch ( V_5 -> V_52 ) {
case V_53 :
V_18 = V_8 -> V_54 ( V_8 , * V_47 , V_50 , & V_48 , V_51 ) ;
break;
case V_55 :
V_18 = V_8 -> V_56 ( V_8 , * V_47 , V_50 , & V_48 , V_51 ) ;
break;
case V_57 :
{
struct V_58 V_59 ;
V_59 . V_52 = V_60 ;
V_59 . V_61 = V_51 ;
V_59 . V_62 = NULL ;
V_59 . V_50 = V_50 ;
V_18 = V_8 -> V_63 ( V_8 , * V_47 , & V_59 ) ;
V_48 = V_59 . V_48 ;
break;
}
default:
V_18 = V_8 -> V_64 ( V_8 , * V_47 , V_50 , & V_48 , V_51 ) ;
}
if ( ! V_18 || ( V_18 == - V_65 ) || ( V_18 == - V_66 ) ) {
* V_47 += V_48 ;
if ( F_20 ( V_45 , V_51 , V_48 ) ) {
F_16 ( V_51 ) ;
return - V_67 ;
}
else
V_49 += V_48 ;
V_46 -= V_48 ;
V_45 += V_48 ;
if ( V_48 == 0 )
V_46 = 0 ;
}
else {
F_16 ( V_51 ) ;
return V_18 ;
}
}
F_16 ( V_51 ) ;
return V_49 ;
}
static T_2 F_21 ( struct V_1 * V_1 , const char T_3 * V_45 , T_4 V_46 , T_1 * V_47 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
T_4 V_13 = V_46 ;
char * V_51 ;
T_4 V_48 ;
T_4 V_49 = 0 ;
int V_18 = 0 ;
int V_50 ;
F_4 ( V_20 , L_4 ) ;
if ( * V_47 == V_8 -> V_13 )
return - V_68 ;
if ( * V_47 + V_46 > V_8 -> V_13 )
V_46 = V_8 -> V_13 - * V_47 ;
if ( ! V_46 )
return 0 ;
V_51 = F_18 ( V_8 , & V_13 ) ;
if ( ! V_51 )
return - V_30 ;
while ( V_46 ) {
V_50 = F_19 ( T_4 , V_46 , V_13 ) ;
if ( F_22 ( V_51 , V_45 , V_50 ) ) {
F_16 ( V_51 ) ;
return - V_67 ;
}
switch ( V_5 -> V_52 ) {
case V_53 :
V_18 = - V_69 ;
break;
case V_55 :
if ( ! V_8 -> V_70 ) {
V_18 = - V_71 ;
break;
}
V_18 = V_8 -> V_70 ( V_8 , * V_47 , V_50 , & V_48 , V_51 ) ;
break;
case V_57 :
{
struct V_58 V_59 ;
V_59 . V_52 = V_60 ;
V_59 . V_61 = V_51 ;
V_59 . V_62 = NULL ;
V_59 . V_50 = V_50 ;
V_18 = V_8 -> V_72 ( V_8 , * V_47 , & V_59 ) ;
V_48 = V_59 . V_48 ;
break;
}
default:
V_18 = ( * ( V_8 -> V_73 ) ) ( V_8 , * V_47 , V_50 , & V_48 , V_51 ) ;
}
if ( ! V_18 ) {
* V_47 += V_48 ;
V_49 += V_48 ;
V_46 -= V_48 ;
V_45 += V_48 ;
}
else {
F_16 ( V_51 ) ;
return V_18 ;
}
}
F_16 ( V_51 ) ;
return V_49 ;
}
static void F_23 ( struct V_74 * V_75 )
{
F_24 ( ( V_76 * ) V_75 -> V_77 ) ;
}
static int F_25 ( struct V_4 * V_5 , int V_52 )
{
struct V_7 * V_8 = V_5 -> V_8 ;
int V_18 = 0 ;
switch ( V_52 ) {
case V_78 :
if ( ! V_8 -> V_54 )
V_18 = - V_71 ;
else
V_5 -> V_52 = V_53 ;
break;
case V_79 :
if ( ! V_8 -> V_54 )
V_18 = - V_71 ;
else
V_5 -> V_52 = V_55 ;
break;
default:
V_18 = - V_14 ;
case V_80 :
break;
}
return V_18 ;
}
static int F_26 ( struct V_1 * V_1 , struct V_7 * V_8 ,
T_5 V_81 , T_6 V_82 , void T_3 * V_83 ,
T_6 T_3 * V_84 )
{
struct V_58 V_59 ;
T_6 V_48 ;
int V_18 = 0 ;
if ( ! ( V_1 -> V_21 & V_22 ) )
return - V_85 ;
if ( V_82 > 4096 )
return - V_14 ;
if ( ! V_8 -> V_72 )
V_18 = - V_71 ;
else
V_18 = F_27 ( V_86 , V_83 , V_82 ) ? 0 : - V_67 ;
if ( V_18 )
return V_18 ;
V_59 . V_87 = V_82 ;
V_59 . V_88 = V_81 & ( V_8 -> V_89 - 1 ) ;
V_59 . V_61 = NULL ;
V_59 . V_52 = V_90 ;
if ( V_59 . V_88 && V_59 . V_87 > ( V_8 -> V_89 - V_59 . V_88 ) )
return - V_14 ;
V_59 . V_62 = F_28 ( V_83 , V_82 ) ;
if ( F_7 ( V_59 . V_62 ) )
return F_8 ( V_59 . V_62 ) ;
V_81 &= ~ ( ( T_5 ) V_8 -> V_89 - 1 ) ;
V_18 = V_8 -> V_72 ( V_8 , V_81 , & V_59 ) ;
if ( V_59 . V_91 > 0xFFFFFFFFU )
V_18 = - V_92 ;
V_48 = V_59 . V_91 ;
if ( F_20 ( V_84 , & V_48 , sizeof( V_82 ) ) )
V_18 = - V_67 ;
F_16 ( V_59 . V_62 ) ;
return V_18 ;
}
static int F_29 ( struct V_7 * V_8 , T_5 V_81 ,
T_6 V_82 , void T_3 * V_83 , T_6 T_3 * V_84 )
{
struct V_58 V_59 ;
int V_18 = 0 ;
if ( V_82 > 4096 )
return - V_14 ;
if ( ! V_8 -> V_63 )
V_18 = - V_71 ;
else
V_18 = F_27 ( V_93 , V_83 ,
V_82 ) ? 0 : - V_67 ;
if ( V_18 )
return V_18 ;
V_59 . V_87 = V_82 ;
V_59 . V_88 = V_81 & ( V_8 -> V_89 - 1 ) ;
V_59 . V_61 = NULL ;
V_59 . V_52 = V_90 ;
if ( V_59 . V_88 && V_59 . V_87 > ( V_8 -> V_89 - V_59 . V_88 ) )
return - V_14 ;
V_59 . V_62 = F_30 ( V_82 , V_42 ) ;
if ( ! V_59 . V_62 )
return - V_30 ;
V_81 &= ~ ( ( T_5 ) V_8 -> V_89 - 1 ) ;
V_18 = V_8 -> V_63 ( V_8 , V_81 , & V_59 ) ;
if ( F_31 ( V_59 . V_91 , V_84 ) )
V_18 = - V_67 ;
else if ( V_59 . V_91 && F_20 ( V_83 , V_59 . V_62 ,
V_59 . V_91 ) )
V_18 = - V_67 ;
F_16 ( V_59 . V_62 ) ;
return V_18 ;
}
static int F_32 ( const struct V_94 * V_95 ,
struct V_96 * V_97 )
{
int V_98 ;
if ( ! V_95 || ! V_97 )
return - V_14 ;
memset ( V_97 , 0 , sizeof( * V_97 ) ) ;
V_97 -> V_99 = F_33 ( ( int ) V_95 -> V_99 , V_100 ) ;
for ( V_98 = 0 ; V_98 < V_97 -> V_99 ; V_98 ++ )
V_97 -> V_101 [ V_98 ] = V_95 -> V_101 [ V_98 ] ;
for ( V_98 = 0 ; V_98 < V_102 ; V_98 ++ ) {
if ( V_95 -> V_103 [ V_98 ] . V_82 == 0 &&
V_95 -> V_103 [ V_98 ] . V_2 == 0 )
break;
V_97 -> V_104 += V_95 -> V_103 [ V_98 ] . V_82 ;
V_97 -> V_103 [ V_98 ] = V_95 -> V_103 [ V_98 ] ;
}
return 0 ;
}
static int F_34 ( struct V_7 * V_8 ,
struct V_105 T_3 * V_106 )
{
struct V_105 V_107 ;
struct V_108 V_109 ;
if ( ! F_35 ( V_110 ) )
return - V_85 ;
if ( F_22 ( & V_107 , V_106 , sizeof( struct V_105 ) ) )
return - V_67 ;
if ( F_22 ( & V_109 , V_107 . V_111 , sizeof( struct V_108 ) ) )
return - V_67 ;
switch ( V_107 . V_112 ) {
case V_113 :
if ( F_36 ( V_8 ) )
return - V_14 ;
return F_37 ( V_8 , V_109 . V_114 , V_109 . V_81 , V_109 . V_82 ) ;
case V_115 :
if ( V_109 . V_116 < 0 )
return - V_14 ;
return F_38 ( V_8 , V_109 . V_116 ) ;
default:
return - V_14 ;
}
}
static int F_39 ( struct V_1 * V_1 , T_7 V_117 , T_8 V_106 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
void T_3 * V_118 = ( void T_3 * ) V_106 ;
int V_18 = 0 ;
T_8 V_13 ;
struct V_119 V_120 ;
F_4 ( V_20 , L_5 ) ;
V_13 = ( V_117 & V_121 ) >> V_122 ;
if ( V_117 & V_123 ) {
if ( ! F_27 ( V_86 , V_118 , V_13 ) )
return - V_67 ;
}
if ( V_117 & V_124 ) {
if ( ! F_27 ( V_93 , V_118 , V_13 ) )
return - V_67 ;
}
switch ( V_117 ) {
case V_125 :
if ( F_20 ( V_118 , & ( V_8 -> V_126 ) , sizeof( int ) ) )
return - V_67 ;
break;
case V_127 :
{
T_6 V_128 ;
struct V_129 * V_130 ;
struct V_131 T_3 * V_132 = V_118 ;
if ( F_40 ( V_128 , & ( V_132 -> V_133 ) ) )
return - V_67 ;
if ( V_128 >= V_8 -> V_126 )
return - V_14 ;
V_130 = & ( V_8 -> V_134 [ V_128 ] ) ;
if ( F_31 ( V_130 -> V_2 , & ( V_132 -> V_2 ) )
|| F_31 ( V_130 -> V_135 , & ( V_132 -> V_135 ) )
|| F_31 ( V_130 -> V_136 , & ( V_132 -> V_136 ) ) )
return - V_67 ;
break;
}
case V_137 :
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
V_120 . type = V_8 -> type ;
V_120 . V_40 = V_8 -> V_40 ;
V_120 . V_13 = V_8 -> V_13 ;
V_120 . V_135 = V_8 -> V_135 ;
V_120 . V_138 = V_8 -> V_138 ;
V_120 . V_89 = V_8 -> V_89 ;
V_120 . V_139 = - 1 ;
if ( F_20 ( V_118 , & V_120 , sizeof( struct V_119 ) ) )
return - V_67 ;
break;
case V_140 :
case V_141 :
{
struct V_74 * V_142 ;
if( ! ( V_1 -> V_21 & V_22 ) )
return - V_85 ;
V_142 = F_13 ( sizeof( struct V_74 ) , V_42 ) ;
if ( ! V_142 )
V_18 = - V_30 ;
else {
V_76 V_143 ;
F_41 ( V_144 , V_145 ) ;
F_42 ( & V_143 ) ;
if ( V_117 == V_141 ) {
struct V_146 V_147 ;
if ( F_22 ( & V_147 , V_118 ,
sizeof( struct V_146 ) ) ) {
F_16 ( V_142 ) ;
return - V_67 ;
}
V_142 -> V_148 = V_147 . V_81 ;
V_142 -> V_50 = V_147 . V_82 ;
} else {
struct V_149 V_150 ;
if ( F_22 ( & V_150 , V_118 ,
sizeof( struct V_149 ) ) ) {
F_16 ( V_142 ) ;
return - V_67 ;
}
V_142 -> V_148 = V_150 . V_81 ;
V_142 -> V_50 = V_150 . V_82 ;
}
V_142 -> V_8 = V_8 ;
V_142 -> V_151 = F_23 ;
V_142 -> V_77 = ( unsigned long ) & V_143 ;
V_18 = V_8 -> V_142 ( V_8 , V_142 ) ;
if ( ! V_18 ) {
F_43 ( V_152 ) ;
F_44 ( & V_143 , & V_144 ) ;
if ( V_142 -> V_153 != V_154 &&
V_142 -> V_153 != V_155 )
F_45 () ;
F_46 ( & V_143 , & V_144 ) ;
F_43 ( V_156 ) ;
V_18 = ( V_142 -> V_153 == V_155 ) ? - V_157 : 0 ;
}
F_16 ( V_142 ) ;
}
break;
}
case V_158 :
{
struct V_159 V_45 ;
struct V_159 T_3 * V_160 = V_118 ;
if ( F_22 ( & V_45 , V_118 , sizeof( V_45 ) ) )
V_18 = - V_67 ;
else
V_18 = F_26 ( V_1 , V_8 , V_45 . V_81 , V_45 . V_82 ,
V_45 . V_83 , & V_160 -> V_82 ) ;
break;
}
case V_161 :
{
struct V_159 V_45 ;
struct V_159 T_3 * V_160 = V_118 ;
if ( F_22 ( & V_45 , V_118 , sizeof( V_45 ) ) )
V_18 = - V_67 ;
else
V_18 = F_29 ( V_8 , V_45 . V_81 , V_45 . V_82 ,
V_45 . V_83 , & V_160 -> V_81 ) ;
break;
}
case V_162 :
{
struct V_163 V_45 ;
struct V_163 T_3 * V_160 = V_118 ;
if ( F_22 ( & V_45 , V_118 , sizeof( V_45 ) ) )
V_18 = - V_67 ;
else
V_18 = F_26 ( V_1 , V_8 , V_45 . V_81 , V_45 . V_82 ,
( void T_3 * ) ( V_164 ) V_45 . V_165 ,
& V_160 -> V_82 ) ;
break;
}
case V_166 :
{
struct V_163 V_45 ;
struct V_163 T_3 * V_160 = V_118 ;
if ( F_22 ( & V_45 , V_118 , sizeof( V_45 ) ) )
V_18 = - V_67 ;
else
V_18 = F_29 ( V_8 , V_45 . V_81 , V_45 . V_82 ,
( void T_3 * ) ( V_164 ) V_45 . V_165 ,
& V_160 -> V_82 ) ;
break;
}
case V_167 :
{
struct V_149 V_168 ;
if ( F_22 ( & V_168 , V_118 , sizeof( V_168 ) ) )
return - V_67 ;
if ( ! V_8 -> V_169 )
V_18 = - V_71 ;
else
V_18 = V_8 -> V_169 ( V_8 , V_168 . V_81 , V_168 . V_82 ) ;
break;
}
case V_170 :
{
struct V_149 V_168 ;
if ( F_22 ( & V_168 , V_118 , sizeof( V_168 ) ) )
return - V_67 ;
if ( ! V_8 -> V_171 )
V_18 = - V_71 ;
else
V_18 = V_8 -> V_171 ( V_8 , V_168 . V_81 , V_168 . V_82 ) ;
break;
}
case V_172 :
{
struct V_149 V_168 ;
if ( F_22 ( & V_168 , V_118 , sizeof( V_168 ) ) )
return - V_67 ;
if ( ! V_8 -> V_173 )
V_18 = - V_71 ;
else
V_18 = V_8 -> V_173 ( V_8 , V_168 . V_81 , V_168 . V_82 ) ;
break;
}
case V_174 :
{
struct V_175 V_176 ;
if ( ! V_8 -> V_177 )
return - V_71 ;
if ( V_8 -> V_177 -> V_99 > F_47 ( V_176 . V_101 ) )
return - V_14 ;
V_176 . V_178 = V_179 ;
memcpy ( & V_176 . V_101 , V_8 -> V_177 -> V_101 , sizeof( V_176 . V_101 ) ) ;
memcpy ( & V_176 . V_103 , V_8 -> V_177 -> V_103 ,
sizeof( V_176 . V_103 ) ) ;
V_176 . V_99 = V_8 -> V_177 -> V_99 ;
if ( F_20 ( V_118 , & V_176 , sizeof( struct V_175 ) ) )
return - V_67 ;
break;
}
case V_180 :
{
T_1 V_181 ;
if ( F_22 ( & V_181 , V_118 , sizeof( T_1 ) ) )
return - V_67 ;
if ( ! V_8 -> V_182 )
V_18 = - V_71 ;
else
return V_8 -> V_182 ( V_8 , V_181 ) ;
break;
}
case V_183 :
{
T_1 V_181 ;
if ( F_22 ( & V_181 , V_118 , sizeof( T_1 ) ) )
return - V_67 ;
if ( ! V_8 -> V_184 )
V_18 = - V_71 ;
else
return V_8 -> V_184 ( V_8 , V_181 ) ;
break;
}
#ifdef F_48
case V_185 :
{
int V_52 ;
if ( F_22 ( & V_52 , V_118 , sizeof( int ) ) )
return - V_67 ;
V_5 -> V_52 = V_186 ;
V_18 = F_25 ( V_5 , V_52 ) ;
V_1 -> V_11 = 0 ;
break;
}
case V_187 :
case V_188 :
{
struct V_189 * V_45 = F_30 ( 4096 , V_42 ) ;
if ( ! V_45 )
return - V_30 ;
V_18 = - V_71 ;
switch ( V_5 -> V_52 ) {
case V_53 :
if ( V_8 -> V_190 )
V_18 = V_8 -> V_190 ( V_8 , V_45 , 4096 ) ;
break;
case V_55 :
if ( V_8 -> V_191 )
V_18 = V_8 -> V_191 ( V_8 , V_45 , 4096 ) ;
break;
default:
break;
}
if ( V_18 >= 0 ) {
if ( V_117 == V_187 ) {
int V_192 = V_18 / sizeof( struct V_189 ) ;
V_18 = F_20 ( V_118 , & V_192 , sizeof( int ) ) ;
} else
V_18 = F_20 ( V_118 , V_45 , V_18 ) ;
if ( V_18 )
V_18 = - V_67 ;
}
F_16 ( V_45 ) ;
break;
}
case V_193 :
{
struct V_189 V_194 ;
if ( V_5 -> V_52 != V_55 )
return - V_14 ;
if ( F_22 ( & V_194 , V_118 , sizeof( V_194 ) ) )
return - V_67 ;
if ( ! V_8 -> V_195 )
return - V_71 ;
V_18 = V_8 -> V_195 ( V_8 , V_194 . V_81 , V_194 . V_82 ) ;
break;
}
#endif
case V_196 :
{
struct V_96 * V_197 ;
if ( ! V_8 -> V_177 )
return - V_71 ;
V_197 = F_30 ( sizeof( * V_197 ) , V_42 ) ;
if ( ! V_197 )
return - V_30 ;
F_32 ( V_8 -> V_177 , V_197 ) ;
if ( F_20 ( V_118 , V_197 , sizeof( * V_197 ) ) )
V_18 = - V_67 ;
F_16 ( V_197 ) ;
break;
}
case V_198 :
{
if ( F_20 ( V_118 , & V_8 -> V_199 ,
sizeof( struct V_200 ) ) )
return - V_67 ;
break;
}
case V_201 :
{
V_5 -> V_52 = 0 ;
switch( V_106 ) {
case V_53 :
case V_55 :
V_18 = F_25 ( V_5 , V_106 ) ;
break;
case V_57 :
if ( ! V_8 -> V_63 || ! V_8 -> V_72 )
return - V_71 ;
V_5 -> V_52 = V_106 ;
case V_186 :
break;
default:
V_18 = - V_14 ;
}
V_1 -> V_11 = 0 ;
break;
}
case V_202 :
{
V_18 = F_34 ( V_8 ,
(struct V_105 T_3 * ) V_106 ) ;
break;
}
case V_203 :
{
V_18 = 0 ;
break;
}
default:
V_18 = - V_204 ;
}
return V_18 ;
}
static long F_49 ( struct V_1 * V_1 , T_7 V_117 , T_8 V_106 )
{
int V_18 ;
F_5 ( & V_24 ) ;
V_18 = F_39 ( V_1 , V_117 , V_106 ) ;
F_14 ( & V_24 ) ;
return V_18 ;
}
static long F_50 ( struct V_1 * V_1 , unsigned int V_117 ,
unsigned long V_106 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
void T_3 * V_118 = F_51 ( V_106 ) ;
int V_18 = 0 ;
F_5 ( & V_24 ) ;
switch ( V_117 ) {
case V_205 :
{
struct V_206 V_45 ;
struct V_206 T_3 * V_160 = V_118 ;
if ( F_22 ( & V_45 , V_118 , sizeof( V_45 ) ) )
V_18 = - V_67 ;
else
V_18 = F_26 ( V_1 , V_8 , V_45 . V_81 ,
V_45 . V_82 , F_51 ( V_45 . V_83 ) ,
& V_160 -> V_82 ) ;
break;
}
case V_207 :
{
struct V_206 V_45 ;
struct V_206 T_3 * V_160 = V_118 ;
if ( F_22 ( & V_45 , V_118 , sizeof( V_45 ) ) )
V_18 = - V_67 ;
else
V_18 = F_29 ( V_8 , V_45 . V_81 ,
V_45 . V_82 , F_51 ( V_45 . V_83 ) ,
& V_160 -> V_81 ) ;
break;
}
default:
V_18 = F_39 ( V_1 , V_117 , ( unsigned long ) V_118 ) ;
}
F_14 ( & V_24 ) ;
return V_18 ;
}
static unsigned long F_52 ( struct V_1 * V_1 ,
unsigned long V_148 ,
unsigned long V_50 ,
unsigned long V_208 ,
unsigned long V_40 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
if ( V_8 -> V_209 ) {
unsigned long V_2 ;
if ( V_148 != 0 )
return ( unsigned long ) - V_14 ;
if ( V_50 > V_8 -> V_13 || V_208 >= ( V_8 -> V_13 >> V_210 ) )
return ( unsigned long ) - V_14 ;
V_2 = V_208 << V_210 ;
if ( V_2 > V_8 -> V_13 - V_50 )
return ( unsigned long ) - V_14 ;
return V_8 -> V_209 ( V_8 , V_50 , V_2 , V_40 ) ;
}
return ( unsigned long ) - V_211 ;
}
static int F_53 ( struct V_1 * V_1 , struct V_212 * V_213 )
{
#ifdef F_54
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
struct V_214 * V_215 = V_8 -> V_77 ;
unsigned long V_81 ;
unsigned long V_216 ;
T_9 V_50 ;
if ( V_8 -> type == V_217 || V_8 -> type == V_218 ) {
V_216 = V_213 -> V_219 << V_210 ;
V_81 = V_215 -> V_220 ;
V_50 = F_55 ( ( V_81 & ~ V_221 ) + V_215 -> V_13 ) ;
V_81 &= V_221 ;
if ( ( V_213 -> V_222 - V_213 -> V_223 + V_216 ) > V_50 )
return - V_14 ;
V_216 += V_81 ;
V_213 -> V_219 = V_216 >> V_210 ;
V_213 -> V_224 |= V_225 | V_226 ;
#ifdef F_56
if ( V_1 -> V_227 & V_228 || V_216 >= F_57 ( V_229 ) )
V_213 -> V_230 = F_56 ( V_213 -> V_230 ) ;
#endif
if ( F_58 ( V_213 , V_213 -> V_223 , V_216 >> V_210 ,
V_213 -> V_222 - V_213 -> V_223 ,
V_213 -> V_230 ) )
return - V_231 ;
return 0 ;
}
return - V_211 ;
#else
return V_213 -> V_224 & V_232 ? 0 : - V_211 ;
#endif
}
static struct V_233 * F_59 ( struct V_234 * V_235 ,
int V_40 , const char * V_236 , void * V_111 )
{
return F_60 ( V_235 , L_6 , NULL , NULL , V_237 ) ;
}
static void F_61 ( struct V_7 * V_8 )
{
}
static void F_62 ( struct V_7 * V_8 )
{
struct V_15 * V_19 = F_63 ( V_28 -> V_29 , V_8 -> V_238 ) ;
if ( V_19 ) {
V_19 -> V_239 = 0 ;
F_12 ( V_19 ) ;
}
}
static int T_10 F_64 ( void )
{
int V_18 ;
V_18 = F_65 ( V_240 , 0 , 1 << V_241 ,
L_7 , & V_242 ) ;
if ( V_18 < 0 ) {
F_66 ( L_8
L_9 , V_240 ) ;
return V_18 ;
}
V_18 = F_67 ( & V_243 ) ;
if ( V_18 ) {
F_66 ( L_10 , V_18 ) ;
goto V_244;
}
V_28 = F_68 ( & V_243 ) ;
if ( F_7 ( V_28 ) ) {
V_18 = F_8 ( V_28 ) ;
F_66 ( L_11 , V_18 ) ;
goto V_245;
}
F_69 ( & V_246 ) ;
return V_18 ;
V_245:
F_70 ( & V_243 ) ;
V_244:
F_71 ( V_240 , 0 , 1 << V_241 , L_7 ) ;
return V_18 ;
}
static void T_11 F_72 ( void )
{
F_73 ( & V_246 ) ;
F_74 ( V_28 ) ;
F_70 ( & V_243 ) ;
F_71 ( V_240 , 0 , 1 << V_241 , L_7 ) ;
}
