static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_7 [ F_2 ( V_8 ) ] ;
int V_9 ;
V_9 = F_3 ( V_6 , V_7 ) ;
if ( V_9 )
return V_9 ;
F_4 ( V_8 , V_7 , V_10 , V_4 ) ;
if ( V_4 != V_11 )
F_4 ( V_8 , V_7 , V_12 , 1 ) ;
return F_5 ( V_6 , V_7 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
int V_9 ;
if ( ! F_7 ( V_2 -> V_6 , V_14 ) )
return 0 ;
if ( V_14 -> V_4 == V_11 )
return 0 ;
V_9 = F_1 ( V_2 , V_11 ) ;
if ( V_9 )
return V_9 ;
V_14 -> V_4 = V_11 ;
return 0 ;
}
static int F_8 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_2 V_19 [ V_20 ] ;
bool V_21 = false ;
bool V_22 = false ;
int V_9 = 0 ;
int V_23 ;
if ( ! F_7 ( V_2 -> V_6 , V_18 ) )
return - V_24 ;
V_18 -> V_25 = F_10 ( V_2 -> V_6 ) + 1 ;
for ( V_23 = 0 ; V_23 < V_18 -> V_25 ; V_23 ++ ) {
V_9 = F_11 ( V_6 , V_23 , & V_18 -> V_26 [ V_23 ] ) ;
if ( V_9 )
return V_9 ;
V_9 = F_12 ( V_6 , V_23 , & V_19 [ V_23 ] ) ;
if ( V_9 )
return V_9 ;
V_9 = F_13 ( V_6 , V_23 , & V_18 -> V_27 [ V_23 ] ) ;
if ( V_9 )
return V_9 ;
if ( V_18 -> V_27 [ V_23 ] < V_28 &&
V_19 [ V_23 ] == ( V_29 + 1 ) )
V_22 = true ;
if ( V_19 [ V_23 ] == ( V_30 - 1 ) )
V_21 = true ;
}
if ( V_22 ) {
for ( V_23 = 0 ; V_23 < V_18 -> V_25 ; V_23 ++ )
if ( V_19 [ V_23 ] == V_29 )
V_18 -> V_27 [ V_23 ] = 0 ;
}
for ( V_23 = 0 ; V_23 < V_18 -> V_25 ; V_23 ++ ) {
if ( V_18 -> V_27 [ V_23 ] < V_28 )
V_2 -> V_14 . V_31 [ V_23 ] = V_32 ;
else if ( V_19 [ V_23 ] == V_30 &&
! V_21 )
V_2 -> V_14 . V_31 [ V_23 ] = V_33 ;
}
memcpy ( V_18 -> V_31 , V_2 -> V_14 . V_31 , sizeof( V_18 -> V_31 ) ) ;
return V_9 ;
}
static void F_14 ( struct V_17 * V_18 , T_2 * V_19 , int V_34 )
{
bool V_35 = false ;
bool V_36 = false ;
int V_37 ;
int V_23 ;
for ( V_23 = 0 ; V_23 <= V_34 ; V_23 ++ ) {
if ( V_18 -> V_31 [ V_23 ] == V_32 ) {
V_35 = true ;
if ( ! V_18 -> V_27 [ V_23 ] )
V_36 = true ;
}
}
V_37 = V_29 ;
if ( V_35 )
V_37 ++ ;
if ( V_36 )
V_37 ++ ;
for ( V_23 = 0 ; V_23 <= V_34 ; V_23 ++ ) {
switch ( V_18 -> V_31 [ V_23 ] ) {
case V_33 :
V_19 [ V_23 ] = V_30 ;
break;
case V_38 :
V_19 [ V_23 ] = V_37 ++ ;
break;
case V_32 :
V_19 [ V_23 ] = V_29 ;
if ( V_18 -> V_27 [ V_23 ] && V_36 )
V_19 [ V_23 ] = V_29 + 1 ;
break;
}
}
}
static void F_15 ( struct V_17 * V_18 , T_2 * V_27 ,
T_2 * V_19 , int V_34 )
{
int V_39 = 0 ;
int V_40 = - 1 ;
int V_41 = 0 ;
int V_23 ;
for ( V_23 = 0 ; V_23 <= V_34 ; V_23 ++ ) {
if ( V_18 -> V_31 [ V_23 ] == V_32 &&
! V_18 -> V_27 [ V_23 ] ) {
V_41 ++ ;
V_40 = V_23 ;
}
}
if ( V_41 )
V_39 = V_28 / V_41 ;
for ( V_23 = 0 ; V_23 <= V_34 ; V_23 ++ ) {
switch ( V_18 -> V_31 [ V_23 ] ) {
case V_33 :
V_27 [ V_23 ] = V_28 ;
break;
case V_38 :
V_27 [ V_23 ] = V_28 ;
break;
case V_32 :
V_27 [ V_23 ] = V_18 -> V_27 [ V_23 ] ?
V_18 -> V_27 [ V_23 ] :
V_39 ;
break;
}
}
if ( V_40 != - 1 )
V_27 [ V_40 ] +=
V_28 % V_41 ;
}
int F_16 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
T_2 V_27 [ V_20 ] ;
T_2 V_19 [ V_20 ] ;
int V_34 = F_10 ( V_6 ) ;
int V_9 ;
F_14 ( V_18 , V_19 , V_34 ) ;
F_15 ( V_18 , V_27 , V_19 , V_34 ) ;
V_9 = F_17 ( V_6 , V_18 -> V_26 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_18 ( V_6 , V_19 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_19 ( V_6 , V_27 ) ;
if ( V_9 )
return V_9 ;
memcpy ( V_2 -> V_14 . V_31 , V_18 -> V_31 , sizeof( V_18 -> V_31 ) ) ;
return V_9 ;
}
static int F_20 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
int V_42 = 0 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_20 ; V_23 ++ ) {
if ( V_18 -> V_26 [ V_23 ] >= V_43 ) {
F_21 ( V_16 ,
L_1 ,
V_43 ) ;
return - V_44 ;
}
}
for ( V_23 = 0 ; V_23 < V_20 ; V_23 ++ )
if ( V_18 -> V_31 [ V_23 ] == V_32 )
V_42 += V_18 -> V_27 [ V_23 ] ;
if ( V_42 != 0 && V_42 != 100 ) {
F_21 ( V_16 ,
L_2 ) ;
return - V_44 ;
}
return 0 ;
}
static int F_22 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
int V_9 ;
if ( ! F_7 ( V_2 -> V_6 , V_18 ) )
return - V_24 ;
V_9 = F_20 ( V_16 , V_18 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_16 ( V_2 , V_18 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_23 ( struct V_15 * V_45 ,
struct V_46 * V_47 )
{
struct V_1 * V_2 = F_9 ( V_45 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_48 * V_49 = & V_2 -> V_50 . V_51 ;
int V_23 ;
V_47 -> V_52 = F_10 ( V_6 ) + 1 ;
for ( V_23 = 0 ; V_23 < V_20 ; V_23 ++ ) {
V_47 -> V_53 [ V_23 ] = F_24 ( V_49 , V_23 , V_54 ) ;
V_47 -> V_55 [ V_23 ] = F_24 ( V_49 , V_23 , V_56 ) ;
}
return F_25 ( V_6 , & V_47 -> V_57 , NULL ) ;
}
static int F_26 ( struct V_15 * V_45 ,
struct V_46 * V_47 )
{
struct V_1 * V_2 = F_9 ( V_45 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_2 V_58 ;
int V_59 ;
F_25 ( V_6 , & V_58 , NULL ) ;
if ( V_47 -> V_57 == V_58 )
return 0 ;
V_59 = F_27 ( V_6 , V_47 -> V_57 , V_47 -> V_57 ) ;
F_28 ( V_6 ) ;
return V_59 ;
}
static T_2 F_29 ( struct V_15 * V_45 )
{
struct V_1 * V_2 = F_9 ( V_45 ) ;
return V_2 -> V_14 . V_60 ;
}
static T_2 F_30 ( struct V_15 * V_45 , T_2 V_4 )
{
struct V_1 * V_2 = F_9 ( V_45 ) ;
struct V_13 * V_14 = & V_2 -> V_14 ;
if ( V_4 & V_61 )
return 1 ;
if ( ( ! V_4 ) && F_7 ( V_2 -> V_6 , V_14 ) ) {
if ( V_14 -> V_4 == V_62 )
return 0 ;
if ( ! F_1 ( V_2 , V_62 ) ) {
V_14 -> V_4 = V_62 ;
V_14 -> V_60 &= ~ V_63 ;
return 0 ;
}
return 1 ;
}
if ( ! ( V_4 & V_63 ) )
return 1 ;
if ( F_6 ( F_9 ( V_45 ) ) )
return 1 ;
V_14 -> V_60 = V_4 ;
return 0 ;
}
static int F_31 ( struct V_15 * V_16 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_2 V_66 [ V_20 ] ;
T_2 V_67 [ V_20 ] ;
int V_9 ;
int V_23 ;
V_9 = F_32 ( V_6 , V_66 , V_67 ) ;
if ( V_9 )
return V_9 ;
memset ( V_65 -> V_68 , 0 , sizeof( V_65 -> V_68 ) ) ;
for ( V_23 = 0 ; V_23 <= F_10 ( V_6 ) ; V_23 ++ ) {
switch ( V_67 [ V_23 ] ) {
case V_69 :
V_65 -> V_68 [ V_23 ] = V_66 [ V_23 ] * V_70 ;
break;
case V_71 :
V_65 -> V_68 [ V_23 ] = V_66 [ V_23 ] * V_72 ;
break;
case V_73 :
break;
default:
F_33 ( true , L_3 ) ;
break;
}
}
return 0 ;
}
static int F_34 ( struct V_15 * V_16 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_2 V_66 [ V_20 ] ;
T_2 V_67 [ V_20 ] ;
T_3 V_74 = F_35 ( 255 * V_70 , V_72 ) ;
int V_23 ;
memset ( V_66 , 0 , sizeof( V_66 ) ) ;
memset ( V_67 , 0 , sizeof( V_67 ) ) ;
for ( V_23 = 0 ; V_23 <= F_10 ( V_6 ) ; V_23 ++ ) {
if ( ! V_65 -> V_68 [ V_23 ] ) {
V_67 [ V_23 ] = V_73 ;
continue;
}
if ( V_65 -> V_68 [ V_23 ] < V_74 ) {
V_66 [ V_23 ] = F_36 ( V_65 -> V_68 [ V_23 ] ,
V_70 ) ;
V_66 [ V_23 ] = V_66 [ V_23 ] ? V_66 [ V_23 ] : 1 ;
V_67 [ V_23 ] = V_69 ;
} else {
V_66 [ V_23 ] = F_36 ( V_65 -> V_68 [ V_23 ] ,
V_72 ) ;
V_67 [ V_23 ] = V_71 ;
}
}
return F_37 ( V_6 , V_66 , V_67 ) ;
}
static T_2 F_38 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_75 * V_76 = & V_2 -> V_14 . V_76 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_17 V_18 ;
struct V_46 V_47 ;
int V_9 = - V_24 ;
int V_23 ;
if ( ! F_7 ( V_6 , V_18 ) )
goto V_77;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
V_18 . V_25 = V_20 ;
for ( V_23 = 0 ; V_23 < V_78 ; V_23 ++ ) {
V_18 . V_27 [ V_23 ] = V_76 -> V_79 [ V_23 ] ;
V_18 . V_80 [ V_23 ] = V_76 -> V_79 [ V_23 ] ;
V_18 . V_31 [ V_23 ] = V_32 ;
V_18 . V_26 [ V_23 ] = V_76 -> V_81 [ V_23 ] ;
}
V_9 = F_20 ( V_16 , & V_18 ) ;
if ( V_9 ) {
F_21 ( V_16 ,
L_4 , V_82 , V_9 ) ;
goto V_77;
}
V_9 = F_16 ( V_2 , & V_18 ) ;
if ( V_9 ) {
F_21 ( V_16 ,
L_5 , V_82 , V_9 ) ;
goto V_77;
}
V_47 . V_52 = F_10 ( V_6 ) + 1 ;
if ( ! V_76 -> V_83 )
V_47 . V_57 = 0 ;
else
for ( V_23 = 0 ; V_23 < V_84 ; V_23 ++ )
V_47 . V_57 |= V_76 -> V_85 [ V_23 ] << V_23 ;
V_9 = F_26 ( V_16 , & V_47 ) ;
if ( V_9 ) {
F_21 ( V_16 ,
L_6 , V_82 , V_9 ) ;
goto V_77;
}
V_77:
return V_9 ? V_86 : V_87 ;
}
static T_2 F_39 ( struct V_15 * V_16 )
{
return V_88 ;
}
static void F_40 ( struct V_15 * V_16 ,
T_2 * V_89 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
if ( ! V_89 )
return;
memset ( V_89 , 0xff , V_90 ) ;
F_41 ( V_2 -> V_6 , 0 , V_89 ) ;
}
static void F_42 ( struct V_15 * V_16 ,
int V_91 , T_2 V_92 ,
T_2 V_93 , T_2 V_94 , T_2 V_95 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_75 * V_76 = & V_2 -> V_14 . V_76 ;
if ( V_91 >= V_84 ) {
F_21 ( V_16 ,
L_7 , V_82 ) ;
return;
}
if ( V_93 >= V_78 ) {
F_21 ( V_16 ,
L_8 , V_82 ) ;
return;
}
V_76 -> V_81 [ V_91 ] = V_93 ;
}
static void F_43 ( struct V_15 * V_16 ,
int V_93 , T_2 V_94 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_75 * V_76 = & V_2 -> V_14 . V_76 ;
if ( V_93 >= V_78 ) {
F_21 ( V_16 ,
L_8 , V_82 ) ;
return;
}
V_76 -> V_79 [ V_93 ] = V_94 ;
}
static void F_44 ( struct V_15 * V_16 ,
int V_91 , T_2 * V_92 ,
T_2 * V_93 , T_2 * V_94 , T_2 * V_95 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
if ( ! F_7 ( V_2 -> V_6 , V_18 ) ) {
F_21 ( V_16 , L_9 , V_82 ) ;
return;
}
if ( V_91 >= V_84 ) {
F_21 ( V_16 ,
L_7 , V_82 ) ;
return;
}
* V_92 = 0 ;
* V_94 = 0 ;
* V_95 = 0 ;
if ( F_11 ( V_6 , V_91 , V_93 ) )
* V_93 = 0 ;
}
static void F_45 ( struct V_15 * V_16 ,
int V_93 , T_2 * V_94 )
{
struct V_17 V_18 ;
if ( V_93 >= V_78 ) {
F_21 ( V_16 ,
L_8 , V_82 ) ;
return;
}
F_8 ( V_16 , & V_18 ) ;
* V_94 = V_18 . V_27 [ V_93 ] ;
}
static void F_46 ( struct V_15 * V_16 ,
int V_91 , T_2 V_96 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_75 * V_76 = & V_2 -> V_14 . V_76 ;
if ( V_91 >= V_84 ) {
F_21 ( V_16 ,
L_7 , V_82 ) ;
return;
}
if ( V_96 > 1 )
return;
V_76 -> V_85 [ V_91 ] = V_96 ;
}
static int
F_47 ( struct V_15 * V_16 ,
int V_91 , T_2 * V_96 )
{
struct V_46 V_47 ;
int V_9 ;
V_9 = F_23 ( V_16 , & V_47 ) ;
if ( V_9 )
* V_96 = 0 ;
else
* V_96 = ( V_47 . V_57 >> V_91 ) & 0x01 ;
return V_9 ;
}
static void F_48 ( struct V_15 * V_16 ,
int V_91 , T_2 * V_96 )
{
if ( V_91 >= V_84 ) {
F_21 ( V_16 ,
L_7 , V_82 ) ;
return;
}
if ( ! V_96 )
return;
F_47 ( V_16 , V_91 , V_96 ) ;
}
static T_2 F_49 ( struct V_15 * V_16 ,
int V_97 , T_2 * V_60 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_2 V_98 = 0 ;
switch ( V_97 ) {
case V_99 :
* V_60 = true ;
break;
case V_100 :
* V_60 = true ;
break;
case V_101 :
* V_60 = false ;
break;
case V_102 :
* V_60 = 1 << F_10 ( V_6 ) ;
break;
case V_103 :
* V_60 = 1 << F_10 ( V_6 ) ;
break;
case V_104 :
* V_60 = false ;
break;
case V_105 :
* V_60 = false ;
break;
case V_106 :
* V_60 = V_2 -> V_14 . V_60 |
V_107 |
V_108 ;
break;
default:
* V_60 = 0 ;
V_98 = 1 ;
break;
}
return V_98 ;
}
static int F_50 ( struct V_15 * V_16 ,
int V_109 , T_2 * V_110 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
switch ( V_109 ) {
case V_111 :
case V_112 :
* V_110 = F_10 ( V_6 ) + 1 ;
break;
default:
return - V_44 ;
}
return 0 ;
}
static T_2 F_51 ( struct V_15 * V_16 )
{
struct V_46 V_47 ;
if ( F_23 ( V_16 , & V_47 ) )
return V_113 ;
return V_47 . V_57 ? V_88 : V_113 ;
}
static void F_52 ( struct V_15 * V_16 , T_2 V_114 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_75 * V_76 = & V_2 -> V_14 . V_76 ;
if ( ( V_114 != V_88 ) && ( V_114 != V_113 ) )
return;
V_76 -> V_83 = V_114 ;
}
static void F_53 ( struct V_1 * V_2 ,
enum V_3 * V_4 )
{
T_1 V_77 [ F_2 ( V_8 ) ] ;
* V_4 = V_11 ;
if ( ! F_3 ( V_2 -> V_6 , V_77 ) )
* V_4 = F_54 ( V_8 , V_77 , V_115 ) ;
if ( * V_4 != V_11 )
* V_4 = V_62 ;
}
static void F_55 ( struct V_1 * V_2 )
{
int V_23 ;
struct V_17 V_18 ;
if ( ! F_7 ( V_2 -> V_6 , V_18 ) )
return;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_25 = F_10 ( V_2 -> V_6 ) + 1 ;
for ( V_23 = 0 ; V_23 < V_18 . V_25 ; V_23 ++ ) {
V_18 . V_27 [ V_23 ] = V_28 ;
V_18 . V_31 [ V_23 ] = V_33 ;
V_18 . V_26 [ V_23 ] = V_23 ;
}
V_18 . V_26 [ 0 ] = 1 ;
V_18 . V_26 [ 1 ] = 0 ;
F_16 ( V_2 , & V_18 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
if ( ! F_7 ( V_2 -> V_6 , V_116 ) )
return;
if ( F_7 ( V_2 -> V_6 , V_14 ) )
F_53 ( V_2 , & V_14 -> V_4 ) ;
V_2 -> V_14 . V_60 = V_107 |
V_108 ;
if ( V_2 -> V_14 . V_4 == V_11 )
V_2 -> V_14 . V_60 |= V_63 ;
F_55 ( V_2 ) ;
}
