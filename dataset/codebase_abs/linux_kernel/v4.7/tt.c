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
F_22 ( V_38 -> V_36 ,
V_38 -> V_39 [ V_32 ] ) ;
}
#endif
}
void F_23 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_18 * V_19 = F_19 ( V_29 ) ;
struct V_40 * V_41 ;
int V_22 = F_12 ( V_19 ) ;
if ( F_13 ( V_22 != sizeof( * V_41 ) ) ) {
F_3 ( V_2 , L_6 ) ;
return;
}
V_41 = (struct V_40 * ) V_19 -> V_24 ;
F_15 ( V_2 , L_7 ,
V_41 -> V_17 ) ;
F_1 ( V_2 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_42 V_43 = {
. V_44 = F_25 ( V_45 ) ,
} ;
struct V_46 V_47 = {
. V_48 = F_25 ( V_49 ) ,
} ;
T_1 V_50 ;
if ( F_26 ( & V_2 -> V_51 -> V_52 , V_53 ) )
V_50 = F_27 ( V_54 ,
V_55 , 0 ) ;
else
V_50 = V_56 ;
if ( ! F_28 ( & V_2 -> V_51 -> V_52 ,
V_57 ) )
return F_29 ( V_2 , V_50 , 0 , sizeof( V_43 ) , & V_43 ) ;
return F_29 ( V_2 , V_50 , 0 , sizeof( V_47 ) , & V_47 ) ;
}
int F_30 ( struct V_1 * V_2 , T_2 * V_16 )
{
struct V_58 V_59 ;
static T_3 V_60 [] = { F_31 (PHY_OPS_GROUP,
DTS_MEASUREMENT_NOTIF_WIDE) } ;
int V_27 ;
if ( ! F_26 ( & V_2 -> V_51 -> V_52 , V_53 ) )
V_60 [ 0 ] = V_61 ;
F_32 ( & V_2 -> V_62 ) ;
F_33 ( & V_2 -> V_26 , & V_59 ,
V_60 , F_34 ( V_60 ) ,
F_16 , V_16 ) ;
V_27 = F_24 ( V_2 ) ;
if ( V_27 ) {
F_3 ( V_2 , L_8 , V_27 ) ;
F_35 ( & V_2 -> V_26 , & V_59 ) ;
return V_27 ;
}
V_27 = F_36 ( & V_2 -> V_26 , & V_59 ,
V_63 ) ;
if ( V_27 )
F_3 ( V_2 , L_9 ) ;
return V_27 ;
}
static void F_37 ( struct V_64 * V_65 )
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
F_38 ( & V_2 -> V_62 ) ;
if ( F_39 ( V_2 ) )
goto V_66;
if ( F_40 ( V_2 , V_67 ) ) {
F_41 ( V_2 ) ;
goto V_66;
}
V_27 = F_30 ( V_2 , & V_16 ) ;
F_42 ( V_2 , V_67 ) ;
F_41 ( V_2 ) ;
if ( V_27 )
goto V_66;
F_15 ( V_2 , L_10 , V_16 ) ;
if ( V_16 <= V_4 -> V_7 . V_14 ) {
F_43 ( & V_2 -> V_62 ) ;
F_8 ( V_2 ) ;
return;
}
V_66:
F_43 ( & V_2 -> V_62 ) ;
F_6 ( & V_2 -> V_5 . V_14 ,
F_44 ( V_6 * V_15 ) ) ;
}
static void F_45 ( void * V_68 , T_4 * V_69 ,
struct V_70 * V_71 )
{
struct V_1 * V_2 = V_68 ;
enum V_72 V_73 ;
F_32 ( & V_2 -> V_62 ) ;
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
int V_81 , V_82 ;
for ( V_81 = 0 ; V_81 < V_83 ; V_81 ++ ) {
V_80 = F_48 ( V_2 , V_81 ) ;
if ( ! V_80 )
continue;
if ( V_78 == V_80 -> V_84 )
continue;
V_82 = F_49 ( V_2 , V_80 , V_78 ) ;
if ( V_82 ) {
F_3 ( V_2 , L_11 ,
V_78 ? L_12 : L_13 ) ;
} else {
F_15 ( V_2 , L_14 ,
V_78 ? L_15 : L_16 ) ;
V_80 -> V_84 = V_78 ;
}
}
}
void F_50 ( struct V_1 * V_2 , T_1 V_85 )
{
struct V_86 V_43 = {
. V_87 = V_88 ,
. V_22 = { sizeof( T_1 ) , } ,
. V_24 = { & V_85 , } ,
} ;
V_85 = F_51 ( V_85 , V_2 -> V_5 . V_89 ) ;
if ( F_52 ( V_2 , & V_43 ) == 0 ) {
F_15 ( V_2 , L_17 ,
V_85 ) ;
V_2 -> V_5 . V_90 = V_85 ;
} else {
F_3 ( V_2 , L_18 ) ;
}
}
void F_10 ( struct V_1 * V_2 )
{
struct V_91 * V_7 = & V_2 -> V_5 . V_7 ;
struct V_3 * V_4 = & V_2 -> V_5 ;
T_2 V_17 = V_2 -> V_17 ;
bool V_92 = false ;
int V_81 ;
T_1 V_90 ;
F_15 ( V_2 , L_10 , V_2 -> V_17 ) ;
if ( V_7 -> V_93 && V_17 >= V_7 -> V_94 ) {
F_1 ( V_2 ) ;
return;
}
if ( V_7 -> V_93 &&
V_17 <= V_7 -> V_14 ) {
F_8 ( V_2 ) ;
return;
}
if ( V_7 -> V_95 ) {
if ( ! V_4 -> V_12 &&
V_17 >= V_7 -> V_96 ) {
F_15 ( V_2 , L_19 ) ;
V_4 -> V_12 = true ;
F_53 (
V_2 -> V_97 , V_98 ,
F_45 , V_2 ) ;
V_92 = true ;
} else if ( V_4 -> V_12 &&
V_17 <= V_7 -> V_99 ) {
F_15 ( V_2 , L_20 ) ;
V_4 -> V_12 = false ;
F_53 (
V_2 -> V_97 , V_98 ,
F_45 , V_2 ) ;
}
}
if ( V_7 -> V_100 ) {
if ( V_17 >= V_7 -> V_101 ) {
F_47 ( V_2 , true ) ;
V_92 = true ;
} else if ( V_17 <= V_7 -> V_102 ) {
F_47 ( V_2 , false ) ;
}
}
if ( V_7 -> V_103 ) {
V_90 = V_4 -> V_89 ;
for ( V_81 = 0 ; V_81 < V_104 ; V_81 ++ ) {
if ( V_17 < V_7 -> V_90 [ V_81 ] . V_17 )
break;
V_90 = F_51 ( V_4 -> V_89 ,
V_7 -> V_90 [ V_81 ] . V_85 ) ;
}
if ( V_90 != V_4 -> V_89 )
V_92 = true ;
if ( V_4 -> V_90 != V_90 )
F_50 ( V_2 , V_90 ) ;
}
if ( ! V_4 -> V_11 && V_92 ) {
F_54 ( V_2 ,
L_21 ) ;
V_4 -> V_11 = true ;
} else if ( V_4 -> V_11 && ! V_4 -> V_12 &&
V_4 -> V_90 == V_4 -> V_89 &&
V_17 <= V_7 -> V_102 ) {
F_54 ( V_2 ,
L_22 ) ;
V_4 -> V_11 = false ;
}
}
int F_55 ( struct V_1 * V_2 , T_1 V_105 , T_1 V_106 )
{
struct V_107 V_43 = {
. V_108 = F_25 ( V_105 ) ,
. V_109 = F_25 ( V_110 [ V_106 ] ) ,
. V_111 = 0 ,
} ;
int V_27 ;
T_1 V_10 ;
F_32 ( & V_2 -> V_62 ) ;
V_27 = F_56 ( V_2 , F_31 ( V_55 ,
V_112 ) ,
sizeof( V_43 ) , & V_43 , & V_10 ) ;
if ( V_27 ) {
F_3 ( V_2 , L_23 , V_27 ) ;
return V_27 ;
}
switch ( V_105 ) {
case V_113 :
#ifdef F_20
V_2 -> V_114 . V_115 = V_106 ;
#endif
break;
case V_116 :
F_15 ( V_2 , L_24 , V_10 ) ;
return V_10 ;
case V_117 :
F_15 ( V_2 , L_25 ) ;
break;
}
return 0 ;
}
static int F_57 ( const void * V_118 , const void * V_119 )
{
return ( ( V_120 ) F_58 ( * ( V_121 * ) V_118 ) -
( V_120 ) F_58 ( * ( V_121 * ) V_119 ) ) ;
}
int F_59 ( struct V_1 * V_2 )
{
struct V_122 V_43 = { 0 } ;
int V_27 , V_81 , V_123 , V_124 = 0 ;
F_32 ( & V_2 -> V_62 ) ;
if ( ! V_2 -> V_35 . V_36 )
return - V_23 ;
for ( V_81 = 0 ; V_81 < V_34 ; V_81 ++ ) {
if ( V_2 -> V_35 . V_125 [ V_81 ] != V_126 ) {
V_43 . V_127 [ V_124 ++ ] =
F_60 ( V_2 -> V_35 . V_125 [ V_81 ] ) ;
}
}
V_43 . V_128 = F_25 ( V_124 ) ;
if ( ! V_124 )
goto V_129;
F_61 ( V_43 . V_127 , V_124 , sizeof( V_120 ) , F_57 , NULL ) ;
for ( V_81 = 0 ; V_81 < V_124 ; V_81 ++ ) {
for ( V_123 = 0 ; V_123 < V_34 ; V_123 ++ ) {
if ( F_58 ( V_43 . V_127 [ V_81 ] ) ==
V_2 -> V_35 . V_125 [ V_123 ] )
V_2 -> V_35 . V_39 [ V_81 ] = V_123 ;
}
}
V_129:
V_27 = F_29 ( V_2 , F_31 ( V_55 ,
V_130 ) ,
0 , sizeof( V_43 ) , & V_43 ) ;
if ( V_27 )
F_3 ( V_2 , L_26 ,
V_27 ) ;
return V_27 ;
}
static int F_62 ( struct V_131 * V_132 ,
int * V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_132 -> V_133 ;
int V_27 ;
int V_16 ;
F_38 ( & V_2 -> V_62 ) ;
if ( ! V_2 -> V_134 || ! ( V_2 -> V_135 == V_136 ) ) {
V_27 = - V_137 ;
goto V_138;
}
V_27 = F_30 ( V_2 , & V_16 ) ;
if ( V_27 )
goto V_138;
* V_17 = V_16 * 1000 ;
V_138:
F_43 ( & V_2 -> V_62 ) ;
return V_27 ;
}
static int F_63 ( struct V_131 * V_132 ,
int V_139 , int * V_16 )
{
struct V_1 * V_2 = (struct V_1 * ) V_132 -> V_133 ;
if ( V_139 < 0 || V_139 >= V_34 )
return - V_23 ;
* V_16 = V_2 -> V_35 . V_125 [ V_139 ] * 1000 ;
return 0 ;
}
static int F_64 ( struct V_131 * V_132 ,
int V_139 , enum V_140 * type )
{
if ( V_139 < 0 || V_139 >= V_34 )
return - V_23 ;
* type = V_141 ;
return 0 ;
}
static int F_65 ( struct V_131 * V_132 ,
int V_139 , int V_16 )
{
struct V_1 * V_2 = (struct V_1 * ) V_132 -> V_133 ;
struct V_37 * V_36 ;
int V_81 , V_27 ;
V_120 V_17 ;
F_38 ( & V_2 -> V_62 ) ;
if ( ! V_2 -> V_134 || ! ( V_2 -> V_135 == V_136 ) ) {
V_27 = - V_137 ;
goto V_138;
}
if ( V_139 < 0 || V_139 >= V_34 ) {
V_27 = - V_23 ;
goto V_138;
}
if ( ( V_16 / 1000 ) > V_142 ) {
V_27 = - V_23 ;
goto V_138;
}
V_17 = ( V_120 ) ( V_16 / 1000 ) ;
V_36 = & V_2 -> V_35 ;
if ( ! V_36 ) {
V_27 = - V_137 ;
goto V_138;
}
if ( V_36 -> V_125 [ V_139 ] == V_17 ) {
V_27 = 0 ;
goto V_138;
}
for ( V_81 = 0 ; V_81 < V_34 ; V_81 ++ ) {
if ( V_36 -> V_125 [ V_81 ] == V_17 ) {
V_27 = - V_23 ;
goto V_138;
}
}
V_36 -> V_125 [ V_139 ] = V_17 ;
V_27 = F_59 ( V_2 ) ;
V_138:
F_43 ( & V_2 -> V_62 ) ;
return V_27 ;
}
static void F_66 ( struct V_1 * V_2 )
{
int V_81 ;
char V_143 [] = L_27 ;
if ( ! F_5 ( V_2 ) ) {
V_2 -> V_35 . V_36 = NULL ;
return;
}
F_67 ( F_34 ( V_143 ) >= V_144 ) ;
V_2 -> V_35 . V_36 = F_68 ( V_143 ,
V_34 ,
V_145 ,
V_2 , & V_146 ,
NULL , 0 , 0 ) ;
if ( F_69 ( V_2 -> V_35 . V_36 ) ) {
F_15 ( V_2 ,
L_28 ,
F_70 ( V_2 -> V_35 . V_36 ) ) ;
V_2 -> V_35 . V_36 = NULL ;
return;
}
for ( V_81 = 0 ; V_81 < V_34 ; V_81 ++ )
V_2 -> V_35 . V_125 [ V_81 ] = V_126 ;
}
static int F_71 ( struct V_147 * V_148 ,
unsigned long * V_106 )
{
* V_106 = F_34 ( V_110 ) - 1 ;
return 0 ;
}
static int F_72 ( struct V_147 * V_148 ,
unsigned long * V_106 )
{
struct V_1 * V_2 = (struct V_1 * ) ( V_148 -> V_133 ) ;
* V_106 = V_2 -> V_114 . V_115 ;
return 0 ;
}
static int F_73 ( struct V_147 * V_148 ,
unsigned long V_149 )
{
struct V_1 * V_2 = (struct V_1 * ) ( V_148 -> V_133 ) ;
int V_27 ;
if ( ! V_2 -> V_134 || ! ( V_2 -> V_135 == V_136 ) )
return - V_137 ;
F_38 ( & V_2 -> V_62 ) ;
if ( V_149 >= F_34 ( V_110 ) ) {
V_27 = - V_23 ;
goto V_150;
}
V_27 = F_55 ( V_2 , V_113 ,
V_149 ) ;
V_150:
F_43 ( & V_2 -> V_62 ) ;
return V_27 ;
}
static void F_74 ( struct V_1 * V_2 )
{
char V_143 [] = L_27 ;
if ( ! F_75 ( V_2 ) )
return;
F_67 ( F_34 ( V_143 ) >= V_144 ) ;
V_2 -> V_114 . V_148 =
F_76 ( V_143 ,
V_2 ,
& V_151 ) ;
if ( F_69 ( V_2 -> V_114 . V_148 ) ) {
F_15 ( V_2 ,
L_29 ,
F_70 ( V_2 -> V_114 . V_148 ) ) ;
V_2 -> V_114 . V_148 = NULL ;
return;
}
}
static void F_77 ( struct V_1 * V_2 )
{
if ( ! F_5 ( V_2 ) || ! V_2 -> V_35 . V_36 )
return;
F_15 ( V_2 , L_30 ) ;
F_78 ( V_2 -> V_35 . V_36 ) ;
V_2 -> V_35 . V_36 = NULL ;
}
static void F_79 ( struct V_1 * V_2 )
{
if ( ! F_75 ( V_2 ) || ! V_2 -> V_114 . V_148 )
return;
F_15 ( V_2 , L_31 ) ;
F_80 ( V_2 -> V_114 . V_148 ) ;
V_2 -> V_114 . V_148 = NULL ;
}
void F_81 ( struct V_1 * V_2 , T_1 V_89 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
F_15 ( V_2 , L_32 ) ;
if ( V_2 -> V_152 -> V_153 )
V_4 -> V_7 = * V_2 -> V_152 -> V_153 ;
else
V_4 -> V_7 = V_154 ;
V_4 -> V_11 = false ;
V_4 -> V_12 = false ;
V_4 -> V_89 = V_89 ;
F_82 ( & V_4 -> V_14 , F_37 ) ;
#ifdef F_20
F_74 ( V_2 ) ;
F_66 ( V_2 ) ;
#endif
}
void F_83 ( struct V_1 * V_2 )
{
F_84 ( & V_2 -> V_5 . V_14 ) ;
F_15 ( V_2 , L_33 ) ;
#ifdef F_20
F_79 ( V_2 ) ;
F_77 ( V_2 ) ;
#endif
}
