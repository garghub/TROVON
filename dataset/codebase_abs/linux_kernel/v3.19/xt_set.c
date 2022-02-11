static inline int
F_1 ( T_1 V_1 , const struct V_2 * V_3 ,
const struct V_4 * V_5 ,
struct V_6 * V_7 , int V_8 )
{
if ( F_2 ( V_1 , V_3 , V_5 , V_7 ) )
V_8 = ! V_8 ;
return V_8 ;
}
static bool
F_3 ( const struct V_2 * V_3 , struct V_4 * V_5 )
{
const struct V_9 * V_10 = V_5 -> V_11 ;
F_4 ( V_7 , V_5 -> V_12 , V_10 -> F_1 . V_13 . V_14 . V_15 ,
V_10 -> F_1 . V_13 . V_14 . V_16 , 0 , V_17 ) ;
return F_1 ( V_10 -> F_1 . V_1 , V_3 , V_5 , & V_7 ,
V_10 -> F_1 . V_13 . V_14 . V_16 & V_18 ) ;
}
static void
F_5 ( struct V_19 * V_10 )
{
T_2 V_20 ;
V_10 -> V_13 . V_14 . V_15 = V_21 ;
if ( V_10 -> V_13 . V_16 [ 0 ] & V_22 )
V_10 -> V_13 . V_14 . V_16 |= V_18 ;
for ( V_20 = 0 ; V_20 < V_23 - 1 && V_10 -> V_13 . V_16 [ V_20 ] ; V_20 ++ ) {
V_10 -> V_13 . V_14 . V_15 ++ ;
if ( V_10 -> V_13 . V_16 [ V_20 ] & V_24 )
V_10 -> V_13 . V_14 . V_16 |= ( 1 << V_10 -> V_13 . V_14 . V_15 ) ;
}
}
static int
F_6 ( const struct V_25 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
T_1 V_1 ;
V_1 = F_7 ( V_5 -> V_26 , V_10 -> F_1 . V_1 ) ;
if ( V_1 == V_27 ) {
F_8 ( L_1 ,
V_10 -> F_1 . V_1 ) ;
return - V_28 ;
}
if ( V_10 -> F_1 . V_13 . V_16 [ V_23 - 1 ] != 0 ) {
F_8 ( L_2 ) ;
F_9 ( V_5 -> V_26 , V_10 -> F_1 . V_1 ) ;
return - V_29 ;
}
F_5 ( & V_10 -> F_1 ) ;
return 0 ;
}
static void
F_10 ( const struct V_30 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
F_9 ( V_5 -> V_26 , V_10 -> F_1 . V_1 ) ;
}
static bool
F_11 ( const struct V_2 * V_3 , struct V_4 * V_5 )
{
const struct V_31 * V_10 = V_5 -> V_11 ;
F_4 ( V_7 , V_5 -> V_12 , V_10 -> F_1 . V_15 ,
V_10 -> F_1 . V_16 , 0 , V_17 ) ;
if ( V_7 . V_16 & V_32 )
V_7 . V_33 |= V_34 ;
return F_1 ( V_10 -> F_1 . V_1 , V_3 , V_5 , & V_7 ,
V_10 -> F_1 . V_16 & V_18 ) ;
}
static int
F_12 ( const struct V_25 * V_5 )
{
struct V_31 * V_10 = V_5 -> V_11 ;
T_1 V_1 ;
V_1 = F_7 ( V_5 -> V_26 , V_10 -> F_1 . V_1 ) ;
if ( V_1 == V_27 ) {
F_8 ( L_1 ,
V_10 -> F_1 . V_1 ) ;
return - V_28 ;
}
if ( V_10 -> F_1 . V_15 > V_23 ) {
F_8 ( L_2 ) ;
F_9 ( V_5 -> V_26 , V_10 -> F_1 . V_1 ) ;
return - V_29 ;
}
return 0 ;
}
static void
F_13 ( const struct V_30 * V_5 )
{
struct V_31 * V_10 = V_5 -> V_11 ;
F_9 ( V_5 -> V_26 , V_10 -> F_1 . V_1 ) ;
}
static bool
F_14 ( T_3 V_35 , const struct V_36 * V_10 )
{
switch ( V_10 -> V_37 ) {
case V_38 :
return true ;
case V_39 :
return V_35 == V_10 -> V_40 ;
case V_41 :
return V_35 != V_10 -> V_40 ;
case V_42 :
return V_35 < V_10 -> V_40 ;
case V_43 :
return V_35 > V_10 -> V_40 ;
}
return false ;
}
static bool
F_15 ( const struct V_2 * V_3 , struct V_4 * V_5 )
{
const struct V_44 * V_10 = V_5 -> V_11 ;
F_4 ( V_7 , V_5 -> V_12 , V_10 -> F_1 . V_15 ,
V_10 -> F_1 . V_16 , V_10 -> V_16 , V_17 ) ;
int V_45 ;
if ( V_10 -> V_46 . V_37 != V_38 ||
V_10 -> V_47 . V_37 != V_38 )
V_7 . V_33 |= V_48 ;
V_45 = F_1 ( V_10 -> F_1 . V_1 , V_3 , V_5 , & V_7 ,
V_10 -> F_1 . V_16 & V_18 ) ;
if ( ! ( V_45 && V_7 . V_33 & V_48 ) )
return V_45 ;
if ( ! F_14 ( V_7 . V_49 . V_46 , & V_10 -> V_46 ) )
return 0 ;
return F_14 ( V_7 . V_49 . V_47 , & V_10 -> V_47 ) ;
}
static bool
F_16 ( T_3 V_35 , const struct V_50 * V_10 )
{
switch ( V_10 -> V_37 ) {
case V_38 :
return true ;
case V_39 :
return V_35 == V_10 -> V_40 ;
case V_41 :
return V_35 != V_10 -> V_40 ;
case V_42 :
return V_35 < V_10 -> V_40 ;
case V_43 :
return V_35 > V_10 -> V_40 ;
}
return false ;
}
static bool
F_17 ( const struct V_2 * V_3 , struct V_4 * V_5 )
{
const struct V_51 * V_10 = V_5 -> V_11 ;
F_4 ( V_7 , V_5 -> V_12 , V_10 -> F_1 . V_15 ,
V_10 -> F_1 . V_16 , V_10 -> V_16 , V_17 ) ;
int V_45 ;
if ( V_10 -> V_46 . V_37 != V_38 ||
V_10 -> V_47 . V_37 != V_38 )
V_7 . V_33 |= V_48 ;
V_45 = F_1 ( V_10 -> F_1 . V_1 , V_3 , V_5 , & V_7 ,
V_10 -> F_1 . V_16 & V_18 ) ;
if ( ! ( V_45 && V_7 . V_33 & V_48 ) )
return V_45 ;
if ( ! F_16 ( V_7 . V_49 . V_46 , & V_10 -> V_46 ) )
return 0 ;
return F_16 ( V_7 . V_49 . V_47 , & V_10 -> V_47 ) ;
}
static unsigned int
F_18 ( struct V_2 * V_3 , const struct V_4 * V_5 )
{
const struct V_52 * V_10 = V_5 -> V_53 ;
F_4 ( V_54 , V_5 -> V_12 , V_10 -> V_55 . V_13 . V_14 . V_15 ,
V_10 -> V_55 . V_13 . V_14 . V_16 , 0 , V_17 ) ;
F_4 ( V_56 , V_5 -> V_12 , V_10 -> V_57 . V_13 . V_14 . V_15 ,
V_10 -> V_57 . V_13 . V_14 . V_16 , 0 , V_17 ) ;
if ( V_10 -> V_55 . V_1 != V_27 )
F_19 ( V_10 -> V_55 . V_1 , V_3 , V_5 , & V_54 ) ;
if ( V_10 -> V_57 . V_1 != V_27 )
F_20 ( V_10 -> V_57 . V_1 , V_3 , V_5 , & V_56 ) ;
return V_58 ;
}
static int
F_21 ( const struct V_59 * V_5 )
{
struct V_52 * V_10 = V_5 -> V_53 ;
T_1 V_1 ;
if ( V_10 -> V_55 . V_1 != V_27 ) {
V_1 = F_7 ( V_5 -> V_26 , V_10 -> V_55 . V_1 ) ;
if ( V_1 == V_27 ) {
F_8 ( L_3 ,
V_10 -> V_55 . V_1 ) ;
return - V_28 ;
}
}
if ( V_10 -> V_57 . V_1 != V_27 ) {
V_1 = F_7 ( V_5 -> V_26 , V_10 -> V_57 . V_1 ) ;
if ( V_1 == V_27 ) {
F_8 ( L_4 ,
V_10 -> V_57 . V_1 ) ;
if ( V_10 -> V_55 . V_1 != V_27 )
F_9 ( V_5 -> V_26 , V_10 -> V_55 . V_1 ) ;
return - V_28 ;
}
}
if ( V_10 -> V_55 . V_13 . V_16 [ V_23 - 1 ] != 0 ||
V_10 -> V_57 . V_13 . V_16 [ V_23 - 1 ] != 0 ) {
F_8 ( L_5 ) ;
if ( V_10 -> V_55 . V_1 != V_27 )
F_9 ( V_5 -> V_26 , V_10 -> V_55 . V_1 ) ;
if ( V_10 -> V_57 . V_1 != V_27 )
F_9 ( V_5 -> V_26 , V_10 -> V_57 . V_1 ) ;
return - V_29 ;
}
F_5 ( & V_10 -> V_55 ) ;
F_5 ( & V_10 -> V_57 ) ;
return 0 ;
}
static void
F_22 ( const struct V_60 * V_5 )
{
const struct V_52 * V_10 = V_5 -> V_53 ;
if ( V_10 -> V_55 . V_1 != V_27 )
F_9 ( V_5 -> V_26 , V_10 -> V_55 . V_1 ) ;
if ( V_10 -> V_57 . V_1 != V_27 )
F_9 ( V_5 -> V_26 , V_10 -> V_57 . V_1 ) ;
}
static unsigned int
F_23 ( struct V_2 * V_3 , const struct V_4 * V_5 )
{
const struct V_61 * V_10 = V_5 -> V_53 ;
F_4 ( V_54 , V_5 -> V_12 , V_10 -> V_55 . V_15 ,
V_10 -> V_55 . V_16 , 0 , V_17 ) ;
F_4 ( V_56 , V_5 -> V_12 , V_10 -> V_57 . V_15 ,
V_10 -> V_57 . V_16 , 0 , V_17 ) ;
if ( V_10 -> V_55 . V_1 != V_27 )
F_19 ( V_10 -> V_55 . V_1 , V_3 , V_5 , & V_54 ) ;
if ( V_10 -> V_57 . V_1 != V_27 )
F_20 ( V_10 -> V_57 . V_1 , V_3 , V_5 , & V_56 ) ;
return V_58 ;
}
static int
F_24 ( const struct V_59 * V_5 )
{
const struct V_61 * V_10 = V_5 -> V_53 ;
T_1 V_1 ;
if ( V_10 -> V_55 . V_1 != V_27 ) {
V_1 = F_7 ( V_5 -> V_26 , V_10 -> V_55 . V_1 ) ;
if ( V_1 == V_27 ) {
F_8 ( L_3 ,
V_10 -> V_55 . V_1 ) ;
return - V_28 ;
}
}
if ( V_10 -> V_57 . V_1 != V_27 ) {
V_1 = F_7 ( V_5 -> V_26 , V_10 -> V_57 . V_1 ) ;
if ( V_1 == V_27 ) {
F_8 ( L_4 ,
V_10 -> V_57 . V_1 ) ;
if ( V_10 -> V_55 . V_1 != V_27 )
F_9 ( V_5 -> V_26 , V_10 -> V_55 . V_1 ) ;
return - V_28 ;
}
}
if ( V_10 -> V_55 . V_15 > V_23 ||
V_10 -> V_57 . V_15 > V_23 ) {
F_8 ( L_5 ) ;
if ( V_10 -> V_55 . V_1 != V_27 )
F_9 ( V_5 -> V_26 , V_10 -> V_55 . V_1 ) ;
if ( V_10 -> V_57 . V_1 != V_27 )
F_9 ( V_5 -> V_26 , V_10 -> V_57 . V_1 ) ;
return - V_29 ;
}
return 0 ;
}
static void
F_25 ( const struct V_60 * V_5 )
{
const struct V_61 * V_10 = V_5 -> V_53 ;
if ( V_10 -> V_55 . V_1 != V_27 )
F_9 ( V_5 -> V_26 , V_10 -> V_55 . V_1 ) ;
if ( V_10 -> V_57 . V_1 != V_27 )
F_9 ( V_5 -> V_26 , V_10 -> V_57 . V_1 ) ;
}
static unsigned int
F_26 ( struct V_2 * V_3 , const struct V_4 * V_5 )
{
const struct V_62 * V_10 = V_5 -> V_53 ;
F_4 ( V_54 , V_5 -> V_12 , V_10 -> V_55 . V_15 ,
V_10 -> V_55 . V_16 , V_10 -> V_16 , V_10 -> V_63 ) ;
F_4 ( V_56 , V_5 -> V_12 , V_10 -> V_57 . V_15 ,
V_10 -> V_57 . V_16 , 0 , V_17 ) ;
if ( V_54 . V_49 . V_63 != V_64 &&
V_54 . V_49 . V_63 > V_17 / V_65 )
V_54 . V_49 . V_63 = V_17 / V_65 ;
if ( V_10 -> V_55 . V_1 != V_27 )
F_19 ( V_10 -> V_55 . V_1 , V_3 , V_5 , & V_54 ) ;
if ( V_10 -> V_57 . V_1 != V_27 )
F_20 ( V_10 -> V_57 . V_1 , V_3 , V_5 , & V_56 ) ;
return V_58 ;
}
static unsigned int
F_27 ( struct V_2 * V_3 , const struct V_4 * V_5 )
{
const struct V_66 * V_10 = V_5 -> V_53 ;
F_4 ( V_54 , V_5 -> V_12 , V_10 -> V_55 . V_15 ,
V_10 -> V_55 . V_16 , V_10 -> V_16 , V_10 -> V_63 ) ;
F_4 ( V_56 , V_5 -> V_12 , V_10 -> V_57 . V_15 ,
V_10 -> V_57 . V_16 , 0 , V_17 ) ;
F_4 ( V_67 , V_5 -> V_12 , V_10 -> V_68 . V_15 ,
V_10 -> V_68 . V_16 , 0 , V_17 ) ;
int V_45 ;
if ( V_54 . V_49 . V_63 != V_64 &&
V_54 . V_49 . V_63 > V_17 / V_65 )
V_54 . V_49 . V_63 = V_17 / V_65 ;
if ( V_10 -> V_55 . V_1 != V_27 )
F_19 ( V_10 -> V_55 . V_1 , V_3 , V_5 , & V_54 ) ;
if ( V_10 -> V_57 . V_1 != V_27 )
F_20 ( V_10 -> V_57 . V_1 , V_3 , V_5 , & V_56 ) ;
if ( V_10 -> V_68 . V_1 != V_27 ) {
V_67 . V_33 |= V_10 -> V_16 & ( V_69 |
V_70 |
V_71 ) ;
V_45 = F_1 ( V_10 -> V_68 . V_1 , V_3 , V_5 , & V_67 ,
V_10 -> V_68 . V_16 & V_18 ) ;
if ( ! V_45 )
return V_58 ;
if ( V_67 . V_33 & V_69 )
V_3 -> V_72 = ( V_3 -> V_72 & ~ ( V_67 . V_49 . V_73 ) )
^ ( V_67 . V_49 . V_74 ) ;
if ( V_67 . V_33 & V_70 )
V_3 -> V_75 = V_67 . V_49 . V_76 ;
if ( ( V_67 . V_33 & V_71 ) &&
V_3 -> V_77 &&
V_3 -> V_77 -> V_78 > V_67 . V_49 . V_79 )
F_28 ( V_3 , V_67 . V_49 . V_79 ) ;
}
return V_58 ;
}
static int
F_29 ( const struct V_59 * V_5 )
{
const struct V_66 * V_10 = V_5 -> V_53 ;
T_1 V_1 ;
if ( V_10 -> V_55 . V_1 != V_27 ) {
V_1 = F_7 ( V_5 -> V_26 ,
V_10 -> V_55 . V_1 ) ;
if ( V_1 == V_27 ) {
F_8 ( L_3 ,
V_10 -> V_55 . V_1 ) ;
return - V_28 ;
}
}
if ( V_10 -> V_57 . V_1 != V_27 ) {
V_1 = F_7 ( V_5 -> V_26 ,
V_10 -> V_57 . V_1 ) ;
if ( V_1 == V_27 ) {
F_8 ( L_4 ,
V_10 -> V_57 . V_1 ) ;
if ( V_10 -> V_55 . V_1 != V_27 )
F_9 ( V_5 -> V_26 ,
V_10 -> V_55 . V_1 ) ;
return - V_28 ;
}
}
if ( V_10 -> V_68 . V_1 != V_27 ) {
if ( strncmp ( V_5 -> V_80 , L_6 , 7 ) ) {
F_8 ( L_7 ) ;
return - V_81 ;
}
if ( ( ( V_10 -> V_16 & V_70 ) |
( V_10 -> V_16 & V_71 ) ) &&
! ( V_5 -> V_82 & ( 1 << V_83 |
1 << V_84 |
1 << V_85 ) ) ) {
F_8 ( L_8
L_9 ) ;
return - V_81 ;
}
V_1 = F_7 ( V_5 -> V_26 ,
V_10 -> V_68 . V_1 ) ;
if ( V_1 == V_27 ) {
F_8 ( L_10 ,
V_10 -> V_68 . V_1 ) ;
if ( V_10 -> V_55 . V_1 != V_27 )
F_9 ( V_5 -> V_26 ,
V_10 -> V_55 . V_1 ) ;
if ( V_10 -> V_57 . V_1 != V_27 )
F_9 ( V_5 -> V_26 ,
V_10 -> V_57 . V_1 ) ;
return - V_28 ;
}
}
if ( V_10 -> V_55 . V_15 > V_23 ||
V_10 -> V_57 . V_15 > V_23 ||
V_10 -> V_68 . V_15 > V_23 ) {
F_8 ( L_11
L_12 ) ;
if ( V_10 -> V_55 . V_1 != V_27 )
F_9 ( V_5 -> V_26 , V_10 -> V_55 . V_1 ) ;
if ( V_10 -> V_57 . V_1 != V_27 )
F_9 ( V_5 -> V_26 , V_10 -> V_57 . V_1 ) ;
if ( V_10 -> V_68 . V_1 != V_27 )
F_9 ( V_5 -> V_26 , V_10 -> V_68 . V_1 ) ;
return - V_29 ;
}
return 0 ;
}
static void
F_30 ( const struct V_60 * V_5 )
{
const struct V_66 * V_10 = V_5 -> V_53 ;
if ( V_10 -> V_55 . V_1 != V_27 )
F_9 ( V_5 -> V_26 , V_10 -> V_55 . V_1 ) ;
if ( V_10 -> V_57 . V_1 != V_27 )
F_9 ( V_5 -> V_26 , V_10 -> V_57 . V_1 ) ;
if ( V_10 -> V_68 . V_1 != V_27 )
F_9 ( V_5 -> V_26 , V_10 -> V_68 . V_1 ) ;
}
static int T_4 F_31 ( void )
{
int V_45 = F_32 ( V_86 , F_33 ( V_86 ) ) ;
if ( ! V_45 ) {
V_45 = F_34 ( V_87 ,
F_33 ( V_87 ) ) ;
if ( V_45 )
F_35 ( V_86 ,
F_33 ( V_86 ) ) ;
}
return V_45 ;
}
static void T_5 F_36 ( void )
{
F_35 ( V_86 , F_33 ( V_86 ) ) ;
F_37 ( V_87 , F_33 ( V_87 ) ) ;
}
