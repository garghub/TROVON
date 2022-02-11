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
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_20 :
return true ;
default:
return false ;
}
}
static int F_3 ( int V_21 , int V_22 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < F_4 ( V_24 ) ; V_23 ++ ) {
if ( V_24 [ V_23 ] . V_22 == V_22 &&
V_24 [ V_23 ] . V_21 == V_21 )
return V_23 ;
}
return - V_25 ;
}
static int F_5 ( struct V_26 * V_27 , int V_28 ,
unsigned int V_29 , int V_30 )
{
struct V_31 * V_32 = V_27 -> V_32 ;
struct V_33 * V_34 = F_6 ( V_32 ) ;
int V_23 ;
if ( V_28 != 0 ) {
F_7 ( V_32 -> V_2 , L_1 , V_28 ) ;
return - V_25 ;
}
for ( V_23 = 0 ; V_23 < F_4 ( V_24 ) ; V_23 ++ ) {
if ( V_24 [ V_23 ] . V_21 == V_29 ) {
V_34 -> V_35 = V_29 ;
return 0 ;
}
}
V_34 -> V_35 = 0 ;
F_7 ( V_32 -> V_2 , L_2 , V_29 ) ;
return - V_25 ;
}
static int F_8 ( struct V_26 * V_27 , unsigned int V_36 )
{
struct V_31 * V_32 = V_27 -> V_32 ;
struct V_33 * V_34 = F_6 ( V_32 ) ;
T_1 V_37 = 0 ;
switch ( V_36 & V_38 ) {
case V_39 :
F_9 ( V_32 , V_6 ,
V_40 ,
V_40 ) ;
break;
case V_41 :
F_9 ( V_32 , V_6 ,
V_40 ,
0 ) ;
break;
default:
return - V_25 ;
}
switch ( V_36 & V_42 ) {
case V_43 :
V_37 |= V_43 ;
break;
case V_44 :
V_37 |= V_44 ;
break;
case V_45 :
V_37 |= V_45 ;
break;
default:
return - V_25 ;
}
V_34 -> V_46 = V_37 ;
return 0 ;
}
static int F_10 ( struct V_26 * V_47 , int V_48 )
{
struct V_31 * V_32 = V_47 -> V_32 ;
if ( V_48 ) {
F_9 ( V_32 , V_5 ,
V_49 ,
V_49 ) ;
F_9 ( V_32 , V_16 ,
V_50 ,
V_50 ) ;
} else {
F_9 ( V_32 , V_5 ,
V_49 ,
0 ) ;
F_9 ( V_32 , V_16 ,
V_50 ,
0 ) ;
}
return 0 ;
}
static int F_11 ( struct V_51 * V_52 ,
struct V_53 * V_54 ,
struct V_26 * V_47 )
{
struct V_31 * V_32 = V_47 -> V_32 ;
struct V_33 * V_34 = F_6 ( V_32 ) ;
int V_55 ;
if ( V_52 -> V_56 == V_57 &&
( ( V_34 -> V_46 & V_42 )
== V_44 ) )
return - V_25 ;
V_55 = F_3 ( V_34 -> V_35 , F_12 ( V_54 ) ) ;
if ( V_55 >= 0 ) {
F_9 ( V_32 , V_6 ,
V_58 , V_24 [ V_55 ] . V_59 << 6 ) ;
F_9 ( V_32 , V_7 ,
V_60 ,
V_24 [ V_55 ] . V_61 << 4 ) ;
} else {
F_7 ( V_32 -> V_2 , L_3 ) ;
return - V_25 ;
}
switch ( V_34 -> V_46 & V_42 ) {
case V_43 :
F_9 ( V_32 , V_5 ,
V_62 , ( 1 << 4 ) ) ;
F_9 ( V_32 , V_6 ,
V_63 , ( 1 << 4 ) ) ;
F_9 ( V_32 , V_16 ,
V_64 , ( 1 << 6 ) ) ;
break;
case V_44 :
if ( F_13 ( V_54 ) == 16 ) {
F_9 ( V_32 , V_5 ,
V_62 , ( 1 << 5 ) ) ;
F_9 ( V_32 , V_16 ,
V_64 , ( 1 << 7 ) ) ;
} else {
F_9 ( V_32 , V_5 ,
V_62 , ( 3 << 5 ) ) ;
F_9 ( V_32 , V_16 ,
V_64 , ( 1 << 7 ) ) ;
}
break;
case V_45 :
F_9 ( V_32 , V_5 ,
V_62 , 0 ) ;
F_9 ( V_32 , V_6 ,
V_63 , 0 ) ;
F_9 ( V_32 , V_16 ,
V_64 , ( 1 << 6 ) ) ;
break;
default:
return - V_25 ;
}
return 0 ;
}
static int F_14 ( struct V_31 * V_32 ,
enum V_65 V_66 )
{
switch ( V_66 ) {
case V_67 :
break;
case V_68 :
F_9 ( V_32 , V_4 ,
V_69 , 0 ) ;
break;
case V_70 :
F_9 ( V_32 , V_4 ,
V_69 ,
V_69 ) ;
break;
case V_71 :
F_9 ( V_32 , V_4 ,
V_69 ,
V_69 ) ;
break;
}
V_32 -> V_72 . V_73 = V_66 ;
return 0 ;
}
static int F_15 ( struct V_74 * V_74 ,
const struct V_75 * V_76 )
{
struct V_33 * V_34 ;
int V_77 = 0 ;
unsigned int V_78 = 0 ;
unsigned int V_3 ;
V_34 = F_16 ( & V_74 -> V_2 , sizeof( struct V_33 ) ,
V_79 ) ;
if ( V_34 == NULL )
return - V_80 ;
V_34 -> V_2 = & V_74 -> V_2 ;
V_34 -> V_81 = F_17 ( V_74 , & V_82 ) ;
if ( F_18 ( V_34 -> V_81 ) ) {
V_77 = F_19 ( V_34 -> V_81 ) ;
F_7 ( & V_74 -> V_2 , L_4 , V_77 ) ;
return V_77 ;
}
V_34 -> V_83 = F_20 ( & V_74 -> V_2 ,
L_5 ) ;
if ( F_18 ( V_34 -> V_83 ) ) {
V_77 = F_19 ( V_34 -> V_83 ) ;
if ( V_77 != - V_84 && V_77 != - V_85 )
return V_77 ;
V_34 -> V_83 = NULL ;
} else {
V_77 = F_21 ( V_34 -> V_83 , 0 ) ;
if ( V_77 )
return V_77 ;
F_22 ( 1 ) ;
F_23 ( V_34 -> V_83 , 1 ) ;
}
F_24 ( V_74 , V_34 ) ;
V_77 = F_25 ( V_34 -> V_81 , V_86 , & V_3 ) ;
V_78 = V_3 & V_87 ;
if ( V_78 != V_88 ) {
V_77 = - V_89 ;
F_7 ( & V_74 -> V_2 ,
L_6 ,
V_78 , V_86 ) ;
return V_77 ;
}
F_26 ( & V_74 -> V_2 ,
L_7 ,
V_3 & V_90 ) ;
F_27 ( V_34 -> V_81 , V_4 , 0x0F ) ;
V_77 = F_28 ( & V_74 -> V_2 ,
& V_91 , V_92 ,
F_4 ( V_92 ) ) ;
return V_77 ;
}
static int F_29 ( struct V_74 * V_93 )
{
F_30 ( & V_93 -> V_2 ) ;
return 0 ;
}
