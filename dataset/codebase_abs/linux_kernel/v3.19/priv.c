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
V_2 -> V_21 . V_68 ++ ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
V_7 = F_39 ( V_2 , F_45 ( struct V_69 , V_70 ) ,
V_71 , 4 ) ;
if ( V_7 )
return V_7 ;
F_14 ( V_2 , 5 , L_8 ,
* ( unsigned int * ) V_71 ) ;
F_46 ( V_2 , * ( unsigned int * ) V_71 ) ;
return 0 ;
}
int F_47 ( T_6 * V_72 )
{
if ( V_72 -> V_12 & V_73 )
return 0 ;
if ( ( V_72 -> V_12 & V_74 ) == V_75 ) {
if ( V_72 -> V_36 & ~ V_76 )
return 0 ;
}
if ( ! ( V_72 -> V_12 & V_74 ) && ( V_72 -> V_36 & ~ V_77 ) )
return 0 ;
if ( ( V_72 -> V_12 & V_74 ) == V_78 )
return 0 ;
if ( V_72 -> V_36 & 1 )
return 0 ;
return 1 ;
}
int F_48 ( struct V_1 * V_2 )
{
T_6 * V_11 = & V_2 -> V_9 . V_10 -> V_11 ;
T_7 V_79 ;
T_2 V_36 ;
int V_7 ;
if ( V_11 -> V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
V_36 = F_3 ( V_2 ) ;
if ( V_36 & 7 )
return F_2 ( V_2 , V_15 ) ;
V_7 = F_4 ( V_2 , V_36 , & V_79 , sizeof( V_79 ) ) ;
if ( V_7 )
return F_5 ( V_2 , V_7 ) ;
if ( ! ( V_79 . V_12 & V_80 ) )
return F_2 ( V_2 , V_15 ) ;
V_11 -> V_12 = ( V_79 . V_12 & ~ V_80 ) << 32 ;
V_11 -> V_12 |= V_79 . V_36 & V_81 ;
V_11 -> V_36 = V_79 . V_36 & ~ V_81 ;
if ( ! F_47 ( V_11 ) )
return F_2 ( V_2 , V_15 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
T_6 V_79 ;
T_2 V_36 ;
int V_7 ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
V_36 = F_3 ( V_2 ) ;
if ( V_36 & 7 )
return F_2 ( V_2 , V_15 ) ;
V_7 = F_4 ( V_2 , V_36 , & V_79 , sizeof( V_79 ) ) ;
if ( V_7 )
return F_5 ( V_2 , V_7 ) ;
V_2 -> V_9 . V_10 -> V_11 = V_79 ;
if ( ! F_47 ( & V_2 -> V_9 . V_10 -> V_11 ) )
return F_2 ( V_2 , V_15 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
T_2 V_82 = V_2 -> V_9 . V_82 ;
T_2 V_19 ;
int V_7 ;
V_2 -> V_21 . V_83 ++ ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
V_19 = F_3 ( V_2 ) ;
if ( V_19 & 7 )
return F_2 ( V_2 , V_15 ) ;
V_7 = F_18 ( V_2 , V_19 , & V_82 , sizeof( V_82 ) ) ;
if ( V_7 )
return F_5 ( V_2 , V_7 ) ;
F_14 ( V_2 , 5 , L_4 , L_9 ) ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 , struct V_84 * V_85 )
{
int V_86 = 0 ;
int V_87 ;
V_86 = F_52 ( & V_2 -> V_16 -> V_88 ) ;
if ( F_53 ( V_85 , 3 , 2 , 2 ) )
V_85 -> V_89 = 0 ;
if ( V_85 -> V_89 < 8 )
V_85 -> V_89 ++ ;
for ( V_87 = V_85 -> V_89 - 1 ; V_87 > 0 ; V_87 -- )
memcpy ( & V_85 -> V_90 [ V_87 ] , & V_85 -> V_90 [ V_87 - 1 ] , sizeof( V_85 -> V_90 [ 0 ] ) ) ;
V_85 -> V_90 [ 0 ] . V_91 = V_86 ;
V_85 -> V_90 [ 0 ] . V_92 = V_86 ;
V_85 -> V_90 [ 0 ] . V_93 = 0 ;
V_85 -> V_90 [ 0 ] . V_94 = 0 ;
V_85 -> V_90 [ 0 ] . V_95 = 1000 ;
memcpy ( V_85 -> V_90 [ 0 ] . V_96 , L_10 , 8 ) ;
F_54 ( V_85 -> V_90 [ 0 ] . V_96 , 8 ) ;
memcpy ( V_85 -> V_90 [ 0 ] . V_97 , L_11 , 16 ) ;
F_54 ( V_85 -> V_90 [ 0 ] . V_97 , 16 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
int V_98 = ( V_2 -> V_38 -> V_39 . V_40 . V_41 [ 0 ] & 0xf0000000 ) >> 28 ;
int V_99 = V_2 -> V_38 -> V_39 . V_40 . V_41 [ 0 ] & 0xff ;
int V_100 = V_2 -> V_38 -> V_39 . V_40 . V_41 [ 1 ] & 0xffff ;
unsigned long V_85 = 0 ;
T_2 V_19 ;
int V_7 = 0 ;
V_2 -> V_21 . V_101 ++ ;
F_14 ( V_2 , 4 , L_12 , V_98 , V_99 , V_100 ) ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
if ( V_98 > 3 ) {
F_7 ( V_2 , 3 ) ;
return 0 ;
}
if ( V_2 -> V_38 -> V_39 . V_40 . V_41 [ 0 ] & 0x0fffff00
|| V_2 -> V_38 -> V_39 . V_40 . V_41 [ 1 ] & 0xffff0000 )
return F_2 ( V_2 , V_15 ) ;
if ( V_98 == 0 ) {
V_2 -> V_38 -> V_39 . V_40 . V_41 [ 0 ] = 3 << 28 ;
F_7 ( V_2 , 0 ) ;
return 0 ;
}
V_19 = F_3 ( V_2 ) ;
if ( V_19 & 0xfff )
return F_2 ( V_2 , V_15 ) ;
switch ( V_98 ) {
case 1 :
case 2 :
V_85 = F_56 ( V_102 ) ;
if ( ! V_85 )
goto V_103;
if ( F_53 ( ( void * ) V_85 , V_98 , V_99 , V_100 ) )
goto V_103;
break;
case 3 :
if ( V_99 != 2 || V_100 != 2 )
goto V_103;
V_85 = F_56 ( V_102 ) ;
if ( ! V_85 )
goto V_103;
F_51 ( V_2 , ( void * ) V_85 ) ;
break;
}
V_7 = F_18 ( V_2 , V_19 , ( void * ) V_85 , V_44 ) ;
if ( V_7 ) {
V_7 = F_5 ( V_2 , V_7 ) ;
goto V_104;
}
F_57 ( V_2 , V_98 , V_99 , V_100 , V_19 ) ;
F_58 ( V_85 ) ;
F_7 ( V_2 , 0 ) ;
V_2 -> V_38 -> V_39 . V_40 . V_41 [ 0 ] = 0 ;
return 0 ;
V_103:
F_7 ( V_2 , 3 ) ;
V_104:
F_58 ( V_85 ) ;
return V_7 ;
}
int F_59 ( struct V_1 * V_2 )
{
T_8 V_105 ;
V_105 = V_106 [ V_2 -> V_9 . V_10 -> V_66 & 0x00ff ] ;
if ( V_105 )
return V_105 ( V_2 ) ;
return - V_67 ;
}
static int F_60 ( struct V_1 * V_2 )
{
int V_107 , V_37 ;
F_31 ( V_2 , & V_107 , & V_37 ) ;
V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_107 ] &= 0xffffffff00000000UL ;
V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_107 ] |= V_2 -> V_9 . V_10 -> V_11 . V_12 >> 32 ;
if ( V_37 ) {
V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_37 ] &= 0xffffffff00000000UL ;
V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_37 ] |=
V_2 -> V_9 . V_10 -> V_11 . V_12 & 0x00000000ffffffffUL ;
}
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_107 , V_37 ;
unsigned long V_108 , V_109 ;
V_2 -> V_21 . V_110 ++ ;
F_31 ( V_2 , & V_107 , & V_37 ) ;
if ( ! V_111 )
return F_2 ( V_2 , V_112 ) ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
if ( V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_107 ] & V_113 )
return F_2 ( V_2 , V_15 ) ;
if ( V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_107 ] & V_114 && ! F_62 ( 14 ) )
return F_2 ( V_2 , V_15 ) ;
if ( V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_107 ] & ( V_115 | V_116 ) )
return F_2 ( V_2 , V_15 ) ;
V_108 = V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_37 ] & V_42 ;
V_108 = F_32 ( V_2 , V_108 ) ;
switch ( V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_107 ] & V_117 ) {
case 0x00000000 :
V_109 = ( V_108 + ( 1UL << 12 ) ) & ~ ( ( 1UL << 12 ) - 1 ) ;
break;
case 0x00001000 :
V_109 = ( V_108 + ( 1UL << 20 ) ) & ~ ( ( 1UL << 20 ) - 1 ) ;
break;
default:
return F_2 ( V_2 , V_15 ) ;
}
if ( V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_107 ] & V_118 ) {
if ( F_33 ( V_2 , V_108 ) )
return F_34 ( V_2 , & V_2 -> V_9 . V_43 ) ;
}
while ( V_108 < V_109 ) {
unsigned long V_119 , V_120 ;
if ( ( V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_107 ] & V_117 ) == 0 )
V_120 = F_35 ( V_2 , V_108 ) ;
else
V_120 = V_108 ;
V_119 = F_63 ( V_2 -> V_16 , F_64 ( V_120 ) ) ;
if ( F_65 ( V_119 ) )
return F_2 ( V_2 , V_23 ) ;
if ( V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_107 ] & V_118 ) {
if ( F_66 ( ( void V_121 * ) V_119 , V_44 ) )
return F_2 ( V_2 , V_23 ) ;
}
if ( V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_107 ] & V_122 ) {
int V_7 = F_21 ( V_2 ) ;
if ( V_7 )
return V_7 ;
if ( F_67 ( V_123 -> V_124 , V_119 ,
V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_107 ] & V_125 ,
V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_107 ] & V_114 ) )
return F_2 ( V_2 , V_23 ) ;
}
V_108 += V_44 ;
}
if ( V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_107 ] & V_117 )
V_2 -> V_38 -> V_39 . V_40 . V_41 [ V_37 ] = V_109 ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 )
{
int V_126 = ( V_2 -> V_9 . V_10 -> V_127 & ~ V_42 ) >> 3 ;
unsigned long * V_127 , V_128 ;
struct V_129 * V_129 ;
int V_6 ;
F_14 ( V_2 , 5 , L_13 , V_126 ) ;
V_129 = V_2 -> V_9 . V_129 ;
V_2 -> V_21 . V_130 ++ ;
if ( ! F_69 ( V_2 -> V_16 ) )
return F_2 ( V_2 , V_112 ) ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
if ( ( ( V_2 -> V_9 . V_10 -> V_63 & 0xf0000000 ) >> 28 ) > 6 )
return F_2 ( V_2 , V_15 ) ;
F_25 ( V_2 , 4 ) ;
V_2 -> V_9 . V_10 -> V_127 &= V_42 ;
V_127 = F_70 ( V_2 -> V_9 . V_10 -> V_127 ) ;
F_71 ( & V_129 -> V_124 -> V_131 ) ;
for ( V_6 = 0 ; V_6 < V_126 ; ++ V_6 ) {
V_128 = V_127 [ V_6 ] ;
if ( F_72 ( V_128 & ~ V_42 || V_128 < 2 * V_44 ) )
break;
F_73 ( V_129 , V_128 ) ;
}
F_74 ( & V_129 -> V_124 -> V_131 ) ;
if ( V_6 < V_126 )
return F_2 ( V_2 , V_15 ) ;
return 0 ;
}
int F_75 ( struct V_1 * V_2 )
{
T_8 V_105 ;
V_105 = V_132 [ V_2 -> V_9 . V_10 -> V_66 & 0x00ff ] ;
if ( V_105 )
return V_105 ( V_2 ) ;
return - V_67 ;
}
int F_76 ( struct V_1 * V_2 )
{
int V_107 = ( V_2 -> V_9 . V_10 -> V_66 & 0x00f0 ) >> 4 ;
int V_133 = V_2 -> V_9 . V_10 -> V_66 & 0x000f ;
int V_134 , V_7 , V_135 ;
T_3 V_136 [ 16 ] ;
T_2 V_26 ;
V_2 -> V_21 . V_137 ++ ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
V_26 = F_77 ( V_2 ) ;
if ( V_26 & 3 )
return F_2 ( V_2 , V_15 ) ;
F_14 ( V_2 , 5 , L_14 , V_107 , V_133 , V_26 ) ;
F_78 ( V_2 , 0 , V_107 , V_133 , V_26 ) ;
V_135 = ( ( V_133 - V_107 ) & 0xf ) + 1 ;
V_7 = F_4 ( V_2 , V_26 , V_136 , V_135 * sizeof( T_3 ) ) ;
if ( V_7 )
return F_5 ( V_2 , V_7 ) ;
V_134 = V_107 ;
V_135 = 0 ;
do {
V_2 -> V_9 . V_10 -> V_51 [ V_134 ] &= 0xffffffff00000000ul ;
V_2 -> V_9 . V_10 -> V_51 [ V_134 ] |= V_136 [ V_135 ++ ] ;
if ( V_134 == V_133 )
break;
V_134 = ( V_134 + 1 ) % 16 ;
} while ( 1 );
F_79 ( V_138 , V_2 ) ;
return 0 ;
}
int F_80 ( struct V_1 * V_2 )
{
int V_107 = ( V_2 -> V_9 . V_10 -> V_66 & 0x00f0 ) >> 4 ;
int V_133 = V_2 -> V_9 . V_10 -> V_66 & 0x000f ;
int V_134 , V_7 , V_135 ;
T_3 V_136 [ 16 ] ;
T_2 V_26 ;
V_2 -> V_21 . V_139 ++ ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
V_26 = F_77 ( V_2 ) ;
if ( V_26 & 3 )
return F_2 ( V_2 , V_15 ) ;
F_14 ( V_2 , 5 , L_15 , V_107 , V_133 , V_26 ) ;
F_81 ( V_2 , 0 , V_107 , V_133 , V_26 ) ;
V_134 = V_107 ;
V_135 = 0 ;
do {
V_136 [ V_135 ++ ] = V_2 -> V_9 . V_10 -> V_51 [ V_134 ] ;
if ( V_134 == V_133 )
break;
V_134 = ( V_134 + 1 ) % 16 ;
} while ( 1 );
V_7 = F_18 ( V_2 , V_26 , V_136 , V_135 * sizeof( T_3 ) ) ;
return V_7 ? F_5 ( V_2 , V_7 ) : 0 ;
}
static int F_82 ( struct V_1 * V_2 )
{
int V_107 = ( V_2 -> V_9 . V_10 -> V_66 & 0x00f0 ) >> 4 ;
int V_133 = V_2 -> V_9 . V_10 -> V_66 & 0x000f ;
int V_134 , V_7 , V_135 ;
T_2 V_136 [ 16 ] ;
T_2 V_26 ;
V_2 -> V_21 . V_140 ++ ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
V_26 = F_83 ( V_2 ) ;
if ( V_26 & 7 )
return F_2 ( V_2 , V_15 ) ;
F_14 ( V_2 , 5 , L_16 , V_107 , V_133 , V_26 ) ;
F_78 ( V_2 , 1 , V_107 , V_133 , V_26 ) ;
V_135 = ( ( V_133 - V_107 ) & 0xf ) + 1 ;
V_7 = F_4 ( V_2 , V_26 , V_136 , V_135 * sizeof( T_2 ) ) ;
if ( V_7 )
return F_5 ( V_2 , V_7 ) ;
V_134 = V_107 ;
V_135 = 0 ;
do {
V_2 -> V_9 . V_10 -> V_51 [ V_134 ] = V_136 [ V_135 ++ ] ;
if ( V_134 == V_133 )
break;
V_134 = ( V_134 + 1 ) % 16 ;
} while ( 1 );
F_79 ( V_138 , V_2 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 )
{
int V_107 = ( V_2 -> V_9 . V_10 -> V_66 & 0x00f0 ) >> 4 ;
int V_133 = V_2 -> V_9 . V_10 -> V_66 & 0x000f ;
int V_134 , V_7 , V_135 ;
T_2 V_136 [ 16 ] ;
T_2 V_26 ;
V_2 -> V_21 . V_141 ++ ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
V_26 = F_83 ( V_2 ) ;
if ( V_26 & 7 )
return F_2 ( V_2 , V_15 ) ;
F_14 ( V_2 , 5 , L_17 , V_107 , V_133 , V_26 ) ;
F_81 ( V_2 , 1 , V_107 , V_133 , V_26 ) ;
V_134 = V_107 ;
V_135 = 0 ;
do {
V_136 [ V_135 ++ ] = V_2 -> V_9 . V_10 -> V_51 [ V_134 ] ;
if ( V_134 == V_133 )
break;
V_134 = ( V_134 + 1 ) % 16 ;
} while ( 1 );
V_7 = F_18 ( V_2 , V_26 , V_136 , V_135 * sizeof( T_2 ) ) ;
return V_7 ? F_5 ( V_2 , V_7 ) : 0 ;
}
int F_85 ( struct V_1 * V_2 )
{
T_8 V_105 ;
V_105 = V_142 [ V_2 -> V_9 . V_10 -> V_63 & 0xff ] ;
if ( V_105 )
return V_105 ( V_2 ) ;
return - V_67 ;
}
static int F_86 ( struct V_1 * V_2 )
{
T_2 V_143 , V_144 ;
unsigned long V_145 , V_146 ;
int V_147 = 0 , V_50 = 0 ;
bool V_148 ;
V_2 -> V_21 . V_149 ++ ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
F_87 ( V_2 , & V_143 , & V_144 ) ;
if ( V_144 & 0xf0 )
return - V_67 ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_150 )
F_88 ( V_2 ) ;
V_147 = F_89 ( V_2 , V_143 , & V_146 , 1 ) ;
if ( V_147 == V_151 ) {
V_50 = 1 ;
V_147 = F_89 ( V_2 , V_143 , & V_146 , 0 ) ;
}
if ( V_147 ) {
if ( V_147 == V_23 || V_147 == V_152 ) {
V_147 = F_2 ( V_2 , V_147 ) ;
} else if ( V_147 > 0 ) {
F_7 ( V_2 , 3 ) ;
V_147 = 0 ;
}
goto V_153;
}
V_145 = F_90 ( V_2 -> V_16 , F_64 ( V_146 ) , & V_148 ) ;
if ( F_65 ( V_145 ) ) {
V_147 = F_2 ( V_2 , V_23 ) ;
} else {
if ( ! V_148 )
V_50 = 1 ;
F_7 ( V_2 , V_50 ) ;
}
V_153:
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_150 )
F_91 ( V_2 ) ;
return V_147 ;
}
int F_92 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_9 . V_10 -> V_66 & 0x00ff ) == 0x01 )
return F_86 ( V_2 ) ;
return - V_67 ;
}
static int F_93 ( struct V_1 * V_2 )
{
T_3 V_154 ;
if ( V_2 -> V_9 . V_10 -> V_11 . V_12 & V_13 )
return F_2 ( V_2 , V_14 ) ;
if ( V_2 -> V_38 -> V_39 . V_40 . V_41 [ 0 ] & 0x00000000ffff0000 )
return F_2 ( V_2 ,
V_15 ) ;
V_154 = V_2 -> V_38 -> V_39 . V_40 . V_41 [ 0 ] & 0x000000000000ffff ;
V_2 -> V_9 . V_10 -> V_155 = V_154 ;
return 0 ;
}
int F_94 ( struct V_1 * V_2 )
{
T_8 V_105 ;
V_105 = V_156 [ V_2 -> V_9 . V_10 -> V_66 & 0x00ff ] ;
if ( V_105 )
return V_105 ( V_2 ) ;
return - V_67 ;
}
