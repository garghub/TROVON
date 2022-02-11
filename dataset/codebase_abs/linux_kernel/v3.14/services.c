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
while ( V_18 -> V_25 && V_18 -> V_25 [ V_12 ] ) {
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
struct V_40 V_120 ;
struct V_32 V_121 ;
struct V_122 * V_123 ;
struct V_122 * V_124 ;
T_3 V_125 = 0 ;
V_123 = F_27 ( V_1 . V_126 ,
V_41 -> type - 1 ) ;
F_12 ( ! V_123 ) ;
V_124 = F_27 ( V_1 . V_126 ,
V_42 -> type - 1 ) ;
F_12 ( ! V_124 ) ;
if ( V_123 -> V_127 ) {
memset ( & V_121 , 0 , sizeof( V_121 ) ) ;
memcpy ( & V_119 , V_41 , sizeof( V_119 ) ) ;
V_119 . type = V_123 -> V_127 ;
F_28 ( & V_119 ,
V_42 ,
V_27 ,
& V_121 ) ;
if ( ( V_121 . V_36 & V_33 -> V_36 ) == V_33 -> V_36 )
return;
V_125 = ~ V_121 . V_36 & V_33 -> V_36 ;
}
if ( V_124 -> V_127 ) {
memset ( & V_121 , 0 , sizeof( V_121 ) ) ;
memcpy ( & V_120 , V_42 , sizeof( V_120 ) ) ;
V_120 . type = V_124 -> V_127 ;
F_28 ( V_41 ,
& V_120 ,
V_27 ,
& V_121 ) ;
if ( ( V_121 . V_36 & V_33 -> V_36 ) == V_33 -> V_36 )
return;
V_125 = ~ V_121 . V_36 & V_33 -> V_36 ;
}
if ( V_123 -> V_127 && V_124 -> V_127 ) {
memset ( & V_121 , 0 , sizeof( V_121 ) ) ;
F_28 ( & V_119 ,
& V_120 ,
V_27 ,
& V_121 ) ;
if ( ( V_121 . V_36 & V_33 -> V_36 ) == V_33 -> V_36 )
return;
V_125 = ~ V_121 . V_36 & V_33 -> V_36 ;
}
if ( V_125 ) {
V_33 -> V_36 &= ~ V_125 ;
F_19 ( V_41 , V_42 ,
V_27 , V_125 , L_12 ) ;
}
}
static void F_28 ( struct V_40 * V_41 ,
struct V_40 * V_42 ,
T_1 V_27 ,
struct V_32 * V_33 )
{
struct V_128 * V_129 ;
struct V_130 * V_131 ;
struct V_132 V_133 ;
struct V_134 * V_135 ;
struct V_100 * V_136 ;
struct V_137 * V_138 , * V_139 ;
struct V_140 * V_141 , * V_142 ;
unsigned int V_10 , V_11 ;
V_33 -> V_36 = 0 ;
V_33 -> V_37 = 0 ;
V_33 -> V_38 = 0xffffffff ;
if ( F_29 ( ! V_27 || V_27 > V_1 . V_143 . V_144 ) ) {
if ( F_30 () )
F_4 ( V_145 L_13 , V_27 ) ;
return;
}
V_136 = V_1 . V_111 [ V_27 - 1 ] ;
V_133 . V_146 = V_27 ;
V_133 . V_147 = V_148 ;
V_138 = F_31 ( V_1 . V_149 , V_41 -> type - 1 ) ;
F_12 ( ! V_138 ) ;
V_139 = F_31 ( V_1 . V_149 , V_42 -> type - 1 ) ;
F_12 ( ! V_139 ) ;
F_32 (sattr, snode, i) {
F_32 (tattr, tnode, j) {
V_133 . V_150 = V_10 + 1 ;
V_133 . V_151 = V_11 + 1 ;
for ( V_135 = F_33 ( & V_1 . V_152 , & V_133 ) ;
V_135 ;
V_135 = F_34 ( V_135 , V_133 . V_147 ) ) {
if ( V_135 -> V_153 . V_147 == V_154 )
V_33 -> V_36 |= V_135 -> V_155 . V_156 ;
else if ( V_135 -> V_153 . V_147 == V_157 )
V_33 -> V_37 |= V_135 -> V_155 . V_156 ;
else if ( V_135 -> V_153 . V_147 == V_158 )
V_33 -> V_38 &= V_135 -> V_155 . V_156 ;
}
F_35 ( & V_1 . V_159 , & V_133 , V_33 ) ;
}
}
V_129 = V_136 -> V_160 ;
while ( V_129 ) {
if ( ( V_129 -> V_96 & ( V_33 -> V_36 ) ) &&
! F_11 ( V_41 , V_42 , NULL ,
V_129 -> V_161 ) ) {
V_33 -> V_36 &= ~ ( V_129 -> V_96 ) ;
}
V_129 = V_129 -> V_59 ;
}
if ( V_27 == V_1 . V_162 &&
( V_33 -> V_36 & V_1 . V_163 ) &&
V_41 -> V_70 != V_42 -> V_70 ) {
for ( V_131 = V_1 . V_130 ; V_131 ; V_131 = V_131 -> V_59 ) {
if ( V_41 -> V_70 == V_131 -> V_70 &&
V_42 -> V_70 == V_131 -> V_164 )
break;
}
if ( ! V_131 )
V_33 -> V_36 &= ~ V_1 . V_163 ;
}
F_26 ( V_41 , V_42 ,
V_27 , V_33 ) ;
}
static int F_36 ( struct V_40 * V_165 ,
struct V_40 * V_166 ,
struct V_40 * V_42 ,
T_1 V_27 )
{
char * V_167 = NULL , * V_34 = NULL , * V_168 = NULL ;
T_3 V_169 , V_170 , V_171 ;
if ( F_22 ( V_165 , & V_167 , & V_169 ) )
goto V_114;
if ( F_22 ( V_166 , & V_34 , & V_170 ) )
goto V_114;
if ( F_22 ( V_42 , & V_168 , & V_171 ) )
goto V_114;
F_37 ( V_115 -> V_116 , V_16 , V_117 ,
L_14
L_15 ,
V_167 , V_34 , V_168 , F_20 ( & V_1 , V_110 , V_27 - 1 ) ) ;
V_114:
F_6 ( V_167 ) ;
F_6 ( V_34 ) ;
F_6 ( V_168 ) ;
if ( ! V_172 )
return 0 ;
return - V_173 ;
}
int F_38 ( T_3 V_174 , T_3 V_175 , T_3 V_176 ,
T_1 V_177 )
{
struct V_40 * V_165 ;
struct V_40 * V_166 ;
struct V_40 * V_42 ;
struct V_100 * V_136 ;
struct V_128 * V_129 ;
T_1 V_27 ;
int V_178 = 0 ;
if ( ! V_179 )
return 0 ;
F_39 ( & V_180 ) ;
V_27 = F_7 ( V_177 ) ;
if ( ! V_27 || V_27 > V_1 . V_143 . V_144 ) {
F_4 ( V_181 L_16 ,
V_182 , V_27 ) ;
V_178 = - V_14 ;
goto V_114;
}
V_136 = V_1 . V_111 [ V_27 - 1 ] ;
V_165 = F_40 ( & V_183 , V_174 ) ;
if ( ! V_165 ) {
F_4 ( V_181 L_17 ,
V_182 , V_174 ) ;
V_178 = - V_14 ;
goto V_114;
}
V_166 = F_40 ( & V_183 , V_175 ) ;
if ( ! V_166 ) {
F_4 ( V_181 L_17 ,
V_182 , V_175 ) ;
V_178 = - V_14 ;
goto V_114;
}
V_42 = F_40 ( & V_183 , V_176 ) ;
if ( ! V_42 ) {
F_4 ( V_181 L_17 ,
V_182 , V_176 ) ;
V_178 = - V_14 ;
goto V_114;
}
V_129 = V_136 -> V_184 ;
while ( V_129 ) {
if ( ! F_11 ( V_165 , V_166 , V_42 ,
V_129 -> V_161 ) ) {
V_178 = F_36 ( V_165 , V_166 ,
V_42 , V_27 ) ;
goto V_114;
}
V_129 = V_129 -> V_59 ;
}
V_114:
F_41 ( & V_180 ) ;
return V_178 ;
}
int F_42 ( T_3 V_185 , T_3 V_186 )
{
struct V_40 * V_187 , * V_188 ;
struct V_122 * type ;
int V_107 ;
int V_178 ;
F_39 ( & V_180 ) ;
V_178 = - V_14 ;
V_187 = F_40 ( & V_183 , V_185 ) ;
if ( ! V_187 ) {
F_4 ( V_181 L_18 ,
V_182 , V_185 ) ;
goto V_114;
}
V_178 = - V_14 ;
V_188 = F_40 ( & V_183 , V_186 ) ;
if ( ! V_188 ) {
F_4 ( V_181 L_18 ,
V_182 , V_186 ) ;
goto V_114;
}
V_178 = 0 ;
if ( V_187 -> type == V_188 -> type )
goto V_114;
V_107 = V_188 -> type ;
while ( true ) {
type = F_27 ( V_1 . V_126 ,
V_107 - 1 ) ;
F_12 ( ! type ) ;
V_178 = - V_173 ;
if ( ! type -> V_127 )
break;
V_178 = 0 ;
if ( type -> V_127 == V_187 -> type )
break;
V_107 = type -> V_127 ;
}
if ( V_178 ) {
char * V_189 = NULL ;
char * V_190 = NULL ;
T_3 V_108 ;
if ( ! F_22 ( V_187 ,
& V_189 , & V_108 ) &&
! F_22 ( V_188 ,
& V_190 , & V_108 ) ) {
F_37 ( V_115 -> V_116 ,
V_16 , V_117 ,
L_19
L_20
L_21 ,
V_189 , V_190 ) ;
}
F_6 ( V_190 ) ;
F_6 ( V_189 ) ;
}
V_114:
F_41 ( & V_180 ) ;
return V_178 ;
}
static void F_43 ( struct V_32 * V_33 )
{
V_33 -> V_36 = 0 ;
V_33 -> V_37 = 0 ;
V_33 -> V_38 = 0xffffffff ;
V_33 -> V_191 = V_192 ;
V_33 -> V_193 = 0 ;
}
void F_44 ( T_3 V_194 ,
T_3 V_195 ,
T_1 V_177 ,
struct V_32 * V_33 )
{
T_1 V_27 ;
struct V_40 * V_41 = NULL , * V_42 = NULL ;
F_39 ( & V_180 ) ;
F_43 ( V_33 ) ;
if ( ! V_179 )
goto V_196;
V_41 = F_40 ( & V_183 , V_194 ) ;
if ( ! V_41 ) {
F_4 ( V_181 L_17 ,
V_182 , V_194 ) ;
goto V_114;
}
if ( F_13 ( & V_1 . V_197 , V_41 -> type ) )
V_33 -> V_193 |= V_198 ;
V_42 = F_40 ( & V_183 , V_195 ) ;
if ( ! V_42 ) {
F_4 ( V_181 L_17 ,
V_182 , V_195 ) ;
goto V_114;
}
V_27 = F_7 ( V_177 ) ;
if ( F_29 ( V_177 && ! V_27 ) ) {
if ( V_1 . V_26 )
goto V_196;
goto V_114;
}
F_28 ( V_41 , V_42 , V_27 , V_33 ) ;
F_9 ( V_177 , V_33 , V_1 . V_26 ) ;
V_114:
F_41 ( & V_180 ) ;
return;
V_196:
V_33 -> V_36 = 0xffffffff ;
goto V_114;
}
void F_45 ( T_3 V_194 ,
T_3 V_195 ,
T_1 V_27 ,
struct V_32 * V_33 )
{
struct V_40 * V_41 = NULL , * V_42 = NULL ;
F_39 ( & V_180 ) ;
F_43 ( V_33 ) ;
if ( ! V_179 )
goto V_196;
V_41 = F_40 ( & V_183 , V_194 ) ;
if ( ! V_41 ) {
F_4 ( V_181 L_17 ,
V_182 , V_194 ) ;
goto V_114;
}
if ( F_13 ( & V_1 . V_197 , V_41 -> type ) )
V_33 -> V_193 |= V_198 ;
V_42 = F_40 ( & V_183 , V_195 ) ;
if ( ! V_42 ) {
F_4 ( V_181 L_17 ,
V_182 , V_195 ) ;
goto V_114;
}
if ( F_29 ( ! V_27 ) ) {
if ( V_1 . V_26 )
goto V_196;
goto V_114;
}
F_28 ( V_41 , V_42 , V_27 , V_33 ) ;
V_114:
F_41 ( & V_180 ) ;
return;
V_196:
V_33 -> V_36 = 0xffffffff ;
goto V_114;
}
static int F_22 ( struct V_40 * V_40 , char * * V_41 , T_3 * V_199 )
{
char * V_200 ;
if ( V_41 )
* V_41 = NULL ;
* V_199 = 0 ;
if ( V_40 -> V_201 ) {
* V_199 = V_40 -> V_201 ;
if ( V_41 ) {
* V_41 = F_46 ( V_40 -> V_202 , V_16 ) ;
if ( ! ( * V_41 ) )
return - V_17 ;
}
return 0 ;
}
* V_199 += strlen ( F_20 ( & V_1 , V_203 , V_40 -> V_67 - 1 ) ) + 1 ;
* V_199 += strlen ( F_20 ( & V_1 , V_204 , V_40 -> V_70 - 1 ) ) + 1 ;
* V_199 += strlen ( F_20 ( & V_1 , V_205 , V_40 -> type - 1 ) ) + 1 ;
* V_199 += F_47 ( V_40 ) ;
if ( ! V_41 )
return 0 ;
V_200 = F_48 ( * V_199 , V_16 ) ;
if ( ! V_200 )
return - V_17 ;
* V_41 = V_200 ;
sprintf ( V_200 , L_22 ,
F_20 ( & V_1 , V_203 , V_40 -> V_67 - 1 ) ,
F_20 ( & V_1 , V_204 , V_40 -> V_70 - 1 ) ,
F_20 ( & V_1 , V_205 , V_40 -> type - 1 ) ) ;
V_200 += strlen ( F_20 ( & V_1 , V_203 , V_40 -> V_67 - 1 ) ) +
1 + strlen ( F_20 ( & V_1 , V_204 , V_40 -> V_70 - 1 ) ) +
1 + strlen ( F_20 ( & V_1 , V_205 , V_40 -> type - 1 ) ) ;
F_49 ( V_40 , & V_200 ) ;
* V_200 = 0 ;
return 0 ;
}
const char * F_50 ( T_3 V_206 )
{
if ( F_29 ( V_206 > V_207 ) )
return NULL ;
return V_208 [ V_206 ] ;
}
static int F_51 ( T_3 V_206 , char * * V_41 ,
T_3 * V_199 , int V_209 )
{
struct V_40 * V_40 ;
int V_178 = 0 ;
if ( V_41 )
* V_41 = NULL ;
* V_199 = 0 ;
if ( ! V_179 ) {
if ( V_206 <= V_207 ) {
char * V_200 ;
* V_199 = strlen ( V_208 [ V_206 ] ) + 1 ;
if ( ! V_41 )
goto V_114;
V_200 = F_48 ( * V_199 , V_16 ) ;
if ( ! V_200 ) {
V_178 = - V_17 ;
goto V_114;
}
strcpy ( V_200 , V_208 [ V_206 ] ) ;
* V_41 = V_200 ;
goto V_114;
}
F_4 ( V_181 L_23
L_24 , V_182 , V_206 ) ;
V_178 = - V_14 ;
goto V_114;
}
F_39 ( & V_180 ) ;
if ( V_209 )
V_40 = F_52 ( & V_183 , V_206 ) ;
else
V_40 = F_40 ( & V_183 , V_206 ) ;
if ( ! V_40 ) {
F_4 ( V_181 L_17 ,
V_182 , V_206 ) ;
V_178 = - V_14 ;
goto V_210;
}
V_178 = F_22 ( V_40 , V_41 , V_199 ) ;
V_210:
F_41 ( & V_180 ) ;
V_114:
return V_178 ;
}
int F_53 ( T_3 V_206 , char * * V_41 , T_3 * V_199 )
{
return F_51 ( V_206 , V_41 , V_199 , 0 ) ;
}
int F_54 ( T_3 V_206 , char * * V_41 , T_3 * V_199 )
{
return F_51 ( V_206 , V_41 , V_199 , 1 ) ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_183 * V_211 ,
char * V_41 ,
T_3 V_199 ,
struct V_40 * V_212 ,
T_3 V_213 )
{
struct V_49 * V_70 ;
struct V_122 * V_214 ;
struct V_215 * V_216 ;
char * V_200 , * V_217 , V_218 ;
int V_178 = 0 ;
F_56 ( V_212 ) ;
V_178 = - V_14 ;
V_200 = ( char * ) V_41 ;
V_217 = V_200 ;
while ( * V_217 && * V_217 != ':' )
V_217 ++ ;
if ( * V_217 == 0 )
goto V_114;
* V_217 ++ = 0 ;
V_216 = F_57 ( V_2 -> V_219 . V_113 , V_200 ) ;
if ( ! V_216 )
goto V_114;
V_212 -> V_67 = V_216 -> V_21 ;
V_200 = V_217 ;
while ( * V_217 && * V_217 != ':' )
V_217 ++ ;
if ( * V_217 == 0 )
goto V_114;
* V_217 ++ = 0 ;
V_70 = F_57 ( V_2 -> V_220 . V_113 , V_200 ) ;
if ( ! V_70 )
goto V_114;
V_212 -> V_70 = V_70 -> V_21 ;
V_200 = V_217 ;
while ( * V_217 && * V_217 != ':' )
V_217 ++ ;
V_218 = * V_217 ;
* V_217 ++ = 0 ;
V_214 = F_57 ( V_2 -> V_221 . V_113 , V_200 ) ;
if ( ! V_214 || V_214 -> V_222 )
goto V_114;
V_212 -> type = V_214 -> V_21 ;
V_178 = F_58 ( V_2 , V_218 , & V_217 , V_212 , V_211 , V_213 ) ;
if ( V_178 )
goto V_114;
V_178 = - V_14 ;
if ( ( V_217 - V_41 ) < V_199 )
goto V_114;
if ( ! F_59 ( V_2 , V_212 ) )
goto V_114;
V_178 = 0 ;
V_114:
if ( V_178 )
F_60 ( V_212 ) ;
return V_178 ;
}
static int F_61 ( const char * V_41 , T_3 V_199 ,
T_3 * V_206 , T_3 V_213 , T_4 V_223 ,
int V_209 )
{
char * V_224 , * V_202 = NULL ;
struct V_40 V_40 ;
int V_178 = 0 ;
if ( ! V_199 )
return - V_14 ;
if ( ! V_179 ) {
int V_10 ;
for ( V_10 = 1 ; V_10 < V_207 ; V_10 ++ ) {
if ( ! strcmp ( V_208 [ V_10 ] , V_41 ) ) {
* V_206 = V_10 ;
return 0 ;
}
}
* V_206 = V_225 ;
return 0 ;
}
* V_206 = V_226 ;
V_224 = F_48 ( V_199 + 1 , V_223 ) ;
if ( ! V_224 )
return - V_17 ;
memcpy ( V_224 , V_41 , V_199 ) ;
V_224 [ V_199 ] = 0 ;
if ( V_209 ) {
V_178 = - V_17 ;
V_202 = F_46 ( V_224 , V_223 ) ;
if ( ! V_202 )
goto V_114;
}
F_39 ( & V_180 ) ;
V_178 = F_55 ( & V_1 , & V_183 , V_224 ,
V_199 , & V_40 , V_213 ) ;
if ( V_178 == - V_14 && V_209 ) {
V_40 . V_202 = V_202 ;
V_40 . V_201 = V_199 ;
V_202 = NULL ;
} else if ( V_178 )
goto V_210;
V_178 = F_62 ( & V_183 , & V_40 , V_206 ) ;
F_60 ( & V_40 ) ;
V_210:
F_41 ( & V_180 ) ;
V_114:
F_6 ( V_224 ) ;
F_6 ( V_202 ) ;
return V_178 ;
}
int F_63 ( const char * V_41 , T_3 V_199 , T_3 * V_206 ,
T_4 V_227 )
{
return F_61 ( V_41 , V_199 ,
V_206 , V_226 , V_227 , 0 ) ;
}
int F_64 ( const char * V_41 , T_3 V_199 ,
T_3 * V_206 , T_3 V_213 , T_4 V_223 )
{
return F_61 ( V_41 , V_199 ,
V_206 , V_213 , V_223 , 1 ) ;
}
int F_65 ( const char * V_41 , T_3 V_199 ,
T_3 * V_206 )
{
return F_61 ( V_41 , V_199 ,
V_206 , V_226 , V_228 , 1 ) ;
}
static int F_66 (
struct V_40 * V_41 ,
struct V_40 * V_42 ,
T_1 V_27 ,
struct V_40 * V_229 )
{
char * V_56 = NULL , * V_168 = NULL , * V_34 = NULL ;
T_3 V_230 , V_171 , V_170 ;
if ( F_22 ( V_41 , & V_56 , & V_230 ) )
goto V_114;
if ( F_22 ( V_42 , & V_168 , & V_171 ) )
goto V_114;
if ( F_22 ( V_229 , & V_34 , & V_170 ) )
goto V_114;
F_37 ( V_115 -> V_116 , V_16 , V_117 ,
L_25
L_26
L_27
L_28 ,
V_34 , V_56 , V_168 , F_20 ( & V_1 , V_110 , V_27 - 1 ) ) ;
V_114:
F_6 ( V_56 ) ;
F_6 ( V_168 ) ;
F_6 ( V_34 ) ;
if ( ! V_172 )
return 0 ;
return - V_231 ;
}
static void F_67 ( struct V_1 * V_217 , struct V_40 * V_229 ,
T_3 V_232 , T_3 V_233 , T_1 V_27 ,
const char * V_234 )
{
struct V_235 V_236 ;
struct V_237 * V_238 ;
if ( ! F_13 ( & V_217 -> V_239 , V_233 ) )
return;
V_236 . V_232 = V_232 ;
V_236 . V_233 = V_233 ;
V_236 . V_27 = V_27 ;
V_236 . V_15 = V_234 ;
V_238 = F_57 ( V_217 -> V_235 , & V_236 ) ;
if ( V_238 )
V_229 -> type = V_238 -> V_238 ;
}
static int F_68 ( T_3 V_194 ,
T_3 V_195 ,
T_1 V_177 ,
T_3 V_147 ,
const char * V_234 ,
T_3 * V_240 ,
bool V_241 )
{
struct V_100 * V_242 = NULL ;
struct V_40 * V_41 = NULL , * V_42 = NULL , V_229 ;
struct V_243 * V_244 = NULL ;
struct V_132 V_133 ;
struct V_245 * V_246 ;
struct V_134 * V_135 ;
T_1 V_27 ;
int V_178 = 0 ;
bool V_247 ;
if ( ! V_179 ) {
switch ( V_177 ) {
case V_248 :
* V_240 = V_194 ;
break;
default:
* V_240 = V_195 ;
break;
}
goto V_114;
}
F_56 ( & V_229 ) ;
F_39 ( & V_180 ) ;
if ( V_241 ) {
V_27 = F_7 ( V_177 ) ;
V_247 = F_69 ( V_177 ) ;
} else {
V_27 = V_177 ;
V_247 = F_69 ( F_8 ( V_27 ) ) ;
}
V_41 = F_40 ( & V_183 , V_194 ) ;
if ( ! V_41 ) {
F_4 ( V_181 L_17 ,
V_182 , V_194 ) ;
V_178 = - V_14 ;
goto V_210;
}
V_42 = F_40 ( & V_183 , V_195 ) ;
if ( ! V_42 ) {
F_4 ( V_181 L_17 ,
V_182 , V_195 ) ;
V_178 = - V_14 ;
goto V_210;
}
if ( V_27 && V_27 <= V_1 . V_143 . V_144 )
V_242 = V_1 . V_111 [ V_27 - 1 ] ;
switch ( V_147 ) {
case V_249 :
case V_250 :
if ( V_242 && V_242 -> V_251 == V_252 ) {
V_229 . V_67 = V_42 -> V_67 ;
} else {
V_229 . V_67 = V_41 -> V_67 ;
}
break;
case V_253 :
V_229 . V_67 = V_42 -> V_67 ;
break;
}
if ( V_242 && V_242 -> V_254 == V_255 ) {
V_229 . V_70 = V_41 -> V_70 ;
} else if ( V_242 && V_242 -> V_254 == V_252 ) {
V_229 . V_70 = V_42 -> V_70 ;
} else {
if ( ( V_27 == V_1 . V_162 ) || ( V_247 == true ) )
V_229 . V_70 = V_41 -> V_70 ;
else
V_229 . V_70 = V_256 ;
}
if ( V_242 && V_242 -> V_257 == V_255 ) {
V_229 . type = V_41 -> type ;
} else if ( V_242 && V_242 -> V_257 == V_252 ) {
V_229 . type = V_42 -> type ;
} else {
if ( ( V_27 == V_1 . V_162 ) || ( V_247 == true ) ) {
V_229 . type = V_41 -> type ;
} else {
V_229 . type = V_42 -> type ;
}
}
V_133 . V_150 = V_41 -> type ;
V_133 . V_151 = V_42 -> type ;
V_133 . V_146 = V_27 ;
V_133 . V_147 = V_147 ;
V_246 = F_70 ( & V_1 . V_152 , & V_133 ) ;
if ( ! V_246 ) {
V_135 = F_33 ( & V_1 . V_159 , & V_133 ) ;
for (; V_135 ; V_135 = F_34 ( V_135 , V_147 ) ) {
if ( V_135 -> V_153 . V_147 & V_258 ) {
V_246 = & V_135 -> V_155 ;
break;
}
}
}
if ( V_246 ) {
V_229 . type = V_246 -> V_156 ;
}
if ( V_234 )
F_67 ( & V_1 , & V_229 , V_41 -> type ,
V_42 -> type , V_27 , V_234 ) ;
if ( V_147 & V_249 ) {
for ( V_244 = V_1 . V_259 ; V_244 ; V_244 = V_244 -> V_59 ) {
if ( ( V_244 -> V_70 == V_41 -> V_70 ) &&
( V_244 -> type == V_42 -> type ) &&
( V_244 -> V_27 == V_27 ) ) {
V_229 . V_70 = V_244 -> V_164 ;
break;
}
}
}
V_178 = F_71 ( V_41 , V_42 , V_27 , V_147 ,
& V_229 , V_247 ) ;
if ( V_178 )
goto V_210;
if ( ! F_59 ( & V_1 , & V_229 ) ) {
V_178 = F_66 ( V_41 ,
V_42 ,
V_27 ,
& V_229 ) ;
if ( V_178 )
goto V_210;
}
V_178 = F_62 ( & V_183 , & V_229 , V_240 ) ;
V_210:
F_41 ( & V_180 ) ;
F_60 ( & V_229 ) ;
V_114:
return V_178 ;
}
int F_72 ( T_3 V_194 , T_3 V_195 , T_1 V_27 ,
const struct V_260 * V_260 , T_3 * V_240 )
{
return F_68 ( V_194 , V_195 , V_27 , V_249 ,
V_260 ? V_260 -> V_15 : NULL , V_240 , true ) ;
}
int F_73 ( T_3 V_194 , T_3 V_195 , T_1 V_27 ,
const char * V_234 , T_3 * V_240 )
{
return F_68 ( V_194 , V_195 , V_27 , V_249 ,
V_234 , V_240 , false ) ;
}
int F_74 ( T_3 V_194 ,
T_3 V_195 ,
T_1 V_27 ,
T_3 * V_240 )
{
return F_68 ( V_194 , V_195 , V_27 , V_253 , NULL ,
V_240 , false ) ;
}
int F_75 ( T_3 V_194 ,
T_3 V_195 ,
T_1 V_27 ,
T_3 * V_240 )
{
return F_68 ( V_194 , V_195 , V_27 , V_250 , NULL ,
V_240 , false ) ;
}
static int F_76 ( T_3 V_206 ,
struct V_40 * V_40 ,
void * V_261 )
{
struct V_183 * V_56 = V_261 ;
if ( V_206 > V_207 )
return F_77 ( V_56 , V_206 , V_40 ) ;
else
return 0 ;
}
static inline int F_78 ( struct V_40 * V_40 )
{
char * V_56 ;
T_3 V_201 ;
if ( V_172 )
return - V_14 ;
if ( ! F_22 ( V_40 , & V_56 , & V_201 ) ) {
F_4 ( V_145 L_29 , V_56 ) ;
F_6 ( V_56 ) ;
}
return 0 ;
}
static int F_79 ( T_3 V_153 ,
struct V_40 * V_48 ,
void * V_217 )
{
struct V_262 * args ;
struct V_40 V_218 ;
struct V_165 * V_263 ;
struct V_264 * V_78 ;
struct V_49 * V_70 ;
struct V_122 * V_214 ;
struct V_215 * V_216 ;
char * V_56 ;
T_3 V_201 ;
int V_178 = 0 ;
if ( V_153 <= V_207 )
goto V_114;
args = V_217 ;
if ( V_48 -> V_202 ) {
struct V_40 V_212 ;
V_178 = - V_17 ;
V_56 = F_46 ( V_48 -> V_202 , V_228 ) ;
if ( ! V_56 )
goto V_114;
V_178 = F_55 ( args -> V_265 , NULL , V_56 ,
V_48 -> V_201 , & V_212 , V_226 ) ;
F_6 ( V_56 ) ;
if ( ! V_178 ) {
F_4 ( V_22 L_30 ,
V_48 -> V_202 ) ;
F_6 ( V_48 -> V_202 ) ;
memcpy ( V_48 , & V_212 , sizeof( * V_48 ) ) ;
goto V_114;
} else if ( V_178 == - V_14 ) {
V_178 = 0 ;
goto V_114;
} else {
F_4 ( V_181 L_31 ,
V_48 -> V_202 , - V_178 ) ;
goto V_114;
}
}
V_178 = F_80 ( & V_218 , V_48 ) ;
if ( V_178 )
goto V_114;
V_178 = - V_14 ;
V_216 = F_57 ( args -> V_265 -> V_219 . V_113 ,
F_20 ( args -> V_266 , V_203 , V_48 -> V_67 - 1 ) ) ;
if ( ! V_216 )
goto V_267;
V_48 -> V_67 = V_216 -> V_21 ;
V_178 = - V_14 ;
V_70 = F_57 ( args -> V_265 -> V_220 . V_113 ,
F_20 ( args -> V_266 , V_204 , V_48 -> V_70 - 1 ) ) ;
if ( ! V_70 )
goto V_267;
V_48 -> V_70 = V_70 -> V_21 ;
V_178 = - V_14 ;
V_214 = F_57 ( args -> V_265 -> V_221 . V_113 ,
F_20 ( args -> V_266 , V_205 , V_48 -> type - 1 ) ) ;
if ( ! V_214 )
goto V_267;
V_48 -> type = V_214 -> V_21 ;
if ( args -> V_266 -> V_39 && args -> V_265 -> V_39 ) {
V_178 = F_81 ( args -> V_266 , args -> V_265 , V_48 ) ;
if ( V_178 )
goto V_267;
} else if ( args -> V_266 -> V_39 && ! args -> V_265 -> V_39 ) {
F_82 ( V_48 ) ;
} else if ( ! args -> V_266 -> V_39 && args -> V_265 -> V_39 ) {
V_263 = args -> V_265 -> V_268 [ V_269 ] ;
while ( V_263 && V_263 -> V_206 [ 0 ] != V_270 )
V_263 = V_263 -> V_59 ;
V_178 = - V_14 ;
if ( ! V_263 ) {
F_4 ( V_181 L_32
L_33 ) ;
goto V_267;
}
V_78 = & V_263 -> V_40 [ 0 ] . V_78 ;
V_178 = F_83 ( V_48 , V_78 ) ;
if ( V_178 )
goto V_267;
}
if ( ! F_59 ( args -> V_265 , V_48 ) ) {
V_178 = F_78 ( & V_218 ) ;
if ( V_178 )
goto V_267;
}
F_60 ( & V_218 ) ;
V_178 = 0 ;
V_114:
return V_178 ;
V_267:
V_178 = F_22 ( & V_218 , & V_56 , & V_201 ) ;
if ( V_178 )
return V_178 ;
F_60 ( & V_218 ) ;
F_60 ( V_48 ) ;
V_48 -> V_202 = V_56 ;
V_48 -> V_201 = V_201 ;
F_4 ( V_22 L_34 ,
V_48 -> V_202 ) ;
V_178 = 0 ;
goto V_114;
}
static void F_84 ( void )
{
V_271 = F_13 ( & V_1 . V_272 ,
V_273 ) ;
V_274 = F_13 ( & V_1 . V_272 ,
V_275 ) ;
V_276 = F_13 ( & V_1 . V_272 ,
V_277 ) ;
}
int F_85 ( void * V_156 , T_2 V_201 )
{
struct V_1 * V_278 , * V_279 ;
struct V_183 V_280 , V_281 ;
struct V_5 * V_282 , * V_4 = NULL ;
struct V_262 args ;
T_3 V_191 ;
T_1 V_283 ;
int V_178 = 0 ;
struct V_284 V_285 = { V_156 , V_201 } , * V_286 = & V_285 ;
V_278 = F_86 ( 2 * sizeof( * V_278 ) , V_228 ) ;
if ( ! V_278 ) {
V_178 = - V_17 ;
goto V_114;
}
V_279 = V_278 + 1 ;
if ( ! V_179 ) {
F_87 () ;
V_178 = F_88 ( & V_1 , V_286 ) ;
if ( V_178 ) {
F_89 () ;
goto V_114;
}
V_1 . V_201 = V_201 ;
V_178 = F_1 ( & V_1 , V_287 ,
& V_29 ,
& V_28 ) ;
if ( V_178 ) {
F_90 ( & V_1 ) ;
F_89 () ;
goto V_114;
}
V_178 = F_91 ( & V_1 , & V_183 ) ;
if ( V_178 ) {
F_90 ( & V_1 ) ;
F_89 () ;
goto V_114;
}
F_84 () ;
V_179 = 1 ;
V_191 = ++ V_192 ;
F_92 () ;
F_93 ( V_191 ) ;
F_94 ( V_191 ) ;
F_95 ( V_191 ) ;
F_96 () ;
F_97 () ;
goto V_114;
}
#if 0
sidtab_hash_eval(&sidtab, "sids");
#endif
V_178 = F_88 ( V_279 , V_286 ) ;
if ( V_178 )
goto V_114;
V_279 -> V_201 = V_201 ;
if ( V_1 . V_39 && ! V_279 -> V_39 )
F_4 ( V_22 L_35 ) ;
else if ( ! V_1 . V_39 && V_279 -> V_39 )
F_4 ( V_22 L_36 ) ;
V_178 = F_91 ( V_279 , & V_281 ) ;
if ( V_178 ) {
F_4 ( V_181 L_37 ) ;
F_90 ( V_279 ) ;
goto V_114;
}
V_178 = F_1 ( V_279 , V_287 , & V_4 , & V_283 ) ;
if ( V_178 )
goto V_24;
V_178 = F_98 ( V_279 ) ;
if ( V_178 ) {
F_4 ( V_181 L_38 ) ;
goto V_24;
}
F_99 ( & V_183 ) ;
V_178 = F_100 ( & V_183 , F_76 , & V_281 ) ;
if ( V_178 )
goto V_24;
args . V_266 = & V_1 ;
args . V_265 = V_279 ;
V_178 = F_100 ( & V_281 , F_79 , & args ) ;
if ( V_178 ) {
F_4 ( V_181 L_39
L_40
L_41 ) ;
goto V_24;
}
memcpy ( V_278 , & V_1 , sizeof( V_1 ) ) ;
F_101 ( & V_280 , & V_183 ) ;
F_102 ( & V_180 ) ;
memcpy ( & V_1 , V_279 , sizeof( V_1 ) ) ;
F_101 ( & V_183 , & V_281 ) ;
F_84 () ;
V_282 = V_29 ;
V_29 = V_4 ;
V_28 = V_283 ;
V_191 = ++ V_192 ;
F_103 ( & V_180 ) ;
F_90 ( V_278 ) ;
F_104 ( & V_280 ) ;
F_6 ( V_282 ) ;
F_93 ( V_191 ) ;
F_94 ( V_191 ) ;
F_95 ( V_191 ) ;
F_96 () ;
F_97 () ;
V_178 = 0 ;
goto V_114;
V_24:
F_6 ( V_4 ) ;
F_104 ( & V_281 ) ;
F_90 ( V_279 ) ;
V_114:
F_6 ( V_278 ) ;
return V_178 ;
}
T_2 F_105 ( void )
{
T_2 V_201 ;
F_39 ( & V_180 ) ;
V_201 = V_1 . V_201 ;
F_41 ( & V_180 ) ;
return V_201 ;
}
int F_106 ( T_5 V_288 , T_1 V_289 , T_3 * V_240 )
{
struct V_165 * V_48 ;
int V_178 = 0 ;
F_39 ( & V_180 ) ;
V_48 = V_1 . V_268 [ V_290 ] ;
while ( V_48 ) {
if ( V_48 -> V_291 . V_289 . V_288 == V_288 &&
V_48 -> V_291 . V_289 . V_292 <= V_289 &&
V_48 -> V_291 . V_289 . V_293 >= V_289 )
break;
V_48 = V_48 -> V_59 ;
}
if ( V_48 ) {
if ( ! V_48 -> V_206 [ 0 ] ) {
V_178 = F_62 ( & V_183 ,
& V_48 -> V_40 [ 0 ] ,
& V_48 -> V_206 [ 0 ] ) ;
if ( V_178 )
goto V_114;
}
* V_240 = V_48 -> V_206 [ 0 ] ;
} else {
* V_240 = V_294 ;
}
V_114:
F_41 ( & V_180 ) ;
return V_178 ;
}
int F_107 ( char * V_15 , T_3 * V_295 )
{
int V_178 = 0 ;
struct V_165 * V_48 ;
F_39 ( & V_180 ) ;
V_48 = V_1 . V_268 [ V_296 ] ;
while ( V_48 ) {
if ( strcmp ( V_15 , V_48 -> V_291 . V_15 ) == 0 )
break;
V_48 = V_48 -> V_59 ;
}
if ( V_48 ) {
if ( ! V_48 -> V_206 [ 0 ] || ! V_48 -> V_206 [ 1 ] ) {
V_178 = F_62 ( & V_183 ,
& V_48 -> V_40 [ 0 ] ,
& V_48 -> V_206 [ 0 ] ) ;
if ( V_178 )
goto V_114;
V_178 = F_62 ( & V_183 ,
& V_48 -> V_40 [ 1 ] ,
& V_48 -> V_206 [ 1 ] ) ;
if ( V_178 )
goto V_114;
}
* V_295 = V_48 -> V_206 [ 0 ] ;
} else
* V_295 = V_297 ;
V_114:
F_41 ( & V_180 ) ;
return V_178 ;
}
static int F_108 ( T_3 * V_298 , T_3 * V_299 , T_3 * V_118 )
{
int V_10 , V_300 = 0 ;
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ )
if ( V_299 [ V_10 ] != ( V_298 [ V_10 ] & V_118 [ V_10 ] ) ) {
V_300 = 1 ;
break;
}
return ! V_300 ;
}
int F_109 ( T_1 V_301 ,
void * V_302 ,
T_3 V_303 ,
T_3 * V_240 )
{
int V_178 ;
struct V_165 * V_48 ;
F_39 ( & V_180 ) ;
switch ( V_301 ) {
case V_304 : {
T_3 V_299 ;
V_178 = - V_14 ;
if ( V_303 != sizeof( T_3 ) )
goto V_114;
V_299 = * ( ( T_3 * ) V_302 ) ;
V_48 = V_1 . V_268 [ V_305 ] ;
while ( V_48 ) {
if ( V_48 -> V_291 . V_135 . V_299 == ( V_299 & V_48 -> V_291 . V_135 . V_118 ) )
break;
V_48 = V_48 -> V_59 ;
}
break;
}
case V_306 :
V_178 = - V_14 ;
if ( V_303 != sizeof( V_307 ) * 2 )
goto V_114;
V_48 = V_1 . V_268 [ V_308 ] ;
while ( V_48 ) {
if ( F_108 ( V_302 , V_48 -> V_291 . V_309 . V_299 ,
V_48 -> V_291 . V_309 . V_118 ) )
break;
V_48 = V_48 -> V_59 ;
}
break;
default:
V_178 = 0 ;
* V_240 = V_310 ;
goto V_114;
}
if ( V_48 ) {
if ( ! V_48 -> V_206 [ 0 ] ) {
V_178 = F_62 ( & V_183 ,
& V_48 -> V_40 [ 0 ] ,
& V_48 -> V_206 [ 0 ] ) ;
if ( V_178 )
goto V_114;
}
* V_240 = V_48 -> V_206 [ 0 ] ;
} else {
* V_240 = V_310 ;
}
V_178 = 0 ;
V_114:
F_41 ( & V_180 ) ;
return V_178 ;
}
int F_110 ( T_3 V_311 ,
char * V_312 ,
T_3 * * V_313 ,
T_3 * V_314 )
{
struct V_40 * V_315 , V_316 ;
T_3 * V_317 = NULL , * V_318 , V_206 ;
T_3 V_319 = 0 , V_320 = V_321 ;
struct V_215 * V_67 ;
struct V_49 * V_70 ;
struct V_140 * V_322 , * V_142 ;
int V_178 = 0 , V_10 , V_11 ;
* V_313 = NULL ;
* V_314 = 0 ;
if ( ! V_179 )
goto V_114;
F_39 ( & V_180 ) ;
F_56 ( & V_316 ) ;
V_178 = - V_14 ;
V_315 = F_40 ( & V_183 , V_311 ) ;
if ( ! V_315 )
goto V_210;
V_178 = - V_14 ;
V_67 = F_57 ( V_1 . V_219 . V_113 , V_312 ) ;
if ( ! V_67 )
goto V_210;
V_316 . V_67 = V_67 -> V_21 ;
V_178 = - V_17 ;
V_317 = F_2 ( V_320 , sizeof( * V_317 ) , V_16 ) ;
if ( ! V_317 )
goto V_210;
F_32 (&user->roles, rnode, i) {
V_70 = V_1 . V_71 [ V_10 ] ;
V_316 . V_70 = V_10 + 1 ;
F_32 (&role->types, tnode, j) {
V_316 . type = V_11 + 1 ;
if ( F_111 ( V_315 , V_67 , & V_316 ) )
continue;
V_178 = F_62 ( & V_183 , & V_316 , & V_206 ) ;
if ( V_178 )
goto V_210;
if ( V_319 < V_320 ) {
V_317 [ V_319 ++ ] = V_206 ;
} else {
V_178 = - V_17 ;
V_320 += V_321 ;
V_318 = F_2 ( V_320 , sizeof( * V_318 ) , V_16 ) ;
if ( ! V_318 )
goto V_210;
memcpy ( V_318 , V_317 , V_319 * sizeof( * V_318 ) ) ;
F_6 ( V_317 ) ;
V_317 = V_318 ;
V_317 [ V_319 ++ ] = V_206 ;
}
}
}
V_178 = 0 ;
V_210:
F_41 ( & V_180 ) ;
if ( V_178 || ! V_319 ) {
F_6 ( V_317 ) ;
goto V_114;
}
V_178 = - V_17 ;
V_318 = F_2 ( V_319 , sizeof( * V_318 ) , V_228 ) ;
if ( ! V_318 ) {
F_6 ( V_317 ) ;
goto V_114;
}
for ( V_10 = 0 , V_11 = 0 ; V_10 < V_319 ; V_10 ++ ) {
struct V_32 V_323 ;
V_178 = F_112 ( V_311 , V_317 [ V_10 ] ,
V_248 ,
V_324 , V_325 ,
& V_323 ) ;
if ( ! V_178 )
V_318 [ V_11 ++ ] = V_317 [ V_10 ] ;
F_113 () ;
}
V_178 = 0 ;
F_6 ( V_317 ) ;
* V_313 = V_318 ;
* V_314 = V_11 ;
V_114:
return V_178 ;
}
int F_114 ( const char * V_326 ,
char * V_327 ,
T_1 V_328 ,
T_3 * V_206 )
{
int V_201 ;
T_1 V_329 ;
struct V_330 * V_330 ;
struct V_165 * V_48 ;
int V_178 , V_331 = 0 ;
while ( V_327 [ 0 ] == '/' && V_327 [ 1 ] == '/' )
V_327 ++ ;
F_39 ( & V_180 ) ;
V_329 = F_7 ( V_328 ) ;
* V_206 = V_270 ;
for ( V_330 = V_1 . V_330 ; V_330 ; V_330 = V_330 -> V_59 ) {
V_331 = strcmp ( V_326 , V_330 -> V_326 ) ;
if ( V_331 <= 0 )
break;
}
V_178 = - V_332 ;
if ( ! V_330 || V_331 )
goto V_114;
for ( V_48 = V_330 -> V_333 ; V_48 ; V_48 = V_48 -> V_59 ) {
V_201 = strlen ( V_48 -> V_291 . V_15 ) ;
if ( ( ! V_48 -> V_334 . V_329 || V_329 == V_48 -> V_334 . V_329 ) &&
( strncmp ( V_48 -> V_291 . V_15 , V_327 , V_201 ) == 0 ) )
break;
}
V_178 = - V_332 ;
if ( ! V_48 )
goto V_114;
if ( ! V_48 -> V_206 [ 0 ] ) {
V_178 = F_62 ( & V_183 , & V_48 -> V_40 [ 0 ] , & V_48 -> V_206 [ 0 ] ) ;
if ( V_178 )
goto V_114;
}
* V_206 = V_48 -> V_206 [ 0 ] ;
V_178 = 0 ;
V_114:
F_41 ( & V_180 ) ;
return V_178 ;
}
int F_115 ( struct V_335 * V_336 )
{
int V_178 = 0 ;
struct V_165 * V_48 ;
struct V_337 * V_338 = V_336 -> V_339 ;
const char * V_326 = V_336 -> V_340 -> V_15 ;
F_39 ( & V_180 ) ;
V_48 = V_1 . V_268 [ V_341 ] ;
while ( V_48 ) {
if ( strcmp ( V_326 , V_48 -> V_291 . V_15 ) == 0 )
break;
V_48 = V_48 -> V_59 ;
}
if ( V_48 ) {
V_338 -> V_342 = V_48 -> V_334 . V_342 ;
if ( ! V_48 -> V_206 [ 0 ] ) {
V_178 = F_62 ( & V_183 , & V_48 -> V_40 [ 0 ] ,
& V_48 -> V_206 [ 0 ] ) ;
if ( V_178 )
goto V_114;
}
V_338 -> V_206 = V_48 -> V_206 [ 0 ] ;
} else {
V_178 = F_114 ( V_326 , L_42 , V_343 , & V_338 -> V_206 ) ;
if ( V_178 ) {
V_338 -> V_342 = V_344 ;
V_178 = 0 ;
} else {
V_338 -> V_342 = V_345 ;
}
}
V_114:
F_41 ( & V_180 ) ;
return V_178 ;
}
int F_116 ( int * V_201 , char * * * V_91 , int * * V_346 )
{
int V_10 , V_178 ;
F_39 ( & V_180 ) ;
* V_91 = NULL ;
* V_346 = NULL ;
V_178 = 0 ;
* V_201 = V_1 . V_347 . V_144 ;
if ( ! * V_201 )
goto V_114;
V_178 = - V_17 ;
* V_91 = F_2 ( * V_201 , sizeof( char * ) , V_16 ) ;
if ( ! * V_91 )
goto V_24;
V_178 = - V_17 ;
* V_346 = F_2 ( * V_201 , sizeof( int ) , V_16 ) ;
if ( ! * V_346 )
goto V_24;
for ( V_10 = 0 ; V_10 < * V_201 ; V_10 ++ ) {
T_2 V_348 ;
( * V_346 ) [ V_10 ] = V_1 . V_349 [ V_10 ] -> V_350 ;
V_348 = strlen ( F_20 ( & V_1 , V_351 , V_10 ) ) + 1 ;
V_178 = - V_17 ;
( * V_91 ) [ V_10 ] = F_48 ( sizeof( char ) * V_348 , V_16 ) ;
if ( ! ( * V_91 ) [ V_10 ] )
goto V_24;
strncpy ( ( * V_91 ) [ V_10 ] , F_20 ( & V_1 , V_351 , V_10 ) , V_348 ) ;
( * V_91 ) [ V_10 ] [ V_348 - 1 ] = 0 ;
}
V_178 = 0 ;
V_114:
F_41 ( & V_180 ) ;
return V_178 ;
V_24:
if ( * V_91 ) {
for ( V_10 = 0 ; V_10 < * V_201 ; V_10 ++ )
F_6 ( ( * V_91 ) [ V_10 ] ) ;
}
F_6 ( * V_346 ) ;
goto V_114;
}
int F_117 ( int V_201 , int * V_346 )
{
int V_10 , V_178 ;
int V_352 , V_191 = 0 ;
struct V_353 * V_354 ;
F_102 ( & V_180 ) ;
V_178 = - V_355 ;
V_352 = V_1 . V_347 . V_144 ;
if ( V_201 != V_352 )
goto V_114;
for ( V_10 = 0 ; V_10 < V_201 ; V_10 ++ ) {
if ( ! ! V_346 [ V_10 ] != V_1 . V_349 [ V_10 ] -> V_350 ) {
F_37 ( V_115 -> V_116 , V_16 ,
V_356 ,
L_43 ,
F_20 ( & V_1 , V_351 , V_10 ) ,
! ! V_346 [ V_10 ] ,
V_1 . V_349 [ V_10 ] -> V_350 ,
F_118 ( & V_357 , F_119 ( V_115 ) ) ,
F_120 ( V_115 ) ) ;
}
if ( V_346 [ V_10 ] )
V_1 . V_349 [ V_10 ] -> V_350 = 1 ;
else
V_1 . V_349 [ V_10 ] -> V_350 = 0 ;
}
for ( V_354 = V_1 . V_358 ; V_354 ; V_354 = V_354 -> V_59 ) {
V_178 = F_121 ( & V_1 , V_354 ) ;
if ( V_178 )
goto V_114;
}
V_191 = ++ V_192 ;
V_178 = 0 ;
V_114:
F_103 ( & V_180 ) ;
if ( ! V_178 ) {
F_93 ( V_191 ) ;
F_94 ( V_191 ) ;
F_95 ( V_191 ) ;
F_97 () ;
}
return V_178 ;
}
int F_122 ( int bool )
{
int V_178 ;
int V_201 ;
F_39 ( & V_180 ) ;
V_178 = - V_355 ;
V_201 = V_1 . V_347 . V_144 ;
if ( bool >= V_201 )
goto V_114;
V_178 = V_1 . V_349 [ bool ] -> V_350 ;
V_114:
F_41 ( & V_180 ) ;
return V_178 ;
}
static int F_98 ( struct V_1 * V_217 )
{
int V_178 , V_359 = 0 , * V_360 = NULL , V_10 ;
char * * V_361 = NULL ;
struct V_362 * V_363 ;
struct V_353 * V_354 ;
V_178 = F_116 ( & V_359 , & V_361 , & V_360 ) ;
if ( V_178 )
goto V_114;
for ( V_10 = 0 ; V_10 < V_359 ; V_10 ++ ) {
V_363 = F_57 ( V_217 -> V_347 . V_113 , V_361 [ V_10 ] ) ;
if ( V_363 )
V_363 -> V_350 = V_360 [ V_10 ] ;
}
for ( V_354 = V_217 -> V_358 ; V_354 ; V_354 = V_354 -> V_59 ) {
V_178 = F_121 ( V_217 , V_354 ) ;
if ( V_178 )
goto V_114;
}
V_114:
if ( V_361 ) {
for ( V_10 = 0 ; V_10 < V_359 ; V_10 ++ )
F_6 ( V_361 [ V_10 ] ) ;
}
F_6 ( V_361 ) ;
F_6 ( V_360 ) ;
return V_178 ;
}
int F_123 ( T_3 V_206 , T_3 V_364 , T_3 * V_186 )
{
struct V_40 * V_365 ;
struct V_40 * V_366 ;
struct V_40 V_367 ;
char * V_56 ;
T_3 V_201 ;
int V_178 ;
V_178 = 0 ;
if ( ! V_179 || ! V_1 . V_39 ) {
* V_186 = V_206 ;
goto V_114;
}
F_56 ( & V_367 ) ;
F_39 ( & V_180 ) ;
V_178 = - V_14 ;
V_365 = F_40 ( & V_183 , V_206 ) ;
if ( ! V_365 ) {
F_4 ( V_181 L_17 ,
V_182 , V_206 ) ;
goto V_210;
}
V_178 = - V_14 ;
V_366 = F_40 ( & V_183 , V_364 ) ;
if ( ! V_366 ) {
F_4 ( V_181 L_17 ,
V_182 , V_364 ) ;
goto V_210;
}
V_367 . V_67 = V_365 -> V_67 ;
V_367 . V_70 = V_365 -> V_70 ;
V_367 . type = V_365 -> type ;
V_178 = F_124 ( & V_367 , V_366 ) ;
if ( V_178 )
goto V_210;
if ( ! F_59 ( & V_1 , & V_367 ) ) {
V_178 = F_78 ( & V_367 ) ;
if ( V_178 ) {
if ( ! F_22 ( & V_367 , & V_56 , & V_201 ) ) {
F_37 ( V_115 -> V_116 , V_16 , V_117 ,
L_44 , V_56 ) ;
F_6 ( V_56 ) ;
}
goto V_210;
}
}
V_178 = F_62 ( & V_183 , & V_367 , V_186 ) ;
V_210:
F_41 ( & V_180 ) ;
F_60 ( & V_367 ) ;
V_114:
return V_178 ;
}
int F_125 ( T_3 V_368 , T_3 V_369 ,
T_3 V_370 ,
T_3 * V_371 )
{
int V_178 ;
struct V_40 * V_372 ;
struct V_40 * V_373 ;
* V_371 = V_226 ;
if ( V_370 == V_226 ) {
* V_371 = V_368 ;
return 0 ;
}
if ( V_368 == V_226 || V_369 == V_374 ) {
* V_371 = V_370 ;
return 0 ;
}
if ( ! V_1 . V_39 )
return 0 ;
F_39 ( & V_180 ) ;
V_178 = - V_14 ;
V_372 = F_40 ( & V_183 , V_368 ) ;
if ( ! V_372 ) {
F_4 ( V_181 L_17 ,
V_182 , V_368 ) ;
goto V_114;
}
V_178 = - V_14 ;
V_373 = F_40 ( & V_183 , V_370 ) ;
if ( ! V_373 ) {
F_4 ( V_181 L_17 ,
V_182 , V_370 ) ;
goto V_114;
}
V_178 = ( F_126 ( V_372 , V_373 ) ? 0 : - V_231 ) ;
if ( V_178 )
goto V_114;
* V_371 = V_370 ;
V_114:
F_41 ( & V_180 ) ;
return V_178 ;
}
static int F_127 ( void * V_12 , void * V_92 , void * args )
{
struct V_100 * V_155 = V_92 ;
char * V_15 = V_12 , * * V_375 = args ;
int V_21 = V_155 -> V_21 - 1 ;
V_375 [ V_21 ] = F_46 ( V_15 , V_16 ) ;
if ( ! V_375 [ V_21 ] )
return - V_17 ;
return 0 ;
}
int F_128 ( char * * * V_375 , int * V_376 )
{
int V_178 ;
F_39 ( & V_180 ) ;
V_178 = - V_17 ;
* V_376 = V_1 . V_143 . V_144 ;
* V_375 = F_2 ( * V_376 , sizeof( * * V_375 ) , V_16 ) ;
if ( ! * V_375 )
goto V_114;
V_178 = F_21 ( V_1 . V_143 . V_113 , F_127 ,
* V_375 ) ;
if ( V_178 ) {
int V_10 ;
for ( V_10 = 0 ; V_10 < * V_376 ; V_10 ++ )
F_6 ( ( * V_375 ) [ V_10 ] ) ;
F_6 ( * V_375 ) ;
}
V_114:
F_41 ( & V_180 ) ;
return V_178 ;
}
static int F_129 ( void * V_12 , void * V_92 , void * args )
{
struct V_93 * V_155 = V_92 ;
char * V_15 = V_12 , * * V_25 = args ;
int V_21 = V_155 -> V_21 - 1 ;
V_25 [ V_21 ] = F_46 ( V_15 , V_16 ) ;
if ( ! V_25 [ V_21 ] )
return - V_17 ;
return 0 ;
}
int F_130 ( char * V_377 , char * * * V_25 , int * V_378 )
{
int V_178 , V_10 ;
struct V_100 * V_379 ;
F_39 ( & V_180 ) ;
V_178 = - V_14 ;
V_379 = F_57 ( V_1 . V_143 . V_113 , V_377 ) ;
if ( ! V_379 ) {
F_4 ( V_181 L_45 ,
V_182 , V_377 ) ;
goto V_114;
}
V_178 = - V_17 ;
* V_378 = V_379 -> V_96 . V_144 ;
* V_25 = F_2 ( * V_378 , sizeof( * * V_25 ) , V_16 ) ;
if ( ! * V_25 )
goto V_114;
if ( V_379 -> V_112 ) {
V_178 = F_21 ( V_379 -> V_112 -> V_96 . V_113 ,
F_129 , * V_25 ) ;
if ( V_178 )
goto V_24;
}
V_178 = F_21 ( V_379 -> V_96 . V_113 , F_129 ,
* V_25 ) ;
if ( V_178 )
goto V_24;
V_114:
F_41 ( & V_180 ) ;
return V_178 ;
V_24:
F_41 ( & V_180 ) ;
for ( V_10 = 0 ; V_10 < * V_378 ; V_10 ++ )
F_6 ( ( * V_25 ) [ V_10 ] ) ;
F_6 ( * V_25 ) ;
return V_178 ;
}
int F_131 ( void )
{
return V_1 . V_23 ;
}
int F_132 ( void )
{
return V_1 . V_26 ;
}
int F_133 ( unsigned int V_380 )
{
int V_178 ;
F_39 ( & V_180 ) ;
V_178 = F_13 ( & V_1 . V_272 , V_380 ) ;
F_41 ( & V_180 ) ;
return V_178 ;
}
void F_134 ( void * V_381 )
{
struct V_382 * V_383 = V_381 ;
if ( V_383 ) {
F_60 ( & V_383 -> V_384 ) ;
F_6 ( V_383 ) ;
}
}
int F_135 ( T_3 V_385 , T_3 V_72 , char * V_386 , void * * V_381 )
{
struct V_382 * V_387 ;
struct V_49 * V_388 ;
struct V_122 * V_389 ;
struct V_215 * V_390 ;
struct V_382 * * V_383 = (struct V_382 * * ) V_381 ;
int V_178 = 0 ;
* V_383 = NULL ;
if ( ! V_179 )
return - V_391 ;
switch ( V_385 ) {
case V_392 :
case V_393 :
case V_394 :
case V_395 :
case V_396 :
case V_397 :
if ( V_72 != V_398 && V_72 != V_399 )
return - V_14 ;
break;
case V_400 :
case V_401 :
case V_402 :
case V_403 :
if ( strchr ( V_386 , '-' ) )
return - V_14 ;
break;
default:
return - V_14 ;
}
V_387 = F_86 ( sizeof( struct V_382 ) , V_228 ) ;
if ( ! V_387 )
return - V_17 ;
F_56 ( & V_387 -> V_384 ) ;
F_39 ( & V_180 ) ;
V_387 -> V_404 = V_192 ;
switch ( V_385 ) {
case V_392 :
case V_395 :
V_178 = - V_14 ;
V_390 = F_57 ( V_1 . V_219 . V_113 , V_386 ) ;
if ( ! V_390 )
goto V_114;
V_387 -> V_384 . V_67 = V_390 -> V_21 ;
break;
case V_393 :
case V_396 :
V_178 = - V_14 ;
V_388 = F_57 ( V_1 . V_220 . V_113 , V_386 ) ;
if ( ! V_388 )
goto V_114;
V_387 -> V_384 . V_70 = V_388 -> V_21 ;
break;
case V_394 :
case V_397 :
V_178 = - V_14 ;
V_389 = F_57 ( V_1 . V_221 . V_113 , V_386 ) ;
if ( ! V_389 )
goto V_114;
V_387 -> V_384 . type = V_389 -> V_21 ;
break;
case V_400 :
case V_401 :
case V_402 :
case V_403 :
V_178 = F_136 ( V_386 , & V_387 -> V_384 , V_16 ) ;
if ( V_178 )
goto V_114;
break;
}
V_178 = 0 ;
V_114:
F_41 ( & V_180 ) ;
if ( V_178 ) {
F_134 ( V_387 ) ;
V_387 = NULL ;
}
* V_383 = V_387 ;
return V_178 ;
}
int F_137 ( struct V_405 * V_383 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_383 -> V_406 ; V_10 ++ ) {
struct V_407 * V_408 = & V_383 -> V_409 [ V_10 ] ;
switch ( V_408 -> type ) {
case V_392 :
case V_393 :
case V_394 :
case V_400 :
case V_401 :
case V_395 :
case V_396 :
case V_397 :
case V_402 :
case V_403 :
return 1 ;
}
}
return 0 ;
}
int F_138 ( T_3 V_206 , T_3 V_385 , T_3 V_72 , void * V_381 ,
struct V_116 * V_410 )
{
struct V_40 * V_411 ;
struct V_52 * V_79 ;
struct V_382 * V_383 = V_381 ;
int V_379 = 0 ;
if ( F_29 ( ! V_383 ) ) {
F_139 ( 1 , L_46 ) ;
return - V_332 ;
}
F_39 ( & V_180 ) ;
if ( V_383 -> V_404 < V_192 ) {
V_379 = - V_412 ;
goto V_114;
}
V_411 = F_40 ( & V_183 , V_206 ) ;
if ( F_29 ( ! V_411 ) ) {
F_139 ( 1 , L_47 ,
V_206 ) ;
V_379 = - V_332 ;
goto V_114;
}
switch ( V_385 ) {
case V_392 :
case V_395 :
switch ( V_72 ) {
case V_398 :
V_379 = ( V_411 -> V_67 == V_383 -> V_384 . V_67 ) ;
break;
case V_399 :
V_379 = ( V_411 -> V_67 != V_383 -> V_384 . V_67 ) ;
break;
}
break;
case V_393 :
case V_396 :
switch ( V_72 ) {
case V_398 :
V_379 = ( V_411 -> V_70 == V_383 -> V_384 . V_70 ) ;
break;
case V_399 :
V_379 = ( V_411 -> V_70 != V_383 -> V_384 . V_70 ) ;
break;
}
break;
case V_394 :
case V_397 :
switch ( V_72 ) {
case V_398 :
V_379 = ( V_411 -> type == V_383 -> V_384 . type ) ;
break;
case V_399 :
V_379 = ( V_411 -> type != V_383 -> V_384 . type ) ;
break;
}
break;
case V_400 :
case V_401 :
case V_402 :
case V_403 :
V_79 = ( ( V_385 == V_400 ||
V_385 == V_402 ) ?
& V_411 -> V_78 . V_79 [ 0 ] : & V_411 -> V_78 . V_79 [ 1 ] ) ;
switch ( V_72 ) {
case V_398 :
V_379 = F_14 ( & V_383 -> V_384 . V_78 . V_79 [ 0 ] ,
V_79 ) ;
break;
case V_399 :
V_379 = ! F_14 ( & V_383 -> V_384 . V_78 . V_79 [ 0 ] ,
V_79 ) ;
break;
case V_413 :
V_379 = ( F_15 ( & V_383 -> V_384 . V_78 . V_79 [ 0 ] ,
V_79 ) &&
! F_14 ( & V_383 -> V_384 . V_78 . V_79 [ 0 ] ,
V_79 ) ) ;
break;
case V_414 :
V_379 = F_15 ( & V_383 -> V_384 . V_78 . V_79 [ 0 ] ,
V_79 ) ;
break;
case V_415 :
V_379 = ( F_15 ( V_79 ,
& V_383 -> V_384 . V_78 . V_79 [ 0 ] ) &&
! F_14 ( V_79 ,
& V_383 -> V_384 . V_78 . V_79 [ 0 ] ) ) ;
break;
case V_416 :
V_379 = F_15 ( V_79 ,
& V_383 -> V_384 . V_78 . V_79 [ 0 ] ) ;
break;
}
}
V_114:
F_41 ( & V_180 ) ;
return V_379 ;
}
static int F_140 ( T_3 V_417 )
{
int V_24 = 0 ;
if ( V_417 == V_418 && V_419 )
V_24 = V_419 () ;
return V_24 ;
}
static int T_6 F_141 ( void )
{
int V_24 ;
V_24 = F_142 ( F_140 , V_418 ) ;
if ( V_24 )
F_143 ( L_48 , V_24 ) ;
return V_24 ;
}
static void F_144 ( struct V_420 * V_421 ,
T_3 V_206 )
{
T_3 * V_422 ;
V_422 = F_48 ( sizeof( * V_422 ) , V_16 ) ;
if ( V_422 == NULL )
return;
V_421 -> V_423 = F_145 ( V_16 ) ;
if ( V_421 -> V_423 == NULL ) {
F_6 ( V_422 ) ;
return;
}
* V_422 = V_206 ;
V_421 -> V_423 -> free = F_6 ;
V_421 -> V_423 -> V_156 = V_422 ;
V_421 -> V_193 |= V_424 ;
}
int F_146 ( struct V_420 * V_421 ,
T_3 * V_206 )
{
int V_178 ;
struct V_40 * V_212 ;
struct V_40 V_425 ;
if ( ! V_179 ) {
* V_206 = V_226 ;
return 0 ;
}
F_39 ( & V_180 ) ;
if ( V_421 -> V_193 & V_424 )
* V_206 = * ( T_3 * ) V_421 -> V_423 -> V_156 ;
else if ( V_421 -> V_193 & V_426 )
* V_206 = V_421 -> V_65 . V_427 ;
else if ( V_421 -> V_193 & V_428 ) {
V_178 = - V_429 ;
V_212 = F_40 ( & V_183 , V_430 ) ;
if ( V_212 == NULL )
goto V_114;
F_56 ( & V_425 ) ;
V_425 . V_67 = V_212 -> V_67 ;
V_425 . V_70 = V_212 -> V_70 ;
V_425 . type = V_212 -> type ;
F_147 ( & V_425 , V_421 ) ;
if ( V_421 -> V_193 & V_431 ) {
V_178 = F_148 ( & V_425 . V_78 . V_79 [ 0 ] . V_432 ,
V_421 -> V_65 . V_433 . V_432 ) ;
if ( V_178 )
goto V_114;
memcpy ( & V_425 . V_78 . V_79 [ 1 ] . V_432 ,
& V_425 . V_78 . V_79 [ 0 ] . V_432 ,
sizeof( V_425 . V_78 . V_79 [ 0 ] . V_432 ) ) ;
}
V_178 = - V_429 ;
if ( ! F_149 ( & V_1 , & V_425 ) )
goto V_434;
V_178 = F_62 ( & V_183 , & V_425 , V_206 ) ;
if ( V_178 )
goto V_434;
F_144 ( V_421 , * V_206 ) ;
F_150 ( & V_425 . V_78 . V_79 [ 0 ] . V_432 ) ;
} else
* V_206 = V_226 ;
F_41 ( & V_180 ) ;
return 0 ;
V_434:
F_150 ( & V_425 . V_78 . V_79 [ 0 ] . V_432 ) ;
V_114:
F_41 ( & V_180 ) ;
return V_178 ;
}
int F_151 ( T_3 V_206 , struct V_420 * V_421 )
{
int V_178 ;
struct V_40 * V_212 ;
if ( ! V_179 )
return 0 ;
F_39 ( & V_180 ) ;
V_178 = - V_332 ;
V_212 = F_40 ( & V_183 , V_206 ) ;
if ( V_212 == NULL )
goto V_114;
V_178 = - V_17 ;
V_421 -> V_301 = F_46 ( F_20 ( & V_1 , V_205 , V_212 -> type - 1 ) ,
V_16 ) ;
if ( V_421 -> V_301 == NULL )
goto V_114;
V_421 -> V_65 . V_427 = V_206 ;
V_421 -> V_193 |= V_435 | V_426 ;
F_152 ( V_212 , V_421 ) ;
V_178 = F_153 ( V_212 , V_421 ) ;
V_114:
F_41 ( & V_180 ) ;
return V_178 ;
}
int F_154 ( void * * V_156 , T_2 * V_201 )
{
int V_178 ;
struct V_284 V_286 ;
if ( ! V_179 )
return - V_14 ;
* V_201 = F_105 () ;
* V_156 = F_155 ( * V_201 ) ;
if ( ! * V_156 )
return - V_17 ;
V_286 . V_156 = * V_156 ;
V_286 . V_201 = * V_201 ;
F_39 ( & V_180 ) ;
V_178 = F_156 ( & V_1 , & V_286 ) ;
F_41 ( & V_180 ) ;
if ( V_178 )
return V_178 ;
* V_201 = ( unsigned long ) V_286 . V_156 - ( unsigned long ) * V_156 ;
return 0 ;
}
