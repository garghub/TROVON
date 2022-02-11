static int F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_3 , 64 ) ) {
F_3 ( V_2 , 3 , L_1 , L_2 ) ;
V_2 -> V_4 . V_5 -> V_6 |= V_7 ;
F_4 ( V_2 ) ;
return 0 ;
} else
return F_5 ( V_2 , V_8 ) ;
}
int F_6 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_4 . V_5 -> V_9 & 0xf ) <= 4 )
return F_1 ( V_2 ) ;
else
return - V_10 ;
}
static int F_7 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_3 , 133 ) ) {
F_3 ( V_2 , 3 , L_1 , L_3 ) ;
F_8 () ;
F_9 ( 2 , 4 ) ;
V_11 -> V_12 . V_13 = (struct V_13 * ) & V_2 -> V_14 -> V_15 . V_16 . V_17 ;
F_10 ( V_11 -> V_12 . V_13 ) ;
F_11 () ;
V_2 -> V_4 . V_5 -> V_18 |= V_19 ;
V_2 -> V_4 . V_5 -> V_20 |= V_21 ;
V_2 -> V_4 . V_22 = 1 ;
F_4 ( V_2 ) ;
return 0 ;
} else
return F_5 ( V_2 , V_8 ) ;
}
int F_12 ( struct V_1 * V_2 )
{
int V_23 = V_2 -> V_4 . V_5 -> V_24 & 0xff ;
if ( V_23 == 0x49 || V_23 == 0x4d )
return F_7 ( V_2 ) ;
else
return - V_10 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_25 ;
T_1 V_26 ;
T_2 V_27 , V_28 ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
V_27 = F_14 ( V_2 , & V_26 ) ;
if ( V_27 & 7 )
return F_5 ( V_2 , V_33 ) ;
V_25 = F_15 ( V_2 , V_27 , V_26 , & V_28 , sizeof( V_28 ) ) ;
if ( V_25 )
return F_16 ( V_2 , V_25 ) ;
F_3 ( V_2 , 3 , L_4 , V_28 ) ;
F_17 ( V_2 -> V_3 , V_28 ) ;
F_18 ( V_2 , 0 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
T_2 V_34 ;
T_3 V_35 ;
int V_25 ;
T_1 V_26 ;
V_2 -> V_36 . V_37 ++ ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
V_34 = F_14 ( V_2 , & V_26 ) ;
if ( V_34 & 3 )
return F_5 ( V_2 , V_33 ) ;
V_25 = F_15 ( V_2 , V_34 , V_26 , & V_35 , sizeof( V_35 ) ) ;
if ( V_25 )
return F_16 ( V_2 , V_25 ) ;
V_35 &= 0x7fffe000u ;
if ( F_20 ( V_2 -> V_3 , V_35 ) )
return F_5 ( V_2 , V_38 ) ;
F_21 ( V_2 , V_35 ) ;
F_22 ( V_2 , 1 , V_35 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
T_2 V_34 ;
T_3 V_35 ;
int V_25 ;
T_1 V_26 ;
V_2 -> V_36 . V_39 ++ ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
V_34 = F_14 ( V_2 , & V_26 ) ;
if ( V_34 & 3 )
return F_5 ( V_2 , V_33 ) ;
V_35 = F_24 ( V_2 ) ;
V_25 = F_25 ( V_2 , V_34 , V_26 , & V_35 , sizeof( V_35 ) ) ;
if ( V_25 )
return F_16 ( V_2 , V_25 ) ;
F_3 ( V_2 , 3 , L_5 , V_35 , V_34 ) ;
F_22 ( V_2 , 0 , V_35 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
T_4 V_40 = V_2 -> V_40 ;
T_2 V_41 ;
int V_25 ;
T_1 V_26 ;
V_2 -> V_36 . V_42 ++ ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
V_41 = F_14 ( V_2 , & V_26 ) ;
if ( V_41 & 1 )
return F_5 ( V_2 , V_33 ) ;
V_25 = F_25 ( V_2 , V_41 , V_26 , & V_40 , sizeof( V_40 ) ) ;
if ( V_25 )
return F_16 ( V_2 , V_25 ) ;
F_3 ( V_2 , 3 , L_6 , V_40 , V_41 ) ;
F_27 ( V_2 , V_41 ) ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 )
{
int V_25 = 0 ;
struct V_43 * V_5 = V_2 -> V_4 . V_5 ;
F_29 ( V_2 ) ;
if ( ! ( V_5 -> V_44 & ( V_45 | V_46 | V_47 ) ) &&
! ( F_30 ( & V_5 -> V_48 ) & V_49 ) )
return V_25 ;
V_25 = F_31 () ;
F_3 ( V_2 , 3 , L_7 , V_25 ) ;
if ( ! V_25 ) {
if ( F_30 ( & V_5 -> V_48 ) & V_49 )
F_32 ( V_49 , & V_5 -> V_48 ) ;
else
V_5 -> V_44 &= ~ ( V_45 | V_46 |
V_47 ) ;
}
return V_25 ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_25 ;
V_2 -> V_36 . V_50 ++ ;
V_25 = F_28 ( V_2 ) ;
if ( V_25 )
return V_25 ;
if ( V_51 . V_52 ) {
F_4 ( V_2 ) ;
F_3 ( V_2 , 4 , L_1 , L_8 ) ;
return - V_53 ;
}
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
unsigned long V_54 ;
unsigned char V_55 ;
int V_56 , V_57 ;
int V_25 ;
V_25 = F_33 ( V_2 ) ;
if ( V_25 )
return V_25 != - V_53 ? V_25 : 0 ;
F_35 ( V_2 , & V_56 , & V_57 ) ;
V_54 = V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_57 ] & V_59 ;
V_54 = F_36 ( V_2 , V_54 ) ;
V_54 = F_37 ( V_2 , V_54 ) ;
V_54 = F_38 ( V_2 -> V_3 , F_39 ( V_54 ) ) ;
if ( F_40 ( V_54 ) )
return F_5 ( V_2 , V_38 ) ;
F_41 ( & V_11 -> V_60 -> V_61 ) ;
V_25 = F_42 ( V_11 -> V_60 , V_54 , & V_55 ) ;
F_43 ( & V_11 -> V_60 -> V_61 ) ;
if ( V_25 )
return F_5 ( V_2 , V_38 ) ;
V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_56 ] &= ~ 0xff ;
V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_56 ] |= V_55 ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
unsigned long V_54 ;
int V_56 , V_57 ;
int V_25 ;
V_25 = F_33 ( V_2 ) ;
if ( V_25 )
return V_25 != - V_53 ? V_25 : 0 ;
F_35 ( V_2 , & V_56 , & V_57 ) ;
V_54 = V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_57 ] & V_59 ;
V_54 = F_36 ( V_2 , V_54 ) ;
V_54 = F_37 ( V_2 , V_54 ) ;
V_54 = F_38 ( V_2 -> V_3 , F_39 ( V_54 ) ) ;
if ( F_40 ( V_54 ) )
return F_5 ( V_2 , V_38 ) ;
F_41 ( & V_11 -> V_60 -> V_61 ) ;
V_25 = F_45 ( V_11 -> V_60 , V_54 ) ;
F_43 ( & V_11 -> V_60 -> V_61 ) ;
if ( V_25 < 0 )
return F_5 ( V_2 , V_38 ) ;
F_18 ( V_2 , V_25 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
unsigned char V_62 = V_2 -> V_4 . V_5 -> V_24 >> 28 ;
unsigned long V_63 , V_64 ;
unsigned char V_55 , V_65 ;
int V_56 , V_57 ;
int V_25 ;
V_25 = F_33 ( V_2 ) ;
if ( V_25 )
return V_25 != - V_53 ? V_25 : 0 ;
if ( ! F_2 ( V_2 -> V_3 , 8 ) )
V_62 &= ~ V_66 ;
if ( ! F_2 ( V_2 -> V_3 , 10 ) )
V_62 &= ~ ( V_67 | V_68 ) ;
if ( ! F_2 ( V_2 -> V_3 , 14 ) )
V_62 &= ~ V_69 ;
F_35 ( V_2 , & V_56 , & V_57 ) ;
V_55 = V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_56 ] & 0xfe ;
V_63 = V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_57 ] & V_59 ;
V_63 = F_36 ( V_2 , V_63 ) ;
if ( V_62 & V_66 ) {
V_64 = ( V_63 + ( 1UL << 20 ) ) & ~ ( ( 1UL << 20 ) - 1 ) ;
} else {
V_63 = F_37 ( V_2 , V_63 ) ;
V_64 = V_63 + V_70 ;
}
while ( V_63 != V_64 ) {
unsigned long V_54 = F_38 ( V_2 -> V_3 , F_39 ( V_63 ) ) ;
if ( F_40 ( V_54 ) )
return F_5 ( V_2 , V_38 ) ;
F_41 ( & V_11 -> V_60 -> V_61 ) ;
V_25 = F_47 ( V_11 -> V_60 , V_54 , V_55 , & V_65 ,
V_62 & V_69 , V_62 & V_68 ,
V_62 & V_67 ) ;
F_43 ( & V_11 -> V_60 -> V_61 ) ;
if ( V_25 < 0 )
return F_5 ( V_2 , V_38 ) ;
V_63 += V_70 ;
}
if ( V_62 & ( V_67 | V_68 ) ) {
if ( V_62 & V_66 ) {
F_18 ( V_2 , 3 ) ;
} else {
F_18 ( V_2 , V_25 ) ;
V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_56 ] &= ~ 0xff00UL ;
V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_56 ] |= ( T_2 ) V_65 << 8 ;
}
}
if ( V_62 & V_66 ) {
if ( F_48 ( V_2 -> V_4 . V_5 -> V_29 ) . V_71 == V_72 )
V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_57 ] &= ~ V_59 ;
else
V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_57 ] &= ~ 0xfffff000UL ;
V_64 = F_36 ( V_2 , V_64 ) ;
V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_57 ] |= V_64 ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
V_2 -> V_36 . V_73 ++ ;
if ( F_48 ( V_2 -> V_4 . V_5 -> V_29 ) . V_74 )
return F_5 ( V_2 , V_32 ) ;
F_50 ( V_2 -> V_3 -> V_4 . V_75 , ! F_51 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_3 ( V_2 , 4 , L_1 , L_9 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
T_5 V_54 ;
int V_57 ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
F_35 ( V_2 , NULL , & V_57 ) ;
V_54 = V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_57 ] & V_59 ;
V_54 = F_36 ( V_2 , V_54 ) ;
if ( F_53 ( V_2 , V_54 ) )
return F_54 ( V_2 , & V_2 -> V_4 . V_76 ) ;
V_54 = F_37 ( V_2 , V_54 ) ;
if ( F_20 ( V_2 -> V_3 , V_54 ) )
return F_5 ( V_2 , V_38 ) ;
if ( F_55 ( V_2 -> V_3 , V_54 , V_70 ) )
return - V_77 ;
F_18 ( V_2 , 0 ) ;
V_2 -> V_14 -> V_15 . V_16 . V_58 [ 0 ] = 0 ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_78 * V_79 ;
unsigned long V_80 ;
T_3 V_81 [ 3 ] ;
int V_25 ;
T_2 V_54 ;
T_1 V_26 ;
V_54 = F_14 ( V_2 , & V_26 ) ;
if ( V_54 & 3 )
return F_5 ( V_2 , V_33 ) ;
V_79 = F_57 ( V_2 -> V_3 , V_2 -> V_4 . V_5 -> V_82 [ 6 ] , 0 ) ;
if ( ! V_79 ) {
F_18 ( V_2 , 0 ) ;
return 0 ;
}
V_81 [ 0 ] = V_79 -> V_83 . V_84 << 16 | V_79 -> V_83 . V_85 ;
V_81 [ 1 ] = V_79 -> V_83 . V_86 ;
V_81 [ 2 ] = V_79 -> V_83 . V_87 ;
if ( V_54 ) {
V_80 = sizeof( V_81 ) - 4 ;
V_25 = F_25 ( V_2 , V_54 , V_26 , & V_81 , V_80 ) ;
if ( V_25 ) {
V_25 = F_16 ( V_2 , V_25 ) ;
goto V_88;
}
} else {
V_80 = sizeof( V_81 ) ;
if ( F_58 ( V_2 , V_89 , & V_81 , V_80 ) ) {
V_25 = - V_77 ;
goto V_88;
}
}
F_59 ( V_79 ) ;
F_18 ( V_2 , 1 ) ;
return 0 ;
V_88:
if ( F_60 ( V_2 -> V_3 , V_79 ) ) {
F_59 ( V_79 ) ;
V_25 = - V_77 ;
}
return V_25 ? - V_77 : 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_78 * V_79 = NULL ;
const T_2 V_90 = 0xffUL << 24 ;
if ( V_2 -> V_14 -> V_15 . V_16 . V_58 [ 1 ] )
V_79 = F_57 ( V_2 -> V_3 , V_90 ,
V_2 -> V_14 -> V_15 . V_16 . V_58 [ 1 ] ) ;
V_2 -> V_14 -> V_91 = V_92 ;
V_2 -> V_14 -> V_93 . V_94 = ! ! V_79 ;
if ( V_79 ) {
V_2 -> V_14 -> V_93 . V_84 = V_79 -> V_83 . V_84 ;
V_2 -> V_14 -> V_93 . V_85 = V_79 -> V_83 . V_85 ;
V_2 -> V_14 -> V_93 . V_86 = V_79 -> V_83 . V_86 ;
V_2 -> V_14 -> V_93 . V_87 = V_79 -> V_83 . V_87 ;
}
V_2 -> V_14 -> V_93 . V_24 = V_2 -> V_4 . V_5 -> V_24 ;
F_59 ( V_79 ) ;
return - V_95 ;
}
static int F_62 ( struct V_1 * V_2 )
{
F_3 ( V_2 , 4 , L_1 , L_10 ) ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
if ( V_2 -> V_3 -> V_4 . V_96 ) {
if ( V_2 -> V_4 . V_5 -> V_9 == 0xb236 )
return F_56 ( V_2 ) ;
if ( V_2 -> V_4 . V_5 -> V_9 == 0xb235 )
return F_61 ( V_2 ) ;
return - V_10 ;
} else {
F_18 ( V_2 , 3 ) ;
return 0 ;
}
}
static int F_63 ( struct V_1 * V_2 )
{
int V_25 ;
unsigned int V_97 ;
V_2 -> V_36 . V_98 ++ ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
V_97 = * V_2 -> V_3 -> V_4 . V_99 . V_100 >> 32 ;
V_25 = F_58 ( V_2 , F_64 ( struct V_101 , V_102 ) ,
& V_97 , sizeof( V_97 ) ) ;
if ( V_25 )
return V_25 ;
F_3 ( V_2 , 3 , L_11 , V_97 ) ;
F_65 ( V_2 , V_97 ) ;
return 0 ;
}
int F_66 ( T_6 * V_103 )
{
if ( V_103 -> V_30 & V_104 )
return 0 ;
if ( ( V_103 -> V_30 & V_105 ) == V_106 ) {
if ( V_103 -> V_54 & ~ V_107 )
return 0 ;
}
if ( ! ( V_103 -> V_30 & V_105 ) && ( V_103 -> V_54 & ~ V_108 ) )
return 0 ;
if ( ( V_103 -> V_30 & V_105 ) == V_109 )
return 0 ;
if ( V_103 -> V_54 & 1 )
return 0 ;
return 1 ;
}
int F_67 ( struct V_1 * V_2 )
{
T_6 * V_29 = & V_2 -> V_4 . V_5 -> V_29 ;
T_7 V_110 ;
T_2 V_54 ;
int V_25 ;
T_1 V_26 ;
if ( V_29 -> V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
V_54 = F_14 ( V_2 , & V_26 ) ;
if ( V_54 & 7 )
return F_5 ( V_2 , V_33 ) ;
V_25 = F_15 ( V_2 , V_54 , V_26 , & V_110 , sizeof( V_110 ) ) ;
if ( V_25 )
return F_16 ( V_2 , V_25 ) ;
if ( ! ( V_110 . V_30 & V_111 ) )
return F_5 ( V_2 , V_33 ) ;
V_29 -> V_30 = ( V_110 . V_30 & ~ V_111 ) << 32 ;
V_29 -> V_30 |= V_110 . V_54 & V_112 ;
V_29 -> V_54 = V_110 . V_54 & ~ V_112 ;
if ( ! F_66 ( V_29 ) )
return F_5 ( V_2 , V_33 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 )
{
T_6 V_110 ;
T_2 V_54 ;
int V_25 ;
T_1 V_26 ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
V_54 = F_14 ( V_2 , & V_26 ) ;
if ( V_54 & 7 )
return F_5 ( V_2 , V_33 ) ;
V_25 = F_15 ( V_2 , V_54 , V_26 , & V_110 , sizeof( V_110 ) ) ;
if ( V_25 )
return F_16 ( V_2 , V_25 ) ;
V_2 -> V_4 . V_5 -> V_29 = V_110 ;
if ( ! F_66 ( & V_2 -> V_4 . V_5 -> V_29 ) )
return F_5 ( V_2 , V_33 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
T_2 V_113 = V_2 -> V_3 -> V_4 . V_99 . V_114 ;
T_2 V_34 ;
int V_25 ;
T_1 V_26 ;
V_2 -> V_36 . V_115 ++ ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
V_34 = F_14 ( V_2 , & V_26 ) ;
if ( V_34 & 7 )
return F_5 ( V_2 , V_33 ) ;
V_25 = F_25 ( V_2 , V_34 , V_26 , & V_113 , sizeof( V_113 ) ) ;
if ( V_25 )
return F_16 ( V_2 , V_25 ) ;
F_3 ( V_2 , 3 , L_12 , V_113 ) ;
return 0 ;
}
static void F_70 ( struct V_1 * V_2 , struct V_116 * V_117 )
{
int V_118 = 0 ;
int V_119 ;
V_118 = F_30 ( & V_2 -> V_3 -> V_120 ) ;
if ( F_71 ( V_117 , 3 , 2 , 2 ) )
V_117 -> V_121 = 0 ;
if ( V_117 -> V_121 < 8 )
V_117 -> V_121 ++ ;
for ( V_119 = V_117 -> V_121 - 1 ; V_119 > 0 ; V_119 -- )
memcpy ( & V_117 -> V_122 [ V_119 ] , & V_117 -> V_122 [ V_119 - 1 ] , sizeof( V_117 -> V_122 [ 0 ] ) ) ;
memset ( & V_117 -> V_122 [ 0 ] , 0 , sizeof( V_117 -> V_122 [ 0 ] ) ) ;
V_117 -> V_122 [ 0 ] . V_123 = V_118 ;
V_117 -> V_122 [ 0 ] . V_124 = V_118 ;
V_117 -> V_122 [ 0 ] . V_125 = 0 ;
V_117 -> V_122 [ 0 ] . V_126 = 0 ;
V_117 -> V_122 [ 0 ] . V_127 = 1000 ;
memcpy ( V_117 -> V_122 [ 0 ] . V_128 , L_13 , 8 ) ;
F_72 ( V_117 -> V_122 [ 0 ] . V_128 , 8 ) ;
memcpy ( V_117 -> V_122 [ 0 ] . V_129 , L_14 , 16 ) ;
F_72 ( V_117 -> V_122 [ 0 ] . V_129 , 16 ) ;
}
static void F_73 ( struct V_1 * V_2 , T_2 V_54 , T_1 V_26 ,
T_1 V_130 , T_1 V_131 , T_4 V_132 )
{
V_2 -> V_14 -> V_91 = V_133 ;
V_2 -> V_14 -> V_134 . V_54 = V_54 ;
V_2 -> V_14 -> V_134 . V_26 = V_26 ;
V_2 -> V_14 -> V_134 . V_130 = V_130 ;
V_2 -> V_14 -> V_134 . V_131 = V_131 ;
V_2 -> V_14 -> V_134 . V_132 = V_132 ;
}
static int F_74 ( struct V_1 * V_2 )
{
int V_130 = ( V_2 -> V_14 -> V_15 . V_16 . V_58 [ 0 ] & 0xf0000000 ) >> 28 ;
int V_131 = V_2 -> V_14 -> V_15 . V_16 . V_58 [ 0 ] & 0xff ;
int V_132 = V_2 -> V_14 -> V_15 . V_16 . V_58 [ 1 ] & 0xffff ;
unsigned long V_117 = 0 ;
T_2 V_34 ;
int V_25 = 0 ;
T_1 V_26 ;
V_2 -> V_36 . V_135 ++ ;
F_3 ( V_2 , 3 , L_15 , V_130 , V_131 , V_132 ) ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
if ( V_130 > 3 ) {
F_18 ( V_2 , 3 ) ;
return 0 ;
}
if ( V_2 -> V_14 -> V_15 . V_16 . V_58 [ 0 ] & 0x0fffff00
|| V_2 -> V_14 -> V_15 . V_16 . V_58 [ 1 ] & 0xffff0000 )
return F_5 ( V_2 , V_33 ) ;
if ( V_130 == 0 ) {
V_2 -> V_14 -> V_15 . V_16 . V_58 [ 0 ] = 3 << 28 ;
F_18 ( V_2 , 0 ) ;
return 0 ;
}
V_34 = F_14 ( V_2 , & V_26 ) ;
if ( V_34 & 0xfff )
return F_5 ( V_2 , V_33 ) ;
switch ( V_130 ) {
case 1 :
case 2 :
V_117 = F_75 ( V_136 ) ;
if ( ! V_117 )
goto V_137;
if ( F_71 ( ( void * ) V_117 , V_130 , V_131 , V_132 ) )
goto V_137;
break;
case 3 :
if ( V_131 != 2 || V_132 != 2 )
goto V_137;
V_117 = F_75 ( V_136 ) ;
if ( ! V_117 )
goto V_137;
F_70 ( V_2 , ( void * ) V_117 ) ;
break;
}
V_25 = F_25 ( V_2 , V_34 , V_26 , ( void * ) V_117 , V_70 ) ;
if ( V_25 ) {
V_25 = F_16 ( V_2 , V_25 ) ;
goto V_138;
}
if ( V_2 -> V_3 -> V_4 . V_139 ) {
F_73 ( V_2 , V_34 , V_26 , V_130 , V_131 , V_132 ) ;
V_25 = - V_95 ;
}
F_76 ( V_2 , V_130 , V_131 , V_132 , V_34 ) ;
F_77 ( V_117 ) ;
F_18 ( V_2 , 0 ) ;
V_2 -> V_14 -> V_15 . V_16 . V_58 [ 0 ] = 0 ;
return V_25 ;
V_137:
F_18 ( V_2 , 3 ) ;
V_138:
F_77 ( V_117 ) ;
return V_25 ;
}
int F_78 ( struct V_1 * V_2 )
{
T_8 V_140 ;
V_140 = V_141 [ V_2 -> V_4 . V_5 -> V_9 & 0x00ff ] ;
if ( V_140 )
return V_140 ( V_2 ) ;
return - V_10 ;
}
static int F_79 ( struct V_1 * V_2 )
{
int V_56 , V_57 ;
F_35 ( V_2 , & V_56 , & V_57 ) ;
V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_56 ] &= 0xffffffff00000000UL ;
V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_56 ] |= V_2 -> V_4 . V_5 -> V_29 . V_30 >> 32 ;
if ( V_57 ) {
V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_57 ] &= 0xffffffff00000000UL ;
V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_57 ] |=
V_2 -> V_4 . V_5 -> V_29 . V_30 & 0x00000000ffffffffUL ;
}
return 0 ;
}
static int F_80 ( struct V_1 * V_2 )
{
bool V_142 = false , V_143 = false , V_144 ;
int V_56 , V_57 ;
unsigned long V_63 , V_64 ;
unsigned char V_55 ;
V_2 -> V_36 . V_145 ++ ;
F_35 ( V_2 , & V_56 , & V_57 ) ;
if ( ! F_2 ( V_2 -> V_3 , 8 ) )
return F_5 ( V_2 , V_8 ) ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
if ( V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_56 ] & V_146 )
return F_5 ( V_2 , V_33 ) ;
if ( V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_56 ] & V_147 &&
! F_2 ( V_2 -> V_3 , 14 ) )
return F_5 ( V_2 , V_33 ) ;
if ( V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_56 ] & V_148 &&
F_2 ( V_2 -> V_3 , 10 ) ) {
V_142 = V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_56 ] & V_149 ;
V_143 = V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_56 ] & V_150 ;
}
V_144 = V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_56 ] & V_147 ;
V_55 = V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_56 ] & V_151 ;
V_63 = V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_57 ] & V_59 ;
V_63 = F_36 ( V_2 , V_63 ) ;
if ( V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_56 ] & V_152 ) {
if ( F_53 ( V_2 , V_63 ) )
return F_54 ( V_2 , & V_2 -> V_4 . V_76 ) ;
}
switch ( V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_56 ] & V_153 ) {
case 0x00000000 :
V_63 = F_37 ( V_2 , V_63 ) ;
V_64 = ( V_63 + ( 1UL << 12 ) ) & ~ ( ( 1UL << 12 ) - 1 ) ;
break;
case 0x00001000 :
V_64 = ( V_63 + ( 1UL << 20 ) ) & ~ ( ( 1UL << 20 ) - 1 ) ;
break;
case 0x00002000 :
if ( ! F_2 ( V_2 -> V_3 , 78 ) ||
F_48 ( V_2 -> V_4 . V_5 -> V_29 ) . V_71 == V_154 )
return F_5 ( V_2 , V_33 ) ;
V_64 = ( V_63 + ( 1UL << 31 ) ) & ~ ( ( 1UL << 31 ) - 1 ) ;
break;
default:
return F_5 ( V_2 , V_33 ) ;
}
while ( V_63 != V_64 ) {
unsigned long V_155 ;
V_155 = F_38 ( V_2 -> V_3 , F_39 ( V_63 ) ) ;
if ( F_40 ( V_155 ) )
return F_5 ( V_2 , V_38 ) ;
if ( V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_56 ] & V_152 ) {
if ( F_81 ( ( void V_156 * ) V_155 , V_70 ) )
return F_5 ( V_2 , V_38 ) ;
}
if ( V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_56 ] & V_148 ) {
int V_25 = F_28 ( V_2 ) ;
if ( V_25 )
return V_25 ;
F_41 ( & V_11 -> V_60 -> V_61 ) ;
V_25 = F_47 ( V_11 -> V_60 , V_155 ,
V_55 , NULL , V_144 , V_142 , V_143 ) ;
F_43 ( & V_11 -> V_60 -> V_61 ) ;
if ( V_25 < 0 )
return F_5 ( V_2 , V_38 ) ;
}
V_63 += V_70 ;
}
if ( V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_56 ] & V_153 ) {
if ( F_48 ( V_2 -> V_4 . V_5 -> V_29 ) . V_71 == V_72 ) {
V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_57 ] = V_64 ;
} else {
V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_57 ] &= ~ 0xffffffffUL ;
V_64 = F_36 ( V_2 , V_64 ) ;
V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_57 ] |= V_64 ;
}
}
return 0 ;
}
static inline int F_82 ( struct V_1 * V_2 , const int V_157 )
{
struct V_158 * V_159 = V_2 -> V_3 -> V_4 . V_160 ;
int V_161 , V_162 , V_163 , V_164 ;
unsigned long V_165 , V_166 , V_167 , V_168 , V_169 ;
unsigned long * V_170 ;
F_35 ( V_2 , & V_161 , & V_162 ) ;
V_165 = V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_162 ] >> V_171 ;
V_166 = F_38 ( V_2 -> V_3 , V_165 ) ;
V_164 = ( V_2 -> V_4 . V_5 -> V_170 & ~ V_59 ) >> 3 ;
if ( F_40 ( V_166 ) )
return F_5 ( V_2 , V_38 ) ;
V_163 = F_83 ( V_2 -> V_3 -> V_60 , V_166 , V_157 , & V_169 , & V_168 ) ;
if ( V_163 < 0 ) {
V_167 = V_157 ? 0x10 : 0 ;
V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_161 ] = V_167 ;
return 0 ;
}
V_167 = ( V_168 & V_172 ) >> 22 ;
if ( V_169 & V_173 ) {
V_167 |= 2 ;
if ( V_168 & V_174 )
V_167 |= 1 ;
}
V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_161 ] = V_167 ;
if ( V_163 > 0 ) {
V_170 = F_84 ( V_2 -> V_4 . V_5 -> V_170 & V_59 ) ;
V_170 [ V_164 ] = V_165 << V_171 ;
}
if ( V_157 ) {
if ( ! F_85 ( V_165 , V_159 -> V_175 ) )
F_86 ( & V_159 -> V_176 ) ;
}
return V_163 ;
}
static int F_87 ( struct V_1 * V_2 )
{
int V_164 = ( V_2 -> V_4 . V_5 -> V_170 & ~ V_59 ) >> 3 ;
unsigned long * V_170 ;
struct V_177 * V_177 ;
int V_178 , V_157 ;
F_3 ( V_2 , 4 , L_16 , V_164 ) ;
V_177 = V_2 -> V_4 . V_177 ;
V_2 -> V_36 . V_179 ++ ;
if ( ! V_2 -> V_3 -> V_4 . V_180 )
return F_5 ( V_2 , V_8 ) ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
V_157 = ( V_2 -> V_4 . V_5 -> V_24 & 0xf0000000 ) >> 28 ;
if ( V_157 > V_181 )
return F_5 ( V_2 , V_33 ) ;
if ( F_88 ( ! V_2 -> V_3 -> V_4 . V_160 ) ) {
if ( V_2 -> V_3 -> V_60 -> V_182 . V_180 == 0 ) {
F_89 ( & V_2 -> V_3 -> V_60 -> V_61 ) ;
V_2 -> V_3 -> V_60 -> V_182 . V_180 = 1 ;
F_90 ( & V_2 -> V_3 -> V_60 -> V_61 ) ;
}
V_2 -> V_4 . V_5 -> V_183 |= V_184 ;
F_4 ( V_2 ) ;
} else {
V_178 = F_82 ( V_2 , V_157 ) ;
if ( V_178 < 0 )
return V_178 ;
V_164 += V_178 ;
}
V_2 -> V_4 . V_5 -> V_170 &= V_59 ;
V_170 = F_84 ( V_2 -> V_4 . V_5 -> V_170 ) ;
F_41 ( & V_177 -> V_60 -> V_61 ) ;
for ( V_178 = 0 ; V_178 < V_164 ; ++ V_178 )
F_91 ( V_177 , V_170 [ V_178 ] ) ;
F_43 ( & V_177 -> V_60 -> V_61 ) ;
return 0 ;
}
int F_92 ( struct V_1 * V_2 )
{
T_8 V_140 ;
V_140 = V_185 [ V_2 -> V_4 . V_5 -> V_9 & 0x00ff ] ;
if ( V_140 )
return V_140 ( V_2 ) ;
return - V_10 ;
}
int F_93 ( struct V_1 * V_2 )
{
int V_56 = ( V_2 -> V_4 . V_5 -> V_9 & 0x00f0 ) >> 4 ;
int V_186 = V_2 -> V_4 . V_5 -> V_9 & 0x000f ;
int V_187 , V_25 , V_188 ;
T_3 V_189 [ 16 ] ;
T_2 V_41 ;
T_1 V_26 ;
V_2 -> V_36 . V_190 ++ ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
V_41 = F_94 ( V_2 , & V_26 ) ;
if ( V_41 & 3 )
return F_5 ( V_2 , V_33 ) ;
F_3 ( V_2 , 4 , L_17 , V_56 , V_186 , V_41 ) ;
F_95 ( V_2 , 0 , V_56 , V_186 , V_41 ) ;
V_188 = ( ( V_186 - V_56 ) & 0xf ) + 1 ;
V_25 = F_15 ( V_2 , V_41 , V_26 , V_189 , V_188 * sizeof( T_3 ) ) ;
if ( V_25 )
return F_16 ( V_2 , V_25 ) ;
V_187 = V_56 ;
V_188 = 0 ;
do {
V_2 -> V_4 . V_5 -> V_82 [ V_187 ] &= 0xffffffff00000000ul ;
V_2 -> V_4 . V_5 -> V_82 [ V_187 ] |= V_189 [ V_188 ++ ] ;
if ( V_187 == V_186 )
break;
V_187 = ( V_187 + 1 ) % 16 ;
} while ( 1 );
F_96 ( V_191 , V_2 ) ;
return 0 ;
}
int F_97 ( struct V_1 * V_2 )
{
int V_56 = ( V_2 -> V_4 . V_5 -> V_9 & 0x00f0 ) >> 4 ;
int V_186 = V_2 -> V_4 . V_5 -> V_9 & 0x000f ;
int V_187 , V_25 , V_188 ;
T_3 V_189 [ 16 ] ;
T_2 V_41 ;
T_1 V_26 ;
V_2 -> V_36 . V_192 ++ ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
V_41 = F_94 ( V_2 , & V_26 ) ;
if ( V_41 & 3 )
return F_5 ( V_2 , V_33 ) ;
F_3 ( V_2 , 4 , L_18 , V_56 , V_186 , V_41 ) ;
F_98 ( V_2 , 0 , V_56 , V_186 , V_41 ) ;
V_187 = V_56 ;
V_188 = 0 ;
do {
V_189 [ V_188 ++ ] = V_2 -> V_4 . V_5 -> V_82 [ V_187 ] ;
if ( V_187 == V_186 )
break;
V_187 = ( V_187 + 1 ) % 16 ;
} while ( 1 );
V_25 = F_25 ( V_2 , V_41 , V_26 , V_189 , V_188 * sizeof( T_3 ) ) ;
return V_25 ? F_16 ( V_2 , V_25 ) : 0 ;
}
static int F_99 ( struct V_1 * V_2 )
{
int V_56 = ( V_2 -> V_4 . V_5 -> V_9 & 0x00f0 ) >> 4 ;
int V_186 = V_2 -> V_4 . V_5 -> V_9 & 0x000f ;
int V_187 , V_25 , V_188 ;
T_2 V_189 [ 16 ] ;
T_2 V_41 ;
T_1 V_26 ;
V_2 -> V_36 . V_193 ++ ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
V_41 = F_100 ( V_2 , & V_26 ) ;
if ( V_41 & 7 )
return F_5 ( V_2 , V_33 ) ;
F_3 ( V_2 , 4 , L_19 , V_56 , V_186 , V_41 ) ;
F_95 ( V_2 , 1 , V_56 , V_186 , V_41 ) ;
V_188 = ( ( V_186 - V_56 ) & 0xf ) + 1 ;
V_25 = F_15 ( V_2 , V_41 , V_26 , V_189 , V_188 * sizeof( T_2 ) ) ;
if ( V_25 )
return F_16 ( V_2 , V_25 ) ;
V_187 = V_56 ;
V_188 = 0 ;
do {
V_2 -> V_4 . V_5 -> V_82 [ V_187 ] = V_189 [ V_188 ++ ] ;
if ( V_187 == V_186 )
break;
V_187 = ( V_187 + 1 ) % 16 ;
} while ( 1 );
F_96 ( V_191 , V_2 ) ;
return 0 ;
}
static int F_101 ( struct V_1 * V_2 )
{
int V_56 = ( V_2 -> V_4 . V_5 -> V_9 & 0x00f0 ) >> 4 ;
int V_186 = V_2 -> V_4 . V_5 -> V_9 & 0x000f ;
int V_187 , V_25 , V_188 ;
T_2 V_189 [ 16 ] ;
T_2 V_41 ;
T_1 V_26 ;
V_2 -> V_36 . V_194 ++ ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
V_41 = F_100 ( V_2 , & V_26 ) ;
if ( V_41 & 7 )
return F_5 ( V_2 , V_33 ) ;
F_3 ( V_2 , 4 , L_20 , V_56 , V_186 , V_41 ) ;
F_98 ( V_2 , 1 , V_56 , V_186 , V_41 ) ;
V_187 = V_56 ;
V_188 = 0 ;
do {
V_189 [ V_188 ++ ] = V_2 -> V_4 . V_5 -> V_82 [ V_187 ] ;
if ( V_187 == V_186 )
break;
V_187 = ( V_187 + 1 ) % 16 ;
} while ( 1 );
V_25 = F_25 ( V_2 , V_41 , V_26 , V_189 , V_188 * sizeof( T_2 ) ) ;
return V_25 ? F_16 ( V_2 , V_25 ) : 0 ;
}
int F_102 ( struct V_1 * V_2 )
{
T_8 V_140 ;
V_140 = V_195 [ V_2 -> V_4 . V_5 -> V_24 & 0xff ] ;
if ( V_140 )
return V_140 ( V_2 ) ;
return - V_10 ;
}
static int F_103 ( struct V_1 * V_2 )
{
T_2 V_196 , V_197 ;
unsigned long V_166 , V_198 ;
int V_199 = 0 , V_200 = 0 ;
bool V_201 ;
T_1 V_26 ;
V_2 -> V_36 . V_202 ++ ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
F_104 ( V_2 , & V_196 , & V_197 , & V_26 , NULL ) ;
if ( V_197 & 0xf0 )
return - V_10 ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_203 )
F_105 ( V_2 ) ;
V_199 = F_106 ( V_2 , V_196 , V_26 , & V_198 , V_204 ) ;
if ( V_199 == V_205 ) {
V_200 = 1 ;
V_199 = F_106 ( V_2 , V_196 , V_26 , & V_198 ,
V_206 ) ;
}
if ( V_199 ) {
if ( V_199 == V_38 || V_199 == V_207 ) {
V_199 = F_5 ( V_2 , V_199 ) ;
} else if ( V_199 > 0 ) {
F_18 ( V_2 , 3 ) ;
V_199 = 0 ;
}
goto V_208;
}
V_166 = F_107 ( V_2 -> V_3 , F_39 ( V_198 ) , & V_201 ) ;
if ( F_40 ( V_166 ) ) {
V_199 = F_5 ( V_2 , V_38 ) ;
} else {
if ( ! V_201 )
V_200 = 1 ;
F_18 ( V_2 , V_200 ) ;
}
V_208:
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_203 )
F_108 ( V_2 ) ;
return V_199 ;
}
int F_109 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_4 . V_5 -> V_9 & 0x00ff ) == 0x01 )
return F_103 ( V_2 ) ;
return - V_10 ;
}
static int F_110 ( struct V_1 * V_2 )
{
T_3 V_209 ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
if ( V_2 -> V_14 -> V_15 . V_16 . V_58 [ 0 ] & 0x00000000ffff0000 )
return F_5 ( V_2 ,
V_33 ) ;
V_209 = V_2 -> V_14 -> V_15 . V_16 . V_58 [ 0 ] & 0x000000000000ffff ;
V_2 -> V_4 . V_5 -> V_210 = V_209 ;
return 0 ;
}
static int F_111 ( struct V_1 * V_2 )
{
F_18 ( V_2 , 3 ) ;
return 0 ;
}
int F_112 ( struct V_1 * V_2 )
{
T_8 V_140 ;
V_140 = V_211 [ V_2 -> V_4 . V_5 -> V_9 & 0x00ff ] ;
if ( V_140 )
return V_140 ( V_2 ) ;
return - V_10 ;
}
