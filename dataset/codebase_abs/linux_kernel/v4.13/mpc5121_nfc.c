static inline T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
return F_4 ( V_7 -> V_8 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_9 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
F_6 ( V_7 -> V_8 + V_3 , V_9 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_10 )
{
F_5 ( V_2 , V_3 , F_1 ( V_2 , V_3 ) | V_10 ) ;
}
static inline void F_8 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_10 )
{
F_5 ( V_2 , V_3 , F_1 ( V_2 , V_3 ) & ~ V_10 ) ;
}
static inline void F_9 ( struct V_1 * V_2 , T_1 V_11 )
{
F_5 ( V_2 , V_12 , V_11 ) ;
F_5 ( V_2 , V_13 , V_14 ) ;
F_10 ( V_2 ) ;
}
static inline void F_11 ( struct V_1 * V_2 , T_1 V_15 )
{
F_5 ( V_2 , V_16 , V_15 ) ;
F_5 ( V_2 , V_13 , V_17 ) ;
F_10 ( V_2 ) ;
}
static inline void F_12 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_18 , V_19 ) ;
F_5 ( V_2 , V_13 , V_20 ) ;
F_10 ( V_2 ) ;
}
static inline void F_13 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_18 , V_19 ) ;
F_5 ( V_2 , V_13 , V_21 ) ;
F_10 ( V_2 ) ;
}
static inline void F_14 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_18 , V_19 ) ;
F_5 ( V_2 , V_13 , V_22 ) ;
F_10 ( V_2 ) ;
}
static inline void F_15 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_18 , V_19 ) ;
F_5 ( V_2 , V_13 , V_23 ) ;
F_10 ( V_2 ) ;
}
static T_3 F_16 ( int V_24 , void * V_25 )
{
struct V_1 * V_2 = V_25 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
F_7 ( V_2 , V_26 , V_27 ) ;
F_17 ( & V_7 -> V_28 ) ;
return V_29 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
int V_30 ;
if ( ( F_1 ( V_2 , V_13 ) & V_31 ) == 0 ) {
F_8 ( V_2 , V_26 , V_27 ) ;
V_30 = F_18 ( V_7 -> V_28 ,
( F_1 ( V_2 , V_13 ) & V_31 ) , V_32 ) ;
if ( ! V_30 )
F_19 ( V_7 -> V_33 ,
L_1 ) ;
}
F_8 ( V_2 , V_13 , V_31 ) ;
}
static void F_20 ( struct V_1 * V_2 , int V_34 , int V_35 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_4 V_36 = V_5 -> V_36 ;
if ( V_34 != - 1 ) {
F_9 ( V_2 , V_34 ) ;
if ( V_2 -> V_37 > 512 )
F_9 ( V_2 , V_34 >> 8 ) ;
}
if ( V_35 != - 1 ) {
do {
F_9 ( V_2 , V_35 & 0xFF ) ;
V_35 >>= 8 ;
V_36 >>= 8 ;
} while ( V_36 );
}
}
static void F_21 ( struct V_1 * V_2 , int V_5 )
{
if ( V_5 < 0 ) {
F_8 ( V_2 , V_26 , V_38 ) ;
return;
}
F_8 ( V_2 , V_18 , V_39 ) ;
F_7 ( V_2 , V_18 , ( V_5 << V_40 ) &
V_39 ) ;
F_7 ( V_2 , V_26 , V_38 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_41 * V_42 ;
V_42 = F_23 ( NULL , NULL , L_2 ) ;
if ( V_42 ) {
V_7 -> V_43 = F_24 ( V_42 , 0 ) ;
F_25 ( V_42 ) ;
if ( ! V_7 -> V_43 )
return - V_44 ;
V_7 -> V_43 += 9 ;
return 0 ;
}
return - V_45 ;
}
static void F_26 ( struct V_1 * V_2 , int V_5 )
{
struct V_4 * V_46 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_46 ) ;
T_5 V_47 ;
V_47 = F_27 ( V_7 -> V_43 ) ;
V_47 |= 0x0F ;
if ( V_5 >= 0 ) {
F_21 ( V_2 , 0 ) ;
V_47 &= ~ ( 1 << V_5 ) ;
} else
F_21 ( V_2 , - 1 ) ;
F_28 ( V_7 -> V_43 , V_47 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
return 1 ;
}
static void F_30 ( struct V_1 * V_2 , unsigned V_48 ,
int V_34 , int V_35 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
V_7 -> V_34 = ( V_34 >= 0 ) ? V_34 : 0 ;
V_7 -> V_49 = 0 ;
switch ( V_48 ) {
case V_50 :
F_12 ( V_2 ) ;
break;
case V_51 :
V_34 = 0 ;
break;
case V_52 :
V_7 -> V_34 += 256 ;
V_48 = V_51 ;
V_34 = 0 ;
break;
case V_53 :
V_7 -> V_49 = 1 ;
V_48 = V_51 ;
V_34 = 0 ;
break;
case V_54 :
F_30 ( V_2 , V_51 , V_34 , V_35 ) ;
V_34 = 0 ;
break;
case V_55 :
case V_56 :
case V_57 :
case V_58 :
break;
default:
return;
}
F_11 ( V_2 , V_48 ) ;
F_20 ( V_2 , V_34 , V_35 ) ;
switch ( V_48 ) {
case V_51 :
if ( V_2 -> V_37 > 512 )
F_11 ( V_2 , V_59 ) ;
F_13 ( V_2 ) ;
break;
case V_57 :
F_14 ( V_2 ) ;
break;
case V_58 :
F_15 ( V_2 ) ;
if ( V_5 -> V_60 & V_61 )
V_7 -> V_34 = 1 ;
else
V_7 -> V_34 = 0 ;
break;
}
}
static void F_31 ( struct V_1 * V_2 , T_2 V_62 ,
T_5 * V_63 , T_2 V_64 , int V_65 )
{
struct V_4 * V_46 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_46 ) ;
T_2 V_66 , V_67 , V_68 , V_69 ;
V_68 = ( V_2 -> V_70 / ( V_2 -> V_37 / 512 ) ) & ~ 1 ;
while ( V_64 ) {
V_67 = V_62 / V_68 ;
if ( V_67 > V_71 - 1 )
V_67 = V_71 - 1 ;
V_66 = V_62 - ( V_67 * V_68 ) ;
V_69 = F_32 ( V_68 - V_66 , V_64 ) ;
if ( V_65 )
F_33 ( V_7 -> V_8 + F_34 ( V_67 ) + V_66 ,
V_63 , V_69 ) ;
else
F_35 ( V_63 ,
V_7 -> V_8 + F_34 ( V_67 ) + V_66 , V_69 ) ;
V_63 += V_69 ;
V_62 += V_69 ;
V_64 -= V_69 ;
} ;
}
static void F_36 ( struct V_1 * V_2 , T_6 * V_72 , int V_73 ,
int V_65 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
T_2 V_74 = V_7 -> V_34 ;
T_2 V_75 ;
if ( V_7 -> V_49 || V_74 >= V_2 -> V_37 ) {
if ( V_74 >= V_2 -> V_37 )
V_74 -= V_2 -> V_37 ;
V_7 -> V_34 += V_73 ;
F_31 ( V_2 , V_74 , V_72 , V_73 , V_65 ) ;
return;
}
V_75 = F_32 ( ( T_2 ) V_73 , V_2 -> V_37 - V_74 ) ;
V_7 -> V_34 += V_75 ;
if ( V_65 )
F_33 ( V_7 -> V_8 + F_37 ( 0 ) + V_74 , V_72 , V_75 ) ;
else
F_35 ( V_72 , V_7 -> V_8 + F_37 ( 0 ) + V_74 , V_75 ) ;
if ( V_75 != V_73 ) {
V_72 += V_75 ;
V_73 -= V_75 ;
F_36 ( V_2 , V_72 , V_73 , V_65 ) ;
}
}
static void F_38 ( struct V_1 * V_2 , T_6 * V_72 , int V_73 )
{
F_36 ( V_2 , V_72 , V_73 , 0 ) ;
}
static void F_39 ( struct V_1 * V_2 ,
const T_6 * V_72 , int V_73 )
{
F_36 ( V_2 , ( T_6 * ) V_72 , V_73 , 1 ) ;
}
static T_5 F_40 ( struct V_1 * V_2 )
{
T_5 V_76 ;
F_38 ( V_2 , & V_76 , sizeof( V_76 ) ) ;
return V_76 ;
}
static T_1 F_41 ( struct V_1 * V_2 )
{
T_1 V_76 ;
F_38 ( V_2 , ( T_6 * ) & V_76 , sizeof( V_76 ) ) ;
return V_76 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_77 * V_78 ;
struct V_41 * V_79 ;
T_2 V_80 = 0 ;
T_2 V_81 = 0 ;
T_2 V_82 ;
T_2 V_83 ;
T_2 V_84 , V_85 ;
int V_86 = 0 ;
V_79 = F_23 ( NULL , NULL , L_3 ) ;
if ( ! V_79 ) {
F_43 ( V_7 -> V_33 , L_4
L_5 ) ;
return - V_87 ;
}
V_78 = F_24 ( V_79 , 0 ) ;
if ( ! V_78 ) {
F_43 ( V_7 -> V_33 , L_6 ) ;
V_86 = - V_88 ;
goto V_89;
}
V_83 = F_44 ( & V_78 -> V_90 ) ;
V_82 = ( ( V_83 >> 6 ) & 0x1 ) ? 2 : 1 ;
V_85 = ( V_83 >> 7 ) & 0x1 ;
V_84 = ( V_83 >> 21 ) & 0x3 ;
switch ( ( V_85 << 2 ) | V_84 ) {
case 0x00 :
case 0x01 :
V_80 = 512 ;
V_81 = 16 ;
break;
case 0x02 :
case 0x03 :
V_80 = 4096 ;
V_81 = 128 ;
break;
case 0x04 :
case 0x05 :
V_80 = 2048 ;
V_81 = 64 ;
break;
case 0x06 :
case 0x07 :
V_80 = 4096 ;
V_81 = 218 ;
break;
}
V_2 -> V_37 = V_80 ;
V_2 -> V_70 = V_81 ;
if ( V_82 == 2 )
V_5 -> V_60 |= V_61 ;
F_45 ( V_7 -> V_33 , L_7
L_8
L_9 ,
V_82 * 8 , V_80 ,
V_81 ) ;
F_46 ( V_78 ) ;
V_89:
F_25 ( V_79 ) ;
return V_86 ;
}
static void F_47 ( struct V_91 * V_33 , struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
if ( V_7 -> V_92 )
F_48 ( V_7 -> V_92 ) ;
if ( V_7 -> V_43 )
F_46 ( V_7 -> V_43 ) ;
}
static int F_49 ( struct V_93 * V_94 )
{
struct V_41 * V_42 = V_94 -> V_33 . V_95 ;
struct V_92 * V_92 ;
struct V_91 * V_33 = & V_94 -> V_33 ;
struct V_6 * V_7 ;
struct V_96 V_97 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
unsigned long V_98 , V_99 ;
const T_7 * V_100 ;
int V_101 = 0 ;
int V_102 = 0 ;
int V_103 , V_73 ;
V_103 = ( F_50 ( V_104 ) >> 4 ) & 0xF ;
if ( ( V_103 != 2 ) && ( V_103 != 3 ) ) {
F_43 ( V_33 , L_10 , V_103 ) ;
return - V_105 ;
}
V_7 = F_51 ( V_33 , sizeof( * V_7 ) , V_106 ) ;
if ( ! V_7 )
return - V_44 ;
V_5 = & V_7 -> V_5 ;
V_2 = F_52 ( V_5 ) ;
V_2 -> V_33 . V_107 = V_33 ;
F_53 ( V_5 , V_7 ) ;
F_54 ( V_5 , V_42 ) ;
V_7 -> V_33 = V_33 ;
V_102 = F_42 ( V_2 ) ;
if ( V_102 ) {
F_43 ( V_33 , L_11 ) ;
return V_102 ;
}
V_7 -> V_24 = F_55 ( V_42 , 0 ) ;
if ( V_7 -> V_24 == V_108 ) {
F_43 ( V_33 , L_12 ) ;
return - V_45 ;
}
V_102 = F_56 ( V_42 , 0 , & V_97 ) ;
if ( V_102 ) {
F_43 ( V_33 , L_13 ) ;
return V_102 ;
}
V_100 = F_57 ( V_42 , L_14 , & V_73 ) ;
if ( ! V_100 || V_73 != sizeof( * V_100 ) ) {
F_43 ( V_33 , L_15 ) ;
return - V_45 ;
}
V_98 = V_97 . V_109 ;
V_99 = F_58 ( & V_97 ) ;
if ( ! F_59 ( V_33 , V_98 , V_99 , V_110 ) ) {
F_43 ( V_33 , L_16 ) ;
return - V_88 ;
}
V_7 -> V_8 = F_60 ( V_33 , V_98 , V_99 ) ;
if ( ! V_7 -> V_8 ) {
F_43 ( V_33 , L_17 ) ;
return - V_44 ;
}
V_2 -> V_111 = L_18 ;
V_5 -> V_112 = F_29 ;
V_5 -> V_113 = F_30 ;
V_5 -> V_114 = F_40 ;
V_5 -> V_115 = F_41 ;
V_5 -> V_116 = F_38 ;
V_5 -> V_117 = F_39 ;
V_5 -> V_118 = F_21 ;
V_5 -> V_119 = V_120 ;
V_5 -> V_121 = V_120 ;
V_5 -> V_122 = V_123 ;
V_5 -> V_124 . V_125 = V_126 ;
V_5 -> V_124 . V_127 = V_128 ;
if ( F_61 ( L_19 ) ) {
V_102 = F_22 ( V_2 ) ;
if ( V_102 ) {
F_43 ( V_33 , L_20 ) ;
return V_102 ;
}
V_5 -> V_118 = F_26 ;
}
V_92 = F_62 ( V_33 , L_21 ) ;
if ( F_63 ( V_92 ) ) {
F_43 ( V_33 , L_22 ) ;
V_102 = F_64 ( V_92 ) ;
goto error;
}
V_102 = F_65 ( V_92 ) ;
if ( V_102 ) {
F_43 ( V_33 , L_23 ) ;
goto error;
}
V_7 -> V_92 = V_92 ;
F_7 ( V_2 , V_26 , V_129 ) ;
while ( F_1 ( V_2 , V_26 ) & V_129 ) {
if ( V_101 ++ >= V_130 ) {
F_43 ( V_33 , L_24 ) ;
V_102 = - V_45 ;
goto error;
}
F_66 ( 1 ) ;
}
F_5 ( V_2 , V_131 , V_132 ) ;
F_5 ( V_2 , V_133 , 0x0000 ) ;
F_5 ( V_2 , V_134 , 0xFFFF ) ;
F_5 ( V_2 , V_135 , V_136 ) ;
F_5 ( V_2 , V_26 , V_137 | V_27 |
V_138 ) ;
F_5 ( V_2 , V_139 , V_2 -> V_70 >> 1 ) ;
F_67 ( & V_7 -> V_28 ) ;
V_102 = F_68 ( V_33 , V_7 -> V_24 , & F_16 , 0 , V_110 ,
V_2 ) ;
if ( V_102 ) {
F_43 ( V_33 , L_25 ) ;
goto error;
}
V_102 = F_69 ( V_2 , F_70 ( V_100 ) ) ;
if ( V_102 ) {
F_43 ( V_33 , L_26 ) ;
goto error;
}
switch ( V_2 -> V_140 / V_2 -> V_37 ) {
case 32 :
F_7 ( V_2 , V_26 , V_141 ) ;
break;
case 64 :
F_7 ( V_2 , V_26 , V_142 ) ;
break;
case 128 :
F_7 ( V_2 , V_26 , V_143 ) ;
break;
case 256 :
F_7 ( V_2 , V_26 , V_144 ) ;
break;
default:
F_43 ( V_33 , L_27 ) ;
V_102 = - V_105 ;
goto error;
}
F_71 ( V_33 , V_2 ) ;
V_102 = F_72 ( V_2 , NULL , 0 ) ;
if ( V_102 ) {
F_43 ( V_33 , L_28 ) ;
goto error;
}
return 0 ;
error:
F_47 ( V_33 , V_2 ) ;
return V_102 ;
}
static int F_73 ( struct V_93 * V_94 )
{
struct V_91 * V_33 = & V_94 -> V_33 ;
struct V_1 * V_2 = F_74 ( V_33 ) ;
F_75 ( V_2 ) ;
F_47 ( V_33 , V_2 ) ;
return 0 ;
}
