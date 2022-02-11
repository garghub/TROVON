static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_8 -> V_9 -> V_10 ( V_8 , V_4 , V_6 ) ;
}
static int F_3 ( const struct V_11 * V_12 ,
const struct V_1 * V_2 ,
const struct V_13 * const V_14 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_15 = F_4 ( V_12 -> V_16 ) ;
T_2 V_17 ;
if ( ! V_14 [ V_18 ] ||
! V_14 [ V_19 ] )
return - V_20 ;
V_17 = F_5 ( F_6 ( V_14 [ V_19 ] ) ) ;
V_8 = F_7 ( V_12 -> V_21 , V_14 [ V_18 ] , V_17 ,
V_15 ) ;
if ( F_8 ( V_8 ) )
return - V_22 ;
F_2 ( V_2 ) = V_8 ;
V_8 -> V_23 ++ ;
return 0 ;
}
static int F_9 ( struct V_24 * V_25 , const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_10 ( V_25 , V_18 , V_8 -> V_26 ) ||
F_11 ( V_25 , V_19 ,
F_12 ( V_8 -> V_9 -> type -> type ) ) )
goto V_27;
return 0 ;
V_27:
return - 1 ;
}
static void F_13 ( const struct V_11 * V_12 ,
const struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_8 -> V_23 -- ;
}
static void F_14 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_28 * V_29 = F_15 ( V_2 ) ;
const struct V_30 * V_31 = V_29 -> V_31 ;
const struct V_32 * V_33 ;
struct V_7 * V_8 ;
bool V_34 ;
V_34 = V_31 -> V_9 -> V_35 ( F_16 ( V_6 ) , V_31 , & V_4 -> V_36 [ V_29 -> V_37 ] ,
& V_33 ) ;
if ( ! V_34 ) {
V_4 -> V_38 . V_39 = V_40 ;
return;
}
V_8 = * F_17 ( V_33 ) ;
V_8 -> V_9 -> V_10 ( V_8 , V_4 , V_6 ) ;
}
static int F_18 ( const struct V_11 * V_12 ,
const struct V_1 * V_2 ,
const struct V_13 * const V_14 [] )
{
struct V_28 * V_29 = F_15 ( V_2 ) ;
T_1 V_15 = F_4 ( V_12 -> V_16 ) ;
struct V_30 * V_31 ;
int V_41 ;
V_31 = F_19 ( V_12 -> V_16 , V_12 -> V_21 , V_14 [ V_42 ] ,
V_14 [ V_43 ] , V_15 ) ;
if ( F_8 ( V_31 ) )
return F_20 ( V_31 ) ;
if ( ! ( V_31 -> V_44 & V_45 ) )
return - V_20 ;
V_29 -> V_37 = F_21 ( V_14 [ V_46 ] ) ;
V_41 = F_22 ( V_29 -> V_37 , V_31 -> V_47 ) ;
if ( V_41 < 0 )
return V_41 ;
V_29 -> V_48 . V_44 = V_31 -> V_44 & V_45 ;
V_41 = F_23 ( V_12 , V_31 , & V_29 -> V_48 ) ;
if ( V_41 < 0 )
return V_41 ;
V_29 -> V_31 = V_31 ;
return 0 ;
}
static int F_24 ( struct V_24 * V_25 , const struct V_1 * V_2 )
{
const struct V_28 * V_29 = F_15 ( V_2 ) ;
if ( F_25 ( V_25 , V_46 , V_29 -> V_37 ) ||
F_10 ( V_25 , V_42 , V_29 -> V_31 -> V_26 ) )
goto V_27;
return 0 ;
V_27:
return - 1 ;
}
static void F_26 ( const struct V_11 * V_12 ,
const struct V_1 * V_2 )
{
struct V_28 * V_29 = F_15 ( V_2 ) ;
F_27 ( V_12 , V_29 -> V_31 , & V_29 -> V_48 ) ;
}
static const struct V_49 *
F_28 ( const struct V_11 * V_12 ,
const struct V_13 * const V_14 [] )
{
if ( V_14 [ V_46 ] &&
( V_14 [ V_42 ] ||
V_14 [ V_43 ] ) )
return & V_50 ;
else if ( V_14 [ V_18 ] &&
V_14 [ V_19 ] )
return & V_51 ;
return F_29 ( - V_52 ) ;
}
static int T_3 F_30 ( void )
{
return F_31 ( & V_53 ) ;
}
static void T_4 F_32 ( void )
{
F_33 ( & V_53 ) ;
}
