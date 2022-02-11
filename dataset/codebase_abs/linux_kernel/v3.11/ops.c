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
F_18 ( & V_6 -> V_54 ) ;
F_19 ( & V_6 -> V_55 ) ;
F_20 ( & V_6 -> V_56 ) ;
F_20 ( & V_6 -> V_57 ) ;
F_19 ( & V_6 -> V_58 ) ;
F_21 ( & V_6 -> V_59 , V_60 ) ;
F_21 ( & V_6 -> V_61 , V_62 ) ;
F_21 ( & V_6 -> V_63 , V_64 ) ;
F_22 ( V_6 -> V_43 , V_6 -> V_19 -> V_53 ) ;
V_45 . V_4 = V_4 ;
V_45 . V_46 = V_46 ;
V_45 . V_65 = F_23 ( V_46 ) ;
V_45 . V_66 = V_67 . V_68 ;
if ( V_6 -> V_11 -> V_69 . V_70 & V_71 )
V_45 . V_72 = true ;
if ( ! V_67 . V_73 )
V_45 . V_74 = V_38 -> V_75 -> V_76 ;
else
V_45 . V_74 = V_77 ;
V_45 . V_78 = V_79 ;
V_45 . V_80 = V_81 ;
V_45 . V_82 = V_83 ;
snprintf ( V_6 -> V_43 -> V_84 -> V_85 ,
sizeof( V_6 -> V_43 -> V_84 -> V_85 ) ,
L_5 , V_11 -> V_85 ) ;
F_24 ( V_6 -> V_19 , & V_45 ) ;
V_19 -> V_86 = V_87 ;
V_19 -> V_88 = sizeof( struct V_89 ) ;
F_25 ( & V_6 -> V_90 ) ;
V_6 -> V_91 = F_26 ( V_19 ) ;
if ( ! V_6 -> V_91 ) {
F_27 ( V_6 , L_6 ) ;
goto V_92;
}
F_28 ( V_6 , L_7 ,
V_6 -> V_38 -> V_93 , V_6 -> V_19 -> V_20 ) ;
V_48 = F_29 ( V_6 -> V_19 ) ;
if ( V_48 )
goto V_92;
F_30 ( V_6 ) ;
F_31 ( & V_6 -> V_54 ) ;
V_48 = F_32 ( V_6 , true ) ;
F_33 ( & V_6 -> V_54 ) ;
if ( V_48 < 0 && ! V_94 . V_95 ) {
F_27 ( V_6 , L_8 , V_48 ) ;
goto V_92;
}
if ( ! V_94 . V_95 )
F_34 ( V_6 -> V_19 , false ) ;
V_49 = sizeof( struct V_96 ) +
V_6 -> V_11 -> V_69 . V_97 +
( V_98 * sizeof( struct V_99 ) ) ;
V_6 -> V_100 = F_35 ( V_49 , V_101 ) ;
if ( ! V_6 -> V_100 )
goto V_92;
V_48 = F_36 ( V_6 ) ;
if ( V_48 )
goto V_92;
V_48 = F_37 ( V_6 , V_41 ) ;
if ( V_48 )
goto V_102;
return V_4 ;
V_102:
F_38 ( V_6 -> V_43 ) ;
V_92:
F_39 ( V_6 -> V_91 ) ;
F_40 ( V_6 -> V_100 ) ;
F_34 ( V_19 , true ) ;
F_41 ( V_6 -> V_43 ) ;
return NULL ;
}
static void F_42 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
int V_103 ;
F_43 ( V_6 ) ;
F_44 ( V_6 ) ;
F_38 ( V_6 -> V_43 ) ;
F_40 ( V_6 -> V_100 ) ;
#if F_45 ( V_104 ) && F_45 ( V_105 )
F_40 ( V_6 -> V_106 ) ;
#endif
F_34 ( V_6 -> V_19 , true ) ;
F_39 ( V_6 -> V_91 ) ;
V_6 -> V_91 = NULL ;
F_46 ( V_6 -> V_107 ) ;
for ( V_103 = 0 ; V_103 < V_108 ; V_103 ++ )
F_40 ( V_6 -> V_109 [ V_103 ] . V_110 ) ;
F_41 ( V_6 -> V_43 ) ;
}
void F_47 ( struct V_5 * V_6 )
{
struct V_111 * V_112 , * V_113 ;
F_48 ( & V_6 -> V_55 ) ;
F_49 (entry, tmp, &mvm->async_handlers_list, list) {
F_50 ( & V_112 -> V_114 ) ;
F_51 ( & V_112 -> V_115 ) ;
F_40 ( V_112 ) ;
}
F_52 ( & V_6 -> V_55 ) ;
}
static void V_60 ( struct V_116 * V_117 )
{
struct V_5 * V_6 =
F_53 ( V_117 , struct V_5 , V_59 ) ;
struct V_111 * V_112 , * V_113 ;
struct V_118 V_119 ;
F_20 ( & V_119 ) ;
F_31 ( & V_6 -> V_54 ) ;
F_48 ( & V_6 -> V_55 ) ;
F_54 ( & V_6 -> V_57 , & V_119 ) ;
F_52 ( & V_6 -> V_55 ) ;
F_49 (entry, tmp, &local_list, list) {
if ( V_112 -> V_120 ( V_6 , & V_112 -> V_114 , NULL ) )
F_55 ( V_6 ,
L_9 ) ;
F_50 ( & V_112 -> V_114 ) ;
F_51 ( & V_112 -> V_115 ) ;
F_40 ( V_112 ) ;
}
F_33 ( & V_6 -> V_54 ) ;
}
static int F_56 ( struct V_3 * V_4 ,
struct V_121 * V_114 ,
struct V_122 * V_123 )
{
struct V_124 * V_125 = F_57 ( V_114 ) ;
struct V_5 * V_6 = F_9 ( V_4 ) ;
T_3 V_103 ;
F_58 ( & V_6 -> V_90 , V_125 ) ;
for ( V_103 = 0 ; V_103 < F_23 ( V_126 ) ; V_103 ++ ) {
const struct V_127 * V_128 = & V_126 [ V_103 ] ;
struct V_111 * V_112 ;
if ( V_128 -> V_129 != V_125 -> V_130 . V_123 )
continue;
if ( ! V_128 -> V_131 )
return V_128 -> V_120 ( V_6 , V_114 , V_123 ) ;
V_112 = F_59 ( sizeof( * V_112 ) , V_132 ) ;
if ( ! V_112 )
return 0 ;
V_112 -> V_114 . V_133 = F_60 ( V_114 ) ;
V_112 -> V_114 . V_134 = V_114 -> V_134 ;
V_112 -> V_114 . V_135 = V_114 -> V_135 ;
V_112 -> V_120 = V_128 -> V_120 ;
F_61 ( & V_6 -> V_55 ) ;
F_62 ( & V_112 -> V_115 , & V_6 -> V_57 ) ;
F_63 ( & V_6 -> V_55 ) ;
F_64 ( & V_6 -> V_59 ) ;
break;
}
return 0 ;
}
static void F_65 ( struct V_3 * V_4 , int V_136 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
int V_137 = V_6 -> V_138 [ V_136 ] ;
if ( F_66 ( V_137 == V_139 ) )
return;
if ( F_67 ( & V_6 -> V_140 [ V_137 ] ) > 1 ) {
F_68 ( V_6 ,
L_10 ,
V_136 , V_137 ) ;
return;
}
F_69 ( V_137 , & V_6 -> V_141 ) ;
F_70 ( V_6 -> V_43 , V_137 ) ;
}
static void F_71 ( struct V_3 * V_4 , int V_136 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
int V_137 = V_6 -> V_138 [ V_136 ] ;
if ( F_66 ( V_137 == V_139 ) )
return;
if ( F_72 ( & V_6 -> V_140 [ V_137 ] ) > 0 ) {
F_68 ( V_6 ,
L_11 ,
V_136 , V_137 ) ;
return;
}
F_73 ( V_137 , & V_6 -> V_141 ) ;
F_74 ( V_6 -> V_43 , V_137 ) ;
}
void F_75 ( struct V_5 * V_6 , bool V_142 )
{
if ( V_142 )
F_69 ( V_143 , & V_6 -> V_144 ) ;
else
F_73 ( V_143 , & V_6 -> V_144 ) ;
F_76 ( V_6 -> V_43 -> V_84 , F_77 ( V_6 ) ) ;
}
static void F_78 ( struct V_3 * V_4 , bool V_142 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
if ( V_142 )
F_69 ( V_145 , & V_6 -> V_144 ) ;
else
F_73 ( V_145 , & V_6 -> V_144 ) ;
F_76 ( V_6 -> V_43 -> V_84 , F_77 ( V_6 ) ) ;
}
static void F_79 ( struct V_3 * V_4 , struct V_146 * V_147 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
struct V_148 * V_149 ;
V_149 = F_80 ( V_147 ) ;
F_81 ( V_6 -> V_19 , V_149 -> V_150 [ 1 ] ) ;
F_82 ( V_6 -> V_43 , V_147 ) ;
}
static void F_83 ( struct V_5 * V_6 )
{
F_84 ( & V_6 -> V_90 ) ;
if ( F_85 ( V_151 , & V_6 -> V_144 ) ) {
F_27 ( V_6 , L_12 ) ;
} else if ( V_6 -> V_152 == V_153 &&
V_67 . V_154 ) {
switch ( V_6 -> V_155 ) {
case V_156 :
break;
case V_157 :
F_86 ( V_6 -> V_43 , true ) ;
break;
}
F_87 ( V_6 -> V_43 ) ;
}
}
static void F_88 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_89 ( V_6 ) ;
F_83 ( V_6 ) ;
}
static void F_90 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_12 ( 1 ) ;
F_83 ( V_6 ) ;
}
