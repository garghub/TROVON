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
F_15 ( V_2 ,
L_1 ,
V_8 ) ;
V_14 = F_12 ( V_13 , V_12 ) ;
while ( V_8 != 0xff && ( V_8 & V_9 ) &&
F_13 ( V_15 , V_14 ) ) {
F_14 ( V_2 , 50 ) ;
V_8 = V_2 -> V_5 -> V_10 ( V_2 ) ;
}
if ( V_8 == 0xff )
return - V_16 ;
if ( V_8 & V_9 ) {
F_16 ( V_2 ,
L_2 ,
F_17 ( V_12 , 1000 ) , V_8 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_18 ( struct V_18 * V_19 )
{
T_1 V_8 = V_19 -> V_2 -> V_5 -> V_10 ( V_19 -> V_2 ) ;
return F_19 ( V_8 ) ;
}
int F_20 ( struct V_18 * V_19 , unsigned long V_20 )
{
return F_21 ( V_19 , V_20 , F_18 ) ;
}
static void F_22 ( struct V_1 * V_2 , T_1 V_21 )
{
if ( V_2 -> V_5 -> V_22 )
V_2 -> V_5 -> V_22 ( V_2 , V_21 ) ;
else
F_23 ( V_21 , V_2 -> V_3 . V_23 ) ;
}
void F_24 ( struct V_1 * V_2 , unsigned int V_24 )
{
T_1 V_25 ;
if ( V_24 == 0 )
V_25 = V_26 ;
else
V_25 = V_26 | V_27 ;
F_23 ( V_25 , V_2 -> V_3 . V_28 ) ;
F_6 ( V_2 ) ;
}
static void F_25 ( struct V_1 * V_2 , unsigned int V_24 ,
unsigned int V_29 , unsigned int V_30 )
{
if ( F_26 ( V_2 ) )
F_27 ( V_2 , L_3 ,
V_24 , V_29 ) ;
if ( V_29 )
F_28 ( V_2 ) ;
V_2 -> V_5 -> V_31 ( V_2 , V_24 ) ;
if ( V_29 ) {
if ( V_30 && V_2 -> V_19 . V_24 [ V_24 ] . V_32 == V_33 )
F_14 ( V_2 , 150 ) ;
F_28 ( V_2 ) ;
}
}
void F_29 ( struct V_1 * V_2 )
{
struct V_34 * V_3 = & V_2 -> V_3 ;
if ( V_2 -> V_5 -> V_35 ) {
V_2 -> V_5 -> V_35 ( V_2 ) ;
return;
}
V_2 -> V_21 &= ~ V_36 ;
V_2 -> V_37 = V_2 -> V_21 ;
if ( V_2 -> V_5 -> V_22 || V_3 -> V_23 )
F_22 ( V_2 , V_2 -> V_21 ) ;
F_28 ( V_2 ) ;
if ( V_2 -> V_5 -> V_38 )
V_2 -> V_5 -> V_38 ( V_2 ) ;
}
void F_30 ( struct V_1 * V_2 , const struct V_39 * V_40 )
{
struct V_34 * V_3 = & V_2 -> V_3 ;
unsigned int V_41 = V_40 -> V_42 & V_43 ;
if ( V_40 -> V_21 != V_2 -> V_37 ) {
if ( V_3 -> V_23 )
F_23 ( V_40 -> V_21 , V_3 -> V_23 ) ;
V_2 -> V_37 = V_40 -> V_21 ;
F_28 ( V_2 ) ;
}
if ( V_41 && ( V_40 -> V_42 & V_44 ) ) {
F_31 ( ! V_3 -> V_23 ) ;
F_23 ( V_40 -> V_45 , V_3 -> V_46 ) ;
F_23 ( V_40 -> V_47 , V_3 -> V_48 ) ;
F_23 ( V_40 -> V_49 , V_3 -> V_50 ) ;
F_23 ( V_40 -> V_51 , V_3 -> V_52 ) ;
F_23 ( V_40 -> V_53 , V_3 -> V_54 ) ;
F_32 ( L_4 ,
V_40 -> V_45 ,
V_40 -> V_47 ,
V_40 -> V_49 ,
V_40 -> V_51 ,
V_40 -> V_53 ) ;
}
if ( V_41 ) {
F_23 ( V_40 -> V_55 , V_3 -> V_46 ) ;
F_23 ( V_40 -> V_56 , V_3 -> V_48 ) ;
F_23 ( V_40 -> V_57 , V_3 -> V_50 ) ;
F_23 ( V_40 -> V_58 , V_3 -> V_52 ) ;
F_23 ( V_40 -> V_59 , V_3 -> V_54 ) ;
F_32 ( L_5 ,
V_40 -> V_55 ,
V_40 -> V_56 ,
V_40 -> V_57 ,
V_40 -> V_58 ,
V_40 -> V_59 ) ;
}
if ( V_40 -> V_42 & V_60 ) {
F_23 ( V_40 -> V_24 , V_3 -> V_28 ) ;
F_32 ( L_6 , V_40 -> V_24 ) ;
}
F_28 ( V_2 ) ;
}
void F_33 ( struct V_1 * V_2 , struct V_39 * V_40 )
{
struct V_34 * V_3 = & V_2 -> V_3 ;
V_40 -> V_61 = F_1 ( V_2 ) ;
V_40 -> V_55 = F_2 ( V_3 -> V_62 ) ;
V_40 -> V_56 = F_2 ( V_3 -> V_48 ) ;
V_40 -> V_57 = F_2 ( V_3 -> V_50 ) ;
V_40 -> V_58 = F_2 ( V_3 -> V_52 ) ;
V_40 -> V_59 = F_2 ( V_3 -> V_54 ) ;
V_40 -> V_24 = F_2 ( V_3 -> V_28 ) ;
if ( V_40 -> V_42 & V_44 ) {
if ( F_34 ( V_3 -> V_23 ) ) {
F_23 ( V_40 -> V_21 | V_63 , V_3 -> V_23 ) ;
V_40 -> V_45 = F_2 ( V_3 -> V_62 ) ;
V_40 -> V_47 = F_2 ( V_3 -> V_48 ) ;
V_40 -> V_49 = F_2 ( V_3 -> V_50 ) ;
V_40 -> V_51 = F_2 ( V_3 -> V_52 ) ;
V_40 -> V_53 = F_2 ( V_3 -> V_54 ) ;
F_23 ( V_40 -> V_21 , V_3 -> V_23 ) ;
V_2 -> V_37 = V_40 -> V_21 ;
} else
F_31 ( 1 ) ;
}
}
void F_35 ( struct V_1 * V_2 , const struct V_39 * V_40 )
{
F_36 ( L_7 , V_2 -> V_64 , V_40 -> V_61 ) ;
F_23 ( V_40 -> V_61 , V_2 -> V_3 . V_65 ) ;
F_6 ( V_2 ) ;
}
static inline void F_37 ( struct V_1 * V_2 ,
const struct V_39 * V_40 )
{
V_2 -> V_5 -> V_66 ( V_2 , V_40 ) ;
V_2 -> V_5 -> V_67 ( V_2 , V_40 ) ;
}
unsigned int F_38 ( struct V_68 * V_69 , unsigned char * V_70 ,
unsigned int V_71 , int V_72 )
{
struct V_1 * V_2 = V_69 -> V_19 -> V_2 ;
void T_2 * V_73 = V_2 -> V_3 . V_73 ;
unsigned int V_74 = V_71 >> 1 ;
if ( V_72 == V_75 )
F_39 ( V_73 , V_70 , V_74 ) ;
else
F_40 ( V_73 , V_70 , V_74 ) ;
if ( F_41 ( V_71 & 0x01 ) ) {
unsigned char V_76 [ 2 ] = { } ;
V_70 += V_71 - 1 ;
if ( V_72 == V_75 ) {
F_39 ( V_73 , V_76 , 1 ) ;
* V_70 = V_76 [ 0 ] ;
} else {
V_76 [ 0 ] = * V_70 ;
F_40 ( V_73 , V_76 , 1 ) ;
}
V_74 ++ ;
}
return V_74 << 1 ;
}
unsigned int F_42 ( struct V_68 * V_69 , unsigned char * V_70 ,
unsigned int V_71 , int V_72 )
{
struct V_1 * V_2 = V_69 -> V_19 -> V_2 ;
void T_2 * V_73 = V_2 -> V_3 . V_73 ;
unsigned int V_74 = V_71 >> 2 ;
int V_77 = V_71 & 3 ;
if ( ! ( V_2 -> V_78 & V_79 ) )
return F_38 ( V_69 , V_70 , V_71 , V_72 ) ;
if ( V_72 == V_75 )
F_43 ( V_73 , V_70 , V_74 ) ;
else
F_44 ( V_73 , V_70 , V_74 ) ;
if ( F_41 ( V_77 ) ) {
unsigned char V_76 [ 4 ] = { } ;
V_70 += V_71 - V_77 ;
if ( V_72 == V_75 ) {
if ( V_77 < 3 )
F_39 ( V_73 , V_76 , 1 ) ;
else
F_43 ( V_73 , V_76 , 1 ) ;
memcpy ( V_70 , V_76 , V_77 ) ;
} else {
memcpy ( V_76 , V_70 , V_77 ) ;
if ( V_77 < 3 )
F_40 ( V_73 , V_76 , 1 ) ;
else
F_44 ( V_73 , V_76 , 1 ) ;
}
}
return ( V_71 + 1 ) & ~ 1 ;
}
unsigned int F_45 ( struct V_68 * V_69 , unsigned char * V_70 ,
unsigned int V_71 , int V_72 )
{
unsigned long V_42 ;
unsigned int V_80 ;
F_46 ( V_42 ) ;
V_80 = F_42 ( V_69 , V_70 , V_71 , V_72 ) ;
F_47 ( V_42 ) ;
return V_80 ;
}
static void F_48 ( struct V_81 * V_82 )
{
int V_83 = ( V_82 -> V_40 . V_42 & V_84 ) ;
struct V_1 * V_2 = V_82 -> V_2 ;
struct V_85 * V_85 ;
unsigned int V_86 ;
unsigned char * V_70 ;
if ( V_82 -> V_87 == V_82 -> V_88 - V_82 -> V_89 )
V_2 -> V_90 = V_91 ;
V_85 = F_49 ( V_82 -> V_92 ) ;
V_86 = V_82 -> V_92 -> V_86 + V_82 -> V_93 ;
V_85 = F_50 ( V_85 , ( V_86 >> V_94 ) ) ;
V_86 %= V_95 ;
F_36 ( L_8 , V_82 -> V_40 . V_42 & V_84 ? L_9 : L_10 ) ;
if ( F_51 ( V_85 ) ) {
unsigned long V_42 ;
F_46 ( V_42 ) ;
V_70 = F_52 ( V_85 ) ;
V_2 -> V_5 -> V_96 ( V_82 -> V_69 , V_70 + V_86 , V_82 -> V_89 ,
V_83 ) ;
F_53 ( V_70 ) ;
F_47 ( V_42 ) ;
} else {
V_70 = F_54 ( V_85 ) ;
V_2 -> V_5 -> V_96 ( V_82 -> V_69 , V_70 + V_86 , V_82 -> V_89 ,
V_83 ) ;
}
if ( ! V_83 && ! F_55 ( V_85 ) )
F_56 ( V_85 ) ;
V_82 -> V_87 += V_82 -> V_89 ;
V_82 -> V_93 += V_82 -> V_89 ;
if ( V_82 -> V_93 == V_82 -> V_92 -> V_97 ) {
V_82 -> V_92 = F_57 ( V_82 -> V_92 ) ;
V_82 -> V_93 = 0 ;
}
}
static void F_58 ( struct V_81 * V_82 )
{
if ( F_59 ( & V_82 -> V_40 ) ) {
unsigned int V_56 ;
F_31 ( V_82 -> V_69 -> V_98 == 0 ) ;
V_56 = F_60 ( ( V_82 -> V_88 - V_82 -> V_87 ) / V_82 -> V_89 ,
V_82 -> V_69 -> V_98 ) ;
while ( V_56 -- )
F_48 ( V_82 ) ;
} else
F_48 ( V_82 ) ;
F_5 ( V_82 -> V_2 ) ;
}
static void F_61 ( struct V_1 * V_2 , struct V_81 * V_82 )
{
F_36 ( L_11 ) ;
F_31 ( V_82 -> V_69 -> V_99 < 12 ) ;
V_2 -> V_5 -> V_96 ( V_82 -> V_69 , V_82 -> V_100 , V_82 -> V_69 -> V_99 , 1 ) ;
F_5 ( V_2 ) ;
switch ( V_82 -> V_40 . V_101 ) {
case V_102 :
V_2 -> V_90 = V_103 ;
break;
case V_104 :
V_2 -> V_90 = V_91 ;
break;
#ifdef F_62
case V_105 :
V_2 -> V_90 = V_91 ;
V_2 -> V_5 -> V_106 ( V_82 ) ;
break;
#endif
default:
F_9 () ;
}
}
static int F_63 ( struct V_81 * V_82 , unsigned int V_107 )
{
int V_72 = ( V_82 -> V_40 . V_42 & V_84 ) ? V_108 : V_75 ;
struct V_1 * V_2 = V_82 -> V_2 ;
struct V_68 * V_69 = V_82 -> V_69 ;
struct V_109 * V_110 = & V_69 -> V_19 -> V_111 ;
struct V_112 * V_113 ;
struct V_85 * V_85 ;
unsigned char * V_70 ;
unsigned int V_86 , V_114 , V_80 ;
V_115:
V_113 = V_82 -> V_92 ;
if ( F_41 ( ! V_113 ) ) {
F_64 ( V_110 , L_12
L_13 ,
V_82 -> V_88 , V_82 -> V_87 , V_107 ) ;
return - 1 ;
}
V_85 = F_49 ( V_113 ) ;
V_86 = V_113 -> V_86 + V_82 -> V_93 ;
V_85 = F_50 ( V_85 , ( V_86 >> V_94 ) ) ;
V_86 %= V_95 ;
V_114 = F_60 ( V_113 -> V_97 - V_82 -> V_93 , V_107 ) ;
V_114 = F_60 ( V_114 , ( unsigned int ) V_95 - V_86 ) ;
F_36 ( L_8 , V_82 -> V_40 . V_42 & V_84 ? L_9 : L_10 ) ;
if ( F_51 ( V_85 ) ) {
unsigned long V_42 ;
F_46 ( V_42 ) ;
V_70 = F_52 ( V_85 ) ;
V_80 = V_2 -> V_5 -> V_96 ( V_69 , V_70 + V_86 ,
V_114 , V_72 ) ;
F_53 ( V_70 ) ;
F_47 ( V_42 ) ;
} else {
V_70 = F_54 ( V_85 ) ;
V_80 = V_2 -> V_5 -> V_96 ( V_69 , V_70 + V_86 ,
V_114 , V_72 ) ;
}
V_107 -= F_60 ( V_107 , V_80 ) ;
V_82 -> V_87 += V_114 ;
V_82 -> V_93 += V_114 ;
if ( V_82 -> V_93 == V_113 -> V_97 ) {
V_82 -> V_92 = F_57 ( V_82 -> V_92 ) ;
V_82 -> V_93 = 0 ;
}
if ( V_107 )
goto V_115;
return 0 ;
}
static void F_65 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_2 ;
struct V_68 * V_69 = V_82 -> V_69 ;
struct V_109 * V_110 = & V_69 -> V_19 -> V_111 ;
unsigned int V_116 , V_117 , V_118 , V_107 ;
int V_119 , V_83 = ( V_82 -> V_40 . V_42 & V_84 ) ? 1 : 0 ;
V_2 -> V_5 -> V_120 ( V_2 , & V_82 -> V_121 ) ;
V_116 = V_82 -> V_121 . V_56 ;
V_117 = V_82 -> V_121 . V_58 ;
V_118 = V_82 -> V_121 . V_59 ;
V_107 = ( V_118 << 8 ) | V_117 ;
if ( F_41 ( V_116 & V_122 ) )
goto V_123;
V_119 = ( ( V_116 & V_124 ) == 0 ) ? 1 : 0 ;
if ( F_41 ( V_83 != V_119 ) )
goto V_123;
if ( F_41 ( ! V_107 ) )
goto V_123;
F_32 ( L_14 , V_2 -> V_64 , V_107 ) ;
if ( F_41 ( F_63 ( V_82 , V_107 ) ) )
goto V_125;
F_5 ( V_2 ) ;
return;
V_123:
F_64 ( V_110 , L_15 ,
V_116 , V_107 ) ;
V_125:
V_82 -> V_126 |= V_127 ;
V_2 -> V_90 = V_128 ;
}
static inline int F_66 ( struct V_1 * V_2 ,
struct V_81 * V_82 )
{
if ( V_82 -> V_40 . V_42 & V_129 )
return 1 ;
if ( V_2 -> V_90 == V_130 ) {
if ( V_82 -> V_40 . V_101 == V_131 &&
( V_82 -> V_40 . V_42 & V_84 ) )
return 1 ;
if ( F_67 ( V_82 -> V_40 . V_101 ) &&
! ( V_82 -> V_69 -> V_42 & V_132 ) )
return 1 ;
}
return 0 ;
}
static void F_68 ( struct V_81 * V_82 , int V_133 )
{
struct V_1 * V_2 = V_82 -> V_2 ;
unsigned long V_42 ;
if ( V_2 -> V_5 -> V_134 ) {
if ( V_133 ) {
F_69 ( V_2 -> V_135 , V_42 ) ;
V_82 = F_70 ( V_2 , V_82 -> V_136 ) ;
if ( V_82 ) {
if ( F_34 ( ! ( V_82 -> V_126 & V_127 ) ) ) {
F_29 ( V_2 ) ;
F_71 ( V_82 ) ;
} else
F_72 ( V_2 ) ;
}
F_73 ( V_2 -> V_135 , V_42 ) ;
} else {
if ( F_34 ( ! ( V_82 -> V_126 & V_127 ) ) )
F_71 ( V_82 ) ;
else
F_72 ( V_2 ) ;
}
} else {
if ( V_133 ) {
F_69 ( V_2 -> V_135 , V_42 ) ;
F_29 ( V_2 ) ;
F_71 ( V_82 ) ;
F_73 ( V_2 -> V_135 , V_42 ) ;
} else
F_71 ( V_82 ) ;
}
}
int F_74 ( struct V_1 * V_2 , struct V_81 * V_82 ,
T_1 V_8 , int V_133 )
{
struct V_18 * V_19 = V_82 -> V_69 -> V_19 ;
struct V_109 * V_110 = & V_19 -> V_111 ;
unsigned long V_42 = 0 ;
int V_137 ;
F_31 ( ( V_82 -> V_42 & V_138 ) == 0 ) ;
F_31 ( V_133 != F_66 ( V_2 , V_82 ) ) ;
V_139:
F_36 ( L_16 ,
V_2 -> V_64 , V_82 -> V_40 . V_101 , V_2 -> V_90 , V_8 ) ;
switch ( V_2 -> V_90 ) {
case V_130 :
V_137 = ( V_82 -> V_40 . V_42 & V_129 ) ;
if ( F_41 ( ( V_8 & V_140 ) == 0 ) ) {
if ( F_34 ( V_8 & ( V_141 | V_142 ) ) )
V_82 -> V_126 |= V_143 ;
else {
F_64 ( V_110 ,
L_17 ) ;
V_82 -> V_126 |= V_127 ;
}
V_2 -> V_90 = V_128 ;
goto V_139;
}
if ( F_41 ( V_8 & ( V_141 | V_142 ) ) ) {
if ( ! ( V_82 -> V_69 -> V_144 & V_145 ) ) {
F_64 ( V_110 , L_18
L_19
L_20 , V_8 ) ;
V_82 -> V_126 |= V_127 ;
V_2 -> V_90 = V_128 ;
goto V_139;
}
}
if ( V_133 )
F_69 ( V_2 -> V_135 , V_42 ) ;
if ( V_82 -> V_40 . V_101 == V_131 ) {
V_2 -> V_90 = V_103 ;
F_58 ( V_82 ) ;
} else
F_61 ( V_2 , V_82 ) ;
if ( V_133 )
F_73 ( V_2 -> V_135 , V_42 ) ;
break;
case V_103 :
if ( V_82 -> V_40 . V_101 == V_102 ) {
if ( ( V_8 & V_140 ) == 0 ) {
V_2 -> V_90 = V_91 ;
goto V_139;
}
if ( F_41 ( V_8 & ( V_141 | V_142 ) ) ) {
F_64 ( V_110 , L_21
L_19
L_20 , V_8 ) ;
V_82 -> V_126 |= V_127 ;
V_2 -> V_90 = V_128 ;
goto V_139;
}
F_65 ( V_82 ) ;
if ( F_41 ( V_2 -> V_90 == V_128 ) )
goto V_139;
} else {
if ( F_41 ( ( V_8 & V_140 ) == 0 ) ) {
if ( F_34 ( V_8 & ( V_141 | V_142 ) ) ) {
V_82 -> V_126 |= V_143 ;
if ( V_82 -> V_69 -> V_144 &
V_146 )
V_82 -> V_126 |=
V_147 ;
} else {
F_64 ( V_110 , L_22
L_23
L_20 , V_8 ) ;
V_82 -> V_126 |= V_127 |
V_147 ;
}
V_2 -> V_90 = V_128 ;
goto V_139;
}
if ( F_41 ( V_8 & ( V_141 | V_142 ) ) ) {
V_82 -> V_126 |= V_143 ;
if ( ! ( V_82 -> V_40 . V_42 & V_84 ) ) {
F_58 ( V_82 ) ;
V_8 = F_28 ( V_2 ) ;
}
if ( V_8 & ( V_9 | V_140 ) ) {
F_64 ( V_110 , L_22
L_24
L_20 , V_8 ) ;
V_82 -> V_126 |= V_127 ;
}
if ( V_8 == 0x7f )
V_82 -> V_126 |= V_147 ;
V_2 -> V_90 = V_128 ;
goto V_139;
}
F_58 ( V_82 ) ;
if ( V_2 -> V_90 == V_91 &&
( ! ( V_82 -> V_40 . V_42 & V_84 ) ) ) {
V_8 = F_28 ( V_2 ) ;
goto V_139;
}
}
V_137 = 1 ;
break;
case V_91 :
if ( F_41 ( ! F_75 ( V_8 ) ) ) {
V_82 -> V_126 |= F_76 ( V_8 ) ;
V_2 -> V_90 = V_128 ;
goto V_139;
}
F_36 ( L_25 ,
V_2 -> V_64 , V_82 -> V_69 -> V_148 , V_8 ) ;
F_31 ( V_82 -> V_126 & ( V_143 | V_127 ) ) ;
V_2 -> V_90 = V_149 ;
F_68 ( V_82 , V_133 ) ;
V_137 = 0 ;
break;
case V_128 :
V_2 -> V_90 = V_149 ;
F_68 ( V_82 , V_133 ) ;
V_137 = 0 ;
break;
default:
V_137 = 0 ;
F_9 () ;
}
return V_137 ;
}
void F_77 ( struct V_150 * V_151 )
{
F_78 ( V_152 , V_151 ) ;
}
void F_79 ( struct V_153 * V_154 , unsigned long V_155 )
{
F_80 ( V_152 , V_154 , V_155 ) ;
}
void F_81 ( struct V_18 * V_19 , unsigned long V_155 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_82 ( ( V_2 -> V_156 != NULL ) &&
( V_2 -> V_156 != V_19 ) ) ;
V_2 -> V_156 = V_19 ;
F_79 ( & V_2 -> V_157 , F_83 ( V_155 ) ) ;
}
void F_84 ( struct V_1 * V_2 )
{
F_36 ( L_26 ) ;
F_85 ( & V_2 -> V_157 ) ;
F_86 ( V_2 -> V_135 ) ;
V_2 -> V_90 = V_149 ;
F_87 ( V_2 -> V_135 ) ;
V_2 -> V_156 = NULL ;
if ( F_88 ( V_2 ) )
F_89 ( V_2 , L_27 , V_158 ) ;
}
static void F_90 ( struct V_150 * V_151 )
{
struct V_1 * V_2 =
F_91 ( V_151 , struct V_1 , V_157 . V_151 ) ;
struct V_18 * V_19 = V_2 -> V_156 ;
struct V_81 * V_82 ;
T_1 V_8 ;
int V_137 ;
F_92 ( V_2 -> V_156 == NULL ) ;
V_82 = F_70 ( V_2 , V_19 -> V_159 ) ;
if ( ! V_82 ) {
V_2 -> V_156 = NULL ;
return;
}
V_139:
F_31 ( V_2 -> V_90 == V_149 ) ;
V_8 = F_11 ( V_2 , V_9 , 5 ) ;
if ( V_8 & V_9 ) {
F_14 ( V_2 , 2 ) ;
V_8 = F_11 ( V_2 , V_9 , 10 ) ;
if ( V_8 & V_9 ) {
F_81 ( V_19 , V_160 ) ;
return;
}
}
V_2 -> V_156 = NULL ;
V_137 = F_74 ( V_2 , V_82 , V_8 , 1 ) ;
if ( V_137 )
goto V_139;
}
unsigned int F_93 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_2 ;
struct V_18 * V_19 = V_82 -> V_69 -> V_19 ;
if ( V_2 -> V_42 & V_161 )
V_82 -> V_40 . V_42 |= V_129 ;
F_25 ( V_2 , V_82 -> V_69 -> V_148 , 1 , 0 ) ;
switch ( V_82 -> V_40 . V_101 ) {
case V_162 :
if ( V_82 -> V_40 . V_42 & V_129 )
F_94 ( V_82 ) ;
F_37 ( V_2 , & V_82 -> V_40 ) ;
V_2 -> V_90 = V_91 ;
if ( V_82 -> V_40 . V_42 & V_129 )
F_81 ( V_19 , 0 ) ;
break;
case V_131 :
if ( V_82 -> V_40 . V_42 & V_129 )
F_94 ( V_82 ) ;
F_37 ( V_2 , & V_82 -> V_40 ) ;
if ( V_82 -> V_40 . V_42 & V_84 ) {
V_2 -> V_90 = V_130 ;
F_81 ( V_19 , 0 ) ;
} else {
V_2 -> V_90 = V_103 ;
if ( V_82 -> V_40 . V_42 & V_129 )
F_81 ( V_19 , 0 ) ;
}
break;
case V_102 :
case V_104 :
if ( V_82 -> V_40 . V_42 & V_129 )
F_94 ( V_82 ) ;
F_37 ( V_2 , & V_82 -> V_40 ) ;
V_2 -> V_90 = V_130 ;
if ( ( ! ( V_82 -> V_69 -> V_42 & V_132 ) ) ||
( V_82 -> V_40 . V_42 & V_129 ) )
F_81 ( V_19 , 0 ) ;
break;
default:
F_31 ( 1 ) ;
return V_163 ;
}
return 0 ;
}
bool F_95 ( struct V_81 * V_82 )
{
V_82 -> V_2 -> V_5 -> V_120 ( V_82 -> V_2 , & V_82 -> V_121 ) ;
return true ;
}
static unsigned int F_96 ( struct V_1 * V_2 )
{
V_2 -> V_164 . V_165 ++ ;
#ifdef F_97
if ( ( V_2 -> V_164 . V_165 % 1000 ) == 0 ) {
V_2 -> V_5 -> V_10 ( V_2 ) ;
if ( V_2 -> V_5 -> V_38 )
V_2 -> V_5 -> V_38 ( V_2 ) ;
F_15 ( V_2 , L_28 ) ;
return 1 ;
}
#endif
return 0 ;
}
static unsigned int F_98 ( struct V_1 * V_2 ,
struct V_81 * V_82 ,
bool V_166 )
{
T_1 V_8 ;
F_32 ( L_29 ,
V_2 -> V_64 , V_82 -> V_40 . V_101 , V_2 -> V_90 ) ;
switch ( V_2 -> V_90 ) {
case V_130 :
if ( ! ( V_82 -> V_69 -> V_42 & V_132 ) )
return F_96 ( V_2 ) ;
break;
case V_149 :
return F_96 ( V_2 ) ;
default:
break;
}
V_8 = F_4 ( V_2 ) ;
if ( V_8 & V_9 ) {
if ( V_166 ) {
V_82 -> V_126 |= V_127 ;
V_2 -> V_90 = V_128 ;
} else
return F_96 ( V_2 ) ;
}
if ( V_2 -> V_5 -> V_38 )
V_2 -> V_5 -> V_38 ( V_2 ) ;
F_74 ( V_2 , V_82 , V_8 , 0 ) ;
return 1 ;
}
unsigned int F_99 ( struct V_1 * V_2 , struct V_81 * V_82 )
{
return F_98 ( V_2 , V_82 , false ) ;
}
T_3 F_100 ( int V_167 , void * V_168 )
{
return F_101 ( V_167 , V_168 , F_99 ) ;
}
void F_102 ( struct V_1 * V_2 )
{
T_1 V_8 ;
struct V_81 * V_82 ;
V_82 = F_70 ( V_2 , V_2 -> V_19 . V_159 ) ;
if ( ! V_82 || V_82 -> V_40 . V_42 & V_129 )
return;
V_8 = F_3 ( V_2 ) ;
if ( V_8 & V_9 )
return;
F_15 ( V_2 , L_30 ,
V_8 ) ;
F_99 ( V_2 , V_82 ) ;
}
void F_103 ( struct V_1 * V_2 )
{
V_2 -> V_21 |= V_36 ;
V_2 -> V_37 = V_2 -> V_21 ;
if ( V_2 -> V_5 -> V_22 || V_2 -> V_3 . V_23 )
F_22 ( V_2 , V_2 -> V_21 ) ;
V_2 -> V_5 -> V_10 ( V_2 ) ;
if ( V_2 -> V_5 -> V_38 )
V_2 -> V_5 -> V_38 ( V_2 ) ;
}
void F_104 ( struct V_1 * V_2 )
{
V_2 -> V_5 -> V_10 ( V_2 ) ;
if ( V_2 -> V_5 -> V_38 )
V_2 -> V_5 -> V_38 ( V_2 ) ;
F_29 ( V_2 ) ;
}
int F_105 ( struct V_18 * V_19 , unsigned long V_20 )
{
struct V_169 * V_170 = & V_19 -> V_171 ;
int V_172 ;
V_172 = F_106 ( V_19 , V_20 ) ;
if ( V_172 )
return V_172 ;
if ( V_170 -> V_173 . V_174 & V_175 )
return 0 ;
if ( ! F_107 ( V_19 ) ) {
V_172 = F_20 ( V_19 , V_20 ) ;
if ( V_172 && V_172 != - V_16 ) {
F_108 ( V_19 ,
L_31 ,
V_172 ) ;
V_170 -> V_173 . V_174 |= V_175 ;
}
}
return 0 ;
}
static unsigned int F_109 ( struct V_1 * V_2 , unsigned int V_24 )
{
struct V_34 * V_3 = & V_2 -> V_3 ;
T_1 V_56 , V_57 ;
V_2 -> V_5 -> V_31 ( V_2 , V_24 ) ;
F_23 ( 0x55 , V_3 -> V_48 ) ;
F_23 ( 0xaa , V_3 -> V_50 ) ;
F_23 ( 0xaa , V_3 -> V_48 ) ;
F_23 ( 0x55 , V_3 -> V_50 ) ;
F_23 ( 0x55 , V_3 -> V_48 ) ;
F_23 ( 0xaa , V_3 -> V_50 ) ;
V_56 = F_2 ( V_3 -> V_48 ) ;
V_57 = F_2 ( V_3 -> V_50 ) ;
if ( ( V_56 == 0x55 ) && ( V_57 == 0xaa ) )
return 1 ;
return 0 ;
}
unsigned int F_110 ( struct V_68 * V_69 , int V_176 ,
T_1 * V_177 )
{
struct V_1 * V_2 = V_69 -> V_19 -> V_2 ;
struct V_39 V_40 ;
unsigned int V_32 ;
T_1 V_178 ;
V_2 -> V_5 -> V_31 ( V_2 , V_69 -> V_148 ) ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_2 -> V_5 -> V_120 ( V_2 , & V_40 ) ;
V_178 = V_40 . V_55 ;
if ( V_177 )
* V_177 = V_178 ;
if ( V_178 == 0 )
V_69 -> V_144 |= V_146 ;
else if ( V_178 == 1 )
;
else if ( ( V_69 -> V_148 == 0 ) && ( V_178 == 0x81 ) )
;
else
return V_179 ;
V_32 = F_111 ( & V_40 ) ;
if ( V_32 == V_180 ) {
if ( V_176 && ( V_69 -> V_144 & V_146 ) )
V_32 = V_181 ;
else
V_32 = V_179 ;
} else if ( ( V_32 == V_181 ) &&
( V_2 -> V_5 -> V_10 ( V_2 ) == 0 ) )
V_32 = V_179 ;
return V_32 ;
}
int F_112 ( struct V_18 * V_19 , unsigned int V_182 ,
unsigned long V_20 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_34 * V_3 = & V_2 -> V_3 ;
unsigned int V_183 = V_182 & ( 1 << 0 ) ;
unsigned int V_184 = V_182 & ( 1 << 1 ) ;
int V_172 , V_185 = 0 ;
F_14 ( V_2 , V_186 ) ;
V_172 = F_20 ( V_19 , V_20 ) ;
if ( V_172 )
return V_172 ;
if ( V_184 ) {
int V_173 ;
V_2 -> V_5 -> V_31 ( V_2 , 1 ) ;
for ( V_173 = 0 ; V_173 < 2 ; V_173 ++ ) {
T_1 V_56 , V_57 ;
V_56 = F_2 ( V_3 -> V_48 ) ;
V_57 = F_2 ( V_3 -> V_50 ) ;
if ( ( V_56 == 1 ) && ( V_57 == 1 ) )
break;
F_14 ( V_2 , 50 ) ;
}
V_172 = F_20 ( V_19 , V_20 ) ;
if ( V_172 ) {
if ( V_172 != - V_16 )
return V_172 ;
V_185 = V_172 ;
}
}
V_2 -> V_5 -> V_31 ( V_2 , 0 ) ;
if ( V_184 )
V_2 -> V_5 -> V_31 ( V_2 , 1 ) ;
if ( V_183 )
V_2 -> V_5 -> V_31 ( V_2 , 0 ) ;
return V_185 ;
}
static int F_113 ( struct V_1 * V_2 , unsigned int V_182 ,
unsigned long V_20 )
{
struct V_34 * V_3 = & V_2 -> V_3 ;
F_36 ( L_32 , V_2 -> V_64 ) ;
if ( V_2 -> V_3 . V_23 ) {
F_23 ( V_2 -> V_21 , V_3 -> V_23 ) ;
F_114 ( 20 ) ;
F_23 ( V_2 -> V_21 | V_187 , V_3 -> V_23 ) ;
F_114 ( 20 ) ;
F_23 ( V_2 -> V_21 , V_3 -> V_23 ) ;
V_2 -> V_37 = V_2 -> V_21 ;
}
return F_112 ( & V_2 -> V_19 , V_182 , V_20 ) ;
}
int F_115 ( struct V_18 * V_19 , unsigned int * V_188 ,
unsigned long V_20 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_189 = V_2 -> V_42 & V_190 ;
unsigned int V_182 = 0 ;
int V_172 ;
T_1 V_178 ;
F_36 ( L_26 ) ;
if ( F_109 ( V_2 , 0 ) )
V_182 |= ( 1 << 0 ) ;
if ( V_189 && F_109 ( V_2 , 1 ) )
V_182 |= ( 1 << 1 ) ;
V_2 -> V_5 -> V_31 ( V_2 , 0 ) ;
F_36 ( L_33 , V_182 ) ;
V_172 = F_113 ( V_2 , V_182 , V_20 ) ;
if ( V_172 && ( V_172 != - V_16 || F_116 ( V_19 ) ) ) {
F_117 ( V_19 , L_34 , V_172 ) ;
return V_172 ;
}
V_188 [ 0 ] = F_110 ( & V_19 -> V_24 [ 0 ] ,
V_182 & ( 1 << 0 ) , & V_178 ) ;
if ( V_189 && V_178 != 0x81 )
V_188 [ 1 ] = F_110 ( & V_19 -> V_24 [ 1 ] ,
V_182 & ( 1 << 1 ) , & V_178 ) ;
F_36 ( L_35 , V_188 [ 0 ] , V_188 [ 1 ] ) ;
return 0 ;
}
int F_118 ( struct V_18 * V_19 , unsigned int * V_32 ,
unsigned long V_20 )
{
struct V_169 * V_170 = & V_19 -> V_171 ;
const unsigned long * V_191 = F_119 ( V_170 ) ;
bool V_192 ;
int V_172 ;
V_172 = F_120 ( V_19 , V_191 , V_20 , & V_192 ,
F_18 ) ;
if ( V_192 )
* V_32 = F_110 ( V_19 -> V_24 , 1 , NULL ) ;
F_36 ( L_36 , * V_32 ) ;
return V_172 ;
}
void F_121 ( struct V_18 * V_19 , unsigned int * V_188 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_122 ( V_19 , V_188 ) ;
if ( V_188 [ 0 ] != V_179 )
V_2 -> V_5 -> V_31 ( V_2 , 1 ) ;
if ( V_188 [ 1 ] != V_179 )
V_2 -> V_5 -> V_31 ( V_2 , 0 ) ;
if ( V_188 [ 0 ] == V_179 && V_188 [ 1 ] == V_179 ) {
F_36 ( L_37 ) ;
return;
}
if ( V_2 -> V_5 -> V_22 || V_2 -> V_3 . V_23 ) {
F_22 ( V_2 , V_2 -> V_21 ) ;
V_2 -> V_37 = V_2 -> V_21 ;
}
}
void F_123 ( struct V_81 * V_82 )
{
int V_114 ;
struct V_1 * V_2 ;
if ( V_82 == NULL || V_82 -> V_193 == V_194 )
return;
V_2 = V_82 -> V_2 ;
for ( V_114 = 0 ; ( V_2 -> V_5 -> V_10 ( V_2 ) & V_140 )
&& V_114 < 65536 ; V_114 += 2 )
F_124 ( V_2 -> V_3 . V_73 ) ;
if ( V_114 )
F_89 ( V_2 , L_38 , V_114 ) ;
}
void F_125 ( struct V_1 * V_2 )
{
T_4 V_195 = V_2 -> V_5 -> V_195 ;
T_4 V_196 = V_2 -> V_5 -> V_196 ;
struct V_81 * V_82 ;
unsigned long V_42 ;
V_82 = F_126 ( V_2 , V_2 -> V_19 . V_159 ) ;
if ( V_82 && ! ( V_82 -> V_42 & V_197 ) )
V_82 = NULL ;
F_69 ( V_2 -> V_135 , V_42 ) ;
if ( V_2 -> V_5 -> V_198 )
V_2 -> V_5 -> V_198 ( V_82 ) ;
F_73 ( V_2 -> V_135 , V_42 ) ;
if ( ( V_196 == V_199 ||
V_196 == F_118 ) && ! F_116 ( & V_2 -> V_19 ) )
V_196 = NULL ;
F_127 ( V_2 , V_2 -> V_5 -> V_200 , V_195 , V_196 ,
V_2 -> V_5 -> V_201 ) ;
}
void F_128 ( struct V_34 * V_3 )
{
V_3 -> V_73 = V_3 -> V_202 + V_203 ;
V_3 -> V_62 = V_3 -> V_202 + V_204 ;
V_3 -> V_46 = V_3 -> V_202 + V_205 ;
V_3 -> V_48 = V_3 -> V_202 + V_206 ;
V_3 -> V_50 = V_3 -> V_202 + V_207 ;
V_3 -> V_52 = V_3 -> V_202 + V_208 ;
V_3 -> V_54 = V_3 -> V_202 + V_209 ;
V_3 -> V_28 = V_3 -> V_202 + V_210 ;
V_3 -> V_4 = V_3 -> V_202 + V_211 ;
V_3 -> V_65 = V_3 -> V_202 + V_212 ;
}
static int F_129 ( struct V_213 * V_214 , int V_215 )
{
int V_173 ;
V_215 = V_215 * 2 ;
for ( V_173 = 0 ; V_173 < 2 ; V_173 ++ ) {
if ( F_130 ( V_214 , V_215 + V_173 ) == 0 ||
F_131 ( V_214 , V_215 + V_173 ) == 0 )
return 0 ;
}
return 1 ;
}
int F_132 ( struct V_216 * V_217 )
{
struct V_24 * V_218 = V_217 -> V_69 ;
struct V_213 * V_214 = F_133 ( V_218 ) ;
unsigned int V_219 = 0 ;
int V_173 , V_172 ;
for ( V_173 = 0 ; V_173 < 2 ; V_173 ++ ) {
struct V_1 * V_2 = V_217 -> V_220 [ V_173 ] ;
int V_221 = V_173 * 2 ;
void T_2 * const * V_222 ;
if ( F_134 ( V_2 ) )
continue;
if ( ! F_129 ( V_214 , V_173 ) ) {
V_2 -> V_5 = & V_223 ;
continue;
}
V_172 = F_135 ( V_214 , 0x3 << V_221 ,
F_136 ( V_218 ) ) ;
if ( V_172 ) {
F_137 ( V_218 ,
L_39 ,
V_173 , V_172 ) ;
if ( V_172 == - V_17 )
F_138 ( V_214 ) ;
V_2 -> V_5 = & V_223 ;
continue;
}
V_217 -> V_222 = V_222 = F_139 ( V_214 ) ;
V_2 -> V_3 . V_202 = V_222 [ V_221 ] ;
V_2 -> V_3 . V_7 =
V_2 -> V_3 . V_23 = ( void T_2 * )
( ( unsigned long ) V_222 [ V_221 + 1 ] | V_224 ) ;
F_128 ( & V_2 -> V_3 ) ;
F_140 ( V_2 , L_40 ,
( unsigned long long ) F_130 ( V_214 , V_221 ) ,
( unsigned long long ) F_130 ( V_214 , V_221 + 1 ) ) ;
V_219 |= 1 << V_173 ;
}
if ( ! V_219 ) {
F_141 ( V_218 , L_41 ) ;
return - V_16 ;
}
return 0 ;
}
int F_142 ( struct V_213 * V_214 ,
const struct F_27 * const * V_225 ,
struct V_216 * * V_226 )
{
struct V_216 * V_217 ;
int V_172 ;
if ( ! F_143 ( & V_214 -> V_69 , NULL , V_227 ) )
return - V_228 ;
V_217 = F_144 ( & V_214 -> V_69 , V_225 , 2 ) ;
if ( ! V_217 ) {
F_141 ( & V_214 -> V_69 , L_42 ) ;
V_172 = - V_228 ;
goto V_125;
}
V_172 = F_132 ( V_217 ) ;
if ( V_172 )
goto V_125;
F_145 ( & V_214 -> V_69 , NULL ) ;
* V_226 = V_217 ;
return 0 ;
V_125:
F_146 ( & V_214 -> V_69 , NULL ) ;
return V_172 ;
}
int F_147 ( struct V_216 * V_217 ,
T_5 V_229 ,
struct V_230 * V_231 )
{
struct V_24 * V_69 = V_217 -> V_69 ;
struct V_213 * V_214 = F_133 ( V_69 ) ;
const char * V_232 = F_136 ( V_217 -> V_69 ) ;
int V_233 = 0 , V_172 ;
V_172 = F_148 ( V_217 ) ;
if ( V_172 )
return V_172 ;
if ( ( V_214 -> V_32 >> 8 ) == V_234 ) {
T_1 V_235 , V_219 ;
F_149 ( V_214 , V_236 , & V_235 ) ;
V_219 = ( 1 << 2 ) | ( 1 << 0 ) ;
if ( ( V_235 & V_219 ) != V_219 )
V_233 = 1 ;
}
if ( ! F_143 ( V_69 , NULL , V_227 ) )
return - V_228 ;
if ( ! V_233 && V_214 -> V_167 ) {
int V_173 ;
V_172 = F_150 ( V_69 , V_214 -> V_167 , V_229 ,
V_237 , V_232 , V_217 ) ;
if ( V_172 )
goto V_238;
for ( V_173 = 0 ; V_173 < 2 ; V_173 ++ ) {
if ( F_134 ( V_217 -> V_220 [ V_173 ] ) )
continue;
F_140 ( V_217 -> V_220 [ V_173 ] , L_43 , V_214 -> V_167 ) ;
}
} else if ( V_233 ) {
if ( ! F_134 ( V_217 -> V_220 [ 0 ] ) ) {
V_172 = F_150 ( V_69 , F_151 ( V_214 ) ,
V_229 , V_237 ,
V_232 , V_217 ) ;
if ( V_172 )
goto V_238;
F_140 ( V_217 -> V_220 [ 0 ] , L_43 ,
F_151 ( V_214 ) ) ;
}
if ( ! F_134 ( V_217 -> V_220 [ 1 ] ) ) {
V_172 = F_150 ( V_69 , F_152 ( V_214 ) ,
V_229 , V_237 ,
V_232 , V_217 ) ;
if ( V_172 )
goto V_238;
F_140 ( V_217 -> V_220 [ 1 ] , L_43 ,
F_152 ( V_214 ) ) ;
}
}
V_172 = F_153 ( V_217 , V_231 ) ;
V_238:
if ( V_172 == 0 )
F_145 ( V_69 , NULL ) ;
else
F_146 ( V_69 , NULL ) ;
return V_172 ;
}
static const struct F_27 * F_154 (
const struct F_27 * const * V_225 )
{
int V_173 ;
for ( V_173 = 0 ; V_173 < 2 && V_225 [ V_173 ] ; V_173 ++ )
if ( V_225 [ V_173 ] -> V_239 != & V_223 )
return V_225 [ V_173 ] ;
return NULL ;
}
static int F_155 ( struct V_213 * V_214 ,
const struct F_27 * const * V_225 ,
struct V_230 * V_231 , void * V_240 ,
int V_241 , bool V_242 )
{
struct V_24 * V_69 = & V_214 -> V_69 ;
const struct F_27 * V_243 ;
struct V_216 * V_217 = NULL ;
int V_172 ;
F_36 ( L_26 ) ;
V_243 = F_154 ( V_225 ) ;
if ( ! V_243 ) {
F_141 ( & V_214 -> V_69 , L_44 ) ;
return - V_244 ;
}
if ( ! F_143 ( V_69 , NULL , V_227 ) )
return - V_228 ;
V_172 = F_156 ( V_214 ) ;
if ( V_172 )
goto V_238;
#ifdef F_62
if ( V_242 )
V_172 = F_157 ( V_214 , V_225 , & V_217 ) ;
else
#endif
V_172 = F_142 ( V_214 , V_225 , & V_217 ) ;
if ( V_172 )
goto V_238;
V_217 -> V_245 = V_240 ;
V_217 -> V_42 |= V_241 ;
#ifdef F_62
if ( V_242 ) {
F_158 ( V_214 ) ;
V_172 = F_147 ( V_217 , V_246 , V_231 ) ;
} else
#endif
V_172 = F_147 ( V_217 , F_100 , V_231 ) ;
V_238:
if ( V_172 == 0 )
F_145 ( & V_214 -> V_69 , NULL ) ;
else
F_146 ( & V_214 -> V_69 , NULL ) ;
return V_172 ;
}
int F_159 ( struct V_213 * V_214 ,
const struct F_27 * const * V_225 ,
struct V_230 * V_231 , void * V_240 , int V_247 )
{
return F_155 ( V_214 , V_225 , V_231 , V_240 , V_247 , 0 ) ;
}
static void F_160 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_2 ;
struct V_248 * V_249 = V_2 -> V_250 ;
struct V_112 * V_113 ;
unsigned int V_251 , V_243 ;
V_243 = 0 ;
F_161 (qc->sg, sg, qc->n_elem, si) {
T_6 V_252 , V_86 ;
T_6 V_253 , V_254 ;
V_252 = ( T_6 ) F_162 ( V_113 ) ;
V_253 = F_163 ( V_113 ) ;
while ( V_253 ) {
V_86 = V_252 & 0xffff ;
V_254 = V_253 ;
if ( ( V_86 + V_253 ) > 0x10000 )
V_254 = 0x10000 - V_86 ;
V_249 [ V_243 ] . V_252 = F_164 ( V_252 ) ;
V_249 [ V_243 ] . V_255 = F_164 ( V_254 & 0xffff ) ;
F_32 ( L_45 , V_243 , V_252 , V_254 ) ;
V_243 ++ ;
V_253 -= V_254 ;
V_252 += V_254 ;
}
}
V_249 [ V_243 - 1 ] . V_255 |= F_164 ( V_256 ) ;
}
static void F_165 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_2 ;
struct V_248 * V_249 = V_2 -> V_250 ;
struct V_112 * V_113 ;
unsigned int V_251 , V_243 ;
V_243 = 0 ;
F_161 (qc->sg, sg, qc->n_elem, si) {
T_6 V_252 , V_86 ;
T_6 V_253 , V_254 , V_257 ;
V_252 = ( T_6 ) F_162 ( V_113 ) ;
V_253 = F_163 ( V_113 ) ;
while ( V_253 ) {
V_86 = V_252 & 0xffff ;
V_254 = V_253 ;
if ( ( V_86 + V_253 ) > 0x10000 )
V_254 = 0x10000 - V_86 ;
V_257 = V_254 & 0xffff ;
V_249 [ V_243 ] . V_252 = F_164 ( V_252 ) ;
if ( V_257 == 0 ) {
V_249 [ V_243 ] . V_255 = F_164 ( 0x8000 ) ;
V_257 = 0x8000 ;
V_249 [ ++ V_243 ] . V_252 = F_164 ( V_252 + 0x8000 ) ;
}
V_249 [ V_243 ] . V_255 = F_164 ( V_257 ) ;
F_32 ( L_45 , V_243 , V_252 , V_254 ) ;
V_243 ++ ;
V_253 -= V_254 ;
V_252 += V_254 ;
}
}
V_249 [ V_243 - 1 ] . V_255 |= F_164 ( V_256 ) ;
}
void F_166 ( struct V_81 * V_82 )
{
if ( ! ( V_82 -> V_42 & V_258 ) )
return;
F_160 ( V_82 ) ;
}
void F_167 ( struct V_81 * V_82 )
{
if ( ! ( V_82 -> V_42 & V_258 ) )
return;
F_165 ( V_82 ) ;
}
unsigned int F_168 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_2 ;
struct V_18 * V_19 = V_82 -> V_69 -> V_19 ;
if ( ! F_169 ( V_82 -> V_40 . V_101 ) )
return F_93 ( V_82 ) ;
F_25 ( V_2 , V_82 -> V_69 -> V_148 , 1 , 0 ) ;
switch ( V_82 -> V_40 . V_101 ) {
case V_259 :
F_31 ( V_82 -> V_40 . V_42 & V_129 ) ;
V_2 -> V_5 -> V_66 ( V_2 , & V_82 -> V_40 ) ;
V_2 -> V_5 -> V_260 ( V_82 ) ;
V_2 -> V_5 -> V_106 ( V_82 ) ;
V_2 -> V_90 = V_91 ;
break;
case V_105 :
F_31 ( V_82 -> V_40 . V_42 & V_129 ) ;
V_2 -> V_5 -> V_66 ( V_2 , & V_82 -> V_40 ) ;
V_2 -> V_5 -> V_260 ( V_82 ) ;
V_2 -> V_90 = V_130 ;
if ( ! ( V_82 -> V_69 -> V_42 & V_132 ) )
F_81 ( V_19 , 0 ) ;
break;
default:
F_82 ( 1 ) ;
return V_163 ;
}
return 0 ;
}
unsigned int F_170 ( struct V_1 * V_2 , struct V_81 * V_82 )
{
struct V_109 * V_110 = & V_2 -> V_19 . V_111 ;
T_1 V_261 = 0 ;
bool V_262 = false ;
unsigned int V_263 ;
if ( V_2 -> V_90 == V_91 && F_169 ( V_82 -> V_40 . V_101 ) ) {
V_261 = V_2 -> V_5 -> V_264 ( V_2 ) ;
F_32 ( L_46 , V_2 -> V_64 , V_261 ) ;
if ( ! ( V_261 & V_265 ) )
return F_96 ( V_2 ) ;
V_2 -> V_5 -> V_266 ( V_82 ) ;
V_262 = true ;
if ( F_41 ( V_261 & V_267 ) ) {
V_82 -> V_126 |= V_268 ;
V_2 -> V_90 = V_128 ;
}
}
V_263 = F_98 ( V_2 , V_82 , V_262 ) ;
if ( F_41 ( V_82 -> V_126 ) && F_169 ( V_82 -> V_40 . V_101 ) )
F_64 ( V_110 , L_47 , V_261 ) ;
return V_263 ;
}
T_3 V_246 ( int V_167 , void * V_168 )
{
return F_101 ( V_167 , V_168 , F_170 ) ;
}
void F_171 ( struct V_1 * V_2 )
{
struct V_81 * V_82 ;
unsigned long V_42 ;
bool V_269 = false ;
V_82 = F_126 ( V_2 , V_2 -> V_19 . V_159 ) ;
if ( V_82 && ! ( V_82 -> V_42 & V_197 ) )
V_82 = NULL ;
F_69 ( V_2 -> V_135 , V_42 ) ;
if ( V_82 && F_169 ( V_82 -> V_40 . V_101 ) ) {
T_1 V_261 ;
V_261 = V_2 -> V_5 -> V_264 ( V_2 ) ;
if ( V_82 -> V_126 == V_270 && ( V_261 & V_267 ) ) {
V_82 -> V_126 = V_268 ;
V_269 = true ;
}
V_2 -> V_5 -> V_266 ( V_82 ) ;
if ( V_269 ) {
V_2 -> V_5 -> V_10 ( V_2 ) ;
if ( V_2 -> V_5 -> V_38 )
V_2 -> V_5 -> V_38 ( V_2 ) ;
}
}
F_73 ( V_2 -> V_135 , V_42 ) ;
if ( V_269 )
F_172 ( V_2 ) ;
F_125 ( V_2 ) ;
}
void F_173 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_2 ;
unsigned long V_42 ;
if ( F_169 ( V_82 -> V_40 . V_101 ) ) {
F_69 ( V_2 -> V_135 , V_42 ) ;
V_2 -> V_5 -> V_266 ( V_82 ) ;
F_73 ( V_2 -> V_135 , V_42 ) ;
}
}
void F_174 ( struct V_1 * V_2 )
{
void T_2 * V_271 = V_2 -> V_3 . V_272 ;
if ( ! V_271 )
return;
F_23 ( F_2 ( V_271 + V_273 ) , V_271 + V_273 ) ;
}
void F_175 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_2 ;
unsigned int V_72 = ( V_82 -> V_40 . V_42 & V_84 ) ;
T_1 V_274 ;
F_176 () ;
F_177 ( V_2 -> V_275 , V_2 -> V_3 . V_272 + V_276 ) ;
V_274 = F_2 ( V_2 -> V_3 . V_272 + V_277 ) ;
V_274 &= ~ ( V_278 | V_279 ) ;
if ( ! V_72 )
V_274 |= V_278 ;
F_23 ( V_274 , V_2 -> V_3 . V_272 + V_277 ) ;
V_2 -> V_5 -> V_67 ( V_2 , & V_82 -> V_40 ) ;
}
void F_178 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_2 ;
T_1 V_274 ;
V_274 = F_2 ( V_2 -> V_3 . V_272 + V_277 ) ;
F_23 ( V_274 | V_279 , V_2 -> V_3 . V_272 + V_277 ) ;
}
void F_179 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_2 ;
void T_2 * V_271 = V_2 -> V_3 . V_272 ;
F_23 ( F_2 ( V_271 + V_277 ) & ~ V_279 ,
V_271 + V_277 ) ;
F_8 ( V_2 ) ;
}
T_1 F_180 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 . V_272 + V_273 ) ;
}
int F_181 ( struct V_1 * V_2 )
{
if ( V_2 -> V_280 || V_2 -> V_281 ) {
V_2 -> V_250 =
F_182 ( V_2 -> V_217 -> V_69 , V_282 ,
& V_2 -> V_275 , V_227 ) ;
if ( ! V_2 -> V_250 )
return - V_228 ;
}
return 0 ;
}
int F_183 ( struct V_1 * V_2 )
{
V_2 -> V_78 |= V_79 | V_283 ;
return F_181 ( V_2 ) ;
}
int F_184 ( struct V_213 * V_214 )
{
unsigned long V_242 = F_130 ( V_214 , 4 ) ;
T_1 V_284 ;
if ( V_242 == 0 )
return - V_285 ;
V_284 = F_185 ( V_242 + 0x02 ) ;
F_186 ( V_284 & 0x60 , V_242 + 0x02 ) ;
V_284 = F_185 ( V_242 + 0x02 ) ;
if ( V_284 & 0x80 )
return - V_286 ;
return 0 ;
}
static void F_187 ( struct V_216 * V_217 , const char * V_287 )
{
int V_173 ;
F_141 ( V_217 -> V_69 , L_48 , V_287 ) ;
for ( V_173 = 0 ; V_173 < 2 ; V_173 ++ ) {
V_217 -> V_220 [ V_173 ] -> V_280 = 0 ;
V_217 -> V_220 [ V_173 ] -> V_281 = 0 ;
}
}
void F_188 ( struct V_216 * V_217 )
{
struct V_24 * V_218 = V_217 -> V_69 ;
struct V_213 * V_214 = F_133 ( V_218 ) ;
int V_173 , V_172 ;
if ( F_130 ( V_214 , 4 ) == 0 ) {
F_187 ( V_217 , L_49 ) ;
return;
}
V_172 = F_189 ( V_214 , V_288 ) ;
if ( V_172 )
F_187 ( V_217 , L_50 ) ;
if ( ! V_172 ) {
V_172 = F_190 ( V_214 , V_288 ) ;
if ( V_172 )
F_187 ( V_217 ,
L_51 ) ;
}
V_172 = F_135 ( V_214 , 1 << 4 , F_136 ( V_218 ) ) ;
if ( V_172 ) {
F_187 ( V_217 , L_52 ) ;
return;
}
V_217 -> V_222 = F_139 ( V_214 ) ;
for ( V_173 = 0 ; V_173 < 2 ; V_173 ++ ) {
struct V_1 * V_2 = V_217 -> V_220 [ V_173 ] ;
void T_2 * V_242 = V_217 -> V_222 [ 4 ] + 8 * V_173 ;
if ( F_134 ( V_2 ) )
continue;
V_2 -> V_3 . V_272 = V_242 ;
if ( ( ! ( V_2 -> V_42 & V_289 ) ) &&
( F_2 ( V_242 + 2 ) & 0x80 ) )
V_217 -> V_42 |= V_290 ;
F_140 ( V_2 , L_53 ,
( unsigned long long ) F_130 ( V_214 , 4 ) + 8 * V_173 ) ;
}
}
int F_157 ( struct V_213 * V_214 ,
const struct F_27 * const * V_225 ,
struct V_216 * * V_226 )
{
int V_172 ;
V_172 = F_142 ( V_214 , V_225 , V_226 ) ;
if ( V_172 )
return V_172 ;
F_188 ( * V_226 ) ;
return 0 ;
}
int F_191 ( struct V_213 * V_214 ,
const struct F_27 * const * V_225 ,
struct V_230 * V_231 , void * V_240 ,
int V_241 )
{
return F_155 ( V_214 , V_225 , V_231 , V_240 , V_241 , 1 ) ;
}
void F_192 ( struct V_1 * V_2 )
{
F_193 ( & V_2 -> V_157 , F_90 ) ;
V_2 -> V_21 = V_291 ;
V_2 -> V_37 = 0xFF ;
}
int T_7 F_194 ( void )
{
V_152 = F_195 ( L_54 , V_292 , V_293 ) ;
if ( ! V_152 )
return - V_228 ;
return 0 ;
}
void F_196 ( void )
{
F_197 ( V_152 ) ;
}
