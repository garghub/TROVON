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
const struct V_15 * V_16 ,
struct V_1 * V_2 ,
const struct V_17 * V_18 ,
const struct V_17 * V_19 )
{
if ( F_1 ( V_2 ) )
F_8 ( V_14 , V_16 , V_2 , V_18 , V_19 ) ;
else
F_9 ( V_14 , V_16 , V_2 , V_18 , V_19 ) ;
}
static inline void F_10 ( struct V_13 * V_14 ,
const struct V_15 * V_16 ,
struct V_1 * V_2 ,
const struct V_17 * V_18 ,
const struct V_17 * V_19 )
{
#if F_11 ( V_20 )
if ( F_5 ( V_2 ) &&
F_12 ( V_14 , V_16 , V_2 , V_18 , V_19 ) == 0 )
return;
#endif
F_9 ( V_14 , V_16 , V_2 , V_18 , V_19 ) ;
}
static unsigned int
F_13 ( const struct V_15 * V_16 ,
struct V_1 * V_2 ,
const struct V_17 * V_18 ,
const struct V_17 * V_19 ,
int (* F_14)( struct V_1 * ) )
{
struct V_13 V_14 ;
switch ( F_15 ( V_2 ) -> V_21 ) {
case F_16 ( V_22 ) :
F_7 ( & V_14 , V_16 , V_2 , V_18 , V_19 ) ;
break;
case F_16 ( V_23 ) :
F_10 ( & V_14 , V_16 , V_2 , V_18 , V_19 ) ;
break;
default:
F_9 ( & V_14 , V_16 , V_2 , V_18 , V_19 ) ;
break;
}
return F_17 ( & V_14 , V_16 ) ;
}
static int F_18 ( struct V_24 * V_24 )
{
V_24 -> V_25 . V_26 = F_19 ( sizeof( struct V_27 ) , V_28 ) ;
if ( V_24 -> V_25 . V_26 == NULL )
return - V_29 ;
memcpy ( V_24 -> V_25 . V_26 , & V_30 , sizeof( V_30 ) ) ;
if ( F_20 ( V_24 , V_24 -> V_25 . V_26 ) < 0 )
goto V_31;
return 0 ;
V_31:
F_21 ( V_24 -> V_25 . V_26 ) ;
return - V_29 ;
}
static void F_22 ( struct V_24 * V_24 )
{
F_23 ( V_24 -> V_25 . V_26 ) ;
F_21 ( V_24 -> V_25 . V_26 ) ;
}
static int T_2 F_24 ( void )
{
int V_32 ;
F_25 ( & V_33 ) ;
V_32 = F_26 ( & V_34 ) ;
if ( V_32 < 0 )
F_27 ( & V_33 ) ;
return V_32 ;
}
static void T_3 F_28 ( void )
{
F_29 ( & V_34 ) ;
F_27 ( & V_33 ) ;
}
