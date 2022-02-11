static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 -> V_5 ) ;
return V_6 ;
}
static int F_3 ( struct V_7 * V_8 ,
enum V_9 V_10 , union V_11 * V_12 )
{
struct V_3 * V_4 = F_4 ( V_8 ) ;
unsigned int V_13 , V_14 ;
int V_15 ;
switch ( V_10 ) {
case V_16 :
V_15 = F_5 ( V_4 -> V_17 , V_18 , & V_14 ) ;
if ( V_15 )
return V_15 ;
V_12 -> V_19 = F_6 ( V_14 ) ;
return 0 ;
case V_20 :
if ( F_7 ( V_21 ) ) {
V_15 = F_8 ( V_4 -> V_22 ,
& V_12 -> V_19 ) ;
if ( V_15 )
return V_15 ;
V_12 -> V_19 *= 1000 ;
return 0 ;
}
V_15 = F_9 ( V_4 -> V_17 ,
V_23 , 12 ) ;
if ( V_15 < 0 )
return V_15 ;
V_12 -> V_19 = V_15 * 1700 ;
return 0 ;
case V_24 :
V_15 = F_5 ( V_4 -> V_17 , V_18 , & V_14 ) ;
if ( V_15 )
return V_15 ;
switch ( V_14 & V_25 ) {
case V_26 :
if ( V_4 -> V_27 == V_28 )
V_12 -> V_19 = - 1 ;
else
V_12 -> V_19 = 100000 ;
break;
case V_29 :
V_12 -> V_19 = 500000 ;
break;
case V_30 :
V_12 -> V_19 = 900000 ;
break;
case V_31 :
V_12 -> V_19 = - 1 ;
break;
}
return 0 ;
case V_32 :
if ( F_7 ( V_21 ) ) {
V_15 = F_8 ( V_4 -> V_33 ,
& V_12 -> V_19 ) ;
if ( V_15 )
return V_15 ;
V_12 -> V_19 *= 1000 ;
return 0 ;
}
V_15 = F_9 ( V_4 -> V_17 ,
V_34 , 12 ) ;
if ( V_15 < 0 )
return V_15 ;
V_12 -> V_19 = V_15 * 375 ;
return 0 ;
default:
break;
}
V_15 = F_5 ( V_4 -> V_17 , V_35 , & V_13 ) ;
if ( V_15 )
return V_15 ;
switch ( V_10 ) {
case V_36 :
if ( ! ( V_13 & V_37 ) ) {
V_12 -> V_19 = V_38 ;
break;
}
V_12 -> V_19 = V_39 ;
if ( V_4 -> V_27 == V_40 ) {
V_15 = F_5 ( V_4 -> V_17 ,
V_41 , & V_14 ) ;
if ( V_15 )
return V_15 ;
if ( ! ( V_14 & V_42 ) )
V_12 -> V_19 =
V_43 ;
}
break;
case V_44 :
V_12 -> V_19 = ! ! ( V_13 & V_37 ) ;
break;
case V_45 :
V_12 -> V_19 = ! ! ( V_13 & V_46 ) ;
break;
default:
return - V_47 ;
}
return 0 ;
}
static int F_10 ( struct V_3 * V_4 ,
int V_19 )
{
int V_12 ;
switch ( V_19 ) {
case 4000000 :
case 4100000 :
case 4200000 :
case 4300000 :
case 4400000 :
case 4500000 :
case 4600000 :
case 4700000 :
V_12 = ( V_19 - 4000000 ) / 100000 ;
return F_11 ( V_4 -> V_17 ,
V_18 ,
V_48 ,
V_12 << V_49 ) ;
default:
return - V_47 ;
}
return - V_47 ;
}
static int F_12 ( struct V_3 * V_4 ,
int V_19 )
{
int V_12 ;
switch ( V_19 ) {
case 100000 :
if ( V_4 -> V_27 == V_28 )
return - V_47 ;
case 500000 :
case 900000 :
V_12 = ( 900000 - V_19 ) / 400000 ;
return F_11 ( V_4 -> V_17 ,
V_18 ,
V_25 , V_12 ) ;
default:
return - V_47 ;
}
return - V_47 ;
}
static int F_13 ( struct V_7 * V_8 ,
enum V_9 V_10 ,
const union V_11 * V_12 )
{
struct V_3 * V_4 = F_4 ( V_8 ) ;
switch ( V_10 ) {
case V_16 :
return F_10 ( V_4 , V_12 -> V_19 ) ;
case V_24 :
return F_12 ( V_4 , V_12 -> V_19 ) ;
default:
return - V_47 ;
}
return - V_47 ;
}
static int F_14 ( struct V_7 * V_8 ,
enum V_9 V_10 )
{
return V_10 == V_16 ||
V_10 == V_24 ;
}
static int F_15 ( struct V_50 * V_51 ,
struct V_3 * V_4 )
{
V_4 -> V_22 = F_16 ( & V_51 -> V_52 , L_1 ) ;
if ( F_17 ( V_4 -> V_22 ) ) {
if ( F_18 ( V_4 -> V_22 ) == - V_53 )
return - V_54 ;
return F_18 ( V_4 -> V_22 ) ;
}
V_4 -> V_33 = F_16 ( & V_51 -> V_52 , L_2 ) ;
if ( F_17 ( V_4 -> V_33 ) ) {
if ( F_18 ( V_4 -> V_33 ) == - V_53 )
return - V_54 ;
return F_18 ( V_4 -> V_33 ) ;
}
return 0 ;
}
static int F_19 ( struct V_3 * V_4 )
{
return F_11 ( V_4 -> V_17 , V_55 ,
V_56 |
V_57 ,
V_56 |
V_57 ) ;
}
static int F_20 ( struct V_50 * V_51 )
{
struct V_58 * V_59 = F_21 ( V_51 -> V_52 . V_60 ) ;
struct V_61 V_62 = {} ;
struct V_3 * V_4 ;
static const char * const V_63 [] = { L_3 ,
L_4 , L_5 , L_6 , NULL } ;
static const char * const V_64 [] = {
L_3 , L_4 , NULL } ;
static const char * const * V_65 ;
const struct V_66 * V_67 ;
int V_68 , V_1 , V_15 ;
if ( ! F_22 ( V_51 -> V_52 . V_69 ) )
return - V_53 ;
if ( ! V_59 ) {
F_23 ( & V_51 -> V_52 , L_7 ) ;
return - V_47 ;
}
V_4 = F_24 ( & V_51 -> V_52 , sizeof( * V_4 ) , V_70 ) ;
if ( ! V_4 )
return - V_71 ;
V_4 -> V_27 = (enum V_72 ) F_25 (
& V_51 -> V_52 ) ;
V_4 -> V_73 = V_51 -> V_52 . V_69 ;
V_4 -> V_17 = V_59 -> V_17 ;
if ( V_4 -> V_27 == V_40 ) {
V_15 = F_11 ( V_4 -> V_17 , V_74 ,
V_75 ,
V_75 ) ;
if ( V_15 )
return V_15 ;
if ( F_7 ( V_21 ) )
V_15 = F_15 ( V_51 , V_4 ) ;
else
V_15 = F_19 ( V_4 ) ;
if ( V_15 )
return V_15 ;
V_67 = & V_76 ;
V_65 = V_63 ;
} else if ( V_4 -> V_27 == V_28 ||
V_4 -> V_27 == V_77 ) {
V_67 = & V_78 ;
V_65 = V_64 ;
} else {
F_23 ( & V_51 -> V_52 , L_8 ,
V_59 -> V_79 ) ;
return - V_47 ;
}
V_62 . V_69 = V_51 -> V_52 . V_69 ;
V_62 . V_80 = V_4 ;
V_4 -> V_5 = F_26 ( & V_51 -> V_52 , V_67 ,
& V_62 ) ;
if ( F_17 ( V_4 -> V_5 ) )
return F_18 ( V_4 -> V_5 ) ;
for ( V_68 = 0 ; V_65 [ V_68 ] ; V_68 ++ ) {
V_1 = F_27 ( V_51 , V_65 [ V_68 ] ) ;
if ( V_1 < 0 ) {
F_28 ( & V_51 -> V_52 , L_9 ,
V_65 [ V_68 ] , V_1 ) ;
continue;
}
V_1 = F_29 ( V_59 -> V_81 , V_1 ) ;
V_15 = F_30 ( & V_51 -> V_52 , V_1 ,
F_1 , 0 , V_82 , V_4 ) ;
if ( V_15 < 0 )
F_28 ( & V_51 -> V_52 , L_10 ,
V_65 [ V_68 ] , V_15 ) ;
}
return 0 ;
}
