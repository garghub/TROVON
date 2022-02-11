static int F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 ;
T_1 V_4 , V_5 ;
int V_6 , V_7 ;
T_2 V_8 ;
T_3 V_9 ;
if ( V_2 -> V_10 . V_11 -> V_12 . V_13 & V_14 )
return F_2 ( V_2 , V_15 ) ;
V_9 = F_3 ( V_2 , & V_8 ) ;
if ( V_9 & 7 )
return F_2 ( V_2 , V_16 ) ;
V_7 = F_4 ( V_2 , V_9 , V_8 , & V_5 , sizeof( V_5 ) ) ;
if ( V_7 )
return F_5 ( V_2 , V_7 ) ;
if ( F_6 ( & V_4 ) ) {
F_7 ( V_2 , 3 ) ;
return 0 ;
}
V_5 = ( V_5 - V_4 ) & ~ 0x3fUL ;
F_8 ( & V_2 -> V_17 -> V_18 ) ;
F_9 (i, cpup, vcpu->kvm)
V_3 -> V_10 . V_11 -> V_19 = V_5 ;
F_10 ( & V_2 -> V_17 -> V_18 ) ;
F_7 ( V_2 , 0 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
T_3 V_20 ;
T_4 V_21 ;
int V_7 ;
T_2 V_8 ;
V_2 -> V_22 . V_23 ++ ;
if ( V_2 -> V_10 . V_11 -> V_12 . V_13 & V_14 )
return F_2 ( V_2 , V_15 ) ;
V_20 = F_3 ( V_2 , & V_8 ) ;
if ( V_20 & 3 )
return F_2 ( V_2 , V_16 ) ;
V_7 = F_4 ( V_2 , V_20 , V_8 , & V_21 , sizeof( V_21 ) ) ;
if ( V_7 )
return F_5 ( V_2 , V_7 ) ;
V_21 &= 0x7fffe000u ;
if ( F_12 ( V_2 -> V_17 , V_21 ) )
return F_2 ( V_2 , V_24 ) ;
F_13 ( V_2 , V_21 ) ;
F_14 ( V_2 , 5 , L_1 , V_21 ) ;
F_15 ( V_2 , 1 , V_21 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_3 V_20 ;
T_4 V_21 ;
int V_7 ;
T_2 V_8 ;
V_2 -> V_22 . V_25 ++ ;
if ( V_2 -> V_10 . V_11 -> V_12 . V_13 & V_14 )
return F_2 ( V_2 , V_15 ) ;
V_20 = F_3 ( V_2 , & V_8 ) ;
if ( V_20 & 3 )
return F_2 ( V_2 , V_16 ) ;
V_21 = F_17 ( V_2 ) ;
V_7 = F_18 ( V_2 , V_20 , V_8 , & V_21 , sizeof( V_21 ) ) ;
if ( V_7 )
return F_5 ( V_2 , V_7 ) ;
F_14 ( V_2 , 5 , L_2 , V_21 ) ;
F_15 ( V_2 , 0 , V_21 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
T_5 V_26 = V_2 -> V_26 ;
T_3 V_27 ;
int V_7 ;
T_2 V_8 ;
V_2 -> V_22 . V_28 ++ ;
if ( V_2 -> V_10 . V_11 -> V_12 . V_13 & V_14 )
return F_2 ( V_2 , V_15 ) ;
V_27 = F_3 ( V_2 , & V_8 ) ;
if ( V_27 & 1 )
return F_2 ( V_2 , V_16 ) ;
V_7 = F_18 ( V_2 , V_27 , V_8 , & V_26 , sizeof( V_26 ) ) ;
if ( V_7 )
return F_5 ( V_2 , V_7 ) ;
F_14 ( V_2 , 5 , L_3 , V_27 ) ;
F_20 ( V_2 , V_27 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_7 = 0 ;
if ( ! ( V_2 -> V_10 . V_11 -> V_29 & ( V_30 | V_31 | V_32 ) ) )
return V_7 ;
V_7 = F_22 () ;
F_23 ( V_2 ) ;
V_2 -> V_10 . V_11 -> V_29 &= ~ ( V_30 | V_31 | V_32 ) ;
return V_7 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_7 = F_21 ( V_2 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_22 . V_33 ++ ;
if ( V_2 -> V_10 . V_11 -> V_12 . V_13 & V_14 )
return F_2 ( V_2 , V_15 ) ;
F_25 ( V_2 , 4 ) ;
F_14 ( V_2 , 4 , L_4 , L_5 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_34 ++ ;
if ( F_27 ( V_2 -> V_10 . V_11 -> V_12 ) . V_35 )
return F_2 ( V_2 , V_15 ) ;
F_28 ( V_2 -> V_17 -> V_10 . V_36 , ! F_29 ( V_2 ) ) ;
F_25 ( V_2 , 4 ) ;
F_14 ( V_2 , 4 , L_4 , L_6 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
T_6 V_37 ;
int V_38 ;
if ( V_2 -> V_10 . V_11 -> V_12 . V_13 & V_14 )
return F_2 ( V_2 , V_15 ) ;
F_31 ( V_2 , NULL , & V_38 ) ;
V_37 = V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_38 ] & V_43 ;
V_37 = F_32 ( V_2 , V_37 ) ;
if ( F_33 ( V_2 , V_37 ) )
return F_34 ( V_2 , & V_2 -> V_10 . V_44 ) ;
V_37 = F_35 ( V_2 , V_37 ) ;
if ( F_12 ( V_2 -> V_17 , V_37 ) )
return F_2 ( V_2 , V_24 ) ;
if ( F_36 ( V_2 -> V_17 , V_37 , V_45 ) )
return - V_46 ;
F_7 ( V_2 , 0 ) ;
V_2 -> V_39 -> V_40 . V_41 . V_42 [ 0 ] = 0 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_47 * V_48 ;
unsigned long V_49 ;
T_4 V_50 [ 3 ] ;
int V_7 ;
T_3 V_37 ;
T_2 V_8 ;
V_37 = F_3 ( V_2 , & V_8 ) ;
if ( V_37 & 3 )
return F_2 ( V_2 , V_16 ) ;
V_48 = F_38 ( V_2 -> V_17 , V_2 -> V_10 . V_11 -> V_51 [ 6 ] , 0 ) ;
if ( ! V_48 ) {
F_7 ( V_2 , 0 ) ;
return 0 ;
}
V_50 [ 0 ] = V_48 -> V_52 . V_53 << 16 | V_48 -> V_52 . V_54 ;
V_50 [ 1 ] = V_48 -> V_52 . V_55 ;
V_50 [ 2 ] = V_48 -> V_52 . V_56 ;
if ( V_37 ) {
V_49 = sizeof( V_50 ) - 4 ;
V_7 = F_18 ( V_2 , V_37 , V_8 , & V_50 , V_49 ) ;
if ( V_7 ) {
V_7 = F_5 ( V_2 , V_7 ) ;
goto V_57;
}
} else {
V_49 = sizeof( V_50 ) ;
if ( F_39 ( V_2 , V_58 , & V_50 , V_49 ) ) {
V_7 = - V_46 ;
goto V_57;
}
}
F_40 ( V_48 ) ;
F_7 ( V_2 , 1 ) ;
return 0 ;
V_57:
if ( F_41 ( V_2 -> V_17 , V_48 ) ) {
F_40 ( V_48 ) ;
V_7 = - V_46 ;
}
return V_7 ? - V_46 : 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_47 * V_48 = NULL ;
const T_3 V_59 = 0xffUL << 24 ;
if ( V_2 -> V_39 -> V_40 . V_41 . V_42 [ 1 ] )
V_48 = F_38 ( V_2 -> V_17 , V_59 ,
V_2 -> V_39 -> V_40 . V_41 . V_42 [ 1 ] ) ;
V_2 -> V_39 -> V_60 = V_61 ;
V_2 -> V_39 -> V_62 . V_63 = ! ! V_48 ;
if ( V_48 ) {
V_2 -> V_39 -> V_62 . V_53 = V_48 -> V_52 . V_53 ;
V_2 -> V_39 -> V_62 . V_54 = V_48 -> V_52 . V_54 ;
V_2 -> V_39 -> V_62 . V_55 = V_48 -> V_52 . V_55 ;
V_2 -> V_39 -> V_62 . V_56 = V_48 -> V_52 . V_56 ;
}
V_2 -> V_39 -> V_62 . V_64 = V_2 -> V_10 . V_11 -> V_64 ;
F_40 ( V_48 ) ;
return - V_65 ;
}
static int F_43 ( struct V_1 * V_2 )
{
F_14 ( V_2 , 4 , L_4 , L_7 ) ;
if ( V_2 -> V_10 . V_11 -> V_12 . V_13 & V_14 )
return F_2 ( V_2 , V_15 ) ;
if ( V_2 -> V_17 -> V_10 . V_66 ) {
if ( V_2 -> V_10 . V_11 -> V_67 == 0xb236 )
return F_37 ( V_2 ) ;
if ( V_2 -> V_10 . V_11 -> V_67 == 0xb235 )
return F_42 ( V_2 ) ;
return - V_68 ;
} else {
F_7 ( V_2 , 3 ) ;
return 0 ;
}
}
static int F_44 ( struct V_1 * V_2 )
{
int V_7 ;
unsigned int V_69 ;
V_2 -> V_22 . V_70 ++ ;
if ( V_2 -> V_10 . V_11 -> V_12 . V_13 & V_14 )
return F_2 ( V_2 , V_15 ) ;
V_69 = * V_2 -> V_17 -> V_10 . V_71 . V_69 -> V_72 >> 32 ;
V_7 = F_39 ( V_2 , F_45 ( struct V_73 , V_74 ) ,
& V_69 , sizeof( V_69 ) ) ;
if ( V_7 )
return V_7 ;
F_14 ( V_2 , 5 , L_8 , V_69 ) ;
F_46 ( V_2 , V_69 ) ;
return 0 ;
}
int F_47 ( T_7 * V_75 )
{
if ( V_75 -> V_13 & V_76 )
return 0 ;
if ( ( V_75 -> V_13 & V_77 ) == V_78 ) {
if ( V_75 -> V_37 & ~ V_79 )
return 0 ;
}
if ( ! ( V_75 -> V_13 & V_77 ) && ( V_75 -> V_37 & ~ V_80 ) )
return 0 ;
if ( ( V_75 -> V_13 & V_77 ) == V_81 )
return 0 ;
if ( V_75 -> V_37 & 1 )
return 0 ;
return 1 ;
}
int F_48 ( struct V_1 * V_2 )
{
T_7 * V_12 = & V_2 -> V_10 . V_11 -> V_12 ;
T_8 V_82 ;
T_3 V_37 ;
int V_7 ;
T_2 V_8 ;
if ( V_12 -> V_13 & V_14 )
return F_2 ( V_2 , V_15 ) ;
V_37 = F_3 ( V_2 , & V_8 ) ;
if ( V_37 & 7 )
return F_2 ( V_2 , V_16 ) ;
V_7 = F_4 ( V_2 , V_37 , V_8 , & V_82 , sizeof( V_82 ) ) ;
if ( V_7 )
return F_5 ( V_2 , V_7 ) ;
if ( ! ( V_82 . V_13 & V_83 ) )
return F_2 ( V_2 , V_16 ) ;
V_12 -> V_13 = ( V_82 . V_13 & ~ V_83 ) << 32 ;
V_12 -> V_13 |= V_82 . V_37 & V_84 ;
V_12 -> V_37 = V_82 . V_37 & ~ V_84 ;
if ( ! F_47 ( V_12 ) )
return F_2 ( V_2 , V_16 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
T_7 V_82 ;
T_3 V_37 ;
int V_7 ;
T_2 V_8 ;
if ( V_2 -> V_10 . V_11 -> V_12 . V_13 & V_14 )
return F_2 ( V_2 , V_15 ) ;
V_37 = F_3 ( V_2 , & V_8 ) ;
if ( V_37 & 7 )
return F_2 ( V_2 , V_16 ) ;
V_7 = F_4 ( V_2 , V_37 , V_8 , & V_82 , sizeof( V_82 ) ) ;
if ( V_7 )
return F_5 ( V_2 , V_7 ) ;
V_2 -> V_10 . V_11 -> V_12 = V_82 ;
if ( ! F_47 ( & V_2 -> V_10 . V_11 -> V_12 ) )
return F_2 ( V_2 , V_16 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
T_3 V_85 = V_2 -> V_10 . V_85 ;
T_3 V_20 ;
int V_7 ;
T_2 V_8 ;
V_2 -> V_22 . V_86 ++ ;
if ( V_2 -> V_10 . V_11 -> V_12 . V_13 & V_14 )
return F_2 ( V_2 , V_15 ) ;
V_20 = F_3 ( V_2 , & V_8 ) ;
if ( V_20 & 7 )
return F_2 ( V_2 , V_16 ) ;
V_7 = F_18 ( V_2 , V_20 , V_8 , & V_85 , sizeof( V_85 ) ) ;
if ( V_7 )
return F_5 ( V_2 , V_7 ) ;
F_14 ( V_2 , 5 , L_4 , L_9 ) ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 , struct V_87 * V_88 )
{
int V_89 = 0 ;
int V_90 ;
V_89 = F_52 ( & V_2 -> V_17 -> V_91 ) ;
if ( F_53 ( V_88 , 3 , 2 , 2 ) )
V_88 -> V_92 = 0 ;
if ( V_88 -> V_92 < 8 )
V_88 -> V_92 ++ ;
for ( V_90 = V_88 -> V_92 - 1 ; V_90 > 0 ; V_90 -- )
memcpy ( & V_88 -> V_93 [ V_90 ] , & V_88 -> V_93 [ V_90 - 1 ] , sizeof( V_88 -> V_93 [ 0 ] ) ) ;
memset ( & V_88 -> V_93 [ 0 ] , 0 , sizeof( V_88 -> V_93 [ 0 ] ) ) ;
V_88 -> V_93 [ 0 ] . V_94 = V_89 ;
V_88 -> V_93 [ 0 ] . V_95 = V_89 ;
V_88 -> V_93 [ 0 ] . V_96 = 0 ;
V_88 -> V_93 [ 0 ] . V_97 = 0 ;
V_88 -> V_93 [ 0 ] . V_98 = 1000 ;
memcpy ( V_88 -> V_93 [ 0 ] . V_99 , L_10 , 8 ) ;
F_54 ( V_88 -> V_93 [ 0 ] . V_99 , 8 ) ;
memcpy ( V_88 -> V_93 [ 0 ] . V_100 , L_11 , 16 ) ;
F_54 ( V_88 -> V_93 [ 0 ] . V_100 , 16 ) ;
}
static void F_55 ( struct V_1 * V_2 , T_3 V_37 , T_2 V_8 ,
T_9 V_101 , T_9 V_102 , T_5 V_103 )
{
V_2 -> V_39 -> V_60 = V_104 ;
V_2 -> V_39 -> V_105 . V_37 = V_37 ;
V_2 -> V_39 -> V_105 . V_8 = V_8 ;
V_2 -> V_39 -> V_105 . V_101 = V_101 ;
V_2 -> V_39 -> V_105 . V_102 = V_102 ;
V_2 -> V_39 -> V_105 . V_103 = V_103 ;
}
static int F_56 ( struct V_1 * V_2 )
{
int V_101 = ( V_2 -> V_39 -> V_40 . V_41 . V_42 [ 0 ] & 0xf0000000 ) >> 28 ;
int V_102 = V_2 -> V_39 -> V_40 . V_41 . V_42 [ 0 ] & 0xff ;
int V_103 = V_2 -> V_39 -> V_40 . V_41 . V_42 [ 1 ] & 0xffff ;
unsigned long V_88 = 0 ;
T_3 V_20 ;
int V_7 = 0 ;
T_2 V_8 ;
V_2 -> V_22 . V_106 ++ ;
F_14 ( V_2 , 4 , L_12 , V_101 , V_102 , V_103 ) ;
if ( V_2 -> V_10 . V_11 -> V_12 . V_13 & V_14 )
return F_2 ( V_2 , V_15 ) ;
if ( V_101 > 3 ) {
F_7 ( V_2 , 3 ) ;
return 0 ;
}
if ( V_2 -> V_39 -> V_40 . V_41 . V_42 [ 0 ] & 0x0fffff00
|| V_2 -> V_39 -> V_40 . V_41 . V_42 [ 1 ] & 0xffff0000 )
return F_2 ( V_2 , V_16 ) ;
if ( V_101 == 0 ) {
V_2 -> V_39 -> V_40 . V_41 . V_42 [ 0 ] = 3 << 28 ;
F_7 ( V_2 , 0 ) ;
return 0 ;
}
V_20 = F_3 ( V_2 , & V_8 ) ;
if ( V_20 & 0xfff )
return F_2 ( V_2 , V_16 ) ;
switch ( V_101 ) {
case 1 :
case 2 :
V_88 = F_57 ( V_107 ) ;
if ( ! V_88 )
goto V_108;
if ( F_53 ( ( void * ) V_88 , V_101 , V_102 , V_103 ) )
goto V_108;
break;
case 3 :
if ( V_102 != 2 || V_103 != 2 )
goto V_108;
V_88 = F_57 ( V_107 ) ;
if ( ! V_88 )
goto V_108;
F_51 ( V_2 , ( void * ) V_88 ) ;
break;
}
V_7 = F_18 ( V_2 , V_20 , V_8 , ( void * ) V_88 , V_45 ) ;
if ( V_7 ) {
V_7 = F_5 ( V_2 , V_7 ) ;
goto V_109;
}
if ( V_2 -> V_17 -> V_10 . V_110 ) {
F_55 ( V_2 , V_20 , V_8 , V_101 , V_102 , V_103 ) ;
V_7 = - V_65 ;
}
F_58 ( V_2 , V_101 , V_102 , V_103 , V_20 ) ;
F_59 ( V_88 ) ;
F_7 ( V_2 , 0 ) ;
V_2 -> V_39 -> V_40 . V_41 . V_42 [ 0 ] = 0 ;
return V_7 ;
V_108:
F_7 ( V_2 , 3 ) ;
V_109:
F_59 ( V_88 ) ;
return V_7 ;
}
int F_60 ( struct V_1 * V_2 )
{
T_10 V_111 ;
V_111 = V_112 [ V_2 -> V_10 . V_11 -> V_67 & 0x00ff ] ;
if ( V_111 )
return V_111 ( V_2 ) ;
return - V_68 ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_113 , V_38 ;
F_31 ( V_2 , & V_113 , & V_38 ) ;
V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_113 ] &= 0xffffffff00000000UL ;
V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_113 ] |= V_2 -> V_10 . V_11 -> V_12 . V_13 >> 32 ;
if ( V_38 ) {
V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_38 ] &= 0xffffffff00000000UL ;
V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_38 ] |=
V_2 -> V_10 . V_11 -> V_12 . V_13 & 0x00000000ffffffffUL ;
}
return 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
int V_113 , V_38 ;
unsigned long V_114 , V_115 ;
V_2 -> V_22 . V_116 ++ ;
F_31 ( V_2 , & V_113 , & V_38 ) ;
if ( ! V_117 )
return F_2 ( V_2 , V_118 ) ;
if ( V_2 -> V_10 . V_11 -> V_12 . V_13 & V_14 )
return F_2 ( V_2 , V_15 ) ;
if ( V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_113 ] & V_119 )
return F_2 ( V_2 , V_16 ) ;
if ( V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_113 ] & V_120 && ! F_63 ( 14 ) )
return F_2 ( V_2 , V_16 ) ;
if ( V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_113 ] & ( V_121 | V_122 ) )
return F_2 ( V_2 , V_16 ) ;
V_114 = V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_38 ] & V_43 ;
V_114 = F_32 ( V_2 , V_114 ) ;
switch ( V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_113 ] & V_123 ) {
case 0x00000000 :
V_115 = ( V_114 + ( 1UL << 12 ) ) & ~ ( ( 1UL << 12 ) - 1 ) ;
break;
case 0x00001000 :
V_115 = ( V_114 + ( 1UL << 20 ) ) & ~ ( ( 1UL << 20 ) - 1 ) ;
break;
default:
return F_2 ( V_2 , V_16 ) ;
}
if ( V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_113 ] & V_124 ) {
if ( F_33 ( V_2 , V_114 ) )
return F_34 ( V_2 , & V_2 -> V_10 . V_44 ) ;
}
while ( V_114 < V_115 ) {
unsigned long V_125 , V_126 ;
if ( ( V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_113 ] & V_123 ) == 0 )
V_126 = F_35 ( V_2 , V_114 ) ;
else
V_126 = V_114 ;
V_125 = F_64 ( V_2 -> V_17 , F_65 ( V_126 ) ) ;
if ( F_66 ( V_125 ) )
return F_2 ( V_2 , V_24 ) ;
if ( V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_113 ] & V_124 ) {
if ( F_67 ( ( void V_127 * ) V_125 , V_45 ) )
return F_2 ( V_2 , V_24 ) ;
}
if ( V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_113 ] & V_128 ) {
int V_7 = F_21 ( V_2 ) ;
if ( V_7 )
return V_7 ;
if ( F_68 ( V_129 -> V_130 , V_125 ,
V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_113 ] & V_131 ,
V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_113 ] & V_120 ) )
return F_2 ( V_2 , V_24 ) ;
}
V_114 += V_45 ;
}
if ( V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_113 ] & V_123 )
V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_38 ] = V_115 ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
int V_132 = ( V_2 -> V_10 . V_11 -> V_133 & ~ V_43 ) >> 3 ;
unsigned long * V_133 , V_134 ;
struct V_135 * V_135 ;
int V_6 ;
F_14 ( V_2 , 5 , L_13 , V_132 ) ;
V_135 = V_2 -> V_10 . V_135 ;
V_2 -> V_22 . V_136 ++ ;
if ( ! F_70 ( V_2 -> V_17 ) )
return F_2 ( V_2 , V_118 ) ;
if ( V_2 -> V_10 . V_11 -> V_12 . V_13 & V_14 )
return F_2 ( V_2 , V_15 ) ;
if ( ( ( V_2 -> V_10 . V_11 -> V_64 & 0xf0000000 ) >> 28 ) > 6 )
return F_2 ( V_2 , V_16 ) ;
F_25 ( V_2 , 4 ) ;
V_2 -> V_10 . V_11 -> V_133 &= V_43 ;
V_133 = F_71 ( V_2 -> V_10 . V_11 -> V_133 ) ;
F_72 ( & V_135 -> V_130 -> V_137 ) ;
for ( V_6 = 0 ; V_6 < V_132 ; ++ V_6 ) {
V_134 = V_133 [ V_6 ] ;
if ( F_73 ( V_134 & ~ V_43 || V_134 < 2 * V_45 ) )
break;
F_74 ( V_135 , V_134 ) ;
}
F_75 ( & V_135 -> V_130 -> V_137 ) ;
if ( V_6 < V_132 )
return F_2 ( V_2 , V_16 ) ;
return 0 ;
}
int F_76 ( struct V_1 * V_2 )
{
T_10 V_111 ;
V_111 = V_138 [ V_2 -> V_10 . V_11 -> V_67 & 0x00ff ] ;
if ( V_111 )
return V_111 ( V_2 ) ;
return - V_68 ;
}
int F_77 ( struct V_1 * V_2 )
{
int V_113 = ( V_2 -> V_10 . V_11 -> V_67 & 0x00f0 ) >> 4 ;
int V_139 = V_2 -> V_10 . V_11 -> V_67 & 0x000f ;
int V_140 , V_7 , V_141 ;
T_4 V_142 [ 16 ] ;
T_3 V_27 ;
T_2 V_8 ;
V_2 -> V_22 . V_143 ++ ;
if ( V_2 -> V_10 . V_11 -> V_12 . V_13 & V_14 )
return F_2 ( V_2 , V_15 ) ;
V_27 = F_78 ( V_2 , & V_8 ) ;
if ( V_27 & 3 )
return F_2 ( V_2 , V_16 ) ;
F_14 ( V_2 , 5 , L_14 , V_113 , V_139 , V_27 ) ;
F_79 ( V_2 , 0 , V_113 , V_139 , V_27 ) ;
V_141 = ( ( V_139 - V_113 ) & 0xf ) + 1 ;
V_7 = F_4 ( V_2 , V_27 , V_8 , V_142 , V_141 * sizeof( T_4 ) ) ;
if ( V_7 )
return F_5 ( V_2 , V_7 ) ;
V_140 = V_113 ;
V_141 = 0 ;
do {
V_2 -> V_10 . V_11 -> V_51 [ V_140 ] &= 0xffffffff00000000ul ;
V_2 -> V_10 . V_11 -> V_51 [ V_140 ] |= V_142 [ V_141 ++ ] ;
if ( V_140 == V_139 )
break;
V_140 = ( V_140 + 1 ) % 16 ;
} while ( 1 );
F_80 ( V_144 , V_2 ) ;
return 0 ;
}
int F_81 ( struct V_1 * V_2 )
{
int V_113 = ( V_2 -> V_10 . V_11 -> V_67 & 0x00f0 ) >> 4 ;
int V_139 = V_2 -> V_10 . V_11 -> V_67 & 0x000f ;
int V_140 , V_7 , V_141 ;
T_4 V_142 [ 16 ] ;
T_3 V_27 ;
T_2 V_8 ;
V_2 -> V_22 . V_145 ++ ;
if ( V_2 -> V_10 . V_11 -> V_12 . V_13 & V_14 )
return F_2 ( V_2 , V_15 ) ;
V_27 = F_78 ( V_2 , & V_8 ) ;
if ( V_27 & 3 )
return F_2 ( V_2 , V_16 ) ;
F_14 ( V_2 , 5 , L_15 , V_113 , V_139 , V_27 ) ;
F_82 ( V_2 , 0 , V_113 , V_139 , V_27 ) ;
V_140 = V_113 ;
V_141 = 0 ;
do {
V_142 [ V_141 ++ ] = V_2 -> V_10 . V_11 -> V_51 [ V_140 ] ;
if ( V_140 == V_139 )
break;
V_140 = ( V_140 + 1 ) % 16 ;
} while ( 1 );
V_7 = F_18 ( V_2 , V_27 , V_8 , V_142 , V_141 * sizeof( T_4 ) ) ;
return V_7 ? F_5 ( V_2 , V_7 ) : 0 ;
}
static int F_83 ( struct V_1 * V_2 )
{
int V_113 = ( V_2 -> V_10 . V_11 -> V_67 & 0x00f0 ) >> 4 ;
int V_139 = V_2 -> V_10 . V_11 -> V_67 & 0x000f ;
int V_140 , V_7 , V_141 ;
T_3 V_142 [ 16 ] ;
T_3 V_27 ;
T_2 V_8 ;
V_2 -> V_22 . V_146 ++ ;
if ( V_2 -> V_10 . V_11 -> V_12 . V_13 & V_14 )
return F_2 ( V_2 , V_15 ) ;
V_27 = F_84 ( V_2 , & V_8 ) ;
if ( V_27 & 7 )
return F_2 ( V_2 , V_16 ) ;
F_14 ( V_2 , 5 , L_16 , V_113 , V_139 , V_27 ) ;
F_79 ( V_2 , 1 , V_113 , V_139 , V_27 ) ;
V_141 = ( ( V_139 - V_113 ) & 0xf ) + 1 ;
V_7 = F_4 ( V_2 , V_27 , V_8 , V_142 , V_141 * sizeof( T_3 ) ) ;
if ( V_7 )
return F_5 ( V_2 , V_7 ) ;
V_140 = V_113 ;
V_141 = 0 ;
do {
V_2 -> V_10 . V_11 -> V_51 [ V_140 ] = V_142 [ V_141 ++ ] ;
if ( V_140 == V_139 )
break;
V_140 = ( V_140 + 1 ) % 16 ;
} while ( 1 );
F_80 ( V_144 , V_2 ) ;
return 0 ;
}
static int F_85 ( struct V_1 * V_2 )
{
int V_113 = ( V_2 -> V_10 . V_11 -> V_67 & 0x00f0 ) >> 4 ;
int V_139 = V_2 -> V_10 . V_11 -> V_67 & 0x000f ;
int V_140 , V_7 , V_141 ;
T_3 V_142 [ 16 ] ;
T_3 V_27 ;
T_2 V_8 ;
V_2 -> V_22 . V_147 ++ ;
if ( V_2 -> V_10 . V_11 -> V_12 . V_13 & V_14 )
return F_2 ( V_2 , V_15 ) ;
V_27 = F_84 ( V_2 , & V_8 ) ;
if ( V_27 & 7 )
return F_2 ( V_2 , V_16 ) ;
F_14 ( V_2 , 5 , L_17 , V_113 , V_139 , V_27 ) ;
F_82 ( V_2 , 1 , V_113 , V_139 , V_27 ) ;
V_140 = V_113 ;
V_141 = 0 ;
do {
V_142 [ V_141 ++ ] = V_2 -> V_10 . V_11 -> V_51 [ V_140 ] ;
if ( V_140 == V_139 )
break;
V_140 = ( V_140 + 1 ) % 16 ;
} while ( 1 );
V_7 = F_18 ( V_2 , V_27 , V_8 , V_142 , V_141 * sizeof( T_3 ) ) ;
return V_7 ? F_5 ( V_2 , V_7 ) : 0 ;
}
int F_86 ( struct V_1 * V_2 )
{
T_10 V_111 ;
V_111 = V_148 [ V_2 -> V_10 . V_11 -> V_64 & 0xff ] ;
if ( V_111 )
return V_111 ( V_2 ) ;
return - V_68 ;
}
static int F_87 ( struct V_1 * V_2 )
{
T_3 V_149 , V_150 ;
unsigned long V_151 , V_152 ;
int V_153 = 0 , V_154 = 0 ;
bool V_155 ;
T_2 V_8 ;
V_2 -> V_22 . V_156 ++ ;
if ( V_2 -> V_10 . V_11 -> V_12 . V_13 & V_14 )
return F_2 ( V_2 , V_15 ) ;
F_88 ( V_2 , & V_149 , & V_150 , & V_8 , NULL ) ;
if ( V_150 & 0xf0 )
return - V_68 ;
if ( V_2 -> V_10 . V_11 -> V_12 . V_13 & V_157 )
F_89 ( V_2 ) ;
V_153 = F_90 ( V_2 , V_149 , V_8 , & V_152 , 1 ) ;
if ( V_153 == V_158 ) {
V_154 = 1 ;
V_153 = F_90 ( V_2 , V_149 , V_8 , & V_152 , 0 ) ;
}
if ( V_153 ) {
if ( V_153 == V_24 || V_153 == V_159 ) {
V_153 = F_2 ( V_2 , V_153 ) ;
} else if ( V_153 > 0 ) {
F_7 ( V_2 , 3 ) ;
V_153 = 0 ;
}
goto V_160;
}
V_151 = F_91 ( V_2 -> V_17 , F_65 ( V_152 ) , & V_155 ) ;
if ( F_66 ( V_151 ) ) {
V_153 = F_2 ( V_2 , V_24 ) ;
} else {
if ( ! V_155 )
V_154 = 1 ;
F_7 ( V_2 , V_154 ) ;
}
V_160:
if ( V_2 -> V_10 . V_11 -> V_12 . V_13 & V_157 )
F_92 ( V_2 ) ;
return V_153 ;
}
int F_93 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_10 . V_11 -> V_67 & 0x00ff ) == 0x01 )
return F_87 ( V_2 ) ;
return - V_68 ;
}
static int F_94 ( struct V_1 * V_2 )
{
T_4 V_161 ;
if ( V_2 -> V_10 . V_11 -> V_12 . V_13 & V_14 )
return F_2 ( V_2 , V_15 ) ;
if ( V_2 -> V_39 -> V_40 . V_41 . V_42 [ 0 ] & 0x00000000ffff0000 )
return F_2 ( V_2 ,
V_16 ) ;
V_161 = V_2 -> V_39 -> V_40 . V_41 . V_42 [ 0 ] & 0x000000000000ffff ;
V_2 -> V_10 . V_11 -> V_162 = V_161 ;
return 0 ;
}
int F_95 ( struct V_1 * V_2 )
{
T_10 V_111 ;
V_111 = V_163 [ V_2 -> V_10 . V_11 -> V_67 & 0x00ff ] ;
if ( V_111 )
return V_111 ( V_2 ) ;
return - V_68 ;
}
