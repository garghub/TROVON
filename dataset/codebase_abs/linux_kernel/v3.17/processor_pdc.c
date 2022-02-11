static bool T_1 F_1 ( T_2 V_1 )
{
int V_2 , type ;
T_3 V_3 ;
T_4 V_4 ;
T_5 V_5 ;
unsigned long long V_6 ;
union V_7 V_8 = { 0 } ;
struct V_9 V_10 = { sizeof( union V_7 ) , & V_8 } ;
V_4 = F_2 ( V_1 , & V_5 ) ;
if ( F_3 ( V_4 ) )
return false ;
switch ( V_5 ) {
case V_11 :
V_4 = F_4 ( V_1 , NULL , NULL , & V_10 ) ;
if ( F_3 ( V_4 ) )
return false ;
V_3 = V_8 . V_12 . V_13 ;
break;
case V_14 :
V_4 = F_5 ( V_1 , L_1 , NULL , & V_6 ) ;
if ( F_3 ( V_4 ) )
return false ;
V_3 = V_6 ;
break;
default:
return false ;
}
type = ( V_5 == V_14 ) ? 1 : 0 ;
V_2 = F_6 ( V_1 , type , V_3 ) ;
if ( V_2 == - 1 )
return false ;
return true ;
}
static void F_7 ( T_3 * V_15 )
{
V_15 [ 0 ] = V_16 ;
V_15 [ 1 ] = 1 ;
V_15 [ 2 ] = V_17 ;
F_8 ( V_15 ) ;
}
static struct V_18 * F_9 ( void )
{
struct V_18 * V_19 ;
union V_7 * V_20 ;
T_3 * V_15 ;
V_19 = F_10 ( sizeof( struct V_18 ) , V_21 ) ;
if ( ! V_19 )
goto V_22;
V_20 = F_10 ( sizeof( union V_7 ) , V_21 ) ;
if ( ! V_20 ) {
F_11 ( V_19 ) ;
goto V_22;
}
V_15 = F_10 ( 12 , V_21 ) ;
if ( ! V_15 ) {
F_11 ( V_20 ) ;
F_11 ( V_19 ) ;
goto V_22;
}
F_7 ( V_15 ) ;
V_20 -> type = V_23 ;
V_20 -> V_10 . V_24 = 12 ;
V_20 -> V_10 . V_25 = ( V_26 * ) V_15 ;
V_19 -> V_27 = 1 ;
V_19 -> V_25 = V_20 ;
return V_19 ;
V_22:
F_12 ( L_2 ) ;
return NULL ;
}
static T_4
F_13 ( T_2 V_1 , struct V_18 * V_28 )
{
T_4 V_4 = V_29 ;
if ( V_30 == V_31 ) {
union V_7 * V_20 ;
T_3 * V_10 = NULL ;
V_20 = V_28 -> V_25 ;
V_10 = ( T_3 * ) ( V_20 -> V_10 . V_25 ) ;
V_10 [ 2 ] &= ~ ( V_32 | V_33 ) ;
}
V_4 = F_4 ( V_1 , L_3 , V_28 , NULL ) ;
if ( F_3 ( V_4 ) )
F_14 ( ( V_34 ,
L_4 ) ) ;
return V_4 ;
}
void F_15 ( T_2 V_1 )
{
struct V_18 * V_19 ;
if ( F_16 () == false )
return;
V_19 = F_9 () ;
if ( ! V_19 )
return;
F_13 ( V_1 , V_19 ) ;
F_11 ( V_19 -> V_25 -> V_10 . V_25 ) ;
F_11 ( V_19 -> V_25 ) ;
F_11 ( V_19 ) ;
}
static T_4 T_1
F_17 ( T_2 V_1 , T_3 V_35 , void * V_36 , void * * V_37 )
{
if ( F_1 ( V_1 ) == false )
return V_29 ;
F_15 ( V_1 ) ;
return V_29 ;
}
static int T_1 F_18 ( const struct V_38 * V_39 )
{
F_19 ( L_5 ,
V_39 -> V_40 ) ;
V_30 = V_31 ;
return 0 ;
}
static void T_1 F_20 ( void )
{
F_21 ( V_41 ) ;
}
void T_1 F_22 ( void )
{
F_20 () ;
F_23 ( V_11 , V_42 ,
V_43 ,
F_17 , NULL , NULL , NULL ) ;
F_24 ( V_44 , F_17 , NULL , NULL ) ;
}
