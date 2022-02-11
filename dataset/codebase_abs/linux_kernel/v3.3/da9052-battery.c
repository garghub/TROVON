static inline int F_1 ( int V_1 )
{
return ( ( V_1 * 1000 ) / 512 ) + 2500 ;
}
static inline int F_2 ( int V_1 )
{
return ( V_1 * 3900 ) / 1000 ;
}
static int F_3 ( struct V_2 * V_3 ,
int * V_4 )
{
int V_5 ;
if ( V_3 -> V_6 == V_7 )
return - V_8 ;
V_5 = F_4 ( V_3 -> V_9 , V_10 ) ;
if ( V_5 < 0 )
return V_5 ;
* V_4 = F_2 ( V_5 & V_11 ) ;
return 0 ;
}
static int F_5 ( struct V_2 * V_3 , int * V_4 )
{
int V_5 ;
if ( V_3 -> V_6 == V_7 )
return - V_8 ;
V_5 = F_4 ( V_3 -> V_9 , V_12 ) ;
if ( V_5 < 0 )
return V_5 ;
* V_4 = F_2 ( V_5 & V_13 ) ;
return 0 ;
}
static int F_6 ( struct V_2 * V_3 , int * V_6 )
{
T_1 V_14 [ 2 ] = { 0 , 0 } ;
T_1 V_15 ;
T_1 V_16 ;
int V_5 ;
int V_17 ;
int V_18 ;
bool V_19 ;
bool V_20 ;
bool V_21 ;
bool V_22 ;
bool V_23 ;
bool V_24 ;
V_5 = F_7 ( V_3 -> V_9 , V_25 , 2 , V_14 ) ;
if ( V_5 < 0 )
return V_5 ;
V_15 = V_14 [ 0 ] ;
V_16 = V_14 [ 1 ] ;
V_19 = V_15 & V_26 ;
V_20 = V_15 & V_27 ;
V_21 = V_15 & V_28 ;
V_22 = V_15 & V_29 ;
V_23 = V_19 && V_20 ;
V_24 = V_21 && V_22 ;
if ( V_23 || V_24 ) {
V_3 -> V_30 = V_31 ;
if ( ( V_16 & V_32 ) != 0 ) {
V_5 = F_5 ( V_3 , & V_17 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_3 ( V_3 , & V_18 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_17 >= V_18 )
V_3 -> V_6 = V_33 ;
else
V_3 -> V_6 = V_34 ;
} else {
V_3 -> V_6 = V_33 ;
}
} else if ( V_20 || V_22 ) {
V_3 -> V_30 = V_31 ;
V_3 -> V_6 = V_34 ;
} else {
V_3 -> V_30 = V_35 ;
V_3 -> V_6 = V_7 ;
}
if ( V_6 != NULL )
* V_6 = V_3 -> V_6 ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 , int * V_36 )
{
int V_37 ;
V_37 = F_9 ( V_3 -> V_9 , V_38 ) ;
if ( V_37 < 0 )
return V_37 ;
* V_36 = F_1 ( V_37 ) ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 , int * V_39 )
{
int V_40 ;
V_40 = F_11 ( V_3 -> V_9 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( V_40 > V_41 )
* V_39 = 1 ;
else
* V_39 = 0 ;
return 0 ;
}
static int F_12 ( int V_42 , int V_43 ,
int V_44 , int V_45 ,
int V_46 )
{
int V_47 ;
V_47 = ( ( V_45 - V_44 ) * 1000 ) / ( V_43 - V_42 ) ;
V_47 = V_44 + ( ( ( V_46 - V_42 ) * V_47 ) / 1000 ) ;
return V_47 ;
}
unsigned char F_13 ( unsigned char V_48 )
{
int V_49 ;
if ( V_48 <= V_50 [ 0 ] )
return 0 ;
if ( V_48 > V_50 [ V_51 - 1 ] )
return V_51 - 1 ;
for ( V_49 = 0 ; V_49 < V_51 ; V_49 ++ ) {
if ( ( V_48 > V_50 [ V_49 ] ) &&
( V_48 <= F_14 ( V_50 [ V_49 ] , V_50 [ V_49 + 1 ] ) ) )
return V_49 ;
if ( ( V_48 > F_14 ( V_50 [ V_49 ] , V_50 [ V_49 + 1 ] ) )
&& ( V_48 <= V_50 [ V_49 ] ) )
return V_49 + 1 ;
}
}
static int F_15 ( struct V_2 * V_3 , int * V_52 )
{
int V_48 ;
int V_46 ;
int V_42 ;
int V_43 ;
int V_45 ;
int V_44 ;
int V_5 ;
int V_53 ;
int V_49 = 0 ;
int V_54 ;
V_5 = F_8 ( V_3 , & V_46 ) ;
if ( V_5 < 0 )
return V_5 ;
V_48 = F_11 ( V_3 -> V_9 ) ;
if ( V_48 < 0 )
return V_48 ;
V_49 = F_13 ( V_48 ) ;
if ( V_46 >= V_55 [ V_49 ] [ 0 ] [ 0 ] ) {
* V_52 = 100 ;
return 0 ;
}
if ( V_46 <= V_55 [ V_49 ] [ V_56 - 1 ] [ 0 ] ) {
* V_52 = 0 ;
return 0 ;
}
V_53 = 0 ;
for ( V_54 = 0 ; V_54 < ( V_56 - 1 ) ; V_54 ++ ) {
if ( ( V_46 <= V_55 [ V_49 ] [ V_54 ] [ 0 ] ) &&
( V_46 >= V_55 [ V_49 ] [ V_54 + 1 ] [ 0 ] ) ) {
V_43 = V_55 [ V_49 ] [ V_54 ] [ 0 ] ;
V_42 = V_55 [ V_49 ] [ V_54 + 1 ] [ 0 ] ;
V_45 = V_55 [ V_49 ] [ V_54 ] [ 1 ] ;
V_44 = V_55 [ V_49 ] [ V_54 + 1 ] [ 1 ] ;
V_53 = 1 ;
break;
}
}
if ( ! V_53 )
return - V_57 ;
* V_52 = F_12 ( V_42 , V_43 , V_44 ,
V_45 , V_46 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 , int * V_58 )
{
int V_5 ;
int V_59 ;
int V_52 ;
V_5 = F_10 ( V_3 , & V_59 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_59 ) {
V_3 -> V_58 = V_60 ;
return 0 ;
}
if ( V_3 -> V_58 != V_61 ) {
V_5 = F_15 ( V_3 , & V_52 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_52 < V_62 )
V_3 -> V_58 = V_63 ;
else
V_3 -> V_58 = V_64 ;
}
* V_58 = V_3 -> V_58 ;
return 0 ;
}
static T_2 F_17 ( int V_65 , void * V_66 )
{
struct V_2 * V_3 = V_66 ;
V_65 -= V_3 -> V_9 -> V_67 ;
if ( V_65 == V_68 )
V_3 -> V_6 = V_69 ;
else
F_6 ( V_3 , NULL ) ;
if ( V_65 == V_68 || V_65 == V_70 ||
V_65 == V_71 || V_65 == V_72 ) {
F_18 ( & V_3 -> V_73 ) ;
}
return V_74 ;
}
static int F_19 ( struct V_75 * V_76 ,
unsigned long V_77 , void * V_66 )
{
T_1 V_78 ;
T_1 V_79 ;
int * V_4 = V_66 ;
int V_5 ;
struct V_2 * V_3 = F_20 ( V_76 , struct V_2 ,
V_76 ) ;
if ( V_3 -> V_6 == V_7 )
return - V_80 ;
V_5 = F_4 ( V_3 -> V_9 , V_81 ) ;
if ( V_5 & V_82 )
return - V_80 ;
if ( V_3 -> V_9 -> V_83 == V_84 )
V_78 = 0 ;
else
V_78 = 1 ;
if ( * V_4 < V_85 [ V_78 ] [ 0 ] ||
* V_4 > V_85 [ V_78 ] [ V_86 - 1 ] )
return - V_8 ;
for ( V_79 = 0 ; V_79 <= V_86 - 1 ; V_79 ++ ) {
if ( * V_4 <= V_85 [ V_78 ] [ V_79 ] )
break;
}
return F_21 ( V_3 -> V_9 , V_87 ,
V_88 , V_79 ) ;
}
static int F_22 ( struct V_89 * V_73 ,
enum V_90 V_91 ,
union V_92 * V_93 )
{
int V_5 ;
int V_39 ;
struct V_2 * V_3 = F_20 ( V_73 , struct V_2 ,
V_73 ) ;
V_5 = F_10 ( V_3 , & V_39 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_39 && V_91 != V_94 )
return - V_95 ;
switch ( V_91 ) {
case V_96 :
V_5 = F_6 ( V_3 , & V_93 -> V_97 ) ;
break;
case V_98 :
V_93 -> V_97 =
( V_3 -> V_30 == V_35 ) ? 0 : 1 ;
break;
case V_94 :
V_5 = F_10 ( V_3 , & V_93 -> V_97 ) ;
break;
case V_99 :
V_5 = F_16 ( V_3 , & V_93 -> V_97 ) ;
break;
case V_100 :
V_93 -> V_97 = V_101 * 1000 ;
break;
case V_102 :
V_5 = F_8 ( V_3 , & V_93 -> V_97 ) ;
break;
case V_103 :
V_5 = F_5 ( V_3 , & V_93 -> V_97 ) ;
break;
case V_104 :
V_5 = F_15 ( V_3 , & V_93 -> V_97 ) ;
break;
case V_105 :
V_93 -> V_97 = F_11 ( V_3 -> V_9 ) ;
V_5 = V_93 -> V_97 ;
break;
case V_106 :
V_93 -> V_97 = V_107 ;
break;
default:
return - V_8 ;
}
return V_5 ;
}
static T_3 T_4 F_23 ( struct V_108 * V_109 )
{
struct V_110 * V_111 ;
struct V_2 * V_3 ;
int V_5 ;
int V_65 ;
int V_49 ;
V_3 = F_24 ( sizeof( struct V_2 ) , V_112 ) ;
if ( ! V_3 )
return - V_113 ;
V_3 -> V_9 = F_25 ( V_109 -> V_114 . V_115 ) ;
V_3 -> V_73 = V_116 ;
V_3 -> V_30 = V_35 ;
V_3 -> V_6 = V_117 ;
V_3 -> V_58 = V_60 ;
V_3 -> V_76 . V_118 = F_19 ;
V_111 = V_3 -> V_9 -> V_114 -> V_119 ;
if ( V_111 != NULL && V_111 -> V_120 )
V_3 -> V_73 . V_120 = V_111 -> V_120 ;
else
V_3 -> V_73 . V_120 = 1 ;
for ( V_49 = 0 ; V_49 < F_26 ( V_121 ) ; V_49 ++ ) {
V_65 = F_27 ( V_109 , V_121 [ V_49 ] ) ;
V_5 = F_28 ( V_3 -> V_9 -> V_67 + V_65 ,
NULL , F_17 ,
V_122 | V_123 ,
V_121 [ V_49 ] , V_3 ) ;
if ( V_5 != 0 ) {
F_29 ( V_3 -> V_9 -> V_114 ,
L_1 ,
V_121 [ V_49 ] , V_65 , V_5 ) ;
goto V_124;
}
}
V_5 = F_30 ( & V_109 -> V_114 , & V_3 -> V_73 ) ;
if ( V_5 )
goto V_124;
return 0 ;
V_124:
for (; V_49 >= 0 ; V_49 -- ) {
V_65 = F_27 ( V_109 , V_121 [ V_49 ] ) ;
F_31 ( V_3 -> V_9 -> V_67 + V_65 , V_3 ) ;
}
F_32 ( V_3 ) ;
return V_5 ;
}
static int T_5 F_33 ( struct V_108 * V_109 )
{
int V_49 ;
int V_65 ;
struct V_2 * V_3 = F_34 ( V_109 ) ;
for ( V_49 = 0 ; V_49 < F_26 ( V_121 ) ; V_49 ++ ) {
V_65 = F_27 ( V_109 , V_121 [ V_49 ] ) ;
F_31 ( V_3 -> V_9 -> V_67 + V_65 , V_3 ) ;
}
F_35 ( & V_3 -> V_73 ) ;
return 0 ;
}
static int T_6 F_36 ( void )
{
return F_37 ( & V_125 ) ;
}
static void T_7 F_38 ( void )
{
F_39 ( & V_125 ) ;
}
