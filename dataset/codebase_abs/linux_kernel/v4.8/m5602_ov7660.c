int F_1 ( struct V_1 * V_1 )
{
int V_2 = 0 , V_3 ;
T_1 V_4 = 0 , V_5 = 0 ;
if ( V_6 ) {
if ( V_6 == V_7 ) {
F_2 ( L_1 , V_8 . V_9 ) ;
goto V_10;
}
return - V_11 ;
}
for ( V_3 = 0 ; V_3 < F_3 ( V_12 ) && ! V_2 ; V_3 ++ ) {
T_1 V_13 [ 2 ] ;
if ( V_12 [ V_3 ] [ 0 ] == V_14 ) {
V_2 = F_4 ( V_1 ,
V_12 [ V_3 ] [ 1 ] ,
V_12 [ V_3 ] [ 2 ] ) ;
} else {
V_13 [ 0 ] = V_12 [ V_3 ] [ 2 ] ;
V_2 = F_5 ( V_1 ,
V_12 [ V_3 ] [ 1 ] , V_13 , 1 ) ;
}
}
if ( V_2 < 0 )
return V_2 ;
if ( F_6 ( V_1 , V_15 , & V_4 , 1 ) )
return - V_11 ;
if ( F_6 ( V_1 , V_16 , & V_5 , 1 ) )
return - V_11 ;
F_2 ( L_2 , V_4 , V_5 ) ;
if ( ( V_4 == 0x76 ) && ( V_5 == 0x60 ) ) {
F_2 ( L_3 ) ;
goto V_10;
}
return - V_11 ;
V_10:
V_1 -> V_17 . V_18 . V_19 = V_20 ;
V_1 -> V_17 . V_18 . V_21 = F_3 ( V_20 ) ;
return 0 ;
}
int F_7 ( struct V_1 * V_1 )
{
int V_3 , V_2 ;
for ( V_3 = 0 ; V_3 < F_3 ( V_22 ) ; V_3 ++ ) {
T_1 V_13 [ 2 ] ;
if ( V_22 [ V_3 ] [ 0 ] == V_14 ) {
V_2 = F_4 ( V_1 ,
V_22 [ V_3 ] [ 1 ] ,
V_22 [ V_3 ] [ 2 ] ) ;
} else {
V_13 [ 0 ] = V_22 [ V_3 ] [ 2 ] ;
V_2 = F_5 ( V_1 ,
V_22 [ V_3 ] [ 1 ] , V_13 , 1 ) ;
}
if ( V_2 < 0 )
return V_2 ;
}
if ( V_23 )
F_8 ( V_1 ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_1 )
{
struct V_24 * V_25 = & V_1 -> V_17 . V_26 ;
V_1 -> V_17 . V_27 . V_26 = V_25 ;
F_10 ( V_25 , 6 ) ;
F_11 ( V_25 , & V_28 , V_29 ,
0 , 1 , 1 , 1 ) ;
F_12 ( V_25 , & V_28 ,
V_30 , 1 , 0 , V_31 ) ;
V_1 -> V_32 = F_11 ( V_25 , & V_28 ,
V_33 , 0 , 1 , 1 , 1 ) ;
V_1 -> V_34 = F_11 ( V_25 , & V_28 , V_35 , 0 ,
255 , 1 , V_36 ) ;
V_1 -> V_37 = F_11 ( V_25 , & V_28 , V_38 ,
0 , 1 , 1 , 0 ) ;
V_1 -> V_39 = F_11 ( V_25 , & V_28 , V_40 ,
0 , 1 , 1 , 0 ) ;
if ( V_25 -> error ) {
F_13 ( L_4 ) ;
return V_25 -> error ;
}
F_14 ( 2 , & V_1 -> V_32 , 0 , false ) ;
F_15 ( 2 , & V_1 -> V_37 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_1 )
{
return 0 ;
}
int F_17 ( struct V_1 * V_1 )
{
return 0 ;
}
void F_18 ( struct V_1 * V_1 )
{
F_17 ( V_1 ) ;
V_1 -> V_41 = NULL ;
}
static int F_19 ( struct V_17 * V_17 , T_2 V_42 )
{
int V_2 ;
T_1 V_43 = V_42 ;
struct V_1 * V_1 = (struct V_1 * ) V_17 ;
F_20 ( V_44 , L_5 , V_42 ) ;
V_2 = F_5 ( V_1 , V_45 , & V_43 , 1 ) ;
return V_2 ;
}
static int F_21 ( struct V_17 * V_17 ,
T_2 V_42 )
{
int V_2 ;
T_1 V_43 ;
struct V_1 * V_1 = (struct V_1 * ) V_17 ;
F_20 ( V_44 , L_6 , V_42 ) ;
V_2 = F_6 ( V_1 , V_46 , & V_43 , 1 ) ;
if ( V_2 < 0 )
return V_2 ;
V_43 = ( ( V_43 & 0xfd ) | ( ( V_42 & 0x01 ) << 1 ) ) ;
V_2 = F_5 ( V_1 , V_46 , & V_43 , 1 ) ;
return V_2 ;
}
static int F_22 ( struct V_17 * V_17 , T_2 V_42 )
{
int V_2 ;
T_1 V_43 ;
struct V_1 * V_1 = (struct V_1 * ) V_17 ;
F_20 ( V_44 , L_7 , V_42 ) ;
V_2 = F_6 ( V_1 , V_46 , & V_43 , 1 ) ;
if ( V_2 < 0 )
return V_2 ;
V_43 = ( ( V_43 & 0xfb ) | ( ( V_42 & 0x01 ) << 2 ) ) ;
return F_5 ( V_1 , V_46 , & V_43 , 1 ) ;
}
static int F_23 ( struct V_17 * V_17 ,
T_2 V_42 )
{
int V_2 ;
T_1 V_43 ;
struct V_1 * V_1 = (struct V_1 * ) V_17 ;
F_20 ( V_44 , L_8 , V_42 ) ;
V_2 = F_6 ( V_1 , V_46 , & V_43 , 1 ) ;
if ( V_2 < 0 )
return V_2 ;
V_42 = ( V_42 == V_31 ) ;
V_43 = ( ( V_43 & 0xfe ) | ( ( V_42 & 0x01 ) << 0 ) ) ;
return F_5 ( V_1 , V_46 , & V_43 , 1 ) ;
}
static int F_24 ( struct V_17 * V_17 )
{
int V_2 ;
T_1 V_43 ;
struct V_1 * V_1 = (struct V_1 * ) V_17 ;
F_20 ( V_44 , L_9 , V_1 -> V_37 -> V_42 , V_1 -> V_39 -> V_42 ) ;
V_43 = ( V_1 -> V_37 -> V_42 << 5 ) | ( V_1 -> V_39 -> V_42 << 4 ) ;
V_2 = F_5 ( V_1 , V_47 , & V_43 , 1 ) ;
return V_2 ;
}
static int F_25 ( struct V_48 * V_49 )
{
struct V_17 * V_17 =
F_26 ( V_49 -> V_50 , struct V_17 , V_26 ) ;
struct V_1 * V_1 = (struct V_1 * ) V_17 ;
int V_2 ;
if ( ! V_17 -> V_51 )
return 0 ;
switch ( V_49 -> V_52 ) {
case V_29 :
V_2 = F_21 ( V_17 , V_49 -> V_42 ) ;
break;
case V_30 :
V_2 = F_23 ( V_17 , V_49 -> V_42 ) ;
break;
case V_33 :
V_2 = F_22 ( V_17 , V_49 -> V_42 ) ;
if ( V_2 || V_49 -> V_42 )
return V_2 ;
V_2 = F_19 ( V_17 , V_1 -> V_34 -> V_42 ) ;
break;
case V_38 :
V_2 = F_24 ( V_17 ) ;
break;
default:
return - V_53 ;
}
return V_2 ;
}
static void F_8 ( struct V_1 * V_1 )
{
int V_54 ;
F_2 ( L_10 ) ;
for ( V_54 = 0 ; V_54 < 0xa9 ; V_54 ++ ) {
T_1 V_55 ;
F_6 ( V_1 , V_54 , & V_55 , 1 ) ;
F_2 ( L_11 , V_54 , V_55 ) ;
}
F_2 ( L_12 ) ;
F_2 ( L_13 ) ;
for ( V_54 = 0 ; V_54 < 0xff ; V_54 ++ ) {
T_1 V_56 , V_57 ;
T_1 V_58 [ 2 ] = { 0xff , 0xff } ;
F_6 ( V_1 , V_54 , & V_56 , 1 ) ;
F_5 ( V_1 , V_54 , V_58 , 1 ) ;
F_6 ( V_1 , V_54 , & V_57 , 1 ) ;
if ( V_57 == V_58 [ 0 ] )
F_2 ( L_14 , V_54 ) ;
else
F_2 ( L_15 , V_54 ) ;
F_5 ( V_1 , V_54 , & V_56 , 1 ) ;
}
}
