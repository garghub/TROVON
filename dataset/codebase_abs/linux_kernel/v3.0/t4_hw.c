static int F_1 ( struct V_1 * V_1 , int V_2 , T_1 V_3 ,
int V_4 , int V_5 , int V_6 , T_1 * V_7 )
{
while ( 1 ) {
T_1 V_8 = F_2 ( V_1 , V_2 ) ;
if ( ! ! ( V_8 & V_3 ) == V_4 ) {
if ( V_7 )
* V_7 = V_8 ;
return 0 ;
}
if ( -- V_5 == 0 )
return - V_9 ;
if ( V_6 )
F_3 ( V_6 ) ;
}
}
static inline int F_4 ( struct V_1 * V_1 , int V_2 , T_1 V_3 ,
int V_4 , int V_5 , int V_6 )
{
return F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ,
V_6 , NULL ) ;
}
void F_5 ( struct V_1 * V_1 , unsigned int V_10 , T_1 V_3 ,
T_1 V_8 )
{
T_1 V_11 = F_2 ( V_1 , V_10 ) & ~ V_3 ;
F_6 ( V_1 , V_10 , V_11 | V_8 ) ;
( void ) F_2 ( V_1 , V_10 ) ;
}
static void F_7 ( struct V_1 * V_12 , unsigned int V_13 ,
unsigned int V_14 , T_1 * V_15 ,
unsigned int V_16 , unsigned int V_17 )
{
while ( V_16 -- ) {
F_6 ( V_12 , V_13 , V_17 ) ;
* V_15 ++ = F_2 ( V_12 , V_14 ) ;
V_17 ++ ;
}
}
static void F_8 ( struct V_1 * V_12 , T_2 * V_18 , int V_19 ,
T_1 V_20 )
{
for ( ; V_19 ; V_19 -- , V_20 += 8 )
* V_18 ++ = F_9 ( F_10 ( V_12 , V_20 ) ) ;
}
static void F_11 ( struct V_1 * V_12 , T_1 V_20 )
{
struct V_21 V_22 ;
F_8 ( V_12 , ( T_2 * ) & V_22 , sizeof( V_22 ) / 8 , V_20 ) ;
F_12 ( V_12 -> V_23 ,
L_1 ,
V_22 . V_24 . assert . V_25 , F_13 ( V_22 . V_24 . assert . line ) ,
F_13 ( V_22 . V_24 . assert . V_26 ) , F_13 ( V_22 . V_24 . assert . V_27 ) ) ;
}
static void F_14 ( struct V_1 * V_12 , int V_28 , T_1 V_14 )
{
F_15 ( V_12 -> V_23 ,
L_2 , V_28 ,
( unsigned long long ) F_10 ( V_12 , V_14 ) ,
( unsigned long long ) F_10 ( V_12 , V_14 + 8 ) ,
( unsigned long long ) F_10 ( V_12 , V_14 + 16 ) ,
( unsigned long long ) F_10 ( V_12 , V_14 + 24 ) ,
( unsigned long long ) F_10 ( V_12 , V_14 + 32 ) ,
( unsigned long long ) F_10 ( V_12 , V_14 + 40 ) ,
( unsigned long long ) F_10 ( V_12 , V_14 + 48 ) ,
( unsigned long long ) F_10 ( V_12 , V_14 + 56 ) ) ;
}
int F_16 ( struct V_1 * V_12 , int V_28 , const void * V_29 , int V_30 ,
void * V_18 , bool V_31 )
{
static const int V_6 [] = {
1 , 1 , 3 , 5 , 10 , 10 , 20 , 50 , 100 , 200
} ;
T_1 V_11 ;
T_3 V_32 ;
int V_33 , V_34 , V_35 ;
const T_2 * V_36 = V_29 ;
T_1 V_14 = F_17 ( V_28 , V_37 ) ;
T_1 V_38 = F_17 ( V_28 , V_39 ) ;
if ( ( V_30 & 15 ) || V_30 > V_40 )
return - V_41 ;
if ( V_12 -> V_42 -> V_43 != V_44 )
return - V_45 ;
V_11 = F_18 ( F_2 ( V_12 , V_38 ) ) ;
for ( V_33 = 0 ; V_11 == V_46 && V_33 < 3 ; V_33 ++ )
V_11 = F_18 ( F_2 ( V_12 , V_38 ) ) ;
if ( V_11 != V_47 )
return V_11 ? - V_48 : - V_49 ;
for ( V_33 = 0 ; V_33 < V_30 ; V_33 += 8 )
F_19 ( V_12 , V_14 + V_33 , F_20 ( * V_36 ++ ) ) ;
F_6 ( V_12 , V_38 , V_50 | F_21 ( V_51 ) ) ;
F_2 ( V_12 , V_38 ) ;
V_35 = 0 ;
V_34 = V_6 [ 0 ] ;
for ( V_33 = 0 ; V_33 < V_52 ; V_33 += V_34 ) {
if ( V_31 ) {
V_34 = V_6 [ V_35 ] ;
if ( V_35 < F_22 ( V_6 ) - 1 )
V_35 ++ ;
F_23 ( V_34 ) ;
} else
F_24 ( V_34 ) ;
V_11 = F_2 ( V_12 , V_38 ) ;
if ( F_18 ( V_11 ) == V_47 ) {
if ( ! ( V_11 & V_50 ) ) {
F_6 ( V_12 , V_38 , 0 ) ;
continue;
}
V_32 = F_10 ( V_12 , V_14 ) ;
if ( F_25 ( V_32 >> 32 ) == V_53 ) {
F_11 ( V_12 , V_14 ) ;
V_32 = F_26 ( V_45 ) ;
} else if ( V_18 )
F_8 ( V_12 , V_18 , V_30 / 8 , V_14 ) ;
if ( F_27 ( ( int ) V_32 ) )
F_14 ( V_12 , V_28 , V_14 ) ;
F_6 ( V_12 , V_38 , 0 ) ;
return - F_27 ( ( int ) V_32 ) ;
}
}
F_14 ( V_12 , V_28 , V_14 ) ;
F_15 ( V_12 -> V_23 , L_3 ,
* ( const V_54 * ) V_29 , V_28 ) ;
return - V_49 ;
}
int F_28 ( struct V_1 * V_12 , T_1 V_10 , T_4 * V_55 , T_3 * V_56 )
{
int V_33 ;
if ( F_2 ( V_12 , V_57 ) & V_58 )
return - V_48 ;
F_6 ( V_12 , V_59 , V_10 & ~ 0x3fU ) ;
F_6 ( V_12 , V_60 , 64 ) ;
F_6 ( V_12 , V_61 , 0xc ) ;
F_6 ( V_12 , V_57 , F_29 ( 1 ) | V_58 |
F_30 ( 1 ) ) ;
V_33 = F_4 ( V_12 , V_57 , V_58 , 0 , 10 , 1 ) ;
if ( V_33 )
return V_33 ;
#define F_31 ( V_33 ) MC_BIST_STATUS_REG(MC_BIST_STATUS_RDATA, i)
for ( V_33 = 15 ; V_33 >= 0 ; V_33 -- )
* V_55 ++ = F_32 ( F_2 ( V_12 , F_31 ( V_33 ) ) ) ;
if ( V_56 )
* V_56 = F_10 ( V_12 , F_31 ( 16 ) ) ;
#undef F_31
return 0 ;
}
int F_33 ( struct V_1 * V_12 , int V_62 , T_1 V_10 , T_4 * V_55 , T_3 * V_56 )
{
int V_33 ;
V_62 *= V_63 ;
if ( F_2 ( V_12 , V_64 + V_62 ) & V_58 )
return - V_48 ;
F_6 ( V_12 , V_65 + V_62 , V_10 & ~ 0x3fU ) ;
F_6 ( V_12 , V_66 + V_62 , 64 ) ;
F_6 ( V_12 , V_67 + V_62 , 0xc ) ;
F_6 ( V_12 , V_64 + V_62 ,
F_29 ( 1 ) | F_30 ( 1 ) | V_58 ) ;
V_33 = F_4 ( V_12 , V_64 + V_62 , V_58 , 0 , 10 , 1 ) ;
if ( V_33 )
return V_33 ;
#define F_34 ( V_33 ) (EDC_BIST_STATUS_REG(EDC_BIST_STATUS_RDATA, i) + idx)
for ( V_33 = 15 ; V_33 >= 0 ; V_33 -- )
* V_55 ++ = F_32 ( F_2 ( V_12 , F_34 ( V_33 ) ) ) ;
if ( V_56 )
* V_56 = F_10 ( V_12 , F_34 ( 16 ) ) ;
#undef F_34
return 0 ;
}
int F_35 ( struct V_1 * V_1 , bool V_68 )
{
unsigned int V_11 = V_68 ? 0xc : 0 ;
int V_69 = F_36 ( V_1 -> V_42 , V_70 , 4 , & V_11 ) ;
return V_69 < 0 ? V_69 : 0 ;
}
static int F_37 ( struct V_1 * V_1 , struct V_71 * V_36 )
{
int V_33 , V_69 ;
int V_72 , V_73 ;
V_54 V_74 [ V_75 ] , V_76 ;
unsigned int V_77 , V_78 , V_79 ;
V_69 = F_38 ( V_1 -> V_42 , V_80 , sizeof( V_74 ) , V_74 ) ;
if ( V_69 < 0 )
return V_69 ;
if ( V_74 [ 0 ] != V_81 ) {
F_15 ( V_1 -> V_23 , L_4 ) ;
return - V_41 ;
}
V_79 = F_39 ( V_74 ) ;
if ( V_79 > V_82 )
V_79 = V_82 ;
V_33 = F_40 ( V_74 , 0 , V_75 , V_83 ) ;
if ( V_33 < 0 ) {
F_15 ( V_1 -> V_23 , L_5 ) ;
return - V_41 ;
}
V_77 = F_39 ( & V_74 [ V_33 ] ) ;
V_78 = V_33 + V_84 ;
if ( V_77 + V_78 > V_75 ) {
F_15 ( V_1 -> V_23 , L_6 , V_77 ) ;
return - V_41 ;
}
#define F_41 ( T_5 , T_6 ) do { \
var = pci_vpd_find_info_keyword(vpd, kw_offset, vpdr_len, name); \
if (var < 0) { \
dev_err(adapter->pdev_dev, "missing VPD keyword " name "\n"); \
return -EINVAL; \
} \
var += PCI_VPD_INFO_FLD_HDR_SIZE; \
} while (0)
F_41 ( V_33 , L_7 ) ;
for ( V_76 = 0 ; V_33 >= 0 ; V_33 -- )
V_76 += V_74 [ V_33 ] ;
if ( V_76 ) {
F_15 ( V_1 -> V_23 ,
L_8 , V_76 ) ;
return - V_41 ;
}
F_41 ( V_72 , L_9 ) ;
F_41 ( V_73 , L_10 ) ;
#undef F_41
memcpy ( V_36 -> V_85 , V_74 + V_84 , V_79 ) ;
F_42 ( V_36 -> V_85 ) ;
memcpy ( V_36 -> V_72 , V_74 + V_72 , V_86 ) ;
F_42 ( V_36 -> V_72 ) ;
V_33 = F_43 ( V_74 + V_73 - V_87 ) ;
memcpy ( V_36 -> V_73 , V_74 + V_73 , F_44 ( V_33 , V_88 ) ) ;
F_42 ( V_36 -> V_73 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_1 , unsigned int V_89 , int V_90 ,
int V_91 , T_1 * V_7 )
{
int V_69 ;
if ( ! V_89 || V_89 > 4 )
return - V_41 ;
if ( F_2 ( V_1 , V_92 ) & V_93 )
return - V_48 ;
V_90 = V_90 ? V_94 : 0 ;
V_91 = V_91 ? V_95 : 0 ;
F_6 ( V_1 , V_92 , V_91 | V_90 | F_46 ( V_89 - 1 ) ) ;
V_69 = F_4 ( V_1 , V_92 , V_93 , 0 , V_96 , 5 ) ;
if ( ! V_69 )
* V_7 = F_2 ( V_1 , V_97 ) ;
return V_69 ;
}
static int F_47 ( struct V_1 * V_1 , unsigned int V_89 , int V_90 ,
int V_91 , T_1 V_8 )
{
if ( ! V_89 || V_89 > 4 )
return - V_41 ;
if ( F_2 ( V_1 , V_92 ) & V_93 )
return - V_48 ;
V_90 = V_90 ? V_94 : 0 ;
V_91 = V_91 ? V_95 : 0 ;
F_6 ( V_1 , V_97 , V_8 ) ;
F_6 ( V_1 , V_92 , V_91 |
V_90 | F_46 ( V_89 - 1 ) | V_98 ) ;
return F_4 ( V_1 , V_92 , V_93 , 0 , V_96 , 5 ) ;
}
static int F_48 ( struct V_1 * V_1 , int V_5 , int V_6 )
{
int V_69 ;
T_1 V_99 ;
while ( 1 ) {
if ( ( V_69 = F_47 ( V_1 , 1 , 1 , 1 , V_100 ) ) != 0 ||
( V_69 = F_45 ( V_1 , 1 , 0 , 1 , & V_99 ) ) != 0 )
return V_69 ;
if ( ! ( V_99 & 1 ) )
return 0 ;
if ( -- V_5 == 0 )
return - V_9 ;
if ( V_6 )
F_23 ( V_6 ) ;
}
}
static int F_49 ( struct V_1 * V_1 , unsigned int V_10 ,
unsigned int V_101 , T_1 * V_55 , int V_102 )
{
int V_69 ;
if ( V_10 + V_101 * sizeof( T_1 ) > V_1 -> V_103 . V_104 || ( V_10 & 3 ) )
return - V_41 ;
V_10 = F_50 ( V_10 ) | V_105 ;
if ( ( V_69 = F_47 ( V_1 , 4 , 1 , 0 , V_10 ) ) != 0 ||
( V_69 = F_45 ( V_1 , 1 , 1 , 0 , V_55 ) ) != 0 )
return V_69 ;
for ( ; V_101 ; V_101 -- , V_55 ++ ) {
V_69 = F_45 ( V_1 , 4 , V_101 > 1 , V_101 == 1 , V_55 ) ;
if ( V_101 == 1 )
F_6 ( V_1 , V_92 , 0 ) ;
if ( V_69 )
return V_69 ;
if ( V_102 )
* V_55 = F_32 ( * V_55 ) ;
}
return 0 ;
}
static int F_51 ( struct V_1 * V_1 , unsigned int V_10 ,
unsigned int V_106 , const V_54 * V_55 )
{
int V_69 ;
T_1 V_107 [ 64 ] ;
unsigned int V_33 , V_108 , V_109 , V_8 , V_110 = V_10 & 0xff ;
if ( V_10 >= V_1 -> V_103 . V_104 || V_110 + V_106 > V_111 )
return - V_41 ;
V_8 = F_50 ( V_10 ) | V_112 ;
if ( ( V_69 = F_47 ( V_1 , 1 , 0 , 1 , V_113 ) ) != 0 ||
( V_69 = F_47 ( V_1 , 4 , 1 , 1 , V_8 ) ) != 0 )
goto V_114;
for ( V_109 = V_106 ; V_109 ; V_109 -= V_108 ) {
V_108 = F_44 ( V_109 , 4U ) ;
for ( V_8 = 0 , V_33 = 0 ; V_33 < V_108 ; ++ V_33 )
V_8 = ( V_8 << 8 ) + * V_55 ++ ;
V_69 = F_47 ( V_1 , V_108 , V_108 != V_109 , 1 , V_8 ) ;
if ( V_69 )
goto V_114;
}
V_69 = F_48 ( V_1 , 8 , 1 ) ;
if ( V_69 )
goto V_114;
F_6 ( V_1 , V_92 , 0 ) ;
V_69 = F_49 ( V_1 , V_10 & ~ 0xff , F_22 ( V_107 ) , V_107 , 1 ) ;
if ( V_69 )
return V_69 ;
if ( memcmp ( V_55 - V_106 , ( V_54 * ) V_107 + V_110 , V_106 ) ) {
F_15 ( V_1 -> V_23 ,
L_11 ,
V_10 ) ;
return - V_45 ;
}
return 0 ;
V_114:
F_6 ( V_1 , V_92 , 0 ) ;
return V_69 ;
}
static int F_52 ( struct V_1 * V_1 , T_1 * V_115 )
{
return F_49 ( V_1 , V_1 -> V_103 . V_116 +
F_53 ( struct V_117 , V_118 ) , 1 , V_115 , 0 ) ;
}
static int F_54 ( struct V_1 * V_1 , T_1 * V_115 )
{
return F_49 ( V_1 , V_1 -> V_103 . V_116 +
F_53 ( struct V_117 , V_119 ) ,
1 , V_115 , 0 ) ;
}
int F_55 ( struct V_1 * V_1 )
{
T_1 V_120 [ 2 ] ;
int V_69 , V_121 , V_122 , V_123 ;
V_69 = F_52 ( V_1 , & V_1 -> V_103 . V_124 ) ;
if ( ! V_69 )
V_69 = F_54 ( V_1 , & V_1 -> V_103 . V_125 ) ;
if ( ! V_69 )
V_69 = F_49 ( V_1 , V_1 -> V_103 . V_116 +
F_53 ( struct V_117 , V_126 ) ,
2 , V_120 , 1 ) ;
if ( V_69 )
return V_69 ;
V_121 = F_56 ( V_1 -> V_103 . V_124 ) ;
V_122 = F_57 ( V_1 -> V_103 . V_124 ) ;
V_123 = F_58 ( V_1 -> V_103 . V_124 ) ;
memcpy ( V_1 -> V_103 . V_120 , V_120 ,
sizeof( V_1 -> V_103 . V_120 ) ) ;
if ( V_121 != V_127 ) {
F_15 ( V_1 -> V_23 ,
L_12 ,
V_121 , V_127 ) ;
return - V_41 ;
}
if ( V_122 == V_128 && V_123 == V_129 )
return 0 ;
return 1 ;
}
static int F_59 ( struct V_1 * V_1 , int V_130 , int V_131 )
{
int V_69 = 0 ;
while ( V_130 <= V_131 ) {
if ( ( V_69 = F_47 ( V_1 , 1 , 0 , 1 , V_113 ) ) != 0 ||
( V_69 = F_47 ( V_1 , 4 , 0 , 1 ,
V_132 | ( V_130 << 8 ) ) ) != 0 ||
( V_69 = F_48 ( V_1 , 14 , 500 ) ) != 0 ) {
F_15 ( V_1 -> V_23 ,
L_13 ,
V_130 , V_69 ) ;
break;
}
V_130 ++ ;
}
F_6 ( V_1 , V_92 , 0 ) ;
return V_69 ;
}
int F_60 ( struct V_1 * V_12 , const V_54 * V_133 , unsigned int V_30 )
{
T_1 V_76 ;
int V_69 , V_10 ;
unsigned int V_33 ;
V_54 V_134 [ V_111 ] ;
const T_1 * V_36 = ( const T_1 * ) V_133 ;
const struct V_117 * V_135 = ( const struct V_117 * ) V_133 ;
unsigned int V_136 = V_12 -> V_103 . V_104 / V_12 -> V_103 . V_137 ;
unsigned int V_138 = V_12 -> V_103 . V_116 ;
unsigned int V_139 = V_138 / V_136 ;
if ( ! V_30 ) {
F_15 ( V_12 -> V_23 , L_14 ) ;
return - V_41 ;
}
if ( V_30 & 511 ) {
F_15 ( V_12 -> V_23 ,
L_15 ) ;
return - V_41 ;
}
if ( F_61 ( V_135 -> V_140 ) * 512 != V_30 ) {
F_15 ( V_12 -> V_23 ,
L_16 ) ;
return - V_41 ;
}
if ( V_30 > V_141 ) {
F_15 ( V_12 -> V_23 , L_17 ,
V_141 ) ;
return - V_142 ;
}
for ( V_76 = 0 , V_33 = 0 ; V_33 < V_30 / sizeof( V_76 ) ; V_33 ++ )
V_76 += F_13 ( V_36 [ V_33 ] ) ;
if ( V_76 != 0xffffffff ) {
F_15 ( V_12 -> V_23 ,
L_18 , V_76 ) ;
return - V_41 ;
}
V_33 = F_62 ( V_30 , V_136 ) ;
V_69 = F_59 ( V_12 , V_139 , V_139 + V_33 - 1 ) ;
if ( V_69 )
goto V_143;
memcpy ( V_134 , V_133 , V_111 ) ;
( (struct V_117 * ) V_134 ) -> V_118 = F_32 ( 0xffffffff ) ;
V_69 = F_51 ( V_12 , V_138 , V_111 , V_134 ) ;
if ( V_69 )
goto V_143;
V_10 = V_138 ;
for ( V_30 -= V_111 ; V_30 ; V_30 -= V_111 ) {
V_10 += V_111 ;
V_133 += V_111 ;
V_69 = F_51 ( V_12 , V_10 , V_111 , V_133 ) ;
if ( V_69 )
goto V_143;
}
V_69 = F_51 ( V_12 ,
V_138 + F_53 ( struct V_117 , V_118 ) ,
sizeof( V_135 -> V_118 ) , ( const V_54 * ) & V_135 -> V_118 ) ;
V_143:
if ( V_69 )
F_15 ( V_12 -> V_23 , L_19 ,
V_69 ) ;
return V_69 ;
}
int F_63 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_144 ,
struct V_145 * V_146 )
{
struct V_147 V_108 ;
unsigned int V_148 = 0 , V_149 = F_64 ( V_150 ) ;
V_146 -> V_151 = 0 ;
if ( V_146 -> V_152 & V_153 )
V_148 |= V_154 ;
if ( V_146 -> V_152 & V_155 )
V_148 |= V_156 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_157 = F_32 ( F_65 ( V_158 ) | V_159 |
V_160 | F_66 ( V_144 ) ) ;
V_108 . V_161 = F_32 ( F_67 ( V_162 ) |
F_68 ( V_108 ) ) ;
if ( ! ( V_146 -> V_163 & V_164 ) ) {
V_108 . V_24 . V_165 . V_166 = F_32 ( ( V_146 -> V_163 & V_167 ) | V_148 ) ;
V_146 -> V_148 = V_146 -> V_152 & ( V_153 | V_155 ) ;
} else if ( V_146 -> V_168 == V_169 ) {
V_108 . V_24 . V_165 . V_166 = F_32 ( V_146 -> V_170 | V_148 | V_149 ) ;
V_146 -> V_148 = V_146 -> V_152 & ( V_153 | V_155 ) ;
} else
V_108 . V_24 . V_165 . V_166 = F_32 ( V_146 -> V_171 | V_148 | V_149 ) ;
return F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , NULL ) ;
}
int F_70 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_144 )
{
struct V_147 V_108 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_157 = F_32 ( F_65 ( V_158 ) | V_159 |
V_160 | F_66 ( V_144 ) ) ;
V_108 . V_161 = F_32 ( F_67 ( V_162 ) |
F_68 ( V_108 ) ) ;
V_108 . V_24 . V_165 . V_166 = F_32 ( V_164 ) ;
return F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , NULL ) ;
}
static int F_71 ( struct V_1 * V_1 , unsigned int V_2 ,
const struct V_172 * V_173 )
{
int V_174 = 0 ;
unsigned int V_3 = 0 ;
unsigned int V_99 = F_2 ( V_1 , V_2 ) ;
for ( ; V_173 -> V_3 ; ++ V_173 ) {
if ( ! ( V_99 & V_173 -> V_3 ) )
continue;
if ( V_173 -> V_174 ) {
V_174 ++ ;
F_12 ( V_1 -> V_23 , L_20 , V_173 -> V_175 ,
V_99 & V_173 -> V_3 ) ;
} else if ( V_173 -> V_175 && F_72 () )
F_73 ( V_1 -> V_23 , L_20 , V_173 -> V_175 ,
V_99 & V_173 -> V_3 ) ;
V_3 |= V_173 -> V_3 ;
}
V_99 &= V_3 ;
if ( V_99 )
F_6 ( V_1 , V_2 , V_99 ) ;
return V_174 ;
}
static void F_74 ( struct V_1 * V_1 )
{
static const struct V_172 V_176 [] = {
{ V_177 , L_21 , - 1 , 1 } ,
{ V_178 , L_22 , - 1 , 1 } ,
{ V_179 , L_23 , - 1 , 1 } ,
{ V_180 , L_24 , - 1 , 1 } ,
{ V_181 , L_25 , - 1 , 1 } ,
{ 0 }
} ;
static const struct V_172 V_182 [] = {
{ V_183 , L_26 , - 1 , 1 } ,
{ V_184 , L_27 , - 1 , 1 } ,
{ V_185 , L_28 , - 1 , 1 } ,
{ V_186 , L_29 , - 1 , 1 } ,
{ V_187 , L_30 , - 1 , 1 } ,
{ V_188 , L_31 , - 1 , 1 } ,
{ V_189 , L_32 , - 1 , 1 } ,
{ V_190 , L_33 , - 1 , 1 } ,
{ V_191 , L_34 , - 1 , 1 } ,
{ 0 }
} ;
static const struct V_172 V_192 [] = {
{ V_193 , L_35 , - 1 , 1 } ,
{ V_194 , L_36 , - 1 , 1 } ,
{ V_195 , L_37 , - 1 , 1 } ,
{ V_196 , L_38 , - 1 , 1 } ,
{ V_197 , L_39 , - 1 , 1 } ,
{ V_198 , L_40 , - 1 , 1 } ,
{ V_199 , L_41 , - 1 , 1 } ,
{ V_200 , L_42 , - 1 , 1 } ,
{ V_201 , L_43 , - 1 , 1 } ,
{ V_202 , L_44 , - 1 , 1 } ,
{ V_203 , L_45 , - 1 , 1 } ,
{ V_204 , L_46 , - 1 , 1 } ,
{ V_205 , L_47 , - 1 , 1 } ,
{ V_206 , L_48 , - 1 , 1 } ,
{ V_207 , L_49 , - 1 , 1 } ,
{ V_208 , L_50 , - 1 , 1 } ,
{ V_209 , L_51 , - 1 , 1 } ,
{ V_210 , L_52 , - 1 , 1 } ,
{ V_211 , L_53 , - 1 , 1 } ,
{ V_212 , L_54 , - 1 , 1 } ,
{ V_213 , L_55 , - 1 , 1 } ,
{ V_214 , L_56 , - 1 , 1 } ,
{ V_215 , L_57 , - 1 , 1 } ,
{ V_216 , L_58 , - 1 , 1 } ,
{ V_217 , L_59 , - 1 , 1 } ,
{ V_218 , L_60 , - 1 , 1 } ,
{ V_219 , L_61 , - 1 , 1 } ,
{ V_220 , L_62 , - 1 , 1 } ,
{ V_221 , L_63 , - 1 , 1 } ,
{ V_222 , L_64 , - 1 , 0 } ,
{ 0 }
} ;
int V_223 ;
V_223 = F_71 ( V_1 ,
V_224 ,
V_176 ) +
F_71 ( V_1 ,
V_225 ,
V_182 ) +
F_71 ( V_1 , V_226 , V_192 ) ;
if ( V_223 )
F_75 ( V_1 ) ;
}
static void F_76 ( struct V_1 * V_1 )
{
static const struct V_172 V_227 [] = {
{ 0x3fffffff , L_65 , - 1 , 1 } ,
{ V_228 , L_66 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_71 ( V_1 , V_229 , V_227 ) )
F_75 ( V_1 ) ;
}
static void F_77 ( struct V_1 * V_1 )
{
T_3 V_11 ;
static const struct V_172 V_230 [] = {
{ V_231 ,
L_67 , - 1 , 1 } ,
{ V_232 ,
L_68 , - 1 , 0 } ,
{ V_233 , L_69 , - 1 , 0 } ,
{ V_234 , L_70 , - 1 , 0 } ,
{ V_235 | V_236 ,
L_71 , - 1 , 0 } ,
{ V_237 , L_72 , - 1 ,
0 } ,
{ V_238 , L_73 , - 1 ,
0 } ,
{ V_239 , L_74 , - 1 ,
0 } ,
{ V_240 , L_75 , - 1 ,
0 } ,
{ V_241 ,
L_76 , - 1 , 0 } ,
{ V_242 ,
L_77 , - 1 , 0 } ,
{ V_243 , L_78 , - 1 , 0 } ,
{ V_244 , L_79 , - 1 , 0 } ,
{ 0 }
} ;
V_11 = ( T_3 ) F_2 ( V_1 , V_245 ) |
( ( T_3 ) F_2 ( V_1 , V_246 ) << 32 ) ;
if ( V_11 ) {
F_12 ( V_1 -> V_23 , L_80 ,
( unsigned long long ) V_11 ) ;
F_6 ( V_1 , V_245 , V_11 ) ;
F_6 ( V_1 , V_246 , V_11 >> 32 ) ;
}
if ( F_71 ( V_1 , V_247 , V_230 ) ||
V_11 != 0 )
F_75 ( V_1 ) ;
}
static void F_78 ( struct V_1 * V_1 )
{
static const struct V_172 V_248 [] = {
{ V_249 , L_81 , - 1 , 1 } ,
{ V_250 , L_82 , - 1 , 1 } ,
{ V_251 , L_83 , - 1 , 1 } ,
{ V_252 , L_84 , - 1 , 1 } ,
{ V_253 , L_85 , - 1 , 1 } ,
{ V_254 , L_86 , - 1 , 1 } ,
{ V_255 , L_87 , - 1 , 1 } ,
{ 0 }
} ;
static const struct V_172 V_256 [] = {
{ V_257 , L_88 , - 1 , 1 } ,
{ V_258 , L_89 , - 1 , 1 } ,
{ V_259 , L_90 , - 1 , 1 } ,
{ V_260 , L_91 , - 1 , 1 } ,
{ V_261 , L_92 , - 1 , 1 } ,
{ V_262 , L_93 , - 1 , 1 } ,
{ V_263 , L_94 , - 1 , 1 } ,
{ V_264 , L_95 , - 1 , 1 } ,
{ V_265 , L_96 , - 1 , 1 } ,
{ V_266 , L_97 , - 1 , 1 } ,
{ V_267 , L_98 , - 1 , 1 } ,
{ V_268 , L_99 , - 1 , 1 } ,
{ V_269 , L_100 , - 1 , 1 } ,
{ V_270 , L_101 , - 1 , 1 } ,
{ V_271 , L_102 , - 1 , 1 } ,
{ V_272 , L_103 , - 1 , 1 } ,
{ V_273 , L_104 , - 1 , 1 } ,
{ V_274 , L_105 , - 1 , 1 } ,
{ V_275 , L_106 , - 1 , 1 } ,
{ V_276 , L_107 , - 1 , 1 } ,
{ V_277 , L_108 , - 1 , 1 } ,
{ V_278 , L_109 , - 1 , 1 } ,
{ V_279 , L_110 , - 1 , 1 } ,
{ V_280 , L_111 , - 1 , 1 } ,
{ V_281 , L_112 , - 1 , 1 } ,
{ V_282 , L_113 , - 1 , 1 } ,
{ V_283 , L_114 , - 1 , 1 } ,
{ V_284 , L_115 , - 1 , 1 } ,
{ 0 }
} ;
int V_223 ;
V_223 = F_71 ( V_1 , V_285 ,
V_248 ) +
F_71 ( V_1 , V_286 ,
V_256 ) ;
if ( V_223 )
F_75 ( V_1 ) ;
}
static void F_79 ( struct V_1 * V_1 )
{
static const struct V_172 V_287 [] = {
{ 0x1800000 , L_116 , - 1 , 1 } ,
{ 0x7fffff , L_117 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_71 ( V_1 , V_288 , V_287 ) )
F_75 ( V_1 ) ;
}
static void F_80 ( struct V_1 * V_1 )
{
static const struct V_172 V_289 [] = {
{ V_290 , L_118 , - 1 ,
0 } ,
{ V_291 , L_119 , - 1 ,
0 } ,
{ V_292 , L_120 , - 1 ,
0 } ,
{ V_293 , L_121 , - 1 ,
0 } ,
{ 0xfffffff , L_122 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_71 ( V_1 , V_294 , V_289 ) )
F_75 ( V_1 ) ;
}
static void F_81 ( struct V_1 * V_1 )
{
static const struct V_172 V_295 [] = {
{ V_296 , L_123 , - 1 , 1 } ,
{ V_297 , L_124 , - 1 , 1 } ,
{ V_298 , L_125 , - 1 , 1 } ,
{ V_299 , L_126 , - 1 , 1 } ,
{ V_300 , L_127 , - 1 , 1 } ,
{ V_301 , L_128 , - 1 , 1 } ,
{ V_302 , L_129 , - 1 , 1 } ,
{ V_303 , L_130 , - 1 , 1 } ,
{ V_304 , L_131 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_71 ( V_1 , V_305 , V_295 ) )
F_75 ( V_1 ) ;
}
static void F_82 ( struct V_1 * V_1 )
{
static const struct V_172 V_306 [] = {
{ V_307 , L_132 , - 1 , 1 } ,
{ V_308 , L_133 , - 1 , 1 } ,
{ V_309 , L_134 , - 1 , 1 } ,
{ V_302 , L_135 , - 1 , 1 } ,
{ V_310 , L_136 , - 1 , 1 } ,
{ V_311 , L_137 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_71 ( V_1 , V_312 , V_306 ) )
F_75 ( V_1 ) ;
}
static void F_83 ( struct V_1 * V_1 )
{
static const struct V_172 V_313 [] = {
{ V_314 , L_138 , - 1 , 1 } ,
{ V_315 , L_139 , - 1 , 1 } ,
{ V_316 , L_140 , - 1 , 1 } ,
{ V_317 , L_141 , - 1 , 1 } ,
{ V_318 , L_142 , - 1 , 1 } ,
{ V_319 , L_143 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_71 ( V_1 , V_320 , V_313 ) )
F_75 ( V_1 ) ;
}
static void F_84 ( struct V_1 * V_12 )
{
static const struct V_172 V_321 [] = {
{ V_322 , L_144 , - 1 , 0 } ,
{ V_323 , L_145 , - 1 , 0 } ,
{ V_324 , L_146 , - 1 , 1 } ,
{ V_325 , L_147 , - 1 , 1 } ,
{ V_326 , L_148 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_71 ( V_12 , V_327 , V_321 ) )
F_75 ( V_12 ) ;
}
static void F_85 ( struct V_1 * V_1 )
{
static const struct V_172 V_328 [] = {
{ 0xffffff , L_149 , - 1 , 1 } ,
{ 0 }
} ;
static const struct V_172 V_329 [] = {
{ V_330 , L_150 , - 1 , 1 } ,
{ V_331 , L_151 , - 1 , 1 } ,
{ V_332 , L_152 , - 1 , 1 } ,
{ V_333 , L_153 , - 1 , 1 } ,
{ V_334 , L_154 , - 1 , 1 } ,
{ V_335 , L_155 , - 1 , 1 } ,
{ V_336 , L_156 , - 1 , 1 } ,
{ 0 }
} ;
static const struct V_172 V_337 [] = {
{ V_338 , L_157 , - 1 , 1 } ,
{ V_339 , L_158 , - 1 , 1 } ,
{ V_340 , L_159 , - 1 , 1 } ,
{ 0 }
} ;
static const struct V_172 V_341 [] = {
{ 0x1fffff , L_160 , - 1 , 1 } ,
{ 0 }
} ;
static const struct V_172 V_342 [] = {
{ 0xfffff , L_161 , - 1 , 1 } ,
{ 0 }
} ;
static const struct V_172 V_343 [] = {
{ 0xffffff , L_162 , - 1 , 1 } ,
{ 0 }
} ;
static const struct V_172 V_344 [] = {
{ V_345 , L_163 , - 1 , 1 } ,
{ V_346 , L_164 , - 1 , 1 } ,
{ V_347 , L_165 , - 1 , 1 } ,
{ 0 }
} ;
int V_223 ;
V_223 = F_71 ( V_1 , V_348 ,
V_328 ) +
F_71 ( V_1 , V_349 ,
V_329 ) +
F_71 ( V_1 , V_350 ,
V_337 ) +
F_71 ( V_1 , V_351 ,
V_341 ) +
F_71 ( V_1 , V_352 ,
V_342 ) +
F_71 ( V_1 , V_353 ,
V_343 ) +
F_71 ( V_1 , V_354 ,
V_344 ) ;
F_6 ( V_1 , V_355 , V_356 | V_357 |
V_358 | V_359 | V_360 ) ;
F_2 ( V_1 , V_355 ) ;
if ( V_223 )
F_75 ( V_1 ) ;
}
static void F_86 ( struct V_1 * V_1 , int V_62 )
{
static const char T_6 [ 3 ] [ 5 ] = { L_166 , L_167 , L_168 } ;
unsigned int V_10 , V_361 , V_11 ;
if ( V_62 <= V_362 ) {
V_10 = F_87 ( V_363 , V_62 ) ;
V_361 = F_87 ( V_364 , V_62 ) ;
} else {
V_10 = V_365 ;
V_361 = V_366 ;
}
V_11 = F_2 ( V_1 , V_10 ) & V_367 ;
if ( V_11 & V_368 )
F_12 ( V_1 -> V_23 , L_169 ,
T_6 [ V_62 ] ) ;
if ( V_11 & V_369 ) {
T_1 V_370 = F_88 ( F_2 ( V_1 , V_361 ) ) ;
F_6 ( V_1 , V_361 , V_371 ) ;
if ( F_72 () )
F_73 ( V_1 -> V_23 ,
L_170 ,
V_370 , T_6 [ V_62 ] , V_370 > 1 ? L_171 : L_172 ) ;
}
if ( V_11 & V_372 )
F_12 ( V_1 -> V_23 ,
L_173 , T_6 [ V_62 ] ) ;
F_6 ( V_1 , V_10 , V_11 ) ;
if ( V_11 & ( V_368 | V_372 ) )
F_75 ( V_1 ) ;
}
static void F_89 ( struct V_1 * V_12 )
{
T_1 V_11 , V_99 = F_2 ( V_12 , V_373 ) ;
if ( V_99 & V_374 )
F_12 ( V_12 -> V_23 ,
L_174 ,
F_2 ( V_12 , V_375 ) ) ;
if ( V_99 & V_376 ) {
V_11 = F_2 ( V_12 , V_377 ) ;
F_12 ( V_12 -> V_23 , L_175
L_176 ,
F_90 ( V_11 ) ,
F_91 ( V_11 ) << 4 ) ;
}
F_6 ( V_12 , V_373 , V_99 ) ;
F_75 ( V_12 ) ;
}
static void F_92 ( struct V_1 * V_12 )
{
static const struct V_172 V_378 [] = {
{ V_379 , L_177 , - 1 , 1 } ,
{ V_380 , L_178 , - 1 , 1 } ,
{ V_381 , L_179 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_71 ( V_12 , V_382 , V_378 ) )
F_75 ( V_12 ) ;
}
static void F_93 ( struct V_1 * V_12 )
{
static const struct V_172 V_383 [] = {
{ V_384 , L_180 , - 1 , 1 } ,
{ V_385 , L_181 , - 1 , 1 } ,
{ V_386 , L_182 , - 1 , 1 } ,
{ V_387 , L_183 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_71 ( V_12 , V_388 , V_383 ) )
F_75 ( V_12 ) ;
}
static void F_94 ( struct V_1 * V_12 , int V_144 )
{
T_1 V_11 = F_2 ( V_12 , F_95 ( V_144 , V_389 ) ) ;
V_11 &= V_386 | V_387 ;
if ( ! V_11 )
return;
if ( V_11 & V_386 )
F_12 ( V_12 -> V_23 , L_184 ,
V_144 ) ;
if ( V_11 & V_387 )
F_12 ( V_12 -> V_23 , L_185 ,
V_144 ) ;
F_6 ( V_12 , F_95 ( V_144 , V_389 ) , V_11 ) ;
F_75 ( V_12 ) ;
}
static void F_96 ( struct V_1 * V_12 )
{
static const struct V_172 V_390 [] = {
{ V_391 , L_186 , - 1 , 1 } ,
{ V_392 , L_187 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_71 ( V_12 , V_393 , V_390 ) )
F_75 ( V_12 ) ;
}
int F_97 ( struct V_1 * V_1 )
{
T_1 V_394 = F_2 ( V_1 , V_395 ) ;
if ( ! ( V_394 & V_396 ) )
return 0 ;
if ( V_394 & V_397 )
F_78 ( V_1 ) ;
if ( V_394 & V_398 )
F_85 ( V_1 ) ;
if ( V_394 & V_399 )
F_93 ( V_1 ) ;
if ( V_394 & V_400 )
F_96 ( V_1 ) ;
if ( V_394 & V_401 )
F_92 ( V_1 ) ;
if ( V_394 & V_402 )
F_94 ( V_1 , 0 ) ;
if ( V_394 & V_403 )
F_94 ( V_1 , 1 ) ;
if ( V_394 & V_404 )
F_94 ( V_1 , 2 ) ;
if ( V_394 & V_405 )
F_94 ( V_1 , 3 ) ;
if ( V_394 & V_406 )
F_74 ( V_1 ) ;
if ( V_394 & V_407 )
F_86 ( V_1 , V_408 ) ;
if ( V_394 & V_409 )
F_86 ( V_1 , V_410 ) ;
if ( V_394 & V_411 )
F_86 ( V_1 , V_362 ) ;
if ( V_394 & V_412 )
F_84 ( V_1 ) ;
if ( V_394 & V_413 )
F_76 ( V_1 ) ;
if ( V_394 & V_414 )
F_89 ( V_1 ) ;
if ( V_394 & V_415 )
F_81 ( V_1 ) ;
if ( V_394 & V_416 )
F_82 ( V_1 ) ;
if ( V_394 & V_417 )
F_79 ( V_1 ) ;
if ( V_394 & V_418 )
F_83 ( V_1 ) ;
if ( V_394 & V_419 )
F_77 ( V_1 ) ;
if ( V_394 & V_420 )
F_80 ( V_1 ) ;
F_6 ( V_1 , V_395 , V_394 & V_396 ) ;
( void ) F_2 ( V_1 , V_395 ) ;
return 1 ;
}
void F_98 ( struct V_1 * V_1 )
{
T_1 V_421 = F_99 ( F_2 ( V_1 , V_422 ) ) ;
F_6 ( V_1 , V_423 , V_231 |
V_232 | V_233 |
V_234 | V_235 |
V_236 | V_237 |
V_238 | V_239 |
V_240 | V_241 |
V_242 | V_243 |
V_244 ) ;
F_6 ( V_1 , F_100 ( V_424 ) , V_425 ) ;
F_5 ( V_1 , V_426 , 0 , 1 << V_421 ) ;
}
void F_101 ( struct V_1 * V_1 )
{
T_1 V_421 = F_99 ( F_2 ( V_1 , V_422 ) ) ;
F_6 ( V_1 , F_100 ( V_424 ) , 0 ) ;
F_5 ( V_1 , V_426 , 1 << V_421 , 0 ) ;
}
static int F_102 ( const V_54 * V_10 )
{
T_1 V_427 = ( ( T_1 ) V_10 [ 0 ] << 16 ) | ( ( T_1 ) V_10 [ 1 ] << 8 ) | V_10 [ 2 ] ;
T_1 V_428 = ( ( T_1 ) V_10 [ 3 ] << 16 ) | ( ( T_1 ) V_10 [ 4 ] << 8 ) | V_10 [ 5 ] ;
V_427 ^= V_428 ;
V_427 ^= ( V_427 >> 12 ) ;
V_427 ^= ( V_427 >> 6 ) ;
return V_427 & 0x3f ;
}
int F_103 ( struct V_1 * V_1 , int V_28 , unsigned int V_429 ,
int V_130 , int V_106 , const T_7 * V_430 , unsigned int V_431 )
{
int V_69 ;
const T_7 * V_432 = V_430 ;
const T_7 * V_433 = V_430 + V_431 ;
struct V_434 V_29 ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
V_29 . V_435 = F_32 ( F_65 ( V_436 ) |
V_159 | V_437 |
F_104 ( V_429 ) ) ;
V_29 . V_438 = F_32 ( F_68 ( V_29 ) ) ;
while ( V_106 > 0 ) {
int V_439 = F_44 ( V_106 , 32 ) ;
T_4 * V_440 = & V_29 . V_441 ;
V_29 . V_442 = F_105 ( V_439 ) ;
V_29 . V_443 = F_105 ( V_130 ) ;
V_130 += V_439 ;
V_106 -= V_439 ;
while ( V_439 > 0 ) {
unsigned int V_11 ;
V_11 = F_106 ( * V_432 ) ;
if ( ++ V_432 >= V_433 )
V_432 = V_430 ;
V_11 |= F_107 ( * V_432 ) ;
if ( ++ V_432 >= V_433 )
V_432 = V_430 ;
V_11 |= F_108 ( * V_432 ) ;
if ( ++ V_432 >= V_433 )
V_432 = V_430 ;
* V_440 ++ = F_32 ( V_11 ) ;
V_439 -= 3 ;
}
V_69 = F_69 ( V_1 , V_28 , & V_29 , sizeof( V_29 ) , NULL ) ;
if ( V_69 )
return V_69 ;
}
return 0 ;
}
int F_109 ( struct V_1 * V_1 , int V_28 , unsigned int V_444 ,
unsigned int V_445 )
{
struct V_446 V_108 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_447 = F_32 ( F_65 ( V_448 ) |
V_159 | V_437 ) ;
V_108 . V_438 = F_32 ( F_68 ( V_108 ) ) ;
if ( V_444 == V_449 ) {
V_108 . V_24 . V_450 . V_451 = F_32 ( F_110 ( V_444 ) ) ;
} else if ( V_444 == V_452 ) {
V_108 . V_24 . V_453 . V_451 =
F_32 ( F_110 ( V_444 ) ) ;
V_108 . V_24 . V_453 . V_454 = F_32 ( V_445 ) ;
} else
return - V_41 ;
return F_69 ( V_1 , V_28 , & V_108 , sizeof( V_108 ) , NULL ) ;
}
void F_111 ( struct V_1 * V_12 , struct V_455 * V_456 ,
struct V_455 * V_457 )
{
T_1 V_8 [ V_458 - V_459 + 1 ] ;
#define F_112 ( V_26 ) ((TP_MIB_TCP_##x) - TP_MIB_TCP_OUT_RST)
#define F_113 ( V_26 ) val[STAT_IDX(x)]
#define F_114 ( V_26 ) (((u64)STAT(x##_HI) << 32) | STAT(x##_LO))
if ( V_456 ) {
F_7 ( V_12 , V_460 , V_461 , V_8 ,
F_22 ( V_8 ) , V_459 ) ;
V_456 -> V_462 = F_113 ( V_463 ) ;
V_456 -> V_464 = F_114 ( V_465 ) ;
V_456 -> V_466 = F_114 ( V_467 ) ;
V_456 -> V_468 = F_114 ( V_469 ) ;
}
if ( V_457 ) {
F_7 ( V_12 , V_460 , V_461 , V_8 ,
F_22 ( V_8 ) , V_470 ) ;
V_457 -> V_462 = F_113 ( V_463 ) ;
V_457 -> V_464 = F_114 ( V_465 ) ;
V_457 -> V_466 = F_114 ( V_467 ) ;
V_457 -> V_468 = F_114 ( V_469 ) ;
}
#undef F_114
#undef F_113
#undef F_112
}
void F_115 ( struct V_1 * V_12 , T_7 * V_471 , V_54 * V_472 )
{
T_1 V_11 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_473 ; ++ V_33 ) {
F_6 ( V_12 , V_474 ,
F_116 ( 0xff ) | F_117 ( V_33 ) ) ;
V_11 = F_2 ( V_12 , V_474 ) ;
V_471 [ V_33 ] = F_118 ( V_11 ) ;
if ( V_472 )
V_472 [ V_33 ] = F_119 ( V_11 ) ;
}
}
static void T_8 F_120 ( unsigned short * V_427 , unsigned short * V_428 )
{
V_427 [ 0 ] = V_427 [ 1 ] = V_427 [ 2 ] = V_427 [ 3 ] = V_427 [ 4 ] = V_427 [ 5 ] = V_427 [ 6 ] = V_427 [ 7 ] = V_427 [ 8 ] = 1 ;
V_427 [ 9 ] = 2 ;
V_427 [ 10 ] = 3 ;
V_427 [ 11 ] = 4 ;
V_427 [ 12 ] = 5 ;
V_427 [ 13 ] = 6 ;
V_427 [ 14 ] = 7 ;
V_427 [ 15 ] = 8 ;
V_427 [ 16 ] = 9 ;
V_427 [ 17 ] = 10 ;
V_427 [ 18 ] = 14 ;
V_427 [ 19 ] = 17 ;
V_427 [ 20 ] = 21 ;
V_427 [ 21 ] = 25 ;
V_427 [ 22 ] = 30 ;
V_427 [ 23 ] = 35 ;
V_427 [ 24 ] = 45 ;
V_427 [ 25 ] = 60 ;
V_427 [ 26 ] = 80 ;
V_427 [ 27 ] = 100 ;
V_427 [ 28 ] = 200 ;
V_427 [ 29 ] = 300 ;
V_427 [ 30 ] = 400 ;
V_427 [ 31 ] = 500 ;
V_428 [ 0 ] = V_428 [ 1 ] = V_428 [ 2 ] = V_428 [ 3 ] = V_428 [ 4 ] = V_428 [ 5 ] = V_428 [ 6 ] = V_428 [ 7 ] = V_428 [ 8 ] = 0 ;
V_428 [ 9 ] = V_428 [ 10 ] = 1 ;
V_428 [ 11 ] = V_428 [ 12 ] = 2 ;
V_428 [ 13 ] = V_428 [ 14 ] = V_428 [ 15 ] = V_428 [ 16 ] = 3 ;
V_428 [ 17 ] = V_428 [ 18 ] = V_428 [ 19 ] = V_428 [ 20 ] = V_428 [ 21 ] = 4 ;
V_428 [ 22 ] = V_428 [ 23 ] = V_428 [ 24 ] = V_428 [ 25 ] = V_428 [ 26 ] = V_428 [ 27 ] = 5 ;
V_428 [ 28 ] = V_428 [ 29 ] = 6 ;
V_428 [ 30 ] = V_428 [ 31 ] = 7 ;
}
void F_121 ( struct V_1 * V_12 , const unsigned short * V_471 ,
const unsigned short * V_475 , const unsigned short * V_476 )
{
static const unsigned int V_477 [ V_478 ] = {
2 , 6 , 10 , 14 , 20 , 28 , 40 , 56 , 80 , 112 , 160 , 224 , 320 , 448 , 640 ,
896 , 1281 , 1792 , 2560 , 3584 , 5120 , 7168 , 10240 , 14336 , 20480 ,
28672 , 40960 , 57344 , 81920 , 114688 , 163840 , 229376
} ;
unsigned int V_33 , V_479 ;
for ( V_33 = 0 ; V_33 < V_473 ; ++ V_33 ) {
unsigned int V_480 = V_471 [ V_33 ] ;
unsigned int V_481 = F_122 ( V_480 ) ;
if ( ! ( V_480 & ( ( 1 << V_481 ) >> 2 ) ) )
V_481 -- ;
F_6 ( V_12 , V_474 , F_116 ( V_33 ) |
F_123 ( V_481 ) | F_117 ( V_480 ) ) ;
for ( V_479 = 0 ; V_479 < V_478 ; ++ V_479 ) {
unsigned int V_482 ;
V_482 = F_124 ( ( ( V_480 - 40 ) * V_475 [ V_479 ] ) / V_477 [ V_479 ] ,
V_483 ) ;
F_6 ( V_12 , V_484 , ( V_33 << 21 ) |
( V_479 << 16 ) | ( V_476 [ V_479 ] << 13 ) | V_482 ) ;
}
}
}
static unsigned int F_125 ( struct V_1 * V_12 , int V_62 )
{
T_1 V_106 = F_126 ( F_2 ( V_12 , V_485 ) ) ;
if ( V_106 == 0 )
return V_62 == 0 ? 0xf : 0 ;
if ( V_106 == 1 )
return V_62 < 2 ? ( 3 << ( 2 * V_62 ) ) : 0 ;
return 1 << V_62 ;
}
void F_127 ( struct V_1 * V_12 , int V_62 , struct V_486 * V_36 )
{
T_1 V_487 = F_125 ( V_12 , V_62 ) ;
#define F_128 ( T_6 ) \
t4_read_reg64(adap, PORT_REG(idx, MPS_PORT_STAT_##name##_L))
#define F_129 ( T_6 ) t4_read_reg64(adap, MPS_STAT_##name##_L)
V_36 -> V_488 = F_128 ( V_489 ) ;
V_36 -> V_490 = F_128 ( V_491 ) ;
V_36 -> V_492 = F_128 ( V_493 ) ;
V_36 -> V_494 = F_128 ( V_495 ) ;
V_36 -> V_496 = F_128 ( V_497 ) ;
V_36 -> V_498 = F_128 ( V_499 ) ;
V_36 -> V_500 = F_128 ( V_501 ) ;
V_36 -> V_502 = F_128 ( V_503 ) ;
V_36 -> V_504 = F_128 ( V_505 ) ;
V_36 -> V_506 = F_128 ( V_507 ) ;
V_36 -> V_508 = F_128 ( V_509 ) ;
V_36 -> V_510 = F_128 ( V_511 ) ;
V_36 -> V_512 = F_128 ( V_513 ) ;
V_36 -> V_514 = F_128 ( V_515 ) ;
V_36 -> V_516 = F_128 ( V_517 ) ;
V_36 -> V_518 = F_128 ( V_519 ) ;
V_36 -> V_520 = F_128 ( V_521 ) ;
V_36 -> V_522 = F_128 ( V_523 ) ;
V_36 -> V_524 = F_128 ( V_525 ) ;
V_36 -> V_526 = F_128 ( V_527 ) ;
V_36 -> V_528 = F_128 ( V_529 ) ;
V_36 -> V_530 = F_128 ( V_531 ) ;
V_36 -> V_532 = F_128 ( V_533 ) ;
V_36 -> V_534 = F_128 ( V_535 ) ;
V_36 -> V_536 = F_128 ( V_537 ) ;
V_36 -> V_538 = F_128 ( V_539 ) ;
V_36 -> V_540 = F_128 ( V_541 ) ;
V_36 -> V_542 = F_128 ( V_543 ) ;
V_36 -> V_544 = F_128 ( V_545 ) ;
V_36 -> V_546 = F_128 ( V_547 ) ;
V_36 -> V_548 = F_128 ( V_549 ) ;
V_36 -> V_550 = F_128 ( V_551 ) ;
V_36 -> V_552 = F_128 ( V_553 ) ;
V_36 -> V_554 = F_128 ( V_555 ) ;
V_36 -> V_556 = F_128 ( V_557 ) ;
V_36 -> V_558 = F_128 ( V_559 ) ;
V_36 -> V_560 = F_128 ( V_561 ) ;
V_36 -> V_562 = F_128 ( V_563 ) ;
V_36 -> V_564 = F_128 ( V_565 ) ;
V_36 -> V_566 = F_128 ( V_567 ) ;
V_36 -> V_568 = F_128 ( V_569 ) ;
V_36 -> V_570 = F_128 ( V_571 ) ;
V_36 -> V_572 = F_128 ( V_573 ) ;
V_36 -> V_574 = F_128 ( V_575 ) ;
V_36 -> V_576 = F_128 ( V_577 ) ;
V_36 -> V_578 = F_128 ( V_579 ) ;
V_36 -> V_580 = F_128 ( V_581 ) ;
V_36 -> V_582 = F_128 ( V_583 ) ;
V_36 -> V_584 = F_128 ( V_585 ) ;
V_36 -> V_586 = F_128 ( V_587 ) ;
V_36 -> V_588 = ( V_487 & 1 ) ? F_129 ( V_589 ) : 0 ;
V_36 -> V_590 = ( V_487 & 2 ) ? F_129 ( V_591 ) : 0 ;
V_36 -> V_592 = ( V_487 & 4 ) ? F_129 ( V_593 ) : 0 ;
V_36 -> V_594 = ( V_487 & 8 ) ? F_129 ( V_595 ) : 0 ;
V_36 -> V_596 = ( V_487 & 1 ) ? F_129 ( V_597 ) : 0 ;
V_36 -> V_598 = ( V_487 & 2 ) ? F_129 ( V_599 ) : 0 ;
V_36 -> V_600 = ( V_487 & 4 ) ? F_129 ( V_601 ) : 0 ;
V_36 -> V_602 = ( V_487 & 8 ) ? F_129 ( V_603 ) : 0 ;
#undef F_128
#undef F_129
}
void F_130 ( struct V_1 * V_12 , unsigned int V_144 ,
const V_54 * V_10 )
{
if ( V_10 ) {
F_6 ( V_12 , F_95 ( V_144 , V_604 ) ,
( V_10 [ 2 ] << 24 ) | ( V_10 [ 3 ] << 16 ) |
( V_10 [ 4 ] << 8 ) | V_10 [ 5 ] ) ;
F_6 ( V_12 , F_95 ( V_144 , V_605 ) ,
( V_10 [ 0 ] << 8 ) | V_10 [ 1 ] ) ;
}
F_5 ( V_12 , F_95 ( V_144 , V_606 ) , V_607 ,
V_10 ? V_607 : 0 ) ;
}
int F_131 ( struct V_1 * V_12 , unsigned int V_144 , unsigned int V_608 ,
T_3 V_609 , T_3 V_610 , unsigned int V_611 , bool V_68 )
{
int V_33 ;
if ( ! V_68 ) {
F_5 ( V_12 , F_95 ( V_144 , V_606 ) ,
V_612 , 0 ) ;
return 0 ;
}
if ( V_608 > 0xff )
return - V_41 ;
#define F_132 ( T_6 ) PORT_REG(port, XGMAC_PORT_EPIO_##name)
F_6 ( V_12 , F_132 ( V_613 ) , V_609 >> 32 ) ;
F_6 ( V_12 , F_132 ( V_614 ) , V_610 ) ;
F_6 ( V_12 , F_132 ( V_615 ) , V_610 >> 32 ) ;
for ( V_33 = 0 ; V_33 < V_616 ; V_33 ++ , V_608 >>= 1 ) {
if ( ! ( V_608 & 1 ) )
continue;
F_6 ( V_12 , F_132 ( V_617 ) , V_609 ) ;
F_6 ( V_12 , F_132 ( V_618 ) , F_133 ( V_33 ) | V_619 ) ;
F_2 ( V_12 , F_132 ( V_618 ) ) ;
if ( F_2 ( V_12 , F_132 ( V_618 ) ) & V_93 )
return - V_49 ;
F_6 ( V_12 , F_132 ( V_617 ) , V_611 ) ;
F_6 ( V_12 , F_132 ( V_618 ) , F_133 ( V_33 + 32 ) | V_619 ) ;
F_2 ( V_12 , F_132 ( V_618 ) ) ;
if ( F_2 ( V_12 , F_132 ( V_618 ) ) & V_93 )
return - V_49 ;
}
#undef F_132
F_5 ( V_12 , F_95 ( V_144 , V_606 ) , 0 , V_612 ) ;
return 0 ;
}
int F_134 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_620 ,
unsigned int V_621 , unsigned int V_2 , T_7 * V_7 )
{
int V_69 ;
struct V_622 V_108 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_623 = F_32 ( F_65 ( V_624 ) | V_159 |
V_625 | F_135 ( V_626 ) ) ;
V_108 . V_627 = F_32 ( F_68 ( V_108 ) ) ;
V_108 . V_24 . V_628 . V_629 = F_105 ( F_136 ( V_620 ) |
F_137 ( V_621 ) ) ;
V_108 . V_24 . V_628 . V_630 = F_105 ( V_2 ) ;
V_69 = F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , & V_108 ) ;
if ( V_69 == 0 )
* V_7 = F_61 ( V_108 . V_24 . V_628 . V_631 ) ;
return V_69 ;
}
int F_138 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_620 ,
unsigned int V_621 , unsigned int V_2 , T_7 V_8 )
{
struct V_622 V_108 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_623 = F_32 ( F_65 ( V_624 ) | V_159 |
V_437 | F_135 ( V_626 ) ) ;
V_108 . V_627 = F_32 ( F_68 ( V_108 ) ) ;
V_108 . V_24 . V_628 . V_629 = F_105 ( F_136 ( V_620 ) |
F_137 ( V_621 ) ) ;
V_108 . V_24 . V_628 . V_630 = F_105 ( V_2 ) ;
V_108 . V_24 . V_628 . V_631 = F_105 ( V_8 ) ;
return F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , NULL ) ;
}
int F_139 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_632 ,
enum V_633 V_634 , enum V_635 * V_636 )
{
int V_69 ;
struct V_637 V_108 ;
F_140 ( V_108 , V_638 , V_639 ) ;
V_108 . V_640 = F_32 (
F_141 ( V_634 == V_641 ) |
F_142 ( V_634 == V_642 ) |
F_143 ( V_634 == V_642 ? V_28 : 0xff ) |
F_144 ( V_632 ) ) ;
V_69 = F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , & V_108 ) ;
if ( V_69 == 0 && V_636 ) {
T_1 V_11 = F_13 ( V_108 . V_640 ) ;
if ( V_11 & V_643 )
* V_636 = V_644 ;
else if ( V_11 & V_645 )
* V_636 = V_646 ;
else
* V_636 = V_647 ;
}
return V_69 ;
}
int F_145 ( struct V_1 * V_12 , unsigned int V_28 )
{
struct V_648 V_108 ;
F_140 ( V_108 , V_649 , V_639 ) ;
return F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , NULL ) ;
}
int F_146 ( struct V_1 * V_12 , unsigned int V_28 )
{
struct V_650 V_108 ;
F_140 ( V_108 , V_651 , V_639 ) ;
return F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , NULL ) ;
}
int F_147 ( struct V_1 * V_12 , unsigned int V_28 , int V_652 )
{
struct V_653 V_108 ;
F_140 ( V_108 , V_654 , V_639 ) ;
V_108 . V_8 = F_32 ( V_652 ) ;
return F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , NULL ) ;
}
int F_148 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_421 ,
unsigned int V_655 , unsigned int V_656 , const T_1 * V_103 ,
T_1 * V_8 )
{
int V_33 , V_69 ;
struct V_657 V_108 ;
T_4 * V_36 = & V_108 . V_658 [ 0 ] . V_659 ;
if ( V_656 > 7 )
return - V_41 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_660 = F_32 ( F_65 ( V_661 ) | V_159 |
V_625 | F_149 ( V_421 ) |
F_150 ( V_655 ) ) ;
V_108 . V_438 = F_32 ( F_68 ( V_108 ) ) ;
for ( V_33 = 0 ; V_33 < V_656 ; V_33 ++ , V_36 += 2 )
* V_36 = F_32 ( * V_103 ++ ) ;
V_69 = F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , & V_108 ) ;
if ( V_69 == 0 )
for ( V_33 = 0 , V_36 = & V_108 . V_658 [ 0 ] . V_8 ; V_33 < V_656 ; V_33 ++ , V_36 += 2 )
* V_8 ++ = F_13 ( * V_36 ) ;
return V_69 ;
}
int F_151 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_421 ,
unsigned int V_655 , unsigned int V_656 , const T_1 * V_103 ,
const T_1 * V_8 )
{
struct V_657 V_108 ;
T_4 * V_36 = & V_108 . V_658 [ 0 ] . V_659 ;
if ( V_656 > 7 )
return - V_41 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_660 = F_32 ( F_65 ( V_661 ) | V_159 |
V_437 | F_149 ( V_421 ) |
F_150 ( V_655 ) ) ;
V_108 . V_438 = F_32 ( F_68 ( V_108 ) ) ;
while ( V_656 -- ) {
* V_36 ++ = F_32 ( * V_103 ++ ) ;
* V_36 ++ = F_32 ( * V_8 ++ ) ;
}
return F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , NULL ) ;
}
int F_152 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_421 ,
unsigned int V_655 , unsigned int V_662 , unsigned int V_663 ,
unsigned int V_664 , unsigned int V_665 , unsigned int V_666 ,
unsigned int V_667 , unsigned int V_668 , unsigned int V_669 ,
unsigned int V_670 , unsigned int V_671 , unsigned int V_672 )
{
struct V_673 V_108 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_660 = F_32 ( F_65 ( V_674 ) | V_159 |
V_437 | F_153 ( V_421 ) |
F_154 ( V_655 ) ) ;
V_108 . V_438 = F_32 ( F_68 ( V_108 ) ) ;
V_108 . V_675 = F_32 ( F_155 ( V_664 ) |
F_156 ( V_665 ) ) ;
V_108 . V_676 = F_32 ( F_157 ( V_668 ) |
F_158 ( V_669 ) |
F_159 ( V_662 ) ) ;
V_108 . V_677 = F_32 ( F_160 ( V_666 ) | F_161 ( V_667 ) |
F_162 ( V_670 ) ) ;
V_108 . V_678 = F_32 ( F_163 ( V_671 ) |
F_164 ( V_672 ) |
F_165 ( V_663 ) ) ;
return F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , NULL ) ;
}
int F_166 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_144 ,
unsigned int V_421 , unsigned int V_655 , unsigned int V_679 , V_54 * V_680 ,
unsigned int * V_681 )
{
int V_69 ;
struct V_682 V_108 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_660 = F_32 ( F_65 ( V_683 ) | V_159 |
V_437 | V_160 |
F_167 ( V_421 ) | F_168 ( V_655 ) ) ;
V_108 . V_684 = F_32 ( V_685 | F_68 ( V_108 ) ) ;
V_108 . V_686 = F_169 ( V_144 ) ;
V_108 . V_679 = V_679 - 1 ;
V_69 = F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , & V_108 ) ;
if ( V_69 )
return V_69 ;
if ( V_680 ) {
memcpy ( V_680 , V_108 . V_680 , sizeof( V_108 . V_680 ) ) ;
switch ( V_679 ) {
case 5 :
memcpy ( V_680 + 24 , V_108 . V_687 , sizeof( V_108 . V_687 ) ) ;
case 4 :
memcpy ( V_680 + 18 , V_108 . V_688 , sizeof( V_108 . V_688 ) ) ;
case 3 :
memcpy ( V_680 + 12 , V_108 . V_689 , sizeof( V_108 . V_689 ) ) ;
case 2 :
memcpy ( V_680 + 6 , V_108 . V_690 , sizeof( V_108 . V_690 ) ) ;
}
}
if ( V_681 )
* V_681 = F_170 ( F_61 ( V_108 . V_691 ) ) ;
return F_171 ( F_61 ( V_108 . V_692 ) ) ;
}
int F_172 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_429 ,
int V_480 , int V_693 , int V_694 , int V_695 , int V_696 ,
bool V_31 )
{
struct V_697 V_108 ;
if ( V_480 < 0 )
V_480 = V_698 ;
if ( V_693 < 0 )
V_693 = V_699 ;
if ( V_694 < 0 )
V_694 = V_700 ;
if ( V_695 < 0 )
V_695 = V_701 ;
if ( V_696 < 0 )
V_696 = V_702 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_435 = F_32 ( F_65 ( V_703 ) | V_159 |
V_437 | F_173 ( V_429 ) ) ;
V_108 . V_438 = F_32 ( F_68 ( V_108 ) ) ;
V_108 . V_704 = F_32 ( F_174 ( V_480 ) |
F_175 ( V_693 ) |
F_176 ( V_694 ) |
F_177 ( V_695 ) |
F_178 ( V_696 ) ) ;
return F_16 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , NULL , V_31 ) ;
}
int F_179 ( struct V_1 * V_12 , unsigned int V_28 ,
unsigned int V_429 , bool free , unsigned int V_705 ,
const V_54 * * V_10 , T_7 * V_62 , T_3 * V_706 , bool V_31 )
{
int V_33 , V_69 ;
struct V_707 V_108 ;
struct V_708 * V_36 ;
if ( V_705 > 7 )
return - V_41 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_435 = F_32 ( F_65 ( V_709 ) | V_159 |
V_437 | ( free ? V_160 : 0 ) |
F_180 ( V_429 ) ) ;
V_108 . V_710 = F_32 ( F_181 ( free ) |
F_182 ( ( V_705 + 2 ) / 2 ) ) ;
for ( V_33 = 0 , V_36 = V_108 . V_24 . V_711 ; V_33 < V_705 ; V_33 ++ , V_36 ++ ) {
V_36 -> V_712 = F_105 ( V_713 |
F_183 ( V_714 ) ) ;
memcpy ( V_36 -> V_715 , V_10 [ V_33 ] , sizeof( V_36 -> V_715 ) ) ;
}
V_69 = F_16 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , & V_108 , V_31 ) ;
if ( V_69 )
return V_69 ;
for ( V_33 = 0 , V_36 = V_108 . V_24 . V_711 ; V_33 < V_705 ; V_33 ++ , V_36 ++ ) {
T_7 V_716 = F_184 ( F_61 ( V_36 -> V_712 ) ) ;
if ( V_62 )
V_62 [ V_33 ] = V_716 >= V_717 ? 0xffff : V_716 ;
if ( V_716 < V_717 )
V_69 ++ ;
else if ( V_706 )
* V_706 |= ( 1ULL << F_102 ( V_10 [ V_33 ] ) ) ;
}
return V_69 ;
}
int F_185 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_429 ,
int V_62 , const V_54 * V_10 , bool V_718 , bool V_719 )
{
int V_69 , V_444 ;
struct V_707 V_108 ;
struct V_708 * V_36 = V_108 . V_24 . V_711 ;
if ( V_62 < 0 )
V_62 = V_718 ? V_720 : V_714 ;
V_444 = V_719 ? V_721 : V_722 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_435 = F_32 ( F_65 ( V_709 ) | V_159 |
V_437 | F_180 ( V_429 ) ) ;
V_108 . V_710 = F_32 ( F_182 ( 1 ) ) ;
V_36 -> V_712 = F_105 ( V_713 |
F_186 ( V_444 ) |
F_183 ( V_62 ) ) ;
memcpy ( V_36 -> V_715 , V_10 , sizeof( V_36 -> V_715 ) ) ;
V_69 = F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , & V_108 ) ;
if ( V_69 == 0 ) {
V_69 = F_184 ( F_61 ( V_36 -> V_712 ) ) ;
if ( V_69 >= V_717 )
V_69 = - V_723 ;
}
return V_69 ;
}
int F_187 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_429 ,
bool V_724 , T_3 V_725 , bool V_31 )
{
struct V_707 V_108 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_435 = F_32 ( F_65 ( V_709 ) | V_159 |
V_437 | F_188 ( V_429 ) ) ;
V_108 . V_710 = F_32 ( V_726 |
F_189 ( V_724 ) |
F_182 ( 1 ) ) ;
V_108 . V_24 . V_706 . V_727 = F_9 ( V_725 ) ;
return F_16 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , NULL , V_31 ) ;
}
int F_190 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_429 ,
bool V_728 , bool V_729 )
{
struct V_730 V_108 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_435 = F_32 ( F_65 ( V_731 ) | V_159 |
V_160 | F_188 ( V_429 ) ) ;
V_108 . V_732 = F_32 ( F_191 ( V_728 ) |
F_192 ( V_729 ) | F_68 ( V_108 ) ) ;
return F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , NULL ) ;
}
int F_193 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_429 ,
unsigned int V_733 )
{
struct V_730 V_108 ;
V_108 . V_435 = F_32 ( F_65 ( V_731 ) | V_159 |
V_160 | F_188 ( V_429 ) ) ;
V_108 . V_732 = F_32 ( V_734 | F_68 ( V_108 ) ) ;
V_108 . V_735 = F_105 ( V_733 ) ;
return F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , NULL ) ;
}
int F_194 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_421 ,
unsigned int V_655 , unsigned int V_736 , unsigned int V_737 ,
unsigned int V_738 , unsigned int V_739 )
{
struct V_740 V_108 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_660 = F_32 ( F_65 ( V_741 ) | V_159 |
V_160 | F_195 ( V_421 ) |
F_196 ( V_655 ) ) ;
V_108 . V_684 = F_32 ( V_742 | F_68 ( V_108 ) ) ;
V_108 . V_743 = F_32 ( F_197 ( V_736 ) ) ;
V_108 . V_737 = F_105 ( V_737 ) ;
V_108 . V_738 = F_105 ( V_738 ) ;
V_108 . V_739 = F_105 ( V_739 ) ;
return F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , NULL ) ;
}
int F_198 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_421 ,
unsigned int V_655 , unsigned int V_744 )
{
struct V_745 V_108 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_660 = F_32 ( F_65 ( V_746 ) | V_159 |
V_160 | F_199 ( V_421 ) |
F_200 ( V_655 ) ) ;
V_108 . V_684 = F_32 ( V_747 | F_68 ( V_108 ) ) ;
V_108 . V_748 = F_32 ( F_201 ( V_744 ) ) ;
return F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , NULL ) ;
}
int F_202 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_421 ,
unsigned int V_655 , unsigned int V_744 )
{
struct V_749 V_108 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_660 = F_32 ( F_65 ( V_750 ) | V_159 |
V_160 | F_203 ( V_421 ) |
F_204 ( V_655 ) ) ;
V_108 . V_684 = F_32 ( V_751 | F_68 ( V_108 ) ) ;
V_108 . V_752 = F_32 ( F_205 ( V_744 ) ) ;
return F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , NULL ) ;
}
int F_206 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_421 ,
unsigned int V_655 , unsigned int V_744 )
{
struct V_753 V_108 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_660 = F_32 ( F_65 ( V_754 ) | V_159 |
V_160 | F_207 ( V_421 ) |
F_208 ( V_655 ) ) ;
V_108 . V_684 = F_32 ( V_755 | F_68 ( V_108 ) ) ;
V_108 . V_748 = F_32 ( F_209 ( V_744 ) ) ;
return F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , NULL ) ;
}
int F_210 ( struct V_1 * V_12 , const T_2 * V_18 )
{
V_54 V_756 = * ( const V_54 * ) V_18 ;
if ( V_756 == V_158 ) {
int V_757 = 0 , V_148 = 0 ;
const struct V_147 * V_36 = ( void * ) V_18 ;
int V_758 = F_211 ( F_13 ( V_36 -> V_157 ) ) ;
int V_144 = V_12 -> V_759 [ V_758 ] ;
struct V_760 * V_761 = F_212 ( V_12 , V_144 ) ;
struct V_145 * V_146 = & V_761 -> V_762 ;
T_1 V_763 = F_13 ( V_36 -> V_24 . V_764 . V_765 ) ;
int V_151 = ( V_763 & V_766 ) != 0 ;
T_1 V_767 = F_213 ( V_763 ) ;
if ( V_763 & V_768 )
V_148 |= V_153 ;
if ( V_763 & V_769 )
V_148 |= V_155 ;
if ( V_763 & F_214 ( V_770 ) )
V_757 = V_771 ;
else if ( V_763 & F_214 ( V_772 ) )
V_757 = V_773 ;
else if ( V_763 & F_214 ( V_774 ) )
V_757 = V_775 ;
if ( V_151 != V_146 -> V_151 || V_757 != V_146 -> V_757 ||
V_148 != V_146 -> V_148 ) {
V_146 -> V_151 = V_151 ;
V_146 -> V_757 = V_757 ;
V_146 -> V_148 = V_148 ;
F_215 ( V_12 , V_144 , V_151 ) ;
}
if ( V_767 != V_761 -> V_776 ) {
V_761 -> V_776 = V_767 ;
F_216 ( V_12 , V_144 ) ;
}
}
return 0 ;
}
static void T_8 F_217 ( struct V_1 * V_1 ,
struct V_777 * V_36 )
{
T_7 V_8 ;
T_1 V_778 = F_218 ( V_1 -> V_42 ) ;
if ( V_778 ) {
F_219 ( V_1 -> V_42 , V_778 + V_779 ,
& V_8 ) ;
V_36 -> V_757 = V_8 & V_780 ;
V_36 -> V_781 = ( V_8 & V_782 ) >> 4 ;
}
}
static void T_8 F_220 ( struct V_145 * V_146 ,
unsigned int V_783 )
{
V_146 -> V_163 = V_783 ;
V_146 -> V_170 = 0 ;
V_146 -> V_757 = 0 ;
V_146 -> V_152 = V_146 -> V_148 = V_153 | V_155 ;
if ( V_146 -> V_163 & V_164 ) {
V_146 -> V_171 = V_146 -> V_163 & V_167 ;
V_146 -> V_168 = V_784 ;
V_146 -> V_152 |= V_785 ;
} else {
V_146 -> V_171 = 0 ;
V_146 -> V_168 = V_169 ;
}
}
int F_221 ( struct V_1 * V_12 )
{
if ( F_2 ( V_12 , V_422 ) != 0xffffffff )
return 0 ;
F_23 ( 500 ) ;
return F_2 ( V_12 , V_422 ) != 0xffffffff ? 0 : - V_45 ;
}
static int T_8 F_222 ( struct V_1 * V_12 )
{
int V_69 ;
T_1 V_764 ;
V_69 = F_47 ( V_12 , 1 , 1 , 0 , V_786 ) ;
if ( ! V_69 )
V_69 = F_45 ( V_12 , 3 , 0 , 1 , & V_764 ) ;
F_6 ( V_12 , V_92 , 0 ) ;
if ( V_69 )
return V_69 ;
if ( ( V_764 & 0xff ) != 0x20 )
return - V_41 ;
V_764 >>= 16 ;
if ( V_764 >= 0x14 && V_764 < 0x18 )
V_12 -> V_103 . V_137 = 1 << ( V_764 - 16 ) ;
else if ( V_764 == 0x18 )
V_12 -> V_103 . V_137 = 64 ;
else
return - V_41 ;
V_12 -> V_103 . V_104 = 1 << V_764 ;
V_12 -> V_103 . V_116 =
F_2 ( V_12 , V_787 ) & V_788 ;
return 0 ;
}
int T_8 F_223 ( struct V_1 * V_1 )
{
int V_69 ;
V_69 = F_221 ( V_1 ) ;
if ( V_69 < 0 )
return V_69 ;
F_217 ( V_1 , & V_1 -> V_103 . V_789 ) ;
V_1 -> V_103 . V_790 = F_2 ( V_1 , V_791 ) ;
V_69 = F_222 ( V_1 ) ;
if ( V_69 < 0 ) {
F_15 ( V_1 -> V_23 , L_188 , V_69 ) ;
return V_69 ;
}
V_69 = F_37 ( V_1 , & V_1 -> V_103 . V_74 ) ;
if ( V_69 < 0 )
return V_69 ;
F_120 ( V_1 -> V_103 . V_792 , V_1 -> V_103 . V_793 ) ;
V_1 -> V_103 . V_794 = 1 ;
V_1 -> V_103 . V_795 = 1 ;
return 0 ;
}
int T_8 F_224 ( struct V_1 * V_12 , int V_28 , int V_421 , int V_655 )
{
V_54 V_10 [ 6 ] ;
int V_69 , V_33 , V_796 = 0 ;
struct V_147 V_108 ;
struct V_797 V_798 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
memset ( & V_798 , 0 , sizeof( V_798 ) ) ;
F_225 (adap, i) {
unsigned int V_681 ;
struct V_760 * V_36 = F_212 ( V_12 , V_33 ) ;
while ( ( V_12 -> V_103 . V_795 & ( 1 << V_796 ) ) == 0 )
V_796 ++ ;
V_108 . V_157 = F_32 ( F_65 ( V_158 ) |
V_159 | V_625 |
F_66 ( V_796 ) ) ;
V_108 . V_161 = F_32 (
F_67 ( V_799 ) |
F_68 ( V_108 ) ) ;
V_69 = F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , & V_108 ) ;
if ( V_69 )
return V_69 ;
V_69 = F_166 ( V_12 , V_28 , V_796 , V_421 , V_655 , 1 , V_10 , & V_681 ) ;
if ( V_69 < 0 )
return V_69 ;
V_36 -> V_429 = V_69 ;
V_36 -> V_800 = V_796 ;
V_36 -> V_801 = V_796 ;
V_36 -> V_681 = V_681 ;
memcpy ( V_12 -> V_144 [ V_33 ] -> V_802 , V_10 , V_803 ) ;
memcpy ( V_12 -> V_144 [ V_33 ] -> V_804 , V_10 , V_803 ) ;
V_12 -> V_144 [ V_33 ] -> V_805 = V_796 ;
V_69 = F_13 ( V_108 . V_24 . V_764 . V_765 ) ;
V_36 -> V_806 = ( V_69 & V_807 ) ?
F_226 ( V_69 ) : - 1 ;
V_36 -> V_808 = F_227 ( V_69 ) ;
V_36 -> V_776 = V_809 ;
V_798 . V_435 = F_32 ( F_65 ( V_810 ) |
V_159 | V_625 |
F_228 ( V_36 -> V_429 ) ) ;
V_798 . V_438 = F_32 ( F_68 ( V_798 ) ) ;
V_69 = F_69 ( V_12 , V_28 , & V_798 , sizeof( V_798 ) , & V_798 ) ;
if ( V_69 )
return V_69 ;
V_36 -> V_811 = F_13 ( V_798 . V_24 . V_453 . V_812 ) ;
F_220 ( & V_36 -> V_762 , F_61 ( V_108 . V_24 . V_764 . V_813 ) ) ;
V_796 ++ ;
}
return 0 ;
}
