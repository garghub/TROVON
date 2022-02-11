static T_1 F_1 ( const struct V_1 * V_2 , T_2 V_3 ,
T_3 V_4 )
{
union V_5 V_6 ;
T_1 V_7 ;
F_2 ( & V_2 -> V_8 , L_1 , V_4 , V_3 ) ;
V_6 . V_9 = 0x0000 ;
V_7 = F_3 ( V_2 -> V_10 , V_2 -> V_11 ,
V_2 -> V_12 | V_13 ,
V_14 , V_3 ,
V_15 , & V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
F_4 ( V_16 ) ;
V_6 . V_9 = V_4 ;
V_7 = F_3 ( V_2 -> V_10 , V_2 -> V_11 ,
V_2 -> V_12 | V_13 ,
V_14 , V_3 ,
V_15 , & V_6 ) ;
F_4 ( V_16 ) ;
return V_7 ;
}
static int F_5 ( struct V_17 * V_6 , bool V_18 )
{
unsigned long V_19 ;
if ( ! V_6 -> V_20 )
return 0 ;
F_6 ( & V_6 -> V_2 -> V_8 ) ;
if ( V_18 ) {
V_19 = V_21 ;
if ( F_7 ( V_19 , V_6 -> V_22 ) &&
F_8 ( F_9 (
V_6 -> V_22 - V_19 ) ) != 0 ) {
F_10 ( & V_6 -> V_2 -> V_8 ) ;
return - V_23 ;
}
}
return 0 ;
}
static void F_11 ( struct V_17 * V_6 )
{
if ( ! V_6 -> V_20 )
return;
F_12 ( & V_6 -> V_2 -> V_8 ) ;
F_10 ( & V_6 -> V_2 -> V_8 ) ;
}
static inline int F_5 ( struct V_17 * V_6 , bool V_18 )
{
return 0 ;
}
static inline void F_11 ( struct V_17 * V_6 )
{
}
static int F_13 ( struct V_24 * V_25 ,
struct V_26 const * V_27 , int * V_28 ,
int * V_29 , long V_30 )
{
struct V_17 * V_6 = F_14 ( V_25 ) ;
T_2 V_31 ;
T_1 V_7 ;
switch ( V_30 ) {
case V_32 :
switch ( V_27 -> V_33 ) {
case V_34 :
V_31 = V_35 ;
break;
case V_36 :
switch ( V_27 -> V_27 ) {
case 0 :
V_31 = V_37 ;
break;
case 1 :
V_31 = V_38 ;
break;
default:
return - V_39 ;
}
break;
default:
return - V_39 ;
}
V_7 = F_5 ( V_6 , true ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_15 ( V_6 -> V_2 , V_31 ) ;
F_11 ( V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_7 & 0x8000 )
return - V_40 ;
* V_28 = V_7 ;
return V_41 ;
case V_42 :
* V_28 = V_43 ;
* V_29 = V_44 ;
return V_45 ;
case V_46 :
* V_28 = V_47 ;
return V_41 ;
case V_48 :
F_5 ( V_6 , false ) ;
F_16 ( & V_6 -> V_49 ) ;
V_7 = F_15 ( V_6 -> V_2 ,
V_50 ) ;
F_17 ( & V_6 -> V_49 ) ;
F_11 ( V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_7 == V_51 ) {
* V_28 = 1 ;
* V_29 = 0 ;
} else {
* V_28 = 0 ;
* V_29 = V_7 * V_52 ;
}
return V_53 ;
default:
return - V_39 ;
}
}
static int F_18 ( struct V_24 * V_25 ,
struct V_26 const * V_27 , int V_28 ,
int V_29 , long V_30 )
{
struct V_17 * V_6 = F_14 ( V_25 ) ;
T_1 V_7 ;
switch ( V_30 ) {
case V_48 :
if ( V_28 < 0 || V_29 < 0 || V_28 > 1 || ( V_28 == 1 && V_29 != 0 ) )
return - V_39 ;
V_28 = V_28 * V_51 +
V_29 / V_52 ;
F_5 ( V_6 , false ) ;
F_16 ( & V_6 -> V_49 ) ;
V_7 = F_1 ( V_6 -> V_2 , V_50 ,
V_28 ) ;
F_17 ( & V_6 -> V_49 ) ;
F_11 ( V_6 ) ;
return V_7 ;
default:
return - V_39 ;
}
}
static int F_19 ( struct V_24 * V_25 ,
struct V_26 const * V_27 ,
long V_30 )
{
switch ( V_30 ) {
case V_48 :
return V_53 ;
default:
return - V_39 ;
}
}
static int F_20 ( struct V_17 * V_6 )
{
T_1 V_7 ;
if ( ! V_6 -> V_20 ) {
F_2 ( & V_6 -> V_2 -> V_8 , L_2 ) ;
return - V_54 ;
}
F_2 ( & V_6 -> V_2 -> V_8 , L_3 ) ;
F_16 ( & V_6 -> V_49 ) ;
V_7 = F_3 ( V_6 -> V_2 -> V_10 , V_6 -> V_2 -> V_11 ,
V_6 -> V_2 -> V_12 | V_13 ,
V_14 , V_55 ,
V_56 , NULL ) ;
F_17 ( & V_6 -> V_49 ) ;
return V_7 ;
}
static int F_21 ( struct V_17 * V_6 )
{
if ( ! V_6 -> V_20 ) {
F_2 ( & V_6 -> V_2 -> V_8 , L_4 ) ;
return - V_54 ;
}
F_2 ( & V_6 -> V_2 -> V_8 , L_5 ) ;
F_22 ( V_6 -> V_2 -> V_10 ) ;
F_23 ( V_6 -> V_20 , 0 ) ;
F_4 ( V_57 ) ;
F_24 ( V_6 -> V_20 ) ;
F_25 ( V_6 -> V_2 -> V_10 ) ;
V_6 -> V_22 = V_21 +
F_26 ( V_58 ) ;
F_15 ( V_6 -> V_2 , V_59 ) ;
return 0 ;
}
static struct V_60 * F_27 ( struct V_1 * V_2 )
{
struct V_60 * V_61 ;
if ( ! F_28 ( V_2 -> V_10 ,
V_62 ) ) {
F_29 ( & V_2 -> V_8 ,
L_6 ) ;
return NULL ;
}
V_61 = F_30 ( & V_2 -> V_8 , L_7 , V_63 ) ;
if ( F_31 ( V_61 ) ) {
F_32 ( & V_2 -> V_8 ,
L_8 ,
F_33 ( V_61 ) ) ;
return NULL ;
} else if ( ! V_61 ) {
F_29 ( & V_2 -> V_8 ,
L_9 ) ;
}
return V_61 ;
}
static inline int F_20 ( struct V_17 * V_6 )
{
return - V_54 ;
}
static inline int F_21 ( struct V_17 * V_6 )
{
return - V_54 ;
}
static inline struct V_60 * F_27 ( struct V_1 * V_2 )
{
return NULL ;
}
static int F_34 ( struct V_1 * V_2 )
{
T_1 V_7 ;
V_7 = F_15 ( V_2 , V_59 ) ;
if ( V_7 < 0 )
return V_7 ;
return ( V_7 & V_64 ) ? 1 : 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
const struct V_65 * V_66 )
{
struct V_24 * V_25 ;
struct V_17 * V_6 ;
int V_7 ;
if ( ! F_28 ( V_2 -> V_10 , V_67 ) )
return - V_68 ;
V_25 = F_36 ( & V_2 -> V_8 , sizeof( * V_6 ) ) ;
if ( ! V_25 )
return - V_69 ;
V_6 = F_14 ( V_25 ) ;
F_37 ( V_2 , V_25 ) ;
V_6 -> V_2 = V_2 ;
F_38 ( & V_6 -> V_49 ) ;
V_6 -> V_20 = F_27 ( V_2 ) ;
F_21 ( V_6 ) ;
V_25 -> V_8 . V_70 = & V_2 -> V_8 ;
V_25 -> V_71 = V_66 -> V_71 ;
V_25 -> V_72 = V_73 ;
V_25 -> V_74 = & V_75 ;
V_7 = F_34 ( V_2 ) ;
switch ( V_7 ) {
case 0 :
F_2 ( & V_2 -> V_8 , L_10 ) ;
V_25 -> V_76 = V_77 ;
V_25 -> V_78 = 2 ;
break;
case 1 :
F_2 ( & V_2 -> V_8 , L_11 ) ;
V_25 -> V_76 = V_77 ;
V_25 -> V_78 = 3 ;
break;
default:
return V_7 ;
}
if ( V_6 -> V_20 ) {
F_39 ( & V_2 -> V_8 ,
V_79 ) ;
F_40 ( & V_2 -> V_8 ) ;
F_41 ( & V_2 -> V_8 ) ;
F_42 ( & V_2 -> V_8 ) ;
}
return F_43 ( V_25 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_45 ( V_2 ) ;
struct V_17 * V_6 = F_14 ( V_25 ) ;
F_46 ( V_25 ) ;
if ( V_6 -> V_20 ) {
F_47 ( & V_2 -> V_8 ) ;
if ( ! F_48 ( & V_2 -> V_8 ) )
F_20 ( V_6 ) ;
F_49 ( & V_2 -> V_8 ) ;
}
return 0 ;
}
static int F_50 ( struct V_80 * V_8 )
{
struct V_24 * V_25 = F_45 ( F_51 ( V_8 ) ) ;
struct V_17 * V_6 = F_14 ( V_25 ) ;
if ( V_6 -> V_20 && F_52 ( V_8 ) )
return F_20 ( V_6 ) ;
return 0 ;
}
static int F_53 ( struct V_80 * V_8 )
{
struct V_24 * V_25 = F_45 ( F_51 ( V_8 ) ) ;
struct V_17 * V_6 = F_14 ( V_25 ) ;
int V_81 ;
if ( V_6 -> V_20 ) {
V_81 = F_21 ( V_6 ) ;
if ( V_81 < 0 )
return V_81 ;
F_47 ( V_8 ) ;
F_41 ( V_8 ) ;
F_42 ( V_8 ) ;
}
return 0 ;
}
static int F_54 ( struct V_80 * V_8 )
{
struct V_24 * V_25 = F_45 ( F_51 ( V_8 ) ) ;
struct V_17 * V_6 = F_14 ( V_25 ) ;
return F_20 ( V_6 ) ;
}
static int F_55 ( struct V_80 * V_8 )
{
struct V_24 * V_25 = F_45 ( F_51 ( V_8 ) ) ;
struct V_17 * V_6 = F_14 ( V_25 ) ;
return F_21 ( V_6 ) ;
}
