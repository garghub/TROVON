static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_2 V_4 ;
V_4 = V_5 ;
F_2 ( 1 , V_6 ) ;
V_3 = F_3 ( V_7 ) ;
F_2 ( V_3 | 1 << 5 , V_7 ) ;
F_4 ( 300 ) ;
F_5 ( V_4 , V_8 ) ;
F_6 ( V_4 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
F_1 ( V_2 ) ;
F_8 ( V_2 , & V_10 -> V_12 ) ;
F_9 ( V_2 , & V_10 -> V_12 ) ;
if ( F_6 ( V_13 ) & V_14 )
F_10 ( V_2 , & V_10 -> V_12 , V_13 ) ;
if ( F_6 ( V_15 ) & V_14 )
F_10 ( V_2 , & V_10 -> V_12 , V_15 ) ;
return 0 ;
}
static int F_11 ( struct V_16 * V_17 )
{
return V_18 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned long V_19 ;
T_3 V_20 ;
T_4 V_21 ;
T_4 V_22 ;
if ( ! V_10 -> V_23 ) {
F_13 ( V_2 -> V_2 , L_1 ) ;
return - V_24 ;
}
V_20 = V_10 -> V_23 -> V_25 ;
V_22 = V_26 ;
V_19 = V_10 -> V_27 ;
V_21 = ( V_19 * V_28 ) / V_29 ;
V_21 *= V_22 ;
V_21 /= V_20 ;
V_21 /= V_22 ;
if ( V_21 > ( unsigned long long ) V_30 ||
V_21 < ( unsigned long long ) V_31 )
return - V_32 ;
else {
}
return 0 ;
}
static int F_14 ( struct V_16 * V_17 )
{
int V_33 = V_17 -> V_34 . V_35 ;
if ( V_33 < 1 )
V_33 = 1 ;
V_18 = V_33 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_36 ;
struct V_37 V_34 ;
memset ( & V_34 , 0 , sizeof( struct V_37 ) ) ;
V_34 . V_38 = 100 ;
V_34 . type = V_39 ;
V_40 = F_16 ( L_2 ,
NULL , ( void * ) V_2 , & V_41 , & V_34 ) ;
if ( F_17 ( V_40 ) )
return F_18 ( V_40 ) ;
V_36 = F_12 ( V_2 ) ;
if ( V_36 < 0 ) {
F_19 ( V_40 ) ;
V_40 = NULL ;
return V_36 ;
}
V_40 -> V_34 . V_35 = 100 ;
V_40 -> V_34 . V_38 = 100 ;
F_20 ( V_40 ) ;
V_10 -> V_16 = V_40 ;
return 0 ;
}
static inline T_2 F_21 ( T_5 V_42 , T_5 V_43 )
{
int V_44 = ( 0x10 << 24 ) | ( V_42 << 16 ) | ( V_43 << 8 ) ;
T_4 V_45 = 0 ;
struct V_46 * V_47 = F_22 ( 0 , 0 ) ;
F_23 ( V_47 , 0xD0 , V_44 ) ;
F_24 ( V_47 , 0xD4 , & V_45 ) ;
F_25 ( V_47 ) ;
return V_45 ;
}
static inline void F_26 ( T_5 V_42 , T_5 V_43 , T_2 V_21 )
{
int V_44 = ( 0x11 << 24 ) | ( V_42 << 16 ) | ( V_43 << 8 ) | 0xF0 ;
struct V_46 * V_47 = F_22 ( 0 , 0 ) ;
F_23 ( V_47 , 0xD4 , V_21 ) ;
F_23 ( V_47 , 0xD0 , V_44 ) ;
F_25 ( V_47 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
T_2 V_48 ;
int V_49 ;
V_10 -> V_50 = F_21 ( V_51 ,
V_52 ) & 0xFFFF ;
V_10 -> V_53 = F_21 ( V_51 ,
V_54 ) & 0xFFFF ;
V_48 = F_28 ( V_10 -> V_50 + V_55 ) ;
V_48 &= ~ V_56 ;
V_48 |= V_57 ;
F_29 ( V_48 , V_10 -> V_50 + V_55 ) ;
for ( V_49 = 0 ; V_49 < 5 ; V_49 ++ ) {
T_2 V_58 = F_28 ( V_10 -> V_50 + V_59 ) ;
if ( ( V_58 & V_56 ) == 0 )
return;
F_4 ( 10 ) ;
}
F_13 ( V_2 -> V_2 , L_3 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_60 * V_61 = & V_10 -> V_61 ;
struct V_62 * V_63 ;
F_31 ( V_2 -> V_2 , L_4 ) ;
F_32 ( V_2 -> V_64 , 0xF4 , & V_61 -> V_65 . V_66 ) ;
V_61 -> V_65 . V_67 = F_6 ( V_68 ) ;
V_61 -> V_65 . V_69 = F_6 ( V_70 ) ;
V_61 -> V_65 . V_71 = F_6 ( V_72 ) ;
V_61 -> V_65 . V_73 [ 0 ] = F_6 ( V_74 ) ;
V_61 -> V_65 . V_73 [ 1 ] = F_6 ( V_75 ) ;
V_61 -> V_65 . V_73 [ 2 ] = F_6 ( V_76 ) ;
V_61 -> V_65 . V_73 [ 3 ] = F_6 ( V_77 ) ;
V_61 -> V_65 . V_73 [ 4 ] = F_6 ( V_78 ) ;
V_61 -> V_65 . V_73 [ 5 ] = F_6 ( V_79 ) ;
V_61 -> V_65 . V_80 = F_6 ( V_81 ) ;
V_61 -> V_65 . V_82 = F_6 ( V_83 ) ;
V_61 -> V_65 . V_84 = F_6 ( V_85 ) ;
V_61 -> V_86 = F_6 ( V_87 ) ;
V_61 -> V_88 = F_6 ( V_89 ) ;
V_61 -> V_65 . V_90 = F_6 ( V_91 ) ;
V_61 -> V_65 . V_92 = F_6 ( V_93 ) ;
V_61 -> V_65 . V_94 = F_6 ( V_95 ) ;
V_61 -> V_65 . V_96 = F_6 ( V_97 ) ;
V_61 -> V_65 . V_98 = F_6 ( V_99 ) ;
V_61 -> V_65 . V_100 = F_6 ( V_5 ) ;
V_61 -> V_65 . V_101 = F_6 ( V_102 ) ;
V_61 -> V_65 . V_103 = F_6 ( V_104 ) ;
F_33 (connector, &dev->mode_config.connector_list, head)
V_63 -> V_105 -> V_106 ( V_63 , V_107 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_60 * V_61 = & V_10 -> V_61 ;
struct V_62 * V_63 ;
T_2 V_108 ;
F_35 ( V_2 -> V_64 , 0xF4 , V_61 -> V_65 . V_66 ) ;
F_5 ( V_68 , V_61 -> V_65 . V_67 ) ;
F_5 ( V_70 , V_61 -> V_65 . V_69 ) ;
F_5 ( V_109 , 0 ) ;
F_5 ( V_109 , V_110 | V_111 ) ;
V_108 = F_6 ( V_112 ) ;
if ( ( V_108 & V_113 ) == 0 ) {
F_5 ( V_112 , V_108 | V_113 ) ;
F_6 ( V_112 ) ;
}
V_108 = F_6 ( V_114 ) ;
if ( ( V_108 & V_113 ) == 0 ) {
F_5 ( V_114 , V_108 | V_113 ) ;
F_6 ( V_114 ) ;
}
F_4 ( 500 ) ;
F_5 ( V_74 , V_61 -> V_65 . V_73 [ 0 ] ) ;
F_5 ( V_75 , V_61 -> V_65 . V_73 [ 1 ] ) ;
F_5 ( V_76 , V_61 -> V_65 . V_73 [ 2 ] ) ;
F_5 ( V_77 , V_61 -> V_65 . V_73 [ 3 ] ) ;
F_5 ( V_78 , V_61 -> V_65 . V_73 [ 4 ] ) ;
F_5 ( V_79 , V_61 -> V_65 . V_73 [ 5 ] ) ;
F_5 ( V_72 , V_61 -> V_65 . V_71 ) ;
F_5 ( V_81 , V_61 -> V_65 . V_80 ) ;
F_5 ( V_89 , V_61 -> V_88 ) ;
F_5 ( V_91 , V_61 -> V_65 . V_90 ) ;
F_5 ( V_93 , V_61 -> V_65 . V_92 ) ;
F_5 ( V_85 , V_61 -> V_65 . V_84 ) ;
F_5 ( V_87 , V_61 -> V_86 ) ;
F_5 ( V_95 , V_61 -> V_65 . V_94 ) ;
F_5 ( V_97 , V_61 -> V_65 . V_96 ) ;
F_5 ( V_99 , V_61 -> V_65 . V_98 ) ;
F_5 ( V_83 , V_61 -> V_65 . V_82 ) ;
F_5 ( V_5 , V_61 -> V_65 . V_100 ) ;
F_5 ( V_102 , V_61 -> V_65 . V_101 ) ;
F_5 ( V_104 , V_61 -> V_65 . V_103 ) ;
F_26 ( 3 , 0x30 , 0x08027108 ) ;
F_36 ( V_2 ) ;
F_33 (connector, &dev->mode_config.connector_list, head)
V_63 -> V_105 -> V_106 ( V_63 , V_115 ) ;
F_37 ( V_2 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
T_2 V_48 , V_116 , V_58 ;
int V_117 = 5 ;
V_48 = F_28 ( V_10 -> V_50 + V_55 ) ;
V_48 &= ~ V_56 ;
V_48 |= V_118 ;
V_116 = V_56 ;
F_29 ( V_48 , V_10 -> V_50 + V_55 ) ;
while ( V_117 -- ) {
V_58 = F_28 ( V_10 -> V_50 + V_59 ) ;
if ( ( V_58 & V_116 ) == V_119 )
return 0 ;
F_4 ( 10 ) ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
T_2 V_48 , V_116 , V_58 ;
int V_117 = 5 ;
V_48 = F_28 ( V_10 -> V_50 + V_55 ) ;
V_48 &= ~ V_56 ;
V_48 |= V_57 ;
V_116 = V_56 ;
F_29 ( V_48 , V_10 -> V_50 + V_55 ) ;
while ( V_117 -- ) {
V_58 = F_28 ( V_10 -> V_50 + V_59 ) ;
if ( ( V_58 & V_116 ) == V_120 )
return 0 ;
F_4 ( 10 ) ;
}
return 0 ;
}
static void F_40 ( struct V_1 * V_2 )
{
T_4 clock ;
struct V_46 * V_47 = F_22 ( 0 , 0 ) ;
struct V_9 * V_10 = V_2 -> V_11 ;
F_23 ( V_47 , 0xD0 , 0xD0050300 ) ;
F_24 ( V_47 , 0xD4 , & clock ) ;
F_25 ( V_47 ) ;
switch ( clock & 0x07 ) {
case 0 :
V_10 -> V_27 = 100 ;
break;
case 1 :
V_10 -> V_27 = 133 ;
break;
case 2 :
V_10 -> V_27 = 150 ;
break;
case 3 :
V_10 -> V_27 = 178 ;
break;
case 4 :
V_10 -> V_27 = 200 ;
break;
case 5 :
case 6 :
case 7 :
V_10 -> V_27 = 266 ;
default:
V_10 -> V_27 = 0 ;
}
}
static int F_41 ( struct V_1 * V_2 )
{
F_40 ( V_2 ) ;
F_42 ( V_2 ) ;
F_43 ( V_2 ) ;
F_5 ( V_121 , 0 ) ;
F_5 ( V_122 , F_6 ( V_122 ) ) ;
return 0 ;
}
