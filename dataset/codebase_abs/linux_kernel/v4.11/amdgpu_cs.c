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
}
if ( ! ( * V_7 && ( * V_7 ) -> V_2 ) ) {
F_2 ( L_7 ,
V_5 , V_3 ) ;
return - V_8 ;
}
return 0 ;
}
static int F_3 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
T_2 * V_29 )
{
struct V_30 * V_31 ;
unsigned long V_32 ;
V_31 = F_4 ( V_26 -> V_33 , V_28 -> V_34 ) ;
if ( V_31 == NULL )
return - V_8 ;
V_26 -> V_35 . V_36 = F_5 ( F_6 ( V_31 ) ) ;
V_26 -> V_35 . V_37 = 0 ;
V_26 -> V_35 . V_38 . V_39 = & V_26 -> V_35 . V_36 -> V_40 ;
V_26 -> V_35 . V_38 . V_41 = true ;
V_26 -> V_35 . V_42 = NULL ;
V_32 = F_7 ( V_26 -> V_35 . V_36 ) ;
if ( V_32 != V_43 || ( V_28 -> V_29 + 8 ) > V_32 )
return - V_8 ;
* V_29 = V_28 -> V_29 ;
F_8 ( V_31 ) ;
if ( F_9 ( V_26 -> V_35 . V_36 -> V_40 . V_44 ) ) {
F_10 ( & V_26 -> V_35 . V_36 ) ;
return - V_8 ;
}
return 0 ;
}
int F_11 ( struct V_25 * V_26 , void * V_28 )
{
struct V_45 * V_46 = V_26 -> V_33 -> V_47 ;
struct V_48 * V_49 = & V_46 -> V_49 ;
union V_50 * V_51 = V_28 ;
T_3 * V_52 ;
T_3 * V_53 ;
unsigned V_32 , V_54 = 0 ;
T_2 V_55 = 0 ;
int V_56 ;
int V_57 ;
if ( V_51 -> V_58 . V_59 == 0 )
return 0 ;
V_53 = F_12 ( V_51 -> V_58 . V_59 , sizeof( T_3 ) , V_60 ) ;
if ( ! V_53 )
return - V_61 ;
V_26 -> V_62 = F_13 ( V_46 , V_51 -> V_58 . V_63 ) ;
if ( ! V_26 -> V_62 ) {
V_57 = - V_8 ;
goto V_64;
}
V_52 = ( T_3 V_65 * ) ( unsigned long ) ( V_51 -> V_58 . V_66 ) ;
if ( F_14 ( V_53 , V_52 ,
sizeof( T_3 ) * V_51 -> V_58 . V_59 ) ) {
V_57 = - V_67 ;
goto V_68;
}
V_26 -> V_69 = V_51 -> V_58 . V_59 ;
V_26 -> V_66 = F_12 ( V_26 -> V_69 , sizeof( struct V_70 ) ,
V_60 ) ;
if ( ! V_26 -> V_66 ) {
V_57 = - V_61 ;
goto V_68;
}
for ( V_56 = 0 ; V_56 < V_26 -> V_69 ; V_56 ++ ) {
struct V_71 V_65 * * V_72 = NULL ;
struct V_71 V_73 ;
T_2 V_65 * V_74 ;
V_72 = ( void V_65 * ) ( unsigned long ) V_53 [ V_56 ] ;
if ( F_14 ( & V_73 , V_72 ,
sizeof( struct V_71 ) ) ) {
V_57 = - V_67 ;
V_56 -- ;
goto V_75;
}
V_26 -> V_66 [ V_56 ] . V_76 = V_73 . V_76 ;
V_26 -> V_66 [ V_56 ] . V_77 = V_73 . V_77 ;
V_32 = V_26 -> V_66 [ V_56 ] . V_77 ;
V_74 = ( void V_65 * ) ( unsigned long ) V_73 . V_78 ;
V_26 -> V_66 [ V_56 ] . V_79 = F_15 ( V_32 , sizeof( T_2 ) ) ;
if ( V_26 -> V_66 [ V_56 ] . V_79 == NULL ) {
V_57 = - V_61 ;
V_56 -- ;
goto V_75;
}
V_32 *= sizeof( T_2 ) ;
if ( F_14 ( V_26 -> V_66 [ V_56 ] . V_79 , V_74 , V_32 ) ) {
V_57 = - V_67 ;
goto V_75;
}
switch ( V_26 -> V_66 [ V_56 ] . V_76 ) {
case V_80 :
++ V_54 ;
break;
case V_81 :
V_32 = sizeof( struct V_27 ) ;
if ( V_26 -> V_66 [ V_56 ] . V_77 * sizeof( T_2 ) < V_32 ) {
V_57 = - V_8 ;
goto V_75;
}
V_57 = F_3 ( V_26 , V_26 -> V_66 [ V_56 ] . V_79 ,
& V_55 ) ;
if ( V_57 )
goto V_75;
break;
case V_82 :
break;
default:
V_57 = - V_8 ;
goto V_75;
}
}
V_57 = F_16 ( V_26 -> V_2 , V_54 , & V_26 -> V_83 , V_49 ) ;
if ( V_57 )
goto V_84;
if ( V_26 -> V_35 . V_36 )
V_26 -> V_83 -> V_85 = V_55 ;
F_17 ( V_53 ) ;
return 0 ;
V_84:
V_56 = V_26 -> V_69 - 1 ;
V_75:
for (; V_56 >= 0 ; V_56 -- )
F_18 ( V_26 -> V_66 [ V_56 ] . V_79 ) ;
F_17 ( V_26 -> V_66 ) ;
V_26 -> V_66 = NULL ;
V_26 -> V_69 = 0 ;
V_68:
F_19 ( V_26 -> V_62 ) ;
V_64:
F_17 ( V_53 ) ;
return V_57 ;
}
static T_4 F_20 ( struct V_1 * V_2 , T_5 V_86 )
{
if ( V_86 <= 0 || ! V_2 -> V_87 . V_88 )
return 0 ;
return V_86 << V_2 -> V_87 . V_88 ;
}
static T_5 F_21 ( struct V_1 * V_2 , T_4 V_89 )
{
if ( ! V_2 -> V_87 . V_88 )
return 0 ;
return V_89 >> V_2 -> V_87 . V_88 ;
}
static T_4 F_22 ( struct V_1 * V_2 )
{
T_5 V_90 , V_91 ;
T_4 V_92 ;
T_4 V_93 , V_94 , V_95 ;
const T_5 V_96 = 200000 ;
if ( ! V_2 -> V_87 . V_88 )
return 0 ;
V_94 = V_2 -> V_97 . V_98 - V_2 -> V_99 ;
V_95 = F_23 ( & V_2 -> V_100 ) ;
V_93 = V_95 >= V_94 ? 0 : V_94 - V_95 ;
F_24 ( & V_2 -> V_87 . V_101 ) ;
V_90 = F_25 ( F_26 () ) ;
V_91 = V_90 - V_2 -> V_87 . V_102 ;
V_2 -> V_87 . V_102 = V_90 ;
V_2 -> V_87 . V_103 = F_27 ( V_2 -> V_87 . V_103 + V_91 ,
V_96 ) ;
if ( V_93 >= 128 * 1024 * 1024 || V_93 >= V_94 / 8 ) {
T_5 V_104 ;
if ( ! ( V_2 -> V_105 & V_106 ) )
V_104 = F_21 ( V_2 , V_93 / 4 ) ;
else
V_104 = 0 ;
V_2 -> V_87 . V_103 = F_28 ( V_104 , V_2 -> V_87 . V_103 ) ;
}
V_92 = F_20 ( V_2 , V_2 -> V_87 . V_103 ) ;
F_29 ( & V_2 -> V_87 . V_101 ) ;
return V_92 ;
}
void F_30 ( struct V_1 * V_2 , T_4 V_107 )
{
F_24 ( & V_2 -> V_87 . V_101 ) ;
V_2 -> V_87 . V_103 -= F_21 ( V_2 , V_107 ) ;
F_29 ( & V_2 -> V_87 . V_101 ) ;
}
static int F_31 ( struct V_25 * V_26 ,
struct V_108 * V_39 )
{
struct V_1 * V_2 = F_32 ( V_39 -> V_40 . V_109 ) ;
T_4 V_110 ;
T_2 V_111 ;
int V_112 ;
if ( V_39 -> V_113 )
return 0 ;
if ( V_26 -> V_114 < V_26 -> V_115 )
V_111 = V_39 -> V_116 ;
else
V_111 = V_39 -> V_117 ;
V_118:
F_33 ( V_39 , V_111 ) ;
V_110 = F_23 ( & V_2 -> V_119 ) ;
V_112 = F_34 ( & V_39 -> V_40 , & V_39 -> V_120 , true , false ) ;
V_26 -> V_114 += F_23 ( & V_2 -> V_119 ) -
V_110 ;
if ( F_35 ( V_112 == - V_61 ) && V_111 != V_39 -> V_117 ) {
V_111 = V_39 -> V_117 ;
goto V_118;
}
return V_112 ;
}
static bool F_36 ( struct V_25 * V_26 ,
struct V_108 * V_121 )
{
T_2 V_111 = V_121 -> V_117 ;
int V_112 ;
if ( ! V_26 -> V_122 )
return false ;
for (; & V_26 -> V_122 -> V_38 . V_123 != & V_26 -> V_121 ;
V_26 -> V_122 = F_37 ( V_26 -> V_122 , V_38 . V_123 ) ) {
struct V_124 * V_125 = V_26 -> V_122 ;
struct V_108 * V_39 = V_125 -> V_36 ;
struct V_1 * V_2 = F_32 ( V_39 -> V_40 . V_109 ) ;
T_4 V_110 ;
T_2 V_126 ;
if ( V_125 -> V_36 == V_121 )
break;
V_126 = F_38 ( V_39 -> V_40 . V_127 . V_128 ) ;
if ( ! ( V_126 & V_111 ) )
continue;
V_126 = V_39 -> V_117 & ~ V_111 ;
if ( ! V_126 )
continue;
F_33 ( V_39 , V_126 ) ;
V_110 = F_23 ( & V_2 -> V_119 ) ;
V_112 = F_34 ( & V_39 -> V_40 , & V_39 -> V_120 , true , false ) ;
V_26 -> V_114 += F_23 ( & V_2 -> V_119 ) -
V_110 ;
if ( F_35 ( V_112 ) )
break;
V_26 -> V_122 = F_37 ( V_26 -> V_122 , V_38 . V_123 ) ;
F_39 ( & V_125 -> V_38 . V_123 , & V_26 -> V_121 ) ;
return true ;
}
return false ;
}
static int F_40 ( void * V_129 , struct V_108 * V_39 )
{
struct V_25 * V_26 = V_129 ;
int V_112 ;
do {
V_112 = F_31 ( V_26 , V_39 ) ;
} while ( V_112 == - V_61 && F_36 ( V_26 , V_39 ) );
if ( V_112 )
return V_112 ;
if ( V_39 -> V_130 )
V_112 = F_31 ( V_26 , V_39 -> V_130 ) ;
return V_112 ;
}
static int F_41 ( struct V_25 * V_26 ,
struct V_131 * V_121 )
{
struct V_124 * V_132 ;
int V_112 ;
F_42 (lobj, validated, tv.head) {
struct V_108 * V_39 = V_132 -> V_36 ;
bool V_133 = false ;
struct V_134 * V_135 ;
V_135 = F_9 ( V_39 -> V_40 . V_44 ) ;
if ( V_135 && V_135 != V_136 -> V_137 )
return - V_138 ;
if ( V_132 -> V_42 && V_39 -> V_40 . V_44 -> V_139 != V_140 ) {
T_6 V_32 = sizeof( struct V_141 * ) ;
V_32 *= V_39 -> V_40 . V_44 -> V_142 ;
memcpy ( V_39 -> V_40 . V_44 -> V_143 , V_132 -> V_42 , V_32 ) ;
V_133 = true ;
}
if ( V_26 -> V_122 == V_132 )
V_26 -> V_122 = NULL ;
V_112 = F_40 ( V_26 , V_39 ) ;
if ( V_112 )
return V_112 ;
if ( V_133 ) {
F_18 ( V_132 -> V_42 ) ;
V_132 -> V_42 = NULL ;
}
}
return 0 ;
}
static int F_43 ( struct V_25 * V_26 ,
union V_50 * V_51 )
{
struct V_45 * V_46 = V_26 -> V_33 -> V_47 ;
struct V_124 * V_144 ;
struct V_131 V_145 ;
bool V_146 = false ;
unsigned V_56 , V_147 = 10 ;
int V_112 ;
F_44 ( & V_26 -> V_121 ) ;
V_26 -> V_148 = F_45 ( V_46 , V_51 -> V_58 . V_149 ) ;
if ( V_26 -> V_148 ) {
V_146 = V_26 -> V_148 -> V_150 !=
V_26 -> V_148 -> V_151 ;
F_46 ( V_26 -> V_148 , & V_26 -> V_121 ) ;
}
F_44 ( & V_145 ) ;
F_47 ( & V_46 -> V_49 , & V_26 -> V_121 , & V_26 -> V_152 ) ;
if ( V_26 -> V_35 . V_36 )
F_48 ( & V_26 -> V_35 . V_38 . V_123 , & V_26 -> V_121 ) ;
if ( V_146 )
F_49 ( & V_136 -> V_137 -> V_153 ) ;
while ( 1 ) {
struct V_131 V_154 ;
unsigned V_56 ;
V_112 = F_50 ( & V_26 -> V_155 , & V_26 -> V_121 , true ,
& V_145 ) ;
if ( F_35 ( V_112 != 0 ) ) {
if ( V_112 != - V_156 )
F_2 ( L_8 ) ;
goto V_157;
}
if ( ! V_26 -> V_148 )
break;
F_44 ( & V_154 ) ;
for ( V_56 = V_26 -> V_148 -> V_150 ;
V_56 < V_26 -> V_148 -> V_151 ; ++ V_56 ) {
V_144 = & V_26 -> V_148 -> V_158 [ V_56 ] ;
if ( F_51 ( V_144 -> V_36 -> V_40 . V_44 ,
& V_144 -> V_159 ) && V_144 -> V_42 ) {
F_52 ( V_144 -> V_42 ,
V_144 -> V_36 -> V_40 . V_44 -> V_142 ,
false ) ;
F_18 ( V_144 -> V_42 ) ;
V_144 -> V_42 = NULL ;
}
if ( V_144 -> V_36 -> V_40 . V_44 -> V_139 != V_140 &&
! V_144 -> V_42 ) {
F_53 ( & V_144 -> V_38 . V_123 ) ;
F_48 ( & V_144 -> V_38 . V_123 , & V_154 ) ;
F_54 ( V_144 -> V_36 ) ;
}
}
if ( F_55 ( & V_154 ) )
break;
F_56 ( & V_26 -> V_155 , & V_26 -> V_121 ) ;
if ( ! -- V_147 ) {
V_112 = - V_160 ;
F_2 ( L_9 , V_161 ) ;
goto V_157;
}
F_42 (e, &need_pages, tv.head) {
struct V_162 * V_44 = V_144 -> V_36 -> V_40 . V_44 ;
V_144 -> V_42 = F_57 ( V_44 -> V_142 ,
sizeof( struct V_141 * ) ) ;
if ( ! V_144 -> V_42 ) {
V_112 = - V_61 ;
F_2 ( L_10 , V_161 ) ;
goto V_157;
}
V_112 = F_58 ( V_44 , V_144 -> V_42 ) ;
if ( V_112 ) {
F_2 ( L_11 ) ;
F_18 ( V_144 -> V_42 ) ;
V_144 -> V_42 = NULL ;
goto V_157;
}
}
F_59 ( & V_154 , & V_26 -> V_121 ) ;
}
V_26 -> V_115 = F_22 ( V_26 -> V_2 ) ;
V_26 -> V_114 = 0 ;
V_26 -> V_122 = F_60 ( & V_26 -> V_121 ,
struct V_124 ,
V_38 . V_123 ) ;
V_112 = F_61 ( V_26 -> V_2 , & V_46 -> V_49 ,
F_40 , V_26 ) ;
if ( V_112 ) {
F_2 ( L_12 ) ;
goto V_163;
}
V_112 = F_41 ( V_26 , & V_145 ) ;
if ( V_112 ) {
F_2 ( L_13 ) ;
goto V_163;
}
V_112 = F_41 ( V_26 , & V_26 -> V_121 ) ;
if ( V_112 ) {
F_2 ( L_14 ) ;
goto V_163;
}
F_30 ( V_26 -> V_2 , V_26 -> V_114 ) ;
V_46 -> V_49 . V_164 =
F_23 ( & V_26 -> V_2 -> V_165 ) ;
if ( V_26 -> V_148 ) {
struct V_108 * V_166 = V_26 -> V_148 -> V_167 ;
struct V_108 * V_168 = V_26 -> V_148 -> V_169 ;
struct V_108 * V_170 = V_26 -> V_148 -> V_171 ;
struct V_48 * V_49 = & V_46 -> V_49 ;
unsigned V_56 ;
for ( V_56 = 0 ; V_56 < V_26 -> V_148 -> V_151 ; V_56 ++ ) {
struct V_108 * V_39 = V_26 -> V_148 -> V_158 [ V_56 ] . V_36 ;
V_26 -> V_148 -> V_158 [ V_56 ] . V_172 = F_62 ( V_49 , V_39 ) ;
}
if ( V_166 ) {
V_26 -> V_83 -> V_173 = F_63 ( V_166 ) ;
V_26 -> V_83 -> V_174 = F_7 ( V_166 ) ;
}
if ( V_168 ) {
V_26 -> V_83 -> V_175 = F_63 ( V_168 ) ;
V_26 -> V_83 -> V_176 = F_7 ( V_168 ) ;
}
if ( V_170 ) {
V_26 -> V_83 -> V_177 = F_63 ( V_170 ) ;
V_26 -> V_83 -> V_178 = F_7 ( V_170 ) ;
}
}
if ( ! V_112 && V_26 -> V_35 . V_36 ) {
struct V_108 * V_179 = V_26 -> V_35 . V_36 ;
V_112 = F_64 ( & V_179 -> V_40 , & V_179 -> V_40 . V_127 ) ;
V_26 -> V_83 -> V_85 += F_63 ( V_179 ) ;
}
V_163:
if ( V_112 ) {
F_65 ( V_26 -> V_2 , & V_46 -> V_49 ) ;
F_56 ( & V_26 -> V_155 , & V_26 -> V_121 ) ;
}
V_157:
if ( V_146 )
F_66 ( & V_136 -> V_137 -> V_153 ) ;
if ( V_26 -> V_148 ) {
for ( V_56 = V_26 -> V_148 -> V_150 ;
V_56 < V_26 -> V_148 -> V_151 ; ++ V_56 ) {
V_144 = & V_26 -> V_148 -> V_158 [ V_56 ] ;
if ( ! V_144 -> V_42 )
continue;
F_52 ( V_144 -> V_42 ,
V_144 -> V_36 -> V_40 . V_44 -> V_142 ,
false ) ;
F_18 ( V_144 -> V_42 ) ;
}
}
return V_112 ;
}
static int F_67 ( struct V_25 * V_26 )
{
struct V_124 * V_144 ;
int V_112 ;
F_42 (e, &p->validated, tv.head) {
struct V_180 * V_181 = V_144 -> V_36 -> V_40 . V_181 ;
V_112 = F_68 ( V_26 -> V_2 , & V_26 -> V_83 -> V_182 , V_181 , V_26 -> V_33 ) ;
if ( V_112 )
return V_112 ;
}
return 0 ;
}
static void F_69 ( struct V_25 * V_183 , int error , bool V_184 )
{
struct V_45 * V_46 = V_183 -> V_33 -> V_47 ;
unsigned V_56 ;
if ( ! error ) {
F_65 ( V_183 -> V_2 , & V_46 -> V_49 ) ;
F_70 ( & V_183 -> V_155 ,
& V_183 -> V_121 ,
V_183 -> V_185 ) ;
} else if ( V_184 ) {
F_56 ( & V_183 -> V_155 ,
& V_183 -> V_121 ) ;
}
F_71 ( V_183 -> V_185 ) ;
if ( V_183 -> V_62 )
F_19 ( V_183 -> V_62 ) ;
if ( V_183 -> V_148 )
F_72 ( V_183 -> V_148 ) ;
for ( V_56 = 0 ; V_56 < V_183 -> V_69 ; V_56 ++ )
F_18 ( V_183 -> V_66 [ V_56 ] . V_79 ) ;
F_17 ( V_183 -> V_66 ) ;
if ( V_183 -> V_83 )
F_73 ( V_183 -> V_83 ) ;
F_10 ( & V_183 -> V_35 . V_36 ) ;
}
static int F_74 ( struct V_25 * V_26 ,
struct V_48 * V_49 )
{
struct V_1 * V_2 = V_26 -> V_2 ;
struct V_186 * V_172 ;
struct V_108 * V_39 ;
int V_56 , V_112 ;
V_112 = F_75 ( V_2 , V_49 ) ;
if ( V_112 )
return V_112 ;
V_112 = F_76 ( V_2 , & V_26 -> V_83 -> V_182 , V_49 -> V_187 ) ;
if ( V_112 )
return V_112 ;
V_112 = F_77 ( V_2 , V_49 ) ;
if ( V_112 )
return V_112 ;
if ( F_78 ( V_2 ) ) {
struct V_188 * V_189 ;
V_172 = V_49 -> V_190 ;
F_79 ( ! V_172 ) ;
V_112 = F_80 ( V_2 , V_172 , false ) ;
if ( V_112 )
return V_112 ;
V_189 = V_172 -> V_191 ;
V_112 = F_76 ( V_2 , & V_26 -> V_83 -> V_182 , V_189 ) ;
if ( V_112 )
return V_112 ;
}
if ( V_26 -> V_148 ) {
for ( V_56 = 0 ; V_56 < V_26 -> V_148 -> V_151 ; V_56 ++ ) {
struct V_188 * V_189 ;
V_39 = V_26 -> V_148 -> V_158 [ V_56 ] . V_36 ;
if ( ! V_39 )
continue;
V_172 = V_26 -> V_148 -> V_158 [ V_56 ] . V_172 ;
if ( V_172 == NULL )
continue;
V_112 = F_80 ( V_2 , V_172 , false ) ;
if ( V_112 )
return V_112 ;
V_189 = V_172 -> V_191 ;
V_112 = F_76 ( V_2 , & V_26 -> V_83 -> V_182 , V_189 ) ;
if ( V_112 )
return V_112 ;
}
}
V_112 = F_81 ( V_2 , V_49 , & V_26 -> V_83 -> V_182 ) ;
if ( V_192 && V_26 -> V_148 ) {
for ( V_56 = 0 ; V_56 < V_26 -> V_148 -> V_151 ; V_56 ++ ) {
V_39 = V_26 -> V_148 -> V_158 [ V_56 ] . V_36 ;
if ( ! V_39 )
continue;
F_82 ( V_2 , V_39 ) ;
}
}
return V_112 ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_45 * V_46 = V_26 -> V_33 -> V_47 ;
struct V_48 * V_49 = & V_46 -> V_49 ;
struct V_6 * V_5 = V_26 -> V_83 -> V_5 ;
int V_56 , V_112 ;
if ( V_5 -> V_193 -> V_194 ) {
for ( V_56 = 0 ; V_56 < V_26 -> V_83 -> V_54 ; V_56 ++ ) {
V_112 = F_84 ( V_5 , V_26 , V_56 ) ;
if ( V_112 )
return V_112 ;
}
}
if ( V_26 -> V_83 -> V_49 ) {
V_26 -> V_83 -> V_195 = F_63 ( V_49 -> V_196 ) ;
V_112 = F_74 ( V_26 , V_49 ) ;
if ( V_112 )
return V_112 ;
}
return F_67 ( V_26 ) ;
}
static int F_85 ( struct V_1 * V_2 ,
struct V_25 * V_183 )
{
struct V_45 * V_46 = V_183 -> V_33 -> V_47 ;
struct V_48 * V_49 = & V_46 -> V_49 ;
int V_56 , V_197 ;
int V_112 ;
for ( V_56 = 0 , V_197 = 0 ; V_56 < V_183 -> V_69 && V_197 < V_183 -> V_83 -> V_54 ; V_56 ++ ) {
struct V_70 * V_198 ;
struct V_199 * V_200 ;
struct V_201 * V_202 ;
struct V_6 * V_5 ;
V_198 = & V_183 -> V_66 [ V_56 ] ;
V_200 = & V_183 -> V_83 -> V_203 [ V_197 ] ;
V_202 = (struct V_201 * ) V_198 -> V_79 ;
if ( V_198 -> V_76 != V_80 )
continue;
V_112 = F_1 ( V_2 , V_202 -> V_3 ,
V_202 -> V_4 , V_202 -> V_5 ,
& V_5 ) ;
if ( V_112 )
return V_112 ;
if ( V_200 -> V_105 & V_204 ) {
V_183 -> V_83 -> V_205 |= V_206 ;
if ( ! V_183 -> V_62 -> V_207 ) {
V_183 -> V_83 -> V_205 |= V_208 ;
V_183 -> V_62 -> V_207 = true ;
}
}
if ( V_183 -> V_83 -> V_5 && V_183 -> V_83 -> V_5 != V_5 )
return - V_8 ;
V_183 -> V_83 -> V_5 = V_5 ;
if ( V_5 -> V_193 -> V_194 ) {
struct V_209 * V_210 ;
struct V_108 * V_211 = NULL ;
T_3 V_29 ;
T_7 * V_212 ;
V_210 = F_86 ( V_183 , V_202 -> va_start ,
& V_211 ) ;
if ( ! V_211 ) {
F_2 ( L_15 ) ;
return - V_8 ;
}
if ( ( V_202 -> va_start + V_202 -> V_213 ) >
( V_210 -> V_214 . V_215 + 1 ) * V_216 ) {
F_2 ( L_16 ) ;
return - V_8 ;
}
V_112 = F_87 ( V_211 , ( void * * ) & V_212 ) ;
if ( V_112 ) {
return V_112 ;
}
V_29 = ( ( T_3 ) V_210 -> V_214 . V_217 ) * V_216 ;
V_212 += V_202 -> va_start - V_29 ;
V_112 = F_88 ( V_2 , V_49 , V_202 -> V_213 , V_200 ) ;
if ( V_112 ) {
F_2 ( L_17 ) ;
return V_112 ;
}
memcpy ( V_200 -> V_218 , V_212 , V_202 -> V_213 ) ;
F_89 ( V_211 ) ;
} else {
V_112 = F_88 ( V_2 , V_49 , 0 , V_200 ) ;
if ( V_112 ) {
F_2 ( L_17 ) ;
return V_112 ;
}
}
V_200 -> V_219 = V_202 -> va_start ;
V_200 -> V_77 = V_202 -> V_213 / 4 ;
V_200 -> V_105 = V_202 -> V_105 ;
V_197 ++ ;
}
if ( V_183 -> V_83 -> V_85 && (
V_183 -> V_83 -> V_5 -> V_193 -> type == V_220 ||
V_183 -> V_83 -> V_5 -> V_193 -> type == V_221 ) )
return - V_8 ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_45 * V_46 = V_26 -> V_33 -> V_47 ;
int V_56 , V_197 , V_112 ;
for ( V_56 = 0 ; V_56 < V_26 -> V_69 ; ++ V_56 ) {
struct V_222 * V_223 ;
struct V_70 * V_198 ;
unsigned V_224 ;
V_198 = & V_26 -> V_66 [ V_56 ] ;
if ( V_198 -> V_76 != V_82 )
continue;
V_223 = (struct V_222 * ) V_198 -> V_79 ;
V_224 = V_198 -> V_77 * 4 /
sizeof( struct V_222 ) ;
for ( V_197 = 0 ; V_197 < V_224 ; ++ V_197 ) {
struct V_6 * V_5 ;
struct V_225 * V_62 ;
struct V_188 * V_185 ;
V_112 = F_1 ( V_2 , V_223 [ V_197 ] . V_3 ,
V_223 [ V_197 ] . V_4 ,
V_223 [ V_197 ] . V_5 , & V_5 ) ;
if ( V_112 )
return V_112 ;
V_62 = F_13 ( V_46 , V_223 [ V_197 ] . V_63 ) ;
if ( V_62 == NULL )
return - V_8 ;
V_185 = F_91 ( V_62 , V_5 ,
V_223 [ V_197 ] . V_34 ) ;
if ( F_92 ( V_185 ) ) {
V_112 = F_93 ( V_185 ) ;
F_19 ( V_62 ) ;
return V_112 ;
} else if ( V_185 ) {
V_112 = F_76 ( V_2 , & V_26 -> V_83 -> V_182 ,
V_185 ) ;
F_71 ( V_185 ) ;
F_19 ( V_62 ) ;
if ( V_112 )
return V_112 ;
}
}
}
return 0 ;
}
static int F_94 ( struct V_25 * V_26 ,
union V_50 * V_51 )
{
struct V_6 * V_5 = V_26 -> V_83 -> V_5 ;
struct V_226 * V_227 = & V_26 -> V_62 -> V_228 [ V_5 -> V_229 ] . V_227 ;
struct V_230 * V_83 ;
int V_112 ;
V_83 = V_26 -> V_83 ;
V_26 -> V_83 = NULL ;
V_112 = F_95 ( & V_83 -> V_231 , & V_5 -> V_232 , V_227 , V_26 -> V_33 ) ;
if ( V_112 ) {
F_73 ( V_83 ) ;
return V_112 ;
}
V_83 -> V_233 = V_26 -> V_33 ;
V_83 -> V_234 = V_227 -> V_235 ;
V_26 -> V_185 = F_96 ( & V_83 -> V_231 . V_236 -> V_237 ) ;
V_51 -> V_238 . V_34 = F_97 ( V_26 -> V_62 , V_5 , V_26 -> V_185 ) ;
V_83 -> V_239 = V_51 -> V_238 . V_34 ;
F_98 ( V_83 ) ;
F_99 ( V_83 ) ;
F_100 ( & V_83 -> V_231 ) ;
return 0 ;
}
int F_101 ( struct V_240 * V_241 , void * V_28 , struct V_242 * V_33 )
{
struct V_1 * V_2 = V_241 -> V_243 ;
union V_50 * V_51 = V_28 ;
struct V_25 V_183 = {} ;
bool V_244 = false ;
int V_56 , V_112 ;
if ( ! V_2 -> V_245 )
return - V_246 ;
V_183 . V_2 = V_2 ;
V_183 . V_33 = V_33 ;
V_112 = F_11 ( & V_183 , V_28 ) ;
if ( V_112 ) {
F_2 ( L_18 ) ;
goto V_238;
}
V_112 = F_43 ( & V_183 , V_28 ) ;
if ( V_112 ) {
if ( V_112 == - V_61 )
F_2 ( L_19 ) ;
else if ( V_112 != - V_156 )
F_2 ( L_20 , V_112 ) ;
goto V_238;
}
V_244 = true ;
V_112 = F_85 ( V_2 , & V_183 ) ;
if ( V_112 )
goto V_238;
V_112 = F_90 ( V_2 , & V_183 ) ;
if ( V_112 ) {
F_2 ( L_21 , V_112 ) ;
goto V_238;
}
for ( V_56 = 0 ; V_56 < V_183 . V_83 -> V_54 ; V_56 ++ )
F_102 ( & V_183 , V_56 ) ;
V_112 = F_83 ( V_2 , & V_183 ) ;
if ( V_112 )
goto V_238;
V_112 = F_94 ( & V_183 , V_51 ) ;
V_238:
F_69 ( & V_183 , V_112 , V_244 ) ;
return V_112 ;
}
int F_103 ( struct V_240 * V_241 , void * V_28 ,
struct V_242 * V_33 )
{
union V_247 * V_248 = V_28 ;
struct V_1 * V_2 = V_241 -> V_243 ;
unsigned long V_249 = F_104 ( V_248 -> V_58 . V_249 ) ;
struct V_6 * V_5 = NULL ;
struct V_225 * V_62 ;
struct V_188 * V_185 ;
long V_112 ;
V_112 = F_1 ( V_2 , V_248 -> V_58 . V_3 , V_248 -> V_58 . V_4 ,
V_248 -> V_58 . V_5 , & V_5 ) ;
if ( V_112 )
return V_112 ;
V_62 = F_13 ( V_33 -> V_47 , V_248 -> V_58 . V_63 ) ;
if ( V_62 == NULL )
return - V_8 ;
V_185 = F_91 ( V_62 , V_5 , V_248 -> V_58 . V_34 ) ;
if ( F_92 ( V_185 ) )
V_112 = F_93 ( V_185 ) ;
else if ( V_185 ) {
V_112 = F_105 ( V_185 , true , V_249 ) ;
F_71 ( V_185 ) ;
} else
V_112 = 1 ;
F_19 ( V_62 ) ;
if ( V_112 < 0 )
return V_112 ;
memset ( V_248 , 0 , sizeof( * V_248 ) ) ;
V_248 -> V_238 . V_250 = ( V_112 == 0 ) ;
return 0 ;
}
static struct V_188 * F_106 ( struct V_1 * V_2 ,
struct V_242 * V_33 ,
struct V_251 * V_252 )
{
struct V_6 * V_5 ;
struct V_225 * V_62 ;
struct V_188 * V_185 ;
int V_112 ;
V_112 = F_1 ( V_2 , V_252 -> V_3 , V_252 -> V_4 ,
V_252 -> V_5 , & V_5 ) ;
if ( V_112 )
return F_107 ( V_112 ) ;
V_62 = F_13 ( V_33 -> V_47 , V_252 -> V_63 ) ;
if ( V_62 == NULL )
return F_107 ( - V_8 ) ;
V_185 = F_91 ( V_62 , V_5 , V_252 -> V_253 ) ;
F_19 ( V_62 ) ;
return V_185 ;
}
static int F_108 ( struct V_1 * V_2 ,
struct V_242 * V_33 ,
union V_254 * V_248 ,
struct V_251 * V_255 )
{
T_2 V_256 = V_248 -> V_58 . V_256 ;
unsigned int V_56 ;
long V_112 = 1 ;
for ( V_56 = 0 ; V_56 < V_256 ; V_56 ++ ) {
struct V_188 * V_185 ;
unsigned long V_249 = F_104 ( V_248 -> V_58 . V_257 ) ;
V_185 = F_106 ( V_2 , V_33 , & V_255 [ V_56 ] ) ;
if ( F_92 ( V_185 ) )
return F_93 ( V_185 ) ;
else if ( ! V_185 )
continue;
V_112 = F_105 ( V_185 , true , V_249 ) ;
if ( V_112 < 0 )
return V_112 ;
if ( V_112 == 0 )
break;
}
memset ( V_248 , 0 , sizeof( * V_248 ) ) ;
V_248 -> V_238 . V_250 = ( V_112 > 0 ) ;
return 0 ;
}
static int F_109 ( struct V_1 * V_2 ,
struct V_242 * V_33 ,
union V_254 * V_248 ,
struct V_251 * V_255 )
{
unsigned long V_249 = F_104 ( V_248 -> V_58 . V_257 ) ;
T_2 V_256 = V_248 -> V_58 . V_256 ;
T_2 V_258 = ~ 0 ;
struct V_188 * * V_158 ;
unsigned int V_56 ;
long V_112 ;
V_158 = F_110 ( V_256 , sizeof( struct V_188 * ) , V_60 ) ;
if ( V_158 == NULL )
return - V_61 ;
for ( V_56 = 0 ; V_56 < V_256 ; V_56 ++ ) {
struct V_188 * V_185 ;
V_185 = F_106 ( V_2 , V_33 , & V_255 [ V_56 ] ) ;
if ( F_92 ( V_185 ) ) {
V_112 = F_93 ( V_185 ) ;
goto V_259;
} else if ( V_185 ) {
V_158 [ V_56 ] = V_185 ;
} else {
V_112 = 1 ;
goto V_238;
}
}
V_112 = F_111 ( V_158 , V_256 , true , V_249 ,
& V_258 ) ;
if ( V_112 < 0 )
goto V_259;
V_238:
memset ( V_248 , 0 , sizeof( * V_248 ) ) ;
V_248 -> V_238 . V_250 = ( V_112 > 0 ) ;
V_248 -> V_238 . V_260 = V_258 ;
V_112 = 0 ;
V_259:
for ( V_56 = 0 ; V_56 < V_256 ; V_56 ++ )
F_71 ( V_158 [ V_56 ] ) ;
F_17 ( V_158 ) ;
return V_112 ;
}
int F_112 ( struct V_240 * V_241 , void * V_28 ,
struct V_242 * V_33 )
{
struct V_1 * V_2 = V_241 -> V_243 ;
union V_254 * V_248 = V_28 ;
T_2 V_256 = V_248 -> V_58 . V_256 ;
struct V_251 * V_261 ;
struct V_251 * V_255 ;
int V_112 ;
V_255 = F_12 ( V_256 , sizeof( struct V_251 ) ,
V_60 ) ;
if ( V_255 == NULL )
return - V_61 ;
V_261 = ( void V_65 * ) ( unsigned long ) ( V_248 -> V_58 . V_255 ) ;
if ( F_14 ( V_255 , V_261 ,
sizeof( struct V_251 ) * V_256 ) ) {
V_112 = - V_67 ;
goto V_262;
}
if ( V_248 -> V_58 . V_263 )
V_112 = F_108 ( V_2 , V_33 , V_248 , V_255 ) ;
else
V_112 = F_109 ( V_2 , V_33 , V_248 , V_255 ) ;
V_262:
F_17 ( V_255 ) ;
return V_112 ;
}
struct V_209 *
F_86 ( struct V_25 * V_183 ,
T_3 V_264 , struct V_108 * * V_39 )
{
struct V_209 * V_265 ;
unsigned V_56 ;
if ( ! V_183 -> V_148 )
return NULL ;
V_264 /= V_216 ;
for ( V_56 = 0 ; V_56 < V_183 -> V_148 -> V_151 ; V_56 ++ ) {
struct V_124 * V_132 ;
V_132 = & V_183 -> V_148 -> V_158 [ V_56 ] ;
if ( ! V_132 -> V_172 )
continue;
F_42 (mapping, &lobj->bo_va->valids, list) {
if ( V_265 -> V_214 . V_217 > V_264 ||
V_264 > V_265 -> V_214 . V_215 )
continue;
* V_39 = V_132 -> V_172 -> V_39 ;
return V_265 ;
}
F_42 (mapping, &lobj->bo_va->invalids, list) {
if ( V_265 -> V_214 . V_217 > V_264 ||
V_264 > V_265 -> V_214 . V_215 )
continue;
* V_39 = V_132 -> V_172 -> V_39 ;
return V_265 ;
}
}
return NULL ;
}
int F_113 ( struct V_25 * V_183 )
{
unsigned V_56 ;
int V_112 ;
if ( ! V_183 -> V_148 )
return 0 ;
for ( V_56 = 0 ; V_56 < V_183 -> V_148 -> V_151 ; V_56 ++ ) {
struct V_108 * V_39 = V_183 -> V_148 -> V_158 [ V_56 ] . V_36 ;
V_112 = F_64 ( & V_39 -> V_40 , & V_39 -> V_40 . V_127 ) ;
if ( F_35 ( V_112 ) )
return V_112 ;
if ( V_39 -> V_105 & V_266 )
continue;
V_39 -> V_105 |= V_266 ;
F_33 ( V_39 , V_39 -> V_117 ) ;
V_112 = F_34 ( & V_39 -> V_40 , & V_39 -> V_120 , false , false ) ;
if ( F_35 ( V_112 ) )
return V_112 ;
}
return 0 ;
}
