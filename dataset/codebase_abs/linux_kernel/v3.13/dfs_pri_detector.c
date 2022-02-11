static T_1 F_1 ( T_1 V_1 , T_1 V_2 , T_1 V_3 )
{
T_1 V_4 ;
T_1 V_5 ;
T_1 V_6 ;
if ( V_2 == 0 )
return 0 ;
V_6 = ( V_1 < V_2 ) ? ( V_2 - V_1 ) : ( V_1 - V_2 ) ;
if ( V_6 <= V_3 )
return 1 ;
V_5 = V_1 / V_2 ;
V_4 = V_1 % V_2 ;
if ( V_4 > V_3 ) {
if ( ( V_2 - V_4 ) <= V_3 )
V_5 ++ ;
else
V_5 = 0 ;
}
return V_5 ;
}
static void F_2 ( void )
{
F_3 ( & V_7 ) ;
V_8 ++ ;
F_4 ( V_9 ) ;
F_5 ( & V_7 ) ;
}
static void F_6 ( void )
{
F_3 ( & V_7 ) ;
V_8 -- ;
F_7 ( V_9 ) ;
if ( V_8 == 0 ) {
struct V_10 * V_11 , * V_12 ;
struct V_13 * V_14 , * V_15 ;
F_8 (p, p0, &pulse_pool, head) {
F_9 ( & V_14 -> V_16 ) ;
F_7 ( V_17 ) ;
F_10 ( V_14 ) ;
}
F_8 (ps, ps0, &pseq_pool, head) {
F_9 ( & V_11 -> V_16 ) ;
F_7 ( V_18 ) ;
F_10 ( V_11 ) ;
}
}
F_5 ( & V_7 ) ;
}
static void F_11 ( struct V_13 * V_19 )
{
F_3 ( & V_7 ) ;
F_12 ( & V_19 -> V_16 , & V_20 ) ;
F_7 ( V_21 ) ;
F_5 ( & V_7 ) ;
}
static void F_13 ( struct V_10 * V_22 )
{
F_3 ( & V_7 ) ;
F_12 ( & V_22 -> V_16 , & V_23 ) ;
F_7 ( V_24 ) ;
F_5 ( & V_7 ) ;
}
static struct V_10 * F_14 ( void )
{
struct V_10 * V_22 = NULL ;
F_3 ( & V_7 ) ;
if ( ! F_15 ( & V_23 ) ) {
V_22 = F_16 ( & V_23 , struct V_10 , V_16 ) ;
F_9 ( & V_22 -> V_16 ) ;
F_4 ( V_24 ) ;
}
F_5 ( & V_7 ) ;
return V_22 ;
}
static struct V_13 * F_17 ( void )
{
struct V_13 * V_19 = NULL ;
F_3 ( & V_7 ) ;
if ( ! F_15 ( & V_20 ) ) {
V_19 = F_16 ( & V_20 , struct V_13 , V_16 ) ;
F_9 ( & V_19 -> V_16 ) ;
F_4 ( V_21 ) ;
}
F_5 ( & V_7 ) ;
return V_19 ;
}
static struct V_13 * F_18 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = & V_26 -> V_29 ;
if ( F_15 ( V_28 ) )
return NULL ;
return F_19 ( V_28 -> V_30 , struct V_13 , V_16 ) ;
}
static bool F_20 ( struct V_25 * V_26 )
{
struct V_13 * V_14 = F_18 ( V_26 ) ;
if ( V_14 != NULL ) {
F_21 ( & V_14 -> V_16 ) ;
V_26 -> V_31 -- ;
F_11 ( V_14 ) ;
}
return ( V_26 -> V_31 > 0 ) ;
}
static void F_22 ( struct V_25 * V_26 )
{
T_2 V_32 ;
struct V_13 * V_14 ;
if ( V_26 -> V_31 < 2 )
return;
if ( V_26 -> V_33 <= V_26 -> V_34 )
return;
V_32 = V_26 -> V_33 - V_26 -> V_34 ;
while ( ( V_14 = F_18 ( V_26 ) ) != NULL ) {
if ( V_14 -> V_35 >= V_32 )
return;
F_20 ( V_26 ) ;
}
}
static bool F_23 ( struct V_25 * V_26 , T_2 V_35 )
{
struct V_13 * V_14 = F_17 () ;
if ( V_14 == NULL ) {
V_14 = F_24 ( sizeof( * V_14 ) , V_36 ) ;
if ( V_14 == NULL ) {
F_4 ( V_37 ) ;
return false ;
}
F_4 ( V_17 ) ;
F_4 ( V_21 ) ;
}
F_25 ( & V_14 -> V_16 ) ;
V_14 -> V_35 = V_35 ;
F_12 ( & V_14 -> V_16 , & V_26 -> V_29 ) ;
V_26 -> V_31 ++ ;
V_26 -> V_33 = V_35 ;
F_22 ( V_26 ) ;
if ( V_26 -> V_31 >= V_26 -> V_38 )
F_20 ( V_26 ) ;
return true ;
}
static bool F_26 ( struct V_25 * V_26 ,
T_2 V_35 , T_1 V_39 )
{
struct V_13 * V_14 ;
F_27 (p, &pde->pulses, head) {
struct V_10 V_11 , * V_40 ;
struct V_13 * V_41 ;
T_1 V_42 ;
T_2 V_32 ;
T_1 V_43 = V_35 - V_14 -> V_35 ;
if ( V_43 < V_26 -> V_44 -> V_45 )
continue;
if ( V_43 > V_26 -> V_44 -> V_46 )
break;
V_11 . V_31 = 2 ;
V_11 . V_47 = 0 ;
V_11 . V_48 = V_14 -> V_35 ;
V_11 . V_33 = V_35 ;
V_11 . V_49 = V_35 - V_14 -> V_35 ;
V_11 . V_50 = V_11 . V_49 * ( V_26 -> V_44 -> V_51 - 1 )
+ 2 * V_26 -> V_44 -> V_52 ;
V_41 = V_14 ;
V_42 = 0 ;
V_32 = V_35 - V_11 . V_50 ;
F_28 (p2, &pde->pulses, head) {
T_1 V_5 ;
if ( V_41 -> V_35 < V_32 )
break;
V_5 = F_1 ( V_11 . V_33 - V_41 -> V_35 , V_11 . V_49 ,
V_26 -> V_44 -> V_52 ) ;
if ( V_5 > 0 ) {
V_11 . V_31 ++ ;
V_11 . V_48 = V_41 -> V_35 ;
V_11 . V_47 += V_42 ;
V_42 = 0 ;
} else {
V_42 ++ ;
}
}
if ( V_11 . V_31 < V_39 )
continue;
V_11 . V_53 = V_11 . V_48 + V_11 . V_50 ;
V_40 = F_14 () ;
if ( V_40 == NULL ) {
V_40 = F_24 ( sizeof( * V_40 ) , V_36 ) ;
if ( V_40 == NULL ) {
F_4 ( V_54 ) ;
return false ;
}
F_4 ( V_18 ) ;
F_4 ( V_24 ) ;
}
memcpy ( V_40 , & V_11 , sizeof( V_11 ) ) ;
F_25 ( & V_40 -> V_16 ) ;
F_12 ( & V_40 -> V_16 , & V_26 -> V_55 ) ;
}
return true ;
}
static T_1
F_29 ( struct V_25 * V_26 , T_2 V_35 )
{
T_1 V_38 = 0 ;
struct V_10 * V_11 , * V_56 ;
F_8 (ps, ps2, &pde->sequences, head) {
T_1 V_43 ;
T_1 V_5 ;
if ( V_35 > V_11 -> V_53 ) {
F_21 ( & V_11 -> V_16 ) ;
F_13 ( V_11 ) ;
continue;
}
V_43 = V_35 - V_11 -> V_33 ;
V_5 = F_1 ( V_43 , V_11 -> V_49 ,
V_26 -> V_44 -> V_52 ) ;
if ( V_5 > 0 ) {
V_11 -> V_33 = V_35 ;
V_11 -> V_31 ++ ;
if ( V_38 < V_11 -> V_31 )
V_38 = V_11 -> V_31 ;
} else {
V_11 -> V_47 ++ ;
}
}
return V_38 ;
}
static struct V_10 *
F_30 ( struct V_25 * V_26 )
{
struct V_10 * V_11 ;
if ( F_15 ( & V_26 -> V_55 ) )
return NULL ;
F_27 (ps, &pde->sequences, head) {
if ( ( V_11 -> V_31 >= V_26 -> V_44 -> V_57 ) &&
( V_11 -> V_31 * V_26 -> V_44 -> V_58 >= V_11 -> V_47 ) )
return V_11 ;
}
return NULL ;
}
static void F_31 ( struct V_25 * V_26 , T_2 V_35 )
{
struct V_10 * V_11 , * V_12 ;
struct V_13 * V_14 , * V_15 ;
F_8 (ps, ps0, &pde->sequences, head) {
F_21 ( & V_11 -> V_16 ) ;
F_13 ( V_11 ) ;
}
F_8 (p, p0, &pde->pulses, head) {
F_21 ( & V_14 -> V_16 ) ;
F_11 ( V_14 ) ;
}
V_26 -> V_31 = 0 ;
V_26 -> V_33 = V_35 ;
}
static void F_32 ( struct V_25 * V_59 )
{
F_31 ( V_59 , 0 ) ;
F_6 () ;
F_10 ( V_59 ) ;
}
static struct V_10 * F_33 ( struct V_25 * V_59 ,
struct V_60 * V_61 )
{
T_1 V_62 ;
struct V_10 * V_11 ;
T_2 V_35 = V_61 -> V_35 ;
const struct V_63 * V_44 = V_59 -> V_44 ;
if ( ( V_44 -> V_64 > V_61 -> V_65 ) || ( V_44 -> V_66 < V_61 -> V_65 ) )
return NULL ;
if ( ( V_35 - V_59 -> V_33 ) < V_44 -> V_52 )
return NULL ;
V_59 -> V_33 = V_35 ;
V_62 = F_29 ( V_59 , V_35 ) ;
if ( ! F_26 ( V_59 , V_35 , V_62 ) ) {
F_31 ( V_59 , V_35 ) ;
return NULL ;
}
V_11 = F_30 ( V_59 ) ;
if ( V_11 == NULL )
F_23 ( V_59 , V_35 ) ;
return V_11 ;
}
struct V_25 * F_34 ( const struct V_63 * V_44 )
{
struct V_25 * V_59 ;
V_59 = F_35 ( sizeof( * V_59 ) , V_36 ) ;
if ( V_59 == NULL )
return NULL ;
V_59 -> exit = F_32 ;
V_59 -> V_67 = F_33 ;
V_59 -> V_68 = F_31 ;
F_25 ( & V_59 -> V_55 ) ;
F_25 ( & V_59 -> V_29 ) ;
V_59 -> V_34 = V_44 -> V_46 * V_44 -> V_51 * V_44 -> V_58 ;
V_59 -> V_38 = V_44 -> V_51 * 2 ;
V_59 -> V_44 = V_44 ;
F_2 () ;
return V_59 ;
}
