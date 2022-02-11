static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
unsigned int V_7 ;
int V_8 ;
V_6 = F_2 ( sizeof *V_6 , V_9 ) ;
if ( V_6 == NULL )
return - V_10 ;
V_6 -> V_11 = V_4 -> V_11 ;
memcpy ( V_6 -> V_12 , V_4 -> V_12 , sizeof V_6 -> V_12 ) ;
memcpy ( V_6 -> V_13 , V_4 -> V_13 , sizeof V_6 -> V_13 ) ;
V_6 -> V_14 = V_4 -> V_14 ;
V_6 -> V_7 = V_4 -> V_7 ;
V_6 -> V_15 = V_4 -> V_15 ;
V_6 -> V_16 = V_4 -> V_16 ;
V_6 -> V_17 = V_4 -> V_17 ;
switch ( V_4 -> V_16 ) {
case V_18 :
case V_19 :
case V_20 :
break;
case V_21 :
if ( V_4 -> V_22 == 0 ||
V_4 -> V_22 > V_23 ) {
V_8 = - V_24 ;
goto V_25;
}
V_7 = V_4 -> V_22 * sizeof( * V_6 -> V_26 ) ;
V_6 -> V_26 = F_3 ( V_7 , V_9 ) ;
if ( V_6 -> V_26 == NULL ) {
V_8 = - V_10 ;
goto V_25;
}
if ( F_4 ( V_6 -> V_26 , V_4 -> V_26 , V_7 ) ) {
V_8 = - V_27 ;
goto V_25;
}
V_6 -> V_22 = V_4 -> V_22 ;
break;
default:
F_5 ( V_28 , L_1
L_2 , V_4 -> V_16 ) ;
V_8 = - V_29 ;
goto V_25;
}
V_8 = F_6 ( V_2 , V_6 ) ;
V_25:
F_7 ( V_6 -> V_26 ) ;
F_7 ( V_6 ) ;
return V_8 ;
}
static T_1 F_8 ( struct V_30 * V_31 , T_1 V_32 )
{
unsigned int V_33 ;
if ( V_31 -> V_34 ) {
T_1 V_35 = - 1 , V_36 ;
for ( V_33 = 0 ; V_33 < V_31 -> V_34 ; ++ V_33 ) {
V_36 = V_32 > V_31 -> V_37 [ V_33 ]
? V_32 - V_31 -> V_37 [ V_33 ]
: V_31 -> V_37 [ V_33 ] - V_32 ;
if ( V_36 > V_35 )
break;
V_35 = V_36 ;
}
V_32 = V_31 -> V_37 [ V_33 - 1 ] ;
} else {
const T_1 V_38 = V_31 -> V_37 [ 0 ] ;
const T_1 V_39 = V_31 -> V_37 [ 1 ] ;
const T_1 V_40 = V_31 -> V_37 [ 2 ] ;
V_32 = V_38 + ( V_32 - V_38 + V_40 / 2 ) / V_40 * V_40 ;
if ( V_32 > V_39 )
V_32 = V_39 ;
}
return V_32 ;
}
static int F_9 ( struct V_41 * V_42 ,
struct V_43 * V_44 , struct V_45 * V_46 ,
struct V_47 * * V_47 , struct V_30 * * V_30 )
{
struct V_47 * V_48 = NULL ;
struct V_30 * V_31 = NULL ;
T_2 V_49 , V_50 ;
unsigned int V_51 , V_52 ;
unsigned int V_33 ;
T_1 V_32 ;
int V_8 = 0 ;
T_3 * V_53 ;
if ( V_44 -> type != V_42 -> type )
return - V_24 ;
V_53 = ( T_3 * ) & V_44 -> V_44 . V_54 . V_55 ;
F_5 ( V_56 , L_3 ,
V_44 -> V_44 . V_54 . V_55 ,
V_53 [ 0 ] , V_53 [ 1 ] , V_53 [ 2 ] , V_53 [ 3 ] ,
V_44 -> V_44 . V_54 . V_57 , V_44 -> V_44 . V_54 . V_58 ) ;
for ( V_33 = 0 ; V_33 < V_42 -> V_59 ; ++ V_33 ) {
V_48 = & V_42 -> V_48 [ V_33 ] ;
if ( V_48 -> V_53 == V_44 -> V_44 . V_54 . V_55 )
break;
}
if ( V_33 == V_42 -> V_59 ) {
V_48 = V_42 -> V_60 ;
V_44 -> V_44 . V_54 . V_55 = V_48 -> V_53 ;
}
V_49 = V_44 -> V_44 . V_54 . V_57 ;
V_50 = V_44 -> V_44 . V_54 . V_58 ;
V_52 = ( unsigned int ) - 1 ;
for ( V_33 = 0 ; V_33 < V_48 -> V_61 ; ++ V_33 ) {
T_2 V_62 = V_48 -> V_31 [ V_33 ] . V_63 ;
T_2 V_64 = V_48 -> V_31 [ V_33 ] . V_65 ;
V_51 = V_38 ( V_62 , V_49 ) * V_38 ( V_64 , V_50 ) ;
V_51 = V_62 * V_64 + V_49 * V_50 - 2 * V_51 ;
if ( V_51 < V_52 ) {
V_52 = V_51 ;
V_31 = & V_48 -> V_31 [ V_33 ] ;
}
if ( V_52 == 0 )
break;
}
if ( V_31 == NULL ) {
F_5 ( V_56 , L_4 ,
V_44 -> V_44 . V_54 . V_57 , V_44 -> V_44 . V_54 . V_58 ) ;
return - V_24 ;
}
V_32 = V_31 -> V_66 ;
F_5 ( V_56 , L_5
L_6 , V_32 / 10 , V_32 % 10 , 10000000 / V_32 ,
( 100000000 / V_32 ) % 10 ) ;
memset ( V_46 , 0 , sizeof *V_46 ) ;
V_46 -> V_67 = 1 ;
V_46 -> V_68 = V_48 -> V_69 ;
V_46 -> V_70 = V_31 -> V_70 ;
V_46 -> V_37 = F_8 ( V_31 , V_32 ) ;
F_10 ( & V_42 -> V_71 ) ;
if ( V_42 -> V_72 -> V_73 & V_74 )
V_46 -> V_75 =
V_42 -> V_76 . V_75 ;
V_8 = F_11 ( V_42 , V_46 ) ;
F_12 ( & V_42 -> V_71 ) ;
if ( V_8 < 0 )
goto V_25;
V_44 -> V_44 . V_54 . V_57 = V_31 -> V_63 ;
V_44 -> V_44 . V_54 . V_58 = V_31 -> V_65 ;
V_44 -> V_44 . V_54 . V_77 = V_78 ;
V_44 -> V_44 . V_54 . V_79 = V_48 -> V_80 * V_31 -> V_63 / 8 ;
V_44 -> V_44 . V_54 . V_81 = V_46 -> V_75 ;
V_44 -> V_44 . V_54 . V_82 = V_48 -> V_82 ;
V_44 -> V_44 . V_54 . V_83 = 0 ;
if ( V_47 != NULL )
* V_47 = V_48 ;
if ( V_30 != NULL )
* V_30 = V_31 ;
V_25:
return V_8 ;
}
static int F_13 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_47 * V_48 ;
struct V_30 * V_31 ;
int V_8 = 0 ;
if ( V_44 -> type != V_42 -> type )
return - V_24 ;
F_10 ( & V_42 -> V_71 ) ;
V_48 = V_42 -> V_84 ;
V_31 = V_42 -> V_85 ;
if ( V_48 == NULL || V_31 == NULL ) {
V_8 = - V_24 ;
goto V_25;
}
V_44 -> V_44 . V_54 . V_55 = V_48 -> V_53 ;
V_44 -> V_44 . V_54 . V_57 = V_31 -> V_63 ;
V_44 -> V_44 . V_54 . V_58 = V_31 -> V_65 ;
V_44 -> V_44 . V_54 . V_77 = V_78 ;
V_44 -> V_44 . V_54 . V_79 = V_48 -> V_80 * V_31 -> V_63 / 8 ;
V_44 -> V_44 . V_54 . V_81 = V_42 -> V_76 . V_75 ;
V_44 -> V_44 . V_54 . V_82 = V_48 -> V_82 ;
V_44 -> V_44 . V_54 . V_83 = 0 ;
V_25:
F_12 ( & V_42 -> V_71 ) ;
return V_8 ;
}
static int F_14 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_45 V_46 ;
struct V_47 * V_48 ;
struct V_30 * V_31 ;
int V_8 ;
if ( V_44 -> type != V_42 -> type )
return - V_24 ;
V_8 = F_9 ( V_42 , V_44 , & V_46 , & V_48 , & V_31 ) ;
if ( V_8 < 0 )
return V_8 ;
F_10 ( & V_42 -> V_71 ) ;
if ( F_15 ( & V_42 -> V_86 ) ) {
V_8 = - V_87 ;
goto V_25;
}
V_42 -> V_76 = V_46 ;
V_42 -> V_84 = V_48 ;
V_42 -> V_85 = V_31 ;
V_25:
F_12 ( & V_42 -> V_71 ) ;
return V_8 ;
}
static int F_16 ( struct V_41 * V_42 ,
struct V_88 * V_89 )
{
T_4 V_90 , V_91 ;
if ( V_89 -> type != V_42 -> type )
return - V_24 ;
F_10 ( & V_42 -> V_71 ) ;
V_90 = V_42 -> V_76 . V_37 ;
F_12 ( & V_42 -> V_71 ) ;
V_91 = 10000000 ;
F_17 ( & V_90 , & V_91 , 8 , 333 ) ;
memset ( V_89 , 0 , sizeof *V_89 ) ;
V_89 -> type = V_42 -> type ;
if ( V_42 -> type == V_92 ) {
V_89 -> V_89 . V_93 . V_94 = V_95 ;
V_89 -> V_89 . V_93 . V_96 = 0 ;
V_89 -> V_89 . V_93 . V_97 . V_90 = V_90 ;
V_89 -> V_89 . V_93 . V_97 . V_91 = V_91 ;
V_89 -> V_89 . V_93 . V_98 = 0 ;
V_89 -> V_89 . V_93 . V_99 = 0 ;
} else {
V_89 -> V_89 . V_100 . V_94 = V_95 ;
V_89 -> V_89 . V_100 . V_101 = 0 ;
V_89 -> V_89 . V_100 . V_97 . V_90 = V_90 ;
V_89 -> V_89 . V_100 . V_97 . V_91 = V_91 ;
}
return 0 ;
}
static int F_18 ( struct V_41 * V_42 ,
struct V_88 * V_89 )
{
struct V_45 V_46 ;
struct V_102 V_97 ;
T_4 V_32 ;
int V_8 ;
if ( V_89 -> type != V_42 -> type )
return - V_24 ;
if ( V_89 -> type == V_92 )
V_97 = V_89 -> V_89 . V_93 . V_97 ;
else
V_97 = V_89 -> V_89 . V_100 . V_97 ;
V_32 = F_19 ( V_97 . V_90 ,
V_97 . V_91 ) ;
F_5 ( V_56 , L_7 ,
V_97 . V_90 , V_97 . V_91 , V_32 ) ;
F_10 ( & V_42 -> V_71 ) ;
if ( F_20 ( & V_42 -> V_86 ) ) {
F_12 ( & V_42 -> V_71 ) ;
return - V_87 ;
}
V_46 = V_42 -> V_76 ;
V_46 . V_37 =
F_8 ( V_42 -> V_85 , V_32 ) ;
V_8 = F_11 ( V_42 , & V_46 ) ;
if ( V_8 < 0 ) {
F_12 ( & V_42 -> V_71 ) ;
return V_8 ;
}
V_42 -> V_76 = V_46 ;
F_12 ( & V_42 -> V_71 ) ;
V_97 . V_90 = V_46 . V_37 ;
V_97 . V_91 = 10000000 ;
F_17 ( & V_97 . V_90 ,
& V_97 . V_91 , 8 , 333 ) ;
if ( V_89 -> type == V_92 )
V_89 -> V_89 . V_93 . V_97 = V_97 ;
else
V_89 -> V_89 . V_100 . V_97 = V_97 ;
return 0 ;
}
static int F_21 ( struct V_103 * V_104 )
{
if ( V_104 -> V_105 == V_106 )
return 0 ;
if ( F_22 ( & V_104 -> V_42 -> V_107 ) != 1 ) {
F_23 ( & V_104 -> V_42 -> V_107 ) ;
return - V_87 ;
}
V_104 -> V_105 = V_106 ;
return 0 ;
}
static void F_24 ( struct V_103 * V_104 )
{
if ( V_104 -> V_105 == V_106 )
F_23 ( & V_104 -> V_42 -> V_107 ) ;
V_104 -> V_105 = V_108 ;
}
static int F_25 ( struct V_103 * V_104 )
{
return V_104 -> V_105 == V_106 ;
}
static int F_26 ( struct V_109 * V_109 )
{
struct V_41 * V_42 ;
struct V_103 * V_104 ;
int V_8 = 0 ;
F_5 ( V_110 , L_8 ) ;
V_42 = F_27 ( V_109 ) ;
V_8 = F_28 ( V_42 -> V_72 -> V_111 ) ;
if ( V_8 < 0 )
return V_8 ;
V_104 = F_2 ( sizeof *V_104 , V_9 ) ;
if ( V_104 == NULL ) {
F_29 ( V_42 -> V_72 -> V_111 ) ;
return - V_10 ;
}
F_10 ( & V_42 -> V_72 -> V_112 ) ;
if ( V_42 -> V_72 -> V_113 == 0 ) {
V_8 = F_30 ( V_42 -> V_72 , V_9 ) ;
if ( V_8 < 0 ) {
F_12 ( & V_42 -> V_72 -> V_112 ) ;
F_29 ( V_42 -> V_72 -> V_111 ) ;
F_7 ( V_104 ) ;
return V_8 ;
}
}
V_42 -> V_72 -> V_113 ++ ;
F_12 ( & V_42 -> V_72 -> V_112 ) ;
F_31 ( & V_104 -> V_114 , & V_42 -> V_115 ) ;
F_32 ( & V_104 -> V_114 ) ;
V_104 -> V_2 = V_42 -> V_2 ;
V_104 -> V_42 = V_42 ;
V_104 -> V_105 = V_108 ;
V_109 -> V_116 = V_104 ;
return 0 ;
}
static int F_33 ( struct V_109 * V_109 )
{
struct V_103 * V_104 = V_109 -> V_116 ;
struct V_41 * V_42 = V_104 -> V_42 ;
F_5 ( V_110 , L_9 ) ;
if ( F_25 ( V_104 ) )
F_34 ( & V_42 -> V_86 ) ;
F_24 ( V_104 ) ;
F_35 ( & V_104 -> V_114 ) ;
F_36 ( & V_104 -> V_114 ) ;
F_7 ( V_104 ) ;
V_109 -> V_116 = NULL ;
F_10 ( & V_42 -> V_72 -> V_112 ) ;
if ( -- V_42 -> V_72 -> V_113 == 0 )
F_37 ( V_42 -> V_72 ) ;
F_12 ( & V_42 -> V_72 -> V_112 ) ;
F_29 ( V_42 -> V_72 -> V_111 ) ;
return 0 ;
}
static int F_38 ( struct V_109 * V_109 , void * V_117 ,
struct V_118 * V_119 )
{
struct V_120 * V_115 = F_39 ( V_109 ) ;
struct V_103 * V_104 = V_109 -> V_116 ;
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_41 * V_42 = V_104 -> V_42 ;
F_40 ( V_119 -> V_121 , L_10 , sizeof( V_119 -> V_121 ) ) ;
F_40 ( V_119 -> V_122 , V_115 -> V_12 , sizeof( V_119 -> V_122 ) ) ;
F_41 ( V_42 -> V_72 -> V_123 , V_119 -> V_124 , sizeof( V_119 -> V_124 ) ) ;
V_119 -> V_125 = V_126 | V_127
| V_2 -> V_128 ;
if ( V_42 -> type == V_92 )
V_119 -> V_129 = V_130 | V_127 ;
else
V_119 -> V_129 = V_131 | V_127 ;
return 0 ;
}
static int F_42 ( struct V_41 * V_42 ,
struct V_132 * V_44 )
{
struct V_47 * V_48 ;
enum V_133 type = V_44 -> type ;
T_1 V_69 = V_44 -> V_69 ;
if ( V_44 -> type != V_42 -> type || V_44 -> V_69 >= V_42 -> V_59 )
return - V_24 ;
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
V_44 -> V_69 = V_69 ;
V_44 -> type = type ;
V_48 = & V_42 -> V_48 [ V_44 -> V_69 ] ;
V_44 -> V_134 = 0 ;
if ( V_48 -> V_134 & V_135 )
V_44 -> V_134 |= V_136 ;
F_40 ( V_44 -> V_137 , V_48 -> V_12 , sizeof( V_44 -> V_137 ) ) ;
V_44 -> V_137 [ sizeof( V_44 -> V_137 ) - 1 ] = 0 ;
V_44 -> V_55 = V_48 -> V_53 ;
return 0 ;
}
static int F_43 ( struct V_109 * V_109 , void * V_117 ,
struct V_132 * V_44 )
{
struct V_103 * V_104 = V_117 ;
struct V_41 * V_42 = V_104 -> V_42 ;
return F_42 ( V_42 , V_44 ) ;
}
static int F_44 ( struct V_109 * V_109 , void * V_117 ,
struct V_132 * V_44 )
{
struct V_103 * V_104 = V_117 ;
struct V_41 * V_42 = V_104 -> V_42 ;
return F_42 ( V_42 , V_44 ) ;
}
static int F_45 ( struct V_109 * V_109 , void * V_117 ,
struct V_43 * V_44 )
{
struct V_103 * V_104 = V_117 ;
struct V_41 * V_42 = V_104 -> V_42 ;
return F_13 ( V_42 , V_44 ) ;
}
static int F_46 ( struct V_109 * V_109 , void * V_117 ,
struct V_43 * V_44 )
{
struct V_103 * V_104 = V_117 ;
struct V_41 * V_42 = V_104 -> V_42 ;
return F_13 ( V_42 , V_44 ) ;
}
static int F_47 ( struct V_109 * V_109 , void * V_117 ,
struct V_43 * V_44 )
{
struct V_103 * V_104 = V_117 ;
struct V_41 * V_42 = V_104 -> V_42 ;
int V_8 ;
V_8 = F_21 ( V_104 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_14 ( V_42 , V_44 ) ;
}
static int F_48 ( struct V_109 * V_109 , void * V_117 ,
struct V_43 * V_44 )
{
struct V_103 * V_104 = V_117 ;
struct V_41 * V_42 = V_104 -> V_42 ;
int V_8 ;
V_8 = F_21 ( V_104 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_14 ( V_42 , V_44 ) ;
}
static int F_49 ( struct V_109 * V_109 , void * V_117 ,
struct V_43 * V_44 )
{
struct V_103 * V_104 = V_117 ;
struct V_41 * V_42 = V_104 -> V_42 ;
struct V_45 V_46 ;
return F_9 ( V_42 , V_44 , & V_46 , NULL , NULL ) ;
}
static int F_50 ( struct V_109 * V_109 , void * V_117 ,
struct V_43 * V_44 )
{
struct V_103 * V_104 = V_117 ;
struct V_41 * V_42 = V_104 -> V_42 ;
struct V_45 V_46 ;
return F_9 ( V_42 , V_44 , & V_46 , NULL , NULL ) ;
}
static int F_51 ( struct V_109 * V_109 , void * V_117 ,
struct V_138 * V_139 )
{
struct V_103 * V_104 = V_117 ;
struct V_41 * V_42 = V_104 -> V_42 ;
int V_8 ;
V_8 = F_21 ( V_104 ) ;
if ( V_8 < 0 )
return V_8 ;
F_10 ( & V_42 -> V_71 ) ;
V_8 = F_52 ( & V_42 -> V_86 , V_139 ) ;
F_12 ( & V_42 -> V_71 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 == 0 )
F_24 ( V_104 ) ;
return 0 ;
}
static int F_53 ( struct V_109 * V_109 , void * V_117 ,
struct V_140 * V_141 )
{
struct V_103 * V_104 = V_117 ;
struct V_41 * V_42 = V_104 -> V_42 ;
if ( ! F_25 ( V_104 ) )
return - V_87 ;
return F_54 ( & V_42 -> V_86 , V_141 ) ;
}
static int F_55 ( struct V_109 * V_109 , void * V_117 , struct V_140 * V_141 )
{
struct V_103 * V_104 = V_117 ;
struct V_41 * V_42 = V_104 -> V_42 ;
if ( ! F_25 ( V_104 ) )
return - V_87 ;
return F_56 ( & V_42 -> V_86 , V_141 ) ;
}
static int F_57 ( struct V_109 * V_109 , void * V_117 ,
struct V_142 * exp )
{
struct V_103 * V_104 = V_117 ;
struct V_41 * V_42 = V_104 -> V_42 ;
if ( ! F_25 ( V_104 ) )
return - V_87 ;
return F_58 ( & V_42 -> V_86 , exp ) ;
}
static int F_59 ( struct V_109 * V_109 , void * V_117 , struct V_140 * V_141 )
{
struct V_103 * V_104 = V_117 ;
struct V_41 * V_42 = V_104 -> V_42 ;
if ( ! F_25 ( V_104 ) )
return - V_87 ;
return F_60 ( & V_42 -> V_86 , V_141 ,
V_109 -> V_143 & V_144 ) ;
}
static int F_61 ( struct V_109 * V_109 , void * V_117 ,
struct V_145 * V_146 )
{
struct V_103 * V_104 = V_117 ;
struct V_41 * V_42 = V_104 -> V_42 ;
int V_8 ;
V_8 = F_21 ( V_104 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_62 ( & V_42 -> V_86 , V_146 ) ;
}
static int F_63 ( struct V_109 * V_109 , void * V_117 ,
enum V_133 type )
{
struct V_103 * V_104 = V_117 ;
struct V_41 * V_42 = V_104 -> V_42 ;
int V_8 ;
if ( ! F_25 ( V_104 ) )
return - V_87 ;
F_10 ( & V_42 -> V_71 ) ;
V_8 = F_64 ( & V_42 -> V_86 , type ) ;
F_12 ( & V_42 -> V_71 ) ;
return V_8 ;
}
static int F_65 ( struct V_109 * V_109 , void * V_117 ,
enum V_133 type )
{
struct V_103 * V_104 = V_117 ;
struct V_41 * V_42 = V_104 -> V_42 ;
if ( ! F_25 ( V_104 ) )
return - V_87 ;
F_10 ( & V_42 -> V_71 ) ;
F_66 ( & V_42 -> V_86 , type ) ;
F_12 ( & V_42 -> V_71 ) ;
return 0 ;
}
static int F_67 ( struct V_109 * V_109 , void * V_117 ,
struct V_147 * V_148 )
{
struct V_103 * V_104 = V_117 ;
struct V_1 * V_2 = V_104 -> V_2 ;
const struct V_149 * V_14 = V_2 -> V_14 ;
struct V_149 * V_150 = NULL ;
T_5 V_69 = V_148 -> V_69 ;
int V_151 = 0 ;
if ( V_14 == NULL ||
( V_2 -> V_72 -> V_73 & V_152 ) ) {
if ( V_69 != 0 )
return - V_24 ;
F_68 (iterm, &chain->entities, chain) {
if ( F_69 ( V_150 ) )
break;
}
V_151 = V_150 -> V_11 ;
} else if ( V_69 < V_14 -> V_153 ) {
V_151 = V_14 -> V_154 [ V_69 ] ;
F_68 (iterm, &chain->entities, chain) {
if ( ! F_69 ( V_150 ) )
continue;
if ( V_150 -> V_11 == V_151 )
break;
}
}
if ( V_150 == NULL || V_150 -> V_11 != V_151 )
return - V_24 ;
memset ( V_148 , 0 , sizeof( * V_148 ) ) ;
V_148 -> V_69 = V_69 ;
F_40 ( V_148 -> V_12 , V_150 -> V_12 , sizeof( V_148 -> V_12 ) ) ;
if ( F_70 ( V_150 ) == V_155 )
V_148 -> type = V_156 ;
return 0 ;
}
static int F_71 ( struct V_109 * V_109 , void * V_117 , unsigned int * V_148 )
{
struct V_103 * V_104 = V_117 ;
struct V_1 * V_2 = V_104 -> V_2 ;
int V_8 ;
T_6 V_33 ;
if ( V_2 -> V_14 == NULL ||
( V_2 -> V_72 -> V_73 & V_152 ) ) {
* V_148 = 0 ;
return 0 ;
}
V_8 = F_72 ( V_2 -> V_72 , V_157 , V_2 -> V_14 -> V_11 ,
V_2 -> V_72 -> V_158 , V_159 ,
& V_33 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
* V_148 = V_33 - 1 ;
return 0 ;
}
static int F_73 ( struct V_109 * V_109 , void * V_117 , unsigned int V_148 )
{
struct V_103 * V_104 = V_117 ;
struct V_1 * V_2 = V_104 -> V_2 ;
int V_8 ;
T_5 V_33 ;
V_8 = F_21 ( V_104 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_2 -> V_14 == NULL ||
( V_2 -> V_72 -> V_73 & V_152 ) ) {
if ( V_148 )
return - V_24 ;
return 0 ;
}
if ( V_148 >= V_2 -> V_14 -> V_153 )
return - V_24 ;
V_33 = V_148 + 1 ;
return F_72 ( V_2 -> V_72 , V_160 , V_2 -> V_14 -> V_11 ,
V_2 -> V_72 -> V_158 , V_159 ,
& V_33 , 1 ) ;
}
static int F_74 ( struct V_109 * V_109 , void * V_117 ,
struct V_161 * V_162 )
{
struct V_103 * V_104 = V_117 ;
struct V_1 * V_2 = V_104 -> V_2 ;
return F_75 ( V_2 , V_162 ) ;
}
static int F_76 ( struct V_109 * V_109 , void * V_117 ,
struct V_163 * V_164 )
{
struct V_103 * V_104 = V_117 ;
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_161 V_162 = { V_164 -> V_11 } ;
int V_8 ;
V_8 = F_75 ( V_2 , & V_162 ) ;
if ( V_8 )
return V_8 ;
V_164 -> V_11 = V_162 . V_11 ;
V_164 -> type = V_162 . type ;
F_40 ( V_164 -> V_12 , V_162 . V_12 , sizeof( V_164 -> V_12 ) ) ;
V_164 -> V_165 = V_162 . V_165 ;
V_164 -> V_166 = V_162 . V_166 ;
V_164 -> V_40 = V_162 . V_40 ;
V_164 -> V_167 = V_162 . V_167 ;
V_164 -> V_134 = V_162 . V_134 ;
V_164 -> V_168 = 4 ;
V_164 -> V_169 = 1 ;
V_164 -> V_170 = 0 ;
memset ( V_164 -> V_171 , 0 , sizeof( V_164 -> V_171 ) ) ;
memset ( V_164 -> V_172 , 0 , sizeof( V_164 -> V_172 ) ) ;
return 0 ;
}
static int F_77 ( struct V_109 * V_109 , void * V_117 ,
struct V_173 * V_76 )
{
struct V_103 * V_104 = V_117 ;
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_174 V_175 ;
int V_8 ;
memset ( & V_175 , 0 , sizeof( V_175 ) ) ;
V_175 . V_11 = V_76 -> V_11 ;
V_8 = F_78 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_79 ( V_2 , & V_175 ) ;
F_80 ( V_104 ) ;
if ( V_8 < 0 )
return V_8 ;
V_76 -> V_176 = V_175 . V_176 ;
return 0 ;
}
static int F_81 ( struct V_109 * V_109 , void * V_117 ,
struct V_173 * V_76 )
{
struct V_103 * V_104 = V_117 ;
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_174 V_175 ;
int V_8 ;
memset ( & V_175 , 0 , sizeof( V_175 ) ) ;
V_175 . V_11 = V_76 -> V_11 ;
V_175 . V_176 = V_76 -> V_176 ;
V_8 = F_78 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_82 ( V_2 , & V_175 ) ;
if ( V_8 < 0 ) {
F_80 ( V_104 ) ;
return V_8 ;
}
V_8 = F_83 ( V_104 , & V_175 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
V_76 -> V_176 = V_175 . V_176 ;
return 0 ;
}
static int F_84 ( struct V_109 * V_109 , void * V_117 ,
struct V_177 * V_178 )
{
struct V_103 * V_104 = V_117 ;
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_174 * V_76 = V_178 -> V_179 ;
unsigned int V_33 ;
int V_8 ;
if ( V_178 -> V_180 == V_181 ) {
for ( V_33 = 0 ; V_33 < V_178 -> V_182 ; ++ V_76 , ++ V_33 ) {
struct V_161 V_162 = { . V_11 = V_76 -> V_11 } ;
V_8 = F_75 ( V_2 , & V_162 ) ;
if ( V_8 < 0 ) {
V_178 -> V_183 = V_33 ;
return V_8 ;
}
V_76 -> V_176 = V_162 . V_167 ;
}
return 0 ;
}
V_8 = F_78 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
for ( V_33 = 0 ; V_33 < V_178 -> V_182 ; ++ V_76 , ++ V_33 ) {
V_8 = F_79 ( V_2 , V_76 ) ;
if ( V_8 < 0 ) {
F_80 ( V_104 ) ;
V_178 -> V_183 = V_33 ;
return V_8 ;
}
}
V_178 -> V_183 = 0 ;
return F_80 ( V_104 ) ;
}
static int F_85 ( struct V_103 * V_104 ,
struct V_177 * V_178 ,
bool V_184 )
{
struct V_174 * V_76 = V_178 -> V_179 ;
struct V_1 * V_2 = V_104 -> V_2 ;
unsigned int V_33 ;
int V_8 ;
if ( V_178 -> V_180 == V_181 )
return - V_24 ;
V_8 = F_78 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
for ( V_33 = 0 ; V_33 < V_178 -> V_182 ; ++ V_76 , ++ V_33 ) {
V_8 = F_82 ( V_2 , V_76 ) ;
if ( V_8 < 0 ) {
F_80 ( V_104 ) ;
V_178 -> V_183 = V_184 ? V_178 -> V_182 : V_33 ;
return V_8 ;
}
}
V_178 -> V_183 = 0 ;
if ( V_184 )
return F_83 ( V_104 , V_178 -> V_179 , V_178 -> V_182 ) ;
else
return F_80 ( V_104 ) ;
}
static int F_86 ( struct V_109 * V_109 , void * V_117 ,
struct V_177 * V_178 )
{
struct V_103 * V_104 = V_117 ;
return F_85 ( V_104 , V_178 , true ) ;
}
static int F_87 ( struct V_109 * V_109 , void * V_117 ,
struct V_177 * V_178 )
{
struct V_103 * V_104 = V_117 ;
return F_85 ( V_104 , V_178 , false ) ;
}
static int F_88 ( struct V_109 * V_109 , void * V_117 ,
struct V_185 * V_186 )
{
struct V_103 * V_104 = V_117 ;
struct V_1 * V_2 = V_104 -> V_2 ;
return F_89 ( V_2 , V_186 ) ;
}
static int F_90 ( struct V_109 * V_109 , void * V_117 ,
struct V_187 * V_188 )
{
struct V_103 * V_104 = V_117 ;
struct V_41 * V_42 = V_104 -> V_42 ;
if ( V_188 -> type != V_42 -> type )
return - V_24 ;
switch ( V_188 -> V_189 ) {
case V_190 :
case V_191 :
if ( V_42 -> type != V_92 )
return - V_24 ;
break;
case V_192 :
case V_193 :
if ( V_42 -> type != V_194 )
return - V_24 ;
break;
default:
return - V_24 ;
}
V_188 -> V_195 . V_196 = 0 ;
V_188 -> V_195 . V_197 = 0 ;
F_10 ( & V_42 -> V_71 ) ;
V_188 -> V_195 . V_57 = V_42 -> V_85 -> V_63 ;
V_188 -> V_195 . V_58 = V_42 -> V_85 -> V_65 ;
F_12 ( & V_42 -> V_71 ) ;
return 0 ;
}
static int F_91 ( struct V_109 * V_109 , void * V_117 ,
struct V_88 * V_89 )
{
struct V_103 * V_104 = V_117 ;
struct V_41 * V_42 = V_104 -> V_42 ;
return F_16 ( V_42 , V_89 ) ;
}
static int F_92 ( struct V_109 * V_109 , void * V_117 ,
struct V_88 * V_89 )
{
struct V_103 * V_104 = V_117 ;
struct V_41 * V_42 = V_104 -> V_42 ;
int V_8 ;
V_8 = F_21 ( V_104 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_18 ( V_42 , V_89 ) ;
}
static int F_93 ( struct V_109 * V_109 , void * V_117 ,
struct V_198 * V_199 )
{
struct V_103 * V_104 = V_117 ;
struct V_41 * V_42 = V_104 -> V_42 ;
struct V_47 * V_48 = NULL ;
struct V_30 * V_31 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_42 -> V_59 ; V_33 ++ ) {
if ( V_42 -> V_48 [ V_33 ] . V_53 == V_199 -> V_200 ) {
V_48 = & V_42 -> V_48 [ V_33 ] ;
break;
}
}
if ( V_48 == NULL )
return - V_24 ;
if ( V_199 -> V_69 >= V_48 -> V_61 )
return - V_24 ;
V_31 = & V_48 -> V_31 [ V_199 -> V_69 ] ;
V_199 -> type = V_201 ;
V_199 -> V_202 . V_57 = V_31 -> V_63 ;
V_199 -> V_202 . V_58 = V_31 -> V_65 ;
return 0 ;
}
static int F_94 ( struct V_109 * V_109 , void * V_117 ,
struct V_203 * V_204 )
{
struct V_103 * V_104 = V_117 ;
struct V_41 * V_42 = V_104 -> V_42 ;
struct V_47 * V_48 = NULL ;
struct V_30 * V_31 = NULL ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_42 -> V_59 ; V_33 ++ ) {
if ( V_42 -> V_48 [ V_33 ] . V_53 == V_204 -> V_200 ) {
V_48 = & V_42 -> V_48 [ V_33 ] ;
break;
}
}
if ( V_48 == NULL )
return - V_24 ;
for ( V_33 = 0 ; V_33 < V_48 -> V_61 ; V_33 ++ ) {
if ( V_48 -> V_31 [ V_33 ] . V_63 == V_204 -> V_57 &&
V_48 -> V_31 [ V_33 ] . V_65 == V_204 -> V_58 ) {
V_31 = & V_48 -> V_31 [ V_33 ] ;
break;
}
}
if ( V_31 == NULL )
return - V_24 ;
if ( V_31 -> V_34 ) {
if ( V_204 -> V_69 >= V_31 -> V_34 )
return - V_24 ;
V_204 -> type = V_205 ;
V_204 -> V_202 . V_90 =
V_31 -> V_37 [ V_204 -> V_69 ] ;
V_204 -> V_202 . V_91 = 10000000 ;
F_17 ( & V_204 -> V_202 . V_90 ,
& V_204 -> V_202 . V_91 , 8 , 333 ) ;
} else {
if ( V_204 -> V_69 )
return - V_24 ;
V_204 -> type = V_206 ;
V_204 -> V_207 . V_38 . V_90 = V_31 -> V_37 [ 0 ] ;
V_204 -> V_207 . V_38 . V_91 = 10000000 ;
V_204 -> V_207 . V_39 . V_90 = V_31 -> V_37 [ 1 ] ;
V_204 -> V_207 . V_39 . V_91 = 10000000 ;
V_204 -> V_207 . V_40 . V_90 = V_31 -> V_37 [ 2 ] ;
V_204 -> V_207 . V_40 . V_91 = 10000000 ;
F_17 ( & V_204 -> V_207 . V_38 . V_90 ,
& V_204 -> V_207 . V_38 . V_91 , 8 , 333 ) ;
F_17 ( & V_204 -> V_207 . V_39 . V_90 ,
& V_204 -> V_207 . V_39 . V_91 , 8 , 333 ) ;
F_17 ( & V_204 -> V_207 . V_40 . V_90 ,
& V_204 -> V_207 . V_40 . V_91 , 8 , 333 ) ;
}
return 0 ;
}
static int F_95 ( struct V_208 * V_117 ,
const struct V_209 * V_210 )
{
switch ( V_210 -> type ) {
case V_211 :
return F_96 ( V_117 , V_210 , 0 , & V_212 ) ;
default:
return - V_24 ;
}
}
static long F_97 ( struct V_109 * V_109 , void * V_117 , bool V_213 ,
unsigned int V_214 , void * V_215 )
{
struct V_103 * V_104 = V_117 ;
struct V_1 * V_2 = V_104 -> V_2 ;
switch ( V_214 ) {
case V_216 :
return F_1 ( V_2 , V_215 ) ;
case V_217 :
return F_98 ( V_2 , V_215 ) ;
default:
return - V_29 ;
}
}
static int F_99 ( struct V_3 * V_218 ,
const struct V_219 T_7 * V_220 )
{
T_8 V_221 ;
if ( ! F_100 ( V_222 , V_220 , sizeof( * V_220 ) ) ||
F_101 ( V_218 , V_220 , F_102 ( F_103 ( * V_220 ) , V_26 ) ) ||
F_104 ( V_218 -> V_22 , & V_220 -> V_22 ) )
return - V_27 ;
memset ( V_218 -> V_172 , 0 , sizeof( V_218 -> V_172 ) ) ;
if ( V_218 -> V_22 == 0 ) {
V_218 -> V_26 = NULL ;
return 0 ;
}
if ( F_104 ( V_221 , & V_220 -> V_26 ) )
return - V_27 ;
V_218 -> V_26 = F_105 ( V_221 ) ;
return 0 ;
}
static int F_106 ( const struct V_3 * V_218 ,
struct V_219 T_7 * V_220 )
{
if ( ! F_100 ( V_223 , V_220 , sizeof( * V_220 ) ) ||
F_107 ( V_220 , V_218 , F_102 ( F_103 ( * V_220 ) , V_26 ) ) ||
F_108 ( V_218 -> V_22 , & V_220 -> V_22 ) )
return - V_27 ;
if ( F_109 ( V_220 -> V_172 , sizeof( V_220 -> V_172 ) ) )
return - V_27 ;
return 0 ;
}
static int F_110 ( struct V_224 * V_218 ,
const struct V_225 T_7 * V_220 )
{
T_8 V_221 ;
if ( ! F_100 ( V_222 , V_220 , sizeof( * V_220 ) ) ||
F_101 ( V_218 , V_220 , F_102 ( F_103 ( * V_220 ) , V_226 ) ) )
return - V_27 ;
if ( V_218 -> V_7 == 0 ) {
V_218 -> V_226 = NULL ;
return 0 ;
}
if ( F_104 ( V_221 , & V_220 -> V_226 ) )
return - V_27 ;
V_218 -> V_226 = F_105 ( V_221 ) ;
return 0 ;
}
static int F_111 ( const struct V_224 * V_218 ,
struct V_225 T_7 * V_220 )
{
if ( ! F_100 ( V_223 , V_220 , sizeof( * V_220 ) ) ||
F_107 ( V_220 , V_218 , F_102 ( F_103 ( * V_220 ) , V_226 ) ) )
return - V_27 ;
return 0 ;
}
static long F_112 ( struct V_109 * V_109 ,
unsigned int V_214 , unsigned long V_215 )
{
struct V_103 * V_104 = V_109 -> V_116 ;
union {
struct V_3 V_4 ;
struct V_224 V_227 ;
} V_228 ;
void T_7 * V_220 = F_105 ( V_215 ) ;
long V_8 ;
switch ( V_214 ) {
case V_229 :
V_8 = F_99 ( & V_228 . V_4 , V_220 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_1 ( V_104 -> V_2 , & V_228 . V_4 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_106 ( & V_228 . V_4 , V_220 ) ;
if ( V_8 )
return V_8 ;
break;
case V_230 :
V_8 = F_110 ( & V_228 . V_227 , V_220 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_98 ( V_104 -> V_2 , & V_228 . V_227 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_111 ( & V_228 . V_227 , V_220 ) ;
if ( V_8 )
return V_8 ;
break;
default:
return - V_231 ;
}
return V_8 ;
}
static T_9 F_113 ( struct V_109 * V_109 , char T_7 * V_226 ,
T_10 V_182 , T_11 * V_232 )
{
F_5 ( V_110 , L_11 ) ;
return - V_24 ;
}
static int F_114 ( struct V_109 * V_109 , struct V_233 * V_234 )
{
struct V_103 * V_104 = V_109 -> V_116 ;
struct V_41 * V_42 = V_104 -> V_42 ;
F_5 ( V_110 , L_12 ) ;
return F_115 ( & V_42 -> V_86 , V_234 ) ;
}
static unsigned int F_116 ( struct V_109 * V_109 , T_12 * V_235 )
{
struct V_103 * V_104 = V_109 -> V_116 ;
struct V_41 * V_42 = V_104 -> V_42 ;
F_5 ( V_110 , L_13 ) ;
return F_117 ( & V_42 -> V_86 , V_109 , V_235 ) ;
}
static unsigned long F_118 ( struct V_109 * V_109 ,
unsigned long V_236 , unsigned long V_237 , unsigned long V_238 ,
unsigned long V_134 )
{
struct V_103 * V_104 = V_109 -> V_116 ;
struct V_41 * V_42 = V_104 -> V_42 ;
F_5 ( V_110 , L_14 ) ;
return F_119 ( & V_42 -> V_86 , V_238 ) ;
}
