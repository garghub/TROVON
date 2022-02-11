static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_21 :
return true ;
default:
return false ;
}
}
static int F_3 ( int V_22 , int V_23 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < F_4 ( V_25 ) ; V_24 ++ ) {
if ( V_25 [ V_24 ] . V_23 == V_23 &&
V_25 [ V_24 ] . V_22 == V_22 )
return V_24 ;
}
return - V_26 ;
}
static int F_5 ( struct V_27 * V_28 , int V_29 ,
unsigned int V_30 , int V_31 )
{
struct V_32 * V_33 = V_28 -> V_33 ;
struct V_34 * V_35 = F_6 ( V_33 ) ;
int V_24 ;
if ( V_29 != 0 ) {
F_7 ( V_33 -> V_2 , L_1 , V_29 ) ;
return - V_26 ;
}
for ( V_24 = 0 ; V_24 < F_4 ( V_25 ) ; V_24 ++ ) {
if ( V_25 [ V_24 ] . V_22 == V_30 ) {
V_35 -> V_36 = V_30 ;
return 0 ;
}
}
V_35 -> V_36 = 0 ;
F_7 ( V_33 -> V_2 , L_2 , V_30 ) ;
return - V_26 ;
}
static int F_8 ( struct V_27 * V_28 , unsigned int V_37 )
{
struct V_32 * V_33 = V_28 -> V_33 ;
struct V_34 * V_35 = F_6 ( V_33 ) ;
T_1 V_38 = 0 ;
switch ( V_37 & V_39 ) {
case V_40 :
F_9 ( V_33 , V_6 ,
V_41 ,
V_41 ) ;
break;
case V_42 :
F_9 ( V_33 , V_6 ,
V_41 ,
0 ) ;
break;
default:
return - V_26 ;
}
switch ( V_37 & V_43 ) {
case V_44 :
V_38 |= V_44 ;
break;
case V_45 :
V_38 |= V_45 ;
break;
case V_46 :
V_38 |= V_46 ;
break;
default:
return - V_26 ;
}
V_35 -> V_47 = V_38 ;
return 0 ;
}
static int F_10 ( struct V_27 * V_48 , int V_49 )
{
struct V_32 * V_33 = V_48 -> V_33 ;
if ( V_49 ) {
F_9 ( V_33 , V_5 ,
V_50 ,
V_50 ) ;
F_9 ( V_33 , V_16 ,
V_51 ,
V_51 ) ;
} else {
F_9 ( V_33 , V_5 ,
V_50 ,
0 ) ;
F_9 ( V_33 , V_16 ,
V_51 ,
0 ) ;
}
return 0 ;
}
static int F_11 ( struct V_52 * V_53 ,
struct V_54 * V_55 ,
struct V_27 * V_48 )
{
struct V_32 * V_33 = V_48 -> V_33 ;
struct V_34 * V_35 = F_6 ( V_33 ) ;
int V_56 ;
if ( V_53 -> V_57 == V_58 &&
( ( V_35 -> V_47 & V_43 )
== V_45 ) )
return - V_26 ;
V_56 = F_3 ( V_35 -> V_36 , F_12 ( V_55 ) ) ;
if ( V_56 >= 0 ) {
F_9 ( V_33 , V_6 ,
V_59 , V_25 [ V_56 ] . V_60 << 6 ) ;
F_9 ( V_33 , V_7 ,
V_61 ,
V_25 [ V_56 ] . V_62 << 4 ) ;
} else {
F_7 ( V_33 -> V_2 , L_3 ) ;
return - V_26 ;
}
switch ( V_35 -> V_47 & V_43 ) {
case V_44 :
F_9 ( V_33 , V_5 ,
V_63 , ( 1 << 4 ) ) ;
F_9 ( V_33 , V_6 ,
V_64 , ( 1 << 4 ) ) ;
F_9 ( V_33 , V_16 ,
V_65 , ( 1 << 6 ) ) ;
break;
case V_45 :
if ( F_13 ( V_55 ) == 16 ) {
F_9 ( V_33 , V_5 ,
V_63 , ( 2 << 4 ) ) ;
F_9 ( V_33 , V_16 ,
V_65 , ( 2 << 6 ) ) ;
} else {
F_9 ( V_33 , V_5 ,
V_63 , ( 3 << 4 ) ) ;
F_9 ( V_33 , V_16 ,
V_65 , ( 3 << 6 ) ) ;
}
break;
case V_46 :
F_9 ( V_33 , V_5 ,
V_63 , 0 ) ;
F_9 ( V_33 , V_6 ,
V_64 , 0 ) ;
F_9 ( V_33 , V_16 ,
V_65 , 0 ) ;
break;
default:
return - V_26 ;
}
return 0 ;
}
static int F_14 ( struct V_32 * V_33 ,
enum V_66 V_67 )
{
switch ( V_67 ) {
case V_68 :
break;
case V_69 :
F_9 ( V_33 , V_4 ,
V_70 , 0 ) ;
break;
case V_71 :
F_9 ( V_33 , V_4 ,
V_70 ,
V_70 ) ;
break;
case V_72 :
F_9 ( V_33 , V_4 ,
V_70 ,
V_70 ) ;
break;
}
return 0 ;
}
static int F_15 ( struct V_73 * V_73 ,
const struct V_74 * V_75 )
{
struct V_34 * V_35 ;
int V_76 = 0 ;
unsigned int V_77 = 0 ;
unsigned int V_3 ;
V_35 = F_16 ( & V_73 -> V_2 , sizeof( struct V_34 ) ,
V_78 ) ;
if ( V_35 == NULL )
return - V_79 ;
V_35 -> V_80 = F_17 ( V_73 , & V_81 ) ;
if ( F_18 ( V_35 -> V_80 ) ) {
V_76 = F_19 ( V_35 -> V_80 ) ;
F_7 ( & V_73 -> V_2 , L_4 , V_76 ) ;
return V_76 ;
}
V_35 -> V_82 = F_20 ( & V_73 -> V_2 ,
L_5 , V_83 ) ;
if ( F_18 ( V_35 -> V_82 ) )
return F_19 ( V_35 -> V_82 ) ;
if ( V_35 -> V_82 ) {
F_21 ( 1 ) ;
F_22 ( V_35 -> V_82 , 1 ) ;
}
F_23 ( V_73 , V_35 ) ;
V_76 = F_24 ( V_35 -> V_80 , V_20 , & V_3 ) ;
V_77 = V_3 & V_84 ;
if ( V_77 != V_85 ) {
V_76 = - V_86 ;
F_7 ( & V_73 -> V_2 ,
L_6 ,
V_77 , V_20 ) ;
return V_76 ;
}
F_25 ( & V_73 -> V_2 ,
L_7 ,
V_3 & V_87 ) ;
F_26 ( V_35 -> V_80 , V_4 , 0x0F ) ;
V_76 = F_27 ( & V_73 -> V_2 ,
& V_88 , V_89 ,
F_4 ( V_89 ) ) ;
return V_76 ;
}
static int F_28 ( struct V_73 * V_90 )
{
F_29 ( & V_90 -> V_2 ) ;
return 0 ;
}
