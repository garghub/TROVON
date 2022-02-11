static unsigned int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_5 * V_7 ,
int (* F_2)( struct V_3 * ) )
{
struct V_8 V_9 ;
if ( F_3 ( & V_9 , V_2 , V_4 , V_6 , V_7 ) < 0 )
return V_10 ;
return F_4 ( & V_9 , V_2 ) ;
}
static unsigned int F_5 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_5 * V_7 ,
int (* F_2)( struct V_3 * ) )
{
if ( F_6 ( V_4 -> V_11 < sizeof( struct V_12 ) ) ) {
if ( F_7 () )
F_8 ( L_1
L_2 ) ;
return V_13 ;
}
return F_1 ( V_2 , V_4 , V_6 , V_7 , F_2 ) ;
}
static int F_9 ( struct V_14 * V_14 )
{
V_14 -> V_15 . V_16 = F_10 ( sizeof( struct V_17 ) , V_18 ) ;
if ( V_14 -> V_15 . V_16 == NULL )
return - V_19 ;
memcpy ( V_14 -> V_15 . V_16 , & V_20 , sizeof( V_20 ) ) ;
if ( F_11 ( V_14 , V_14 -> V_15 . V_16 ) < 0 )
goto V_21;
return 0 ;
V_21:
F_12 ( V_14 -> V_15 . V_16 ) ;
return - V_19 ;
}
static void F_13 ( struct V_14 * V_14 )
{
F_14 ( V_14 -> V_15 . V_16 ) ;
F_12 ( V_14 -> V_15 . V_16 ) ;
}
static int T_1 F_15 ( void )
{
int V_22 ;
F_16 ( & V_23 ) ;
V_22 = F_17 ( & V_24 ) ;
if ( V_22 < 0 )
F_18 ( & V_23 ) ;
return V_22 ;
}
static void T_2 F_19 ( void )
{
F_20 ( & V_24 ) ;
F_18 ( & V_23 ) ;
}
