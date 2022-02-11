static unsigned int F_1 ( void * V_1 ,
struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_6 V_7 ;
F_2 ( & V_7 , V_3 , V_5 ) ;
return F_3 ( & V_7 , V_1 ) ;
}
static unsigned int F_4 ( void * V_1 ,
struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
if ( F_5 ( V_3 -> V_8 < sizeof( struct V_9 ) ||
F_6 ( V_3 ) -> V_10 < sizeof( struct V_9 ) / 4 ) ) {
if ( F_7 () )
F_8 ( L_1
L_2 ) ;
return V_11 ;
}
return F_1 ( V_1 , V_3 , V_5 ) ;
}
static int F_9 ( struct V_12 * V_12 )
{
V_12 -> V_13 . V_14 = F_10 ( sizeof( struct V_15 ) , V_16 ) ;
if ( V_12 -> V_13 . V_14 == NULL )
return - V_17 ;
memcpy ( V_12 -> V_13 . V_14 , & V_18 , sizeof( V_18 ) ) ;
if ( F_11 ( V_12 , V_12 -> V_13 . V_14 ) < 0 )
goto V_19;
return 0 ;
V_19:
F_12 ( V_12 -> V_13 . V_14 ) ;
return - V_17 ;
}
static void F_13 ( struct V_12 * V_12 )
{
F_14 ( V_12 -> V_13 . V_14 ) ;
F_12 ( V_12 -> V_13 . V_14 ) ;
}
static int T_1 F_15 ( void )
{
int V_20 ;
F_16 ( & V_21 ) ;
V_20 = F_17 ( & V_22 ) ;
if ( V_20 < 0 )
F_18 ( & V_21 ) ;
return V_20 ;
}
static void T_2 F_19 ( void )
{
F_20 ( & V_22 ) ;
F_18 ( & V_21 ) ;
}
