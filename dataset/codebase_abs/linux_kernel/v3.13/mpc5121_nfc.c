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
static T_5 F_38 ( struct V_1 * V_2 )
{
T_5 V_77 ;
F_36 ( V_2 , & V_77 , sizeof( V_77 ) ) ;
return V_77 ;
}
static T_1 F_39 ( struct V_1 * V_2 )
{
T_1 V_77 ;
F_36 ( V_2 , ( T_6 * ) & V_77 , sizeof( V_77 ) ) ;
return V_77 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_6 ;
struct V_78 * V_79 ;
struct V_42 * V_80 ;
T_2 V_81 = 0 ;
T_2 V_82 = 0 ;
T_2 V_83 ;
T_2 V_84 ;
T_2 V_85 , V_86 ;
int V_87 = 0 ;
V_80 = F_21 ( NULL , NULL , L_3 ) ;
if ( ! V_80 ) {
F_41 ( V_8 -> V_34 , L_4
L_5 ) ;
return - V_88 ;
}
V_79 = F_22 ( V_80 , 0 ) ;
if ( ! V_79 ) {
F_41 ( V_8 -> V_34 , L_6 ) ;
V_87 = - V_89 ;
goto V_90;
}
V_84 = F_42 ( & V_79 -> V_91 ) ;
V_83 = ( ( V_84 >> 6 ) & 0x1 ) ? 2 : 1 ;
V_86 = ( V_84 >> 7 ) & 0x1 ;
V_85 = ( V_84 >> 21 ) & 0x3 ;
switch ( ( V_86 << 2 ) | V_85 ) {
case 0x00 :
case 0x01 :
V_81 = 512 ;
V_82 = 16 ;
break;
case 0x02 :
case 0x03 :
V_81 = 4096 ;
V_82 = 128 ;
break;
case 0x04 :
case 0x05 :
V_81 = 2048 ;
V_82 = 64 ;
break;
case 0x06 :
case 0x07 :
V_81 = 4096 ;
V_82 = 218 ;
break;
}
V_2 -> V_38 = V_81 ;
V_2 -> V_71 = V_82 ;
if ( V_83 == 2 )
V_5 -> V_61 |= V_62 ;
F_43 ( V_8 -> V_34 , L_7
L_8
L_9 ,
V_83 * 8 , V_81 ,
V_82 ) ;
F_44 ( V_79 ) ;
V_90:
F_23 ( V_80 ) ;
return V_87 ;
}
static void F_45 ( struct V_92 * V_34 , struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_6 ;
if ( V_8 -> V_93 )
F_46 ( V_8 -> V_93 ) ;
if ( V_8 -> V_44 )
F_44 ( V_8 -> V_44 ) ;
}
static int F_47 ( struct V_94 * V_95 )
{
struct V_42 * V_96 , * V_43 = V_95 -> V_34 . V_97 ;
struct V_93 * V_93 ;
struct V_92 * V_34 = & V_95 -> V_34 ;
struct V_7 * V_8 ;
struct V_98 V_99 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
unsigned long V_100 , V_101 ;
const T_7 * V_102 ;
int V_103 = 0 ;
int V_104 = 0 ;
int V_105 , V_74 ;
struct V_106 V_107 ;
V_105 = ( F_48 ( V_108 ) >> 4 ) & 0xF ;
if ( ( V_105 != 2 ) && ( V_105 != 3 ) ) {
F_41 ( V_34 , L_10 , V_105 ) ;
return - V_109 ;
}
V_8 = F_49 ( V_34 , sizeof( * V_8 ) , V_110 ) ;
if ( ! V_8 ) {
F_41 ( V_34 , L_11 ) ;
return - V_45 ;
}
V_2 = & V_8 -> V_2 ;
V_5 = & V_8 -> V_5 ;
V_2 -> V_6 = V_5 ;
V_5 -> V_6 = V_8 ;
V_8 -> V_34 = V_34 ;
V_104 = F_40 ( V_2 ) ;
if ( V_104 ) {
F_41 ( V_34 , L_12 ) ;
return V_104 ;
}
V_8 -> V_25 = F_50 ( V_43 , 0 ) ;
if ( V_8 -> V_25 == V_111 ) {
F_41 ( V_34 , L_13 ) ;
return - V_46 ;
}
V_104 = F_51 ( V_43 , 0 , & V_99 ) ;
if ( V_104 ) {
F_41 ( V_34 , L_14 ) ;
return V_104 ;
}
V_102 = F_52 ( V_43 , L_15 , & V_74 ) ;
if ( ! V_102 || V_74 != sizeof( * V_102 ) ) {
F_41 ( V_34 , L_16 ) ;
return - V_46 ;
}
V_100 = V_99 . V_112 ;
V_101 = F_53 ( & V_99 ) ;
if ( ! F_54 ( V_34 , V_100 , V_101 , V_113 ) ) {
F_41 ( V_34 , L_17 ) ;
return - V_89 ;
}
V_8 -> V_9 = F_55 ( V_34 , V_100 , V_101 ) ;
if ( ! V_8 -> V_9 ) {
F_41 ( V_34 , L_18 ) ;
return - V_45 ;
}
V_2 -> V_114 = L_19 ;
V_107 . V_97 = V_43 ;
V_5 -> V_115 = F_27 ;
V_5 -> V_116 = F_28 ;
V_5 -> V_117 = F_38 ;
V_5 -> V_118 = F_39 ;
V_5 -> V_119 = F_36 ;
V_5 -> V_120 = F_37 ;
V_5 -> V_121 = F_19 ;
V_5 -> V_122 = V_123 ;
V_5 -> V_124 . V_125 = V_126 ;
V_96 = F_56 ( L_20 ) ;
if ( F_57 ( V_96 , L_21 ) ) {
V_104 = F_20 ( V_2 ) ;
if ( V_104 ) {
F_41 ( V_34 , L_22 ) ;
F_23 ( V_96 ) ;
return V_104 ;
}
V_5 -> V_121 = F_24 ;
}
F_23 ( V_96 ) ;
V_93 = F_58 ( V_34 , L_23 ) ;
if ( F_59 ( V_93 ) ) {
F_41 ( V_34 , L_24 ) ;
V_104 = F_60 ( V_93 ) ;
goto error;
}
V_104 = F_61 ( V_93 ) ;
if ( V_104 ) {
F_41 ( V_34 , L_25 ) ;
goto error;
}
V_8 -> V_93 = V_93 ;
F_5 ( V_2 , V_27 , V_127 ) ;
while ( F_1 ( V_2 , V_27 ) & V_127 ) {
if ( V_103 ++ >= V_128 ) {
F_41 ( V_34 , L_26 ) ;
V_104 = - V_46 ;
goto error;
}
F_62 ( 1 ) ;
}
F_3 ( V_2 , V_129 , V_130 ) ;
F_3 ( V_2 , V_131 , 0x0000 ) ;
F_3 ( V_2 , V_132 , 0xFFFF ) ;
F_3 ( V_2 , V_133 , V_134 ) ;
F_3 ( V_2 , V_27 , V_135 | V_28 |
V_136 ) ;
F_3 ( V_2 , V_137 , V_2 -> V_71 >> 1 ) ;
F_63 ( & V_8 -> V_29 ) ;
V_104 = F_64 ( V_34 , V_8 -> V_25 , & F_14 , 0 , V_113 ,
V_2 ) ;
if ( V_104 ) {
F_41 ( V_34 , L_27 ) ;
goto error;
}
if ( F_65 ( V_2 , F_66 ( V_102 ) ) ) {
F_41 ( V_34 , L_28 ) ;
F_67 ( V_34 , V_8 -> V_25 , V_2 ) ;
V_104 = - V_109 ;
goto error;
}
switch ( V_2 -> V_138 / V_2 -> V_38 ) {
case 32 :
F_5 ( V_2 , V_27 , V_139 ) ;
break;
case 64 :
F_5 ( V_2 , V_27 , V_140 ) ;
break;
case 128 :
F_5 ( V_2 , V_27 , V_141 ) ;
break;
case 256 :
F_5 ( V_2 , V_27 , V_142 ) ;
break;
default:
F_41 ( V_34 , L_29 ) ;
F_67 ( V_34 , V_8 -> V_25 , V_2 ) ;
V_104 = - V_109 ;
goto error;
}
F_68 ( V_34 , V_2 ) ;
V_104 = F_69 ( V_2 , NULL , & V_107 , NULL , 0 ) ;
if ( V_104 ) {
F_41 ( V_34 , L_30 ) ;
F_67 ( V_34 , V_8 -> V_25 , V_2 ) ;
goto error;
}
return 0 ;
error:
F_45 ( V_34 , V_2 ) ;
return V_104 ;
}
static int F_70 ( struct V_94 * V_95 )
{
struct V_92 * V_34 = & V_95 -> V_34 ;
struct V_1 * V_2 = F_71 ( V_34 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_6 ;
F_72 ( V_2 ) ;
F_67 ( V_34 , V_8 -> V_25 , V_2 ) ;
F_45 ( V_34 , V_2 ) ;
return 0 ;
}
