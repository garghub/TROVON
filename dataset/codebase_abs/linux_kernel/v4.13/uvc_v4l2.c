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
V_6 -> V_26 = F_3 ( V_4 -> V_26 , V_7 ) ;
if ( F_4 ( V_6 -> V_26 ) ) {
V_8 = F_5 ( V_6 -> V_26 ) ;
goto V_25;
}
V_6 -> V_22 = V_4 -> V_22 ;
break;
default:
F_6 ( V_27 , L_1
L_2 , V_4 -> V_16 ) ;
V_8 = - V_28 ;
goto V_25;
}
V_8 = F_7 ( V_2 , V_6 ) ;
F_8 ( V_6 -> V_26 ) ;
V_25:
F_8 ( V_6 ) ;
return V_8 ;
}
static T_1 F_9 ( struct V_29 * V_30 , T_1 V_31 )
{
unsigned int V_32 ;
if ( V_30 -> V_33 ) {
T_1 V_34 = - 1 , V_35 ;
for ( V_32 = 0 ; V_32 < V_30 -> V_33 ; ++ V_32 ) {
V_35 = V_31 > V_30 -> V_36 [ V_32 ]
? V_31 - V_30 -> V_36 [ V_32 ]
: V_30 -> V_36 [ V_32 ] - V_31 ;
if ( V_35 > V_34 )
break;
V_34 = V_35 ;
}
V_31 = V_30 -> V_36 [ V_32 - 1 ] ;
} else {
const T_1 V_37 = V_30 -> V_36 [ 0 ] ;
const T_1 V_38 = V_30 -> V_36 [ 1 ] ;
const T_1 V_39 = V_30 -> V_36 [ 2 ] ;
V_31 = V_37 + ( V_31 - V_37 + V_39 / 2 ) / V_39 * V_39 ;
if ( V_31 > V_38 )
V_31 = V_38 ;
}
return V_31 ;
}
static T_1 F_10 ( const struct V_40 * V_41 ,
const struct V_29 * V_30 )
{
switch ( V_41 -> V_42 ) {
case V_43 :
case V_44 :
case V_45 :
case V_46 :
return V_30 -> V_47 ;
default:
return V_41 -> V_48 * V_30 -> V_47 / 8 ;
}
}
static int F_11 ( struct V_49 * V_50 ,
struct V_51 * V_52 , struct V_53 * V_54 ,
struct V_40 * * V_40 , struct V_29 * * V_29 )
{
struct V_40 * V_41 = NULL ;
struct V_29 * V_30 = NULL ;
T_2 V_55 , V_56 ;
unsigned int V_57 , V_58 ;
unsigned int V_32 ;
T_1 V_31 ;
int V_8 = 0 ;
T_3 * V_42 ;
if ( V_52 -> type != V_50 -> type )
return - V_24 ;
V_42 = ( T_3 * ) & V_52 -> V_52 . V_59 . V_60 ;
F_6 ( V_61 , L_3 ,
V_52 -> V_52 . V_59 . V_60 ,
V_42 [ 0 ] , V_42 [ 1 ] , V_42 [ 2 ] , V_42 [ 3 ] ,
V_52 -> V_52 . V_59 . V_62 , V_52 -> V_52 . V_59 . V_63 ) ;
for ( V_32 = 0 ; V_32 < V_50 -> V_64 ; ++ V_32 ) {
V_41 = & V_50 -> V_41 [ V_32 ] ;
if ( V_41 -> V_42 == V_52 -> V_52 . V_59 . V_60 )
break;
}
if ( V_32 == V_50 -> V_64 ) {
V_41 = V_50 -> V_65 ;
V_52 -> V_52 . V_59 . V_60 = V_41 -> V_42 ;
}
V_55 = V_52 -> V_52 . V_59 . V_62 ;
V_56 = V_52 -> V_52 . V_59 . V_63 ;
V_58 = ( unsigned int ) - 1 ;
for ( V_32 = 0 ; V_32 < V_41 -> V_66 ; ++ V_32 ) {
T_2 V_67 = V_41 -> V_30 [ V_32 ] . V_47 ;
T_2 V_68 = V_41 -> V_30 [ V_32 ] . V_69 ;
V_57 = V_37 ( V_67 , V_55 ) * V_37 ( V_68 , V_56 ) ;
V_57 = V_67 * V_68 + V_55 * V_56 - 2 * V_57 ;
if ( V_57 < V_58 ) {
V_58 = V_57 ;
V_30 = & V_41 -> V_30 [ V_32 ] ;
}
if ( V_58 == 0 )
break;
}
if ( V_30 == NULL ) {
F_6 ( V_61 , L_4 ,
V_52 -> V_52 . V_59 . V_62 , V_52 -> V_52 . V_59 . V_63 ) ;
return - V_24 ;
}
V_31 = V_30 -> V_70 ;
F_6 ( V_61 , L_5
L_6 , V_31 / 10 , V_31 % 10 , 10000000 / V_31 ,
( 100000000 / V_31 ) % 10 ) ;
memset ( V_54 , 0 , sizeof *V_54 ) ;
V_54 -> V_71 = 1 ;
V_54 -> V_72 = V_41 -> V_73 ;
V_54 -> V_74 = V_30 -> V_74 ;
V_54 -> V_36 = F_9 ( V_30 , V_31 ) ;
F_12 ( & V_50 -> V_75 ) ;
if ( V_50 -> V_76 -> V_77 & V_78 )
V_54 -> V_79 =
V_50 -> V_80 . V_79 ;
V_8 = F_13 ( V_50 , V_54 ) ;
F_14 ( & V_50 -> V_75 ) ;
if ( V_8 < 0 )
goto V_81;
V_52 -> V_52 . V_59 . V_62 = V_30 -> V_47 ;
V_52 -> V_52 . V_59 . V_63 = V_30 -> V_69 ;
V_52 -> V_52 . V_59 . V_82 = V_83 ;
V_52 -> V_52 . V_59 . V_84 = F_10 ( V_41 , V_30 ) ;
V_52 -> V_52 . V_59 . V_85 = V_54 -> V_79 ;
V_52 -> V_52 . V_59 . V_86 = V_41 -> V_86 ;
V_52 -> V_52 . V_59 . V_87 = 0 ;
if ( V_40 != NULL )
* V_40 = V_41 ;
if ( V_29 != NULL )
* V_29 = V_30 ;
V_81:
return V_8 ;
}
static int F_15 ( struct V_49 * V_50 ,
struct V_51 * V_52 )
{
struct V_40 * V_41 ;
struct V_29 * V_30 ;
int V_8 = 0 ;
if ( V_52 -> type != V_50 -> type )
return - V_24 ;
F_12 ( & V_50 -> V_75 ) ;
V_41 = V_50 -> V_88 ;
V_30 = V_50 -> V_89 ;
if ( V_41 == NULL || V_30 == NULL ) {
V_8 = - V_24 ;
goto V_81;
}
V_52 -> V_52 . V_59 . V_60 = V_41 -> V_42 ;
V_52 -> V_52 . V_59 . V_62 = V_30 -> V_47 ;
V_52 -> V_52 . V_59 . V_63 = V_30 -> V_69 ;
V_52 -> V_52 . V_59 . V_82 = V_83 ;
V_52 -> V_52 . V_59 . V_84 = F_10 ( V_41 , V_30 ) ;
V_52 -> V_52 . V_59 . V_85 = V_50 -> V_80 . V_79 ;
V_52 -> V_52 . V_59 . V_86 = V_41 -> V_86 ;
V_52 -> V_52 . V_59 . V_87 = 0 ;
V_81:
F_14 ( & V_50 -> V_75 ) ;
return V_8 ;
}
static int F_16 ( struct V_49 * V_50 ,
struct V_51 * V_52 )
{
struct V_53 V_54 ;
struct V_40 * V_41 ;
struct V_29 * V_30 ;
int V_8 ;
if ( V_52 -> type != V_50 -> type )
return - V_24 ;
V_8 = F_11 ( V_50 , V_52 , & V_54 , & V_41 , & V_30 ) ;
if ( V_8 < 0 )
return V_8 ;
F_12 ( & V_50 -> V_75 ) ;
if ( F_17 ( & V_50 -> V_90 ) ) {
V_8 = - V_91 ;
goto V_81;
}
V_50 -> V_80 = V_54 ;
V_50 -> V_88 = V_41 ;
V_50 -> V_89 = V_30 ;
V_81:
F_14 ( & V_50 -> V_75 ) ;
return V_8 ;
}
static int F_18 ( struct V_49 * V_50 ,
struct V_92 * V_93 )
{
T_4 V_94 , V_95 ;
if ( V_93 -> type != V_50 -> type )
return - V_24 ;
F_12 ( & V_50 -> V_75 ) ;
V_94 = V_50 -> V_80 . V_36 ;
F_14 ( & V_50 -> V_75 ) ;
V_95 = 10000000 ;
F_19 ( & V_94 , & V_95 , 8 , 333 ) ;
memset ( V_93 , 0 , sizeof *V_93 ) ;
V_93 -> type = V_50 -> type ;
if ( V_50 -> type == V_96 ) {
V_93 -> V_93 . V_97 . V_98 = V_99 ;
V_93 -> V_93 . V_97 . V_100 = 0 ;
V_93 -> V_93 . V_97 . V_101 . V_94 = V_94 ;
V_93 -> V_93 . V_97 . V_101 . V_95 = V_95 ;
V_93 -> V_93 . V_97 . V_102 = 0 ;
V_93 -> V_93 . V_97 . V_103 = 0 ;
} else {
V_93 -> V_93 . V_104 . V_98 = V_99 ;
V_93 -> V_93 . V_104 . V_105 = 0 ;
V_93 -> V_93 . V_104 . V_101 . V_94 = V_94 ;
V_93 -> V_93 . V_104 . V_101 . V_95 = V_95 ;
}
return 0 ;
}
static int F_20 ( struct V_49 * V_50 ,
struct V_92 * V_93 )
{
struct V_53 V_54 ;
struct V_106 V_101 ;
T_4 V_31 ;
int V_8 ;
if ( V_93 -> type != V_50 -> type )
return - V_24 ;
if ( V_93 -> type == V_96 )
V_101 = V_93 -> V_93 . V_97 . V_101 ;
else
V_101 = V_93 -> V_93 . V_104 . V_101 ;
V_31 = F_21 ( V_101 . V_94 ,
V_101 . V_95 ) ;
F_6 ( V_61 , L_7 ,
V_101 . V_94 , V_101 . V_95 , V_31 ) ;
F_12 ( & V_50 -> V_75 ) ;
if ( F_22 ( & V_50 -> V_90 ) ) {
F_14 ( & V_50 -> V_75 ) ;
return - V_91 ;
}
V_54 = V_50 -> V_80 ;
V_54 . V_36 =
F_9 ( V_50 -> V_89 , V_31 ) ;
V_8 = F_13 ( V_50 , & V_54 ) ;
if ( V_8 < 0 ) {
F_14 ( & V_50 -> V_75 ) ;
return V_8 ;
}
V_50 -> V_80 = V_54 ;
F_14 ( & V_50 -> V_75 ) ;
V_101 . V_94 = V_54 . V_36 ;
V_101 . V_95 = 10000000 ;
F_19 ( & V_101 . V_94 ,
& V_101 . V_95 , 8 , 333 ) ;
if ( V_93 -> type == V_96 )
V_93 -> V_93 . V_97 . V_101 = V_101 ;
else
V_93 -> V_93 . V_104 . V_101 = V_101 ;
return 0 ;
}
static int F_23 ( struct V_107 * V_108 )
{
if ( V_108 -> V_109 == V_110 )
return 0 ;
if ( F_24 ( & V_108 -> V_50 -> V_111 ) != 1 ) {
F_25 ( & V_108 -> V_50 -> V_111 ) ;
return - V_91 ;
}
V_108 -> V_109 = V_110 ;
return 0 ;
}
static void F_26 ( struct V_107 * V_108 )
{
if ( V_108 -> V_109 == V_110 )
F_25 ( & V_108 -> V_50 -> V_111 ) ;
V_108 -> V_109 = V_112 ;
}
static int F_27 ( struct V_107 * V_108 )
{
return V_108 -> V_109 == V_110 ;
}
static int F_28 ( struct V_113 * V_113 )
{
struct V_49 * V_50 ;
struct V_107 * V_108 ;
int V_8 = 0 ;
F_6 ( V_114 , L_8 ) ;
V_50 = F_29 ( V_113 ) ;
V_8 = F_30 ( V_50 -> V_76 -> V_115 ) ;
if ( V_8 < 0 )
return V_8 ;
V_108 = F_2 ( sizeof *V_108 , V_9 ) ;
if ( V_108 == NULL ) {
F_31 ( V_50 -> V_76 -> V_115 ) ;
return - V_10 ;
}
F_12 ( & V_50 -> V_76 -> V_116 ) ;
if ( V_50 -> V_76 -> V_117 == 0 ) {
V_8 = F_32 ( V_50 -> V_76 , V_9 ) ;
if ( V_8 < 0 ) {
F_14 ( & V_50 -> V_76 -> V_116 ) ;
F_31 ( V_50 -> V_76 -> V_115 ) ;
F_8 ( V_108 ) ;
return V_8 ;
}
}
V_50 -> V_76 -> V_117 ++ ;
F_14 ( & V_50 -> V_76 -> V_116 ) ;
F_33 ( & V_108 -> V_118 , & V_50 -> V_119 ) ;
F_34 ( & V_108 -> V_118 ) ;
V_108 -> V_2 = V_50 -> V_2 ;
V_108 -> V_50 = V_50 ;
V_108 -> V_109 = V_112 ;
V_113 -> V_120 = V_108 ;
return 0 ;
}
static int F_35 ( struct V_113 * V_113 )
{
struct V_107 * V_108 = V_113 -> V_120 ;
struct V_49 * V_50 = V_108 -> V_50 ;
F_6 ( V_114 , L_9 ) ;
if ( F_27 ( V_108 ) )
F_36 ( & V_50 -> V_90 ) ;
F_26 ( V_108 ) ;
F_37 ( & V_108 -> V_118 ) ;
F_38 ( & V_108 -> V_118 ) ;
F_8 ( V_108 ) ;
V_113 -> V_120 = NULL ;
F_12 ( & V_50 -> V_76 -> V_116 ) ;
if ( -- V_50 -> V_76 -> V_117 == 0 )
F_39 ( V_50 -> V_76 ) ;
F_14 ( & V_50 -> V_76 -> V_116 ) ;
F_31 ( V_50 -> V_76 -> V_115 ) ;
return 0 ;
}
static int F_40 ( struct V_113 * V_113 , void * V_121 ,
struct V_122 * V_123 )
{
struct V_124 * V_119 = F_41 ( V_113 ) ;
struct V_107 * V_108 = V_113 -> V_120 ;
struct V_1 * V_2 = V_108 -> V_2 ;
struct V_49 * V_50 = V_108 -> V_50 ;
F_42 ( V_123 -> V_125 , L_10 , sizeof( V_123 -> V_125 ) ) ;
F_42 ( V_123 -> V_126 , V_119 -> V_12 , sizeof( V_123 -> V_126 ) ) ;
F_43 ( V_50 -> V_76 -> V_127 , V_123 -> V_128 , sizeof( V_123 -> V_128 ) ) ;
V_123 -> V_129 = V_130 | V_131
| V_2 -> V_132 ;
if ( V_50 -> type == V_96 )
V_123 -> V_133 = V_134 | V_131 ;
else
V_123 -> V_133 = V_135 | V_131 ;
return 0 ;
}
static int F_44 ( struct V_49 * V_50 ,
struct V_136 * V_52 )
{
struct V_40 * V_41 ;
enum V_137 type = V_52 -> type ;
T_1 V_73 = V_52 -> V_73 ;
if ( V_52 -> type != V_50 -> type || V_52 -> V_73 >= V_50 -> V_64 )
return - V_24 ;
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
V_52 -> V_73 = V_73 ;
V_52 -> type = type ;
V_41 = & V_50 -> V_41 [ V_52 -> V_73 ] ;
V_52 -> V_138 = 0 ;
if ( V_41 -> V_138 & V_139 )
V_52 -> V_138 |= V_140 ;
F_42 ( V_52 -> V_141 , V_41 -> V_12 , sizeof( V_52 -> V_141 ) ) ;
V_52 -> V_141 [ sizeof( V_52 -> V_141 ) - 1 ] = 0 ;
V_52 -> V_60 = V_41 -> V_42 ;
return 0 ;
}
static int F_45 ( struct V_113 * V_113 , void * V_121 ,
struct V_136 * V_52 )
{
struct V_107 * V_108 = V_121 ;
struct V_49 * V_50 = V_108 -> V_50 ;
return F_44 ( V_50 , V_52 ) ;
}
static int F_46 ( struct V_113 * V_113 , void * V_121 ,
struct V_136 * V_52 )
{
struct V_107 * V_108 = V_121 ;
struct V_49 * V_50 = V_108 -> V_50 ;
return F_44 ( V_50 , V_52 ) ;
}
static int F_47 ( struct V_113 * V_113 , void * V_121 ,
struct V_51 * V_52 )
{
struct V_107 * V_108 = V_121 ;
struct V_49 * V_50 = V_108 -> V_50 ;
return F_15 ( V_50 , V_52 ) ;
}
static int F_48 ( struct V_113 * V_113 , void * V_121 ,
struct V_51 * V_52 )
{
struct V_107 * V_108 = V_121 ;
struct V_49 * V_50 = V_108 -> V_50 ;
return F_15 ( V_50 , V_52 ) ;
}
static int F_49 ( struct V_113 * V_113 , void * V_121 ,
struct V_51 * V_52 )
{
struct V_107 * V_108 = V_121 ;
struct V_49 * V_50 = V_108 -> V_50 ;
int V_8 ;
V_8 = F_23 ( V_108 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_16 ( V_50 , V_52 ) ;
}
static int F_50 ( struct V_113 * V_113 , void * V_121 ,
struct V_51 * V_52 )
{
struct V_107 * V_108 = V_121 ;
struct V_49 * V_50 = V_108 -> V_50 ;
int V_8 ;
V_8 = F_23 ( V_108 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_16 ( V_50 , V_52 ) ;
}
static int F_51 ( struct V_113 * V_113 , void * V_121 ,
struct V_51 * V_52 )
{
struct V_107 * V_108 = V_121 ;
struct V_49 * V_50 = V_108 -> V_50 ;
struct V_53 V_54 ;
return F_11 ( V_50 , V_52 , & V_54 , NULL , NULL ) ;
}
static int F_52 ( struct V_113 * V_113 , void * V_121 ,
struct V_51 * V_52 )
{
struct V_107 * V_108 = V_121 ;
struct V_49 * V_50 = V_108 -> V_50 ;
struct V_53 V_54 ;
return F_11 ( V_50 , V_52 , & V_54 , NULL , NULL ) ;
}
static int F_53 ( struct V_113 * V_113 , void * V_121 ,
struct V_142 * V_143 )
{
struct V_107 * V_108 = V_121 ;
struct V_49 * V_50 = V_108 -> V_50 ;
int V_8 ;
V_8 = F_23 ( V_108 ) ;
if ( V_8 < 0 )
return V_8 ;
F_12 ( & V_50 -> V_75 ) ;
V_8 = F_54 ( & V_50 -> V_90 , V_143 ) ;
F_14 ( & V_50 -> V_75 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 == 0 )
F_26 ( V_108 ) ;
return 0 ;
}
static int F_55 ( struct V_113 * V_113 , void * V_121 ,
struct V_144 * V_145 )
{
struct V_107 * V_108 = V_121 ;
struct V_49 * V_50 = V_108 -> V_50 ;
if ( ! F_27 ( V_108 ) )
return - V_91 ;
return F_56 ( & V_50 -> V_90 , V_145 ) ;
}
static int F_57 ( struct V_113 * V_113 , void * V_121 , struct V_144 * V_145 )
{
struct V_107 * V_108 = V_121 ;
struct V_49 * V_50 = V_108 -> V_50 ;
if ( ! F_27 ( V_108 ) )
return - V_91 ;
return F_58 ( & V_50 -> V_90 , V_145 ) ;
}
static int F_59 ( struct V_113 * V_113 , void * V_121 ,
struct V_146 * exp )
{
struct V_107 * V_108 = V_121 ;
struct V_49 * V_50 = V_108 -> V_50 ;
if ( ! F_27 ( V_108 ) )
return - V_91 ;
return F_60 ( & V_50 -> V_90 , exp ) ;
}
static int F_61 ( struct V_113 * V_113 , void * V_121 , struct V_144 * V_145 )
{
struct V_107 * V_108 = V_121 ;
struct V_49 * V_50 = V_108 -> V_50 ;
if ( ! F_27 ( V_108 ) )
return - V_91 ;
return F_62 ( & V_50 -> V_90 , V_145 ,
V_113 -> V_147 & V_148 ) ;
}
static int F_63 ( struct V_113 * V_113 , void * V_121 ,
struct V_149 * V_150 )
{
struct V_107 * V_108 = V_121 ;
struct V_49 * V_50 = V_108 -> V_50 ;
int V_8 ;
V_8 = F_23 ( V_108 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_64 ( & V_50 -> V_90 , V_150 ) ;
}
static int F_65 ( struct V_113 * V_113 , void * V_121 ,
enum V_137 type )
{
struct V_107 * V_108 = V_121 ;
struct V_49 * V_50 = V_108 -> V_50 ;
int V_8 ;
if ( ! F_27 ( V_108 ) )
return - V_91 ;
F_12 ( & V_50 -> V_75 ) ;
V_8 = F_66 ( & V_50 -> V_90 , type ) ;
F_14 ( & V_50 -> V_75 ) ;
return V_8 ;
}
static int F_67 ( struct V_113 * V_113 , void * V_121 ,
enum V_137 type )
{
struct V_107 * V_108 = V_121 ;
struct V_49 * V_50 = V_108 -> V_50 ;
if ( ! F_27 ( V_108 ) )
return - V_91 ;
F_12 ( & V_50 -> V_75 ) ;
F_68 ( & V_50 -> V_90 , type ) ;
F_14 ( & V_50 -> V_75 ) ;
return 0 ;
}
static int F_69 ( struct V_113 * V_113 , void * V_121 ,
struct V_151 * V_152 )
{
struct V_107 * V_108 = V_121 ;
struct V_1 * V_2 = V_108 -> V_2 ;
const struct V_153 * V_14 = V_2 -> V_14 ;
struct V_153 * V_154 = NULL ;
T_5 V_73 = V_152 -> V_73 ;
int V_155 = 0 ;
if ( V_14 == NULL ||
( V_2 -> V_76 -> V_77 & V_156 ) ) {
if ( V_73 != 0 )
return - V_24 ;
F_70 (iterm, &chain->entities, chain) {
if ( F_71 ( V_154 ) )
break;
}
V_155 = V_154 -> V_11 ;
} else if ( V_73 < V_14 -> V_157 ) {
V_155 = V_14 -> V_158 [ V_73 ] ;
F_70 (iterm, &chain->entities, chain) {
if ( ! F_71 ( V_154 ) )
continue;
if ( V_154 -> V_11 == V_155 )
break;
}
}
if ( V_154 == NULL || V_154 -> V_11 != V_155 )
return - V_24 ;
memset ( V_152 , 0 , sizeof( * V_152 ) ) ;
V_152 -> V_73 = V_73 ;
F_42 ( V_152 -> V_12 , V_154 -> V_12 , sizeof( V_152 -> V_12 ) ) ;
if ( F_72 ( V_154 ) == V_159 )
V_152 -> type = V_160 ;
return 0 ;
}
static int F_73 ( struct V_113 * V_113 , void * V_121 , unsigned int * V_152 )
{
struct V_107 * V_108 = V_121 ;
struct V_1 * V_2 = V_108 -> V_2 ;
int V_8 ;
T_6 V_32 ;
if ( V_2 -> V_14 == NULL ||
( V_2 -> V_76 -> V_77 & V_156 ) ) {
* V_152 = 0 ;
return 0 ;
}
V_8 = F_74 ( V_2 -> V_76 , V_161 , V_2 -> V_14 -> V_11 ,
V_2 -> V_76 -> V_162 , V_163 ,
& V_32 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
* V_152 = V_32 - 1 ;
return 0 ;
}
static int F_75 ( struct V_113 * V_113 , void * V_121 , unsigned int V_152 )
{
struct V_107 * V_108 = V_121 ;
struct V_1 * V_2 = V_108 -> V_2 ;
int V_8 ;
T_5 V_32 ;
V_8 = F_23 ( V_108 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_2 -> V_14 == NULL ||
( V_2 -> V_76 -> V_77 & V_156 ) ) {
if ( V_152 )
return - V_24 ;
return 0 ;
}
if ( V_152 >= V_2 -> V_14 -> V_157 )
return - V_24 ;
V_32 = V_152 + 1 ;
return F_74 ( V_2 -> V_76 , V_164 , V_2 -> V_14 -> V_11 ,
V_2 -> V_76 -> V_162 , V_163 ,
& V_32 , 1 ) ;
}
static int F_76 ( struct V_113 * V_113 , void * V_121 ,
struct V_165 * V_166 )
{
struct V_107 * V_108 = V_121 ;
struct V_1 * V_2 = V_108 -> V_2 ;
return F_77 ( V_2 , V_166 ) ;
}
static int F_78 ( struct V_113 * V_113 , void * V_121 ,
struct V_167 * V_168 )
{
struct V_107 * V_108 = V_121 ;
struct V_1 * V_2 = V_108 -> V_2 ;
struct V_165 V_166 = { V_168 -> V_11 } ;
int V_8 ;
V_8 = F_77 ( V_2 , & V_166 ) ;
if ( V_8 )
return V_8 ;
V_168 -> V_11 = V_166 . V_11 ;
V_168 -> type = V_166 . type ;
F_42 ( V_168 -> V_12 , V_166 . V_12 , sizeof( V_168 -> V_12 ) ) ;
V_168 -> V_169 = V_166 . V_169 ;
V_168 -> V_170 = V_166 . V_170 ;
V_168 -> V_39 = V_166 . V_39 ;
V_168 -> V_171 = V_166 . V_171 ;
V_168 -> V_138 = V_166 . V_138 ;
V_168 -> V_172 = 4 ;
V_168 -> V_173 = 1 ;
V_168 -> V_174 = 0 ;
memset ( V_168 -> V_175 , 0 , sizeof( V_168 -> V_175 ) ) ;
memset ( V_168 -> V_176 , 0 , sizeof( V_168 -> V_176 ) ) ;
return 0 ;
}
static int F_79 ( struct V_113 * V_113 , void * V_121 ,
struct V_177 * V_80 )
{
struct V_107 * V_108 = V_121 ;
struct V_1 * V_2 = V_108 -> V_2 ;
struct V_178 V_179 ;
int V_8 ;
memset ( & V_179 , 0 , sizeof( V_179 ) ) ;
V_179 . V_11 = V_80 -> V_11 ;
V_8 = F_80 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_81 ( V_2 , & V_179 ) ;
F_82 ( V_108 ) ;
if ( V_8 < 0 )
return V_8 ;
V_80 -> V_180 = V_179 . V_180 ;
return 0 ;
}
static int F_83 ( struct V_113 * V_113 , void * V_121 ,
struct V_177 * V_80 )
{
struct V_107 * V_108 = V_121 ;
struct V_1 * V_2 = V_108 -> V_2 ;
struct V_178 V_179 ;
int V_8 ;
memset ( & V_179 , 0 , sizeof( V_179 ) ) ;
V_179 . V_11 = V_80 -> V_11 ;
V_179 . V_180 = V_80 -> V_180 ;
V_8 = F_80 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_84 ( V_2 , & V_179 ) ;
if ( V_8 < 0 ) {
F_82 ( V_108 ) ;
return V_8 ;
}
V_8 = F_85 ( V_108 , & V_179 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
V_80 -> V_180 = V_179 . V_180 ;
return 0 ;
}
static int F_86 ( struct V_113 * V_113 , void * V_121 ,
struct V_181 * V_182 )
{
struct V_107 * V_108 = V_121 ;
struct V_1 * V_2 = V_108 -> V_2 ;
struct V_178 * V_80 = V_182 -> V_183 ;
unsigned int V_32 ;
int V_8 ;
if ( V_182 -> V_184 == V_185 ) {
for ( V_32 = 0 ; V_32 < V_182 -> V_186 ; ++ V_80 , ++ V_32 ) {
struct V_165 V_166 = { . V_11 = V_80 -> V_11 } ;
V_8 = F_77 ( V_2 , & V_166 ) ;
if ( V_8 < 0 ) {
V_182 -> V_187 = V_32 ;
return V_8 ;
}
V_80 -> V_180 = V_166 . V_171 ;
}
return 0 ;
}
V_8 = F_80 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
for ( V_32 = 0 ; V_32 < V_182 -> V_186 ; ++ V_80 , ++ V_32 ) {
V_8 = F_81 ( V_2 , V_80 ) ;
if ( V_8 < 0 ) {
F_82 ( V_108 ) ;
V_182 -> V_187 = V_32 ;
return V_8 ;
}
}
V_182 -> V_187 = 0 ;
return F_82 ( V_108 ) ;
}
static int F_87 ( struct V_107 * V_108 ,
struct V_181 * V_182 ,
bool V_188 )
{
struct V_178 * V_80 = V_182 -> V_183 ;
struct V_1 * V_2 = V_108 -> V_2 ;
unsigned int V_32 ;
int V_8 ;
if ( V_182 -> V_184 == V_185 )
return - V_24 ;
V_8 = F_80 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
for ( V_32 = 0 ; V_32 < V_182 -> V_186 ; ++ V_80 , ++ V_32 ) {
V_8 = F_84 ( V_2 , V_80 ) ;
if ( V_8 < 0 ) {
F_82 ( V_108 ) ;
V_182 -> V_187 = V_188 ? V_182 -> V_186 : V_32 ;
return V_8 ;
}
}
V_182 -> V_187 = 0 ;
if ( V_188 )
return F_85 ( V_108 , V_182 -> V_183 , V_182 -> V_186 ) ;
else
return F_82 ( V_108 ) ;
}
static int F_88 ( struct V_113 * V_113 , void * V_121 ,
struct V_181 * V_182 )
{
struct V_107 * V_108 = V_121 ;
return F_87 ( V_108 , V_182 , true ) ;
}
static int F_89 ( struct V_113 * V_113 , void * V_121 ,
struct V_181 * V_182 )
{
struct V_107 * V_108 = V_121 ;
return F_87 ( V_108 , V_182 , false ) ;
}
static int F_90 ( struct V_113 * V_113 , void * V_121 ,
struct V_189 * V_190 )
{
struct V_107 * V_108 = V_121 ;
struct V_1 * V_2 = V_108 -> V_2 ;
return F_91 ( V_2 , V_190 ) ;
}
static int F_92 ( struct V_113 * V_113 , void * V_121 ,
struct V_191 * V_192 )
{
struct V_107 * V_108 = V_121 ;
struct V_49 * V_50 = V_108 -> V_50 ;
if ( V_192 -> type != V_50 -> type )
return - V_24 ;
switch ( V_192 -> V_193 ) {
case V_194 :
case V_195 :
if ( V_50 -> type != V_96 )
return - V_24 ;
break;
case V_196 :
case V_197 :
if ( V_50 -> type != V_198 )
return - V_24 ;
break;
default:
return - V_24 ;
}
V_192 -> V_199 . V_200 = 0 ;
V_192 -> V_199 . V_201 = 0 ;
F_12 ( & V_50 -> V_75 ) ;
V_192 -> V_199 . V_62 = V_50 -> V_89 -> V_47 ;
V_192 -> V_199 . V_63 = V_50 -> V_89 -> V_69 ;
F_14 ( & V_50 -> V_75 ) ;
return 0 ;
}
static int F_93 ( struct V_113 * V_113 , void * V_121 ,
struct V_92 * V_93 )
{
struct V_107 * V_108 = V_121 ;
struct V_49 * V_50 = V_108 -> V_50 ;
return F_18 ( V_50 , V_93 ) ;
}
static int F_94 ( struct V_113 * V_113 , void * V_121 ,
struct V_92 * V_93 )
{
struct V_107 * V_108 = V_121 ;
struct V_49 * V_50 = V_108 -> V_50 ;
int V_8 ;
V_8 = F_23 ( V_108 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_20 ( V_50 , V_93 ) ;
}
static int F_95 ( struct V_113 * V_113 , void * V_121 ,
struct V_202 * V_203 )
{
struct V_107 * V_108 = V_121 ;
struct V_49 * V_50 = V_108 -> V_50 ;
struct V_40 * V_41 = NULL ;
struct V_29 * V_30 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_50 -> V_64 ; V_32 ++ ) {
if ( V_50 -> V_41 [ V_32 ] . V_42 == V_203 -> V_204 ) {
V_41 = & V_50 -> V_41 [ V_32 ] ;
break;
}
}
if ( V_41 == NULL )
return - V_24 ;
if ( V_203 -> V_73 >= V_41 -> V_66 )
return - V_24 ;
V_30 = & V_41 -> V_30 [ V_203 -> V_73 ] ;
V_203 -> type = V_205 ;
V_203 -> V_206 . V_62 = V_30 -> V_47 ;
V_203 -> V_206 . V_63 = V_30 -> V_69 ;
return 0 ;
}
static int F_96 ( struct V_113 * V_113 , void * V_121 ,
struct V_207 * V_208 )
{
struct V_107 * V_108 = V_121 ;
struct V_49 * V_50 = V_108 -> V_50 ;
struct V_40 * V_41 = NULL ;
struct V_29 * V_30 = NULL ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_50 -> V_64 ; V_32 ++ ) {
if ( V_50 -> V_41 [ V_32 ] . V_42 == V_208 -> V_204 ) {
V_41 = & V_50 -> V_41 [ V_32 ] ;
break;
}
}
if ( V_41 == NULL )
return - V_24 ;
for ( V_32 = 0 ; V_32 < V_41 -> V_66 ; V_32 ++ ) {
if ( V_41 -> V_30 [ V_32 ] . V_47 == V_208 -> V_62 &&
V_41 -> V_30 [ V_32 ] . V_69 == V_208 -> V_63 ) {
V_30 = & V_41 -> V_30 [ V_32 ] ;
break;
}
}
if ( V_30 == NULL )
return - V_24 ;
if ( V_30 -> V_33 ) {
if ( V_208 -> V_73 >= V_30 -> V_33 )
return - V_24 ;
V_208 -> type = V_209 ;
V_208 -> V_206 . V_94 =
V_30 -> V_36 [ V_208 -> V_73 ] ;
V_208 -> V_206 . V_95 = 10000000 ;
F_19 ( & V_208 -> V_206 . V_94 ,
& V_208 -> V_206 . V_95 , 8 , 333 ) ;
} else {
if ( V_208 -> V_73 )
return - V_24 ;
V_208 -> type = V_210 ;
V_208 -> V_211 . V_37 . V_94 = V_30 -> V_36 [ 0 ] ;
V_208 -> V_211 . V_37 . V_95 = 10000000 ;
V_208 -> V_211 . V_38 . V_94 = V_30 -> V_36 [ 1 ] ;
V_208 -> V_211 . V_38 . V_95 = 10000000 ;
V_208 -> V_211 . V_39 . V_94 = V_30 -> V_36 [ 2 ] ;
V_208 -> V_211 . V_39 . V_95 = 10000000 ;
F_19 ( & V_208 -> V_211 . V_37 . V_94 ,
& V_208 -> V_211 . V_37 . V_95 , 8 , 333 ) ;
F_19 ( & V_208 -> V_211 . V_38 . V_94 ,
& V_208 -> V_211 . V_38 . V_95 , 8 , 333 ) ;
F_19 ( & V_208 -> V_211 . V_39 . V_94 ,
& V_208 -> V_211 . V_39 . V_95 , 8 , 333 ) ;
}
return 0 ;
}
static int F_97 ( struct V_212 * V_121 ,
const struct V_213 * V_214 )
{
switch ( V_214 -> type ) {
case V_215 :
return F_98 ( V_121 , V_214 , 0 , & V_216 ) ;
default:
return - V_24 ;
}
}
static long F_99 ( struct V_113 * V_113 , void * V_121 , bool V_217 ,
unsigned int V_218 , void * V_219 )
{
struct V_107 * V_108 = V_121 ;
struct V_1 * V_2 = V_108 -> V_2 ;
switch ( V_218 ) {
case V_220 :
return F_1 ( V_2 , V_219 ) ;
case V_221 :
return F_100 ( V_2 , V_219 ) ;
default:
return - V_28 ;
}
}
static int F_101 ( struct V_3 * V_222 ,
const struct V_223 T_7 * V_224 )
{
T_8 V_225 ;
if ( ! F_102 ( V_226 , V_224 , sizeof( * V_224 ) ) ||
F_103 ( V_222 , V_224 , F_104 ( F_105 ( * V_224 ) , V_26 ) ) ||
F_106 ( V_222 -> V_22 , & V_224 -> V_22 ) )
return - V_227 ;
memset ( V_222 -> V_176 , 0 , sizeof( V_222 -> V_176 ) ) ;
if ( V_222 -> V_22 == 0 ) {
V_222 -> V_26 = NULL ;
return 0 ;
}
if ( F_106 ( V_225 , & V_224 -> V_26 ) )
return - V_227 ;
V_222 -> V_26 = F_107 ( V_225 ) ;
return 0 ;
}
static int F_108 ( const struct V_3 * V_222 ,
struct V_223 T_7 * V_224 )
{
if ( ! F_102 ( V_228 , V_224 , sizeof( * V_224 ) ) ||
F_109 ( V_224 , V_222 , F_104 ( F_105 ( * V_224 ) , V_26 ) ) ||
F_110 ( V_222 -> V_22 , & V_224 -> V_22 ) )
return - V_227 ;
if ( F_111 ( V_224 -> V_176 , sizeof( V_224 -> V_176 ) ) )
return - V_227 ;
return 0 ;
}
static int F_112 ( struct V_229 * V_222 ,
const struct V_230 T_7 * V_224 )
{
T_8 V_225 ;
if ( ! F_102 ( V_226 , V_224 , sizeof( * V_224 ) ) ||
F_103 ( V_222 , V_224 , F_104 ( F_105 ( * V_224 ) , V_231 ) ) )
return - V_227 ;
if ( V_222 -> V_7 == 0 ) {
V_222 -> V_231 = NULL ;
return 0 ;
}
if ( F_106 ( V_225 , & V_224 -> V_231 ) )
return - V_227 ;
V_222 -> V_231 = F_107 ( V_225 ) ;
return 0 ;
}
static int F_113 ( const struct V_229 * V_222 ,
struct V_230 T_7 * V_224 )
{
if ( ! F_102 ( V_228 , V_224 , sizeof( * V_224 ) ) ||
F_109 ( V_224 , V_222 , F_104 ( F_105 ( * V_224 ) , V_231 ) ) )
return - V_227 ;
return 0 ;
}
static long F_114 ( struct V_113 * V_113 ,
unsigned int V_218 , unsigned long V_219 )
{
struct V_107 * V_108 = V_113 -> V_120 ;
union {
struct V_3 V_4 ;
struct V_229 V_232 ;
} V_233 ;
void T_7 * V_224 = F_107 ( V_219 ) ;
long V_8 ;
switch ( V_218 ) {
case V_234 :
V_8 = F_101 ( & V_233 . V_4 , V_224 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_1 ( V_108 -> V_2 , & V_233 . V_4 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_108 ( & V_233 . V_4 , V_224 ) ;
if ( V_8 )
return V_8 ;
break;
case V_235 :
V_8 = F_112 ( & V_233 . V_232 , V_224 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_100 ( V_108 -> V_2 , & V_233 . V_232 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_113 ( & V_233 . V_232 , V_224 ) ;
if ( V_8 )
return V_8 ;
break;
default:
return - V_236 ;
}
return V_8 ;
}
static T_9 F_115 ( struct V_113 * V_113 , char T_7 * V_231 ,
T_10 V_186 , T_11 * V_237 )
{
F_6 ( V_114 , L_11 ) ;
return - V_24 ;
}
static int F_116 ( struct V_113 * V_113 , struct V_238 * V_239 )
{
struct V_107 * V_108 = V_113 -> V_120 ;
struct V_49 * V_50 = V_108 -> V_50 ;
F_6 ( V_114 , L_12 ) ;
return F_117 ( & V_50 -> V_90 , V_239 ) ;
}
static unsigned int F_118 ( struct V_113 * V_113 , T_12 * V_240 )
{
struct V_107 * V_108 = V_113 -> V_120 ;
struct V_49 * V_50 = V_108 -> V_50 ;
F_6 ( V_114 , L_13 ) ;
return F_119 ( & V_50 -> V_90 , V_113 , V_240 ) ;
}
static unsigned long F_120 ( struct V_113 * V_113 ,
unsigned long V_241 , unsigned long V_242 , unsigned long V_243 ,
unsigned long V_138 )
{
struct V_107 * V_108 = V_113 -> V_120 ;
struct V_49 * V_50 = V_108 -> V_50 ;
F_6 ( V_114 , L_14 ) ;
return F_121 ( & V_50 -> V_90 , V_243 ) ;
}
