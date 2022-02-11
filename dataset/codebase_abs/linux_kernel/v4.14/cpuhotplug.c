static inline bool F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 = F_3 () ;
#ifdef F_4
if ( F_5 ( V_4 ) )
V_4 = F_6 ( V_2 ) ;
if ( F_7 ( V_4 , V_5 ) < V_6 &&
F_8 ( V_4 , V_7 ) >= V_6 ) {
F_9 ( L_1 ,
F_10 ( V_4 ) , V_2 -> V_8 , V_5 ) ;
return true ;
}
#endif
return F_11 ( V_5 , V_4 ) ;
}
static bool F_12 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_13 ( V_10 ) ;
struct V_11 * V_12 = F_14 ( V_2 ) ;
bool V_13 = ! F_15 ( V_2 ) && ! F_16 ( V_2 ) ;
const struct V_3 * V_14 ;
bool V_15 = false ;
int V_16 ;
if ( ! V_12 || ! V_12 -> V_17 ) {
F_17 ( L_2 , V_2 -> V_8 ) ;
return false ;
}
if ( F_18 ( V_2 ) || ! F_19 ( V_2 ) || ! F_1 ( V_2 ) ) {
F_20 ( V_10 , false ) ;
return false ;
}
F_21 ( V_10 ) ;
if ( F_20 ( V_10 , true ) )
V_14 = F_22 ( V_10 ) ;
else
V_14 = F_6 ( V_2 ) ;
if ( V_13 && V_12 -> V_18 )
V_12 -> V_18 ( V_2 ) ;
if ( F_8 ( V_14 , V_7 ) >= V_6 ) {
if ( F_23 ( V_2 ) ) {
F_24 ( V_2 ) ;
F_25 ( V_10 ) ;
return false ;
}
V_14 = V_7 ;
V_15 = true ;
}
V_16 = F_26 ( V_2 , V_14 , false ) ;
if ( V_16 ) {
F_27 ( L_3 ,
V_2 -> V_8 , V_16 ) ;
V_15 = false ;
}
if ( V_13 && V_12 -> V_19 )
V_12 -> V_19 ( V_2 ) ;
return V_15 ;
}
void F_28 ( void )
{
struct V_9 * V_10 ;
unsigned int V_8 ;
F_29 (irq) {
bool V_20 ;
V_10 = F_30 ( V_8 ) ;
F_31 ( & V_10 -> V_21 ) ;
V_20 = F_12 ( V_10 ) ;
F_32 ( & V_10 -> V_21 ) ;
if ( V_20 ) {
F_27 ( L_4 ,
V_8 , F_3 () ) ;
}
}
}
static void F_33 ( struct V_9 * V_10 , unsigned int V_5 )
{
struct V_1 * V_22 = F_13 ( V_10 ) ;
const struct V_3 * V_14 = F_6 ( V_22 ) ;
if ( ! F_23 ( V_22 ) || ! V_10 -> V_23 ||
! F_14 ( V_22 ) || ! F_11 ( V_5 , V_14 ) )
return;
if ( F_34 ( V_22 ) ) {
F_35 ( V_10 , V_24 , V_25 ) ;
return;
}
if ( ! F_36 ( V_22 ) )
F_37 ( V_22 , V_14 , false ) ;
}
int F_38 ( unsigned int V_5 )
{
struct V_9 * V_10 ;
unsigned int V_8 ;
F_39 () ;
F_29 (irq) {
V_10 = F_30 ( V_8 ) ;
F_40 ( & V_10 -> V_21 ) ;
F_33 ( V_10 , V_5 ) ;
F_41 ( & V_10 -> V_21 ) ;
}
F_42 () ;
return 0 ;
}
