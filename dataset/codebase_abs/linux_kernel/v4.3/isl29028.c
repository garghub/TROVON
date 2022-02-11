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
V_24 , V_25 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_4 ( V_2 -> V_7 , V_8 ,
V_20 , V_18 ) ;
break;
case V_26 :
V_12 = F_4 ( V_2 -> V_7 , V_8 ,
V_24 , V_27 ) ;
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
unsigned int V_34 ;
unsigned int V_35 ;
int V_12 ;
V_12 = F_10 ( V_2 -> V_7 , V_36 , & V_34 ) ;
if ( V_12 < 0 ) {
F_11 ( V_2 -> V_37 ,
L_1 , V_12 ) ;
return V_12 ;
}
V_12 = F_10 ( V_2 -> V_7 , V_38 , & V_35 ) ;
if ( V_12 < 0 ) {
F_11 ( V_2 -> V_37 ,
L_2 , V_12 ) ;
return V_12 ;
}
* V_33 = ( ( V_35 & 0xF ) << 8 ) | ( V_34 & 0xFF ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , int * V_39 )
{
unsigned int V_40 ;
int V_12 ;
V_12 = F_10 ( V_2 -> V_7 , V_41 , & V_40 ) ;
if ( V_12 < 0 ) {
F_11 ( V_2 -> V_37 , L_3 ,
V_41 , V_12 ) ;
return V_12 ;
}
* V_39 = V_40 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , int * V_42 )
{
int V_12 ;
if ( ! V_2 -> V_43 ) {
V_12 = F_5 ( V_2 , true ) ;
if ( V_12 < 0 )
return V_12 ;
V_2 -> V_43 = true ;
}
return F_12 ( V_2 , V_42 ) ;
}
static int F_14 ( struct V_1 * V_2 , int * V_44 )
{
int V_12 ;
int V_45 ;
if ( V_2 -> V_21 != V_23 ) {
V_12 = F_8 ( V_2 , V_23 ) ;
if ( V_12 < 0 ) {
F_11 ( V_2 -> V_37 ,
L_4 , V_12 ) ;
return V_12 ;
}
V_2 -> V_21 = V_23 ;
}
V_12 = F_9 ( V_2 , & V_45 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_2 -> V_17 == 125 )
V_45 = ( V_45 * 31 ) / 1000 ;
else
V_45 = ( V_45 * 49 ) / 100 ;
* V_44 = V_45 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , int * V_46 )
{
int V_12 ;
if ( V_2 -> V_21 != V_26 ) {
V_12 = F_8 ( V_2 , V_26 ) ;
if ( V_12 < 0 ) {
F_11 ( V_2 -> V_37 ,
L_5 , V_12 ) ;
return V_12 ;
}
V_2 -> V_21 = V_26 ;
}
return F_9 ( V_2 , V_46 ) ;
}
static int F_16 ( struct V_47 * V_48 ,
struct V_49 const * V_50 , int V_13 , int V_51 , long V_52 )
{
struct V_1 * V_2 = F_17 ( V_48 ) ;
int V_12 = - V_53 ;
F_18 ( & V_2 -> V_54 ) ;
switch ( V_50 -> type ) {
case V_55 :
if ( V_52 != V_56 ) {
F_11 ( V_2 -> V_37 ,
L_6 ,
V_52 ) ;
break;
}
if ( V_13 < 1 || V_13 > 100 ) {
F_11 ( V_2 -> V_37 ,
L_7 , V_13 ) ;
break;
}
V_12 = F_1 ( V_2 , V_13 ) ;
if ( V_12 < 0 ) {
F_11 ( V_2 -> V_37 ,
L_8 ,
V_12 ) ;
break;
}
V_2 -> V_16 = V_13 ;
break;
case V_57 :
if ( V_52 != V_58 ) {
F_11 ( V_2 -> V_37 ,
L_9 ,
V_52 ) ;
break;
}
if ( ( V_13 != 125 ) && ( V_13 != 2000 ) ) {
F_11 ( V_2 -> V_37 ,
L_10 , V_13 ) ;
break;
}
V_12 = F_7 ( V_2 , V_13 ) ;
if ( V_12 < 0 ) {
F_11 ( V_2 -> V_37 ,
L_11 , V_12 ) ;
break;
}
V_2 -> V_17 = V_13 ;
break;
default:
F_11 ( V_2 -> V_37 , L_12 ) ;
break;
}
F_19 ( & V_2 -> V_54 ) ;
return V_12 ;
}
static int F_20 ( struct V_47 * V_48 ,
struct V_49 const * V_50 , int * V_13 , int * V_51 , long V_52 )
{
struct V_1 * V_2 = F_17 ( V_48 ) ;
int V_12 = - V_53 ;
F_18 ( & V_2 -> V_54 ) ;
switch ( V_52 ) {
case V_59 :
case V_60 :
switch ( V_50 -> type ) {
case V_57 :
V_12 = F_14 ( V_2 , V_13 ) ;
break;
case V_61 :
V_12 = F_15 ( V_2 , V_13 ) ;
break;
case V_55 :
V_12 = F_13 ( V_2 , V_13 ) ;
break;
default:
break;
}
if ( V_12 < 0 )
break;
V_12 = V_62 ;
break;
case V_56 :
if ( V_50 -> type != V_55 )
break;
* V_13 = V_2 -> V_16 ;
V_12 = V_62 ;
break;
case V_58 :
if ( V_50 -> type != V_57 )
break;
* V_13 = V_2 -> V_17 ;
V_12 = V_62 ;
break;
default:
F_11 ( V_2 -> V_37 , L_13 , V_52 ) ;
break;
}
F_19 ( & V_2 -> V_54 ) ;
return V_12 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_12 ;
V_2 -> V_43 = false ;
V_2 -> V_16 = 20 ;
V_2 -> V_17 = 2000 ;
V_2 -> V_21 = V_28 ;
V_12 = F_22 ( V_2 -> V_7 , V_63 , 0x0 ) ;
if ( V_12 < 0 ) {
F_11 ( V_2 -> V_37 , L_14 ,
V_64 , V_63 , V_12 ) ;
return V_12 ;
}
V_12 = F_22 ( V_2 -> V_7 , V_65 , 0x0 ) ;
if ( V_12 < 0 ) {
F_11 ( V_2 -> V_37 , L_14 ,
V_64 , V_65 , V_12 ) ;
return V_12 ;
}
V_12 = F_22 ( V_2 -> V_7 , V_8 , 0x0 ) ;
if ( V_12 < 0 ) {
F_11 ( V_2 -> V_37 , L_14 ,
V_64 , V_8 , V_12 ) ;
return V_12 ;
}
V_12 = F_1 ( V_2 , V_2 -> V_16 ) ;
if ( V_12 < 0 ) {
F_11 ( V_2 -> V_37 , L_15 ,
V_12 ) ;
return V_12 ;
}
V_12 = F_7 ( V_2 , V_2 -> V_17 ) ;
if ( V_12 < 0 )
F_11 ( V_2 -> V_37 ,
L_16 , V_12 ) ;
return V_12 ;
}
static bool F_23 ( struct V_66 * V_37 , unsigned int V_67 )
{
switch ( V_67 ) {
case V_68 :
case V_41 :
case V_36 :
case V_38 :
return true ;
default:
return false ;
}
}
static int F_24 ( struct V_69 * V_70 ,
const struct V_71 * V_72 )
{
struct V_1 * V_2 ;
struct V_47 * V_48 ;
int V_12 ;
V_48 = F_25 ( & V_70 -> V_37 , sizeof( * V_2 ) ) ;
if ( ! V_48 ) {
F_11 ( & V_70 -> V_37 , L_17 ) ;
return - V_73 ;
}
V_2 = F_17 ( V_48 ) ;
F_26 ( V_70 , V_48 ) ;
V_2 -> V_37 = & V_70 -> V_37 ;
F_27 ( & V_2 -> V_54 ) ;
V_2 -> V_7 = F_28 ( V_70 , & V_74 ) ;
if ( F_29 ( V_2 -> V_7 ) ) {
V_12 = F_30 ( V_2 -> V_7 ) ;
F_11 ( V_2 -> V_37 , L_18 , V_12 ) ;
return V_12 ;
}
V_12 = F_21 ( V_2 ) ;
if ( V_12 < 0 ) {
F_11 ( V_2 -> V_37 , L_19 , V_12 ) ;
return V_12 ;
}
V_48 -> V_75 = & V_76 ;
V_48 -> V_77 = V_78 ;
V_48 -> V_79 = F_3 ( V_78 ) ;
V_48 -> V_80 = V_72 -> V_80 ;
V_48 -> V_37 . V_81 = & V_70 -> V_37 ;
V_48 -> V_82 = V_83 ;
V_12 = F_31 ( V_48 ) ;
if ( V_12 < 0 ) {
F_11 ( V_2 -> V_37 , L_20 ,
V_12 ) ;
return V_12 ;
}
return 0 ;
}
static int F_32 ( struct V_69 * V_70 )
{
struct V_47 * V_48 = F_33 ( V_70 ) ;
F_34 ( V_48 ) ;
return 0 ;
}
