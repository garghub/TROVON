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
V_23 = V_12 -> V_2 . V_29 ;
if ( ! V_23 )
return - V_28 ;
V_4 = F_9 ( & V_12 -> V_2 , sizeof( * V_4 ) , V_30 ) ;
if ( ! V_4 )
return - V_31 ;
V_4 -> V_32 = F_10 ( V_12 , & V_33 ) ;
if ( F_11 ( V_4 -> V_32 ) ) {
error = F_12 ( V_4 -> V_32 ) ;
F_13 ( & V_12 -> V_2 , L_1 ,
error ) ;
return error ;
}
V_4 -> V_9 = V_16 -> V_9 ;
for ( V_25 = 0 ; V_25 < V_34 ; V_25 ++ , V_19 ++ , V_23 ++ ) {
V_4 -> V_19 [ V_25 ] = V_19 ;
V_4 -> V_35 [ V_25 ] . V_36 = V_19 -> V_36 ;
V_4 -> V_35 [ V_25 ] . V_14 = V_25 ;
V_4 -> V_35 [ V_25 ] . V_37 = V_19 -> V_38 ;
V_4 -> V_35 [ V_25 ] . V_39 = V_19 -> V_40 ;
V_4 -> V_35 [ V_25 ] . V_41 = ( V_25 > V_7 ?
& V_42 : & V_43 ) ;
V_4 -> V_35 [ V_25 ] . type = V_44 ;
V_4 -> V_35 [ V_25 ] . V_45 = V_46 ;
V_4 -> V_35 [ V_25 ] . V_47 = V_48 ;
switch ( V_25 ) {
case V_49 :
V_4 -> V_35 [ V_25 ] . V_50 = V_51 ;
V_4 -> V_35 [ V_25 ] . V_52 = 0x07 ;
V_4 -> V_35 [ V_25 ] . V_53 = 1 << 1 ;
break;
case V_54 :
V_4 -> V_35 [ V_25 ] . V_50 = V_51 ;
V_4 -> V_35 [ V_25 ] . V_52 = 0x70 ;
V_4 -> V_35 [ V_25 ] . V_53 = 1 << 2 ;
break;
default:
V_4 -> V_35 [ V_25 ] . V_53 =
1 << ( V_34 - V_25 ) ;
V_4 -> V_35 [ V_25 ] . V_50 = V_55 ;
V_4 -> V_35 [ V_25 ] . V_52 = V_19 -> V_38 - 1 ;
V_4 -> V_35 [ V_25 ] . V_56 = V_57 ;
V_4 -> V_35 [ V_25 ] . V_58 = V_59 ;
}
V_21 . V_2 = & V_12 -> V_2 ;
V_21 . V_23 = V_23 ;
V_21 . V_17 = V_4 ;
V_21 . V_32 = V_4 -> V_32 ;
V_24 = F_14 ( & V_4 -> V_35 [ V_25 ] , & V_21 ) ;
if ( F_11 ( V_24 ) ) {
F_13 ( & V_12 -> V_2 , L_2 ,
V_14 -> V_36 ) ;
error = F_12 ( V_24 ) ;
goto V_60;
}
V_4 -> V_24 [ V_25 ] = V_24 ;
}
F_15 ( V_12 , V_4 ) ;
F_16 ( V_4 -> V_32 , V_57 ,
V_61 , V_61 ) ;
return 0 ;
V_60:
while ( -- V_25 >= 0 )
F_17 ( V_4 -> V_24 [ V_25 ] ) ;
return error ;
}
static int F_18 ( struct V_11 * V_12 )
{
struct V_3 * V_4 = F_19 ( V_12 ) ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_34 ; V_25 ++ )
F_17 ( V_4 -> V_24 [ V_25 ] ) ;
return 0 ;
}
static int T_1 F_20 ( void )
{
return F_21 ( & V_62 ) ;
}
static void T_2 F_22 ( void )
{
F_23 ( & V_62 ) ;
}
