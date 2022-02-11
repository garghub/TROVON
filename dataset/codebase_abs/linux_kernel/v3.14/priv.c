static int F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 ;
T_1 V_4 , V_5 ;
T_2 V_6 ;
int V_7 ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
V_6 = F_3 ( V_2 ) ;
if ( V_6 & 7 )
return F_2 ( V_2 , V_14 ) ;
if ( F_4 ( V_2 , V_5 , ( T_2 V_15 * ) V_6 ) )
return F_2 ( V_2 , V_16 ) ;
if ( F_5 ( & V_4 ) ) {
F_6 ( V_2 , 3 ) ;
return 0 ;
}
V_5 = ( V_5 - V_4 ) & ~ 0x3fUL ;
F_7 ( & V_2 -> V_17 -> V_18 ) ;
F_8 (i, cpup, vcpu->kvm)
V_3 -> V_8 . V_9 -> V_19 = V_5 ;
F_9 ( & V_2 -> V_17 -> V_18 ) ;
F_6 ( V_2 , 0 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
T_2 V_20 ;
T_3 V_21 = 0 ;
T_4 V_22 ;
V_2 -> V_23 . V_24 ++ ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
V_20 = F_3 ( V_2 ) ;
if ( V_20 & 3 )
return F_2 ( V_2 , V_14 ) ;
if ( F_4 ( V_2 , V_21 , ( T_3 V_15 * ) V_20 ) )
return F_2 ( V_2 , V_16 ) ;
V_21 = V_21 & 0x7fffe000u ;
if ( F_11 ( V_2 , & V_22 , V_21 , 1 ) ||
( F_11 ( V_2 , & V_22 , V_21 + V_25 , 1 ) ) )
return F_2 ( V_2 , V_16 ) ;
F_12 ( V_2 , V_21 ) ;
F_13 ( V_2 , 5 , L_1 , V_21 ) ;
F_14 ( V_2 , 1 , V_21 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
T_2 V_20 ;
T_3 V_21 ;
V_2 -> V_23 . V_26 ++ ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
V_20 = F_3 ( V_2 ) ;
if ( V_20 & 3 )
return F_2 ( V_2 , V_14 ) ;
V_21 = V_2 -> V_8 . V_9 -> V_27 ;
V_21 = V_21 & 0x7fffe000u ;
if ( F_16 ( V_2 , V_21 , ( T_3 V_15 * ) V_20 ) )
return F_2 ( V_2 , V_16 ) ;
F_13 ( V_2 , 5 , L_2 , V_21 ) ;
F_14 ( V_2 , 0 , V_21 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
T_2 V_28 ;
V_2 -> V_23 . V_29 ++ ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
V_28 = F_3 ( V_2 ) ;
if ( V_28 & 1 )
return F_2 ( V_2 , V_14 ) ;
if ( F_16 ( V_2 , V_2 -> V_30 , ( V_31 V_15 * ) V_28 ) )
return F_2 ( V_2 , V_16 ) ;
F_13 ( V_2 , 5 , L_3 , V_28 ) ;
F_18 ( V_2 , V_28 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
V_2 -> V_23 . V_32 ++ ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
V_2 -> V_8 . V_9 -> V_10 . V_33 =
F_20 ( V_2 -> V_8 . V_9 -> V_10 , 4 ) ;
F_13 ( V_2 , 4 , L_4 , L_5 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
unsigned long V_34 ;
T_5 V_33 ;
int V_35 ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
F_22 ( V_2 , NULL , & V_35 ) ;
V_33 = V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_35 ] & V_40 ;
V_33 = F_23 ( V_2 , V_33 ) ;
V_34 = F_24 ( V_2 -> V_17 , F_25 ( V_33 ) ) ;
if ( F_26 ( V_34 ) )
return F_2 ( V_2 , V_16 ) ;
if ( F_27 ( ( void V_15 * ) V_34 , V_25 ) != 0 )
return - V_41 ;
F_6 ( V_2 , 0 ) ;
V_2 -> V_36 -> V_37 . V_38 . V_39 [ 0 ] = 0 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_42 * V_43 ;
T_2 V_33 ;
int V_44 ;
V_33 = F_3 ( V_2 ) ;
if ( V_33 & 3 )
return F_2 ( V_2 , V_14 ) ;
V_44 = 0 ;
V_43 = F_29 ( V_2 -> V_17 , V_2 -> V_8 . V_9 -> V_45 [ 6 ] , 0 ) ;
if ( ! V_43 )
goto V_46;
V_44 = 1 ;
if ( V_33 ) {
if ( F_16 ( V_2 , V_43 -> V_47 . V_48 , ( V_31 V_15 * ) V_33 )
|| F_16 ( V_2 , V_43 -> V_47 . V_49 , ( V_31 V_15 * ) ( V_33 + 2 ) )
|| F_16 ( V_2 , V_43 -> V_47 . V_50 , ( T_3 V_15 * ) ( V_33 + 4 ) ) )
return F_2 ( V_2 , V_16 ) ;
} else {
F_16 ( V_2 , V_43 -> V_47 . V_48 , ( V_31 V_15 * ) V_51 ) ;
F_16 ( V_2 , V_43 -> V_47 . V_49 , ( V_31 V_15 * ) V_52 ) ;
F_16 ( V_2 , V_43 -> V_47 . V_50 , ( T_3 V_15 * ) V_53 ) ;
F_16 ( V_2 , V_43 -> V_47 . V_54 , ( T_3 V_15 * ) V_55 ) ;
}
F_30 ( V_43 ) ;
V_46:
F_6 ( V_2 , V_44 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_42 * V_43 ;
V_43 = F_29 ( V_2 -> V_17 , 0 ,
V_2 -> V_36 -> V_37 . V_38 . V_39 [ 1 ] ) ;
V_2 -> V_36 -> V_56 = V_57 ;
V_2 -> V_36 -> V_58 . V_59 = ! ! V_43 ;
if ( V_43 ) {
V_2 -> V_36 -> V_58 . V_48 = V_43 -> V_47 . V_48 ;
V_2 -> V_36 -> V_58 . V_49 = V_43 -> V_47 . V_49 ;
V_2 -> V_36 -> V_58 . V_50 = V_43 -> V_47 . V_50 ;
V_2 -> V_36 -> V_58 . V_54 = V_43 -> V_47 . V_54 ;
}
V_2 -> V_36 -> V_58 . V_60 = V_2 -> V_8 . V_9 -> V_60 ;
F_30 ( V_43 ) ;
return - V_61 ;
}
static int F_32 ( struct V_1 * V_2 )
{
F_13 ( V_2 , 4 , L_4 , L_6 ) ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
if ( V_2 -> V_17 -> V_8 . V_62 ) {
if ( V_2 -> V_8 . V_9 -> V_63 == 0xb236 )
return F_28 ( V_2 ) ;
if ( V_2 -> V_8 . V_9 -> V_63 == 0xb235 )
return F_31 ( V_2 ) ;
return - V_64 ;
} else {
F_6 ( V_2 , 3 ) ;
return 0 ;
}
}
static int F_33 ( struct V_1 * V_2 )
{
int V_65 ;
V_2 -> V_23 . V_66 ++ ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
V_65 = F_34 ( V_2 , F_35 ( struct V_67 , V_68 ) ,
V_69 , 4 ) ;
if ( V_65 )
return F_2 ( V_2 , V_16 ) ;
F_13 ( V_2 , 5 , L_7 ,
* ( unsigned int * ) V_69 ) ;
F_36 ( V_2 , * ( unsigned int * ) V_69 ) ;
return 0 ;
}
static void F_37 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_70 )
F_38 ( V_2 ) ;
}
static int F_39 ( T_6 * V_71 ) {
if ( V_71 -> V_11 & V_72 )
return 0 ;
if ( ( V_71 -> V_11 & V_73 ) == V_74 ) {
if ( V_71 -> V_33 & ~ V_75 )
return 0 ;
}
if ( ! ( V_71 -> V_11 & V_73 ) && ( V_71 -> V_33 & ~ V_76 ) )
return 0 ;
if ( ( V_71 -> V_11 & V_73 ) == V_77 )
return 0 ;
return 1 ;
}
int F_40 ( struct V_1 * V_2 )
{
T_6 * V_10 = & V_2 -> V_8 . V_9 -> V_10 ;
T_7 V_78 ;
T_2 V_33 ;
if ( V_10 -> V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
V_33 = F_3 ( V_2 ) ;
if ( V_33 & 7 )
return F_2 ( V_2 , V_14 ) ;
if ( F_41 ( V_2 , & V_78 , V_33 , sizeof( V_78 ) ) )
return F_2 ( V_2 , V_16 ) ;
if ( ! ( V_78 . V_11 & V_79 ) )
return F_2 ( V_2 , V_14 ) ;
V_10 -> V_11 = ( V_78 . V_11 & ~ V_79 ) << 32 ;
V_10 -> V_11 |= V_78 . V_33 & V_80 ;
V_10 -> V_33 = V_78 . V_33 & ~ V_80 ;
if ( ! F_39 ( V_10 ) )
return F_2 ( V_2 , V_14 ) ;
F_37 ( V_2 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
T_6 V_78 ;
T_2 V_33 ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
V_33 = F_3 ( V_2 ) ;
if ( V_33 & 7 )
return F_2 ( V_2 , V_14 ) ;
if ( F_41 ( V_2 , & V_78 , V_33 , sizeof( V_78 ) ) )
return F_2 ( V_2 , V_16 ) ;
V_2 -> V_8 . V_9 -> V_10 = V_78 ;
if ( ! F_39 ( & V_2 -> V_8 . V_9 -> V_10 ) )
return F_2 ( V_2 , V_14 ) ;
F_37 ( V_2 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
T_2 V_20 ;
V_2 -> V_23 . V_81 ++ ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
V_20 = F_3 ( V_2 ) ;
if ( V_20 & 7 )
return F_2 ( V_2 , V_14 ) ;
if ( F_16 ( V_2 , V_2 -> V_8 . V_82 , ( T_2 V_15 * ) V_20 ) )
return F_2 ( V_2 , V_16 ) ;
F_13 ( V_2 , 5 , L_4 , L_8 ) ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 , struct V_83 * V_84 )
{
struct V_85 * V_86 = & V_2 -> V_17 -> V_8 . V_87 ;
int V_88 = 0 ;
int V_89 ;
F_45 ( & V_86 -> V_18 ) ;
for ( V_89 = 0 ; V_89 < V_90 ; V_89 ++ )
if ( V_86 -> V_91 [ V_89 ] )
V_88 ++ ;
F_46 ( & V_86 -> V_18 ) ;
if ( F_47 ( V_84 , 3 , 2 , 2 ) )
V_84 -> V_92 = 0 ;
if ( V_84 -> V_92 < 8 )
V_84 -> V_92 ++ ;
for ( V_89 = V_84 -> V_92 - 1 ; V_89 > 0 ; V_89 -- )
memcpy ( & V_84 -> V_93 [ V_89 ] , & V_84 -> V_93 [ V_89 - 1 ] , sizeof( V_84 -> V_93 [ 0 ] ) ) ;
V_84 -> V_93 [ 0 ] . V_94 = V_88 ;
V_84 -> V_93 [ 0 ] . V_95 = V_88 ;
V_84 -> V_93 [ 0 ] . V_96 = 0 ;
V_84 -> V_93 [ 0 ] . V_97 = 0 ;
V_84 -> V_93 [ 0 ] . V_98 = 1000 ;
memcpy ( V_84 -> V_93 [ 0 ] . V_99 , L_9 , 8 ) ;
F_48 ( V_84 -> V_93 [ 0 ] . V_99 , 8 ) ;
memcpy ( V_84 -> V_93 [ 0 ] . V_100 , L_10 , 16 ) ;
F_48 ( V_84 -> V_93 [ 0 ] . V_100 , 16 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_101 = ( V_2 -> V_36 -> V_37 . V_38 . V_39 [ 0 ] & 0xf0000000 ) >> 28 ;
int V_102 = V_2 -> V_36 -> V_37 . V_38 . V_39 [ 0 ] & 0xff ;
int V_103 = V_2 -> V_36 -> V_37 . V_38 . V_39 [ 1 ] & 0xffff ;
unsigned long V_84 = 0 ;
T_2 V_20 ;
int V_65 = 0 ;
V_2 -> V_23 . V_104 ++ ;
F_13 ( V_2 , 4 , L_11 , V_101 , V_102 , V_103 ) ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
if ( V_101 > 3 ) {
F_6 ( V_2 , 3 ) ;
return 0 ;
}
if ( V_2 -> V_36 -> V_37 . V_38 . V_39 [ 0 ] & 0x0fffff00
|| V_2 -> V_36 -> V_37 . V_38 . V_39 [ 1 ] & 0xffff0000 )
return F_2 ( V_2 , V_14 ) ;
if ( V_101 == 0 ) {
V_2 -> V_36 -> V_37 . V_38 . V_39 [ 0 ] = 3 << 28 ;
F_6 ( V_2 , 0 ) ;
return 0 ;
}
V_20 = F_3 ( V_2 ) ;
if ( V_20 & 0xfff )
return F_2 ( V_2 , V_14 ) ;
switch ( V_101 ) {
case 1 :
case 2 :
V_84 = F_50 ( V_105 ) ;
if ( ! V_84 )
goto V_106;
if ( F_47 ( ( void * ) V_84 , V_101 , V_102 , V_103 ) )
goto V_106;
break;
case 3 :
if ( V_102 != 2 || V_103 != 2 )
goto V_106;
V_84 = F_50 ( V_105 ) ;
if ( ! V_84 )
goto V_106;
F_44 ( V_2 , ( void * ) V_84 ) ;
break;
}
if ( F_51 ( V_2 , V_20 , ( void * ) V_84 , V_25 ) ) {
V_65 = F_2 ( V_2 , V_16 ) ;
goto V_107;
}
F_52 ( V_2 , V_101 , V_102 , V_103 , V_20 ) ;
F_53 ( V_84 ) ;
F_6 ( V_2 , 0 ) ;
V_2 -> V_36 -> V_37 . V_38 . V_39 [ 0 ] = 0 ;
return 0 ;
V_106:
F_6 ( V_2 , 3 ) ;
V_107:
F_53 ( V_84 ) ;
return V_65 ;
}
int F_54 ( struct V_1 * V_2 )
{
T_8 V_108 ;
V_108 = V_109 [ V_2 -> V_8 . V_9 -> V_63 & 0x00ff ] ;
if ( V_108 )
return V_108 ( V_2 ) ;
return - V_64 ;
}
static int F_55 ( struct V_1 * V_2 )
{
int V_110 , V_35 ;
F_22 ( V_2 , & V_110 , & V_35 ) ;
V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_110 ] &= 0xffffffff00000000UL ;
V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_110 ] |= V_2 -> V_8 . V_9 -> V_10 . V_11 >> 32 ;
if ( V_35 ) {
V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_35 ] &= 0xffffffff00000000UL ;
V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_35 ] |=
V_2 -> V_8 . V_9 -> V_10 . V_11 & 0x00000000ffffffffUL ;
}
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
int V_110 , V_35 ;
unsigned long V_111 , V_112 ;
V_2 -> V_23 . V_113 ++ ;
F_22 ( V_2 , & V_110 , & V_35 ) ;
if ( ! V_114 )
return F_2 ( V_2 , V_115 ) ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
if ( V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_110 ] & V_116 )
return F_2 ( V_2 , V_14 ) ;
if ( V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_110 ] & V_117 && ! F_57 ( 14 ) )
return F_2 ( V_2 , V_14 ) ;
if ( V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_110 ] & ( V_118 | V_119 ) )
return F_2 ( V_2 , V_14 ) ;
V_111 = V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_35 ] & V_40 ;
switch ( V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_110 ] & V_120 ) {
case 0x00000000 :
V_112 = ( V_111 + ( 1UL << 12 ) ) & ~ ( ( 1UL << 12 ) - 1 ) ;
break;
case 0x00001000 :
V_112 = ( V_111 + ( 1UL << 20 ) ) & ~ ( ( 1UL << 20 ) - 1 ) ;
break;
default:
return F_2 ( V_2 , V_14 ) ;
}
while ( V_111 < V_112 ) {
unsigned long V_28 ;
V_28 = F_58 ( V_111 , V_2 -> V_8 . V_121 ) ;
if ( F_59 ( ( void * ) V_28 ) )
return F_2 ( V_2 , V_16 ) ;
if ( V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_110 ] & V_122 ) {
if ( F_27 ( ( void V_15 * ) V_28 , V_25 ) )
return F_2 ( V_2 , V_16 ) ;
}
if ( V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_110 ] & V_123 ) {
if ( F_60 ( V_124 -> V_125 , V_28 ,
V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_110 ] & V_126 ,
V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_110 ] & V_117 ) )
return F_2 ( V_2 , V_16 ) ;
}
V_111 += V_25 ;
}
if ( V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_110 ] & V_120 )
V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_35 ] = V_112 ;
return 0 ;
}
int F_61 ( struct V_1 * V_2 )
{
T_8 V_108 ;
V_108 = V_127 [ V_2 -> V_8 . V_9 -> V_63 & 0x00ff ] ;
if ( V_108 )
return V_108 ( V_2 ) ;
return - V_64 ;
}
int F_62 ( struct V_1 * V_2 )
{
int V_110 = ( V_2 -> V_8 . V_9 -> V_63 & 0x00f0 ) >> 4 ;
int V_128 = V_2 -> V_8 . V_9 -> V_63 & 0x000f ;
T_2 V_28 ;
T_3 V_5 = 0 ;
int V_129 , V_65 ;
V_2 -> V_23 . V_130 ++ ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
V_28 = F_63 ( V_2 ) ;
if ( V_28 & 3 )
return F_2 ( V_2 , V_14 ) ;
F_13 ( V_2 , 5 , L_12 , V_110 , V_128 ,
V_28 ) ;
F_64 ( V_2 , 0 , V_110 , V_128 , V_28 ) ;
V_129 = V_110 ;
do {
V_65 = F_4 ( V_2 , V_5 , ( T_3 V_15 * ) V_28 ) ;
if ( V_65 )
return F_2 ( V_2 , V_16 ) ;
V_2 -> V_8 . V_9 -> V_45 [ V_129 ] &= 0xffffffff00000000ul ;
V_2 -> V_8 . V_9 -> V_45 [ V_129 ] |= V_5 ;
V_28 += 4 ;
if ( V_129 == V_128 )
break;
V_129 = ( V_129 + 1 ) % 16 ;
} while ( 1 );
return 0 ;
}
static int F_65 ( struct V_1 * V_2 )
{
int V_110 = ( V_2 -> V_8 . V_9 -> V_63 & 0x00f0 ) >> 4 ;
int V_128 = V_2 -> V_8 . V_9 -> V_63 & 0x000f ;
T_2 V_28 ;
int V_129 , V_65 ;
V_2 -> V_23 . V_131 ++ ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
V_28 = F_66 ( V_2 ) ;
if ( V_28 & 7 )
return F_2 ( V_2 , V_14 ) ;
V_129 = V_110 ;
F_13 ( V_2 , 5 , L_13 , V_110 , V_128 ,
V_28 ) ;
F_64 ( V_2 , 1 , V_110 , V_128 , V_28 ) ;
do {
V_65 = F_4 ( V_2 , V_2 -> V_8 . V_9 -> V_45 [ V_129 ] ,
( T_2 V_15 * ) V_28 ) ;
if ( V_65 )
return F_2 ( V_2 , V_16 ) ;
V_28 += 8 ;
if ( V_129 == V_128 )
break;
V_129 = ( V_129 + 1 ) % 16 ;
} while ( 1 );
return 0 ;
}
int F_67 ( struct V_1 * V_2 )
{
T_8 V_108 ;
V_108 = V_132 [ V_2 -> V_8 . V_9 -> V_60 & 0xff ] ;
if ( V_108 )
return V_108 ( V_2 ) ;
return - V_64 ;
}
static int F_68 ( struct V_1 * V_2 )
{
T_2 V_133 , V_134 ;
struct V_135 * V_136 ;
unsigned long V_137 ;
V_2 -> V_23 . V_138 ++ ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
F_69 ( V_2 , & V_133 , & V_134 ) ;
if ( V_134 & 0xf0 )
return - V_64 ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_139 )
return - V_64 ;
F_70 ( & V_124 -> V_125 -> V_140 ) ;
V_137 = F_71 ( V_133 , V_2 -> V_8 . V_121 ) ;
if ( F_72 ( V_137 ) )
goto V_141;
V_136 = F_73 ( V_124 -> V_125 , V_137 ) ;
if ( ! V_136 )
goto V_141;
V_2 -> V_8 . V_9 -> V_10 . V_11 &= ~ ( 3ul << 44 ) ;
if ( ! ( V_136 -> V_142 & V_143 ) && ( V_136 -> V_142 & V_144 ) )
V_2 -> V_8 . V_9 -> V_10 . V_11 |= ( 1ul << 44 ) ;
if ( ! ( V_136 -> V_142 & V_143 ) && ! ( V_136 -> V_142 & V_144 ) )
V_2 -> V_8 . V_9 -> V_10 . V_11 |= ( 2ul << 44 ) ;
F_74 ( & V_124 -> V_125 -> V_140 ) ;
return 0 ;
V_141:
F_74 ( & V_124 -> V_125 -> V_140 ) ;
return F_2 ( V_2 , V_16 ) ;
}
int F_75 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_8 . V_9 -> V_63 & 0x00ff ) == 0x01 )
return F_68 ( V_2 ) ;
return - V_64 ;
}
static int F_76 ( struct V_1 * V_2 )
{
T_3 V_145 ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
if ( V_2 -> V_36 -> V_37 . V_38 . V_39 [ 0 ] & 0x00000000ffff0000 )
return F_2 ( V_2 ,
V_14 ) ;
V_145 = V_2 -> V_36 -> V_37 . V_38 . V_39 [ 0 ] & 0x000000000000ffff ;
V_2 -> V_8 . V_9 -> V_146 = V_145 ;
return 0 ;
}
int F_77 ( struct V_1 * V_2 )
{
T_8 V_108 ;
V_108 = V_147 [ V_2 -> V_8 . V_9 -> V_63 & 0x00ff ] ;
if ( V_108 )
return V_108 ( V_2 ) ;
return - V_64 ;
}
