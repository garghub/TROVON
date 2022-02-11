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
static unsigned char F_13 ( unsigned char V_48 )
{
int V_49 ;
if ( V_48 <= V_50 [ 0 ] )
return 0 ;
if ( V_48 > V_50 [ V_51 - 1 ] )
return V_51 - 1 ;
for ( V_49 = 0 ; V_49 < V_51 - 1 ; V_49 ++ ) {
if ( ( V_48 > V_50 [ V_49 ] ) &&
( V_48 <= F_14 ( V_50 [ V_49 ] , V_50 [ V_49 + 1 ] ) ) )
return V_49 ;
if ( ( V_48 > F_14 ( V_50 [ V_49 ] , V_50 [ V_49 + 1 ] ) )
&& ( V_48 <= V_50 [ V_49 ] ) )
return V_49 + 1 ;
}
F_15 ( 1 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 , int * V_52 )
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
static int F_17 ( struct V_2 * V_3 , int * V_58 )
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
V_5 = F_16 ( V_3 , & V_52 ) ;
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
static T_2 F_18 ( int V_65 , void * V_66 )
{
struct V_2 * V_3 = V_66 ;
int V_67 ;
V_67 = F_19 ( V_3 -> V_9 -> V_68 , V_65 ) ;
V_65 -= V_67 ;
if ( V_65 == V_69 )
V_3 -> V_6 = V_70 ;
else
F_6 ( V_3 , NULL ) ;
if ( V_65 == V_69 || V_65 == V_71 ||
V_65 == V_72 || V_65 == V_73 ) {
F_20 ( & V_3 -> V_74 ) ;
}
return V_75 ;
}
static int F_21 ( struct V_76 * V_77 ,
unsigned long V_78 , void * V_66 )
{
T_1 V_79 ;
T_1 V_80 ;
int * V_4 = V_66 ;
int V_5 ;
struct V_2 * V_3 = F_22 ( V_77 , struct V_2 ,
V_77 ) ;
if ( V_3 -> V_6 == V_7 )
return - V_81 ;
V_5 = F_4 ( V_3 -> V_9 , V_82 ) ;
if ( V_5 & V_83 )
return - V_81 ;
if ( V_3 -> V_9 -> V_84 == V_85 )
V_79 = 0 ;
else
V_79 = 1 ;
if ( * V_4 < V_86 [ V_79 ] [ 0 ] ||
* V_4 > V_86 [ V_79 ] [ V_87 - 1 ] )
return - V_8 ;
for ( V_80 = 0 ; V_80 <= V_87 - 1 ; V_80 ++ ) {
if ( * V_4 <= V_86 [ V_79 ] [ V_80 ] )
break;
}
return F_23 ( V_3 -> V_9 , V_88 ,
V_89 , V_80 ) ;
}
static int F_24 ( struct V_90 * V_74 ,
enum V_91 V_92 ,
union V_93 * V_94 )
{
int V_5 ;
int V_39 ;
struct V_2 * V_3 = F_22 ( V_74 , struct V_2 ,
V_74 ) ;
V_5 = F_10 ( V_3 , & V_39 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_39 && V_92 != V_95 )
return - V_96 ;
switch ( V_92 ) {
case V_97 :
V_5 = F_6 ( V_3 , & V_94 -> V_98 ) ;
break;
case V_99 :
V_94 -> V_98 =
( V_3 -> V_30 == V_35 ) ? 0 : 1 ;
break;
case V_95 :
V_5 = F_10 ( V_3 , & V_94 -> V_98 ) ;
break;
case V_100 :
V_5 = F_17 ( V_3 , & V_94 -> V_98 ) ;
break;
case V_101 :
V_94 -> V_98 = V_102 * 1000 ;
break;
case V_103 :
V_5 = F_8 ( V_3 , & V_94 -> V_98 ) ;
break;
case V_104 :
V_5 = F_5 ( V_3 , & V_94 -> V_98 ) ;
break;
case V_105 :
V_5 = F_16 ( V_3 , & V_94 -> V_98 ) ;
break;
case V_106 :
V_94 -> V_98 = F_11 ( V_3 -> V_9 ) ;
V_5 = V_94 -> V_98 ;
break;
case V_107 :
V_94 -> V_98 = V_108 ;
break;
default:
return - V_8 ;
}
return V_5 ;
}
static T_3 F_25 ( struct V_109 * V_110 )
{
struct V_111 * V_112 ;
struct V_2 * V_3 ;
int V_5 ;
int V_49 ;
V_3 = F_26 ( sizeof( struct V_2 ) , V_113 ) ;
if ( ! V_3 )
return - V_114 ;
V_3 -> V_9 = F_27 ( V_110 -> V_115 . V_116 ) ;
V_3 -> V_74 = V_117 ;
V_3 -> V_30 = V_35 ;
V_3 -> V_6 = V_118 ;
V_3 -> V_58 = V_60 ;
V_3 -> V_77 . V_119 = F_21 ;
V_112 = V_3 -> V_9 -> V_115 -> V_120 ;
if ( V_112 != NULL && V_112 -> V_121 )
V_3 -> V_74 . V_121 = V_112 -> V_121 ;
else
V_3 -> V_74 . V_121 = 1 ;
for ( V_49 = 0 ; V_49 < F_28 ( V_122 ) ; V_49 ++ ) {
V_5 = F_29 ( V_3 -> V_9 ,
V_123 [ V_49 ] , V_122 [ V_49 ] ,
F_18 , V_3 ) ;
if ( V_5 != 0 ) {
F_30 ( V_3 -> V_9 -> V_115 ,
L_1 ,
V_122 [ V_49 ] , V_5 ) ;
goto V_124;
}
}
V_5 = F_31 ( & V_110 -> V_115 , & V_3 -> V_74 ) ;
if ( V_5 )
goto V_124;
F_32 ( V_110 , V_3 ) ;
return 0 ;
V_124:
while ( -- V_49 >= 0 )
F_33 ( V_3 -> V_9 , V_123 [ V_49 ] , V_3 ) ;
F_34 ( V_3 ) ;
return V_5 ;
}
static int F_35 ( struct V_109 * V_110 )
{
int V_49 ;
struct V_2 * V_3 = F_36 ( V_110 ) ;
for ( V_49 = 0 ; V_49 < F_28 ( V_122 ) ; V_49 ++ )
F_33 ( V_3 -> V_9 , V_123 [ V_49 ] , V_3 ) ;
F_37 ( & V_3 -> V_74 ) ;
F_34 ( V_3 ) ;
return 0 ;
}
