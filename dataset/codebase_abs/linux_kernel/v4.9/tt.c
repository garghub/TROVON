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
V_50 = F_26 ( V_51 ,
V_52 , 0 ) ;
if ( ! F_27 ( & V_2 -> V_53 -> V_54 ,
V_55 ) )
return F_28 ( V_2 , V_50 , 0 , sizeof( V_43 ) , & V_43 ) ;
return F_28 ( V_2 , V_50 , 0 , sizeof( V_47 ) , & V_47 ) ;
}
int F_29 ( struct V_1 * V_2 , T_2 * V_16 )
{
struct V_56 V_57 ;
static T_3 V_58 [] = { F_30 (PHY_OPS_GROUP,
DTS_MEASUREMENT_NOTIF_WIDE) } ;
int V_27 ;
F_31 ( & V_2 -> V_59 ) ;
F_32 ( & V_2 -> V_26 , & V_57 ,
V_58 , F_33 ( V_58 ) ,
F_16 , V_16 ) ;
V_27 = F_24 ( V_2 ) ;
if ( V_27 ) {
F_3 ( V_2 , L_8 , V_27 ) ;
F_34 ( & V_2 -> V_26 , & V_57 ) ;
return V_27 ;
}
V_27 = F_35 ( & V_2 -> V_26 , & V_57 ,
V_60 ) ;
if ( V_27 )
F_3 ( V_2 , L_9 ) ;
return V_27 ;
}
static void F_36 ( struct V_61 * V_62 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
T_1 V_6 ;
T_2 V_16 ;
int V_27 ;
V_4 = F_17 ( V_62 , struct V_3 , V_14 . V_62 ) ;
V_2 = F_17 ( V_4 , struct V_1 , V_5 ) ;
if ( F_5 ( V_2 ) ) {
F_8 ( V_2 ) ;
return;
}
V_6 = V_4 -> V_7 . V_8 ;
F_37 ( & V_2 -> V_59 ) ;
if ( F_38 ( V_2 ) )
goto V_63;
if ( F_39 ( V_2 , V_64 ) ) {
F_40 ( V_2 ) ;
goto V_63;
}
V_27 = F_29 ( V_2 , & V_16 ) ;
F_41 ( V_2 , V_64 ) ;
F_40 ( V_2 ) ;
if ( V_27 )
goto V_63;
F_15 ( V_2 , L_10 , V_16 ) ;
if ( V_16 <= V_4 -> V_7 . V_14 ) {
F_42 ( & V_2 -> V_59 ) ;
F_8 ( V_2 ) ;
return;
}
V_63:
F_42 ( & V_2 -> V_59 ) ;
F_6 ( & V_2 -> V_5 . V_14 ,
F_43 ( V_6 * V_15 ) ) ;
}
static void F_44 ( void * V_65 , T_4 * V_66 ,
struct V_67 * V_68 )
{
struct V_1 * V_2 = V_65 ;
enum V_69 V_70 ;
F_31 ( & V_2 -> V_59 ) ;
if ( V_2 -> V_5 . V_12 )
V_70 = V_71 ;
else
V_70 = V_72 ;
if ( V_68 -> type != V_73 )
return;
F_45 ( V_2 , V_68 , V_74 , V_70 ) ;
}
static void F_46 ( struct V_1 * V_2 , bool V_75 )
{
struct V_76 * V_77 ;
int V_78 , V_79 ;
for ( V_78 = 0 ; V_78 < V_80 ; V_78 ++ ) {
V_77 = F_47 ( V_2 , V_78 ) ;
if ( ! V_77 )
continue;
if ( V_75 == V_77 -> V_81 )
continue;
V_79 = F_48 ( V_2 , V_77 , V_75 ) ;
if ( V_79 ) {
F_3 ( V_2 , L_11 ,
V_75 ? L_12 : L_13 ) ;
} else {
F_15 ( V_2 , L_14 ,
V_75 ? L_15 : L_16 ) ;
V_77 -> V_81 = V_75 ;
}
}
}
void F_49 ( struct V_1 * V_2 , T_1 V_82 )
{
struct V_83 V_43 = {
. V_84 = V_85 ,
. V_22 = { sizeof( T_1 ) , } ,
. V_24 = { & V_82 , } ,
} ;
V_82 = F_50 ( V_82 , V_2 -> V_5 . V_86 ) ;
if ( F_51 ( V_2 , & V_43 ) == 0 ) {
F_15 ( V_2 , L_17 ,
V_82 ) ;
V_2 -> V_5 . V_87 = V_82 ;
} else {
F_3 ( V_2 , L_18 ) ;
}
}
void F_10 ( struct V_1 * V_2 )
{
struct V_88 * V_7 = & V_2 -> V_5 . V_7 ;
struct V_3 * V_4 = & V_2 -> V_5 ;
T_2 V_17 = V_2 -> V_17 ;
bool V_89 = false ;
int V_78 ;
T_1 V_87 ;
F_15 ( V_2 , L_10 , V_2 -> V_17 ) ;
if ( V_7 -> V_90 && V_17 >= V_7 -> V_91 ) {
F_1 ( V_2 ) ;
return;
}
if ( V_7 -> V_90 &&
V_17 <= V_7 -> V_14 ) {
F_8 ( V_2 ) ;
return;
}
if ( V_7 -> V_92 ) {
if ( ! V_4 -> V_12 &&
V_17 >= V_7 -> V_93 ) {
F_15 ( V_2 , L_19 ) ;
V_4 -> V_12 = true ;
F_52 (
V_2 -> V_94 , V_95 ,
F_44 , V_2 ) ;
V_89 = true ;
} else if ( V_4 -> V_12 &&
V_17 <= V_7 -> V_96 ) {
F_15 ( V_2 , L_20 ) ;
V_4 -> V_12 = false ;
F_52 (
V_2 -> V_94 , V_95 ,
F_44 , V_2 ) ;
}
}
if ( V_7 -> V_97 ) {
if ( V_17 >= V_7 -> V_98 ) {
F_46 ( V_2 , true ) ;
V_89 = true ;
} else if ( V_17 <= V_7 -> V_99 ) {
F_46 ( V_2 , false ) ;
}
}
if ( V_7 -> V_100 ) {
V_87 = V_4 -> V_86 ;
for ( V_78 = 0 ; V_78 < V_101 ; V_78 ++ ) {
if ( V_17 < V_7 -> V_87 [ V_78 ] . V_17 )
break;
V_87 = F_50 ( V_4 -> V_86 ,
V_7 -> V_87 [ V_78 ] . V_82 ) ;
}
if ( V_87 != V_4 -> V_86 )
V_89 = true ;
if ( V_4 -> V_87 != V_87 )
F_49 ( V_2 , V_87 ) ;
}
if ( ! V_4 -> V_11 && V_89 ) {
F_53 ( V_2 ,
L_21 ) ;
V_4 -> V_11 = true ;
} else if ( V_4 -> V_11 && ! V_4 -> V_12 &&
V_4 -> V_87 == V_4 -> V_86 &&
V_17 <= V_7 -> V_99 ) {
F_53 ( V_2 ,
L_22 ) ;
V_4 -> V_11 = false ;
}
}
int F_54 ( struct V_1 * V_2 , T_1 V_102 , T_1 V_103 )
{
struct V_104 V_43 = {
. V_105 = F_25 ( V_102 ) ,
. V_106 = F_25 ( V_107 [ V_103 ] ) ,
. V_108 = 0 ,
} ;
int V_27 ;
T_1 V_10 ;
F_31 ( & V_2 -> V_59 ) ;
V_27 = F_55 ( V_2 , F_30 ( V_52 ,
V_109 ) ,
sizeof( V_43 ) , & V_43 , & V_10 ) ;
if ( V_27 ) {
F_3 ( V_2 , L_23 , V_27 ) ;
return V_27 ;
}
switch ( V_102 ) {
case V_110 :
#ifdef F_20
V_2 -> V_111 . V_112 = V_103 ;
#endif
break;
case V_113 :
F_15 ( V_2 , L_24 , V_10 ) ;
return V_10 ;
case V_114 :
F_15 ( V_2 , L_25 ) ;
break;
}
return 0 ;
}
static int F_56 ( const void * V_115 , const void * V_116 )
{
return ( ( V_117 ) F_57 ( * ( V_118 * ) V_115 ) -
( V_117 ) F_57 ( * ( V_118 * ) V_116 ) ) ;
}
int F_58 ( struct V_1 * V_2 )
{
struct V_119 V_43 = { 0 } ;
int V_27 , V_78 , V_120 , V_121 = 0 ;
F_31 ( & V_2 -> V_59 ) ;
if ( ! V_2 -> V_35 . V_36 )
return - V_23 ;
for ( V_78 = 0 ; V_78 < V_34 ; V_78 ++ ) {
if ( V_2 -> V_35 . V_122 [ V_78 ] != V_123 ) {
V_43 . V_124 [ V_121 ++ ] =
F_59 ( V_2 -> V_35 . V_122 [ V_78 ] ) ;
}
}
V_43 . V_125 = F_25 ( V_121 ) ;
if ( ! V_121 )
goto V_126;
F_60 ( V_43 . V_124 , V_121 , sizeof( V_117 ) , F_56 , NULL ) ;
for ( V_78 = 0 ; V_78 < V_121 ; V_78 ++ ) {
for ( V_120 = 0 ; V_120 < V_34 ; V_120 ++ ) {
if ( F_57 ( V_43 . V_124 [ V_78 ] ) ==
V_2 -> V_35 . V_122 [ V_120 ] )
V_2 -> V_35 . V_39 [ V_78 ] = V_120 ;
}
}
V_126:
V_27 = F_28 ( V_2 , F_30 ( V_52 ,
V_127 ) ,
0 , sizeof( V_43 ) , & V_43 ) ;
if ( V_27 )
F_3 ( V_2 , L_26 ,
V_27 ) ;
return V_27 ;
}
static int F_61 ( struct V_128 * V_129 ,
int * V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_129 -> V_130 ;
int V_27 ;
int V_16 ;
F_37 ( & V_2 -> V_59 ) ;
if ( ! V_2 -> V_131 || ! ( V_2 -> V_132 == V_133 ) ) {
V_27 = - V_134 ;
goto V_135;
}
V_27 = F_29 ( V_2 , & V_16 ) ;
if ( V_27 )
goto V_135;
* V_17 = V_16 * 1000 ;
V_135:
F_42 ( & V_2 -> V_59 ) ;
return V_27 ;
}
static int F_62 ( struct V_128 * V_129 ,
int V_136 , int * V_16 )
{
struct V_1 * V_2 = (struct V_1 * ) V_129 -> V_130 ;
if ( V_136 < 0 || V_136 >= V_34 )
return - V_23 ;
* V_16 = V_2 -> V_35 . V_122 [ V_136 ] * 1000 ;
return 0 ;
}
static int F_63 ( struct V_128 * V_129 ,
int V_136 , enum V_137 * type )
{
if ( V_136 < 0 || V_136 >= V_34 )
return - V_23 ;
* type = V_138 ;
return 0 ;
}
static int F_64 ( struct V_128 * V_129 ,
int V_136 , int V_16 )
{
struct V_1 * V_2 = (struct V_1 * ) V_129 -> V_130 ;
struct V_37 * V_36 ;
int V_78 , V_27 ;
V_117 V_17 ;
F_37 ( & V_2 -> V_59 ) ;
if ( ! V_2 -> V_131 || ! ( V_2 -> V_132 == V_133 ) ) {
V_27 = - V_134 ;
goto V_135;
}
if ( V_136 < 0 || V_136 >= V_34 ) {
V_27 = - V_23 ;
goto V_135;
}
if ( ( V_16 / 1000 ) > V_139 ) {
V_27 = - V_23 ;
goto V_135;
}
V_17 = ( V_117 ) ( V_16 / 1000 ) ;
V_36 = & V_2 -> V_35 ;
if ( ! V_36 ) {
V_27 = - V_134 ;
goto V_135;
}
if ( V_36 -> V_122 [ V_136 ] == V_17 ) {
V_27 = 0 ;
goto V_135;
}
for ( V_78 = 0 ; V_78 < V_34 ; V_78 ++ ) {
if ( V_36 -> V_122 [ V_78 ] == V_17 ) {
V_27 = - V_23 ;
goto V_135;
}
}
V_36 -> V_122 [ V_136 ] = V_17 ;
V_27 = F_58 ( V_2 ) ;
V_135:
F_42 ( & V_2 -> V_59 ) ;
return V_27 ;
}
static void F_65 ( struct V_1 * V_2 )
{
int V_78 ;
char V_140 [] = L_27 ;
if ( ! F_5 ( V_2 ) ) {
V_2 -> V_35 . V_36 = NULL ;
return;
}
F_66 ( F_33 ( V_140 ) >= V_141 ) ;
V_2 -> V_35 . V_36 = F_67 ( V_140 ,
V_34 ,
V_142 ,
V_2 , & V_143 ,
NULL , 0 , 0 ) ;
if ( F_68 ( V_2 -> V_35 . V_36 ) ) {
F_15 ( V_2 ,
L_28 ,
F_69 ( V_2 -> V_35 . V_36 ) ) ;
V_2 -> V_35 . V_36 = NULL ;
return;
}
for ( V_78 = 0 ; V_78 < V_34 ; V_78 ++ )
V_2 -> V_35 . V_122 [ V_78 ] = V_123 ;
}
static int F_70 ( struct V_144 * V_145 ,
unsigned long * V_103 )
{
* V_103 = F_33 ( V_107 ) - 1 ;
return 0 ;
}
static int F_71 ( struct V_144 * V_145 ,
unsigned long * V_103 )
{
struct V_1 * V_2 = (struct V_1 * ) ( V_145 -> V_130 ) ;
* V_103 = V_2 -> V_111 . V_112 ;
return 0 ;
}
static int F_72 ( struct V_144 * V_145 ,
unsigned long V_146 )
{
struct V_1 * V_2 = (struct V_1 * ) ( V_145 -> V_130 ) ;
int V_27 ;
if ( ! V_2 -> V_131 || ! ( V_2 -> V_132 == V_133 ) )
return - V_134 ;
F_37 ( & V_2 -> V_59 ) ;
if ( V_146 >= F_33 ( V_107 ) ) {
V_27 = - V_23 ;
goto V_147;
}
V_27 = F_54 ( V_2 , V_110 ,
V_146 ) ;
V_147:
F_42 ( & V_2 -> V_59 ) ;
return V_27 ;
}
static void F_73 ( struct V_1 * V_2 )
{
char V_140 [] = L_27 ;
if ( ! F_74 ( V_2 ) )
return;
F_66 ( F_33 ( V_140 ) >= V_141 ) ;
V_2 -> V_111 . V_145 =
F_75 ( V_140 ,
V_2 ,
& V_148 ) ;
if ( F_68 ( V_2 -> V_111 . V_145 ) ) {
F_15 ( V_2 ,
L_29 ,
F_69 ( V_2 -> V_111 . V_145 ) ) ;
V_2 -> V_111 . V_145 = NULL ;
return;
}
}
static void F_76 ( struct V_1 * V_2 )
{
if ( ! F_5 ( V_2 ) || ! V_2 -> V_35 . V_36 )
return;
F_15 ( V_2 , L_30 ) ;
F_77 ( V_2 -> V_35 . V_36 ) ;
V_2 -> V_35 . V_36 = NULL ;
}
static void F_78 ( struct V_1 * V_2 )
{
if ( ! F_74 ( V_2 ) || ! V_2 -> V_111 . V_145 )
return;
F_15 ( V_2 , L_31 ) ;
F_79 ( V_2 -> V_111 . V_145 ) ;
V_2 -> V_111 . V_145 = NULL ;
}
void F_80 ( struct V_1 * V_2 , T_1 V_86 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
F_15 ( V_2 , L_32 ) ;
if ( V_2 -> V_149 -> V_150 )
V_4 -> V_7 = * V_2 -> V_149 -> V_150 ;
else
V_4 -> V_7 = V_151 ;
V_4 -> V_11 = false ;
V_4 -> V_12 = false ;
V_4 -> V_86 = V_86 ;
F_81 ( & V_4 -> V_14 , F_36 ) ;
#ifdef F_20
F_73 ( V_2 ) ;
F_65 ( V_2 ) ;
#endif
}
void F_82 ( struct V_1 * V_2 )
{
F_83 ( & V_2 -> V_5 . V_14 ) ;
F_15 ( V_2 , L_33 ) ;
#ifdef F_20
F_78 ( V_2 ) ;
F_76 ( V_2 ) ;
#endif
}
