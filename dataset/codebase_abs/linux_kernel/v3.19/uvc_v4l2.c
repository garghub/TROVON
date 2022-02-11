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
if ( V_42 -> V_72 -> V_105 & V_111 )
return - V_112 ;
V_8 = F_28 ( V_42 -> V_72 -> V_113 ) ;
if ( V_8 < 0 )
return V_8 ;
V_104 = F_2 ( sizeof *V_104 , V_9 ) ;
if ( V_104 == NULL ) {
F_29 ( V_42 -> V_72 -> V_113 ) ;
return - V_10 ;
}
F_10 ( & V_42 -> V_72 -> V_114 ) ;
if ( V_42 -> V_72 -> V_115 == 0 ) {
V_8 = F_30 ( V_42 -> V_72 , V_9 ) ;
if ( V_8 < 0 ) {
F_12 ( & V_42 -> V_72 -> V_114 ) ;
F_29 ( V_42 -> V_72 -> V_113 ) ;
F_7 ( V_104 ) ;
return V_8 ;
}
}
V_42 -> V_72 -> V_115 ++ ;
F_12 ( & V_42 -> V_72 -> V_114 ) ;
F_31 ( & V_104 -> V_116 , V_42 -> V_117 ) ;
F_32 ( & V_104 -> V_116 ) ;
V_104 -> V_2 = V_42 -> V_2 ;
V_104 -> V_42 = V_42 ;
V_104 -> V_105 = V_108 ;
V_109 -> V_118 = V_104 ;
return 0 ;
}
static int F_33 ( struct V_109 * V_109 )
{
struct V_103 * V_104 = V_109 -> V_118 ;
struct V_41 * V_42 = V_104 -> V_42 ;
F_5 ( V_110 , L_9 ) ;
if ( F_25 ( V_104 ) )
F_34 ( & V_42 -> V_86 ) ;
F_24 ( V_104 ) ;
F_35 ( & V_104 -> V_116 ) ;
F_36 ( & V_104 -> V_116 ) ;
F_7 ( V_104 ) ;
V_109 -> V_118 = NULL ;
F_10 ( & V_42 -> V_72 -> V_114 ) ;
if ( -- V_42 -> V_72 -> V_115 == 0 )
F_37 ( V_42 -> V_72 ) ;
F_12 ( & V_42 -> V_72 -> V_114 ) ;
F_29 ( V_42 -> V_72 -> V_113 ) ;
return 0 ;
}
static int F_38 ( struct V_109 * V_109 , void * V_119 ,
struct V_120 * V_121 )
{
struct V_122 * V_117 = F_39 ( V_109 ) ;
struct V_103 * V_104 = V_109 -> V_118 ;
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_41 * V_42 = V_104 -> V_42 ;
F_40 ( V_121 -> V_123 , L_10 , sizeof( V_121 -> V_123 ) ) ;
F_40 ( V_121 -> V_124 , V_117 -> V_12 , sizeof( V_121 -> V_124 ) ) ;
F_41 ( V_42 -> V_72 -> V_125 , V_121 -> V_126 , sizeof( V_121 -> V_126 ) ) ;
V_121 -> V_127 = V_128 | V_129
| V_2 -> V_130 ;
if ( V_42 -> type == V_92 )
V_121 -> V_131 = V_132 | V_129 ;
else
V_121 -> V_131 = V_133 | V_129 ;
return 0 ;
}
static int F_42 ( struct V_41 * V_42 ,
struct V_134 * V_44 )
{
struct V_47 * V_48 ;
enum V_135 type = V_44 -> type ;
T_1 V_69 = V_44 -> V_69 ;
if ( V_44 -> type != V_42 -> type || V_44 -> V_69 >= V_42 -> V_59 )
return - V_24 ;
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
V_44 -> V_69 = V_69 ;
V_44 -> type = type ;
V_48 = & V_42 -> V_48 [ V_44 -> V_69 ] ;
V_44 -> V_136 = 0 ;
if ( V_48 -> V_136 & V_137 )
V_44 -> V_136 |= V_138 ;
F_40 ( V_44 -> V_139 , V_48 -> V_12 , sizeof( V_44 -> V_139 ) ) ;
V_44 -> V_139 [ sizeof( V_44 -> V_139 ) - 1 ] = 0 ;
V_44 -> V_55 = V_48 -> V_53 ;
return 0 ;
}
static int F_43 ( struct V_109 * V_109 , void * V_119 ,
struct V_134 * V_44 )
{
struct V_103 * V_104 = V_119 ;
struct V_41 * V_42 = V_104 -> V_42 ;
return F_42 ( V_42 , V_44 ) ;
}
static int F_44 ( struct V_109 * V_109 , void * V_119 ,
struct V_134 * V_44 )
{
struct V_103 * V_104 = V_119 ;
struct V_41 * V_42 = V_104 -> V_42 ;
return F_42 ( V_42 , V_44 ) ;
}
static int F_45 ( struct V_109 * V_109 , void * V_119 ,
struct V_43 * V_44 )
{
struct V_103 * V_104 = V_119 ;
struct V_41 * V_42 = V_104 -> V_42 ;
return F_13 ( V_42 , V_44 ) ;
}
static int F_46 ( struct V_109 * V_109 , void * V_119 ,
struct V_43 * V_44 )
{
struct V_103 * V_104 = V_119 ;
struct V_41 * V_42 = V_104 -> V_42 ;
return F_13 ( V_42 , V_44 ) ;
}
static int F_47 ( struct V_109 * V_109 , void * V_119 ,
struct V_43 * V_44 )
{
struct V_103 * V_104 = V_119 ;
struct V_41 * V_42 = V_104 -> V_42 ;
int V_8 ;
V_8 = F_21 ( V_104 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_14 ( V_42 , V_44 ) ;
}
static int F_48 ( struct V_109 * V_109 , void * V_119 ,
struct V_43 * V_44 )
{
struct V_103 * V_104 = V_119 ;
struct V_41 * V_42 = V_104 -> V_42 ;
int V_8 ;
V_8 = F_21 ( V_104 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_14 ( V_42 , V_44 ) ;
}
static int F_49 ( struct V_109 * V_109 , void * V_119 ,
struct V_43 * V_44 )
{
struct V_103 * V_104 = V_119 ;
struct V_41 * V_42 = V_104 -> V_42 ;
struct V_45 V_46 ;
return F_9 ( V_42 , V_44 , & V_46 , NULL , NULL ) ;
}
static int F_50 ( struct V_109 * V_109 , void * V_119 ,
struct V_43 * V_44 )
{
struct V_103 * V_104 = V_119 ;
struct V_41 * V_42 = V_104 -> V_42 ;
struct V_45 V_46 ;
return F_9 ( V_42 , V_44 , & V_46 , NULL , NULL ) ;
}
static int F_51 ( struct V_109 * V_109 , void * V_119 ,
struct V_140 * V_141 )
{
struct V_103 * V_104 = V_119 ;
struct V_41 * V_42 = V_104 -> V_42 ;
int V_8 ;
V_8 = F_21 ( V_104 ) ;
if ( V_8 < 0 )
return V_8 ;
F_10 ( & V_42 -> V_71 ) ;
V_8 = F_52 ( & V_42 -> V_86 , V_141 ) ;
F_12 ( & V_42 -> V_71 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 == 0 )
F_24 ( V_104 ) ;
return 0 ;
}
static int F_53 ( struct V_109 * V_109 , void * V_119 ,
struct V_142 * V_143 )
{
struct V_103 * V_104 = V_119 ;
struct V_41 * V_42 = V_104 -> V_42 ;
if ( ! F_25 ( V_104 ) )
return - V_87 ;
return F_54 ( & V_42 -> V_86 , V_143 ) ;
}
static int F_55 ( struct V_109 * V_109 , void * V_119 , struct V_142 * V_143 )
{
struct V_103 * V_104 = V_119 ;
struct V_41 * V_42 = V_104 -> V_42 ;
if ( ! F_25 ( V_104 ) )
return - V_87 ;
return F_56 ( & V_42 -> V_86 , V_143 ) ;
}
static int F_57 ( struct V_109 * V_109 , void * V_119 , struct V_142 * V_143 )
{
struct V_103 * V_104 = V_119 ;
struct V_41 * V_42 = V_104 -> V_42 ;
if ( ! F_25 ( V_104 ) )
return - V_87 ;
return F_58 ( & V_42 -> V_86 , V_143 ,
V_109 -> V_144 & V_145 ) ;
}
static int F_59 ( struct V_109 * V_109 , void * V_119 ,
struct V_146 * V_147 )
{
struct V_103 * V_104 = V_119 ;
struct V_41 * V_42 = V_104 -> V_42 ;
int V_8 ;
V_8 = F_21 ( V_104 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_60 ( & V_42 -> V_86 , V_147 ) ;
}
static int F_61 ( struct V_109 * V_109 , void * V_119 ,
enum V_135 type )
{
struct V_103 * V_104 = V_119 ;
struct V_41 * V_42 = V_104 -> V_42 ;
int V_8 ;
if ( ! F_25 ( V_104 ) )
return - V_87 ;
F_10 ( & V_42 -> V_71 ) ;
V_8 = F_62 ( & V_42 -> V_86 , type ) ;
F_12 ( & V_42 -> V_71 ) ;
return V_8 ;
}
static int F_63 ( struct V_109 * V_109 , void * V_119 ,
enum V_135 type )
{
struct V_103 * V_104 = V_119 ;
struct V_41 * V_42 = V_104 -> V_42 ;
if ( ! F_25 ( V_104 ) )
return - V_87 ;
F_10 ( & V_42 -> V_71 ) ;
F_64 ( & V_42 -> V_86 , type ) ;
F_12 ( & V_42 -> V_71 ) ;
return 0 ;
}
static int F_65 ( struct V_109 * V_109 , void * V_119 ,
struct V_148 * V_149 )
{
struct V_103 * V_104 = V_119 ;
struct V_1 * V_2 = V_104 -> V_2 ;
const struct V_150 * V_14 = V_2 -> V_14 ;
struct V_150 * V_151 = NULL ;
T_5 V_69 = V_149 -> V_69 ;
int V_152 = 0 ;
if ( V_14 == NULL ||
( V_2 -> V_72 -> V_73 & V_153 ) ) {
if ( V_69 != 0 )
return - V_24 ;
F_66 (iterm, &chain->entities, chain) {
if ( F_67 ( V_151 ) )
break;
}
V_152 = V_151 -> V_11 ;
} else if ( V_69 < V_14 -> V_154 ) {
V_152 = V_14 -> V_155 [ V_69 ] ;
F_66 (iterm, &chain->entities, chain) {
if ( ! F_67 ( V_151 ) )
continue;
if ( V_151 -> V_11 == V_152 )
break;
}
}
if ( V_151 == NULL || V_151 -> V_11 != V_152 )
return - V_24 ;
memset ( V_149 , 0 , sizeof( * V_149 ) ) ;
V_149 -> V_69 = V_69 ;
F_40 ( V_149 -> V_12 , V_151 -> V_12 , sizeof( V_149 -> V_12 ) ) ;
if ( F_68 ( V_151 ) == V_156 )
V_149 -> type = V_157 ;
return 0 ;
}
static int F_69 ( struct V_109 * V_109 , void * V_119 , unsigned int * V_149 )
{
struct V_103 * V_104 = V_119 ;
struct V_1 * V_2 = V_104 -> V_2 ;
int V_8 ;
T_6 V_33 ;
if ( V_2 -> V_14 == NULL ||
( V_2 -> V_72 -> V_73 & V_153 ) ) {
* V_149 = 0 ;
return 0 ;
}
V_8 = F_70 ( V_2 -> V_72 , V_158 , V_2 -> V_14 -> V_11 ,
V_2 -> V_72 -> V_159 , V_160 ,
& V_33 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
* V_149 = V_33 - 1 ;
return 0 ;
}
static int F_71 ( struct V_109 * V_109 , void * V_119 , unsigned int V_149 )
{
struct V_103 * V_104 = V_119 ;
struct V_1 * V_2 = V_104 -> V_2 ;
int V_8 ;
T_5 V_33 ;
V_8 = F_21 ( V_104 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_2 -> V_14 == NULL ||
( V_2 -> V_72 -> V_73 & V_153 ) ) {
if ( V_149 )
return - V_24 ;
return 0 ;
}
if ( V_149 >= V_2 -> V_14 -> V_154 )
return - V_24 ;
V_33 = V_149 + 1 ;
return F_70 ( V_2 -> V_72 , V_161 , V_2 -> V_14 -> V_11 ,
V_2 -> V_72 -> V_159 , V_160 ,
& V_33 , 1 ) ;
}
static int F_72 ( struct V_109 * V_109 , void * V_119 ,
struct V_162 * V_163 )
{
struct V_103 * V_104 = V_119 ;
struct V_1 * V_2 = V_104 -> V_2 ;
return F_73 ( V_2 , V_163 ) ;
}
static int F_74 ( struct V_109 * V_109 , void * V_119 ,
struct V_164 * V_76 )
{
struct V_103 * V_104 = V_119 ;
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_165 V_166 ;
int V_8 ;
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
V_166 . V_11 = V_76 -> V_11 ;
V_8 = F_75 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_76 ( V_2 , & V_166 ) ;
F_77 ( V_104 ) ;
if ( V_8 < 0 )
return V_8 ;
V_76 -> V_167 = V_166 . V_167 ;
return 0 ;
}
static int F_78 ( struct V_109 * V_109 , void * V_119 ,
struct V_164 * V_76 )
{
struct V_103 * V_104 = V_119 ;
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_165 V_166 ;
int V_8 ;
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
V_166 . V_11 = V_76 -> V_11 ;
V_166 . V_167 = V_76 -> V_167 ;
V_8 = F_75 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_79 ( V_2 , & V_166 ) ;
if ( V_8 < 0 ) {
F_77 ( V_104 ) ;
return V_8 ;
}
V_8 = F_80 ( V_104 , & V_166 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
V_76 -> V_167 = V_166 . V_167 ;
return 0 ;
}
static int F_81 ( struct V_109 * V_109 , void * V_119 ,
struct V_168 * V_169 )
{
struct V_103 * V_104 = V_119 ;
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_165 * V_76 = V_169 -> V_170 ;
unsigned int V_33 ;
int V_8 ;
V_8 = F_75 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
for ( V_33 = 0 ; V_33 < V_169 -> V_171 ; ++ V_76 , ++ V_33 ) {
V_8 = F_76 ( V_2 , V_76 ) ;
if ( V_8 < 0 ) {
F_77 ( V_104 ) ;
V_169 -> V_172 = V_33 ;
return V_8 ;
}
}
V_169 -> V_172 = 0 ;
return F_77 ( V_104 ) ;
}
static int F_82 ( struct V_103 * V_104 ,
struct V_168 * V_169 ,
bool V_173 )
{
struct V_165 * V_76 = V_169 -> V_170 ;
struct V_1 * V_2 = V_104 -> V_2 ;
unsigned int V_33 ;
int V_8 ;
V_8 = F_75 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
for ( V_33 = 0 ; V_33 < V_169 -> V_171 ; ++ V_76 , ++ V_33 ) {
V_8 = F_79 ( V_2 , V_76 ) ;
if ( V_8 < 0 ) {
F_77 ( V_104 ) ;
V_169 -> V_172 = V_173 ? V_169 -> V_171 : V_33 ;
return V_8 ;
}
}
V_169 -> V_172 = 0 ;
if ( V_173 )
return F_80 ( V_104 , V_169 -> V_170 , V_169 -> V_171 ) ;
else
return F_77 ( V_104 ) ;
}
static int F_83 ( struct V_109 * V_109 , void * V_119 ,
struct V_168 * V_169 )
{
struct V_103 * V_104 = V_119 ;
return F_82 ( V_104 , V_169 , true ) ;
}
static int F_84 ( struct V_109 * V_109 , void * V_119 ,
struct V_168 * V_169 )
{
struct V_103 * V_104 = V_119 ;
return F_82 ( V_104 , V_169 , false ) ;
}
static int F_85 ( struct V_109 * V_109 , void * V_119 ,
struct V_174 * V_175 )
{
struct V_103 * V_104 = V_119 ;
struct V_1 * V_2 = V_104 -> V_2 ;
return F_86 ( V_2 , V_175 ) ;
}
static int F_87 ( struct V_109 * V_109 , void * V_119 ,
struct V_176 * V_177 )
{
struct V_103 * V_104 = V_119 ;
struct V_41 * V_42 = V_104 -> V_42 ;
if ( V_177 -> type != V_42 -> type )
return - V_24 ;
V_177 -> V_178 . V_179 = 0 ;
V_177 -> V_178 . V_180 = 0 ;
F_10 ( & V_42 -> V_71 ) ;
V_177 -> V_178 . V_57 = V_42 -> V_85 -> V_63 ;
V_177 -> V_178 . V_58 = V_42 -> V_85 -> V_65 ;
F_12 ( & V_42 -> V_71 ) ;
V_177 -> V_181 = V_177 -> V_178 ;
V_177 -> V_182 . V_90 = 1 ;
V_177 -> V_182 . V_91 = 1 ;
return 0 ;
}
static int F_88 ( struct V_109 * V_109 , void * V_119 ,
struct V_88 * V_89 )
{
struct V_103 * V_104 = V_119 ;
struct V_41 * V_42 = V_104 -> V_42 ;
return F_16 ( V_42 , V_89 ) ;
}
static int F_89 ( struct V_109 * V_109 , void * V_119 ,
struct V_88 * V_89 )
{
struct V_103 * V_104 = V_119 ;
struct V_41 * V_42 = V_104 -> V_42 ;
int V_8 ;
V_8 = F_21 ( V_104 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_18 ( V_42 , V_89 ) ;
}
static int F_90 ( struct V_109 * V_109 , void * V_119 ,
struct V_183 * V_184 )
{
struct V_103 * V_104 = V_119 ;
struct V_41 * V_42 = V_104 -> V_42 ;
struct V_47 * V_48 = NULL ;
struct V_30 * V_31 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_42 -> V_59 ; V_33 ++ ) {
if ( V_42 -> V_48 [ V_33 ] . V_53 == V_184 -> V_185 ) {
V_48 = & V_42 -> V_48 [ V_33 ] ;
break;
}
}
if ( V_48 == NULL )
return - V_24 ;
if ( V_184 -> V_69 >= V_48 -> V_61 )
return - V_24 ;
V_31 = & V_48 -> V_31 [ V_184 -> V_69 ] ;
V_184 -> type = V_186 ;
V_184 -> V_187 . V_57 = V_31 -> V_63 ;
V_184 -> V_187 . V_58 = V_31 -> V_65 ;
return 0 ;
}
static int F_91 ( struct V_109 * V_109 , void * V_119 ,
struct V_188 * V_189 )
{
struct V_103 * V_104 = V_119 ;
struct V_41 * V_42 = V_104 -> V_42 ;
struct V_47 * V_48 = NULL ;
struct V_30 * V_31 = NULL ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_42 -> V_59 ; V_33 ++ ) {
if ( V_42 -> V_48 [ V_33 ] . V_53 == V_189 -> V_185 ) {
V_48 = & V_42 -> V_48 [ V_33 ] ;
break;
}
}
if ( V_48 == NULL )
return - V_24 ;
for ( V_33 = 0 ; V_33 < V_48 -> V_61 ; V_33 ++ ) {
if ( V_48 -> V_31 [ V_33 ] . V_63 == V_189 -> V_57 &&
V_48 -> V_31 [ V_33 ] . V_65 == V_189 -> V_58 ) {
V_31 = & V_48 -> V_31 [ V_33 ] ;
break;
}
}
if ( V_31 == NULL )
return - V_24 ;
if ( V_31 -> V_34 ) {
if ( V_189 -> V_69 >= V_31 -> V_34 )
return - V_24 ;
V_189 -> type = V_190 ;
V_189 -> V_187 . V_90 =
V_31 -> V_37 [ V_189 -> V_69 ] ;
V_189 -> V_187 . V_91 = 10000000 ;
F_17 ( & V_189 -> V_187 . V_90 ,
& V_189 -> V_187 . V_91 , 8 , 333 ) ;
} else {
V_189 -> type = V_191 ;
V_189 -> V_192 . V_38 . V_90 = V_31 -> V_37 [ 0 ] ;
V_189 -> V_192 . V_38 . V_91 = 10000000 ;
V_189 -> V_192 . V_39 . V_90 = V_31 -> V_37 [ 1 ] ;
V_189 -> V_192 . V_39 . V_91 = 10000000 ;
V_189 -> V_192 . V_40 . V_90 = V_31 -> V_37 [ 2 ] ;
V_189 -> V_192 . V_40 . V_91 = 10000000 ;
F_17 ( & V_189 -> V_192 . V_38 . V_90 ,
& V_189 -> V_192 . V_38 . V_91 , 8 , 333 ) ;
F_17 ( & V_189 -> V_192 . V_39 . V_90 ,
& V_189 -> V_192 . V_39 . V_91 , 8 , 333 ) ;
F_17 ( & V_189 -> V_192 . V_40 . V_90 ,
& V_189 -> V_192 . V_40 . V_91 , 8 , 333 ) ;
}
return 0 ;
}
static int F_92 ( struct V_193 * V_119 ,
const struct V_194 * V_195 )
{
switch ( V_195 -> type ) {
case V_196 :
return F_93 ( V_119 , V_195 , 0 , & V_197 ) ;
default:
return - V_24 ;
}
}
static long F_94 ( struct V_109 * V_109 , void * V_119 , bool V_198 ,
unsigned int V_199 , void * V_200 )
{
struct V_103 * V_104 = V_119 ;
struct V_1 * V_2 = V_104 -> V_2 ;
switch ( V_199 ) {
case V_201 :
return F_1 ( V_2 , V_200 ) ;
case V_202 :
return F_95 ( V_2 , V_200 ) ;
default:
return - V_29 ;
}
}
static int F_96 ( struct V_3 * V_203 ,
const struct V_204 T_7 * V_205 )
{
struct V_206 T_7 * V_207 ;
struct V_206 T_7 * V_208 ;
T_8 V_209 ;
if ( ! F_97 ( V_210 , V_205 , sizeof( * V_205 ) ) ||
F_98 ( V_203 , V_205 , F_99 ( F_100 ( * V_205 ) , V_26 ) ) ||
F_101 ( V_203 -> V_22 , & V_205 -> V_22 ) )
return - V_27 ;
memset ( V_203 -> V_211 , 0 , sizeof( V_203 -> V_211 ) ) ;
if ( V_203 -> V_22 == 0 ) {
V_203 -> V_26 = NULL ;
return 0 ;
}
if ( F_101 ( V_209 , & V_205 -> V_26 ) )
return - V_27 ;
V_207 = F_102 ( V_209 ) ;
if ( ! F_97 ( V_210 , V_207 , V_203 -> V_22 * sizeof( * V_207 ) ) )
return - V_27 ;
V_208 = F_103 ( V_203 -> V_22 * sizeof( * V_208 ) ) ;
if ( V_208 == NULL )
return - V_27 ;
V_203 -> V_26 = V_208 ;
if ( F_104 ( V_208 , V_207 , V_203 -> V_22 * sizeof( * V_207 ) ) )
return - V_27 ;
return 0 ;
}
static int F_105 ( const struct V_3 * V_203 ,
struct V_204 T_7 * V_205 )
{
struct V_206 T_7 * V_207 ;
struct V_206 T_7 * V_208 = V_203 -> V_26 ;
T_8 V_209 ;
if ( ! F_97 ( V_212 , V_205 , sizeof( * V_205 ) ) ||
F_106 ( V_205 , V_203 , F_99 ( F_100 ( * V_205 ) , V_26 ) ) ||
F_107 ( V_203 -> V_22 , & V_205 -> V_22 ) )
return - V_27 ;
if ( F_108 ( V_205 -> V_211 , sizeof( V_205 -> V_211 ) ) )
return - V_27 ;
if ( V_203 -> V_22 == 0 )
return 0 ;
if ( F_109 ( V_209 , & V_205 -> V_26 ) )
return - V_27 ;
V_207 = F_102 ( V_209 ) ;
if ( F_104 ( V_207 , V_208 , V_203 -> V_22 * sizeof( * V_207 ) ) )
return - V_27 ;
return 0 ;
}
static int F_110 ( struct V_213 * V_203 ,
const struct V_214 T_7 * V_205 )
{
T_6 T_7 * V_215 ;
T_6 T_7 * V_216 ;
T_8 V_209 ;
if ( ! F_97 ( V_210 , V_205 , sizeof( * V_205 ) ) ||
F_98 ( V_203 , V_205 , F_99 ( F_100 ( * V_205 ) , V_217 ) ) )
return - V_27 ;
if ( V_203 -> V_7 == 0 ) {
V_203 -> V_217 = NULL ;
return 0 ;
}
if ( F_101 ( V_209 , & V_205 -> V_217 ) )
return - V_27 ;
V_215 = F_102 ( V_209 ) ;
if ( ! F_97 ( V_210 , V_215 , V_203 -> V_7 ) )
return - V_27 ;
V_216 = F_103 ( V_203 -> V_7 ) ;
if ( V_216 == NULL )
return - V_27 ;
V_203 -> V_217 = V_216 ;
if ( F_104 ( V_216 , V_215 , V_203 -> V_7 ) )
return - V_27 ;
return 0 ;
}
static int F_111 ( const struct V_213 * V_203 ,
struct V_214 T_7 * V_205 )
{
T_6 T_7 * V_215 ;
T_6 T_7 * V_216 = V_203 -> V_217 ;
T_8 V_209 ;
if ( ! F_97 ( V_212 , V_205 , sizeof( * V_205 ) ) ||
F_106 ( V_205 , V_203 , F_99 ( F_100 ( * V_205 ) , V_217 ) ) )
return - V_27 ;
if ( V_203 -> V_7 == 0 )
return 0 ;
if ( F_109 ( V_209 , & V_205 -> V_217 ) )
return - V_27 ;
V_215 = F_102 ( V_209 ) ;
if ( ! F_97 ( V_210 , V_215 , V_203 -> V_7 ) )
return - V_27 ;
if ( F_104 ( V_215 , V_216 , V_203 -> V_7 ) )
return - V_27 ;
return 0 ;
}
static long F_112 ( struct V_109 * V_109 ,
unsigned int V_199 , unsigned long V_200 )
{
union {
struct V_3 V_4 ;
struct V_213 V_218 ;
} V_219 ;
void T_7 * V_205 = F_102 ( V_200 ) ;
T_9 V_220 ;
long V_8 ;
switch ( V_199 ) {
case V_221 :
V_199 = V_201 ;
V_8 = F_96 ( & V_219 . V_4 , V_205 ) ;
break;
case V_222 :
V_199 = V_202 ;
V_8 = F_110 ( & V_219 . V_218 , V_205 ) ;
break;
default:
return - V_223 ;
}
V_220 = F_113 () ;
F_114 ( V_224 ) ;
V_8 = F_115 ( V_109 , V_199 , ( unsigned long ) & V_219 ) ;
F_114 ( V_220 ) ;
if ( V_8 < 0 )
return V_8 ;
switch ( V_199 ) {
case V_201 :
V_8 = F_105 ( & V_219 . V_4 , V_205 ) ;
break;
case V_202 :
V_8 = F_111 ( & V_219 . V_218 , V_205 ) ;
break;
}
return V_8 ;
}
static T_10 F_116 ( struct V_109 * V_109 , char T_7 * V_217 ,
T_11 V_171 , T_12 * V_225 )
{
F_5 ( V_110 , L_11 ) ;
return - V_24 ;
}
static int F_117 ( struct V_109 * V_109 , struct V_226 * V_227 )
{
struct V_103 * V_104 = V_109 -> V_118 ;
struct V_41 * V_42 = V_104 -> V_42 ;
F_5 ( V_110 , L_12 ) ;
return F_118 ( & V_42 -> V_86 , V_227 ) ;
}
static unsigned int F_119 ( struct V_109 * V_109 , T_13 * V_228 )
{
struct V_103 * V_104 = V_109 -> V_118 ;
struct V_41 * V_42 = V_104 -> V_42 ;
F_5 ( V_110 , L_13 ) ;
return F_120 ( & V_42 -> V_86 , V_109 , V_228 ) ;
}
static unsigned long F_121 ( struct V_109 * V_109 ,
unsigned long V_229 , unsigned long V_230 , unsigned long V_231 ,
unsigned long V_136 )
{
struct V_103 * V_104 = V_109 -> V_118 ;
struct V_41 * V_42 = V_104 -> V_42 ;
F_5 ( V_110 , L_14 ) ;
return F_122 ( & V_42 -> V_86 , V_231 ) ;
}
