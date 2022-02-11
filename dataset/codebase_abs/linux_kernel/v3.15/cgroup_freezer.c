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
return F_1 ( F_6 ( & V_1 -> V_3 ) ) ;
}
bool F_7 ( struct V_4 * V_5 )
{
bool V_7 ;
F_8 () ;
V_7 = F_3 ( V_5 ) -> V_8 & V_9 ;
F_9 () ;
return V_7 ;
}
static const char * F_10 ( unsigned int V_8 )
{
if ( V_8 & V_10 )
return L_1 ;
if ( V_8 & V_9 )
return L_2 ;
return L_3 ;
}
static struct V_2 *
F_11 ( struct V_2 * V_11 )
{
struct V_1 * V_1 ;
V_1 = F_12 ( sizeof( struct V_1 ) , V_12 ) ;
if ( ! V_1 )
return F_13 ( - V_13 ) ;
return & V_1 -> V_3 ;
}
static int F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_1 * V_14 = F_5 ( V_1 ) ;
F_15 ( & V_15 ) ;
V_1 -> V_8 |= V_16 ;
if ( V_14 && ( V_14 -> V_8 & V_9 ) ) {
V_1 -> V_8 |= V_17 | V_10 ;
F_16 ( & V_18 ) ;
}
F_17 ( & V_15 ) ;
return 0 ;
}
static void F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_15 ( & V_15 ) ;
if ( V_1 -> V_8 & V_9 )
F_19 ( & V_18 ) ;
V_1 -> V_8 = 0 ;
F_17 ( & V_15 ) ;
}
static void F_20 ( struct V_2 * V_3 )
{
F_21 ( F_1 ( V_3 ) ) ;
}
static void F_22 ( struct V_2 * V_19 ,
struct V_20 * V_21 )
{
struct V_1 * V_1 = F_1 ( V_19 ) ;
struct V_4 * V_5 ;
bool V_22 = false ;
F_15 ( & V_15 ) ;
F_23 (task, tset) {
if ( ! ( V_1 -> V_8 & V_9 ) ) {
F_24 ( V_5 ) ;
} else {
F_25 ( V_5 ) ;
V_1 -> V_8 &= ~ V_10 ;
V_22 = true ;
}
}
while ( V_22 && ( V_1 = F_5 ( V_1 ) ) ) {
V_1 -> V_8 &= ~ V_10 ;
V_22 = V_1 -> V_8 & V_9 ;
}
F_17 ( & V_15 ) ;
}
static void F_26 ( struct V_4 * V_5 )
{
struct V_1 * V_1 ;
if ( F_27 ( V_5 , V_6 ) )
return;
F_15 ( & V_15 ) ;
F_8 () ;
V_1 = F_3 ( V_5 ) ;
if ( V_1 -> V_8 & V_9 )
F_25 ( V_5 ) ;
F_9 () ;
F_17 ( & V_15 ) ;
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_2 * V_23 ;
struct V_24 V_25 ;
struct V_4 * V_5 ;
F_29 ( & V_15 ) ;
if ( ! ( V_1 -> V_8 & V_9 ) ||
( V_1 -> V_8 & V_10 ) )
return;
F_8 () ;
F_30 (pos, css) {
struct V_1 * V_26 = F_1 ( V_23 ) ;
if ( ( V_26 -> V_8 & V_16 ) &&
! ( V_26 -> V_8 & V_10 ) ) {
F_9 () ;
return;
}
}
F_9 () ;
F_31 ( V_3 , & V_25 ) ;
while ( ( V_5 = F_32 ( & V_25 ) ) ) {
if ( F_33 ( V_5 ) ) {
if ( ! F_34 ( V_5 ) && ! F_35 ( V_5 ) )
goto V_27;
}
}
V_1 -> V_8 |= V_10 ;
V_27:
F_36 ( & V_25 ) ;
}
static int F_37 ( struct V_28 * V_29 , void * V_30 )
{
struct V_2 * V_3 = F_38 ( V_29 ) , * V_23 ;
F_15 ( & V_15 ) ;
F_8 () ;
F_39 (pos, css) {
if ( ! F_40 ( V_23 ) )
continue;
F_9 () ;
F_28 ( V_23 ) ;
F_8 () ;
F_41 ( V_23 ) ;
}
F_9 () ;
F_17 ( & V_15 ) ;
F_42 ( V_29 , F_10 ( F_1 ( V_3 ) -> V_8 ) ) ;
F_43 ( V_29 , '\n' ) ;
return 0 ;
}
static void F_44 ( struct V_1 * V_1 )
{
struct V_24 V_25 ;
struct V_4 * V_5 ;
F_31 ( & V_1 -> V_3 , & V_25 ) ;
while ( ( V_5 = F_32 ( & V_25 ) ) )
F_25 ( V_5 ) ;
F_36 ( & V_25 ) ;
}
static void F_45 ( struct V_1 * V_1 )
{
struct V_24 V_25 ;
struct V_4 * V_5 ;
F_31 ( & V_1 -> V_3 , & V_25 ) ;
while ( ( V_5 = F_32 ( & V_25 ) ) )
F_24 ( V_5 ) ;
F_36 ( & V_25 ) ;
}
static void F_46 ( struct V_1 * V_1 , bool V_31 ,
unsigned int V_8 )
{
F_29 ( & V_15 ) ;
if ( ! ( V_1 -> V_8 & V_16 ) )
return;
if ( V_31 ) {
if ( ! ( V_1 -> V_8 & V_9 ) )
F_16 ( & V_18 ) ;
V_1 -> V_8 |= V_8 ;
F_44 ( V_1 ) ;
} else {
bool V_32 = V_1 -> V_8 & V_9 ;
V_1 -> V_8 &= ~ V_8 ;
if ( ! ( V_1 -> V_8 & V_9 ) ) {
if ( V_32 )
F_19 ( & V_18 ) ;
V_1 -> V_8 &= ~ V_10 ;
F_45 ( V_1 ) ;
}
}
}
static void F_47 ( struct V_1 * V_1 , bool V_31 )
{
struct V_2 * V_23 ;
F_15 ( & V_15 ) ;
F_8 () ;
F_48 (pos, &freezer->css) {
struct V_1 * V_33 = F_1 ( V_23 ) ;
struct V_1 * V_14 = F_5 ( V_33 ) ;
if ( ! F_40 ( V_23 ) )
continue;
F_9 () ;
if ( V_33 == V_1 )
F_46 ( V_33 , V_31 ,
V_34 ) ;
else
F_46 ( V_33 ,
V_14 -> V_8 & V_9 ,
V_17 ) ;
F_8 () ;
F_41 ( V_23 ) ;
}
F_9 () ;
F_17 ( & V_15 ) ;
}
static int F_49 ( struct V_2 * V_3 , struct V_35 * V_36 ,
char * V_37 )
{
bool V_31 ;
if ( strcmp ( V_37 , F_10 ( 0 ) ) == 0 )
V_31 = false ;
else if ( strcmp ( V_37 , F_10 ( V_10 ) ) == 0 )
V_31 = true ;
else
return - V_38 ;
F_47 ( F_1 ( V_3 ) , V_31 ) ;
return 0 ;
}
static T_1 F_50 ( struct V_2 * V_3 ,
struct V_35 * V_36 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return ( bool ) ( V_1 -> V_8 & V_34 ) ;
}
static T_1 F_51 ( struct V_2 * V_3 ,
struct V_35 * V_36 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return ( bool ) ( V_1 -> V_8 & V_17 ) ;
}
