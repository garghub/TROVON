static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 V_9 = { 0 } ;
int V_10 ;
V_10 = F_3 ( V_7 -> V_11 , & V_9 ) ;
if ( V_10 )
return V_10 ;
return F_4 ( V_5 , V_12 , L_1 ,
V_9 . V_13 , V_9 . V_14 ) ;
}
static int F_5 ( bool V_15 )
{
int V_10 = - V_16 , V_17 = 0 ;
struct V_18 T_2 * V_19 = V_20 . V_21 ;
T_3 V_22 = F_6 ( F_7 () , V_20 . V_23 ) ;
if ( ! V_20 . V_24 )
return 0 ;
while ( ! F_8 ( F_7 () , V_22 ) ) {
V_17 = F_9 ( & V_19 -> V_17 ) ;
if ( V_17 & V_25 ) {
V_10 = 0 ;
if ( V_15 && ( V_17 & V_26 ) )
V_10 = - V_16 ;
break;
}
F_10 ( 3 ) ;
}
if ( F_11 ( ! V_10 ) )
V_20 . V_24 = false ;
else
F_12 ( L_2 , V_17 ) ;
return V_10 ;
}
static int F_13 ( T_4 V_27 )
{
int V_10 = - V_16 , V_28 ;
struct V_18 * V_19 =
(struct V_18 * ) V_20 . V_21 ;
static T_3 V_29 , V_30 ;
static int V_31 ;
unsigned int V_32 ;
if ( V_27 == V_33 ) {
if ( V_20 . V_34 )
F_13 ( V_35 ) ;
V_10 = F_5 ( false ) ;
if ( V_10 )
goto V_36;
} else
V_20 . V_34 = FALSE ;
if ( V_20 . V_37 ) {
V_32 = F_14 ( F_7 () , V_29 ) ;
if ( V_20 . V_37 > V_32 )
F_10 ( V_20 . V_37 - V_32 ) ;
}
if ( V_20 . V_38 ) {
if ( V_31 == 0 ) {
V_32 = F_15 ( F_7 () , V_30 ) ;
if ( V_32 < 60 * V_39 ) {
F_16 ( L_3 ) ;
V_10 = - V_16 ;
goto V_36;
}
V_30 = F_7 () ;
V_31 = V_20 . V_38 ;
}
V_31 -- ;
}
F_17 ( V_27 , & V_19 -> V_40 ) ;
F_17 ( 0 , & V_19 -> V_17 ) ;
V_20 . V_24 = true ;
V_10 = F_18 ( V_20 . V_41 , & V_27 ) ;
if ( V_10 < 0 ) {
F_12 ( L_4 ,
V_27 , V_10 ) ;
goto V_36;
}
V_10 = F_5 ( true ) ;
if ( V_20 . V_37 )
V_29 = F_7 () ;
if ( V_20 . V_41 -> V_42 -> V_43 )
F_19 ( V_20 . V_41 , V_10 ) ;
else
F_20 ( V_20 . V_41 , V_10 ) ;
V_36:
if ( V_27 == V_35 ) {
if ( F_21 ( V_10 ) ) {
F_22 (i) {
struct V_6 * V_44 = F_23 ( V_45 , V_28 ) ;
if ( ! V_44 )
continue;
if ( V_44 -> V_46 == V_20 . V_47 )
V_44 -> V_48 = V_10 ;
}
}
V_20 . V_47 ++ ;
F_24 ( & V_20 . V_49 ) ;
}
return V_10 ;
}
static void F_25 ( struct V_50 * V_51 , void * V_52 , int V_10 )
{
if ( V_10 < 0 )
F_16 ( L_5 ,
* ( T_4 * ) V_52 , V_10 ) ;
else
F_16 ( L_6 ,
* ( T_4 * ) V_52 , V_10 ) ;
}
static int F_26 ( struct V_6 * V_7 , T_5 V_53 )
{
int V_54 = - V_55 ;
T_6 V_17 = V_56 ;
struct V_57 V_58 = { V_59 , NULL } ;
struct V_57 V_60 = { sizeof( L_7 ) , L_7 } ;
struct V_57 V_61 = { 0 , NULL } ;
union V_62 * V_63 = NULL ;
struct V_64 * V_65 ;
V_17 = F_27 ( V_53 , L_8 , NULL , & V_58 ,
V_66 ) ;
if ( F_28 ( V_17 ) )
return - V_67 ;
V_63 = V_58 . V_68 ;
if ( ! V_63 || V_63 -> V_69 . V_70 != 1 ) {
F_16 ( L_9 ) ;
goto V_36;
}
V_65 = & ( V_7 -> V_71 ) ;
V_61 . V_72 = sizeof( struct V_64 ) ;
V_61 . V_68 = V_65 ;
V_17 = F_29 ( & ( V_63 -> V_69 . V_73 [ 0 ] ) ,
& V_60 , & V_61 ) ;
if ( F_28 ( V_17 ) ) {
F_16 ( L_10 , V_7 -> V_11 ) ;
goto V_36;
}
if ( V_65 -> V_74 != V_75 ) {
F_16 ( L_11 , V_7 -> V_11 ) ;
goto V_36;
}
if ( V_65 -> V_76 != V_77 ) {
F_16 ( L_12 , V_7 -> V_11 ) ;
goto V_36;
}
if ( V_65 -> V_78 != V_79 &&
V_65 -> V_78 != V_80 &&
V_65 -> V_78 != V_81 ) {
F_16 ( L_13 , V_7 -> V_11 ) ;
goto V_36;
}
V_54 = 0 ;
V_36:
F_30 ( V_58 . V_68 ) ;
return V_54 ;
}
int F_31 ( struct V_82 * * V_83 )
{
int V_84 ;
int V_85 = 0 ;
unsigned int V_28 , V_86 ;
T_7 V_87 ;
struct V_82 * V_88 , * V_89 ;
struct V_64 * V_65 ;
struct V_64 * V_90 ;
struct V_6 * V_7 , * V_91 ;
if ( ! F_32 ( & V_87 , V_92 ) )
return - V_93 ;
F_22 (i) {
V_88 = V_83 [ V_28 ] ;
if ( ! V_88 )
continue;
if ( F_33 ( V_28 , V_87 ) )
continue;
V_7 = F_23 ( V_45 , V_28 ) ;
if ( ! V_7 ) {
V_85 = - V_55 ;
goto V_94;
}
V_65 = & ( V_7 -> V_71 ) ;
F_34 ( V_28 , V_88 -> V_95 ) ;
F_34 ( V_28 , V_87 ) ;
if ( V_65 -> V_96 <= 1 )
continue;
V_84 = V_65 -> V_96 ;
if ( V_65 -> V_78 == V_79 )
V_88 -> V_97 = V_98 ;
else if ( V_65 -> V_78 == V_81 )
V_88 -> V_97 = V_99 ;
else if ( V_65 -> V_78 == V_80 )
V_88 -> V_97 = V_100 ;
F_22 (j) {
if ( V_28 == V_86 )
continue;
V_91 = F_23 ( V_45 , V_86 ) ;
if ( ! V_91 ) {
V_85 = - V_55 ;
goto V_94;
}
V_90 = & ( V_91 -> V_71 ) ;
if ( V_90 -> V_101 != V_65 -> V_101 )
continue;
if ( V_90 -> V_96 != V_84 ) {
V_85 = - V_55 ;
goto V_94;
}
if ( V_65 -> V_78 != V_90 -> V_78 ) {
V_85 = - V_55 ;
goto V_94;
}
F_34 ( V_86 , V_87 ) ;
F_34 ( V_86 , V_88 -> V_95 ) ;
}
F_22 (j) {
if ( V_28 == V_86 )
continue;
V_89 = V_83 [ V_86 ] ;
if ( ! V_89 )
continue;
V_91 = F_23 ( V_45 , V_86 ) ;
if ( ! V_91 ) {
V_85 = - V_55 ;
goto V_94;
}
V_90 = & ( V_91 -> V_71 ) ;
if ( V_90 -> V_101 != V_65 -> V_101 )
continue;
V_89 -> V_97 = V_88 -> V_97 ;
F_35 ( V_89 -> V_95 ,
V_88 -> V_95 ) ;
}
}
V_94:
F_22 (i) {
V_88 = V_83 [ V_28 ] ;
if ( ! V_88 )
continue;
if ( V_85 ) {
F_36 ( V_88 -> V_95 ) ;
F_34 ( V_28 , V_88 -> V_95 ) ;
V_88 -> V_97 = V_98 ;
}
}
F_37 ( V_87 ) ;
return V_85 ;
}
static int F_38 ( int V_102 )
{
struct V_103 * V_104 ;
T_8 V_105 ;
if ( V_102 >= 0 ) {
V_20 . V_41 = F_39 ( & V_106 ,
V_102 ) ;
if ( F_40 ( V_20 . V_41 ) ) {
F_12 ( L_14 ) ;
return - V_67 ;
}
V_104 = ( V_20 . V_41 ) -> V_107 ;
if ( ! V_104 ) {
F_12 ( L_15 ) ;
return - V_67 ;
}
V_105 = V_108 * V_104 -> V_109 ;
V_20 . V_23 = F_41 ( V_105 * V_110 ) ;
V_20 . V_37 = V_104 -> V_111 ;
V_20 . V_38 = V_104 -> V_112 ;
V_20 . V_113 = V_104 -> V_109 ;
V_20 . V_21 = F_42 ( V_104 -> V_114 , V_104 -> V_72 ) ;
if ( ! V_20 . V_21 ) {
F_12 ( L_16 ) ;
return - V_93 ;
}
V_20 . V_115 = true ;
}
return 0 ;
}
bool __weak F_43 ( void )
{
return false ;
}
int F_44 ( struct V_116 * V_88 )
{
struct V_57 V_117 = { V_59 , NULL } ;
union V_62 * V_118 , * V_119 ;
struct V_6 * V_7 ;
struct V_120 * V_121 ;
struct V_122 * V_123 ;
T_5 V_53 = V_88 -> V_53 ;
unsigned int V_124 , V_28 , V_125 ;
T_6 V_17 ;
int V_10 = - V_55 ;
V_17 = F_27 ( V_53 , L_17 , NULL , & V_117 ,
V_66 ) ;
if ( F_28 ( V_17 ) ) {
V_10 = - V_67 ;
goto V_126;
}
V_118 = (union V_62 * ) V_117 . V_68 ;
V_7 = F_45 ( sizeof( struct V_6 ) , V_92 ) ;
if ( ! V_7 ) {
V_10 = - V_93 ;
goto V_126;
}
V_119 = & V_118 -> V_69 . V_73 [ 0 ] ;
if ( V_119 -> type == V_127 ) {
V_124 = V_119 -> integer . V_128 ;
} else {
F_16 ( L_18 ,
V_119 -> type ) ;
goto V_129;
}
if ( V_124 != V_130 ) {
F_16 ( L_19 ,
V_124 , V_130 ) ;
goto V_129;
}
V_7 -> V_74 = V_124 ;
V_119 = & V_118 -> V_69 . V_73 [ 1 ] ;
if ( V_119 -> type == V_127 ) {
V_125 = V_119 -> integer . V_128 ;
} else {
F_16 ( L_20 ,
V_119 -> type ) ;
goto V_129;
}
if ( V_125 != V_131 ) {
F_16 ( L_21 ,
V_125 , V_131 ) ;
goto V_129;
}
for ( V_28 = 2 ; V_28 < V_124 ; V_28 ++ ) {
V_119 = & V_118 -> V_69 . V_73 [ V_28 ] ;
if ( V_119 -> type == V_127 ) {
V_7 -> V_132 [ V_28 - 2 ] . type = V_127 ;
V_7 -> V_132 [ V_28 - 2 ] . V_133 . V_134 = V_119 -> integer . V_128 ;
} else if ( V_119 -> type == V_135 ) {
V_121 = (struct V_120 * )
V_119 -> V_58 . V_68 ;
if ( V_121 -> V_136 == V_137 ) {
if ( V_20 . V_102 < 0 )
V_20 . V_102 = V_121 -> V_138 ;
else if ( V_20 . V_102 != V_121 -> V_138 ) {
F_16 ( L_22 ) ;
goto V_129;
}
} else if ( V_121 -> V_136 == V_139 ) {
if ( V_121 -> V_140 ) {
void T_2 * V_141 ;
V_141 = F_46 ( V_121 -> V_140 , V_121 -> V_142 / 8 ) ;
if ( ! V_141 )
goto V_129;
V_7 -> V_132 [ V_28 - 2 ] . V_143 = V_141 ;
}
} else {
if ( V_121 -> V_136 != V_144 || ! F_43 () ) {
F_16 ( L_23 , V_121 -> V_136 ) ;
goto V_129;
}
}
V_7 -> V_132 [ V_28 - 2 ] . type = V_135 ;
memcpy ( & V_7 -> V_132 [ V_28 - 2 ] . V_133 . V_145 , V_121 , sizeof( * V_121 ) ) ;
} else {
F_16 ( L_24 , V_28 , V_88 -> V_146 ) ;
goto V_129;
}
}
V_7 -> V_11 = V_88 -> V_146 ;
V_10 = F_26 ( V_7 , V_53 ) ;
if ( V_10 )
goto V_129;
if ( ! V_20 . V_115 ) {
V_10 = F_38 ( V_20 . V_102 ) ;
if ( V_10 )
goto V_129;
F_47 ( & V_20 . V_147 ) ;
F_48 ( & V_20 . V_49 ) ;
}
F_16 ( L_25 , V_88 -> V_146 ) ;
V_123 = F_49 ( V_88 -> V_146 ) ;
if ( ! V_123 ) {
V_10 = - V_148 ;
goto V_129;
}
F_23 ( V_45 , V_88 -> V_146 ) = V_7 ;
V_10 = F_50 ( & V_7 -> V_2 , & V_149 , & V_123 -> V_2 ,
L_26 ) ;
if ( V_10 ) {
F_23 ( V_45 , V_88 -> V_146 ) = NULL ;
goto V_129;
}
F_30 ( V_117 . V_68 ) ;
return 0 ;
V_129:
for ( V_28 = 2 ; V_28 < V_7 -> V_74 ; V_28 ++ ) {
void T_2 * V_141 = V_7 -> V_132 [ V_28 - 2 ] . V_143 ;
if ( V_141 )
F_51 ( V_141 ) ;
}
F_30 ( V_7 ) ;
V_126:
F_30 ( V_117 . V_68 ) ;
return V_10 ;
}
void F_52 ( struct V_116 * V_88 )
{
struct V_6 * V_7 ;
unsigned int V_28 ;
void T_2 * V_141 ;
V_7 = F_23 ( V_45 , V_88 -> V_146 ) ;
if ( ! V_7 )
return;
for ( V_28 = 2 ; V_28 < V_7 -> V_74 ; V_28 ++ ) {
V_141 = V_7 -> V_132 [ V_28 - 2 ] . V_143 ;
if ( V_141 )
F_51 ( V_141 ) ;
}
F_53 ( & V_7 -> V_2 ) ;
F_30 ( V_7 ) ;
}
int __weak F_54 ( int V_150 , struct V_120 * V_145 , T_8 * V_151 )
{
return - V_152 ;
}
int __weak F_55 ( int V_150 , struct V_120 * V_145 , T_8 V_151 )
{
return - V_152 ;
}
static int F_56 ( int V_153 , struct V_154 * V_155 , T_8 * V_151 )
{
int V_156 = 0 ;
void T_2 * V_157 = 0 ;
struct V_120 * V_145 = & V_155 -> V_133 . V_145 ;
if ( V_155 -> type == V_127 ) {
* V_151 = V_155 -> V_133 . V_134 ;
return V_156 ;
}
* V_151 = 0 ;
if ( V_145 -> V_136 == V_137 )
V_157 = F_57 ( V_145 -> V_140 ) ;
else if ( V_145 -> V_136 == V_139 )
V_157 = V_155 -> V_143 ;
else if ( V_145 -> V_136 == V_144 )
return F_54 ( V_153 , V_145 , V_151 ) ;
else
return F_58 ( ( V_158 ) V_145 -> V_140 ,
V_151 , V_145 -> V_142 ) ;
switch ( V_145 -> V_142 ) {
case 8 :
* V_151 = F_59 ( V_157 ) ;
break;
case 16 :
* V_151 = F_9 ( V_157 ) ;
break;
case 32 :
* V_151 = F_60 ( V_157 ) ;
break;
case 64 :
* V_151 = F_61 ( V_157 ) ;
break;
default:
F_16 ( L_27 ,
V_145 -> V_142 ) ;
V_156 = - V_55 ;
}
return V_156 ;
}
static int F_62 ( int V_153 , struct V_154 * V_155 , T_8 V_151 )
{
int V_156 = 0 ;
void T_2 * V_157 = 0 ;
struct V_120 * V_145 = & V_155 -> V_133 . V_145 ;
if ( V_145 -> V_136 == V_137 )
V_157 = F_57 ( V_145 -> V_140 ) ;
else if ( V_145 -> V_136 == V_139 )
V_157 = V_155 -> V_143 ;
else if ( V_145 -> V_136 == V_144 )
return F_55 ( V_153 , V_145 , V_151 ) ;
else
return F_63 ( ( V_158 ) V_145 -> V_140 ,
V_151 , V_145 -> V_142 ) ;
switch ( V_145 -> V_142 ) {
case 8 :
F_64 ( V_151 , V_157 ) ;
break;
case 16 :
F_17 ( V_151 , V_157 ) ;
break;
case 32 :
F_65 ( V_151 , V_157 ) ;
break;
case 64 :
F_66 ( V_151 , V_157 ) ;
break;
default:
F_16 ( L_28 ,
V_145 -> V_142 ) ;
V_156 = - V_55 ;
break;
}
return V_156 ;
}
int F_67 ( int V_150 , struct V_159 * V_160 )
{
struct V_6 * V_6 = F_23 ( V_45 , V_150 ) ;
struct V_154 * V_161 , * V_162 ,
* V_163 , * V_164 ;
T_8 V_165 , V_166 , V_167 , V_168 ;
int V_10 = 0 , V_169 = 0 ;
if ( ! V_6 ) {
F_16 ( L_29 , V_150 ) ;
return - V_67 ;
}
V_161 = & V_6 -> V_132 [ V_170 ] ;
V_162 = & V_6 -> V_132 [ V_171 ] ;
V_163 = & V_6 -> V_132 [ V_172 ] ;
V_164 = & V_6 -> V_132 [ V_173 ] ;
if ( F_68 ( V_161 ) || F_68 ( V_162 ) ||
F_68 ( V_163 ) || F_68 ( V_164 ) ) {
V_169 = 1 ;
F_69 ( & V_20 . V_147 ) ;
if ( F_13 ( V_33 ) < 0 ) {
V_10 = - V_16 ;
goto V_174;
}
}
F_56 ( V_150 , V_161 , & V_165 ) ;
V_160 -> V_175 = V_165 ;
F_56 ( V_150 , V_162 , & V_166 ) ;
V_160 -> V_176 = V_166 ;
F_56 ( V_150 , V_164 , & V_167 ) ;
V_160 -> V_177 = V_167 ;
F_56 ( V_150 , V_163 , & V_168 ) ;
V_160 -> V_178 = V_168 ;
if ( ! V_165 || ! V_166 || ! V_167 || ! V_168 )
V_10 = - V_55 ;
V_174:
if ( V_169 )
F_70 ( & V_20 . V_147 ) ;
return V_10 ;
}
int F_3 ( int V_150 , struct V_8 * V_179 )
{
struct V_6 * V_6 = F_23 ( V_45 , V_150 ) ;
struct V_154 * V_180 , * V_181 ,
* V_182 , * V_183 ;
T_8 V_14 , V_13 , V_184 , V_185 ;
int V_10 = 0 , V_169 = 0 ;
if ( ! V_6 ) {
F_16 ( L_29 , V_150 ) ;
return - V_67 ;
}
V_180 = & V_6 -> V_132 [ V_186 ] ;
V_181 = & V_6 -> V_132 [ V_187 ] ;
V_182 = & V_6 -> V_132 [ V_188 ] ;
V_183 = & V_6 -> V_132 [ V_189 ] ;
if ( ! F_71 ( V_182 ) )
V_182 = & V_6 -> V_132 [ V_173 ] ;
if ( F_68 ( V_180 ) || F_68 ( V_181 ) ||
F_68 ( V_183 ) || F_68 ( V_182 ) ) {
F_69 ( & V_20 . V_147 ) ;
V_169 = 1 ;
if ( F_13 ( V_33 ) < 0 ) {
V_10 = - V_16 ;
goto V_174;
}
}
F_56 ( V_150 , V_180 , & V_14 ) ;
F_56 ( V_150 , V_181 , & V_13 ) ;
F_56 ( V_150 , V_182 , & V_184 ) ;
V_185 = ( T_8 ) ( ~ ( ( T_8 ) 0 ) ) ;
if ( F_71 ( V_183 ) )
F_56 ( V_150 , V_183 , & V_185 ) ;
if ( ! V_14 || ! V_13 || ! V_184 ) {
V_10 = - V_55 ;
goto V_174;
}
V_179 -> V_14 = V_14 ;
V_179 -> V_13 = V_13 ;
V_179 -> V_190 = V_184 ;
V_179 -> V_191 = V_185 ;
V_174:
if ( V_169 )
F_70 ( & V_20 . V_147 ) ;
return V_10 ;
}
int F_72 ( int V_153 , struct V_192 * V_193 )
{
struct V_6 * V_6 = F_23 ( V_45 , V_153 ) ;
struct V_154 * V_194 ;
int V_10 = 0 ;
if ( ! V_6 ) {
F_16 ( L_29 , V_153 ) ;
return - V_67 ;
}
V_194 = & V_6 -> V_132 [ V_195 ] ;
if ( F_68 ( V_194 ) ) {
F_73 ( & V_20 . V_147 ) ;
if ( V_20 . V_24 ) {
V_10 = F_5 ( false ) ;
if ( V_10 ) {
F_74 ( & V_20 . V_147 ) ;
return V_10 ;
}
}
V_20 . V_34 = true ;
V_6 -> V_46 = V_20 . V_47 ;
V_6 -> V_48 = 0 ;
}
F_62 ( V_153 , V_194 , V_193 -> V_196 ) ;
if ( F_68 ( V_194 ) )
F_74 ( & V_20 . V_147 ) ;
if ( F_68 ( V_194 ) ) {
if ( F_75 ( & V_20 . V_147 ) ) {
if ( V_20 . V_34 )
F_13 ( V_35 ) ;
F_70 ( & V_20 . V_147 ) ;
} else
F_76 ( V_20 . V_49 ,
V_6 -> V_46 != V_20 . V_47 ) ;
V_10 = V_6 -> V_48 ;
}
return V_10 ;
}
unsigned int F_77 ( int V_197 )
{
unsigned int V_198 = 0 ;
struct V_6 * V_6 ;
struct V_154 * V_194 ;
V_6 = F_23 ( V_45 , V_197 ) ;
if ( ! V_6 )
return V_199 ;
V_194 = & V_6 -> V_132 [ V_195 ] ;
if ( ! F_68 ( V_194 ) )
return V_199 ;
if ( V_20 . V_38 )
V_198 = 60 * ( 1000 * 1000 * 1000 / V_20 . V_38 ) ;
V_198 = F_78 ( V_198 , V_20 . V_113 * 1000 ) ;
V_198 = F_78 ( V_198 , V_20 . V_37 * 1000 ) ;
return V_198 ;
}
