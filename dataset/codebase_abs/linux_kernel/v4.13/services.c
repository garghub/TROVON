static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * * V_6 ,
T_1 * V_7 )
{
struct V_5 * V_8 = NULL ;
T_2 V_9 = sizeof( struct V_5 ) ;
T_1 V_10 , V_11 ;
unsigned V_12 ;
bool V_13 = false ;
if ( ! V_4 )
return - V_14 ;
V_10 = 0 ;
while ( V_4 [ V_10 ] . V_15 )
V_10 ++ ;
V_8 = F_2 ( ++ V_10 , V_9 , V_16 ) ;
if ( ! V_8 )
return - V_17 ;
V_11 = 0 ;
while ( V_4 [ V_11 ] . V_15 ) {
struct V_3 * V_18 = V_4 + ( V_11 ++ ) ;
struct V_5 * V_19 = V_8 + V_11 ;
if ( ! strcmp ( V_18 -> V_15 , L_1 ) ) {
V_19 -> V_20 = 0 ;
continue;
}
V_19 -> V_21 = F_3 ( V_2 , V_18 -> V_15 ) ;
if ( ! V_19 -> V_21 ) {
F_4 ( V_22
L_2 ,
V_18 -> V_15 ) ;
if ( V_2 -> V_23 )
goto V_24;
V_19 -> V_20 = 0 ;
V_13 = true ;
continue;
}
V_12 = 0 ;
while ( V_18 -> V_25 [ V_12 ] ) {
if ( ! * V_18 -> V_25 [ V_12 ] ) {
V_12 ++ ;
continue;
}
V_19 -> V_25 [ V_12 ] = F_5 ( V_2 , V_19 -> V_21 ,
V_18 -> V_25 [ V_12 ] ) ;
if ( ! V_19 -> V_25 [ V_12 ] ) {
F_4 ( V_22
L_3 ,
V_18 -> V_25 [ V_12 ] , V_18 -> V_15 ) ;
if ( V_2 -> V_23 )
goto V_24;
V_13 = true ;
}
V_12 ++ ;
}
V_19 -> V_20 = V_12 ;
}
if ( V_13 )
F_4 ( V_22 L_4 ,
V_2 -> V_26 ? L_5 : L_6 ) ;
* V_6 = V_8 ;
* V_7 = V_10 ;
return 0 ;
V_24:
F_6 ( V_8 ) ;
return - V_14 ;
}
static T_1 F_7 ( T_1 V_27 )
{
if ( V_27 < V_28 )
return V_29 [ V_27 ] . V_21 ;
return V_27 ;
}
static T_1 F_8 ( T_1 V_30 )
{
T_1 V_10 ;
for ( V_10 = 1 ; V_10 < V_28 ; V_10 ++ ) {
if ( V_29 [ V_10 ] . V_21 == V_30 )
return V_10 ;
}
return V_31 ;
}
static void F_9 ( T_1 V_27 , struct V_32 * V_33 ,
int V_26 )
{
if ( V_27 < V_28 ) {
unsigned V_10 , V_34 = V_29 [ V_27 ] . V_20 ;
T_3 V_35 ;
for ( V_10 = 0 , V_35 = 0 ; V_10 < V_34 ; V_10 ++ ) {
if ( V_33 -> V_36 & V_29 [ V_27 ] . V_25 [ V_10 ] )
V_35 |= 1 << V_10 ;
if ( V_26 && ! V_29 [ V_27 ] . V_25 [ V_10 ] )
V_35 |= 1 << V_10 ;
}
V_33 -> V_36 = V_35 ;
for ( V_10 = 0 , V_35 = 0 ; V_10 < V_34 ; V_10 ++ )
if ( V_33 -> V_37 & V_29 [ V_27 ] . V_25 [ V_10 ] )
V_35 |= 1 << V_10 ;
V_33 -> V_37 = V_35 ;
for ( V_10 = 0 , V_35 = 0 ; V_10 < V_34 ; V_10 ++ ) {
if ( V_33 -> V_38 & V_29 [ V_27 ] . V_25 [ V_10 ] )
V_35 |= 1 << V_10 ;
if ( ! V_26 && ! V_29 [ V_27 ] . V_25 [ V_10 ] )
V_35 |= 1 << V_10 ;
}
for (; V_10 < ( sizeof( T_3 ) * 8 ) ; V_10 ++ )
V_35 |= 1 << V_10 ;
V_33 -> V_38 = V_35 ;
}
}
int F_10 ( void )
{
return V_1 . V_39 ;
}
static int F_11 ( struct V_40 * V_41 ,
struct V_40 * V_42 ,
struct V_40 * V_43 ,
struct V_44 * V_45 )
{
T_3 V_46 , V_47 ;
struct V_40 * V_48 ;
struct V_49 * V_50 , * V_51 ;
struct V_52 * V_53 , * V_54 ;
struct V_44 * V_55 ;
int V_56 [ V_57 ] ;
int V_58 = - 1 ;
for ( V_55 = V_45 ; V_55 ; V_55 = V_55 -> V_59 ) {
switch ( V_55 -> V_60 ) {
case V_61 :
F_12 ( V_58 < 0 ) ;
V_56 [ V_58 ] = ! V_56 [ V_58 ] ;
break;
case V_62 :
F_12 ( V_58 < 1 ) ;
V_58 -- ;
V_56 [ V_58 ] &= V_56 [ V_58 + 1 ] ;
break;
case V_63 :
F_12 ( V_58 < 1 ) ;
V_58 -- ;
V_56 [ V_58 ] |= V_56 [ V_58 + 1 ] ;
break;
case V_64 :
if ( V_58 == ( V_57 - 1 ) )
return 0 ;
switch ( V_55 -> V_65 ) {
case V_66 :
V_46 = V_41 -> V_67 ;
V_47 = V_42 -> V_67 ;
break;
case V_68 :
V_46 = V_41 -> type ;
V_47 = V_42 -> type ;
break;
case V_69 :
V_46 = V_41 -> V_70 ;
V_47 = V_42 -> V_70 ;
V_50 = V_1 . V_71 [ V_46 - 1 ] ;
V_51 = V_1 . V_71 [ V_47 - 1 ] ;
switch ( V_55 -> V_72 ) {
case V_73 :
V_56 [ ++ V_58 ] = F_13 ( & V_50 -> V_74 ,
V_47 - 1 ) ;
continue;
case V_75 :
V_56 [ ++ V_58 ] = F_13 ( & V_51 -> V_74 ,
V_46 - 1 ) ;
continue;
case V_76 :
V_56 [ ++ V_58 ] = ( ! F_13 ( & V_50 -> V_74 ,
V_47 - 1 ) &&
! F_13 ( & V_51 -> V_74 ,
V_46 - 1 ) ) ;
continue;
default:
break;
}
break;
case V_77 :
V_53 = & ( V_41 -> V_78 . V_79 [ 0 ] ) ;
V_54 = & ( V_42 -> V_78 . V_79 [ 0 ] ) ;
goto V_80;
case V_81 :
V_53 = & ( V_41 -> V_78 . V_79 [ 0 ] ) ;
V_54 = & ( V_42 -> V_78 . V_79 [ 1 ] ) ;
goto V_80;
case V_82 :
V_53 = & ( V_41 -> V_78 . V_79 [ 1 ] ) ;
V_54 = & ( V_42 -> V_78 . V_79 [ 0 ] ) ;
goto V_80;
case V_83 :
V_53 = & ( V_41 -> V_78 . V_79 [ 1 ] ) ;
V_54 = & ( V_42 -> V_78 . V_79 [ 1 ] ) ;
goto V_80;
case V_84 :
V_53 = & ( V_41 -> V_78 . V_79 [ 0 ] ) ;
V_54 = & ( V_41 -> V_78 . V_79 [ 1 ] ) ;
goto V_80;
case V_85 :
V_53 = & ( V_42 -> V_78 . V_79 [ 0 ] ) ;
V_54 = & ( V_42 -> V_78 . V_79 [ 1 ] ) ;
goto V_80;
V_80:
switch ( V_55 -> V_72 ) {
case V_86 :
V_56 [ ++ V_58 ] = F_14 ( V_53 , V_54 ) ;
continue;
case V_87 :
V_56 [ ++ V_58 ] = ! F_14 ( V_53 , V_54 ) ;
continue;
case V_73 :
V_56 [ ++ V_58 ] = F_15 ( V_53 , V_54 ) ;
continue;
case V_75 :
V_56 [ ++ V_58 ] = F_15 ( V_54 , V_53 ) ;
continue;
case V_76 :
V_56 [ ++ V_58 ] = F_16 ( V_54 , V_53 ) ;
continue;
default:
F_17 () ;
return 0 ;
}
break;
default:
F_17 () ;
return 0 ;
}
switch ( V_55 -> V_72 ) {
case V_86 :
V_56 [ ++ V_58 ] = ( V_46 == V_47 ) ;
break;
case V_87 :
V_56 [ ++ V_58 ] = ( V_46 != V_47 ) ;
break;
default:
F_17 () ;
return 0 ;
}
break;
case V_88 :
if ( V_58 == ( V_57 - 1 ) )
return 0 ;
V_48 = V_41 ;
if ( V_55 -> V_65 & V_89 )
V_48 = V_42 ;
else if ( V_55 -> V_65 & V_90 ) {
V_48 = V_43 ;
if ( ! V_48 ) {
F_17 () ;
return 0 ;
}
}
if ( V_55 -> V_65 & V_66 )
V_46 = V_48 -> V_67 ;
else if ( V_55 -> V_65 & V_69 )
V_46 = V_48 -> V_70 ;
else if ( V_55 -> V_65 & V_68 )
V_46 = V_48 -> type ;
else {
F_17 () ;
return 0 ;
}
switch ( V_55 -> V_72 ) {
case V_86 :
V_56 [ ++ V_58 ] = F_13 ( & V_55 -> V_91 , V_46 - 1 ) ;
break;
case V_87 :
V_56 [ ++ V_58 ] = ! F_13 ( & V_55 -> V_91 , V_46 - 1 ) ;
break;
default:
F_17 () ;
return 0 ;
}
break;
default:
F_17 () ;
return 0 ;
}
}
F_12 ( V_58 != 0 ) ;
return V_56 [ 0 ] ;
}
static int F_18 ( void * V_12 , void * V_92 , void * args )
{
struct V_93 * V_94 = V_92 ;
char * * V_95 = args ;
F_12 ( V_94 -> V_21 < 1 || V_94 -> V_21 > 32 ) ;
V_95 [ V_94 -> V_21 - 1 ] = ( char * ) V_12 ;
return 0 ;
}
static void F_19 ( struct V_40 * V_41 ,
struct V_40 * V_42 ,
T_1 V_27 ,
T_3 V_96 ,
const char * V_97 )
{
struct V_98 * V_99 ;
struct V_100 * V_101 ;
struct V_102 * V_103 ;
char * V_104 ;
char * V_105 = NULL ;
char * V_106 = NULL ;
char * V_95 [ 32 ] ;
int V_107 ;
T_3 V_108 ;
bool V_109 = false ;
if ( ! V_96 )
return;
V_104 = F_20 ( & V_1 , V_110 , V_27 - 1 ) ;
V_101 = V_1 . V_111 [ V_27 - 1 ] ;
V_99 = V_101 -> V_112 ;
if ( V_99 &&
F_21 ( V_99 -> V_96 . V_113 ,
F_18 , V_95 ) < 0 )
goto V_114;
if ( F_21 ( V_101 -> V_96 . V_113 ,
F_18 , V_95 ) < 0 )
goto V_114;
if ( F_22 ( V_41 ,
& V_105 , & V_108 ) < 0 )
goto V_114;
if ( F_22 ( V_42 ,
& V_106 , & V_108 ) < 0 )
goto V_114;
V_103 = F_23 ( V_115 -> V_116 ,
V_16 , V_117 ) ;
if ( ! V_103 )
goto V_114;
F_24 ( V_103 , L_7
L_8 ,
V_97 , V_105 , V_106 , V_104 ) ;
for ( V_107 = 0 ; V_107 < 32 ; V_107 ++ ) {
T_3 V_118 = ( 1 << V_107 ) ;
if ( ( V_118 & V_96 ) == 0 )
continue;
F_24 ( V_103 , L_9 ,
V_109 ? L_10 : L_1 ,
V_95 [ V_107 ]
? V_95 [ V_107 ] : L_11 ) ;
V_109 = true ;
}
F_25 ( V_103 ) ;
V_114:
F_6 ( V_106 ) ;
F_6 ( V_105 ) ;
return;
}
static void F_26 ( struct V_40 * V_41 ,
struct V_40 * V_42 ,
T_1 V_27 ,
struct V_32 * V_33 )
{
struct V_40 V_119 ;
struct V_40 V_120 , * V_121 = V_42 ;
struct V_32 V_122 ;
struct V_123 * V_124 ;
struct V_123 * V_125 ;
T_3 V_126 = 0 ;
V_124 = F_27 ( V_1 . V_127 ,
V_41 -> type - 1 ) ;
F_12 ( ! V_124 ) ;
if ( ! V_124 -> V_128 )
return;
V_125 = F_27 ( V_1 . V_127 ,
V_42 -> type - 1 ) ;
F_12 ( ! V_125 ) ;
memset ( & V_122 , 0 , sizeof( V_122 ) ) ;
memcpy ( & V_119 , V_41 , sizeof( V_119 ) ) ;
V_119 . type = V_124 -> V_128 ;
if ( V_125 -> V_128 ) {
memcpy ( & V_120 , V_42 , sizeof( V_120 ) ) ;
V_120 . type = V_125 -> V_128 ;
V_121 = & V_120 ;
}
F_28 ( & V_119 ,
V_121 ,
V_27 ,
& V_122 ,
NULL ) ;
V_126 = ~ V_122 . V_36 & V_33 -> V_36 ;
if ( F_29 ( ! V_126 ) )
return;
V_33 -> V_36 &= ~ V_126 ;
F_19 ( V_41 , V_42 ,
V_27 , V_126 , L_12 ) ;
}
void F_30 (
struct V_129 * V_130 ,
struct V_131 * V_132 )
{
unsigned int V_10 ;
if ( V_132 -> V_133 . V_134 . V_130 -> V_135 == V_136 ) {
for ( V_10 = 0 ; V_10 < F_31 ( V_130 -> V_137 . V_138 ) ; V_10 ++ )
V_130 -> V_137 . V_138 [ V_10 ] |= V_132 -> V_133 . V_134 . V_130 -> V_25 . V_138 [ V_10 ] ;
} else if ( V_132 -> V_133 . V_134 . V_130 -> V_135 == V_139 ) {
F_32 ( V_130 -> V_137 . V_138 ,
V_132 -> V_133 . V_134 . V_130 -> V_140 ) ;
}
if ( V_132 -> V_141 . V_135 & V_142 )
V_130 -> V_143 = 1 ;
}
static void F_28 ( struct V_40 * V_41 ,
struct V_40 * V_42 ,
T_1 V_27 ,
struct V_32 * V_33 ,
struct V_129 * V_130 )
{
struct V_144 * V_145 ;
struct V_146 * V_147 ;
struct V_148 V_149 ;
struct V_131 * V_132 ;
struct V_100 * V_150 ;
struct V_151 * V_152 , * V_153 ;
struct V_154 * V_155 , * V_156 ;
unsigned int V_10 , V_11 ;
V_33 -> V_36 = 0 ;
V_33 -> V_37 = 0 ;
V_33 -> V_38 = 0xffffffff ;
if ( V_130 ) {
memset ( & V_130 -> V_137 , 0 , sizeof( V_130 -> V_137 ) ) ;
V_130 -> V_143 = 0 ;
}
if ( F_33 ( ! V_27 || V_27 > V_1 . V_157 . V_158 ) ) {
if ( F_34 () )
F_4 ( V_159 L_13 , V_27 ) ;
return;
}
V_150 = V_1 . V_111 [ V_27 - 1 ] ;
V_149 . V_160 = V_27 ;
V_149 . V_135 = V_161 | V_162 ;
V_152 = F_35 ( V_1 . V_163 , V_41 -> type - 1 ) ;
F_12 ( ! V_152 ) ;
V_153 = F_35 ( V_1 . V_163 , V_42 -> type - 1 ) ;
F_12 ( ! V_153 ) ;
F_36 (sattr, snode, i) {
F_36 (tattr, tnode, j) {
V_149 . V_164 = V_10 + 1 ;
V_149 . V_165 = V_11 + 1 ;
for ( V_132 = F_37 ( & V_1 . V_166 , & V_149 ) ;
V_132 ;
V_132 = F_38 ( V_132 , V_149 . V_135 ) ) {
if ( V_132 -> V_141 . V_135 == V_167 )
V_33 -> V_36 |= V_132 -> V_133 . V_134 . V_168 ;
else if ( V_132 -> V_141 . V_135 == V_169 )
V_33 -> V_37 |= V_132 -> V_133 . V_134 . V_168 ;
else if ( V_132 -> V_141 . V_135 == V_170 )
V_33 -> V_38 &= V_132 -> V_133 . V_134 . V_168 ;
else if ( V_130 && ( V_132 -> V_141 . V_135 & V_162 ) )
F_30 ( V_130 , V_132 ) ;
}
F_39 ( & V_1 . V_171 , & V_149 ,
V_33 , V_130 ) ;
}
}
V_145 = V_150 -> V_172 ;
while ( V_145 ) {
if ( ( V_145 -> V_96 & ( V_33 -> V_36 ) ) &&
! F_11 ( V_41 , V_42 , NULL ,
V_145 -> V_173 ) ) {
V_33 -> V_36 &= ~ ( V_145 -> V_96 ) ;
}
V_145 = V_145 -> V_59 ;
}
if ( V_27 == V_1 . V_174 &&
( V_33 -> V_36 & V_1 . V_175 ) &&
V_41 -> V_70 != V_42 -> V_70 ) {
for ( V_147 = V_1 . V_146 ; V_147 ; V_147 = V_147 -> V_59 ) {
if ( V_41 -> V_70 == V_147 -> V_70 &&
V_42 -> V_70 == V_147 -> V_176 )
break;
}
if ( ! V_147 )
V_33 -> V_36 &= ~ V_1 . V_175 ;
}
F_26 ( V_41 , V_42 ,
V_27 , V_33 ) ;
}
static int F_40 ( struct V_40 * V_177 ,
struct V_40 * V_178 ,
struct V_40 * V_42 ,
T_1 V_27 )
{
char * V_179 = NULL , * V_34 = NULL , * V_180 = NULL ;
T_3 V_181 , V_182 , V_183 ;
if ( F_22 ( V_177 , & V_179 , & V_181 ) )
goto V_114;
if ( F_22 ( V_178 , & V_34 , & V_182 ) )
goto V_114;
if ( F_22 ( V_42 , & V_180 , & V_183 ) )
goto V_114;
F_41 ( V_115 -> V_116 , V_16 , V_117 ,
L_14
L_15 ,
V_179 , V_34 , V_180 , F_20 ( & V_1 , V_110 , V_27 - 1 ) ) ;
V_114:
F_6 ( V_179 ) ;
F_6 ( V_34 ) ;
F_6 ( V_180 ) ;
if ( ! V_184 )
return 0 ;
return - V_185 ;
}
static int F_42 ( T_3 V_186 , T_3 V_187 , T_3 V_188 ,
T_1 V_189 , bool V_67 )
{
struct V_40 * V_177 ;
struct V_40 * V_178 ;
struct V_40 * V_42 ;
struct V_100 * V_150 ;
struct V_144 * V_145 ;
T_1 V_27 ;
int V_190 = 0 ;
if ( ! V_191 )
return 0 ;
F_43 ( & V_192 ) ;
if ( ! V_67 )
V_27 = F_7 ( V_189 ) ;
else
V_27 = V_189 ;
if ( ! V_27 || V_27 > V_1 . V_157 . V_158 ) {
V_190 = - V_14 ;
goto V_114;
}
V_150 = V_1 . V_111 [ V_27 - 1 ] ;
V_177 = F_44 ( & V_193 , V_186 ) ;
if ( ! V_177 ) {
F_4 ( V_194 L_16 ,
V_195 , V_186 ) ;
V_190 = - V_14 ;
goto V_114;
}
V_178 = F_44 ( & V_193 , V_187 ) ;
if ( ! V_178 ) {
F_4 ( V_194 L_16 ,
V_195 , V_187 ) ;
V_190 = - V_14 ;
goto V_114;
}
V_42 = F_44 ( & V_193 , V_188 ) ;
if ( ! V_42 ) {
F_4 ( V_194 L_16 ,
V_195 , V_188 ) ;
V_190 = - V_14 ;
goto V_114;
}
V_145 = V_150 -> V_196 ;
while ( V_145 ) {
if ( ! F_11 ( V_177 , V_178 , V_42 ,
V_145 -> V_173 ) ) {
if ( V_67 )
V_190 = - V_185 ;
else
V_190 = F_40 ( V_177 ,
V_178 ,
V_42 ,
V_27 ) ;
goto V_114;
}
V_145 = V_145 -> V_59 ;
}
V_114:
F_45 ( & V_192 ) ;
return V_190 ;
}
int F_46 ( T_3 V_186 , T_3 V_187 , T_3 V_188 ,
T_1 V_27 )
{
return F_42 ( V_186 , V_187 , V_188 ,
V_27 , true ) ;
}
int F_47 ( T_3 V_186 , T_3 V_187 , T_3 V_188 ,
T_1 V_189 )
{
return F_42 ( V_186 , V_187 , V_188 ,
V_189 , false ) ;
}
int F_48 ( T_3 V_197 , T_3 V_198 )
{
struct V_40 * V_199 , * V_200 ;
struct V_123 * type ;
int V_107 ;
int V_190 ;
F_43 ( & V_192 ) ;
V_190 = - V_14 ;
V_199 = F_44 ( & V_193 , V_197 ) ;
if ( ! V_199 ) {
F_4 ( V_194 L_17 ,
V_195 , V_197 ) ;
goto V_114;
}
V_190 = - V_14 ;
V_200 = F_44 ( & V_193 , V_198 ) ;
if ( ! V_200 ) {
F_4 ( V_194 L_17 ,
V_195 , V_198 ) ;
goto V_114;
}
V_190 = 0 ;
if ( V_199 -> type == V_200 -> type )
goto V_114;
V_107 = V_200 -> type ;
while ( true ) {
type = F_27 ( V_1 . V_127 ,
V_107 - 1 ) ;
F_12 ( ! type ) ;
V_190 = - V_185 ;
if ( ! type -> V_128 )
break;
V_190 = 0 ;
if ( type -> V_128 == V_199 -> type )
break;
V_107 = type -> V_128 ;
}
if ( V_190 ) {
char * V_201 = NULL ;
char * V_202 = NULL ;
T_3 V_108 ;
if ( ! F_22 ( V_199 ,
& V_201 , & V_108 ) &&
! F_22 ( V_200 ,
& V_202 , & V_108 ) ) {
F_41 ( V_115 -> V_116 ,
V_16 , V_117 ,
L_18
L_19
L_20 ,
V_201 , V_202 ) ;
}
F_6 ( V_202 ) ;
F_6 ( V_201 ) ;
}
V_114:
F_45 ( & V_192 ) ;
return V_190 ;
}
static void F_49 ( struct V_32 * V_33 )
{
V_33 -> V_36 = 0 ;
V_33 -> V_37 = 0 ;
V_33 -> V_38 = 0xffffffff ;
V_33 -> V_203 = V_204 ;
V_33 -> V_205 = 0 ;
}
void F_50 ( struct V_206 * V_207 ,
struct V_131 * V_132 )
{
unsigned int V_10 ;
if ( V_132 -> V_133 . V_134 . V_130 -> V_135 == V_139 ) {
if ( V_207 -> V_140 != V_132 -> V_133 . V_134 . V_130 -> V_140 )
return;
} else if ( V_132 -> V_133 . V_134 . V_130 -> V_135 == V_136 ) {
if ( ! F_51 ( V_132 -> V_133 . V_134 . V_130 -> V_25 . V_138 ,
V_207 -> V_140 ) )
return;
} else {
F_17 () ;
}
if ( V_132 -> V_141 . V_135 == V_142 ) {
V_207 -> V_208 |= V_209 ;
if ( V_132 -> V_133 . V_134 . V_130 -> V_135 == V_136 ) {
memset ( V_207 -> V_36 -> V_138 , 0xff ,
sizeof( V_207 -> V_36 -> V_138 ) ) ;
}
if ( V_132 -> V_133 . V_134 . V_130 -> V_135 == V_139 ) {
for ( V_10 = 0 ; V_10 < F_31 ( V_207 -> V_36 -> V_138 ) ; V_10 ++ )
V_207 -> V_36 -> V_138 [ V_10 ] |=
V_132 -> V_133 . V_134 . V_130 -> V_25 . V_138 [ V_10 ] ;
}
} else if ( V_132 -> V_141 . V_135 == V_210 ) {
V_207 -> V_208 |= V_211 ;
if ( V_132 -> V_133 . V_134 . V_130 -> V_135 == V_136 ) {
memset ( V_207 -> V_37 -> V_138 , 0xff ,
sizeof( V_207 -> V_37 -> V_138 ) ) ;
}
if ( V_132 -> V_133 . V_134 . V_130 -> V_135 == V_139 ) {
for ( V_10 = 0 ; V_10 < F_31 ( V_207 -> V_37 -> V_138 ) ; V_10 ++ )
V_207 -> V_37 -> V_138 [ V_10 ] |=
V_132 -> V_133 . V_134 . V_130 -> V_25 . V_138 [ V_10 ] ;
}
} else if ( V_132 -> V_141 . V_135 == V_212 ) {
V_207 -> V_208 |= V_213 ;
if ( V_132 -> V_133 . V_134 . V_130 -> V_135 == V_136 ) {
memset ( V_207 -> V_214 -> V_138 , 0xff ,
sizeof( V_207 -> V_214 -> V_138 ) ) ;
}
if ( V_132 -> V_133 . V_134 . V_130 -> V_135 == V_139 ) {
for ( V_10 = 0 ; V_10 < F_31 ( V_207 -> V_214 -> V_138 ) ; V_10 ++ )
V_207 -> V_214 -> V_138 [ V_10 ] |=
V_132 -> V_133 . V_134 . V_130 -> V_25 . V_138 [ V_10 ] ;
}
} else {
F_17 () ;
}
}
void F_52 ( T_3 V_215 ,
T_3 V_216 ,
T_1 V_189 ,
T_4 V_140 ,
struct V_206 * V_207 )
{
T_1 V_27 ;
struct V_40 * V_41 , * V_42 ;
struct V_148 V_149 ;
struct V_131 * V_132 ;
struct V_151 * V_152 , * V_153 ;
struct V_154 * V_155 , * V_156 ;
unsigned int V_10 , V_11 ;
V_207 -> V_140 = V_140 ;
V_207 -> V_208 = 0 ;
memset ( V_207 -> V_36 -> V_138 , 0 , sizeof( V_207 -> V_36 -> V_138 ) ) ;
memset ( V_207 -> V_37 -> V_138 , 0 , sizeof( V_207 -> V_37 -> V_138 ) ) ;
memset ( V_207 -> V_214 -> V_138 , 0 , sizeof( V_207 -> V_214 -> V_138 ) ) ;
F_43 ( & V_192 ) ;
if ( ! V_191 )
goto V_217;
V_41 = F_44 ( & V_193 , V_215 ) ;
if ( ! V_41 ) {
F_4 ( V_194 L_16 ,
V_195 , V_215 ) ;
goto V_114;
}
V_42 = F_44 ( & V_193 , V_216 ) ;
if ( ! V_42 ) {
F_4 ( V_194 L_16 ,
V_195 , V_216 ) ;
goto V_114;
}
V_27 = F_7 ( V_189 ) ;
if ( F_33 ( V_189 && ! V_27 ) ) {
if ( V_1 . V_26 )
goto V_217;
goto V_114;
}
if ( F_33 ( ! V_27 || V_27 > V_1 . V_157 . V_158 ) ) {
F_53 ( L_13 , V_27 ) ;
goto V_114;
}
V_149 . V_160 = V_27 ;
V_149 . V_135 = V_162 ;
V_152 = F_35 ( V_1 . V_163 ,
V_41 -> type - 1 ) ;
F_12 ( ! V_152 ) ;
V_153 = F_35 ( V_1 . V_163 ,
V_42 -> type - 1 ) ;
F_12 ( ! V_153 ) ;
F_36 (sattr, snode, i) {
F_36 (tattr, tnode, j) {
V_149 . V_164 = V_10 + 1 ;
V_149 . V_165 = V_11 + 1 ;
for ( V_132 = F_37 ( & V_1 . V_166 , & V_149 ) ;
V_132 ;
V_132 = F_38 ( V_132 , V_149 . V_135 ) )
F_50 ( V_207 , V_132 ) ;
F_54 ( & V_1 . V_171 ,
& V_149 , V_207 ) ;
}
}
V_114:
F_45 ( & V_192 ) ;
return;
V_217:
memset ( V_207 -> V_36 -> V_138 , 0xff , sizeof( V_207 -> V_36 -> V_138 ) ) ;
goto V_114;
}
void F_55 ( T_3 V_215 ,
T_3 V_216 ,
T_1 V_189 ,
struct V_32 * V_33 ,
struct V_129 * V_130 )
{
T_1 V_27 ;
struct V_40 * V_41 = NULL , * V_42 = NULL ;
F_43 ( & V_192 ) ;
F_49 ( V_33 ) ;
V_130 -> V_143 = 0 ;
if ( ! V_191 )
goto V_217;
V_41 = F_44 ( & V_193 , V_215 ) ;
if ( ! V_41 ) {
F_4 ( V_194 L_16 ,
V_195 , V_215 ) ;
goto V_114;
}
if ( F_13 ( & V_1 . V_218 , V_41 -> type ) )
V_33 -> V_205 |= V_219 ;
V_42 = F_44 ( & V_193 , V_216 ) ;
if ( ! V_42 ) {
F_4 ( V_194 L_16 ,
V_195 , V_216 ) ;
goto V_114;
}
V_27 = F_7 ( V_189 ) ;
if ( F_33 ( V_189 && ! V_27 ) ) {
if ( V_1 . V_26 )
goto V_217;
goto V_114;
}
F_28 ( V_41 , V_42 , V_27 , V_33 , V_130 ) ;
F_9 ( V_189 , V_33 , V_1 . V_26 ) ;
V_114:
F_45 ( & V_192 ) ;
return;
V_217:
V_33 -> V_36 = 0xffffffff ;
goto V_114;
}
void F_56 ( T_3 V_215 ,
T_3 V_216 ,
T_1 V_27 ,
struct V_32 * V_33 )
{
struct V_40 * V_41 = NULL , * V_42 = NULL ;
F_43 ( & V_192 ) ;
F_49 ( V_33 ) ;
if ( ! V_191 )
goto V_217;
V_41 = F_44 ( & V_193 , V_215 ) ;
if ( ! V_41 ) {
F_4 ( V_194 L_16 ,
V_195 , V_215 ) ;
goto V_114;
}
if ( F_13 ( & V_1 . V_218 , V_41 -> type ) )
V_33 -> V_205 |= V_219 ;
V_42 = F_44 ( & V_193 , V_216 ) ;
if ( ! V_42 ) {
F_4 ( V_194 L_16 ,
V_195 , V_216 ) ;
goto V_114;
}
if ( F_33 ( ! V_27 ) ) {
if ( V_1 . V_26 )
goto V_217;
goto V_114;
}
F_28 ( V_41 , V_42 , V_27 , V_33 , NULL ) ;
V_114:
F_45 ( & V_192 ) ;
return;
V_217:
V_33 -> V_36 = 0xffffffff ;
goto V_114;
}
static int F_22 ( struct V_40 * V_40 , char * * V_41 , T_3 * V_220 )
{
char * V_221 ;
if ( V_41 )
* V_41 = NULL ;
* V_220 = 0 ;
if ( V_40 -> V_143 ) {
* V_220 = V_40 -> V_143 ;
if ( V_41 ) {
* V_41 = F_57 ( V_40 -> V_222 , V_16 ) ;
if ( ! ( * V_41 ) )
return - V_17 ;
}
return 0 ;
}
* V_220 += strlen ( F_20 ( & V_1 , V_223 , V_40 -> V_67 - 1 ) ) + 1 ;
* V_220 += strlen ( F_20 ( & V_1 , V_224 , V_40 -> V_70 - 1 ) ) + 1 ;
* V_220 += strlen ( F_20 ( & V_1 , V_225 , V_40 -> type - 1 ) ) + 1 ;
* V_220 += F_58 ( V_40 ) ;
if ( ! V_41 )
return 0 ;
V_221 = F_59 ( * V_220 , V_16 ) ;
if ( ! V_221 )
return - V_17 ;
* V_41 = V_221 ;
V_221 += sprintf ( V_221 , L_21 ,
F_20 ( & V_1 , V_223 , V_40 -> V_67 - 1 ) ,
F_20 ( & V_1 , V_224 , V_40 -> V_70 - 1 ) ,
F_20 ( & V_1 , V_225 , V_40 -> type - 1 ) ) ;
F_60 ( V_40 , & V_221 ) ;
* V_221 = 0 ;
return 0 ;
}
const char * F_61 ( T_3 V_226 )
{
if ( F_33 ( V_226 > V_227 ) )
return NULL ;
return V_228 [ V_226 ] ;
}
static int F_62 ( T_3 V_226 , char * * V_41 ,
T_3 * V_220 , int V_229 )
{
struct V_40 * V_40 ;
int V_190 = 0 ;
if ( V_41 )
* V_41 = NULL ;
* V_220 = 0 ;
if ( ! V_191 ) {
if ( V_226 <= V_227 ) {
char * V_221 ;
* V_220 = strlen ( V_228 [ V_226 ] ) + 1 ;
if ( ! V_41 )
goto V_114;
V_221 = F_63 ( V_228 [ V_226 ] ,
* V_220 , V_16 ) ;
if ( ! V_221 ) {
V_190 = - V_17 ;
goto V_114;
}
* V_41 = V_221 ;
goto V_114;
}
F_4 ( V_194 L_22
L_23 , V_195 , V_226 ) ;
V_190 = - V_14 ;
goto V_114;
}
F_43 ( & V_192 ) ;
if ( V_229 )
V_40 = F_64 ( & V_193 , V_226 ) ;
else
V_40 = F_44 ( & V_193 , V_226 ) ;
if ( ! V_40 ) {
F_4 ( V_194 L_16 ,
V_195 , V_226 ) ;
V_190 = - V_14 ;
goto V_230;
}
V_190 = F_22 ( V_40 , V_41 , V_220 ) ;
V_230:
F_45 ( & V_192 ) ;
V_114:
return V_190 ;
}
int F_65 ( T_3 V_226 , char * * V_41 , T_3 * V_220 )
{
return F_62 ( V_226 , V_41 , V_220 , 0 ) ;
}
int F_66 ( T_3 V_226 , char * * V_41 , T_3 * V_220 )
{
return F_62 ( V_226 , V_41 , V_220 , 1 ) ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_193 * V_231 ,
char * V_41 ,
T_3 V_220 ,
struct V_40 * V_232 ,
T_3 V_233 )
{
struct V_49 * V_70 ;
struct V_123 * V_234 ;
struct V_235 * V_236 ;
char * V_221 , * V_138 , V_237 ;
int V_190 = 0 ;
F_68 ( V_232 ) ;
V_190 = - V_14 ;
V_221 = ( char * ) V_41 ;
V_138 = V_221 ;
while ( * V_138 && * V_138 != ':' )
V_138 ++ ;
if ( * V_138 == 0 )
goto V_114;
* V_138 ++ = 0 ;
V_236 = F_69 ( V_2 -> V_238 . V_113 , V_221 ) ;
if ( ! V_236 )
goto V_114;
V_232 -> V_67 = V_236 -> V_21 ;
V_221 = V_138 ;
while ( * V_138 && * V_138 != ':' )
V_138 ++ ;
if ( * V_138 == 0 )
goto V_114;
* V_138 ++ = 0 ;
V_70 = F_69 ( V_2 -> V_239 . V_113 , V_221 ) ;
if ( ! V_70 )
goto V_114;
V_232 -> V_70 = V_70 -> V_21 ;
V_221 = V_138 ;
while ( * V_138 && * V_138 != ':' )
V_138 ++ ;
V_237 = * V_138 ;
* V_138 ++ = 0 ;
V_234 = F_69 ( V_2 -> V_240 . V_113 , V_221 ) ;
if ( ! V_234 || V_234 -> V_241 )
goto V_114;
V_232 -> type = V_234 -> V_21 ;
V_190 = F_70 ( V_2 , V_237 , & V_138 , V_232 , V_231 , V_233 ) ;
if ( V_190 )
goto V_114;
V_190 = - V_14 ;
if ( ( V_138 - V_41 ) < V_220 )
goto V_114;
if ( ! F_71 ( V_2 , V_232 ) )
goto V_114;
V_190 = 0 ;
V_114:
if ( V_190 )
F_72 ( V_232 ) ;
return V_190 ;
}
static int F_73 ( const char * V_41 , T_3 V_220 ,
T_3 * V_226 , T_3 V_233 , T_5 V_242 ,
int V_229 )
{
char * V_243 , * V_222 = NULL ;
struct V_40 V_40 ;
int V_190 = 0 ;
if ( ! V_220 )
return - V_14 ;
if ( ! V_191 ) {
int V_10 ;
for ( V_10 = 1 ; V_10 < V_227 ; V_10 ++ ) {
if ( ! strcmp ( V_228 [ V_10 ] , V_41 ) ) {
* V_226 = V_10 ;
return 0 ;
}
}
* V_226 = V_244 ;
return 0 ;
}
* V_226 = V_245 ;
V_243 = F_59 ( V_220 + 1 , V_242 ) ;
if ( ! V_243 )
return - V_17 ;
memcpy ( V_243 , V_41 , V_220 ) ;
V_243 [ V_220 ] = 0 ;
if ( V_229 ) {
V_190 = - V_17 ;
V_222 = F_57 ( V_243 , V_242 ) ;
if ( ! V_222 )
goto V_114;
}
F_43 ( & V_192 ) ;
V_190 = F_67 ( & V_1 , & V_193 , V_243 ,
V_220 , & V_40 , V_233 ) ;
if ( V_190 == - V_14 && V_229 ) {
V_40 . V_222 = V_222 ;
V_40 . V_143 = V_220 ;
V_222 = NULL ;
} else if ( V_190 )
goto V_230;
V_190 = F_74 ( & V_193 , & V_40 , V_226 ) ;
F_72 ( & V_40 ) ;
V_230:
F_45 ( & V_192 ) ;
V_114:
F_6 ( V_243 ) ;
F_6 ( V_222 ) ;
return V_190 ;
}
int F_75 ( const char * V_41 , T_3 V_220 , T_3 * V_226 ,
T_5 V_246 )
{
return F_73 ( V_41 , V_220 ,
V_226 , V_245 , V_246 , 0 ) ;
}
int F_76 ( const char * V_41 , T_3 * V_226 , T_5 V_246 )
{
return F_75 ( V_41 , strlen ( V_41 ) , V_226 , V_246 ) ;
}
int F_77 ( const char * V_41 , T_3 V_220 ,
T_3 * V_226 , T_3 V_233 , T_5 V_242 )
{
return F_73 ( V_41 , V_220 ,
V_226 , V_233 , V_242 , 1 ) ;
}
int F_78 ( const char * V_41 , T_3 V_220 ,
T_3 * V_226 )
{
return F_73 ( V_41 , V_220 ,
V_226 , V_245 , V_247 , 1 ) ;
}
static int F_79 (
struct V_40 * V_41 ,
struct V_40 * V_42 ,
T_1 V_27 ,
struct V_40 * V_248 )
{
char * V_56 = NULL , * V_180 = NULL , * V_34 = NULL ;
T_3 V_249 , V_183 , V_182 ;
if ( F_22 ( V_41 , & V_56 , & V_249 ) )
goto V_114;
if ( F_22 ( V_42 , & V_180 , & V_183 ) )
goto V_114;
if ( F_22 ( V_248 , & V_34 , & V_182 ) )
goto V_114;
F_41 ( V_115 -> V_116 , V_16 , V_117 ,
L_24
L_25
L_26
L_27 ,
V_34 , V_56 , V_180 , F_20 ( & V_1 , V_110 , V_27 - 1 ) ) ;
V_114:
F_6 ( V_56 ) ;
F_6 ( V_180 ) ;
F_6 ( V_34 ) ;
if ( ! V_184 )
return 0 ;
return - V_250 ;
}
static void F_80 ( struct V_1 * V_138 , struct V_40 * V_248 ,
T_3 V_251 , T_3 V_252 , T_1 V_27 ,
const char * V_253 )
{
struct V_254 V_255 ;
struct V_256 * V_257 ;
if ( ! F_13 ( & V_138 -> V_258 , V_252 ) )
return;
V_255 . V_251 = V_251 ;
V_255 . V_252 = V_252 ;
V_255 . V_27 = V_27 ;
V_255 . V_15 = V_253 ;
V_257 = F_69 ( V_138 -> V_254 , & V_255 ) ;
if ( V_257 )
V_248 -> type = V_257 -> V_257 ;
}
static int F_81 ( T_3 V_215 ,
T_3 V_216 ,
T_1 V_189 ,
T_3 V_135 ,
const char * V_253 ,
T_3 * V_259 ,
bool V_260 )
{
struct V_100 * V_261 = NULL ;
struct V_40 * V_41 = NULL , * V_42 = NULL , V_248 ;
struct V_262 * V_263 = NULL ;
struct V_148 V_149 ;
struct V_264 * V_265 ;
struct V_131 * V_132 ;
T_1 V_27 ;
int V_190 = 0 ;
bool V_266 ;
if ( ! V_191 ) {
switch ( V_189 ) {
case V_267 :
* V_259 = V_215 ;
break;
default:
* V_259 = V_216 ;
break;
}
goto V_114;
}
F_68 ( & V_248 ) ;
F_43 ( & V_192 ) ;
if ( V_260 ) {
V_27 = F_7 ( V_189 ) ;
V_266 = F_82 ( V_189 ) ;
} else {
V_27 = V_189 ;
V_266 = F_82 ( F_8 ( V_27 ) ) ;
}
V_41 = F_44 ( & V_193 , V_215 ) ;
if ( ! V_41 ) {
F_4 ( V_194 L_16 ,
V_195 , V_215 ) ;
V_190 = - V_14 ;
goto V_230;
}
V_42 = F_44 ( & V_193 , V_216 ) ;
if ( ! V_42 ) {
F_4 ( V_194 L_16 ,
V_195 , V_216 ) ;
V_190 = - V_14 ;
goto V_230;
}
if ( V_27 && V_27 <= V_1 . V_157 . V_158 )
V_261 = V_1 . V_111 [ V_27 - 1 ] ;
switch ( V_135 ) {
case V_268 :
case V_269 :
if ( V_261 && V_261 -> V_270 == V_271 ) {
V_248 . V_67 = V_42 -> V_67 ;
} else {
V_248 . V_67 = V_41 -> V_67 ;
}
break;
case V_272 :
V_248 . V_67 = V_42 -> V_67 ;
break;
}
if ( V_261 && V_261 -> V_273 == V_274 ) {
V_248 . V_70 = V_41 -> V_70 ;
} else if ( V_261 && V_261 -> V_273 == V_271 ) {
V_248 . V_70 = V_42 -> V_70 ;
} else {
if ( ( V_27 == V_1 . V_174 ) || ( V_266 == true ) )
V_248 . V_70 = V_41 -> V_70 ;
else
V_248 . V_70 = V_275 ;
}
if ( V_261 && V_261 -> V_276 == V_274 ) {
V_248 . type = V_41 -> type ;
} else if ( V_261 && V_261 -> V_276 == V_271 ) {
V_248 . type = V_42 -> type ;
} else {
if ( ( V_27 == V_1 . V_174 ) || ( V_266 == true ) ) {
V_248 . type = V_41 -> type ;
} else {
V_248 . type = V_42 -> type ;
}
}
V_149 . V_164 = V_41 -> type ;
V_149 . V_165 = V_42 -> type ;
V_149 . V_160 = V_27 ;
V_149 . V_135 = V_135 ;
V_265 = F_83 ( & V_1 . V_166 , & V_149 ) ;
if ( ! V_265 ) {
V_132 = F_37 ( & V_1 . V_171 , & V_149 ) ;
for (; V_132 ; V_132 = F_38 ( V_132 , V_135 ) ) {
if ( V_132 -> V_141 . V_135 & V_277 ) {
V_265 = & V_132 -> V_133 ;
break;
}
}
}
if ( V_265 ) {
V_248 . type = V_265 -> V_134 . V_168 ;
}
if ( V_253 )
F_80 ( & V_1 , & V_248 , V_41 -> type ,
V_42 -> type , V_27 , V_253 ) ;
if ( V_135 & V_268 ) {
for ( V_263 = V_1 . V_278 ; V_263 ; V_263 = V_263 -> V_59 ) {
if ( ( V_263 -> V_70 == V_41 -> V_70 ) &&
( V_263 -> type == V_42 -> type ) &&
( V_263 -> V_27 == V_27 ) ) {
V_248 . V_70 = V_263 -> V_176 ;
break;
}
}
}
V_190 = F_84 ( V_41 , V_42 , V_27 , V_135 ,
& V_248 , V_266 ) ;
if ( V_190 )
goto V_230;
if ( ! F_71 ( & V_1 , & V_248 ) ) {
V_190 = F_79 ( V_41 ,
V_42 ,
V_27 ,
& V_248 ) ;
if ( V_190 )
goto V_230;
}
V_190 = F_74 ( & V_193 , & V_248 , V_259 ) ;
V_230:
F_45 ( & V_192 ) ;
F_72 ( & V_248 ) ;
V_114:
return V_190 ;
}
int F_85 ( T_3 V_215 , T_3 V_216 , T_1 V_27 ,
const struct V_279 * V_279 , T_3 * V_259 )
{
return F_81 ( V_215 , V_216 , V_27 , V_268 ,
V_279 ? V_279 -> V_15 : NULL , V_259 , true ) ;
}
int F_86 ( T_3 V_215 , T_3 V_216 , T_1 V_27 ,
const char * V_253 , T_3 * V_259 )
{
return F_81 ( V_215 , V_216 , V_27 , V_268 ,
V_253 , V_259 , false ) ;
}
int F_87 ( T_3 V_215 ,
T_3 V_216 ,
T_1 V_27 ,
T_3 * V_259 )
{
return F_81 ( V_215 , V_216 , V_27 , V_272 , NULL ,
V_259 , false ) ;
}
int F_88 ( T_3 V_215 ,
T_3 V_216 ,
T_1 V_27 ,
T_3 * V_259 )
{
return F_81 ( V_215 , V_216 , V_27 , V_269 , NULL ,
V_259 , false ) ;
}
static int F_89 ( T_3 V_226 ,
struct V_40 * V_40 ,
void * V_280 )
{
struct V_193 * V_56 = V_280 ;
if ( V_226 > V_227 )
return F_90 ( V_56 , V_226 , V_40 ) ;
else
return 0 ;
}
static inline int F_91 ( struct V_40 * V_40 )
{
char * V_56 ;
T_3 V_143 ;
if ( V_184 )
return - V_14 ;
if ( ! F_22 ( V_40 , & V_56 , & V_143 ) ) {
F_4 ( V_159 L_28 , V_56 ) ;
F_6 ( V_56 ) ;
}
return 0 ;
}
static int F_92 ( T_3 V_141 ,
struct V_40 * V_48 ,
void * V_138 )
{
struct V_281 * args ;
struct V_40 V_237 ;
struct V_177 * V_282 ;
struct V_283 * V_78 ;
struct V_49 * V_70 ;
struct V_123 * V_234 ;
struct V_235 * V_236 ;
char * V_56 ;
T_3 V_143 ;
int V_190 = 0 ;
if ( V_141 <= V_227 )
goto V_114;
args = V_138 ;
if ( V_48 -> V_222 ) {
struct V_40 V_232 ;
V_190 = - V_17 ;
V_56 = F_57 ( V_48 -> V_222 , V_247 ) ;
if ( ! V_56 )
goto V_114;
V_190 = F_67 ( args -> V_284 , NULL , V_56 ,
V_48 -> V_143 , & V_232 , V_245 ) ;
F_6 ( V_56 ) ;
if ( ! V_190 ) {
F_4 ( V_22 L_29 ,
V_48 -> V_222 ) ;
F_6 ( V_48 -> V_222 ) ;
memcpy ( V_48 , & V_232 , sizeof( * V_48 ) ) ;
goto V_114;
} else if ( V_190 == - V_14 ) {
V_190 = 0 ;
goto V_114;
} else {
F_4 ( V_194 L_30 ,
V_48 -> V_222 , - V_190 ) ;
goto V_114;
}
}
V_190 = F_93 ( & V_237 , V_48 ) ;
if ( V_190 )
goto V_114;
V_190 = - V_14 ;
V_236 = F_69 ( args -> V_284 -> V_238 . V_113 ,
F_20 ( args -> V_285 , V_223 , V_48 -> V_67 - 1 ) ) ;
if ( ! V_236 )
goto V_286;
V_48 -> V_67 = V_236 -> V_21 ;
V_190 = - V_14 ;
V_70 = F_69 ( args -> V_284 -> V_239 . V_113 ,
F_20 ( args -> V_285 , V_224 , V_48 -> V_70 - 1 ) ) ;
if ( ! V_70 )
goto V_286;
V_48 -> V_70 = V_70 -> V_21 ;
V_190 = - V_14 ;
V_234 = F_69 ( args -> V_284 -> V_240 . V_113 ,
F_20 ( args -> V_285 , V_225 , V_48 -> type - 1 ) ) ;
if ( ! V_234 )
goto V_286;
V_48 -> type = V_234 -> V_21 ;
if ( args -> V_285 -> V_39 && args -> V_284 -> V_39 ) {
V_190 = F_94 ( args -> V_285 , args -> V_284 , V_48 ) ;
if ( V_190 )
goto V_286;
} else if ( args -> V_285 -> V_39 && ! args -> V_284 -> V_39 ) {
F_95 ( V_48 ) ;
} else if ( ! args -> V_285 -> V_39 && args -> V_284 -> V_39 ) {
V_282 = args -> V_284 -> V_287 [ V_288 ] ;
while ( V_282 && V_282 -> V_226 [ 0 ] != V_289 )
V_282 = V_282 -> V_59 ;
V_190 = - V_14 ;
if ( ! V_282 ) {
F_4 ( V_194 L_31
L_32 ) ;
goto V_286;
}
V_78 = & V_282 -> V_40 [ 0 ] . V_78 ;
V_190 = F_96 ( V_48 , V_78 ) ;
if ( V_190 )
goto V_286;
}
if ( ! F_71 ( args -> V_284 , V_48 ) ) {
V_190 = F_91 ( & V_237 ) ;
if ( V_190 )
goto V_286;
}
F_72 ( & V_237 ) ;
V_190 = 0 ;
V_114:
return V_190 ;
V_286:
V_190 = F_22 ( & V_237 , & V_56 , & V_143 ) ;
if ( V_190 )
return V_190 ;
F_72 ( & V_237 ) ;
F_72 ( V_48 ) ;
V_48 -> V_222 = V_56 ;
V_48 -> V_143 = V_143 ;
F_4 ( V_22 L_33 ,
V_48 -> V_222 ) ;
V_190 = 0 ;
goto V_114;
}
static void F_97 ( void )
{
unsigned int V_10 ;
struct V_154 * V_132 ;
V_290 = F_13 ( & V_1 . V_291 ,
V_292 ) ;
V_293 = F_13 ( & V_1 . V_291 ,
V_294 ) ;
V_295 = F_13 ( & V_1 . V_291 ,
V_296 ) ;
V_297 = F_13 ( & V_1 . V_291 ,
V_298 ) ;
V_299 =
F_13 ( & V_1 . V_291 ,
V_300 ) ;
for ( V_10 = 0 ; V_10 < F_31 ( V_301 ) ; V_10 ++ )
F_98 ( L_34 ,
V_301 [ V_10 ] ,
F_13 ( & V_1 . V_291 , V_10 ) ) ;
F_36 (&policydb.policycaps, node, i) {
if ( V_10 >= F_31 ( V_301 ) )
F_98 ( L_35 ,
V_10 ) ;
}
}
int F_99 ( void * V_168 , T_2 V_143 )
{
struct V_1 * V_302 , * V_303 ;
struct V_193 V_304 , V_305 ;
struct V_5 * V_306 , * V_4 = NULL ;
struct V_281 args ;
T_3 V_203 ;
T_1 V_307 ;
int V_190 = 0 ;
struct V_308 V_309 = { V_168 , V_143 } , * V_310 = & V_309 ;
V_302 = F_100 ( 2 * sizeof( * V_302 ) , V_247 ) ;
if ( ! V_302 ) {
V_190 = - V_17 ;
goto V_114;
}
V_303 = V_302 + 1 ;
if ( ! V_191 ) {
F_101 () ;
F_102 () ;
V_190 = F_103 ( & V_1 , V_310 ) ;
if ( V_190 ) {
F_104 () ;
F_105 () ;
goto V_114;
}
V_1 . V_143 = V_143 ;
V_190 = F_1 ( & V_1 , V_311 ,
& V_29 ,
& V_28 ) ;
if ( V_190 ) {
F_106 ( & V_1 ) ;
F_104 () ;
F_105 () ;
goto V_114;
}
V_190 = F_107 ( & V_1 , & V_193 ) ;
if ( V_190 ) {
F_106 ( & V_1 ) ;
F_104 () ;
F_105 () ;
goto V_114;
}
F_97 () ;
V_191 = 1 ;
V_203 = ++ V_204 ;
F_108 () ;
F_109 ( V_203 ) ;
F_110 ( V_203 ) ;
F_111 ( V_203 ) ;
F_112 () ;
F_113 () ;
goto V_114;
}
#if 0
sidtab_hash_eval(&sidtab, "sids");
#endif
V_190 = F_103 ( V_303 , V_310 ) ;
if ( V_190 )
goto V_114;
V_303 -> V_143 = V_143 ;
if ( V_1 . V_39 && ! V_303 -> V_39 )
F_4 ( V_22 L_36 ) ;
else if ( ! V_1 . V_39 && V_303 -> V_39 )
F_4 ( V_22 L_37 ) ;
V_190 = F_107 ( V_303 , & V_305 ) ;
if ( V_190 ) {
F_4 ( V_194 L_38 ) ;
F_106 ( V_303 ) ;
goto V_114;
}
V_190 = F_1 ( V_303 , V_311 , & V_4 , & V_307 ) ;
if ( V_190 )
goto V_24;
V_190 = F_114 ( V_303 ) ;
if ( V_190 ) {
F_4 ( V_194 L_39 ) ;
goto V_24;
}
F_115 ( & V_193 ) ;
V_190 = F_116 ( & V_193 , F_89 , & V_305 ) ;
if ( V_190 )
goto V_24;
args . V_285 = & V_1 ;
args . V_284 = V_303 ;
V_190 = F_116 ( & V_305 , F_92 , & args ) ;
if ( V_190 ) {
F_4 ( V_194 L_40
L_41
L_42 ) ;
goto V_24;
}
memcpy ( V_302 , & V_1 , sizeof( V_1 ) ) ;
F_117 ( & V_304 , & V_193 ) ;
F_118 ( & V_192 ) ;
memcpy ( & V_1 , V_303 , sizeof( V_1 ) ) ;
F_117 ( & V_193 , & V_305 ) ;
F_97 () ;
V_306 = V_29 ;
V_29 = V_4 ;
V_28 = V_307 ;
V_203 = ++ V_204 ;
F_119 ( & V_192 ) ;
F_106 ( V_302 ) ;
F_120 ( & V_304 ) ;
F_6 ( V_306 ) ;
F_109 ( V_203 ) ;
F_110 ( V_203 ) ;
F_111 ( V_203 ) ;
F_112 () ;
F_113 () ;
V_190 = 0 ;
goto V_114;
V_24:
F_6 ( V_4 ) ;
F_120 ( & V_305 ) ;
F_106 ( V_303 ) ;
V_114:
F_6 ( V_302 ) ;
return V_190 ;
}
T_2 F_121 ( void )
{
T_2 V_143 ;
F_43 ( & V_192 ) ;
V_143 = V_1 . V_143 ;
F_45 ( & V_192 ) ;
return V_143 ;
}
int F_122 ( T_4 V_312 , T_1 V_313 , T_3 * V_259 )
{
struct V_177 * V_48 ;
int V_190 = 0 ;
F_43 ( & V_192 ) ;
V_48 = V_1 . V_287 [ V_314 ] ;
while ( V_48 ) {
if ( V_48 -> V_134 . V_313 . V_312 == V_312 &&
V_48 -> V_134 . V_313 . V_315 <= V_313 &&
V_48 -> V_134 . V_313 . V_316 >= V_313 )
break;
V_48 = V_48 -> V_59 ;
}
if ( V_48 ) {
if ( ! V_48 -> V_226 [ 0 ] ) {
V_190 = F_74 ( & V_193 ,
& V_48 -> V_40 [ 0 ] ,
& V_48 -> V_226 [ 0 ] ) ;
if ( V_190 )
goto V_114;
}
* V_259 = V_48 -> V_226 [ 0 ] ;
} else {
* V_259 = V_317 ;
}
V_114:
F_45 ( & V_192 ) ;
return V_190 ;
}
int F_123 ( T_6 V_318 , T_1 V_319 , T_3 * V_259 )
{
struct V_177 * V_48 ;
int V_190 = 0 ;
F_43 ( & V_192 ) ;
V_48 = V_1 . V_287 [ V_320 ] ;
while ( V_48 ) {
if ( V_48 -> V_134 . V_321 . V_322 <= V_319 &&
V_48 -> V_134 . V_321 . V_323 >= V_319 &&
V_48 -> V_134 . V_321 . V_318 == V_318 )
break;
V_48 = V_48 -> V_59 ;
}
if ( V_48 ) {
if ( ! V_48 -> V_226 [ 0 ] ) {
V_190 = F_74 ( & V_193 ,
& V_48 -> V_40 [ 0 ] ,
& V_48 -> V_226 [ 0 ] ) ;
if ( V_190 )
goto V_114;
}
* V_259 = V_48 -> V_226 [ 0 ] ;
} else
* V_259 = V_289 ;
V_114:
F_45 ( & V_192 ) ;
return V_190 ;
}
int F_124 ( const char * V_324 , T_4 V_325 , T_3 * V_259 )
{
struct V_177 * V_48 ;
int V_190 = 0 ;
F_43 ( & V_192 ) ;
V_48 = V_1 . V_287 [ V_326 ] ;
while ( V_48 ) {
if ( V_48 -> V_134 . V_327 . V_313 == V_325 &&
! strncmp ( V_48 -> V_134 . V_327 . V_324 ,
V_324 ,
V_328 ) )
break;
V_48 = V_48 -> V_59 ;
}
if ( V_48 ) {
if ( ! V_48 -> V_226 [ 0 ] ) {
V_190 = F_74 ( & V_193 ,
& V_48 -> V_40 [ 0 ] ,
& V_48 -> V_226 [ 0 ] ) ;
if ( V_190 )
goto V_114;
}
* V_259 = V_48 -> V_226 [ 0 ] ;
} else
* V_259 = V_289 ;
V_114:
F_45 ( & V_192 ) ;
return V_190 ;
}
int F_125 ( char * V_15 , T_3 * V_329 )
{
int V_190 = 0 ;
struct V_177 * V_48 ;
F_43 ( & V_192 ) ;
V_48 = V_1 . V_287 [ V_330 ] ;
while ( V_48 ) {
if ( strcmp ( V_15 , V_48 -> V_134 . V_15 ) == 0 )
break;
V_48 = V_48 -> V_59 ;
}
if ( V_48 ) {
if ( ! V_48 -> V_226 [ 0 ] || ! V_48 -> V_226 [ 1 ] ) {
V_190 = F_74 ( & V_193 ,
& V_48 -> V_40 [ 0 ] ,
& V_48 -> V_226 [ 0 ] ) ;
if ( V_190 )
goto V_114;
V_190 = F_74 ( & V_193 ,
& V_48 -> V_40 [ 1 ] ,
& V_48 -> V_226 [ 1 ] ) ;
if ( V_190 )
goto V_114;
}
* V_329 = V_48 -> V_226 [ 0 ] ;
} else
* V_329 = V_331 ;
V_114:
F_45 ( & V_192 ) ;
return V_190 ;
}
static int F_126 ( T_3 * V_332 , T_3 * V_333 , T_3 * V_118 )
{
int V_10 , V_334 = 0 ;
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ )
if ( V_333 [ V_10 ] != ( V_332 [ V_10 ] & V_118 [ V_10 ] ) ) {
V_334 = 1 ;
break;
}
return ! V_334 ;
}
int F_127 ( T_1 V_335 ,
void * V_336 ,
T_3 V_337 ,
T_3 * V_259 )
{
int V_190 ;
struct V_177 * V_48 ;
F_43 ( & V_192 ) ;
switch ( V_335 ) {
case V_338 : {
T_3 V_333 ;
V_190 = - V_14 ;
if ( V_337 != sizeof( T_3 ) )
goto V_114;
V_333 = * ( ( T_3 * ) V_336 ) ;
V_48 = V_1 . V_287 [ V_339 ] ;
while ( V_48 ) {
if ( V_48 -> V_134 . V_132 . V_333 == ( V_333 & V_48 -> V_134 . V_132 . V_118 ) )
break;
V_48 = V_48 -> V_59 ;
}
break;
}
case V_340 :
V_190 = - V_14 ;
if ( V_337 != sizeof( T_6 ) * 2 )
goto V_114;
V_48 = V_1 . V_287 [ V_341 ] ;
while ( V_48 ) {
if ( F_126 ( V_336 , V_48 -> V_134 . V_342 . V_333 ,
V_48 -> V_134 . V_342 . V_118 ) )
break;
V_48 = V_48 -> V_59 ;
}
break;
default:
V_190 = 0 ;
* V_259 = V_343 ;
goto V_114;
}
if ( V_48 ) {
if ( ! V_48 -> V_226 [ 0 ] ) {
V_190 = F_74 ( & V_193 ,
& V_48 -> V_40 [ 0 ] ,
& V_48 -> V_226 [ 0 ] ) ;
if ( V_190 )
goto V_114;
}
* V_259 = V_48 -> V_226 [ 0 ] ;
} else {
* V_259 = V_343 ;
}
V_190 = 0 ;
V_114:
F_45 ( & V_192 ) ;
return V_190 ;
}
int F_128 ( T_3 V_344 ,
char * V_345 ,
T_3 * * V_346 ,
T_3 * V_347 )
{
struct V_40 * V_348 , V_349 ;
T_3 * V_350 = NULL , * V_351 , V_226 ;
T_3 V_352 = 0 , V_353 = V_354 ;
struct V_235 * V_67 ;
struct V_49 * V_70 ;
struct V_154 * V_355 , * V_156 ;
int V_190 = 0 , V_10 , V_11 ;
* V_346 = NULL ;
* V_347 = 0 ;
if ( ! V_191 )
goto V_114;
F_43 ( & V_192 ) ;
F_68 ( & V_349 ) ;
V_190 = - V_14 ;
V_348 = F_44 ( & V_193 , V_344 ) ;
if ( ! V_348 )
goto V_230;
V_190 = - V_14 ;
V_67 = F_69 ( V_1 . V_238 . V_113 , V_345 ) ;
if ( ! V_67 )
goto V_230;
V_349 . V_67 = V_67 -> V_21 ;
V_190 = - V_17 ;
V_350 = F_2 ( V_353 , sizeof( * V_350 ) , V_16 ) ;
if ( ! V_350 )
goto V_230;
F_36 (&user->roles, rnode, i) {
V_70 = V_1 . V_71 [ V_10 ] ;
V_349 . V_70 = V_10 + 1 ;
F_36 (&role->types, tnode, j) {
V_349 . type = V_11 + 1 ;
if ( F_129 ( V_348 , V_67 , & V_349 ) )
continue;
V_190 = F_74 ( & V_193 , & V_349 , & V_226 ) ;
if ( V_190 )
goto V_230;
if ( V_352 < V_353 ) {
V_350 [ V_352 ++ ] = V_226 ;
} else {
V_190 = - V_17 ;
V_353 += V_354 ;
V_351 = F_2 ( V_353 , sizeof( * V_351 ) , V_16 ) ;
if ( ! V_351 )
goto V_230;
memcpy ( V_351 , V_350 , V_352 * sizeof( * V_351 ) ) ;
F_6 ( V_350 ) ;
V_350 = V_351 ;
V_350 [ V_352 ++ ] = V_226 ;
}
}
}
V_190 = 0 ;
V_230:
F_45 ( & V_192 ) ;
if ( V_190 || ! V_352 ) {
F_6 ( V_350 ) ;
goto V_114;
}
V_190 = - V_17 ;
V_351 = F_2 ( V_352 , sizeof( * V_351 ) , V_247 ) ;
if ( ! V_351 ) {
F_6 ( V_350 ) ;
goto V_114;
}
for ( V_10 = 0 , V_11 = 0 ; V_10 < V_352 ; V_10 ++ ) {
struct V_32 V_356 ;
V_190 = F_130 ( V_344 , V_350 [ V_10 ] ,
V_267 ,
V_357 , V_358 ,
& V_356 ) ;
if ( ! V_190 )
V_351 [ V_11 ++ ] = V_350 [ V_10 ] ;
F_131 () ;
}
V_190 = 0 ;
F_6 ( V_350 ) ;
* V_346 = V_351 ;
* V_347 = V_11 ;
V_114:
return V_190 ;
}
static inline int F_132 ( const char * V_359 ,
char * V_360 ,
T_1 V_361 ,
T_3 * V_226 )
{
int V_143 ;
T_1 V_362 ;
struct V_363 * V_363 ;
struct V_177 * V_48 ;
int V_190 , V_364 = 0 ;
while ( V_360 [ 0 ] == '/' && V_360 [ 1 ] == '/' )
V_360 ++ ;
V_362 = F_7 ( V_361 ) ;
* V_226 = V_289 ;
for ( V_363 = V_1 . V_363 ; V_363 ; V_363 = V_363 -> V_59 ) {
V_364 = strcmp ( V_359 , V_363 -> V_359 ) ;
if ( V_364 <= 0 )
break;
}
V_190 = - V_365 ;
if ( ! V_363 || V_364 )
goto V_114;
for ( V_48 = V_363 -> V_366 ; V_48 ; V_48 = V_48 -> V_59 ) {
V_143 = strlen ( V_48 -> V_134 . V_15 ) ;
if ( ( ! V_48 -> V_367 . V_362 || V_362 == V_48 -> V_367 . V_362 ) &&
( strncmp ( V_48 -> V_134 . V_15 , V_360 , V_143 ) == 0 ) )
break;
}
V_190 = - V_365 ;
if ( ! V_48 )
goto V_114;
if ( ! V_48 -> V_226 [ 0 ] ) {
V_190 = F_74 ( & V_193 , & V_48 -> V_40 [ 0 ] , & V_48 -> V_226 [ 0 ] ) ;
if ( V_190 )
goto V_114;
}
* V_226 = V_48 -> V_226 [ 0 ] ;
V_190 = 0 ;
V_114:
return V_190 ;
}
int F_133 ( const char * V_359 ,
char * V_360 ,
T_1 V_361 ,
T_3 * V_226 )
{
int V_368 ;
F_43 ( & V_192 ) ;
V_368 = F_132 ( V_359 , V_360 , V_361 , V_226 ) ;
F_45 ( & V_192 ) ;
return V_368 ;
}
int F_134 ( struct V_369 * V_370 )
{
int V_190 = 0 ;
struct V_177 * V_48 ;
struct V_371 * V_372 = V_370 -> V_373 ;
const char * V_359 = V_370 -> V_374 -> V_15 ;
F_43 ( & V_192 ) ;
V_48 = V_1 . V_287 [ V_375 ] ;
while ( V_48 ) {
if ( strcmp ( V_359 , V_48 -> V_134 . V_15 ) == 0 )
break;
V_48 = V_48 -> V_59 ;
}
if ( V_48 ) {
V_372 -> V_376 = V_48 -> V_367 . V_376 ;
if ( ! V_48 -> V_226 [ 0 ] ) {
V_190 = F_74 ( & V_193 , & V_48 -> V_40 [ 0 ] ,
& V_48 -> V_226 [ 0 ] ) ;
if ( V_190 )
goto V_114;
}
V_372 -> V_226 = V_48 -> V_226 [ 0 ] ;
} else {
V_190 = F_132 ( V_359 , L_43 , V_377 ,
& V_372 -> V_226 ) ;
if ( V_190 ) {
V_372 -> V_376 = V_378 ;
V_190 = 0 ;
} else {
V_372 -> V_376 = V_379 ;
}
}
V_114:
F_45 ( & V_192 ) ;
return V_190 ;
}
int F_135 ( int * V_143 , char * * * V_91 , int * * V_380 )
{
int V_10 , V_190 ;
F_43 ( & V_192 ) ;
* V_91 = NULL ;
* V_380 = NULL ;
V_190 = 0 ;
* V_143 = V_1 . V_381 . V_158 ;
if ( ! * V_143 )
goto V_114;
V_190 = - V_17 ;
* V_91 = F_2 ( * V_143 , sizeof( char * ) , V_16 ) ;
if ( ! * V_91 )
goto V_24;
V_190 = - V_17 ;
* V_380 = F_2 ( * V_143 , sizeof( int ) , V_16 ) ;
if ( ! * V_380 )
goto V_24;
for ( V_10 = 0 ; V_10 < * V_143 ; V_10 ++ ) {
( * V_380 ) [ V_10 ] = V_1 . V_382 [ V_10 ] -> V_383 ;
V_190 = - V_17 ;
( * V_91 ) [ V_10 ] = F_57 ( F_20 ( & V_1 , V_384 , V_10 ) , V_16 ) ;
if ( ! ( * V_91 ) [ V_10 ] )
goto V_24;
}
V_190 = 0 ;
V_114:
F_45 ( & V_192 ) ;
return V_190 ;
V_24:
if ( * V_91 ) {
for ( V_10 = 0 ; V_10 < * V_143 ; V_10 ++ )
F_6 ( ( * V_91 ) [ V_10 ] ) ;
}
F_6 ( * V_380 ) ;
goto V_114;
}
int F_136 ( int V_143 , int * V_380 )
{
int V_10 , V_190 ;
int V_385 , V_203 = 0 ;
struct V_386 * V_387 ;
F_118 ( & V_192 ) ;
V_190 = - V_388 ;
V_385 = V_1 . V_381 . V_158 ;
if ( V_143 != V_385 )
goto V_114;
for ( V_10 = 0 ; V_10 < V_143 ; V_10 ++ ) {
if ( ! ! V_380 [ V_10 ] != V_1 . V_382 [ V_10 ] -> V_383 ) {
F_41 ( V_115 -> V_116 , V_16 ,
V_389 ,
L_44 ,
F_20 ( & V_1 , V_384 , V_10 ) ,
! ! V_380 [ V_10 ] ,
V_1 . V_382 [ V_10 ] -> V_383 ,
F_137 ( & V_390 , F_138 ( V_115 ) ) ,
F_139 ( V_115 ) ) ;
}
if ( V_380 [ V_10 ] )
V_1 . V_382 [ V_10 ] -> V_383 = 1 ;
else
V_1 . V_382 [ V_10 ] -> V_383 = 0 ;
}
for ( V_387 = V_1 . V_391 ; V_387 ; V_387 = V_387 -> V_59 ) {
V_190 = F_140 ( & V_1 , V_387 ) ;
if ( V_190 )
goto V_114;
}
V_203 = ++ V_204 ;
V_190 = 0 ;
V_114:
F_119 ( & V_192 ) ;
if ( ! V_190 ) {
F_109 ( V_203 ) ;
F_110 ( V_203 ) ;
F_111 ( V_203 ) ;
F_113 () ;
}
return V_190 ;
}
int F_141 ( int V_107 )
{
int V_190 ;
int V_143 ;
F_43 ( & V_192 ) ;
V_190 = - V_388 ;
V_143 = V_1 . V_381 . V_158 ;
if ( V_107 >= V_143 )
goto V_114;
V_190 = V_1 . V_382 [ V_107 ] -> V_383 ;
V_114:
F_45 ( & V_192 ) ;
return V_190 ;
}
static int F_114 ( struct V_1 * V_138 )
{
int V_190 , V_392 = 0 , * V_393 = NULL , V_10 ;
char * * V_394 = NULL ;
struct V_395 * V_396 ;
struct V_386 * V_387 ;
V_190 = F_135 ( & V_392 , & V_394 , & V_393 ) ;
if ( V_190 )
goto V_114;
for ( V_10 = 0 ; V_10 < V_392 ; V_10 ++ ) {
V_396 = F_69 ( V_138 -> V_381 . V_113 , V_394 [ V_10 ] ) ;
if ( V_396 )
V_396 -> V_383 = V_393 [ V_10 ] ;
}
for ( V_387 = V_138 -> V_391 ; V_387 ; V_387 = V_387 -> V_59 ) {
V_190 = F_140 ( V_138 , V_387 ) ;
if ( V_190 )
goto V_114;
}
V_114:
if ( V_394 ) {
for ( V_10 = 0 ; V_10 < V_392 ; V_10 ++ )
F_6 ( V_394 [ V_10 ] ) ;
}
F_6 ( V_394 ) ;
F_6 ( V_393 ) ;
return V_190 ;
}
int F_142 ( T_3 V_226 , T_3 V_397 , T_3 * V_198 )
{
struct V_40 * V_398 ;
struct V_40 * V_399 ;
struct V_40 V_400 ;
char * V_56 ;
T_3 V_143 ;
int V_190 ;
V_190 = 0 ;
if ( ! V_191 || ! V_1 . V_39 ) {
* V_198 = V_226 ;
goto V_114;
}
F_68 ( & V_400 ) ;
F_43 ( & V_192 ) ;
V_190 = - V_14 ;
V_398 = F_44 ( & V_193 , V_226 ) ;
if ( ! V_398 ) {
F_4 ( V_194 L_16 ,
V_195 , V_226 ) ;
goto V_230;
}
V_190 = - V_14 ;
V_399 = F_44 ( & V_193 , V_397 ) ;
if ( ! V_399 ) {
F_4 ( V_194 L_16 ,
V_195 , V_397 ) ;
goto V_230;
}
V_400 . V_67 = V_398 -> V_67 ;
V_400 . V_70 = V_398 -> V_70 ;
V_400 . type = V_398 -> type ;
V_190 = F_143 ( & V_400 , V_399 ) ;
if ( V_190 )
goto V_230;
if ( ! F_71 ( & V_1 , & V_400 ) ) {
V_190 = F_91 ( & V_400 ) ;
if ( V_190 ) {
if ( ! F_22 ( & V_400 , & V_56 , & V_143 ) ) {
F_41 ( V_115 -> V_116 ,
V_16 , V_117 ,
L_45
L_46 , V_56 ) ;
F_6 ( V_56 ) ;
}
goto V_230;
}
}
V_190 = F_74 ( & V_193 , & V_400 , V_198 ) ;
V_230:
F_45 ( & V_192 ) ;
F_72 ( & V_400 ) ;
V_114:
return V_190 ;
}
int F_144 ( T_3 V_401 , T_3 V_402 ,
T_3 V_403 ,
T_3 * V_404 )
{
int V_190 ;
struct V_40 * V_405 ;
struct V_40 * V_406 ;
* V_404 = V_245 ;
if ( V_403 == V_245 ) {
* V_404 = V_401 ;
return 0 ;
}
if ( V_401 == V_245 || V_402 == V_407 ) {
* V_404 = V_403 ;
return 0 ;
}
if ( ! V_1 . V_39 )
return 0 ;
F_43 ( & V_192 ) ;
V_190 = - V_14 ;
V_405 = F_44 ( & V_193 , V_401 ) ;
if ( ! V_405 ) {
F_4 ( V_194 L_16 ,
V_195 , V_401 ) ;
goto V_114;
}
V_190 = - V_14 ;
V_406 = F_44 ( & V_193 , V_403 ) ;
if ( ! V_406 ) {
F_4 ( V_194 L_16 ,
V_195 , V_403 ) ;
goto V_114;
}
V_190 = ( F_145 ( V_405 , V_406 ) ? 0 : - V_250 ) ;
if ( V_190 )
goto V_114;
* V_404 = V_403 ;
V_114:
F_45 ( & V_192 ) ;
return V_190 ;
}
static int F_146 ( void * V_12 , void * V_92 , void * args )
{
struct V_100 * V_133 = V_92 ;
char * V_15 = V_12 , * * V_408 = args ;
int V_21 = V_133 -> V_21 - 1 ;
V_408 [ V_21 ] = F_57 ( V_15 , V_16 ) ;
if ( ! V_408 [ V_21 ] )
return - V_17 ;
return 0 ;
}
int F_147 ( char * * * V_408 , int * V_409 )
{
int V_190 ;
F_43 ( & V_192 ) ;
V_190 = - V_17 ;
* V_409 = V_1 . V_157 . V_158 ;
* V_408 = F_2 ( * V_409 , sizeof( * * V_408 ) , V_16 ) ;
if ( ! * V_408 )
goto V_114;
V_190 = F_21 ( V_1 . V_157 . V_113 , F_146 ,
* V_408 ) ;
if ( V_190 ) {
int V_10 ;
for ( V_10 = 0 ; V_10 < * V_409 ; V_10 ++ )
F_6 ( ( * V_408 ) [ V_10 ] ) ;
F_6 ( * V_408 ) ;
}
V_114:
F_45 ( & V_192 ) ;
return V_190 ;
}
static int F_148 ( void * V_12 , void * V_92 , void * args )
{
struct V_93 * V_133 = V_92 ;
char * V_15 = V_12 , * * V_25 = args ;
int V_21 = V_133 -> V_21 - 1 ;
V_25 [ V_21 ] = F_57 ( V_15 , V_16 ) ;
if ( ! V_25 [ V_21 ] )
return - V_17 ;
return 0 ;
}
int F_149 ( char * V_410 , char * * * V_25 , int * V_411 )
{
int V_190 , V_10 ;
struct V_100 * V_412 ;
F_43 ( & V_192 ) ;
V_190 = - V_14 ;
V_412 = F_69 ( V_1 . V_157 . V_113 , V_410 ) ;
if ( ! V_412 ) {
F_4 ( V_194 L_47 ,
V_195 , V_410 ) ;
goto V_114;
}
V_190 = - V_17 ;
* V_411 = V_412 -> V_96 . V_158 ;
* V_25 = F_2 ( * V_411 , sizeof( * * V_25 ) , V_16 ) ;
if ( ! * V_25 )
goto V_114;
if ( V_412 -> V_112 ) {
V_190 = F_21 ( V_412 -> V_112 -> V_96 . V_113 ,
F_148 , * V_25 ) ;
if ( V_190 )
goto V_24;
}
V_190 = F_21 ( V_412 -> V_96 . V_113 , F_148 ,
* V_25 ) ;
if ( V_190 )
goto V_24;
V_114:
F_45 ( & V_192 ) ;
return V_190 ;
V_24:
F_45 ( & V_192 ) ;
for ( V_10 = 0 ; V_10 < * V_411 ; V_10 ++ )
F_6 ( ( * V_25 ) [ V_10 ] ) ;
F_6 ( * V_25 ) ;
return V_190 ;
}
int F_150 ( void )
{
return V_1 . V_23 ;
}
int F_151 ( void )
{
return V_1 . V_26 ;
}
int F_152 ( unsigned int V_413 )
{
int V_190 ;
F_43 ( & V_192 ) ;
V_190 = F_13 ( & V_1 . V_291 , V_413 ) ;
F_45 ( & V_192 ) ;
return V_190 ;
}
void F_153 ( void * V_414 )
{
struct V_415 * V_416 = V_414 ;
if ( V_416 ) {
F_72 ( & V_416 -> V_417 ) ;
F_6 ( V_416 ) ;
}
}
int F_154 ( T_3 V_418 , T_3 V_72 , char * V_419 , void * * V_414 )
{
struct V_415 * V_420 ;
struct V_49 * V_421 ;
struct V_123 * V_422 ;
struct V_235 * V_423 ;
struct V_415 * * V_416 = (struct V_415 * * ) V_414 ;
int V_190 = 0 ;
* V_416 = NULL ;
if ( ! V_191 )
return - V_424 ;
switch ( V_418 ) {
case V_425 :
case V_426 :
case V_427 :
case V_428 :
case V_429 :
case V_430 :
if ( V_72 != V_431 && V_72 != V_432 )
return - V_14 ;
break;
case V_433 :
case V_434 :
case V_435 :
case V_436 :
if ( strchr ( V_419 , '-' ) )
return - V_14 ;
break;
default:
return - V_14 ;
}
V_420 = F_100 ( sizeof( struct V_415 ) , V_247 ) ;
if ( ! V_420 )
return - V_17 ;
F_68 ( & V_420 -> V_417 ) ;
F_43 ( & V_192 ) ;
V_420 -> V_437 = V_204 ;
switch ( V_418 ) {
case V_425 :
case V_428 :
V_190 = - V_14 ;
V_423 = F_69 ( V_1 . V_238 . V_113 , V_419 ) ;
if ( ! V_423 )
goto V_114;
V_420 -> V_417 . V_67 = V_423 -> V_21 ;
break;
case V_426 :
case V_429 :
V_190 = - V_14 ;
V_421 = F_69 ( V_1 . V_239 . V_113 , V_419 ) ;
if ( ! V_421 )
goto V_114;
V_420 -> V_417 . V_70 = V_421 -> V_21 ;
break;
case V_427 :
case V_430 :
V_190 = - V_14 ;
V_422 = F_69 ( V_1 . V_240 . V_113 , V_419 ) ;
if ( ! V_422 )
goto V_114;
V_420 -> V_417 . type = V_422 -> V_21 ;
break;
case V_433 :
case V_434 :
case V_435 :
case V_436 :
V_190 = F_155 ( V_419 , & V_420 -> V_417 , V_16 ) ;
if ( V_190 )
goto V_114;
break;
}
V_190 = 0 ;
V_114:
F_45 ( & V_192 ) ;
if ( V_190 ) {
F_153 ( V_420 ) ;
V_420 = NULL ;
}
* V_416 = V_420 ;
return V_190 ;
}
int F_156 ( struct V_438 * V_416 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_416 -> V_439 ; V_10 ++ ) {
struct V_440 * V_441 = & V_416 -> V_442 [ V_10 ] ;
switch ( V_441 -> type ) {
case V_425 :
case V_426 :
case V_427 :
case V_433 :
case V_434 :
case V_428 :
case V_429 :
case V_430 :
case V_435 :
case V_436 :
return 1 ;
}
}
return 0 ;
}
int F_157 ( T_3 V_226 , T_3 V_418 , T_3 V_72 , void * V_414 ,
struct V_116 * V_443 )
{
struct V_40 * V_444 ;
struct V_52 * V_79 ;
struct V_415 * V_416 = V_414 ;
int V_412 = 0 ;
if ( F_33 ( ! V_416 ) ) {
F_158 ( 1 , L_48 ) ;
return - V_365 ;
}
F_43 ( & V_192 ) ;
if ( V_416 -> V_437 < V_204 ) {
V_412 = - V_445 ;
goto V_114;
}
V_444 = F_44 ( & V_193 , V_226 ) ;
if ( F_33 ( ! V_444 ) ) {
F_158 ( 1 , L_49 ,
V_226 ) ;
V_412 = - V_365 ;
goto V_114;
}
switch ( V_418 ) {
case V_425 :
case V_428 :
switch ( V_72 ) {
case V_431 :
V_412 = ( V_444 -> V_67 == V_416 -> V_417 . V_67 ) ;
break;
case V_432 :
V_412 = ( V_444 -> V_67 != V_416 -> V_417 . V_67 ) ;
break;
}
break;
case V_426 :
case V_429 :
switch ( V_72 ) {
case V_431 :
V_412 = ( V_444 -> V_70 == V_416 -> V_417 . V_70 ) ;
break;
case V_432 :
V_412 = ( V_444 -> V_70 != V_416 -> V_417 . V_70 ) ;
break;
}
break;
case V_427 :
case V_430 :
switch ( V_72 ) {
case V_431 :
V_412 = ( V_444 -> type == V_416 -> V_417 . type ) ;
break;
case V_432 :
V_412 = ( V_444 -> type != V_416 -> V_417 . type ) ;
break;
}
break;
case V_433 :
case V_434 :
case V_435 :
case V_436 :
V_79 = ( ( V_418 == V_433 ||
V_418 == V_435 ) ?
& V_444 -> V_78 . V_79 [ 0 ] : & V_444 -> V_78 . V_79 [ 1 ] ) ;
switch ( V_72 ) {
case V_431 :
V_412 = F_14 ( & V_416 -> V_417 . V_78 . V_79 [ 0 ] ,
V_79 ) ;
break;
case V_432 :
V_412 = ! F_14 ( & V_416 -> V_417 . V_78 . V_79 [ 0 ] ,
V_79 ) ;
break;
case V_446 :
V_412 = ( F_15 ( & V_416 -> V_417 . V_78 . V_79 [ 0 ] ,
V_79 ) &&
! F_14 ( & V_416 -> V_417 . V_78 . V_79 [ 0 ] ,
V_79 ) ) ;
break;
case V_447 :
V_412 = F_15 ( & V_416 -> V_417 . V_78 . V_79 [ 0 ] ,
V_79 ) ;
break;
case V_448 :
V_412 = ( F_15 ( V_79 ,
& V_416 -> V_417 . V_78 . V_79 [ 0 ] ) &&
! F_14 ( V_79 ,
& V_416 -> V_417 . V_78 . V_79 [ 0 ] ) ) ;
break;
case V_449 :
V_412 = F_15 ( V_79 ,
& V_416 -> V_417 . V_78 . V_79 [ 0 ] ) ;
break;
}
}
V_114:
F_45 ( & V_192 ) ;
return V_412 ;
}
static int F_159 ( T_3 V_450 )
{
int V_24 = 0 ;
if ( V_450 == V_451 && V_452 )
V_24 = V_452 () ;
return V_24 ;
}
static int T_7 F_160 ( void )
{
int V_24 ;
V_24 = F_161 ( F_159 , V_451 ) ;
if ( V_24 )
F_162 ( L_50 , V_24 ) ;
return V_24 ;
}
static void F_163 ( struct V_453 * V_454 ,
T_3 V_226 )
{
T_3 * V_455 ;
V_455 = F_59 ( sizeof( * V_455 ) , V_16 ) ;
if ( V_455 == NULL )
return;
V_454 -> V_456 = F_164 ( V_16 ) ;
if ( V_454 -> V_456 == NULL ) {
F_6 ( V_455 ) ;
return;
}
* V_455 = V_226 ;
V_454 -> V_456 -> free = F_6 ;
V_454 -> V_456 -> V_168 = V_455 ;
V_454 -> V_205 |= V_457 ;
}
int F_165 ( struct V_453 * V_454 ,
T_3 * V_226 )
{
int V_190 ;
struct V_40 * V_232 ;
struct V_40 V_458 ;
if ( ! V_191 ) {
* V_226 = V_245 ;
return 0 ;
}
F_43 ( & V_192 ) ;
if ( V_454 -> V_205 & V_457 )
* V_226 = * ( T_3 * ) V_454 -> V_456 -> V_168 ;
else if ( V_454 -> V_205 & V_459 )
* V_226 = V_454 -> V_65 . V_460 ;
else if ( V_454 -> V_205 & V_461 ) {
V_190 = - V_462 ;
V_232 = F_44 ( & V_193 , V_463 ) ;
if ( V_232 == NULL )
goto V_114;
F_68 ( & V_458 ) ;
V_458 . V_67 = V_232 -> V_67 ;
V_458 . V_70 = V_232 -> V_70 ;
V_458 . type = V_232 -> type ;
F_166 ( & V_458 , V_454 ) ;
if ( V_454 -> V_205 & V_464 ) {
V_190 = F_167 ( & V_458 , V_454 ) ;
if ( V_190 )
goto V_114;
}
V_190 = - V_462 ;
if ( ! F_168 ( & V_1 , & V_458 ) )
goto V_465;
V_190 = F_74 ( & V_193 , & V_458 , V_226 ) ;
if ( V_190 )
goto V_465;
F_163 ( V_454 , * V_226 ) ;
F_169 ( & V_458 . V_78 . V_79 [ 0 ] . V_466 ) ;
} else
* V_226 = V_245 ;
F_45 ( & V_192 ) ;
return 0 ;
V_465:
F_169 ( & V_458 . V_78 . V_79 [ 0 ] . V_466 ) ;
V_114:
F_45 ( & V_192 ) ;
return V_190 ;
}
int F_170 ( T_3 V_226 , struct V_453 * V_454 )
{
int V_190 ;
struct V_40 * V_232 ;
if ( ! V_191 )
return 0 ;
F_43 ( & V_192 ) ;
V_190 = - V_365 ;
V_232 = F_44 ( & V_193 , V_226 ) ;
if ( V_232 == NULL )
goto V_114;
V_190 = - V_17 ;
V_454 -> V_335 = F_57 ( F_20 ( & V_1 , V_225 , V_232 -> type - 1 ) ,
V_16 ) ;
if ( V_454 -> V_335 == NULL )
goto V_114;
V_454 -> V_65 . V_460 = V_226 ;
V_454 -> V_205 |= V_467 | V_459 ;
F_171 ( V_232 , V_454 ) ;
V_190 = F_172 ( V_232 , V_454 ) ;
V_114:
F_45 ( & V_192 ) ;
return V_190 ;
}
int F_173 ( void * * V_168 , T_2 * V_143 )
{
int V_190 ;
struct V_308 V_310 ;
if ( ! V_191 )
return - V_14 ;
* V_143 = F_121 () ;
* V_168 = F_174 ( * V_143 ) ;
if ( ! * V_168 )
return - V_17 ;
V_310 . V_168 = * V_168 ;
V_310 . V_143 = * V_143 ;
F_43 ( & V_192 ) ;
V_190 = F_175 ( & V_1 , & V_310 ) ;
F_45 ( & V_192 ) ;
if ( V_190 )
return V_190 ;
* V_143 = ( unsigned long ) V_310 . V_168 - ( unsigned long ) * V_168 ;
return 0 ;
}
