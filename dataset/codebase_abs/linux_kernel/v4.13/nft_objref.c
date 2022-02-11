static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_8 -> type -> V_9 ( V_8 , V_4 , V_6 ) ;
}
static int F_3 ( const struct V_10 * V_11 ,
const struct V_1 * V_2 ,
const struct V_12 * const V_13 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_14 = F_4 ( V_11 -> V_15 ) ;
T_2 V_16 ;
if ( ! V_13 [ V_17 ] ||
! V_13 [ V_18 ] )
return - V_19 ;
V_16 = F_5 ( F_6 ( V_13 [ V_18 ] ) ) ;
V_8 = F_7 ( V_11 -> V_20 , V_13 [ V_17 ] , V_16 ,
V_14 ) ;
if ( F_8 ( V_8 ) )
return - V_21 ;
F_2 ( V_2 ) = V_8 ;
V_8 -> V_22 ++ ;
return 0 ;
}
static int F_9 ( struct V_23 * V_24 , const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_10 ( V_24 , V_17 , V_8 -> V_25 ) ||
F_11 ( V_24 , V_18 , F_12 ( V_8 -> type -> type ) ) )
goto V_26;
return 0 ;
V_26:
return - 1 ;
}
static void F_13 ( const struct V_10 * V_11 ,
const struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_8 -> V_22 -- ;
}
static void F_14 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_27 * V_28 = F_15 ( V_2 ) ;
const struct V_29 * V_30 = V_28 -> V_30 ;
const struct V_31 * V_32 ;
struct V_7 * V_8 ;
bool V_33 ;
V_33 = V_30 -> V_34 -> V_35 ( F_16 ( V_6 ) , V_30 , & V_4 -> V_36 [ V_28 -> V_37 ] ,
& V_32 ) ;
if ( ! V_33 ) {
V_4 -> V_38 . V_39 = V_40 ;
return;
}
V_8 = * F_17 ( V_32 ) ;
V_8 -> type -> V_9 ( V_8 , V_4 , V_6 ) ;
}
static int F_18 ( const struct V_10 * V_11 ,
const struct V_1 * V_2 ,
const struct V_12 * const V_13 [] )
{
struct V_27 * V_28 = F_15 ( V_2 ) ;
T_1 V_14 = F_4 ( V_11 -> V_15 ) ;
struct V_29 * V_30 ;
int V_41 ;
V_30 = F_19 ( V_11 -> V_15 , V_11 -> V_20 , V_13 [ V_42 ] ,
V_13 [ V_43 ] , V_14 ) ;
if ( F_8 ( V_30 ) )
return F_20 ( V_30 ) ;
if ( ! ( V_30 -> V_44 & V_45 ) )
return - V_19 ;
V_28 -> V_37 = F_21 ( V_13 [ V_46 ] ) ;
V_41 = F_22 ( V_28 -> V_37 , V_30 -> V_47 ) ;
if ( V_41 < 0 )
return V_41 ;
V_28 -> V_48 . V_44 = V_30 -> V_44 & V_45 ;
V_41 = F_23 ( V_11 , V_30 , & V_28 -> V_48 ) ;
if ( V_41 < 0 )
return V_41 ;
V_28 -> V_30 = V_30 ;
return 0 ;
}
static int F_24 ( struct V_23 * V_24 , const struct V_1 * V_2 )
{
const struct V_27 * V_28 = F_15 ( V_2 ) ;
if ( F_25 ( V_24 , V_46 , V_28 -> V_37 ) ||
F_10 ( V_24 , V_42 , V_28 -> V_30 -> V_25 ) )
goto V_26;
return 0 ;
V_26:
return - 1 ;
}
static void F_26 ( const struct V_10 * V_11 ,
const struct V_1 * V_2 )
{
struct V_27 * V_28 = F_15 ( V_2 ) ;
F_27 ( V_11 , V_28 -> V_30 , & V_28 -> V_48 ) ;
}
static const struct V_49 *
F_28 ( const struct V_10 * V_11 ,
const struct V_12 * const V_13 [] )
{
if ( V_13 [ V_46 ] &&
( V_13 [ V_42 ] ||
V_13 [ V_43 ] ) )
return & V_50 ;
else if ( V_13 [ V_17 ] &&
V_13 [ V_18 ] )
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
