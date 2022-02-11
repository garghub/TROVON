static inline bool F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 , V_5 ;
T_2 V_6 ;
F_2 ( & V_7 ) ;
V_4 = F_3 () ;
V_5 = V_2 -> V_5 + V_4 - V_2 -> V_8 ;
if ( V_5 > V_2 -> V_9 )
V_5 = V_2 -> V_9 ;
V_2 -> V_8 = V_4 ;
V_6 = V_5 - V_3 ;
if ( V_6 >= 0 ) {
V_2 -> V_5 = V_6 ;
F_4 ( & V_7 ) ;
return false ;
}
V_2 -> V_5 = V_5 ;
F_4 ( & V_7 ) ;
return true ;
}
static int F_5 ( struct V_1 * V_2 ,
const struct V_10 * const V_11 [] )
{
T_1 V_12 ;
if ( V_11 [ V_13 ] == NULL ||
V_11 [ V_14 ] == NULL )
return - V_15 ;
V_2 -> V_16 = F_6 ( F_7 ( V_11 [ V_13 ] ) ) ;
V_12 = F_6 ( F_7 ( V_11 [ V_14 ] ) ) ;
V_2 -> V_17 = V_12 * V_18 ;
if ( V_2 -> V_16 == 0 || V_2 -> V_17 < V_12 )
return - V_19 ;
V_2 -> V_5 = V_2 -> V_9 = V_2 -> V_17 ;
if ( V_11 [ V_20 ] ) {
T_1 V_16 ;
V_2 -> V_21 = F_8 ( F_9 ( V_11 [ V_20 ] ) ) ;
V_16 = V_2 -> V_16 + V_2 -> V_21 ;
if ( V_16 < V_2 -> V_16 )
return - V_19 ;
V_2 -> V_16 = V_16 ;
}
V_2 -> V_8 = F_3 () ;
return 0 ;
}
static int F_10 ( struct V_22 * V_23 , const struct V_1 * V_2 ,
enum V_24 type )
{
T_1 V_25 = F_11 ( V_2 -> V_17 , V_18 ) ;
T_1 V_16 = V_2 -> V_16 - V_2 -> V_21 ;
if ( F_12 ( V_23 , V_13 , F_13 ( V_16 ) ) ||
F_12 ( V_23 , V_14 , F_13 ( V_25 ) ) ||
F_14 ( V_23 , V_20 , F_15 ( V_2 -> V_21 ) ) ||
F_14 ( V_23 , V_26 , F_15 ( type ) ) )
goto V_27;
return 0 ;
V_27:
return - 1 ;
}
static void F_16 ( const struct V_28 * V_29 ,
struct V_30 * V_31 ,
const struct V_32 * V_33 )
{
struct V_34 * V_35 = F_17 ( V_29 ) ;
if ( F_1 ( & V_35 -> V_2 , V_35 -> V_3 ) )
V_31 -> V_36 . V_37 = V_38 ;
}
static int F_18 ( const struct V_39 * V_40 ,
const struct V_28 * V_29 ,
const struct V_10 * const V_11 [] )
{
struct V_34 * V_35 = F_17 ( V_29 ) ;
int V_41 ;
V_41 = F_5 ( & V_35 -> V_2 , V_11 ) ;
if ( V_41 < 0 )
return V_41 ;
V_35 -> V_3 = F_11 ( V_35 -> V_2 . V_17 , V_35 -> V_2 . V_16 ) ;
return 0 ;
}
static int F_19 ( struct V_22 * V_23 , const struct V_28 * V_29 )
{
const struct V_34 * V_35 = F_17 ( V_29 ) ;
return F_10 ( V_23 , & V_35 -> V_2 , V_42 ) ;
}
static void F_20 ( const struct V_28 * V_29 ,
struct V_30 * V_31 ,
const struct V_32 * V_33 )
{
struct V_1 * V_35 = F_17 ( V_29 ) ;
T_1 V_3 = F_11 ( V_35 -> V_17 * V_33 -> V_23 -> V_43 , V_35 -> V_16 ) ;
if ( F_1 ( V_35 , V_3 ) )
V_31 -> V_36 . V_37 = V_38 ;
}
static int F_21 ( const struct V_39 * V_40 ,
const struct V_28 * V_29 ,
const struct V_10 * const V_11 [] )
{
struct V_1 * V_35 = F_17 ( V_29 ) ;
return F_5 ( V_35 , V_11 ) ;
}
static int F_22 ( struct V_22 * V_23 ,
const struct V_28 * V_29 )
{
const struct V_1 * V_35 = F_17 ( V_29 ) ;
return F_10 ( V_23 , V_35 , V_44 ) ;
}
static const struct V_45 *
F_23 ( const struct V_39 * V_40 ,
const struct V_10 * const V_11 [] )
{
if ( V_11 [ V_26 ] == NULL )
return & V_46 ;
switch ( F_8 ( F_9 ( V_11 [ V_26 ] ) ) ) {
case V_42 :
return & V_46 ;
case V_44 :
return & V_47 ;
}
return F_24 ( - V_48 ) ;
}
static int T_3 F_25 ( void )
{
return F_26 ( & V_24 ) ;
}
static void T_4 F_27 ( void )
{
F_28 ( & V_24 ) ;
}
