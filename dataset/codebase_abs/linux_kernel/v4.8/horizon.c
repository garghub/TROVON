static inline void T_1 F_1 ( void ) {
F_2 ( L_1 , V_1 , V_2 ) ;
}
static inline void F_3 ( const T_2 * V_3 , unsigned char V_4 , T_3 V_5 ) {
F_4 ( F_5 ( V_5 ) , V_3 -> V_6 + V_4 ) ;
}
static inline T_3 F_6 ( const T_2 * V_3 , unsigned char V_4 ) {
return F_7 ( F_8 ( V_3 -> V_6 + V_4 ) ) ;
}
static inline void F_9 ( const T_2 * V_3 , unsigned char V_4 , T_4 V_5 ) {
F_10 ( F_11 ( V_5 ) , V_3 -> V_6 + V_4 ) ;
}
static inline T_4 F_12 ( const T_2 * V_3 , unsigned char V_4 ) {
return F_13 ( F_14 ( V_3 -> V_6 + V_4 ) ) ;
}
static inline void F_15 ( const T_2 * V_3 , unsigned char V_4 , void * V_7 , T_3 V_8 ) {
F_16 ( V_3 -> V_6 + V_4 , V_7 , V_8 ) ;
}
static inline void F_17 ( const T_2 * V_3 , unsigned char V_4 , void * V_7 , T_3 V_8 ) {
F_18 ( V_3 -> V_6 + V_4 , V_7 , V_8 ) ;
}
static inline void F_19 ( const T_2 * V_3 , T_5 * V_7 , T_3 V_5 ) {
F_3 ( V_3 , V_9 , ( V_7 - ( T_5 * ) 0 ) * sizeof( T_5 ) ) ;
F_3 ( V_3 , V_10 , V_5 ) ;
}
static inline T_3 F_20 ( const T_2 * V_3 , T_5 * V_7 ) {
F_3 ( V_3 , V_11 , ( V_7 - ( T_5 * ) 0 ) * sizeof( T_5 ) ) ;
return F_6 ( V_3 , V_10 ) ;
}
static inline void F_21 ( const T_2 * V_3 , T_3 V_7 , T_3 V_5 ) {
F_3 ( V_3 , V_9 , ( T_3 ) V_7 | 0x80000000 ) ;
F_3 ( V_3 , V_10 , V_5 ) ;
}
static inline T_3 F_22 ( const T_2 * V_3 , T_3 V_7 ) {
F_3 ( V_3 , V_11 , ( T_3 ) V_7 | 0x80000000 ) ;
return F_6 ( V_3 , V_10 ) ;
}
static inline void F_23 ( T_2 * V_3 , T_4 V_12 ) {
F_9 ( V_3 , V_13 , V_14 | V_12 ) ;
return;
}
static void F_24 ( T_2 * V_3 ) {
while ( F_12 ( V_3 , V_13 ) & V_14 )
;
return;
}
static inline void F_25 ( T_2 * V_3 , T_4 V_12 ) {
F_9 ( V_3 , V_13 , V_12 ) ;
return;
}
static void F_26 ( T_2 * V_3 ) {
while ( F_12 ( V_3 , V_13 ) & V_15 )
;
return;
}
static inline void F_27 ( T_2 * V_3 , T_4 V_16 ) {
F_3 ( V_3 , V_17 , V_16 ) ;
return;
}
static inline void F_28 ( T_2 * V_3 , short V_18 , T_6 V_19 , T_4 V_20 ) {
F_9 ( V_3 , V_21 ,
V_18 * V_22 | V_19 ) ;
F_9 ( V_3 , V_23 , V_20 ) ;
return;
}
static inline void F_29 ( char * V_24 , unsigned int V_25 , struct V_26 * V_27 ) {
#ifdef F_30
unsigned int V_28 ;
unsigned char * V_5 = V_27 -> V_5 ;
F_31 ( V_29 , L_2 , V_24 , V_25 ) ;
for ( V_28 = 0 ; V_28 < V_27 -> V_8 && V_28 < 256 ; V_28 ++ )
F_32 ( V_29 , L_3 , V_5 [ V_28 ] ) ;
F_33 ( V_29 , L_4 ) ;
#else
( void ) V_24 ;
( void ) V_25 ;
( void ) V_27 ;
#endif
return;
}
static inline void F_34 ( T_2 * V_3 ) {
#ifdef F_30
F_35 ( V_30 , L_5 , F_6 ( V_3 , V_31 ) ) ;
F_35 ( V_30 , L_6 , F_12 ( V_3 , V_32 ) ) ;
F_35 ( V_30 , L_7 , F_12 ( V_3 , V_33 ) ) ;
F_35 ( V_30 , L_8 , F_12 ( V_3 , V_34 ) ) ;
F_35 ( V_30 , L_9 , F_6 ( V_3 , V_35 ) ) ;
F_35 ( V_30 , L_10 , F_6 ( V_3 , V_36 ) ) ;
#else
( void ) V_3 ;
#endif
return;
}
static inline void F_36 ( T_2 * V_3 ) {
#ifdef F_30
unsigned int V_28 ;
F_31 ( V_30 , L_11 ) ;
for ( V_28 = 0 ; V_28 < 0x10 ; ++ V_28 )
F_32 ( V_30 , L_12 , F_22 ( V_3 , V_28 ) ) ;
F_33 ( V_30 , L_4 ) ;
#else
( void ) V_3 ;
#endif
return;
}
static inline int F_37 ( T_4 * V_12 , const short V_37 , const int V_38 ) {
unsigned short V_39 = 10 - V_40 ;
if ( 0 <= V_37 && V_37 < 1 << V_40 && 0 <= V_38 && V_38 < 1 << V_39 ) {
* V_12 = V_37 << V_39 | V_38 ;
return * V_12 ? 0 : - V_41 ;
}
return - V_41 ;
}
static inline T_4 F_38 ( T_3 V_42 ) {
return V_42 & V_43 ;
}
static inline T_4 F_39 ( T_3 V_42 ) {
return ( V_42 >> V_44 ) & V_45 ;
}
static int F_40 ( const T_2 * V_3 , T_3 V_46 , T_7 V_47 ,
T_4 * V_48 , unsigned int * V_49 )
{
const unsigned long V_50 = F_41 ( V_51 , & V_3 -> V_52 ) ? V_53 : V_54 ;
T_3 div = V_55 ;
T_3 V_56 ;
unsigned long V_57 = V_50 ;
unsigned int V_58 = 0 ;
F_35 ( V_59 | V_60 , L_13 , V_50 , V_46 ,
V_47 == V_61 ? L_14 : V_47 == V_62 ? L_15 : L_16 ) ;
if ( ! V_46 ) {
F_35 ( V_59 | V_63 , L_17 ) ;
return - V_41 ;
}
while ( V_58 < V_64 + V_55 && ( V_57 % 2 == 0 ) ) {
V_57 = V_57 >> 1 ;
++ V_58 ;
}
if ( V_57 <= ( V_46 << ( V_64 + V_55 - V_58 ) ) ) {
switch ( V_47 ) {
case V_62 :
V_56 = F_42 ( V_50 , V_46 << div ) ;
if ( ! V_56 )
V_56 = 1 ;
break;
case V_65 :
V_56 = F_43 ( V_50 , V_46 << div ) ;
if ( ! V_56 )
V_56 = 1 ;
break;
default:
V_56 = V_50 / ( V_46 << div ) ;
if ( ! V_56 )
return - V_41 ;
}
F_35 ( V_59 , L_18 , V_56 , div ) ;
goto V_66;
}
while ( div < V_67 ) {
div ++ ;
if ( V_57 <= ( V_46 << ( V_64 + div - V_58 ) ) ) {
switch ( V_47 ) {
case V_62 :
V_56 = F_42 ( V_50 , V_46 << div ) ;
break;
case V_65 :
V_56 = F_43 ( V_50 , V_46 << div ) ;
break;
default:
V_56 = V_50 / ( V_46 << div ) ;
}
F_35 ( V_59 , L_19 , V_56 , div ) ;
goto V_66;
}
}
if ( V_47 == V_62 )
return - V_41 ;
V_56 = 1 << V_64 ;
F_35 ( V_59 , L_20 , V_56 , div ) ;
V_66:
if ( div > V_67 || ( ! V_56 ) || V_56 > 1 << V_64 ) {
F_35 ( V_59 , L_21 ,
div , V_56 ) ;
return - V_41 ;
} else {
if ( V_48 )
* V_48 = ( div << V_68 ) | ( V_56 - 1 ) ;
if ( V_49 ) {
* V_49 = F_42 ( V_50 , V_56 << div ) ;
F_35 ( V_59 , L_22 , * V_49 ) ;
}
return 0 ;
}
}
static int F_44 ( const T_2 * V_3 , T_3 V_46 , T_7 V_47 , unsigned int V_69 ,
T_4 * V_70 , unsigned int * V_49 ) {
unsigned int V_71 ;
F_35 ( V_59 | V_60 , L_23 ,
V_46 , ( V_47 == V_61 ) ? L_14 : ( V_47 == V_62 ) ? L_15 : L_16 , V_69 ) ;
if ( ! V_49 )
V_49 = & V_71 ;
if ( F_40 ( V_3 , V_46 , V_65 , V_70 , V_49 ) )
return - 1 ;
if ( V_46 - V_69 <= * V_49 && * V_49 <= V_46 + V_69 )
return 0 ;
else
return F_40 ( V_3 , V_46 , V_47 , V_70 , V_49 ) ;
}
static int F_45 ( T_2 * V_3 , T_4 V_12 ) {
unsigned long V_52 ;
T_3 V_72 ;
T_4 V_73 = V_74 ;
T_8 * V_75 = & V_76 -> V_77 [ V_12 ] ;
F_35 ( V_60 , L_24 , V_12 ) ;
F_46 ( & V_3 -> V_78 , V_52 ) ;
V_72 = F_20 ( V_3 , & V_75 -> V_79 ) & V_80 ;
F_47 ( & V_3 -> V_78 , V_52 ) ;
if ( V_72 != V_81 ) {
F_35 ( V_63 | V_82 , L_25 ) ;
return - V_83 ;
}
if ( V_3 -> V_84 ) {
V_73 = V_3 -> V_85 [ -- V_3 -> V_84 ] ;
F_35 ( V_82 , L_26 , V_73 ) ;
if ( V_73 == V_81 || V_73 == V_74 ) {
F_35 ( V_63 | V_82 , L_27 ) ;
V_73 = V_74 ;
}
} else {
F_35 ( V_82 , L_28 ) ;
}
F_46 ( & V_3 -> V_78 , V_52 ) ;
F_19 ( V_3 , & V_75 -> V_79 ,
V_73 | V_86 | V_87 ) ;
if ( V_73 != V_74 )
F_19 ( V_3 , & V_75 -> V_88 , V_73 ) ;
F_47 ( & V_3 -> V_78 , V_52 ) ;
F_35 ( V_60 , L_29 ) ;
return 0 ;
}
static void F_48 ( struct V_26 * V_27 ) {
if ( F_49 ( V_27 ) -> V_89 -> V_90 ) {
F_49 ( V_27 ) -> V_89 -> V_90 ( F_49 ( V_27 ) -> V_89 , V_27 ) ;
} else {
F_50 ( V_27 ) ;
}
}
static void F_51 ( T_2 * V_3 , T_4 V_25 ) {
unsigned long V_52 ;
T_3 V_20 ;
T_3 V_91 , V_92 ;
T_8 * V_75 = & V_76 -> V_77 [ V_25 ] ;
int V_93 = 0 ;
F_46 ( & V_3 -> V_78 , V_52 ) ;
V_20 = F_20 ( V_3 , & V_75 -> V_79 ) & V_80 ;
F_47 ( & V_3 -> V_78 , V_52 ) ;
if ( V_20 == V_81 ) {
F_35 ( V_82 , L_30 , V_25 ) ;
return;
}
if ( V_20 == V_74 )
V_93 = 1 ;
F_46 ( & V_3 -> V_78 , V_52 ) ;
for (; ; ) {
F_19 ( V_3 , & V_75 -> V_79 , V_81 ) ;
if ( ( F_20 ( V_3 , & V_75 -> V_79 ) & V_80 ) == V_81 )
break;
V_93 = 0 ;
}
if ( V_93 ) {
F_47 ( & V_3 -> V_78 , V_52 ) ;
return;
}
F_24 ( V_3 ) ;
for (; ; ) {
T_4 V_94 = V_25 ^ ( V_95 / 2 ) ;
F_25 ( V_3 , V_94 ) ;
F_26 ( V_3 ) ;
V_91 = F_20 ( V_3 , & V_75 -> V_88 ) ;
F_25 ( V_3 , V_25 ) ;
F_26 ( V_3 ) ;
F_23 ( V_3 , V_25 ) ;
F_24 ( V_3 ) ;
F_25 ( V_3 , V_94 ) ;
F_26 ( V_3 ) ;
V_92 = F_20 ( V_3 , & V_75 -> V_88 ) ;
F_35 ( V_82 | V_96 , L_31 , V_91 , V_92 ) ;
if ( V_91 == V_92 ) {
V_3 -> V_85 [ V_3 -> V_84 ++ ] = ( T_4 ) V_91 ;
break;
}
}
#if 0
{
rx_q_entry * wr_ptr = &memmap->rx_q_entries[rd_regw (dev, RX_QUEUE_WR_PTR_OFF)];
rx_q_entry * rd_ptr = dev->rx_q_entry;
PRINTD (DBG_VCC|DBG_RX, "rd_ptr = %u, wr_ptr = %u", rd_ptr, wr_ptr);
while (rd_ptr != wr_ptr) {
u32 x = rd_mem (dev, (HDW *) rd_ptr);
if (vc == rx_q_entry_to_rx_channel (x)) {
x |= SIMONS_DODGEY_MARKER;
PRINTD (DBG_RX|DBG_VCC|DBG_WARN, "marking a frame as dodgey");
wr_mem (dev, (HDW *) rd_ptr, x);
}
if (rd_ptr == dev->rx_q_wrap)
rd_ptr = dev->rx_q_reset;
else
rd_ptr++;
}
}
#endif
F_47 ( & V_3 -> V_78 , V_52 ) ;
return;
}
static void F_52 ( T_2 * V_3 , int V_97 ) {
unsigned int V_98 ;
int V_99 = 0 ;
#ifndef F_53
V_99 = 1 ;
while ( V_99 ) {
#endif
V_98 = V_3 -> V_98 ;
#if 0
spin_count = 0;
while (rd_regl (dev, MASTER_RX_COUNT_REG_OFF)) {
PRINTD (DBG_RX|DBG_WARN, "RX error: other PCI Bus Master RX still in progress!");
if (++spin_count > 10) {
PRINTD (DBG_RX|DBG_ERR, "spun out waiting PCI Bus Master RX completion");
wr_regl (dev, MASTER_RX_COUNT_REG_OFF, 0);
clear_bit (rx_busy, &dev->flags);
hrz_kfree_skb (dev->rx_skb);
return;
}
}
#endif
if ( V_98 ) {
if ( V_98 <= V_100 ) {
F_35 ( V_96 | V_101 , L_32 ) ;
V_99 = 1 ;
}
if ( V_98 <= V_102 ) {
F_35 ( V_96 | V_101 , L_33 ) ;
V_3 -> V_98 = 0 ;
} else {
F_35 ( V_96 | V_101 , L_34 ) ;
V_3 -> V_98 = V_98 - V_102 ;
V_98 = V_102 ;
}
} else {
#if 0
unsigned int rx_regions = dev->rx_regions;
#else
unsigned int V_103 = 0 ;
#endif
if ( V_103 ) {
#if 0
dev->rx_addr = dev->rx_iovec->iov_base;
rx_bytes = dev->rx_iovec->iov_len;
++dev->rx_iovec;
dev->rx_regions = rx_regions - 1;
if (rx_bytes <= MAX_PIO_COUNT) {
PRINTD (DBG_RX|DBG_BUS, "(pio)");
pio_instead = 1;
}
if (rx_bytes <= MAX_TRANSFER_COUNT) {
PRINTD (DBG_RX|DBG_BUS, "(full region)");
dev->rx_bytes = 0;
} else {
PRINTD (DBG_RX|DBG_BUS, "(start multi region)");
dev->rx_bytes = rx_bytes - MAX_TRANSFER_COUNT;
rx_bytes = MAX_TRANSFER_COUNT;
}
#endif
} else {
struct V_26 * V_27 = V_3 -> V_104 ;
F_23 ( V_3 , V_3 -> V_105 ) ;
F_29 ( L_35 , V_3 -> V_105 , V_27 ) ;
F_35 ( V_96 | V_106 , L_36 , V_27 -> V_5 , V_27 -> V_8 ) ;
{
struct V_107 * V_89 = F_49 ( V_27 ) -> V_89 ;
F_54 ( & V_89 -> V_108 -> V_109 ) ;
F_55 ( V_27 ) ;
V_89 -> V_110 ( V_89 , V_27 ) ;
}
}
}
if ( V_98 ) {
if ( V_99 ) {
if ( V_97 )
F_3 ( V_3 , V_111 , 0 ) ;
F_17 ( V_3 , V_112 , V_3 -> V_113 , V_98 ) ;
} else {
F_3 ( V_3 , V_114 , F_56 ( V_3 -> V_113 ) ) ;
F_3 ( V_3 , V_111 , V_98 ) ;
}
V_3 -> V_113 += V_98 ;
} else {
if ( V_97 )
F_3 ( V_3 , V_111 , 0 ) ;
F_57 ( V_3 ) ;
F_58 ( V_115 , & V_3 -> V_52 ) ;
F_35 ( V_96 , L_37 , V_3 ) ;
}
#ifdef F_53
if ( V_99 )
return F_52 ( V_3 , 0 ) ;
return;
#else
V_97 = 0 ;
}
return;
#endif
}
static void F_59 ( T_2 * V_3 ) {
if ( F_41 ( V_115 , & V_3 -> V_52 ) ) {
F_52 ( V_3 , 1 ) ;
} else {
F_35 ( V_96 | V_63 , L_38 ) ;
F_3 ( V_3 , V_111 , 0 ) ;
}
return;
}
static int F_60 ( T_2 * V_3 ) {
F_35 ( V_116 , L_39 , V_3 , V_3 -> V_52 ) ;
F_61 ( V_3 -> V_117 , ( ! F_62 ( V_118 , & V_3 -> V_52 ) ) ) ;
F_35 ( V_116 , L_40 , V_3 , V_3 -> V_52 ) ;
if ( F_63 ( V_119 ) )
return - 1 ;
F_35 ( V_116 , L_41 , V_3 ) ;
return 0 ;
}
static inline void F_64 ( T_2 * V_3 ) {
F_58 ( V_118 , & V_3 -> V_52 ) ;
F_35 ( V_116 , L_42 , V_3 ) ;
F_65 ( & V_3 -> V_117 ) ;
}
static void F_66 ( T_2 * const V_3 , int V_97 ) {
unsigned int V_120 ;
int V_121 = 0 ;
int V_99 = 0 ;
#ifndef F_53
V_99 = 1 ;
while ( V_99 ) {
#endif
V_120 = V_3 -> V_120 ;
#if 0
spin_count = 0;
while (rd_regl (dev, MASTER_TX_COUNT_REG_OFF)) {
PRINTD (DBG_TX|DBG_WARN, "TX error: other PCI Bus Master TX still in progress!");
if (++spin_count > 10) {
PRINTD (DBG_TX|DBG_ERR, "spun out waiting PCI Bus Master TX completion");
wr_regl (dev, MASTER_TX_COUNT_REG_OFF, 0);
tx_release (dev);
hrz_kfree_skb (dev->tx_skb);
return;
}
}
#endif
if ( V_120 ) {
if ( ! F_41 ( V_51 , & V_3 -> V_52 ) || V_120 <= V_100 ) {
F_35 ( V_116 | V_101 , L_32 ) ;
V_99 = 1 ;
}
if ( V_120 <= V_102 ) {
F_35 ( V_116 | V_101 , L_33 ) ;
if ( ! V_3 -> V_122 ) {
V_121 = 1 ;
}
V_3 -> V_120 = 0 ;
} else {
F_35 ( V_116 | V_101 , L_34 ) ;
V_3 -> V_120 = V_120 - V_102 ;
V_120 = V_102 ;
}
} else {
unsigned int V_123 = V_3 -> V_123 ;
if ( V_123 ) {
V_3 -> V_124 = V_3 -> V_122 -> V_125 ;
V_120 = V_3 -> V_122 -> V_126 ;
++ V_3 -> V_122 ;
V_3 -> V_123 = V_123 - 1 ;
if ( ! F_41 ( V_51 , & V_3 -> V_52 ) || V_120 <= V_100 ) {
F_35 ( V_116 | V_101 , L_32 ) ;
V_99 = 1 ;
}
if ( V_120 <= V_102 ) {
F_35 ( V_116 | V_101 , L_43 ) ;
V_3 -> V_120 = 0 ;
} else {
F_35 ( V_116 | V_101 , L_44 ) ;
V_3 -> V_120 = V_120 - V_102 ;
V_120 = V_102 ;
}
} else {
struct V_26 * V_27 = V_3 -> V_127 ;
V_3 -> V_122 = NULL ;
F_54 ( & F_49 ( V_27 ) -> V_89 -> V_108 -> V_128 ) ;
F_48 ( V_27 ) ;
}
}
if ( V_120 ) {
if ( V_99 ) {
if ( V_97 )
F_3 ( V_3 , V_129 , 0 ) ;
F_15 ( V_3 , V_112 , V_3 -> V_124 , V_120 ) ;
if ( V_121 )
F_3 ( V_3 , V_130 , F_67 ( V_3 -> V_127 -> V_8 ) ) ;
} else {
F_3 ( V_3 , V_131 , F_56 ( V_3 -> V_124 ) ) ;
if ( V_121 )
F_3 ( V_3 , V_132 , F_67 ( V_3 -> V_127 -> V_8 ) ) ;
F_3 ( V_3 , V_129 ,
V_121
? V_120 | V_133
: V_120 ) ;
}
V_3 -> V_124 += V_120 ;
} else {
if ( V_97 )
F_3 ( V_3 , V_129 , 0 ) ;
F_57 ( V_3 ) ;
F_64 ( V_3 ) ;
}
#ifdef F_53
if ( V_99 )
return F_66 ( V_3 , 0 ) ;
return;
#else
V_97 = 0 ;
}
return;
#endif
}
static void F_68 ( T_2 * V_3 ) {
if ( F_41 ( V_118 , & V_3 -> V_52 ) ) {
F_66 ( V_3 , 1 ) ;
} else {
F_35 ( V_116 | V_63 , L_45 ) ;
F_3 ( V_3 , V_129 , 0 ) ;
}
return;
}
static T_3 F_69 ( T_2 * V_3 ) {
T_3 V_134 ;
F_70 ( & V_3 -> V_78 ) ;
V_134 = F_20 ( V_3 , & V_3 -> V_135 -> V_136 ) ;
if ( V_3 -> V_135 == V_3 -> V_137 )
V_3 -> V_135 = V_3 -> V_138 ;
else
V_3 -> V_135 ++ ;
F_9 ( V_3 , V_139 , V_3 -> V_135 - V_3 -> V_138 ) ;
F_71 ( & V_3 -> V_78 ) ;
return V_134 ;
}
static void F_72 ( T_2 * V_3 ) {
T_3 V_134 ;
T_3 V_140 ;
T_4 V_141 ;
T_4 V_105 ;
F_35 ( V_60 , L_46 ) ;
if ( F_62 ( V_115 , & V_3 -> V_52 ) ) {
F_35 ( V_96 , L_47 ) ;
return;
}
F_35 ( V_96 , L_48 , V_3 ) ;
F_73 ( V_3 ) ;
V_134 = F_69 ( V_3 ) ;
V_141 = F_38 ( V_134 ) ;
V_105 = F_39 ( V_134 ) ;
F_24 ( V_3 ) ;
F_25 ( V_3 , V_105 ) ;
F_35 ( V_96 , L_49 , V_134 ) ;
V_140 = V_134 & ( V_142 | V_143 | V_144 ) ;
if ( ! V_141 ) {
F_74 ( V_145 , L_50 ) ;
V_140 &= ~ V_143 ;
}
if ( V_140 & V_144 ) {
F_35 ( V_96 | V_63 , L_51 ) ;
}
if ( V_140 == ( V_142 | V_143 ) ) {
struct V_107 * V_107 ;
F_35 ( V_96 , L_52 , V_105 , V_141 ) ;
V_107 = V_3 -> V_146 [ V_105 ] ;
if ( V_107 ) {
if ( V_107 -> V_147 . V_148 . V_149 != V_150 ) {
if ( V_141 <= V_107 -> V_147 . V_148 . V_151 ) {
struct V_26 * V_27 = F_75 ( V_107 , V_141 , V_152 ) ;
if ( V_27 ) {
V_3 -> V_104 = V_27 ;
V_3 -> V_105 = V_105 ;
F_76 ( V_27 , V_141 ) ;
F_49 ( V_27 ) -> V_89 = V_107 ;
V_3 -> V_98 = V_141 ;
V_3 -> V_113 = V_27 -> V_5 ;
F_35 ( V_96 , L_53 ,
V_27 -> V_5 , V_141 ) ;
F_52 ( V_3 , 0 ) ;
return;
} else {
F_35 ( V_106 | V_153 , L_54 ) ;
}
} else {
F_74 ( V_154 , L_55 , V_105 ) ;
}
} else {
F_74 ( V_155 , L_56 ) ;
}
} else {
F_35 ( V_153 | V_82 | V_96 , L_57 ) ;
}
} else {
}
F_57 ( V_3 ) ;
F_23 ( V_3 , V_105 ) ;
F_58 ( V_115 , & V_3 -> V_52 ) ;
return;
}
static T_9 F_77 ( int V_97 , void * V_156 )
{
T_2 * V_3 = V_156 ;
T_3 V_157 ;
unsigned int V_158 ;
F_35 ( V_60 , L_58 , V_156 ) ;
V_158 = 0 ;
while ( ( V_157 = F_6 ( V_3 , V_36 )
& V_159 ) ) {
if ( V_157 & V_160 ) {
++ V_158 ;
F_35 ( V_161 | V_101 | V_96 , L_59 ) ;
F_59 ( V_3 ) ;
}
if ( V_157 & V_162 ) {
++ V_158 ;
F_35 ( V_161 | V_101 | V_116 , L_60 ) ;
F_68 ( V_3 ) ;
}
if ( V_157 & V_163 ) {
++ V_158 ;
F_35 ( V_161 | V_96 , L_61 ) ;
F_72 ( V_3 ) ;
}
}
if ( V_158 ) {
F_35 ( V_161 , L_62 , V_158 ) ;
} else {
F_35 ( V_161 | V_153 , L_63 , V_157 ) ;
}
F_35 ( V_161 | V_60 , L_64 , V_156 ) ;
if ( V_158 )
return V_164 ;
return V_165 ;
}
static void F_78 ( unsigned long V_166 ) {
T_2 * V_3 = ( T_2 * ) V_166 ;
V_3 -> V_167 += F_12 ( V_3 , V_168 ) ;
V_3 -> V_169 += F_12 ( V_3 , V_170 ) ;
V_3 -> V_171 += F_12 ( V_3 , V_172 ) ;
V_3 -> V_173 += F_12 ( V_3 , V_174 ) ;
F_79 ( & V_3 -> V_175 , V_176 + V_177 / 10 ) ;
return;
}
static short F_80 ( T_2 * V_3 , T_10 * V_89 ) {
unsigned short V_178 ;
short V_16 = - 1 ;
unsigned int V_179 ;
F_35 ( V_60 | V_116 , L_65 , V_3 ) ;
V_179 = 0 ;
while ( ! ( V_178 = F_12 ( V_3 , V_34 ) & V_180 ) ) {
F_35 ( V_116 | V_153 , L_66 ) ;
if ( ++ V_179 > 100 ) {
F_35 ( V_116 | V_63 , L_67 ) ;
return - V_83 ;
}
}
{
int V_18 = V_3 -> V_181 ;
int V_182 = 1 ;
while ( V_182 ) {
if ( V_178 & ( 1 << V_18 ) ) {
V_16 = V_18 ;
V_182 = 0 ;
}
++ V_18 ;
if ( V_18 == V_183 )
V_18 = 0 ;
}
V_3 -> V_181 = V_18 ;
}
{
T_11 * V_184 = & V_76 -> V_185 [ V_16 ] ;
T_3 V_186 ;
T_3 V_187 ;
T_4 V_12 = V_89 -> V_12 ;
unsigned long V_52 ;
F_46 ( & V_3 -> V_78 , V_52 ) ;
V_3 -> V_188 [ V_16 ] = V_12 ;
F_28 ( V_3 , V_16 , V_189 ,
V_89 -> V_190 ) ;
F_28 ( V_3 , V_16 , V_191 ,
V_89 -> V_192 ) ;
#if 0
if (vcc->tx_xbr_bits == VBR_RATE_TYPE) {
update_tx_channel_config (dev, tx_channel, SCR_TIMER_ACCESS,
vcc->tx_scr_bits);
update_tx_channel_config (dev, tx_channel, BUCKET_CAPACITY_ACCESS,
vcc->tx_bucket_bits);
update_tx_channel_config (dev, tx_channel, BUCKET_FULLNESS_ACCESS,
vcc->tx_bucket_bits);
}
#endif
V_186 = F_20 ( V_3 , & V_184 -> V_88 ) & V_80 ;
V_187 = F_20 ( V_3 , & V_184 -> V_79 ) & V_80 ;
if ( V_186 != V_187 ) {
F_35 ( V_116 | V_63 , L_68 ) ;
}
F_35 ( V_116 , L_69 ,
V_186 , V_187 ) ;
switch ( V_89 -> V_193 ) {
case V_194 :
F_35 ( V_59 | V_116 , L_70 ) ;
V_186 |= V_195 ;
V_187 |= V_195 ;
break;
case V_196 :
F_35 ( V_59 | V_116 , L_71 ) ;
V_186 |= V_197 ;
V_187 |= V_197 ;
break;
case V_198 :
V_186 |= V_86 ;
V_187 |= V_86 ;
F_19 ( V_3 , & V_184 -> V_199 , V_200 ) ;
break;
}
F_19 ( V_3 , & V_184 -> V_88 , V_186 ) ;
F_19 ( V_3 , & V_184 -> V_79 , V_187 ) ;
F_19 ( V_3 , & V_184 -> V_201 , V_12 ) ;
F_47 ( & V_3 -> V_78 , V_52 ) ;
}
return V_16 ;
}
static int F_81 ( struct V_107 * V_107 , struct V_26 * V_27 ) {
unsigned int V_179 ;
int V_202 ;
T_2 * V_3 = F_82 ( V_107 -> V_3 ) ;
T_10 * V_89 = F_83 ( V_107 ) ;
T_4 V_12 = V_89 -> V_12 ;
T_3 V_203 ;
short V_16 ;
F_35 ( V_60 | V_116 , L_72 ,
V_12 , V_27 -> V_5 , V_27 -> V_8 ) ;
F_29 ( L_73 , V_12 , V_27 ) ;
if ( V_107 -> V_147 . V_204 . V_149 == V_150 ) {
F_74 ( V_145 , L_74 , V_12 ) ;
F_48 ( V_27 ) ;
return - V_205 ;
}
F_49 ( V_27 ) -> V_89 = V_107 ;
if ( V_27 -> V_8 > V_107 -> V_147 . V_204 . V_151 ) {
F_74 ( V_145 , L_75 ) ;
F_48 ( V_27 ) ;
return - V_205 ;
}
if ( ! V_12 ) {
F_35 ( V_63 | V_116 , L_76 ) ;
F_48 ( V_27 ) ;
return - V_205 ;
}
#if 0
{
u16 status;
pci_read_config_word (dev->pci_dev, PCI_STATUS, &status);
if (status & PCI_STATUS_REC_MASTER_ABORT) {
PRINTD (DBG_BUS|DBG_ERR, "Clearing PCI Master Abort (and cleaning up)");
status &= ~PCI_STATUS_REC_MASTER_ABORT;
pci_write_config_word (dev->pci_dev, PCI_STATUS, status);
if (test_bit (tx_busy, &dev->flags)) {
hrz_kfree_skb (dev->tx_skb);
tx_release (dev);
}
}
}
#endif
#ifdef F_30
if ( V_12 == 1023 ) {
unsigned int V_28 ;
unsigned short V_206 = 0 ;
char * V_207 = V_27 -> V_5 ;
if ( * V_207 ++ == 'D' ) {
for ( V_28 = 0 ; V_28 < 4 ; ++ V_28 )
V_206 = ( V_206 << 4 ) | F_84 ( * V_207 ++ ) ;
F_74 ( V_154 , L_77 , V_208 = V_206 ) ;
}
}
#endif
if ( F_60 ( V_3 ) ) {
F_48 ( V_27 ) ;
return - V_209 ;
}
V_203 = ( V_27 -> V_8 + ( V_210 - 1 ) ) / V_211 + 3 ;
V_179 = 0 ;
while ( ( V_202 = F_12 ( V_3 , V_212 ) ) < V_203 ) {
F_35 ( V_116 , L_78 ,
V_202 , V_203 ) ;
F_85 () ;
if ( ++ V_179 > 1000 ) {
F_35 ( V_116 | V_63 , L_79 ,
V_202 , V_203 ) ;
F_64 ( V_3 ) ;
F_48 ( V_27 ) ;
return - V_209 ;
}
}
if ( V_12 == V_3 -> V_213 ) {
F_35 ( V_116 , L_80 ) ;
V_16 = V_3 -> V_214 ;
} else {
F_35 ( V_116 , L_81 ) ;
for ( V_16 = 0 ; V_16 < V_183 ; ++ V_16 )
if ( V_3 -> V_188 [ V_16 ] == V_12 ) {
F_35 ( V_116 , L_82 ) ;
break;
}
if ( V_16 == V_183 ) {
F_35 ( V_116 , L_83 ) ;
V_16 = F_80 ( V_3 , V_89 ) ;
if ( V_16 < 0 ) {
F_35 ( V_116 | V_63 , L_84 ) ;
F_64 ( V_3 ) ;
return V_16 ;
}
}
F_35 ( V_116 , L_85 ) ;
F_27 ( V_3 , V_16 ) ;
V_3 -> V_213 = V_12 ;
V_3 -> V_214 = V_16 ;
}
F_35 ( V_116 , L_86 , V_16 ) ;
F_73 ( V_3 ) ;
{
unsigned int V_215 = V_27 -> V_8 ;
unsigned int V_216 = F_86 ( V_27 ) -> V_217 ;
V_3 -> V_127 = V_27 ;
if ( V_216 ) {
V_3 -> V_123 = V_216 ;
V_3 -> V_122 = NULL ;
V_3 -> V_120 = 0 ;
F_35 ( V_116 | V_101 , L_87 ,
V_27 -> V_5 , V_215 ) ;
F_64 ( V_3 ) ;
F_48 ( V_27 ) ;
return - V_205 ;
} else {
V_3 -> V_123 = 0 ;
V_3 -> V_122 = NULL ;
V_3 -> V_120 = V_215 ;
V_3 -> V_124 = V_27 -> V_5 ;
F_35 ( V_116 | V_101 , L_88 ,
V_27 -> V_5 , V_215 ) ;
}
F_66 ( V_3 , 0 ) ;
}
return 0 ;
}
static void F_87 ( const T_2 * V_3 ) {
T_3 V_218 = F_6 ( V_3 , V_31 ) ;
V_218 = V_218 & V_219 ;
F_3 ( V_3 , V_31 , V_218 ) ;
while ( V_218 & V_219 )
V_218 = F_6 ( V_3 , V_31 ) ;
F_3 ( V_3 , V_31 , V_218 |
V_220 | V_221 | V_222 | V_223 ) ;
F_88 ( 1000 ) ;
F_3 ( V_3 , V_31 , V_218 ) ;
}
static void F_89 ( const T_2 * V_3 , T_3 V_224 )
{
F_3 ( V_3 , V_31 , V_224 ) ;
F_88 ( 5 ) ;
}
static void F_90 ( const T_2 * V_3 , T_3 V_224 )
{
F_89 ( V_3 , V_224 & ~ V_225 ) ;
F_89 ( V_3 , V_224 | V_225 ) ;
}
static T_4 F_91 ( const T_2 * V_3 , T_4 V_7 )
{
T_3 V_224 = F_6 ( V_3 , V_31 ) ;
const unsigned int V_226 = 6 ;
const unsigned int V_227 = 16 ;
unsigned int V_28 ;
T_4 V_228 ;
V_224 &= ~ ( V_229 | V_225 | V_230 ) ;
F_89 ( V_3 , V_224 ) ;
V_224 |= ( V_229 | V_230 ) ;
F_90 ( V_3 , V_224 ) ;
V_224 |= V_230 ;
F_90 ( V_3 , V_224 ) ;
V_224 &= ~ V_230 ;
F_90 ( V_3 , V_224 ) ;
for ( V_28 = 0 ; V_28 < V_226 ; V_28 ++ ) {
if ( V_7 & ( 1 << ( V_226 - 1 ) ) )
V_224 |= V_230 ;
else
V_224 &= ~ V_230 ;
F_90 ( V_3 , V_224 ) ;
V_7 = V_7 << 1 ;
}
V_224 &= ~ V_230 ;
V_228 = 0 ;
for ( V_28 = 0 ; V_28 < V_227 ; V_28 ++ ) {
V_228 = V_228 >> 1 ;
F_90 ( V_3 , V_224 ) ;
if ( F_6 ( V_3 , V_31 ) & V_231 )
V_228 |= ( 1 << ( V_227 - 1 ) ) ;
}
V_224 &= ~ ( V_225 | V_229 ) ;
F_89 ( V_3 , V_224 ) ;
return V_228 ;
}
static int F_92 ( T_2 * V_3 )
{
int V_232 ;
T_4 V_18 ;
int V_233 ;
T_5 * V_234 ;
T_12 * V_184 ;
T_12 * V_75 ;
T_3 V_224 ;
V_224 = F_6 ( V_3 , V_31 ) ;
F_35 ( V_235 , L_89 , V_224 ) ;
V_232 = V_224 & V_236 ;
if ( V_232 )
F_2 ( V_237 L_90 ) ;
else
F_2 ( V_237 L_91 ) ;
F_2 ( L_92 ) ;
F_2 ( L_93 ) ;
F_87 ( V_3 ) ;
F_2 ( L_94 ) ;
for ( V_234 = ( T_5 * ) V_76 ; V_234 < ( T_5 * ) ( V_76 + 1 ) ; ++ V_234 )
F_19 ( V_3 , V_234 , 0 ) ;
F_2 ( L_95 ) ;
for ( V_18 = 0 ; V_18 < V_183 ; ++ V_18 ) {
T_11 * V_184 = & V_76 -> V_185 [ V_18 ] ;
T_12 * V_238 = & V_76 -> V_239 [ V_18 ] ;
F_19 ( V_3 , & V_184 -> V_88 , F_93 ( V_238 ) ) ;
F_19 ( V_3 , & V_184 -> V_79 , F_93 ( V_238 ) ) ;
F_19 ( V_3 , & V_238 -> V_240 , V_241 ) ;
}
F_2 ( L_96 ) ;
V_184 = V_76 -> V_242 ;
F_19 ( V_3 , & V_76 -> V_243 . V_240 , F_93 ( V_184 ) | V_241 ) ;
for ( V_233 = 0 ; V_233 < V_244 - 1 ; V_233 ++ ) {
F_19 ( V_3 , & V_184 -> V_240 , F_93 ( V_184 + 1 ) | V_241 ) ;
V_184 ++ ;
}
F_19 ( V_3 , & V_184 -> V_240 , F_93 ( & V_76 -> V_245 ) | V_241 ) ;
F_9 ( V_3 , V_212 , V_244 ) ;
F_2 ( L_97 ) ;
for ( V_18 = 0 ; V_18 < V_95 ; ++ V_18 ) {
T_8 * V_75 = & V_76 -> V_77 [ V_18 ] ;
F_19 ( V_3 , & V_75 -> V_79 , V_86 | V_81 ) ;
}
F_2 ( L_98 ) ;
V_75 = V_76 -> V_246 ;
F_19 ( V_3 , & V_76 -> V_247 . V_240 , F_93 ( V_75 ) | V_241 ) ;
for ( V_233 = 0 ; V_233 < V_248 - 1 ; V_233 ++ ) {
F_19 ( V_3 , & V_75 -> V_240 , F_93 ( V_75 + 1 ) | V_241 ) ;
V_75 ++ ;
}
F_19 ( V_3 , & V_75 -> V_240 , F_93 ( & V_76 -> V_249 ) | V_241 ) ;
F_9 ( V_3 , V_250 , V_248 ) ;
F_9 ( V_3 , V_33 ,
V_251 | V_252 | V_253 ) ;
F_9 ( V_3 , V_32 ,
V_254 | V_255 | V_40 ) ;
F_9 ( V_3 , V_256 ,
V_257 | V_258 | V_259 ) ;
F_9 ( V_3 , V_260 ,
F_42 ( V_261 + V_210 , V_211 ) ) ;
F_9 ( V_3 , V_32 , F_12 ( V_3 , V_32 ) | V_262 ) ;
F_2 ( L_99 ) ;
V_224 |= V_263 | V_264 | V_265 | V_266 ;
F_3 ( V_3 , V_31 , V_224 ) ;
if ( V_232 ) {
V_224 |= V_267 ;
F_3 ( V_3 , V_31 , V_224 ) ;
if ( F_22 ( V_3 , 0 ) & 0x00f0 ) {
F_2 ( L_100 ) ;
F_21 ( V_3 , 0x00 , 0x0080 ) ;
F_21 ( V_3 , 0x00 , 0x0000 ) ;
F_21 ( V_3 , 0x63 , F_22 ( V_3 , 0x63 ) | 0x0002 ) ;
F_21 ( V_3 , 0x05 , F_22 ( V_3 , 0x05 ) | 0x0001 ) ;
} else {
F_2 ( L_101 ) ;
F_21 ( V_3 , 0 , F_22 ( V_3 , 0 ) | 0x0001 ) ;
F_21 ( V_3 , 0 , F_22 ( V_3 , 0 ) & ~ 0x0001 ) ;
F_21 ( V_3 , 0 , 0x0002 ) ;
F_21 ( V_3 , 2 , 0x0B80 ) ;
}
} else {
V_224 &= ~ V_267 ;
}
F_2 ( L_102 ) ;
F_94 ( V_3 ) ;
F_57 ( V_3 ) ;
F_2 ( L_103 ) ;
{
T_4 V_268 = 0 ;
int V_28 ;
T_6 * V_269 = V_3 -> V_270 -> V_269 ;
for ( V_28 = 0 ; V_28 < V_271 ; ++ V_28 ) {
if ( V_28 % 2 == 0 )
V_268 = F_91 ( V_3 , V_28 / 2 + 2 ) ;
else
V_268 = V_268 >> 8 ;
V_269 [ V_28 ] = V_268 & 0xFF ;
F_2 ( L_104 , V_269 [ V_28 ] ) ;
}
}
F_3 ( V_3 , V_35 , V_159 ) ;
F_2 ( L_105 ) ;
F_2 ( L_106 ) ;
return V_232 ;
}
static int F_95 ( T_13 V_193 , struct V_272 * V_273 , unsigned int V_274 ) {
F_35 ( V_60 | V_59 , L_107 ) ;
switch ( V_193 ) {
case V_194 :
if ( ! ( V_273 -> V_151 ) ) {
F_35 ( V_59 , L_108 ) ;
V_273 -> V_151 = V_275 ;
} else if ( V_273 -> V_151 != V_275 ) {
F_35 ( V_59 | V_63 , L_109 ) ;
return - V_41 ;
}
break;
case V_196 :
if ( V_273 -> V_151 == 0 || V_273 -> V_151 > V_276 ) {
F_35 ( V_59 , L_110 , V_273 -> V_151 ? L_111 : L_112 ) ;
V_273 -> V_151 = V_276 ;
}
break;
case V_198 :
if ( V_273 -> V_151 == 0 || V_273 -> V_151 > V_274 ) {
F_35 ( V_59 , L_110 , V_273 -> V_151 ? L_111 : L_112 ) ;
V_273 -> V_151 = V_274 ;
}
break;
}
return 0 ;
}
static int F_96 ( struct V_272 * V_273 , unsigned int V_277 ) {
if ( V_273 -> V_278 == V_279 )
F_35 ( V_59 , L_113 ) ;
else if ( V_273 -> V_278 < 0 )
F_35 ( V_59 , L_114 ) ;
else if ( V_273 -> V_278 && V_273 -> V_278 > V_277 )
F_35 ( V_59 , L_115 ) ;
else
if ( ( 0 ) && V_273 -> V_280 == V_279 )
F_35 ( V_59 , L_116 ) ;
else if ( ( V_273 -> V_280 != V_279 ) && V_273 -> V_280 < 0 )
F_35 ( V_59 , L_117 ) ;
else if ( V_273 -> V_280 && V_273 -> V_280 != V_279 && V_273 -> V_280 < V_277 )
F_35 ( V_59 , L_118 ) ;
else {
F_35 ( V_59 , L_119 ) ;
return 0 ;
}
F_35 ( V_59 , L_120 ,
V_277 , V_273 -> V_278 , V_273 -> V_277 , V_273 -> V_280 ) ;
return - V_41 ;
}
static int F_97 ( struct V_107 * V_107 )
{
int error ;
T_4 V_12 ;
struct V_281 * V_147 ;
struct V_272 * V_204 ;
struct V_272 * V_148 ;
T_2 * V_3 = F_82 ( V_107 -> V_3 ) ;
T_10 V_89 ;
T_10 * V_282 ;
short V_37 = V_107 -> V_37 ;
int V_38 = V_107 -> V_38 ;
F_35 ( V_60 | V_82 , L_121 , V_37 , V_38 ) ;
#ifdef F_98
if ( V_37 == F_98 || V_38 == V_283 ) {
F_74 ( V_155 , L_122 ) ;
return - V_41 ;
}
#endif
error = F_37 ( & V_12 , V_37 , V_38 ) ;
if ( error ) {
F_35 ( V_153 | V_82 , L_123 , V_37 , V_38 ) ;
return error ;
}
V_89 . V_12 = V_12 ;
V_89 . V_284 = 0x0 ;
V_147 = & V_107 -> V_147 ;
switch ( V_147 -> V_193 ) {
case V_285 :
F_35 ( V_59 | V_82 , L_124 ) ;
V_89 . V_193 = V_194 ;
break;
case V_286 :
F_35 ( V_59 | V_82 , L_125 ) ;
V_89 . V_193 = V_196 ;
break;
case V_287 :
F_35 ( V_59 | V_82 , L_126 ) ;
V_89 . V_193 = V_198 ;
break;
default:
F_35 ( V_59 | V_82 , L_127 ) ;
return - V_41 ;
}
F_35 ( V_59 , L_128 ) ;
V_204 = & V_147 -> V_204 ;
V_89 . V_284 = 0 ;
V_89 . V_190 = V_288 ;
V_89 . V_192 = V_289 ;
#if 0
vcc.tx_scr_bits = CLOCK_DISABLE;
vcc.tx_bucket_bits = 0;
#endif
if ( V_204 -> V_149 != V_150 ) {
error = F_95 ( V_89 . V_193 , V_204 , V_290 ) ;
if ( error ) {
F_35 ( V_59 , L_129 ) ;
return error ;
}
switch ( V_204 -> V_149 ) {
case V_291 : {
V_89 . V_284 = 0 ;
F_40 ( V_3 , 1 << 30 , V_65 , & V_89 . V_192 , NULL ) ;
V_89 . V_190 = V_292 ;
break;
}
#if 0
case ATM_ABR: {
vcc.tx_rate = 0;
make_rate (dev, 1<<30, round_nearest, &vcc.tx_pcr_bits, 0);
vcc.tx_xbr_bits = ABR_RATE_TYPE;
break;
}
#endif
case V_293 : {
int V_277 = F_99 ( V_204 ) ;
T_7 V_47 ;
if ( ! V_277 ) {
V_47 = V_62 ;
F_35 ( V_59 , L_130 ) ;
V_277 = V_3 -> V_294 ;
} else if ( V_277 < 0 ) {
V_47 = V_62 ;
V_277 = - V_277 ;
} else {
V_47 = V_61 ;
}
error = F_44 ( V_3 , V_277 , V_47 , 10 ,
& V_89 . V_192 , & V_89 . V_284 ) ;
if ( error ) {
F_35 ( V_59 , L_131 ) ;
return error ;
}
error = F_96 ( V_204 , V_89 . V_284 ) ;
if ( error ) {
F_35 ( V_59 , L_132 ) ;
return error ;
}
V_89 . V_190 = V_295 ;
break;
}
#if 0
case ATM_VBR: {
int pcr = atm_pcr_goal (txtp);
int scr = pcr/2;
unsigned int mbs = 60;
rounding pr;
rounding sr;
unsigned int bucket;
if (!pcr) {
pr = round_nearest;
pcr = 1<<30;
} else if (pcr < 0) {
pr = round_down;
pcr = -pcr;
} else {
pr = round_up;
}
error = make_rate_with_tolerance (dev, pcr, pr, 10,
&vcc.tx_pcr_bits, 0);
if (!scr) {
sr = round_down;
PRINTD (DBG_QOS, "snatching all remaining TX bandwidth");
scr = dev->tx_avail;
} else if (scr < 0) {
sr = round_down;
scr = -scr;
} else {
sr = round_up;
}
error = make_rate_with_tolerance (dev, scr, sr, 10,
&vcc.tx_scr_bits, &vcc.tx_rate);
if (error) {
PRINTD (DBG_QOS, "could not make rate from TX SCR");
return error;
}
if (error) {
PRINTD (DBG_QOS, "TX SCR failed consistency check");
return error;
}
bucket = mbs*(pcr-scr)/pcr;
if (bucket*pcr != mbs*(pcr-scr))
bucket += 1;
if (bucket > BUCKET_MAX_SIZE) {
PRINTD (DBG_QOS, "shrinking bucket from %u to %u",
bucket, BUCKET_MAX_SIZE);
bucket = BUCKET_MAX_SIZE;
}
vcc.tx_xbr_bits = VBR_RATE_TYPE;
vcc.tx_bucket_bits = bucket;
break;
}
#endif
default: {
F_35 ( V_59 , L_133 ) ;
return - V_41 ;
}
}
}
F_35 ( V_59 , L_134 ) ;
V_148 = & V_147 -> V_148 ;
V_89 . V_296 = 0 ;
if ( V_148 -> V_149 != V_150 ) {
error = F_95 ( V_89 . V_193 , V_148 , V_261 ) ;
if ( error ) {
F_35 ( V_59 , L_135 ) ;
return error ;
}
switch ( V_148 -> V_149 ) {
case V_291 : {
break;
}
#if 0
case ATM_ABR: {
vcc.rx_rate = 0;
break;
}
#endif
case V_293 : {
int V_277 = F_99 ( V_148 ) ;
if ( ! V_277 ) {
F_35 ( V_59 , L_136 ) ;
V_277 = V_3 -> V_297 ;
} else if ( V_277 < 0 ) {
V_277 = - V_277 ;
}
V_89 . V_296 = V_277 ;
error = F_96 ( V_148 , V_89 . V_296 ) ;
if ( error ) {
F_35 ( V_59 , L_137 ) ;
return error ;
}
break;
}
#if 0
case ATM_VBR: {
int scr = 1<<16;
if (!scr) {
PRINTD (DBG_QOS, "snatching all remaining RX bandwidth");
scr = dev->rx_avail;
} else if (scr < 0) {
scr = -scr;
}
vcc.rx_rate = scr;
if (error) {
PRINTD (DBG_QOS, "RX SCR failed consistency check");
return error;
}
break;
}
#endif
default: {
F_35 ( V_59 , L_138 ) ;
return - V_41 ;
}
}
}
if ( V_89 . V_193 != V_198 ) {
F_35 ( V_59 , L_139 ) ;
return - V_41 ;
}
V_282 = F_100 ( sizeof( T_10 ) , V_298 ) ;
if ( ! V_282 ) {
F_74 ( V_145 , L_140 ) ;
return - V_299 ;
}
* V_282 = V_89 ;
error = 0 ;
F_70 ( & V_3 -> V_300 ) ;
if ( V_89 . V_284 > V_3 -> V_294 ) {
F_35 ( V_59 , L_141 ) ;
error = - V_301 ;
}
if ( V_89 . V_296 > V_3 -> V_297 ) {
F_35 ( V_59 , L_142 ) ;
error = - V_301 ;
}
if ( ! error ) {
V_3 -> V_294 -= V_89 . V_284 ;
V_3 -> V_297 -= V_89 . V_296 ;
F_35 ( V_59 | V_82 , L_143 ,
V_89 . V_284 , V_89 . V_296 ) ;
}
F_71 ( & V_3 -> V_300 ) ;
if ( error ) {
F_35 ( V_59 | V_82 , L_144 ) ;
F_101 ( V_282 ) ;
return error ;
}
F_102 ( V_302 , & V_107 -> V_52 ) ;
if ( V_148 -> V_149 != V_150 ) {
if ( V_3 -> V_146 [ V_12 ] ) {
F_35 ( V_63 | V_82 , L_145 ) ;
error = - V_83 ;
}
if ( ! error )
error = F_45 ( V_3 , V_12 ) ;
if ( error ) {
F_101 ( V_282 ) ;
return error ;
}
V_3 -> V_146 [ V_12 ] = V_107 ;
}
V_107 -> V_303 = ( void * ) V_282 ;
F_102 ( V_304 , & V_107 -> V_52 ) ;
return 0 ;
}
static void F_103 ( struct V_107 * V_107 ) {
T_2 * V_3 = F_82 ( V_107 -> V_3 ) ;
T_10 * V_89 = F_83 ( V_107 ) ;
T_4 V_12 = V_89 -> V_12 ;
F_35 ( V_82 | V_60 , L_146 ) ;
F_58 ( V_304 , & V_107 -> V_52 ) ;
if ( V_107 -> V_147 . V_204 . V_149 != V_150 ) {
unsigned int V_28 ;
while ( F_60 ( V_3 ) )
;
for ( V_28 = 0 ; V_28 < V_183 ; ++ V_28 )
if ( V_3 -> V_188 [ V_28 ] == V_12 ) {
V_3 -> V_188 [ V_28 ] = - 1 ;
break;
}
if ( V_3 -> V_213 == V_12 )
V_3 -> V_214 = - 1 ;
F_64 ( V_3 ) ;
}
if ( V_107 -> V_147 . V_148 . V_149 != V_150 ) {
F_51 ( V_3 , V_12 ) ;
if ( V_107 != V_3 -> V_146 [ V_12 ] )
F_74 ( V_145 , L_147 ,
L_148 ,
V_107 , V_3 -> V_146 [ V_12 ] ) ;
V_3 -> V_146 [ V_12 ] = NULL ;
}
F_70 ( & V_3 -> V_300 ) ;
F_35 ( V_59 | V_82 , L_149 ,
V_89 -> V_284 , V_89 -> V_296 ) ;
V_3 -> V_294 += V_89 -> V_284 ;
V_3 -> V_297 += V_89 -> V_296 ;
F_71 ( & V_3 -> V_300 ) ;
F_101 ( V_89 ) ;
F_58 ( V_302 , & V_107 -> V_52 ) ;
}
static int F_104 ( struct V_270 * V_270 , T_14 * V_305 , char * V_306 ) {
T_2 * V_3 = F_82 ( V_270 ) ;
int V_307 = * V_305 ;
F_35 ( V_60 , L_150 ) ;
#if 0
if (!left--) {
unsigned int count = sprintf (page, "vbr buckets:");
unsigned int i;
for (i = 0; i < TX_CHANS; ++i)
count += sprintf (page, " %u/%u",
query_tx_channel_config (dev, i, BUCKET_FULLNESS_ACCESS),
query_tx_channel_config (dev, i, BUCKET_CAPACITY_ACCESS));
count += sprintf (page+count, ".\n");
return count;
}
#endif
if ( ! V_307 -- )
return sprintf ( V_306 ,
L_151 ,
V_3 -> V_167 , V_3 -> V_169 ,
V_3 -> V_171 , V_3 -> V_173 ) ;
if ( ! V_307 -- )
return sprintf ( V_306 ,
L_152 ,
F_12 ( V_3 , V_212 ) ,
F_12 ( V_3 , V_250 ) ,
V_3 -> V_84 ) ;
if ( ! V_307 -- )
return sprintf ( V_306 ,
L_153 ,
V_3 -> V_294 , V_3 -> V_297 ) ;
return 0 ;
}
static int F_105 ( struct V_308 * V_308 ,
const struct V_309 * V_310 )
{
T_2 * V_3 ;
int V_311 = 0 ;
T_3 V_6 = F_106 ( V_308 , 0 ) ;
T_3 * V_312 = F_107 ( F_106 ( V_308 , 1 ) ) ;
unsigned int V_97 ;
unsigned char V_313 ;
F_35 ( V_60 , L_154 ) ;
if ( F_108 ( V_308 ) )
return - V_41 ;
if ( ! F_109 ( V_6 , V_314 , V_237 ) ) {
V_311 = - V_41 ;
goto V_315;
}
V_3 = F_110 ( sizeof( T_2 ) , V_298 ) ;
if ( ! V_3 ) {
F_35 ( V_63 , L_155 ) ;
V_311 = - V_299 ;
goto V_316;
}
F_111 ( V_308 , V_3 ) ;
V_97 = V_308 -> V_97 ;
if ( F_112 ( V_97 ,
F_77 ,
V_317 ,
V_237 ,
V_3 ) ) {
F_35 ( V_153 , L_156 ) ;
V_311 = - V_41 ;
goto V_318;
}
F_35 ( V_235 , L_157 ,
V_6 , V_97 , V_312 ) ;
V_3 -> V_270 = F_113 ( V_237 , & V_308 -> V_3 , & V_319 , - 1 ,
NULL ) ;
if ( ! ( V_3 -> V_270 ) ) {
F_35 ( V_63 , L_158 ) ;
V_311 = - V_41 ;
goto V_320;
}
F_35 ( V_235 , L_159 ,
V_3 -> V_270 -> V_321 , V_3 , V_3 -> V_270 ) ;
V_3 -> V_270 -> V_303 = ( void * ) V_3 ;
V_3 -> V_308 = V_308 ;
F_114 ( V_308 ) ;
F_115 ( V_308 , V_322 , & V_313 ) ;
if ( V_323 ) {
F_35 ( V_235 , L_160 ,
L_161 , V_313 , V_323 ) ;
F_116 ( V_308 , V_322 , V_323 ) ;
} else if ( V_313 < V_324 ) {
F_74 ( V_154 , L_160 ,
L_162 , V_313 , V_324 ) ;
F_116 ( V_308 , V_322 , V_324 ) ;
}
V_3 -> V_6 = V_6 ;
V_3 -> V_97 = V_97 ;
V_3 -> V_312 = V_312 ;
V_3 -> V_135 = V_3 -> V_138 = & V_76 -> V_325 [ 0 ] ;
V_3 -> V_137 = & V_76 -> V_325 [ V_95 - 1 ] ;
V_3 -> V_213 = - 1 ;
V_3 -> V_214 = - 1 ;
V_3 -> V_181 = 0 ;
V_3 -> V_123 = 0 ;
V_3 -> V_120 = 0 ;
V_3 -> V_127 = NULL ;
V_3 -> V_122 = NULL ;
V_3 -> V_167 = 0 ;
V_3 -> V_169 = 0 ;
V_3 -> V_171 = 0 ;
V_3 -> V_173 = 0 ;
V_3 -> V_84 = 0 ;
{
unsigned int V_28 ;
for ( V_28 = 0 ; V_28 < V_183 ; ++ V_28 )
V_3 -> V_188 [ V_28 ] = - 1 ;
}
V_3 -> V_52 = 0 ;
if ( F_92 ( V_3 ) ) {
V_3 -> V_294 = V_326 ;
V_3 -> V_297 = V_326 ;
F_102 ( V_51 , & V_3 -> V_52 ) ;
} else {
V_3 -> V_294 = ( ( 25600000 / 8 ) * 26 ) / ( 27 * 53 ) ;
V_3 -> V_297 = ( ( 25600000 / 8 ) * 26 ) / ( 27 * 53 ) ;
F_35 ( V_153 , L_163 ) ;
}
F_117 ( & V_3 -> V_300 ) ;
F_117 ( & V_3 -> V_78 ) ;
F_118 ( & V_3 -> V_117 ) ;
V_3 -> V_270 -> V_327 . V_40 = V_40 ;
V_3 -> V_270 -> V_327 . V_39 = 10 - V_40 ;
F_119 ( & V_3 -> V_175 , F_78 , ( unsigned long ) V_3 ) ;
F_79 ( & V_3 -> V_175 , V_176 ) ;
V_328:
return V_311 ;
V_320:
F_120 ( V_3 -> V_97 , V_3 ) ;
V_318:
F_101 ( V_3 ) ;
V_316:
F_121 ( V_6 , V_314 ) ;
V_315:
F_122 ( V_308 ) ;
goto V_328;
}
static void F_123 ( struct V_308 * V_308 )
{
T_2 * V_3 ;
V_3 = F_124 ( V_308 ) ;
F_35 ( V_235 , L_164 , V_3 , V_3 -> V_270 ) ;
F_125 ( & V_3 -> V_175 ) ;
F_87 ( V_3 ) ;
F_126 ( V_3 -> V_270 ) ;
F_120 ( V_3 -> V_97 , V_3 ) ;
F_121 ( V_3 -> V_6 , V_314 ) ;
F_101 ( V_3 ) ;
F_122 ( V_308 ) ;
}
static void T_1 F_127 ( void ) {
#ifdef F_30
F_74 ( V_329 , L_165 , V_208 &= V_330 ) ;
#else
if ( V_208 )
F_74 ( V_329 , L_166 ) ;
#endif
if ( V_40 > V_331 )
F_74 ( V_145 , L_167 ,
V_40 = V_331 ) ;
if ( V_290 < 0 || V_290 > V_332 )
F_74 ( V_329 , L_168 ,
V_290 = V_332 ) ;
if ( V_261 < 0 || V_261 > V_333 )
F_74 ( V_329 , L_169 ,
V_261 = V_333 ) ;
return;
}
static int T_1 F_128 ( void ) {
if ( sizeof( struct V_334 ) != 128 * 1024 / 4 ) {
F_74 ( V_145 , L_170 ,
( unsigned long ) sizeof( struct V_334 ) ) ;
return - V_299 ;
}
F_1 () ;
F_127 () ;
return F_129 ( & V_335 ) ;
}
static void T_15 F_130 ( void ) {
F_35 ( V_60 , L_171 ) ;
F_131 ( & V_335 ) ;
}
