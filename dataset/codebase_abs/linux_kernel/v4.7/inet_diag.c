static const struct V_1 * F_1 ( int V_2 )
{
if ( ! V_3 [ V_2 ] )
F_2 ( L_1 , V_4 ,
V_5 , V_6 , V_2 ) ;
F_3 ( & V_7 ) ;
if ( ! V_3 [ V_2 ] )
return F_4 ( - V_8 ) ;
return V_3 [ V_2 ] ;
}
static void F_5 ( const struct V_1 * V_9 )
{
F_6 ( & V_7 ) ;
}
void F_7 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
V_11 -> V_14 = V_13 -> V_15 ;
V_11 -> V_16 . V_17 = F_8 ( V_13 -> V_18 ) ;
V_11 -> V_16 . V_19 = V_13 -> V_20 ;
V_11 -> V_16 . V_21 = V_13 -> V_22 ;
F_9 ( V_13 , V_11 -> V_16 . V_23 ) ;
#if F_10 ( V_24 )
if ( V_13 -> V_15 == V_25 ) {
* (struct V_26 * ) V_11 -> V_16 . V_27 = V_13 -> V_28 ;
* (struct V_26 * ) V_11 -> V_16 . V_29 = V_13 -> V_30 ;
} else
#endif
{
memset ( & V_11 -> V_16 . V_27 , 0 , sizeof( V_11 -> V_16 . V_27 ) ) ;
memset ( & V_11 -> V_16 . V_29 , 0 , sizeof( V_11 -> V_16 . V_29 ) ) ;
V_11 -> V_16 . V_27 [ 0 ] = V_13 -> V_31 ;
V_11 -> V_16 . V_29 [ 0 ] = V_13 -> V_32 ;
}
}
static T_1 F_11 ( void )
{
return F_12 ( sizeof( struct V_33 ) )
+ F_12 ( 1 )
+ F_12 ( 1 )
+ F_12 ( 1 )
+ F_12 ( sizeof( struct V_34 ) )
+ F_12 ( sizeof( struct V_10 ) )
+ F_12 ( V_35 * sizeof( V_36 ) )
+ F_12 ( V_37 )
+ F_12 ( sizeof( struct V_38 ) )
+ 64 ;
}
int F_13 ( struct V_12 * V_13 , struct V_39 * V_40 ,
struct V_10 * V_11 , int V_41 ,
struct V_42 * V_43 )
{
const struct V_44 * V_45 = F_14 ( V_13 ) ;
if ( F_15 ( V_40 , V_46 , V_13 -> V_47 ) )
goto V_48;
if ( V_41 & ( 1 << ( V_49 - 1 ) ) )
if ( F_15 ( V_40 , V_49 , V_45 -> V_50 ) < 0 )
goto V_48;
#if F_10 ( V_24 )
if ( V_11 -> V_14 == V_25 ) {
if ( V_41 & ( 1 << ( V_51 - 1 ) ) )
if ( F_15 ( V_40 , V_51 ,
F_16 ( V_13 ) -> V_52 ) < 0 )
goto V_48;
if ( ( ( 1 << V_13 -> V_53 ) & ( V_54 | V_55 ) ) &&
F_15 ( V_40 , V_56 , F_17 ( V_13 ) ) )
goto V_48;
}
#endif
V_11 -> V_57 = F_18 ( V_43 , F_19 ( V_13 ) ) ;
V_11 -> V_58 = F_20 ( V_13 ) ;
return 0 ;
V_48:
return 1 ;
}
int F_21 ( struct V_12 * V_13 , struct V_59 * V_60 ,
struct V_39 * V_40 , const struct V_61 * V_62 ,
struct V_42 * V_43 ,
V_36 V_63 , V_36 V_64 , T_2 V_65 ,
const struct V_66 * V_67 )
{
const struct V_68 * V_69 ;
const struct V_1 * V_9 ;
int V_41 = V_62 -> V_70 ;
struct V_10 * V_11 ;
struct V_66 * V_71 ;
struct V_72 * V_73 ;
void * V_74 = NULL ;
V_9 = V_3 [ V_62 -> V_75 ] ;
F_22 ( ! V_9 ) ;
V_71 = F_23 ( V_40 , V_63 , V_64 , V_67 -> V_76 , sizeof( * V_11 ) ,
V_65 ) ;
if ( ! V_71 )
return - V_77 ;
V_11 = F_24 ( V_71 ) ;
F_22 ( ! F_25 ( V_13 ) ) ;
F_7 ( V_11 , V_13 ) ;
V_11 -> V_78 = V_13 -> V_53 ;
V_11 -> V_79 = 0 ;
V_11 -> V_80 = 0 ;
if ( F_13 ( V_13 , V_40 , V_11 , V_41 , V_43 ) )
goto V_48;
if ( V_41 & ( 1 << ( V_81 - 1 ) ) ) {
struct V_34 V_82 = {
. V_83 = F_26 ( V_13 ) ,
. V_84 = V_13 -> V_85 ,
. V_86 = V_13 -> V_87 ,
. V_88 = F_27 ( V_13 ) ,
} ;
if ( F_28 ( V_40 , V_81 , sizeof( V_82 ) , & V_82 ) < 0 )
goto V_48;
}
if ( V_41 & ( 1 << ( V_89 - 1 ) ) )
if ( F_29 ( V_13 , V_40 , V_89 ) )
goto V_48;
if ( ! V_60 ) {
V_9 -> V_90 ( V_13 , V_11 , NULL ) ;
goto V_91;
}
if ( V_60 -> V_92 == V_93 ||
V_60 -> V_92 == V_94 ||
V_60 -> V_92 == V_95 ) {
V_11 -> V_79 = 1 ;
V_11 -> V_80 = V_60 -> V_96 ;
V_11 -> V_97 =
F_30 ( V_60 -> V_98 - V_99 ) ;
} else if ( V_60 -> V_92 == V_100 ) {
V_11 -> V_79 = 4 ;
V_11 -> V_80 = V_60 -> V_101 ;
V_11 -> V_97 =
F_30 ( V_60 -> V_98 - V_99 ) ;
} else if ( F_31 ( & V_13 -> V_102 ) ) {
V_11 -> V_79 = 2 ;
V_11 -> V_80 = V_60 -> V_101 ;
V_11 -> V_97 =
F_30 ( V_13 -> V_102 . V_103 - V_99 ) ;
} else {
V_11 -> V_79 = 0 ;
V_11 -> V_97 = 0 ;
}
if ( ( V_41 & ( 1 << ( V_104 - 1 ) ) ) && V_9 -> V_105 ) {
V_73 = F_32 ( V_40 , V_104 ,
V_9 -> V_105 ,
V_106 ) ;
if ( ! V_73 )
goto V_48;
V_74 = F_33 ( V_73 ) ;
}
if ( V_41 & ( 1 << ( V_107 - 1 ) ) ) {
int V_108 = 0 ;
F_34 () ;
V_69 = F_35 ( V_60 -> V_109 ) ;
if ( V_69 )
V_108 = F_36 ( V_40 , V_107 , V_69 -> V_110 ) ;
F_37 () ;
if ( V_108 < 0 )
goto V_48;
}
V_9 -> V_90 ( V_13 , V_11 , V_74 ) ;
if ( V_13 -> V_53 < V_111 ) {
union V_112 V_74 ;
T_1 V_113 = 0 ;
int V_73 ;
F_34 () ;
V_69 = F_35 ( V_60 -> V_109 ) ;
if ( V_69 && V_69 -> V_114 )
V_113 = V_69 -> V_114 ( V_13 , V_41 , & V_73 , & V_74 ) ;
F_37 () ;
if ( V_113 && F_28 ( V_40 , V_73 , V_113 , & V_74 ) < 0 )
goto V_48;
}
V_91:
F_38 ( V_40 , V_71 ) ;
return 0 ;
V_48:
F_39 ( V_40 , V_71 ) ;
return - V_77 ;
}
static int F_40 ( struct V_12 * V_13 ,
struct V_39 * V_40 ,
const struct V_61 * V_62 ,
struct V_42 * V_43 ,
V_36 V_63 , V_36 V_64 , T_2 V_65 ,
const struct V_66 * V_67 )
{
return F_21 ( V_13 , F_41 ( V_13 ) , V_40 , V_62 ,
V_43 , V_63 , V_64 , V_65 , V_67 ) ;
}
static int F_42 ( struct V_12 * V_13 ,
struct V_39 * V_40 ,
V_36 V_63 , V_36 V_64 , T_2 V_65 ,
const struct V_66 * V_67 )
{
struct V_115 * V_116 = F_43 ( V_13 ) ;
struct V_10 * V_11 ;
struct V_66 * V_71 ;
long V_117 ;
V_71 = F_23 ( V_40 , V_63 , V_64 , V_67 -> V_76 , sizeof( * V_11 ) ,
V_65 ) ;
if ( ! V_71 )
return - V_77 ;
V_11 = F_24 ( V_71 ) ;
F_22 ( V_116 -> V_118 != V_111 ) ;
V_117 = V_116 -> V_119 . V_103 - V_99 ;
if ( V_117 < 0 )
V_117 = 0 ;
F_7 ( V_11 , V_13 ) ;
V_11 -> V_80 = 0 ;
V_11 -> V_78 = V_116 -> V_120 ;
V_11 -> V_79 = 3 ;
V_11 -> V_97 = F_30 ( V_117 ) ;
V_11 -> V_121 = 0 ;
V_11 -> V_122 = 0 ;
V_11 -> V_57 = 0 ;
V_11 -> V_58 = 0 ;
F_38 ( V_40 , V_71 ) ;
return 0 ;
}
static int F_44 ( struct V_12 * V_13 , struct V_39 * V_40 ,
V_36 V_63 , V_36 V_64 , T_2 V_65 ,
const struct V_66 * V_67 )
{
struct V_10 * V_11 ;
struct V_66 * V_71 ;
long V_117 ;
V_71 = F_23 ( V_40 , V_63 , V_64 , V_67 -> V_76 , sizeof( * V_11 ) ,
V_65 ) ;
if ( ! V_71 )
return - V_77 ;
V_11 = F_24 ( V_71 ) ;
F_7 ( V_11 , V_13 ) ;
V_11 -> V_78 = V_123 ;
V_11 -> V_79 = 1 ;
V_11 -> V_80 = F_45 ( V_13 ) -> V_124 ;
F_46 ( F_47 ( struct V_125 , V_126 ) !=
F_47 ( struct V_12 , V_127 ) ) ;
V_117 = F_45 ( V_13 ) -> V_128 . V_103 - V_99 ;
V_11 -> V_97 = ( V_117 >= 0 ) ? F_30 ( V_117 ) : 0 ;
V_11 -> V_121 = 0 ;
V_11 -> V_122 = 0 ;
V_11 -> V_57 = 0 ;
V_11 -> V_58 = 0 ;
F_38 ( V_40 , V_71 ) ;
return 0 ;
}
static int F_48 ( struct V_12 * V_13 , struct V_39 * V_40 ,
const struct V_61 * V_11 ,
struct V_42 * V_43 ,
V_36 V_63 , V_36 V_64 , T_2 V_65 ,
const struct V_66 * V_67 )
{
if ( V_13 -> V_53 == V_111 )
return F_42 ( V_13 , V_40 , V_63 , V_64 ,
V_65 , V_67 ) ;
if ( V_13 -> V_53 == V_129 )
return F_44 ( V_13 , V_40 , V_63 , V_64 ,
V_65 , V_67 ) ;
return F_40 ( V_13 , V_40 , V_11 , V_43 , V_63 , V_64 ,
V_65 , V_67 ) ;
}
struct V_12 * F_49 ( struct V_130 * V_130 ,
struct V_131 * V_132 ,
const struct V_61 * V_62 )
{
struct V_12 * V_13 ;
F_34 () ;
if ( V_62 -> V_133 == V_6 )
V_13 = F_50 ( V_130 , V_132 , NULL , 0 , V_62 -> V_16 . V_29 [ 0 ] ,
V_62 -> V_16 . V_19 , V_62 -> V_16 . V_27 [ 0 ] ,
V_62 -> V_16 . V_17 , V_62 -> V_16 . V_21 ) ;
#if F_10 ( V_24 )
else if ( V_62 -> V_133 == V_25 ) {
if ( F_51 ( (struct V_26 * ) V_62 -> V_16 . V_29 ) &&
F_51 ( (struct V_26 * ) V_62 -> V_16 . V_27 ) )
V_13 = F_50 ( V_130 , V_132 , NULL , 0 , V_62 -> V_16 . V_29 [ 3 ] ,
V_62 -> V_16 . V_19 , V_62 -> V_16 . V_27 [ 3 ] ,
V_62 -> V_16 . V_17 , V_62 -> V_16 . V_21 ) ;
else
V_13 = F_52 ( V_130 , V_132 , NULL , 0 ,
(struct V_26 * ) V_62 -> V_16 . V_29 ,
V_62 -> V_16 . V_19 ,
(struct V_26 * ) V_62 -> V_16 . V_27 ,
V_62 -> V_16 . V_17 ,
V_62 -> V_16 . V_21 ) ;
}
#endif
else {
F_37 () ;
return F_4 ( - V_134 ) ;
}
F_37 () ;
if ( ! V_13 )
return F_4 ( - V_8 ) ;
if ( F_53 ( V_13 , V_62 -> V_16 . V_23 ) ) {
F_54 ( V_13 ) ;
return F_4 ( - V_8 ) ;
}
return V_13 ;
}
int F_55 ( struct V_131 * V_132 ,
struct V_39 * V_135 ,
const struct V_66 * V_71 ,
const struct V_61 * V_62 )
{
struct V_130 * V_130 = F_56 ( V_135 -> V_13 ) ;
struct V_39 * V_136 ;
struct V_12 * V_13 ;
int V_108 ;
V_13 = F_49 ( V_130 , V_132 , V_62 ) ;
if ( F_57 ( V_13 ) )
return F_58 ( V_13 ) ;
V_136 = F_59 ( F_11 () , V_137 ) ;
if ( ! V_136 ) {
V_108 = - V_138 ;
goto V_91;
}
V_108 = F_48 ( V_13 , V_136 , V_62 ,
F_60 ( F_61 ( V_135 ) . V_13 ) ,
F_61 ( V_135 ) . V_63 ,
V_71 -> V_139 , 0 , V_71 ) ;
if ( V_108 < 0 ) {
F_62 ( V_108 == - V_77 ) ;
F_63 ( V_136 ) ;
goto V_91;
}
V_108 = F_64 ( V_130 -> V_140 , V_136 , F_61 ( V_135 ) . V_63 ,
V_141 ) ;
if ( V_108 > 0 )
V_108 = 0 ;
V_91:
if ( V_13 )
F_54 ( V_13 ) ;
return V_108 ;
}
static int F_65 ( int V_142 , struct V_39 * V_135 ,
const struct V_66 * V_71 ,
const struct V_61 * V_62 )
{
const struct V_1 * V_9 ;
int V_108 ;
V_9 = F_1 ( V_62 -> V_75 ) ;
if ( F_57 ( V_9 ) )
V_108 = F_58 ( V_9 ) ;
else if ( V_142 == V_143 )
V_108 = V_9 -> V_144 ( V_135 , V_71 , V_62 ) ;
else if ( V_142 == V_145 && V_9 -> V_146 )
V_108 = V_9 -> V_146 ( V_135 , V_62 ) ;
else
V_108 = - V_147 ;
F_5 ( V_9 ) ;
return V_108 ;
}
static int F_66 ( const T_3 * V_148 , const T_3 * V_149 , int V_150 )
{
int V_151 = V_150 >> 5 ;
V_150 &= 0x1f ;
if ( V_151 ) {
if ( memcmp ( V_148 , V_149 , V_151 << 2 ) )
return 0 ;
}
if ( V_150 ) {
T_3 V_152 , V_153 ;
T_3 V_154 ;
V_152 = V_148 [ V_151 ] ;
V_153 = V_149 [ V_151 ] ;
V_154 = F_67 ( ( 0xffffffff ) << ( 32 - V_150 ) ) ;
if ( ( V_152 ^ V_153 ) & V_154 )
return 0 ;
}
return 1 ;
}
static int F_68 ( const struct V_72 * V_155 ,
const struct V_156 * V_157 )
{
const void * V_158 = F_33 ( V_155 ) ;
int V_159 = F_69 ( V_155 ) ;
while ( V_159 > 0 ) {
int V_160 = 1 ;
const struct V_161 * V_162 = V_158 ;
switch ( V_162 -> V_163 ) {
case V_164 :
break;
case V_165 :
V_160 = 0 ;
break;
case V_166 :
V_160 = V_157 -> V_167 >= V_162 [ 1 ] . V_168 ;
break;
case V_169 :
V_160 = V_157 -> V_167 <= V_162 [ 1 ] . V_168 ;
break;
case V_170 :
V_160 = V_157 -> V_171 >= V_162 [ 1 ] . V_168 ;
break;
case V_172 :
V_160 = V_157 -> V_171 <= V_162 [ 1 ] . V_168 ;
break;
case V_173 :
V_160 = ! ( V_157 -> V_174 & V_175 ) ;
break;
case V_176 :
case V_177 : {
const struct V_178 * V_179 ;
const T_3 * V_180 ;
V_179 = ( const struct V_178 * ) ( V_162 + 1 ) ;
if ( V_179 -> V_181 != - 1 &&
V_179 -> V_181 != ( V_162 -> V_163 == V_176 ?
V_157 -> V_167 : V_157 -> V_171 ) ) {
V_160 = 0 ;
break;
}
if ( V_162 -> V_163 == V_176 )
V_180 = V_157 -> V_182 ;
else
V_180 = V_157 -> V_183 ;
if ( V_179 -> V_184 != V_185 &&
V_179 -> V_184 != V_157 -> V_184 ) {
if ( V_157 -> V_184 == V_25 &&
V_179 -> V_184 == V_6 ) {
if ( V_180 [ 0 ] == 0 && V_180 [ 1 ] == 0 &&
V_180 [ 2 ] == F_67 ( 0xffff ) &&
F_66 ( V_180 + 3 ,
V_179 -> V_180 ,
V_179 -> V_186 ) )
break;
}
V_160 = 0 ;
break;
}
if ( V_179 -> V_186 == 0 )
break;
if ( F_66 ( V_180 , V_179 -> V_180 ,
V_179 -> V_186 ) )
break;
V_160 = 0 ;
break;
}
}
if ( V_160 ) {
V_159 -= V_162 -> V_160 ;
V_158 += V_162 -> V_160 ;
} else {
V_159 -= V_162 -> V_168 ;
V_158 += V_162 -> V_168 ;
}
}
return V_159 == 0 ;
}
static void F_70 ( struct V_156 * V_157 ,
const struct V_12 * V_13 )
{
#if F_10 ( V_24 )
if ( V_13 -> V_15 == V_25 ) {
V_157 -> V_182 = V_13 -> V_28 . V_187 ;
V_157 -> V_183 = V_13 -> V_30 . V_187 ;
} else
#endif
{
V_157 -> V_182 = & V_13 -> V_31 ;
V_157 -> V_183 = & V_13 -> V_32 ;
}
}
int F_71 ( const struct V_72 * V_158 , struct V_12 * V_13 )
{
struct V_44 * V_45 = F_14 ( V_13 ) ;
struct V_156 V_157 ;
if ( ! V_158 )
return 1 ;
V_157 . V_184 = V_13 -> V_15 ;
F_70 ( & V_157 , V_13 ) ;
V_157 . V_167 = V_45 -> V_188 ;
V_157 . V_171 = F_72 ( V_45 -> V_189 ) ;
V_157 . V_174 = F_25 ( V_13 ) ? V_13 -> V_190 : 0 ;
return F_68 ( V_158 , & V_157 ) ;
}
static int F_73 ( const void * V_158 , int V_159 , int V_191 )
{
while ( V_159 >= 0 ) {
const struct V_161 * V_162 = V_158 ;
if ( V_191 > V_159 )
return 0 ;
if ( V_191 == V_159 )
return 1 ;
if ( V_162 -> V_160 < 4 || V_162 -> V_160 & 3 )
return 0 ;
V_159 -= V_162 -> V_160 ;
V_158 += V_162 -> V_160 ;
}
return 0 ;
}
static bool F_74 ( const struct V_161 * V_162 , int V_159 ,
int * V_192 )
{
struct V_178 * V_179 ;
int V_193 ;
* V_192 += sizeof( struct V_178 ) ;
if ( V_159 < * V_192 )
return false ;
V_179 = (struct V_178 * ) ( V_162 + 1 ) ;
switch ( V_179 -> V_184 ) {
case V_185 :
V_193 = 0 ;
break;
case V_6 :
V_193 = sizeof( struct V_194 ) ;
break;
case V_25 :
V_193 = sizeof( struct V_26 ) ;
break;
default:
return false ;
}
* V_192 += V_193 ;
if ( V_159 < * V_192 )
return false ;
if ( V_179 -> V_186 > 8 * V_193 )
return false ;
return true ;
}
static bool F_75 ( const struct V_161 * V_162 ,
int V_159 , int * V_192 )
{
* V_192 += sizeof( struct V_161 ) ;
if ( V_159 < * V_192 )
return false ;
return true ;
}
static int F_76 ( const void * V_195 , int V_196 )
{
const void * V_158 = V_195 ;
int V_159 = V_196 ;
while ( V_159 > 0 ) {
int V_192 = sizeof( struct V_161 ) ;
const struct V_161 * V_162 = V_158 ;
switch ( V_162 -> V_163 ) {
case V_176 :
case V_177 :
if ( ! F_74 ( V_158 , V_159 , & V_192 ) )
return - V_134 ;
break;
case V_166 :
case V_169 :
case V_170 :
case V_172 :
if ( ! F_75 ( V_158 , V_159 , & V_192 ) )
return - V_134 ;
break;
case V_173 :
case V_165 :
case V_164 :
break;
default:
return - V_134 ;
}
if ( V_162 -> V_163 != V_164 ) {
if ( V_162 -> V_168 < V_192 || V_162 -> V_168 > V_159 + 4 || V_162 -> V_168 & 3 )
return - V_134 ;
if ( V_162 -> V_168 < V_159 &&
! F_73 ( V_195 , V_196 , V_159 - V_162 -> V_168 ) )
return - V_134 ;
}
if ( V_162 -> V_160 < V_192 || V_162 -> V_160 > V_159 + 4 || V_162 -> V_160 & 3 )
return - V_134 ;
V_158 += V_162 -> V_160 ;
V_159 -= V_162 -> V_160 ;
}
return V_159 == 0 ? 0 : - V_134 ;
}
static int F_77 ( struct V_12 * V_13 ,
struct V_39 * V_40 ,
struct V_197 * V_198 ,
const struct V_61 * V_11 ,
const struct V_72 * V_158 )
{
if ( ! F_71 ( V_158 , V_13 ) )
return 0 ;
return F_40 ( V_13 , V_40 , V_11 ,
F_60 ( F_61 ( V_198 -> V_40 ) . V_13 ) ,
F_61 ( V_198 -> V_40 ) . V_63 ,
V_198 -> V_71 -> V_139 , V_199 , V_198 -> V_71 ) ;
}
static void F_78 ( void )
{
F_46 ( F_47 ( struct V_115 , V_200 ) !=
F_47 ( struct V_12 , V_15 ) ) ;
F_46 ( F_47 ( struct V_115 , V_201 ) !=
F_47 ( struct V_44 , V_188 ) ) ;
F_46 ( F_47 ( struct V_115 , V_202 ) !=
F_47 ( struct V_44 , V_189 ) ) ;
F_46 ( F_47 ( struct V_115 , V_203 ) !=
F_47 ( struct V_44 , V_204 ) ) ;
F_46 ( F_47 ( struct V_115 , V_205 ) !=
F_47 ( struct V_44 , V_206 ) ) ;
#if F_10 ( V_24 )
F_46 ( F_47 ( struct V_115 , V_207 ) !=
F_47 ( struct V_12 , V_28 ) ) ;
F_46 ( F_47 ( struct V_115 , V_208 ) !=
F_47 ( struct V_12 , V_30 ) ) ;
#endif
}
void F_79 ( struct V_131 * V_132 , struct V_39 * V_40 ,
struct V_197 * V_198 ,
const struct V_61 * V_11 , struct V_72 * V_158 )
{
struct V_130 * V_130 = F_56 ( V_40 -> V_13 ) ;
int V_209 , V_210 , V_211 , V_212 ;
V_36 V_213 = V_11 -> V_213 ;
if ( V_213 & V_214 )
V_213 |= V_215 ;
V_211 = V_198 -> args [ 1 ] ;
V_212 = V_210 = V_198 -> args [ 2 ] ;
if ( V_198 -> args [ 0 ] == 0 ) {
if ( ! ( V_213 & V_54 ) )
goto V_216;
for ( V_209 = V_211 ; V_209 < V_217 ; V_209 ++ ) {
struct V_218 * V_219 ;
struct V_12 * V_13 ;
V_210 = 0 ;
V_219 = & V_132 -> V_220 [ V_209 ] ;
F_80 ( & V_219 -> V_221 ) ;
F_81 (sk, &ilb->head) {
struct V_44 * V_45 = F_14 ( V_13 ) ;
if ( ! F_82 ( F_56 ( V_13 ) , V_130 ) )
continue;
if ( V_210 < V_212 ) {
V_210 ++ ;
continue;
}
if ( V_11 -> V_133 != V_185 &&
V_13 -> V_15 != V_11 -> V_133 )
goto V_222;
if ( V_11 -> V_16 . V_17 != V_45 -> V_223 &&
V_11 -> V_16 . V_17 )
goto V_222;
if ( V_11 -> V_16 . V_19 ||
V_198 -> args [ 3 ] > 0 )
goto V_222;
if ( F_77 ( V_13 , V_40 , V_198 , V_11 , V_158 ) < 0 ) {
F_83 ( & V_219 -> V_221 ) ;
goto V_224;
}
V_222:
V_198 -> args [ 3 ] = 0 ;
V_198 -> args [ 4 ] = 0 ;
++ V_210 ;
}
F_83 ( & V_219 -> V_221 ) ;
V_212 = 0 ;
V_198 -> args [ 3 ] = 0 ;
V_198 -> args [ 4 ] = 0 ;
}
V_216:
V_198 -> args [ 0 ] = 1 ;
V_211 = V_210 = V_212 = 0 ;
}
if ( ! ( V_213 & ~ V_54 ) )
goto V_91;
for ( V_209 = V_211 ; V_209 <= V_132 -> V_225 ; V_209 ++ ) {
struct V_226 * V_227 = & V_132 -> V_228 [ V_209 ] ;
T_4 * V_221 = F_84 ( V_132 , V_209 ) ;
struct V_229 * V_230 ;
struct V_12 * V_13 ;
V_210 = 0 ;
if ( F_85 ( & V_227 -> V_231 ) )
continue;
if ( V_209 > V_211 )
V_212 = 0 ;
F_80 ( V_221 ) ;
F_86 (sk, node, &head->chain) {
int V_232 , V_233 ;
if ( ! F_82 ( F_56 ( V_13 ) , V_130 ) )
continue;
if ( V_210 < V_212 )
goto V_234;
V_232 = ( V_13 -> V_53 == V_111 ) ?
F_43 ( V_13 ) -> V_120 : V_13 -> V_53 ;
if ( ! ( V_213 & ( 1 << V_232 ) ) )
goto V_234;
if ( V_11 -> V_133 != V_185 &&
V_13 -> V_15 != V_11 -> V_133 )
goto V_234;
if ( V_11 -> V_16 . V_17 != F_8 ( V_13 -> V_18 ) &&
V_11 -> V_16 . V_17 )
goto V_234;
if ( V_11 -> V_16 . V_19 != V_13 -> V_20 &&
V_11 -> V_16 . V_19 )
goto V_234;
F_78 () ;
if ( ! F_71 ( V_158 , V_13 ) )
goto V_234;
V_233 = F_48 ( V_13 , V_40 , V_11 ,
F_60 ( F_61 ( V_198 -> V_40 ) . V_13 ) ,
F_61 ( V_198 -> V_40 ) . V_63 ,
V_198 -> V_71 -> V_139 , V_199 ,
V_198 -> V_71 ) ;
if ( V_233 < 0 ) {
F_83 ( V_221 ) ;
goto V_224;
}
V_234:
++ V_210 ;
}
F_83 ( V_221 ) ;
F_87 () ;
}
V_224:
V_198 -> args [ 1 ] = V_209 ;
V_198 -> args [ 2 ] = V_210 ;
V_91:
;
}
static int F_88 ( struct V_39 * V_40 , struct V_197 * V_198 ,
const struct V_61 * V_11 ,
struct V_72 * V_158 )
{
const struct V_1 * V_9 ;
int V_108 = 0 ;
V_9 = F_1 ( V_11 -> V_75 ) ;
if ( ! F_57 ( V_9 ) )
V_9 -> V_235 ( V_40 , V_198 , V_11 , V_158 ) ;
else
V_108 = F_58 ( V_9 ) ;
F_5 ( V_9 ) ;
return V_108 ? : V_40 -> V_159 ;
}
static int F_89 ( struct V_39 * V_40 , struct V_197 * V_198 )
{
int V_236 = sizeof( struct V_61 ) ;
struct V_72 * V_158 = NULL ;
if ( F_90 ( V_198 -> V_71 , V_236 ) )
V_158 = F_91 ( V_198 -> V_71 , V_236 , V_237 ) ;
return F_88 ( V_40 , V_198 , F_24 ( V_198 -> V_71 ) , V_158 ) ;
}
static int F_92 ( int type )
{
switch ( type ) {
case V_238 :
return V_239 ;
case V_240 :
return V_241 ;
default:
return 0 ;
}
}
static int F_93 ( struct V_39 * V_40 ,
struct V_197 * V_198 )
{
struct V_242 * V_243 = F_24 ( V_198 -> V_71 ) ;
int V_236 = sizeof( struct V_242 ) ;
struct V_61 V_62 ;
struct V_72 * V_158 = NULL ;
V_62 . V_133 = V_185 ;
V_62 . V_75 = F_92 ( V_198 -> V_71 -> V_76 ) ;
V_62 . V_70 = V_243 -> V_70 ;
V_62 . V_213 = V_243 -> V_213 ;
V_62 . V_16 = V_243 -> V_16 ;
if ( F_90 ( V_198 -> V_71 , V_236 ) )
V_158 = F_91 ( V_198 -> V_71 , V_236 , V_237 ) ;
return F_88 ( V_40 , V_198 , & V_62 , V_158 ) ;
}
static int F_94 ( struct V_39 * V_135 ,
const struct V_66 * V_71 )
{
struct V_242 * V_243 = F_24 ( V_71 ) ;
struct V_61 V_62 ;
V_62 . V_133 = V_243 -> V_14 ;
V_62 . V_75 = F_92 ( V_71 -> V_76 ) ;
V_62 . V_70 = V_243 -> V_70 ;
V_62 . V_213 = V_243 -> V_213 ;
V_62 . V_16 = V_243 -> V_16 ;
return F_65 ( V_143 , V_135 , V_71 , & V_62 ) ;
}
static int F_95 ( struct V_39 * V_40 , struct V_66 * V_71 )
{
int V_236 = sizeof( struct V_242 ) ;
struct V_130 * V_130 = F_56 ( V_40 -> V_13 ) ;
if ( V_71 -> V_76 >= V_244 ||
F_96 ( V_71 ) < V_236 )
return - V_134 ;
if ( V_71 -> V_65 & V_245 ) {
if ( F_90 ( V_71 , V_236 ) ) {
struct V_72 * V_73 ;
V_73 = F_91 ( V_71 , V_236 ,
V_237 ) ;
if ( ! V_73 ||
F_69 ( V_73 ) < sizeof( struct V_161 ) ||
F_76 ( F_33 ( V_73 ) , F_69 ( V_73 ) ) )
return - V_134 ;
}
{
struct V_246 V_247 = {
. V_235 = F_93 ,
} ;
return F_97 ( V_130 -> V_140 , V_40 , V_71 , & V_247 ) ;
}
}
return F_94 ( V_40 , V_71 ) ;
}
static int F_98 ( struct V_39 * V_40 , struct V_66 * V_248 )
{
int V_236 = sizeof( struct V_61 ) ;
struct V_130 * V_130 = F_56 ( V_40 -> V_13 ) ;
if ( F_96 ( V_248 ) < V_236 )
return - V_134 ;
if ( V_248 -> V_76 == V_143 &&
V_248 -> V_65 & V_245 ) {
if ( F_90 ( V_248 , V_236 ) ) {
struct V_72 * V_73 ;
V_73 = F_91 ( V_248 , V_236 ,
V_237 ) ;
if ( ! V_73 ||
F_69 ( V_73 ) < sizeof( struct V_161 ) ||
F_76 ( F_33 ( V_73 ) , F_69 ( V_73 ) ) )
return - V_134 ;
}
{
struct V_246 V_247 = {
. V_235 = F_89 ,
} ;
return F_97 ( V_130 -> V_140 , V_40 , V_248 , & V_247 ) ;
}
}
return F_65 ( V_248 -> V_76 , V_40 , V_248 , F_24 ( V_248 ) ) ;
}
static
int F_99 ( struct V_39 * V_40 , struct V_12 * V_13 )
{
const struct V_1 * V_9 ;
struct V_66 * V_71 ;
struct V_72 * V_73 ;
struct V_10 * V_11 ;
void * V_74 = NULL ;
int V_108 = 0 ;
V_71 = F_23 ( V_40 , 0 , 0 , V_143 , sizeof( * V_11 ) , 0 ) ;
if ( ! V_71 )
return - V_138 ;
V_11 = F_24 ( V_71 ) ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
F_7 ( V_11 , V_13 ) ;
if ( V_13 -> V_249 == V_250 || V_13 -> V_249 == V_251 )
V_11 -> V_16 . V_17 = F_14 ( V_13 ) -> V_223 ;
V_11 -> V_78 = V_13 -> V_53 ;
if ( ( V_108 = F_15 ( V_40 , V_252 , V_13 -> V_253 ) ) ) {
F_39 ( V_40 , V_71 ) ;
return V_108 ;
}
V_9 = F_1 ( V_13 -> V_253 ) ;
if ( F_57 ( V_9 ) ) {
F_5 ( V_9 ) ;
F_39 ( V_40 , V_71 ) ;
return F_58 ( V_9 ) ;
}
V_73 = V_9 -> V_105
? F_32 ( V_40 , V_104 ,
V_9 -> V_105 ,
V_106 )
: NULL ;
if ( V_73 )
V_74 = F_33 ( V_73 ) ;
V_9 -> V_90 ( V_13 , V_11 , V_74 ) ;
F_5 ( V_9 ) ;
F_38 ( V_40 , V_71 ) ;
return 0 ;
}
int F_100 ( const struct V_1 * V_248 )
{
const T_5 type = V_248 -> V_254 ;
int V_108 = - V_134 ;
if ( type >= V_255 )
goto V_91;
F_3 ( & V_7 ) ;
V_108 = - V_256 ;
if ( ! V_3 [ type ] ) {
V_3 [ type ] = V_248 ;
V_108 = 0 ;
}
F_6 ( & V_7 ) ;
V_91:
return V_108 ;
}
void F_101 ( const struct V_1 * V_248 )
{
const T_5 type = V_248 -> V_254 ;
if ( type >= V_255 )
return;
F_3 ( & V_7 ) ;
V_3 [ type ] = NULL ;
F_6 ( & V_7 ) ;
}
static int T_6 F_102 ( void )
{
const int V_257 = ( V_255 *
sizeof( struct V_1 * ) ) ;
int V_108 = - V_138 ;
V_3 = F_103 ( V_257 , V_137 ) ;
if ( ! V_3 )
goto V_91;
V_108 = F_104 ( & V_1 ) ;
if ( V_108 )
goto V_258;
V_108 = F_104 ( & V_259 ) ;
if ( V_108 )
goto V_260;
F_105 ( F_95 ) ;
V_91:
return V_108 ;
V_260:
F_106 ( & V_1 ) ;
V_258:
F_107 ( V_3 ) ;
goto V_91;
}
static void T_7 F_108 ( void )
{
F_106 ( & V_259 ) ;
F_106 ( & V_1 ) ;
F_109 ( F_95 ) ;
F_107 ( V_3 ) ;
}
