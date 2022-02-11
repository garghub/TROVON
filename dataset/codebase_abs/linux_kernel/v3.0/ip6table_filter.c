static unsigned int
F_1 ( unsigned int V_1 , struct V_2 * V_3 ,
const struct V_4 * V_5 , const struct V_4 * V_6 ,
int (* F_2)( struct V_2 * ) )
{
const struct V_7 * V_7 = F_3 ( ( V_5 != NULL ) ? V_5 : V_6 ) ;
return F_4 ( V_3 , V_1 , V_5 , V_6 , V_7 -> V_8 . V_9 ) ;
}
static int T_1 F_5 ( struct V_7 * V_7 )
{
struct V_10 * V_11 ;
V_11 = F_6 ( & V_12 ) ;
if ( V_11 == NULL )
return - V_13 ;
( (struct V_14 * ) V_11 -> V_15 ) [ 1 ] . V_16 . V_17 =
- V_18 - 1 ;
V_7 -> V_8 . V_9 =
F_7 ( V_7 , & V_12 , V_11 ) ;
F_8 ( V_11 ) ;
if ( F_9 ( V_7 -> V_8 . V_9 ) )
return F_10 ( V_7 -> V_8 . V_9 ) ;
return 0 ;
}
static void T_2 F_11 ( struct V_7 * V_7 )
{
F_12 ( V_7 , V_7 -> V_8 . V_9 ) ;
}
static int T_3 F_13 ( void )
{
int V_19 ;
if ( V_18 < 0 || V_18 > V_20 ) {
F_14 ( L_1 ) ;
return - V_21 ;
}
V_19 = F_15 ( & V_22 ) ;
if ( V_19 < 0 )
return V_19 ;
V_23 = F_16 ( & V_12 , F_1 ) ;
if ( F_9 ( V_23 ) ) {
V_19 = F_10 ( V_23 ) ;
goto V_24;
}
return V_19 ;
V_24:
F_17 ( & V_22 ) ;
return V_19 ;
}
static void T_4 F_18 ( void )
{
F_19 ( & V_12 , V_23 ) ;
F_17 ( & V_22 ) ;
}
