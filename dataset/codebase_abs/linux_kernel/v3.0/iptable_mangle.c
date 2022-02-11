static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
unsigned int V_5 ;
const struct V_6 * V_7 ;
T_1 V_8 ;
T_2 V_9 , V_10 ;
T_3 V_11 ;
if ( V_2 -> V_12 < sizeof( struct V_6 ) ||
F_2 ( V_2 ) < sizeof( struct V_6 ) )
return V_13 ;
V_11 = V_2 -> V_11 ;
V_7 = F_3 ( V_2 ) ;
V_9 = V_7 -> V_9 ;
V_10 = V_7 -> V_10 ;
V_8 = V_7 -> V_8 ;
V_5 = F_4 ( V_2 , V_14 , NULL , V_4 ,
F_5 ( V_4 ) -> V_15 . V_16 ) ;
if ( V_5 != V_17 && V_5 != V_18 ) {
V_7 = F_3 ( V_2 ) ;
if ( V_7 -> V_9 != V_9 ||
V_7 -> V_10 != V_10 ||
V_2 -> V_11 != V_11 ||
V_7 -> V_8 != V_8 )
if ( F_6 ( V_2 , V_19 ) )
V_5 = V_17 ;
}
return V_5 ;
}
static unsigned int
F_7 ( unsigned int V_20 ,
struct V_1 * V_2 ,
const struct V_3 * V_21 ,
const struct V_3 * V_4 ,
int (* F_8)( struct V_1 * ) )
{
if ( V_20 == V_14 )
return F_1 ( V_2 , V_4 ) ;
if ( V_20 == V_22 )
return F_4 ( V_2 , V_20 , V_21 , V_4 ,
F_5 ( V_4 ) -> V_15 . V_16 ) ;
return F_4 ( V_2 , V_20 , V_21 , V_4 ,
F_5 ( V_21 ) -> V_15 . V_16 ) ;
}
static int T_4 F_9 ( struct V_23 * V_23 )
{
struct V_24 * V_25 ;
V_25 = F_10 ( & V_26 ) ;
if ( V_25 == NULL )
return - V_27 ;
V_23 -> V_15 . V_16 =
F_11 ( V_23 , & V_26 , V_25 ) ;
F_12 ( V_25 ) ;
if ( F_13 ( V_23 -> V_15 . V_16 ) )
return F_14 ( V_23 -> V_15 . V_16 ) ;
return 0 ;
}
static void T_5 F_15 ( struct V_23 * V_23 )
{
F_16 ( V_23 , V_23 -> V_15 . V_16 ) ;
}
static int T_6 F_17 ( void )
{
int V_5 ;
V_5 = F_18 ( & V_28 ) ;
if ( V_5 < 0 )
return V_5 ;
V_29 = F_19 ( & V_26 , F_7 ) ;
if ( F_13 ( V_29 ) ) {
V_5 = F_14 ( V_29 ) ;
goto V_30;
}
return V_5 ;
V_30:
F_20 ( & V_28 ) ;
return V_5 ;
}
static void T_7 F_21 ( void )
{
F_22 ( & V_26 , V_29 ) ;
F_20 ( & V_28 ) ;
}
