static int F_1 ( int V_1 )
{
unsigned int V_2 = F_2 ( 1000 , V_1 ) ;
int V_3 ;
for ( V_3 = 0 ; V_3 < F_3 ( V_4 ) ; ++ V_3 ) {
if ( V_2 >= V_4 [ V_3 ] )
break;
}
return V_3 ;
}
static int F_4 ( struct V_5 * V_6 ,
unsigned int V_1 )
{
struct V_7 * V_8 = F_5 ( V_6 -> V_9 ) ;
int V_10 , V_11 ;
V_10 = F_1 ( V_1 ) ;
V_11 = F_6 ( V_6 -> V_9 , V_12 ,
V_13 ,
V_10 << V_14 ) ;
if ( V_11 < 0 ) {
F_7 ( V_8 , L_1 ,
V_15 , V_11 ) ;
return V_11 ;
}
V_6 -> V_16 = V_1 ;
return V_11 ;
}
static int F_8 ( struct V_5 * V_6 )
{
int V_10 , V_11 ;
V_11 = F_4 ( V_6 , V_6 -> V_16 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_6 -> V_9 , V_12 ,
V_17 ,
V_18 ) ;
if ( V_11 < 0 )
return V_11 ;
V_10 = F_1 ( V_6 -> V_16 ) ;
F_9 ( V_4 [ V_10 ] ) ;
return 0 ;
}
static int F_10 ( struct V_5 * V_6 , int V_19 )
{
struct V_7 * V_8 = F_5 ( V_6 -> V_9 ) ;
int V_20 = ( V_19 == 2000 ) ? V_21 :
V_22 ;
int V_11 ;
V_11 = F_6 ( V_6 -> V_9 , V_12 ,
V_23 , V_20 ) ;
if ( V_11 < 0 ) {
F_7 ( V_8 , L_2 , V_15 ,
V_11 ) ;
return V_11 ;
}
V_6 -> V_19 = V_19 ;
return V_11 ;
}
static int F_11 ( struct V_5 * V_6 ,
enum V_24 V_25 )
{
int V_11 ;
if ( V_6 -> V_26 == V_25 )
return 0 ;
V_11 = F_10 ( V_6 , V_6 -> V_19 ) ;
if ( V_11 < 0 )
return V_11 ;
switch ( V_25 ) {
case V_27 :
V_11 = F_6 ( V_6 -> V_9 , V_12 ,
V_28 ,
V_29 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_6 -> V_9 , V_12 ,
V_23 ,
V_21 ) ;
break;
case V_30 :
V_11 = F_6 ( V_6 -> V_9 , V_12 ,
V_28 ,
V_31 ) ;
break;
case V_32 :
return F_6 ( V_6 -> V_9 , V_12 ,
V_33 ,
V_34 ) ;
}
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_6 -> V_9 , V_12 ,
V_33 ,
V_35 ) ;
if ( V_11 < 0 )
return V_11 ;
F_9 ( V_36 ) ;
V_6 -> V_26 = V_25 ;
return 0 ;
}
static int F_12 ( struct V_5 * V_6 , int * V_37 )
{
struct V_7 * V_8 = F_5 ( V_6 -> V_9 ) ;
unsigned int V_38 ;
unsigned int V_39 ;
int V_11 ;
V_11 = F_13 ( V_6 -> V_9 , V_40 , & V_38 ) ;
if ( V_11 < 0 ) {
F_7 ( V_8 ,
L_3 ,
V_15 , V_11 ) ;
return V_11 ;
}
V_11 = F_13 ( V_6 -> V_9 , V_41 , & V_39 ) ;
if ( V_11 < 0 ) {
F_7 ( V_8 ,
L_4 ,
V_15 , V_11 ) ;
return V_11 ;
}
* V_37 = ( ( V_39 & 0xF ) << 8 ) | ( V_38 & 0xFF ) ;
return 0 ;
}
static int F_14 ( struct V_5 * V_6 , int * V_42 )
{
struct V_7 * V_8 = F_5 ( V_6 -> V_9 ) ;
unsigned int V_43 ;
int V_11 ;
if ( ! V_6 -> V_44 ) {
V_11 = F_8 ( V_6 ) ;
if ( V_11 < 0 )
return V_11 ;
V_6 -> V_44 = true ;
}
V_11 = F_13 ( V_6 -> V_9 , V_45 , & V_43 ) ;
if ( V_11 < 0 ) {
F_7 ( V_8 , L_5 ,
V_15 , V_11 ) ;
return V_11 ;
}
* V_42 = V_43 ;
return 0 ;
}
static int F_15 ( struct V_5 * V_6 , int * V_46 )
{
struct V_7 * V_8 = F_5 ( V_6 -> V_9 ) ;
int V_11 ;
int V_47 ;
V_11 = F_11 ( V_6 , V_27 ) ;
if ( V_11 < 0 ) {
F_7 ( V_8 , L_6 , V_15 ,
V_11 ) ;
return V_11 ;
}
V_11 = F_12 ( V_6 , & V_47 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_6 -> V_19 == 125 )
V_47 = ( V_47 * 31 ) / 1000 ;
else
V_47 = ( V_47 * 49 ) / 100 ;
* V_46 = V_47 ;
return 0 ;
}
static int F_16 ( struct V_5 * V_6 , int * V_48 )
{
struct V_7 * V_8 = F_5 ( V_6 -> V_9 ) ;
int V_11 ;
V_11 = F_11 ( V_6 , V_30 ) ;
if ( V_11 < 0 ) {
F_7 ( V_8 , L_7 , V_15 ,
V_11 ) ;
return V_11 ;
}
return F_12 ( V_6 , V_48 ) ;
}
static int F_17 ( struct V_5 * V_6 , bool V_49 )
{
struct V_7 * V_8 = F_5 ( V_6 -> V_9 ) ;
int V_11 ;
if ( V_49 ) {
V_11 = F_18 ( V_8 ) ;
if ( V_11 < 0 )
F_19 ( V_8 ) ;
} else {
F_20 ( V_8 ) ;
V_11 = F_21 ( V_8 ) ;
}
return V_11 ;
}
static int F_22 ( struct V_50 * V_51 ,
struct V_52 const * V_53 ,
int V_20 , int V_54 , long V_55 )
{
struct V_5 * V_6 = F_23 ( V_51 ) ;
struct V_7 * V_8 = F_5 ( V_6 -> V_9 ) ;
int V_11 ;
V_11 = F_17 ( V_6 , true ) ;
if ( V_11 < 0 )
return V_11 ;
F_24 ( & V_6 -> V_56 ) ;
V_11 = - V_57 ;
switch ( V_53 -> type ) {
case V_58 :
if ( V_55 != V_59 ) {
F_7 ( V_8 ,
L_8 ,
V_15 , V_55 ) ;
break;
}
if ( V_20 < 1 || V_20 > 100 ) {
F_7 ( V_8 ,
L_9 ,
V_15 , V_20 ) ;
break;
}
V_11 = F_4 ( V_6 , V_20 ) ;
break;
case V_60 :
if ( V_55 != V_61 ) {
F_7 ( V_8 ,
L_10 ,
V_15 , V_55 ) ;
break;
}
if ( V_20 != 125 && V_20 != 2000 ) {
F_7 ( V_8 ,
L_11 ,
V_15 , V_20 ) ;
break;
}
V_11 = F_10 ( V_6 , V_20 ) ;
break;
default:
F_7 ( V_8 , L_12 ,
V_15 , V_53 -> type ) ;
break;
}
F_25 ( & V_6 -> V_56 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_17 ( V_6 , false ) ;
if ( V_11 < 0 )
return V_11 ;
return V_11 ;
}
static int F_26 ( struct V_50 * V_51 ,
struct V_52 const * V_53 ,
int * V_20 , int * V_54 , long V_55 )
{
struct V_5 * V_6 = F_23 ( V_51 ) ;
struct V_7 * V_8 = F_5 ( V_6 -> V_9 ) ;
int V_11 , V_62 ;
V_11 = F_17 ( V_6 , true ) ;
if ( V_11 < 0 )
return V_11 ;
F_24 ( & V_6 -> V_56 ) ;
V_11 = - V_57 ;
switch ( V_55 ) {
case V_63 :
case V_64 :
switch ( V_53 -> type ) {
case V_60 :
V_11 = F_15 ( V_6 , V_20 ) ;
break;
case V_65 :
V_11 = F_16 ( V_6 , V_20 ) ;
break;
case V_58 :
V_11 = F_14 ( V_6 , V_20 ) ;
break;
default:
break;
}
if ( V_11 < 0 )
break;
V_11 = V_66 ;
break;
case V_59 :
if ( V_53 -> type != V_58 )
break;
* V_20 = V_6 -> V_16 ;
V_11 = V_66 ;
break;
case V_61 :
if ( V_53 -> type != V_60 )
break;
* V_20 = V_6 -> V_19 ;
V_11 = V_66 ;
break;
default:
F_7 ( V_8 , L_13 ,
V_15 , V_55 ) ;
break;
}
F_25 ( & V_6 -> V_56 ) ;
if ( V_11 < 0 )
return V_11 ;
V_62 = F_17 ( V_6 , false ) ;
if ( V_62 < 0 )
return V_62 ;
return V_11 ;
}
static int F_27 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_5 ( V_6 -> V_9 ) ;
int V_11 ;
V_11 = F_28 ( V_6 -> V_9 , V_12 , 0x0 ) ;
if ( V_11 < 0 )
F_7 ( V_8 , L_14 ,
V_15 , V_11 ) ;
V_6 -> V_26 = V_32 ;
V_6 -> V_44 = false ;
return V_11 ;
}
static bool F_29 ( struct V_7 * V_8 , unsigned int V_67 )
{
switch ( V_67 ) {
case V_68 :
case V_45 :
case V_40 :
case V_41 :
return true ;
default:
return false ;
}
}
static int F_30 ( struct V_69 * V_70 ,
const struct V_71 * V_72 )
{
struct V_5 * V_6 ;
struct V_50 * V_51 ;
int V_11 ;
V_51 = F_31 ( & V_70 -> V_8 , sizeof( * V_6 ) ) ;
if ( ! V_51 )
return - V_73 ;
V_6 = F_23 ( V_51 ) ;
F_32 ( V_70 , V_51 ) ;
F_33 ( & V_6 -> V_56 ) ;
V_6 -> V_9 = F_34 ( V_70 , & V_74 ) ;
if ( F_35 ( V_6 -> V_9 ) ) {
V_11 = F_36 ( V_6 -> V_9 ) ;
F_7 ( & V_70 -> V_8 , L_15 ,
V_15 , V_11 ) ;
return V_11 ;
}
V_6 -> V_44 = false ;
V_6 -> V_16 = 20 ;
V_6 -> V_19 = 2000 ;
V_11 = F_28 ( V_6 -> V_9 , V_75 , 0x0 ) ;
if ( V_11 < 0 ) {
F_7 ( & V_70 -> V_8 ,
L_16 ,
V_15 , V_11 ) ;
return V_11 ;
}
V_11 = F_28 ( V_6 -> V_9 , V_76 , 0x0 ) ;
if ( V_11 < 0 ) {
F_7 ( & V_70 -> V_8 ,
L_17 ,
V_15 , V_11 ) ;
return V_11 ;
}
V_11 = F_27 ( V_6 ) ;
if ( V_11 < 0 )
return V_11 ;
V_51 -> V_77 = & V_78 ;
V_51 -> V_79 = V_80 ;
V_51 -> V_81 = F_3 ( V_80 ) ;
V_51 -> V_82 = V_72 -> V_82 ;
V_51 -> V_8 . V_83 = & V_70 -> V_8 ;
V_51 -> V_84 = V_85 ;
F_37 ( & V_70 -> V_8 ) ;
F_38 ( & V_70 -> V_8 ,
V_86 ) ;
F_39 ( & V_70 -> V_8 ) ;
V_11 = F_40 ( V_51 -> V_8 . V_83 , V_51 ) ;
if ( V_11 < 0 ) {
F_7 ( & V_70 -> V_8 ,
L_18 ,
V_15 , V_11 ) ;
return V_11 ;
}
return 0 ;
}
static int F_41 ( struct V_69 * V_70 )
{
struct V_50 * V_51 = F_42 ( V_70 ) ;
struct V_5 * V_6 = F_23 ( V_51 ) ;
F_43 ( V_51 ) ;
F_44 ( & V_70 -> V_8 ) ;
F_45 ( & V_70 -> V_8 ) ;
F_19 ( & V_70 -> V_8 ) ;
return F_27 ( V_6 ) ;
}
static int T_1 F_46 ( struct V_7 * V_8 )
{
struct V_50 * V_51 = F_42 ( F_47 ( V_8 ) ) ;
struct V_5 * V_6 = F_23 ( V_51 ) ;
int V_11 ;
F_24 ( & V_6 -> V_56 ) ;
V_11 = F_27 ( V_6 ) ;
F_25 ( & V_6 -> V_56 ) ;
return V_11 ;
}
static int T_1 F_48 ( struct V_7 * V_8 )
{
return 0 ;
}
