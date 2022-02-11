static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_2 V_4 = 0 ;
T_3 V_5 ;
V_2 -> V_6 . V_7 ++ ;
V_3 = F_2 ( V_2 ) ;
if ( V_3 & 3 ) {
F_3 ( V_2 , V_8 ) ;
goto V_9;
}
if ( F_4 ( V_2 , V_3 , & V_4 ) ) {
F_3 ( V_2 , V_10 ) ;
goto V_9;
}
V_4 = V_4 & 0x7fffe000u ;
if ( F_5 ( V_2 , & V_5 , V_4 , 1 ) ||
( F_5 ( V_2 , & V_5 , V_4 + V_11 , 1 ) ) ) {
F_3 ( V_2 , V_10 ) ;
goto V_9;
}
F_6 ( V_2 , V_4 ) ;
F_7 ( V_2 , 5 , L_1 , V_4 ) ;
F_8 ( V_2 , 1 , V_4 ) ;
V_9:
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_2 V_4 ;
V_2 -> V_6 . V_12 ++ ;
V_3 = F_2 ( V_2 ) ;
if ( V_3 & 3 ) {
F_3 ( V_2 , V_8 ) ;
goto V_9;
}
V_4 = V_2 -> V_13 . V_14 -> V_15 ;
V_4 = V_4 & 0x7fffe000u ;
if ( F_10 ( V_2 , V_3 , V_4 ) ) {
F_3 ( V_2 , V_10 ) ;
goto V_9;
}
F_7 ( V_2 , 5 , L_2 , V_4 ) ;
F_8 ( V_2 , 0 , V_4 ) ;
V_9:
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
T_1 V_16 ;
int V_17 ;
V_2 -> V_6 . V_18 ++ ;
V_16 = F_2 ( V_2 ) ;
if ( V_16 & 1 ) {
F_3 ( V_2 , V_8 ) ;
goto V_9;
}
V_17 = F_12 ( V_2 , V_16 , V_2 -> V_19 ) ;
if ( V_17 == - V_20 ) {
F_3 ( V_2 , V_10 ) ;
goto V_9;
}
F_7 ( V_2 , 5 , L_3 , V_16 ) ;
F_13 ( V_2 , V_16 ) ;
V_9:
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
V_2 -> V_6 . V_21 ++ ;
V_2 -> V_13 . V_14 -> V_22 . V_23 -= 4 ;
F_7 ( V_2 , 4 , L_4 , L_5 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
T_1 V_23 ;
struct V_24 * V_25 ;
int V_26 ;
V_23 = F_2 ( V_2 ) ;
V_25 = F_16 ( V_2 -> V_27 , V_2 -> V_28 -> V_29 . V_30 . V_31 [ 6 ] , 0 ) ;
if ( V_25 ) {
if ( V_23 ) {
F_12 ( V_2 , V_23 , V_25 -> V_32 . V_33 ) ;
F_12 ( V_2 , V_23 + 2 , V_25 -> V_32 . V_34 ) ;
F_10 ( V_2 , V_23 + 4 , V_25 -> V_32 . V_35 ) ;
} else {
F_12 ( V_2 , 184 , V_25 -> V_32 . V_33 ) ;
F_12 ( V_2 , 186 , V_25 -> V_32 . V_34 ) ;
F_10 ( V_2 , 188 , V_25 -> V_32 . V_35 ) ;
F_10 ( V_2 , 192 , V_25 -> V_32 . V_36 ) ;
}
V_26 = 1 ;
} else
V_26 = 0 ;
F_17 ( V_25 ) ;
V_2 -> V_13 . V_14 -> V_22 . V_37 &= ~ ( 3ul << 44 ) ;
V_2 -> V_13 . V_14 -> V_22 . V_37 |= ( V_26 & 3ul ) << 44 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_24 * V_25 ;
V_25 = F_16 ( V_2 -> V_27 , 0 ,
V_2 -> V_28 -> V_29 . V_30 . V_38 [ 1 ] ) ;
V_2 -> V_28 -> V_39 = V_40 ;
V_2 -> V_28 -> V_41 . V_42 = ! ! V_25 ;
if ( V_25 ) {
V_2 -> V_28 -> V_41 . V_33 = V_25 -> V_32 . V_33 ;
V_2 -> V_28 -> V_41 . V_34 = V_25 -> V_32 . V_34 ;
V_2 -> V_28 -> V_41 . V_35 = V_25 -> V_32 . V_35 ;
V_2 -> V_28 -> V_41 . V_36 = V_25 -> V_32 . V_36 ;
}
V_2 -> V_28 -> V_41 . V_43 = V_2 -> V_13 . V_14 -> V_43 ;
F_17 ( V_25 ) ;
return - V_44 ;
}
static int F_19 ( struct V_1 * V_2 )
{
F_7 ( V_2 , 4 , L_4 , L_6 ) ;
if ( V_2 -> V_27 -> V_13 . V_45 ) {
if ( V_2 -> V_13 . V_14 -> V_46 == 0xb236 )
return F_15 ( V_2 ) ;
if ( V_2 -> V_13 . V_14 -> V_46 == 0xb235 )
return F_18 ( V_2 ) ;
return - V_47 ;
} else {
V_2 -> V_13 . V_14 -> V_22 . V_37 &= ~ ( 3ul << 44 ) ;
V_2 -> V_13 . V_14 -> V_22 . V_37 |= ( 3 & 3ul ) << 44 ;
return 0 ;
}
}
static int F_20 ( struct V_1 * V_2 )
{
unsigned int V_48 ;
int V_17 ;
V_2 -> V_6 . V_49 ++ ;
V_48 = V_50 . V_51 & 0xff00fff3 ;
V_17 = F_21 ( V_2 , F_22 ( struct V_52 , V_51 ) ,
& V_48 , sizeof( V_48 ) ) ;
if ( V_17 == - V_20 )
F_3 ( V_2 , V_10 ) ;
else {
F_7 ( V_2 , 5 , L_7 ,
V_48 ) ;
F_23 ( V_2 , V_48 ) ;
}
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 . V_14 -> V_22 . V_37 & V_53 )
F_25 ( V_2 ) ;
}
int F_26 ( struct V_1 * V_2 )
{
T_1 V_23 ;
T_4 V_54 ;
if ( V_2 -> V_13 . V_14 -> V_22 . V_37 & V_55 )
return F_3 ( V_2 ,
V_56 ) ;
V_23 = F_2 ( V_2 ) ;
if ( V_23 & 7 ) {
F_3 ( V_2 , V_8 ) ;
goto V_9;
}
if ( F_27 ( V_2 , & V_54 , V_23 , sizeof( V_54 ) ) ) {
F_3 ( V_2 , V_10 ) ;
goto V_9;
}
if ( ! ( V_54 . V_37 & V_57 ) ) {
F_3 ( V_2 , V_8 ) ;
goto V_9;
}
V_2 -> V_13 . V_14 -> V_22 . V_37 =
( V_54 . V_37 & ~ V_57 ) << 32 ;
V_2 -> V_13 . V_14 -> V_22 . V_23 = V_54 . V_23 ;
if ( ( V_2 -> V_13 . V_14 -> V_22 . V_37 & V_58 ) ||
( ! ( V_2 -> V_13 . V_14 -> V_22 . V_37 & V_59 ) &&
( V_2 -> V_13 . V_14 -> V_22 . V_23 & ~ V_60 ) ) ||
( ( V_2 -> V_13 . V_14 -> V_22 . V_37 & V_59 ) ==
V_61 ) ) {
F_3 ( V_2 , V_8 ) ;
goto V_9;
}
F_24 ( V_2 ) ;
V_9:
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
T_1 V_23 ;
T_5 V_54 ;
V_23 = F_2 ( V_2 ) ;
if ( V_23 & 7 ) {
F_3 ( V_2 , V_8 ) ;
goto V_9;
}
if ( F_27 ( V_2 , & V_54 , V_23 , sizeof( V_54 ) ) ) {
F_3 ( V_2 , V_10 ) ;
goto V_9;
}
V_2 -> V_13 . V_14 -> V_22 . V_37 = V_54 . V_37 ;
V_2 -> V_13 . V_14 -> V_22 . V_23 = V_54 . V_23 ;
if ( ( V_2 -> V_13 . V_14 -> V_22 . V_37 & V_58 ) ||
( ( ( V_2 -> V_13 . V_14 -> V_22 . V_37 & V_59 ) ==
V_62 ) &&
( V_2 -> V_13 . V_14 -> V_22 . V_23 & ~ V_63 ) ) ||
( ! ( V_2 -> V_13 . V_14 -> V_22 . V_37 & V_59 ) &&
( V_2 -> V_13 . V_14 -> V_22 . V_23 & ~ V_60 ) ) ||
( ( V_2 -> V_13 . V_14 -> V_22 . V_37 & V_59 ) ==
V_61 ) ) {
F_3 ( V_2 , V_8 ) ;
goto V_9;
}
F_24 ( V_2 ) ;
V_9:
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_17 ;
V_2 -> V_6 . V_64 ++ ;
V_3 = F_2 ( V_2 ) ;
if ( V_3 & 7 ) {
F_3 ( V_2 , V_8 ) ;
goto V_9;
}
V_17 = F_30 ( V_2 , V_3 , V_2 -> V_13 . V_65 ) ;
if ( V_17 == - V_20 ) {
F_3 ( V_2 , V_10 ) ;
goto V_9;
}
F_7 ( V_2 , 5 , L_4 , L_8 ) ;
V_9:
return 0 ;
}
static void F_31 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
struct V_68 * V_69 = & V_2 -> V_27 -> V_13 . V_70 ;
int V_71 = 0 ;
int V_72 ;
F_32 ( & V_69 -> V_73 ) ;
for ( V_72 = 0 ; V_72 < V_74 ; V_72 ++ )
if ( V_69 -> V_75 [ V_72 ] )
V_71 ++ ;
F_33 ( & V_69 -> V_73 ) ;
if ( F_34 ( V_67 , 3 , 2 , 2 ) )
V_67 -> V_76 = 0 ;
if ( V_67 -> V_76 < 8 )
V_67 -> V_76 ++ ;
for ( V_72 = V_67 -> V_76 - 1 ; V_72 > 0 ; V_72 -- )
memcpy ( & V_67 -> V_77 [ V_72 ] , & V_67 -> V_77 [ V_72 - 1 ] , sizeof( V_67 -> V_77 [ 0 ] ) ) ;
V_67 -> V_77 [ 0 ] . V_78 = V_71 ;
V_67 -> V_77 [ 0 ] . V_79 = V_71 ;
V_67 -> V_77 [ 0 ] . V_80 = 0 ;
V_67 -> V_77 [ 0 ] . V_81 = 0 ;
V_67 -> V_77 [ 0 ] . V_82 = 1000 ;
memcpy ( V_67 -> V_77 [ 0 ] . V_83 , L_9 , 8 ) ;
F_35 ( V_67 -> V_77 [ 0 ] . V_83 , 8 ) ;
memcpy ( V_67 -> V_77 [ 0 ] . V_84 , L_10 , 16 ) ;
F_35 ( V_67 -> V_77 [ 0 ] . V_84 , 16 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_85 = ( V_2 -> V_28 -> V_29 . V_30 . V_38 [ 0 ] & 0xf0000000 ) >> 28 ;
int V_86 = V_2 -> V_28 -> V_29 . V_30 . V_38 [ 0 ] & 0xff ;
int V_87 = V_2 -> V_28 -> V_29 . V_30 . V_38 [ 1 ] & 0xffff ;
T_1 V_3 ;
unsigned long V_67 ;
V_2 -> V_6 . V_88 ++ ;
F_7 ( V_2 , 4 , L_11 , V_85 , V_86 , V_87 ) ;
V_3 = F_2 ( V_2 ) ;
if ( V_3 & 0xfff && V_85 > 0 )
return F_3 ( V_2 , V_8 ) ;
switch ( V_85 ) {
case 0 :
V_2 -> V_28 -> V_29 . V_30 . V_38 [ 0 ] = 3 << 28 ;
V_2 -> V_13 . V_14 -> V_22 . V_37 &= ~ ( 3ul << 44 ) ;
return 0 ;
case 1 :
case 2 :
V_67 = F_37 ( V_89 ) ;
if ( ! V_67 )
goto V_90;
if ( F_34 ( ( void * ) V_67 , V_85 , V_86 , V_87 ) )
goto V_91;
break;
case 3 :
if ( V_86 != 2 || V_87 != 2 )
goto V_90;
V_67 = F_37 ( V_89 ) ;
if ( ! V_67 )
goto V_90;
F_31 ( V_2 , ( void * ) V_67 ) ;
break;
default:
goto V_90;
}
if ( F_38 ( V_2 , V_3 , ( void * ) V_67 , V_11 ) ) {
F_3 ( V_2 , V_10 ) ;
goto V_91;
}
F_39 ( V_2 , V_85 , V_86 , V_87 , V_3 ) ;
F_40 ( V_67 ) ;
V_2 -> V_13 . V_14 -> V_22 . V_37 &= ~ ( 3ul << 44 ) ;
V_2 -> V_28 -> V_29 . V_30 . V_38 [ 0 ] = 0 ;
return 0 ;
V_91:
F_40 ( V_67 ) ;
V_90:
V_2 -> V_13 . V_14 -> V_22 . V_37 |= 3ul << 44 ;
return 0 ;
}
int F_41 ( struct V_1 * V_2 )
{
T_6 V_92 ;
V_92 = V_93 [ V_2 -> V_13 . V_14 -> V_46 & 0x00ff ] ;
if ( V_92 ) {
if ( V_2 -> V_13 . V_14 -> V_22 . V_37 & V_55 )
return F_3 ( V_2 ,
V_56 ) ;
else
return V_92 ( V_2 ) ;
}
return - V_47 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_94 , V_95 ;
V_94 = ( V_2 -> V_13 . V_14 -> V_43 & 0x00f00000 ) >> 24 ;
V_95 = ( V_2 -> V_13 . V_14 -> V_43 & 0x000f0000 ) >> 16 ;
V_2 -> V_28 -> V_29 . V_30 . V_38 [ V_94 ] &= 0xffffffff00000000 ;
V_2 -> V_28 -> V_29 . V_30 . V_38 [ V_94 ] |= V_2 -> V_13 . V_14 -> V_22 . V_37 >> 32 ;
if ( V_95 ) {
V_2 -> V_28 -> V_29 . V_30 . V_38 [ V_95 ] &= 0xffffffff00000000 ;
V_2 -> V_28 -> V_29 . V_30 . V_38 [ V_95 ] |=
V_2 -> V_13 . V_14 -> V_22 . V_37 & 0x00000000ffffffff ;
}
return 0 ;
}
int F_43 ( struct V_1 * V_2 )
{
T_6 V_92 ;
V_92 = V_96 [ V_2 -> V_13 . V_14 -> V_46 & 0x00ff ] ;
if ( V_92 ) {
if ( ( V_92 != F_42 ) &&
( V_2 -> V_13 . V_14 -> V_22 . V_37 & V_55 ) )
return F_3 ( V_2 ,
V_56 ) ;
else
return V_92 ( V_2 ) ;
}
return - V_47 ;
}
int F_44 ( struct V_1 * V_2 )
{
T_6 V_92 ;
if ( V_2 -> V_13 . V_14 -> V_22 . V_37 & V_55 )
return F_3 ( V_2 ,
V_56 ) ;
V_92 = V_97 [ V_2 -> V_13 . V_14 -> V_43 & 0xff ] ;
if ( V_92 )
return V_92 ( V_2 ) ;
return - V_47 ;
}
static int F_45 ( struct V_1 * V_2 )
{
T_1 V_98 , V_99 ;
struct V_100 * V_101 ;
unsigned long V_102 ;
V_2 -> V_6 . V_103 ++ ;
F_46 ( V_2 , & V_98 , & V_99 ) ;
if ( V_99 & 0xf0 )
return - V_47 ;
if ( V_2 -> V_13 . V_14 -> V_22 . V_37 & V_104 )
return - V_47 ;
V_102 = ( unsigned long ) F_47 ( V_2 , V_98 ) ;
F_48 ( & V_105 -> V_106 -> V_107 ) ;
V_101 = F_49 ( V_105 -> V_106 , V_102 ) ;
if ( ! V_101 ) {
F_50 ( & V_105 -> V_106 -> V_107 ) ;
return F_3 ( V_2 , V_10 ) ;
}
V_2 -> V_13 . V_14 -> V_22 . V_37 &= ~ ( 3ul << 44 ) ;
if ( ! ( V_101 -> V_108 & V_109 ) && ( V_101 -> V_108 & V_110 ) )
V_2 -> V_13 . V_14 -> V_22 . V_37 |= ( 1ul << 44 ) ;
if ( ! ( V_101 -> V_108 & V_109 ) && ! ( V_101 -> V_108 & V_110 ) )
V_2 -> V_13 . V_14 -> V_22 . V_37 |= ( 2ul << 44 ) ;
F_50 ( & V_105 -> V_106 -> V_107 ) ;
return 0 ;
}
int F_51 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_13 . V_14 -> V_46 & 0x00ff ) == 0x01 )
return F_45 ( V_2 ) ;
return - V_47 ;
}
static int F_52 ( struct V_1 * V_2 )
{
T_2 V_111 ;
if ( V_2 -> V_13 . V_14 -> V_22 . V_37 & V_55 )
return F_3 ( V_2 ,
V_56 ) ;
if ( V_2 -> V_28 -> V_29 . V_30 . V_38 [ 0 ] & 0x00000000ffff0000 )
return F_3 ( V_2 ,
V_8 ) ;
V_111 = V_2 -> V_28 -> V_29 . V_30 . V_38 [ 0 ] & 0x000000000000ffff ;
V_2 -> V_13 . V_14 -> V_112 = V_111 ;
return 0 ;
}
int F_53 ( struct V_1 * V_2 )
{
T_6 V_92 ;
V_92 = V_113 [ V_2 -> V_13 . V_14 -> V_46 & 0x00ff ] ;
if ( V_92 )
return V_92 ( V_2 ) ;
return - V_47 ;
}
