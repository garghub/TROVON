static int
F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_1 V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_7 ;
struct V_8 T_2 * V_9 ;
V_7 = V_2 -> V_10 ;
V_9 = (struct V_8 T_2 * ) V_7 -> V_10 . V_11 ;
if ( F_2 ( V_2 -> V_12 ) )
return 0 ;
V_3 = 0 ;
switch ( V_13 >> 20 ) {
case 4 :
V_3 |= ( 0x3ff << V_14 ) ;
break;
case 8 :
V_3 |= ( 0x3fe << V_14 ) ;
break;
case 16 :
V_3 |= ( 0x3fc << V_14 ) ;
break;
case 32 :
V_3 |= ( 0x3f8 << V_14 ) ;
break;
case 64 :
V_3 |= ( 0x3f0 << V_14 ) ;
break;
case 128 :
V_3 |= ( 0x3e0 << V_14 ) ;
break;
case 256 :
V_3 |= ( 0x3c0 << V_14 ) ;
break;
case 512 :
V_3 |= ( 0x380 << V_14 ) ;
break;
case 1024 :
V_3 |= ( 0x300 << V_14 ) ;
break;
case 2048 :
V_3 |= ( 0x200 << V_14 ) ;
break;
case 4096 :
V_3 |= ( 0x000 << V_14 ) ;
break;
default:
F_3 ( V_15 L_1
L_2 , V_16 , ( V_17 ) V_13 ) ;
return - 1 ;
}
if ( V_18 >= 16384 ) {
V_2 -> V_19 = 16384 ;
V_3 |= V_20 ;
} else {
V_2 -> V_19 = 4096 ;
}
V_2 -> V_21 = V_13 ;
V_2 -> V_22 = V_23 ;
V_2 -> V_24 =
V_2 -> V_21 / V_2 -> V_19 ;
V_3 |= ( V_25 | V_26 ) ;
V_3 |= V_2 -> V_22 ;
V_2 -> V_27 = V_2 -> V_24 * sizeof( T_1 ) ;
V_6 =
F_4 ( V_2 -> V_28 ,
V_29 | V_30 ,
F_5 ( V_2 -> V_27 ) ) ;
if ( ! V_6 ) {
F_3 ( V_15 L_3
L_4 ,
V_16 ,
V_2 -> V_27 ,
F_5 ( V_2 -> V_27 ) ) ;
return - V_31 ;
}
V_2 -> V_32 = F_6 ( V_6 ) ;
V_2 -> V_33 =
F_7 ( F_8 ( V_2 -> V_32 ) ) ;
V_4 = V_34 - V_23 ;
V_2 -> V_35 = V_34 ;
V_2 -> V_36 = V_37 ;
V_2 -> V_38 = V_4 / V_2 -> V_19 ;
V_2 -> V_39 =
V_2 -> V_33 + V_4 ;
V_2 -> V_40 =
& V_2 -> V_32 [ V_2 -> V_38 ] ;
V_2 -> V_41 =
V_2 -> V_36 / V_2 -> V_19 ;
V_2 -> V_42 =
F_9 ( V_2 -> V_41 / 8 , V_29 ) ;
if ( ! V_2 -> V_42 ) {
F_10 ( ( unsigned long ) V_2 -> V_32 ,
F_5 ( V_2 -> V_27 ) ) ;
return - 1 ;
}
V_4 = V_43 - V_23 ;
V_2 -> V_44 = V_43 ;
V_2 -> V_45 = V_46 ;
V_2 -> V_47 = V_4 / V_2 -> V_19 ;
V_2 -> V_48 =
V_2 -> V_33 + V_4 ;
V_2 -> V_49 =
& V_2 -> V_32 [ V_2 -> V_47 ] ;
V_2 -> V_50 =
V_2 -> V_45 / V_2 -> V_19 ;
F_11 ( & V_9 -> V_51 ,
V_52 ) ;
F_12 ( & V_9 -> V_53 , V_54 ) ;
F_11 ( & V_9 -> V_53 ,
( 0x2ull << V_55 ) ) ;
V_2 -> V_56 = 1 ;
F_12 ( & V_9 -> V_53 ,
( V_57 | V_58 ) ) ;
F_13 ( V_59 , & V_9 -> V_60 ) ;
F_13 ( V_59 , & V_9 -> V_61 ) ;
F_12 ( & V_9 -> V_62 , V_59 ) ;
F_13 ( V_3 , & V_9 -> V_63 ) ;
F_13 ( V_2 -> V_33 | 1 , & V_9 -> V_64 ) ;
return 0 ;
}
void
F_14 ( struct V_1 * V_2 )
{
int V_65 ;
T_3 V_66 ;
struct V_8 T_2 * V_67 ;
struct V_68 * V_69 ;
struct V_7 * V_70 ;
V_70 = V_2 -> V_10 ;
F_15 (pdev, tioca_kern->ca_devices, bus_list) {
if ( V_69 -> V_71 != ( V_72 << 8 ) )
continue;
V_65 = F_16 ( V_69 , V_73 ) ;
if ( ! V_65 )
return;
F_17 ( V_69 , V_65 + V_74 , & V_66 ) ;
if ( ! ( V_66 & V_75 ) )
return;
}
F_15 (pdev, tioca_kern->ca_devices, bus_list) {
if ( V_69 -> V_71 != ( V_72 << 8 ) )
continue;
V_65 = F_16 ( V_69 , V_73 ) ;
F_17 ( V_69 , V_65 + V_76 , & V_66 ) ;
V_66 |= V_77 ;
F_18 ( V_69 , V_65 + V_76 , V_66 ) ;
}
V_67 = (struct V_8 T_2 * ) V_70 -> V_10 . V_11 ;
F_11 ( & V_67 -> V_51 , V_78 ) ;
}
static T_1
F_19 ( unsigned long V_79 )
{
T_4 V_80 ;
V_80 = F_7 ( V_79 ) ;
F_20 ( ! V_80 ) ;
F_20 ( V_80 >> 54 ) ;
V_80 |= ( 1UL << 60 ) ;
return V_80 ;
}
static T_1
F_21 ( struct V_68 * V_69 , T_1 V_79 )
{
struct V_7 * V_7 ;
struct V_8 T_2 * V_9 ;
T_1 V_81 ;
T_4 V_80 ;
T_3 V_82 ;
T_1 V_83 ;
struct V_84 * V_84 = F_22 ( V_69 ) ;
V_7 = (struct V_7 * ) V_84 -> V_85 ;
V_9 = (struct V_8 T_2 * ) V_7 -> V_10 . V_11 ;
V_81 = F_7 ( V_79 ) ;
if ( ! V_81 )
return 0 ;
V_80 = ( T_4 ) ( V_81 & 0xffffffffffffUL ) ;
V_82 = V_81 >> 48 ;
if ( V_82 > 64 ) {
F_3 ( V_15 L_5
L_6 , V_16 , ( void * ) V_81 ) ;
return 0 ;
}
V_83 = F_23 ( & V_9 -> V_86 ) ;
if ( V_82 != ( V_83 >> V_87 ) ) {
F_3 ( V_15 L_7
L_8 ,
V_16 ,
V_82 , ( V_83 >> V_87 ) ) ;
return 0 ;
}
return V_80 ;
}
static T_4
F_24 ( struct V_68 * V_69 , unsigned long V_79 , T_5 V_88 )
{
int V_89 , V_90 , V_91 , V_92 , V_93 ;
T_1 V_94 , V_95 ;
struct V_7 * V_7 ;
struct V_1 * V_2 ;
T_4 V_80 = 0 ;
struct V_96 * V_97 ;
void * V_98 ;
unsigned long V_99 ;
struct V_84 * V_84 = F_22 ( V_69 ) ;
V_7 = (struct V_7 * ) V_84 -> V_85 ;
V_2 = (struct V_1 * ) V_7 -> V_100 ;
V_94 = F_7 ( V_79 ) ;
if ( ! V_94 )
return 0 ;
F_25 ( & V_2 -> V_101 , V_99 ) ;
V_97 = F_9 ( sizeof( struct V_96 ) , V_102 ) ;
if ( ! V_97 )
goto V_103;
V_89 = V_2 -> V_19 ;
V_90 = F_26 ( V_89 ) - 1 ;
V_95 = V_94 + V_88 - 1 ;
V_92 = ( V_95 >> V_90 ) - ( V_94 >> V_90 ) + 1 ;
V_98 = V_2 -> V_42 ;
V_93 = V_2 -> V_41 ;
V_91 = F_27 ( V_98 , V_93 , 0 , V_92 , 0 ) ;
if ( V_91 >= V_93 ) {
F_28 ( V_97 ) ;
goto V_103;
}
F_29 ( V_98 , V_91 , V_92 ) ;
V_80 = V_2 -> V_35 + ( V_91 * V_89 ) ;
V_97 -> V_104 = V_80 ;
V_97 -> V_105 = V_92 ;
V_97 -> V_106 = V_91 ;
F_30 ( & V_97 -> V_107 , & V_2 -> V_108 ) ;
if ( V_94 % V_89 ) {
V_2 -> V_40 [ V_91 ] = F_31 ( V_94 ) ;
V_80 += V_94 & ( V_89 - 1 ) ;
V_94 &= ~ ( V_89 - 1 ) ;
V_94 += V_89 ;
V_91 ++ ;
}
while ( V_94 < V_95 ) {
V_2 -> V_40 [ V_91 ] = F_31 ( V_94 ) ;
V_94 += V_89 ;
V_91 ++ ;
}
F_32 ( V_2 ) ;
V_103:
F_33 ( & V_2 -> V_101 , V_99 ) ;
return V_80 ;
}
static void
F_34 ( struct V_68 * V_69 , T_4 V_80 , int V_109 )
{
int V_110 , V_91 ;
struct V_7 * V_7 ;
struct V_1 * V_2 ;
struct V_96 * V_98 ;
struct V_84 * V_84 = F_22 ( V_69 ) ;
unsigned long V_99 ;
V_7 = (struct V_7 * ) V_84 -> V_85 ;
V_2 = (struct V_1 * ) V_7 -> V_100 ;
if ( V_80 < V_2 -> V_35 ||
V_80 >= ( V_2 -> V_35 + V_2 -> V_36 ) )
return;
F_25 ( & V_2 -> V_101 , V_99 ) ;
F_15 (map, &tioca_kern->ca_dmamaps, cad_list)
if ( V_98 -> V_104 == V_80 )
break;
F_20 ( V_98 == NULL ) ;
V_91 = V_98 -> V_106 ;
for ( V_110 = 0 ; V_110 < V_98 -> V_105 ; V_110 ++ , V_91 ++ ) {
F_35 ( V_91 , V_2 -> V_42 ) ;
V_2 -> V_40 [ V_91 ] = 0 ;
}
F_32 ( V_2 ) ;
F_36 ( & V_98 -> V_107 ) ;
F_33 ( & V_2 -> V_101 , V_99 ) ;
F_28 ( V_98 ) ;
}
static T_1
F_37 ( struct V_68 * V_69 , unsigned long V_79 , T_5 V_111 , int V_112 )
{
T_1 V_113 ;
if ( V_112 & V_114 )
return 0 ;
if ( V_69 -> V_115 == ~ 0UL )
V_113 = F_19 ( V_79 ) ;
else if ( V_69 -> V_115 == 0xffffffffffffUL )
V_113 = F_21 ( V_69 , V_79 ) ;
else
V_113 = 0 ;
if ( V_113 == 0 )
V_113 = F_24 ( V_69 , V_79 , V_111 ) ;
return V_113 ;
}
static T_6
F_38 ( int V_116 , void * V_117 )
{
struct V_7 * V_118 = V_117 ;
struct V_119 V_120 ;
T_1 V_121 ;
T_1 V_122 ;
V_120 . V_123 = 0 ;
V_120 . V_124 = 0 ;
V_121 = V_118 -> V_10 . V_125 ;
V_122 = V_118 -> V_10 . V_126 ;
F_39 ( V_120 ,
( T_1 ) V_127 ,
V_121 , V_122 , 0 , 0 , 0 , 0 , 0 ) ;
return V_128 ;
}
static void *
F_40 ( struct V_129 * V_130 , struct V_131 * V_132 )
{
struct V_7 * V_7 ;
struct V_1 * V_2 ;
struct V_133 * V_134 ;
if ( F_41 () && F_42 () < 0x0406 ) {
F_3
( V_15 L_9
L_10 , V_16 ) ;
return NULL ;
}
V_7 = F_9 ( sizeof( struct V_7 ) , V_29 ) ;
if ( ! V_7 )
return NULL ;
memcpy ( V_7 , V_130 , sizeof( struct V_7 ) ) ;
V_7 -> V_10 . V_11 = ( unsigned long )
F_43 ( F_44 ( V_7 -> V_10 . V_11 ) ,
sizeof( struct V_7 ) ) ;
V_2 = F_9 ( sizeof( struct V_1 ) , V_29 ) ;
if ( ! V_2 ) {
F_28 ( V_7 ) ;
return NULL ;
}
V_2 -> V_10 = V_7 ;
F_45 ( & V_2 -> V_101 ) ;
F_46 ( & V_2 -> V_108 ) ;
V_2 -> V_28 =
F_47 ( V_7 -> V_135 ) ;
V_7 -> V_100 = ( T_1 ) V_2 ;
V_134 = F_48 ( V_7 -> V_10 . V_125 ,
V_7 -> V_10 . V_126 ) ;
F_20 ( ! V_134 ) ;
V_2 -> V_12 = & V_134 -> V_136 ;
if ( F_1 ( V_2 ) < 0 ) {
F_28 ( V_2 ) ;
F_28 ( V_7 ) ;
return NULL ;
}
V_137 ++ ;
F_30 ( & V_2 -> V_138 , & V_139 ) ;
if ( F_49 ( V_140 ,
F_38 ,
V_141 , L_11 , ( void * ) V_7 ) )
F_3 ( V_142
L_12
L_13 ,
V_16 , V_140 ,
( int ) V_7 -> V_10 . V_126 ) ;
F_50 ( V_140 ) ;
V_132 -> V_143 = V_2 -> V_28 ;
return V_7 ;
}
int
F_51 ( void )
{
V_144 [ V_145 ] = & V_146 ;
return 0 ;
}
