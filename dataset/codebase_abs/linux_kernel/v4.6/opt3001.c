static int F_1 ( const struct V_1 * V_2 , int V_3 ,
int V_4 , T_1 * V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < F_2 ( V_7 ) ; V_6 ++ ) {
const struct V_8 * V_9 = & V_7 [ V_6 ] ;
if ( ( V_3 * 1000 + V_4 / 1000 ) <=
( V_9 -> V_3 * 1000 + V_9 -> V_4 / 1000 ) ) {
* V_5 = V_6 ;
return 0 ;
}
}
return - V_10 ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_5 ,
T_2 V_11 , int * V_3 , int * V_4 )
{
int V_12 ;
V_12 = 10 * ( V_11 << V_5 ) ;
* V_3 = V_12 / 1000 ;
* V_4 = ( V_12 - ( * V_3 * 1000 ) ) * 1000 ;
}
static void F_4 ( struct V_1 * V_2 , T_2 * V_13 , T_2 V_14 )
{
* V_13 &= ~ V_15 ;
* V_13 |= V_14 ;
V_2 -> V_14 = V_14 ;
}
static int F_5 ( struct V_1 * V_2 , int * V_3 , int * V_4 )
{
int V_16 ;
T_2 V_11 ;
T_2 V_13 ;
T_1 V_5 ;
T_2 V_17 ;
long V_18 ;
if ( V_2 -> V_19 ) {
V_16 = F_6 ( V_2 -> V_20 ,
V_21 ,
V_22 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_23 , L_1 ,
V_21 ) ;
return V_16 ;
}
V_2 -> V_24 = true ;
}
V_2 -> V_25 = false ;
V_16 = F_8 ( V_2 -> V_20 , V_26 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_23 , L_2 ,
V_26 ) ;
goto V_27;
}
V_13 = V_16 ;
F_4 ( V_2 , & V_13 , V_28 ) ;
V_16 = F_6 ( V_2 -> V_20 , V_26 ,
V_13 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_23 , L_1 ,
V_26 ) ;
goto V_27;
}
if ( V_2 -> V_19 ) {
V_16 = F_9 ( V_2 -> V_29 ,
V_2 -> V_25 ,
F_10 ( V_30 ) ) ;
} else {
V_18 = ( V_2 -> V_31 == V_32 ) ?
V_33 : V_30 ;
F_11 ( V_18 ) ;
V_16 = F_8 ( V_2 -> V_20 ,
V_26 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_23 , L_2 ,
V_26 ) ;
goto V_27;
}
if ( ! ( V_16 & V_34 ) ) {
V_16 = - V_35 ;
goto V_27;
}
V_16 = F_8 ( V_2 -> V_20 , V_36 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_23 , L_2 ,
V_36 ) ;
goto V_27;
}
V_2 -> V_37 = V_16 ;
V_2 -> V_25 = true ;
}
V_27:
if ( V_2 -> V_19 )
V_2 -> V_24 = false ;
if ( V_16 == 0 )
return - V_35 ;
else if ( V_16 < 0 )
return V_16 ;
if ( V_2 -> V_19 ) {
V_17 = ( V_2 -> V_38 << 12 ) | V_2 -> V_39 ;
V_16 = F_6 ( V_2 -> V_20 ,
V_21 ,
V_17 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_23 , L_1 ,
V_21 ) ;
return V_16 ;
}
}
V_5 = F_12 ( V_2 -> V_37 ) ;
V_11 = F_13 ( V_2 -> V_37 ) ;
F_3 ( V_2 , V_5 , V_11 , V_3 , V_4 ) ;
return V_40 ;
}
static int F_14 ( struct V_1 * V_2 , int * V_3 , int * V_4 )
{
* V_3 = 0 ;
* V_4 = V_2 -> V_31 ;
return V_40 ;
}
static int F_15 ( struct V_1 * V_2 , int time )
{
int V_16 ;
T_2 V_13 ;
V_16 = F_8 ( V_2 -> V_20 , V_26 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_23 , L_2 ,
V_26 ) ;
return V_16 ;
}
V_13 = V_16 ;
switch ( time ) {
case V_32 :
V_13 &= ~ V_41 ;
V_2 -> V_31 = V_32 ;
break;
case V_42 :
V_13 |= V_41 ;
V_2 -> V_31 = V_42 ;
break;
default:
return - V_10 ;
}
return F_6 ( V_2 -> V_20 , V_26 ,
V_13 ) ;
}
static int F_16 ( struct V_43 * V_44 ,
struct V_45 const * V_46 , int * V_3 , int * V_4 ,
long V_47 )
{
struct V_1 * V_2 = F_17 ( V_44 ) ;
int V_16 ;
if ( V_2 -> V_14 == V_48 )
return - V_49 ;
if ( V_46 -> type != V_50 )
return - V_10 ;
F_18 ( & V_2 -> V_51 ) ;
switch ( V_47 ) {
case V_52 :
V_16 = F_5 ( V_2 , V_3 , V_4 ) ;
break;
case V_53 :
V_16 = F_14 ( V_2 , V_3 , V_4 ) ;
break;
default:
V_16 = - V_10 ;
}
F_19 ( & V_2 -> V_51 ) ;
return V_16 ;
}
static int F_20 ( struct V_43 * V_44 ,
struct V_45 const * V_46 , int V_3 , int V_4 ,
long V_47 )
{
struct V_1 * V_2 = F_17 ( V_44 ) ;
int V_16 ;
if ( V_2 -> V_14 == V_48 )
return - V_49 ;
if ( V_46 -> type != V_50 )
return - V_10 ;
if ( V_47 != V_53 )
return - V_10 ;
if ( V_3 != 0 )
return - V_10 ;
F_18 ( & V_2 -> V_51 ) ;
V_16 = F_15 ( V_2 , V_4 ) ;
F_19 ( & V_2 -> V_51 ) ;
return V_16 ;
}
static int F_21 ( struct V_43 * V_44 ,
const struct V_45 * V_46 , enum V_54 type ,
enum V_55 V_56 , enum V_57 V_58 ,
int * V_3 , int * V_4 )
{
struct V_1 * V_2 = F_17 ( V_44 ) ;
int V_16 = V_40 ;
F_18 ( & V_2 -> V_51 ) ;
switch ( V_56 ) {
case V_59 :
F_3 ( V_2 , V_2 -> V_60 ,
V_2 -> V_61 , V_3 , V_4 ) ;
break;
case V_62 :
F_3 ( V_2 , V_2 -> V_38 ,
V_2 -> V_39 , V_3 , V_4 ) ;
break;
default:
V_16 = - V_10 ;
}
F_19 ( & V_2 -> V_51 ) ;
return V_16 ;
}
static int F_22 ( struct V_43 * V_44 ,
const struct V_45 * V_46 , enum V_54 type ,
enum V_55 V_56 , enum V_57 V_58 ,
int V_3 , int V_4 )
{
struct V_1 * V_2 = F_17 ( V_44 ) ;
int V_16 ;
T_2 V_11 ;
T_2 V_17 ;
T_2 V_13 ;
T_1 V_5 ;
if ( V_3 < 0 )
return - V_10 ;
F_18 ( & V_2 -> V_51 ) ;
V_16 = F_1 ( V_2 , V_3 , V_4 , & V_5 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_23 , L_3 , V_3 , V_4 ) ;
goto V_27;
}
V_11 = ( ( ( V_3 * 1000 ) + ( V_4 / 1000 ) ) / 10 ) >> V_5 ;
V_17 = ( V_5 << 12 ) | V_11 ;
switch ( V_56 ) {
case V_59 :
V_13 = V_63 ;
V_2 -> V_61 = V_11 ;
V_2 -> V_60 = V_5 ;
break;
case V_62 :
V_13 = V_21 ;
V_2 -> V_39 = V_11 ;
V_2 -> V_38 = V_5 ;
break;
default:
V_16 = - V_10 ;
goto V_27;
}
V_16 = F_6 ( V_2 -> V_20 , V_13 , V_17 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_23 , L_1 , V_13 ) ;
goto V_27;
}
V_27:
F_19 ( & V_2 -> V_51 ) ;
return V_16 ;
}
static int F_23 ( struct V_43 * V_44 ,
const struct V_45 * V_46 , enum V_54 type ,
enum V_55 V_56 )
{
struct V_1 * V_2 = F_17 ( V_44 ) ;
return V_2 -> V_14 == V_48 ;
}
static int F_24 ( struct V_43 * V_44 ,
const struct V_45 * V_46 , enum V_54 type ,
enum V_55 V_56 , int V_64 )
{
struct V_1 * V_2 = F_17 ( V_44 ) ;
int V_16 ;
T_2 V_14 ;
T_2 V_13 ;
if ( V_64 && V_2 -> V_14 == V_48 )
return 0 ;
if ( ! V_64 && V_2 -> V_14 == V_65 )
return 0 ;
F_18 ( & V_2 -> V_51 ) ;
V_14 = V_64 ? V_48
: V_65 ;
V_16 = F_8 ( V_2 -> V_20 , V_26 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_23 , L_2 ,
V_26 ) ;
goto V_27;
}
V_13 = V_16 ;
F_4 ( V_2 , & V_13 , V_14 ) ;
V_16 = F_6 ( V_2 -> V_20 , V_26 ,
V_13 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_23 , L_1 ,
V_26 ) ;
goto V_27;
}
V_27:
F_19 ( & V_2 -> V_51 ) ;
return V_16 ;
}
static int F_25 ( struct V_1 * V_2 )
{
char V_66 [ 2 ] ;
T_2 V_67 ;
int V_16 ;
V_16 = F_8 ( V_2 -> V_20 , V_68 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_23 , L_2 ,
V_68 ) ;
return V_16 ;
}
V_66 [ 0 ] = V_16 >> 8 ;
V_66 [ 1 ] = V_16 & 0xff ;
V_16 = F_8 ( V_2 -> V_20 , V_69 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_23 , L_2 ,
V_69 ) ;
return V_16 ;
}
V_67 = V_16 ;
F_26 ( V_2 -> V_23 , L_4 , V_66 [ 0 ] ,
V_66 [ 1 ] , V_67 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_16 ;
T_2 V_13 ;
V_16 = F_8 ( V_2 -> V_20 , V_26 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_23 , L_2 ,
V_26 ) ;
return V_16 ;
}
V_13 = V_16 ;
V_13 &= ~ V_70 ;
V_13 |= V_71 ;
if ( V_13 & V_41 )
V_2 -> V_31 = V_42 ;
else
V_2 -> V_31 = V_32 ;
F_4 ( V_2 , & V_13 , V_65 ) ;
V_13 |= V_72 ;
V_13 &= ~ V_73 ;
V_13 &= ~ V_74 ;
V_13 &= ~ V_75 ;
V_16 = F_6 ( V_2 -> V_20 , V_26 ,
V_13 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_23 , L_1 ,
V_26 ) ;
return V_16 ;
}
V_16 = F_8 ( V_2 -> V_20 , V_21 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_23 , L_2 ,
V_21 ) ;
return V_16 ;
}
V_2 -> V_39 = F_13 ( V_16 ) ;
V_2 -> V_38 = F_12 ( V_16 ) ;
V_16 = F_8 ( V_2 -> V_20 , V_63 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_23 , L_2 ,
V_63 ) ;
return V_16 ;
}
V_2 -> V_61 = F_13 ( V_16 ) ;
V_2 -> V_60 = F_12 ( V_16 ) ;
return 0 ;
}
static T_3 F_28 ( int V_76 , void * V_77 )
{
struct V_43 * V_44 = V_77 ;
struct V_1 * V_2 = F_17 ( V_44 ) ;
int V_16 ;
if ( ! V_2 -> V_24 )
F_18 ( & V_2 -> V_51 ) ;
V_16 = F_8 ( V_2 -> V_20 , V_26 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_23 , L_2 ,
V_26 ) ;
goto V_78;
}
if ( ( V_16 & V_15 ) ==
V_48 ) {
if ( V_16 & V_79 )
F_29 ( V_44 ,
F_30 ( V_50 , 0 ,
V_80 ,
V_59 ) ,
F_31 () ) ;
if ( V_16 & V_81 )
F_29 ( V_44 ,
F_30 ( V_50 , 0 ,
V_80 ,
V_62 ) ,
F_31 () ) ;
} else if ( V_16 & V_34 ) {
V_16 = F_8 ( V_2 -> V_20 , V_36 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_23 , L_2 ,
V_36 ) ;
goto V_78;
}
V_2 -> V_37 = V_16 ;
V_2 -> V_25 = true ;
F_32 ( & V_2 -> V_29 ) ;
}
V_78:
if ( ! V_2 -> V_24 )
F_19 ( & V_2 -> V_51 ) ;
return V_82 ;
}
static int F_33 ( struct V_83 * V_20 ,
const struct V_84 * V_85 )
{
struct V_86 * V_23 = & V_20 -> V_23 ;
struct V_43 * V_44 ;
struct V_1 * V_2 ;
int V_76 = V_20 -> V_76 ;
int V_16 ;
V_44 = F_34 ( V_23 , sizeof( * V_2 ) ) ;
if ( ! V_44 )
return - V_87 ;
V_2 = F_17 ( V_44 ) ;
V_2 -> V_20 = V_20 ;
V_2 -> V_23 = V_23 ;
F_35 ( & V_2 -> V_51 ) ;
F_36 ( & V_2 -> V_29 ) ;
F_37 ( V_20 , V_44 ) ;
V_16 = F_25 ( V_2 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_27 ( V_2 ) ;
if ( V_16 )
return V_16 ;
V_44 -> V_88 = V_20 -> V_88 ;
V_44 -> V_89 = V_90 ;
V_44 -> V_91 = F_2 ( V_90 ) ;
V_44 -> V_23 . V_92 = V_23 ;
V_44 -> V_93 = V_94 ;
V_44 -> V_58 = & V_95 ;
V_16 = F_38 ( V_23 , V_44 ) ;
if ( V_16 ) {
F_7 ( V_23 , L_5 ) ;
return V_16 ;
}
if ( V_76 > 0 ) {
V_16 = F_39 ( V_76 , NULL , F_28 ,
V_96 | V_97 ,
L_6 , V_44 ) ;
if ( V_16 ) {
F_7 ( V_23 , L_7 , V_76 ) ;
return V_16 ;
}
V_2 -> V_19 = true ;
} else {
F_40 ( V_2 -> V_23 , L_8 ) ;
}
return 0 ;
}
static int F_41 ( struct V_83 * V_20 )
{
struct V_43 * V_44 = F_42 ( V_20 ) ;
struct V_1 * V_2 = F_17 ( V_44 ) ;
int V_16 ;
T_2 V_13 ;
if ( V_2 -> V_19 )
F_43 ( V_20 -> V_76 , V_44 ) ;
V_16 = F_8 ( V_2 -> V_20 , V_26 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_23 , L_2 ,
V_26 ) ;
return V_16 ;
}
V_13 = V_16 ;
F_4 ( V_2 , & V_13 , V_65 ) ;
V_16 = F_6 ( V_2 -> V_20 , V_26 ,
V_13 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_23 , L_1 ,
V_26 ) ;
return V_16 ;
}
return 0 ;
}
