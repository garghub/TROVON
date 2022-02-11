static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int * V_4 )
{
return F_2 ( V_2 -> V_5 , V_3 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
return F_4 ( V_2 -> V_5 , V_3 , V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_6 , unsigned int V_4 )
{
return F_6 ( V_2 -> V_5 , V_3 , V_6 , V_4 ) ;
}
static int F_7 ( struct V_7 * V_8 )
{
int V_9 ;
unsigned int V_10 ;
enum V_11 V_12 = F_8 ( V_8 ) ;
struct V_1 * V_2 = F_9 ( V_8 ) ;
V_9 = F_1 ( V_2 , 0x12 + V_12 , & V_10 ) ;
if ( V_9 < 0 ) {
F_10 ( V_2 -> V_13 , L_1 , V_14 ) ;
return V_9 ;
}
return ( V_10 & 0xff ) * 100 ;
}
static int F_11 ( struct V_7 * V_8 , unsigned int V_15 )
{
int V_9 ;
unsigned int V_16 = 0x0 ;
enum V_11 V_12 = F_8 ( V_8 ) ;
struct V_1 * V_2 = F_9 ( V_8 ) ;
switch ( V_15 ) {
case V_17 :
V_16 = ( 0x01 << V_12 ) ;
break;
case V_18 :
V_9 = F_5 ( V_2 , 0x08 + V_12 , 0x20 , 0x00 ) ;
if ( V_9 < 0 )
goto V_19;
break;
case V_20 :
V_9 = F_5 ( V_2 , 0x08 + V_12 , 0x20 , 0x20 ) ;
if ( V_9 < 0 )
goto V_19;
V_9 = F_5 ( V_2 , 0x10 , 0x01 , 0x01 ) ;
if ( V_9 < 0 )
goto V_19;
break;
default:
F_10 ( V_2 -> V_13 , L_2 , V_14 ) ;
V_16 = ( 0x01 << V_12 ) ;
}
V_9 = F_5 ( V_2 , 0x06 , 0x01 << V_12 , V_16 ) ;
if ( V_9 < 0 )
goto V_19;
return V_9 ;
V_19:
F_10 ( V_2 -> V_13 , L_1 , V_14 ) ;
return V_9 ;
}
static unsigned int F_12 ( struct V_7 * V_8 )
{
int V_9 ;
unsigned int V_10 ;
enum V_11 V_12 = F_8 ( V_8 ) ;
struct V_1 * V_2 = F_9 ( V_8 ) ;
V_9 = F_1 ( V_2 , 0x06 , & V_10 ) ;
if ( V_9 < 0 )
goto V_19;
if ( V_10 & ( 0x01 << V_12 ) )
return V_17 ;
V_9 = F_1 ( V_2 , 0x08 + V_12 , & V_10 ) ;
if ( V_9 < 0 )
goto V_19;
if ( V_10 & 0x20 )
return V_20 ;
return V_18 ;
V_19:
F_10 ( V_2 -> V_13 , L_1 , V_14 ) ;
return 0 ;
}
static int F_13 ( struct V_7 * V_8 , int V_21 )
{
int V_9 ;
unsigned int V_10 = 0x00 ;
enum V_11 V_12 = F_8 ( V_8 ) ;
struct V_1 * V_2 = F_9 ( V_8 ) ;
switch ( V_21 ) {
case 0 ... 230 :
V_10 = 0x07 ;
break;
case 231 ... 470 :
V_10 = 0x06 ;
break;
case 471 ... 940 :
V_10 = 0x05 ;
break;
case 941 ... 1900 :
V_10 = 0x04 ;
break;
case 1901 ... 3800 :
V_10 = 0x03 ;
break;
case 3801 ... 7500 :
V_10 = 0x02 ;
break;
case 7501 ... 15000 :
V_10 = 0x01 ;
break;
case 15001 ... 30000 :
V_10 = 0x00 ;
break;
default:
F_10 ( V_2 -> V_13 ,
L_3 , V_21 , V_14 ) ;
return - V_22 ;
}
V_9 = F_5 ( V_2 , 0x07 + V_12 , 0x07 , V_10 ) ;
if ( V_9 < 0 )
goto V_19;
return V_9 ;
V_19:
F_10 ( V_2 -> V_13 , L_1 , V_14 ) ;
return V_9 ;
}
static int F_14 ( struct V_1 * V_2 )
{
unsigned int V_10 ;
int V_9 , V_23 , V_24 ;
struct V_25 * V_26 = V_2 -> V_26 ;
V_9 = F_1 ( V_2 , 0x3D , & V_10 ) ;
if ( V_9 < 0 )
goto V_27;
V_2 -> V_28 = V_10 & 0x0F ;
for ( V_23 = 0 ; V_23 < V_29 [ V_2 -> V_28 ] . V_30 ; V_23 ++ ) {
V_24 = V_29 [ V_2 -> V_28 ] . V_24 [ V_23 ] ;
V_26 -> V_31 [ V_24 ] = & V_32 [ V_24 ] ;
}
return V_9 ;
V_27:
F_10 ( V_2 -> V_13 , L_1 , V_14 ) ;
return V_9 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_9 , V_23 , V_24 ;
struct V_25 * V_26 = V_2 -> V_26 ;
struct V_33 V_34 = { } ;
V_34 . V_5 = V_2 -> V_5 ;
V_34 . V_13 = V_2 -> V_13 ;
V_34 . V_35 = V_2 ;
for ( V_23 = 0 ; V_23 < V_29 [ V_2 -> V_28 ] . V_30 ; V_23 ++ ) {
V_24 = V_29 [ V_2 -> V_28 ] . V_24 [ V_23 ] ;
V_34 . V_36 = V_26 -> V_31 [ V_24 ] ;
V_34 . V_37 = V_2 -> V_13 -> V_37 ;
V_2 -> V_8 [ V_24 ] =
F_16 ( & V_38 [ V_24 ] , & V_34 ) ;
if ( F_17 ( V_2 -> V_8 [ V_24 ] ) ) {
V_9 = F_18 ( V_2 -> V_8 [ V_24 ] ) ;
V_2 -> V_8 [ V_24 ] = NULL ;
F_10 ( V_2 -> V_13 , L_4 ,
V_24 ) ;
goto V_39;
}
}
return 0 ;
V_39:
for ( V_23 = 0 ; V_23 < V_40 ; V_23 ++ )
F_19 ( V_2 -> V_8 [ V_23 ] ) ;
return V_9 ;
}
static T_1 F_20 ( int V_41 , void * V_42 )
{
int V_9 , V_23 ;
unsigned int V_43 , V_44 ;
struct V_1 * V_2 = V_42 ;
V_9 = F_1 ( V_2 , 0x0D , & V_43 ) ;
if ( V_9 < 0 )
goto V_19;
V_9 = F_3 ( V_2 , 0x0D , 0x00 ) ;
if ( V_9 < 0 )
goto V_19;
for ( V_23 = 0 ; V_23 < V_40 ; V_23 ++ )
if ( ( V_43 & ( 0x4 << V_23 ) )
&& ( V_2 -> V_45 & ( 0x04 << V_23 ) )
&& ( V_2 -> V_8 [ V_23 ] != NULL ) )
F_21 ( V_2 -> V_8 [ V_23 ] ,
V_46 ,
NULL ) ;
V_9 = F_1 ( V_2 , 0x0E , & V_44 ) ;
if ( V_9 < 0 )
goto V_19;
V_9 = F_3 ( V_2 , 0x0E , 0x00 ) ;
if ( V_9 < 0 )
goto V_19;
if ( ( V_44 & 0x01 ) && ( V_2 -> V_45 & 0x01 ) )
for ( V_23 = 0 ; V_23 < V_40 ; V_23 ++ )
if ( V_2 -> V_8 [ V_23 ] != NULL )
F_21 ( V_2 -> V_8 [ V_23 ] ,
V_47 ,
NULL ) ;
if ( ( V_44 & 0x02 ) && ( V_2 -> V_45 & 0x02 ) )
for ( V_23 = 0 ; V_23 < V_40 ; V_23 ++ )
if ( V_2 -> V_8 [ V_23 ] != NULL )
F_21 ( V_2 -> V_8 [ V_23 ] ,
V_48 ,
NULL ) ;
return V_49 ;
V_19:
F_10 ( V_2 -> V_13 , L_1 , V_14 ) ;
return V_50 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_9 ;
unsigned int V_10 ;
if ( V_2 -> V_41 == 0 ) {
F_23 ( V_2 -> V_13 , L_5 , V_14 ) ;
return 0 ;
}
V_9 = F_1 ( V_2 , 0x0F , & V_10 ) ;
if ( V_9 < 0 )
goto V_19;
V_2 -> V_45 = V_10 ;
V_9 = F_24 ( V_2 -> V_41 , NULL , F_20 ,
V_51 | V_52 ,
L_6 , V_2 ) ;
if ( V_9 )
return V_9 ;
return V_9 ;
V_19:
F_10 ( V_2 -> V_13 , L_1 , V_14 ) ;
return V_9 ;
}
static int F_25 ( struct V_53 * V_54 ,
const struct V_55 * V_12 )
{
int V_9 , V_23 ;
struct V_1 * V_2 ;
struct V_25 * V_26 = F_26 ( & V_54 -> V_13 ) ;
if ( ! F_27 ( V_54 -> V_56 , V_57 ) ) {
F_10 ( & V_54 -> V_13 , L_7 ) ;
return - V_58 ;
}
V_2 = F_28 ( & V_54 -> V_13 ,
sizeof( struct V_1 ) , V_59 ) ;
if ( ! V_2 )
return - V_60 ;
V_2 -> V_13 = & V_54 -> V_13 ;
V_2 -> V_5 = F_29 ( V_54 , & V_61 ) ;
if ( F_17 ( V_2 -> V_5 ) ) {
V_9 = F_18 ( V_2 -> V_5 ) ;
F_10 ( & V_54 -> V_13 , L_8 , V_9 ) ;
return V_9 ;
}
F_30 ( V_54 , V_2 ) ;
if ( V_26 != NULL ) {
V_2 -> V_26 = V_26 ;
V_2 -> V_28 = V_26 -> V_28 ;
} else {
V_2 -> V_26 = F_28 ( V_2 -> V_13 ,
sizeof( struct V_25 ) ,
V_59 ) ;
if ( ! V_2 -> V_26 )
return - V_60 ;
V_9 = F_14 ( V_2 ) ;
if ( V_9 < 0 ) {
F_10 ( & V_54 -> V_13 , L_9 ) ;
return V_9 ;
}
}
V_9 = F_15 ( V_2 ) ;
if ( V_9 < 0 ) {
F_10 ( & V_54 -> V_13 , L_10 ) ;
goto V_62;
}
V_2 -> V_41 = V_54 -> V_41 ;
V_9 = F_22 ( V_2 ) ;
if ( V_9 < 0 ) {
F_10 ( & V_54 -> V_13 , L_11 ) ;
goto V_63;
}
return V_9 ;
V_63:
for ( V_23 = 0 ; V_23 < V_29 [ V_2 -> V_28 ] . V_30 ; V_23 ++ )
F_19 ( V_2 -> V_8 [ V_23 ] ) ;
V_62:
for ( V_23 = 0 ; V_23 < V_40 ; V_23 ++ )
F_3 ( V_2 , V_23 , 0x00 ) ;
return V_9 ;
}
static int F_31 ( struct V_53 * V_54 )
{
int V_23 ;
struct V_1 * V_2 = F_32 ( V_54 ) ;
for ( V_23 = 0 ; V_23 < V_29 [ V_2 -> V_28 ] . V_30 ; V_23 ++ )
F_19 ( V_2 -> V_8 [ V_23 ] ) ;
for ( V_23 = 0 ; V_23 < V_40 ; V_23 ++ )
F_3 ( V_2 , V_23 , 0x00 ) ;
if ( V_2 -> V_41 != 0 )
F_33 ( V_2 -> V_41 , V_2 ) ;
return 0 ;
}
static int T_2 F_34 ( void )
{
return F_35 ( & V_64 ) ;
}
static void T_3 F_36 ( void )
{
F_37 ( & V_64 ) ;
}
