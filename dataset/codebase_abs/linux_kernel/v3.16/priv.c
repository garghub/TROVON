static int F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 ;
T_1 V_4 , V_5 ;
int V_6 , V_7 ;
T_2 V_8 ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
V_8 = F_3 ( V_2 ) ;
if ( V_8 & 7 )
return F_2 ( V_2 , V_15 ) ;
V_7 = F_4 ( V_2 , V_8 , & V_5 , sizeof( V_5 ) ) ;
if ( V_7 )
return F_5 ( V_2 , V_7 ) ;
if ( F_6 ( & V_4 ) ) {
F_7 ( V_2 , 3 ) ;
return 0 ;
}
V_5 = ( V_5 - V_4 ) & ~ 0x3fUL ;
F_8 ( & V_2 -> V_16 -> V_17 ) ;
F_9 (i, cpup, vcpu->kvm)
V_3 -> V_9 . V_10 -> V_18 = V_5 ;
F_10 ( & V_2 -> V_16 -> V_17 ) ;
F_7 ( V_2 , 0 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
T_2 V_19 ;
T_3 V_20 ;
int V_7 ;
V_2 -> V_21 . V_22 ++ ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
V_19 = F_3 ( V_2 ) ;
if ( V_19 & 3 )
return F_2 ( V_2 , V_15 ) ;
V_7 = F_4 ( V_2 , V_19 , & V_20 , sizeof( V_20 ) ) ;
if ( V_7 )
return F_5 ( V_2 , V_7 ) ;
V_20 &= 0x7fffe000u ;
if ( F_12 ( V_2 -> V_16 , V_20 ) )
return F_2 ( V_2 , V_23 ) ;
F_13 ( V_2 , V_20 ) ;
F_14 ( V_2 , 5 , L_1 , V_20 ) ;
F_15 ( V_2 , 1 , V_20 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_2 V_19 ;
T_3 V_20 ;
int V_7 ;
V_2 -> V_21 . V_24 ++ ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
V_19 = F_3 ( V_2 ) ;
if ( V_19 & 3 )
return F_2 ( V_2 , V_15 ) ;
V_20 = F_17 ( V_2 ) ;
V_7 = F_18 ( V_2 , V_19 , & V_20 , sizeof( V_20 ) ) ;
if ( V_7 )
return F_5 ( V_2 , V_7 ) ;
F_14 ( V_2 , 5 , L_2 , V_20 ) ;
F_15 ( V_2 , 0 , V_20 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
T_4 V_25 = V_2 -> V_25 ;
T_2 V_26 ;
int V_7 ;
V_2 -> V_21 . V_27 ++ ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
V_26 = F_3 ( V_2 ) ;
if ( V_26 & 1 )
return F_2 ( V_2 , V_15 ) ;
V_7 = F_18 ( V_2 , V_26 , & V_25 , sizeof( V_25 ) ) ;
if ( V_7 )
return F_5 ( V_2 , V_7 ) ;
F_14 ( V_2 , 5 , L_3 , V_26 ) ;
F_20 ( V_2 , V_26 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_9 . V_10 -> V_28 & ( V_29 | V_30 | V_31 ) ) )
return;
F_22 () ;
F_23 ( V_2 ) ;
V_2 -> V_9 . V_10 -> V_28 &= ~ ( V_29 | V_30 | V_31 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
V_2 -> V_21 . V_32 ++ ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
V_2 -> V_9 . V_10 -> V_11 . V_33 =
F_25 ( V_2 -> V_9 . V_10 -> V_11 , 4 ) ;
F_14 ( V_2 , 4 , L_4 , L_5 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
T_5 * V_34 = & V_2 -> V_9 . V_10 -> V_11 ;
V_2 -> V_21 . V_35 ++ ;
if ( F_27 ( * V_34 ) . V_36 )
return F_2 ( V_2 , V_14 ) ;
F_28 ( V_2 -> V_16 -> V_9 . V_37 , ! F_29 ( V_2 ) ) ;
V_34 -> V_33 = F_25 ( * V_34 , 4 ) ;
F_14 ( V_2 , 4 , L_4 , L_6 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
T_6 V_33 ;
int V_38 ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
F_31 ( V_2 , NULL , & V_38 ) ;
V_33 = V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_38 ] & V_43 ;
V_33 = F_32 ( V_2 , V_33 ) ;
if ( F_33 ( V_2 , V_33 ) )
return F_34 ( V_2 , & V_2 -> V_9 . V_44 ) ;
V_33 = F_35 ( V_2 , V_33 ) ;
if ( F_12 ( V_2 -> V_16 , V_33 ) )
return F_2 ( V_2 , V_23 ) ;
if ( F_36 ( V_2 -> V_16 , V_33 , V_45 ) )
return - V_46 ;
F_7 ( V_2 , 0 ) ;
V_2 -> V_39 -> V_40 . V_41 . V_42 [ 0 ] = 0 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_47 * V_48 ;
unsigned long V_49 ;
T_3 V_50 [ 3 ] ;
int V_51 , V_7 ;
T_2 V_33 ;
V_7 = 0 ;
V_33 = F_3 ( V_2 ) ;
if ( V_33 & 3 )
return F_2 ( V_2 , V_15 ) ;
V_51 = 0 ;
V_48 = F_38 ( V_2 -> V_16 , V_2 -> V_9 . V_10 -> V_52 [ 6 ] , 0 ) ;
if ( ! V_48 )
goto V_53;
V_51 = 1 ;
V_50 [ 0 ] = V_48 -> V_54 . V_55 << 16 | V_48 -> V_54 . V_56 ;
V_50 [ 1 ] = V_48 -> V_54 . V_57 ;
V_50 [ 2 ] = V_48 -> V_54 . V_58 ;
if ( V_33 ) {
V_49 = sizeof( V_50 ) - 4 ;
V_7 = F_18 ( V_2 , V_33 , & V_50 , V_49 ) ;
if ( V_7 )
return F_5 ( V_2 , V_7 ) ;
} else {
V_49 = sizeof( V_50 ) ;
if ( F_39 ( V_2 , V_59 , & V_50 , V_49 ) )
V_7 = - V_46 ;
}
if ( ! V_7 )
F_40 ( V_48 ) ;
else
F_41 ( V_2 -> V_16 , V_48 ) ;
V_53:
if ( ! V_7 )
F_7 ( V_2 , V_51 ) ;
return V_7 ? - V_46 : 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_47 * V_48 ;
V_48 = F_38 ( V_2 -> V_16 , 0 ,
V_2 -> V_39 -> V_40 . V_41 . V_42 [ 1 ] ) ;
V_2 -> V_39 -> V_60 = V_61 ;
V_2 -> V_39 -> V_62 . V_63 = ! ! V_48 ;
if ( V_48 ) {
V_2 -> V_39 -> V_62 . V_55 = V_48 -> V_54 . V_55 ;
V_2 -> V_39 -> V_62 . V_56 = V_48 -> V_54 . V_56 ;
V_2 -> V_39 -> V_62 . V_57 = V_48 -> V_54 . V_57 ;
V_2 -> V_39 -> V_62 . V_58 = V_48 -> V_54 . V_58 ;
}
V_2 -> V_39 -> V_62 . V_64 = V_2 -> V_9 . V_10 -> V_64 ;
F_40 ( V_48 ) ;
return - V_65 ;
}
static int F_43 ( struct V_1 * V_2 )
{
F_14 ( V_2 , 4 , L_4 , L_7 ) ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
if ( V_2 -> V_16 -> V_9 . V_66 ) {
if ( V_2 -> V_9 . V_10 -> V_67 == 0xb236 )
return F_37 ( V_2 ) ;
if ( V_2 -> V_9 . V_10 -> V_67 == 0xb235 )
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
V_2 -> V_21 . V_69 ++ ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
V_7 = F_39 ( V_2 , F_45 ( struct V_70 , V_71 ) ,
V_72 , 4 ) ;
if ( V_7 )
return V_7 ;
F_14 ( V_2 , 5 , L_8 ,
* ( unsigned int * ) V_72 ) ;
F_46 ( V_2 , * ( unsigned int * ) V_72 ) ;
return 0 ;
}
static void F_47 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_73 )
F_48 ( V_2 ) ;
}
int F_49 ( T_5 * V_34 )
{
if ( V_34 -> V_12 & V_74 )
return 0 ;
if ( ( V_34 -> V_12 & V_75 ) == V_76 ) {
if ( V_34 -> V_33 & ~ V_77 )
return 0 ;
}
if ( ! ( V_34 -> V_12 & V_75 ) && ( V_34 -> V_33 & ~ V_78 ) )
return 0 ;
if ( ( V_34 -> V_12 & V_75 ) == V_79 )
return 0 ;
if ( V_34 -> V_33 & 1 )
return 0 ;
return 1 ;
}
int F_50 ( struct V_1 * V_2 )
{
T_5 * V_11 = & V_2 -> V_9 . V_10 -> V_11 ;
T_7 V_80 ;
T_2 V_33 ;
int V_7 ;
if ( V_11 -> V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
V_33 = F_3 ( V_2 ) ;
if ( V_33 & 7 )
return F_2 ( V_2 , V_15 ) ;
V_7 = F_4 ( V_2 , V_33 , & V_80 , sizeof( V_80 ) ) ;
if ( V_7 )
return F_5 ( V_2 , V_7 ) ;
if ( ! ( V_80 . V_12 & V_81 ) )
return F_2 ( V_2 , V_15 ) ;
V_11 -> V_12 = ( V_80 . V_12 & ~ V_81 ) << 32 ;
V_11 -> V_12 |= V_80 . V_33 & V_82 ;
V_11 -> V_33 = V_80 . V_33 & ~ V_82 ;
if ( ! F_49 ( V_11 ) )
return F_2 ( V_2 , V_15 ) ;
F_47 ( V_2 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
T_5 V_80 ;
T_2 V_33 ;
int V_7 ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
V_33 = F_3 ( V_2 ) ;
if ( V_33 & 7 )
return F_2 ( V_2 , V_15 ) ;
V_7 = F_4 ( V_2 , V_33 , & V_80 , sizeof( V_80 ) ) ;
if ( V_7 )
return F_5 ( V_2 , V_7 ) ;
V_2 -> V_9 . V_10 -> V_11 = V_80 ;
if ( ! F_49 ( & V_2 -> V_9 . V_10 -> V_11 ) )
return F_2 ( V_2 , V_15 ) ;
F_47 ( V_2 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
T_2 V_83 = V_2 -> V_9 . V_83 ;
T_2 V_19 ;
int V_7 ;
V_2 -> V_21 . V_84 ++ ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
V_19 = F_3 ( V_2 ) ;
if ( V_19 & 7 )
return F_2 ( V_2 , V_15 ) ;
V_7 = F_18 ( V_2 , V_19 , & V_83 , sizeof( V_83 ) ) ;
if ( V_7 )
return F_5 ( V_2 , V_7 ) ;
F_14 ( V_2 , 5 , L_4 , L_9 ) ;
return 0 ;
}
static void F_53 ( struct V_1 * V_2 , struct V_85 * V_86 )
{
int V_87 = 0 ;
int V_88 ;
V_87 = F_54 ( & V_2 -> V_16 -> V_89 ) ;
if ( F_55 ( V_86 , 3 , 2 , 2 ) )
V_86 -> V_90 = 0 ;
if ( V_86 -> V_90 < 8 )
V_86 -> V_90 ++ ;
for ( V_88 = V_86 -> V_90 - 1 ; V_88 > 0 ; V_88 -- )
memcpy ( & V_86 -> V_91 [ V_88 ] , & V_86 -> V_91 [ V_88 - 1 ] , sizeof( V_86 -> V_91 [ 0 ] ) ) ;
V_86 -> V_91 [ 0 ] . V_92 = V_87 ;
V_86 -> V_91 [ 0 ] . V_93 = V_87 ;
V_86 -> V_91 [ 0 ] . V_94 = 0 ;
V_86 -> V_91 [ 0 ] . V_95 = 0 ;
V_86 -> V_91 [ 0 ] . V_96 = 1000 ;
memcpy ( V_86 -> V_91 [ 0 ] . V_97 , L_10 , 8 ) ;
F_56 ( V_86 -> V_91 [ 0 ] . V_97 , 8 ) ;
memcpy ( V_86 -> V_91 [ 0 ] . V_98 , L_11 , 16 ) ;
F_56 ( V_86 -> V_91 [ 0 ] . V_98 , 16 ) ;
}
static int F_57 ( struct V_1 * V_2 )
{
int V_99 = ( V_2 -> V_39 -> V_40 . V_41 . V_42 [ 0 ] & 0xf0000000 ) >> 28 ;
int V_100 = V_2 -> V_39 -> V_40 . V_41 . V_42 [ 0 ] & 0xff ;
int V_101 = V_2 -> V_39 -> V_40 . V_41 . V_42 [ 1 ] & 0xffff ;
unsigned long V_86 = 0 ;
T_2 V_19 ;
int V_7 = 0 ;
V_2 -> V_21 . V_102 ++ ;
F_14 ( V_2 , 4 , L_12 , V_99 , V_100 , V_101 ) ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
if ( V_99 > 3 ) {
F_7 ( V_2 , 3 ) ;
return 0 ;
}
if ( V_2 -> V_39 -> V_40 . V_41 . V_42 [ 0 ] & 0x0fffff00
|| V_2 -> V_39 -> V_40 . V_41 . V_42 [ 1 ] & 0xffff0000 )
return F_2 ( V_2 , V_15 ) ;
if ( V_99 == 0 ) {
V_2 -> V_39 -> V_40 . V_41 . V_42 [ 0 ] = 3 << 28 ;
F_7 ( V_2 , 0 ) ;
return 0 ;
}
V_19 = F_3 ( V_2 ) ;
if ( V_19 & 0xfff )
return F_2 ( V_2 , V_15 ) ;
switch ( V_99 ) {
case 1 :
case 2 :
V_86 = F_58 ( V_103 ) ;
if ( ! V_86 )
goto V_104;
if ( F_55 ( ( void * ) V_86 , V_99 , V_100 , V_101 ) )
goto V_104;
break;
case 3 :
if ( V_100 != 2 || V_101 != 2 )
goto V_104;
V_86 = F_58 ( V_103 ) ;
if ( ! V_86 )
goto V_104;
F_53 ( V_2 , ( void * ) V_86 ) ;
break;
}
V_7 = F_18 ( V_2 , V_19 , ( void * ) V_86 , V_45 ) ;
if ( V_7 ) {
V_7 = F_5 ( V_2 , V_7 ) ;
goto V_105;
}
F_59 ( V_2 , V_99 , V_100 , V_101 , V_19 ) ;
F_60 ( V_86 ) ;
F_7 ( V_2 , 0 ) ;
V_2 -> V_39 -> V_40 . V_41 . V_42 [ 0 ] = 0 ;
return 0 ;
V_104:
F_7 ( V_2 , 3 ) ;
V_105:
F_60 ( V_86 ) ;
return V_7 ;
}
int F_61 ( struct V_1 * V_2 )
{
T_8 V_106 ;
V_106 = V_107 [ V_2 -> V_9 . V_10 -> V_67 & 0x00ff ] ;
if ( V_106 )
return V_106 ( V_2 ) ;
return - V_68 ;
}
static int F_62 ( struct V_1 * V_2 )
{
int V_108 , V_38 ;
F_31 ( V_2 , & V_108 , & V_38 ) ;
V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_108 ] &= 0xffffffff00000000UL ;
V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_108 ] |= V_2 -> V_9 . V_10 -> V_11 . V_12 >> 32 ;
if ( V_38 ) {
V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_38 ] &= 0xffffffff00000000UL ;
V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_38 ] |=
V_2 -> V_9 . V_10 -> V_11 . V_12 & 0x00000000ffffffffUL ;
}
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
int V_108 , V_38 ;
unsigned long V_109 , V_110 ;
V_2 -> V_21 . V_111 ++ ;
F_31 ( V_2 , & V_108 , & V_38 ) ;
if ( ! V_112 )
return F_2 ( V_2 , V_113 ) ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
if ( V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_108 ] & V_114 )
return F_2 ( V_2 , V_15 ) ;
if ( V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_108 ] & V_115 && ! F_64 ( 14 ) )
return F_2 ( V_2 , V_15 ) ;
if ( V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_108 ] & ( V_116 | V_117 ) )
return F_2 ( V_2 , V_15 ) ;
V_109 = V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_38 ] & V_43 ;
if ( V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_108 ] & V_118 ) {
if ( F_33 ( V_2 , V_109 ) )
return F_34 ( V_2 , & V_2 -> V_9 . V_44 ) ;
}
switch ( V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_108 ] & V_119 ) {
case 0x00000000 :
V_110 = ( V_109 + ( 1UL << 12 ) ) & ~ ( ( 1UL << 12 ) - 1 ) ;
break;
case 0x00001000 :
V_110 = ( V_109 + ( 1UL << 20 ) ) & ~ ( ( 1UL << 20 ) - 1 ) ;
break;
default:
return F_2 ( V_2 , V_15 ) ;
}
while ( V_109 < V_110 ) {
unsigned long V_120 , V_121 ;
if ( ( V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_108 ] & V_119 ) == 0 )
V_121 = F_35 ( V_2 , V_109 ) ;
else
V_121 = V_109 ;
V_120 = F_65 ( V_2 -> V_16 , F_66 ( V_121 ) ) ;
if ( F_67 ( V_120 ) )
return F_2 ( V_2 , V_23 ) ;
if ( V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_108 ] & V_118 ) {
if ( F_68 ( ( void V_122 * ) V_120 , V_45 ) )
return F_2 ( V_2 , V_23 ) ;
}
if ( V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_108 ] & V_123 ) {
F_21 ( V_2 ) ;
if ( F_69 ( V_124 -> V_125 , V_120 ,
V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_108 ] & V_126 ,
V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_108 ] & V_115 ) )
return F_2 ( V_2 , V_23 ) ;
}
V_109 += V_45 ;
}
if ( V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_108 ] & V_119 )
V_2 -> V_39 -> V_40 . V_41 . V_42 [ V_38 ] = V_110 ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 )
{
int V_127 = ( V_2 -> V_9 . V_10 -> V_128 & ~ V_43 ) >> 3 ;
unsigned long * V_128 , V_129 ;
struct V_130 * V_130 ;
int V_6 ;
F_14 ( V_2 , 5 , L_13 , V_127 ) ;
V_130 = V_2 -> V_9 . V_130 ;
V_2 -> V_21 . V_131 ++ ;
if ( ! F_71 ( V_2 -> V_16 ) )
return F_2 ( V_2 , V_113 ) ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
if ( ( ( V_2 -> V_9 . V_10 -> V_64 & 0xf0000000 ) >> 28 ) > 6 )
return F_2 ( V_2 , V_15 ) ;
V_2 -> V_9 . V_10 -> V_11 . V_33 =
F_25 ( V_2 -> V_9 . V_10 -> V_11 , 4 ) ;
V_2 -> V_9 . V_10 -> V_128 &= V_43 ;
V_128 = F_72 ( V_2 -> V_9 . V_10 -> V_128 ) ;
F_73 ( & V_130 -> V_125 -> V_132 ) ;
for ( V_6 = 0 ; V_6 < V_127 ; ++ V_6 ) {
V_129 = V_128 [ V_6 ] ;
if ( F_74 ( V_129 & ~ V_43 || V_129 < 2 * V_45 ) )
break;
F_75 ( V_129 , V_130 ) ;
}
F_76 ( & V_130 -> V_125 -> V_132 ) ;
if ( V_6 < V_127 )
return F_2 ( V_2 , V_15 ) ;
return 0 ;
}
int F_77 ( struct V_1 * V_2 )
{
T_8 V_106 ;
V_106 = V_133 [ V_2 -> V_9 . V_10 -> V_67 & 0x00ff ] ;
if ( V_106 )
return V_106 ( V_2 ) ;
return - V_68 ;
}
int F_78 ( struct V_1 * V_2 )
{
int V_108 = ( V_2 -> V_9 . V_10 -> V_67 & 0x00f0 ) >> 4 ;
int V_134 = V_2 -> V_9 . V_10 -> V_67 & 0x000f ;
T_3 V_5 = 0 ;
int V_135 , V_7 ;
T_2 V_26 ;
V_2 -> V_21 . V_136 ++ ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
V_26 = F_79 ( V_2 ) ;
if ( V_26 & 3 )
return F_2 ( V_2 , V_15 ) ;
F_14 ( V_2 , 5 , L_14 , V_108 , V_134 , V_26 ) ;
F_80 ( V_2 , 0 , V_108 , V_134 , V_26 ) ;
V_135 = V_108 ;
do {
V_7 = F_4 ( V_2 , V_26 , & V_5 , sizeof( V_5 ) ) ;
if ( V_7 )
return F_5 ( V_2 , V_7 ) ;
V_2 -> V_9 . V_10 -> V_52 [ V_135 ] &= 0xffffffff00000000ul ;
V_2 -> V_9 . V_10 -> V_52 [ V_135 ] |= V_5 ;
V_26 += 4 ;
if ( V_135 == V_134 )
break;
V_135 = ( V_135 + 1 ) % 16 ;
} while ( 1 );
return 0 ;
}
int F_81 ( struct V_1 * V_2 )
{
int V_108 = ( V_2 -> V_9 . V_10 -> V_67 & 0x00f0 ) >> 4 ;
int V_134 = V_2 -> V_9 . V_10 -> V_67 & 0x000f ;
T_2 V_26 ;
T_3 V_5 ;
int V_135 , V_7 ;
V_2 -> V_21 . V_137 ++ ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
V_26 = F_79 ( V_2 ) ;
if ( V_26 & 3 )
return F_2 ( V_2 , V_15 ) ;
F_14 ( V_2 , 5 , L_15 , V_108 , V_134 , V_26 ) ;
F_82 ( V_2 , 0 , V_108 , V_134 , V_26 ) ;
V_135 = V_108 ;
do {
V_5 = V_2 -> V_9 . V_10 -> V_52 [ V_135 ] & 0x00000000fffffffful ;
V_7 = F_18 ( V_2 , V_26 , & V_5 , sizeof( V_5 ) ) ;
if ( V_7 )
return F_5 ( V_2 , V_7 ) ;
V_26 += 4 ;
if ( V_135 == V_134 )
break;
V_135 = ( V_135 + 1 ) % 16 ;
} while ( 1 );
return 0 ;
}
static int F_83 ( struct V_1 * V_2 )
{
int V_108 = ( V_2 -> V_9 . V_10 -> V_67 & 0x00f0 ) >> 4 ;
int V_134 = V_2 -> V_9 . V_10 -> V_67 & 0x000f ;
T_2 V_26 , V_5 ;
int V_135 , V_7 ;
V_2 -> V_21 . V_138 ++ ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
V_26 = F_84 ( V_2 ) ;
if ( V_26 & 7 )
return F_2 ( V_2 , V_15 ) ;
V_135 = V_108 ;
F_14 ( V_2 , 5 , L_16 , V_108 , V_134 , V_26 ) ;
F_80 ( V_2 , 1 , V_108 , V_134 , V_26 ) ;
do {
V_7 = F_4 ( V_2 , V_26 , & V_5 , sizeof( V_5 ) ) ;
if ( V_7 )
return F_5 ( V_2 , V_7 ) ;
V_2 -> V_9 . V_10 -> V_52 [ V_135 ] = V_5 ;
V_26 += 8 ;
if ( V_135 == V_134 )
break;
V_135 = ( V_135 + 1 ) % 16 ;
} while ( 1 );
return 0 ;
}
static int F_85 ( struct V_1 * V_2 )
{
int V_108 = ( V_2 -> V_9 . V_10 -> V_67 & 0x00f0 ) >> 4 ;
int V_134 = V_2 -> V_9 . V_10 -> V_67 & 0x000f ;
T_2 V_26 , V_5 ;
int V_135 , V_7 ;
V_2 -> V_21 . V_139 ++ ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
V_26 = F_84 ( V_2 ) ;
if ( V_26 & 7 )
return F_2 ( V_2 , V_15 ) ;
V_135 = V_108 ;
F_14 ( V_2 , 5 , L_17 , V_108 , V_134 , V_26 ) ;
F_82 ( V_2 , 1 , V_108 , V_134 , V_26 ) ;
do {
V_5 = V_2 -> V_9 . V_10 -> V_52 [ V_135 ] ;
V_7 = F_18 ( V_2 , V_26 , & V_5 , sizeof( V_5 ) ) ;
if ( V_7 )
return F_5 ( V_2 , V_7 ) ;
V_26 += 8 ;
if ( V_135 == V_134 )
break;
V_135 = ( V_135 + 1 ) % 16 ;
} while ( 1 );
return 0 ;
}
int F_86 ( struct V_1 * V_2 )
{
T_8 V_106 ;
V_106 = V_140 [ V_2 -> V_9 . V_10 -> V_64 & 0xff ] ;
if ( V_106 )
return V_106 ( V_2 ) ;
return - V_68 ;
}
static int F_87 ( struct V_1 * V_2 )
{
T_2 V_141 , V_142 ;
unsigned long V_143 , V_144 ;
int V_145 = 0 , V_51 = 0 ;
bool V_146 ;
V_2 -> V_21 . V_147 ++ ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
F_88 ( V_2 , & V_141 , & V_142 ) ;
if ( V_142 & 0xf0 )
return - V_68 ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_148 )
F_89 ( V_2 ) ;
V_145 = F_90 ( V_2 , V_141 , & V_144 , 1 ) ;
if ( V_145 == V_149 ) {
V_51 = 1 ;
V_145 = F_90 ( V_2 , V_141 , & V_144 , 0 ) ;
}
if ( V_145 ) {
if ( V_145 == V_23 || V_145 == V_150 ) {
V_145 = F_2 ( V_2 , V_145 ) ;
} else if ( V_145 > 0 ) {
F_7 ( V_2 , 3 ) ;
V_145 = 0 ;
}
goto V_151;
}
V_143 = F_91 ( V_2 -> V_16 , F_66 ( V_144 ) , & V_146 ) ;
if ( F_67 ( V_143 ) ) {
V_145 = F_2 ( V_2 , V_23 ) ;
} else {
if ( ! V_146 )
V_51 = 1 ;
F_7 ( V_2 , V_51 ) ;
}
V_151:
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_148 )
F_92 ( V_2 ) ;
return V_145 ;
}
int F_93 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_9 . V_10 -> V_67 & 0x00ff ) == 0x01 )
return F_87 ( V_2 ) ;
return - V_68 ;
}
static int F_94 ( struct V_1 * V_2 )
{
T_3 V_152 ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
if ( V_2 -> V_39 -> V_40 . V_41 . V_42 [ 0 ] & 0x00000000ffff0000 )
return F_2 ( V_2 ,
V_15 ) ;
V_152 = V_2 -> V_39 -> V_40 . V_41 . V_42 [ 0 ] & 0x000000000000ffff ;
V_2 -> V_9 . V_10 -> V_153 = V_152 ;
return 0 ;
}
int F_95 ( struct V_1 * V_2 )
{
T_8 V_106 ;
V_106 = V_154 [ V_2 -> V_9 . V_10 -> V_67 & 0x00ff ] ;
if ( V_106 )
return V_106 ( V_2 ) ;
return - V_68 ;
}
