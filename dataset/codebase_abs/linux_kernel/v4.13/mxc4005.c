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
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_12 :
case V_13 :
case V_11 :
return true ;
default:
return false ;
}
}
static int F_3 ( struct V_14 * V_15 )
{
int V_16 ;
V_16 = F_4 ( V_15 -> V_17 , V_4 ,
( V_18 * ) V_15 -> V_19 , sizeof( V_15 -> V_19 ) ) ;
if ( V_16 < 0 ) {
F_5 ( V_15 -> V_2 , L_1 ) ;
return V_16 ;
}
return 0 ;
}
static int F_6 ( struct V_14 * V_15 ,
unsigned int V_20 )
{
T_1 V_3 ;
int V_16 ;
V_16 = F_4 ( V_15 -> V_17 , V_20 , ( V_18 * ) & V_3 , sizeof( V_3 ) ) ;
if ( V_16 < 0 ) {
F_5 ( V_15 -> V_2 , L_2 , V_20 ) ;
return V_16 ;
}
return F_7 ( V_3 ) ;
}
static int F_8 ( struct V_14 * V_15 )
{
unsigned int V_3 ;
int V_16 ;
int V_21 ;
V_16 = F_9 ( V_15 -> V_17 , V_11 , & V_3 ) ;
if ( V_16 < 0 ) {
F_5 ( V_15 -> V_2 , L_3 ) ;
return V_16 ;
}
V_21 = V_3 >> V_22 ;
if ( V_21 < 0 || V_21 >= F_10 ( V_23 ) )
return - V_24 ;
return V_23 [ V_21 ] . V_25 ;
}
static int F_11 ( struct V_14 * V_15 , int V_26 )
{
unsigned int V_3 ;
int V_21 ;
int V_16 ;
for ( V_21 = 0 ; V_21 < F_10 ( V_23 ) ; V_21 ++ ) {
if ( V_23 [ V_21 ] . V_25 == V_26 ) {
V_3 = V_21 << V_22 ;
V_16 = F_12 ( V_15 -> V_17 ,
V_11 ,
V_27 ,
V_3 ) ;
if ( V_16 < 0 )
F_5 ( V_15 -> V_2 ,
L_4 ) ;
return V_16 ;
}
}
return - V_24 ;
}
static int F_13 ( struct V_28 * V_29 ,
struct V_30 const * V_31 ,
int * V_26 , int * V_32 , long V_33 )
{
struct V_14 * V_15 = F_14 ( V_29 ) ;
int V_16 ;
switch ( V_33 ) {
case V_34 :
switch ( V_31 -> type ) {
case V_35 :
if ( F_15 ( V_29 ) )
return - V_36 ;
V_16 = F_6 ( V_15 , V_31 -> V_37 ) ;
if ( V_16 < 0 )
return V_16 ;
* V_26 = F_16 ( V_16 >> V_31 -> V_38 . V_39 ,
V_31 -> V_38 . V_40 - 1 ) ;
return V_41 ;
default:
return - V_24 ;
}
case V_42 :
V_16 = F_8 ( V_15 ) ;
if ( V_16 < 0 )
return V_16 ;
* V_26 = 0 ;
* V_32 = V_16 ;
return V_43 ;
default:
return - V_24 ;
}
}
static int F_17 ( struct V_28 * V_29 ,
struct V_30 const * V_31 ,
int V_26 , int V_32 , long V_33 )
{
struct V_14 * V_15 = F_14 ( V_29 ) ;
switch ( V_33 ) {
case V_42 :
if ( V_26 != 0 )
return - V_24 ;
return F_11 ( V_15 , V_32 ) ;
default:
return - V_24 ;
}
}
static T_2 F_18 ( int V_44 , void * V_45 )
{
struct V_46 * V_47 = V_45 ;
struct V_28 * V_29 = V_47 -> V_29 ;
struct V_14 * V_15 = F_14 ( V_29 ) ;
int V_16 ;
V_16 = F_3 ( V_15 ) ;
if ( V_16 < 0 )
goto V_48;
F_19 ( V_29 , V_15 -> V_19 ,
V_47 -> V_49 ) ;
V_48:
F_20 ( V_29 -> V_50 ) ;
return V_51 ;
}
static int F_21 ( struct V_14 * V_15 )
{
int V_16 ;
V_16 = F_22 ( V_15 -> V_17 , V_12 ,
V_52 ) ;
if ( V_16 < 0 ) {
F_5 ( V_15 -> V_2 , L_5 ) ;
return V_16 ;
}
return 0 ;
}
static int F_23 ( struct V_53 * V_50 ,
bool V_54 )
{
struct V_28 * V_29 = F_24 ( V_50 ) ;
struct V_14 * V_15 = F_14 ( V_29 ) ;
int V_16 ;
F_25 ( & V_15 -> V_55 ) ;
if ( V_54 ) {
V_16 = F_22 ( V_15 -> V_17 , V_13 ,
V_56 ) ;
} else {
V_16 = F_22 ( V_15 -> V_17 , V_13 ,
~ V_56 ) ;
}
if ( V_16 < 0 ) {
F_26 ( & V_15 -> V_55 ) ;
F_5 ( V_15 -> V_2 , L_6 ) ;
return V_16 ;
}
V_15 -> V_57 = V_54 ;
F_26 ( & V_15 -> V_55 ) ;
return 0 ;
}
static int F_27 ( struct V_53 * V_50 )
{
struct V_28 * V_29 = F_24 ( V_50 ) ;
struct V_14 * V_15 = F_14 ( V_29 ) ;
if ( ! V_15 -> V_58 )
return 0 ;
return F_21 ( V_15 ) ;
}
static int F_28 ( struct V_14 * V_15 )
{
int V_16 ;
unsigned int V_3 ;
V_16 = F_9 ( V_15 -> V_17 , V_10 , & V_3 ) ;
if ( V_16 < 0 ) {
F_5 ( V_15 -> V_2 , L_7 ) ;
return V_16 ;
}
F_29 ( V_15 -> V_2 , L_8 , V_3 ) ;
return 0 ;
}
static int F_30 ( struct V_59 * V_60 ,
const struct V_61 * V_62 )
{
struct V_14 * V_15 ;
struct V_28 * V_29 ;
struct V_17 * V_17 ;
int V_16 ;
V_29 = F_31 ( & V_60 -> V_2 , sizeof( * V_15 ) ) ;
if ( ! V_29 )
return - V_63 ;
V_17 = F_32 ( V_60 , & V_64 ) ;
if ( F_33 ( V_17 ) ) {
F_5 ( & V_60 -> V_2 , L_9 ) ;
return F_34 ( V_17 ) ;
}
V_15 = F_14 ( V_29 ) ;
F_35 ( V_60 , V_29 ) ;
V_15 -> V_2 = & V_60 -> V_2 ;
V_15 -> V_17 = V_17 ;
V_16 = F_28 ( V_15 ) ;
if ( V_16 < 0 ) {
F_5 ( & V_60 -> V_2 , L_10 ) ;
return V_16 ;
}
F_36 ( & V_15 -> V_55 ) ;
V_29 -> V_2 . V_65 = & V_60 -> V_2 ;
V_29 -> V_66 = V_67 ;
V_29 -> V_68 = F_10 ( V_67 ) ;
V_29 -> V_69 = V_70 ;
V_29 -> V_71 = V_72 ;
V_29 -> V_73 = V_74 ;
V_29 -> V_75 = & V_76 ;
V_16 = F_37 ( V_29 ,
V_77 ,
F_18 ,
NULL ) ;
if ( V_16 < 0 ) {
F_5 ( & V_60 -> V_2 ,
L_11 ) ;
return V_16 ;
}
if ( V_60 -> V_44 > 0 ) {
V_15 -> V_58 = F_38 ( & V_60 -> V_2 ,
L_12 ,
V_29 -> V_71 ,
V_29 -> V_62 ) ;
if ( ! V_15 -> V_58 )
return - V_63 ;
V_16 = F_39 ( & V_60 -> V_2 , V_60 -> V_44 ,
V_78 ,
NULL ,
V_79 |
V_80 ,
V_81 ,
V_15 -> V_58 ) ;
if ( V_16 ) {
F_5 ( & V_60 -> V_2 ,
L_13 ) ;
goto V_82;
}
V_15 -> V_58 -> V_2 . V_65 = & V_60 -> V_2 ;
V_15 -> V_58 -> V_83 = & V_84 ;
F_40 ( V_15 -> V_58 , V_29 ) ;
V_29 -> V_50 = V_15 -> V_58 ;
F_41 ( V_29 -> V_50 ) ;
V_16 = F_42 ( V_15 -> V_58 ) ;
if ( V_16 ) {
F_5 ( & V_60 -> V_2 ,
L_14 ) ;
goto V_85;
}
}
V_16 = F_43 ( V_29 ) ;
if ( V_16 < 0 ) {
F_5 ( & V_60 -> V_2 ,
L_15 , V_16 ) ;
goto V_82;
}
return 0 ;
V_85:
F_44 ( V_15 -> V_58 ) ;
V_82:
F_45 ( V_29 ) ;
return V_16 ;
}
static int F_46 ( struct V_59 * V_60 )
{
struct V_28 * V_29 = F_47 ( V_60 ) ;
struct V_14 * V_15 = F_14 ( V_29 ) ;
F_48 ( V_29 ) ;
F_45 ( V_29 ) ;
if ( V_15 -> V_58 )
F_44 ( V_15 -> V_58 ) ;
return 0 ;
}
