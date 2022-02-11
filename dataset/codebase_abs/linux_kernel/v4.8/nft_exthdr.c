static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 * V_9 = & V_4 -> V_10 [ V_8 -> V_11 ] ;
unsigned int V_12 = 0 ;
int V_13 ;
V_13 = F_3 ( V_6 -> V_14 , & V_12 , V_8 -> type , NULL , NULL ) ;
if ( V_13 < 0 )
goto V_13;
V_12 += V_8 -> V_12 ;
V_9 [ V_8 -> V_15 / V_16 ] = 0 ;
if ( F_4 ( V_6 -> V_14 , V_12 , V_9 , V_8 -> V_15 ) < 0 )
goto V_13;
return;
V_13:
V_4 -> V_17 . V_18 = V_19 ;
}
static int F_5 ( const struct V_20 * V_21 ,
const struct V_1 * V_2 ,
const struct V_22 * const V_23 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_12 , V_15 ;
if ( V_23 [ V_24 ] == NULL ||
V_23 [ V_25 ] == NULL ||
V_23 [ V_26 ] == NULL ||
V_23 [ V_27 ] == NULL )
return - V_28 ;
V_12 = F_6 ( F_7 ( V_23 [ V_26 ] ) ) ;
V_15 = F_6 ( F_7 ( V_23 [ V_27 ] ) ) ;
if ( V_12 > V_29 || V_15 > V_29 )
return - V_30 ;
V_8 -> type = F_8 ( V_23 [ V_25 ] ) ;
V_8 -> V_12 = V_12 ;
V_8 -> V_15 = V_15 ;
V_8 -> V_11 = F_9 ( V_23 [ V_24 ] ) ;
return F_10 ( V_21 , V_8 -> V_11 , NULL ,
V_31 , V_8 -> V_15 ) ;
}
static int F_11 ( struct V_32 * V_14 , const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_12 ( V_14 , V_24 , V_8 -> V_11 ) )
goto V_33;
if ( F_13 ( V_14 , V_25 , V_8 -> type ) )
goto V_33;
if ( F_14 ( V_14 , V_26 , F_15 ( V_8 -> V_12 ) ) )
goto V_33;
if ( F_14 ( V_14 , V_27 , F_15 ( V_8 -> V_15 ) ) )
goto V_33;
return 0 ;
V_33:
return - 1 ;
}
static int T_2 F_16 ( void )
{
return F_17 ( & V_34 ) ;
}
static void T_3 F_18 ( void )
{
F_19 ( & V_34 ) ;
}
