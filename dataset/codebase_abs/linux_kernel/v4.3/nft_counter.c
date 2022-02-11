static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 ;
F_3 () ;
V_10 = F_4 ( V_8 -> V_11 ) ;
F_5 ( & V_10 -> V_12 ) ;
V_10 -> V_11 . V_13 += V_6 -> V_14 -> V_15 ;
V_10 -> V_11 . V_16 ++ ;
F_6 ( & V_10 -> V_12 ) ;
F_7 () ;
}
static int F_8 ( struct V_17 * V_14 , const struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_18 ;
struct V_19 V_20 ;
T_1 V_13 , V_16 ;
unsigned int V_21 ;
int V_22 ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
F_9 (cpu) {
V_18 = F_10 ( V_8 -> V_11 , V_22 ) ;
do {
V_21 = F_11 ( & V_18 -> V_12 ) ;
V_13 = V_18 -> V_11 . V_13 ;
V_16 = V_18 -> V_11 . V_16 ;
} while ( F_12 ( & V_18 -> V_12 , V_21 ) );
V_20 . V_16 += V_16 ;
V_20 . V_13 += V_13 ;
}
if ( F_13 ( V_14 , V_23 , F_14 ( V_20 . V_13 ) ) ||
F_13 ( V_14 , V_24 , F_14 ( V_20 . V_16 ) ) )
goto V_25;
return 0 ;
V_25:
return - 1 ;
}
static int F_15 ( const struct V_26 * V_27 ,
const struct V_1 * V_2 ,
const struct V_28 * const V_29 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 T_2 * V_18 ;
struct V_9 * V_10 ;
V_18 = F_16 ( struct V_9 ) ;
if ( V_18 == NULL )
return V_30 ;
F_17 () ;
V_10 = F_4 ( V_18 ) ;
if ( V_29 [ V_24 ] ) {
V_10 -> V_11 . V_16 =
F_18 ( F_19 ( V_29 [ V_24 ] ) ) ;
}
if ( V_29 [ V_23 ] ) {
V_10 -> V_11 . V_13 =
F_18 ( F_19 ( V_29 [ V_23 ] ) ) ;
}
F_20 () ;
V_8 -> V_11 = V_18 ;
return 0 ;
}
static void F_21 ( const struct V_26 * V_27 ,
const struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_22 ( V_8 -> V_11 ) ;
}
static int T_3 F_23 ( void )
{
return F_24 ( & V_31 ) ;
}
static void T_4 F_25 ( void )
{
F_26 ( & V_31 ) ;
}
