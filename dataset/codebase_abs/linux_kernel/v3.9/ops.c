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
if ( V_6 -> V_11 ) {
V_7 = V_6 -> V_11 -> V_7 ;
V_8 = V_6 -> V_11 -> V_8 ;
V_9 = V_6 -> V_11 -> V_9 ;
} else {
V_7 = 0 ;
V_8 = 0 ;
V_9 = 0 ;
}
V_10 |= F_10 ( V_6 -> V_12 -> V_13 ) <<
V_14 ;
V_10 |= F_11 ( V_6 -> V_12 -> V_13 ) <<
V_15 ;
V_10 |= V_7 << V_16 ;
V_10 |= V_8 << V_17 ;
V_10 |= V_9 << V_18 ;
F_12 ( ( V_7 << V_16 ) &
~ V_19 ) ;
V_10 |= V_20 ;
V_10 |= V_21 ;
F_13 ( V_6 -> V_12 , V_22 ,
V_23 |
V_24 |
V_19 |
V_25 |
V_26 |
V_20 |
V_21 ,
V_10 ) ;
F_14 ( V_6 , L_4 , V_7 ,
V_8 , V_9 ) ;
F_15 ( V_6 -> V_12 , V_27 ,
V_28 ,
~ V_28 ) ;
}
static struct V_3 *
F_16 ( struct V_29 * V_12 , const struct V_30 * V_31 ,
const struct V_32 * V_33 , struct V_34 * V_35 )
{
struct V_36 * V_37 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_38 V_39 = {} ;
static const T_3 V_40 [] = {
V_41 ,
} ;
int V_42 , V_43 ;
switch ( V_31 -> V_44 ) {
case V_45 :
case V_46 :
case V_47 :
break;
default:
F_17 ( V_12 , L_5 ) ;
return NULL ;
}
V_37 = F_18 ( sizeof( struct V_3 ) +
sizeof( struct V_5 ) ,
& V_48 ) ;
if ( ! V_37 )
return NULL ;
V_4 = V_37 -> V_49 ;
V_4 -> V_50 = & V_2 ;
V_4 -> V_12 = V_12 ;
V_6 = F_9 ( V_4 ) ;
V_6 -> V_51 = V_12 -> V_51 ;
V_6 -> V_12 = V_12 ;
V_6 -> V_31 = V_31 ;
V_6 -> V_33 = V_33 ;
V_6 -> V_37 = V_37 ;
F_19 ( & V_6 -> V_52 ) ;
F_20 ( & V_6 -> V_53 ) ;
F_21 ( & V_6 -> V_54 ) ;
F_21 ( & V_6 -> V_55 ) ;
F_20 ( & V_6 -> V_56 ) ;
F_22 ( & V_6 -> V_57 , V_58 ) ;
F_22 ( & V_6 -> V_59 , V_60 ) ;
F_22 ( & V_6 -> V_61 , V_62 ) ;
F_23 ( V_6 -> V_37 , V_6 -> V_12 -> V_51 ) ;
V_39 . V_4 = V_4 ;
V_39 . V_40 = V_40 ;
V_39 . V_63 = F_24 ( V_40 ) ;
V_39 . V_64 = V_65 . V_66 ;
if ( V_31 -> V_44 == V_47 )
V_39 . V_67 = true ;
if ( ! V_65 . V_68 )
V_39 . V_69 = V_31 -> V_70 -> V_71 ;
else
V_39 . V_69 = V_72 ;
V_39 . V_73 = V_74 ;
V_39 . V_75 = V_76 ;
V_39 . V_77 = V_78 ;
snprintf ( V_6 -> V_37 -> V_79 -> V_80 ,
sizeof( V_6 -> V_37 -> V_79 -> V_80 ) ,
L_6 , V_33 -> V_80 ) ;
F_25 ( V_6 -> V_12 , & V_39 ) ;
V_12 -> V_81 = V_82 ;
V_12 -> V_83 = sizeof( struct V_84 ) ;
F_26 ( & V_6 -> V_85 ) ;
V_6 -> V_86 = F_27 ( V_12 ) ;
if ( ! V_6 -> V_86 ) {
F_17 ( V_6 , L_7 ) ;
goto V_87;
}
F_28 ( V_6 , L_8 ,
V_6 -> V_31 -> V_88 , V_6 -> V_12 -> V_13 ) ;
V_42 = F_29 ( V_6 -> V_12 ) ;
if ( V_42 )
goto V_87;
F_30 ( & V_6 -> V_52 ) ;
V_42 = F_31 ( V_6 , true ) ;
F_32 ( & V_6 -> V_52 ) ;
if ( V_42 && ! V_89 . V_90 ) {
F_17 ( V_6 , L_9 , V_42 ) ;
goto V_87;
}
if ( ! V_89 . V_90 )
F_33 ( V_6 -> V_12 , false ) ;
V_43 = sizeof( struct V_91 ) +
V_6 -> V_33 -> V_92 . V_93 +
( V_94 * sizeof( struct V_95 ) ) ;
V_6 -> V_96 = F_34 ( V_43 , V_97 ) ;
if ( ! V_6 -> V_96 )
goto V_87;
V_42 = F_35 ( V_6 ) ;
if ( V_42 )
goto V_87;
V_42 = F_36 ( V_6 , V_35 ) ;
if ( V_42 )
goto V_98;
return V_4 ;
V_98:
F_37 ( V_6 -> V_37 ) ;
V_87:
F_38 ( V_6 -> V_86 ) ;
F_39 ( V_6 -> V_96 ) ;
F_39 ( V_6 -> V_99 ) ;
F_33 ( V_12 , true ) ;
F_40 ( V_6 -> V_37 ) ;
return NULL ;
}
static void F_41 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
int V_100 ;
F_42 ( V_6 ) ;
F_37 ( V_6 -> V_37 ) ;
F_39 ( V_6 -> V_96 ) ;
F_33 ( V_6 -> V_12 , true ) ;
F_38 ( V_6 -> V_86 ) ;
V_6 -> V_86 = NULL ;
F_39 ( V_6 -> V_99 ) ;
F_43 ( V_6 -> V_11 ) ;
for ( V_100 = 0 ; V_100 < V_101 ; V_100 ++ )
F_39 ( V_6 -> V_102 [ V_100 ] . V_103 ) ;
F_40 ( V_6 -> V_37 ) ;
}
void F_44 ( struct V_5 * V_6 )
{
struct V_104 * V_105 , * V_106 ;
F_45 ( & V_6 -> V_53 ) ;
F_46 (entry, tmp, &mvm->async_handlers_list, list) {
F_47 ( & V_105 -> V_107 ) ;
F_48 ( & V_105 -> V_108 ) ;
F_39 ( V_105 ) ;
}
F_49 ( & V_6 -> V_53 ) ;
}
static void V_58 ( struct V_109 * V_110 )
{
struct V_5 * V_6 =
F_50 ( V_110 , struct V_5 , V_57 ) ;
struct V_104 * V_105 , * V_106 ;
struct V_111 V_112 ;
F_21 ( & V_112 ) ;
F_30 ( & V_6 -> V_52 ) ;
F_45 ( & V_6 -> V_53 ) ;
F_51 ( & V_6 -> V_55 , & V_112 ) ;
F_49 ( & V_6 -> V_53 ) ;
F_46 (entry, tmp, &local_list, list) {
if ( V_105 -> V_113 ( V_6 , & V_105 -> V_107 , NULL ) )
F_52 ( V_6 ,
L_10 ) ;
F_47 ( & V_105 -> V_107 ) ;
F_48 ( & V_105 -> V_108 ) ;
F_39 ( V_105 ) ;
}
F_32 ( & V_6 -> V_52 ) ;
}
static int F_53 ( struct V_3 * V_4 ,
struct V_114 * V_107 ,
struct V_115 * V_116 )
{
struct V_117 * V_118 = F_54 ( V_107 ) ;
struct V_5 * V_6 = F_9 ( V_4 ) ;
T_3 V_100 ;
F_55 ( & V_6 -> V_85 , V_118 ) ;
for ( V_100 = 0 ; V_100 < F_24 ( V_119 ) ; V_100 ++ ) {
const struct V_120 * V_121 = & V_119 [ V_100 ] ;
struct V_104 * V_105 ;
if ( V_121 -> V_122 != V_118 -> V_123 . V_116 )
continue;
if ( ! V_121 -> V_124 )
return V_121 -> V_113 ( V_6 , V_107 , V_116 ) ;
V_105 = F_56 ( sizeof( * V_105 ) , V_125 ) ;
if ( ! V_105 )
return 0 ;
V_105 -> V_107 . V_126 = F_57 ( V_107 ) ;
V_105 -> V_107 . V_127 = V_107 -> V_127 ;
V_105 -> V_107 . V_128 = V_107 -> V_128 ;
V_105 -> V_113 = V_121 -> V_113 ;
F_58 ( & V_6 -> V_53 ) ;
F_59 ( & V_105 -> V_108 , & V_6 -> V_55 ) ;
F_60 ( & V_6 -> V_53 ) ;
F_61 ( & V_6 -> V_57 ) ;
break;
}
return 0 ;
}
static void F_62 ( struct V_3 * V_4 , int V_129 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
int V_130 = V_6 -> V_131 [ V_129 ] ;
if ( F_63 ( V_130 == V_132 ) )
return;
if ( F_64 ( & V_6 -> V_133 [ V_130 ] ) > 1 ) {
F_65 ( V_6 ,
L_11 ,
V_129 , V_130 ) ;
return;
}
F_66 ( V_130 , & V_6 -> V_134 ) ;
F_67 ( V_6 -> V_37 , V_130 ) ;
}
static void F_68 ( struct V_3 * V_4 , int V_129 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
int V_130 = V_6 -> V_131 [ V_129 ] ;
if ( F_63 ( V_130 == V_132 ) )
return;
if ( F_69 ( & V_6 -> V_133 [ V_130 ] ) > 0 ) {
F_65 ( V_6 ,
L_12 ,
V_129 , V_130 ) ;
return;
}
F_70 ( V_130 , & V_6 -> V_134 ) ;
F_71 ( V_6 -> V_37 , V_130 ) ;
}
static void F_72 ( struct V_3 * V_4 , bool V_135 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
if ( V_135 )
F_66 ( V_136 , & V_6 -> V_137 ) ;
else
F_70 ( V_136 , & V_6 -> V_137 ) ;
F_73 ( V_6 -> V_37 -> V_79 , V_135 ) ;
}
static void F_74 ( struct V_3 * V_4 , struct V_138 * V_139 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
struct V_140 * V_141 ;
V_141 = F_75 ( V_139 ) ;
F_76 ( V_6 -> V_12 , V_141 -> V_142 [ 1 ] ) ;
F_77 ( V_6 -> V_37 , V_139 ) ;
}
static void F_78 ( struct V_5 * V_6 )
{
F_79 ( & V_6 -> V_85 ) ;
if ( F_80 ( V_143 , & V_6 -> V_137 ) ) {
F_17 ( V_6 , L_13 ) ;
} else if ( V_6 -> V_144 == V_145 &&
V_65 . V_146 ) {
switch ( V_6 -> V_147 ) {
case V_148 :
break;
case V_149 :
F_81 ( V_6 -> V_37 , true ) ;
break;
}
F_82 ( V_6 -> V_37 ) ;
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
