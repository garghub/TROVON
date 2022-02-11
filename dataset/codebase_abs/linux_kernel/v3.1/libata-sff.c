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
unsigned char V_76 [ 2 ] ;
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
unsigned char V_76 [ 4 ] ;
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
V_80 = F_38 ( V_69 , V_70 , V_71 , V_72 ) ;
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
if ( F_41 ( V_117 & ( 1 << 0 ) ) )
goto V_123;
V_120 = ( ( V_117 & ( 1 << 1 ) ) == 0 ) ? 1 : 0 ;
if ( F_41 ( V_83 != V_120 ) )
goto V_123;
if ( F_41 ( ! V_108 ) )
goto V_123;
F_32 ( L_14 , V_2 -> V_64 , V_108 ) ;
if ( F_41 ( F_63 ( V_82 , V_108 ) ) )
goto V_124;
F_5 ( V_2 ) ;
return;
V_123:
F_64 ( V_111 , L_15 ,
V_117 , V_108 ) ;
V_124:
V_82 -> V_125 |= V_126 ;
V_2 -> V_90 = V_127 ;
}
static inline int F_66 ( struct V_1 * V_2 ,
struct V_81 * V_82 )
{
if ( V_82 -> V_40 . V_42 & V_128 )
return 1 ;
if ( V_2 -> V_90 == V_129 ) {
if ( V_82 -> V_40 . V_102 == V_130 &&
( V_82 -> V_40 . V_42 & V_84 ) )
return 1 ;
if ( F_67 ( V_82 -> V_40 . V_102 ) &&
! ( V_82 -> V_69 -> V_42 & V_131 ) )
return 1 ;
}
return 0 ;
}
static void F_68 ( struct V_81 * V_82 , int V_132 )
{
struct V_1 * V_2 = V_82 -> V_2 ;
unsigned long V_42 ;
if ( V_2 -> V_5 -> V_133 ) {
if ( V_132 ) {
F_69 ( V_2 -> V_134 , V_42 ) ;
V_82 = F_70 ( V_2 , V_82 -> V_135 ) ;
if ( V_82 ) {
if ( F_34 ( ! ( V_82 -> V_125 & V_126 ) ) ) {
F_29 ( V_2 ) ;
F_71 ( V_82 ) ;
} else
F_72 ( V_2 ) ;
}
F_73 ( V_2 -> V_134 , V_42 ) ;
} else {
if ( F_34 ( ! ( V_82 -> V_125 & V_126 ) ) )
F_71 ( V_82 ) ;
else
F_72 ( V_2 ) ;
}
} else {
if ( V_132 ) {
F_69 ( V_2 -> V_134 , V_42 ) ;
F_29 ( V_2 ) ;
F_71 ( V_82 ) ;
F_73 ( V_2 -> V_134 , V_42 ) ;
} else
F_71 ( V_82 ) ;
}
}
int F_74 ( struct V_1 * V_2 , struct V_81 * V_82 ,
T_1 V_8 , int V_132 )
{
struct V_18 * V_19 = V_82 -> V_69 -> V_19 ;
struct V_110 * V_111 = & V_19 -> V_112 ;
unsigned long V_42 = 0 ;
int V_136 ;
F_31 ( ( V_82 -> V_42 & V_137 ) == 0 ) ;
F_31 ( V_132 != F_66 ( V_2 , V_82 ) ) ;
V_138:
F_36 ( L_16 ,
V_2 -> V_64 , V_82 -> V_40 . V_102 , V_2 -> V_90 , V_8 ) ;
switch ( V_2 -> V_90 ) {
case V_129 :
V_136 = ( V_82 -> V_40 . V_42 & V_128 ) ;
if ( F_41 ( ( V_8 & V_139 ) == 0 ) ) {
if ( F_34 ( V_8 & ( V_140 | V_141 ) ) )
V_82 -> V_125 |= V_142 ;
else {
F_64 ( V_111 ,
L_17 ) ;
V_82 -> V_125 |= V_126 ;
}
V_2 -> V_90 = V_127 ;
goto V_138;
}
if ( F_41 ( V_8 & ( V_140 | V_141 ) ) ) {
if ( ! ( V_82 -> V_69 -> V_143 & V_144 ) ) {
F_64 ( V_111 , L_18
L_19
L_20 , V_8 ) ;
V_82 -> V_125 |= V_126 ;
V_2 -> V_90 = V_127 ;
goto V_138;
}
}
if ( V_132 )
F_69 ( V_2 -> V_134 , V_42 ) ;
if ( V_82 -> V_40 . V_102 == V_130 ) {
V_2 -> V_90 = V_104 ;
F_58 ( V_82 ) ;
} else
F_61 ( V_2 , V_82 ) ;
if ( V_132 )
F_73 ( V_2 -> V_134 , V_42 ) ;
break;
case V_104 :
if ( V_82 -> V_40 . V_102 == V_103 ) {
if ( ( V_8 & V_139 ) == 0 ) {
V_2 -> V_90 = V_91 ;
goto V_138;
}
if ( F_41 ( V_8 & ( V_140 | V_141 ) ) ) {
F_64 ( V_111 , L_21
L_19
L_20 , V_8 ) ;
V_82 -> V_125 |= V_126 ;
V_2 -> V_90 = V_127 ;
goto V_138;
}
F_65 ( V_82 ) ;
if ( F_41 ( V_2 -> V_90 == V_127 ) )
goto V_138;
} else {
if ( F_41 ( ( V_8 & V_139 ) == 0 ) ) {
if ( F_34 ( V_8 & ( V_140 | V_141 ) ) ) {
V_82 -> V_125 |= V_142 ;
if ( V_82 -> V_69 -> V_143 &
V_145 )
V_82 -> V_125 |=
V_146 ;
} else {
F_64 ( V_111 , L_22
L_23
L_20 , V_8 ) ;
V_82 -> V_125 |= V_126 |
V_146 ;
}
V_2 -> V_90 = V_127 ;
goto V_138;
}
if ( F_41 ( V_8 & ( V_140 | V_141 ) ) ) {
V_82 -> V_125 |= V_142 ;
if ( ! ( V_82 -> V_40 . V_42 & V_84 ) ) {
F_58 ( V_82 ) ;
V_8 = F_28 ( V_2 ) ;
}
if ( V_8 & ( V_9 | V_139 ) ) {
F_64 ( V_111 , L_22
L_24
L_20 , V_8 ) ;
V_82 -> V_125 |= V_126 ;
}
if ( V_8 == 0x7f )
V_82 -> V_125 |= V_146 ;
V_2 -> V_90 = V_127 ;
goto V_138;
}
F_58 ( V_82 ) ;
if ( V_2 -> V_90 == V_91 &&
( ! ( V_82 -> V_40 . V_42 & V_84 ) ) ) {
V_8 = F_28 ( V_2 ) ;
goto V_138;
}
}
V_136 = 1 ;
break;
case V_91 :
if ( F_41 ( ! F_75 ( V_8 ) ) ) {
V_82 -> V_125 |= F_76 ( V_8 ) ;
V_2 -> V_90 = V_127 ;
goto V_138;
}
F_36 ( L_25 ,
V_2 -> V_64 , V_82 -> V_69 -> V_147 , V_8 ) ;
F_31 ( V_82 -> V_125 & ( V_142 | V_126 ) ) ;
V_2 -> V_90 = V_148 ;
F_68 ( V_82 , V_132 ) ;
V_136 = 0 ;
break;
case V_127 :
V_2 -> V_90 = V_148 ;
F_68 ( V_82 , V_132 ) ;
V_136 = 0 ;
break;
default:
V_136 = 0 ;
F_9 () ;
}
return V_136 ;
}
void F_77 ( struct V_149 * V_150 )
{
F_78 ( V_151 , V_150 ) ;
}
void F_79 ( struct V_152 * V_153 , unsigned long V_154 )
{
F_80 ( V_151 , V_153 , V_154 ) ;
}
void F_81 ( struct V_18 * V_19 , unsigned long V_154 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_82 ( ( V_2 -> V_155 != NULL ) &&
( V_2 -> V_155 != V_19 ) ) ;
V_2 -> V_155 = V_19 ;
F_79 ( & V_2 -> V_156 , F_83 ( V_154 ) ) ;
}
void F_84 ( struct V_1 * V_2 )
{
F_36 ( L_26 ) ;
F_85 ( & V_2 -> V_156 ) ;
V_2 -> V_90 = V_148 ;
V_2 -> V_155 = NULL ;
if ( F_86 ( V_2 ) )
F_87 ( V_2 , L_27 , V_157 ) ;
}
static void F_88 ( struct V_149 * V_150 )
{
struct V_1 * V_2 =
F_89 ( V_150 , struct V_1 , V_156 . V_150 ) ;
struct V_18 * V_19 = V_2 -> V_155 ;
struct V_81 * V_82 ;
T_1 V_8 ;
int V_136 ;
F_90 ( V_2 -> V_155 == NULL ) ;
V_82 = F_70 ( V_2 , V_19 -> V_158 ) ;
if ( ! V_82 ) {
V_2 -> V_155 = NULL ;
return;
}
V_138:
F_31 ( V_2 -> V_90 == V_148 ) ;
V_8 = F_11 ( V_2 , V_9 , 5 ) ;
if ( V_8 & V_9 ) {
F_14 ( V_2 , 2 ) ;
V_8 = F_11 ( V_2 , V_9 , 10 ) ;
if ( V_8 & V_9 ) {
F_81 ( V_19 , V_159 ) ;
return;
}
}
V_2 -> V_155 = NULL ;
V_136 = F_74 ( V_2 , V_82 , V_8 , 1 ) ;
if ( V_136 )
goto V_138;
}
unsigned int F_91 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_2 ;
struct V_18 * V_19 = V_82 -> V_69 -> V_19 ;
if ( V_2 -> V_42 & V_160 )
V_82 -> V_40 . V_42 |= V_128 ;
F_25 ( V_2 , V_82 -> V_69 -> V_147 , 1 , 0 ) ;
switch ( V_82 -> V_40 . V_102 ) {
case V_161 :
if ( V_82 -> V_40 . V_42 & V_128 )
F_92 ( V_82 ) ;
F_37 ( V_2 , & V_82 -> V_40 ) ;
V_2 -> V_90 = V_91 ;
if ( V_82 -> V_40 . V_42 & V_128 )
F_81 ( V_19 , 0 ) ;
break;
case V_130 :
if ( V_82 -> V_40 . V_42 & V_128 )
F_92 ( V_82 ) ;
F_37 ( V_2 , & V_82 -> V_40 ) ;
if ( V_82 -> V_40 . V_42 & V_84 ) {
V_2 -> V_90 = V_129 ;
F_81 ( V_19 , 0 ) ;
} else {
V_2 -> V_90 = V_104 ;
if ( V_82 -> V_40 . V_42 & V_128 )
F_81 ( V_19 , 0 ) ;
}
break;
case V_103 :
case V_105 :
if ( V_82 -> V_40 . V_42 & V_128 )
F_92 ( V_82 ) ;
F_37 ( V_2 , & V_82 -> V_40 ) ;
V_2 -> V_90 = V_129 ;
if ( ( ! ( V_82 -> V_69 -> V_42 & V_131 ) ) ||
( V_82 -> V_40 . V_42 & V_128 ) )
F_81 ( V_19 , 0 ) ;
break;
default:
F_31 ( 1 ) ;
return V_162 ;
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
V_2 -> V_163 . V_164 ++ ;
#ifdef F_95
if ( ( V_2 -> V_163 . V_164 % 1000 ) == 0 ) {
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
bool V_165 )
{
T_1 V_8 ;
F_32 ( L_29 ,
V_2 -> V_64 , V_82 -> V_40 . V_102 , V_2 -> V_90 ) ;
switch ( V_2 -> V_90 ) {
case V_129 :
if ( ! ( V_82 -> V_69 -> V_42 & V_131 ) )
return F_94 ( V_2 ) ;
break;
case V_148 :
return F_94 ( V_2 ) ;
default:
break;
}
V_8 = F_4 ( V_2 ) ;
if ( V_8 & V_9 ) {
if ( V_165 ) {
V_82 -> V_125 |= V_126 ;
V_2 -> V_90 = V_127 ;
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
T_3 F_98 ( int V_166 , void * V_167 )
{
return F_99 ( V_166 , V_167 , F_97 ) ;
}
void F_100 ( struct V_1 * V_2 )
{
T_1 V_8 ;
struct V_81 * V_82 ;
V_82 = F_70 ( V_2 , V_2 -> V_19 . V_158 ) ;
if ( ! V_82 || V_82 -> V_40 . V_42 & V_128 )
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
struct V_168 * V_169 = & V_19 -> V_170 ;
int V_171 ;
V_171 = F_104 ( V_19 , V_20 ) ;
if ( V_171 )
return V_171 ;
if ( V_169 -> V_172 . V_173 & V_174 )
return 0 ;
if ( ! F_105 ( V_19 ) ) {
V_171 = F_20 ( V_19 , V_20 ) ;
if ( V_171 && V_171 != - V_16 ) {
F_106 ( V_19 ,
L_31 ,
V_171 ) ;
V_169 -> V_172 . V_173 |= V_174 ;
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
unsigned int F_108 ( struct V_68 * V_69 , int V_175 ,
T_1 * V_176 )
{
struct V_1 * V_2 = V_69 -> V_19 -> V_2 ;
struct V_39 V_40 ;
unsigned int V_32 ;
T_1 V_177 ;
V_2 -> V_5 -> V_31 ( V_2 , V_69 -> V_147 ) ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_2 -> V_5 -> V_121 ( V_2 , & V_40 ) ;
V_177 = V_40 . V_55 ;
if ( V_176 )
* V_176 = V_177 ;
if ( V_177 == 0 )
V_69 -> V_143 |= V_145 ;
else if ( V_177 == 1 )
;
else if ( ( V_69 -> V_147 == 0 ) && ( V_177 == 0x81 ) )
;
else
return V_178 ;
V_32 = F_109 ( & V_40 ) ;
if ( V_32 == V_179 ) {
if ( V_175 && ( V_69 -> V_143 & V_145 ) )
V_32 = V_180 ;
else
V_32 = V_178 ;
} else if ( ( V_32 == V_180 ) &&
( V_2 -> V_5 -> V_10 ( V_2 ) == 0 ) )
V_32 = V_178 ;
return V_32 ;
}
int F_110 ( struct V_18 * V_19 , unsigned int V_181 ,
unsigned long V_20 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_34 * V_3 = & V_2 -> V_3 ;
unsigned int V_182 = V_181 & ( 1 << 0 ) ;
unsigned int V_183 = V_181 & ( 1 << 1 ) ;
int V_171 , V_184 = 0 ;
F_14 ( V_2 , V_185 ) ;
V_171 = F_20 ( V_19 , V_20 ) ;
if ( V_171 )
return V_171 ;
if ( V_183 ) {
int V_172 ;
V_2 -> V_5 -> V_31 ( V_2 , 1 ) ;
for ( V_172 = 0 ; V_172 < 2 ; V_172 ++ ) {
T_1 V_56 , V_57 ;
V_56 = F_2 ( V_3 -> V_48 ) ;
V_57 = F_2 ( V_3 -> V_50 ) ;
if ( ( V_56 == 1 ) && ( V_57 == 1 ) )
break;
F_14 ( V_2 , 50 ) ;
}
V_171 = F_20 ( V_19 , V_20 ) ;
if ( V_171 ) {
if ( V_171 != - V_16 )
return V_171 ;
V_184 = V_171 ;
}
}
V_2 -> V_5 -> V_31 ( V_2 , 0 ) ;
if ( V_183 )
V_2 -> V_5 -> V_31 ( V_2 , 1 ) ;
if ( V_182 )
V_2 -> V_5 -> V_31 ( V_2 , 0 ) ;
return V_184 ;
}
static int F_111 ( struct V_1 * V_2 , unsigned int V_181 ,
unsigned long V_20 )
{
struct V_34 * V_3 = & V_2 -> V_3 ;
F_36 ( L_32 , V_2 -> V_64 ) ;
F_23 ( V_2 -> V_21 , V_3 -> V_23 ) ;
F_112 ( 20 ) ;
F_23 ( V_2 -> V_21 | V_186 , V_3 -> V_23 ) ;
F_112 ( 20 ) ;
F_23 ( V_2 -> V_21 , V_3 -> V_23 ) ;
V_2 -> V_37 = V_2 -> V_21 ;
return F_110 ( & V_2 -> V_19 , V_181 , V_20 ) ;
}
int F_113 ( struct V_18 * V_19 , unsigned int * V_187 ,
unsigned long V_20 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned int V_188 = V_2 -> V_42 & V_189 ;
unsigned int V_181 = 0 ;
int V_171 ;
T_1 V_177 ;
F_36 ( L_26 ) ;
if ( F_107 ( V_2 , 0 ) )
V_181 |= ( 1 << 0 ) ;
if ( V_188 && F_107 ( V_2 , 1 ) )
V_181 |= ( 1 << 1 ) ;
V_2 -> V_5 -> V_31 ( V_2 , 0 ) ;
F_36 ( L_33 , V_181 ) ;
V_171 = F_111 ( V_2 , V_181 , V_20 ) ;
if ( V_171 && ( V_171 != - V_16 || F_114 ( V_19 ) ) ) {
F_115 ( V_19 , L_34 , V_171 ) ;
return V_171 ;
}
V_187 [ 0 ] = F_108 ( & V_19 -> V_24 [ 0 ] ,
V_181 & ( 1 << 0 ) , & V_177 ) ;
if ( V_188 && V_177 != 0x81 )
V_187 [ 1 ] = F_108 ( & V_19 -> V_24 [ 1 ] ,
V_181 & ( 1 << 1 ) , & V_177 ) ;
F_36 ( L_35 , V_187 [ 0 ] , V_187 [ 1 ] ) ;
return 0 ;
}
int F_116 ( struct V_18 * V_19 , unsigned int * V_32 ,
unsigned long V_20 )
{
struct V_168 * V_169 = & V_19 -> V_170 ;
const unsigned long * V_190 = F_117 ( V_169 ) ;
bool V_191 ;
int V_171 ;
V_171 = F_118 ( V_19 , V_190 , V_20 , & V_191 ,
F_18 ) ;
if ( V_191 )
* V_32 = F_108 ( V_19 -> V_24 , 1 , NULL ) ;
F_36 ( L_36 , * V_32 ) ;
return V_171 ;
}
void F_119 ( struct V_18 * V_19 , unsigned int * V_187 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_120 ( V_19 , V_187 ) ;
if ( V_187 [ 0 ] != V_178 )
V_2 -> V_5 -> V_31 ( V_2 , 1 ) ;
if ( V_187 [ 1 ] != V_178 )
V_2 -> V_5 -> V_31 ( V_2 , 0 ) ;
if ( V_187 [ 0 ] == V_178 && V_187 [ 1 ] == V_178 ) {
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
if ( V_82 == NULL || V_82 -> V_192 == V_193 )
return;
V_2 = V_82 -> V_2 ;
for ( V_115 = 0 ; ( V_2 -> V_5 -> V_10 ( V_2 ) & V_139 )
&& V_115 < 65536 ; V_115 += 2 )
F_122 ( V_2 -> V_3 . V_73 ) ;
if ( V_115 )
F_87 ( V_2 , L_38 , V_115 ) ;
}
void F_123 ( struct V_1 * V_2 )
{
T_4 V_194 = V_2 -> V_5 -> V_194 ;
T_4 V_195 = V_2 -> V_5 -> V_195 ;
struct V_81 * V_82 ;
unsigned long V_42 ;
V_82 = F_124 ( V_2 , V_2 -> V_19 . V_158 ) ;
if ( V_82 && ! ( V_82 -> V_42 & V_196 ) )
V_82 = NULL ;
F_69 ( V_2 -> V_134 , V_42 ) ;
if ( V_2 -> V_5 -> V_197 )
V_2 -> V_5 -> V_197 ( V_82 ) ;
F_73 ( V_2 -> V_134 , V_42 ) ;
if ( V_194 == F_113 && ! V_2 -> V_3 . V_23 )
V_194 = NULL ;
if ( ( V_195 == V_198 ||
V_195 == F_116 ) && ! F_114 ( & V_2 -> V_19 ) )
V_195 = NULL ;
F_125 ( V_2 , V_2 -> V_5 -> V_199 , V_194 , V_195 ,
V_2 -> V_5 -> V_200 ) ;
}
void F_126 ( struct V_34 * V_3 )
{
V_3 -> V_73 = V_3 -> V_201 + V_202 ;
V_3 -> V_62 = V_3 -> V_201 + V_203 ;
V_3 -> V_46 = V_3 -> V_201 + V_204 ;
V_3 -> V_48 = V_3 -> V_201 + V_205 ;
V_3 -> V_50 = V_3 -> V_201 + V_206 ;
V_3 -> V_52 = V_3 -> V_201 + V_207 ;
V_3 -> V_54 = V_3 -> V_201 + V_208 ;
V_3 -> V_28 = V_3 -> V_201 + V_209 ;
V_3 -> V_4 = V_3 -> V_201 + V_210 ;
V_3 -> V_65 = V_3 -> V_201 + V_211 ;
}
static int F_127 ( struct V_212 * V_213 , int V_214 )
{
int V_172 ;
V_214 = V_214 * 2 ;
for ( V_172 = 0 ; V_172 < 2 ; V_172 ++ ) {
if ( F_128 ( V_213 , V_214 + V_172 ) == 0 ||
F_129 ( V_213 , V_214 + V_172 ) == 0 )
return 0 ;
}
return 1 ;
}
int F_130 ( struct V_215 * V_216 )
{
struct V_24 * V_217 = V_216 -> V_69 ;
struct V_212 * V_213 = F_131 ( V_217 ) ;
unsigned int V_218 = 0 ;
int V_172 , V_171 ;
for ( V_172 = 0 ; V_172 < 2 ; V_172 ++ ) {
struct V_1 * V_2 = V_216 -> V_219 [ V_172 ] ;
int V_220 = V_172 * 2 ;
void T_2 * const * V_221 ;
if ( F_132 ( V_2 ) )
continue;
if ( ! F_127 ( V_213 , V_172 ) ) {
V_2 -> V_5 = & V_222 ;
continue;
}
V_171 = F_133 ( V_213 , 0x3 << V_220 ,
F_134 ( V_217 ) ) ;
if ( V_171 ) {
F_135 ( V_217 ,
L_39 ,
V_172 , V_171 ) ;
if ( V_171 == - V_17 )
F_136 ( V_213 ) ;
V_2 -> V_5 = & V_222 ;
continue;
}
V_216 -> V_221 = V_221 = F_137 ( V_213 ) ;
V_2 -> V_3 . V_201 = V_221 [ V_220 ] ;
V_2 -> V_3 . V_7 =
V_2 -> V_3 . V_23 = ( void T_2 * )
( ( unsigned long ) V_221 [ V_220 + 1 ] | V_223 ) ;
F_126 ( & V_2 -> V_3 ) ;
F_138 ( V_2 , L_40 ,
( unsigned long long ) F_128 ( V_213 , V_220 ) ,
( unsigned long long ) F_128 ( V_213 , V_220 + 1 ) ) ;
V_218 |= 1 << V_172 ;
}
if ( ! V_218 ) {
F_139 ( V_217 , L_41 ) ;
return - V_16 ;
}
return 0 ;
}
int F_140 ( struct V_212 * V_213 ,
const struct F_27 * const * V_224 ,
struct V_215 * * V_225 )
{
struct V_215 * V_216 ;
int V_171 ;
if ( ! F_141 ( & V_213 -> V_69 , NULL , V_226 ) )
return - V_227 ;
V_216 = F_142 ( & V_213 -> V_69 , V_224 , 2 ) ;
if ( ! V_216 ) {
F_139 ( & V_213 -> V_69 , L_42 ) ;
V_171 = - V_227 ;
goto V_124;
}
V_171 = F_130 ( V_216 ) ;
if ( V_171 )
goto V_124;
F_143 ( & V_213 -> V_69 , NULL ) ;
* V_225 = V_216 ;
return 0 ;
V_124:
F_144 ( & V_213 -> V_69 , NULL ) ;
return V_171 ;
}
int F_145 ( struct V_215 * V_216 ,
T_5 V_228 ,
struct V_229 * V_230 )
{
struct V_24 * V_69 = V_216 -> V_69 ;
struct V_212 * V_213 = F_131 ( V_69 ) ;
const char * V_231 = F_134 ( V_216 -> V_69 ) ;
int V_232 = 0 , V_171 ;
V_171 = F_146 ( V_216 ) ;
if ( V_171 )
return V_171 ;
if ( ( V_213 -> V_32 >> 8 ) == V_233 ) {
T_1 V_234 , V_218 ;
F_147 ( V_213 , V_235 , & V_234 ) ;
V_218 = ( 1 << 2 ) | ( 1 << 0 ) ;
if ( ( V_234 & V_218 ) != V_218 )
V_232 = 1 ;
#if F_148 ( V_236 )
if ( V_232 ) {
F_149 ( V_237 L_43 ) ;
return - V_238 ;
}
#endif
}
if ( ! F_141 ( V_69 , NULL , V_226 ) )
return - V_227 ;
if ( ! V_232 && V_213 -> V_166 ) {
int V_172 ;
V_171 = F_150 ( V_69 , V_213 -> V_166 , V_228 ,
V_239 , V_231 , V_216 ) ;
if ( V_171 )
goto V_240;
for ( V_172 = 0 ; V_172 < 2 ; V_172 ++ ) {
if ( F_132 ( V_216 -> V_219 [ V_172 ] ) )
continue;
F_138 ( V_216 -> V_219 [ V_172 ] , L_44 , V_213 -> V_166 ) ;
}
} else if ( V_232 ) {
if ( ! F_132 ( V_216 -> V_219 [ 0 ] ) ) {
V_171 = F_150 ( V_69 , F_151 ( V_213 ) ,
V_228 , V_239 ,
V_231 , V_216 ) ;
if ( V_171 )
goto V_240;
F_138 ( V_216 -> V_219 [ 0 ] , L_44 ,
F_151 ( V_213 ) ) ;
}
if ( ! F_132 ( V_216 -> V_219 [ 1 ] ) ) {
V_171 = F_150 ( V_69 , F_152 ( V_213 ) ,
V_228 , V_239 ,
V_231 , V_216 ) ;
if ( V_171 )
goto V_240;
F_138 ( V_216 -> V_219 [ 1 ] , L_44 ,
F_152 ( V_213 ) ) ;
}
}
V_171 = F_153 ( V_216 , V_230 ) ;
V_240:
if ( V_171 == 0 )
F_143 ( V_69 , NULL ) ;
else
F_144 ( V_69 , NULL ) ;
return V_171 ;
}
static const struct F_27 * F_154 (
const struct F_27 * const * V_224 )
{
int V_172 ;
for ( V_172 = 0 ; V_172 < 2 && V_224 [ V_172 ] ; V_172 ++ )
if ( V_224 [ V_172 ] -> V_241 != & V_222 )
return V_224 [ V_172 ] ;
return NULL ;
}
int F_155 ( struct V_212 * V_213 ,
const struct F_27 * const * V_224 ,
struct V_229 * V_230 , void * V_242 , int V_243 )
{
struct V_24 * V_69 = & V_213 -> V_69 ;
const struct F_27 * V_244 ;
struct V_215 * V_216 = NULL ;
int V_171 ;
F_36 ( L_26 ) ;
V_244 = F_154 ( V_224 ) ;
if ( ! V_244 ) {
F_139 ( & V_213 -> V_69 , L_45 ) ;
return - V_245 ;
}
if ( ! F_141 ( V_69 , NULL , V_226 ) )
return - V_227 ;
V_171 = F_156 ( V_213 ) ;
if ( V_171 )
goto V_240;
V_171 = F_140 ( V_213 , V_224 , & V_216 ) ;
if ( V_171 )
goto V_240;
V_216 -> V_246 = V_242 ;
V_216 -> V_42 |= V_243 ;
V_171 = F_145 ( V_216 , F_98 , V_230 ) ;
V_240:
if ( V_171 == 0 )
F_143 ( & V_213 -> V_69 , NULL ) ;
else
F_144 ( & V_213 -> V_69 , NULL ) ;
return V_171 ;
}
static void F_157 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_2 ;
struct V_247 * V_248 = V_2 -> V_249 ;
struct V_113 * V_114 ;
unsigned int V_250 , V_244 ;
V_244 = 0 ;
F_158 (qc->sg, sg, qc->n_elem, si) {
T_6 V_251 , V_86 ;
T_6 V_252 , V_253 ;
V_251 = ( T_6 ) F_159 ( V_114 ) ;
V_252 = F_160 ( V_114 ) ;
while ( V_252 ) {
V_86 = V_251 & 0xffff ;
V_253 = V_252 ;
if ( ( V_86 + V_252 ) > 0x10000 )
V_253 = 0x10000 - V_86 ;
V_248 [ V_244 ] . V_251 = F_161 ( V_251 ) ;
V_248 [ V_244 ] . V_254 = F_161 ( V_253 & 0xffff ) ;
F_32 ( L_46 , V_244 , V_251 , V_253 ) ;
V_244 ++ ;
V_252 -= V_253 ;
V_251 += V_253 ;
}
}
V_248 [ V_244 - 1 ] . V_254 |= F_161 ( V_255 ) ;
}
static void F_162 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_2 ;
struct V_247 * V_248 = V_2 -> V_249 ;
struct V_113 * V_114 ;
unsigned int V_250 , V_244 ;
V_244 = 0 ;
F_158 (qc->sg, sg, qc->n_elem, si) {
T_6 V_251 , V_86 ;
T_6 V_252 , V_253 , V_256 ;
V_251 = ( T_6 ) F_159 ( V_114 ) ;
V_252 = F_160 ( V_114 ) ;
while ( V_252 ) {
V_86 = V_251 & 0xffff ;
V_253 = V_252 ;
if ( ( V_86 + V_252 ) > 0x10000 )
V_253 = 0x10000 - V_86 ;
V_256 = V_253 & 0xffff ;
V_248 [ V_244 ] . V_251 = F_161 ( V_251 ) ;
if ( V_256 == 0 ) {
V_248 [ V_244 ] . V_254 = F_161 ( 0x8000 ) ;
V_256 = 0x8000 ;
V_248 [ ++ V_244 ] . V_251 = F_161 ( V_251 + 0x8000 ) ;
}
V_248 [ V_244 ] . V_254 = F_161 ( V_256 ) ;
F_32 ( L_46 , V_244 , V_251 , V_253 ) ;
V_244 ++ ;
V_252 -= V_253 ;
V_251 += V_253 ;
}
}
V_248 [ V_244 - 1 ] . V_254 |= F_161 ( V_255 ) ;
}
void F_163 ( struct V_81 * V_82 )
{
if ( ! ( V_82 -> V_42 & V_257 ) )
return;
F_157 ( V_82 ) ;
}
void F_164 ( struct V_81 * V_82 )
{
if ( ! ( V_82 -> V_42 & V_257 ) )
return;
F_162 ( V_82 ) ;
}
unsigned int F_165 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_2 ;
struct V_18 * V_19 = V_82 -> V_69 -> V_19 ;
if ( ! F_166 ( V_82 -> V_40 . V_102 ) )
return F_91 ( V_82 ) ;
F_25 ( V_2 , V_82 -> V_69 -> V_147 , 1 , 0 ) ;
switch ( V_82 -> V_40 . V_102 ) {
case V_258 :
F_31 ( V_82 -> V_40 . V_42 & V_128 ) ;
V_2 -> V_5 -> V_66 ( V_2 , & V_82 -> V_40 ) ;
V_2 -> V_5 -> V_259 ( V_82 ) ;
V_2 -> V_5 -> V_107 ( V_82 ) ;
V_2 -> V_90 = V_91 ;
break;
case V_106 :
F_31 ( V_82 -> V_40 . V_42 & V_128 ) ;
V_2 -> V_5 -> V_66 ( V_2 , & V_82 -> V_40 ) ;
V_2 -> V_5 -> V_259 ( V_82 ) ;
V_2 -> V_90 = V_129 ;
if ( ! ( V_82 -> V_69 -> V_42 & V_131 ) )
F_81 ( V_19 , 0 ) ;
break;
default:
F_82 ( 1 ) ;
return V_162 ;
}
return 0 ;
}
unsigned int F_167 ( struct V_1 * V_2 , struct V_81 * V_82 )
{
struct V_110 * V_111 = & V_2 -> V_19 . V_112 ;
T_1 V_260 = 0 ;
bool V_261 = false ;
unsigned int V_262 ;
if ( V_2 -> V_90 == V_91 && F_166 ( V_82 -> V_40 . V_102 ) ) {
V_260 = V_2 -> V_5 -> V_263 ( V_2 ) ;
F_32 ( L_47 , V_2 -> V_64 , V_260 ) ;
if ( ! ( V_260 & V_264 ) )
return F_94 ( V_2 ) ;
V_2 -> V_5 -> V_265 ( V_82 ) ;
V_261 = true ;
if ( F_41 ( V_260 & V_266 ) ) {
V_82 -> V_125 |= V_267 ;
V_2 -> V_90 = V_127 ;
}
}
V_262 = F_96 ( V_2 , V_82 , V_261 ) ;
if ( F_41 ( V_82 -> V_125 ) && F_166 ( V_82 -> V_40 . V_102 ) )
F_64 ( V_111 , L_48 , V_260 ) ;
return V_262 ;
}
T_3 F_168 ( int V_166 , void * V_167 )
{
return F_99 ( V_166 , V_167 , F_167 ) ;
}
void F_169 ( struct V_1 * V_2 )
{
struct V_81 * V_82 ;
unsigned long V_42 ;
bool V_268 = false ;
V_82 = F_124 ( V_2 , V_2 -> V_19 . V_158 ) ;
if ( V_82 && ! ( V_82 -> V_42 & V_196 ) )
V_82 = NULL ;
F_69 ( V_2 -> V_134 , V_42 ) ;
if ( V_82 && F_166 ( V_82 -> V_40 . V_102 ) ) {
T_1 V_260 ;
V_260 = V_2 -> V_5 -> V_263 ( V_2 ) ;
if ( V_82 -> V_125 == V_269 && ( V_260 & V_266 ) ) {
V_82 -> V_125 = V_267 ;
V_268 = true ;
}
V_2 -> V_5 -> V_265 ( V_82 ) ;
if ( V_268 ) {
V_2 -> V_5 -> V_10 ( V_2 ) ;
if ( V_2 -> V_5 -> V_38 )
V_2 -> V_5 -> V_38 ( V_2 ) ;
}
}
F_73 ( V_2 -> V_134 , V_42 ) ;
if ( V_268 )
F_170 ( V_2 ) ;
F_123 ( V_2 ) ;
}
void F_171 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_2 ;
unsigned long V_42 ;
if ( F_166 ( V_82 -> V_40 . V_102 ) ) {
F_69 ( V_2 -> V_134 , V_42 ) ;
V_2 -> V_5 -> V_265 ( V_82 ) ;
F_73 ( V_2 -> V_134 , V_42 ) ;
}
}
void F_172 ( struct V_1 * V_2 )
{
void T_2 * V_270 = V_2 -> V_3 . V_271 ;
if ( ! V_270 )
return;
F_23 ( F_2 ( V_270 + V_272 ) , V_270 + V_272 ) ;
}
void F_173 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_2 ;
unsigned int V_72 = ( V_82 -> V_40 . V_42 & V_84 ) ;
T_1 V_273 ;
F_174 () ;
F_175 ( V_2 -> V_274 , V_2 -> V_3 . V_271 + V_275 ) ;
V_273 = F_2 ( V_2 -> V_3 . V_271 + V_276 ) ;
V_273 &= ~ ( V_277 | V_278 ) ;
if ( ! V_72 )
V_273 |= V_277 ;
F_23 ( V_273 , V_2 -> V_3 . V_271 + V_276 ) ;
V_2 -> V_5 -> V_67 ( V_2 , & V_82 -> V_40 ) ;
}
void F_176 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_2 ;
T_1 V_273 ;
V_273 = F_2 ( V_2 -> V_3 . V_271 + V_276 ) ;
F_23 ( V_273 | V_278 , V_2 -> V_3 . V_271 + V_276 ) ;
}
void F_177 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_2 ;
void T_2 * V_270 = V_2 -> V_3 . V_271 ;
F_23 ( F_2 ( V_270 + V_276 ) & ~ V_278 ,
V_270 + V_276 ) ;
F_8 ( V_2 ) ;
}
T_1 F_178 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 . V_271 + V_272 ) ;
}
int F_179 ( struct V_1 * V_2 )
{
if ( V_2 -> V_279 || V_2 -> V_280 ) {
V_2 -> V_249 =
F_180 ( V_2 -> V_216 -> V_69 , V_281 ,
& V_2 -> V_274 , V_226 ) ;
if ( ! V_2 -> V_249 )
return - V_227 ;
}
return 0 ;
}
int F_181 ( struct V_1 * V_2 )
{
V_2 -> V_78 |= V_79 | V_282 ;
return F_179 ( V_2 ) ;
}
int F_182 ( struct V_212 * V_213 )
{
unsigned long V_283 = F_128 ( V_213 , 4 ) ;
T_1 V_284 ;
if ( V_283 == 0 )
return - V_285 ;
V_284 = F_183 ( V_283 + 0x02 ) ;
F_184 ( V_284 & 0x60 , V_283 + 0x02 ) ;
V_284 = F_183 ( V_283 + 0x02 ) ;
if ( V_284 & 0x80 )
return - V_238 ;
return 0 ;
}
static void F_185 ( struct V_215 * V_216 , const char * V_286 )
{
int V_172 ;
F_139 ( V_216 -> V_69 , L_49 , V_286 ) ;
for ( V_172 = 0 ; V_172 < 2 ; V_172 ++ ) {
V_216 -> V_219 [ V_172 ] -> V_279 = 0 ;
V_216 -> V_219 [ V_172 ] -> V_280 = 0 ;
}
}
void F_186 ( struct V_215 * V_216 )
{
struct V_24 * V_217 = V_216 -> V_69 ;
struct V_212 * V_213 = F_131 ( V_217 ) ;
int V_172 , V_171 ;
if ( F_128 ( V_213 , 4 ) == 0 ) {
F_185 ( V_216 , L_50 ) ;
return;
}
V_171 = F_187 ( V_213 , V_287 ) ;
if ( V_171 )
F_185 ( V_216 , L_51 ) ;
if ( ! V_171 ) {
V_171 = F_188 ( V_213 , V_287 ) ;
if ( V_171 )
F_185 ( V_216 ,
L_52 ) ;
}
V_171 = F_133 ( V_213 , 1 << 4 , F_134 ( V_217 ) ) ;
if ( V_171 ) {
F_185 ( V_216 , L_53 ) ;
return;
}
V_216 -> V_221 = F_137 ( V_213 ) ;
for ( V_172 = 0 ; V_172 < 2 ; V_172 ++ ) {
struct V_1 * V_2 = V_216 -> V_219 [ V_172 ] ;
void T_2 * V_283 = V_216 -> V_221 [ 4 ] + 8 * V_172 ;
if ( F_132 ( V_2 ) )
continue;
V_2 -> V_3 . V_271 = V_283 ;
if ( ( ! ( V_2 -> V_42 & V_288 ) ) &&
( F_2 ( V_283 + 2 ) & 0x80 ) )
V_216 -> V_42 |= V_289 ;
F_138 ( V_2 , L_54 ,
( unsigned long long ) F_128 ( V_213 , 4 ) + 8 * V_172 ) ;
}
}
int F_189 ( struct V_212 * V_213 ,
const struct F_27 * const * V_224 ,
struct V_215 * * V_225 )
{
int V_171 ;
V_171 = F_140 ( V_213 , V_224 , V_225 ) ;
if ( V_171 )
return V_171 ;
F_186 ( * V_225 ) ;
return 0 ;
}
int F_190 ( struct V_212 * V_213 ,
const struct F_27 * const * V_224 ,
struct V_229 * V_230 , void * V_242 ,
int V_290 )
{
struct V_24 * V_69 = & V_213 -> V_69 ;
const struct F_27 * V_244 ;
struct V_215 * V_216 = NULL ;
int V_171 ;
F_36 ( L_26 ) ;
V_244 = F_154 ( V_224 ) ;
if ( ! V_244 ) {
F_139 ( & V_213 -> V_69 , L_45 ) ;
return - V_245 ;
}
if ( ! F_141 ( V_69 , NULL , V_226 ) )
return - V_227 ;
V_171 = F_156 ( V_213 ) ;
if ( V_171 )
goto V_240;
V_171 = F_189 ( V_213 , V_224 , & V_216 ) ;
if ( V_171 )
goto V_240;
V_216 -> V_246 = V_242 ;
V_216 -> V_42 |= V_290 ;
F_191 ( V_213 ) ;
V_171 = F_145 ( V_216 , F_168 , V_230 ) ;
V_240:
if ( V_171 == 0 )
F_143 ( & V_213 -> V_69 , NULL ) ;
else
F_144 ( & V_213 -> V_69 , NULL ) ;
return V_171 ;
}
void F_192 ( struct V_1 * V_2 )
{
F_193 ( & V_2 -> V_156 , F_88 ) ;
V_2 -> V_21 = V_291 ;
V_2 -> V_37 = 0xFF ;
}
int T_7 F_194 ( void )
{
V_151 = F_195 ( L_55 , V_292 , V_293 ) ;
if ( ! V_151 )
return - V_227 ;
return 0 ;
}
void F_196 ( void )
{
F_197 ( V_151 ) ;
}
