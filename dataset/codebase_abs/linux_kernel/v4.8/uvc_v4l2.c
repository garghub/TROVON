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
static T_1 F_9 ( const struct V_41 * V_42 ,
const struct V_30 * V_31 )
{
switch ( V_42 -> V_43 ) {
case V_44 :
case V_45 :
case V_46 :
case V_47 :
return V_31 -> V_48 ;
default:
return V_42 -> V_49 * V_31 -> V_48 / 8 ;
}
}
static int F_10 ( struct V_50 * V_51 ,
struct V_52 * V_53 , struct V_54 * V_55 ,
struct V_41 * * V_41 , struct V_30 * * V_30 )
{
struct V_41 * V_42 = NULL ;
struct V_30 * V_31 = NULL ;
T_2 V_56 , V_57 ;
unsigned int V_58 , V_59 ;
unsigned int V_33 ;
T_1 V_32 ;
int V_8 = 0 ;
T_3 * V_43 ;
if ( V_53 -> type != V_51 -> type )
return - V_24 ;
V_43 = ( T_3 * ) & V_53 -> V_53 . V_60 . V_61 ;
F_5 ( V_62 , L_3 ,
V_53 -> V_53 . V_60 . V_61 ,
V_43 [ 0 ] , V_43 [ 1 ] , V_43 [ 2 ] , V_43 [ 3 ] ,
V_53 -> V_53 . V_60 . V_63 , V_53 -> V_53 . V_60 . V_64 ) ;
for ( V_33 = 0 ; V_33 < V_51 -> V_65 ; ++ V_33 ) {
V_42 = & V_51 -> V_42 [ V_33 ] ;
if ( V_42 -> V_43 == V_53 -> V_53 . V_60 . V_61 )
break;
}
if ( V_33 == V_51 -> V_65 ) {
V_42 = V_51 -> V_66 ;
V_53 -> V_53 . V_60 . V_61 = V_42 -> V_43 ;
}
V_56 = V_53 -> V_53 . V_60 . V_63 ;
V_57 = V_53 -> V_53 . V_60 . V_64 ;
V_59 = ( unsigned int ) - 1 ;
for ( V_33 = 0 ; V_33 < V_42 -> V_67 ; ++ V_33 ) {
T_2 V_68 = V_42 -> V_31 [ V_33 ] . V_48 ;
T_2 V_69 = V_42 -> V_31 [ V_33 ] . V_70 ;
V_58 = V_38 ( V_68 , V_56 ) * V_38 ( V_69 , V_57 ) ;
V_58 = V_68 * V_69 + V_56 * V_57 - 2 * V_58 ;
if ( V_58 < V_59 ) {
V_59 = V_58 ;
V_31 = & V_42 -> V_31 [ V_33 ] ;
}
if ( V_59 == 0 )
break;
}
if ( V_31 == NULL ) {
F_5 ( V_62 , L_4 ,
V_53 -> V_53 . V_60 . V_63 , V_53 -> V_53 . V_60 . V_64 ) ;
return - V_24 ;
}
V_32 = V_31 -> V_71 ;
F_5 ( V_62 , L_5
L_6 , V_32 / 10 , V_32 % 10 , 10000000 / V_32 ,
( 100000000 / V_32 ) % 10 ) ;
memset ( V_55 , 0 , sizeof *V_55 ) ;
V_55 -> V_72 = 1 ;
V_55 -> V_73 = V_42 -> V_74 ;
V_55 -> V_75 = V_31 -> V_75 ;
V_55 -> V_37 = F_8 ( V_31 , V_32 ) ;
F_11 ( & V_51 -> V_76 ) ;
if ( V_51 -> V_77 -> V_78 & V_79 )
V_55 -> V_80 =
V_51 -> V_81 . V_80 ;
V_8 = F_12 ( V_51 , V_55 ) ;
F_13 ( & V_51 -> V_76 ) ;
if ( V_8 < 0 )
goto V_25;
V_53 -> V_53 . V_60 . V_63 = V_31 -> V_48 ;
V_53 -> V_53 . V_60 . V_64 = V_31 -> V_70 ;
V_53 -> V_53 . V_60 . V_82 = V_83 ;
V_53 -> V_53 . V_60 . V_84 = F_9 ( V_42 , V_31 ) ;
V_53 -> V_53 . V_60 . V_85 = V_55 -> V_80 ;
V_53 -> V_53 . V_60 . V_86 = V_42 -> V_86 ;
V_53 -> V_53 . V_60 . V_87 = 0 ;
if ( V_41 != NULL )
* V_41 = V_42 ;
if ( V_30 != NULL )
* V_30 = V_31 ;
V_25:
return V_8 ;
}
static int F_14 ( struct V_50 * V_51 ,
struct V_52 * V_53 )
{
struct V_41 * V_42 ;
struct V_30 * V_31 ;
int V_8 = 0 ;
if ( V_53 -> type != V_51 -> type )
return - V_24 ;
F_11 ( & V_51 -> V_76 ) ;
V_42 = V_51 -> V_88 ;
V_31 = V_51 -> V_89 ;
if ( V_42 == NULL || V_31 == NULL ) {
V_8 = - V_24 ;
goto V_25;
}
V_53 -> V_53 . V_60 . V_61 = V_42 -> V_43 ;
V_53 -> V_53 . V_60 . V_63 = V_31 -> V_48 ;
V_53 -> V_53 . V_60 . V_64 = V_31 -> V_70 ;
V_53 -> V_53 . V_60 . V_82 = V_83 ;
V_53 -> V_53 . V_60 . V_84 = F_9 ( V_42 , V_31 ) ;
V_53 -> V_53 . V_60 . V_85 = V_51 -> V_81 . V_80 ;
V_53 -> V_53 . V_60 . V_86 = V_42 -> V_86 ;
V_53 -> V_53 . V_60 . V_87 = 0 ;
V_25:
F_13 ( & V_51 -> V_76 ) ;
return V_8 ;
}
static int F_15 ( struct V_50 * V_51 ,
struct V_52 * V_53 )
{
struct V_54 V_55 ;
struct V_41 * V_42 ;
struct V_30 * V_31 ;
int V_8 ;
if ( V_53 -> type != V_51 -> type )
return - V_24 ;
V_8 = F_10 ( V_51 , V_53 , & V_55 , & V_42 , & V_31 ) ;
if ( V_8 < 0 )
return V_8 ;
F_11 ( & V_51 -> V_76 ) ;
if ( F_16 ( & V_51 -> V_90 ) ) {
V_8 = - V_91 ;
goto V_25;
}
V_51 -> V_81 = V_55 ;
V_51 -> V_88 = V_42 ;
V_51 -> V_89 = V_31 ;
V_25:
F_13 ( & V_51 -> V_76 ) ;
return V_8 ;
}
static int F_17 ( struct V_50 * V_51 ,
struct V_92 * V_93 )
{
T_4 V_94 , V_95 ;
if ( V_93 -> type != V_51 -> type )
return - V_24 ;
F_11 ( & V_51 -> V_76 ) ;
V_94 = V_51 -> V_81 . V_37 ;
F_13 ( & V_51 -> V_76 ) ;
V_95 = 10000000 ;
F_18 ( & V_94 , & V_95 , 8 , 333 ) ;
memset ( V_93 , 0 , sizeof *V_93 ) ;
V_93 -> type = V_51 -> type ;
if ( V_51 -> type == V_96 ) {
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
static int F_19 ( struct V_50 * V_51 ,
struct V_92 * V_93 )
{
struct V_54 V_55 ;
struct V_106 V_101 ;
T_4 V_32 ;
int V_8 ;
if ( V_93 -> type != V_51 -> type )
return - V_24 ;
if ( V_93 -> type == V_96 )
V_101 = V_93 -> V_93 . V_97 . V_101 ;
else
V_101 = V_93 -> V_93 . V_104 . V_101 ;
V_32 = F_20 ( V_101 . V_94 ,
V_101 . V_95 ) ;
F_5 ( V_62 , L_7 ,
V_101 . V_94 , V_101 . V_95 , V_32 ) ;
F_11 ( & V_51 -> V_76 ) ;
if ( F_21 ( & V_51 -> V_90 ) ) {
F_13 ( & V_51 -> V_76 ) ;
return - V_91 ;
}
V_55 = V_51 -> V_81 ;
V_55 . V_37 =
F_8 ( V_51 -> V_89 , V_32 ) ;
V_8 = F_12 ( V_51 , & V_55 ) ;
if ( V_8 < 0 ) {
F_13 ( & V_51 -> V_76 ) ;
return V_8 ;
}
V_51 -> V_81 = V_55 ;
F_13 ( & V_51 -> V_76 ) ;
V_101 . V_94 = V_55 . V_37 ;
V_101 . V_95 = 10000000 ;
F_18 ( & V_101 . V_94 ,
& V_101 . V_95 , 8 , 333 ) ;
if ( V_93 -> type == V_96 )
V_93 -> V_93 . V_97 . V_101 = V_101 ;
else
V_93 -> V_93 . V_104 . V_101 = V_101 ;
return 0 ;
}
static int F_22 ( struct V_107 * V_108 )
{
if ( V_108 -> V_109 == V_110 )
return 0 ;
if ( F_23 ( & V_108 -> V_51 -> V_111 ) != 1 ) {
F_24 ( & V_108 -> V_51 -> V_111 ) ;
return - V_91 ;
}
V_108 -> V_109 = V_110 ;
return 0 ;
}
static void F_25 ( struct V_107 * V_108 )
{
if ( V_108 -> V_109 == V_110 )
F_24 ( & V_108 -> V_51 -> V_111 ) ;
V_108 -> V_109 = V_112 ;
}
static int F_26 ( struct V_107 * V_108 )
{
return V_108 -> V_109 == V_110 ;
}
static int F_27 ( struct V_113 * V_113 )
{
struct V_50 * V_51 ;
struct V_107 * V_108 ;
int V_8 = 0 ;
F_5 ( V_114 , L_8 ) ;
V_51 = F_28 ( V_113 ) ;
V_8 = F_29 ( V_51 -> V_77 -> V_115 ) ;
if ( V_8 < 0 )
return V_8 ;
V_108 = F_2 ( sizeof *V_108 , V_9 ) ;
if ( V_108 == NULL ) {
F_30 ( V_51 -> V_77 -> V_115 ) ;
return - V_10 ;
}
F_11 ( & V_51 -> V_77 -> V_116 ) ;
if ( V_51 -> V_77 -> V_117 == 0 ) {
V_8 = F_31 ( V_51 -> V_77 , V_9 ) ;
if ( V_8 < 0 ) {
F_13 ( & V_51 -> V_77 -> V_116 ) ;
F_30 ( V_51 -> V_77 -> V_115 ) ;
F_7 ( V_108 ) ;
return V_8 ;
}
}
V_51 -> V_77 -> V_117 ++ ;
F_13 ( & V_51 -> V_77 -> V_116 ) ;
F_32 ( & V_108 -> V_118 , & V_51 -> V_119 ) ;
F_33 ( & V_108 -> V_118 ) ;
V_108 -> V_2 = V_51 -> V_2 ;
V_108 -> V_51 = V_51 ;
V_108 -> V_109 = V_112 ;
V_113 -> V_120 = V_108 ;
return 0 ;
}
static int F_34 ( struct V_113 * V_113 )
{
struct V_107 * V_108 = V_113 -> V_120 ;
struct V_50 * V_51 = V_108 -> V_51 ;
F_5 ( V_114 , L_9 ) ;
if ( F_26 ( V_108 ) )
F_35 ( & V_51 -> V_90 ) ;
F_25 ( V_108 ) ;
F_36 ( & V_108 -> V_118 ) ;
F_37 ( & V_108 -> V_118 ) ;
F_7 ( V_108 ) ;
V_113 -> V_120 = NULL ;
F_11 ( & V_51 -> V_77 -> V_116 ) ;
if ( -- V_51 -> V_77 -> V_117 == 0 )
F_38 ( V_51 -> V_77 ) ;
F_13 ( & V_51 -> V_77 -> V_116 ) ;
F_30 ( V_51 -> V_77 -> V_115 ) ;
return 0 ;
}
static int F_39 ( struct V_113 * V_113 , void * V_121 ,
struct V_122 * V_123 )
{
struct V_124 * V_119 = F_40 ( V_113 ) ;
struct V_107 * V_108 = V_113 -> V_120 ;
struct V_1 * V_2 = V_108 -> V_2 ;
struct V_50 * V_51 = V_108 -> V_51 ;
F_41 ( V_123 -> V_125 , L_10 , sizeof( V_123 -> V_125 ) ) ;
F_41 ( V_123 -> V_126 , V_119 -> V_12 , sizeof( V_123 -> V_126 ) ) ;
F_42 ( V_51 -> V_77 -> V_127 , V_123 -> V_128 , sizeof( V_123 -> V_128 ) ) ;
V_123 -> V_129 = V_130 | V_131
| V_2 -> V_132 ;
if ( V_51 -> type == V_96 )
V_123 -> V_133 = V_134 | V_131 ;
else
V_123 -> V_133 = V_135 | V_131 ;
return 0 ;
}
static int F_43 ( struct V_50 * V_51 ,
struct V_136 * V_53 )
{
struct V_41 * V_42 ;
enum V_137 type = V_53 -> type ;
T_1 V_74 = V_53 -> V_74 ;
if ( V_53 -> type != V_51 -> type || V_53 -> V_74 >= V_51 -> V_65 )
return - V_24 ;
memset ( V_53 , 0 , sizeof( * V_53 ) ) ;
V_53 -> V_74 = V_74 ;
V_53 -> type = type ;
V_42 = & V_51 -> V_42 [ V_53 -> V_74 ] ;
V_53 -> V_138 = 0 ;
if ( V_42 -> V_138 & V_139 )
V_53 -> V_138 |= V_140 ;
F_41 ( V_53 -> V_141 , V_42 -> V_12 , sizeof( V_53 -> V_141 ) ) ;
V_53 -> V_141 [ sizeof( V_53 -> V_141 ) - 1 ] = 0 ;
V_53 -> V_61 = V_42 -> V_43 ;
return 0 ;
}
static int F_44 ( struct V_113 * V_113 , void * V_121 ,
struct V_136 * V_53 )
{
struct V_107 * V_108 = V_121 ;
struct V_50 * V_51 = V_108 -> V_51 ;
return F_43 ( V_51 , V_53 ) ;
}
static int F_45 ( struct V_113 * V_113 , void * V_121 ,
struct V_136 * V_53 )
{
struct V_107 * V_108 = V_121 ;
struct V_50 * V_51 = V_108 -> V_51 ;
return F_43 ( V_51 , V_53 ) ;
}
static int F_46 ( struct V_113 * V_113 , void * V_121 ,
struct V_52 * V_53 )
{
struct V_107 * V_108 = V_121 ;
struct V_50 * V_51 = V_108 -> V_51 ;
return F_14 ( V_51 , V_53 ) ;
}
static int F_47 ( struct V_113 * V_113 , void * V_121 ,
struct V_52 * V_53 )
{
struct V_107 * V_108 = V_121 ;
struct V_50 * V_51 = V_108 -> V_51 ;
return F_14 ( V_51 , V_53 ) ;
}
static int F_48 ( struct V_113 * V_113 , void * V_121 ,
struct V_52 * V_53 )
{
struct V_107 * V_108 = V_121 ;
struct V_50 * V_51 = V_108 -> V_51 ;
int V_8 ;
V_8 = F_22 ( V_108 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_15 ( V_51 , V_53 ) ;
}
static int F_49 ( struct V_113 * V_113 , void * V_121 ,
struct V_52 * V_53 )
{
struct V_107 * V_108 = V_121 ;
struct V_50 * V_51 = V_108 -> V_51 ;
int V_8 ;
V_8 = F_22 ( V_108 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_15 ( V_51 , V_53 ) ;
}
static int F_50 ( struct V_113 * V_113 , void * V_121 ,
struct V_52 * V_53 )
{
struct V_107 * V_108 = V_121 ;
struct V_50 * V_51 = V_108 -> V_51 ;
struct V_54 V_55 ;
return F_10 ( V_51 , V_53 , & V_55 , NULL , NULL ) ;
}
static int F_51 ( struct V_113 * V_113 , void * V_121 ,
struct V_52 * V_53 )
{
struct V_107 * V_108 = V_121 ;
struct V_50 * V_51 = V_108 -> V_51 ;
struct V_54 V_55 ;
return F_10 ( V_51 , V_53 , & V_55 , NULL , NULL ) ;
}
static int F_52 ( struct V_113 * V_113 , void * V_121 ,
struct V_142 * V_143 )
{
struct V_107 * V_108 = V_121 ;
struct V_50 * V_51 = V_108 -> V_51 ;
int V_8 ;
V_8 = F_22 ( V_108 ) ;
if ( V_8 < 0 )
return V_8 ;
F_11 ( & V_51 -> V_76 ) ;
V_8 = F_53 ( & V_51 -> V_90 , V_143 ) ;
F_13 ( & V_51 -> V_76 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 == 0 )
F_25 ( V_108 ) ;
return 0 ;
}
static int F_54 ( struct V_113 * V_113 , void * V_121 ,
struct V_144 * V_145 )
{
struct V_107 * V_108 = V_121 ;
struct V_50 * V_51 = V_108 -> V_51 ;
if ( ! F_26 ( V_108 ) )
return - V_91 ;
return F_55 ( & V_51 -> V_90 , V_145 ) ;
}
static int F_56 ( struct V_113 * V_113 , void * V_121 , struct V_144 * V_145 )
{
struct V_107 * V_108 = V_121 ;
struct V_50 * V_51 = V_108 -> V_51 ;
if ( ! F_26 ( V_108 ) )
return - V_91 ;
return F_57 ( & V_51 -> V_90 , V_145 ) ;
}
static int F_58 ( struct V_113 * V_113 , void * V_121 ,
struct V_146 * exp )
{
struct V_107 * V_108 = V_121 ;
struct V_50 * V_51 = V_108 -> V_51 ;
if ( ! F_26 ( V_108 ) )
return - V_91 ;
return F_59 ( & V_51 -> V_90 , exp ) ;
}
static int F_60 ( struct V_113 * V_113 , void * V_121 , struct V_144 * V_145 )
{
struct V_107 * V_108 = V_121 ;
struct V_50 * V_51 = V_108 -> V_51 ;
if ( ! F_26 ( V_108 ) )
return - V_91 ;
return F_61 ( & V_51 -> V_90 , V_145 ,
V_113 -> V_147 & V_148 ) ;
}
static int F_62 ( struct V_113 * V_113 , void * V_121 ,
struct V_149 * V_150 )
{
struct V_107 * V_108 = V_121 ;
struct V_50 * V_51 = V_108 -> V_51 ;
int V_8 ;
V_8 = F_22 ( V_108 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_63 ( & V_51 -> V_90 , V_150 ) ;
}
static int F_64 ( struct V_113 * V_113 , void * V_121 ,
enum V_137 type )
{
struct V_107 * V_108 = V_121 ;
struct V_50 * V_51 = V_108 -> V_51 ;
int V_8 ;
if ( ! F_26 ( V_108 ) )
return - V_91 ;
F_11 ( & V_51 -> V_76 ) ;
V_8 = F_65 ( & V_51 -> V_90 , type ) ;
F_13 ( & V_51 -> V_76 ) ;
return V_8 ;
}
static int F_66 ( struct V_113 * V_113 , void * V_121 ,
enum V_137 type )
{
struct V_107 * V_108 = V_121 ;
struct V_50 * V_51 = V_108 -> V_51 ;
if ( ! F_26 ( V_108 ) )
return - V_91 ;
F_11 ( & V_51 -> V_76 ) ;
F_67 ( & V_51 -> V_90 , type ) ;
F_13 ( & V_51 -> V_76 ) ;
return 0 ;
}
static int F_68 ( struct V_113 * V_113 , void * V_121 ,
struct V_151 * V_152 )
{
struct V_107 * V_108 = V_121 ;
struct V_1 * V_2 = V_108 -> V_2 ;
const struct V_153 * V_14 = V_2 -> V_14 ;
struct V_153 * V_154 = NULL ;
T_5 V_74 = V_152 -> V_74 ;
int V_155 = 0 ;
if ( V_14 == NULL ||
( V_2 -> V_77 -> V_78 & V_156 ) ) {
if ( V_74 != 0 )
return - V_24 ;
F_69 (iterm, &chain->entities, chain) {
if ( F_70 ( V_154 ) )
break;
}
V_155 = V_154 -> V_11 ;
} else if ( V_74 < V_14 -> V_157 ) {
V_155 = V_14 -> V_158 [ V_74 ] ;
F_69 (iterm, &chain->entities, chain) {
if ( ! F_70 ( V_154 ) )
continue;
if ( V_154 -> V_11 == V_155 )
break;
}
}
if ( V_154 == NULL || V_154 -> V_11 != V_155 )
return - V_24 ;
memset ( V_152 , 0 , sizeof( * V_152 ) ) ;
V_152 -> V_74 = V_74 ;
F_41 ( V_152 -> V_12 , V_154 -> V_12 , sizeof( V_152 -> V_12 ) ) ;
if ( F_71 ( V_154 ) == V_159 )
V_152 -> type = V_160 ;
return 0 ;
}
static int F_72 ( struct V_113 * V_113 , void * V_121 , unsigned int * V_152 )
{
struct V_107 * V_108 = V_121 ;
struct V_1 * V_2 = V_108 -> V_2 ;
int V_8 ;
T_6 V_33 ;
if ( V_2 -> V_14 == NULL ||
( V_2 -> V_77 -> V_78 & V_156 ) ) {
* V_152 = 0 ;
return 0 ;
}
V_8 = F_73 ( V_2 -> V_77 , V_161 , V_2 -> V_14 -> V_11 ,
V_2 -> V_77 -> V_162 , V_163 ,
& V_33 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
* V_152 = V_33 - 1 ;
return 0 ;
}
static int F_74 ( struct V_113 * V_113 , void * V_121 , unsigned int V_152 )
{
struct V_107 * V_108 = V_121 ;
struct V_1 * V_2 = V_108 -> V_2 ;
int V_8 ;
T_5 V_33 ;
V_8 = F_22 ( V_108 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_2 -> V_14 == NULL ||
( V_2 -> V_77 -> V_78 & V_156 ) ) {
if ( V_152 )
return - V_24 ;
return 0 ;
}
if ( V_152 >= V_2 -> V_14 -> V_157 )
return - V_24 ;
V_33 = V_152 + 1 ;
return F_73 ( V_2 -> V_77 , V_164 , V_2 -> V_14 -> V_11 ,
V_2 -> V_77 -> V_162 , V_163 ,
& V_33 , 1 ) ;
}
static int F_75 ( struct V_113 * V_113 , void * V_121 ,
struct V_165 * V_166 )
{
struct V_107 * V_108 = V_121 ;
struct V_1 * V_2 = V_108 -> V_2 ;
return F_76 ( V_2 , V_166 ) ;
}
static int F_77 ( struct V_113 * V_113 , void * V_121 ,
struct V_167 * V_168 )
{
struct V_107 * V_108 = V_121 ;
struct V_1 * V_2 = V_108 -> V_2 ;
struct V_165 V_166 = { V_168 -> V_11 } ;
int V_8 ;
V_8 = F_76 ( V_2 , & V_166 ) ;
if ( V_8 )
return V_8 ;
V_168 -> V_11 = V_166 . V_11 ;
V_168 -> type = V_166 . type ;
F_41 ( V_168 -> V_12 , V_166 . V_12 , sizeof( V_168 -> V_12 ) ) ;
V_168 -> V_169 = V_166 . V_169 ;
V_168 -> V_170 = V_166 . V_170 ;
V_168 -> V_40 = V_166 . V_40 ;
V_168 -> V_171 = V_166 . V_171 ;
V_168 -> V_138 = V_166 . V_138 ;
V_168 -> V_172 = 4 ;
V_168 -> V_173 = 1 ;
V_168 -> V_174 = 0 ;
memset ( V_168 -> V_175 , 0 , sizeof( V_168 -> V_175 ) ) ;
memset ( V_168 -> V_176 , 0 , sizeof( V_168 -> V_176 ) ) ;
return 0 ;
}
static int F_78 ( struct V_113 * V_113 , void * V_121 ,
struct V_177 * V_81 )
{
struct V_107 * V_108 = V_121 ;
struct V_1 * V_2 = V_108 -> V_2 ;
struct V_178 V_179 ;
int V_8 ;
memset ( & V_179 , 0 , sizeof( V_179 ) ) ;
V_179 . V_11 = V_81 -> V_11 ;
V_8 = F_79 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_80 ( V_2 , & V_179 ) ;
F_81 ( V_108 ) ;
if ( V_8 < 0 )
return V_8 ;
V_81 -> V_180 = V_179 . V_180 ;
return 0 ;
}
static int F_82 ( struct V_113 * V_113 , void * V_121 ,
struct V_177 * V_81 )
{
struct V_107 * V_108 = V_121 ;
struct V_1 * V_2 = V_108 -> V_2 ;
struct V_178 V_179 ;
int V_8 ;
memset ( & V_179 , 0 , sizeof( V_179 ) ) ;
V_179 . V_11 = V_81 -> V_11 ;
V_179 . V_180 = V_81 -> V_180 ;
V_8 = F_79 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_83 ( V_2 , & V_179 ) ;
if ( V_8 < 0 ) {
F_81 ( V_108 ) ;
return V_8 ;
}
V_8 = F_84 ( V_108 , & V_179 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
V_81 -> V_180 = V_179 . V_180 ;
return 0 ;
}
static int F_85 ( struct V_113 * V_113 , void * V_121 ,
struct V_181 * V_182 )
{
struct V_107 * V_108 = V_121 ;
struct V_1 * V_2 = V_108 -> V_2 ;
struct V_178 * V_81 = V_182 -> V_183 ;
unsigned int V_33 ;
int V_8 ;
if ( V_182 -> V_184 == V_185 ) {
for ( V_33 = 0 ; V_33 < V_182 -> V_186 ; ++ V_81 , ++ V_33 ) {
struct V_165 V_166 = { . V_11 = V_81 -> V_11 } ;
V_8 = F_76 ( V_2 , & V_166 ) ;
if ( V_8 < 0 ) {
V_182 -> V_187 = V_33 ;
return V_8 ;
}
V_81 -> V_180 = V_166 . V_171 ;
}
return 0 ;
}
V_8 = F_79 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
for ( V_33 = 0 ; V_33 < V_182 -> V_186 ; ++ V_81 , ++ V_33 ) {
V_8 = F_80 ( V_2 , V_81 ) ;
if ( V_8 < 0 ) {
F_81 ( V_108 ) ;
V_182 -> V_187 = V_33 ;
return V_8 ;
}
}
V_182 -> V_187 = 0 ;
return F_81 ( V_108 ) ;
}
static int F_86 ( struct V_107 * V_108 ,
struct V_181 * V_182 ,
bool V_188 )
{
struct V_178 * V_81 = V_182 -> V_183 ;
struct V_1 * V_2 = V_108 -> V_2 ;
unsigned int V_33 ;
int V_8 ;
if ( V_182 -> V_184 == V_185 )
return - V_24 ;
V_8 = F_79 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
for ( V_33 = 0 ; V_33 < V_182 -> V_186 ; ++ V_81 , ++ V_33 ) {
V_8 = F_83 ( V_2 , V_81 ) ;
if ( V_8 < 0 ) {
F_81 ( V_108 ) ;
V_182 -> V_187 = V_188 ? V_182 -> V_186 : V_33 ;
return V_8 ;
}
}
V_182 -> V_187 = 0 ;
if ( V_188 )
return F_84 ( V_108 , V_182 -> V_183 , V_182 -> V_186 ) ;
else
return F_81 ( V_108 ) ;
}
static int F_87 ( struct V_113 * V_113 , void * V_121 ,
struct V_181 * V_182 )
{
struct V_107 * V_108 = V_121 ;
return F_86 ( V_108 , V_182 , true ) ;
}
static int F_88 ( struct V_113 * V_113 , void * V_121 ,
struct V_181 * V_182 )
{
struct V_107 * V_108 = V_121 ;
return F_86 ( V_108 , V_182 , false ) ;
}
static int F_89 ( struct V_113 * V_113 , void * V_121 ,
struct V_189 * V_190 )
{
struct V_107 * V_108 = V_121 ;
struct V_1 * V_2 = V_108 -> V_2 ;
return F_90 ( V_2 , V_190 ) ;
}
static int F_91 ( struct V_113 * V_113 , void * V_121 ,
struct V_191 * V_192 )
{
struct V_107 * V_108 = V_121 ;
struct V_50 * V_51 = V_108 -> V_51 ;
if ( V_192 -> type != V_51 -> type )
return - V_24 ;
switch ( V_192 -> V_193 ) {
case V_194 :
case V_195 :
if ( V_51 -> type != V_96 )
return - V_24 ;
break;
case V_196 :
case V_197 :
if ( V_51 -> type != V_198 )
return - V_24 ;
break;
default:
return - V_24 ;
}
V_192 -> V_199 . V_200 = 0 ;
V_192 -> V_199 . V_201 = 0 ;
F_11 ( & V_51 -> V_76 ) ;
V_192 -> V_199 . V_63 = V_51 -> V_89 -> V_48 ;
V_192 -> V_199 . V_64 = V_51 -> V_89 -> V_70 ;
F_13 ( & V_51 -> V_76 ) ;
return 0 ;
}
static int F_92 ( struct V_113 * V_113 , void * V_121 ,
struct V_92 * V_93 )
{
struct V_107 * V_108 = V_121 ;
struct V_50 * V_51 = V_108 -> V_51 ;
return F_17 ( V_51 , V_93 ) ;
}
static int F_93 ( struct V_113 * V_113 , void * V_121 ,
struct V_92 * V_93 )
{
struct V_107 * V_108 = V_121 ;
struct V_50 * V_51 = V_108 -> V_51 ;
int V_8 ;
V_8 = F_22 ( V_108 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_19 ( V_51 , V_93 ) ;
}
static int F_94 ( struct V_113 * V_113 , void * V_121 ,
struct V_202 * V_203 )
{
struct V_107 * V_108 = V_121 ;
struct V_50 * V_51 = V_108 -> V_51 ;
struct V_41 * V_42 = NULL ;
struct V_30 * V_31 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_51 -> V_65 ; V_33 ++ ) {
if ( V_51 -> V_42 [ V_33 ] . V_43 == V_203 -> V_204 ) {
V_42 = & V_51 -> V_42 [ V_33 ] ;
break;
}
}
if ( V_42 == NULL )
return - V_24 ;
if ( V_203 -> V_74 >= V_42 -> V_67 )
return - V_24 ;
V_31 = & V_42 -> V_31 [ V_203 -> V_74 ] ;
V_203 -> type = V_205 ;
V_203 -> V_206 . V_63 = V_31 -> V_48 ;
V_203 -> V_206 . V_64 = V_31 -> V_70 ;
return 0 ;
}
static int F_95 ( struct V_113 * V_113 , void * V_121 ,
struct V_207 * V_208 )
{
struct V_107 * V_108 = V_121 ;
struct V_50 * V_51 = V_108 -> V_51 ;
struct V_41 * V_42 = NULL ;
struct V_30 * V_31 = NULL ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_51 -> V_65 ; V_33 ++ ) {
if ( V_51 -> V_42 [ V_33 ] . V_43 == V_208 -> V_204 ) {
V_42 = & V_51 -> V_42 [ V_33 ] ;
break;
}
}
if ( V_42 == NULL )
return - V_24 ;
for ( V_33 = 0 ; V_33 < V_42 -> V_67 ; V_33 ++ ) {
if ( V_42 -> V_31 [ V_33 ] . V_48 == V_208 -> V_63 &&
V_42 -> V_31 [ V_33 ] . V_70 == V_208 -> V_64 ) {
V_31 = & V_42 -> V_31 [ V_33 ] ;
break;
}
}
if ( V_31 == NULL )
return - V_24 ;
if ( V_31 -> V_34 ) {
if ( V_208 -> V_74 >= V_31 -> V_34 )
return - V_24 ;
V_208 -> type = V_209 ;
V_208 -> V_206 . V_94 =
V_31 -> V_37 [ V_208 -> V_74 ] ;
V_208 -> V_206 . V_95 = 10000000 ;
F_18 ( & V_208 -> V_206 . V_94 ,
& V_208 -> V_206 . V_95 , 8 , 333 ) ;
} else {
if ( V_208 -> V_74 )
return - V_24 ;
V_208 -> type = V_210 ;
V_208 -> V_211 . V_38 . V_94 = V_31 -> V_37 [ 0 ] ;
V_208 -> V_211 . V_38 . V_95 = 10000000 ;
V_208 -> V_211 . V_39 . V_94 = V_31 -> V_37 [ 1 ] ;
V_208 -> V_211 . V_39 . V_95 = 10000000 ;
V_208 -> V_211 . V_40 . V_94 = V_31 -> V_37 [ 2 ] ;
V_208 -> V_211 . V_40 . V_95 = 10000000 ;
F_18 ( & V_208 -> V_211 . V_38 . V_94 ,
& V_208 -> V_211 . V_38 . V_95 , 8 , 333 ) ;
F_18 ( & V_208 -> V_211 . V_39 . V_94 ,
& V_208 -> V_211 . V_39 . V_95 , 8 , 333 ) ;
F_18 ( & V_208 -> V_211 . V_40 . V_94 ,
& V_208 -> V_211 . V_40 . V_95 , 8 , 333 ) ;
}
return 0 ;
}
static int F_96 ( struct V_212 * V_121 ,
const struct V_213 * V_214 )
{
switch ( V_214 -> type ) {
case V_215 :
return F_97 ( V_121 , V_214 , 0 , & V_216 ) ;
default:
return - V_24 ;
}
}
static long F_98 ( struct V_113 * V_113 , void * V_121 , bool V_217 ,
unsigned int V_218 , void * V_219 )
{
struct V_107 * V_108 = V_121 ;
struct V_1 * V_2 = V_108 -> V_2 ;
switch ( V_218 ) {
case V_220 :
return F_1 ( V_2 , V_219 ) ;
case V_221 :
return F_99 ( V_2 , V_219 ) ;
default:
return - V_29 ;
}
}
static int F_100 ( struct V_3 * V_222 ,
const struct V_223 T_7 * V_224 )
{
T_8 V_225 ;
if ( ! F_101 ( V_226 , V_224 , sizeof( * V_224 ) ) ||
F_102 ( V_222 , V_224 , F_103 ( F_104 ( * V_224 ) , V_26 ) ) ||
F_105 ( V_222 -> V_22 , & V_224 -> V_22 ) )
return - V_27 ;
memset ( V_222 -> V_176 , 0 , sizeof( V_222 -> V_176 ) ) ;
if ( V_222 -> V_22 == 0 ) {
V_222 -> V_26 = NULL ;
return 0 ;
}
if ( F_105 ( V_225 , & V_224 -> V_26 ) )
return - V_27 ;
V_222 -> V_26 = F_106 ( V_225 ) ;
return 0 ;
}
static int F_107 ( const struct V_3 * V_222 ,
struct V_223 T_7 * V_224 )
{
if ( ! F_101 ( V_227 , V_224 , sizeof( * V_224 ) ) ||
F_108 ( V_224 , V_222 , F_103 ( F_104 ( * V_224 ) , V_26 ) ) ||
F_109 ( V_222 -> V_22 , & V_224 -> V_22 ) )
return - V_27 ;
if ( F_110 ( V_224 -> V_176 , sizeof( V_224 -> V_176 ) ) )
return - V_27 ;
return 0 ;
}
static int F_111 ( struct V_228 * V_222 ,
const struct V_229 T_7 * V_224 )
{
T_8 V_225 ;
if ( ! F_101 ( V_226 , V_224 , sizeof( * V_224 ) ) ||
F_102 ( V_222 , V_224 , F_103 ( F_104 ( * V_224 ) , V_230 ) ) )
return - V_27 ;
if ( V_222 -> V_7 == 0 ) {
V_222 -> V_230 = NULL ;
return 0 ;
}
if ( F_105 ( V_225 , & V_224 -> V_230 ) )
return - V_27 ;
V_222 -> V_230 = F_106 ( V_225 ) ;
return 0 ;
}
static int F_112 ( const struct V_228 * V_222 ,
struct V_229 T_7 * V_224 )
{
if ( ! F_101 ( V_227 , V_224 , sizeof( * V_224 ) ) ||
F_108 ( V_224 , V_222 , F_103 ( F_104 ( * V_224 ) , V_230 ) ) )
return - V_27 ;
return 0 ;
}
static long F_113 ( struct V_113 * V_113 ,
unsigned int V_218 , unsigned long V_219 )
{
struct V_107 * V_108 = V_113 -> V_120 ;
union {
struct V_3 V_4 ;
struct V_228 V_231 ;
} V_232 ;
void T_7 * V_224 = F_106 ( V_219 ) ;
long V_8 ;
switch ( V_218 ) {
case V_233 :
V_8 = F_100 ( & V_232 . V_4 , V_224 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_1 ( V_108 -> V_2 , & V_232 . V_4 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_107 ( & V_232 . V_4 , V_224 ) ;
if ( V_8 )
return V_8 ;
break;
case V_234 :
V_8 = F_111 ( & V_232 . V_231 , V_224 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_99 ( V_108 -> V_2 , & V_232 . V_231 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_112 ( & V_232 . V_231 , V_224 ) ;
if ( V_8 )
return V_8 ;
break;
default:
return - V_235 ;
}
return V_8 ;
}
static T_9 F_114 ( struct V_113 * V_113 , char T_7 * V_230 ,
T_10 V_186 , T_11 * V_236 )
{
F_5 ( V_114 , L_11 ) ;
return - V_24 ;
}
static int F_115 ( struct V_113 * V_113 , struct V_237 * V_238 )
{
struct V_107 * V_108 = V_113 -> V_120 ;
struct V_50 * V_51 = V_108 -> V_51 ;
F_5 ( V_114 , L_12 ) ;
return F_116 ( & V_51 -> V_90 , V_238 ) ;
}
static unsigned int F_117 ( struct V_113 * V_113 , T_12 * V_239 )
{
struct V_107 * V_108 = V_113 -> V_120 ;
struct V_50 * V_51 = V_108 -> V_51 ;
F_5 ( V_114 , L_13 ) ;
return F_118 ( & V_51 -> V_90 , V_113 , V_239 ) ;
}
static unsigned long F_119 ( struct V_113 * V_113 ,
unsigned long V_240 , unsigned long V_241 , unsigned long V_242 ,
unsigned long V_138 )
{
struct V_107 * V_108 = V_113 -> V_120 ;
struct V_50 * V_51 = V_108 -> V_51 ;
F_5 ( V_114 , L_14 ) ;
return F_120 ( & V_51 -> V_90 , V_242 ) ;
}
