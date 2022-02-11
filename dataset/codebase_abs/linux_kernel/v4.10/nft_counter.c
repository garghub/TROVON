static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 ;
T_1 * V_9 ;
F_2 () ;
V_8 = F_3 ( V_2 -> V_10 ) ;
V_9 = F_3 ( & V_11 ) ;
F_4 ( V_9 ) ;
V_8 -> V_12 += V_6 -> V_13 -> V_14 ;
V_8 -> V_15 ++ ;
F_5 ( V_9 ) ;
F_6 () ;
}
static inline void F_7 ( struct V_16 * V_17 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
F_1 ( V_2 , V_4 , V_6 ) ;
}
static int F_9 ( const struct V_18 * const V_19 [] ,
struct V_1 * V_2 )
{
struct V_7 T_2 * V_20 ;
struct V_7 * V_8 ;
V_20 = F_10 ( struct V_7 ) ;
if ( V_20 == NULL )
return - V_21 ;
F_11 () ;
V_8 = F_3 ( V_20 ) ;
if ( V_19 [ V_22 ] ) {
V_8 -> V_15 =
F_12 ( F_13 ( V_19 [ V_22 ] ) ) ;
}
if ( V_19 [ V_23 ] ) {
V_8 -> V_12 =
F_12 ( F_13 ( V_19 [ V_23 ] ) ) ;
}
F_14 () ;
V_2 -> V_10 = V_20 ;
return 0 ;
}
static int F_15 ( const struct V_18 * const V_19 [] ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
return F_9 ( V_19 , V_2 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_17 ( V_2 -> V_10 ) ;
}
static void F_18 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
F_16 ( V_2 ) ;
}
static void F_19 ( struct V_1 T_2 * V_2 ,
struct V_7 * V_24 )
{
struct V_7 * V_8 ;
F_2 () ;
V_8 = F_3 ( V_2 -> V_10 ) ;
V_8 -> V_15 -= V_24 -> V_15 ;
V_8 -> V_12 -= V_24 -> V_12 ;
F_6 () ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_7 * V_24 )
{
struct V_7 * V_8 ;
const T_1 * V_9 ;
T_3 V_12 , V_15 ;
unsigned int V_25 ;
int V_26 ;
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
F_21 (cpu) {
V_9 = F_22 ( & V_11 , V_26 ) ;
V_8 = F_22 ( V_2 -> V_10 , V_26 ) ;
do {
V_25 = F_23 ( V_9 ) ;
V_12 = V_8 -> V_12 ;
V_15 = V_8 -> V_15 ;
} while ( F_24 ( V_9 , V_25 ) );
V_24 -> V_12 += V_12 ;
V_24 -> V_15 += V_15 ;
}
}
static int F_25 ( struct V_27 * V_13 ,
struct V_1 * V_2 ,
bool V_28 )
{
struct V_7 V_24 ;
F_20 ( V_2 , & V_24 ) ;
if ( F_26 ( V_13 , V_23 , F_27 ( V_24 . V_12 ) ,
V_29 ) ||
F_26 ( V_13 , V_22 , F_27 ( V_24 . V_15 ) ,
V_29 ) )
goto V_30;
if ( V_28 )
F_19 ( V_2 , & V_24 ) ;
return 0 ;
V_30:
return - 1 ;
}
static int F_28 ( struct V_27 * V_13 ,
struct V_16 * V_17 , bool V_28 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
return F_25 ( V_13 , V_2 , V_28 ) ;
}
static void F_29 ( const struct V_31 * V_32 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_1 * V_2 = F_30 ( V_32 ) ;
F_1 ( V_2 , V_4 , V_6 ) ;
}
static int F_31 ( struct V_27 * V_13 , const struct V_31 * V_32 )
{
struct V_1 * V_2 = F_30 ( V_32 ) ;
return F_25 ( V_13 , V_2 , false ) ;
}
static int F_32 ( const struct V_33 * V_34 ,
const struct V_31 * V_32 ,
const struct V_18 * const V_19 [] )
{
struct V_1 * V_2 = F_30 ( V_32 ) ;
return F_9 ( V_19 , V_2 ) ;
}
static void F_33 ( const struct V_33 * V_34 ,
const struct V_31 * V_32 )
{
struct V_1 * V_2 = F_30 ( V_32 ) ;
F_16 ( V_2 ) ;
}
static int F_34 ( struct V_31 * V_35 , const struct V_31 * V_36 )
{
struct V_1 * V_2 = F_30 ( V_36 ) ;
struct V_1 * V_37 = F_30 ( V_35 ) ;
struct V_7 T_2 * V_20 ;
struct V_7 * V_8 ;
struct V_7 V_24 ;
F_20 ( V_2 , & V_24 ) ;
V_20 = F_35 ( struct V_7 , V_38 ) ;
if ( V_20 == NULL )
return - V_21 ;
F_11 () ;
V_8 = F_3 ( V_20 ) ;
V_8 -> V_15 = V_24 . V_15 ;
V_8 -> V_12 = V_24 . V_12 ;
F_14 () ;
V_37 -> V_10 = V_20 ;
return 0 ;
}
static int T_4 F_36 ( void )
{
int V_26 , V_39 ;
F_21 (cpu)
F_37 ( F_22 ( & V_11 , V_26 ) ) ;
V_39 = F_38 ( & V_40 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_39 ( & V_41 ) ;
if ( V_39 < 0 )
goto V_42;
return 0 ;
V_42:
F_40 ( & V_40 ) ;
return V_39 ;
}
static void T_5 F_41 ( void )
{
F_42 ( & V_41 ) ;
F_40 ( & V_40 ) ;
}
