static int F_1 ( struct V_1 * V_1 , void * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_2 ;
T_1 V_8 ;
if ( V_3 != sizeof( * V_7 ) )
return - V_9 ;
V_8 = F_2 ( V_1 , V_7 -> V_8 ) ;
if ( V_8 == V_10 )
return - V_11 ;
V_5 -> V_12 = sizeof( * V_7 ) ;
V_5 -> V_2 = ( unsigned long ) F_3 ( V_2 , V_5 -> V_12 , V_13 ) ;
if ( V_5 -> V_2 )
return 0 ;
F_4 ( V_1 , V_8 ) ;
return - V_14 ;
}
static void F_5 ( struct V_4 * V_5 )
{
const struct V_6 * V_7 = ( const void * ) V_5 -> V_2 ;
if ( V_7 ) {
F_4 ( V_5 -> V_1 , V_7 -> V_8 ) ;
F_6 ( ( void * ) V_5 -> V_2 ) ;
}
}
static int F_7 ( struct V_15 * V_16 , struct V_4 * V_5 ,
struct V_17 * V_18 )
{
struct V_19 V_20 ;
struct V_21 V_22 ;
const struct V_6 * V_7 = ( const void * ) V_5 -> V_2 ;
struct V_23 * V_24 , * V_25 = NULL ;
int V_26 , V_27 ;
switch ( F_8 ( V_16 ) ) {
case F_9 ( V_28 ) :
V_22 . V_29 = V_30 ;
if ( ! F_10 ( V_16 , sizeof( struct V_31 ) ) )
return 0 ;
V_22 . V_32 = F_11 ( V_16 ) ;
break;
case F_9 ( V_33 ) :
V_22 . V_29 = V_34 ;
if ( ! F_10 ( V_16 , sizeof( struct V_35 ) ) )
return 0 ;
V_22 . V_32 = sizeof( struct V_35 ) ;
break;
default:
return 0 ;
}
V_22 . V_36 = 0 ;
V_20 . V_29 = V_22 . V_29 ;
V_20 . V_37 = V_7 -> V_37 ;
V_20 . V_38 = V_7 -> V_38 ;
V_20 . V_39 = 0 ;
V_20 . V_40 . V_41 = ~ 0u ;
V_27 = F_12 ( V_16 ) ;
F_13 ( V_16 , V_27 ) ;
V_24 = V_16 -> V_24 ;
F_14 () ;
if ( V_16 -> V_42 )
V_25 = F_15 ( V_5 -> V_1 , V_16 -> V_42 ) ;
V_22 . V_43 = V_25 ? V_25 : V_24 ;
V_22 . V_44 = V_24 ;
V_26 = F_16 ( V_7 -> V_8 , V_16 , & V_22 , & V_20 ) ;
F_17 () ;
F_18 ( V_16 , V_27 ) ;
return V_26 ;
}
static int T_2 F_19 ( void )
{
return F_20 ( & V_45 ) ;
}
static void T_3 F_21 ( void )
{
F_22 ( & V_45 ) ;
}
