int F_1 ( struct V_1 * V_1 )
{
T_1 V_2 = 0 , V_3 ;
T_2 * V_4 ;
if ( V_5 ) {
if ( V_5 == V_6 ) {
F_2 ( L_1 , V_7 . V_8 ) ;
goto V_9;
}
return - V_10 ;
}
F_3 ( V_11 , L_2 ) ;
for ( V_3 = 0 ; V_3 < F_4 ( V_12 ) ; V_3 ++ ) {
T_1 V_13 = V_12 [ V_3 ] [ 2 ] ;
if ( V_12 [ V_3 ] [ 0 ] == V_14 )
F_5 ( V_1 ,
V_12 [ V_3 ] [ 1 ] , & V_13 , 1 ) ;
else
F_6 ( V_1 , V_12 [ V_3 ] [ 1 ] , V_13 ) ;
}
if ( F_7 ( V_1 , V_15 , & V_2 , 1 ) )
return - V_10 ;
if ( V_2 == 0x30 ) {
F_2 ( L_3 ) ;
goto V_9;
}
return - V_10 ;
V_9:
V_4 = F_8 (
F_4 ( V_16 ) * sizeof( T_2 ) , V_17 ) ;
if ( ! V_4 )
return - V_18 ;
V_1 -> V_19 . V_20 . V_21 = V_22 ;
V_1 -> V_19 . V_20 . V_23 = F_4 ( V_22 ) ;
V_1 -> V_24 -> V_25 = V_16 ;
V_1 -> V_24 -> V_26 = F_4 ( V_16 ) ;
for ( V_3 = 0 ; V_3 < F_4 ( V_16 ) ; V_3 ++ )
V_4 [ V_3 ] = V_16 [ V_3 ] . V_27 . V_28 ;
V_1 -> V_29 = V_4 ;
return 0 ;
}
int F_9 ( struct V_1 * V_1 )
{
T_2 * V_4 = V_1 -> V_29 ;
int V_3 , V_30 = 0 ;
for ( V_3 = 0 ; V_3 < F_4 ( V_31 ) && ! V_30 ; V_3 ++ ) {
T_1 V_13 [ 2 ] = { 0x00 , 0x00 } ;
switch ( V_31 [ V_3 ] [ 0 ] ) {
case V_32 :
V_30 = F_6 ( V_1 ,
V_31 [ V_3 ] [ 1 ] ,
V_31 [ V_3 ] [ 2 ] ) ;
break;
case V_14 :
V_13 [ 0 ] = V_31 [ V_3 ] [ 2 ] ;
V_30 = F_5 ( V_1 ,
V_31 [ V_3 ] [ 1 ] , V_13 , 1 ) ;
break;
default:
F_2 ( L_4 ) ;
return - V_33 ;
}
}
if ( V_30 < 0 )
return V_30 ;
if ( V_34 )
F_10 ( V_1 ) ;
V_30 = F_11 ( & V_1 -> V_19 ,
V_4 [ V_35 ] ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_12 ( & V_1 -> V_19 , V_4 [ V_36 ] ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_13 ( & V_1 -> V_19 , V_4 [ V_37 ] ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_14 ( & V_1 -> V_19 , V_4 [ V_38 ] ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_15 ( & V_1 -> V_19 ,
V_4 [ V_39 ] ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_16 ( & V_1 -> V_19 ,
V_4 [ V_40 ] ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_17 ( & V_1 -> V_19 ,
V_4 [ V_41 ] ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_18 ( & V_1 -> V_19 ,
V_4 [ V_42 ] ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_19 ( & V_1 -> V_19 ,
V_4 [ V_43 ] ) ;
return V_30 ;
}
int F_20 ( struct V_1 * V_1 )
{
struct V_20 * V_20 = & V_1 -> V_19 . V_20 ;
int V_3 , V_30 = 0 ;
int V_44 = V_20 -> V_21 [ V_1 -> V_19 . V_45 ] . V_44 ;
int V_46 = V_20 -> V_21 [ V_1 -> V_19 . V_45 ] . V_46 ;
int V_47 = V_20 -> V_21 [ V_1 -> V_19 . V_45 ] . V_48 ;
T_1 V_13 ;
switch ( V_44 ) {
case 320 :
V_13 = V_49 ;
V_30 = F_5 ( V_1 , V_50 , & V_13 , 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_13 = ( ( V_44 + 3 ) >> 8 ) & 0xff ;
V_30 = F_5 ( V_1 , V_51 , & V_13 , 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_13 = ( V_44 + 3 ) & 0xff ;
V_30 = F_5 ( V_1 , V_52 , & V_13 , 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_13 = ( ( V_46 + 1 ) >> 8 ) & 0xff ;
V_30 = F_5 ( V_1 , V_53 , & V_13 , 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_13 = ( V_46 + 1 ) & 0xff ;
V_30 = F_5 ( V_1 , V_54 , & V_13 , 1 ) ;
V_46 += 6 ;
V_44 -= 1 ;
break;
case 640 :
V_13 = 0 ;
V_30 = F_5 ( V_1 , V_50 , & V_13 , 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_13 = ( ( V_44 + 7 ) >> 8 ) & 0xff ;
V_30 = F_5 ( V_1 , V_51 , & V_13 , 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_13 = ( V_44 + 7 ) & 0xff ;
V_30 = F_5 ( V_1 , V_52 , & V_13 , 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_13 = ( ( V_46 + 3 ) >> 8 ) & 0xff ;
V_30 = F_5 ( V_1 , V_53 , & V_13 , 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_13 = ( V_46 + 3 ) & 0xff ;
V_30 = F_5 ( V_1 , V_54 , & V_13 , 1 ) ;
V_46 += 12 ;
V_44 -= 2 ;
break;
}
V_30 = F_6 ( V_1 , V_55 , 0x0c ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_6 ( V_1 , V_56 , 0x81 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_6 ( V_1 , V_57 , 0x82 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_6 ( V_1 , V_58 , 0x01 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_6 ( V_1 , V_59 ,
( ( V_47 >> 8 ) & 0xff ) ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_6 ( V_1 , V_59 , ( V_47 & 0xff ) ) ;
if ( V_30 < 0 )
return V_30 ;
for ( V_3 = 0 ; V_3 < 2 && ! V_30 ; V_3 ++ )
V_30 = F_6 ( V_1 , V_59 , 0 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_6 ( V_1 , V_59 , ( V_46 >> 8 ) & 0xff ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_6 ( V_1 , V_59 , ( V_46 & 0xff ) ) ;
if ( V_30 < 0 )
return V_30 ;
for ( V_3 = 0 ; V_3 < 2 && ! V_30 ; V_3 ++ )
V_30 = F_6 ( V_1 , V_59 , 0 ) ;
for ( V_3 = 0 ; V_3 < 2 && ! V_30 ; V_3 ++ )
V_30 = F_6 ( V_1 , V_58 , 0 ) ;
for ( V_3 = 0 ; V_3 < 2 && ! V_30 ; V_3 ++ )
V_30 = F_6 ( V_1 , V_60 , 0 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_6 ( V_1 , V_60 , ( V_44 >> 8 ) & 0xff ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_6 ( V_1 , V_60 , ( V_44 & 0xff ) ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_6 ( V_1 , V_58 , 0 ) ;
return V_30 ;
}
static int F_21 ( struct V_19 * V_19 , T_3 * V_61 )
{
struct V_1 * V_1 = (struct V_1 * ) V_19 ;
T_2 * V_4 = V_1 -> V_29 ;
* V_61 = V_4 [ V_35 ] ;
F_3 ( V_62 , L_5 , * V_61 ) ;
return 0 ;
}
static int F_11 ( struct V_19 * V_19 , T_3 V_61 )
{
struct V_1 * V_1 = (struct V_1 * ) V_19 ;
T_2 * V_4 = V_1 -> V_29 ;
T_1 V_63 ;
int V_30 ;
V_4 [ V_35 ] = V_61 ;
F_3 ( V_62 , L_6 , V_61 & 0xffff ) ;
V_63 = ( ( V_61 & 0xff00 ) >> 8 ) ;
F_3 ( V_62 , L_7 ,
V_63 ) ;
V_30 = F_5 ( V_1 , V_64 ,
& V_63 , 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_63 = ( V_61 & 0xff ) ;
F_3 ( V_62 , L_8 ,
V_63 ) ;
V_30 = F_5 ( V_1 , V_65 ,
& V_63 , 1 ) ;
return V_30 ;
}
static int F_22 ( struct V_19 * V_19 , T_3 * V_61 )
{
struct V_1 * V_1 = (struct V_1 * ) V_19 ;
T_2 * V_4 = V_1 -> V_29 ;
* V_61 = V_4 [ V_36 ] ;
F_3 ( V_62 , L_9 , * V_61 ) ;
return 0 ;
}
static int F_12 ( struct V_19 * V_19 , T_3 V_61 )
{
struct V_1 * V_1 = (struct V_1 * ) V_19 ;
T_2 * V_4 = V_1 -> V_29 ;
T_1 V_63 ;
int V_30 ;
V_4 [ V_36 ] = V_61 ;
V_63 = V_61 & 0xff ;
F_3 ( V_62 , L_10 , V_63 ) ;
V_30 = F_5 ( V_1 , V_66 ,
& V_63 , 1 ) ;
return V_30 ;
}
static int F_23 ( struct V_19 * V_19 , T_3 * V_61 )
{
struct V_1 * V_1 = (struct V_1 * ) V_19 ;
T_2 * V_4 = V_1 -> V_29 ;
* V_61 = V_4 [ V_37 ] ;
F_3 ( V_62 , L_11 , * V_61 ) ;
return 0 ;
}
static int F_13 ( struct V_19 * V_19 , T_3 V_61 )
{
struct V_1 * V_1 = (struct V_1 * ) V_19 ;
T_2 * V_4 = V_1 -> V_29 ;
T_1 V_63 ;
int V_30 ;
V_4 [ V_37 ] = V_61 ;
F_3 ( V_62 , L_12 , V_61 ) ;
V_30 = F_7 ( V_1 , V_67 , & V_63 , 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_63 = ( 0x7f & V_63 ) | ( ( V_61 & 0x01 ) << 7 ) ;
V_30 = F_5 ( V_1 , V_67 ,
& V_63 , 1 ) ;
return V_30 ;
}
static int F_24 ( struct V_19 * V_19 , T_3 * V_61 )
{
struct V_1 * V_1 = (struct V_1 * ) V_19 ;
T_2 * V_4 = V_1 -> V_29 ;
* V_61 = V_4 [ V_38 ] ;
F_3 ( V_62 , L_13 , * V_61 ) ;
return 0 ;
}
static int F_14 ( struct V_19 * V_19 , T_3 V_61 )
{
struct V_1 * V_1 = (struct V_1 * ) V_19 ;
T_2 * V_4 = V_1 -> V_29 ;
T_1 V_63 ;
int V_30 ;
V_4 [ V_38 ] = V_61 ;
F_3 ( V_62 , L_14 , V_61 ) ;
V_30 = F_7 ( V_1 , V_67 , & V_63 , 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_63 = ( V_63 & 0xbf ) | ( ( V_61 & 0x01 ) << 6 ) ;
V_30 = F_5 ( V_1 , V_67 ,
& V_63 , 1 ) ;
return V_30 ;
}
static int F_25 ( struct V_19 * V_19 , T_3 * V_61 )
{
struct V_1 * V_1 = (struct V_1 * ) V_19 ;
T_2 * V_4 = V_1 -> V_29 ;
* V_61 = V_4 [ V_39 ] ;
F_3 ( V_62 , L_15 , * V_61 ) ;
return 0 ;
}
static int F_15 ( struct V_19 * V_19 , T_3 V_61 )
{
struct V_1 * V_1 = (struct V_1 * ) V_19 ;
T_2 * V_4 = V_1 -> V_29 ;
T_1 V_63 ;
int V_30 ;
V_4 [ V_39 ] = V_61 ;
V_63 = V_61 & 0xff ;
F_3 ( V_62 , L_16 , V_63 ) ;
V_30 = F_5 ( V_1 , V_68 ,
& V_63 , 1 ) ;
return V_30 ;
}
static int F_26 ( struct V_19 * V_19 , T_3 * V_61 )
{
struct V_1 * V_1 = (struct V_1 * ) V_19 ;
T_2 * V_4 = V_1 -> V_29 ;
* V_61 = V_4 [ V_40 ] ;
F_3 ( V_62 , L_17 , * V_61 ) ;
return 0 ;
}
static int F_16 ( struct V_19 * V_19 , T_3 V_61 )
{
struct V_1 * V_1 = (struct V_1 * ) V_19 ;
T_2 * V_4 = V_1 -> V_29 ;
T_1 V_63 ;
int V_30 ;
V_4 [ V_40 ] = V_61 ;
V_63 = V_61 & 0xff ;
F_3 ( V_62 , L_18 , V_63 ) ;
V_30 = F_5 ( V_1 , V_69 ,
& V_63 , 1 ) ;
return V_30 ;
}
static int F_27 ( struct V_19 * V_19 , T_3 * V_61 )
{
struct V_1 * V_1 = (struct V_1 * ) V_19 ;
T_2 * V_4 = V_1 -> V_29 ;
* V_61 = V_4 [ V_41 ] ;
F_3 ( V_62 , L_19 , * V_61 ) ;
return 0 ;
}
static int F_17 ( struct V_19 * V_19 , T_3 V_61 )
{
struct V_1 * V_1 = (struct V_1 * ) V_19 ;
T_2 * V_4 = V_1 -> V_29 ;
T_1 V_63 ;
int V_30 ;
V_4 [ V_41 ] = V_61 ;
V_63 = V_61 & 0xff ;
F_3 ( V_62 , L_20 , V_63 ) ;
V_30 = F_5 ( V_1 , V_70 ,
& V_63 , 1 ) ;
if ( V_30 < 0 )
return V_30 ;
return F_5 ( V_1 , V_71 ,
& V_63 , 1 ) ;
}
static int F_28 ( struct V_19 * V_19 ,
T_3 * V_61 )
{
struct V_1 * V_1 = (struct V_1 * ) V_19 ;
T_2 * V_4 = V_1 -> V_29 ;
* V_61 = V_4 [ V_42 ] ;
F_3 ( V_62 , L_21 , * V_61 ) ;
return 0 ;
}
static int F_18 ( struct V_19 * V_19 ,
T_3 V_61 )
{
struct V_1 * V_1 = (struct V_1 * ) V_19 ;
T_2 * V_4 = V_1 -> V_29 ;
T_1 V_63 ;
int V_30 ;
V_4 [ V_42 ] = V_61 ;
V_30 = F_7 ( V_1 , V_72 , & V_63 , 1 ) ;
if ( V_30 < 0 )
return V_30 ;
F_3 ( V_62 , L_22 , V_61 ) ;
V_63 = ( V_63 & 0xfe ) | ( V_61 & 0x01 ) ;
V_30 = F_5 ( V_1 , V_72 , & V_63 , 1 ) ;
return V_30 ;
}
static int F_29 ( struct V_19 * V_19 ,
T_3 * V_61 )
{
struct V_1 * V_1 = (struct V_1 * ) V_19 ;
T_2 * V_4 = V_1 -> V_29 ;
* V_61 = V_4 [ V_43 ] ;
F_3 ( V_62 , L_23 , * V_61 ) ;
return 0 ;
}
static int F_19 ( struct V_19 * V_19 ,
T_3 V_61 )
{
struct V_1 * V_1 = (struct V_1 * ) V_19 ;
T_2 * V_4 = V_1 -> V_29 ;
T_1 V_63 ;
int V_30 ;
V_4 [ V_43 ] = V_61 ;
V_30 = F_7 ( V_1 , V_72 , & V_63 , 1 ) ;
if ( V_30 < 0 )
return V_30 ;
F_3 ( V_62 , L_24 , V_61 ) ;
V_63 = ( V_63 & 0xfd ) | ( ( V_61 & 0x01 ) << 1 ) ;
return F_5 ( V_1 , V_72 , & V_63 , 1 ) ;
}
void F_30 ( struct V_1 * V_1 )
{
V_1 -> V_73 = NULL ;
F_31 ( V_1 -> V_29 ) ;
}
static void F_10 ( struct V_1 * V_1 )
{
int V_74 ;
T_1 V_75 = 0 ;
F_2 ( L_25 ) ;
for ( V_74 = 0 ; V_74 < 0x7f ; V_74 ++ ) {
F_7 ( V_1 , V_74 , & V_75 , 1 ) ;
F_2 ( L_26 , V_74 , V_75 ) ;
}
F_2 ( L_27 ) ;
F_2 ( L_28 ) ;
for ( V_74 = 0 ; V_74 < 0xff ; V_74 ++ ) {
T_1 V_76 , V_77 ;
T_1 V_78 [ 2 ] = { 0xff , 0xff } ;
F_7 ( V_1 , V_74 , & V_76 , 1 ) ;
F_5 ( V_1 , V_74 , V_78 , 1 ) ;
F_7 ( V_1 , V_74 , & V_77 , 1 ) ;
if ( V_77 == V_78 [ 0 ] )
F_2 ( L_29 , V_74 ) ;
else
F_2 ( L_30 , V_74 ) ;
F_5 ( V_1 , V_74 , & V_76 , 1 ) ;
}
}
