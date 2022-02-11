static unsigned int
F_1 ( void * V_1 , struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
if ( V_5 -> V_6 == V_7 &&
( V_3 -> V_8 < sizeof( struct V_9 ) ||
F_2 ( V_3 ) < sizeof( struct V_9 ) ) )
return V_10 ;
return F_3 ( V_3 , V_5 , V_5 -> V_11 -> V_12 . V_13 ) ;
}
static int T_1 F_4 ( struct V_11 * V_11 )
{
struct V_14 * V_15 ;
int V_16 ;
if ( V_11 -> V_12 . V_13 )
return 0 ;
V_15 = F_5 ( & V_17 ) ;
if ( V_15 == NULL )
return - V_18 ;
( (struct V_19 * ) V_15 -> V_20 ) [ 1 ] . V_21 . V_22 =
V_23 ? - V_10 - 1 : - V_24 - 1 ;
V_16 = F_6 ( V_11 , & V_17 , V_15 , V_25 ,
& V_11 -> V_12 . V_13 ) ;
F_7 ( V_15 ) ;
return V_16 ;
}
static int T_1 F_8 ( struct V_11 * V_11 )
{
if ( V_11 == & V_26 || ! V_23 )
return F_4 ( V_11 ) ;
return 0 ;
}
static void T_2 F_9 ( struct V_11 * V_11 )
{
if ( ! V_11 -> V_12 . V_13 )
return;
F_10 ( V_11 , V_11 -> V_12 . V_13 , V_25 ) ;
V_11 -> V_12 . V_13 = NULL ;
}
static int T_3 F_11 ( void )
{
int V_27 ;
V_25 = F_12 ( & V_17 , F_1 ) ;
if ( F_13 ( V_25 ) )
return F_14 ( V_25 ) ;
V_27 = F_15 ( & V_28 ) ;
if ( V_27 < 0 )
F_7 ( V_25 ) ;
return V_27 ;
}
static void T_4 F_16 ( void )
{
F_17 ( & V_28 ) ;
F_7 ( V_25 ) ;
}
