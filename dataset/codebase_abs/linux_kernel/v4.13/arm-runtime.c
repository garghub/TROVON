static int T_1 F_1 ( void )
{
return F_2 ( & V_1 , L_1 ) ;
}
static bool T_1 F_3 ( void )
{
T_2 * V_2 ;
bool V_3 ;
V_4 . V_5 = F_4 ( & V_4 ) ;
F_5 ( & V_4 ) ;
F_6 ( NULL , & V_4 ) ;
V_3 = false ;
F_7 (md) {
T_3 V_6 = V_2 -> V_7 ;
int V_8 ;
if ( ! ( V_2 -> V_9 & V_10 ) )
continue;
if ( V_2 -> V_11 == 0 )
return false ;
V_8 = F_8 ( & V_4 , V_2 ) ;
if ( ! V_8 ) {
F_9 ( L_2 ,
& V_6 , ( void * ) ( unsigned long ) V_2 -> V_11 ) ;
} else {
F_10 ( L_3 ,
& V_6 , V_8 ) ;
return false ;
}
if ( V_12 >= V_6 &&
V_12 < V_6 + ( V_2 -> V_13 * V_14 ) ) {
V_15 . V_16 = ( void * ) ( unsigned long ) ( V_12 -
V_6 + V_2 -> V_11 ) ;
V_3 = true ;
}
}
if ( ! V_3 ) {
F_11 ( L_4 ) ;
return false ;
}
if ( F_12 ( & V_4 , V_17 ) )
return false ;
return true ;
}
static int T_1 F_13 ( void )
{
T_4 V_18 ;
if ( ! F_14 ( V_19 ) ) {
F_9 ( L_5 ) ;
return 0 ;
}
if ( F_15 () ) {
F_9 ( L_6 ) ;
return 0 ;
}
if ( F_14 ( V_20 ) ) {
F_9 ( L_7 ) ;
return 0 ;
}
F_9 ( L_8 ) ;
V_18 = V_15 . V_21 . V_22 * V_15 . V_21 . V_23 ;
if ( F_16 ( V_15 . V_21 . V_24 , V_18 ) ) {
F_11 ( L_9 ) ;
return - V_25 ;
}
if ( ! F_3 () ) {
F_11 ( L_10 ) ;
return - V_25 ;
}
F_17 () ;
F_18 ( V_20 , & V_15 . V_26 ) ;
return 0 ;
}
void F_19 ( void )
{
F_20 () ;
F_21 ( & V_4 ) ;
}
void F_22 ( void )
{
F_21 ( V_27 -> V_28 ) ;
F_23 () ;
}
static int T_1 F_24 ( void )
{
F_25 () ;
if ( V_29 )
F_26 () ;
return 0 ;
}
