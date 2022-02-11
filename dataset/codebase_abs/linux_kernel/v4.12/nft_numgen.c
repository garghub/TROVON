static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_9 , V_10 ;
do {
V_10 = F_3 ( & V_8 -> V_11 ) ;
V_9 = ( V_10 + 1 < V_8 -> V_12 ) ? V_10 + 1 : 0 ;
} while ( F_4 ( & V_8 -> V_11 , V_10 , V_9 ) != V_10 );
V_4 -> V_13 [ V_8 -> V_14 ] = V_9 + V_8 -> V_15 ;
}
static int F_5 ( const struct V_16 * V_17 ,
const struct V_1 * V_2 ,
const struct V_18 * const V_19 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_19 [ V_20 ] )
V_8 -> V_15 = F_6 ( F_7 ( V_19 [ V_20 ] ) ) ;
V_8 -> V_12 = F_6 ( F_7 ( V_19 [ V_21 ] ) ) ;
if ( V_8 -> V_12 == 0 )
return - V_22 ;
if ( V_8 -> V_15 + V_8 -> V_12 - 1 < V_8 -> V_15 )
return - V_23 ;
V_8 -> V_14 = F_8 ( V_19 [ V_24 ] ) ;
F_9 ( & V_8 -> V_11 , V_8 -> V_12 - 1 ) ;
return F_10 ( V_17 , V_8 -> V_14 , NULL ,
V_25 , sizeof( T_1 ) ) ;
}
static int F_11 ( struct V_26 * V_27 , enum V_28 V_14 ,
T_1 V_12 , enum V_29 type , T_1 V_15 )
{
if ( F_12 ( V_27 , V_24 , V_14 ) )
goto V_30;
if ( F_13 ( V_27 , V_21 , F_14 ( V_12 ) ) )
goto V_30;
if ( F_13 ( V_27 , V_31 , F_14 ( type ) ) )
goto V_30;
if ( F_13 ( V_27 , V_20 , F_14 ( V_15 ) ) )
goto V_30;
return 0 ;
V_30:
return - 1 ;
}
static int F_15 ( struct V_26 * V_27 , const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
return F_11 ( V_27 , V_8 -> V_14 , V_8 -> V_12 , V_32 ,
V_8 -> V_15 ) ;
}
static void F_16 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_33 * V_8 = F_2 ( V_2 ) ;
struct V_34 * V_35 = F_17 ( & V_36 ) ;
T_1 V_37 ;
V_37 = F_18 ( F_19 ( V_35 ) , V_8 -> V_12 ) ;
V_4 -> V_13 [ V_8 -> V_14 ] = V_37 + V_8 -> V_15 ;
}
static int F_20 ( const struct V_16 * V_17 ,
const struct V_1 * V_2 ,
const struct V_18 * const V_19 [] )
{
struct V_33 * V_8 = F_2 ( V_2 ) ;
if ( V_19 [ V_20 ] )
V_8 -> V_15 = F_6 ( F_7 ( V_19 [ V_20 ] ) ) ;
V_8 -> V_12 = F_6 ( F_7 ( V_19 [ V_21 ] ) ) ;
if ( V_8 -> V_12 == 0 )
return - V_22 ;
if ( V_8 -> V_15 + V_8 -> V_12 - 1 < V_8 -> V_15 )
return - V_23 ;
F_21 ( & V_36 ) ;
V_8 -> V_14 = F_8 ( V_19 [ V_24 ] ) ;
return F_10 ( V_17 , V_8 -> V_14 , NULL ,
V_25 , sizeof( T_1 ) ) ;
}
static int F_22 ( struct V_26 * V_27 , const struct V_1 * V_2 )
{
const struct V_33 * V_8 = F_2 ( V_2 ) ;
return F_11 ( V_27 , V_8 -> V_14 , V_8 -> V_12 , V_38 ,
V_8 -> V_15 ) ;
}
static const struct V_39 *
F_23 ( const struct V_16 * V_17 , const struct V_18 * const V_19 [] )
{
T_1 type ;
if ( ! V_19 [ V_24 ] ||
! V_19 [ V_21 ] ||
! V_19 [ V_31 ] )
return F_24 ( - V_40 ) ;
type = F_6 ( F_7 ( V_19 [ V_31 ] ) ) ;
switch ( type ) {
case V_32 :
return & V_41 ;
case V_38 :
return & V_42 ;
}
return F_24 ( - V_40 ) ;
}
static int T_2 F_25 ( void )
{
return F_26 ( & V_43 ) ;
}
static void T_3 F_27 ( void )
{
F_28 ( & V_43 ) ;
}
