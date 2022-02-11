static inline T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_6 ;
return F_2 ( V_8 -> V_9 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_10 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_6 ;
F_4 ( V_8 -> V_9 + V_3 , V_10 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_11 )
{
F_3 ( V_2 , V_3 , F_1 ( V_2 , V_3 ) | V_11 ) ;
}
static inline void F_6 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_11 )
{
F_3 ( V_2 , V_3 , F_1 ( V_2 , V_3 ) & ~ V_11 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_1 V_12 )
{
F_3 ( V_2 , V_13 , V_12 ) ;
F_3 ( V_2 , V_14 , V_15 ) ;
F_8 ( V_2 ) ;
}
static inline void F_9 ( struct V_1 * V_2 , T_1 V_16 )
{
F_3 ( V_2 , V_17 , V_16 ) ;
F_3 ( V_2 , V_14 , V_18 ) ;
F_8 ( V_2 ) ;
}
static inline void F_10 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_19 , V_20 ) ;
F_3 ( V_2 , V_14 , V_21 ) ;
F_8 ( V_2 ) ;
}
static inline void F_11 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_19 , V_20 ) ;
F_3 ( V_2 , V_14 , V_22 ) ;
F_8 ( V_2 ) ;
}
static inline void F_12 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_19 , V_20 ) ;
F_3 ( V_2 , V_14 , V_23 ) ;
F_8 ( V_2 ) ;
}
static inline void F_13 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_19 , V_20 ) ;
F_3 ( V_2 , V_14 , V_24 ) ;
F_8 ( V_2 ) ;
}
static T_3 F_14 ( int V_25 , void * V_26 )
{
struct V_1 * V_2 = V_26 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_6 ;
F_5 ( V_2 , V_27 , V_28 ) ;
F_15 ( & V_8 -> V_29 ) ;
return V_30 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_6 ;
int V_31 ;
if ( ( F_1 ( V_2 , V_14 ) & V_32 ) == 0 ) {
F_6 ( V_2 , V_27 , V_28 ) ;
V_31 = F_16 ( V_8 -> V_29 ,
( F_1 ( V_2 , V_14 ) & V_32 ) , V_33 ) ;
if ( ! V_31 )
F_17 ( V_8 -> V_34 ,
L_1 ) ;
}
F_6 ( V_2 , V_14 , V_32 ) ;
}
static void F_18 ( struct V_1 * V_2 , int V_35 , int V_36 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_4 V_37 = V_5 -> V_37 ;
if ( V_35 != - 1 ) {
F_7 ( V_2 , V_35 ) ;
if ( V_2 -> V_38 > 512 )
F_7 ( V_2 , V_35 >> 8 ) ;
}
if ( V_36 != - 1 ) {
do {
F_7 ( V_2 , V_36 & 0xFF ) ;
V_36 >>= 8 ;
V_37 >>= 8 ;
} while ( V_37 );
}
}
static void F_19 ( struct V_1 * V_2 , int V_5 )
{
if ( V_5 < 0 ) {
F_6 ( V_2 , V_27 , V_39 ) ;
return;
}
F_6 ( V_2 , V_19 , V_40 ) ;
F_5 ( V_2 , V_19 , ( V_5 << V_41 ) &
V_40 ) ;
F_5 ( V_2 , V_27 , V_39 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_6 ;
struct V_42 * V_43 ;
V_43 = F_21 ( NULL , NULL , L_2 ) ;
if ( V_43 ) {
V_8 -> V_44 = F_22 ( V_43 , 0 ) ;
F_23 ( V_43 ) ;
if ( ! V_8 -> V_44 )
return - V_45 ;
V_8 -> V_44 += 9 ;
return 0 ;
}
return - V_46 ;
}
static void F_24 ( struct V_1 * V_2 , int V_5 )
{
struct V_4 * V_47 = V_2 -> V_6 ;
struct V_7 * V_8 = V_47 -> V_6 ;
T_5 V_48 ;
V_48 = F_25 ( V_8 -> V_44 ) ;
V_48 |= 0x0F ;
if ( V_5 >= 0 ) {
F_19 ( V_2 , 0 ) ;
V_48 &= ~ ( 1 << V_5 ) ;
} else
F_19 ( V_2 , - 1 ) ;
F_26 ( V_8 -> V_44 , V_48 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
return 1 ;
}
static void F_28 ( struct V_1 * V_2 , unsigned V_49 ,
int V_35 , int V_36 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_6 ;
V_8 -> V_35 = ( V_35 >= 0 ) ? V_35 : 0 ;
V_8 -> V_50 = 0 ;
switch ( V_49 ) {
case V_51 :
F_10 ( V_2 ) ;
break;
case V_52 :
V_35 = 0 ;
break;
case V_53 :
V_8 -> V_35 += 256 ;
V_49 = V_52 ;
V_35 = 0 ;
break;
case V_54 :
V_8 -> V_50 = 1 ;
V_49 = V_52 ;
V_35 = 0 ;
break;
case V_55 :
F_28 ( V_2 , V_52 , V_35 , V_36 ) ;
V_35 = 0 ;
break;
case V_56 :
case V_57 :
case V_58 :
case V_59 :
break;
default:
return;
}
F_9 ( V_2 , V_49 ) ;
F_18 ( V_2 , V_35 , V_36 ) ;
switch ( V_49 ) {
case V_52 :
if ( V_2 -> V_38 > 512 )
F_9 ( V_2 , V_60 ) ;
F_11 ( V_2 ) ;
break;
case V_58 :
F_12 ( V_2 ) ;
break;
case V_59 :
F_13 ( V_2 ) ;
if ( V_5 -> V_61 & V_62 )
V_8 -> V_35 = 1 ;
else
V_8 -> V_35 = 0 ;
break;
}
}
static void F_29 ( struct V_1 * V_2 , T_2 V_63 ,
T_5 * V_64 , T_2 V_65 , int V_66 )
{
struct V_4 * V_47 = V_2 -> V_6 ;
struct V_7 * V_8 = V_47 -> V_6 ;
T_2 V_67 , V_68 , V_69 , V_70 ;
V_69 = ( V_2 -> V_71 / ( V_2 -> V_38 / 512 ) ) & ~ 1 ;
while ( V_65 ) {
V_68 = V_63 / V_69 ;
if ( V_68 > V_72 - 1 )
V_68 = V_72 - 1 ;
V_67 = V_63 - ( V_68 * V_69 ) ;
V_70 = F_30 ( V_69 - V_67 , V_65 ) ;
if ( V_66 )
F_31 ( V_8 -> V_9 + F_32 ( V_68 ) + V_67 ,
V_64 , V_70 ) ;
else
F_33 ( V_64 ,
V_8 -> V_9 + F_32 ( V_68 ) + V_67 , V_70 ) ;
V_64 += V_70 ;
V_63 += V_70 ;
V_65 -= V_70 ;
} ;
}
static void F_34 ( struct V_1 * V_2 , T_6 * V_73 , int V_74 ,
int V_66 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_6 ;
T_2 V_75 = V_8 -> V_35 ;
T_2 V_76 ;
if ( V_8 -> V_50 || V_75 >= V_2 -> V_38 ) {
if ( V_75 >= V_2 -> V_38 )
V_75 -= V_2 -> V_38 ;
V_8 -> V_35 += V_74 ;
F_29 ( V_2 , V_75 , V_73 , V_74 , V_66 ) ;
return;
}
V_76 = F_30 ( ( T_2 ) V_74 , V_2 -> V_38 - V_75 ) ;
V_8 -> V_35 += V_76 ;
if ( V_66 )
F_31 ( V_8 -> V_9 + F_35 ( 0 ) + V_75 , V_73 , V_76 ) ;
else
F_33 ( V_73 , V_8 -> V_9 + F_35 ( 0 ) + V_75 , V_76 ) ;
if ( V_76 != V_74 ) {
V_73 += V_76 ;
V_74 -= V_76 ;
F_34 ( V_2 , V_73 , V_74 , V_66 ) ;
}
}
static void F_36 ( struct V_1 * V_2 , T_6 * V_73 , int V_74 )
{
F_34 ( V_2 , V_73 , V_74 , 0 ) ;
}
static void F_37 ( struct V_1 * V_2 ,
const T_6 * V_73 , int V_74 )
{
F_34 ( V_2 , ( T_6 * ) V_73 , V_74 , 1 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
const T_6 * V_73 , int V_74 )
{
T_6 V_77 [ 256 ] ;
T_2 V_78 ;
while ( V_74 ) {
V_78 = F_30 ( V_74 , 256 ) ;
F_36 ( V_2 , V_77 , V_78 ) ;
if ( memcmp ( V_73 , V_77 , V_78 ) )
return 1 ;
V_73 += V_78 ;
V_74 -= V_78 ;
}
return 0 ;
}
static T_5 F_39 ( struct V_1 * V_2 )
{
T_5 V_77 ;
F_36 ( V_2 , & V_77 , sizeof( V_77 ) ) ;
return V_77 ;
}
static T_1 F_40 ( struct V_1 * V_2 )
{
T_1 V_77 ;
F_36 ( V_2 , ( T_6 * ) & V_77 , sizeof( V_77 ) ) ;
return V_77 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_6 ;
struct V_79 * V_80 ;
struct V_42 * V_81 ;
T_2 V_82 = 0 ;
T_2 V_83 = 0 ;
T_2 V_84 ;
T_2 V_85 ;
T_2 V_86 , V_87 ;
int V_88 = 0 ;
V_81 = F_21 ( NULL , NULL , L_3 ) ;
if ( ! V_81 ) {
F_42 ( V_8 -> V_34 , L_4
L_5 ) ;
return - V_89 ;
}
V_80 = F_22 ( V_81 , 0 ) ;
if ( ! V_80 ) {
F_42 ( V_8 -> V_34 , L_6 ) ;
V_88 = - V_90 ;
goto V_91;
}
V_85 = F_43 ( & V_80 -> V_92 ) ;
V_84 = ( ( V_85 >> 6 ) & 0x1 ) ? 2 : 1 ;
V_87 = ( V_85 >> 7 ) & 0x1 ;
V_86 = ( V_85 >> 21 ) & 0x3 ;
switch ( ( V_87 << 2 ) | V_86 ) {
case 0x00 :
case 0x01 :
V_82 = 512 ;
V_83 = 16 ;
break;
case 0x02 :
case 0x03 :
V_82 = 4096 ;
V_83 = 128 ;
break;
case 0x04 :
case 0x05 :
V_82 = 2048 ;
V_83 = 64 ;
break;
case 0x06 :
case 0x07 :
V_82 = 4096 ;
V_83 = 218 ;
break;
}
V_2 -> V_38 = V_82 ;
V_2 -> V_71 = V_83 ;
if ( V_84 == 2 )
V_5 -> V_61 |= V_62 ;
F_44 ( V_8 -> V_34 , L_7
L_8
L_9 ,
V_84 * 8 , V_82 ,
V_83 ) ;
F_45 ( V_80 ) ;
V_91:
F_23 ( V_81 ) ;
return V_88 ;
}
static void F_46 ( struct V_93 * V_34 , struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_6 ;
if ( V_8 -> V_94 ) {
F_47 ( V_8 -> V_94 ) ;
F_48 ( V_8 -> V_94 ) ;
}
if ( V_8 -> V_44 )
F_45 ( V_8 -> V_44 ) ;
}
static int T_7 F_49 ( struct V_95 * V_96 )
{
struct V_42 * V_97 , * V_43 = V_96 -> V_34 . V_98 ;
struct V_93 * V_34 = & V_96 -> V_34 ;
struct V_7 * V_8 ;
struct V_99 V_100 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
unsigned long V_101 , V_102 ;
const T_8 * V_103 ;
int V_104 = 0 ;
int V_105 = 0 ;
int V_106 , V_74 ;
struct V_107 V_108 ;
V_106 = ( F_50 ( V_109 ) >> 4 ) & 0xF ;
if ( ( V_106 != 2 ) && ( V_106 != 3 ) ) {
F_42 ( V_34 , L_10 , V_106 ) ;
return - V_110 ;
}
V_8 = F_51 ( V_34 , sizeof( * V_8 ) , V_111 ) ;
if ( ! V_8 ) {
F_42 ( V_34 , L_11 ) ;
return - V_45 ;
}
V_2 = & V_8 -> V_2 ;
V_5 = & V_8 -> V_5 ;
V_2 -> V_6 = V_5 ;
V_5 -> V_6 = V_8 ;
V_8 -> V_34 = V_34 ;
V_105 = F_41 ( V_2 ) ;
if ( V_105 ) {
F_42 ( V_34 , L_12 ) ;
return V_105 ;
}
V_8 -> V_25 = F_52 ( V_43 , 0 ) ;
if ( V_8 -> V_25 == V_112 ) {
F_42 ( V_34 , L_13 ) ;
return - V_46 ;
}
V_105 = F_53 ( V_43 , 0 , & V_100 ) ;
if ( V_105 ) {
F_42 ( V_34 , L_14 ) ;
return V_105 ;
}
V_103 = F_54 ( V_43 , L_15 , & V_74 ) ;
if ( ! V_103 || V_74 != sizeof( * V_103 ) ) {
F_42 ( V_34 , L_16 ) ;
return - V_46 ;
}
V_101 = V_100 . V_113 ;
V_102 = F_55 ( & V_100 ) ;
if ( ! F_56 ( V_34 , V_101 , V_102 , V_114 ) ) {
F_42 ( V_34 , L_17 ) ;
return - V_90 ;
}
V_8 -> V_9 = F_57 ( V_34 , V_101 , V_102 ) ;
if ( ! V_8 -> V_9 ) {
F_42 ( V_34 , L_18 ) ;
return - V_45 ;
}
V_2 -> V_115 = L_19 ;
V_108 . V_98 = V_43 ;
V_5 -> V_116 = F_27 ;
V_5 -> V_117 = F_28 ;
V_5 -> V_118 = F_39 ;
V_5 -> V_119 = F_40 ;
V_5 -> V_120 = F_36 ;
V_5 -> V_121 = F_37 ;
V_5 -> V_122 = F_38 ;
V_5 -> V_123 = F_19 ;
V_5 -> V_61 = V_124 ;
V_5 -> V_125 = V_126 ;
V_5 -> V_127 . V_128 = V_129 ;
V_97 = F_58 ( L_20 ) ;
if ( F_59 ( V_97 , L_21 ) ) {
V_105 = F_20 ( V_2 ) ;
if ( V_105 ) {
F_42 ( V_34 , L_22 ) ;
F_23 ( V_97 ) ;
return V_105 ;
}
V_5 -> V_123 = F_24 ;
}
F_23 ( V_97 ) ;
V_8 -> V_94 = F_60 ( V_34 , L_23 ) ;
if ( F_61 ( V_8 -> V_94 ) ) {
F_42 ( V_34 , L_24 ) ;
V_105 = F_62 ( V_8 -> V_94 ) ;
goto error;
}
F_63 ( V_8 -> V_94 ) ;
F_5 ( V_2 , V_27 , V_130 ) ;
while ( F_1 ( V_2 , V_27 ) & V_130 ) {
if ( V_104 ++ >= V_131 ) {
F_42 ( V_34 , L_25 ) ;
V_105 = - V_46 ;
goto error;
}
F_64 ( 1 ) ;
}
F_3 ( V_2 , V_132 , V_133 ) ;
F_3 ( V_2 , V_134 , 0x0000 ) ;
F_3 ( V_2 , V_135 , 0xFFFF ) ;
F_3 ( V_2 , V_136 , V_137 ) ;
F_3 ( V_2 , V_27 , V_138 | V_28 |
V_139 ) ;
F_3 ( V_2 , V_140 , V_2 -> V_71 >> 1 ) ;
F_65 ( & V_8 -> V_29 ) ;
V_105 = F_66 ( V_34 , V_8 -> V_25 , & F_14 , 0 , V_114 ,
V_2 ) ;
if ( V_105 ) {
F_42 ( V_34 , L_26 ) ;
goto error;
}
if ( F_67 ( V_2 , F_68 ( V_103 ) ) ) {
F_42 ( V_34 , L_27 ) ;
F_69 ( V_34 , V_8 -> V_25 , V_2 ) ;
V_105 = - V_110 ;
goto error;
}
switch ( V_2 -> V_141 / V_2 -> V_38 ) {
case 32 :
F_5 ( V_2 , V_27 , V_142 ) ;
break;
case 64 :
F_5 ( V_2 , V_27 , V_143 ) ;
break;
case 128 :
F_5 ( V_2 , V_27 , V_144 ) ;
break;
case 256 :
F_5 ( V_2 , V_27 , V_145 ) ;
break;
default:
F_42 ( V_34 , L_28 ) ;
F_69 ( V_34 , V_8 -> V_25 , V_2 ) ;
V_105 = - V_110 ;
goto error;
}
F_70 ( V_34 , V_2 ) ;
V_105 = F_71 ( V_2 , NULL , & V_108 , NULL , 0 ) ;
if ( V_105 ) {
F_42 ( V_34 , L_29 ) ;
F_69 ( V_34 , V_8 -> V_25 , V_2 ) ;
goto error;
}
return 0 ;
error:
F_46 ( V_34 , V_2 ) ;
return V_105 ;
}
static int T_9 F_72 ( struct V_95 * V_96 )
{
struct V_93 * V_34 = & V_96 -> V_34 ;
struct V_1 * V_2 = F_73 ( V_34 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_6 ;
F_74 ( V_2 ) ;
F_69 ( V_34 , V_8 -> V_25 , V_2 ) ;
F_46 ( V_34 , V_2 ) ;
return 0 ;
}
