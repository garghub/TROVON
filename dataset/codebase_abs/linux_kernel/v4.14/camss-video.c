static int F_1 ( T_1 V_1 , T_1 V_2 ,
const struct V_3 * V_4 ,
unsigned int V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
if ( V_4 [ V_6 ] . V_1 == V_1 &&
V_4 [ V_6 ] . V_2 == V_2 )
return V_6 ;
}
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ )
if ( V_4 [ V_6 ] . V_1 == V_1 )
return V_6 ;
F_2 ( 1 ) ;
return - V_7 ;
}
static int F_3 ( const struct V_8 * V_9 ,
struct V_10 * V_11 ,
const struct V_3 * V_12 ,
unsigned int V_13 )
{
unsigned int V_6 ;
T_1 V_14 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
F_4 ( V_11 , V_9 ) ;
V_11 -> V_2 = V_12 -> V_2 ;
V_11 -> V_15 = V_12 -> V_16 ;
for ( V_6 = 0 ; V_6 < V_11 -> V_15 ; V_6 ++ ) {
V_14 = V_11 -> V_17 / V_12 -> V_18 [ V_6 ] . V_19 *
V_12 -> V_18 [ V_6 ] . V_20 * V_12 -> V_21 [ V_6 ] / 8 ;
V_14 = F_5 ( V_14 , V_13 ) ;
V_11 -> V_22 [ V_6 ] . V_14 = V_14 ;
V_11 -> V_22 [ V_6 ] . V_23 = V_11 -> V_24 /
V_12 -> V_25 [ V_6 ] . V_19 * V_12 -> V_25 [ V_6 ] . V_20 *
V_14 ;
}
return 0 ;
}
static struct V_26 * F_6 ( struct V_27 * V_28 ,
T_1 * V_29 )
{
struct V_30 * V_31 ;
V_31 = F_7 ( & V_28 -> V_29 ) ;
if ( ! V_31 || ! F_8 ( V_31 -> V_32 ) )
return NULL ;
if ( V_29 )
* V_29 = V_31 -> V_33 ;
return F_9 ( V_31 -> V_32 ) ;
}
static int F_10 ( struct V_27 * V_28 ,
struct V_34 * V_35 )
{
struct V_36 V_37 ;
struct V_26 * V_38 ;
T_1 V_29 ;
int V_39 ;
V_38 = F_6 ( V_28 , & V_29 ) ;
if ( V_38 == NULL )
return - V_40 ;
V_37 . V_29 = V_29 ;
V_37 . V_41 = V_42 ;
V_39 = F_11 ( V_38 , V_29 , V_43 , NULL , & V_37 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_1 ( V_37 . V_35 . V_1 ,
V_35 -> V_37 . V_44 . V_2 ,
V_28 -> V_4 , V_28 -> V_5 ) ;
if ( V_39 < 0 )
return V_39 ;
V_35 -> type = V_28 -> type ;
return F_3 ( & V_37 . V_35 , & V_35 -> V_37 . V_44 ,
& V_28 -> V_4 [ V_39 ] , V_28 -> V_45 ) ;
}
static int F_12 ( struct V_46 * V_47 ,
unsigned int * V_48 , unsigned int * V_15 ,
unsigned int V_49 [] , struct V_50 * V_51 [] )
{
struct V_27 * V_28 = F_13 ( V_47 ) ;
const struct V_10 * V_35 =
& V_28 -> V_52 . V_37 . V_44 ;
unsigned int V_6 ;
if ( * V_15 ) {
if ( * V_15 != V_35 -> V_15 )
return - V_7 ;
for ( V_6 = 0 ; V_6 < * V_15 ; V_6 ++ )
if ( V_49 [ V_6 ] < V_35 -> V_22 [ V_6 ] . V_23 )
return - V_7 ;
return 0 ;
}
* V_15 = V_35 -> V_15 ;
for ( V_6 = 0 ; V_6 < * V_15 ; V_6 ++ )
V_49 [ V_6 ] = V_35 -> V_22 [ V_6 ] . V_23 ;
return 0 ;
}
static int F_14 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = F_15 ( V_54 ) ;
struct V_27 * V_28 = F_13 ( V_54 -> V_46 ) ;
struct V_57 * V_58 = F_16 ( V_56 , struct V_57 ,
V_54 ) ;
const struct V_10 * V_35 =
& V_28 -> V_52 . V_37 . V_44 ;
struct V_59 * V_60 ;
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_35 -> V_15 ; V_6 ++ ) {
V_60 = F_17 ( V_54 , V_6 ) ;
if ( ! V_60 )
return - V_61 ;
V_58 -> V_62 [ V_6 ] = F_18 ( V_60 -> V_63 ) ;
}
if ( V_35 -> V_2 == V_64 ||
V_35 -> V_2 == V_65 ||
V_35 -> V_2 == V_66 ||
V_35 -> V_2 == V_67 )
V_58 -> V_62 [ 1 ] = V_58 -> V_62 [ 0 ] +
V_35 -> V_22 [ 0 ] . V_14 *
V_35 -> V_24 ;
return 0 ;
}
static int F_19 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = F_15 ( V_54 ) ;
struct V_27 * V_28 = F_13 ( V_54 -> V_46 ) ;
const struct V_10 * V_35 =
& V_28 -> V_52 . V_37 . V_44 ;
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_35 -> V_15 ; V_6 ++ ) {
if ( V_35 -> V_22 [ V_6 ] . V_23 > F_20 ( V_54 , V_6 ) )
return - V_7 ;
F_21 ( V_54 , V_6 , V_35 -> V_22 [ V_6 ] . V_23 ) ;
}
V_56 -> V_68 = V_69 ;
return 0 ;
}
static void F_22 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = F_15 ( V_54 ) ;
struct V_27 * V_28 = F_13 ( V_54 -> V_46 ) ;
struct V_57 * V_58 = F_16 ( V_56 , struct V_57 ,
V_54 ) ;
V_28 -> V_70 -> V_71 ( V_28 , V_58 ) ;
}
static int F_23 ( struct V_27 * V_28 )
{
struct V_10 * V_11 = & V_28 -> V_52 . V_37 . V_44 ;
struct V_34 V_35 ;
struct V_10 * V_72 = & V_35 . V_37 . V_44 ;
int V_39 ;
V_72 -> V_2 = V_11 -> V_2 ;
V_39 = F_10 ( V_28 , & V_35 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_11 -> V_2 != V_72 -> V_2 ||
V_11 -> V_24 != V_72 -> V_24 ||
V_11 -> V_17 != V_72 -> V_17 ||
V_11 -> V_15 != V_72 -> V_15 ||
V_11 -> V_68 != V_35 . V_37 . V_44 . V_68 )
return - V_40 ;
return 0 ;
}
static int F_24 ( struct V_46 * V_47 , unsigned int V_73 )
{
struct V_27 * V_28 = F_13 ( V_47 ) ;
struct V_74 * V_75 = & V_28 -> V_75 ;
struct V_76 * V_32 ;
struct V_30 * V_29 ;
struct V_26 * V_38 ;
int V_39 ;
V_39 = F_25 ( & V_75 -> V_32 , & V_28 -> V_77 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_23 ( V_28 ) ;
if ( V_39 < 0 )
goto error;
V_32 = & V_75 -> V_32 ;
while ( 1 ) {
V_29 = & V_32 -> V_78 [ 0 ] ;
if ( ! ( V_29 -> V_79 & V_80 ) )
break;
V_29 = F_7 ( V_29 ) ;
if ( ! V_29 || ! F_8 ( V_29 -> V_32 ) )
break;
V_32 = V_29 -> V_32 ;
V_38 = F_9 ( V_32 ) ;
V_39 = F_11 ( V_38 , V_28 , V_81 , 1 ) ;
if ( V_39 < 0 && V_39 != - V_82 )
goto error;
}
return 0 ;
error:
F_26 ( & V_75 -> V_32 ) ;
V_28 -> V_70 -> V_83 ( V_28 , V_84 ) ;
return V_39 ;
}
static void F_27 ( struct V_46 * V_47 )
{
struct V_27 * V_28 = F_13 ( V_47 ) ;
struct V_74 * V_75 = & V_28 -> V_75 ;
struct V_76 * V_32 ;
struct V_30 * V_29 ;
struct V_26 * V_38 ;
V_32 = & V_75 -> V_32 ;
while ( 1 ) {
V_29 = & V_32 -> V_78 [ 0 ] ;
if ( ! ( V_29 -> V_79 & V_80 ) )
break;
V_29 = F_7 ( V_29 ) ;
if ( ! V_29 || ! F_8 ( V_29 -> V_32 ) )
break;
V_32 = V_29 -> V_32 ;
V_38 = F_9 ( V_32 ) ;
F_11 ( V_38 , V_28 , V_81 , 0 ) ;
}
F_26 ( & V_75 -> V_32 ) ;
V_28 -> V_70 -> V_83 ( V_28 , V_85 ) ;
}
static int F_28 ( struct V_86 * V_86 , void * V_87 ,
struct V_88 * V_89 )
{
struct V_27 * V_28 = F_29 ( V_86 ) ;
F_30 ( V_89 -> V_90 , L_1 , sizeof( V_89 -> V_90 ) ) ;
F_30 ( V_89 -> V_91 , L_2 , sizeof( V_89 -> V_91 ) ) ;
snprintf ( V_89 -> V_92 , sizeof( V_89 -> V_92 ) , L_3 ,
F_31 ( V_28 -> V_93 -> V_94 ) ) ;
return 0 ;
}
static int F_32 ( struct V_86 * V_86 , void * V_87 , struct V_95 * V_12 )
{
struct V_27 * V_28 = F_29 ( V_86 ) ;
int V_6 , V_96 , V_97 ;
if ( V_12 -> type != V_28 -> type )
return - V_7 ;
if ( V_12 -> V_33 >= V_28 -> V_5 )
return - V_7 ;
V_97 = - 1 ;
for ( V_6 = 0 ; V_6 < V_28 -> V_5 ; V_6 ++ ) {
for ( V_96 = 0 ; V_96 < V_6 ; V_96 ++ ) {
if ( V_28 -> V_4 [ V_6 ] . V_2 ==
V_28 -> V_4 [ V_96 ] . V_2 )
break;
}
if ( V_96 == V_6 )
V_97 ++ ;
if ( V_97 == V_12 -> V_33 )
break;
}
if ( V_97 < V_12 -> V_33 )
return - V_7 ;
V_12 -> V_2 = V_28 -> V_4 [ V_6 ] . V_2 ;
return 0 ;
}
static int F_33 ( struct V_86 * V_86 , void * V_87 , struct V_34 * V_12 )
{
struct V_27 * V_28 = F_29 ( V_86 ) ;
* V_12 = V_28 -> V_52 ;
return 0 ;
}
static int F_34 ( struct V_27 * V_28 , struct V_34 * V_12 )
{
struct V_10 * V_44 ;
const struct V_3 * V_98 ;
struct V_99 * V_100 ;
T_1 V_14 [ 3 ] = { 0 } ;
T_1 V_23 [ 3 ] = { 0 } ;
T_1 V_17 , V_24 ;
T_1 V_101 , V_102 ;
int V_6 , V_96 ;
V_44 = & V_12 -> V_37 . V_44 ;
if ( V_28 -> V_103 )
for ( V_6 = 0 ; V_6 < V_44 -> V_15 && V_6 < 3 ; V_6 ++ ) {
V_100 = & V_44 -> V_22 [ V_6 ] ;
V_14 [ V_6 ] = F_35 ( T_1 , V_100 -> V_14 ,
1 , 65528 ) ;
V_23 [ V_6 ] = F_35 ( T_1 , V_100 -> V_23 ,
V_14 [ V_6 ] ,
V_14 [ V_6 ] * 4096 ) ;
}
for ( V_96 = 0 ; V_96 < V_28 -> V_5 ; V_96 ++ )
if ( V_44 -> V_2 == V_28 -> V_4 [ V_96 ] . V_2 )
break;
if ( V_96 == V_28 -> V_5 )
V_96 = 0 ;
V_98 = & V_28 -> V_4 [ V_96 ] ;
V_17 = V_44 -> V_17 ;
V_24 = V_44 -> V_24 ;
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
V_44 -> V_2 = V_98 -> V_2 ;
V_44 -> V_17 = F_35 ( T_1 , V_17 , 1 , 8191 ) ;
V_44 -> V_24 = F_35 ( T_1 , V_24 , 1 , 8191 ) ;
V_44 -> V_15 = V_98 -> V_16 ;
for ( V_6 = 0 ; V_6 < V_44 -> V_15 ; V_6 ++ ) {
V_101 = V_44 -> V_17 / V_98 -> V_18 [ V_6 ] . V_19 *
V_98 -> V_18 [ V_6 ] . V_20 * V_98 -> V_21 [ V_6 ] / 8 ;
V_101 = F_5 ( V_101 , V_28 -> V_45 ) ;
V_44 -> V_22 [ V_6 ] . V_14 = V_101 ;
V_44 -> V_22 [ V_6 ] . V_23 = V_44 -> V_24 /
V_98 -> V_25 [ V_6 ] . V_19 * V_98 -> V_25 [ V_6 ] . V_20 * V_101 ;
}
V_44 -> V_68 = V_69 ;
V_44 -> V_104 = V_105 ;
V_44 -> V_79 = 0 ;
V_44 -> V_106 = F_36 ( V_44 -> V_104 ) ;
V_44 -> V_107 = F_37 ( true ,
V_44 -> V_104 , V_44 -> V_106 ) ;
V_44 -> V_108 = F_38 ( V_44 -> V_104 ) ;
if ( V_28 -> V_103 )
for ( V_6 = 0 ; V_6 < V_44 -> V_15 ; V_6 ++ ) {
V_100 = & V_44 -> V_22 [ V_6 ] ;
V_100 -> V_14 = F_35 ( T_1 , V_100 -> V_14 ,
1 , 65528 ) ;
V_100 -> V_23 = F_35 ( T_1 , V_100 -> V_23 ,
V_100 -> V_14 ,
V_100 -> V_14 * 4096 ) ;
V_102 = V_100 -> V_23 / V_100 -> V_14 ;
if ( V_100 -> V_14 < V_14 [ V_6 ] )
V_100 -> V_14 = F_5 ( V_14 [ V_6 ] , 8 ) ;
if ( V_100 -> V_23 < V_100 -> V_14 * V_102 )
V_100 -> V_23 = V_100 -> V_14 * V_102 ;
if ( V_100 -> V_23 < V_23 [ V_6 ] )
V_100 -> V_23 = V_23 [ V_6 ] ;
}
return 0 ;
}
static int F_39 ( struct V_86 * V_86 , void * V_87 , struct V_34 * V_12 )
{
struct V_27 * V_28 = F_29 ( V_86 ) ;
return F_34 ( V_28 , V_12 ) ;
}
static int F_40 ( struct V_86 * V_86 , void * V_87 , struct V_34 * V_12 )
{
struct V_27 * V_28 = F_29 ( V_86 ) ;
int V_39 ;
if ( F_41 ( & V_28 -> V_109 ) )
return - V_110 ;
V_39 = F_34 ( V_28 , V_12 ) ;
if ( V_39 < 0 )
return V_39 ;
V_28 -> V_52 = * V_12 ;
return 0 ;
}
static int F_42 ( struct V_86 * V_86 , void * V_87 ,
struct V_111 * V_112 )
{
if ( V_112 -> V_33 > 0 )
return - V_7 ;
F_30 ( V_112 -> V_113 , L_4 , sizeof( V_112 -> V_113 ) ) ;
V_112 -> type = V_114 ;
return 0 ;
}
static int F_43 ( struct V_86 * V_86 , void * V_87 , unsigned int * V_112 )
{
* V_112 = 0 ;
return 0 ;
}
static int F_44 ( struct V_86 * V_86 , void * V_87 , unsigned int V_112 )
{
return V_112 == 0 ? 0 : - V_7 ;
}
static int F_45 ( struct V_86 * V_86 )
{
struct V_74 * V_75 = F_46 ( V_86 ) ;
struct V_27 * V_28 = F_29 ( V_86 ) ;
struct V_115 * V_116 ;
int V_39 ;
F_47 ( & V_28 -> V_117 ) ;
V_116 = F_48 ( sizeof( * V_116 ) , V_118 ) ;
if ( V_116 == NULL ) {
V_39 = - V_119 ;
goto V_120;
}
F_49 ( V_116 , V_75 ) ;
F_50 ( V_116 ) ;
V_86 -> V_121 = V_116 ;
V_39 = F_51 ( & V_75 -> V_32 , 1 ) ;
if ( V_39 < 0 ) {
F_52 ( V_28 -> V_93 -> V_94 , L_5 ,
V_39 ) ;
goto V_122;
}
F_53 ( & V_28 -> V_117 ) ;
return 0 ;
V_122:
F_54 ( V_86 ) ;
V_120:
F_53 ( & V_28 -> V_117 ) ;
return V_39 ;
}
static int F_55 ( struct V_86 * V_86 )
{
struct V_74 * V_75 = F_46 ( V_86 ) ;
F_56 ( V_86 ) ;
F_51 ( & V_75 -> V_32 , 0 ) ;
V_86 -> V_121 = NULL ;
return 0 ;
}
static void F_57 ( struct V_74 * V_75 )
{
struct V_27 * V_28 = F_58 ( V_75 ) ;
F_59 ( & V_75 -> V_32 ) ;
F_60 ( & V_28 -> V_123 ) ;
F_60 ( & V_28 -> V_117 ) ;
if ( F_61 ( & V_28 -> V_93 -> V_124 ) )
F_62 ( V_28 -> V_93 ) ;
}
static int F_63 ( struct V_27 * V_28 )
{
int V_39 ;
struct V_34 V_35 = {
. type = V_125 ,
. V_37 . V_44 = {
. V_17 = 1920 ,
. V_24 = 1080 ,
. V_2 = V_28 -> V_4 [ 0 ] . V_2 ,
} ,
} ;
V_39 = F_34 ( V_28 , & V_35 ) ;
if ( V_39 < 0 )
return V_39 ;
V_28 -> V_52 = V_35 ;
return 0 ;
}
int F_64 ( struct V_27 * V_28 , struct V_126 * V_127 ,
const char * V_113 , int V_128 )
{
struct V_30 * V_29 = & V_28 -> V_29 ;
struct V_74 * V_75 ;
struct V_46 * V_47 ;
int V_39 ;
V_75 = & V_28 -> V_75 ;
F_65 ( & V_28 -> V_123 ) ;
V_47 = & V_28 -> V_109 ;
V_47 -> V_129 = V_28 ;
V_47 -> V_130 = & V_131 ;
V_47 -> V_70 = & V_132 ;
V_47 -> type = V_125 ;
V_47 -> V_133 = V_134 | V_135 | V_136 ;
V_47 -> V_137 = V_138 ;
V_47 -> V_139 = sizeof( struct V_57 ) ;
V_47 -> V_94 = V_28 -> V_93 -> V_94 ;
V_47 -> V_117 = & V_28 -> V_123 ;
V_39 = F_66 ( V_47 ) ;
if ( V_39 < 0 ) {
F_52 ( V_127 -> V_94 , L_6 , V_39 ) ;
goto V_140;
}
V_29 -> V_79 = V_80 ;
V_39 = F_67 ( & V_75 -> V_32 , 1 , V_29 ) ;
if ( V_39 < 0 ) {
F_52 ( V_127 -> V_94 , L_7 ,
V_39 ) ;
goto V_141;
}
F_65 ( & V_28 -> V_117 ) ;
V_28 -> V_4 = V_142 ;
V_28 -> V_5 = F_68 ( V_142 ) ;
if ( V_128 ) {
V_28 -> V_4 = V_143 ;
V_28 -> V_5 = F_68 ( V_143 ) ;
}
V_39 = F_63 ( V_28 ) ;
if ( V_39 < 0 ) {
F_52 ( V_127 -> V_94 , L_8 , V_39 ) ;
goto V_144;
}
V_75 -> V_145 = & V_146 ;
V_75 -> V_147 = V_148 | V_149 |
V_150 ;
V_75 -> V_151 = & V_152 ;
V_75 -> V_153 = F_57 ;
V_75 -> V_127 = V_127 ;
V_75 -> V_154 = V_155 ;
V_75 -> V_156 = & V_28 -> V_109 ;
V_75 -> V_117 = & V_28 -> V_117 ;
F_30 ( V_75 -> V_113 , V_113 , sizeof( V_75 -> V_113 ) ) ;
V_39 = F_69 ( V_75 , V_157 , - 1 ) ;
if ( V_39 < 0 ) {
F_52 ( V_127 -> V_94 , L_9 ,
V_39 ) ;
goto V_144;
}
F_70 ( V_75 , V_28 ) ;
F_71 ( & V_28 -> V_93 -> V_124 ) ;
return 0 ;
V_144:
F_59 ( & V_75 -> V_32 ) ;
F_60 ( & V_28 -> V_117 ) ;
V_141:
F_72 ( & V_28 -> V_109 ) ;
V_140:
F_60 ( & V_28 -> V_123 ) ;
return V_39 ;
}
void F_73 ( struct V_27 * V_28 )
{
if ( F_74 ( & V_28 -> V_109 ) )
F_72 ( & V_28 -> V_109 ) ;
}
void F_75 ( struct V_27 * V_28 )
{
F_71 ( & V_28 -> V_93 -> V_124 ) ;
F_76 ( & V_28 -> V_75 ) ;
F_77 ( & V_28 -> V_93 -> V_124 ) ;
}
