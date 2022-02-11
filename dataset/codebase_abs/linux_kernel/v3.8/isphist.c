static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_8 ;
F_2 ( V_4 , 0 , V_9 , V_10 ) ;
F_3 ( V_4 , V_9 , V_11 , V_12 ) ;
for ( V_8 = V_13 / 4 ; V_8 > 0 ; V_8 -- ) {
F_4 ( V_4 , V_9 , V_14 ) ;
F_4 ( V_4 , V_9 , V_14 ) ;
F_4 ( V_4 , V_9 , V_14 ) ;
F_4 ( V_4 , V_9 , V_14 ) ;
}
F_5 ( V_4 , V_9 , V_11 , V_12 ) ;
V_2 -> V_15 = V_6 -> V_16 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
V_2 -> V_17 . V_18 = V_19 ;
V_2 -> V_17 . V_20 = V_21 ;
V_2 -> V_17 . V_22 = 1 ;
V_2 -> V_17 . V_23 = V_24 ;
V_2 -> V_17 . V_25 = V_4 -> V_26 [ V_9 ]
+ V_14 ;
V_2 -> V_17 . V_27 = V_28 ;
V_2 -> V_17 . V_29 = V_30 ;
}
static void F_7 ( struct V_1 * V_2 , void * V_7 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_7 ;
int V_31 ;
T_1 V_32 ;
T_1 V_33 ;
T_1 V_34 [ V_35 ] ;
T_1 V_36 [ V_35 ] ;
if ( ! V_2 -> V_37 || V_2 -> V_38 == V_39 ||
V_2 -> V_38 == V_40 )
return;
V_32 = V_6 -> V_41 << V_42 ;
V_33 = V_6 -> V_43 [ 0 ] << V_44 ;
V_33 |= V_6 -> V_43 [ 1 ] << V_45 ;
V_33 |= V_6 -> V_43 [ 2 ] << V_46 ;
if ( V_6 -> V_41 == V_47 )
V_33 |= V_6 -> V_43 [ 3 ] << V_48 ;
for ( V_31 = 0 ; V_31 < V_35 ; V_31 ++ ) {
if ( V_31 < V_6 -> V_49 ) {
V_34 [ V_31 ] = V_6 -> V_50 [ V_31 ] . V_51 <<
V_52 ;
V_34 [ V_31 ] = V_6 -> V_50 [ V_31 ] . V_53 <<
V_54 ;
V_36 [ V_31 ] = V_6 -> V_50 [ V_31 ] . V_55 <<
V_52 ;
V_36 [ V_31 ] = V_6 -> V_50 [ V_31 ] . V_56 <<
V_54 ;
} else {
V_34 [ V_31 ] = 0 ;
V_36 [ V_31 ] = 0 ;
}
}
V_32 |= V_6 -> V_57 << V_58 ;
switch ( V_6 -> V_57 ) {
case V_59 :
V_32 |= ( V_60 - 8 ) <<
V_61 ;
break;
case V_62 :
V_32 |= ( V_60 - 7 ) <<
V_61 ;
break;
case V_63 :
V_32 |= ( V_60 - 6 ) <<
V_61 ;
break;
default:
V_32 |= ( V_60 - 5 ) <<
V_61 ;
break;
}
F_1 ( V_2 ) ;
F_2 ( V_4 , V_32 , V_9 , V_11 ) ;
F_2 ( V_4 , V_33 , V_9 , V_64 ) ;
F_2 ( V_4 , V_34 [ 0 ] , V_9 , V_65 ) ;
F_2 ( V_4 , V_36 [ 0 ] , V_9 , V_66 ) ;
F_2 ( V_4 , V_34 [ 1 ] , V_9 , V_67 ) ;
F_2 ( V_4 , V_36 [ 1 ] , V_9 , V_68 ) ;
F_2 ( V_4 , V_34 [ 2 ] , V_9 , V_69 ) ;
F_2 ( V_4 , V_36 [ 2 ] , V_9 , V_70 ) ;
F_2 ( V_4 , V_34 [ 3 ] , V_9 , V_71 ) ;
F_2 ( V_4 , V_36 [ 3 ] , V_9 , V_72 ) ;
V_2 -> V_37 = 0 ;
V_2 -> V_73 += V_2 -> V_74 ;
V_2 -> V_74 = 0 ;
V_2 -> V_75 = V_6 -> V_75 ;
}
static void F_8 ( struct V_1 * V_2 , int V_76 )
{
if ( V_76 ) {
F_3 ( V_2 -> V_4 , V_9 , V_77 ,
V_78 ) ;
F_9 ( V_2 -> V_4 , V_79 ) ;
} else {
F_5 ( V_2 -> V_4 , V_9 , V_77 ,
V_78 ) ;
F_10 ( V_2 -> V_4 , V_79 ) ;
}
}
static int F_11 ( struct V_1 * V_2 )
{
return F_4 ( V_2 -> V_4 , V_9 , V_77 )
& V_80 ;
}
static void F_12 ( int V_81 , T_2 V_82 , void * V_83 )
{
struct V_1 * V_2 = V_83 ;
if ( V_82 & ~ V_84 ) {
F_13 ( V_2 -> V_4 -> V_85 , L_1 ,
V_82 ) ;
F_14 ( V_81 ) ;
F_1 ( V_2 ) ;
F_15 ( & V_2 -> V_86 , 1 ) ;
}
F_5 ( V_2 -> V_4 , V_9 , V_11 ,
V_12 ) ;
F_16 ( V_2 ) ;
if ( V_2 -> V_38 != V_39 )
F_17 ( V_2 -> V_4 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
T_3 V_87 = V_2 -> V_88 -> V_87 ;
if ( F_19 ( ! V_87 ) ) {
F_13 ( V_2 -> V_4 -> V_85 , L_2 ) ;
F_1 ( V_2 ) ;
return V_89 ;
}
F_2 ( V_2 -> V_4 , 0 , V_9 , V_10 ) ;
F_3 ( V_2 -> V_4 , V_9 , V_11 ,
V_12 ) ;
F_20 ( V_2 -> V_4 ) ;
V_2 -> V_17 . V_90 = V_87 ;
V_2 -> V_17 . V_91 = V_2 -> V_75 / sizeof( T_1 ) ;
F_21 ( V_2 -> V_92 , & V_2 -> V_17 ) ;
F_22 ( V_2 -> V_92 ) ;
return V_93 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 * V_94 = V_2 -> V_88 -> V_95 ;
unsigned int V_8 ;
if ( ! V_94 ) {
F_13 ( V_4 -> V_85 , L_3 ) ;
F_1 ( V_2 ) ;
return V_89 ;
}
F_2 ( V_4 , 0 , V_9 , V_10 ) ;
F_3 ( V_4 , V_9 , V_11 , V_12 ) ;
for ( V_8 = V_2 -> V_75 / 16 ; V_8 > 0 ; V_8 -- ) {
* V_94 ++ = F_4 ( V_4 , V_9 , V_14 ) ;
* V_94 ++ = F_4 ( V_4 , V_9 , V_14 ) ;
* V_94 ++ = F_4 ( V_4 , V_9 , V_14 ) ;
* V_94 ++ = F_4 ( V_4 , V_9 , V_14 ) ;
}
F_5 ( V_2 -> V_4 , V_9 , V_11 ,
V_12 ) ;
return V_96 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_5 * V_97 = V_2 -> V_7 ;
int V_98 ;
if ( F_25 ( & V_2 -> V_86 ) || V_2 -> V_38 != V_99 ) {
F_1 ( V_2 ) ;
return V_89 ;
}
if ( -- ( V_2 -> V_15 ) )
return V_89 ;
if ( F_26 ( V_2 ) )
V_98 = F_18 ( V_2 ) ;
else
V_98 = F_23 ( V_2 ) ;
V_2 -> V_15 = V_97 -> V_16 ;
return V_98 ;
}
static T_1 F_27 ( struct V_5 * V_6 )
{
return F_28 ( V_6 -> V_57 ) * V_6 -> V_49 ;
}
static int F_29 ( struct V_1 * V_2 , void * V_100 )
{
struct V_5 * V_97 = V_100 ;
int V_31 ;
T_1 V_75 ;
if ( V_97 -> V_41 > V_101 )
return - V_102 ;
if ( ( V_97 -> V_49 < V_103 ) ||
( V_97 -> V_49 > V_35 ) )
return - V_102 ;
for ( V_31 = 0 ; V_31 < V_97 -> V_49 ; V_31 ++ ) {
if ( V_97 -> V_50 [ V_31 ] . V_51 & ~ V_104 )
return - V_102 ;
if ( V_97 -> V_50 [ V_31 ] . V_53 & ~ V_104 )
return - V_102 ;
if ( V_97 -> V_50 [ V_31 ] . V_55 & ~ V_104 )
return - V_102 ;
if ( V_97 -> V_50 [ V_31 ] . V_56 & ~ V_104 )
return - V_102 ;
if ( V_97 -> V_50 [ V_31 ] . V_51 > V_97 -> V_50 [ V_31 ] . V_53 )
return - V_102 ;
if ( V_97 -> V_50 [ V_31 ] . V_55 > V_97 -> V_50 [ V_31 ] . V_56 )
return - V_102 ;
}
switch ( V_97 -> V_49 ) {
case 1 :
if ( V_97 -> V_57 > V_59 )
return - V_102 ;
break;
case 2 :
if ( V_97 -> V_57 > V_62 )
return - V_102 ;
break;
default:
if ( V_97 -> V_57 > V_63 )
return - V_102 ;
break;
}
V_75 = F_27 ( V_97 ) ;
if ( V_75 > V_97 -> V_75 )
V_97 -> V_75 = V_75 ;
else if ( V_97 -> V_75 > V_105 )
V_97 -> V_75 = V_105 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_5 * V_97 )
{
struct V_5 * V_106 = V_2 -> V_7 ;
int V_31 ;
if ( V_106 -> V_41 != V_97 -> V_41 )
return 1 ;
if ( V_106 -> V_16 != V_97 -> V_16 )
return 1 ;
if ( V_106 -> V_57 != V_97 -> V_57 )
return 1 ;
for ( V_31 = 0 ; V_31 < V_107 ; V_31 ++ ) {
if ( V_31 == 3 && V_97 -> V_41 == V_101 )
break;
else if ( V_106 -> V_43 [ V_31 ] != V_97 -> V_43 [ V_31 ] )
return 1 ;
}
if ( V_106 -> V_49 != V_97 -> V_49 )
return 1 ;
for ( V_31 = 0 ; V_31 < V_97 -> V_49 ; V_31 ++ ) {
if ( V_106 -> V_50 [ V_31 ] . V_51 != V_97 -> V_50 [ V_31 ] . V_51 )
return 1 ;
if ( V_106 -> V_50 [ V_31 ] . V_53 != V_97 -> V_50 [ V_31 ] . V_53 )
return 1 ;
if ( V_106 -> V_50 [ V_31 ] . V_55 != V_97 -> V_50 [ V_31 ] . V_55 )
return 1 ;
if ( V_106 -> V_50 [ V_31 ] . V_56 != V_97 -> V_50 [ V_31 ] . V_56 )
return 1 ;
}
return 0 ;
}
static void F_31 ( struct V_1 * V_2 , void * V_100 )
{
struct V_5 * V_97 = V_100 ;
struct V_5 * V_106 = V_2 -> V_7 ;
if ( ! V_2 -> V_108 || F_30 ( V_2 , V_97 ) ) {
memcpy ( V_106 , V_97 , sizeof( * V_97 ) ) ;
if ( V_97 -> V_16 == 0 )
V_97 -> V_16 = 1 ;
V_2 -> V_74 ++ ;
V_2 -> V_37 = 1 ;
V_106 -> V_75 = F_27 ( V_106 ) ;
}
}
static long F_32 ( struct V_109 * V_110 , unsigned int V_111 , void * V_112 )
{
struct V_1 * V_113 = F_33 ( V_110 ) ;
switch ( V_111 ) {
case V_114 :
return F_34 ( V_113 , V_112 ) ;
case V_115 :
return F_35 ( V_113 , V_112 ) ;
case V_116 : {
int * V_117 = V_112 ;
return F_36 ( V_113 , ! ! * V_117 ) ;
}
}
return - V_118 ;
}
int F_37 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_119 ;
struct V_5 * V_120 ;
int V_98 = - 1 ;
V_120 = F_38 ( sizeof( * V_120 ) , V_121 ) ;
if ( V_120 == NULL )
return - V_122 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_4 = V_4 ;
if ( V_123 )
V_98 = F_39 ( V_124 , L_4 ,
F_12 , V_2 , & V_2 -> V_92 ) ;
if ( V_98 ) {
if ( V_123 )
F_40 ( V_4 -> V_85 , L_5
L_6 ) ;
V_2 -> V_92 = - 1 ;
} else {
F_13 ( V_4 -> V_85 , L_7 , V_2 -> V_92 ) ;
F_6 ( V_2 ) ;
F_41 ( V_2 -> V_92 , V_84 ) ;
}
V_2 -> V_125 = & V_126 ;
V_2 -> V_7 = V_120 ;
V_2 -> V_127 = V_128 ;
V_98 = F_42 ( V_2 , L_8 , & V_129 ) ;
if ( V_98 ) {
F_43 ( V_120 ) ;
if ( F_26 ( V_2 ) )
F_44 ( V_2 -> V_92 ) ;
}
return V_98 ;
}
void F_45 ( struct V_3 * V_4 )
{
if ( F_26 ( & V_4 -> V_119 ) )
F_44 ( V_4 -> V_119 . V_92 ) ;
F_43 ( V_4 -> V_119 . V_7 ) ;
F_46 ( & V_4 -> V_119 ) ;
}
