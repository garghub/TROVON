static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 )
{
struct V_6 * V_7 ;
unsigned long V_8 ;
V_7 = F_2 ( V_2 -> V_9 , V_4 -> V_10 ) ;
if ( V_7 == NULL )
return - V_11 ;
V_2 -> V_12 . V_13 = F_3 ( F_4 ( V_7 ) ) ;
V_2 -> V_12 . V_14 = 0 ;
V_2 -> V_12 . V_15 . V_16 = & V_2 -> V_12 . V_13 -> V_17 ;
V_2 -> V_12 . V_15 . V_18 = true ;
V_2 -> V_12 . V_19 = NULL ;
V_8 = F_5 ( V_2 -> V_12 . V_13 ) ;
if ( V_8 != V_20 || ( V_4 -> V_5 + 8 ) > V_8 )
return - V_11 ;
* V_5 = V_4 -> V_5 ;
F_6 ( V_7 ) ;
if ( F_7 ( V_2 -> V_12 . V_13 -> V_17 . V_21 ) ) {
F_8 ( & V_2 -> V_12 . V_13 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , void * V_4 )
{
struct V_22 * V_23 = V_2 -> V_9 -> V_24 ;
struct V_25 * V_26 = & V_23 -> V_26 ;
union V_27 * V_28 = V_4 ;
T_2 * V_29 ;
T_2 * V_30 ;
unsigned V_8 , V_31 = 0 ;
T_1 V_32 = 0 ;
int V_33 ;
int V_34 ;
if ( V_28 -> V_35 . V_36 == 0 )
return 0 ;
V_30 = F_10 ( V_28 -> V_35 . V_36 , sizeof( T_2 ) , V_37 ) ;
if ( ! V_30 )
return - V_38 ;
V_2 -> V_39 = F_11 ( V_23 , V_28 -> V_35 . V_40 ) ;
if ( ! V_2 -> V_39 ) {
V_34 = - V_11 ;
goto V_41;
}
V_29 = F_12 ( V_28 -> V_35 . V_42 ) ;
if ( F_13 ( V_30 , V_29 ,
sizeof( T_2 ) * V_28 -> V_35 . V_36 ) ) {
V_34 = - V_43 ;
goto V_44;
}
V_2 -> V_45 = V_28 -> V_35 . V_36 ;
V_2 -> V_42 = F_10 ( V_2 -> V_45 , sizeof( struct V_46 ) ,
V_37 ) ;
if ( ! V_2 -> V_42 ) {
V_34 = - V_38 ;
goto V_44;
}
for ( V_33 = 0 ; V_33 < V_2 -> V_45 ; V_33 ++ ) {
struct V_47 T_3 * * V_48 = NULL ;
struct V_47 V_49 ;
T_1 T_3 * V_50 ;
V_48 = F_12 ( V_30 [ V_33 ] ) ;
if ( F_13 ( & V_49 , V_48 ,
sizeof( struct V_47 ) ) ) {
V_34 = - V_43 ;
V_33 -- ;
goto V_51;
}
V_2 -> V_42 [ V_33 ] . V_52 = V_49 . V_52 ;
V_2 -> V_42 [ V_33 ] . V_53 = V_49 . V_53 ;
V_8 = V_2 -> V_42 [ V_33 ] . V_53 ;
V_50 = F_12 ( V_49 . V_54 ) ;
V_2 -> V_42 [ V_33 ] . V_55 = F_14 ( V_8 , sizeof( T_1 ) , V_37 ) ;
if ( V_2 -> V_42 [ V_33 ] . V_55 == NULL ) {
V_34 = - V_38 ;
V_33 -- ;
goto V_51;
}
V_8 *= sizeof( T_1 ) ;
if ( F_13 ( V_2 -> V_42 [ V_33 ] . V_55 , V_50 , V_8 ) ) {
V_34 = - V_43 ;
goto V_51;
}
switch ( V_2 -> V_42 [ V_33 ] . V_52 ) {
case V_56 :
++ V_31 ;
break;
case V_57 :
V_8 = sizeof( struct V_3 ) ;
if ( V_2 -> V_42 [ V_33 ] . V_53 * sizeof( T_1 ) < V_8 ) {
V_34 = - V_11 ;
goto V_51;
}
V_34 = F_1 ( V_2 , V_2 -> V_42 [ V_33 ] . V_55 ,
& V_32 ) ;
if ( V_34 )
goto V_51;
break;
case V_58 :
case V_59 :
case V_60 :
break;
default:
V_34 = - V_11 ;
goto V_51;
}
}
V_34 = F_15 ( V_2 -> V_61 , V_31 , & V_2 -> V_62 , V_26 ) ;
if ( V_34 )
goto V_63;
if ( V_2 -> V_12 . V_13 )
V_2 -> V_62 -> V_64 = V_32 ;
F_16 ( V_30 ) ;
return 0 ;
V_63:
V_33 = V_2 -> V_45 - 1 ;
V_51:
for (; V_33 >= 0 ; V_33 -- )
F_17 ( V_2 -> V_42 [ V_33 ] . V_55 ) ;
F_16 ( V_2 -> V_42 ) ;
V_2 -> V_42 = NULL ;
V_2 -> V_45 = 0 ;
V_44:
F_18 ( V_2 -> V_39 ) ;
V_41:
F_16 ( V_30 ) ;
return V_34 ;
}
static T_4 F_19 ( struct V_65 * V_61 , T_5 V_66 )
{
if ( V_66 <= 0 || ! V_61 -> V_67 . V_68 )
return 0 ;
return V_66 << V_61 -> V_67 . V_68 ;
}
static T_5 F_20 ( struct V_65 * V_61 , T_4 V_69 )
{
if ( ! V_61 -> V_67 . V_68 )
return 0 ;
return V_69 >> V_61 -> V_67 . V_68 ;
}
static void F_21 ( struct V_65 * V_61 ,
T_4 * V_70 ,
T_4 * V_71 )
{
T_5 V_72 , V_73 ;
T_4 V_74 , V_75 , V_76 ;
const T_5 V_77 = 200000 ;
if ( ! V_61 -> V_67 . V_68 ) {
* V_70 = 0 ;
* V_71 = 0 ;
return;
}
V_75 = V_61 -> V_78 . V_79 - V_61 -> V_80 ;
V_76 = F_22 ( & V_61 -> V_81 . V_82 . V_83 [ V_84 ] ) ;
V_74 = V_76 >= V_75 ? 0 : V_75 - V_76 ;
F_23 ( & V_61 -> V_67 . V_85 ) ;
V_72 = F_24 ( F_25 () ) ;
V_73 = V_72 - V_61 -> V_67 . V_86 ;
V_61 -> V_67 . V_86 = V_72 ;
V_61 -> V_67 . V_87 = F_26 ( V_61 -> V_67 . V_87 + V_73 ,
V_77 ) ;
if ( V_74 >= 128 * 1024 * 1024 || V_74 >= V_75 / 8 ) {
T_5 V_88 ;
if ( ! ( V_61 -> V_89 & V_90 ) )
V_88 = F_20 ( V_61 , V_74 / 4 ) ;
else
V_88 = 0 ;
V_61 -> V_67 . V_87 = F_27 ( V_88 , V_61 -> V_67 . V_87 ) ;
}
* V_70 = F_19 ( V_61 , V_61 -> V_67 . V_87 ) ;
if ( V_61 -> V_78 . V_91 < V_61 -> V_78 . V_79 ) {
T_4 V_92 = V_61 -> V_78 . V_91 ;
T_4 V_93 =
F_28 ( & V_61 -> V_81 . V_82 . V_83 [ V_84 ] ) ;
if ( V_93 < V_92 ) {
T_4 V_94 = V_92 - V_93 ;
V_61 -> V_67 . V_95 = F_26 ( V_61 -> V_67 . V_95 +
V_73 , V_77 ) ;
if ( V_94 >= V_92 / 2 )
V_61 -> V_67 . V_95 =
F_27 ( F_20 ( V_61 , V_94 / 2 ) ,
V_61 -> V_67 . V_95 ) ;
}
* V_71 = F_19 ( V_61 , V_61 -> V_67 . V_95 ) ;
} else {
* V_71 = 0 ;
}
F_29 ( & V_61 -> V_67 . V_85 ) ;
}
void F_30 ( struct V_65 * V_61 , T_4 V_96 ,
T_4 V_97 )
{
F_23 ( & V_61 -> V_67 . V_85 ) ;
V_61 -> V_67 . V_87 -= F_20 ( V_61 , V_96 ) ;
V_61 -> V_67 . V_95 -= F_20 ( V_61 , V_97 ) ;
F_29 ( & V_61 -> V_67 . V_85 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_98 * V_16 )
{
struct V_65 * V_61 = F_32 ( V_16 -> V_17 . V_82 ) ;
T_4 V_99 , V_100 ;
T_1 V_101 ;
int V_102 ;
if ( V_16 -> V_103 )
return 0 ;
if ( V_2 -> V_100 < V_2 -> V_104 ) {
if ( V_61 -> V_78 . V_91 < V_61 -> V_78 . V_79 &&
( V_16 -> V_89 & V_105 ) ) {
if ( V_2 -> V_106 < V_2 -> V_107 )
V_101 = V_16 -> V_108 ;
else
V_101 = V_16 -> V_109 ;
} else {
V_101 = V_16 -> V_108 ;
}
} else {
V_101 = V_16 -> V_109 ;
}
V_110:
F_33 ( V_16 , V_101 ) ;
V_99 = F_34 ( & V_61 -> V_111 ) ;
V_102 = F_35 ( & V_16 -> V_17 , & V_16 -> V_112 , true , false ) ;
V_100 = F_34 ( & V_61 -> V_111 ) -
V_99 ;
V_2 -> V_100 += V_100 ;
if ( V_61 -> V_78 . V_91 < V_61 -> V_78 . V_79 &&
V_16 -> V_17 . V_113 . V_114 == V_84 &&
V_16 -> V_17 . V_113 . V_115 < V_61 -> V_78 . V_91 >> V_116 )
V_2 -> V_106 += V_100 ;
if ( F_36 ( V_102 == - V_38 ) && V_101 != V_16 -> V_109 ) {
V_101 = V_16 -> V_109 ;
goto V_110;
}
return V_102 ;
}
static bool F_37 ( struct V_1 * V_2 ,
struct V_98 * V_117 )
{
T_1 V_101 = V_117 -> V_109 ;
int V_102 ;
if ( ! V_2 -> V_118 )
return false ;
for (; & V_2 -> V_118 -> V_15 . V_119 != & V_2 -> V_117 ;
V_2 -> V_118 = F_38 ( V_2 -> V_118 , V_15 . V_119 ) ) {
struct V_120 * V_121 = V_2 -> V_118 ;
struct V_98 * V_16 = V_121 -> V_13 ;
struct V_65 * V_61 = F_32 ( V_16 -> V_17 . V_82 ) ;
T_4 V_99 , V_100 ;
bool V_122 ;
T_1 V_123 ;
if ( V_121 -> V_13 == V_117 )
break;
V_123 = F_39 ( V_16 -> V_17 . V_113 . V_114 ) ;
if ( ! ( V_123 & V_101 ) )
continue;
V_123 = V_16 -> V_109 & ~ V_101 ;
if ( ! V_123 )
continue;
F_33 ( V_16 , V_123 ) ;
V_122 =
V_61 -> V_78 . V_91 < V_61 -> V_78 . V_79 &&
V_16 -> V_17 . V_113 . V_114 == V_84 &&
V_16 -> V_17 . V_113 . V_115 < V_61 -> V_78 . V_91 >> V_116 ;
V_99 = F_34 ( & V_61 -> V_111 ) ;
V_102 = F_35 ( & V_16 -> V_17 , & V_16 -> V_112 , true , false ) ;
V_100 = F_34 ( & V_61 -> V_111 ) -
V_99 ;
V_2 -> V_100 += V_100 ;
if ( V_122 )
V_2 -> V_106 += V_100 ;
if ( F_36 ( V_102 ) )
break;
V_2 -> V_118 = F_38 ( V_2 -> V_118 , V_15 . V_119 ) ;
F_40 ( & V_121 -> V_15 . V_119 , & V_2 -> V_117 ) ;
return true ;
}
return false ;
}
static int F_41 ( void * V_124 , struct V_98 * V_16 )
{
struct V_1 * V_2 = V_124 ;
int V_102 ;
do {
V_102 = F_31 ( V_2 , V_16 ) ;
} while ( V_102 == - V_38 && F_37 ( V_2 , V_16 ) );
if ( V_102 )
return V_102 ;
if ( V_16 -> V_125 )
V_102 = F_31 ( V_2 , V_16 -> V_125 ) ;
return V_102 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_126 * V_117 )
{
struct V_120 * V_127 ;
int V_102 ;
F_43 (lobj, validated, tv.head) {
struct V_98 * V_16 = V_127 -> V_13 ;
bool V_128 = false ;
struct V_129 * V_130 ;
V_130 = F_7 ( V_16 -> V_17 . V_21 ) ;
if ( V_130 && V_130 != V_131 -> V_132 )
return - V_133 ;
if ( V_127 -> V_19 && V_16 -> V_17 . V_21 -> V_134 != V_135 ) {
T_6 V_8 = sizeof( struct V_136 * ) ;
V_8 *= V_16 -> V_17 . V_21 -> V_137 ;
memcpy ( V_16 -> V_17 . V_21 -> V_138 , V_127 -> V_19 , V_8 ) ;
V_128 = true ;
}
if ( V_2 -> V_118 == V_127 )
V_2 -> V_118 = NULL ;
V_102 = F_41 ( V_2 , V_16 ) ;
if ( V_102 )
return V_102 ;
if ( V_128 ) {
F_17 ( V_127 -> V_19 ) ;
V_127 -> V_19 = NULL ;
}
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 ,
union V_27 * V_28 )
{
struct V_22 * V_23 = V_2 -> V_9 -> V_24 ;
struct V_120 * V_139 ;
struct V_126 V_140 ;
bool V_141 = false ;
unsigned V_33 , V_142 = 10 ;
int V_102 ;
F_45 ( & V_2 -> V_117 ) ;
V_2 -> V_143 = F_46 ( V_23 , V_28 -> V_35 . V_144 ) ;
if ( V_2 -> V_143 ) {
V_141 = V_2 -> V_143 -> V_145 !=
V_2 -> V_143 -> V_146 ;
F_47 ( V_2 -> V_143 , & V_2 -> V_117 ) ;
}
F_45 ( & V_140 ) ;
F_48 ( & V_23 -> V_26 , & V_2 -> V_117 , & V_2 -> V_147 ) ;
if ( V_2 -> V_12 . V_13 )
F_49 ( & V_2 -> V_12 . V_15 . V_119 , & V_2 -> V_117 ) ;
if ( V_141 )
F_50 ( & V_131 -> V_132 -> V_148 ) ;
while ( 1 ) {
struct V_126 V_149 ;
unsigned V_33 ;
V_102 = F_51 ( & V_2 -> V_150 , & V_2 -> V_117 , true ,
& V_140 ) ;
if ( F_36 ( V_102 != 0 ) ) {
if ( V_102 != - V_151 )
F_52 ( L_1 ) ;
goto V_152;
}
if ( ! V_2 -> V_143 )
break;
F_45 ( & V_149 ) ;
for ( V_33 = V_2 -> V_143 -> V_145 ;
V_33 < V_2 -> V_143 -> V_146 ; ++ V_33 ) {
V_139 = & V_2 -> V_143 -> V_153 [ V_33 ] ;
if ( F_53 ( V_139 -> V_13 -> V_17 . V_21 ,
& V_139 -> V_154 ) && V_139 -> V_19 ) {
F_54 ( V_139 -> V_19 ,
V_139 -> V_13 -> V_17 . V_21 -> V_137 ,
false ) ;
F_17 ( V_139 -> V_19 ) ;
V_139 -> V_19 = NULL ;
}
if ( V_139 -> V_13 -> V_17 . V_21 -> V_134 != V_135 &&
! V_139 -> V_19 ) {
F_55 ( & V_139 -> V_15 . V_119 ) ;
F_49 ( & V_139 -> V_15 . V_119 , & V_149 ) ;
F_56 ( V_139 -> V_13 ) ;
}
}
if ( F_57 ( & V_149 ) )
break;
F_58 ( & V_2 -> V_150 , & V_2 -> V_117 ) ;
if ( ! -- V_142 ) {
V_102 = - V_155 ;
F_52 ( L_2 , V_156 ) ;
goto V_152;
}
F_43 (e, &need_pages, tv.head) {
struct V_157 * V_21 = V_139 -> V_13 -> V_17 . V_21 ;
V_139 -> V_19 = F_14 ( V_21 -> V_137 ,
sizeof( struct V_136 * ) ,
V_37 | V_158 ) ;
if ( ! V_139 -> V_19 ) {
V_102 = - V_38 ;
F_52 ( L_3 , V_156 ) ;
goto V_152;
}
V_102 = F_59 ( V_21 , V_139 -> V_19 ) ;
if ( V_102 ) {
F_52 ( L_4 ) ;
F_17 ( V_139 -> V_19 ) ;
V_139 -> V_19 = NULL ;
goto V_152;
}
}
F_60 ( & V_149 , & V_2 -> V_117 ) ;
}
F_21 ( V_2 -> V_61 , & V_2 -> V_104 ,
& V_2 -> V_107 ) ;
V_2 -> V_100 = 0 ;
V_2 -> V_106 = 0 ;
V_2 -> V_118 = F_61 ( & V_2 -> V_117 ,
struct V_120 ,
V_15 . V_119 ) ;
V_102 = F_62 ( V_2 -> V_61 , & V_23 -> V_26 ,
F_41 , V_2 ) ;
if ( V_102 ) {
F_52 ( L_5 ) ;
goto V_159;
}
V_102 = F_42 ( V_2 , & V_140 ) ;
if ( V_102 ) {
F_52 ( L_6 ) ;
goto V_159;
}
V_102 = F_42 ( V_2 , & V_2 -> V_117 ) ;
if ( V_102 ) {
F_52 ( L_7 ) ;
goto V_159;
}
F_30 ( V_2 -> V_61 , V_2 -> V_100 ,
V_2 -> V_106 ) ;
V_23 -> V_26 . V_160 =
F_34 ( & V_2 -> V_61 -> V_161 ) ;
if ( V_2 -> V_143 ) {
struct V_98 * V_162 = V_2 -> V_143 -> V_163 ;
struct V_98 * V_164 = V_2 -> V_143 -> V_165 ;
struct V_98 * V_166 = V_2 -> V_143 -> V_167 ;
struct V_25 * V_26 = & V_23 -> V_26 ;
unsigned V_33 ;
for ( V_33 = 0 ; V_33 < V_2 -> V_143 -> V_146 ; V_33 ++ ) {
struct V_98 * V_16 = V_2 -> V_143 -> V_153 [ V_33 ] . V_13 ;
V_2 -> V_143 -> V_153 [ V_33 ] . V_168 = F_63 ( V_26 , V_16 ) ;
}
if ( V_162 ) {
V_2 -> V_62 -> V_169 = F_64 ( V_162 ) ;
V_2 -> V_62 -> V_170 = F_5 ( V_162 ) ;
}
if ( V_164 ) {
V_2 -> V_62 -> V_171 = F_64 ( V_164 ) ;
V_2 -> V_62 -> V_172 = F_5 ( V_164 ) ;
}
if ( V_166 ) {
V_2 -> V_62 -> V_173 = F_64 ( V_166 ) ;
V_2 -> V_62 -> V_174 = F_5 ( V_166 ) ;
}
}
if ( ! V_102 && V_2 -> V_12 . V_13 ) {
struct V_98 * V_175 = V_2 -> V_12 . V_13 ;
V_102 = F_65 ( & V_175 -> V_17 , & V_175 -> V_17 . V_113 ) ;
V_2 -> V_62 -> V_64 += F_64 ( V_175 ) ;
}
V_159:
if ( V_102 )
F_58 ( & V_2 -> V_150 , & V_2 -> V_117 ) ;
V_152:
if ( V_141 )
F_66 ( & V_131 -> V_132 -> V_148 ) ;
if ( V_2 -> V_143 ) {
for ( V_33 = V_2 -> V_143 -> V_145 ;
V_33 < V_2 -> V_143 -> V_146 ; ++ V_33 ) {
V_139 = & V_2 -> V_143 -> V_153 [ V_33 ] ;
if ( ! V_139 -> V_19 )
continue;
F_54 ( V_139 -> V_19 ,
V_139 -> V_13 -> V_17 . V_21 -> V_137 ,
false ) ;
F_17 ( V_139 -> V_19 ) ;
}
}
return V_102 ;
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_120 * V_139 ;
int V_102 ;
F_43 (e, &p->validated, tv.head) {
struct V_176 * V_177 = V_139 -> V_13 -> V_17 . V_177 ;
V_102 = F_68 ( V_2 -> V_61 , & V_2 -> V_62 -> V_178 , V_177 , V_2 -> V_9 ) ;
if ( V_102 )
return V_102 ;
}
return 0 ;
}
static void F_69 ( struct V_1 * V_179 , int error ,
bool V_180 )
{
unsigned V_33 ;
if ( ! error )
F_70 ( & V_179 -> V_150 ,
& V_179 -> V_117 ,
V_179 -> V_181 ) ;
else if ( V_180 )
F_58 ( & V_179 -> V_150 ,
& V_179 -> V_117 ) ;
for ( V_33 = 0 ; V_33 < V_179 -> V_182 ; V_33 ++ )
F_71 ( V_179 -> V_183 [ V_33 ] ) ;
F_16 ( V_179 -> V_183 ) ;
F_72 ( V_179 -> V_181 ) ;
if ( V_179 -> V_39 )
F_18 ( V_179 -> V_39 ) ;
if ( V_179 -> V_143 )
F_73 ( V_179 -> V_143 ) ;
for ( V_33 = 0 ; V_33 < V_179 -> V_45 ; V_33 ++ )
F_17 ( V_179 -> V_42 [ V_33 ] . V_55 ) ;
F_16 ( V_179 -> V_42 ) ;
if ( V_179 -> V_62 )
F_74 ( V_179 -> V_62 ) ;
F_8 ( & V_179 -> V_12 . V_13 ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_65 * V_61 = V_2 -> V_61 ;
struct V_22 * V_23 = V_2 -> V_9 -> V_24 ;
struct V_25 * V_26 = & V_23 -> V_26 ;
struct V_184 * V_168 ;
struct V_98 * V_16 ;
int V_33 , V_102 ;
V_102 = F_76 ( V_61 , V_26 ) ;
if ( V_102 )
return V_102 ;
V_102 = F_77 ( V_61 , & V_2 -> V_62 -> V_178 , V_26 -> V_185 ) ;
if ( V_102 )
return V_102 ;
V_102 = F_78 ( V_61 , V_26 , NULL ) ;
if ( V_102 )
return V_102 ;
V_102 = F_79 ( V_61 , V_23 -> V_186 , false ) ;
if ( V_102 )
return V_102 ;
V_102 = F_77 ( V_61 , & V_2 -> V_62 -> V_178 ,
V_23 -> V_186 -> V_187 ) ;
if ( V_102 )
return V_102 ;
if ( F_80 ( V_61 ) ) {
struct V_188 * V_189 ;
V_168 = V_23 -> V_190 ;
F_81 ( ! V_168 ) ;
V_102 = F_79 ( V_61 , V_168 , false ) ;
if ( V_102 )
return V_102 ;
V_189 = V_168 -> V_187 ;
V_102 = F_77 ( V_61 , & V_2 -> V_62 -> V_178 , V_189 ) ;
if ( V_102 )
return V_102 ;
}
if ( V_2 -> V_143 ) {
for ( V_33 = 0 ; V_33 < V_2 -> V_143 -> V_146 ; V_33 ++ ) {
struct V_188 * V_189 ;
V_16 = V_2 -> V_143 -> V_153 [ V_33 ] . V_13 ;
if ( ! V_16 )
continue;
V_168 = V_2 -> V_143 -> V_153 [ V_33 ] . V_168 ;
if ( V_168 == NULL )
continue;
V_102 = F_79 ( V_61 , V_168 , false ) ;
if ( V_102 )
return V_102 ;
V_189 = V_168 -> V_187 ;
V_102 = F_77 ( V_61 , & V_2 -> V_62 -> V_178 , V_189 ) ;
if ( V_102 )
return V_102 ;
}
}
V_102 = F_82 ( V_61 , V_26 , & V_2 -> V_62 -> V_178 ) ;
if ( V_191 && V_2 -> V_143 ) {
for ( V_33 = 0 ; V_33 < V_2 -> V_143 -> V_146 ; V_33 ++ ) {
V_16 = V_2 -> V_143 -> V_153 [ V_33 ] . V_13 ;
if ( ! V_16 )
continue;
F_83 ( V_61 , V_16 ) ;
}
}
return V_102 ;
}
static int F_84 ( struct V_65 * V_61 ,
struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_9 -> V_24 ;
struct V_25 * V_26 = & V_23 -> V_26 ;
struct V_192 * V_193 = V_2 -> V_62 -> V_193 ;
int V_33 , V_102 ;
if ( V_193 -> V_194 -> V_195 ) {
for ( V_33 = 0 ; V_33 < V_2 -> V_62 -> V_31 ; V_33 ++ ) {
V_102 = F_85 ( V_193 , V_2 , V_33 ) ;
if ( V_102 )
return V_102 ;
}
}
if ( V_2 -> V_62 -> V_26 ) {
V_2 -> V_62 -> V_196 = F_64 ( V_26 -> V_197 . V_16 ) ;
V_102 = F_75 ( V_2 ) ;
if ( V_102 )
return V_102 ;
}
return F_67 ( V_2 ) ;
}
static int F_86 ( struct V_65 * V_61 ,
struct V_1 * V_179 )
{
struct V_22 * V_23 = V_179 -> V_9 -> V_24 ;
struct V_25 * V_26 = & V_23 -> V_26 ;
int V_33 , V_198 ;
int V_102 , V_199 = 0 , V_200 = 0 ;
for ( V_33 = 0 , V_198 = 0 ; V_33 < V_179 -> V_45 && V_198 < V_179 -> V_62 -> V_31 ; V_33 ++ ) {
struct V_46 * V_201 ;
struct V_202 * V_203 ;
struct V_204 * V_205 ;
struct V_192 * V_193 ;
V_201 = & V_179 -> V_42 [ V_33 ] ;
V_203 = & V_179 -> V_62 -> V_206 [ V_198 ] ;
V_205 = (struct V_204 * ) V_201 -> V_55 ;
if ( V_201 -> V_52 != V_56 )
continue;
if ( V_205 -> V_207 == V_208 && F_80 ( V_61 ) ) {
if ( V_205 -> V_89 & V_209 ) {
if ( V_205 -> V_89 & V_210 )
V_199 ++ ;
else
V_200 ++ ;
}
if ( V_199 > 1 || V_200 > 1 )
return - V_11 ;
}
V_102 = F_87 ( V_61 , & V_179 -> V_39 -> V_211 , V_205 -> V_207 ,
V_205 -> V_212 , V_205 -> V_193 , & V_193 ) ;
if ( V_102 )
return V_102 ;
if ( V_205 -> V_89 & V_213 ) {
V_179 -> V_62 -> V_214 |= V_215 ;
if ( ! V_179 -> V_39 -> V_216 ) {
V_179 -> V_62 -> V_214 |= V_217 ;
V_179 -> V_39 -> V_216 = true ;
}
}
if ( V_179 -> V_62 -> V_193 && V_179 -> V_62 -> V_193 != V_193 )
return - V_11 ;
V_179 -> V_62 -> V_193 = V_193 ;
if ( V_193 -> V_194 -> V_195 ) {
struct V_218 * V_219 ;
struct V_98 * V_220 = NULL ;
T_2 V_5 ;
T_7 * V_221 ;
V_219 = F_88 ( V_179 , V_205 -> va_start ,
& V_220 ) ;
if ( ! V_220 ) {
F_52 ( L_8 ) ;
return - V_11 ;
}
if ( ( V_205 -> va_start + V_205 -> V_222 ) >
( V_219 -> V_223 + 1 ) * V_224 ) {
F_52 ( L_9 ) ;
return - V_11 ;
}
V_102 = F_89 ( V_220 , ( void * * ) & V_221 ) ;
if ( V_102 ) {
return V_102 ;
}
V_5 = V_219 -> V_115 * V_224 ;
V_221 += V_205 -> va_start - V_5 ;
V_102 = F_90 ( V_61 , V_26 , V_205 -> V_222 , V_203 ) ;
if ( V_102 ) {
F_52 ( L_10 ) ;
return V_102 ;
}
memcpy ( V_203 -> V_225 , V_221 , V_205 -> V_222 ) ;
F_91 ( V_220 ) ;
} else {
V_102 = F_90 ( V_61 , V_26 , 0 , V_203 ) ;
if ( V_102 ) {
F_52 ( L_10 ) ;
return V_102 ;
}
}
V_203 -> V_226 = V_205 -> va_start ;
V_203 -> V_53 = V_205 -> V_222 / 4 ;
V_203 -> V_89 = V_205 -> V_89 ;
V_198 ++ ;
}
if ( V_179 -> V_62 -> V_64 && (
V_179 -> V_62 -> V_193 -> V_194 -> type == V_227 ||
V_179 -> V_62 -> V_193 -> V_194 -> type == V_228 ) )
return - V_11 ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_46 * V_201 )
{
struct V_22 * V_23 = V_2 -> V_9 -> V_24 ;
unsigned V_229 ;
int V_33 , V_102 ;
struct V_230 * V_231 ;
V_231 = (struct V_230 * ) V_201 -> V_55 ;
V_229 = V_201 -> V_53 * 4 /
sizeof( struct V_230 ) ;
for ( V_33 = 0 ; V_33 < V_229 ; ++ V_33 ) {
struct V_192 * V_193 ;
struct V_232 * V_39 ;
struct V_188 * V_181 ;
V_39 = F_11 ( V_23 , V_231 [ V_33 ] . V_40 ) ;
if ( V_39 == NULL )
return - V_11 ;
V_102 = F_87 ( V_2 -> V_61 , & V_39 -> V_211 ,
V_231 [ V_33 ] . V_207 ,
V_231 [ V_33 ] . V_212 ,
V_231 [ V_33 ] . V_193 , & V_193 ) ;
if ( V_102 ) {
F_18 ( V_39 ) ;
return V_102 ;
}
V_181 = F_93 ( V_39 , V_193 ,
V_231 [ V_33 ] . V_10 ) ;
if ( F_94 ( V_181 ) ) {
V_102 = F_95 ( V_181 ) ;
F_18 ( V_39 ) ;
return V_102 ;
} else if ( V_181 ) {
V_102 = F_77 ( V_2 -> V_61 , & V_2 -> V_62 -> V_178 ,
V_181 ) ;
F_72 ( V_181 ) ;
F_18 ( V_39 ) ;
if ( V_102 )
return V_102 ;
}
}
return 0 ;
}
static int F_96 ( struct V_1 * V_2 ,
T_1 V_10 )
{
int V_102 ;
struct V_188 * V_181 ;
V_102 = F_97 ( V_2 -> V_9 , V_10 , & V_181 ) ;
if ( V_102 )
return V_102 ;
V_102 = F_77 ( V_2 -> V_61 , & V_2 -> V_62 -> V_178 , V_181 ) ;
F_72 ( V_181 ) ;
return V_102 ;
}
static int F_98 ( struct V_1 * V_2 ,
struct V_46 * V_201 )
{
unsigned V_229 ;
int V_33 , V_102 ;
struct V_233 * V_231 ;
V_231 = (struct V_233 * ) V_201 -> V_55 ;
V_229 = V_201 -> V_53 * 4 /
sizeof( struct V_233 ) ;
for ( V_33 = 0 ; V_33 < V_229 ; ++ V_33 ) {
V_102 = F_96 ( V_2 , V_231 [ V_33 ] . V_10 ) ;
if ( V_102 )
return V_102 ;
}
return 0 ;
}
static int F_99 ( struct V_1 * V_2 ,
struct V_46 * V_201 )
{
unsigned V_229 ;
int V_33 ;
struct V_233 * V_231 ;
V_231 = (struct V_233 * ) V_201 -> V_55 ;
V_229 = V_201 -> V_53 * 4 /
sizeof( struct V_233 ) ;
V_2 -> V_183 = F_10 ( V_229 ,
sizeof( struct V_234 * ) ,
V_37 ) ;
V_2 -> V_182 = 0 ;
if ( ! V_2 -> V_183 )
return - V_38 ;
for ( V_33 = 0 ; V_33 < V_229 ; ++ V_33 ) {
V_2 -> V_183 [ V_33 ] = F_100 ( V_2 -> V_9 , V_231 [ V_33 ] . V_10 ) ;
if ( ! V_2 -> V_183 [ V_33 ] )
return - V_11 ;
V_2 -> V_182 ++ ;
}
return 0 ;
}
static int F_101 ( struct V_65 * V_61 ,
struct V_1 * V_2 )
{
int V_33 , V_102 ;
for ( V_33 = 0 ; V_33 < V_2 -> V_45 ; ++ V_33 ) {
struct V_46 * V_201 ;
V_201 = & V_2 -> V_42 [ V_33 ] ;
if ( V_201 -> V_52 == V_58 ) {
V_102 = F_92 ( V_2 , V_201 ) ;
if ( V_102 )
return V_102 ;
} else if ( V_201 -> V_52 == V_59 ) {
V_102 = F_98 ( V_2 , V_201 ) ;
if ( V_102 )
return V_102 ;
} else if ( V_201 -> V_52 == V_60 ) {
V_102 = F_99 ( V_2 , V_201 ) ;
if ( V_102 )
return V_102 ;
}
}
return 0 ;
}
static void F_102 ( struct V_1 * V_2 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_2 -> V_182 ; ++ V_33 )
F_103 ( V_2 -> V_183 [ V_33 ] , V_2 -> V_181 ) ;
}
static int F_104 ( struct V_1 * V_2 ,
union V_27 * V_28 )
{
struct V_192 * V_193 = V_2 -> V_62 -> V_193 ;
struct V_235 * V_236 = & V_2 -> V_39 -> V_237 [ V_193 -> V_238 ] . V_236 ;
struct V_239 * V_62 ;
int V_102 ;
V_62 = V_2 -> V_62 ;
V_2 -> V_62 = NULL ;
V_102 = F_105 ( & V_62 -> V_240 , & V_193 -> V_241 , V_236 , V_2 -> V_9 ) ;
if ( V_102 ) {
F_74 ( V_62 ) ;
return V_102 ;
}
V_62 -> V_242 = V_2 -> V_9 ;
V_62 -> V_243 = V_236 -> V_244 ;
V_2 -> V_181 = F_106 ( & V_62 -> V_240 . V_245 -> V_246 ) ;
F_102 ( V_2 ) ;
V_28 -> V_247 . V_10 = F_107 ( V_2 -> V_39 , V_193 , V_2 -> V_181 ) ;
V_62 -> V_248 = V_28 -> V_247 . V_10 ;
F_108 ( V_62 ) ;
F_109 ( V_62 ) ;
F_110 ( & V_62 -> V_240 ) ;
return 0 ;
}
int F_111 ( struct V_249 * V_250 , void * V_4 , struct V_251 * V_9 )
{
struct V_65 * V_61 = V_250 -> V_252 ;
struct V_22 * V_23 = V_9 -> V_24 ;
union V_27 * V_28 = V_4 ;
struct V_1 V_179 = {} ;
bool V_253 = false ;
int V_33 , V_102 ;
if ( ! V_61 -> V_254 )
return - V_255 ;
if ( F_112 ( V_61 , V_23 ) )
return - V_256 ;
V_179 . V_61 = V_61 ;
V_179 . V_9 = V_9 ;
V_102 = F_9 ( & V_179 , V_4 ) ;
if ( V_102 ) {
F_52 ( L_11 ) ;
goto V_247;
}
V_102 = F_44 ( & V_179 , V_4 ) ;
if ( V_102 ) {
if ( V_102 == - V_38 )
F_52 ( L_12 ) ;
else if ( V_102 != - V_151 )
F_52 ( L_13 , V_102 ) ;
goto V_247;
}
V_253 = true ;
V_102 = F_86 ( V_61 , & V_179 ) ;
if ( V_102 )
goto V_247;
V_102 = F_101 ( V_61 , & V_179 ) ;
if ( V_102 ) {
F_52 ( L_14 , V_102 ) ;
goto V_247;
}
for ( V_33 = 0 ; V_33 < V_179 . V_62 -> V_31 ; V_33 ++ )
F_113 ( & V_179 , V_33 ) ;
V_102 = F_84 ( V_61 , & V_179 ) ;
if ( V_102 )
goto V_247;
V_102 = F_104 ( & V_179 , V_28 ) ;
V_247:
F_69 ( & V_179 , V_102 , V_253 ) ;
return V_102 ;
}
int F_114 ( struct V_249 * V_250 , void * V_4 ,
struct V_251 * V_9 )
{
union V_257 * V_258 = V_4 ;
struct V_65 * V_61 = V_250 -> V_252 ;
struct V_22 * V_23 = V_9 -> V_24 ;
unsigned long V_259 = F_115 ( V_258 -> V_35 . V_259 ) ;
struct V_192 * V_193 = NULL ;
struct V_232 * V_39 ;
struct V_188 * V_181 ;
long V_102 ;
if ( F_112 ( V_61 , V_23 ) )
return - V_256 ;
V_39 = F_11 ( V_9 -> V_24 , V_258 -> V_35 . V_40 ) ;
if ( V_39 == NULL )
return - V_11 ;
V_102 = F_87 ( V_61 , & V_39 -> V_211 ,
V_258 -> V_35 . V_207 , V_258 -> V_35 . V_212 ,
V_258 -> V_35 . V_193 , & V_193 ) ;
if ( V_102 ) {
F_18 ( V_39 ) ;
return V_102 ;
}
V_181 = F_93 ( V_39 , V_193 , V_258 -> V_35 . V_10 ) ;
if ( F_94 ( V_181 ) )
V_102 = F_95 ( V_181 ) ;
else if ( V_181 ) {
V_102 = F_116 ( V_181 , true , V_259 ) ;
F_72 ( V_181 ) ;
} else
V_102 = 1 ;
F_18 ( V_39 ) ;
if ( V_102 < 0 )
return V_102 ;
memset ( V_258 , 0 , sizeof( * V_258 ) ) ;
V_258 -> V_247 . V_260 = ( V_102 == 0 ) ;
return 0 ;
}
static struct V_188 * F_117 ( struct V_65 * V_61 ,
struct V_251 * V_9 ,
struct V_261 * V_262 )
{
struct V_192 * V_193 ;
struct V_232 * V_39 ;
struct V_188 * V_181 ;
int V_102 ;
V_39 = F_11 ( V_9 -> V_24 , V_262 -> V_40 ) ;
if ( V_39 == NULL )
return F_118 ( - V_11 ) ;
V_102 = F_87 ( V_61 , & V_39 -> V_211 , V_262 -> V_207 ,
V_262 -> V_212 , V_262 -> V_193 , & V_193 ) ;
if ( V_102 ) {
F_18 ( V_39 ) ;
return F_118 ( V_102 ) ;
}
V_181 = F_93 ( V_39 , V_193 , V_262 -> V_263 ) ;
F_18 ( V_39 ) ;
return V_181 ;
}
static int F_119 ( struct V_65 * V_61 ,
struct V_251 * V_9 ,
union V_264 * V_258 ,
struct V_261 * V_265 )
{
T_1 V_266 = V_258 -> V_35 . V_266 ;
unsigned int V_33 ;
long V_102 = 1 ;
for ( V_33 = 0 ; V_33 < V_266 ; V_33 ++ ) {
struct V_188 * V_181 ;
unsigned long V_259 = F_115 ( V_258 -> V_35 . V_267 ) ;
V_181 = F_117 ( V_61 , V_9 , & V_265 [ V_33 ] ) ;
if ( F_94 ( V_181 ) )
return F_95 ( V_181 ) ;
else if ( ! V_181 )
continue;
V_102 = F_116 ( V_181 , true , V_259 ) ;
F_72 ( V_181 ) ;
if ( V_102 < 0 )
return V_102 ;
if ( V_102 == 0 )
break;
}
memset ( V_258 , 0 , sizeof( * V_258 ) ) ;
V_258 -> V_247 . V_260 = ( V_102 > 0 ) ;
return 0 ;
}
static int F_120 ( struct V_65 * V_61 ,
struct V_251 * V_9 ,
union V_264 * V_258 ,
struct V_261 * V_265 )
{
unsigned long V_259 = F_115 ( V_258 -> V_35 . V_267 ) ;
T_1 V_266 = V_258 -> V_35 . V_266 ;
T_1 V_268 = ~ 0 ;
struct V_188 * * V_153 ;
unsigned int V_33 ;
long V_102 ;
V_153 = F_121 ( V_266 , sizeof( struct V_188 * ) , V_37 ) ;
if ( V_153 == NULL )
return - V_38 ;
for ( V_33 = 0 ; V_33 < V_266 ; V_33 ++ ) {
struct V_188 * V_181 ;
V_181 = F_117 ( V_61 , V_9 , & V_265 [ V_33 ] ) ;
if ( F_94 ( V_181 ) ) {
V_102 = F_95 ( V_181 ) ;
goto V_269;
} else if ( V_181 ) {
V_153 [ V_33 ] = V_181 ;
} else {
V_102 = 1 ;
goto V_247;
}
}
V_102 = F_122 ( V_153 , V_266 , true , V_259 ,
& V_268 ) ;
if ( V_102 < 0 )
goto V_269;
V_247:
memset ( V_258 , 0 , sizeof( * V_258 ) ) ;
V_258 -> V_247 . V_260 = ( V_102 > 0 ) ;
V_258 -> V_247 . V_270 = V_268 ;
V_102 = 0 ;
V_269:
for ( V_33 = 0 ; V_33 < V_266 ; V_33 ++ )
F_72 ( V_153 [ V_33 ] ) ;
F_16 ( V_153 ) ;
return V_102 ;
}
int F_123 ( struct V_249 * V_250 , void * V_4 ,
struct V_251 * V_9 )
{
struct V_65 * V_61 = V_250 -> V_252 ;
struct V_22 * V_23 = V_9 -> V_24 ;
union V_264 * V_258 = V_4 ;
T_1 V_266 = V_258 -> V_35 . V_266 ;
struct V_261 * V_271 ;
struct V_261 * V_265 ;
int V_102 ;
if ( F_112 ( V_61 , V_23 ) )
return - V_256 ;
V_265 = F_10 ( V_266 , sizeof( struct V_261 ) ,
V_37 ) ;
if ( V_265 == NULL )
return - V_38 ;
V_271 = F_12 ( V_258 -> V_35 . V_265 ) ;
if ( F_13 ( V_265 , V_271 ,
sizeof( struct V_261 ) * V_266 ) ) {
V_102 = - V_43 ;
goto V_272;
}
if ( V_258 -> V_35 . V_273 )
V_102 = F_119 ( V_61 , V_9 , V_258 , V_265 ) ;
else
V_102 = F_120 ( V_61 , V_9 , V_258 , V_265 ) ;
V_272:
F_16 ( V_265 ) ;
return V_102 ;
}
struct V_218 *
F_88 ( struct V_1 * V_179 ,
T_2 V_274 , struct V_98 * * V_16 )
{
struct V_218 * V_275 ;
unsigned V_33 ;
if ( ! V_179 -> V_143 )
return NULL ;
V_274 /= V_224 ;
for ( V_33 = 0 ; V_33 < V_179 -> V_143 -> V_146 ; V_33 ++ ) {
struct V_120 * V_127 ;
V_127 = & V_179 -> V_143 -> V_153 [ V_33 ] ;
if ( ! V_127 -> V_168 )
continue;
F_43 (mapping, &lobj->bo_va->valids, list) {
if ( V_275 -> V_115 > V_274 ||
V_274 > V_275 -> V_223 )
continue;
* V_16 = V_127 -> V_168 -> V_240 . V_16 ;
return V_275 ;
}
F_43 (mapping, &lobj->bo_va->invalids, list) {
if ( V_275 -> V_115 > V_274 ||
V_274 > V_275 -> V_223 )
continue;
* V_16 = V_127 -> V_168 -> V_240 . V_16 ;
return V_275 ;
}
}
return NULL ;
}
int F_124 ( struct V_1 * V_179 )
{
unsigned V_33 ;
int V_102 ;
if ( ! V_179 -> V_143 )
return 0 ;
for ( V_33 = 0 ; V_33 < V_179 -> V_143 -> V_146 ; V_33 ++ ) {
struct V_98 * V_16 = V_179 -> V_143 -> V_153 [ V_33 ] . V_13 ;
V_102 = F_65 ( & V_16 -> V_17 , & V_16 -> V_17 . V_113 ) ;
if ( F_36 ( V_102 ) )
return V_102 ;
if ( V_16 -> V_89 & V_276 )
continue;
V_16 -> V_89 |= V_276 ;
F_33 ( V_16 , V_16 -> V_109 ) ;
V_102 = F_35 ( & V_16 -> V_17 , & V_16 -> V_112 , false , false ) ;
if ( F_36 ( V_102 ) )
return V_102 ;
}
return 0 ;
}
