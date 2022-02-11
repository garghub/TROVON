static unsigned int
F_1 ( void * V_1 ,
struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_6 V_7 ;
switch ( F_2 ( V_3 ) -> V_8 ) {
case F_3 ( V_9 ) :
F_4 ( & V_7 , V_3 , V_5 ) ;
break;
case F_3 ( V_10 ) :
F_5 ( & V_7 , V_3 , V_5 ) ;
break;
default:
F_6 ( & V_7 , V_3 , V_5 ) ;
break;
}
return F_7 ( & V_7 , V_1 ) ;
}
static int F_8 ( struct V_11 * V_11 )
{
V_11 -> V_12 . V_13 = F_9 ( sizeof( struct V_14 ) , V_15 ) ;
if ( V_11 -> V_12 . V_13 == NULL )
return - V_16 ;
memcpy ( V_11 -> V_12 . V_13 , & V_17 , sizeof( V_17 ) ) ;
if ( F_10 ( V_11 , V_11 -> V_12 . V_13 ) < 0 )
goto V_18;
return 0 ;
V_18:
F_11 ( V_11 -> V_12 . V_13 ) ;
return - V_16 ;
}
static void F_12 ( struct V_11 * V_11 )
{
F_13 ( V_11 , V_11 -> V_12 . V_13 ) ;
F_11 ( V_11 -> V_12 . V_13 ) ;
}
static void F_14 ( const struct V_2 * V_3 ,
struct V_19 * V_20 )
{
}
static int F_15 ( struct V_11 * V_11 , struct V_2 * V_3 ,
const struct V_19 * V_20 )
{
return 0 ;
}
static T_1 F_16 ( struct V_2 * V_3 , unsigned int V_21 ,
unsigned int V_22 , T_2 V_23 )
{
return 0 ;
}
static T_1 F_17 ( struct V_2 * V_3 , unsigned int V_21 ,
unsigned int V_22 , unsigned int V_24 ,
T_2 V_23 )
{
return 0 ;
}
static int F_18 ( struct V_11 * V_11 , struct V_25 * * V_26 ,
struct V_27 * V_28 , bool T_3 V_29 )
{
return 0 ;
}
static int T_4 F_19 ( void )
{
int V_30 ;
F_20 ( & V_31 ) ;
V_30 = F_21 ( & V_32 ) ;
if ( V_30 < 0 )
goto V_33;
V_30 = F_22 ( & V_34 ) ;
if ( V_30 < 0 )
goto V_35;
return V_30 ;
V_35:
F_23 ( & V_32 ) ;
V_33:
F_24 ( & V_31 ) ;
return V_30 ;
}
static void T_5 F_25 ( void )
{
F_26 ( & V_34 ) ;
F_23 ( & V_32 ) ;
F_24 ( & V_31 ) ;
}
