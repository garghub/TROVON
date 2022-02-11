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
F_18 ( & V_6 -> V_56 ) ;
F_19 ( & V_6 -> V_57 ) ;
F_20 ( & V_6 -> V_58 ) ;
F_20 ( & V_6 -> V_59 ) ;
F_19 ( & V_6 -> V_60 ) ;
F_21 ( & V_6 -> V_61 , V_62 ) ;
F_21 ( & V_6 -> V_63 , V_64 ) ;
F_21 ( & V_6 -> V_65 , V_66 ) ;
F_22 ( V_6 -> V_43 , V_6 -> V_19 -> V_53 ) ;
V_45 . V_4 = V_4 ;
V_45 . V_46 = V_46 ;
V_45 . V_67 = F_23 ( V_46 ) ;
V_45 . V_68 = V_55 . V_69 ;
if ( V_6 -> V_11 -> V_70 . V_71 & V_72 )
V_45 . V_73 = true ;
if ( ! V_55 . V_74 )
V_45 . V_75 = V_38 -> V_76 -> V_77 ;
else
V_45 . V_75 = V_78 ;
V_45 . V_79 = V_80 ;
V_45 . V_81 = V_82 ;
V_45 . V_83 = V_84 ;
snprintf ( V_6 -> V_43 -> V_85 -> V_86 ,
sizeof( V_6 -> V_43 -> V_85 -> V_86 ) ,
L_5 , V_11 -> V_86 ) ;
F_24 ( V_6 -> V_19 , & V_45 ) ;
V_19 -> V_87 = V_88 ;
V_19 -> V_89 = sizeof( struct V_90 ) ;
F_25 ( & V_6 -> V_91 ) ;
V_6 -> V_92 = F_26 ( V_19 ) ;
if ( ! V_6 -> V_92 ) {
F_27 ( V_6 , L_6 ) ;
goto V_93;
}
F_28 ( V_6 , L_7 ,
V_6 -> V_38 -> V_94 , V_6 -> V_19 -> V_20 ) ;
V_48 = F_29 ( V_6 -> V_19 ) ;
if ( V_48 )
goto V_93;
F_30 ( V_6 ) ;
F_31 ( & V_6 -> V_56 ) ;
V_48 = F_32 ( V_6 , true ) ;
F_33 ( & V_6 -> V_56 ) ;
if ( V_48 < 0 && ! V_95 . V_96 ) {
F_27 ( V_6 , L_8 , V_48 ) ;
goto V_93;
}
if ( ! V_95 . V_96 )
F_34 ( V_6 -> V_19 , false ) ;
V_49 = sizeof( struct V_97 ) +
V_6 -> V_11 -> V_70 . V_98 +
( V_99 * sizeof( struct V_100 ) ) ;
V_6 -> V_101 = F_35 ( V_49 , V_102 ) ;
if ( ! V_6 -> V_101 )
goto V_93;
V_48 = F_36 ( V_6 ) ;
if ( V_48 )
goto V_93;
V_48 = F_37 ( V_6 , V_41 ) ;
if ( V_48 )
goto V_103;
if ( V_6 -> V_11 -> V_70 . V_71 & V_104 )
V_6 -> V_105 = & V_106 ;
else
V_6 -> V_105 = & V_107 ;
memset ( & V_6 -> V_108 , 0 , sizeof( struct V_109 ) ) ;
return V_4 ;
V_103:
F_38 ( V_6 -> V_43 ) ;
V_93:
F_39 ( V_6 -> V_92 ) ;
F_40 ( V_6 -> V_101 ) ;
F_34 ( V_19 , true ) ;
F_41 ( V_6 -> V_43 ) ;
return NULL ;
}
static void F_42 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
int V_110 ;
F_43 ( V_6 ) ;
F_44 ( V_6 ) ;
F_38 ( V_6 -> V_43 ) ;
F_40 ( V_6 -> V_101 ) ;
#if F_45 ( V_111 ) && F_45 ( V_112 )
F_40 ( V_6 -> V_113 ) ;
#endif
F_34 ( V_6 -> V_19 , true ) ;
F_39 ( V_6 -> V_92 ) ;
V_6 -> V_92 = NULL ;
F_46 ( V_6 -> V_114 ) ;
for ( V_110 = 0 ; V_110 < V_115 ; V_110 ++ )
F_40 ( V_6 -> V_116 [ V_110 ] . V_117 ) ;
F_41 ( V_6 -> V_43 ) ;
}
void F_47 ( struct V_5 * V_6 )
{
struct V_118 * V_119 , * V_120 ;
F_48 ( & V_6 -> V_57 ) ;
F_49 (entry, tmp, &mvm->async_handlers_list, list) {
F_50 ( & V_119 -> V_121 ) ;
F_51 ( & V_119 -> V_122 ) ;
F_40 ( V_119 ) ;
}
F_52 ( & V_6 -> V_57 ) ;
}
static void V_62 ( struct V_123 * V_124 )
{
struct V_5 * V_6 =
F_53 ( V_124 , struct V_5 , V_61 ) ;
struct V_118 * V_119 , * V_120 ;
struct V_125 V_126 ;
F_20 ( & V_126 ) ;
F_31 ( & V_6 -> V_56 ) ;
F_48 ( & V_6 -> V_57 ) ;
F_54 ( & V_6 -> V_59 , & V_126 ) ;
F_52 ( & V_6 -> V_57 ) ;
F_49 (entry, tmp, &local_list, list) {
if ( V_119 -> V_127 ( V_6 , & V_119 -> V_121 , NULL ) )
F_55 ( V_6 ,
L_9 ) ;
F_50 ( & V_119 -> V_121 ) ;
F_51 ( & V_119 -> V_122 ) ;
F_40 ( V_119 ) ;
}
F_33 ( & V_6 -> V_56 ) ;
}
static int F_56 ( struct V_3 * V_4 ,
struct V_128 * V_121 ,
struct V_129 * V_130 )
{
struct V_131 * V_132 = F_57 ( V_121 ) ;
struct V_5 * V_6 = F_9 ( V_4 ) ;
T_3 V_110 ;
F_58 ( & V_6 -> V_91 , V_132 ) ;
for ( V_110 = 0 ; V_110 < F_23 ( V_133 ) ; V_110 ++ ) {
const struct V_134 * V_135 = & V_133 [ V_110 ] ;
struct V_118 * V_119 ;
if ( V_135 -> V_136 != V_132 -> V_137 . V_130 )
continue;
if ( ! V_135 -> V_138 )
return V_135 -> V_127 ( V_6 , V_121 , V_130 ) ;
V_119 = F_59 ( sizeof( * V_119 ) , V_139 ) ;
if ( ! V_119 )
return 0 ;
V_119 -> V_121 . V_140 = F_60 ( V_121 ) ;
V_119 -> V_121 . V_141 = V_121 -> V_141 ;
V_119 -> V_121 . V_142 = V_121 -> V_142 ;
V_119 -> V_127 = V_135 -> V_127 ;
F_61 ( & V_6 -> V_57 ) ;
F_62 ( & V_119 -> V_122 , & V_6 -> V_59 ) ;
F_63 ( & V_6 -> V_57 ) ;
F_64 ( & V_6 -> V_61 ) ;
break;
}
return 0 ;
}
static void F_65 ( struct V_3 * V_4 , int V_143 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
int V_144 = V_6 -> V_145 [ V_143 ] ;
if ( F_66 ( V_144 == V_146 ) )
return;
if ( F_67 ( & V_6 -> V_147 [ V_144 ] ) > 1 ) {
F_68 ( V_6 ,
L_10 ,
V_143 , V_144 ) ;
return;
}
F_69 ( V_144 , & V_6 -> V_148 ) ;
F_70 ( V_6 -> V_43 , V_144 ) ;
}
static void F_71 ( struct V_3 * V_4 , int V_143 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
int V_144 = V_6 -> V_145 [ V_143 ] ;
if ( F_66 ( V_144 == V_146 ) )
return;
if ( F_72 ( & V_6 -> V_147 [ V_144 ] ) > 0 ) {
F_68 ( V_6 ,
L_11 ,
V_143 , V_144 ) ;
return;
}
F_73 ( V_144 , & V_6 -> V_148 ) ;
F_74 ( V_6 -> V_43 , V_144 ) ;
}
void F_75 ( struct V_5 * V_6 , bool V_149 )
{
if ( V_149 )
F_69 ( V_150 , & V_6 -> V_151 ) ;
else
F_73 ( V_150 , & V_6 -> V_151 ) ;
F_76 ( V_6 -> V_43 -> V_85 , F_77 ( V_6 ) ) ;
}
static void F_78 ( struct V_3 * V_4 , bool V_149 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
if ( V_149 )
F_69 ( V_152 , & V_6 -> V_151 ) ;
else
F_73 ( V_152 , & V_6 -> V_151 ) ;
F_76 ( V_6 -> V_43 -> V_85 , F_77 ( V_6 ) ) ;
}
static void F_79 ( struct V_3 * V_4 , struct V_153 * V_154 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
struct V_155 * V_156 ;
V_156 = F_80 ( V_154 ) ;
F_81 ( V_6 -> V_19 , V_156 -> V_157 [ 1 ] ) ;
F_82 ( V_6 -> V_43 , V_154 ) ;
}
static void F_83 ( struct V_123 * V_124 )
{
struct V_158 * V_159 ;
V_159 = F_53 ( V_124 , struct V_158 , V_160 ) ;
if ( F_84 ( V_159 -> V_53 ) )
F_85 ( V_159 -> V_53 , L_12 ) ;
F_40 ( V_159 ) ;
F_86 ( V_161 ) ;
}
static void F_87 ( struct V_5 * V_6 )
{
F_88 ( & V_6 -> V_91 ) ;
if ( F_89 ( V_162 , & V_6 -> V_151 ) ) {
struct V_158 * V_159 ;
F_27 ( V_6 ,
L_13 ) ;
if ( ! F_90 ( V_161 ) ) {
F_27 ( V_6 , L_14 ) ;
return;
}
V_159 = F_59 ( sizeof( * V_159 ) , V_139 ) ;
if ( ! V_159 ) {
F_86 ( V_161 ) ;
return;
}
V_159 -> V_53 = V_6 -> V_19 -> V_53 ;
F_21 ( & V_159 -> V_160 , F_83 ) ;
F_64 ( & V_159 -> V_160 ) ;
} else if ( V_6 -> V_163 == V_164 && V_6 -> V_54 ) {
switch ( V_6 -> V_165 ) {
case V_166 :
break;
case V_167 :
F_91 ( V_6 -> V_43 , true ) ;
break;
}
if ( V_6 -> V_54 > 0 )
V_6 -> V_54 -- ;
F_92 ( V_6 -> V_43 ) ;
}
}
static void F_93 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_94 ( V_6 ) ;
if ( ! V_6 -> V_54 )
F_95 ( V_6 ) ;
F_87 ( V_6 ) ;
}
static void F_96 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_12 ( 1 ) ;
F_87 ( V_6 ) ;
}
