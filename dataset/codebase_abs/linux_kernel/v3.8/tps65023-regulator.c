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
return V_6 ;
} else
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 = F_3 ( V_2 ) ;
int V_5 ;
if ( V_7 != V_4 -> V_11 )
return - V_10 ;
V_5 = F_6 ( V_4 -> V_12 , V_13 , V_16 ) ;
if ( V_5 )
goto V_17;
V_5 = F_7 ( V_4 -> V_12 , V_18 ,
V_19 , V_19 ) ;
V_17:
return V_5 ;
}
static int F_8 ( struct V_20 * V_21 ,
const struct V_22 * V_23 )
{
const struct V_24 * V_25 = ( void * ) V_23 -> V_26 ;
const struct V_27 * V_14 = V_25 -> V_14 ;
struct V_28 V_29 = { } ;
struct V_30 * V_31 ;
struct V_1 * V_32 ;
struct V_3 * V_4 ;
int V_33 ;
int error ;
if ( ! F_9 ( V_21 -> V_34 , V_35 ) )
return - V_36 ;
V_31 = V_21 -> V_2 . V_37 ;
if ( ! V_31 )
return - V_36 ;
V_4 = F_10 ( & V_21 -> V_2 , sizeof( * V_4 ) , V_38 ) ;
if ( ! V_4 )
return - V_39 ;
V_4 -> V_12 = F_11 ( V_21 , & V_40 ) ;
if ( F_12 ( V_4 -> V_12 ) ) {
error = F_13 ( V_4 -> V_12 ) ;
F_14 ( & V_21 -> V_2 , L_1 ,
error ) ;
return error ;
}
V_4 -> V_11 = V_25 -> V_11 ;
for ( V_33 = 0 ; V_33 < V_41 ; V_33 ++ , V_14 ++ , V_31 ++ ) {
V_4 -> V_14 [ V_33 ] = V_14 ;
V_4 -> V_42 [ V_33 ] . V_43 = V_14 -> V_43 ;
V_4 -> V_42 [ V_33 ] . V_23 = V_33 ;
V_4 -> V_42 [ V_33 ] . V_44 = V_14 -> V_15 ;
V_4 -> V_42 [ V_33 ] . V_45 = V_14 -> V_46 ;
V_4 -> V_42 [ V_33 ] . V_47 = ( V_33 > V_9 ?
& V_48 : & V_49 ) ;
V_4 -> V_42 [ V_33 ] . type = V_50 ;
V_4 -> V_42 [ V_33 ] . V_51 = V_52 ;
V_4 -> V_42 [ V_33 ] . V_53 = V_54 ;
switch ( V_33 ) {
case V_55 :
V_4 -> V_42 [ V_33 ] . V_56 = V_57 ;
V_4 -> V_42 [ V_33 ] . V_58 = 0x07 ;
V_4 -> V_42 [ V_33 ] . V_59 = 1 << 1 ;
break;
case V_60 :
V_4 -> V_42 [ V_33 ] . V_56 = V_57 ;
V_4 -> V_42 [ V_33 ] . V_58 = 0x70 ;
V_4 -> V_42 [ V_33 ] . V_59 = 1 << 2 ;
break;
default:
V_4 -> V_42 [ V_33 ] . V_59 =
1 << ( V_41 - V_33 ) ;
}
V_29 . V_2 = & V_21 -> V_2 ;
V_29 . V_31 = V_31 ;
V_29 . V_26 = V_4 ;
V_29 . V_12 = V_4 -> V_12 ;
V_32 = F_15 ( & V_4 -> V_42 [ V_33 ] , & V_29 ) ;
if ( F_12 ( V_32 ) ) {
F_14 ( & V_21 -> V_2 , L_2 ,
V_23 -> V_43 ) ;
error = F_13 ( V_32 ) ;
goto V_61;
}
V_4 -> V_32 [ V_33 ] = V_32 ;
}
F_16 ( V_21 , V_4 ) ;
F_7 ( V_4 -> V_12 , V_18 ,
V_62 , V_62 ) ;
return 0 ;
V_61:
while ( -- V_33 >= 0 )
F_17 ( V_4 -> V_32 [ V_33 ] ) ;
return error ;
}
static int F_18 ( struct V_20 * V_21 )
{
struct V_3 * V_4 = F_19 ( V_21 ) ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_41 ; V_33 ++ )
F_17 ( V_4 -> V_32 [ V_33 ] ) ;
return 0 ;
}
static int T_1 F_20 ( void )
{
return F_21 ( & V_63 ) ;
}
static void T_2 F_22 ( void )
{
F_23 ( & V_63 ) ;
}
