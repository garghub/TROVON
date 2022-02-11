static bool T_1 F_1 ( void )
{
T_2 * V_1 ;
V_2 . V_3 = F_2 ( & V_2 ) ;
F_3 ( NULL , & V_2 ) ;
F_4 (&memmap, md) {
T_3 V_4 = V_1 -> V_5 ;
int V_6 ;
if ( ! ( V_1 -> V_7 & V_8 ) )
continue;
if ( V_1 -> V_9 == 0 )
return false ;
V_6 = F_5 ( & V_2 , V_1 ) ;
if ( ! V_6 ) {
F_6 ( L_1 ,
& V_4 , ( void * ) ( unsigned long ) V_1 -> V_9 ) ;
} else {
F_7 ( L_2 ,
& V_4 , V_6 ) ;
return false ;
}
}
return true ;
}
static int T_1 F_8 ( void )
{
T_4 V_10 ;
if ( ! F_9 ( V_11 ) ) {
F_6 ( L_3 ) ;
return 0 ;
}
if ( F_10 () ) {
F_6 ( L_4 ) ;
return 0 ;
}
F_6 ( L_5 ) ;
V_10 = V_12 . V_13 - V_12 . V_14 ;
V_12 . V_14 = ( V_15 void * ) F_11 ( V_12 . V_16 ,
V_10 ) ;
if ( ! V_12 . V_14 ) {
F_12 ( L_6 ) ;
return - V_17 ;
}
V_12 . V_13 = V_12 . V_14 + V_10 ;
V_18 . V_12 = & V_12 ;
V_18 . V_19 = ( V_15 void * ) F_11 ( V_20 ,
sizeof( V_21 ) ) ;
if ( ! V_18 . V_19 ) {
F_12 ( L_7 ) ;
return - V_17 ;
}
F_13 ( V_22 , & V_18 . V_23 ) ;
if ( ! F_1 () ) {
F_12 ( L_8 ) ;
return - V_17 ;
}
F_14 () ;
F_13 ( V_24 , & V_18 . V_23 ) ;
V_18 . V_25 = V_18 . V_19 -> V_26 . V_27 ;
return 0 ;
}
void F_15 ( void )
{
F_16 () ;
F_17 ( & V_2 ) ;
}
void F_18 ( void )
{
F_17 ( V_28 -> V_29 ) ;
F_19 () ;
}
