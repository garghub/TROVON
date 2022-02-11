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
static inline T_1 F_5 ( const struct V_1 * V_2 ,
int V_4 )
{
int V_17 ;
T_1 V_7 ;
for ( V_17 = 0 ; V_17 < F_6 ( V_18 ) ; ++ V_17 ) {
if ( V_4 == V_18 [ V_17 ] )
break;
}
if ( V_17 == F_6 ( V_18 ) )
return - V_19 ;
V_7 = F_7 ( V_2 , V_20 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 &= ~ V_21 ;
V_7 |= V_22 << V_23 ;
V_7 &= ~ V_24 ;
V_7 |= V_17 << V_25 ;
V_7 = F_1 ( V_2 , V_20 , V_7 ) ;
return V_7 ;
}
static int F_8 ( struct V_26 * V_6 , bool V_27 )
{
unsigned long V_28 ;
if ( ! V_6 -> V_29 )
return 0 ;
F_9 ( & V_6 -> V_2 -> V_8 ) ;
if ( V_27 ) {
V_28 = V_30 ;
if ( F_10 ( V_28 , V_6 -> V_31 ) &&
F_11 ( F_12 (
V_6 -> V_31 - V_28 ) ) != 0 ) {
F_13 ( & V_6 -> V_2 -> V_8 ) ;
return - V_32 ;
}
}
return 0 ;
}
static void F_14 ( struct V_26 * V_6 )
{
if ( ! V_6 -> V_29 )
return;
F_15 ( & V_6 -> V_2 -> V_8 ) ;
F_13 ( & V_6 -> V_2 -> V_8 ) ;
}
static inline int F_8 ( struct V_26 * V_6 , bool V_27 )
{
return 0 ;
}
static inline void F_14 ( struct V_26 * V_6 )
{
}
static int F_16 ( struct V_33 * V_34 ,
struct V_35 const * V_36 , int * V_37 ,
int * V_38 , long V_39 )
{
struct V_26 * V_6 = F_17 ( V_34 ) ;
T_2 V_40 ;
T_1 V_7 ;
switch ( V_39 ) {
case V_41 :
switch ( V_36 -> V_42 ) {
case V_43 :
V_40 = V_44 ;
break;
case V_45 :
switch ( V_36 -> V_36 ) {
case 0 :
V_40 = V_46 ;
break;
case 1 :
V_40 = V_47 ;
break;
default:
return - V_19 ;
}
break;
default:
return - V_19 ;
}
V_7 = F_8 ( V_6 , true ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_6 -> V_2 , V_40 ) ;
F_14 ( V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_7 & 0x8000 )
return - V_48 ;
* V_37 = V_7 ;
return V_49 ;
case V_50 :
* V_37 = V_51 ;
* V_38 = V_52 ;
return V_53 ;
case V_54 :
* V_37 = V_55 ;
return V_49 ;
case V_56 :
F_8 ( V_6 , false ) ;
F_18 ( & V_6 -> V_57 ) ;
V_7 = F_7 ( V_6 -> V_2 ,
V_58 ) ;
F_19 ( & V_6 -> V_57 ) ;
F_14 ( V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_7 == V_59 ) {
* V_37 = 1 ;
* V_38 = 0 ;
} else {
* V_37 = 0 ;
* V_38 = V_7 * V_60 ;
}
return V_61 ;
case V_62 :
F_8 ( V_6 , false ) ;
F_18 ( & V_6 -> V_57 ) ;
V_7 = F_7 ( V_6 -> V_2 , V_20 ) ;
F_19 ( & V_6 -> V_57 ) ;
F_14 ( V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_37 = V_18 [ V_7 & V_24 ] / 100 ;
* V_38 = ( V_18 [ V_7 & V_24 ] % 100 ) *
10000 ;
return V_53 ;
default:
return - V_19 ;
}
}
static int F_20 ( struct V_33 * V_34 ,
struct V_35 const * V_36 , int V_37 ,
int V_38 , long V_39 )
{
struct V_26 * V_6 = F_17 ( V_34 ) ;
T_1 V_7 ;
switch ( V_39 ) {
case V_56 :
if ( V_37 < 0 || V_38 < 0 || V_37 > 1 || ( V_37 == 1 && V_38 != 0 ) )
return - V_19 ;
V_37 = V_37 * V_59 +
V_38 / V_60 ;
F_8 ( V_6 , false ) ;
F_18 ( & V_6 -> V_57 ) ;
V_7 = F_1 ( V_6 -> V_2 , V_58 ,
V_37 ) ;
F_19 ( & V_6 -> V_57 ) ;
F_14 ( V_6 ) ;
return V_7 ;
case V_62 :
if ( V_37 < 0 || V_38 < 0 )
return - V_19 ;
F_8 ( V_6 , false ) ;
F_18 ( & V_6 -> V_57 ) ;
V_7 = F_5 ( V_6 -> V_2 ,
V_37 * 100 + V_38 / 10000 ) ;
F_19 ( & V_6 -> V_57 ) ;
F_14 ( V_6 ) ;
return V_7 ;
default:
return - V_19 ;
}
}
static int F_21 ( struct V_33 * V_34 ,
struct V_35 const * V_36 ,
long V_39 )
{
switch ( V_39 ) {
case V_56 :
return V_61 ;
case V_62 :
return V_53 ;
default:
return - V_19 ;
}
}
static int F_22 ( struct V_26 * V_6 )
{
T_1 V_7 ;
if ( ! V_6 -> V_29 ) {
F_2 ( & V_6 -> V_2 -> V_8 , L_2 ) ;
return - V_63 ;
}
F_2 ( & V_6 -> V_2 -> V_8 , L_3 ) ;
F_18 ( & V_6 -> V_57 ) ;
V_7 = F_3 ( V_6 -> V_2 -> V_10 , V_6 -> V_2 -> V_11 ,
V_6 -> V_2 -> V_12 | V_13 ,
V_14 , V_64 ,
V_65 , NULL ) ;
F_19 ( & V_6 -> V_57 ) ;
return V_7 ;
}
static int F_23 ( struct V_26 * V_6 )
{
if ( ! V_6 -> V_29 ) {
F_2 ( & V_6 -> V_2 -> V_8 , L_4 ) ;
return - V_63 ;
}
F_2 ( & V_6 -> V_2 -> V_8 , L_5 ) ;
F_24 ( V_6 -> V_2 -> V_10 ) ;
F_25 ( V_6 -> V_29 , 0 ) ;
F_4 ( V_66 ) ;
F_26 ( V_6 -> V_29 ) ;
F_27 ( V_6 -> V_2 -> V_10 ) ;
V_6 -> V_31 = V_30 +
F_28 ( V_67 ) ;
F_7 ( V_6 -> V_2 , V_20 ) ;
return 0 ;
}
static struct V_68 * F_29 ( struct V_1 * V_2 )
{
struct V_68 * V_69 ;
if ( ! F_30 ( V_2 -> V_10 ,
V_70 ) ) {
F_31 ( & V_2 -> V_8 ,
L_6 ) ;
return NULL ;
}
V_69 = F_32 ( & V_2 -> V_8 , L_7 , V_71 ) ;
if ( F_33 ( V_69 ) ) {
F_34 ( & V_2 -> V_8 ,
L_8 ,
F_35 ( V_69 ) ) ;
return NULL ;
} else if ( ! V_69 ) {
F_31 ( & V_2 -> V_8 ,
L_9 ) ;
}
return V_69 ;
}
static inline int F_22 ( struct V_26 * V_6 )
{
return - V_63 ;
}
static inline int F_23 ( struct V_26 * V_6 )
{
return - V_63 ;
}
static inline struct V_68 * F_29 ( struct V_1 * V_2 )
{
return NULL ;
}
static int F_36 ( struct V_1 * V_2 )
{
T_1 V_7 ;
V_7 = F_7 ( V_2 , V_20 ) ;
if ( V_7 < 0 )
return V_7 ;
return ( V_7 & V_72 ) ? 1 : 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
const struct V_73 * V_74 )
{
struct V_33 * V_34 ;
struct V_26 * V_6 ;
int V_7 ;
if ( ! F_30 ( V_2 -> V_10 , V_75 ) )
return - V_76 ;
V_34 = F_38 ( & V_2 -> V_8 , sizeof( * V_6 ) ) ;
if ( ! V_34 )
return - V_77 ;
V_6 = F_17 ( V_34 ) ;
F_39 ( V_2 , V_34 ) ;
V_6 -> V_2 = V_2 ;
F_40 ( & V_6 -> V_57 ) ;
V_6 -> V_29 = F_29 ( V_2 ) ;
F_23 ( V_6 ) ;
V_34 -> V_8 . V_78 = & V_2 -> V_8 ;
V_34 -> V_79 = V_74 -> V_79 ;
V_34 -> V_80 = V_81 ;
V_34 -> V_82 = & V_83 ;
V_7 = F_36 ( V_2 ) ;
switch ( V_7 ) {
case 0 :
F_2 ( & V_2 -> V_8 , L_10 ) ;
V_34 -> V_84 = V_85 ;
V_34 -> V_86 = 2 ;
break;
case 1 :
F_2 ( & V_2 -> V_8 , L_11 ) ;
V_34 -> V_84 = V_85 ;
V_34 -> V_86 = 3 ;
break;
default:
return V_7 ;
}
if ( V_6 -> V_29 ) {
F_41 ( & V_2 -> V_8 ,
V_87 ) ;
F_42 ( & V_2 -> V_8 ) ;
F_43 ( & V_2 -> V_8 ) ;
F_44 ( & V_2 -> V_8 ) ;
}
return F_45 ( V_34 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = F_47 ( V_2 ) ;
struct V_26 * V_6 = F_17 ( V_34 ) ;
F_48 ( V_34 ) ;
if ( V_6 -> V_29 ) {
F_49 ( & V_2 -> V_8 ) ;
if ( ! F_50 ( & V_2 -> V_8 ) )
F_22 ( V_6 ) ;
F_51 ( & V_2 -> V_8 ) ;
}
return 0 ;
}
static int F_52 ( struct V_88 * V_8 )
{
struct V_33 * V_34 = F_47 ( F_53 ( V_8 ) ) ;
struct V_26 * V_6 = F_17 ( V_34 ) ;
if ( V_6 -> V_29 && F_54 ( V_8 ) )
return F_22 ( V_6 ) ;
return 0 ;
}
static int F_55 ( struct V_88 * V_8 )
{
struct V_33 * V_34 = F_47 ( F_53 ( V_8 ) ) ;
struct V_26 * V_6 = F_17 ( V_34 ) ;
int V_89 ;
if ( V_6 -> V_29 ) {
V_89 = F_23 ( V_6 ) ;
if ( V_89 < 0 )
return V_89 ;
F_49 ( V_8 ) ;
F_43 ( V_8 ) ;
F_44 ( V_8 ) ;
}
return 0 ;
}
static int F_56 ( struct V_88 * V_8 )
{
struct V_33 * V_34 = F_47 ( F_53 ( V_8 ) ) ;
struct V_26 * V_6 = F_17 ( V_34 ) ;
return F_22 ( V_6 ) ;
}
static int F_57 ( struct V_88 * V_8 )
{
struct V_33 * V_34 = F_47 ( F_53 ( V_8 ) ) ;
struct V_26 * V_6 = F_17 ( V_34 ) ;
return F_23 ( V_6 ) ;
}
