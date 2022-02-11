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
T_4 V_108 ;
T_2 V_109 ;
int V_110 ;
if ( V_38 -> V_111 )
return 0 ;
if ( V_25 -> V_112 < V_25 -> V_113 )
V_109 = V_38 -> V_114 ;
else
V_109 = V_38 -> V_115 ;
V_116:
F_32 ( V_38 , V_109 ) ;
V_108 = F_23 ( & V_38 -> V_2 -> V_117 ) ;
V_110 = F_33 ( & V_38 -> V_39 , & V_38 -> V_118 , true , false ) ;
V_25 -> V_112 += F_23 ( & V_38 -> V_2 -> V_117 ) -
V_108 ;
if ( F_34 ( V_110 == - V_60 ) && V_109 != V_38 -> V_115 ) {
V_109 = V_38 -> V_115 ;
goto V_116;
}
return V_110 ;
}
static bool F_35 ( struct V_24 * V_25 ,
struct V_119 * V_120 )
{
T_2 V_109 = V_120 -> V_35 -> V_115 ;
int V_110 ;
if ( ! V_25 -> V_121 )
return false ;
for (; & V_25 -> V_121 -> V_37 . V_122 != & V_25 -> V_123 ;
V_25 -> V_121 = F_36 ( V_25 -> V_121 , V_37 . V_122 ) ) {
struct V_119 * V_124 = V_25 -> V_121 ;
struct V_107 * V_38 = V_124 -> V_35 ;
T_4 V_108 ;
T_2 V_125 ;
if ( V_124 == V_120 )
break;
V_125 = F_37 ( V_38 -> V_39 . V_126 . V_127 ) ;
if ( ! ( V_125 & V_109 ) )
continue;
V_125 = V_38 -> V_115 & ~ V_109 ;
if ( ! V_125 )
continue;
F_32 ( V_38 , V_125 ) ;
V_108 = F_23 ( & V_38 -> V_2 -> V_117 ) ;
V_110 = F_33 ( & V_38 -> V_39 , & V_38 -> V_118 , true , false ) ;
V_25 -> V_112 += F_23 ( & V_38 -> V_2 -> V_117 ) -
V_108 ;
if ( F_34 ( V_110 ) )
break;
V_25 -> V_121 = F_36 ( V_25 -> V_121 , V_37 . V_122 ) ;
F_38 ( & V_124 -> V_37 . V_122 , & V_25 -> V_123 ) ;
return true ;
}
return false ;
}
static int F_39 ( struct V_24 * V_25 ,
struct V_128 * V_123 )
{
struct V_119 * V_120 ;
int V_110 ;
F_40 (lobj, validated, tv.head) {
struct V_107 * V_38 = V_120 -> V_35 ;
bool V_129 = false ;
struct V_130 * V_131 ;
V_131 = F_9 ( V_38 -> V_39 . V_43 ) ;
if ( V_131 && V_131 != V_132 -> V_133 )
return - V_134 ;
if ( V_120 -> V_41 && V_38 -> V_39 . V_43 -> V_135 != V_136 ) {
T_6 V_31 = sizeof( struct V_137 * ) ;
V_31 *= V_38 -> V_39 . V_43 -> V_138 ;
memcpy ( V_38 -> V_39 . V_43 -> V_139 , V_120 -> V_41 , V_31 ) ;
V_129 = true ;
}
if ( V_25 -> V_121 == V_120 )
V_25 -> V_121 = NULL ;
do {
V_110 = F_31 ( V_25 , V_38 ) ;
} while ( V_110 == - V_60 && F_35 ( V_25 , V_120 ) );
if ( V_110 )
return V_110 ;
if ( V_38 -> V_140 ) {
V_110 = F_31 ( V_25 , V_38 ) ;
if ( V_110 )
return V_110 ;
}
if ( V_129 ) {
F_18 ( V_120 -> V_41 ) ;
V_120 -> V_41 = NULL ;
}
}
return 0 ;
}
static int F_41 ( struct V_24 * V_25 ,
union V_49 * V_50 )
{
struct V_44 * V_45 = V_25 -> V_32 -> V_46 ;
struct V_119 * V_141 ;
struct V_128 V_142 ;
bool V_143 = false ;
unsigned V_55 , V_144 = 10 ;
int V_110 ;
F_42 ( & V_25 -> V_123 ) ;
V_25 -> V_145 = F_43 ( V_45 , V_50 -> V_57 . V_146 ) ;
if ( V_25 -> V_145 ) {
V_143 = V_25 -> V_145 -> V_147 !=
V_25 -> V_145 -> V_148 ;
F_44 ( V_25 -> V_145 , & V_25 -> V_123 ) ;
}
F_42 ( & V_142 ) ;
F_45 ( & V_45 -> V_48 , & V_25 -> V_123 , & V_25 -> V_149 ) ;
if ( V_25 -> V_34 . V_35 )
F_46 ( & V_25 -> V_34 . V_37 . V_122 , & V_25 -> V_123 ) ;
if ( V_143 )
F_47 ( & V_132 -> V_133 -> V_150 ) ;
while ( 1 ) {
struct V_128 V_151 ;
unsigned V_55 ;
V_110 = F_48 ( & V_25 -> V_152 , & V_25 -> V_123 , true ,
& V_142 ) ;
if ( F_34 ( V_110 != 0 ) ) {
if ( V_110 != - V_153 )
F_2 ( L_7 ) ;
goto V_154;
}
if ( ! V_25 -> V_145 )
break;
F_42 ( & V_151 ) ;
for ( V_55 = V_25 -> V_145 -> V_147 ;
V_55 < V_25 -> V_145 -> V_148 ; ++ V_55 ) {
V_141 = & V_25 -> V_145 -> V_155 [ V_55 ] ;
if ( F_49 ( V_141 -> V_35 -> V_39 . V_43 ,
& V_141 -> V_156 ) && V_141 -> V_41 ) {
F_50 ( V_141 -> V_41 ,
V_141 -> V_35 -> V_39 . V_43 -> V_138 ,
false ) ;
F_18 ( V_141 -> V_41 ) ;
V_141 -> V_41 = NULL ;
}
if ( V_141 -> V_35 -> V_39 . V_43 -> V_135 != V_136 &&
! V_141 -> V_41 ) {
F_51 ( & V_141 -> V_37 . V_122 ) ;
F_46 ( & V_141 -> V_37 . V_122 , & V_151 ) ;
F_52 ( V_141 -> V_35 ) ;
}
}
if ( F_53 ( & V_151 ) )
break;
F_54 ( & V_25 -> V_152 , & V_25 -> V_123 ) ;
if ( ! -- V_144 ) {
V_110 = - V_157 ;
F_2 ( L_8 , V_158 ) ;
goto V_154;
}
F_40 (e, &need_pages, tv.head) {
struct V_159 * V_43 = V_141 -> V_35 -> V_39 . V_43 ;
V_141 -> V_41 = F_55 ( V_43 -> V_138 ,
sizeof( struct V_137 * ) ) ;
if ( ! V_141 -> V_41 ) {
V_110 = - V_60 ;
F_2 ( L_9 , V_158 ) ;
goto V_154;
}
V_110 = F_56 ( V_43 , V_141 -> V_41 ) ;
if ( V_110 ) {
F_2 ( L_10 ) ;
F_18 ( V_141 -> V_41 ) ;
V_141 -> V_41 = NULL ;
goto V_154;
}
}
F_57 ( & V_151 , & V_25 -> V_123 ) ;
}
F_58 ( V_25 -> V_2 , & V_45 -> V_48 , & V_142 ) ;
V_25 -> V_113 = F_22 ( V_25 -> V_2 ) ;
V_25 -> V_112 = 0 ;
V_25 -> V_121 = F_59 ( & V_25 -> V_123 ,
struct V_119 ,
V_37 . V_122 ) ;
V_110 = F_39 ( V_25 , & V_142 ) ;
if ( V_110 ) {
F_2 ( L_11 ) ;
goto V_160;
}
V_110 = F_39 ( V_25 , & V_25 -> V_123 ) ;
if ( V_110 ) {
F_2 ( L_12 ) ;
goto V_160;
}
F_30 ( V_25 -> V_2 , V_25 -> V_112 ) ;
V_45 -> V_48 . V_161 =
F_23 ( & V_25 -> V_2 -> V_162 ) ;
if ( V_25 -> V_145 ) {
struct V_107 * V_163 = V_25 -> V_145 -> V_164 ;
struct V_107 * V_165 = V_25 -> V_145 -> V_166 ;
struct V_107 * V_167 = V_25 -> V_145 -> V_168 ;
struct V_47 * V_48 = & V_45 -> V_48 ;
unsigned V_55 ;
for ( V_55 = 0 ; V_55 < V_25 -> V_145 -> V_148 ; V_55 ++ ) {
struct V_107 * V_38 = V_25 -> V_145 -> V_155 [ V_55 ] . V_35 ;
V_25 -> V_145 -> V_155 [ V_55 ] . V_169 = F_60 ( V_48 , V_38 ) ;
}
if ( V_163 ) {
V_25 -> V_82 -> V_170 = F_61 ( V_163 ) ;
V_25 -> V_82 -> V_171 = F_7 ( V_163 ) ;
}
if ( V_165 ) {
V_25 -> V_82 -> V_172 = F_61 ( V_165 ) ;
V_25 -> V_82 -> V_173 = F_7 ( V_165 ) ;
}
if ( V_167 ) {
V_25 -> V_82 -> V_174 = F_61 ( V_167 ) ;
V_25 -> V_82 -> V_175 = F_7 ( V_167 ) ;
}
}
if ( ! V_110 && V_25 -> V_34 . V_35 ) {
struct V_107 * V_176 = V_25 -> V_34 . V_35 ;
V_110 = F_62 ( & V_176 -> V_39 , & V_176 -> V_39 . V_126 ) ;
V_25 -> V_82 -> V_84 += F_61 ( V_176 ) ;
}
V_160:
if ( V_110 ) {
F_63 ( V_25 -> V_2 , & V_45 -> V_48 ) ;
F_54 ( & V_25 -> V_152 , & V_25 -> V_123 ) ;
}
V_154:
if ( V_143 )
F_64 ( & V_132 -> V_133 -> V_150 ) ;
if ( V_25 -> V_145 ) {
for ( V_55 = V_25 -> V_145 -> V_147 ;
V_55 < V_25 -> V_145 -> V_148 ; ++ V_55 ) {
V_141 = & V_25 -> V_145 -> V_155 [ V_55 ] ;
if ( ! V_141 -> V_41 )
continue;
F_50 ( V_141 -> V_41 ,
V_141 -> V_35 -> V_39 . V_43 -> V_138 ,
false ) ;
F_18 ( V_141 -> V_41 ) ;
}
}
return V_110 ;
}
static int F_65 ( struct V_24 * V_25 )
{
struct V_119 * V_141 ;
int V_110 ;
F_40 (e, &p->validated, tv.head) {
struct V_177 * V_178 = V_141 -> V_35 -> V_39 . V_178 ;
V_110 = F_66 ( V_25 -> V_2 , & V_25 -> V_82 -> V_179 , V_178 , V_25 -> V_32 ) ;
if ( V_110 )
return V_110 ;
}
return 0 ;
}
static void F_67 ( struct V_24 * V_180 , int error , bool V_181 )
{
struct V_44 * V_45 = V_180 -> V_32 -> V_46 ;
unsigned V_55 ;
if ( ! error ) {
F_63 ( V_180 -> V_2 , & V_45 -> V_48 ) ;
F_68 ( & V_180 -> V_152 ,
& V_180 -> V_123 ,
V_180 -> V_182 ) ;
} else if ( V_181 ) {
F_54 ( & V_180 -> V_152 ,
& V_180 -> V_123 ) ;
}
F_69 ( V_180 -> V_182 ) ;
if ( V_180 -> V_61 )
F_19 ( V_180 -> V_61 ) ;
if ( V_180 -> V_145 )
F_70 ( V_180 -> V_145 ) ;
for ( V_55 = 0 ; V_55 < V_180 -> V_68 ; V_55 ++ )
F_18 ( V_180 -> V_65 [ V_55 ] . V_78 ) ;
F_17 ( V_180 -> V_65 ) ;
if ( V_180 -> V_82 )
F_71 ( V_180 -> V_82 ) ;
F_10 ( & V_180 -> V_34 . V_35 ) ;
}
static int F_72 ( struct V_24 * V_25 ,
struct V_47 * V_48 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
struct V_183 * V_169 ;
struct V_107 * V_38 ;
int V_55 , V_110 ;
V_110 = F_73 ( V_2 , V_48 ) ;
if ( V_110 )
return V_110 ;
V_110 = F_74 ( V_2 , & V_25 -> V_82 -> V_179 , V_48 -> V_184 ) ;
if ( V_110 )
return V_110 ;
V_110 = F_75 ( V_2 , V_48 ) ;
if ( V_110 )
return V_110 ;
if ( V_25 -> V_145 ) {
for ( V_55 = 0 ; V_55 < V_25 -> V_145 -> V_148 ; V_55 ++ ) {
struct V_182 * V_185 ;
V_38 = V_25 -> V_145 -> V_155 [ V_55 ] . V_35 ;
if ( ! V_38 )
continue;
V_169 = V_25 -> V_145 -> V_155 [ V_55 ] . V_169 ;
if ( V_169 == NULL )
continue;
V_110 = F_76 ( V_2 , V_169 , false ) ;
if ( V_110 )
return V_110 ;
V_185 = V_169 -> V_186 ;
V_110 = F_74 ( V_2 , & V_25 -> V_82 -> V_179 , V_185 ) ;
if ( V_110 )
return V_110 ;
}
}
V_110 = F_77 ( V_2 , V_48 , & V_25 -> V_82 -> V_179 ) ;
if ( V_187 && V_25 -> V_145 ) {
for ( V_55 = 0 ; V_55 < V_25 -> V_145 -> V_148 ; V_55 ++ ) {
V_38 = V_25 -> V_145 -> V_155 [ V_55 ] . V_35 ;
if ( ! V_38 )
continue;
F_78 ( V_2 , V_38 ) ;
}
}
return V_110 ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_44 * V_45 = V_25 -> V_32 -> V_46 ;
struct V_47 * V_48 = & V_45 -> V_48 ;
struct V_6 * V_5 = V_25 -> V_82 -> V_5 ;
int V_55 , V_110 ;
if ( V_5 -> V_188 -> V_189 ) {
V_25 -> V_82 -> V_48 = NULL ;
for ( V_55 = 0 ; V_55 < V_25 -> V_82 -> V_53 ; V_55 ++ ) {
V_110 = F_80 ( V_5 , V_25 , V_55 ) ;
if ( V_110 )
return V_110 ;
}
} else {
V_25 -> V_82 -> V_190 = F_61 ( V_48 -> V_191 ) ;
V_110 = F_72 ( V_25 , V_48 ) ;
if ( V_110 )
return V_110 ;
}
return F_65 ( V_25 ) ;
}
static int F_81 ( struct V_1 * V_2 , int V_110 )
{
if ( V_110 == - V_157 ) {
V_110 = F_82 ( V_2 ) ;
if ( ! V_110 )
V_110 = - V_192 ;
}
return V_110 ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_24 * V_180 )
{
struct V_44 * V_45 = V_180 -> V_32 -> V_46 ;
struct V_47 * V_48 = & V_45 -> V_48 ;
int V_55 , V_193 ;
int V_110 ;
for ( V_55 = 0 , V_193 = 0 ; V_55 < V_180 -> V_68 && V_193 < V_180 -> V_82 -> V_53 ; V_55 ++ ) {
struct V_69 * V_194 ;
struct V_195 * V_196 ;
struct V_197 * V_198 ;
struct V_6 * V_5 ;
V_194 = & V_180 -> V_65 [ V_55 ] ;
V_196 = & V_180 -> V_82 -> V_199 [ V_193 ] ;
V_198 = (struct V_197 * ) V_194 -> V_78 ;
if ( V_194 -> V_75 != V_79 )
continue;
V_110 = F_1 ( V_2 , V_198 -> V_3 ,
V_198 -> V_4 , V_198 -> V_5 ,
& V_5 ) ;
if ( V_110 )
return V_110 ;
if ( V_196 -> V_104 & V_200 ) {
V_180 -> V_82 -> V_201 |= V_202 ;
if ( ! V_180 -> V_61 -> V_203 ) {
V_180 -> V_82 -> V_201 |= V_204 ;
V_180 -> V_61 -> V_203 = true ;
}
}
if ( V_180 -> V_82 -> V_5 && V_180 -> V_82 -> V_5 != V_5 )
return - V_8 ;
V_180 -> V_82 -> V_5 = V_5 ;
if ( V_5 -> V_188 -> V_189 ) {
struct V_205 * V_206 ;
struct V_107 * V_207 = NULL ;
T_3 V_28 ;
T_7 * V_208 ;
V_206 = F_84 ( V_180 , V_198 -> va_start ,
& V_207 ) ;
if ( ! V_207 ) {
F_2 ( L_13 ) ;
return - V_8 ;
}
if ( ( V_198 -> va_start + V_198 -> V_209 ) >
( V_206 -> V_210 . V_211 + 1 ) * V_212 ) {
F_2 ( L_14 ) ;
return - V_8 ;
}
V_110 = F_85 ( V_207 , ( void * * ) & V_208 ) ;
if ( V_110 ) {
return V_110 ;
}
V_28 = ( ( T_3 ) V_206 -> V_210 . V_213 ) * V_212 ;
V_208 += V_198 -> va_start - V_28 ;
V_110 = F_86 ( V_2 , NULL , V_198 -> V_209 , V_196 ) ;
if ( V_110 ) {
F_2 ( L_15 ) ;
return V_110 ;
}
memcpy ( V_196 -> V_214 , V_208 , V_198 -> V_209 ) ;
F_87 ( V_207 ) ;
} else {
V_110 = F_86 ( V_2 , V_48 , 0 , V_196 ) ;
if ( V_110 ) {
F_2 ( L_15 ) ;
return V_110 ;
}
V_196 -> V_215 = V_198 -> va_start ;
}
V_196 -> V_76 = V_198 -> V_209 / 4 ;
V_196 -> V_104 = V_198 -> V_104 ;
V_193 ++ ;
}
if ( V_180 -> V_82 -> V_84 && (
V_180 -> V_82 -> V_5 -> type == V_216 ||
V_180 -> V_82 -> V_5 -> type == V_217 ) )
return - V_8 ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_44 * V_45 = V_25 -> V_32 -> V_46 ;
int V_55 , V_193 , V_110 ;
for ( V_55 = 0 ; V_55 < V_25 -> V_68 ; ++ V_55 ) {
struct V_218 * V_219 ;
struct V_69 * V_194 ;
unsigned V_220 ;
V_194 = & V_25 -> V_65 [ V_55 ] ;
if ( V_194 -> V_75 != V_81 )
continue;
V_219 = (struct V_218 * ) V_194 -> V_78 ;
V_220 = V_194 -> V_76 * 4 /
sizeof( struct V_218 ) ;
for ( V_193 = 0 ; V_193 < V_220 ; ++ V_193 ) {
struct V_6 * V_5 ;
struct V_221 * V_61 ;
struct V_182 * V_182 ;
V_110 = F_1 ( V_2 , V_219 [ V_193 ] . V_3 ,
V_219 [ V_193 ] . V_4 ,
V_219 [ V_193 ] . V_5 , & V_5 ) ;
if ( V_110 )
return V_110 ;
V_61 = F_13 ( V_45 , V_219 [ V_193 ] . V_62 ) ;
if ( V_61 == NULL )
return - V_8 ;
V_182 = F_89 ( V_61 , V_5 ,
V_219 [ V_193 ] . V_33 ) ;
if ( F_90 ( V_182 ) ) {
V_110 = F_91 ( V_182 ) ;
F_19 ( V_61 ) ;
return V_110 ;
} else if ( V_182 ) {
V_110 = F_74 ( V_2 , & V_25 -> V_82 -> V_179 ,
V_182 ) ;
F_69 ( V_182 ) ;
F_19 ( V_61 ) ;
if ( V_110 )
return V_110 ;
}
}
}
return 0 ;
}
static int F_92 ( struct V_24 * V_25 ,
union V_49 * V_50 )
{
struct V_6 * V_5 = V_25 -> V_82 -> V_5 ;
struct V_222 * V_223 = & V_25 -> V_61 -> V_224 [ V_5 -> V_225 ] . V_223 ;
struct V_226 * V_82 ;
int V_110 ;
V_82 = V_25 -> V_82 ;
V_25 -> V_82 = NULL ;
V_110 = F_93 ( & V_82 -> V_227 , & V_5 -> V_228 , V_223 , V_25 -> V_32 ) ;
if ( V_110 ) {
F_71 ( V_82 ) ;
return V_110 ;
}
V_82 -> V_229 = V_25 -> V_32 ;
V_82 -> V_230 = V_223 -> V_231 ;
V_25 -> V_182 = F_94 ( & V_82 -> V_227 . V_232 -> V_233 ) ;
V_50 -> V_234 . V_33 = F_95 ( V_25 -> V_61 , V_5 , V_25 -> V_182 ) ;
V_82 -> V_235 = V_50 -> V_234 . V_33 ;
F_96 ( V_82 ) ;
F_97 ( V_82 ) ;
F_98 ( & V_82 -> V_227 ) ;
return 0 ;
}
int F_99 ( struct V_236 * V_237 , void * V_27 , struct V_238 * V_32 )
{
struct V_1 * V_2 = V_237 -> V_239 ;
union V_49 * V_50 = V_27 ;
struct V_24 V_180 = {} ;
bool V_240 = false ;
int V_55 , V_110 ;
if ( ! V_2 -> V_241 )
return - V_242 ;
V_180 . V_2 = V_2 ;
V_180 . V_32 = V_32 ;
V_110 = F_11 ( & V_180 , V_27 ) ;
if ( V_110 ) {
F_2 ( L_16 ) ;
F_67 ( & V_180 , V_110 , false ) ;
V_110 = F_81 ( V_2 , V_110 ) ;
return V_110 ;
}
V_110 = F_41 ( & V_180 , V_27 ) ;
if ( V_110 == - V_60 )
F_2 ( L_17 ) ;
else if ( V_110 && V_110 != - V_153 )
F_2 ( L_18 , V_110 ) ;
else if ( ! V_110 ) {
V_240 = true ;
V_110 = F_83 ( V_2 , & V_180 ) ;
}
if ( ! V_110 ) {
V_110 = F_88 ( V_2 , & V_180 ) ;
if ( V_110 )
F_2 ( L_19 , V_110 ) ;
}
if ( V_110 )
goto V_234;
for ( V_55 = 0 ; V_55 < V_180 . V_82 -> V_53 ; V_55 ++ )
F_100 ( & V_180 , V_55 ) ;
V_110 = F_79 ( V_2 , & V_180 ) ;
if ( V_110 )
goto V_234;
V_110 = F_92 ( & V_180 , V_50 ) ;
V_234:
F_67 ( & V_180 , V_110 , V_240 ) ;
V_110 = F_81 ( V_2 , V_110 ) ;
return V_110 ;
}
int F_101 ( struct V_236 * V_237 , void * V_27 ,
struct V_238 * V_32 )
{
union V_243 * V_244 = V_27 ;
struct V_1 * V_2 = V_237 -> V_239 ;
unsigned long V_245 = F_102 ( V_244 -> V_57 . V_245 ) ;
struct V_6 * V_5 = NULL ;
struct V_221 * V_61 ;
struct V_182 * V_182 ;
long V_110 ;
V_110 = F_1 ( V_2 , V_244 -> V_57 . V_3 , V_244 -> V_57 . V_4 ,
V_244 -> V_57 . V_5 , & V_5 ) ;
if ( V_110 )
return V_110 ;
V_61 = F_13 ( V_32 -> V_46 , V_244 -> V_57 . V_62 ) ;
if ( V_61 == NULL )
return - V_8 ;
V_182 = F_89 ( V_61 , V_5 , V_244 -> V_57 . V_33 ) ;
if ( F_90 ( V_182 ) )
V_110 = F_91 ( V_182 ) ;
else if ( V_182 ) {
V_110 = F_103 ( V_182 , true , V_245 ) ;
F_69 ( V_182 ) ;
} else
V_110 = 1 ;
F_19 ( V_61 ) ;
if ( V_110 < 0 )
return V_110 ;
memset ( V_244 , 0 , sizeof( * V_244 ) ) ;
V_244 -> V_234 . V_246 = ( V_110 == 0 ) ;
return 0 ;
}
struct V_205 *
F_84 ( struct V_24 * V_180 ,
T_3 V_247 , struct V_107 * * V_38 )
{
struct V_205 * V_248 ;
unsigned V_55 ;
if ( ! V_180 -> V_145 )
return NULL ;
V_247 /= V_212 ;
for ( V_55 = 0 ; V_55 < V_180 -> V_145 -> V_148 ; V_55 ++ ) {
struct V_119 * V_120 ;
V_120 = & V_180 -> V_145 -> V_155 [ V_55 ] ;
if ( ! V_120 -> V_169 )
continue;
F_40 (mapping, &lobj->bo_va->valids, list) {
if ( V_248 -> V_210 . V_213 > V_247 ||
V_247 > V_248 -> V_210 . V_211 )
continue;
* V_38 = V_120 -> V_169 -> V_38 ;
return V_248 ;
}
F_40 (mapping, &lobj->bo_va->invalids, list) {
if ( V_248 -> V_210 . V_213 > V_247 ||
V_247 > V_248 -> V_210 . V_211 )
continue;
* V_38 = V_120 -> V_169 -> V_38 ;
return V_248 ;
}
}
return NULL ;
}
int F_104 ( struct V_24 * V_180 )
{
unsigned V_55 ;
int V_110 ;
if ( ! V_180 -> V_145 )
return 0 ;
for ( V_55 = 0 ; V_55 < V_180 -> V_145 -> V_148 ; V_55 ++ ) {
struct V_107 * V_38 = V_180 -> V_145 -> V_155 [ V_55 ] . V_35 ;
V_110 = F_62 ( & V_38 -> V_39 , & V_38 -> V_39 . V_126 ) ;
if ( F_34 ( V_110 ) )
return V_110 ;
}
return 0 ;
}
