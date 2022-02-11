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
if ( V_4 -> V_30 && V_4 -> V_31 )
F_11 ( V_29 -> V_32 , 0 ,
V_33 ,
V_4 -> V_31 ) ;
return 0 ;
}
static int F_12 ( struct V_28 * V_29 ,
struct V_34 * V_35 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 ;
int V_36 ;
int V_37 ;
int V_38 ;
if ( V_29 -> V_39 == V_40 )
V_36 = V_41 ;
else
V_36 = V_42 ;
if ( V_4 -> V_30 ) {
if ( ! V_4 -> V_31 ) {
F_13 ( V_2 -> V_13 , L_2 ) ;
return - V_22 ;
}
for ( V_6 = 0 ; V_6 < V_4 -> V_31 -> V_43 ; V_6 ++ )
if ( V_4 -> V_31 -> V_44 [ V_6 ] ==
F_14 ( V_35 ) )
break;
if ( V_6 == V_4 -> V_31 -> V_43 ) {
F_13 ( V_2 -> V_13 ,
L_3 ,
F_14 ( V_35 ) ) ;
return - V_22 ;
}
V_38 = V_4 -> V_45 [ V_6 ] ;
} else {
V_38 = 0 ;
V_4 -> V_46 = 0 ;
}
F_5 ( V_2 , V_47 ,
V_48 ,
V_4 -> V_46 ? V_48 : 0 ) ;
switch ( F_15 ( V_35 ) ) {
case 16 :
V_37 = 3 ;
break;
case 18 :
V_37 = 2 ;
break;
case 20 :
V_37 = 1 ;
break;
case 24 :
V_37 = 0 ;
break;
case 32 :
V_37 = 4 ;
break;
default:
return - V_22 ;
}
if ( V_29 -> V_39 == V_40 ) {
F_5 ( V_2 , V_49 ,
V_50 ,
V_37 << V_51 ) ;
V_4 -> V_11 = F_14 ( V_35 ) ;
F_1 ( V_2 ) ;
} else
F_5 ( V_2 , V_52 ,
V_53 ,
V_37 << V_54 ) ;
return F_5 ( V_2 , V_36 , V_55 , V_38 ) ;
}
static int F_16 ( struct V_23 * V_56 ,
int V_57 , unsigned int V_58 , int V_59 )
{
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_46 = 0 ;
switch ( V_58 ) {
case 0 :
V_4 -> V_31 = NULL ;
V_4 -> V_45 = NULL ;
break;
case 22579200 :
V_46 = 1 ;
case 11289600 :
V_4 -> V_31 = & V_60 ;
V_4 -> V_45 = V_61 ;
break;
case 24576000 :
V_46 = 1 ;
case 12288000 :
V_4 -> V_31 = & V_62 ;
V_4 -> V_45 = V_63 ;
break;
default:
return - V_22 ;
}
V_4 -> V_46 = V_46 ;
return 0 ;
}
static int F_17 ( struct V_23 * V_56 ,
unsigned int V_64 )
{
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_65 = 0 ;
T_1 V_66 = 0 ;
switch ( V_64 & V_67 ) {
case V_68 :
F_5 ( V_2 , V_47 ,
V_69 ,
V_69 ) ;
V_4 -> V_30 = true ;
break;
case V_70 :
F_5 ( V_2 , V_47 ,
V_69 , 0 ) ;
V_4 -> V_30 = false ;
break;
default:
return - V_22 ;
}
switch ( V_64 & V_71 ) {
case V_72 :
V_65 |= V_73 ;
V_66 |= V_74 ;
break;
case V_75 :
V_65 |= V_76 ;
V_66 |= V_77 ;
break;
case V_78 :
V_65 |= V_79 ;
V_66 |= V_80 ;
break;
default:
return - V_22 ;
}
if ( ( V_64 & V_81 ) != V_82 )
return - V_22 ;
F_5 ( V_2 , V_49 ,
V_83 , V_65 ) ;
F_5 ( V_2 , V_52 ,
V_84 , V_66 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
enum V_85 V_86 )
{
switch ( V_86 ) {
case V_87 :
break;
case V_88 :
F_19 ( V_2 , V_89 , 0 ) ;
F_5 ( V_2 , V_90 ,
V_91 |
V_92 ,
V_93 |
V_92 ) ;
break;
case V_94 :
if ( F_20 ( V_2 ) == V_95 ) {
F_5 ( V_2 , V_90 ,
V_91 |
V_92 ,
V_96 |
V_92 ) ;
F_21 ( 100 ) ;
}
F_19 ( V_2 , V_97 ,
V_98 |
V_99 ) ;
F_5 ( V_2 , V_90 ,
V_91 |
V_92 ,
V_100 |
V_92 ) ;
break;
case V_95 :
F_5 ( V_2 , V_90 ,
V_91 |
V_92 ,
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
F_23 ( V_4 -> V_101 ) ;
V_21 = F_24 ( F_3 ( V_4 -> V_102 ) ,
V_4 -> V_102 ) ;
if ( V_21 ) {
F_13 ( V_2 -> V_13 , L_4 ) ;
return V_21 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_103 * V_103 = F_26 ( V_2 -> V_13 , NULL ) ;
struct V_3 * V_4 ;
int V_21 ;
V_4 = F_2 ( V_2 ) ;
V_21 = F_27 ( V_4 -> V_101 ) ;
if ( V_21 ) {
F_13 ( V_2 -> V_13 , L_5 ) ;
return V_21 ;
}
V_21 = F_28 ( F_3 ( V_4 -> V_102 ) ,
V_4 -> V_102 ) ;
if ( V_21 ) {
F_13 ( V_2 -> V_13 , L_6 ) ;
return V_21 ;
}
F_29 ( V_103 ) ;
V_21 = F_30 ( V_103 ) ;
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
V_21 = F_28 ( F_3 ( V_4 -> V_102 ) ,
V_4 -> V_102 ) ;
if ( V_21 ) {
F_13 ( V_2 -> V_13 , L_6 ) ;
return V_21 ;
}
V_4 -> V_101 = F_32 ( V_2 -> V_13 , NULL ) ;
if ( F_33 ( V_4 -> V_101 ) ) {
F_13 ( V_2 -> V_13 , L_8 ) ;
V_21 = F_34 ( V_4 -> V_101 ) ;
goto V_104;
}
V_21 = F_27 ( V_4 -> V_101 ) ;
if ( V_21 ) {
F_13 ( V_2 -> V_13 , L_9 ) ;
goto V_104;
}
return 0 ;
V_104:
F_24 ( F_3 ( V_4 -> V_102 ) ,
V_4 -> V_102 ) ;
return V_21 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_101 )
F_23 ( V_4 -> V_101 ) ;
F_24 ( F_3 ( V_4 -> V_102 ) ,
V_4 -> V_102 ) ;
return 0 ;
}
int F_36 ( struct V_105 * V_13 , struct V_103 * V_103 )
{
struct V_3 * V_4 ;
int V_21 ;
int V_6 ;
if ( F_33 ( V_103 ) )
return F_34 ( V_103 ) ;
V_4 = F_37 ( V_13 , sizeof( * V_4 ) , V_106 ) ;
if ( V_4 == NULL )
return - V_107 ;
V_4 -> V_103 = V_103 ;
for ( V_6 = 0 ; V_6 < F_3 ( V_4 -> V_102 ) ; V_6 ++ )
V_4 -> V_102 [ V_6 ] . V_108 = V_109 [ V_6 ] ;
V_21 = F_38 ( V_13 , F_3 ( V_4 -> V_102 ) ,
V_4 -> V_102 ) ;
if ( V_21 ) {
F_13 ( V_13 , L_10 ) ;
return V_21 ;
}
F_39 ( V_13 , V_4 ) ;
return F_40 ( V_13 ,
& V_110 , & V_111 , 1 ) ;
}
