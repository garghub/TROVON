static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 ... V_5 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_6 :
return true ;
default:
return false ;
}
}
static int F_3 ( int V_7 , int V_8 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < F_4 ( V_10 ) ; V_9 ++ ) {
if ( V_10 [ V_9 ] . V_8 == V_8 &&
V_10 [ V_9 ] . V_7 == V_7 )
return V_9 ;
}
return - V_11 ;
}
static int F_5 ( struct V_12 * V_13 , int V_14 ,
unsigned int V_15 , int V_16 )
{
struct V_17 * V_18 = V_13 -> V_18 ;
struct V_19 * V_20 = F_6 ( V_18 ) ;
int V_9 ;
if ( V_14 != 0 ) {
F_7 ( V_18 -> V_2 , L_1 , V_14 ) ;
return - V_11 ;
}
for ( V_9 = 0 ; V_9 < F_4 ( V_10 ) ; V_9 ++ ) {
if ( V_10 [ V_9 ] . V_7 == V_15 ) {
V_20 -> V_21 = V_15 ;
return 0 ;
}
}
V_20 -> V_21 = 0 ;
F_7 ( V_18 -> V_2 , L_2 , V_15 ) ;
return - V_11 ;
}
static int F_8 ( struct V_12 * V_13 , unsigned int V_22 )
{
struct V_17 * V_18 = V_13 -> V_18 ;
struct V_19 * V_20 = F_6 ( V_18 ) ;
T_1 V_23 = 0 ;
switch ( V_22 & V_24 ) {
case V_25 :
F_9 ( V_18 , V_26 ,
V_27 ,
V_27 ) ;
break;
case V_28 :
F_9 ( V_18 , V_26 ,
V_27 ,
0 ) ;
break;
default:
return - V_11 ;
}
switch ( V_22 & V_29 ) {
case V_30 :
V_23 |= V_30 ;
break;
case V_31 :
V_23 |= V_31 ;
break;
case V_32 :
V_23 |= V_32 ;
break;
default:
return - V_11 ;
}
V_20 -> V_33 = V_23 ;
return 0 ;
}
static int F_10 ( struct V_12 * V_34 , int V_35 )
{
struct V_17 * V_18 = V_34 -> V_18 ;
if ( V_35 ) {
F_9 ( V_18 , V_36 ,
V_37 ,
V_37 ) ;
F_9 ( V_18 , V_5 ,
V_38 ,
V_38 ) ;
} else {
F_9 ( V_18 , V_36 ,
V_37 ,
0 ) ;
F_9 ( V_18 , V_5 ,
V_38 ,
0 ) ;
}
return 0 ;
}
static int F_11 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
struct V_12 * V_34 )
{
struct V_17 * V_18 = V_34 -> V_18 ;
struct V_19 * V_20 = F_6 ( V_18 ) ;
int V_43 ;
if ( V_40 -> V_44 == V_45 &&
( ( V_20 -> V_33 & V_29 )
== V_31 ) )
return - V_11 ;
V_43 = F_3 ( V_20 -> V_21 , F_12 ( V_42 ) ) ;
if ( V_43 >= 0 ) {
F_9 ( V_18 , V_26 ,
V_46 , V_10 [ V_43 ] . V_47 << 6 ) ;
F_9 ( V_18 , V_48 ,
V_49 ,
V_10 [ V_43 ] . V_50 << 4 ) ;
} else {
F_7 ( V_18 -> V_2 , L_3 ) ;
return - V_11 ;
}
switch ( V_20 -> V_33 & V_29 ) {
case V_30 :
F_9 ( V_18 , V_36 ,
V_51 , ( 1 << 4 ) ) ;
F_9 ( V_18 , V_26 ,
V_52 , ( 1 << 4 ) ) ;
F_9 ( V_18 , V_5 ,
V_53 , ( 1 << 6 ) ) ;
break;
case V_31 :
if ( F_13 ( V_42 ) == 16 ) {
F_9 ( V_18 , V_36 ,
V_51 , ( 2 << 4 ) ) ;
F_9 ( V_18 , V_5 ,
V_53 , ( 2 << 6 ) ) ;
} else {
F_9 ( V_18 , V_36 ,
V_51 , ( 3 << 4 ) ) ;
F_9 ( V_18 , V_5 ,
V_53 , ( 3 << 6 ) ) ;
}
break;
case V_32 :
F_9 ( V_18 , V_36 ,
V_51 , 0 ) ;
F_9 ( V_18 , V_26 ,
V_52 , 0 ) ;
F_9 ( V_18 , V_5 ,
V_53 , 0 ) ;
break;
default:
return - V_11 ;
}
return 0 ;
}
static int F_14 ( struct V_17 * V_18 ,
enum V_54 V_55 )
{
switch ( V_55 ) {
case V_56 :
break;
case V_57 :
F_9 ( V_18 , V_58 ,
V_59 , 0 ) ;
break;
case V_60 :
F_9 ( V_18 , V_58 ,
V_59 ,
V_59 ) ;
break;
case V_61 :
F_9 ( V_18 , V_58 ,
V_59 ,
V_59 ) ;
break;
}
return 0 ;
}
static int F_15 ( struct V_62 * V_62 ,
const struct V_63 * V_64 )
{
struct V_19 * V_20 ;
int V_65 = 0 ;
unsigned int V_66 = 0 ;
unsigned int V_3 ;
V_20 = F_16 ( & V_62 -> V_2 , sizeof( struct V_19 ) ,
V_67 ) ;
if ( V_20 == NULL )
return - V_68 ;
V_20 -> V_69 = F_17 ( V_62 , & V_70 ) ;
if ( F_18 ( V_20 -> V_69 ) ) {
V_65 = F_19 ( V_20 -> V_69 ) ;
F_7 ( & V_62 -> V_2 , L_4 , V_65 ) ;
return V_65 ;
}
V_20 -> V_71 = F_20 ( & V_62 -> V_2 ,
L_5 , V_72 ) ;
if ( F_18 ( V_20 -> V_71 ) )
return F_19 ( V_20 -> V_71 ) ;
if ( V_20 -> V_71 ) {
F_21 ( 1 ) ;
F_22 ( V_20 -> V_71 , 1 ) ;
}
F_23 ( V_62 , V_20 ) ;
V_65 = F_24 ( V_20 -> V_69 , V_4 , & V_3 ) ;
V_66 = V_3 & V_73 ;
if ( V_66 != V_74 ) {
V_65 = - V_75 ;
F_7 ( & V_62 -> V_2 ,
L_6 ,
V_66 , V_4 ) ;
return V_65 ;
}
F_25 ( & V_62 -> V_2 ,
L_7 ,
V_3 & V_76 ) ;
F_26 ( V_20 -> V_69 , V_58 , 0x0F ) ;
V_65 = F_27 ( & V_62 -> V_2 ,
& V_77 , V_78 ,
F_4 ( V_78 ) ) ;
return V_65 ;
}
static int F_28 ( struct V_62 * V_79 )
{
F_29 ( & V_79 -> V_2 ) ;
return 0 ;
}
