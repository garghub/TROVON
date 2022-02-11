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
struct V_30 * V_31 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_32 ;
int V_6 ;
int V_33 ;
T_1 V_34 ;
if ( V_29 -> V_35 == V_36 )
V_33 = V_37 ;
else
V_33 = V_38 ;
V_32 = F_11 ( V_4 -> V_39 ) ;
if ( ( V_32 != V_40 ) &&
( V_32 != V_41 ) ) {
F_12 ( V_2 -> V_13 ,
L_2 ,
V_42 , V_32 ,
V_40 , V_41 ) ;
return - V_22 ;
}
V_34 = V_43 [ 0 ] . V_10 ;
for ( V_6 = 1 ; V_6 < F_3 ( V_43 ) ; V_6 ++ )
if ( F_13 ( V_31 ) <= V_43 [ V_6 ] . V_10 )
V_34 = V_43 [ V_6 ] . V_34 ;
if ( V_29 -> V_35 == V_36 ) {
V_4 -> V_11 = F_13 ( V_31 ) ;
F_1 ( V_2 ) ;
}
return F_5 ( V_2 , V_33 , V_44 , V_34 ) ;
}
static int F_14 ( struct V_23 * V_45 ,
unsigned int V_46 )
{
struct V_1 * V_2 = V_45 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_32 ;
T_1 V_47 = V_48 ;
if ( ( V_46 & V_49 ) != V_50 )
return - V_22 ;
switch ( V_46 & V_51 ) {
case V_52 :
V_47 |= V_53 ;
break;
case V_54 :
V_47 |= V_55 ;
break;
case V_56 :
V_47 |= V_57 ;
break;
default:
return - V_22 ;
}
if ( ( V_46 & V_58 ) != V_59 )
return - V_22 ;
F_15 ( V_2 , V_60 , V_47 ) ;
F_15 ( V_2 , V_61 , V_47 ) ;
V_32 = F_11 ( V_4 -> V_39 ) ;
if ( V_32 == V_40 )
F_15 ( V_2 , V_62 ,
V_63 ) ;
else
F_15 ( V_2 , V_62 ,
V_64 |
V_63 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
enum V_65 V_66 )
{
switch ( V_66 ) {
case V_67 :
break;
case V_68 :
F_15 ( V_2 , V_69 , 0 ) ;
F_5 ( V_2 , V_70 ,
V_71 |
V_72 ,
V_73 |
V_72 ) ;
break;
case V_74 :
if ( F_17 ( V_2 ) == V_75 ) {
F_5 ( V_2 , V_70 ,
V_71 |
V_72 ,
V_76 |
V_72 ) ;
F_18 ( 100 ) ;
}
F_15 ( V_2 , V_77 ,
V_78 |
V_79 ) ;
F_5 ( V_2 , V_70 ,
V_71 |
V_72 ,
V_80 |
V_72 ) ;
break;
case V_75 :
F_5 ( V_2 , V_70 ,
V_71 |
V_72 ,
0 ) ;
break;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_21 ;
V_4 = F_2 ( V_2 ) ;
F_20 ( V_4 -> V_39 ) ;
V_21 = F_21 ( F_3 ( V_4 -> V_81 ) ,
V_4 -> V_81 ) ;
if ( V_21 ) {
F_12 ( V_2 -> V_13 , L_3 ) ;
return V_21 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_82 * V_82 = F_23 ( V_2 -> V_13 , NULL ) ;
struct V_3 * V_4 ;
int V_21 ;
V_4 = F_2 ( V_2 ) ;
V_21 = F_24 ( V_4 -> V_39 ) ;
if ( V_21 ) {
F_12 ( V_2 -> V_13 , L_4 ) ;
return V_21 ;
}
V_21 = F_25 ( F_3 ( V_4 -> V_81 ) ,
V_4 -> V_81 ) ;
if ( V_21 ) {
F_12 ( V_2 -> V_13 , L_5 ) ;
return V_21 ;
}
F_26 ( V_82 ) ;
V_21 = F_27 ( V_82 ) ;
if ( V_21 ) {
F_12 ( V_2 -> V_13 , L_6 ) ;
return V_21 ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_21 ;
V_4 = F_2 ( V_2 ) ;
V_21 = F_25 ( F_3 ( V_4 -> V_81 ) ,
V_4 -> V_81 ) ;
if ( V_21 ) {
F_12 ( V_2 -> V_13 , L_5 ) ;
return V_21 ;
}
V_4 -> V_39 = F_29 ( V_2 -> V_13 , NULL ) ;
if ( F_30 ( V_4 -> V_39 ) ) {
F_12 ( V_2 -> V_13 , L_7 ) ;
V_21 = F_31 ( V_4 -> V_39 ) ;
goto V_83;
}
V_21 = F_24 ( V_4 -> V_39 ) ;
if ( V_21 ) {
F_12 ( V_2 -> V_13 , L_8 ) ;
goto V_83;
}
return 0 ;
V_83:
F_21 ( F_3 ( V_4 -> V_81 ) ,
V_4 -> V_81 ) ;
return V_21 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_39 )
F_20 ( V_4 -> V_39 ) ;
F_21 ( F_3 ( V_4 -> V_81 ) ,
V_4 -> V_81 ) ;
return 0 ;
}
int F_33 ( struct V_84 * V_13 , struct V_82 * V_82 )
{
struct V_3 * V_4 ;
int V_21 ;
int V_6 ;
if ( F_30 ( V_82 ) )
return F_31 ( V_82 ) ;
V_4 = F_34 ( V_13 , sizeof( * V_4 ) , V_85 ) ;
if ( V_4 == NULL )
return - V_86 ;
V_4 -> V_82 = V_82 ;
for ( V_6 = 0 ; V_6 < F_3 ( V_4 -> V_81 ) ; V_6 ++ )
V_4 -> V_81 [ V_6 ] . V_87 = V_88 [ V_6 ] ;
V_21 = F_35 ( V_13 , F_3 ( V_4 -> V_81 ) ,
V_4 -> V_81 ) ;
if ( V_21 ) {
F_12 ( V_13 , L_9 ) ;
return V_21 ;
}
F_36 ( V_13 , V_4 ) ;
return F_37 ( V_13 ,
& V_89 , & V_90 , 1 ) ;
}
