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
if ( V_14 -> V_30 ) {
return ! F_15 ( V_14 -> V_30 ) ;
} else {
int V_31 = 0 ;
V_31 = F_7 ( V_14 -> V_8 , V_17 ) ;
if ( V_31 < 0 ) {
F_13 ( & V_14 -> V_8 -> V_23 ,
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
int V_11 ;
if ( ! F_14 ( V_14 ) )
return 0 ;
V_11 = F_7 ( V_14 -> V_8 , V_17 ) ;
if ( V_11 < 0 )
return V_11 ;
return ! ( V_11 & V_18 ) ;
}
static T_4 F_17 ( int V_33 , void * V_34 )
{
struct V_2 * V_3 = V_34 ;
struct V_1 * V_14 = F_1 ( V_3 ) ;
F_18 ( & V_14 -> V_35 ) ;
if ( V_14 -> V_36 && F_14 ( V_14 ) )
F_10 ( V_14 ) ;
else
F_11 ( V_14 ) ;
F_19 ( & V_14 -> V_35 ) ;
F_20 ( V_3 ) ;
return V_37 ;
}
static int F_21 ( struct V_2 * V_3 ,
enum V_4 V_5 ,
union V_38 * V_39 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
switch ( V_5 ) {
case V_40 :
V_39 -> V_41 = F_14 ( V_14 ) ? 1 : 0 ;
break;
case V_6 :
switch ( F_16 ( V_14 ) ) {
case 1 :
V_39 -> V_41 = V_42 ;
break;
case 0 :
V_39 -> V_41 = V_43 ;
break;
default:
V_39 -> V_41 = V_44 ;
break;
}
break;
default:
return - V_45 ;
}
return 0 ;
}
static int F_22 ( struct V_2 * V_3 ,
enum V_4 V_5 ,
const union V_38 * V_39 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
int V_11 ;
switch ( V_5 ) {
case V_6 :
switch ( V_39 -> V_41 ) {
case V_42 :
F_18 ( & V_14 -> V_35 ) ;
V_14 -> V_36 = true ;
V_11 = F_10 ( V_14 ) ;
F_19 ( & V_14 -> V_35 ) ;
if ( V_11 )
return V_11 ;
F_12 ( V_14 ) ;
break;
case V_46 :
case V_43 :
F_18 ( & V_14 -> V_35 ) ;
V_14 -> V_36 = false ;
V_11 = F_11 ( V_14 ) ;
F_19 ( & V_14 -> V_35 ) ;
if ( V_11 )
return V_11 ;
break;
default:
return - V_45 ;
}
F_20 ( V_3 ) ;
break;
default:
return - V_47 ;
}
return 0 ;
}
static struct V_19 * F_23 ( struct V_7 * V_8 )
{
struct V_19 * V_15 ;
struct V_48 * V_49 = V_8 -> V_23 . V_50 ;
T_5 V_39 ;
int V_11 ;
V_15 = F_24 ( & V_8 -> V_23 , sizeof( * V_15 ) , V_51 ) ;
if ( ! V_15 ) {
F_13 ( & V_8 -> V_23 ,
L_5 ) ;
return NULL ;
}
V_11 = F_25 ( V_49 , L_6 , & V_39 ) ;
if ( ! V_11 )
V_15 -> V_20 = V_39 ;
V_11 = F_25 ( V_49 , L_7 , & V_39 ) ;
if ( ! V_11 )
V_15 -> V_24 = V_39 ;
V_11 = F_25 ( V_49 , L_8 , & V_39 ) ;
if ( ! V_11 )
V_15 -> V_27 = V_39 ;
V_15 -> V_16 = F_26 ( V_49 , L_9 ) ;
return V_15 ;
}
static int F_27 ( struct V_7 * V_8 ,
const struct V_52 * V_53 )
{
int V_11 ;
struct V_1 * V_14 ;
struct V_54 * V_55 ;
struct V_56 V_57 = {} ;
char * V_58 ;
V_14 = F_24 ( & V_8 -> V_23 , sizeof( * V_14 ) , V_51 ) ;
if ( ! V_14 )
return - V_59 ;
F_28 ( & V_14 -> V_35 ) ;
V_14 -> V_36 = true ;
V_14 -> V_15 = V_8 -> V_23 . V_60 ;
if ( F_29 ( V_61 ) && ! V_14 -> V_15 && V_8 -> V_23 . V_50 )
V_14 -> V_15 = F_23 ( V_8 ) ;
if ( ! V_14 -> V_15 ) {
F_13 ( & V_8 -> V_23 , L_10 ) ;
return - V_45 ;
}
V_58 = ( char * ) V_14 -> V_15 -> V_58 ;
if ( ! V_58 ) {
V_58 = F_30 ( & V_8 -> V_23 , V_51 ,
L_11 ,
F_31 ( & V_8 -> V_23 ) ) ;
if ( ! V_58 ) {
F_13 ( & V_8 -> V_23 , L_12 ) ;
return - V_59 ;
}
}
V_14 -> V_8 = V_8 ;
V_55 = & V_14 -> V_62 ;
V_55 -> V_58 = V_58 ;
V_55 -> type = V_63 ;
V_55 -> V_64 = V_65 ;
V_55 -> V_66 = F_32 ( V_65 ) ;
V_55 -> V_67 = F_21 ;
V_55 -> V_68 = F_22 ;
V_55 -> V_69 =
F_3 ;
V_57 . V_70 = V_14 -> V_15 -> V_70 ;
V_57 . V_71 = V_14 -> V_15 -> V_71 ;
V_57 . V_50 = V_8 -> V_23 . V_50 ;
V_57 . V_72 = V_14 ;
F_33 ( V_8 , V_14 ) ;
V_14 -> V_30 = F_34 ( & V_8 -> V_23 ,
L_13 ,
V_73 ) ;
if ( F_35 ( V_14 -> V_30 ) ) {
V_11 = F_36 ( V_14 -> V_30 ) ;
F_13 ( & V_8 -> V_23 , L_14 , V_11 ) ;
return V_11 ;
}
if ( ! V_14 -> V_30 || F_14 ( V_14 ) ) {
V_11 = F_7 ( V_8 , V_74 ) ;
if ( V_11 < 0 ) {
F_13 ( & V_8 -> V_23 , L_15 ,
V_11 ) ;
return V_11 ;
} else if ( V_11 != 0x0040 ) {
F_13 ( & V_8 -> V_23 ,
L_16 , V_11 ) ;
return - V_75 ;
}
V_11 = F_7 ( V_8 , V_76 ) ;
if ( V_11 < 0 ) {
F_13 ( & V_8 -> V_23 , L_17 , V_11 ) ;
return V_11 ;
} else if ( V_11 != 0x000B ) {
F_13 ( & V_8 -> V_23 ,
L_18 , V_11 ) ;
return - V_75 ;
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
V_14 -> V_14 = F_37 ( & V_8 -> V_23 , V_55 ,
& V_57 ) ;
if ( F_35 ( V_14 -> V_14 ) ) {
V_11 = F_36 ( V_14 -> V_14 ) ;
F_13 ( & V_8 -> V_23 , L_21 ,
V_11 ) ;
return V_11 ;
}
if ( V_8 -> V_33 ) {
V_11 = F_38 ( & V_8 -> V_23 , V_8 -> V_33 ,
NULL , F_17 ,
V_77 |
V_78 |
V_79 ,
V_55 -> V_58 ,
V_14 -> V_14 ) ;
if ( V_11 ) {
F_13 ( & V_8 -> V_23 ,
L_22 ,
V_8 -> V_33 , V_11 ) ;
return V_11 ;
}
}
return 0 ;
}
