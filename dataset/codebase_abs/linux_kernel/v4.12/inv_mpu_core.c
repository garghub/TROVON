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
V_7 = 0 ;
F_17 ( & V_31 -> V_56 ) ;
if ( ! V_2 -> V_42 . V_57 ) {
V_7 = F_5 ( V_2 , true ) ;
if ( V_7 )
goto V_58;
}
switch ( V_52 -> type ) {
case V_59 :
if ( ! V_2 -> V_42 . V_60 ||
! V_2 -> V_42 . V_57 ) {
V_7 = F_1 ( V_2 , true ,
V_8 ) ;
if ( V_7 )
goto V_58;
}
V_54 = F_13 ( V_2 , V_2 -> V_10 -> V_61 ,
V_52 -> V_62 , V_23 ) ;
if ( ! V_2 -> V_42 . V_60 ||
! V_2 -> V_42 . V_57 ) {
V_7 = F_1 ( V_2 , false ,
V_8 ) ;
if ( V_7 )
goto V_58;
}
break;
case V_63 :
if ( ! V_2 -> V_42 . V_64 ||
! V_2 -> V_42 . V_57 ) {
V_7 = F_1 ( V_2 , true ,
V_65 ) ;
if ( V_7 )
goto V_58;
}
V_54 = F_13 ( V_2 , V_2 -> V_10 -> V_66 ,
V_52 -> V_62 , V_23 ) ;
if ( ! V_2 -> V_42 . V_64 ||
! V_2 -> V_42 . V_57 ) {
V_7 = F_1 ( V_2 , false ,
V_65 ) ;
if ( V_7 )
goto V_58;
}
break;
case V_67 :
F_4 ( V_68 ) ;
V_54 = F_13 ( V_2 , V_2 -> V_10 -> V_69 ,
V_48 , V_23 ) ;
break;
default:
V_54 = - V_49 ;
break;
}
V_58:
if ( ! V_2 -> V_42 . V_57 )
V_7 |= F_5 ( V_2 , false ) ;
F_18 ( & V_31 -> V_56 ) ;
if ( V_7 )
return V_7 ;
return V_54 ;
}
case V_70 :
switch ( V_52 -> type ) {
case V_59 :
* V_23 = 0 ;
* V_53 = V_71 [ V_2 -> V_42 . V_72 ] ;
return V_73 ;
case V_63 :
* V_23 = 0 ;
* V_53 = V_74 [ V_2 -> V_42 . V_75 ] ;
return V_76 ;
case V_67 :
* V_23 = 0 ;
* V_53 = V_77 ;
return V_76 ;
default:
return - V_49 ;
}
case V_78 :
switch ( V_52 -> type ) {
case V_67 :
* V_23 = V_79 ;
return V_50 ;
default:
return - V_49 ;
}
case V_80 :
switch ( V_52 -> type ) {
case V_59 :
V_54 = F_13 ( V_2 , V_2 -> V_10 -> V_81 ,
V_52 -> V_62 , V_23 ) ;
return V_50 ;
case V_63 :
V_54 = F_13 ( V_2 , V_2 -> V_10 -> V_82 ,
V_52 -> V_62 , V_23 ) ;
return V_50 ;
default:
return - V_49 ;
}
default:
return - V_49 ;
}
}
static int F_19 ( struct V_1 * V_2 , int V_23 )
{
int V_7 , V_83 ;
T_2 V_5 ;
for ( V_83 = 0 ; V_83 < F_20 ( V_71 ) ; ++ V_83 ) {
if ( V_71 [ V_83 ] == V_23 ) {
V_5 = ( V_83 << V_33 ) ;
V_7 = F_3 ( V_2 -> V_9 , V_2 -> V_10 -> V_34 , V_5 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_42 . V_72 = V_83 ;
return 0 ;
}
}
return - V_49 ;
}
static int F_21 ( struct V_30 * V_31 ,
struct V_51 const * V_52 , long V_4 )
{
switch ( V_4 ) {
case V_70 :
switch ( V_52 -> type ) {
case V_59 :
return V_73 ;
default:
return V_76 ;
}
default:
return V_76 ;
}
return - V_49 ;
}
static int F_22 ( struct V_1 * V_2 , int V_23 )
{
int V_7 , V_83 ;
T_2 V_5 ;
for ( V_83 = 0 ; V_83 < F_20 ( V_74 ) ; ++ V_83 ) {
if ( V_74 [ V_83 ] == V_23 ) {
V_5 = ( V_83 << V_40 ) ;
V_7 = F_3 ( V_2 -> V_9 , V_2 -> V_10 -> V_41 , V_5 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_42 . V_75 = V_83 ;
return 0 ;
}
}
return - V_49 ;
}
static int F_23 ( struct V_30 * V_31 ,
struct V_51 const * V_52 ,
int V_23 , int V_53 , long V_4 )
{
struct V_1 * V_2 = F_9 ( V_31 ) ;
int V_7 ;
F_17 ( & V_31 -> V_56 ) ;
if ( V_2 -> V_42 . V_57 ) {
V_7 = - V_84 ;
goto V_85;
}
V_7 = F_5 ( V_2 , true ) ;
if ( V_7 )
goto V_85;
switch ( V_4 ) {
case V_70 :
switch ( V_52 -> type ) {
case V_59 :
V_7 = F_19 ( V_2 , V_53 ) ;
break;
case V_63 :
V_7 = F_22 ( V_2 , V_53 ) ;
break;
default:
V_7 = - V_49 ;
break;
}
break;
case V_80 :
switch ( V_52 -> type ) {
case V_59 :
V_7 = F_10 ( V_2 ,
V_2 -> V_10 -> V_81 ,
V_52 -> V_62 , V_23 ) ;
break;
case V_63 :
V_7 = F_10 ( V_2 ,
V_2 -> V_10 -> V_82 ,
V_52 -> V_62 , V_23 ) ;
break;
default:
V_7 = - V_49 ;
}
default:
V_7 = - V_49 ;
break;
}
V_85:
V_7 |= F_5 ( V_2 , false ) ;
F_18 ( & V_31 -> V_56 ) ;
return V_7 ;
}
static int F_24 ( struct V_1 * V_2 , int V_86 )
{
const int V_87 [] = { 188 , 98 , 42 , 20 , 10 , 5 } ;
const int V_5 [] = { V_88 , V_89 ,
V_90 , V_35 ,
V_91 , V_92 } ;
int V_83 , V_93 , V_7 ;
T_2 V_94 ;
V_93 = ( V_86 >> 1 ) ;
V_83 = 0 ;
while ( ( V_93 < V_87 [ V_83 ] ) && ( V_83 < F_20 ( V_5 ) - 1 ) )
V_83 ++ ;
V_94 = V_5 [ V_83 ] ;
V_7 = F_7 ( V_2 , V_94 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_42 . V_24 = V_94 ;
return 0 ;
}
static T_4
F_25 ( struct V_95 * V_96 , struct V_97 * V_98 ,
const char * V_99 , T_5 V_100 )
{
T_6 V_101 ;
T_2 V_5 ;
int V_7 ;
struct V_30 * V_31 = F_26 ( V_96 ) ;
struct V_1 * V_2 = F_9 ( V_31 ) ;
if ( F_27 ( V_99 , 10 , & V_101 ) )
return - V_49 ;
if ( V_101 < V_102 ||
V_101 > V_103 )
return - V_49 ;
if ( V_101 == V_2 -> V_42 . V_101 )
return V_100 ;
F_17 ( & V_31 -> V_56 ) ;
if ( V_2 -> V_42 . V_57 ) {
V_7 = - V_84 ;
goto V_104;
}
V_7 = F_5 ( V_2 , true ) ;
if ( V_7 )
goto V_104;
V_5 = V_36 / V_101 - 1 ;
V_7 = F_3 ( V_2 -> V_9 , V_2 -> V_10 -> V_38 , V_5 ) ;
if ( V_7 )
goto V_104;
V_2 -> V_42 . V_101 = V_101 ;
V_7 = F_24 ( V_2 , V_101 ) ;
if ( V_7 )
goto V_104;
V_104:
V_7 |= F_5 ( V_2 , false ) ;
F_18 ( & V_31 -> V_56 ) ;
if ( V_7 )
return V_7 ;
return V_100 ;
}
static T_4
F_28 ( struct V_95 * V_96 , struct V_97 * V_98 ,
char * V_99 )
{
struct V_1 * V_2 = F_9 ( F_26 ( V_96 ) ) ;
return sprintf ( V_99 , L_1 , V_2 -> V_42 . V_101 ) ;
}
static T_4 F_29 ( struct V_95 * V_96 , struct V_97 * V_98 ,
char * V_99 )
{
struct V_1 * V_2 = F_9 ( F_26 ( V_96 ) ) ;
struct V_105 * V_106 = F_30 ( V_98 ) ;
T_7 * V_107 ;
switch ( V_106 -> V_108 ) {
case V_109 :
case V_110 :
V_107 = V_2 -> V_111 . V_112 ;
return sprintf ( V_99 , L_2 ,
V_107 [ 0 ] , V_107 [ 1 ] , V_107 [ 2 ] , V_107 [ 3 ] , V_107 [ 4 ] , V_107 [ 5 ] , V_107 [ 6 ] , V_107 [ 7 ] , V_107 [ 8 ] ) ;
default:
return - V_49 ;
}
}
static int F_31 ( struct V_30 * V_31 ,
struct V_113 * V_114 )
{
struct V_1 * V_2 = F_9 ( V_31 ) ;
if ( V_2 -> V_114 != V_114 )
return - V_49 ;
return 0 ;
}
static const struct V_115 *
F_32 ( const struct V_30 * V_31 ,
const struct V_51 * V_52 )
{
return & ( (struct V_1 * ) F_9 ( V_31 ) ) -> V_112 ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_7 ;
unsigned int V_116 ;
V_2 -> V_117 = & V_43 [ V_2 -> V_25 ] ;
V_2 -> V_10 = V_43 [ V_2 -> V_25 ] . V_10 ;
V_7 = F_3 ( V_2 -> V_9 , V_2 -> V_10 -> V_11 ,
V_118 ) ;
if ( V_7 )
return V_7 ;
F_4 ( V_119 ) ;
V_7 = F_2 ( V_2 -> V_9 , V_120 , & V_116 ) ;
if ( V_7 )
return V_7 ;
if ( V_116 != V_2 -> V_117 -> V_121 ) {
F_34 ( F_35 ( V_2 -> V_9 ) ,
L_3 ,
V_116 , V_2 -> V_117 -> V_121 , V_2 -> V_117 -> V_122 ) ;
}
V_7 = F_5 ( V_2 , false ) ;
if ( V_7 )
return V_7 ;
V_7 = F_5 ( V_2 , true ) ;
if ( V_7 )
return V_7 ;
V_7 = F_1 ( V_2 , false ,
V_65 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_1 ( V_2 , false ,
V_8 ) ;
if ( V_7 )
return V_7 ;
return 0 ;
}
int F_36 ( struct V_123 * V_123 , int V_124 , const char * V_122 ,
int (* F_37)( struct V_30 * ) , int V_25 )
{
struct V_1 * V_2 ;
struct V_30 * V_31 ;
struct V_125 * V_126 ;
struct V_95 * V_96 = F_35 ( V_123 ) ;
int V_7 ;
V_31 = F_38 ( V_96 , sizeof( * V_2 ) ) ;
if ( ! V_31 )
return - V_127 ;
F_39 ( F_20 ( V_43 ) != V_128 ) ;
if ( V_25 < 0 || V_25 >= V_128 ) {
F_40 ( V_96 , L_4 ,
V_25 , V_122 ) ;
return - V_129 ;
}
V_2 = F_9 ( V_31 ) ;
V_2 -> V_25 = V_25 ;
V_2 -> V_18 = 0 ;
V_2 -> V_124 = V_124 ;
V_2 -> V_9 = V_123 ;
V_126 = F_41 ( V_96 ) ;
if ( ! V_126 ) {
V_7 = F_42 ( V_96 , L_5 ,
& V_2 -> V_112 ) ;
if ( V_7 ) {
F_40 ( V_96 , L_6 ,
V_7 ) ;
return V_7 ;
}
} else {
V_2 -> V_111 = * V_126 ;
}
V_7 = F_33 ( V_2 ) ;
if ( V_7 )
return V_7 ;
if ( F_37 )
F_37 ( V_31 ) ;
V_7 = F_8 ( V_31 ) ;
if ( V_7 ) {
F_40 ( V_96 , L_7 ) ;
return V_7 ;
}
F_43 ( V_96 , V_31 ) ;
V_31 -> V_96 . V_130 = V_96 ;
if ( V_122 )
V_31 -> V_122 = V_122 ;
else
V_31 -> V_122 = F_44 ( V_96 ) ;
V_31 -> V_131 = V_132 ;
V_31 -> V_133 = F_20 ( V_132 ) ;
V_31 -> V_134 = & V_135 ;
V_31 -> V_136 = V_137 ;
V_7 = F_45 ( V_31 ,
V_138 ,
V_139 ,
NULL ) ;
if ( V_7 ) {
F_40 ( V_96 , L_8 , V_7 ) ;
return V_7 ;
}
V_7 = F_46 ( V_31 ) ;
if ( V_7 ) {
F_40 ( V_96 , L_9 , V_7 ) ;
goto V_140;
}
F_47 ( V_2 -> V_141 ) ;
F_48 ( & V_2 -> V_142 ) ;
V_7 = F_49 ( V_31 ) ;
if ( V_7 ) {
F_40 ( V_96 , L_10 , V_7 ) ;
goto V_143;
}
return 0 ;
V_143:
F_50 ( V_2 ) ;
V_140:
F_51 ( V_31 ) ;
return V_7 ;
}
int F_52 ( struct V_95 * V_96 )
{
struct V_30 * V_31 = F_53 ( V_96 ) ;
F_54 ( V_31 ) ;
F_50 ( F_9 ( V_31 ) ) ;
F_51 ( V_31 ) ;
return 0 ;
}
static int F_55 ( struct V_95 * V_96 )
{
return F_5 ( F_9 ( F_53 ( V_96 ) ) , true ) ;
}
static int F_56 ( struct V_95 * V_96 )
{
return F_5 ( F_9 ( F_53 ( V_96 ) ) , false ) ;
}
