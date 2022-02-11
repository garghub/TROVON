static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
if ( ! F_2 ( V_2 , 0 ) )
return V_8 ;
F_3 ( F_4 ( V_2 ) -> V_9 , V_6 -> V_10 ) ;
if ( ! ( V_6 -> V_11 & V_12 ) &&
F_4 ( V_2 ) -> V_13 == F_5 ( V_14 ) ) {
const struct V_15 * V_16 ;
struct V_15 V_17 ;
V_16 = F_6 ( V_2 , 0 , sizeof( V_17 ) , & V_17 ) ;
if ( V_16 == NULL )
return V_8 ;
if ( V_16 -> V_18 != V_19 )
goto V_20;
if ( F_7 ( V_2 , sizeof( V_17 ) , V_6 -> V_10 , V_19 ) )
return V_8 ;
}
V_20:
return V_6 -> V_11 | ~ V_21 ;
}
static int F_8 ( const struct V_22 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
int V_23 ;
V_23 = V_6 -> V_11 | ~ V_21 ;
if ( V_24 && V_23 == V_25 )
return - V_26 ;
if ( F_9 ( V_23 ) )
return - V_26 ;
V_23 = V_6 -> V_11 | V_21 ;
if ( ( V_23 & ~ V_12 ) != ~ V_12 )
return - V_26 ;
return 0 ;
}
static int T_1 F_10 ( void )
{
return F_11 ( & V_27 ) ;
}
static void T_2 F_12 ( void )
{
F_13 ( & V_27 ) ;
}
