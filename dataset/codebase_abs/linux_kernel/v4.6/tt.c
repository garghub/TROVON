static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
T_1 V_6 = V_4 -> V_7 . V_8 ;
if ( F_2 ( V_9 , & V_2 -> V_10 ) )
return;
F_3 ( V_2 , L_1 ) ;
F_4 ( V_2 , true ) ;
if ( ! F_5 ( V_2 ) ) {
V_4 -> V_11 = false ;
V_4 -> V_12 = false ;
}
if ( ! V_2 -> V_13 )
F_6 ( & V_4 -> V_14 ,
F_7 ( V_6 * V_15 ) ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_9 , & V_2 -> V_10 ) )
return;
F_3 ( V_2 , L_2 ) ;
F_4 ( V_2 , false ) ;
}
void F_9 ( struct V_1 * V_2 , T_1 V_16 )
{
if ( V_2 -> V_13 )
return;
if ( V_2 -> V_17 == V_16 )
return;
V_2 -> V_17 = V_16 ;
F_10 ( V_2 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_20 * V_21 ;
int V_22 = F_12 ( V_19 ) ;
int V_16 ;
if ( F_13 ( V_22 < sizeof( * V_21 ) ) ) {
F_3 ( V_2 , L_3 ) ;
return - V_23 ;
}
V_21 = ( void * ) V_19 -> V_24 ;
V_16 = F_14 ( V_21 -> V_16 ) ;
if ( F_13 ( V_16 < 0 ) )
V_16 = 0 ;
F_15 ( V_2 , L_4 , V_16 ) ;
return V_16 ;
}
static bool F_16 ( struct V_25 * V_26 ,
struct V_18 * V_19 , void * V_24 )
{
struct V_1 * V_2 =
F_17 ( V_26 , struct V_1 , V_26 ) ;
int * V_16 = V_24 ;
int V_27 ;
V_27 = F_11 ( V_2 , V_19 ) ;
if ( V_27 < 0 )
return true ;
* V_16 = V_27 ;
return true ;
}
void F_18 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_18 * V_19 = F_19 ( V_29 ) ;
struct V_30 * V_31 ;
int V_22 = F_12 ( V_19 ) ;
int V_16 ;
T_1 V_32 ;
if ( F_2 ( V_9 , & V_2 -> V_10 ) )
return;
V_16 = F_11 ( V_2 , V_19 ) ;
if ( ! F_5 ( V_2 ) ) {
if ( V_16 >= 0 )
F_9 ( V_2 , V_16 ) ;
return;
}
if ( F_13 ( V_22 < sizeof( * V_31 ) ) ) {
F_3 ( V_2 , L_3 ) ;
return;
}
V_31 = ( void * ) V_19 -> V_24 ;
V_32 = F_14 ( V_31 -> V_33 ) ;
if ( V_32 == 0xFF )
return;
F_15 ( V_2 , L_5 ,
V_16 , V_32 ) ;
#ifdef F_20
if ( F_21 ( V_32 >= V_34 ) )
return;
if ( V_2 -> V_35 . V_36 ) {
struct V_37 * V_38 = & V_2 -> V_35 ;
F_22 ( & V_2 -> V_39 ) ;
F_23 ( V_38 -> V_36 ,
V_38 -> V_40 [ V_32 ] ) ;
F_24 ( & V_2 -> V_39 ) ;
}
#endif
}
void F_25 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_18 * V_19 = F_19 ( V_29 ) ;
struct V_41 * V_42 ;
int V_22 = F_12 ( V_19 ) ;
if ( F_13 ( V_22 != sizeof( * V_42 ) ) ) {
F_3 ( V_2 , L_6 ) ;
return;
}
V_42 = (struct V_41 * ) V_19 -> V_24 ;
F_15 ( V_2 , L_7 ,
V_42 -> V_17 ) ;
F_1 ( V_2 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_43 V_44 = {
. V_45 = F_27 ( V_46 ) ,
} ;
struct V_47 V_48 = {
. V_49 = F_27 ( V_50 ) ,
} ;
T_1 V_51 ;
if ( F_28 ( & V_2 -> V_52 -> V_53 , V_54 ) )
V_51 = F_29 ( V_55 ,
V_56 , 0 ) ;
else
V_51 = V_57 ;
if ( ! F_30 ( & V_2 -> V_52 -> V_53 ,
V_58 ) )
return F_31 ( V_2 , V_51 , 0 , sizeof( V_44 ) , & V_44 ) ;
return F_31 ( V_2 , V_51 , 0 , sizeof( V_48 ) , & V_48 ) ;
}
int F_32 ( struct V_1 * V_2 , T_2 * V_16 )
{
struct V_59 V_60 ;
static T_3 V_61 [] = { F_33 (PHY_OPS_GROUP,
DTS_MEASUREMENT_NOTIF_WIDE) } ;
int V_27 ;
if ( ! F_28 ( & V_2 -> V_52 -> V_53 , V_54 ) )
V_61 [ 0 ] = V_62 ;
F_34 ( & V_2 -> V_39 ) ;
F_35 ( & V_2 -> V_26 , & V_60 ,
V_61 , F_36 ( V_61 ) ,
F_16 , V_16 ) ;
V_27 = F_26 ( V_2 ) ;
if ( V_27 ) {
F_3 ( V_2 , L_8 , V_27 ) ;
F_37 ( & V_2 -> V_26 , & V_60 ) ;
return V_27 ;
}
V_27 = F_38 ( & V_2 -> V_26 , & V_60 ,
V_63 ) ;
if ( V_27 )
F_3 ( V_2 , L_9 ) ;
return V_27 ;
}
static void F_39 ( struct V_64 * V_65 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
T_1 V_6 ;
T_2 V_16 ;
int V_27 ;
V_4 = F_17 ( V_65 , struct V_3 , V_14 . V_65 ) ;
V_2 = F_17 ( V_4 , struct V_1 , V_5 ) ;
if ( F_5 ( V_2 ) ) {
F_8 ( V_2 ) ;
return;
}
V_6 = V_4 -> V_7 . V_8 ;
F_24 ( & V_2 -> V_39 ) ;
if ( F_40 ( V_2 ) )
goto V_66;
if ( F_41 ( V_2 , V_67 ) ) {
F_42 ( V_2 ) ;
goto V_66;
}
V_27 = F_32 ( V_2 , & V_16 ) ;
F_43 ( V_2 , V_67 ) ;
F_42 ( V_2 ) ;
if ( V_27 )
goto V_66;
F_15 ( V_2 , L_10 , V_16 ) ;
if ( V_16 <= V_4 -> V_7 . V_14 ) {
F_22 ( & V_2 -> V_39 ) ;
F_8 ( V_2 ) ;
return;
}
V_66:
F_22 ( & V_2 -> V_39 ) ;
F_6 ( & V_2 -> V_5 . V_14 ,
F_44 ( V_6 * V_15 ) ) ;
}
static void F_45 ( void * V_68 , T_4 * V_69 ,
struct V_70 * V_71 )
{
struct V_1 * V_2 = V_68 ;
enum V_72 V_73 ;
F_34 ( & V_2 -> V_39 ) ;
if ( V_2 -> V_5 . V_12 )
V_73 = V_74 ;
else
V_73 = V_75 ;
if ( V_71 -> type != V_76 )
return;
F_46 ( V_2 , V_71 , V_77 , V_73 ) ;
}
static void F_47 ( struct V_1 * V_2 , bool V_78 )
{
struct V_79 * V_80 ;
struct V_81 * V_82 ;
int V_83 , V_84 ;
for ( V_83 = 0 ; V_83 < V_85 ; V_83 ++ ) {
V_80 = F_48 ( V_2 -> V_86 [ V_83 ] ,
F_49 ( & V_2 -> V_39 ) ) ;
if ( F_50 ( V_80 ) )
continue;
V_82 = F_51 ( V_80 ) ;
if ( V_78 == V_82 -> V_87 )
continue;
V_84 = F_52 ( V_2 , V_82 , V_78 ) ;
if ( V_84 ) {
F_3 ( V_2 , L_11 ,
V_78 ? L_12 : L_13 ) ;
} else {
F_15 ( V_2 , L_14 ,
V_78 ? L_15 : L_16 ) ;
V_82 -> V_87 = V_78 ;
}
}
}
void F_53 ( struct V_1 * V_2 , T_1 V_88 )
{
struct V_89 V_44 = {
. V_90 = V_91 ,
. V_22 = { sizeof( T_1 ) , } ,
. V_24 = { & V_88 , } ,
} ;
V_88 = F_54 ( V_88 , V_2 -> V_5 . V_92 ) ;
if ( F_55 ( V_2 , & V_44 ) == 0 ) {
F_15 ( V_2 , L_17 ,
V_88 ) ;
V_2 -> V_5 . V_93 = V_88 ;
} else {
F_3 ( V_2 , L_18 ) ;
}
}
void F_10 ( struct V_1 * V_2 )
{
struct V_94 * V_7 = & V_2 -> V_5 . V_7 ;
struct V_3 * V_4 = & V_2 -> V_5 ;
T_2 V_17 = V_2 -> V_17 ;
bool V_95 = false ;
int V_83 ;
T_1 V_93 ;
F_15 ( V_2 , L_10 , V_2 -> V_17 ) ;
if ( V_7 -> V_96 && V_17 >= V_7 -> V_97 ) {
F_1 ( V_2 ) ;
return;
}
if ( V_7 -> V_96 &&
V_17 <= V_7 -> V_14 ) {
F_8 ( V_2 ) ;
return;
}
if ( V_7 -> V_98 ) {
if ( ! V_4 -> V_12 &&
V_17 >= V_7 -> V_99 ) {
F_15 ( V_2 , L_19 ) ;
V_4 -> V_12 = true ;
F_56 (
V_2 -> V_100 , V_101 ,
F_45 , V_2 ) ;
V_95 = true ;
} else if ( V_4 -> V_12 &&
V_17 <= V_7 -> V_102 ) {
F_15 ( V_2 , L_20 ) ;
V_4 -> V_12 = false ;
F_56 (
V_2 -> V_100 , V_101 ,
F_45 , V_2 ) ;
}
}
if ( V_7 -> V_103 ) {
if ( V_17 >= V_7 -> V_104 ) {
F_47 ( V_2 , true ) ;
V_95 = true ;
} else if ( V_17 <= V_7 -> V_105 ) {
F_47 ( V_2 , false ) ;
}
}
if ( V_7 -> V_106 ) {
V_93 = V_4 -> V_92 ;
for ( V_83 = 0 ; V_83 < V_107 ; V_83 ++ ) {
if ( V_17 < V_7 -> V_93 [ V_83 ] . V_17 )
break;
V_93 = F_54 ( V_4 -> V_92 ,
V_7 -> V_93 [ V_83 ] . V_88 ) ;
}
if ( V_93 != V_4 -> V_92 )
V_95 = true ;
if ( V_4 -> V_93 != V_93 )
F_53 ( V_2 , V_93 ) ;
}
if ( ! V_4 -> V_11 && V_95 ) {
F_57 ( V_2 ,
L_21 ) ;
V_4 -> V_11 = true ;
} else if ( V_4 -> V_11 && ! V_4 -> V_12 &&
V_4 -> V_93 == V_4 -> V_92 &&
V_17 <= V_7 -> V_105 ) {
F_57 ( V_2 ,
L_22 ) ;
V_4 -> V_11 = false ;
}
}
int F_58 ( struct V_1 * V_2 , T_1 V_108 , T_1 V_109 )
{
struct V_110 V_44 = {
. V_111 = F_27 ( V_108 ) ,
. V_112 = F_27 ( V_113 [ V_109 ] ) ,
. V_114 = 0 ,
} ;
int V_27 ;
T_1 V_10 ;
F_34 ( & V_2 -> V_39 ) ;
V_27 = F_59 ( V_2 , F_33 ( V_56 ,
V_115 ) ,
sizeof( V_44 ) , & V_44 , & V_10 ) ;
if ( V_27 ) {
F_3 ( V_2 , L_23 , V_27 ) ;
return V_27 ;
}
switch ( V_108 ) {
case V_116 :
#ifdef F_20
V_2 -> V_117 . V_118 = V_109 ;
#endif
break;
case V_119 :
F_15 ( V_2 , L_24 , V_10 ) ;
return V_10 ;
case V_120 :
F_15 ( V_2 , L_25 ) ;
break;
}
return 0 ;
}
static int F_60 ( const void * V_121 , const void * V_122 )
{
return ( ( V_123 ) F_61 ( * ( V_124 * ) V_121 ) -
( V_123 ) F_61 ( * ( V_124 * ) V_122 ) ) ;
}
int F_62 ( struct V_1 * V_2 )
{
struct V_125 V_44 = { 0 } ;
int V_27 , V_83 , V_126 , V_127 = 0 ;
F_34 ( & V_2 -> V_39 ) ;
if ( ! V_2 -> V_35 . V_36 )
return - V_23 ;
for ( V_83 = 0 ; V_83 < V_34 ; V_83 ++ ) {
if ( V_2 -> V_35 . V_128 [ V_83 ] != V_129 ) {
V_44 . V_130 [ V_127 ++ ] =
F_63 ( V_2 -> V_35 . V_128 [ V_83 ] ) ;
}
}
V_44 . V_131 = F_27 ( V_127 ) ;
if ( ! V_127 )
goto V_132;
F_64 ( V_44 . V_130 , V_127 , sizeof( V_123 ) , F_60 , NULL ) ;
for ( V_83 = 0 ; V_83 < V_127 ; V_83 ++ ) {
for ( V_126 = 0 ; V_126 < V_34 ; V_126 ++ ) {
if ( F_61 ( V_44 . V_130 [ V_83 ] ) ==
V_2 -> V_35 . V_128 [ V_126 ] )
V_2 -> V_35 . V_40 [ V_83 ] = V_126 ;
}
}
V_132:
V_27 = F_31 ( V_2 , F_33 ( V_56 ,
V_133 ) ,
0 , sizeof( V_44 ) , & V_44 ) ;
if ( V_27 )
F_3 ( V_2 , L_26 ,
V_27 ) ;
return V_27 ;
}
static int F_65 ( struct V_134 * V_135 ,
int * V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_135 -> V_136 ;
int V_27 ;
int V_16 ;
F_24 ( & V_2 -> V_39 ) ;
if ( ! V_2 -> V_137 || ! ( V_2 -> V_138 == V_139 ) ) {
V_27 = - V_140 ;
goto V_141;
}
V_27 = F_32 ( V_2 , & V_16 ) ;
if ( V_27 )
goto V_141;
* V_17 = V_16 * 1000 ;
V_141:
F_22 ( & V_2 -> V_39 ) ;
return V_27 ;
}
static int F_66 ( struct V_134 * V_135 ,
int V_142 , int * V_16 )
{
struct V_1 * V_2 = (struct V_1 * ) V_135 -> V_136 ;
if ( V_142 < 0 || V_142 >= V_34 )
return - V_23 ;
* V_16 = V_2 -> V_35 . V_128 [ V_142 ] * 1000 ;
return 0 ;
}
static int F_67 ( struct V_134 * V_135 ,
int V_142 , enum V_143 * type )
{
if ( V_142 < 0 || V_142 >= V_34 )
return - V_23 ;
* type = V_144 ;
return 0 ;
}
static int F_68 ( struct V_134 * V_135 ,
int V_142 , int V_16 )
{
struct V_1 * V_2 = (struct V_1 * ) V_135 -> V_136 ;
struct V_37 * V_36 ;
int V_83 , V_27 ;
V_123 V_17 ;
F_24 ( & V_2 -> V_39 ) ;
if ( ! V_2 -> V_137 || ! ( V_2 -> V_138 == V_139 ) ) {
V_27 = - V_140 ;
goto V_141;
}
if ( V_142 < 0 || V_142 >= V_34 ) {
V_27 = - V_23 ;
goto V_141;
}
if ( ( V_16 / 1000 ) > V_145 ) {
V_27 = - V_23 ;
goto V_141;
}
V_17 = ( V_123 ) ( V_16 / 1000 ) ;
V_36 = & V_2 -> V_35 ;
if ( ! V_36 ) {
V_27 = - V_140 ;
goto V_141;
}
if ( V_36 -> V_128 [ V_142 ] == V_17 ) {
V_27 = 0 ;
goto V_141;
}
for ( V_83 = 0 ; V_83 < V_34 ; V_83 ++ ) {
if ( V_36 -> V_128 [ V_83 ] == V_17 ) {
V_27 = - V_23 ;
goto V_141;
}
}
V_36 -> V_128 [ V_142 ] = V_17 ;
V_27 = F_62 ( V_2 ) ;
V_141:
F_22 ( & V_2 -> V_39 ) ;
return V_27 ;
}
static void F_69 ( struct V_1 * V_2 )
{
int V_83 ;
char V_146 [] = L_27 ;
if ( ! F_5 ( V_2 ) ) {
V_2 -> V_35 . V_36 = NULL ;
return;
}
F_70 ( F_36 ( V_146 ) >= V_147 ) ;
V_2 -> V_35 . V_36 = F_71 ( V_146 ,
V_34 ,
V_148 ,
V_2 , & V_149 ,
NULL , 0 , 0 ) ;
if ( F_72 ( V_2 -> V_35 . V_36 ) ) {
F_15 ( V_2 ,
L_28 ,
F_73 ( V_2 -> V_35 . V_36 ) ) ;
V_2 -> V_35 . V_36 = NULL ;
return;
}
for ( V_83 = 0 ; V_83 < V_34 ; V_83 ++ )
V_2 -> V_35 . V_128 [ V_83 ] = V_129 ;
}
static int F_74 ( struct V_150 * V_151 ,
unsigned long * V_109 )
{
* V_109 = F_36 ( V_113 ) - 1 ;
return 0 ;
}
static int F_75 ( struct V_150 * V_151 ,
unsigned long * V_109 )
{
struct V_1 * V_2 = (struct V_1 * ) ( V_151 -> V_136 ) ;
if ( F_2 ( V_152 , & V_2 -> V_10 ) )
return - V_153 ;
* V_109 = V_2 -> V_117 . V_118 ;
return 0 ;
}
static int F_76 ( struct V_150 * V_151 ,
unsigned long V_154 )
{
struct V_1 * V_2 = (struct V_1 * ) ( V_151 -> V_136 ) ;
int V_27 ;
if ( ! V_2 -> V_137 || ! ( V_2 -> V_138 == V_139 ) )
return - V_140 ;
if ( F_2 ( V_152 , & V_2 -> V_10 ) )
return - V_153 ;
F_24 ( & V_2 -> V_39 ) ;
if ( V_154 >= F_36 ( V_113 ) ) {
V_27 = - V_23 ;
goto V_155;
}
V_27 = F_58 ( V_2 , V_116 ,
V_154 ) ;
V_155:
F_22 ( & V_2 -> V_39 ) ;
return V_27 ;
}
static void F_77 ( struct V_1 * V_2 )
{
char V_146 [] = L_27 ;
if ( ! F_78 ( V_2 ) )
return;
F_70 ( F_36 ( V_146 ) >= V_147 ) ;
V_2 -> V_117 . V_151 =
F_79 ( V_146 ,
V_2 ,
& V_156 ) ;
if ( F_72 ( V_2 -> V_117 . V_151 ) ) {
F_15 ( V_2 ,
L_29 ,
F_73 ( V_2 -> V_117 . V_151 ) ) ;
V_2 -> V_117 . V_151 = NULL ;
return;
}
}
static void F_80 ( struct V_1 * V_2 )
{
if ( ! F_5 ( V_2 ) || ! V_2 -> V_35 . V_36 )
return;
F_15 ( V_2 , L_30 ) ;
F_81 ( V_2 -> V_35 . V_36 ) ;
V_2 -> V_35 . V_36 = NULL ;
}
static void F_82 ( struct V_1 * V_2 )
{
if ( ! F_78 ( V_2 ) || ! V_2 -> V_117 . V_151 )
return;
F_15 ( V_2 , L_31 ) ;
F_83 ( V_2 -> V_117 . V_151 ) ;
V_2 -> V_117 . V_151 = NULL ;
}
void F_84 ( struct V_1 * V_2 , T_1 V_92 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
F_15 ( V_2 , L_32 ) ;
if ( V_2 -> V_157 -> V_158 )
V_4 -> V_7 = * V_2 -> V_157 -> V_158 ;
else
V_4 -> V_7 = V_159 ;
V_4 -> V_11 = false ;
V_4 -> V_12 = false ;
V_4 -> V_92 = V_92 ;
F_85 ( & V_4 -> V_14 , F_39 ) ;
#ifdef F_20
F_77 ( V_2 ) ;
F_69 ( V_2 ) ;
#endif
}
void F_86 ( struct V_1 * V_2 )
{
F_87 ( & V_2 -> V_5 . V_14 ) ;
F_15 ( V_2 , L_33 ) ;
#ifdef F_20
F_82 ( V_2 ) ;
F_80 ( V_2 ) ;
#endif
}
