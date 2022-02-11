static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 V_9 = { 0 } ;
F_3 ( V_7 -> V_10 , & V_9 ) ;
return F_4 ( V_5 , V_11 , L_1 ,
V_9 . V_12 , V_9 . V_13 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 V_9 = { 0 } ;
F_3 ( V_7 -> V_10 , & V_9 ) ;
return F_4 ( V_5 , V_11 , L_2 ,
V_9 . V_14 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 V_9 = { 0 } ;
F_3 ( V_7 -> V_10 , & V_9 ) ;
return F_4 ( V_5 , V_11 , L_2 , V_9 . V_15 ) ;
}
static int F_7 ( bool V_16 )
{
int V_17 = - V_18 , V_19 = 0 ;
struct V_20 T_2 * V_21 = V_22 . V_23 ;
T_3 V_24 = F_8 ( F_9 () , V_22 . V_25 ) ;
if ( ! V_22 . V_26 )
return 0 ;
while ( ! F_10 ( F_9 () , V_24 ) ) {
V_19 = F_11 ( & V_21 -> V_19 ) ;
if ( V_19 & V_27 ) {
V_17 = 0 ;
if ( V_16 && ( V_19 & V_28 ) )
V_17 = - V_18 ;
break;
}
F_12 ( 3 ) ;
}
if ( F_13 ( ! V_17 ) )
V_22 . V_26 = false ;
else
F_14 ( L_3 , V_19 ) ;
return V_17 ;
}
static int F_15 ( T_4 V_29 )
{
int V_17 = - V_18 , V_30 ;
struct V_20 * V_21 =
(struct V_20 * ) V_22 . V_23 ;
static T_3 V_31 , V_32 ;
static int V_33 ;
unsigned int V_34 ;
if ( V_29 == V_35 ) {
if ( V_22 . V_36 )
F_15 ( V_37 ) ;
V_17 = F_7 ( false ) ;
if ( V_17 )
goto V_38;
} else
V_22 . V_36 = FALSE ;
if ( V_22 . V_39 ) {
V_34 = F_16 ( F_9 () , V_31 ) ;
if ( V_22 . V_39 > V_34 )
F_12 ( V_22 . V_39 - V_34 ) ;
}
if ( V_22 . V_40 ) {
if ( V_33 == 0 ) {
V_34 = F_17 ( F_9 () , V_32 ) ;
if ( V_34 < 60 * V_41 ) {
F_18 ( L_4 ) ;
V_17 = - V_18 ;
goto V_38;
}
V_32 = F_9 () ;
V_33 = V_22 . V_40 ;
}
V_33 -- ;
}
F_19 ( V_29 , & V_21 -> V_42 ) ;
F_19 ( 0 , & V_21 -> V_19 ) ;
V_22 . V_26 = true ;
V_17 = F_20 ( V_22 . V_43 , & V_29 ) ;
if ( V_17 < 0 ) {
F_14 ( L_5 ,
V_29 , V_17 ) ;
goto V_38;
}
V_17 = F_7 ( true ) ;
if ( V_22 . V_39 )
V_31 = F_9 () ;
if ( V_22 . V_43 -> V_44 -> V_45 )
F_21 ( V_22 . V_43 , V_17 ) ;
else
F_22 ( V_22 . V_43 , V_17 ) ;
V_38:
if ( V_29 == V_37 ) {
if ( F_23 ( V_17 ) ) {
F_24 (i) {
struct V_6 * V_46 = F_25 ( V_47 , V_30 ) ;
if ( ! V_46 )
continue;
if ( V_46 -> V_48 == V_22 . V_49 )
V_46 -> V_50 = V_17 ;
}
}
V_22 . V_49 ++ ;
F_26 ( & V_22 . V_51 ) ;
}
return V_17 ;
}
static void F_27 ( struct V_52 * V_53 , void * V_54 , int V_17 )
{
if ( V_17 < 0 )
F_18 ( L_6 ,
* ( T_4 * ) V_54 , V_17 ) ;
else
F_18 ( L_7 ,
* ( T_4 * ) V_54 , V_17 ) ;
}
static int F_28 ( struct V_6 * V_7 , T_5 V_55 )
{
int V_56 = - V_57 ;
T_6 V_19 = V_58 ;
struct V_59 V_60 = { V_61 , NULL } ;
struct V_59 V_62 = { sizeof( L_8 ) , L_8 } ;
struct V_59 V_63 = { 0 , NULL } ;
union V_64 * V_65 = NULL ;
struct V_66 * V_67 ;
V_19 = F_29 ( V_55 , L_9 , NULL , & V_60 ,
V_68 ) ;
if ( F_30 ( V_19 ) )
return - V_69 ;
V_65 = V_60 . V_70 ;
if ( ! V_65 || V_65 -> V_71 . V_72 != 1 ) {
F_18 ( L_10 ) ;
goto V_38;
}
V_67 = & ( V_7 -> V_73 ) ;
V_63 . V_74 = sizeof( struct V_66 ) ;
V_63 . V_70 = V_67 ;
V_19 = F_31 ( & ( V_65 -> V_71 . V_75 [ 0 ] ) ,
& V_62 , & V_63 ) ;
if ( F_30 ( V_19 ) ) {
F_18 ( L_11 , V_7 -> V_10 ) ;
goto V_38;
}
if ( V_67 -> V_76 != V_77 ) {
F_18 ( L_12 , V_7 -> V_10 ) ;
goto V_38;
}
if ( V_67 -> V_78 != V_79 ) {
F_18 ( L_13 , V_7 -> V_10 ) ;
goto V_38;
}
if ( V_67 -> V_80 != V_81 &&
V_67 -> V_80 != V_82 &&
V_67 -> V_80 != V_83 ) {
F_18 ( L_14 , V_7 -> V_10 ) ;
goto V_38;
}
V_56 = 0 ;
V_38:
F_32 ( V_60 . V_70 ) ;
return V_56 ;
}
int F_33 ( struct V_84 * * V_85 )
{
int V_86 ;
int V_87 = 0 ;
unsigned int V_30 , V_88 ;
T_7 V_89 ;
struct V_84 * V_90 , * V_91 ;
struct V_66 * V_67 ;
struct V_66 * V_92 ;
struct V_6 * V_7 , * V_93 ;
if ( ! F_34 ( & V_89 , V_94 ) )
return - V_95 ;
F_24 (i) {
V_90 = V_85 [ V_30 ] ;
if ( ! V_90 )
continue;
if ( F_35 ( V_30 , V_89 ) )
continue;
V_7 = F_25 ( V_47 , V_30 ) ;
if ( ! V_7 ) {
V_87 = - V_57 ;
goto V_96;
}
V_67 = & ( V_7 -> V_73 ) ;
F_36 ( V_30 , V_90 -> V_97 ) ;
F_36 ( V_30 , V_89 ) ;
if ( V_67 -> V_98 <= 1 )
continue;
V_86 = V_67 -> V_98 ;
if ( V_67 -> V_80 == V_81 )
V_90 -> V_99 = V_100 ;
else if ( V_67 -> V_80 == V_83 )
V_90 -> V_99 = V_101 ;
else if ( V_67 -> V_80 == V_82 )
V_90 -> V_99 = V_102 ;
F_24 (j) {
if ( V_30 == V_88 )
continue;
V_93 = F_25 ( V_47 , V_88 ) ;
if ( ! V_93 ) {
V_87 = - V_57 ;
goto V_96;
}
V_92 = & ( V_93 -> V_73 ) ;
if ( V_92 -> V_103 != V_67 -> V_103 )
continue;
if ( V_92 -> V_98 != V_86 ) {
V_87 = - V_57 ;
goto V_96;
}
if ( V_67 -> V_80 != V_92 -> V_80 ) {
V_87 = - V_57 ;
goto V_96;
}
F_36 ( V_88 , V_89 ) ;
F_36 ( V_88 , V_90 -> V_97 ) ;
}
F_24 (j) {
if ( V_30 == V_88 )
continue;
V_91 = V_85 [ V_88 ] ;
if ( ! V_91 )
continue;
V_93 = F_25 ( V_47 , V_88 ) ;
if ( ! V_93 ) {
V_87 = - V_57 ;
goto V_96;
}
V_92 = & ( V_93 -> V_73 ) ;
if ( V_92 -> V_103 != V_67 -> V_103 )
continue;
V_91 -> V_99 = V_90 -> V_99 ;
F_37 ( V_91 -> V_97 ,
V_90 -> V_97 ) ;
}
}
V_96:
F_24 (i) {
V_90 = V_85 [ V_30 ] ;
if ( ! V_90 )
continue;
if ( V_87 ) {
F_38 ( V_90 -> V_97 ) ;
F_36 ( V_30 , V_90 -> V_97 ) ;
V_90 -> V_99 = V_100 ;
}
}
F_39 ( V_89 ) ;
return V_87 ;
}
static int F_40 ( int V_104 )
{
struct V_105 * V_106 ;
T_8 V_107 ;
if ( V_104 >= 0 ) {
V_22 . V_43 = F_41 ( & V_108 ,
V_104 ) ;
if ( F_42 ( V_22 . V_43 ) ) {
F_14 ( L_15 ) ;
return - V_69 ;
}
V_106 = ( V_22 . V_43 ) -> V_109 ;
if ( ! V_106 ) {
F_14 ( L_16 ) ;
return - V_69 ;
}
V_107 = V_110 * V_106 -> V_111 ;
V_22 . V_25 = F_43 ( V_107 * V_112 ) ;
V_22 . V_39 = V_106 -> V_113 ;
V_22 . V_40 = V_106 -> V_114 ;
V_22 . V_115 = V_106 -> V_111 ;
V_22 . V_23 = F_44 ( V_106 -> V_116 , V_106 -> V_74 ) ;
if ( ! V_22 . V_23 ) {
F_14 ( L_17 ) ;
return - V_95 ;
}
V_22 . V_117 = true ;
}
return 0 ;
}
bool __weak F_45 ( void )
{
return false ;
}
int F_46 ( struct V_118 * V_90 )
{
struct V_59 V_119 = { V_61 , NULL } ;
union V_64 * V_120 , * V_121 ;
struct V_6 * V_7 ;
struct V_122 * V_123 ;
struct V_124 * V_125 ;
T_5 V_55 = V_90 -> V_55 ;
unsigned int V_126 , V_30 , V_127 ;
T_6 V_19 ;
int V_17 = - V_57 ;
V_19 = F_29 ( V_55 , L_18 , NULL , & V_119 ,
V_68 ) ;
if ( F_30 ( V_19 ) ) {
V_17 = - V_69 ;
goto V_128;
}
V_120 = (union V_64 * ) V_119 . V_70 ;
V_7 = F_47 ( sizeof( struct V_6 ) , V_94 ) ;
if ( ! V_7 ) {
V_17 = - V_95 ;
goto V_128;
}
V_121 = & V_120 -> V_71 . V_75 [ 0 ] ;
if ( V_121 -> type == V_129 ) {
V_126 = V_121 -> integer . V_130 ;
} else {
F_18 ( L_19 ,
V_121 -> type ) ;
goto V_131;
}
if ( V_126 != V_132 ) {
F_18 ( L_20 ,
V_126 , V_132 ) ;
goto V_131;
}
V_7 -> V_76 = V_126 ;
V_121 = & V_120 -> V_71 . V_75 [ 1 ] ;
if ( V_121 -> type == V_129 ) {
V_127 = V_121 -> integer . V_130 ;
} else {
F_18 ( L_21 ,
V_121 -> type ) ;
goto V_131;
}
if ( V_127 != V_133 ) {
F_18 ( L_22 ,
V_127 , V_133 ) ;
goto V_131;
}
for ( V_30 = 2 ; V_30 < V_126 ; V_30 ++ ) {
V_121 = & V_120 -> V_71 . V_75 [ V_30 ] ;
if ( V_121 -> type == V_129 ) {
V_7 -> V_134 [ V_30 - 2 ] . type = V_129 ;
V_7 -> V_134 [ V_30 - 2 ] . V_135 . V_136 = V_121 -> integer . V_130 ;
} else if ( V_121 -> type == V_137 ) {
V_123 = (struct V_122 * )
V_121 -> V_60 . V_70 ;
if ( V_123 -> V_138 == V_139 ) {
if ( V_22 . V_104 < 0 )
V_22 . V_104 = V_123 -> V_140 ;
else if ( V_22 . V_104 != V_123 -> V_140 ) {
F_18 ( L_23 ) ;
goto V_131;
}
} else if ( V_123 -> V_138 == V_141 ) {
if ( V_123 -> V_142 ) {
void T_2 * V_143 ;
V_143 = F_48 ( V_123 -> V_142 , V_123 -> V_144 / 8 ) ;
if ( ! V_143 )
goto V_131;
V_7 -> V_134 [ V_30 - 2 ] . V_145 = V_143 ;
}
} else {
if ( V_123 -> V_138 != V_146 || ! F_45 () ) {
F_18 ( L_24 , V_123 -> V_138 ) ;
goto V_131;
}
}
V_7 -> V_134 [ V_30 - 2 ] . type = V_137 ;
memcpy ( & V_7 -> V_134 [ V_30 - 2 ] . V_135 . V_147 , V_123 , sizeof( * V_123 ) ) ;
} else {
F_18 ( L_25 , V_30 , V_90 -> V_148 ) ;
goto V_131;
}
}
V_7 -> V_10 = V_90 -> V_148 ;
V_17 = F_28 ( V_7 , V_55 ) ;
if ( V_17 )
goto V_131;
if ( ! V_22 . V_117 ) {
V_17 = F_40 ( V_22 . V_104 ) ;
if ( V_17 )
goto V_131;
F_49 ( & V_22 . V_149 ) ;
F_50 ( & V_22 . V_51 ) ;
}
F_18 ( L_26 , V_90 -> V_148 ) ;
V_125 = F_51 ( V_90 -> V_148 ) ;
if ( ! V_125 ) {
V_17 = - V_150 ;
goto V_131;
}
F_25 ( V_47 , V_90 -> V_148 ) = V_7 ;
V_17 = F_52 ( & V_7 -> V_2 , & V_151 , & V_125 -> V_2 ,
L_27 ) ;
if ( V_17 ) {
F_25 ( V_47 , V_90 -> V_148 ) = NULL ;
goto V_131;
}
F_32 ( V_119 . V_70 ) ;
return 0 ;
V_131:
for ( V_30 = 2 ; V_30 < V_7 -> V_76 ; V_30 ++ ) {
void T_2 * V_143 = V_7 -> V_134 [ V_30 - 2 ] . V_145 ;
if ( V_143 )
F_53 ( V_143 ) ;
}
F_32 ( V_7 ) ;
V_128:
F_32 ( V_119 . V_70 ) ;
return V_17 ;
}
void F_54 ( struct V_118 * V_90 )
{
struct V_6 * V_7 ;
unsigned int V_30 ;
void T_2 * V_143 ;
V_7 = F_25 ( V_47 , V_90 -> V_148 ) ;
if ( ! V_7 )
return;
for ( V_30 = 2 ; V_30 < V_7 -> V_76 ; V_30 ++ ) {
V_143 = V_7 -> V_134 [ V_30 - 2 ] . V_145 ;
if ( V_143 )
F_53 ( V_143 ) ;
}
F_55 ( & V_7 -> V_2 ) ;
F_32 ( V_7 ) ;
}
int __weak F_56 ( int V_152 , struct V_122 * V_147 , T_8 * V_153 )
{
return - V_154 ;
}
int __weak F_57 ( int V_152 , struct V_122 * V_147 , T_8 V_153 )
{
return - V_154 ;
}
static int F_58 ( int V_155 , struct V_156 * V_157 , T_8 * V_153 )
{
int V_158 = 0 ;
void T_2 * V_159 = 0 ;
struct V_122 * V_147 = & V_157 -> V_135 . V_147 ;
if ( V_157 -> type == V_129 ) {
* V_153 = V_157 -> V_135 . V_136 ;
return V_158 ;
}
* V_153 = 0 ;
if ( V_147 -> V_138 == V_139 )
V_159 = F_59 ( V_147 -> V_142 ) ;
else if ( V_147 -> V_138 == V_141 )
V_159 = V_157 -> V_145 ;
else if ( V_147 -> V_138 == V_146 )
return F_56 ( V_155 , V_147 , V_153 ) ;
else
return F_60 ( ( V_160 ) V_147 -> V_142 ,
V_153 , V_147 -> V_144 ) ;
switch ( V_147 -> V_144 ) {
case 8 :
* V_153 = F_61 ( V_159 ) ;
break;
case 16 :
* V_153 = F_11 ( V_159 ) ;
break;
case 32 :
* V_153 = F_62 ( V_159 ) ;
break;
case 64 :
* V_153 = F_63 ( V_159 ) ;
break;
default:
F_18 ( L_28 ,
V_147 -> V_144 ) ;
V_158 = - V_57 ;
}
return V_158 ;
}
static int F_64 ( int V_155 , struct V_156 * V_157 , T_8 V_153 )
{
int V_158 = 0 ;
void T_2 * V_159 = 0 ;
struct V_122 * V_147 = & V_157 -> V_135 . V_147 ;
if ( V_147 -> V_138 == V_139 )
V_159 = F_59 ( V_147 -> V_142 ) ;
else if ( V_147 -> V_138 == V_141 )
V_159 = V_157 -> V_145 ;
else if ( V_147 -> V_138 == V_146 )
return F_57 ( V_155 , V_147 , V_153 ) ;
else
return F_65 ( ( V_160 ) V_147 -> V_142 ,
V_153 , V_147 -> V_144 ) ;
switch ( V_147 -> V_144 ) {
case 8 :
F_66 ( V_153 , V_159 ) ;
break;
case 16 :
F_19 ( V_153 , V_159 ) ;
break;
case 32 :
F_67 ( V_153 , V_159 ) ;
break;
case 64 :
F_68 ( V_153 , V_159 ) ;
break;
default:
F_18 ( L_29 ,
V_147 -> V_144 ) ;
V_158 = - V_57 ;
break;
}
return V_158 ;
}
int F_69 ( int V_152 , struct V_161 * V_162 )
{
struct V_6 * V_6 = F_25 ( V_47 , V_152 ) ;
struct V_156 * V_163 , * V_164 , * V_165 ,
* V_166 ;
T_8 V_167 , V_168 , V_169 ;
int V_17 = 0 , V_170 = 0 ;
if ( ! V_6 ) {
F_18 ( L_30 , V_152 ) ;
return - V_69 ;
}
V_163 = & V_6 -> V_134 [ V_171 ] ;
V_164 = & V_6 -> V_134 [ V_172 ] ;
V_165 = & V_6 -> V_134 [ V_173 ] ;
V_166 = & V_6 -> V_134 [ V_174 ] ;
if ( F_70 ( V_163 ) || F_70 ( V_164 ) ||
F_70 ( V_165 ) || F_70 ( V_166 ) ) {
V_170 = 1 ;
F_71 ( & V_22 . V_149 ) ;
if ( F_15 ( V_35 ) < 0 ) {
V_17 = - V_18 ;
goto V_175;
}
}
F_58 ( V_152 , V_163 , & V_167 ) ;
V_162 -> V_176 = V_167 ;
F_58 ( V_152 , V_164 , & V_168 ) ;
V_162 -> V_177 = V_168 ;
F_58 ( V_152 , V_166 , & V_169 ) ;
V_162 -> V_178 = V_169 ;
if ( ! V_167 || ! V_168 || ! V_169 )
V_17 = - V_57 ;
V_175:
if ( V_170 )
F_72 ( & V_22 . V_149 ) ;
return V_17 ;
}
int F_3 ( int V_152 , struct V_8 * V_179 )
{
struct V_6 * V_6 = F_25 ( V_47 , V_152 ) ;
struct V_156 * V_180 , * V_181 ,
* V_182 , * V_183 ;
T_8 V_13 , V_12 , V_165 , V_15 ;
int V_17 = 0 , V_170 = 0 ;
if ( ! V_6 ) {
F_18 ( L_30 , V_152 ) ;
return - V_69 ;
}
V_180 = & V_6 -> V_134 [ V_184 ] ;
V_181 = & V_6 -> V_134 [ V_185 ] ;
V_182 = & V_6 -> V_134 [ V_173 ] ;
V_183 = & V_6 -> V_134 [ V_186 ] ;
if ( ! F_73 ( V_182 ) )
V_182 = & V_6 -> V_134 [ V_174 ] ;
if ( F_70 ( V_180 ) || F_70 ( V_181 ) ||
F_70 ( V_183 ) || F_70 ( V_182 ) ) {
F_71 ( & V_22 . V_149 ) ;
V_170 = 1 ;
if ( F_15 ( V_35 ) < 0 ) {
V_17 = - V_18 ;
goto V_175;
}
}
F_58 ( V_152 , V_180 , & V_13 ) ;
F_58 ( V_152 , V_181 , & V_12 ) ;
F_58 ( V_152 , V_182 , & V_165 ) ;
V_15 = ( T_8 ) ( ~ ( ( T_8 ) 0 ) ) ;
if ( F_73 ( V_183 ) )
F_58 ( V_152 , V_183 , & V_15 ) ;
if ( ! V_13 || ! V_12 || ! V_165 ) {
V_17 = - V_57 ;
goto V_175;
}
V_179 -> V_13 = V_13 ;
V_179 -> V_12 = V_12 ;
V_179 -> V_14 = V_165 ;
V_179 -> V_15 = V_15 ;
V_175:
if ( V_170 )
F_72 ( & V_22 . V_149 ) ;
return V_17 ;
}
int F_74 ( int V_155 , struct V_187 * V_188 )
{
struct V_6 * V_6 = F_25 ( V_47 , V_155 ) ;
struct V_156 * V_189 ;
int V_17 = 0 ;
if ( ! V_6 ) {
F_18 ( L_30 , V_155 ) ;
return - V_69 ;
}
V_189 = & V_6 -> V_134 [ V_190 ] ;
if ( F_70 ( V_189 ) ) {
F_75 ( & V_22 . V_149 ) ;
if ( V_22 . V_26 ) {
V_17 = F_7 ( false ) ;
if ( V_17 ) {
F_76 ( & V_22 . V_149 ) ;
return V_17 ;
}
}
V_22 . V_36 = true ;
V_6 -> V_48 = V_22 . V_49 ;
V_6 -> V_50 = 0 ;
}
F_64 ( V_155 , V_189 , V_188 -> V_191 ) ;
if ( F_70 ( V_189 ) )
F_76 ( & V_22 . V_149 ) ;
if ( F_70 ( V_189 ) ) {
if ( F_77 ( & V_22 . V_149 ) ) {
if ( V_22 . V_36 )
F_15 ( V_37 ) ;
F_72 ( & V_22 . V_149 ) ;
} else
F_78 ( V_22 . V_51 ,
V_6 -> V_48 != V_22 . V_49 ) ;
V_17 = V_6 -> V_50 ;
}
return V_17 ;
}
unsigned int F_79 ( int V_192 )
{
unsigned int V_193 = 0 ;
struct V_6 * V_6 ;
struct V_156 * V_189 ;
V_6 = F_25 ( V_47 , V_192 ) ;
if ( ! V_6 )
return V_194 ;
V_189 = & V_6 -> V_134 [ V_190 ] ;
if ( ! F_70 ( V_189 ) )
return V_194 ;
if ( V_22 . V_40 )
V_193 = 60 * ( 1000 * 1000 * 1000 / V_22 . V_40 ) ;
V_193 = F_80 ( V_193 , V_22 . V_115 * 1000 ) ;
V_193 = F_80 ( V_193 , V_22 . V_39 * 1000 ) ;
return V_193 ;
}
