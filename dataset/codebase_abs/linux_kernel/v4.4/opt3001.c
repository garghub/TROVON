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
V_16 = F_6 ( V_2 -> V_18 , V_19 ,
V_20 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_21 , L_1 ,
V_19 ) ;
return V_16 ;
}
V_2 -> V_22 = false ;
V_2 -> V_23 = true ;
V_16 = F_8 ( V_2 -> V_18 , V_24 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_21 , L_2 ,
V_24 ) ;
goto V_25;
}
V_13 = V_16 ;
F_4 ( V_2 , & V_13 , V_26 ) ;
V_16 = F_6 ( V_2 -> V_18 , V_24 ,
V_13 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_21 , L_1 ,
V_24 ) ;
goto V_25;
}
V_16 = F_9 ( V_2 -> V_27 , V_2 -> V_22 ,
V_28 ) ;
V_25:
V_2 -> V_23 = false ;
if ( V_16 == 0 )
return - V_29 ;
else if ( V_16 < 0 )
return V_16 ;
V_17 = ( V_2 -> V_30 << 12 ) | V_2 -> V_31 ;
V_16 = F_6 ( V_2 -> V_18 , V_19 ,
V_17 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_21 , L_1 ,
V_19 ) ;
return V_16 ;
}
V_5 = F_10 ( V_2 -> V_32 ) ;
V_11 = F_11 ( V_2 -> V_32 ) ;
F_3 ( V_2 , V_5 , V_11 , V_3 , V_4 ) ;
return V_33 ;
}
static int F_12 ( struct V_1 * V_2 , int * V_3 , int * V_4 )
{
* V_3 = 0 ;
* V_4 = V_2 -> V_34 ;
return V_33 ;
}
static int F_13 ( struct V_1 * V_2 , int time )
{
int V_16 ;
T_2 V_13 ;
V_16 = F_8 ( V_2 -> V_18 , V_24 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_21 , L_2 ,
V_24 ) ;
return V_16 ;
}
V_13 = V_16 ;
switch ( time ) {
case 100000 :
V_13 &= ~ V_35 ;
V_2 -> V_34 = 100000 ;
break;
case 800000 :
V_13 |= V_35 ;
V_2 -> V_34 = 800000 ;
break;
default:
return - V_10 ;
}
return F_6 ( V_2 -> V_18 , V_24 ,
V_13 ) ;
}
static int F_14 ( struct V_36 * V_37 ,
struct V_38 const * V_39 , int * V_3 , int * V_4 ,
long V_40 )
{
struct V_1 * V_2 = F_15 ( V_37 ) ;
int V_16 ;
if ( V_2 -> V_14 == V_41 )
return - V_42 ;
if ( V_39 -> type != V_43 )
return - V_10 ;
F_16 ( & V_2 -> V_44 ) ;
switch ( V_40 ) {
case V_45 :
V_16 = F_5 ( V_2 , V_3 , V_4 ) ;
break;
case V_46 :
V_16 = F_12 ( V_2 , V_3 , V_4 ) ;
break;
default:
V_16 = - V_10 ;
}
F_17 ( & V_2 -> V_44 ) ;
return V_16 ;
}
static int F_18 ( struct V_36 * V_37 ,
struct V_38 const * V_39 , int V_3 , int V_4 ,
long V_40 )
{
struct V_1 * V_2 = F_15 ( V_37 ) ;
int V_16 ;
if ( V_2 -> V_14 == V_41 )
return - V_42 ;
if ( V_39 -> type != V_43 )
return - V_10 ;
if ( V_40 != V_46 )
return - V_10 ;
if ( V_3 != 0 )
return - V_10 ;
F_16 ( & V_2 -> V_44 ) ;
V_16 = F_13 ( V_2 , V_4 ) ;
F_17 ( & V_2 -> V_44 ) ;
return V_16 ;
}
static int F_19 ( struct V_36 * V_37 ,
const struct V_38 * V_39 , enum V_47 type ,
enum V_48 V_49 , enum V_50 V_51 ,
int * V_3 , int * V_4 )
{
struct V_1 * V_2 = F_15 ( V_37 ) ;
int V_16 = V_33 ;
F_16 ( & V_2 -> V_44 ) ;
switch ( V_49 ) {
case V_52 :
F_3 ( V_2 , V_2 -> V_53 ,
V_2 -> V_54 , V_3 , V_4 ) ;
break;
case V_55 :
F_3 ( V_2 , V_2 -> V_30 ,
V_2 -> V_31 , V_3 , V_4 ) ;
break;
default:
V_16 = - V_10 ;
}
F_17 ( & V_2 -> V_44 ) ;
return V_16 ;
}
static int F_20 ( struct V_36 * V_37 ,
const struct V_38 * V_39 , enum V_47 type ,
enum V_48 V_49 , enum V_50 V_51 ,
int V_3 , int V_4 )
{
struct V_1 * V_2 = F_15 ( V_37 ) ;
int V_16 ;
T_2 V_11 ;
T_2 V_17 ;
T_2 V_13 ;
T_1 V_5 ;
if ( V_3 < 0 )
return - V_10 ;
F_16 ( & V_2 -> V_44 ) ;
V_16 = F_1 ( V_2 , V_3 , V_4 , & V_5 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_21 , L_3 , V_3 , V_4 ) ;
goto V_25;
}
V_11 = ( ( ( V_3 * 1000 ) + ( V_4 / 1000 ) ) / 10 ) >> V_5 ;
V_17 = ( V_5 << 12 ) | V_11 ;
switch ( V_49 ) {
case V_52 :
V_13 = V_56 ;
V_2 -> V_54 = V_11 ;
V_2 -> V_53 = V_5 ;
break;
case V_55 :
V_13 = V_19 ;
V_2 -> V_31 = V_11 ;
V_2 -> V_30 = V_5 ;
break;
default:
V_16 = - V_10 ;
goto V_25;
}
V_16 = F_6 ( V_2 -> V_18 , V_13 , V_17 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_21 , L_1 , V_13 ) ;
goto V_25;
}
V_25:
F_17 ( & V_2 -> V_44 ) ;
return V_16 ;
}
static int F_21 ( struct V_36 * V_37 ,
const struct V_38 * V_39 , enum V_47 type ,
enum V_48 V_49 )
{
struct V_1 * V_2 = F_15 ( V_37 ) ;
return V_2 -> V_14 == V_41 ;
}
static int F_22 ( struct V_36 * V_37 ,
const struct V_38 * V_39 , enum V_47 type ,
enum V_48 V_49 , int V_57 )
{
struct V_1 * V_2 = F_15 ( V_37 ) ;
int V_16 ;
T_2 V_14 ;
T_2 V_13 ;
if ( V_57 && V_2 -> V_14 == V_41 )
return 0 ;
if ( ! V_57 && V_2 -> V_14 == V_58 )
return 0 ;
F_16 ( & V_2 -> V_44 ) ;
V_14 = V_57 ? V_41
: V_58 ;
V_16 = F_8 ( V_2 -> V_18 , V_24 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_21 , L_2 ,
V_24 ) ;
goto V_25;
}
V_13 = V_16 ;
F_4 ( V_2 , & V_13 , V_14 ) ;
V_16 = F_6 ( V_2 -> V_18 , V_24 ,
V_13 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_21 , L_1 ,
V_24 ) ;
goto V_25;
}
V_25:
F_17 ( & V_2 -> V_44 ) ;
return V_16 ;
}
static int F_23 ( struct V_1 * V_2 )
{
char V_59 [ 2 ] ;
T_2 V_60 ;
int V_16 ;
V_16 = F_8 ( V_2 -> V_18 , V_61 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_21 , L_2 ,
V_61 ) ;
return V_16 ;
}
V_59 [ 0 ] = V_16 >> 8 ;
V_59 [ 1 ] = V_16 & 0xff ;
V_16 = F_8 ( V_2 -> V_18 , V_62 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_21 , L_2 ,
V_62 ) ;
return V_16 ;
}
V_60 = V_16 ;
F_24 ( V_2 -> V_21 , L_4 , V_59 [ 0 ] ,
V_59 [ 1 ] , V_60 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_16 ;
T_2 V_13 ;
V_16 = F_8 ( V_2 -> V_18 , V_24 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_21 , L_2 ,
V_24 ) ;
return V_16 ;
}
V_13 = V_16 ;
V_13 &= ~ V_63 ;
V_13 |= V_64 ;
if ( V_13 & V_35 )
V_2 -> V_34 = 800000 ;
else
V_2 -> V_34 = 100000 ;
F_4 ( V_2 , & V_13 , V_58 ) ;
V_13 |= V_65 ;
V_13 &= ~ V_66 ;
V_13 &= ~ V_67 ;
V_13 &= ~ V_68 ;
V_16 = F_6 ( V_2 -> V_18 , V_24 ,
V_13 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_21 , L_1 ,
V_24 ) ;
return V_16 ;
}
V_16 = F_8 ( V_2 -> V_18 , V_19 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_21 , L_2 ,
V_19 ) ;
return V_16 ;
}
V_2 -> V_31 = F_11 ( V_16 ) ;
V_2 -> V_30 = F_10 ( V_16 ) ;
V_16 = F_8 ( V_2 -> V_18 , V_56 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_21 , L_2 ,
V_56 ) ;
return V_16 ;
}
V_2 -> V_54 = F_11 ( V_16 ) ;
V_2 -> V_53 = F_10 ( V_16 ) ;
return 0 ;
}
static T_3 F_26 ( int V_69 , void * V_70 )
{
struct V_36 * V_37 = V_70 ;
struct V_1 * V_2 = F_15 ( V_37 ) ;
int V_16 ;
if ( ! V_2 -> V_23 )
F_16 ( & V_2 -> V_44 ) ;
V_16 = F_8 ( V_2 -> V_18 , V_24 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_21 , L_2 ,
V_24 ) ;
goto V_71;
}
if ( ( V_16 & V_15 ) ==
V_41 ) {
if ( V_16 & V_72 )
F_27 ( V_37 ,
F_28 ( V_43 , 0 ,
V_73 ,
V_52 ) ,
F_29 () ) ;
if ( V_16 & V_74 )
F_27 ( V_37 ,
F_28 ( V_43 , 0 ,
V_73 ,
V_55 ) ,
F_29 () ) ;
} else if ( V_16 & V_75 ) {
V_16 = F_8 ( V_2 -> V_18 , V_76 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_21 , L_2 ,
V_76 ) ;
goto V_71;
}
V_2 -> V_32 = V_16 ;
V_2 -> V_22 = true ;
F_30 ( & V_2 -> V_27 ) ;
}
V_71:
if ( ! V_2 -> V_23 )
F_17 ( & V_2 -> V_44 ) ;
return V_77 ;
}
static int F_31 ( struct V_78 * V_18 ,
const struct V_79 * V_80 )
{
struct V_81 * V_21 = & V_18 -> V_21 ;
struct V_36 * V_37 ;
struct V_1 * V_2 ;
int V_69 = V_18 -> V_69 ;
int V_16 ;
V_37 = F_32 ( V_21 , sizeof( * V_2 ) ) ;
if ( ! V_37 )
return - V_82 ;
V_2 = F_15 ( V_37 ) ;
V_2 -> V_18 = V_18 ;
V_2 -> V_21 = V_21 ;
F_33 ( & V_2 -> V_44 ) ;
F_34 ( & V_2 -> V_27 ) ;
F_35 ( V_18 , V_37 ) ;
V_16 = F_23 ( V_2 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_25 ( V_2 ) ;
if ( V_16 )
return V_16 ;
V_37 -> V_83 = V_18 -> V_83 ;
V_37 -> V_84 = V_85 ;
V_37 -> V_86 = F_2 ( V_85 ) ;
V_37 -> V_21 . V_87 = V_21 ;
V_37 -> V_88 = V_89 ;
V_37 -> V_51 = & V_90 ;
V_16 = F_36 ( V_21 , V_37 ) ;
if ( V_16 ) {
F_7 ( V_21 , L_5 ) ;
return V_16 ;
}
V_16 = F_37 ( V_69 , NULL , F_26 ,
V_91 | V_92 ,
L_6 , V_37 ) ;
if ( V_16 ) {
F_7 ( V_21 , L_7 , V_69 ) ;
return V_16 ;
}
return 0 ;
}
static int F_38 ( struct V_78 * V_18 )
{
struct V_36 * V_37 = F_39 ( V_18 ) ;
struct V_1 * V_2 = F_15 ( V_37 ) ;
int V_16 ;
T_2 V_13 ;
F_40 ( V_18 -> V_69 , V_37 ) ;
V_16 = F_8 ( V_2 -> V_18 , V_24 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_21 , L_2 ,
V_24 ) ;
return V_16 ;
}
V_13 = V_16 ;
F_4 ( V_2 , & V_13 , V_58 ) ;
V_16 = F_6 ( V_2 -> V_18 , V_24 ,
V_13 ) ;
if ( V_16 < 0 ) {
F_7 ( V_2 -> V_21 , L_1 ,
V_24 ) ;
return V_16 ;
}
return 0 ;
}
