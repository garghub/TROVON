static void F_1 ( struct V_1 * V_1 )
{
int V_2 ;
int V_3 ;
int V_4 , V_5 , V_6 ;
switch ( V_1 -> V_7 [ 0 ] ) {
case 0xff :
case 0x00 :
break;
case 0x0e :
V_2 = ( V_1 -> V_7 [ 1 ] & 0x01 ) ;
V_3 = ( V_1 -> V_7 [ 1 ] & 0x02 ) ;
V_4 = ( ( V_1 -> V_7 [ 2 ] & 0x1f ) << 8 ) | V_1 -> V_7 [ 3 ] ;
V_5 = ( ( V_1 -> V_7 [ 4 ] & 0x1f ) << 8 ) | V_1 -> V_7 [ 5 ] ;
V_6 = V_1 -> V_7 [ 6 ] ;
F_2 ( V_1 -> V_8 , V_9 , V_2 ) ;
F_3 ( V_1 -> V_8 , V_10 , V_4 ) ;
F_3 ( V_1 -> V_8 , V_11 , V_5 ) ;
F_3 ( V_1 -> V_8 , V_12 , V_6 ) ;
F_2 ( V_1 -> V_8 , V_13 , V_2 ) ;
F_2 ( V_1 -> V_8 , V_14 , V_3 ) ;
F_4 ( V_1 -> V_8 ) ;
break;
case 0x19 :
if ( ( V_1 -> V_7 [ 1 ] & 0xf0 ) == 0x10 )
break;
default:
F_5 ( V_1 -> V_15 ,
L_1 ,
V_1 -> V_7 [ 0 ] , V_1 -> V_7 [ 1 ] ) ;
break;
}
}
static T_1 F_6 ( int V_16 , void * V_17 )
{
struct V_1 * V_1 = V_17 ;
struct V_18 * V_19 = V_1 -> V_19 ;
T_1 V_20 = V_21 ;
T_2 V_22 ;
V_22 = F_7 ( V_19 , V_23 ) ;
if ( V_22 & V_24 ) {
F_5 ( V_1 -> V_15 ,
L_2 , V_22 ) ;
F_8 ( V_19 , V_23 , ( V_22 & V_24 ) ) ;
V_20 = V_25 ;
}
while ( V_22 & V_26 ) {
T_2 V_7 ;
V_7 = F_7 ( V_19 , V_27 ) ;
V_1 -> V_7 [ V_1 -> V_28 + 0 ] = ( V_7 >> 8 ) ;
V_1 -> V_7 [ V_1 -> V_28 + 1 ] = V_7 ;
V_1 -> V_28 += 2 ;
if ( F_9 ( V_1 -> V_7 [ 0 ] ) < V_1 -> V_28 ) {
F_1 ( V_1 ) ;
V_1 -> V_28 = 0 ;
}
V_22 = F_7 ( V_19 , V_23 ) ;
V_20 = V_25 ;
}
return V_20 ;
}
static void F_10 ( struct V_1 * V_1 )
{
struct V_18 * V_19 = V_1 -> V_19 ;
int V_29 ;
F_11 ( V_19 -> V_30 ) ;
F_8 ( V_19 , V_31 , V_32 ) ;
F_8 ( V_19 , V_23 , V_24 ) ;
F_8 ( V_19 , V_33 , 0 ) ;
F_8 ( V_19 , V_34 , V_35 ) ;
for ( V_29 = 100 ; V_29 != 0 ; -- V_29 ) {
if ( ! ( F_7 ( V_19 , V_23 ) & V_36 ) )
break;
F_12 ( 1 ) ;
}
if ( V_29 == 0 )
F_13 ( V_1 -> V_15 ,
L_3 ) ;
if ( F_14 ( V_1 -> V_37 ) )
F_15 ( V_1 -> V_37 , 1 ) ;
}
static void F_16 ( struct V_1 * V_1 )
{
struct V_18 * V_19 = V_1 -> V_19 ;
if ( F_14 ( V_1 -> V_37 ) )
F_15 ( V_1 -> V_37 , 0 ) ;
F_8 ( V_19 , V_34 , 0 ) ;
F_17 ( V_19 -> V_30 ) ;
}
static int F_18 ( struct V_38 * V_8 )
{
struct V_1 * V_1 = F_19 ( V_8 ) ;
F_10 ( V_1 ) ;
return 0 ;
}
static void F_20 ( struct V_38 * V_8 )
{
struct V_1 * V_1 = F_19 ( V_8 ) ;
F_16 ( V_1 ) ;
}
static int T_3 F_21 ( struct V_39 * V_40 )
{
const struct V_41 * V_42 =
F_22 ( & V_40 -> V_15 ) ;
struct V_18 * V_19 ;
struct V_38 * V_8 ;
struct V_1 * V_1 ;
int error ;
if ( ! V_42 ) {
F_13 ( & V_40 -> V_15 , L_4 ) ;
return - V_43 ;
}
if ( F_14 ( V_42 -> V_37 ) ) {
error = F_23 ( V_42 -> V_37 , V_44 ,
L_5 ) ;
if ( error )
return error ;
}
V_19 = F_24 ( V_42 -> V_45 , V_40 -> V_46 ) ;
if ( ! V_19 ) {
error = - V_47 ;
goto V_48;
}
if ( F_7 ( V_19 , V_34 ) & V_49 ) {
F_8 ( V_19 , V_34 , 0 ) ;
F_5 ( & V_40 -> V_15 , L_6 , V_42 -> V_45 ) ;
}
V_1 = F_25 ( sizeof( * V_1 ) , V_50 ) ;
V_8 = F_26 () ;
if ( ! V_1 || ! V_8 ) {
error = - V_51 ;
goto V_52;
}
V_1 -> V_19 = V_19 ;
V_1 -> V_8 = V_8 ;
V_1 -> V_15 = & V_40 -> V_15 ;
V_1 -> V_37 = V_42 -> V_37 ;
V_8 -> V_46 = V_40 -> V_46 ;
V_8 -> V_15 . V_53 = & V_40 -> V_15 ;
F_27 ( V_54 , V_8 -> V_55 ) ;
F_27 ( V_56 , V_8 -> V_55 ) ;
F_27 ( V_14 , V_8 -> V_57 ) ;
F_27 ( V_9 , V_8 -> V_57 ) ;
F_27 ( V_13 , V_8 -> V_57 ) ;
F_28 ( V_8 , V_10 ,
V_58 , V_59 , 0 , 0 ) ;
F_28 ( V_8 , V_11 ,
V_60 , V_61 , 0 , 0 ) ;
F_28 ( V_8 , V_12 ,
V_62 , V_63 ,
0 , 0 ) ;
V_8 -> V_64 = F_18 ;
V_8 -> V_65 = F_20 ;
F_29 ( V_8 , V_1 ) ;
error = F_30 ( V_19 -> V_16 , F_6 , 0 , V_40 -> V_46 , V_1 ) ;
if ( error )
goto V_52;
error = F_31 ( V_8 ) ;
if ( error )
goto V_66;
F_32 ( V_40 , V_1 ) ;
F_33 ( & V_40 -> V_15 , L_7 , V_42 -> V_45 , V_19 -> V_16 ) ;
return 0 ;
V_66:
F_34 ( V_19 -> V_16 , & V_40 -> V_15 ) ;
V_52:
F_35 ( V_8 ) ;
F_36 ( V_1 ) ;
F_37 ( V_19 ) ;
V_48:
if ( F_14 ( V_42 -> V_37 ) )
F_38 ( V_42 -> V_37 ) ;
return error ;
}
static int T_4 F_39 ( struct V_39 * V_40 )
{
const struct V_41 * V_42 =
F_22 ( & V_40 -> V_15 ) ;
struct V_1 * V_1 = F_40 ( V_40 ) ;
struct V_18 * V_19 = V_1 -> V_19 ;
F_34 ( V_19 -> V_16 , V_1 ) ;
F_41 ( V_1 -> V_8 ) ;
F_36 ( V_1 ) ;
F_37 ( V_19 ) ;
if ( F_14 ( V_42 -> V_37 ) )
F_38 ( V_42 -> V_37 ) ;
return 0 ;
}
static int F_42 ( struct V_67 * V_15 )
{
struct V_39 * V_40 = F_43 ( V_15 ) ;
struct V_1 * V_1 = F_40 ( V_40 ) ;
struct V_38 * V_8 = V_1 -> V_8 ;
F_44 ( & V_8 -> V_68 ) ;
if ( V_8 -> V_69 )
F_16 ( V_1 ) ;
F_45 ( & V_8 -> V_68 ) ;
return 0 ;
}
static int F_46 ( struct V_67 * V_15 )
{
struct V_39 * V_40 = F_43 ( V_15 ) ;
struct V_1 * V_1 = F_40 ( V_40 ) ;
struct V_38 * V_8 = V_1 -> V_8 ;
F_44 ( & V_8 -> V_68 ) ;
if ( V_8 -> V_69 )
F_10 ( V_1 ) ;
F_45 ( & V_8 -> V_68 ) ;
return 0 ;
}
