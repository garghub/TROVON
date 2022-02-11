static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 , V_6 , V_7 ;
if ( V_4 -> V_8 ) {
V_7 = 1 ;
for ( V_6 = 2 ; V_6 < F_3 ( V_9 ) ; V_6 ++ ) {
if ( abs ( V_9 [ V_6 ] - V_4 -> V_10 ) <
abs ( V_9 [ V_7 ] - V_4 -> V_10 ) )
V_7 = V_6 ;
}
V_5 = V_7 << 1 ;
} else {
V_5 = 0 ;
}
F_4 ( V_2 -> V_11 , L_1 , V_5 ) ;
return F_5 ( V_2 , V_12 , 0x6 , V_5 ) ;
}
static int F_6 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = F_7 ( V_14 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_16 -> V_17 . V_18 . V_19 [ 0 ] = V_4 -> V_8 ;
return 0 ;
}
static int F_8 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = F_7 ( V_14 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_8 = V_16 -> V_17 . V_18 . V_19 [ 0 ] ;
int V_20 ;
if ( V_8 > 1 )
return - V_21 ;
V_20 = F_1 ( V_2 ) ;
if ( V_20 < 0 )
return V_20 ;
V_4 -> V_8 = V_8 ;
return 0 ;
}
static int F_9 ( struct V_22 * V_23 , int V_24 )
{
return F_5 ( V_23 -> V_2 , V_25 ,
V_26 ,
V_24 ? V_26 : 0 ) ;
}
static int F_10 ( struct V_27 * V_28 ,
struct V_29 * V_30 ,
struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_31 ;
int V_6 ;
int V_32 ;
T_1 V_33 ;
if ( V_28 -> V_34 == V_35 )
V_32 = V_36 ;
else
V_32 = V_37 ;
V_31 = F_11 ( V_4 -> V_38 ) ;
if ( ( V_31 != V_39 ) &&
( V_31 != V_40 ) ) {
F_12 ( V_2 -> V_11 ,
L_2 ,
V_41 , V_31 ,
V_39 , V_40 ) ;
return - V_21 ;
}
V_33 = V_42 [ 0 ] . V_43 ;
for ( V_6 = 1 ; V_6 < F_3 ( V_42 ) ; V_6 ++ )
if ( F_13 ( V_30 ) <= V_42 [ V_6 ] . V_43 )
V_33 = V_42 [ V_6 ] . V_33 ;
if ( V_28 -> V_34 == V_35 ) {
V_4 -> V_10 = F_13 ( V_30 ) ;
F_1 ( V_2 ) ;
}
return F_5 ( V_2 , V_32 , V_44 , V_33 ) ;
}
static int F_14 ( struct V_22 * V_45 ,
unsigned int V_46 )
{
struct V_1 * V_2 = V_45 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_31 ;
T_1 V_47 = V_48 ;
if ( ( V_46 & V_49 ) != V_50 )
return - V_21 ;
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
return - V_21 ;
}
if ( ( V_46 & V_58 ) != V_59 )
return - V_21 ;
F_15 ( V_2 , V_60 , V_47 ) ;
F_15 ( V_2 , V_61 , V_47 ) ;
V_31 = F_11 ( V_4 -> V_38 ) ;
if ( V_31 == V_39 )
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
if ( V_2 -> V_75 . V_76 == V_77 ) {
F_5 ( V_2 , V_70 ,
V_71 |
V_72 ,
V_78 |
V_72 ) ;
F_17 ( 100 ) ;
}
F_15 ( V_2 , V_79 ,
V_80 |
V_81 ) ;
F_5 ( V_2 , V_70 ,
V_71 |
V_72 ,
V_82 |
V_72 ) ;
break;
case V_77 :
F_5 ( V_2 , V_70 ,
V_71 |
V_72 ,
0 ) ;
break;
}
V_2 -> V_75 . V_76 = V_66 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_20 ;
V_4 = F_2 ( V_2 ) ;
F_19 ( V_4 -> V_38 ) ;
V_20 = F_20 ( F_3 ( V_4 -> V_83 ) ,
V_4 -> V_83 ) ;
if ( V_20 ) {
F_12 ( V_2 -> V_11 , L_3 ) ;
return V_20 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_84 * V_84 = F_22 ( V_2 -> V_11 , NULL ) ;
struct V_3 * V_4 ;
int V_20 ;
V_4 = F_2 ( V_2 ) ;
V_20 = F_23 ( V_4 -> V_38 ) ;
if ( V_20 ) {
F_12 ( V_2 -> V_11 , L_4 ) ;
return V_20 ;
}
V_20 = F_24 ( F_3 ( V_4 -> V_83 ) ,
V_4 -> V_83 ) ;
if ( V_20 ) {
F_12 ( V_2 -> V_11 , L_5 ) ;
return V_20 ;
}
F_25 ( V_84 ) ;
V_20 = F_26 ( V_84 ) ;
if ( V_20 ) {
F_12 ( V_2 -> V_11 , L_6 ) ;
return V_20 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_20 ;
V_4 = F_2 ( V_2 ) ;
V_20 = F_24 ( F_3 ( V_4 -> V_83 ) ,
V_4 -> V_83 ) ;
if ( V_20 ) {
F_12 ( V_2 -> V_11 , L_5 ) ;
return V_20 ;
}
V_4 -> V_38 = F_28 ( V_2 -> V_11 , NULL ) ;
if ( F_29 ( V_4 -> V_38 ) ) {
F_12 ( V_2 -> V_11 , L_7 ) ;
V_20 = F_30 ( V_4 -> V_38 ) ;
goto V_85;
}
V_20 = F_23 ( V_4 -> V_38 ) ;
if ( V_20 ) {
F_12 ( V_2 -> V_11 , L_8 ) ;
goto V_85;
}
return 0 ;
V_85:
F_20 ( F_3 ( V_4 -> V_83 ) ,
V_4 -> V_83 ) ;
return V_20 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_38 )
F_19 ( V_4 -> V_38 ) ;
F_20 ( F_3 ( V_4 -> V_83 ) ,
V_4 -> V_83 ) ;
return 0 ;
}
int F_32 ( struct V_86 * V_11 , struct V_84 * V_84 )
{
struct V_3 * V_4 ;
int V_20 ;
int V_6 ;
if ( F_29 ( V_84 ) )
return F_30 ( V_84 ) ;
V_4 = F_33 ( V_11 , sizeof( * V_4 ) , V_87 ) ;
if ( V_4 == NULL )
return - V_88 ;
V_4 -> V_84 = V_84 ;
for ( V_6 = 0 ; V_6 < F_3 ( V_4 -> V_83 ) ; V_6 ++ )
V_4 -> V_83 [ V_6 ] . V_89 = V_90 [ V_6 ] ;
V_20 = F_34 ( V_11 , F_3 ( V_4 -> V_83 ) ,
V_4 -> V_83 ) ;
if ( V_20 ) {
F_12 ( V_11 , L_9 ) ;
return V_20 ;
}
F_35 ( V_11 , V_4 ) ;
return F_36 ( V_11 ,
& V_91 , & V_92 , 1 ) ;
}
