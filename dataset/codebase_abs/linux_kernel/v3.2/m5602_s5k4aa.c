int F_1 ( struct V_1 * V_1 )
{
T_1 V_2 [ 6 ] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
const T_1 V_3 [ 6 ] = { 0x00 , 0x10 , 0x00 , 0x4b , 0x33 , 0x75 } ;
int V_4 , V_5 = 0 ;
T_2 * V_6 ;
if ( V_7 ) {
if ( V_7 == V_8 ) {
F_2 ( L_1 , V_9 . V_10 ) ;
goto V_11;
}
return - V_12 ;
}
F_3 ( V_13 , L_2 ) ;
for ( V_4 = 0 ; V_4 < F_4 ( V_14 ) && ! V_5 ; V_4 ++ ) {
T_1 V_15 [ 2 ] = { 0x00 , 0x00 } ;
switch ( V_14 [ V_4 ] [ 0 ] ) {
case V_16 :
V_5 = F_5 ( V_1 ,
V_14 [ V_4 ] [ 1 ] ,
V_14 [ V_4 ] [ 2 ] ) ;
break;
case V_17 :
V_15 [ 0 ] = V_14 [ V_4 ] [ 2 ] ;
V_5 = F_6 ( V_1 ,
V_14 [ V_4 ] [ 1 ] ,
V_15 , 1 ) ;
break;
case V_18 :
V_15 [ 0 ] = V_14 [ V_4 ] [ 2 ] ;
V_15 [ 1 ] = V_14 [ V_4 ] [ 3 ] ;
V_5 = F_6 ( V_1 ,
V_14 [ V_4 ] [ 1 ] ,
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
V_6 = F_8 (
F_4 ( V_20 ) * sizeof( T_2 ) , V_21 ) ;
if ( ! V_6 )
return - V_22 ;
V_1 -> V_23 . V_24 . V_25 = V_26 ;
V_1 -> V_23 . V_24 . V_27 = F_4 ( V_26 ) ;
V_1 -> V_28 -> V_29 = V_20 ;
V_1 -> V_28 -> V_30 = F_4 ( V_20 ) ;
for ( V_4 = 0 ; V_4 < F_4 ( V_20 ) ; V_4 ++ )
V_6 [ V_4 ] = V_20 [ V_4 ] . V_31 . V_32 ;
V_1 -> V_33 = V_6 ;
return 0 ;
}
int F_9 ( struct V_1 * V_1 )
{
int V_4 , V_5 = 0 ;
T_1 V_15 [ 2 ] ;
struct V_24 * V_24 = & V_1 -> V_23 . V_24 ;
T_2 * V_6 = V_1 -> V_33 ;
switch ( V_24 -> V_25 [ V_1 -> V_23 . V_34 ] . V_35 ) {
case 1280 :
F_3 ( V_36 , L_5 ) ;
for ( V_4 = 0 ; V_4 < F_4 ( V_37 ) ; V_4 ++ ) {
switch ( V_37 [ V_4 ] [ 0 ] ) {
case V_16 :
V_5 = F_5 ( V_1 ,
V_37 [ V_4 ] [ 1 ] ,
V_37 [ V_4 ] [ 2 ] ) ;
break;
case V_17 :
V_15 [ 0 ] = V_37 [ V_4 ] [ 2 ] ;
V_5 = F_6 ( V_1 ,
V_37 [ V_4 ] [ 1 ] ,
V_15 , 1 ) ;
break;
case V_18 :
V_15 [ 0 ] = V_37 [ V_4 ] [ 2 ] ;
V_15 [ 1 ] = V_37 [ V_4 ] [ 3 ] ;
V_5 = F_6 ( V_1 ,
V_37 [ V_4 ] [ 1 ] ,
V_15 , 2 ) ;
break;
default:
F_10 ( L_3 ) ;
return - V_19 ;
}
}
V_5 = F_11 ( & V_1 -> V_23 , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
break;
case 640 :
F_3 ( V_36 , L_6 ) ;
for ( V_4 = 0 ; V_4 < F_4 ( V_38 ) ; V_4 ++ ) {
switch ( V_38 [ V_4 ] [ 0 ] ) {
case V_16 :
V_5 = F_5 ( V_1 ,
V_38 [ V_4 ] [ 1 ] ,
V_38 [ V_4 ] [ 2 ] ) ;
break;
case V_17 :
V_15 [ 0 ] = V_38 [ V_4 ] [ 2 ] ;
V_5 = F_6 ( V_1 ,
V_38 [ V_4 ] [ 1 ] ,
V_15 , 1 ) ;
break;
case V_18 :
V_15 [ 0 ] = V_38 [ V_4 ] [ 2 ] ;
V_15 [ 1 ] = V_38 [ V_4 ] [ 3 ] ;
V_5 = F_6 ( V_1 ,
V_38 [ V_4 ] [ 1 ] ,
V_15 , 2 ) ;
break;
default:
F_10 ( L_3 ) ;
return - V_19 ;
}
}
V_5 = F_11 ( & V_1 -> V_23 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
break;
}
if ( V_5 < 0 )
return V_5 ;
V_5 = F_12 ( & V_1 -> V_23 ,
V_6 [ V_39 ] ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_13 ( & V_1 -> V_23 , V_6 [ V_40 ] ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_14 ( & V_1 -> V_23 ,
V_6 [ V_41 ] ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_11 ( & V_1 -> V_23 , V_6 [ V_42 ] ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_15 ( & V_1 -> V_23 , V_6 [ V_43 ] ) ;
if ( V_5 < 0 )
return V_5 ;
return F_16 ( & V_1 -> V_23 , V_6 [ V_44 ] ) ;
}
int F_17 ( struct V_1 * V_1 )
{
int V_4 , V_5 = 0 ;
for ( V_4 = 0 ; V_4 < F_4 ( V_45 ) && ! V_5 ; V_4 ++ ) {
T_1 V_15 [ 2 ] = { 0x00 , 0x00 } ;
switch ( V_45 [ V_4 ] [ 0 ] ) {
case V_16 :
V_5 = F_5 ( V_1 ,
V_45 [ V_4 ] [ 1 ] ,
V_45 [ V_4 ] [ 2 ] ) ;
break;
case V_17 :
V_15 [ 0 ] = V_45 [ V_4 ] [ 2 ] ;
V_5 = F_6 ( V_1 ,
V_45 [ V_4 ] [ 1 ] , V_15 , 1 ) ;
break;
case V_18 :
V_15 [ 0 ] = V_45 [ V_4 ] [ 2 ] ;
V_15 [ 1 ] = V_45 [ V_4 ] [ 3 ] ;
V_5 = F_6 ( V_1 ,
V_45 [ V_4 ] [ 1 ] , V_15 , 2 ) ;
break;
default:
F_2 ( L_3 ) ;
return - V_19 ;
}
}
if ( V_46 )
F_18 ( V_1 ) ;
return V_5 ;
}
static int F_19 ( struct V_23 * V_23 , T_3 * V_47 )
{
struct V_1 * V_1 = (struct V_1 * ) V_23 ;
T_2 * V_6 = V_1 -> V_33 ;
* V_47 = V_6 [ V_39 ] ;
F_3 ( V_36 , L_7 , * V_47 ) ;
return 0 ;
}
static int F_12 ( struct V_23 * V_23 , T_3 V_47 )
{
struct V_1 * V_1 = (struct V_1 * ) V_23 ;
T_2 * V_6 = V_1 -> V_33 ;
T_1 V_15 = V_48 ;
int V_5 ;
V_6 [ V_39 ] = V_47 ;
F_3 ( V_36 , L_8 , V_47 ) ;
V_5 = F_6 ( V_1 , V_49 , & V_15 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_15 = ( V_47 >> 8 ) & 0xff ;
V_5 = F_6 ( V_1 , V_50 , & V_15 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_15 = V_47 & 0xff ;
V_5 = F_6 ( V_1 , V_51 , & V_15 , 1 ) ;
return V_5 ;
}
static int F_20 ( struct V_23 * V_23 , T_3 * V_47 )
{
struct V_1 * V_1 = (struct V_1 * ) V_23 ;
T_2 * V_6 = V_1 -> V_33 ;
* V_47 = V_6 [ V_43 ] ;
F_3 ( V_36 , L_9 , * V_47 ) ;
return 0 ;
}
static int F_15 ( struct V_23 * V_23 , T_3 V_47 )
{
struct V_1 * V_1 = (struct V_1 * ) V_23 ;
T_2 * V_6 = V_1 -> V_33 ;
T_1 V_15 = V_48 ;
int V_5 ;
V_6 [ V_43 ] = V_47 ;
F_3 ( V_36 , L_10 , V_47 ) ;
V_5 = F_6 ( V_1 , V_49 , & V_15 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_7 ( V_1 , V_52 , & V_15 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( F_21 ( V_53 ) )
V_47 = ! V_47 ;
V_15 = ( ( V_15 & ~ V_54 ) | ( ( V_47 & 0x01 ) << 7 ) ) ;
V_5 = F_6 ( V_1 , V_52 , & V_15 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_7 ( V_1 , V_55 , & V_15 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_47 )
V_15 &= 0xfe ;
else
V_15 |= 0x01 ;
V_5 = F_6 ( V_1 , V_55 , & V_15 , 1 ) ;
return V_5 ;
}
static int F_22 ( struct V_23 * V_23 , T_3 * V_47 )
{
struct V_1 * V_1 = (struct V_1 * ) V_23 ;
T_2 * V_6 = V_1 -> V_33 ;
* V_47 = V_6 [ V_44 ] ;
F_3 ( V_36 , L_11 , * V_47 ) ;
return 0 ;
}
static int F_16 ( struct V_23 * V_23 , T_3 V_47 )
{
struct V_1 * V_1 = (struct V_1 * ) V_23 ;
T_2 * V_6 = V_1 -> V_33 ;
T_1 V_15 = V_48 ;
int V_5 ;
V_6 [ V_44 ] = V_47 ;
F_3 ( V_36 , L_12 , V_47 ) ;
V_5 = F_6 ( V_1 , V_49 , & V_15 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_7 ( V_1 , V_52 , & V_15 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( F_21 ( V_53 ) )
V_47 = ! V_47 ;
V_15 = ( ( V_15 & ~ V_56 ) | ( ( V_47 & 0x01 ) << 6 ) ) ;
V_5 = F_6 ( V_1 , V_52 , & V_15 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_7 ( V_1 , V_57 , & V_15 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_47 )
V_15 &= 0xfe ;
else
V_15 |= 0x01 ;
V_5 = F_6 ( V_1 , V_57 , & V_15 , 1 ) ;
return V_5 ;
}
static int F_23 ( struct V_23 * V_23 , T_3 * V_47 )
{
struct V_1 * V_1 = (struct V_1 * ) V_23 ;
T_2 * V_6 = V_1 -> V_33 ;
* V_47 = V_6 [ V_40 ] ;
F_3 ( V_36 , L_13 , * V_47 ) ;
return 0 ;
}
static int F_13 ( struct V_23 * V_23 , T_3 V_47 )
{
struct V_1 * V_1 = (struct V_1 * ) V_23 ;
T_2 * V_6 = V_1 -> V_33 ;
T_1 V_15 = V_48 ;
int V_5 ;
V_6 [ V_40 ] = V_47 ;
F_3 ( V_36 , L_14 , V_47 ) ;
V_5 = F_6 ( V_1 , V_49 , & V_15 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_15 = V_47 & 0xff ;
V_5 = F_6 ( V_1 , V_58 , & V_15 , 1 ) ;
return V_5 ;
}
static int F_24 ( struct V_23 * V_23 , T_3 * V_47 )
{
struct V_1 * V_1 = (struct V_1 * ) V_23 ;
T_2 * V_6 = V_1 -> V_33 ;
* V_47 = V_6 [ V_41 ] ;
F_3 ( V_36 , L_15 , * V_47 ) ;
return 0 ;
}
static int F_14 ( struct V_23 * V_23 , T_3 V_47 )
{
struct V_1 * V_1 = (struct V_1 * ) V_23 ;
T_2 * V_6 = V_1 -> V_33 ;
T_1 V_15 = V_48 ;
int V_5 ;
V_6 [ V_41 ] = V_47 ;
F_3 ( V_36 , L_16 , V_47 ) ;
V_5 = F_6 ( V_1 , V_49 , & V_15 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_15 = V_47 & 0xff ;
return F_6 ( V_1 , V_59 , & V_15 , 1 ) ;
}
static int F_25 ( struct V_23 * V_23 , T_3 * V_47 )
{
struct V_1 * V_1 = (struct V_1 * ) V_23 ;
T_2 * V_6 = V_1 -> V_33 ;
* V_47 = V_6 [ V_42 ] ;
F_3 ( V_36 , L_17 , * V_47 ) ;
return 0 ;
}
static int F_11 ( struct V_23 * V_23 , T_3 V_47 )
{
struct V_1 * V_1 = (struct V_1 * ) V_23 ;
T_2 * V_6 = V_1 -> V_33 ;
T_1 V_15 = V_48 ;
int V_5 ;
V_6 [ V_42 ] = V_47 ;
F_3 ( V_36 , L_18 , V_47 ) ;
V_5 = F_6 ( V_1 , V_49 , & V_15 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_15 = V_47 & 0x01 ;
return F_6 ( V_1 , V_60 , & V_15 , 1 ) ;
}
void F_26 ( struct V_1 * V_1 )
{
V_1 -> V_61 = NULL ;
F_27 ( V_1 -> V_33 ) ;
}
static void F_18 ( struct V_1 * V_1 )
{
int V_62 ;
T_1 V_63 , V_64 ;
F_7 ( V_1 , V_49 , & V_64 , 1 ) ;
for ( V_63 = 0 ; V_63 < 16 ; V_63 ++ ) {
F_6 ( V_1 , V_49 , & V_63 , 1 ) ;
F_2 ( L_19 ,
V_63 ) ;
for ( V_62 = 0 ; V_62 <= 0xff ; V_62 ++ ) {
T_1 V_65 = 0 ;
F_7 ( V_1 , V_62 , & V_65 , 1 ) ;
F_2 ( L_20 ,
V_62 , V_65 ) ;
}
}
F_2 ( L_21 ) ;
for ( V_63 = 0 ; V_63 < 16 ; V_63 ++ ) {
F_6 ( V_1 , V_49 , & V_63 , 1 ) ;
F_2 ( L_22 ,
V_63 ) ;
for ( V_62 = 0 ; V_62 <= 0xff ; V_62 ++ ) {
T_1 V_66 , V_67 , V_68 = 0xff ;
F_7 ( V_1 , V_62 , & V_66 , 1 ) ;
F_6 ( V_1 , V_62 , & V_68 , 1 ) ;
F_7 ( V_1 , V_62 , & V_67 , 1 ) ;
if ( V_67 == V_68 )
F_2 ( L_23 ,
V_62 ) ;
else
F_2 ( L_24 ,
V_62 ) ;
F_6 ( V_1 , V_62 , & V_66 , 1 ) ;
}
}
F_2 ( L_25 ) ;
F_6 ( V_1 , V_49 , & V_64 , 1 ) ;
}
