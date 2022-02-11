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
static int F_21 ( struct V_1 * V_2 )
{
int V_7 = 0 ;
if ( ! ( V_2 -> V_9 . V_10 -> V_28 & ( V_29 | V_30 | V_31 ) ) )
return V_7 ;
V_7 = F_22 () ;
F_23 ( V_2 ) ;
V_2 -> V_9 . V_10 -> V_28 &= ~ ( V_29 | V_30 | V_31 ) ;
return V_7 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_7 = F_21 ( V_2 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_21 . V_32 ++ ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
F_25 ( V_2 , 4 ) ;
F_14 ( V_2 , 4 , L_4 , L_5 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
V_2 -> V_21 . V_33 ++ ;
if ( F_27 ( V_2 -> V_9 . V_10 -> V_11 ) . V_34 )
return F_2 ( V_2 , V_14 ) ;
F_28 ( V_2 -> V_16 -> V_9 . V_35 , ! F_29 ( V_2 ) ) ;
F_25 ( V_2 , 4 ) ;
F_14 ( V_2 , 4 , L_4 , L_6 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
T_5 V_36 ;
int V_37 ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
F_31 ( V_2 , NULL , & V_37 ) ;
V_36 = V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_37 ] & V_42 ;
V_36 = F_32 ( V_2 , V_36 ) ;
if ( F_33 ( V_2 , V_36 ) )
return F_34 ( V_2 , & V_2 -> V_9 . V_43 ) ;
V_36 = F_35 ( V_2 , V_36 ) ;
if ( F_12 ( V_2 -> V_16 , V_36 ) )
return F_2 ( V_2 , V_23 ) ;
if ( F_36 ( V_2 -> V_16 , V_36 , V_44 ) )
return - V_45 ;
F_7 ( V_2 , 0 ) ;
V_2 -> V_38 -> V_39 . V_40 . V_41 [ 0 ] = 0 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_46 * V_47 ;
unsigned long V_48 ;
T_3 V_49 [ 3 ] ;
int V_50 , V_7 ;
T_2 V_36 ;
V_7 = 0 ;
V_36 = F_3 ( V_2 ) ;
if ( V_36 & 3 )
return F_2 ( V_2 , V_15 ) ;
V_50 = 0 ;
V_47 = F_38 ( V_2 -> V_16 , V_2 -> V_9 . V_10 -> V_51 [ 6 ] , 0 ) ;
if ( ! V_47 )
goto V_52;
V_50 = 1 ;
V_49 [ 0 ] = V_47 -> V_53 . V_54 << 16 | V_47 -> V_53 . V_55 ;
V_49 [ 1 ] = V_47 -> V_53 . V_56 ;
V_49 [ 2 ] = V_47 -> V_53 . V_57 ;
if ( V_36 ) {
V_48 = sizeof( V_49 ) - 4 ;
V_7 = F_18 ( V_2 , V_36 , & V_49 , V_48 ) ;
if ( V_7 )
return F_5 ( V_2 , V_7 ) ;
} else {
V_48 = sizeof( V_49 ) ;
if ( F_39 ( V_2 , V_58 , & V_49 , V_48 ) )
V_7 = - V_45 ;
}
if ( ! V_7 )
F_40 ( V_47 ) ;
else
F_41 ( V_2 -> V_16 , V_47 ) ;
V_52:
if ( ! V_7 )
F_7 ( V_2 , V_50 ) ;
return V_7 ? - V_45 : 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_46 * V_47 ;
V_47 = F_38 ( V_2 -> V_16 , 0 ,
V_2 -> V_38 -> V_39 . V_40 . V_41 [ 1 ] ) ;
V_2 -> V_38 -> V_59 = V_60 ;
V_2 -> V_38 -> V_61 . V_62 = ! ! V_47 ;
if ( V_47 ) {
V_2 -> V_38 -> V_61 . V_54 = V_47 -> V_53 . V_54 ;
V_2 -> V_38 -> V_61 . V_55 = V_47 -> V_53 . V_55 ;
V_2 -> V_38 -> V_61 . V_56 = V_47 -> V_53 . V_56 ;
V_2 -> V_38 -> V_61 . V_57 = V_47 -> V_53 . V_57 ;
}
V_2 -> V_38 -> V_61 . V_63 = V_2 -> V_9 . V_10 -> V_63 ;
F_40 ( V_47 ) ;
return - V_64 ;
}
static int F_43 ( struct V_1 * V_2 )
{
F_14 ( V_2 , 4 , L_4 , L_7 ) ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
if ( V_2 -> V_16 -> V_9 . V_65 ) {
if ( V_2 -> V_9 . V_10 -> V_66 == 0xb236 )
return F_37 ( V_2 ) ;
if ( V_2 -> V_9 . V_10 -> V_66 == 0xb235 )
return F_42 ( V_2 ) ;
return - V_67 ;
} else {
F_7 ( V_2 , 3 ) ;
return 0 ;
}
}
static int F_44 ( struct V_1 * V_2 )
{
int V_7 ;
unsigned int V_68 ;
V_2 -> V_21 . V_69 ++ ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
V_68 = * V_2 -> V_16 -> V_9 . V_70 . V_68 -> V_71 >> 32 ;
V_7 = F_39 ( V_2 , F_45 ( struct V_72 , V_73 ) ,
& V_68 , sizeof( V_68 ) ) ;
if ( V_7 )
return V_7 ;
F_14 ( V_2 , 5 , L_8 , V_68 ) ;
F_46 ( V_2 , V_68 ) ;
return 0 ;
}
int F_47 ( T_6 * V_74 )
{
if ( V_74 -> V_12 & V_75 )
return 0 ;
if ( ( V_74 -> V_12 & V_76 ) == V_77 ) {
if ( V_74 -> V_36 & ~ V_78 )
return 0 ;
}
if ( ! ( V_74 -> V_12 & V_76 ) && ( V_74 -> V_36 & ~ V_79 ) )
return 0 ;
if ( ( V_74 -> V_12 & V_76 ) == V_80 )
return 0 ;
if ( V_74 -> V_36 & 1 )
return 0 ;
return 1 ;
}
int F_48 ( struct V_1 * V_2 )
{
T_6 * V_11 = & V_2 -> V_9 . V_10 -> V_11 ;
T_7 V_81 ;
T_2 V_36 ;
int V_7 ;
if ( V_11 -> V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
V_36 = F_3 ( V_2 ) ;
if ( V_36 & 7 )
return F_2 ( V_2 , V_15 ) ;
V_7 = F_4 ( V_2 , V_36 , & V_81 , sizeof( V_81 ) ) ;
if ( V_7 )
return F_5 ( V_2 , V_7 ) ;
if ( ! ( V_81 . V_12 & V_82 ) )
return F_2 ( V_2 , V_15 ) ;
V_11 -> V_12 = ( V_81 . V_12 & ~ V_82 ) << 32 ;
V_11 -> V_12 |= V_81 . V_36 & V_83 ;
V_11 -> V_36 = V_81 . V_36 & ~ V_83 ;
if ( ! F_47 ( V_11 ) )
return F_2 ( V_2 , V_15 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
T_6 V_81 ;
T_2 V_36 ;
int V_7 ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
V_36 = F_3 ( V_2 ) ;
if ( V_36 & 7 )
return F_2 ( V_2 , V_15 ) ;
V_7 = F_4 ( V_2 , V_36 , & V_81 , sizeof( V_81 ) ) ;
if ( V_7 )
return F_5 ( V_2 , V_7 ) ;
V_2 -> V_9 . V_10 -> V_11 = V_81 ;
if ( ! F_47 ( & V_2 -> V_9 . V_10 -> V_11 ) )
return F_2 ( V_2 , V_15 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
T_2 V_84 = V_2 -> V_9 . V_84 ;
T_2 V_19 ;
int V_7 ;
V_2 -> V_21 . V_85 ++ ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
V_19 = F_3 ( V_2 ) ;
if ( V_19 & 7 )
return F_2 ( V_2 , V_15 ) ;
V_7 = F_18 ( V_2 , V_19 , & V_84 , sizeof( V_84 ) ) ;
if ( V_7 )
return F_5 ( V_2 , V_7 ) ;
F_14 ( V_2 , 5 , L_4 , L_9 ) ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 , struct V_86 * V_87 )
{
int V_88 = 0 ;
int V_89 ;
V_88 = F_52 ( & V_2 -> V_16 -> V_90 ) ;
if ( F_53 ( V_87 , 3 , 2 , 2 ) )
V_87 -> V_91 = 0 ;
if ( V_87 -> V_91 < 8 )
V_87 -> V_91 ++ ;
for ( V_89 = V_87 -> V_91 - 1 ; V_89 > 0 ; V_89 -- )
memcpy ( & V_87 -> V_92 [ V_89 ] , & V_87 -> V_92 [ V_89 - 1 ] , sizeof( V_87 -> V_92 [ 0 ] ) ) ;
V_87 -> V_92 [ 0 ] . V_93 = V_88 ;
V_87 -> V_92 [ 0 ] . V_94 = V_88 ;
V_87 -> V_92 [ 0 ] . V_95 = 0 ;
V_87 -> V_92 [ 0 ] . V_96 = 0 ;
V_87 -> V_92 [ 0 ] . V_97 = 1000 ;
memcpy ( V_87 -> V_92 [ 0 ] . V_98 , L_10 , 8 ) ;
F_54 ( V_87 -> V_92 [ 0 ] . V_98 , 8 ) ;
memcpy ( V_87 -> V_92 [ 0 ] . V_99 , L_11 , 16 ) ;
F_54 ( V_87 -> V_92 [ 0 ] . V_99 , 16 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
int V_100 = ( V_2 -> V_38 -> V_39 . V_40 . V_41 [ 0 ] & 0xf0000000 ) >> 28 ;
int V_101 = V_2 -> V_38 -> V_39 . V_40 . V_41 [ 0 ] & 0xff ;
int V_102 = V_2 -> V_38 -> V_39 . V_40 . V_41 [ 1 ] & 0xffff ;
unsigned long V_87 = 0 ;
T_2 V_19 ;
int V_7 = 0 ;
V_2 -> V_21 . V_103 ++ ;
F_14 ( V_2 , 4 , L_12 , V_100 , V_101 , V_102 ) ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
if ( V_100 > 3 ) {
F_7 ( V_2 , 3 ) ;
return 0 ;
}
if ( V_2 -> V_38 -> V_39 . V_40 . V_41 [ 0 ] & 0x0fffff00
|| V_2 -> V_38 -> V_39 . V_40 . V_41 [ 1 ] & 0xffff0000 )
return F_2 ( V_2 , V_15 ) ;
if ( V_100 == 0 ) {
V_2 -> V_38 -> V_39 . V_40 . V_41 [ 0 ] = 3 << 28 ;
F_7 ( V_2 , 0 ) ;
return 0 ;
}
V_19 = F_3 ( V_2 ) ;
if ( V_19 & 0xfff )
return F_2 ( V_2 , V_15 ) ;
switch ( V_100 ) {
case 1 :
case 2 :
V_87 = F_56 ( V_104 ) ;
if ( ! V_87 )
goto V_105;
if ( F_53 ( ( void * ) V_87 , V_100 , V_101 , V_102 ) )
goto V_105;
break;
case 3 :
if ( V_101 != 2 || V_102 != 2 )
goto V_105;
V_87 = F_56 ( V_104 ) ;
if ( ! V_87 )
goto V_105;
F_51 ( V_2 , ( void * ) V_87 ) ;
break;
}
V_7 = F_18 ( V_2 , V_19 , ( void * ) V_87 , V_44 ) ;
if ( V_7 ) {
V_7 = F_5 ( V_2 , V_7 ) ;
goto V_106;
}
F_57 ( V_2 , V_100 , V_101 , V_102 , V_19 ) ;
F_58 ( V_87 ) ;
F_7 ( V_2 , 0 ) ;
V_2 -> V_38 -> V_39 . V_40 . V_41 [ 0 ] = 0 ;
return 0 ;
V_105:
F_7 ( V_2 , 3 ) ;
V_106:
F_58 ( V_87 ) ;
return V_7 ;
}
int F_59 ( struct V_1 * V_2 )
{
T_8 V_107 ;
V_107 = V_108 [ V_2 -> V_9 . V_10 -> V_66 & 0x00ff ] ;
if ( V_107 )
return V_107 ( V_2 ) ;
return - V_67 ;
}
static int F_60 ( struct V_1 * V_2 )
{
int V_109 , V_37 ;
F_31 ( V_2 , & V_109 , & V_37 ) ;
V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_109 ] &= 0xffffffff00000000UL ;
V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_109 ] |= V_2 -> V_9 . V_10 -> V_11 . V_12 >> 32 ;
if ( V_37 ) {
V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_37 ] &= 0xffffffff00000000UL ;
V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_37 ] |=
V_2 -> V_9 . V_10 -> V_11 . V_12 & 0x00000000ffffffffUL ;
}
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_109 , V_37 ;
unsigned long V_110 , V_111 ;
V_2 -> V_21 . V_112 ++ ;
F_31 ( V_2 , & V_109 , & V_37 ) ;
if ( ! V_113 )
return F_2 ( V_2 , V_114 ) ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
if ( V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_109 ] & V_115 )
return F_2 ( V_2 , V_15 ) ;
if ( V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_109 ] & V_116 && ! F_62 ( 14 ) )
return F_2 ( V_2 , V_15 ) ;
if ( V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_109 ] & ( V_117 | V_118 ) )
return F_2 ( V_2 , V_15 ) ;
V_110 = V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_37 ] & V_42 ;
V_110 = F_32 ( V_2 , V_110 ) ;
switch ( V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_109 ] & V_119 ) {
case 0x00000000 :
V_111 = ( V_110 + ( 1UL << 12 ) ) & ~ ( ( 1UL << 12 ) - 1 ) ;
break;
case 0x00001000 :
V_111 = ( V_110 + ( 1UL << 20 ) ) & ~ ( ( 1UL << 20 ) - 1 ) ;
break;
default:
return F_2 ( V_2 , V_15 ) ;
}
if ( V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_109 ] & V_120 ) {
if ( F_33 ( V_2 , V_110 ) )
return F_34 ( V_2 , & V_2 -> V_9 . V_43 ) ;
}
while ( V_110 < V_111 ) {
unsigned long V_121 , V_122 ;
if ( ( V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_109 ] & V_119 ) == 0 )
V_122 = F_35 ( V_2 , V_110 ) ;
else
V_122 = V_110 ;
V_121 = F_63 ( V_2 -> V_16 , F_64 ( V_122 ) ) ;
if ( F_65 ( V_121 ) )
return F_2 ( V_2 , V_23 ) ;
if ( V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_109 ] & V_120 ) {
if ( F_66 ( ( void V_123 * ) V_121 , V_44 ) )
return F_2 ( V_2 , V_23 ) ;
}
if ( V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_109 ] & V_124 ) {
int V_7 = F_21 ( V_2 ) ;
if ( V_7 )
return V_7 ;
if ( F_67 ( V_125 -> V_126 , V_121 ,
V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_109 ] & V_127 ,
V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_109 ] & V_116 ) )
return F_2 ( V_2 , V_23 ) ;
}
V_110 += V_44 ;
}
if ( V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_109 ] & V_119 )
V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_37 ] = V_111 ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 )
{
int V_128 = ( V_2 -> V_9 . V_10 -> V_129 & ~ V_42 ) >> 3 ;
unsigned long * V_129 , V_130 ;
struct V_131 * V_131 ;
int V_6 ;
F_14 ( V_2 , 5 , L_13 , V_128 ) ;
V_131 = V_2 -> V_9 . V_131 ;
V_2 -> V_21 . V_132 ++ ;
if ( ! F_69 ( V_2 -> V_16 ) )
return F_2 ( V_2 , V_114 ) ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
if ( ( ( V_2 -> V_9 . V_10 -> V_63 & 0xf0000000 ) >> 28 ) > 6 )
return F_2 ( V_2 , V_15 ) ;
F_25 ( V_2 , 4 ) ;
V_2 -> V_9 . V_10 -> V_129 &= V_42 ;
V_129 = F_70 ( V_2 -> V_9 . V_10 -> V_129 ) ;
F_71 ( & V_131 -> V_126 -> V_133 ) ;
for ( V_6 = 0 ; V_6 < V_128 ; ++ V_6 ) {
V_130 = V_129 [ V_6 ] ;
if ( F_72 ( V_130 & ~ V_42 || V_130 < 2 * V_44 ) )
break;
F_73 ( V_131 , V_130 ) ;
}
F_74 ( & V_131 -> V_126 -> V_133 ) ;
if ( V_6 < V_128 )
return F_2 ( V_2 , V_15 ) ;
return 0 ;
}
int F_75 ( struct V_1 * V_2 )
{
T_8 V_107 ;
V_107 = V_134 [ V_2 -> V_9 . V_10 -> V_66 & 0x00ff ] ;
if ( V_107 )
return V_107 ( V_2 ) ;
return - V_67 ;
}
int F_76 ( struct V_1 * V_2 )
{
int V_109 = ( V_2 -> V_9 . V_10 -> V_66 & 0x00f0 ) >> 4 ;
int V_135 = V_2 -> V_9 . V_10 -> V_66 & 0x000f ;
int V_136 , V_7 , V_137 ;
T_3 V_138 [ 16 ] ;
T_2 V_26 ;
V_2 -> V_21 . V_139 ++ ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
V_26 = F_77 ( V_2 ) ;
if ( V_26 & 3 )
return F_2 ( V_2 , V_15 ) ;
F_14 ( V_2 , 5 , L_14 , V_109 , V_135 , V_26 ) ;
F_78 ( V_2 , 0 , V_109 , V_135 , V_26 ) ;
V_137 = ( ( V_135 - V_109 ) & 0xf ) + 1 ;
V_7 = F_4 ( V_2 , V_26 , V_138 , V_137 * sizeof( T_3 ) ) ;
if ( V_7 )
return F_5 ( V_2 , V_7 ) ;
V_136 = V_109 ;
V_137 = 0 ;
do {
V_2 -> V_9 . V_10 -> V_51 [ V_136 ] &= 0xffffffff00000000ul ;
V_2 -> V_9 . V_10 -> V_51 [ V_136 ] |= V_138 [ V_137 ++ ] ;
if ( V_136 == V_135 )
break;
V_136 = ( V_136 + 1 ) % 16 ;
} while ( 1 );
F_79 ( V_140 , V_2 ) ;
return 0 ;
}
int F_80 ( struct V_1 * V_2 )
{
int V_109 = ( V_2 -> V_9 . V_10 -> V_66 & 0x00f0 ) >> 4 ;
int V_135 = V_2 -> V_9 . V_10 -> V_66 & 0x000f ;
int V_136 , V_7 , V_137 ;
T_3 V_138 [ 16 ] ;
T_2 V_26 ;
V_2 -> V_21 . V_141 ++ ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
V_26 = F_77 ( V_2 ) ;
if ( V_26 & 3 )
return F_2 ( V_2 , V_15 ) ;
F_14 ( V_2 , 5 , L_15 , V_109 , V_135 , V_26 ) ;
F_81 ( V_2 , 0 , V_109 , V_135 , V_26 ) ;
V_136 = V_109 ;
V_137 = 0 ;
do {
V_138 [ V_137 ++ ] = V_2 -> V_9 . V_10 -> V_51 [ V_136 ] ;
if ( V_136 == V_135 )
break;
V_136 = ( V_136 + 1 ) % 16 ;
} while ( 1 );
V_7 = F_18 ( V_2 , V_26 , V_138 , V_137 * sizeof( T_3 ) ) ;
return V_7 ? F_5 ( V_2 , V_7 ) : 0 ;
}
static int F_82 ( struct V_1 * V_2 )
{
int V_109 = ( V_2 -> V_9 . V_10 -> V_66 & 0x00f0 ) >> 4 ;
int V_135 = V_2 -> V_9 . V_10 -> V_66 & 0x000f ;
int V_136 , V_7 , V_137 ;
T_2 V_138 [ 16 ] ;
T_2 V_26 ;
V_2 -> V_21 . V_142 ++ ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
V_26 = F_83 ( V_2 ) ;
if ( V_26 & 7 )
return F_2 ( V_2 , V_15 ) ;
F_14 ( V_2 , 5 , L_16 , V_109 , V_135 , V_26 ) ;
F_78 ( V_2 , 1 , V_109 , V_135 , V_26 ) ;
V_137 = ( ( V_135 - V_109 ) & 0xf ) + 1 ;
V_7 = F_4 ( V_2 , V_26 , V_138 , V_137 * sizeof( T_2 ) ) ;
if ( V_7 )
return F_5 ( V_2 , V_7 ) ;
V_136 = V_109 ;
V_137 = 0 ;
do {
V_2 -> V_9 . V_10 -> V_51 [ V_136 ] = V_138 [ V_137 ++ ] ;
if ( V_136 == V_135 )
break;
V_136 = ( V_136 + 1 ) % 16 ;
} while ( 1 );
F_79 ( V_140 , V_2 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 )
{
int V_109 = ( V_2 -> V_9 . V_10 -> V_66 & 0x00f0 ) >> 4 ;
int V_135 = V_2 -> V_9 . V_10 -> V_66 & 0x000f ;
int V_136 , V_7 , V_137 ;
T_2 V_138 [ 16 ] ;
T_2 V_26 ;
V_2 -> V_21 . V_143 ++ ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
V_26 = F_83 ( V_2 ) ;
if ( V_26 & 7 )
return F_2 ( V_2 , V_15 ) ;
F_14 ( V_2 , 5 , L_17 , V_109 , V_135 , V_26 ) ;
F_81 ( V_2 , 1 , V_109 , V_135 , V_26 ) ;
V_136 = V_109 ;
V_137 = 0 ;
do {
V_138 [ V_137 ++ ] = V_2 -> V_9 . V_10 -> V_51 [ V_136 ] ;
if ( V_136 == V_135 )
break;
V_136 = ( V_136 + 1 ) % 16 ;
} while ( 1 );
V_7 = F_18 ( V_2 , V_26 , V_138 , V_137 * sizeof( T_2 ) ) ;
return V_7 ? F_5 ( V_2 , V_7 ) : 0 ;
}
int F_85 ( struct V_1 * V_2 )
{
T_8 V_107 ;
V_107 = V_144 [ V_2 -> V_9 . V_10 -> V_63 & 0xff ] ;
if ( V_107 )
return V_107 ( V_2 ) ;
return - V_67 ;
}
static int F_86 ( struct V_1 * V_2 )
{
T_2 V_145 , V_146 ;
unsigned long V_147 , V_148 ;
int V_149 = 0 , V_50 = 0 ;
bool V_150 ;
V_2 -> V_21 . V_151 ++ ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
F_87 ( V_2 , & V_145 , & V_146 ) ;
if ( V_146 & 0xf0 )
return - V_67 ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_152 )
F_88 ( V_2 ) ;
V_149 = F_89 ( V_2 , V_145 , & V_148 , 1 ) ;
if ( V_149 == V_153 ) {
V_50 = 1 ;
V_149 = F_89 ( V_2 , V_145 , & V_148 , 0 ) ;
}
if ( V_149 ) {
if ( V_149 == V_23 || V_149 == V_154 ) {
V_149 = F_2 ( V_2 , V_149 ) ;
} else if ( V_149 > 0 ) {
F_7 ( V_2 , 3 ) ;
V_149 = 0 ;
}
goto V_155;
}
V_147 = F_90 ( V_2 -> V_16 , F_64 ( V_148 ) , & V_150 ) ;
if ( F_65 ( V_147 ) ) {
V_149 = F_2 ( V_2 , V_23 ) ;
} else {
if ( ! V_150 )
V_50 = 1 ;
F_7 ( V_2 , V_50 ) ;
}
V_155:
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_152 )
F_91 ( V_2 ) ;
return V_149 ;
}
int F_92 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_9 . V_10 -> V_66 & 0x00ff ) == 0x01 )
return F_86 ( V_2 ) ;
return - V_67 ;
}
static int F_93 ( struct V_1 * V_2 )
{
T_3 V_156 ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
if ( V_2 -> V_38 -> V_39 . V_40 . V_41 [ 0 ] & 0x00000000ffff0000 )
return F_2 ( V_2 ,
V_15 ) ;
V_156 = V_2 -> V_38 -> V_39 . V_40 . V_41 [ 0 ] & 0x000000000000ffff ;
V_2 -> V_9 . V_10 -> V_157 = V_156 ;
return 0 ;
}
int F_94 ( struct V_1 * V_2 )
{
T_8 V_107 ;
V_107 = V_158 [ V_2 -> V_9 . V_10 -> V_66 & 0x00ff ] ;
if ( V_107 )
return V_107 ( V_2 ) ;
return - V_67 ;
}
