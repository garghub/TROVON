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
V_70 = F_52 ( V_85 , V_96 ) ;
V_2 -> V_5 -> V_97 ( V_82 -> V_69 , V_70 + V_86 , V_82 -> V_89 ,
V_83 ) ;
F_53 ( V_70 , V_96 ) ;
F_47 ( V_42 ) ;
} else {
V_70 = F_54 ( V_85 ) ;
V_2 -> V_5 -> V_97 ( V_82 -> V_69 , V_70 + V_86 , V_82 -> V_89 ,
V_83 ) ;
}
if ( ! V_83 && ! F_55 ( V_85 ) )
F_56 ( V_85 ) ;
V_82 -> V_87 += V_82 -> V_89 ;
V_82 -> V_93 += V_82 -> V_89 ;
if ( V_82 -> V_93 == V_82 -> V_92 -> V_98 ) {
V_82 -> V_92 = F_57 ( V_82 -> V_92 ) ;
V_82 -> V_93 = 0 ;
}
}
static void F_58 ( struct V_81 * V_82 )
{
if ( F_59 ( & V_82 -> V_40 ) ) {
unsigned int V_56 ;
F_31 ( V_82 -> V_69 -> V_99 == 0 ) ;
V_56 = F_60 ( ( V_82 -> V_88 - V_82 -> V_87 ) / V_82 -> V_89 ,
V_82 -> V_69 -> V_99 ) ;
while ( V_56 -- )
F_48 ( V_82 ) ;
} else
F_48 ( V_82 ) ;
F_5 ( V_82 -> V_2 ) ;
}
static void F_61 ( struct V_1 * V_2 , struct V_81 * V_82 )
{
F_36 ( L_11 ) ;
F_31 ( V_82 -> V_69 -> V_100 < 12 ) ;
V_2 -> V_5 -> V_97 ( V_82 -> V_69 , V_82 -> V_101 , V_82 -> V_69 -> V_100 , 1 ) ;
F_5 ( V_2 ) ;
switch ( V_82 -> V_40 . V_102 ) {
case V_103 :
V_2 -> V_90 = V_104 ;
break;
case V_105 :
V_2 -> V_90 = V_91 ;
break;
#ifdef F_62
case V_106 :
V_2 -> V_90 = V_91 ;
V_2 -> V_5 -> V_107 ( V_82 ) ;
break;
#endif
default:
F_9 () ;
}
}
static int F_63 ( struct V_81 * V_82 , unsigned int V_108 )
{
int V_72 = ( V_82 -> V_40 . V_42 & V_84 ) ? V_109 : V_75 ;
struct V_1 * V_2 = V_82 -> V_2 ;
struct V_68 * V_69 = V_82 -> V_69 ;
struct V_110 * V_111 = & V_69 -> V_19 -> V_112 ;
struct V_113 * V_114 ;
struct V_85 * V_85 ;
unsigned char * V_70 ;
unsigned int V_86 , V_115 , V_80 ;
V_116:
V_114 = V_82 -> V_92 ;
if ( F_41 ( ! V_114 ) ) {
F_64 ( V_111 , L_12
L_13 ,
V_82 -> V_88 , V_82 -> V_87 , V_108 ) ;
return - 1 ;
}
V_85 = F_49 ( V_114 ) ;
V_86 = V_114 -> V_86 + V_82 -> V_93 ;
V_85 = F_50 ( V_85 , ( V_86 >> V_94 ) ) ;
V_86 %= V_95 ;
V_115 = F_60 ( V_114 -> V_98 - V_82 -> V_93 , V_108 ) ;
V_115 = F_60 ( V_115 , ( unsigned int ) V_95 - V_86 ) ;
F_36 ( L_8 , V_82 -> V_40 . V_42 & V_84 ? L_9 : L_10 ) ;
if ( F_51 ( V_85 ) ) {
unsigned long V_42 ;
F_46 ( V_42 ) ;
V_70 = F_52 ( V_85 , V_96 ) ;
V_80 = V_2 -> V_5 -> V_97 ( V_69 , V_70 + V_86 ,
V_115 , V_72 ) ;
F_53 ( V_70 , V_96 ) ;
F_47 ( V_42 ) ;
} else {
V_70 = F_54 ( V_85 ) ;
V_80 = V_2 -> V_5 -> V_97 ( V_69 , V_70 + V_86 ,
V_115 , V_72 ) ;
}
V_108 -= F_60 ( V_108 , V_80 ) ;
V_82 -> V_87 += V_115 ;
V_82 -> V_93 += V_115 ;
if ( V_82 -> V_93 == V_114 -> V_98 ) {
V_82 -> V_92 = F_57 ( V_82 -> V_92 ) ;
V_82 -> V_93 = 0 ;
}
if ( V_108 )
goto V_116;
return 0 ;
}
static void F_65 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_2 ;
struct V_68 * V_69 = V_82 -> V_69 ;
struct V_110 * V_111 = & V_69 -> V_19 -> V_112 ;
unsigned int V_117 , V_118 , V_119 , V_108 ;
int V_120 , V_83 = ( V_82 -> V_40 . V_42 & V_84 ) ? 1 : 0 ;
V_2 -> V_5 -> V_121 ( V_2 , & V_82 -> V_122 ) ;
V_117 = V_82 -> V_122 . V_56 ;
V_118 = V_82 -> V_122 . V_58 ;
V_119 = V_82 -> V_122 . V_59 ;
V_108 = ( V_119 << 8 ) | V_118 ;
if ( F_41 ( V_117 & V_123 ) )
goto V_124;
V_120 = ( ( V_117 & V_125 ) == 0 ) ? 1 : 0 ;
if ( F_41 ( V_83 != V_120 ) )
goto V_124;
if ( F_41 ( ! V_108 ) )
goto V_124;
F_32 ( L_14 , V_2 -> V_64 , V_108 ) ;
if ( F_41 ( F_63 ( V_82 , V_108 ) ) )
goto V_126;
F_5 ( V_2 ) ;
return;
V_124:
F_64 ( V_111 , L_15 ,
V_117 , V_108 ) ;
V_126:
V_82 -> V_127 |= V_128 ;
V_2 -> V_90 = V_129 ;
}
static inline int F_66 ( struct V_1 * V_2 ,
struct V_81 * V_82 )
{
if ( V_82 -> V_40 . V_42 & V_130 )
return 1 ;
if ( V_2 -> V_90 == V_131 ) {
if ( V_82 -> V_40 . V_102 == V_132 &&
( V_82 -> V_40 . V_42 & V_84 ) )
return 1 ;
if ( F_67 ( V_82 -> V_40 . V_102 ) &&
! ( V_82 -> V_69 -> V_42 & V_133 ) )
return 1 ;
}
return 0 ;
}
static void F_68 ( struct V_81 * V_82 , int V_134 )
{
struct V_1 * V_2 = V_82 -> V_2 ;
unsigned long V_42 ;
if ( V_2 -> V_5 -> V_135 ) {
if ( V_134 ) {
F_69 ( V_2 -> V_136 , V_42 ) ;
V_82 = F_70 ( V_2 , V_82 -> V_137 ) ;
if ( V_82 ) {
if ( F_34 ( ! ( V_82 -> V_127 & V_128 ) ) ) {
F_29 ( V_2 ) ;
F_71 ( V_82 ) ;
} else
F_72 ( V_2 ) ;
}
F_73 ( V_2 -> V_136 , V_42 ) ;
} else {
if ( F_34 ( ! ( V_82 -> V_127 & V_128 ) ) )
F_71 ( V_82 ) ;
else
F_72 ( V_2 ) ;
}
} else {
if ( V_134 ) {
F_69 ( V_2 -> V_136 , V_42 ) ;
F_29 ( V_2 ) ;
F_71 ( V_82 ) ;
F_73 ( V_2 -> V_136 , V_42 ) ;
} else
F_71 ( V_82 ) ;
}
}
int F_74 ( struct V_1 * V_2 , struct V_81 * V_82 ,
T_1 V_8 , int V_134 )
{
struct V_18 * V_19 = V_82 -> V_69 -> V_19 ;
struct V_110 * V_111 = & V_19 -> V_112 ;
unsigned long V_42 = 0 ;
int V_138 ;
F_31 ( ( V_82 -> V_42 & V_139 ) == 0 ) ;
F_31 ( V_134 != F_66 ( V_2 , V_82 ) ) ;
V_140:
F_36 ( L_16 ,
V_2 -> V_64 , V_82 -> V_40 . V_102 , V_2 -> V_90 , V_8 ) ;
switch ( V_2 -> V_90 ) {
case V_131 :
V_138 = ( V_82 -> V_40 . V_42 & V_130 ) ;
if ( F_41 ( ( V_8 & V_141 ) == 0 ) ) {
if ( F_34 ( V_8 & ( V_142 | V_143 ) ) )
V_82 -> V_127 |= V_144 ;
else {
F_64 ( V_111 ,
L_17 ) ;
V_82 -> V_127 |= V_128 ;
}
V_2 -> V_90 = V_129 ;
goto V_140;
}
if ( F_41 ( V_8 & ( V_142 | V_143 ) ) ) {
if ( ! ( V_82 -> V_69 -> V_145 & V_146 ) ) {
F_64 ( V_111 , L_18
L_19
L_20 , V_8 ) ;
V_82 -> V_127 |= V_128 ;
V_2 -> V_90 = V_129 ;
goto V_140;
}
}
if ( V_134 )
F_69 ( V_2 -> V_136 , V_42 ) ;
if ( V_82 -> V_40 . V_102 == V_132 ) {
V_2 -> V_90 = V_104 ;
F_58 ( V_82 ) ;
} else
F_61 ( V_2 , V_82 ) ;
if ( V_134 )
F_73 ( V_2 -> V_136 , V_42 ) ;
break;
case V_104 :
if ( V_82 -> V_40 . V_102 == V_103 ) {
if ( ( V_8 & V_141 ) == 0 ) {
V_2 -> V_90 = V_91 ;
goto V_140;
}
if ( F_41 ( V_8 & ( V_142 | V_143 ) ) ) {
F_64 ( V_111 , L_21
L_19
L_20 , V_8 ) ;
V_82 -> V_127 |= V_128 ;
V_2 -> V_90 = V_129 ;
goto V_140;
}
F_65 ( V_82 ) ;
if ( F_41 ( V_2 -> V_90 == V_129 ) )
goto V_140;
} else {
if ( F_41 ( ( V_8 & V_141 ) == 0 ) ) {
if ( F_34 ( V_8 & ( V_142 | V_143 ) ) ) {
V_82 -> V_127 |= V_144 ;
if ( V_82 -> V_69 -> V_145 &
V_147 )
V_82 -> V_127 |=
V_148 ;
} else {
F_64 ( V_111 , L_22
L_23
L_20 , V_8 ) ;
V_82 -> V_127 |= V_128 |
V_148 ;
}
V_2 -> V_90 = V_129 ;
goto V_140;
}
if ( F_41 ( V_8 & ( V_142 | V_143 ) ) ) {
V_82 -> V_127 |= V_144 ;
if ( ! ( V_82 -> V_40 . V_42 & V_84 ) ) {
F_58 ( V_82 ) ;
V_8 = F_28 ( V_2 ) ;
}
if ( V_8 & ( V_9 | V_141 ) ) {
F_64 ( V_111 , L_22
L_24
L_20 , V_8 ) ;
V_82 -> V_127 |= V_128 ;
}
if ( V_8 == 0x7f )
V_82 -> V_127 |= V_148 ;
V_2 -> V_90 = V_129 ;
goto V_140;
}
F_58 ( V_82 ) ;
if ( V_2 -> V_90 == V_91 &&
( ! ( V_82 -> V_40 . V_42 & V_84 ) ) ) {
V_8 = F_28 ( V_2 ) ;
goto V_140;
}
}
V_138 = 1 ;
break;
case V_91 :
if ( F_41 ( ! F_75 ( V_8 ) ) ) {
V_82 -> V_127 |= F_76 ( V_8 ) ;
V_2 -> V_90 = V_129 ;
goto V_140;
}
F_36 ( L_25 ,
V_2 -> V_64 , V_82 -> V_69 -> V_149 , V_8 ) ;
F_31 ( V_82 -> V_127 & ( V_144 | V_128 ) ) ;
V_2 -> V_90 = V_150 ;
F_68 ( V_82 , V_134 ) ;
V_138 = 0 ;
break;
case V_129 :
V_2 -> V_90 = V_150 ;
F_68 ( V_82 , V_134 ) ;
V_138 = 0 ;
break;
default:
V_138 = 0 ;
F_9 () ;
}
return V_138 ;
}
void F_77 ( struct V_151 * V_152 )
{
F_78 ( V_153 , V_152 ) ;
}
void F_79 ( struct V_154 * V_155 , unsigned long V_156 )
{
F_80 ( V_153 , V_155 , V_156 ) ;
}
void F_81 ( struct V_18 * V_19 , unsigned long V_156 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_82 ( ( V_2 -> V_157 != NULL ) &&
( V_2 -> V_157 != V_19 ) ) ;
V_2 -> V_157 = V_19 ;
F_79 ( & V_2 -> V_158 , F_83 ( V_156 ) ) ;
}
void F_84 ( struct V_1 * V_2 )
{
F_36 ( L_26 ) ;
F_85 ( & V_2 -> V_158 ) ;
V_2 -> V_90 = V_150 ;
V_2 -> V_157 = NULL ;
if ( F_86 ( V_2 ) )
F_87 ( V_2 , L_27 , V_159 ) ;
}
static void F_88 ( struct V_151 * V_152 )
{
struct V_1 * V_2 =
F_89 ( V_152 , struct V_1 , V_158 . V_152 ) ;
struct V_18 * V_19 = V_2 -> V_157 ;
struct V_81 * V_82 ;
T_1 V_8 ;
int V_138 ;
F_90 ( V_2 -> V_157 == NULL ) ;
V_82 = F_70 ( V_2 , V_19 -> V_160 ) ;
if ( ! V_82 ) {
V_2 -> V_157 = NULL ;
return;
}
V_140:
F_31 ( V_2 -> V_90 == V_150 ) ;
V_8 = F_11 ( V_2 , V_9 , 5 ) ;
if ( V_8 & V_9 ) {
F_14 ( V_2 , 2 ) ;
V_8 = F_11 ( V_2 , V_9 , 10 ) ;
if ( V_8 & V_9 ) {
F_81 ( V_19 , V_161 ) ;
return;
}
}
V_2 -> V_157 = NULL ;
V_138 = F_74 ( V_2 , V_82 , V_8 , 1 ) ;
if ( V_138 )
goto V_140;
}
unsigned int F_91 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_2 ;
struct V_18 * V_19 = V_82 -> V_69 -> V_19 ;
if ( V_2 -> V_42 & V_162 )
V_82 -> V_40 . V_42 |= V_130 ;
F_25 ( V_2 , V_82 -> V_69 -> V_149 , 1 , 0 ) ;
switch ( V_82 -> V_40 . V_102 ) {
case V_163 :
if ( V_82 -> V_40 . V_42 & V_130 )
F_92 ( V_82 ) ;
F_37 ( V_2 , & V_82 -> V_40 ) ;
V_2 -> V_90 = V_91 ;
if ( V_82 -> V_40 . V_42 & V_130 )
F_81 ( V_19 , 0 ) ;
break;
case V_132 :
if ( V_82 -> V_40 . V_42 & V_130 )
F_92 ( V_82 ) ;
F_37 ( V_2 , & V_82 -> V_40 ) ;
if ( V_82 -> V_40 . V_42 & V_84 ) {
V_2 -> V_90 = V_131 ;
F_81 ( V_19 , 0 ) ;
} else {
V_2 -> V_90 = V_104 ;
if ( V_82 -> V_40 . V_42 & V_130 )
F_81 ( V_19 , 0 ) ;
}
break;
case V_103 :
case V_105 :
if ( V_82 -> V_40 . V_42 & V_130 )
F_92 ( V_82 ) ;
F_37 ( V_2 , & V_82 -> V_40 ) ;
V_2 -> V_90 = V_131 ;
if ( ( ! ( V_82 -> V_69 -> V_42 & V_133 ) ) ||
( V_82 -> V_40 . V_42 & V_130 ) )
F_81 ( V_19 , 0 ) ;
break;
default:
F_31 ( 1 ) ;
return V_164 ;
}
return 0 ;
}
bool F_93 ( struct V_81 * V_82 )
{
V_82 -> V_2 -> V_5 -> V_121 ( V_82 -> V_2 , & V_82 -> V_122 ) ;
return true ;
}
static unsigned int F_94 ( struct V_1 * V_2 )
{
V_2 -> V_165 . V_166 ++ ;
#ifdef F_95
if ( ( V_2 -> V_165 . V_166 % 1000 ) == 0 ) {
V_2 -> V_5 -> V_10 ( V_2 ) ;
if ( V_2 -> V_5 -> V_38 )
V_2 -> V_5 -> V_38 ( V_2 ) ;
F_15 ( V_2 , L_28 ) ;
return 1 ;
}
#endif
return 0 ;
}
static unsigned int F_96 ( struct V_1 * V_2 ,
struct V_81 * V_82 ,
bool V_167 )
{
T_1 V_8 ;
F_32 ( L_29 ,
V_2 -> V_64 , V_82 -> V_40 . V_102 , V_2 -> V_90 ) ;
switch ( V_2 -> V_90 ) {
case V_131 :
if ( ! ( V_82 -> V_69 -> V_42 & V_133 ) )
return F_94 ( V_2 ) ;
break;
case V_150 :
return F_94 ( V_2 ) ;
default:
break;
}
V_8 = F_4 ( V_2 ) ;
if ( V_8 & V_9 ) {
if ( V_167 ) {
V_82 -> V_127 |= V_128 ;
V_2 -> V_90 = V_129 ;
} else
return F_94 ( V_2 ) ;
}
if ( V_2 -> V_5 -> V_38 )
V_2 -> V_5 -> V_38 ( V_2 ) ;
F_74 ( V_2 , V_82 , V_8 , 0 ) ;
return 1 ;
}
unsigned int F_97 ( struct V_1 * V_2 , struct V_81 * V_82 )
{
return F_96 ( V_2 , V_82 , false ) ;
}
T_3 F_98 ( int V_168 , void * V_169 )
{
return F_99 ( V_168 , V_169 , F_97 ) ;
}
void F_100 ( struct V_1 * V_2 )
{
T_1 V_8 ;
struct V_81 * V_82 ;
V_82 = F_70 ( V_2 , V_2 -> V_19 . V_160 ) ;
if ( ! V_82 || V_82 -> V_40 . V_42 & V_130 )
return;
V_8 = F_3 ( V_2 ) ;
if ( V_8 & V_9 )
return;
F_15 ( V_2 , L_30 ,
V_8 ) ;
F_97 ( V_2 , V_82 ) ;
}
void F_101 ( struct V_1 * V_2 )
{
V_2 -> V_21 |= V_36 ;
V_2 -> V_37 = V_2 -> V_21 ;
if ( V_2 -> V_5 -> V_22 || V_2 -> V_3 . V_23 )
F_22 ( V_2 , V_2 -> V_21 ) ;
V_2 -> V_5 -> V_10 ( V_2 ) ;
if ( V_2 -> V_5 -> V_38 )
V_2 -> V_5 -> V_38 ( V_2 ) ;
}
void F_102 ( struct V_1 * V_2 )
{
V_2 -> V_5 -> V_10 ( V_2 ) ;
if ( V_2 -> V_5 -> V_38 )
V_2 -> V_5 -> V_38 ( V_2 ) ;
F_29 ( V_2 ) ;
}
int F_103 ( struct V_18 * V_19 , unsigned long V_20 )
{
struct V_170 * V_171 = & V_19 -> V_172 ;
int V_173 ;
V_173 = F_104 ( V_19 , V_20 ) ;
if ( V_173 )
return V_173 ;
if ( V_171 -> V_174 . V_175 & V_176 )
return 0 ;
if ( ! F_105 ( V_19 ) ) {
V_173 = F_20 ( V_19 , V_20 ) ;
if ( V_173 && V_173 != - V_16 ) {
F_106 ( V_19 ,
L_31 ,
V_173 ) ;
V_171 -> V_174 . V_175 |= V_176 ;
}
}
return 0 ;
}
static unsigned int F_107 ( struct V_1 * V_2 , unsigned int V_24 )
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
unsigned int F_108 ( struct V_68 * V_69 , int V_177 ,
T_1 * V_178 )
{
struct V_1 * V_2 = V_69 -> V_19 -> V_2 ;
struct V_39 V_40 ;
unsigned int V_32 ;
T_1 V_179 ;
V_2 -> V_5 -> V_31 ( V_2 , V_69 -> V_149 ) ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_2 -> V_5 -> V_121 ( V_2 , & V_40 ) ;
V_179 = V_40 . V_55 ;
if ( V_178 )
* V_178 = V_179 ;
if ( V_179 == 0 )
V_69 -> V_145 |= V_147 ;
else if ( V_179 == 1 )
;
else if ( ( V_69 -> V_149 == 0 ) && ( V_179 == 0x81 ) )
;
else
return V_180 ;
V_32 = F_109 ( & V_40 ) ;
if ( V_32 == V_181 ) {
if ( V_177 && ( V_69 -> V_145 & V_147 ) )
V_32 = V_182 ;
else
V_32 = V_180 ;
} else if ( ( V_32 == V_182 ) &&
( V_2 -> V_5 -> V_10 ( V_2 ) == 0 ) )
V_32 = V_180 ;
return V_32 ;
}
int F_110 ( struct V_18 * V_19 , unsigned int V_183 ,
unsigned long V_20 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_34 * V_3 = & V_2 -> V_3 ;
unsigned int V_184 = V_183 & ( 1 << 0 ) ;
unsigned int V_185 = V_183 & ( 1 << 1 ) ;
int V_173 , V_186 = 0 ;
F_14 ( V_2 , V_187 ) ;
V_173 = F_20 ( V_19 , V_20 ) ;
if ( V_173 )
return V_173 ;
if ( V_185 ) {
int V_174 ;
V_2 -> V_5 -> V_31 ( V_2 , 1 ) ;
for ( V_174 = 0 ; V_174 < 2 ; V_174 ++ ) {
T_1 V_56 , V_57 ;
V_56 = F_2 ( V_3 -> V_48 ) ;
V_57 = F_2 ( V_3 -> V_50 ) ;
if ( ( V_56 == 1 ) && ( V_57 == 1 ) )
break;
F_14 ( V_2 , 50 ) ;
}
V_173 = F_20 ( V_19 , V_20 ) ;
if ( V_173 ) {
if ( V_173 != - V_16 )
return V_173 ;
V_186 = V_173 ;
}
}
V_2 -> V_5 -> V_31 ( V_2 , 0 ) ;
if ( V_185 )
V_2 -> V_5 -> V_31 ( V_2 , 1 ) ;
if ( V_184 )
V_2 -> V_5 -> V_31 ( V_2 , 0 ) ;
return V_186 ;
}
static int F_111 ( struct V_1 * V_2 , unsigned int V_183 ,
unsigned long V_20 )
{
struct V_34 * V_3 = & V_2 -> V_3 ;
F_36 ( L_32 , V_2 -> V_64 ) ;
F_23 ( V_2 -> V_21 , V_3 -> V_23 ) ;
F_112 ( 20 ) ;
F_23 ( V_2 -> V_21 | V_188 , V_3 -> V_23 ) ;
F_112 ( 20 ) ;
F_23 ( V_2 -> V_21 , V_3 -> V_23 ) ;
V_2 -> V_37 = V_2 -> V_21 ;
return F_110 ( & V_2 -> V_19 , V_183 , V_20 ) ;
}
int F_113 ( struct V_18 * V_19 , unsigned int * V_189 ,
unsigned long V_20 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_190 = V_2 -> V_42 & V_191 ;
unsigned int V_183 = 0 ;
int V_173 ;
T_1 V_179 ;
F_36 ( L_26 ) ;
if ( F_107 ( V_2 , 0 ) )
V_183 |= ( 1 << 0 ) ;
if ( V_190 && F_107 ( V_2 , 1 ) )
V_183 |= ( 1 << 1 ) ;
V_2 -> V_5 -> V_31 ( V_2 , 0 ) ;
F_36 ( L_33 , V_183 ) ;
V_173 = F_111 ( V_2 , V_183 , V_20 ) ;
if ( V_173 && ( V_173 != - V_16 || F_114 ( V_19 ) ) ) {
F_115 ( V_19 , L_34 , V_173 ) ;
return V_173 ;
}
V_189 [ 0 ] = F_108 ( & V_19 -> V_24 [ 0 ] ,
V_183 & ( 1 << 0 ) , & V_179 ) ;
if ( V_190 && V_179 != 0x81 )
V_189 [ 1 ] = F_108 ( & V_19 -> V_24 [ 1 ] ,
V_183 & ( 1 << 1 ) , & V_179 ) ;
F_36 ( L_35 , V_189 [ 0 ] , V_189 [ 1 ] ) ;
return 0 ;
}
int F_116 ( struct V_18 * V_19 , unsigned int * V_32 ,
unsigned long V_20 )
{
struct V_170 * V_171 = & V_19 -> V_172 ;
const unsigned long * V_192 = F_117 ( V_171 ) ;
bool V_193 ;
int V_173 ;
V_173 = F_118 ( V_19 , V_192 , V_20 , & V_193 ,
F_18 ) ;
if ( V_193 )
* V_32 = F_108 ( V_19 -> V_24 , 1 , NULL ) ;
F_36 ( L_36 , * V_32 ) ;
return V_173 ;
}
void F_119 ( struct V_18 * V_19 , unsigned int * V_189 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_120 ( V_19 , V_189 ) ;
if ( V_189 [ 0 ] != V_180 )
V_2 -> V_5 -> V_31 ( V_2 , 1 ) ;
if ( V_189 [ 1 ] != V_180 )
V_2 -> V_5 -> V_31 ( V_2 , 0 ) ;
if ( V_189 [ 0 ] == V_180 && V_189 [ 1 ] == V_180 ) {
F_36 ( L_37 ) ;
return;
}
if ( V_2 -> V_5 -> V_22 || V_2 -> V_3 . V_23 ) {
F_22 ( V_2 , V_2 -> V_21 ) ;
V_2 -> V_37 = V_2 -> V_21 ;
}
}
void F_121 ( struct V_81 * V_82 )
{
int V_115 ;
struct V_1 * V_2 ;
if ( V_82 == NULL || V_82 -> V_194 == V_195 )
return;
V_2 = V_82 -> V_2 ;
for ( V_115 = 0 ; ( V_2 -> V_5 -> V_10 ( V_2 ) & V_141 )
&& V_115 < 65536 ; V_115 += 2 )
F_122 ( V_2 -> V_3 . V_73 ) ;
if ( V_115 )
F_87 ( V_2 , L_38 , V_115 ) ;
}
void F_123 ( struct V_1 * V_2 )
{
T_4 V_196 = V_2 -> V_5 -> V_196 ;
T_4 V_197 = V_2 -> V_5 -> V_197 ;
struct V_81 * V_82 ;
unsigned long V_42 ;
V_82 = F_124 ( V_2 , V_2 -> V_19 . V_160 ) ;
if ( V_82 && ! ( V_82 -> V_42 & V_198 ) )
V_82 = NULL ;
F_69 ( V_2 -> V_136 , V_42 ) ;
if ( V_2 -> V_5 -> V_199 )
V_2 -> V_5 -> V_199 ( V_82 ) ;
F_73 ( V_2 -> V_136 , V_42 ) ;
if ( V_196 == F_113 && ! V_2 -> V_3 . V_23 )
V_196 = NULL ;
if ( ( V_197 == V_200 ||
V_197 == F_116 ) && ! F_114 ( & V_2 -> V_19 ) )
V_197 = NULL ;
F_125 ( V_2 , V_2 -> V_5 -> V_201 , V_196 , V_197 ,
V_2 -> V_5 -> V_202 ) ;
}
void F_126 ( struct V_34 * V_3 )
{
V_3 -> V_73 = V_3 -> V_203 + V_204 ;
V_3 -> V_62 = V_3 -> V_203 + V_205 ;
V_3 -> V_46 = V_3 -> V_203 + V_206 ;
V_3 -> V_48 = V_3 -> V_203 + V_207 ;
V_3 -> V_50 = V_3 -> V_203 + V_208 ;
V_3 -> V_52 = V_3 -> V_203 + V_209 ;
V_3 -> V_54 = V_3 -> V_203 + V_210 ;
V_3 -> V_28 = V_3 -> V_203 + V_211 ;
V_3 -> V_4 = V_3 -> V_203 + V_212 ;
V_3 -> V_65 = V_3 -> V_203 + V_213 ;
}
static int F_127 ( struct V_214 * V_215 , int V_216 )
{
int V_174 ;
V_216 = V_216 * 2 ;
for ( V_174 = 0 ; V_174 < 2 ; V_174 ++ ) {
if ( F_128 ( V_215 , V_216 + V_174 ) == 0 ||
F_129 ( V_215 , V_216 + V_174 ) == 0 )
return 0 ;
}
return 1 ;
}
int F_130 ( struct V_217 * V_218 )
{
struct V_24 * V_219 = V_218 -> V_69 ;
struct V_214 * V_215 = F_131 ( V_219 ) ;
unsigned int V_220 = 0 ;
int V_174 , V_173 ;
for ( V_174 = 0 ; V_174 < 2 ; V_174 ++ ) {
struct V_1 * V_2 = V_218 -> V_221 [ V_174 ] ;
int V_222 = V_174 * 2 ;
void T_2 * const * V_223 ;
if ( F_132 ( V_2 ) )
continue;
if ( ! F_127 ( V_215 , V_174 ) ) {
V_2 -> V_5 = & V_224 ;
continue;
}
V_173 = F_133 ( V_215 , 0x3 << V_222 ,
F_134 ( V_219 ) ) ;
if ( V_173 ) {
F_135 ( V_219 ,
L_39 ,
V_174 , V_173 ) ;
if ( V_173 == - V_17 )
F_136 ( V_215 ) ;
V_2 -> V_5 = & V_224 ;
continue;
}
V_218 -> V_223 = V_223 = F_137 ( V_215 ) ;
V_2 -> V_3 . V_203 = V_223 [ V_222 ] ;
V_2 -> V_3 . V_7 =
V_2 -> V_3 . V_23 = ( void T_2 * )
( ( unsigned long ) V_223 [ V_222 + 1 ] | V_225 ) ;
F_126 ( & V_2 -> V_3 ) ;
F_138 ( V_2 , L_40 ,
( unsigned long long ) F_128 ( V_215 , V_222 ) ,
( unsigned long long ) F_128 ( V_215 , V_222 + 1 ) ) ;
V_220 |= 1 << V_174 ;
}
if ( ! V_220 ) {
F_139 ( V_219 , L_41 ) ;
return - V_16 ;
}
return 0 ;
}
int F_140 ( struct V_214 * V_215 ,
const struct F_27 * const * V_226 ,
struct V_217 * * V_227 )
{
struct V_217 * V_218 ;
int V_173 ;
if ( ! F_141 ( & V_215 -> V_69 , NULL , V_228 ) )
return - V_229 ;
V_218 = F_142 ( & V_215 -> V_69 , V_226 , 2 ) ;
if ( ! V_218 ) {
F_139 ( & V_215 -> V_69 , L_42 ) ;
V_173 = - V_229 ;
goto V_126;
}
V_173 = F_130 ( V_218 ) ;
if ( V_173 )
goto V_126;
F_143 ( & V_215 -> V_69 , NULL ) ;
* V_227 = V_218 ;
return 0 ;
V_126:
F_144 ( & V_215 -> V_69 , NULL ) ;
return V_173 ;
}
int F_145 ( struct V_217 * V_218 ,
T_5 V_230 ,
struct V_231 * V_232 )
{
struct V_24 * V_69 = V_218 -> V_69 ;
struct V_214 * V_215 = F_131 ( V_69 ) ;
const char * V_233 = F_134 ( V_218 -> V_69 ) ;
int V_234 = 0 , V_173 ;
V_173 = F_146 ( V_218 ) ;
if ( V_173 )
return V_173 ;
if ( ( V_215 -> V_32 >> 8 ) == V_235 ) {
T_1 V_236 , V_220 ;
F_147 ( V_215 , V_237 , & V_236 ) ;
V_220 = ( 1 << 2 ) | ( 1 << 0 ) ;
if ( ( V_236 & V_220 ) != V_220 )
V_234 = 1 ;
#if F_148 ( V_238 )
if ( V_234 ) {
F_149 ( V_239 L_43 ) ;
return - V_240 ;
}
#endif
}
if ( ! F_141 ( V_69 , NULL , V_228 ) )
return - V_229 ;
if ( ! V_234 && V_215 -> V_168 ) {
int V_174 ;
V_173 = F_150 ( V_69 , V_215 -> V_168 , V_230 ,
V_241 , V_233 , V_218 ) ;
if ( V_173 )
goto V_242;
for ( V_174 = 0 ; V_174 < 2 ; V_174 ++ ) {
if ( F_132 ( V_218 -> V_221 [ V_174 ] ) )
continue;
F_138 ( V_218 -> V_221 [ V_174 ] , L_44 , V_215 -> V_168 ) ;
}
} else if ( V_234 ) {
if ( ! F_132 ( V_218 -> V_221 [ 0 ] ) ) {
V_173 = F_150 ( V_69 , F_151 ( V_215 ) ,
V_230 , V_241 ,
V_233 , V_218 ) ;
if ( V_173 )
goto V_242;
F_138 ( V_218 -> V_221 [ 0 ] , L_44 ,
F_151 ( V_215 ) ) ;
}
if ( ! F_132 ( V_218 -> V_221 [ 1 ] ) ) {
V_173 = F_150 ( V_69 , F_152 ( V_215 ) ,
V_230 , V_241 ,
V_233 , V_218 ) ;
if ( V_173 )
goto V_242;
F_138 ( V_218 -> V_221 [ 1 ] , L_44 ,
F_152 ( V_215 ) ) ;
}
}
V_173 = F_153 ( V_218 , V_232 ) ;
V_242:
if ( V_173 == 0 )
F_143 ( V_69 , NULL ) ;
else
F_144 ( V_69 , NULL ) ;
return V_173 ;
}
static const struct F_27 * F_154 (
const struct F_27 * const * V_226 )
{
int V_174 ;
for ( V_174 = 0 ; V_174 < 2 && V_226 [ V_174 ] ; V_174 ++ )
if ( V_226 [ V_174 ] -> V_243 != & V_224 )
return V_226 [ V_174 ] ;
return NULL ;
}
static int F_155 ( struct V_214 * V_215 ,
const struct F_27 * const * V_226 ,
struct V_231 * V_232 , void * V_244 ,
int V_245 , bool V_246 )
{
struct V_24 * V_69 = & V_215 -> V_69 ;
const struct F_27 * V_247 ;
struct V_217 * V_218 = NULL ;
int V_173 ;
F_36 ( L_26 ) ;
V_247 = F_154 ( V_226 ) ;
if ( ! V_247 ) {
F_139 ( & V_215 -> V_69 , L_45 ) ;
return - V_248 ;
}
if ( ! F_141 ( V_69 , NULL , V_228 ) )
return - V_229 ;
V_173 = F_156 ( V_215 ) ;
if ( V_173 )
goto V_242;
#ifdef F_62
if ( V_246 )
V_173 = F_157 ( V_215 , V_226 , & V_218 ) ;
else
#endif
V_173 = F_140 ( V_215 , V_226 , & V_218 ) ;
if ( V_173 )
goto V_242;
V_218 -> V_249 = V_244 ;
V_218 -> V_42 |= V_245 ;
#ifdef F_62
if ( V_246 ) {
F_158 ( V_215 ) ;
V_173 = F_145 ( V_218 , V_250 , V_232 ) ;
} else
#endif
V_173 = F_145 ( V_218 , F_98 , V_232 ) ;
V_242:
if ( V_173 == 0 )
F_143 ( & V_215 -> V_69 , NULL ) ;
else
F_144 ( & V_215 -> V_69 , NULL ) ;
return V_173 ;
}
int F_159 ( struct V_214 * V_215 ,
const struct F_27 * const * V_226 ,
struct V_231 * V_232 , void * V_244 , int V_251 )
{
return F_155 ( V_215 , V_226 , V_232 , V_244 , V_251 , 0 ) ;
}
static void F_160 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_2 ;
struct V_252 * V_253 = V_2 -> V_254 ;
struct V_113 * V_114 ;
unsigned int V_255 , V_247 ;
V_247 = 0 ;
F_161 (qc->sg, sg, qc->n_elem, si) {
T_6 V_256 , V_86 ;
T_6 V_257 , V_258 ;
V_256 = ( T_6 ) F_162 ( V_114 ) ;
V_257 = F_163 ( V_114 ) ;
while ( V_257 ) {
V_86 = V_256 & 0xffff ;
V_258 = V_257 ;
if ( ( V_86 + V_257 ) > 0x10000 )
V_258 = 0x10000 - V_86 ;
V_253 [ V_247 ] . V_256 = F_164 ( V_256 ) ;
V_253 [ V_247 ] . V_259 = F_164 ( V_258 & 0xffff ) ;
F_32 ( L_46 , V_247 , V_256 , V_258 ) ;
V_247 ++ ;
V_257 -= V_258 ;
V_256 += V_258 ;
}
}
V_253 [ V_247 - 1 ] . V_259 |= F_164 ( V_260 ) ;
}
static void F_165 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_2 ;
struct V_252 * V_253 = V_2 -> V_254 ;
struct V_113 * V_114 ;
unsigned int V_255 , V_247 ;
V_247 = 0 ;
F_161 (qc->sg, sg, qc->n_elem, si) {
T_6 V_256 , V_86 ;
T_6 V_257 , V_258 , V_261 ;
V_256 = ( T_6 ) F_162 ( V_114 ) ;
V_257 = F_163 ( V_114 ) ;
while ( V_257 ) {
V_86 = V_256 & 0xffff ;
V_258 = V_257 ;
if ( ( V_86 + V_257 ) > 0x10000 )
V_258 = 0x10000 - V_86 ;
V_261 = V_258 & 0xffff ;
V_253 [ V_247 ] . V_256 = F_164 ( V_256 ) ;
if ( V_261 == 0 ) {
V_253 [ V_247 ] . V_259 = F_164 ( 0x8000 ) ;
V_261 = 0x8000 ;
V_253 [ ++ V_247 ] . V_256 = F_164 ( V_256 + 0x8000 ) ;
}
V_253 [ V_247 ] . V_259 = F_164 ( V_261 ) ;
F_32 ( L_46 , V_247 , V_256 , V_258 ) ;
V_247 ++ ;
V_257 -= V_258 ;
V_256 += V_258 ;
}
}
V_253 [ V_247 - 1 ] . V_259 |= F_164 ( V_260 ) ;
}
void F_166 ( struct V_81 * V_82 )
{
if ( ! ( V_82 -> V_42 & V_262 ) )
return;
F_160 ( V_82 ) ;
}
void F_167 ( struct V_81 * V_82 )
{
if ( ! ( V_82 -> V_42 & V_262 ) )
return;
F_165 ( V_82 ) ;
}
unsigned int F_168 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_2 ;
struct V_18 * V_19 = V_82 -> V_69 -> V_19 ;
if ( ! F_169 ( V_82 -> V_40 . V_102 ) )
return F_91 ( V_82 ) ;
F_25 ( V_2 , V_82 -> V_69 -> V_149 , 1 , 0 ) ;
switch ( V_82 -> V_40 . V_102 ) {
case V_263 :
F_31 ( V_82 -> V_40 . V_42 & V_130 ) ;
V_2 -> V_5 -> V_66 ( V_2 , & V_82 -> V_40 ) ;
V_2 -> V_5 -> V_264 ( V_82 ) ;
V_2 -> V_5 -> V_107 ( V_82 ) ;
V_2 -> V_90 = V_91 ;
break;
case V_106 :
F_31 ( V_82 -> V_40 . V_42 & V_130 ) ;
V_2 -> V_5 -> V_66 ( V_2 , & V_82 -> V_40 ) ;
V_2 -> V_5 -> V_264 ( V_82 ) ;
V_2 -> V_90 = V_131 ;
if ( ! ( V_82 -> V_69 -> V_42 & V_133 ) )
F_81 ( V_19 , 0 ) ;
break;
default:
F_82 ( 1 ) ;
return V_164 ;
}
return 0 ;
}
unsigned int F_170 ( struct V_1 * V_2 , struct V_81 * V_82 )
{
struct V_110 * V_111 = & V_2 -> V_19 . V_112 ;
T_1 V_265 = 0 ;
bool V_266 = false ;
unsigned int V_267 ;
if ( V_2 -> V_90 == V_91 && F_169 ( V_82 -> V_40 . V_102 ) ) {
V_265 = V_2 -> V_5 -> V_268 ( V_2 ) ;
F_32 ( L_47 , V_2 -> V_64 , V_265 ) ;
if ( ! ( V_265 & V_269 ) )
return F_94 ( V_2 ) ;
V_2 -> V_5 -> V_270 ( V_82 ) ;
V_266 = true ;
if ( F_41 ( V_265 & V_271 ) ) {
V_82 -> V_127 |= V_272 ;
V_2 -> V_90 = V_129 ;
}
}
V_267 = F_96 ( V_2 , V_82 , V_266 ) ;
if ( F_41 ( V_82 -> V_127 ) && F_169 ( V_82 -> V_40 . V_102 ) )
F_64 ( V_111 , L_48 , V_265 ) ;
return V_267 ;
}
T_3 V_250 ( int V_168 , void * V_169 )
{
return F_99 ( V_168 , V_169 , F_170 ) ;
}
void F_171 ( struct V_1 * V_2 )
{
struct V_81 * V_82 ;
unsigned long V_42 ;
bool V_273 = false ;
V_82 = F_124 ( V_2 , V_2 -> V_19 . V_160 ) ;
if ( V_82 && ! ( V_82 -> V_42 & V_198 ) )
V_82 = NULL ;
F_69 ( V_2 -> V_136 , V_42 ) ;
if ( V_82 && F_169 ( V_82 -> V_40 . V_102 ) ) {
T_1 V_265 ;
V_265 = V_2 -> V_5 -> V_268 ( V_2 ) ;
if ( V_82 -> V_127 == V_274 && ( V_265 & V_271 ) ) {
V_82 -> V_127 = V_272 ;
V_273 = true ;
}
V_2 -> V_5 -> V_270 ( V_82 ) ;
if ( V_273 ) {
V_2 -> V_5 -> V_10 ( V_2 ) ;
if ( V_2 -> V_5 -> V_38 )
V_2 -> V_5 -> V_38 ( V_2 ) ;
}
}
F_73 ( V_2 -> V_136 , V_42 ) ;
if ( V_273 )
F_172 ( V_2 ) ;
F_123 ( V_2 ) ;
}
void F_173 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_2 ;
unsigned long V_42 ;
if ( F_169 ( V_82 -> V_40 . V_102 ) ) {
F_69 ( V_2 -> V_136 , V_42 ) ;
V_2 -> V_5 -> V_270 ( V_82 ) ;
F_73 ( V_2 -> V_136 , V_42 ) ;
}
}
void F_174 ( struct V_1 * V_2 )
{
void T_2 * V_275 = V_2 -> V_3 . V_276 ;
if ( ! V_275 )
return;
F_23 ( F_2 ( V_275 + V_277 ) , V_275 + V_277 ) ;
}
void F_175 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_2 ;
unsigned int V_72 = ( V_82 -> V_40 . V_42 & V_84 ) ;
T_1 V_278 ;
F_176 () ;
F_177 ( V_2 -> V_279 , V_2 -> V_3 . V_276 + V_280 ) ;
V_278 = F_2 ( V_2 -> V_3 . V_276 + V_281 ) ;
V_278 &= ~ ( V_282 | V_283 ) ;
if ( ! V_72 )
V_278 |= V_282 ;
F_23 ( V_278 , V_2 -> V_3 . V_276 + V_281 ) ;
V_2 -> V_5 -> V_67 ( V_2 , & V_82 -> V_40 ) ;
}
void F_178 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_2 ;
T_1 V_278 ;
V_278 = F_2 ( V_2 -> V_3 . V_276 + V_281 ) ;
F_23 ( V_278 | V_283 , V_2 -> V_3 . V_276 + V_281 ) ;
}
void F_179 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_2 ;
void T_2 * V_275 = V_2 -> V_3 . V_276 ;
F_23 ( F_2 ( V_275 + V_281 ) & ~ V_283 ,
V_275 + V_281 ) ;
F_8 ( V_2 ) ;
}
T_1 F_180 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 . V_276 + V_277 ) ;
}
int F_181 ( struct V_1 * V_2 )
{
if ( V_2 -> V_284 || V_2 -> V_285 ) {
V_2 -> V_254 =
F_182 ( V_2 -> V_218 -> V_69 , V_286 ,
& V_2 -> V_279 , V_228 ) ;
if ( ! V_2 -> V_254 )
return - V_229 ;
}
return 0 ;
}
int F_183 ( struct V_1 * V_2 )
{
V_2 -> V_78 |= V_79 | V_287 ;
return F_181 ( V_2 ) ;
}
int F_184 ( struct V_214 * V_215 )
{
unsigned long V_246 = F_128 ( V_215 , 4 ) ;
T_1 V_288 ;
if ( V_246 == 0 )
return - V_289 ;
V_288 = F_185 ( V_246 + 0x02 ) ;
F_186 ( V_288 & 0x60 , V_246 + 0x02 ) ;
V_288 = F_185 ( V_246 + 0x02 ) ;
if ( V_288 & 0x80 )
return - V_240 ;
return 0 ;
}
static void F_187 ( struct V_217 * V_218 , const char * V_290 )
{
int V_174 ;
F_139 ( V_218 -> V_69 , L_49 , V_290 ) ;
for ( V_174 = 0 ; V_174 < 2 ; V_174 ++ ) {
V_218 -> V_221 [ V_174 ] -> V_284 = 0 ;
V_218 -> V_221 [ V_174 ] -> V_285 = 0 ;
}
}
void F_188 ( struct V_217 * V_218 )
{
struct V_24 * V_219 = V_218 -> V_69 ;
struct V_214 * V_215 = F_131 ( V_219 ) ;
int V_174 , V_173 ;
if ( F_128 ( V_215 , 4 ) == 0 ) {
F_187 ( V_218 , L_50 ) ;
return;
}
V_173 = F_189 ( V_215 , V_291 ) ;
if ( V_173 )
F_187 ( V_218 , L_51 ) ;
if ( ! V_173 ) {
V_173 = F_190 ( V_215 , V_291 ) ;
if ( V_173 )
F_187 ( V_218 ,
L_52 ) ;
}
V_173 = F_133 ( V_215 , 1 << 4 , F_134 ( V_219 ) ) ;
if ( V_173 ) {
F_187 ( V_218 , L_53 ) ;
return;
}
V_218 -> V_223 = F_137 ( V_215 ) ;
for ( V_174 = 0 ; V_174 < 2 ; V_174 ++ ) {
struct V_1 * V_2 = V_218 -> V_221 [ V_174 ] ;
void T_2 * V_246 = V_218 -> V_223 [ 4 ] + 8 * V_174 ;
if ( F_132 ( V_2 ) )
continue;
V_2 -> V_3 . V_276 = V_246 ;
if ( ( ! ( V_2 -> V_42 & V_292 ) ) &&
( F_2 ( V_246 + 2 ) & 0x80 ) )
V_218 -> V_42 |= V_293 ;
F_138 ( V_2 , L_54 ,
( unsigned long long ) F_128 ( V_215 , 4 ) + 8 * V_174 ) ;
}
}
int F_157 ( struct V_214 * V_215 ,
const struct F_27 * const * V_226 ,
struct V_217 * * V_227 )
{
int V_173 ;
V_173 = F_140 ( V_215 , V_226 , V_227 ) ;
if ( V_173 )
return V_173 ;
F_188 ( * V_227 ) ;
return 0 ;
}
int F_191 ( struct V_214 * V_215 ,
const struct F_27 * const * V_226 ,
struct V_231 * V_232 , void * V_244 ,
int V_245 )
{
return F_155 ( V_215 , V_226 , V_232 , V_244 , V_245 , 1 ) ;
}
void F_192 ( struct V_1 * V_2 )
{
F_193 ( & V_2 -> V_158 , F_88 ) ;
V_2 -> V_21 = V_294 ;
V_2 -> V_37 = 0xFF ;
}
int T_7 F_194 ( void )
{
V_153 = F_195 ( L_55 , V_295 , V_296 ) ;
if ( ! V_153 )
return - V_229 ;
return 0 ;
}
void F_196 ( void )
{
F_197 ( V_153 ) ;
}
