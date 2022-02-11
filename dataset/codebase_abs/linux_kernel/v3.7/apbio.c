bool F_1 ( void )
{
T_1 V_1 ;
F_2 ( & V_2 ) ;
if ( V_3 )
goto V_4;
F_3 ( V_1 ) ;
F_4 ( V_5 , V_1 ) ;
V_3 = F_5 ( V_1 , NULL , NULL ) ;
if ( ! V_3 ) {
F_6 ( L_1 , V_6 ) ;
goto V_7;
}
V_8 = F_7 ( NULL , sizeof( V_9 ) ,
& V_10 , V_11 ) ;
if ( ! V_8 ) {
F_8 ( L_2 , V_6 ) ;
goto V_12;
}
V_13 . V_14 = V_15 ;
V_13 . V_16 = V_15 ;
V_13 . V_17 = V_18 ;
V_13 . V_19 = 1 ;
V_13 . V_20 = 1 ;
V_4:
F_9 ( & V_2 ) ;
return true ;
V_12:
F_10 ( V_3 ) ;
V_3 = NULL ;
V_7:
F_9 ( & V_2 ) ;
return false ;
}
static void F_11 ( void * args )
{
F_12 ( & V_21 ) ;
}
static int F_13 ( unsigned long V_22 ,
enum V_23 V_24 )
{
struct V_25 * V_26 ;
int V_27 ;
if ( V_24 == V_28 )
V_13 . V_29 = V_22 ;
else
V_13 . V_30 = V_22 ;
V_27 = F_14 ( V_3 , & V_13 ) ;
if ( V_27 )
return V_27 ;
V_26 = F_15 ( V_3 ,
V_10 , sizeof( V_9 ) , V_24 ,
V_31 | V_32 ) ;
if ( ! V_26 )
return - V_33 ;
V_26 -> V_34 = F_11 ;
V_26 -> V_35 = NULL ;
F_16 ( V_21 ) ;
F_17 ( V_26 ) ;
F_18 ( V_3 ) ;
V_27 = F_19 ( & V_21 ,
F_20 ( 50 ) ) ;
if ( F_21 ( V_27 == 0 , L_3 ) ) {
F_22 ( V_3 ) ;
return - V_36 ;
}
return 0 ;
}
static V_9 F_23 ( unsigned long V_37 )
{
int V_27 ;
if ( ! V_3 && ! F_1 () )
return F_24 ( V_37 ) ;
F_2 ( & V_2 ) ;
V_27 = F_13 ( V_37 , V_28 ) ;
if ( V_27 < 0 ) {
F_8 ( L_4 , V_37 ) ;
* ( V_9 * ) V_8 = 0 ;
}
F_9 ( & V_2 ) ;
return * ( ( V_9 * ) V_8 ) ;
}
static void F_25 ( V_9 V_38 , unsigned long V_37 )
{
int V_27 ;
if ( ! V_3 && ! F_1 () ) {
F_26 ( V_38 , V_37 ) ;
return;
}
F_2 ( & V_2 ) ;
* ( ( V_9 * ) V_8 ) = V_38 ;
V_27 = F_13 ( V_37 , V_39 ) ;
if ( V_27 < 0 )
F_8 ( L_5 , V_37 ) ;
F_9 ( & V_2 ) ;
}
static V_9 F_24 ( unsigned long V_37 )
{
return F_27 ( F_28 ( V_37 ) ) ;
}
static void F_26 ( V_9 V_38 , unsigned long V_37 )
{
F_29 ( V_38 , F_28 ( V_37 ) ) ;
}
void F_30 ( void )
{
if ( F_31 ( L_6 ) ||
! F_32 () ) {
V_40 = F_23 ;
V_41 = F_25 ;
} else {
V_40 = F_24 ;
V_41 = F_26 ;
}
}
V_9 F_33 ( unsigned long V_37 )
{
return V_40 ( V_37 ) ;
}
void F_34 ( V_9 V_38 , unsigned long V_37 )
{
V_41 ( V_38 , V_37 ) ;
}
