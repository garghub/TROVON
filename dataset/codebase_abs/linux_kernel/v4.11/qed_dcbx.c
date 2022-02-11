static bool F_1 ( T_1 V_1 )
{
return ! ! ( F_2 ( V_1 , V_2 ) ==
V_3 ) ;
}
static bool F_3 ( T_1 V_1 )
{
T_2 V_4 = F_2 ( V_1 , V_5 ) ;
if ( V_4 == V_6 )
return F_1 ( V_1 ) ;
return ! ! ( V_4 == V_7 ) ;
}
static bool F_4 ( T_1 V_1 )
{
return ! ! ( F_2 ( V_1 , V_2 ) ==
V_8 ) ;
}
static bool F_5 ( T_1 V_1 , T_2 type )
{
T_2 V_4 = F_2 ( V_1 , V_5 ) ;
if ( V_4 == V_6 )
return F_4 ( V_1 ) ;
return ! ! ( V_4 == type || V_4 == V_9 ) ;
}
static bool F_6 ( T_1 V_1 , T_3 V_10 , bool V_11 )
{
bool V_12 ;
if ( V_11 )
V_12 = F_3 ( V_1 ) ;
else
V_12 = F_1 ( V_1 ) ;
return ! ! ( V_12 && ( V_10 == V_13 ) ) ;
}
static bool F_7 ( T_1 V_1 , T_3 V_10 , bool V_11 )
{
bool V_14 ;
if ( V_11 )
V_14 = F_5 ( V_1 ,
V_15 ) ;
else
V_14 = F_4 ( V_1 ) ;
return ! ! ( V_14 && ( V_10 == V_16 ) ) ;
}
static bool F_8 ( T_1 V_1 , T_3 V_10 , bool V_11 )
{
bool V_12 ;
if ( V_11 )
V_12 = F_3 ( V_1 ) ;
else
V_12 = F_1 ( V_1 ) ;
return ! ! ( V_12 && ( V_10 == V_17 ) ) ;
}
static bool F_9 ( T_1 V_1 , T_3 V_10 , bool V_11 )
{
bool V_12 ;
if ( V_11 )
V_12 = F_3 ( V_1 ) ;
else
V_12 = F_1 ( V_1 ) ;
return ! ! ( V_12 && ( V_10 == V_18 ) ) ;
}
static bool F_10 ( T_1 V_1 , T_3 V_10 , bool V_11 )
{
bool V_14 ;
if ( V_11 )
V_14 = F_5 ( V_1 ,
V_19 ) ;
else
V_14 = F_4 ( V_1 ) ;
return ! ! ( V_14 && ( V_10 == V_20 ) ) ;
}
static void
F_11 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
enum V_25 V_26 ;
int V_27 ;
F_12 ( V_22 , V_28 , L_1 ,
V_24 -> V_29 ) ;
for ( V_27 = 0 ; V_27 < F_13 ( V_30 ) ; V_27 ++ ) {
V_26 = V_30 [ V_27 ] . V_26 ;
F_12 ( V_22 , V_28 ,
L_2 ,
V_30 [ V_27 ] . V_31 , V_24 -> V_32 [ V_26 ] . V_33 ,
V_24 -> V_32 [ V_26 ] . V_34 , V_24 -> V_32 [ V_26 ] . V_35 ,
V_24 -> V_32 [ V_26 ] . V_36 , V_22 -> V_37 . V_38 ) ;
}
}
static void
F_14 ( struct V_23 * V_24 ,
struct V_39 * V_40 ,
bool V_34 ,
bool V_33 ,
T_2 V_41 ,
T_2 V_36 ,
enum V_25 type ,
enum V_42 V_43 )
{
V_24 -> V_32 [ type ] . V_33 = V_33 ;
V_24 -> V_32 [ type ] . V_34 = V_34 ;
V_24 -> V_32 [ type ] . V_35 = V_41 ;
V_24 -> V_32 [ type ] . V_36 = V_36 ;
if ( V_40 -> V_43 == V_43 ) {
if ( V_43 == V_44 )
V_40 -> V_45 = V_36 ;
else
V_40 -> V_46 = V_36 ;
}
}
static void
F_15 ( struct V_23 * V_24 ,
struct V_21 * V_22 ,
bool V_34 ,
bool V_33 ,
T_2 V_41 , T_2 V_36 , enum V_25 type )
{
struct V_39 * V_40 = & V_22 -> V_37 ;
enum V_42 V_43 ;
enum V_25 V_26 ;
char * V_31 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < F_13 ( V_30 ) ; V_27 ++ ) {
V_26 = V_30 [ V_27 ] . V_26 ;
if ( type != V_26 )
continue;
V_43 = V_30 [ V_27 ] . V_43 ;
V_31 = V_30 [ V_27 ] . V_31 ;
F_14 ( V_24 , V_40 , V_34 , V_33 ,
V_41 , V_36 , type , V_43 ) ;
}
}
static bool
F_16 ( struct V_21 * V_22 ,
T_1 V_47 ,
T_3 V_26 , enum V_25 * type , bool V_11 )
{
if ( F_8 ( V_47 , V_26 , V_11 ) ) {
* type = V_48 ;
} else if ( F_9 ( V_47 , V_26 , V_11 ) ) {
* type = V_49 ;
} else if ( F_7 ( V_47 , V_26 , V_11 ) ) {
* type = V_50 ;
} else if ( F_6 ( V_47 , V_26 , V_11 ) ) {
* type = V_51 ;
} else if ( F_10 ( V_47 , V_26 , V_11 ) ) {
* type = V_52 ;
} else {
* type = V_53 ;
F_17 ( V_22 ,
L_3 ,
V_26 , V_47 ) ;
return false ;
}
return true ;
}
static int
F_18 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
struct V_54 * V_55 ,
T_1 V_56 , int V_57 , T_2 V_58 )
{
T_2 V_36 , V_59 ;
enum V_25 type ;
bool V_34 , V_11 ;
T_3 V_60 ;
int V_35 ;
int V_27 ;
F_12 ( V_22 , V_28 , L_4 , V_57 ) ;
V_11 = ( V_58 == V_61 ) ;
for ( V_27 = 0 ; V_27 < V_57 ; V_27 ++ ) {
V_60 = F_2 ( V_55 [ V_27 ] . V_62 ,
V_63 ) ;
V_59 = F_2 ( V_55 [ V_27 ] . V_62 ,
V_64 ) ;
V_35 = F_19 ( V_59 ) - 1 ;
if ( V_35 < 0 ) {
F_17 ( V_22 , L_5 ) ;
return - V_65 ;
}
V_36 = F_20 ( V_56 , V_35 ) ;
if ( F_16 ( V_22 , V_55 [ V_27 ] . V_62 ,
V_60 , & type , V_11 ) ) {
V_34 = ! ( type == V_51 ) ;
F_15 ( V_24 , V_22 , V_34 , true ,
V_35 , V_36 , type ) ;
}
}
if ( ! V_24 -> V_32 [ V_52 ] . V_33 &&
V_24 -> V_32 [ V_49 ] . V_33 ) {
V_36 = V_24 -> V_32 [ V_49 ] . V_36 ;
V_35 = V_24 -> V_32 [ V_49 ] . V_35 ;
F_15 ( V_24 , V_22 , true , true ,
V_35 , V_36 , V_52 ) ;
}
V_36 = V_24 -> V_32 [ V_51 ] . V_36 ;
V_35 = V_24 -> V_32 [ V_51 ] . V_35 ;
for ( type = 0 ; type < V_53 ; type ++ ) {
if ( V_24 -> V_32 [ type ] . V_33 )
continue;
V_34 = ! ( type == V_51 ) ;
F_15 ( V_24 , V_22 , V_34 , true ,
V_35 , V_36 , type ) ;
}
return 0 ;
}
static int F_21 ( struct V_21 * V_22 )
{
struct V_66 * V_67 ;
struct V_54 * V_55 ;
struct V_23 V_68 = { 0 } ;
struct V_69 * V_70 ;
struct V_39 * V_40 ;
T_1 V_56 , V_71 ;
T_2 V_58 ;
int V_72 ;
int V_73 = 0 ;
V_71 = V_22 -> V_74 -> V_75 . V_71 ;
V_58 = F_2 ( V_71 , V_76 ) ;
V_67 = & V_22 -> V_74 -> V_75 . V_77 . V_78 ;
V_55 = V_67 -> V_79 ;
V_70 = & V_22 -> V_74 -> V_75 . V_77 . V_80 ;
V_56 = V_70 -> V_56 [ 0 ] ;
V_40 = & V_22 -> V_37 ;
V_72 = F_2 ( V_67 -> V_71 , V_81 ) ;
V_73 = F_18 ( V_22 , & V_68 , V_55 , V_56 ,
V_72 , V_58 ) ;
if ( V_73 )
return V_73 ;
V_40 -> V_38 = F_2 ( V_70 -> V_71 , V_82 ) ;
V_68 . V_83 = V_22 -> V_84 ;
V_68 . V_29 = ! ! V_58 ;
F_11 ( V_22 , & V_68 ) ;
memcpy ( & V_22 -> V_74 -> V_85 , & V_68 ,
sizeof( struct V_23 ) ) ;
return 0 ;
}
static int
F_22 ( struct V_21 * V_22 ,
struct V_86 * V_87 ,
struct V_88 * V_24 ,
enum V_89 type )
{
T_1 V_90 , V_91 ;
int V_92 = 0 ;
int V_73 = 0 ;
do {
if ( type == V_93 ) {
F_23 ( V_22 , V_87 , V_24 -> V_94 ,
V_24 -> V_95 , V_24 -> V_96 ) ;
V_90 = V_24 -> V_94 -> V_90 ;
V_91 = V_24 -> V_94 -> V_91 ;
} else {
F_23 ( V_22 , V_87 , V_24 -> V_97 ,
V_24 -> V_95 , V_24 -> V_96 ) ;
V_90 = V_24 -> V_97 -> V_90 ;
V_91 = V_24 -> V_97 -> V_91 ;
}
V_92 ++ ;
F_12 ( V_22 ,
V_28 ,
L_6 ,
type , V_92 , V_90 , V_91 ) ;
} while ( ( V_90 != V_91 ) &&
( V_92 < V_98 ) );
if ( V_92 >= V_98 ) {
F_17 ( V_22 ,
L_7 ,
type , V_92 , V_90 , V_91 ) ;
V_73 = - V_99 ;
}
return V_73 ;
}
static void
F_24 ( struct V_21 * V_22 ,
struct V_100 * V_101 ,
struct V_23 * V_102 )
{
T_2 V_103 ;
V_101 -> V_104 = V_105 ;
V_101 -> V_106 = V_105 ;
V_101 -> V_107 = V_105 ;
V_101 -> V_108 = V_105 ;
if ( V_102 -> V_32 [ V_49 ] . V_33 &&
V_102 -> V_32 [ V_49 ] . V_34 )
V_101 -> V_104 = V_102 -> V_32 [ V_49 ] . V_35 ;
if ( V_102 -> V_32 [ V_52 ] . V_33 &&
V_102 -> V_32 [ V_52 ] . V_34 ) {
V_103 = V_102 -> V_32 [ V_52 ] . V_35 ;
V_101 -> V_106 = V_103 ;
}
if ( V_102 -> V_32 [ V_50 ] . V_33 &&
V_102 -> V_32 [ V_50 ] . V_34 )
V_101 -> V_107 = V_102 -> V_32 [ V_50 ] . V_35 ;
if ( V_102 -> V_32 [ V_48 ] . V_33 &&
V_102 -> V_32 [ V_48 ] . V_34 )
V_101 -> V_108 = V_102 -> V_32 [ V_48 ] . V_35 ;
if ( V_102 -> V_32 [ V_51 ] . V_33 &&
V_102 -> V_32 [ V_51 ] . V_34 )
V_101 -> V_109 = V_102 -> V_32 [ V_51 ] . V_35 ;
F_12 ( V_22 , V_28 ,
L_8 ,
V_101 -> V_107 , V_101 -> V_104 , V_101 -> V_106 , V_101 -> V_108 ,
V_101 -> V_109 ) ;
}
static void
F_25 ( struct V_21 * V_22 ,
struct V_66 * V_67 ,
struct V_54 * V_55 ,
struct V_110 * V_111 , bool V_11 )
{
struct V_112 * V_62 ;
T_2 V_113 ;
int V_27 ;
V_111 -> V_114 = F_2 ( V_67 -> V_71 ,
V_115 ) ;
V_111 -> V_116 = F_2 ( V_67 -> V_71 , V_117 ) ;
V_111 -> V_118 = F_2 ( V_67 -> V_71 , V_119 ) ;
V_111 -> V_120 = F_2 ( V_67 -> V_71 ,
V_81 ) ;
for ( V_27 = 0 ; V_27 < V_121 ; V_27 ++ ) {
V_62 = & V_111 -> V_122 [ V_27 ] ;
if ( V_11 ) {
T_2 V_123 ;
T_1 V_103 ;
V_123 = F_2 ( V_55 [ V_27 ] . V_62 ,
V_5 ) ;
switch ( V_123 ) {
case V_6 :
V_103 = F_2 ( V_55 [ V_27 ] . V_62 ,
V_2 ) ;
V_62 -> V_123 = V_103 ?
V_124 :
V_125 ;
break;
case V_7 :
V_62 -> V_123 = V_125 ;
break;
case V_15 :
V_62 -> V_123 = V_126 ;
break;
case V_19 :
V_62 -> V_123 = V_127 ;
break;
case V_9 :
V_62 -> V_123 = V_124 ;
break;
}
} else {
V_62 -> V_12 = ! ( F_2 ( V_55 [ V_27 ] . V_62 ,
V_2 ) ) ;
}
V_113 = F_2 ( V_55 [ V_27 ] . V_62 , V_64 ) ;
V_62 -> V_41 = F_19 ( V_113 ) - 1 ;
V_62 -> V_10 = F_2 ( V_55 [ V_27 ] . V_62 ,
V_63 ) ;
F_16 ( V_22 , V_55 [ V_27 ] . V_62 ,
V_62 -> V_10 ,
& V_62 -> V_128 , V_11 ) ;
}
F_12 ( V_22 , V_28 ,
L_9 ,
V_111 -> V_114 , V_111 -> V_116 ,
V_111 -> V_118 ) ;
}
static void
F_26 ( struct V_21 * V_22 ,
T_1 V_129 , struct V_110 * V_111 )
{
T_2 V_130 ;
V_111 -> V_129 . V_131 = F_2 ( V_129 , V_132 ) ;
V_111 -> V_129 . V_133 = F_2 ( V_129 , V_134 ) ;
V_111 -> V_129 . V_135 = F_2 ( V_129 , V_136 ) ;
V_130 = F_2 ( V_129 , V_137 ) ;
V_111 -> V_129 . V_41 [ 0 ] = ! ! ( V_130 & V_138 ) ;
V_111 -> V_129 . V_41 [ 1 ] = ! ! ( V_130 & V_139 ) ;
V_111 -> V_129 . V_41 [ 2 ] = ! ! ( V_130 & V_140 ) ;
V_111 -> V_129 . V_41 [ 3 ] = ! ! ( V_130 & V_141 ) ;
V_111 -> V_129 . V_41 [ 4 ] = ! ! ( V_130 & V_142 ) ;
V_111 -> V_129 . V_41 [ 5 ] = ! ! ( V_130 & V_143 ) ;
V_111 -> V_129 . V_41 [ 6 ] = ! ! ( V_130 & V_144 ) ;
V_111 -> V_129 . V_41 [ 7 ] = ! ! ( V_130 & V_145 ) ;
F_12 ( V_22 , V_28 ,
L_10 ,
V_111 -> V_129 . V_131 , V_130 ) ;
}
static void
F_27 ( struct V_21 * V_22 ,
struct V_69 * V_70 ,
struct V_110 * V_111 )
{
T_1 V_146 [ 2 ] , V_147 [ 2 ] , V_113 ;
int V_27 ;
V_111 -> V_148 = F_2 ( V_70 -> V_71 ,
V_149 ) ;
V_111 -> V_150 = F_2 ( V_70 -> V_71 ,
V_151 ) ;
V_111 -> V_152 = F_2 ( V_70 -> V_71 , V_153 ) ;
V_111 -> V_154 = F_2 ( V_70 -> V_71 ,
V_82 ) ;
F_12 ( V_22 , V_28 ,
L_11 ,
V_111 -> V_148 ,
V_111 -> V_152 ,
V_70 -> V_56 [ 0 ] , V_111 -> V_154 ) ;
if ( V_111 -> V_150 && ! V_111 -> V_154 ) {
V_111 -> V_154 = V_155 ;
F_12 ( V_22 , V_28 ,
L_12 ,
V_111 -> V_154 ) ;
}
V_146 [ 0 ] = F_28 ( V_70 -> V_156 [ 0 ] ) ;
V_146 [ 1 ] = F_28 ( V_70 -> V_156 [ 1 ] ) ;
V_147 [ 0 ] = F_28 ( V_70 -> V_157 [ 0 ] ) ;
V_147 [ 1 ] = F_28 ( V_70 -> V_157 [ 1 ] ) ;
V_113 = V_70 -> V_56 [ 0 ] ;
for ( V_27 = 0 ; V_27 < V_155 ; V_27 ++ ) {
V_111 -> V_158 [ V_27 ] = ( ( T_2 * ) V_146 ) [ V_27 ] ;
V_111 -> V_159 [ V_27 ] = ( ( T_2 * ) V_147 ) [ V_27 ] ;
V_111 -> V_160 [ V_27 ] = F_20 ( V_113 , V_27 ) ;
F_12 ( V_22 , V_28 ,
L_13 ,
V_27 , V_111 -> V_158 [ V_27 ] ,
V_111 -> V_159 [ V_27 ] ) ;
}
}
static void
F_29 ( struct V_21 * V_22 ,
struct V_66 * V_67 ,
struct V_54 * V_55 ,
struct V_69 * V_70 ,
T_1 V_129 , struct V_110 * V_111 , bool V_11 )
{
F_25 ( V_22 , V_67 , V_55 , V_111 , V_11 ) ;
F_27 ( V_22 , V_70 , V_111 ) ;
F_26 ( V_22 , V_129 , V_111 ) ;
}
static void
F_30 ( struct V_21 * V_22 ,
struct V_86 * V_87 , struct V_161 * V_162 )
{
struct V_163 * V_164 ;
V_164 = & V_22 -> V_74 -> V_165 . V_77 ;
F_29 ( V_22 , & V_164 -> V_78 ,
V_164 -> V_78 . V_79 , & V_164 -> V_80 ,
V_164 -> V_129 , & V_162 -> V_166 . V_162 , false ) ;
V_162 -> V_166 . V_167 = true ;
}
static void
F_31 ( struct V_21 * V_22 ,
struct V_86 * V_87 , struct V_161 * V_162 )
{
struct V_163 * V_164 ;
V_164 = & V_22 -> V_74 -> V_168 . V_77 ;
F_29 ( V_22 , & V_164 -> V_78 ,
V_164 -> V_78 . V_79 , & V_164 -> V_80 ,
V_164 -> V_129 , & V_162 -> V_168 . V_162 , false ) ;
V_162 -> V_168 . V_167 = true ;
}
static void
F_32 ( struct V_21 * V_22 ,
struct V_86 * V_87 ,
struct V_161 * V_162 )
{
struct V_169 * V_170 ;
struct V_23 * V_102 ;
struct V_163 * V_164 ;
bool V_135 , V_171 ;
T_1 V_71 ;
bool V_103 ;
V_71 = V_22 -> V_74 -> V_75 . V_71 ;
V_170 = & V_162 -> V_75 ;
V_135 = ! ! ( F_2 ( V_71 , V_76 ) !=
V_172 ) ;
if ( ! V_135 ) {
V_170 -> V_135 = V_135 ;
V_170 -> V_167 = false ;
return;
}
V_164 = & V_22 -> V_74 -> V_75 . V_77 ;
V_102 = & V_22 -> V_74 -> V_85 ;
V_103 = ! ! ( F_2 ( V_71 , V_76 ) ==
V_61 ) ;
V_170 -> V_11 = V_103 ;
V_103 = ! ! ( F_2 ( V_71 , V_76 ) ==
V_173 ) ;
V_170 -> V_174 = V_103 ;
F_12 ( V_22 , V_28 , L_14 ,
V_170 -> V_11 , V_170 -> V_174 ) ;
F_29 ( V_22 , & V_164 -> V_78 ,
V_164 -> V_78 . V_79 , & V_164 -> V_80 ,
V_164 -> V_129 , & V_162 -> V_75 . V_162 ,
V_170 -> V_11 ) ;
F_24 ( V_22 , & V_170 -> V_175 , V_102 ) ;
V_171 = F_2 ( V_164 -> V_78 . V_71 , V_119 ) ;
V_170 -> V_171 = V_171 ;
V_170 -> V_135 = V_135 ;
V_170 -> V_167 = true ;
}
static void
F_33 ( struct V_21 * V_22 ,
struct V_86 * V_87 ,
struct V_161 * V_162 )
{
struct V_176 * V_177 ;
V_177 = & V_22 -> V_74 -> V_178 [ V_179 ] ;
memcpy ( V_162 -> V_178 . V_180 , V_177 -> V_180 ,
F_13 ( V_177 -> V_180 ) ) ;
memcpy ( V_162 -> V_178 . V_181 , V_177 -> V_181 ,
F_13 ( V_177 -> V_181 ) ) ;
}
static void
F_34 ( struct V_21 * V_22 ,
struct V_86 * V_87 ,
struct V_161 * V_162 )
{
struct V_182 * V_183 ;
V_183 = & V_22 -> V_74 -> V_94 [ V_179 ] ;
memcpy ( V_162 -> V_94 . V_184 , V_183 -> V_184 ,
F_13 ( V_183 -> V_184 ) ) ;
memcpy ( V_162 -> V_94 . V_185 , V_183 -> V_185 ,
F_13 ( V_183 -> V_185 ) ) ;
}
static int
F_35 ( struct V_21 * V_22 , struct V_86 * V_87 ,
struct V_161 * V_111 ,
enum V_89 type )
{
switch ( type ) {
case V_186 :
F_31 ( V_22 , V_87 , V_111 ) ;
break;
case V_187 :
F_30 ( V_22 , V_87 , V_111 ) ;
break;
case V_188 :
F_32 ( V_22 , V_87 , V_111 ) ;
break;
case V_93 :
F_34 ( V_22 , V_87 , V_111 ) ;
break;
case V_189 :
F_33 ( V_22 , V_87 , V_111 ) ;
break;
default:
F_17 ( V_22 , L_15 , type ) ;
return - V_65 ;
}
return 0 ;
}
static int
F_36 ( struct V_21 * V_22 , struct V_86 * V_87 )
{
struct V_88 V_68 ;
int V_73 = 0 ;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
V_68 . V_95 = V_22 -> V_190 -> V_191 + F_37 ( struct V_192 ,
V_193 ) ;
V_68 . V_178 = V_22 -> V_74 -> V_178 ;
V_68 . V_96 = sizeof( struct V_176 ) ;
F_23 ( V_22 , V_87 , V_68 . V_178 , V_68 . V_95 , V_68 . V_96 ) ;
return V_73 ;
}
static int
F_38 ( struct V_21 * V_22 ,
struct V_86 * V_87 ,
enum V_89 type )
{
struct V_88 V_68 ;
int V_73 = 0 ;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
V_68 . V_95 = V_22 -> V_190 -> V_191 + F_37 ( struct V_192 ,
V_194 ) ;
V_68 . V_94 = V_22 -> V_74 -> V_94 ;
V_68 . V_96 = sizeof( struct V_182 ) ;
V_73 = F_22 ( V_22 , V_87 , & V_68 , type ) ;
return V_73 ;
}
static int
F_39 ( struct V_21 * V_22 ,
struct V_86 * V_87 ,
enum V_89 type )
{
struct V_88 V_68 ;
int V_73 = 0 ;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
V_68 . V_95 = V_22 -> V_190 -> V_191 +
F_37 ( struct V_192 , V_195 ) ;
V_68 . V_97 = & V_22 -> V_74 -> V_75 ;
V_68 . V_96 = sizeof( struct V_196 ) ;
V_73 = F_22 ( V_22 , V_87 , & V_68 , type ) ;
return V_73 ;
}
static int
F_40 ( struct V_21 * V_22 ,
struct V_86 * V_87 , enum V_89 type )
{
struct V_88 V_68 ;
int V_73 = 0 ;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
V_68 . V_95 = V_22 -> V_190 -> V_191 +
F_37 ( struct V_192 , V_197 ) ;
V_68 . V_97 = & V_22 -> V_74 -> V_168 ;
V_68 . V_96 = sizeof( struct V_196 ) ;
V_73 = F_22 ( V_22 , V_87 , & V_68 , type ) ;
return V_73 ;
}
static int
F_41 ( struct V_21 * V_22 , struct V_86 * V_87 )
{
struct V_88 V_68 ;
int V_73 = 0 ;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
V_68 . V_95 = V_22 -> V_190 -> V_191 +
F_37 ( struct V_192 , V_198 ) ;
V_68 . V_165 = & V_22 -> V_74 -> V_165 ;
V_68 . V_96 = sizeof( struct V_199 ) ;
F_23 ( V_22 , V_87 , V_68 . V_165 , V_68 . V_95 , V_68 . V_96 ) ;
return V_73 ;
}
static int F_42 ( struct V_21 * V_22 ,
struct V_86 * V_87 , enum V_89 type )
{
int V_73 = - V_65 ;
switch ( type ) {
case V_188 :
V_73 = F_39 ( V_22 , V_87 , type ) ;
break;
case V_186 :
V_73 = F_40 ( V_22 , V_87 , type ) ;
break;
case V_187 :
V_73 = F_41 ( V_22 , V_87 ) ;
break;
case V_93 :
V_73 = F_38 ( V_22 , V_87 , type ) ;
break;
case V_189 :
V_73 = F_36 ( V_22 , V_87 ) ;
break;
default:
F_17 ( V_22 , L_15 , type ) ;
}
return V_73 ;
}
void F_43 ( struct V_21 * V_200 , T_1 V_201 )
{
struct V_202 * V_203 = V_200 -> V_204 -> V_205 . V_206 ;
void * V_207 = V_200 -> V_204 -> V_208 ;
if ( V_207 && V_203 -> V_209 )
V_203 -> V_209 ( V_207 , & V_200 -> V_74 -> V_210 , V_201 ) ;
}
int
F_44 ( struct V_21 * V_22 ,
struct V_86 * V_87 , enum V_89 type )
{
int V_73 = 0 ;
V_73 = F_42 ( V_22 , V_87 , type ) ;
if ( V_73 )
return V_73 ;
if ( type == V_188 ) {
V_73 = F_21 ( V_22 ) ;
if ( ! V_73 ) {
F_45 ( V_22 , V_87 ) ;
F_46 ( V_22 ) ;
}
}
F_35 ( V_22 , V_87 , & V_22 -> V_74 -> V_210 , type ) ;
F_43 ( V_22 , type ) ;
return V_73 ;
}
int F_47 ( struct V_21 * V_22 )
{
int V_73 = 0 ;
V_22 -> V_74 = F_48 ( sizeof( * V_22 -> V_74 ) , V_211 ) ;
if ( ! V_22 -> V_74 )
V_73 = - V_212 ;
return V_73 ;
}
void F_49 ( struct V_21 * V_22 ,
struct V_213 * V_74 )
{
F_50 ( V_22 -> V_74 ) ;
}
static void F_51 ( struct V_214 * V_24 ,
struct V_23 * V_215 ,
enum V_25 type )
{
V_24 -> V_216 = V_215 -> V_32 [ type ] . V_34 ;
V_24 -> V_217 = V_215 -> V_32 [ type ] . V_35 ;
V_24 -> V_218 = V_215 -> V_32 [ type ] . V_36 ;
}
void F_52 ( struct V_23 * V_215 ,
struct V_219 * V_220 )
{
struct V_214 * V_221 ;
bool V_222 = false ;
V_220 -> V_83 = V_215 -> V_83 ;
V_222 = V_215 -> V_32 [ V_48 ] . V_33 ;
V_220 -> V_223 = V_222 ;
V_222 = V_215 -> V_32 [ V_49 ] . V_33 ;
V_220 -> V_224 = V_222 ;
V_222 = V_215 -> V_32 [ V_52 ] . V_33 ;
V_220 -> V_224 = V_222 ;
V_222 = V_215 -> V_32 [ V_50 ] . V_33 ;
V_220 -> V_225 = V_222 ;
V_222 = V_215 -> V_32 [ V_51 ] . V_33 ;
V_220 -> V_226 = V_222 ;
V_221 = & V_220 -> V_227 ;
F_51 ( V_221 , V_215 , V_48 ) ;
V_221 = & V_220 -> V_228 ;
if ( V_215 -> V_32 [ V_49 ] . V_33 )
F_51 ( V_221 , V_215 ,
V_49 ) ;
if ( V_215 -> V_32 [ V_52 ] . V_33 )
F_51 ( V_221 , V_215 ,
V_52 ) ;
V_221 = & V_220 -> V_229 ;
F_51 ( V_221 , V_215 , V_50 ) ;
V_221 = & V_220 -> V_230 ;
F_51 ( V_221 , V_215 , V_51 ) ;
}
static int F_53 ( struct V_21 * V_22 ,
struct V_161 * V_231 ,
enum V_89 type )
{
struct V_86 * V_87 ;
int V_73 ;
if ( F_54 ( V_22 -> V_204 ) )
return - V_65 ;
V_87 = F_55 ( V_22 ) ;
if ( ! V_87 )
return - V_232 ;
V_73 = F_42 ( V_22 , V_87 , type ) ;
if ( V_73 )
goto V_233;
V_73 = F_35 ( V_22 , V_87 , V_231 , type ) ;
V_233:
F_56 ( V_22 , V_87 ) ;
return V_73 ;
}
static void
F_57 ( struct V_21 * V_22 ,
T_1 * V_129 , struct V_110 * V_111 )
{
T_2 V_130 = 0 ;
int V_27 ;
* V_129 &= ~ V_234 ;
if ( V_111 -> V_129 . V_131 )
* V_129 |= V_235 ;
else
* V_129 &= ~ V_235 ;
if ( V_111 -> V_129 . V_135 )
* V_129 |= V_236 ;
else
* V_129 &= ~ V_236 ;
* V_129 &= ~ V_237 ;
* V_129 |= ( T_1 ) V_111 -> V_129 . V_133 << V_238 ;
for ( V_27 = 0 ; V_27 < V_155 ; V_27 ++ )
if ( V_111 -> V_129 . V_41 [ V_27 ] )
V_130 |= F_58 ( V_27 ) ;
* V_129 &= ~ V_239 ;
* V_129 |= ( V_130 << V_240 ) ;
F_12 ( V_22 , V_28 , L_16 , * V_129 ) ;
}
static void
F_59 ( struct V_21 * V_22 ,
struct V_69 * V_70 ,
struct V_110 * V_111 )
{
T_2 * V_146 , * V_147 ;
T_1 V_103 ;
int V_27 ;
if ( V_111 -> V_148 )
V_70 -> V_71 |= V_241 ;
else
V_70 -> V_71 &= ~ V_241 ;
if ( V_111 -> V_152 )
V_70 -> V_71 |= V_242 ;
else
V_70 -> V_71 &= ~ V_242 ;
if ( V_111 -> V_150 )
V_70 -> V_71 |= V_243 ;
else
V_70 -> V_71 &= ~ V_243 ;
V_70 -> V_71 &= ~ V_244 ;
V_70 -> V_71 |= ( T_1 ) V_111 -> V_154 << V_245 ;
V_146 = ( T_2 * ) & V_70 -> V_156 [ 0 ] ;
V_147 = ( T_2 * ) & V_70 -> V_157 [ 0 ] ;
V_70 -> V_56 [ 0 ] = 0 ;
for ( V_27 = 0 ; V_27 < V_155 ; V_27 ++ ) {
V_146 [ V_27 ] = V_111 -> V_158 [ V_27 ] ;
V_147 [ V_27 ] = V_111 -> V_159 [ V_27 ] ;
V_103 = ( ( ( T_1 ) V_111 -> V_160 [ V_27 ] ) << ( ( 7 - V_27 ) * 4 ) ) ;
V_70 -> V_56 [ 0 ] |= V_103 ;
}
for ( V_27 = 0 ; V_27 < 2 ; V_27 ++ ) {
V_70 -> V_156 [ V_27 ] = F_60 ( V_70 -> V_156 [ V_27 ] ) ;
V_70 -> V_157 [ V_27 ] = F_60 ( V_70 -> V_157 [ V_27 ] ) ;
}
}
static void
F_61 ( struct V_21 * V_22 ,
struct V_66 * V_67 ,
struct V_110 * V_111 , bool V_11 )
{
T_1 * V_62 ;
int V_27 ;
if ( V_111 -> V_114 )
V_67 -> V_71 |= V_246 ;
else
V_67 -> V_71 &= ~ V_246 ;
if ( V_111 -> V_116 )
V_67 -> V_71 |= V_247 ;
else
V_67 -> V_71 &= ~ V_247 ;
V_67 -> V_71 &= ~ V_248 ;
V_67 -> V_71 |= ( T_1 ) V_111 -> V_120 <<
V_249 ;
for ( V_27 = 0 ; V_27 < V_121 ; V_27 ++ ) {
V_62 = & V_67 -> V_79 [ V_27 ] . V_62 ;
* V_62 = 0 ;
if ( V_11 ) {
* V_62 &= ~ ( V_250 | V_251 ) ;
switch ( V_111 -> V_122 [ V_27 ] . V_123 ) {
case V_125 :
* V_62 |= ( ( T_1 ) V_7 <<
V_252 ) ;
* V_62 |= ( ( T_1 ) V_3 <<
V_253 ) ;
break;
case V_126 :
* V_62 |= ( ( T_1 ) V_15 <<
V_252 ) ;
* V_62 |= ( ( T_1 ) V_8 <<
V_253 ) ;
break;
case V_127 :
* V_62 |= ( ( T_1 ) V_19 <<
V_252 ) ;
* V_62 |= ( ( T_1 ) V_8 <<
V_253 ) ;
break;
case V_124 :
* V_62 |= ( ( T_1 ) V_9 <<
V_252 ) ;
* V_62 |= ( ( T_1 ) V_8 <<
V_253 ) ;
break;
}
} else {
* V_62 &= ~ V_251 ;
if ( V_111 -> V_122 [ V_27 ] . V_12 )
* V_62 |= ( ( T_1 ) V_3 <<
V_253 ) ;
else
* V_62 |= ( ( T_1 ) V_8 <<
V_253 ) ;
}
* V_62 &= ~ V_254 ;
* V_62 |= ( ( T_1 ) V_111 -> V_122 [ V_27 ] . V_10 <<
V_255 ) ;
* V_62 &= ~ V_256 ;
* V_62 |= ( ( T_1 ) ( V_111 -> V_122 [ V_27 ] . V_41 ) <<
V_257 ) ;
}
}
static void
F_62 ( struct V_21 * V_22 ,
struct V_199 * V_165 ,
struct V_258 * V_162 )
{
bool V_11 = false ;
V_165 -> V_71 = 0 ;
memcpy ( & V_165 -> V_77 ,
& V_22 -> V_74 -> V_75 . V_77 ,
sizeof( V_165 -> V_77 ) ) ;
if ( V_162 -> V_135 ) {
V_165 -> V_259 = V_162 -> V_260 ;
V_11 = ! ! ( V_162 -> V_260 & V_61 ) ;
} else {
V_165 -> V_259 = V_172 ;
}
if ( V_162 -> V_261 & V_262 )
F_57 ( V_22 , & V_165 -> V_77 . V_129 ,
& V_162 -> V_259 . V_162 ) ;
if ( V_162 -> V_261 & V_263 )
F_59 ( V_22 , & V_165 -> V_77 . V_80 ,
& V_162 -> V_259 . V_162 ) ;
if ( V_162 -> V_261 & V_264 )
F_61 ( V_22 , & V_165 -> V_77 . V_78 ,
& V_162 -> V_259 . V_162 , V_11 ) ;
}
int F_63 ( struct V_21 * V_22 , struct V_86 * V_87 ,
struct V_258 * V_162 , bool V_265 )
{
struct V_199 V_165 ;
struct V_88 V_68 ;
T_1 V_266 = 0 , V_267 = 0 ;
int V_73 = 0 ;
if ( ! V_265 ) {
memcpy ( & V_22 -> V_74 -> V_268 , V_162 ,
sizeof( struct V_258 ) ) ;
return 0 ;
}
memset ( & V_22 -> V_74 -> V_268 , 0 , sizeof( V_22 -> V_74 -> V_268 ) ) ;
memset ( & V_165 , 0 , sizeof( V_165 ) ) ;
F_62 ( V_22 , & V_165 , V_162 ) ;
V_68 . V_95 = V_22 -> V_190 -> V_191 +
F_37 ( struct V_192 , V_198 ) ;
V_68 . V_165 = & V_165 ;
V_68 . V_96 = sizeof( struct V_199 ) ;
F_64 ( V_22 , V_87 , V_68 . V_95 , V_68 . V_165 , V_68 . V_96 ) ;
V_73 = F_65 ( V_22 , V_87 , V_269 ,
1 << V_270 , & V_266 , & V_267 ) ;
if ( V_73 )
F_66 ( V_22 , L_17 ) ;
return V_73 ;
}
int F_67 ( struct V_21 * V_22 ,
struct V_258 * V_162 )
{
struct V_161 * V_271 ;
int V_73 ;
if ( V_22 -> V_74 -> V_268 . V_259 . V_167 ) {
memcpy ( V_162 , & V_22 -> V_74 -> V_268 ,
sizeof( struct V_258 ) ) ;
return 0 ;
}
V_271 = F_48 ( sizeof( * V_271 ) , V_211 ) ;
if ( ! V_271 )
return - V_212 ;
memset ( V_271 , 0 , sizeof( * V_271 ) ) ;
V_73 = F_53 ( V_22 , V_271 , V_188 ) ;
if ( V_73 ) {
F_50 ( V_271 ) ;
return V_73 ;
}
V_22 -> V_74 -> V_268 . V_261 = 0 ;
V_22 -> V_74 -> V_268 . V_260 = V_172 ;
if ( V_271 -> V_75 . V_174 )
V_22 -> V_74 -> V_268 . V_260 |= V_173 ;
if ( V_271 -> V_75 . V_11 )
V_22 -> V_74 -> V_268 . V_260 |= V_61 ;
V_22 -> V_74 -> V_268 . V_135 = V_271 -> V_75 . V_135 ;
memcpy ( & V_22 -> V_74 -> V_268 . V_259 . V_162 ,
& V_271 -> V_75 . V_162 ,
sizeof( struct V_272 ) ) ;
V_22 -> V_74 -> V_268 . V_259 . V_167 = true ;
memcpy ( V_162 , & V_22 -> V_74 -> V_268 , sizeof( struct V_258 ) ) ;
F_50 ( V_271 ) ;
return 0 ;
}
static struct V_161 * F_68 ( struct V_21 * V_200 ,
enum V_89 type )
{
struct V_161 * V_271 ;
V_271 = F_69 ( sizeof( * V_271 ) , V_273 ) ;
if ( ! V_271 )
return NULL ;
memset ( V_271 , 0 , sizeof( * V_271 ) ) ;
if ( F_53 ( V_200 , V_271 , type ) ) {
F_50 ( V_271 ) ;
return NULL ;
}
if ( ( type == V_188 ) &&
! V_271 -> V_75 . V_135 ) {
F_70 ( V_200 , L_18 ) ;
F_50 ( V_271 ) ;
return NULL ;
}
return V_271 ;
}
static T_2 F_71 ( struct V_274 * V_204 )
{
struct V_21 * V_200 = F_72 ( V_204 ) ;
struct V_161 * V_271 ;
bool V_135 ;
V_271 = F_68 ( V_200 , V_188 ) ;
if ( ! V_271 )
return 0 ;
V_135 = V_271 -> V_75 . V_135 ;
F_12 ( V_200 , V_28 , L_19 , V_135 ) ;
F_50 ( V_271 ) ;
return V_135 ;
}
static T_2 F_73 ( struct V_274 * V_204 , T_2 V_275 )
{
struct V_21 * V_200 = F_72 ( V_204 ) ;
struct V_258 V_276 ;
struct V_86 * V_277 ;
int V_73 ;
F_12 ( V_200 , V_28 , L_19 , V_275 ) ;
memset ( & V_276 , 0 , sizeof( V_276 ) ) ;
V_73 = F_67 ( V_200 , & V_276 ) ;
if ( V_73 )
return 1 ;
V_276 . V_135 = ! ! V_275 ;
V_277 = F_55 ( V_200 ) ;
if ( ! V_277 )
return 1 ;
V_73 = F_63 ( V_200 , V_277 , & V_276 , 0 ) ;
F_56 ( V_200 , V_277 ) ;
return V_73 ? 1 : 0 ;
}
static void F_74 ( struct V_274 * V_204 , int V_36 , T_2 * V_278 ,
T_2 * V_279 , T_2 * V_280 , T_2 * V_281 )
{
struct V_21 * V_200 = F_72 ( V_204 ) ;
struct V_161 * V_271 ;
F_12 ( V_200 , V_28 , L_20 , V_36 ) ;
* V_278 = * V_279 = * V_280 = * V_281 = 0 ;
if ( V_36 < 0 || V_36 >= V_155 ) {
F_70 ( V_200 , L_21 , V_36 ) ;
return;
}
V_271 = F_68 ( V_200 , V_188 ) ;
if ( ! V_271 )
return;
* V_279 = V_271 -> V_75 . V_162 . V_160 [ V_36 ] ;
F_50 ( V_271 ) ;
}
static void F_75 ( struct V_274 * V_204 , int V_279 , T_2 * V_280 )
{
struct V_21 * V_200 = F_72 ( V_204 ) ;
struct V_161 * V_271 ;
* V_280 = 0 ;
F_12 ( V_200 , V_28 , L_22 , V_279 ) ;
if ( V_279 < 0 || V_279 >= V_155 ) {
F_70 ( V_200 , L_23 , V_279 ) ;
return;
}
V_271 = F_68 ( V_200 , V_188 ) ;
if ( ! V_271 )
return;
* V_280 = V_271 -> V_75 . V_162 . V_158 [ V_279 ] ;
F_12 ( V_200 , V_28 , L_24 , * V_280 ) ;
F_50 ( V_271 ) ;
}
static void F_76 ( struct V_274 * V_204 , int V_36 , T_2 * V_41 ,
T_2 * V_282 , T_2 * V_280 , T_2 * V_281 )
{
F_70 ( F_72 ( V_204 ) , L_25 ) ;
* V_41 = * V_282 = * V_280 = * V_281 = 0 ;
}
static void F_77 ( struct V_274 * V_204 ,
int V_282 , T_2 * V_280 )
{
F_70 ( F_72 ( V_204 ) , L_25 ) ;
* V_280 = 0 ;
}
static void F_78 ( struct V_274 * V_204 ,
int V_35 , T_2 * V_283 )
{
struct V_21 * V_200 = F_72 ( V_204 ) ;
struct V_161 * V_271 ;
F_12 ( V_200 , V_28 , L_26 , V_35 ) ;
if ( V_35 < 0 || V_35 >= V_155 ) {
F_70 ( V_200 , L_27 , V_35 ) ;
return;
}
V_271 = F_68 ( V_200 , V_188 ) ;
if ( ! V_271 )
return;
* V_283 = V_271 -> V_75 . V_162 . V_129 . V_41 [ V_35 ] ;
F_12 ( V_200 , V_28 , L_28 , * V_283 ) ;
F_50 ( V_271 ) ;
}
static void F_79 ( struct V_274 * V_204 , int V_35 , T_2 V_283 )
{
struct V_21 * V_200 = F_72 ( V_204 ) ;
struct V_258 V_276 ;
struct V_86 * V_277 ;
int V_73 ;
F_12 ( V_200 , V_28 , L_29 ,
V_35 , V_283 ) ;
if ( V_35 < 0 || V_35 >= V_155 ) {
F_70 ( V_200 , L_27 , V_35 ) ;
return;
}
memset ( & V_276 , 0 , sizeof( V_276 ) ) ;
V_73 = F_67 ( V_200 , & V_276 ) ;
if ( V_73 )
return;
V_276 . V_261 |= V_262 ;
V_276 . V_259 . V_162 . V_129 . V_41 [ V_35 ] = ! ! V_283 ;
V_277 = F_55 ( V_200 ) ;
if ( ! V_277 )
return;
V_73 = F_63 ( V_200 , V_277 , & V_276 , 0 ) ;
F_56 ( V_200 , V_277 ) ;
}
static T_2 F_80 ( struct V_274 * V_204 , int V_284 , T_2 * V_285 )
{
struct V_21 * V_200 = F_72 ( V_204 ) ;
struct V_161 * V_271 ;
int V_73 = 0 ;
F_12 ( V_200 , V_28 , L_30 , V_284 ) ;
V_271 = F_68 ( V_200 , V_188 ) ;
if ( ! V_271 )
return 1 ;
switch ( V_284 ) {
case V_286 :
case V_287 :
case V_288 :
case V_289 :
* V_285 = true ;
break;
case V_290 :
case V_291 :
* V_285 = 0x80 ;
break;
case V_292 :
* V_285 = ( V_293 | V_294 |
V_295 ) ;
break;
default:
* V_285 = false ;
V_73 = 1 ;
}
F_12 ( V_200 , V_28 , L_31 , V_284 , * V_285 ) ;
F_50 ( V_271 ) ;
return V_73 ;
}
static int F_81 ( struct V_274 * V_204 , int V_296 , T_2 * V_297 )
{
struct V_21 * V_200 = F_72 ( V_204 ) ;
struct V_161 * V_271 ;
int V_73 = 0 ;
F_12 ( V_200 , V_28 , L_32 , V_296 ) ;
V_271 = F_68 ( V_200 , V_188 ) ;
if ( ! V_271 )
return - V_65 ;
switch ( V_296 ) {
case V_298 :
* V_297 = V_271 -> V_75 . V_162 . V_154 ;
break;
case V_299 :
* V_297 = V_271 -> V_75 . V_162 . V_129 . V_133 ;
break;
default:
V_73 = - V_65 ;
}
F_50 ( V_271 ) ;
F_12 ( V_200 , V_28 , L_33 , * V_297 ) ;
return V_73 ;
}
static T_2 F_82 ( struct V_274 * V_204 )
{
struct V_21 * V_200 = F_72 ( V_204 ) ;
struct V_161 * V_271 ;
bool V_135 ;
V_271 = F_68 ( V_200 , V_188 ) ;
if ( ! V_271 )
return 0 ;
V_135 = V_271 -> V_75 . V_162 . V_129 . V_135 ;
F_12 ( V_200 , V_28 , L_34 , V_135 ) ;
F_50 ( V_271 ) ;
return V_135 ;
}
static T_2 F_83 ( struct V_274 * V_204 )
{
struct V_21 * V_200 = F_72 ( V_204 ) ;
struct V_161 * V_271 ;
T_2 V_300 = 0 ;
V_271 = F_68 ( V_200 , V_188 ) ;
if ( ! V_271 )
return 0 ;
if ( V_271 -> V_75 . V_135 )
V_300 |= V_293 ;
if ( V_271 -> V_75 . V_11 )
V_300 |= V_295 ;
if ( V_271 -> V_75 . V_174 )
V_300 |= V_294 ;
F_12 ( V_200 , V_28 , L_35 , V_300 ) ;
F_50 ( V_271 ) ;
return V_300 ;
}
static void F_84 ( struct V_274 * V_204 ,
int V_36 ,
T_2 V_301 , T_2 V_279 , T_2 V_280 , T_2 V_281 )
{
struct V_21 * V_200 = F_72 ( V_204 ) ;
struct V_258 V_276 ;
struct V_86 * V_277 ;
int V_73 ;
F_12 ( V_200 , V_28 ,
L_36 ,
V_36 , V_301 , V_279 , V_280 , V_281 ) ;
if ( V_36 < 0 || V_36 >= V_155 ) {
F_70 ( V_200 , L_21 , V_36 ) ;
return;
}
memset ( & V_276 , 0 , sizeof( V_276 ) ) ;
V_73 = F_67 ( V_200 , & V_276 ) ;
if ( V_73 )
return;
V_276 . V_261 |= V_263 ;
V_276 . V_259 . V_162 . V_160 [ V_36 ] = V_279 ;
V_277 = F_55 ( V_200 ) ;
if ( ! V_277 )
return;
V_73 = F_63 ( V_200 , V_277 , & V_276 , 0 ) ;
F_56 ( V_200 , V_277 ) ;
}
static void F_85 ( struct V_274 * V_204 , int V_41 ,
T_2 V_301 , T_2 V_279 , T_2 V_280 , T_2 V_281 )
{
F_70 ( F_72 ( V_204 ) , L_25 ) ;
}
static void F_86 ( struct V_274 * V_204 , int V_279 , T_2 V_280 )
{
struct V_21 * V_200 = F_72 ( V_204 ) ;
struct V_258 V_276 ;
struct V_86 * V_277 ;
int V_73 ;
F_12 ( V_200 , V_28 , L_37 , V_279 , V_280 ) ;
if ( V_279 < 0 || V_279 >= V_155 ) {
F_70 ( V_200 , L_23 , V_279 ) ;
return;
}
memset ( & V_276 , 0 , sizeof( V_276 ) ) ;
V_73 = F_67 ( V_200 , & V_276 ) ;
if ( V_73 )
return;
V_276 . V_261 |= V_263 ;
V_276 . V_259 . V_162 . V_158 [ V_279 ] = V_280 ;
V_277 = F_55 ( V_200 ) ;
if ( ! V_277 )
return;
V_73 = F_63 ( V_200 , V_277 , & V_276 , 0 ) ;
F_56 ( V_200 , V_277 ) ;
}
static void F_87 ( struct V_274 * V_204 , int V_279 , T_2 V_280 )
{
F_70 ( F_72 ( V_204 ) , L_25 ) ;
}
static T_2 F_88 ( struct V_274 * V_204 )
{
struct V_21 * V_200 = F_72 ( V_204 ) ;
struct V_258 V_276 ;
struct V_86 * V_277 ;
int V_73 ;
memset ( & V_276 , 0 , sizeof( V_276 ) ) ;
V_73 = F_67 ( V_200 , & V_276 ) ;
if ( V_73 )
return 1 ;
V_277 = F_55 ( V_200 ) ;
if ( ! V_277 )
return 1 ;
V_73 = F_63 ( V_200 , V_277 , & V_276 , 1 ) ;
F_56 ( V_200 , V_277 ) ;
return V_73 ;
}
static int F_89 ( struct V_274 * V_204 , int V_296 , T_2 V_297 )
{
struct V_21 * V_200 = F_72 ( V_204 ) ;
struct V_258 V_276 ;
struct V_86 * V_277 ;
int V_73 ;
F_12 ( V_200 , V_28 , L_38 , V_296 , V_297 ) ;
memset ( & V_276 , 0 , sizeof( V_276 ) ) ;
V_73 = F_67 ( V_200 , & V_276 ) ;
if ( V_73 )
return 1 ;
switch ( V_296 ) {
case V_298 :
V_276 . V_261 |= V_263 ;
V_276 . V_259 . V_162 . V_154 = V_297 ;
break;
case V_299 :
V_276 . V_261 |= V_262 ;
V_276 . V_259 . V_162 . V_129 . V_133 = V_297 ;
break;
default:
F_70 ( V_200 , L_39 , V_296 ) ;
return - V_65 ;
}
V_277 = F_55 ( V_200 ) ;
if ( ! V_277 )
return - V_65 ;
V_73 = F_63 ( V_200 , V_277 , & V_276 , 0 ) ;
F_56 ( V_200 , V_277 ) ;
return 0 ;
}
static void F_90 ( struct V_274 * V_204 , T_2 V_275 )
{
struct V_21 * V_200 = F_72 ( V_204 ) ;
struct V_258 V_276 ;
struct V_86 * V_277 ;
int V_73 ;
F_12 ( V_200 , V_28 , L_40 , V_275 ) ;
memset ( & V_276 , 0 , sizeof( V_276 ) ) ;
V_73 = F_67 ( V_200 , & V_276 ) ;
if ( V_73 )
return;
V_276 . V_261 |= V_262 ;
V_276 . V_259 . V_162 . V_129 . V_135 = ! ! V_275 ;
V_277 = F_55 ( V_200 ) ;
if ( ! V_277 )
return;
V_73 = F_63 ( V_200 , V_277 , & V_276 , 0 ) ;
F_56 ( V_200 , V_277 ) ;
}
static int F_91 ( struct V_274 * V_204 , T_2 V_302 , T_3 V_303 )
{
struct V_21 * V_200 = F_72 ( V_204 ) ;
struct V_161 * V_271 ;
struct V_112 * V_62 ;
bool V_12 ;
T_2 V_41 = 0 ;
int V_27 ;
V_271 = F_68 ( V_200 , V_188 ) ;
if ( ! V_271 )
return - V_65 ;
V_12 = ! ! ( V_302 == V_304 ) ;
for ( V_27 = 0 ; V_27 < V_305 ; V_27 ++ ) {
V_62 = & V_271 -> V_75 . V_162 . V_122 [ V_27 ] ;
if ( ( V_62 -> V_12 == V_12 ) && ( V_62 -> V_10 == V_303 ) ) {
V_41 = V_62 -> V_41 ;
break;
}
}
if ( V_27 == V_305 ) {
F_17 ( V_204 , L_41 , V_302 , V_303 ) ;
F_50 ( V_271 ) ;
return - V_65 ;
}
F_50 ( V_271 ) ;
return V_41 ;
}
static int F_92 ( struct V_274 * V_204 ,
T_2 V_302 , T_3 V_303 , T_2 V_113 )
{
struct V_21 * V_200 = F_72 ( V_204 ) ;
struct V_258 V_276 ;
struct V_112 * V_62 ;
struct V_86 * V_277 ;
bool V_12 ;
int V_73 , V_27 ;
memset ( & V_276 , 0 , sizeof( V_276 ) ) ;
V_73 = F_67 ( V_200 , & V_276 ) ;
if ( V_73 )
return - V_65 ;
V_12 = ! ! ( V_302 == V_304 ) ;
for ( V_27 = 0 ; V_27 < V_305 ; V_27 ++ ) {
V_62 = & V_276 . V_259 . V_162 . V_122 [ V_27 ] ;
if ( ( V_62 -> V_12 == V_12 ) && ( V_62 -> V_10 == V_303 ) )
break;
if ( ! V_62 -> V_10 ) {
V_276 . V_259 . V_162 . V_120 ++ ;
break;
}
}
if ( V_27 == V_305 ) {
F_17 ( V_204 , L_42 ) ;
return - V_232 ;
}
V_276 . V_261 |= V_264 ;
V_276 . V_259 . V_162 . V_122 [ V_27 ] . V_12 = V_12 ;
V_276 . V_259 . V_162 . V_122 [ V_27 ] . V_10 = V_303 ;
V_276 . V_259 . V_162 . V_122 [ V_27 ] . V_41 = V_113 ;
V_277 = F_55 ( V_200 ) ;
if ( ! V_277 )
return - V_232 ;
V_73 = F_63 ( V_200 , V_277 , & V_276 , 0 ) ;
F_56 ( V_200 , V_277 ) ;
return V_73 ;
}
static T_2 F_93 ( struct V_274 * V_204 , T_2 V_300 )
{
struct V_21 * V_200 = F_72 ( V_204 ) ;
struct V_258 V_276 ;
struct V_86 * V_277 ;
int V_73 ;
F_12 ( V_200 , V_28 , L_43 , V_300 ) ;
if ( ! ( V_300 & V_295 ) && ! ( V_300 & V_294 ) ) {
F_70 ( V_200 , L_44 ) ;
return 1 ;
}
memset ( & V_276 , 0 , sizeof( V_276 ) ) ;
V_73 = F_67 ( V_200 , & V_276 ) ;
if ( V_73 )
return 1 ;
V_276 . V_260 = 0 ;
if ( V_300 & V_294 ) {
V_276 . V_260 |= V_173 ;
V_276 . V_135 = true ;
}
if ( V_300 & V_295 ) {
V_276 . V_260 |= V_61 ;
V_276 . V_135 = true ;
}
V_277 = F_55 ( V_200 ) ;
if ( ! V_277 )
return 1 ;
V_73 = F_63 ( V_200 , V_277 , & V_276 , 0 ) ;
F_56 ( V_200 , V_277 ) ;
return 0 ;
}
static T_2 F_94 ( struct V_274 * V_204 , int V_306 , T_2 * V_71 )
{
struct V_21 * V_200 = F_72 ( V_204 ) ;
struct V_161 * V_271 ;
F_12 ( V_200 , V_28 , L_45 , V_306 ) ;
V_271 = F_68 ( V_200 , V_188 ) ;
if ( ! V_271 )
return 1 ;
* V_71 = 0 ;
switch ( V_306 ) {
case V_307 :
if ( V_271 -> V_75 . V_162 . V_150 )
* V_71 = V_308 ;
else
* V_71 = V_309 ;
break;
case V_310 :
if ( V_271 -> V_75 . V_162 . V_129 . V_135 )
* V_71 = V_308 ;
else
* V_71 = V_309 ;
break;
case V_311 :
if ( V_271 -> V_75 . V_162 . V_116 )
* V_71 = V_308 ;
else
* V_71 = V_309 ;
break;
default:
F_70 ( V_200 , L_46 , V_306 ) ;
F_50 ( V_271 ) ;
return 1 ;
}
F_12 ( V_200 , V_28 , L_47 , * V_71 ) ;
F_50 ( V_271 ) ;
return 0 ;
}
static T_2 F_95 ( struct V_274 * V_204 , int V_306 , T_2 V_71 )
{
struct V_21 * V_200 = F_72 ( V_204 ) ;
struct V_258 V_276 ;
bool V_135 , V_131 ;
struct V_86 * V_277 ;
int V_73 ;
F_12 ( V_200 , V_28 , L_48 ,
V_306 , V_71 ) ;
memset ( & V_276 , 0 , sizeof( V_276 ) ) ;
V_73 = F_67 ( V_200 , & V_276 ) ;
if ( V_73 )
return 1 ;
V_135 = ! ! ( V_71 & V_308 ) ;
V_131 = ! ! ( V_71 & V_312 ) ;
switch ( V_306 ) {
case V_307 :
V_276 . V_261 |= V_263 ;
V_276 . V_259 . V_162 . V_150 = V_135 ;
V_276 . V_259 . V_162 . V_148 = V_131 ;
break;
case V_310 :
V_276 . V_261 |= V_262 ;
V_276 . V_259 . V_162 . V_129 . V_135 = V_135 ;
V_276 . V_259 . V_162 . V_129 . V_131 = V_131 ;
break;
case V_311 :
V_276 . V_261 |= V_264 ;
V_276 . V_259 . V_162 . V_114 = V_131 ;
break;
default:
F_70 ( V_200 , L_46 , V_306 ) ;
return 1 ;
}
V_277 = F_55 ( V_200 ) ;
if ( ! V_277 )
return 1 ;
V_73 = F_63 ( V_200 , V_277 , & V_276 , 0 ) ;
F_56 ( V_200 , V_277 ) ;
return 0 ;
}
static int F_96 ( struct V_274 * V_204 ,
struct V_313 * V_314 ,
T_3 * V_315 )
{
struct V_21 * V_200 = F_72 ( V_204 ) ;
struct V_161 * V_271 ;
V_271 = F_68 ( V_200 , V_186 ) ;
if ( ! V_271 )
return - V_65 ;
V_314 -> V_131 = V_271 -> V_168 . V_162 . V_114 ;
V_314 -> error = V_271 -> V_168 . V_162 . V_118 ;
* V_315 = V_271 -> V_168 . V_162 . V_120 ;
F_50 ( V_271 ) ;
return 0 ;
}
static int F_97 ( struct V_274 * V_204 ,
struct V_316 * V_317 )
{
struct V_21 * V_200 = F_72 ( V_204 ) ;
struct V_161 * V_271 ;
int V_27 ;
V_271 = F_68 ( V_200 , V_186 ) ;
if ( ! V_271 )
return - V_65 ;
for ( V_27 = 0 ; V_27 < V_271 -> V_168 . V_162 . V_120 ; V_27 ++ ) {
if ( V_271 -> V_168 . V_162 . V_122 [ V_27 ] . V_12 )
V_317 [ V_27 ] . V_318 = V_304 ;
else
V_317 [ V_27 ] . V_318 = V_319 ;
V_317 [ V_27 ] . V_35 = V_271 -> V_168 . V_162 . V_122 [ V_27 ] . V_41 ;
V_317 [ V_27 ] . V_320 =
V_271 -> V_168 . V_162 . V_122 [ V_27 ] . V_10 ;
}
F_50 ( V_271 ) ;
return 0 ;
}
static int F_98 ( struct V_274 * V_204 , struct V_321 * V_129 )
{
struct V_21 * V_200 = F_72 ( V_204 ) ;
struct V_161 * V_271 ;
int V_27 ;
V_271 = F_68 ( V_200 , V_186 ) ;
if ( ! V_271 )
return - V_65 ;
for ( V_27 = 0 ; V_27 < V_155 ; V_27 ++ )
if ( V_271 -> V_168 . V_162 . V_129 . V_41 [ V_27 ] )
V_129 -> V_322 |= F_58 ( V_27 ) ;
V_129 -> V_323 = V_271 -> V_168 . V_162 . V_129 . V_133 ;
F_12 ( V_200 , V_28 , L_49 ,
V_129 -> V_322 , V_129 -> V_323 ) ;
F_50 ( V_271 ) ;
return 0 ;
}
static int F_99 ( struct V_274 * V_204 , struct V_324 * V_325 )
{
struct V_21 * V_200 = F_72 ( V_204 ) ;
struct V_161 * V_271 ;
int V_27 ;
V_271 = F_68 ( V_200 , V_186 ) ;
if ( ! V_271 )
return - V_65 ;
V_325 -> V_131 = V_271 -> V_168 . V_162 . V_148 ;
for ( V_27 = 0 ; V_27 < V_155 ; V_27 ++ ) {
V_325 -> V_326 [ V_27 ] = V_271 -> V_168 . V_162 . V_158 [ V_27 ] ;
V_325 -> V_327 [ V_27 ] = V_271 -> V_168 . V_162 . V_160 [ V_27 ] ;
}
F_12 ( V_200 , V_28 , L_50 , V_325 -> V_131 ) ;
F_50 ( V_271 ) ;
return 0 ;
}
static int F_100 ( struct V_274 * V_204 ,
struct V_328 * V_129 , bool V_168 )
{
struct V_21 * V_200 = F_72 ( V_204 ) ;
struct V_110 * V_162 ;
struct V_161 * V_271 ;
int V_73 , V_27 ;
V_271 = F_68 ( V_200 , V_188 ) ;
if ( ! V_271 )
return - V_65 ;
if ( ! V_271 -> V_75 . V_11 ) {
F_70 ( V_200 , L_51 ) ;
F_50 ( V_271 ) ;
return - V_65 ;
}
if ( V_168 ) {
memset ( V_271 , 0 , sizeof( * V_271 ) ) ;
V_73 = F_53 ( V_200 , V_271 ,
V_186 ) ;
if ( V_73 ) {
F_50 ( V_271 ) ;
return - V_65 ;
}
V_162 = & V_271 -> V_168 . V_162 ;
} else {
V_162 = & V_271 -> V_75 . V_162 ;
}
V_129 -> V_329 = V_162 -> V_129 . V_133 ;
V_129 -> V_322 = 0 ;
for ( V_27 = 0 ; V_27 < V_155 ; V_27 ++ )
if ( V_162 -> V_129 . V_41 [ V_27 ] )
V_129 -> V_322 |= F_58 ( V_27 ) ;
F_50 ( V_271 ) ;
return 0 ;
}
static int F_101 ( struct V_274 * V_204 , struct V_328 * V_129 )
{
return F_100 ( V_204 , V_129 , false ) ;
}
static int F_102 ( struct V_274 * V_204 , struct V_328 * V_129 )
{
struct V_21 * V_200 = F_72 ( V_204 ) ;
struct V_161 * V_271 ;
struct V_258 V_276 ;
struct V_86 * V_277 ;
int V_73 , V_27 ;
V_271 = F_68 ( V_200 , V_188 ) ;
if ( ! V_271 )
return - V_65 ;
if ( ! V_271 -> V_75 . V_11 ) {
F_70 ( V_200 , L_51 ) ;
F_50 ( V_271 ) ;
return - V_65 ;
}
F_50 ( V_271 ) ;
memset ( & V_276 , 0 , sizeof( V_276 ) ) ;
V_73 = F_67 ( V_200 , & V_276 ) ;
if ( V_73 )
return - V_65 ;
V_276 . V_261 |= V_262 ;
for ( V_27 = 0 ; V_27 < V_155 ; V_27 ++ )
V_276 . V_259 . V_162 . V_129 . V_41 [ V_27 ] = ! ! ( V_129 -> V_322 & F_58 ( V_27 ) ) ;
V_276 . V_259 . V_162 . V_129 . V_133 = V_129 -> V_329 ;
V_277 = F_55 ( V_200 ) ;
if ( ! V_277 )
return - V_65 ;
V_73 = F_63 ( V_200 , V_277 , & V_276 , 0 ) ;
F_56 ( V_200 , V_277 ) ;
return V_73 ;
}
static int F_103 ( struct V_274 * V_204 ,
struct V_330 * V_80 , bool V_168 )
{
struct V_21 * V_200 = F_72 ( V_204 ) ;
struct V_161 * V_271 ;
struct V_110 * V_162 ;
int V_73 ;
V_271 = F_68 ( V_200 , V_188 ) ;
if ( ! V_271 )
return - V_65 ;
if ( ! V_271 -> V_75 . V_11 ) {
F_70 ( V_200 , L_51 ) ;
F_50 ( V_271 ) ;
return - V_65 ;
}
if ( V_168 ) {
memset ( V_271 , 0 , sizeof( * V_271 ) ) ;
V_73 = F_53 ( V_200 , V_271 ,
V_186 ) ;
if ( V_73 ) {
F_50 ( V_271 ) ;
return - V_65 ;
}
V_162 = & V_271 -> V_168 . V_162 ;
} else {
V_162 = & V_271 -> V_75 . V_162 ;
}
V_80 -> V_331 = V_162 -> V_154 ;
V_80 -> V_131 = V_162 -> V_148 ;
V_80 -> V_332 = V_162 -> V_152 ;
memcpy ( V_80 -> V_333 , V_162 -> V_158 , sizeof( V_80 -> V_333 ) ) ;
memcpy ( V_80 -> V_334 , V_162 -> V_159 , sizeof( V_80 -> V_334 ) ) ;
memcpy ( V_80 -> V_335 , V_162 -> V_160 , sizeof( V_80 -> V_335 ) ) ;
F_50 ( V_271 ) ;
return 0 ;
}
static int F_104 ( struct V_274 * V_204 , struct V_330 * V_80 )
{
return F_103 ( V_204 , V_80 , false ) ;
}
static int F_105 ( struct V_274 * V_204 , struct V_330 * V_80 )
{
struct V_21 * V_200 = F_72 ( V_204 ) ;
struct V_161 * V_271 ;
struct V_258 V_276 ;
struct V_86 * V_277 ;
int V_73 ;
V_271 = F_68 ( V_200 , V_188 ) ;
if ( ! V_271 )
return - V_65 ;
if ( ! V_271 -> V_75 . V_11 ) {
F_70 ( V_200 , L_51 ) ;
F_50 ( V_271 ) ;
return - V_65 ;
}
F_50 ( V_271 ) ;
memset ( & V_276 , 0 , sizeof( V_276 ) ) ;
V_73 = F_67 ( V_200 , & V_276 ) ;
if ( V_73 )
return - V_65 ;
V_276 . V_261 |= V_263 ;
V_276 . V_259 . V_162 . V_154 = V_80 -> V_331 ;
V_276 . V_259 . V_162 . V_148 = V_80 -> V_131 ;
V_276 . V_259 . V_162 . V_152 = V_80 -> V_332 ;
memcpy ( V_276 . V_259 . V_162 . V_158 , V_80 -> V_333 ,
sizeof( V_80 -> V_333 ) ) ;
memcpy ( V_276 . V_259 . V_162 . V_159 , V_80 -> V_334 ,
sizeof( V_80 -> V_334 ) ) ;
memcpy ( V_276 . V_259 . V_162 . V_160 , V_80 -> V_335 ,
sizeof( V_80 -> V_335 ) ) ;
V_277 = F_55 ( V_200 ) ;
if ( ! V_277 )
return - V_65 ;
V_73 = F_63 ( V_200 , V_277 , & V_276 , 0 ) ;
F_56 ( V_200 , V_277 ) ;
return V_73 ;
}
static int
F_106 ( struct V_274 * V_204 , struct V_330 * V_80 )
{
return F_103 ( V_204 , V_80 , true ) ;
}
static int
F_107 ( struct V_274 * V_204 , struct V_328 * V_129 )
{
return F_100 ( V_204 , V_129 , true ) ;
}
static int F_108 ( struct V_274 * V_204 , struct V_316 * V_78 )
{
struct V_21 * V_200 = F_72 ( V_204 ) ;
struct V_161 * V_271 ;
struct V_112 * V_62 ;
bool V_12 ;
T_2 V_41 = 0 ;
int V_27 ;
V_271 = F_68 ( V_200 , V_188 ) ;
if ( ! V_271 )
return - V_65 ;
if ( ! V_271 -> V_75 . V_11 ) {
F_70 ( V_200 , L_51 ) ;
F_50 ( V_271 ) ;
return - V_65 ;
}
V_12 = ! ! ( ( V_78 -> V_318 - 1 ) == V_304 ) ;
for ( V_27 = 0 ; V_27 < V_305 ; V_27 ++ ) {
V_62 = & V_271 -> V_75 . V_162 . V_122 [ V_27 ] ;
if ( ( V_62 -> V_12 == V_12 ) &&
( V_62 -> V_10 == V_78 -> V_320 ) ) {
V_41 = V_62 -> V_41 ;
break;
}
}
if ( V_27 == V_305 ) {
F_17 ( V_204 , L_41 , V_78 -> V_318 ,
V_78 -> V_320 ) ;
F_50 ( V_271 ) ;
return - V_65 ;
}
V_78 -> V_35 = F_19 ( V_41 ) - 1 ;
F_50 ( V_271 ) ;
return 0 ;
}
static int F_109 ( struct V_274 * V_204 , struct V_316 * V_78 )
{
struct V_21 * V_200 = F_72 ( V_204 ) ;
struct V_161 * V_271 ;
struct V_258 V_276 ;
struct V_112 * V_62 ;
struct V_86 * V_277 ;
bool V_12 ;
int V_73 , V_27 ;
if ( V_78 -> V_35 < 0 || V_78 -> V_35 >= V_155 ) {
F_70 ( V_200 , L_27 , V_78 -> V_35 ) ;
return - V_65 ;
}
V_271 = F_68 ( V_200 , V_188 ) ;
if ( ! V_271 )
return - V_65 ;
if ( ! V_271 -> V_75 . V_11 ) {
F_70 ( V_200 , L_51 ) ;
F_50 ( V_271 ) ;
return - V_65 ;
}
F_50 ( V_271 ) ;
memset ( & V_276 , 0 , sizeof( V_276 ) ) ;
V_73 = F_67 ( V_200 , & V_276 ) ;
if ( V_73 )
return - V_65 ;
V_12 = ! ! ( ( V_78 -> V_318 - 1 ) == V_304 ) ;
for ( V_27 = 0 ; V_27 < V_305 ; V_27 ++ ) {
V_62 = & V_276 . V_259 . V_162 . V_122 [ V_27 ] ;
if ( ( V_62 -> V_12 == V_12 ) &&
( V_62 -> V_10 == V_78 -> V_320 ) )
break;
if ( ! V_62 -> V_10 ) {
V_276 . V_259 . V_162 . V_120 ++ ;
break;
}
}
if ( V_27 == V_305 ) {
F_17 ( V_204 , L_42 ) ;
return - V_232 ;
}
V_276 . V_261 |= V_264 ;
V_276 . V_259 . V_162 . V_122 [ V_27 ] . V_12 = V_12 ;
V_276 . V_259 . V_162 . V_122 [ V_27 ] . V_10 = V_78 -> V_320 ;
V_276 . V_259 . V_162 . V_122 [ V_27 ] . V_41 = F_58 ( V_78 -> V_35 ) ;
V_277 = F_55 ( V_200 ) ;
if ( ! V_277 )
return - V_232 ;
V_73 = F_63 ( V_200 , V_277 , & V_276 , 0 ) ;
F_56 ( V_200 , V_277 ) ;
return V_73 ;
}
