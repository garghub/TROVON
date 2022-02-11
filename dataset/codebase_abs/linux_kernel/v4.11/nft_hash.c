static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
const void * V_9 = & V_4 -> V_9 [ V_8 -> V_10 ] ;
T_1 V_11 ;
V_11 = F_3 ( F_4 ( V_9 , V_8 -> V_12 , V_8 -> V_13 ) , V_8 -> V_14 ) ;
V_4 -> V_9 [ V_8 -> V_15 ] = V_11 + V_8 -> V_16 ;
}
static int F_5 ( const struct V_17 * V_18 ,
const struct V_1 * V_2 ,
const struct V_19 * const V_20 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_12 ;
int V_21 ;
if ( ! V_20 [ V_22 ] ||
! V_20 [ V_23 ] ||
! V_20 [ V_24 ] ||
! V_20 [ V_25 ] )
return - V_26 ;
if ( V_20 [ V_27 ] )
V_8 -> V_16 = F_6 ( F_7 ( V_20 [ V_27 ] ) ) ;
V_8 -> V_10 = F_8 ( V_20 [ V_22 ] ) ;
V_8 -> V_15 = F_8 ( V_20 [ V_23 ] ) ;
V_21 = F_9 ( V_20 [ V_24 ] , V_28 , & V_12 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_12 == 0 )
return - V_29 ;
V_8 -> V_12 = V_12 ;
V_8 -> V_14 = F_6 ( F_7 ( V_20 [ V_25 ] ) ) ;
if ( V_8 -> V_14 <= 1 )
return - V_29 ;
if ( V_8 -> V_16 + V_8 -> V_14 - 1 < V_8 -> V_16 )
return - V_30 ;
if ( V_20 [ V_31 ] ) {
V_8 -> V_13 = F_6 ( F_7 ( V_20 [ V_31 ] ) ) ;
} else {
V_8 -> V_32 = true ;
F_10 ( & V_8 -> V_13 , sizeof( V_8 -> V_13 ) ) ;
}
return F_11 ( V_8 -> V_10 , V_12 ) &&
F_12 ( V_18 , V_8 -> V_15 , NULL ,
V_33 , sizeof( T_1 ) ) ;
}
static int F_13 ( struct V_34 * V_35 ,
const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_14 ( V_35 , V_22 , V_8 -> V_10 ) )
goto V_36;
if ( F_14 ( V_35 , V_23 , V_8 -> V_15 ) )
goto V_36;
if ( F_15 ( V_35 , V_24 , F_16 ( V_8 -> V_12 ) ) )
goto V_36;
if ( F_15 ( V_35 , V_25 , F_16 ( V_8 -> V_14 ) ) )
goto V_36;
if ( ! V_8 -> V_32 &&
F_15 ( V_35 , V_31 , F_16 ( V_8 -> V_13 ) ) )
goto V_36;
if ( V_8 -> V_16 != 0 )
if ( F_15 ( V_35 , V_27 , F_16 ( V_8 -> V_16 ) ) )
goto V_36;
return 0 ;
V_36:
return - 1 ;
}
static int T_2 F_17 ( void )
{
return F_18 ( & V_37 ) ;
}
static void T_3 F_19 ( void )
{
F_20 ( & V_37 ) ;
}
