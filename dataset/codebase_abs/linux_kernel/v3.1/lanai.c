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
V_6 -> V_13 = F_5 ( V_10 , V_11 , & V_6 -> V_14 ) ;
if ( V_6 -> V_13 != NULL ) {
F_6 ( ( V_6 -> V_14 & ~ 0xFFFFFF00 ) == 0 ,
L_1 ,
( unsigned long ) V_6 -> V_14 ) ;
V_6 -> V_15 = V_6 -> V_13 ;
V_6 -> V_16 = ( V_17 * )
( & ( ( unsigned char * ) V_6 -> V_13 ) [ V_11 ] ) ;
memset ( V_6 -> V_13 , 0 , V_11 ) ;
break;
}
V_11 /= 2 ;
} while ( V_11 >= V_8 );
}
static inline T_2 F_7 ( const struct V_5 * V_6 )
{
return ( ( unsigned long ) V_6 -> V_16 ) - ( ( unsigned long ) V_6 -> V_13 ) ;
}
static void F_8 ( struct V_5 * V_6 ,
struct V_9 * V_10 )
{
if ( V_6 -> V_13 != NULL ) {
F_9 ( V_10 , F_7 ( V_6 ) ,
V_6 -> V_13 , V_6 -> V_14 ) ;
V_6 -> V_13 = V_6 -> V_16 = V_6 -> V_15 = NULL ;
}
}
static int F_10 ( const struct V_5 * V_6 )
{
int V_18 = F_11 ( F_7 ( V_6 ) ) + ( V_19 - 10 ) ;
if ( V_18 > 7 )
V_18 = 7 ;
return V_18 ;
}
static inline T_3 F_12 ( const struct V_1 * V_2 ,
enum V_20 V_21 )
{
return V_2 -> V_22 + V_21 ;
}
static inline V_17 F_13 ( const struct V_1 * V_2 ,
enum V_20 V_21 )
{
V_17 V_23 ;
V_23 = F_14 ( F_12 ( V_2 , V_21 ) ) ;
F_15 ( L_2 , ( unsigned int ) V_2 -> V_22 ,
( int ) V_21 , V_23 ) ;
return V_23 ;
}
static inline void F_16 ( const struct V_1 * V_2 , V_17 V_24 ,
enum V_20 V_21 )
{
F_15 ( L_3 , ( unsigned int ) V_2 -> V_22 ,
( int ) V_21 , V_24 ) ;
F_17 ( V_24 , F_12 ( V_2 , V_21 ) ) ;
}
static inline void F_18 ( const struct V_1 * V_2 )
{
F_16 ( V_2 , V_2 -> V_25 , V_26 ) ;
}
static inline void F_19 ( const struct V_1 * V_2 )
{
F_16 ( V_2 , V_2 -> V_27 , V_28 ) ;
}
static inline void F_20 ( const struct V_1 * V_2 )
{
#ifdef F_21
if ( F_22 ( ( V_2 -> V_25 & V_29 ) != 0 ) )
return;
#endif
F_19 ( V_2 ) ;
}
static inline void F_23 ( const struct V_1 * V_2 )
{
F_24 ( L_4 ) ;
F_16 ( V_2 , 0 , V_30 ) ;
F_25 ( 5 ) ;
}
static inline T_3 F_26 ( const struct V_1 * V_2 , int V_31 )
{
return V_2 -> V_22 + V_32 + V_31 ;
}
static inline V_17 F_27 ( const struct V_1 * V_2 , int V_31 )
{
return F_14 ( F_26 ( V_2 , V_31 ) ) ;
}
static inline void F_28 ( const struct V_1 * V_2 ,
V_17 V_24 , int V_31 )
{
F_17 ( V_24 , F_26 ( V_2 , V_31 ) ) ;
}
static int T_4 F_29 ( const struct V_1 * V_2 ,
int V_31 , V_17 V_33 )
{
V_17 V_34 ;
F_28 ( V_2 , V_33 , V_31 ) ;
V_34 = F_27 ( V_2 , V_31 ) ;
if ( F_30 ( V_34 == V_33 ) )
return 0 ;
F_31 (KERN_ERR DEV_LABEL
L_5 ,
lanai->number, offset,
(unsigned int) pattern, (unsigned int) readback) ;
return - V_35 ;
}
static int T_4 F_32 ( const struct V_1 * V_2 , V_17 V_33 )
{
int V_31 , V_36 = 0 ;
for ( V_31 = 0 ; V_31 < V_37 && V_36 == 0 ; V_31 += 4 )
V_36 = F_29 ( V_2 , V_31 , V_33 ) ;
return V_36 ;
}
static int T_4 F_33 ( const struct V_1 * V_2 )
{
#ifdef F_34
int V_36 ;
F_24 ( L_6 ) ;
if ( ( V_36 = F_32 ( V_2 , 0x5555 ) ) != 0 )
return V_36 ;
if ( ( V_36 = F_32 ( V_2 , 0xAAAA ) ) != 0 )
return V_36 ;
#endif
F_24 ( L_7 ) ;
return F_32 ( V_2 , 0x0000 ) ;
}
static inline T_3 F_35 ( const struct V_1 * V_2 ,
T_1 V_4 )
{
return F_26 ( V_2 , V_4 * V_38 ) ;
}
static inline V_17 F_36 ( const struct V_39 * V_40 ,
enum V_41 V_31 )
{
V_17 V_24 ;
F_6 ( V_40 -> V_42 != NULL , L_8 ) ;
V_24 = F_14 ( V_40 -> V_42 + V_31 ) ;
F_15 ( L_9 ,
V_40 -> V_4 , ( int ) V_31 , V_24 ) ;
return V_24 ;
}
static inline void F_37 ( const struct V_39 * V_40 ,
V_17 V_24 , enum V_41 V_31 )
{
F_6 ( V_40 -> V_42 != NULL , L_10 ) ;
F_6 ( ( V_24 & ~ 0xFFFF ) == 0 ,
L_11 ,
( unsigned int ) V_24 , V_40 -> V_4 , ( unsigned int ) V_31 ) ;
F_15 ( L_12 ,
V_40 -> V_4 , ( unsigned int ) V_31 , ( unsigned int ) V_24 ) ;
F_17 ( V_24 , V_40 -> V_42 + V_31 ) ;
}
static inline int F_38 ( int V_11 )
{
int V_43 = ( V_11 + 8 + 47 ) / 48 ;
return V_43 * 48 ;
}
static inline int F_39 ( int V_44 )
{
int V_43 = V_44 / 48 ;
return V_43 * 48 ;
}
static inline void F_40 ( struct V_45 * V_46 , struct V_47 * V_48 )
{
if ( V_46 -> V_49 != NULL )
V_46 -> V_49 ( V_46 , V_48 ) ;
else
F_41 ( V_48 ) ;
}
static void F_42 ( const struct V_39 * V_40 )
{
V_17 V_50 ;
if ( V_40 -> V_51 . V_46 -> V_52 . V_53 == V_54 ) {
T_5 V_14 = V_40 -> V_51 . V_6 . V_14 ;
F_37 ( V_40 , 0xFFFF , V_55 ) ;
F_37 ( V_40 , 0xFFFF , V_56 ) ;
F_37 ( V_40 , 0 , V_57 ) ;
F_37 ( V_40 , 0 , V_58 ) ;
F_37 ( V_40 , 0 , V_59 ) ;
F_37 ( V_40 , ( V_14 >> 16 ) & 0xFFFF , V_60 ) ;
V_50 = ( ( V_14 >> 8 ) & 0xFF ) |
F_43 ( F_10 ( & V_40 -> V_51 . V_6 ) ) |
F_44 ( V_61 ) |
F_45 ( V_62 ) ;
} else
V_50 = F_44 ( V_63 ) |
V_64 |
F_45 ( V_65 ) ;
F_37 ( V_40 , V_50 , V_66 ) ;
}
static void F_46 ( const struct V_39 * V_40 )
{
T_5 V_14 = V_40 -> V_67 . V_6 . V_14 ;
F_37 ( V_40 , 0 , V_68 ) ;
F_37 ( V_40 , 0xFFFF , V_69 ) ;
F_37 ( V_40 , 0xFFFF , V_70 ) ;
F_37 ( V_40 , 0 , V_71 ) ;
F_37 ( V_40 , 0 , V_72 ) ;
F_37 ( V_40 , 0 , V_73 ) ;
F_37 ( V_40 ,
( V_40 -> V_67 . V_46 -> V_52 . V_74 . V_75 == V_76 ) ?
V_77 | V_40 -> V_4 : 0 , V_78 ) ;
F_37 ( V_40 , ( V_14 >> 16 ) & 0xFFFF , V_79 ) ;
F_37 ( V_40 ,
( ( V_14 >> 8 ) & 0xFF ) |
F_47 ( F_10 ( & V_40 -> V_67 . V_6 ) ) ,
V_80 ) ;
}
static void F_48 ( const struct V_39 * V_40 )
{
if ( V_40 -> V_42 == NULL )
return;
F_37 ( V_40 ,
F_44 ( V_61 ) |
F_45 ( V_81 ) , V_66 ) ;
F_25 ( 15 ) ;
F_37 ( V_40 , 0 , V_60 ) ;
F_37 ( V_40 , 0 , V_55 ) ;
F_37 ( V_40 , 0 , V_56 ) ;
F_37 ( V_40 , 0 , V_57 ) ;
F_37 ( V_40 , 0 , V_58 ) ;
F_37 ( V_40 , 0 , V_59 ) ;
}
static void F_49 ( struct V_1 * V_2 ,
struct V_39 * V_40 )
{
struct V_47 * V_48 ;
unsigned long V_82 , V_83 ;
int V_84 , V_85 , V_86 = - 1 ;
F_6 ( ! F_50 () ,
L_13 ) ;
if ( V_40 -> V_42 == NULL )
return;
while ( ( V_48 = F_51 ( & V_40 -> V_67 . V_87 ) ) != NULL )
F_40 ( V_40 -> V_67 . V_46 , V_48 ) ;
F_52 ( & V_88 , V_82 ) ;
F_53 ( V_40 -> V_4 , V_2 -> V_89 ) ;
F_54 ( & V_88 , V_82 ) ;
V_83 = V_90 +
( ( ( F_7 ( & V_40 -> V_67 . V_6 ) / 1024 ) * V_91 ) >> 7 ) ;
V_85 = F_55 ( F_36 ( V_40 , V_73 ) ) ;
for (; ; ) {
V_84 = F_56 ( F_36 ( V_40 , V_71 ) ) ;
if ( V_84 == V_85 &&
( V_40 -> V_67 . V_46 -> V_52 . V_74 . V_75 != V_76 ||
( F_36 ( V_40 , V_78 ) &
V_77 ) == 0 ) )
break;
if ( V_84 != V_86 ) {
V_86 = V_84 ;
V_83 += V_91 / 10 ;
}
if ( F_22 ( F_57 ( V_90 , V_83 ) ) ) {
F_31 (KERN_ERR DEV_LABEL L_14
L_15 ,
lvcc->tx.atmvcc->dev->number, lvcc->vci) ;
F_24 ( L_16 , V_84 , V_85 ) ;
break;
}
F_58 ( 40 ) ;
}
F_37 ( V_40 , 0 , V_71 ) ;
F_37 ( V_40 , 0 , V_73 ) ;
F_37 ( V_40 , 0 , V_72 ) ;
F_37 ( V_40 , 0 , V_69 ) ;
F_37 ( V_40 , 0 , V_70 ) ;
F_37 ( V_40 , 0 , V_79 ) ;
F_37 ( V_40 , 0 , V_80 ) ;
}
static inline int F_59 ( struct V_1 * V_2 )
{
F_24 ( L_17 ) ;
F_4 ( & V_2 -> V_92 , V_93 , 80 ,
V_2 -> V_10 ) ;
return ( V_2 -> V_92 . V_13 == NULL ) ? - V_94 : 0 ;
}
static inline void F_60 ( struct V_1 * V_2 )
{
F_24 ( L_18 ) ;
F_8 ( & V_2 -> V_92 , V_2 -> V_10 ) ;
}
static int T_4 F_61 ( struct V_1 * V_2 )
{
F_31 (KERN_INFO DEV_LABEL L_19 ,
lanai->number) ;
memset ( & V_2 -> V_95 [ V_96 ] , 0 , 6 ) ;
return 0 ;
}
static int T_4 F_62 ( struct V_1 * V_2 )
{
V_2 -> V_97 = 0 ;
V_2 -> V_98 = V_99 ;
return 0 ;
}
static int T_4 F_61 ( struct V_1 * V_2 )
{
int V_100 , V_101 ;
T_6 V_102 ;
V_17 V_103 ;
#define F_63 ( T_7 ) do { lanai->conf1 = x; conf1_write(lanai); \
} while (0)
#define F_64 () set_config1(lanai->conf1 | CONFIG1_PROMCLK)
#define F_65 () set_config1(lanai->conf1 &~ CONFIG1_PROMCLK)
#define F_66 () set_config1(lanai->conf1 | CONFIG1_PROMDATA)
#define F_67 () set_config1(lanai->conf1 &~ CONFIG1_PROMDATA)
#define F_68 () do { data_h(); clock_h(); udelay(5); } while (0)
#define F_69 () (reg_read(lanai, Status_Reg) & STATUS_PROMDATA)
#define F_70 () do { data_l(); udelay(5); clock_h(); udelay(5); \
data_h(); udelay(5); } while (0)
F_66 () ; F_64 () ; F_25 ( 5 ) ;
for ( V_101 = 0 ; V_101 < V_104 ; V_101 ++ ) {
V_102 = ( V_101 << 1 ) | 1 ;
F_67 () ; F_25 ( 5 ) ;
F_65 () ; F_25 ( 5 ) ;
for ( V_100 = 128 ; V_100 != 0 ; V_100 >>= 1 ) {
V_103 = ( V_2 -> V_25 & ~ V_105 ) |
( ( V_102 & V_100 ) ? V_105 : 0 ) ;
if ( V_2 -> V_25 != V_103 ) {
F_63 ( V_103 ) ;
F_25 ( 5 ) ;
}
F_64 () ; F_25 ( 5 ) ; F_65 () ; F_25 ( 5 ) ;
}
F_66 () ; F_64 () ; F_25 ( 5 ) ;
if ( F_69 () != 0 )
goto error;
F_65 () ; F_25 ( 5 ) ;
for ( V_102 = 0 , V_100 = 7 ; V_100 >= 0 ; V_100 -- ) {
F_66 () ; F_64 () ; F_25 ( 5 ) ;
V_102 = ( V_102 << 1 ) | ! ! F_69 () ;
F_65 () ; F_25 ( 5 ) ;
}
F_66 () ; F_64 () ; F_25 ( 5 ) ;
if ( F_69 () == 0 )
goto error;
F_65 () ; F_25 ( 5 ) ;
F_70 () ;
V_2 -> V_95 [ V_101 ] = V_102 ;
F_24 ( L_20 ,
( unsigned int ) V_101 , ( unsigned int ) V_102 ) ;
}
return 0 ;
error:
F_65 () ; F_25 ( 5 ) ;
F_70 () ;
F_31 (KERN_ERR DEV_LABEL L_21 ,
lanai->number, address) ;
return - V_35 ;
#undef F_63
#undef F_64
#undef F_65
#undef F_66
#undef F_67
#undef F_68
#undef F_69
#undef F_70
}
static inline V_17 F_71 ( const struct V_1 * V_2 , int V_101 )
{
return F_72 ( ( const V_17 * ) & V_2 -> V_95 [ V_101 ] ) ;
}
static int T_4 F_62 ( struct V_1 * V_2 )
{
int V_100 , V_106 ;
V_17 V_107 ;
const T_6 * V_108 = V_2 -> V_95 ;
#ifdef F_73
for ( V_100 = V_109 ;
V_100 < ( V_109 + V_110 ) ; V_100 ++ )
if ( V_108 [ V_100 ] < 0x20 || V_108 [ V_100 ] > 0x7E )
break;
if ( V_100 != V_109 &&
V_100 != V_109 + V_110 && V_108 [ V_100 ] == '\0' )
F_24 ( L_22 ,
( char * ) & V_108 [ V_109 ] ) ;
else
F_24 ( L_23 ) ;
#endif
for ( V_100 = V_106 = 0 ; V_100 < V_111 ; V_100 ++ )
V_106 += V_108 [ V_100 ] ;
V_106 &= 0xFF ;
if ( V_106 != V_108 [ V_111 ] ) {
F_31 (KERN_ERR DEV_LABEL L_24
L_25 , lanai->number,
(unsigned int) s, (unsigned int) e[EEPROM_CHECKSUM]) ;
return - V_35 ;
}
V_106 ^= 0xFF ;
if ( V_106 != V_108 [ V_112 ] ) {
F_31 (KERN_ERR DEV_LABEL L_26
L_27 , lanai->number,
(unsigned int) s, (unsigned int) e[EEPROM_CHECKSUM_REV]) ;
return - V_35 ;
}
for ( V_100 = 0 ; V_100 < 6 ; V_100 ++ )
if ( ( V_108 [ V_96 + V_100 ] ^ V_108 [ V_113 + V_100 ] ) != 0xFF ) {
F_31 (KERN_ERR DEV_LABEL
L_28
L_29 , lanai->number,
(unsigned int) e[EEPROM_MAC + i],
(unsigned int) e[EEPROM_MAC_REV + i]) ;
return - V_35 ;
}
F_24 ( L_30 , & V_108 [ V_96 ] ) ;
V_2 -> V_97 = F_71 ( V_2 , V_114 ) ;
V_107 = F_71 ( V_2 , V_115 ) ;
if ( ( V_2 -> V_97 ^ V_107 ) != 0xFFFFFFFF ) {
F_31 (KERN_ERR DEV_LABEL L_31
L_32 , lanai->number,
(unsigned int) lanai->serialno, (unsigned int) v) ;
return - V_35 ;
}
F_24 ( L_33 , ( unsigned int ) V_2 -> V_97 ) ;
V_2 -> V_98 = F_71 ( V_2 , V_116 ) ;
V_107 = F_71 ( V_2 , V_117 ) ;
if ( ( V_2 -> V_98 ^ V_107 ) != 0xFFFFFFFF ) {
F_31 (KERN_ERR DEV_LABEL L_34
L_32 , lanai->number,
lanai->magicno, v) ;
return - V_35 ;
}
F_24 ( L_35 , V_2 -> V_98 ) ;
if ( V_2 -> V_98 != V_99 )
F_31 (KERN_WARNING DEV_LABEL L_36
L_37 ,
lanai->number, (unsigned int) lanai->magicno,
(unsigned int) EEPROM_MAGIC_VALUE) ;
return 0 ;
}
static inline const T_6 * F_74 ( const struct V_1 * V_2 )
{
return & V_2 -> V_95 [ V_96 ] ;
}
static inline V_17 F_75 ( const struct V_1 * V_2 )
{
return F_13 ( V_2 , V_118 ) ;
}
static inline void F_76 ( const struct V_1 * V_2 , V_17 V_100 )
{
F_16 ( V_2 , V_100 , V_119 ) ;
}
static inline void F_77 ( const struct V_1 * V_2 , V_17 V_100 )
{
F_16 ( V_2 , V_100 , V_120 ) ;
}
static void F_78 ( int V_121 , const char * V_122 , int V_123 )
{
static const char * V_124 [ 2 ] = { L_38 , L_39 } ;
F_31 (KERN_INFO DEV_LABEL L_40 ,
itf, name, onoff[!status]) ;
}
static void F_79 ( struct V_1 * V_2 )
{
V_17 V_125 = F_13 ( V_2 , V_126 ) ;
V_17 V_127 = V_125 ^ V_2 -> V_123 ;
V_2 -> V_123 = V_125 ;
#define V_108 ( T_8 , V_122 ) \
if (changes & flag) \
status_message(lanai->number, name, new & flag)
V_108 ( V_128 , L_41 ) ;
V_108 ( V_129 , L_42 ) ;
V_108 ( V_130 , L_43 ) ;
V_108 ( V_131 , L_44 ) ;
#undef V_108
}
static void F_80 ( int V_121 , const char * V_122 )
{
F_31 (KERN_INFO DEV_LABEL L_45 , itf, name) ;
}
static void F_81 ( struct V_1 * V_2 , int V_132 )
{
T_9 V_106 ;
int V_36 ;
V_36 = F_82 ( V_2 -> V_10 , V_133 , & V_106 ) ;
if ( V_36 != V_134 ) {
F_31 (KERN_ERR DEV_LABEL L_46
L_47 , lanai->number, result) ;
return;
}
V_106 &= V_135 | V_136 |
V_137 | V_138 |
V_139 | V_140 ;
if ( V_106 == 0 )
return;
V_36 = F_83 ( V_2 -> V_10 , V_133 , V_106 ) ;
if ( V_36 != V_134 )
F_31 (KERN_ERR DEV_LABEL L_48
L_47 , lanai->number, result) ;
if ( V_132 )
return;
#define V_108 ( T_8 , V_122 , T_10 ) \
if (s & flag) { \
pcistatus_got(lanai->number, name); \
++lanai->stats.pcierr_##stat; \
}
V_108 ( V_135 , L_49 , V_141 ) ;
V_108 ( V_136 , L_50 , V_142 ) ;
V_108 ( V_137 , L_51 , V_143 ) ;
V_108 ( V_138 , L_52 , V_144 ) ;
V_108 ( V_139 , L_53 , V_145 ) ;
V_108 ( V_140 , L_54 , V_146 ) ;
#undef V_108
}
static inline int F_84 ( const struct V_39 * V_40 , int V_147 )
{
int V_148 ;
V_148 = V_147 * 16 ;
V_148 -= ( ( unsigned long ) V_40 -> V_67 . V_6 . V_15 ) -
( ( unsigned long ) V_40 -> V_67 . V_6 . V_13 ) ;
V_148 -= 16 ;
if ( V_148 < 0 )
V_148 += F_7 ( & V_40 -> V_67 . V_6 ) ;
return V_148 ;
}
static inline int F_85 ( const struct V_39 * V_40 )
{
return ! F_86 ( & V_40 -> V_67 . V_87 ) ;
}
static inline void F_87 ( struct V_39 * V_40 ,
V_17 V_82 , int V_149 )
{
int V_150 ;
F_6 ( ( ( ( unsigned long ) V_40 -> V_67 . V_6 . V_15 ) & 15 ) == 0 ,
L_55 , V_40 -> V_67 . V_6 . V_15 ) ;
V_40 -> V_67 . V_6 . V_15 += 4 ;
V_150 = ( ( unsigned char * ) V_40 -> V_67 . V_6 . V_15 ) -
( unsigned char * ) V_40 -> V_67 . V_6 . V_13 ;
F_6 ( ( V_150 & ~ 0x0001FFF0 ) == 0 ,
L_56
L_57 , V_150 , V_40 -> V_4 ,
V_40 -> V_67 . V_6 . V_13 , V_40 -> V_67 . V_6 . V_15 , V_40 -> V_67 . V_6 . V_16 ) ;
V_150 = ( V_150 + V_149 ) & ( F_7 ( & V_40 -> V_67 . V_6 ) - 1 ) ;
F_6 ( ( V_150 & ~ 0x0001FFF0 ) == 0 ,
L_58
L_57 , V_150 , V_40 -> V_4 ,
V_40 -> V_67 . V_6 . V_13 , V_40 -> V_67 . V_6 . V_15 , V_40 -> V_67 . V_6 . V_16 ) ;
V_40 -> V_67 . V_6 . V_15 [ - 1 ] =
F_88 ( V_151 | V_152 |
( ( V_40 -> V_67 . V_46 -> V_153 & V_154 ) ?
V_155 : 0 ) | V_82 | V_150 >> 4 ) ;
if ( V_40 -> V_67 . V_6 . V_15 >= V_40 -> V_67 . V_6 . V_16 )
V_40 -> V_67 . V_6 . V_15 = V_40 -> V_67 . V_6 . V_13 ;
}
static inline void F_89 ( struct V_39 * V_40 ,
int V_149 , int V_156 , int V_157 )
{
F_6 ( ( ( ( unsigned long ) V_40 -> V_67 . V_6 . V_15 ) & 15 ) == 8 ,
L_59 , V_40 -> V_67 . V_6 . V_15 ) ;
V_40 -> V_67 . V_6 . V_15 += 2 ;
V_40 -> V_67 . V_6 . V_15 [ - 2 ] = F_90 ( ( V_157 << 24 ) | ( V_156 << 16 ) | V_149 ) ;
if ( V_40 -> V_67 . V_6 . V_15 >= V_40 -> V_67 . V_6 . V_16 )
V_40 -> V_67 . V_6 . V_15 = V_40 -> V_67 . V_6 . V_13 ;
}
static inline void F_91 ( struct V_39 * V_40 ,
const unsigned char * V_158 , int V_159 )
{
unsigned char * V_108 ;
int V_160 ;
V_108 = ( ( unsigned char * ) V_40 -> V_67 . V_6 . V_15 ) + V_159 ;
V_160 = V_108 - ( unsigned char * ) V_40 -> V_67 . V_6 . V_16 ;
if ( V_160 < 0 )
V_160 = 0 ;
memcpy ( V_40 -> V_67 . V_6 . V_15 , V_158 , V_159 - V_160 ) ;
if ( V_160 != 0 ) {
memcpy ( V_40 -> V_67 . V_6 . V_13 , V_158 + V_159 - V_160 , V_160 ) ;
V_108 = ( ( unsigned char * ) V_40 -> V_67 . V_6 . V_13 ) + V_160 ;
}
V_40 -> V_67 . V_6 . V_15 = ( V_17 * ) V_108 ;
}
static inline void F_92 ( struct V_39 * V_40 , int V_159 )
{
unsigned char * V_108 ;
int V_160 ;
if ( V_159 == 0 )
return;
V_108 = ( ( unsigned char * ) V_40 -> V_67 . V_6 . V_15 ) + V_159 ;
V_160 = V_108 - ( unsigned char * ) V_40 -> V_67 . V_6 . V_16 ;
if ( V_160 < 0 )
V_160 = 0 ;
memset ( V_40 -> V_67 . V_6 . V_15 , 0 , V_159 - V_160 ) ;
if ( V_160 != 0 ) {
memset ( V_40 -> V_67 . V_6 . V_13 , 0 , V_160 ) ;
V_108 = ( ( unsigned char * ) V_40 -> V_67 . V_6 . V_13 ) + V_160 ;
}
V_40 -> V_67 . V_6 . V_15 = ( V_17 * ) V_108 ;
}
static inline void F_93 ( struct V_1 * V_2 ,
const struct V_39 * V_40 )
{
int V_100 , V_15 = ( ( unsigned char * ) V_40 -> V_67 . V_6 . V_15 ) -
( unsigned char * ) V_40 -> V_67 . V_6 . V_13 ;
F_6 ( ( V_15 & ~ 0x0001FFF0 ) == 0 ,
L_60 ,
V_15 , V_40 -> V_4 , V_40 -> V_67 . V_6 . V_13 , V_40 -> V_67 . V_6 . V_15 ,
V_40 -> V_67 . V_6 . V_16 ) ;
F_94 ( & V_2 -> V_161 ) ;
for ( V_100 = 0 ; F_13 ( V_2 , V_126 ) & V_162 ; V_100 ++ ) {
if ( F_22 ( V_100 > 50 ) ) {
F_31 (KERN_ERR DEV_LABEL L_61
L_62 , lanai->number) ;
break;
}
F_25 ( 5 ) ;
}
F_95 () ;
F_16 ( V_2 , ( V_15 << 12 ) | V_40 -> V_4 , V_163 ) ;
F_96 ( & V_2 -> V_161 ) ;
}
static void F_97 ( struct V_1 * V_2 ,
struct V_39 * V_40 , struct V_47 * V_48 , int V_164 )
{
int V_165 ;
F_6 ( V_164 == F_38 ( V_48 -> V_149 ) ,
L_63 ,
V_164 , F_38 ( V_48 -> V_149 ) ) ;
F_87 ( V_40 , 0 , V_164 ) ;
V_165 = V_164 - V_48 -> V_149 - 8 ;
F_6 ( V_165 >= 0 , L_64 , V_165 ) ;
F_6 ( V_165 < 48 , L_65 , V_165 ) ;
F_91 ( V_40 , V_48 -> V_102 , V_48 -> V_149 ) ;
F_92 ( V_40 , V_165 ) ;
F_89 ( V_40 , V_48 -> V_149 , 0 , 0 ) ;
F_93 ( V_2 , V_40 ) ;
F_40 ( V_40 -> V_67 . V_46 , V_48 ) ;
F_98 ( & V_40 -> V_67 . V_46 -> V_166 -> V_67 ) ;
}
static void F_99 ( struct V_1 * V_2 ,
struct V_39 * V_40 , int V_147 )
{
int V_159 ;
struct V_47 * V_48 ;
int V_44 = F_84 ( V_40 , V_147 ) ;
F_6 ( F_85 ( V_40 ) ,
L_66 ,
V_40 -> V_4 ) ;
while ( V_44 >= 64 ) {
V_48 = F_51 ( & V_40 -> V_67 . V_87 ) ;
if ( V_48 == NULL )
goto V_167;
V_159 = F_38 ( V_48 -> V_149 ) ;
if ( V_159 + 16 > V_44 ) {
F_100 ( & V_40 -> V_67 . V_87 , V_48 ) ;
return;
}
F_97 ( V_2 , V_40 , V_48 , V_159 ) ;
V_44 -= V_159 + 16 ;
}
if ( ! F_85 ( V_40 ) ) {
V_167:
F_53 ( V_40 -> V_4 , V_2 -> V_89 ) ;
}
}
static void F_101 ( struct V_1 * V_2 , struct V_39 * V_40 ,
struct V_47 * V_48 )
{
int V_44 , V_159 ;
if ( F_85 ( V_40 ) )
goto V_168;
V_44 = F_84 ( V_40 ,
F_56 ( F_36 ( V_40 , V_71 ) ) ) ;
V_159 = F_38 ( V_48 -> V_149 ) ;
F_6 ( V_159 + 16 >= 64 , L_67 , V_159 ) ;
if ( V_44 < V_159 + 16 ) {
F_102 ( V_40 -> V_4 , V_2 -> V_89 ) ;
V_168:
F_103 ( & V_40 -> V_67 . V_87 , V_48 ) ;
return;
}
F_97 ( V_2 , V_40 , V_48 , V_159 ) ;
}
static void F_104 ( struct V_1 * V_2 ,
struct V_39 * V_40 , int V_147 )
{
F_31 (KERN_INFO DEV_LABEL
L_68 ) ;
}
static void F_105 ( struct V_1 * V_2 , struct V_39 * V_40 ,
struct V_47 * V_48 )
{
F_31 (KERN_INFO DEV_LABEL L_69 ) ;
F_40 ( V_40 -> V_67 . V_46 , V_48 ) ;
}
static inline void F_106 ( unsigned char * V_169 ,
const struct V_39 * V_40 , int V_159 )
{
int V_160 = ( ( const unsigned char * ) V_40 -> V_51 . V_6 . V_15 ) + V_159 -
( ( const unsigned char * ) ( V_40 -> V_51 . V_6 . V_16 ) ) ;
if ( V_160 < 0 )
V_160 = 0 ;
memcpy ( V_169 , V_40 -> V_51 . V_6 . V_15 , V_159 - V_160 ) ;
memcpy ( V_169 + V_159 - V_160 , V_40 -> V_51 . V_6 . V_13 , V_160 ) ;
F_107 () ;
}
static void F_108 ( struct V_39 * V_40 , int V_147 )
{
int V_11 ;
struct V_47 * V_48 ;
const V_17 * T_7 ;
V_17 * V_16 = & V_40 -> V_51 . V_6 . V_13 [ V_147 * 4 ] ;
int V_159 = ( ( unsigned long ) V_16 ) - ( ( unsigned long ) V_40 -> V_51 . V_6 . V_15 ) ;
if ( V_159 < 0 )
V_159 += F_7 ( & V_40 -> V_51 . V_6 ) ;
F_6 ( V_159 >= 0 && V_159 < F_7 ( & V_40 -> V_51 . V_6 ) && ! ( V_159 & 15 ) ,
L_70 ,
V_159 , F_7 ( & V_40 -> V_51 . V_6 ) ) ;
if ( ( T_7 = & V_16 [ - 2 ] ) < V_40 -> V_51 . V_6 . V_13 )
T_7 = & V_40 -> V_51 . V_6 . V_16 [ - 2 ] ;
F_109 () ;
V_11 = F_72 ( T_7 ) & 0xffff ;
if ( F_22 ( V_159 != F_38 ( V_11 ) ) ) {
F_31 (KERN_INFO DEV_LABEL L_71
L_72 ,
lvcc->rx.atmvcc->dev->number, lvcc->vci, size, n) ;
V_40 -> V_166 . T_7 . V_170 . V_171 ++ ;
goto V_172;
}
V_48 = F_110 ( V_40 -> V_51 . V_46 , V_11 , V_173 ) ;
if ( F_22 ( V_48 == NULL ) ) {
V_40 -> V_166 . V_174 ++ ;
goto V_172;
}
F_111 ( V_48 , V_11 ) ;
F_106 ( V_48 -> V_102 , V_40 , V_11 ) ;
F_112 ( V_48 ) -> V_175 = V_40 -> V_51 . V_46 ;
F_113 ( V_48 ) ;
V_40 -> V_51 . V_46 -> V_176 ( V_40 -> V_51 . V_46 , V_48 ) ;
F_98 ( & V_40 -> V_51 . V_46 -> V_166 -> V_51 ) ;
V_172:
V_40 -> V_51 . V_6 . V_15 = V_16 ;
F_37 ( V_40 , V_147 , V_59 ) ;
}
static void F_114 ( struct V_1 * V_2 )
{
F_31 (KERN_INFO DEV_LABEL L_73 ) ;
}
static int T_4 F_115 ( struct V_1 * V_2 )
{
#ifdef F_116
F_6 ( ( V_2 -> V_177 ) * sizeof( struct V_39 * ) <= V_178 ,
L_74 ) ;
V_2 -> V_179 = (struct V_39 * * ) F_117 ( V_180 ) ;
return ( V_2 -> V_179 == NULL ) ? - V_94 : 0 ;
#else
int V_7 = ( V_2 -> V_177 ) * sizeof( struct V_39 * ) ;
V_2 -> V_179 = (struct V_39 * * ) F_118 ( V_7 ) ;
if ( F_22 ( V_2 -> V_179 == NULL ) )
return - V_94 ;
memset ( V_2 -> V_179 , 0 , V_7 ) ;
return 0 ;
#endif
}
static inline void F_119 ( const struct V_1 * V_2 )
{
#ifdef F_116
F_120 ( ( unsigned long ) V_2 -> V_179 ) ;
#else
F_121 ( V_2 -> V_179 ) ;
#endif
}
static inline struct V_39 * F_122 ( void )
{
struct V_39 * V_40 ;
V_40 = F_123 ( sizeof( * V_40 ) , V_180 ) ;
if ( F_30 ( V_40 != NULL ) ) {
F_124 ( & V_40 -> V_67 . V_87 ) ;
#ifdef F_73
V_40 -> V_4 = - 1 ;
#endif
}
return V_40 ;
}
static int F_125 ( struct V_1 * V_2 ,
struct V_5 * V_6 , int V_181 , int V_182 ,
const char * V_122 )
{
int V_11 ;
if ( F_22 ( V_181 < 1 ) )
V_181 = 1 ;
V_181 = F_38 ( V_181 ) ;
V_11 = ( V_181 + 16 ) * V_182 + 16 ;
F_4 ( V_6 , V_11 , V_181 + 32 , V_2 -> V_10 ) ;
if ( F_22 ( V_6 -> V_13 == NULL ) )
return - V_94 ;
if ( F_22 ( F_7 ( V_6 ) < V_11 ) )
F_31 (KERN_WARNING DEV_LABEL L_75
L_76 , lanai->number, size,
name, lanai_buf_size(buf)) ;
F_24 ( L_77 , F_7 ( V_6 ) , V_122 ) ;
return 0 ;
}
static inline int F_126 ( struct V_1 * V_2 ,
struct V_39 * V_40 , const struct V_183 * V_52 )
{
return F_125 ( V_2 , & V_40 -> V_51 . V_6 ,
V_52 -> V_184 . V_181 , V_185 , L_78 ) ;
}
static int F_127 ( struct V_1 * V_2 , struct V_39 * V_40 ,
const struct V_183 * V_52 )
{
int V_181 , V_182 ;
if ( V_52 -> V_53 == V_186 ) {
V_40 -> V_67 . V_187 = F_104 ;
V_181 = V_188 - 1 ;
V_182 = V_189 ;
} else {
V_40 -> V_67 . V_187 = F_99 ;
V_181 = V_52 -> V_74 . V_181 ;
V_182 = V_190 ;
}
return F_125 ( V_2 , & V_40 -> V_67 . V_6 , V_181 ,
V_182 , L_79 ) ;
}
static inline void F_128 ( struct V_1 * V_2 ,
struct V_39 * V_40 , T_1 V_4 )
{
if ( V_40 -> V_42 != NULL )
return;
F_24 ( L_80 , V_4 ) ;
#ifdef F_21
if ( V_2 -> V_191 ++ == 0 ) {
F_24 ( L_81 ) ;
V_2 -> V_25 &= ~ V_29 ;
F_18 ( V_2 ) ;
F_19 ( V_2 ) ;
}
#endif
V_40 -> V_42 = F_35 ( V_2 , V_4 ) ;
V_2 -> V_179 [ V_40 -> V_4 = V_4 ] = V_40 ;
}
static inline void F_129 ( struct V_1 * V_2 ,
struct V_39 * V_40 )
{
if ( V_40 -> V_42 == NULL )
return;
F_24 ( L_82 , V_40 -> V_4 ) ;
V_40 -> V_42 = NULL ;
V_2 -> V_179 [ V_40 -> V_4 ] = NULL ;
#ifdef F_21
if ( -- V_2 -> V_191 == 0 ) {
F_24 ( L_83 ) ;
V_2 -> V_25 |= V_29 ;
F_18 ( V_2 ) ;
}
#endif
}
static void F_130 ( struct V_1 * V_2 )
{
F_31 (KERN_CRIT DEV_LABEL L_84
L_85 , lanai->number) ;
F_16 ( V_2 , V_192 , V_193 ) ;
V_2 -> V_166 . V_194 ++ ;
}
static int T_4 F_131 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_195 , V_196 * 4 , 8 ,
V_2 -> V_10 ) ;
if ( F_22 ( V_2 -> V_195 . V_13 == NULL ) )
return - V_94 ;
F_24 ( L_86 ,
( unsigned long ) V_2 -> V_195 . V_13 ,
F_7 ( & V_2 -> V_195 ) ,
F_10 ( & V_2 -> V_195 ) ) ;
F_16 ( V_2 , 0 , V_197 ) ;
F_16 ( V_2 ,
F_132 ( F_10 ( & V_2 -> V_195 ) ) |
F_133 ( V_2 -> V_195 . V_14 ) ,
V_198 ) ;
return 0 ;
}
static inline void F_134 ( struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_195 , V_2 -> V_10 ) ;
}
static int F_135 ( struct V_1 * V_2 , V_17 V_106 )
{
T_1 V_4 = F_136 ( V_106 ) ;
struct V_39 * V_40 ;
F_137 ( & V_88 ) ;
V_40 = V_2 -> V_179 [ V_4 ] ;
if ( F_22 ( V_40 == NULL ) ) {
F_138 ( & V_88 ) ;
F_24 ( L_87
L_88 , V_2 -> V_199 , ( unsigned int ) V_106 , V_4 ) ;
if ( V_106 & V_200 )
V_2 -> V_166 . V_201 ++ ;
else
V_2 -> V_166 . V_202 ++ ;
return 0 ;
}
if ( V_106 & V_200 ) {
if ( F_22 ( V_40 -> V_67 . V_46 == NULL ) ) {
F_138 ( & V_88 ) ;
F_24 ( L_89
L_88 , V_2 -> V_199 , ( unsigned int ) V_106 , V_4 ) ;
V_2 -> V_166 . V_201 ++ ;
return 0 ;
}
F_102 ( V_4 , V_2 -> V_203 ) ;
V_40 -> V_67 . V_147 = F_139 ( V_106 ) ;
F_138 ( & V_88 ) ;
return 1 ;
}
if ( F_22 ( V_40 -> V_51 . V_46 == NULL ) ) {
F_138 ( & V_88 ) ;
F_24 ( L_90
L_88 , V_2 -> V_199 , ( unsigned int ) V_106 , V_4 ) ;
V_2 -> V_166 . V_202 ++ ;
return 0 ;
}
if ( F_22 ( V_40 -> V_51 . V_46 -> V_52 . V_53 != V_54 ) ) {
F_138 ( & V_88 ) ;
F_24 ( L_91
L_88 , V_2 -> V_199 , ( unsigned int ) V_106 , V_4 ) ;
V_2 -> V_166 . V_204 ++ ;
F_98 ( & V_40 -> V_51 . V_46 -> V_166 -> V_205 ) ;
return 0 ;
}
if ( F_30 ( ! ( V_106 & ( V_206 | V_207 | V_208 ) ) ) ) {
F_108 ( V_40 , F_139 ( V_106 ) ) ;
F_138 ( & V_88 ) ;
return 0 ;
}
if ( V_106 & V_206 ) {
int V_7 ;
F_138 ( & V_88 ) ;
F_24 ( L_92 , V_4 ) ;
F_98 ( & V_40 -> V_51 . V_46 -> V_166 -> V_205 ) ;
V_40 -> V_166 . T_7 . V_170 . V_209 ++ ;
V_7 = ( F_139 ( V_106 ) * 16 ) -
( ( ( unsigned long ) V_40 -> V_51 . V_6 . V_15 ) -
( ( unsigned long ) V_40 -> V_51 . V_6 . V_13 ) ) + 47 ;
if ( V_7 < 0 )
V_7 += F_7 ( & V_40 -> V_51 . V_6 ) ;
V_2 -> V_166 . V_210 += ( V_7 / 48 ) ;
return 0 ;
}
if ( V_106 & V_207 ) {
F_138 ( & V_88 ) ;
F_98 ( & V_40 -> V_51 . V_46 -> V_166 -> V_205 ) ;
V_40 -> V_166 . T_7 . V_170 . V_211 ++ ;
F_31 (KERN_ERR DEV_LABEL L_93
L_94 , lanai->number, vci) ;
F_130 ( V_2 ) ;
return 0 ;
}
F_24 ( L_95 , V_4 ) ;
F_98 ( & V_40 -> V_51 . V_46 -> V_166 -> V_205 ) ;
V_40 -> V_166 . T_7 . V_170 . V_212 ++ ;
V_40 -> V_51 . V_6 . V_15 = & V_40 -> V_51 . V_6 . V_13 [ F_139 ( V_106 ) * 4 ] ;
F_37 ( V_40 , F_139 ( V_106 ) , V_59 ) ;
F_138 ( & V_88 ) ;
return 0 ;
}
static void F_140 ( struct V_1 * V_2 , T_1 V_4 )
{
struct V_39 * V_40 = V_2 -> V_179 [ V_4 ] ;
if ( F_85 ( V_40 ) )
V_40 -> V_67 . V_187 ( V_2 , V_40 , V_40 -> V_67 . V_147 ) ;
}
static void F_141 ( struct V_1 * V_2 )
{
int V_213 = 0 ;
V_17 V_214 = F_13 ( V_2 , V_197 ) ;
const V_17 * V_16 = V_2 -> V_195 . V_13 + V_214 ;
while ( V_2 -> V_195 . V_15 != V_16 ) {
V_213 += F_135 ( V_2 ,
F_142 ( V_2 -> V_195 . V_15 ++ ) ) ;
if ( V_2 -> V_195 . V_15 >= V_2 -> V_195 . V_16 )
V_2 -> V_195 . V_15 = V_2 -> V_195 . V_13 ;
}
F_16 ( V_2 , V_214 , V_215 ) ;
if ( V_213 != 0 ) {
F_137 ( & V_88 ) ;
F_1 ( V_2 , V_2 -> V_203 ,
F_140 ) ;
F_143 ( V_2 -> V_203 , V_216 ) ;
F_138 ( & V_88 ) ;
}
}
static void F_144 ( struct V_1 * V_2 )
{
V_17 V_217 = F_13 ( V_2 , V_218 ) ;
V_2 -> V_166 . V_219 += F_145 ( V_217 ) ;
V_2 -> V_166 . V_220 += F_146 ( V_217 ) ;
V_2 -> V_166 . V_221 += F_147 ( V_217 ) ;
V_2 -> V_166 . V_210 += F_148 ( V_217 ) ;
}
static void F_149 ( struct V_1 * V_2 , T_1 V_4 )
{
struct V_39 * V_40 = V_2 -> V_179 [ V_4 ] ;
int V_147 ;
if ( V_40 == NULL || V_40 -> V_67 . V_46 == NULL ||
! F_85 ( V_40 ) ) {
F_53 ( V_4 , V_2 -> V_89 ) ;
return;
}
V_147 = F_56 ( F_36 ( V_40 , V_71 ) ) ;
V_40 -> V_67 . V_187 ( V_2 , V_40 , V_147 ) ;
}
static void F_150 ( unsigned long V_222 )
{
struct V_1 * V_2 = (struct V_1 * ) V_222 ;
#ifndef F_151
unsigned long V_82 ;
#ifdef F_21
if ( V_2 -> V_25 & V_29 )
return;
#endif
F_152 ( V_82 ) ;
if ( F_153 ( & V_2 -> V_223 ) ) {
F_141 ( V_2 ) ;
F_96 ( & V_2 -> V_223 ) ;
}
F_137 ( & V_88 ) ;
F_1 ( V_2 , V_2 -> V_89 , F_149 ) ;
F_138 ( & V_88 ) ;
F_154 ( V_82 ) ;
F_144 ( V_2 ) ;
#endif
F_155 ( & V_2 -> V_224 , V_90 + V_225 ) ;
}
static inline void F_156 ( struct V_1 * V_2 )
{
F_157 ( & V_2 -> V_224 ) ;
V_2 -> V_224 . V_226 = V_90 + V_225 ;
V_2 -> V_224 . V_102 = ( unsigned long ) V_2 ;
V_2 -> V_224 . V_227 = F_150 ;
F_158 ( & V_2 -> V_224 ) ;
}
static inline void F_159 ( struct V_1 * V_2 )
{
F_160 ( & V_2 -> V_224 ) ;
}
static inline void F_161 ( struct V_1 * V_2 , V_17 V_228 )
{
V_17 V_229 = 0 ;
if ( V_228 & V_230 ) {
V_229 = V_230 ;
F_94 ( & V_2 -> V_223 ) ;
F_141 ( V_2 ) ;
F_96 ( & V_2 -> V_223 ) ;
}
if ( V_228 & ( V_231 | V_232 ) ) {
V_229 |= V_228 & ( V_231 | V_232 ) ;
F_114 ( V_2 ) ;
}
if ( V_229 == V_228 )
goto V_233;
if ( V_228 & V_234 ) {
V_228 &= ~ V_234 ;
F_144 ( V_2 ) ;
}
if ( V_228 & V_235 ) {
V_229 |= V_228 & V_235 ;
F_79 ( V_2 ) ;
}
if ( F_22 ( V_228 & V_236 ) ) {
F_31 (KERN_ERR DEV_LABEL L_96
L_97 ,
lanai->number, (unsigned int) (reason & INT_DMASHUT),
(unsigned int) reg_read(lanai, DMA_Addr_Reg)) ;
if ( V_228 & V_237 ) {
F_130 ( V_2 ) ;
return;
}
V_229 |= ( V_228 & V_236 ) ;
F_31 (KERN_ERR DEV_LABEL L_98 ,
lanai->number) ;
F_18 ( V_2 ) ;
V_2 -> V_166 . V_238 ++ ;
F_81 ( V_2 , 0 ) ;
}
if ( F_22 ( V_228 & V_239 ) ) {
V_229 |= ( V_228 & V_239 ) ;
F_31 (KERN_ERR DEV_LABEL L_99 ,
lanai->number) ;
F_81 ( V_2 , 0 ) ;
}
if ( F_22 ( V_228 & V_240 ) ) {
F_31 (KERN_ERR DEV_LABEL L_100
L_101 , lanai->number,
(unsigned int) (reason & INT_SEGSHUT)) ;
F_130 ( V_2 ) ;
return;
}
if ( F_22 ( V_228 & ( V_241 | V_242 ) ) ) {
F_31 (KERN_ERR DEV_LABEL L_100
L_102 ,
lanai->number,
(unsigned int) (reason & (INT_PING | INT_WAKE))) ;
F_130 ( V_2 ) ;
return;
}
#ifdef F_73
if ( F_22 ( V_229 != V_228 ) ) {
F_24 ( L_103 ,
( unsigned int ) ( V_228 & ~ V_229 ) ) ;
V_229 = V_228 ;
}
#endif
V_233:
if ( V_229 != 0 )
F_16 ( V_2 , V_229 , V_193 ) ;
}
static T_11 F_162 ( int V_243 , void * V_244 )
{
struct V_1 * V_2 = V_244 ;
V_17 V_228 ;
#ifdef F_21
if ( F_22 ( V_2 -> V_25 & V_29 ) )
return V_245 ;
#endif
V_228 = F_75 ( V_2 ) ;
if ( V_228 == 0 )
return V_245 ;
do {
if ( F_22 ( V_228 == 0xFFFFFFFF ) )
break;
F_161 ( V_2 , V_228 ) ;
V_228 = F_75 ( V_2 ) ;
} while ( V_228 != 0 );
return V_246 ;
}
static int F_163 ( const char * V_122 , V_17 V_24 , int * V_247 )
{
F_24 ( L_104 , V_122 ,
( int ) F_164 ( V_24 ) ,
( int ) F_165 ( V_24 ) ) ;
if ( F_164 ( V_24 ) != V_248 ) {
F_31 (KERN_ERR DEV_LABEL L_105
L_106 , name, (int) RESET_GET_BOARD_ID(val)) ;
return - V_249 ;
}
if ( V_247 != NULL )
* V_247 = F_165 ( V_24 ) ;
return 0 ;
}
static int T_4 F_166 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
int V_36 ;
if ( F_167 ( V_10 ) != 0 ) {
F_31 (KERN_ERR DEV_LABEL L_107
L_108 , lanai->number) ;
return - V_250 ;
}
F_168 ( V_10 ) ;
if ( F_169 ( V_10 , F_170 ( 32 ) ) != 0 ) {
F_31 (KERN_WARNING DEV_LABEL
L_109 , lanai->number) ;
return - V_251 ;
}
if ( F_171 ( V_10 , F_170 ( 32 ) ) != 0 ) {
F_31 (KERN_WARNING DEV_LABEL
L_109 , lanai->number) ;
return - V_251 ;
}
V_36 = F_163 ( L_110 , V_10 -> V_252 , NULL ) ;
if ( V_36 != 0 )
return V_36 ;
V_36 = F_172 ( V_10 , V_253 , 0 ) ;
if ( V_36 != V_134 ) {
F_31 (KERN_ERR DEV_LABEL L_111
L_112 , lanai->number, result) ;
return - V_254 ;
}
F_81 ( V_2 , 1 ) ;
F_81 ( V_2 , 0 ) ;
return 0 ;
}
static inline int F_173 ( struct V_1 * V_2 ,
const struct V_183 * V_52 )
{
if ( V_52 -> V_74 . V_75 == V_76 || V_52 -> V_53 == V_186 )
return 0 ;
if ( V_52 -> V_184 . V_75 != V_255 ) {
if ( V_2 -> V_256 != 0 )
return 0 ;
V_2 -> V_27 |= V_257 ;
F_20 ( V_2 ) ;
}
return 1 ;
}
static int F_174 ( struct V_1 * V_2 , T_1 V_4 ,
const struct V_45 * V_46 )
{
const struct V_183 * V_52 = & V_46 -> V_52 ;
const struct V_39 * V_40 = V_2 -> V_179 [ V_4 ] ;
if ( V_4 == 0 && ! F_173 ( V_2 , V_52 ) )
return 0 ;
if ( F_22 ( V_40 != NULL ) ) {
if ( V_52 -> V_184 . V_75 != V_255 &&
V_40 -> V_51 . V_46 != NULL && V_40 -> V_51 . V_46 != V_46 )
return 0 ;
if ( V_52 -> V_74 . V_75 != V_255 &&
V_40 -> V_67 . V_46 != NULL && V_40 -> V_67 . V_46 != V_46 )
return 0 ;
if ( V_52 -> V_74 . V_75 == V_76 &&
V_2 -> V_258 != NULL && V_2 -> V_258 != V_46 )
return 0 ;
}
if ( V_52 -> V_53 == V_186 && V_2 -> V_256 == 0 &&
V_52 -> V_184 . V_75 != V_255 ) {
const struct V_39 * V_259 = V_2 -> V_179 [ 0 ] ;
if ( V_259 != NULL && V_259 -> V_51 . V_46 != NULL )
return 0 ;
V_2 -> V_27 &= ~ V_257 ;
F_20 ( V_2 ) ;
}
return 1 ;
}
static int F_175 ( struct V_1 * V_2 ,
const struct V_45 * V_46 , short * V_260 , T_1 * V_261 )
{
switch ( * V_260 ) {
case V_262 :
* V_260 = 0 ;
case 0 :
break;
default:
return - V_263 ;
}
switch ( * V_261 ) {
case V_264 :
for ( * V_261 = V_265 ; * V_261 < V_2 -> V_177 ;
( * V_261 ) ++ )
if ( F_174 ( V_2 , * V_261 , V_46 ) )
return 0 ;
return - V_263 ;
default:
if ( * V_261 >= V_2 -> V_177 || * V_261 < 0 ||
! F_174 ( V_2 , * V_261 , V_46 ) )
return - V_263 ;
}
return 0 ;
}
static int F_176 ( const struct V_183 * V_52 )
{
int V_266 = 0 ;
int T_7 , V_267 , V_268 = F_177 ( & V_52 -> V_74 ) ;
if ( V_268 == 0 )
return 0 ;
if ( V_268 < 0 ) {
V_266 = 1 ;
V_268 = - V_268 ;
}
T_7 = V_268 * 27 ;
V_267 = ( 3125 << ( 9 + V_269 ) ) - ( T_7 << V_269 ) ;
if ( V_266 )
V_267 += T_7 - 1 ;
V_267 /= T_7 ;
if ( V_267 > V_270 )
V_267 = V_270 ;
F_24 ( L_113 ,
V_268 , V_266 ? 'Y' : 'N' , V_267 ) ;
return V_267 ;
}
static inline void F_178 ( struct V_1 * V_2 )
{
F_16 ( V_2 , F_176 ( & V_2 -> V_258 -> V_52 ) , V_271 ) ;
F_16 ( V_2 , V_2 -> V_258 -> V_4 , V_272 ) ;
V_2 -> V_27 |= V_273 ;
F_19 ( V_2 ) ;
}
static inline void F_179 ( struct V_1 * V_2 )
{
V_2 -> V_27 &= ~ V_273 ;
F_19 ( V_2 ) ;
}
static int T_4 F_180 ( struct V_274 * V_275 )
{
struct V_1 * V_2 = (struct V_1 * ) V_275 -> V_276 ;
unsigned long V_277 ;
int V_36 ;
F_24 ( L_114 ) ;
V_2 -> V_199 = V_275 -> V_199 ;
V_2 -> V_177 = V_216 ;
F_143 ( V_2 -> V_89 , V_216 ) ;
F_143 ( V_2 -> V_203 , V_216 ) ;
V_2 -> V_256 = 0 ;
#ifdef F_21
V_2 -> V_191 = 0 ;
#endif
V_2 -> V_258 = NULL ;
memset ( & V_2 -> V_166 , 0 , sizeof V_2 -> V_166 ) ;
F_181 ( & V_2 -> V_161 ) ;
F_181 ( & V_2 -> V_223 ) ;
V_275 -> V_278 . V_279 = 0 ;
V_275 -> V_278 . V_280 = 0 ;
while ( 1 << V_275 -> V_278 . V_280 < V_2 -> V_177 )
V_275 -> V_278 . V_280 ++ ;
V_275 -> V_281 = V_282 ;
if ( ( V_36 = F_166 ( V_2 ) ) != 0 )
goto error;
V_277 = V_2 -> V_10 -> V_283 [ 0 ] . V_13 ;
V_2 -> V_22 = ( T_3 ) F_182 ( V_277 , V_284 ) ;
if ( V_2 -> V_22 == NULL ) {
F_31 (KERN_ERR DEV_LABEL L_115 ) ;
goto V_285;
}
F_23 ( V_2 ) ;
V_2 -> V_25 = F_13 ( V_2 , V_26 ) ;
V_2 -> V_25 &= ~ ( V_286 | V_29 |
V_287 ) ;
V_2 -> V_25 |= F_183 ( V_288 ) ;
F_16 ( V_2 , V_2 -> V_25 | V_286 , V_26 ) ;
F_25 ( 1000 ) ;
F_18 ( V_2 ) ;
V_36 = F_163 ( L_116 ,
F_13 ( V_2 , V_30 ) , & V_2 -> V_289 ) ;
if ( V_36 != 0 )
goto V_290;
if ( ( V_36 = F_61 ( V_2 ) ) != 0 )
goto V_290;
if ( ( V_36 = F_62 ( V_2 ) ) != 0 )
goto V_290;
F_16 ( V_2 , V_2 -> V_25 | V_286 , V_26 ) ;
F_25 ( 1000 ) ;
F_18 ( V_2 ) ;
V_2 -> V_25 |= ( V_291 | V_292 | V_293 ) ;
F_18 ( V_2 ) ;
if ( ( V_36 = F_33 ( V_2 ) ) != 0 )
goto V_290;
V_2 -> V_25 |= V_293 ;
F_18 ( V_2 ) ;
if ( ( V_36 = F_131 ( V_2 ) ) != 0 )
goto V_290;
if ( ( V_36 = F_115 ( V_2 ) ) != 0 )
goto V_294;
V_2 -> V_27 = ( V_2 -> V_177 >= 512 ? V_295 : 0 ) |
V_296 | V_297 ;
F_19 ( V_2 ) ;
F_16 ( V_2 , V_298 , V_299 ) ;
F_16 ( V_2 , 0 , V_271 ) ;
if ( ( V_36 = F_184 ( V_2 -> V_10 -> V_243 , F_162 , V_300 ,
V_301 , V_2 ) ) != 0 ) {
F_31 (KERN_ERR DEV_LABEL L_117 ) ;
goto V_302;
}
F_185 () ;
F_76 ( V_2 , V_192 & ~ ( V_241 | V_242 ) ) ;
V_2 -> V_25 = ( V_2 -> V_25 & ~ V_303 ) |
F_186 ( V_304 ) |
V_291 | V_292 ;
F_18 ( V_2 ) ;
V_2 -> V_123 = F_13 ( V_2 , V_126 ) ;
#ifdef F_21
V_2 -> V_25 |= V_29 ;
F_18 ( V_2 ) ;
#endif
memcpy ( V_275 -> V_305 , F_74 ( V_2 ) , V_306 ) ;
F_156 ( V_2 ) ;
F_31 (KERN_NOTICE DEV_LABEL L_118
L_119 , lanai->number, (int) lanai->pci->revision,
(unsigned long) lanai->base, lanai->pci->irq, atmdev->esi) ;
F_31 (KERN_NOTICE DEV_LABEL L_120
L_121 , lanai->number,
lanai->type==lanai2 ? L_122 : L_123 , (unsigned int) lanai->serialno,
(unsigned int) lanai->serialno, lanai->board_rev) ;
return 0 ;
V_302:
F_119 ( V_2 ) ;
V_294:
F_134 ( V_2 ) ;
V_290:
F_23 ( V_2 ) ;
#ifdef F_21
V_2 -> V_25 = F_13 ( V_2 , V_26 ) | V_29 ;
F_18 ( V_2 ) ;
#endif
F_187 ( V_2 -> V_22 ) ;
V_285:
F_188 ( V_2 -> V_10 ) ;
error:
return V_36 ;
}
static void F_189 ( struct V_274 * V_275 )
{
struct V_1 * V_2 = (struct V_1 * ) V_275 -> V_276 ;
F_31 (KERN_INFO DEV_LABEL L_124 ,
lanai->number) ;
F_159 ( V_2 ) ;
#ifdef F_21
V_2 -> V_25 = F_13 ( V_2 , V_26 ) & ~ V_29 ;
F_18 ( V_2 ) ;
#endif
F_77 ( V_2 , V_192 ) ;
F_190 ( V_2 -> V_10 -> V_243 , V_2 ) ;
F_23 ( V_2 ) ;
#ifdef F_21
V_2 -> V_25 |= V_29 ;
F_18 ( V_2 ) ;
#endif
F_188 ( V_2 -> V_10 ) ;
F_119 ( V_2 ) ;
F_134 ( V_2 ) ;
F_187 ( V_2 -> V_22 ) ;
F_191 ( V_2 ) ;
}
static void F_192 ( struct V_45 * V_46 )
{
struct V_39 * V_40 = (struct V_39 * ) V_46 -> V_276 ;
struct V_1 * V_2 = (struct V_1 * ) V_46 -> V_307 -> V_276 ;
if ( V_40 == NULL )
return;
F_193 ( V_308 , & V_46 -> V_82 ) ;
F_193 ( V_309 , & V_46 -> V_82 ) ;
if ( V_40 -> V_51 . V_46 == V_46 ) {
F_48 ( V_40 ) ;
if ( V_46 -> V_52 . V_53 == V_186 ) {
if ( -- V_2 -> V_256 <= 0 )
F_60 ( V_2 ) ;
} else
F_8 ( & V_40 -> V_51 . V_6 , V_2 -> V_10 ) ;
V_40 -> V_51 . V_46 = NULL ;
}
if ( V_40 -> V_67 . V_46 == V_46 ) {
if ( V_46 == V_2 -> V_258 ) {
if ( V_40 -> V_42 != NULL )
F_179 ( V_2 ) ;
V_2 -> V_258 = NULL ;
}
F_49 ( V_2 , V_40 ) ;
F_8 ( & V_40 -> V_67 . V_6 , V_2 -> V_10 ) ;
V_40 -> V_67 . V_46 = NULL ;
}
if ( -- V_40 -> V_310 == 0 ) {
F_129 ( V_2 , V_40 ) ;
F_191 ( V_40 ) ;
}
V_46 -> V_276 = NULL ;
F_193 ( V_311 , & V_46 -> V_82 ) ;
}
static int F_194 ( struct V_45 * V_46 )
{
struct V_1 * V_2 ;
struct V_39 * V_40 ;
int V_36 = 0 ;
int V_4 = V_46 -> V_4 ;
short V_312 = V_46 -> V_312 ;
if ( ( F_195 ( V_309 , & V_46 -> V_82 ) ) ||
( V_312 == V_313 ) || ( V_4 == V_314 ) )
return - V_254 ;
V_2 = (struct V_1 * ) V_46 -> V_307 -> V_276 ;
V_36 = F_175 ( V_2 , V_46 , & V_312 , & V_4 ) ;
if ( F_22 ( V_36 != 0 ) )
goto V_172;
F_196 ( V_311 , & V_46 -> V_82 ) ;
if ( V_46 -> V_52 . V_53 != V_186 && V_46 -> V_52 . V_53 != V_54 )
return - V_254 ;
F_24 ( V_301 L_125 , V_2 -> V_199 ,
( int ) V_312 , V_4 ) ;
V_40 = V_2 -> V_179 [ V_4 ] ;
if ( V_40 == NULL ) {
V_40 = F_122 () ;
if ( F_22 ( V_40 == NULL ) )
return - V_94 ;
V_46 -> V_276 = V_40 ;
}
V_40 -> V_310 ++ ;
if ( V_46 -> V_52 . V_184 . V_75 != V_255 ) {
F_6 ( V_40 -> V_51 . V_46 == NULL , L_126 ,
V_4 ) ;
if ( V_46 -> V_52 . V_53 == V_186 ) {
if ( V_2 -> V_256 == 0 )
V_36 = F_59 ( V_2 ) ;
} else
V_36 = F_126 (
V_2 , V_40 , & V_46 -> V_52 ) ;
if ( F_22 ( V_36 != 0 ) )
goto V_315;
V_40 -> V_51 . V_46 = V_46 ;
V_40 -> V_166 . V_174 = 0 ;
V_40 -> V_166 . T_7 . V_170 . V_171 = 0 ;
V_40 -> V_166 . T_7 . V_170 . V_209 = 0 ;
V_40 -> V_166 . T_7 . V_170 . V_211 = 0 ;
V_40 -> V_166 . T_7 . V_170 . V_212 = 0 ;
if ( V_46 -> V_52 . V_53 == V_186 )
V_2 -> V_256 ++ ;
}
if ( V_46 -> V_52 . V_74 . V_75 != V_255 ) {
F_6 ( V_40 -> V_67 . V_46 == NULL , L_127 ,
V_4 ) ;
V_36 = F_127 ( V_2 , V_40 , & V_46 -> V_52 ) ;
if ( F_22 ( V_36 != 0 ) )
goto V_315;
V_40 -> V_67 . V_46 = V_46 ;
if ( V_46 -> V_52 . V_74 . V_75 == V_76 ) {
F_6 ( V_2 -> V_258 == NULL ,
L_128 , V_4 ) ;
V_2 -> V_258 = V_46 ;
}
}
F_128 ( V_2 , V_40 , V_4 ) ;
F_95 () ;
if ( V_46 == V_40 -> V_51 . V_46 )
F_42 ( V_40 ) ;
if ( V_46 == V_40 -> V_67 . V_46 ) {
F_46 ( V_40 ) ;
if ( V_2 -> V_258 == V_46 )
F_178 ( V_2 ) ;
}
F_196 ( V_308 , & V_46 -> V_82 ) ;
return 0 ;
V_315:
F_192 ( V_46 ) ;
V_172:
return V_36 ;
}
static int F_197 ( struct V_45 * V_46 , struct V_47 * V_48 )
{
struct V_39 * V_40 = (struct V_39 * ) V_46 -> V_276 ;
struct V_1 * V_2 = (struct V_1 * ) V_46 -> V_307 -> V_276 ;
unsigned long V_82 ;
if ( F_22 ( V_40 == NULL || V_40 -> V_42 == NULL ||
V_40 -> V_67 . V_46 != V_46 ) )
goto V_316;
#ifdef F_73
if ( F_22 ( V_48 == NULL ) ) {
F_24 ( L_129 , V_46 -> V_4 ) ;
goto V_316;
}
if ( F_22 ( V_2 == NULL ) ) {
F_24 ( L_130 , V_46 -> V_4 ) ;
goto V_316;
}
#endif
F_112 ( V_48 ) -> V_175 = V_46 ;
switch ( V_46 -> V_52 . V_53 ) {
case V_54 :
F_52 ( & V_88 , V_82 ) ;
F_101 ( V_2 , V_40 , V_48 ) ;
F_54 ( & V_88 , V_82 ) ;
return 0 ;
case V_186 :
if ( F_22 ( V_48 -> V_149 != V_188 - 1 ) )
goto V_316;
F_198 ( ( V_17 * ) V_48 -> V_102 ) ;
F_52 ( & V_88 , V_82 ) ;
F_105 ( V_2 , V_40 , V_48 ) ;
F_54 ( & V_88 , V_82 ) ;
return 0 ;
}
F_24 ( L_131 , ( int ) V_46 -> V_52 . V_53 ,
V_46 -> V_4 ) ;
V_316:
F_40 ( V_46 , V_48 ) ;
return - V_254 ;
}
static int F_199 ( struct V_45 * V_46 ,
struct V_183 * V_52 , int V_82 )
{
return - V_251 ;
}
static int F_200 ( struct V_274 * V_275 , T_12 * V_150 , char * V_317 )
{
struct V_1 * V_2 = (struct V_1 * ) V_275 -> V_276 ;
T_12 V_318 = * V_150 ;
struct V_39 * V_40 ;
if ( V_318 -- == 0 )
return sprintf ( V_317 , V_301 L_132
L_133 ,
V_275 -> V_199 , V_2 -> type == V_319 ? L_122 : L_123 ,
( unsigned int ) V_2 -> V_97 ,
( unsigned int ) V_2 -> V_98 , V_2 -> V_177 ) ;
if ( V_318 -- == 0 )
return sprintf ( V_317 , L_134 ,
V_2 -> V_289 , ( int ) V_2 -> V_10 -> V_320 ) ;
if ( V_318 -- == 0 )
return sprintf ( V_317 , L_135 ,
& V_2 -> V_95 [ V_96 ] ) ;
if ( V_318 -- == 0 )
return sprintf ( V_317 , L_136
L_137 , ( V_2 -> V_123 & V_128 ) ? 1 : 0 ,
( V_2 -> V_123 & V_129 ) ? 1 : 0 ,
( V_2 -> V_123 & V_130 ) ? 1 : 0 ,
( V_2 -> V_123 & V_131 ) ? 1 : 0 ) ;
if ( V_318 -- == 0 )
return sprintf ( V_317 , L_138
L_139 , F_7 ( & V_2 -> V_195 ) ,
V_2 -> V_256 ? F_7 ( & V_2 -> V_92 ) : 0 ) ;
if ( V_318 -- == 0 ) {
F_144 ( V_2 ) ;
return sprintf ( V_317 , L_140
L_141 ,
V_2 -> V_166 . V_210 , V_2 -> V_166 . V_221 ,
V_2 -> V_166 . V_220 , V_2 -> V_166 . V_219 ) ;
}
if ( V_318 -- == 0 )
return sprintf ( V_317 , L_142
L_143 ,
V_2 -> V_166 . V_321 ,
V_2 -> V_166 . V_322 ,
V_2 -> V_166 . V_323 ) ;
if ( V_318 -- == 0 )
return sprintf ( V_317 , L_144
L_145 , V_2 -> V_166 . V_324 ,
V_2 -> V_166 . V_325 ) ;
if ( V_318 -- == 0 )
return sprintf ( V_317 , L_146
L_147 , V_2 -> V_166 . V_202 ,
V_2 -> V_166 . V_201 ,
V_2 -> V_166 . V_204 ) ;
if ( V_318 -- == 0 )
return sprintf ( V_317 , L_148 ,
V_2 -> V_166 . V_238 , V_2 -> V_166 . V_194 ) ;
F_137 ( & V_88 ) ;
for (; ; V_318 ++ ) {
if ( V_318 >= V_216 ) {
V_318 = 0 ;
goto V_172;
}
if ( ( V_40 = V_2 -> V_179 [ V_318 ] ) != NULL )
break;
( * V_150 ) ++ ;
}
V_318 = sprintf ( V_317 , L_149 , ( T_1 ) V_318 ,
V_40 -> V_310 , V_40 -> V_166 . V_174 ) ;
if ( V_40 -> V_51 . V_46 != NULL ) {
V_318 += sprintf ( & V_317 [ V_318 ] , L_150 ,
V_40 -> V_51 . V_46 -> V_52 . V_53 == V_54 ? 5 : 0 ) ;
if ( V_40 -> V_51 . V_46 -> V_52 . V_53 == V_54 )
V_318 += sprintf ( & V_317 [ V_318 ] , L_151
L_152
L_153 ,
F_7 ( & V_40 -> V_51 . V_6 ) ,
V_40 -> V_166 . T_7 . V_170 . V_171 ,
V_40 -> V_166 . T_7 . V_170 . V_209 ,
V_40 -> V_166 . T_7 . V_170 . V_211 ,
V_40 -> V_166 . T_7 . V_170 . V_212 ) ;
}
if ( V_40 -> V_67 . V_46 != NULL )
V_318 += sprintf ( & V_317 [ V_318 ] , L_154
L_155 ,
V_40 -> V_67 . V_46 -> V_52 . V_53 == V_54 ? 5 : 0 ,
F_7 ( & V_40 -> V_67 . V_6 ) ,
V_40 -> V_67 . V_46 == V_2 -> V_258 ? 'C' : 'U' ,
F_85 ( V_40 ) ? 'Y' : 'N' ) ;
V_317 [ V_318 ++ ] = '\n' ;
V_317 [ V_318 ] = '\0' ;
V_172:
F_138 ( & V_88 ) ;
return V_318 ;
}
static int T_4 F_201 ( struct V_9 * V_10 ,
const struct V_326 * V_327 )
{
struct V_1 * V_2 ;
struct V_274 * V_275 ;
int V_36 ;
V_2 = F_202 ( sizeof( * V_2 ) , V_180 ) ;
if ( V_2 == NULL ) {
F_31 (KERN_ERR DEV_LABEL
L_156 ) ;
return - V_94 ;
}
V_275 = F_203 ( V_301 , & V_10 -> V_307 , & V_328 , - 1 , NULL ) ;
if ( V_275 == NULL ) {
F_31 (KERN_ERR DEV_LABEL
L_157 ) ;
F_191 ( V_2 ) ;
return - V_251 ;
}
V_275 -> V_276 = V_2 ;
V_2 -> V_10 = V_10 ;
V_2 -> type = (enum V_329 ) V_327 -> V_330 ;
V_36 = F_180 ( V_275 ) ;
if ( V_36 != 0 ) {
F_24 ( L_158 , - V_36 ) ;
F_204 ( V_275 ) ;
F_191 ( V_2 ) ;
}
return V_36 ;
}
static int T_13 F_205 ( void )
{
int T_7 ;
T_7 = F_206 ( & V_331 ) ;
if ( T_7 != 0 )
F_31 (KERN_ERR DEV_LABEL L_159 ) ;
return T_7 ;
}
static void T_14 F_207 ( void )
{
F_24 ( L_160 ) ;
F_208 ( & V_331 ) ;
}
