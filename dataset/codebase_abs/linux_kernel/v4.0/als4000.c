static inline void F_1 ( unsigned long V_1 ,
enum V_2 V_3 ,
T_1 V_4 )
{
F_2 ( V_4 , V_1 + V_3 ) ;
}
static inline void F_3 ( unsigned long V_1 ,
enum V_2 V_3 ,
T_2 V_4 )
{
F_4 ( V_4 , V_1 + V_3 ) ;
}
static inline T_1 F_5 ( unsigned long V_1 ,
enum V_2 V_3 )
{
return F_6 ( V_1 + V_3 ) ;
}
static inline T_2 F_7 ( unsigned long V_1 ,
enum V_2 V_3 )
{
return F_8 ( V_1 + V_3 ) ;
}
static inline void F_9 ( unsigned long V_1 ,
enum V_5 V_3 ,
T_2 V_4 )
{
F_1 ( V_1 , V_6 , V_3 ) ;
F_3 ( V_1 , V_7 , V_4 ) ;
}
static inline void F_10 ( struct V_8 * V_9 ,
enum V_5 V_3 ,
T_2 V_4 )
{
F_9 ( V_9 -> V_10 , V_3 , V_4 ) ;
}
static inline T_2 F_11 ( unsigned long V_1 ,
enum V_5 V_3 )
{
F_1 ( V_1 , V_6 , V_3 ) ;
return F_7 ( V_1 , V_7 ) ;
}
static inline T_2 F_12 ( struct V_8 * V_9 , enum V_5 V_3 )
{
return F_11 ( V_9 -> V_10 , V_3 ) ;
}
static inline void F_13 ( struct V_8 * V_11 ,
enum V_12 V_3 ,
T_1 V_13 )
{
F_14 ( V_11 , V_3 | 0xc0 , V_13 ) ;
}
static inline T_1 F_15 ( struct V_8 * V_11 ,
enum V_12 V_3 )
{
return F_16 ( V_11 , V_3 | 0xc0 ) ;
}
static void F_17 ( struct V_8 * V_11 , unsigned int V_14 )
{
if ( ! ( V_11 -> V_15 & V_16 ) ) {
F_18 ( V_11 , V_17 ) ;
F_18 ( V_11 , V_14 >> 8 ) ;
F_18 ( V_11 , V_14 ) ;
}
}
static inline void F_19 ( struct V_8 * V_11 ,
T_3 V_18 , unsigned V_19 )
{
F_10 ( V_11 , V_20 , V_18 ) ;
F_10 ( V_11 , V_21 , ( V_19 - 1 ) ) ;
}
static inline void F_20 ( struct V_8 * V_11 ,
T_3 V_18 ,
unsigned V_19 )
{
F_10 ( V_11 , V_22 , V_18 ) ;
F_10 ( V_11 , V_23 ,
( V_19 - 1 ) | 0x180000 ) ;
}
static int F_21 ( struct V_24 * V_25 )
{
int V_26 ;
V_26 = 0 ;
if ( F_22 ( V_25 -> V_27 ) )
V_26 |= V_28 ;
if ( F_23 ( V_25 -> V_27 ) == 16 )
V_26 |= V_29 ;
if ( V_25 -> V_30 > 1 )
V_26 |= V_31 ;
return V_26 ;
}
static int F_24 ( struct V_32 * V_33 ,
struct V_34 * V_35 )
{
return F_25 ( V_33 , F_26 ( V_35 ) ) ;
}
static int F_27 ( struct V_32 * V_33 )
{
F_28 ( V_33 ) ;
return 0 ;
}
static int F_29 ( struct V_32 * V_33 )
{
struct V_8 * V_11 = F_30 ( V_33 ) ;
struct V_24 * V_25 = V_33 -> V_25 ;
unsigned long V_19 ;
unsigned V_36 ;
V_11 -> V_37 = F_21 ( V_25 ) ;
V_19 = F_31 ( V_33 ) ;
V_36 = F_32 ( V_33 ) ;
if ( V_11 -> V_37 & V_29 )
V_36 >>= 1 ;
V_36 -- ;
F_33 ( & V_11 -> V_38 ) ;
F_17 ( V_11 , V_25 -> V_14 ) ;
F_19 ( V_11 , V_25 -> V_39 , V_19 ) ;
F_34 ( & V_11 -> V_38 ) ;
F_33 ( & V_11 -> V_40 ) ;
F_13 ( V_11 , V_41 , V_36 & 0xff ) ;
F_13 ( V_11 , V_42 , V_36 >> 8 ) ;
F_34 ( & V_11 -> V_40 ) ;
return 0 ;
}
static int F_35 ( struct V_32 * V_33 )
{
struct V_8 * V_11 = F_30 ( V_33 ) ;
struct V_24 * V_25 = V_33 -> V_25 ;
unsigned long V_19 ;
unsigned V_36 ;
V_11 -> V_43 = F_21 ( V_25 ) ;
V_19 = F_31 ( V_33 ) ;
V_36 = F_32 ( V_33 ) ;
if ( V_11 -> V_43 & V_29 )
V_36 >>= 1 ;
V_36 -- ;
F_33 ( & V_11 -> V_38 ) ;
F_17 ( V_11 , V_25 -> V_14 ) ;
F_20 ( V_11 , V_25 -> V_39 , V_19 ) ;
F_18 ( V_11 , F_36 ( V_11 ) . V_44 ) ;
F_18 ( V_11 , F_36 ( V_11 ) . V_27 ) ;
F_18 ( V_11 , V_36 & 0xff ) ;
F_18 ( V_11 , V_36 >> 8 ) ;
F_18 ( V_11 , F_36 ( V_11 ) . V_45 ) ;
F_34 ( & V_11 -> V_38 ) ;
return 0 ;
}
static int F_37 ( struct V_32 * V_33 , int V_46 )
{
struct V_8 * V_11 = F_30 ( V_33 ) ;
int V_26 = 0 ;
F_38 ( & V_11 -> V_40 ) ;
switch ( V_46 ) {
case V_47 :
case V_48 :
V_11 -> V_15 |= V_49 ;
F_13 ( V_11 , V_50 ,
F_39 ( V_11 ) ) ;
break;
case V_51 :
case V_52 :
V_11 -> V_15 &= ~ V_49 ;
F_13 ( V_11 , V_50 ,
F_39 ( V_11 ) ) ;
break;
default:
V_26 = - V_53 ;
break;
}
F_40 ( & V_11 -> V_40 ) ;
return V_26 ;
}
static int F_41 ( struct V_32 * V_33 , int V_46 )
{
struct V_8 * V_11 = F_30 ( V_33 ) ;
int V_26 = 0 ;
F_38 ( & V_11 -> V_38 ) ;
switch ( V_46 ) {
case V_47 :
case V_48 :
V_11 -> V_15 |= V_54 ;
F_18 ( V_11 , F_36 ( V_11 ) . V_55 ) ;
break;
case V_51 :
case V_52 :
F_18 ( V_11 , F_36 ( V_11 ) . V_45 ) ;
V_11 -> V_15 &= ~ V_54 ;
break;
default:
V_26 = - V_53 ;
break;
}
F_40 ( & V_11 -> V_38 ) ;
return V_26 ;
}
static T_4 F_42 ( struct V_32 * V_33 )
{
struct V_8 * V_11 = F_30 ( V_33 ) ;
unsigned int V_26 ;
F_38 ( & V_11 -> V_38 ) ;
V_26 = F_12 ( V_11 , V_56 ) ;
F_40 ( & V_11 -> V_38 ) ;
V_26 &= 0xffff ;
return F_43 ( V_33 -> V_25 , V_26 ) ;
}
static T_4 F_44 ( struct V_32 * V_33 )
{
struct V_8 * V_11 = F_30 ( V_33 ) ;
unsigned V_26 ;
F_38 ( & V_11 -> V_38 ) ;
V_26 = F_12 ( V_11 , V_57 ) ;
F_40 ( & V_11 -> V_38 ) ;
V_26 &= 0xffff ;
return F_43 ( V_33 -> V_25 , V_26 ) ;
}
static T_5 F_45 ( int V_58 , void * V_59 )
{
struct V_8 * V_11 = V_59 ;
unsigned V_60 ;
unsigned V_61 ;
V_60 = F_5 ( V_11 -> V_10 ,
V_62 ) ;
if ( ( V_60 & V_63 )
&& ( V_11 -> V_64 ) )
F_46 ( V_11 -> V_64 ) ;
if ( ( V_60 & V_65 )
&& ( V_11 -> V_66 ) )
F_46 ( V_11 -> V_66 ) ;
if ( ( V_60 & V_67 )
&& ( V_11 -> V_68 ) )
F_47 ( V_58 , V_11 -> V_68 -> V_69 ) ;
F_1 ( V_11 -> V_10 ,
V_62 , V_60 ) ;
F_38 ( & V_11 -> V_40 ) ;
V_61 = F_16 ( V_11 , V_70 ) ;
F_40 ( & V_11 -> V_40 ) ;
if ( V_61 & V_71 )
F_48 ( V_11 ) ;
if ( V_61 & V_72 )
F_49 ( V_11 ) ;
if ( V_61 & V_73 )
F_6 ( V_11 -> V_74 ) ;
if ( V_61 & V_75 )
F_5 ( V_11 -> V_10 ,
V_76 ) ;
return F_50 (
( V_60 & ( V_63 | V_65 |
V_67 ) )
|| ( V_61 & ( V_71 | V_72 |
V_73 | V_75 ) )
) ;
}
static int F_51 ( struct V_32 * V_33 )
{
struct V_8 * V_11 = F_30 ( V_33 ) ;
struct V_24 * V_25 = V_33 -> V_25 ;
V_11 -> V_64 = V_33 ;
V_25 -> V_77 = V_78 ;
return 0 ;
}
static int F_52 ( struct V_32 * V_33 )
{
struct V_8 * V_11 = F_30 ( V_33 ) ;
V_11 -> V_64 = NULL ;
F_28 ( V_33 ) ;
return 0 ;
}
static int F_53 ( struct V_32 * V_33 )
{
struct V_8 * V_11 = F_30 ( V_33 ) ;
struct V_24 * V_25 = V_33 -> V_25 ;
V_11 -> V_66 = V_33 ;
V_25 -> V_77 = V_79 ;
return 0 ;
}
static int F_54 ( struct V_32 * V_33 )
{
struct V_8 * V_11 = F_30 ( V_33 ) ;
V_11 -> V_66 = NULL ;
F_28 ( V_33 ) ;
return 0 ;
}
static int F_55 ( struct V_8 * V_11 , int V_80 )
{
struct V_81 * V_82 ;
int V_83 ;
V_83 = F_56 ( V_11 -> V_84 , L_1 , V_80 , 1 , 1 , & V_82 ) ;
if ( V_83 < 0 )
return V_83 ;
V_82 -> V_69 = V_11 ;
V_82 -> V_85 = V_86 ;
F_57 ( V_82 , V_87 , & V_88 ) ;
F_57 ( V_82 , V_89 , & V_90 ) ;
F_58 ( V_82 , V_91 , F_59 ( V_11 -> V_92 ) ,
64 * 1024 , 64 * 1024 ) ;
V_11 -> V_82 = V_82 ;
return 0 ;
}
static void F_60 ( unsigned long V_1 ,
unsigned int V_93 ,
unsigned int V_94 ,
unsigned int V_95 ,
unsigned int V_96 )
{
T_2 V_97 = 0 ;
T_2 V_98 = 0 ;
if ( V_94 > 0 )
V_98 |= ( V_94 | 1 ) << 16 ;
if ( V_93 > 0 )
V_98 |= ( V_93 | 1 ) ;
if ( V_96 > 0 )
V_97 |= ( V_96 | 1 ) << 16 ;
if ( V_95 > 0 )
V_97 |= ( V_95 | 1 ) ;
F_9 ( V_1 , V_99 , V_97 ) ;
F_9 ( V_1 , V_100 , V_98 ) ;
}
static void F_61 ( struct V_8 * V_11 )
{
T_1 V_101 ;
int V_102 ;
F_33 ( & V_11 -> V_40 ) ;
V_101 = F_15 ( V_11 , V_103 ) ;
F_13 ( V_11 , V_103 ,
V_101 | V_104 ) ;
F_14 ( V_11 , V_105 , V_106 ) ;
F_13 ( V_11 , V_103 ,
V_101 & ~ V_104 ) ;
F_34 ( & V_11 -> V_40 ) ;
F_33 ( & V_11 -> V_38 ) ;
F_10 ( V_11 , V_107 ,
V_108 ) ;
for ( V_102 = V_22 ; V_102 <= V_109 ; ++ V_102 )
F_10 ( V_11 , V_102 , 0 ) ;
F_10 ( V_11 , V_110 ,
( F_12 ( V_11 , V_110 ) & ~ 0x07 ) | 0x04 ) ;
F_34 ( & V_11 -> V_38 ) ;
}
static int F_62 ( struct V_111 * V_112 , int V_113 )
{
struct V_114 * V_115 ;
struct V_116 * V_117 ;
int V_118 ;
if ( V_119 [ V_113 ] == 0 )
return - V_120 ;
if ( V_119 [ V_113 ] == 1 ) {
for ( V_118 = 0x200 ; V_118 <= 0x218 ; V_118 += 8 ) {
V_117 = F_63 ( V_118 , 8 , L_2 ) ;
if ( V_117 )
break;
}
} else {
V_118 = V_119 [ V_113 ] ;
V_117 = F_63 ( V_118 , 8 , L_2 ) ;
}
if ( ! V_117 ) {
F_64 ( & V_112 -> V_92 -> V_113 , L_3 ) ;
return - V_121 ;
}
V_112 -> V_114 = V_115 = F_65 () ;
if ( ! V_115 ) {
F_66 ( & V_112 -> V_92 -> V_113 , L_4 ) ;
F_67 ( V_117 ) ;
return - V_122 ;
}
F_68 ( V_115 , L_5 ) ;
F_69 ( V_115 , L_6 , F_70 ( V_112 -> V_92 ) ) ;
F_71 ( V_115 , & V_112 -> V_92 -> V_113 ) ;
V_115 -> V_123 = V_118 ;
F_72 ( V_115 , V_117 ) ;
F_60 ( V_112 -> V_1 , 0 , 0 , 0 , 1 ) ;
F_73 ( V_112 -> V_114 ) ;
return 0 ;
}
static void F_74 ( struct V_111 * V_112 )
{
if ( V_112 -> V_114 ) {
struct V_116 * V_117 = F_75 ( V_112 -> V_114 ) ;
F_76 ( V_112 -> V_114 ) ;
V_112 -> V_114 = NULL ;
F_60 ( V_112 -> V_1 , 0 , 0 , 0 , 0 ) ;
F_67 ( V_117 ) ;
}
}
static inline int F_62 ( struct V_111 * V_112 , int V_113 ) { return - V_124 ; }
static inline void F_74 ( struct V_111 * V_112 ) { }
static void F_77 ( struct V_125 * V_84 )
{
struct V_111 * V_112 = V_84 -> V_69 ;
F_9 ( V_112 -> V_1 , V_107 , 0 ) ;
F_74 ( V_112 ) ;
F_78 ( V_112 -> V_92 ) ;
F_79 ( V_112 -> V_92 ) ;
}
static int F_80 ( struct V_126 * V_92 ,
const struct V_127 * V_128 )
{
static int V_113 ;
struct V_125 * V_84 ;
struct V_111 * V_112 ;
unsigned long V_1 ;
struct V_8 * V_11 ;
struct V_129 * V_130 ;
unsigned short V_131 ;
int V_83 ;
if ( V_113 >= V_132 )
return - V_120 ;
if ( ! V_133 [ V_113 ] ) {
V_113 ++ ;
return - V_134 ;
}
if ( ( V_83 = F_81 ( V_92 ) ) < 0 ) {
return V_83 ;
}
if ( F_82 ( V_92 , F_83 ( 24 ) ) < 0 ||
F_84 ( V_92 , F_83 ( 24 ) ) < 0 ) {
F_66 ( & V_92 -> V_113 , L_7 ) ;
F_79 ( V_92 ) ;
return - V_135 ;
}
if ( ( V_83 = F_85 ( V_92 , L_8 ) ) < 0 ) {
F_79 ( V_92 ) ;
return V_83 ;
}
V_1 = F_86 ( V_92 , 0 ) ;
F_87 ( V_92 , V_136 , & V_131 ) ;
F_88 ( V_92 , V_136 , V_131 | V_137 ) ;
F_89 ( V_92 ) ;
V_83 = F_90 ( & V_92 -> V_113 , V_138 [ V_113 ] , V_139 [ V_113 ] , V_140 ,
sizeof( * V_112 ) ,
& V_84 ) ;
if ( V_83 < 0 ) {
F_78 ( V_92 ) ;
F_79 ( V_92 ) ;
return V_83 ;
}
V_112 = V_84 -> V_69 ;
V_112 -> V_92 = V_92 ;
V_112 -> V_1 = V_1 ;
V_84 -> V_141 = F_77 ;
F_60 ( V_112 -> V_1 , 0 , 0 , 0 , 0 ) ;
if ( ( V_83 = F_91 ( V_84 ,
V_1 + V_142 ,
V_92 -> V_58 ,
F_45 ,
- 1 ,
- 1 ,
V_143 ,
& V_11 ) ) < 0 ) {
goto V_144;
}
V_112 -> V_11 = V_11 ;
V_11 -> V_92 = V_92 ;
V_11 -> V_10 = V_1 ;
F_61 ( V_11 ) ;
strcpy ( V_84 -> V_145 , L_8 ) ;
strcpy ( V_84 -> V_146 , L_9 ) ;
sprintf ( V_84 -> V_147 , L_10 ,
V_84 -> V_146 , V_11 -> V_10 , V_11 -> V_58 ) ;
if ( ( V_83 = F_92 ( V_84 , 0 , V_148 ,
V_1 + V_149 ,
V_150 |
V_151 ,
- 1 , & V_11 -> V_68 ) ) < 0 ) {
F_66 ( & V_92 -> V_113 , L_11 ,
V_1 + V_149 ) ;
goto V_144;
}
if ( ( V_83 = F_55 ( V_11 , 0 ) ) < 0 ) {
goto V_144;
}
if ( ( V_83 = F_93 ( V_11 ) ) < 0 ) {
goto V_144;
}
if ( F_94 ( V_84 ,
V_1 + V_142 ,
V_1 + V_152 ,
V_153 , 1 , & V_130 ) < 0 ) {
F_66 ( & V_92 -> V_113 , L_12 ,
V_1 + V_142 ,
V_1 + V_152 ) ;
} else {
if ( ( V_83 = F_95 ( V_130 , 0 , 1 , NULL ) ) < 0 ) {
goto V_144;
}
}
F_62 ( V_112 , V_113 ) ;
if ( ( V_83 = F_96 ( V_84 ) ) < 0 ) {
goto V_144;
}
F_97 ( V_92 , V_84 ) ;
V_113 ++ ;
V_83 = 0 ;
goto V_154;
V_144:
F_98 ( V_84 ) ;
V_154:
return V_83 ;
}
static void F_99 ( struct V_126 * V_92 )
{
F_98 ( F_100 ( V_92 ) ) ;
}
static int F_101 ( struct V_80 * V_113 )
{
struct V_125 * V_84 = F_102 ( V_113 ) ;
struct V_111 * V_112 = V_84 -> V_69 ;
struct V_8 * V_11 = V_112 -> V_11 ;
F_103 ( V_84 , V_155 ) ;
F_104 ( V_11 -> V_82 ) ;
F_105 ( V_11 ) ;
return 0 ;
}
static int F_106 ( struct V_80 * V_113 )
{
struct V_125 * V_84 = F_102 ( V_113 ) ;
struct V_111 * V_112 = V_84 -> V_69 ;
struct V_8 * V_11 = V_112 -> V_11 ;
F_61 ( V_11 ) ;
F_107 ( V_11 ) ;
F_108 ( V_11 ) ;
#ifdef F_109
if ( V_112 -> V_114 )
F_60 ( V_112 -> V_1 , 0 , 0 , 0 , 1 ) ;
#endif
F_103 ( V_84 , V_156 ) ;
return 0 ;
}
