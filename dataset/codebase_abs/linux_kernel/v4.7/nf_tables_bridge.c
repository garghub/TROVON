int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 V_5 ;
if ( ! F_2 ( V_2 , sizeof( struct V_3 ) ) )
return 0 ;
V_4 = F_3 ( V_2 ) ;
if ( V_4 -> V_6 < 5 || V_4 -> V_7 != 4 )
return 0 ;
V_5 = F_4 ( V_4 -> V_8 ) ;
if ( V_2 -> V_5 < V_5 )
return 0 ;
else if ( V_5 < ( V_4 -> V_6 * 4 ) )
return 0 ;
if ( ! F_2 ( V_2 , V_4 -> V_6 * 4 ) )
return 0 ;
return 1 ;
}
int F_5 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
T_1 V_11 ;
if ( ! F_2 ( V_2 , sizeof( struct V_9 ) ) )
return 0 ;
V_10 = F_6 ( V_2 ) ;
if ( V_10 -> V_7 != 6 )
return 0 ;
V_11 = F_4 ( V_10 -> V_12 ) ;
if ( V_11 + sizeof( struct V_9 ) > V_2 -> V_5 )
return 0 ;
return 1 ;
}
static inline void F_7 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
const struct V_15 * V_16 )
{
if ( F_1 ( V_2 ) )
F_8 ( V_14 , V_2 , V_16 ) ;
else
F_9 ( V_14 , V_2 , V_16 ) ;
}
static inline void F_10 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
const struct V_15 * V_16 )
{
#if F_11 ( V_17 )
if ( F_5 ( V_2 ) &&
F_12 ( V_14 , V_2 , V_16 ) == 0 )
return;
#endif
F_9 ( V_14 , V_2 , V_16 ) ;
}
static unsigned int
F_13 ( void * V_18 ,
struct V_1 * V_2 ,
const struct V_15 * V_16 )
{
struct V_13 V_14 ;
switch ( F_14 ( V_2 ) -> V_19 ) {
case F_15 ( V_20 ) :
F_7 ( & V_14 , V_2 , V_16 ) ;
break;
case F_15 ( V_21 ) :
F_10 ( & V_14 , V_2 , V_16 ) ;
break;
default:
F_9 ( & V_14 , V_2 , V_16 ) ;
break;
}
return F_16 ( & V_14 , V_18 ) ;
}
static int F_17 ( struct V_22 * V_22 )
{
V_22 -> V_23 . V_24 = F_18 ( sizeof( struct V_25 ) , V_26 ) ;
if ( V_22 -> V_23 . V_24 == NULL )
return - V_27 ;
memcpy ( V_22 -> V_23 . V_24 , & V_28 , sizeof( V_28 ) ) ;
if ( F_19 ( V_22 , V_22 -> V_23 . V_24 ) < 0 )
goto V_29;
return 0 ;
V_29:
F_20 ( V_22 -> V_23 . V_24 ) ;
return - V_27 ;
}
static void F_21 ( struct V_22 * V_22 )
{
F_22 ( V_22 , V_22 -> V_23 . V_24 ) ;
F_20 ( V_22 -> V_23 . V_24 ) ;
}
static void F_23 ( const struct V_1 * V_2 ,
struct V_30 * V_31 )
{
}
static int F_24 ( struct V_22 * V_22 , struct V_1 * V_2 ,
const struct V_30 * V_31 )
{
return 0 ;
}
static T_2 F_25 ( struct V_1 * V_2 , unsigned int V_32 ,
unsigned int V_33 , T_3 V_34 )
{
return 0 ;
}
static T_2 F_26 ( struct V_1 * V_2 , unsigned int V_32 ,
unsigned int V_33 , unsigned int V_5 ,
T_3 V_34 )
{
return 0 ;
}
static int F_27 ( struct V_22 * V_22 , struct V_35 * * V_36 ,
struct V_37 * V_38 , bool T_4 V_39 )
{
return 0 ;
}
static int T_5 F_28 ( void )
{
int V_40 ;
F_29 ( & V_41 ) ;
F_30 ( & V_42 ) ;
V_40 = F_31 ( & V_43 ) ;
if ( V_40 < 0 ) {
F_32 ( & V_42 ) ;
F_33 ( & V_41 ) ;
}
return V_40 ;
}
static void T_6 F_34 ( void )
{
F_35 ( & V_43 ) ;
F_32 ( & V_42 ) ;
F_33 ( & V_41 ) ;
}
