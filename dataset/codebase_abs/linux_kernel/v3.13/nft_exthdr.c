static void F_1 ( const struct V_1 * V_2 ,
struct V_3 V_4 [ V_5 + 1 ] ,
const struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_3 * V_10 = & V_4 [ V_9 -> V_11 ] ;
unsigned int V_12 = 0 ;
int V_13 ;
V_13 = F_3 ( V_7 -> V_14 , & V_12 , V_9 -> type , NULL , NULL ) ;
if ( V_13 < 0 )
goto V_13;
V_12 += V_9 -> V_12 ;
if ( F_4 ( V_7 -> V_14 , V_12 , V_10 -> V_4 , V_9 -> V_15 ) < 0 )
goto V_13;
return;
V_13:
V_4 [ V_16 ] . V_17 = V_18 ;
}
static int F_5 ( const struct V_19 * V_20 ,
const struct V_1 * V_2 ,
const struct V_21 * const V_22 [] )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
if ( V_22 [ V_23 ] == NULL ||
V_22 [ V_24 ] == NULL ||
V_22 [ V_25 ] == NULL ||
V_22 [ V_26 ] == NULL )
return - V_27 ;
V_9 -> type = F_6 ( V_22 [ V_24 ] ) ;
V_9 -> V_12 = F_7 ( F_8 ( V_22 [ V_25 ] ) ) ;
V_9 -> V_15 = F_7 ( F_8 ( V_22 [ V_26 ] ) ) ;
if ( V_9 -> V_15 == 0 ||
V_9 -> V_15 > F_9 ( struct V_3 , V_4 ) )
return - V_27 ;
V_9 -> V_11 = F_7 ( F_8 ( V_22 [ V_23 ] ) ) ;
V_13 = F_10 ( V_9 -> V_11 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_11 ( V_20 , V_9 -> V_11 , NULL , V_28 ) ;
}
static int F_12 ( struct V_29 * V_14 , const struct V_1 * V_2 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( F_13 ( V_14 , V_23 , F_14 ( V_9 -> V_11 ) ) )
goto V_30;
if ( F_15 ( V_14 , V_24 , V_9 -> type ) )
goto V_30;
if ( F_13 ( V_14 , V_25 , F_14 ( V_9 -> V_12 ) ) )
goto V_30;
if ( F_13 ( V_14 , V_26 , F_14 ( V_9 -> V_15 ) ) )
goto V_30;
return 0 ;
V_30:
return - 1 ;
}
static int T_1 F_16 ( void )
{
return F_17 ( & V_31 ) ;
}
static void T_2 F_18 ( void )
{
F_19 ( & V_31 ) ;
}
