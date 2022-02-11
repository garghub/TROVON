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
if ( F_10 ( & V_16 ) != 0 )
return;
if ( F_6 ( V_1 ) == true ) {
F_8 ( V_1 , false ) ;
return;
}
if ( ! F_4 () )
return;
if ( F_11 () ) {
int V_17 = F_12 () ;
if ( F_6 ( V_18 ) == true )
return;
F_13 ( L_1 , V_17 ) ;
F_14 () ;
F_15 ( V_19 ) ;
if ( V_13 )
F_16 ( V_13 ) ;
else
F_17 () ;
if ( V_20 &&
! F_18 ( 0 , & V_21 ) )
F_19 () ;
if ( V_22 )
F_20 ( V_13 , L_2 ) ;
F_8 ( V_18 , true ) ;
return;
}
F_8 ( V_18 , false ) ;
return;
}
int F_21 ( unsigned int V_23 )
{
struct V_24 * V_25 ;
struct V_8 * V_9 = F_22 ( V_26 , V_23 ) ;
int V_27 = 0 ;
if ( ! ( V_28 & V_29 ) )
goto V_30;
if ( V_9 && V_9 -> V_31 > V_32 )
goto V_30;
if ( V_9 != NULL )
goto V_33;
if ( F_23 ( & V_34 ) == 1 )
V_27 = 1 ;
V_25 = & V_35 ;
V_25 -> V_36 = F_24 ( V_37 ) ;
V_9 = F_25 ( V_25 , V_23 , NULL , F_9 , NULL ) ;
if ( V_27 && F_26 ( V_9 ) )
V_38 = F_27 ( V_9 ) ;
if ( ! F_26 ( V_9 ) ) {
if ( V_27 || V_38 )
F_28 ( L_3 ) ;
goto V_39;
}
F_29 () ;
F_30 ( V_40 , & V_28 ) ;
F_31 () ;
if ( ! V_27 && ( F_27 ( V_9 ) == V_38 ) )
return F_27 ( V_9 ) ;
if ( F_27 ( V_9 ) == - V_41 )
F_28 ( L_4 , V_23 ) ;
else if ( F_27 ( V_9 ) == - V_42 )
F_32 ( L_5 ,
V_23 ) ;
else
F_33 ( L_6 ,
V_23 , F_27 ( V_9 ) ) ;
F_28 ( L_7 ) ;
return F_27 ( V_9 ) ;
V_39:
F_22 ( V_26 , V_23 ) = V_9 ;
V_33:
F_34 ( F_22 ( V_26 , V_23 ) ) ;
V_30:
return 0 ;
}
void F_35 ( unsigned int V_23 )
{
struct V_8 * V_9 = F_22 ( V_26 , V_23 ) ;
if ( V_9 ) {
F_36 ( V_9 ) ;
F_22 ( V_26 , V_23 ) = NULL ;
F_37 ( V_9 ) ;
if ( F_38 ( & V_34 ) )
V_38 = 0 ;
}
}
