static unsigned int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 V_8 ;
if ( F_2 ( & V_8 , V_2 , V_4 , V_6 ) < 0 )
return V_9 ;
return F_3 ( & V_8 , V_2 ) ;
}
static unsigned int F_4 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
if ( F_5 ( V_4 -> V_10 < sizeof( struct V_11 ) ) ) {
if ( F_6 () )
F_7 ( L_1
L_2 ) ;
return V_12 ;
}
return F_1 ( V_2 , V_4 , V_6 ) ;
}
static int F_8 ( struct V_13 * V_13 )
{
V_13 -> V_14 . V_15 = F_9 ( sizeof( struct V_16 ) , V_17 ) ;
if ( V_13 -> V_14 . V_15 == NULL )
return - V_18 ;
memcpy ( V_13 -> V_14 . V_15 , & V_19 , sizeof( V_19 ) ) ;
if ( F_10 ( V_13 , V_13 -> V_14 . V_15 ) < 0 )
goto V_20;
return 0 ;
V_20:
F_11 ( V_13 -> V_14 . V_15 ) ;
return - V_18 ;
}
static void F_12 ( struct V_13 * V_13 )
{
F_13 ( V_13 -> V_14 . V_15 ) ;
F_11 ( V_13 -> V_14 . V_15 ) ;
}
static int T_1 F_14 ( void )
{
int V_21 ;
F_15 ( & V_22 ) ;
V_21 = F_16 ( & V_23 ) ;
if ( V_21 < 0 )
F_17 ( & V_22 ) ;
return V_21 ;
}
static void T_2 F_18 ( void )
{
F_19 ( & V_23 ) ;
F_17 ( & V_22 ) ;
}
