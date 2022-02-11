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
static void F_6 ( struct V_1 * V_2 , void * V_7 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_7 ;
int V_17 ;
T_1 V_18 ;
T_1 V_19 ;
T_1 V_20 [ V_21 ] ;
T_1 V_22 [ V_21 ] ;
if ( ! V_2 -> V_23 || V_2 -> V_24 == V_25 ||
V_2 -> V_24 == V_26 )
return;
V_18 = V_6 -> V_27 << V_28 ;
V_19 = V_6 -> V_29 [ 0 ] << V_30 ;
V_19 |= V_6 -> V_29 [ 1 ] << V_31 ;
V_19 |= V_6 -> V_29 [ 2 ] << V_32 ;
if ( V_6 -> V_27 == V_33 )
V_19 |= V_6 -> V_29 [ 3 ] << V_34 ;
for ( V_17 = 0 ; V_17 < V_21 ; V_17 ++ ) {
if ( V_17 < V_6 -> V_35 ) {
V_20 [ V_17 ] = ( V_6 -> V_36 [ V_17 ] . V_37 <<
V_38 )
| ( V_6 -> V_36 [ V_17 ] . V_39 <<
V_40 ) ;
V_22 [ V_17 ] = ( V_6 -> V_36 [ V_17 ] . V_41 <<
V_38 )
| ( V_6 -> V_36 [ V_17 ] . V_42 <<
V_40 ) ;
} else {
V_20 [ V_17 ] = 0 ;
V_22 [ V_17 ] = 0 ;
}
}
V_18 |= V_6 -> V_43 << V_44 ;
switch ( V_6 -> V_43 ) {
case V_45 :
V_18 |= ( V_46 - 8 ) <<
V_47 ;
break;
case V_48 :
V_18 |= ( V_46 - 7 ) <<
V_47 ;
break;
case V_49 :
V_18 |= ( V_46 - 6 ) <<
V_47 ;
break;
default:
V_18 |= ( V_46 - 5 ) <<
V_47 ;
break;
}
F_1 ( V_2 ) ;
F_2 ( V_4 , V_18 , V_9 , V_11 ) ;
F_2 ( V_4 , V_19 , V_9 , V_50 ) ;
F_2 ( V_4 , V_20 [ 0 ] , V_9 , V_51 ) ;
F_2 ( V_4 , V_22 [ 0 ] , V_9 , V_52 ) ;
F_2 ( V_4 , V_20 [ 1 ] , V_9 , V_53 ) ;
F_2 ( V_4 , V_22 [ 1 ] , V_9 , V_54 ) ;
F_2 ( V_4 , V_20 [ 2 ] , V_9 , V_55 ) ;
F_2 ( V_4 , V_22 [ 2 ] , V_9 , V_56 ) ;
F_2 ( V_4 , V_20 [ 3 ] , V_9 , V_57 ) ;
F_2 ( V_4 , V_22 [ 3 ] , V_9 , V_58 ) ;
V_2 -> V_23 = 0 ;
V_2 -> V_59 += V_2 -> V_60 ;
V_2 -> V_60 = 0 ;
V_2 -> V_61 = V_6 -> V_61 ;
}
static void F_7 ( struct V_1 * V_2 , int V_62 )
{
if ( V_62 ) {
F_3 ( V_2 -> V_4 , V_9 , V_63 ,
V_64 ) ;
F_8 ( V_2 -> V_4 , V_65 ) ;
} else {
F_5 ( V_2 -> V_4 , V_9 , V_63 ,
V_64 ) ;
F_9 ( V_2 -> V_4 , V_65 ) ;
}
}
static int F_10 ( struct V_1 * V_2 )
{
return F_4 ( V_2 -> V_4 , V_9 , V_63 )
& V_66 ;
}
static void F_11 ( void * V_67 )
{
struct V_1 * V_2 = V_67 ;
F_5 ( V_2 -> V_4 , V_9 , V_11 ,
V_12 ) ;
F_12 ( V_2 ) ;
if ( V_2 -> V_24 != V_25 )
F_13 ( V_2 -> V_4 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
T_2 V_68 = V_2 -> V_69 -> V_68 ;
struct V_70 * V_71 ;
struct V_72 V_73 ;
T_3 V_74 ;
int V_75 ;
if ( F_15 ( ! V_68 ) ) {
F_16 ( V_2 -> V_4 -> V_76 , L_1 ) ;
goto error;
}
F_2 ( V_2 -> V_4 , 0 , V_9 , V_10 ) ;
F_3 ( V_2 -> V_4 , V_9 , V_11 ,
V_12 ) ;
F_17 ( V_2 -> V_4 ) ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
V_73 . V_77 = V_2 -> V_4 -> V_78 + V_14 ;
V_73 . V_79 = V_80 ;
V_73 . V_81 = V_2 -> V_61 / 4 ;
V_75 = F_18 ( V_2 -> V_82 , & V_73 ) ;
if ( V_75 < 0 ) {
F_16 ( V_2 -> V_4 -> V_76 ,
L_2 ) ;
goto error;
}
V_71 = F_19 ( V_2 -> V_82 , V_68 ,
V_2 -> V_61 , V_83 ,
V_84 ) ;
if ( V_71 == NULL ) {
F_16 ( V_2 -> V_4 -> V_76 ,
L_3 ) ;
goto error;
}
V_71 -> V_85 = F_11 ;
V_71 -> V_86 = V_2 ;
V_74 = V_71 -> V_87 ( V_71 ) ;
if ( F_20 ( V_74 ) ) {
F_16 ( V_2 -> V_4 -> V_76 , L_4 ) ;
goto error;
}
F_21 ( V_2 -> V_82 ) ;
return V_88 ;
error:
F_1 ( V_2 ) ;
return V_89 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 * V_90 = V_2 -> V_69 -> V_91 ;
unsigned int V_8 ;
if ( ! V_90 ) {
F_16 ( V_4 -> V_76 , L_5 ) ;
F_1 ( V_2 ) ;
return V_89 ;
}
F_2 ( V_4 , 0 , V_9 , V_10 ) ;
F_3 ( V_4 , V_9 , V_11 , V_12 ) ;
for ( V_8 = V_2 -> V_61 / 16 ; V_8 > 0 ; V_8 -- ) {
* V_90 ++ = F_4 ( V_4 , V_9 , V_14 ) ;
* V_90 ++ = F_4 ( V_4 , V_9 , V_14 ) ;
* V_90 ++ = F_4 ( V_4 , V_9 , V_14 ) ;
* V_90 ++ = F_4 ( V_4 , V_9 , V_14 ) ;
}
F_5 ( V_2 -> V_4 , V_9 , V_11 ,
V_12 ) ;
return V_92 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_5 * V_93 = V_2 -> V_7 ;
int V_75 ;
if ( F_24 ( & V_2 -> V_94 ) || V_2 -> V_24 != V_95 ) {
F_1 ( V_2 ) ;
return V_89 ;
}
if ( -- ( V_2 -> V_15 ) )
return V_89 ;
if ( V_2 -> V_82 )
V_75 = F_14 ( V_2 ) ;
else
V_75 = F_22 ( V_2 ) ;
V_2 -> V_15 = V_93 -> V_16 ;
return V_75 ;
}
static T_1 F_25 ( struct V_5 * V_6 )
{
return F_26 ( V_6 -> V_43 ) * V_6 -> V_35 ;
}
static int F_27 ( struct V_1 * V_2 , void * V_96 )
{
struct V_5 * V_93 = V_96 ;
int V_17 ;
T_1 V_61 ;
if ( V_93 -> V_27 > V_97 )
return - V_98 ;
if ( ( V_93 -> V_35 < V_99 ) ||
( V_93 -> V_35 > V_21 ) )
return - V_98 ;
for ( V_17 = 0 ; V_17 < V_93 -> V_35 ; V_17 ++ ) {
if ( V_93 -> V_36 [ V_17 ] . V_37 & ~ V_100 )
return - V_98 ;
if ( V_93 -> V_36 [ V_17 ] . V_39 & ~ V_100 )
return - V_98 ;
if ( V_93 -> V_36 [ V_17 ] . V_41 & ~ V_100 )
return - V_98 ;
if ( V_93 -> V_36 [ V_17 ] . V_42 & ~ V_100 )
return - V_98 ;
if ( V_93 -> V_36 [ V_17 ] . V_37 > V_93 -> V_36 [ V_17 ] . V_39 )
return - V_98 ;
if ( V_93 -> V_36 [ V_17 ] . V_41 > V_93 -> V_36 [ V_17 ] . V_42 )
return - V_98 ;
}
switch ( V_93 -> V_35 ) {
case 1 :
if ( V_93 -> V_43 > V_45 )
return - V_98 ;
break;
case 2 :
if ( V_93 -> V_43 > V_48 )
return - V_98 ;
break;
default:
if ( V_93 -> V_43 > V_49 )
return - V_98 ;
break;
}
V_61 = F_25 ( V_93 ) ;
if ( V_61 > V_93 -> V_61 )
V_93 -> V_61 = V_61 ;
else if ( V_93 -> V_61 > V_101 )
V_93 -> V_61 = V_101 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_5 * V_93 )
{
struct V_5 * V_102 = V_2 -> V_7 ;
int V_17 ;
if ( V_102 -> V_27 != V_93 -> V_27 )
return 1 ;
if ( V_102 -> V_16 != V_93 -> V_16 )
return 1 ;
if ( V_102 -> V_43 != V_93 -> V_43 )
return 1 ;
for ( V_17 = 0 ; V_17 < V_103 ; V_17 ++ ) {
if ( V_17 == 3 && V_93 -> V_27 == V_97 )
break;
else if ( V_102 -> V_29 [ V_17 ] != V_93 -> V_29 [ V_17 ] )
return 1 ;
}
if ( V_102 -> V_35 != V_93 -> V_35 )
return 1 ;
for ( V_17 = 0 ; V_17 < V_93 -> V_35 ; V_17 ++ ) {
if ( V_102 -> V_36 [ V_17 ] . V_37 != V_93 -> V_36 [ V_17 ] . V_37 )
return 1 ;
if ( V_102 -> V_36 [ V_17 ] . V_39 != V_93 -> V_36 [ V_17 ] . V_39 )
return 1 ;
if ( V_102 -> V_36 [ V_17 ] . V_41 != V_93 -> V_36 [ V_17 ] . V_41 )
return 1 ;
if ( V_102 -> V_36 [ V_17 ] . V_42 != V_93 -> V_36 [ V_17 ] . V_42 )
return 1 ;
}
return 0 ;
}
static void F_29 ( struct V_1 * V_2 , void * V_96 )
{
struct V_5 * V_93 = V_96 ;
struct V_5 * V_102 = V_2 -> V_7 ;
if ( ! V_2 -> V_104 || F_28 ( V_2 , V_93 ) ) {
memcpy ( V_102 , V_93 , sizeof( * V_93 ) ) ;
if ( V_93 -> V_16 == 0 )
V_93 -> V_16 = 1 ;
V_2 -> V_60 ++ ;
V_2 -> V_23 = 1 ;
V_102 -> V_61 = F_25 ( V_102 ) ;
}
}
static long F_30 ( struct V_105 * V_106 , unsigned int V_107 , void * V_108 )
{
struct V_1 * V_109 = F_31 ( V_106 ) ;
switch ( V_107 ) {
case V_110 :
return F_32 ( V_109 , V_108 ) ;
case V_111 :
return F_33 ( V_109 , V_108 ) ;
case V_112 : {
int * V_113 = V_108 ;
return F_34 ( V_109 , ! ! * V_113 ) ;
}
}
return - V_114 ;
}
int F_35 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_115 ;
struct V_5 * V_116 ;
int V_75 = - 1 ;
V_116 = F_36 ( V_4 -> V_76 , sizeof( * V_116 ) , V_117 ) ;
if ( V_116 == NULL )
return - V_118 ;
V_2 -> V_4 = V_4 ;
if ( V_119 ) {
T_4 V_120 ;
F_37 ( V_120 ) ;
F_38 ( V_121 , V_120 ) ;
V_2 -> V_82 = F_39 ( & V_120 ) ;
if ( F_40 ( V_2 -> V_82 ) ) {
V_75 = F_41 ( V_2 -> V_82 ) ;
if ( V_75 == - V_122 )
return V_75 ;
V_2 -> V_82 = NULL ;
F_42 ( V_4 -> V_76 ,
L_6 ) ;
} else {
F_16 ( V_4 -> V_76 , L_7 ,
F_43 ( V_2 -> V_82 ) ) ;
}
}
V_2 -> V_123 = & V_124 ;
V_2 -> V_7 = V_116 ;
V_2 -> V_125 = V_126 ;
V_75 = F_44 ( V_2 , L_8 , & V_127 ) ;
if ( V_75 ) {
if ( V_2 -> V_82 )
F_45 ( V_2 -> V_82 ) ;
}
return V_75 ;
}
void F_46 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_115 ;
if ( V_2 -> V_82 )
F_45 ( V_2 -> V_82 ) ;
F_47 ( V_2 ) ;
}
