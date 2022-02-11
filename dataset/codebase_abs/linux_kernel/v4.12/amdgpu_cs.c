int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 ,
struct V_6 * * V_7 )
{
if ( V_4 != 0 ) {
F_2 ( L_1 , V_4 ) ;
return - V_8 ;
}
switch ( V_3 ) {
default:
F_2 ( L_2 , V_3 ) ;
return - V_8 ;
case V_9 :
if ( V_5 < V_2 -> V_10 . V_11 ) {
* V_7 = & V_2 -> V_10 . V_12 [ V_5 ] ;
} else {
F_2 ( L_3 ,
V_2 -> V_10 . V_11 ) ;
return - V_8 ;
}
break;
case V_13 :
if ( V_5 < V_2 -> V_10 . V_14 ) {
* V_7 = & V_2 -> V_10 . V_15 [ V_5 ] ;
} else {
F_2 ( L_4 ,
V_2 -> V_10 . V_14 ) ;
return - V_8 ;
}
break;
case V_16 :
if ( V_5 < V_2 -> V_17 . V_18 ) {
* V_7 = & V_2 -> V_17 . V_19 [ V_5 ] . V_5 ;
} else {
F_2 ( L_5 ,
V_2 -> V_17 . V_18 ) ;
return - V_8 ;
}
break;
case V_20 :
* V_7 = & V_2 -> V_21 . V_5 ;
break;
case V_22 :
if ( V_5 < V_2 -> V_23 . V_24 ) {
* V_7 = & V_2 -> V_23 . V_5 [ V_5 ] ;
} else {
F_2 ( L_6 , V_2 -> V_23 . V_24 ) ;
return - V_8 ;
}
break;
case V_25 :
if ( V_5 < V_2 -> V_21 . V_26 ) {
* V_7 = & V_2 -> V_21 . V_27 [ V_5 ] ;
} else {
F_2 ( L_7 ,
V_2 -> V_21 . V_26 ) ;
return - V_8 ;
}
break;
}
if ( ! ( * V_7 && ( * V_7 ) -> V_2 ) ) {
F_2 ( L_8 ,
V_5 , V_3 ) ;
return - V_8 ;
}
return 0 ;
}
static int F_3 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
T_2 * V_32 )
{
struct V_33 * V_34 ;
unsigned long V_35 ;
V_34 = F_4 ( V_29 -> V_36 , V_31 -> V_37 ) ;
if ( V_34 == NULL )
return - V_8 ;
V_29 -> V_38 . V_39 = F_5 ( F_6 ( V_34 ) ) ;
V_29 -> V_38 . V_40 = 0 ;
V_29 -> V_38 . V_41 . V_42 = & V_29 -> V_38 . V_39 -> V_43 ;
V_29 -> V_38 . V_41 . V_44 = true ;
V_29 -> V_38 . V_45 = NULL ;
V_35 = F_7 ( V_29 -> V_38 . V_39 ) ;
if ( V_35 != V_46 || ( V_31 -> V_32 + 8 ) > V_35 )
return - V_8 ;
* V_32 = V_31 -> V_32 ;
F_8 ( V_34 ) ;
if ( F_9 ( V_29 -> V_38 . V_39 -> V_43 . V_47 ) ) {
F_10 ( & V_29 -> V_38 . V_39 ) ;
return - V_8 ;
}
return 0 ;
}
int F_11 ( struct V_28 * V_29 , void * V_31 )
{
struct V_48 * V_49 = V_29 -> V_36 -> V_50 ;
struct V_51 * V_52 = & V_49 -> V_52 ;
union V_53 * V_54 = V_31 ;
T_3 * V_55 ;
T_3 * V_56 ;
unsigned V_35 , V_57 = 0 ;
T_2 V_58 = 0 ;
int V_59 ;
int V_60 ;
if ( V_54 -> V_61 . V_62 == 0 )
return 0 ;
V_56 = F_12 ( V_54 -> V_61 . V_62 , sizeof( T_3 ) , V_63 ) ;
if ( ! V_56 )
return - V_64 ;
V_29 -> V_65 = F_13 ( V_49 , V_54 -> V_61 . V_66 ) ;
if ( ! V_29 -> V_65 ) {
V_60 = - V_8 ;
goto V_67;
}
V_55 = ( T_3 V_68 * ) ( V_69 ) ( V_54 -> V_61 . V_70 ) ;
if ( F_14 ( V_56 , V_55 ,
sizeof( T_3 ) * V_54 -> V_61 . V_62 ) ) {
V_60 = - V_71 ;
goto V_72;
}
V_29 -> V_73 = V_54 -> V_61 . V_62 ;
V_29 -> V_70 = F_12 ( V_29 -> V_73 , sizeof( struct V_74 ) ,
V_63 ) ;
if ( ! V_29 -> V_70 ) {
V_60 = - V_64 ;
goto V_72;
}
for ( V_59 = 0 ; V_59 < V_29 -> V_73 ; V_59 ++ ) {
struct V_75 V_68 * * V_76 = NULL ;
struct V_75 V_77 ;
T_2 V_68 * V_78 ;
V_76 = ( void V_68 * ) ( V_69 ) V_56 [ V_59 ] ;
if ( F_14 ( & V_77 , V_76 ,
sizeof( struct V_75 ) ) ) {
V_60 = - V_71 ;
V_59 -- ;
goto V_79;
}
V_29 -> V_70 [ V_59 ] . V_80 = V_77 . V_80 ;
V_29 -> V_70 [ V_59 ] . V_81 = V_77 . V_81 ;
V_35 = V_29 -> V_70 [ V_59 ] . V_81 ;
V_78 = ( void V_68 * ) ( V_69 ) V_77 . V_82 ;
V_29 -> V_70 [ V_59 ] . V_83 = F_15 ( V_35 , sizeof( T_2 ) ) ;
if ( V_29 -> V_70 [ V_59 ] . V_83 == NULL ) {
V_60 = - V_64 ;
V_59 -- ;
goto V_79;
}
V_35 *= sizeof( T_2 ) ;
if ( F_14 ( V_29 -> V_70 [ V_59 ] . V_83 , V_78 , V_35 ) ) {
V_60 = - V_71 ;
goto V_79;
}
switch ( V_29 -> V_70 [ V_59 ] . V_80 ) {
case V_84 :
++ V_57 ;
break;
case V_85 :
V_35 = sizeof( struct V_30 ) ;
if ( V_29 -> V_70 [ V_59 ] . V_81 * sizeof( T_2 ) < V_35 ) {
V_60 = - V_8 ;
goto V_79;
}
V_60 = F_3 ( V_29 , V_29 -> V_70 [ V_59 ] . V_83 ,
& V_58 ) ;
if ( V_60 )
goto V_79;
break;
case V_86 :
break;
default:
V_60 = - V_8 ;
goto V_79;
}
}
V_60 = F_16 ( V_29 -> V_2 , V_57 , & V_29 -> V_87 , V_52 ) ;
if ( V_60 )
goto V_88;
if ( V_29 -> V_38 . V_39 )
V_29 -> V_87 -> V_89 = V_58 ;
F_17 ( V_56 ) ;
return 0 ;
V_88:
V_59 = V_29 -> V_73 - 1 ;
V_79:
for (; V_59 >= 0 ; V_59 -- )
F_18 ( V_29 -> V_70 [ V_59 ] . V_83 ) ;
F_17 ( V_29 -> V_70 ) ;
V_29 -> V_70 = NULL ;
V_29 -> V_73 = 0 ;
V_72:
F_19 ( V_29 -> V_65 ) ;
V_67:
F_17 ( V_56 ) ;
return V_60 ;
}
static T_4 F_20 ( struct V_1 * V_2 , T_5 V_90 )
{
if ( V_90 <= 0 || ! V_2 -> V_91 . V_92 )
return 0 ;
return V_90 << V_2 -> V_91 . V_92 ;
}
static T_5 F_21 ( struct V_1 * V_2 , T_4 V_93 )
{
if ( ! V_2 -> V_91 . V_92 )
return 0 ;
return V_93 >> V_2 -> V_91 . V_92 ;
}
static T_4 F_22 ( struct V_1 * V_2 )
{
T_5 V_94 , V_95 ;
T_4 V_96 ;
T_4 V_97 , V_98 , V_99 ;
const T_5 V_100 = 200000 ;
if ( ! V_2 -> V_91 . V_92 )
return 0 ;
V_98 = V_2 -> V_101 . V_102 - V_2 -> V_103 ;
V_99 = F_23 ( & V_2 -> V_104 ) ;
V_97 = V_99 >= V_98 ? 0 : V_98 - V_99 ;
F_24 ( & V_2 -> V_91 . V_105 ) ;
V_94 = F_25 ( F_26 () ) ;
V_95 = V_94 - V_2 -> V_91 . V_106 ;
V_2 -> V_91 . V_106 = V_94 ;
V_2 -> V_91 . V_107 = F_27 ( V_2 -> V_91 . V_107 + V_95 ,
V_100 ) ;
if ( V_97 >= 128 * 1024 * 1024 || V_97 >= V_98 / 8 ) {
T_5 V_108 ;
if ( ! ( V_2 -> V_109 & V_110 ) )
V_108 = F_21 ( V_2 , V_97 / 4 ) ;
else
V_108 = 0 ;
V_2 -> V_91 . V_107 = F_28 ( V_108 , V_2 -> V_91 . V_107 ) ;
}
V_96 = F_20 ( V_2 , V_2 -> V_91 . V_107 ) ;
F_29 ( & V_2 -> V_91 . V_105 ) ;
return V_96 ;
}
void F_30 ( struct V_1 * V_2 , T_4 V_111 )
{
F_24 ( & V_2 -> V_91 . V_105 ) ;
V_2 -> V_91 . V_107 -= F_21 ( V_2 , V_111 ) ;
F_29 ( & V_2 -> V_91 . V_105 ) ;
}
static int F_31 ( struct V_28 * V_29 ,
struct V_112 * V_42 )
{
struct V_1 * V_2 = F_32 ( V_42 -> V_43 . V_113 ) ;
T_4 V_114 ;
T_2 V_115 ;
int V_116 ;
if ( V_42 -> V_117 )
return 0 ;
if ( V_29 -> V_118 < V_29 -> V_119 )
V_115 = V_42 -> V_120 ;
else
V_115 = V_42 -> V_121 ;
V_122:
F_33 ( V_42 , V_115 ) ;
V_114 = F_23 ( & V_2 -> V_123 ) ;
V_116 = F_34 ( & V_42 -> V_43 , & V_42 -> V_124 , true , false ) ;
V_29 -> V_118 += F_23 ( & V_2 -> V_123 ) -
V_114 ;
if ( F_35 ( V_116 == - V_64 ) && V_115 != V_42 -> V_121 ) {
V_115 = V_42 -> V_121 ;
goto V_122;
}
return V_116 ;
}
static bool F_36 ( struct V_28 * V_29 ,
struct V_112 * V_125 )
{
T_2 V_115 = V_125 -> V_121 ;
int V_116 ;
if ( ! V_29 -> V_126 )
return false ;
for (; & V_29 -> V_126 -> V_41 . V_127 != & V_29 -> V_125 ;
V_29 -> V_126 = F_37 ( V_29 -> V_126 , V_41 . V_127 ) ) {
struct V_128 * V_129 = V_29 -> V_126 ;
struct V_112 * V_42 = V_129 -> V_39 ;
struct V_1 * V_2 = F_32 ( V_42 -> V_43 . V_113 ) ;
T_4 V_114 ;
T_2 V_130 ;
if ( V_129 -> V_39 == V_125 )
break;
V_130 = F_38 ( V_42 -> V_43 . V_131 . V_132 ) ;
if ( ! ( V_130 & V_115 ) )
continue;
V_130 = V_42 -> V_121 & ~ V_115 ;
if ( ! V_130 )
continue;
F_33 ( V_42 , V_130 ) ;
V_114 = F_23 ( & V_2 -> V_123 ) ;
V_116 = F_34 ( & V_42 -> V_43 , & V_42 -> V_124 , true , false ) ;
V_29 -> V_118 += F_23 ( & V_2 -> V_123 ) -
V_114 ;
if ( F_35 ( V_116 ) )
break;
V_29 -> V_126 = F_37 ( V_29 -> V_126 , V_41 . V_127 ) ;
F_39 ( & V_129 -> V_41 . V_127 , & V_29 -> V_125 ) ;
return true ;
}
return false ;
}
static int F_40 ( void * V_133 , struct V_112 * V_42 )
{
struct V_28 * V_29 = V_133 ;
int V_116 ;
do {
V_116 = F_31 ( V_29 , V_42 ) ;
} while ( V_116 == - V_64 && F_36 ( V_29 , V_42 ) );
if ( V_116 )
return V_116 ;
if ( V_42 -> V_134 )
V_116 = F_31 ( V_29 , V_42 -> V_134 ) ;
return V_116 ;
}
static int F_41 ( struct V_28 * V_29 ,
struct V_135 * V_125 )
{
struct V_128 * V_136 ;
int V_116 ;
F_42 (lobj, validated, tv.head) {
struct V_112 * V_42 = V_136 -> V_39 ;
bool V_137 = false ;
struct V_138 * V_139 ;
V_139 = F_9 ( V_42 -> V_43 . V_47 ) ;
if ( V_139 && V_139 != V_140 -> V_141 )
return - V_142 ;
if ( V_136 -> V_45 && V_42 -> V_43 . V_47 -> V_143 != V_144 ) {
T_6 V_35 = sizeof( struct V_145 * ) ;
V_35 *= V_42 -> V_43 . V_47 -> V_146 ;
memcpy ( V_42 -> V_43 . V_47 -> V_147 , V_136 -> V_45 , V_35 ) ;
V_137 = true ;
}
if ( V_29 -> V_126 == V_136 )
V_29 -> V_126 = NULL ;
V_116 = F_40 ( V_29 , V_42 ) ;
if ( V_116 )
return V_116 ;
if ( V_137 ) {
F_18 ( V_136 -> V_45 ) ;
V_136 -> V_45 = NULL ;
}
}
return 0 ;
}
static int F_43 ( struct V_28 * V_29 ,
union V_53 * V_54 )
{
struct V_48 * V_49 = V_29 -> V_36 -> V_50 ;
struct V_128 * V_148 ;
struct V_135 V_149 ;
bool V_150 = false ;
unsigned V_59 , V_151 = 10 ;
int V_116 ;
F_44 ( & V_29 -> V_125 ) ;
V_29 -> V_152 = F_45 ( V_49 , V_54 -> V_61 . V_153 ) ;
if ( V_29 -> V_152 ) {
V_150 = V_29 -> V_152 -> V_154 !=
V_29 -> V_152 -> V_155 ;
F_46 ( V_29 -> V_152 , & V_29 -> V_125 ) ;
}
F_44 ( & V_149 ) ;
F_47 ( & V_49 -> V_52 , & V_29 -> V_125 , & V_29 -> V_156 ) ;
if ( V_29 -> V_38 . V_39 )
F_48 ( & V_29 -> V_38 . V_41 . V_127 , & V_29 -> V_125 ) ;
if ( V_150 )
F_49 ( & V_140 -> V_141 -> V_157 ) ;
while ( 1 ) {
struct V_135 V_158 ;
unsigned V_59 ;
V_116 = F_50 ( & V_29 -> V_159 , & V_29 -> V_125 , true ,
& V_149 ) ;
if ( F_35 ( V_116 != 0 ) ) {
if ( V_116 != - V_160 )
F_2 ( L_9 ) ;
goto V_161;
}
if ( ! V_29 -> V_152 )
break;
F_44 ( & V_158 ) ;
for ( V_59 = V_29 -> V_152 -> V_154 ;
V_59 < V_29 -> V_152 -> V_155 ; ++ V_59 ) {
V_148 = & V_29 -> V_152 -> V_162 [ V_59 ] ;
if ( F_51 ( V_148 -> V_39 -> V_43 . V_47 ,
& V_148 -> V_163 ) && V_148 -> V_45 ) {
F_52 ( V_148 -> V_45 ,
V_148 -> V_39 -> V_43 . V_47 -> V_146 ,
false ) ;
F_18 ( V_148 -> V_45 ) ;
V_148 -> V_45 = NULL ;
}
if ( V_148 -> V_39 -> V_43 . V_47 -> V_143 != V_144 &&
! V_148 -> V_45 ) {
F_53 ( & V_148 -> V_41 . V_127 ) ;
F_48 ( & V_148 -> V_41 . V_127 , & V_158 ) ;
F_54 ( V_148 -> V_39 ) ;
}
}
if ( F_55 ( & V_158 ) )
break;
F_56 ( & V_29 -> V_159 , & V_29 -> V_125 ) ;
if ( ! -- V_151 ) {
V_116 = - V_164 ;
F_2 ( L_10 , V_165 ) ;
goto V_161;
}
F_42 (e, &need_pages, tv.head) {
struct V_166 * V_47 = V_148 -> V_39 -> V_43 . V_47 ;
V_148 -> V_45 = F_57 ( V_47 -> V_146 ,
sizeof( struct V_145 * ) ) ;
if ( ! V_148 -> V_45 ) {
V_116 = - V_64 ;
F_2 ( L_11 , V_165 ) ;
goto V_161;
}
V_116 = F_58 ( V_47 , V_148 -> V_45 ) ;
if ( V_116 ) {
F_2 ( L_12 ) ;
F_18 ( V_148 -> V_45 ) ;
V_148 -> V_45 = NULL ;
goto V_161;
}
}
F_59 ( & V_158 , & V_29 -> V_125 ) ;
}
V_29 -> V_119 = F_22 ( V_29 -> V_2 ) ;
V_29 -> V_118 = 0 ;
V_29 -> V_126 = F_60 ( & V_29 -> V_125 ,
struct V_128 ,
V_41 . V_127 ) ;
V_116 = F_61 ( V_29 -> V_2 , & V_49 -> V_52 ,
F_40 , V_29 ) ;
if ( V_116 ) {
F_2 ( L_13 ) ;
goto V_167;
}
V_116 = F_41 ( V_29 , & V_149 ) ;
if ( V_116 ) {
F_2 ( L_14 ) ;
goto V_167;
}
V_116 = F_41 ( V_29 , & V_29 -> V_125 ) ;
if ( V_116 ) {
F_2 ( L_15 ) ;
goto V_167;
}
F_30 ( V_29 -> V_2 , V_29 -> V_118 ) ;
V_49 -> V_52 . V_168 =
F_23 ( & V_29 -> V_2 -> V_169 ) ;
if ( V_29 -> V_152 ) {
struct V_112 * V_170 = V_29 -> V_152 -> V_171 ;
struct V_112 * V_172 = V_29 -> V_152 -> V_173 ;
struct V_112 * V_174 = V_29 -> V_152 -> V_175 ;
struct V_51 * V_52 = & V_49 -> V_52 ;
unsigned V_59 ;
for ( V_59 = 0 ; V_59 < V_29 -> V_152 -> V_155 ; V_59 ++ ) {
struct V_112 * V_42 = V_29 -> V_152 -> V_162 [ V_59 ] . V_39 ;
V_29 -> V_152 -> V_162 [ V_59 ] . V_176 = F_62 ( V_52 , V_42 ) ;
}
if ( V_170 ) {
V_29 -> V_87 -> V_177 = F_63 ( V_170 ) ;
V_29 -> V_87 -> V_178 = F_7 ( V_170 ) ;
}
if ( V_172 ) {
V_29 -> V_87 -> V_179 = F_63 ( V_172 ) ;
V_29 -> V_87 -> V_180 = F_7 ( V_172 ) ;
}
if ( V_174 ) {
V_29 -> V_87 -> V_181 = F_63 ( V_174 ) ;
V_29 -> V_87 -> V_182 = F_7 ( V_174 ) ;
}
}
if ( ! V_116 && V_29 -> V_38 . V_39 ) {
struct V_112 * V_183 = V_29 -> V_38 . V_39 ;
V_116 = F_64 ( & V_183 -> V_43 , & V_183 -> V_43 . V_131 ) ;
V_29 -> V_87 -> V_89 += F_63 ( V_183 ) ;
}
V_167:
if ( V_116 ) {
F_65 ( V_29 -> V_2 , & V_49 -> V_52 ) ;
F_56 ( & V_29 -> V_159 , & V_29 -> V_125 ) ;
}
V_161:
if ( V_150 )
F_66 ( & V_140 -> V_141 -> V_157 ) ;
if ( V_29 -> V_152 ) {
for ( V_59 = V_29 -> V_152 -> V_154 ;
V_59 < V_29 -> V_152 -> V_155 ; ++ V_59 ) {
V_148 = & V_29 -> V_152 -> V_162 [ V_59 ] ;
if ( ! V_148 -> V_45 )
continue;
F_52 ( V_148 -> V_45 ,
V_148 -> V_39 -> V_43 . V_47 -> V_146 ,
false ) ;
F_18 ( V_148 -> V_45 ) ;
}
}
return V_116 ;
}
static int F_67 ( struct V_28 * V_29 )
{
struct V_128 * V_148 ;
int V_116 ;
F_42 (e, &p->validated, tv.head) {
struct V_184 * V_185 = V_148 -> V_39 -> V_43 . V_185 ;
V_116 = F_68 ( V_29 -> V_2 , & V_29 -> V_87 -> V_186 , V_185 , V_29 -> V_36 ) ;
if ( V_116 )
return V_116 ;
}
return 0 ;
}
static void F_69 ( struct V_28 * V_187 , int error , bool V_188 )
{
struct V_48 * V_49 = V_187 -> V_36 -> V_50 ;
unsigned V_59 ;
if ( ! error ) {
F_65 ( V_187 -> V_2 , & V_49 -> V_52 ) ;
F_70 ( & V_187 -> V_159 ,
& V_187 -> V_125 ,
V_187 -> V_189 ) ;
} else if ( V_188 ) {
F_56 ( & V_187 -> V_159 ,
& V_187 -> V_125 ) ;
}
F_71 ( V_187 -> V_189 ) ;
if ( V_187 -> V_65 )
F_19 ( V_187 -> V_65 ) ;
if ( V_187 -> V_152 )
F_72 ( V_187 -> V_152 ) ;
for ( V_59 = 0 ; V_59 < V_187 -> V_73 ; V_59 ++ )
F_18 ( V_187 -> V_70 [ V_59 ] . V_83 ) ;
F_17 ( V_187 -> V_70 ) ;
if ( V_187 -> V_87 )
F_73 ( V_187 -> V_87 ) ;
F_10 ( & V_187 -> V_38 . V_39 ) ;
}
static int F_74 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_2 ;
struct V_48 * V_49 = V_29 -> V_36 -> V_50 ;
struct V_51 * V_52 = & V_49 -> V_52 ;
struct V_190 * V_176 ;
struct V_112 * V_42 ;
int V_59 , V_116 ;
V_116 = F_75 ( V_2 , V_52 ) ;
if ( V_116 )
return V_116 ;
V_116 = F_76 ( V_2 , & V_29 -> V_87 -> V_186 , V_52 -> V_191 ) ;
if ( V_116 )
return V_116 ;
V_116 = F_77 ( V_2 , V_52 , NULL ) ;
if ( V_116 )
return V_116 ;
V_116 = F_78 ( V_2 , V_49 -> V_192 , false ) ;
if ( V_116 )
return V_116 ;
V_116 = F_76 ( V_2 , & V_29 -> V_87 -> V_186 ,
V_49 -> V_192 -> V_193 ) ;
if ( V_116 )
return V_116 ;
if ( F_79 ( V_2 ) ) {
struct V_194 * V_195 ;
V_176 = V_52 -> V_196 ;
F_80 ( ! V_176 ) ;
V_116 = F_78 ( V_2 , V_176 , false ) ;
if ( V_116 )
return V_116 ;
V_195 = V_176 -> V_193 ;
V_116 = F_76 ( V_2 , & V_29 -> V_87 -> V_186 , V_195 ) ;
if ( V_116 )
return V_116 ;
}
if ( V_29 -> V_152 ) {
for ( V_59 = 0 ; V_59 < V_29 -> V_152 -> V_155 ; V_59 ++ ) {
struct V_194 * V_195 ;
V_42 = V_29 -> V_152 -> V_162 [ V_59 ] . V_39 ;
if ( ! V_42 )
continue;
V_176 = V_29 -> V_152 -> V_162 [ V_59 ] . V_176 ;
if ( V_176 == NULL )
continue;
V_116 = F_78 ( V_2 , V_176 , false ) ;
if ( V_116 )
return V_116 ;
V_195 = V_176 -> V_193 ;
V_116 = F_76 ( V_2 , & V_29 -> V_87 -> V_186 , V_195 ) ;
if ( V_116 )
return V_116 ;
}
}
V_116 = F_81 ( V_2 , V_52 , & V_29 -> V_87 -> V_186 ) ;
if ( V_197 && V_29 -> V_152 ) {
for ( V_59 = 0 ; V_59 < V_29 -> V_152 -> V_155 ; V_59 ++ ) {
V_42 = V_29 -> V_152 -> V_162 [ V_59 ] . V_39 ;
if ( ! V_42 )
continue;
F_82 ( V_2 , V_42 ) ;
}
}
return V_116 ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_48 * V_49 = V_29 -> V_36 -> V_50 ;
struct V_51 * V_52 = & V_49 -> V_52 ;
struct V_6 * V_5 = V_29 -> V_87 -> V_5 ;
int V_59 , V_116 ;
if ( V_5 -> V_198 -> V_199 ) {
for ( V_59 = 0 ; V_59 < V_29 -> V_87 -> V_57 ; V_59 ++ ) {
V_116 = F_84 ( V_5 , V_29 , V_59 ) ;
if ( V_116 )
return V_116 ;
}
}
if ( V_29 -> V_87 -> V_52 ) {
V_29 -> V_87 -> V_200 = F_63 ( V_52 -> V_201 . V_42 ) ;
V_116 = F_74 ( V_29 ) ;
if ( V_116 )
return V_116 ;
}
return F_67 ( V_29 ) ;
}
static int F_85 ( struct V_1 * V_2 ,
struct V_28 * V_187 )
{
struct V_48 * V_49 = V_187 -> V_36 -> V_50 ;
struct V_51 * V_52 = & V_49 -> V_52 ;
int V_59 , V_202 ;
int V_116 , V_203 = 0 , V_204 = 0 ;
for ( V_59 = 0 , V_202 = 0 ; V_59 < V_187 -> V_73 && V_202 < V_187 -> V_87 -> V_57 ; V_59 ++ ) {
struct V_74 * V_205 ;
struct V_206 * V_207 ;
struct V_208 * V_209 ;
struct V_6 * V_5 ;
V_205 = & V_187 -> V_70 [ V_59 ] ;
V_207 = & V_187 -> V_87 -> V_210 [ V_202 ] ;
V_209 = (struct V_208 * ) V_205 -> V_83 ;
if ( V_205 -> V_80 != V_84 )
continue;
if ( V_209 -> V_3 == V_9 && F_79 ( V_2 ) ) {
if ( V_209 -> V_109 & V_211 ) {
if ( V_209 -> V_109 & V_212 )
V_203 ++ ;
else
V_204 ++ ;
}
if ( V_203 > 1 || V_204 > 1 )
return - V_8 ;
}
V_116 = F_1 ( V_2 , V_209 -> V_3 ,
V_209 -> V_4 , V_209 -> V_5 ,
& V_5 ) ;
if ( V_116 )
return V_116 ;
if ( V_209 -> V_109 & V_213 ) {
V_187 -> V_87 -> V_214 |= V_215 ;
if ( ! V_187 -> V_65 -> V_216 ) {
V_187 -> V_87 -> V_214 |= V_217 ;
V_187 -> V_65 -> V_216 = true ;
}
}
if ( V_187 -> V_87 -> V_5 && V_187 -> V_87 -> V_5 != V_5 )
return - V_8 ;
V_187 -> V_87 -> V_5 = V_5 ;
if ( V_5 -> V_198 -> V_199 ) {
struct V_218 * V_219 ;
struct V_112 * V_220 = NULL ;
T_3 V_32 ;
T_7 * V_221 ;
V_219 = F_86 ( V_187 , V_209 -> va_start ,
& V_220 ) ;
if ( ! V_220 ) {
F_2 ( L_16 ) ;
return - V_8 ;
}
if ( ( V_209 -> va_start + V_209 -> V_222 ) >
( V_219 -> V_223 + 1 ) * V_224 ) {
F_2 ( L_17 ) ;
return - V_8 ;
}
V_116 = F_87 ( V_220 , ( void * * ) & V_221 ) ;
if ( V_116 ) {
return V_116 ;
}
V_32 = V_219 -> V_225 * V_224 ;
V_221 += V_209 -> va_start - V_32 ;
V_116 = F_88 ( V_2 , V_52 , V_209 -> V_222 , V_207 ) ;
if ( V_116 ) {
F_2 ( L_18 ) ;
return V_116 ;
}
memcpy ( V_207 -> V_226 , V_221 , V_209 -> V_222 ) ;
F_89 ( V_220 ) ;
} else {
V_116 = F_88 ( V_2 , V_52 , 0 , V_207 ) ;
if ( V_116 ) {
F_2 ( L_18 ) ;
return V_116 ;
}
}
V_207 -> V_227 = V_209 -> va_start ;
V_207 -> V_81 = V_209 -> V_222 / 4 ;
V_207 -> V_109 = V_209 -> V_109 ;
V_202 ++ ;
}
if ( V_187 -> V_87 -> V_89 && (
V_187 -> V_87 -> V_5 -> V_198 -> type == V_228 ||
V_187 -> V_87 -> V_5 -> V_198 -> type == V_229 ) )
return - V_8 ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_48 * V_49 = V_29 -> V_36 -> V_50 ;
int V_59 , V_202 , V_116 ;
for ( V_59 = 0 ; V_59 < V_29 -> V_73 ; ++ V_59 ) {
struct V_230 * V_231 ;
struct V_74 * V_205 ;
unsigned V_232 ;
V_205 = & V_29 -> V_70 [ V_59 ] ;
if ( V_205 -> V_80 != V_86 )
continue;
V_231 = (struct V_230 * ) V_205 -> V_83 ;
V_232 = V_205 -> V_81 * 4 /
sizeof( struct V_230 ) ;
for ( V_202 = 0 ; V_202 < V_232 ; ++ V_202 ) {
struct V_6 * V_5 ;
struct V_233 * V_65 ;
struct V_194 * V_189 ;
V_116 = F_1 ( V_2 , V_231 [ V_202 ] . V_3 ,
V_231 [ V_202 ] . V_4 ,
V_231 [ V_202 ] . V_5 , & V_5 ) ;
if ( V_116 )
return V_116 ;
V_65 = F_13 ( V_49 , V_231 [ V_202 ] . V_66 ) ;
if ( V_65 == NULL )
return - V_8 ;
V_189 = F_91 ( V_65 , V_5 ,
V_231 [ V_202 ] . V_37 ) ;
if ( F_92 ( V_189 ) ) {
V_116 = F_93 ( V_189 ) ;
F_19 ( V_65 ) ;
return V_116 ;
} else if ( V_189 ) {
V_116 = F_76 ( V_2 , & V_29 -> V_87 -> V_186 ,
V_189 ) ;
F_71 ( V_189 ) ;
F_19 ( V_65 ) ;
if ( V_116 )
return V_116 ;
}
}
}
return 0 ;
}
static int F_94 ( struct V_28 * V_29 ,
union V_53 * V_54 )
{
struct V_6 * V_5 = V_29 -> V_87 -> V_5 ;
struct V_234 * V_235 = & V_29 -> V_65 -> V_236 [ V_5 -> V_237 ] . V_235 ;
struct V_238 * V_87 ;
int V_116 ;
V_87 = V_29 -> V_87 ;
V_29 -> V_87 = NULL ;
V_116 = F_95 ( & V_87 -> V_239 , & V_5 -> V_240 , V_235 , V_29 -> V_36 ) ;
if ( V_116 ) {
F_73 ( V_87 ) ;
return V_116 ;
}
V_87 -> V_241 = V_29 -> V_36 ;
V_87 -> V_242 = V_235 -> V_243 ;
V_29 -> V_189 = F_96 ( & V_87 -> V_239 . V_244 -> V_245 ) ;
V_54 -> V_246 . V_37 = F_97 ( V_29 -> V_65 , V_5 , V_29 -> V_189 ) ;
V_87 -> V_247 = V_54 -> V_246 . V_37 ;
F_98 ( V_87 ) ;
F_69 ( V_29 , 0 , true ) ;
F_99 ( V_87 ) ;
F_100 ( & V_87 -> V_239 ) ;
return 0 ;
}
int F_101 ( struct V_248 * V_249 , void * V_31 , struct V_250 * V_36 )
{
struct V_1 * V_2 = V_249 -> V_251 ;
union V_53 * V_54 = V_31 ;
struct V_28 V_187 = {} ;
bool V_252 = false ;
int V_59 , V_116 ;
if ( ! V_2 -> V_253 )
return - V_254 ;
V_187 . V_2 = V_2 ;
V_187 . V_36 = V_36 ;
V_116 = F_11 ( & V_187 , V_31 ) ;
if ( V_116 ) {
F_2 ( L_19 ) ;
goto V_246;
}
V_116 = F_43 ( & V_187 , V_31 ) ;
if ( V_116 ) {
if ( V_116 == - V_64 )
F_2 ( L_20 ) ;
else if ( V_116 != - V_160 )
F_2 ( L_21 , V_116 ) ;
goto V_246;
}
V_252 = true ;
V_116 = F_85 ( V_2 , & V_187 ) ;
if ( V_116 )
goto V_246;
V_116 = F_90 ( V_2 , & V_187 ) ;
if ( V_116 ) {
F_2 ( L_22 , V_116 ) ;
goto V_246;
}
for ( V_59 = 0 ; V_59 < V_187 . V_87 -> V_57 ; V_59 ++ )
F_102 ( & V_187 , V_59 ) ;
V_116 = F_83 ( V_2 , & V_187 ) ;
if ( V_116 )
goto V_246;
V_116 = F_94 ( & V_187 , V_54 ) ;
if ( V_116 )
goto V_246;
return 0 ;
V_246:
F_69 ( & V_187 , V_116 , V_252 ) ;
return V_116 ;
}
int F_103 ( struct V_248 * V_249 , void * V_31 ,
struct V_250 * V_36 )
{
union V_255 * V_256 = V_31 ;
struct V_1 * V_2 = V_249 -> V_251 ;
unsigned long V_257 = F_104 ( V_256 -> V_61 . V_257 ) ;
struct V_6 * V_5 = NULL ;
struct V_233 * V_65 ;
struct V_194 * V_189 ;
long V_116 ;
V_116 = F_1 ( V_2 , V_256 -> V_61 . V_3 , V_256 -> V_61 . V_4 ,
V_256 -> V_61 . V_5 , & V_5 ) ;
if ( V_116 )
return V_116 ;
V_65 = F_13 ( V_36 -> V_50 , V_256 -> V_61 . V_66 ) ;
if ( V_65 == NULL )
return - V_8 ;
V_189 = F_91 ( V_65 , V_5 , V_256 -> V_61 . V_37 ) ;
if ( F_92 ( V_189 ) )
V_116 = F_93 ( V_189 ) ;
else if ( V_189 ) {
V_116 = F_105 ( V_189 , true , V_257 ) ;
F_71 ( V_189 ) ;
} else
V_116 = 1 ;
F_19 ( V_65 ) ;
if ( V_116 < 0 )
return V_116 ;
memset ( V_256 , 0 , sizeof( * V_256 ) ) ;
V_256 -> V_246 . V_258 = ( V_116 == 0 ) ;
return 0 ;
}
static struct V_194 * F_106 ( struct V_1 * V_2 ,
struct V_250 * V_36 ,
struct V_259 * V_260 )
{
struct V_6 * V_5 ;
struct V_233 * V_65 ;
struct V_194 * V_189 ;
int V_116 ;
V_116 = F_1 ( V_2 , V_260 -> V_3 , V_260 -> V_4 ,
V_260 -> V_5 , & V_5 ) ;
if ( V_116 )
return F_107 ( V_116 ) ;
V_65 = F_13 ( V_36 -> V_50 , V_260 -> V_66 ) ;
if ( V_65 == NULL )
return F_107 ( - V_8 ) ;
V_189 = F_91 ( V_65 , V_5 , V_260 -> V_261 ) ;
F_19 ( V_65 ) ;
return V_189 ;
}
static int F_108 ( struct V_1 * V_2 ,
struct V_250 * V_36 ,
union V_262 * V_256 ,
struct V_259 * V_263 )
{
T_2 V_264 = V_256 -> V_61 . V_264 ;
unsigned int V_59 ;
long V_116 = 1 ;
for ( V_59 = 0 ; V_59 < V_264 ; V_59 ++ ) {
struct V_194 * V_189 ;
unsigned long V_257 = F_104 ( V_256 -> V_61 . V_265 ) ;
V_189 = F_106 ( V_2 , V_36 , & V_263 [ V_59 ] ) ;
if ( F_92 ( V_189 ) )
return F_93 ( V_189 ) ;
else if ( ! V_189 )
continue;
V_116 = F_105 ( V_189 , true , V_257 ) ;
F_71 ( V_189 ) ;
if ( V_116 < 0 )
return V_116 ;
if ( V_116 == 0 )
break;
}
memset ( V_256 , 0 , sizeof( * V_256 ) ) ;
V_256 -> V_246 . V_258 = ( V_116 > 0 ) ;
return 0 ;
}
static int F_109 ( struct V_1 * V_2 ,
struct V_250 * V_36 ,
union V_262 * V_256 ,
struct V_259 * V_263 )
{
unsigned long V_257 = F_104 ( V_256 -> V_61 . V_265 ) ;
T_2 V_264 = V_256 -> V_61 . V_264 ;
T_2 V_266 = ~ 0 ;
struct V_194 * * V_162 ;
unsigned int V_59 ;
long V_116 ;
V_162 = F_110 ( V_264 , sizeof( struct V_194 * ) , V_63 ) ;
if ( V_162 == NULL )
return - V_64 ;
for ( V_59 = 0 ; V_59 < V_264 ; V_59 ++ ) {
struct V_194 * V_189 ;
V_189 = F_106 ( V_2 , V_36 , & V_263 [ V_59 ] ) ;
if ( F_92 ( V_189 ) ) {
V_116 = F_93 ( V_189 ) ;
goto V_267;
} else if ( V_189 ) {
V_162 [ V_59 ] = V_189 ;
} else {
V_116 = 1 ;
goto V_246;
}
}
V_116 = F_111 ( V_162 , V_264 , true , V_257 ,
& V_266 ) ;
if ( V_116 < 0 )
goto V_267;
V_246:
memset ( V_256 , 0 , sizeof( * V_256 ) ) ;
V_256 -> V_246 . V_258 = ( V_116 > 0 ) ;
V_256 -> V_246 . V_268 = V_266 ;
V_116 = 0 ;
V_267:
for ( V_59 = 0 ; V_59 < V_264 ; V_59 ++ )
F_71 ( V_162 [ V_59 ] ) ;
F_17 ( V_162 ) ;
return V_116 ;
}
int F_112 ( struct V_248 * V_249 , void * V_31 ,
struct V_250 * V_36 )
{
struct V_1 * V_2 = V_249 -> V_251 ;
union V_262 * V_256 = V_31 ;
T_2 V_264 = V_256 -> V_61 . V_264 ;
struct V_259 * V_269 ;
struct V_259 * V_263 ;
int V_116 ;
V_263 = F_12 ( V_264 , sizeof( struct V_259 ) ,
V_63 ) ;
if ( V_263 == NULL )
return - V_64 ;
V_269 = ( void V_68 * ) ( V_69 ) ( V_256 -> V_61 . V_263 ) ;
if ( F_14 ( V_263 , V_269 ,
sizeof( struct V_259 ) * V_264 ) ) {
V_116 = - V_71 ;
goto V_270;
}
if ( V_256 -> V_61 . V_271 )
V_116 = F_108 ( V_2 , V_36 , V_256 , V_263 ) ;
else
V_116 = F_109 ( V_2 , V_36 , V_256 , V_263 ) ;
V_270:
F_17 ( V_263 ) ;
return V_116 ;
}
struct V_218 *
F_86 ( struct V_28 * V_187 ,
T_3 V_272 , struct V_112 * * V_42 )
{
struct V_218 * V_273 ;
unsigned V_59 ;
if ( ! V_187 -> V_152 )
return NULL ;
V_272 /= V_224 ;
for ( V_59 = 0 ; V_59 < V_187 -> V_152 -> V_155 ; V_59 ++ ) {
struct V_128 * V_136 ;
V_136 = & V_187 -> V_152 -> V_162 [ V_59 ] ;
if ( ! V_136 -> V_176 )
continue;
F_42 (mapping, &lobj->bo_va->valids, list) {
if ( V_273 -> V_225 > V_272 ||
V_272 > V_273 -> V_223 )
continue;
* V_42 = V_136 -> V_176 -> V_42 ;
return V_273 ;
}
F_42 (mapping, &lobj->bo_va->invalids, list) {
if ( V_273 -> V_225 > V_272 ||
V_272 > V_273 -> V_223 )
continue;
* V_42 = V_136 -> V_176 -> V_42 ;
return V_273 ;
}
}
return NULL ;
}
int F_113 ( struct V_28 * V_187 )
{
unsigned V_59 ;
int V_116 ;
if ( ! V_187 -> V_152 )
return 0 ;
for ( V_59 = 0 ; V_59 < V_187 -> V_152 -> V_155 ; V_59 ++ ) {
struct V_112 * V_42 = V_187 -> V_152 -> V_162 [ V_59 ] . V_39 ;
V_116 = F_64 ( & V_42 -> V_43 , & V_42 -> V_43 . V_131 ) ;
if ( F_35 ( V_116 ) )
return V_116 ;
if ( V_42 -> V_109 & V_274 )
continue;
V_42 -> V_109 |= V_274 ;
F_33 ( V_42 , V_42 -> V_121 ) ;
V_116 = F_34 ( & V_42 -> V_43 , & V_42 -> V_124 , false , false ) ;
if ( F_35 ( V_116 ) )
return V_116 ;
}
return 0 ;
}
