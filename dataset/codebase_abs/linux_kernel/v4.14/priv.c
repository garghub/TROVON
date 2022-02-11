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
V_64 = ( V_63 + V_70 ) & ~ ( V_70 - 1 ) ;
} else {
V_63 = F_37 ( V_2 , V_63 ) ;
V_64 = V_63 + V_71 ;
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
V_63 += V_71 ;
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
if ( F_48 ( V_2 -> V_4 . V_5 -> V_29 ) . V_72 == V_73 )
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
V_2 -> V_36 . V_74 ++ ;
if ( F_48 ( V_2 -> V_4 . V_5 -> V_29 ) . V_75 )
return F_5 ( V_2 , V_32 ) ;
F_50 ( V_2 -> V_3 -> V_4 . V_76 , ! F_51 ( V_2 ) ) ;
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
return F_54 ( V_2 , & V_2 -> V_4 . V_77 ) ;
V_54 = F_37 ( V_2 , V_54 ) ;
if ( F_20 ( V_2 -> V_3 , V_54 ) )
return F_5 ( V_2 , V_38 ) ;
if ( F_55 ( V_2 -> V_3 , V_54 , V_71 ) )
return - V_78 ;
F_18 ( V_2 , 0 ) ;
V_2 -> V_14 -> V_15 . V_16 . V_58 [ 0 ] = 0 ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_79 * V_80 ;
unsigned long V_81 ;
T_3 V_82 [ 3 ] ;
int V_25 ;
T_2 V_54 ;
T_1 V_26 ;
V_54 = F_14 ( V_2 , & V_26 ) ;
if ( V_54 & 3 )
return F_5 ( V_2 , V_33 ) ;
V_80 = F_57 ( V_2 -> V_3 , V_2 -> V_4 . V_5 -> V_83 [ 6 ] , 0 ) ;
if ( ! V_80 ) {
F_18 ( V_2 , 0 ) ;
return 0 ;
}
V_82 [ 0 ] = V_80 -> V_84 . V_85 << 16 | V_80 -> V_84 . V_86 ;
V_82 [ 1 ] = V_80 -> V_84 . V_87 ;
V_82 [ 2 ] = V_80 -> V_84 . V_88 ;
if ( V_54 ) {
V_81 = sizeof( V_82 ) - 4 ;
V_25 = F_25 ( V_2 , V_54 , V_26 , & V_82 , V_81 ) ;
if ( V_25 ) {
V_25 = F_16 ( V_2 , V_25 ) ;
goto V_89;
}
} else {
V_81 = sizeof( V_82 ) ;
if ( F_58 ( V_2 , V_90 , & V_82 , V_81 ) ) {
V_25 = - V_78 ;
goto V_89;
}
}
F_59 ( V_80 ) ;
F_18 ( V_2 , 1 ) ;
return 0 ;
V_89:
if ( F_60 ( V_2 -> V_3 , V_80 ) ) {
F_59 ( V_80 ) ;
V_25 = - V_78 ;
}
return V_25 ? - V_78 : 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_79 * V_80 = NULL ;
const T_2 V_91 = 0xffUL << 24 ;
if ( V_2 -> V_14 -> V_15 . V_16 . V_58 [ 1 ] )
V_80 = F_57 ( V_2 -> V_3 , V_91 ,
V_2 -> V_14 -> V_15 . V_16 . V_58 [ 1 ] ) ;
V_2 -> V_14 -> V_92 = V_93 ;
V_2 -> V_14 -> V_94 . V_95 = ! ! V_80 ;
if ( V_80 ) {
V_2 -> V_14 -> V_94 . V_85 = V_80 -> V_84 . V_85 ;
V_2 -> V_14 -> V_94 . V_86 = V_80 -> V_84 . V_86 ;
V_2 -> V_14 -> V_94 . V_87 = V_80 -> V_84 . V_87 ;
V_2 -> V_14 -> V_94 . V_88 = V_80 -> V_84 . V_88 ;
}
V_2 -> V_14 -> V_94 . V_24 = V_2 -> V_4 . V_5 -> V_24 ;
F_59 ( V_80 ) ;
return - V_96 ;
}
static int F_62 ( struct V_1 * V_2 )
{
F_3 ( V_2 , 4 , L_1 , L_10 ) ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
if ( V_2 -> V_3 -> V_4 . V_97 ) {
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
unsigned int V_98 ;
V_2 -> V_36 . V_99 ++ ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
V_98 = * V_2 -> V_3 -> V_4 . V_100 . V_101 >> 32 ;
V_25 = F_58 ( V_2 , F_64 ( struct V_102 , V_103 ) ,
& V_98 , sizeof( V_98 ) ) ;
if ( V_25 )
return V_25 ;
F_3 ( V_2 , 3 , L_11 , V_98 ) ;
F_65 ( V_2 , V_98 ) ;
return 0 ;
}
int F_66 ( T_6 * V_104 )
{
if ( V_104 -> V_30 & V_105 )
return 0 ;
if ( ( V_104 -> V_30 & V_106 ) == V_107 ) {
if ( V_104 -> V_54 & ~ V_108 )
return 0 ;
}
if ( ! ( V_104 -> V_30 & V_106 ) && ( V_104 -> V_54 & ~ V_109 ) )
return 0 ;
if ( ( V_104 -> V_30 & V_106 ) == V_110 )
return 0 ;
if ( V_104 -> V_54 & 1 )
return 0 ;
return 1 ;
}
int F_67 ( struct V_1 * V_2 )
{
T_6 * V_29 = & V_2 -> V_4 . V_5 -> V_29 ;
T_7 V_111 ;
T_2 V_54 ;
int V_25 ;
T_1 V_26 ;
if ( V_29 -> V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
V_54 = F_14 ( V_2 , & V_26 ) ;
if ( V_54 & 7 )
return F_5 ( V_2 , V_33 ) ;
V_25 = F_15 ( V_2 , V_54 , V_26 , & V_111 , sizeof( V_111 ) ) ;
if ( V_25 )
return F_16 ( V_2 , V_25 ) ;
if ( ! ( V_111 . V_30 & V_112 ) )
return F_5 ( V_2 , V_33 ) ;
V_29 -> V_30 = ( V_111 . V_30 & ~ V_112 ) << 32 ;
V_29 -> V_30 |= V_111 . V_54 & V_113 ;
V_29 -> V_54 = V_111 . V_54 & ~ V_113 ;
if ( ! F_66 ( V_29 ) )
return F_5 ( V_2 , V_33 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 )
{
T_6 V_111 ;
T_2 V_54 ;
int V_25 ;
T_1 V_26 ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
V_54 = F_14 ( V_2 , & V_26 ) ;
if ( V_54 & 7 )
return F_5 ( V_2 , V_33 ) ;
V_25 = F_15 ( V_2 , V_54 , V_26 , & V_111 , sizeof( V_111 ) ) ;
if ( V_25 )
return F_16 ( V_2 , V_25 ) ;
V_2 -> V_4 . V_5 -> V_29 = V_111 ;
if ( ! F_66 ( & V_2 -> V_4 . V_5 -> V_29 ) )
return F_5 ( V_2 , V_33 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
T_2 V_114 = V_2 -> V_3 -> V_4 . V_100 . V_115 ;
T_2 V_34 ;
int V_25 ;
T_1 V_26 ;
V_2 -> V_36 . V_116 ++ ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
V_34 = F_14 ( V_2 , & V_26 ) ;
if ( V_34 & 7 )
return F_5 ( V_2 , V_33 ) ;
V_25 = F_25 ( V_2 , V_34 , V_26 , & V_114 , sizeof( V_114 ) ) ;
if ( V_25 )
return F_16 ( V_2 , V_25 ) ;
F_3 ( V_2 , 3 , L_12 , V_114 ) ;
return 0 ;
}
static void F_70 ( struct V_1 * V_2 , struct V_117 * V_118 )
{
int V_119 = 0 ;
int V_120 ;
V_119 = F_30 ( & V_2 -> V_3 -> V_121 ) ;
if ( F_71 ( V_118 , 3 , 2 , 2 ) )
V_118 -> V_122 = 0 ;
if ( V_118 -> V_122 < 8 )
V_118 -> V_122 ++ ;
for ( V_120 = V_118 -> V_122 - 1 ; V_120 > 0 ; V_120 -- )
memcpy ( & V_118 -> V_123 [ V_120 ] , & V_118 -> V_123 [ V_120 - 1 ] , sizeof( V_118 -> V_123 [ 0 ] ) ) ;
memset ( & V_118 -> V_123 [ 0 ] , 0 , sizeof( V_118 -> V_123 [ 0 ] ) ) ;
V_118 -> V_123 [ 0 ] . V_124 = V_119 ;
V_118 -> V_123 [ 0 ] . V_125 = V_119 ;
V_118 -> V_123 [ 0 ] . V_126 = 0 ;
V_118 -> V_123 [ 0 ] . V_127 = 0 ;
V_118 -> V_123 [ 0 ] . V_128 = 1000 ;
memcpy ( V_118 -> V_123 [ 0 ] . V_129 , L_13 , 8 ) ;
F_72 ( V_118 -> V_123 [ 0 ] . V_129 , 8 ) ;
memcpy ( V_118 -> V_123 [ 0 ] . V_130 , L_14 , 16 ) ;
F_72 ( V_118 -> V_123 [ 0 ] . V_130 , 16 ) ;
}
static void F_73 ( struct V_1 * V_2 , T_2 V_54 , T_1 V_26 ,
T_1 V_131 , T_1 V_132 , T_4 V_133 )
{
V_2 -> V_14 -> V_92 = V_134 ;
V_2 -> V_14 -> V_135 . V_54 = V_54 ;
V_2 -> V_14 -> V_135 . V_26 = V_26 ;
V_2 -> V_14 -> V_135 . V_131 = V_131 ;
V_2 -> V_14 -> V_135 . V_132 = V_132 ;
V_2 -> V_14 -> V_135 . V_133 = V_133 ;
}
static int F_74 ( struct V_1 * V_2 )
{
int V_131 = ( V_2 -> V_14 -> V_15 . V_16 . V_58 [ 0 ] & 0xf0000000 ) >> 28 ;
int V_132 = V_2 -> V_14 -> V_15 . V_16 . V_58 [ 0 ] & 0xff ;
int V_133 = V_2 -> V_14 -> V_15 . V_16 . V_58 [ 1 ] & 0xffff ;
unsigned long V_118 = 0 ;
T_2 V_34 ;
int V_25 = 0 ;
T_1 V_26 ;
V_2 -> V_36 . V_136 ++ ;
F_3 ( V_2 , 3 , L_15 , V_131 , V_132 , V_133 ) ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
if ( V_131 > 3 ) {
F_18 ( V_2 , 3 ) ;
return 0 ;
}
if ( V_2 -> V_14 -> V_15 . V_16 . V_58 [ 0 ] & 0x0fffff00
|| V_2 -> V_14 -> V_15 . V_16 . V_58 [ 1 ] & 0xffff0000 )
return F_5 ( V_2 , V_33 ) ;
if ( V_131 == 0 ) {
V_2 -> V_14 -> V_15 . V_16 . V_58 [ 0 ] = 3 << 28 ;
F_18 ( V_2 , 0 ) ;
return 0 ;
}
V_34 = F_14 ( V_2 , & V_26 ) ;
if ( V_34 & 0xfff )
return F_5 ( V_2 , V_33 ) ;
switch ( V_131 ) {
case 1 :
case 2 :
V_118 = F_75 ( V_137 ) ;
if ( ! V_118 )
goto V_138;
if ( F_71 ( ( void * ) V_118 , V_131 , V_132 , V_133 ) )
goto V_138;
break;
case 3 :
if ( V_132 != 2 || V_133 != 2 )
goto V_138;
V_118 = F_75 ( V_137 ) ;
if ( ! V_118 )
goto V_138;
F_70 ( V_2 , ( void * ) V_118 ) ;
break;
}
V_25 = F_25 ( V_2 , V_34 , V_26 , ( void * ) V_118 , V_71 ) ;
if ( V_25 ) {
V_25 = F_16 ( V_2 , V_25 ) ;
goto V_139;
}
if ( V_2 -> V_3 -> V_4 . V_140 ) {
F_73 ( V_2 , V_34 , V_26 , V_131 , V_132 , V_133 ) ;
V_25 = - V_96 ;
}
F_76 ( V_2 , V_131 , V_132 , V_133 , V_34 ) ;
F_77 ( V_118 ) ;
F_18 ( V_2 , 0 ) ;
V_2 -> V_14 -> V_15 . V_16 . V_58 [ 0 ] = 0 ;
return V_25 ;
V_138:
F_18 ( V_2 , 3 ) ;
V_139:
F_77 ( V_118 ) ;
return V_25 ;
}
int F_78 ( struct V_1 * V_2 )
{
T_8 V_141 ;
V_141 = V_142 [ V_2 -> V_4 . V_5 -> V_9 & 0x00ff ] ;
if ( V_141 )
return V_141 ( V_2 ) ;
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
bool V_143 = false , V_144 = false , V_145 ;
int V_56 , V_57 ;
unsigned long V_63 , V_64 ;
unsigned char V_55 ;
V_2 -> V_36 . V_146 ++ ;
F_35 ( V_2 , & V_56 , & V_57 ) ;
if ( ! F_2 ( V_2 -> V_3 , 8 ) )
return F_5 ( V_2 , V_8 ) ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
if ( V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_56 ] & V_147 )
return F_5 ( V_2 , V_33 ) ;
if ( V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_56 ] & V_148 &&
! F_2 ( V_2 -> V_3 , 14 ) )
return F_5 ( V_2 , V_33 ) ;
if ( V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_56 ] & V_149 &&
F_2 ( V_2 -> V_3 , 10 ) ) {
V_143 = V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_56 ] & V_150 ;
V_144 = V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_56 ] & V_151 ;
}
V_145 = V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_56 ] & V_148 ;
V_55 = V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_56 ] & V_152 ;
V_63 = V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_57 ] & V_59 ;
V_63 = F_36 ( V_2 , V_63 ) ;
if ( V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_56 ] & V_153 ) {
if ( F_53 ( V_2 , V_63 ) )
return F_54 ( V_2 , & V_2 -> V_4 . V_77 ) ;
}
switch ( V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_56 ] & V_154 ) {
case 0x00000000 :
V_63 = F_37 ( V_2 , V_63 ) ;
V_64 = ( V_63 + V_71 ) & ~ ( V_71 - 1 ) ;
break;
case 0x00001000 :
V_64 = ( V_63 + V_70 ) & ~ ( V_70 - 1 ) ;
break;
case 0x00002000 :
if ( ! F_2 ( V_2 -> V_3 , 78 ) ||
F_48 ( V_2 -> V_4 . V_5 -> V_29 ) . V_72 == V_155 )
return F_5 ( V_2 , V_33 ) ;
V_64 = ( V_63 + V_156 ) & ~ ( V_156 - 1 ) ;
break;
default:
return F_5 ( V_2 , V_33 ) ;
}
while ( V_63 != V_64 ) {
unsigned long V_157 ;
V_157 = F_38 ( V_2 -> V_3 , F_39 ( V_63 ) ) ;
if ( F_40 ( V_157 ) )
return F_5 ( V_2 , V_38 ) ;
if ( V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_56 ] & V_153 ) {
if ( F_81 ( ( void V_158 * ) V_157 , V_71 ) )
return F_5 ( V_2 , V_38 ) ;
}
if ( V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_56 ] & V_149 ) {
int V_25 = F_28 ( V_2 ) ;
if ( V_25 )
return V_25 ;
F_41 ( & V_11 -> V_60 -> V_61 ) ;
V_25 = F_47 ( V_11 -> V_60 , V_157 ,
V_55 , NULL , V_145 , V_143 , V_144 ) ;
F_43 ( & V_11 -> V_60 -> V_61 ) ;
if ( V_25 < 0 )
return F_5 ( V_2 , V_38 ) ;
}
V_63 += V_71 ;
}
if ( V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_56 ] & V_154 ) {
if ( F_48 ( V_2 -> V_4 . V_5 -> V_29 ) . V_72 == V_73 ) {
V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_57 ] = V_64 ;
} else {
V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_57 ] &= ~ 0xffffffffUL ;
V_64 = F_36 ( V_2 , V_64 ) ;
V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_57 ] |= V_64 ;
}
}
return 0 ;
}
static inline int F_82 ( struct V_1 * V_2 , const int V_159 )
{
struct V_160 * V_161 = V_2 -> V_3 -> V_4 . V_162 ;
int V_163 , V_164 , V_165 , V_166 ;
unsigned long V_167 , V_168 , V_169 , V_170 , V_171 ;
unsigned long * V_172 ;
F_35 ( V_2 , & V_163 , & V_164 ) ;
V_167 = V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_164 ] >> V_173 ;
V_168 = F_38 ( V_2 -> V_3 , V_167 ) ;
V_166 = ( V_2 -> V_4 . V_5 -> V_172 & ~ V_59 ) >> 3 ;
if ( F_40 ( V_168 ) )
return F_5 ( V_2 , V_38 ) ;
V_165 = F_83 ( V_2 -> V_3 -> V_60 , V_168 , V_159 , & V_171 , & V_170 ) ;
if ( V_165 < 0 ) {
V_169 = V_159 ? 0x10 : 0 ;
V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_163 ] = V_169 ;
return 0 ;
}
V_169 = ( V_170 & V_174 ) >> 22 ;
if ( V_171 & V_175 ) {
V_169 |= 2 ;
if ( V_170 & V_176 )
V_169 |= 1 ;
}
if ( V_170 & V_177 )
V_169 |= 0x20 ;
V_2 -> V_14 -> V_15 . V_16 . V_58 [ V_163 ] = V_169 ;
if ( V_165 > 0 ) {
V_172 = F_84 ( V_2 -> V_4 . V_5 -> V_172 & V_59 ) ;
V_172 [ V_166 ] = V_167 << V_173 ;
}
if ( V_159 ) {
if ( ! F_85 ( V_167 , V_161 -> V_178 ) )
F_86 ( & V_161 -> V_179 ) ;
}
return V_165 ;
}
static int F_87 ( struct V_1 * V_2 )
{
int V_166 = ( V_2 -> V_4 . V_5 -> V_172 & ~ V_59 ) >> 3 ;
unsigned long * V_172 ;
struct V_180 * V_180 ;
int V_181 , V_159 ;
F_3 ( V_2 , 4 , L_16 , V_166 ) ;
V_180 = V_2 -> V_4 . V_180 ;
V_2 -> V_36 . V_182 ++ ;
if ( ! V_2 -> V_3 -> V_4 . V_183 )
return F_5 ( V_2 , V_8 ) ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
V_159 = ( V_2 -> V_4 . V_5 -> V_24 & 0xf0000000 ) >> 28 ;
if ( V_159 > ( F_2 ( V_2 -> V_3 , 147 ) ? V_184
: V_185 ) )
return F_5 ( V_2 , V_33 ) ;
if ( F_88 ( ! V_2 -> V_3 -> V_4 . V_162 ) ) {
if ( V_2 -> V_3 -> V_60 -> V_186 . V_183 == 0 ) {
F_89 ( & V_2 -> V_3 -> V_60 -> V_61 ) ;
V_2 -> V_3 -> V_60 -> V_186 . V_183 = 1 ;
F_90 ( & V_2 -> V_3 -> V_60 -> V_61 ) ;
}
V_2 -> V_4 . V_5 -> V_187 |= V_188 ;
F_4 ( V_2 ) ;
} else {
V_181 = F_82 ( V_2 , V_159 ) ;
if ( V_181 < 0 )
return V_181 ;
V_166 += V_181 ;
}
V_2 -> V_4 . V_5 -> V_172 &= V_59 ;
V_172 = F_84 ( V_2 -> V_4 . V_5 -> V_172 ) ;
F_41 ( & V_180 -> V_60 -> V_61 ) ;
for ( V_181 = 0 ; V_181 < V_166 ; ++ V_181 )
F_91 ( V_180 , V_172 [ V_181 ] ) ;
F_43 ( & V_180 -> V_60 -> V_61 ) ;
return 0 ;
}
int F_92 ( struct V_1 * V_2 )
{
T_8 V_141 ;
V_141 = V_189 [ V_2 -> V_4 . V_5 -> V_9 & 0x00ff ] ;
if ( V_141 )
return V_141 ( V_2 ) ;
return - V_10 ;
}
int F_93 ( struct V_1 * V_2 )
{
int V_56 = ( V_2 -> V_4 . V_5 -> V_9 & 0x00f0 ) >> 4 ;
int V_190 = V_2 -> V_4 . V_5 -> V_9 & 0x000f ;
int V_191 , V_25 , V_192 ;
T_3 V_193 [ 16 ] ;
T_2 V_41 ;
T_1 V_26 ;
V_2 -> V_36 . V_194 ++ ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
V_41 = F_94 ( V_2 , & V_26 ) ;
if ( V_41 & 3 )
return F_5 ( V_2 , V_33 ) ;
F_3 ( V_2 , 4 , L_17 , V_56 , V_190 , V_41 ) ;
F_95 ( V_2 , 0 , V_56 , V_190 , V_41 ) ;
V_192 = ( ( V_190 - V_56 ) & 0xf ) + 1 ;
V_25 = F_15 ( V_2 , V_41 , V_26 , V_193 , V_192 * sizeof( T_3 ) ) ;
if ( V_25 )
return F_16 ( V_2 , V_25 ) ;
V_191 = V_56 ;
V_192 = 0 ;
do {
V_2 -> V_4 . V_5 -> V_83 [ V_191 ] &= 0xffffffff00000000ul ;
V_2 -> V_4 . V_5 -> V_83 [ V_191 ] |= V_193 [ V_192 ++ ] ;
if ( V_191 == V_190 )
break;
V_191 = ( V_191 + 1 ) % 16 ;
} while ( 1 );
F_96 ( V_195 , V_2 ) ;
return 0 ;
}
int F_97 ( struct V_1 * V_2 )
{
int V_56 = ( V_2 -> V_4 . V_5 -> V_9 & 0x00f0 ) >> 4 ;
int V_190 = V_2 -> V_4 . V_5 -> V_9 & 0x000f ;
int V_191 , V_25 , V_192 ;
T_3 V_193 [ 16 ] ;
T_2 V_41 ;
T_1 V_26 ;
V_2 -> V_36 . V_196 ++ ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
V_41 = F_94 ( V_2 , & V_26 ) ;
if ( V_41 & 3 )
return F_5 ( V_2 , V_33 ) ;
F_3 ( V_2 , 4 , L_18 , V_56 , V_190 , V_41 ) ;
F_98 ( V_2 , 0 , V_56 , V_190 , V_41 ) ;
V_191 = V_56 ;
V_192 = 0 ;
do {
V_193 [ V_192 ++ ] = V_2 -> V_4 . V_5 -> V_83 [ V_191 ] ;
if ( V_191 == V_190 )
break;
V_191 = ( V_191 + 1 ) % 16 ;
} while ( 1 );
V_25 = F_25 ( V_2 , V_41 , V_26 , V_193 , V_192 * sizeof( T_3 ) ) ;
return V_25 ? F_16 ( V_2 , V_25 ) : 0 ;
}
static int F_99 ( struct V_1 * V_2 )
{
int V_56 = ( V_2 -> V_4 . V_5 -> V_9 & 0x00f0 ) >> 4 ;
int V_190 = V_2 -> V_4 . V_5 -> V_9 & 0x000f ;
int V_191 , V_25 , V_192 ;
T_2 V_193 [ 16 ] ;
T_2 V_41 ;
T_1 V_26 ;
V_2 -> V_36 . V_197 ++ ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
V_41 = F_100 ( V_2 , & V_26 ) ;
if ( V_41 & 7 )
return F_5 ( V_2 , V_33 ) ;
F_3 ( V_2 , 4 , L_19 , V_56 , V_190 , V_41 ) ;
F_95 ( V_2 , 1 , V_56 , V_190 , V_41 ) ;
V_192 = ( ( V_190 - V_56 ) & 0xf ) + 1 ;
V_25 = F_15 ( V_2 , V_41 , V_26 , V_193 , V_192 * sizeof( T_2 ) ) ;
if ( V_25 )
return F_16 ( V_2 , V_25 ) ;
V_191 = V_56 ;
V_192 = 0 ;
do {
V_2 -> V_4 . V_5 -> V_83 [ V_191 ] = V_193 [ V_192 ++ ] ;
if ( V_191 == V_190 )
break;
V_191 = ( V_191 + 1 ) % 16 ;
} while ( 1 );
F_96 ( V_195 , V_2 ) ;
return 0 ;
}
static int F_101 ( struct V_1 * V_2 )
{
int V_56 = ( V_2 -> V_4 . V_5 -> V_9 & 0x00f0 ) >> 4 ;
int V_190 = V_2 -> V_4 . V_5 -> V_9 & 0x000f ;
int V_191 , V_25 , V_192 ;
T_2 V_193 [ 16 ] ;
T_2 V_41 ;
T_1 V_26 ;
V_2 -> V_36 . V_198 ++ ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
V_41 = F_100 ( V_2 , & V_26 ) ;
if ( V_41 & 7 )
return F_5 ( V_2 , V_33 ) ;
F_3 ( V_2 , 4 , L_20 , V_56 , V_190 , V_41 ) ;
F_98 ( V_2 , 1 , V_56 , V_190 , V_41 ) ;
V_191 = V_56 ;
V_192 = 0 ;
do {
V_193 [ V_192 ++ ] = V_2 -> V_4 . V_5 -> V_83 [ V_191 ] ;
if ( V_191 == V_190 )
break;
V_191 = ( V_191 + 1 ) % 16 ;
} while ( 1 );
V_25 = F_25 ( V_2 , V_41 , V_26 , V_193 , V_192 * sizeof( T_2 ) ) ;
return V_25 ? F_16 ( V_2 , V_25 ) : 0 ;
}
int F_102 ( struct V_1 * V_2 )
{
T_8 V_141 ;
V_141 = V_199 [ V_2 -> V_4 . V_5 -> V_24 & 0xff ] ;
if ( V_141 )
return V_141 ( V_2 ) ;
return - V_10 ;
}
static int F_103 ( struct V_1 * V_2 )
{
T_2 V_200 , V_201 ;
unsigned long V_168 , V_202 ;
int V_203 = 0 , V_204 = 0 ;
bool V_205 ;
T_1 V_26 ;
V_2 -> V_36 . V_206 ++ ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
F_104 ( V_2 , & V_200 , & V_201 , & V_26 , NULL ) ;
if ( V_201 & 0xf0 )
return - V_10 ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_207 )
F_105 ( V_2 ) ;
V_203 = F_106 ( V_2 , V_200 , V_26 , & V_202 , V_208 ) ;
if ( V_203 == V_209 ) {
V_204 = 1 ;
V_203 = F_106 ( V_2 , V_200 , V_26 , & V_202 ,
V_210 ) ;
}
if ( V_203 ) {
if ( V_203 == V_38 || V_203 == V_211 ) {
V_203 = F_5 ( V_2 , V_203 ) ;
} else if ( V_203 > 0 ) {
F_18 ( V_2 , 3 ) ;
V_203 = 0 ;
}
goto V_212;
}
V_168 = F_107 ( V_2 -> V_3 , F_39 ( V_202 ) , & V_205 ) ;
if ( F_40 ( V_168 ) ) {
V_203 = F_5 ( V_2 , V_38 ) ;
} else {
if ( ! V_205 )
V_204 = 1 ;
F_18 ( V_2 , V_204 ) ;
}
V_212:
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_207 )
F_108 ( V_2 ) ;
return V_203 ;
}
int F_109 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_4 . V_5 -> V_9 & 0x00ff ) == 0x01 )
return F_103 ( V_2 ) ;
return - V_10 ;
}
static int F_110 ( struct V_1 * V_2 )
{
T_3 V_213 ;
if ( V_2 -> V_4 . V_5 -> V_29 . V_30 & V_31 )
return F_5 ( V_2 , V_32 ) ;
if ( V_2 -> V_14 -> V_15 . V_16 . V_58 [ 0 ] & 0x00000000ffff0000 )
return F_5 ( V_2 ,
V_33 ) ;
V_213 = V_2 -> V_14 -> V_15 . V_16 . V_58 [ 0 ] & 0x000000000000ffff ;
V_2 -> V_4 . V_5 -> V_214 = V_213 ;
return 0 ;
}
static int F_111 ( struct V_1 * V_2 )
{
F_18 ( V_2 , 3 ) ;
return 0 ;
}
int F_112 ( struct V_1 * V_2 )
{
T_8 V_141 ;
V_141 = V_215 [ V_2 -> V_4 . V_5 -> V_9 & 0x00ff ] ;
if ( V_141 )
return V_141 ( V_2 ) ;
return - V_10 ;
}
