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
int V_9 = 0 ;
int V_19 ;
if ( ! F_7 ( V_2 -> V_6 , V_18 ) )
return - V_20 ;
V_18 -> V_21 = F_10 ( V_2 -> V_6 ) + 1 ;
for ( V_19 = 0 ; V_19 < V_18 -> V_21 ; V_19 ++ ) {
V_9 = F_11 ( V_6 , V_19 , & V_18 -> V_22 [ V_19 ] ) ;
if ( V_9 )
return V_9 ;
}
for ( V_19 = 0 ; V_19 < V_18 -> V_21 ; V_19 ++ ) {
V_9 = F_12 ( V_6 , V_19 , & V_18 -> V_23 [ V_19 ] ) ;
if ( V_9 )
return V_9 ;
if ( V_18 -> V_23 [ V_19 ] < V_24 )
V_2 -> V_14 . V_25 [ V_19 ] = V_26 ;
}
memcpy ( V_18 -> V_25 , V_2 -> V_14 . V_25 , sizeof( V_18 -> V_25 ) ) ;
return V_9 ;
}
static void F_13 ( struct V_17 * V_18 , T_2 * V_27 , int V_28 )
{
bool V_29 = false ;
int V_30 ;
int V_19 ;
for ( V_19 = 0 ; V_19 <= V_28 ; V_19 ++ )
if ( V_18 -> V_25 [ V_19 ] == V_26 )
V_29 = true ;
V_30 = V_29 ? 1 : 0 ;
for ( V_19 = 0 ; V_19 <= V_28 ; V_19 ++ ) {
switch ( V_18 -> V_25 [ V_19 ] ) {
case V_31 :
V_27 [ V_19 ] = V_32 ;
break;
case V_33 :
V_27 [ V_19 ] = V_30 ++ ;
break;
case V_26 :
V_27 [ V_19 ] = V_34 ;
break;
}
}
}
static void F_14 ( struct V_17 * V_18 , T_2 * V_23 ,
T_2 * V_27 , int V_28 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 <= V_28 ; V_19 ++ ) {
switch ( V_18 -> V_25 [ V_19 ] ) {
case V_31 :
V_23 [ V_19 ] = V_24 ;
break;
case V_33 :
V_23 [ V_19 ] = V_24 ;
break;
case V_26 :
V_23 [ V_19 ] = V_18 -> V_23 [ V_19 ] ;
break;
}
}
}
int F_15 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
T_2 V_23 [ V_35 ] ;
T_2 V_27 [ V_35 ] ;
int V_28 = F_10 ( V_6 ) ;
int V_9 ;
F_13 ( V_18 , V_27 , V_28 ) ;
F_14 ( V_18 , V_23 , V_27 , V_28 ) ;
V_9 = F_16 ( V_6 , V_18 -> V_22 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_17 ( V_6 , V_27 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_18 ( V_6 , V_23 ) ;
if ( V_9 )
return V_9 ;
memcpy ( V_2 -> V_14 . V_25 , V_18 -> V_25 , sizeof( V_18 -> V_25 ) ) ;
return V_9 ;
}
static int F_19 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
int V_36 = 0 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_35 ; V_19 ++ ) {
if ( V_18 -> V_22 [ V_19 ] >= V_37 ) {
F_20 ( V_16 ,
L_1 ,
V_37 ) ;
return - V_38 ;
}
}
for ( V_19 = 0 ; V_19 < V_35 ; V_19 ++ ) {
if ( V_18 -> V_25 [ V_19 ] == V_26 ) {
if ( ! V_18 -> V_23 [ V_19 ] ) {
F_20 ( V_16 ,
L_2 ) ;
return - V_38 ;
}
V_36 += V_18 -> V_23 [ V_19 ] ;
}
}
if ( V_36 != 0 && V_36 != 100 ) {
F_20 ( V_16 ,
L_3 ) ;
return - V_38 ;
}
return 0 ;
}
static int F_21 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
int V_9 ;
if ( ! F_7 ( V_2 -> V_6 , V_18 ) )
return - V_20 ;
V_9 = F_19 ( V_16 , V_18 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_15 ( V_2 , V_18 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_22 ( struct V_15 * V_39 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = F_9 ( V_39 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_42 * V_43 = & V_2 -> V_44 . V_45 ;
int V_19 ;
V_41 -> V_46 = F_10 ( V_6 ) + 1 ;
for ( V_19 = 0 ; V_19 < V_35 ; V_19 ++ ) {
V_41 -> V_47 [ V_19 ] = F_23 ( V_43 , V_19 , V_48 ) ;
V_41 -> V_49 [ V_19 ] = F_23 ( V_43 , V_19 , V_50 ) ;
}
return F_24 ( V_6 , & V_41 -> V_51 , NULL ) ;
}
static int F_25 ( struct V_15 * V_39 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = F_9 ( V_39 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_2 V_52 ;
int V_53 ;
F_24 ( V_6 , & V_52 , NULL ) ;
if ( V_41 -> V_51 == V_52 )
return 0 ;
V_53 = F_26 ( V_6 , V_41 -> V_51 , V_41 -> V_51 ) ;
F_27 ( V_6 ) ;
return V_53 ;
}
static T_2 F_28 ( struct V_15 * V_39 )
{
struct V_1 * V_2 = F_9 ( V_39 ) ;
struct V_13 * V_14 = & V_2 -> V_14 ;
T_2 V_4 = V_54 | V_55 ;
if ( V_14 -> V_4 == V_11 )
V_4 |= V_56 ;
return V_4 ;
}
static T_2 F_29 ( struct V_15 * V_39 , T_2 V_4 )
{
struct V_1 * V_2 = F_9 ( V_39 ) ;
struct V_13 * V_14 = & V_2 -> V_14 ;
if ( V_4 & V_57 )
return 1 ;
if ( ( ! V_4 ) && F_7 ( V_2 -> V_6 , V_14 ) ) {
if ( V_14 -> V_4 == V_58 )
return 0 ;
if ( ! F_1 ( V_2 , V_58 ) ) {
V_14 -> V_4 = V_58 ;
return 0 ;
}
return 1 ;
}
if ( ! ( V_4 & V_56 ) )
return 1 ;
if ( F_6 ( F_9 ( V_39 ) ) )
return 1 ;
return 0 ;
}
static int F_30 ( struct V_15 * V_16 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_2 V_61 [ V_35 ] ;
T_2 V_62 [ V_35 ] ;
int V_9 ;
int V_19 ;
V_9 = F_31 ( V_6 , V_61 , V_62 ) ;
if ( V_9 )
return V_9 ;
memset ( V_60 -> V_63 , 0 , sizeof( V_60 -> V_63 ) ) ;
for ( V_19 = 0 ; V_19 <= F_10 ( V_6 ) ; V_19 ++ ) {
switch ( V_62 [ V_19 ] ) {
case V_64 :
V_60 -> V_63 [ V_19 ] = V_61 [ V_19 ] * V_65 ;
break;
case V_66 :
V_60 -> V_63 [ V_19 ] = V_61 [ V_19 ] * V_67 ;
break;
case V_68 :
break;
default:
F_32 ( true , L_4 ) ;
break;
}
}
return 0 ;
}
static int F_33 ( struct V_15 * V_16 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_2 V_61 [ V_35 ] ;
T_2 V_62 [ V_35 ] ;
T_3 V_69 = F_34 ( 255 * V_65 , V_67 ) ;
int V_19 ;
memset ( V_61 , 0 , sizeof( V_61 ) ) ;
memset ( V_62 , 0 , sizeof( V_62 ) ) ;
for ( V_19 = 0 ; V_19 <= F_10 ( V_6 ) ; V_19 ++ ) {
if ( ! V_60 -> V_63 [ V_19 ] ) {
V_62 [ V_19 ] = V_68 ;
continue;
}
if ( V_60 -> V_63 [ V_19 ] < V_69 ) {
V_61 [ V_19 ] = F_35 ( V_60 -> V_63 [ V_19 ] ,
V_65 ) ;
V_61 [ V_19 ] = V_61 [ V_19 ] ? V_61 [ V_19 ] : 1 ;
V_62 [ V_19 ] = V_64 ;
} else {
V_61 [ V_19 ] = F_35 ( V_60 -> V_63 [ V_19 ] ,
V_67 ) ;
V_62 [ V_19 ] = V_66 ;
}
}
return F_36 ( V_6 , V_61 , V_62 ) ;
}
static T_2 F_37 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_70 * V_71 = & V_2 -> V_14 . V_71 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_17 V_18 ;
struct V_40 V_41 ;
int V_9 = - V_20 ;
int V_19 ;
if ( ! F_7 ( V_6 , V_18 ) )
goto V_72;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_18 . V_21 = V_35 ;
for ( V_19 = 0 ; V_19 < V_73 ; V_19 ++ ) {
V_18 . V_23 [ V_19 ] = V_71 -> V_74 [ V_19 ] ;
V_18 . V_75 [ V_19 ] = V_71 -> V_74 [ V_19 ] ;
V_18 . V_25 [ V_19 ] = V_26 ;
V_18 . V_22 [ V_19 ] = V_71 -> V_76 [ V_19 ] ;
}
V_9 = F_19 ( V_16 , & V_18 ) ;
if ( V_9 ) {
F_20 ( V_16 ,
L_5 , V_77 , V_9 ) ;
goto V_72;
}
V_9 = F_15 ( V_2 , & V_18 ) ;
if ( V_9 ) {
F_20 ( V_16 ,
L_6 , V_77 , V_9 ) ;
goto V_72;
}
V_41 . V_46 = F_10 ( V_6 ) + 1 ;
if ( ! V_71 -> V_78 )
V_41 . V_51 = 0 ;
else
for ( V_19 = 0 ; V_19 < V_79 ; V_19 ++ )
V_41 . V_51 |= V_71 -> V_80 [ V_19 ] << V_19 ;
V_9 = F_25 ( V_16 , & V_41 ) ;
if ( V_9 ) {
F_20 ( V_16 ,
L_7 , V_77 , V_9 ) ;
goto V_72;
}
V_72:
return V_9 ? V_81 : V_82 ;
}
static T_2 F_38 ( struct V_15 * V_16 )
{
return V_83 ;
}
static void F_39 ( struct V_15 * V_16 ,
T_2 * V_84 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
if ( ! V_84 )
return;
F_40 ( V_2 -> V_6 , 0 , V_84 ) ;
}
static void F_41 ( struct V_15 * V_16 ,
int V_85 , T_2 V_86 ,
T_2 V_87 , T_2 V_88 , T_2 V_89 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_70 * V_71 = & V_2 -> V_14 . V_71 ;
if ( V_85 >= V_79 ) {
F_20 ( V_16 ,
L_8 , V_77 ) ;
return;
}
if ( V_87 >= V_73 ) {
F_20 ( V_16 ,
L_9 , V_77 ) ;
return;
}
V_71 -> V_76 [ V_85 ] = V_87 ;
}
static void F_42 ( struct V_15 * V_16 ,
int V_87 , T_2 V_88 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_70 * V_71 = & V_2 -> V_14 . V_71 ;
if ( V_87 >= V_73 ) {
F_20 ( V_16 ,
L_9 , V_77 ) ;
return;
}
V_71 -> V_74 [ V_87 ] = V_88 ;
}
static void F_43 ( struct V_15 * V_16 ,
int V_85 , T_2 * V_86 ,
T_2 * V_87 , T_2 * V_88 , T_2 * V_89 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
if ( ! F_7 ( V_2 -> V_6 , V_18 ) ) {
F_20 ( V_16 , L_10 , V_77 ) ;
return;
}
if ( V_85 >= V_79 ) {
F_20 ( V_16 ,
L_8 , V_77 ) ;
return;
}
* V_86 = 0 ;
* V_88 = 0 ;
* V_89 = 0 ;
if ( F_11 ( V_6 , V_85 , V_87 ) )
* V_87 = 0 ;
}
static void F_44 ( struct V_15 * V_16 ,
int V_87 , T_2 * V_88 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
if ( V_87 >= V_73 ) {
F_20 ( V_16 ,
L_9 , V_77 ) ;
return;
}
if ( F_12 ( V_6 , V_87 , V_88 ) )
* V_88 = 0 ;
}
static void F_45 ( struct V_15 * V_16 ,
int V_85 , T_2 V_90 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_70 * V_71 = & V_2 -> V_14 . V_71 ;
if ( V_85 >= V_79 ) {
F_20 ( V_16 ,
L_8 , V_77 ) ;
return;
}
if ( V_90 > 1 )
return;
V_71 -> V_80 [ V_85 ] = V_90 ;
}
static int
F_46 ( struct V_15 * V_16 ,
int V_85 , T_2 * V_90 )
{
struct V_40 V_41 ;
int V_9 ;
V_9 = F_22 ( V_16 , & V_41 ) ;
if ( V_9 )
* V_90 = 0 ;
else
* V_90 = ( V_41 . V_51 >> V_85 ) & 0x01 ;
return V_9 ;
}
static void F_47 ( struct V_15 * V_16 ,
int V_85 , T_2 * V_90 )
{
if ( V_85 >= V_79 ) {
F_20 ( V_16 ,
L_8 , V_77 ) ;
return;
}
if ( ! V_90 )
return;
F_46 ( V_16 , V_85 , V_90 ) ;
}
static T_2 F_48 ( struct V_15 * V_16 ,
int V_91 , T_2 * V_92 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_2 V_93 = 0 ;
switch ( V_91 ) {
case V_94 :
* V_92 = true ;
break;
case V_95 :
* V_92 = true ;
break;
case V_96 :
* V_92 = false ;
break;
case V_97 :
* V_92 = 1 << F_10 ( V_6 ) ;
break;
case V_98 :
* V_92 = 1 << F_10 ( V_6 ) ;
break;
case V_99 :
* V_92 = false ;
break;
case V_100 :
* V_92 = false ;
break;
case V_101 :
* V_92 = ( V_57 |
V_55 |
V_102 ) ;
break;
default:
* V_92 = 0 ;
V_93 = 1 ;
break;
}
return V_93 ;
}
static int F_49 ( struct V_15 * V_16 ,
int V_103 , T_2 * V_104 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
switch ( V_103 ) {
case V_105 :
case V_106 :
* V_104 = F_10 ( V_6 ) + 1 ;
break;
default:
return - V_38 ;
}
return 0 ;
}
static T_2 F_50 ( struct V_15 * V_16 )
{
struct V_40 V_41 ;
if ( F_22 ( V_16 , & V_41 ) )
return V_107 ;
return V_41 . V_51 ? V_83 : V_107 ;
}
static void F_51 ( struct V_15 * V_16 , T_2 V_108 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_70 * V_71 = & V_2 -> V_14 . V_71 ;
if ( ( V_108 != V_83 ) && ( V_108 != V_107 ) )
return;
V_71 -> V_78 = V_108 ;
}
static void F_52 ( struct V_1 * V_2 ,
enum V_3 * V_4 )
{
T_1 V_72 [ F_2 ( V_8 ) ] ;
* V_4 = V_11 ;
if ( ! F_3 ( V_2 -> V_6 , V_72 ) )
* V_4 = F_53 ( V_8 , V_72 , V_109 ) ;
if ( * V_4 != V_11 )
* V_4 = V_58 ;
}
static void F_54 ( struct V_1 * V_2 )
{
int V_19 ;
struct V_17 V_18 ;
if ( ! F_7 ( V_2 -> V_6 , V_18 ) )
return;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_21 = F_10 ( V_2 -> V_6 ) + 1 ;
for ( V_19 = 0 ; V_19 < V_18 . V_21 ; V_19 ++ ) {
V_18 . V_23 [ V_19 ] = V_24 ;
V_18 . V_25 [ V_19 ] = V_31 ;
V_18 . V_22 [ V_19 ] = V_19 ;
}
memcpy ( V_2 -> V_14 . V_25 , V_18 . V_25 , sizeof( V_18 . V_25 ) ) ;
V_18 . V_22 [ 0 ] = 1 ;
V_18 . V_22 [ 1 ] = 0 ;
F_15 ( V_2 , & V_18 ) ;
}
void F_55 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = & V_2 -> V_14 ;
if ( F_7 ( V_2 -> V_6 , V_14 ) )
F_52 ( V_2 , & V_14 -> V_4 ) ;
F_54 ( V_2 ) ;
}
