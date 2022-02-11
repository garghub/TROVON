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
if ( V_15 < V_12 -> V_27 . V_28 ) {
* V_17 = & V_12 -> V_27 . V_29 [ V_15 ] . V_15 ;
} else {
F_9 ( L_5 ,
V_12 -> V_27 . V_28 ) ;
return - V_18 ;
}
break;
case V_30 :
* V_17 = & V_12 -> V_31 . V_15 ;
break;
case V_32 :
if ( V_15 < 2 ) {
* V_17 = & V_12 -> V_33 . V_15 [ V_15 ] ;
} else {
F_9 ( L_6 ) ;
return - V_18 ;
}
break;
}
return 0 ;
}
static int F_10 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
struct V_38 * V_39 ;
T_2 V_40 ;
V_40 = V_37 -> V_40 ;
V_39 = F_11 ( V_35 -> V_12 -> V_41 , V_35 -> V_42 ,
V_37 -> V_40 ) ;
if ( V_39 == NULL )
return - V_18 ;
V_35 -> V_43 . V_44 = F_12 ( F_13 ( V_39 ) ) ;
V_35 -> V_43 . V_45 = V_37 -> V_45 ;
if ( F_14 ( V_35 -> V_43 . V_44 -> V_46 . V_47 ) ) {
F_15 ( V_39 ) ;
return - V_18 ;
}
V_35 -> V_48 . V_49 = F_12 ( V_35 -> V_43 . V_44 ) ;
V_35 -> V_48 . V_50 = V_51 ;
V_35 -> V_48 . V_52 = V_51 ;
V_35 -> V_48 . V_8 = 0 ;
V_35 -> V_48 . V_53 . V_44 = & V_35 -> V_48 . V_49 -> V_46 ;
V_35 -> V_48 . V_53 . V_54 = true ;
F_15 ( V_39 ) ;
return 0 ;
}
int F_16 ( struct V_34 * V_35 , void * V_55 )
{
union V_56 * V_57 = V_55 ;
T_3 * V_58 ;
T_3 * V_59 ;
struct V_60 * V_61 = V_35 -> V_42 -> V_62 ;
unsigned V_63 ;
int V_3 ;
int V_64 ;
if ( V_57 -> V_65 . V_66 == 0 )
return 0 ;
V_59 = F_17 ( V_57 -> V_65 . V_66 , sizeof( T_3 ) , V_67 ) ;
if ( ! V_59 )
return - V_68 ;
V_35 -> V_69 = F_18 ( V_61 , V_57 -> V_65 . V_70 ) ;
if ( ! V_35 -> V_69 ) {
V_64 = - V_18 ;
goto V_71;
}
V_35 -> V_72 = F_19 ( V_61 , V_57 -> V_65 . V_73 ) ;
F_2 ( & V_35 -> V_74 ) ;
V_58 = ( T_3 V_75 * ) ( unsigned long ) ( V_57 -> V_65 . V_76 ) ;
if ( F_20 ( V_59 , V_58 ,
sizeof( T_3 ) * V_57 -> V_65 . V_66 ) ) {
V_64 = - V_77 ;
goto V_78;
}
V_35 -> V_79 = V_57 -> V_65 . V_66 ;
V_35 -> V_76 = F_17 ( V_35 -> V_79 , sizeof( struct V_80 ) ,
V_67 ) ;
if ( ! V_35 -> V_76 ) {
V_64 = - V_68 ;
goto V_78;
}
for ( V_3 = 0 ; V_3 < V_35 -> V_79 ; V_3 ++ ) {
struct V_81 V_75 * * V_82 = NULL ;
struct V_81 V_83 ;
T_2 V_75 * V_84 ;
V_82 = ( void V_75 * ) ( unsigned long ) V_59 [ V_3 ] ;
if ( F_20 ( & V_83 , V_82 ,
sizeof( struct V_81 ) ) ) {
V_64 = - V_77 ;
V_3 -- ;
goto V_85;
}
V_35 -> V_76 [ V_3 ] . V_86 = V_83 . V_86 ;
V_35 -> V_76 [ V_3 ] . V_87 = V_83 . V_87 ;
V_63 = V_35 -> V_76 [ V_3 ] . V_87 ;
V_84 = ( void V_75 * ) ( unsigned long ) V_83 . V_88 ;
V_35 -> V_76 [ V_3 ] . V_89 = V_84 ;
V_35 -> V_76 [ V_3 ] . V_90 = F_21 ( V_63 , sizeof( T_2 ) ) ;
if ( V_35 -> V_76 [ V_3 ] . V_90 == NULL ) {
V_64 = - V_68 ;
V_3 -- ;
goto V_85;
}
V_63 *= sizeof( T_2 ) ;
if ( F_20 ( V_35 -> V_76 [ V_3 ] . V_90 , V_84 , V_63 ) ) {
V_64 = - V_77 ;
goto V_85;
}
switch ( V_35 -> V_76 [ V_3 ] . V_86 ) {
case V_91 :
V_35 -> V_92 ++ ;
break;
case V_93 :
V_63 = sizeof( struct V_36 ) ;
if ( V_35 -> V_76 [ V_3 ] . V_87 * sizeof( T_2 ) < V_63 ) {
V_64 = - V_18 ;
goto V_85;
}
V_64 = F_10 ( V_35 , ( void * ) V_35 -> V_76 [ V_3 ] . V_90 ) ;
if ( V_64 )
goto V_85;
break;
case V_94 :
break;
default:
V_64 = - V_18 ;
goto V_85;
}
}
V_35 -> V_95 = F_22 ( V_35 -> V_92 , sizeof( struct V_96 ) , V_67 ) ;
if ( ! V_35 -> V_95 ) {
V_64 = - V_68 ;
goto V_97;
}
F_23 ( V_59 ) ;
return 0 ;
V_97:
V_3 = V_35 -> V_79 - 1 ;
V_85:
for (; V_3 >= 0 ; V_3 -- )
F_24 ( V_35 -> V_76 [ V_3 ] . V_90 ) ;
F_23 ( V_35 -> V_76 ) ;
V_78:
if ( V_35 -> V_72 )
F_25 ( V_35 -> V_72 ) ;
F_26 ( V_35 -> V_69 ) ;
V_71:
F_23 ( V_59 ) ;
return V_64 ;
}
static T_4 F_27 ( struct V_11 * V_12 )
{
T_4 V_98 = V_12 -> V_99 . V_98 ;
T_4 V_100 = F_28 ( & V_12 -> V_100 ) ;
T_4 V_101 = V_98 >> 1 ;
T_4 V_102 = V_100 >= V_101 ? 0 : V_101 - V_100 ;
T_4 V_103 = V_102 >> 1 ;
return F_29 ( V_103 , 1024 * 1024ull ) ;
}
int F_30 ( struct V_11 * V_12 ,
struct V_104 * V_105 ,
struct V_6 * V_74 )
{
struct V_106 * V_107 ;
struct V_108 * V_44 ;
T_4 V_109 = 0 , V_110 ;
T_4 V_103 = F_27 ( V_12 ) ;
int V_111 ;
F_31 (lobj, validated, tv.head) {
V_44 = V_107 -> V_49 ;
if ( ! V_44 -> V_112 ) {
T_1 V_113 = V_107 -> V_50 ;
T_1 V_114 =
F_32 ( V_44 -> V_46 . V_115 . V_116 ) ;
if ( ( V_107 -> V_52 & V_114 ) != 0 &&
( V_113 & V_114 ) == 0 &&
V_109 > V_103 ) {
V_113 = V_114 ;
}
V_117:
F_33 ( V_44 , V_113 ) ;
V_110 = F_28 ( & V_12 -> V_118 ) ;
V_111 = F_34 ( & V_44 -> V_46 , & V_44 -> V_119 , true , false ) ;
V_109 += F_28 ( & V_12 -> V_118 ) -
V_110 ;
if ( F_35 ( V_111 ) ) {
if ( V_111 != - V_120 && V_113 != V_107 -> V_52 ) {
V_113 = V_107 -> V_52 ;
goto V_117;
}
return V_111 ;
}
}
V_107 -> V_121 = F_36 ( V_105 , V_44 ) ;
}
return 0 ;
}
static int F_37 ( struct V_34 * V_35 )
{
struct V_60 * V_61 = V_35 -> V_42 -> V_62 ;
struct V_1 V_122 ;
struct V_6 V_123 ;
bool V_124 = false ;
int V_3 , V_111 ;
if ( V_35 -> V_72 ) {
V_124 = V_35 -> V_72 -> V_125 ;
F_1 ( & V_122 ) ;
for ( V_3 = 0 ; V_3 < V_35 -> V_72 -> V_126 ; V_3 ++ )
F_3 ( & V_122 , & V_35 -> V_72 -> V_127 [ V_3 ] . V_53 . V_128 ,
V_35 -> V_72 -> V_127 [ V_3 ] . V_8 ) ;
F_6 ( & V_122 , & V_35 -> V_74 ) ;
}
F_2 ( & V_123 ) ;
F_38 ( & V_61 -> V_105 , & V_35 -> V_74 , & V_35 -> V_129 ) ;
if ( V_35 -> V_43 . V_44 )
F_39 ( & V_35 -> V_48 . V_53 . V_128 , & V_35 -> V_74 ) ;
if ( V_124 )
F_40 ( & V_130 -> V_131 -> V_132 ) ;
V_111 = F_41 ( & V_35 -> V_133 , & V_35 -> V_74 , true , & V_123 ) ;
if ( F_35 ( V_111 != 0 ) )
goto V_134;
F_42 ( & V_61 -> V_105 , & V_123 ) ;
V_111 = F_30 ( V_35 -> V_12 , & V_61 -> V_105 , & V_123 ) ;
if ( V_111 )
goto V_135;
V_111 = F_30 ( V_35 -> V_12 , & V_61 -> V_105 , & V_35 -> V_74 ) ;
V_135:
if ( V_111 ) {
F_43 ( V_35 -> V_12 , & V_61 -> V_105 ) ;
F_44 ( & V_35 -> V_133 , & V_35 -> V_74 ) ;
}
V_134:
if ( V_124 )
F_45 ( & V_130 -> V_131 -> V_132 ) ;
return V_111 ;
}
static int F_46 ( struct V_34 * V_35 )
{
struct V_106 * V_136 ;
int V_111 ;
F_31 (e, &p->validated, tv.head) {
struct V_137 * V_138 = V_136 -> V_49 -> V_46 . V_138 ;
V_111 = F_47 ( V_35 -> V_12 , & V_35 -> V_95 [ 0 ] . V_139 , V_138 , V_35 -> V_42 ) ;
if ( V_111 )
return V_111 ;
}
return 0 ;
}
static int F_48 ( void * V_140 , struct V_6 * V_141 ,
struct V_6 * V_2 )
{
struct V_106 * V_142 = F_49 ( V_141 , struct V_106 , V_53 . V_128 ) ;
struct V_106 * V_143 = F_49 ( V_2 , struct V_106 , V_53 . V_128 ) ;
return ( int ) V_142 -> V_49 -> V_46 . V_144 - ( int ) V_143 -> V_49 -> V_46 . V_144 ;
}
static void F_50 ( struct V_34 * V_145 , int error , bool V_146 )
{
struct V_60 * V_61 = V_145 -> V_42 -> V_62 ;
unsigned V_3 ;
if ( ! error ) {
F_43 ( V_145 -> V_12 , & V_61 -> V_105 ) ;
F_51 ( NULL , & V_145 -> V_74 , F_48 ) ;
F_52 ( & V_145 -> V_133 ,
& V_145 -> V_74 ,
V_145 -> V_147 ) ;
} else if ( V_146 ) {
F_44 ( & V_145 -> V_133 ,
& V_145 -> V_74 ) ;
}
F_53 ( V_145 -> V_147 ) ;
if ( V_145 -> V_69 )
F_26 ( V_145 -> V_69 ) ;
if ( V_145 -> V_72 )
F_25 ( V_145 -> V_72 ) ;
for ( V_3 = 0 ; V_3 < V_145 -> V_79 ; V_3 ++ )
F_24 ( V_145 -> V_76 [ V_3 ] . V_90 ) ;
F_23 ( V_145 -> V_76 ) ;
if ( V_145 -> V_95 )
for ( V_3 = 0 ; V_3 < V_145 -> V_92 ; V_3 ++ )
F_54 ( V_145 -> V_12 , & V_145 -> V_95 [ V_3 ] ) ;
F_23 ( V_145 -> V_95 ) ;
F_55 ( & V_145 -> V_43 . V_44 ) ;
F_55 ( & V_145 -> V_48 . V_49 ) ;
}
static int F_56 ( struct V_34 * V_35 ,
struct V_104 * V_105 )
{
struct V_11 * V_12 = V_35 -> V_12 ;
struct V_148 * V_121 ;
struct V_108 * V_44 ;
int V_3 , V_111 ;
V_111 = F_57 ( V_12 , V_105 ) ;
if ( V_111 )
return V_111 ;
V_111 = F_58 ( V_12 , & V_35 -> V_95 [ 0 ] . V_139 , V_105 -> V_149 ) ;
if ( V_111 )
return V_111 ;
V_111 = F_59 ( V_12 , V_105 ) ;
if ( V_111 )
return V_111 ;
if ( V_35 -> V_72 ) {
for ( V_3 = 0 ; V_3 < V_35 -> V_72 -> V_126 ; V_3 ++ ) {
struct V_147 * V_150 ;
V_44 = V_35 -> V_72 -> V_127 [ V_3 ] . V_49 ;
if ( ! V_44 )
continue;
V_121 = V_35 -> V_72 -> V_127 [ V_3 ] . V_121 ;
if ( V_121 == NULL )
continue;
V_111 = F_60 ( V_12 , V_121 , & V_44 -> V_46 . V_115 ) ;
if ( V_111 )
return V_111 ;
V_150 = V_121 -> V_151 ;
V_111 = F_58 ( V_12 , & V_35 -> V_95 [ 0 ] . V_139 , V_150 ) ;
if ( V_111 )
return V_111 ;
}
}
V_111 = F_61 ( V_12 , V_105 , & V_35 -> V_95 [ 0 ] . V_139 ) ;
if ( V_152 && V_35 -> V_72 ) {
for ( V_3 = 0 ; V_3 < V_35 -> V_72 -> V_126 ; V_3 ++ ) {
V_44 = V_35 -> V_72 -> V_127 [ V_3 ] . V_49 ;
if ( ! V_44 )
continue;
F_62 ( V_12 , V_44 ) ;
}
}
return V_111 ;
}
static int F_63 ( struct V_11 * V_12 ,
struct V_34 * V_145 )
{
struct V_60 * V_61 = V_145 -> V_42 -> V_62 ;
struct V_104 * V_105 = & V_61 -> V_105 ;
struct V_16 * V_15 ;
int V_3 , V_111 ;
if ( V_145 -> V_92 == 0 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_145 -> V_92 ; V_3 ++ ) {
V_15 = V_145 -> V_95 [ V_3 ] . V_15 ;
if ( V_15 -> V_153 -> V_154 ) {
V_111 = F_64 ( V_15 , V_145 , V_3 ) ;
if ( V_111 )
return V_111 ;
}
}
V_111 = F_56 ( V_145 , V_105 ) ;
if ( ! V_111 )
F_46 ( V_145 ) ;
return V_111 ;
}
static int F_65 ( struct V_11 * V_12 , int V_111 )
{
if ( V_111 == - V_155 ) {
V_111 = F_66 ( V_12 ) ;
if ( ! V_111 )
V_111 = - V_156 ;
}
return V_111 ;
}
static int F_67 ( struct V_11 * V_12 ,
struct V_34 * V_145 )
{
struct V_60 * V_61 = V_145 -> V_42 -> V_62 ;
struct V_104 * V_105 = & V_61 -> V_105 ;
int V_3 , V_157 ;
int V_111 ;
for ( V_3 = 0 , V_157 = 0 ; V_3 < V_145 -> V_79 && V_157 < V_145 -> V_92 ; V_3 ++ ) {
struct V_80 * V_158 ;
struct V_96 * V_159 ;
struct V_160 * V_161 ;
struct V_16 * V_15 ;
V_158 = & V_145 -> V_76 [ V_3 ] ;
V_159 = & V_145 -> V_95 [ V_157 ] ;
V_161 = (struct V_160 * ) V_158 -> V_90 ;
if ( V_158 -> V_86 != V_91 )
continue;
V_111 = F_8 ( V_12 , V_161 -> V_13 ,
V_161 -> V_14 , V_161 -> V_15 ,
& V_15 ) ;
if ( V_111 )
return V_111 ;
if ( V_15 -> V_153 -> V_154 ) {
struct V_162 * V_163 ;
struct V_108 * V_164 = NULL ;
T_3 V_45 ;
T_5 * V_165 ;
V_163 = F_68 ( V_145 , V_161 -> va_start ,
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
V_111 = F_69 ( V_164 , ( void * * ) & V_165 ) ;
if ( V_111 ) {
return V_111 ;
}
V_45 = ( ( T_3 ) V_163 -> V_167 . V_170 ) * V_169 ;
V_165 += V_161 -> va_start - V_45 ;
V_111 = F_70 ( V_15 , NULL , V_161 -> V_166 , V_159 ) ;
if ( V_111 ) {
F_9 ( L_9 ) ;
return V_111 ;
}
memcpy ( V_159 -> V_171 , V_165 , V_161 -> V_166 ) ;
F_71 ( V_164 ) ;
} else {
V_111 = F_70 ( V_15 , V_105 , 0 , V_159 ) ;
if ( V_111 ) {
F_9 ( L_9 ) ;
return V_111 ;
}
V_159 -> V_172 = V_161 -> va_start ;
}
V_159 -> V_87 = V_161 -> V_166 / 4 ;
V_159 -> V_173 = V_161 -> V_173 ;
V_159 -> V_69 = V_145 -> V_69 ;
V_157 ++ ;
}
if ( ! V_145 -> V_92 )
return 0 ;
if ( V_145 -> V_72 ) {
struct V_108 * V_174 = V_145 -> V_72 -> V_175 ;
struct V_108 * V_176 = V_145 -> V_72 -> V_177 ;
struct V_108 * V_178 = V_145 -> V_72 -> V_179 ;
struct V_96 * V_159 = & V_145 -> V_95 [ 0 ] ;
if ( V_174 ) {
V_159 -> V_180 = F_72 ( V_174 ) ;
V_159 -> V_181 = F_73 ( V_174 ) ;
}
if ( V_176 ) {
V_159 -> V_182 = F_72 ( V_176 ) ;
V_159 -> V_183 = F_73 ( V_176 ) ;
}
if ( V_178 ) {
V_159 -> V_184 = F_72 ( V_178 ) ;
V_159 -> V_185 = F_73 ( V_178 ) ;
}
}
if ( V_145 -> V_43 . V_44 ) {
struct V_96 * V_159 = & V_145 -> V_95 [ V_145 -> V_92 - 1 ] ;
if ( V_159 -> V_15 -> type == V_186 ||
V_159 -> V_15 -> type == V_187 )
return - V_18 ;
V_159 -> V_188 = & V_145 -> V_43 ;
}
return 0 ;
}
static int F_74 ( struct V_11 * V_12 ,
struct V_34 * V_35 )
{
struct V_60 * V_61 = V_35 -> V_42 -> V_62 ;
struct V_96 * V_159 ;
int V_3 , V_157 , V_111 ;
if ( ! V_35 -> V_92 )
return 0 ;
V_159 = & V_35 -> V_95 [ 0 ] ;
for ( V_3 = 0 ; V_3 < V_35 -> V_79 ; ++ V_3 ) {
struct V_189 * V_190 ;
struct V_80 * V_158 ;
unsigned V_191 ;
V_158 = & V_35 -> V_76 [ V_3 ] ;
if ( V_158 -> V_86 != V_94 )
continue;
V_190 = (struct V_189 * ) V_158 -> V_90 ;
V_191 = V_158 -> V_87 * 4 /
sizeof( struct V_189 ) ;
for ( V_157 = 0 ; V_157 < V_191 ; ++ V_157 ) {
struct V_16 * V_15 ;
struct V_192 * V_69 ;
struct V_147 * V_147 ;
V_111 = F_8 ( V_12 , V_190 [ V_157 ] . V_13 ,
V_190 [ V_157 ] . V_14 ,
V_190 [ V_157 ] . V_15 , & V_15 ) ;
if ( V_111 )
return V_111 ;
V_69 = F_18 ( V_61 , V_190 [ V_157 ] . V_70 ) ;
if ( V_69 == NULL )
return - V_18 ;
V_147 = F_75 ( V_69 , V_15 ,
V_190 [ V_157 ] . V_40 ) ;
if ( F_76 ( V_147 ) ) {
V_111 = F_77 ( V_147 ) ;
F_26 ( V_69 ) ;
return V_111 ;
} else if ( V_147 ) {
V_111 = F_58 ( V_12 , & V_159 -> V_139 , V_147 ) ;
F_53 ( V_147 ) ;
F_26 ( V_69 ) ;
if ( V_111 )
return V_111 ;
}
}
}
return 0 ;
}
static int F_78 ( struct V_193 * V_194 )
{
int V_3 ;
if ( V_194 -> V_95 )
for ( V_3 = 0 ; V_3 < V_194 -> V_92 ; V_3 ++ )
F_54 ( V_194 -> V_12 , & V_194 -> V_95 [ V_3 ] ) ;
F_23 ( V_194 -> V_95 ) ;
if ( V_194 -> V_43 . V_44 )
F_55 ( & V_194 -> V_43 . V_44 ) ;
return 0 ;
}
int F_79 ( struct V_195 * V_196 , void * V_55 , struct V_197 * V_42 )
{
struct V_11 * V_12 = V_196 -> V_198 ;
union V_56 * V_57 = V_55 ;
struct V_34 V_145 = {} ;
bool V_199 = false ;
int V_3 , V_111 ;
if ( ! V_12 -> V_200 )
return - V_201 ;
V_145 . V_12 = V_12 ;
V_145 . V_42 = V_42 ;
V_111 = F_16 ( & V_145 , V_55 ) ;
if ( V_111 ) {
F_9 ( L_10 ) ;
F_50 ( & V_145 , V_111 , false ) ;
V_111 = F_65 ( V_12 , V_111 ) ;
return V_111 ;
}
V_111 = F_37 ( & V_145 ) ;
if ( V_111 == - V_68 )
F_9 ( L_11 ) ;
else if ( V_111 && V_111 != - V_120 )
F_9 ( L_12 , V_111 ) ;
else if ( ! V_111 ) {
V_199 = true ;
V_111 = F_67 ( V_12 , & V_145 ) ;
}
if ( ! V_111 ) {
V_111 = F_74 ( V_12 , & V_145 ) ;
if ( V_111 )
F_9 ( L_13 , V_111 ) ;
}
if ( V_111 )
goto V_202;
for ( V_3 = 0 ; V_3 < V_145 . V_92 ; V_3 ++ )
F_80 ( & V_145 , V_3 ) ;
V_111 = F_63 ( V_12 , & V_145 ) ;
if ( V_111 )
goto V_202;
if ( V_203 && V_145 . V_92 ) {
struct V_16 * V_15 = V_145 . V_95 -> V_15 ;
struct V_204 * V_147 ;
struct V_193 * V_194 ;
V_194 = F_81 ( sizeof( struct V_193 ) , V_67 ) ;
if ( ! V_194 ) {
V_111 = - V_68 ;
goto V_202;
}
V_194 -> V_205 . V_206 = & V_15 -> V_206 ;
V_194 -> V_205 . V_207 = & V_145 . V_69 -> V_208 [ V_15 -> V_209 ] . V_210 ;
V_194 -> V_12 = V_145 . V_12 ;
V_194 -> V_211 = V_145 . V_42 ;
V_194 -> V_212 = F_78 ;
V_194 -> V_95 = V_145 . V_95 ;
V_194 -> V_92 = V_145 . V_92 ;
V_145 . V_95 = NULL ;
V_145 . V_92 = 0 ;
if ( V_194 -> V_95 [ V_194 -> V_92 - 1 ] . V_188 ) {
V_194 -> V_43 = V_145 . V_43 ;
V_194 -> V_95 [ V_194 -> V_92 - 1 ] . V_188 = & V_194 -> V_43 ;
V_145 . V_43 . V_44 = NULL ;
}
V_147 = F_82 ( V_194 -> V_205 . V_207 ,
V_145 . V_42 ) ;
if ( ! V_147 ) {
V_111 = - V_68 ;
F_78 ( V_194 ) ;
F_23 ( V_194 ) ;
goto V_202;
}
V_194 -> V_205 . V_213 = V_147 ;
V_145 . V_147 = F_83 ( & V_147 -> V_205 ) ;
V_57 -> V_202 . V_40 = F_84 ( V_145 . V_69 , V_15 ,
& V_147 -> V_205 ) ;
V_194 -> V_95 [ V_194 -> V_92 - 1 ] . V_214 = V_57 -> V_202 . V_40 ;
F_85 ( V_194 ) ;
F_86 ( & V_194 -> V_205 ) ;
} else {
struct V_215 * V_147 ;
V_111 = F_87 ( V_12 , V_145 . V_92 , V_145 . V_95 ,
V_145 . V_42 ) ;
V_147 = V_145 . V_95 [ V_145 . V_92 - 1 ] . V_147 ;
V_145 . V_147 = F_83 ( & V_147 -> V_205 ) ;
V_57 -> V_202 . V_40 = V_145 . V_95 [ V_145 . V_92 - 1 ] . V_214 ;
}
V_202:
F_50 ( & V_145 , V_111 , V_199 ) ;
V_111 = F_65 ( V_12 , V_111 ) ;
return V_111 ;
}
int F_88 ( struct V_195 * V_196 , void * V_55 ,
struct V_197 * V_42 )
{
union V_216 * V_217 = V_55 ;
struct V_11 * V_12 = V_196 -> V_198 ;
unsigned long V_218 = F_89 ( V_217 -> V_65 . V_218 ) ;
struct V_16 * V_15 = NULL ;
struct V_192 * V_69 ;
struct V_147 * V_147 ;
long V_111 ;
V_111 = F_8 ( V_12 , V_217 -> V_65 . V_13 , V_217 -> V_65 . V_14 ,
V_217 -> V_65 . V_15 , & V_15 ) ;
if ( V_111 )
return V_111 ;
V_69 = F_18 ( V_42 -> V_62 , V_217 -> V_65 . V_70 ) ;
if ( V_69 == NULL )
return - V_18 ;
V_147 = F_75 ( V_69 , V_15 , V_217 -> V_65 . V_40 ) ;
if ( F_76 ( V_147 ) )
V_111 = F_77 ( V_147 ) ;
else if ( V_147 ) {
V_111 = F_90 ( V_147 , true , V_218 ) ;
F_53 ( V_147 ) ;
} else
V_111 = 1 ;
F_26 ( V_69 ) ;
if ( V_111 < 0 )
return V_111 ;
memset ( V_217 , 0 , sizeof( * V_217 ) ) ;
V_217 -> V_202 . V_219 = ( V_111 == 0 ) ;
return 0 ;
}
struct V_162 *
F_68 ( struct V_34 * V_145 ,
T_3 V_220 , struct V_108 * * V_44 )
{
struct V_106 * V_221 ;
struct V_162 * V_222 ;
V_220 /= V_169 ;
F_31 (reloc, &parser->validated, tv.head) {
if ( ! V_221 -> V_121 )
continue;
F_31 (mapping, &reloc->bo_va->valids, list) {
if ( V_222 -> V_167 . V_170 > V_220 ||
V_220 > V_222 -> V_167 . V_168 )
continue;
* V_44 = V_221 -> V_121 -> V_44 ;
return V_222 ;
}
F_31 (mapping, &reloc->bo_va->invalids, list) {
if ( V_222 -> V_167 . V_170 > V_220 ||
V_220 > V_222 -> V_167 . V_168 )
continue;
* V_44 = V_221 -> V_121 -> V_44 ;
return V_222 ;
}
}
return NULL ;
}
