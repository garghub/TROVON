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
if ( V_5 < 2 ) {
* V_7 = & V_2 -> V_23 . V_5 [ V_5 ] ;
} else {
F_2 ( L_6 ) ;
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
static int F_3 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
T_2 * V_28 )
{
struct V_29 * V_30 ;
unsigned long V_31 ;
V_30 = F_4 ( V_25 -> V_32 , V_27 -> V_33 ) ;
if ( V_30 == NULL )
return - V_8 ;
V_25 -> V_34 . V_35 = F_5 ( F_6 ( V_30 ) ) ;
V_25 -> V_34 . V_36 = 0 ;
V_25 -> V_34 . V_37 . V_38 = & V_25 -> V_34 . V_35 -> V_39 ;
V_25 -> V_34 . V_37 . V_40 = true ;
V_25 -> V_34 . V_41 = NULL ;
V_31 = F_7 ( V_25 -> V_34 . V_35 ) ;
if ( V_31 != V_42 || ( V_27 -> V_28 + 8 ) > V_31 )
return - V_8 ;
* V_28 = V_27 -> V_28 ;
F_8 ( V_30 ) ;
if ( F_9 ( V_25 -> V_34 . V_35 -> V_39 . V_43 ) ) {
F_10 ( & V_25 -> V_34 . V_35 ) ;
return - V_8 ;
}
return 0 ;
}
int F_11 ( struct V_24 * V_25 , void * V_27 )
{
struct V_44 * V_45 = V_25 -> V_32 -> V_46 ;
struct V_47 * V_48 = & V_45 -> V_48 ;
union V_49 * V_50 = V_27 ;
T_3 * V_51 ;
T_3 * V_52 ;
unsigned V_31 , V_53 = 0 ;
T_2 V_54 = 0 ;
int V_55 ;
int V_56 ;
if ( V_50 -> V_57 . V_58 == 0 )
return 0 ;
V_52 = F_12 ( V_50 -> V_57 . V_58 , sizeof( T_3 ) , V_59 ) ;
if ( ! V_52 )
return - V_60 ;
V_25 -> V_61 = F_13 ( V_45 , V_50 -> V_57 . V_62 ) ;
if ( ! V_25 -> V_61 ) {
V_56 = - V_8 ;
goto V_63;
}
V_51 = ( T_3 V_64 * ) ( unsigned long ) ( V_50 -> V_57 . V_65 ) ;
if ( F_14 ( V_52 , V_51 ,
sizeof( T_3 ) * V_50 -> V_57 . V_58 ) ) {
V_56 = - V_66 ;
goto V_67;
}
V_25 -> V_68 = V_50 -> V_57 . V_58 ;
V_25 -> V_65 = F_12 ( V_25 -> V_68 , sizeof( struct V_69 ) ,
V_59 ) ;
if ( ! V_25 -> V_65 ) {
V_56 = - V_60 ;
goto V_67;
}
for ( V_55 = 0 ; V_55 < V_25 -> V_68 ; V_55 ++ ) {
struct V_70 V_64 * * V_71 = NULL ;
struct V_70 V_72 ;
T_2 V_64 * V_73 ;
V_71 = ( void V_64 * ) ( unsigned long ) V_52 [ V_55 ] ;
if ( F_14 ( & V_72 , V_71 ,
sizeof( struct V_70 ) ) ) {
V_56 = - V_66 ;
V_55 -- ;
goto V_74;
}
V_25 -> V_65 [ V_55 ] . V_75 = V_72 . V_75 ;
V_25 -> V_65 [ V_55 ] . V_76 = V_72 . V_76 ;
V_31 = V_25 -> V_65 [ V_55 ] . V_76 ;
V_73 = ( void V_64 * ) ( unsigned long ) V_72 . V_77 ;
V_25 -> V_65 [ V_55 ] . V_78 = F_15 ( V_31 , sizeof( T_2 ) ) ;
if ( V_25 -> V_65 [ V_55 ] . V_78 == NULL ) {
V_56 = - V_60 ;
V_55 -- ;
goto V_74;
}
V_31 *= sizeof( T_2 ) ;
if ( F_14 ( V_25 -> V_65 [ V_55 ] . V_78 , V_73 , V_31 ) ) {
V_56 = - V_66 ;
goto V_74;
}
switch ( V_25 -> V_65 [ V_55 ] . V_75 ) {
case V_79 :
++ V_53 ;
break;
case V_80 :
V_31 = sizeof( struct V_26 ) ;
if ( V_25 -> V_65 [ V_55 ] . V_76 * sizeof( T_2 ) < V_31 ) {
V_56 = - V_8 ;
goto V_74;
}
V_56 = F_3 ( V_25 , V_25 -> V_65 [ V_55 ] . V_78 ,
& V_54 ) ;
if ( V_56 )
goto V_74;
break;
case V_81 :
break;
default:
V_56 = - V_8 ;
goto V_74;
}
}
V_56 = F_16 ( V_25 -> V_2 , V_53 , & V_25 -> V_82 , V_48 ) ;
if ( V_56 )
goto V_83;
if ( V_25 -> V_34 . V_35 )
V_25 -> V_82 -> V_84 = V_54 ;
F_17 ( V_52 ) ;
return 0 ;
V_83:
V_55 = V_25 -> V_68 - 1 ;
V_74:
for (; V_55 >= 0 ; V_55 -- )
F_18 ( V_25 -> V_65 [ V_55 ] . V_78 ) ;
F_17 ( V_25 -> V_65 ) ;
V_67:
F_19 ( V_25 -> V_61 ) ;
V_63:
F_17 ( V_52 ) ;
return V_56 ;
}
static T_4 F_20 ( struct V_1 * V_2 , T_5 V_85 )
{
if ( V_85 <= 0 || ! V_2 -> V_86 . V_87 )
return 0 ;
return V_85 << V_2 -> V_86 . V_87 ;
}
static T_5 F_21 ( struct V_1 * V_2 , T_4 V_88 )
{
if ( ! V_2 -> V_86 . V_87 )
return 0 ;
return V_88 >> V_2 -> V_86 . V_87 ;
}
static T_4 F_22 ( struct V_1 * V_2 )
{
T_5 V_89 , V_90 ;
T_4 V_91 ;
T_4 V_92 , V_93 , V_94 ;
const T_5 V_95 = 200000 ;
if ( ! V_2 -> V_86 . V_87 )
return 0 ;
V_93 = V_2 -> V_96 . V_97 - V_2 -> V_98 ;
V_94 = F_23 ( & V_2 -> V_99 ) ;
V_92 = V_94 >= V_93 ? 0 : V_93 - V_94 ;
F_24 ( & V_2 -> V_86 . V_100 ) ;
V_89 = F_25 ( F_26 () ) ;
V_90 = V_89 - V_2 -> V_86 . V_101 ;
V_2 -> V_86 . V_101 = V_89 ;
V_2 -> V_86 . V_102 = F_27 ( V_2 -> V_86 . V_102 + V_90 ,
V_95 ) ;
if ( V_92 >= 128 * 1024 * 1024 || V_92 >= V_93 / 8 ) {
T_5 V_103 ;
if ( ! ( V_2 -> V_104 & V_105 ) )
V_103 = F_21 ( V_2 , V_92 / 4 ) ;
else
V_103 = 0 ;
V_2 -> V_86 . V_102 = F_28 ( V_103 , V_2 -> V_86 . V_102 ) ;
}
V_91 = F_20 ( V_2 , V_2 -> V_86 . V_102 ) ;
F_29 ( & V_2 -> V_86 . V_100 ) ;
return V_91 ;
}
static void F_30 ( struct V_1 * V_2 ,
T_4 V_106 )
{
F_24 ( & V_2 -> V_86 . V_100 ) ;
V_2 -> V_86 . V_102 -= F_21 ( V_2 , V_106 ) ;
F_29 ( & V_2 -> V_86 . V_100 ) ;
}
static int F_31 ( struct V_24 * V_25 ,
struct V_107 * V_38 )
{
struct V_1 * V_2 = F_32 ( V_38 -> V_39 . V_108 ) ;
T_4 V_109 ;
T_2 V_110 ;
int V_111 ;
if ( V_38 -> V_112 )
return 0 ;
if ( V_25 -> V_113 < V_25 -> V_114 )
V_110 = V_38 -> V_115 ;
else
V_110 = V_38 -> V_116 ;
V_117:
F_33 ( V_38 , V_110 ) ;
V_109 = F_23 ( & V_2 -> V_118 ) ;
V_111 = F_34 ( & V_38 -> V_39 , & V_38 -> V_119 , true , false ) ;
V_25 -> V_113 += F_23 ( & V_2 -> V_118 ) -
V_109 ;
if ( F_35 ( V_111 == - V_60 ) && V_110 != V_38 -> V_116 ) {
V_110 = V_38 -> V_116 ;
goto V_117;
}
return V_111 ;
}
static bool F_36 ( struct V_24 * V_25 ,
struct V_107 * V_120 )
{
T_2 V_110 = V_120 -> V_116 ;
int V_111 ;
if ( ! V_25 -> V_121 )
return false ;
for (; & V_25 -> V_121 -> V_37 . V_122 != & V_25 -> V_120 ;
V_25 -> V_121 = F_37 ( V_25 -> V_121 , V_37 . V_122 ) ) {
struct V_123 * V_124 = V_25 -> V_121 ;
struct V_107 * V_38 = V_124 -> V_35 ;
struct V_1 * V_2 = F_32 ( V_38 -> V_39 . V_108 ) ;
T_4 V_109 ;
T_2 V_125 ;
if ( V_124 -> V_35 == V_120 )
break;
V_125 = F_38 ( V_38 -> V_39 . V_126 . V_127 ) ;
if ( ! ( V_125 & V_110 ) )
continue;
V_125 = V_38 -> V_116 & ~ V_110 ;
if ( ! V_125 )
continue;
F_33 ( V_38 , V_125 ) ;
V_109 = F_23 ( & V_2 -> V_118 ) ;
V_111 = F_34 ( & V_38 -> V_39 , & V_38 -> V_119 , true , false ) ;
V_25 -> V_113 += F_23 ( & V_2 -> V_118 ) -
V_109 ;
if ( F_35 ( V_111 ) )
break;
V_25 -> V_121 = F_37 ( V_25 -> V_121 , V_37 . V_122 ) ;
F_39 ( & V_124 -> V_37 . V_122 , & V_25 -> V_120 ) ;
return true ;
}
return false ;
}
static int F_40 ( void * V_128 , struct V_107 * V_38 )
{
struct V_24 * V_25 = V_128 ;
int V_111 ;
do {
V_111 = F_31 ( V_25 , V_38 ) ;
} while ( V_111 == - V_60 && F_36 ( V_25 , V_38 ) );
if ( V_111 )
return V_111 ;
if ( V_38 -> V_129 )
V_111 = F_31 ( V_25 , V_38 -> V_129 ) ;
return V_111 ;
}
static int F_41 ( struct V_24 * V_25 ,
struct V_130 * V_120 )
{
struct V_123 * V_131 ;
int V_111 ;
F_42 (lobj, validated, tv.head) {
struct V_107 * V_38 = V_131 -> V_35 ;
bool V_132 = false ;
struct V_133 * V_134 ;
V_134 = F_9 ( V_38 -> V_39 . V_43 ) ;
if ( V_134 && V_134 != V_135 -> V_136 )
return - V_137 ;
if ( V_131 -> V_41 && V_38 -> V_39 . V_43 -> V_138 != V_139 ) {
T_6 V_31 = sizeof( struct V_140 * ) ;
V_31 *= V_38 -> V_39 . V_43 -> V_141 ;
memcpy ( V_38 -> V_39 . V_43 -> V_142 , V_131 -> V_41 , V_31 ) ;
V_132 = true ;
}
if ( V_25 -> V_121 == V_131 )
V_25 -> V_121 = NULL ;
V_111 = F_40 ( V_25 , V_38 ) ;
if ( V_111 )
return V_111 ;
if ( V_132 ) {
F_18 ( V_131 -> V_41 ) ;
V_131 -> V_41 = NULL ;
}
}
return 0 ;
}
static int F_43 ( struct V_24 * V_25 ,
union V_49 * V_50 )
{
struct V_44 * V_45 = V_25 -> V_32 -> V_46 ;
struct V_123 * V_143 ;
struct V_130 V_144 ;
bool V_145 = false ;
unsigned V_55 , V_146 = 10 ;
int V_111 ;
F_44 ( & V_25 -> V_120 ) ;
V_25 -> V_147 = F_45 ( V_45 , V_50 -> V_57 . V_148 ) ;
if ( V_25 -> V_147 ) {
V_145 = V_25 -> V_147 -> V_149 !=
V_25 -> V_147 -> V_150 ;
F_46 ( V_25 -> V_147 , & V_25 -> V_120 ) ;
}
F_44 ( & V_144 ) ;
F_47 ( & V_45 -> V_48 , & V_25 -> V_120 , & V_25 -> V_151 ) ;
if ( V_25 -> V_34 . V_35 )
F_48 ( & V_25 -> V_34 . V_37 . V_122 , & V_25 -> V_120 ) ;
if ( V_145 )
F_49 ( & V_135 -> V_136 -> V_152 ) ;
while ( 1 ) {
struct V_130 V_153 ;
unsigned V_55 ;
V_111 = F_50 ( & V_25 -> V_154 , & V_25 -> V_120 , true ,
& V_144 ) ;
if ( F_35 ( V_111 != 0 ) ) {
if ( V_111 != - V_155 )
F_2 ( L_8 ) ;
goto V_156;
}
if ( ! V_25 -> V_147 )
break;
F_44 ( & V_153 ) ;
for ( V_55 = V_25 -> V_147 -> V_149 ;
V_55 < V_25 -> V_147 -> V_150 ; ++ V_55 ) {
V_143 = & V_25 -> V_147 -> V_157 [ V_55 ] ;
if ( F_51 ( V_143 -> V_35 -> V_39 . V_43 ,
& V_143 -> V_158 ) && V_143 -> V_41 ) {
F_52 ( V_143 -> V_41 ,
V_143 -> V_35 -> V_39 . V_43 -> V_141 ,
false ) ;
F_18 ( V_143 -> V_41 ) ;
V_143 -> V_41 = NULL ;
}
if ( V_143 -> V_35 -> V_39 . V_43 -> V_138 != V_139 &&
! V_143 -> V_41 ) {
F_53 ( & V_143 -> V_37 . V_122 ) ;
F_48 ( & V_143 -> V_37 . V_122 , & V_153 ) ;
F_54 ( V_143 -> V_35 ) ;
}
}
if ( F_55 ( & V_153 ) )
break;
F_56 ( & V_25 -> V_154 , & V_25 -> V_120 ) ;
if ( ! -- V_146 ) {
V_111 = - V_159 ;
F_2 ( L_9 , V_160 ) ;
goto V_156;
}
F_42 (e, &need_pages, tv.head) {
struct V_161 * V_43 = V_143 -> V_35 -> V_39 . V_43 ;
V_143 -> V_41 = F_57 ( V_43 -> V_141 ,
sizeof( struct V_140 * ) ) ;
if ( ! V_143 -> V_41 ) {
V_111 = - V_60 ;
F_2 ( L_10 , V_160 ) ;
goto V_156;
}
V_111 = F_58 ( V_43 , V_143 -> V_41 ) ;
if ( V_111 ) {
F_2 ( L_11 ) ;
F_18 ( V_143 -> V_41 ) ;
V_143 -> V_41 = NULL ;
goto V_156;
}
}
F_59 ( & V_153 , & V_25 -> V_120 ) ;
}
V_25 -> V_114 = F_22 ( V_25 -> V_2 ) ;
V_25 -> V_113 = 0 ;
V_25 -> V_121 = F_60 ( & V_25 -> V_120 ,
struct V_123 ,
V_37 . V_122 ) ;
V_111 = F_61 ( V_25 -> V_2 , & V_45 -> V_48 ,
F_40 , V_25 ) ;
if ( V_111 ) {
F_2 ( L_12 ) ;
goto V_162;
}
V_111 = F_41 ( V_25 , & V_144 ) ;
if ( V_111 ) {
F_2 ( L_13 ) ;
goto V_162;
}
V_111 = F_41 ( V_25 , & V_25 -> V_120 ) ;
if ( V_111 ) {
F_2 ( L_14 ) ;
goto V_162;
}
F_30 ( V_25 -> V_2 , V_25 -> V_113 ) ;
V_45 -> V_48 . V_163 =
F_23 ( & V_25 -> V_2 -> V_164 ) ;
if ( V_25 -> V_147 ) {
struct V_107 * V_165 = V_25 -> V_147 -> V_166 ;
struct V_107 * V_167 = V_25 -> V_147 -> V_168 ;
struct V_107 * V_169 = V_25 -> V_147 -> V_170 ;
struct V_47 * V_48 = & V_45 -> V_48 ;
unsigned V_55 ;
for ( V_55 = 0 ; V_55 < V_25 -> V_147 -> V_150 ; V_55 ++ ) {
struct V_107 * V_38 = V_25 -> V_147 -> V_157 [ V_55 ] . V_35 ;
V_25 -> V_147 -> V_157 [ V_55 ] . V_171 = F_62 ( V_48 , V_38 ) ;
}
if ( V_165 ) {
V_25 -> V_82 -> V_172 = F_63 ( V_165 ) ;
V_25 -> V_82 -> V_173 = F_7 ( V_165 ) ;
}
if ( V_167 ) {
V_25 -> V_82 -> V_174 = F_63 ( V_167 ) ;
V_25 -> V_82 -> V_175 = F_7 ( V_167 ) ;
}
if ( V_169 ) {
V_25 -> V_82 -> V_176 = F_63 ( V_169 ) ;
V_25 -> V_82 -> V_177 = F_7 ( V_169 ) ;
}
}
if ( ! V_111 && V_25 -> V_34 . V_35 ) {
struct V_107 * V_178 = V_25 -> V_34 . V_35 ;
V_111 = F_64 ( & V_178 -> V_39 , & V_178 -> V_39 . V_126 ) ;
V_25 -> V_82 -> V_84 += F_63 ( V_178 ) ;
}
V_162:
if ( V_111 ) {
F_65 ( V_25 -> V_2 , & V_45 -> V_48 ) ;
F_56 ( & V_25 -> V_154 , & V_25 -> V_120 ) ;
}
V_156:
if ( V_145 )
F_66 ( & V_135 -> V_136 -> V_152 ) ;
if ( V_25 -> V_147 ) {
for ( V_55 = V_25 -> V_147 -> V_149 ;
V_55 < V_25 -> V_147 -> V_150 ; ++ V_55 ) {
V_143 = & V_25 -> V_147 -> V_157 [ V_55 ] ;
if ( ! V_143 -> V_41 )
continue;
F_52 ( V_143 -> V_41 ,
V_143 -> V_35 -> V_39 . V_43 -> V_141 ,
false ) ;
F_18 ( V_143 -> V_41 ) ;
}
}
return V_111 ;
}
static int F_67 ( struct V_24 * V_25 )
{
struct V_123 * V_143 ;
int V_111 ;
F_42 (e, &p->validated, tv.head) {
struct V_179 * V_180 = V_143 -> V_35 -> V_39 . V_180 ;
V_111 = F_68 ( V_25 -> V_2 , & V_25 -> V_82 -> V_181 , V_180 , V_25 -> V_32 ) ;
if ( V_111 )
return V_111 ;
}
return 0 ;
}
static void F_69 ( struct V_24 * V_182 , int error , bool V_183 )
{
struct V_44 * V_45 = V_182 -> V_32 -> V_46 ;
unsigned V_55 ;
if ( ! error ) {
F_65 ( V_182 -> V_2 , & V_45 -> V_48 ) ;
F_70 ( & V_182 -> V_154 ,
& V_182 -> V_120 ,
V_182 -> V_184 ) ;
} else if ( V_183 ) {
F_56 ( & V_182 -> V_154 ,
& V_182 -> V_120 ) ;
}
F_71 ( V_182 -> V_184 ) ;
if ( V_182 -> V_61 )
F_19 ( V_182 -> V_61 ) ;
if ( V_182 -> V_147 )
F_72 ( V_182 -> V_147 ) ;
for ( V_55 = 0 ; V_55 < V_182 -> V_68 ; V_55 ++ )
F_18 ( V_182 -> V_65 [ V_55 ] . V_78 ) ;
F_17 ( V_182 -> V_65 ) ;
if ( V_182 -> V_82 )
F_73 ( V_182 -> V_82 ) ;
F_10 ( & V_182 -> V_34 . V_35 ) ;
}
static int F_74 ( struct V_24 * V_25 ,
struct V_47 * V_48 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
struct V_185 * V_171 ;
struct V_107 * V_38 ;
int V_55 , V_111 ;
V_111 = F_75 ( V_2 , V_48 ) ;
if ( V_111 )
return V_111 ;
V_111 = F_76 ( V_2 , & V_25 -> V_82 -> V_181 , V_48 -> V_186 ) ;
if ( V_111 )
return V_111 ;
V_111 = F_77 ( V_2 , V_48 ) ;
if ( V_111 )
return V_111 ;
if ( V_25 -> V_147 ) {
for ( V_55 = 0 ; V_55 < V_25 -> V_147 -> V_150 ; V_55 ++ ) {
struct V_187 * V_188 ;
V_38 = V_25 -> V_147 -> V_157 [ V_55 ] . V_35 ;
if ( ! V_38 )
continue;
V_171 = V_25 -> V_147 -> V_157 [ V_55 ] . V_171 ;
if ( V_171 == NULL )
continue;
V_111 = F_78 ( V_2 , V_171 , false ) ;
if ( V_111 )
return V_111 ;
V_188 = V_171 -> V_189 ;
V_111 = F_76 ( V_2 , & V_25 -> V_82 -> V_181 , V_188 ) ;
if ( V_111 )
return V_111 ;
}
}
V_111 = F_79 ( V_2 , V_48 , & V_25 -> V_82 -> V_181 ) ;
if ( V_190 && V_25 -> V_147 ) {
for ( V_55 = 0 ; V_55 < V_25 -> V_147 -> V_150 ; V_55 ++ ) {
V_38 = V_25 -> V_147 -> V_157 [ V_55 ] . V_35 ;
if ( ! V_38 )
continue;
F_80 ( V_2 , V_38 ) ;
}
}
return V_111 ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_44 * V_45 = V_25 -> V_32 -> V_46 ;
struct V_47 * V_48 = & V_45 -> V_48 ;
struct V_6 * V_5 = V_25 -> V_82 -> V_5 ;
int V_55 , V_111 ;
if ( V_5 -> V_191 -> V_192 ) {
for ( V_55 = 0 ; V_55 < V_25 -> V_82 -> V_53 ; V_55 ++ ) {
V_111 = F_82 ( V_5 , V_25 , V_55 ) ;
if ( V_111 )
return V_111 ;
}
}
if ( V_25 -> V_82 -> V_48 ) {
V_25 -> V_82 -> V_193 = F_63 ( V_48 -> V_194 ) ;
V_111 = F_74 ( V_25 , V_48 ) ;
if ( V_111 )
return V_111 ;
}
return F_67 ( V_25 ) ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_24 * V_182 )
{
struct V_44 * V_45 = V_182 -> V_32 -> V_46 ;
struct V_47 * V_48 = & V_45 -> V_48 ;
int V_55 , V_195 ;
int V_111 ;
for ( V_55 = 0 , V_195 = 0 ; V_55 < V_182 -> V_68 && V_195 < V_182 -> V_82 -> V_53 ; V_55 ++ ) {
struct V_69 * V_196 ;
struct V_197 * V_198 ;
struct V_199 * V_200 ;
struct V_6 * V_5 ;
V_196 = & V_182 -> V_65 [ V_55 ] ;
V_198 = & V_182 -> V_82 -> V_201 [ V_195 ] ;
V_200 = (struct V_199 * ) V_196 -> V_78 ;
if ( V_196 -> V_75 != V_79 )
continue;
V_111 = F_1 ( V_2 , V_200 -> V_3 ,
V_200 -> V_4 , V_200 -> V_5 ,
& V_5 ) ;
if ( V_111 )
return V_111 ;
if ( V_198 -> V_104 & V_202 ) {
V_182 -> V_82 -> V_203 |= V_204 ;
if ( ! V_182 -> V_61 -> V_205 ) {
V_182 -> V_82 -> V_203 |= V_206 ;
V_182 -> V_61 -> V_205 = true ;
}
}
if ( V_182 -> V_82 -> V_5 && V_182 -> V_82 -> V_5 != V_5 )
return - V_8 ;
V_182 -> V_82 -> V_5 = V_5 ;
if ( V_5 -> V_191 -> V_192 ) {
struct V_207 * V_208 ;
struct V_107 * V_209 = NULL ;
T_3 V_28 ;
T_7 * V_210 ;
V_208 = F_84 ( V_182 , V_200 -> va_start ,
& V_209 ) ;
if ( ! V_209 ) {
F_2 ( L_15 ) ;
return - V_8 ;
}
if ( ( V_200 -> va_start + V_200 -> V_211 ) >
( V_208 -> V_212 . V_213 + 1 ) * V_214 ) {
F_2 ( L_16 ) ;
return - V_8 ;
}
V_111 = F_85 ( V_209 , ( void * * ) & V_210 ) ;
if ( V_111 ) {
return V_111 ;
}
V_28 = ( ( T_3 ) V_208 -> V_212 . V_215 ) * V_214 ;
V_210 += V_200 -> va_start - V_28 ;
V_111 = F_86 ( V_2 , V_48 , V_200 -> V_211 , V_198 ) ;
if ( V_111 ) {
F_2 ( L_17 ) ;
return V_111 ;
}
memcpy ( V_198 -> V_216 , V_210 , V_200 -> V_211 ) ;
F_87 ( V_209 ) ;
} else {
V_111 = F_86 ( V_2 , V_48 , 0 , V_198 ) ;
if ( V_111 ) {
F_2 ( L_17 ) ;
return V_111 ;
}
}
V_198 -> V_217 = V_200 -> va_start ;
V_198 -> V_76 = V_200 -> V_211 / 4 ;
V_198 -> V_104 = V_200 -> V_104 ;
V_195 ++ ;
}
if ( V_182 -> V_82 -> V_84 && (
V_182 -> V_82 -> V_5 -> V_191 -> type == V_218 ||
V_182 -> V_82 -> V_5 -> V_191 -> type == V_219 ) )
return - V_8 ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_44 * V_45 = V_25 -> V_32 -> V_46 ;
int V_55 , V_195 , V_111 ;
for ( V_55 = 0 ; V_55 < V_25 -> V_68 ; ++ V_55 ) {
struct V_220 * V_221 ;
struct V_69 * V_196 ;
unsigned V_222 ;
V_196 = & V_25 -> V_65 [ V_55 ] ;
if ( V_196 -> V_75 != V_81 )
continue;
V_221 = (struct V_220 * ) V_196 -> V_78 ;
V_222 = V_196 -> V_76 * 4 /
sizeof( struct V_220 ) ;
for ( V_195 = 0 ; V_195 < V_222 ; ++ V_195 ) {
struct V_6 * V_5 ;
struct V_223 * V_61 ;
struct V_187 * V_184 ;
V_111 = F_1 ( V_2 , V_221 [ V_195 ] . V_3 ,
V_221 [ V_195 ] . V_4 ,
V_221 [ V_195 ] . V_5 , & V_5 ) ;
if ( V_111 )
return V_111 ;
V_61 = F_13 ( V_45 , V_221 [ V_195 ] . V_62 ) ;
if ( V_61 == NULL )
return - V_8 ;
V_184 = F_89 ( V_61 , V_5 ,
V_221 [ V_195 ] . V_33 ) ;
if ( F_90 ( V_184 ) ) {
V_111 = F_91 ( V_184 ) ;
F_19 ( V_61 ) ;
return V_111 ;
} else if ( V_184 ) {
V_111 = F_76 ( V_2 , & V_25 -> V_82 -> V_181 ,
V_184 ) ;
F_71 ( V_184 ) ;
F_19 ( V_61 ) ;
if ( V_111 )
return V_111 ;
}
}
}
return 0 ;
}
static int F_92 ( struct V_24 * V_25 ,
union V_49 * V_50 )
{
struct V_6 * V_5 = V_25 -> V_82 -> V_5 ;
struct V_224 * V_225 = & V_25 -> V_61 -> V_226 [ V_5 -> V_227 ] . V_225 ;
struct V_228 * V_82 ;
int V_111 ;
V_82 = V_25 -> V_82 ;
V_25 -> V_82 = NULL ;
V_111 = F_93 ( & V_82 -> V_229 , & V_5 -> V_230 , V_225 , V_25 -> V_32 ) ;
if ( V_111 ) {
F_73 ( V_82 ) ;
return V_111 ;
}
V_82 -> V_231 = V_25 -> V_32 ;
V_82 -> V_232 = V_225 -> V_233 ;
V_25 -> V_184 = F_94 ( & V_82 -> V_229 . V_234 -> V_235 ) ;
V_50 -> V_236 . V_33 = F_95 ( V_25 -> V_61 , V_5 , V_25 -> V_184 ) ;
V_82 -> V_237 = V_50 -> V_236 . V_33 ;
F_96 ( V_82 ) ;
F_97 ( V_82 ) ;
F_98 ( & V_82 -> V_229 ) ;
return 0 ;
}
int F_99 ( struct V_238 * V_239 , void * V_27 , struct V_240 * V_32 )
{
struct V_1 * V_2 = V_239 -> V_241 ;
union V_49 * V_50 = V_27 ;
struct V_24 V_182 = {} ;
bool V_242 = false ;
int V_55 , V_111 ;
if ( ! V_2 -> V_243 )
return - V_244 ;
V_182 . V_2 = V_2 ;
V_182 . V_32 = V_32 ;
V_111 = F_11 ( & V_182 , V_27 ) ;
if ( V_111 ) {
F_2 ( L_18 ) ;
goto V_236;
}
V_111 = F_43 ( & V_182 , V_27 ) ;
if ( V_111 ) {
if ( V_111 == - V_60 )
F_2 ( L_19 ) ;
else if ( V_111 != - V_155 )
F_2 ( L_20 , V_111 ) ;
goto V_236;
}
V_242 = true ;
V_111 = F_83 ( V_2 , & V_182 ) ;
if ( V_111 )
goto V_236;
V_111 = F_88 ( V_2 , & V_182 ) ;
if ( V_111 ) {
F_2 ( L_21 , V_111 ) ;
goto V_236;
}
for ( V_55 = 0 ; V_55 < V_182 . V_82 -> V_53 ; V_55 ++ )
F_100 ( & V_182 , V_55 ) ;
V_111 = F_81 ( V_2 , & V_182 ) ;
if ( V_111 )
goto V_236;
V_111 = F_92 ( & V_182 , V_50 ) ;
V_236:
F_69 ( & V_182 , V_111 , V_242 ) ;
return V_111 ;
}
int F_101 ( struct V_238 * V_239 , void * V_27 ,
struct V_240 * V_32 )
{
union V_245 * V_246 = V_27 ;
struct V_1 * V_2 = V_239 -> V_241 ;
unsigned long V_247 = F_102 ( V_246 -> V_57 . V_247 ) ;
struct V_6 * V_5 = NULL ;
struct V_223 * V_61 ;
struct V_187 * V_184 ;
long V_111 ;
V_111 = F_1 ( V_2 , V_246 -> V_57 . V_3 , V_246 -> V_57 . V_4 ,
V_246 -> V_57 . V_5 , & V_5 ) ;
if ( V_111 )
return V_111 ;
V_61 = F_13 ( V_32 -> V_46 , V_246 -> V_57 . V_62 ) ;
if ( V_61 == NULL )
return - V_8 ;
V_184 = F_89 ( V_61 , V_5 , V_246 -> V_57 . V_33 ) ;
if ( F_90 ( V_184 ) )
V_111 = F_91 ( V_184 ) ;
else if ( V_184 ) {
V_111 = F_103 ( V_184 , true , V_247 ) ;
F_71 ( V_184 ) ;
} else
V_111 = 1 ;
F_19 ( V_61 ) ;
if ( V_111 < 0 )
return V_111 ;
memset ( V_246 , 0 , sizeof( * V_246 ) ) ;
V_246 -> V_236 . V_248 = ( V_111 == 0 ) ;
return 0 ;
}
static struct V_187 * F_104 ( struct V_1 * V_2 ,
struct V_240 * V_32 ,
struct V_249 * V_250 )
{
struct V_6 * V_5 ;
struct V_223 * V_61 ;
struct V_187 * V_184 ;
int V_111 ;
V_111 = F_1 ( V_2 , V_250 -> V_3 , V_250 -> V_4 ,
V_250 -> V_5 , & V_5 ) ;
if ( V_111 )
return F_105 ( V_111 ) ;
V_61 = F_13 ( V_32 -> V_46 , V_250 -> V_62 ) ;
if ( V_61 == NULL )
return F_105 ( - V_8 ) ;
V_184 = F_89 ( V_61 , V_5 , V_250 -> V_251 ) ;
F_19 ( V_61 ) ;
return V_184 ;
}
static int F_106 ( struct V_1 * V_2 ,
struct V_240 * V_32 ,
union V_252 * V_246 ,
struct V_249 * V_253 )
{
T_2 V_254 = V_246 -> V_57 . V_254 ;
unsigned int V_55 ;
long V_111 = 1 ;
for ( V_55 = 0 ; V_55 < V_254 ; V_55 ++ ) {
struct V_187 * V_184 ;
unsigned long V_247 = F_102 ( V_246 -> V_57 . V_255 ) ;
V_184 = F_104 ( V_2 , V_32 , & V_253 [ V_55 ] ) ;
if ( F_90 ( V_184 ) )
return F_91 ( V_184 ) ;
else if ( ! V_184 )
continue;
V_111 = F_103 ( V_184 , true , V_247 ) ;
if ( V_111 < 0 )
return V_111 ;
if ( V_111 == 0 )
break;
}
memset ( V_246 , 0 , sizeof( * V_246 ) ) ;
V_246 -> V_236 . V_248 = ( V_111 > 0 ) ;
return 0 ;
}
static int F_107 ( struct V_1 * V_2 ,
struct V_240 * V_32 ,
union V_252 * V_246 ,
struct V_249 * V_253 )
{
unsigned long V_247 = F_102 ( V_246 -> V_57 . V_255 ) ;
T_2 V_254 = V_246 -> V_57 . V_254 ;
T_2 V_256 = ~ 0 ;
struct V_187 * * V_157 ;
unsigned int V_55 ;
long V_111 ;
V_157 = F_108 ( V_254 , sizeof( struct V_187 * ) , V_59 ) ;
if ( V_157 == NULL )
return - V_60 ;
for ( V_55 = 0 ; V_55 < V_254 ; V_55 ++ ) {
struct V_187 * V_184 ;
V_184 = F_104 ( V_2 , V_32 , & V_253 [ V_55 ] ) ;
if ( F_90 ( V_184 ) ) {
V_111 = F_91 ( V_184 ) ;
goto V_257;
} else if ( V_184 ) {
V_157 [ V_55 ] = V_184 ;
} else {
V_111 = 1 ;
goto V_236;
}
}
V_111 = F_109 ( V_157 , V_254 , true , V_247 ,
& V_256 ) ;
if ( V_111 < 0 )
goto V_257;
V_236:
memset ( V_246 , 0 , sizeof( * V_246 ) ) ;
V_246 -> V_236 . V_248 = ( V_111 > 0 ) ;
V_246 -> V_236 . V_258 = V_256 ;
V_111 = 0 ;
V_257:
for ( V_55 = 0 ; V_55 < V_254 ; V_55 ++ )
F_71 ( V_157 [ V_55 ] ) ;
F_17 ( V_157 ) ;
return V_111 ;
}
int F_110 ( struct V_238 * V_239 , void * V_27 ,
struct V_240 * V_32 )
{
struct V_1 * V_2 = V_239 -> V_241 ;
union V_252 * V_246 = V_27 ;
T_2 V_254 = V_246 -> V_57 . V_254 ;
struct V_249 * V_259 ;
struct V_249 * V_253 ;
int V_111 ;
V_253 = F_12 ( V_254 , sizeof( struct V_249 ) ,
V_59 ) ;
if ( V_253 == NULL )
return - V_60 ;
V_259 = ( void V_64 * ) ( unsigned long ) ( V_246 -> V_57 . V_253 ) ;
if ( F_14 ( V_253 , V_259 ,
sizeof( struct V_249 ) * V_254 ) ) {
V_111 = - V_66 ;
goto V_260;
}
if ( V_246 -> V_57 . V_261 )
V_111 = F_106 ( V_2 , V_32 , V_246 , V_253 ) ;
else
V_111 = F_107 ( V_2 , V_32 , V_246 , V_253 ) ;
V_260:
F_17 ( V_253 ) ;
return V_111 ;
}
struct V_207 *
F_84 ( struct V_24 * V_182 ,
T_3 V_262 , struct V_107 * * V_38 )
{
struct V_207 * V_263 ;
unsigned V_55 ;
if ( ! V_182 -> V_147 )
return NULL ;
V_262 /= V_214 ;
for ( V_55 = 0 ; V_55 < V_182 -> V_147 -> V_150 ; V_55 ++ ) {
struct V_123 * V_131 ;
V_131 = & V_182 -> V_147 -> V_157 [ V_55 ] ;
if ( ! V_131 -> V_171 )
continue;
F_42 (mapping, &lobj->bo_va->valids, list) {
if ( V_263 -> V_212 . V_215 > V_262 ||
V_262 > V_263 -> V_212 . V_213 )
continue;
* V_38 = V_131 -> V_171 -> V_38 ;
return V_263 ;
}
F_42 (mapping, &lobj->bo_va->invalids, list) {
if ( V_263 -> V_212 . V_215 > V_262 ||
V_262 > V_263 -> V_212 . V_213 )
continue;
* V_38 = V_131 -> V_171 -> V_38 ;
return V_263 ;
}
}
return NULL ;
}
int F_111 ( struct V_24 * V_182 )
{
unsigned V_55 ;
int V_111 ;
if ( ! V_182 -> V_147 )
return 0 ;
for ( V_55 = 0 ; V_55 < V_182 -> V_147 -> V_150 ; V_55 ++ ) {
struct V_107 * V_38 = V_182 -> V_147 -> V_157 [ V_55 ] . V_35 ;
V_111 = F_64 ( & V_38 -> V_39 , & V_38 -> V_39 . V_126 ) ;
if ( F_35 ( V_111 ) )
return V_111 ;
if ( V_38 -> V_104 & V_264 )
continue;
V_38 -> V_104 |= V_264 ;
F_33 ( V_38 , V_38 -> V_116 ) ;
V_111 = F_34 ( & V_38 -> V_39 , & V_38 -> V_119 , false , false ) ;
if ( F_35 ( V_111 ) )
return V_111 ;
}
return 0 ;
}
