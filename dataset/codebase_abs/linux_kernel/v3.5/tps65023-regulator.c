static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
int V_6 , V_7 = F_3 ( V_2 ) ;
if ( V_7 < V_8 || V_7 > V_9 )
return - V_10 ;
if ( V_7 == V_4 -> V_11 ) {
V_5 = F_4 ( V_4 -> V_12 , V_13 , & V_6 ) ;
if ( V_5 != 0 )
return V_5 ;
V_6 &= ( V_4 -> V_14 [ V_7 ] -> V_15 - 1 ) ;
return V_4 -> V_14 [ V_7 ] -> V_16 [ V_6 ] * 1000 ;
} else
return V_4 -> V_14 [ V_7 ] -> V_17 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned V_18 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 = F_3 ( V_2 ) ;
int V_5 ;
if ( V_7 != V_4 -> V_11 )
return - V_10 ;
V_5 = F_6 ( V_4 -> V_12 , V_13 , V_18 ) ;
if ( V_5 )
goto V_19;
V_5 = F_7 ( V_4 -> V_12 , V_20 ,
V_21 , V_21 ) ;
V_19:
return V_5 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 , V_22 = F_3 ( V_2 ) ;
int V_5 ;
if ( V_22 < V_23 || V_22 > V_24 )
return - V_10 ;
V_5 = F_4 ( V_4 -> V_12 , V_25 , & V_6 ) ;
if ( V_5 != 0 )
return V_5 ;
V_6 >>= ( F_9 ( V_22 - V_23 ) ) ;
V_6 &= ( V_4 -> V_14 [ V_22 ] -> V_15 - 1 ) ;
return V_4 -> V_14 [ V_22 ] -> V_16 [ V_6 ] * 1000 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned V_18 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_26 = F_3 ( V_2 ) - V_23 ;
return F_7 ( V_4 -> V_12 , V_25 ,
F_11 ( V_26 ) ,
V_18 << F_9 ( V_26 ) ) ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned V_18 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 = F_3 ( V_2 ) ;
if ( V_7 < V_8 || V_7 > V_9 )
return - V_10 ;
if ( V_7 == V_4 -> V_11 ) {
if ( V_18 >= V_4 -> V_14 [ V_7 ] -> V_15 )
return - V_10 ;
else
return V_4 -> V_14 [ V_7 ] -> V_16 [ V_18 ] * 1000 ;
} else
return V_4 -> V_14 [ V_7 ] -> V_17 ;
}
static int F_13 ( struct V_1 * V_2 ,
unsigned V_18 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_22 = F_3 ( V_2 ) ;
if ( V_22 < V_23 || V_22 > V_24 )
return - V_10 ;
if ( V_18 >= V_4 -> V_14 [ V_22 ] -> V_15 )
return - V_10 ;
else
return V_4 -> V_14 [ V_22 ] -> V_16 [ V_18 ] * 1000 ;
}
static int T_1 F_14 ( struct V_27 * V_28 ,
const struct V_29 * V_30 )
{
const struct V_31 * V_32 = ( void * ) V_30 -> V_33 ;
const struct V_34 * V_14 = V_32 -> V_14 ;
struct V_35 V_36 = { } ;
struct V_37 * V_38 ;
struct V_1 * V_39 ;
struct V_3 * V_4 ;
int V_40 ;
int error ;
if ( ! F_15 ( V_28 -> V_41 , V_42 ) )
return - V_43 ;
V_38 = V_28 -> V_2 . V_44 ;
if ( ! V_38 )
return - V_43 ;
V_4 = F_16 ( & V_28 -> V_2 , sizeof( * V_4 ) , V_45 ) ;
if ( ! V_4 )
return - V_46 ;
V_4 -> V_12 = F_17 ( V_28 , & V_47 ) ;
if ( F_18 ( V_4 -> V_12 ) ) {
error = F_19 ( V_4 -> V_12 ) ;
F_20 ( & V_28 -> V_2 , L_1 ,
error ) ;
return error ;
}
V_4 -> V_11 = V_32 -> V_11 ;
for ( V_40 = 0 ; V_40 < V_48 ; V_40 ++ , V_14 ++ , V_38 ++ ) {
V_4 -> V_14 [ V_40 ] = V_14 ;
V_4 -> V_49 [ V_40 ] . V_50 = V_14 -> V_50 ;
V_4 -> V_49 [ V_40 ] . V_30 = V_40 ;
V_4 -> V_49 [ V_40 ] . V_51 = V_14 -> V_15 ;
V_4 -> V_49 [ V_40 ] . V_52 = ( V_40 > V_9 ?
& V_53 : & V_54 ) ;
V_4 -> V_49 [ V_40 ] . type = V_55 ;
V_4 -> V_49 [ V_40 ] . V_56 = V_57 ;
V_4 -> V_49 [ V_40 ] . V_58 = V_59 ;
if ( V_40 == V_23 )
V_4 -> V_49 [ V_40 ] . V_60 = 1 << 1 ;
else if ( V_40 == V_24 )
V_4 -> V_49 [ V_40 ] . V_60 = 1 << 2 ;
else
V_4 -> V_49 [ V_40 ] . V_60 =
1 << ( V_48 - V_40 ) ;
V_36 . V_2 = & V_28 -> V_2 ;
V_36 . V_38 = V_38 ;
V_36 . V_33 = V_4 ;
V_36 . V_12 = V_4 -> V_12 ;
V_39 = F_21 ( & V_4 -> V_49 [ V_40 ] , & V_36 ) ;
if ( F_18 ( V_39 ) ) {
F_20 ( & V_28 -> V_2 , L_2 ,
V_30 -> V_50 ) ;
error = F_19 ( V_39 ) ;
goto V_61;
}
V_4 -> V_39 [ V_40 ] = V_39 ;
}
F_22 ( V_28 , V_4 ) ;
F_7 ( V_4 -> V_12 , V_20 ,
V_62 , V_62 ) ;
return 0 ;
V_61:
while ( -- V_40 >= 0 )
F_23 ( V_4 -> V_39 [ V_40 ] ) ;
return error ;
}
static int T_2 F_24 ( struct V_27 * V_28 )
{
struct V_3 * V_4 = F_25 ( V_28 ) ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_48 ; V_40 ++ )
F_23 ( V_4 -> V_39 [ V_40 ] ) ;
return 0 ;
}
static int T_3 F_26 ( void )
{
return F_27 ( & V_63 ) ;
}
static void T_4 F_28 ( void )
{
F_29 ( & V_63 ) ;
}
