int F_1 ( struct V_1 * V_1 )
{
int V_2 = 0 ;
T_1 V_3 = 0 , V_4 = 0 , V_5 ;
T_2 * V_6 ;
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
V_6 = F_8 (
F_4 ( V_19 ) * sizeof( T_2 ) , V_20 ) ;
if ( ! V_6 )
return - V_21 ;
V_1 -> V_22 . V_23 . V_24 = V_25 ;
V_1 -> V_22 . V_23 . V_26 = F_4 ( V_25 ) ;
V_1 -> V_27 -> V_28 = V_19 ;
V_1 -> V_27 -> V_29 = F_4 ( V_19 ) ;
for ( V_5 = 0 ; V_5 < F_4 ( V_19 ) ; V_5 ++ )
V_6 [ V_5 ] = V_19 [ V_5 ] . V_30 . V_31 ;
V_1 -> V_32 = V_6 ;
return 0 ;
}
int F_9 ( struct V_1 * V_1 )
{
int V_5 , V_2 = 0 ;
T_1 V_15 ;
T_2 * V_6 = V_1 -> V_32 ;
if ( V_33 )
F_10 ( V_1 ) ;
for ( V_5 = 0 ; V_5 < F_4 ( V_34 ) && ! V_2 ; V_5 ++ ) {
V_15 = V_34 [ V_5 ] [ 2 ] ;
if ( V_34 [ V_5 ] [ 0 ] == V_16 )
V_2 = F_5 ( V_1 , V_34 [ V_5 ] [ 1 ] ,
& V_15 , 1 ) ;
else
V_2 = F_6 ( V_1 , V_34 [ V_5 ] [ 1 ] , V_15 ) ;
}
V_2 = F_11 ( & V_1 -> V_22 ,
V_6 [ V_35 ] ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_12 ( & V_1 -> V_22 , V_6 [ V_36 ] ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_13 ( & V_1 -> V_22 ,
V_6 [ V_37 ] ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_14 ( & V_1 -> V_22 ,
V_6 [ V_38 ] ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_15 ( & V_1 -> V_22 , V_6 [ V_39 ] ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_16 ( & V_1 -> V_22 , V_6 [ V_40 ] ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_17 ( & V_1 -> V_22 ,
V_6 [ V_41 ] ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_18 ( & V_1 -> V_22 ,
V_6 [ V_42 ] ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_19 ( & V_1 -> V_22 ,
V_6 [ V_43 ] ) ;
return V_2 ;
}
int F_20 ( struct V_1 * V_1 )
{
T_1 V_15 ;
int V_5 , V_2 = 0 ;
struct V_23 * V_23 = & V_1 -> V_22 . V_23 ;
T_2 * V_6 = V_1 -> V_32 ;
int V_44 = V_23 -> V_24 [ V_1 -> V_22 . V_45 ] . V_44 ;
int V_46 = V_23 -> V_24 [ V_1 -> V_22 . V_45 ] . V_46 ;
int V_47 = V_23 -> V_24 [ V_1 -> V_22 . V_45 ] . V_48 ;
int V_49 = V_50 ;
if ( ( ! F_21 ( V_51 ) &&
V_6 [ V_40 ] ) ||
( F_21 ( V_51 ) &&
! V_6 [ V_40 ] ) )
V_47 -- ;
if ( V_44 <= 320 )
V_49 /= 2 ;
for ( V_5 = 0 ; V_5 < F_4 ( V_52 ) && ! V_2 ; V_5 ++ ) {
if ( V_52 [ V_5 ] [ 0 ] == V_53 )
V_2 = F_6 ( V_1 , V_52 [ V_5 ] [ 1 ] ,
V_52 [ V_5 ] [ 2 ] ) ;
else if ( V_52 [ V_5 ] [ 0 ] == V_16 ) {
V_15 = V_52 [ V_5 ] [ 2 ] ;
V_2 = F_5 ( V_1 ,
V_52 [ V_5 ] [ 1 ] , & V_15 , 1 ) ;
}
}
if ( V_2 < 0 )
return V_2 ;
V_2 = F_6 ( V_1 , V_54 ,
( ( V_47 >> 8 ) & 0xff ) ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_6 ( V_1 , V_54 , ( V_47 & 0xff ) ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_6 ( V_1 , V_54 , 0 ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_6 ( V_1 , V_54 , ( V_46 >> 8 ) & 0xff ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_6 ( V_1 , V_54 , ( V_46 & 0xff ) ) ;
if ( V_2 < 0 )
return V_2 ;
for ( V_5 = 0 ; V_5 < 2 && ! V_2 ; V_5 ++ )
V_2 = F_6 ( V_1 , V_54 , 0 ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_6 ( V_1 , V_55 , 0 ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_6 ( V_1 , V_55 , 2 ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_6 ( V_1 , V_56 ,
( V_49 >> 8 ) & 0xff ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_6 ( V_1 , V_56 , V_49 & 0xff ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_6 ( V_1 , V_56 ,
( ( V_44 + V_49 ) >> 8 ) & 0xff ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_6 ( V_1 , V_56 ,
( ( V_44 + V_49 ) & 0xff ) ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_6 ( V_1 , V_55 , 0 ) ;
if ( V_2 < 0 )
return V_2 ;
switch ( V_44 ) {
case 640 :
F_3 ( V_57 , L_4 ) ;
V_15 = V_58 | V_59 |
V_60 ;
V_2 = F_5 ( V_1 , V_61 , & V_15 , 1 ) ;
break;
case 352 :
F_3 ( V_57 , L_5 ) ;
V_15 = V_62 | V_59 |
V_60 ;
V_2 = F_5 ( V_1 , V_61 , & V_15 , 1 ) ;
break;
case 320 :
F_3 ( V_57 , L_6 ) ;
V_15 = V_63 | V_59 |
V_60 ;
V_2 = F_5 ( V_1 , V_61 , & V_15 , 1 ) ;
break;
case 176 :
F_3 ( V_57 , L_7 ) ;
V_15 = V_64 | V_59 |
V_60 ;
V_2 = F_5 ( V_1 , V_61 , & V_15 , 1 ) ;
break;
}
return V_2 ;
}
int F_22 ( struct V_1 * V_1 )
{
T_1 V_15 = V_65 | V_66 ;
return F_5 ( V_1 , V_67 , & V_15 , 1 ) ;
}
void F_23 ( struct V_1 * V_1 )
{
F_22 ( V_1 ) ;
V_1 -> V_68 = NULL ;
F_24 ( V_1 -> V_32 ) ;
}
static int F_25 ( struct V_22 * V_22 , T_3 * V_69 )
{
struct V_1 * V_1 = (struct V_1 * ) V_22 ;
T_2 * V_6 = V_1 -> V_32 ;
* V_69 = V_6 [ V_35 ] ;
F_3 ( V_57 , L_8 , * V_69 ) ;
return 0 ;
}
static int F_11 ( struct V_22 * V_22 , T_3 V_69 )
{
struct V_1 * V_1 = (struct V_1 * ) V_22 ;
T_2 * V_6 = V_1 -> V_32 ;
T_1 V_70 ;
int V_2 ;
F_3 ( V_57 , L_9 , V_69 ) ;
V_6 [ V_35 ] = V_69 ;
V_70 = ( V_69 >> 10 ) & 0x3f ;
V_2 = F_5 ( V_1 , V_71 ,
& V_70 , 1 ) ;
if ( V_2 < 0 )
return V_2 ;
V_70 = ( V_69 >> 2 ) & 0xff ;
V_2 = F_5 ( V_1 , V_72 ,
& V_70 , 1 ) ;
if ( V_2 < 0 )
return V_2 ;
V_70 = V_69 & 0x03 ;
V_2 = F_5 ( V_1 , V_73 , & V_70 , 1 ) ;
return V_2 ;
}
static int F_26 ( struct V_22 * V_22 , T_3 * V_69 )
{
struct V_1 * V_1 = (struct V_1 * ) V_22 ;
T_2 * V_6 = V_1 -> V_32 ;
* V_69 = V_6 [ V_36 ] ;
F_3 ( V_57 , L_10 , * V_69 ) ;
return 0 ;
}
static int F_12 ( struct V_22 * V_22 , T_3 V_69 )
{
int V_2 ;
T_1 V_70 ;
struct V_1 * V_1 = (struct V_1 * ) V_22 ;
T_2 * V_6 = V_1 -> V_32 ;
F_3 ( V_57 , L_11 , V_69 ) ;
V_6 [ V_36 ] = V_69 ;
V_2 = F_7 ( V_1 , V_74 , & V_70 , 1 ) ;
if ( V_2 < 0 )
return V_2 ;
V_70 = ( ( V_69 & 0x0300 ) >> 2 ) |
( V_70 & 0x3f ) ;
V_2 = F_5 ( V_1 , V_74 , & V_70 , 1 ) ;
if ( V_2 < 0 )
return V_2 ;
V_70 = V_69 & 0xff ;
V_2 = F_5 ( V_1 , V_75 , & V_70 , 1 ) ;
return V_2 ;
}
static int F_27 ( struct V_22 * V_22 , T_3 * V_69 )
{
struct V_1 * V_1 = (struct V_1 * ) V_22 ;
T_2 * V_6 = V_1 -> V_32 ;
* V_69 = V_6 [ V_37 ] ;
F_3 ( V_57 , L_12 , * V_69 ) ;
return 0 ;
}
static int F_13 ( struct V_22 * V_22 , T_3 V_69 )
{
int V_2 ;
T_1 V_70 ;
struct V_1 * V_1 = (struct V_1 * ) V_22 ;
T_2 * V_6 = V_1 -> V_32 ;
F_3 ( V_57 , L_13 , V_69 ) ;
V_6 [ V_37 ] = V_69 ;
V_70 = V_69 & 0xff ;
V_2 = F_5 ( V_1 , V_76 , & V_70 , 1 ) ;
return V_2 ;
}
static int F_28 ( struct V_22 * V_22 , T_3 * V_69 )
{
struct V_1 * V_1 = (struct V_1 * ) V_22 ;
T_2 * V_6 = V_1 -> V_32 ;
* V_69 = V_6 [ V_38 ] ;
F_3 ( V_57 , L_14 , * V_69 ) ;
return 0 ;
}
static int F_14 ( struct V_22 * V_22 , T_3 V_69 )
{
int V_2 ;
T_1 V_70 ;
struct V_1 * V_1 = (struct V_1 * ) V_22 ;
T_2 * V_6 = V_1 -> V_32 ;
F_3 ( V_57 , L_15 , V_69 ) ;
V_6 [ V_38 ] = V_69 ;
V_70 = V_69 & 0xff ;
V_2 = F_5 ( V_1 , V_77 , & V_70 , 1 ) ;
return V_2 ;
}
static int F_29 ( struct V_22 * V_22 , T_3 * V_69 )
{
struct V_1 * V_1 = (struct V_1 * ) V_22 ;
T_2 * V_6 = V_1 -> V_32 ;
* V_69 = V_6 [ V_39 ] ;
F_3 ( V_57 , L_16 , * V_69 ) ;
return 0 ;
}
static int F_15 ( struct V_22 * V_22 , T_3 V_69 )
{
int V_2 ;
T_1 V_70 ;
struct V_1 * V_1 = (struct V_1 * ) V_22 ;
T_2 * V_6 = V_1 -> V_32 ;
F_3 ( V_57 , L_17 , V_69 ) ;
V_6 [ V_39 ] = V_69 ;
if ( ! F_21 ( V_51 ) )
V_70 = ( ( V_69 & 0x01 ) << 5 ) |
( V_6 [ V_40 ] << 4 ) ;
else
V_70 = ( ( V_69 & 0x01 ) << 5 ) |
( ! V_6 [ V_40 ] << 4 ) ;
V_2 = F_5 ( V_1 , V_78 , & V_70 , 1 ) ;
return V_2 ;
}
static int F_30 ( struct V_22 * V_22 , T_3 * V_69 )
{
struct V_1 * V_1 = (struct V_1 * ) V_22 ;
T_2 * V_6 = V_1 -> V_32 ;
* V_69 = V_6 [ V_40 ] ;
F_3 ( V_57 , L_18 , * V_69 ) ;
return 0 ;
}
static int F_16 ( struct V_22 * V_22 , T_3 V_69 )
{
int V_2 ;
T_1 V_70 ;
struct V_1 * V_1 = (struct V_1 * ) V_22 ;
T_2 * V_6 = V_1 -> V_32 ;
F_3 ( V_57 , L_19 , V_69 ) ;
V_6 [ V_40 ] = V_69 ;
if ( F_21 ( V_51 ) )
V_69 = ! V_69 ;
V_70 = ( ( V_69 & 0x01 ) << 4 ) | ( V_6 [ V_40 ] << 5 ) ;
V_2 = F_5 ( V_1 , V_78 , & V_70 , 1 ) ;
if ( V_2 < 0 )
return V_2 ;
if ( V_22 -> V_79 )
V_2 = F_20 ( V_1 ) ;
return V_2 ;
}
static int F_31 ( struct V_22 * V_22 , T_3 * V_69 )
{
struct V_1 * V_1 = (struct V_1 * ) V_22 ;
T_2 * V_6 = V_1 -> V_32 ;
* V_69 = V_6 [ V_41 ] ;
F_3 ( V_57 , L_20 , * V_69 ) ;
return 0 ;
}
static int F_17 ( struct V_22 * V_22 ,
T_3 V_69 )
{
int V_2 ;
T_1 V_70 ;
struct V_1 * V_1 = (struct V_1 * ) V_22 ;
T_2 * V_6 = V_1 -> V_32 ;
F_3 ( V_57 , L_21 , V_69 ) ;
V_6 [ V_41 ] = V_69 ;
V_2 = F_7 ( V_1 , V_80 , & V_70 , 1 ) ;
if ( V_2 < 0 )
return V_2 ;
V_70 = ( ( V_70 & 0xfe ) | ( ( V_69 & 0x01 ) << 0 ) ) ;
return F_5 ( V_1 , V_80 , & V_70 , 1 ) ;
}
static int F_32 ( struct V_22 * V_22 ,
T_3 * V_69 )
{
struct V_1 * V_1 = (struct V_1 * ) V_22 ;
T_2 * V_6 = V_1 -> V_32 ;
* V_69 = V_6 [ V_42 ] ;
return 0 ;
}
static int F_18 ( struct V_22 * V_22 ,
T_3 V_69 )
{
int V_2 ;
T_1 V_70 ;
struct V_1 * V_1 = (struct V_1 * ) V_22 ;
T_2 * V_6 = V_1 -> V_32 ;
F_3 ( V_57 , L_22 , V_69 ) ;
V_6 [ V_42 ] = V_69 ;
V_2 = F_7 ( V_1 , V_80 , & V_70 , 1 ) ;
if ( V_2 < 0 )
return V_2 ;
V_70 = ( ( V_70 & 0xfd ) | ( ( V_69 & 0x01 ) << 1 ) ) ;
V_2 = F_5 ( V_1 , V_80 , & V_70 , 1 ) ;
return V_2 ;
}
static int F_33 ( struct V_22 * V_22 , T_3 * V_69 )
{
struct V_1 * V_1 = (struct V_1 * ) V_22 ;
T_2 * V_6 = V_1 -> V_32 ;
* V_69 = V_6 [ V_43 ] ;
F_3 ( V_57 , L_23 , * V_69 ) ;
return 0 ;
}
static int F_19 ( struct V_22 * V_22 , T_3 V_69 )
{
int V_2 ;
T_1 V_70 ;
struct V_1 * V_1 = (struct V_1 * ) V_22 ;
T_2 * V_6 = V_1 -> V_32 ;
F_3 ( V_57 , L_24 , V_69 ) ;
V_6 [ V_43 ] = V_69 ;
V_2 = F_7 ( V_1 , V_80 , & V_70 , 1 ) ;
if ( V_2 < 0 )
return V_2 ;
V_70 = ( ( V_70 & 0xfb ) | ( ( V_69 & 0x01 ) << 2 ) ) ;
return F_5 ( V_1 , V_80 , & V_70 , 1 ) ;
}
static void F_10 ( struct V_1 * V_1 )
{
int V_81 ;
F_2 ( L_25 ) ;
for ( V_81 = 0 ; V_81 < 0xa9 ; V_81 ++ ) {
T_1 V_82 ;
F_7 ( V_1 , V_81 , & V_82 , 1 ) ;
F_2 ( L_26 , V_81 , V_82 ) ;
}
F_2 ( L_27 ) ;
F_2 ( L_28 ) ;
for ( V_81 = 0 ; V_81 < 0xff ; V_81 ++ ) {
T_1 V_83 , V_84 ;
T_1 V_85 [ 2 ] = { 0xff , 0xff } ;
F_7 ( V_1 , V_81 , & V_83 , 1 ) ;
F_5 ( V_1 , V_81 , V_85 , 1 ) ;
F_7 ( V_1 , V_81 , & V_84 , 1 ) ;
if ( V_84 == V_85 [ 0 ] )
F_2 ( L_29 , V_81 ) ;
else
F_2 ( L_30 , V_81 ) ;
F_5 ( V_1 , V_81 , & V_83 , 1 ) ;
}
}
