static int F_1 ( T_1 V_1 , T_1 V_2 )
{
return V_1 * 1000 + V_2 * 1000 / 256 ;
}
static int F_2 ( T_1 V_1 , T_1 V_2 )
{
if ( V_1 & 0x80 )
return ( V_1 - 0x100 ) * 1000 ;
return F_1 ( V_1 , V_2 ) ;
}
static int F_3 ( struct V_3 * V_4 )
{
unsigned int V_5 ;
int V_6 ;
V_6 = F_4 ( V_4 -> V_7 , V_8 , & V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
switch ( V_5 ) {
case V_9 :
V_4 -> V_10 = 63 ;
break;
case V_11 :
V_4 -> V_10 = 364 ;
break;
case V_12 :
V_4 -> V_10 = 1000 ;
break;
case V_13 :
default:
V_4 -> V_10 = 2500 ;
break;
}
return 0 ;
}
static int F_5 ( struct V_3 * V_4 , long V_10 )
{
int V_6 , V_5 ;
if ( V_10 <= 63 ) {
V_10 = 63 ;
V_5 = V_9 ;
} else if ( V_10 <= 364 ) {
V_10 = 364 ;
V_5 = V_11 ;
} else if ( V_10 <= 1000 ) {
V_10 = 1000 ;
V_5 = V_12 ;
} else {
V_10 = 2500 ;
V_5 = V_13 ;
}
V_6 = F_6 ( V_4 -> V_7 , V_8 , V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 -> V_10 = V_10 ;
return 0 ;
}
static int F_7 ( struct V_14 * V_15 , T_2 V_16 , int V_17 ,
long * V_18 )
{
struct V_3 * V_4 = F_8 ( V_15 ) ;
struct V_7 * V_7 = V_4 -> V_7 ;
int V_6 , V_19 , V_20 , V_21 , V_22 ;
switch ( V_16 ) {
case V_23 :
V_19 = V_17 ? V_24 :
V_25 ;
V_20 = V_17 ? V_26 :
V_27 ;
V_6 = F_4 ( V_7 , V_19 , & V_21 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_7 , V_20 , & V_22 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( ! V_17 || ( V_22 & 0x80 ) || V_22 < 0x7f ) {
* V_18 = F_2 ( V_22 , V_21 ) ;
return 0 ;
}
V_6 = F_4 ( V_7 , V_28 ,
& V_21 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_7 , V_29 ,
& V_22 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_18 = F_1 ( V_22 , V_21 ) ;
return 0 ;
case V_30 :
V_6 = F_4 ( V_7 , V_31 ,
& V_22 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_18 = V_22 * 1000 ;
return 0 ;
case V_32 :
V_20 = V_17 ? V_33 :
V_34 ;
V_6 = F_4 ( V_7 , V_20 , & V_22 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_18 = V_22 * 1000 ;
return 0 ;
case V_35 :
V_6 = F_4 ( V_7 , V_31 ,
& V_22 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_7 , V_36 ,
& V_21 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_18 = ( V_22 - V_21 ) * 1000 ;
return 0 ;
case V_37 :
V_20 = V_17 ? V_33 :
V_34 ;
V_6 = F_4 ( V_7 , V_20 , & V_22 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_7 , V_36 ,
& V_21 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_18 = ( V_22 - V_21 ) * 1000 ;
return 0 ;
case V_38 :
V_6 = F_4 ( V_7 , V_39 , & V_22 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_18 = ( V_22 & V_40 ) ? 1 : 2 ;
return 0 ;
case V_41 :
V_6 = F_4 ( V_7 , V_42 ,
& V_21 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_7 , V_43 ,
& V_22 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_18 = F_2 ( V_22 , V_21 ) ;
return 0 ;
case V_44 :
V_6 = F_4 ( V_7 , V_45 , & V_22 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_18 = ! ! ( V_22 & V_46 ) ;
return 0 ;
case V_47 :
V_6 = F_4 ( V_7 , V_45 , & V_22 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_18 = ! ! ( V_22 & ( V_17 ? V_48 : V_49 ) ) ;
return 0 ;
case V_50 :
V_6 = F_4 ( V_7 , V_45 , & V_22 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_18 = ! ! ( V_22 & V_51 ) ;
return 0 ;
default:
return - V_52 ;
}
}
static int F_9 ( struct V_14 * V_15 , T_2 V_16 , int V_17 ,
long V_18 )
{
struct V_3 * V_4 = F_8 ( V_15 ) ;
struct V_7 * V_7 = V_4 -> V_7 ;
unsigned int V_53 ;
int V_6 , V_54 ;
switch ( V_16 ) {
case V_30 :
V_18 = F_10 ( V_18 / 1000 , 0 , 255 ) ;
V_6 = F_6 ( V_7 , V_31 , V_18 ) ;
return V_6 ;
case V_32 :
V_54 = V_17 ? V_33 :
V_34 ;
V_18 = F_10 ( V_18 / 1000 , 0 , V_17 ? 255 : 127 ) ;
V_6 = F_6 ( V_7 , V_54 , V_18 ) ;
return V_6 ;
case V_37 :
F_11 ( & V_4 -> V_55 ) ;
V_6 = F_4 ( V_7 , V_34 ,
& V_53 ) ;
if ( V_6 < 0 ) {
F_12 ( & V_4 -> V_55 ) ;
return V_6 ;
}
V_18 = F_10 ( V_18 , - 1000000 , 1000000 ) ;
V_18 = V_53 - V_18 / 1000 ;
V_18 = F_10 ( V_18 , 0 , 31 ) ;
V_6 = F_6 ( V_7 , V_36 ,
V_18 ) ;
F_12 ( & V_4 -> V_55 ) ;
return V_6 ;
case V_41 :
V_18 = F_10 ( V_18 , - 128000 , 127875 ) ;
V_18 = V_18 * 256 / 1000 ;
F_11 ( & V_4 -> V_55 ) ;
V_6 = F_6 ( V_7 , V_42 ,
V_18 & 0xe0 ) ;
if ( V_6 < 0 ) {
F_12 ( & V_4 -> V_55 ) ;
return V_6 ;
}
V_6 = F_6 ( V_7 , V_43 ,
( V_18 >> 8 ) & 0xff ) ;
F_12 ( & V_4 -> V_55 ) ;
return V_6 ;
case V_38 :
if ( V_18 != 1 && V_18 != 2 )
return - V_56 ;
V_6 = F_13 ( V_7 , V_39 ,
V_40 ,
V_18 == 1 ? V_40 : 0 ) ;
return V_6 ;
default:
return - V_52 ;
}
}
static int F_14 ( struct V_14 * V_15 , T_2 V_16 , int V_17 ,
long * V_18 )
{
struct V_3 * V_4 = F_8 ( V_15 ) ;
switch ( V_16 ) {
case V_57 :
* V_18 = V_4 -> V_10 ;
return 0 ;
default:
return - V_52 ;
}
}
static int F_15 ( struct V_14 * V_15 , T_2 V_16 , int V_17 ,
long V_18 )
{
struct V_3 * V_4 = F_8 ( V_15 ) ;
int V_6 ;
switch ( V_16 ) {
case V_57 :
F_11 ( & V_4 -> V_55 ) ;
V_6 = F_5 ( V_4 , V_18 ) ;
F_12 ( & V_4 -> V_55 ) ;
return V_6 ;
default:
return - V_52 ;
}
}
static int F_16 ( struct V_14 * V_15 , enum V_58 type ,
T_2 V_16 , int V_17 , long * V_18 )
{
switch ( type ) {
case V_59 :
return F_14 ( V_15 , V_16 , V_17 , V_18 ) ;
case V_60 :
return F_7 ( V_15 , V_16 , V_17 , V_18 ) ;
default:
return - V_52 ;
}
}
static int F_17 ( struct V_14 * V_15 , enum V_58 type ,
T_2 V_16 , int V_17 , long V_18 )
{
switch ( type ) {
case V_59 :
return F_15 ( V_15 , V_16 , V_17 , V_18 ) ;
case V_60 :
return F_9 ( V_15 , V_16 , V_17 , V_18 ) ;
default:
return - V_52 ;
}
}
static T_3 F_18 ( const void * V_4 , T_2 V_16 , int V_17 )
{
switch ( V_16 ) {
case V_23 :
case V_44 :
case V_35 :
case V_47 :
case V_50 :
return V_61 ;
case V_38 :
case V_30 :
case V_32 :
case V_41 :
return V_61 | V_62 ;
case V_37 :
return ( V_17 == 0 ) ? V_61 | V_62 : V_61 ;
default:
return 0 ;
}
}
static T_3 F_19 ( const void * V_4 ,
enum V_58 type ,
T_2 V_16 , int V_17 )
{
switch ( type ) {
case V_59 :
switch ( V_16 ) {
case V_57 :
return V_61 | V_62 ;
default:
return 0 ;
}
case V_60 :
return F_18 ( V_4 , V_16 , V_17 ) ;
default:
return 0 ;
}
}
static int F_20 ( struct V_63 * V_64 ,
struct V_65 * V_66 )
{
struct V_67 * V_68 = V_64 -> V_68 ;
int V_69 = V_64 -> V_70 ;
const char * V_71 ;
int V_72 , V_73 ;
if ( ! F_21 ( V_68 , V_74 ) )
return - V_75 ;
V_73 = F_22 ( V_64 , V_76 ) ;
if ( V_73 != V_77 )
return - V_75 ;
V_72 = F_22 ( V_64 , V_78 ) ;
switch ( V_72 ) {
case V_79 :
if ( V_69 != 0x18 && V_69 != 0x29 && V_69 != 0x4c )
return - V_75 ;
V_71 = L_1 ;
break;
case V_80 :
V_71 = L_2 ;
break;
default:
return - V_75 ;
}
F_23 ( V_66 -> type , V_71 , V_81 ) ;
return 0 ;
}
static int F_24 ( struct V_3 * V_4 )
{
int V_6 ;
V_6 = F_3 ( V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_13 ( V_4 -> V_7 , V_82 ,
V_83 , 0 ) ;
}
static bool F_25 ( struct V_14 * V_15 , unsigned int V_54 )
{
switch ( V_54 ) {
case V_82 :
case V_8 :
case V_84 :
case V_39 :
case V_43 :
case V_42 :
case V_31 :
case V_34 :
case V_33 :
case V_36 :
return true ;
default:
return false ;
}
}
static bool F_26 ( struct V_14 * V_15 , unsigned int V_54 )
{
switch ( V_54 ) {
case V_45 :
case V_85 :
case V_27 :
case V_25 :
case V_26 :
case V_24 :
case V_29 :
case V_28 :
return true ;
default:
return false ;
}
}
static int F_27 ( struct V_63 * V_86 ,
const struct V_87 * V_73 )
{
struct V_14 * V_15 = & V_86 -> V_15 ;
struct V_3 * V_4 ;
struct V_14 * V_88 ;
int V_6 ;
V_4 = F_28 ( V_15 , sizeof( struct V_3 ) , V_89 ) ;
if ( ! V_4 )
return - V_90 ;
V_4 -> V_7 = F_29 ( V_86 , & V_91 ) ;
if ( F_30 ( V_4 -> V_7 ) )
return F_31 ( V_4 -> V_7 ) ;
F_32 ( & V_4 -> V_55 ) ;
V_6 = F_24 ( V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
V_88 = F_33 ( V_15 , V_86 -> V_71 ,
V_4 ,
& V_92 ,
NULL ) ;
return F_34 ( V_88 ) ;
}
