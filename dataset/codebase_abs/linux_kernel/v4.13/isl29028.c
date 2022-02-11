static int F_1 ( int V_1 , int V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; ++ V_3 ) {
if ( V_4 [ V_3 ] . V_1 == V_1 &&
V_4 [ V_3 ] . V_2 == V_2 )
return V_3 ;
}
return - V_5 ;
}
static int F_3 ( struct V_6 * V_7 ,
int V_1 , int V_2 )
{
struct V_8 * V_9 = F_4 ( V_7 -> V_10 ) ;
int V_11 , V_12 ;
V_11 = F_1 ( V_1 ,
V_2 ) ;
if ( V_11 < 0 )
return V_11 ;
V_12 = F_5 ( V_7 -> V_10 , V_13 ,
V_14 ,
V_11 << V_15 ) ;
if ( V_12 < 0 ) {
F_6 ( V_9 , L_1 ,
V_16 , V_12 ) ;
return V_12 ;
}
V_7 -> V_17 = V_1 ;
V_7 -> V_18 = V_2 ;
return V_12 ;
}
static int F_7 ( struct V_6 * V_7 )
{
int V_19 , V_12 ;
V_12 = F_3 ( V_7 , V_7 -> V_17 ,
V_7 -> V_18 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_5 ( V_7 -> V_10 , V_13 ,
V_20 ,
V_21 ) ;
if ( V_12 < 0 )
return V_12 ;
V_19 = F_1 ( V_7 -> V_17 ,
V_7 -> V_18 ) ;
if ( V_19 < 0 )
return V_19 ;
F_8 ( V_4 [ V_19 ] . V_22 ) ;
return 0 ;
}
static int F_9 ( struct V_6 * V_7 , int V_23 )
{
struct V_8 * V_9 = F_4 ( V_7 -> V_10 ) ;
int V_24 = ( V_23 == 2000 ) ? V_25 :
V_26 ;
int V_12 ;
V_12 = F_5 ( V_7 -> V_10 , V_13 ,
V_27 , V_24 ) ;
if ( V_12 < 0 ) {
F_6 ( V_9 , L_2 , V_16 ,
V_12 ) ;
return V_12 ;
}
V_7 -> V_23 = V_23 ;
return V_12 ;
}
static int F_10 ( struct V_6 * V_7 ,
enum V_28 V_29 )
{
int V_12 ;
if ( V_7 -> V_30 == V_29 )
return 0 ;
V_12 = F_9 ( V_7 , V_7 -> V_23 ) ;
if ( V_12 < 0 )
return V_12 ;
switch ( V_29 ) {
case V_31 :
V_12 = F_5 ( V_7 -> V_10 , V_13 ,
V_32 ,
V_33 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_5 ( V_7 -> V_10 , V_13 ,
V_27 ,
V_25 ) ;
break;
case V_34 :
V_12 = F_5 ( V_7 -> V_10 , V_13 ,
V_32 ,
V_35 ) ;
break;
case V_36 :
return F_5 ( V_7 -> V_10 , V_13 ,
V_37 ,
V_38 ) ;
}
if ( V_12 < 0 )
return V_12 ;
V_12 = F_5 ( V_7 -> V_10 , V_13 ,
V_37 ,
V_39 ) ;
if ( V_12 < 0 )
return V_12 ;
F_8 ( V_40 ) ;
V_7 -> V_30 = V_29 ;
return 0 ;
}
static int F_11 ( struct V_6 * V_7 , int * V_41 )
{
struct V_8 * V_9 = F_4 ( V_7 -> V_10 ) ;
unsigned int V_42 ;
unsigned int V_43 ;
int V_12 ;
V_12 = F_12 ( V_7 -> V_10 , V_44 , & V_42 ) ;
if ( V_12 < 0 ) {
F_6 ( V_9 ,
L_3 ,
V_16 , V_12 ) ;
return V_12 ;
}
V_12 = F_12 ( V_7 -> V_10 , V_45 , & V_43 ) ;
if ( V_12 < 0 ) {
F_6 ( V_9 ,
L_4 ,
V_16 , V_12 ) ;
return V_12 ;
}
* V_41 = ( ( V_43 & 0xF ) << 8 ) | ( V_42 & 0xFF ) ;
return 0 ;
}
static int F_13 ( struct V_6 * V_7 , int * V_46 )
{
struct V_8 * V_9 = F_4 ( V_7 -> V_10 ) ;
unsigned int V_47 ;
int V_12 ;
if ( ! V_7 -> V_48 ) {
V_12 = F_7 ( V_7 ) ;
if ( V_12 < 0 )
return V_12 ;
V_7 -> V_48 = true ;
}
V_12 = F_12 ( V_7 -> V_10 , V_49 , & V_47 ) ;
if ( V_12 < 0 ) {
F_6 ( V_9 , L_5 ,
V_16 , V_12 ) ;
return V_12 ;
}
* V_46 = V_47 ;
return 0 ;
}
static int F_14 ( struct V_6 * V_7 , int * V_50 )
{
struct V_8 * V_9 = F_4 ( V_7 -> V_10 ) ;
int V_12 ;
int V_51 ;
V_12 = F_10 ( V_7 , V_31 ) ;
if ( V_12 < 0 ) {
F_6 ( V_9 , L_6 , V_16 ,
V_12 ) ;
return V_12 ;
}
V_12 = F_11 ( V_7 , & V_51 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_7 -> V_23 == 125 )
V_51 = ( V_51 * 31 ) / 1000 ;
else
V_51 = ( V_51 * 49 ) / 100 ;
* V_50 = V_51 ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 , int * V_52 )
{
struct V_8 * V_9 = F_4 ( V_7 -> V_10 ) ;
int V_12 ;
V_12 = F_10 ( V_7 , V_34 ) ;
if ( V_12 < 0 ) {
F_6 ( V_9 , L_7 , V_16 ,
V_12 ) ;
return V_12 ;
}
return F_11 ( V_7 , V_52 ) ;
}
static int F_16 ( struct V_6 * V_7 , bool V_53 )
{
struct V_8 * V_9 = F_4 ( V_7 -> V_10 ) ;
int V_12 ;
if ( V_53 ) {
V_12 = F_17 ( V_9 ) ;
if ( V_12 < 0 )
F_18 ( V_9 ) ;
} else {
F_19 ( V_9 ) ;
V_12 = F_20 ( V_9 ) ;
}
return V_12 ;
}
static int F_21 ( struct V_54 * V_55 ,
struct V_56 const * V_57 ,
int V_24 , int V_58 , long V_59 )
{
struct V_6 * V_7 = F_22 ( V_55 ) ;
struct V_8 * V_9 = F_4 ( V_7 -> V_10 ) ;
int V_12 ;
V_12 = F_16 ( V_7 , true ) ;
if ( V_12 < 0 )
return V_12 ;
F_23 ( & V_7 -> V_60 ) ;
V_12 = - V_5 ;
switch ( V_57 -> type ) {
case V_61 :
if ( V_59 != V_62 ) {
F_6 ( V_9 ,
L_8 ,
V_16 , V_59 ) ;
break;
}
if ( V_24 < 1 || V_24 > 100 ) {
F_6 ( V_9 ,
L_9 ,
V_16 , V_24 ) ;
break;
}
V_12 = F_3 ( V_7 , V_24 , V_58 ) ;
break;
case V_63 :
if ( V_59 != V_64 ) {
F_6 ( V_9 ,
L_10 ,
V_16 , V_59 ) ;
break;
}
if ( V_24 != 125 && V_24 != 2000 ) {
F_6 ( V_9 ,
L_11 ,
V_16 , V_24 ) ;
break;
}
V_12 = F_9 ( V_7 , V_24 ) ;
break;
default:
F_6 ( V_9 , L_12 ,
V_16 , V_57 -> type ) ;
break;
}
F_24 ( & V_7 -> V_60 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_16 ( V_7 , false ) ;
if ( V_12 < 0 )
return V_12 ;
return V_12 ;
}
static int F_25 ( struct V_54 * V_55 ,
struct V_56 const * V_57 ,
int * V_24 , int * V_58 , long V_59 )
{
struct V_6 * V_7 = F_22 ( V_55 ) ;
struct V_8 * V_9 = F_4 ( V_7 -> V_10 ) ;
int V_12 , V_65 ;
V_12 = F_16 ( V_7 , true ) ;
if ( V_12 < 0 )
return V_12 ;
F_23 ( & V_7 -> V_60 ) ;
V_12 = - V_5 ;
switch ( V_59 ) {
case V_66 :
case V_67 :
switch ( V_57 -> type ) {
case V_63 :
V_12 = F_14 ( V_7 , V_24 ) ;
break;
case V_68 :
V_12 = F_15 ( V_7 , V_24 ) ;
break;
case V_61 :
V_12 = F_13 ( V_7 , V_24 ) ;
break;
default:
break;
}
if ( V_12 < 0 )
break;
V_12 = V_69 ;
break;
case V_62 :
if ( V_57 -> type != V_61 )
break;
* V_24 = V_7 -> V_17 ;
* V_58 = V_7 -> V_18 ;
V_12 = V_69 ;
break;
case V_64 :
if ( V_57 -> type != V_63 )
break;
* V_24 = V_7 -> V_23 ;
V_12 = V_69 ;
break;
default:
F_6 ( V_9 , L_13 ,
V_16 , V_59 ) ;
break;
}
F_24 ( & V_7 -> V_60 ) ;
if ( V_12 < 0 )
return V_12 ;
V_65 = F_16 ( V_7 , false ) ;
if ( V_65 < 0 )
return V_65 ;
return V_12 ;
}
static int F_26 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_4 ( V_7 -> V_10 ) ;
int V_12 ;
V_12 = F_27 ( V_7 -> V_10 , V_13 , 0x0 ) ;
if ( V_12 < 0 )
F_6 ( V_9 , L_14 ,
V_16 , V_12 ) ;
V_7 -> V_30 = V_36 ;
V_7 -> V_48 = false ;
return V_12 ;
}
static bool F_28 ( struct V_8 * V_9 , unsigned int V_70 )
{
switch ( V_70 ) {
case V_71 :
case V_49 :
case V_44 :
case V_45 :
return true ;
default:
return false ;
}
}
static int F_29 ( struct V_72 * V_73 ,
const struct V_74 * V_75 )
{
struct V_6 * V_7 ;
struct V_54 * V_55 ;
int V_12 ;
V_55 = F_30 ( & V_73 -> V_9 , sizeof( * V_7 ) ) ;
if ( ! V_55 )
return - V_76 ;
V_7 = F_22 ( V_55 ) ;
F_31 ( V_73 , V_55 ) ;
F_32 ( & V_7 -> V_60 ) ;
V_7 -> V_10 = F_33 ( V_73 , & V_77 ) ;
if ( F_34 ( V_7 -> V_10 ) ) {
V_12 = F_35 ( V_7 -> V_10 ) ;
F_6 ( & V_73 -> V_9 , L_15 ,
V_16 , V_12 ) ;
return V_12 ;
}
V_7 -> V_48 = false ;
V_7 -> V_17 = 20 ;
V_7 -> V_18 = 0 ;
V_7 -> V_23 = 2000 ;
V_12 = F_27 ( V_7 -> V_10 , V_78 , 0x0 ) ;
if ( V_12 < 0 ) {
F_6 ( & V_73 -> V_9 ,
L_16 ,
V_16 , V_12 ) ;
return V_12 ;
}
V_12 = F_27 ( V_7 -> V_10 , V_79 , 0x0 ) ;
if ( V_12 < 0 ) {
F_6 ( & V_73 -> V_9 ,
L_17 ,
V_16 , V_12 ) ;
return V_12 ;
}
V_12 = F_26 ( V_7 ) ;
if ( V_12 < 0 )
return V_12 ;
V_55 -> V_80 = & V_81 ;
V_55 -> V_82 = V_83 ;
V_55 -> V_84 = F_2 ( V_83 ) ;
V_55 -> V_85 = V_75 -> V_85 ;
V_55 -> V_9 . V_86 = & V_73 -> V_9 ;
V_55 -> V_87 = V_88 ;
F_36 ( & V_73 -> V_9 ) ;
F_37 ( & V_73 -> V_9 ,
V_89 ) ;
F_38 ( & V_73 -> V_9 ) ;
V_12 = F_39 ( V_55 -> V_9 . V_86 , V_55 ) ;
if ( V_12 < 0 ) {
F_6 ( & V_73 -> V_9 ,
L_18 ,
V_16 , V_12 ) ;
return V_12 ;
}
return 0 ;
}
static int F_40 ( struct V_72 * V_73 )
{
struct V_54 * V_55 = F_41 ( V_73 ) ;
struct V_6 * V_7 = F_22 ( V_55 ) ;
F_42 ( V_55 ) ;
F_43 ( & V_73 -> V_9 ) ;
F_44 ( & V_73 -> V_9 ) ;
F_18 ( & V_73 -> V_9 ) ;
return F_26 ( V_7 ) ;
}
static int T_1 F_45 ( struct V_8 * V_9 )
{
struct V_54 * V_55 = F_41 ( F_46 ( V_9 ) ) ;
struct V_6 * V_7 = F_22 ( V_55 ) ;
int V_12 ;
F_23 ( & V_7 -> V_60 ) ;
V_12 = F_26 ( V_7 ) ;
F_24 ( & V_7 -> V_60 ) ;
return V_12 ;
}
static int T_1 F_47 ( struct V_8 * V_9 )
{
return 0 ;
}
