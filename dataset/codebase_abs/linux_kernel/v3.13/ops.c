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
V_4 -> V_19 = V_19 ;
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
F_18 ( & V_6 -> V_61 ) ;
F_19 ( & V_6 -> V_62 ) ;
F_20 ( & V_6 -> V_63 ) ;
F_20 ( & V_6 -> V_64 ) ;
F_19 ( & V_6 -> V_65 ) ;
F_21 ( & V_6 -> V_66 , V_67 ) ;
F_21 ( & V_6 -> V_68 , V_69 ) ;
F_21 ( & V_6 -> V_70 , V_71 ) ;
F_22 ( V_6 -> V_43 , V_6 -> V_19 -> V_53 ) ;
V_45 . V_4 = V_4 ;
V_45 . V_46 = V_46 ;
V_45 . V_72 = F_23 ( V_46 ) ;
V_45 . V_73 = V_55 . V_74 ;
if ( V_6 -> V_11 -> V_75 . V_76 & V_77 )
V_45 . V_78 = true ;
if ( ! V_55 . V_79 )
V_45 . V_80 = V_38 -> V_59 -> V_81 ;
else
V_45 . V_80 = V_82 ;
V_45 . V_83 = V_84 ;
V_45 . V_85 = V_86 ;
V_45 . V_87 = V_88 ;
snprintf ( V_6 -> V_43 -> V_89 -> V_90 ,
sizeof( V_6 -> V_43 -> V_89 -> V_90 ) ,
L_5 , V_11 -> V_90 ) ;
F_24 ( V_6 -> V_19 , & V_45 ) ;
V_19 -> V_91 = V_92 ;
V_19 -> V_93 = sizeof( struct V_94 ) ;
F_25 ( & V_6 -> V_95 ) ;
V_6 -> V_96 = F_26 ( V_19 ) ;
if ( ! V_6 -> V_96 ) {
F_27 ( V_6 , L_6 ) ;
goto V_97;
}
F_28 ( V_6 , L_7 ,
V_6 -> V_38 -> V_98 , V_6 -> V_19 -> V_20 ) ;
F_29 ( V_6 ) ;
if ( V_55 . V_99 ) {
F_30 ( V_6 ) ;
} else {
V_48 = F_31 ( V_6 -> V_19 ) ;
if ( V_48 )
goto V_97;
F_32 ( & V_6 -> V_61 ) ;
V_48 = F_33 ( V_6 , true ) ;
F_34 ( & V_6 -> V_61 ) ;
if ( V_48 < 0 && ! V_100 . V_101 ) {
F_27 ( V_6 , L_8 , V_48 ) ;
goto V_97;
}
if ( ! V_100 . V_101 )
F_35 ( V_6 -> V_19 , false ) ;
}
V_49 = sizeof( struct V_102 ) +
V_6 -> V_11 -> V_75 . V_103 +
( V_104 * sizeof( struct V_105 ) ) ;
V_6 -> V_106 = F_36 ( V_49 , V_107 ) ;
if ( ! V_6 -> V_106 )
goto V_97;
V_48 = F_37 ( V_6 ) ;
if ( V_48 )
goto V_97;
V_48 = F_38 ( V_6 , V_41 ) ;
if ( V_48 )
goto V_108;
if ( V_6 -> V_11 -> V_75 . V_76 & V_109 )
V_6 -> V_110 = & V_111 ;
else
V_6 -> V_110 = & V_112 ;
memset ( & V_6 -> V_113 , 0 , sizeof( struct V_114 ) ) ;
return V_4 ;
V_108:
F_39 ( V_6 -> V_43 ) ;
V_97:
F_40 ( V_6 -> V_96 ) ;
F_41 ( V_6 -> V_106 ) ;
if ( ! V_55 . V_99 )
F_35 ( V_19 , true ) ;
F_42 ( V_6 -> V_43 ) ;
return NULL ;
}
static void F_43 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
int V_115 ;
F_44 ( V_6 ) ;
F_45 ( V_6 ) ;
F_39 ( V_6 -> V_43 ) ;
F_41 ( V_6 -> V_106 ) ;
#if F_46 ( V_116 ) && F_46 ( V_117 )
F_41 ( V_6 -> V_118 ) ;
#endif
F_35 ( V_6 -> V_19 , true ) ;
F_40 ( V_6 -> V_96 ) ;
V_6 -> V_96 = NULL ;
F_47 ( V_6 -> V_119 ) ;
for ( V_115 = 0 ; V_115 < V_120 ; V_115 ++ )
F_41 ( V_6 -> V_121 [ V_115 ] . V_122 ) ;
F_42 ( V_6 -> V_43 ) ;
}
void F_48 ( struct V_5 * V_6 )
{
struct V_123 * V_124 , * V_125 ;
F_49 ( & V_6 -> V_62 ) ;
F_50 (entry, tmp, &mvm->async_handlers_list, list) {
F_51 ( & V_124 -> V_126 ) ;
F_52 ( & V_124 -> V_127 ) ;
F_41 ( V_124 ) ;
}
F_53 ( & V_6 -> V_62 ) ;
}
static void V_67 ( struct V_128 * V_129 )
{
struct V_5 * V_6 =
F_54 ( V_129 , struct V_5 , V_66 ) ;
struct V_123 * V_124 , * V_125 ;
struct V_130 V_131 ;
F_20 ( & V_131 ) ;
F_32 ( & V_6 -> V_61 ) ;
F_49 ( & V_6 -> V_62 ) ;
F_55 ( & V_6 -> V_64 , & V_131 ) ;
F_53 ( & V_6 -> V_62 ) ;
F_50 (entry, tmp, &local_list, list) {
if ( V_124 -> V_132 ( V_6 , & V_124 -> V_126 , NULL ) )
F_56 ( V_6 ,
L_9 ) ;
F_51 ( & V_124 -> V_126 ) ;
F_52 ( & V_124 -> V_127 ) ;
F_41 ( V_124 ) ;
}
F_34 ( & V_6 -> V_61 ) ;
}
static int F_57 ( struct V_3 * V_4 ,
struct V_133 * V_126 ,
struct V_134 * V_135 )
{
struct V_136 * V_137 = F_58 ( V_126 ) ;
struct V_5 * V_6 = F_9 ( V_4 ) ;
T_3 V_115 ;
F_59 ( & V_6 -> V_95 , V_137 ) ;
for ( V_115 = 0 ; V_115 < F_23 ( V_138 ) ; V_115 ++ ) {
const struct V_139 * V_140 = & V_138 [ V_115 ] ;
struct V_123 * V_124 ;
if ( V_140 -> V_141 != V_137 -> V_142 . V_135 )
continue;
if ( ! V_140 -> V_143 )
return V_140 -> V_132 ( V_6 , V_126 , V_135 ) ;
V_124 = F_60 ( sizeof( * V_124 ) , V_144 ) ;
if ( ! V_124 )
return 0 ;
V_124 -> V_126 . V_145 = F_61 ( V_126 ) ;
V_124 -> V_126 . V_146 = V_126 -> V_146 ;
V_124 -> V_126 . V_147 = V_126 -> V_147 ;
V_124 -> V_132 = V_140 -> V_132 ;
F_62 ( & V_6 -> V_62 ) ;
F_63 ( & V_124 -> V_127 , & V_6 -> V_64 ) ;
F_64 ( & V_6 -> V_62 ) ;
F_65 ( & V_6 -> V_66 ) ;
break;
}
return 0 ;
}
static void F_66 ( struct V_3 * V_4 , int V_148 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
int V_149 = V_6 -> V_150 [ V_148 ] ;
if ( F_67 ( V_149 == V_151 ) )
return;
if ( F_68 ( & V_6 -> V_152 [ V_149 ] ) > 1 ) {
F_69 ( V_6 ,
L_10 ,
V_148 , V_149 ) ;
return;
}
F_70 ( V_149 , & V_6 -> V_153 ) ;
F_71 ( V_6 -> V_43 , V_149 ) ;
}
static void F_72 ( struct V_3 * V_4 , int V_148 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
int V_149 = V_6 -> V_150 [ V_148 ] ;
if ( F_67 ( V_149 == V_151 ) )
return;
if ( F_73 ( & V_6 -> V_152 [ V_149 ] ) > 0 ) {
F_69 ( V_6 ,
L_11 ,
V_148 , V_149 ) ;
return;
}
F_74 ( V_149 , & V_6 -> V_153 ) ;
F_75 ( V_6 -> V_43 , V_149 ) ;
}
void F_76 ( struct V_5 * V_6 , bool V_154 )
{
if ( V_154 )
F_70 ( V_155 , & V_6 -> V_156 ) ;
else
F_74 ( V_155 , & V_6 -> V_156 ) ;
F_77 ( V_6 -> V_43 -> V_89 , F_78 ( V_6 ) ) ;
}
static void F_79 ( struct V_3 * V_4 , bool V_154 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
if ( V_154 )
F_70 ( V_157 , & V_6 -> V_156 ) ;
else
F_74 ( V_157 , & V_6 -> V_156 ) ;
F_77 ( V_6 -> V_43 -> V_89 , F_78 ( V_6 ) ) ;
}
static void F_80 ( struct V_3 * V_4 , struct V_158 * V_159 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
struct V_160 * V_161 ;
V_161 = F_81 ( V_159 ) ;
F_82 ( V_6 -> V_19 , V_161 -> V_162 [ 1 ] ) ;
F_83 ( V_6 -> V_43 , V_159 ) ;
}
static void F_84 ( struct V_128 * V_129 )
{
struct V_163 * V_164 ;
V_164 = F_54 ( V_129 , struct V_163 , V_165 ) ;
if ( F_85 ( V_164 -> V_53 ) )
F_86 ( V_164 -> V_53 , L_12 ) ;
F_41 ( V_164 ) ;
F_87 ( V_166 ) ;
}
static void F_88 ( struct V_5 * V_6 )
{
F_89 ( & V_6 -> V_95 ) ;
if ( F_90 ( V_167 , & V_6 -> V_156 ) ) {
struct V_163 * V_164 ;
F_27 ( V_6 ,
L_13 ) ;
if ( ! F_91 ( V_166 ) ) {
F_27 ( V_6 , L_14 ) ;
return;
}
V_164 = F_60 ( sizeof( * V_164 ) , V_144 ) ;
if ( ! V_164 ) {
F_87 ( V_166 ) ;
return;
}
V_164 -> V_53 = V_6 -> V_19 -> V_53 ;
F_21 ( & V_164 -> V_165 , F_84 ) ;
F_65 ( & V_164 -> V_165 ) ;
} else if ( V_6 -> V_168 == V_169 && V_6 -> V_54 ) {
switch ( V_6 -> V_170 ) {
case V_171 :
break;
case V_172 :
F_92 ( V_6 -> V_43 , true ) ;
break;
case V_173 :
F_93 ( V_6 -> V_43 ) ;
break;
}
if ( V_6 -> V_54 > 0 )
V_6 -> V_54 -- ;
F_94 ( V_6 -> V_43 ) ;
}
}
static void F_95 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_96 ( V_6 ) ;
if ( ! V_6 -> V_54 )
F_97 ( V_6 ) ;
F_88 ( V_6 ) ;
}
static void F_98 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_12 ( 1 ) ;
F_88 ( V_6 ) ;
}
