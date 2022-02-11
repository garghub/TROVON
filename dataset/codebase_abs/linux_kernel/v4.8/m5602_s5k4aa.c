int F_1 ( struct V_1 * V_1 )
{
T_1 V_2 [ 6 ] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
const T_1 V_3 [ 6 ] = { 0x00 , 0x10 , 0x00 , 0x4b , 0x33 , 0x75 } ;
struct V_4 * V_4 = (struct V_4 * ) V_1 ;
int V_5 , V_6 = 0 ;
if ( V_7 ) {
if ( V_7 == V_8 ) {
F_2 ( L_1 , V_9 . V_10 ) ;
goto V_11;
}
return - V_12 ;
}
F_3 ( V_13 , L_2 ) ;
for ( V_5 = 0 ; V_5 < F_4 ( V_14 ) && ! V_6 ; V_5 ++ ) {
T_1 V_15 [ 2 ] = { 0x00 , 0x00 } ;
switch ( V_14 [ V_5 ] [ 0 ] ) {
case V_16 :
V_6 = F_5 ( V_1 ,
V_14 [ V_5 ] [ 1 ] ,
V_14 [ V_5 ] [ 2 ] ) ;
break;
case V_17 :
V_15 [ 0 ] = V_14 [ V_5 ] [ 2 ] ;
V_6 = F_6 ( V_1 ,
V_14 [ V_5 ] [ 1 ] ,
V_15 , 1 ) ;
break;
case V_18 :
V_15 [ 0 ] = V_14 [ V_5 ] [ 2 ] ;
V_15 [ 1 ] = V_14 [ V_5 ] [ 3 ] ;
V_6 = F_6 ( V_1 ,
V_14 [ V_5 ] [ 1 ] ,
V_15 , 2 ) ;
break;
default:
F_2 ( L_3 ) ;
return - V_19 ;
}
}
if ( F_7 ( V_1 , 0x00 , V_2 , 2 ) )
return - V_12 ;
if ( F_7 ( V_1 , 0x02 , V_2 + 2 , 2 ) )
return - V_12 ;
if ( F_7 ( V_1 , 0x04 , V_2 + 4 , 2 ) )
return - V_12 ;
if ( memcmp ( V_2 , V_3 , sizeof( V_2 ) ) )
return - V_12 ;
else
F_2 ( L_4 ) ;
V_11:
V_1 -> V_4 . V_20 . V_21 = V_22 ;
V_1 -> V_4 . V_20 . V_23 = F_4 ( V_22 ) ;
return 0 ;
}
int F_8 ( struct V_1 * V_1 )
{
int V_5 , V_6 = 0 ;
T_1 V_15 [ 2 ] ;
struct V_20 * V_20 = & V_1 -> V_4 . V_20 ;
struct V_4 * V_4 = (struct V_4 * ) V_1 ;
switch ( V_20 -> V_21 [ V_1 -> V_4 . V_24 ] . V_25 ) {
case 1280 :
F_3 ( V_26 , L_5 ) ;
for ( V_5 = 0 ; V_5 < F_4 ( V_27 ) ; V_5 ++ ) {
switch ( V_27 [ V_5 ] [ 0 ] ) {
case V_16 :
V_6 = F_5 ( V_1 ,
V_27 [ V_5 ] [ 1 ] ,
V_27 [ V_5 ] [ 2 ] ) ;
break;
case V_17 :
V_15 [ 0 ] = V_27 [ V_5 ] [ 2 ] ;
V_6 = F_6 ( V_1 ,
V_27 [ V_5 ] [ 1 ] ,
V_15 , 1 ) ;
break;
case V_18 :
V_15 [ 0 ] = V_27 [ V_5 ] [ 2 ] ;
V_15 [ 1 ] = V_27 [ V_5 ] [ 3 ] ;
V_6 = F_6 ( V_1 ,
V_27 [ V_5 ] [ 1 ] ,
V_15 , 2 ) ;
break;
default:
F_9 ( L_3 ) ;
return - V_19 ;
}
}
break;
case 640 :
F_3 ( V_26 , L_6 ) ;
for ( V_5 = 0 ; V_5 < F_4 ( V_28 ) ; V_5 ++ ) {
switch ( V_28 [ V_5 ] [ 0 ] ) {
case V_16 :
V_6 = F_5 ( V_1 ,
V_28 [ V_5 ] [ 1 ] ,
V_28 [ V_5 ] [ 2 ] ) ;
break;
case V_17 :
V_15 [ 0 ] = V_28 [ V_5 ] [ 2 ] ;
V_6 = F_6 ( V_1 ,
V_28 [ V_5 ] [ 1 ] ,
V_15 , 1 ) ;
break;
case V_18 :
V_15 [ 0 ] = V_28 [ V_5 ] [ 2 ] ;
V_15 [ 1 ] = V_28 [ V_5 ] [ 3 ] ;
V_6 = F_6 ( V_1 ,
V_28 [ V_5 ] [ 1 ] ,
V_15 , 2 ) ;
break;
default:
F_9 ( L_3 ) ;
return - V_19 ;
}
}
break;
}
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
int F_10 ( struct V_1 * V_1 )
{
int V_5 , V_6 = 0 ;
for ( V_5 = 0 ; V_5 < F_4 ( V_29 ) && ! V_6 ; V_5 ++ ) {
T_1 V_15 [ 2 ] = { 0x00 , 0x00 } ;
switch ( V_29 [ V_5 ] [ 0 ] ) {
case V_16 :
V_6 = F_5 ( V_1 ,
V_29 [ V_5 ] [ 1 ] ,
V_29 [ V_5 ] [ 2 ] ) ;
break;
case V_17 :
V_15 [ 0 ] = V_29 [ V_5 ] [ 2 ] ;
V_6 = F_6 ( V_1 ,
V_29 [ V_5 ] [ 1 ] , V_15 , 1 ) ;
break;
case V_18 :
V_15 [ 0 ] = V_29 [ V_5 ] [ 2 ] ;
V_15 [ 1 ] = V_29 [ V_5 ] [ 3 ] ;
V_6 = F_6 ( V_1 ,
V_29 [ V_5 ] [ 1 ] , V_15 , 2 ) ;
break;
default:
F_2 ( L_3 ) ;
return - V_19 ;
}
}
if ( V_30 )
F_11 ( V_1 ) ;
return V_6 ;
}
int F_12 ( struct V_1 * V_1 )
{
struct V_31 * V_32 = & V_1 -> V_4 . V_33 ;
V_1 -> V_4 . V_34 . V_33 = V_32 ;
F_13 ( V_32 , 6 ) ;
F_14 ( V_32 , & V_35 , V_36 ,
0 , 0x1f , 1 , V_37 ) ;
F_14 ( V_32 , & V_35 , V_38 ,
13 , 0xfff , 1 , 0x100 ) ;
F_14 ( V_32 , & V_35 , V_39 ,
0 , 127 , 1 , V_40 ) ;
F_14 ( V_32 , & V_35 , V_41 ,
0 , 1 , 1 , 1 ) ;
V_1 -> V_42 = F_14 ( V_32 , & V_35 , V_43 ,
0 , 1 , 1 , 0 ) ;
V_1 -> V_44 = F_14 ( V_32 , & V_35 , V_45 ,
0 , 1 , 1 , 0 ) ;
if ( V_32 -> error ) {
F_9 ( L_7 ) ;
return V_32 -> error ;
}
F_15 ( 2 , & V_1 -> V_42 ) ;
return 0 ;
}
static int F_16 ( struct V_4 * V_4 , T_2 V_46 )
{
struct V_1 * V_1 = (struct V_1 * ) V_4 ;
T_1 V_15 = V_47 ;
int V_6 ;
F_3 ( V_26 , L_8 , V_46 ) ;
V_6 = F_6 ( V_1 , V_48 , & V_15 , 1 ) ;
if ( V_6 < 0 )
return V_6 ;
V_15 = ( V_46 >> 8 ) & 0xff ;
V_6 = F_6 ( V_1 , V_49 , & V_15 , 1 ) ;
if ( V_6 < 0 )
return V_6 ;
V_15 = V_46 & 0xff ;
V_6 = F_6 ( V_1 , V_50 , & V_15 , 1 ) ;
return V_6 ;
}
static int F_17 ( struct V_4 * V_4 )
{
struct V_1 * V_1 = (struct V_1 * ) V_4 ;
T_1 V_15 = V_47 ;
int V_6 ;
int V_42 = V_1 -> V_42 -> V_46 ;
int V_44 = V_1 -> V_44 -> V_46 ;
F_3 ( V_26 , L_9 , V_42 , V_44 ) ;
V_6 = F_6 ( V_1 , V_48 , & V_15 , 1 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_7 ( V_1 , V_51 , & V_15 , 1 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( F_18 ( V_52 ) ) {
V_42 = ! V_42 ;
V_44 = ! V_44 ;
}
V_15 = ( V_15 & 0x7f ) | ( V_44 << 7 ) | ( V_42 << 6 ) ;
V_6 = F_6 ( V_1 , V_51 , & V_15 , 1 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_7 ( V_1 , V_53 , & V_15 , 1 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_42 )
V_15 &= 0xfe ;
else
V_15 |= 0x01 ;
V_6 = F_6 ( V_1 , V_53 , & V_15 , 1 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_7 ( V_1 , V_54 , & V_15 , 1 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_44 )
V_15 &= 0xfe ;
else
V_15 |= 0x01 ;
V_6 = F_6 ( V_1 , V_54 , & V_15 , 1 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_19 ( struct V_4 * V_4 , T_2 V_46 )
{
struct V_1 * V_1 = (struct V_1 * ) V_4 ;
T_1 V_15 = V_47 ;
int V_6 ;
F_3 ( V_26 , L_10 , V_46 ) ;
V_6 = F_6 ( V_1 , V_48 , & V_15 , 1 ) ;
if ( V_6 < 0 )
return V_6 ;
V_15 = V_46 & 0xff ;
V_6 = F_6 ( V_1 , V_55 , & V_15 , 1 ) ;
return V_6 ;
}
static int F_20 ( struct V_4 * V_4 , T_2 V_46 )
{
struct V_1 * V_1 = (struct V_1 * ) V_4 ;
T_1 V_15 = V_47 ;
int V_6 ;
F_3 ( V_26 , L_11 , V_46 ) ;
V_6 = F_6 ( V_1 , V_48 , & V_15 , 1 ) ;
if ( V_6 < 0 )
return V_6 ;
V_15 = V_46 & 0xff ;
return F_6 ( V_1 , V_56 , & V_15 , 1 ) ;
}
static int F_21 ( struct V_4 * V_4 , T_2 V_46 )
{
struct V_1 * V_1 = (struct V_1 * ) V_4 ;
T_1 V_15 = V_47 ;
int V_6 ;
F_3 ( V_26 , L_12 , V_46 ) ;
V_6 = F_6 ( V_1 , V_48 , & V_15 , 1 ) ;
if ( V_6 < 0 )
return V_6 ;
V_15 = V_46 & 0x01 ;
return F_6 ( V_1 , V_57 , & V_15 , 1 ) ;
}
static int F_22 ( struct V_58 * V_59 )
{
struct V_4 * V_4 =
F_23 ( V_59 -> V_60 , struct V_4 , V_33 ) ;
int V_6 ;
if ( ! V_4 -> V_61 )
return 0 ;
switch ( V_59 -> V_62 ) {
case V_36 :
V_6 = F_20 ( V_4 , V_59 -> V_46 ) ;
break;
case V_38 :
V_6 = F_16 ( V_4 , V_59 -> V_46 ) ;
break;
case V_39 :
V_6 = F_19 ( V_4 , V_59 -> V_46 ) ;
break;
case V_41 :
V_6 = F_21 ( V_4 , V_59 -> V_46 ) ;
break;
case V_43 :
V_6 = F_17 ( V_4 ) ;
break;
default:
return - V_19 ;
}
return V_6 ;
}
void F_24 ( struct V_1 * V_1 )
{
V_1 -> V_63 = NULL ;
}
static void F_11 ( struct V_1 * V_1 )
{
int V_64 ;
T_1 V_65 , V_66 ;
F_7 ( V_1 , V_48 , & V_66 , 1 ) ;
for ( V_65 = 0 ; V_65 < 16 ; V_65 ++ ) {
F_6 ( V_1 , V_48 , & V_65 , 1 ) ;
F_2 ( L_13 ,
V_65 ) ;
for ( V_64 = 0 ; V_64 <= 0xff ; V_64 ++ ) {
T_1 V_67 = 0 ;
F_7 ( V_1 , V_64 , & V_67 , 1 ) ;
F_2 ( L_14 ,
V_64 , V_67 ) ;
}
}
F_2 ( L_15 ) ;
for ( V_65 = 0 ; V_65 < 16 ; V_65 ++ ) {
F_6 ( V_1 , V_48 , & V_65 , 1 ) ;
F_2 ( L_16 ,
V_65 ) ;
for ( V_64 = 0 ; V_64 <= 0xff ; V_64 ++ ) {
T_1 V_68 , V_69 , V_70 = 0xff ;
F_7 ( V_1 , V_64 , & V_68 , 1 ) ;
F_6 ( V_1 , V_64 , & V_70 , 1 ) ;
F_7 ( V_1 , V_64 , & V_69 , 1 ) ;
if ( V_69 == V_70 )
F_2 ( L_17 ,
V_64 ) ;
else
F_2 ( L_18 ,
V_64 ) ;
F_6 ( V_1 , V_64 , & V_68 , 1 ) ;
}
}
F_2 ( L_19 ) ;
F_6 ( V_1 , V_48 , & V_66 , 1 ) ;
}
