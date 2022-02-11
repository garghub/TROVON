static inline T_1
F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void
F_3 ( struct V_1 * V_2 , unsigned V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline T_2
F_5 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_6 ( V_2 -> V_4 + V_3 ) ;
}
static inline void
F_7 ( struct V_1 * V_2 , unsigned V_3 , T_2 V_5 )
{
F_8 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void
F_9 ( struct V_1 * V_2 )
{
T_1 V_6 ;
V_6 = F_1 ( V_2 , V_7 ) &
~ ( V_8 | V_9 ) ;
F_3 ( V_2 , V_7 , V_6 ) ;
F_1 ( V_2 , V_7 ) ;
}
static inline void
F_10 ( struct V_1 * V_2 )
{
T_1 V_6 ;
V_6 = F_1 ( V_2 , V_7 ) | V_8 | V_9 ;
F_3 ( V_2 , V_7 , V_6 ) ;
F_1 ( V_2 , V_7 ) ;
}
static inline void
F_11 ( struct V_1 * V_2 , T_2 V_10 )
{
F_7 ( V_2 , V_11 , V_10 ) ;
F_7 ( V_2 , V_12 , V_10 ) ;
}
static inline void
F_12 ( struct V_1 * V_2 , T_2 V_13 )
{
F_7 ( V_2 , V_14 , V_13 ) ;
F_7 ( V_2 , V_15 , V_13 ) ;
}
static inline void
F_13 ( struct V_1 * V_2 , T_2 V_13 )
{
F_7 ( V_2 , V_16 , V_13 ) ;
F_7 ( V_2 , V_17 , V_13 ) ;
}
static inline void
F_14 ( struct V_1 * V_2 , T_2 V_10 )
{
F_7 ( V_2 , V_18 , V_10 ) ;
F_7 ( V_2 , V_19 , V_10 ) ;
}
static inline void
F_15 ( struct V_1 * V_2 , T_2 V_13 )
{
F_7 ( V_2 , V_20 , V_13 ) ;
F_7 ( V_2 , V_21 , V_13 ) ;
}
static inline void
F_16 ( struct V_1 * V_2 , T_2 V_13 )
{
F_7 ( V_2 , V_22 , V_13 ) ;
F_7 ( V_2 , V_23 , V_13 ) ;
}
static void
F_17 ( struct V_1 * V_2 , unsigned int V_24 )
{
T_1 V_3 ;
if ( V_24 & V_25 ) {
V_3 = F_1 ( V_2 , V_26 ) & ~ V_27 ;
F_3 ( V_2 , V_26 , V_3 ) ;
V_2 -> V_28 . V_3 = V_3 ;
V_3 = F_1 ( V_2 , V_29 ) ;
V_3 &= V_30 ;
V_3 &= ~ V_31 ;
F_3 ( V_2 , V_29 , V_3 ) ;
F_14 ( V_2 , 0x0 ) ;
F_15 ( V_2 , 0x0 ) ;
F_16 ( V_2 , 0x0 ) ;
F_1 ( V_2 , V_29 ) ;
}
if ( V_24 & V_32 ) {
V_3 = F_1 ( V_2 , V_33 ) & ~ V_34 ;
F_3 ( V_2 , V_33 , V_3 ) ;
V_2 -> V_35 . V_3 = V_3 ;
V_3 = F_1 ( V_2 , V_36 ) ;
V_3 &= V_30 ;
V_3 &= ~ V_31 ;
F_3 ( V_2 , V_36 , V_3 ) ;
F_11 ( V_2 , 0x0 ) ;
F_12 ( V_2 , 0x0 ) ;
F_13 ( V_2 , 0x0 ) ;
F_1 ( V_2 , V_36 ) ;
}
}
static T_1
F_18 ( struct V_37 * V_38 , unsigned short V_3 )
{
struct V_1 * V_2 = V_38 -> V_39 ;
return F_1 ( V_2 , V_40 + V_3 ) ;
}
static void
F_19 ( struct V_37 * V_38 , unsigned short V_3 , unsigned short V_5 )
{
struct V_1 * V_2 = V_38 -> V_39 ;
F_3 ( V_2 , V_40 + V_3 , V_5 ) ;
}
static int
F_20 ( struct V_1 * V_2 )
{
int V_41 = 400 ;
while ( ! ( F_1 ( V_2 , V_42 ) & V_43 )
&& -- V_41 )
F_21 ( 1 ) ;
if ( ! V_41 ) {
F_22 ( V_2 -> V_44 -> V_45 , L_1 ,
V_46 ) ;
return - V_47 ;
}
F_23 ( V_2 -> V_44 -> V_45 , L_2 , V_46 , 400 - V_41 ) ;
return 0 ;
}
static int
F_24 ( struct V_48 * V_49 ,
struct V_50 * V_51 )
{
return F_25 ( V_49 ,
F_26 ( V_51 ) ) ;
}
static int
F_27 ( struct V_48 * V_49 )
{
return F_28 ( V_49 ) ;
}
static int
F_29 ( struct V_48 * V_52 )
{
struct V_1 * V_2 = F_30 ( V_52 ) ;
struct V_53 * V_54 = V_52 -> V_55 ;
V_2 -> V_56 = V_52 ;
V_54 -> V_57 = V_58 ;
return 0 ;
}
static int
F_31 ( struct V_48 * V_52 )
{
struct V_1 * V_2 = F_30 ( V_52 ) ;
struct V_53 * V_54 = V_52 -> V_55 ;
V_2 -> V_59 = V_52 ;
V_54 -> V_57 = V_60 ;
return 0 ;
}
static int
F_32 ( struct V_48 * V_52 )
{
struct V_1 * V_2 = F_30 ( V_52 ) ;
V_2 -> V_56 = NULL ;
return 0 ;
}
static int
F_33 ( struct V_48 * V_52 )
{
struct V_1 * V_2 = F_30 ( V_52 ) ;
V_2 -> V_59 = NULL ;
return 0 ;
}
static int
F_34 ( struct V_48 * V_52 )
{
struct V_1 * V_2 = F_30 ( V_52 ) ;
struct V_53 * V_54 = V_52 -> V_55 ;
unsigned int V_61 = F_35 ( V_52 ) ;
unsigned int V_13 = F_36 ( V_52 ) ;
T_1 V_3 ;
F_17 ( V_2 , V_25 ) ;
V_3 = F_1 ( V_2 , V_26 ) ;
V_3 &= ~ ( V_62 | V_63 ) ;
if ( F_37 ( V_54 -> V_64 ) == 16 )
V_3 |= V_62 ;
if ( V_54 -> V_65 > 1 )
V_3 |= V_63 ;
F_38 ( & V_2 -> V_66 ) ;
V_2 -> V_28 . V_61 = V_61 ;
V_2 -> V_28 . V_3 = V_3 ;
V_2 -> V_28 . V_67 = V_54 -> V_68 ;
F_3 ( V_2 , V_26 , V_2 -> V_28 . V_3 ) ;
F_3 ( V_2 , V_69 , V_54 -> V_70 ) ;
F_14 ( V_2 , V_2 -> V_28 . V_67 ) ;
F_15 ( V_2 , V_61 ) ;
F_16 ( V_2 , V_13 ) ;
F_1 ( V_2 , V_26 ) ;
F_39 ( & V_2 -> V_66 ) ;
F_23 ( V_2 -> V_44 -> V_45 ,
L_3 ,
V_2 -> V_28 . V_67 , V_13 , V_61 , V_3 , V_54 -> V_70 ) ;
return 0 ;
}
static int
F_40 ( struct V_48 * V_52 )
{
struct V_1 * V_2 = F_30 ( V_52 ) ;
struct V_53 * V_54 = V_52 -> V_55 ;
unsigned int V_61 = F_35 ( V_52 ) ;
unsigned int V_13 = F_36 ( V_52 ) ;
T_1 V_3 ;
F_17 ( V_2 , V_32 ) ;
V_3 = F_1 ( V_2 , V_33 ) ;
V_3 &= ~ ( V_71 | V_72 ) ;
if ( F_37 ( V_54 -> V_64 ) == 16 )
V_3 |= V_71 ;
if ( V_54 -> V_65 > 1 )
V_3 |= V_72 ;
F_38 ( & V_2 -> V_66 ) ;
V_2 -> V_35 . V_61 = V_61 ;
V_2 -> V_35 . V_3 = V_3 ;
V_2 -> V_35 . V_67 = V_54 -> V_68 ;
F_3 ( V_2 , V_33 , V_2 -> V_35 . V_3 ) ;
F_11 ( V_2 , V_2 -> V_35 . V_67 ) ;
F_12 ( V_2 , V_61 ) ;
F_13 ( V_2 , V_13 ) ;
F_1 ( V_2 , V_33 ) ;
F_39 ( & V_2 -> V_66 ) ;
F_23 ( V_2 -> V_44 -> V_45 ,
L_4 ,
V_2 -> V_35 . V_67 , V_13 , V_61 , V_3 , V_54 -> V_70 ) ;
return 0 ;
}
static int
F_41 ( struct V_48 * V_52 , int V_73 )
{
T_1 V_74 ;
struct V_1 * V_2 = F_30 ( V_52 ) ;
V_74 = F_1 ( V_2 , V_26 ) ;
switch ( V_73 ) {
case V_75 :
F_3 ( V_2 , V_29 , V_31 | V_76 ) ;
V_74 |= V_27 ;
F_7 ( V_2 , V_77 , V_78 ) ;
F_9 ( V_2 ) ;
break;
case V_79 :
F_10 ( V_2 ) ;
V_74 &= ~ V_27 ;
break;
default:
F_42 () ;
return - V_80 ;
}
V_2 -> V_28 . V_3 = V_74 ;
F_3 ( V_2 , V_26 , V_74 ) ;
F_1 ( V_2 , V_26 ) ;
if ( V_73 == V_79 )
F_17 ( V_2 , V_25 ) ;
return 0 ;
}
static int
F_43 ( struct V_48 * V_52 , int V_73 )
{
T_1 V_35 ;
struct V_1 * V_2 = F_30 ( V_52 ) ;
V_35 = F_1 ( V_2 , V_33 ) ;
switch ( V_73 ) {
case V_75 :
F_3 ( V_2 , V_36 , V_31 | V_76 ) ;
V_35 |= V_34 ;
F_7 ( V_2 , V_77 , V_81 ) ;
break;
case V_79 :
V_35 &= ~ V_34 ;
break;
default:
return - V_80 ;
}
V_2 -> V_35 . V_3 = V_35 ;
F_3 ( V_2 , V_33 , V_35 ) ;
F_1 ( V_2 , V_33 ) ;
if ( V_73 == V_79 )
F_17 ( V_2 , V_32 ) ;
return 0 ;
}
static T_3
F_44 ( struct V_48 * V_52 )
{
T_4 V_82 = 0 ;
struct V_1 * V_2 = F_30 ( V_52 ) ;
if ( F_45 ( ! ( V_2 -> V_28 . V_3 & V_27 ) ) )
return 0 ;
V_82 = F_5 ( V_2 , V_19 ) ;
V_82 -= V_2 -> V_28 . V_67 ;
if ( F_46 ( V_82 >= V_2 -> V_28 . V_61 ) )
return 0 ;
return F_47 ( V_52 -> V_55 , V_82 ) ;
}
static T_3
F_48 ( struct V_48 * V_52 )
{
T_4 V_82 = 0 ;
struct V_1 * V_2 = F_30 ( V_52 ) ;
if ( F_45 ( ! ( V_2 -> V_35 . V_3 & V_34 ) ) )
return 0 ;
V_82 = F_5 ( V_2 , V_12 ) ;
V_82 -= V_2 -> V_35 . V_67 ;
if ( F_46 ( V_82 >= V_2 -> V_35 . V_61 ) )
return 0 ;
return F_47 ( V_52 -> V_55 , V_82 ) ;
}
static T_5
F_49 ( int V_83 , void * V_84 )
{
unsigned long V_6 ;
struct V_1 * V_2 = V_84 ;
V_6 = F_5 ( V_2 , V_85 ) ;
F_7 ( V_2 , V_85 , V_6 ) ;
V_6 &= V_86 ;
if ( F_45 ( ! V_6 ) )
return V_87 ;
if ( V_6 & ( V_88 | V_89 ) )
F_23 ( V_2 -> V_44 -> V_45 ,
L_5 ) ;
if ( ( V_6 & V_90 ) && V_2 -> V_56 )
F_50 ( V_2 -> V_56 ) ;
if ( ( V_6 & V_91 ) && V_2 -> V_59 )
F_50 ( V_2 -> V_59 ) ;
return V_92 ;
}
static int
F_51 ( struct V_1 * V_2 , int V_93 )
{
int V_94 ;
struct V_95 * V_96 ;
V_94 = F_52 ( V_2 -> V_44 , V_2 -> V_44 -> V_97 , V_93 , 1 , 1 , & V_96 ) ;
if ( V_94 < 0 )
return V_94 ;
F_53 ( V_96 , V_98 ,
& V_99 ) ;
F_53 ( V_96 , V_100 ,
& V_101 ) ;
V_96 -> V_39 = V_2 ;
V_96 -> V_102 = 0 ;
strcpy ( V_96 -> V_103 , V_2 -> V_44 -> V_104 ) ;
V_2 -> V_96 = V_96 ;
V_2 -> V_56 = NULL ;
V_2 -> V_59 = NULL ;
V_94 = F_54 ( V_96 , V_105 ,
F_55 ( V_2 -> V_106 ) ,
V_107 / 2 ,
V_107 ) ;
if ( V_94 < 0 ) {
F_22 ( V_2 -> V_44 -> V_45 , L_6 , V_94 ) ;
return V_94 ;
}
return 0 ;
}
static void
F_56 ( struct V_108 * V_109 , struct V_110 * V_111 )
{
struct V_1 * V_2 = V_109 -> V_39 ;
T_1 V_3 ;
int V_112 ;
V_3 = F_1 ( V_2 , V_26 ) ;
F_57 ( V_111 , L_7 ,
( V_3 & V_27 ) ? L_8 : L_9 ) ;
F_57 ( V_111 , L_10 ,
( V_3 & V_63 ) ? L_11 : L_12 ) ;
F_57 ( V_111 , L_13 ,
( V_3 & V_62 ) ? 16 : 8 ) ;
V_112 = ( V_3 & V_113 ) ?
( ( ( ( V_3 & V_113 ) >> 12 ) & 0x01 ) ? 12 : 18 ) : 4 ;
V_112 /= ( V_3 & V_63 ) ? 2 : 1 ;
F_57 ( V_111 , L_14 , V_112 ,
( V_3 & V_63 ) ? L_11 : L_12 ) ;
F_57 ( V_111 , L_15 ,
V_3 & V_114 ? L_8 : L_9 ) ;
V_112 = ( V_3 & V_115 ) ?
( ( ( ( V_3 & V_115 ) >> 4 ) & 0x01 ) ? 12 : 18 ) : 4 ;
V_112 /= ( V_3 & V_63 ) ? 2 : 1 ;
F_57 ( V_111 , L_16 , V_112 ,
( V_3 & V_63 ) ? L_11 : L_12 ) ;
V_3 = F_1 ( V_2 , V_33 ) ;
F_57 ( V_111 , L_17 ,
( V_3 & V_34 ) ? L_8 : L_9 ) ;
F_57 ( V_111 , L_18 ,
( V_3 & V_72 ) ? L_11 : L_12 ) ;
F_57 ( V_111 , L_19 ,
( V_3 & V_71 ) ? 16 : 8 ) ;
V_112 = ( V_3 & V_116 ) ?
( ( ( ( V_3 & V_116 ) >> 4 ) & 0x01 ) ? 12 : 18 ) : 4 ;
V_112 /= ( V_3 & V_72 ) ? 2 : 1 ;
F_57 ( V_111 , L_20 , V_112 ,
( V_3 & V_72 ) ? L_11 : L_12 ) ;
F_57 ( V_111 , L_21 ,
V_3 & V_117 ? L_8 : L_9 ) ;
V_112 = ( V_3 & V_118 ) ?
( ( ( ( V_3 & V_118 ) >> 12 ) & 0x01 ) ? 12 : 18 ) : 4 ;
V_112 /= ( V_3 & V_72 ) ? 2 : 1 ;
F_57 ( V_111 , L_22 , V_112 ,
( V_3 & V_63 ) ? L_11 : L_12 ) ;
V_3 = F_1 ( V_2 , V_7 ) ;
F_57 ( V_111 , L_23 ,
( V_3 & V_9 ) ? L_24 : L_25 ,
( ( V_3 & V_119 ) >> 8 ) * 3 ) ;
V_3 = F_1 ( V_2 , V_7 ) ;
F_57 ( V_111 , L_26 ,
( V_3 & V_8 ) ? L_24 : L_25 ,
( V_3 & V_120 ) * 3 ) ;
V_3 = F_1 ( V_2 , V_69 ) ;
F_57 ( V_111 , L_27 , V_3 ) ;
V_3 = F_1 ( V_2 , V_121 ) ;
F_57 ( V_111 , L_28 , V_3 ) ;
}
static void
F_58 ( struct V_1 * V_2 )
{
struct V_108 * V_109 ;
if ( ! F_59 ( V_2 -> V_44 , V_2 -> V_44 -> V_97 , & V_109 ) )
F_60 ( V_109 , V_2 , F_56 ) ;
}
static void
F_61 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_1 ( V_2 , V_42 ) ;
V_3 |= V_122 ;
F_3 ( V_2 , V_42 , V_3 ) ;
F_1 ( V_2 , V_42 ) ;
F_62 ( 10 ) ;
V_3 |= V_123 ;
F_3 ( V_2 , V_42 , V_3 ) ;
F_20 ( V_2 ) ;
V_3 = F_1 ( V_2 , V_42 ) ;
V_3 |= V_124 | V_125 ;
F_3 ( V_2 , V_42 , V_3 ) ;
F_1 ( V_2 , V_42 ) ;
}
static void
F_63 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = V_127 -> V_39 ;
V_2 -> V_128 = NULL ;
}
static void
F_64 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_39 ;
V_2 -> V_38 = NULL ;
}
static int
F_65 ( struct V_1 * V_2 , const char * V_129 )
{
int V_94 ;
struct V_130 V_38 ;
static struct V_131 V_132 = {
. V_133 = F_19 ,
. V_134 = F_18 ,
} ;
F_61 ( V_2 ) ;
V_94 = V_126 ( V_2 -> V_44 , 0 , & V_132 , V_2 , & V_2 -> V_128 ) ;
if ( V_94 < 0 )
return V_94 ;
V_2 -> V_128 -> V_135 = F_63 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . V_39 = V_2 ;
V_38 . V_135 = F_64 ;
V_38 . V_106 = V_2 -> V_106 ;
V_94 = F_66 ( V_2 -> V_128 , & V_38 , & V_2 -> V_38 ) ;
if ( V_94 < 0 )
return V_94 ;
F_67 ( V_2 -> V_38 , V_136 , V_129 ) ;
return 0 ;
}
static int
F_68 ( struct V_1 * V_2 )
{
if ( V_2 -> V_83 < 0 )
goto V_137;
F_38 ( & V_2 -> V_66 ) ;
F_10 ( V_2 ) ;
F_17 ( V_2 , V_25 | V_32 ) ;
F_7 ( V_2 , V_85 , V_89 | V_88 ) ;
F_5 ( V_2 , V_85 ) ;
F_39 ( & V_2 -> V_66 ) ;
if ( V_2 -> V_83 >= 0 )
F_69 ( V_2 -> V_83 , V_2 ) ;
V_137:
F_70 ( V_2 -> V_4 ) ;
F_71 ( V_2 -> V_106 ) ;
F_72 ( V_2 -> V_106 ) ;
F_73 ( V_2 ) ;
return 0 ;
}
static int
F_74 ( struct V_138 * V_93 )
{
struct V_1 * V_2 = V_93 -> V_139 ;
return F_68 ( V_2 ) ;
}
static int
F_75 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_140 , V_141 ) ;
F_1 ( V_2 , V_140 ) ;
F_21 ( 10 ) ;
F_7 ( V_2 , V_85 , V_142 | V_143 ) ;
return 0 ;
}
static int
F_76 ( struct V_144 * V_44 ,
struct V_145 * V_106 ,
struct V_1 * * V_146 )
{
int V_94 ;
struct V_1 * V_2 ;
static struct V_147 V_132 = {
. V_148 = F_74 ,
} ;
* V_146 = NULL ;
if ( ( V_94 = F_77 ( V_106 ) ) < 0 )
return V_94 ;
if ( F_78 ( & V_106 -> V_45 , F_79 ( 32 ) ) < 0 ||
F_80 ( & V_106 -> V_45 , F_79 ( 32 ) ) < 0 ) {
F_22 ( V_44 -> V_45 , L_29 ) ;
F_72 ( V_106 ) ;
return - V_149 ;
}
if ( ( V_2 = F_81 ( sizeof( * V_2 ) , V_150 ) ) == NULL ) {
F_72 ( V_106 ) ;
return - V_151 ;
}
V_2 -> V_44 = V_44 ;
V_44 -> V_39 = V_2 ;
V_2 -> V_106 = V_106 ;
V_2 -> V_83 = - 1 ;
if ( ( V_94 = F_82 ( V_106 , V_44 -> V_97 ) ) < 0 )
goto V_152;
V_2 -> V_153 = F_83 ( V_106 , 0 ) ;
V_2 -> V_4 = F_84 ( V_106 , 0 ) ;
if ( V_2 -> V_4 == NULL ) {
F_22 ( V_44 -> V_45 , L_30 ) ;
V_94 = - V_154 ;
goto V_152;
}
F_85 ( V_106 ) ;
F_86 ( & V_2 -> V_66 ) ;
if ( F_87 ( V_106 -> V_83 , F_49 ,
V_155 , V_156 , V_2 ) ) {
F_22 ( V_44 -> V_45 , L_31 , V_106 -> V_83 ) ;
F_68 ( V_2 ) ;
return - V_154 ;
}
V_2 -> V_83 = V_106 -> V_83 ;
F_88 ( V_2 -> V_83 ) ;
if ( ( V_94 = F_75 ( V_2 ) ) < 0 ) {
F_68 ( V_2 ) ;
return V_94 ;
}
if ( ( V_94 = F_89 ( V_44 , V_157 , V_2 , & V_132 ) ) < 0 ) {
F_68 ( V_2 ) ;
return V_94 ;
}
* V_146 = V_2 ;
return 0 ;
V_152:
F_73 ( V_2 ) ;
F_72 ( V_106 ) ;
return V_94 ;
}
static int
F_90 ( struct V_145 * V_106 ,
const struct V_158 * V_159 )
{
int V_94 ;
static int V_160 ;
struct V_144 * V_44 ;
struct V_1 * V_2 ;
if ( V_160 >= V_161 )
return - V_162 ;
if ( ! V_163 [ V_160 ] ) {
V_160 ++ ;
return - V_164 ;
}
V_94 = F_91 ( & V_106 -> V_45 , V_165 [ V_160 ] , V_166 [ V_160 ] , V_167 ,
0 , & V_44 ) ;
if ( V_94 < 0 )
return V_94 ;
strcpy ( V_44 -> V_97 , L_32 ) ;
strcpy ( V_44 -> V_104 , L_33 ) ;
V_94 = F_76 ( V_44 , V_106 , & V_2 ) ;
if ( V_94 < 0 )
goto V_152;
sprintf ( V_44 -> V_168 , L_34 ,
V_44 -> V_104 , V_2 -> V_153 , V_2 -> V_83 ) ;
V_94 = F_65 ( V_2 , V_169 [ V_160 ] ) ;
if ( V_94 < 0 )
goto V_152;
V_94 = F_51 ( V_2 , 0 ) ;
if ( V_94 < 0 )
goto V_152;
F_58 ( V_2 ) ;
V_94 = F_92 ( V_44 ) ;
if ( V_94 < 0 )
goto V_152;
F_93 ( V_106 , V_44 ) ;
V_160 ++ ;
return 0 ;
V_152:
F_94 ( V_44 ) ;
return V_94 ;
}
static void
F_95 ( struct V_145 * V_106 )
{
F_94 ( F_96 ( V_106 ) ) ;
}
