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
return 0 ;
}
static int F_3 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_30 * V_31 ;
T_2 V_32 ;
V_32 = V_29 -> V_32 ;
V_31 = F_4 ( V_25 -> V_2 -> V_33 , V_25 -> V_34 ,
V_29 -> V_32 ) ;
if ( V_31 == NULL )
return - V_8 ;
V_27 -> V_35 = F_5 ( F_6 ( V_31 ) ) ;
V_27 -> V_36 = V_29 -> V_36 ;
if ( F_7 ( V_27 -> V_35 -> V_37 . V_38 ) ) {
F_8 ( V_31 ) ;
return - V_8 ;
}
V_25 -> V_39 . V_40 = F_5 ( V_27 -> V_35 ) ;
V_25 -> V_39 . V_41 = 0 ;
V_25 -> V_39 . V_42 . V_35 = & V_25 -> V_39 . V_40 -> V_37 ;
V_25 -> V_39 . V_42 . V_43 = true ;
V_25 -> V_39 . V_44 = NULL ;
F_8 ( V_31 ) ;
return 0 ;
}
int F_9 ( struct V_24 * V_25 , void * V_45 )
{
struct V_46 * V_47 = V_25 -> V_34 -> V_48 ;
union V_49 * V_50 = V_45 ;
T_3 * V_51 ;
T_3 * V_52 ;
struct V_26 V_27 = {} ;
unsigned V_53 , V_54 = 0 ;
int V_55 ;
int V_56 ;
if ( V_50 -> V_57 . V_58 == 0 )
return 0 ;
V_52 = F_10 ( V_50 -> V_57 . V_58 , sizeof( T_3 ) , V_59 ) ;
if ( ! V_52 )
return - V_60 ;
V_25 -> V_61 = F_11 ( V_47 , V_50 -> V_57 . V_62 ) ;
if ( ! V_25 -> V_61 ) {
V_56 = - V_8 ;
goto V_63;
}
V_51 = ( T_3 V_64 * ) ( unsigned long ) ( V_50 -> V_57 . V_65 ) ;
if ( F_12 ( V_52 , V_51 ,
sizeof( T_3 ) * V_50 -> V_57 . V_58 ) ) {
V_56 = - V_66 ;
goto V_67;
}
V_25 -> V_68 = V_50 -> V_57 . V_58 ;
V_25 -> V_65 = F_10 ( V_25 -> V_68 , sizeof( struct V_69 ) ,
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
if ( F_12 ( & V_72 , V_71 ,
sizeof( struct V_70 ) ) ) {
V_56 = - V_66 ;
V_55 -- ;
goto V_74;
}
V_25 -> V_65 [ V_55 ] . V_75 = V_72 . V_75 ;
V_25 -> V_65 [ V_55 ] . V_76 = V_72 . V_76 ;
V_53 = V_25 -> V_65 [ V_55 ] . V_76 ;
V_73 = ( void V_64 * ) ( unsigned long ) V_72 . V_77 ;
V_25 -> V_65 [ V_55 ] . V_78 = F_13 ( V_53 , sizeof( T_2 ) ) ;
if ( V_25 -> V_65 [ V_55 ] . V_78 == NULL ) {
V_56 = - V_60 ;
V_55 -- ;
goto V_74;
}
V_53 *= sizeof( T_2 ) ;
if ( F_12 ( V_25 -> V_65 [ V_55 ] . V_78 , V_73 , V_53 ) ) {
V_56 = - V_66 ;
goto V_74;
}
switch ( V_25 -> V_65 [ V_55 ] . V_75 ) {
case V_79 :
++ V_54 ;
break;
case V_80 :
V_53 = sizeof( struct V_28 ) ;
if ( V_25 -> V_65 [ V_55 ] . V_76 * sizeof( T_2 ) < V_53 ) {
V_56 = - V_8 ;
goto V_74;
}
V_56 = F_3 ( V_25 , & V_27 , ( void * ) V_25 -> V_65 [ V_55 ] . V_78 ) ;
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
V_56 = F_14 ( V_25 -> V_2 , V_54 , & V_25 -> V_82 ) ;
if ( V_56 )
goto V_83;
V_25 -> V_82 -> V_27 = V_27 ;
F_15 ( V_52 ) ;
return 0 ;
V_83:
V_55 = V_25 -> V_68 - 1 ;
V_74:
for (; V_55 >= 0 ; V_55 -- )
F_16 ( V_25 -> V_65 [ V_55 ] . V_78 ) ;
F_15 ( V_25 -> V_65 ) ;
V_67:
F_17 ( V_25 -> V_61 ) ;
V_63:
F_15 ( V_52 ) ;
return V_56 ;
}
static T_4 F_18 ( struct V_1 * V_2 )
{
T_4 V_84 = V_2 -> V_85 . V_84 ;
T_4 V_86 = F_19 ( & V_2 -> V_86 ) ;
T_4 V_87 = V_84 >> 1 ;
T_4 V_88 = V_86 >= V_87 ? 0 : V_87 - V_86 ;
T_4 V_89 = V_88 >> 1 ;
return F_20 ( V_89 , 1024 * 1024ull ) ;
}
int F_21 ( struct V_24 * V_25 ,
struct V_90 * V_91 )
{
struct V_92 * V_93 ;
T_4 V_94 ;
int V_95 ;
F_22 (lobj, validated, tv.head) {
struct V_96 * V_35 = V_93 -> V_40 ;
bool V_97 = false ;
struct V_98 * V_99 ;
T_2 V_100 ;
V_99 = F_7 ( V_35 -> V_37 . V_38 ) ;
if ( V_99 && V_99 != V_101 -> V_102 )
return - V_103 ;
if ( V_93 -> V_44 && V_35 -> V_37 . V_38 -> V_104 != V_105 ) {
T_5 V_53 = sizeof( struct V_106 * ) ;
V_53 *= V_35 -> V_37 . V_38 -> V_107 ;
memcpy ( V_35 -> V_37 . V_38 -> V_108 , V_93 -> V_44 , V_53 ) ;
V_97 = true ;
}
if ( V_35 -> V_109 )
continue;
if ( V_25 -> V_110 <= V_25 -> V_89 )
V_100 = V_35 -> V_111 ;
else
V_100 = V_35 -> V_112 ;
V_113:
F_23 ( V_35 , V_100 ) ;
V_94 = F_19 ( & V_35 -> V_2 -> V_114 ) ;
V_95 = F_24 ( & V_35 -> V_37 , & V_35 -> V_115 , true , false ) ;
V_25 -> V_110 += F_19 ( & V_35 -> V_2 -> V_114 ) -
V_94 ;
if ( F_25 ( V_95 ) ) {
if ( V_95 != - V_116 && V_100 != V_35 -> V_112 ) {
V_100 = V_35 -> V_112 ;
goto V_113;
}
return V_95 ;
}
if ( V_97 ) {
F_16 ( V_93 -> V_44 ) ;
V_93 -> V_44 = NULL ;
}
}
return 0 ;
}
static int F_26 ( struct V_24 * V_25 ,
union V_49 * V_50 )
{
struct V_46 * V_47 = V_25 -> V_34 -> V_48 ;
struct V_92 * V_117 ;
struct V_90 V_118 ;
bool V_119 = false ;
unsigned V_55 , V_120 = 10 ;
int V_95 ;
F_27 ( & V_25 -> V_91 ) ;
V_25 -> V_121 = F_28 ( V_47 , V_50 -> V_57 . V_122 ) ;
if ( V_25 -> V_121 ) {
V_119 = V_25 -> V_121 -> V_123 !=
V_25 -> V_121 -> V_124 ;
F_29 ( V_25 -> V_121 , & V_25 -> V_91 ) ;
}
F_27 ( & V_118 ) ;
F_30 ( & V_47 -> V_125 , & V_25 -> V_91 , & V_25 -> V_126 ) ;
if ( V_25 -> V_82 -> V_27 . V_35 )
F_31 ( & V_25 -> V_39 . V_42 . V_127 , & V_25 -> V_91 ) ;
if ( V_119 )
F_32 ( & V_101 -> V_102 -> V_128 ) ;
while ( 1 ) {
struct V_90 V_129 ;
unsigned V_55 ;
V_95 = F_33 ( & V_25 -> V_130 , & V_25 -> V_91 , true ,
& V_118 ) ;
if ( F_25 ( V_95 != 0 ) )
goto V_131;
if ( ! V_25 -> V_121 )
break;
F_27 ( & V_129 ) ;
for ( V_55 = V_25 -> V_121 -> V_123 ;
V_55 < V_25 -> V_121 -> V_124 ; ++ V_55 ) {
V_117 = & V_25 -> V_121 -> V_132 [ V_55 ] ;
if ( F_34 ( V_117 -> V_40 -> V_37 . V_38 ,
& V_117 -> V_133 ) && V_117 -> V_44 ) {
F_35 ( V_117 -> V_44 ,
V_117 -> V_40 -> V_37 . V_38 -> V_107 ,
false ) ;
F_16 ( V_117 -> V_44 ) ;
V_117 -> V_44 = NULL ;
}
if ( V_117 -> V_40 -> V_37 . V_38 -> V_104 != V_105 &&
! V_117 -> V_44 ) {
F_36 ( & V_117 -> V_42 . V_127 ) ;
F_31 ( & V_117 -> V_42 . V_127 , & V_129 ) ;
F_37 ( V_117 -> V_40 ) ;
}
}
if ( F_38 ( & V_129 ) )
break;
F_39 ( & V_25 -> V_130 , & V_25 -> V_91 ) ;
if ( ! -- V_120 ) {
V_95 = - V_134 ;
goto V_131;
}
F_22 (e, &need_pages, tv.head) {
struct V_135 * V_38 = V_117 -> V_40 -> V_37 . V_38 ;
V_117 -> V_44 = F_40 ( V_38 -> V_107 ,
sizeof( struct V_106 * ) ) ;
if ( ! V_117 -> V_44 ) {
V_95 = - V_60 ;
goto V_131;
}
V_95 = F_41 ( V_38 , V_117 -> V_44 ) ;
if ( V_95 ) {
F_16 ( V_117 -> V_44 ) ;
V_117 -> V_44 = NULL ;
goto V_131;
}
}
F_42 ( & V_129 , & V_25 -> V_91 ) ;
}
F_43 ( & V_47 -> V_125 , & V_118 ) ;
V_25 -> V_89 = F_18 ( V_25 -> V_2 ) ;
V_25 -> V_110 = 0 ;
V_95 = F_21 ( V_25 , & V_118 ) ;
if ( V_95 )
goto V_136;
V_95 = F_21 ( V_25 , & V_25 -> V_91 ) ;
if ( V_95 )
goto V_136;
if ( V_25 -> V_121 ) {
struct V_137 * V_125 = & V_47 -> V_125 ;
unsigned V_55 ;
for ( V_55 = 0 ; V_55 < V_25 -> V_121 -> V_124 ; V_55 ++ ) {
struct V_96 * V_35 = V_25 -> V_121 -> V_132 [ V_55 ] . V_40 ;
V_25 -> V_121 -> V_132 [ V_55 ] . V_138 = F_44 ( V_125 , V_35 ) ;
}
}
V_136:
if ( V_95 ) {
F_45 ( V_25 -> V_2 , & V_47 -> V_125 ) ;
F_39 ( & V_25 -> V_130 , & V_25 -> V_91 ) ;
}
V_131:
if ( V_119 )
F_46 ( & V_101 -> V_102 -> V_128 ) ;
if ( V_25 -> V_121 ) {
for ( V_55 = V_25 -> V_121 -> V_123 ;
V_55 < V_25 -> V_121 -> V_124 ; ++ V_55 ) {
V_117 = & V_25 -> V_121 -> V_132 [ V_55 ] ;
if ( ! V_117 -> V_44 )
continue;
F_35 ( V_117 -> V_44 ,
V_117 -> V_40 -> V_37 . V_38 -> V_107 ,
false ) ;
F_16 ( V_117 -> V_44 ) ;
}
}
return V_95 ;
}
static int F_47 ( struct V_24 * V_25 )
{
struct V_92 * V_117 ;
int V_95 ;
F_22 (e, &p->validated, tv.head) {
struct V_139 * V_140 = V_117 -> V_40 -> V_37 . V_140 ;
V_95 = F_48 ( V_25 -> V_2 , & V_25 -> V_82 -> V_141 , V_140 , V_25 -> V_34 ) ;
if ( V_95 )
return V_95 ;
}
return 0 ;
}
static int F_49 ( void * V_142 , struct V_90 * V_143 ,
struct V_90 * V_144 )
{
struct V_92 * V_145 = F_50 ( V_143 , struct V_92 , V_42 . V_127 ) ;
struct V_92 * V_146 = F_50 ( V_144 , struct V_92 , V_42 . V_127 ) ;
return ( int ) V_145 -> V_40 -> V_37 . V_107 - ( int ) V_146 -> V_40 -> V_37 . V_107 ;
}
static void F_51 ( struct V_24 * V_147 , int error , bool V_148 )
{
struct V_46 * V_47 = V_147 -> V_34 -> V_48 ;
unsigned V_55 ;
if ( ! error ) {
F_45 ( V_147 -> V_2 , & V_47 -> V_125 ) ;
F_52 ( NULL , & V_147 -> V_91 , F_49 ) ;
F_53 ( & V_147 -> V_130 ,
& V_147 -> V_91 ,
V_147 -> V_149 ) ;
} else if ( V_148 ) {
F_39 ( & V_147 -> V_130 ,
& V_147 -> V_91 ) ;
}
F_54 ( V_147 -> V_149 ) ;
if ( V_147 -> V_61 )
F_17 ( V_147 -> V_61 ) ;
if ( V_147 -> V_121 )
F_55 ( V_147 -> V_121 ) ;
for ( V_55 = 0 ; V_55 < V_147 -> V_68 ; V_55 ++ )
F_16 ( V_147 -> V_65 [ V_55 ] . V_78 ) ;
F_15 ( V_147 -> V_65 ) ;
if ( V_147 -> V_82 )
F_56 ( V_147 -> V_82 ) ;
F_57 ( & V_147 -> V_39 . V_40 ) ;
}
static int F_58 ( struct V_24 * V_25 ,
struct V_137 * V_125 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
struct V_150 * V_138 ;
struct V_96 * V_35 ;
int V_55 , V_95 ;
V_95 = F_59 ( V_2 , V_125 ) ;
if ( V_95 )
return V_95 ;
V_95 = F_60 ( V_2 , & V_25 -> V_82 -> V_141 , V_125 -> V_151 ) ;
if ( V_95 )
return V_95 ;
V_95 = F_61 ( V_2 , V_125 ) ;
if ( V_95 )
return V_95 ;
if ( V_25 -> V_121 ) {
for ( V_55 = 0 ; V_55 < V_25 -> V_121 -> V_124 ; V_55 ++ ) {
struct V_149 * V_152 ;
V_35 = V_25 -> V_121 -> V_132 [ V_55 ] . V_40 ;
if ( ! V_35 )
continue;
V_138 = V_25 -> V_121 -> V_132 [ V_55 ] . V_138 ;
if ( V_138 == NULL )
continue;
V_95 = F_62 ( V_2 , V_138 , & V_35 -> V_37 . V_153 ) ;
if ( V_95 )
return V_95 ;
V_152 = V_138 -> V_154 ;
V_95 = F_60 ( V_2 , & V_25 -> V_82 -> V_141 , V_152 ) ;
if ( V_95 )
return V_95 ;
}
}
V_95 = F_63 ( V_2 , V_125 , & V_25 -> V_82 -> V_141 ) ;
if ( V_155 && V_25 -> V_121 ) {
for ( V_55 = 0 ; V_55 < V_25 -> V_121 -> V_124 ; V_55 ++ ) {
V_35 = V_25 -> V_121 -> V_132 [ V_55 ] . V_40 ;
if ( ! V_35 )
continue;
F_64 ( V_2 , V_35 ) ;
}
}
return V_95 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_46 * V_47 = V_25 -> V_34 -> V_48 ;
struct V_137 * V_125 = & V_47 -> V_125 ;
struct V_6 * V_5 = V_25 -> V_82 -> V_5 ;
int V_55 , V_95 ;
if ( V_5 -> V_156 -> V_157 ) {
for ( V_55 = 0 ; V_55 < V_25 -> V_82 -> V_54 ; V_55 ++ ) {
V_95 = F_66 ( V_5 , V_25 , V_55 ) ;
if ( V_95 )
return V_95 ;
}
}
V_95 = F_58 ( V_25 , V_125 ) ;
if ( ! V_95 )
F_47 ( V_25 ) ;
return V_95 ;
}
static int F_67 ( struct V_1 * V_2 , int V_95 )
{
if ( V_95 == - V_134 ) {
V_95 = F_68 ( V_2 ) ;
if ( ! V_95 )
V_95 = - V_158 ;
}
return V_95 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_24 * V_147 )
{
struct V_46 * V_47 = V_147 -> V_34 -> V_48 ;
struct V_137 * V_125 = & V_47 -> V_125 ;
int V_55 , V_159 ;
int V_95 ;
for ( V_55 = 0 , V_159 = 0 ; V_55 < V_147 -> V_68 && V_159 < V_147 -> V_82 -> V_54 ; V_55 ++ ) {
struct V_69 * V_160 ;
struct V_161 * V_162 ;
struct V_163 * V_164 ;
struct V_6 * V_5 ;
V_160 = & V_147 -> V_65 [ V_55 ] ;
V_162 = & V_147 -> V_82 -> V_165 [ V_159 ] ;
V_164 = (struct V_163 * ) V_160 -> V_78 ;
if ( V_160 -> V_75 != V_79 )
continue;
V_95 = F_1 ( V_2 , V_164 -> V_3 ,
V_164 -> V_4 , V_164 -> V_5 ,
& V_5 ) ;
if ( V_95 )
return V_95 ;
if ( V_147 -> V_82 -> V_5 && V_147 -> V_82 -> V_5 != V_5 )
return - V_8 ;
V_147 -> V_82 -> V_5 = V_5 ;
if ( V_5 -> V_156 -> V_157 ) {
struct V_166 * V_167 ;
struct V_96 * V_168 = NULL ;
T_3 V_36 ;
T_6 * V_169 ;
V_167 = F_70 ( V_147 , V_164 -> va_start ,
& V_168 ) ;
if ( ! V_168 ) {
F_2 ( L_7 ) ;
return - V_8 ;
}
if ( ( V_164 -> va_start + V_164 -> V_170 ) >
( V_167 -> V_171 . V_172 + 1 ) * V_173 ) {
F_2 ( L_8 ) ;
return - V_8 ;
}
V_95 = F_71 ( V_168 , ( void * * ) & V_169 ) ;
if ( V_95 ) {
return V_95 ;
}
V_36 = ( ( T_3 ) V_167 -> V_171 . V_174 ) * V_173 ;
V_169 += V_164 -> va_start - V_36 ;
V_95 = F_72 ( V_2 , NULL , V_164 -> V_170 , V_162 ) ;
if ( V_95 ) {
F_2 ( L_9 ) ;
return V_95 ;
}
memcpy ( V_162 -> V_175 , V_169 , V_164 -> V_170 ) ;
F_73 ( V_168 ) ;
} else {
V_95 = F_72 ( V_2 , V_125 , 0 , V_162 ) ;
if ( V_95 ) {
F_2 ( L_9 ) ;
return V_95 ;
}
V_162 -> V_176 = V_164 -> va_start ;
}
V_162 -> V_76 = V_164 -> V_170 / 4 ;
V_162 -> V_177 = V_164 -> V_177 ;
V_162 -> V_61 = V_147 -> V_61 ;
V_159 ++ ;
}
if ( V_147 -> V_121 ) {
struct V_96 * V_178 = V_147 -> V_121 -> V_179 ;
struct V_96 * V_180 = V_147 -> V_121 -> V_181 ;
struct V_96 * V_182 = V_147 -> V_121 -> V_183 ;
struct V_161 * V_162 = & V_147 -> V_82 -> V_165 [ 0 ] ;
if ( V_178 ) {
V_162 -> V_184 = F_74 ( V_178 ) ;
V_162 -> V_185 = F_75 ( V_178 ) ;
}
if ( V_180 ) {
V_162 -> V_186 = F_74 ( V_180 ) ;
V_162 -> V_187 = F_75 ( V_180 ) ;
}
if ( V_182 ) {
V_162 -> V_188 = F_74 ( V_182 ) ;
V_162 -> V_189 = F_75 ( V_182 ) ;
}
}
if ( V_147 -> V_82 -> V_27 . V_35 ) {
struct V_161 * V_162 = & V_147 -> V_82 -> V_165 [ V_147 -> V_82 -> V_54 - 1 ] ;
if ( V_147 -> V_82 -> V_5 -> type == V_190 ||
V_147 -> V_82 -> V_5 -> type == V_191 )
return - V_8 ;
V_162 -> V_192 = & V_147 -> V_82 -> V_27 ;
}
return 0 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_46 * V_47 = V_25 -> V_34 -> V_48 ;
int V_55 , V_159 , V_95 ;
for ( V_55 = 0 ; V_55 < V_25 -> V_68 ; ++ V_55 ) {
struct V_193 * V_194 ;
struct V_69 * V_160 ;
unsigned V_195 ;
V_160 = & V_25 -> V_65 [ V_55 ] ;
if ( V_160 -> V_75 != V_81 )
continue;
V_194 = (struct V_193 * ) V_160 -> V_78 ;
V_195 = V_160 -> V_76 * 4 /
sizeof( struct V_193 ) ;
for ( V_159 = 0 ; V_159 < V_195 ; ++ V_159 ) {
struct V_6 * V_5 ;
struct V_196 * V_61 ;
struct V_149 * V_149 ;
V_95 = F_1 ( V_2 , V_194 [ V_159 ] . V_3 ,
V_194 [ V_159 ] . V_4 ,
V_194 [ V_159 ] . V_5 , & V_5 ) ;
if ( V_95 )
return V_95 ;
V_61 = F_11 ( V_47 , V_194 [ V_159 ] . V_62 ) ;
if ( V_61 == NULL )
return - V_8 ;
V_149 = F_77 ( V_61 , V_5 ,
V_194 [ V_159 ] . V_32 ) ;
if ( F_78 ( V_149 ) ) {
V_95 = F_79 ( V_149 ) ;
F_17 ( V_61 ) ;
return V_95 ;
} else if ( V_149 ) {
V_95 = F_60 ( V_2 , & V_25 -> V_82 -> V_141 ,
V_149 ) ;
F_54 ( V_149 ) ;
F_17 ( V_61 ) ;
if ( V_95 )
return V_95 ;
}
}
}
return 0 ;
}
static int F_80 ( struct V_24 * V_25 ,
union V_49 * V_50 )
{
struct V_6 * V_5 = V_25 -> V_82 -> V_5 ;
struct V_197 * V_149 ;
struct V_198 * V_82 ;
V_82 = V_25 -> V_82 ;
V_25 -> V_82 = NULL ;
V_82 -> V_199 . V_200 = & V_5 -> V_200 ;
V_82 -> V_199 . V_201 = & V_25 -> V_61 -> V_202 [ V_5 -> V_203 ] . V_204 ;
V_82 -> V_205 = V_25 -> V_34 ;
V_149 = F_81 ( V_82 -> V_199 . V_201 , V_25 -> V_34 ) ;
if ( ! V_149 ) {
F_56 ( V_82 ) ;
return - V_60 ;
}
V_82 -> V_199 . V_206 = V_149 ;
V_25 -> V_149 = F_82 ( & V_149 -> V_199 ) ;
V_50 -> V_207 . V_32 = F_83 ( V_25 -> V_61 , V_5 ,
& V_149 -> V_199 ) ;
V_82 -> V_165 [ V_82 -> V_54 - 1 ] . V_208 = V_50 -> V_207 . V_32 ;
F_84 ( V_82 ) ;
F_85 ( & V_82 -> V_199 ) ;
return 0 ;
}
int F_86 ( struct V_209 * V_210 , void * V_45 , struct V_211 * V_34 )
{
struct V_1 * V_2 = V_210 -> V_212 ;
union V_49 * V_50 = V_45 ;
struct V_24 V_147 = {} ;
bool V_213 = false ;
int V_55 , V_95 ;
if ( ! V_2 -> V_214 )
return - V_215 ;
V_147 . V_2 = V_2 ;
V_147 . V_34 = V_34 ;
V_95 = F_9 ( & V_147 , V_45 ) ;
if ( V_95 ) {
F_2 ( L_10 ) ;
F_51 ( & V_147 , V_95 , false ) ;
V_95 = F_67 ( V_2 , V_95 ) ;
return V_95 ;
}
V_95 = F_26 ( & V_147 , V_45 ) ;
if ( V_95 == - V_60 )
F_2 ( L_11 ) ;
else if ( V_95 && V_95 != - V_116 )
F_2 ( L_12 , V_95 ) ;
else if ( ! V_95 ) {
V_213 = true ;
V_95 = F_69 ( V_2 , & V_147 ) ;
}
if ( ! V_95 ) {
V_95 = F_76 ( V_2 , & V_147 ) ;
if ( V_95 )
F_2 ( L_13 , V_95 ) ;
}
if ( V_95 )
goto V_207;
for ( V_55 = 0 ; V_55 < V_147 . V_82 -> V_54 ; V_55 ++ )
F_87 ( & V_147 , V_55 ) ;
V_95 = F_65 ( V_2 , & V_147 ) ;
if ( V_95 )
goto V_207;
V_95 = F_80 ( & V_147 , V_50 ) ;
V_207:
F_51 ( & V_147 , V_95 , V_213 ) ;
V_95 = F_67 ( V_2 , V_95 ) ;
return V_95 ;
}
int F_88 ( struct V_209 * V_210 , void * V_45 ,
struct V_211 * V_34 )
{
union V_216 * V_217 = V_45 ;
struct V_1 * V_2 = V_210 -> V_212 ;
unsigned long V_218 = F_89 ( V_217 -> V_57 . V_218 ) ;
struct V_6 * V_5 = NULL ;
struct V_196 * V_61 ;
struct V_149 * V_149 ;
long V_95 ;
V_95 = F_1 ( V_2 , V_217 -> V_57 . V_3 , V_217 -> V_57 . V_4 ,
V_217 -> V_57 . V_5 , & V_5 ) ;
if ( V_95 )
return V_95 ;
V_61 = F_11 ( V_34 -> V_48 , V_217 -> V_57 . V_62 ) ;
if ( V_61 == NULL )
return - V_8 ;
V_149 = F_77 ( V_61 , V_5 , V_217 -> V_57 . V_32 ) ;
if ( F_78 ( V_149 ) )
V_95 = F_79 ( V_149 ) ;
else if ( V_149 ) {
V_95 = F_90 ( V_149 , true , V_218 ) ;
F_54 ( V_149 ) ;
} else
V_95 = 1 ;
F_17 ( V_61 ) ;
if ( V_95 < 0 )
return V_95 ;
memset ( V_217 , 0 , sizeof( * V_217 ) ) ;
V_217 -> V_207 . V_219 = ( V_95 == 0 ) ;
return 0 ;
}
struct V_166 *
F_70 ( struct V_24 * V_147 ,
T_3 V_220 , struct V_96 * * V_35 )
{
struct V_166 * V_221 ;
unsigned V_55 ;
if ( ! V_147 -> V_121 )
return NULL ;
V_220 /= V_173 ;
for ( V_55 = 0 ; V_55 < V_147 -> V_121 -> V_124 ; V_55 ++ ) {
struct V_92 * V_93 ;
V_93 = & V_147 -> V_121 -> V_132 [ V_55 ] ;
if ( ! V_93 -> V_138 )
continue;
F_22 (mapping, &lobj->bo_va->valids, list) {
if ( V_221 -> V_171 . V_174 > V_220 ||
V_220 > V_221 -> V_171 . V_172 )
continue;
* V_35 = V_93 -> V_138 -> V_35 ;
return V_221 ;
}
F_22 (mapping, &lobj->bo_va->invalids, list) {
if ( V_221 -> V_171 . V_174 > V_220 ||
V_220 > V_221 -> V_171 . V_172 )
continue;
* V_35 = V_93 -> V_138 -> V_35 ;
return V_221 ;
}
}
return NULL ;
}
