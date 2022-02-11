static int F_1 ( T_1 * V_1 , T_2 V_2 )
{
T_1 V_3 ;
T_3 V_4 ;
struct V_5 V_6 = { V_7 , NULL } ;
union V_8 * V_9 ;
if ( ! V_1 )
return - V_10 ;
if ( V_2 > 2 )
return - V_11 ;
V_4 = F_2 ( V_12 , V_2 , & V_6 ) ;
if ( F_3 ( V_4 ) )
return - V_11 ;
V_9 = (union V_8 * ) V_6 . V_13 ;
if ( V_9 && V_9 -> type == V_14 ) {
V_3 = V_9 -> integer . V_15 ;
} else {
V_3 = 0 ;
}
if ( V_6 . V_16 > 0 )
F_4 ( V_6 . V_13 ) ;
switch ( V_2 ) {
case V_17 :
* V_1 = ( V_3 == 3 ) ? 1 : 0 ;
return 0 ;
case V_18 :
* V_1 = ( V_3 == 1 ) ? 0 : 1 ;
return 0 ;
default:
return - V_11 ;
}
}
static int F_5 ( T_1 * V_19 , T_2 V_2 )
{
T_1 V_15 ;
T_3 V_4 ;
struct V_5 V_20 ;
if ( ! V_19 )
return - V_10 ;
if ( V_2 > 2 )
return - V_11 ;
switch ( V_2 ) {
case V_17 :
V_15 = ( * V_19 ) ? 1 : 2 ;
break;
case V_18 :
V_15 = ( * V_19 ) ? 0 : 1 ;
break;
default:
return - V_11 ;
}
V_20 . V_16 = sizeof( T_1 ) ;
V_20 . V_13 = & V_15 ;
V_4 = F_6 ( V_12 , V_2 , & V_20 ) ;
if ( F_3 ( V_4 ) )
return - V_11 ;
return 0 ;
}
static int T_4 F_7 ( struct V_21 * V_22 )
{
return F_8 ( & V_22 -> V_23 . V_24 , & V_25 ) ;
}
static int F_9 ( struct V_21 * V_22 )
{
F_10 ( & V_22 -> V_23 . V_24 , & V_25 ) ;
return 0 ;
}
static int F_11 ( struct V_22 * V_23 )
{
int V_26 ;
V_26 = F_1 ( & V_27 . V_28 , V_17 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_1 ( & V_27 . V_29 , V_18 ) ;
if ( V_26 )
return V_26 ;
return 0 ;
}
static int F_12 ( struct V_22 * V_23 )
{
int V_26 ;
V_26 = F_5 ( & V_27 . V_28 , V_17 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_5 ( & V_27 . V_29 , V_18 ) ;
if ( V_26 )
return V_26 ;
return 0 ;
}
static int T_4 F_13 ( void )
{
int error ;
if ( ! F_14 ( V_12 ) )
return - V_11 ;
V_30 = F_15 ( L_1 , - 1 ) ;
if ( ! V_30 )
return - V_31 ;
error = F_16 ( V_30 ) ;
if ( error )
goto V_32;
error = F_17 ( & V_33 , F_7 ) ;
if ( error )
goto V_34;
F_18 ( L_2 ) ;
return 0 ;
V_34:
F_19 ( V_30 ) ;
V_32:
F_20 ( V_30 ) ;
return error ;
}
static void T_5 F_21 ( void )
{
F_22 ( V_30 ) ;
F_23 ( & V_33 ) ;
}
