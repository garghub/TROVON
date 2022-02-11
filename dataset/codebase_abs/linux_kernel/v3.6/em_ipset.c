static int F_1 ( struct V_1 * V_2 , void * V_3 , int V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_3 ;
T_1 V_9 ;
if ( V_4 != sizeof( * V_8 ) )
return - V_10 ;
V_9 = F_2 ( V_8 -> V_9 ) ;
if ( V_9 == V_11 )
return - V_12 ;
V_6 -> V_13 = sizeof( * V_8 ) ;
V_6 -> V_3 = ( unsigned long ) F_3 ( V_3 , V_6 -> V_13 , V_14 ) ;
if ( V_6 -> V_3 )
return 0 ;
F_4 ( V_9 ) ;
return - V_15 ;
}
static void F_5 ( struct V_1 * V_16 , struct V_5 * V_6 )
{
const struct V_7 * V_8 = ( const void * ) V_6 -> V_3 ;
if ( V_8 ) {
F_4 ( V_8 -> V_9 ) ;
F_6 ( ( void * ) V_6 -> V_3 ) ;
}
}
static int F_7 ( struct V_17 * V_18 , struct V_5 * V_6 ,
struct V_19 * V_20 )
{
struct V_21 V_22 ;
struct V_23 V_24 ;
const struct V_7 * V_8 = ( const void * ) V_6 -> V_3 ;
struct V_25 * V_26 , * V_27 = NULL ;
int V_28 , V_29 ;
switch ( V_18 -> V_30 ) {
case F_8 ( V_31 ) :
V_24 . V_32 = V_33 ;
if ( ! F_9 ( V_18 , sizeof( struct V_34 ) ) )
return 0 ;
V_24 . V_35 = F_10 ( V_18 ) ;
break;
case F_8 ( V_36 ) :
V_24 . V_32 = V_37 ;
if ( ! F_9 ( V_18 , sizeof( struct V_38 ) ) )
return 0 ;
V_24 . V_35 = sizeof( struct V_38 ) ;
break;
default:
return 0 ;
}
V_24 . V_39 = 0 ;
V_22 . V_32 = V_24 . V_32 ;
V_22 . V_40 = V_8 -> V_40 ;
V_22 . V_41 = V_8 -> V_41 ;
V_22 . V_42 = 0 ;
V_22 . V_43 = ~ 0u ;
V_29 = F_11 ( V_18 ) ;
F_12 ( V_18 , V_29 ) ;
V_26 = V_18 -> V_26 ;
F_13 () ;
if ( V_26 && V_18 -> V_44 )
V_27 = F_14 ( F_15 ( V_26 ) , V_18 -> V_44 ) ;
V_24 . V_45 = V_27 ? V_27 : V_26 ;
V_24 . V_46 = V_26 ;
V_28 = F_16 ( V_8 -> V_9 , V_18 , & V_24 , & V_22 ) ;
F_17 () ;
F_18 ( V_18 , V_29 ) ;
return V_28 ;
}
static int T_2 F_19 ( void )
{
return F_20 ( & V_47 ) ;
}
static void T_3 F_21 ( void )
{
F_22 ( & V_47 ) ;
}
