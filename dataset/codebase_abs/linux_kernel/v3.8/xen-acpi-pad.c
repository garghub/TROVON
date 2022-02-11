static int F_1 ( unsigned int V_1 )
{
struct V_2 V_3 ;
V_3 . V_4 = V_5 ;
V_3 . V_6 . V_7 . type = V_8 ;
V_3 . V_6 . V_7 . V_1 = V_1 ;
return F_2 ( & V_3 ) ;
}
static int F_3 ( void )
{
struct V_2 V_3 ;
V_3 . V_4 = V_5 ;
V_3 . V_6 . V_7 . type = V_9 ;
return F_2 ( & V_3 )
? : V_3 . V_6 . V_7 . V_1 ;
}
static int F_4 ( T_1 V_10 )
{
struct V_11 V_12 = { V_13 , NULL } ;
union V_14 * V_15 ;
int V_16 = - 1 ;
if ( F_5 ( F_6 ( V_10 , L_1 , NULL , & V_12 ) ) )
return V_16 ;
if ( ! V_12 . V_17 || ! V_12 . V_18 )
return V_16 ;
V_15 = V_12 . V_18 ;
if ( V_15 -> type == V_19 &&
V_15 -> V_15 . V_20 == 2 &&
V_15 -> V_15 . V_21 [ 0 ] . integer . V_22 == 1 )
V_16 = V_15 -> V_15 . V_21 [ 1 ] . integer . V_22 ;
F_7 ( V_12 . V_18 ) ;
return V_16 ;
}
static void F_8 ( T_1 V_10 , int V_23 ,
T_2 V_1 )
{
union V_14 V_24 [ 3 ] = {
{ . type = V_25 ,} ,
{ . type = V_25 ,} ,
{ . type = V_26 ,} ,
} ;
struct V_27 V_28 = { 3 , V_24 } ;
V_24 [ 0 ] . integer . V_22 = V_29 ;
V_24 [ 1 ] . integer . V_22 = V_23 ;
V_24 [ 2 ] . V_12 . V_17 = 4 ;
V_24 [ 2 ] . V_12 . V_18 = ( void * ) & V_1 ;
F_6 ( V_10 , L_2 , & V_28 , NULL ) ;
}
static void F_9 ( T_1 V_10 )
{
int V_1 ;
F_10 ( & V_30 ) ;
V_1 = F_4 ( V_10 ) ;
if ( V_1 < 0 ) {
F_11 ( & V_30 ) ;
return;
}
V_1 = F_1 ( V_1 )
? : F_3 () ;
if ( V_1 >= 0 )
F_8 ( V_10 , 0 , V_1 ) ;
F_11 ( & V_30 ) ;
}
static void F_12 ( T_1 V_10 , T_3 V_31 ,
void * V_32 )
{
switch ( V_31 ) {
case V_29 :
F_9 ( V_10 ) ;
break;
default:
F_13 ( L_3 , V_31 ) ;
break;
}
}
static int F_14 ( struct V_33 * V_34 )
{
T_4 V_35 ;
strcpy ( F_15 ( V_34 ) , V_36 ) ;
strcpy ( F_16 ( V_34 ) , V_37 ) ;
V_35 = F_17 ( V_34 -> V_10 ,
V_38 , F_12 , V_34 ) ;
if ( F_5 ( V_35 ) )
return - V_39 ;
return 0 ;
}
static int F_18 ( struct V_33 * V_34 ,
int type )
{
F_10 ( & V_30 ) ;
F_1 ( 0 ) ;
F_11 ( & V_30 ) ;
F_19 ( V_34 -> V_10 ,
V_38 , F_12 ) ;
return 0 ;
}
static int T_5 F_20 ( void )
{
if ( ! F_21 () )
return - V_39 ;
if ( ! F_22 ( 4 , 2 ) )
return - V_39 ;
return F_23 ( & V_40 ) ;
}
