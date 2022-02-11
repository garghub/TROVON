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
static int F_7 ( struct V_22 * V_23 )
{
int V_7 ;
T_2 V_5 ;
struct V_1 * V_2 = F_8 ( V_23 ) ;
V_7 = F_5 ( V_2 , true ) ;
if ( V_7 )
return V_7 ;
V_5 = ( V_24 << V_25 ) ;
V_7 = F_3 ( V_2 -> V_9 , V_2 -> V_10 -> V_26 , V_5 ) ;
if ( V_7 )
return V_7 ;
V_5 = V_27 ;
V_7 = F_3 ( V_2 -> V_9 , V_2 -> V_10 -> V_28 , V_5 ) ;
if ( V_7 )
return V_7 ;
V_5 = V_29 / V_30 - 1 ;
V_7 = F_3 ( V_2 -> V_9 , V_2 -> V_10 -> V_31 , V_5 ) ;
if ( V_7 )
return V_7 ;
V_5 = ( V_32 << V_33 ) ;
V_7 = F_3 ( V_2 -> V_9 , V_2 -> V_10 -> V_34 , V_5 ) ;
if ( V_7 )
return V_7 ;
memcpy ( & V_2 -> V_35 , V_36 [ V_2 -> V_37 ] . V_38 ,
sizeof( struct V_39 ) ) ;
V_7 = F_5 ( V_2 , false ) ;
return V_7 ;
}
static int F_9 ( struct V_1 * V_2 , int V_10 ,
int V_40 , int V_41 )
{
int V_42 , V_7 ;
T_3 V_5 = F_10 ( V_41 ) ;
V_42 = ( V_40 - V_43 ) * 2 ;
V_7 = F_11 ( V_2 -> V_9 , V_10 + V_42 , ( T_2 * ) & V_5 , 2 ) ;
if ( V_7 )
return - V_44 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , int V_10 ,
int V_40 , int * V_41 )
{
int V_42 , V_7 ;
T_3 V_5 ;
V_42 = ( V_40 - V_43 ) * 2 ;
V_7 = F_13 ( V_2 -> V_9 , V_10 + V_42 , ( T_2 * ) & V_5 , 2 ) ;
if ( V_7 )
return - V_44 ;
* V_41 = ( short ) F_14 ( & V_5 ) ;
return V_45 ;
}
static int
F_15 ( struct V_22 * V_23 ,
struct V_46 const * V_47 ,
int * V_41 , int * V_48 , long V_4 )
{
struct V_1 * V_2 = F_8 ( V_23 ) ;
int V_49 = 0 ;
switch ( V_4 ) {
case V_50 :
{
int V_7 ;
V_49 = V_45 ;
V_7 = 0 ;
F_16 ( & V_23 -> V_51 ) ;
if ( ! V_2 -> V_35 . V_52 ) {
V_7 = F_5 ( V_2 , true ) ;
if ( V_7 )
goto V_53;
}
switch ( V_47 -> type ) {
case V_54 :
if ( ! V_2 -> V_35 . V_55 ||
! V_2 -> V_35 . V_52 ) {
V_7 = F_1 ( V_2 , true ,
V_8 ) ;
if ( V_7 )
goto V_53;
}
V_49 = F_12 ( V_2 , V_2 -> V_10 -> V_56 ,
V_47 -> V_57 , V_41 ) ;
if ( ! V_2 -> V_35 . V_55 ||
! V_2 -> V_35 . V_52 ) {
V_7 = F_1 ( V_2 , false ,
V_8 ) ;
if ( V_7 )
goto V_53;
}
break;
case V_58 :
if ( ! V_2 -> V_35 . V_59 ||
! V_2 -> V_35 . V_52 ) {
V_7 = F_1 ( V_2 , true ,
V_60 ) ;
if ( V_7 )
goto V_53;
}
V_49 = F_12 ( V_2 , V_2 -> V_10 -> V_61 ,
V_47 -> V_57 , V_41 ) ;
if ( ! V_2 -> V_35 . V_59 ||
! V_2 -> V_35 . V_52 ) {
V_7 = F_1 ( V_2 , false ,
V_60 ) ;
if ( V_7 )
goto V_53;
}
break;
case V_62 :
F_4 ( V_63 ) ;
V_49 = F_12 ( V_2 , V_2 -> V_10 -> V_64 ,
V_43 , V_41 ) ;
break;
default:
V_49 = - V_44 ;
break;
}
V_53:
if ( ! V_2 -> V_35 . V_52 )
V_7 |= F_5 ( V_2 , false ) ;
F_17 ( & V_23 -> V_51 ) ;
if ( V_7 )
return V_7 ;
return V_49 ;
}
case V_65 :
switch ( V_47 -> type ) {
case V_54 :
* V_41 = 0 ;
* V_48 = V_66 [ V_2 -> V_35 . V_67 ] ;
return V_68 ;
case V_58 :
* V_41 = 0 ;
* V_48 = V_69 [ V_2 -> V_35 . V_70 ] ;
return V_71 ;
case V_62 :
* V_41 = 0 ;
* V_48 = V_72 ;
return V_71 ;
default:
return - V_44 ;
}
case V_73 :
switch ( V_47 -> type ) {
case V_62 :
* V_41 = V_74 ;
return V_45 ;
default:
return - V_44 ;
}
case V_75 :
switch ( V_47 -> type ) {
case V_54 :
V_49 = F_12 ( V_2 , V_2 -> V_10 -> V_76 ,
V_47 -> V_57 , V_41 ) ;
return V_45 ;
case V_58 :
V_49 = F_12 ( V_2 , V_2 -> V_10 -> V_77 ,
V_47 -> V_57 , V_41 ) ;
return V_45 ;
default:
return - V_44 ;
}
default:
return - V_44 ;
}
}
static int F_18 ( struct V_1 * V_2 , int V_41 )
{
int V_7 , V_78 ;
T_2 V_5 ;
for ( V_78 = 0 ; V_78 < F_19 ( V_66 ) ; ++ V_78 ) {
if ( V_66 [ V_78 ] == V_41 ) {
V_5 = ( V_78 << V_25 ) ;
V_7 = F_3 ( V_2 -> V_9 , V_2 -> V_10 -> V_26 , V_5 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_35 . V_67 = V_78 ;
return 0 ;
}
}
return - V_44 ;
}
static int F_20 ( struct V_22 * V_23 ,
struct V_46 const * V_47 , long V_4 )
{
switch ( V_4 ) {
case V_65 :
switch ( V_47 -> type ) {
case V_54 :
return V_68 ;
default:
return V_71 ;
}
default:
return V_71 ;
}
return - V_44 ;
}
static int F_21 ( struct V_1 * V_2 , int V_41 )
{
int V_7 , V_78 ;
T_2 V_5 ;
for ( V_78 = 0 ; V_78 < F_19 ( V_69 ) ; ++ V_78 ) {
if ( V_69 [ V_78 ] == V_41 ) {
V_5 = ( V_78 << V_33 ) ;
V_7 = F_3 ( V_2 -> V_9 , V_2 -> V_10 -> V_34 , V_5 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_35 . V_70 = V_78 ;
return 0 ;
}
}
return - V_44 ;
}
static int F_22 ( struct V_22 * V_23 ,
struct V_46 const * V_47 ,
int V_41 , int V_48 , long V_4 )
{
struct V_1 * V_2 = F_8 ( V_23 ) ;
int V_7 ;
F_16 ( & V_23 -> V_51 ) ;
if ( V_2 -> V_35 . V_52 ) {
V_7 = - V_79 ;
goto V_80;
}
V_7 = F_5 ( V_2 , true ) ;
if ( V_7 )
goto V_80;
switch ( V_4 ) {
case V_65 :
switch ( V_47 -> type ) {
case V_54 :
V_7 = F_18 ( V_2 , V_48 ) ;
break;
case V_58 :
V_7 = F_21 ( V_2 , V_48 ) ;
break;
default:
V_7 = - V_44 ;
break;
}
break;
case V_75 :
switch ( V_47 -> type ) {
case V_54 :
V_7 = F_9 ( V_2 ,
V_2 -> V_10 -> V_76 ,
V_47 -> V_57 , V_41 ) ;
break;
case V_58 :
V_7 = F_9 ( V_2 ,
V_2 -> V_10 -> V_77 ,
V_47 -> V_57 , V_41 ) ;
break;
default:
V_7 = - V_44 ;
}
default:
V_7 = - V_44 ;
break;
}
V_80:
V_7 |= F_5 ( V_2 , false ) ;
F_17 ( & V_23 -> V_51 ) ;
return V_7 ;
}
static int F_23 ( struct V_1 * V_2 , int V_81 )
{
const int V_82 [] = { 188 , 98 , 42 , 20 , 10 , 5 } ;
const int V_5 [] = { V_83 , V_84 ,
V_85 , V_27 ,
V_86 , V_87 } ;
int V_78 , V_88 , V_7 ;
T_2 V_89 ;
V_88 = ( V_81 >> 1 ) ;
V_78 = 0 ;
while ( ( V_88 < V_82 [ V_78 ] ) && ( V_78 < F_19 ( V_5 ) - 1 ) )
V_78 ++ ;
V_89 = V_5 [ V_78 ] ;
V_7 = F_3 ( V_2 -> V_9 , V_2 -> V_10 -> V_28 , V_89 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_35 . V_28 = V_89 ;
return 0 ;
}
static T_4
F_24 ( struct V_90 * V_91 , struct V_92 * V_93 ,
const char * V_94 , T_5 V_95 )
{
T_6 V_96 ;
T_2 V_5 ;
int V_7 ;
struct V_22 * V_23 = F_25 ( V_91 ) ;
struct V_1 * V_2 = F_8 ( V_23 ) ;
if ( F_26 ( V_94 , 10 , & V_96 ) )
return - V_44 ;
if ( V_96 < V_97 ||
V_96 > V_98 )
return - V_44 ;
if ( V_96 == V_2 -> V_35 . V_96 )
return V_95 ;
F_16 ( & V_23 -> V_51 ) ;
if ( V_2 -> V_35 . V_52 ) {
V_7 = - V_79 ;
goto V_99;
}
V_7 = F_5 ( V_2 , true ) ;
if ( V_7 )
goto V_99;
V_5 = V_29 / V_96 - 1 ;
V_7 = F_3 ( V_2 -> V_9 , V_2 -> V_10 -> V_31 , V_5 ) ;
if ( V_7 )
goto V_99;
V_2 -> V_35 . V_96 = V_96 ;
V_7 = F_23 ( V_2 , V_96 ) ;
if ( V_7 )
goto V_99;
V_99:
V_7 |= F_5 ( V_2 , false ) ;
F_17 ( & V_23 -> V_51 ) ;
if ( V_7 )
return V_7 ;
return V_95 ;
}
static T_4
F_27 ( struct V_90 * V_91 , struct V_92 * V_93 ,
char * V_94 )
{
struct V_1 * V_2 = F_8 ( F_25 ( V_91 ) ) ;
return sprintf ( V_94 , L_1 , V_2 -> V_35 . V_96 ) ;
}
static T_4 F_28 ( struct V_90 * V_91 , struct V_92 * V_93 ,
char * V_94 )
{
struct V_1 * V_2 = F_8 ( F_25 ( V_91 ) ) ;
struct V_100 * V_101 = F_29 ( V_93 ) ;
T_7 * V_102 ;
switch ( V_101 -> V_103 ) {
case V_104 :
case V_105 :
V_102 = V_2 -> V_106 . V_107 ;
return sprintf ( V_94 , L_2 ,
V_102 [ 0 ] , V_102 [ 1 ] , V_102 [ 2 ] , V_102 [ 3 ] , V_102 [ 4 ] , V_102 [ 5 ] , V_102 [ 6 ] , V_102 [ 7 ] , V_102 [ 8 ] ) ;
default:
return - V_44 ;
}
}
static int F_30 ( struct V_22 * V_23 ,
struct V_108 * V_109 )
{
struct V_1 * V_2 = F_8 ( V_23 ) ;
if ( V_2 -> V_109 != V_109 )
return - V_44 ;
return 0 ;
}
static const struct V_110 *
F_31 ( const struct V_22 * V_23 ,
const struct V_46 * V_47 )
{
return & ( (struct V_1 * ) F_8 ( V_23 ) ) -> V_107 ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_7 ;
unsigned int V_111 ;
V_2 -> V_112 = & V_36 [ V_2 -> V_37 ] ;
V_2 -> V_10 = V_36 [ V_2 -> V_37 ] . V_10 ;
V_7 = F_3 ( V_2 -> V_9 , V_2 -> V_10 -> V_11 ,
V_113 ) ;
if ( V_7 )
return V_7 ;
F_4 ( V_114 ) ;
V_7 = F_2 ( V_2 -> V_9 , V_115 , & V_111 ) ;
if ( V_7 )
return V_7 ;
if ( V_111 != V_2 -> V_112 -> V_116 ) {
F_33 ( F_34 ( V_2 -> V_9 ) ,
L_3 ,
V_111 , V_2 -> V_112 -> V_116 , V_2 -> V_112 -> V_117 ) ;
}
V_7 = F_5 ( V_2 , false ) ;
if ( V_7 )
return V_7 ;
V_7 = F_5 ( V_2 , true ) ;
if ( V_7 )
return V_7 ;
V_7 = F_1 ( V_2 , false ,
V_60 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_1 ( V_2 , false ,
V_8 ) ;
if ( V_7 )
return V_7 ;
return 0 ;
}
int F_35 ( struct V_118 * V_118 , int V_119 , const char * V_117 ,
int (* F_36)( struct V_22 * ) , int V_37 )
{
struct V_1 * V_2 ;
struct V_22 * V_23 ;
struct V_120 * V_121 ;
struct V_90 * V_91 = F_34 ( V_118 ) ;
int V_7 ;
V_23 = F_37 ( V_91 , sizeof( * V_2 ) ) ;
if ( ! V_23 )
return - V_122 ;
F_38 ( F_19 ( V_36 ) != V_123 ) ;
if ( V_37 < 0 || V_37 >= V_123 ) {
F_39 ( V_91 , L_4 ,
V_37 , V_117 ) ;
return - V_124 ;
}
V_2 = F_8 ( V_23 ) ;
V_2 -> V_37 = V_37 ;
V_2 -> V_18 = 0 ;
V_2 -> V_119 = V_119 ;
V_2 -> V_9 = V_118 ;
V_121 = F_40 ( V_91 ) ;
if ( ! V_121 ) {
V_7 = F_41 ( V_91 , L_5 ,
& V_2 -> V_107 ) ;
if ( V_7 ) {
F_39 ( V_91 , L_6 ,
V_7 ) ;
return V_7 ;
}
} else {
V_2 -> V_106 = * V_121 ;
}
V_7 = F_32 ( V_2 ) ;
if ( V_7 )
return V_7 ;
if ( F_36 )
F_36 ( V_23 ) ;
V_7 = F_7 ( V_23 ) ;
if ( V_7 ) {
F_39 ( V_91 , L_7 ) ;
return V_7 ;
}
F_42 ( V_91 , V_23 ) ;
V_23 -> V_91 . V_125 = V_91 ;
if ( V_117 )
V_23 -> V_117 = V_117 ;
else
V_23 -> V_117 = F_43 ( V_91 ) ;
V_23 -> V_126 = V_127 ;
V_23 -> V_128 = F_19 ( V_127 ) ;
V_23 -> V_129 = & V_130 ;
V_23 -> V_131 = V_132 ;
V_7 = F_44 ( V_23 ,
V_133 ,
V_134 ,
NULL ) ;
if ( V_7 ) {
F_39 ( V_91 , L_8 , V_7 ) ;
return V_7 ;
}
V_7 = F_45 ( V_23 ) ;
if ( V_7 ) {
F_39 ( V_91 , L_9 , V_7 ) ;
goto V_135;
}
F_46 ( V_2 -> V_136 ) ;
F_47 ( & V_2 -> V_137 ) ;
V_7 = F_48 ( V_23 ) ;
if ( V_7 ) {
F_39 ( V_91 , L_10 , V_7 ) ;
goto V_138;
}
return 0 ;
V_138:
F_49 ( V_2 ) ;
V_135:
F_50 ( V_23 ) ;
return V_7 ;
}
int F_51 ( struct V_90 * V_91 )
{
struct V_22 * V_23 = F_52 ( V_91 ) ;
F_53 ( V_23 ) ;
F_49 ( F_8 ( V_23 ) ) ;
F_50 ( V_23 ) ;
return 0 ;
}
static int F_54 ( struct V_90 * V_91 )
{
return F_5 ( F_8 ( F_52 ( V_91 ) ) , true ) ;
}
static int F_55 ( struct V_90 * V_91 )
{
return F_5 ( F_8 ( F_52 ( V_91 ) ) , false ) ;
}
