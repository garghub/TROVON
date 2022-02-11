static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 , struct V_1 , V_4 ) ;
}
static inline struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( V_6 -> V_7 , struct V_1 , V_8 ) ;
}
static inline T_1 F_4 ( struct V_1 * V_1 , T_1 V_9 )
{
return F_5 ( & V_1 -> V_10 [ V_9 ] ) ;
}
static inline void F_6 ( struct V_1 * V_1 , T_1 V_9 , T_1 V_11 )
{
F_7 ( V_11 , & V_1 -> V_10 [ V_9 ] ) ;
}
static inline void F_8 ( struct V_1 * V_1 , T_1 V_9 , T_1 V_12 , T_1 V_13 )
{
T_1 V_11 = F_5 ( & V_1 -> V_10 [ V_9 ] ) ;
V_11 &= ~ V_12 ;
V_11 |= V_13 ;
F_7 ( V_11 , & V_1 -> V_10 [ V_9 ] ) ;
}
static void F_9 ( struct V_1 * V_1 , T_1 V_11 )
{
V_11 &= ~ V_14 ;
V_11 |= V_15 / 2 ;
F_6 ( V_1 , V_16 , V_11 ) ;
}
static void F_10 ( void * V_17 , int V_18 )
{
struct V_1 * V_1 = V_17 ;
if ( V_18 )
F_8 ( V_1 , V_19 , V_20 , V_20 ) ;
else
F_8 ( V_1 , V_19 , V_20 , 0 ) ;
}
static void F_11 ( void * V_17 , int V_18 )
{
struct V_1 * V_1 = V_17 ;
if ( V_18 )
F_8 ( V_1 , V_19 , V_21 , V_21 ) ;
else
F_8 ( V_1 , V_19 , V_21 , 0 ) ;
if ( ( V_18 ) && ( V_1 -> V_22 == 0 ) ) {
V_1 -> V_22 = 1 ;
} else {
if ( ( ! V_18 ) && ( V_1 -> V_22 == 1 ) )
F_10 ( V_1 , 1 ) ;
V_1 -> V_22 = 0 ;
}
}
static int F_12 ( void * V_17 )
{
struct V_1 * V_1 = V_17 ;
return F_4 ( V_1 , V_19 ) & V_20 ;
}
static int F_13 ( void * V_17 )
{
struct V_1 * V_1 = V_17 ;
return F_4 ( V_1 , V_19 ) & V_21 ;
}
static void F_14 ( struct V_1 * V_1 , int V_23 )
{
T_1 V_11 = F_4 ( V_1 , V_24 ) ;
if ( V_11 & V_25 ) {
V_11 &= ~ V_25 ;
F_6 ( V_1 , V_24 , V_11 ) ;
}
if ( V_23 ) {
V_11 |= V_25 ;
F_6 ( V_1 , V_24 , V_11 ) ;
}
}
static void F_15 ( struct V_1 * V_1 , int V_23 )
{
T_1 V_11 = F_4 ( V_1 , V_16 ) ;
if ( V_11 & V_26 ) {
V_11 &= ~ V_26 ;
F_9 ( V_1 , V_11 ) ;
}
if ( V_23 ) {
V_11 |= V_26 ;
F_9 ( V_1 , V_11 ) ;
}
}
static void F_16 ( struct V_1 * V_1 )
{
F_6 ( V_1 , V_27 , V_1 -> V_28 ) ;
}
static int F_17 ( struct V_1 * V_1 )
{
V_1 -> V_28 = F_18 ( V_1 -> V_29 , V_1 -> V_30 ,
V_31 , V_32 ) ;
return F_19 ( V_1 -> V_29 , V_1 -> V_28 ) ;
}
static void F_20 ( struct V_1 * V_1 )
{
F_21 ( V_1 -> V_29 , V_1 -> V_28 ,
V_31 , V_32 ) ;
}
static int F_22 ( struct V_2 * V_33 )
{
struct V_1 * V_1 = F_1 ( V_33 ) ;
if ( V_1 -> V_34 ++ == 0 )
F_8 ( V_1 , F_23 ( 0 ) , V_35 | V_36 , 0 ) ;
if ( ( V_33 -> V_37 < 0x2000 ) && ( V_33 -> V_38 < V_39 ) )
F_8 ( V_1 , F_23 ( V_33 -> V_38 ) , V_40 | V_41 , V_40 | V_33 -> V_37 ) ;
else if ( V_1 -> V_42 ++ == 0 )
F_8 ( V_1 , F_23 ( 0 ) , V_36 , V_36 ) ;
return 0 ;
}
static int F_24 ( struct V_2 * V_33 )
{
struct V_1 * V_1 = F_1 ( V_33 ) ;
if ( -- V_1 -> V_34 == 0 )
F_8 ( V_1 , F_23 ( 0 ) , V_35 , V_35 ) ;
if ( ( V_33 -> V_37 < 0x2000 ) && ( V_33 -> V_38 < V_39 ) )
F_8 ( V_1 , F_23 ( V_33 -> V_38 ) , V_40 | V_41 , 0x1fff ) ;
else if ( -- V_1 -> V_42 == 0 )
F_8 ( V_1 , F_23 ( 0 ) , V_36 , 0 ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_1 , unsigned int V_43 )
{
F_26 ( V_1 -> V_29 , V_1 -> V_28 ,
V_31 , V_32 ) ;
if ( ( V_43 == 0 ) || ( V_43 > V_15 ) ) {
unsigned int V_44 = 0 ;
while ( V_1 -> V_30 [ V_44 ] == 0x47 )
V_44 += 188 ;
V_43 = V_44 / 188 ;
if ( V_44 == 0 ) {
F_15 ( V_1 , 1 ) ;
F_27 ( V_45 , & V_1 -> V_29 -> V_46 , L_1 ) ;
}
}
F_28 ( & V_1 -> V_4 , V_1 -> V_30 , V_43 ) ;
memset ( V_1 -> V_30 , 0 , V_43 * 188 ) ;
F_16 ( V_1 ) ;
F_29 ( V_1 -> V_29 , V_1 -> V_28 ,
V_31 , V_32 ) ;
}
static T_2 F_30 ( int V_47 , void * V_48 )
{
struct V_1 * V_1 = V_48 ;
T_1 V_49 ;
V_49 = F_4 ( V_1 , V_16 ) ;
if ( ! ( V_49 & ( V_50 | V_51 ) ) )
return V_52 ;
if ( V_49 == 0xffffffff ) {
if ( V_1 -> V_53 == 0 )
F_31 ( & V_1 -> V_29 -> V_46 , L_2 ) ;
V_1 -> V_53 = 1 ;
return V_54 ;
}
if ( V_49 & V_50 ) {
F_25 ( V_1 , ( V_49 & V_55 ) >> 24 ) ;
if ( V_49 & V_51 )
V_1 -> V_56 ++ ;
if ( V_1 -> V_56 ) {
F_31 ( & V_1 -> V_29 -> V_46 , L_3 ,
V_1 -> V_56 ) ;
F_15 ( V_1 , 1 ) ;
V_1 -> V_56 = 0 ;
}
} else if ( V_49 & V_51 ) {
V_1 -> V_56 ++ ;
}
F_9 ( V_1 , V_49 | V_57 ) ;
return V_54 ;
}
static void F_32 ( struct V_1 * V_1 )
{
T_1 V_11 = F_4 ( V_1 , V_16 ) ;
V_11 |= ( V_58 | V_59 ) ;
V_11 &= ~ ( V_60 | V_61 ) ;
V_11 |= V_57 ;
F_9 ( V_1 , V_11 ) ;
}
static void F_33 ( struct V_1 * V_1 )
{
T_1 V_11 = F_4 ( V_1 , V_16 ) ;
V_11 |= ( V_60 | V_61 | V_58 | V_59 ) ;
V_11 |= V_57 ;
F_9 ( V_1 , V_11 ) ;
}
static int F_34 ( struct V_1 * V_1 )
{
F_14 ( V_1 , 1 ) ;
F_8 ( V_1 , V_24 , V_62 , V_62 ) ;
#ifdef F_35
F_8 ( V_1 , F_23 ( 0 ) , V_63 , V_63 ) ;
#else
F_8 ( V_1 , F_23 ( 0 ) , V_63 , 0 ) ;
#endif
F_17 ( V_1 ) ;
F_16 ( V_1 ) ;
F_32 ( V_1 ) ;
F_15 ( V_1 , 1 ) ;
return 0 ;
}
static void F_36 ( struct V_1 * V_1 )
{
F_33 ( V_1 ) ;
F_15 ( V_1 , 0 ) ;
F_8 ( V_1 , V_24 , V_62 | V_64 | V_65 , V_64 ) ;
F_20 ( V_1 ) ;
F_14 ( V_1 , 0 ) ;
}
static inline T_1 F_37 ( T_1 V_66 , T_1 V_67 )
{
if ( V_67 == 0 )
return ~ 0 ;
return F_38 ( V_66 , V_67 ) ;
}
static int F_39 ( struct V_5 * V_6 )
{
struct V_68 * V_69 = & V_6 -> V_70 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_71 V_72 ;
int V_73 ;
T_3 V_74 [ 4 ] ;
T_1 div ;
div = F_37 ( V_69 -> V_75 * 3 , 500000 ) + 217 ;
V_74 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_74 [ 1 ] = ( div >> 0 ) & 0xff ;
if ( V_69 -> V_75 < 611000000 )
V_74 [ 2 ] = 0xb4 ;
else if ( V_69 -> V_75 < 811000000 )
V_74 [ 2 ] = 0xbc ;
else
V_74 [ 2 ] = 0xf4 ;
if ( V_69 -> V_75 < 350000000 )
V_74 [ 3 ] = 0x02 ;
else
V_74 [ 3 ] = 0x04 ;
if ( V_69 -> V_76 == 8000000 )
V_74 [ 3 ] |= 0x08 ;
V_72 . V_77 = V_78 >> 1 ;
V_72 . V_79 = 0 ;
V_72 . V_74 = V_74 ;
V_72 . V_80 = sizeof( V_74 ) ;
if ( V_6 -> V_81 . V_82 )
V_6 -> V_81 . V_82 ( V_6 , 1 ) ;
V_73 = F_40 ( & V_1 -> V_83 , & V_72 , 1 ) ;
if ( V_73 < 0 )
return V_73 ;
else if ( V_73 == 0 )
return - V_84 ;
return 0 ;
}
static int F_41 ( struct V_5 * V_6 ,
const struct V_85 * * V_86 , char * V_87 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
return F_42 ( V_86 , V_87 , & V_1 -> V_29 -> V_46 ) ;
}
static int F_43 ( struct V_1 * V_1 )
{
int V_73 ;
V_1 -> V_6 = F_44 ( & V_88 , & V_1 -> V_83 ) ;
if ( ! V_1 -> V_6 ) {
F_31 ( & V_1 -> V_29 -> V_46 , L_4 ) ;
return - V_89 ;
}
V_1 -> V_6 -> V_81 . V_90 . V_91 = F_39 ;
V_73 = F_45 ( & V_1 -> V_8 , V_1 -> V_6 ) ;
if ( V_73 < 0 ) {
if ( V_1 -> V_6 -> V_81 . V_92 )
V_1 -> V_6 -> V_81 . V_92 ( V_1 -> V_6 ) ;
return V_73 ;
}
return 0 ;
}
static void F_46 ( struct V_1 * V_1 )
{
T_1 V_11 = F_4 ( V_1 , V_24 ) & V_93 ;
F_47 ( & V_1 -> V_29 -> V_46 , L_5 ,
( V_11 >> 12 ) & 0x0f , ( V_11 >> 4 ) & 0xff ) ;
}
static void F_48 ( struct V_1 * V_1 , T_3 * V_94 )
{
T_1 V_11 = F_4 ( V_1 , V_95 ) ;
V_94 [ 0 ] = ( V_11 >> 8 ) & 0xff ;
V_94 [ 1 ] = ( V_11 >> 0 ) & 0xff ;
V_11 = F_4 ( V_1 , V_96 ) ;
V_94 [ 2 ] = ( V_11 >> 8 ) & 0xff ;
V_94 [ 3 ] = ( V_11 >> 0 ) & 0xff ;
V_11 = F_4 ( V_1 , V_97 ) ;
V_94 [ 4 ] = ( V_11 >> 8 ) & 0xff ;
V_94 [ 5 ] = ( V_11 >> 0 ) & 0xff ;
F_47 ( & V_1 -> V_29 -> V_46 , L_6 , V_94 ) ;
}
static int F_49 ( struct V_1 * V_1 )
{
struct V_98 * V_29 = V_1 -> V_29 ;
unsigned int V_44 , V_99 ;
T_3 T_4 * V_100 ;
V_100 = F_50 ( V_29 , 1 , 0 ) ;
if ( ! V_100 )
return - V_101 ;
F_47 ( & V_29 -> V_46 , L_7 ) ;
for ( V_44 = 0xe0 ; V_44 < 0x100 ; V_44 += 4 ) {
T_1 V_11 = F_5 ( & V_100 [ V_44 ] ) ;
for ( V_99 = 0 ; V_99 < 32 ; V_99 += 8 ) {
if ( ( V_11 & 0xff ) == 0xff )
goto V_102;
F_51 ( L_8 , V_11 & 0xff ) ;
V_11 >>= 8 ;
}
}
V_102:
F_51 ( L_9 ) ;
F_52 ( V_29 , V_100 ) ;
return 0 ;
}
static int F_53 ( struct V_98 * V_29 , const struct V_103 * V_104 )
{
struct V_1 * V_1 ;
struct V_8 * V_8 ;
struct V_105 * V_106 ;
struct V_107 * V_108 ;
int V_73 = - V_109 ;
V_1 = F_54 ( sizeof( struct V_1 ) , V_110 ) ;
if ( ! V_1 )
goto V_102;
V_1 -> V_29 = V_29 ;
V_73 = F_55 ( V_29 ) ;
if ( V_73 < 0 )
goto V_111;
F_56 ( V_29 , 0x6c , 0x8000 ) ;
V_73 = F_57 ( V_29 , F_58 ( 32 ) ) ;
if ( V_73 < 0 )
goto V_112;
F_59 ( V_29 ) ;
V_73 = F_60 ( V_29 , V_113 ) ;
if ( V_73 < 0 )
goto V_112;
V_1 -> V_10 = F_50 ( V_29 , 0 , 0x40 ) ;
if ( ! V_1 -> V_10 ) {
V_73 = - V_101 ;
goto V_114;
}
F_61 ( V_29 , V_1 ) ;
V_73 = F_62 ( V_29 -> V_47 , F_30 , V_115 , V_113 , V_1 ) ;
if ( V_73 < 0 )
goto V_116;
V_73 = F_34 ( V_1 ) ;
if ( V_73 < 0 )
goto V_117;
F_63 ( & V_1 -> V_83 , V_1 ) ;
strcpy ( V_1 -> V_83 . V_87 , V_113 ) ;
V_1 -> V_83 . V_118 = V_119 ;
V_1 -> V_83 . V_46 . V_120 = & V_29 -> V_46 ;
V_1 -> V_83 . V_121 = & V_1 -> V_122 ;
V_1 -> V_122 . V_17 = V_1 ;
V_1 -> V_122 . V_123 = F_10 ;
V_1 -> V_122 . V_124 = F_11 ;
V_1 -> V_122 . V_125 = F_12 ;
V_1 -> V_122 . V_126 = F_13 ;
V_1 -> V_122 . V_127 = 10 ;
V_1 -> V_122 . V_128 = 10 ;
F_10 ( V_1 , 1 ) ;
F_11 ( V_1 , 1 ) ;
V_73 = F_64 ( & V_1 -> V_83 ) ;
if ( V_73 < 0 )
goto V_129;
V_73 = F_65 ( & V_1 -> V_8 , V_113 ,
V_119 , & V_29 -> V_46 , V_130 ) ;
if ( V_73 < 0 )
goto V_131;
V_8 = & V_1 -> V_8 ;
F_46 ( V_1 ) ;
F_49 ( V_1 ) ;
F_48 ( V_1 , V_8 -> V_132 ) ;
V_106 = & V_1 -> V_4 ;
V_106 -> V_133 = 256 ;
V_106 -> V_134 = 256 ;
V_106 -> V_135 = F_22 ;
V_106 -> V_136 = F_24 ;
V_106 -> V_108 . V_137 = ( V_138 |
V_139 | V_140 ) ;
V_73 = F_66 ( V_106 ) ;
if ( V_73 < 0 )
goto V_141;
V_108 = & V_106 -> V_108 ;
V_1 -> V_142 . V_143 = V_144 ;
V_1 -> V_145 . V_143 = V_146 ;
V_1 -> V_147 . V_133 = V_39 ;
V_1 -> V_147 . V_4 = V_108 ;
V_73 = F_67 ( & V_1 -> V_147 , V_8 ) ;
if ( V_73 < 0 )
goto V_148;
V_73 = V_108 -> V_149 ( V_108 , & V_1 -> V_142 ) ;
if ( V_73 < 0 )
goto V_150;
V_73 = V_108 -> V_149 ( V_108 , & V_1 -> V_145 ) ;
if ( V_73 < 0 )
goto V_151;
V_73 = V_108 -> V_152 ( V_108 , & V_1 -> V_142 ) ;
if ( V_73 < 0 )
goto V_153;
V_73 = F_43 ( V_1 ) ;
if ( V_73 < 0 )
goto V_154;
F_68 ( V_8 , & V_1 -> V_155 , V_108 ) ;
V_102:
return V_73 ;
V_154:
V_108 -> V_156 ( V_108 ) ;
V_153:
V_108 -> V_157 ( V_108 , & V_1 -> V_145 ) ;
V_151:
V_108 -> V_157 ( V_108 , & V_1 -> V_142 ) ;
V_150:
F_69 ( & V_1 -> V_147 ) ;
V_148:
F_70 ( V_106 ) ;
V_141:
F_71 ( V_8 ) ;
V_131:
F_72 ( & V_1 -> V_83 ) ;
V_129:
F_36 ( V_1 ) ;
V_117:
F_73 ( V_29 -> V_47 , V_1 ) ;
V_116:
F_52 ( V_29 , V_1 -> V_10 ) ;
V_114:
F_74 ( V_29 ) ;
V_112:
F_75 ( V_29 ) ;
V_111:
F_76 ( V_1 ) ;
goto V_102;
}
static void F_77 ( struct V_98 * V_29 )
{
struct V_1 * V_1 = F_78 ( V_29 ) ;
struct V_8 * V_8 = & V_1 -> V_8 ;
struct V_105 * V_106 = & V_1 -> V_4 ;
struct V_107 * V_108 = & V_106 -> V_108 ;
V_108 -> V_158 ( V_108 ) ;
F_79 ( & V_1 -> V_155 ) ;
if ( V_1 -> V_6 )
F_80 ( V_1 -> V_6 ) ;
V_108 -> V_156 ( V_108 ) ;
V_108 -> V_157 ( V_108 , & V_1 -> V_145 ) ;
V_108 -> V_157 ( V_108 , & V_1 -> V_142 ) ;
F_69 ( & V_1 -> V_147 ) ;
F_70 ( V_106 ) ;
F_71 ( V_8 ) ;
F_72 ( & V_1 -> V_83 ) ;
F_36 ( V_1 ) ;
F_73 ( V_29 -> V_47 , V_1 ) ;
F_52 ( V_29 , V_1 -> V_10 ) ;
F_74 ( V_29 ) ;
F_75 ( V_29 ) ;
F_76 ( V_1 ) ;
}
