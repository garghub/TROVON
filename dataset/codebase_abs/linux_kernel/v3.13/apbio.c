static bool F_1 ( void )
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
V_13 . V_17 = 1 ;
V_13 . V_18 = 1 ;
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
F_12 ( & V_19 ) ;
}
static int F_13 ( unsigned long V_20 ,
enum V_21 V_22 )
{
struct V_23 * V_24 ;
int V_25 ;
if ( V_22 == V_26 )
V_13 . V_27 = V_20 ;
else
V_13 . V_28 = V_20 ;
V_25 = F_14 ( V_3 , & V_13 ) ;
if ( V_25 )
return V_25 ;
V_24 = F_15 ( V_3 ,
V_10 , sizeof( V_9 ) , V_22 ,
V_29 | V_30 ) ;
if ( ! V_24 )
return - V_31 ;
V_24 -> V_32 = F_11 ;
V_24 -> V_33 = NULL ;
F_16 ( & V_19 ) ;
F_17 ( V_24 ) ;
F_18 ( V_3 ) ;
V_25 = F_19 ( & V_19 ,
F_20 ( 50 ) ) ;
if ( F_21 ( V_25 == 0 , L_3 ) ) {
F_22 ( V_3 ) ;
return - V_34 ;
}
return 0 ;
}
static V_9 F_23 ( unsigned long V_35 )
{
int V_25 ;
if ( ! V_3 && ! F_1 () )
return F_24 ( V_35 ) ;
F_2 ( & V_2 ) ;
V_25 = F_13 ( V_35 , V_26 ) ;
if ( V_25 < 0 ) {
F_8 ( L_4 , V_35 ) ;
* ( V_9 * ) V_8 = 0 ;
}
F_9 ( & V_2 ) ;
return * ( ( V_9 * ) V_8 ) ;
}
static void F_25 ( V_9 V_36 , unsigned long V_35 )
{
int V_25 ;
if ( ! V_3 && ! F_1 () ) {
F_26 ( V_36 , V_35 ) ;
return;
}
F_2 ( & V_2 ) ;
* ( ( V_9 * ) V_8 ) = V_36 ;
V_25 = F_13 ( V_35 , V_37 ) ;
if ( V_25 < 0 )
F_8 ( L_5 , V_35 ) ;
F_9 ( & V_2 ) ;
}
static V_9 F_24 ( unsigned long V_35 )
{
return F_27 ( F_28 ( V_35 ) ) ;
}
static void F_26 ( V_9 V_36 , unsigned long V_35 )
{
F_29 ( V_36 , F_28 ( V_35 ) ) ;
}
void F_30 ( void )
{
if ( F_31 ( L_6 ) ||
! F_32 () ) {
V_38 = F_23 ;
V_39 = F_25 ;
} else {
V_38 = F_24 ;
V_39 = F_26 ;
}
}
V_9 F_33 ( unsigned long V_35 )
{
return V_38 ( V_35 ) ;
}
void F_34 ( V_9 V_36 , unsigned long V_35 )
{
V_39 ( V_36 , V_35 ) ;
}
