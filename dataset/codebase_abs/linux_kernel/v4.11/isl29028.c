static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
static unsigned int V_7 [] = { 800 , 400 , 200 , 100 , 75 , 50 , 12 , 0 } ;
unsigned int V_8 = F_3 ( 1000 , V_3 ) ;
int V_9 , V_10 ;
for ( V_9 = 0 ; V_9 < F_4 ( V_7 ) ; ++ V_9 ) {
if ( V_8 >= V_7 [ V_9 ] )
break;
}
V_10 = F_5 ( V_2 -> V_6 , V_11 ,
V_12 ,
V_9 << V_13 ) ;
if ( V_10 < 0 ) {
F_6 ( V_5 , L_1 ,
V_14 , V_10 ) ;
return V_10 ;
}
V_2 -> V_15 = V_3 ;
return V_10 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_10 ;
V_10 = F_1 ( V_2 , V_2 -> V_15 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_5 ( V_2 -> V_6 , V_11 ,
V_16 ,
V_17 ) ;
if ( V_10 < 0 )
return V_10 ;
F_8 ( F_3 ( 1000 , V_2 -> V_15 ) ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , int V_18 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_19 = ( V_18 == 2000 ) ? V_20 :
V_21 ;
int V_10 ;
V_10 = F_5 ( V_2 -> V_6 , V_11 ,
V_22 , V_19 ) ;
if ( V_10 < 0 ) {
F_6 ( V_5 , L_2 , V_14 ,
V_10 ) ;
return V_10 ;
}
V_2 -> V_18 = V_18 ;
return V_10 ;
}
static int F_10 ( struct V_1 * V_2 ,
enum V_23 V_24 )
{
int V_10 ;
if ( V_2 -> V_25 == V_24 )
return 0 ;
V_10 = F_9 ( V_2 , V_2 -> V_18 ) ;
if ( V_10 < 0 )
return V_10 ;
switch ( V_24 ) {
case V_26 :
V_10 = F_5 ( V_2 -> V_6 , V_11 ,
V_27 ,
V_28 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_5 ( V_2 -> V_6 , V_11 ,
V_22 ,
V_20 ) ;
break;
case V_29 :
V_10 = F_5 ( V_2 -> V_6 , V_11 ,
V_27 ,
V_30 ) ;
break;
case V_31 :
return F_5 ( V_2 -> V_6 , V_11 ,
V_32 ,
V_33 ) ;
}
if ( V_10 < 0 )
return V_10 ;
V_10 = F_5 ( V_2 -> V_6 , V_11 ,
V_32 ,
V_34 ) ;
if ( V_10 < 0 )
return V_10 ;
F_8 ( V_35 ) ;
V_2 -> V_25 = V_24 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , int * V_36 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
unsigned int V_37 ;
unsigned int V_38 ;
int V_10 ;
V_10 = F_12 ( V_2 -> V_6 , V_39 , & V_37 ) ;
if ( V_10 < 0 ) {
F_6 ( V_5 ,
L_3 ,
V_14 , V_10 ) ;
return V_10 ;
}
V_10 = F_12 ( V_2 -> V_6 , V_40 , & V_38 ) ;
if ( V_10 < 0 ) {
F_6 ( V_5 ,
L_4 ,
V_14 , V_10 ) ;
return V_10 ;
}
* V_36 = ( ( V_38 & 0xF ) << 8 ) | ( V_37 & 0xFF ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , int * V_41 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
unsigned int V_42 ;
int V_10 ;
if ( ! V_2 -> V_43 ) {
V_10 = F_7 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_2 -> V_43 = true ;
}
V_10 = F_12 ( V_2 -> V_6 , V_44 , & V_42 ) ;
if ( V_10 < 0 ) {
F_6 ( V_5 , L_5 ,
V_14 , V_10 ) ;
return V_10 ;
}
* V_41 = V_42 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , int * V_45 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_10 ;
int V_46 ;
V_10 = F_10 ( V_2 , V_26 ) ;
if ( V_10 < 0 ) {
F_6 ( V_5 , L_6 , V_14 ,
V_10 ) ;
return V_10 ;
}
V_10 = F_11 ( V_2 , & V_46 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_2 -> V_18 == 125 )
V_46 = ( V_46 * 31 ) / 1000 ;
else
V_46 = ( V_46 * 49 ) / 100 ;
* V_45 = V_46 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , int * V_47 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_10 ;
V_10 = F_10 ( V_2 , V_29 ) ;
if ( V_10 < 0 ) {
F_6 ( V_5 , L_7 , V_14 ,
V_10 ) ;
return V_10 ;
}
return F_11 ( V_2 , V_47 ) ;
}
static int F_16 ( struct V_1 * V_2 , bool V_48 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_10 ;
if ( V_48 ) {
V_10 = F_17 ( V_5 ) ;
if ( V_10 < 0 )
F_18 ( V_5 ) ;
} else {
F_19 ( V_5 ) ;
V_10 = F_20 ( V_5 ) ;
}
return V_10 ;
}
static int F_21 ( struct V_49 * V_50 ,
struct V_51 const * V_52 ,
int V_19 , int V_53 , long V_54 )
{
struct V_1 * V_2 = F_22 ( V_50 ) ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_10 ;
V_10 = F_16 ( V_2 , true ) ;
if ( V_10 < 0 )
return V_10 ;
F_23 ( & V_2 -> V_55 ) ;
V_10 = - V_56 ;
switch ( V_52 -> type ) {
case V_57 :
if ( V_54 != V_58 ) {
F_6 ( V_5 ,
L_8 ,
V_14 , V_54 ) ;
break;
}
if ( V_19 < 1 || V_19 > 100 ) {
F_6 ( V_5 ,
L_9 ,
V_14 , V_19 ) ;
break;
}
V_10 = F_1 ( V_2 , V_19 ) ;
break;
case V_59 :
if ( V_54 != V_60 ) {
F_6 ( V_5 ,
L_10 ,
V_14 , V_54 ) ;
break;
}
if ( V_19 != 125 && V_19 != 2000 ) {
F_6 ( V_5 ,
L_11 ,
V_14 , V_19 ) ;
break;
}
V_10 = F_9 ( V_2 , V_19 ) ;
break;
default:
F_6 ( V_5 , L_12 ,
V_14 , V_52 -> type ) ;
break;
}
F_24 ( & V_2 -> V_55 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_16 ( V_2 , false ) ;
if ( V_10 < 0 )
return V_10 ;
return V_10 ;
}
static int F_25 ( struct V_49 * V_50 ,
struct V_51 const * V_52 ,
int * V_19 , int * V_53 , long V_54 )
{
struct V_1 * V_2 = F_22 ( V_50 ) ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_10 , V_61 ;
V_10 = F_16 ( V_2 , true ) ;
if ( V_10 < 0 )
return V_10 ;
F_23 ( & V_2 -> V_55 ) ;
V_10 = - V_56 ;
switch ( V_54 ) {
case V_62 :
case V_63 :
switch ( V_52 -> type ) {
case V_59 :
V_10 = F_14 ( V_2 , V_19 ) ;
break;
case V_64 :
V_10 = F_15 ( V_2 , V_19 ) ;
break;
case V_57 :
V_10 = F_13 ( V_2 , V_19 ) ;
break;
default:
break;
}
if ( V_10 < 0 )
break;
V_10 = V_65 ;
break;
case V_58 :
if ( V_52 -> type != V_57 )
break;
* V_19 = V_2 -> V_15 ;
V_10 = V_65 ;
break;
case V_60 :
if ( V_52 -> type != V_59 )
break;
* V_19 = V_2 -> V_18 ;
V_10 = V_65 ;
break;
default:
F_6 ( V_5 , L_13 ,
V_14 , V_54 ) ;
break;
}
F_24 ( & V_2 -> V_55 ) ;
if ( V_10 < 0 )
return V_10 ;
V_61 = F_16 ( V_2 , false ) ;
if ( V_61 < 0 )
return V_61 ;
return V_10 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_10 ;
V_10 = F_27 ( V_2 -> V_6 , V_11 , 0x0 ) ;
if ( V_10 < 0 )
F_6 ( V_5 , L_14 ,
V_14 , V_10 ) ;
V_2 -> V_25 = V_31 ;
V_2 -> V_43 = false ;
return V_10 ;
}
static bool F_28 ( struct V_4 * V_5 , unsigned int V_66 )
{
switch ( V_66 ) {
case V_67 :
case V_44 :
case V_39 :
case V_40 :
return true ;
default:
return false ;
}
}
static int F_29 ( struct V_68 * V_69 ,
const struct V_70 * V_71 )
{
struct V_1 * V_2 ;
struct V_49 * V_50 ;
int V_10 ;
V_50 = F_30 ( & V_69 -> V_5 , sizeof( * V_2 ) ) ;
if ( ! V_50 )
return - V_72 ;
V_2 = F_22 ( V_50 ) ;
F_31 ( V_69 , V_50 ) ;
F_32 ( & V_2 -> V_55 ) ;
V_2 -> V_6 = F_33 ( V_69 , & V_73 ) ;
if ( F_34 ( V_2 -> V_6 ) ) {
V_10 = F_35 ( V_2 -> V_6 ) ;
F_6 ( & V_69 -> V_5 , L_15 ,
V_14 , V_10 ) ;
return V_10 ;
}
V_2 -> V_43 = false ;
V_2 -> V_15 = 20 ;
V_2 -> V_18 = 2000 ;
V_10 = F_27 ( V_2 -> V_6 , V_74 , 0x0 ) ;
if ( V_10 < 0 ) {
F_6 ( & V_69 -> V_5 ,
L_16 ,
V_14 , V_10 ) ;
return V_10 ;
}
V_10 = F_27 ( V_2 -> V_6 , V_75 , 0x0 ) ;
if ( V_10 < 0 ) {
F_6 ( & V_69 -> V_5 ,
L_17 ,
V_14 , V_10 ) ;
return V_10 ;
}
V_10 = F_26 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_50 -> V_76 = & V_77 ;
V_50 -> V_78 = V_79 ;
V_50 -> V_80 = F_4 ( V_79 ) ;
V_50 -> V_81 = V_71 -> V_81 ;
V_50 -> V_5 . V_82 = & V_69 -> V_5 ;
V_50 -> V_83 = V_84 ;
F_36 ( & V_69 -> V_5 ) ;
F_37 ( & V_69 -> V_5 ,
V_85 ) ;
F_38 ( & V_69 -> V_5 ) ;
V_10 = F_39 ( V_50 -> V_5 . V_82 , V_50 ) ;
if ( V_10 < 0 ) {
F_6 ( & V_69 -> V_5 ,
L_18 ,
V_14 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int F_40 ( struct V_68 * V_69 )
{
struct V_49 * V_50 = F_41 ( V_69 ) ;
struct V_1 * V_2 = F_22 ( V_50 ) ;
F_42 ( V_50 ) ;
F_43 ( & V_69 -> V_5 ) ;
F_44 ( & V_69 -> V_5 ) ;
F_18 ( & V_69 -> V_5 ) ;
return F_26 ( V_2 ) ;
}
static int T_1 F_45 ( struct V_4 * V_5 )
{
struct V_49 * V_50 = F_41 ( F_46 ( V_5 ) ) ;
struct V_1 * V_2 = F_22 ( V_50 ) ;
int V_10 ;
F_23 ( & V_2 -> V_55 ) ;
V_10 = F_26 ( V_2 ) ;
F_24 ( & V_2 -> V_55 ) ;
return V_10 ;
}
static int T_1 F_47 ( struct V_4 * V_5 )
{
return 0 ;
}
