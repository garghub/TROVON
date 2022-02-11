static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_2 V_4 = 0 ;
T_3 V_5 ;
V_2 -> V_6 . V_7 ++ ;
V_3 = F_2 ( V_2 ) ;
if ( V_3 & 3 )
return F_3 ( V_2 , V_8 ) ;
if ( F_4 ( V_2 , V_4 , ( T_2 V_9 * ) V_3 ) )
return F_3 ( V_2 , V_10 ) ;
V_4 = V_4 & 0x7fffe000u ;
if ( F_5 ( V_2 , & V_5 , V_4 , 1 ) ||
( F_5 ( V_2 , & V_5 , V_4 + V_11 , 1 ) ) )
return F_3 ( V_2 , V_10 ) ;
F_6 ( V_2 , V_4 ) ;
F_7 ( V_2 , 5 , L_1 , V_4 ) ;
F_8 ( V_2 , 1 , V_4 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_2 V_4 ;
V_2 -> V_6 . V_12 ++ ;
V_3 = F_2 ( V_2 ) ;
if ( V_3 & 3 )
return F_3 ( V_2 , V_8 ) ;
V_4 = V_2 -> V_13 . V_14 -> V_15 ;
V_4 = V_4 & 0x7fffe000u ;
if ( F_10 ( V_2 , V_4 , ( T_2 V_9 * ) V_3 ) )
return F_3 ( V_2 , V_10 ) ;
F_7 ( V_2 , 5 , L_2 , V_4 ) ;
F_8 ( V_2 , 0 , V_4 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
T_1 V_16 ;
V_2 -> V_6 . V_17 ++ ;
V_16 = F_2 ( V_2 ) ;
if ( V_16 & 1 )
return F_3 ( V_2 , V_8 ) ;
if ( F_10 ( V_2 , V_2 -> V_18 , ( V_19 V_9 * ) V_16 ) )
return F_3 ( V_2 , V_10 ) ;
F_7 ( V_2 , 5 , L_3 , V_16 ) ;
F_12 ( V_2 , V_16 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
V_2 -> V_6 . V_20 ++ ;
V_2 -> V_13 . V_14 -> V_21 . V_22 -= 4 ;
F_7 ( V_2 , 4 , L_4 , L_5 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_23 * V_24 ;
T_1 V_22 ;
int V_25 ;
V_22 = F_2 ( V_2 ) ;
if ( V_22 & 3 )
return F_3 ( V_2 , V_8 ) ;
V_25 = 0 ;
V_24 = F_15 ( V_2 -> V_26 , V_2 -> V_27 -> V_28 . V_29 . V_30 [ 6 ] , 0 ) ;
if ( ! V_24 )
goto V_31;
V_25 = 1 ;
if ( V_22 ) {
F_10 ( V_2 , V_24 -> V_32 . V_33 , ( V_19 V_9 * ) V_22 ) ;
F_10 ( V_2 , V_24 -> V_32 . V_34 , ( V_19 V_9 * ) ( V_22 + 2 ) ) ;
F_10 ( V_2 , V_24 -> V_32 . V_35 , ( T_2 V_9 * ) ( V_22 + 4 ) ) ;
} else {
F_10 ( V_2 , V_24 -> V_32 . V_33 , ( V_19 V_9 * ) V_36 ) ;
F_10 ( V_2 , V_24 -> V_32 . V_34 , ( V_19 V_9 * ) V_37 ) ;
F_10 ( V_2 , V_24 -> V_32 . V_35 , ( T_2 V_9 * ) V_38 ) ;
F_10 ( V_2 , V_24 -> V_32 . V_39 , ( T_2 V_9 * ) V_40 ) ;
}
F_16 ( V_24 ) ;
V_31:
V_2 -> V_13 . V_14 -> V_21 . V_41 &= ~ ( 3ul << 44 ) ;
V_2 -> V_13 . V_14 -> V_21 . V_41 |= ( V_25 & 3ul ) << 44 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_23 * V_24 ;
V_24 = F_15 ( V_2 -> V_26 , 0 ,
V_2 -> V_27 -> V_28 . V_29 . V_42 [ 1 ] ) ;
V_2 -> V_27 -> V_43 = V_44 ;
V_2 -> V_27 -> V_45 . V_46 = ! ! V_24 ;
if ( V_24 ) {
V_2 -> V_27 -> V_45 . V_33 = V_24 -> V_32 . V_33 ;
V_2 -> V_27 -> V_45 . V_34 = V_24 -> V_32 . V_34 ;
V_2 -> V_27 -> V_45 . V_35 = V_24 -> V_32 . V_35 ;
V_2 -> V_27 -> V_45 . V_39 = V_24 -> V_32 . V_39 ;
}
V_2 -> V_27 -> V_45 . V_47 = V_2 -> V_13 . V_14 -> V_47 ;
F_16 ( V_24 ) ;
return - V_48 ;
}
static int F_18 ( struct V_1 * V_2 )
{
F_7 ( V_2 , 4 , L_4 , L_6 ) ;
if ( V_2 -> V_26 -> V_13 . V_49 ) {
if ( V_2 -> V_13 . V_14 -> V_50 == 0xb236 )
return F_14 ( V_2 ) ;
if ( V_2 -> V_13 . V_14 -> V_50 == 0xb235 )
return F_17 ( V_2 ) ;
return - V_51 ;
} else {
V_2 -> V_13 . V_14 -> V_21 . V_41 &= ~ ( 3ul << 44 ) ;
V_2 -> V_13 . V_14 -> V_21 . V_41 |= ( 3 & 3ul ) << 44 ;
return 0 ;
}
}
static int F_19 ( struct V_1 * V_2 )
{
unsigned int V_52 ;
int V_53 ;
V_2 -> V_6 . V_54 ++ ;
V_52 = V_55 . V_56 & 0xff00fff3 ;
V_53 = F_20 ( V_2 , F_21 ( struct V_57 , V_56 ) ,
& V_52 , sizeof( V_52 ) ) ;
if ( V_53 )
return F_3 ( V_2 , V_10 ) ;
F_7 ( V_2 , 5 , L_7 , V_52 ) ;
F_22 ( V_2 , V_52 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 . V_14 -> V_21 . V_41 & V_58 )
F_24 ( V_2 ) ;
}
static int F_25 ( T_4 * V_59 ) {
if ( V_59 -> V_41 & V_60 )
return 0 ;
if ( ( V_59 -> V_41 & V_61 ) == V_62 ) {
if ( V_59 -> V_22 & ~ V_63 )
return 0 ;
}
if ( ! ( V_59 -> V_41 & V_61 ) && ( V_59 -> V_22 & ~ V_64 ) )
return 0 ;
if ( ( V_59 -> V_41 & V_61 ) == V_65 )
return 0 ;
return 1 ;
}
int F_26 ( struct V_1 * V_2 )
{
T_4 * V_21 = & V_2 -> V_13 . V_14 -> V_21 ;
T_5 V_66 ;
T_1 V_22 ;
if ( V_21 -> V_41 & V_67 )
return F_3 ( V_2 ,
V_68 ) ;
V_22 = F_2 ( V_2 ) ;
if ( V_22 & 7 )
return F_3 ( V_2 , V_8 ) ;
if ( F_27 ( V_2 , & V_66 , V_22 , sizeof( V_66 ) ) )
return F_3 ( V_2 , V_10 ) ;
if ( ! ( V_66 . V_41 & V_69 ) )
return F_3 ( V_2 , V_8 ) ;
V_21 -> V_41 = ( V_66 . V_41 & ~ V_69 ) << 32 ;
V_21 -> V_41 |= V_66 . V_22 & V_70 ;
V_21 -> V_22 = V_66 . V_22 & ~ V_70 ;
if ( ! F_25 ( V_21 ) )
return F_3 ( V_2 , V_8 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
T_4 V_66 ;
T_1 V_22 ;
V_22 = F_2 ( V_2 ) ;
if ( V_22 & 7 )
return F_3 ( V_2 , V_8 ) ;
if ( F_27 ( V_2 , & V_66 , V_22 , sizeof( V_66 ) ) )
return F_3 ( V_2 , V_10 ) ;
V_2 -> V_13 . V_14 -> V_21 = V_66 ;
if ( ! F_25 ( & V_2 -> V_13 . V_14 -> V_21 ) )
return F_3 ( V_2 , V_8 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_2 -> V_6 . V_71 ++ ;
V_3 = F_2 ( V_2 ) ;
if ( V_3 & 7 )
return F_3 ( V_2 , V_8 ) ;
if ( F_10 ( V_2 , V_2 -> V_13 . V_72 , ( T_1 V_9 * ) V_3 ) )
return F_3 ( V_2 , V_10 ) ;
F_7 ( V_2 , 5 , L_4 , L_8 ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 , struct V_73 * V_74 )
{
struct V_75 * V_76 = & V_2 -> V_26 -> V_13 . V_77 ;
int V_78 = 0 ;
int V_79 ;
F_31 ( & V_76 -> V_80 ) ;
for ( V_79 = 0 ; V_79 < V_81 ; V_79 ++ )
if ( V_76 -> V_82 [ V_79 ] )
V_78 ++ ;
F_32 ( & V_76 -> V_80 ) ;
if ( F_33 ( V_74 , 3 , 2 , 2 ) )
V_74 -> V_83 = 0 ;
if ( V_74 -> V_83 < 8 )
V_74 -> V_83 ++ ;
for ( V_79 = V_74 -> V_83 - 1 ; V_79 > 0 ; V_79 -- )
memcpy ( & V_74 -> V_84 [ V_79 ] , & V_74 -> V_84 [ V_79 - 1 ] , sizeof( V_74 -> V_84 [ 0 ] ) ) ;
V_74 -> V_84 [ 0 ] . V_85 = V_78 ;
V_74 -> V_84 [ 0 ] . V_86 = V_78 ;
V_74 -> V_84 [ 0 ] . V_87 = 0 ;
V_74 -> V_84 [ 0 ] . V_88 = 0 ;
V_74 -> V_84 [ 0 ] . V_89 = 1000 ;
memcpy ( V_74 -> V_84 [ 0 ] . V_90 , L_9 , 8 ) ;
F_34 ( V_74 -> V_84 [ 0 ] . V_90 , 8 ) ;
memcpy ( V_74 -> V_84 [ 0 ] . V_91 , L_10 , 16 ) ;
F_34 ( V_74 -> V_84 [ 0 ] . V_91 , 16 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_92 = ( V_2 -> V_27 -> V_28 . V_29 . V_42 [ 0 ] & 0xf0000000 ) >> 28 ;
int V_93 = V_2 -> V_27 -> V_28 . V_29 . V_42 [ 0 ] & 0xff ;
int V_94 = V_2 -> V_27 -> V_28 . V_29 . V_42 [ 1 ] & 0xffff ;
unsigned long V_74 = 0 ;
T_1 V_3 ;
int V_53 = 0 ;
V_2 -> V_6 . V_95 ++ ;
F_7 ( V_2 , 4 , L_11 , V_92 , V_93 , V_94 ) ;
V_3 = F_2 ( V_2 ) ;
if ( V_3 & 0xfff && V_92 > 0 )
return F_3 ( V_2 , V_8 ) ;
switch ( V_92 ) {
case 0 :
V_2 -> V_27 -> V_28 . V_29 . V_42 [ 0 ] = 3 << 28 ;
V_2 -> V_13 . V_14 -> V_21 . V_41 &= ~ ( 3ul << 44 ) ;
return 0 ;
case 1 :
case 2 :
V_74 = F_36 ( V_96 ) ;
if ( ! V_74 )
goto V_97;
if ( F_33 ( ( void * ) V_74 , V_92 , V_93 , V_94 ) )
goto V_97;
break;
case 3 :
if ( V_93 != 2 || V_94 != 2 )
goto V_97;
V_74 = F_36 ( V_96 ) ;
if ( ! V_74 )
goto V_97;
F_30 ( V_2 , ( void * ) V_74 ) ;
break;
default:
goto V_97;
}
if ( F_37 ( V_2 , V_3 , ( void * ) V_74 , V_11 ) ) {
V_53 = F_3 ( V_2 , V_10 ) ;
goto V_98;
}
F_38 ( V_2 , V_92 , V_93 , V_94 , V_3 ) ;
F_39 ( V_74 ) ;
V_2 -> V_13 . V_14 -> V_21 . V_41 &= ~ ( 3ul << 44 ) ;
V_2 -> V_27 -> V_28 . V_29 . V_42 [ 0 ] = 0 ;
return 0 ;
V_97:
V_2 -> V_13 . V_14 -> V_21 . V_41 |= 3ul << 44 ;
V_98:
F_39 ( V_74 ) ;
return V_53 ;
}
int F_40 ( struct V_1 * V_2 )
{
T_6 V_99 ;
V_99 = V_100 [ V_2 -> V_13 . V_14 -> V_50 & 0x00ff ] ;
if ( V_99 ) {
if ( V_2 -> V_13 . V_14 -> V_21 . V_41 & V_67 )
return F_3 ( V_2 ,
V_68 ) ;
else
return V_99 ( V_2 ) ;
}
return - V_51 ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_101 , V_102 ;
V_101 = ( V_2 -> V_13 . V_14 -> V_47 & 0x00f00000 ) >> 24 ;
V_102 = ( V_2 -> V_13 . V_14 -> V_47 & 0x000f0000 ) >> 16 ;
V_2 -> V_27 -> V_28 . V_29 . V_42 [ V_101 ] &= 0xffffffff00000000 ;
V_2 -> V_27 -> V_28 . V_29 . V_42 [ V_101 ] |= V_2 -> V_13 . V_14 -> V_21 . V_41 >> 32 ;
if ( V_102 ) {
V_2 -> V_27 -> V_28 . V_29 . V_42 [ V_102 ] &= 0xffffffff00000000 ;
V_2 -> V_27 -> V_28 . V_29 . V_42 [ V_102 ] |=
V_2 -> V_13 . V_14 -> V_21 . V_41 & 0x00000000ffffffff ;
}
return 0 ;
}
int F_42 ( struct V_1 * V_2 )
{
T_6 V_99 ;
V_99 = V_103 [ V_2 -> V_13 . V_14 -> V_50 & 0x00ff ] ;
if ( V_99 ) {
if ( ( V_99 != F_41 ) &&
( V_2 -> V_13 . V_14 -> V_21 . V_41 & V_67 ) )
return F_3 ( V_2 ,
V_68 ) ;
else
return V_99 ( V_2 ) ;
}
return - V_51 ;
}
int F_43 ( struct V_1 * V_2 )
{
T_6 V_99 ;
if ( V_2 -> V_13 . V_14 -> V_21 . V_41 & V_67 )
return F_3 ( V_2 ,
V_68 ) ;
V_99 = V_104 [ V_2 -> V_13 . V_14 -> V_47 & 0xff ] ;
if ( V_99 )
return V_99 ( V_2 ) ;
return - V_51 ;
}
static int F_44 ( struct V_1 * V_2 )
{
T_1 V_105 , V_106 ;
struct V_107 * V_108 ;
unsigned long V_109 ;
V_2 -> V_6 . V_110 ++ ;
F_45 ( V_2 , & V_105 , & V_106 ) ;
if ( V_106 & 0xf0 )
return - V_51 ;
if ( V_2 -> V_13 . V_14 -> V_21 . V_41 & V_111 )
return - V_51 ;
F_46 ( & V_112 -> V_113 -> V_114 ) ;
V_109 = F_47 ( V_105 , V_2 -> V_13 . V_115 ) ;
if ( F_48 ( V_109 ) )
goto V_116;
V_108 = F_49 ( V_112 -> V_113 , V_109 ) ;
if ( ! V_108 )
goto V_116;
V_2 -> V_13 . V_14 -> V_21 . V_41 &= ~ ( 3ul << 44 ) ;
if ( ! ( V_108 -> V_117 & V_118 ) && ( V_108 -> V_117 & V_119 ) )
V_2 -> V_13 . V_14 -> V_21 . V_41 |= ( 1ul << 44 ) ;
if ( ! ( V_108 -> V_117 & V_118 ) && ! ( V_108 -> V_117 & V_119 ) )
V_2 -> V_13 . V_14 -> V_21 . V_41 |= ( 2ul << 44 ) ;
F_50 ( & V_112 -> V_113 -> V_114 ) ;
return 0 ;
V_116:
F_50 ( & V_112 -> V_113 -> V_114 ) ;
return F_3 ( V_2 , V_10 ) ;
}
int F_51 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_13 . V_14 -> V_50 & 0x00ff ) == 0x01 )
return F_44 ( V_2 ) ;
return - V_51 ;
}
static int F_52 ( struct V_1 * V_2 )
{
T_2 V_120 ;
if ( V_2 -> V_13 . V_14 -> V_21 . V_41 & V_67 )
return F_3 ( V_2 ,
V_68 ) ;
if ( V_2 -> V_27 -> V_28 . V_29 . V_42 [ 0 ] & 0x00000000ffff0000 )
return F_3 ( V_2 ,
V_8 ) ;
V_120 = V_2 -> V_27 -> V_28 . V_29 . V_42 [ 0 ] & 0x000000000000ffff ;
V_2 -> V_13 . V_14 -> V_121 = V_120 ;
return 0 ;
}
int F_53 ( struct V_1 * V_2 )
{
T_6 V_99 ;
V_99 = V_122 [ V_2 -> V_13 . V_14 -> V_50 & 0x00ff ] ;
if ( V_99 )
return V_99 ( V_2 ) ;
return - V_51 ;
}
