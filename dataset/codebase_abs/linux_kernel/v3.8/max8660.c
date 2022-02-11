static int F_1 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 , T_1 V_4 )
{
static const T_1 V_5 [ V_6 ] =
{ 0x10 , 0x12 , 0x20 , 0x23 , 0x24 , 0x29 , 0x2a , 0x32 , 0x33 , 0x39 , 0x80 } ;
int V_7 ;
T_1 V_8 = ( V_1 -> V_9 [ V_2 ] & V_3 ) | V_4 ;
F_2 ( & V_1 -> V_10 -> V_11 , L_1 ,
V_5 [ V_2 ] , V_8 ) ;
V_7 = F_3 ( V_1 -> V_10 ,
V_5 [ V_2 ] , V_8 ) ;
if ( V_7 == 0 )
V_1 -> V_9 [ V_2 ] = V_8 ;
return V_7 ;
}
static int F_4 ( struct V_12 * V_13 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_1 V_4 = V_1 -> V_9 [ V_14 ] ;
T_1 V_3 = ( F_6 ( V_13 ) == V_15 ) ? 1 : 4 ;
return ! ! ( V_4 & V_3 ) ;
}
static int F_7 ( struct V_12 * V_13 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_1 V_16 = ( F_6 ( V_13 ) == V_15 ) ? 1 : 4 ;
return F_1 ( V_1 , V_14 , 0xff , V_16 ) ;
}
static int F_8 ( struct V_12 * V_13 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_1 V_3 = ( F_6 ( V_13 ) == V_15 ) ? ~ 1 : ~ 4 ;
return F_1 ( V_1 , V_14 , V_3 , 0 ) ;
}
static int F_9 ( struct V_12 * V_13 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_1 V_2 = ( F_6 ( V_13 ) == V_15 ) ? V_17 : V_18 ;
T_1 V_19 = V_1 -> V_9 [ V_2 ] ;
return V_19 ;
}
static int F_10 ( struct V_12 * V_13 ,
unsigned int V_19 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_1 V_2 , V_20 ;
int V_7 ;
V_2 = ( F_6 ( V_13 ) == V_15 ) ? V_17 : V_18 ;
V_7 = F_1 ( V_1 , V_2 , 0 , V_19 ) ;
if ( V_7 )
return V_7 ;
V_20 = ( F_6 ( V_13 ) == V_15 ) ? 0x03 : 0x30 ;
return F_1 ( V_1 , V_21 , 0xff , V_20 ) ;
}
static int F_11 ( struct V_12 * V_13 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_1 V_19 = V_1 -> V_9 [ V_22 ] ;
return V_19 ;
}
static int F_12 ( struct V_12 * V_13 ,
unsigned int V_19 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
int V_7 ;
V_7 = F_1 ( V_1 , V_22 , 0 , V_19 ) ;
if ( V_7 )
return V_7 ;
return F_1 ( V_1 , V_21 , 0xff , 0xc0 ) ;
}
static int F_13 ( struct V_12 * V_13 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_1 V_4 = V_1 -> V_9 [ V_23 ] ;
T_1 V_3 = ( F_6 ( V_13 ) == V_24 ) ? 2 : 4 ;
return ! ! ( V_4 & V_3 ) ;
}
static int F_14 ( struct V_12 * V_13 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_1 V_16 = ( F_6 ( V_13 ) == V_24 ) ? 2 : 4 ;
return F_1 ( V_1 , V_23 , 0xff , V_16 ) ;
}
static int F_15 ( struct V_12 * V_13 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_1 V_3 = ( F_6 ( V_13 ) == V_24 ) ? ~ 2 : ~ 4 ;
return F_1 ( V_1 , V_23 , V_3 , 0 ) ;
}
static int F_16 ( struct V_12 * V_13 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_1 V_25 = ( F_6 ( V_13 ) == V_24 ) ? 0 : 4 ;
T_1 V_19 = ( V_1 -> V_9 [ V_26 ] >> V_25 ) & 0xf ;
return V_19 ;
}
static int F_17 ( struct V_12 * V_13 ,
unsigned int V_19 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
if ( F_6 ( V_13 ) == V_24 )
return F_1 ( V_1 , V_26 , 0xf0 , V_19 ) ;
else
return F_1 ( V_1 , V_26 , 0x0f ,
V_19 << 4 ) ;
}
static int F_18 ( struct V_27 * V_10 ,
const struct V_28 * V_29 )
{
struct V_12 * * V_13 ;
struct V_30 * V_31 = V_10 -> V_11 . V_32 ;
struct V_33 V_34 = { } ;
struct V_1 * V_1 ;
int V_35 , V_36 , V_37 , V_7 = - V_38 ;
if ( V_31 -> V_39 > V_40 ) {
F_19 ( & V_10 -> V_11 , L_2 ) ;
return - V_38 ;
}
V_1 = F_20 ( & V_10 -> V_11 , sizeof( struct V_1 ) +
sizeof( struct V_12 * ) * V_40 ,
V_41 ) ;
if ( ! V_1 )
return - V_42 ;
V_1 -> V_10 = V_10 ;
V_13 = V_1 -> V_13 ;
if ( V_31 -> V_43 ) {
V_1 -> V_9 [ V_14 ] = 5 ;
} else {
V_44 . V_45 = F_7 ;
V_44 . V_46 = F_8 ;
}
V_1 -> V_9 [ V_47 ] =
V_1 -> V_9 [ V_17 ] =
V_1 -> V_9 [ V_48 ] =
V_1 -> V_9 [ V_18 ] = 0x1b ;
V_1 -> V_9 [ V_49 ] =
V_1 -> V_9 [ V_22 ] = 0x04 ;
for ( V_36 = 0 ; V_36 < V_31 -> V_39 ; V_36 ++ ) {
if ( ! V_31 -> V_50 [ V_36 ] . V_32 )
goto V_51;
V_35 = V_31 -> V_50 [ V_36 ] . V_32 -> V_52 . V_35 ;
switch ( V_31 -> V_50 [ V_36 ] . V_37 ) {
case V_15 :
if ( V_35 )
V_1 -> V_9 [ V_14 ] |= 1 ;
break;
case V_53 :
if ( V_35 )
V_1 -> V_9 [ V_14 ] |= 4 ;
break;
case V_54 :
break;
case V_24 :
if ( V_35 )
V_1 -> V_9 [ V_23 ] |= 2 ;
break;
case V_55 :
if ( ! strcmp ( V_29 -> V_56 , L_3 ) ) {
F_19 ( & V_10 -> V_11 , L_4 ) ;
goto V_51;
}
if ( V_35 )
V_1 -> V_9 [ V_23 ] |= 4 ;
break;
default:
F_19 ( & V_10 -> V_11 , L_5 ,
V_31 -> V_50 [ V_36 ] . V_56 ) ;
goto V_51;
}
}
for ( V_36 = 0 ; V_36 < V_31 -> V_39 ; V_36 ++ ) {
V_37 = V_31 -> V_50 [ V_36 ] . V_37 ;
V_34 . V_11 = & V_10 -> V_11 ;
V_34 . V_57 = V_31 -> V_50 [ V_36 ] . V_32 ;
V_34 . V_58 = V_1 ;
V_13 [ V_36 ] = F_21 ( & V_59 [ V_37 ] , & V_34 ) ;
if ( F_22 ( V_13 [ V_36 ] ) ) {
V_7 = F_23 ( V_13 [ V_36 ] ) ;
F_19 ( & V_10 -> V_11 , L_6 ,
V_59 [ V_37 ] . V_56 ) ;
goto V_60;
}
}
F_24 ( V_10 , V_1 ) ;
return 0 ;
V_60:
while ( -- V_36 >= 0 )
F_25 ( V_13 [ V_36 ] ) ;
V_51:
return V_7 ;
}
static int F_26 ( struct V_27 * V_10 )
{
struct V_1 * V_1 = F_27 ( V_10 ) ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_40 ; V_36 ++ )
if ( V_1 -> V_13 [ V_36 ] )
F_25 ( V_1 -> V_13 [ V_36 ] ) ;
return 0 ;
}
static int T_2 F_28 ( void )
{
return F_29 ( & V_61 ) ;
}
static void T_3 F_30 ( void )
{
F_31 ( & V_61 ) ;
}
