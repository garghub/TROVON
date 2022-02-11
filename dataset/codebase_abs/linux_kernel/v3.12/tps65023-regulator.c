static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = F_3 ( V_2 ) ;
if ( V_5 < V_6 || V_5 > V_7 )
return - V_8 ;
if ( V_5 != V_4 -> V_9 )
return 0 ;
return F_4 ( V_2 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = F_3 ( V_2 ) ;
if ( V_5 != V_4 -> V_9 )
return - V_8 ;
return F_6 ( V_2 , V_10 ) ;
}
static int F_7 ( struct V_11 * V_12 ,
const struct V_13 * V_14 )
{
const struct V_15 * V_16 = ( void * ) V_14 -> V_17 ;
const struct V_18 * V_19 = V_16 -> V_19 ;
struct V_20 V_21 = { } ;
struct V_22 * V_23 ;
struct V_1 * V_24 ;
struct V_3 * V_4 ;
int V_25 ;
int error ;
if ( ! F_8 ( V_12 -> V_26 , V_27 ) )
return - V_28 ;
V_23 = F_9 ( & V_12 -> V_2 ) ;
if ( ! V_23 )
return - V_28 ;
V_4 = F_10 ( & V_12 -> V_2 , sizeof( * V_4 ) , V_29 ) ;
if ( ! V_4 )
return - V_30 ;
V_4 -> V_31 = F_11 ( V_12 , & V_32 ) ;
if ( F_12 ( V_4 -> V_31 ) ) {
error = F_13 ( V_4 -> V_31 ) ;
F_14 ( & V_12 -> V_2 , L_1 ,
error ) ;
return error ;
}
V_4 -> V_9 = V_16 -> V_9 ;
for ( V_25 = 0 ; V_25 < V_33 ; V_25 ++ , V_19 ++ , V_23 ++ ) {
V_4 -> V_19 [ V_25 ] = V_19 ;
V_4 -> V_34 [ V_25 ] . V_35 = V_19 -> V_35 ;
V_4 -> V_34 [ V_25 ] . V_14 = V_25 ;
V_4 -> V_34 [ V_25 ] . V_36 = V_19 -> V_37 ;
V_4 -> V_34 [ V_25 ] . V_38 = V_19 -> V_39 ;
V_4 -> V_34 [ V_25 ] . V_40 = ( V_25 > V_7 ?
& V_41 : & V_42 ) ;
V_4 -> V_34 [ V_25 ] . type = V_43 ;
V_4 -> V_34 [ V_25 ] . V_44 = V_45 ;
V_4 -> V_34 [ V_25 ] . V_46 = V_47 ;
switch ( V_25 ) {
case V_48 :
V_4 -> V_34 [ V_25 ] . V_49 = V_50 ;
V_4 -> V_34 [ V_25 ] . V_51 = 0x07 ;
V_4 -> V_34 [ V_25 ] . V_52 = 1 << 1 ;
break;
case V_53 :
V_4 -> V_34 [ V_25 ] . V_49 = V_50 ;
V_4 -> V_34 [ V_25 ] . V_51 = 0x70 ;
V_4 -> V_34 [ V_25 ] . V_52 = 1 << 2 ;
break;
default:
V_4 -> V_34 [ V_25 ] . V_52 =
1 << ( V_33 - V_25 ) ;
V_4 -> V_34 [ V_25 ] . V_49 = V_54 ;
V_4 -> V_34 [ V_25 ] . V_51 = V_19 -> V_37 - 1 ;
V_4 -> V_34 [ V_25 ] . V_55 = V_56 ;
V_4 -> V_34 [ V_25 ] . V_57 = V_58 ;
}
V_21 . V_2 = & V_12 -> V_2 ;
V_21 . V_23 = V_23 ;
V_21 . V_17 = V_4 ;
V_21 . V_31 = V_4 -> V_31 ;
V_24 = F_15 ( & V_4 -> V_34 [ V_25 ] , & V_21 ) ;
if ( F_12 ( V_24 ) ) {
F_14 ( & V_12 -> V_2 , L_2 ,
V_14 -> V_35 ) ;
error = F_13 ( V_24 ) ;
goto V_59;
}
V_4 -> V_24 [ V_25 ] = V_24 ;
}
F_16 ( V_12 , V_4 ) ;
F_17 ( V_4 -> V_31 , V_56 ,
V_60 , V_60 ) ;
return 0 ;
V_59:
while ( -- V_25 >= 0 )
F_18 ( V_4 -> V_24 [ V_25 ] ) ;
return error ;
}
static int F_19 ( struct V_11 * V_12 )
{
struct V_3 * V_4 = F_20 ( V_12 ) ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_33 ; V_25 ++ )
F_18 ( V_4 -> V_24 [ V_25 ] ) ;
return 0 ;
}
static int T_1 F_21 ( void )
{
return F_22 ( & V_61 ) ;
}
static void T_2 F_23 ( void )
{
F_24 ( & V_61 ) ;
}
