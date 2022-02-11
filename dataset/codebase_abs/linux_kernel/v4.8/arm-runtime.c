static bool T_1 F_1 ( void )
{
T_2 * V_1 ;
bool V_2 ;
V_3 . V_4 = F_2 ( & V_3 ) ;
F_3 ( NULL , & V_3 ) ;
V_2 = false ;
F_4 (md) {
T_3 V_5 = V_1 -> V_6 ;
int V_7 ;
if ( ! ( V_1 -> V_8 & V_9 ) )
continue;
if ( V_1 -> V_10 == 0 )
return false ;
V_7 = F_5 ( & V_3 , V_1 ) ;
if ( ! V_7 ) {
F_6 ( L_1 ,
& V_5 , ( void * ) ( unsigned long ) V_1 -> V_10 ) ;
} else {
F_7 ( L_2 ,
& V_5 , V_7 ) ;
return false ;
}
if ( V_11 >= V_5 &&
V_11 < V_5 + ( V_1 -> V_12 * V_13 ) ) {
V_14 . V_15 = ( void * ) ( unsigned long ) ( V_11 -
V_5 + V_1 -> V_10 ) ;
V_2 = true ;
}
}
if ( ! V_2 ) {
F_8 ( L_3 ) ;
return false ;
}
if ( F_9 ( & V_3 , V_16 ) )
return false ;
return true ;
}
static int T_1 F_10 ( void )
{
T_4 V_17 ;
if ( ! F_11 ( V_18 ) ) {
F_6 ( L_4 ) ;
return 0 ;
}
if ( F_12 () ) {
F_6 ( L_5 ) ;
return 0 ;
}
if ( F_11 ( V_19 ) ) {
F_6 ( L_6 ) ;
return 0 ;
}
F_6 ( L_7 ) ;
V_17 = V_14 . V_20 . V_21 - V_14 . V_20 . V_22 ;
V_14 . V_20 . V_22 = F_13 ( V_14 . V_20 . V_23 , V_17 , V_24 ) ;
if ( ! V_14 . V_20 . V_22 ) {
F_8 ( L_8 ) ;
return - V_25 ;
}
V_14 . V_20 . V_21 = V_14 . V_20 . V_22 + V_17 ;
if ( ! F_1 () ) {
F_8 ( L_9 ) ;
return - V_25 ;
}
F_14 () ;
F_15 ( V_19 , & V_14 . V_26 ) ;
return 0 ;
}
void F_16 ( void )
{
F_17 () ;
F_18 ( & V_3 ) ;
}
void F_19 ( void )
{
F_18 ( V_27 -> V_28 ) ;
F_20 () ;
}
