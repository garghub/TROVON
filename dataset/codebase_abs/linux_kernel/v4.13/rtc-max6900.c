static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
T_1 V_4 [ 1 ] = { V_5 } ;
T_1 V_6 [ 1 ] = { V_7 } ;
struct V_8 V_9 [ 4 ] = {
{
. V_10 = V_2 -> V_10 ,
. V_11 = 0 ,
. V_12 = sizeof( V_4 ) ,
. V_3 = V_4 }
,
{
. V_10 = V_2 -> V_10 ,
. V_11 = V_13 ,
. V_12 = V_14 ,
. V_3 = V_3 }
,
{
. V_10 = V_2 -> V_10 ,
. V_11 = 0 ,
. V_12 = sizeof( V_6 ) ,
. V_3 = V_6 }
,
{
. V_10 = V_2 -> V_10 ,
. V_11 = V_13 ,
. V_12 = sizeof( V_3 [ V_15 ] ) ,
. V_3 = & V_3 [ V_15 ]
}
} ;
int V_16 ;
V_16 = F_2 ( V_2 -> V_17 , V_9 , F_3 ( V_9 ) ) ;
if ( V_16 != F_3 ( V_9 ) ) {
F_4 ( & V_2 -> V_18 , L_1 , V_19 ) ;
return - V_20 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 const * V_3 )
{
T_1 V_21 [ 1 + 1 ] = { V_22 } ;
struct V_8 V_23 [ 1 ] = {
{
. V_10 = V_2 -> V_10 ,
. V_11 = 0 ,
. V_12 = sizeof( V_21 ) ,
. V_3 = V_21 }
} ;
T_1 V_24 [ V_14 + 1 ] = { V_25 } ;
struct V_8 V_26 [ 1 ] = {
{
. V_10 = V_2 -> V_10 ,
. V_11 = 0 ,
. V_12 = sizeof( V_24 ) ,
. V_3 = V_24 }
} ;
int V_16 ;
V_21 [ 1 ] = V_3 [ V_15 ] ;
V_16 = F_2 ( V_2 -> V_17 , V_23 ,
F_3 ( V_23 ) ) ;
if ( V_16 != F_3 ( V_23 ) )
goto V_27;
F_6 ( V_28 ) ;
memcpy ( & V_24 [ 1 ] , V_3 , V_14 ) ;
V_16 = F_2 ( V_2 -> V_17 , V_26 , F_3 ( V_26 ) ) ;
if ( V_16 != F_3 ( V_26 ) )
goto V_27;
F_6 ( V_28 ) ;
return 0 ;
V_27:
F_4 ( & V_2 -> V_18 , L_2 , V_19 ) ;
return - V_20 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
int V_16 ;
T_1 V_31 [ V_32 ] ;
V_16 = F_1 ( V_2 , V_31 ) ;
if ( V_16 < 0 )
return V_16 ;
V_30 -> V_33 = F_8 ( V_31 [ V_34 ] ) ;
V_30 -> V_35 = F_8 ( V_31 [ V_36 ] ) ;
V_30 -> V_37 = F_8 ( V_31 [ V_38 ] & 0x3f ) ;
V_30 -> V_39 = F_8 ( V_31 [ V_40 ] ) ;
V_30 -> V_41 = F_8 ( V_31 [ V_42 ] ) - 1 ;
V_30 -> V_43 = F_8 ( V_31 [ V_44 ] ) +
F_8 ( V_31 [ V_15 ] ) * 100 - 1900 ;
V_30 -> V_45 = F_8 ( V_31 [ V_46 ] ) ;
return F_9 ( V_30 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
return F_11 ( V_2 , V_47 , 0 ) ;
}
static int
F_12 ( struct V_1 * V_2 , struct V_29 const * V_30 )
{
T_1 V_31 [ V_32 ] ;
int V_16 ;
V_16 = F_10 ( V_2 ) ;
if ( V_16 < 0 )
return V_16 ;
V_31 [ V_34 ] = F_13 ( V_30 -> V_33 ) ;
V_31 [ V_36 ] = F_13 ( V_30 -> V_35 ) ;
V_31 [ V_38 ] = F_13 ( V_30 -> V_37 ) ;
V_31 [ V_40 ] = F_13 ( V_30 -> V_39 ) ;
V_31 [ V_42 ] = F_13 ( V_30 -> V_41 + 1 ) ;
V_31 [ V_46 ] = F_13 ( V_30 -> V_45 ) ;
V_31 [ V_44 ] = F_13 ( V_30 -> V_43 % 100 ) ;
V_31 [ V_15 ] = F_13 ( ( V_30 -> V_43 + 1900 ) / 100 ) ;
V_31 [ V_48 ] = V_49 ;
V_16 = F_5 ( V_2 , V_31 ) ;
if ( V_16 < 0 )
return V_16 ;
return 0 ;
}
static int F_14 ( struct V_50 * V_18 , struct V_29 * V_30 )
{
return F_7 ( F_15 ( V_18 ) , V_30 ) ;
}
static int F_16 ( struct V_50 * V_18 , struct V_29 * V_30 )
{
return F_12 ( F_15 ( V_18 ) , V_30 ) ;
}
static int
F_17 ( struct V_1 * V_2 , const struct V_51 * V_52 )
{
struct V_53 * V_54 ;
if ( ! F_18 ( V_2 -> V_17 , V_55 ) )
return - V_56 ;
V_54 = F_19 ( & V_2 -> V_18 , V_57 . V_58 . V_59 ,
& V_60 , V_61 ) ;
if ( F_20 ( V_54 ) )
return F_21 ( V_54 ) ;
F_22 ( V_2 , V_54 ) ;
return 0 ;
}
