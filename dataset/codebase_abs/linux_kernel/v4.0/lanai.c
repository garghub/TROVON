static void F_1 ( struct V_1 * V_2 ,
const unsigned long * V_3 ,
void (* F_2)( struct V_1 * , T_1 V_4 ) )
{
T_1 V_4 ;
F_3 (vci, lp, NUM_VCI)
F_2 ( V_2 , V_4 ) ;
}
static void F_4 ( struct V_5 * V_6 ,
T_2 V_7 , T_2 V_8 , struct V_9 * V_10 )
{
int V_11 ;
if ( V_7 > ( 128 * 1024 ) )
V_7 = 128 * 1024 ;
for ( V_11 = V_12 ; V_11 < V_7 ; V_11 *= 2 )
;
if ( V_8 < V_12 )
V_8 = V_12 ;
do {
V_6 -> V_13 = F_5 ( & V_10 -> V_14 ,
V_11 , & V_6 -> V_15 , V_16 ) ;
if ( V_6 -> V_13 != NULL ) {
F_6 ( ( V_6 -> V_15 & ~ 0xFFFFFF00 ) == 0 ,
L_1 ,
( unsigned long ) V_6 -> V_15 ) ;
V_6 -> V_17 = V_6 -> V_13 ;
V_6 -> V_18 = ( V_19 * )
( & ( ( unsigned char * ) V_6 -> V_13 ) [ V_11 ] ) ;
memset ( V_6 -> V_13 , 0 , V_11 ) ;
break;
}
V_11 /= 2 ;
} while ( V_11 >= V_8 );
}
static inline T_2 F_7 ( const struct V_5 * V_6 )
{
return ( ( unsigned long ) V_6 -> V_18 ) - ( ( unsigned long ) V_6 -> V_13 ) ;
}
static void F_8 ( struct V_5 * V_6 ,
struct V_9 * V_10 )
{
if ( V_6 -> V_13 != NULL ) {
F_9 ( & V_10 -> V_14 , F_7 ( V_6 ) ,
V_6 -> V_13 , V_6 -> V_15 ) ;
V_6 -> V_13 = V_6 -> V_18 = V_6 -> V_17 = NULL ;
}
}
static int F_10 ( const struct V_5 * V_6 )
{
int V_20 = F_11 ( F_7 ( V_6 ) ) + ( V_21 - 10 ) ;
if ( V_20 > 7 )
V_20 = 7 ;
return V_20 ;
}
static inline T_3 F_12 ( const struct V_1 * V_2 ,
enum V_22 V_23 )
{
return V_2 -> V_24 + V_23 ;
}
static inline V_19 F_13 ( const struct V_1 * V_2 ,
enum V_22 V_23 )
{
V_19 V_25 ;
V_25 = F_14 ( F_12 ( V_2 , V_23 ) ) ;
F_15 ( L_2 , ( unsigned int ) V_2 -> V_24 ,
( int ) V_23 , V_25 ) ;
return V_25 ;
}
static inline void F_16 ( const struct V_1 * V_2 , V_19 V_26 ,
enum V_22 V_23 )
{
F_15 ( L_3 , ( unsigned int ) V_2 -> V_24 ,
( int ) V_23 , V_26 ) ;
F_17 ( V_26 , F_12 ( V_2 , V_23 ) ) ;
}
static inline void F_18 ( const struct V_1 * V_2 )
{
F_16 ( V_2 , V_2 -> V_27 , V_28 ) ;
}
static inline void F_19 ( const struct V_1 * V_2 )
{
F_16 ( V_2 , V_2 -> V_29 , V_30 ) ;
}
static inline void F_20 ( const struct V_1 * V_2 )
{
#ifdef F_21
if ( F_22 ( ( V_2 -> V_27 & V_31 ) != 0 ) )
return;
#endif
F_19 ( V_2 ) ;
}
static inline void F_23 ( const struct V_1 * V_2 )
{
F_24 ( L_4 ) ;
F_16 ( V_2 , 0 , V_32 ) ;
F_25 ( 5 ) ;
}
static inline T_3 F_26 ( const struct V_1 * V_2 , int V_33 )
{
return V_2 -> V_24 + V_34 + V_33 ;
}
static inline V_19 F_27 ( const struct V_1 * V_2 , int V_33 )
{
return F_14 ( F_26 ( V_2 , V_33 ) ) ;
}
static inline void F_28 ( const struct V_1 * V_2 ,
V_19 V_26 , int V_33 )
{
F_17 ( V_26 , F_26 ( V_2 , V_33 ) ) ;
}
static int F_29 ( const struct V_1 * V_2 , int V_33 ,
V_19 V_35 )
{
V_19 V_36 ;
F_28 ( V_2 , V_35 , V_33 ) ;
V_36 = F_27 ( V_2 , V_33 ) ;
if ( F_30 ( V_36 == V_35 ) )
return 0 ;
F_31 (KERN_ERR DEV_LABEL
L_5 ,
lanai->number, offset,
(unsigned int) pattern, (unsigned int) readback) ;
return - V_37 ;
}
static int F_32 ( const struct V_1 * V_2 , V_19 V_35 )
{
int V_33 , V_38 = 0 ;
for ( V_33 = 0 ; V_33 < V_39 && V_38 == 0 ; V_33 += 4 )
V_38 = F_29 ( V_2 , V_33 , V_35 ) ;
return V_38 ;
}
static int F_33 ( const struct V_1 * V_2 )
{
#ifdef F_34
int V_38 ;
F_24 ( L_6 ) ;
if ( ( V_38 = F_32 ( V_2 , 0x5555 ) ) != 0 )
return V_38 ;
if ( ( V_38 = F_32 ( V_2 , 0xAAAA ) ) != 0 )
return V_38 ;
#endif
F_24 ( L_7 ) ;
return F_32 ( V_2 , 0x0000 ) ;
}
static inline T_3 F_35 ( const struct V_1 * V_2 ,
T_1 V_4 )
{
return F_26 ( V_2 , V_4 * V_40 ) ;
}
static inline V_19 F_36 ( const struct V_41 * V_42 ,
enum V_43 V_33 )
{
V_19 V_26 ;
F_6 ( V_42 -> V_44 != NULL , L_8 ) ;
V_26 = F_14 ( V_42 -> V_44 + V_33 ) ;
F_15 ( L_9 ,
V_42 -> V_4 , ( int ) V_33 , V_26 ) ;
return V_26 ;
}
static inline void F_37 ( const struct V_41 * V_42 ,
V_19 V_26 , enum V_43 V_33 )
{
F_6 ( V_42 -> V_44 != NULL , L_10 ) ;
F_6 ( ( V_26 & ~ 0xFFFF ) == 0 ,
L_11 ,
( unsigned int ) V_26 , V_42 -> V_4 , ( unsigned int ) V_33 ) ;
F_15 ( L_12 ,
V_42 -> V_4 , ( unsigned int ) V_33 , ( unsigned int ) V_26 ) ;
F_17 ( V_26 , V_42 -> V_44 + V_33 ) ;
}
static inline int F_38 ( int V_11 )
{
int V_45 = ( V_11 + 8 + 47 ) / 48 ;
return V_45 * 48 ;
}
static inline void F_39 ( struct V_46 * V_47 , struct V_48 * V_49 )
{
if ( V_47 -> V_50 != NULL )
V_47 -> V_50 ( V_47 , V_49 ) ;
else
F_40 ( V_49 ) ;
}
static void F_41 ( const struct V_41 * V_42 )
{
V_19 V_51 ;
if ( V_42 -> V_52 . V_47 -> V_53 . V_54 == V_55 ) {
T_4 V_15 = V_42 -> V_52 . V_6 . V_15 ;
F_37 ( V_42 , 0xFFFF , V_56 ) ;
F_37 ( V_42 , 0xFFFF , V_57 ) ;
F_37 ( V_42 , 0 , V_58 ) ;
F_37 ( V_42 , 0 , V_59 ) ;
F_37 ( V_42 , 0 , V_60 ) ;
F_37 ( V_42 , ( V_15 >> 16 ) & 0xFFFF , V_61 ) ;
V_51 = ( ( V_15 >> 8 ) & 0xFF ) |
F_42 ( F_10 ( & V_42 -> V_52 . V_6 ) ) |
F_43 ( V_62 ) |
F_44 ( V_63 ) ;
} else
V_51 = F_43 ( V_64 ) |
V_65 |
F_44 ( V_66 ) ;
F_37 ( V_42 , V_51 , V_67 ) ;
}
static void F_45 ( const struct V_41 * V_42 )
{
T_4 V_15 = V_42 -> V_68 . V_6 . V_15 ;
F_37 ( V_42 , 0 , V_69 ) ;
F_37 ( V_42 , 0xFFFF , V_70 ) ;
F_37 ( V_42 , 0xFFFF , V_71 ) ;
F_37 ( V_42 , 0 , V_72 ) ;
F_37 ( V_42 , 0 , V_73 ) ;
F_37 ( V_42 , 0 , V_74 ) ;
F_37 ( V_42 ,
( V_42 -> V_68 . V_47 -> V_53 . V_75 . V_76 == V_77 ) ?
V_78 | V_42 -> V_4 : 0 , V_79 ) ;
F_37 ( V_42 , ( V_15 >> 16 ) & 0xFFFF , V_80 ) ;
F_37 ( V_42 ,
( ( V_15 >> 8 ) & 0xFF ) |
F_46 ( F_10 ( & V_42 -> V_68 . V_6 ) ) ,
V_81 ) ;
}
static void F_47 ( const struct V_41 * V_42 )
{
if ( V_42 -> V_44 == NULL )
return;
F_37 ( V_42 ,
F_43 ( V_62 ) |
F_44 ( V_82 ) , V_67 ) ;
F_25 ( 15 ) ;
F_37 ( V_42 , 0 , V_61 ) ;
F_37 ( V_42 , 0 , V_56 ) ;
F_37 ( V_42 , 0 , V_57 ) ;
F_37 ( V_42 , 0 , V_58 ) ;
F_37 ( V_42 , 0 , V_59 ) ;
F_37 ( V_42 , 0 , V_60 ) ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
struct V_48 * V_49 ;
unsigned long V_83 , V_84 ;
int V_85 , V_86 , V_87 = - 1 ;
F_6 ( ! F_49 () ,
L_13 ) ;
if ( V_42 -> V_44 == NULL )
return;
while ( ( V_49 = F_50 ( & V_42 -> V_68 . V_88 ) ) != NULL )
F_39 ( V_42 -> V_68 . V_47 , V_49 ) ;
F_51 ( & V_89 , V_83 ) ;
F_52 ( V_42 -> V_4 , V_2 -> V_90 ) ;
F_53 ( & V_89 , V_83 ) ;
V_84 = V_91 +
( ( ( F_7 ( & V_42 -> V_68 . V_6 ) / 1024 ) * V_92 ) >> 7 ) ;
V_86 = F_54 ( F_36 ( V_42 , V_74 ) ) ;
for (; ; ) {
V_85 = F_55 ( F_36 ( V_42 , V_72 ) ) ;
if ( V_85 == V_86 &&
( V_42 -> V_68 . V_47 -> V_53 . V_75 . V_76 != V_77 ||
( F_36 ( V_42 , V_79 ) &
V_78 ) == 0 ) )
break;
if ( V_85 != V_87 ) {
V_87 = V_85 ;
V_84 += V_92 / 10 ;
}
if ( F_22 ( F_56 ( V_91 , V_84 ) ) ) {
F_31 (KERN_ERR DEV_LABEL L_14
L_15 ,
lvcc->tx.atmvcc->dev->number, lvcc->vci) ;
F_24 ( L_16 , V_85 , V_86 ) ;
break;
}
F_57 ( 40 ) ;
}
F_37 ( V_42 , 0 , V_72 ) ;
F_37 ( V_42 , 0 , V_74 ) ;
F_37 ( V_42 , 0 , V_73 ) ;
F_37 ( V_42 , 0 , V_70 ) ;
F_37 ( V_42 , 0 , V_71 ) ;
F_37 ( V_42 , 0 , V_80 ) ;
F_37 ( V_42 , 0 , V_81 ) ;
}
static inline int F_58 ( struct V_1 * V_2 )
{
F_24 ( L_17 ) ;
F_4 ( & V_2 -> V_93 , V_94 , 80 ,
V_2 -> V_10 ) ;
return ( V_2 -> V_93 . V_13 == NULL ) ? - V_95 : 0 ;
}
static inline void F_59 ( struct V_1 * V_2 )
{
F_24 ( L_18 ) ;
F_8 ( & V_2 -> V_93 , V_2 -> V_10 ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
F_31 (KERN_INFO DEV_LABEL L_19 ,
lanai->number) ;
memset ( & V_2 -> V_96 [ V_97 ] , 0 , 6 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
V_2 -> V_98 = 0 ;
V_2 -> V_99 = V_100 ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
int V_101 , V_102 ;
T_5 V_103 ;
V_19 V_104 ;
#define F_62 ( T_6 ) do { lanai->conf1 = x; conf1_write(lanai); \
} while (0)
#define F_63 () set_config1(lanai->conf1 | CONFIG1_PROMCLK)
#define F_64 () set_config1(lanai->conf1 &~ CONFIG1_PROMCLK)
#define F_65 () set_config1(lanai->conf1 | CONFIG1_PROMDATA)
#define F_66 () set_config1(lanai->conf1 &~ CONFIG1_PROMDATA)
#define F_67 () do { data_h(); clock_h(); udelay(5); } while (0)
#define F_68 () (reg_read(lanai, Status_Reg) & STATUS_PROMDATA)
#define F_69 () do { data_l(); udelay(5); clock_h(); udelay(5); \
data_h(); udelay(5); } while (0)
F_65 () ; F_63 () ; F_25 ( 5 ) ;
for ( V_102 = 0 ; V_102 < V_105 ; V_102 ++ ) {
V_103 = ( V_102 << 1 ) | 1 ;
F_66 () ; F_25 ( 5 ) ;
F_64 () ; F_25 ( 5 ) ;
for ( V_101 = 128 ; V_101 != 0 ; V_101 >>= 1 ) {
V_104 = ( V_2 -> V_27 & ~ V_106 ) |
( ( V_103 & V_101 ) ? V_106 : 0 ) ;
if ( V_2 -> V_27 != V_104 ) {
F_62 ( V_104 ) ;
F_25 ( 5 ) ;
}
F_63 () ; F_25 ( 5 ) ; F_64 () ; F_25 ( 5 ) ;
}
F_65 () ; F_63 () ; F_25 ( 5 ) ;
if ( F_68 () != 0 )
goto error;
F_64 () ; F_25 ( 5 ) ;
for ( V_103 = 0 , V_101 = 7 ; V_101 >= 0 ; V_101 -- ) {
F_65 () ; F_63 () ; F_25 ( 5 ) ;
V_103 = ( V_103 << 1 ) | ! ! F_68 () ;
F_64 () ; F_25 ( 5 ) ;
}
F_65 () ; F_63 () ; F_25 ( 5 ) ;
if ( F_68 () == 0 )
goto error;
F_64 () ; F_25 ( 5 ) ;
F_69 () ;
V_2 -> V_96 [ V_102 ] = V_103 ;
F_24 ( L_20 ,
( unsigned int ) V_102 , ( unsigned int ) V_103 ) ;
}
return 0 ;
error:
F_64 () ; F_25 ( 5 ) ;
F_69 () ;
F_31 (KERN_ERR DEV_LABEL L_21 ,
lanai->number, address) ;
return - V_37 ;
#undef F_62
#undef F_63
#undef F_64
#undef F_65
#undef F_66
#undef F_67
#undef F_68
#undef F_69
}
static inline V_19 F_70 ( const struct V_1 * V_2 , int V_102 )
{
return F_71 ( ( const V_19 * ) & V_2 -> V_96 [ V_102 ] ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_101 , V_107 ;
V_19 V_108 ;
const T_5 * V_109 = V_2 -> V_96 ;
#ifdef F_72
for ( V_101 = V_110 ;
V_101 < ( V_110 + V_111 ) ; V_101 ++ )
if ( V_109 [ V_101 ] < 0x20 || V_109 [ V_101 ] > 0x7E )
break;
if ( V_101 != V_110 &&
V_101 != V_110 + V_111 && V_109 [ V_101 ] == '\0' )
F_24 ( L_22 ,
( char * ) & V_109 [ V_110 ] ) ;
else
F_24 ( L_23 ) ;
#endif
for ( V_101 = V_107 = 0 ; V_101 < V_112 ; V_101 ++ )
V_107 += V_109 [ V_101 ] ;
V_107 &= 0xFF ;
if ( V_107 != V_109 [ V_112 ] ) {
F_31 (KERN_ERR DEV_LABEL L_24
L_25 , lanai->number,
(unsigned int) s, (unsigned int) e[EEPROM_CHECKSUM]) ;
return - V_37 ;
}
V_107 ^= 0xFF ;
if ( V_107 != V_109 [ V_113 ] ) {
F_31 (KERN_ERR DEV_LABEL L_26
L_27 , lanai->number,
(unsigned int) s, (unsigned int) e[EEPROM_CHECKSUM_REV]) ;
return - V_37 ;
}
for ( V_101 = 0 ; V_101 < 6 ; V_101 ++ )
if ( ( V_109 [ V_97 + V_101 ] ^ V_109 [ V_114 + V_101 ] ) != 0xFF ) {
F_31 (KERN_ERR DEV_LABEL
L_28
L_29 , lanai->number,
(unsigned int) e[EEPROM_MAC + i],
(unsigned int) e[EEPROM_MAC_REV + i]) ;
return - V_37 ;
}
F_24 ( L_30 , & V_109 [ V_97 ] ) ;
V_2 -> V_98 = F_70 ( V_2 , V_115 ) ;
V_108 = F_70 ( V_2 , V_116 ) ;
if ( ( V_2 -> V_98 ^ V_108 ) != 0xFFFFFFFF ) {
F_31 (KERN_ERR DEV_LABEL L_31
L_32 , lanai->number,
(unsigned int) lanai->serialno, (unsigned int) v) ;
return - V_37 ;
}
F_24 ( L_33 , ( unsigned int ) V_2 -> V_98 ) ;
V_2 -> V_99 = F_70 ( V_2 , V_117 ) ;
V_108 = F_70 ( V_2 , V_118 ) ;
if ( ( V_2 -> V_99 ^ V_108 ) != 0xFFFFFFFF ) {
F_31 (KERN_ERR DEV_LABEL L_34
L_32 , lanai->number,
lanai->magicno, v) ;
return - V_37 ;
}
F_24 ( L_35 , V_2 -> V_99 ) ;
if ( V_2 -> V_99 != V_100 )
F_31 (KERN_WARNING DEV_LABEL L_36
L_37 ,
lanai->number, (unsigned int) lanai->magicno,
(unsigned int) EEPROM_MAGIC_VALUE) ;
return 0 ;
}
static inline const T_5 * F_73 ( const struct V_1 * V_2 )
{
return & V_2 -> V_96 [ V_97 ] ;
}
static inline V_19 F_74 ( const struct V_1 * V_2 )
{
return F_13 ( V_2 , V_119 ) ;
}
static inline void F_75 ( const struct V_1 * V_2 , V_19 V_101 )
{
F_16 ( V_2 , V_101 , V_120 ) ;
}
static inline void F_76 ( const struct V_1 * V_2 , V_19 V_101 )
{
F_16 ( V_2 , V_101 , V_121 ) ;
}
static void F_77 ( int V_122 , const char * V_123 , int V_124 )
{
static const char * V_125 [ 2 ] = { L_38 , L_39 } ;
F_31 (KERN_INFO DEV_LABEL L_40 ,
itf, name, onoff[!status]) ;
}
static void F_78 ( struct V_1 * V_2 )
{
V_19 V_126 = F_13 ( V_2 , V_127 ) ;
V_19 V_128 = V_126 ^ V_2 -> V_124 ;
V_2 -> V_124 = V_126 ;
#define V_109 ( T_7 , V_123 ) \
if (changes & flag) \
status_message(lanai->number, name, new & flag)
V_109 ( V_129 , L_41 ) ;
V_109 ( V_130 , L_42 ) ;
V_109 ( V_131 , L_43 ) ;
V_109 ( V_132 , L_44 ) ;
#undef V_109
}
static void F_79 ( int V_122 , const char * V_123 )
{
F_31 (KERN_INFO DEV_LABEL L_45 , itf, name) ;
}
static void F_80 ( struct V_1 * V_2 , int V_133 )
{
T_8 V_107 ;
int V_38 ;
V_38 = F_81 ( V_2 -> V_10 , V_134 , & V_107 ) ;
if ( V_38 != V_135 ) {
F_31 (KERN_ERR DEV_LABEL L_46
L_47 , lanai->number, result) ;
return;
}
V_107 &= V_136 | V_137 |
V_138 | V_139 |
V_140 | V_141 ;
if ( V_107 == 0 )
return;
V_38 = F_82 ( V_2 -> V_10 , V_134 , V_107 ) ;
if ( V_38 != V_135 )
F_31 (KERN_ERR DEV_LABEL L_48
L_47 , lanai->number, result) ;
if ( V_133 )
return;
#define V_109 ( T_7 , V_123 , T_9 ) \
if (s & flag) { \
pcistatus_got(lanai->number, name); \
++lanai->stats.pcierr_##stat; \
}
V_109 ( V_136 , L_49 , V_142 ) ;
V_109 ( V_137 , L_50 , V_143 ) ;
V_109 ( V_138 , L_51 , V_144 ) ;
V_109 ( V_139 , L_52 , V_145 ) ;
V_109 ( V_140 , L_53 , V_146 ) ;
V_109 ( V_141 , L_54 , V_147 ) ;
#undef V_109
}
static inline int F_83 ( const struct V_41 * V_42 , int V_148 )
{
int V_149 ;
V_149 = V_148 * 16 ;
V_149 -= ( ( unsigned long ) V_42 -> V_68 . V_6 . V_17 ) -
( ( unsigned long ) V_42 -> V_68 . V_6 . V_13 ) ;
V_149 -= 16 ;
if ( V_149 < 0 )
V_149 += F_7 ( & V_42 -> V_68 . V_6 ) ;
return V_149 ;
}
static inline int F_84 ( const struct V_41 * V_42 )
{
return ! F_85 ( & V_42 -> V_68 . V_88 ) ;
}
static inline void F_86 ( struct V_41 * V_42 ,
V_19 V_83 , int V_150 )
{
int V_151 ;
F_6 ( ( ( ( unsigned long ) V_42 -> V_68 . V_6 . V_17 ) & 15 ) == 0 ,
L_55 , V_42 -> V_68 . V_6 . V_17 ) ;
V_42 -> V_68 . V_6 . V_17 += 4 ;
V_151 = ( ( unsigned char * ) V_42 -> V_68 . V_6 . V_17 ) -
( unsigned char * ) V_42 -> V_68 . V_6 . V_13 ;
F_6 ( ( V_151 & ~ 0x0001FFF0 ) == 0 ,
L_56
L_57 , V_151 , V_42 -> V_4 ,
V_42 -> V_68 . V_6 . V_13 , V_42 -> V_68 . V_6 . V_17 , V_42 -> V_68 . V_6 . V_18 ) ;
V_151 = ( V_151 + V_150 ) & ( F_7 ( & V_42 -> V_68 . V_6 ) - 1 ) ;
F_6 ( ( V_151 & ~ 0x0001FFF0 ) == 0 ,
L_58
L_57 , V_151 , V_42 -> V_4 ,
V_42 -> V_68 . V_6 . V_13 , V_42 -> V_68 . V_6 . V_17 , V_42 -> V_68 . V_6 . V_18 ) ;
V_42 -> V_68 . V_6 . V_17 [ - 1 ] =
F_87 ( V_152 | V_153 |
( ( V_42 -> V_68 . V_47 -> V_154 & V_155 ) ?
V_156 : 0 ) | V_83 | V_151 >> 4 ) ;
if ( V_42 -> V_68 . V_6 . V_17 >= V_42 -> V_68 . V_6 . V_18 )
V_42 -> V_68 . V_6 . V_17 = V_42 -> V_68 . V_6 . V_13 ;
}
static inline void F_88 ( struct V_41 * V_42 ,
int V_150 , int V_157 , int V_158 )
{
F_6 ( ( ( ( unsigned long ) V_42 -> V_68 . V_6 . V_17 ) & 15 ) == 8 ,
L_59 , V_42 -> V_68 . V_6 . V_17 ) ;
V_42 -> V_68 . V_6 . V_17 += 2 ;
V_42 -> V_68 . V_6 . V_17 [ - 2 ] = F_89 ( ( V_158 << 24 ) | ( V_157 << 16 ) | V_150 ) ;
if ( V_42 -> V_68 . V_6 . V_17 >= V_42 -> V_68 . V_6 . V_18 )
V_42 -> V_68 . V_6 . V_17 = V_42 -> V_68 . V_6 . V_13 ;
}
static inline void F_90 ( struct V_41 * V_42 ,
const unsigned char * V_159 , int V_160 )
{
unsigned char * V_109 ;
int V_161 ;
V_109 = ( ( unsigned char * ) V_42 -> V_68 . V_6 . V_17 ) + V_160 ;
V_161 = V_109 - ( unsigned char * ) V_42 -> V_68 . V_6 . V_18 ;
if ( V_161 < 0 )
V_161 = 0 ;
memcpy ( V_42 -> V_68 . V_6 . V_17 , V_159 , V_160 - V_161 ) ;
if ( V_161 != 0 ) {
memcpy ( V_42 -> V_68 . V_6 . V_13 , V_159 + V_160 - V_161 , V_161 ) ;
V_109 = ( ( unsigned char * ) V_42 -> V_68 . V_6 . V_13 ) + V_161 ;
}
V_42 -> V_68 . V_6 . V_17 = ( V_19 * ) V_109 ;
}
static inline void F_91 ( struct V_41 * V_42 , int V_160 )
{
unsigned char * V_109 ;
int V_161 ;
if ( V_160 == 0 )
return;
V_109 = ( ( unsigned char * ) V_42 -> V_68 . V_6 . V_17 ) + V_160 ;
V_161 = V_109 - ( unsigned char * ) V_42 -> V_68 . V_6 . V_18 ;
if ( V_161 < 0 )
V_161 = 0 ;
memset ( V_42 -> V_68 . V_6 . V_17 , 0 , V_160 - V_161 ) ;
if ( V_161 != 0 ) {
memset ( V_42 -> V_68 . V_6 . V_13 , 0 , V_161 ) ;
V_109 = ( ( unsigned char * ) V_42 -> V_68 . V_6 . V_13 ) + V_161 ;
}
V_42 -> V_68 . V_6 . V_17 = ( V_19 * ) V_109 ;
}
static inline void F_92 ( struct V_1 * V_2 ,
const struct V_41 * V_42 )
{
int V_101 , V_17 = ( ( unsigned char * ) V_42 -> V_68 . V_6 . V_17 ) -
( unsigned char * ) V_42 -> V_68 . V_6 . V_13 ;
F_6 ( ( V_17 & ~ 0x0001FFF0 ) == 0 ,
L_60 ,
V_17 , V_42 -> V_4 , V_42 -> V_68 . V_6 . V_13 , V_42 -> V_68 . V_6 . V_17 ,
V_42 -> V_68 . V_6 . V_18 ) ;
F_93 ( & V_2 -> V_162 ) ;
for ( V_101 = 0 ; F_13 ( V_2 , V_127 ) & V_163 ; V_101 ++ ) {
if ( F_22 ( V_101 > 50 ) ) {
F_31 (KERN_ERR DEV_LABEL L_61
L_62 , lanai->number) ;
break;
}
F_25 ( 5 ) ;
}
F_94 () ;
F_16 ( V_2 , ( V_17 << 12 ) | V_42 -> V_4 , V_164 ) ;
F_95 ( & V_2 -> V_162 ) ;
}
static void F_96 ( struct V_1 * V_2 ,
struct V_41 * V_42 , struct V_48 * V_49 , int V_165 )
{
int V_166 ;
F_6 ( V_165 == F_38 ( V_49 -> V_150 ) ,
L_63 ,
V_165 , F_38 ( V_49 -> V_150 ) ) ;
F_86 ( V_42 , 0 , V_165 ) ;
V_166 = V_165 - V_49 -> V_150 - 8 ;
F_6 ( V_166 >= 0 , L_64 , V_166 ) ;
F_6 ( V_166 < 48 , L_65 , V_166 ) ;
F_90 ( V_42 , V_49 -> V_103 , V_49 -> V_150 ) ;
F_91 ( V_42 , V_166 ) ;
F_88 ( V_42 , V_49 -> V_150 , 0 , 0 ) ;
F_92 ( V_2 , V_42 ) ;
F_39 ( V_42 -> V_68 . V_47 , V_49 ) ;
F_97 ( & V_42 -> V_68 . V_47 -> V_167 -> V_68 ) ;
}
static void F_98 ( struct V_1 * V_2 ,
struct V_41 * V_42 , int V_148 )
{
int V_160 ;
struct V_48 * V_49 ;
int V_168 = F_83 ( V_42 , V_148 ) ;
F_6 ( F_84 ( V_42 ) ,
L_66 ,
V_42 -> V_4 ) ;
while ( V_168 >= 64 ) {
V_49 = F_50 ( & V_42 -> V_68 . V_88 ) ;
if ( V_49 == NULL )
goto V_169;
V_160 = F_38 ( V_49 -> V_150 ) ;
if ( V_160 + 16 > V_168 ) {
F_99 ( & V_42 -> V_68 . V_88 , V_49 ) ;
return;
}
F_96 ( V_2 , V_42 , V_49 , V_160 ) ;
V_168 -= V_160 + 16 ;
}
if ( ! F_84 ( V_42 ) ) {
V_169:
F_52 ( V_42 -> V_4 , V_2 -> V_90 ) ;
}
}
static void F_100 ( struct V_1 * V_2 , struct V_41 * V_42 ,
struct V_48 * V_49 )
{
int V_168 , V_160 ;
if ( F_84 ( V_42 ) )
goto V_170;
V_168 = F_83 ( V_42 ,
F_55 ( F_36 ( V_42 , V_72 ) ) ) ;
V_160 = F_38 ( V_49 -> V_150 ) ;
F_6 ( V_160 + 16 >= 64 , L_67 , V_160 ) ;
if ( V_168 < V_160 + 16 ) {
F_101 ( V_42 -> V_4 , V_2 -> V_90 ) ;
V_170:
F_102 ( & V_42 -> V_68 . V_88 , V_49 ) ;
return;
}
F_96 ( V_2 , V_42 , V_49 , V_160 ) ;
}
static void F_103 ( struct V_1 * V_2 ,
struct V_41 * V_42 , int V_148 )
{
F_31 (KERN_INFO DEV_LABEL
L_68 ) ;
}
static void F_104 ( struct V_1 * V_2 , struct V_41 * V_42 ,
struct V_48 * V_49 )
{
F_31 (KERN_INFO DEV_LABEL L_69 ) ;
F_39 ( V_42 -> V_68 . V_47 , V_49 ) ;
}
static inline void F_105 ( unsigned char * V_171 ,
const struct V_41 * V_42 , int V_160 )
{
int V_161 = ( ( const unsigned char * ) V_42 -> V_52 . V_6 . V_17 ) + V_160 -
( ( const unsigned char * ) ( V_42 -> V_52 . V_6 . V_18 ) ) ;
if ( V_161 < 0 )
V_161 = 0 ;
memcpy ( V_171 , V_42 -> V_52 . V_6 . V_17 , V_160 - V_161 ) ;
memcpy ( V_171 + V_160 - V_161 , V_42 -> V_52 . V_6 . V_13 , V_161 ) ;
F_106 () ;
}
static void F_107 ( struct V_41 * V_42 , int V_148 )
{
int V_11 ;
struct V_48 * V_49 ;
const V_19 * T_6 ;
V_19 * V_18 = & V_42 -> V_52 . V_6 . V_13 [ V_148 * 4 ] ;
int V_160 = ( ( unsigned long ) V_18 ) - ( ( unsigned long ) V_42 -> V_52 . V_6 . V_17 ) ;
if ( V_160 < 0 )
V_160 += F_7 ( & V_42 -> V_52 . V_6 ) ;
F_6 ( V_160 >= 0 && V_160 < F_7 ( & V_42 -> V_52 . V_6 ) && ! ( V_160 & 15 ) ,
L_70 ,
V_160 , F_7 ( & V_42 -> V_52 . V_6 ) ) ;
if ( ( T_6 = & V_18 [ - 2 ] ) < V_42 -> V_52 . V_6 . V_13 )
T_6 = & V_42 -> V_52 . V_6 . V_18 [ - 2 ] ;
F_108 () ;
V_11 = F_71 ( T_6 ) & 0xffff ;
if ( F_22 ( V_160 != F_38 ( V_11 ) ) ) {
F_31 (KERN_INFO DEV_LABEL L_71
L_72 ,
lvcc->rx.atmvcc->dev->number, lvcc->vci, size, n) ;
V_42 -> V_167 . T_6 . V_172 . V_173 ++ ;
goto V_174;
}
V_49 = F_109 ( V_42 -> V_52 . V_47 , V_11 , V_175 ) ;
if ( F_22 ( V_49 == NULL ) ) {
V_42 -> V_167 . V_176 ++ ;
goto V_174;
}
F_110 ( V_49 , V_11 ) ;
F_105 ( V_49 -> V_103 , V_42 , V_11 ) ;
F_111 ( V_49 ) -> V_177 = V_42 -> V_52 . V_47 ;
F_112 ( V_49 ) ;
V_42 -> V_52 . V_47 -> V_178 ( V_42 -> V_52 . V_47 , V_49 ) ;
F_97 ( & V_42 -> V_52 . V_47 -> V_167 -> V_52 ) ;
V_174:
V_42 -> V_52 . V_6 . V_17 = V_18 ;
F_37 ( V_42 , V_148 , V_60 ) ;
}
static void F_113 ( struct V_1 * V_2 )
{
F_31 (KERN_INFO DEV_LABEL L_73 ) ;
}
static int F_114 ( struct V_1 * V_2 )
{
#ifdef F_115
F_6 ( ( V_2 -> V_179 ) * sizeof( struct V_41 * ) <= V_180 ,
L_74 ) ;
V_2 -> V_181 = (struct V_41 * * ) F_116 ( V_16 ) ;
return ( V_2 -> V_181 == NULL ) ? - V_95 : 0 ;
#else
int V_7 = ( V_2 -> V_179 ) * sizeof( struct V_41 * ) ;
V_2 -> V_181 = F_117 ( V_7 ) ;
if ( F_22 ( V_2 -> V_181 == NULL ) )
return - V_95 ;
return 0 ;
#endif
}
static inline void F_118 ( const struct V_1 * V_2 )
{
#ifdef F_115
F_119 ( ( unsigned long ) V_2 -> V_181 ) ;
#else
F_120 ( V_2 -> V_181 ) ;
#endif
}
static inline struct V_41 * F_121 ( void )
{
struct V_41 * V_42 ;
V_42 = F_122 ( sizeof( * V_42 ) , V_16 ) ;
if ( F_30 ( V_42 != NULL ) ) {
F_123 ( & V_42 -> V_68 . V_88 ) ;
#ifdef F_72
V_42 -> V_4 = - 1 ;
#endif
}
return V_42 ;
}
static int F_124 ( struct V_1 * V_2 ,
struct V_5 * V_6 , int V_182 , int V_183 ,
const char * V_123 )
{
int V_11 ;
if ( F_22 ( V_182 < 1 ) )
V_182 = 1 ;
V_182 = F_38 ( V_182 ) ;
V_11 = ( V_182 + 16 ) * V_183 + 16 ;
F_4 ( V_6 , V_11 , V_182 + 32 , V_2 -> V_10 ) ;
if ( F_22 ( V_6 -> V_13 == NULL ) )
return - V_95 ;
if ( F_22 ( F_7 ( V_6 ) < V_11 ) )
F_31 (KERN_WARNING DEV_LABEL L_75
L_76 , lanai->number, size,
name, lanai_buf_size(buf)) ;
F_24 ( L_77 , F_7 ( V_6 ) , V_123 ) ;
return 0 ;
}
static inline int F_125 ( struct V_1 * V_2 ,
struct V_41 * V_42 , const struct V_184 * V_53 )
{
return F_124 ( V_2 , & V_42 -> V_52 . V_6 ,
V_53 -> V_185 . V_182 , V_186 , L_78 ) ;
}
static int F_126 ( struct V_1 * V_2 , struct V_41 * V_42 ,
const struct V_184 * V_53 )
{
int V_182 , V_183 ;
if ( V_53 -> V_54 == V_187 ) {
V_42 -> V_68 . V_188 = F_103 ;
V_182 = V_189 - 1 ;
V_183 = V_190 ;
} else {
V_42 -> V_68 . V_188 = F_98 ;
V_182 = V_53 -> V_75 . V_182 ;
V_183 = V_191 ;
}
return F_124 ( V_2 , & V_42 -> V_68 . V_6 , V_182 ,
V_183 , L_79 ) ;
}
static inline void F_127 ( struct V_1 * V_2 ,
struct V_41 * V_42 , T_1 V_4 )
{
if ( V_42 -> V_44 != NULL )
return;
F_24 ( L_80 , V_4 ) ;
#ifdef F_21
if ( V_2 -> V_192 ++ == 0 ) {
F_24 ( L_81 ) ;
V_2 -> V_27 &= ~ V_31 ;
F_18 ( V_2 ) ;
F_19 ( V_2 ) ;
}
#endif
V_42 -> V_44 = F_35 ( V_2 , V_4 ) ;
V_2 -> V_181 [ V_42 -> V_4 = V_4 ] = V_42 ;
}
static inline void F_128 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
if ( V_42 -> V_44 == NULL )
return;
F_24 ( L_82 , V_42 -> V_4 ) ;
V_42 -> V_44 = NULL ;
V_2 -> V_181 [ V_42 -> V_4 ] = NULL ;
#ifdef F_21
if ( -- V_2 -> V_192 == 0 ) {
F_24 ( L_83 ) ;
V_2 -> V_27 |= V_31 ;
F_18 ( V_2 ) ;
}
#endif
}
static void F_129 ( struct V_1 * V_2 )
{
F_31 (KERN_CRIT DEV_LABEL L_84
L_85 , lanai->number) ;
F_16 ( V_2 , V_193 , V_194 ) ;
V_2 -> V_167 . V_195 ++ ;
}
static int F_130 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_196 , V_197 * 4 , 8 ,
V_2 -> V_10 ) ;
if ( F_22 ( V_2 -> V_196 . V_13 == NULL ) )
return - V_95 ;
F_24 ( L_86 ,
( unsigned long ) V_2 -> V_196 . V_13 ,
F_7 ( & V_2 -> V_196 ) ,
F_10 ( & V_2 -> V_196 ) ) ;
F_16 ( V_2 , 0 , V_198 ) ;
F_16 ( V_2 ,
F_131 ( F_10 ( & V_2 -> V_196 ) ) |
F_132 ( V_2 -> V_196 . V_15 ) ,
V_199 ) ;
return 0 ;
}
static inline void F_133 ( struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_196 , V_2 -> V_10 ) ;
}
static int F_134 ( struct V_1 * V_2 , V_19 V_107 )
{
T_1 V_4 = F_135 ( V_107 ) ;
struct V_41 * V_42 ;
F_136 ( & V_89 ) ;
V_42 = V_2 -> V_181 [ V_4 ] ;
if ( F_22 ( V_42 == NULL ) ) {
F_137 ( & V_89 ) ;
F_24 ( L_87
L_88 , V_2 -> V_200 , ( unsigned int ) V_107 , V_4 ) ;
if ( V_107 & V_201 )
V_2 -> V_167 . V_202 ++ ;
else
V_2 -> V_167 . V_203 ++ ;
return 0 ;
}
if ( V_107 & V_201 ) {
if ( F_22 ( V_42 -> V_68 . V_47 == NULL ) ) {
F_137 ( & V_89 ) ;
F_24 ( L_89
L_88 , V_2 -> V_200 , ( unsigned int ) V_107 , V_4 ) ;
V_2 -> V_167 . V_202 ++ ;
return 0 ;
}
F_101 ( V_4 , V_2 -> V_204 ) ;
V_42 -> V_68 . V_148 = F_138 ( V_107 ) ;
F_137 ( & V_89 ) ;
return 1 ;
}
if ( F_22 ( V_42 -> V_52 . V_47 == NULL ) ) {
F_137 ( & V_89 ) ;
F_24 ( L_90
L_88 , V_2 -> V_200 , ( unsigned int ) V_107 , V_4 ) ;
V_2 -> V_167 . V_203 ++ ;
return 0 ;
}
if ( F_22 ( V_42 -> V_52 . V_47 -> V_53 . V_54 != V_55 ) ) {
F_137 ( & V_89 ) ;
F_24 ( L_91
L_88 , V_2 -> V_200 , ( unsigned int ) V_107 , V_4 ) ;
V_2 -> V_167 . V_205 ++ ;
F_97 ( & V_42 -> V_52 . V_47 -> V_167 -> V_206 ) ;
return 0 ;
}
if ( F_30 ( ! ( V_107 & ( V_207 | V_208 | V_209 ) ) ) ) {
F_107 ( V_42 , F_138 ( V_107 ) ) ;
F_137 ( & V_89 ) ;
return 0 ;
}
if ( V_107 & V_207 ) {
int V_7 ;
F_137 ( & V_89 ) ;
F_24 ( L_92 , V_4 ) ;
F_97 ( & V_42 -> V_52 . V_47 -> V_167 -> V_206 ) ;
V_42 -> V_167 . T_6 . V_172 . V_210 ++ ;
V_7 = ( F_138 ( V_107 ) * 16 ) -
( ( ( unsigned long ) V_42 -> V_52 . V_6 . V_17 ) -
( ( unsigned long ) V_42 -> V_52 . V_6 . V_13 ) ) + 47 ;
if ( V_7 < 0 )
V_7 += F_7 ( & V_42 -> V_52 . V_6 ) ;
V_2 -> V_167 . V_211 += ( V_7 / 48 ) ;
return 0 ;
}
if ( V_107 & V_208 ) {
F_137 ( & V_89 ) ;
F_97 ( & V_42 -> V_52 . V_47 -> V_167 -> V_206 ) ;
V_42 -> V_167 . T_6 . V_172 . V_212 ++ ;
F_31 (KERN_ERR DEV_LABEL L_93
L_94 , lanai->number, vci) ;
F_129 ( V_2 ) ;
return 0 ;
}
F_24 ( L_95 , V_4 ) ;
F_97 ( & V_42 -> V_52 . V_47 -> V_167 -> V_206 ) ;
V_42 -> V_167 . T_6 . V_172 . V_213 ++ ;
V_42 -> V_52 . V_6 . V_17 = & V_42 -> V_52 . V_6 . V_13 [ F_138 ( V_107 ) * 4 ] ;
F_37 ( V_42 , F_138 ( V_107 ) , V_60 ) ;
F_137 ( & V_89 ) ;
return 0 ;
}
static void F_139 ( struct V_1 * V_2 , T_1 V_4 )
{
struct V_41 * V_42 = V_2 -> V_181 [ V_4 ] ;
if ( F_84 ( V_42 ) )
V_42 -> V_68 . V_188 ( V_2 , V_42 , V_42 -> V_68 . V_148 ) ;
}
static void F_140 ( struct V_1 * V_2 )
{
int V_214 = 0 ;
V_19 V_215 = F_13 ( V_2 , V_198 ) ;
const V_19 * V_18 = V_2 -> V_196 . V_13 + V_215 ;
while ( V_2 -> V_196 . V_17 != V_18 ) {
V_214 += F_134 ( V_2 ,
F_141 ( V_2 -> V_196 . V_17 ++ ) ) ;
if ( V_2 -> V_196 . V_17 >= V_2 -> V_196 . V_18 )
V_2 -> V_196 . V_17 = V_2 -> V_196 . V_13 ;
}
F_16 ( V_2 , V_215 , V_216 ) ;
if ( V_214 != 0 ) {
F_136 ( & V_89 ) ;
F_1 ( V_2 , V_2 -> V_204 ,
F_139 ) ;
F_142 ( V_2 -> V_204 , V_217 ) ;
F_137 ( & V_89 ) ;
}
}
static void F_143 ( struct V_1 * V_2 )
{
V_19 V_218 = F_13 ( V_2 , V_219 ) ;
V_2 -> V_167 . V_220 += F_144 ( V_218 ) ;
V_2 -> V_167 . V_221 += F_145 ( V_218 ) ;
V_2 -> V_167 . V_222 += F_146 ( V_218 ) ;
V_2 -> V_167 . V_211 += F_147 ( V_218 ) ;
}
static void F_148 ( struct V_1 * V_2 , T_1 V_4 )
{
struct V_41 * V_42 = V_2 -> V_181 [ V_4 ] ;
int V_148 ;
if ( V_42 == NULL || V_42 -> V_68 . V_47 == NULL ||
! F_84 ( V_42 ) ) {
F_52 ( V_4 , V_2 -> V_90 ) ;
return;
}
V_148 = F_55 ( F_36 ( V_42 , V_72 ) ) ;
V_42 -> V_68 . V_188 ( V_2 , V_42 , V_148 ) ;
}
static void F_149 ( unsigned long V_223 )
{
struct V_1 * V_2 = (struct V_1 * ) V_223 ;
#ifndef F_150
unsigned long V_83 ;
#ifdef F_21
if ( V_2 -> V_27 & V_31 )
return;
#endif
F_151 ( V_83 ) ;
if ( F_152 ( & V_2 -> V_224 ) ) {
F_140 ( V_2 ) ;
F_95 ( & V_2 -> V_224 ) ;
}
F_136 ( & V_89 ) ;
F_1 ( V_2 , V_2 -> V_90 , F_148 ) ;
F_137 ( & V_89 ) ;
F_153 ( V_83 ) ;
F_143 ( V_2 ) ;
#endif
F_154 ( & V_2 -> V_225 , V_91 + V_226 ) ;
}
static inline void F_155 ( struct V_1 * V_2 )
{
F_156 ( & V_2 -> V_225 ) ;
V_2 -> V_225 . V_227 = V_91 + V_226 ;
V_2 -> V_225 . V_103 = ( unsigned long ) V_2 ;
V_2 -> V_225 . V_228 = F_149 ;
F_157 ( & V_2 -> V_225 ) ;
}
static inline void F_158 ( struct V_1 * V_2 )
{
F_159 ( & V_2 -> V_225 ) ;
}
static inline void F_160 ( struct V_1 * V_2 , V_19 V_229 )
{
V_19 V_230 = 0 ;
if ( V_229 & V_231 ) {
V_230 = V_231 ;
F_93 ( & V_2 -> V_224 ) ;
F_140 ( V_2 ) ;
F_95 ( & V_2 -> V_224 ) ;
}
if ( V_229 & ( V_232 | V_233 ) ) {
V_230 |= V_229 & ( V_232 | V_233 ) ;
F_113 ( V_2 ) ;
}
if ( V_230 == V_229 )
goto V_234;
if ( V_229 & V_235 ) {
V_229 &= ~ V_235 ;
F_143 ( V_2 ) ;
}
if ( V_229 & V_236 ) {
V_230 |= V_229 & V_236 ;
F_78 ( V_2 ) ;
}
if ( F_22 ( V_229 & V_237 ) ) {
F_31 (KERN_ERR DEV_LABEL L_96
L_97 ,
lanai->number, (unsigned int) (reason & INT_DMASHUT),
(unsigned int) reg_read(lanai, DMA_Addr_Reg)) ;
if ( V_229 & V_238 ) {
F_129 ( V_2 ) ;
return;
}
V_230 |= ( V_229 & V_237 ) ;
F_31 (KERN_ERR DEV_LABEL L_98 ,
lanai->number) ;
F_18 ( V_2 ) ;
V_2 -> V_167 . V_239 ++ ;
F_80 ( V_2 , 0 ) ;
}
if ( F_22 ( V_229 & V_240 ) ) {
V_230 |= ( V_229 & V_240 ) ;
F_31 (KERN_ERR DEV_LABEL L_99 ,
lanai->number) ;
F_80 ( V_2 , 0 ) ;
}
if ( F_22 ( V_229 & V_241 ) ) {
F_31 (KERN_ERR DEV_LABEL L_100
L_101 , lanai->number,
(unsigned int) (reason & INT_SEGSHUT)) ;
F_129 ( V_2 ) ;
return;
}
if ( F_22 ( V_229 & ( V_242 | V_243 ) ) ) {
F_31 (KERN_ERR DEV_LABEL L_100
L_102 ,
lanai->number,
(unsigned int) (reason & (INT_PING | INT_WAKE))) ;
F_129 ( V_2 ) ;
return;
}
#ifdef F_72
if ( F_22 ( V_230 != V_229 ) ) {
F_24 ( L_103 ,
( unsigned int ) ( V_229 & ~ V_230 ) ) ;
V_230 = V_229 ;
}
#endif
V_234:
if ( V_230 != 0 )
F_16 ( V_2 , V_230 , V_194 ) ;
}
static T_10 F_161 ( int V_244 , void * V_245 )
{
struct V_1 * V_2 = V_245 ;
V_19 V_229 ;
#ifdef F_21
if ( F_22 ( V_2 -> V_27 & V_31 ) )
return V_246 ;
#endif
V_229 = F_74 ( V_2 ) ;
if ( V_229 == 0 )
return V_246 ;
do {
if ( F_22 ( V_229 == 0xFFFFFFFF ) )
break;
F_160 ( V_2 , V_229 ) ;
V_229 = F_74 ( V_2 ) ;
} while ( V_229 != 0 );
return V_247 ;
}
static int F_162 ( const char * V_123 , V_19 V_26 , int * V_248 )
{
F_24 ( L_104 , V_123 ,
( int ) F_163 ( V_26 ) ,
( int ) F_164 ( V_26 ) ) ;
if ( F_163 ( V_26 ) != V_249 ) {
F_31 (KERN_ERR DEV_LABEL L_105
L_106 , name, (int) RESET_GET_BOARD_ID(val)) ;
return - V_250 ;
}
if ( V_248 != NULL )
* V_248 = F_164 ( V_26 ) ;
return 0 ;
}
static int F_165 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
int V_38 ;
if ( F_166 ( V_10 ) != 0 ) {
F_31 (KERN_ERR DEV_LABEL L_107
L_108 , lanai->number) ;
return - V_251 ;
}
F_167 ( V_10 ) ;
if ( F_168 ( & V_10 -> V_14 , F_169 ( 32 ) ) != 0 ) {
F_31 (KERN_WARNING DEV_LABEL
L_109 , lanai->number) ;
return - V_252 ;
}
V_38 = F_162 ( L_110 , V_10 -> V_253 , NULL ) ;
if ( V_38 != 0 )
return V_38 ;
V_38 = F_170 ( V_10 , V_254 , 0 ) ;
if ( V_38 != V_135 ) {
F_31 (KERN_ERR DEV_LABEL L_111
L_112 , lanai->number, result) ;
return - V_255 ;
}
F_80 ( V_2 , 1 ) ;
F_80 ( V_2 , 0 ) ;
return 0 ;
}
static inline int F_171 ( struct V_1 * V_2 ,
const struct V_184 * V_53 )
{
if ( V_53 -> V_75 . V_76 == V_77 || V_53 -> V_54 == V_187 )
return 0 ;
if ( V_53 -> V_185 . V_76 != V_256 ) {
if ( V_2 -> V_257 != 0 )
return 0 ;
V_2 -> V_29 |= V_258 ;
F_20 ( V_2 ) ;
}
return 1 ;
}
static int F_172 ( struct V_1 * V_2 , T_1 V_4 ,
const struct V_46 * V_47 )
{
const struct V_184 * V_53 = & V_47 -> V_53 ;
const struct V_41 * V_42 = V_2 -> V_181 [ V_4 ] ;
if ( V_4 == 0 && ! F_171 ( V_2 , V_53 ) )
return 0 ;
if ( F_22 ( V_42 != NULL ) ) {
if ( V_53 -> V_185 . V_76 != V_256 &&
V_42 -> V_52 . V_47 != NULL && V_42 -> V_52 . V_47 != V_47 )
return 0 ;
if ( V_53 -> V_75 . V_76 != V_256 &&
V_42 -> V_68 . V_47 != NULL && V_42 -> V_68 . V_47 != V_47 )
return 0 ;
if ( V_53 -> V_75 . V_76 == V_77 &&
V_2 -> V_259 != NULL && V_2 -> V_259 != V_47 )
return 0 ;
}
if ( V_53 -> V_54 == V_187 && V_2 -> V_257 == 0 &&
V_53 -> V_185 . V_76 != V_256 ) {
const struct V_41 * V_260 = V_2 -> V_181 [ 0 ] ;
if ( V_260 != NULL && V_260 -> V_52 . V_47 != NULL )
return 0 ;
V_2 -> V_29 &= ~ V_258 ;
F_20 ( V_2 ) ;
}
return 1 ;
}
static int F_173 ( struct V_1 * V_2 ,
const struct V_46 * V_47 , short * V_261 , T_1 * V_262 )
{
switch ( * V_261 ) {
case V_263 :
* V_261 = 0 ;
case 0 :
break;
default:
return - V_264 ;
}
switch ( * V_262 ) {
case V_265 :
for ( * V_262 = V_266 ; * V_262 < V_2 -> V_179 ;
( * V_262 ) ++ )
if ( F_172 ( V_2 , * V_262 , V_47 ) )
return 0 ;
return - V_264 ;
default:
if ( * V_262 >= V_2 -> V_179 || * V_262 < 0 ||
! F_172 ( V_2 , * V_262 , V_47 ) )
return - V_264 ;
}
return 0 ;
}
static int F_174 ( const struct V_184 * V_53 )
{
int V_267 = 0 ;
int T_6 , V_268 , V_269 = F_175 ( & V_53 -> V_75 ) ;
if ( V_269 == 0 )
return 0 ;
if ( V_269 < 0 ) {
V_267 = 1 ;
V_269 = - V_269 ;
}
T_6 = V_269 * 27 ;
V_268 = ( 3125 << ( 9 + V_270 ) ) - ( T_6 << V_270 ) ;
if ( V_267 )
V_268 += T_6 - 1 ;
V_268 /= T_6 ;
if ( V_268 > V_271 )
V_268 = V_271 ;
F_24 ( L_113 ,
V_269 , V_267 ? 'Y' : 'N' , V_268 ) ;
return V_268 ;
}
static inline void F_176 ( struct V_1 * V_2 )
{
F_16 ( V_2 , F_174 ( & V_2 -> V_259 -> V_53 ) , V_272 ) ;
F_16 ( V_2 , V_2 -> V_259 -> V_4 , V_273 ) ;
V_2 -> V_29 |= V_274 ;
F_19 ( V_2 ) ;
}
static inline void F_177 ( struct V_1 * V_2 )
{
V_2 -> V_29 &= ~ V_274 ;
F_19 ( V_2 ) ;
}
static int F_178 ( struct V_275 * V_276 )
{
struct V_1 * V_2 = (struct V_1 * ) V_276 -> V_277 ;
unsigned long V_278 ;
int V_38 ;
F_24 ( L_114 ) ;
V_2 -> V_200 = V_276 -> V_200 ;
V_2 -> V_179 = V_217 ;
F_142 ( V_2 -> V_90 , V_217 ) ;
F_142 ( V_2 -> V_204 , V_217 ) ;
V_2 -> V_257 = 0 ;
#ifdef F_21
V_2 -> V_192 = 0 ;
#endif
V_2 -> V_259 = NULL ;
memset ( & V_2 -> V_167 , 0 , sizeof V_2 -> V_167 ) ;
F_179 ( & V_2 -> V_162 ) ;
F_179 ( & V_2 -> V_224 ) ;
V_276 -> V_279 . V_280 = 0 ;
V_276 -> V_279 . V_281 = 0 ;
while ( 1 << V_276 -> V_279 . V_281 < V_2 -> V_179 )
V_276 -> V_279 . V_281 ++ ;
V_276 -> V_282 = V_283 ;
if ( ( V_38 = F_165 ( V_2 ) ) != 0 )
goto error;
V_278 = V_2 -> V_10 -> V_284 [ 0 ] . V_13 ;
V_2 -> V_24 = ( T_3 ) F_180 ( V_278 , V_285 ) ;
if ( V_2 -> V_24 == NULL ) {
F_31 (KERN_ERR DEV_LABEL L_115 ) ;
goto V_286;
}
F_23 ( V_2 ) ;
V_2 -> V_27 = F_13 ( V_2 , V_28 ) ;
V_2 -> V_27 &= ~ ( V_287 | V_31 |
V_288 ) ;
V_2 -> V_27 |= F_181 ( V_289 ) ;
F_16 ( V_2 , V_2 -> V_27 | V_287 , V_28 ) ;
F_25 ( 1000 ) ;
F_18 ( V_2 ) ;
V_38 = F_162 ( L_116 ,
F_13 ( V_2 , V_32 ) , & V_2 -> V_290 ) ;
if ( V_38 != 0 )
goto V_291;
if ( ( V_38 = F_60 ( V_2 ) ) != 0 )
goto V_291;
if ( ( V_38 = F_61 ( V_2 ) ) != 0 )
goto V_291;
F_16 ( V_2 , V_2 -> V_27 | V_287 , V_28 ) ;
F_25 ( 1000 ) ;
F_18 ( V_2 ) ;
V_2 -> V_27 |= ( V_292 | V_293 | V_294 ) ;
F_18 ( V_2 ) ;
if ( ( V_38 = F_33 ( V_2 ) ) != 0 )
goto V_291;
V_2 -> V_27 |= V_294 ;
F_18 ( V_2 ) ;
if ( ( V_38 = F_130 ( V_2 ) ) != 0 )
goto V_291;
if ( ( V_38 = F_114 ( V_2 ) ) != 0 )
goto V_295;
V_2 -> V_29 = ( V_2 -> V_179 >= 512 ? V_296 : 0 ) |
V_297 | V_298 ;
F_19 ( V_2 ) ;
F_16 ( V_2 , V_299 , V_300 ) ;
F_16 ( V_2 , 0 , V_272 ) ;
if ( ( V_38 = F_182 ( V_2 -> V_10 -> V_244 , F_161 , V_301 ,
V_302 , V_2 ) ) != 0 ) {
F_31 (KERN_ERR DEV_LABEL L_117 ) ;
goto V_303;
}
F_183 () ;
F_75 ( V_2 , V_193 & ~ ( V_242 | V_243 ) ) ;
V_2 -> V_27 = ( V_2 -> V_27 & ~ V_304 ) |
F_184 ( V_305 ) |
V_292 | V_293 ;
F_18 ( V_2 ) ;
V_2 -> V_124 = F_13 ( V_2 , V_127 ) ;
#ifdef F_21
V_2 -> V_27 |= V_31 ;
F_18 ( V_2 ) ;
#endif
memcpy ( V_276 -> V_306 , F_73 ( V_2 ) , V_307 ) ;
F_155 ( V_2 ) ;
F_31 (KERN_NOTICE DEV_LABEL L_118
L_119 , lanai->number, (int) lanai->pci->revision,
(unsigned long) lanai->base, lanai->pci->irq, atmdev->esi) ;
F_31 (KERN_NOTICE DEV_LABEL L_120
L_121 , lanai->number,
lanai->type==lanai2 ? L_122 : L_123 , (unsigned int) lanai->serialno,
(unsigned int) lanai->serialno, lanai->board_rev) ;
return 0 ;
V_303:
F_118 ( V_2 ) ;
V_295:
F_133 ( V_2 ) ;
V_291:
F_23 ( V_2 ) ;
#ifdef F_21
V_2 -> V_27 = F_13 ( V_2 , V_28 ) | V_31 ;
F_18 ( V_2 ) ;
#endif
F_185 ( V_2 -> V_24 ) ;
V_286:
F_186 ( V_2 -> V_10 ) ;
error:
return V_38 ;
}
static void F_187 ( struct V_275 * V_276 )
{
struct V_1 * V_2 = (struct V_1 * ) V_276 -> V_277 ;
F_31 (KERN_INFO DEV_LABEL L_124 ,
lanai->number) ;
F_158 ( V_2 ) ;
#ifdef F_21
V_2 -> V_27 = F_13 ( V_2 , V_28 ) & ~ V_31 ;
F_18 ( V_2 ) ;
#endif
F_76 ( V_2 , V_193 ) ;
F_188 ( V_2 -> V_10 -> V_244 , V_2 ) ;
F_23 ( V_2 ) ;
#ifdef F_21
V_2 -> V_27 |= V_31 ;
F_18 ( V_2 ) ;
#endif
F_186 ( V_2 -> V_10 ) ;
F_118 ( V_2 ) ;
F_133 ( V_2 ) ;
F_185 ( V_2 -> V_24 ) ;
F_189 ( V_2 ) ;
}
static void F_190 ( struct V_46 * V_47 )
{
struct V_41 * V_42 = (struct V_41 * ) V_47 -> V_277 ;
struct V_1 * V_2 = (struct V_1 * ) V_47 -> V_14 -> V_277 ;
if ( V_42 == NULL )
return;
F_191 ( V_308 , & V_47 -> V_83 ) ;
F_191 ( V_309 , & V_47 -> V_83 ) ;
if ( V_42 -> V_52 . V_47 == V_47 ) {
F_47 ( V_42 ) ;
if ( V_47 -> V_53 . V_54 == V_187 ) {
if ( -- V_2 -> V_257 <= 0 )
F_59 ( V_2 ) ;
} else
F_8 ( & V_42 -> V_52 . V_6 , V_2 -> V_10 ) ;
V_42 -> V_52 . V_47 = NULL ;
}
if ( V_42 -> V_68 . V_47 == V_47 ) {
if ( V_47 == V_2 -> V_259 ) {
if ( V_42 -> V_44 != NULL )
F_177 ( V_2 ) ;
V_2 -> V_259 = NULL ;
}
F_48 ( V_2 , V_42 ) ;
F_8 ( & V_42 -> V_68 . V_6 , V_2 -> V_10 ) ;
V_42 -> V_68 . V_47 = NULL ;
}
if ( -- V_42 -> V_310 == 0 ) {
F_128 ( V_2 , V_42 ) ;
F_189 ( V_42 ) ;
}
V_47 -> V_277 = NULL ;
F_191 ( V_311 , & V_47 -> V_83 ) ;
}
static int F_192 ( struct V_46 * V_47 )
{
struct V_1 * V_2 ;
struct V_41 * V_42 ;
int V_38 = 0 ;
int V_4 = V_47 -> V_4 ;
short V_312 = V_47 -> V_312 ;
if ( ( F_193 ( V_309 , & V_47 -> V_83 ) ) ||
( V_312 == V_313 ) || ( V_4 == V_314 ) )
return - V_255 ;
V_2 = (struct V_1 * ) V_47 -> V_14 -> V_277 ;
V_38 = F_173 ( V_2 , V_47 , & V_312 , & V_4 ) ;
if ( F_22 ( V_38 != 0 ) )
goto V_174;
F_194 ( V_311 , & V_47 -> V_83 ) ;
if ( V_47 -> V_53 . V_54 != V_187 && V_47 -> V_53 . V_54 != V_55 )
return - V_255 ;
F_24 ( V_302 L_125 , V_2 -> V_200 ,
( int ) V_312 , V_4 ) ;
V_42 = V_2 -> V_181 [ V_4 ] ;
if ( V_42 == NULL ) {
V_42 = F_121 () ;
if ( F_22 ( V_42 == NULL ) )
return - V_95 ;
V_47 -> V_277 = V_42 ;
}
V_42 -> V_310 ++ ;
if ( V_47 -> V_53 . V_185 . V_76 != V_256 ) {
F_6 ( V_42 -> V_52 . V_47 == NULL , L_126 ,
V_4 ) ;
if ( V_47 -> V_53 . V_54 == V_187 ) {
if ( V_2 -> V_257 == 0 )
V_38 = F_58 ( V_2 ) ;
} else
V_38 = F_125 (
V_2 , V_42 , & V_47 -> V_53 ) ;
if ( F_22 ( V_38 != 0 ) )
goto V_315;
V_42 -> V_52 . V_47 = V_47 ;
V_42 -> V_167 . V_176 = 0 ;
V_42 -> V_167 . T_6 . V_172 . V_173 = 0 ;
V_42 -> V_167 . T_6 . V_172 . V_210 = 0 ;
V_42 -> V_167 . T_6 . V_172 . V_212 = 0 ;
V_42 -> V_167 . T_6 . V_172 . V_213 = 0 ;
if ( V_47 -> V_53 . V_54 == V_187 )
V_2 -> V_257 ++ ;
}
if ( V_47 -> V_53 . V_75 . V_76 != V_256 ) {
F_6 ( V_42 -> V_68 . V_47 == NULL , L_127 ,
V_4 ) ;
V_38 = F_126 ( V_2 , V_42 , & V_47 -> V_53 ) ;
if ( F_22 ( V_38 != 0 ) )
goto V_315;
V_42 -> V_68 . V_47 = V_47 ;
if ( V_47 -> V_53 . V_75 . V_76 == V_77 ) {
F_6 ( V_2 -> V_259 == NULL ,
L_128 , V_4 ) ;
V_2 -> V_259 = V_47 ;
}
}
F_127 ( V_2 , V_42 , V_4 ) ;
F_94 () ;
if ( V_47 == V_42 -> V_52 . V_47 )
F_41 ( V_42 ) ;
if ( V_47 == V_42 -> V_68 . V_47 ) {
F_45 ( V_42 ) ;
if ( V_2 -> V_259 == V_47 )
F_176 ( V_2 ) ;
}
F_194 ( V_308 , & V_47 -> V_83 ) ;
return 0 ;
V_315:
F_190 ( V_47 ) ;
V_174:
return V_38 ;
}
static int F_195 ( struct V_46 * V_47 , struct V_48 * V_49 )
{
struct V_41 * V_42 = (struct V_41 * ) V_47 -> V_277 ;
struct V_1 * V_2 = (struct V_1 * ) V_47 -> V_14 -> V_277 ;
unsigned long V_83 ;
if ( F_22 ( V_42 == NULL || V_42 -> V_44 == NULL ||
V_42 -> V_68 . V_47 != V_47 ) )
goto V_316;
#ifdef F_72
if ( F_22 ( V_49 == NULL ) ) {
F_24 ( L_129 , V_47 -> V_4 ) ;
goto V_316;
}
if ( F_22 ( V_2 == NULL ) ) {
F_24 ( L_130 , V_47 -> V_4 ) ;
goto V_316;
}
#endif
F_111 ( V_49 ) -> V_177 = V_47 ;
switch ( V_47 -> V_53 . V_54 ) {
case V_55 :
F_51 ( & V_89 , V_83 ) ;
F_100 ( V_2 , V_42 , V_49 ) ;
F_53 ( & V_89 , V_83 ) ;
return 0 ;
case V_187 :
if ( F_22 ( V_49 -> V_150 != V_189 - 1 ) )
goto V_316;
F_196 ( ( V_19 * ) V_49 -> V_103 ) ;
F_51 ( & V_89 , V_83 ) ;
F_104 ( V_2 , V_42 , V_49 ) ;
F_53 ( & V_89 , V_83 ) ;
return 0 ;
}
F_24 ( L_131 , ( int ) V_47 -> V_53 . V_54 ,
V_47 -> V_4 ) ;
V_316:
F_39 ( V_47 , V_49 ) ;
return - V_255 ;
}
static int F_197 ( struct V_46 * V_47 ,
struct V_184 * V_53 , int V_83 )
{
return - V_252 ;
}
static int F_198 ( struct V_275 * V_276 , T_11 * V_151 , char * V_317 )
{
struct V_1 * V_2 = (struct V_1 * ) V_276 -> V_277 ;
T_11 V_318 = * V_151 ;
struct V_41 * V_42 ;
if ( V_318 -- == 0 )
return sprintf ( V_317 , V_302 L_132
L_133 ,
V_276 -> V_200 , V_2 -> type == V_319 ? L_122 : L_123 ,
( unsigned int ) V_2 -> V_98 ,
( unsigned int ) V_2 -> V_99 , V_2 -> V_179 ) ;
if ( V_318 -- == 0 )
return sprintf ( V_317 , L_134 ,
V_2 -> V_290 , ( int ) V_2 -> V_10 -> V_320 ) ;
if ( V_318 -- == 0 )
return sprintf ( V_317 , L_135 ,
& V_2 -> V_96 [ V_97 ] ) ;
if ( V_318 -- == 0 )
return sprintf ( V_317 , L_136
L_137 , ( V_2 -> V_124 & V_129 ) ? 1 : 0 ,
( V_2 -> V_124 & V_130 ) ? 1 : 0 ,
( V_2 -> V_124 & V_131 ) ? 1 : 0 ,
( V_2 -> V_124 & V_132 ) ? 1 : 0 ) ;
if ( V_318 -- == 0 )
return sprintf ( V_317 , L_138
L_139 , F_7 ( & V_2 -> V_196 ) ,
V_2 -> V_257 ? F_7 ( & V_2 -> V_93 ) : 0 ) ;
if ( V_318 -- == 0 ) {
F_143 ( V_2 ) ;
return sprintf ( V_317 , L_140
L_141 ,
V_2 -> V_167 . V_211 , V_2 -> V_167 . V_222 ,
V_2 -> V_167 . V_221 , V_2 -> V_167 . V_220 ) ;
}
if ( V_318 -- == 0 )
return sprintf ( V_317 , L_142
L_143 ,
V_2 -> V_167 . V_321 ,
V_2 -> V_167 . V_322 ,
V_2 -> V_167 . V_323 ) ;
if ( V_318 -- == 0 )
return sprintf ( V_317 , L_144
L_145 , V_2 -> V_167 . V_324 ,
V_2 -> V_167 . V_325 ) ;
if ( V_318 -- == 0 )
return sprintf ( V_317 , L_146
L_147 , V_2 -> V_167 . V_203 ,
V_2 -> V_167 . V_202 ,
V_2 -> V_167 . V_205 ) ;
if ( V_318 -- == 0 )
return sprintf ( V_317 , L_148 ,
V_2 -> V_167 . V_239 , V_2 -> V_167 . V_195 ) ;
F_136 ( & V_89 ) ;
for (; ; V_318 ++ ) {
if ( V_318 >= V_217 ) {
V_318 = 0 ;
goto V_174;
}
if ( ( V_42 = V_2 -> V_181 [ V_318 ] ) != NULL )
break;
( * V_151 ) ++ ;
}
V_318 = sprintf ( V_317 , L_149 , ( T_1 ) V_318 ,
V_42 -> V_310 , V_42 -> V_167 . V_176 ) ;
if ( V_42 -> V_52 . V_47 != NULL ) {
V_318 += sprintf ( & V_317 [ V_318 ] , L_150 ,
V_42 -> V_52 . V_47 -> V_53 . V_54 == V_55 ? 5 : 0 ) ;
if ( V_42 -> V_52 . V_47 -> V_53 . V_54 == V_55 )
V_318 += sprintf ( & V_317 [ V_318 ] , L_151
L_152
L_153 ,
F_7 ( & V_42 -> V_52 . V_6 ) ,
V_42 -> V_167 . T_6 . V_172 . V_173 ,
V_42 -> V_167 . T_6 . V_172 . V_210 ,
V_42 -> V_167 . T_6 . V_172 . V_212 ,
V_42 -> V_167 . T_6 . V_172 . V_213 ) ;
}
if ( V_42 -> V_68 . V_47 != NULL )
V_318 += sprintf ( & V_317 [ V_318 ] , L_154
L_155 ,
V_42 -> V_68 . V_47 -> V_53 . V_54 == V_55 ? 5 : 0 ,
F_7 ( & V_42 -> V_68 . V_6 ) ,
V_42 -> V_68 . V_47 == V_2 -> V_259 ? 'C' : 'U' ,
F_84 ( V_42 ) ? 'Y' : 'N' ) ;
V_317 [ V_318 ++ ] = '\n' ;
V_317 [ V_318 ] = '\0' ;
V_174:
F_137 ( & V_89 ) ;
return V_318 ;
}
static int F_199 ( struct V_9 * V_10 ,
const struct V_326 * V_327 )
{
struct V_1 * V_2 ;
struct V_275 * V_276 ;
int V_38 ;
V_2 = F_200 ( sizeof( * V_2 ) , V_16 ) ;
if ( V_2 == NULL ) {
F_31 (KERN_ERR DEV_LABEL
L_156 ) ;
return - V_95 ;
}
V_276 = F_201 ( V_302 , & V_10 -> V_14 , & V_328 , - 1 , NULL ) ;
if ( V_276 == NULL ) {
F_31 (KERN_ERR DEV_LABEL
L_157 ) ;
F_189 ( V_2 ) ;
return - V_252 ;
}
V_276 -> V_277 = V_2 ;
V_2 -> V_10 = V_10 ;
V_2 -> type = (enum V_329 ) V_327 -> V_330 ;
V_38 = F_178 ( V_276 ) ;
if ( V_38 != 0 ) {
F_24 ( L_158 , - V_38 ) ;
F_202 ( V_276 ) ;
F_189 ( V_2 ) ;
}
return V_38 ;
}
