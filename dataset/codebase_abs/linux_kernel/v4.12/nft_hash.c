static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
const void * V_9 = & V_4 -> V_9 [ V_8 -> V_10 ] ;
T_1 V_11 ;
V_11 = F_3 ( F_4 ( V_9 , V_8 -> V_12 , V_8 -> V_13 ) , V_8 -> V_14 ) ;
V_4 -> V_9 [ V_8 -> V_15 ] = V_11 + V_8 -> V_16 ;
}
static void F_5 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_17 * V_8 = F_2 ( V_2 ) ;
struct V_18 * V_19 = V_6 -> V_19 ;
T_1 V_11 ;
V_11 = F_3 ( F_6 ( V_19 ) , V_8 -> V_14 ) ;
V_4 -> V_9 [ V_8 -> V_15 ] = V_11 + V_8 -> V_16 ;
}
static int F_7 ( const struct V_20 * V_21 ,
const struct V_1 * V_2 ,
const struct V_22 * const V_23 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_12 ;
int V_24 ;
if ( ! V_23 [ V_25 ] ||
! V_23 [ V_26 ] ||
! V_23 [ V_27 ] ||
! V_23 [ V_28 ] )
return - V_29 ;
if ( V_23 [ V_30 ] )
V_8 -> V_16 = F_8 ( F_9 ( V_23 [ V_30 ] ) ) ;
V_8 -> V_10 = F_10 ( V_23 [ V_25 ] ) ;
V_8 -> V_15 = F_10 ( V_23 [ V_26 ] ) ;
V_24 = F_11 ( V_23 [ V_27 ] , V_31 , & V_12 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_12 == 0 )
return - V_32 ;
V_8 -> V_12 = V_12 ;
V_8 -> V_14 = F_8 ( F_9 ( V_23 [ V_28 ] ) ) ;
if ( V_8 -> V_14 <= 1 )
return - V_32 ;
if ( V_8 -> V_16 + V_8 -> V_14 - 1 < V_8 -> V_16 )
return - V_33 ;
if ( V_23 [ V_34 ] ) {
V_8 -> V_13 = F_8 ( F_9 ( V_23 [ V_34 ] ) ) ;
} else {
V_8 -> V_35 = true ;
F_12 ( & V_8 -> V_13 , sizeof( V_8 -> V_13 ) ) ;
}
return F_13 ( V_8 -> V_10 , V_12 ) &&
F_14 ( V_21 , V_8 -> V_15 , NULL ,
V_36 , sizeof( T_1 ) ) ;
}
static int F_15 ( const struct V_20 * V_21 ,
const struct V_1 * V_2 ,
const struct V_22 * const V_23 [] )
{
struct V_17 * V_8 = F_2 ( V_2 ) ;
if ( ! V_23 [ V_26 ] ||
! V_23 [ V_28 ] )
return - V_29 ;
if ( V_23 [ V_30 ] )
V_8 -> V_16 = F_8 ( F_9 ( V_23 [ V_30 ] ) ) ;
V_8 -> V_15 = F_10 ( V_23 [ V_26 ] ) ;
V_8 -> V_14 = F_8 ( F_9 ( V_23 [ V_28 ] ) ) ;
if ( V_8 -> V_14 <= 1 )
return - V_32 ;
if ( V_8 -> V_16 + V_8 -> V_14 - 1 < V_8 -> V_16 )
return - V_33 ;
return F_14 ( V_21 , V_8 -> V_15 , NULL ,
V_36 , sizeof( T_1 ) ) ;
}
static int F_16 ( struct V_18 * V_19 ,
const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_17 ( V_19 , V_25 , V_8 -> V_10 ) )
goto V_37;
if ( F_17 ( V_19 , V_26 , V_8 -> V_15 ) )
goto V_37;
if ( F_18 ( V_19 , V_27 , F_19 ( V_8 -> V_12 ) ) )
goto V_37;
if ( F_18 ( V_19 , V_28 , F_19 ( V_8 -> V_14 ) ) )
goto V_37;
if ( ! V_8 -> V_35 &&
F_18 ( V_19 , V_34 , F_19 ( V_8 -> V_13 ) ) )
goto V_37;
if ( V_8 -> V_16 != 0 )
if ( F_18 ( V_19 , V_30 , F_19 ( V_8 -> V_16 ) ) )
goto V_37;
if ( F_18 ( V_19 , V_38 , F_19 ( V_39 ) ) )
goto V_37;
return 0 ;
V_37:
return - 1 ;
}
static int F_20 ( struct V_18 * V_19 ,
const struct V_1 * V_2 )
{
const struct V_17 * V_8 = F_2 ( V_2 ) ;
if ( F_17 ( V_19 , V_26 , V_8 -> V_15 ) )
goto V_37;
if ( F_18 ( V_19 , V_28 , F_19 ( V_8 -> V_14 ) ) )
goto V_37;
if ( V_8 -> V_16 != 0 )
if ( F_18 ( V_19 , V_30 , F_19 ( V_8 -> V_16 ) ) )
goto V_37;
if ( F_18 ( V_19 , V_38 , F_19 ( V_40 ) ) )
goto V_37;
return 0 ;
V_37:
return - 1 ;
}
static const struct V_41 *
F_21 ( const struct V_20 * V_21 ,
const struct V_22 * const V_23 [] )
{
T_1 type ;
if ( ! V_23 [ V_38 ] )
return & V_42 ;
type = F_8 ( F_9 ( V_23 [ V_38 ] ) ) ;
switch ( type ) {
case V_40 :
return & V_43 ;
case V_39 :
return & V_42 ;
default:
break;
}
return F_22 ( - V_44 ) ;
}
static int T_2 F_23 ( void )
{
return F_24 ( & V_45 ) ;
}
static void T_3 F_25 ( void )
{
F_26 ( & V_45 ) ;
}
