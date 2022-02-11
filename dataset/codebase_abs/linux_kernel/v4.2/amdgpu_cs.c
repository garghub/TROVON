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
int F_10 ( struct V_32 * V_33 , void * V_34 )
{
union V_35 * V_36 = V_34 ;
T_2 * V_37 ;
T_2 * V_38 = NULL ;
struct V_39 * V_40 = V_33 -> V_41 -> V_42 ;
unsigned V_43 , V_3 ;
int V_44 = 0 ;
if ( ! V_36 -> V_45 . V_46 )
goto V_47;
V_33 -> V_48 = F_11 ( V_40 , V_36 -> V_45 . V_49 ) ;
if ( ! V_33 -> V_48 ) {
V_44 = - V_18 ;
goto V_47;
}
V_33 -> V_50 = F_12 ( V_40 , V_36 -> V_45 . V_51 ) ;
F_2 ( & V_33 -> V_52 ) ;
V_38 = F_13 ( V_36 -> V_45 . V_46 , sizeof( T_2 ) , V_53 ) ;
if ( V_38 == NULL ) {
V_44 = - V_54 ;
goto V_47;
}
V_37 = ( T_2 * ) ( unsigned long ) ( V_36 -> V_45 . V_55 ) ;
if ( F_14 ( V_38 , V_37 ,
sizeof( T_2 ) * V_36 -> V_45 . V_46 ) ) {
V_44 = - V_56 ;
goto V_47;
}
V_33 -> V_57 = V_36 -> V_45 . V_46 ;
V_33 -> V_55 = F_13 ( V_33 -> V_57 , sizeof( struct V_58 ) ,
V_53 ) ;
if ( V_33 -> V_55 == NULL ) {
V_44 = - V_54 ;
goto V_47;
}
for ( V_3 = 0 ; V_3 < V_33 -> V_57 ; V_3 ++ ) {
struct V_59 T_3 * * V_60 = NULL ;
struct V_59 V_61 ;
T_4 T_3 * V_62 ;
V_60 = ( void T_3 * ) ( unsigned long ) V_38 [ V_3 ] ;
if ( F_14 ( & V_61 , V_60 ,
sizeof( struct V_59 ) ) ) {
V_44 = - V_56 ;
goto V_47;
}
V_33 -> V_55 [ V_3 ] . V_63 = V_61 . V_63 ;
V_33 -> V_55 [ V_3 ] . V_64 = V_61 . V_64 ;
V_43 = V_33 -> V_55 [ V_3 ] . V_64 ;
V_62 = ( void T_3 * ) ( unsigned long ) V_61 . V_65 ;
V_33 -> V_55 [ V_3 ] . V_66 = V_62 ;
V_33 -> V_55 [ V_3 ] . V_67 = F_15 ( V_43 , sizeof( T_4 ) ) ;
if ( V_33 -> V_55 [ V_3 ] . V_67 == NULL ) {
V_44 = - V_54 ;
goto V_47;
}
V_43 *= sizeof( T_4 ) ;
if ( F_14 ( V_33 -> V_55 [ V_3 ] . V_67 , V_62 , V_43 ) ) {
V_44 = - V_56 ;
goto V_47;
}
switch ( V_33 -> V_55 [ V_3 ] . V_63 ) {
case V_68 :
V_33 -> V_69 ++ ;
break;
case V_70 :
V_43 = sizeof( struct V_71 ) ;
if ( V_33 -> V_55 [ V_3 ] . V_64 * sizeof( T_4 ) >= V_43 ) {
T_4 V_72 ;
struct V_73 * V_74 ;
struct V_71 * V_75 ;
V_75 = ( void * ) V_33 -> V_55 [ V_3 ] . V_67 ;
V_72 = V_75 -> V_72 ;
V_74 = F_16 ( V_33 -> V_12 -> V_76 ,
V_33 -> V_41 , V_72 ) ;
if ( V_74 == NULL ) {
V_44 = - V_18 ;
goto V_47;
}
V_33 -> V_77 . V_78 = F_17 ( V_74 ) ;
V_33 -> V_77 . V_79 = V_75 -> V_79 ;
} else {
V_44 = - V_18 ;
goto V_47;
}
break;
case V_80 :
break;
default:
V_44 = - V_18 ;
goto V_47;
}
}
V_33 -> V_81 = F_13 ( V_33 -> V_69 , sizeof( struct V_82 ) , V_53 ) ;
if ( ! V_33 -> V_81 ) {
V_44 = - V_54 ;
goto V_47;
}
V_47:
F_18 ( V_38 ) ;
return V_44 ;
}
static T_5 F_19 ( struct V_11 * V_12 )
{
T_5 V_83 = V_12 -> V_84 . V_83 ;
T_5 V_85 = F_20 ( & V_12 -> V_85 ) ;
T_5 V_86 = V_83 >> 1 ;
T_5 V_87 = V_85 >= V_86 ? 0 : V_86 - V_85 ;
T_5 V_88 = V_87 >> 1 ;
return F_21 ( V_88 , 1024 * 1024ull ) ;
}
int F_22 ( struct V_32 * V_33 )
{
struct V_39 * V_40 = V_33 -> V_41 -> V_42 ;
struct V_89 * V_90 = & V_40 -> V_90 ;
struct V_11 * V_12 = V_33 -> V_12 ;
struct V_91 * V_92 ;
struct V_6 V_93 ;
struct V_94 * V_78 ;
T_5 V_95 = 0 , V_96 ;
T_5 V_88 = F_19 ( V_12 ) ;
int V_44 ;
F_2 ( & V_93 ) ;
V_44 = F_23 ( & V_33 -> V_97 , & V_33 -> V_52 , true , & V_93 ) ;
if ( F_24 ( V_44 != 0 ) ) {
return V_44 ;
}
F_25 (lobj, &p->validated, tv.head) {
V_78 = V_92 -> V_98 ;
if ( ! V_78 -> V_99 ) {
T_1 V_100 = V_92 -> V_101 ;
T_1 V_102 =
F_26 ( V_78 -> V_103 . V_104 . V_105 ) ;
if ( V_102 != V_106 &&
( V_100 & V_102 ) == 0 &&
V_95 > V_88 ) {
V_100 = V_102 ;
}
V_107:
F_27 ( V_78 , V_100 ) ;
V_96 = F_20 ( & V_12 -> V_108 ) ;
V_44 = F_28 ( & V_78 -> V_103 , & V_78 -> V_109 , true , false ) ;
V_95 += F_20 ( & V_12 -> V_108 ) -
V_96 ;
if ( F_24 ( V_44 ) ) {
if ( V_44 != - V_110 && V_100 != V_92 -> V_111 ) {
V_100 = V_92 -> V_111 ;
goto V_107;
}
F_29 ( & V_33 -> V_97 , & V_33 -> V_52 ) ;
return V_44 ;
}
}
V_92 -> V_112 = F_30 ( V_90 , V_78 ) ;
}
return 0 ;
}
static int F_31 ( struct V_32 * V_33 )
{
struct V_39 * V_40 = V_33 -> V_41 -> V_42 ;
struct V_1 V_113 ;
bool V_114 = false ;
int V_3 , V_44 ;
if ( V_33 -> V_50 ) {
V_114 = V_33 -> V_50 -> V_115 ;
F_1 ( & V_113 ) ;
for ( V_3 = 0 ; V_3 < V_33 -> V_50 -> V_116 ; V_3 ++ )
F_3 ( & V_113 , & V_33 -> V_50 -> V_117 [ V_3 ] . V_118 . V_119 ,
V_33 -> V_50 -> V_117 [ V_3 ] . V_8 ) ;
F_6 ( & V_113 , & V_33 -> V_52 ) ;
}
V_33 -> V_120 = F_32 ( V_33 -> V_12 , & V_40 -> V_90 ,
& V_33 -> V_52 ) ;
if ( V_114 )
F_33 ( & V_121 -> V_122 -> V_123 ) ;
V_44 = F_22 ( V_33 ) ;
if ( V_114 )
F_34 ( & V_121 -> V_122 -> V_123 ) ;
return V_44 ;
}
static int F_35 ( struct V_32 * V_33 )
{
struct V_91 * V_124 ;
int V_44 ;
F_25 (e, &p->validated, tv.head) {
struct V_125 * V_126 = V_124 -> V_98 -> V_103 . V_126 ;
V_44 = F_36 ( V_33 -> V_12 , & V_33 -> V_81 [ 0 ] . V_127 , V_126 , V_33 -> V_41 ) ;
if ( V_44 )
return V_44 ;
}
return 0 ;
}
static int F_37 ( void * V_128 , struct V_6 * V_129 ,
struct V_6 * V_2 )
{
struct V_91 * V_130 = F_38 ( V_129 , struct V_91 , V_118 . V_119 ) ;
struct V_91 * V_131 = F_38 ( V_2 , struct V_91 , V_118 . V_119 ) ;
return ( int ) V_130 -> V_98 -> V_103 . V_132 - ( int ) V_131 -> V_98 -> V_103 . V_132 ;
}
static void F_39 ( struct V_32 * V_133 , int error , bool V_134 )
{
unsigned V_3 ;
if ( ! error ) {
F_40 ( NULL , & V_133 -> V_52 , F_37 ) ;
F_41 ( & V_133 -> V_97 ,
& V_133 -> V_52 ,
& V_133 -> V_81 [ V_133 -> V_69 - 1 ] . V_135 -> V_136 ) ;
} else if ( V_134 ) {
F_29 ( & V_133 -> V_97 ,
& V_133 -> V_52 ) ;
}
if ( V_133 -> V_48 )
F_42 ( V_133 -> V_48 ) ;
if ( V_133 -> V_50 )
F_43 ( V_133 -> V_50 ) ;
F_44 ( V_133 -> V_120 ) ;
for ( V_3 = 0 ; V_3 < V_133 -> V_57 ; V_3 ++ )
F_44 ( V_133 -> V_55 [ V_3 ] . V_67 ) ;
F_18 ( V_133 -> V_55 ) ;
if ( V_133 -> V_81 )
for ( V_3 = 0 ; V_3 < V_133 -> V_69 ; V_3 ++ )
F_45 ( V_133 -> V_12 , & V_133 -> V_81 [ V_3 ] ) ;
F_18 ( V_133 -> V_81 ) ;
if ( V_133 -> V_77 . V_78 )
F_46 ( & V_133 -> V_77 . V_78 -> V_137 ) ;
}
static int F_47 ( struct V_32 * V_33 ,
struct V_89 * V_90 )
{
struct V_11 * V_12 = V_33 -> V_12 ;
struct V_138 * V_112 ;
struct V_94 * V_78 ;
int V_3 , V_44 ;
V_44 = F_48 ( V_12 , V_90 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_49 ( V_12 , V_90 ) ;
if ( V_44 )
return V_44 ;
if ( V_33 -> V_50 ) {
for ( V_3 = 0 ; V_3 < V_33 -> V_50 -> V_116 ; V_3 ++ ) {
V_78 = V_33 -> V_50 -> V_117 [ V_3 ] . V_98 ;
if ( ! V_78 )
continue;
V_112 = V_33 -> V_50 -> V_117 [ V_3 ] . V_112 ;
if ( V_112 == NULL )
continue;
V_44 = F_50 ( V_12 , V_112 , & V_78 -> V_103 . V_104 ) ;
if ( V_44 )
return V_44 ;
F_51 ( & V_33 -> V_81 [ 0 ] . V_127 , V_112 -> V_139 ) ;
}
}
return F_52 ( V_12 , V_90 , & V_33 -> V_81 [ 0 ] . V_127 ) ;
}
static int F_53 ( struct V_11 * V_12 ,
struct V_32 * V_133 )
{
struct V_39 * V_40 = V_133 -> V_41 -> V_42 ;
struct V_89 * V_90 = & V_40 -> V_90 ;
struct V_16 * V_15 ;
int V_3 , V_44 ;
if ( V_133 -> V_69 == 0 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_133 -> V_69 ; V_3 ++ ) {
V_15 = V_133 -> V_81 [ V_3 ] . V_15 ;
if ( V_15 -> V_140 -> V_141 ) {
V_44 = F_54 ( V_15 , V_133 , V_3 ) ;
if ( V_44 )
return V_44 ;
}
}
F_55 ( & V_90 -> V_142 ) ;
V_44 = F_47 ( V_133 , V_90 ) ;
if ( V_44 ) {
goto V_47;
}
F_35 ( V_133 ) ;
V_44 = F_56 ( V_12 , V_133 -> V_69 , V_133 -> V_81 ,
V_133 -> V_41 ) ;
V_47:
F_57 ( & V_90 -> V_142 ) ;
return V_44 ;
}
static int F_58 ( struct V_11 * V_12 , int V_44 )
{
if ( V_44 == - V_143 ) {
V_44 = F_59 ( V_12 ) ;
if ( ! V_44 )
V_44 = - V_144 ;
}
return V_44 ;
}
static int F_60 ( struct V_11 * V_12 ,
struct V_32 * V_133 )
{
struct V_39 * V_40 = V_133 -> V_41 -> V_42 ;
struct V_89 * V_90 = & V_40 -> V_90 ;
int V_3 , V_145 ;
int V_44 ;
for ( V_3 = 0 , V_145 = 0 ; V_3 < V_133 -> V_57 && V_145 < V_133 -> V_69 ; V_3 ++ ) {
struct V_58 * V_146 ;
struct V_82 * V_147 ;
struct V_148 * V_149 ;
struct V_16 * V_15 ;
V_146 = & V_133 -> V_55 [ V_3 ] ;
V_147 = & V_133 -> V_81 [ V_145 ] ;
V_149 = (struct V_148 * ) V_146 -> V_67 ;
if ( V_146 -> V_63 != V_68 )
continue;
V_44 = F_8 ( V_12 , V_149 -> V_13 ,
V_149 -> V_14 , V_149 -> V_15 ,
& V_15 ) ;
if ( V_44 )
return V_44 ;
if ( V_15 -> V_140 -> V_141 ) {
struct V_150 * V_151 ;
struct V_94 * V_152 = NULL ;
T_2 V_79 ;
T_6 * V_153 ;
V_151 = F_61 ( V_133 , V_149 -> va_start ,
& V_152 ) ;
if ( ! V_152 ) {
F_9 ( L_7 ) ;
return - V_18 ;
}
if ( ( V_149 -> va_start + V_149 -> V_154 ) >
( V_151 -> V_155 . V_156 + 1 ) * V_157 ) {
F_9 ( L_8 ) ;
return - V_18 ;
}
V_44 = F_62 ( V_152 , ( void * * ) & V_153 ) ;
if ( V_44 ) {
return V_44 ;
}
V_79 = ( ( T_2 ) V_151 -> V_155 . V_158 ) * V_157 ;
V_153 += V_149 -> va_start - V_79 ;
V_44 = F_63 ( V_15 , NULL , V_149 -> V_154 , V_147 ) ;
if ( V_44 ) {
F_9 ( L_9 ) ;
return V_44 ;
}
memcpy ( V_147 -> V_159 , V_153 , V_149 -> V_154 ) ;
F_64 ( V_152 ) ;
} else {
V_44 = F_63 ( V_15 , V_90 , 0 , V_147 ) ;
if ( V_44 ) {
F_9 ( L_9 ) ;
return V_44 ;
}
V_147 -> V_160 = V_149 -> va_start ;
}
V_147 -> V_64 = V_149 -> V_154 / 4 ;
V_147 -> V_161 = V_149 -> V_161 ;
V_147 -> V_48 = V_133 -> V_48 ;
V_145 ++ ;
}
if ( ! V_133 -> V_69 )
return 0 ;
if ( V_133 -> V_50 ) {
struct V_94 * V_162 = V_133 -> V_50 -> V_163 ;
struct V_94 * V_164 = V_133 -> V_50 -> V_165 ;
struct V_94 * V_166 = V_133 -> V_50 -> V_167 ;
struct V_82 * V_147 = & V_133 -> V_81 [ 0 ] ;
if ( V_162 ) {
V_147 -> V_168 = F_65 ( V_162 ) ;
V_147 -> V_169 = F_66 ( V_162 ) ;
}
if ( V_164 ) {
V_147 -> V_170 = F_65 ( V_164 ) ;
V_147 -> V_171 = F_66 ( V_164 ) ;
}
if ( V_166 ) {
V_147 -> V_172 = F_65 ( V_166 ) ;
V_147 -> V_173 = F_66 ( V_166 ) ;
}
}
if ( V_133 -> V_77 . V_78 ) {
struct V_82 * V_147 = & V_133 -> V_81 [ V_133 -> V_69 - 1 ] ;
if ( V_147 -> V_15 -> type == V_174 ||
V_147 -> V_15 -> type == V_175 )
return - V_18 ;
V_147 -> V_176 = & V_133 -> V_77 ;
}
return 0 ;
}
static int F_67 ( struct V_11 * V_12 ,
struct V_32 * V_33 )
{
struct V_39 * V_40 = V_33 -> V_41 -> V_42 ;
struct V_82 * V_147 ;
int V_3 , V_145 , V_44 ;
if ( ! V_33 -> V_69 )
return 0 ;
V_147 = & V_33 -> V_81 [ 0 ] ;
for ( V_3 = 0 ; V_3 < V_33 -> V_57 ; ++ V_3 ) {
struct V_177 * V_178 ;
struct V_58 * V_146 ;
unsigned V_179 ;
V_146 = & V_33 -> V_55 [ V_3 ] ;
if ( V_146 -> V_63 != V_80 )
continue;
V_178 = (struct V_177 * ) V_146 -> V_67 ;
V_179 = V_146 -> V_64 * 4 /
sizeof( struct V_177 ) ;
for ( V_145 = 0 ; V_145 < V_179 ; ++ V_145 ) {
struct V_180 * V_135 ;
struct V_16 * V_15 ;
struct V_181 * V_48 ;
V_44 = F_8 ( V_12 , V_178 [ V_145 ] . V_13 ,
V_178 [ V_145 ] . V_14 ,
V_178 [ V_145 ] . V_15 , & V_15 ) ;
if ( V_44 )
return V_44 ;
V_48 = F_11 ( V_40 , V_178 [ V_145 ] . V_49 ) ;
if ( V_48 == NULL )
return - V_18 ;
V_44 = F_68 ( V_15 , V_33 -> V_41 ,
V_178 [ V_145 ] . V_72 ,
& V_135 ) ;
if ( V_44 ) {
F_42 ( V_48 ) ;
return V_44 ;
}
F_51 ( & V_147 -> V_127 , V_135 ) ;
F_69 ( & V_135 ) ;
F_42 ( V_48 ) ;
}
}
return 0 ;
}
int F_70 ( struct V_182 * V_183 , void * V_34 , struct V_184 * V_41 )
{
struct V_11 * V_12 = V_183 -> V_185 ;
union V_35 * V_36 = V_34 ;
struct V_32 V_133 ;
int V_44 , V_3 ;
bool V_186 = false ;
F_33 ( & V_12 -> V_187 ) ;
if ( ! V_12 -> V_188 ) {
F_34 ( & V_12 -> V_187 ) ;
return - V_189 ;
}
memset ( & V_133 , 0 , sizeof( struct V_32 ) ) ;
V_133 . V_41 = V_41 ;
V_133 . V_12 = V_12 ;
V_44 = F_10 ( & V_133 , V_34 ) ;
if ( V_44 ) {
F_9 ( L_10 ) ;
F_39 ( & V_133 , V_44 , false ) ;
F_34 ( & V_12 -> V_187 ) ;
V_44 = F_58 ( V_12 , V_44 ) ;
return V_44 ;
}
V_44 = F_31 ( & V_133 ) ;
if ( V_44 ) {
if ( V_44 != - V_110 ) {
if ( V_44 == - V_54 )
F_9 ( L_11 ) ;
else
F_9 ( L_12 , V_44 ) ;
}
}
if ( ! V_44 ) {
V_186 = true ;
V_44 = F_60 ( V_12 , & V_133 ) ;
}
if ( ! V_44 )
V_44 = F_67 ( V_12 , & V_133 ) ;
if ( V_44 ) {
F_39 ( & V_133 , V_44 , V_186 ) ;
F_34 ( & V_12 -> V_187 ) ;
V_44 = F_58 ( V_12 , V_44 ) ;
return V_44 ;
}
for ( V_3 = 0 ; V_3 < V_133 . V_69 ; V_3 ++ )
F_71 ( & V_133 , V_3 ) ;
V_44 = F_53 ( V_12 , & V_133 ) ;
if ( V_44 ) {
goto V_47;
}
V_36 -> V_47 . V_72 = V_133 . V_81 [ V_133 . V_69 - 1 ] . V_135 -> V_190 ;
V_47:
F_39 ( & V_133 , V_44 , true ) ;
F_34 ( & V_12 -> V_187 ) ;
V_44 = F_58 ( V_12 , V_44 ) ;
return V_44 ;
}
int F_72 ( struct V_182 * V_183 , void * V_34 ,
struct V_184 * V_41 )
{
union V_191 * V_192 = V_34 ;
struct V_11 * V_12 = V_183 -> V_185 ;
unsigned long V_193 = F_73 ( V_192 -> V_45 . V_193 ) ;
struct V_180 * V_135 = NULL ;
struct V_16 * V_15 = NULL ;
struct V_181 * V_48 ;
long V_44 ;
V_48 = F_11 ( V_41 -> V_42 , V_192 -> V_45 . V_49 ) ;
if ( V_48 == NULL )
return - V_18 ;
V_44 = F_8 ( V_12 , V_192 -> V_45 . V_13 , V_192 -> V_45 . V_14 ,
V_192 -> V_45 . V_15 , & V_15 ) ;
if ( V_44 ) {
F_42 ( V_48 ) ;
return V_44 ;
}
V_44 = F_68 ( V_15 , V_41 , V_192 -> V_45 . V_72 , & V_135 ) ;
if ( V_44 ) {
F_42 ( V_48 ) ;
return V_44 ;
}
V_44 = F_74 ( & V_135 -> V_136 , true , V_193 ) ;
F_69 ( & V_135 ) ;
F_42 ( V_48 ) ;
if ( V_44 < 0 )
return V_44 ;
memset ( V_192 , 0 , sizeof( * V_192 ) ) ;
V_192 -> V_47 . V_194 = ( V_44 == 0 ) ;
return 0 ;
}
struct V_150 *
F_61 ( struct V_32 * V_133 ,
T_2 V_195 , struct V_94 * * V_78 )
{
struct V_91 * V_196 ;
struct V_150 * V_197 ;
V_195 /= V_157 ;
F_25 (reloc, &parser->validated, tv.head) {
if ( ! V_196 -> V_112 )
continue;
F_25 (mapping, &reloc->bo_va->mappings, list) {
if ( V_197 -> V_155 . V_158 > V_195 ||
V_195 > V_197 -> V_155 . V_156 )
continue;
* V_78 = V_196 -> V_112 -> V_78 ;
return V_197 ;
}
}
return NULL ;
}
