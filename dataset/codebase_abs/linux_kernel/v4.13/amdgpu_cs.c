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
V_29 = ( T_2 V_42 * ) ( V_43 ) ( V_28 -> V_35 . V_44 ) ;
if ( F_12 ( V_30 , V_29 ,
sizeof( T_2 ) * V_28 -> V_35 . V_36 ) ) {
V_34 = - V_45 ;
goto V_46;
}
V_2 -> V_47 = V_28 -> V_35 . V_36 ;
V_2 -> V_44 = F_10 ( V_2 -> V_47 , sizeof( struct V_48 ) ,
V_37 ) ;
if ( ! V_2 -> V_44 ) {
V_34 = - V_38 ;
goto V_46;
}
for ( V_33 = 0 ; V_33 < V_2 -> V_47 ; V_33 ++ ) {
struct V_49 V_42 * * V_50 = NULL ;
struct V_49 V_51 ;
T_1 V_42 * V_52 ;
V_50 = ( void V_42 * ) ( V_43 ) V_30 [ V_33 ] ;
if ( F_12 ( & V_51 , V_50 ,
sizeof( struct V_49 ) ) ) {
V_34 = - V_45 ;
V_33 -- ;
goto V_53;
}
V_2 -> V_44 [ V_33 ] . V_54 = V_51 . V_54 ;
V_2 -> V_44 [ V_33 ] . V_55 = V_51 . V_55 ;
V_8 = V_2 -> V_44 [ V_33 ] . V_55 ;
V_52 = ( void V_42 * ) ( V_43 ) V_51 . V_56 ;
V_2 -> V_44 [ V_33 ] . V_57 = F_13 ( V_8 , sizeof( T_1 ) , V_37 ) ;
if ( V_2 -> V_44 [ V_33 ] . V_57 == NULL ) {
V_34 = - V_38 ;
V_33 -- ;
goto V_53;
}
V_8 *= sizeof( T_1 ) ;
if ( F_12 ( V_2 -> V_44 [ V_33 ] . V_57 , V_52 , V_8 ) ) {
V_34 = - V_45 ;
goto V_53;
}
switch ( V_2 -> V_44 [ V_33 ] . V_54 ) {
case V_58 :
++ V_31 ;
break;
case V_59 :
V_8 = sizeof( struct V_3 ) ;
if ( V_2 -> V_44 [ V_33 ] . V_55 * sizeof( T_1 ) < V_8 ) {
V_34 = - V_11 ;
goto V_53;
}
V_34 = F_1 ( V_2 , V_2 -> V_44 [ V_33 ] . V_57 ,
& V_32 ) ;
if ( V_34 )
goto V_53;
break;
case V_60 :
case V_61 :
case V_62 :
break;
default:
V_34 = - V_11 ;
goto V_53;
}
}
V_34 = F_14 ( V_2 -> V_63 , V_31 , & V_2 -> V_64 , V_26 ) ;
if ( V_34 )
goto V_65;
if ( V_2 -> V_12 . V_13 )
V_2 -> V_64 -> V_66 = V_32 ;
F_15 ( V_30 ) ;
return 0 ;
V_65:
V_33 = V_2 -> V_47 - 1 ;
V_53:
for (; V_33 >= 0 ; V_33 -- )
F_16 ( V_2 -> V_44 [ V_33 ] . V_57 ) ;
F_15 ( V_2 -> V_44 ) ;
V_2 -> V_44 = NULL ;
V_2 -> V_47 = 0 ;
V_46:
F_17 ( V_2 -> V_39 ) ;
V_41:
F_15 ( V_30 ) ;
return V_34 ;
}
static T_3 F_18 ( struct V_67 * V_63 , T_4 V_68 )
{
if ( V_68 <= 0 || ! V_63 -> V_69 . V_70 )
return 0 ;
return V_68 << V_63 -> V_69 . V_70 ;
}
static T_4 F_19 ( struct V_67 * V_63 , T_3 V_71 )
{
if ( ! V_63 -> V_69 . V_70 )
return 0 ;
return V_71 >> V_63 -> V_69 . V_70 ;
}
static T_3 F_20 ( struct V_67 * V_63 )
{
T_4 V_72 , V_73 ;
T_3 V_74 ;
T_3 V_75 , V_76 , V_77 ;
const T_4 V_78 = 200000 ;
if ( ! V_63 -> V_69 . V_70 )
return 0 ;
V_76 = V_63 -> V_79 . V_80 - V_63 -> V_81 ;
V_77 = F_21 ( & V_63 -> V_82 ) ;
V_75 = V_77 >= V_76 ? 0 : V_76 - V_77 ;
F_22 ( & V_63 -> V_69 . V_83 ) ;
V_72 = F_23 ( F_24 () ) ;
V_73 = V_72 - V_63 -> V_69 . V_84 ;
V_63 -> V_69 . V_84 = V_72 ;
V_63 -> V_69 . V_85 = F_25 ( V_63 -> V_69 . V_85 + V_73 ,
V_78 ) ;
if ( V_75 >= 128 * 1024 * 1024 || V_75 >= V_76 / 8 ) {
T_4 V_86 ;
if ( ! ( V_63 -> V_87 & V_88 ) )
V_86 = F_19 ( V_63 , V_75 / 4 ) ;
else
V_86 = 0 ;
V_63 -> V_69 . V_85 = F_26 ( V_86 , V_63 -> V_69 . V_85 ) ;
}
V_74 = F_18 ( V_63 , V_63 -> V_69 . V_85 ) ;
F_27 ( & V_63 -> V_69 . V_83 ) ;
return V_74 ;
}
void F_28 ( struct V_67 * V_63 , T_3 V_89 )
{
F_22 ( & V_63 -> V_69 . V_83 ) ;
V_63 -> V_69 . V_85 -= F_19 ( V_63 , V_89 ) ;
F_27 ( & V_63 -> V_69 . V_83 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_90 * V_16 )
{
struct V_67 * V_63 = F_30 ( V_16 -> V_17 . V_91 ) ;
T_3 V_92 ;
T_1 V_93 ;
int V_94 ;
if ( V_16 -> V_95 )
return 0 ;
if ( V_2 -> V_96 < V_2 -> V_97 )
V_93 = V_16 -> V_98 ;
else
V_93 = V_16 -> V_99 ;
V_100:
F_31 ( V_16 , V_93 ) ;
V_92 = F_21 ( & V_63 -> V_101 ) ;
V_94 = F_32 ( & V_16 -> V_17 , & V_16 -> V_102 , true , false ) ;
V_2 -> V_96 += F_21 ( & V_63 -> V_101 ) -
V_92 ;
if ( F_33 ( V_94 == - V_38 ) && V_93 != V_16 -> V_99 ) {
V_93 = V_16 -> V_99 ;
goto V_100;
}
return V_94 ;
}
static bool F_34 ( struct V_1 * V_2 ,
struct V_90 * V_103 )
{
T_1 V_93 = V_103 -> V_99 ;
int V_94 ;
if ( ! V_2 -> V_104 )
return false ;
for (; & V_2 -> V_104 -> V_15 . V_105 != & V_2 -> V_103 ;
V_2 -> V_104 = F_35 ( V_2 -> V_104 , V_15 . V_105 ) ) {
struct V_106 * V_107 = V_2 -> V_104 ;
struct V_90 * V_16 = V_107 -> V_13 ;
struct V_67 * V_63 = F_30 ( V_16 -> V_17 . V_91 ) ;
T_3 V_92 ;
T_1 V_108 ;
if ( V_107 -> V_13 == V_103 )
break;
V_108 = F_36 ( V_16 -> V_17 . V_109 . V_110 ) ;
if ( ! ( V_108 & V_93 ) )
continue;
V_108 = V_16 -> V_99 & ~ V_93 ;
if ( ! V_108 )
continue;
F_31 ( V_16 , V_108 ) ;
V_92 = F_21 ( & V_63 -> V_101 ) ;
V_94 = F_32 ( & V_16 -> V_17 , & V_16 -> V_102 , true , false ) ;
V_2 -> V_96 += F_21 ( & V_63 -> V_101 ) -
V_92 ;
if ( F_33 ( V_94 ) )
break;
V_2 -> V_104 = F_35 ( V_2 -> V_104 , V_15 . V_105 ) ;
F_37 ( & V_107 -> V_15 . V_105 , & V_2 -> V_103 ) ;
return true ;
}
return false ;
}
static int F_38 ( void * V_111 , struct V_90 * V_16 )
{
struct V_1 * V_2 = V_111 ;
int V_94 ;
do {
V_94 = F_29 ( V_2 , V_16 ) ;
} while ( V_94 == - V_38 && F_34 ( V_2 , V_16 ) );
if ( V_94 )
return V_94 ;
if ( V_16 -> V_112 )
V_94 = F_29 ( V_2 , V_16 -> V_112 ) ;
return V_94 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_113 * V_103 )
{
struct V_106 * V_114 ;
int V_94 ;
F_40 (lobj, validated, tv.head) {
struct V_90 * V_16 = V_114 -> V_13 ;
bool V_115 = false ;
struct V_116 * V_117 ;
V_117 = F_7 ( V_16 -> V_17 . V_21 ) ;
if ( V_117 && V_117 != V_118 -> V_119 )
return - V_120 ;
if ( V_114 -> V_19 && V_16 -> V_17 . V_21 -> V_121 != V_122 ) {
T_5 V_8 = sizeof( struct V_123 * ) ;
V_8 *= V_16 -> V_17 . V_21 -> V_124 ;
memcpy ( V_16 -> V_17 . V_21 -> V_125 , V_114 -> V_19 , V_8 ) ;
V_115 = true ;
}
if ( V_2 -> V_104 == V_114 )
V_2 -> V_104 = NULL ;
V_94 = F_38 ( V_2 , V_16 ) ;
if ( V_94 )
return V_94 ;
if ( V_115 ) {
F_16 ( V_114 -> V_19 ) ;
V_114 -> V_19 = NULL ;
}
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
union V_27 * V_28 )
{
struct V_22 * V_23 = V_2 -> V_9 -> V_24 ;
struct V_106 * V_126 ;
struct V_113 V_127 ;
bool V_128 = false ;
unsigned V_33 , V_129 = 10 ;
int V_94 ;
F_42 ( & V_2 -> V_103 ) ;
V_2 -> V_130 = F_43 ( V_23 , V_28 -> V_35 . V_131 ) ;
if ( V_2 -> V_130 ) {
V_128 = V_2 -> V_130 -> V_132 !=
V_2 -> V_130 -> V_133 ;
F_44 ( V_2 -> V_130 , & V_2 -> V_103 ) ;
}
F_42 ( & V_127 ) ;
F_45 ( & V_23 -> V_26 , & V_2 -> V_103 , & V_2 -> V_134 ) ;
if ( V_2 -> V_12 . V_13 )
F_46 ( & V_2 -> V_12 . V_15 . V_105 , & V_2 -> V_103 ) ;
if ( V_128 )
F_47 ( & V_118 -> V_119 -> V_135 ) ;
while ( 1 ) {
struct V_113 V_136 ;
unsigned V_33 ;
V_94 = F_48 ( & V_2 -> V_137 , & V_2 -> V_103 , true ,
& V_127 ) ;
if ( F_33 ( V_94 != 0 ) ) {
if ( V_94 != - V_138 )
F_49 ( L_1 ) ;
goto V_139;
}
if ( ! V_2 -> V_130 )
break;
F_42 ( & V_136 ) ;
for ( V_33 = V_2 -> V_130 -> V_132 ;
V_33 < V_2 -> V_130 -> V_133 ; ++ V_33 ) {
V_126 = & V_2 -> V_130 -> V_140 [ V_33 ] ;
if ( F_50 ( V_126 -> V_13 -> V_17 . V_21 ,
& V_126 -> V_141 ) && V_126 -> V_19 ) {
F_51 ( V_126 -> V_19 ,
V_126 -> V_13 -> V_17 . V_21 -> V_124 ,
false ) ;
F_16 ( V_126 -> V_19 ) ;
V_126 -> V_19 = NULL ;
}
if ( V_126 -> V_13 -> V_17 . V_21 -> V_121 != V_122 &&
! V_126 -> V_19 ) {
F_52 ( & V_126 -> V_15 . V_105 ) ;
F_46 ( & V_126 -> V_15 . V_105 , & V_136 ) ;
F_53 ( V_126 -> V_13 ) ;
}
}
if ( F_54 ( & V_136 ) )
break;
F_55 ( & V_2 -> V_137 , & V_2 -> V_103 ) ;
if ( ! -- V_129 ) {
V_94 = - V_142 ;
F_49 ( L_2 , V_143 ) ;
goto V_139;
}
F_40 (e, &need_pages, tv.head) {
struct V_144 * V_21 = V_126 -> V_13 -> V_17 . V_21 ;
V_126 -> V_19 = F_13 ( V_21 -> V_124 ,
sizeof( struct V_123 * ) ,
V_37 | V_145 ) ;
if ( ! V_126 -> V_19 ) {
V_94 = - V_38 ;
F_49 ( L_3 , V_143 ) ;
goto V_139;
}
V_94 = F_56 ( V_21 , V_126 -> V_19 ) ;
if ( V_94 ) {
F_49 ( L_4 ) ;
F_16 ( V_126 -> V_19 ) ;
V_126 -> V_19 = NULL ;
goto V_139;
}
}
F_57 ( & V_136 , & V_2 -> V_103 ) ;
}
V_2 -> V_97 = F_20 ( V_2 -> V_63 ) ;
V_2 -> V_96 = 0 ;
V_2 -> V_104 = F_58 ( & V_2 -> V_103 ,
struct V_106 ,
V_15 . V_105 ) ;
V_94 = F_59 ( V_2 -> V_63 , & V_23 -> V_26 ,
F_38 , V_2 ) ;
if ( V_94 ) {
F_49 ( L_5 ) ;
goto V_146;
}
V_94 = F_39 ( V_2 , & V_127 ) ;
if ( V_94 ) {
F_49 ( L_6 ) ;
goto V_146;
}
V_94 = F_39 ( V_2 , & V_2 -> V_103 ) ;
if ( V_94 ) {
F_49 ( L_7 ) ;
goto V_146;
}
F_28 ( V_2 -> V_63 , V_2 -> V_96 ) ;
V_23 -> V_26 . V_147 =
F_21 ( & V_2 -> V_63 -> V_148 ) ;
if ( V_2 -> V_130 ) {
struct V_90 * V_149 = V_2 -> V_130 -> V_150 ;
struct V_90 * V_151 = V_2 -> V_130 -> V_152 ;
struct V_90 * V_153 = V_2 -> V_130 -> V_154 ;
struct V_25 * V_26 = & V_23 -> V_26 ;
unsigned V_33 ;
for ( V_33 = 0 ; V_33 < V_2 -> V_130 -> V_133 ; V_33 ++ ) {
struct V_90 * V_16 = V_2 -> V_130 -> V_140 [ V_33 ] . V_13 ;
V_2 -> V_130 -> V_140 [ V_33 ] . V_155 = F_60 ( V_26 , V_16 ) ;
}
if ( V_149 ) {
V_2 -> V_64 -> V_156 = F_61 ( V_149 ) ;
V_2 -> V_64 -> V_157 = F_5 ( V_149 ) ;
}
if ( V_151 ) {
V_2 -> V_64 -> V_158 = F_61 ( V_151 ) ;
V_2 -> V_64 -> V_159 = F_5 ( V_151 ) ;
}
if ( V_153 ) {
V_2 -> V_64 -> V_160 = F_61 ( V_153 ) ;
V_2 -> V_64 -> V_161 = F_5 ( V_153 ) ;
}
}
if ( ! V_94 && V_2 -> V_12 . V_13 ) {
struct V_90 * V_162 = V_2 -> V_12 . V_13 ;
V_94 = F_62 ( & V_162 -> V_17 , & V_162 -> V_17 . V_109 ) ;
V_2 -> V_64 -> V_66 += F_61 ( V_162 ) ;
}
V_146:
if ( V_94 ) {
F_63 ( V_2 -> V_63 , & V_23 -> V_26 ) ;
F_55 ( & V_2 -> V_137 , & V_2 -> V_103 ) ;
}
V_139:
if ( V_128 )
F_64 ( & V_118 -> V_119 -> V_135 ) ;
if ( V_2 -> V_130 ) {
for ( V_33 = V_2 -> V_130 -> V_132 ;
V_33 < V_2 -> V_130 -> V_133 ; ++ V_33 ) {
V_126 = & V_2 -> V_130 -> V_140 [ V_33 ] ;
if ( ! V_126 -> V_19 )
continue;
F_51 ( V_126 -> V_19 ,
V_126 -> V_13 -> V_17 . V_21 -> V_124 ,
false ) ;
F_16 ( V_126 -> V_19 ) ;
}
}
return V_94 ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_106 * V_126 ;
int V_94 ;
F_40 (e, &p->validated, tv.head) {
struct V_163 * V_164 = V_126 -> V_13 -> V_17 . V_164 ;
V_94 = F_66 ( V_2 -> V_63 , & V_2 -> V_64 -> V_165 , V_164 , V_2 -> V_9 ) ;
if ( V_94 )
return V_94 ;
}
return 0 ;
}
static void F_67 ( struct V_1 * V_166 , int error , bool V_167 )
{
struct V_22 * V_23 = V_166 -> V_9 -> V_24 ;
unsigned V_33 ;
if ( ! error ) {
F_63 ( V_166 -> V_63 , & V_23 -> V_26 ) ;
F_68 ( & V_166 -> V_137 ,
& V_166 -> V_103 ,
V_166 -> V_168 ) ;
} else if ( V_167 ) {
F_55 ( & V_166 -> V_137 ,
& V_166 -> V_103 ) ;
}
for ( V_33 = 0 ; V_33 < V_166 -> V_169 ; V_33 ++ )
F_69 ( V_166 -> V_170 [ V_33 ] ) ;
F_15 ( V_166 -> V_170 ) ;
F_70 ( V_166 -> V_168 ) ;
if ( V_166 -> V_39 )
F_17 ( V_166 -> V_39 ) ;
if ( V_166 -> V_130 )
F_71 ( V_166 -> V_130 ) ;
for ( V_33 = 0 ; V_33 < V_166 -> V_47 ; V_33 ++ )
F_16 ( V_166 -> V_44 [ V_33 ] . V_57 ) ;
F_15 ( V_166 -> V_44 ) ;
if ( V_166 -> V_64 )
F_72 ( V_166 -> V_64 ) ;
F_8 ( & V_166 -> V_12 . V_13 ) ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_67 * V_63 = V_2 -> V_63 ;
struct V_22 * V_23 = V_2 -> V_9 -> V_24 ;
struct V_25 * V_26 = & V_23 -> V_26 ;
struct V_171 * V_155 ;
struct V_90 * V_16 ;
int V_33 , V_94 ;
V_94 = F_74 ( V_63 , V_26 ) ;
if ( V_94 )
return V_94 ;
V_94 = F_75 ( V_63 , & V_2 -> V_64 -> V_165 , V_26 -> V_172 ) ;
if ( V_94 )
return V_94 ;
V_94 = F_76 ( V_63 , V_26 , NULL ) ;
if ( V_94 )
return V_94 ;
V_94 = F_77 ( V_63 , V_23 -> V_173 , false ) ;
if ( V_94 )
return V_94 ;
V_94 = F_75 ( V_63 , & V_2 -> V_64 -> V_165 ,
V_23 -> V_173 -> V_174 ) ;
if ( V_94 )
return V_94 ;
if ( F_78 ( V_63 ) ) {
struct V_175 * V_176 ;
V_155 = V_26 -> V_177 ;
F_79 ( ! V_155 ) ;
V_94 = F_77 ( V_63 , V_155 , false ) ;
if ( V_94 )
return V_94 ;
V_176 = V_155 -> V_174 ;
V_94 = F_75 ( V_63 , & V_2 -> V_64 -> V_165 , V_176 ) ;
if ( V_94 )
return V_94 ;
}
if ( V_2 -> V_130 ) {
for ( V_33 = 0 ; V_33 < V_2 -> V_130 -> V_133 ; V_33 ++ ) {
struct V_175 * V_176 ;
V_16 = V_2 -> V_130 -> V_140 [ V_33 ] . V_13 ;
if ( ! V_16 )
continue;
V_155 = V_2 -> V_130 -> V_140 [ V_33 ] . V_155 ;
if ( V_155 == NULL )
continue;
V_94 = F_77 ( V_63 , V_155 , false ) ;
if ( V_94 )
return V_94 ;
V_176 = V_155 -> V_174 ;
V_94 = F_75 ( V_63 , & V_2 -> V_64 -> V_165 , V_176 ) ;
if ( V_94 )
return V_94 ;
}
}
V_94 = F_80 ( V_63 , V_26 , & V_2 -> V_64 -> V_165 ) ;
if ( V_178 && V_2 -> V_130 ) {
for ( V_33 = 0 ; V_33 < V_2 -> V_130 -> V_133 ; V_33 ++ ) {
V_16 = V_2 -> V_130 -> V_140 [ V_33 ] . V_13 ;
if ( ! V_16 )
continue;
F_81 ( V_63 , V_16 ) ;
}
}
return V_94 ;
}
static int F_82 ( struct V_67 * V_63 ,
struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_9 -> V_24 ;
struct V_25 * V_26 = & V_23 -> V_26 ;
struct V_179 * V_180 = V_2 -> V_64 -> V_180 ;
int V_33 , V_94 ;
if ( V_180 -> V_181 -> V_182 ) {
for ( V_33 = 0 ; V_33 < V_2 -> V_64 -> V_31 ; V_33 ++ ) {
V_94 = F_83 ( V_180 , V_2 , V_33 ) ;
if ( V_94 )
return V_94 ;
}
}
if ( V_2 -> V_64 -> V_26 ) {
V_2 -> V_64 -> V_183 = F_61 ( V_26 -> V_184 . V_16 ) ;
V_94 = F_73 ( V_2 ) ;
if ( V_94 )
return V_94 ;
}
return F_65 ( V_2 ) ;
}
static int F_84 ( struct V_67 * V_63 ,
struct V_1 * V_166 )
{
struct V_22 * V_23 = V_166 -> V_9 -> V_24 ;
struct V_25 * V_26 = & V_23 -> V_26 ;
int V_33 , V_185 ;
int V_94 , V_186 = 0 , V_187 = 0 ;
for ( V_33 = 0 , V_185 = 0 ; V_33 < V_166 -> V_47 && V_185 < V_166 -> V_64 -> V_31 ; V_33 ++ ) {
struct V_48 * V_188 ;
struct V_189 * V_190 ;
struct V_191 * V_192 ;
struct V_179 * V_180 ;
V_188 = & V_166 -> V_44 [ V_33 ] ;
V_190 = & V_166 -> V_64 -> V_193 [ V_185 ] ;
V_192 = (struct V_191 * ) V_188 -> V_57 ;
if ( V_188 -> V_54 != V_58 )
continue;
if ( V_192 -> V_194 == V_195 && F_78 ( V_63 ) ) {
if ( V_192 -> V_87 & V_196 ) {
if ( V_192 -> V_87 & V_197 )
V_186 ++ ;
else
V_187 ++ ;
}
if ( V_186 > 1 || V_187 > 1 )
return - V_11 ;
}
V_94 = F_85 ( V_63 , & V_166 -> V_39 -> V_198 , V_192 -> V_194 ,
V_192 -> V_199 , V_192 -> V_180 , & V_180 ) ;
if ( V_94 )
return V_94 ;
if ( V_192 -> V_87 & V_200 ) {
V_166 -> V_64 -> V_201 |= V_202 ;
if ( ! V_166 -> V_39 -> V_203 ) {
V_166 -> V_64 -> V_201 |= V_204 ;
V_166 -> V_39 -> V_203 = true ;
}
}
if ( V_166 -> V_64 -> V_180 && V_166 -> V_64 -> V_180 != V_180 )
return - V_11 ;
V_166 -> V_64 -> V_180 = V_180 ;
if ( V_180 -> V_181 -> V_182 ) {
struct V_205 * V_206 ;
struct V_90 * V_207 = NULL ;
T_2 V_5 ;
T_6 * V_208 ;
V_206 = F_86 ( V_166 , V_192 -> va_start ,
& V_207 ) ;
if ( ! V_207 ) {
F_49 ( L_8 ) ;
return - V_11 ;
}
if ( ( V_192 -> va_start + V_192 -> V_209 ) >
( V_206 -> V_210 + 1 ) * V_211 ) {
F_49 ( L_9 ) ;
return - V_11 ;
}
V_94 = F_87 ( V_207 , ( void * * ) & V_208 ) ;
if ( V_94 ) {
return V_94 ;
}
V_5 = V_206 -> V_212 * V_211 ;
V_208 += V_192 -> va_start - V_5 ;
V_94 = F_88 ( V_63 , V_26 , V_192 -> V_209 , V_190 ) ;
if ( V_94 ) {
F_49 ( L_10 ) ;
return V_94 ;
}
memcpy ( V_190 -> V_213 , V_208 , V_192 -> V_209 ) ;
F_89 ( V_207 ) ;
} else {
V_94 = F_88 ( V_63 , V_26 , 0 , V_190 ) ;
if ( V_94 ) {
F_49 ( L_10 ) ;
return V_94 ;
}
}
V_190 -> V_214 = V_192 -> va_start ;
V_190 -> V_55 = V_192 -> V_209 / 4 ;
V_190 -> V_87 = V_192 -> V_87 ;
V_185 ++ ;
}
if ( V_166 -> V_64 -> V_66 && (
V_166 -> V_64 -> V_180 -> V_181 -> type == V_215 ||
V_166 -> V_64 -> V_180 -> V_181 -> type == V_216 ) )
return - V_11 ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_48 * V_188 )
{
struct V_22 * V_23 = V_2 -> V_9 -> V_24 ;
unsigned V_217 ;
int V_33 , V_94 ;
struct V_218 * V_219 ;
V_219 = (struct V_218 * ) V_188 -> V_57 ;
V_217 = V_188 -> V_55 * 4 /
sizeof( struct V_218 ) ;
for ( V_33 = 0 ; V_33 < V_217 ; ++ V_33 ) {
struct V_179 * V_180 ;
struct V_220 * V_39 ;
struct V_175 * V_168 ;
V_39 = F_11 ( V_23 , V_219 [ V_33 ] . V_40 ) ;
if ( V_39 == NULL )
return - V_11 ;
V_94 = F_85 ( V_2 -> V_63 , & V_39 -> V_198 ,
V_219 [ V_33 ] . V_194 ,
V_219 [ V_33 ] . V_199 ,
V_219 [ V_33 ] . V_180 , & V_180 ) ;
if ( V_94 ) {
F_17 ( V_39 ) ;
return V_94 ;
}
V_168 = F_91 ( V_39 , V_180 ,
V_219 [ V_33 ] . V_10 ) ;
if ( F_92 ( V_168 ) ) {
V_94 = F_93 ( V_168 ) ;
F_17 ( V_39 ) ;
return V_94 ;
} else if ( V_168 ) {
V_94 = F_75 ( V_2 -> V_63 , & V_2 -> V_64 -> V_165 ,
V_168 ) ;
F_70 ( V_168 ) ;
F_17 ( V_39 ) ;
if ( V_94 )
return V_94 ;
}
}
return 0 ;
}
static int F_94 ( struct V_1 * V_2 ,
T_1 V_10 )
{
int V_94 ;
struct V_175 * V_168 ;
V_94 = F_95 ( V_2 -> V_9 , V_10 , & V_168 ) ;
if ( V_94 )
return V_94 ;
V_94 = F_75 ( V_2 -> V_63 , & V_2 -> V_64 -> V_165 , V_168 ) ;
F_70 ( V_168 ) ;
return V_94 ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_48 * V_188 )
{
unsigned V_217 ;
int V_33 , V_94 ;
struct V_221 * V_219 ;
V_219 = (struct V_221 * ) V_188 -> V_57 ;
V_217 = V_188 -> V_55 * 4 /
sizeof( struct V_221 ) ;
for ( V_33 = 0 ; V_33 < V_217 ; ++ V_33 ) {
V_94 = F_94 ( V_2 , V_219 [ V_33 ] . V_10 ) ;
if ( V_94 )
return V_94 ;
}
return 0 ;
}
static int F_97 ( struct V_1 * V_2 ,
struct V_48 * V_188 )
{
unsigned V_217 ;
int V_33 ;
struct V_221 * V_219 ;
V_219 = (struct V_221 * ) V_188 -> V_57 ;
V_217 = V_188 -> V_55 * 4 /
sizeof( struct V_221 ) ;
V_2 -> V_170 = F_10 ( V_217 ,
sizeof( struct V_222 * ) ,
V_37 ) ;
V_2 -> V_169 = 0 ;
for ( V_33 = 0 ; V_33 < V_217 ; ++ V_33 ) {
V_2 -> V_170 [ V_33 ] = F_98 ( V_2 -> V_9 , V_219 [ V_33 ] . V_10 ) ;
if ( ! V_2 -> V_170 [ V_33 ] )
return - V_11 ;
V_2 -> V_169 ++ ;
}
return 0 ;
}
static int F_99 ( struct V_67 * V_63 ,
struct V_1 * V_2 )
{
int V_33 , V_94 ;
for ( V_33 = 0 ; V_33 < V_2 -> V_47 ; ++ V_33 ) {
struct V_48 * V_188 ;
V_188 = & V_2 -> V_44 [ V_33 ] ;
if ( V_188 -> V_54 == V_60 ) {
V_94 = F_90 ( V_2 , V_188 ) ;
if ( V_94 )
return V_94 ;
} else if ( V_188 -> V_54 == V_61 ) {
V_94 = F_96 ( V_2 , V_188 ) ;
if ( V_94 )
return V_94 ;
} else if ( V_188 -> V_54 == V_62 ) {
V_94 = F_97 ( V_2 , V_188 ) ;
if ( V_94 )
return V_94 ;
}
}
return 0 ;
}
static void F_100 ( struct V_1 * V_2 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_2 -> V_169 ; ++ V_33 )
F_101 ( V_2 -> V_170 [ V_33 ] , V_2 -> V_168 ) ;
}
static int F_102 ( struct V_1 * V_2 ,
union V_27 * V_28 )
{
struct V_179 * V_180 = V_2 -> V_64 -> V_180 ;
struct V_223 * V_224 = & V_2 -> V_39 -> V_225 [ V_180 -> V_226 ] . V_224 ;
struct V_227 * V_64 ;
int V_94 ;
V_64 = V_2 -> V_64 ;
V_2 -> V_64 = NULL ;
V_94 = F_103 ( & V_64 -> V_228 , & V_180 -> V_229 , V_224 , V_2 -> V_9 ) ;
if ( V_94 ) {
F_72 ( V_64 ) ;
return V_94 ;
}
V_64 -> V_230 = V_2 -> V_9 ;
V_64 -> V_231 = V_224 -> V_232 ;
V_2 -> V_168 = F_104 ( & V_64 -> V_228 . V_233 -> V_234 ) ;
F_100 ( V_2 ) ;
V_28 -> V_235 . V_10 = F_105 ( V_2 -> V_39 , V_180 , V_2 -> V_168 ) ;
V_64 -> V_236 = V_28 -> V_235 . V_10 ;
F_106 ( V_64 ) ;
F_67 ( V_2 , 0 , true ) ;
F_107 ( V_64 ) ;
F_108 ( & V_64 -> V_228 ) ;
return 0 ;
}
int F_109 ( struct V_237 * V_238 , void * V_4 , struct V_239 * V_9 )
{
struct V_67 * V_63 = V_238 -> V_240 ;
struct V_22 * V_23 = V_9 -> V_24 ;
union V_27 * V_28 = V_4 ;
struct V_1 V_166 = {} ;
bool V_241 = false ;
int V_33 , V_94 ;
if ( ! V_63 -> V_242 )
return - V_243 ;
if ( F_110 ( V_63 , V_23 ) )
return - V_244 ;
V_166 . V_63 = V_63 ;
V_166 . V_9 = V_9 ;
V_94 = F_9 ( & V_166 , V_4 ) ;
if ( V_94 ) {
F_49 ( L_11 ) ;
goto V_235;
}
V_94 = F_41 ( & V_166 , V_4 ) ;
if ( V_94 ) {
if ( V_94 == - V_38 )
F_49 ( L_12 ) ;
else if ( V_94 != - V_138 )
F_49 ( L_13 , V_94 ) ;
goto V_235;
}
V_241 = true ;
V_94 = F_84 ( V_63 , & V_166 ) ;
if ( V_94 )
goto V_235;
V_94 = F_99 ( V_63 , & V_166 ) ;
if ( V_94 ) {
F_49 ( L_14 , V_94 ) ;
goto V_235;
}
for ( V_33 = 0 ; V_33 < V_166 . V_64 -> V_31 ; V_33 ++ )
F_111 ( & V_166 , V_33 ) ;
V_94 = F_82 ( V_63 , & V_166 ) ;
if ( V_94 )
goto V_235;
V_94 = F_102 ( & V_166 , V_28 ) ;
if ( V_94 )
goto V_235;
return 0 ;
V_235:
F_67 ( & V_166 , V_94 , V_241 ) ;
return V_94 ;
}
int F_112 ( struct V_237 * V_238 , void * V_4 ,
struct V_239 * V_9 )
{
union V_245 * V_246 = V_4 ;
struct V_67 * V_63 = V_238 -> V_240 ;
struct V_22 * V_23 = V_9 -> V_24 ;
unsigned long V_247 = F_113 ( V_246 -> V_35 . V_247 ) ;
struct V_179 * V_180 = NULL ;
struct V_220 * V_39 ;
struct V_175 * V_168 ;
long V_94 ;
if ( F_110 ( V_63 , V_23 ) )
return - V_244 ;
V_39 = F_11 ( V_9 -> V_24 , V_246 -> V_35 . V_40 ) ;
if ( V_39 == NULL )
return - V_11 ;
V_94 = F_85 ( V_63 , & V_39 -> V_198 ,
V_246 -> V_35 . V_194 , V_246 -> V_35 . V_199 ,
V_246 -> V_35 . V_180 , & V_180 ) ;
if ( V_94 ) {
F_17 ( V_39 ) ;
return V_94 ;
}
V_168 = F_91 ( V_39 , V_180 , V_246 -> V_35 . V_10 ) ;
if ( F_92 ( V_168 ) )
V_94 = F_93 ( V_168 ) ;
else if ( V_168 ) {
V_94 = F_114 ( V_168 , true , V_247 ) ;
F_70 ( V_168 ) ;
} else
V_94 = 1 ;
F_17 ( V_39 ) ;
if ( V_94 < 0 )
return V_94 ;
memset ( V_246 , 0 , sizeof( * V_246 ) ) ;
V_246 -> V_235 . V_248 = ( V_94 == 0 ) ;
return 0 ;
}
static struct V_175 * F_115 ( struct V_67 * V_63 ,
struct V_239 * V_9 ,
struct V_249 * V_250 )
{
struct V_179 * V_180 ;
struct V_220 * V_39 ;
struct V_175 * V_168 ;
int V_94 ;
V_39 = F_11 ( V_9 -> V_24 , V_250 -> V_40 ) ;
if ( V_39 == NULL )
return F_116 ( - V_11 ) ;
V_94 = F_85 ( V_63 , & V_39 -> V_198 , V_250 -> V_194 ,
V_250 -> V_199 , V_250 -> V_180 , & V_180 ) ;
if ( V_94 ) {
F_17 ( V_39 ) ;
return F_116 ( V_94 ) ;
}
V_168 = F_91 ( V_39 , V_180 , V_250 -> V_251 ) ;
F_17 ( V_39 ) ;
return V_168 ;
}
static int F_117 ( struct V_67 * V_63 ,
struct V_239 * V_9 ,
union V_252 * V_246 ,
struct V_249 * V_253 )
{
T_1 V_254 = V_246 -> V_35 . V_254 ;
unsigned int V_33 ;
long V_94 = 1 ;
for ( V_33 = 0 ; V_33 < V_254 ; V_33 ++ ) {
struct V_175 * V_168 ;
unsigned long V_247 = F_113 ( V_246 -> V_35 . V_255 ) ;
V_168 = F_115 ( V_63 , V_9 , & V_253 [ V_33 ] ) ;
if ( F_92 ( V_168 ) )
return F_93 ( V_168 ) ;
else if ( ! V_168 )
continue;
V_94 = F_114 ( V_168 , true , V_247 ) ;
F_70 ( V_168 ) ;
if ( V_94 < 0 )
return V_94 ;
if ( V_94 == 0 )
break;
}
memset ( V_246 , 0 , sizeof( * V_246 ) ) ;
V_246 -> V_235 . V_248 = ( V_94 > 0 ) ;
return 0 ;
}
static int F_118 ( struct V_67 * V_63 ,
struct V_239 * V_9 ,
union V_252 * V_246 ,
struct V_249 * V_253 )
{
unsigned long V_247 = F_113 ( V_246 -> V_35 . V_255 ) ;
T_1 V_254 = V_246 -> V_35 . V_254 ;
T_1 V_256 = ~ 0 ;
struct V_175 * * V_140 ;
unsigned int V_33 ;
long V_94 ;
V_140 = F_119 ( V_254 , sizeof( struct V_175 * ) , V_37 ) ;
if ( V_140 == NULL )
return - V_38 ;
for ( V_33 = 0 ; V_33 < V_254 ; V_33 ++ ) {
struct V_175 * V_168 ;
V_168 = F_115 ( V_63 , V_9 , & V_253 [ V_33 ] ) ;
if ( F_92 ( V_168 ) ) {
V_94 = F_93 ( V_168 ) ;
goto V_257;
} else if ( V_168 ) {
V_140 [ V_33 ] = V_168 ;
} else {
V_94 = 1 ;
goto V_235;
}
}
V_94 = F_120 ( V_140 , V_254 , true , V_247 ,
& V_256 ) ;
if ( V_94 < 0 )
goto V_257;
V_235:
memset ( V_246 , 0 , sizeof( * V_246 ) ) ;
V_246 -> V_235 . V_248 = ( V_94 > 0 ) ;
V_246 -> V_235 . V_258 = V_256 ;
V_94 = 0 ;
V_257:
for ( V_33 = 0 ; V_33 < V_254 ; V_33 ++ )
F_70 ( V_140 [ V_33 ] ) ;
F_15 ( V_140 ) ;
return V_94 ;
}
int F_121 ( struct V_237 * V_238 , void * V_4 ,
struct V_239 * V_9 )
{
struct V_67 * V_63 = V_238 -> V_240 ;
struct V_22 * V_23 = V_9 -> V_24 ;
union V_252 * V_246 = V_4 ;
T_1 V_254 = V_246 -> V_35 . V_254 ;
struct V_249 * V_259 ;
struct V_249 * V_253 ;
int V_94 ;
if ( F_110 ( V_63 , V_23 ) )
return - V_244 ;
V_253 = F_10 ( V_254 , sizeof( struct V_249 ) ,
V_37 ) ;
if ( V_253 == NULL )
return - V_38 ;
V_259 = ( void V_42 * ) ( V_43 ) ( V_246 -> V_35 . V_253 ) ;
if ( F_12 ( V_253 , V_259 ,
sizeof( struct V_249 ) * V_254 ) ) {
V_94 = - V_45 ;
goto V_260;
}
if ( V_246 -> V_35 . V_261 )
V_94 = F_117 ( V_63 , V_9 , V_246 , V_253 ) ;
else
V_94 = F_118 ( V_63 , V_9 , V_246 , V_253 ) ;
V_260:
F_15 ( V_253 ) ;
return V_94 ;
}
struct V_205 *
F_86 ( struct V_1 * V_166 ,
T_2 V_262 , struct V_90 * * V_16 )
{
struct V_205 * V_263 ;
unsigned V_33 ;
if ( ! V_166 -> V_130 )
return NULL ;
V_262 /= V_211 ;
for ( V_33 = 0 ; V_33 < V_166 -> V_130 -> V_133 ; V_33 ++ ) {
struct V_106 * V_114 ;
V_114 = & V_166 -> V_130 -> V_140 [ V_33 ] ;
if ( ! V_114 -> V_155 )
continue;
F_40 (mapping, &lobj->bo_va->valids, list) {
if ( V_263 -> V_212 > V_262 ||
V_262 > V_263 -> V_210 )
continue;
* V_16 = V_114 -> V_155 -> V_16 ;
return V_263 ;
}
F_40 (mapping, &lobj->bo_va->invalids, list) {
if ( V_263 -> V_212 > V_262 ||
V_262 > V_263 -> V_210 )
continue;
* V_16 = V_114 -> V_155 -> V_16 ;
return V_263 ;
}
}
return NULL ;
}
int F_122 ( struct V_1 * V_166 )
{
unsigned V_33 ;
int V_94 ;
if ( ! V_166 -> V_130 )
return 0 ;
for ( V_33 = 0 ; V_33 < V_166 -> V_130 -> V_133 ; V_33 ++ ) {
struct V_90 * V_16 = V_166 -> V_130 -> V_140 [ V_33 ] . V_13 ;
V_94 = F_62 ( & V_16 -> V_17 , & V_16 -> V_17 . V_109 ) ;
if ( F_33 ( V_94 ) )
return V_94 ;
if ( V_16 -> V_87 & V_264 )
continue;
V_16 -> V_87 |= V_264 ;
F_31 ( V_16 , V_16 -> V_99 ) ;
V_94 = F_32 ( & V_16 -> V_17 , & V_16 -> V_102 , false , false ) ;
if ( F_33 ( V_94 ) )
return V_94 ;
}
return 0 ;
}
