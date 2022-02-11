static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 ? F_2 ( V_3 , struct V_1 , V_3 ) : NULL ;
}
static inline struct V_1 * F_3 ( struct V_4 * V_5 )
{
return F_1 ( F_4 ( V_5 , V_6 ) ) ;
}
static struct V_1 * F_5 ( struct V_1 * V_1 )
{
return F_1 ( V_1 -> V_3 . V_7 ) ;
}
bool F_6 ( struct V_4 * V_5 )
{
bool V_8 ;
F_7 () ;
V_8 = F_3 ( V_5 ) -> V_9 & V_10 ;
F_8 () ;
return V_8 ;
}
static const char * F_9 ( unsigned int V_9 )
{
if ( V_9 & V_11 )
return L_1 ;
if ( V_9 & V_10 )
return L_2 ;
return L_3 ;
}
static struct V_2 *
F_10 ( struct V_2 * V_12 )
{
struct V_1 * V_1 ;
V_1 = F_11 ( sizeof( struct V_1 ) , V_13 ) ;
if ( ! V_1 )
return F_12 ( - V_14 ) ;
return & V_1 -> V_3 ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_1 * V_7 = F_5 ( V_1 ) ;
F_14 ( & V_15 ) ;
V_1 -> V_9 |= V_16 ;
if ( V_7 && ( V_7 -> V_9 & V_10 ) ) {
V_1 -> V_9 |= V_17 | V_11 ;
F_15 ( & V_18 ) ;
}
F_16 ( & V_15 ) ;
return 0 ;
}
static void F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_14 ( & V_15 ) ;
if ( V_1 -> V_9 & V_10 )
F_18 ( & V_18 ) ;
V_1 -> V_9 = 0 ;
F_16 ( & V_15 ) ;
}
static void F_19 ( struct V_2 * V_3 )
{
F_20 ( F_1 ( V_3 ) ) ;
}
static void F_21 ( struct V_2 * V_19 ,
struct V_20 * V_21 )
{
struct V_1 * V_1 = F_1 ( V_19 ) ;
struct V_4 * V_5 ;
bool V_22 = false ;
F_14 ( & V_15 ) ;
F_22 (task, tset) {
if ( ! ( V_1 -> V_9 & V_10 ) ) {
F_23 ( V_5 ) ;
} else {
F_24 ( V_5 ) ;
V_1 -> V_9 &= ~ V_11 ;
V_22 = true ;
}
}
while ( V_22 && ( V_1 = F_5 ( V_1 ) ) ) {
V_1 -> V_9 &= ~ V_11 ;
V_22 = V_1 -> V_9 & V_10 ;
}
F_16 ( & V_15 ) ;
}
static void F_25 ( struct V_4 * V_5 , void * V_23 )
{
struct V_1 * V_1 ;
if ( F_26 ( V_5 , V_6 ) )
return;
F_14 ( & V_15 ) ;
F_7 () ;
V_1 = F_3 ( V_5 ) ;
if ( V_1 -> V_9 & V_10 )
F_24 ( V_5 ) ;
F_8 () ;
F_16 ( & V_15 ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_2 * V_24 ;
struct V_25 V_26 ;
struct V_4 * V_5 ;
F_28 ( & V_15 ) ;
if ( ! ( V_1 -> V_9 & V_10 ) ||
( V_1 -> V_9 & V_11 ) )
return;
F_7 () ;
F_29 (pos, css) {
struct V_1 * V_27 = F_1 ( V_24 ) ;
if ( ( V_27 -> V_9 & V_16 ) &&
! ( V_27 -> V_9 & V_11 ) ) {
F_8 () ;
return;
}
}
F_8 () ;
F_30 ( V_3 , & V_26 ) ;
while ( ( V_5 = F_31 ( & V_26 ) ) ) {
if ( F_32 ( V_5 ) ) {
if ( ! F_33 ( V_5 ) && ! F_34 ( V_5 ) )
goto V_28;
}
}
V_1 -> V_9 |= V_11 ;
V_28:
F_35 ( & V_26 ) ;
}
static int F_36 ( struct V_29 * V_30 , void * V_31 )
{
struct V_2 * V_3 = F_37 ( V_30 ) , * V_24 ;
F_14 ( & V_15 ) ;
F_7 () ;
F_38 (pos, css) {
if ( ! F_39 ( V_24 ) )
continue;
F_8 () ;
F_27 ( V_24 ) ;
F_7 () ;
F_40 ( V_24 ) ;
}
F_8 () ;
F_16 ( & V_15 ) ;
F_41 ( V_30 , F_9 ( F_1 ( V_3 ) -> V_9 ) ) ;
F_42 ( V_30 , '\n' ) ;
return 0 ;
}
static void F_43 ( struct V_1 * V_1 )
{
struct V_25 V_26 ;
struct V_4 * V_5 ;
F_30 ( & V_1 -> V_3 , & V_26 ) ;
while ( ( V_5 = F_31 ( & V_26 ) ) )
F_24 ( V_5 ) ;
F_35 ( & V_26 ) ;
}
static void F_44 ( struct V_1 * V_1 )
{
struct V_25 V_26 ;
struct V_4 * V_5 ;
F_30 ( & V_1 -> V_3 , & V_26 ) ;
while ( ( V_5 = F_31 ( & V_26 ) ) )
F_23 ( V_5 ) ;
F_35 ( & V_26 ) ;
}
static void F_45 ( struct V_1 * V_1 , bool V_32 ,
unsigned int V_9 )
{
F_28 ( & V_15 ) ;
if ( ! ( V_1 -> V_9 & V_16 ) )
return;
if ( V_32 ) {
if ( ! ( V_1 -> V_9 & V_10 ) )
F_15 ( & V_18 ) ;
V_1 -> V_9 |= V_9 ;
F_43 ( V_1 ) ;
} else {
bool V_33 = V_1 -> V_9 & V_10 ;
V_1 -> V_9 &= ~ V_9 ;
if ( ! ( V_1 -> V_9 & V_10 ) ) {
if ( V_33 )
F_18 ( & V_18 ) ;
V_1 -> V_9 &= ~ V_11 ;
F_44 ( V_1 ) ;
}
}
}
static void F_46 ( struct V_1 * V_1 , bool V_32 )
{
struct V_2 * V_24 ;
F_14 ( & V_15 ) ;
F_7 () ;
F_47 (pos, &freezer->css) {
struct V_1 * V_34 = F_1 ( V_24 ) ;
struct V_1 * V_7 = F_5 ( V_34 ) ;
if ( ! F_39 ( V_24 ) )
continue;
F_8 () ;
if ( V_34 == V_1 )
F_45 ( V_34 , V_32 ,
V_35 ) ;
else
F_45 ( V_34 ,
V_7 -> V_9 & V_10 ,
V_17 ) ;
F_7 () ;
F_40 ( V_24 ) ;
}
F_8 () ;
F_16 ( & V_15 ) ;
}
static T_1 F_48 ( struct V_36 * V_37 ,
char * V_38 , T_2 V_39 , T_3 V_40 )
{
bool V_32 ;
V_38 = F_49 ( V_38 ) ;
if ( strcmp ( V_38 , F_9 ( 0 ) ) == 0 )
V_32 = false ;
else if ( strcmp ( V_38 , F_9 ( V_11 ) ) == 0 )
V_32 = true ;
else
return - V_41 ;
F_46 ( F_1 ( F_50 ( V_37 ) ) , V_32 ) ;
return V_39 ;
}
static T_4 F_51 ( struct V_2 * V_3 ,
struct V_42 * V_43 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return ( bool ) ( V_1 -> V_9 & V_35 ) ;
}
static T_4 F_52 ( struct V_2 * V_3 ,
struct V_42 * V_43 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return ( bool ) ( V_1 -> V_9 & V_17 ) ;
}
