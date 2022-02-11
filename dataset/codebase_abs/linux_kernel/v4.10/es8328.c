static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 , V_6 , V_7 ;
if ( V_4 -> V_8 ) {
V_7 = 0 ;
for ( V_6 = 1 ; V_6 < F_3 ( V_9 ) ; V_6 ++ ) {
if ( abs ( V_9 [ V_6 ] . V_10 - V_4 -> V_11 ) <
abs ( V_9 [ V_7 ] . V_10 - V_4 -> V_11 ) )
V_7 = V_6 ;
}
V_5 = V_9 [ V_7 ] . V_5 ;
} else {
V_5 = V_12 ;
}
F_4 ( V_2 -> V_13 , L_1 , V_5 ) ;
return F_5 ( V_2 , V_14 ,
V_15 , V_5 ) ;
}
static int F_6 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = F_7 ( V_17 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_19 -> V_20 . integer . V_20 [ 0 ] = V_4 -> V_8 ;
return 0 ;
}
static int F_8 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = F_7 ( V_17 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_8 = V_19 -> V_20 . integer . V_20 [ 0 ] ;
int V_21 ;
if ( V_8 > 1 )
return - V_22 ;
V_21 = F_1 ( V_2 ) ;
if ( V_21 < 0 )
return V_21 ;
V_4 -> V_8 = V_8 ;
return 0 ;
}
static int F_9 ( struct V_23 * V_24 , int V_25 )
{
return F_5 ( V_24 -> V_2 , V_26 ,
V_27 ,
V_25 ? V_27 : 0 ) ;
}
static int F_10 ( struct V_28 * V_29 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_30 )
F_11 ( V_29 -> V_31 , 0 ,
V_32 ,
V_4 -> V_30 ) ;
return 0 ;
}
static int F_12 ( struct V_28 * V_29 ,
struct V_33 * V_34 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 ;
int V_35 ;
int V_36 ;
int V_37 ;
if ( ! V_4 -> V_30 ) {
F_13 ( V_2 -> V_13 , L_2 ) ;
return - V_22 ;
}
if ( V_29 -> V_38 == V_39 )
V_35 = V_40 ;
else
V_35 = V_41 ;
for ( V_6 = 0 ; V_6 < V_4 -> V_30 -> V_42 ; V_6 ++ )
if ( V_4 -> V_30 -> V_43 [ V_6 ] == F_14 ( V_34 ) )
break;
if ( V_6 == V_4 -> V_30 -> V_42 ) {
F_13 ( V_2 -> V_13 , L_3 ,
F_14 ( V_34 ) ) ;
return - V_22 ;
}
V_37 = V_4 -> V_44 [ V_6 ] ;
F_5 ( V_2 , V_45 ,
V_46 ,
V_4 -> V_47 ? V_46 : 0 ) ;
switch ( F_15 ( V_34 ) ) {
case 16 :
V_36 = 3 ;
break;
case 18 :
V_36 = 2 ;
break;
case 20 :
V_36 = 1 ;
break;
case 24 :
V_36 = 0 ;
break;
case 32 :
V_36 = 4 ;
break;
default:
return - V_22 ;
}
if ( V_29 -> V_38 == V_39 ) {
F_5 ( V_2 , V_48 ,
V_49 ,
V_36 << V_50 ) ;
V_4 -> V_11 = F_14 ( V_34 ) ;
F_1 ( V_2 ) ;
} else
F_5 ( V_2 , V_51 ,
V_52 ,
V_36 << V_53 ) ;
return F_5 ( V_2 , V_35 , V_54 , V_37 ) ;
}
static int F_16 ( struct V_23 * V_55 ,
int V_56 , unsigned int V_57 , int V_58 )
{
struct V_1 * V_2 = V_55 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_47 = 0 ;
switch ( V_57 ) {
case 0 :
V_4 -> V_30 = NULL ;
V_4 -> V_44 = NULL ;
break;
case 22579200 :
V_47 = 1 ;
case 11289600 :
V_4 -> V_30 = & V_59 ;
V_4 -> V_44 = V_60 ;
break;
case 24576000 :
V_47 = 1 ;
case 12288000 :
V_4 -> V_30 = & V_61 ;
V_4 -> V_44 = V_62 ;
break;
default:
return - V_22 ;
}
V_4 -> V_47 = V_47 ;
return 0 ;
}
static int F_17 ( struct V_23 * V_55 ,
unsigned int V_63 )
{
struct V_1 * V_2 = V_55 -> V_2 ;
T_1 V_64 = 0 ;
T_1 V_65 = 0 ;
if ( ( V_63 & V_66 ) != V_67 )
return - V_22 ;
switch ( V_63 & V_68 ) {
case V_69 :
V_64 |= V_70 ;
V_65 |= V_71 ;
break;
case V_72 :
V_64 |= V_73 ;
V_65 |= V_74 ;
break;
case V_75 :
V_64 |= V_76 ;
V_65 |= V_77 ;
break;
default:
return - V_22 ;
}
if ( ( V_63 & V_78 ) != V_79 )
return - V_22 ;
F_5 ( V_2 , V_48 ,
V_80 , V_64 ) ;
F_5 ( V_2 , V_51 ,
V_81 , V_65 ) ;
F_5 ( V_2 , V_45 ,
V_82 , V_82 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
enum V_83 V_84 )
{
switch ( V_84 ) {
case V_85 :
break;
case V_86 :
F_19 ( V_2 , V_87 , 0 ) ;
F_5 ( V_2 , V_88 ,
V_89 |
V_90 ,
V_91 |
V_90 ) ;
break;
case V_92 :
if ( F_20 ( V_2 ) == V_93 ) {
F_5 ( V_2 , V_88 ,
V_89 |
V_90 ,
V_94 |
V_90 ) ;
F_21 ( 100 ) ;
}
F_19 ( V_2 , V_95 ,
V_96 |
V_97 ) ;
F_5 ( V_2 , V_88 ,
V_89 |
V_90 ,
V_98 |
V_90 ) ;
break;
case V_93 :
F_5 ( V_2 , V_88 ,
V_89 |
V_90 ,
0 ) ;
break;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_21 ;
V_4 = F_2 ( V_2 ) ;
F_23 ( V_4 -> V_99 ) ;
V_21 = F_24 ( F_3 ( V_4 -> V_100 ) ,
V_4 -> V_100 ) ;
if ( V_21 ) {
F_13 ( V_2 -> V_13 , L_4 ) ;
return V_21 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_101 * V_101 = F_26 ( V_2 -> V_13 , NULL ) ;
struct V_3 * V_4 ;
int V_21 ;
V_4 = F_2 ( V_2 ) ;
V_21 = F_27 ( V_4 -> V_99 ) ;
if ( V_21 ) {
F_13 ( V_2 -> V_13 , L_5 ) ;
return V_21 ;
}
V_21 = F_28 ( F_3 ( V_4 -> V_100 ) ,
V_4 -> V_100 ) ;
if ( V_21 ) {
F_13 ( V_2 -> V_13 , L_6 ) ;
return V_21 ;
}
F_29 ( V_101 ) ;
V_21 = F_30 ( V_101 ) ;
if ( V_21 ) {
F_13 ( V_2 -> V_13 , L_7 ) ;
return V_21 ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_21 ;
V_4 = F_2 ( V_2 ) ;
V_21 = F_28 ( F_3 ( V_4 -> V_100 ) ,
V_4 -> V_100 ) ;
if ( V_21 ) {
F_13 ( V_2 -> V_13 , L_6 ) ;
return V_21 ;
}
V_4 -> V_99 = F_32 ( V_2 -> V_13 , NULL ) ;
if ( F_33 ( V_4 -> V_99 ) ) {
F_13 ( V_2 -> V_13 , L_8 ) ;
V_21 = F_34 ( V_4 -> V_99 ) ;
goto V_102;
}
V_21 = F_27 ( V_4 -> V_99 ) ;
if ( V_21 ) {
F_13 ( V_2 -> V_13 , L_9 ) ;
goto V_102;
}
return 0 ;
V_102:
F_24 ( F_3 ( V_4 -> V_100 ) ,
V_4 -> V_100 ) ;
return V_21 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_99 )
F_23 ( V_4 -> V_99 ) ;
F_24 ( F_3 ( V_4 -> V_100 ) ,
V_4 -> V_100 ) ;
return 0 ;
}
int F_36 ( struct V_103 * V_13 , struct V_101 * V_101 )
{
struct V_3 * V_4 ;
int V_21 ;
int V_6 ;
if ( F_33 ( V_101 ) )
return F_34 ( V_101 ) ;
V_4 = F_37 ( V_13 , sizeof( * V_4 ) , V_104 ) ;
if ( V_4 == NULL )
return - V_105 ;
V_4 -> V_101 = V_101 ;
for ( V_6 = 0 ; V_6 < F_3 ( V_4 -> V_100 ) ; V_6 ++ )
V_4 -> V_100 [ V_6 ] . V_106 = V_107 [ V_6 ] ;
V_21 = F_38 ( V_13 , F_3 ( V_4 -> V_100 ) ,
V_4 -> V_100 ) ;
if ( V_21 ) {
F_13 ( V_13 , L_10 ) ;
return V_21 ;
}
F_39 ( V_13 , V_4 ) ;
return F_40 ( V_13 ,
& V_108 , & V_109 , 1 ) ;
}
