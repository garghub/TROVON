int F_1 ( struct V_1 * V_1 )
{
int V_2 = 0 ;
T_1 V_3 = 0 , V_4 = 0 , V_5 ;
struct V_6 * V_6 = (struct V_6 * ) V_1 ;
if ( V_7 ) {
if ( V_7 == V_8 ) {
F_2 ( L_1 , V_9 . V_10 ) ;
goto V_11;
}
return - V_12 ;
}
F_3 ( V_13 , L_2 ) ;
for ( V_5 = 0 ; V_5 < F_4 ( V_14 ) && ! V_2 ; V_5 ++ ) {
T_1 V_15 = V_14 [ V_5 ] [ 2 ] ;
if ( V_14 [ V_5 ] [ 0 ] == V_16 )
V_2 = F_5 ( V_1 ,
V_14 [ V_5 ] [ 1 ] , & V_15 , 1 ) ;
else
V_2 = F_6 ( V_1 ,
V_14 [ V_5 ] [ 1 ] , V_15 ) ;
}
if ( V_2 < 0 )
return V_2 ;
if ( F_7 ( V_1 , V_17 , & V_3 , 1 ) )
return - V_12 ;
if ( F_7 ( V_1 , V_18 , & V_4 , 1 ) )
return - V_12 ;
if ( ( V_3 == 0x96 ) && ( V_4 == 0x52 ) ) {
F_2 ( L_3 ) ;
goto V_11;
}
return - V_12 ;
V_11:
V_1 -> V_6 . V_19 . V_20 = V_21 ;
V_1 -> V_6 . V_19 . V_22 = F_4 ( V_21 ) ;
return 0 ;
}
int F_8 ( struct V_1 * V_1 )
{
int V_5 , V_2 = 0 ;
T_1 V_15 ;
if ( V_23 )
F_9 ( V_1 ) ;
for ( V_5 = 0 ; V_5 < F_4 ( V_24 ) && ! V_2 ; V_5 ++ ) {
V_15 = V_24 [ V_5 ] [ 2 ] ;
if ( V_24 [ V_5 ] [ 0 ] == V_16 )
V_2 = F_5 ( V_1 , V_24 [ V_5 ] [ 1 ] ,
& V_15 , 1 ) ;
else
V_2 = F_6 ( V_1 , V_24 [ V_5 ] [ 1 ] , V_15 ) ;
}
return 0 ;
}
int F_10 ( struct V_1 * V_1 )
{
struct V_25 * V_26 = & V_1 -> V_6 . V_27 ;
V_1 -> V_6 . V_28 . V_27 = V_26 ;
F_11 ( V_26 , 9 ) ;
V_1 -> V_29 = F_12 ( V_26 , & V_30 ,
V_31 ,
0 , 1 , 1 , 1 ) ;
V_1 -> V_32 = F_12 ( V_26 , & V_30 ,
V_33 , 0 , 255 , 1 ,
V_34 ) ;
V_1 -> V_35 = F_12 ( V_26 , & V_30 ,
V_36 , 0 , 255 , 1 ,
V_37 ) ;
V_1 -> V_38 = F_13 ( V_26 , & V_30 ,
V_39 , 1 , 0 , V_40 ) ;
V_1 -> V_41 = F_12 ( V_26 , & V_30 , V_42 ,
0 , 0x1ff , 4 , V_43 ) ;
V_1 -> V_44 = F_12 ( V_26 , & V_30 ,
V_45 , 0 , 1 , 1 , 1 ) ;
V_1 -> V_46 = F_12 ( V_26 , & V_30 , V_47 , 0 ,
0x3ff , 1 , V_48 ) ;
V_1 -> V_49 = F_12 ( V_26 , & V_30 , V_50 ,
0 , 1 , 1 , 0 ) ;
V_1 -> V_51 = F_12 ( V_26 , & V_30 , V_52 ,
0 , 1 , 1 , 0 ) ;
if ( V_26 -> error ) {
F_14 ( L_4 ) ;
return V_26 -> error ;
}
F_15 ( 3 , & V_1 -> V_29 , 0 , false ) ;
F_15 ( 2 , & V_1 -> V_38 , 0 , false ) ;
F_15 ( 2 , & V_1 -> V_44 , 0 , false ) ;
F_16 ( 2 , & V_1 -> V_49 ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_1 )
{
T_1 V_15 ;
int V_5 , V_2 = 0 ;
struct V_19 * V_19 = & V_1 -> V_6 . V_19 ;
int V_53 = V_19 -> V_20 [ V_1 -> V_6 . V_54 ] . V_53 ;
int V_55 = V_19 -> V_20 [ V_1 -> V_6 . V_54 ] . V_55 ;
int V_56 = V_19 -> V_20 [ V_1 -> V_6 . V_54 ] . V_57 ;
int V_58 = V_59 ;
struct V_6 * V_6 = (struct V_6 * ) V_1 ;
if ( ( ! F_18 ( V_60 ) &&
V_1 -> V_51 -> V_61 ) ||
( F_18 ( V_60 ) &&
! V_1 -> V_51 -> V_61 ) )
V_56 -- ;
if ( V_53 <= 320 )
V_58 /= 2 ;
for ( V_5 = 0 ; V_5 < F_4 ( V_62 ) && ! V_2 ; V_5 ++ ) {
if ( V_62 [ V_5 ] [ 0 ] == V_63 )
V_2 = F_6 ( V_1 , V_62 [ V_5 ] [ 1 ] ,
V_62 [ V_5 ] [ 2 ] ) ;
else if ( V_62 [ V_5 ] [ 0 ] == V_16 ) {
V_15 = V_62 [ V_5 ] [ 2 ] ;
V_2 = F_5 ( V_1 ,
V_62 [ V_5 ] [ 1 ] , & V_15 , 1 ) ;
}
}
if ( V_2 < 0 )
return V_2 ;
V_2 = F_6 ( V_1 , V_64 ,
( ( V_56 >> 8 ) & 0xff ) ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_6 ( V_1 , V_64 , ( V_56 & 0xff ) ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_6 ( V_1 , V_64 , 0 ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_6 ( V_1 , V_64 , ( V_55 >> 8 ) & 0xff ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_6 ( V_1 , V_64 , ( V_55 & 0xff ) ) ;
if ( V_2 < 0 )
return V_2 ;
for ( V_5 = 0 ; V_5 < 2 && ! V_2 ; V_5 ++ )
V_2 = F_6 ( V_1 , V_64 , 0 ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_6 ( V_1 , V_65 , 0 ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_6 ( V_1 , V_65 , 2 ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_6 ( V_1 , V_66 ,
( V_58 >> 8 ) & 0xff ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_6 ( V_1 , V_66 , V_58 & 0xff ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_6 ( V_1 , V_66 ,
( ( V_53 + V_58 ) >> 8 ) & 0xff ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_6 ( V_1 , V_66 ,
( ( V_53 + V_58 ) & 0xff ) ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_6 ( V_1 , V_65 , 0 ) ;
if ( V_2 < 0 )
return V_2 ;
switch ( V_53 ) {
case 640 :
F_3 ( V_67 , L_5 ) ;
V_15 = V_68 | V_69 |
V_70 ;
V_2 = F_5 ( V_1 , V_71 , & V_15 , 1 ) ;
break;
case 352 :
F_3 ( V_67 , L_6 ) ;
V_15 = V_72 | V_69 |
V_70 ;
V_2 = F_5 ( V_1 , V_71 , & V_15 , 1 ) ;
break;
case 320 :
F_3 ( V_67 , L_7 ) ;
V_15 = V_73 | V_69 |
V_70 ;
V_2 = F_5 ( V_1 , V_71 , & V_15 , 1 ) ;
break;
case 176 :
F_3 ( V_67 , L_8 ) ;
V_15 = V_74 | V_69 |
V_70 ;
V_2 = F_5 ( V_1 , V_71 , & V_15 , 1 ) ;
break;
}
return V_2 ;
}
int F_19 ( struct V_1 * V_1 )
{
T_1 V_15 = V_75 | V_76 ;
return F_5 ( V_1 , V_77 , & V_15 , 1 ) ;
}
void F_20 ( struct V_1 * V_1 )
{
F_19 ( V_1 ) ;
V_1 -> V_78 = NULL ;
}
static int F_21 ( struct V_6 * V_6 , T_2 V_61 )
{
struct V_1 * V_1 = (struct V_1 * ) V_6 ;
T_1 V_79 ;
int V_2 ;
F_3 ( V_67 , L_9 , V_61 ) ;
V_79 = ( V_61 >> 10 ) & 0x3f ;
V_2 = F_5 ( V_1 , V_80 ,
& V_79 , 1 ) ;
if ( V_2 < 0 )
return V_2 ;
V_79 = ( V_61 >> 2 ) & 0xff ;
V_2 = F_5 ( V_1 , V_81 ,
& V_79 , 1 ) ;
if ( V_2 < 0 )
return V_2 ;
V_79 = V_61 & 0x03 ;
V_2 = F_5 ( V_1 , V_82 , & V_79 , 1 ) ;
return V_2 ;
}
static int F_22 ( struct V_6 * V_6 , T_2 V_61 )
{
int V_2 ;
T_1 V_79 ;
struct V_1 * V_1 = (struct V_1 * ) V_6 ;
F_3 ( V_67 , L_10 , V_61 ) ;
V_2 = F_7 ( V_1 , V_83 , & V_79 , 1 ) ;
if ( V_2 < 0 )
return V_2 ;
V_79 = ( ( V_61 & 0x0300 ) >> 2 ) |
( V_79 & 0x3f ) ;
V_2 = F_5 ( V_1 , V_83 , & V_79 , 1 ) ;
if ( V_2 < 0 )
return V_2 ;
V_79 = V_61 & 0xff ;
V_2 = F_5 ( V_1 , V_84 , & V_79 , 1 ) ;
return V_2 ;
}
static int F_23 ( struct V_6 * V_6 , T_2 V_61 )
{
int V_2 ;
T_1 V_79 ;
struct V_1 * V_1 = (struct V_1 * ) V_6 ;
F_3 ( V_67 , L_11 , V_61 ) ;
V_79 = V_61 & 0xff ;
V_2 = F_5 ( V_1 , V_85 , & V_79 , 1 ) ;
return V_2 ;
}
static int F_24 ( struct V_6 * V_6 , T_2 V_61 )
{
int V_2 ;
T_1 V_79 ;
struct V_1 * V_1 = (struct V_1 * ) V_6 ;
F_3 ( V_67 , L_12 , V_61 ) ;
V_79 = V_61 & 0xff ;
V_2 = F_5 ( V_1 , V_86 , & V_79 , 1 ) ;
return V_2 ;
}
static int F_25 ( struct V_6 * V_6 )
{
int V_2 ;
T_1 V_79 ;
struct V_1 * V_1 = (struct V_1 * ) V_6 ;
int V_49 = V_1 -> V_49 -> V_61 ;
int V_51 = V_1 -> V_51 -> V_61 ;
F_3 ( V_67 , L_13 , V_49 , V_51 ) ;
if ( F_18 ( V_60 ) )
V_51 = ! V_51 ;
V_79 = ( V_49 << 5 ) | ( V_51 << 4 ) ;
V_2 = F_5 ( V_1 , V_87 , & V_79 , 1 ) ;
if ( V_2 < 0 )
return V_2 ;
if ( V_6 -> V_88 )
V_2 = F_17 ( V_1 ) ;
return V_2 ;
}
static int F_26 ( struct V_6 * V_6 ,
T_2 V_61 )
{
int V_2 ;
T_1 V_79 ;
struct V_1 * V_1 = (struct V_1 * ) V_6 ;
F_3 ( V_67 , L_14 , V_61 ) ;
V_2 = F_7 ( V_1 , V_89 , & V_79 , 1 ) ;
if ( V_2 < 0 )
return V_2 ;
V_61 = ( V_61 == V_40 ) ;
V_79 = ( ( V_79 & 0xfe ) | ( ( V_61 & 0x01 ) << 0 ) ) ;
return F_5 ( V_1 , V_89 , & V_79 , 1 ) ;
}
static int F_27 ( struct V_6 * V_6 ,
T_2 V_61 )
{
int V_2 ;
T_1 V_79 ;
struct V_1 * V_1 = (struct V_1 * ) V_6 ;
F_3 ( V_67 , L_15 , V_61 ) ;
V_2 = F_7 ( V_1 , V_89 , & V_79 , 1 ) ;
if ( V_2 < 0 )
return V_2 ;
V_79 = ( ( V_79 & 0xfd ) | ( ( V_61 & 0x01 ) << 1 ) ) ;
V_2 = F_5 ( V_1 , V_89 , & V_79 , 1 ) ;
return V_2 ;
}
static int F_28 ( struct V_6 * V_6 , T_2 V_61 )
{
int V_2 ;
T_1 V_79 ;
struct V_1 * V_1 = (struct V_1 * ) V_6 ;
F_3 ( V_67 , L_16 , V_61 ) ;
V_2 = F_7 ( V_1 , V_89 , & V_79 , 1 ) ;
if ( V_2 < 0 )
return V_2 ;
V_79 = ( ( V_79 & 0xfb ) | ( ( V_61 & 0x01 ) << 2 ) ) ;
return F_5 ( V_1 , V_89 , & V_79 , 1 ) ;
}
static int F_29 ( struct V_90 * V_91 )
{
struct V_6 * V_6 =
F_30 ( V_91 -> V_92 , struct V_6 , V_27 ) ;
struct V_1 * V_1 = (struct V_1 * ) V_6 ;
int V_2 ;
if ( ! V_6 -> V_88 )
return 0 ;
switch ( V_91 -> V_93 ) {
case V_31 :
V_2 = F_27 ( V_6 , V_91 -> V_61 ) ;
if ( V_2 || V_91 -> V_61 )
return V_2 ;
V_2 = F_23 ( V_6 , V_1 -> V_32 -> V_61 ) ;
if ( V_2 )
return V_2 ;
V_2 = F_24 ( V_6 , V_1 -> V_35 -> V_61 ) ;
break;
case V_39 :
V_2 = F_26 ( V_6 , V_91 -> V_61 ) ;
if ( V_2 || V_91 -> V_61 == V_40 )
return V_2 ;
V_2 = F_21 ( V_6 , V_1 -> V_41 -> V_61 ) ;
break;
case V_45 :
V_2 = F_28 ( V_6 , V_91 -> V_61 ) ;
if ( V_2 || V_91 -> V_61 )
return V_2 ;
V_2 = F_22 ( V_6 , V_1 -> V_46 -> V_61 ) ;
break;
case V_50 :
V_2 = F_25 ( V_6 ) ;
break;
default:
return - V_94 ;
}
return V_2 ;
}
static void F_9 ( struct V_1 * V_1 )
{
int V_95 ;
F_2 ( L_17 ) ;
for ( V_95 = 0 ; V_95 < 0xa9 ; V_95 ++ ) {
T_1 V_96 ;
F_7 ( V_1 , V_95 , & V_96 , 1 ) ;
F_2 ( L_18 , V_95 , V_96 ) ;
}
F_2 ( L_19 ) ;
F_2 ( L_20 ) ;
for ( V_95 = 0 ; V_95 < 0xff ; V_95 ++ ) {
T_1 V_97 , V_98 ;
T_1 V_99 [ 2 ] = { 0xff , 0xff } ;
F_7 ( V_1 , V_95 , & V_97 , 1 ) ;
F_5 ( V_1 , V_95 , V_99 , 1 ) ;
F_7 ( V_1 , V_95 , & V_98 , 1 ) ;
if ( V_98 == V_99 [ 0 ] )
F_2 ( L_21 , V_95 ) ;
else
F_2 ( L_22 , V_95 ) ;
F_5 ( V_1 , V_95 , & V_97 , 1 ) ;
}
}
