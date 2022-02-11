static unsigned int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_5 * V_7 ,
int (* F_2)( struct V_3 * ) )
{
struct V_8 V_9 ;
if ( F_3 ( V_4 -> V_10 < sizeof( struct V_11 ) ) ) {
if ( F_4 () )
F_5 ( L_1
L_2 ) ;
return V_12 ;
}
if ( F_6 ( & V_9 , V_2 , V_4 , V_6 , V_7 ) < 0 )
return V_13 ;
return F_7 ( & V_9 , V_2 ) ;
}
static int F_8 ( struct V_14 * V_14 )
{
V_14 -> V_15 . V_16 = F_9 ( sizeof( struct V_17 ) , V_18 ) ;
if ( V_14 -> V_15 . V_16 == NULL )
return - V_19 ;
memcpy ( V_14 -> V_15 . V_16 , & V_20 , sizeof( V_20 ) ) ;
if ( F_10 ( V_14 , V_14 -> V_15 . V_16 ) < 0 )
goto V_21;
return 0 ;
V_21:
F_11 ( V_14 -> V_15 . V_16 ) ;
return - V_19 ;
}
static void F_12 ( struct V_14 * V_14 )
{
F_13 ( V_14 -> V_15 . V_16 ) ;
F_11 ( V_14 -> V_15 . V_16 ) ;
}
static unsigned int
F_14 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_5 * V_7 ,
int (* F_2)( struct V_3 * ) )
{
struct V_8 V_9 ;
if ( F_6 ( & V_9 , V_2 , V_4 , V_6 , V_7 ) < 0 )
return V_13 ;
return F_7 ( & V_9 , V_2 ) ;
}
static int T_1 F_15 ( void )
{
F_16 ( & V_22 ) ;
return F_17 ( & V_23 ) ;
}
static void T_2 F_18 ( void )
{
F_19 ( & V_23 ) ;
F_20 ( & V_22 ) ;
}
