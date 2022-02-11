static int F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_3 , 64 ) ) {
V_2 -> V_4 . V_5 -> V_6 |= 0x01 ;
F_3 ( V_2 ) ;
return 0 ;
} else
return F_4 ( V_2 , V_7 ) ;
}
int F_5 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_4 . V_5 -> V_8 & 0xf ) <= 4 )
return F_1 ( V_2 ) ;
else
return - V_9 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_10 ;
T_1 V_11 ;
T_2 V_12 , V_13 ;
if ( V_2 -> V_4 . V_5 -> V_14 . V_15 & V_16 )
return F_4 ( V_2 , V_17 ) ;
V_12 = F_7 ( V_2 , & V_11 ) ;
if ( V_12 & 7 )
return F_4 ( V_2 , V_18 ) ;
V_10 = F_8 ( V_2 , V_12 , V_11 , & V_13 , sizeof( V_13 ) ) ;
if ( V_10 )
return F_9 ( V_2 , V_10 ) ;
F_10 ( V_2 , 3 , L_1 , V_13 ) ;
F_11 ( V_2 -> V_3 , V_13 ) ;
F_12 ( V_2 , 0 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
T_2 V_19 ;
T_3 V_20 ;
int V_10 ;
T_1 V_11 ;
V_2 -> V_21 . V_22 ++ ;
if ( V_2 -> V_4 . V_5 -> V_14 . V_15 & V_16 )
return F_4 ( V_2 , V_17 ) ;
V_19 = F_7 ( V_2 , & V_11 ) ;
if ( V_19 & 3 )
return F_4 ( V_2 , V_18 ) ;
V_10 = F_8 ( V_2 , V_19 , V_11 , & V_20 , sizeof( V_20 ) ) ;
if ( V_10 )
return F_9 ( V_2 , V_10 ) ;
V_20 &= 0x7fffe000u ;
if ( F_14 ( V_2 -> V_3 , V_20 ) )
return F_4 ( V_2 , V_23 ) ;
F_15 ( V_2 , V_20 ) ;
F_16 ( V_2 , 1 , V_20 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
T_2 V_19 ;
T_3 V_20 ;
int V_10 ;
T_1 V_11 ;
V_2 -> V_21 . V_24 ++ ;
if ( V_2 -> V_4 . V_5 -> V_14 . V_15 & V_16 )
return F_4 ( V_2 , V_17 ) ;
V_19 = F_7 ( V_2 , & V_11 ) ;
if ( V_19 & 3 )
return F_4 ( V_2 , V_18 ) ;
V_20 = F_18 ( V_2 ) ;
V_10 = F_19 ( V_2 , V_19 , V_11 , & V_20 , sizeof( V_20 ) ) ;
if ( V_10 )
return F_9 ( V_2 , V_10 ) ;
F_10 ( V_2 , 3 , L_2 , V_20 , V_19 ) ;
F_16 ( V_2 , 0 , V_20 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
T_4 V_25 = V_2 -> V_25 ;
T_2 V_26 ;
int V_10 ;
T_1 V_11 ;
V_2 -> V_21 . V_27 ++ ;
if ( V_2 -> V_4 . V_5 -> V_14 . V_15 & V_16 )
return F_4 ( V_2 , V_17 ) ;
V_26 = F_7 ( V_2 , & V_11 ) ;
if ( V_26 & 1 )
return F_4 ( V_2 , V_18 ) ;
V_10 = F_19 ( V_2 , V_26 , V_11 , & V_25 , sizeof( V_25 ) ) ;
if ( V_10 )
return F_9 ( V_2 , V_10 ) ;
F_10 ( V_2 , 3 , L_3 , V_25 , V_26 ) ;
F_21 ( V_2 , V_26 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_10 = 0 ;
F_23 ( V_2 ) ;
if ( ! ( V_2 -> V_4 . V_5 -> V_28 & ( V_29 | V_30 | V_31 ) ) )
return V_10 ;
V_10 = F_24 () ;
F_10 ( V_2 , 3 , L_4 , V_10 ) ;
if ( ! V_10 )
V_2 -> V_4 . V_5 -> V_28 &= ~ ( V_29 | V_30 | V_31 ) ;
return V_10 ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_10 ;
V_2 -> V_21 . V_32 ++ ;
V_10 = F_22 ( V_2 ) ;
if ( V_10 )
return V_10 ;
if ( V_33 . V_34 ) {
F_3 ( V_2 ) ;
F_10 ( V_2 , 4 , L_5 , L_6 ) ;
return - V_35 ;
}
if ( V_2 -> V_4 . V_5 -> V_14 . V_15 & V_16 )
return F_4 ( V_2 , V_17 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
unsigned long V_36 ;
unsigned char V_37 ;
int V_38 , V_39 ;
int V_10 ;
V_10 = F_25 ( V_2 ) ;
if ( V_10 )
return V_10 != - V_35 ? V_10 : 0 ;
F_27 ( V_2 , & V_38 , & V_39 ) ;
V_36 = V_2 -> V_40 -> V_41 . V_42 . V_43 [ V_39 ] & V_44 ;
V_36 = F_28 ( V_2 , V_36 ) ;
V_36 = F_29 ( V_2 , V_36 ) ;
V_36 = F_30 ( V_2 -> V_3 , F_31 ( V_36 ) ) ;
if ( F_32 ( V_36 ) )
return F_4 ( V_2 , V_23 ) ;
F_33 ( & V_45 -> V_46 -> V_47 ) ;
V_10 = F_34 ( V_45 -> V_46 , V_36 , & V_37 ) ;
F_35 ( & V_45 -> V_46 -> V_47 ) ;
if ( V_10 )
return F_4 ( V_2 , V_23 ) ;
V_2 -> V_40 -> V_41 . V_42 . V_43 [ V_38 ] &= ~ 0xff ;
V_2 -> V_40 -> V_41 . V_42 . V_43 [ V_38 ] |= V_37 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
unsigned long V_36 ;
int V_38 , V_39 ;
int V_10 ;
V_10 = F_25 ( V_2 ) ;
if ( V_10 )
return V_10 != - V_35 ? V_10 : 0 ;
F_27 ( V_2 , & V_38 , & V_39 ) ;
V_36 = V_2 -> V_40 -> V_41 . V_42 . V_43 [ V_39 ] & V_44 ;
V_36 = F_28 ( V_2 , V_36 ) ;
V_36 = F_29 ( V_2 , V_36 ) ;
V_36 = F_30 ( V_2 -> V_3 , F_31 ( V_36 ) ) ;
if ( F_32 ( V_36 ) )
return F_4 ( V_2 , V_23 ) ;
F_33 ( & V_45 -> V_46 -> V_47 ) ;
V_10 = F_37 ( V_45 -> V_46 , V_36 ) ;
F_35 ( & V_45 -> V_46 -> V_47 ) ;
if ( V_10 < 0 )
return F_4 ( V_2 , V_23 ) ;
F_12 ( V_2 , V_10 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
unsigned char V_48 = V_2 -> V_4 . V_5 -> V_49 >> 28 ;
unsigned long V_50 , V_51 ;
unsigned char V_37 , V_52 ;
int V_38 , V_39 ;
int V_10 ;
V_10 = F_25 ( V_2 ) ;
if ( V_10 )
return V_10 != - V_35 ? V_10 : 0 ;
if ( ! F_2 ( V_2 -> V_3 , 8 ) )
V_48 &= ~ V_53 ;
if ( ! F_2 ( V_2 -> V_3 , 10 ) )
V_48 &= ~ ( V_54 | V_55 ) ;
if ( ! F_2 ( V_2 -> V_3 , 14 ) )
V_48 &= ~ V_56 ;
F_27 ( V_2 , & V_38 , & V_39 ) ;
V_37 = V_2 -> V_40 -> V_41 . V_42 . V_43 [ V_38 ] & 0xfe ;
V_50 = V_2 -> V_40 -> V_41 . V_42 . V_43 [ V_39 ] & V_44 ;
V_50 = F_28 ( V_2 , V_50 ) ;
if ( V_48 & V_53 ) {
V_51 = ( V_50 + ( 1UL << 20 ) ) & ~ ( ( 1UL << 20 ) - 1 ) ;
} else {
V_50 = F_29 ( V_2 , V_50 ) ;
V_51 = V_50 + V_57 ;
}
while ( V_50 != V_51 ) {
unsigned long V_36 = F_30 ( V_2 -> V_3 , F_31 ( V_50 ) ) ;
if ( F_32 ( V_36 ) )
return F_4 ( V_2 , V_23 ) ;
F_33 ( & V_45 -> V_46 -> V_47 ) ;
V_10 = F_39 ( V_45 -> V_46 , V_36 , V_37 , & V_52 ,
V_48 & V_56 , V_48 & V_55 ,
V_48 & V_54 ) ;
F_35 ( & V_45 -> V_46 -> V_47 ) ;
if ( V_10 < 0 )
return F_4 ( V_2 , V_23 ) ;
V_50 += V_57 ;
} ;
if ( V_48 & ( V_54 | V_55 ) ) {
if ( V_48 & V_53 ) {
F_12 ( V_2 , 3 ) ;
} else {
F_12 ( V_2 , V_10 ) ;
V_2 -> V_40 -> V_41 . V_42 . V_43 [ V_38 ] &= ~ 0xff00UL ;
V_2 -> V_40 -> V_41 . V_42 . V_43 [ V_38 ] |= ( T_2 ) V_52 << 8 ;
}
}
if ( V_48 & V_53 ) {
if ( F_40 ( V_2 -> V_4 . V_5 -> V_14 ) . V_58 == V_59 )
V_2 -> V_40 -> V_41 . V_42 . V_43 [ V_39 ] &= ~ V_44 ;
else
V_2 -> V_40 -> V_41 . V_42 . V_43 [ V_39 ] &= ~ 0xfffff000UL ;
V_51 = F_28 ( V_2 , V_51 ) ;
V_2 -> V_40 -> V_41 . V_42 . V_43 [ V_39 ] |= V_51 ;
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
V_2 -> V_21 . V_60 ++ ;
if ( F_40 ( V_2 -> V_4 . V_5 -> V_14 ) . V_61 )
return F_4 ( V_2 , V_17 ) ;
F_42 ( V_2 -> V_3 -> V_4 . V_62 , ! F_43 ( V_2 ) ) ;
F_3 ( V_2 ) ;
F_10 ( V_2 , 4 , L_5 , L_7 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
T_5 V_36 ;
int V_39 ;
if ( V_2 -> V_4 . V_5 -> V_14 . V_15 & V_16 )
return F_4 ( V_2 , V_17 ) ;
F_27 ( V_2 , NULL , & V_39 ) ;
V_36 = V_2 -> V_40 -> V_41 . V_42 . V_43 [ V_39 ] & V_44 ;
V_36 = F_28 ( V_2 , V_36 ) ;
if ( F_45 ( V_2 , V_36 ) )
return F_46 ( V_2 , & V_2 -> V_4 . V_63 ) ;
V_36 = F_29 ( V_2 , V_36 ) ;
if ( F_14 ( V_2 -> V_3 , V_36 ) )
return F_4 ( V_2 , V_23 ) ;
if ( F_47 ( V_2 -> V_3 , V_36 , V_57 ) )
return - V_64 ;
F_12 ( V_2 , 0 ) ;
V_2 -> V_40 -> V_41 . V_42 . V_43 [ 0 ] = 0 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_65 * V_66 ;
unsigned long V_67 ;
T_3 V_68 [ 3 ] ;
int V_10 ;
T_2 V_36 ;
T_1 V_11 ;
V_36 = F_7 ( V_2 , & V_11 ) ;
if ( V_36 & 3 )
return F_4 ( V_2 , V_18 ) ;
V_66 = F_49 ( V_2 -> V_3 , V_2 -> V_4 . V_5 -> V_69 [ 6 ] , 0 ) ;
if ( ! V_66 ) {
F_12 ( V_2 , 0 ) ;
return 0 ;
}
V_68 [ 0 ] = V_66 -> V_70 . V_71 << 16 | V_66 -> V_70 . V_72 ;
V_68 [ 1 ] = V_66 -> V_70 . V_73 ;
V_68 [ 2 ] = V_66 -> V_70 . V_74 ;
if ( V_36 ) {
V_67 = sizeof( V_68 ) - 4 ;
V_10 = F_19 ( V_2 , V_36 , V_11 , & V_68 , V_67 ) ;
if ( V_10 ) {
V_10 = F_9 ( V_2 , V_10 ) ;
goto V_75;
}
} else {
V_67 = sizeof( V_68 ) ;
if ( F_50 ( V_2 , V_76 , & V_68 , V_67 ) ) {
V_10 = - V_64 ;
goto V_75;
}
}
F_51 ( V_66 ) ;
F_12 ( V_2 , 1 ) ;
return 0 ;
V_75:
if ( F_52 ( V_2 -> V_3 , V_66 ) ) {
F_51 ( V_66 ) ;
V_10 = - V_64 ;
}
return V_10 ? - V_64 : 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = NULL ;
const T_2 V_77 = 0xffUL << 24 ;
if ( V_2 -> V_40 -> V_41 . V_42 . V_43 [ 1 ] )
V_66 = F_49 ( V_2 -> V_3 , V_77 ,
V_2 -> V_40 -> V_41 . V_42 . V_43 [ 1 ] ) ;
V_2 -> V_40 -> V_78 = V_79 ;
V_2 -> V_40 -> V_80 . V_81 = ! ! V_66 ;
if ( V_66 ) {
V_2 -> V_40 -> V_80 . V_71 = V_66 -> V_70 . V_71 ;
V_2 -> V_40 -> V_80 . V_72 = V_66 -> V_70 . V_72 ;
V_2 -> V_40 -> V_80 . V_73 = V_66 -> V_70 . V_73 ;
V_2 -> V_40 -> V_80 . V_74 = V_66 -> V_70 . V_74 ;
}
V_2 -> V_40 -> V_80 . V_49 = V_2 -> V_4 . V_5 -> V_49 ;
F_51 ( V_66 ) ;
return - V_82 ;
}
static int F_54 ( struct V_1 * V_2 )
{
F_10 ( V_2 , 4 , L_5 , L_8 ) ;
if ( V_2 -> V_4 . V_5 -> V_14 . V_15 & V_16 )
return F_4 ( V_2 , V_17 ) ;
if ( V_2 -> V_3 -> V_4 . V_83 ) {
if ( V_2 -> V_4 . V_5 -> V_8 == 0xb236 )
return F_48 ( V_2 ) ;
if ( V_2 -> V_4 . V_5 -> V_8 == 0xb235 )
return F_53 ( V_2 ) ;
return - V_9 ;
} else {
F_12 ( V_2 , 3 ) ;
return 0 ;
}
}
static int F_55 ( struct V_1 * V_2 )
{
int V_10 ;
unsigned int V_84 ;
V_2 -> V_21 . V_85 ++ ;
if ( V_2 -> V_4 . V_5 -> V_14 . V_15 & V_16 )
return F_4 ( V_2 , V_17 ) ;
V_84 = * V_2 -> V_3 -> V_4 . V_86 . V_87 >> 32 ;
V_10 = F_50 ( V_2 , F_56 ( struct V_88 , V_89 ) ,
& V_84 , sizeof( V_84 ) ) ;
if ( V_10 )
return V_10 ;
F_10 ( V_2 , 3 , L_9 , V_84 ) ;
F_57 ( V_2 , V_84 ) ;
return 0 ;
}
int F_58 ( T_6 * V_90 )
{
if ( V_90 -> V_15 & V_91 )
return 0 ;
if ( ( V_90 -> V_15 & V_92 ) == V_93 ) {
if ( V_90 -> V_36 & ~ V_94 )
return 0 ;
}
if ( ! ( V_90 -> V_15 & V_92 ) && ( V_90 -> V_36 & ~ V_95 ) )
return 0 ;
if ( ( V_90 -> V_15 & V_92 ) == V_96 )
return 0 ;
if ( V_90 -> V_36 & 1 )
return 0 ;
return 1 ;
}
int F_59 ( struct V_1 * V_2 )
{
T_6 * V_14 = & V_2 -> V_4 . V_5 -> V_14 ;
T_7 V_97 ;
T_2 V_36 ;
int V_10 ;
T_1 V_11 ;
if ( V_14 -> V_15 & V_16 )
return F_4 ( V_2 , V_17 ) ;
V_36 = F_7 ( V_2 , & V_11 ) ;
if ( V_36 & 7 )
return F_4 ( V_2 , V_18 ) ;
V_10 = F_8 ( V_2 , V_36 , V_11 , & V_97 , sizeof( V_97 ) ) ;
if ( V_10 )
return F_9 ( V_2 , V_10 ) ;
if ( ! ( V_97 . V_15 & V_98 ) )
return F_4 ( V_2 , V_18 ) ;
V_14 -> V_15 = ( V_97 . V_15 & ~ V_98 ) << 32 ;
V_14 -> V_15 |= V_97 . V_36 & V_99 ;
V_14 -> V_36 = V_97 . V_36 & ~ V_99 ;
if ( ! F_58 ( V_14 ) )
return F_4 ( V_2 , V_18 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
T_6 V_97 ;
T_2 V_36 ;
int V_10 ;
T_1 V_11 ;
if ( V_2 -> V_4 . V_5 -> V_14 . V_15 & V_16 )
return F_4 ( V_2 , V_17 ) ;
V_36 = F_7 ( V_2 , & V_11 ) ;
if ( V_36 & 7 )
return F_4 ( V_2 , V_18 ) ;
V_10 = F_8 ( V_2 , V_36 , V_11 , & V_97 , sizeof( V_97 ) ) ;
if ( V_10 )
return F_9 ( V_2 , V_10 ) ;
V_2 -> V_4 . V_5 -> V_14 = V_97 ;
if ( ! F_58 ( & V_2 -> V_4 . V_5 -> V_14 ) )
return F_4 ( V_2 , V_18 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
T_2 V_100 = V_2 -> V_3 -> V_4 . V_86 . V_101 ;
T_2 V_19 ;
int V_10 ;
T_1 V_11 ;
V_2 -> V_21 . V_102 ++ ;
if ( V_2 -> V_4 . V_5 -> V_14 . V_15 & V_16 )
return F_4 ( V_2 , V_17 ) ;
V_19 = F_7 ( V_2 , & V_11 ) ;
if ( V_19 & 7 )
return F_4 ( V_2 , V_18 ) ;
V_10 = F_19 ( V_2 , V_19 , V_11 , & V_100 , sizeof( V_100 ) ) ;
if ( V_10 )
return F_9 ( V_2 , V_10 ) ;
F_10 ( V_2 , 3 , L_10 , V_100 ) ;
return 0 ;
}
static void F_62 ( struct V_1 * V_2 , struct V_103 * V_104 )
{
int V_105 = 0 ;
int V_106 ;
V_105 = F_63 ( & V_2 -> V_3 -> V_107 ) ;
if ( F_64 ( V_104 , 3 , 2 , 2 ) )
V_104 -> V_108 = 0 ;
if ( V_104 -> V_108 < 8 )
V_104 -> V_108 ++ ;
for ( V_106 = V_104 -> V_108 - 1 ; V_106 > 0 ; V_106 -- )
memcpy ( & V_104 -> V_109 [ V_106 ] , & V_104 -> V_109 [ V_106 - 1 ] , sizeof( V_104 -> V_109 [ 0 ] ) ) ;
memset ( & V_104 -> V_109 [ 0 ] , 0 , sizeof( V_104 -> V_109 [ 0 ] ) ) ;
V_104 -> V_109 [ 0 ] . V_110 = V_105 ;
V_104 -> V_109 [ 0 ] . V_111 = V_105 ;
V_104 -> V_109 [ 0 ] . V_112 = 0 ;
V_104 -> V_109 [ 0 ] . V_113 = 0 ;
V_104 -> V_109 [ 0 ] . V_114 = 1000 ;
memcpy ( V_104 -> V_109 [ 0 ] . V_115 , L_11 , 8 ) ;
F_65 ( V_104 -> V_109 [ 0 ] . V_115 , 8 ) ;
memcpy ( V_104 -> V_109 [ 0 ] . V_116 , L_12 , 16 ) ;
F_65 ( V_104 -> V_109 [ 0 ] . V_116 , 16 ) ;
}
static void F_66 ( struct V_1 * V_2 , T_2 V_36 , T_1 V_11 ,
T_8 V_117 , T_8 V_118 , T_4 V_119 )
{
V_2 -> V_40 -> V_78 = V_120 ;
V_2 -> V_40 -> V_121 . V_36 = V_36 ;
V_2 -> V_40 -> V_121 . V_11 = V_11 ;
V_2 -> V_40 -> V_121 . V_117 = V_117 ;
V_2 -> V_40 -> V_121 . V_118 = V_118 ;
V_2 -> V_40 -> V_121 . V_119 = V_119 ;
}
static int F_67 ( struct V_1 * V_2 )
{
int V_117 = ( V_2 -> V_40 -> V_41 . V_42 . V_43 [ 0 ] & 0xf0000000 ) >> 28 ;
int V_118 = V_2 -> V_40 -> V_41 . V_42 . V_43 [ 0 ] & 0xff ;
int V_119 = V_2 -> V_40 -> V_41 . V_42 . V_43 [ 1 ] & 0xffff ;
unsigned long V_104 = 0 ;
T_2 V_19 ;
int V_10 = 0 ;
T_1 V_11 ;
V_2 -> V_21 . V_122 ++ ;
F_10 ( V_2 , 3 , L_13 , V_117 , V_118 , V_119 ) ;
if ( V_2 -> V_4 . V_5 -> V_14 . V_15 & V_16 )
return F_4 ( V_2 , V_17 ) ;
if ( V_117 > 3 ) {
F_12 ( V_2 , 3 ) ;
return 0 ;
}
if ( V_2 -> V_40 -> V_41 . V_42 . V_43 [ 0 ] & 0x0fffff00
|| V_2 -> V_40 -> V_41 . V_42 . V_43 [ 1 ] & 0xffff0000 )
return F_4 ( V_2 , V_18 ) ;
if ( V_117 == 0 ) {
V_2 -> V_40 -> V_41 . V_42 . V_43 [ 0 ] = 3 << 28 ;
F_12 ( V_2 , 0 ) ;
return 0 ;
}
V_19 = F_7 ( V_2 , & V_11 ) ;
if ( V_19 & 0xfff )
return F_4 ( V_2 , V_18 ) ;
switch ( V_117 ) {
case 1 :
case 2 :
V_104 = F_68 ( V_123 ) ;
if ( ! V_104 )
goto V_124;
if ( F_64 ( ( void * ) V_104 , V_117 , V_118 , V_119 ) )
goto V_124;
break;
case 3 :
if ( V_118 != 2 || V_119 != 2 )
goto V_124;
V_104 = F_68 ( V_123 ) ;
if ( ! V_104 )
goto V_124;
F_62 ( V_2 , ( void * ) V_104 ) ;
break;
}
V_10 = F_19 ( V_2 , V_19 , V_11 , ( void * ) V_104 , V_57 ) ;
if ( V_10 ) {
V_10 = F_9 ( V_2 , V_10 ) ;
goto V_125;
}
if ( V_2 -> V_3 -> V_4 . V_126 ) {
F_66 ( V_2 , V_19 , V_11 , V_117 , V_118 , V_119 ) ;
V_10 = - V_82 ;
}
F_69 ( V_2 , V_117 , V_118 , V_119 , V_19 ) ;
F_70 ( V_104 ) ;
F_12 ( V_2 , 0 ) ;
V_2 -> V_40 -> V_41 . V_42 . V_43 [ 0 ] = 0 ;
return V_10 ;
V_124:
F_12 ( V_2 , 3 ) ;
V_125:
F_70 ( V_104 ) ;
return V_10 ;
}
int F_71 ( struct V_1 * V_2 )
{
T_9 V_127 ;
V_127 = V_128 [ V_2 -> V_4 . V_5 -> V_8 & 0x00ff ] ;
if ( V_127 )
return V_127 ( V_2 ) ;
return - V_9 ;
}
static int F_72 ( struct V_1 * V_2 )
{
int V_38 , V_39 ;
F_27 ( V_2 , & V_38 , & V_39 ) ;
V_2 -> V_40 -> V_41 . V_42 . V_43 [ V_38 ] &= 0xffffffff00000000UL ;
V_2 -> V_40 -> V_41 . V_42 . V_43 [ V_38 ] |= V_2 -> V_4 . V_5 -> V_14 . V_15 >> 32 ;
if ( V_39 ) {
V_2 -> V_40 -> V_41 . V_42 . V_43 [ V_39 ] &= 0xffffffff00000000UL ;
V_2 -> V_40 -> V_41 . V_42 . V_43 [ V_39 ] |=
V_2 -> V_4 . V_5 -> V_14 . V_15 & 0x00000000ffffffffUL ;
}
return 0 ;
}
static int F_73 ( struct V_1 * V_2 )
{
bool V_129 = false , V_130 = false , V_131 ;
int V_38 , V_39 ;
unsigned long V_50 , V_51 ;
unsigned char V_37 ;
V_2 -> V_21 . V_132 ++ ;
F_27 ( V_2 , & V_38 , & V_39 ) ;
if ( ! F_2 ( V_2 -> V_3 , 8 ) )
return F_4 ( V_2 , V_7 ) ;
if ( V_2 -> V_4 . V_5 -> V_14 . V_15 & V_16 )
return F_4 ( V_2 , V_17 ) ;
if ( V_2 -> V_40 -> V_41 . V_42 . V_43 [ V_38 ] & V_133 )
return F_4 ( V_2 , V_18 ) ;
if ( V_2 -> V_40 -> V_41 . V_42 . V_43 [ V_38 ] & V_134 &&
! F_2 ( V_2 -> V_3 , 14 ) )
return F_4 ( V_2 , V_18 ) ;
if ( V_2 -> V_40 -> V_41 . V_42 . V_43 [ V_38 ] & V_135 &&
F_2 ( V_2 -> V_3 , 10 ) ) {
V_129 = V_2 -> V_40 -> V_41 . V_42 . V_43 [ V_38 ] & V_136 ;
V_130 = V_2 -> V_40 -> V_41 . V_42 . V_43 [ V_38 ] & V_137 ;
}
V_131 = V_2 -> V_40 -> V_41 . V_42 . V_43 [ V_38 ] & V_134 ;
V_37 = V_2 -> V_40 -> V_41 . V_42 . V_43 [ V_38 ] & V_138 ;
V_50 = V_2 -> V_40 -> V_41 . V_42 . V_43 [ V_39 ] & V_44 ;
V_50 = F_28 ( V_2 , V_50 ) ;
if ( V_2 -> V_40 -> V_41 . V_42 . V_43 [ V_38 ] & V_139 ) {
if ( F_45 ( V_2 , V_50 ) )
return F_46 ( V_2 , & V_2 -> V_4 . V_63 ) ;
}
switch ( V_2 -> V_40 -> V_41 . V_42 . V_43 [ V_38 ] & V_140 ) {
case 0x00000000 :
V_50 = F_29 ( V_2 , V_50 ) ;
V_51 = ( V_50 + ( 1UL << 12 ) ) & ~ ( ( 1UL << 12 ) - 1 ) ;
break;
case 0x00001000 :
V_51 = ( V_50 + ( 1UL << 20 ) ) & ~ ( ( 1UL << 20 ) - 1 ) ;
break;
case 0x00002000 :
if ( ! F_2 ( V_2 -> V_3 , 78 ) ||
F_40 ( V_2 -> V_4 . V_5 -> V_14 ) . V_58 == V_141 )
return F_4 ( V_2 , V_18 ) ;
V_51 = ( V_50 + ( 1UL << 31 ) ) & ~ ( ( 1UL << 31 ) - 1 ) ;
break;
default:
return F_4 ( V_2 , V_18 ) ;
}
while ( V_50 != V_51 ) {
unsigned long V_142 ;
V_142 = F_30 ( V_2 -> V_3 , F_31 ( V_50 ) ) ;
if ( F_32 ( V_142 ) )
return F_4 ( V_2 , V_23 ) ;
if ( V_2 -> V_40 -> V_41 . V_42 . V_43 [ V_38 ] & V_139 ) {
if ( F_74 ( ( void V_143 * ) V_142 , V_57 ) )
return F_4 ( V_2 , V_23 ) ;
}
if ( V_2 -> V_40 -> V_41 . V_42 . V_43 [ V_38 ] & V_135 ) {
int V_10 = F_22 ( V_2 ) ;
if ( V_10 )
return V_10 ;
F_33 ( & V_45 -> V_46 -> V_47 ) ;
V_10 = F_39 ( V_45 -> V_46 , V_142 ,
V_37 , NULL , V_131 , V_129 , V_130 ) ;
F_35 ( & V_45 -> V_46 -> V_47 ) ;
if ( V_10 < 0 )
return F_4 ( V_2 , V_23 ) ;
}
V_50 += V_57 ;
}
if ( V_2 -> V_40 -> V_41 . V_42 . V_43 [ V_38 ] & V_140 ) {
if ( F_40 ( V_2 -> V_4 . V_5 -> V_14 ) . V_58 == V_59 ) {
V_2 -> V_40 -> V_41 . V_42 . V_43 [ V_39 ] = V_51 ;
} else {
V_2 -> V_40 -> V_41 . V_42 . V_43 [ V_39 ] &= ~ 0xffffffffUL ;
V_51 = F_28 ( V_2 , V_51 ) ;
V_2 -> V_40 -> V_41 . V_42 . V_43 [ V_39 ] |= V_51 ;
}
}
return 0 ;
}
static int F_75 ( struct V_1 * V_2 )
{
int V_144 = ( V_2 -> V_4 . V_5 -> V_145 & ~ V_44 ) >> 3 ;
unsigned long * V_145 ;
struct V_146 * V_146 ;
int V_147 ;
F_10 ( V_2 , 4 , L_14 , V_144 ) ;
V_146 = V_2 -> V_4 . V_146 ;
V_2 -> V_21 . V_148 ++ ;
if ( ! V_2 -> V_3 -> V_4 . V_149 )
return F_4 ( V_2 , V_7 ) ;
if ( V_2 -> V_4 . V_5 -> V_14 . V_15 & V_16 )
return F_4 ( V_2 , V_17 ) ;
if ( ( ( V_2 -> V_4 . V_5 -> V_49 & 0xf0000000 ) >> 28 ) > 6 )
return F_4 ( V_2 , V_18 ) ;
F_3 ( V_2 ) ;
V_2 -> V_4 . V_5 -> V_145 &= V_44 ;
V_145 = F_76 ( V_2 -> V_4 . V_5 -> V_145 ) ;
F_33 ( & V_146 -> V_46 -> V_47 ) ;
for ( V_147 = 0 ; V_147 < V_144 ; ++ V_147 )
F_77 ( V_146 , V_145 [ V_147 ] ) ;
F_35 ( & V_146 -> V_46 -> V_47 ) ;
return 0 ;
}
int F_78 ( struct V_1 * V_2 )
{
T_9 V_127 ;
V_127 = V_150 [ V_2 -> V_4 . V_5 -> V_8 & 0x00ff ] ;
if ( V_127 )
return V_127 ( V_2 ) ;
return - V_9 ;
}
int F_79 ( struct V_1 * V_2 )
{
int V_38 = ( V_2 -> V_4 . V_5 -> V_8 & 0x00f0 ) >> 4 ;
int V_151 = V_2 -> V_4 . V_5 -> V_8 & 0x000f ;
int V_152 , V_10 , V_153 ;
T_3 V_154 [ 16 ] ;
T_2 V_26 ;
T_1 V_11 ;
V_2 -> V_21 . V_155 ++ ;
if ( V_2 -> V_4 . V_5 -> V_14 . V_15 & V_16 )
return F_4 ( V_2 , V_17 ) ;
V_26 = F_80 ( V_2 , & V_11 ) ;
if ( V_26 & 3 )
return F_4 ( V_2 , V_18 ) ;
F_10 ( V_2 , 4 , L_15 , V_38 , V_151 , V_26 ) ;
F_81 ( V_2 , 0 , V_38 , V_151 , V_26 ) ;
V_153 = ( ( V_151 - V_38 ) & 0xf ) + 1 ;
V_10 = F_8 ( V_2 , V_26 , V_11 , V_154 , V_153 * sizeof( T_3 ) ) ;
if ( V_10 )
return F_9 ( V_2 , V_10 ) ;
V_152 = V_38 ;
V_153 = 0 ;
do {
V_2 -> V_4 . V_5 -> V_69 [ V_152 ] &= 0xffffffff00000000ul ;
V_2 -> V_4 . V_5 -> V_69 [ V_152 ] |= V_154 [ V_153 ++ ] ;
if ( V_152 == V_151 )
break;
V_152 = ( V_152 + 1 ) % 16 ;
} while ( 1 );
F_82 ( V_156 , V_2 ) ;
return 0 ;
}
int F_83 ( struct V_1 * V_2 )
{
int V_38 = ( V_2 -> V_4 . V_5 -> V_8 & 0x00f0 ) >> 4 ;
int V_151 = V_2 -> V_4 . V_5 -> V_8 & 0x000f ;
int V_152 , V_10 , V_153 ;
T_3 V_154 [ 16 ] ;
T_2 V_26 ;
T_1 V_11 ;
V_2 -> V_21 . V_157 ++ ;
if ( V_2 -> V_4 . V_5 -> V_14 . V_15 & V_16 )
return F_4 ( V_2 , V_17 ) ;
V_26 = F_80 ( V_2 , & V_11 ) ;
if ( V_26 & 3 )
return F_4 ( V_2 , V_18 ) ;
F_10 ( V_2 , 4 , L_16 , V_38 , V_151 , V_26 ) ;
F_84 ( V_2 , 0 , V_38 , V_151 , V_26 ) ;
V_152 = V_38 ;
V_153 = 0 ;
do {
V_154 [ V_153 ++ ] = V_2 -> V_4 . V_5 -> V_69 [ V_152 ] ;
if ( V_152 == V_151 )
break;
V_152 = ( V_152 + 1 ) % 16 ;
} while ( 1 );
V_10 = F_19 ( V_2 , V_26 , V_11 , V_154 , V_153 * sizeof( T_3 ) ) ;
return V_10 ? F_9 ( V_2 , V_10 ) : 0 ;
}
static int F_85 ( struct V_1 * V_2 )
{
int V_38 = ( V_2 -> V_4 . V_5 -> V_8 & 0x00f0 ) >> 4 ;
int V_151 = V_2 -> V_4 . V_5 -> V_8 & 0x000f ;
int V_152 , V_10 , V_153 ;
T_2 V_154 [ 16 ] ;
T_2 V_26 ;
T_1 V_11 ;
V_2 -> V_21 . V_158 ++ ;
if ( V_2 -> V_4 . V_5 -> V_14 . V_15 & V_16 )
return F_4 ( V_2 , V_17 ) ;
V_26 = F_86 ( V_2 , & V_11 ) ;
if ( V_26 & 7 )
return F_4 ( V_2 , V_18 ) ;
F_10 ( V_2 , 4 , L_17 , V_38 , V_151 , V_26 ) ;
F_81 ( V_2 , 1 , V_38 , V_151 , V_26 ) ;
V_153 = ( ( V_151 - V_38 ) & 0xf ) + 1 ;
V_10 = F_8 ( V_2 , V_26 , V_11 , V_154 , V_153 * sizeof( T_2 ) ) ;
if ( V_10 )
return F_9 ( V_2 , V_10 ) ;
V_152 = V_38 ;
V_153 = 0 ;
do {
V_2 -> V_4 . V_5 -> V_69 [ V_152 ] = V_154 [ V_153 ++ ] ;
if ( V_152 == V_151 )
break;
V_152 = ( V_152 + 1 ) % 16 ;
} while ( 1 );
F_82 ( V_156 , V_2 ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 )
{
int V_38 = ( V_2 -> V_4 . V_5 -> V_8 & 0x00f0 ) >> 4 ;
int V_151 = V_2 -> V_4 . V_5 -> V_8 & 0x000f ;
int V_152 , V_10 , V_153 ;
T_2 V_154 [ 16 ] ;
T_2 V_26 ;
T_1 V_11 ;
V_2 -> V_21 . V_159 ++ ;
if ( V_2 -> V_4 . V_5 -> V_14 . V_15 & V_16 )
return F_4 ( V_2 , V_17 ) ;
V_26 = F_86 ( V_2 , & V_11 ) ;
if ( V_26 & 7 )
return F_4 ( V_2 , V_18 ) ;
F_10 ( V_2 , 4 , L_18 , V_38 , V_151 , V_26 ) ;
F_84 ( V_2 , 1 , V_38 , V_151 , V_26 ) ;
V_152 = V_38 ;
V_153 = 0 ;
do {
V_154 [ V_153 ++ ] = V_2 -> V_4 . V_5 -> V_69 [ V_152 ] ;
if ( V_152 == V_151 )
break;
V_152 = ( V_152 + 1 ) % 16 ;
} while ( 1 );
V_10 = F_19 ( V_2 , V_26 , V_11 , V_154 , V_153 * sizeof( T_2 ) ) ;
return V_10 ? F_9 ( V_2 , V_10 ) : 0 ;
}
int F_88 ( struct V_1 * V_2 )
{
T_9 V_127 ;
V_127 = V_160 [ V_2 -> V_4 . V_5 -> V_49 & 0xff ] ;
if ( V_127 )
return V_127 ( V_2 ) ;
return - V_9 ;
}
static int F_89 ( struct V_1 * V_2 )
{
T_2 V_161 , V_162 ;
unsigned long V_163 , V_164 ;
int V_165 = 0 , V_166 = 0 ;
bool V_167 ;
T_1 V_11 ;
V_2 -> V_21 . V_168 ++ ;
if ( V_2 -> V_4 . V_5 -> V_14 . V_15 & V_16 )
return F_4 ( V_2 , V_17 ) ;
F_90 ( V_2 , & V_161 , & V_162 , & V_11 , NULL ) ;
if ( V_162 & 0xf0 )
return - V_9 ;
if ( V_2 -> V_4 . V_5 -> V_14 . V_15 & V_169 )
F_91 ( V_2 ) ;
V_165 = F_92 ( V_2 , V_161 , V_11 , & V_164 , V_170 ) ;
if ( V_165 == V_171 ) {
V_166 = 1 ;
V_165 = F_92 ( V_2 , V_161 , V_11 , & V_164 ,
V_172 ) ;
}
if ( V_165 ) {
if ( V_165 == V_23 || V_165 == V_173 ) {
V_165 = F_4 ( V_2 , V_165 ) ;
} else if ( V_165 > 0 ) {
F_12 ( V_2 , 3 ) ;
V_165 = 0 ;
}
goto V_174;
}
V_163 = F_93 ( V_2 -> V_3 , F_31 ( V_164 ) , & V_167 ) ;
if ( F_32 ( V_163 ) ) {
V_165 = F_4 ( V_2 , V_23 ) ;
} else {
if ( ! V_167 )
V_166 = 1 ;
F_12 ( V_2 , V_166 ) ;
}
V_174:
if ( V_2 -> V_4 . V_5 -> V_14 . V_15 & V_169 )
F_94 ( V_2 ) ;
return V_165 ;
}
int F_95 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_4 . V_5 -> V_8 & 0x00ff ) == 0x01 )
return F_89 ( V_2 ) ;
return - V_9 ;
}
static int F_96 ( struct V_1 * V_2 )
{
T_3 V_175 ;
if ( V_2 -> V_4 . V_5 -> V_14 . V_15 & V_16 )
return F_4 ( V_2 , V_17 ) ;
if ( V_2 -> V_40 -> V_41 . V_42 . V_43 [ 0 ] & 0x00000000ffff0000 )
return F_4 ( V_2 ,
V_18 ) ;
V_175 = V_2 -> V_40 -> V_41 . V_42 . V_43 [ 0 ] & 0x000000000000ffff ;
V_2 -> V_4 . V_5 -> V_176 = V_175 ;
return 0 ;
}
static int F_97 ( struct V_1 * V_2 )
{
F_12 ( V_2 , 3 ) ;
return 0 ;
}
int F_98 ( struct V_1 * V_2 )
{
T_9 V_127 ;
V_127 = V_177 [ V_2 -> V_4 . V_5 -> V_8 & 0x00ff ] ;
if ( V_127 )
return V_127 ( V_2 ) ;
return - V_9 ;
}
