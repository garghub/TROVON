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
V_2 -> V_17 . V_18 = V_19 ;
V_2 -> V_17 . V_20 = V_21 ;
V_2 -> V_17 . V_22 = 1 ;
V_2 -> V_17 . V_23 = V_24 ;
V_2 -> V_17 . V_25 = V_26 + V_14 ;
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
F_3 ( V_2 -> V_4 , V_79 , V_80 ,
V_81 ) ;
} else {
F_5 ( V_2 -> V_4 , V_9 , V_77 ,
V_78 ) ;
F_5 ( V_2 -> V_4 , V_79 , V_80 ,
V_81 ) ;
}
}
static int F_9 ( struct V_1 * V_2 )
{
return F_4 ( V_2 -> V_4 , V_9 , V_77 )
& V_82 ;
}
static void F_10 ( int V_83 , T_2 V_84 , void * V_85 )
{
struct V_1 * V_2 = V_85 ;
if ( V_84 & ~ V_86 ) {
F_11 ( V_2 -> V_4 -> V_87 , L_1 ,
V_84 ) ;
F_12 ( V_83 ) ;
F_1 ( V_2 ) ;
F_13 ( & V_2 -> V_88 , 1 ) ;
}
F_5 ( V_2 -> V_4 , V_9 , V_11 ,
V_12 ) ;
F_14 ( V_2 ) ;
if ( V_2 -> V_38 != V_39 )
F_15 ( V_2 -> V_4 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_3 V_89 = V_2 -> V_90 -> V_89 ;
if ( F_17 ( ! V_89 ) ) {
F_11 ( V_2 -> V_4 -> V_87 , L_2 ) ;
F_1 ( V_2 ) ;
return V_91 ;
}
F_2 ( V_2 -> V_4 , 0 , V_9 , V_10 ) ;
F_3 ( V_2 -> V_4 , V_9 , V_11 ,
V_12 ) ;
F_18 ( V_2 -> V_4 ) ;
V_2 -> V_17 . V_92 = V_89 ;
V_2 -> V_17 . V_93 = V_2 -> V_75 / sizeof( T_1 ) ;
F_19 ( V_2 -> V_94 , & V_2 -> V_17 ) ;
F_20 ( V_2 -> V_94 ) ;
return V_95 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 * V_96 = V_2 -> V_90 -> V_97 ;
unsigned int V_8 ;
if ( ! V_96 ) {
F_11 ( V_4 -> V_87 , L_3 ) ;
F_1 ( V_2 ) ;
return V_91 ;
}
F_2 ( V_4 , 0 , V_9 , V_10 ) ;
F_3 ( V_4 , V_9 , V_11 , V_12 ) ;
for ( V_8 = V_2 -> V_75 / 16 ; V_8 > 0 ; V_8 -- ) {
* V_96 ++ = F_4 ( V_4 , V_9 , V_14 ) ;
* V_96 ++ = F_4 ( V_4 , V_9 , V_14 ) ;
* V_96 ++ = F_4 ( V_4 , V_9 , V_14 ) ;
* V_96 ++ = F_4 ( V_4 , V_9 , V_14 ) ;
}
F_5 ( V_2 -> V_4 , V_9 , V_11 ,
V_12 ) ;
return V_98 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_5 * V_99 = V_2 -> V_7 ;
int V_100 ;
if ( F_23 ( & V_2 -> V_88 ) || V_2 -> V_38 != V_101 ) {
F_1 ( V_2 ) ;
return V_91 ;
}
if ( -- ( V_2 -> V_15 ) )
return V_91 ;
if ( F_24 ( V_2 ) )
V_100 = F_16 ( V_2 ) ;
else
V_100 = F_21 ( V_2 ) ;
V_2 -> V_15 = V_99 -> V_16 ;
return V_100 ;
}
static T_1 F_25 ( struct V_5 * V_6 )
{
return F_26 ( V_6 -> V_57 ) * V_6 -> V_49 ;
}
static int F_27 ( struct V_1 * V_2 , void * V_102 )
{
struct V_5 * V_99 = V_102 ;
int V_31 ;
T_1 V_75 ;
if ( V_99 -> V_41 > V_103 )
return - V_104 ;
if ( ( V_99 -> V_49 < V_105 ) ||
( V_99 -> V_49 > V_35 ) )
return - V_104 ;
for ( V_31 = 0 ; V_31 < V_99 -> V_49 ; V_31 ++ ) {
if ( V_99 -> V_50 [ V_31 ] . V_51 & ~ V_106 )
return - V_104 ;
if ( V_99 -> V_50 [ V_31 ] . V_53 & ~ V_106 )
return - V_104 ;
if ( V_99 -> V_50 [ V_31 ] . V_55 & ~ V_106 )
return - V_104 ;
if ( V_99 -> V_50 [ V_31 ] . V_56 & ~ V_106 )
return - V_104 ;
if ( V_99 -> V_50 [ V_31 ] . V_51 > V_99 -> V_50 [ V_31 ] . V_53 )
return - V_104 ;
if ( V_99 -> V_50 [ V_31 ] . V_55 > V_99 -> V_50 [ V_31 ] . V_56 )
return - V_104 ;
}
switch ( V_99 -> V_49 ) {
case 1 :
if ( V_99 -> V_57 > V_59 )
return - V_104 ;
break;
case 2 :
if ( V_99 -> V_57 > V_62 )
return - V_104 ;
break;
default:
if ( V_99 -> V_57 > V_63 )
return - V_104 ;
break;
}
V_75 = F_25 ( V_99 ) ;
if ( V_75 > V_99 -> V_75 )
V_99 -> V_75 = V_75 ;
else if ( V_99 -> V_75 > V_107 )
V_99 -> V_75 = V_107 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_5 * V_99 )
{
struct V_5 * V_108 = V_2 -> V_7 ;
int V_31 ;
if ( V_108 -> V_41 != V_99 -> V_41 )
return 1 ;
if ( V_108 -> V_16 != V_99 -> V_16 )
return 1 ;
if ( V_108 -> V_57 != V_99 -> V_57 )
return 1 ;
for ( V_31 = 0 ; V_31 < V_109 ; V_31 ++ ) {
if ( V_31 == 3 && V_99 -> V_41 == V_103 )
break;
else if ( V_108 -> V_43 [ V_31 ] != V_99 -> V_43 [ V_31 ] )
return 1 ;
}
if ( V_108 -> V_49 != V_99 -> V_49 )
return 1 ;
for ( V_31 = 0 ; V_31 < V_99 -> V_49 ; V_31 ++ ) {
if ( V_108 -> V_50 [ V_31 ] . V_51 != V_99 -> V_50 [ V_31 ] . V_51 )
return 1 ;
if ( V_108 -> V_50 [ V_31 ] . V_53 != V_99 -> V_50 [ V_31 ] . V_53 )
return 1 ;
if ( V_108 -> V_50 [ V_31 ] . V_55 != V_99 -> V_50 [ V_31 ] . V_55 )
return 1 ;
if ( V_108 -> V_50 [ V_31 ] . V_56 != V_99 -> V_50 [ V_31 ] . V_56 )
return 1 ;
}
return 0 ;
}
static void F_29 ( struct V_1 * V_2 , void * V_102 )
{
struct V_5 * V_99 = V_102 ;
struct V_5 * V_108 = V_2 -> V_7 ;
if ( ! V_2 -> V_110 || F_28 ( V_2 , V_99 ) ) {
memcpy ( V_108 , V_99 , sizeof( * V_99 ) ) ;
if ( V_99 -> V_16 == 0 )
V_99 -> V_16 = 1 ;
V_2 -> V_74 ++ ;
V_2 -> V_37 = 1 ;
V_108 -> V_75 = F_25 ( V_108 ) ;
}
}
static long F_30 ( struct V_111 * V_112 , unsigned int V_113 , void * V_114 )
{
struct V_1 * V_115 = F_31 ( V_112 ) ;
switch ( V_113 ) {
case V_116 :
return F_32 ( V_115 , V_114 ) ;
case V_117 :
return F_33 ( V_115 , V_114 ) ;
case V_118 : {
int * V_119 = V_114 ;
return F_34 ( V_115 , ! ! * V_119 ) ;
}
}
return - V_120 ;
}
int F_35 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_121 ;
struct V_5 * V_122 ;
int V_100 = - 1 ;
V_122 = F_36 ( sizeof( * V_122 ) , V_123 ) ;
if ( V_122 == NULL )
return - V_124 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
if ( V_125 )
V_100 = F_37 ( V_126 , L_4 ,
F_10 , V_2 , & V_2 -> V_94 ) ;
if ( V_100 ) {
if ( V_125 )
F_38 ( V_4 -> V_87 , L_5
L_6 ) ;
V_2 -> V_94 = - 1 ;
} else {
F_11 ( V_4 -> V_87 , L_7 , V_2 -> V_94 ) ;
F_6 ( V_2 ) ;
F_39 ( V_2 -> V_94 , V_86 ) ;
}
V_2 -> V_127 = & V_128 ;
V_2 -> V_7 = V_122 ;
V_2 -> V_129 = V_130 ;
V_2 -> V_4 = V_4 ;
V_100 = F_40 ( V_2 , L_8 , & V_131 ) ;
if ( V_100 ) {
F_41 ( V_122 ) ;
if ( F_24 ( V_2 ) )
F_42 ( V_2 -> V_94 ) ;
}
return V_100 ;
}
void F_43 ( struct V_3 * V_4 )
{
if ( F_24 ( & V_4 -> V_121 ) )
F_42 ( V_4 -> V_121 . V_94 ) ;
F_41 ( V_4 -> V_121 . V_7 ) ;
F_44 ( & V_4 -> V_121 ) ;
}
