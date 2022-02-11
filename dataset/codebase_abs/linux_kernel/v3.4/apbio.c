bool F_1 ( void )
{
struct V_1 * V_2 ;
F_2 ( & V_3 ) ;
if ( V_4 )
goto V_5;
V_2 = F_3 ( V_6 |
V_7 ) ;
if ( ! V_2 )
goto V_8;
V_9 = F_4 ( NULL , sizeof( V_10 ) ,
& V_11 , V_12 ) ;
if ( ! V_9 ) {
F_5 ( L_1 , V_13 ) ;
F_6 ( V_2 ) ;
goto V_8;
}
V_4 = V_2 ;
V_5:
F_7 ( & V_3 ) ;
return true ;
V_8:
F_7 ( & V_3 ) ;
return false ;
}
static void F_8 ( struct V_14 * V_15 )
{
F_9 ( & V_16 ) ;
}
V_10 F_10 ( unsigned long V_17 )
{
struct V_14 V_15 ;
int V_18 ;
if ( ! V_4 && ! F_1 () )
return F_11 ( F_12 ( V_17 ) ) ;
F_2 ( & V_3 ) ;
V_15 . F_9 = F_8 ;
V_15 . V_19 = 1 ;
V_15 . V_20 = V_11 ;
V_15 . V_21 = 32 ;
V_15 . V_22 = 1 ;
V_15 . V_23 = V_17 ;
V_15 . V_24 = 32 ;
V_15 . V_25 = 4 ;
V_15 . V_26 = V_27 ;
V_15 . V_28 = 4 ;
F_13 ( V_16 ) ;
F_14 ( V_4 , & V_15 ) ;
V_18 = F_15 ( & V_16 ,
F_16 ( 50 ) ) ;
if ( F_17 ( V_18 == 0 , L_2 ) ) {
F_18 ( V_4 , & V_15 ) ;
* ( V_10 * ) V_9 = 0 ;
}
F_7 ( & V_3 ) ;
return * ( ( V_10 * ) V_9 ) ;
}
void F_19 ( V_10 V_29 , unsigned long V_17 )
{
struct V_14 V_15 ;
int V_18 ;
if ( ! V_4 && ! F_1 () ) {
F_20 ( V_29 , F_12 ( V_17 ) ) ;
return;
}
F_2 ( & V_3 ) ;
* ( ( V_10 * ) V_9 ) = V_29 ;
V_15 . F_9 = F_8 ;
V_15 . V_19 = 0 ;
V_15 . V_20 = V_17 ;
V_15 . V_22 = 4 ;
V_15 . V_21 = 32 ;
V_15 . V_23 = V_11 ;
V_15 . V_24 = 32 ;
V_15 . V_25 = 1 ;
V_15 . V_26 = V_27 ;
V_15 . V_28 = 4 ;
F_13 ( V_16 ) ;
F_14 ( V_4 , & V_15 ) ;
V_18 = F_15 ( & V_16 ,
F_16 ( 50 ) ) ;
if ( F_17 ( V_18 == 0 , L_3 ) )
F_18 ( V_4 , & V_15 ) ;
F_7 ( & V_3 ) ;
}
