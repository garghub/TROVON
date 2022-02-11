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
return V_2 -> V_10 ;
}
V_2 -> V_5 = V_5 ;
F_4 ( & V_7 ) ;
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
return 0 ;
}
static int F_10 ( struct V_26 * V_27 , const struct V_1 * V_2 ,
enum V_28 type )
{
T_3 V_24 = V_2 -> V_10 ? V_25 : 0 ;
T_1 V_29 = F_11 ( V_2 -> V_18 , V_19 ) ;
T_1 V_17 = V_2 -> V_17 - V_2 -> V_22 ;
if ( F_12 ( V_27 , V_14 , F_13 ( V_17 ) ) ||
F_12 ( V_27 , V_15 , F_13 ( V_29 ) ) ||
F_14 ( V_27 , V_21 , F_15 ( V_2 -> V_22 ) ) ||
F_14 ( V_27 , V_30 , F_15 ( type ) ) ||
F_14 ( V_27 , V_23 , F_15 ( V_24 ) ) )
goto V_31;
return 0 ;
V_31:
return - 1 ;
}
static void F_16 ( const struct V_32 * V_33 ,
struct V_34 * V_35 ,
const struct V_36 * V_37 )
{
struct V_38 * V_39 = F_17 ( V_33 ) ;
if ( F_1 ( & V_39 -> V_2 , V_39 -> V_3 ) )
V_35 -> V_40 . V_41 = V_42 ;
}
static int F_18 ( const struct V_43 * V_44 ,
const struct V_32 * V_33 ,
const struct V_11 * const V_12 [] )
{
struct V_38 * V_39 = F_17 ( V_33 ) ;
int V_45 ;
V_45 = F_5 ( & V_39 -> V_2 , V_12 ) ;
if ( V_45 < 0 )
return V_45 ;
V_39 -> V_3 = F_11 ( V_39 -> V_2 . V_18 , V_39 -> V_2 . V_17 ) ;
return 0 ;
}
static int F_19 ( struct V_26 * V_27 , const struct V_32 * V_33 )
{
const struct V_38 * V_39 = F_17 ( V_33 ) ;
return F_10 ( V_27 , & V_39 -> V_2 , V_46 ) ;
}
static void F_20 ( const struct V_32 * V_33 ,
struct V_34 * V_35 ,
const struct V_36 * V_37 )
{
struct V_1 * V_39 = F_17 ( V_33 ) ;
T_1 V_3 = F_11 ( V_39 -> V_18 * V_37 -> V_27 -> V_47 , V_39 -> V_17 ) ;
if ( F_1 ( V_39 , V_3 ) )
V_35 -> V_40 . V_41 = V_42 ;
}
static int F_21 ( const struct V_43 * V_44 ,
const struct V_32 * V_33 ,
const struct V_11 * const V_12 [] )
{
struct V_1 * V_39 = F_17 ( V_33 ) ;
return F_5 ( V_39 , V_12 ) ;
}
static int F_22 ( struct V_26 * V_27 ,
const struct V_32 * V_33 )
{
const struct V_1 * V_39 = F_17 ( V_33 ) ;
return F_10 ( V_27 , V_39 , V_48 ) ;
}
static const struct V_49 *
F_23 ( const struct V_43 * V_44 ,
const struct V_11 * const V_12 [] )
{
if ( V_12 [ V_30 ] == NULL )
return & V_50 ;
switch ( F_8 ( F_9 ( V_12 [ V_30 ] ) ) ) {
case V_46 :
return & V_50 ;
case V_48 :
return & V_51 ;
}
return F_24 ( - V_52 ) ;
}
static int T_4 F_25 ( void )
{
return F_26 ( & V_28 ) ;
}
static void T_5 F_27 ( void )
{
F_28 ( & V_28 ) ;
}
