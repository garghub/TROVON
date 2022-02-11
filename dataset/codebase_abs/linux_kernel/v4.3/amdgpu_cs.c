static void F_1 ( struct V_1 * V_2 )
{
unsigned V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ )
F_2 ( & V_2 -> V_5 [ V_3 ] ) ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_6 * V_7 , unsigned V_8 )
{
F_4 ( V_7 , & V_2 -> V_5 [ F_5 ( V_8 , V_9 ) ] ) ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_6 * V_10 )
{
unsigned V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
F_7 ( & V_2 -> V_5 [ V_3 ] , V_10 ) ;
}
}
int F_8 ( struct V_11 * V_12 , T_1 V_13 ,
T_1 V_14 , T_1 V_15 ,
struct V_16 * * V_17 )
{
if ( V_14 != 0 ) {
F_9 ( L_1 , V_14 ) ;
return - V_18 ;
}
switch ( V_13 ) {
default:
F_9 ( L_2 , V_13 ) ;
return - V_18 ;
case V_19 :
if ( V_15 < V_12 -> V_20 . V_21 ) {
* V_17 = & V_12 -> V_20 . V_22 [ V_15 ] ;
} else {
F_9 ( L_3 ,
V_12 -> V_20 . V_21 ) ;
return - V_18 ;
}
break;
case V_23 :
if ( V_15 < V_12 -> V_20 . V_24 ) {
* V_17 = & V_12 -> V_20 . V_25 [ V_15 ] ;
} else {
F_9 ( L_4 ,
V_12 -> V_20 . V_24 ) ;
return - V_18 ;
}
break;
case V_26 :
if ( V_15 < 2 ) {
* V_17 = & V_12 -> V_27 [ V_15 ] . V_15 ;
} else {
F_9 ( L_5 ) ;
return - V_18 ;
}
break;
case V_28 :
* V_17 = & V_12 -> V_29 . V_15 ;
break;
case V_30 :
if ( V_15 < 2 ) {
* V_17 = & V_12 -> V_31 . V_15 [ V_15 ] ;
} else {
F_9 ( L_6 ) ;
return - V_18 ;
}
break;
}
return 0 ;
}
struct V_32 * F_10 ( struct V_11 * V_12 ,
struct V_33 * V_34 ,
struct V_35 * V_36 ,
struct V_37 * V_38 ,
T_2 V_39 )
{
struct V_32 * V_40 ;
int V_3 ;
V_40 = F_11 ( sizeof( struct V_32 ) , V_41 ) ;
if ( ! V_40 )
return NULL ;
V_40 -> V_12 = V_12 ;
V_40 -> V_34 = V_34 ;
V_40 -> V_36 = V_36 ;
V_40 -> V_38 = V_38 ;
V_40 -> V_39 = V_39 ;
for ( V_3 = 0 ; V_3 < V_39 ; V_3 ++ )
V_38 [ V_3 ] . V_36 = V_36 ;
return V_40 ;
}
int F_12 ( struct V_32 * V_42 , void * V_43 )
{
union V_44 * V_45 = V_43 ;
T_3 * V_46 ;
T_3 * V_47 ;
struct V_48 * V_49 = V_42 -> V_34 -> V_50 ;
unsigned V_51 ;
int V_3 ;
int V_52 ;
if ( V_45 -> V_53 . V_54 == 0 )
return 0 ;
V_47 = F_13 ( V_45 -> V_53 . V_54 , sizeof( T_3 ) , V_41 ) ;
if ( ! V_47 )
return - V_55 ;
V_42 -> V_36 = F_14 ( V_49 , V_45 -> V_53 . V_56 ) ;
if ( ! V_42 -> V_36 ) {
V_52 = - V_18 ;
goto V_57;
}
V_42 -> V_58 = F_15 ( V_49 , V_45 -> V_53 . V_59 ) ;
F_2 ( & V_42 -> V_60 ) ;
V_46 = ( T_3 V_61 * ) ( unsigned long ) ( V_45 -> V_53 . V_62 ) ;
if ( F_16 ( V_47 , V_46 ,
sizeof( T_3 ) * V_45 -> V_53 . V_54 ) ) {
V_52 = - V_63 ;
goto V_64;
}
V_42 -> V_65 = V_45 -> V_53 . V_54 ;
V_42 -> V_62 = F_13 ( V_42 -> V_65 , sizeof( struct V_66 ) ,
V_41 ) ;
if ( ! V_42 -> V_62 ) {
V_52 = - V_55 ;
goto V_64;
}
for ( V_3 = 0 ; V_3 < V_42 -> V_65 ; V_3 ++ ) {
struct V_67 V_61 * * V_68 = NULL ;
struct V_67 V_69 ;
T_2 V_61 * V_70 ;
V_68 = ( void V_61 * ) ( unsigned long ) V_47 [ V_3 ] ;
if ( F_16 ( & V_69 , V_68 ,
sizeof( struct V_67 ) ) ) {
V_52 = - V_63 ;
V_3 -- ;
goto V_71;
}
V_42 -> V_62 [ V_3 ] . V_72 = V_69 . V_72 ;
V_42 -> V_62 [ V_3 ] . V_73 = V_69 . V_73 ;
V_51 = V_42 -> V_62 [ V_3 ] . V_73 ;
V_70 = ( void V_61 * ) ( unsigned long ) V_69 . V_74 ;
V_42 -> V_62 [ V_3 ] . V_75 = V_70 ;
V_42 -> V_62 [ V_3 ] . V_76 = F_17 ( V_51 , sizeof( T_2 ) ) ;
if ( V_42 -> V_62 [ V_3 ] . V_76 == NULL ) {
V_52 = - V_55 ;
V_3 -- ;
goto V_71;
}
V_51 *= sizeof( T_2 ) ;
if ( F_16 ( V_42 -> V_62 [ V_3 ] . V_76 , V_70 , V_51 ) ) {
V_52 = - V_63 ;
goto V_71;
}
switch ( V_42 -> V_62 [ V_3 ] . V_72 ) {
case V_77 :
V_42 -> V_39 ++ ;
break;
case V_78 :
V_51 = sizeof( struct V_79 ) ;
if ( V_42 -> V_62 [ V_3 ] . V_73 * sizeof( T_2 ) >= V_51 ) {
T_2 V_80 ;
struct V_81 * V_82 ;
struct V_79 * V_83 ;
V_83 = ( void * ) V_42 -> V_62 [ V_3 ] . V_76 ;
V_80 = V_83 -> V_80 ;
V_82 = F_18 ( V_42 -> V_12 -> V_84 ,
V_42 -> V_34 , V_80 ) ;
if ( V_82 == NULL ) {
V_52 = - V_18 ;
goto V_71;
}
V_42 -> V_85 . V_86 = F_19 ( V_82 ) ;
V_42 -> V_85 . V_87 = V_83 -> V_87 ;
} else {
V_52 = - V_18 ;
goto V_71;
}
break;
case V_88 :
break;
default:
V_52 = - V_18 ;
goto V_71;
}
}
V_42 -> V_38 = F_20 ( V_42 -> V_39 , sizeof( struct V_37 ) , V_41 ) ;
if ( ! V_42 -> V_38 ) {
V_52 = - V_55 ;
goto V_89;
}
F_21 ( V_47 ) ;
return 0 ;
V_89:
V_3 = V_42 -> V_65 - 1 ;
V_71:
for (; V_3 >= 0 ; V_3 -- )
F_22 ( V_42 -> V_62 [ V_3 ] . V_76 ) ;
F_21 ( V_42 -> V_62 ) ;
V_64:
if ( V_42 -> V_58 )
F_23 ( V_42 -> V_58 ) ;
F_24 ( V_42 -> V_36 ) ;
V_57:
F_21 ( V_47 ) ;
return V_52 ;
}
static T_4 F_25 ( struct V_11 * V_12 )
{
T_4 V_90 = V_12 -> V_91 . V_90 ;
T_4 V_92 = F_26 ( & V_12 -> V_92 ) ;
T_4 V_93 = V_90 >> 1 ;
T_4 V_94 = V_92 >= V_93 ? 0 : V_93 - V_92 ;
T_4 V_95 = V_94 >> 1 ;
return F_27 ( V_95 , 1024 * 1024ull ) ;
}
int F_28 ( struct V_11 * V_12 ,
struct V_96 * V_97 ,
struct V_6 * V_60 )
{
struct V_98 * V_99 ;
struct V_100 * V_86 ;
T_4 V_101 = 0 , V_102 ;
T_4 V_95 = F_25 ( V_12 ) ;
int V_103 ;
F_29 (lobj, validated, tv.head) {
V_86 = V_99 -> V_104 ;
if ( ! V_86 -> V_105 ) {
T_1 V_106 = V_99 -> V_107 ;
T_1 V_108 =
F_30 ( V_86 -> V_109 . V_110 . V_111 ) ;
if ( ( V_99 -> V_112 & V_108 ) != 0 &&
( V_106 & V_108 ) == 0 &&
V_101 > V_95 ) {
V_106 = V_108 ;
}
V_113:
F_31 ( V_86 , V_106 ) ;
V_102 = F_26 ( & V_12 -> V_114 ) ;
V_103 = F_32 ( & V_86 -> V_109 , & V_86 -> V_115 , true , false ) ;
V_101 += F_26 ( & V_12 -> V_114 ) -
V_102 ;
if ( F_33 ( V_103 ) ) {
if ( V_103 != - V_116 && V_106 != V_99 -> V_112 ) {
V_106 = V_99 -> V_112 ;
goto V_113;
}
return V_103 ;
}
}
V_99 -> V_117 = F_34 ( V_97 , V_86 ) ;
}
return 0 ;
}
static int F_35 ( struct V_32 * V_42 )
{
struct V_48 * V_49 = V_42 -> V_34 -> V_50 ;
struct V_1 V_118 ;
struct V_6 V_119 ;
bool V_120 = false ;
int V_3 , V_103 ;
if ( V_42 -> V_58 ) {
V_120 = V_42 -> V_58 -> V_121 ;
F_1 ( & V_118 ) ;
for ( V_3 = 0 ; V_3 < V_42 -> V_58 -> V_122 ; V_3 ++ )
F_3 ( & V_118 , & V_42 -> V_58 -> V_123 [ V_3 ] . V_124 . V_125 ,
V_42 -> V_58 -> V_123 [ V_3 ] . V_8 ) ;
F_6 ( & V_118 , & V_42 -> V_60 ) ;
}
V_42 -> V_126 = F_36 ( V_42 -> V_12 , & V_49 -> V_97 ,
& V_42 -> V_60 ) ;
if ( V_120 )
F_37 ( & V_127 -> V_128 -> V_129 ) ;
F_2 ( & V_119 ) ;
V_103 = F_38 ( & V_42 -> V_130 , & V_42 -> V_60 , true , & V_119 ) ;
if ( F_33 ( V_103 != 0 ) )
goto V_131;
V_103 = F_28 ( V_42 -> V_12 , & V_49 -> V_97 , & V_42 -> V_60 ) ;
if ( V_103 )
goto V_132;
V_103 = F_28 ( V_42 -> V_12 , & V_49 -> V_97 , & V_119 ) ;
V_132:
if ( V_103 )
F_39 ( & V_42 -> V_130 , & V_42 -> V_60 ) ;
V_131:
if ( V_120 )
F_40 ( & V_127 -> V_128 -> V_129 ) ;
return V_103 ;
}
static int F_41 ( struct V_32 * V_42 )
{
struct V_98 * V_133 ;
int V_103 ;
F_29 (e, &p->validated, tv.head) {
struct V_134 * V_135 = V_133 -> V_104 -> V_109 . V_135 ;
V_103 = F_42 ( V_42 -> V_12 , & V_42 -> V_38 [ 0 ] . V_136 , V_135 , V_42 -> V_34 ) ;
if ( V_103 )
return V_103 ;
}
return 0 ;
}
static int F_43 ( void * V_137 , struct V_6 * V_138 ,
struct V_6 * V_2 )
{
struct V_98 * V_139 = F_44 ( V_138 , struct V_98 , V_124 . V_125 ) ;
struct V_98 * V_140 = F_44 ( V_2 , struct V_98 , V_124 . V_125 ) ;
return ( int ) V_139 -> V_104 -> V_109 . V_141 - ( int ) V_140 -> V_104 -> V_109 . V_141 ;
}
static void F_45 ( struct V_32 * V_40 , int error , bool V_142 )
{
if ( ! error ) {
F_46 ( NULL , & V_40 -> V_60 , F_43 ) ;
F_47 ( & V_40 -> V_130 ,
& V_40 -> V_60 ,
& V_40 -> V_38 [ V_40 -> V_39 - 1 ] . V_143 -> V_144 ) ;
} else if ( V_142 ) {
F_39 ( & V_40 -> V_130 ,
& V_40 -> V_60 ) ;
}
}
static void F_48 ( struct V_32 * V_40 )
{
unsigned V_3 ;
if ( V_40 -> V_36 )
F_24 ( V_40 -> V_36 ) ;
if ( V_40 -> V_58 )
F_23 ( V_40 -> V_58 ) ;
F_22 ( V_40 -> V_126 ) ;
for ( V_3 = 0 ; V_3 < V_40 -> V_65 ; V_3 ++ )
F_22 ( V_40 -> V_62 [ V_3 ] . V_76 ) ;
F_21 ( V_40 -> V_62 ) ;
if ( ! V_145 )
{
if ( V_40 -> V_38 )
for ( V_3 = 0 ; V_3 < V_40 -> V_39 ; V_3 ++ )
F_49 ( V_40 -> V_12 , & V_40 -> V_38 [ V_3 ] ) ;
F_21 ( V_40 -> V_38 ) ;
if ( V_40 -> V_85 . V_86 )
F_50 ( & V_40 -> V_85 . V_86 -> V_146 ) ;
}
F_21 ( V_40 ) ;
}
static void F_51 ( struct V_32 * V_40 , int error , bool V_142 )
{
F_45 ( V_40 , error , V_142 ) ;
F_48 ( V_40 ) ;
}
static int F_52 ( struct V_32 * V_42 ,
struct V_96 * V_97 )
{
struct V_11 * V_12 = V_42 -> V_12 ;
struct V_147 * V_117 ;
struct V_100 * V_86 ;
int V_3 , V_103 ;
V_103 = F_53 ( V_12 , V_97 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_54 ( V_12 , & V_42 -> V_38 [ 0 ] . V_136 , V_97 -> V_148 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_55 ( V_12 , V_97 ) ;
if ( V_103 )
return V_103 ;
if ( V_42 -> V_58 ) {
for ( V_3 = 0 ; V_3 < V_42 -> V_58 -> V_122 ; V_3 ++ ) {
struct V_143 * V_149 ;
V_86 = V_42 -> V_58 -> V_123 [ V_3 ] . V_104 ;
if ( ! V_86 )
continue;
V_117 = V_42 -> V_58 -> V_123 [ V_3 ] . V_117 ;
if ( V_117 == NULL )
continue;
V_103 = F_56 ( V_12 , V_117 , & V_86 -> V_109 . V_110 ) ;
if ( V_103 )
return V_103 ;
V_149 = V_117 -> V_150 ;
V_103 = F_54 ( V_12 , & V_42 -> V_38 [ 0 ] . V_136 , V_149 ) ;
if ( V_103 )
return V_103 ;
}
}
return F_57 ( V_12 , V_97 , & V_42 -> V_38 [ 0 ] . V_136 ) ;
}
static int F_58 ( struct V_11 * V_12 ,
struct V_32 * V_40 )
{
struct V_48 * V_49 = V_40 -> V_34 -> V_50 ;
struct V_96 * V_97 = & V_49 -> V_97 ;
struct V_16 * V_15 ;
int V_3 , V_103 ;
if ( V_40 -> V_39 == 0 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_40 -> V_39 ; V_3 ++ ) {
V_15 = V_40 -> V_38 [ V_3 ] . V_15 ;
if ( V_15 -> V_151 -> V_152 ) {
V_103 = F_59 ( V_15 , V_40 , V_3 ) ;
if ( V_103 )
return V_103 ;
}
}
F_60 ( & V_97 -> V_153 ) ;
V_103 = F_52 ( V_40 , V_97 ) ;
if ( V_103 ) {
goto V_154;
}
F_41 ( V_40 ) ;
if ( ! V_145 )
V_103 = F_61 ( V_12 , V_40 -> V_39 , V_40 -> V_38 ,
V_40 -> V_34 ) ;
V_154:
F_62 ( & V_97 -> V_153 ) ;
return V_103 ;
}
static int F_63 ( struct V_11 * V_12 , int V_103 )
{
if ( V_103 == - V_155 ) {
V_103 = F_64 ( V_12 ) ;
if ( ! V_103 )
V_103 = - V_156 ;
}
return V_103 ;
}
static int F_65 ( struct V_11 * V_12 ,
struct V_32 * V_40 )
{
struct V_48 * V_49 = V_40 -> V_34 -> V_50 ;
struct V_96 * V_97 = & V_49 -> V_97 ;
int V_3 , V_157 ;
int V_103 ;
for ( V_3 = 0 , V_157 = 0 ; V_3 < V_40 -> V_65 && V_157 < V_40 -> V_39 ; V_3 ++ ) {
struct V_66 * V_158 ;
struct V_37 * V_159 ;
struct V_160 * V_161 ;
struct V_16 * V_15 ;
V_158 = & V_40 -> V_62 [ V_3 ] ;
V_159 = & V_40 -> V_38 [ V_157 ] ;
V_161 = (struct V_160 * ) V_158 -> V_76 ;
if ( V_158 -> V_72 != V_77 )
continue;
V_103 = F_8 ( V_12 , V_161 -> V_13 ,
V_161 -> V_14 , V_161 -> V_15 ,
& V_15 ) ;
if ( V_103 )
return V_103 ;
if ( V_15 -> V_151 -> V_152 ) {
struct V_162 * V_163 ;
struct V_100 * V_164 = NULL ;
T_3 V_87 ;
T_5 * V_165 ;
V_163 = F_66 ( V_40 , V_161 -> va_start ,
& V_164 ) ;
if ( ! V_164 ) {
F_9 ( L_7 ) ;
return - V_18 ;
}
if ( ( V_161 -> va_start + V_161 -> V_166 ) >
( V_163 -> V_167 . V_168 + 1 ) * V_169 ) {
F_9 ( L_8 ) ;
return - V_18 ;
}
V_103 = F_67 ( V_164 , ( void * * ) & V_165 ) ;
if ( V_103 ) {
return V_103 ;
}
V_87 = ( ( T_3 ) V_163 -> V_167 . V_170 ) * V_169 ;
V_165 += V_161 -> va_start - V_87 ;
V_103 = F_68 ( V_15 , NULL , V_161 -> V_166 , V_159 ) ;
if ( V_103 ) {
F_9 ( L_9 ) ;
return V_103 ;
}
memcpy ( V_159 -> V_171 , V_165 , V_161 -> V_166 ) ;
F_69 ( V_164 ) ;
} else {
V_103 = F_68 ( V_15 , V_97 , 0 , V_159 ) ;
if ( V_103 ) {
F_9 ( L_9 ) ;
return V_103 ;
}
V_159 -> V_172 = V_161 -> va_start ;
}
V_159 -> V_73 = V_161 -> V_166 / 4 ;
V_159 -> V_173 = V_161 -> V_173 ;
V_159 -> V_36 = V_40 -> V_36 ;
V_157 ++ ;
}
if ( ! V_40 -> V_39 )
return 0 ;
if ( V_40 -> V_58 ) {
struct V_100 * V_174 = V_40 -> V_58 -> V_175 ;
struct V_100 * V_176 = V_40 -> V_58 -> V_177 ;
struct V_100 * V_178 = V_40 -> V_58 -> V_179 ;
struct V_37 * V_159 = & V_40 -> V_38 [ 0 ] ;
if ( V_174 ) {
V_159 -> V_180 = F_70 ( V_174 ) ;
V_159 -> V_181 = F_71 ( V_174 ) ;
}
if ( V_176 ) {
V_159 -> V_182 = F_70 ( V_176 ) ;
V_159 -> V_183 = F_71 ( V_176 ) ;
}
if ( V_178 ) {
V_159 -> V_184 = F_70 ( V_178 ) ;
V_159 -> V_185 = F_71 ( V_178 ) ;
}
}
if ( V_40 -> V_85 . V_86 ) {
struct V_37 * V_159 = & V_40 -> V_38 [ V_40 -> V_39 - 1 ] ;
if ( V_159 -> V_15 -> type == V_186 ||
V_159 -> V_15 -> type == V_187 )
return - V_18 ;
V_159 -> V_188 = & V_40 -> V_85 ;
}
return 0 ;
}
static int F_72 ( struct V_11 * V_12 ,
struct V_32 * V_42 )
{
struct V_48 * V_49 = V_42 -> V_34 -> V_50 ;
struct V_37 * V_159 ;
int V_3 , V_157 , V_103 ;
if ( ! V_42 -> V_39 )
return 0 ;
V_159 = & V_42 -> V_38 [ 0 ] ;
for ( V_3 = 0 ; V_3 < V_42 -> V_65 ; ++ V_3 ) {
struct V_189 * V_190 ;
struct V_66 * V_158 ;
unsigned V_191 ;
V_158 = & V_42 -> V_62 [ V_3 ] ;
if ( V_158 -> V_72 != V_88 )
continue;
V_190 = (struct V_189 * ) V_158 -> V_76 ;
V_191 = V_158 -> V_73 * 4 /
sizeof( struct V_189 ) ;
for ( V_157 = 0 ; V_157 < V_191 ; ++ V_157 ) {
struct V_16 * V_15 ;
struct V_35 * V_36 ;
struct V_143 * V_143 ;
V_103 = F_8 ( V_12 , V_190 [ V_157 ] . V_13 ,
V_190 [ V_157 ] . V_14 ,
V_190 [ V_157 ] . V_15 , & V_15 ) ;
if ( V_103 )
return V_103 ;
V_36 = F_14 ( V_49 , V_190 [ V_157 ] . V_56 ) ;
if ( V_36 == NULL )
return - V_18 ;
V_143 = F_73 ( V_36 , V_15 ,
V_190 [ V_157 ] . V_80 ) ;
if ( F_74 ( V_143 ) ) {
V_103 = F_75 ( V_143 ) ;
F_24 ( V_36 ) ;
return V_103 ;
} else if ( V_143 ) {
V_103 = F_54 ( V_12 , & V_159 -> V_136 , V_143 ) ;
F_76 ( V_143 ) ;
F_24 ( V_36 ) ;
if ( V_103 )
return V_103 ;
}
}
}
return 0 ;
}
static int F_77 ( struct V_192 * V_193 )
{
int V_3 ;
if ( V_193 -> V_38 )
for ( V_3 = 0 ; V_3 < V_193 -> V_39 ; V_3 ++ )
F_49 ( V_193 -> V_12 , & V_193 -> V_38 [ V_3 ] ) ;
F_21 ( V_193 -> V_38 ) ;
if ( V_193 -> V_85 . V_86 )
F_50 ( & V_193 -> V_85 . V_86 -> V_146 ) ;
return 0 ;
}
int F_78 ( struct V_194 * V_195 , void * V_43 , struct V_33 * V_34 )
{
struct V_11 * V_12 = V_195 -> V_196 ;
union V_44 * V_45 = V_43 ;
struct V_32 * V_40 ;
bool V_197 = false ;
int V_3 , V_103 ;
F_37 ( & V_12 -> V_198 ) ;
if ( ! V_12 -> V_199 ) {
F_40 ( & V_12 -> V_198 ) ;
return - V_200 ;
}
V_40 = F_10 ( V_12 , V_34 , NULL , NULL , 0 ) ;
if ( ! V_40 )
return - V_55 ;
V_103 = F_12 ( V_40 , V_43 ) ;
if ( V_103 ) {
F_9 ( L_10 ) ;
F_21 ( V_40 ) ;
F_40 ( & V_12 -> V_198 ) ;
V_103 = F_63 ( V_12 , V_103 ) ;
return V_103 ;
}
V_103 = F_35 ( V_40 ) ;
if ( V_103 == - V_55 )
F_9 ( L_11 ) ;
else if ( V_103 && V_103 != - V_116 )
F_9 ( L_12 , V_103 ) ;
else if ( ! V_103 ) {
V_197 = true ;
V_103 = F_65 ( V_12 , V_40 ) ;
}
if ( ! V_103 ) {
V_103 = F_72 ( V_12 , V_40 ) ;
if ( V_103 )
F_9 ( L_13 , V_103 ) ;
}
if ( V_103 )
goto V_154;
for ( V_3 = 0 ; V_3 < V_40 -> V_39 ; V_3 ++ )
F_79 ( V_40 , V_3 ) ;
V_103 = F_58 ( V_12 , V_40 ) ;
if ( V_103 )
goto V_154;
if ( V_145 && V_40 -> V_39 ) {
struct V_192 * V_193 ;
struct V_16 * V_15 = V_40 -> V_38 -> V_15 ;
V_193 = F_11 ( sizeof( struct V_192 ) , V_41 ) ;
if ( ! V_193 )
return - V_55 ;
V_193 -> V_144 . V_201 = & V_15 -> V_201 ;
V_193 -> V_144 . V_202 = & V_40 -> V_36 -> V_203 [ V_15 -> V_204 ] . V_205 ;
V_193 -> V_12 = V_40 -> V_12 ;
V_193 -> V_38 = V_40 -> V_38 ;
V_193 -> V_39 = V_40 -> V_39 ;
V_193 -> V_144 . V_206 = V_40 -> V_34 ;
F_80 ( & V_193 -> V_207 ) ;
if ( V_193 -> V_38 [ V_193 -> V_39 - 1 ] . V_188 ) {
memcpy ( & V_193 -> V_85 , & V_40 -> V_85 ,
sizeof( struct V_208 ) ) ;
V_193 -> V_38 [ V_193 -> V_39 - 1 ] . V_188 = & V_193 -> V_85 ;
}
V_193 -> V_209 = F_77 ;
F_60 ( & V_193 -> V_207 ) ;
V_103 = F_81 ( & V_193 -> V_144 ) ;
if ( V_103 ) {
F_62 ( & V_193 -> V_207 ) ;
F_77 ( V_193 ) ;
F_21 ( V_193 ) ;
goto V_154;
}
V_45 -> V_154 . V_80 =
F_82 ( V_40 -> V_36 , V_15 ,
& V_193 -> V_144 . V_210 -> V_144 ) ;
V_40 -> V_38 [ V_40 -> V_39 - 1 ] . V_211 = V_45 -> V_154 . V_80 ;
F_46 ( NULL , & V_40 -> V_60 , F_43 ) ;
F_47 ( & V_40 -> V_130 ,
& V_40 -> V_60 ,
& V_193 -> V_144 . V_210 -> V_144 ) ;
F_62 ( & V_193 -> V_207 ) ;
F_48 ( V_40 ) ;
F_40 ( & V_12 -> V_198 ) ;
return 0 ;
}
V_45 -> V_154 . V_80 = V_40 -> V_38 [ V_40 -> V_39 - 1 ] . V_211 ;
V_154:
F_51 ( V_40 , V_103 , V_197 ) ;
F_40 ( & V_12 -> V_198 ) ;
V_103 = F_63 ( V_12 , V_103 ) ;
return V_103 ;
}
int F_83 ( struct V_194 * V_195 , void * V_43 ,
struct V_33 * V_34 )
{
union V_212 * V_213 = V_43 ;
struct V_11 * V_12 = V_195 -> V_196 ;
unsigned long V_214 = F_84 ( V_213 -> V_53 . V_214 ) ;
struct V_16 * V_15 = NULL ;
struct V_35 * V_36 ;
struct V_143 * V_143 ;
long V_103 ;
V_103 = F_8 ( V_12 , V_213 -> V_53 . V_13 , V_213 -> V_53 . V_14 ,
V_213 -> V_53 . V_15 , & V_15 ) ;
if ( V_103 )
return V_103 ;
V_36 = F_14 ( V_34 -> V_50 , V_213 -> V_53 . V_56 ) ;
if ( V_36 == NULL )
return - V_18 ;
V_143 = F_73 ( V_36 , V_15 , V_213 -> V_53 . V_80 ) ;
if ( F_74 ( V_143 ) )
V_103 = F_75 ( V_143 ) ;
else if ( V_143 ) {
V_103 = F_85 ( V_143 , true , V_214 ) ;
F_76 ( V_143 ) ;
} else
V_103 = 1 ;
F_24 ( V_36 ) ;
if ( V_103 < 0 )
return V_103 ;
memset ( V_213 , 0 , sizeof( * V_213 ) ) ;
V_213 -> V_154 . V_215 = ( V_103 == 0 ) ;
return 0 ;
}
struct V_162 *
F_66 ( struct V_32 * V_40 ,
T_3 V_216 , struct V_100 * * V_86 )
{
struct V_98 * V_217 ;
struct V_162 * V_218 ;
V_216 /= V_169 ;
F_29 (reloc, &parser->validated, tv.head) {
if ( ! V_217 -> V_117 )
continue;
F_29 (mapping, &reloc->bo_va->valids, list) {
if ( V_218 -> V_167 . V_170 > V_216 ||
V_216 > V_218 -> V_167 . V_168 )
continue;
* V_86 = V_217 -> V_117 -> V_86 ;
return V_218 ;
}
F_29 (mapping, &reloc->bo_va->invalids, list) {
if ( V_218 -> V_167 . V_170 > V_216 ||
V_216 > V_218 -> V_167 . V_168 )
continue;
* V_86 = V_217 -> V_117 -> V_86 ;
return V_218 ;
}
}
return NULL ;
}
