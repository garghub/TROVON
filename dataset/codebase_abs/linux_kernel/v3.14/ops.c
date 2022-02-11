static int T_1 F_1 ( void )
{
int V_1 ;
V_1 = F_2 () ;
if ( V_1 ) {
F_3 ( L_1 , V_1 ) ;
return V_1 ;
}
V_1 = F_4 ( L_2 , & V_2 ) ;
if ( V_1 ) {
F_3 ( L_3 , V_1 ) ;
F_5 () ;
}
return V_1 ;
}
static void T_2 F_6 ( void )
{
F_7 ( L_2 ) ;
F_5 () ;
}
static void F_8 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
T_3 V_7 , V_8 , V_9 ;
T_4 V_10 = 0 ;
V_7 = ( V_6 -> V_11 -> V_12 & V_13 ) >>
V_14 ;
V_8 = ( V_6 -> V_11 -> V_12 & V_15 ) >>
V_16 ;
V_9 = ( V_6 -> V_11 -> V_12 & V_17 ) >>
V_18 ;
V_10 |= F_10 ( V_6 -> V_19 -> V_20 ) <<
V_21 ;
V_10 |= F_11 ( V_6 -> V_19 -> V_20 ) <<
V_22 ;
V_10 |= V_7 << V_23 ;
V_10 |= V_8 << V_24 ;
V_10 |= V_9 << V_25 ;
F_12 ( ( V_7 << V_23 ) &
~ V_26 ) ;
V_10 |= V_27 ;
F_13 ( V_6 -> V_19 , V_28 ,
V_29 |
V_30 |
V_26 |
V_31 |
V_32 |
V_27 |
V_33 ,
V_10 ) ;
F_14 ( V_6 , L_4 , V_7 ,
V_8 , V_9 ) ;
F_15 ( V_6 -> V_19 , V_34 ,
V_35 ,
~ V_35 ) ;
}
static struct V_3 *
F_16 ( struct V_36 * V_19 , const struct V_37 * V_38 ,
const struct V_39 * V_11 , struct V_40 * V_41 )
{
struct V_42 * V_43 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_44 V_45 = {} ;
static const T_3 V_46 [] = {
V_47 ,
} ;
int V_48 , V_49 ;
V_43 = F_17 ( sizeof( struct V_3 ) +
sizeof( struct V_5 ) ,
& V_50 ) ;
if ( ! V_43 )
return NULL ;
V_4 = V_43 -> V_51 ;
V_4 -> V_52 = & V_2 ;
V_6 = F_9 ( V_4 ) ;
V_6 -> V_53 = V_19 -> V_53 ;
V_6 -> V_19 = V_19 ;
V_6 -> V_38 = V_38 ;
V_6 -> V_11 = V_11 ;
V_6 -> V_43 = V_43 ;
V_6 -> V_54 = V_55 . V_54 ? - 1 : 0 ;
V_6 -> V_56 = 15 ;
V_6 -> V_57 = 16 ;
V_6 -> V_58 = V_6 -> V_38 -> V_59 -> V_60 - 1 ;
if ( V_6 -> V_38 -> V_59 -> V_60 == 16 ) {
V_6 -> V_56 = 11 ;
V_6 -> V_57 = 12 ;
}
V_6 -> V_61 = V_62 ;
F_18 ( & V_6 -> V_63 ) ;
F_19 ( & V_6 -> V_64 ) ;
F_20 ( & V_6 -> V_65 ) ;
F_20 ( & V_6 -> V_66 ) ;
F_19 ( & V_6 -> V_67 ) ;
F_21 ( & V_6 -> V_68 , V_69 ) ;
F_21 ( & V_6 -> V_70 , V_71 ) ;
F_21 ( & V_6 -> V_72 , V_73 ) ;
F_22 ( V_6 -> V_43 , V_6 -> V_19 -> V_53 ) ;
V_45 . V_4 = V_4 ;
V_45 . V_46 = V_46 ;
V_45 . V_74 = F_23 ( V_46 ) ;
V_45 . V_75 = V_55 . V_76 ;
if ( V_6 -> V_11 -> V_77 . V_78 & V_79 )
V_45 . V_80 = true ;
if ( ! V_55 . V_81 )
V_45 . V_82 = V_38 -> V_59 -> V_83 ;
else
V_45 . V_82 = V_84 ;
V_45 . V_85 = V_86 ;
V_45 . V_87 = V_88 ;
V_45 . V_89 = V_90 ;
snprintf ( V_6 -> V_43 -> V_91 -> V_92 ,
sizeof( V_6 -> V_43 -> V_91 -> V_92 ) ,
L_5 , V_11 -> V_92 ) ;
F_24 ( V_6 -> V_19 , & V_45 ) ;
V_19 -> V_93 = V_94 ;
V_19 -> V_95 = sizeof( struct V_96 ) ;
F_25 ( & V_6 -> V_97 ) ;
V_6 -> V_98 = F_26 ( V_19 ) ;
if ( ! V_6 -> V_98 ) {
F_27 ( V_6 , L_6 ) ;
goto V_99;
}
F_28 ( V_6 , L_7 ,
V_6 -> V_38 -> V_100 , V_6 -> V_19 -> V_20 ) ;
F_29 ( V_6 ) ;
if ( V_55 . V_101 ) {
V_48 = F_30 ( V_6 ) ;
if ( V_48 )
goto V_99;
} else {
V_48 = F_31 ( V_6 -> V_19 ) ;
if ( V_48 )
goto V_99;
F_32 ( & V_6 -> V_63 ) ;
V_48 = F_33 ( V_6 , true ) ;
F_34 ( V_19 ) ;
F_35 ( & V_6 -> V_63 ) ;
if ( V_48 < 0 && ! V_102 . V_103 ) {
F_27 ( V_6 , L_8 , V_48 ) ;
goto V_99;
}
}
V_49 = sizeof( struct V_104 ) +
V_6 -> V_11 -> V_77 . V_105 +
( V_106 * sizeof( struct V_107 ) ) ;
V_6 -> V_108 = F_36 ( V_49 , V_109 ) ;
if ( ! V_6 -> V_108 )
goto V_99;
V_48 = F_37 ( V_6 ) ;
if ( V_48 )
goto V_99;
V_48 = F_38 ( V_6 , V_41 ) ;
if ( V_48 )
goto V_110;
if ( V_6 -> V_11 -> V_77 . V_78 & V_111 )
V_6 -> V_112 = & V_113 ;
else
V_6 -> V_112 = & V_114 ;
memset ( & V_6 -> V_115 , 0 , sizeof( struct V_116 ) ) ;
return V_4 ;
V_110:
F_39 ( V_6 -> V_43 ) ;
F_40 ( V_6 ) ;
V_99:
F_41 ( V_6 -> V_98 ) ;
F_42 ( V_6 -> V_108 ) ;
if ( ! V_55 . V_101 )
F_43 ( V_19 ) ;
F_44 ( V_6 -> V_43 ) ;
return NULL ;
}
static void F_45 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
int V_117 ;
F_40 ( V_6 ) ;
F_46 ( V_6 ) ;
F_39 ( V_6 -> V_43 ) ;
F_42 ( V_6 -> V_108 ) ;
F_42 ( V_6 -> V_118 ) ;
V_6 -> V_118 = NULL ;
#if F_47 ( V_119 ) && F_47 ( V_120 )
F_42 ( V_6 -> V_121 ) ;
#endif
F_43 ( V_6 -> V_19 ) ;
F_41 ( V_6 -> V_98 ) ;
V_6 -> V_98 = NULL ;
F_48 ( V_6 -> V_122 ) ;
for ( V_117 = 0 ; V_117 < V_123 ; V_117 ++ )
F_42 ( V_6 -> V_124 [ V_117 ] . V_125 ) ;
F_44 ( V_6 -> V_43 ) ;
}
void F_49 ( struct V_5 * V_6 )
{
struct V_126 * V_127 , * V_128 ;
F_50 ( & V_6 -> V_64 ) ;
F_51 (entry, tmp, &mvm->async_handlers_list, list) {
F_52 ( & V_127 -> V_129 ) ;
F_53 ( & V_127 -> V_130 ) ;
F_42 ( V_127 ) ;
}
F_54 ( & V_6 -> V_64 ) ;
}
static void V_69 ( struct V_131 * V_132 )
{
struct V_5 * V_6 =
F_55 ( V_132 , struct V_5 , V_68 ) ;
struct V_126 * V_127 , * V_128 ;
struct V_133 V_134 ;
F_20 ( & V_134 ) ;
F_32 ( & V_6 -> V_63 ) ;
F_50 ( & V_6 -> V_64 ) ;
F_56 ( & V_6 -> V_66 , & V_134 ) ;
F_54 ( & V_6 -> V_64 ) ;
F_51 (entry, tmp, &local_list, list) {
if ( V_127 -> V_135 ( V_6 , & V_127 -> V_129 , NULL ) )
F_57 ( V_6 ,
L_9 ) ;
F_52 ( & V_127 -> V_129 ) ;
F_53 ( & V_127 -> V_130 ) ;
F_42 ( V_127 ) ;
}
F_35 ( & V_6 -> V_63 ) ;
}
static int F_58 ( struct V_3 * V_4 ,
struct V_136 * V_129 ,
struct V_137 * V_138 )
{
struct V_139 * V_140 = F_59 ( V_129 ) ;
struct V_5 * V_6 = F_9 ( V_4 ) ;
T_3 V_117 ;
F_60 ( & V_6 -> V_97 , V_140 ) ;
for ( V_117 = 0 ; V_117 < F_23 ( V_141 ) ; V_117 ++ ) {
const struct V_142 * V_143 = & V_141 [ V_117 ] ;
struct V_126 * V_127 ;
if ( V_143 -> V_144 != V_140 -> V_145 . V_138 )
continue;
if ( ! V_143 -> V_146 )
return V_143 -> V_135 ( V_6 , V_129 , V_138 ) ;
V_127 = F_61 ( sizeof( * V_127 ) , V_147 ) ;
if ( ! V_127 )
return 0 ;
V_127 -> V_129 . V_148 = F_62 ( V_129 ) ;
V_127 -> V_129 . V_149 = V_129 -> V_149 ;
V_127 -> V_129 . V_150 = V_129 -> V_150 ;
V_127 -> V_135 = V_143 -> V_135 ;
F_63 ( & V_6 -> V_64 ) ;
F_64 ( & V_127 -> V_130 , & V_6 -> V_66 ) ;
F_65 ( & V_6 -> V_64 ) ;
F_66 ( & V_6 -> V_68 ) ;
break;
}
return 0 ;
}
static void F_67 ( struct V_3 * V_4 , int V_151 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
int V_152 = V_6 -> V_153 [ V_151 ] ;
if ( F_68 ( V_152 == V_154 ) )
return;
if ( F_69 ( & V_6 -> V_155 [ V_152 ] ) > 1 ) {
F_70 ( V_6 ,
L_10 ,
V_151 , V_152 ) ;
return;
}
F_71 ( V_152 , & V_6 -> V_156 ) ;
F_72 ( V_6 -> V_43 , V_152 ) ;
}
static void F_73 ( struct V_3 * V_4 , int V_151 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
int V_152 = V_6 -> V_153 [ V_151 ] ;
if ( F_68 ( V_152 == V_154 ) )
return;
if ( F_74 ( & V_6 -> V_155 [ V_152 ] ) > 0 ) {
F_70 ( V_6 ,
L_11 ,
V_151 , V_152 ) ;
return;
}
F_75 ( V_152 , & V_6 -> V_156 ) ;
F_76 ( V_6 -> V_43 , V_152 ) ;
}
void F_77 ( struct V_5 * V_6 , bool V_157 )
{
if ( V_157 )
F_71 ( V_158 , & V_6 -> V_159 ) ;
else
F_75 ( V_158 , & V_6 -> V_159 ) ;
F_78 ( V_6 -> V_43 -> V_91 , F_79 ( V_6 ) ) ;
}
static void F_80 ( struct V_3 * V_4 , bool V_157 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
if ( V_157 )
F_71 ( V_160 , & V_6 -> V_159 ) ;
else
F_75 ( V_160 , & V_6 -> V_159 ) ;
if ( V_157 && V_6 -> V_161 != V_162 )
F_34 ( V_6 -> V_19 ) ;
F_78 ( V_6 -> V_43 -> V_91 , F_79 ( V_6 ) ) ;
}
static void F_81 ( struct V_3 * V_4 , struct V_163 * V_164 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
struct V_165 * V_166 ;
V_166 = F_82 ( V_164 ) ;
F_83 ( V_6 -> V_19 , V_166 -> V_167 [ 1 ] ) ;
F_84 ( V_6 -> V_43 , V_164 ) ;
}
static void F_85 ( struct V_131 * V_132 )
{
struct V_168 * V_169 ;
V_169 = F_55 ( V_132 , struct V_168 , V_170 ) ;
if ( F_86 ( V_169 -> V_53 ) )
F_87 ( V_169 -> V_53 , L_12 ) ;
F_42 ( V_169 ) ;
F_88 ( V_171 ) ;
}
static void F_89 ( struct V_5 * V_6 )
{
F_90 ( & V_6 -> V_97 ) ;
if ( F_91 ( V_172 , & V_6 -> V_159 ) ) {
struct V_168 * V_169 ;
F_27 ( V_6 ,
L_13 ) ;
if ( ! F_92 ( V_171 ) ) {
F_27 ( V_6 , L_14 ) ;
return;
}
V_169 = F_61 ( sizeof( * V_169 ) , V_147 ) ;
if ( ! V_169 ) {
F_88 ( V_171 ) ;
return;
}
V_169 -> V_53 = V_6 -> V_19 -> V_53 ;
F_21 ( & V_169 -> V_170 , F_85 ) ;
F_66 ( & V_169 -> V_170 ) ;
} else if ( V_6 -> V_161 == V_173 && V_6 -> V_54 ) {
switch ( V_6 -> V_174 ) {
case V_175 :
break;
case V_176 :
F_93 ( V_6 -> V_43 , true ) ;
break;
case V_177 :
F_94 ( V_6 -> V_43 ) ;
break;
}
if ( V_6 -> V_54 > 0 )
V_6 -> V_54 -- ;
F_95 ( V_6 -> V_43 ) ;
}
}
static void F_96 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_97 ( V_6 ) ;
if ( ! V_6 -> V_54 )
F_98 ( V_6 ) ;
F_89 ( V_6 ) ;
}
static void F_99 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_12 ( 1 ) ;
F_89 ( V_6 ) ;
}
