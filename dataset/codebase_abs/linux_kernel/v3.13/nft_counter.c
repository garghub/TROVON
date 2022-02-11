static void F_1 ( const struct V_1 * V_2 ,
struct V_3 V_4 [ V_5 + 1 ] ,
const struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_3 ( & V_9 -> V_10 ) ;
V_9 -> V_11 += V_7 -> V_12 -> V_13 ;
V_9 -> V_14 ++ ;
F_4 ( & V_9 -> V_10 ) ;
}
static int F_5 ( struct V_15 * V_12 , const struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned int V_16 ;
T_1 V_11 ;
T_1 V_14 ;
do {
V_16 = F_6 ( & V_9 -> V_10 ) ;
V_11 = V_9 -> V_11 ;
V_14 = V_9 -> V_14 ;
} while ( F_7 ( & V_9 -> V_10 , V_16 ) );
if ( F_8 ( V_12 , V_17 , F_9 ( V_11 ) ) )
goto V_18;
if ( F_8 ( V_12 , V_19 , F_9 ( V_14 ) ) )
goto V_18;
return 0 ;
V_18:
return - 1 ;
}
static int F_10 ( const struct V_20 * V_21 ,
const struct V_1 * V_2 ,
const struct V_22 * const V_23 [] )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_23 [ V_19 ] )
V_9 -> V_14 = F_11 ( F_12 ( V_23 [ V_19 ] ) ) ;
if ( V_23 [ V_17 ] )
V_9 -> V_11 = F_11 ( F_12 ( V_23 [ V_17 ] ) ) ;
F_13 ( & V_9 -> V_10 ) ;
return 0 ;
}
static int T_2 F_14 ( void )
{
return F_15 ( & V_24 ) ;
}
static void T_3 F_16 ( void )
{
F_17 ( & V_24 ) ;
}
