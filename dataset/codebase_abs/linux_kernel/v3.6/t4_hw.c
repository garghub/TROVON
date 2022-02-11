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
if ( V_173 -> V_176 )
V_173 -> V_176 ( V_1 ) ;
V_3 |= V_173 -> V_3 ;
}
V_99 &= V_3 ;
if ( V_99 )
F_6 ( V_1 , V_2 , V_99 ) ;
return V_174 ;
}
static void F_74 ( struct V_1 * V_1 )
{
static const struct V_172 V_177 [] = {
{ V_178 , L_21 , - 1 , 1 } ,
{ V_179 , L_22 , - 1 , 1 } ,
{ V_180 , L_23 , - 1 , 1 } ,
{ V_181 , L_24 , - 1 , 1 } ,
{ V_182 , L_25 , - 1 , 1 } ,
{ 0 }
} ;
static const struct V_172 V_183 [] = {
{ V_184 , L_26 , - 1 , 1 } ,
{ V_185 , L_27 , - 1 , 1 } ,
{ V_186 , L_28 , - 1 , 1 } ,
{ V_187 , L_29 , - 1 , 1 } ,
{ V_188 , L_30 , - 1 , 1 } ,
{ V_189 , L_31 , - 1 , 1 } ,
{ V_190 , L_32 , - 1 , 1 } ,
{ V_191 , L_33 , - 1 , 1 } ,
{ V_192 , L_34 , - 1 , 1 } ,
{ 0 }
} ;
static const struct V_172 V_193 [] = {
{ V_194 , L_35 , - 1 , 1 } ,
{ V_195 , L_36 , - 1 , 1 } ,
{ V_196 , L_37 , - 1 , 1 } ,
{ V_197 , L_38 , - 1 , 1 } ,
{ V_198 , L_39 , - 1 , 1 } ,
{ V_199 , L_40 , - 1 , 1 } ,
{ V_200 , L_41 , - 1 , 1 } ,
{ V_201 , L_42 , - 1 , 1 } ,
{ V_202 , L_43 , - 1 , 1 } ,
{ V_203 , L_44 , - 1 , 1 } ,
{ V_204 , L_45 , - 1 , 1 } ,
{ V_205 , L_46 , - 1 , 1 } ,
{ V_206 , L_47 , - 1 , 1 } ,
{ V_207 , L_48 , - 1 , 1 } ,
{ V_208 , L_49 , - 1 , 1 } ,
{ V_209 , L_50 , - 1 , 1 } ,
{ V_210 , L_51 , - 1 , 1 } ,
{ V_211 , L_52 , - 1 , 1 } ,
{ V_212 , L_53 , - 1 , 1 } ,
{ V_213 , L_54 , - 1 , 1 } ,
{ V_214 , L_55 , - 1 , 1 } ,
{ V_215 , L_56 , - 1 , 1 } ,
{ V_216 , L_57 , - 1 , 1 } ,
{ V_217 , L_58 , - 1 , 1 } ,
{ V_218 , L_59 , - 1 , 1 } ,
{ V_219 , L_60 , - 1 , 1 } ,
{ V_220 , L_61 , - 1 , 1 } ,
{ V_221 , L_62 , - 1 , 1 } ,
{ V_222 , L_63 , - 1 , 1 } ,
{ V_223 , L_64 , - 1 , 0 } ,
{ 0 }
} ;
int V_224 ;
V_224 = F_71 ( V_1 ,
V_225 ,
V_177 ) +
F_71 ( V_1 ,
V_226 ,
V_183 ) +
F_71 ( V_1 , V_227 , V_193 ) ;
if ( V_224 )
F_75 ( V_1 ) ;
}
static void F_76 ( struct V_1 * V_1 )
{
static const struct V_172 V_228 [] = {
{ 0x3fffffff , L_65 , - 1 , 1 } ,
{ V_229 , L_66 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_71 ( V_1 , V_230 , V_228 ) )
F_75 ( V_1 ) ;
}
static void F_77 ( struct V_1 * V_1 )
{
T_3 V_11 ;
static const struct V_172 V_231 [] = {
{ V_232 ,
L_67 , - 1 , 1 } ,
{ V_233 ,
L_68 , - 1 , 0 } ,
{ V_234 , L_69 , - 1 , 0 } ,
{ V_235 , NULL , - 1 , 0 , V_236 } ,
{ V_237 , NULL , - 1 , 0 , V_236 } ,
{ V_238 , NULL , - 1 , 0 , V_239 } ,
{ V_240 | V_241 ,
L_70 , - 1 , 0 } ,
{ V_242 , L_71 , - 1 ,
0 } ,
{ V_243 , L_72 , - 1 ,
0 } ,
{ V_244 , L_73 , - 1 ,
0 } ,
{ V_245 , L_74 , - 1 ,
0 } ,
{ V_246 ,
L_75 , - 1 , 0 } ,
{ V_247 ,
L_76 , - 1 , 0 } ,
{ V_248 , L_77 , - 1 , 0 } ,
{ V_249 , L_78 , - 1 , 0 } ,
{ 0 }
} ;
V_11 = ( T_3 ) F_2 ( V_1 , V_250 ) |
( ( T_3 ) F_2 ( V_1 , V_251 ) << 32 ) ;
if ( V_11 ) {
F_12 ( V_1 -> V_23 , L_79 ,
( unsigned long long ) V_11 ) ;
F_6 ( V_1 , V_250 , V_11 ) ;
F_6 ( V_1 , V_251 , V_11 >> 32 ) ;
}
if ( F_71 ( V_1 , V_252 , V_231 ) ||
V_11 != 0 )
F_75 ( V_1 ) ;
}
static void F_78 ( struct V_1 * V_1 )
{
static const struct V_172 V_253 [] = {
{ V_254 , L_80 , - 1 , 1 } ,
{ V_255 , L_81 , - 1 , 1 } ,
{ V_256 , L_82 , - 1 , 1 } ,
{ V_257 , L_83 , - 1 , 1 } ,
{ V_258 , L_84 , - 1 , 1 } ,
{ V_259 , L_85 , - 1 , 1 } ,
{ V_260 , L_86 , - 1 , 1 } ,
{ 0 }
} ;
static const struct V_172 V_261 [] = {
{ V_262 , L_87 , - 1 , 1 } ,
{ V_263 , L_88 , - 1 , 1 } ,
{ V_264 , L_89 , - 1 , 1 } ,
{ V_265 , L_90 , - 1 , 1 } ,
{ V_266 , L_91 , - 1 , 1 } ,
{ V_267 , L_92 , - 1 , 1 } ,
{ V_268 , L_93 , - 1 , 1 } ,
{ V_269 , L_94 , - 1 , 1 } ,
{ V_270 , L_95 , - 1 , 1 } ,
{ V_271 , L_96 , - 1 , 1 } ,
{ V_272 , L_97 , - 1 , 1 } ,
{ V_273 , L_98 , - 1 , 1 } ,
{ V_274 , L_99 , - 1 , 1 } ,
{ V_275 , L_100 , - 1 , 1 } ,
{ V_276 , L_101 , - 1 , 1 } ,
{ V_277 , L_102 , - 1 , 1 } ,
{ V_278 , L_103 , - 1 , 1 } ,
{ V_279 , L_104 , - 1 , 1 } ,
{ V_280 , L_105 , - 1 , 1 } ,
{ V_281 , L_106 , - 1 , 1 } ,
{ V_282 , L_107 , - 1 , 1 } ,
{ V_283 , L_108 , - 1 , 1 } ,
{ V_284 , L_109 , - 1 , 1 } ,
{ V_285 , L_110 , - 1 , 1 } ,
{ V_286 , L_111 , - 1 , 1 } ,
{ V_287 , L_112 , - 1 , 1 } ,
{ V_288 , L_113 , - 1 , 1 } ,
{ V_289 , L_114 , - 1 , 1 } ,
{ 0 }
} ;
int V_224 ;
V_224 = F_71 ( V_1 , V_290 ,
V_253 ) +
F_71 ( V_1 , V_291 ,
V_261 ) ;
if ( V_224 )
F_75 ( V_1 ) ;
}
static void F_79 ( struct V_1 * V_1 )
{
static const struct V_172 V_292 [] = {
{ 0x1800000 , L_115 , - 1 , 1 } ,
{ 0x7fffff , L_116 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_71 ( V_1 , V_293 , V_292 ) )
F_75 ( V_1 ) ;
}
static void F_80 ( struct V_1 * V_1 )
{
static const struct V_172 V_294 [] = {
{ V_295 , L_117 , - 1 ,
0 } ,
{ V_296 , L_118 , - 1 ,
0 } ,
{ V_297 , L_119 , - 1 ,
0 } ,
{ V_298 , L_120 , - 1 ,
0 } ,
{ 0xfffffff , L_121 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_71 ( V_1 , V_299 , V_294 ) )
F_75 ( V_1 ) ;
}
static void F_81 ( struct V_1 * V_1 )
{
static const struct V_172 V_300 [] = {
{ V_301 , L_122 , - 1 , 1 } ,
{ V_302 , L_123 , - 1 , 1 } ,
{ V_303 , L_124 , - 1 , 1 } ,
{ V_304 , L_125 , - 1 , 1 } ,
{ V_305 , L_126 , - 1 , 1 } ,
{ V_306 , L_127 , - 1 , 1 } ,
{ V_307 , L_128 , - 1 , 1 } ,
{ V_308 , L_129 , - 1 , 1 } ,
{ V_309 , L_130 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_71 ( V_1 , V_310 , V_300 ) )
F_75 ( V_1 ) ;
}
static void F_82 ( struct V_1 * V_1 )
{
static const struct V_172 V_311 [] = {
{ V_312 , L_131 , - 1 , 1 } ,
{ V_313 , L_132 , - 1 , 1 } ,
{ V_314 , L_133 , - 1 , 1 } ,
{ V_307 , L_134 , - 1 , 1 } ,
{ V_315 , L_135 , - 1 , 1 } ,
{ V_316 , L_136 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_71 ( V_1 , V_317 , V_311 ) )
F_75 ( V_1 ) ;
}
static void F_83 ( struct V_1 * V_1 )
{
static const struct V_172 V_318 [] = {
{ V_319 , L_137 , - 1 , 1 } ,
{ V_320 , L_138 , - 1 , 1 } ,
{ V_321 , L_139 , - 1 , 1 } ,
{ V_322 , L_140 , - 1 , 1 } ,
{ V_323 , L_141 , - 1 , 1 } ,
{ V_324 , L_142 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_71 ( V_1 , V_325 , V_318 ) )
F_75 ( V_1 ) ;
}
static void F_84 ( struct V_1 * V_12 )
{
static const struct V_172 V_326 [] = {
{ V_327 , L_143 , - 1 , 0 } ,
{ V_328 , L_144 , - 1 , 0 } ,
{ V_329 , L_145 , - 1 , 1 } ,
{ V_330 , L_146 , - 1 , 1 } ,
{ V_331 , L_147 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_71 ( V_12 , V_332 , V_326 ) )
F_75 ( V_12 ) ;
}
static void F_85 ( struct V_1 * V_1 )
{
static const struct V_172 V_333 [] = {
{ 0xffffff , L_148 , - 1 , 1 } ,
{ 0 }
} ;
static const struct V_172 V_334 [] = {
{ V_335 , L_149 , - 1 , 1 } ,
{ V_336 , L_150 , - 1 , 1 } ,
{ V_337 , L_151 , - 1 , 1 } ,
{ V_338 , L_152 , - 1 , 1 } ,
{ V_339 , L_153 , - 1 , 1 } ,
{ V_340 , L_154 , - 1 , 1 } ,
{ V_341 , L_155 , - 1 , 1 } ,
{ 0 }
} ;
static const struct V_172 V_342 [] = {
{ V_343 , L_156 , - 1 , 1 } ,
{ V_344 , L_157 , - 1 , 1 } ,
{ V_345 , L_158 , - 1 , 1 } ,
{ 0 }
} ;
static const struct V_172 V_346 [] = {
{ 0x1fffff , L_159 , - 1 , 1 } ,
{ 0 }
} ;
static const struct V_172 V_347 [] = {
{ 0xfffff , L_160 , - 1 , 1 } ,
{ 0 }
} ;
static const struct V_172 V_348 [] = {
{ 0xffffff , L_161 , - 1 , 1 } ,
{ 0 }
} ;
static const struct V_172 V_349 [] = {
{ V_350 , L_162 , - 1 , 1 } ,
{ V_351 , L_163 , - 1 , 1 } ,
{ V_352 , L_164 , - 1 , 1 } ,
{ 0 }
} ;
int V_224 ;
V_224 = F_71 ( V_1 , V_353 ,
V_333 ) +
F_71 ( V_1 , V_354 ,
V_334 ) +
F_71 ( V_1 , V_355 ,
V_342 ) +
F_71 ( V_1 , V_356 ,
V_346 ) +
F_71 ( V_1 , V_357 ,
V_347 ) +
F_71 ( V_1 , V_358 ,
V_348 ) +
F_71 ( V_1 , V_359 ,
V_349 ) ;
F_6 ( V_1 , V_360 , V_361 | V_362 |
V_363 | V_364 | V_365 ) ;
F_2 ( V_1 , V_360 ) ;
if ( V_224 )
F_75 ( V_1 ) ;
}
static void F_86 ( struct V_1 * V_1 , int V_62 )
{
static const char T_6 [ 3 ] [ 5 ] = { L_165 , L_166 , L_167 } ;
unsigned int V_10 , V_366 , V_11 ;
if ( V_62 <= V_367 ) {
V_10 = F_87 ( V_368 , V_62 ) ;
V_366 = F_87 ( V_369 , V_62 ) ;
} else {
V_10 = V_370 ;
V_366 = V_371 ;
}
V_11 = F_2 ( V_1 , V_10 ) & V_372 ;
if ( V_11 & V_373 )
F_12 ( V_1 -> V_23 , L_168 ,
T_6 [ V_62 ] ) ;
if ( V_11 & V_374 ) {
T_1 V_375 = F_88 ( F_2 ( V_1 , V_366 ) ) ;
F_6 ( V_1 , V_366 , V_376 ) ;
if ( F_72 () )
F_73 ( V_1 -> V_23 ,
L_169 ,
V_375 , T_6 [ V_62 ] , V_375 > 1 ? L_170 : L_171 ) ;
}
if ( V_11 & V_377 )
F_12 ( V_1 -> V_23 ,
L_172 , T_6 [ V_62 ] ) ;
F_6 ( V_1 , V_10 , V_11 ) ;
if ( V_11 & ( V_373 | V_377 ) )
F_75 ( V_1 ) ;
}
static void F_89 ( struct V_1 * V_12 )
{
T_1 V_11 , V_99 = F_2 ( V_12 , V_378 ) ;
if ( V_99 & V_379 )
F_12 ( V_12 -> V_23 ,
L_173 ,
F_2 ( V_12 , V_380 ) ) ;
if ( V_99 & V_381 ) {
V_11 = F_2 ( V_12 , V_382 ) ;
F_12 ( V_12 -> V_23 , L_174
L_175 ,
F_90 ( V_11 ) ,
F_91 ( V_11 ) << 4 ) ;
}
F_6 ( V_12 , V_378 , V_99 ) ;
F_75 ( V_12 ) ;
}
static void F_92 ( struct V_1 * V_12 )
{
static const struct V_172 V_383 [] = {
{ V_384 , L_176 , - 1 , 1 } ,
{ V_385 , L_177 , - 1 , 1 } ,
{ V_386 , L_178 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_71 ( V_12 , V_387 , V_383 ) )
F_75 ( V_12 ) ;
}
static void F_93 ( struct V_1 * V_12 )
{
static const struct V_172 V_388 [] = {
{ V_389 , L_179 , - 1 , 1 } ,
{ V_390 , L_180 , - 1 , 1 } ,
{ V_391 , L_181 , - 1 , 1 } ,
{ V_392 , L_182 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_71 ( V_12 , V_393 , V_388 ) )
F_75 ( V_12 ) ;
}
static void F_94 ( struct V_1 * V_12 , int V_144 )
{
T_1 V_11 = F_2 ( V_12 , F_95 ( V_144 , V_394 ) ) ;
V_11 &= V_391 | V_392 ;
if ( ! V_11 )
return;
if ( V_11 & V_391 )
F_12 ( V_12 -> V_23 , L_183 ,
V_144 ) ;
if ( V_11 & V_392 )
F_12 ( V_12 -> V_23 , L_184 ,
V_144 ) ;
F_6 ( V_12 , F_95 ( V_144 , V_394 ) , V_11 ) ;
F_75 ( V_12 ) ;
}
static void F_96 ( struct V_1 * V_12 )
{
static const struct V_172 V_395 [] = {
{ V_396 , L_185 , - 1 , 1 } ,
{ V_397 , L_186 , - 1 , 1 } ,
{ 0 }
} ;
if ( F_71 ( V_12 , V_398 , V_395 ) )
F_75 ( V_12 ) ;
}
int F_97 ( struct V_1 * V_1 )
{
T_1 V_399 = F_2 ( V_1 , V_400 ) ;
if ( ! ( V_399 & V_401 ) )
return 0 ;
if ( V_399 & V_402 )
F_78 ( V_1 ) ;
if ( V_399 & V_403 )
F_85 ( V_1 ) ;
if ( V_399 & V_404 )
F_93 ( V_1 ) ;
if ( V_399 & V_405 )
F_96 ( V_1 ) ;
if ( V_399 & V_406 )
F_92 ( V_1 ) ;
if ( V_399 & V_407 )
F_94 ( V_1 , 0 ) ;
if ( V_399 & V_408 )
F_94 ( V_1 , 1 ) ;
if ( V_399 & V_409 )
F_94 ( V_1 , 2 ) ;
if ( V_399 & V_410 )
F_94 ( V_1 , 3 ) ;
if ( V_399 & V_411 )
F_74 ( V_1 ) ;
if ( V_399 & V_412 )
F_86 ( V_1 , V_413 ) ;
if ( V_399 & V_414 )
F_86 ( V_1 , V_415 ) ;
if ( V_399 & V_416 )
F_86 ( V_1 , V_367 ) ;
if ( V_399 & V_417 )
F_84 ( V_1 ) ;
if ( V_399 & V_418 )
F_76 ( V_1 ) ;
if ( V_399 & V_419 )
F_89 ( V_1 ) ;
if ( V_399 & V_420 )
F_81 ( V_1 ) ;
if ( V_399 & V_421 )
F_82 ( V_1 ) ;
if ( V_399 & V_422 )
F_79 ( V_1 ) ;
if ( V_399 & V_423 )
F_83 ( V_1 ) ;
if ( V_399 & V_424 )
F_77 ( V_1 ) ;
if ( V_399 & V_425 )
F_80 ( V_1 ) ;
F_6 ( V_1 , V_400 , V_399 & V_401 ) ;
( void ) F_2 ( V_1 , V_400 ) ;
return 1 ;
}
void F_98 ( struct V_1 * V_1 )
{
T_1 V_426 = F_99 ( F_2 ( V_1 , V_427 ) ) ;
F_6 ( V_1 , V_428 , V_232 |
V_233 | V_234 |
V_429 | V_240 |
V_241 | V_242 |
V_243 | V_244 |
V_245 | V_246 |
V_247 | V_248 |
V_237 | V_235 |
V_249 ) ;
F_6 ( V_1 , F_100 ( V_430 ) , V_431 ) ;
F_5 ( V_1 , V_432 , 0 , 1 << V_426 ) ;
}
void F_101 ( struct V_1 * V_1 )
{
T_1 V_426 = F_99 ( F_2 ( V_1 , V_427 ) ) ;
F_6 ( V_1 , F_100 ( V_430 ) , 0 ) ;
F_5 ( V_1 , V_432 , 1 << V_426 , 0 ) ;
}
static int F_102 ( const V_54 * V_10 )
{
T_1 V_433 = ( ( T_1 ) V_10 [ 0 ] << 16 ) | ( ( T_1 ) V_10 [ 1 ] << 8 ) | V_10 [ 2 ] ;
T_1 V_434 = ( ( T_1 ) V_10 [ 3 ] << 16 ) | ( ( T_1 ) V_10 [ 4 ] << 8 ) | V_10 [ 5 ] ;
V_433 ^= V_434 ;
V_433 ^= ( V_433 >> 12 ) ;
V_433 ^= ( V_433 >> 6 ) ;
return V_433 & 0x3f ;
}
int F_103 ( struct V_1 * V_1 , int V_28 , unsigned int V_435 ,
int V_130 , int V_106 , const T_7 * V_436 , unsigned int V_437 )
{
int V_69 ;
const T_7 * V_438 = V_436 ;
const T_7 * V_439 = V_436 + V_437 ;
struct V_440 V_29 ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
V_29 . V_441 = F_32 ( F_65 ( V_442 ) |
V_159 | V_443 |
F_104 ( V_435 ) ) ;
V_29 . V_444 = F_32 ( F_68 ( V_29 ) ) ;
while ( V_106 > 0 ) {
int V_445 = F_44 ( V_106 , 32 ) ;
T_4 * V_446 = & V_29 . V_447 ;
V_29 . V_448 = F_105 ( V_445 ) ;
V_29 . V_449 = F_105 ( V_130 ) ;
V_130 += V_445 ;
V_106 -= V_445 ;
while ( V_445 > 0 ) {
unsigned int V_11 ;
V_11 = F_106 ( * V_438 ) ;
if ( ++ V_438 >= V_439 )
V_438 = V_436 ;
V_11 |= F_107 ( * V_438 ) ;
if ( ++ V_438 >= V_439 )
V_438 = V_436 ;
V_11 |= F_108 ( * V_438 ) ;
if ( ++ V_438 >= V_439 )
V_438 = V_436 ;
* V_446 ++ = F_32 ( V_11 ) ;
V_445 -= 3 ;
}
V_69 = F_69 ( V_1 , V_28 , & V_29 , sizeof( V_29 ) , NULL ) ;
if ( V_69 )
return V_69 ;
}
return 0 ;
}
int F_109 ( struct V_1 * V_1 , int V_28 , unsigned int V_450 ,
unsigned int V_451 )
{
struct V_452 V_108 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_453 = F_32 ( F_65 ( V_454 ) |
V_159 | V_443 ) ;
V_108 . V_444 = F_32 ( F_68 ( V_108 ) ) ;
if ( V_450 == V_455 ) {
V_108 . V_24 . V_456 . V_457 = F_32 ( F_110 ( V_450 ) ) ;
} else if ( V_450 == V_458 ) {
V_108 . V_24 . V_459 . V_457 =
F_32 ( F_110 ( V_450 ) ) ;
V_108 . V_24 . V_459 . V_460 = F_32 ( V_451 ) ;
} else
return - V_41 ;
return F_69 ( V_1 , V_28 , & V_108 , sizeof( V_108 ) , NULL ) ;
}
void F_111 ( struct V_1 * V_12 , struct V_461 * V_462 ,
struct V_461 * V_463 )
{
T_1 V_8 [ V_464 - V_465 + 1 ] ;
#define F_112 ( V_26 ) ((TP_MIB_TCP_##x) - TP_MIB_TCP_OUT_RST)
#define F_113 ( V_26 ) val[STAT_IDX(x)]
#define F_114 ( V_26 ) (((u64)STAT(x##_HI) << 32) | STAT(x##_LO))
if ( V_462 ) {
F_7 ( V_12 , V_466 , V_467 , V_8 ,
F_22 ( V_8 ) , V_465 ) ;
V_462 -> V_468 = F_113 ( V_469 ) ;
V_462 -> V_470 = F_114 ( V_471 ) ;
V_462 -> V_472 = F_114 ( V_473 ) ;
V_462 -> V_474 = F_114 ( V_475 ) ;
}
if ( V_463 ) {
F_7 ( V_12 , V_466 , V_467 , V_8 ,
F_22 ( V_8 ) , V_476 ) ;
V_463 -> V_468 = F_113 ( V_469 ) ;
V_463 -> V_470 = F_114 ( V_471 ) ;
V_463 -> V_472 = F_114 ( V_473 ) ;
V_463 -> V_474 = F_114 ( V_475 ) ;
}
#undef F_114
#undef F_113
#undef F_112
}
void F_115 ( struct V_1 * V_12 , T_7 * V_477 , V_54 * V_478 )
{
T_1 V_11 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_479 ; ++ V_33 ) {
F_6 ( V_12 , V_480 ,
F_116 ( 0xff ) | F_117 ( V_33 ) ) ;
V_11 = F_2 ( V_12 , V_480 ) ;
V_477 [ V_33 ] = F_118 ( V_11 ) ;
if ( V_478 )
V_478 [ V_33 ] = F_119 ( V_11 ) ;
}
}
static void T_8 F_120 ( unsigned short * V_433 , unsigned short * V_434 )
{
V_433 [ 0 ] = V_433 [ 1 ] = V_433 [ 2 ] = V_433 [ 3 ] = V_433 [ 4 ] = V_433 [ 5 ] = V_433 [ 6 ] = V_433 [ 7 ] = V_433 [ 8 ] = 1 ;
V_433 [ 9 ] = 2 ;
V_433 [ 10 ] = 3 ;
V_433 [ 11 ] = 4 ;
V_433 [ 12 ] = 5 ;
V_433 [ 13 ] = 6 ;
V_433 [ 14 ] = 7 ;
V_433 [ 15 ] = 8 ;
V_433 [ 16 ] = 9 ;
V_433 [ 17 ] = 10 ;
V_433 [ 18 ] = 14 ;
V_433 [ 19 ] = 17 ;
V_433 [ 20 ] = 21 ;
V_433 [ 21 ] = 25 ;
V_433 [ 22 ] = 30 ;
V_433 [ 23 ] = 35 ;
V_433 [ 24 ] = 45 ;
V_433 [ 25 ] = 60 ;
V_433 [ 26 ] = 80 ;
V_433 [ 27 ] = 100 ;
V_433 [ 28 ] = 200 ;
V_433 [ 29 ] = 300 ;
V_433 [ 30 ] = 400 ;
V_433 [ 31 ] = 500 ;
V_434 [ 0 ] = V_434 [ 1 ] = V_434 [ 2 ] = V_434 [ 3 ] = V_434 [ 4 ] = V_434 [ 5 ] = V_434 [ 6 ] = V_434 [ 7 ] = V_434 [ 8 ] = 0 ;
V_434 [ 9 ] = V_434 [ 10 ] = 1 ;
V_434 [ 11 ] = V_434 [ 12 ] = 2 ;
V_434 [ 13 ] = V_434 [ 14 ] = V_434 [ 15 ] = V_434 [ 16 ] = 3 ;
V_434 [ 17 ] = V_434 [ 18 ] = V_434 [ 19 ] = V_434 [ 20 ] = V_434 [ 21 ] = 4 ;
V_434 [ 22 ] = V_434 [ 23 ] = V_434 [ 24 ] = V_434 [ 25 ] = V_434 [ 26 ] = V_434 [ 27 ] = 5 ;
V_434 [ 28 ] = V_434 [ 29 ] = 6 ;
V_434 [ 30 ] = V_434 [ 31 ] = 7 ;
}
void F_121 ( struct V_1 * V_12 , const unsigned short * V_477 ,
const unsigned short * V_481 , const unsigned short * V_482 )
{
static const unsigned int V_483 [ V_484 ] = {
2 , 6 , 10 , 14 , 20 , 28 , 40 , 56 , 80 , 112 , 160 , 224 , 320 , 448 , 640 ,
896 , 1281 , 1792 , 2560 , 3584 , 5120 , 7168 , 10240 , 14336 , 20480 ,
28672 , 40960 , 57344 , 81920 , 114688 , 163840 , 229376
} ;
unsigned int V_33 , V_485 ;
for ( V_33 = 0 ; V_33 < V_479 ; ++ V_33 ) {
unsigned int V_486 = V_477 [ V_33 ] ;
unsigned int V_487 = F_122 ( V_486 ) ;
if ( ! ( V_486 & ( ( 1 << V_487 ) >> 2 ) ) )
V_487 -- ;
F_6 ( V_12 , V_480 , F_116 ( V_33 ) |
F_123 ( V_487 ) | F_117 ( V_486 ) ) ;
for ( V_485 = 0 ; V_485 < V_484 ; ++ V_485 ) {
unsigned int V_488 ;
V_488 = F_124 ( ( ( V_486 - 40 ) * V_481 [ V_485 ] ) / V_483 [ V_485 ] ,
V_489 ) ;
F_6 ( V_12 , V_490 , ( V_33 << 21 ) |
( V_485 << 16 ) | ( V_482 [ V_485 ] << 13 ) | V_488 ) ;
}
}
}
static unsigned int F_125 ( struct V_1 * V_12 , int V_62 )
{
T_1 V_106 = F_126 ( F_2 ( V_12 , V_491 ) ) ;
if ( V_106 == 0 )
return V_62 == 0 ? 0xf : 0 ;
if ( V_106 == 1 )
return V_62 < 2 ? ( 3 << ( 2 * V_62 ) ) : 0 ;
return 1 << V_62 ;
}
void F_127 ( struct V_1 * V_12 , int V_62 , struct V_492 * V_36 )
{
T_1 V_493 = F_125 ( V_12 , V_62 ) ;
#define F_128 ( T_6 ) \
t4_read_reg64(adap, PORT_REG(idx, MPS_PORT_STAT_##name##_L))
#define F_129 ( T_6 ) t4_read_reg64(adap, MPS_STAT_##name##_L)
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
V_36 -> V_588 = F_128 ( V_589 ) ;
V_36 -> V_590 = F_128 ( V_591 ) ;
V_36 -> V_592 = F_128 ( V_593 ) ;
V_36 -> V_594 = ( V_493 & 1 ) ? F_129 ( V_595 ) : 0 ;
V_36 -> V_596 = ( V_493 & 2 ) ? F_129 ( V_597 ) : 0 ;
V_36 -> V_598 = ( V_493 & 4 ) ? F_129 ( V_599 ) : 0 ;
V_36 -> V_600 = ( V_493 & 8 ) ? F_129 ( V_601 ) : 0 ;
V_36 -> V_602 = ( V_493 & 1 ) ? F_129 ( V_603 ) : 0 ;
V_36 -> V_604 = ( V_493 & 2 ) ? F_129 ( V_605 ) : 0 ;
V_36 -> V_606 = ( V_493 & 4 ) ? F_129 ( V_607 ) : 0 ;
V_36 -> V_608 = ( V_493 & 8 ) ? F_129 ( V_609 ) : 0 ;
#undef F_128
#undef F_129
}
void F_130 ( struct V_1 * V_12 , unsigned int V_144 ,
const V_54 * V_10 )
{
if ( V_10 ) {
F_6 ( V_12 , F_95 ( V_144 , V_610 ) ,
( V_10 [ 2 ] << 24 ) | ( V_10 [ 3 ] << 16 ) |
( V_10 [ 4 ] << 8 ) | V_10 [ 5 ] ) ;
F_6 ( V_12 , F_95 ( V_144 , V_611 ) ,
( V_10 [ 0 ] << 8 ) | V_10 [ 1 ] ) ;
}
F_5 ( V_12 , F_95 ( V_144 , V_612 ) , V_613 ,
V_10 ? V_613 : 0 ) ;
}
int F_131 ( struct V_1 * V_12 , unsigned int V_144 , unsigned int V_614 ,
T_3 V_615 , T_3 V_616 , unsigned int V_617 , bool V_68 )
{
int V_33 ;
if ( ! V_68 ) {
F_5 ( V_12 , F_95 ( V_144 , V_612 ) ,
V_618 , 0 ) ;
return 0 ;
}
if ( V_614 > 0xff )
return - V_41 ;
#define F_132 ( T_6 ) PORT_REG(port, XGMAC_PORT_EPIO_##name)
F_6 ( V_12 , F_132 ( V_619 ) , V_615 >> 32 ) ;
F_6 ( V_12 , F_132 ( V_620 ) , V_616 ) ;
F_6 ( V_12 , F_132 ( V_621 ) , V_616 >> 32 ) ;
for ( V_33 = 0 ; V_33 < V_622 ; V_33 ++ , V_614 >>= 1 ) {
if ( ! ( V_614 & 1 ) )
continue;
F_6 ( V_12 , F_132 ( V_623 ) , V_615 ) ;
F_6 ( V_12 , F_132 ( V_624 ) , F_133 ( V_33 ) | V_625 ) ;
F_2 ( V_12 , F_132 ( V_624 ) ) ;
if ( F_2 ( V_12 , F_132 ( V_624 ) ) & V_93 )
return - V_49 ;
F_6 ( V_12 , F_132 ( V_623 ) , V_617 ) ;
F_6 ( V_12 , F_132 ( V_624 ) , F_133 ( V_33 + 32 ) | V_625 ) ;
F_2 ( V_12 , F_132 ( V_624 ) ) ;
if ( F_2 ( V_12 , F_132 ( V_624 ) ) & V_93 )
return - V_49 ;
}
#undef F_132
F_5 ( V_12 , F_95 ( V_144 , V_612 ) , 0 , V_618 ) ;
return 0 ;
}
int F_134 ( struct V_1 * V_12 , unsigned int V_28 ,
T_1 V_10 , T_1 V_8 )
{
struct V_626 V_108 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_627 = F_32 ( F_135 ( V_628 ) | V_629 |
V_630 |
F_136 ( V_631 ) ) ;
V_108 . V_632 = F_32 ( F_68 ( V_108 ) ) ;
V_108 . V_24 . V_633 . V_10 = F_32 ( V_10 ) ;
V_108 . V_24 . V_633 . V_8 = F_32 ( V_8 ) ;
return F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , NULL ) ;
}
int F_137 ( struct V_1 * V_12 , T_1 V_10 , T_4 * V_55 , int V_634 )
{
int V_33 ;
int V_635 ;
V_635 = V_10 & 15 ;
if ( ( V_10 & 3 ) || ( V_634 + V_635 ) > V_636 )
return - V_41 ;
F_6 ( V_12 , V_637 , V_10 & ~ 15 ) ;
F_2 ( V_12 , V_637 ) ;
for ( V_33 = 0 ; V_33 < V_634 ; V_33 += 4 )
* V_55 ++ = F_2 ( V_12 , ( V_638 + V_635 + V_33 ) ) ;
return 0 ;
}
int F_138 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_639 ,
unsigned int V_640 , unsigned int V_2 , T_7 * V_7 )
{
int V_69 ;
struct V_626 V_108 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_627 = F_32 ( F_65 ( V_628 ) | V_159 |
V_641 | F_139 ( V_642 ) ) ;
V_108 . V_632 = F_32 ( F_68 ( V_108 ) ) ;
V_108 . V_24 . V_643 . V_644 = F_105 ( F_140 ( V_639 ) |
F_141 ( V_640 ) ) ;
V_108 . V_24 . V_643 . V_645 = F_105 ( V_2 ) ;
V_69 = F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , & V_108 ) ;
if ( V_69 == 0 )
* V_7 = F_61 ( V_108 . V_24 . V_643 . V_646 ) ;
return V_69 ;
}
int F_142 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_639 ,
unsigned int V_640 , unsigned int V_2 , T_7 V_8 )
{
struct V_626 V_108 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_627 = F_32 ( F_65 ( V_628 ) | V_159 |
V_443 | F_139 ( V_642 ) ) ;
V_108 . V_632 = F_32 ( F_68 ( V_108 ) ) ;
V_108 . V_24 . V_643 . V_644 = F_105 ( F_140 ( V_639 ) |
F_141 ( V_640 ) ) ;
V_108 . V_24 . V_643 . V_645 = F_105 ( V_2 ) ;
V_108 . V_24 . V_643 . V_646 = F_105 ( V_8 ) ;
return F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , NULL ) ;
}
int F_143 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_647 ,
enum V_648 V_649 , enum V_650 * V_651 )
{
int V_69 ;
struct V_652 V_108 ;
F_144 ( V_108 , V_653 , V_654 ) ;
V_108 . V_655 = F_32 (
F_145 ( V_649 == V_656 ) |
F_146 ( V_649 == V_657 ) |
F_147 ( V_649 == V_657 ? V_28 : 0xff ) |
F_148 ( V_647 ) ) ;
V_69 = F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , & V_108 ) ;
if ( V_69 == 0 && V_651 ) {
T_1 V_11 = F_13 ( V_108 . V_655 ) ;
if ( V_11 & V_658 )
* V_651 = V_659 ;
else if ( V_11 & V_660 )
* V_651 = V_661 ;
else
* V_651 = V_662 ;
}
return V_69 ;
}
int F_149 ( struct V_1 * V_12 , unsigned int V_28 )
{
struct V_663 V_108 ;
F_144 ( V_108 , V_664 , V_654 ) ;
return F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , NULL ) ;
}
int F_150 ( struct V_1 * V_12 , unsigned int V_28 )
{
struct V_665 V_108 ;
F_144 ( V_108 , V_666 , V_654 ) ;
return F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , NULL ) ;
}
int F_151 ( struct V_1 * V_12 , unsigned int V_28 , int V_667 )
{
struct V_668 V_108 ;
F_144 ( V_108 , V_669 , V_654 ) ;
V_108 . V_8 = F_32 ( V_667 ) ;
return F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , NULL ) ;
}
int F_152 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_426 ,
unsigned int V_670 , unsigned int V_671 , const T_1 * V_103 ,
T_1 * V_8 )
{
int V_33 , V_69 ;
struct V_672 V_108 ;
T_4 * V_36 = & V_108 . V_673 [ 0 ] . V_674 ;
if ( V_671 > 7 )
return - V_41 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_675 = F_32 ( F_65 ( V_676 ) | V_159 |
V_641 | F_153 ( V_426 ) |
F_154 ( V_670 ) ) ;
V_108 . V_444 = F_32 ( F_68 ( V_108 ) ) ;
for ( V_33 = 0 ; V_33 < V_671 ; V_33 ++ , V_36 += 2 )
* V_36 = F_32 ( * V_103 ++ ) ;
V_69 = F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , & V_108 ) ;
if ( V_69 == 0 )
for ( V_33 = 0 , V_36 = & V_108 . V_673 [ 0 ] . V_8 ; V_33 < V_671 ; V_33 ++ , V_36 += 2 )
* V_8 ++ = F_13 ( * V_36 ) ;
return V_69 ;
}
int F_155 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_426 ,
unsigned int V_670 , unsigned int V_671 , const T_1 * V_103 ,
const T_1 * V_8 )
{
struct V_672 V_108 ;
T_4 * V_36 = & V_108 . V_673 [ 0 ] . V_674 ;
if ( V_671 > 7 )
return - V_41 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_675 = F_32 ( F_65 ( V_676 ) | V_159 |
V_443 | F_153 ( V_426 ) |
F_154 ( V_670 ) ) ;
V_108 . V_444 = F_32 ( F_68 ( V_108 ) ) ;
while ( V_671 -- ) {
* V_36 ++ = F_32 ( * V_103 ++ ) ;
* V_36 ++ = F_32 ( * V_8 ++ ) ;
}
return F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , NULL ) ;
}
int F_156 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_426 ,
unsigned int V_670 , unsigned int V_677 , unsigned int V_678 ,
unsigned int V_679 , unsigned int V_680 , unsigned int V_681 ,
unsigned int V_682 , unsigned int V_683 , unsigned int V_684 ,
unsigned int V_685 , unsigned int V_686 , unsigned int V_687 )
{
struct V_688 V_108 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_675 = F_32 ( F_65 ( V_689 ) | V_159 |
V_443 | F_157 ( V_426 ) |
F_158 ( V_670 ) ) ;
V_108 . V_444 = F_32 ( F_68 ( V_108 ) ) ;
V_108 . V_690 = F_32 ( F_159 ( V_679 ) |
F_160 ( V_680 ) ) ;
V_108 . V_691 = F_32 ( F_161 ( V_683 ) |
F_162 ( V_684 ) |
F_163 ( V_677 ) ) ;
V_108 . V_692 = F_32 ( F_164 ( V_681 ) | F_165 ( V_682 ) |
F_166 ( V_685 ) ) ;
V_108 . V_693 = F_32 ( F_167 ( V_686 ) |
F_168 ( V_687 ) |
F_169 ( V_678 ) ) ;
return F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , NULL ) ;
}
int F_170 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_144 ,
unsigned int V_426 , unsigned int V_670 , unsigned int V_694 , V_54 * V_695 ,
unsigned int * V_696 )
{
int V_69 ;
struct V_697 V_108 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_675 = F_32 ( F_65 ( V_698 ) | V_159 |
V_443 | V_160 |
F_171 ( V_426 ) | F_172 ( V_670 ) ) ;
V_108 . V_699 = F_32 ( V_700 | F_68 ( V_108 ) ) ;
V_108 . V_701 = F_173 ( V_144 ) ;
V_108 . V_694 = V_694 - 1 ;
V_69 = F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , & V_108 ) ;
if ( V_69 )
return V_69 ;
if ( V_695 ) {
memcpy ( V_695 , V_108 . V_695 , sizeof( V_108 . V_695 ) ) ;
switch ( V_694 ) {
case 5 :
memcpy ( V_695 + 24 , V_108 . V_702 , sizeof( V_108 . V_702 ) ) ;
case 4 :
memcpy ( V_695 + 18 , V_108 . V_703 , sizeof( V_108 . V_703 ) ) ;
case 3 :
memcpy ( V_695 + 12 , V_108 . V_704 , sizeof( V_108 . V_704 ) ) ;
case 2 :
memcpy ( V_695 + 6 , V_108 . V_705 , sizeof( V_108 . V_705 ) ) ;
}
}
if ( V_696 )
* V_696 = F_174 ( F_61 ( V_108 . V_706 ) ) ;
return F_175 ( F_61 ( V_108 . V_707 ) ) ;
}
int F_176 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_435 ,
int V_486 , int V_708 , int V_709 , int V_710 , int V_711 ,
bool V_31 )
{
struct V_712 V_108 ;
if ( V_486 < 0 )
V_486 = V_713 ;
if ( V_708 < 0 )
V_708 = V_714 ;
if ( V_709 < 0 )
V_709 = V_715 ;
if ( V_710 < 0 )
V_710 = V_716 ;
if ( V_711 < 0 )
V_711 = V_717 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_441 = F_32 ( F_65 ( V_718 ) | V_159 |
V_443 | F_177 ( V_435 ) ) ;
V_108 . V_444 = F_32 ( F_68 ( V_108 ) ) ;
V_108 . V_719 = F_32 ( F_178 ( V_486 ) |
F_179 ( V_708 ) |
F_180 ( V_709 ) |
F_181 ( V_710 ) |
F_182 ( V_711 ) ) ;
return F_16 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , NULL , V_31 ) ;
}
int F_183 ( struct V_1 * V_12 , unsigned int V_28 ,
unsigned int V_435 , bool free , unsigned int V_720 ,
const V_54 * * V_10 , T_7 * V_62 , T_3 * V_721 , bool V_31 )
{
int V_33 , V_69 ;
struct V_722 V_108 ;
struct V_723 * V_36 ;
if ( V_720 > 7 )
return - V_41 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_441 = F_32 ( F_65 ( V_724 ) | V_159 |
V_443 | ( free ? V_160 : 0 ) |
F_184 ( V_435 ) ) ;
V_108 . V_725 = F_32 ( F_185 ( free ) |
F_186 ( ( V_720 + 2 ) / 2 ) ) ;
for ( V_33 = 0 , V_36 = V_108 . V_24 . V_726 ; V_33 < V_720 ; V_33 ++ , V_36 ++ ) {
V_36 -> V_727 = F_105 ( V_728 |
F_187 ( V_729 ) ) ;
memcpy ( V_36 -> V_730 , V_10 [ V_33 ] , sizeof( V_36 -> V_730 ) ) ;
}
V_69 = F_16 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , & V_108 , V_31 ) ;
if ( V_69 )
return V_69 ;
for ( V_33 = 0 , V_36 = V_108 . V_24 . V_726 ; V_33 < V_720 ; V_33 ++ , V_36 ++ ) {
T_7 V_731 = F_188 ( F_61 ( V_36 -> V_727 ) ) ;
if ( V_62 )
V_62 [ V_33 ] = V_731 >= V_732 ? 0xffff : V_731 ;
if ( V_731 < V_732 )
V_69 ++ ;
else if ( V_721 )
* V_721 |= ( 1ULL << F_102 ( V_10 [ V_33 ] ) ) ;
}
return V_69 ;
}
int F_189 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_435 ,
int V_62 , const V_54 * V_10 , bool V_733 , bool V_734 )
{
int V_69 , V_450 ;
struct V_722 V_108 ;
struct V_723 * V_36 = V_108 . V_24 . V_726 ;
if ( V_62 < 0 )
V_62 = V_733 ? V_735 : V_729 ;
V_450 = V_734 ? V_736 : V_737 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_441 = F_32 ( F_65 ( V_724 ) | V_159 |
V_443 | F_184 ( V_435 ) ) ;
V_108 . V_725 = F_32 ( F_186 ( 1 ) ) ;
V_36 -> V_727 = F_105 ( V_728 |
F_190 ( V_450 ) |
F_187 ( V_62 ) ) ;
memcpy ( V_36 -> V_730 , V_10 , sizeof( V_36 -> V_730 ) ) ;
V_69 = F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , & V_108 ) ;
if ( V_69 == 0 ) {
V_69 = F_188 ( F_61 ( V_36 -> V_727 ) ) ;
if ( V_69 >= V_732 )
V_69 = - V_738 ;
}
return V_69 ;
}
int F_191 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_435 ,
bool V_739 , T_3 V_740 , bool V_31 )
{
struct V_722 V_108 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_441 = F_32 ( F_65 ( V_724 ) | V_159 |
V_443 | F_192 ( V_435 ) ) ;
V_108 . V_725 = F_32 ( V_741 |
F_193 ( V_739 ) |
F_186 ( 1 ) ) ;
V_108 . V_24 . V_721 . V_742 = F_9 ( V_740 ) ;
return F_16 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , NULL , V_31 ) ;
}
int F_194 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_435 ,
bool V_743 , bool V_744 )
{
struct V_745 V_108 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_441 = F_32 ( F_65 ( V_746 ) | V_159 |
V_160 | F_192 ( V_435 ) ) ;
V_108 . V_747 = F_32 ( F_195 ( V_743 ) |
F_196 ( V_744 ) | F_68 ( V_108 ) ) ;
return F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , NULL ) ;
}
int F_197 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_435 ,
unsigned int V_748 )
{
struct V_745 V_108 ;
V_108 . V_441 = F_32 ( F_65 ( V_746 ) | V_159 |
V_160 | F_192 ( V_435 ) ) ;
V_108 . V_747 = F_32 ( V_749 | F_68 ( V_108 ) ) ;
V_108 . V_750 = F_105 ( V_748 ) ;
return F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , NULL ) ;
}
int F_198 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_426 ,
unsigned int V_670 , unsigned int V_751 , unsigned int V_752 ,
unsigned int V_753 , unsigned int V_754 )
{
struct V_755 V_108 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_675 = F_32 ( F_65 ( V_756 ) | V_159 |
V_160 | F_199 ( V_426 ) |
F_200 ( V_670 ) ) ;
V_108 . V_699 = F_32 ( V_757 | F_68 ( V_108 ) ) ;
V_108 . V_758 = F_32 ( F_201 ( V_751 ) ) ;
V_108 . V_752 = F_105 ( V_752 ) ;
V_108 . V_753 = F_105 ( V_753 ) ;
V_108 . V_754 = F_105 ( V_754 ) ;
return F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , NULL ) ;
}
int F_202 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_426 ,
unsigned int V_670 , unsigned int V_759 )
{
struct V_760 V_108 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_675 = F_32 ( F_65 ( V_761 ) | V_159 |
V_160 | F_203 ( V_426 ) |
F_204 ( V_670 ) ) ;
V_108 . V_699 = F_32 ( V_762 | F_68 ( V_108 ) ) ;
V_108 . V_763 = F_32 ( F_205 ( V_759 ) ) ;
return F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , NULL ) ;
}
int F_206 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_426 ,
unsigned int V_670 , unsigned int V_759 )
{
struct V_764 V_108 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_675 = F_32 ( F_65 ( V_765 ) | V_159 |
V_160 | F_207 ( V_426 ) |
F_208 ( V_670 ) ) ;
V_108 . V_699 = F_32 ( V_766 | F_68 ( V_108 ) ) ;
V_108 . V_767 = F_32 ( F_209 ( V_759 ) ) ;
return F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , NULL ) ;
}
int F_210 ( struct V_1 * V_12 , unsigned int V_28 , unsigned int V_426 ,
unsigned int V_670 , unsigned int V_759 )
{
struct V_768 V_108 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_675 = F_32 ( F_65 ( V_769 ) | V_159 |
V_160 | F_211 ( V_426 ) |
F_212 ( V_670 ) ) ;
V_108 . V_699 = F_32 ( V_770 | F_68 ( V_108 ) ) ;
V_108 . V_763 = F_32 ( F_213 ( V_759 ) ) ;
return F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , NULL ) ;
}
int F_214 ( struct V_1 * V_12 , const T_2 * V_18 )
{
V_54 V_771 = * ( const V_54 * ) V_18 ;
if ( V_771 == V_158 ) {
int V_772 = 0 , V_148 = 0 ;
const struct V_147 * V_36 = ( void * ) V_18 ;
int V_773 = F_215 ( F_13 ( V_36 -> V_157 ) ) ;
int V_144 = V_12 -> V_774 [ V_773 ] ;
struct V_775 * V_776 = F_216 ( V_12 , V_144 ) ;
struct V_145 * V_146 = & V_776 -> V_777 ;
T_1 V_778 = F_13 ( V_36 -> V_24 . V_779 . V_780 ) ;
int V_151 = ( V_778 & V_781 ) != 0 ;
T_1 V_782 = F_217 ( V_778 ) ;
if ( V_778 & V_783 )
V_148 |= V_153 ;
if ( V_778 & V_784 )
V_148 |= V_155 ;
if ( V_778 & F_218 ( V_785 ) )
V_772 = V_786 ;
else if ( V_778 & F_218 ( V_787 ) )
V_772 = V_788 ;
else if ( V_778 & F_218 ( V_789 ) )
V_772 = V_790 ;
if ( V_151 != V_146 -> V_151 || V_772 != V_146 -> V_772 ||
V_148 != V_146 -> V_148 ) {
V_146 -> V_151 = V_151 ;
V_146 -> V_772 = V_772 ;
V_146 -> V_148 = V_148 ;
F_219 ( V_12 , V_144 , V_151 ) ;
}
if ( V_782 != V_776 -> V_791 ) {
V_776 -> V_791 = V_782 ;
F_220 ( V_12 , V_144 ) ;
}
}
return 0 ;
}
static void T_8 F_221 ( struct V_1 * V_1 ,
struct V_792 * V_36 )
{
T_7 V_8 ;
T_1 V_793 = F_222 ( V_1 -> V_42 ) ;
if ( V_793 ) {
F_223 ( V_1 -> V_42 , V_793 + V_794 ,
& V_8 ) ;
V_36 -> V_772 = V_8 & V_795 ;
V_36 -> V_796 = ( V_8 & V_797 ) >> 4 ;
}
}
static void T_8 F_224 ( struct V_145 * V_146 ,
unsigned int V_798 )
{
V_146 -> V_163 = V_798 ;
V_146 -> V_170 = 0 ;
V_146 -> V_772 = 0 ;
V_146 -> V_152 = V_146 -> V_148 = V_153 | V_155 ;
if ( V_146 -> V_163 & V_164 ) {
V_146 -> V_171 = V_146 -> V_163 & V_167 ;
V_146 -> V_168 = V_799 ;
V_146 -> V_152 |= V_800 ;
} else {
V_146 -> V_171 = 0 ;
V_146 -> V_168 = V_169 ;
}
}
int F_225 ( struct V_1 * V_12 )
{
if ( F_2 ( V_12 , V_427 ) != 0xffffffff )
return 0 ;
F_23 ( 500 ) ;
return F_2 ( V_12 , V_427 ) != 0xffffffff ? 0 : - V_45 ;
}
static int T_8 F_226 ( struct V_1 * V_12 )
{
int V_69 ;
T_1 V_779 ;
V_69 = F_47 ( V_12 , 1 , 1 , 0 , V_801 ) ;
if ( ! V_69 )
V_69 = F_45 ( V_12 , 3 , 0 , 1 , & V_779 ) ;
F_6 ( V_12 , V_92 , 0 ) ;
if ( V_69 )
return V_69 ;
if ( ( V_779 & 0xff ) != 0x20 )
return - V_41 ;
V_779 >>= 16 ;
if ( V_779 >= 0x14 && V_779 < 0x18 )
V_12 -> V_103 . V_137 = 1 << ( V_779 - 16 ) ;
else if ( V_779 == 0x18 )
V_12 -> V_103 . V_137 = 64 ;
else
return - V_41 ;
V_12 -> V_103 . V_104 = 1 << V_779 ;
V_12 -> V_103 . V_116 =
F_2 ( V_12 , V_802 ) & V_803 ;
return 0 ;
}
int T_8 F_227 ( struct V_1 * V_1 )
{
int V_69 ;
V_69 = F_225 ( V_1 ) ;
if ( V_69 < 0 )
return V_69 ;
F_221 ( V_1 , & V_1 -> V_103 . V_804 ) ;
V_1 -> V_103 . V_805 = F_2 ( V_1 , V_806 ) ;
V_69 = F_226 ( V_1 ) ;
if ( V_69 < 0 ) {
F_15 ( V_1 -> V_23 , L_187 , V_69 ) ;
return V_69 ;
}
V_69 = F_37 ( V_1 , & V_1 -> V_103 . V_74 ) ;
if ( V_69 < 0 )
return V_69 ;
F_120 ( V_1 -> V_103 . V_807 , V_1 -> V_103 . V_808 ) ;
V_1 -> V_103 . V_809 = 1 ;
V_1 -> V_103 . V_810 = 1 ;
return 0 ;
}
int T_8 F_228 ( struct V_1 * V_12 , int V_28 , int V_426 , int V_670 )
{
V_54 V_10 [ 6 ] ;
int V_69 , V_33 , V_811 = 0 ;
struct V_147 V_108 ;
struct V_812 V_813 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
memset ( & V_813 , 0 , sizeof( V_813 ) ) ;
F_229 (adap, i) {
unsigned int V_696 ;
struct V_775 * V_36 = F_216 ( V_12 , V_33 ) ;
while ( ( V_12 -> V_103 . V_810 & ( 1 << V_811 ) ) == 0 )
V_811 ++ ;
V_108 . V_157 = F_32 ( F_65 ( V_158 ) |
V_159 | V_641 |
F_66 ( V_811 ) ) ;
V_108 . V_161 = F_32 (
F_67 ( V_814 ) |
F_68 ( V_108 ) ) ;
V_69 = F_69 ( V_12 , V_28 , & V_108 , sizeof( V_108 ) , & V_108 ) ;
if ( V_69 )
return V_69 ;
V_69 = F_170 ( V_12 , V_28 , V_811 , V_426 , V_670 , 1 , V_10 , & V_696 ) ;
if ( V_69 < 0 )
return V_69 ;
V_36 -> V_435 = V_69 ;
V_36 -> V_815 = V_811 ;
V_36 -> V_816 = V_811 ;
V_36 -> V_696 = V_696 ;
memcpy ( V_12 -> V_144 [ V_33 ] -> V_817 , V_10 , V_818 ) ;
memcpy ( V_12 -> V_144 [ V_33 ] -> V_819 , V_10 , V_818 ) ;
V_12 -> V_144 [ V_33 ] -> V_820 = V_811 ;
V_69 = F_13 ( V_108 . V_24 . V_779 . V_780 ) ;
V_36 -> V_821 = ( V_69 & V_822 ) ?
F_230 ( V_69 ) : - 1 ;
V_36 -> V_823 = F_231 ( V_69 ) ;
V_36 -> V_791 = V_824 ;
V_813 . V_441 = F_32 ( F_65 ( V_825 ) |
V_159 | V_641 |
F_232 ( V_36 -> V_435 ) ) ;
V_813 . V_444 = F_32 ( F_68 ( V_813 ) ) ;
V_69 = F_69 ( V_12 , V_28 , & V_813 , sizeof( V_813 ) , & V_813 ) ;
if ( V_69 )
return V_69 ;
V_36 -> V_826 = F_13 ( V_813 . V_24 . V_459 . V_827 ) ;
F_224 ( & V_36 -> V_777 , F_61 ( V_108 . V_24 . V_779 . V_828 ) ) ;
V_811 ++ ;
}
return 0 ;
}
