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
if ( V_40 -> V_43 == V_43 )
V_40 -> V_44 = V_36 ;
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
T_1 V_45 ,
T_3 V_26 , enum V_25 * type , bool V_11 )
{
if ( F_8 ( V_45 , V_26 , V_11 ) ) {
* type = V_46 ;
} else if ( F_9 ( V_45 , V_26 , V_11 ) ) {
* type = V_47 ;
} else if ( F_7 ( V_45 , V_26 , V_11 ) ) {
* type = V_48 ;
} else if ( F_6 ( V_45 , V_26 , V_11 ) ) {
* type = V_49 ;
} else if ( F_10 ( V_45 , V_26 , V_11 ) ) {
* type = V_50 ;
} else {
* type = V_51 ;
F_17 ( V_22 ,
L_3 ,
V_26 , V_45 ) ;
return false ;
}
return true ;
}
static int
F_18 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
struct V_52 * V_53 ,
T_1 V_54 , int V_55 , T_2 V_56 )
{
enum V_25 type ;
T_2 V_36 , V_57 ;
bool V_34 , V_11 ;
T_3 V_58 ;
int V_35 ;
int V_27 ;
F_12 ( V_22 , V_28 , L_4 , V_55 ) ;
V_11 = ( V_56 == V_59 ) ;
for ( V_27 = 0 ; V_27 < V_55 ; V_27 ++ ) {
V_58 = F_2 ( V_53 [ V_27 ] . V_60 ,
V_61 ) ;
V_57 = F_2 ( V_53 [ V_27 ] . V_60 ,
V_62 ) ;
V_35 = F_19 ( V_57 ) - 1 ;
if ( V_35 < 0 ) {
F_17 ( V_22 , L_5 ) ;
return - V_63 ;
}
V_36 = F_20 ( V_54 , V_35 ) ;
if ( F_16 ( V_22 , V_53 [ V_27 ] . V_60 ,
V_58 , & type , V_11 ) ) {
V_34 = ! ( type == V_49 ) ;
F_15 ( V_24 , V_22 , V_34 , true ,
V_35 , V_36 , type ) ;
}
}
if ( ! V_24 -> V_32 [ V_50 ] . V_33 &&
V_24 -> V_32 [ V_47 ] . V_33 ) {
V_36 = V_24 -> V_32 [ V_47 ] . V_36 ;
V_35 = V_24 -> V_32 [ V_47 ] . V_35 ;
F_15 ( V_24 , V_22 , true , true ,
V_35 , V_36 , V_50 ) ;
}
V_36 = V_24 -> V_32 [ V_49 ] . V_36 ;
V_35 = V_24 -> V_32 [ V_49 ] . V_35 ;
for ( type = 0 ; type < V_51 ; type ++ ) {
if ( V_24 -> V_32 [ type ] . V_33 )
continue;
V_34 = ! ( type == V_49 ) ;
F_15 ( V_24 , V_22 , V_34 , true ,
V_35 , V_36 , type ) ;
}
return 0 ;
}
static int F_21 ( struct V_21 * V_22 )
{
struct V_64 * V_65 ;
struct V_52 * V_53 ;
struct V_23 V_66 = { 0 } ;
struct V_67 * V_68 ;
struct V_39 * V_40 ;
T_1 V_54 , V_69 ;
T_2 V_56 ;
int V_70 ;
int V_71 = 0 ;
V_69 = V_22 -> V_72 -> V_73 . V_69 ;
V_56 = F_2 ( V_69 , V_74 ) ;
V_65 = & V_22 -> V_72 -> V_73 . V_75 . V_76 ;
V_53 = V_65 -> V_77 ;
V_68 = & V_22 -> V_72 -> V_73 . V_75 . V_78 ;
V_54 = V_68 -> V_54 [ 0 ] ;
V_40 = & V_22 -> V_37 ;
V_70 = F_2 ( V_65 -> V_69 , V_79 ) ;
V_71 = F_18 ( V_22 , & V_66 , V_53 , V_54 ,
V_70 , V_56 ) ;
if ( V_71 )
return V_71 ;
V_40 -> V_38 = F_2 ( V_68 -> V_69 ,
V_80 ) ;
V_22 -> V_81 . V_82 = F_2 ( V_68 -> V_69 , V_83 ) ;
V_66 . V_84 = V_22 -> V_85 ;
V_66 . V_29 = ! ! V_56 ;
F_11 ( V_22 , & V_66 ) ;
memcpy ( & V_22 -> V_72 -> V_86 , & V_66 ,
sizeof( struct V_23 ) ) ;
return 0 ;
}
static int
F_22 ( struct V_21 * V_22 ,
struct V_87 * V_88 ,
struct V_89 * V_24 ,
enum V_90 type )
{
T_1 V_91 , V_92 ;
int V_93 = 0 ;
int V_71 = 0 ;
do {
if ( type == V_94 ) {
F_23 ( V_22 , V_88 , V_24 -> V_95 ,
V_24 -> V_96 , V_24 -> V_97 ) ;
V_91 = V_24 -> V_95 -> V_91 ;
V_92 = V_24 -> V_95 -> V_92 ;
} else {
F_23 ( V_22 , V_88 , V_24 -> V_98 ,
V_24 -> V_96 , V_24 -> V_97 ) ;
V_91 = V_24 -> V_98 -> V_91 ;
V_92 = V_24 -> V_98 -> V_92 ;
}
V_93 ++ ;
F_12 ( V_22 ,
V_28 ,
L_6 ,
type , V_93 , V_91 , V_92 ) ;
} while ( ( V_91 != V_92 ) &&
( V_93 < V_99 ) );
if ( V_93 >= V_99 ) {
F_17 ( V_22 ,
L_7 ,
type , V_93 , V_91 , V_92 ) ;
V_71 = - V_100 ;
}
return V_71 ;
}
static void
F_24 ( struct V_21 * V_22 ,
struct V_101 * V_102 ,
struct V_23 * V_103 )
{
T_2 V_104 ;
V_102 -> V_105 = V_106 ;
V_102 -> V_107 = V_106 ;
V_102 -> V_108 = V_106 ;
V_102 -> V_109 = V_106 ;
if ( V_103 -> V_32 [ V_47 ] . V_33 &&
V_103 -> V_32 [ V_47 ] . V_34 )
V_102 -> V_105 = V_103 -> V_32 [ V_47 ] . V_35 ;
if ( V_103 -> V_32 [ V_50 ] . V_33 &&
V_103 -> V_32 [ V_50 ] . V_34 ) {
V_104 = V_103 -> V_32 [ V_50 ] . V_35 ;
V_102 -> V_107 = V_104 ;
}
if ( V_103 -> V_32 [ V_48 ] . V_33 &&
V_103 -> V_32 [ V_48 ] . V_34 )
V_102 -> V_108 = V_103 -> V_32 [ V_48 ] . V_35 ;
if ( V_103 -> V_32 [ V_46 ] . V_33 &&
V_103 -> V_32 [ V_46 ] . V_34 )
V_102 -> V_109 = V_103 -> V_32 [ V_46 ] . V_35 ;
if ( V_103 -> V_32 [ V_49 ] . V_33 &&
V_103 -> V_32 [ V_49 ] . V_34 )
V_102 -> V_110 = V_103 -> V_32 [ V_49 ] . V_35 ;
F_12 ( V_22 , V_28 ,
L_8 ,
V_102 -> V_108 , V_102 -> V_105 , V_102 -> V_107 , V_102 -> V_109 ,
V_102 -> V_110 ) ;
}
static void
F_25 ( struct V_21 * V_22 ,
struct V_64 * V_65 ,
struct V_52 * V_53 ,
struct V_111 * V_112 , bool V_11 )
{
struct V_113 * V_60 ;
T_2 V_114 ;
int V_27 ;
V_112 -> V_115 = F_2 ( V_65 -> V_69 ,
V_116 ) ;
V_112 -> V_117 = F_2 ( V_65 -> V_69 , V_118 ) ;
V_112 -> V_119 = F_2 ( V_65 -> V_69 , V_120 ) ;
V_112 -> V_121 = F_2 ( V_65 -> V_69 ,
V_79 ) ;
for ( V_27 = 0 ; V_27 < V_122 ; V_27 ++ ) {
V_60 = & V_112 -> V_123 [ V_27 ] ;
if ( V_11 ) {
T_2 V_124 ;
T_1 V_104 ;
V_124 = F_2 ( V_53 [ V_27 ] . V_60 ,
V_5 ) ;
switch ( V_124 ) {
case V_6 :
V_104 = F_2 ( V_53 [ V_27 ] . V_60 ,
V_2 ) ;
V_60 -> V_124 = V_104 ?
V_125 :
V_126 ;
break;
case V_7 :
V_60 -> V_124 = V_126 ;
break;
case V_15 :
V_60 -> V_124 = V_127 ;
break;
case V_19 :
V_60 -> V_124 = V_128 ;
break;
case V_9 :
V_60 -> V_124 = V_125 ;
break;
}
} else {
V_60 -> V_12 = ! ( F_2 ( V_53 [ V_27 ] . V_60 ,
V_2 ) ) ;
}
V_114 = F_2 ( V_53 [ V_27 ] . V_60 , V_62 ) ;
V_60 -> V_41 = F_19 ( V_114 ) - 1 ;
V_60 -> V_10 = F_2 ( V_53 [ V_27 ] . V_60 ,
V_61 ) ;
F_16 ( V_22 , V_53 [ V_27 ] . V_60 ,
V_60 -> V_10 ,
& V_60 -> V_129 , V_11 ) ;
}
F_12 ( V_22 , V_28 ,
L_9 ,
V_112 -> V_115 , V_112 -> V_117 ,
V_112 -> V_119 ) ;
}
static void
F_26 ( struct V_21 * V_22 ,
T_1 V_130 , struct V_111 * V_112 )
{
T_2 V_131 ;
V_112 -> V_130 . V_132 = F_2 ( V_130 , V_133 ) ;
V_112 -> V_130 . V_134 = F_2 ( V_130 , V_135 ) ;
V_112 -> V_130 . V_136 = F_2 ( V_130 , V_137 ) ;
V_131 = F_2 ( V_130 , V_138 ) ;
V_112 -> V_130 . V_41 [ 0 ] = ! ! ( V_131 & V_139 ) ;
V_112 -> V_130 . V_41 [ 1 ] = ! ! ( V_131 & V_140 ) ;
V_112 -> V_130 . V_41 [ 2 ] = ! ! ( V_131 & V_141 ) ;
V_112 -> V_130 . V_41 [ 3 ] = ! ! ( V_131 & V_142 ) ;
V_112 -> V_130 . V_41 [ 4 ] = ! ! ( V_131 & V_143 ) ;
V_112 -> V_130 . V_41 [ 5 ] = ! ! ( V_131 & V_144 ) ;
V_112 -> V_130 . V_41 [ 6 ] = ! ! ( V_131 & V_145 ) ;
V_112 -> V_130 . V_41 [ 7 ] = ! ! ( V_131 & V_146 ) ;
F_12 ( V_22 , V_28 ,
L_10 ,
V_112 -> V_130 . V_132 , V_131 , V_112 -> V_130 . V_134 ,
V_112 -> V_130 . V_136 ) ;
}
static void
F_27 ( struct V_21 * V_22 ,
struct V_67 * V_68 ,
struct V_111 * V_112 )
{
T_1 V_147 [ 2 ] , V_148 [ 2 ] , V_114 ;
int V_27 ;
V_112 -> V_149 = F_2 ( V_68 -> V_69 ,
V_150 ) ;
V_112 -> V_151 = F_2 ( V_68 -> V_69 ,
V_152 ) ;
V_112 -> V_153 = F_2 ( V_68 -> V_69 , V_154 ) ;
V_112 -> V_155 = F_2 ( V_68 -> V_69 ,
V_80 ) ;
F_12 ( V_22 , V_28 ,
L_11 ,
V_112 -> V_149 , V_112 -> V_151 ,
V_112 -> V_153 , V_68 -> V_54 [ 0 ] ,
V_112 -> V_155 ) ;
if ( V_112 -> V_151 && ! V_112 -> V_155 ) {
V_112 -> V_155 = V_156 ;
F_12 ( V_22 , V_28 ,
L_12 ,
V_112 -> V_155 ) ;
}
V_147 [ 0 ] = F_28 ( V_68 -> V_157 [ 0 ] ) ;
V_147 [ 1 ] = F_28 ( V_68 -> V_157 [ 1 ] ) ;
V_148 [ 0 ] = F_28 ( V_68 -> V_158 [ 0 ] ) ;
V_148 [ 1 ] = F_28 ( V_68 -> V_158 [ 1 ] ) ;
V_114 = V_68 -> V_54 [ 0 ] ;
for ( V_27 = 0 ; V_27 < V_156 ; V_27 ++ ) {
V_112 -> V_159 [ V_27 ] = ( ( T_2 * ) V_147 ) [ V_27 ] ;
V_112 -> V_160 [ V_27 ] = ( ( T_2 * ) V_148 ) [ V_27 ] ;
V_112 -> V_161 [ V_27 ] = F_20 ( V_114 , V_27 ) ;
F_12 ( V_22 , V_28 ,
L_13 ,
V_27 , V_112 -> V_159 [ V_27 ] ,
V_112 -> V_160 [ V_27 ] ) ;
}
}
static void
F_29 ( struct V_21 * V_22 ,
struct V_64 * V_65 ,
struct V_52 * V_53 ,
struct V_67 * V_68 ,
T_1 V_130 , struct V_111 * V_112 , bool V_11 )
{
F_25 ( V_22 , V_65 , V_53 , V_112 , V_11 ) ;
F_27 ( V_22 , V_68 , V_112 ) ;
F_26 ( V_22 , V_130 , V_112 ) ;
}
static void
F_30 ( struct V_21 * V_22 , struct V_162 * V_163 )
{
struct V_164 * V_165 ;
V_165 = & V_22 -> V_72 -> V_166 . V_75 ;
F_29 ( V_22 , & V_165 -> V_76 ,
V_165 -> V_76 . V_77 , & V_165 -> V_78 ,
V_165 -> V_130 , & V_163 -> V_167 . V_163 , false ) ;
V_163 -> V_167 . V_168 = true ;
}
static void
F_31 ( struct V_21 * V_22 , struct V_162 * V_163 )
{
struct V_164 * V_165 ;
V_165 = & V_22 -> V_72 -> V_169 . V_75 ;
F_29 ( V_22 , & V_165 -> V_76 ,
V_165 -> V_76 . V_77 , & V_165 -> V_78 ,
V_165 -> V_130 , & V_163 -> V_169 . V_163 , false ) ;
V_163 -> V_169 . V_168 = true ;
}
static void
F_32 ( struct V_21 * V_22 ,
struct V_162 * V_163 )
{
struct V_170 * V_171 ;
struct V_23 * V_103 ;
struct V_164 * V_165 ;
bool V_136 , V_172 ;
T_1 V_69 ;
bool V_104 ;
V_69 = V_22 -> V_72 -> V_73 . V_69 ;
V_171 = & V_163 -> V_73 ;
V_136 = ! ! ( F_2 ( V_69 , V_74 ) !=
V_173 ) ;
if ( ! V_136 ) {
V_171 -> V_136 = V_136 ;
V_171 -> V_168 = false ;
F_12 ( V_22 , V_28 , L_14 ) ;
return;
}
V_165 = & V_22 -> V_72 -> V_73 . V_75 ;
V_103 = & V_22 -> V_72 -> V_86 ;
V_104 = ! ! ( F_2 ( V_69 , V_74 ) ==
V_59 ) ;
V_171 -> V_11 = V_104 ;
V_104 = ! ! ( F_2 ( V_69 , V_74 ) ==
V_174 ) ;
V_171 -> V_175 = V_104 ;
V_104 = ! ! ( F_2 ( V_69 , V_74 ) ==
V_176 ) ;
V_171 -> V_167 = V_104 ;
F_12 ( V_22 , V_28 ,
L_15 ,
V_171 -> V_11 , V_171 -> V_175 ,
V_171 -> V_167 ) ;
F_29 ( V_22 , & V_165 -> V_76 ,
V_165 -> V_76 . V_77 , & V_165 -> V_78 ,
V_165 -> V_130 , & V_163 -> V_73 . V_163 ,
V_171 -> V_11 ) ;
F_24 ( V_22 , & V_171 -> V_177 , V_103 ) ;
V_172 = F_2 ( V_165 -> V_76 . V_69 , V_120 ) ;
V_171 -> V_172 = V_172 ;
V_171 -> V_136 = V_136 ;
V_171 -> V_168 = true ;
}
static void
F_33 ( struct V_21 * V_22 ,
struct V_162 * V_163 )
{
struct V_178 * V_179 ;
V_179 = & V_22 -> V_72 -> V_180 [ V_181 ] ;
memcpy ( V_163 -> V_180 . V_182 , V_179 -> V_182 ,
F_13 ( V_179 -> V_182 ) ) ;
memcpy ( V_163 -> V_180 . V_183 , V_179 -> V_183 ,
F_13 ( V_179 -> V_183 ) ) ;
}
static void
F_34 ( struct V_21 * V_22 ,
struct V_162 * V_163 )
{
struct V_184 * V_185 ;
V_185 = & V_22 -> V_72 -> V_95 [ V_181 ] ;
memcpy ( V_163 -> V_95 . V_186 , V_185 -> V_186 ,
F_13 ( V_185 -> V_186 ) ) ;
memcpy ( V_163 -> V_95 . V_187 , V_185 -> V_187 ,
F_13 ( V_185 -> V_187 ) ) ;
}
static int
F_35 ( struct V_21 * V_22 , struct V_162 * V_112 ,
enum V_90 type )
{
switch ( type ) {
case V_188 :
F_31 ( V_22 , V_112 ) ;
break;
case V_189 :
F_30 ( V_22 , V_112 ) ;
break;
case V_190 :
F_32 ( V_22 , V_112 ) ;
break;
case V_94 :
F_34 ( V_22 , V_112 ) ;
break;
case V_191 :
F_33 ( V_22 , V_112 ) ;
break;
default:
F_17 ( V_22 , L_16 , type ) ;
return - V_63 ;
}
return 0 ;
}
static int
F_36 ( struct V_21 * V_22 , struct V_87 * V_88 )
{
struct V_89 V_66 ;
int V_71 = 0 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_66 . V_96 = V_22 -> V_192 -> V_193 + F_37 ( struct V_194 ,
V_195 ) ;
V_66 . V_180 = V_22 -> V_72 -> V_180 ;
V_66 . V_97 = sizeof( struct V_178 ) ;
F_23 ( V_22 , V_88 , V_66 . V_180 , V_66 . V_96 , V_66 . V_97 ) ;
return V_71 ;
}
static int
F_38 ( struct V_21 * V_22 ,
struct V_87 * V_88 ,
enum V_90 type )
{
struct V_89 V_66 ;
int V_71 = 0 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_66 . V_96 = V_22 -> V_192 -> V_193 + F_37 ( struct V_194 ,
V_196 ) ;
V_66 . V_95 = V_22 -> V_72 -> V_95 ;
V_66 . V_97 = sizeof( struct V_184 ) ;
V_71 = F_22 ( V_22 , V_88 , & V_66 , type ) ;
return V_71 ;
}
static int
F_39 ( struct V_21 * V_22 ,
struct V_87 * V_88 ,
enum V_90 type )
{
struct V_89 V_66 ;
int V_71 = 0 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_66 . V_96 = V_22 -> V_192 -> V_193 +
F_37 ( struct V_194 , V_197 ) ;
V_66 . V_98 = & V_22 -> V_72 -> V_73 ;
V_66 . V_97 = sizeof( struct V_198 ) ;
V_71 = F_22 ( V_22 , V_88 , & V_66 , type ) ;
return V_71 ;
}
static int
F_40 ( struct V_21 * V_22 ,
struct V_87 * V_88 , enum V_90 type )
{
struct V_89 V_66 ;
int V_71 = 0 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_66 . V_96 = V_22 -> V_192 -> V_193 +
F_37 ( struct V_194 , V_199 ) ;
V_66 . V_98 = & V_22 -> V_72 -> V_169 ;
V_66 . V_97 = sizeof( struct V_198 ) ;
V_71 = F_22 ( V_22 , V_88 , & V_66 , type ) ;
return V_71 ;
}
static int
F_41 ( struct V_21 * V_22 , struct V_87 * V_88 )
{
struct V_89 V_66 ;
int V_71 = 0 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_66 . V_96 = V_22 -> V_192 -> V_193 +
F_37 ( struct V_194 , V_200 ) ;
V_66 . V_166 = & V_22 -> V_72 -> V_166 ;
V_66 . V_97 = sizeof( struct V_201 ) ;
F_23 ( V_22 , V_88 , V_66 . V_166 , V_66 . V_96 , V_66 . V_97 ) ;
return V_71 ;
}
static int F_42 ( struct V_21 * V_22 ,
struct V_87 * V_88 , enum V_90 type )
{
int V_71 = - V_63 ;
switch ( type ) {
case V_190 :
V_71 = F_39 ( V_22 , V_88 , type ) ;
break;
case V_188 :
V_71 = F_40 ( V_22 , V_88 , type ) ;
break;
case V_189 :
V_71 = F_41 ( V_22 , V_88 ) ;
break;
case V_94 :
V_71 = F_38 ( V_22 , V_88 , type ) ;
break;
case V_191 :
V_71 = F_36 ( V_22 , V_88 ) ;
break;
default:
F_17 ( V_22 , L_16 , type ) ;
}
return V_71 ;
}
void F_43 ( struct V_21 * V_202 , T_1 V_203 )
{
struct V_204 * V_205 = V_202 -> V_206 -> V_207 . V_208 ;
void * V_209 = V_202 -> V_206 -> V_210 ;
if ( V_209 && V_205 -> V_211 )
V_205 -> V_211 ( V_209 , & V_202 -> V_72 -> V_212 , V_203 ) ;
}
int
F_44 ( struct V_21 * V_22 ,
struct V_87 * V_88 , enum V_90 type )
{
int V_71 = 0 ;
V_71 = F_42 ( V_22 , V_88 , type ) ;
if ( V_71 )
return V_71 ;
if ( type == V_190 ) {
V_71 = F_21 ( V_22 ) ;
if ( ! V_71 ) {
F_45 ( V_22 , V_88 ) ;
F_46 ( V_22 ) ;
}
}
F_35 ( V_22 , & V_22 -> V_72 -> V_212 , type ) ;
F_43 ( V_22 , type ) ;
return V_71 ;
}
int F_47 ( struct V_21 * V_22 )
{
V_22 -> V_72 = F_48 ( sizeof( * V_22 -> V_72 ) , V_213 ) ;
if ( ! V_22 -> V_72 )
return - V_214 ;
return 0 ;
}
void F_49 ( struct V_21 * V_22 )
{
F_50 ( V_22 -> V_72 ) ;
}
static void F_51 ( struct V_215 * V_24 ,
struct V_23 * V_216 ,
enum V_25 type )
{
V_24 -> V_217 = V_216 -> V_32 [ type ] . V_34 ;
V_24 -> V_218 = V_216 -> V_32 [ type ] . V_35 ;
V_24 -> V_219 = V_216 -> V_32 [ type ] . V_36 ;
}
void F_52 ( struct V_23 * V_216 ,
struct V_220 * V_221 )
{
struct V_215 * V_222 ;
bool V_223 = false ;
V_221 -> V_84 = V_216 -> V_84 ;
V_223 = V_216 -> V_32 [ V_46 ] . V_33 ;
V_221 -> V_224 = V_223 ;
V_223 = V_216 -> V_32 [ V_47 ] . V_33 ;
V_221 -> V_225 = V_223 ;
V_223 = V_216 -> V_32 [ V_50 ] . V_33 ;
V_221 -> V_225 = V_223 ;
V_223 = V_216 -> V_32 [ V_48 ] . V_33 ;
V_221 -> V_226 = V_223 ;
V_223 = V_216 -> V_32 [ V_49 ] . V_33 ;
V_221 -> V_227 = V_223 ;
V_222 = & V_221 -> V_228 ;
F_51 ( V_222 , V_216 , V_46 ) ;
V_222 = & V_221 -> V_229 ;
F_51 ( V_222 , V_216 , V_47 ) ;
V_222 = & V_221 -> V_230 ;
F_51 ( V_222 , V_216 , V_50 ) ;
V_222 = & V_221 -> V_231 ;
F_51 ( V_222 , V_216 , V_48 ) ;
V_222 = & V_221 -> V_232 ;
F_51 ( V_222 , V_216 , V_49 ) ;
}
static int F_53 ( struct V_21 * V_22 ,
struct V_162 * V_233 ,
enum V_90 type )
{
struct V_87 * V_88 ;
int V_71 ;
if ( F_54 ( V_22 -> V_206 ) )
return - V_63 ;
V_88 = F_55 ( V_22 ) ;
if ( ! V_88 )
return - V_234 ;
V_71 = F_42 ( V_22 , V_88 , type ) ;
if ( V_71 )
goto V_235;
V_71 = F_35 ( V_22 , V_233 , type ) ;
V_235:
F_56 ( V_22 , V_88 ) ;
return V_71 ;
}
static void
F_57 ( struct V_21 * V_22 ,
T_1 * V_130 , struct V_111 * V_112 )
{
T_2 V_131 = 0 ;
int V_27 ;
* V_130 &= ~ V_236 ;
if ( V_112 -> V_130 . V_132 )
* V_130 |= V_237 ;
else
* V_130 &= ~ V_237 ;
if ( V_112 -> V_130 . V_136 )
* V_130 |= V_238 ;
else
* V_130 &= ~ V_238 ;
* V_130 &= ~ V_239 ;
* V_130 |= ( T_1 ) V_112 -> V_130 . V_134 << V_240 ;
for ( V_27 = 0 ; V_27 < V_156 ; V_27 ++ )
if ( V_112 -> V_130 . V_41 [ V_27 ] )
V_131 |= F_58 ( V_27 ) ;
* V_130 &= ~ V_241 ;
* V_130 |= ( V_131 << V_242 ) ;
F_12 ( V_22 , V_28 , L_17 , * V_130 ) ;
}
static void
F_59 ( struct V_21 * V_22 ,
struct V_67 * V_68 ,
struct V_111 * V_112 )
{
T_2 * V_147 , * V_148 ;
T_1 V_104 ;
int V_27 ;
if ( V_112 -> V_149 )
V_68 -> V_69 |= V_243 ;
else
V_68 -> V_69 &= ~ V_243 ;
if ( V_112 -> V_153 )
V_68 -> V_69 |= V_244 ;
else
V_68 -> V_69 &= ~ V_244 ;
if ( V_112 -> V_151 )
V_68 -> V_69 |= V_245 ;
else
V_68 -> V_69 &= ~ V_245 ;
V_68 -> V_69 &= ~ V_246 ;
V_68 -> V_69 |= ( T_1 ) V_112 -> V_155 << V_247 ;
V_147 = ( T_2 * ) & V_68 -> V_157 [ 0 ] ;
V_148 = ( T_2 * ) & V_68 -> V_158 [ 0 ] ;
V_68 -> V_54 [ 0 ] = 0 ;
for ( V_27 = 0 ; V_27 < V_156 ; V_27 ++ ) {
V_147 [ V_27 ] = V_112 -> V_159 [ V_27 ] ;
V_148 [ V_27 ] = V_112 -> V_160 [ V_27 ] ;
V_104 = ( ( ( T_1 ) V_112 -> V_161 [ V_27 ] ) << ( ( 7 - V_27 ) * 4 ) ) ;
V_68 -> V_54 [ 0 ] |= V_104 ;
}
for ( V_27 = 0 ; V_27 < 2 ; V_27 ++ ) {
V_68 -> V_157 [ V_27 ] = F_60 ( V_68 -> V_157 [ V_27 ] ) ;
V_68 -> V_158 [ V_27 ] = F_60 ( V_68 -> V_158 [ V_27 ] ) ;
}
}
static void
F_61 ( struct V_21 * V_22 ,
struct V_64 * V_65 ,
struct V_111 * V_112 , bool V_11 )
{
T_1 * V_60 ;
int V_27 ;
if ( V_112 -> V_115 )
V_65 -> V_69 |= V_248 ;
else
V_65 -> V_69 &= ~ V_248 ;
if ( V_112 -> V_117 )
V_65 -> V_69 |= V_249 ;
else
V_65 -> V_69 &= ~ V_249 ;
V_65 -> V_69 &= ~ V_250 ;
V_65 -> V_69 |= ( T_1 ) V_112 -> V_121 <<
V_251 ;
for ( V_27 = 0 ; V_27 < V_122 ; V_27 ++ ) {
V_60 = & V_65 -> V_77 [ V_27 ] . V_60 ;
* V_60 = 0 ;
if ( V_11 ) {
* V_60 &= ~ ( V_252 | V_253 ) ;
switch ( V_112 -> V_123 [ V_27 ] . V_124 ) {
case V_126 :
* V_60 |= ( ( T_1 ) V_7 <<
V_254 ) ;
* V_60 |= ( ( T_1 ) V_3 <<
V_255 ) ;
break;
case V_127 :
* V_60 |= ( ( T_1 ) V_15 <<
V_254 ) ;
* V_60 |= ( ( T_1 ) V_8 <<
V_255 ) ;
break;
case V_128 :
* V_60 |= ( ( T_1 ) V_19 <<
V_254 ) ;
* V_60 |= ( ( T_1 ) V_8 <<
V_255 ) ;
break;
case V_125 :
* V_60 |= ( ( T_1 ) V_9 <<
V_254 ) ;
* V_60 |= ( ( T_1 ) V_8 <<
V_255 ) ;
break;
}
} else {
* V_60 &= ~ V_253 ;
if ( V_112 -> V_123 [ V_27 ] . V_12 )
* V_60 |= ( ( T_1 ) V_3 <<
V_255 ) ;
else
* V_60 |= ( ( T_1 ) V_8 <<
V_255 ) ;
}
* V_60 &= ~ V_256 ;
* V_60 |= ( ( T_1 ) V_112 -> V_123 [ V_27 ] . V_10 <<
V_257 ) ;
* V_60 &= ~ V_258 ;
* V_60 |= ( ( T_1 ) ( V_112 -> V_123 [ V_27 ] . V_41 ) <<
V_259 ) ;
}
}
static void
F_62 ( struct V_21 * V_22 ,
struct V_201 * V_166 ,
struct V_260 * V_163 )
{
bool V_11 = false ;
V_166 -> V_69 = 0 ;
memcpy ( & V_166 -> V_75 ,
& V_22 -> V_72 -> V_73 . V_75 ,
sizeof( V_166 -> V_75 ) ) ;
if ( V_163 -> V_136 ) {
V_166 -> V_261 = V_163 -> V_262 ;
V_11 = ! ! ( V_163 -> V_262 & V_59 ) ;
} else {
V_166 -> V_261 = V_173 ;
}
F_12 ( V_22 , V_28 , L_18 ,
V_166 -> V_261 ) ;
if ( V_163 -> V_263 & V_264 )
F_57 ( V_22 , & V_166 -> V_75 . V_130 ,
& V_163 -> V_261 . V_163 ) ;
if ( V_163 -> V_263 & V_265 )
F_59 ( V_22 , & V_166 -> V_75 . V_78 ,
& V_163 -> V_261 . V_163 ) ;
if ( V_163 -> V_263 & V_266 )
F_61 ( V_22 , & V_166 -> V_75 . V_76 ,
& V_163 -> V_261 . V_163 , V_11 ) ;
}
int F_63 ( struct V_21 * V_22 , struct V_87 * V_88 ,
struct V_260 * V_163 , bool V_267 )
{
struct V_201 V_166 ;
struct V_89 V_66 ;
T_1 V_268 = 0 , V_269 = 0 ;
int V_71 = 0 ;
if ( ! V_267 ) {
memcpy ( & V_22 -> V_72 -> V_270 , V_163 ,
sizeof( struct V_260 ) ) ;
return 0 ;
}
memset ( & V_22 -> V_72 -> V_270 , 0 , sizeof( V_22 -> V_72 -> V_270 ) ) ;
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
F_62 ( V_22 , & V_166 , V_163 ) ;
V_66 . V_96 = V_22 -> V_192 -> V_193 +
F_37 ( struct V_194 , V_200 ) ;
V_66 . V_166 = & V_166 ;
V_66 . V_97 = sizeof( struct V_201 ) ;
F_64 ( V_22 , V_88 , V_66 . V_96 , V_66 . V_166 , V_66 . V_97 ) ;
V_71 = F_65 ( V_22 , V_88 , V_271 ,
1 << V_272 , & V_268 , & V_269 ) ;
if ( V_71 )
F_66 ( V_22 , L_19 ) ;
return V_71 ;
}
int F_67 ( struct V_21 * V_22 ,
struct V_260 * V_163 )
{
struct V_162 * V_273 ;
int V_71 ;
if ( V_22 -> V_72 -> V_270 . V_261 . V_168 ) {
memcpy ( V_163 , & V_22 -> V_72 -> V_270 ,
sizeof( struct V_260 ) ) ;
return 0 ;
}
V_273 = F_48 ( sizeof( * V_273 ) , V_213 ) ;
if ( ! V_273 )
return - V_214 ;
memset ( V_273 , 0 , sizeof( * V_273 ) ) ;
V_71 = F_53 ( V_22 , V_273 , V_190 ) ;
if ( V_71 ) {
F_50 ( V_273 ) ;
return V_71 ;
}
V_22 -> V_72 -> V_270 . V_263 = 0 ;
V_22 -> V_72 -> V_270 . V_262 = V_173 ;
if ( V_273 -> V_73 . V_175 )
V_22 -> V_72 -> V_270 . V_262 |= V_174 ;
if ( V_273 -> V_73 . V_11 )
V_22 -> V_72 -> V_270 . V_262 |= V_59 ;
if ( V_273 -> V_73 . V_167 )
V_22 -> V_72 -> V_270 . V_262 |= V_176 ;
V_22 -> V_72 -> V_270 . V_136 = V_273 -> V_73 . V_136 ;
memcpy ( & V_22 -> V_72 -> V_270 . V_261 . V_163 ,
& V_273 -> V_73 . V_163 ,
sizeof( struct V_274 ) ) ;
V_22 -> V_72 -> V_270 . V_261 . V_168 = true ;
memcpy ( V_163 , & V_22 -> V_72 -> V_270 , sizeof( struct V_260 ) ) ;
F_50 ( V_273 ) ;
return 0 ;
}
static struct V_162 * F_68 ( struct V_21 * V_202 ,
enum V_90 type )
{
struct V_162 * V_273 ;
V_273 = F_69 ( sizeof( * V_273 ) , V_275 ) ;
if ( ! V_273 )
return NULL ;
memset ( V_273 , 0 , sizeof( * V_273 ) ) ;
if ( F_53 ( V_202 , V_273 , type ) ) {
F_50 ( V_273 ) ;
return NULL ;
}
if ( ( type == V_190 ) &&
! V_273 -> V_73 . V_136 ) {
F_70 ( V_202 , L_20 ) ;
F_50 ( V_273 ) ;
return NULL ;
}
return V_273 ;
}
static T_2 F_71 ( struct V_276 * V_206 )
{
struct V_21 * V_202 = F_72 ( V_206 ) ;
struct V_162 * V_273 ;
bool V_136 ;
V_273 = F_68 ( V_202 , V_190 ) ;
if ( ! V_273 )
return 0 ;
V_136 = V_273 -> V_73 . V_136 ;
F_12 ( V_202 , V_28 , L_21 , V_136 ) ;
F_50 ( V_273 ) ;
return V_136 ;
}
static T_2 F_73 ( struct V_276 * V_206 , T_2 V_277 )
{
struct V_21 * V_202 = F_72 ( V_206 ) ;
struct V_260 V_278 ;
struct V_87 * V_279 ;
int V_71 ;
F_12 ( V_202 , V_28 , L_21 , V_277 ) ;
memset ( & V_278 , 0 , sizeof( V_278 ) ) ;
V_71 = F_67 ( V_202 , & V_278 ) ;
if ( V_71 )
return 1 ;
V_278 . V_136 = ! ! V_277 ;
V_279 = F_55 ( V_202 ) ;
if ( ! V_279 )
return 1 ;
V_71 = F_63 ( V_202 , V_279 , & V_278 , 0 ) ;
F_56 ( V_202 , V_279 ) ;
return V_71 ? 1 : 0 ;
}
static void F_74 ( struct V_276 * V_206 , int V_36 , T_2 * V_280 ,
T_2 * V_281 , T_2 * V_282 , T_2 * V_283 )
{
struct V_21 * V_202 = F_72 ( V_206 ) ;
struct V_162 * V_273 ;
F_12 ( V_202 , V_28 , L_22 , V_36 ) ;
* V_280 = * V_281 = * V_282 = * V_283 = 0 ;
if ( V_36 < 0 || V_36 >= V_156 ) {
F_70 ( V_202 , L_23 , V_36 ) ;
return;
}
V_273 = F_68 ( V_202 , V_190 ) ;
if ( ! V_273 )
return;
* V_281 = V_273 -> V_73 . V_163 . V_161 [ V_36 ] ;
F_50 ( V_273 ) ;
}
static void F_75 ( struct V_276 * V_206 , int V_281 , T_2 * V_282 )
{
struct V_21 * V_202 = F_72 ( V_206 ) ;
struct V_162 * V_273 ;
* V_282 = 0 ;
F_12 ( V_202 , V_28 , L_24 , V_281 ) ;
if ( V_281 < 0 || V_281 >= V_156 ) {
F_70 ( V_202 , L_25 , V_281 ) ;
return;
}
V_273 = F_68 ( V_202 , V_190 ) ;
if ( ! V_273 )
return;
* V_282 = V_273 -> V_73 . V_163 . V_159 [ V_281 ] ;
F_12 ( V_202 , V_28 , L_26 , * V_282 ) ;
F_50 ( V_273 ) ;
}
static void F_76 ( struct V_276 * V_206 , int V_36 , T_2 * V_41 ,
T_2 * V_284 , T_2 * V_282 , T_2 * V_283 )
{
F_70 ( F_72 ( V_206 ) , L_27 ) ;
* V_41 = * V_284 = * V_282 = * V_283 = 0 ;
}
static void F_77 ( struct V_276 * V_206 ,
int V_284 , T_2 * V_282 )
{
F_70 ( F_72 ( V_206 ) , L_27 ) ;
* V_282 = 0 ;
}
static void F_78 ( struct V_276 * V_206 ,
int V_35 , T_2 * V_285 )
{
struct V_21 * V_202 = F_72 ( V_206 ) ;
struct V_162 * V_273 ;
F_12 ( V_202 , V_28 , L_28 , V_35 ) ;
if ( V_35 < 0 || V_35 >= V_156 ) {
F_70 ( V_202 , L_29 , V_35 ) ;
return;
}
V_273 = F_68 ( V_202 , V_190 ) ;
if ( ! V_273 )
return;
* V_285 = V_273 -> V_73 . V_163 . V_130 . V_41 [ V_35 ] ;
F_12 ( V_202 , V_28 , L_30 , * V_285 ) ;
F_50 ( V_273 ) ;
}
static void F_79 ( struct V_276 * V_206 , int V_35 , T_2 V_285 )
{
struct V_21 * V_202 = F_72 ( V_206 ) ;
struct V_260 V_278 ;
struct V_87 * V_279 ;
int V_71 ;
F_12 ( V_202 , V_28 , L_31 ,
V_35 , V_285 ) ;
if ( V_35 < 0 || V_35 >= V_156 ) {
F_70 ( V_202 , L_29 , V_35 ) ;
return;
}
memset ( & V_278 , 0 , sizeof( V_278 ) ) ;
V_71 = F_67 ( V_202 , & V_278 ) ;
if ( V_71 )
return;
V_278 . V_263 |= V_264 ;
V_278 . V_261 . V_163 . V_130 . V_41 [ V_35 ] = ! ! V_285 ;
V_279 = F_55 ( V_202 ) ;
if ( ! V_279 )
return;
V_71 = F_63 ( V_202 , V_279 , & V_278 , 0 ) ;
F_56 ( V_202 , V_279 ) ;
}
static T_2 F_80 ( struct V_276 * V_206 , int V_286 , T_2 * V_287 )
{
struct V_21 * V_202 = F_72 ( V_206 ) ;
struct V_162 * V_273 ;
int V_71 = 0 ;
F_12 ( V_202 , V_28 , L_32 , V_286 ) ;
V_273 = F_68 ( V_202 , V_190 ) ;
if ( ! V_273 )
return 1 ;
switch ( V_286 ) {
case V_288 :
case V_289 :
case V_290 :
case V_291 :
* V_287 = true ;
break;
case V_292 :
case V_293 :
* V_287 = 0x80 ;
break;
case V_294 :
* V_287 = ( V_295 | V_296 |
V_297 ) ;
break;
default:
* V_287 = false ;
V_71 = 1 ;
}
F_12 ( V_202 , V_28 , L_33 , V_286 , * V_287 ) ;
F_50 ( V_273 ) ;
return V_71 ;
}
static int F_81 ( struct V_276 * V_206 , int V_298 , T_2 * V_299 )
{
struct V_21 * V_202 = F_72 ( V_206 ) ;
struct V_162 * V_273 ;
int V_71 = 0 ;
F_12 ( V_202 , V_28 , L_34 , V_298 ) ;
V_273 = F_68 ( V_202 , V_190 ) ;
if ( ! V_273 )
return - V_63 ;
switch ( V_298 ) {
case V_300 :
* V_299 = V_273 -> V_73 . V_163 . V_155 ;
break;
case V_301 :
* V_299 = V_273 -> V_73 . V_163 . V_130 . V_134 ;
break;
default:
V_71 = - V_63 ;
}
F_50 ( V_273 ) ;
F_12 ( V_202 , V_28 , L_35 , * V_299 ) ;
return V_71 ;
}
static T_2 F_82 ( struct V_276 * V_206 )
{
struct V_21 * V_202 = F_72 ( V_206 ) ;
struct V_162 * V_273 ;
bool V_136 ;
V_273 = F_68 ( V_202 , V_190 ) ;
if ( ! V_273 )
return 0 ;
V_136 = V_273 -> V_73 . V_163 . V_130 . V_136 ;
F_12 ( V_202 , V_28 , L_36 , V_136 ) ;
F_50 ( V_273 ) ;
return V_136 ;
}
static T_2 F_83 ( struct V_276 * V_206 )
{
struct V_21 * V_202 = F_72 ( V_206 ) ;
struct V_162 * V_273 ;
T_2 V_302 = 0 ;
V_273 = F_68 ( V_202 , V_190 ) ;
if ( ! V_273 )
return 0 ;
if ( V_273 -> V_73 . V_136 )
V_302 |= V_295 ;
if ( V_273 -> V_73 . V_11 )
V_302 |= V_297 ;
if ( V_273 -> V_73 . V_175 )
V_302 |= V_296 ;
F_12 ( V_202 , V_28 , L_37 , V_302 ) ;
F_50 ( V_273 ) ;
return V_302 ;
}
static void F_84 ( struct V_276 * V_206 ,
int V_36 ,
T_2 V_303 , T_2 V_281 , T_2 V_282 , T_2 V_283 )
{
struct V_21 * V_202 = F_72 ( V_206 ) ;
struct V_260 V_278 ;
struct V_87 * V_279 ;
int V_71 ;
F_12 ( V_202 , V_28 ,
L_38 ,
V_36 , V_303 , V_281 , V_282 , V_283 ) ;
if ( V_36 < 0 || V_36 >= V_156 ) {
F_70 ( V_202 , L_23 , V_36 ) ;
return;
}
memset ( & V_278 , 0 , sizeof( V_278 ) ) ;
V_71 = F_67 ( V_202 , & V_278 ) ;
if ( V_71 )
return;
V_278 . V_263 |= V_265 ;
V_278 . V_261 . V_163 . V_161 [ V_36 ] = V_281 ;
V_279 = F_55 ( V_202 ) ;
if ( ! V_279 )
return;
V_71 = F_63 ( V_202 , V_279 , & V_278 , 0 ) ;
F_56 ( V_202 , V_279 ) ;
}
static void F_85 ( struct V_276 * V_206 , int V_41 ,
T_2 V_303 , T_2 V_281 , T_2 V_282 , T_2 V_283 )
{
F_70 ( F_72 ( V_206 ) , L_27 ) ;
}
static void F_86 ( struct V_276 * V_206 , int V_281 , T_2 V_282 )
{
struct V_21 * V_202 = F_72 ( V_206 ) ;
struct V_260 V_278 ;
struct V_87 * V_279 ;
int V_71 ;
F_12 ( V_202 , V_28 , L_39 , V_281 , V_282 ) ;
if ( V_281 < 0 || V_281 >= V_156 ) {
F_70 ( V_202 , L_25 , V_281 ) ;
return;
}
memset ( & V_278 , 0 , sizeof( V_278 ) ) ;
V_71 = F_67 ( V_202 , & V_278 ) ;
if ( V_71 )
return;
V_278 . V_263 |= V_265 ;
V_278 . V_261 . V_163 . V_159 [ V_281 ] = V_282 ;
V_279 = F_55 ( V_202 ) ;
if ( ! V_279 )
return;
V_71 = F_63 ( V_202 , V_279 , & V_278 , 0 ) ;
F_56 ( V_202 , V_279 ) ;
}
static void F_87 ( struct V_276 * V_206 , int V_281 , T_2 V_282 )
{
F_70 ( F_72 ( V_206 ) , L_27 ) ;
}
static T_2 F_88 ( struct V_276 * V_206 )
{
struct V_21 * V_202 = F_72 ( V_206 ) ;
struct V_260 V_278 ;
struct V_87 * V_279 ;
int V_71 ;
memset ( & V_278 , 0 , sizeof( V_278 ) ) ;
V_71 = F_67 ( V_202 , & V_278 ) ;
if ( V_71 )
return 1 ;
V_279 = F_55 ( V_202 ) ;
if ( ! V_279 )
return 1 ;
V_71 = F_63 ( V_202 , V_279 , & V_278 , 1 ) ;
F_56 ( V_202 , V_279 ) ;
return V_71 ;
}
static int F_89 ( struct V_276 * V_206 , int V_298 , T_2 V_299 )
{
struct V_21 * V_202 = F_72 ( V_206 ) ;
struct V_260 V_278 ;
struct V_87 * V_279 ;
int V_71 ;
F_12 ( V_202 , V_28 , L_40 , V_298 , V_299 ) ;
memset ( & V_278 , 0 , sizeof( V_278 ) ) ;
V_71 = F_67 ( V_202 , & V_278 ) ;
if ( V_71 )
return 1 ;
switch ( V_298 ) {
case V_300 :
V_278 . V_263 |= V_265 ;
V_278 . V_261 . V_163 . V_155 = V_299 ;
break;
case V_301 :
V_278 . V_263 |= V_264 ;
V_278 . V_261 . V_163 . V_130 . V_134 = V_299 ;
break;
default:
F_70 ( V_202 , L_41 , V_298 ) ;
return - V_63 ;
}
V_279 = F_55 ( V_202 ) ;
if ( ! V_279 )
return - V_63 ;
V_71 = F_63 ( V_202 , V_279 , & V_278 , 0 ) ;
F_56 ( V_202 , V_279 ) ;
return 0 ;
}
static void F_90 ( struct V_276 * V_206 , T_2 V_277 )
{
struct V_21 * V_202 = F_72 ( V_206 ) ;
struct V_260 V_278 ;
struct V_87 * V_279 ;
int V_71 ;
F_12 ( V_202 , V_28 , L_42 , V_277 ) ;
memset ( & V_278 , 0 , sizeof( V_278 ) ) ;
V_71 = F_67 ( V_202 , & V_278 ) ;
if ( V_71 )
return;
V_278 . V_263 |= V_264 ;
V_278 . V_261 . V_163 . V_130 . V_136 = ! ! V_277 ;
V_279 = F_55 ( V_202 ) ;
if ( ! V_279 )
return;
V_71 = F_63 ( V_202 , V_279 , & V_278 , 0 ) ;
F_56 ( V_202 , V_279 ) ;
}
static int F_91 ( struct V_276 * V_206 , T_2 V_304 , T_3 V_305 )
{
struct V_21 * V_202 = F_72 ( V_206 ) ;
struct V_162 * V_273 ;
struct V_113 * V_60 ;
bool V_12 ;
T_2 V_41 = 0 ;
int V_27 ;
V_273 = F_68 ( V_202 , V_190 ) ;
if ( ! V_273 )
return - V_63 ;
V_12 = ! ! ( V_304 == V_306 ) ;
for ( V_27 = 0 ; V_27 < V_307 ; V_27 ++ ) {
V_60 = & V_273 -> V_73 . V_163 . V_123 [ V_27 ] ;
if ( ( V_60 -> V_12 == V_12 ) && ( V_60 -> V_10 == V_305 ) ) {
V_41 = V_60 -> V_41 ;
break;
}
}
if ( V_27 == V_307 ) {
F_17 ( V_206 , L_43 , V_304 , V_305 ) ;
F_50 ( V_273 ) ;
return - V_63 ;
}
F_50 ( V_273 ) ;
return V_41 ;
}
static int F_92 ( struct V_276 * V_206 ,
T_2 V_304 , T_3 V_305 , T_2 V_114 )
{
struct V_21 * V_202 = F_72 ( V_206 ) ;
struct V_260 V_278 ;
struct V_113 * V_60 ;
struct V_87 * V_279 ;
bool V_12 ;
int V_71 , V_27 ;
memset ( & V_278 , 0 , sizeof( V_278 ) ) ;
V_71 = F_67 ( V_202 , & V_278 ) ;
if ( V_71 )
return - V_63 ;
V_12 = ! ! ( V_304 == V_306 ) ;
for ( V_27 = 0 ; V_27 < V_307 ; V_27 ++ ) {
V_60 = & V_278 . V_261 . V_163 . V_123 [ V_27 ] ;
if ( ( V_60 -> V_12 == V_12 ) && ( V_60 -> V_10 == V_305 ) )
break;
if ( ! V_60 -> V_10 ) {
V_278 . V_261 . V_163 . V_121 ++ ;
break;
}
}
if ( V_27 == V_307 ) {
F_17 ( V_206 , L_44 ) ;
return - V_234 ;
}
V_278 . V_263 |= V_266 ;
V_278 . V_261 . V_163 . V_123 [ V_27 ] . V_12 = V_12 ;
V_278 . V_261 . V_163 . V_123 [ V_27 ] . V_10 = V_305 ;
V_278 . V_261 . V_163 . V_123 [ V_27 ] . V_41 = V_114 ;
V_279 = F_55 ( V_202 ) ;
if ( ! V_279 )
return - V_234 ;
V_71 = F_63 ( V_202 , V_279 , & V_278 , 0 ) ;
F_56 ( V_202 , V_279 ) ;
return V_71 ;
}
static T_2 F_93 ( struct V_276 * V_206 , T_2 V_302 )
{
struct V_21 * V_202 = F_72 ( V_206 ) ;
struct V_260 V_278 ;
struct V_87 * V_279 ;
int V_71 ;
F_12 ( V_202 , V_28 , L_45 , V_302 ) ;
if ( ! ( V_302 & V_297 ) &&
! ( V_302 & V_296 ) && ! ( V_302 & V_308 ) ) {
F_70 ( V_202 , L_46 ) ;
return 1 ;
}
memset ( & V_278 , 0 , sizeof( V_278 ) ) ;
V_71 = F_67 ( V_202 , & V_278 ) ;
if ( V_71 )
return 1 ;
V_278 . V_262 = 0 ;
if ( V_302 & V_296 ) {
V_278 . V_262 |= V_174 ;
V_278 . V_136 = true ;
}
if ( V_302 & V_297 ) {
V_278 . V_262 |= V_59 ;
V_278 . V_136 = true ;
}
if ( V_302 & V_308 ) {
V_278 . V_262 |= V_176 ;
V_278 . V_136 = true ;
}
V_279 = F_55 ( V_202 ) ;
if ( ! V_279 )
return 1 ;
V_71 = F_63 ( V_202 , V_279 , & V_278 , 0 ) ;
F_56 ( V_202 , V_279 ) ;
return V_71 ;
}
static T_2 F_94 ( struct V_276 * V_206 , int V_309 , T_2 * V_69 )
{
struct V_21 * V_202 = F_72 ( V_206 ) ;
struct V_162 * V_273 ;
F_12 ( V_202 , V_28 , L_47 , V_309 ) ;
V_273 = F_68 ( V_202 , V_190 ) ;
if ( ! V_273 )
return 1 ;
* V_69 = 0 ;
switch ( V_309 ) {
case V_310 :
if ( V_273 -> V_73 . V_163 . V_151 )
* V_69 = V_311 ;
else
* V_69 = V_312 ;
break;
case V_313 :
if ( V_273 -> V_73 . V_163 . V_130 . V_136 )
* V_69 = V_311 ;
else
* V_69 = V_312 ;
break;
case V_314 :
if ( V_273 -> V_73 . V_163 . V_117 )
* V_69 = V_311 ;
else
* V_69 = V_312 ;
break;
default:
F_70 ( V_202 , L_48 , V_309 ) ;
F_50 ( V_273 ) ;
return 1 ;
}
F_12 ( V_202 , V_28 , L_49 , * V_69 ) ;
F_50 ( V_273 ) ;
return 0 ;
}
static T_2 F_95 ( struct V_276 * V_206 , int V_309 , T_2 V_69 )
{
struct V_21 * V_202 = F_72 ( V_206 ) ;
struct V_260 V_278 ;
bool V_136 , V_132 ;
struct V_87 * V_279 ;
int V_71 ;
F_12 ( V_202 , V_28 , L_50 ,
V_309 , V_69 ) ;
memset ( & V_278 , 0 , sizeof( V_278 ) ) ;
V_71 = F_67 ( V_202 , & V_278 ) ;
if ( V_71 )
return 1 ;
V_136 = ! ! ( V_69 & V_311 ) ;
V_132 = ! ! ( V_69 & V_315 ) ;
switch ( V_309 ) {
case V_310 :
V_278 . V_263 |= V_265 ;
V_278 . V_261 . V_163 . V_151 = V_136 ;
V_278 . V_261 . V_163 . V_149 = V_132 ;
break;
case V_313 :
V_278 . V_263 |= V_264 ;
V_278 . V_261 . V_163 . V_130 . V_136 = V_136 ;
V_278 . V_261 . V_163 . V_130 . V_132 = V_132 ;
break;
case V_314 :
V_278 . V_263 |= V_266 ;
V_278 . V_261 . V_163 . V_115 = V_132 ;
break;
default:
F_70 ( V_202 , L_48 , V_309 ) ;
return 1 ;
}
V_279 = F_55 ( V_202 ) ;
if ( ! V_279 )
return 1 ;
V_71 = F_63 ( V_202 , V_279 , & V_278 , 0 ) ;
F_56 ( V_202 , V_279 ) ;
return 0 ;
}
static int F_96 ( struct V_276 * V_206 ,
struct V_316 * V_317 ,
T_3 * V_318 )
{
struct V_21 * V_202 = F_72 ( V_206 ) ;
struct V_162 * V_273 ;
V_273 = F_68 ( V_202 , V_188 ) ;
if ( ! V_273 )
return - V_63 ;
V_317 -> V_132 = V_273 -> V_169 . V_163 . V_115 ;
V_317 -> error = V_273 -> V_169 . V_163 . V_119 ;
* V_318 = V_273 -> V_169 . V_163 . V_121 ;
F_50 ( V_273 ) ;
return 0 ;
}
static int F_97 ( struct V_276 * V_206 ,
struct V_319 * V_320 )
{
struct V_21 * V_202 = F_72 ( V_206 ) ;
struct V_162 * V_273 ;
int V_27 ;
V_273 = F_68 ( V_202 , V_188 ) ;
if ( ! V_273 )
return - V_63 ;
for ( V_27 = 0 ; V_27 < V_273 -> V_169 . V_163 . V_121 ; V_27 ++ ) {
if ( V_273 -> V_169 . V_163 . V_123 [ V_27 ] . V_12 )
V_320 [ V_27 ] . V_321 = V_306 ;
else
V_320 [ V_27 ] . V_321 = V_322 ;
V_320 [ V_27 ] . V_35 = V_273 -> V_169 . V_163 . V_123 [ V_27 ] . V_41 ;
V_320 [ V_27 ] . V_323 =
V_273 -> V_169 . V_163 . V_123 [ V_27 ] . V_10 ;
}
F_50 ( V_273 ) ;
return 0 ;
}
static int F_98 ( struct V_276 * V_206 , struct V_324 * V_130 )
{
struct V_21 * V_202 = F_72 ( V_206 ) ;
struct V_162 * V_273 ;
int V_27 ;
V_273 = F_68 ( V_202 , V_188 ) ;
if ( ! V_273 )
return - V_63 ;
for ( V_27 = 0 ; V_27 < V_156 ; V_27 ++ )
if ( V_273 -> V_169 . V_163 . V_130 . V_41 [ V_27 ] )
V_130 -> V_325 |= F_58 ( V_27 ) ;
V_130 -> V_326 = V_273 -> V_169 . V_163 . V_130 . V_134 ;
F_12 ( V_202 , V_28 , L_51 ,
V_130 -> V_325 , V_130 -> V_326 ) ;
F_50 ( V_273 ) ;
return 0 ;
}
static int F_99 ( struct V_276 * V_206 , struct V_327 * V_328 )
{
struct V_21 * V_202 = F_72 ( V_206 ) ;
struct V_162 * V_273 ;
int V_27 ;
V_273 = F_68 ( V_202 , V_188 ) ;
if ( ! V_273 )
return - V_63 ;
V_328 -> V_132 = V_273 -> V_169 . V_163 . V_149 ;
for ( V_27 = 0 ; V_27 < V_156 ; V_27 ++ ) {
V_328 -> V_329 [ V_27 ] = V_273 -> V_169 . V_163 . V_159 [ V_27 ] ;
V_328 -> V_330 [ V_27 ] = V_273 -> V_169 . V_163 . V_161 [ V_27 ] ;
}
F_12 ( V_202 , V_28 , L_52 , V_328 -> V_132 ) ;
F_50 ( V_273 ) ;
return 0 ;
}
static int F_100 ( struct V_276 * V_206 ,
struct V_331 * V_130 , bool V_169 )
{
struct V_21 * V_202 = F_72 ( V_206 ) ;
struct V_111 * V_163 ;
struct V_162 * V_273 ;
int V_71 , V_27 ;
V_273 = F_68 ( V_202 , V_190 ) ;
if ( ! V_273 )
return - V_63 ;
if ( ! V_273 -> V_73 . V_11 ) {
F_70 ( V_202 , L_53 ) ;
F_50 ( V_273 ) ;
return - V_63 ;
}
if ( V_169 ) {
memset ( V_273 , 0 , sizeof( * V_273 ) ) ;
V_71 = F_53 ( V_202 , V_273 ,
V_188 ) ;
if ( V_71 ) {
F_50 ( V_273 ) ;
return - V_63 ;
}
V_163 = & V_273 -> V_169 . V_163 ;
} else {
V_163 = & V_273 -> V_73 . V_163 ;
}
V_130 -> V_332 = V_163 -> V_130 . V_134 ;
V_130 -> V_325 = 0 ;
for ( V_27 = 0 ; V_27 < V_156 ; V_27 ++ )
if ( V_163 -> V_130 . V_41 [ V_27 ] )
V_130 -> V_325 |= F_58 ( V_27 ) ;
F_50 ( V_273 ) ;
return 0 ;
}
static int F_101 ( struct V_276 * V_206 , struct V_331 * V_130 )
{
return F_100 ( V_206 , V_130 , false ) ;
}
static int F_102 ( struct V_276 * V_206 , struct V_331 * V_130 )
{
struct V_21 * V_202 = F_72 ( V_206 ) ;
struct V_162 * V_273 ;
struct V_260 V_278 ;
struct V_87 * V_279 ;
int V_71 , V_27 ;
V_273 = F_68 ( V_202 , V_190 ) ;
if ( ! V_273 )
return - V_63 ;
if ( ! V_273 -> V_73 . V_11 ) {
F_70 ( V_202 , L_53 ) ;
F_50 ( V_273 ) ;
return - V_63 ;
}
F_50 ( V_273 ) ;
memset ( & V_278 , 0 , sizeof( V_278 ) ) ;
V_71 = F_67 ( V_202 , & V_278 ) ;
if ( V_71 )
return - V_63 ;
V_278 . V_263 |= V_264 ;
for ( V_27 = 0 ; V_27 < V_156 ; V_27 ++ )
V_278 . V_261 . V_163 . V_130 . V_41 [ V_27 ] = ! ! ( V_130 -> V_325 & F_58 ( V_27 ) ) ;
V_278 . V_261 . V_163 . V_130 . V_134 = V_130 -> V_332 ;
V_279 = F_55 ( V_202 ) ;
if ( ! V_279 )
return - V_63 ;
V_71 = F_63 ( V_202 , V_279 , & V_278 , 0 ) ;
F_56 ( V_202 , V_279 ) ;
return V_71 ;
}
static int F_103 ( struct V_276 * V_206 ,
struct V_333 * V_78 , bool V_169 )
{
struct V_21 * V_202 = F_72 ( V_206 ) ;
struct V_162 * V_273 ;
struct V_111 * V_163 ;
int V_71 ;
V_273 = F_68 ( V_202 , V_190 ) ;
if ( ! V_273 )
return - V_63 ;
if ( ! V_273 -> V_73 . V_11 ) {
F_70 ( V_202 , L_53 ) ;
F_50 ( V_273 ) ;
return - V_63 ;
}
if ( V_169 ) {
memset ( V_273 , 0 , sizeof( * V_273 ) ) ;
V_71 = F_53 ( V_202 , V_273 ,
V_188 ) ;
if ( V_71 ) {
F_50 ( V_273 ) ;
return - V_63 ;
}
V_163 = & V_273 -> V_169 . V_163 ;
} else {
V_163 = & V_273 -> V_73 . V_163 ;
}
V_78 -> V_334 = V_163 -> V_155 ;
V_78 -> V_132 = V_163 -> V_149 ;
V_78 -> V_335 = V_163 -> V_153 ;
memcpy ( V_78 -> V_336 , V_163 -> V_159 , sizeof( V_78 -> V_336 ) ) ;
memcpy ( V_78 -> V_337 , V_163 -> V_160 , sizeof( V_78 -> V_337 ) ) ;
memcpy ( V_78 -> V_338 , V_163 -> V_161 , sizeof( V_78 -> V_338 ) ) ;
F_50 ( V_273 ) ;
return 0 ;
}
static int F_104 ( struct V_276 * V_206 , struct V_333 * V_78 )
{
return F_103 ( V_206 , V_78 , false ) ;
}
static int F_105 ( struct V_276 * V_206 , struct V_333 * V_78 )
{
struct V_21 * V_202 = F_72 ( V_206 ) ;
struct V_162 * V_273 ;
struct V_260 V_278 ;
struct V_87 * V_279 ;
int V_71 ;
V_273 = F_68 ( V_202 , V_190 ) ;
if ( ! V_273 )
return - V_63 ;
if ( ! V_273 -> V_73 . V_11 ) {
F_70 ( V_202 , L_53 ) ;
F_50 ( V_273 ) ;
return - V_63 ;
}
F_50 ( V_273 ) ;
memset ( & V_278 , 0 , sizeof( V_278 ) ) ;
V_71 = F_67 ( V_202 , & V_278 ) ;
if ( V_71 )
return - V_63 ;
V_278 . V_263 |= V_265 ;
V_278 . V_261 . V_163 . V_155 = V_78 -> V_334 ;
V_278 . V_261 . V_163 . V_149 = V_78 -> V_132 ;
V_278 . V_261 . V_163 . V_153 = V_78 -> V_335 ;
memcpy ( V_278 . V_261 . V_163 . V_159 , V_78 -> V_336 ,
sizeof( V_78 -> V_336 ) ) ;
memcpy ( V_278 . V_261 . V_163 . V_160 , V_78 -> V_337 ,
sizeof( V_78 -> V_337 ) ) ;
memcpy ( V_278 . V_261 . V_163 . V_161 , V_78 -> V_338 ,
sizeof( V_78 -> V_338 ) ) ;
V_279 = F_55 ( V_202 ) ;
if ( ! V_279 )
return - V_63 ;
V_71 = F_63 ( V_202 , V_279 , & V_278 , 0 ) ;
F_56 ( V_202 , V_279 ) ;
return V_71 ;
}
static int
F_106 ( struct V_276 * V_206 , struct V_333 * V_78 )
{
return F_103 ( V_206 , V_78 , true ) ;
}
static int
F_107 ( struct V_276 * V_206 , struct V_331 * V_130 )
{
return F_100 ( V_206 , V_130 , true ) ;
}
static int F_108 ( T_2 V_321 , T_2 * V_124 )
{
switch ( V_321 ) {
case V_339 :
* V_124 = V_126 ;
break;
case V_340 :
* V_124 = V_127 ;
break;
case V_341 :
* V_124 = V_128 ;
break;
case V_342 :
* V_124 = V_125 ;
break;
default:
return - V_63 ;
}
return 0 ;
}
static int F_109 ( struct V_276 * V_206 , struct V_319 * V_76 )
{
struct V_21 * V_202 = F_72 ( V_206 ) ;
struct V_162 * V_273 ;
struct V_113 * V_60 ;
T_2 V_41 = 0 ;
T_2 V_124 ;
int V_27 ;
F_12 ( V_202 , V_28 , L_54 ,
V_76 -> V_321 , V_76 -> V_323 ) ;
if ( F_108 ( V_76 -> V_321 , & V_124 ) ) {
F_70 ( V_206 , L_55 ,
V_76 -> V_321 ) ;
return - V_63 ;
}
V_273 = F_68 ( V_202 , V_190 ) ;
if ( ! V_273 )
return - V_63 ;
if ( ! V_273 -> V_73 . V_11 ) {
F_70 ( V_202 , L_53 ) ;
F_50 ( V_273 ) ;
return - V_63 ;
}
for ( V_27 = 0 ; V_27 < V_307 ; V_27 ++ ) {
V_60 = & V_273 -> V_73 . V_163 . V_123 [ V_27 ] ;
if ( ( V_60 -> V_124 == V_124 ) &&
( V_60 -> V_10 == V_76 -> V_323 ) ) {
V_41 = V_60 -> V_41 ;
break;
}
}
if ( V_27 == V_307 ) {
F_17 ( V_206 , L_43 , V_76 -> V_321 ,
V_76 -> V_323 ) ;
F_50 ( V_273 ) ;
return - V_63 ;
}
V_76 -> V_35 = F_19 ( V_41 ) - 1 ;
F_50 ( V_273 ) ;
return 0 ;
}
static int F_110 ( struct V_276 * V_206 , struct V_319 * V_76 )
{
struct V_21 * V_202 = F_72 ( V_206 ) ;
struct V_162 * V_273 ;
struct V_260 V_278 ;
struct V_113 * V_60 ;
struct V_87 * V_279 ;
T_2 V_124 ;
int V_71 , V_27 ;
F_12 ( V_202 , V_28 , L_56 ,
V_76 -> V_321 , V_76 -> V_323 , V_76 -> V_35 ) ;
if ( V_76 -> V_35 < 0 || V_76 -> V_35 >= V_156 ) {
F_70 ( V_202 , L_29 , V_76 -> V_35 ) ;
return - V_63 ;
}
if ( F_108 ( V_76 -> V_321 , & V_124 ) ) {
F_70 ( V_206 , L_55 ,
V_76 -> V_321 ) ;
return - V_63 ;
}
V_273 = F_68 ( V_202 , V_190 ) ;
if ( ! V_273 )
return - V_63 ;
if ( ! V_273 -> V_73 . V_11 ) {
F_70 ( V_202 , L_53 ) ;
F_50 ( V_273 ) ;
return - V_63 ;
}
F_50 ( V_273 ) ;
memset ( & V_278 , 0 , sizeof( V_278 ) ) ;
V_71 = F_67 ( V_202 , & V_278 ) ;
if ( V_71 )
return - V_63 ;
for ( V_27 = 0 ; V_27 < V_307 ; V_27 ++ ) {
V_60 = & V_278 . V_261 . V_163 . V_123 [ V_27 ] ;
if ( ( V_60 -> V_124 == V_124 ) &&
( V_60 -> V_10 == V_76 -> V_323 ) )
break;
if ( ! V_60 -> V_10 ) {
V_278 . V_261 . V_163 . V_121 ++ ;
break;
}
}
if ( V_27 == V_307 ) {
F_17 ( V_206 , L_44 ) ;
return - V_234 ;
}
V_278 . V_263 |= V_266 ;
V_278 . V_261 . V_163 . V_123 [ V_27 ] . V_124 = V_124 ;
V_278 . V_261 . V_163 . V_123 [ V_27 ] . V_10 = V_76 -> V_323 ;
V_278 . V_261 . V_163 . V_123 [ V_27 ] . V_41 = F_58 ( V_76 -> V_35 ) ;
V_279 = F_55 ( V_202 ) ;
if ( ! V_279 )
return - V_234 ;
V_71 = F_63 ( V_202 , V_279 , & V_278 , 0 ) ;
F_56 ( V_202 , V_279 ) ;
return V_71 ;
}
