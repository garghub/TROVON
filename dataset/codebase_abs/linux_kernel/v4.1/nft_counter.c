static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_3 ( & V_8 -> V_9 ) ;
V_8 -> V_10 += V_6 -> V_11 -> V_12 ;
V_8 -> V_13 ++ ;
F_4 ( & V_8 -> V_9 ) ;
}
static int F_5 ( struct V_14 * V_11 , const struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned int V_15 ;
T_1 V_10 ;
T_1 V_13 ;
do {
V_15 = F_6 ( & V_8 -> V_9 ) ;
V_10 = V_8 -> V_10 ;
V_13 = V_8 -> V_13 ;
} while ( F_7 ( & V_8 -> V_9 , V_15 ) );
if ( F_8 ( V_11 , V_16 , F_9 ( V_10 ) ) )
goto V_17;
if ( F_8 ( V_11 , V_18 , F_9 ( V_13 ) ) )
goto V_17;
return 0 ;
V_17:
return - 1 ;
}
static int F_10 ( const struct V_19 * V_20 ,
const struct V_1 * V_2 ,
const struct V_21 * const V_22 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_22 [ V_18 ] )
V_8 -> V_13 = F_11 ( F_12 ( V_22 [ V_18 ] ) ) ;
if ( V_22 [ V_16 ] )
V_8 -> V_10 = F_11 ( F_12 ( V_22 [ V_16 ] ) ) ;
F_13 ( & V_8 -> V_9 ) ;
return 0 ;
}
static int T_2 F_14 ( void )
{
return F_15 ( & V_23 ) ;
}
static void T_3 F_16 ( void )
{
F_17 ( & V_23 ) ;
}
