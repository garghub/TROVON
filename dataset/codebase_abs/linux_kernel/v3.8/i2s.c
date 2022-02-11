static inline bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 ? true : false ;
}
static inline bool F_2 ( struct V_1 * V_2 )
{
return ( F_3 ( V_2 -> V_4 + V_5 ) & V_6 ) ? true : false ;
}
static inline bool F_4 ( struct V_1 * V_2 )
{
T_1 V_7 ;
if ( ! V_2 )
return false ;
V_7 = F_3 ( V_2 -> V_4 + V_8 ) ;
if ( F_1 ( V_2 ) )
V_7 &= V_9 ;
else
V_7 &= V_10 ;
return V_7 ? true : false ;
}
static inline bool F_5 ( struct V_1 * V_2 )
{
struct V_1 * V_11 = V_2 -> V_3 ? : V_2 -> V_12 ;
return F_4 ( V_11 ) ;
}
static inline bool F_6 ( struct V_1 * V_2 )
{
return F_4 ( V_2 ) || F_5 ( V_2 ) ;
}
static inline bool F_7 ( struct V_1 * V_2 )
{
T_1 V_7 ;
if ( ! V_2 )
return false ;
V_7 = F_3 ( V_2 -> V_4 + V_8 ) & V_13 ;
return V_7 ? true : false ;
}
static inline bool F_8 ( struct V_1 * V_2 )
{
struct V_1 * V_11 = V_2 -> V_3 ? : V_2 -> V_12 ;
return F_7 ( V_11 ) ;
}
static inline bool F_9 ( struct V_1 * V_2 )
{
return F_7 ( V_2 ) || F_8 ( V_2 ) ;
}
static inline bool F_10 ( struct V_1 * V_2 )
{
return F_8 ( V_2 ) || F_5 ( V_2 ) ;
}
static inline bool F_11 ( struct V_1 * V_2 )
{
return F_4 ( V_2 ) || F_7 ( V_2 ) ;
}
static inline bool F_12 ( struct V_1 * V_2 )
{
return F_11 ( V_2 ) || F_10 ( V_2 ) ;
}
static inline struct V_1 * F_13 ( struct V_14 * V_15 )
{
return F_14 ( V_15 ) ;
}
static inline bool F_15 ( struct V_1 * V_2 )
{
if ( V_2 && ( V_2 -> V_16 & V_17 ) )
return true ;
else
return false ;
}
static inline bool F_16 ( struct V_1 * V_2 )
{
if ( F_15 ( V_2 ) && ( V_2 -> V_16 & V_18 ) )
return true ;
else
return false ;
}
static inline unsigned F_17 ( struct V_1 * V_2 )
{
T_1 V_19 = ( F_3 ( V_2 -> V_4 + V_5 ) >> 3 ) & 0x3 ;
switch ( V_19 ) {
case 3 : return 768 ;
case 2 : return 384 ;
case 1 : return 512 ;
default: return 256 ;
}
}
static inline void F_18 ( struct V_1 * V_2 , unsigned V_19 )
{
T_1 V_20 = F_3 ( V_2 -> V_4 + V_5 ) ;
V_20 &= ~ V_21 ;
switch ( V_19 ) {
case 768 :
V_20 |= V_22 ;
break;
case 512 :
V_20 |= V_23 ;
break;
case 384 :
V_20 |= V_24 ;
break;
default:
V_20 |= V_25 ;
break;
}
F_19 ( V_20 , V_2 -> V_4 + V_5 ) ;
}
static inline unsigned F_20 ( struct V_1 * V_2 )
{
T_1 V_26 = ( F_3 ( V_2 -> V_4 + V_5 ) >> 1 ) & 0x3 ;
switch ( V_26 ) {
case 3 : return 24 ;
case 2 : return 16 ;
case 1 : return 48 ;
default: return 32 ;
}
}
static inline void F_21 ( struct V_1 * V_2 , unsigned V_26 )
{
T_1 V_20 = F_3 ( V_2 -> V_4 + V_5 ) ;
V_20 &= ~ V_27 ;
switch ( V_26 ) {
case 48 :
V_20 |= V_28 ;
break;
case 32 :
V_20 |= V_29 ;
break;
case 24 :
V_20 |= V_30 ;
break;
case 16 :
V_20 |= V_31 ;
break;
default:
F_22 ( & V_2 -> V_32 -> V_33 , L_1 ) ;
return;
}
F_19 ( V_20 , V_2 -> V_4 + V_5 ) ;
}
static inline int F_23 ( struct V_1 * V_2 )
{
int V_34 = F_3 ( V_2 -> V_4 + V_5 ) ;
V_34 = ( V_34 >> 13 ) & 0x3 ;
switch ( V_34 ) {
case 2 : return 24 ;
case 1 : return 8 ;
default: return 16 ;
}
}
static void F_24 ( struct V_1 * V_2 , int V_35 )
{
void T_2 * V_4 = V_2 -> V_4 ;
T_1 V_36 = F_3 ( V_4 + V_8 ) ;
T_1 V_20 = F_3 ( V_4 + V_5 ) & ~ V_37 ;
if ( V_35 ) {
V_36 |= V_38 ;
V_36 &= ~ V_39 ;
if ( F_1 ( V_2 ) ) {
V_36 |= V_9 ;
V_36 &= ~ V_40 ;
} else {
V_36 |= V_10 ;
V_36 &= ~ V_41 ;
}
if ( F_9 ( V_2 ) )
V_20 |= V_42 ;
else
V_20 |= V_43 ;
} else {
if ( F_1 ( V_2 ) ) {
V_36 |= V_40 ;
V_36 &= ~ V_9 ;
} else {
V_36 |= V_41 ;
V_36 &= ~ V_10 ;
}
if ( F_5 ( V_2 ) ) {
F_19 ( V_36 , V_4 + V_8 ) ;
return;
}
V_36 |= V_39 ;
if ( F_9 ( V_2 ) )
V_20 |= V_44 ;
else
V_36 &= ~ V_38 ;
}
F_19 ( V_20 , V_4 + V_5 ) ;
F_19 ( V_36 , V_4 + V_8 ) ;
}
static void F_25 ( struct V_1 * V_2 , int V_35 )
{
void T_2 * V_4 = V_2 -> V_4 ;
T_1 V_36 = F_3 ( V_4 + V_8 ) ;
T_1 V_20 = F_3 ( V_4 + V_5 ) & ~ V_37 ;
if ( V_35 ) {
V_36 |= V_13 | V_38 ;
V_36 &= ~ ( V_45 | V_46 ) ;
if ( F_6 ( V_2 ) )
V_20 |= V_42 ;
else
V_20 |= V_44 ;
} else {
V_36 |= V_45 | V_46 ;
V_36 &= ~ V_13 ;
if ( F_6 ( V_2 ) )
V_20 |= V_43 ;
else
V_36 &= ~ V_38 ;
}
F_19 ( V_20 , V_4 + V_5 ) ;
F_19 ( V_36 , V_4 + V_8 ) ;
}
static inline void F_26 ( struct V_1 * V_2 , T_1 V_47 )
{
void T_2 * V_48 ;
T_1 V_49 ;
if ( ! V_2 )
return;
if ( F_1 ( V_2 ) )
V_48 = V_2 -> V_4 + V_50 ;
else
V_48 = V_2 -> V_4 + V_51 ;
F_19 ( F_3 ( V_48 ) | V_47 , V_48 ) ;
V_49 = F_27 ( 1 ) / 1000 ;
while ( -- V_49 )
F_28 () ;
F_19 ( F_3 ( V_48 ) & ~ V_47 , V_48 ) ;
}
static int F_29 ( struct V_14 * V_15 ,
int V_52 , unsigned int V_19 , int V_53 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
struct V_1 * V_11 = V_2 -> V_3 ? : V_2 -> V_12 ;
T_1 V_20 = F_3 ( V_2 -> V_4 + V_5 ) ;
switch ( V_52 ) {
case V_54 :
if ( V_53 == V_55 )
V_19 = 0 ;
if ( ( V_19 && V_11 -> V_19 && ( V_11 -> V_19 != V_19 ) ) ||
( F_12 ( V_2 ) &&
( ( ( V_53 == V_55 )
&& ! ( V_20 & V_56 ) ) ||
( ( V_53 == V_57 )
&& ( V_20 & V_56 ) ) ) ) ) {
F_22 ( & V_2 -> V_32 -> V_33 ,
L_2 , V_58 , __LINE__ ) ;
return - V_59 ;
}
if ( V_53 == V_55 )
V_20 |= V_56 ;
else
V_20 &= ~ V_56 ;
V_2 -> V_19 = V_19 ;
break;
case V_60 :
case V_61 :
if ( ( V_2 -> V_62 & V_63 )
|| ( V_52 == V_60 ) )
V_52 = 0 ;
else
V_52 = 1 ;
if ( ! F_12 ( V_2 ) ) {
if ( V_2 -> V_64 ) {
if ( ( V_52 && ! ( V_20 & V_65 ) ) ||
( ! V_52 && ( V_20 & V_65 ) ) ) {
F_30 ( V_2 -> V_64 ) ;
F_31 ( V_2 -> V_64 ) ;
} else {
V_2 -> V_66 =
F_32 ( V_2 -> V_64 ) ;
return 0 ;
}
}
if ( V_52 )
V_2 -> V_64 = F_33 ( & V_2 -> V_32 -> V_33 ,
L_3 ) ;
else
V_2 -> V_64 = F_33 ( & V_2 -> V_32 -> V_33 ,
L_4 ) ;
F_34 ( V_2 -> V_64 ) ;
V_2 -> V_66 = F_32 ( V_2 -> V_64 ) ;
if ( V_11 ) {
V_11 -> V_64 = V_2 -> V_64 ;
V_11 -> V_66 = V_2 -> V_66 ;
}
} else if ( ( ! V_52 && ( V_20 & V_65 ) )
|| ( V_52 && ! ( V_20 & V_65 ) ) ) {
F_22 ( & V_2 -> V_32 -> V_33 ,
L_2 , V_58 , __LINE__ ) ;
return - V_59 ;
} else {
V_2 -> V_64 = V_11 -> V_64 ;
V_2 -> V_66 = V_11 -> V_66 ;
return 0 ;
}
if ( V_52 == 0 )
V_20 &= ~ V_65 ;
else
V_20 |= V_65 ;
break;
default:
F_22 ( & V_2 -> V_32 -> V_33 , L_5 ) ;
return - V_67 ;
}
F_19 ( V_20 , V_2 -> V_4 + V_5 ) ;
return 0 ;
}
static int F_35 ( struct V_14 * V_15 ,
unsigned int V_68 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
T_1 V_20 = F_3 ( V_2 -> V_4 + V_5 ) ;
T_1 V_69 = 0 ;
switch ( V_68 & V_70 ) {
case V_71 :
V_69 |= V_72 ;
V_69 |= V_73 ;
break;
case V_74 :
V_69 |= V_72 ;
V_69 |= V_75 ;
break;
case V_76 :
V_69 |= V_77 ;
break;
default:
F_22 ( & V_2 -> V_32 -> V_33 , L_6 ) ;
return - V_67 ;
}
switch ( V_68 & V_78 ) {
case V_79 :
break;
case V_80 :
if ( V_69 & V_72 )
V_69 &= ~ V_72 ;
else
V_69 |= V_72 ;
break;
default:
F_22 ( & V_2 -> V_32 -> V_33 , L_7 ) ;
return - V_67 ;
}
switch ( V_68 & V_81 ) {
case V_82 :
V_69 |= V_6 ;
break;
case V_83 :
if ( V_2 -> V_66 == 0 )
F_29 ( V_15 , V_60 ,
0 , V_55 ) ;
break;
default:
F_22 ( & V_2 -> V_32 -> V_33 , L_8 ) ;
return - V_67 ;
}
if ( F_12 ( V_2 ) &&
( ( V_20 & ( V_84 | V_72
| V_6 ) ) != V_69 ) ) {
F_22 ( & V_2 -> V_32 -> V_33 ,
L_2 , V_58 , __LINE__ ) ;
return - V_59 ;
}
V_20 &= ~ ( V_84 | V_72 | V_6 ) ;
V_20 |= V_69 ;
F_19 ( V_20 , V_2 -> V_4 + V_5 ) ;
return 0 ;
}
static int F_36 ( struct V_85 * V_86 ,
struct V_87 * V_88 , struct V_14 * V_15 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
T_1 V_20 = F_3 ( V_2 -> V_4 + V_5 ) ;
if ( ! F_1 ( V_2 ) )
V_20 &= ~ ( V_89 | V_90 ) ;
switch ( F_37 ( V_88 ) ) {
case 6 :
V_20 |= V_89 ;
case 4 :
V_20 |= V_90 ;
break;
case 2 :
if ( V_86 -> V_91 == V_92 )
V_2 -> V_93 . V_94 = 4 ;
else
V_2 -> V_95 . V_94 = 4 ;
break;
case 1 :
if ( V_86 -> V_91 == V_92 )
V_2 -> V_93 . V_94 = 2 ;
else
V_2 -> V_95 . V_94 = 2 ;
break;
default:
F_22 ( & V_2 -> V_32 -> V_33 , L_9 ,
F_37 ( V_88 ) ) ;
return - V_67 ;
}
if ( F_1 ( V_2 ) )
V_20 &= ~ V_96 ;
else
V_20 &= ~ V_97 ;
if ( F_16 ( V_2 ) )
V_20 &= ~ V_98 ;
switch ( F_38 ( V_88 ) ) {
case V_99 :
if ( F_1 ( V_2 ) )
V_20 |= V_100 ;
else
V_20 |= V_101 ;
if ( F_16 ( V_2 ) )
V_20 |= V_102 ;
break;
case V_103 :
if ( F_1 ( V_2 ) )
V_20 |= V_104 ;
else
V_20 |= V_105 ;
if ( F_16 ( V_2 ) )
V_20 |= V_106 ;
break;
case V_107 :
if ( F_1 ( V_2 ) )
V_20 |= V_108 ;
else
V_20 |= V_109 ;
if ( F_16 ( V_2 ) )
V_20 |= V_110 ;
break;
default:
F_22 ( & V_2 -> V_32 -> V_33 , L_10 ,
F_38 ( V_88 ) ) ;
return - V_67 ;
}
F_19 ( V_20 , V_2 -> V_4 + V_5 ) ;
if ( V_86 -> V_91 == V_92 )
F_39 ( V_15 , V_86 ,
( void * ) & V_2 -> V_93 ) ;
else
F_39 ( V_15 , V_86 ,
( void * ) & V_2 -> V_95 ) ;
V_2 -> V_111 = F_40 ( V_88 ) ;
return 0 ;
}
static int F_41 ( struct V_85 * V_86 ,
struct V_14 * V_15 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
struct V_1 * V_11 = V_2 -> V_3 ? : V_2 -> V_12 ;
unsigned long V_112 ;
F_42 ( & V_113 , V_112 ) ;
V_2 -> V_16 |= V_17 ;
if ( F_16 ( V_11 ) )
V_2 -> V_16 &= ~ V_18 ;
else
V_2 -> V_16 |= V_18 ;
V_2 -> V_66 = 0 ;
F_43 ( & V_113 , V_112 ) ;
return 0 ;
}
static void F_44 ( struct V_85 * V_86 ,
struct V_14 * V_15 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
struct V_1 * V_11 = V_2 -> V_3 ? : V_2 -> V_12 ;
unsigned long V_112 ;
F_42 ( & V_113 , V_112 ) ;
V_2 -> V_16 &= ~ V_17 ;
V_2 -> V_16 &= ~ V_18 ;
if ( F_15 ( V_11 ) )
V_11 -> V_16 |= V_18 ;
V_2 -> V_19 = 0 ;
V_2 -> V_26 = 0 ;
F_43 ( & V_113 , V_112 ) ;
if ( ! F_15 ( V_11 ) )
F_29 ( V_15 , V_54 ,
0 , V_55 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_1 * V_11 = V_2 -> V_3 ? : V_2 -> V_12 ;
unsigned V_19 , V_26 , V_34 ;
T_1 V_114 ;
V_34 = F_23 ( V_2 ) ;
V_26 = V_2 -> V_26 ;
if ( ! V_26 && V_11 )
V_26 = V_11 -> V_26 ;
if ( ! V_26 )
V_26 = V_34 * 2 ;
V_19 = V_2 -> V_19 ;
if ( ! V_19 && V_11 )
V_19 = V_11 -> V_19 ;
if ( ( V_19 == 256 || V_19 == 512 ) && ( V_34 == 24 ) ) {
F_22 ( & V_2 -> V_32 -> V_33 ,
L_11 , V_19 ) ;
return - V_67 ;
}
if ( ! V_19 ) {
if ( V_26 == 16 || V_26 == 32 )
V_19 = 256 ;
else
V_19 = 384 ;
}
if ( F_12 ( V_2 ) && ( F_17 ( V_2 ) != V_19 || F_20 ( V_2 ) != V_26 ) ) {
F_22 ( & V_2 -> V_32 -> V_33 ,
L_2 , V_58 , __LINE__ ) ;
return - V_59 ;
}
if ( F_2 ( V_2 ) )
return 0 ;
F_21 ( V_2 , V_26 ) ;
F_18 ( V_2 , V_19 ) ;
if ( ! ( V_2 -> V_62 & V_63 ) ) {
V_114 = V_2 -> V_66 / V_2 -> V_111 / V_19 ;
F_19 ( ( ( V_114 - 1 ) << 8 ) | V_115 , V_2 -> V_4 + V_116 ) ;
F_46 ( & V_2 -> V_32 -> V_33 ,
L_12 ,
V_2 -> V_66 , V_114 , V_19 , V_26 ) ;
}
return 0 ;
}
static int F_47 ( struct V_85 * V_86 ,
int V_117 , struct V_14 * V_15 )
{
int V_118 = ( V_86 -> V_91 == V_119 ) ;
struct V_120 * V_121 = V_86 -> V_122 ;
struct V_1 * V_2 = F_13 ( V_121 -> V_123 ) ;
unsigned long V_112 ;
switch ( V_117 ) {
case V_124 :
case V_125 :
case V_126 :
F_48 ( V_112 ) ;
if ( F_45 ( V_2 ) ) {
F_49 ( V_112 ) ;
return - V_67 ;
}
if ( V_118 )
F_25 ( V_2 , 1 ) ;
else
F_24 ( V_2 , 1 ) ;
F_49 ( V_112 ) ;
break;
case V_127 :
case V_128 :
case V_129 :
F_48 ( V_112 ) ;
if ( V_118 ) {
F_25 ( V_2 , 0 ) ;
F_26 ( V_2 , V_130 ) ;
} else {
F_24 ( V_2 , 0 ) ;
F_26 ( V_2 , V_131 ) ;
}
F_49 ( V_112 ) ;
break;
}
return 0 ;
}
static int F_50 ( struct V_14 * V_15 ,
int V_132 , int div )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
struct V_1 * V_11 = V_2 -> V_3 ? : V_2 -> V_12 ;
switch ( V_132 ) {
case V_133 :
if ( ( F_12 ( V_2 ) && div && ( F_20 ( V_2 ) != div ) )
|| ( V_11 && V_11 -> V_26 && ( V_11 -> V_26 != div ) ) ) {
F_22 ( & V_2 -> V_32 -> V_33 ,
L_2 , V_58 , __LINE__ ) ;
return - V_59 ;
}
V_2 -> V_26 = div ;
break;
default:
F_22 ( & V_2 -> V_32 -> V_33 ,
L_13 , V_132 ) ;
return - V_67 ;
}
return 0 ;
}
static T_3
F_51 ( struct V_85 * V_86 , struct V_14 * V_15 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
T_1 V_134 = F_3 ( V_2 -> V_4 + V_51 ) ;
T_3 V_135 ;
if ( V_86 -> V_91 == V_119 )
V_135 = F_52 ( V_134 ) ;
else if ( F_1 ( V_2 ) )
V_135 = F_53 ( F_3 ( V_2 -> V_4 + V_50 ) ) ;
else
V_135 = F_54 ( V_134 ) ;
return V_135 ;
}
static int F_55 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
if ( V_15 -> V_7 ) {
V_2 -> V_136 = F_3 ( V_2 -> V_4 + V_5 ) ;
V_2 -> V_137 = F_3 ( V_2 -> V_4 + V_8 ) ;
V_2 -> V_138 = F_3 ( V_2 -> V_4 + V_116 ) ;
}
return 0 ;
}
static int F_56 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
if ( V_15 -> V_7 ) {
F_19 ( V_2 -> V_137 , V_2 -> V_4 + V_8 ) ;
F_19 ( V_2 -> V_136 , V_2 -> V_4 + V_5 ) ;
F_19 ( V_2 -> V_138 , V_2 -> V_4 + V_116 ) ;
}
return 0 ;
}
static int F_57 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
struct V_1 * V_11 = V_2 -> V_3 ? : V_2 -> V_12 ;
if ( V_11 && V_11 -> V_139 )
goto V_140;
V_2 -> V_4 = F_58 ( V_2 -> V_141 , 0x100 ) ;
if ( V_2 -> V_4 == NULL ) {
F_22 ( & V_2 -> V_32 -> V_33 , L_14 ) ;
return - V_142 ;
}
V_2 -> V_139 = F_33 ( & V_2 -> V_32 -> V_33 , L_15 ) ;
if ( F_59 ( V_2 -> V_139 ) ) {
F_22 ( & V_2 -> V_32 -> V_33 , L_16 ) ;
F_60 ( V_2 -> V_4 ) ;
return - V_143 ;
}
F_34 ( V_2 -> V_139 ) ;
if ( V_11 ) {
V_11 -> V_4 = V_2 -> V_4 ;
V_11 -> V_139 = V_2 -> V_139 ;
}
if ( V_2 -> V_62 & V_144 )
F_19 ( V_145 , V_2 -> V_4 + V_8 ) ;
if ( V_2 -> V_62 & V_146 )
F_61 ( V_2 -> V_4 ,
V_2 -> V_12 -> V_147 . V_148 ) ;
V_140:
V_2 -> V_19 = 0 ;
V_2 -> V_26 = 0 ;
F_24 ( V_2 , 0 ) ;
F_25 ( V_2 , 0 ) ;
F_26 ( V_2 , V_131 ) ;
F_26 ( V_11 , V_131 ) ;
F_26 ( V_2 , V_130 ) ;
if ( ! F_15 ( V_11 ) )
F_29 ( V_15 , V_54 ,
0 , V_55 ) ;
return 0 ;
}
static int F_62 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_14 ( V_15 ) ;
struct V_1 * V_11 = V_2 -> V_3 ? : V_2 -> V_12 ;
if ( ! V_11 || ! V_11 -> V_139 ) {
if ( V_2 -> V_62 & V_144 )
F_19 ( 0 , V_2 -> V_4 + V_8 ) ;
F_30 ( V_2 -> V_139 ) ;
F_31 ( V_2 -> V_139 ) ;
F_60 ( V_2 -> V_4 ) ;
}
V_2 -> V_139 = NULL ;
return 0 ;
}
static struct V_1 * F_63 ( struct V_149 * V_32 , bool V_150 )
{
struct V_1 * V_2 ;
V_2 = F_64 ( & V_32 -> V_33 , sizeof( struct V_1 ) , V_151 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_32 = V_32 ;
V_2 -> V_3 = NULL ;
V_2 -> V_12 = NULL ;
V_2 -> V_152 . V_153 = 1 ;
V_2 -> V_152 . V_154 = F_57 ;
V_2 -> V_152 . remove = F_62 ;
V_2 -> V_152 . V_155 = & V_156 ;
V_2 -> V_152 . V_157 = F_55 ;
V_2 -> V_152 . V_158 = F_56 ;
V_2 -> V_152 . V_159 . V_160 = 2 ;
V_2 -> V_152 . V_159 . V_161 = 2 ;
V_2 -> V_152 . V_159 . V_162 = V_163 ;
V_2 -> V_152 . V_159 . V_164 = V_165 ;
if ( ! V_150 ) {
V_2 -> V_152 . V_118 . V_160 = 1 ;
V_2 -> V_152 . V_118 . V_161 = 2 ;
V_2 -> V_152 . V_118 . V_162 = V_163 ;
V_2 -> V_152 . V_118 . V_164 = V_165 ;
} else {
V_2 -> V_32 = F_65 ( NULL ,
V_32 -> V_166 , V_32 -> V_167 + V_168 ,
NULL , 0 , NULL , 0 ) ;
if ( F_59 ( V_2 -> V_32 ) )
return NULL ;
}
F_66 ( & V_2 -> V_32 -> V_33 , V_2 ) ;
return V_2 ;
}
static int F_67 ( struct V_149 * V_32 )
{
T_1 V_169 , V_170 , V_171 ;
struct V_1 * V_3 , * V_12 = NULL ;
struct V_172 * V_173 ;
struct V_174 * V_175 ;
struct V_176 * V_177 ;
T_1 V_178 , V_62 ;
int V_179 = 0 ;
if ( V_32 -> V_167 >= V_168 ) {
V_12 = F_68 ( & V_32 -> V_33 ) ;
F_69 ( & V_12 -> V_32 -> V_33 ,
& V_12 -> V_152 ) ;
F_70 ( & V_32 -> V_33 ) ;
return 0 ;
}
V_173 = V_32 -> V_33 . V_180 ;
if ( V_173 == NULL ) {
F_22 ( & V_32 -> V_33 , L_17 ) ;
return - V_67 ;
}
V_177 = F_71 ( V_32 , V_181 , 0 ) ;
if ( ! V_177 ) {
F_22 ( & V_32 -> V_33 , L_18 ) ;
return - V_142 ;
}
V_169 = V_177 -> V_182 ;
V_177 = F_71 ( V_32 , V_181 , 1 ) ;
if ( ! V_177 ) {
F_22 ( & V_32 -> V_33 , L_19 ) ;
return - V_142 ;
}
V_170 = V_177 -> V_182 ;
V_177 = F_71 ( V_32 , V_181 , 2 ) ;
if ( V_177 )
V_171 = V_177 -> V_182 ;
else
V_171 = 0 ;
V_177 = F_71 ( V_32 , V_183 , 0 ) ;
if ( ! V_177 ) {
F_22 ( & V_32 -> V_33 , L_20 ) ;
return - V_142 ;
}
if ( ! F_72 ( V_177 -> V_182 , F_73 ( V_177 ) ,
L_21 ) ) {
F_22 ( & V_32 -> V_33 , L_22 ) ;
return - V_184 ;
}
V_178 = V_177 -> V_182 ;
V_175 = & V_173 -> type . V_2 ;
V_62 = V_175 -> V_62 ;
V_3 = F_63 ( V_32 , false ) ;
if ( ! V_3 ) {
F_22 ( & V_32 -> V_33 , L_23 ) ;
V_179 = - V_185 ;
goto V_186;
}
V_3 -> V_93 . V_148 = V_178 + V_187 ;
V_3 -> V_95 . V_148 = V_178 + V_188 ;
V_3 -> V_93 . V_189 =
(struct V_190 * ) & V_3 -> V_93 ;
V_3 -> V_95 . V_189 =
(struct V_190 * ) & V_3 -> V_95 ;
V_3 -> V_93 . V_191 = V_169 ;
V_3 -> V_95 . V_191 = V_170 ;
V_3 -> V_93 . V_94 = 4 ;
V_3 -> V_95 . V_94 = 4 ;
V_3 -> V_141 = V_178 ;
V_3 -> V_62 = V_62 ;
if ( V_62 & V_192 )
V_3 -> V_152 . V_159 . V_161 = 6 ;
if ( V_62 & V_146 ) {
V_12 = F_63 ( V_32 , true ) ;
if ( ! V_12 ) {
F_22 ( & V_32 -> V_33 , L_24 ) ;
V_179 = - V_185 ;
goto V_186;
}
V_12 -> V_93 . V_148 = V_178 + V_193 ;
V_12 -> V_93 . V_189 =
(struct V_190 * ) & V_12 -> V_93 ;
V_12 -> V_93 . V_191 = V_171 ? : - 1 ;
V_12 -> V_93 . V_94 = 4 ;
V_12 -> V_141 = V_178 ;
V_12 -> V_62 = V_62 ;
V_12 -> V_147 . V_148 = V_175 -> V_194 ;
V_12 -> V_3 = V_3 ;
V_3 -> V_12 = V_12 ;
}
if ( V_173 -> V_195 && V_173 -> V_195 ( V_32 ) ) {
F_22 ( & V_32 -> V_33 , L_25 ) ;
V_179 = - V_67 ;
goto V_186;
}
F_69 ( & V_3 -> V_32 -> V_33 , & V_3 -> V_152 ) ;
F_74 ( & V_32 -> V_33 ) ;
F_70 ( & V_32 -> V_33 ) ;
return 0 ;
V_186:
F_75 ( V_178 , F_73 ( V_177 ) ) ;
return V_179 ;
}
static int F_76 ( struct V_149 * V_32 )
{
struct V_1 * V_2 , * V_11 ;
struct V_176 * V_177 ;
V_2 = F_68 ( & V_32 -> V_33 ) ;
V_11 = V_2 -> V_3 ? : V_2 -> V_12 ;
if ( V_11 ) {
V_11 -> V_3 = NULL ;
V_11 -> V_12 = NULL ;
} else {
F_77 ( & V_32 -> V_33 ) ;
V_177 = F_71 ( V_32 , V_183 , 0 ) ;
if ( V_177 )
F_75 ( V_177 -> V_182 , F_73 ( V_177 ) ) ;
}
V_2 -> V_3 = NULL ;
V_2 -> V_12 = NULL ;
F_78 ( & V_32 -> V_33 ) ;
F_79 ( & V_32 -> V_33 ) ;
return 0 ;
}
