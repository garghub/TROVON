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
static int F_9 ( struct V_12 * V_13 , unsigned V_17 )
{
if ( V_17 > V_18 )
return - V_19 ;
return V_20 + V_17 * V_21 ;
}
static int F_10 ( struct V_12 * V_13 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_1 V_2 = ( F_6 ( V_13 ) == V_15 ) ? V_22 : V_23 ;
T_1 V_17 = V_1 -> V_9 [ V_2 ] ;
return V_20 + V_17 * V_21 ;
}
static int F_11 ( struct V_12 * V_13 , int V_24 , int V_25 ,
unsigned int * V_26 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_1 V_2 , V_17 , V_27 ;
int V_7 ;
if ( V_24 < V_20 || V_24 > V_28 )
return - V_19 ;
if ( V_25 < V_20 || V_25 > V_28 )
return - V_19 ;
V_17 = F_12 ( V_24 - V_20 ,
V_21 ) ;
V_7 = F_9 ( V_13 , V_17 ) ;
if ( V_7 < 0 || V_7 > V_25 )
return - V_19 ;
* V_26 = V_17 ;
V_2 = ( F_6 ( V_13 ) == V_15 ) ? V_22 : V_23 ;
V_7 = F_1 ( V_1 , V_2 , 0 , V_17 ) ;
if ( V_7 )
return V_7 ;
V_27 = ( F_6 ( V_13 ) == V_15 ) ? 0x03 : 0x30 ;
return F_1 ( V_1 , V_29 , 0xff , V_27 ) ;
}
static int F_13 ( struct V_12 * V_13 , unsigned V_17 )
{
if ( V_17 > V_30 )
return - V_19 ;
return V_31 + V_17 * V_32 ;
}
static int F_14 ( struct V_12 * V_13 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_1 V_17 = V_1 -> V_9 [ V_33 ] ;
return V_31 + V_17 * V_32 ;
}
static int F_15 ( struct V_12 * V_13 , int V_24 , int V_25 ,
unsigned int * V_26 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_1 V_17 ;
int V_7 ;
if ( V_24 < V_31 || V_24 > V_34 )
return - V_19 ;
if ( V_25 < V_31 || V_25 > V_34 )
return - V_19 ;
V_17 = F_12 ( V_24 - V_31 ,
V_32 ) ;
V_7 = F_13 ( V_13 , V_17 ) ;
if ( V_7 < 0 || V_7 > V_25 )
return - V_19 ;
* V_26 = V_17 ;
V_7 = F_1 ( V_1 , V_33 , 0 , V_17 ) ;
if ( V_7 )
return V_7 ;
return F_1 ( V_1 , V_29 , 0xff , 0xc0 ) ;
}
static int F_16 ( struct V_12 * V_13 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_1 V_4 = V_1 -> V_9 [ V_35 ] ;
T_1 V_3 = ( F_6 ( V_13 ) == V_36 ) ? 2 : 4 ;
return ! ! ( V_4 & V_3 ) ;
}
static int F_17 ( struct V_12 * V_13 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_1 V_16 = ( F_6 ( V_13 ) == V_36 ) ? 2 : 4 ;
return F_1 ( V_1 , V_35 , 0xff , V_16 ) ;
}
static int F_18 ( struct V_12 * V_13 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_1 V_3 = ( F_6 ( V_13 ) == V_36 ) ? ~ 2 : ~ 4 ;
return F_1 ( V_1 , V_35 , V_3 , 0 ) ;
}
static int F_19 ( struct V_12 * V_13 , unsigned V_17 )
{
if ( V_17 > V_37 )
return - V_19 ;
return V_38 + V_17 * V_39 ;
}
static int F_20 ( struct V_12 * V_13 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_1 V_40 = ( F_6 ( V_13 ) == V_36 ) ? 0 : 4 ;
T_1 V_17 = ( V_1 -> V_9 [ V_41 ] >> V_40 ) & 0xf ;
return V_38 + V_17 * V_39 ;
}
static int F_21 ( struct V_12 * V_13 , int V_24 ,
int V_25 , unsigned int * V_26 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_1 V_17 ;
int V_7 ;
if ( V_24 < V_38 || V_24 > V_42 )
return - V_19 ;
if ( V_25 < V_38 || V_25 > V_42 )
return - V_19 ;
V_17 = F_12 ( V_24 - V_38 ,
V_39 ) ;
V_7 = F_19 ( V_13 , V_17 ) ;
if ( V_7 < 0 || V_7 > V_25 )
return - V_19 ;
* V_26 = V_17 ;
if ( F_6 ( V_13 ) == V_36 )
return F_1 ( V_1 , V_41 , 0xf0 , V_17 ) ;
else
return F_1 ( V_1 , V_41 , 0x0f , V_17 << 4 ) ;
}
static int T_2 F_22 ( struct V_43 * V_10 ,
const struct V_44 * V_45 )
{
struct V_12 * * V_13 ;
struct V_46 * V_47 = V_10 -> V_11 . V_48 ;
struct V_1 * V_1 ;
int V_49 , V_50 , V_51 , V_7 = - V_19 ;
if ( V_47 -> V_52 > V_53 ) {
F_23 ( & V_10 -> V_11 , L_2 ) ;
goto V_54;
}
V_1 = F_24 ( sizeof( struct V_1 ) +
sizeof( struct V_12 * ) * V_53 ,
V_55 ) ;
if ( ! V_1 ) {
V_7 = - V_56 ;
goto V_54;
}
V_1 -> V_10 = V_10 ;
V_13 = V_1 -> V_13 ;
if ( V_47 -> V_57 ) {
V_1 -> V_9 [ V_14 ] = 5 ;
} else {
V_58 . V_59 = F_7 ;
V_58 . V_60 = F_8 ;
}
V_1 -> V_9 [ V_61 ] =
V_1 -> V_9 [ V_22 ] =
V_1 -> V_9 [ V_62 ] =
V_1 -> V_9 [ V_23 ] = 0x1b ;
V_1 -> V_9 [ V_63 ] =
V_1 -> V_9 [ V_33 ] = 0x04 ;
for ( V_50 = 0 ; V_50 < V_47 -> V_52 ; V_50 ++ ) {
if ( ! V_47 -> V_64 [ V_50 ] . V_48 )
goto V_65;
V_49 = V_47 -> V_64 [ V_50 ] . V_48 -> V_66 . V_49 ;
switch ( V_47 -> V_64 [ V_50 ] . V_51 ) {
case V_15 :
if ( V_49 )
V_1 -> V_9 [ V_14 ] |= 1 ;
break;
case V_67 :
if ( V_49 )
V_1 -> V_9 [ V_14 ] |= 4 ;
break;
case V_68 :
break;
case V_36 :
if ( V_49 )
V_1 -> V_9 [ V_35 ] |= 2 ;
break;
case V_69 :
if ( ! strcmp ( V_45 -> V_70 , L_3 ) ) {
F_23 ( & V_10 -> V_11 , L_4 ) ;
goto V_65;
}
if ( V_49 )
V_1 -> V_9 [ V_35 ] |= 4 ;
break;
default:
F_23 ( & V_10 -> V_11 , L_5 ,
V_47 -> V_64 [ V_50 ] . V_70 ) ;
goto V_65;
}
}
for ( V_50 = 0 ; V_50 < V_47 -> V_52 ; V_50 ++ ) {
V_51 = V_47 -> V_64 [ V_50 ] . V_51 ;
V_13 [ V_50 ] = F_25 ( & V_71 [ V_51 ] , & V_10 -> V_11 ,
V_47 -> V_64 [ V_50 ] . V_48 ,
V_1 , NULL ) ;
if ( F_26 ( V_13 [ V_50 ] ) ) {
V_7 = F_27 ( V_13 [ V_50 ] ) ;
F_23 ( & V_10 -> V_11 , L_6 ,
V_71 [ V_51 ] . V_70 ) ;
goto V_72;
}
}
F_28 ( V_10 , V_1 ) ;
F_29 ( & V_10 -> V_11 , L_7 ) ;
return 0 ;
V_72:
while ( -- V_50 >= 0 )
F_30 ( V_13 [ V_50 ] ) ;
V_65:
F_31 ( V_1 ) ;
V_54:
return V_7 ;
}
static int T_3 F_32 ( struct V_43 * V_10 )
{
struct V_1 * V_1 = F_33 ( V_10 ) ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_53 ; V_50 ++ )
if ( V_1 -> V_13 [ V_50 ] )
F_30 ( V_1 -> V_13 [ V_50 ] ) ;
F_31 ( V_1 ) ;
return 0 ;
}
static int T_4 F_34 ( void )
{
return F_35 ( & V_73 ) ;
}
static void T_5 F_36 ( void )
{
F_37 ( & V_73 ) ;
}
