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
if ( F_5 ( V_3 -> V_8 < sizeof( struct V_9 ) ) ) {
if ( F_6 () )
F_7 ( L_1
L_2 ) ;
return V_10 ;
}
return F_1 ( V_1 , V_3 , V_5 ) ;
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
static int T_1 F_14 ( void )
{
int V_19 ;
V_19 = F_15 ( & V_20 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_16 ( & V_21 ) ;
if ( V_19 < 0 )
F_17 ( & V_20 ) ;
return V_19 ;
}
static void T_2 F_18 ( void )
{
F_19 ( & V_21 ) ;
F_17 ( & V_20 ) ;
}
