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
T_2 * V_28 )
{
struct V_29 * V_30 ;
V_30 = F_4 ( V_25 -> V_31 , V_27 -> V_32 ) ;
if ( V_30 == NULL )
return - V_8 ;
V_25 -> V_33 . V_34 = F_5 ( F_6 ( V_30 ) ) ;
V_25 -> V_33 . V_35 = 0 ;
V_25 -> V_33 . V_36 . V_37 = & V_25 -> V_33 . V_34 -> V_38 ;
V_25 -> V_33 . V_36 . V_39 = true ;
V_25 -> V_33 . V_40 = NULL ;
* V_28 = V_27 -> V_28 ;
F_7 ( V_30 ) ;
if ( F_8 ( V_25 -> V_33 . V_34 -> V_38 . V_41 ) ) {
F_9 ( & V_25 -> V_33 . V_34 ) ;
return - V_8 ;
}
return 0 ;
}
int F_10 ( struct V_24 * V_25 , void * V_27 )
{
struct V_42 * V_43 = V_25 -> V_31 -> V_44 ;
struct V_45 * V_46 = & V_43 -> V_46 ;
union V_47 * V_48 = V_27 ;
T_3 * V_49 ;
T_3 * V_50 ;
unsigned V_51 , V_52 = 0 ;
T_2 V_53 = 0 ;
int V_54 ;
int V_55 ;
if ( V_48 -> V_56 . V_57 == 0 )
return 0 ;
V_50 = F_11 ( V_48 -> V_56 . V_57 , sizeof( T_3 ) , V_58 ) ;
if ( ! V_50 )
return - V_59 ;
V_25 -> V_60 = F_12 ( V_43 , V_48 -> V_56 . V_61 ) ;
if ( ! V_25 -> V_60 ) {
V_55 = - V_8 ;
goto V_62;
}
V_49 = ( T_3 V_63 * ) ( unsigned long ) ( V_48 -> V_56 . V_64 ) ;
if ( F_13 ( V_50 , V_49 ,
sizeof( T_3 ) * V_48 -> V_56 . V_57 ) ) {
V_55 = - V_65 ;
goto V_66;
}
V_25 -> V_67 = V_48 -> V_56 . V_57 ;
V_25 -> V_64 = F_11 ( V_25 -> V_67 , sizeof( struct V_68 ) ,
V_58 ) ;
if ( ! V_25 -> V_64 ) {
V_55 = - V_59 ;
goto V_66;
}
for ( V_54 = 0 ; V_54 < V_25 -> V_67 ; V_54 ++ ) {
struct V_69 V_63 * * V_70 = NULL ;
struct V_69 V_71 ;
T_2 V_63 * V_72 ;
V_70 = ( void V_63 * ) ( unsigned long ) V_50 [ V_54 ] ;
if ( F_13 ( & V_71 , V_70 ,
sizeof( struct V_69 ) ) ) {
V_55 = - V_65 ;
V_54 -- ;
goto V_73;
}
V_25 -> V_64 [ V_54 ] . V_74 = V_71 . V_74 ;
V_25 -> V_64 [ V_54 ] . V_75 = V_71 . V_75 ;
V_51 = V_25 -> V_64 [ V_54 ] . V_75 ;
V_72 = ( void V_63 * ) ( unsigned long ) V_71 . V_76 ;
V_25 -> V_64 [ V_54 ] . V_77 = F_14 ( V_51 , sizeof( T_2 ) ) ;
if ( V_25 -> V_64 [ V_54 ] . V_77 == NULL ) {
V_55 = - V_59 ;
V_54 -- ;
goto V_73;
}
V_51 *= sizeof( T_2 ) ;
if ( F_13 ( V_25 -> V_64 [ V_54 ] . V_77 , V_72 , V_51 ) ) {
V_55 = - V_65 ;
goto V_73;
}
switch ( V_25 -> V_64 [ V_54 ] . V_74 ) {
case V_78 :
++ V_52 ;
break;
case V_79 :
V_51 = sizeof( struct V_26 ) ;
if ( V_25 -> V_64 [ V_54 ] . V_75 * sizeof( T_2 ) < V_51 ) {
V_55 = - V_8 ;
goto V_73;
}
V_55 = F_3 ( V_25 , V_25 -> V_64 [ V_54 ] . V_77 ,
& V_53 ) ;
if ( V_55 )
goto V_73;
break;
case V_80 :
break;
default:
V_55 = - V_8 ;
goto V_73;
}
}
V_55 = F_15 ( V_25 -> V_2 , V_52 , & V_25 -> V_81 , V_46 ) ;
if ( V_55 )
goto V_82;
if ( V_25 -> V_33 . V_34 ) {
V_25 -> V_81 -> V_83 = F_5 ( V_25 -> V_33 . V_34 ) ;
V_25 -> V_81 -> V_53 = V_53 ;
}
F_16 ( V_50 ) ;
return 0 ;
V_82:
V_54 = V_25 -> V_67 - 1 ;
V_73:
for (; V_54 >= 0 ; V_54 -- )
F_17 ( V_25 -> V_64 [ V_54 ] . V_77 ) ;
F_16 ( V_25 -> V_64 ) ;
V_66:
F_18 ( V_25 -> V_60 ) ;
V_62:
F_16 ( V_50 ) ;
return V_55 ;
}
static T_4 F_19 ( struct V_1 * V_2 )
{
T_4 V_84 = V_2 -> V_85 . V_84 ;
T_4 V_86 = F_20 ( & V_2 -> V_86 ) ;
T_4 V_87 = V_84 >> 1 ;
T_4 V_88 = V_86 >= V_87 ? 0 : V_87 - V_86 ;
T_4 V_89 = V_88 >> 1 ;
return F_21 ( V_89 , 1024 * 1024ull ) ;
}
int F_22 ( struct V_24 * V_25 ,
struct V_90 * V_91 )
{
struct V_92 * V_93 ;
T_4 V_94 ;
int V_95 ;
F_23 (lobj, validated, tv.head) {
struct V_96 * V_37 = V_93 -> V_34 ;
bool V_97 = false ;
struct V_98 * V_99 ;
T_2 V_100 ;
V_99 = F_8 ( V_37 -> V_38 . V_41 ) ;
if ( V_99 && V_99 != V_101 -> V_102 )
return - V_103 ;
if ( V_93 -> V_40 && V_37 -> V_38 . V_41 -> V_104 != V_105 ) {
T_5 V_51 = sizeof( struct V_106 * ) ;
V_51 *= V_37 -> V_38 . V_41 -> V_107 ;
memcpy ( V_37 -> V_38 . V_41 -> V_108 , V_93 -> V_40 , V_51 ) ;
V_97 = true ;
}
if ( V_37 -> V_109 )
continue;
if ( V_25 -> V_110 <= V_25 -> V_89 )
V_100 = V_37 -> V_111 ;
else
V_100 = V_37 -> V_112 ;
V_113:
F_24 ( V_37 , V_100 ) ;
V_94 = F_20 ( & V_37 -> V_2 -> V_114 ) ;
V_95 = F_25 ( & V_37 -> V_38 , & V_37 -> V_115 , true , false ) ;
V_25 -> V_110 += F_20 ( & V_37 -> V_2 -> V_114 ) -
V_94 ;
if ( F_26 ( V_95 ) ) {
if ( V_95 != - V_116 && V_100 != V_37 -> V_112 ) {
V_100 = V_37 -> V_112 ;
goto V_113;
}
return V_95 ;
}
if ( V_97 ) {
F_17 ( V_93 -> V_40 ) ;
V_93 -> V_40 = NULL ;
}
}
return 0 ;
}
static int F_27 ( struct V_24 * V_25 ,
union V_47 * V_48 )
{
struct V_42 * V_43 = V_25 -> V_31 -> V_44 ;
struct V_92 * V_117 ;
struct V_90 V_118 ;
bool V_119 = false ;
unsigned V_54 , V_120 = 10 ;
int V_95 ;
F_28 ( & V_25 -> V_91 ) ;
V_25 -> V_121 = F_29 ( V_43 , V_48 -> V_56 . V_122 ) ;
if ( V_25 -> V_121 ) {
V_119 = V_25 -> V_121 -> V_123 !=
V_25 -> V_121 -> V_124 ;
F_30 ( V_25 -> V_121 , & V_25 -> V_91 ) ;
}
F_28 ( & V_118 ) ;
F_31 ( & V_43 -> V_46 , & V_25 -> V_91 , & V_25 -> V_125 ) ;
if ( V_25 -> V_33 . V_34 )
F_32 ( & V_25 -> V_33 . V_36 . V_126 , & V_25 -> V_91 ) ;
if ( V_119 )
F_33 ( & V_101 -> V_102 -> V_127 ) ;
while ( 1 ) {
struct V_90 V_128 ;
unsigned V_54 ;
V_95 = F_34 ( & V_25 -> V_129 , & V_25 -> V_91 , true ,
& V_118 ) ;
if ( F_26 ( V_95 != 0 ) )
goto V_130;
if ( ! V_25 -> V_121 )
break;
F_28 ( & V_128 ) ;
for ( V_54 = V_25 -> V_121 -> V_123 ;
V_54 < V_25 -> V_121 -> V_124 ; ++ V_54 ) {
V_117 = & V_25 -> V_121 -> V_131 [ V_54 ] ;
if ( F_35 ( V_117 -> V_34 -> V_38 . V_41 ,
& V_117 -> V_132 ) && V_117 -> V_40 ) {
F_36 ( V_117 -> V_40 ,
V_117 -> V_34 -> V_38 . V_41 -> V_107 ,
false ) ;
F_17 ( V_117 -> V_40 ) ;
V_117 -> V_40 = NULL ;
}
if ( V_117 -> V_34 -> V_38 . V_41 -> V_104 != V_105 &&
! V_117 -> V_40 ) {
F_37 ( & V_117 -> V_36 . V_126 ) ;
F_32 ( & V_117 -> V_36 . V_126 , & V_128 ) ;
F_38 ( V_117 -> V_34 ) ;
}
}
if ( F_39 ( & V_128 ) )
break;
F_40 ( & V_25 -> V_129 , & V_25 -> V_91 ) ;
if ( ! -- V_120 ) {
V_95 = - V_133 ;
goto V_130;
}
F_23 (e, &need_pages, tv.head) {
struct V_134 * V_41 = V_117 -> V_34 -> V_38 . V_41 ;
V_117 -> V_40 = F_41 ( V_41 -> V_107 ,
sizeof( struct V_106 * ) ) ;
if ( ! V_117 -> V_40 ) {
V_95 = - V_59 ;
goto V_130;
}
V_95 = F_42 ( V_41 , V_117 -> V_40 ) ;
if ( V_95 ) {
F_17 ( V_117 -> V_40 ) ;
V_117 -> V_40 = NULL ;
goto V_130;
}
}
F_43 ( & V_128 , & V_25 -> V_91 ) ;
}
F_44 ( & V_43 -> V_46 , & V_118 ) ;
V_25 -> V_89 = F_19 ( V_25 -> V_2 ) ;
V_25 -> V_110 = 0 ;
V_95 = F_22 ( V_25 , & V_118 ) ;
if ( V_95 )
goto V_135;
V_95 = F_22 ( V_25 , & V_25 -> V_91 ) ;
if ( V_95 )
goto V_135;
if ( V_25 -> V_121 ) {
struct V_96 * V_136 = V_25 -> V_121 -> V_137 ;
struct V_96 * V_138 = V_25 -> V_121 -> V_139 ;
struct V_96 * V_140 = V_25 -> V_121 -> V_141 ;
struct V_45 * V_46 = & V_43 -> V_46 ;
unsigned V_54 ;
for ( V_54 = 0 ; V_54 < V_25 -> V_121 -> V_124 ; V_54 ++ ) {
struct V_96 * V_37 = V_25 -> V_121 -> V_131 [ V_54 ] . V_34 ;
V_25 -> V_121 -> V_131 [ V_54 ] . V_142 = F_45 ( V_46 , V_37 ) ;
}
if ( V_136 ) {
V_25 -> V_81 -> V_143 = F_46 ( V_136 ) ;
V_25 -> V_81 -> V_144 = F_47 ( V_136 ) ;
}
if ( V_138 ) {
V_25 -> V_81 -> V_145 = F_46 ( V_138 ) ;
V_25 -> V_81 -> V_146 = F_47 ( V_138 ) ;
}
if ( V_140 ) {
V_25 -> V_81 -> V_147 = F_46 ( V_140 ) ;
V_25 -> V_81 -> V_148 = F_47 ( V_140 ) ;
}
}
V_135:
if ( V_95 ) {
F_48 ( V_25 -> V_2 , & V_43 -> V_46 ) ;
F_40 ( & V_25 -> V_129 , & V_25 -> V_91 ) ;
}
V_130:
if ( V_119 )
F_49 ( & V_101 -> V_102 -> V_127 ) ;
if ( V_25 -> V_121 ) {
for ( V_54 = V_25 -> V_121 -> V_123 ;
V_54 < V_25 -> V_121 -> V_124 ; ++ V_54 ) {
V_117 = & V_25 -> V_121 -> V_131 [ V_54 ] ;
if ( ! V_117 -> V_40 )
continue;
F_36 ( V_117 -> V_40 ,
V_117 -> V_34 -> V_38 . V_41 -> V_107 ,
false ) ;
F_17 ( V_117 -> V_40 ) ;
}
}
return V_95 ;
}
static int F_50 ( struct V_24 * V_25 )
{
struct V_92 * V_117 ;
int V_95 ;
F_23 (e, &p->validated, tv.head) {
struct V_149 * V_150 = V_117 -> V_34 -> V_38 . V_150 ;
V_95 = F_51 ( V_25 -> V_2 , & V_25 -> V_81 -> V_151 , V_150 , V_25 -> V_31 ) ;
if ( V_95 )
return V_95 ;
}
return 0 ;
}
static void F_52 ( struct V_24 * V_152 , int error , bool V_153 )
{
struct V_42 * V_43 = V_152 -> V_31 -> V_44 ;
unsigned V_54 ;
if ( ! error ) {
F_48 ( V_152 -> V_2 , & V_43 -> V_46 ) ;
F_53 ( & V_152 -> V_129 ,
& V_152 -> V_91 ,
V_152 -> V_154 ) ;
} else if ( V_153 ) {
F_40 ( & V_152 -> V_129 ,
& V_152 -> V_91 ) ;
}
F_54 ( V_152 -> V_154 ) ;
if ( V_152 -> V_60 )
F_18 ( V_152 -> V_60 ) ;
if ( V_152 -> V_121 )
F_55 ( V_152 -> V_121 ) ;
for ( V_54 = 0 ; V_54 < V_152 -> V_67 ; V_54 ++ )
F_17 ( V_152 -> V_64 [ V_54 ] . V_77 ) ;
F_16 ( V_152 -> V_64 ) ;
if ( V_152 -> V_81 )
F_56 ( V_152 -> V_81 ) ;
F_9 ( & V_152 -> V_33 . V_34 ) ;
}
static int F_57 ( struct V_24 * V_25 ,
struct V_45 * V_46 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
struct V_155 * V_142 ;
struct V_96 * V_37 ;
int V_54 , V_95 ;
V_95 = F_58 ( V_2 , V_46 ) ;
if ( V_95 )
return V_95 ;
V_95 = F_59 ( V_2 , & V_25 -> V_81 -> V_151 , V_46 -> V_156 ) ;
if ( V_95 )
return V_95 ;
V_95 = F_60 ( V_2 , V_46 ) ;
if ( V_95 )
return V_95 ;
if ( V_25 -> V_121 ) {
for ( V_54 = 0 ; V_54 < V_25 -> V_121 -> V_124 ; V_54 ++ ) {
struct V_154 * V_157 ;
V_37 = V_25 -> V_121 -> V_131 [ V_54 ] . V_34 ;
if ( ! V_37 )
continue;
V_142 = V_25 -> V_121 -> V_131 [ V_54 ] . V_142 ;
if ( V_142 == NULL )
continue;
V_95 = F_61 ( V_2 , V_142 , & V_37 -> V_38 . V_158 ) ;
if ( V_95 )
return V_95 ;
V_157 = V_142 -> V_159 ;
V_95 = F_59 ( V_2 , & V_25 -> V_81 -> V_151 , V_157 ) ;
if ( V_95 )
return V_95 ;
}
}
V_95 = F_62 ( V_2 , V_46 , & V_25 -> V_81 -> V_151 ) ;
if ( V_160 && V_25 -> V_121 ) {
for ( V_54 = 0 ; V_54 < V_25 -> V_121 -> V_124 ; V_54 ++ ) {
V_37 = V_25 -> V_121 -> V_131 [ V_54 ] . V_34 ;
if ( ! V_37 )
continue;
F_63 ( V_2 , V_37 ) ;
}
}
return V_95 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_42 * V_43 = V_25 -> V_31 -> V_44 ;
struct V_45 * V_46 = & V_43 -> V_46 ;
struct V_6 * V_5 = V_25 -> V_81 -> V_5 ;
int V_54 , V_95 ;
if ( V_5 -> V_161 -> V_162 ) {
for ( V_54 = 0 ; V_54 < V_25 -> V_81 -> V_52 ; V_54 ++ ) {
V_95 = F_65 ( V_5 , V_25 , V_54 ) ;
if ( V_95 )
return V_95 ;
}
}
V_95 = F_57 ( V_25 , V_46 ) ;
if ( ! V_95 )
F_50 ( V_25 ) ;
return V_95 ;
}
static int F_66 ( struct V_1 * V_2 , int V_95 )
{
if ( V_95 == - V_133 ) {
V_95 = F_67 ( V_2 ) ;
if ( ! V_95 )
V_95 = - V_163 ;
}
return V_95 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_24 * V_152 )
{
struct V_42 * V_43 = V_152 -> V_31 -> V_44 ;
struct V_45 * V_46 = & V_43 -> V_46 ;
int V_54 , V_164 ;
int V_95 ;
for ( V_54 = 0 , V_164 = 0 ; V_54 < V_152 -> V_67 && V_164 < V_152 -> V_81 -> V_52 ; V_54 ++ ) {
struct V_68 * V_165 ;
struct V_166 * V_167 ;
struct V_168 * V_169 ;
struct V_6 * V_5 ;
V_165 = & V_152 -> V_64 [ V_54 ] ;
V_167 = & V_152 -> V_81 -> V_170 [ V_164 ] ;
V_169 = (struct V_168 * ) V_165 -> V_77 ;
if ( V_165 -> V_74 != V_78 )
continue;
V_95 = F_1 ( V_2 , V_169 -> V_3 ,
V_169 -> V_4 , V_169 -> V_5 ,
& V_5 ) ;
if ( V_95 )
return V_95 ;
if ( V_152 -> V_81 -> V_5 && V_152 -> V_81 -> V_5 != V_5 )
return - V_8 ;
V_152 -> V_81 -> V_5 = V_5 ;
if ( V_5 -> V_161 -> V_162 ) {
struct V_171 * V_172 ;
struct V_96 * V_173 = NULL ;
T_3 V_28 ;
T_6 * V_174 ;
V_172 = F_69 ( V_152 , V_169 -> va_start ,
& V_173 ) ;
if ( ! V_173 ) {
F_2 ( L_7 ) ;
return - V_8 ;
}
if ( ( V_169 -> va_start + V_169 -> V_175 ) >
( V_172 -> V_176 . V_177 + 1 ) * V_178 ) {
F_2 ( L_8 ) ;
return - V_8 ;
}
V_95 = F_70 ( V_173 , ( void * * ) & V_174 ) ;
if ( V_95 ) {
return V_95 ;
}
V_28 = ( ( T_3 ) V_172 -> V_176 . V_179 ) * V_178 ;
V_174 += V_169 -> va_start - V_28 ;
V_95 = F_71 ( V_2 , NULL , V_169 -> V_175 , V_167 ) ;
if ( V_95 ) {
F_2 ( L_9 ) ;
return V_95 ;
}
memcpy ( V_167 -> V_180 , V_174 , V_169 -> V_175 ) ;
F_72 ( V_173 ) ;
} else {
V_95 = F_71 ( V_2 , V_46 , 0 , V_167 ) ;
if ( V_95 ) {
F_2 ( L_9 ) ;
return V_95 ;
}
V_167 -> V_181 = V_169 -> va_start ;
}
V_167 -> V_75 = V_169 -> V_175 / 4 ;
V_167 -> V_182 = V_169 -> V_182 ;
V_164 ++ ;
}
if ( V_152 -> V_81 -> V_83 && (
V_152 -> V_81 -> V_5 -> type == V_183 ||
V_152 -> V_81 -> V_5 -> type == V_184 ) )
return - V_8 ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_42 * V_43 = V_25 -> V_31 -> V_44 ;
int V_54 , V_164 , V_95 ;
for ( V_54 = 0 ; V_54 < V_25 -> V_67 ; ++ V_54 ) {
struct V_185 * V_186 ;
struct V_68 * V_165 ;
unsigned V_187 ;
V_165 = & V_25 -> V_64 [ V_54 ] ;
if ( V_165 -> V_74 != V_80 )
continue;
V_186 = (struct V_185 * ) V_165 -> V_77 ;
V_187 = V_165 -> V_75 * 4 /
sizeof( struct V_185 ) ;
for ( V_164 = 0 ; V_164 < V_187 ; ++ V_164 ) {
struct V_6 * V_5 ;
struct V_188 * V_60 ;
struct V_154 * V_154 ;
V_95 = F_1 ( V_2 , V_186 [ V_164 ] . V_3 ,
V_186 [ V_164 ] . V_4 ,
V_186 [ V_164 ] . V_5 , & V_5 ) ;
if ( V_95 )
return V_95 ;
V_60 = F_12 ( V_43 , V_186 [ V_164 ] . V_61 ) ;
if ( V_60 == NULL )
return - V_8 ;
V_154 = F_74 ( V_60 , V_5 ,
V_186 [ V_164 ] . V_32 ) ;
if ( F_75 ( V_154 ) ) {
V_95 = F_76 ( V_154 ) ;
F_18 ( V_60 ) ;
return V_95 ;
} else if ( V_154 ) {
V_95 = F_59 ( V_2 , & V_25 -> V_81 -> V_151 ,
V_154 ) ;
F_54 ( V_154 ) ;
F_18 ( V_60 ) ;
if ( V_95 )
return V_95 ;
}
}
}
return 0 ;
}
static int F_77 ( struct V_24 * V_25 ,
union V_47 * V_48 )
{
struct V_6 * V_5 = V_25 -> V_81 -> V_5 ;
struct V_189 * V_190 = & V_25 -> V_60 -> V_191 [ V_5 -> V_192 ] . V_190 ;
struct V_154 * V_154 ;
struct V_193 * V_81 ;
int V_95 ;
V_81 = V_25 -> V_81 ;
V_25 -> V_81 = NULL ;
V_95 = F_78 ( & V_81 -> V_194 , & V_5 -> V_195 ,
V_190 , V_196 ,
V_197 ,
V_25 -> V_31 , & V_154 ) ;
if ( V_95 ) {
F_56 ( V_81 ) ;
return V_95 ;
}
V_81 -> V_198 = V_25 -> V_31 ;
V_81 -> V_60 = V_190 -> V_199 ;
V_25 -> V_154 = F_79 ( V_154 ) ;
V_48 -> V_200 . V_32 = F_80 ( V_25 -> V_60 , V_5 , V_154 ) ;
V_81 -> V_201 = V_48 -> V_200 . V_32 ;
F_81 ( V_81 ) ;
F_82 ( & V_81 -> V_194 ) ;
return 0 ;
}
int F_83 ( struct V_202 * V_203 , void * V_27 , struct V_204 * V_31 )
{
struct V_1 * V_2 = V_203 -> V_205 ;
union V_47 * V_48 = V_27 ;
struct V_24 V_152 = {} ;
bool V_206 = false ;
int V_54 , V_95 ;
if ( ! V_2 -> V_207 )
return - V_208 ;
V_152 . V_2 = V_2 ;
V_152 . V_31 = V_31 ;
V_95 = F_10 ( & V_152 , V_27 ) ;
if ( V_95 ) {
F_2 ( L_10 ) ;
F_52 ( & V_152 , V_95 , false ) ;
V_95 = F_66 ( V_2 , V_95 ) ;
return V_95 ;
}
V_95 = F_27 ( & V_152 , V_27 ) ;
if ( V_95 == - V_59 )
F_2 ( L_11 ) ;
else if ( V_95 && V_95 != - V_116 )
F_2 ( L_12 , V_95 ) ;
else if ( ! V_95 ) {
V_206 = true ;
V_95 = F_68 ( V_2 , & V_152 ) ;
}
if ( ! V_95 ) {
V_95 = F_73 ( V_2 , & V_152 ) ;
if ( V_95 )
F_2 ( L_13 , V_95 ) ;
}
if ( V_95 )
goto V_200;
for ( V_54 = 0 ; V_54 < V_152 . V_81 -> V_52 ; V_54 ++ )
F_84 ( & V_152 , V_54 ) ;
V_95 = F_64 ( V_2 , & V_152 ) ;
if ( V_95 )
goto V_200;
V_95 = F_77 ( & V_152 , V_48 ) ;
V_200:
F_52 ( & V_152 , V_95 , V_206 ) ;
V_95 = F_66 ( V_2 , V_95 ) ;
return V_95 ;
}
int F_85 ( struct V_202 * V_203 , void * V_27 ,
struct V_204 * V_31 )
{
union V_209 * V_210 = V_27 ;
struct V_1 * V_2 = V_203 -> V_205 ;
unsigned long V_211 = F_86 ( V_210 -> V_56 . V_211 ) ;
struct V_6 * V_5 = NULL ;
struct V_188 * V_60 ;
struct V_154 * V_154 ;
long V_95 ;
V_95 = F_1 ( V_2 , V_210 -> V_56 . V_3 , V_210 -> V_56 . V_4 ,
V_210 -> V_56 . V_5 , & V_5 ) ;
if ( V_95 )
return V_95 ;
V_60 = F_12 ( V_31 -> V_44 , V_210 -> V_56 . V_61 ) ;
if ( V_60 == NULL )
return - V_8 ;
V_154 = F_74 ( V_60 , V_5 , V_210 -> V_56 . V_32 ) ;
if ( F_75 ( V_154 ) )
V_95 = F_76 ( V_154 ) ;
else if ( V_154 ) {
V_95 = F_87 ( V_154 , true , V_211 ) ;
F_54 ( V_154 ) ;
} else
V_95 = 1 ;
F_18 ( V_60 ) ;
if ( V_95 < 0 )
return V_95 ;
memset ( V_210 , 0 , sizeof( * V_210 ) ) ;
V_210 -> V_200 . V_212 = ( V_95 == 0 ) ;
return 0 ;
}
struct V_171 *
F_69 ( struct V_24 * V_152 ,
T_3 V_213 , struct V_96 * * V_37 )
{
struct V_171 * V_214 ;
unsigned V_54 ;
if ( ! V_152 -> V_121 )
return NULL ;
V_213 /= V_178 ;
for ( V_54 = 0 ; V_54 < V_152 -> V_121 -> V_124 ; V_54 ++ ) {
struct V_92 * V_93 ;
V_93 = & V_152 -> V_121 -> V_131 [ V_54 ] ;
if ( ! V_93 -> V_142 )
continue;
F_23 (mapping, &lobj->bo_va->valids, list) {
if ( V_214 -> V_176 . V_179 > V_213 ||
V_213 > V_214 -> V_176 . V_177 )
continue;
* V_37 = V_93 -> V_142 -> V_37 ;
return V_214 ;
}
F_23 (mapping, &lobj->bo_va->invalids, list) {
if ( V_214 -> V_176 . V_179 > V_213 ||
V_213 > V_214 -> V_176 . V_177 )
continue;
* V_37 = V_93 -> V_142 -> V_37 ;
return V_214 ;
}
}
return NULL ;
}
