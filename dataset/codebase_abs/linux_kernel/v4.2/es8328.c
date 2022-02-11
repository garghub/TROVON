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
V_16 -> V_17 . integer . V_17 [ 0 ] = V_4 -> V_8 ;
return 0 ;
}
static int F_8 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = F_7 ( V_14 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_8 = V_16 -> V_17 . integer . V_17 [ 0 ] ;
int V_18 ;
if ( V_8 > 1 )
return - V_19 ;
V_18 = F_1 ( V_2 ) ;
if ( V_18 < 0 )
return V_18 ;
V_4 -> V_8 = V_8 ;
return 0 ;
}
static int F_9 ( struct V_20 * V_21 , int V_22 )
{
return F_5 ( V_21 -> V_2 , V_23 ,
V_24 ,
V_22 ? V_24 : 0 ) ;
}
static int F_10 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_29 ;
int V_6 ;
int V_30 ;
T_1 V_31 ;
if ( V_26 -> V_32 == V_33 )
V_30 = V_34 ;
else
V_30 = V_35 ;
V_29 = F_11 ( V_4 -> V_36 ) ;
if ( ( V_29 != V_37 ) &&
( V_29 != V_38 ) ) {
F_12 ( V_2 -> V_11 ,
L_2 ,
V_39 , V_29 ,
V_37 , V_38 ) ;
return - V_19 ;
}
V_31 = V_40 [ 0 ] . V_41 ;
for ( V_6 = 1 ; V_6 < F_3 ( V_40 ) ; V_6 ++ )
if ( F_13 ( V_28 ) <= V_40 [ V_6 ] . V_41 )
V_31 = V_40 [ V_6 ] . V_31 ;
if ( V_26 -> V_32 == V_33 ) {
V_4 -> V_10 = F_13 ( V_28 ) ;
F_1 ( V_2 ) ;
}
return F_5 ( V_2 , V_30 , V_42 , V_31 ) ;
}
static int F_14 ( struct V_20 * V_43 ,
unsigned int V_44 )
{
struct V_1 * V_2 = V_43 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_29 ;
T_1 V_45 = V_46 ;
if ( ( V_44 & V_47 ) != V_48 )
return - V_19 ;
switch ( V_44 & V_49 ) {
case V_50 :
V_45 |= V_51 ;
break;
case V_52 :
V_45 |= V_53 ;
break;
case V_54 :
V_45 |= V_55 ;
break;
default:
return - V_19 ;
}
if ( ( V_44 & V_56 ) != V_57 )
return - V_19 ;
F_15 ( V_2 , V_58 , V_45 ) ;
F_15 ( V_2 , V_59 , V_45 ) ;
V_29 = F_11 ( V_4 -> V_36 ) ;
if ( V_29 == V_37 )
F_15 ( V_2 , V_60 ,
V_61 ) ;
else
F_15 ( V_2 , V_60 ,
V_62 |
V_61 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
enum V_63 V_64 )
{
switch ( V_64 ) {
case V_65 :
break;
case V_66 :
F_15 ( V_2 , V_67 , 0 ) ;
F_5 ( V_2 , V_68 ,
V_69 |
V_70 ,
V_71 |
V_70 ) ;
break;
case V_72 :
if ( F_17 ( V_2 ) == V_73 ) {
F_5 ( V_2 , V_68 ,
V_69 |
V_70 ,
V_74 |
V_70 ) ;
F_18 ( 100 ) ;
}
F_15 ( V_2 , V_75 ,
V_76 |
V_77 ) ;
F_5 ( V_2 , V_68 ,
V_69 |
V_70 ,
V_78 |
V_70 ) ;
break;
case V_73 :
F_5 ( V_2 , V_68 ,
V_69 |
V_70 ,
0 ) ;
break;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_18 ;
V_4 = F_2 ( V_2 ) ;
F_20 ( V_4 -> V_36 ) ;
V_18 = F_21 ( F_3 ( V_4 -> V_79 ) ,
V_4 -> V_79 ) ;
if ( V_18 ) {
F_12 ( V_2 -> V_11 , L_3 ) ;
return V_18 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_80 * V_80 = F_23 ( V_2 -> V_11 , NULL ) ;
struct V_3 * V_4 ;
int V_18 ;
V_4 = F_2 ( V_2 ) ;
V_18 = F_24 ( V_4 -> V_36 ) ;
if ( V_18 ) {
F_12 ( V_2 -> V_11 , L_4 ) ;
return V_18 ;
}
V_18 = F_25 ( F_3 ( V_4 -> V_79 ) ,
V_4 -> V_79 ) ;
if ( V_18 ) {
F_12 ( V_2 -> V_11 , L_5 ) ;
return V_18 ;
}
F_26 ( V_80 ) ;
V_18 = F_27 ( V_80 ) ;
if ( V_18 ) {
F_12 ( V_2 -> V_11 , L_6 ) ;
return V_18 ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_18 ;
V_4 = F_2 ( V_2 ) ;
V_18 = F_25 ( F_3 ( V_4 -> V_79 ) ,
V_4 -> V_79 ) ;
if ( V_18 ) {
F_12 ( V_2 -> V_11 , L_5 ) ;
return V_18 ;
}
V_4 -> V_36 = F_29 ( V_2 -> V_11 , NULL ) ;
if ( F_30 ( V_4 -> V_36 ) ) {
F_12 ( V_2 -> V_11 , L_7 ) ;
V_18 = F_31 ( V_4 -> V_36 ) ;
goto V_81;
}
V_18 = F_24 ( V_4 -> V_36 ) ;
if ( V_18 ) {
F_12 ( V_2 -> V_11 , L_8 ) ;
goto V_81;
}
return 0 ;
V_81:
F_21 ( F_3 ( V_4 -> V_79 ) ,
V_4 -> V_79 ) ;
return V_18 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_36 )
F_20 ( V_4 -> V_36 ) ;
F_21 ( F_3 ( V_4 -> V_79 ) ,
V_4 -> V_79 ) ;
return 0 ;
}
int F_33 ( struct V_82 * V_11 , struct V_80 * V_80 )
{
struct V_3 * V_4 ;
int V_18 ;
int V_6 ;
if ( F_30 ( V_80 ) )
return F_31 ( V_80 ) ;
V_4 = F_34 ( V_11 , sizeof( * V_4 ) , V_83 ) ;
if ( V_4 == NULL )
return - V_84 ;
V_4 -> V_80 = V_80 ;
for ( V_6 = 0 ; V_6 < F_3 ( V_4 -> V_79 ) ; V_6 ++ )
V_4 -> V_79 [ V_6 ] . V_85 = V_86 [ V_6 ] ;
V_18 = F_35 ( V_11 , F_3 ( V_4 -> V_79 ) ,
V_4 -> V_79 ) ;
if ( V_18 ) {
F_12 ( V_11 , L_9 ) ;
return V_18 ;
}
F_36 ( V_11 , V_4 ) ;
return F_37 ( V_11 ,
& V_87 , & V_88 , 1 ) ;
}
