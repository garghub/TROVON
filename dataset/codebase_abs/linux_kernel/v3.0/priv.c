static int F_1 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 . V_5 -> V_6 >> 28 ;
int V_7 = ( ( V_2 -> V_4 . V_5 -> V_6 & 0x0fff0000 ) >> 16 ) ;
T_1 V_8 ;
T_2 V_9 = 0 ;
T_3 V_10 ;
V_2 -> V_11 . V_12 ++ ;
V_8 = V_7 ;
if ( V_3 )
V_8 += V_2 -> V_4 . V_13 [ V_3 ] ;
if ( V_8 & 3 ) {
F_2 ( V_2 , V_14 ) ;
goto V_15;
}
if ( F_3 ( V_2 , V_8 , & V_9 ) ) {
F_2 ( V_2 , V_16 ) ;
goto V_15;
}
V_9 = V_9 & 0x7fffe000u ;
if ( F_4 ( V_2 , & V_10 , V_9 , 1 ) ||
( F_4 ( V_2 , & V_10 , V_9 + V_17 , 1 ) ) ) {
F_2 ( V_2 , V_16 ) ;
goto V_15;
}
V_2 -> V_4 . V_5 -> V_18 = V_9 ;
V_2 -> V_4 . V_5 -> V_19 = 0xffff ;
F_5 ( V_2 , 5 , L_1 , V_9 ) ;
V_15:
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 . V_5 -> V_6 >> 28 ;
int V_7 = ( ( V_2 -> V_4 . V_5 -> V_6 & 0x0fff0000 ) >> 16 ) ;
T_1 V_8 ;
T_2 V_9 ;
V_2 -> V_11 . V_20 ++ ;
V_8 = V_7 ;
if ( V_3 )
V_8 += V_2 -> V_4 . V_13 [ V_3 ] ;
if ( V_8 & 3 ) {
F_2 ( V_2 , V_14 ) ;
goto V_15;
}
V_9 = V_2 -> V_4 . V_5 -> V_18 ;
V_9 = V_9 & 0x7fffe000u ;
if ( F_7 ( V_2 , V_8 , V_9 ) ) {
F_2 ( V_2 , V_16 ) ;
goto V_15;
}
F_5 ( V_2 , 5 , L_2 , V_9 ) ;
V_15:
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 . V_5 -> V_6 >> 28 ;
int V_7 = ( ( V_2 -> V_4 . V_5 -> V_6 & 0x0fff0000 ) >> 16 ) ;
T_1 V_21 ;
int V_22 ;
V_2 -> V_11 . V_23 ++ ;
V_21 = V_7 ;
if ( V_3 )
V_21 += V_2 -> V_4 . V_13 [ V_3 ] ;
if ( V_21 & 1 ) {
F_2 ( V_2 , V_14 ) ;
goto V_15;
}
V_22 = F_9 ( V_2 , V_21 , V_2 -> V_24 ) ;
if ( V_22 == - V_25 ) {
F_2 ( V_2 , V_16 ) ;
goto V_15;
}
F_5 ( V_2 , 5 , L_3 , V_21 ) ;
V_15:
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
V_2 -> V_11 . V_26 ++ ;
V_2 -> V_4 . V_5 -> V_27 . V_28 -= 4 ;
F_5 ( V_2 , 4 , L_4 , L_5 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
V_2 -> V_11 . V_29 ++ ;
F_5 ( V_2 , 4 , L_4 , L_6 ) ;
V_2 -> V_4 . V_5 -> V_27 . V_30 &= ~ ( 3ul << 44 ) ;
V_2 -> V_4 . V_5 -> V_27 . V_30 |= ( 3 & 3ul ) << 44 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
V_2 -> V_11 . V_31 ++ ;
F_5 ( V_2 , 4 , L_4 , L_7 ) ;
V_2 -> V_4 . V_5 -> V_27 . V_30 &= ~ ( 3ul << 44 ) ;
V_2 -> V_4 . V_5 -> V_27 . V_30 |= ( 3 & 3ul ) << 44 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
unsigned int V_32 ;
int V_22 ;
V_2 -> V_11 . V_33 ++ ;
V_32 = V_34 . V_35 & 0xff00fff3 ;
V_22 = F_14 ( V_2 , F_15 ( struct V_36 , V_35 ) ,
& V_32 , sizeof( V_32 ) ) ;
if ( V_22 == - V_25 )
F_2 ( V_2 , V_16 ) ;
else
F_5 ( V_2 , 5 , L_8 ,
V_32 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 . V_5 -> V_6 >> 28 ;
int V_7 = ( ( V_2 -> V_4 . V_5 -> V_6 & 0x0fff0000 ) >> 16 ) ;
T_1 V_8 ;
int V_22 ;
V_2 -> V_11 . V_37 ++ ;
V_8 = V_7 ;
if ( V_3 )
V_8 += V_2 -> V_4 . V_13 [ V_3 ] ;
if ( V_8 & 7 ) {
F_2 ( V_2 , V_14 ) ;
goto V_15;
}
V_22 = F_17 ( V_2 , V_8 , V_2 -> V_4 . V_38 ) ;
if ( V_22 == - V_25 ) {
F_2 ( V_2 , V_16 ) ;
goto V_15;
}
F_5 ( V_2 , 5 , L_4 , L_9 ) ;
V_15:
return 0 ;
}
static void F_18 ( struct V_1 * V_2 , struct V_39 * V_40 )
{
struct V_41 * V_42 = & V_2 -> V_43 -> V_4 . V_44 ;
int V_45 = 0 ;
int V_46 ;
F_19 ( & V_42 -> V_47 ) ;
for ( V_46 = 0 ; V_46 < V_48 ; V_46 ++ )
if ( V_42 -> V_49 [ V_46 ] )
V_45 ++ ;
F_20 ( & V_42 -> V_47 ) ;
if ( F_21 ( V_40 , 3 , 2 , 2 ) == - V_50 )
V_40 -> V_51 = 0 ;
if ( V_40 -> V_51 < 8 )
V_40 -> V_51 ++ ;
for ( V_46 = V_40 -> V_51 - 1 ; V_46 > 0 ; V_46 -- )
memcpy ( & V_40 -> V_52 [ V_46 ] , & V_40 -> V_52 [ V_46 - 1 ] , sizeof( V_40 -> V_52 [ 0 ] ) ) ;
V_40 -> V_52 [ 0 ] . V_53 = V_45 ;
V_40 -> V_52 [ 0 ] . V_54 = V_45 ;
V_40 -> V_52 [ 0 ] . V_55 = 0 ;
V_40 -> V_52 [ 0 ] . V_56 = 0 ;
V_40 -> V_52 [ 0 ] . V_57 = 1000 ;
memcpy ( V_40 -> V_52 [ 0 ] . V_58 , L_10 , 8 ) ;
F_22 ( V_40 -> V_52 [ 0 ] . V_58 , 8 ) ;
memcpy ( V_40 -> V_52 [ 0 ] . V_59 , L_11 , 16 ) ;
F_22 ( V_40 -> V_52 [ 0 ] . V_59 , 16 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_60 = ( V_2 -> V_4 . V_13 [ 0 ] & 0xf0000000 ) >> 28 ;
int V_61 = V_2 -> V_4 . V_13 [ 0 ] & 0xff ;
int V_62 = V_2 -> V_4 . V_13 [ 1 ] & 0xffff ;
int V_3 = V_2 -> V_4 . V_5 -> V_6 >> 28 ;
int V_7 = ( ( V_2 -> V_4 . V_5 -> V_6 & 0x0fff0000 ) >> 16 ) ;
T_1 V_8 ;
unsigned long V_40 ;
V_2 -> V_11 . V_63 ++ ;
F_5 ( V_2 , 4 , L_12 , V_60 , V_61 , V_62 ) ;
V_8 = V_7 ;
if ( V_3 )
V_8 += V_2 -> V_4 . V_13 [ V_3 ] ;
if ( V_8 & 0xfff && V_60 > 0 )
return F_2 ( V_2 , V_14 ) ;
switch ( V_60 ) {
case 0 :
V_2 -> V_4 . V_13 [ 0 ] = 3 << 28 ;
V_2 -> V_4 . V_5 -> V_27 . V_30 &= ~ ( 3ul << 44 ) ;
return 0 ;
case 1 :
case 2 :
V_40 = F_24 ( V_64 ) ;
if ( ! V_40 )
goto V_65;
if ( F_21 ( ( void * ) V_40 , V_60 , V_61 , V_62 ) == - V_50 )
goto V_66;
break;
case 3 :
if ( V_61 != 2 || V_62 != 2 )
goto V_65;
V_40 = F_24 ( V_64 ) ;
if ( ! V_40 )
goto V_65;
F_18 ( V_2 , ( void * ) V_40 ) ;
break;
default:
goto V_65;
}
if ( F_25 ( V_2 , V_8 , ( void * ) V_40 , V_17 ) ) {
F_2 ( V_2 , V_16 ) ;
goto V_66;
}
F_26 ( V_40 ) ;
V_2 -> V_4 . V_5 -> V_27 . V_30 &= ~ ( 3ul << 44 ) ;
V_2 -> V_4 . V_13 [ 0 ] = 0 ;
return 0 ;
V_66:
F_26 ( V_40 ) ;
V_65:
V_2 -> V_4 . V_5 -> V_27 . V_30 |= 3ul << 44 ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 )
{
T_4 V_67 ;
V_67 = V_68 [ V_2 -> V_4 . V_5 -> V_69 & 0x00ff ] ;
if ( V_67 ) {
if ( V_2 -> V_4 . V_5 -> V_27 . V_30 & V_70 )
return F_2 ( V_2 ,
V_71 ) ;
else
return V_67 ( V_2 ) ;
}
return - V_72 ;
}
