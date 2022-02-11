static inline bool F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
return F_2 ( V_4 -> V_5 , & V_2 -> V_6 ) >= V_2 -> V_7 ;
}
static inline bool F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_8 & V_9 ;
}
static inline void F_4 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
const struct V_12 * V_13 )
{
if ( F_1 ( V_2 , V_13 -> V_4 ) ^ F_3 ( V_2 ) )
V_11 -> V_14 . V_15 = V_16 ;
}
static void F_5 ( struct V_17 * V_18 ,
struct V_10 * V_11 ,
const struct V_12 * V_13 )
{
struct V_1 * V_2 = F_6 ( V_18 ) ;
bool V_19 ;
V_19 = F_1 ( V_2 , V_13 -> V_4 ) ;
if ( V_19 ^ F_3 ( V_2 ) )
V_11 -> V_14 . V_15 = V_16 ;
if ( V_19 &&
! F_7 ( V_20 , & V_2 -> V_8 ) )
F_8 ( F_9 ( V_13 ) , V_18 -> V_21 , V_18 , 0 , 0 ,
V_22 , F_10 ( V_13 ) , 0 , V_23 ) ;
}
static int F_11 ( const struct V_24 * const V_25 [] ,
struct V_1 * V_2 )
{
unsigned long V_8 = 0 ;
T_1 V_7 , V_6 = 0 ;
if ( ! V_25 [ V_26 ] )
return - V_27 ;
V_7 = F_12 ( F_13 ( V_25 [ V_26 ] ) ) ;
if ( V_7 > V_28 )
return - V_29 ;
if ( V_25 [ V_30 ] ) {
V_6 = F_12 ( F_13 ( V_25 [ V_30 ] ) ) ;
if ( V_6 > V_7 )
return - V_27 ;
}
if ( V_25 [ V_31 ] ) {
V_8 = F_14 ( F_15 ( V_25 [ V_31 ] ) ) ;
if ( V_8 & ~ V_9 )
return - V_27 ;
if ( V_8 & V_32 )
return - V_33 ;
}
V_2 -> V_7 = V_7 ;
V_2 -> V_8 = V_8 ;
F_16 ( & V_2 -> V_6 , V_6 ) ;
return 0 ;
}
static int F_17 ( const struct V_24 * const V_25 [] ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_6 ( V_18 ) ;
return F_11 ( V_25 , V_2 ) ;
}
static int F_18 ( struct V_3 * V_4 , struct V_1 * V_2 ,
bool V_34 )
{
T_1 V_6 , V_35 ;
T_2 V_8 = V_2 -> V_8 ;
V_6 = F_19 ( & V_2 -> V_6 ) ;
if ( V_6 >= V_2 -> V_7 ) {
V_35 = V_2 -> V_7 ;
V_8 |= V_32 ;
} else {
V_35 = V_6 ;
}
if ( F_20 ( V_4 , V_26 , F_21 ( V_2 -> V_7 ) ,
V_36 ) ||
F_20 ( V_4 , V_30 , F_21 ( V_35 ) ,
V_36 ) ||
F_22 ( V_4 , V_31 , F_23 ( V_8 ) ) )
goto V_37;
if ( V_34 ) {
F_24 ( V_6 , & V_2 -> V_6 ) ;
F_25 ( V_20 , & V_2 -> V_8 ) ;
}
return 0 ;
V_37:
return - 1 ;
}
static int F_26 ( struct V_3 * V_4 , struct V_17 * V_18 ,
bool V_34 )
{
struct V_1 * V_2 = F_6 ( V_18 ) ;
return F_18 ( V_4 , V_2 , V_34 ) ;
}
static void F_27 ( const struct V_38 * V_39 ,
struct V_10 * V_11 ,
const struct V_12 * V_13 )
{
struct V_1 * V_2 = F_28 ( V_39 ) ;
F_4 ( V_2 , V_11 , V_13 ) ;
}
static int F_29 ( const struct V_40 * V_41 ,
const struct V_38 * V_39 ,
const struct V_24 * const V_25 [] )
{
struct V_1 * V_2 = F_28 ( V_39 ) ;
return F_11 ( V_25 , V_2 ) ;
}
static int F_30 ( struct V_3 * V_4 , const struct V_38 * V_39 )
{
struct V_1 * V_2 = F_28 ( V_39 ) ;
return F_18 ( V_4 , V_2 , false ) ;
}
static int T_3 F_31 ( void )
{
int V_42 ;
V_42 = F_32 ( & V_43 ) ;
if ( V_42 < 0 )
return V_42 ;
V_42 = F_33 ( & V_44 ) ;
if ( V_42 < 0 )
goto V_45;
return 0 ;
V_45:
F_34 ( & V_43 ) ;
return V_42 ;
}
static void T_4 F_35 ( void )
{
F_36 ( & V_44 ) ;
F_34 ( & V_43 ) ;
}
