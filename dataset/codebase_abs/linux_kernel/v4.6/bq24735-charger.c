static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 ,
enum V_4 V_5 )
{
switch ( V_5 ) {
case V_6 :
return 1 ;
default:
break;
}
return 0 ;
}
static inline int F_4 ( struct V_7 * V_8 , T_1 V_9 ,
T_2 V_10 )
{
return F_5 ( V_8 , V_9 , F_6 ( V_10 ) ) ;
}
static inline int F_7 ( struct V_7 * V_8 , T_1 V_9 )
{
T_3 V_11 = F_8 ( V_8 , V_9 ) ;
return V_11 < 0 ? V_11 : F_6 ( V_11 ) ;
}
static int F_9 ( struct V_7 * V_8 , T_1 V_9 ,
T_2 V_12 , T_2 V_10 )
{
unsigned int V_13 ;
int V_11 ;
V_11 = F_7 ( V_8 , V_9 ) ;
if ( V_11 < 0 )
return V_11 ;
V_13 = V_11 & ~ V_12 ;
V_13 |= V_10 & V_12 ;
return F_4 ( V_8 , V_9 , V_13 ) ;
}
static inline int F_10 ( struct V_1 * V_14 )
{
if ( V_14 -> V_15 -> V_16 )
return 0 ;
return F_9 ( V_14 -> V_8 , V_17 ,
V_18 ,
~ V_18 ) ;
}
static inline int F_11 ( struct V_1 * V_14 )
{
if ( V_14 -> V_15 -> V_16 )
return 0 ;
return F_9 ( V_14 -> V_8 , V_17 ,
V_18 ,
V_18 ) ;
}
static int F_12 ( struct V_1 * V_14 )
{
struct V_19 * V_15 = V_14 -> V_15 ;
int V_11 ;
T_2 V_10 ;
if ( V_15 -> V_16 )
return 0 ;
if ( V_15 -> V_20 ) {
V_10 = V_15 -> V_20 & V_21 ;
V_11 = F_4 ( V_14 -> V_8 ,
V_22 , V_10 ) ;
if ( V_11 < 0 ) {
F_13 ( & V_14 -> V_8 -> V_23 ,
L_1 ,
V_11 ) ;
return V_11 ;
}
}
if ( V_15 -> V_24 ) {
V_10 = V_15 -> V_24 & V_25 ;
V_11 = F_4 ( V_14 -> V_8 ,
V_26 , V_10 ) ;
if ( V_11 < 0 ) {
F_13 ( & V_14 -> V_8 -> V_23 ,
L_2 ,
V_11 ) ;
return V_11 ;
}
}
if ( V_15 -> V_27 ) {
V_10 = V_15 -> V_27 & V_28 ;
V_11 = F_4 ( V_14 -> V_8 ,
V_29 , V_10 ) ;
if ( V_11 < 0 ) {
F_13 ( & V_14 -> V_8 -> V_23 ,
L_3 ,
V_11 ) ;
return V_11 ;
}
}
return 0 ;
}
static bool F_14 ( struct V_1 * V_14 )
{
struct V_19 * V_15 = V_14 -> V_15 ;
int V_11 ;
if ( V_15 -> V_30 ) {
V_11 = F_15 ( V_15 -> V_31 ) ;
return V_11 ^= V_15 -> V_32 == 0 ;
} else {
int V_33 = 0 ;
V_33 = F_7 ( V_14 -> V_8 , V_17 ) ;
if ( V_33 < 0 ) {
F_13 ( & V_14 -> V_8 -> V_23 ,
L_4 ,
V_33 ) ;
return false ;
}
return ( V_33 & V_34 ) ? true : false ;
}
return false ;
}
static int F_16 ( struct V_1 * V_14 )
{
int V_11 = F_7 ( V_14 -> V_8 , V_17 ) ;
if ( V_11 < 0 )
return V_11 ;
return ! ( V_11 & V_18 ) ;
}
static T_4 F_17 ( int V_35 , void * V_36 )
{
struct V_2 * V_3 = V_36 ;
struct V_1 * V_14 = F_1 ( V_3 ) ;
F_18 ( & V_14 -> V_37 ) ;
if ( V_14 -> V_38 && F_14 ( V_14 ) )
F_10 ( V_14 ) ;
else
F_11 ( V_14 ) ;
F_19 ( & V_14 -> V_37 ) ;
F_20 ( V_3 ) ;
return V_39 ;
}
static int F_21 ( struct V_2 * V_3 ,
enum V_4 V_5 ,
union V_40 * V_41 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
switch ( V_5 ) {
case V_42 :
V_41 -> V_43 = F_14 ( V_14 ) ? 1 : 0 ;
break;
case V_6 :
switch ( F_16 ( V_14 ) ) {
case 1 :
V_41 -> V_43 = V_44 ;
break;
case 0 :
V_41 -> V_43 = V_45 ;
break;
default:
V_41 -> V_43 = V_46 ;
break;
}
break;
default:
return - V_47 ;
}
return 0 ;
}
static int F_22 ( struct V_2 * V_3 ,
enum V_4 V_5 ,
const union V_40 * V_41 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
int V_11 ;
switch ( V_5 ) {
case V_6 :
switch ( V_41 -> V_43 ) {
case V_44 :
F_18 ( & V_14 -> V_37 ) ;
V_14 -> V_38 = true ;
V_11 = F_10 ( V_14 ) ;
F_19 ( & V_14 -> V_37 ) ;
if ( V_11 )
return V_11 ;
F_12 ( V_14 ) ;
break;
case V_48 :
case V_45 :
F_18 ( & V_14 -> V_37 ) ;
V_14 -> V_38 = false ;
V_11 = F_11 ( V_14 ) ;
F_19 ( & V_14 -> V_37 ) ;
if ( V_11 )
return V_11 ;
break;
default:
return - V_47 ;
}
F_20 ( V_3 ) ;
break;
default:
return - V_49 ;
}
return 0 ;
}
static struct V_19 * F_23 ( struct V_7 * V_8 )
{
struct V_19 * V_15 ;
struct V_50 * V_51 = V_8 -> V_23 . V_52 ;
T_5 V_41 ;
int V_11 ;
enum V_53 V_54 ;
V_15 = F_24 ( & V_8 -> V_23 , sizeof( * V_15 ) , V_55 ) ;
if ( ! V_15 ) {
F_13 ( & V_8 -> V_23 ,
L_5 ) ;
return NULL ;
}
V_15 -> V_31 = F_25 ( V_51 , L_6 ,
0 , & V_54 ) ;
if ( V_54 & V_56 )
V_15 -> V_32 = 1 ;
V_11 = F_26 ( V_51 , L_7 , & V_41 ) ;
if ( ! V_11 )
V_15 -> V_20 = V_41 ;
V_11 = F_26 ( V_51 , L_8 , & V_41 ) ;
if ( ! V_11 )
V_15 -> V_24 = V_41 ;
V_11 = F_26 ( V_51 , L_9 , & V_41 ) ;
if ( ! V_11 )
V_15 -> V_27 = V_41 ;
V_15 -> V_16 = F_27 ( V_51 , L_10 ) ;
return V_15 ;
}
static int F_28 ( struct V_7 * V_8 ,
const struct V_57 * V_58 )
{
int V_11 ;
struct V_1 * V_14 ;
struct V_59 * V_60 ;
struct V_61 V_62 = {} ;
char * V_63 ;
V_14 = F_24 ( & V_8 -> V_23 , sizeof( * V_14 ) , V_55 ) ;
if ( ! V_14 )
return - V_64 ;
F_29 ( & V_14 -> V_37 ) ;
V_14 -> V_38 = true ;
V_14 -> V_15 = V_8 -> V_23 . V_65 ;
if ( F_30 ( V_66 ) && ! V_14 -> V_15 && V_8 -> V_23 . V_52 )
V_14 -> V_15 = F_23 ( V_8 ) ;
if ( ! V_14 -> V_15 ) {
F_13 ( & V_8 -> V_23 , L_11 ) ;
return - V_47 ;
}
V_63 = ( char * ) V_14 -> V_15 -> V_63 ;
if ( ! V_63 ) {
V_63 = F_31 ( & V_8 -> V_23 , V_55 ,
L_12 ,
F_32 ( & V_8 -> V_23 ) ) ;
if ( ! V_63 ) {
F_13 ( & V_8 -> V_23 , L_13 ) ;
return - V_64 ;
}
}
V_14 -> V_8 = V_8 ;
V_60 = & V_14 -> V_67 ;
V_60 -> V_63 = V_63 ;
V_60 -> type = V_68 ;
V_60 -> V_69 = V_70 ;
V_60 -> V_71 = F_33 ( V_70 ) ;
V_60 -> V_72 = F_21 ;
V_60 -> V_73 = F_22 ;
V_60 -> V_74 =
F_3 ;
V_62 . V_75 = V_14 -> V_15 -> V_75 ;
V_62 . V_76 = V_14 -> V_15 -> V_76 ;
V_62 . V_52 = V_8 -> V_23 . V_52 ;
V_62 . V_77 = V_14 ;
F_34 ( V_8 , V_14 ) ;
if ( F_35 ( V_14 -> V_15 -> V_31 ) ) {
V_11 = F_36 ( & V_8 -> V_23 ,
V_14 -> V_15 -> V_31 ,
V_63 ) ;
if ( V_11 ) {
F_13 ( & V_8 -> V_23 ,
L_14 ,
V_14 -> V_15 -> V_31 , V_11 ) ;
}
V_14 -> V_15 -> V_30 = ! V_11 ;
}
if ( ! V_14 -> V_15 -> V_30
|| F_14 ( V_14 ) ) {
V_11 = F_7 ( V_8 , V_78 ) ;
if ( V_11 < 0 ) {
F_13 ( & V_8 -> V_23 , L_15 ,
V_11 ) ;
return V_11 ;
} else if ( V_11 != 0x0040 ) {
F_13 ( & V_8 -> V_23 ,
L_16 , V_11 ) ;
return - V_79 ;
}
V_11 = F_7 ( V_8 , V_80 ) ;
if ( V_11 < 0 ) {
F_13 ( & V_8 -> V_23 , L_17 , V_11 ) ;
return V_11 ;
} else if ( V_11 != 0x000B ) {
F_13 ( & V_8 -> V_23 ,
L_18 , V_11 ) ;
return - V_79 ;
}
}
V_11 = F_12 ( V_14 ) ;
if ( V_11 < 0 ) {
F_13 ( & V_8 -> V_23 , L_19 ) ;
return V_11 ;
}
if ( F_14 ( V_14 ) ) {
V_11 = F_10 ( V_14 ) ;
if ( V_11 < 0 ) {
F_13 ( & V_8 -> V_23 , L_20 ) ;
return V_11 ;
}
}
V_14 -> V_14 = F_37 ( & V_8 -> V_23 , V_60 ,
& V_62 ) ;
if ( F_38 ( V_14 -> V_14 ) ) {
V_11 = F_39 ( V_14 -> V_14 ) ;
F_13 ( & V_8 -> V_23 , L_21 ,
V_11 ) ;
return V_11 ;
}
if ( V_8 -> V_35 ) {
V_11 = F_40 ( & V_8 -> V_23 , V_8 -> V_35 ,
NULL , F_17 ,
V_81 |
V_82 |
V_83 ,
V_60 -> V_63 ,
V_14 -> V_14 ) ;
if ( V_11 ) {
F_13 ( & V_8 -> V_23 ,
L_22 ,
V_8 -> V_35 , V_11 ) ;
return V_11 ;
}
}
return 0 ;
}
