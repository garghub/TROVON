static void F_1 ( const T_1 * V_1 , unsigned int V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 ; V_6 ++ ) {
V_5 = 2 + V_6 * 3 ;
V_4 [ V_6 ] . V_7 = ( V_1 [ V_5 ] & 0x0f ) ;
V_4 [ V_6 ] . V_7 <<= 8 ;
V_4 [ V_6 ] . V_7 |= V_1 [ V_5 + 2 ] ;
V_4 [ V_6 ] . V_8 = ( V_1 [ V_5 ] & 0xf0 ) ;
V_4 [ V_6 ] . V_8 <<= 4 ;
V_4 [ V_6 ] . V_8 |= V_1 [ V_5 + 1 ] ;
}
}
static void F_2 ( struct V_9 * V_10 , const T_1 * V_1 )
{
struct V_3 V_4 [ V_11 ] ;
int V_12 [ V_11 ] ;
unsigned int V_2 , V_6 ;
V_2 = V_1 [ 1 ] & 0x07 ;
if ( V_2 > V_11 ) {
F_3 ( & V_10 -> V_13 -> V_14 ,
L_1 ,
V_2 , V_11 ) ;
V_2 = V_11 ;
}
F_1 ( V_1 , V_2 , V_4 ) ;
F_4 ( V_10 -> V_15 , V_12 , V_4 ,
V_2 , 0 ) ;
for ( V_6 = 0 ; V_6 < V_2 ; V_6 ++ ) {
F_5 ( V_10 -> V_15 , V_12 [ V_6 ] ) ;
F_6 ( V_10 -> V_15 , V_16 , true ) ;
F_7 ( V_10 -> V_15 , & V_10 -> V_17 ,
V_4 [ V_6 ] . V_7 , V_4 [ V_6 ] . V_8 , true ) ;
}
F_8 ( V_10 -> V_15 ) ;
F_9 ( V_10 -> V_15 ) ;
}
static T_2 F_10 ( int V_18 , void * V_19 )
{
struct V_9 * V_10 = V_19 ;
struct V_20 * V_14 = & V_10 -> V_13 -> V_14 ;
char V_1 [ V_21 ] ;
int V_22 ;
V_22 = F_11 ( V_10 -> V_13 , V_1 , V_21 ) ;
if ( V_22 != V_21 ) {
F_3 ( V_14 , L_2 , V_22 ) ;
goto V_23;
}
switch ( V_1 [ 0 ] ) {
case V_24 :
F_2 ( V_10 , V_1 ) ;
break;
case V_25 :
if ( V_1 [ 1 ] == V_26 )
F_12 ( V_14 , L_3 ) ;
break;
case V_27 :
case V_28 :
break;
default:
F_3 ( V_14 , L_4 , V_1 [ 0 ] ) ;
break;
}
V_23:
return V_29 ;
}
static int F_13 ( struct V_30 * V_14 )
{
struct V_9 * V_10 = F_14 ( V_14 ) ;
F_15 ( V_10 -> V_13 -> V_18 ) ;
F_16 ( V_10 -> V_31 , 1 ) ;
return 0 ;
}
static void F_17 ( struct V_30 * V_14 )
{
struct V_9 * V_10 = F_14 ( V_14 ) ;
F_18 ( V_10 -> V_13 -> V_18 ) ;
F_16 ( V_10 -> V_31 , 0 ) ;
}
static int T_3 F_19 ( struct V_20 * V_14 )
{
struct V_9 * V_10 = F_20 ( F_21 ( V_14 ) ) ;
F_22 ( & V_10 -> V_15 -> V_32 ) ;
if ( V_10 -> V_15 -> V_33 )
F_17 ( V_10 -> V_15 ) ;
F_23 ( & V_10 -> V_15 -> V_32 ) ;
return 0 ;
}
static int T_3 F_24 ( struct V_20 * V_14 )
{
struct V_9 * V_10 = F_20 ( F_21 ( V_14 ) ) ;
F_22 ( & V_10 -> V_15 -> V_32 ) ;
if ( V_10 -> V_15 -> V_33 )
F_13 ( V_10 -> V_15 ) ;
F_23 ( & V_10 -> V_15 -> V_32 ) ;
return 0 ;
}
static int F_25 ( struct V_34 * V_13 , bool V_35 )
{
struct V_20 * V_14 = & V_13 -> V_14 ;
const char * V_36 = V_35 ? L_5 : L_6 ;
T_1 V_37 = V_35 ? V_38 : V_39 ;
T_1 V_1 [ 4 ] ;
int V_22 ;
int error ;
V_1 [ 0 ] = V_40 ;
V_1 [ 1 ] = V_35 ? V_38 : V_39 ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_22 = F_26 ( V_13 , V_1 , sizeof( V_1 ) ) ;
if ( V_22 != sizeof( V_1 ) ) {
error = V_22 < 0 ? V_22 : - V_41 ;
F_3 ( V_14 , L_7 , V_36 , error ) ;
return error ;
}
F_27 ( 20 ) ;
V_22 = F_11 ( V_13 , V_1 , sizeof( V_1 ) ) ;
if ( V_22 != sizeof( V_1 ) ) {
error = V_22 < 0 ? V_22 : - V_41 ;
F_3 ( V_14 , L_8 , V_36 , error ) ;
return error ;
}
if ( V_1 [ 0 ] != V_42 || V_1 [ 1 ] != V_37 ) {
F_3 ( V_14 , L_9 ,
V_36 , V_1 [ 0 ] , V_1 [ 1 ] ) ;
return - V_41 ;
}
return ( ( ( V_1 [ 3 ] & 0xf0 ) << 4 ) | V_1 [ 2 ] ) - 1 ;
}
static int F_28 ( struct V_34 * V_13 ,
const struct V_43 * V_44 )
{
struct V_20 * V_14 = & V_13 -> V_14 ;
struct V_9 * V_10 ;
struct V_30 * V_15 ;
T_1 V_1 [ 4 ] ;
int V_45 , V_46 ;
int error ;
if ( ! V_13 -> V_18 ) {
F_3 ( V_14 , L_10 ) ;
return - V_47 ;
}
V_10 = F_29 ( V_14 , sizeof( * V_10 ) , V_48 ) ;
if ( ! V_10 )
return - V_49 ;
V_10 -> V_31 = F_30 ( V_14 , L_11 , V_50 ) ;
if ( F_31 ( V_10 -> V_31 ) ) {
error = F_32 ( V_10 -> V_31 ) ;
if ( error != - V_51 )
F_3 ( V_14 , L_12 , error ) ;
return error ;
}
V_15 = F_33 ( V_14 ) ;
if ( ! V_15 )
return - V_49 ;
V_15 -> V_52 = V_13 -> V_52 ;
V_15 -> V_44 . V_53 = V_54 ;
V_15 -> V_55 = F_13 ;
V_15 -> V_56 = F_17 ;
V_10 -> V_13 = V_13 ;
F_27 ( 20 ) ;
F_11 ( V_10 -> V_13 , V_1 , sizeof( V_1 ) ) ;
V_45 = F_25 ( V_13 , true ) ;
if ( V_45 < 0 )
return V_45 ;
V_46 = F_25 ( V_13 , false ) ;
if ( V_46 < 0 )
return V_46 ;
F_34 ( V_15 , V_57 , 0 , V_45 , 0 , 0 ) ;
F_34 ( V_15 , V_58 , 0 , V_46 , 0 , 0 ) ;
F_35 ( V_15 , true , & V_10 -> V_17 ) ;
error = F_36 ( V_15 , V_11 ,
V_59 |
V_60 |
V_61 ) ;
if ( error )
return error ;
V_10 -> V_15 = V_15 ;
F_37 ( V_15 , V_10 ) ;
error = F_38 ( V_14 , V_13 -> V_18 ,
NULL , F_10 ,
V_62 , V_13 -> V_52 , V_10 ) ;
if ( error ) {
F_3 ( V_14 , L_13 , error ) ;
return error ;
}
F_17 ( V_10 -> V_15 ) ;
error = F_39 ( V_15 ) ;
if ( error )
return error ;
F_40 ( V_13 , V_10 ) ;
return 0 ;
}
