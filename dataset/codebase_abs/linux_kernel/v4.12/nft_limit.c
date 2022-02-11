static inline bool F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 , V_5 ;
T_2 V_6 ;
F_2 ( & V_2 -> V_7 ) ;
V_4 = F_3 () ;
V_5 = V_2 -> V_5 + V_4 - V_2 -> V_8 ;
if ( V_5 > V_2 -> V_9 )
V_5 = V_2 -> V_9 ;
V_2 -> V_8 = V_4 ;
V_6 = V_5 - V_3 ;
if ( V_6 >= 0 ) {
V_2 -> V_5 = V_6 ;
F_4 ( & V_2 -> V_7 ) ;
return V_2 -> V_10 ;
}
V_2 -> V_5 = V_5 ;
F_4 ( & V_2 -> V_7 ) ;
return ! V_2 -> V_10 ;
}
static int F_5 ( struct V_1 * V_2 ,
const struct V_11 * const V_12 [] )
{
T_1 V_13 ;
if ( V_12 [ V_14 ] == NULL ||
V_12 [ V_15 ] == NULL )
return - V_16 ;
V_2 -> V_17 = F_6 ( F_7 ( V_12 [ V_14 ] ) ) ;
V_13 = F_6 ( F_7 ( V_12 [ V_15 ] ) ) ;
V_2 -> V_18 = V_13 * V_19 ;
if ( V_2 -> V_17 == 0 || V_2 -> V_18 < V_13 )
return - V_20 ;
V_2 -> V_5 = V_2 -> V_9 = V_2 -> V_18 ;
if ( V_12 [ V_21 ] ) {
T_1 V_17 ;
V_2 -> V_22 = F_8 ( F_9 ( V_12 [ V_21 ] ) ) ;
V_17 = V_2 -> V_17 + V_2 -> V_22 ;
if ( V_17 < V_2 -> V_17 )
return - V_20 ;
V_2 -> V_17 = V_17 ;
}
if ( V_12 [ V_23 ] ) {
T_3 V_24 = F_8 ( F_9 ( V_12 [ V_23 ] ) ) ;
if ( V_24 & V_25 )
V_2 -> V_10 = true ;
}
V_2 -> V_8 = F_3 () ;
F_10 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_11 ( struct V_26 * V_27 , const struct V_1 * V_2 ,
enum V_28 type )
{
T_3 V_24 = V_2 -> V_10 ? V_25 : 0 ;
T_1 V_29 = F_12 ( V_2 -> V_18 , V_19 ) ;
T_1 V_17 = V_2 -> V_17 - V_2 -> V_22 ;
if ( F_13 ( V_27 , V_14 , F_14 ( V_17 ) ,
V_30 ) ||
F_13 ( V_27 , V_15 , F_14 ( V_29 ) ,
V_30 ) ||
F_15 ( V_27 , V_21 , F_16 ( V_2 -> V_22 ) ) ||
F_15 ( V_27 , V_31 , F_16 ( type ) ) ||
F_15 ( V_27 , V_23 , F_16 ( V_24 ) ) )
goto V_32;
return 0 ;
V_32:
return - 1 ;
}
static void F_17 ( const struct V_33 * V_34 ,
struct V_35 * V_36 ,
const struct V_37 * V_38 )
{
struct V_39 * V_40 = F_18 ( V_34 ) ;
if ( F_1 ( & V_40 -> V_2 , V_40 -> V_3 ) )
V_36 -> V_41 . V_42 = V_43 ;
}
static int F_19 ( const struct V_44 * V_45 ,
const struct V_33 * V_34 ,
const struct V_11 * const V_12 [] )
{
struct V_39 * V_40 = F_18 ( V_34 ) ;
int V_46 ;
V_46 = F_5 ( & V_40 -> V_2 , V_12 ) ;
if ( V_46 < 0 )
return V_46 ;
V_40 -> V_3 = F_20 ( V_40 -> V_2 . V_18 , V_40 -> V_2 . V_17 ) ;
return 0 ;
}
static int F_21 ( struct V_26 * V_27 , const struct V_33 * V_34 )
{
const struct V_39 * V_40 = F_18 ( V_34 ) ;
return F_11 ( V_27 , & V_40 -> V_2 , V_47 ) ;
}
static void F_22 ( const struct V_33 * V_34 ,
struct V_35 * V_36 ,
const struct V_37 * V_38 )
{
struct V_1 * V_40 = F_18 ( V_34 ) ;
T_1 V_3 = F_20 ( V_40 -> V_18 * V_38 -> V_27 -> V_48 , V_40 -> V_17 ) ;
if ( F_1 ( V_40 , V_3 ) )
V_36 -> V_41 . V_42 = V_43 ;
}
static int F_23 ( const struct V_44 * V_45 ,
const struct V_33 * V_34 ,
const struct V_11 * const V_12 [] )
{
struct V_1 * V_40 = F_18 ( V_34 ) ;
return F_5 ( V_40 , V_12 ) ;
}
static int F_24 ( struct V_26 * V_27 ,
const struct V_33 * V_34 )
{
const struct V_1 * V_40 = F_18 ( V_34 ) ;
return F_11 ( V_27 , V_40 , V_49 ) ;
}
static const struct V_50 *
F_25 ( const struct V_44 * V_45 ,
const struct V_11 * const V_12 [] )
{
if ( V_12 [ V_31 ] == NULL )
return & V_51 ;
switch ( F_8 ( F_9 ( V_12 [ V_31 ] ) ) ) {
case V_47 :
return & V_51 ;
case V_49 :
return & V_52 ;
}
return F_26 ( - V_53 ) ;
}
static int T_4 F_27 ( void )
{
return F_28 ( & V_28 ) ;
}
static void T_5 F_29 ( void )
{
F_30 ( & V_28 ) ;
}
