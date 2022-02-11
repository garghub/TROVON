static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_3 , V_4 ) ;
return F_3 ( V_5 ) ;
}
static inline void F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
F_2 ( V_3 , V_4 ) ;
F_2 ( V_6 , V_5 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_7 )
{
F_2 ( V_8 , V_4 ) ;
F_2 ( V_7 , V_5 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 )
{
T_1 V_9 , V_10 = 0 ;
F_4 ( V_2 , V_11 , V_12 | V_13 | V_14 ) ;
F_5 ( V_2 , V_15 | 0x80 ) ;
do {
V_9 = F_7 () ;
if ( V_9 & V_16 )
V_10 = F_1 ( V_2 , V_17 ) ;
} while ( ! ( V_9 & V_18 ) );
return V_10 ;
}
static void F_8 ( struct V_1 * V_2 , unsigned long V_6 )
{
F_2 ( V_19 , V_4 ) ;
F_2 ( ( V_6 >> 16 ) , V_5 ) ;
F_2 ( ( V_6 >> 8 ) , V_5 ) ;
F_2 ( V_6 , V_5 ) ;
}
static unsigned long F_9 ( struct V_1 * V_2 )
{
unsigned long V_6 ;
F_2 ( V_19 , V_4 ) ;
V_6 = F_3 ( V_5 ) << 16 ;
V_6 |= F_3 ( V_5 ) << 8 ;
V_6 |= F_3 ( V_5 ) ;
return V_6 ;
}
static int F_10 ( T_2 * V_7 )
{
switch ( V_7 -> V_20 [ 0 ] ) {
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case 0xea :
return 1 ;
default:
return 0 ;
}
}
static int F_11 ( unsigned int V_50 )
{
int V_10 ;
for ( V_10 = 1 ; V_51 [ V_10 ] . V_52 ; V_10 ++ ) {
if ( ( V_50 <= V_51 [ V_10 - 0 ] . V_52 ) && ( V_50 > V_51 [ V_10 - 1 ] . V_52 ) ) {
return V_10 ;
}
}
return 7 ;
}
static T_1 F_12 ( unsigned int V_50 , unsigned int V_53 )
{
T_1 V_54 ;
V_50 *= 4 ;
V_54 = V_51 [ F_11 ( V_50 ) ] . V_55 ;
V_54 |= ( V_53 < V_56 ) ? V_53 : V_56 ;
return V_54 ;
}
static int F_13 ( T_2 * V_7 , void (* F_14) ( T_2 * ) )
{
struct V_57 * V_58 ;
struct V_1 * V_2 ;
T_2 * V_59 ;
V_58 = V_7 -> V_60 -> V_61 ;
V_2 = (struct V_1 * ) V_58 -> V_2 ;
F_15 (DB_QUEUE_COMMAND, scmd_printk(KERN_DEBUG, cmd, L_1, cmd->cmnd[0]))
V_7 -> V_62 = NULL ;
V_7 -> V_63 = F_14 ;
V_7 -> V_54 = 0 ;
if ( F_16 ( V_7 ) ) {
V_7 -> V_64 . V_65 = F_17 ( V_7 ) ;
V_7 -> V_64 . V_66 = F_18 ( V_7 ) - 1 ;
V_7 -> V_64 . V_67 = F_19 ( V_7 -> V_64 . V_65 ) ;
V_7 -> V_64 . V_68 = V_7 -> V_64 . V_65 -> V_69 ;
} else {
V_7 -> V_64 . V_65 = NULL ;
V_7 -> V_64 . V_66 = 0 ;
V_7 -> V_64 . V_67 = NULL ;
V_7 -> V_64 . V_68 = 0 ;
}
V_7 -> V_64 . V_70 = 0 ;
V_7 -> V_64 . V_71 = V_72 ;
if ( ! ( V_2 -> V_73 ) || ( V_7 -> V_20 [ 0 ] == V_74 ) ) {
V_7 -> V_62 = ( T_1 * ) V_2 -> V_73 ;
V_2 -> V_73 = V_7 ;
} else {
for ( V_59 = ( T_2 * ) V_2 -> V_73 ; V_59 -> V_62 ; V_59 = ( T_2 * ) V_59 -> V_62 ) ;
V_59 -> V_62 = ( T_1 * ) V_7 ;
}
F_20 ( V_7 -> V_60 -> V_61 ) ;
F_15 (DB_QUEUE_COMMAND, printk(L_2))
return 0 ;
}
void F_21 ( T_1 * V_75 , int V_76 , int V_77 , struct V_1 * V_2 )
{
T_1 V_9 ;
F_15 (DB_TRANSFER, printk(L_3, buf, cnt, data_in_dir ? L_4 : L_5))
F_4 ( V_2 , V_11 , V_12 | V_13 | V_14 ) ;
F_8 ( V_2 , V_76 ) ;
F_5 ( V_2 , V_15 ) ;
if ( V_77 ) {
do {
V_9 = F_7 () ;
if ( V_9 & V_16 )
* V_75 ++ = F_1 ( V_2 , V_17 ) ;
} while ( ! ( V_9 & V_18 ) );
} else {
do {
V_9 = F_7 () ;
if ( V_9 & V_16 )
F_4 ( V_2 , V_17 , * V_75 ++ ) ;
} while ( ! ( V_9 & V_18 ) );
}
}
static void F_22 ( T_2 * V_7 , int V_77 )
{
struct V_1 * V_2 ;
unsigned short * V_78 ;
unsigned short V_79 ;
int V_80 ;
V_2 = (struct V_1 * ) V_7 -> V_60 -> V_61 -> V_2 ;
if ( ! V_7 -> V_64 . V_68 && V_7 -> V_64 . V_66 ) {
++ V_7 -> V_64 . V_65 ;
-- V_7 -> V_64 . V_66 ;
V_7 -> V_64 . V_68 = V_7 -> V_64 . V_65 -> V_69 ;
V_7 -> V_64 . V_67 = F_19 ( V_7 -> V_64 . V_65 ) ;
}
F_4 ( V_2 , V_81 , V_2 -> V_82 [ V_7 -> V_60 -> V_83 ] ) ;
F_8 ( V_2 , V_7 -> V_64 . V_68 ) ;
F_4 ( V_2 , V_11 , V_12 | V_13 | V_84 ) ;
F_2 ( 0 , V_85 ) ;
if ( V_77 ) {
F_2 ( 0 , V_86 ) ;
if ( ( V_2 -> V_87 >= V_88 ) || ( V_2 -> V_87 == V_89 && V_7 -> V_64 . V_90 == 0 ) ) {
F_4 ( V_2 , V_91 , 0x45 ) ;
F_5 ( V_2 , V_92 ) ;
V_2 -> V_93 = V_94 ;
} else
F_5 ( V_2 , V_15 ) ;
V_2 -> V_95 = V_96 ;
V_7 -> V_64 . V_70 = 0 ;
return;
}
if ( ( V_2 -> V_87 >= V_88 ) || ( V_2 -> V_87 == V_89 && V_7 -> V_64 . V_90 == 0 ) ) {
F_4 ( V_2 , V_91 , 0x45 ) ;
F_5 ( V_2 , V_92 ) ;
V_2 -> V_93 = V_94 ;
} else
F_5 ( V_2 , V_15 ) ;
V_2 -> V_95 = V_97 ;
V_78 = ( unsigned short * ) V_7 -> V_64 . V_67 ;
if ( ( V_80 = V_7 -> V_64 . V_68 ) > V_98 )
V_80 = V_98 ;
V_7 -> V_64 . V_70 = V_80 ;
V_80 >>= 1 ;
V_79 = V_2 -> V_99 + V_100 ;
#ifdef F_23
F_24 () ;
#else
while ( V_80 -- )
F_25 ( * V_78 ++ , V_100 ) ;
#endif
}
static T_3 F_26 ( int V_101 , void * V_102 )
{
struct V_57 * V_58 = V_102 ;
struct V_1 * V_2 ;
T_2 * V_103 , * V_7 ;
T_1 V_9 , V_104 , V_105 , V_83 , V_106 , * V_107 , V_108 ;
int V_80 , V_109 ;
unsigned long V_69 ;
unsigned short * V_78 ;
unsigned short V_79 ;
unsigned long V_110 ;
V_2 = (struct V_1 * ) V_58 -> V_2 ;
F_27 ( V_58 -> V_111 , V_110 ) ;
#ifdef F_28
V_2 -> V_112 ++ ;
#endif
F_2 ( 0 , V_113 ) ;
V_9 = F_7 () ;
if ( ! ( V_9 & V_18 ) ) {
V_7 = ( T_2 * ) V_2 -> V_114 ;
F_29 (cmd, L_6 )
if ( V_2 -> V_95 == V_96 ) {
F_15 (DB_FIFO, printk(L_7, read1_io(IO_FIFO_COUNT)))
V_78 = ( unsigned short * ) ( V_7 -> V_64 . V_67 + V_7 -> V_64 . V_70 ) ;
V_80 = F_3 ( V_115 ) & 0xfe ;
V_80 <<= 2 ;
V_79 = V_2 -> V_99 + V_100 ;
#ifdef F_30
F_31 () ;
#else
while ( V_80 -- )
* V_78 ++ = F_32 ( V_100 ) ;
#endif
V_80 = V_78 - ( unsigned short * ) ( V_7 -> V_64 . V_67 + V_7 -> V_64 . V_70 ) ;
V_80 <<= 1 ;
V_7 -> V_64 . V_70 += V_80 ;
}
else if ( V_2 -> V_95 == V_97 ) {
F_15 (DB_FIFO, printk(L_8, read1_io(IO_FIFO_COUNT)))
if ( V_7 -> V_64 . V_68 == V_7 -> V_64 . V_70 ) {
V_80 = 16 ;
while ( V_80 -- )
F_25 ( 0 , V_100 ) ;
}
else {
V_78 = ( unsigned short * ) ( V_7 -> V_64 . V_67 + V_7 -> V_64 . V_70 ) ;
V_80 = V_7 -> V_64 . V_68 - V_7 -> V_64 . V_70 ;
V_109 = F_3 ( V_115 ) & 0xfe ;
V_109 <<= 2 ;
if ( ( V_109 << 1 ) > V_80 )
V_109 = ( V_80 >> 1 ) ;
while ( V_109 -- )
F_25 ( * V_78 ++ , V_100 ) ;
V_80 = V_78 - ( unsigned short * ) ( V_7 -> V_64 . V_67 + V_7 -> V_64 . V_70 ) ;
V_80 <<= 1 ;
V_7 -> V_64 . V_70 += V_80 ;
}
}
else {
F_33 ( L_9 ) ;
}
F_2 ( 0 , V_116 ) ;
F_34 ( V_58 -> V_111 , V_110 ) ;
return V_117 ;
}
V_7 = ( T_2 * ) V_2 -> V_114 ;
V_104 = F_1 ( V_2 , V_118 ) ;
V_105 = F_1 ( V_2 , V_91 ) ;
if ( ! V_7 && ( V_104 != V_119 && V_104 != V_120 && V_104 != V_121 ) ) {
F_33 ( L_10 ) ;
F_2 ( 0 , V_116 ) ;
F_34 ( V_58 -> V_111 , V_110 ) ;
return V_117 ;
}
F_15 (DB_INTR, printk(L_11, asr, sr))
if ( V_2 -> V_95 == V_96 ) {
V_78 = ( unsigned short * ) ( V_7 -> V_64 . V_67 + V_7 -> V_64 . V_70 ) ;
V_80 = ( V_7 -> V_64 . V_68 - F_9 ( V_2 ) ) - V_7 -> V_64 . V_70 ;
V_80 >>= 1 ;
V_79 = V_2 -> V_99 + V_100 ;
#ifdef F_30
F_31 () ;
#else
while ( V_80 -- )
* V_78 ++ = F_32 ( V_100 ) ;
#endif
V_2 -> V_95 = V_122 ;
V_69 = V_7 -> V_64 . V_68 ;
V_7 -> V_64 . V_68 = F_9 ( V_2 ) ;
V_7 -> V_64 . V_67 += ( V_69 - V_7 -> V_64 . V_68 ) ;
F_15 (DB_TRANSFER, printk(L_12, cmd->SCp.ptr, cmd->SCp.this_residual))
}
else if ( V_2 -> V_95 == V_97 ) {
V_2 -> V_95 = V_122 ;
V_69 = V_7 -> V_64 . V_68 ;
V_7 -> V_64 . V_68 = F_9 ( V_2 ) ;
V_7 -> V_64 . V_67 += ( V_69 - V_7 -> V_64 . V_68 ) ;
F_15 (DB_TRANSFER, printk(L_12, cmd->SCp.ptr, cmd->SCp.this_residual))
}
switch ( V_104 ) {
case V_120 :
F_15 (DB_INTR, printk(L_13))
if ( V_2 -> V_93 == V_94 )
V_2 -> V_114 = NULL ;
else {
V_7 = ( T_2 * ) V_2 -> V_123 ;
F_29 (cmd, L_14 )
V_2 -> V_123 = NULL ;
}
V_7 -> V_54 = V_124 << 16 ;
V_2 -> V_125 [ V_7 -> V_60 -> V_83 ] &= ~ ( 1 << V_7 -> V_60 -> V_106 ) ;
V_2 -> V_93 = V_126 ;
V_7 -> V_63 ( V_7 ) ;
F_20 ( V_58 ) ;
break;
case V_121 :
F_15 (DB_INTR, printk(L_15))
V_2 -> V_114 = V_7 = ( T_2 * ) V_2 -> V_123 ;
F_29 (cmd, L_16 )
V_2 -> V_123 = NULL ;
V_2 -> V_127 [ 0 ] = ( 0x80 | 0x00 | V_7 -> V_60 -> V_106 ) ;
if ( V_7 -> V_64 . V_90 )
V_2 -> V_127 [ 0 ] |= 0x40 ;
if ( V_2 -> V_128 [ V_7 -> V_60 -> V_83 ] == V_129 ) {
#ifdef F_35
F_33 ( L_17 ) ;
#endif
V_2 -> V_128 [ V_7 -> V_60 -> V_83 ] = V_130 ;
V_2 -> V_127 [ 1 ] = V_131 ;
V_2 -> V_127 [ 2 ] = 3 ;
V_2 -> V_127 [ 3 ] = V_132 ;
V_2 -> V_127 [ 4 ] = V_133 / 4 ;
V_2 -> V_127 [ 5 ] = V_56 ;
V_2 -> V_134 = 6 ;
} else
V_2 -> V_134 = 1 ;
V_2 -> V_93 = V_135 ;
break;
case V_136 | V_137 :
case V_138 | V_137 :
case V_139 | V_137 :
F_15 (DB_INTR, printk(L_18, cmd->SCp.this_residual, cmd->SCp.buffers_residual))
F_22 ( V_7 , V_140 ) ;
if ( V_2 -> V_93 != V_94 )
V_2 -> V_93 = V_135 ;
break;
case V_136 | V_141 :
case V_138 | V_141 :
case V_139 | V_141 :
F_15 (DB_INTR, printk(L_19, cmd->SCp.this_residual, cmd->SCp.buffers_residual))
F_22 ( V_7 , V_142 ) ;
if ( V_2 -> V_93 != V_94 )
V_2 -> V_93 = V_135 ;
break;
case V_136 | V_143 :
case V_138 | V_143 :
case V_139 | V_143 :
F_15 (DB_INTR, printk(L_20, cmd->cmnd[0]))
F_21 ( V_7 -> V_20 , V_7 -> V_144 , V_142 , V_2 ) ;
V_2 -> V_93 = V_135 ;
break;
case V_136 | V_145 :
case V_138 | V_145 :
case V_139 | V_145 :
F_15 (DB_INTR, printk(L_21))
V_7 -> V_64 . V_71 = F_6 ( V_2 ) ;
F_15 (DB_INTR, printk(L_22, cmd->SCp.Status))
if ( V_2 -> V_87 >= V_89 ) {
V_104 = F_1 ( V_2 , V_118 ) ;
V_2 -> V_93 = V_94 ;
F_4 ( V_2 , V_91 , 0x50 ) ;
F_5 ( V_2 , V_92 ) ;
} else {
V_2 -> V_93 = V_135 ;
}
break;
case V_136 | V_146 :
case V_138 | V_146 :
case V_139 | V_146 :
F_15 (DB_INTR, printk(L_23))
V_108 = F_6 ( V_2 ) ;
V_104 = F_1 ( V_2 , V_118 ) ;
V_2 -> V_147 [ V_2 -> V_148 ] = V_108 ;
if ( V_2 -> V_147 [ 0 ] == V_131 )
V_108 = V_131 ;
else
V_2 -> V_148 = 0 ;
V_7 -> V_64 . V_149 = V_108 ;
switch ( V_108 ) {
case V_150 :
F_15 (DB_INTR, printk(L_24))
F_5 ( V_2 , V_151 ) ;
V_2 -> V_93 = V_152 ;
break;
case V_153 :
F_15 (DB_INTR, printk(L_25))
F_5 ( V_2 , V_151 ) ;
V_2 -> V_93 = V_135 ;
break;
case V_154 :
F_15 (DB_INTR, printk(L_26))
if ( V_2 -> V_87 >= V_89 ) {
F_4 ( V_2 , V_91 , 0x45 ) ;
F_5 ( V_2 , V_92 ) ;
V_2 -> V_93 = V_94 ;
} else {
F_5 ( V_2 , V_151 ) ;
V_2 -> V_93 = V_135 ;
}
break;
case V_155 :
F_15 (DB_INTR, printk(L_27))
V_7 -> V_60 -> V_156 = 1 ;
F_5 ( V_2 , V_151 ) ;
V_2 -> V_93 = V_157 ;
break;
case V_158 :
F_15 (DB_INTR, printk(L_28))
#ifdef F_35
F_33 ( L_29 ) ;
#endif
if ( V_2 -> V_128 [ V_7 -> V_60 -> V_83 ] == V_130 )
V_2 -> V_128 [ V_7 -> V_60 -> V_83 ] = V_159 ;
F_5 ( V_2 , V_151 ) ;
V_2 -> V_93 = V_135 ;
break;
case V_131 :
F_15 (DB_INTR, printk(L_30))
V_107 = V_2 -> V_147 ;
#ifdef F_35
F_33 ( L_22 , V_107 [ V_2 -> V_148 ] ) ;
#endif
if ( ( V_2 -> V_148 >= 2 ) && ( V_2 -> V_148 == ( V_107 [ 1 ] + 1 ) ) ) {
switch ( V_107 [ 2 ] ) {
case V_132 :
V_83 = F_12 ( V_107 [ 3 ] , V_107 [ 4 ] ) ;
if ( V_2 -> V_128 [ V_7 -> V_60 -> V_83 ] != V_130 ) {
F_5 ( V_2 , V_160 ) ;
V_2 -> V_127 [ 0 ] = V_131 ;
V_2 -> V_127 [ 1 ] = 3 ;
V_2 -> V_127 [ 2 ] = V_132 ;
V_2 -> V_127 [ 3 ] = V_2 -> V_161 / 4 ;
V_2 -> V_127 [ 4 ] = 0 ;
V_2 -> V_134 = 5 ;
V_2 -> V_82 [ V_7 -> V_60 -> V_83 ] = F_12 ( V_2 -> V_161 / 4 , 0 ) ;
} else {
V_2 -> V_82 [ V_7 -> V_60 -> V_83 ] = V_83 ;
}
#ifdef F_35
F_33 ( L_31 , V_2 -> V_82 [ V_7 -> V_60 -> V_83 ] ) ;
#endif
V_2 -> V_128 [ V_7 -> V_60 -> V_83 ] = V_159 ;
F_5 ( V_2 , V_151 ) ;
V_2 -> V_93 = V_135 ;
break;
case V_162 :
F_5 ( V_2 , V_160 ) ;
F_33 ( L_32 ) ;
V_2 -> V_127 [ 0 ] = V_131 ;
V_2 -> V_127 [ 1 ] = 2 ;
V_2 -> V_127 [ 2 ] = V_162 ;
V_2 -> V_127 [ 3 ] = 0 ;
V_2 -> V_134 = 4 ;
F_5 ( V_2 , V_151 ) ;
V_2 -> V_93 = V_135 ;
break;
default:
F_5 ( V_2 , V_160 ) ;
F_33 ( L_33 , V_107 [ 2 ] ) ;
V_2 -> V_127 [ 0 ] = V_158 ;
V_2 -> V_134 = 1 ;
F_5 ( V_2 , V_151 ) ;
V_2 -> V_93 = V_135 ;
break;
}
V_2 -> V_148 = 0 ;
}
else {
V_2 -> V_148 ++ ;
F_5 ( V_2 , V_151 ) ;
V_2 -> V_93 = V_135 ;
}
break;
default:
F_33 ( L_34 , V_108 ) ;
F_5 ( V_2 , V_160 ) ;
V_2 -> V_127 [ 0 ] = V_158 ;
V_2 -> V_134 = 1 ;
F_5 ( V_2 , V_151 ) ;
V_2 -> V_93 = V_135 ;
}
break;
case V_163 :
F_4 ( V_2 , V_164 , V_165 ) ;
if ( V_105 == 0x60 ) {
F_15 (DB_INTR, printk(L_35))
V_7 -> V_64 . V_149 = V_150 ;
V_106 = F_1 ( V_2 , V_166 ) ;
F_15 (DB_INTR, printk(L_36, cmd->SCp.Status, lun))
V_2 -> V_114 = NULL ;
V_2 -> V_125 [ V_7 -> V_60 -> V_83 ] &= ~ ( 1 << V_7 -> V_60 -> V_106 ) ;
V_2 -> V_93 = V_126 ;
if ( V_7 -> V_64 . V_71 == V_72 )
V_7 -> V_64 . V_71 = V_106 ;
if ( V_7 -> V_20 [ 0 ] == V_74 && V_7 -> V_64 . V_71 != V_167 )
V_7 -> V_54 = ( V_7 -> V_54 & 0x00ffff ) | ( V_168 << 16 ) ;
else
V_7 -> V_54 = V_7 -> V_64 . V_71 | ( V_7 -> V_64 . V_149 << 8 ) ;
V_7 -> V_63 ( V_7 ) ;
F_20 ( V_58 ) ;
} else {
F_33 ( L_37 , V_9 , V_104 , V_105 ) ;
}
break;
case V_169 :
F_15 (DB_INTR, printk(L_25))
V_2 -> V_93 = V_94 ;
F_4 ( V_2 , V_91 , 0x41 ) ;
F_5 ( V_2 , V_92 ) ;
break;
case V_136 | V_170 :
case V_138 | V_170 :
case V_139 | V_170 :
F_15 (DB_INTR, printk(L_38))
if ( V_2 -> V_134 == 0 ) {
V_2 -> V_134 = 1 ;
V_2 -> V_127 [ 0 ] = V_171 ;
}
F_21 ( V_2 -> V_127 , V_2 -> V_134 , V_142 , V_2 ) ;
F_15 (DB_INTR, printk(L_22, hostdata->outgoing_msg[0]))
V_2 -> V_134 = 0 ;
V_2 -> V_93 = V_135 ;
break;
case V_172 :
F_4 ( V_2 , V_164 , V_165 ) ;
if ( V_7 == NULL ) {
F_33 ( L_39 ) ;
V_2 -> V_93 = V_126 ;
F_34 ( V_58 -> V_111 , V_110 ) ;
return V_117 ;
}
F_15 (DB_INTR, printk(L_40))
V_2 -> V_114 = NULL ;
V_2 -> V_125 [ V_7 -> V_60 -> V_83 ] &= ~ ( 1 << V_7 -> V_60 -> V_106 ) ;
V_2 -> V_93 = V_126 ;
if ( V_7 -> V_20 [ 0 ] == V_74 && V_7 -> V_64 . V_71 != V_167 )
V_7 -> V_54 = ( V_7 -> V_54 & 0x00ffff ) | ( V_168 << 16 ) ;
else
V_7 -> V_54 = V_7 -> V_64 . V_71 | ( V_7 -> V_64 . V_149 << 8 ) ;
V_7 -> V_63 ( V_7 ) ;
F_20 ( V_58 ) ;
break;
case V_173 :
F_4 ( V_2 , V_164 , V_165 ) ;
F_15 (DB_INTR, printk(L_41))
if ( V_7 == NULL ) {
F_33 ( L_39 ) ;
V_2 -> V_93 = V_126 ;
}
switch ( V_2 -> V_93 ) {
case V_152 :
V_2 -> V_114 = NULL ;
V_2 -> V_125 [ V_7 -> V_60 -> V_83 ] &= ~ ( 1 << V_7 -> V_60 -> V_106 ) ;
V_2 -> V_93 = V_126 ;
F_15 (DB_INTR, printk(L_42, cmd->SCp.Status))
if ( V_7 -> V_20 [ 0 ] == V_74 && V_7 -> V_64 . V_71 != V_167 )
V_7 -> V_54 = ( V_7 -> V_54 & 0x00ffff ) | ( V_168 << 16 ) ;
else
V_7 -> V_54 = V_7 -> V_64 . V_71 | ( V_7 -> V_64 . V_149 << 8 ) ;
V_7 -> V_63 ( V_7 ) ;
break;
case V_157 :
case V_94 :
V_7 -> V_62 = ( T_1 * ) V_2 -> V_174 ;
V_2 -> V_174 = V_7 ;
V_2 -> V_114 = NULL ;
V_2 -> V_93 = V_126 ;
#ifdef F_28
V_2 -> V_175 [ V_7 -> V_60 -> V_83 ] ++ ;
#endif
break;
default:
F_33 ( L_43 ) ;
V_2 -> V_93 = V_126 ;
}
F_20 ( V_58 ) ;
break;
case V_119 :
F_15 (DB_INTR, printk(L_44))
if ( V_2 -> V_87 <= V_176 ) {
if ( V_2 -> V_123 ) {
V_7 = ( T_2 * ) V_2 -> V_123 ;
V_2 -> V_123 = NULL ;
V_2 -> V_125 [ V_7 -> V_60 -> V_83 ] &= ~ ( 1 << V_7 -> V_60 -> V_106 ) ;
V_7 -> V_62 = ( T_1 * ) V_2 -> V_73 ;
V_2 -> V_73 = V_7 ;
}
}
else {
if ( V_7 ) {
if ( V_105 == 0x00 ) {
V_2 -> V_125 [ V_7 -> V_60 -> V_83 ] &= ~ ( 1 << V_7 -> V_60 -> V_106 ) ;
V_7 -> V_62 = ( T_1 * ) V_2 -> V_73 ;
V_2 -> V_73 = V_7 ;
} else {
F_33 ( L_45 , V_9 , V_104 , V_105 ) ;
while ( 1 )
F_33 ( L_46 ) ;
}
}
}
V_83 = F_1 ( V_2 , V_164 ) ;
V_83 &= V_177 ;
V_106 = F_1 ( V_2 , V_17 ) ;
if ( V_2 -> V_87 < V_178 )
F_5 ( V_2 , V_151 ) ;
V_106 &= 7 ;
V_7 = ( T_2 * ) V_2 -> V_174 ;
V_103 = NULL ;
while ( V_7 ) {
if ( V_83 == V_7 -> V_60 -> V_83 && V_106 == V_7 -> V_60 -> V_106 )
break;
V_103 = V_7 ;
V_7 = ( T_2 * ) V_7 -> V_62 ;
}
if ( ! V_7 ) {
F_33 ( L_47 , V_83 , V_106 ) ;
break;
}
if ( V_103 )
V_103 -> V_62 = V_7 -> V_62 ;
else
V_2 -> V_174 = ( T_2 * ) V_7 -> V_62 ;
V_2 -> V_114 = V_7 ;
if ( F_10 ( V_7 ) )
F_4 ( V_2 , V_179 , V_7 -> V_60 -> V_83 ) ;
else
F_4 ( V_2 , V_179 , V_7 -> V_60 -> V_83 | V_180 ) ;
if ( V_2 -> V_87 >= V_178 ) {
F_8 ( V_2 , 0 ) ;
F_4 ( V_2 , V_91 , 0x45 ) ;
F_5 ( V_2 , V_92 ) ;
V_2 -> V_93 = V_94 ;
} else
V_2 -> V_93 = V_135 ;
break;
default:
F_33 ( L_48 , V_9 , V_104 , V_105 ) ;
}
F_2 ( 0 , V_116 ) ;
F_15 (DB_INTR, printk(L_49))
F_34 ( V_58 -> V_111 , V_110 ) ;
return V_117 ;
}
static int F_36 ( struct V_57 * V_58 , int type )
{
struct V_1 * V_2 ;
int V_181 , V_10 ;
V_2 = (struct V_1 * ) V_58 -> V_2 ;
F_2 ( 0 , V_113 ) ;
if ( type == V_182 ) {
F_2 ( 0 , V_183 ) ;
V_10 = F_3 ( V_184 ) ;
}
V_10 = F_1 ( V_2 , V_118 ) ;
F_4 ( V_2 , V_185 , V_58 -> V_186 | V_187 | V_188 | V_189 ) ;
F_4 ( V_2 , V_11 , V_12 | V_13 | V_14 ) ;
F_4 ( V_2 , V_81 , F_12 ( V_2 -> V_161 / 4 , V_190 ) ) ;
F_2 ( 0 , V_85 ) ;
F_2 ( 0 , V_86 ) ;
F_4 ( V_2 , V_8 , V_191 ) ;
while ( ! ( F_7 () & V_18 ) )
F_37 () ;
V_10 = F_1 ( V_2 , V_118 ) ;
F_4 ( V_2 , V_192 , 0xa5 ) ;
V_181 = F_1 ( V_2 , V_192 ) ;
if ( V_181 == 0xa5 ) {
V_10 |= V_193 ;
F_4 ( V_2 , V_192 , 0 ) ;
}
F_4 ( V_2 , V_194 , V_195 ) ;
F_4 ( V_2 , V_11 , V_12 | V_13 | V_14 ) ;
F_2 ( 0 , V_116 ) ;
return V_10 ;
}
static int F_38 ( T_2 * V_7 )
{
struct V_57 * V_58 ;
struct V_1 * V_2 ;
int V_10 ;
unsigned long V_110 ;
V_58 = V_7 -> V_60 -> V_61 ;
V_2 = (struct V_1 * ) V_58 -> V_2 ;
F_33 ( V_196 L_50 , V_58 -> V_197 ) ;
F_27 ( V_58 -> V_111 , V_110 ) ;
F_36 ( V_58 , V_182 ) ;
for ( V_10 = 0 ; V_10 < 8 ; V_10 ++ ) {
V_2 -> V_125 [ V_10 ] = 0 ;
V_2 -> V_82 [ V_10 ] = F_12 ( V_198 / 4 , V_190 ) ;
V_2 -> V_128 [ V_10 ] = V_199 ;
}
V_2 -> V_73 = NULL ;
V_2 -> V_123 = NULL ;
V_2 -> V_114 = NULL ;
V_2 -> V_174 = NULL ;
V_2 -> V_93 = V_126 ;
V_2 -> V_95 = V_122 ;
V_2 -> V_148 = 0 ;
V_2 -> V_134 = 0 ;
V_7 -> V_54 = V_200 << 16 ;
F_34 ( V_58 -> V_111 , V_110 ) ;
return V_201 ;
}
static int F_39 ( T_2 * V_7 )
{
struct V_57 * V_58 ;
struct V_1 * V_2 ;
T_2 * V_59 , * V_202 ;
T_1 V_104 , V_9 ;
unsigned long V_203 ;
V_58 = V_7 -> V_60 -> V_61 ;
V_2 = (struct V_1 * ) V_58 -> V_2 ;
F_33 ( V_204 L_51 , V_58 -> V_197 ) ;
F_33 ( L_52 , F_7 () , F_9 ( V_2 ) , V_7 -> V_64 . V_68 , V_7 -> V_64 . V_66 , V_7 -> V_64 . V_70 , F_3 ( V_115 ) ) ;
V_59 = ( T_2 * ) V_2 -> V_73 ;
V_202 = NULL ;
while ( V_59 ) {
if ( V_59 == V_7 ) {
if ( V_202 )
V_202 -> V_62 = V_7 -> V_62 ;
V_7 -> V_62 = NULL ;
V_7 -> V_54 = V_205 << 16 ;
F_33 ( V_196 L_53 , V_58 -> V_197 ) ;
V_7 -> V_63 ( V_7 ) ;
return V_201 ;
}
V_202 = V_59 ;
V_59 = ( T_2 * ) V_59 -> V_62 ;
}
if ( V_2 -> V_114 == V_7 ) {
F_33 ( V_196 L_54 , V_58 -> V_197 ) ;
F_33 ( L_55 ) ;
F_4 ( V_2 , V_11 , V_12 | V_13 | V_14 ) ;
F_5 ( V_2 , V_206 ) ;
F_33 ( L_56 ) ;
V_203 = 1000000 ;
do {
V_9 = F_7 () ;
if ( V_9 & V_16 )
F_1 ( V_2 , V_17 ) ;
} while ( ! ( V_9 & V_18 ) && V_203 -- > 0 );
V_104 = F_1 ( V_2 , V_118 ) ;
F_33 ( L_57 , V_9 , V_104 , F_9 ( V_2 ) , V_203 ) ;
F_33 ( L_58 ) ;
F_5 ( V_2 , V_207 ) ;
V_203 = 1000000 ;
V_9 = F_7 () ;
while ( ( V_9 & V_208 ) && V_203 -- > 0 )
V_9 = F_7 () ;
V_104 = F_1 ( V_2 , V_118 ) ;
F_33 ( L_59 , V_9 , V_104 ) ;
V_2 -> V_125 [ V_7 -> V_60 -> V_83 ] &= ~ ( 1 << V_7 -> V_60 -> V_106 ) ;
V_2 -> V_114 = NULL ;
V_2 -> V_93 = V_126 ;
V_7 -> V_54 = V_205 << 16 ;
V_7 -> V_63 ( V_7 ) ;
F_20 ( V_58 ) ;
return V_201 ;
}
for ( V_59 = ( T_2 * ) V_2 -> V_174 ; V_59 ; V_59 = ( T_2 * ) V_59 -> V_62 )
if ( V_7 == V_59 ) {
F_33 ( V_204 L_60 , V_58 -> V_197 ) ;
return V_209 ;
}
F_20 ( V_58 ) ;
F_33 ( L_61 L_62 , V_58 -> V_197 ) ;
return V_201 ;
}
static int F_40 ( T_2 * V_7 )
{
int V_210 ;
F_41 ( V_7 -> V_60 -> V_61 -> V_111 ) ;
V_210 = F_39 ( V_7 ) ;
F_42 ( V_7 -> V_60 -> V_61 -> V_111 ) ;
return V_210 ;
}
static void T_4 F_43 ( char * V_211 , int * V_212 )
{
int V_80 ;
char * V_213 , * V_214 ;
F_44 ( V_215 , V_211 , V_216 ) ;
V_213 = V_215 ;
V_80 = 0 ;
while ( * V_213 && ( V_80 < V_217 ) ) {
V_214 = strchr ( V_213 , ',' ) ;
if ( V_214 ) {
* V_214 = '\0' ;
if ( V_213 != V_214 )
V_218 [ V_80 ] = V_213 ;
V_213 = V_214 + 1 ;
V_80 ++ ;
} else {
V_218 [ V_80 ] = V_213 ;
break;
}
}
for ( V_80 = 0 ; V_80 < V_217 ; V_80 ++ )
V_219 [ V_80 ] = 0 ;
V_220 = 1 ;
}
static int T_4 F_45 ( char * V_221 , int * V_222 , char * V_75 )
{
int V_10 ;
char * V_223 ;
for ( V_10 = 0 ; V_10 < V_217 ; V_10 ++ ) {
if ( V_219 [ V_10 ] )
continue;
if ( ! strncmp ( V_218 [ V_10 ] , V_221 , strlen ( V_221 ) ) )
break;
}
if ( V_10 == V_217 )
return 0 ;
V_219 [ V_10 ] = 1 ;
V_223 = V_218 [ V_10 ] + strlen ( V_221 ) ;
* V_222 = - 1 ;
if ( * V_223 != ':' )
return ++ V_10 ;
V_223 ++ ;
if ( ( * V_223 >= '0' ) && ( * V_223 <= '9' ) ) {
* V_222 = F_46 ( V_223 , NULL , 0 ) ;
}
return ++ V_10 ;
}
static int F_47 ( T_5 V_224 , T_5 * V_225 , T_1 * V_226 )
{
void T_6 * V_227 = F_48 ( V_224 , 0x34 ) ;
if ( ! V_227 )
return 0 ;
* V_225 = F_49 ( V_227 + 0x10 ) ;
if ( * V_225 == 0x41564f4e || F_49 ( V_227 + 0x30 ) == 0x61776c41 ) {
* V_226 = ~ F_50 ( V_227 + 0x20 ) ;
F_51 ( V_227 ) ;
return 1 ;
}
F_51 ( V_227 ) ;
return 0 ;
}
static int T_4 F_52 ( struct V_228 * V_229 )
{
struct V_57 * V_58 ;
struct V_1 * V_2 ;
int V_230 ;
int V_231 ;
int V_10 ;
unsigned short V_232 ;
T_1 V_226 ;
T_1 V_233 ;
unsigned long V_110 ;
int V_222 ;
char V_75 [ 32 ] ;
if ( ! V_220 && V_234 )
F_43 ( V_234 , NULL ) ;
V_230 = 0 ;
for ( V_231 = 0 ; V_235 [ V_231 ] ; V_231 ++ ) {
T_5 V_225 = 0 ;
if ( F_45 ( L_63 , & V_222 , V_75 ) ) {
V_232 = V_222 ;
V_226 = ~ F_53 ( V_232 + V_236 ) & 0xff ;
F_33 ( L_64 , V_232 ) ;
V_231 = 2 ;
}
else if ( F_47 ( V_235 [ V_231 ] , & V_225 , & V_226 ) ) {
F_33 ( L_65 , ( unsigned int ) V_235 [ V_231 ] ) ;
V_10 = V_226 & ( V_237 | V_238 ) ;
V_232 = V_239 [ V_10 ] ;
V_10 = ~ F_53 ( V_232 + V_236 ) & 0xff ;
if ( V_10 != V_226 ) {
F_33 ( L_66 , V_10 , V_226 ) ;
continue;
}
} else
continue;
if ( ! ( V_226 & V_240 ) ) {
F_33 ( L_67 , V_232 ) ;
continue;
}
V_233 = F_53 ( V_232 + V_184 ) ;
if ( V_226 & V_241 ) {
F_33 ( L_68 , V_232 ) ;
F_33 ( L_69 ) ;
F_33 ( L_70 ) ;
continue;
}
V_229 -> V_242 = L_71 ;
V_58 = F_54 ( V_229 , sizeof( struct V_1 ) ) ;
if ( V_58 == NULL )
continue;
V_230 ++ ;
V_2 = (struct V_1 * ) V_58 -> V_2 ;
V_58 -> V_243 = V_2 -> V_99 = V_232 ;
V_2 -> V_244 = V_226 ;
V_2 -> V_233 = V_233 ;
F_2 ( 0 , V_85 ) ;
F_2 ( 0 , V_86 ) ;
F_2 ( 0 , V_245 ) ;
V_10 = V_246 [ ( V_226 & ( V_247 | V_248 ) ) >> V_249 ] ;
if ( F_55 ( V_10 , F_26 , V_250 , L_71 , V_58 ) ) {
F_33 ( L_72 ) ;
V_230 -- ;
continue;
}
V_58 -> V_251 = V_10 ;
V_58 -> V_252 = 13 ;
F_56 ( V_232 , 13 , L_71 ) ;
for ( V_10 = 0 ; V_10 < 8 ; V_10 ++ ) {
V_2 -> V_125 [ V_10 ] = 0 ;
V_2 -> V_82 [ V_10 ] = F_12 ( V_198 / 4 , V_190 ) ;
V_2 -> V_128 [ V_10 ] = V_199 ;
#ifdef F_28
V_2 -> V_253 [ V_10 ] = 0 ;
V_2 -> V_254 [ V_10 ] = 0 ;
V_2 -> V_175 [ V_10 ] = 0 ;
#endif
}
V_2 -> V_73 = NULL ;
V_2 -> V_123 = NULL ;
V_2 -> V_114 = NULL ;
V_2 -> V_174 = NULL ;
V_2 -> V_93 = V_126 ;
V_2 -> V_95 = V_122 ;
V_2 -> V_87 = V_89 ;
V_2 -> V_156 = V_255 ;
V_2 -> args = V_256 ;
V_2 -> V_148 = 0 ;
V_2 -> V_134 = 0 ;
V_2 -> V_161 = V_198 ;
if ( V_225 == 0x41564f4e && ( V_226 & V_257 ) )
V_2 -> V_258 = 0x00 ;
else
V_2 -> V_258 = 0xff ;
#ifdef F_57
V_2 -> V_259 = V_260 | V_261 | V_262 | V_263 | V_264 | V_265 | V_266 ;
#ifdef F_28
V_2 -> V_112 = 0 ;
#endif
#endif
if ( F_45 ( L_73 , & V_222 , V_75 ) )
V_2 -> V_258 = V_222 ;
if ( F_45 ( L_74 , & V_222 , V_75 ) )
V_2 -> V_161 = V_51 [ F_11 ( ( unsigned int ) V_222 ) ] . V_52 ;
if ( F_45 ( L_75 , & V_222 , V_75 ) ) {
if ( ( V_222 >= V_267 ) && ( V_222 <= V_268 ) )
V_2 -> V_156 = V_222 ;
else
V_2 -> V_156 = V_255 ;
}
if ( F_45 ( L_76 , & V_222 , V_75 ) )
V_2 -> args ^= V_269 ;
if ( F_45 ( L_77 , & V_222 , V_75 ) )
V_2 -> V_87 = V_222 ;
if ( F_45 ( L_78 , & V_222 , V_75 ) )
V_2 -> args = ( V_222 & V_270 ) ;
#ifdef F_57
if ( F_45 ( L_79 , & V_222 , V_75 ) )
V_2 -> V_259 = V_222 ;
#endif
F_27 ( V_58 -> V_111 , V_110 ) ;
V_10 = F_36 ( V_58 , ( V_2 -> args & V_269 ) ? V_271 : V_182 ) ;
F_34 ( V_58 -> V_111 , V_110 ) ;
V_2 -> V_272 = F_1 ( V_2 , V_273 ) ;
if ( V_10 & 0x01 ) {
if ( V_10 & V_193 )
V_2 -> V_274 = V_275 ;
else
V_2 -> V_274 = V_276 ;
} else
V_2 -> V_274 = V_277 ;
F_33 ( L_80 , ( V_226 & 0x7f ) , V_58 -> V_251 , V_2 -> V_99 , ( V_226 & V_278 ) ? L_81 : L_82 , ( V_226 & V_257 ) ? L_81 : L_82 ) ;
F_33 ( L_83 , V_233 , ( V_2 -> V_274 == V_277 ) ? L_84 : ( V_2 -> V_274 == V_276 ) ? L_85 : ( V_2 -> V_274 == V_275 ) ? L_86 : L_87 , V_2 -> V_272 ) ;
#ifdef F_58
F_33 ( L_88 ) ;
for ( V_10 = 0 ; V_10 < V_217 ; V_10 ++ )
F_33 ( L_89 , V_218 [ V_10 ] ) ;
F_33 ( L_90 ) ;
#endif
if ( V_2 -> V_258 == 0xff )
F_33 ( L_91 ) ;
F_33 ( L_92 , V_279 , V_280 ) ;
}
return V_230 ;
}
static int F_59 ( struct V_57 * V_281 )
{
if ( V_281 -> V_251 )
F_60 ( V_281 -> V_251 , V_281 ) ;
if ( V_281 -> V_243 && V_281 -> V_252 )
F_61 ( V_281 -> V_243 , V_281 -> V_252 ) ;
return 0 ;
}
static int F_62 ( struct V_282 * V_283 , struct V_284 * V_285 , T_7 V_286 , int * V_287 )
{
int V_288 ;
V_288 = V_286 ;
V_287 [ 0 ] = 64 ;
V_287 [ 1 ] = 32 ;
V_287 [ 2 ] = V_288 >> 11 ;
if ( V_287 [ 2 ] > 1024 ) {
V_287 [ 0 ] = 64 ;
V_287 [ 1 ] = 63 ;
V_287 [ 2 ] = ( unsigned long ) V_286 / ( V_287 [ 0 ] * V_287 [ 1 ] ) ;
}
if ( V_287 [ 2 ] > 1024 ) {
V_287 [ 0 ] = 128 ;
V_287 [ 1 ] = 63 ;
V_287 [ 2 ] = ( unsigned long ) V_286 / ( V_287 [ 0 ] * V_287 [ 1 ] ) ;
}
if ( V_287 [ 2 ] > 1024 ) {
V_287 [ 0 ] = 255 ;
V_287 [ 1 ] = 63 ;
V_287 [ 2 ] = ( unsigned long ) V_286 / ( V_287 [ 0 ] * V_287 [ 1 ] ) ;
}
return 0 ;
}
static int F_63 ( struct V_57 * V_58 , char * V_75 , char * * V_289 , T_8 V_290 , int V_291 , int V_292 )
{
#ifdef F_57
char * V_293 ;
char V_294 [ 128 ] ;
unsigned long V_110 ;
struct V_1 * V_295 ;
T_2 * V_7 ;
int V_10 , V_80 ;
static int V_296 = 0 ;
V_295 = (struct V_1 * ) V_58 -> V_2 ;
if ( V_292 ) {
V_75 [ V_291 ] = '\0' ;
V_293 = V_75 ;
if ( ! strncmp ( V_293 , L_93 , 6 ) ) {
V_293 += 6 ;
V_295 -> args = F_46 ( V_293 , NULL , 0 ) & V_270 ;
} else if ( ! strncmp ( V_293 , L_94 , 11 ) ) {
V_293 += 11 ;
V_10 = F_46 ( V_293 , NULL , 0 ) ;
if ( V_10 < V_267 || V_10 > V_268 )
V_10 = V_255 ;
V_295 -> V_156 = V_10 ;
} else if ( ! strncmp ( V_293 , L_95 , 7 ) ) {
V_293 += 7 ;
V_10 = F_46 ( V_293 , NULL , 0 ) ;
V_295 -> V_161 = V_51 [ F_11 ( ( unsigned int ) V_10 ) ] . V_52 ;
} else if ( ! strncmp ( V_293 , L_96 , 7 ) ) {
V_293 += 7 ;
V_10 = F_46 ( V_293 , NULL , 0 ) ;
for ( V_80 = 0 ; V_80 < 7 ; V_80 ++ )
if ( V_10 & ( 1 << V_80 ) )
V_295 -> V_128 [ V_80 ] = V_199 ;
} else if ( ! strncmp ( V_293 , L_97 , 5 ) ) {
V_293 += 5 ;
V_295 -> V_259 = F_46 ( V_293 , NULL , 0 ) ;
} else if ( ! strncmp ( V_293 , L_98 , 7 ) ) {
V_293 += 7 ;
V_295 -> V_87 = F_46 ( V_293 , NULL , 0 ) ;
}
return V_291 ;
}
F_27 ( V_58 -> V_111 , V_110 ) ;
V_293 = V_75 ;
* V_293 = '\0' ;
if ( V_295 -> V_259 & V_260 ) {
sprintf ( V_294 , L_99 , V_279 , V_280 ) ;
strcat ( V_293 , V_294 ) ;
}
if ( V_295 -> V_259 & V_261 ) {
sprintf ( V_294 , L_100 , ( V_295 -> V_244 & 0x7f ) , V_58 -> V_251 , V_295 -> V_99 , ( V_295 -> V_244 & 0x40 ) ? L_81 : L_82 , ( V_295 -> V_244 & 0x20 ) ? L_81 : L_82 ) ;
strcat ( V_293 , V_294 ) ;
strcat ( V_293 , L_101 ) ;
for ( V_10 = 0 ; V_10 < 7 ; V_10 ++ ) {
sprintf ( V_294 , L_102 , V_295 -> V_82 [ V_10 ] ) ;
strcat ( V_293 , V_294 ) ;
}
strcat ( V_293 , L_103 ) ;
for ( V_10 = 0 ; V_10 < 7 ; V_10 ++ ) {
sprintf ( V_294 , L_102 , V_295 -> V_128 [ V_10 ] ) ;
strcat ( V_293 , V_294 ) ;
}
}
#ifdef F_28
if ( V_295 -> V_259 & V_262 ) {
strcat ( V_293 , L_104 ) ;
for ( V_10 = 0 ; V_10 < 7 ; V_10 ++ ) {
sprintf ( V_294 , L_105 , V_295 -> V_253 [ V_10 ] ) ;
strcat ( V_293 , V_294 ) ;
}
strcat ( V_293 , L_106 ) ;
for ( V_10 = 0 ; V_10 < 7 ; V_10 ++ ) {
sprintf ( V_294 , L_105 , V_295 -> V_254 [ V_10 ] ) ;
strcat ( V_293 , V_294 ) ;
}
strcat ( V_293 , L_107 ) ;
for ( V_10 = 0 ; V_10 < 7 ; V_10 ++ ) {
sprintf ( V_294 , L_105 , V_295 -> V_175 [ V_10 ] ) ;
strcat ( V_293 , V_294 ) ;
}
sprintf ( V_294 , L_108 , V_295 -> V_112 ) ;
strcat ( V_293 , V_294 ) ;
}
#endif
if ( V_295 -> V_259 & V_263 ) {
strcat ( V_293 , L_109 ) ;
if ( V_295 -> V_114 ) {
V_7 = ( T_2 * ) V_295 -> V_114 ;
sprintf ( V_294 , L_110 , V_7 -> V_60 -> V_83 , V_7 -> V_60 -> V_106 , V_7 -> V_20 [ 0 ] ) ;
strcat ( V_293 , V_294 ) ;
}
}
if ( V_295 -> V_259 & V_264 ) {
strcat ( V_293 , L_111 ) ;
V_7 = ( T_2 * ) V_295 -> V_73 ;
while ( V_7 ) {
sprintf ( V_294 , L_110 , V_7 -> V_60 -> V_83 , V_7 -> V_60 -> V_106 , V_7 -> V_20 [ 0 ] ) ;
strcat ( V_293 , V_294 ) ;
V_7 = ( T_2 * ) V_7 -> V_62 ;
}
}
if ( V_295 -> V_259 & V_265 ) {
strcat ( V_293 , L_112 ) ;
V_7 = ( T_2 * ) V_295 -> V_174 ;
while ( V_7 ) {
sprintf ( V_294 , L_110 , V_7 -> V_60 -> V_83 , V_7 -> V_60 -> V_106 , V_7 -> V_20 [ 0 ] ) ;
strcat ( V_293 , V_294 ) ;
V_7 = ( T_2 * ) V_7 -> V_62 ;
}
}
if ( V_295 -> V_259 & V_297 ) {
;
}
strcat ( V_293 , L_90 ) ;
F_34 ( V_58 -> V_111 , V_110 ) ;
* V_289 = V_75 ;
if ( V_296 ) {
V_296 = 0 ;
return 0 ;
}
if ( V_290 > 0x40000 )
V_296 = 1 ;
if ( V_295 -> V_259 & V_266 )
V_296 = 1 ;
return strlen ( V_293 ) ;
#else
return 0 ;
#endif
}
