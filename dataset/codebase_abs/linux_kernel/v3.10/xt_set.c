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
V_1 = F_7 ( V_10 -> F_1 . V_1 ) ;
if ( V_1 == V_26 ) {
F_8 ( L_1 ,
V_10 -> F_1 . V_1 ) ;
return - V_27 ;
}
if ( V_10 -> F_1 . V_13 . V_16 [ V_23 - 1 ] != 0 ) {
F_8 ( L_2
L_3 ) ;
F_9 ( V_10 -> F_1 . V_1 ) ;
return - V_28 ;
}
F_5 ( & V_10 -> F_1 ) ;
return 0 ;
}
static void
F_10 ( const struct V_29 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
F_9 ( V_10 -> F_1 . V_1 ) ;
}
static unsigned int
F_11 ( struct V_2 * V_3 , const struct V_4 * V_5 )
{
const struct V_30 * V_10 = V_5 -> V_31 ;
F_4 ( V_32 , V_5 -> V_12 , V_10 -> V_33 . V_13 . V_14 . V_15 ,
V_10 -> V_33 . V_13 . V_14 . V_16 , 0 , V_17 ) ;
F_4 ( V_34 , V_5 -> V_12 , V_10 -> V_35 . V_13 . V_14 . V_15 ,
V_10 -> V_35 . V_13 . V_14 . V_16 , 0 , V_17 ) ;
if ( V_10 -> V_33 . V_1 != V_26 )
F_12 ( V_10 -> V_33 . V_1 , V_3 , V_5 , & V_32 ) ;
if ( V_10 -> V_35 . V_1 != V_26 )
F_13 ( V_10 -> V_35 . V_1 , V_3 , V_5 , & V_34 ) ;
return V_36 ;
}
static int
F_14 ( const struct V_37 * V_5 )
{
struct V_30 * V_10 = V_5 -> V_31 ;
T_1 V_1 ;
if ( V_10 -> V_33 . V_1 != V_26 ) {
V_1 = F_7 ( V_10 -> V_33 . V_1 ) ;
if ( V_1 == V_26 ) {
F_8 ( L_4 ,
V_10 -> V_33 . V_1 ) ;
return - V_27 ;
}
}
if ( V_10 -> V_35 . V_1 != V_26 ) {
V_1 = F_7 ( V_10 -> V_35 . V_1 ) ;
if ( V_1 == V_26 ) {
F_8 ( L_5 ,
V_10 -> V_35 . V_1 ) ;
if ( V_10 -> V_33 . V_1 != V_26 )
F_9 ( V_10 -> V_33 . V_1 ) ;
return - V_27 ;
}
}
if ( V_10 -> V_33 . V_13 . V_16 [ V_23 - 1 ] != 0 ||
V_10 -> V_35 . V_13 . V_16 [ V_23 - 1 ] != 0 ) {
F_8 ( L_6
L_3 ) ;
if ( V_10 -> V_33 . V_1 != V_26 )
F_9 ( V_10 -> V_33 . V_1 ) ;
if ( V_10 -> V_35 . V_1 != V_26 )
F_9 ( V_10 -> V_35 . V_1 ) ;
return - V_28 ;
}
F_5 ( & V_10 -> V_33 ) ;
F_5 ( & V_10 -> V_35 ) ;
return 0 ;
}
static void
F_15 ( const struct V_38 * V_5 )
{
const struct V_30 * V_10 = V_5 -> V_31 ;
if ( V_10 -> V_33 . V_1 != V_26 )
F_9 ( V_10 -> V_33 . V_1 ) ;
if ( V_10 -> V_35 . V_1 != V_26 )
F_9 ( V_10 -> V_35 . V_1 ) ;
}
static bool
F_16 ( const struct V_2 * V_3 , struct V_4 * V_5 )
{
const struct V_39 * V_10 = V_5 -> V_11 ;
F_4 ( V_7 , V_5 -> V_12 , V_10 -> F_1 . V_15 ,
V_10 -> F_1 . V_16 , 0 , V_17 ) ;
if ( V_7 . V_16 & V_40 )
V_7 . V_41 |= V_42 ;
return F_1 ( V_10 -> F_1 . V_1 , V_3 , V_5 , & V_7 ,
V_10 -> F_1 . V_16 & V_18 ) ;
}
static int
F_17 ( const struct V_25 * V_5 )
{
struct V_39 * V_10 = V_5 -> V_11 ;
T_1 V_1 ;
V_1 = F_7 ( V_10 -> F_1 . V_1 ) ;
if ( V_1 == V_26 ) {
F_8 ( L_1 ,
V_10 -> F_1 . V_1 ) ;
return - V_27 ;
}
if ( V_10 -> F_1 . V_15 > V_23 ) {
F_8 ( L_2
L_3 ) ;
F_9 ( V_10 -> F_1 . V_1 ) ;
return - V_28 ;
}
return 0 ;
}
static void
F_18 ( const struct V_29 * V_5 )
{
struct V_39 * V_10 = V_5 -> V_11 ;
F_9 ( V_10 -> F_1 . V_1 ) ;
}
static unsigned int
F_19 ( struct V_2 * V_3 , const struct V_4 * V_5 )
{
const struct V_43 * V_10 = V_5 -> V_31 ;
F_4 ( V_32 , V_5 -> V_12 , V_10 -> V_33 . V_15 ,
V_10 -> V_33 . V_16 , 0 , V_17 ) ;
F_4 ( V_34 , V_5 -> V_12 , V_10 -> V_35 . V_15 ,
V_10 -> V_35 . V_16 , 0 , V_17 ) ;
if ( V_10 -> V_33 . V_1 != V_26 )
F_12 ( V_10 -> V_33 . V_1 , V_3 , V_5 , & V_32 ) ;
if ( V_10 -> V_35 . V_1 != V_26 )
F_13 ( V_10 -> V_35 . V_1 , V_3 , V_5 , & V_34 ) ;
return V_36 ;
}
static int
F_20 ( const struct V_37 * V_5 )
{
const struct V_43 * V_10 = V_5 -> V_31 ;
T_1 V_1 ;
if ( V_10 -> V_33 . V_1 != V_26 ) {
V_1 = F_7 ( V_10 -> V_33 . V_1 ) ;
if ( V_1 == V_26 ) {
F_8 ( L_4 ,
V_10 -> V_33 . V_1 ) ;
return - V_27 ;
}
}
if ( V_10 -> V_35 . V_1 != V_26 ) {
V_1 = F_7 ( V_10 -> V_35 . V_1 ) ;
if ( V_1 == V_26 ) {
F_8 ( L_5 ,
V_10 -> V_35 . V_1 ) ;
if ( V_10 -> V_33 . V_1 != V_26 )
F_9 ( V_10 -> V_33 . V_1 ) ;
return - V_27 ;
}
}
if ( V_10 -> V_33 . V_15 > V_23 ||
V_10 -> V_35 . V_15 > V_23 ) {
F_8 ( L_6
L_3 ) ;
if ( V_10 -> V_33 . V_1 != V_26 )
F_9 ( V_10 -> V_33 . V_1 ) ;
if ( V_10 -> V_35 . V_1 != V_26 )
F_9 ( V_10 -> V_35 . V_1 ) ;
return - V_28 ;
}
return 0 ;
}
static void
F_21 ( const struct V_38 * V_5 )
{
const struct V_43 * V_10 = V_5 -> V_31 ;
if ( V_10 -> V_33 . V_1 != V_26 )
F_9 ( V_10 -> V_33 . V_1 ) ;
if ( V_10 -> V_35 . V_1 != V_26 )
F_9 ( V_10 -> V_35 . V_1 ) ;
}
static unsigned int
F_22 ( struct V_2 * V_3 , const struct V_4 * V_5 )
{
const struct V_44 * V_10 = V_5 -> V_31 ;
F_4 ( V_32 , V_5 -> V_12 , V_10 -> V_33 . V_15 ,
V_10 -> V_33 . V_16 , V_10 -> V_16 , V_10 -> V_45 ) ;
F_4 ( V_34 , V_5 -> V_12 , V_10 -> V_35 . V_15 ,
V_10 -> V_35 . V_16 , 0 , V_17 ) ;
if ( V_32 . V_46 . V_45 != V_47 &&
V_32 . V_46 . V_45 > V_17 / V_48 )
V_32 . V_46 . V_45 = V_17 / V_48 ;
if ( V_10 -> V_33 . V_1 != V_26 )
F_12 ( V_10 -> V_33 . V_1 , V_3 , V_5 , & V_32 ) ;
if ( V_10 -> V_35 . V_1 != V_26 )
F_13 ( V_10 -> V_35 . V_1 , V_3 , V_5 , & V_34 ) ;
return V_36 ;
}
static bool
F_23 ( T_3 V_49 , const struct V_50 * V_10 )
{
switch ( V_10 -> V_51 ) {
case V_52 :
return true ;
case V_53 :
return V_49 == V_10 -> V_54 ;
case V_55 :
return V_49 != V_10 -> V_54 ;
case V_56 :
return V_49 < V_10 -> V_54 ;
case V_57 :
return V_49 > V_10 -> V_54 ;
}
return false ;
}
static bool
F_24 ( const struct V_2 * V_3 , struct V_4 * V_5 )
{
const struct V_58 * V_10 = V_5 -> V_11 ;
F_4 ( V_7 , V_5 -> V_12 , V_10 -> F_1 . V_15 ,
V_10 -> F_1 . V_16 , V_10 -> V_16 , V_17 ) ;
int V_59 ;
if ( V_10 -> V_60 . V_51 != V_52 ||
V_10 -> V_61 . V_51 != V_52 )
V_7 . V_41 |= V_62 ;
V_59 = F_1 ( V_10 -> F_1 . V_1 , V_3 , V_5 , & V_7 ,
V_10 -> F_1 . V_16 & V_18 ) ;
if ( ! ( V_59 && V_7 . V_41 & V_62 ) )
return V_59 ;
if ( ! F_23 ( V_7 . V_46 . V_60 , & V_10 -> V_60 ) )
return 0 ;
return F_23 ( V_7 . V_46 . V_61 , & V_10 -> V_61 ) ;
}
static int T_4 F_25 ( void )
{
int V_59 = F_26 ( V_63 , F_27 ( V_63 ) ) ;
if ( ! V_59 ) {
V_59 = F_28 ( V_64 ,
F_27 ( V_64 ) ) ;
if ( V_59 )
F_29 ( V_63 ,
F_27 ( V_63 ) ) ;
}
return V_59 ;
}
static void T_5 F_30 ( void )
{
F_29 ( V_63 , F_27 ( V_63 ) ) ;
F_31 ( V_64 , F_27 ( V_64 ) ) ;
}
