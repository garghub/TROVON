static int F_1 ( struct V_1 * V_2 , void * V_3 , int V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_3 ;
T_1 V_9 ;
struct V_10 * V_10 = F_2 ( F_3 ( V_2 -> V_11 ) ) ;
if ( V_4 != sizeof( * V_8 ) )
return - V_12 ;
V_9 = F_4 ( V_10 , V_8 -> V_9 ) ;
if ( V_9 == V_13 )
return - V_14 ;
V_6 -> V_15 = sizeof( * V_8 ) ;
V_6 -> V_3 = ( unsigned long ) F_5 ( V_3 , V_6 -> V_15 , V_16 ) ;
if ( V_6 -> V_3 )
return 0 ;
F_6 ( V_10 , V_9 ) ;
return - V_17 ;
}
static void F_7 ( struct V_1 * V_18 , struct V_5 * V_6 )
{
const struct V_7 * V_8 = ( const void * ) V_6 -> V_3 ;
if ( V_8 ) {
F_6 ( F_2 ( F_3 ( V_18 -> V_11 ) ) , V_8 -> V_9 ) ;
F_8 ( ( void * ) V_6 -> V_3 ) ;
}
}
static int F_9 ( struct V_19 * V_20 , struct V_5 * V_6 ,
struct V_21 * V_22 )
{
struct V_23 V_24 ;
struct V_25 V_26 ;
const struct V_7 * V_8 = ( const void * ) V_6 -> V_3 ;
struct V_27 * V_28 , * V_29 = NULL ;
int V_30 , V_31 ;
switch ( V_20 -> V_32 ) {
case F_10 ( V_33 ) :
V_26 . V_34 = V_35 ;
if ( ! F_11 ( V_20 , sizeof( struct V_36 ) ) )
return 0 ;
V_26 . V_37 = F_12 ( V_20 ) ;
break;
case F_10 ( V_38 ) :
V_26 . V_34 = V_39 ;
if ( ! F_11 ( V_20 , sizeof( struct V_40 ) ) )
return 0 ;
V_26 . V_37 = sizeof( struct V_40 ) ;
break;
default:
return 0 ;
}
V_26 . V_41 = 0 ;
V_24 . V_34 = V_26 . V_34 ;
V_24 . V_42 = V_8 -> V_42 ;
V_24 . V_43 = V_8 -> V_43 ;
V_24 . V_44 = 0 ;
V_24 . V_45 . V_46 = ~ 0u ;
V_31 = F_13 ( V_20 ) ;
F_14 ( V_20 , V_31 ) ;
V_28 = V_20 -> V_28 ;
F_15 () ;
if ( V_28 && V_20 -> V_47 )
V_29 = F_16 ( F_2 ( V_28 ) , V_20 -> V_47 ) ;
V_26 . V_48 = V_29 ? V_29 : V_28 ;
V_26 . V_49 = V_28 ;
V_30 = F_17 ( V_8 -> V_9 , V_20 , & V_26 , & V_24 ) ;
F_18 () ;
F_19 ( V_20 , V_31 ) ;
return V_30 ;
}
static int T_2 F_20 ( void )
{
return F_21 ( & V_50 ) ;
}
static void T_3 F_22 ( void )
{
F_23 ( & V_50 ) ;
}
