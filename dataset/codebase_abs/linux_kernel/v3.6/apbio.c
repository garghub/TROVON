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
static V_10 F_10 ( unsigned long V_17 )
{
struct V_14 V_15 ;
int V_18 ;
if ( ! V_4 && ! F_1 () )
return F_11 ( V_17 ) ;
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
F_12 ( V_16 ) ;
F_13 ( V_4 , & V_15 ) ;
V_18 = F_14 ( & V_16 ,
F_15 ( 50 ) ) ;
if ( F_16 ( V_18 == 0 , L_2 ) ) {
F_17 ( V_4 , & V_15 ) ;
* ( V_10 * ) V_9 = 0 ;
}
F_7 ( & V_3 ) ;
return * ( ( V_10 * ) V_9 ) ;
}
static void F_18 ( V_10 V_29 , unsigned long V_17 )
{
struct V_14 V_15 ;
int V_18 ;
if ( ! V_4 && ! F_1 () ) {
F_19 ( V_29 , V_17 ) ;
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
F_12 ( V_16 ) ;
F_13 ( V_4 , & V_15 ) ;
V_18 = F_14 ( & V_16 ,
F_15 ( 50 ) ) ;
if ( F_16 ( V_18 == 0 , L_3 ) )
F_17 ( V_4 , & V_15 ) ;
F_7 ( & V_3 ) ;
}
bool F_20 ( void )
{
T_1 V_30 ;
F_2 ( & V_3 ) ;
if ( V_31 )
goto V_32;
F_21 ( V_30 ) ;
F_22 ( V_33 , V_30 ) ;
V_31 = F_23 ( V_30 , NULL , NULL ) ;
if ( ! V_31 ) {
F_24 ( L_4 , V_13 ) ;
goto V_34;
}
V_9 = F_4 ( NULL , sizeof( V_10 ) ,
& V_11 , V_12 ) ;
if ( ! V_9 ) {
F_5 ( L_1 , V_13 ) ;
goto V_35;
}
V_36 . V_37 = V_38 ;
V_36 . V_39 = V_38 ;
V_36 . V_40 = V_27 ;
V_36 . V_41 = 1 ;
V_36 . V_42 = 1 ;
V_32:
F_7 ( & V_3 ) ;
return true ;
V_35:
F_25 ( V_31 ) ;
V_31 = NULL ;
V_34:
F_7 ( & V_3 ) ;
return false ;
}
static void F_8 ( void * args )
{
F_9 ( & V_16 ) ;
}
static int F_26 ( unsigned long V_43 ,
enum V_44 V_45 )
{
struct V_46 * V_47 ;
int V_18 ;
if ( V_45 == V_48 )
V_36 . V_49 = V_43 ;
else
V_36 . V_50 = V_43 ;
V_18 = F_27 ( V_31 , & V_36 ) ;
if ( V_18 )
return V_18 ;
V_47 = F_28 ( V_31 ,
V_11 , sizeof( V_10 ) , V_45 ,
V_51 | V_52 ) ;
if ( ! V_47 )
return - V_53 ;
V_47 -> V_54 = F_8 ;
V_47 -> V_55 = NULL ;
F_12 ( V_16 ) ;
F_29 ( V_47 ) ;
F_30 ( V_31 ) ;
V_18 = F_14 ( & V_16 ,
F_15 ( 50 ) ) ;
if ( F_16 ( V_18 == 0 , L_2 ) ) {
F_31 ( V_31 ) ;
return - V_56 ;
}
return 0 ;
}
static V_10 F_10 ( unsigned long V_17 )
{
int V_18 ;
if ( ! V_31 && ! F_20 () )
return F_11 ( V_17 ) ;
F_2 ( & V_3 ) ;
V_18 = F_26 ( V_17 , V_48 ) ;
if ( V_18 < 0 ) {
F_5 ( L_5 , V_17 ) ;
* ( V_10 * ) V_9 = 0 ;
}
F_7 ( & V_3 ) ;
return * ( ( V_10 * ) V_9 ) ;
}
static void F_18 ( V_10 V_29 , unsigned long V_17 )
{
int V_18 ;
if ( ! V_31 && ! F_20 () ) {
F_19 ( V_29 , V_17 ) ;
return;
}
F_2 ( & V_3 ) ;
* ( ( V_10 * ) V_9 ) = V_29 ;
V_18 = F_26 ( V_17 , V_57 ) ;
if ( V_18 < 0 )
F_5 ( L_6 , V_17 ) ;
F_7 ( & V_3 ) ;
}
static V_10 F_11 ( unsigned long V_17 )
{
return F_32 ( F_33 ( V_17 ) ) ;
}
static void F_19 ( V_10 V_29 , unsigned long V_17 )
{
F_34 ( V_29 , F_33 ( V_17 ) ) ;
}
void F_35 ( void )
{
if ( F_36 ( L_7 ) ||
! F_37 () ) {
V_58 = F_10 ;
V_59 = F_18 ;
} else {
V_58 = F_11 ;
V_59 = F_19 ;
}
}
V_10 F_38 ( unsigned long V_17 )
{
return V_58 ( V_17 ) ;
}
void F_39 ( V_10 V_29 , unsigned long V_17 )
{
V_59 ( V_29 , V_17 ) ;
}
