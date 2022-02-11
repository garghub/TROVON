int F_1 ( struct V_1 * V_1 )
{
T_1 V_2 = 0 , V_3 ;
struct V_4 * V_4 = (struct V_4 * ) V_1 ;
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
V_1 -> V_4 . V_16 . V_17 = V_18 ;
V_1 -> V_4 . V_16 . V_19 = F_4 ( V_18 ) ;
return 0 ;
}
int F_8 ( struct V_1 * V_1 )
{
int V_3 , V_20 = 0 ;
for ( V_3 = 0 ; V_3 < F_4 ( V_21 ) && ! V_20 ; V_3 ++ ) {
T_1 V_13 [ 2 ] = { 0x00 , 0x00 } ;
switch ( V_21 [ V_3 ] [ 0 ] ) {
case V_22 :
V_20 = F_6 ( V_1 ,
V_21 [ V_3 ] [ 1 ] ,
V_21 [ V_3 ] [ 2 ] ) ;
break;
case V_14 :
V_13 [ 0 ] = V_21 [ V_3 ] [ 2 ] ;
V_20 = F_5 ( V_1 ,
V_21 [ V_3 ] [ 1 ] , V_13 , 1 ) ;
break;
default:
F_2 ( L_4 ) ;
return - V_23 ;
}
}
if ( V_20 < 0 )
return V_20 ;
if ( V_24 )
F_9 ( V_1 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_1 )
{
struct V_25 * V_26 = & V_1 -> V_4 . V_27 ;
V_1 -> V_4 . V_28 . V_27 = V_26 ;
F_11 ( V_26 , 9 ) ;
V_1 -> V_29 = F_12 ( V_26 , & V_30 ,
V_31 ,
0 , 1 , 1 , 0 ) ;
V_1 -> V_32 = F_13 ( V_26 , & V_33 , NULL ) ;
V_1 -> V_34 = F_12 ( V_26 , & V_30 ,
V_35 , 0 , 255 , 1 ,
V_36 ) ;
V_1 -> V_37 = F_12 ( V_26 , & V_30 ,
V_38 , 0 , 255 , 1 ,
V_39 ) ;
V_1 -> V_40 = F_14 ( V_26 , & V_30 ,
V_41 , 1 , 0 , V_42 ) ;
V_1 -> V_43 = F_12 ( V_26 , & V_30 , V_44 ,
0 , 0x2ff , 1 , V_45 ) ;
V_1 -> V_46 = F_12 ( V_26 , & V_30 , V_47 , 0 ,
0x4f , 1 , V_48 ) ;
V_1 -> V_49 = F_12 ( V_26 , & V_30 , V_50 ,
0 , 1 , 1 , 0 ) ;
V_1 -> V_51 = F_12 ( V_26 , & V_30 , V_52 ,
0 , 1 , 1 , 0 ) ;
if ( V_26 -> error ) {
F_15 ( L_5 ) ;
return V_26 -> error ;
}
F_16 ( 4 , & V_1 -> V_29 , 0 , false ) ;
F_16 ( 2 , & V_1 -> V_40 , 0 , false ) ;
F_17 ( 2 , & V_1 -> V_49 ) ;
return 0 ;
}
int F_18 ( struct V_1 * V_1 )
{
struct V_16 * V_16 = & V_1 -> V_4 . V_16 ;
int V_3 , V_20 = 0 ;
int V_53 = V_16 -> V_17 [ V_1 -> V_4 . V_54 ] . V_53 ;
int V_55 = V_16 -> V_17 [ V_1 -> V_4 . V_54 ] . V_55 ;
int V_56 = V_16 -> V_17 [ V_1 -> V_4 . V_54 ] . V_57 ;
T_1 V_13 ;
switch ( V_53 ) {
case 320 :
V_13 = V_58 ;
V_20 = F_5 ( V_1 , V_59 , & V_13 , 1 ) ;
if ( V_20 < 0 )
return V_20 ;
V_13 = ( ( V_53 + 3 ) >> 8 ) & 0xff ;
V_20 = F_5 ( V_1 , V_60 , & V_13 , 1 ) ;
if ( V_20 < 0 )
return V_20 ;
V_13 = ( V_53 + 3 ) & 0xff ;
V_20 = F_5 ( V_1 , V_61 , & V_13 , 1 ) ;
if ( V_20 < 0 )
return V_20 ;
V_13 = ( ( V_55 + 1 ) >> 8 ) & 0xff ;
V_20 = F_5 ( V_1 , V_62 , & V_13 , 1 ) ;
if ( V_20 < 0 )
return V_20 ;
V_13 = ( V_55 + 1 ) & 0xff ;
V_20 = F_5 ( V_1 , V_63 , & V_13 , 1 ) ;
V_55 += 6 ;
V_53 -= 1 ;
break;
case 640 :
V_13 = 0 ;
V_20 = F_5 ( V_1 , V_59 , & V_13 , 1 ) ;
if ( V_20 < 0 )
return V_20 ;
V_13 = ( ( V_53 + 7 ) >> 8 ) & 0xff ;
V_20 = F_5 ( V_1 , V_60 , & V_13 , 1 ) ;
if ( V_20 < 0 )
return V_20 ;
V_13 = ( V_53 + 7 ) & 0xff ;
V_20 = F_5 ( V_1 , V_61 , & V_13 , 1 ) ;
if ( V_20 < 0 )
return V_20 ;
V_13 = ( ( V_55 + 3 ) >> 8 ) & 0xff ;
V_20 = F_5 ( V_1 , V_62 , & V_13 , 1 ) ;
if ( V_20 < 0 )
return V_20 ;
V_13 = ( V_55 + 3 ) & 0xff ;
V_20 = F_5 ( V_1 , V_63 , & V_13 , 1 ) ;
V_55 += 12 ;
V_53 -= 2 ;
break;
}
V_20 = F_6 ( V_1 , V_64 , 0x0c ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_6 ( V_1 , V_65 , 0x81 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_6 ( V_1 , V_66 , 0x82 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_6 ( V_1 , V_67 , 0x01 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_6 ( V_1 , V_68 ,
( ( V_56 >> 8 ) & 0xff ) ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_6 ( V_1 , V_68 , ( V_56 & 0xff ) ) ;
if ( V_20 < 0 )
return V_20 ;
for ( V_3 = 0 ; V_3 < 2 && ! V_20 ; V_3 ++ )
V_20 = F_6 ( V_1 , V_68 , 0 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_6 ( V_1 , V_68 , ( V_55 >> 8 ) & 0xff ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_6 ( V_1 , V_68 , ( V_55 & 0xff ) ) ;
if ( V_20 < 0 )
return V_20 ;
for ( V_3 = 0 ; V_3 < 2 && ! V_20 ; V_3 ++ )
V_20 = F_6 ( V_1 , V_68 , 0 ) ;
for ( V_3 = 0 ; V_3 < 2 && ! V_20 ; V_3 ++ )
V_20 = F_6 ( V_1 , V_67 , 0 ) ;
for ( V_3 = 0 ; V_3 < 2 && ! V_20 ; V_3 ++ )
V_20 = F_6 ( V_1 , V_69 , 0 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_6 ( V_1 , V_69 , ( V_53 >> 8 ) & 0xff ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_6 ( V_1 , V_69 , ( V_53 & 0xff ) ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_6 ( V_1 , V_67 , 0 ) ;
return V_20 ;
}
static int F_19 ( struct V_4 * V_4 , T_2 V_70 )
{
struct V_1 * V_1 = (struct V_1 * ) V_4 ;
T_1 V_71 ;
int V_20 ;
F_3 ( V_72 , L_6 , V_70 & 0xffff ) ;
V_71 = ( ( V_70 & 0xff00 ) >> 8 ) ;
F_3 ( V_72 , L_7 ,
V_71 ) ;
V_20 = F_5 ( V_1 , V_73 ,
& V_71 , 1 ) ;
if ( V_20 < 0 )
return V_20 ;
V_71 = ( V_70 & 0xff ) ;
F_3 ( V_72 , L_8 ,
V_71 ) ;
V_20 = F_5 ( V_1 , V_74 ,
& V_71 , 1 ) ;
return V_20 ;
}
static int F_20 ( struct V_4 * V_4 , T_2 V_70 )
{
struct V_1 * V_1 = (struct V_1 * ) V_4 ;
T_1 V_71 ;
int V_20 ;
V_71 = V_70 & 0xff ;
F_3 ( V_72 , L_9 , V_71 ) ;
V_20 = F_5 ( V_1 , V_75 ,
& V_71 , 1 ) ;
return V_20 ;
}
static int F_21 ( struct V_4 * V_4 )
{
struct V_1 * V_1 = (struct V_1 * ) V_4 ;
T_1 V_71 ;
int V_20 ;
F_3 ( V_72 , L_10 , V_1 -> V_49 -> V_70 , V_1 -> V_51 -> V_70 ) ;
V_20 = F_7 ( V_1 , V_76 , & V_71 , 1 ) ;
if ( V_20 < 0 )
return V_20 ;
V_71 = ( 0x3f & V_71 ) | ( V_1 -> V_49 -> V_70 << 7 ) |
( V_1 -> V_51 -> V_70 << 6 ) ;
V_20 = F_5 ( V_1 , V_76 ,
& V_71 , 1 ) ;
return V_20 ;
}
static int F_22 ( struct V_4 * V_4 , T_2 V_70 )
{
struct V_1 * V_1 = (struct V_1 * ) V_4 ;
T_1 V_71 ;
int V_20 ;
V_71 = V_70 & 0xff ;
F_3 ( V_72 , L_11 , V_71 ) ;
V_20 = F_5 ( V_1 , V_77 ,
& V_71 , 1 ) ;
return V_20 ;
}
static int F_23 ( struct V_4 * V_4 , T_2 V_70 )
{
struct V_1 * V_1 = (struct V_1 * ) V_4 ;
T_1 V_71 ;
int V_20 ;
V_71 = V_70 & 0xff ;
F_3 ( V_72 , L_12 , V_71 ) ;
V_20 = F_5 ( V_1 , V_78 ,
& V_71 , 1 ) ;
return V_20 ;
}
static int F_24 ( struct V_4 * V_4 , T_2 V_70 )
{
struct V_1 * V_1 = (struct V_1 * ) V_4 ;
T_1 V_71 ;
int V_20 ;
V_71 = V_70 & 0xff ;
F_3 ( V_72 , L_13 , V_71 ) ;
V_20 = F_5 ( V_1 , V_79 ,
& V_71 , 1 ) ;
if ( V_20 < 0 )
return V_20 ;
return F_5 ( V_1 , V_80 ,
& V_71 , 1 ) ;
}
static int F_25 ( struct V_4 * V_4 ,
T_2 V_70 )
{
struct V_1 * V_1 = (struct V_1 * ) V_4 ;
T_1 V_71 ;
int V_20 ;
V_20 = F_7 ( V_1 , V_81 , & V_71 , 1 ) ;
if ( V_20 < 0 )
return V_20 ;
F_3 ( V_72 , L_14 , V_70 ) ;
V_71 = ( V_71 & 0xfe ) | ( V_70 & 0x01 ) ;
V_20 = F_5 ( V_1 , V_81 , & V_71 , 1 ) ;
return V_20 ;
}
static int F_26 ( struct V_4 * V_4 ,
T_2 V_70 )
{
struct V_1 * V_1 = (struct V_1 * ) V_4 ;
T_1 V_71 ;
int V_20 ;
V_20 = F_7 ( V_1 , V_81 , & V_71 , 1 ) ;
if ( V_20 < 0 )
return V_20 ;
F_3 ( V_72 , L_15 , V_70 ) ;
V_70 = ( V_70 == V_82 ) ;
V_71 = ( V_71 & 0xfd ) | ( ( V_70 & 0x01 ) << 1 ) ;
return F_5 ( V_1 , V_81 , & V_71 , 1 ) ;
}
void F_27 ( struct V_1 * V_1 )
{
V_1 -> V_83 = NULL ;
}
static int F_28 ( struct V_84 * V_85 )
{
struct V_4 * V_4 =
F_29 ( V_85 -> V_86 , struct V_4 , V_27 ) ;
struct V_1 * V_1 = (struct V_1 * ) V_4 ;
int V_20 ;
if ( ! V_4 -> V_87 )
return 0 ;
switch ( V_85 -> V_88 ) {
case V_31 :
V_20 = F_25 ( V_4 , V_85 -> V_70 ) ;
if ( V_20 || V_85 -> V_70 )
return V_20 ;
V_20 = F_24 ( V_4 , V_1 -> V_32 -> V_70 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_22 ( V_4 , V_1 -> V_34 -> V_70 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_23 ( V_4 , V_1 -> V_37 -> V_70 ) ;
break;
case V_41 :
V_20 = F_26 ( V_4 , V_85 -> V_70 ) ;
if ( V_20 || V_85 -> V_70 == V_82 )
return V_20 ;
V_20 = F_19 ( V_4 , V_1 -> V_43 -> V_70 ) ;
break;
case V_47 :
V_20 = F_20 ( V_4 , V_85 -> V_70 ) ;
break;
case V_50 :
V_20 = F_21 ( V_4 ) ;
break;
default:
return - V_23 ;
}
return V_20 ;
}
static void F_9 ( struct V_1 * V_1 )
{
int V_89 ;
T_1 V_90 = 0 ;
F_2 ( L_16 ) ;
for ( V_89 = 0 ; V_89 < 0x7f ; V_89 ++ ) {
F_7 ( V_1 , V_89 , & V_90 , 1 ) ;
F_2 ( L_17 , V_89 , V_90 ) ;
}
F_2 ( L_18 ) ;
F_2 ( L_19 ) ;
for ( V_89 = 0 ; V_89 < 0xff ; V_89 ++ ) {
T_1 V_91 , V_92 ;
T_1 V_93 [ 2 ] = { 0xff , 0xff } ;
F_7 ( V_1 , V_89 , & V_91 , 1 ) ;
F_5 ( V_1 , V_89 , V_93 , 1 ) ;
F_7 ( V_1 , V_89 , & V_92 , 1 ) ;
if ( V_92 == V_93 [ 0 ] )
F_2 ( L_20 , V_89 ) ;
else
F_2 ( L_21 , V_89 ) ;
F_5 ( V_1 , V_89 , & V_91 , 1 ) ;
}
}
