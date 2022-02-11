T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 . V_4 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 -> V_6 )
return V_2 -> V_5 -> V_6 ( V_2 ) ;
return F_2 ( V_2 -> V_3 . V_7 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 )
{
T_1 V_8 ;
if ( V_2 -> V_5 -> V_6 || V_2 -> V_3 . V_7 ) {
V_8 = F_3 ( V_2 ) ;
if ( V_8 & V_9 )
return V_8 ;
}
V_8 = V_2 -> V_5 -> V_10 ( V_2 ) ;
return V_8 ;
}
static void F_5 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 -> V_6 )
V_2 -> V_5 -> V_6 ( V_2 ) ;
else if ( V_2 -> V_3 . V_7 )
F_2 ( V_2 -> V_3 . V_7 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
F_7 ( 400 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 -> V_6 || V_2 -> V_3 . V_7 ) {
F_3 ( V_2 ) ;
return;
}
F_9 () ;
}
int F_10 ( struct V_1 * V_2 ,
unsigned long V_11 , unsigned long V_12 )
{
unsigned long V_13 , V_14 ;
T_1 V_8 ;
V_8 = F_11 ( V_2 , V_9 , 300 ) ;
V_13 = V_15 ;
V_14 = F_12 ( V_13 , V_11 ) ;
while ( V_8 != 0xff && ( V_8 & V_9 ) &&
F_13 ( V_15 , V_14 ) ) {
F_14 ( V_2 , 50 ) ;
V_8 = F_11 ( V_2 , V_9 , 3 ) ;
}
if ( V_8 != 0xff && ( V_8 & V_9 ) )
F_15 ( V_2 , V_16 ,
L_1
L_2 , V_8 ) ;
V_14 = F_12 ( V_13 , V_12 ) ;
while ( V_8 != 0xff && ( V_8 & V_9 ) &&
F_13 ( V_15 , V_14 ) ) {
F_14 ( V_2 , 50 ) ;
V_8 = V_2 -> V_5 -> V_10 ( V_2 ) ;
}
if ( V_8 == 0xff )
return - V_17 ;
if ( V_8 & V_9 ) {
F_15 ( V_2 , V_18 , L_3
L_4 ,
F_16 ( V_12 , 1000 ) , V_8 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_17 ( struct V_20 * V_21 )
{
T_1 V_8 = V_21 -> V_2 -> V_5 -> V_10 ( V_21 -> V_2 ) ;
return F_18 ( V_8 ) ;
}
int F_19 ( struct V_20 * V_21 , unsigned long V_22 )
{
return F_20 ( V_21 , V_22 , F_17 ) ;
}
static void F_21 ( struct V_1 * V_2 , T_1 V_23 )
{
if ( V_2 -> V_5 -> V_24 )
V_2 -> V_5 -> V_24 ( V_2 , V_23 ) ;
else
F_22 ( V_23 , V_2 -> V_3 . V_25 ) ;
}
void F_23 ( struct V_1 * V_2 , unsigned int V_26 )
{
T_1 V_27 ;
if ( V_26 == 0 )
V_27 = V_28 ;
else
V_27 = V_28 | V_29 ;
F_22 ( V_27 , V_2 -> V_3 . V_30 ) ;
F_6 ( V_2 ) ;
}
static void F_24 ( struct V_1 * V_2 , unsigned int V_26 ,
unsigned int V_31 , unsigned int V_32 )
{
if ( F_25 ( V_2 ) )
F_15 ( V_2 , V_33 , L_5
L_6 , V_26 , V_31 ) ;
if ( V_31 )
F_26 ( V_2 ) ;
V_2 -> V_5 -> V_34 ( V_2 , V_26 ) ;
if ( V_31 ) {
if ( V_32 && V_2 -> V_21 . V_26 [ V_26 ] . V_35 == V_36 )
F_14 ( V_2 , 150 ) ;
F_26 ( V_2 ) ;
}
}
void F_27 ( struct V_1 * V_2 )
{
struct V_37 * V_3 = & V_2 -> V_3 ;
if ( V_2 -> V_5 -> V_38 ) {
V_2 -> V_5 -> V_38 ( V_2 ) ;
return;
}
V_2 -> V_23 &= ~ V_39 ;
V_2 -> V_40 = V_2 -> V_23 ;
if ( V_2 -> V_5 -> V_24 || V_3 -> V_25 )
F_21 ( V_2 , V_2 -> V_23 ) ;
F_26 ( V_2 ) ;
if ( V_2 -> V_5 -> V_41 )
V_2 -> V_5 -> V_41 ( V_2 ) ;
}
void F_28 ( struct V_1 * V_2 , const struct V_42 * V_43 )
{
struct V_37 * V_3 = & V_2 -> V_3 ;
unsigned int V_44 = V_43 -> V_45 & V_46 ;
if ( V_43 -> V_23 != V_2 -> V_40 ) {
if ( V_3 -> V_25 )
F_22 ( V_43 -> V_23 , V_3 -> V_25 ) ;
V_2 -> V_40 = V_43 -> V_23 ;
F_26 ( V_2 ) ;
}
if ( V_44 && ( V_43 -> V_45 & V_47 ) ) {
F_29 ( ! V_3 -> V_25 ) ;
F_22 ( V_43 -> V_48 , V_3 -> V_49 ) ;
F_22 ( V_43 -> V_50 , V_3 -> V_51 ) ;
F_22 ( V_43 -> V_52 , V_3 -> V_53 ) ;
F_22 ( V_43 -> V_54 , V_3 -> V_55 ) ;
F_22 ( V_43 -> V_56 , V_3 -> V_57 ) ;
F_30 ( L_7 ,
V_43 -> V_48 ,
V_43 -> V_50 ,
V_43 -> V_52 ,
V_43 -> V_54 ,
V_43 -> V_56 ) ;
}
if ( V_44 ) {
F_22 ( V_43 -> V_58 , V_3 -> V_49 ) ;
F_22 ( V_43 -> V_59 , V_3 -> V_51 ) ;
F_22 ( V_43 -> V_60 , V_3 -> V_53 ) ;
F_22 ( V_43 -> V_61 , V_3 -> V_55 ) ;
F_22 ( V_43 -> V_62 , V_3 -> V_57 ) ;
F_30 ( L_8 ,
V_43 -> V_58 ,
V_43 -> V_59 ,
V_43 -> V_60 ,
V_43 -> V_61 ,
V_43 -> V_62 ) ;
}
if ( V_43 -> V_45 & V_63 ) {
F_22 ( V_43 -> V_26 , V_3 -> V_30 ) ;
F_30 ( L_9 , V_43 -> V_26 ) ;
}
F_26 ( V_2 ) ;
}
void F_31 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
struct V_37 * V_3 = & V_2 -> V_3 ;
V_43 -> V_64 = F_1 ( V_2 ) ;
V_43 -> V_58 = F_2 ( V_3 -> V_65 ) ;
V_43 -> V_59 = F_2 ( V_3 -> V_51 ) ;
V_43 -> V_60 = F_2 ( V_3 -> V_53 ) ;
V_43 -> V_61 = F_2 ( V_3 -> V_55 ) ;
V_43 -> V_62 = F_2 ( V_3 -> V_57 ) ;
V_43 -> V_26 = F_2 ( V_3 -> V_30 ) ;
if ( V_43 -> V_45 & V_47 ) {
if ( F_32 ( V_3 -> V_25 ) ) {
F_22 ( V_43 -> V_23 | V_66 , V_3 -> V_25 ) ;
V_43 -> V_48 = F_2 ( V_3 -> V_65 ) ;
V_43 -> V_50 = F_2 ( V_3 -> V_51 ) ;
V_43 -> V_52 = F_2 ( V_3 -> V_53 ) ;
V_43 -> V_54 = F_2 ( V_3 -> V_55 ) ;
V_43 -> V_56 = F_2 ( V_3 -> V_57 ) ;
F_22 ( V_43 -> V_23 , V_3 -> V_25 ) ;
V_2 -> V_40 = V_43 -> V_23 ;
} else
F_29 ( 1 ) ;
}
}
void F_33 ( struct V_1 * V_2 , const struct V_42 * V_43 )
{
F_34 ( L_10 , V_2 -> V_67 , V_43 -> V_64 ) ;
F_22 ( V_43 -> V_64 , V_2 -> V_3 . V_68 ) ;
F_6 ( V_2 ) ;
}
static inline void F_35 ( struct V_1 * V_2 ,
const struct V_42 * V_43 )
{
V_2 -> V_5 -> V_69 ( V_2 , V_43 ) ;
V_2 -> V_5 -> V_70 ( V_2 , V_43 ) ;
}
unsigned int F_36 ( struct V_71 * V_72 , unsigned char * V_73 ,
unsigned int V_74 , int V_75 )
{
struct V_1 * V_2 = V_72 -> V_21 -> V_2 ;
void T_2 * V_76 = V_2 -> V_3 . V_76 ;
unsigned int V_77 = V_74 >> 1 ;
if ( V_75 == V_78 )
F_37 ( V_76 , V_73 , V_77 ) ;
else
F_38 ( V_76 , V_73 , V_77 ) ;
if ( F_39 ( V_74 & 0x01 ) ) {
unsigned char V_79 [ 2 ] ;
V_73 += V_74 - 1 ;
if ( V_75 == V_78 ) {
F_37 ( V_76 , V_79 , 1 ) ;
* V_73 = V_79 [ 0 ] ;
} else {
V_79 [ 0 ] = * V_73 ;
F_38 ( V_76 , V_79 , 1 ) ;
}
V_77 ++ ;
}
return V_77 << 1 ;
}
unsigned int F_40 ( struct V_71 * V_72 , unsigned char * V_73 ,
unsigned int V_74 , int V_75 )
{
struct V_1 * V_2 = V_72 -> V_21 -> V_2 ;
void T_2 * V_76 = V_2 -> V_3 . V_76 ;
unsigned int V_77 = V_74 >> 2 ;
int V_80 = V_74 & 3 ;
if ( ! ( V_2 -> V_81 & V_82 ) )
return F_36 ( V_72 , V_73 , V_74 , V_75 ) ;
if ( V_75 == V_78 )
F_41 ( V_76 , V_73 , V_77 ) ;
else
F_42 ( V_76 , V_73 , V_77 ) ;
if ( F_39 ( V_80 ) ) {
unsigned char V_79 [ 4 ] ;
V_73 += V_74 - V_80 ;
if ( V_75 == V_78 ) {
if ( V_80 < 3 )
F_37 ( V_76 , V_79 , 1 ) ;
else
F_41 ( V_76 , V_79 , 1 ) ;
memcpy ( V_73 , V_79 , V_80 ) ;
} else {
memcpy ( V_79 , V_73 , V_80 ) ;
if ( V_80 < 3 )
F_38 ( V_76 , V_79 , 1 ) ;
else
F_42 ( V_76 , V_79 , 1 ) ;
}
}
return ( V_74 + 1 ) & ~ 1 ;
}
unsigned int F_43 ( struct V_71 * V_72 , unsigned char * V_73 ,
unsigned int V_74 , int V_75 )
{
unsigned long V_45 ;
unsigned int V_83 ;
F_44 ( V_45 ) ;
V_83 = F_36 ( V_72 , V_73 , V_74 , V_75 ) ;
F_45 ( V_45 ) ;
return V_83 ;
}
static void F_46 ( struct V_84 * V_85 )
{
int V_86 = ( V_85 -> V_43 . V_45 & V_87 ) ;
struct V_1 * V_2 = V_85 -> V_2 ;
struct V_88 * V_88 ;
unsigned int V_89 ;
unsigned char * V_73 ;
if ( V_85 -> V_90 == V_85 -> V_91 - V_85 -> V_92 )
V_2 -> V_93 = V_94 ;
V_88 = F_47 ( V_85 -> V_95 ) ;
V_89 = V_85 -> V_95 -> V_89 + V_85 -> V_96 ;
V_88 = F_48 ( V_88 , ( V_89 >> V_97 ) ) ;
V_89 %= V_98 ;
F_34 ( L_11 , V_85 -> V_43 . V_45 & V_87 ? L_12 : L_13 ) ;
if ( F_49 ( V_88 ) ) {
unsigned long V_45 ;
F_44 ( V_45 ) ;
V_73 = F_50 ( V_88 , V_99 ) ;
V_2 -> V_5 -> V_100 ( V_85 -> V_72 , V_73 + V_89 , V_85 -> V_92 ,
V_86 ) ;
F_51 ( V_73 , V_99 ) ;
F_45 ( V_45 ) ;
} else {
V_73 = F_52 ( V_88 ) ;
V_2 -> V_5 -> V_100 ( V_85 -> V_72 , V_73 + V_89 , V_85 -> V_92 ,
V_86 ) ;
}
if ( ! V_86 && ! F_53 ( V_88 ) )
F_54 ( V_88 ) ;
V_85 -> V_90 += V_85 -> V_92 ;
V_85 -> V_96 += V_85 -> V_92 ;
if ( V_85 -> V_96 == V_85 -> V_95 -> V_101 ) {
V_85 -> V_95 = F_55 ( V_85 -> V_95 ) ;
V_85 -> V_96 = 0 ;
}
}
static void F_56 ( struct V_84 * V_85 )
{
if ( F_57 ( & V_85 -> V_43 ) ) {
unsigned int V_59 ;
F_29 ( V_85 -> V_72 -> V_102 == 0 ) ;
V_59 = F_58 ( ( V_85 -> V_91 - V_85 -> V_90 ) / V_85 -> V_92 ,
V_85 -> V_72 -> V_102 ) ;
while ( V_59 -- )
F_46 ( V_85 ) ;
} else
F_46 ( V_85 ) ;
F_5 ( V_85 -> V_2 ) ;
}
static void F_59 ( struct V_1 * V_2 , struct V_84 * V_85 )
{
F_34 ( L_14 ) ;
F_29 ( V_85 -> V_72 -> V_103 < 12 ) ;
V_2 -> V_5 -> V_100 ( V_85 -> V_72 , V_85 -> V_104 , V_85 -> V_72 -> V_103 , 1 ) ;
F_5 ( V_2 ) ;
switch ( V_85 -> V_43 . V_105 ) {
case V_106 :
V_2 -> V_93 = V_107 ;
break;
case V_108 :
V_2 -> V_93 = V_94 ;
break;
#ifdef F_60
case V_109 :
V_2 -> V_93 = V_94 ;
V_2 -> V_5 -> V_110 ( V_85 ) ;
break;
#endif
default:
F_9 () ;
}
}
static int F_61 ( struct V_84 * V_85 , unsigned int V_111 )
{
int V_75 = ( V_85 -> V_43 . V_45 & V_87 ) ? V_112 : V_78 ;
struct V_1 * V_2 = V_85 -> V_2 ;
struct V_71 * V_72 = V_85 -> V_72 ;
struct V_113 * V_114 = & V_72 -> V_21 -> V_115 ;
struct V_116 * V_117 ;
struct V_88 * V_88 ;
unsigned char * V_73 ;
unsigned int V_89 , V_118 , V_83 ;
V_119:
V_117 = V_85 -> V_95 ;
if ( F_39 ( ! V_117 ) ) {
F_62 ( V_114 , L_15
L_16 ,
V_85 -> V_91 , V_85 -> V_90 , V_111 ) ;
return - 1 ;
}
V_88 = F_47 ( V_117 ) ;
V_89 = V_117 -> V_89 + V_85 -> V_96 ;
V_88 = F_48 ( V_88 , ( V_89 >> V_97 ) ) ;
V_89 %= V_98 ;
V_118 = F_58 ( V_117 -> V_101 - V_85 -> V_96 , V_111 ) ;
V_118 = F_58 ( V_118 , ( unsigned int ) V_98 - V_89 ) ;
F_34 ( L_11 , V_85 -> V_43 . V_45 & V_87 ? L_12 : L_13 ) ;
if ( F_49 ( V_88 ) ) {
unsigned long V_45 ;
F_44 ( V_45 ) ;
V_73 = F_50 ( V_88 , V_99 ) ;
V_83 = V_2 -> V_5 -> V_100 ( V_72 , V_73 + V_89 ,
V_118 , V_75 ) ;
F_51 ( V_73 , V_99 ) ;
F_45 ( V_45 ) ;
} else {
V_73 = F_52 ( V_88 ) ;
V_83 = V_2 -> V_5 -> V_100 ( V_72 , V_73 + V_89 ,
V_118 , V_75 ) ;
}
V_111 -= F_58 ( V_111 , V_83 ) ;
V_85 -> V_90 += V_118 ;
V_85 -> V_96 += V_118 ;
if ( V_85 -> V_96 == V_117 -> V_101 ) {
V_85 -> V_95 = F_55 ( V_85 -> V_95 ) ;
V_85 -> V_96 = 0 ;
}
if ( V_111 )
goto V_119;
return 0 ;
}
static void F_63 ( struct V_84 * V_85 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
struct V_71 * V_72 = V_85 -> V_72 ;
struct V_113 * V_114 = & V_72 -> V_21 -> V_115 ;
unsigned int V_120 , V_121 , V_122 , V_111 ;
int V_123 , V_86 = ( V_85 -> V_43 . V_45 & V_87 ) ? 1 : 0 ;
V_2 -> V_5 -> V_124 ( V_2 , & V_85 -> V_125 ) ;
V_120 = V_85 -> V_125 . V_59 ;
V_121 = V_85 -> V_125 . V_61 ;
V_122 = V_85 -> V_125 . V_62 ;
V_111 = ( V_122 << 8 ) | V_121 ;
if ( F_39 ( V_120 & ( 1 << 0 ) ) )
goto V_126;
V_123 = ( ( V_120 & ( 1 << 1 ) ) == 0 ) ? 1 : 0 ;
if ( F_39 ( V_86 != V_123 ) )
goto V_126;
if ( F_39 ( ! V_111 ) )
goto V_126;
F_30 ( L_17 , V_2 -> V_67 , V_111 ) ;
if ( F_39 ( F_61 ( V_85 , V_111 ) ) )
goto V_127;
F_5 ( V_2 ) ;
return;
V_126:
F_62 ( V_114 , L_18 ,
V_120 , V_111 ) ;
V_127:
V_85 -> V_128 |= V_129 ;
V_2 -> V_93 = V_130 ;
}
static inline int F_64 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
if ( V_85 -> V_43 . V_45 & V_131 )
return 1 ;
if ( V_2 -> V_93 == V_132 ) {
if ( V_85 -> V_43 . V_105 == V_133 &&
( V_85 -> V_43 . V_45 & V_87 ) )
return 1 ;
if ( F_65 ( V_85 -> V_43 . V_105 ) &&
! ( V_85 -> V_72 -> V_45 & V_134 ) )
return 1 ;
}
return 0 ;
}
static void F_66 ( struct V_84 * V_85 , int V_135 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
unsigned long V_45 ;
if ( V_2 -> V_5 -> V_136 ) {
if ( V_135 ) {
F_67 ( V_2 -> V_137 , V_45 ) ;
V_85 = F_68 ( V_2 , V_85 -> V_138 ) ;
if ( V_85 ) {
if ( F_32 ( ! ( V_85 -> V_128 & V_129 ) ) ) {
F_27 ( V_2 ) ;
F_69 ( V_85 ) ;
} else
F_70 ( V_2 ) ;
}
F_71 ( V_2 -> V_137 , V_45 ) ;
} else {
if ( F_32 ( ! ( V_85 -> V_128 & V_129 ) ) )
F_69 ( V_85 ) ;
else
F_70 ( V_2 ) ;
}
} else {
if ( V_135 ) {
F_67 ( V_2 -> V_137 , V_45 ) ;
F_27 ( V_2 ) ;
F_69 ( V_85 ) ;
F_71 ( V_2 -> V_137 , V_45 ) ;
} else
F_69 ( V_85 ) ;
}
}
int F_72 ( struct V_1 * V_2 , struct V_84 * V_85 ,
T_1 V_8 , int V_135 )
{
struct V_20 * V_21 = V_85 -> V_72 -> V_21 ;
struct V_113 * V_114 = & V_21 -> V_115 ;
unsigned long V_45 = 0 ;
int V_139 ;
F_29 ( ( V_85 -> V_45 & V_140 ) == 0 ) ;
F_29 ( V_135 != F_64 ( V_2 , V_85 ) ) ;
V_141:
F_34 ( L_19 ,
V_2 -> V_67 , V_85 -> V_43 . V_105 , V_2 -> V_93 , V_8 ) ;
switch ( V_2 -> V_93 ) {
case V_132 :
V_139 = ( V_85 -> V_43 . V_45 & V_131 ) ;
if ( F_39 ( ( V_8 & V_142 ) == 0 ) ) {
if ( F_32 ( V_8 & ( V_143 | V_144 ) ) )
V_85 -> V_128 |= V_145 ;
else {
F_62 ( V_114 ,
L_20 ) ;
V_85 -> V_128 |= V_129 ;
}
V_2 -> V_93 = V_130 ;
goto V_141;
}
if ( F_39 ( V_8 & ( V_143 | V_144 ) ) ) {
if ( ! ( V_85 -> V_72 -> V_146 & V_147 ) ) {
F_62 ( V_114 , L_21
L_22
L_23 , V_8 ) ;
V_85 -> V_128 |= V_129 ;
V_2 -> V_93 = V_130 ;
goto V_141;
}
}
if ( V_135 )
F_67 ( V_2 -> V_137 , V_45 ) ;
if ( V_85 -> V_43 . V_105 == V_133 ) {
V_2 -> V_93 = V_107 ;
F_56 ( V_85 ) ;
} else
F_59 ( V_2 , V_85 ) ;
if ( V_135 )
F_71 ( V_2 -> V_137 , V_45 ) ;
break;
case V_107 :
if ( V_85 -> V_43 . V_105 == V_106 ) {
if ( ( V_8 & V_142 ) == 0 ) {
V_2 -> V_93 = V_94 ;
goto V_141;
}
if ( F_39 ( V_8 & ( V_143 | V_144 ) ) ) {
F_62 ( V_114 , L_24
L_22
L_23 , V_8 ) ;
V_85 -> V_128 |= V_129 ;
V_2 -> V_93 = V_130 ;
goto V_141;
}
F_63 ( V_85 ) ;
if ( F_39 ( V_2 -> V_93 == V_130 ) )
goto V_141;
} else {
if ( F_39 ( ( V_8 & V_142 ) == 0 ) ) {
if ( F_32 ( V_8 & ( V_143 | V_144 ) ) ) {
V_85 -> V_128 |= V_145 ;
if ( V_85 -> V_72 -> V_146 &
V_148 )
V_85 -> V_128 |=
V_149 ;
} else {
F_62 ( V_114 , L_25
L_26
L_23 , V_8 ) ;
V_85 -> V_128 |= V_129 |
V_149 ;
}
V_2 -> V_93 = V_130 ;
goto V_141;
}
if ( F_39 ( V_8 & ( V_143 | V_144 ) ) ) {
V_85 -> V_128 |= V_145 ;
if ( ! ( V_85 -> V_43 . V_45 & V_87 ) ) {
F_56 ( V_85 ) ;
V_8 = F_26 ( V_2 ) ;
}
if ( V_8 & ( V_9 | V_142 ) ) {
F_62 ( V_114 , L_25
L_27
L_23 , V_8 ) ;
V_85 -> V_128 |= V_129 ;
}
if ( V_8 == 0x7f )
V_85 -> V_128 |= V_149 ;
V_2 -> V_93 = V_130 ;
goto V_141;
}
F_56 ( V_85 ) ;
if ( V_2 -> V_93 == V_94 &&
( ! ( V_85 -> V_43 . V_45 & V_87 ) ) ) {
V_8 = F_26 ( V_2 ) ;
goto V_141;
}
}
V_139 = 1 ;
break;
case V_94 :
if ( F_39 ( ! F_73 ( V_8 ) ) ) {
V_85 -> V_128 |= F_74 ( V_8 ) ;
V_2 -> V_93 = V_130 ;
goto V_141;
}
F_34 ( L_28 ,
V_2 -> V_67 , V_85 -> V_72 -> V_150 , V_8 ) ;
F_29 ( V_85 -> V_128 & ( V_145 | V_129 ) ) ;
V_2 -> V_93 = V_151 ;
F_66 ( V_85 , V_135 ) ;
V_139 = 0 ;
break;
case V_130 :
V_2 -> V_93 = V_151 ;
F_66 ( V_85 , V_135 ) ;
V_139 = 0 ;
break;
default:
V_139 = 0 ;
F_9 () ;
}
return V_139 ;
}
void F_75 ( struct V_152 * V_153 )
{
F_76 ( V_154 , V_153 ) ;
}
void F_77 ( struct V_155 * V_156 , unsigned long V_157 )
{
F_78 ( V_154 , V_156 , V_157 ) ;
}
void F_79 ( struct V_20 * V_21 , unsigned long V_157 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
F_80 ( ( V_2 -> V_158 != NULL ) &&
( V_2 -> V_158 != V_21 ) ) ;
V_2 -> V_158 = V_21 ;
F_77 ( & V_2 -> V_159 , F_81 ( V_157 ) ) ;
}
void F_82 ( struct V_1 * V_2 )
{
F_34 ( L_29 ) ;
F_83 ( & V_2 -> V_159 ) ;
V_2 -> V_93 = V_151 ;
if ( F_84 ( V_2 ) )
F_15 ( V_2 , V_160 , L_30 , V_161 ) ;
}
static void F_85 ( struct V_152 * V_153 )
{
struct V_1 * V_2 =
F_86 ( V_153 , struct V_1 , V_159 . V_153 ) ;
struct V_20 * V_21 = V_2 -> V_158 ;
struct V_84 * V_85 ;
T_1 V_8 ;
int V_139 ;
F_87 ( V_2 -> V_158 == NULL ) ;
V_85 = F_68 ( V_2 , V_21 -> V_162 ) ;
if ( ! V_85 ) {
V_2 -> V_158 = NULL ;
return;
}
V_141:
F_29 ( V_2 -> V_93 == V_151 ) ;
V_8 = F_11 ( V_2 , V_9 , 5 ) ;
if ( V_8 & V_9 ) {
F_14 ( V_2 , 2 ) ;
V_8 = F_11 ( V_2 , V_9 , 10 ) ;
if ( V_8 & V_9 ) {
F_79 ( V_21 , V_163 ) ;
return;
}
}
V_2 -> V_158 = NULL ;
V_139 = F_72 ( V_2 , V_85 , V_8 , 1 ) ;
if ( V_139 )
goto V_141;
}
unsigned int F_88 ( struct V_84 * V_85 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
struct V_20 * V_21 = V_85 -> V_72 -> V_21 ;
if ( V_2 -> V_45 & V_164 )
V_85 -> V_43 . V_45 |= V_131 ;
F_24 ( V_2 , V_85 -> V_72 -> V_150 , 1 , 0 ) ;
switch ( V_85 -> V_43 . V_105 ) {
case V_165 :
if ( V_85 -> V_43 . V_45 & V_131 )
F_89 ( V_85 ) ;
F_35 ( V_2 , & V_85 -> V_43 ) ;
V_2 -> V_93 = V_94 ;
if ( V_85 -> V_43 . V_45 & V_131 )
F_79 ( V_21 , 0 ) ;
break;
case V_133 :
if ( V_85 -> V_43 . V_45 & V_131 )
F_89 ( V_85 ) ;
F_35 ( V_2 , & V_85 -> V_43 ) ;
if ( V_85 -> V_43 . V_45 & V_87 ) {
V_2 -> V_93 = V_132 ;
F_79 ( V_21 , 0 ) ;
} else {
V_2 -> V_93 = V_107 ;
if ( V_85 -> V_43 . V_45 & V_131 )
F_79 ( V_21 , 0 ) ;
}
break;
case V_106 :
case V_108 :
if ( V_85 -> V_43 . V_45 & V_131 )
F_89 ( V_85 ) ;
F_35 ( V_2 , & V_85 -> V_43 ) ;
V_2 -> V_93 = V_132 ;
if ( ( ! ( V_85 -> V_72 -> V_45 & V_134 ) ) ||
( V_85 -> V_43 . V_45 & V_131 ) )
F_79 ( V_21 , 0 ) ;
break;
default:
F_29 ( 1 ) ;
return V_166 ;
}
return 0 ;
}
bool F_90 ( struct V_84 * V_85 )
{
V_85 -> V_2 -> V_5 -> V_124 ( V_85 -> V_2 , & V_85 -> V_125 ) ;
return true ;
}
static unsigned int F_91 ( struct V_1 * V_2 )
{
V_2 -> V_167 . V_168 ++ ;
#ifdef F_92
if ( ( V_2 -> V_167 . V_168 % 1000 ) == 0 ) {
V_2 -> V_5 -> V_10 ( V_2 ) ;
if ( V_2 -> V_5 -> V_41 )
V_2 -> V_5 -> V_41 ( V_2 ) ;
F_15 ( V_2 , V_16 , L_31 ) ;
return 1 ;
}
#endif
return 0 ;
}
static unsigned int F_93 ( struct V_1 * V_2 ,
struct V_84 * V_85 ,
bool V_169 )
{
T_1 V_8 ;
F_30 ( L_32 ,
V_2 -> V_67 , V_85 -> V_43 . V_105 , V_2 -> V_93 ) ;
switch ( V_2 -> V_93 ) {
case V_132 :
if ( ! ( V_85 -> V_72 -> V_45 & V_134 ) )
return F_91 ( V_2 ) ;
break;
case V_151 :
return F_91 ( V_2 ) ;
default:
break;
}
V_8 = F_4 ( V_2 ) ;
if ( V_8 & V_9 ) {
if ( V_169 ) {
V_85 -> V_128 |= V_129 ;
V_2 -> V_93 = V_130 ;
} else
return F_91 ( V_2 ) ;
}
if ( V_2 -> V_5 -> V_41 )
V_2 -> V_5 -> V_41 ( V_2 ) ;
F_72 ( V_2 , V_85 , V_8 , 0 ) ;
return 1 ;
}
unsigned int F_94 ( struct V_1 * V_2 , struct V_84 * V_85 )
{
return F_93 ( V_2 , V_85 , false ) ;
}
T_3 F_95 ( int V_170 , void * V_171 )
{
return F_96 ( V_170 , V_171 , F_94 ) ;
}
void F_97 ( struct V_1 * V_2 )
{
T_1 V_8 ;
struct V_84 * V_85 ;
V_85 = F_68 ( V_2 , V_2 -> V_21 . V_162 ) ;
if ( ! V_85 || V_85 -> V_43 . V_45 & V_131 )
return;
V_8 = F_3 ( V_2 ) ;
if ( V_8 & V_9 )
return;
F_15 ( V_2 , V_16 , L_33 ,
V_8 ) ;
F_94 ( V_2 , V_85 ) ;
}
void F_98 ( struct V_1 * V_2 )
{
V_2 -> V_23 |= V_39 ;
V_2 -> V_40 = V_2 -> V_23 ;
if ( V_2 -> V_5 -> V_24 || V_2 -> V_3 . V_25 )
F_21 ( V_2 , V_2 -> V_23 ) ;
V_2 -> V_5 -> V_10 ( V_2 ) ;
if ( V_2 -> V_5 -> V_41 )
V_2 -> V_5 -> V_41 ( V_2 ) ;
}
void F_99 ( struct V_1 * V_2 )
{
V_2 -> V_5 -> V_10 ( V_2 ) ;
if ( V_2 -> V_5 -> V_41 )
V_2 -> V_5 -> V_41 ( V_2 ) ;
F_27 ( V_2 ) ;
}
int F_100 ( struct V_20 * V_21 , unsigned long V_22 )
{
struct V_172 * V_173 = & V_21 -> V_174 ;
int V_175 ;
V_175 = F_101 ( V_21 , V_22 ) ;
if ( V_175 )
return V_175 ;
if ( V_173 -> V_176 . V_177 & V_178 )
return 0 ;
if ( ! F_102 ( V_21 ) ) {
V_175 = F_19 ( V_21 , V_22 ) ;
if ( V_175 && V_175 != - V_17 ) {
F_103 ( V_21 , V_16 , L_34
L_35 , V_175 ) ;
V_173 -> V_176 . V_177 |= V_178 ;
}
}
return 0 ;
}
static unsigned int F_104 ( struct V_1 * V_2 , unsigned int V_26 )
{
struct V_37 * V_3 = & V_2 -> V_3 ;
T_1 V_59 , V_60 ;
V_2 -> V_5 -> V_34 ( V_2 , V_26 ) ;
F_22 ( 0x55 , V_3 -> V_51 ) ;
F_22 ( 0xaa , V_3 -> V_53 ) ;
F_22 ( 0xaa , V_3 -> V_51 ) ;
F_22 ( 0x55 , V_3 -> V_53 ) ;
F_22 ( 0x55 , V_3 -> V_51 ) ;
F_22 ( 0xaa , V_3 -> V_53 ) ;
V_59 = F_2 ( V_3 -> V_51 ) ;
V_60 = F_2 ( V_3 -> V_53 ) ;
if ( ( V_59 == 0x55 ) && ( V_60 == 0xaa ) )
return 1 ;
return 0 ;
}
unsigned int F_105 ( struct V_71 * V_72 , int V_179 ,
T_1 * V_180 )
{
struct V_1 * V_2 = V_72 -> V_21 -> V_2 ;
struct V_42 V_43 ;
unsigned int V_35 ;
T_1 V_181 ;
V_2 -> V_5 -> V_34 ( V_2 , V_72 -> V_150 ) ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_2 -> V_5 -> V_124 ( V_2 , & V_43 ) ;
V_181 = V_43 . V_58 ;
if ( V_180 )
* V_180 = V_181 ;
if ( V_181 == 0 )
V_72 -> V_146 |= V_148 ;
else if ( V_181 == 1 )
;
else if ( ( V_72 -> V_150 == 0 ) && ( V_181 == 0x81 ) )
;
else
return V_182 ;
V_35 = F_106 ( & V_43 ) ;
if ( V_35 == V_183 ) {
if ( V_179 && ( V_72 -> V_146 & V_148 ) )
V_35 = V_184 ;
else
V_35 = V_182 ;
} else if ( ( V_35 == V_184 ) &&
( V_2 -> V_5 -> V_10 ( V_2 ) == 0 ) )
V_35 = V_182 ;
return V_35 ;
}
int F_107 ( struct V_20 * V_21 , unsigned int V_185 ,
unsigned long V_22 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_37 * V_3 = & V_2 -> V_3 ;
unsigned int V_186 = V_185 & ( 1 << 0 ) ;
unsigned int V_187 = V_185 & ( 1 << 1 ) ;
int V_175 , V_188 = 0 ;
F_14 ( V_2 , V_189 ) ;
V_175 = F_19 ( V_21 , V_22 ) ;
if ( V_175 )
return V_175 ;
if ( V_187 ) {
int V_176 ;
V_2 -> V_5 -> V_34 ( V_2 , 1 ) ;
for ( V_176 = 0 ; V_176 < 2 ; V_176 ++ ) {
T_1 V_59 , V_60 ;
V_59 = F_2 ( V_3 -> V_51 ) ;
V_60 = F_2 ( V_3 -> V_53 ) ;
if ( ( V_59 == 1 ) && ( V_60 == 1 ) )
break;
F_14 ( V_2 , 50 ) ;
}
V_175 = F_19 ( V_21 , V_22 ) ;
if ( V_175 ) {
if ( V_175 != - V_17 )
return V_175 ;
V_188 = V_175 ;
}
}
V_2 -> V_5 -> V_34 ( V_2 , 0 ) ;
if ( V_187 )
V_2 -> V_5 -> V_34 ( V_2 , 1 ) ;
if ( V_186 )
V_2 -> V_5 -> V_34 ( V_2 , 0 ) ;
return V_188 ;
}
static int F_108 ( struct V_1 * V_2 , unsigned int V_185 ,
unsigned long V_22 )
{
struct V_37 * V_3 = & V_2 -> V_3 ;
F_34 ( L_36 , V_2 -> V_67 ) ;
F_22 ( V_2 -> V_23 , V_3 -> V_25 ) ;
F_109 ( 20 ) ;
F_22 ( V_2 -> V_23 | V_190 , V_3 -> V_25 ) ;
F_109 ( 20 ) ;
F_22 ( V_2 -> V_23 , V_3 -> V_25 ) ;
V_2 -> V_40 = V_2 -> V_23 ;
return F_107 ( & V_2 -> V_21 , V_185 , V_22 ) ;
}
int F_110 ( struct V_20 * V_21 , unsigned int * V_191 ,
unsigned long V_22 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
unsigned int V_192 = V_2 -> V_45 & V_193 ;
unsigned int V_185 = 0 ;
int V_175 ;
T_1 V_181 ;
F_34 ( L_29 ) ;
if ( F_104 ( V_2 , 0 ) )
V_185 |= ( 1 << 0 ) ;
if ( V_192 && F_104 ( V_2 , 1 ) )
V_185 |= ( 1 << 1 ) ;
V_2 -> V_5 -> V_34 ( V_2 , 0 ) ;
F_34 ( L_37 , V_185 ) ;
V_175 = F_108 ( V_2 , V_185 , V_22 ) ;
if ( V_175 && ( V_175 != - V_17 || F_111 ( V_21 ) ) ) {
F_103 ( V_21 , V_18 , L_38 , V_175 ) ;
return V_175 ;
}
V_191 [ 0 ] = F_105 ( & V_21 -> V_26 [ 0 ] ,
V_185 & ( 1 << 0 ) , & V_181 ) ;
if ( V_192 && V_181 != 0x81 )
V_191 [ 1 ] = F_105 ( & V_21 -> V_26 [ 1 ] ,
V_185 & ( 1 << 1 ) , & V_181 ) ;
F_34 ( L_39 , V_191 [ 0 ] , V_191 [ 1 ] ) ;
return 0 ;
}
int F_112 ( struct V_20 * V_21 , unsigned int * V_35 ,
unsigned long V_22 )
{
struct V_172 * V_173 = & V_21 -> V_174 ;
const unsigned long * V_194 = F_113 ( V_173 ) ;
bool V_195 ;
int V_175 ;
V_175 = F_114 ( V_21 , V_194 , V_22 , & V_195 ,
F_17 ) ;
if ( V_195 )
* V_35 = F_105 ( V_21 -> V_26 , 1 , NULL ) ;
F_34 ( L_40 , * V_35 ) ;
return V_175 ;
}
void F_115 ( struct V_20 * V_21 , unsigned int * V_191 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
F_116 ( V_21 , V_191 ) ;
if ( V_191 [ 0 ] != V_182 )
V_2 -> V_5 -> V_34 ( V_2 , 1 ) ;
if ( V_191 [ 1 ] != V_182 )
V_2 -> V_5 -> V_34 ( V_2 , 0 ) ;
if ( V_191 [ 0 ] == V_182 && V_191 [ 1 ] == V_182 ) {
F_34 ( L_41 ) ;
return;
}
if ( V_2 -> V_5 -> V_24 || V_2 -> V_3 . V_25 ) {
F_21 ( V_2 , V_2 -> V_23 ) ;
V_2 -> V_40 = V_2 -> V_23 ;
}
}
void F_117 ( struct V_84 * V_85 )
{
int V_118 ;
struct V_1 * V_2 ;
if ( V_85 == NULL || V_85 -> V_196 == V_197 )
return;
V_2 = V_85 -> V_2 ;
for ( V_118 = 0 ; ( V_2 -> V_5 -> V_10 ( V_2 ) & V_142 )
&& V_118 < 65536 ; V_118 += 2 )
F_118 ( V_2 -> V_3 . V_76 ) ;
if ( V_118 )
F_15 ( V_2 , V_160 ,
L_42 , V_118 ) ;
}
void F_119 ( struct V_1 * V_2 )
{
T_4 V_198 = V_2 -> V_5 -> V_198 ;
T_4 V_199 = V_2 -> V_5 -> V_199 ;
struct V_84 * V_85 ;
unsigned long V_45 ;
V_85 = F_120 ( V_2 , V_2 -> V_21 . V_162 ) ;
if ( V_85 && ! ( V_85 -> V_45 & V_200 ) )
V_85 = NULL ;
F_67 ( V_2 -> V_137 , V_45 ) ;
if ( V_2 -> V_5 -> V_201 )
V_2 -> V_5 -> V_201 ( V_85 ) ;
F_71 ( V_2 -> V_137 , V_45 ) ;
if ( V_198 == F_110 && ! V_2 -> V_3 . V_25 )
V_198 = NULL ;
if ( ( V_199 == V_202 ||
V_199 == F_112 ) && ! F_111 ( & V_2 -> V_21 ) )
V_199 = NULL ;
F_121 ( V_2 , V_2 -> V_5 -> V_203 , V_198 , V_199 ,
V_2 -> V_5 -> V_204 ) ;
}
void F_122 ( struct V_37 * V_3 )
{
V_3 -> V_76 = V_3 -> V_205 + V_206 ;
V_3 -> V_65 = V_3 -> V_205 + V_207 ;
V_3 -> V_49 = V_3 -> V_205 + V_208 ;
V_3 -> V_51 = V_3 -> V_205 + V_209 ;
V_3 -> V_53 = V_3 -> V_205 + V_210 ;
V_3 -> V_55 = V_3 -> V_205 + V_211 ;
V_3 -> V_57 = V_3 -> V_205 + V_212 ;
V_3 -> V_30 = V_3 -> V_205 + V_213 ;
V_3 -> V_4 = V_3 -> V_205 + V_214 ;
V_3 -> V_68 = V_3 -> V_205 + V_215 ;
}
static int F_123 ( struct V_216 * V_217 , int V_218 )
{
int V_176 ;
V_218 = V_218 * 2 ;
for ( V_176 = 0 ; V_176 < 2 ; V_176 ++ ) {
if ( F_124 ( V_217 , V_218 + V_176 ) == 0 ||
F_125 ( V_217 , V_218 + V_176 ) == 0 )
return 0 ;
}
return 1 ;
}
int F_126 ( struct V_219 * V_220 )
{
struct V_26 * V_221 = V_220 -> V_72 ;
struct V_216 * V_217 = F_127 ( V_221 ) ;
unsigned int V_222 = 0 ;
int V_176 , V_175 ;
for ( V_176 = 0 ; V_176 < 2 ; V_176 ++ ) {
struct V_1 * V_2 = V_220 -> V_223 [ V_176 ] ;
int V_224 = V_176 * 2 ;
void T_2 * const * V_225 ;
if ( F_128 ( V_2 ) )
continue;
if ( ! F_123 ( V_217 , V_176 ) ) {
V_2 -> V_5 = & V_226 ;
continue;
}
V_175 = F_129 ( V_217 , 0x3 << V_224 ,
F_130 ( V_221 ) ) ;
if ( V_175 ) {
F_131 ( V_16 , V_221 ,
L_43
L_44 , V_176 , V_175 ) ;
if ( V_175 == - V_19 )
F_132 ( V_217 ) ;
V_2 -> V_5 = & V_226 ;
continue;
}
V_220 -> V_225 = V_225 = F_133 ( V_217 ) ;
V_2 -> V_3 . V_205 = V_225 [ V_224 ] ;
V_2 -> V_3 . V_7 =
V_2 -> V_3 . V_25 = ( void T_2 * )
( ( unsigned long ) V_225 [ V_224 + 1 ] | V_227 ) ;
F_122 ( & V_2 -> V_3 ) ;
F_134 ( V_2 , L_45 ,
( unsigned long long ) F_124 ( V_217 , V_224 ) ,
( unsigned long long ) F_124 ( V_217 , V_224 + 1 ) ) ;
V_222 |= 1 << V_176 ;
}
if ( ! V_222 ) {
F_131 ( V_18 , V_221 , L_46 ) ;
return - V_17 ;
}
return 0 ;
}
int F_135 ( struct V_216 * V_217 ,
const struct V_228 * const * V_229 ,
struct V_219 * * V_230 )
{
struct V_219 * V_220 ;
int V_175 ;
if ( ! F_136 ( & V_217 -> V_72 , NULL , V_231 ) )
return - V_232 ;
V_220 = F_137 ( & V_217 -> V_72 , V_229 , 2 ) ;
if ( ! V_220 ) {
F_131 ( V_18 , & V_217 -> V_72 ,
L_47 ) ;
V_175 = - V_232 ;
goto V_127;
}
V_175 = F_126 ( V_220 ) ;
if ( V_175 )
goto V_127;
F_138 ( & V_217 -> V_72 , NULL ) ;
* V_230 = V_220 ;
return 0 ;
V_127:
F_139 ( & V_217 -> V_72 , NULL ) ;
return V_175 ;
}
int F_140 ( struct V_219 * V_220 ,
T_5 V_233 ,
struct V_234 * V_235 )
{
struct V_26 * V_72 = V_220 -> V_72 ;
struct V_216 * V_217 = F_127 ( V_72 ) ;
const char * V_236 = F_130 ( V_220 -> V_72 ) ;
int V_237 = 0 , V_175 ;
V_175 = F_141 ( V_220 ) ;
if ( V_175 )
return V_175 ;
if ( ( V_217 -> V_35 >> 8 ) == V_238 ) {
T_1 V_239 , V_222 ;
F_142 ( V_217 , V_240 , & V_239 ) ;
V_222 = ( 1 << 2 ) | ( 1 << 0 ) ;
if ( ( V_239 & V_222 ) != V_222 )
V_237 = 1 ;
#if F_143 ( V_241 )
if ( V_237 ) {
F_144 ( V_18 L_48 ) ;
return - V_242 ;
}
#endif
}
if ( ! F_136 ( V_72 , NULL , V_231 ) )
return - V_232 ;
if ( ! V_237 && V_217 -> V_170 ) {
int V_176 ;
V_175 = F_145 ( V_72 , V_217 -> V_170 , V_233 ,
V_243 , V_236 , V_220 ) ;
if ( V_175 )
goto V_244;
for ( V_176 = 0 ; V_176 < 2 ; V_176 ++ ) {
if ( F_128 ( V_220 -> V_223 [ V_176 ] ) )
continue;
F_134 ( V_220 -> V_223 [ V_176 ] , L_49 , V_217 -> V_170 ) ;
}
} else if ( V_237 ) {
if ( ! F_128 ( V_220 -> V_223 [ 0 ] ) ) {
V_175 = F_145 ( V_72 , F_146 ( V_217 ) ,
V_233 , V_243 ,
V_236 , V_220 ) ;
if ( V_175 )
goto V_244;
F_134 ( V_220 -> V_223 [ 0 ] , L_49 ,
F_146 ( V_217 ) ) ;
}
if ( ! F_128 ( V_220 -> V_223 [ 1 ] ) ) {
V_175 = F_145 ( V_72 , F_147 ( V_217 ) ,
V_233 , V_243 ,
V_236 , V_220 ) ;
if ( V_175 )
goto V_244;
F_134 ( V_220 -> V_223 [ 1 ] , L_49 ,
F_147 ( V_217 ) ) ;
}
}
V_175 = F_148 ( V_220 , V_235 ) ;
V_244:
if ( V_175 == 0 )
F_138 ( V_72 , NULL ) ;
else
F_139 ( V_72 , NULL ) ;
return V_175 ;
}
static const struct V_228 * F_149 (
const struct V_228 * const * V_229 )
{
int V_176 ;
for ( V_176 = 0 ; V_176 < 2 && V_229 [ V_176 ] ; V_176 ++ )
if ( V_229 [ V_176 ] -> V_245 != & V_226 )
return V_229 [ V_176 ] ;
return NULL ;
}
int F_150 ( struct V_216 * V_217 ,
const struct V_228 * const * V_229 ,
struct V_234 * V_235 , void * V_246 , int V_247 )
{
struct V_26 * V_72 = & V_217 -> V_72 ;
const struct V_228 * V_248 ;
struct V_219 * V_220 = NULL ;
int V_175 ;
F_34 ( L_29 ) ;
V_248 = F_149 ( V_229 ) ;
if ( ! V_248 ) {
F_131 ( V_18 , & V_217 -> V_72 ,
L_50 ) ;
return - V_249 ;
}
if ( ! F_136 ( V_72 , NULL , V_231 ) )
return - V_232 ;
V_175 = F_151 ( V_217 ) ;
if ( V_175 )
goto V_244;
V_175 = F_135 ( V_217 , V_229 , & V_220 ) ;
if ( V_175 )
goto V_244;
V_220 -> V_250 = V_246 ;
V_220 -> V_45 |= V_247 ;
V_175 = F_140 ( V_220 , F_95 , V_235 ) ;
V_244:
if ( V_175 == 0 )
F_138 ( & V_217 -> V_72 , NULL ) ;
else
F_139 ( & V_217 -> V_72 , NULL ) ;
return V_175 ;
}
static void F_152 ( struct V_84 * V_85 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
struct V_251 * V_252 = V_2 -> V_253 ;
struct V_116 * V_117 ;
unsigned int V_254 , V_248 ;
V_248 = 0 ;
F_153 (qc->sg, sg, qc->n_elem, si) {
T_6 V_255 , V_89 ;
T_6 V_256 , V_257 ;
V_255 = ( T_6 ) F_154 ( V_117 ) ;
V_256 = F_155 ( V_117 ) ;
while ( V_256 ) {
V_89 = V_255 & 0xffff ;
V_257 = V_256 ;
if ( ( V_89 + V_256 ) > 0x10000 )
V_257 = 0x10000 - V_89 ;
V_252 [ V_248 ] . V_255 = F_156 ( V_255 ) ;
V_252 [ V_248 ] . V_258 = F_156 ( V_257 & 0xffff ) ;
F_30 ( L_51 , V_248 , V_255 , V_257 ) ;
V_248 ++ ;
V_256 -= V_257 ;
V_255 += V_257 ;
}
}
V_252 [ V_248 - 1 ] . V_258 |= F_156 ( V_259 ) ;
}
static void F_157 ( struct V_84 * V_85 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
struct V_251 * V_252 = V_2 -> V_253 ;
struct V_116 * V_117 ;
unsigned int V_254 , V_248 ;
V_248 = 0 ;
F_153 (qc->sg, sg, qc->n_elem, si) {
T_6 V_255 , V_89 ;
T_6 V_256 , V_257 , V_260 ;
V_255 = ( T_6 ) F_154 ( V_117 ) ;
V_256 = F_155 ( V_117 ) ;
while ( V_256 ) {
V_89 = V_255 & 0xffff ;
V_257 = V_256 ;
if ( ( V_89 + V_256 ) > 0x10000 )
V_257 = 0x10000 - V_89 ;
V_260 = V_257 & 0xffff ;
V_252 [ V_248 ] . V_255 = F_156 ( V_255 ) ;
if ( V_260 == 0 ) {
V_252 [ V_248 ] . V_258 = F_156 ( 0x8000 ) ;
V_260 = 0x8000 ;
V_252 [ ++ V_248 ] . V_255 = F_156 ( V_255 + 0x8000 ) ;
}
V_252 [ V_248 ] . V_258 = F_156 ( V_260 ) ;
F_30 ( L_51 , V_248 , V_255 , V_257 ) ;
V_248 ++ ;
V_256 -= V_257 ;
V_255 += V_257 ;
}
}
V_252 [ V_248 - 1 ] . V_258 |= F_156 ( V_259 ) ;
}
void F_158 ( struct V_84 * V_85 )
{
if ( ! ( V_85 -> V_45 & V_261 ) )
return;
F_152 ( V_85 ) ;
}
void F_159 ( struct V_84 * V_85 )
{
if ( ! ( V_85 -> V_45 & V_261 ) )
return;
F_157 ( V_85 ) ;
}
unsigned int F_160 ( struct V_84 * V_85 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
struct V_20 * V_21 = V_85 -> V_72 -> V_21 ;
if ( ! F_161 ( V_85 -> V_43 . V_105 ) )
return F_88 ( V_85 ) ;
F_24 ( V_2 , V_85 -> V_72 -> V_150 , 1 , 0 ) ;
switch ( V_85 -> V_43 . V_105 ) {
case V_262 :
F_29 ( V_85 -> V_43 . V_45 & V_131 ) ;
V_2 -> V_5 -> V_69 ( V_2 , & V_85 -> V_43 ) ;
V_2 -> V_5 -> V_263 ( V_85 ) ;
V_2 -> V_5 -> V_110 ( V_85 ) ;
V_2 -> V_93 = V_94 ;
break;
case V_109 :
F_29 ( V_85 -> V_43 . V_45 & V_131 ) ;
V_2 -> V_5 -> V_69 ( V_2 , & V_85 -> V_43 ) ;
V_2 -> V_5 -> V_263 ( V_85 ) ;
V_2 -> V_93 = V_132 ;
if ( ! ( V_85 -> V_72 -> V_45 & V_134 ) )
F_79 ( V_21 , 0 ) ;
break;
default:
F_80 ( 1 ) ;
return V_166 ;
}
return 0 ;
}
unsigned int F_162 ( struct V_1 * V_2 , struct V_84 * V_85 )
{
struct V_113 * V_114 = & V_2 -> V_21 . V_115 ;
T_1 V_264 = 0 ;
bool V_265 = false ;
unsigned int V_266 ;
if ( V_2 -> V_93 == V_94 && F_161 ( V_85 -> V_43 . V_105 ) ) {
V_264 = V_2 -> V_5 -> V_267 ( V_2 ) ;
F_30 ( L_52 , V_2 -> V_67 , V_264 ) ;
if ( ! ( V_264 & V_268 ) )
return F_91 ( V_2 ) ;
V_2 -> V_5 -> V_269 ( V_85 ) ;
V_265 = true ;
if ( F_39 ( V_264 & V_270 ) ) {
V_85 -> V_128 |= V_271 ;
V_2 -> V_93 = V_130 ;
}
}
V_266 = F_93 ( V_2 , V_85 , V_265 ) ;
if ( F_39 ( V_85 -> V_128 ) && F_161 ( V_85 -> V_43 . V_105 ) )
F_62 ( V_114 , L_53 , V_264 ) ;
return V_266 ;
}
T_3 F_163 ( int V_170 , void * V_171 )
{
return F_96 ( V_170 , V_171 , F_162 ) ;
}
void F_164 ( struct V_1 * V_2 )
{
struct V_84 * V_85 ;
unsigned long V_45 ;
bool V_272 = false ;
V_85 = F_120 ( V_2 , V_2 -> V_21 . V_162 ) ;
if ( V_85 && ! ( V_85 -> V_45 & V_200 ) )
V_85 = NULL ;
F_67 ( V_2 -> V_137 , V_45 ) ;
if ( V_85 && F_161 ( V_85 -> V_43 . V_105 ) ) {
T_1 V_264 ;
V_264 = V_2 -> V_5 -> V_267 ( V_2 ) ;
if ( V_85 -> V_128 == V_273 && ( V_264 & V_270 ) ) {
V_85 -> V_128 = V_271 ;
V_272 = true ;
}
V_2 -> V_5 -> V_269 ( V_85 ) ;
if ( V_272 ) {
V_2 -> V_5 -> V_10 ( V_2 ) ;
if ( V_2 -> V_5 -> V_41 )
V_2 -> V_5 -> V_41 ( V_2 ) ;
}
}
F_71 ( V_2 -> V_137 , V_45 ) ;
if ( V_272 )
F_165 ( V_2 ) ;
F_119 ( V_2 ) ;
}
void F_166 ( struct V_84 * V_85 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
unsigned long V_45 ;
if ( F_161 ( V_85 -> V_43 . V_105 ) ) {
F_67 ( V_2 -> V_137 , V_45 ) ;
V_2 -> V_5 -> V_269 ( V_85 ) ;
F_71 ( V_2 -> V_137 , V_45 ) ;
}
}
void F_167 ( struct V_1 * V_2 )
{
void T_2 * V_274 = V_2 -> V_3 . V_275 ;
if ( ! V_274 )
return;
F_22 ( F_2 ( V_274 + V_276 ) , V_274 + V_276 ) ;
}
void F_168 ( struct V_84 * V_85 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
unsigned int V_75 = ( V_85 -> V_43 . V_45 & V_87 ) ;
T_1 V_277 ;
F_169 () ;
F_170 ( V_2 -> V_278 , V_2 -> V_3 . V_275 + V_279 ) ;
V_277 = F_2 ( V_2 -> V_3 . V_275 + V_280 ) ;
V_277 &= ~ ( V_281 | V_282 ) ;
if ( ! V_75 )
V_277 |= V_281 ;
F_22 ( V_277 , V_2 -> V_3 . V_275 + V_280 ) ;
V_2 -> V_5 -> V_70 ( V_2 , & V_85 -> V_43 ) ;
}
void F_171 ( struct V_84 * V_85 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
T_1 V_277 ;
V_277 = F_2 ( V_2 -> V_3 . V_275 + V_280 ) ;
F_22 ( V_277 | V_282 , V_2 -> V_3 . V_275 + V_280 ) ;
}
void F_172 ( struct V_84 * V_85 )
{
struct V_1 * V_2 = V_85 -> V_2 ;
void T_2 * V_274 = V_2 -> V_3 . V_275 ;
F_22 ( F_2 ( V_274 + V_280 ) & ~ V_282 ,
V_274 + V_280 ) ;
F_8 ( V_2 ) ;
}
T_1 F_173 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 . V_275 + V_276 ) ;
}
int F_174 ( struct V_1 * V_2 )
{
if ( V_2 -> V_283 || V_2 -> V_284 ) {
V_2 -> V_253 =
F_175 ( V_2 -> V_220 -> V_72 , V_285 ,
& V_2 -> V_278 , V_231 ) ;
if ( ! V_2 -> V_253 )
return - V_232 ;
}
return 0 ;
}
int F_176 ( struct V_1 * V_2 )
{
V_2 -> V_81 |= V_82 | V_286 ;
return F_174 ( V_2 ) ;
}
int F_177 ( struct V_216 * V_217 )
{
unsigned long V_287 = F_124 ( V_217 , 4 ) ;
T_1 V_288 ;
if ( V_287 == 0 )
return - V_289 ;
V_288 = F_178 ( V_287 + 0x02 ) ;
F_179 ( V_288 & 0x60 , V_287 + 0x02 ) ;
V_288 = F_178 ( V_287 + 0x02 ) ;
if ( V_288 & 0x80 )
return - V_242 ;
return 0 ;
}
static void F_180 ( struct V_219 * V_220 , const char * V_290 )
{
int V_176 ;
F_131 ( V_18 , V_220 -> V_72 , L_54 ,
V_290 ) ;
for ( V_176 = 0 ; V_176 < 2 ; V_176 ++ ) {
V_220 -> V_223 [ V_176 ] -> V_283 = 0 ;
V_220 -> V_223 [ V_176 ] -> V_284 = 0 ;
}
}
void F_181 ( struct V_219 * V_220 )
{
struct V_26 * V_221 = V_220 -> V_72 ;
struct V_216 * V_217 = F_127 ( V_221 ) ;
int V_176 , V_175 ;
if ( F_124 ( V_217 , 4 ) == 0 ) {
F_180 ( V_220 , L_55 ) ;
return;
}
V_175 = F_182 ( V_217 , V_291 ) ;
if ( V_175 )
F_180 ( V_220 , L_56 ) ;
if ( ! V_175 ) {
V_175 = F_183 ( V_217 , V_291 ) ;
if ( V_175 )
F_180 ( V_220 ,
L_57 ) ;
}
V_175 = F_129 ( V_217 , 1 << 4 , F_130 ( V_221 ) ) ;
if ( V_175 ) {
F_180 ( V_220 , L_58 ) ;
return;
}
V_220 -> V_225 = F_133 ( V_217 ) ;
for ( V_176 = 0 ; V_176 < 2 ; V_176 ++ ) {
struct V_1 * V_2 = V_220 -> V_223 [ V_176 ] ;
void T_2 * V_287 = V_220 -> V_225 [ 4 ] + 8 * V_176 ;
if ( F_128 ( V_2 ) )
continue;
V_2 -> V_3 . V_275 = V_287 ;
if ( ( ! ( V_2 -> V_45 & V_292 ) ) &&
( F_2 ( V_287 + 2 ) & 0x80 ) )
V_220 -> V_45 |= V_293 ;
F_134 ( V_2 , L_59 ,
( unsigned long long ) F_124 ( V_217 , 4 ) + 8 * V_176 ) ;
}
}
int F_184 ( struct V_216 * V_217 ,
const struct V_228 * const * V_229 ,
struct V_219 * * V_230 )
{
int V_175 ;
V_175 = F_135 ( V_217 , V_229 , V_230 ) ;
if ( V_175 )
return V_175 ;
F_181 ( * V_230 ) ;
return 0 ;
}
int F_185 ( struct V_216 * V_217 ,
const struct V_228 * const * V_229 ,
struct V_234 * V_235 , void * V_246 ,
int V_294 )
{
struct V_26 * V_72 = & V_217 -> V_72 ;
const struct V_228 * V_248 ;
struct V_219 * V_220 = NULL ;
int V_175 ;
F_34 ( L_29 ) ;
V_248 = F_149 ( V_229 ) ;
if ( ! V_248 ) {
F_131 ( V_18 , & V_217 -> V_72 ,
L_50 ) ;
return - V_249 ;
}
if ( ! F_136 ( V_72 , NULL , V_231 ) )
return - V_232 ;
V_175 = F_151 ( V_217 ) ;
if ( V_175 )
goto V_244;
V_175 = F_184 ( V_217 , V_229 , & V_220 ) ;
if ( V_175 )
goto V_244;
V_220 -> V_250 = V_246 ;
V_220 -> V_45 |= V_294 ;
F_186 ( V_217 ) ;
V_175 = F_140 ( V_220 , F_163 , V_235 ) ;
V_244:
if ( V_175 == 0 )
F_138 ( & V_217 -> V_72 , NULL ) ;
else
F_139 ( & V_217 -> V_72 , NULL ) ;
return V_175 ;
}
void F_187 ( struct V_1 * V_2 )
{
F_188 ( & V_2 -> V_159 , F_85 ) ;
V_2 -> V_23 = V_295 ;
V_2 -> V_40 = 0xFF ;
}
int T_7 F_189 ( void )
{
V_154 = F_190 ( L_60 , V_296 , V_297 ) ;
if ( ! V_154 )
return - V_232 ;
return 0 ;
}
void F_191 ( void )
{
F_192 ( V_154 ) ;
}
