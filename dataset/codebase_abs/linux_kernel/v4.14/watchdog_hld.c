void F_1 ( void )
{
F_2 ( V_1 , true ) ;
}
void F_3 ( T_1 V_2 )
{
V_3 = V_2 * 2 ;
}
static bool F_4 ( void )
{
T_2 V_4 , V_5 = F_5 () ;
V_4 = V_5 - F_6 ( V_6 ) ;
if ( V_4 < V_3 ) {
if ( F_7 ( V_7 ) < 10 )
return false ;
}
F_8 ( V_7 , 0 ) ;
F_8 ( V_6 , V_5 ) ;
return true ;
}
static inline bool F_4 ( void )
{
return true ;
}
static void F_9 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
struct V_12 * V_13 )
{
V_9 -> V_14 . V_15 = 0 ;
if ( F_6 ( V_1 ) == true ) {
F_8 ( V_1 , false ) ;
return;
}
if ( ! F_4 () )
return;
if ( F_10 () ) {
int V_16 = F_11 () ;
if ( F_6 ( V_17 ) == true )
return;
F_12 ( L_1 , V_16 ) ;
F_13 () ;
F_14 ( V_18 ) ;
if ( V_13 )
F_15 ( V_13 ) ;
else
F_16 () ;
if ( V_19 &&
! F_17 ( 0 , & V_20 ) )
F_18 () ;
if ( V_21 )
F_19 ( V_13 , L_2 ) ;
F_8 ( V_17 , true ) ;
return;
}
F_8 ( V_17 , false ) ;
return;
}
static int F_20 ( void )
{
unsigned int V_22 = F_11 () ;
struct V_23 * V_24 ;
struct V_8 * V_25 ;
V_24 = & V_26 ;
V_24 -> V_27 = F_21 ( V_28 ) ;
V_25 = F_22 ( V_24 , V_22 , NULL ,
F_9 , NULL ) ;
if ( F_23 ( V_25 ) ) {
F_24 ( L_3 , V_22 ,
F_25 ( V_25 ) ) ;
return F_25 ( V_25 ) ;
}
F_26 ( V_29 , V_25 ) ;
return 0 ;
}
void F_27 ( void )
{
if ( F_20 () )
return;
if ( ! F_28 ( & V_30 ) )
F_24 ( L_4 ) ;
F_29 ( F_30 ( V_29 ) ) ;
}
void F_31 ( void )
{
struct V_8 * V_9 = F_30 ( V_29 ) ;
if ( V_9 ) {
F_32 ( V_9 ) ;
F_26 ( V_29 , NULL ) ;
F_26 ( V_31 , V_9 ) ;
F_33 ( F_11 () , & V_32 ) ;
F_34 ( & V_30 ) ;
}
}
void F_35 ( void )
{
int V_22 ;
F_36 (cpu, &dead_events_mask) {
struct V_8 * V_9 = F_37 ( V_31 , V_22 ) ;
if ( V_9 )
F_38 ( V_9 ) ;
F_37 ( V_31 , V_22 ) = NULL ;
}
F_39 ( & V_32 ) ;
}
void T_3 F_40 ( void )
{
int V_22 ;
F_41 () ;
F_42 (cpu) {
struct V_8 * V_9 = F_37 ( V_29 , V_22 ) ;
if ( V_9 )
F_32 ( V_9 ) ;
}
}
void T_3 F_43 ( void )
{
int V_22 ;
F_41 () ;
if ( ! ( V_33 & V_34 ) )
return;
F_42 (cpu) {
struct V_8 * V_9 = F_37 ( V_29 , V_22 ) ;
if ( V_9 )
F_29 ( V_9 ) ;
}
}
int T_3 F_44 ( void )
{
int V_35 = F_20 () ;
if ( V_35 ) {
F_24 ( L_5 ) ;
} else {
F_38 ( F_30 ( V_29 ) ) ;
F_26 ( V_29 , NULL ) ;
}
return V_35 ;
}
