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
V_8 += V_2 -> V_13 -> V_14 . V_15 . V_16 [ V_3 ] ;
if ( V_8 & 3 ) {
F_2 ( V_2 , V_17 ) ;
goto V_18;
}
if ( F_3 ( V_2 , V_8 , & V_9 ) ) {
F_2 ( V_2 , V_19 ) ;
goto V_18;
}
V_9 = V_9 & 0x7fffe000u ;
if ( F_4 ( V_2 , & V_10 , V_9 , 1 ) ||
( F_4 ( V_2 , & V_10 , V_9 + V_20 , 1 ) ) ) {
F_2 ( V_2 , V_19 ) ;
goto V_18;
}
F_5 ( V_2 , V_9 ) ;
F_6 ( V_2 , 5 , L_1 , V_9 ) ;
V_18:
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 . V_5 -> V_6 >> 28 ;
int V_7 = ( ( V_2 -> V_4 . V_5 -> V_6 & 0x0fff0000 ) >> 16 ) ;
T_1 V_8 ;
T_2 V_9 ;
V_2 -> V_11 . V_21 ++ ;
V_8 = V_7 ;
if ( V_3 )
V_8 += V_2 -> V_13 -> V_14 . V_15 . V_16 [ V_3 ] ;
if ( V_8 & 3 ) {
F_2 ( V_2 , V_17 ) ;
goto V_18;
}
V_9 = V_2 -> V_4 . V_5 -> V_22 ;
V_9 = V_9 & 0x7fffe000u ;
if ( F_8 ( V_2 , V_8 , V_9 ) ) {
F_2 ( V_2 , V_19 ) ;
goto V_18;
}
F_6 ( V_2 , 5 , L_2 , V_9 ) ;
V_18:
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 . V_5 -> V_6 >> 28 ;
int V_7 = ( ( V_2 -> V_4 . V_5 -> V_6 & 0x0fff0000 ) >> 16 ) ;
T_1 V_23 ;
int V_24 ;
V_2 -> V_11 . V_25 ++ ;
V_23 = V_7 ;
if ( V_3 )
V_23 += V_2 -> V_13 -> V_14 . V_15 . V_16 [ V_3 ] ;
if ( V_23 & 1 ) {
F_2 ( V_2 , V_17 ) ;
goto V_18;
}
V_24 = F_10 ( V_2 , V_23 , V_2 -> V_26 ) ;
if ( V_24 == - V_27 ) {
F_2 ( V_2 , V_19 ) ;
goto V_18;
}
F_6 ( V_2 , 5 , L_3 , V_23 ) ;
V_18:
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
V_2 -> V_11 . V_28 ++ ;
V_2 -> V_4 . V_5 -> V_29 . V_30 -= 4 ;
F_6 ( V_2 , 4 , L_4 , L_5 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
V_2 -> V_11 . V_31 ++ ;
F_6 ( V_2 , 4 , L_4 , L_6 ) ;
V_2 -> V_4 . V_5 -> V_29 . V_32 &= ~ ( 3ul << 44 ) ;
V_2 -> V_4 . V_5 -> V_29 . V_32 |= ( 3 & 3ul ) << 44 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
V_2 -> V_11 . V_33 ++ ;
F_6 ( V_2 , 4 , L_4 , L_7 ) ;
V_2 -> V_4 . V_5 -> V_29 . V_32 &= ~ ( 3ul << 44 ) ;
V_2 -> V_4 . V_5 -> V_29 . V_32 |= ( 3 & 3ul ) << 44 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
unsigned int V_34 ;
int V_24 ;
V_2 -> V_11 . V_35 ++ ;
V_34 = V_36 . V_37 & 0xff00fff3 ;
V_24 = F_15 ( V_2 , F_16 ( struct V_38 , V_37 ) ,
& V_34 , sizeof( V_34 ) ) ;
if ( V_24 == - V_27 )
F_2 ( V_2 , V_19 ) ;
else
F_6 ( V_2 , 5 , L_8 ,
V_34 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 . V_5 -> V_6 >> 28 ;
int V_7 = ( ( V_2 -> V_4 . V_5 -> V_6 & 0x0fff0000 ) >> 16 ) ;
T_1 V_8 ;
int V_24 ;
V_2 -> V_11 . V_39 ++ ;
V_8 = V_7 ;
if ( V_3 )
V_8 += V_2 -> V_13 -> V_14 . V_15 . V_16 [ V_3 ] ;
if ( V_8 & 7 ) {
F_2 ( V_2 , V_17 ) ;
goto V_18;
}
V_24 = F_18 ( V_2 , V_8 , V_2 -> V_4 . V_40 ) ;
if ( V_24 == - V_27 ) {
F_2 ( V_2 , V_19 ) ;
goto V_18;
}
F_6 ( V_2 , 5 , L_4 , L_9 ) ;
V_18:
return 0 ;
}
static void F_19 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
struct V_43 * V_44 = & V_2 -> V_45 -> V_4 . V_46 ;
int V_47 = 0 ;
int V_48 ;
F_20 ( & V_44 -> V_49 ) ;
for ( V_48 = 0 ; V_48 < V_50 ; V_48 ++ )
if ( V_44 -> V_51 [ V_48 ] )
V_47 ++ ;
F_21 ( & V_44 -> V_49 ) ;
if ( F_22 ( V_42 , 3 , 2 , 2 ) == - V_52 )
V_42 -> V_53 = 0 ;
if ( V_42 -> V_53 < 8 )
V_42 -> V_53 ++ ;
for ( V_48 = V_42 -> V_53 - 1 ; V_48 > 0 ; V_48 -- )
memcpy ( & V_42 -> V_54 [ V_48 ] , & V_42 -> V_54 [ V_48 - 1 ] , sizeof( V_42 -> V_54 [ 0 ] ) ) ;
V_42 -> V_54 [ 0 ] . V_55 = V_47 ;
V_42 -> V_54 [ 0 ] . V_56 = V_47 ;
V_42 -> V_54 [ 0 ] . V_57 = 0 ;
V_42 -> V_54 [ 0 ] . V_58 = 0 ;
V_42 -> V_54 [ 0 ] . V_59 = 1000 ;
memcpy ( V_42 -> V_54 [ 0 ] . V_60 , L_10 , 8 ) ;
F_23 ( V_42 -> V_54 [ 0 ] . V_60 , 8 ) ;
memcpy ( V_42 -> V_54 [ 0 ] . V_61 , L_11 , 16 ) ;
F_23 ( V_42 -> V_54 [ 0 ] . V_61 , 16 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_62 = ( V_2 -> V_13 -> V_14 . V_15 . V_16 [ 0 ] & 0xf0000000 ) >> 28 ;
int V_63 = V_2 -> V_13 -> V_14 . V_15 . V_16 [ 0 ] & 0xff ;
int V_64 = V_2 -> V_13 -> V_14 . V_15 . V_16 [ 1 ] & 0xffff ;
int V_3 = V_2 -> V_4 . V_5 -> V_6 >> 28 ;
int V_7 = ( ( V_2 -> V_4 . V_5 -> V_6 & 0x0fff0000 ) >> 16 ) ;
T_1 V_8 ;
unsigned long V_42 ;
V_2 -> V_11 . V_65 ++ ;
F_6 ( V_2 , 4 , L_12 , V_62 , V_63 , V_64 ) ;
V_8 = V_7 ;
if ( V_3 )
V_8 += V_2 -> V_13 -> V_14 . V_15 . V_16 [ V_3 ] ;
if ( V_8 & 0xfff && V_62 > 0 )
return F_2 ( V_2 , V_17 ) ;
switch ( V_62 ) {
case 0 :
V_2 -> V_13 -> V_14 . V_15 . V_16 [ 0 ] = 3 << 28 ;
V_2 -> V_4 . V_5 -> V_29 . V_32 &= ~ ( 3ul << 44 ) ;
return 0 ;
case 1 :
case 2 :
V_42 = F_25 ( V_66 ) ;
if ( ! V_42 )
goto V_67;
if ( F_22 ( ( void * ) V_42 , V_62 , V_63 , V_64 ) == - V_52 )
goto V_68;
break;
case 3 :
if ( V_63 != 2 || V_64 != 2 )
goto V_67;
V_42 = F_25 ( V_66 ) ;
if ( ! V_42 )
goto V_67;
F_19 ( V_2 , ( void * ) V_42 ) ;
break;
default:
goto V_67;
}
if ( F_26 ( V_2 , V_8 , ( void * ) V_42 , V_20 ) ) {
F_2 ( V_2 , V_19 ) ;
goto V_68;
}
F_27 ( V_42 ) ;
V_2 -> V_4 . V_5 -> V_29 . V_32 &= ~ ( 3ul << 44 ) ;
V_2 -> V_13 -> V_14 . V_15 . V_16 [ 0 ] = 0 ;
return 0 ;
V_68:
F_27 ( V_42 ) ;
V_67:
V_2 -> V_4 . V_5 -> V_29 . V_32 |= 3ul << 44 ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 )
{
T_4 V_69 ;
V_69 = V_70 [ V_2 -> V_4 . V_5 -> V_71 & 0x00ff ] ;
if ( V_69 ) {
if ( V_2 -> V_4 . V_5 -> V_29 . V_32 & V_72 )
return F_2 ( V_2 ,
V_73 ) ;
else
return V_69 ( V_2 ) ;
}
return - V_74 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_75 = ( V_2 -> V_4 . V_5 -> V_6 & 0xf0000000 ) >> 28 ;
int V_76 = ( V_2 -> V_4 . V_5 -> V_6 & 0x0fff0000 ) >> 16 ;
int V_3 = ( V_2 -> V_4 . V_5 -> V_6 & 0xf000 ) >> 12 ;
int V_7 = V_2 -> V_4 . V_5 -> V_6 & 0x0fff ;
T_1 V_77 = V_76 + V_75 ? V_2 -> V_13 -> V_14 . V_15 . V_16 [ V_75 ] : 0 ;
T_1 V_78 = V_7 + V_3 ? V_2 -> V_13 -> V_14 . V_15 . V_16 [ V_3 ] : 0 ;
struct V_79 * V_80 ;
unsigned long V_81 ;
V_2 -> V_11 . V_82 ++ ;
if ( V_78 & 0xf0 )
return - V_74 ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_32 & V_83 )
return - V_74 ;
V_81 = ( unsigned long ) F_30 ( V_2 , V_77 ) ;
F_31 ( & V_84 -> V_85 -> V_86 ) ;
V_80 = F_32 ( V_84 -> V_85 , V_81 ) ;
if ( ! V_80 ) {
F_33 ( & V_84 -> V_85 -> V_86 ) ;
return F_2 ( V_2 , V_19 ) ;
}
V_2 -> V_4 . V_5 -> V_29 . V_32 &= ~ ( 3ul << 44 ) ;
if ( ! ( V_80 -> V_87 & V_88 ) && ( V_80 -> V_87 & V_89 ) )
V_2 -> V_4 . V_5 -> V_29 . V_32 |= ( 1ul << 44 ) ;
if ( ! ( V_80 -> V_87 & V_88 ) && ! ( V_80 -> V_87 & V_89 ) )
V_2 -> V_4 . V_5 -> V_29 . V_32 |= ( 2ul << 44 ) ;
F_33 ( & V_84 -> V_85 -> V_86 ) ;
return 0 ;
}
int F_34 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_4 . V_5 -> V_71 & 0x00ff ) == 0x01 )
return F_29 ( V_2 ) ;
return - V_74 ;
}
