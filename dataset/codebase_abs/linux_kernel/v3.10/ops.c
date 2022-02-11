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
F_30 ( & V_6 -> V_54 ) ;
V_48 = F_31 ( V_6 , true ) ;
F_32 ( & V_6 -> V_54 ) ;
if ( V_48 && ! V_94 . V_95 ) {
F_27 ( V_6 , L_8 , V_48 ) ;
goto V_92;
}
if ( ! V_94 . V_95 )
F_33 ( V_6 -> V_19 , false ) ;
V_49 = sizeof( struct V_96 ) +
V_6 -> V_11 -> V_69 . V_97 +
( V_98 * sizeof( struct V_99 ) ) ;
V_6 -> V_100 = F_34 ( V_49 , V_101 ) ;
if ( ! V_6 -> V_100 )
goto V_92;
V_48 = F_35 ( V_6 ) ;
if ( V_48 )
goto V_92;
V_48 = F_36 ( V_6 , V_41 ) ;
if ( V_48 )
goto V_102;
return V_4 ;
V_102:
F_37 ( V_6 -> V_43 ) ;
V_92:
F_38 ( V_6 -> V_91 ) ;
F_39 ( V_6 -> V_100 ) ;
F_33 ( V_19 , true ) ;
F_40 ( V_6 -> V_43 ) ;
return NULL ;
}
static void F_41 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
int V_103 ;
F_42 ( V_6 ) ;
F_37 ( V_6 -> V_43 ) ;
F_39 ( V_6 -> V_100 ) ;
F_33 ( V_6 -> V_19 , true ) ;
F_38 ( V_6 -> V_91 ) ;
V_6 -> V_91 = NULL ;
F_43 ( V_6 -> V_104 ) ;
for ( V_103 = 0 ; V_103 < V_105 ; V_103 ++ )
F_39 ( V_6 -> V_106 [ V_103 ] . V_107 ) ;
F_40 ( V_6 -> V_43 ) ;
}
void F_44 ( struct V_5 * V_6 )
{
struct V_108 * V_109 , * V_110 ;
F_45 ( & V_6 -> V_55 ) ;
F_46 (entry, tmp, &mvm->async_handlers_list, list) {
F_47 ( & V_109 -> V_111 ) ;
F_48 ( & V_109 -> V_112 ) ;
F_39 ( V_109 ) ;
}
F_49 ( & V_6 -> V_55 ) ;
}
static void V_60 ( struct V_113 * V_114 )
{
struct V_5 * V_6 =
F_50 ( V_114 , struct V_5 , V_59 ) ;
struct V_108 * V_109 , * V_110 ;
struct V_115 V_116 ;
F_20 ( & V_116 ) ;
F_30 ( & V_6 -> V_54 ) ;
F_45 ( & V_6 -> V_55 ) ;
F_51 ( & V_6 -> V_57 , & V_116 ) ;
F_49 ( & V_6 -> V_55 ) ;
F_46 (entry, tmp, &local_list, list) {
if ( V_109 -> V_117 ( V_6 , & V_109 -> V_111 , NULL ) )
F_52 ( V_6 ,
L_9 ) ;
F_47 ( & V_109 -> V_111 ) ;
F_48 ( & V_109 -> V_112 ) ;
F_39 ( V_109 ) ;
}
F_32 ( & V_6 -> V_54 ) ;
}
static int F_53 ( struct V_3 * V_4 ,
struct V_118 * V_111 ,
struct V_119 * V_120 )
{
struct V_121 * V_122 = F_54 ( V_111 ) ;
struct V_5 * V_6 = F_9 ( V_4 ) ;
T_3 V_103 ;
F_55 ( & V_6 -> V_90 , V_122 ) ;
for ( V_103 = 0 ; V_103 < F_23 ( V_123 ) ; V_103 ++ ) {
const struct V_124 * V_125 = & V_123 [ V_103 ] ;
struct V_108 * V_109 ;
if ( V_125 -> V_126 != V_122 -> V_127 . V_120 )
continue;
if ( ! V_125 -> V_128 )
return V_125 -> V_117 ( V_6 , V_111 , V_120 ) ;
V_109 = F_56 ( sizeof( * V_109 ) , V_129 ) ;
if ( ! V_109 )
return 0 ;
V_109 -> V_111 . V_130 = F_57 ( V_111 ) ;
V_109 -> V_111 . V_131 = V_111 -> V_131 ;
V_109 -> V_111 . V_132 = V_111 -> V_132 ;
V_109 -> V_117 = V_125 -> V_117 ;
F_58 ( & V_6 -> V_55 ) ;
F_59 ( & V_109 -> V_112 , & V_6 -> V_57 ) ;
F_60 ( & V_6 -> V_55 ) ;
F_61 ( & V_6 -> V_59 ) ;
break;
}
return 0 ;
}
static void F_62 ( struct V_3 * V_4 , int V_133 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
int V_134 = V_6 -> V_135 [ V_133 ] ;
if ( F_63 ( V_134 == V_136 ) )
return;
if ( F_64 ( & V_6 -> V_137 [ V_134 ] ) > 1 ) {
F_65 ( V_6 ,
L_10 ,
V_133 , V_134 ) ;
return;
}
F_66 ( V_134 , & V_6 -> V_138 ) ;
F_67 ( V_6 -> V_43 , V_134 ) ;
}
static void F_68 ( struct V_3 * V_4 , int V_133 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
int V_134 = V_6 -> V_135 [ V_133 ] ;
if ( F_63 ( V_134 == V_136 ) )
return;
if ( F_69 ( & V_6 -> V_137 [ V_134 ] ) > 0 ) {
F_65 ( V_6 ,
L_11 ,
V_133 , V_134 ) ;
return;
}
F_70 ( V_134 , & V_6 -> V_138 ) ;
F_71 ( V_6 -> V_43 , V_134 ) ;
}
static void F_72 ( struct V_3 * V_4 , bool V_139 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
if ( V_139 )
F_66 ( V_140 , & V_6 -> V_141 ) ;
else
F_70 ( V_140 , & V_6 -> V_141 ) ;
F_73 ( V_6 -> V_43 -> V_84 , V_139 ) ;
}
static void F_74 ( struct V_3 * V_4 , struct V_142 * V_143 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
struct V_144 * V_145 ;
V_145 = F_75 ( V_143 ) ;
F_76 ( V_6 -> V_19 , V_145 -> V_146 [ 1 ] ) ;
F_77 ( V_6 -> V_43 , V_143 ) ;
}
static void F_78 ( struct V_5 * V_6 )
{
F_79 ( & V_6 -> V_90 ) ;
if ( F_80 ( V_147 , & V_6 -> V_141 ) ) {
F_27 ( V_6 , L_12 ) ;
} else if ( V_6 -> V_148 == V_149 &&
V_67 . V_150 ) {
switch ( V_6 -> V_151 ) {
case V_152 :
break;
case V_153 :
F_81 ( V_6 -> V_43 , true ) ;
break;
}
F_82 ( V_6 -> V_43 ) ;
}
}
static void F_83 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_84 ( V_6 ) ;
F_78 ( V_6 ) ;
}
static void F_85 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
F_12 ( 1 ) ;
F_78 ( V_6 ) ;
}
