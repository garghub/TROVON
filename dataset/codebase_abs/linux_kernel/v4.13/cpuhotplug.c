static inline bool F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_3 ( F_4 () , V_4 ) ;
}
static bool F_5 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
struct V_7 * V_8 = F_7 ( V_2 ) ;
bool V_9 = ! F_8 ( V_2 ) && ! F_9 ( V_2 ) ;
const struct V_3 * V_10 ;
bool V_11 = false ;
int V_12 ;
if ( ! V_8 || ! V_8 -> V_13 ) {
F_10 ( L_1 , V_2 -> V_14 ) ;
return false ;
}
if ( F_11 ( V_2 ) || ! F_12 ( V_2 ) || ! F_1 ( V_2 ) ) {
F_13 ( V_6 , false ) ;
return false ;
}
F_14 ( V_6 ) ;
if ( F_13 ( V_6 , true ) )
V_10 = F_15 ( V_6 ) ;
else
V_10 = F_16 ( V_2 ) ;
if ( V_9 && V_8 -> V_15 )
V_8 -> V_15 ( V_2 ) ;
if ( F_17 ( V_10 , V_16 ) >= V_17 ) {
if ( F_18 ( V_2 ) ) {
F_19 ( V_2 ) ;
F_20 ( V_6 ) ;
return false ;
}
V_10 = V_16 ;
V_11 = true ;
}
V_12 = F_21 ( V_2 , V_10 , false ) ;
if ( V_12 ) {
F_22 ( L_2 ,
V_2 -> V_14 , V_12 ) ;
V_11 = false ;
}
if ( V_9 && V_8 -> V_18 )
V_8 -> V_18 ( V_2 ) ;
return V_11 ;
}
void F_23 ( void )
{
struct V_5 * V_6 ;
unsigned int V_14 ;
F_24 (irq) {
bool V_19 ;
V_6 = F_25 ( V_14 ) ;
F_26 ( & V_6 -> V_20 ) ;
V_19 = F_5 ( V_6 ) ;
F_27 ( & V_6 -> V_20 ) ;
if ( V_19 ) {
F_22 ( L_3 ,
V_14 , F_4 () ) ;
}
}
}
static void F_28 ( struct V_5 * V_6 , unsigned int V_21 )
{
struct V_1 * V_22 = F_6 ( V_6 ) ;
const struct V_3 * V_10 = F_16 ( V_22 ) ;
if ( ! F_18 ( V_22 ) || ! V_6 -> V_23 ||
! F_7 ( V_22 ) || ! F_3 ( V_21 , V_10 ) )
return;
if ( F_29 ( V_22 ) ) {
F_30 ( V_6 , V_24 , V_25 ) ;
return;
}
if ( ! F_31 ( V_22 ) )
F_32 ( V_22 , V_10 , false ) ;
}
int F_33 ( unsigned int V_21 )
{
struct V_5 * V_6 ;
unsigned int V_14 ;
F_34 () ;
F_24 (irq) {
V_6 = F_25 ( V_14 ) ;
F_35 ( & V_6 -> V_20 ) ;
F_28 ( V_6 , V_21 ) ;
F_36 ( & V_6 -> V_20 ) ;
}
F_37 () ;
return 0 ;
}
