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
static void F_8 ( const struct V_9 T_1 * V_11 ,
struct V_17 * V_18 )
{
const struct V_9 * V_19 ;
T_2 V_13 , V_16 ;
unsigned int V_20 ;
int V_21 ;
memset ( V_18 , 0 , sizeof( * V_18 ) ) ;
F_9 (cpu) {
V_19 = F_10 ( V_11 , V_21 ) ;
do {
V_20 = F_11 ( & V_19 -> V_12 ) ;
V_13 = V_19 -> V_11 . V_13 ;
V_16 = V_19 -> V_11 . V_16 ;
} while ( F_12 ( & V_19 -> V_12 , V_20 ) );
V_18 -> V_16 += V_16 ;
V_18 -> V_13 += V_13 ;
}
}
static int F_13 ( struct V_22 * V_14 , const struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_17 V_18 ;
F_8 ( V_8 -> V_11 , & V_18 ) ;
if ( F_14 ( V_14 , V_23 , F_15 ( V_18 . V_13 ) ) ||
F_14 ( V_14 , V_24 , F_15 ( V_18 . V_16 ) ) )
goto V_25;
return 0 ;
V_25:
return - 1 ;
}
static int F_16 ( const struct V_26 * V_27 ,
const struct V_1 * V_2 ,
const struct V_28 * const V_29 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 T_1 * V_19 ;
struct V_9 * V_10 ;
V_19 = F_17 ( struct V_9 ) ;
if ( V_19 == NULL )
return - V_30 ;
F_18 () ;
V_10 = F_4 ( V_19 ) ;
if ( V_29 [ V_24 ] ) {
V_10 -> V_11 . V_16 =
F_19 ( F_20 ( V_29 [ V_24 ] ) ) ;
}
if ( V_29 [ V_23 ] ) {
V_10 -> V_11 . V_13 =
F_19 ( F_20 ( V_29 [ V_23 ] ) ) ;
}
F_21 () ;
V_8 -> V_11 = V_19 ;
return 0 ;
}
static void F_22 ( const struct V_26 * V_27 ,
const struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_23 ( V_8 -> V_11 ) ;
}
static int F_24 ( struct V_1 * V_31 , const struct V_1 * V_32 )
{
struct V_7 * V_8 = F_2 ( V_32 ) ;
struct V_7 * V_33 = F_2 ( V_31 ) ;
struct V_9 T_1 * V_19 ;
struct V_9 * V_10 ;
struct V_17 V_18 ;
F_8 ( V_8 -> V_11 , & V_18 ) ;
V_19 = F_25 ( struct V_9 ,
V_34 ) ;
if ( V_19 == NULL )
return - V_30 ;
F_18 () ;
V_10 = F_4 ( V_19 ) ;
V_10 -> V_11 . V_16 = V_18 . V_16 ;
V_10 -> V_11 . V_13 = V_18 . V_13 ;
F_21 () ;
V_33 -> V_11 = V_19 ;
return 0 ;
}
static int T_3 F_26 ( void )
{
return F_27 ( & V_35 ) ;
}
static void T_4 F_28 ( void )
{
F_29 ( & V_35 ) ;
}
