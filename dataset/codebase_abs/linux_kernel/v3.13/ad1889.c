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
F_22 (KERN_ERR PFX L_1 ,
__func__) ;
return - V_44 ;
}
F_23 ( L_2 , V_45 , 400 - V_41 ) ;
return 0 ;
}
static int
F_24 ( struct V_46 * V_47 ,
struct V_48 * V_49 )
{
return F_25 ( V_47 ,
F_26 ( V_49 ) ) ;
}
static int
F_27 ( struct V_46 * V_47 )
{
return F_28 ( V_47 ) ;
}
static int
F_29 ( struct V_46 * V_50 )
{
struct V_1 * V_2 = F_30 ( V_50 ) ;
struct V_51 * V_52 = V_50 -> V_53 ;
V_2 -> V_54 = V_50 ;
V_52 -> V_55 = V_56 ;
return 0 ;
}
static int
F_31 ( struct V_46 * V_50 )
{
struct V_1 * V_2 = F_30 ( V_50 ) ;
struct V_51 * V_52 = V_50 -> V_53 ;
V_2 -> V_57 = V_50 ;
V_52 -> V_55 = V_58 ;
return 0 ;
}
static int
F_32 ( struct V_46 * V_50 )
{
struct V_1 * V_2 = F_30 ( V_50 ) ;
V_2 -> V_54 = NULL ;
return 0 ;
}
static int
F_33 ( struct V_46 * V_50 )
{
struct V_1 * V_2 = F_30 ( V_50 ) ;
V_2 -> V_57 = NULL ;
return 0 ;
}
static int
F_34 ( struct V_46 * V_50 )
{
struct V_1 * V_2 = F_30 ( V_50 ) ;
struct V_51 * V_52 = V_50 -> V_53 ;
unsigned int V_59 = F_35 ( V_50 ) ;
unsigned int V_13 = F_36 ( V_50 ) ;
T_1 V_3 ;
F_17 ( V_2 , V_25 ) ;
V_3 = F_1 ( V_2 , V_26 ) ;
V_3 &= ~ ( V_60 | V_61 ) ;
if ( F_37 ( V_52 -> V_62 ) == 16 )
V_3 |= V_60 ;
if ( V_52 -> V_63 > 1 )
V_3 |= V_61 ;
F_38 ( & V_2 -> V_64 ) ;
V_2 -> V_28 . V_59 = V_59 ;
V_2 -> V_28 . V_3 = V_3 ;
V_2 -> V_28 . V_65 = V_52 -> V_66 ;
F_3 ( V_2 , V_26 , V_2 -> V_28 . V_3 ) ;
F_3 ( V_2 , V_67 , V_52 -> V_68 ) ;
F_14 ( V_2 , V_2 -> V_28 . V_65 ) ;
F_15 ( V_2 , V_59 ) ;
F_16 ( V_2 , V_13 ) ;
F_1 ( V_2 , V_26 ) ;
F_39 ( & V_2 -> V_64 ) ;
F_23 ( L_3
L_4 , V_2 -> V_28 . V_65 ,
V_13 , V_59 , V_3 , V_52 -> V_68 ) ;
return 0 ;
}
static int
F_40 ( struct V_46 * V_50 )
{
struct V_1 * V_2 = F_30 ( V_50 ) ;
struct V_51 * V_52 = V_50 -> V_53 ;
unsigned int V_59 = F_35 ( V_50 ) ;
unsigned int V_13 = F_36 ( V_50 ) ;
T_1 V_3 ;
F_17 ( V_2 , V_32 ) ;
V_3 = F_1 ( V_2 , V_33 ) ;
V_3 &= ~ ( V_69 | V_70 ) ;
if ( F_37 ( V_52 -> V_62 ) == 16 )
V_3 |= V_69 ;
if ( V_52 -> V_63 > 1 )
V_3 |= V_70 ;
F_38 ( & V_2 -> V_64 ) ;
V_2 -> V_35 . V_59 = V_59 ;
V_2 -> V_35 . V_3 = V_3 ;
V_2 -> V_35 . V_65 = V_52 -> V_66 ;
F_3 ( V_2 , V_33 , V_2 -> V_35 . V_3 ) ;
F_11 ( V_2 , V_2 -> V_35 . V_65 ) ;
F_12 ( V_2 , V_59 ) ;
F_13 ( V_2 , V_13 ) ;
F_1 ( V_2 , V_33 ) ;
F_39 ( & V_2 -> V_64 ) ;
F_23 ( L_5
L_4 , V_2 -> V_35 . V_65 ,
V_13 , V_59 , V_3 , V_52 -> V_68 ) ;
return 0 ;
}
static int
F_41 ( struct V_46 * V_50 , int V_71 )
{
T_1 V_72 ;
struct V_1 * V_2 = F_30 ( V_50 ) ;
V_72 = F_1 ( V_2 , V_26 ) ;
switch ( V_71 ) {
case V_73 :
F_3 ( V_2 , V_29 , V_31 | V_74 ) ;
V_72 |= V_27 ;
F_7 ( V_2 , V_75 , V_76 ) ;
F_9 ( V_2 ) ;
break;
case V_77 :
F_10 ( V_2 ) ;
V_72 &= ~ V_27 ;
break;
default:
F_42 () ;
return - V_78 ;
}
V_2 -> V_28 . V_3 = V_72 ;
F_3 ( V_2 , V_26 , V_72 ) ;
F_1 ( V_2 , V_26 ) ;
if ( V_71 == V_77 )
F_17 ( V_2 , V_25 ) ;
return 0 ;
}
static int
F_43 ( struct V_46 * V_50 , int V_71 )
{
T_1 V_35 ;
struct V_1 * V_2 = F_30 ( V_50 ) ;
V_35 = F_1 ( V_2 , V_33 ) ;
switch ( V_71 ) {
case V_73 :
F_3 ( V_2 , V_36 , V_31 | V_74 ) ;
V_35 |= V_34 ;
F_7 ( V_2 , V_75 , V_79 ) ;
break;
case V_77 :
V_35 &= ~ V_34 ;
break;
default:
return - V_78 ;
}
V_2 -> V_35 . V_3 = V_35 ;
F_3 ( V_2 , V_33 , V_35 ) ;
F_1 ( V_2 , V_33 ) ;
if ( V_71 == V_77 )
F_17 ( V_2 , V_32 ) ;
return 0 ;
}
static T_3
F_44 ( struct V_46 * V_50 )
{
T_4 V_80 = 0 ;
struct V_1 * V_2 = F_30 ( V_50 ) ;
if ( F_45 ( ! ( V_2 -> V_28 . V_3 & V_27 ) ) )
return 0 ;
V_80 = F_5 ( V_2 , V_19 ) ;
V_80 -= V_2 -> V_28 . V_65 ;
if ( F_46 ( V_80 >= V_2 -> V_28 . V_59 ) )
return 0 ;
return F_47 ( V_50 -> V_53 , V_80 ) ;
}
static T_3
F_48 ( struct V_46 * V_50 )
{
T_4 V_80 = 0 ;
struct V_1 * V_2 = F_30 ( V_50 ) ;
if ( F_45 ( ! ( V_2 -> V_35 . V_3 & V_34 ) ) )
return 0 ;
V_80 = F_5 ( V_2 , V_12 ) ;
V_80 -= V_2 -> V_35 . V_65 ;
if ( F_46 ( V_80 >= V_2 -> V_35 . V_59 ) )
return 0 ;
return F_47 ( V_50 -> V_53 , V_80 ) ;
}
static T_5
F_49 ( int V_81 , void * V_82 )
{
unsigned long V_6 ;
struct V_1 * V_2 = V_82 ;
V_6 = F_5 ( V_2 , V_83 ) ;
F_7 ( V_2 , V_83 , V_6 ) ;
V_6 &= V_84 ;
if ( F_45 ( ! V_6 ) )
return V_85 ;
if ( V_6 & ( V_86 | V_87 ) )
F_23 ( L_6 ) ;
if ( ( V_6 & V_88 ) && V_2 -> V_54 )
F_50 ( V_2 -> V_54 ) ;
if ( ( V_6 & V_89 ) && V_2 -> V_57 )
F_50 ( V_2 -> V_57 ) ;
return V_90 ;
}
static int
F_51 ( struct V_1 * V_2 , int V_91 , struct V_92 * * V_93 )
{
int V_94 ;
struct V_92 * V_95 ;
if ( V_93 )
* V_93 = NULL ;
V_94 = F_52 ( V_2 -> V_96 , V_2 -> V_96 -> V_97 , V_91 , 1 , 1 , & V_95 ) ;
if ( V_94 < 0 )
return V_94 ;
F_53 ( V_95 , V_98 ,
& V_99 ) ;
F_53 ( V_95 , V_100 ,
& V_101 ) ;
V_95 -> V_39 = V_2 ;
V_95 -> V_102 = 0 ;
strcpy ( V_95 -> V_103 , V_2 -> V_96 -> V_104 ) ;
V_2 -> V_95 = V_95 ;
V_2 -> V_54 = NULL ;
V_2 -> V_57 = NULL ;
V_94 = F_54 ( V_95 , V_105 ,
F_55 ( V_2 -> V_106 ) ,
V_107 / 2 ,
V_107 ) ;
if ( V_94 < 0 ) {
F_22 (KERN_ERR PFX L_7 , err) ;
return V_94 ;
}
if ( V_93 )
* V_93 = V_95 ;
return 0 ;
}
static void
F_56 ( struct V_108 * V_109 , struct V_110 * V_111 )
{
struct V_1 * V_2 = V_109 -> V_39 ;
T_1 V_3 ;
int V_112 ;
V_3 = F_1 ( V_2 , V_26 ) ;
F_57 ( V_111 , L_8 ,
( V_3 & V_27 ) ? L_9 : L_10 ) ;
F_57 ( V_111 , L_11 ,
( V_3 & V_61 ) ? L_12 : L_13 ) ;
F_57 ( V_111 , L_14 ,
( V_3 & V_60 ) ? 16 : 8 ) ;
V_112 = ( V_3 & V_113 ) ?
( ( ( V_3 & V_113 >> 12 ) & 0x01 ) ? 12 : 18 ) : 4 ;
V_112 /= ( V_3 & V_61 ) ? 2 : 1 ;
F_57 ( V_111 , L_15 , V_112 ,
( V_3 & V_61 ) ? L_12 : L_13 ) ;
F_57 ( V_111 , L_16 ,
V_3 & V_114 ? L_9 : L_10 ) ;
V_112 = ( V_3 & V_115 ) ?
( ( ( V_3 & V_115 >> 4 ) & 0x01 ) ? 12 : 18 ) : 4 ;
V_112 /= ( V_3 & V_61 ) ? 2 : 1 ;
F_57 ( V_111 , L_17 , V_112 ,
( V_3 & V_61 ) ? L_12 : L_13 ) ;
V_3 = F_1 ( V_2 , V_33 ) ;
F_57 ( V_111 , L_18 ,
( V_3 & V_34 ) ? L_9 : L_10 ) ;
F_57 ( V_111 , L_19 ,
( V_3 & V_70 ) ? L_12 : L_13 ) ;
F_57 ( V_111 , L_20 ,
( V_3 & V_69 ) ? 16 : 8 ) ;
V_112 = ( V_3 & V_116 ) ?
( ( ( V_3 & V_116 >> 4 ) & 0x01 ) ? 12 : 18 ) : 4 ;
V_112 /= ( V_3 & V_70 ) ? 2 : 1 ;
F_57 ( V_111 , L_21 , V_112 ,
( V_3 & V_70 ) ? L_12 : L_13 ) ;
F_57 ( V_111 , L_22 ,
V_3 & V_117 ? L_9 : L_10 ) ;
V_112 = ( V_3 & V_118 ) ?
( ( ( V_3 & V_118 >> 12 ) & 0x01 ) ? 12 : 18 ) : 4 ;
V_112 /= ( V_3 & V_70 ) ? 2 : 1 ;
F_57 ( V_111 , L_23 , V_112 ,
( V_3 & V_61 ) ? L_12 : L_13 ) ;
V_3 = F_1 ( V_2 , V_7 ) ;
F_57 ( V_111 , L_24 ,
( V_3 & V_9 ) ? L_25 : L_26 ,
( ( V_3 & V_119 ) >> 8 ) * 3 ) ;
V_3 = F_1 ( V_2 , V_7 ) ;
F_57 ( V_111 , L_27 ,
( V_3 & V_8 ) ? L_25 : L_26 ,
( V_3 & V_120 ) * 3 ) ;
V_3 = F_1 ( V_2 , V_67 ) ;
F_57 ( V_111 , L_28 , V_3 ) ;
V_3 = F_1 ( V_2 , V_121 ) ;
F_57 ( V_111 , L_29 , V_3 ) ;
}
static void
F_58 ( struct V_1 * V_2 )
{
struct V_108 * V_109 ;
if ( ! F_59 ( V_2 -> V_96 , V_2 -> V_96 -> V_97 , & V_109 ) )
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
V_94 = V_126 ( V_2 -> V_96 , 0 , & V_132 , V_2 , & V_2 -> V_128 ) ;
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
if ( V_2 -> V_81 < 0 )
goto V_137;
F_38 ( & V_2 -> V_64 ) ;
F_10 ( V_2 ) ;
F_17 ( V_2 , V_25 | V_32 ) ;
F_7 ( V_2 , V_83 , V_87 | V_86 ) ;
F_5 ( V_2 , V_83 ) ;
F_39 ( & V_2 -> V_64 ) ;
if ( V_2 -> V_81 >= 0 )
F_69 ( V_2 -> V_81 , V_2 ) ;
V_137:
if ( V_2 -> V_4 )
F_70 ( V_2 -> V_4 ) ;
F_71 ( V_2 -> V_106 ) ;
F_72 ( V_2 -> V_106 ) ;
F_73 ( V_2 ) ;
return 0 ;
}
static int
F_74 ( struct V_138 * V_91 )
{
struct V_1 * V_2 = V_91 -> V_139 ;
return F_68 ( V_2 ) ;
}
static int
F_75 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_140 , V_141 ) ;
F_1 ( V_2 , V_140 ) ;
F_21 ( 10 ) ;
F_7 ( V_2 , V_83 , V_142 | V_143 ) ;
return 0 ;
}
static int
F_76 ( struct V_144 * V_96 ,
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
if ( F_78 ( V_106 , F_79 ( 32 ) ) < 0 ||
F_80 ( V_106 , F_79 ( 32 ) ) < 0 ) {
F_81 (KERN_ERR PFX L_30 ) ;
F_72 ( V_106 ) ;
return - V_149 ;
}
if ( ( V_2 = F_82 ( sizeof( * V_2 ) , V_150 ) ) == NULL ) {
F_72 ( V_106 ) ;
return - V_151 ;
}
V_2 -> V_96 = V_96 ;
V_96 -> V_39 = V_2 ;
V_2 -> V_106 = V_106 ;
V_2 -> V_81 = - 1 ;
if ( ( V_94 = F_83 ( V_106 , V_96 -> V_97 ) ) < 0 )
goto V_152;
V_2 -> V_153 = F_84 ( V_106 , 0 ) ;
V_2 -> V_4 = F_85 ( V_106 , 0 ) ;
if ( V_2 -> V_4 == NULL ) {
F_81 (KERN_ERR PFX L_31 ) ;
V_94 = - V_154 ;
goto V_152;
}
F_86 ( V_106 ) ;
F_87 ( & V_2 -> V_64 ) ;
if ( F_88 ( V_106 -> V_81 , F_49 ,
V_155 , V_156 , V_2 ) ) {
F_81 (KERN_ERR PFX L_32 , pci->irq) ;
F_68 ( V_2 ) ;
return - V_154 ;
}
V_2 -> V_81 = V_106 -> V_81 ;
F_89 ( V_2 -> V_81 ) ;
if ( ( V_94 = F_75 ( V_2 ) ) < 0 ) {
F_68 ( V_2 ) ;
return V_94 ;
}
if ( ( V_94 = F_90 ( V_96 , V_157 , V_2 , & V_132 ) ) < 0 ) {
F_68 ( V_2 ) ;
return V_94 ;
}
F_91 ( V_96 , & V_106 -> V_158 ) ;
* V_146 = V_2 ;
return 0 ;
V_152:
F_73 ( V_2 ) ;
F_72 ( V_106 ) ;
return V_94 ;
}
static int
F_92 ( struct V_145 * V_106 ,
const struct V_159 * V_160 )
{
int V_94 ;
static int V_161 ;
struct V_144 * V_96 ;
struct V_1 * V_2 ;
if ( V_161 >= V_162 )
return - V_163 ;
if ( ! V_164 [ V_161 ] ) {
V_161 ++ ;
return - V_165 ;
}
V_94 = F_93 ( V_166 [ V_161 ] , V_167 [ V_161 ] , V_168 , 0 , & V_96 ) ;
if ( V_94 < 0 )
return V_94 ;
strcpy ( V_96 -> V_97 , L_33 ) ;
strcpy ( V_96 -> V_104 , L_34 ) ;
V_94 = F_76 ( V_96 , V_106 , & V_2 ) ;
if ( V_94 < 0 )
goto V_152;
sprintf ( V_96 -> V_169 , L_35 ,
V_96 -> V_104 , V_2 -> V_153 , V_2 -> V_81 ) ;
V_94 = F_65 ( V_2 , V_170 [ V_161 ] ) ;
if ( V_94 < 0 )
goto V_152;
V_94 = F_51 ( V_2 , 0 , NULL ) ;
if ( V_94 < 0 )
goto V_152;
F_58 ( V_2 ) ;
V_94 = F_94 ( V_96 ) ;
if ( V_94 < 0 )
goto V_152;
F_95 ( V_106 , V_96 ) ;
V_161 ++ ;
return 0 ;
V_152:
F_96 ( V_96 ) ;
return V_94 ;
}
static void
F_97 ( struct V_145 * V_106 )
{
F_96 ( F_98 ( V_106 ) ) ;
}
