int F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
return F_2 ( V_2 -> V_5 , V_3 , 1 , & V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
int V_6 ;
T_1 V_7 [ 2 ] ;
struct V_8 V_9 [ 1 ] = {
{
. V_10 = V_2 -> V_5 -> V_10 ,
. V_11 = 0 ,
. V_12 = sizeof( V_7 ) ,
. V_7 = V_7 ,
}
} ;
V_7 [ 0 ] = V_3 ;
V_7 [ 1 ] = V_4 ;
V_6 = F_4 ( V_2 -> V_5 -> V_13 , V_9 , 1 ) ;
if ( V_6 != 1 )
return V_6 ;
return 0 ;
}
static int F_5 ( struct V_14 * V_15 , void * V_16 ,
T_2 V_17 )
{
struct V_18 * V_19 = V_16 ;
struct V_1 * V_2 = F_6 ( V_19 ) ;
int V_6 = 0 ;
F_7 ( & V_19 -> V_20 ) ;
if ( ! V_2 -> V_21 ) {
V_6 = F_3 ( V_2 , V_2 -> V_3 -> V_22 ,
0 ) ;
if ( V_6 )
goto V_23;
F_8 ( V_24 ) ;
}
if ( ! V_6 ) {
V_2 -> V_21 ++ ;
V_6 = F_3 ( V_2 , V_2 -> V_3 -> V_25 ,
V_2 -> V_5 -> V_26 |
V_27 ) ;
}
V_23:
F_9 ( & V_19 -> V_20 ) ;
return V_6 ;
}
static int F_10 ( struct V_14 * V_15 ,
void * V_16 , T_2 V_17 )
{
struct V_18 * V_19 = V_16 ;
struct V_1 * V_2 = F_6 ( V_19 ) ;
F_7 ( & V_19 -> V_20 ) ;
F_3 ( V_2 , V_2 -> V_3 -> V_25 ,
V_2 -> V_5 -> V_26 ) ;
V_2 -> V_21 -- ;
if ( ! V_2 -> V_21 )
F_3 ( V_2 , V_2 -> V_3 -> V_22 ,
V_28 ) ;
F_9 ( & V_19 -> V_20 ) ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 , bool V_29 , T_2 V_30 )
{
T_1 V_4 , V_31 ;
int V_32 ;
if ( V_33 == V_30 ) {
V_32 = F_12 ( V_2 -> V_5 ,
V_2 -> V_3 -> V_22 , 1 , & V_31 ) ;
if ( V_32 != 1 )
return V_32 ;
V_31 &= ~ V_34 ;
}
if ( ( V_33 == V_30 ) && ( ! V_29 ) ) {
V_31 |= V_35 ;
V_32 = F_1 ( V_2 , V_2 -> V_3 -> V_22 , V_31 ) ;
if ( V_32 )
return V_32 ;
}
V_32 = F_12 ( V_2 -> V_5 ,
V_2 -> V_3 -> V_36 , 1 , & V_4 ) ;
if ( V_32 != 1 )
return V_32 ;
if ( V_29 )
V_4 &= ~ V_30 ;
else
V_4 |= V_30 ;
V_32 = F_1 ( V_2 , V_2 -> V_3 -> V_36 , V_4 ) ;
if ( V_32 )
return V_32 ;
if ( V_29 ) {
F_8 ( V_37 ) ;
if ( V_33 == V_30 ) {
V_31 |= V_38 ;
V_32 = F_1 ( V_2 ,
V_2 -> V_3 -> V_22 , V_31 ) ;
if ( V_32 )
return V_32 ;
}
}
return 0 ;
}
int F_13 ( struct V_1 * V_2 , bool V_39 )
{
int V_32 = 0 ;
if ( V_39 ) {
if ( ! V_2 -> V_21 )
V_32 = F_1 ( V_2 , V_2 -> V_3 -> V_22 ,
0 ) ;
if ( ! V_32 )
V_2 -> V_21 ++ ;
} else {
V_2 -> V_21 -- ;
if ( ! V_2 -> V_21 )
V_32 = F_1 ( V_2 , V_2 -> V_3 -> V_22 ,
V_28 ) ;
}
if ( V_32 )
return V_32 ;
if ( V_39 )
F_8 ( V_24 ) ;
return 0 ;
}
static int F_14 ( struct V_18 * V_19 )
{
int V_32 ;
T_1 V_4 ;
struct V_1 * V_2 = F_6 ( V_19 ) ;
V_32 = F_13 ( V_2 , true ) ;
if ( V_32 )
return V_32 ;
V_4 = ( V_40 << V_41 ) ;
V_32 = F_1 ( V_2 , V_2 -> V_3 -> V_42 , V_4 ) ;
if ( V_32 )
return V_32 ;
V_4 = V_43 ;
V_32 = F_1 ( V_2 , V_2 -> V_3 -> V_44 , V_4 ) ;
if ( V_32 )
return V_32 ;
V_4 = V_45 / V_46 - 1 ;
V_32 = F_1 ( V_2 , V_2 -> V_3 -> V_47 , V_4 ) ;
if ( V_32 )
return V_32 ;
V_4 = ( V_48 << V_49 ) ;
V_32 = F_1 ( V_2 , V_2 -> V_3 -> V_50 , V_4 ) ;
if ( V_32 )
return V_32 ;
memcpy ( & V_2 -> V_51 , V_52 [ V_2 -> V_53 ] . V_54 ,
sizeof( struct V_55 ) ) ;
V_32 = F_13 ( V_2 , false ) ;
return V_32 ;
}
static int F_15 ( struct V_1 * V_2 , int V_3 ,
int V_56 , int * V_57 )
{
int V_58 , V_32 ;
T_3 V_4 ;
V_58 = ( V_56 - V_59 ) * 2 ;
V_32 = F_12 ( V_2 -> V_5 , V_3 + V_58 , 2 ,
( T_1 * ) & V_4 ) ;
if ( V_32 != 2 )
return - V_60 ;
* V_57 = ( short ) F_16 ( & V_4 ) ;
return V_61 ;
}
static int F_17 ( struct V_18 * V_19 ,
struct V_62 const * V_63 ,
int * V_57 ,
int * V_64 ,
long V_30 ) {
struct V_1 * V_2 = F_6 ( V_19 ) ;
switch ( V_30 ) {
case V_65 :
{
int V_6 , V_32 ;
V_6 = V_61 ;
V_32 = 0 ;
F_7 ( & V_19 -> V_20 ) ;
if ( ! V_2 -> V_51 . V_66 ) {
V_32 = F_13 ( V_2 , true ) ;
if ( V_32 )
goto V_67;
}
switch ( V_63 -> type ) {
case V_68 :
if ( ! V_2 -> V_51 . V_69 ||
! V_2 -> V_51 . V_66 ) {
V_32 = F_11 ( V_2 , true ,
V_33 ) ;
if ( V_32 )
goto V_67;
}
V_6 = F_15 ( V_2 , V_2 -> V_3 -> V_70 ,
V_63 -> V_71 , V_57 ) ;
if ( ! V_2 -> V_51 . V_69 ||
! V_2 -> V_51 . V_66 ) {
V_32 = F_11 ( V_2 , false ,
V_33 ) ;
if ( V_32 )
goto V_67;
}
break;
case V_72 :
if ( ! V_2 -> V_51 . V_73 ||
! V_2 -> V_51 . V_66 ) {
V_32 = F_11 ( V_2 , true ,
V_74 ) ;
if ( V_32 )
goto V_67;
}
V_6 = F_15 ( V_2 , V_2 -> V_3 -> V_75 ,
V_63 -> V_71 , V_57 ) ;
if ( ! V_2 -> V_51 . V_73 ||
! V_2 -> V_51 . V_66 ) {
V_32 = F_11 ( V_2 , false ,
V_74 ) ;
if ( V_32 )
goto V_67;
}
break;
case V_76 :
F_8 ( V_77 ) ;
F_15 ( V_2 , V_2 -> V_3 -> V_78 ,
V_59 , V_57 ) ;
break;
default:
V_6 = - V_60 ;
break;
}
V_67:
if ( ! V_2 -> V_51 . V_66 )
V_32 |= F_13 ( V_2 , false ) ;
F_9 ( & V_19 -> V_20 ) ;
if ( V_32 )
return V_32 ;
return V_6 ;
}
case V_79 :
switch ( V_63 -> type ) {
case V_68 :
* V_57 = 0 ;
* V_64 = V_80 [ V_2 -> V_51 . V_81 ] ;
return V_82 ;
case V_72 :
* V_57 = 0 ;
* V_64 = V_83 [ V_2 -> V_51 . V_84 ] ;
return V_85 ;
case V_76 :
* V_57 = 0 ;
* V_64 = V_86 ;
return V_85 ;
default:
return - V_60 ;
}
case V_87 :
switch ( V_63 -> type ) {
case V_76 :
* V_57 = V_88 ;
return V_61 ;
default:
return - V_60 ;
}
default:
return - V_60 ;
}
}
static int F_18 ( struct V_1 * V_2 , int V_57 )
{
int V_32 , V_89 ;
T_1 V_4 ;
for ( V_89 = 0 ; V_89 < F_19 ( V_80 ) ; ++ V_89 ) {
if ( V_80 [ V_89 ] == V_57 ) {
V_4 = ( V_89 << V_41 ) ;
V_32 = F_1 ( V_2 ,
V_2 -> V_3 -> V_42 , V_4 ) ;
if ( V_32 )
return V_32 ;
V_2 -> V_51 . V_81 = V_89 ;
return 0 ;
}
}
return - V_60 ;
}
static int F_20 ( struct V_18 * V_19 ,
struct V_62 const * V_63 , long V_30 )
{
switch ( V_30 ) {
case V_79 :
switch ( V_63 -> type ) {
case V_68 :
return V_82 ;
default:
return V_85 ;
}
default:
return V_85 ;
}
return - V_60 ;
}
static int F_21 ( struct V_1 * V_2 , int V_57 )
{
int V_32 , V_89 ;
T_1 V_4 ;
for ( V_89 = 0 ; V_89 < F_19 ( V_83 ) ; ++ V_89 ) {
if ( V_83 [ V_89 ] == V_57 ) {
V_4 = ( V_89 << V_49 ) ;
V_32 = F_1 ( V_2 ,
V_2 -> V_3 -> V_50 , V_4 ) ;
if ( V_32 )
return V_32 ;
V_2 -> V_51 . V_84 = V_89 ;
return 0 ;
}
}
return - V_60 ;
}
static int F_22 ( struct V_18 * V_19 ,
struct V_62 const * V_63 ,
int V_57 ,
int V_64 ,
long V_30 ) {
struct V_1 * V_2 = F_6 ( V_19 ) ;
int V_32 ;
F_7 ( & V_19 -> V_20 ) ;
if ( V_2 -> V_51 . V_66 ) {
V_32 = - V_90 ;
goto V_91;
}
V_32 = F_13 ( V_2 , true ) ;
if ( V_32 )
goto V_91;
switch ( V_30 ) {
case V_79 :
switch ( V_63 -> type ) {
case V_68 :
V_32 = F_18 ( V_2 , V_64 ) ;
break;
case V_72 :
V_32 = F_21 ( V_2 , V_64 ) ;
break;
default:
V_32 = - V_60 ;
break;
}
break;
default:
V_32 = - V_60 ;
break;
}
V_91:
V_32 |= F_13 ( V_2 , false ) ;
F_9 ( & V_19 -> V_20 ) ;
return V_32 ;
}
static int F_23 ( struct V_1 * V_2 , int V_92 )
{
const int V_93 [] = { 188 , 98 , 42 , 20 , 10 , 5 } ;
const int V_4 [] = { V_94 , V_95 ,
V_96 , V_43 ,
V_97 , V_98 } ;
int V_89 , V_99 , V_32 ;
T_1 V_100 ;
V_99 = ( V_92 >> 1 ) ;
V_89 = 0 ;
while ( ( V_99 < V_93 [ V_89 ] ) && ( V_89 < F_19 ( V_4 ) - 1 ) )
V_89 ++ ;
V_100 = V_4 [ V_89 ] ;
V_32 = F_1 ( V_2 , V_2 -> V_3 -> V_44 , V_100 ) ;
if ( V_32 )
return V_32 ;
V_2 -> V_51 . V_44 = V_100 ;
return 0 ;
}
static T_4 F_24 ( struct V_101 * V_102 ,
struct V_103 * V_104 , const char * V_7 , T_5 V_105 )
{
T_6 V_106 ;
T_1 V_4 ;
int V_32 ;
struct V_18 * V_19 = F_25 ( V_102 ) ;
struct V_1 * V_2 = F_6 ( V_19 ) ;
if ( F_26 ( V_7 , 10 , & V_106 ) )
return - V_60 ;
if ( V_106 < V_107 ||
V_106 > V_108 )
return - V_60 ;
if ( V_106 == V_2 -> V_51 . V_106 )
return V_105 ;
F_7 ( & V_19 -> V_20 ) ;
if ( V_2 -> V_51 . V_66 ) {
V_32 = - V_90 ;
goto V_109;
}
V_32 = F_13 ( V_2 , true ) ;
if ( V_32 )
goto V_109;
V_4 = V_45 / V_106 - 1 ;
V_32 = F_1 ( V_2 , V_2 -> V_3 -> V_47 , V_4 ) ;
if ( V_32 )
goto V_109;
V_2 -> V_51 . V_106 = V_106 ;
V_32 = F_23 ( V_2 , V_106 ) ;
if ( V_32 )
goto V_109;
V_109:
V_32 |= F_13 ( V_2 , false ) ;
F_9 ( & V_19 -> V_20 ) ;
if ( V_32 )
return V_32 ;
return V_105 ;
}
static T_4 F_27 ( struct V_101 * V_102 ,
struct V_103 * V_104 , char * V_7 )
{
struct V_1 * V_2 = F_6 ( F_25 ( V_102 ) ) ;
return sprintf ( V_7 , L_1 , V_2 -> V_51 . V_106 ) ;
}
static T_4 F_28 ( struct V_101 * V_102 ,
struct V_103 * V_104 , char * V_7 )
{
struct V_1 * V_2 = F_6 ( F_25 ( V_102 ) ) ;
struct V_110 * V_111 = F_29 ( V_104 ) ;
T_7 * V_112 ;
switch ( V_111 -> V_113 ) {
case V_114 :
case V_115 :
V_112 = V_2 -> V_116 . V_117 ;
return sprintf ( V_7 , L_2 ,
V_112 [ 0 ] , V_112 [ 1 ] , V_112 [ 2 ] , V_112 [ 3 ] , V_112 [ 4 ] , V_112 [ 5 ] , V_112 [ 6 ] , V_112 [ 7 ] , V_112 [ 8 ] ) ;
default:
return - V_60 ;
}
}
static int F_30 ( struct V_18 * V_19 ,
struct V_118 * V_119 )
{
struct V_1 * V_2 = F_6 ( V_19 ) ;
if ( V_2 -> V_119 != V_119 )
return - V_60 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
const struct V_120 * V_121 )
{
int V_32 ;
V_2 -> V_53 = V_122 ;
V_2 -> V_123 = & V_52 [ V_2 -> V_53 ] ;
V_2 -> V_3 = V_52 [ V_2 -> V_53 ] . V_3 ;
V_32 = F_1 ( V_2 , V_2 -> V_3 -> V_22 ,
V_124 ) ;
if ( V_32 )
return V_32 ;
F_8 ( V_125 ) ;
V_32 = F_13 ( V_2 , false ) ;
if ( V_32 )
return V_32 ;
V_32 = F_13 ( V_2 , true ) ;
if ( V_32 )
return V_32 ;
V_32 = F_11 ( V_2 , false ,
V_74 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_11 ( V_2 , false ,
V_33 ) ;
if ( V_32 )
return V_32 ;
return 0 ;
}
static int F_32 ( struct V_126 * V_5 ,
const struct V_120 * V_121 )
{
struct V_1 * V_2 ;
struct V_18 * V_19 ;
struct V_127 * V_128 ;
int V_32 ;
if ( ! F_33 ( V_5 -> V_13 ,
V_129 ) )
return - V_130 ;
V_19 = F_34 ( & V_5 -> V_102 , sizeof( * V_2 ) ) ;
if ( ! V_19 )
return - V_131 ;
V_2 = F_6 ( V_19 ) ;
V_2 -> V_5 = V_5 ;
V_2 -> V_21 = 0 ;
V_128 = F_35 ( & V_5 -> V_102 ) ;
if ( V_128 )
V_2 -> V_116 = * V_128 ;
V_32 = F_31 ( V_2 , V_121 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_14 ( V_19 ) ;
if ( V_32 ) {
F_36 ( & V_5 -> V_102 ,
L_3 ) ;
return V_32 ;
}
F_37 ( V_5 , V_19 ) ;
V_19 -> V_102 . V_132 = & V_5 -> V_102 ;
if ( V_121 )
V_19 -> V_133 = ( char * ) V_121 -> V_133 ;
else
V_19 -> V_133 = ( char * ) F_38 ( & V_5 -> V_102 ) ;
V_19 -> V_134 = V_135 ;
V_19 -> V_136 = F_19 ( V_135 ) ;
V_19 -> V_137 = & V_138 ;
V_19 -> V_139 = V_140 ;
V_32 = F_39 ( V_19 ,
V_141 ,
V_142 ,
NULL ) ;
if ( V_32 ) {
F_36 ( & V_2 -> V_5 -> V_102 , L_4 ,
V_32 ) ;
return V_32 ;
}
V_32 = F_40 ( V_19 ) ;
if ( V_32 ) {
F_36 ( & V_2 -> V_5 -> V_102 , L_5 , V_32 ) ;
goto V_143;
}
F_41 ( V_2 -> V_144 ) ;
F_42 ( & V_2 -> V_145 ) ;
V_32 = F_43 ( V_19 ) ;
if ( V_32 ) {
F_36 ( & V_2 -> V_5 -> V_102 , L_6 , V_32 ) ;
goto V_146;
}
V_2 -> V_147 = F_44 ( V_5 -> V_13 ,
& V_5 -> V_102 ,
V_19 ,
0 , 0 , 0 ,
F_5 ,
F_10 ) ;
if ( ! V_2 -> V_147 ) {
V_32 = - V_148 ;
goto V_149;
}
V_32 = F_45 ( V_2 ) ;
if ( V_32 )
goto V_150;
return 0 ;
V_150:
F_46 ( V_2 -> V_147 ) ;
V_149:
F_47 ( V_19 ) ;
V_146:
F_48 ( V_2 ) ;
V_143:
F_49 ( V_19 ) ;
return V_32 ;
}
static int F_50 ( struct V_126 * V_5 )
{
struct V_18 * V_19 = F_51 ( V_5 ) ;
struct V_1 * V_2 = F_6 ( V_19 ) ;
F_52 ( V_2 ) ;
F_46 ( V_2 -> V_147 ) ;
F_47 ( V_19 ) ;
F_48 ( V_2 ) ;
F_49 ( V_19 ) ;
return 0 ;
}
static int F_53 ( struct V_101 * V_102 )
{
return F_13 (
F_6 ( F_51 ( F_54 ( V_102 ) ) ) , true ) ;
}
static int F_55 ( struct V_101 * V_102 )
{
return F_13 (
F_6 ( F_51 ( F_54 ( V_102 ) ) ) , false ) ;
}
