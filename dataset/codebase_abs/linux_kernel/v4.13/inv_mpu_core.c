int F_1 ( struct V_1 * V_2 , bool V_3 , T_1 V_4 )
{
unsigned int V_5 , V_6 ;
int V_7 ;
if ( V_4 == V_8 ) {
V_7 = F_2 ( V_2 -> V_9 , V_2 -> V_10 -> V_11 , & V_6 ) ;
if ( V_7 )
return V_7 ;
V_6 &= ~ V_12 ;
}
if ( ( V_4 == V_8 ) && ( ! V_3 ) ) {
V_6 |= V_13 ;
V_7 = F_3 ( V_2 -> V_9 , V_2 -> V_10 -> V_11 , V_6 ) ;
if ( V_7 )
return V_7 ;
}
V_7 = F_2 ( V_2 -> V_9 , V_2 -> V_10 -> V_14 , & V_5 ) ;
if ( V_7 )
return V_7 ;
if ( V_3 )
V_5 &= ~ V_4 ;
else
V_5 |= V_4 ;
V_7 = F_3 ( V_2 -> V_9 , V_2 -> V_10 -> V_14 , V_5 ) ;
if ( V_7 )
return V_7 ;
if ( V_3 ) {
F_4 ( V_15 ) ;
if ( V_4 == V_8 ) {
V_6 |= V_16 ;
V_7 = F_3 ( V_2 -> V_9 ,
V_2 -> V_10 -> V_11 , V_6 ) ;
if ( V_7 )
return V_7 ;
}
}
return 0 ;
}
int F_5 ( struct V_1 * V_2 , bool V_17 )
{
int V_7 = 0 ;
if ( V_17 ) {
if ( ! V_2 -> V_18 )
V_7 = F_3 ( V_2 -> V_9 , V_2 -> V_10 -> V_11 , 0 ) ;
if ( ! V_7 )
V_2 -> V_18 ++ ;
} else {
V_2 -> V_18 -- ;
if ( ! V_2 -> V_18 )
V_7 = F_3 ( V_2 -> V_9 , V_2 -> V_10 -> V_11 ,
V_19 ) ;
}
if ( V_7 )
return V_7 ;
if ( V_17 )
F_6 ( V_20 ,
V_21 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
enum V_22 V_23 )
{
int V_7 ;
V_7 = F_3 ( V_2 -> V_9 , V_2 -> V_10 -> V_24 , V_23 ) ;
if ( V_7 )
return V_7 ;
switch ( V_2 -> V_25 ) {
case V_26 :
case V_27 :
case V_28 :
V_7 = 0 ;
break;
default:
V_7 = F_3 ( V_2 -> V_9 , V_2 -> V_10 -> V_29 , V_23 ) ;
break;
}
return V_7 ;
}
static int F_8 ( struct V_30 * V_31 )
{
int V_7 ;
T_2 V_5 ;
struct V_1 * V_2 = F_9 ( V_31 ) ;
V_7 = F_5 ( V_2 , true ) ;
if ( V_7 )
return V_7 ;
V_5 = ( V_32 << V_33 ) ;
V_7 = F_3 ( V_2 -> V_9 , V_2 -> V_10 -> V_34 , V_5 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_7 ( V_2 , V_35 ) ;
if ( V_7 )
return V_7 ;
V_5 = V_36 / V_37 - 1 ;
V_7 = F_3 ( V_2 -> V_9 , V_2 -> V_10 -> V_38 , V_5 ) ;
if ( V_7 )
return V_7 ;
V_5 = ( V_39 << V_40 ) ;
V_7 = F_3 ( V_2 -> V_9 , V_2 -> V_10 -> V_41 , V_5 ) ;
if ( V_7 )
return V_7 ;
memcpy ( & V_2 -> V_42 , V_43 [ V_2 -> V_25 ] . V_44 ,
sizeof( struct V_45 ) ) ;
V_7 = F_5 ( V_2 , false ) ;
return V_7 ;
}
static int F_10 ( struct V_1 * V_2 , int V_10 ,
int V_46 , int V_23 )
{
int V_47 , V_7 ;
T_3 V_5 = F_11 ( V_23 ) ;
V_47 = ( V_46 - V_48 ) * 2 ;
V_7 = F_12 ( V_2 -> V_9 , V_10 + V_47 , ( T_2 * ) & V_5 , 2 ) ;
if ( V_7 )
return - V_49 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , int V_10 ,
int V_46 , int * V_23 )
{
int V_47 , V_7 ;
T_3 V_5 ;
V_47 = ( V_46 - V_48 ) * 2 ;
V_7 = F_14 ( V_2 -> V_9 , V_10 + V_47 , ( T_2 * ) & V_5 , 2 ) ;
if ( V_7 )
return - V_49 ;
* V_23 = ( short ) F_15 ( & V_5 ) ;
return V_50 ;
}
static int
F_16 ( struct V_30 * V_31 ,
struct V_51 const * V_52 ,
int * V_23 , int * V_53 , long V_4 )
{
struct V_1 * V_2 = F_9 ( V_31 ) ;
int V_54 = 0 ;
switch ( V_4 ) {
case V_55 :
{
int V_7 ;
V_54 = V_50 ;
F_17 ( & V_2 -> V_56 ) ;
V_7 = F_18 ( V_31 ) ;
if ( V_7 )
goto V_57;
V_7 = F_5 ( V_2 , true ) ;
if ( V_7 )
goto V_58;
switch ( V_52 -> type ) {
case V_59 :
V_7 = F_1 ( V_2 , true ,
V_8 ) ;
if ( V_7 )
goto V_60;
V_54 = F_13 ( V_2 , V_2 -> V_10 -> V_61 ,
V_52 -> V_62 , V_23 ) ;
V_7 = F_1 ( V_2 , false ,
V_8 ) ;
if ( V_7 )
goto V_60;
break;
case V_63 :
V_7 = F_1 ( V_2 , true ,
V_64 ) ;
if ( V_7 )
goto V_60;
V_54 = F_13 ( V_2 , V_2 -> V_10 -> V_65 ,
V_52 -> V_62 , V_23 ) ;
V_7 = F_1 ( V_2 , false ,
V_64 ) ;
if ( V_7 )
goto V_60;
break;
case V_66 :
F_4 ( V_67 ) ;
V_54 = F_13 ( V_2 , V_2 -> V_10 -> V_68 ,
V_48 , V_23 ) ;
break;
default:
V_54 = - V_49 ;
break;
}
V_60:
V_7 |= F_5 ( V_2 , false ) ;
V_58:
F_19 ( V_31 ) ;
V_57:
F_20 ( & V_2 -> V_56 ) ;
if ( V_7 )
return V_7 ;
return V_54 ;
}
case V_69 :
switch ( V_52 -> type ) {
case V_59 :
F_17 ( & V_2 -> V_56 ) ;
* V_23 = 0 ;
* V_53 = V_70 [ V_2 -> V_42 . V_71 ] ;
F_20 ( & V_2 -> V_56 ) ;
return V_72 ;
case V_63 :
F_17 ( & V_2 -> V_56 ) ;
* V_23 = 0 ;
* V_53 = V_73 [ V_2 -> V_42 . V_74 ] ;
F_20 ( & V_2 -> V_56 ) ;
return V_75 ;
case V_66 :
* V_23 = 0 ;
* V_53 = V_76 ;
return V_75 ;
default:
return - V_49 ;
}
case V_77 :
switch ( V_52 -> type ) {
case V_66 :
* V_23 = V_78 ;
return V_50 ;
default:
return - V_49 ;
}
case V_79 :
switch ( V_52 -> type ) {
case V_59 :
F_17 ( & V_2 -> V_56 ) ;
V_54 = F_13 ( V_2 , V_2 -> V_10 -> V_80 ,
V_52 -> V_62 , V_23 ) ;
F_20 ( & V_2 -> V_56 ) ;
return V_50 ;
case V_63 :
F_17 ( & V_2 -> V_56 ) ;
V_54 = F_13 ( V_2 , V_2 -> V_10 -> V_81 ,
V_52 -> V_62 , V_23 ) ;
F_20 ( & V_2 -> V_56 ) ;
return V_50 ;
default:
return - V_49 ;
}
default:
return - V_49 ;
}
}
static int F_21 ( struct V_1 * V_2 , int V_23 )
{
int V_7 , V_82 ;
T_2 V_5 ;
for ( V_82 = 0 ; V_82 < F_22 ( V_70 ) ; ++ V_82 ) {
if ( V_70 [ V_82 ] == V_23 ) {
V_5 = ( V_82 << V_33 ) ;
V_7 = F_3 ( V_2 -> V_9 , V_2 -> V_10 -> V_34 , V_5 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_42 . V_71 = V_82 ;
return 0 ;
}
}
return - V_49 ;
}
static int F_23 ( struct V_30 * V_31 ,
struct V_51 const * V_52 , long V_4 )
{
switch ( V_4 ) {
case V_69 :
switch ( V_52 -> type ) {
case V_59 :
return V_72 ;
default:
return V_75 ;
}
default:
return V_75 ;
}
return - V_49 ;
}
static int F_24 ( struct V_1 * V_2 , int V_23 )
{
int V_7 , V_82 ;
T_2 V_5 ;
for ( V_82 = 0 ; V_82 < F_22 ( V_73 ) ; ++ V_82 ) {
if ( V_73 [ V_82 ] == V_23 ) {
V_5 = ( V_82 << V_40 ) ;
V_7 = F_3 ( V_2 -> V_9 , V_2 -> V_10 -> V_41 , V_5 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_42 . V_74 = V_82 ;
return 0 ;
}
}
return - V_49 ;
}
static int F_25 ( struct V_30 * V_31 ,
struct V_51 const * V_52 ,
int V_23 , int V_53 , long V_4 )
{
struct V_1 * V_2 = F_9 ( V_31 ) ;
int V_7 ;
F_17 ( & V_2 -> V_56 ) ;
V_7 = F_18 ( V_31 ) ;
if ( V_7 )
goto V_83;
V_7 = F_5 ( V_2 , true ) ;
if ( V_7 )
goto V_84;
switch ( V_4 ) {
case V_69 :
switch ( V_52 -> type ) {
case V_59 :
V_7 = F_21 ( V_2 , V_53 ) ;
break;
case V_63 :
V_7 = F_24 ( V_2 , V_53 ) ;
break;
default:
V_7 = - V_49 ;
break;
}
break;
case V_79 :
switch ( V_52 -> type ) {
case V_59 :
V_7 = F_10 ( V_2 ,
V_2 -> V_10 -> V_80 ,
V_52 -> V_62 , V_23 ) ;
break;
case V_63 :
V_7 = F_10 ( V_2 ,
V_2 -> V_10 -> V_81 ,
V_52 -> V_62 , V_23 ) ;
break;
default:
V_7 = - V_49 ;
}
default:
V_7 = - V_49 ;
break;
}
V_7 |= F_5 ( V_2 , false ) ;
V_84:
F_19 ( V_31 ) ;
V_83:
F_20 ( & V_2 -> V_56 ) ;
return V_7 ;
}
static int F_26 ( struct V_1 * V_2 , int V_85 )
{
const int V_86 [] = { 188 , 98 , 42 , 20 , 10 , 5 } ;
const int V_5 [] = { V_87 , V_88 ,
V_89 , V_35 ,
V_90 , V_91 } ;
int V_82 , V_92 , V_7 ;
T_2 V_93 ;
V_92 = ( V_85 >> 1 ) ;
V_82 = 0 ;
while ( ( V_92 < V_86 [ V_82 ] ) && ( V_82 < F_22 ( V_5 ) - 1 ) )
V_82 ++ ;
V_93 = V_5 [ V_82 ] ;
V_7 = F_7 ( V_2 , V_93 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_42 . V_24 = V_93 ;
return 0 ;
}
static T_4
F_27 ( struct V_94 * V_95 , struct V_96 * V_97 ,
const char * V_98 , T_5 V_99 )
{
T_6 V_100 ;
T_2 V_5 ;
int V_7 ;
struct V_30 * V_31 = F_28 ( V_95 ) ;
struct V_1 * V_2 = F_9 ( V_31 ) ;
if ( F_29 ( V_98 , 10 , & V_100 ) )
return - V_49 ;
if ( V_100 < V_101 ||
V_100 > V_102 )
return - V_49 ;
F_17 ( & V_2 -> V_56 ) ;
if ( V_100 == V_2 -> V_42 . V_100 ) {
V_7 = 0 ;
goto V_103;
}
V_7 = F_18 ( V_31 ) ;
if ( V_7 )
goto V_103;
V_7 = F_5 ( V_2 , true ) ;
if ( V_7 )
goto V_104;
V_5 = V_36 / V_100 - 1 ;
V_7 = F_3 ( V_2 -> V_9 , V_2 -> V_10 -> V_38 , V_5 ) ;
if ( V_7 )
goto V_105;
V_2 -> V_42 . V_100 = V_100 ;
V_7 = F_26 ( V_2 , V_100 ) ;
if ( V_7 )
goto V_105;
V_105:
V_7 |= F_5 ( V_2 , false ) ;
V_104:
F_19 ( V_31 ) ;
V_103:
F_20 ( & V_2 -> V_56 ) ;
if ( V_7 )
return V_7 ;
return V_99 ;
}
static T_4
F_30 ( struct V_94 * V_95 , struct V_96 * V_97 ,
char * V_98 )
{
struct V_1 * V_2 = F_9 ( F_28 ( V_95 ) ) ;
unsigned V_100 ;
F_17 ( & V_2 -> V_56 ) ;
V_100 = V_2 -> V_42 . V_100 ;
F_20 ( & V_2 -> V_56 ) ;
return F_31 ( V_98 , V_106 , L_1 , V_100 ) ;
}
static T_4 F_32 ( struct V_94 * V_95 , struct V_96 * V_97 ,
char * V_98 )
{
struct V_1 * V_2 = F_9 ( F_28 ( V_95 ) ) ;
struct V_107 * V_108 = F_33 ( V_97 ) ;
T_7 * V_109 ;
switch ( V_108 -> V_110 ) {
case V_111 :
case V_112 :
V_109 = V_2 -> V_113 . V_114 ;
return F_31 ( V_98 , V_106 ,
L_2 ,
V_109 [ 0 ] , V_109 [ 1 ] , V_109 [ 2 ] , V_109 [ 3 ] , V_109 [ 4 ] , V_109 [ 5 ] , V_109 [ 6 ] , V_109 [ 7 ] , V_109 [ 8 ] ) ;
default:
return - V_49 ;
}
}
static int F_34 ( struct V_30 * V_31 ,
struct V_115 * V_116 )
{
struct V_1 * V_2 = F_9 ( V_31 ) ;
if ( V_2 -> V_116 != V_116 )
return - V_49 ;
return 0 ;
}
static const struct V_117 *
F_35 ( const struct V_30 * V_31 ,
const struct V_51 * V_52 )
{
return & ( (struct V_1 * ) F_9 ( V_31 ) ) -> V_114 ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_7 ;
unsigned int V_118 ;
int V_82 ;
V_2 -> V_119 = & V_43 [ V_2 -> V_25 ] ;
V_2 -> V_10 = V_43 [ V_2 -> V_25 ] . V_10 ;
V_7 = F_2 ( V_2 -> V_9 , V_120 , & V_118 ) ;
if ( V_7 )
return V_7 ;
if ( V_118 != V_2 -> V_119 -> V_121 ) {
for ( V_82 = 0 ; V_82 < V_122 ; ++ V_82 ) {
if ( V_118 == V_43 [ V_82 ] . V_121 ) {
F_37 ( F_38 ( V_2 -> V_9 ) ,
L_3
L_4 ,
V_118 , V_43 [ V_82 ] . V_123 ,
V_2 -> V_119 -> V_121 , V_2 -> V_119 -> V_123 ) ;
break;
}
}
if ( V_82 >= V_122 ) {
F_39 ( F_38 ( V_2 -> V_9 ) ,
L_5 ,
V_118 , V_2 -> V_119 -> V_121 , V_2 -> V_119 -> V_123 ) ;
return - V_124 ;
}
}
V_7 = F_3 ( V_2 -> V_9 , V_2 -> V_10 -> V_11 ,
V_125 ) ;
if ( V_7 )
return V_7 ;
F_4 ( V_126 ) ;
V_7 = F_5 ( V_2 , false ) ;
if ( V_7 )
return V_7 ;
V_7 = F_5 ( V_2 , true ) ;
if ( V_7 )
return V_7 ;
V_7 = F_1 ( V_2 , false ,
V_64 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_1 ( V_2 , false ,
V_8 ) ;
if ( V_7 )
return V_7 ;
return 0 ;
}
int F_40 ( struct V_127 * V_127 , int V_128 , const char * V_123 ,
int (* F_41)( struct V_30 * ) , int V_25 )
{
struct V_1 * V_2 ;
struct V_30 * V_31 ;
struct V_129 * V_130 ;
struct V_94 * V_95 = F_38 ( V_127 ) ;
int V_7 ;
V_31 = F_42 ( V_95 , sizeof( * V_2 ) ) ;
if ( ! V_31 )
return - V_131 ;
F_43 ( F_22 ( V_43 ) != V_122 ) ;
if ( V_25 < 0 || V_25 >= V_122 ) {
F_39 ( V_95 , L_6 ,
V_25 , V_123 ) ;
return - V_124 ;
}
V_2 = F_9 ( V_31 ) ;
F_44 ( & V_2 -> V_56 ) ;
V_2 -> V_25 = V_25 ;
V_2 -> V_18 = 0 ;
V_2 -> V_128 = V_128 ;
V_2 -> V_9 = V_127 ;
V_130 = F_45 ( V_95 ) ;
if ( ! V_130 ) {
V_7 = F_46 ( V_95 , L_7 ,
& V_2 -> V_114 ) ;
if ( V_7 ) {
F_39 ( V_95 , L_8 ,
V_7 ) ;
return V_7 ;
}
} else {
V_2 -> V_113 = * V_130 ;
}
V_7 = F_36 ( V_2 ) ;
if ( V_7 )
return V_7 ;
if ( F_41 )
F_41 ( V_31 ) ;
V_7 = F_8 ( V_31 ) ;
if ( V_7 ) {
F_39 ( V_95 , L_9 ) ;
return V_7 ;
}
F_47 ( V_95 , V_31 ) ;
V_31 -> V_95 . V_132 = V_95 ;
if ( V_123 )
V_31 -> V_123 = V_123 ;
else
V_31 -> V_123 = F_48 ( V_95 ) ;
V_31 -> V_133 = V_134 ;
V_31 -> V_135 = F_22 ( V_134 ) ;
V_31 -> V_136 = & V_137 ;
V_31 -> V_138 = V_139 ;
V_7 = F_49 ( V_31 ,
V_140 ,
V_141 ,
NULL ) ;
if ( V_7 ) {
F_39 ( V_95 , L_10 , V_7 ) ;
return V_7 ;
}
V_7 = F_50 ( V_31 ) ;
if ( V_7 ) {
F_39 ( V_95 , L_11 , V_7 ) ;
goto V_142;
}
F_51 ( V_2 -> V_143 ) ;
F_52 ( & V_2 -> V_144 ) ;
V_7 = F_53 ( V_31 ) ;
if ( V_7 ) {
F_39 ( V_95 , L_12 , V_7 ) ;
goto V_145;
}
return 0 ;
V_145:
F_54 ( V_2 ) ;
V_142:
F_55 ( V_31 ) ;
return V_7 ;
}
int F_56 ( struct V_94 * V_95 )
{
struct V_30 * V_31 = F_57 ( V_95 ) ;
F_58 ( V_31 ) ;
F_54 ( F_9 ( V_31 ) ) ;
F_55 ( V_31 ) ;
return 0 ;
}
static int F_59 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = F_9 ( F_57 ( V_95 ) ) ;
int V_7 ;
F_17 ( & V_2 -> V_56 ) ;
V_7 = F_5 ( V_2 , true ) ;
F_20 ( & V_2 -> V_56 ) ;
return V_7 ;
}
static int F_60 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = F_9 ( F_57 ( V_95 ) ) ;
int V_7 ;
F_17 ( & V_2 -> V_56 ) ;
V_7 = F_5 ( V_2 , false ) ;
F_20 ( & V_2 -> V_56 ) ;
return V_7 ;
}
