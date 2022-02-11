static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
static unsigned int V_4 [] = { 800 , 400 , 200 , 100 , 75 , 50 , 12 , 0 } ;
int V_5 ;
unsigned int V_6 = F_2 ( 1000 , V_3 ) ;
for ( V_5 = 0 ; V_5 < F_3 ( V_4 ) ; ++ V_5 ) {
if ( V_6 >= V_4 [ V_5 ] )
break;
}
return F_4 ( V_2 -> V_7 , V_8 ,
V_9 , V_5 << V_10 ) ;
}
static int F_5 ( struct V_1 * V_2 , bool V_11 )
{
int V_12 ;
int V_13 = 0 ;
if ( V_11 )
V_13 = V_14 ;
V_12 = F_4 ( V_2 -> V_7 , V_8 ,
V_15 , V_13 ) ;
if ( V_12 < 0 )
return V_12 ;
F_6 ( F_2 ( 1000 , V_2 -> V_16 ) ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , int V_17 )
{
int V_13 = ( V_17 == 2000 ) ? V_18 :
V_19 ;
return F_4 ( V_2 -> V_7 , V_8 ,
V_20 , V_13 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
enum V_21 V_22 )
{
int V_12 = 0 ;
switch ( V_22 ) {
case V_23 :
V_12 = F_4 ( V_2 -> V_7 , V_8 ,
V_24 ,
V_25 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_4 ( V_2 -> V_7 , V_8 ,
V_20 ,
V_18 ) ;
break;
case V_26 :
V_12 = F_4 ( V_2 -> V_7 , V_8 ,
V_24 ,
V_27 ) ;
break;
case V_28 :
return F_4 ( V_2 -> V_7 , V_8 ,
V_29 , V_30 ) ;
}
if ( V_12 < 0 )
return V_12 ;
V_12 = F_4 ( V_2 -> V_7 , V_8 ,
V_29 , V_31 ) ;
if ( V_12 < 0 )
return V_12 ;
F_6 ( V_32 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , int * V_33 )
{
struct V_34 * V_35 = F_10 ( V_2 -> V_7 ) ;
unsigned int V_36 ;
unsigned int V_37 ;
int V_12 ;
V_12 = F_11 ( V_2 -> V_7 , V_38 , & V_36 ) ;
if ( V_12 < 0 ) {
F_12 ( V_35 ,
L_1 , V_12 ) ;
return V_12 ;
}
V_12 = F_11 ( V_2 -> V_7 , V_39 , & V_37 ) ;
if ( V_12 < 0 ) {
F_12 ( V_35 ,
L_2 , V_12 ) ;
return V_12 ;
}
* V_33 = ( ( V_37 & 0xF ) << 8 ) | ( V_36 & 0xFF ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , int * V_40 )
{
struct V_34 * V_35 = F_10 ( V_2 -> V_7 ) ;
unsigned int V_41 ;
int V_12 ;
V_12 = F_11 ( V_2 -> V_7 , V_42 , & V_41 ) ;
if ( V_12 < 0 ) {
F_12 ( V_35 , L_3 ,
V_42 , V_12 ) ;
return V_12 ;
}
* V_40 = V_41 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , int * V_43 )
{
int V_12 ;
if ( ! V_2 -> V_44 ) {
V_12 = F_5 ( V_2 , true ) ;
if ( V_12 < 0 )
return V_12 ;
V_2 -> V_44 = true ;
}
return F_13 ( V_2 , V_43 ) ;
}
static int F_15 ( struct V_1 * V_2 , int * V_45 )
{
struct V_34 * V_35 = F_10 ( V_2 -> V_7 ) ;
int V_12 ;
int V_46 ;
if ( V_2 -> V_21 != V_23 ) {
V_12 = F_8 ( V_2 , V_23 ) ;
if ( V_12 < 0 ) {
F_12 ( V_35 ,
L_4 , V_12 ) ;
return V_12 ;
}
V_2 -> V_21 = V_23 ;
}
V_12 = F_9 ( V_2 , & V_46 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_2 -> V_17 == 125 )
V_46 = ( V_46 * 31 ) / 1000 ;
else
V_46 = ( V_46 * 49 ) / 100 ;
* V_45 = V_46 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , int * V_47 )
{
struct V_34 * V_35 = F_10 ( V_2 -> V_7 ) ;
int V_12 ;
if ( V_2 -> V_21 != V_26 ) {
V_12 = F_8 ( V_2 , V_26 ) ;
if ( V_12 < 0 ) {
F_12 ( V_35 ,
L_5 , V_12 ) ;
return V_12 ;
}
V_2 -> V_21 = V_26 ;
}
return F_9 ( V_2 , V_47 ) ;
}
static int F_17 ( struct V_48 * V_49 ,
struct V_50 const * V_51 ,
int V_13 , int V_52 , long V_53 )
{
struct V_1 * V_2 = F_18 ( V_49 ) ;
struct V_34 * V_35 = F_10 ( V_2 -> V_7 ) ;
int V_12 = - V_54 ;
F_19 ( & V_2 -> V_55 ) ;
switch ( V_51 -> type ) {
case V_56 :
if ( V_53 != V_57 ) {
F_12 ( V_35 ,
L_6 ,
V_53 ) ;
break;
}
if ( V_13 < 1 || V_13 > 100 ) {
F_12 ( V_35 ,
L_7 , V_13 ) ;
break;
}
V_12 = F_1 ( V_2 , V_13 ) ;
if ( V_12 < 0 ) {
F_12 ( V_35 ,
L_8 ,
V_12 ) ;
break;
}
V_2 -> V_16 = V_13 ;
break;
case V_58 :
if ( V_53 != V_59 ) {
F_12 ( V_35 ,
L_9 ,
V_53 ) ;
break;
}
if ( ( V_13 != 125 ) && ( V_13 != 2000 ) ) {
F_12 ( V_35 ,
L_10 , V_13 ) ;
break;
}
V_12 = F_7 ( V_2 , V_13 ) ;
if ( V_12 < 0 ) {
F_12 ( V_35 ,
L_11 , V_12 ) ;
break;
}
V_2 -> V_17 = V_13 ;
break;
default:
F_12 ( V_35 , L_12 ) ;
break;
}
F_20 ( & V_2 -> V_55 ) ;
return V_12 ;
}
static int F_21 ( struct V_48 * V_49 ,
struct V_50 const * V_51 ,
int * V_13 , int * V_52 , long V_53 )
{
struct V_1 * V_2 = F_18 ( V_49 ) ;
struct V_34 * V_35 = F_10 ( V_2 -> V_7 ) ;
int V_12 = - V_54 ;
F_19 ( & V_2 -> V_55 ) ;
switch ( V_53 ) {
case V_60 :
case V_61 :
switch ( V_51 -> type ) {
case V_58 :
V_12 = F_15 ( V_2 , V_13 ) ;
break;
case V_62 :
V_12 = F_16 ( V_2 , V_13 ) ;
break;
case V_56 :
V_12 = F_14 ( V_2 , V_13 ) ;
break;
default:
break;
}
if ( V_12 < 0 )
break;
V_12 = V_63 ;
break;
case V_57 :
if ( V_51 -> type != V_56 )
break;
* V_13 = V_2 -> V_16 ;
V_12 = V_63 ;
break;
case V_59 :
if ( V_51 -> type != V_58 )
break;
* V_13 = V_2 -> V_17 ;
V_12 = V_63 ;
break;
default:
F_12 ( V_35 , L_13 , V_53 ) ;
break;
}
F_20 ( & V_2 -> V_55 ) ;
return V_12 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = F_10 ( V_2 -> V_7 ) ;
int V_12 ;
V_2 -> V_44 = false ;
V_2 -> V_16 = 20 ;
V_2 -> V_17 = 2000 ;
V_2 -> V_21 = V_28 ;
V_12 = F_23 ( V_2 -> V_7 , V_64 , 0x0 ) ;
if ( V_12 < 0 ) {
F_12 ( V_35 , L_14 ,
V_65 , V_64 , V_12 ) ;
return V_12 ;
}
V_12 = F_23 ( V_2 -> V_7 , V_66 , 0x0 ) ;
if ( V_12 < 0 ) {
F_12 ( V_35 , L_14 ,
V_65 , V_66 , V_12 ) ;
return V_12 ;
}
V_12 = F_23 ( V_2 -> V_7 , V_8 , 0x0 ) ;
if ( V_12 < 0 ) {
F_12 ( V_35 , L_14 ,
V_65 , V_8 , V_12 ) ;
return V_12 ;
}
V_12 = F_1 ( V_2 , V_2 -> V_16 ) ;
if ( V_12 < 0 ) {
F_12 ( V_35 , L_15 , V_12 ) ;
return V_12 ;
}
V_12 = F_7 ( V_2 , V_2 -> V_17 ) ;
if ( V_12 < 0 )
F_12 ( V_35 , L_16 , V_12 ) ;
return V_12 ;
}
static bool F_24 ( struct V_34 * V_35 , unsigned int V_67 )
{
switch ( V_67 ) {
case V_68 :
case V_42 :
case V_38 :
case V_39 :
return true ;
default:
return false ;
}
}
static int F_25 ( struct V_69 * V_70 ,
const struct V_71 * V_72 )
{
struct V_1 * V_2 ;
struct V_48 * V_49 ;
int V_12 ;
V_49 = F_26 ( & V_70 -> V_35 , sizeof( * V_2 ) ) ;
if ( ! V_49 ) {
F_12 ( & V_70 -> V_35 , L_17 ) ;
return - V_73 ;
}
V_2 = F_18 ( V_49 ) ;
F_27 ( V_70 , V_49 ) ;
F_28 ( & V_2 -> V_55 ) ;
V_2 -> V_7 = F_29 ( V_70 , & V_74 ) ;
if ( F_30 ( V_2 -> V_7 ) ) {
V_12 = F_31 ( V_2 -> V_7 ) ;
F_12 ( & V_70 -> V_35 , L_18 ,
V_12 ) ;
return V_12 ;
}
V_12 = F_22 ( V_2 ) ;
if ( V_12 < 0 ) {
F_12 ( & V_70 -> V_35 , L_19 , V_12 ) ;
return V_12 ;
}
V_49 -> V_75 = & V_76 ;
V_49 -> V_77 = V_78 ;
V_49 -> V_79 = F_3 ( V_78 ) ;
V_49 -> V_80 = V_72 -> V_80 ;
V_49 -> V_35 . V_81 = & V_70 -> V_35 ;
V_49 -> V_82 = V_83 ;
V_12 = F_32 ( V_49 -> V_35 . V_81 , V_49 ) ;
if ( V_12 < 0 ) {
F_12 ( & V_70 -> V_35 ,
L_20 ,
V_12 ) ;
return V_12 ;
}
return 0 ;
}
