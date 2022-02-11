void F_1 ( void )
{
V_1 &= ~ V_2 ;
}
static int T_1 F_2 ( char * V_3 )
{
if ( ! strncmp ( V_3 , L_1 , 5 ) )
V_4 = 1 ;
else if ( ! strncmp ( V_3 , L_2 , 7 ) )
V_4 = 0 ;
else if ( ! strncmp ( V_3 , L_3 , 1 ) )
V_1 &= ~ V_2 ;
else if ( ! strncmp ( V_3 , L_4 , 1 ) )
V_1 |= V_2 ;
return 1 ;
}
void F_3 ( void )
{
F_4 ( V_5 , true ) ;
F_5 () ;
}
static void F_6 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_11 )
{
V_7 -> V_12 . V_13 = 0 ;
if ( F_7 ( & V_14 ) != 0 )
return;
if ( F_8 ( V_5 ) == true ) {
F_9 ( V_5 , false ) ;
return;
}
if ( F_10 () ) {
int V_15 = F_11 () ;
if ( F_8 ( V_16 ) == true )
return;
F_12 ( L_5 , V_15 ) ;
F_13 () ;
F_14 ( V_17 ) ;
if ( V_11 )
F_15 ( V_11 ) ;
else
F_16 () ;
if ( V_18 &&
! F_17 ( 0 , & V_19 ) )
F_18 () ;
if ( V_4 )
F_19 ( V_11 , L_6 ) ;
F_9 ( V_16 , true ) ;
return;
}
F_9 ( V_16 , false ) ;
return;
}
int F_20 ( unsigned int V_20 )
{
struct V_21 * V_22 ;
struct V_6 * V_7 = F_21 ( V_23 , V_20 ) ;
if ( ! ( V_1 & V_2 ) )
goto V_24;
if ( V_7 && V_7 -> V_25 > V_26 )
goto V_24;
if ( V_7 != NULL )
goto V_27;
V_22 = & V_28 ;
V_22 -> V_29 = F_22 ( V_30 ) ;
V_7 = F_23 ( V_22 , V_20 , NULL , F_6 , NULL ) ;
if ( V_20 == 0 && F_24 ( V_7 ) )
V_31 = F_25 ( V_7 ) ;
if ( ! F_24 ( V_7 ) ) {
if ( V_20 == 0 || V_31 )
F_26 ( L_7 ) ;
goto V_32;
}
F_27 () ;
F_28 ( V_33 , & V_1 ) ;
F_29 () ;
if ( V_20 > 0 && ( F_25 ( V_7 ) == V_31 ) )
return F_25 ( V_7 ) ;
if ( F_25 ( V_7 ) == - V_34 )
F_26 ( L_8 , V_20 ) ;
else if ( F_25 ( V_7 ) == - V_35 )
F_30 ( L_9 ,
V_20 ) ;
else
F_31 ( L_10 ,
V_20 , F_25 ( V_7 ) ) ;
F_26 ( L_11 ) ;
return F_25 ( V_7 ) ;
V_32:
F_21 ( V_23 , V_20 ) = V_7 ;
V_27:
F_32 ( F_21 ( V_23 , V_20 ) ) ;
V_24:
return 0 ;
}
void F_33 ( unsigned int V_20 )
{
struct V_6 * V_7 = F_21 ( V_23 , V_20 ) ;
if ( V_7 ) {
F_34 ( V_7 ) ;
F_21 ( V_23 , V_20 ) = NULL ;
F_35 ( V_7 ) ;
}
if ( V_20 == 0 ) {
V_31 = 0 ;
}
}
