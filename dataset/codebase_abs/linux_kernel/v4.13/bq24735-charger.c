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
return F_5 ( V_8 , V_9 , V_10 ) ;
}
static inline int F_6 ( struct V_7 * V_8 , T_1 V_9 )
{
return F_7 ( V_8 , V_9 ) ;
}
static int F_8 ( struct V_7 * V_8 , T_1 V_9 ,
T_2 V_11 , T_2 V_10 )
{
unsigned int V_12 ;
int V_13 ;
V_13 = F_6 ( V_8 , V_9 ) ;
if ( V_13 < 0 )
return V_13 ;
V_12 = V_13 & ~ V_11 ;
V_12 |= V_10 & V_11 ;
return F_4 ( V_8 , V_9 , V_12 ) ;
}
static int F_9 ( struct V_1 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
int V_13 ;
T_2 V_10 ;
if ( V_16 -> V_17 )
return 0 ;
if ( V_16 -> V_18 ) {
V_10 = V_16 -> V_18 & V_19 ;
V_13 = F_4 ( V_14 -> V_8 ,
V_20 , V_10 ) ;
if ( V_13 < 0 ) {
F_10 ( & V_14 -> V_8 -> V_21 ,
L_1 ,
V_13 ) ;
return V_13 ;
}
}
if ( V_16 -> V_22 ) {
V_10 = V_16 -> V_22 & V_23 ;
V_13 = F_4 ( V_14 -> V_8 ,
V_24 , V_10 ) ;
if ( V_13 < 0 ) {
F_10 ( & V_14 -> V_8 -> V_21 ,
L_2 ,
V_13 ) ;
return V_13 ;
}
}
if ( V_16 -> V_25 ) {
V_10 = V_16 -> V_25 & V_26 ;
V_13 = F_4 ( V_14 -> V_8 ,
V_27 , V_10 ) ;
if ( V_13 < 0 ) {
F_10 ( & V_14 -> V_8 -> V_21 ,
L_3 ,
V_13 ) ;
return V_13 ;
}
}
return 0 ;
}
static inline int F_11 ( struct V_1 * V_14 )
{
int V_13 ;
if ( V_14 -> V_16 -> V_17 )
return 0 ;
V_13 = F_9 ( V_14 ) ;
if ( V_13 )
return V_13 ;
return F_8 ( V_14 -> V_8 , V_28 ,
V_29 , 0 ) ;
}
static inline int F_12 ( struct V_1 * V_14 )
{
if ( V_14 -> V_16 -> V_17 )
return 0 ;
return F_8 ( V_14 -> V_8 , V_28 ,
V_29 ,
V_29 ) ;
}
static bool F_13 ( struct V_1 * V_14 )
{
if ( V_14 -> V_30 ) {
return ! F_14 ( V_14 -> V_30 ) ;
} else {
int V_31 = 0 ;
V_31 = F_6 ( V_14 -> V_8 , V_28 ) ;
if ( V_31 < 0 ) {
F_15 ( & V_14 -> V_8 -> V_21 ,
L_4 ,
V_31 ) ;
return false ;
}
return ( V_31 & V_32 ) ? true : false ;
}
return false ;
}
static int F_16 ( struct V_1 * V_14 )
{
int V_13 ;
if ( ! F_13 ( V_14 ) )
return 0 ;
V_13 = F_6 ( V_14 -> V_8 , V_28 ) ;
if ( V_13 < 0 )
return V_13 ;
return ! ( V_13 & V_29 ) ;
}
static void F_17 ( struct V_1 * V_14 )
{
F_18 ( & V_14 -> V_33 ) ;
if ( V_14 -> V_34 && F_13 ( V_14 ) )
F_11 ( V_14 ) ;
else
F_12 ( V_14 ) ;
F_19 ( & V_14 -> V_33 ) ;
F_20 ( V_14 -> V_14 ) ;
}
static T_3 F_21 ( int V_35 , void * V_36 )
{
struct V_2 * V_3 = V_36 ;
struct V_1 * V_14 = F_1 ( V_3 ) ;
F_17 ( V_14 ) ;
return V_37 ;
}
static void F_22 ( struct V_38 * V_39 )
{
struct V_1 * V_14 = F_23 ( V_39 , struct V_1 , V_40 . V_39 ) ;
F_17 ( V_14 ) ;
F_24 ( & V_14 -> V_40 ,
F_25 ( V_14 -> V_41 ) ) ;
}
static int F_26 ( struct V_2 * V_3 ,
enum V_4 V_5 ,
union V_42 * V_43 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
switch ( V_5 ) {
case V_44 :
V_43 -> V_45 = F_13 ( V_14 ) ? 1 : 0 ;
break;
case V_6 :
switch ( F_16 ( V_14 ) ) {
case 1 :
V_43 -> V_45 = V_46 ;
break;
case 0 :
V_43 -> V_45 = V_47 ;
break;
default:
V_43 -> V_45 = V_48 ;
break;
}
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_27 ( struct V_2 * V_3 ,
enum V_4 V_5 ,
const union V_42 * V_43 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
int V_13 ;
switch ( V_5 ) {
case V_6 :
switch ( V_43 -> V_45 ) {
case V_46 :
F_18 ( & V_14 -> V_33 ) ;
V_14 -> V_34 = true ;
V_13 = F_11 ( V_14 ) ;
F_19 ( & V_14 -> V_33 ) ;
if ( V_13 )
return V_13 ;
break;
case V_50 :
case V_47 :
F_18 ( & V_14 -> V_33 ) ;
V_14 -> V_34 = false ;
V_13 = F_12 ( V_14 ) ;
F_19 ( & V_14 -> V_33 ) ;
if ( V_13 )
return V_13 ;
break;
default:
return - V_49 ;
}
F_20 ( V_3 ) ;
break;
default:
return - V_51 ;
}
return 0 ;
}
static struct V_15 * F_28 ( struct V_7 * V_8 )
{
struct V_15 * V_16 ;
struct V_52 * V_53 = V_8 -> V_21 . V_54 ;
T_4 V_43 ;
int V_13 ;
V_16 = F_29 ( & V_8 -> V_21 , sizeof( * V_16 ) , V_55 ) ;
if ( ! V_16 ) {
F_10 ( & V_8 -> V_21 ,
L_5 ) ;
return NULL ;
}
V_13 = F_30 ( V_53 , L_6 , & V_43 ) ;
if ( ! V_13 )
V_16 -> V_18 = V_43 ;
V_13 = F_30 ( V_53 , L_7 , & V_43 ) ;
if ( ! V_13 )
V_16 -> V_22 = V_43 ;
V_13 = F_30 ( V_53 , L_8 , & V_43 ) ;
if ( ! V_13 )
V_16 -> V_25 = V_43 ;
V_16 -> V_17 = F_31 ( V_53 , L_9 ) ;
return V_16 ;
}
static int F_32 ( struct V_7 * V_8 ,
const struct V_56 * V_57 )
{
int V_13 ;
struct V_1 * V_14 ;
struct V_58 * V_59 ;
struct V_60 V_61 = {} ;
char * V_62 ;
V_14 = F_29 ( & V_8 -> V_21 , sizeof( * V_14 ) , V_55 ) ;
if ( ! V_14 )
return - V_63 ;
F_33 ( & V_14 -> V_33 ) ;
V_14 -> V_34 = true ;
V_14 -> V_16 = V_8 -> V_21 . V_64 ;
if ( F_34 ( V_65 ) && ! V_14 -> V_16 && V_8 -> V_21 . V_54 )
V_14 -> V_16 = F_28 ( V_8 ) ;
if ( ! V_14 -> V_16 ) {
F_10 ( & V_8 -> V_21 , L_10 ) ;
return - V_49 ;
}
V_62 = ( char * ) V_14 -> V_16 -> V_62 ;
if ( ! V_62 ) {
V_62 = F_35 ( & V_8 -> V_21 , V_55 ,
L_11 ,
F_36 ( & V_8 -> V_21 ) ) ;
if ( ! V_62 ) {
F_10 ( & V_8 -> V_21 , L_12 ) ;
return - V_63 ;
}
}
V_14 -> V_8 = V_8 ;
V_59 = & V_14 -> V_66 ;
V_59 -> V_62 = V_62 ;
V_59 -> type = V_67 ;
V_59 -> V_68 = V_69 ;
V_59 -> V_70 = F_37 ( V_69 ) ;
V_59 -> V_71 = F_26 ;
V_59 -> V_72 = F_27 ;
V_59 -> V_73 =
F_3 ;
V_61 . V_74 = V_14 -> V_16 -> V_74 ;
V_61 . V_75 = V_14 -> V_16 -> V_75 ;
V_61 . V_54 = V_8 -> V_21 . V_54 ;
V_61 . V_76 = V_14 ;
F_38 ( V_8 , V_14 ) ;
V_14 -> V_30 = F_39 ( & V_8 -> V_21 ,
L_13 ,
V_77 ) ;
if ( F_40 ( V_14 -> V_30 ) ) {
V_13 = F_41 ( V_14 -> V_30 ) ;
F_10 ( & V_8 -> V_21 , L_14 , V_13 ) ;
return V_13 ;
}
if ( F_13 ( V_14 ) ) {
V_13 = F_6 ( V_8 , V_78 ) ;
if ( V_13 < 0 ) {
F_10 ( & V_8 -> V_21 , L_15 ,
V_13 ) ;
return V_13 ;
} else if ( V_13 != 0x0040 ) {
F_10 ( & V_8 -> V_21 ,
L_16 , V_13 ) ;
return - V_79 ;
}
V_13 = F_6 ( V_8 , V_80 ) ;
if ( V_13 < 0 ) {
F_10 ( & V_8 -> V_21 , L_17 , V_13 ) ;
return V_13 ;
} else if ( V_13 != 0x000B ) {
F_10 ( & V_8 -> V_21 ,
L_18 , V_13 ) ;
return - V_79 ;
}
V_13 = F_11 ( V_14 ) ;
if ( V_13 < 0 ) {
F_10 ( & V_8 -> V_21 , L_19 ) ;
return V_13 ;
}
}
V_14 -> V_14 = F_42 ( & V_8 -> V_21 , V_59 ,
& V_61 ) ;
if ( F_40 ( V_14 -> V_14 ) ) {
V_13 = F_41 ( V_14 -> V_14 ) ;
F_10 ( & V_8 -> V_21 , L_20 ,
V_13 ) ;
return V_13 ;
}
if ( V_8 -> V_35 ) {
V_13 = F_43 ( & V_8 -> V_21 , V_8 -> V_35 ,
NULL , F_21 ,
V_81 |
V_82 |
V_83 ,
V_59 -> V_62 ,
V_14 -> V_14 ) ;
if ( V_13 ) {
F_10 ( & V_8 -> V_21 ,
L_21 ,
V_8 -> V_35 , V_13 ) ;
return V_13 ;
}
} else {
V_13 = F_44 ( & V_8 -> V_21 , L_22 ,
& V_14 -> V_41 ) ;
if ( V_13 )
return 0 ;
if ( ! V_14 -> V_41 )
return 0 ;
F_45 ( & V_14 -> V_40 , F_22 ) ;
F_24 ( & V_14 -> V_40 ,
F_25 ( V_14 -> V_41 ) ) ;
}
return 0 ;
}
static int F_46 ( struct V_7 * V_8 )
{
struct V_1 * V_14 = F_47 ( V_8 ) ;
if ( V_14 -> V_41 )
F_48 ( & V_14 -> V_40 ) ;
return 0 ;
}
