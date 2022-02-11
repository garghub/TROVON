static void F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 , bool V_5 )
{
if ( F_2 ( V_2 ) )
return;
if ( V_3 && V_4 ) {
int V_6 = ( V_4 + V_7 - 1 ) >> V_8 ;
if ( V_5 )
F_3 ( ( unsigned long ) V_3 , V_6 ) ;
else
F_4 ( ( unsigned long ) V_3 , V_6 ) ;
}
}
static inline void F_5 ( struct V_1 * V_2 , struct V_9 * V_10 ,
bool V_5 )
{
F_1 ( V_2 , V_10 -> V_11 , V_10 -> V_12 , V_5 ) ;
}
static inline void F_6 ( struct V_1 * V_2 , struct V_13 * V_13 ,
struct V_14 * V_15 , bool V_5 )
{
if ( V_13 -> V_16 != V_5 ) {
F_1 ( V_2 , V_15 -> V_17 , V_15 -> V_18 , V_5 ) ;
V_13 -> V_16 = V_5 ;
}
}
static inline void F_5 ( struct V_1 * V_2 , struct V_9 * V_10 ,
bool V_5 )
{
}
static inline void F_6 ( struct V_1 * V_2 , struct V_13 * V_13 ,
struct V_14 * V_15 , bool V_5 )
{
}
static int F_7 ( struct V_1 * V_2 )
{
int V_19 ;
V_19 = F_8 ( V_20 ,
F_9 ( V_2 -> V_21 ) ,
V_7 , & V_2 -> V_22 ) ;
if ( V_19 < 0 ) {
F_10 (KERN_ERR SFX L_1 ) ;
return V_19 ;
}
F_5 ( V_2 , & V_2 -> V_22 , true ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_12 ( & V_2 -> V_23 ) ;
V_2 -> V_24 . V_3 = V_2 -> V_22 . V_3 ;
V_2 -> V_24 . V_10 = ( V_25 * ) V_2 -> V_22 . V_11 ;
F_13 ( V_2 , V_26 , ( V_25 ) V_2 -> V_24 . V_3 ) ;
F_13 ( V_2 , V_27 , F_14 ( V_2 -> V_24 . V_3 ) ) ;
F_15 ( V_2 , V_28 , 0x02 ) ;
F_16 ( V_2 , V_29 , 0 ) ;
F_16 ( V_2 , V_30 , V_31 ) ;
F_15 ( V_2 , V_32 , V_33 ) ;
V_2 -> V_34 . V_3 = V_2 -> V_22 . V_3 + 2048 ;
V_2 -> V_34 . V_10 = ( V_25 * ) ( V_2 -> V_22 . V_11 + 2048 ) ;
V_2 -> V_34 . V_35 = V_2 -> V_34 . V_36 = 0 ;
memset ( V_2 -> V_34 . V_37 , 0 , sizeof( V_2 -> V_34 . V_37 ) ) ;
F_13 ( V_2 , V_38 , ( V_25 ) V_2 -> V_34 . V_3 ) ;
F_13 ( V_2 , V_39 , F_14 ( V_2 -> V_34 . V_3 ) ) ;
F_15 ( V_2 , V_40 , 0x02 ) ;
F_16 ( V_2 , V_41 , V_42 ) ;
if ( V_2 -> V_43 & V_44 )
F_16 ( V_2 , V_45 , 0xc0 ) ;
else
F_16 ( V_2 , V_45 , 1 ) ;
F_15 ( V_2 , V_46 , V_47 | V_48 ) ;
F_17 ( & V_2 -> V_23 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_12 ( & V_2 -> V_23 ) ;
F_15 ( V_2 , V_46 , 0 ) ;
F_15 ( V_2 , V_32 , 0 ) ;
F_17 ( & V_2 -> V_23 ) ;
}
static unsigned int F_19 ( V_25 V_49 )
{
unsigned int V_3 = V_49 >> 28 ;
if ( V_3 >= V_50 ) {
F_20 () ;
V_3 = 0 ;
}
return V_3 ;
}
static unsigned int F_21 ( V_25 V_51 )
{
unsigned int V_3 = V_51 & 0xf ;
if ( V_3 >= V_50 ) {
F_20 () ;
V_3 = 0 ;
}
return V_3 ;
}
static int F_22 ( struct V_52 * V_53 , V_25 V_54 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
unsigned int V_3 = F_19 ( V_54 ) ;
unsigned int V_35 ;
F_12 ( & V_2 -> V_23 ) ;
V_35 = F_23 ( V_2 , V_29 ) ;
V_35 ++ ;
V_35 %= V_56 ;
V_2 -> V_34 . V_37 [ V_3 ] ++ ;
V_2 -> V_24 . V_10 [ V_35 ] = F_24 ( V_54 ) ;
F_13 ( V_2 , V_29 , V_35 ) ;
F_17 ( & V_2 -> V_23 ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
unsigned int V_36 , V_35 ;
unsigned int V_3 ;
V_25 V_51 , V_57 ;
V_35 = F_23 ( V_2 , V_41 ) ;
if ( V_35 == V_2 -> V_34 . V_35 )
return;
V_2 -> V_34 . V_35 = V_35 ;
while ( V_2 -> V_34 . V_36 != V_35 ) {
V_2 -> V_34 . V_36 ++ ;
V_2 -> V_34 . V_36 %= V_58 ;
V_36 = V_2 -> V_34 . V_36 << 1 ;
V_57 = F_26 ( V_2 -> V_34 . V_10 [ V_36 + 1 ] ) ;
V_51 = F_26 ( V_2 -> V_34 . V_10 [ V_36 ] ) ;
V_3 = F_21 ( V_57 ) ;
if ( V_57 & V_59 )
F_27 ( V_2 -> V_53 , V_51 , V_57 ) ;
else if ( V_2 -> V_34 . V_37 [ V_3 ] ) {
V_2 -> V_34 . V_51 [ V_3 ] = V_51 ;
F_28 () ;
V_2 -> V_34 . V_37 [ V_3 ] -- ;
} else
F_10 (KERN_ERR SFX L_2
L_3 ,
res, res_ex,
chip->last_cmd[addr]) ;
}
}
static unsigned int F_29 ( struct V_52 * V_53 ,
unsigned int V_3 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
unsigned long V_60 ;
int V_61 = 0 ;
V_62:
V_60 = V_63 + F_30 ( 1000 ) ;
for (; ; ) {
if ( V_2 -> V_64 || V_61 ) {
F_12 ( & V_2 -> V_23 ) ;
F_25 ( V_2 ) ;
F_17 ( & V_2 -> V_23 ) ;
}
if ( ! V_2 -> V_34 . V_37 [ V_3 ] ) {
F_31 () ;
V_53 -> V_65 = 0 ;
if ( ! V_61 )
V_2 -> V_66 = 0 ;
return V_2 -> V_34 . V_51 [ V_3 ] ;
}
if ( F_32 ( V_63 , V_60 ) )
break;
if ( V_53 -> V_67 )
F_33 ( 2 ) ;
else {
F_34 ( 10 ) ;
F_35 () ;
}
}
if ( ! V_2 -> V_64 && V_2 -> V_66 < 2 ) {
F_36 ( V_68 L_4
L_5 ,
V_2 -> V_69 [ V_3 ] ) ;
V_61 = 1 ;
V_2 -> V_66 ++ ;
goto V_62;
}
if ( ! V_2 -> V_64 ) {
F_10 (KERN_WARNING SFX L_4
L_6 ,
chip->last_cmd[addr]) ;
V_2 -> V_64 = 1 ;
goto V_62;
}
if ( V_2 -> V_70 ) {
F_10 (KERN_WARNING SFX L_7
L_8 ,
chip->last_cmd[addr]) ;
F_37 ( V_2 -> V_71 , V_2 ) ;
V_2 -> V_71 = - 1 ;
F_38 ( V_2 -> V_21 ) ;
V_2 -> V_70 = 0 ;
if ( F_39 ( V_2 , 1 ) < 0 ) {
V_53 -> V_65 = 1 ;
return - 1 ;
}
goto V_62;
}
if ( V_2 -> V_72 ) {
return - 1 ;
}
V_53 -> V_65 = 1 ;
if ( V_53 -> V_73 && ! V_53 -> V_74 && ! V_53 -> V_75 ) {
V_53 -> V_74 = 1 ;
return - 1 ;
}
F_10 ( V_76 L_9
L_10 ,
V_2 -> V_69 [ V_3 ] ) ;
V_2 -> V_77 = 1 ;
V_53 -> V_74 = 0 ;
F_18 ( V_2 ) ;
F_13 ( V_2 , V_78 , F_40 ( V_2 , V_78 ) & ~ V_79 ) ;
return - 1 ;
}
static int F_41 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_60 = 50 ;
while ( V_60 -- ) {
if ( F_42 ( V_2 , V_80 ) & V_81 ) {
V_2 -> V_34 . V_51 [ V_3 ] = F_40 ( V_2 , V_82 ) ;
return 0 ;
}
F_34 ( 1 ) ;
}
if ( F_43 () )
F_44 ( V_68 L_11 ,
F_42 ( V_2 , V_80 ) ) ;
V_2 -> V_34 . V_51 [ V_3 ] = - 1 ;
return - V_83 ;
}
static int F_45 ( struct V_52 * V_53 , V_25 V_54 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
unsigned int V_3 = F_19 ( V_54 ) ;
int V_60 = 50 ;
V_53 -> V_65 = 0 ;
while ( V_60 -- ) {
if ( ! ( ( F_42 ( V_2 , V_80 ) & V_84 ) ) ) {
F_16 ( V_2 , V_80 , F_42 ( V_2 , V_80 ) |
V_81 ) ;
F_13 ( V_2 , V_85 , V_54 ) ;
F_16 ( V_2 , V_80 , F_42 ( V_2 , V_80 ) |
V_84 ) ;
return F_41 ( V_2 , V_3 ) ;
}
F_34 ( 1 ) ;
}
if ( F_43 () )
F_44 ( V_68 L_12 ,
F_42 ( V_2 , V_80 ) , V_54 ) ;
return - V_83 ;
}
static unsigned int F_46 ( struct V_52 * V_53 ,
unsigned int V_3 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
return V_2 -> V_34 . V_51 [ V_3 ] ;
}
static int F_47 ( struct V_52 * V_53 , unsigned int V_54 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
V_2 -> V_69 [ F_19 ( V_54 ) ] = V_54 ;
if ( V_2 -> V_77 )
return F_45 ( V_53 , V_54 ) ;
else
return F_22 ( V_53 , V_54 ) ;
}
static unsigned int F_48 ( struct V_52 * V_53 ,
unsigned int V_3 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
if ( V_2 -> V_77 )
return F_46 ( V_53 , V_3 ) ;
else
return F_29 ( V_53 , V_3 ) ;
}
static int F_49 ( struct V_1 * V_2 , int V_86 )
{
int V_87 ;
if ( ! V_86 )
goto V_88;
F_15 ( V_2 , V_89 , V_90 ) ;
F_13 ( V_2 , V_78 , F_40 ( V_2 , V_78 ) & ~ V_91 ) ;
V_87 = 50 ;
while ( F_23 ( V_2 , V_78 ) && -- V_87 )
F_33 ( 1 ) ;
F_33 ( 1 ) ;
F_15 ( V_2 , V_78 , F_23 ( V_2 , V_78 ) | V_91 ) ;
V_87 = 50 ;
while ( ! F_23 ( V_2 , V_78 ) && -- V_87 )
F_33 ( 1 ) ;
F_33 ( 1 ) ;
V_88:
if ( ! F_23 ( V_2 , V_78 ) ) {
F_44 ( V_68 L_13 ) ;
return - V_92 ;
}
if ( ! V_2 -> V_77 )
F_13 ( V_2 , V_78 , F_40 ( V_2 , V_78 ) |
V_79 ) ;
if ( ! V_2 -> V_93 ) {
V_2 -> V_93 = F_42 ( V_2 , V_89 ) ;
F_36 ( V_68 L_14 , V_2 -> V_93 ) ;
}
return 0 ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_13 ( V_2 , V_94 , F_40 ( V_2 , V_94 ) |
V_95 | V_96 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
int V_97 ;
for ( V_97 = 0 ; V_97 < V_2 -> V_98 ; V_97 ++ ) {
struct V_13 * V_13 = & V_2 -> V_13 [ V_97 ] ;
F_52 ( V_13 , V_99 ,
F_53 ( V_13 , V_99 ) & ~ V_100 ) ;
}
F_15 ( V_2 , V_94 , 0 ) ;
F_13 ( V_2 , V_94 , F_40 ( V_2 , V_94 ) &
~ ( V_95 | V_96 ) ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
int V_97 ;
for ( V_97 = 0 ; V_97 < V_2 -> V_98 ; V_97 ++ ) {
struct V_13 * V_13 = & V_2 -> V_13 [ V_97 ] ;
F_52 ( V_13 , V_101 , V_100 ) ;
}
F_15 ( V_2 , V_89 , V_90 ) ;
F_15 ( V_2 , V_102 , V_103 ) ;
F_13 ( V_2 , V_104 , V_95 | V_105 ) ;
}
static void F_55 ( struct V_1 * V_2 , struct V_13 * V_13 )
{
V_13 -> V_106 = 1 ;
F_13 ( V_2 , V_94 ,
F_40 ( V_2 , V_94 ) | ( 1 << V_13 -> V_107 ) ) ;
F_52 ( V_13 , V_99 , F_53 ( V_13 , V_99 ) |
V_108 | V_100 ) ;
}
static void F_56 ( struct V_1 * V_2 , struct V_13 * V_13 )
{
F_52 ( V_13 , V_99 , F_53 ( V_13 , V_99 ) &
~ ( V_108 | V_100 ) ) ;
F_52 ( V_13 , V_101 , V_100 ) ;
}
static void F_57 ( struct V_1 * V_2 , struct V_13 * V_13 )
{
F_56 ( V_2 , V_13 ) ;
F_13 ( V_2 , V_94 ,
F_40 ( V_2 , V_94 ) & ~ ( 1 << V_13 -> V_107 ) ) ;
}
static void F_58 ( struct V_1 * V_2 , int V_86 )
{
if ( V_2 -> V_109 )
return;
F_49 ( V_2 , V_86 ) ;
F_54 ( V_2 ) ;
F_50 ( V_2 ) ;
if ( ! V_2 -> V_77 )
F_11 ( V_2 ) ;
F_13 ( V_2 , V_110 , ( V_25 ) V_2 -> V_111 . V_3 ) ;
F_13 ( V_2 , V_112 , F_14 ( V_2 -> V_111 . V_3 ) ) ;
V_2 -> V_109 = 1 ;
}
static void F_59 ( struct V_113 * V_21 , unsigned int V_114 ,
unsigned char V_115 , unsigned char V_54 )
{
unsigned char V_116 ;
F_60 ( V_21 , V_114 , & V_116 ) ;
V_116 &= ~ V_115 ;
V_116 |= ( V_54 & V_115 ) ;
F_61 ( V_21 , V_114 , V_116 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
if ( V_2 -> V_117 && V_2 -> V_118 == V_119 ) {
T_2 V_117 ;
F_60 ( V_2 -> V_21 , 0x42 , & V_117 ) ;
if ( ! ( V_117 & 0x80 ) && V_2 -> V_21 -> V_120 == 0x30 ) {
V_2 -> V_117 = 0 ;
F_36 ( V_68 L_15 ) ;
}
}
if ( ! ( V_2 -> V_43 & V_121 ) ) {
F_36 ( V_68 L_16 ) ;
F_59 ( V_2 -> V_21 , V_122 , 0x07 , 0 ) ;
}
if ( V_2 -> V_43 & V_123 ) {
F_36 ( V_68 L_17 , F_2 ( V_2 ) ) ;
F_59 ( V_2 -> V_21 ,
V_124 , 0x07 ,
F_2 ( V_2 ) ? V_125 : 0 ) ;
}
if ( V_2 -> V_43 & V_126 ) {
F_36 ( V_68 L_18 , F_2 ( V_2 ) ) ;
F_59 ( V_2 -> V_21 ,
V_127 ,
0x0f , V_128 ) ;
F_59 ( V_2 -> V_21 ,
V_129 ,
0x01 , V_130 ) ;
F_59 ( V_2 -> V_21 ,
V_131 ,
0x01 , V_130 ) ;
}
if ( V_2 -> V_43 & V_132 ) {
unsigned short V_117 ;
F_63 ( V_2 -> V_21 , V_133 , & V_117 ) ;
if ( ( ! F_2 ( V_2 ) && ! ( V_117 & V_134 ) ) ||
( F_2 ( V_2 ) && ( V_117 & V_134 ) ) ) {
V_117 &= ~ V_134 ;
if ( ! F_2 ( V_2 ) )
V_117 |= V_134 ;
F_64 ( V_2 -> V_21 , V_133 , V_117 ) ;
F_63 ( V_2 -> V_21 ,
V_133 , & V_117 ) ;
}
F_36 ( V_68 L_19 ,
( V_117 & V_134 )
? L_20 : L_21 ) ;
}
}
static T_3 F_65 ( int V_71 , void * V_135 )
{
struct V_1 * V_2 = V_135 ;
struct V_13 * V_13 ;
V_25 V_136 ;
T_2 V_137 ;
int V_97 , V_138 ;
F_66 ( & V_2 -> V_23 ) ;
V_136 = F_40 ( V_2 , V_104 ) ;
if ( V_136 == 0 ) {
F_67 ( & V_2 -> V_23 ) ;
return V_139 ;
}
for ( V_97 = 0 ; V_97 < V_2 -> V_98 ; V_97 ++ ) {
V_13 = & V_2 -> V_13 [ V_97 ] ;
if ( V_136 & V_13 -> V_140 ) {
V_137 = F_53 ( V_13 , V_101 ) ;
F_52 ( V_13 , V_101 , V_100 ) ;
if ( ! V_13 -> V_141 || ! V_13 -> V_142 ||
! ( V_137 & V_143 ) )
continue;
V_138 = F_68 ( V_2 , V_13 ) ;
if ( V_138 == 1 ) {
V_13 -> V_144 = 0 ;
F_67 ( & V_2 -> V_23 ) ;
F_69 ( V_13 -> V_141 ) ;
F_66 ( & V_2 -> V_23 ) ;
} else if ( V_138 == 0 && V_2 -> V_53 && V_2 -> V_53 -> V_145 ) {
V_13 -> V_144 = 1 ;
F_70 ( V_2 -> V_53 -> V_145 ,
& V_2 -> V_146 ) ;
}
}
}
V_136 = F_23 ( V_2 , V_102 ) ;
if ( V_136 & V_103 ) {
if ( V_136 & V_147 ) {
if ( V_2 -> V_43 & V_148 )
F_34 ( 80 ) ;
F_25 ( V_2 ) ;
}
F_15 ( V_2 , V_102 , V_103 ) ;
}
#if 0
if (azx_readb(chip, STATESTS) & 0x04)
azx_writeb(chip, STATESTS, 0x04);
#endif
F_67 ( & V_2 -> V_23 ) ;
return V_149 ;
}
static int F_71 ( struct V_150 * V_141 ,
struct V_13 * V_13 , V_25 * * V_151 ,
int V_152 , int V_4 , int V_153 )
{
V_25 * V_154 = * V_151 ;
while ( V_4 > 0 ) {
T_4 V_3 ;
int V_155 ;
if ( V_13 -> V_156 >= V_157 )
return - V_158 ;
V_3 = F_72 ( V_141 , V_152 ) ;
V_154 [ 0 ] = F_24 ( ( V_25 ) V_3 ) ;
V_154 [ 1 ] = F_24 ( F_14 ( V_3 ) ) ;
V_155 = F_73 ( V_141 , V_152 , V_4 ) ;
V_154 [ 2 ] = F_24 ( V_155 ) ;
V_4 -= V_155 ;
V_154 [ 3 ] = ( V_4 || ! V_153 ) ? 0 : F_24 ( 0x01 ) ;
V_154 += 4 ;
V_13 -> V_156 ++ ;
V_152 += V_155 ;
}
* V_151 = V_154 ;
return V_152 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_150 * V_141 ,
struct V_13 * V_13 )
{
V_25 * V_154 ;
int V_97 , V_152 , V_159 , V_160 ;
int V_161 ;
F_75 ( V_13 , V_162 , 0 ) ;
F_75 ( V_13 , V_163 , 0 ) ;
V_160 = V_13 -> V_160 ;
V_159 = V_13 -> V_164 / V_160 ;
V_154 = ( V_25 * ) V_13 -> V_154 . V_11 ;
V_152 = 0 ;
V_13 -> V_156 = 0 ;
V_161 = V_165 [ V_2 -> V_166 ] ;
if ( V_161 > 0 ) {
struct V_14 * V_15 = V_141 -> V_15 ;
int V_167 = V_161 ;
V_161 = ( V_161 * V_15 -> V_168 + 47999 ) / 48000 ;
if ( ! V_161 )
V_161 = V_167 ;
else
V_161 = ( ( V_161 + V_167 - 1 ) / V_167 ) *
V_167 ;
V_161 = F_76 ( V_15 , V_161 ) ;
if ( V_161 >= V_160 ) {
F_10 (KERN_WARNING SFX L_22 ,
bdl_pos_adj[chip->dev_index]) ;
V_161 = 0 ;
} else {
V_152 = F_71 ( V_141 , V_13 ,
& V_154 , V_152 , V_161 ,
! V_141 -> V_15 -> V_169 ) ;
if ( V_152 < 0 )
goto error;
}
} else
V_161 = 0 ;
for ( V_97 = 0 ; V_97 < V_159 ; V_97 ++ ) {
if ( V_97 == V_159 - 1 && V_161 )
V_152 = F_71 ( V_141 , V_13 , & V_154 , V_152 ,
V_160 - V_161 , 0 ) ;
else
V_152 = F_71 ( V_141 , V_13 , & V_154 , V_152 ,
V_160 ,
! V_141 -> V_15 -> V_169 ) ;
if ( V_152 < 0 )
goto error;
}
return 0 ;
error:
F_10 (KERN_ERR SFX L_23 ,
azx_dev->bufsize, period_bytes) ;
return - V_158 ;
}
static void F_77 ( struct V_1 * V_2 , struct V_13 * V_13 )
{
unsigned char V_54 ;
int V_60 ;
F_56 ( V_2 , V_13 ) ;
F_52 ( V_13 , V_99 , F_53 ( V_13 , V_99 ) |
V_170 ) ;
F_34 ( 3 ) ;
V_60 = 300 ;
while ( ! ( ( V_54 = F_53 ( V_13 , V_99 ) ) & V_170 ) &&
-- V_60 )
;
V_54 &= ~ V_170 ;
F_52 ( V_13 , V_99 , V_54 ) ;
F_34 ( 3 ) ;
V_60 = 300 ;
while ( ( ( V_54 = F_53 ( V_13 , V_99 ) ) & V_170 ) &&
-- V_60 )
;
* V_13 -> V_111 = 0 ;
}
static int F_78 ( struct V_1 * V_2 , struct V_13 * V_13 )
{
unsigned int V_54 ;
F_56 ( V_2 , V_13 ) ;
V_54 = F_79 ( V_13 , V_99 ) ;
V_54 = ( V_54 & ~ V_171 ) |
( V_13 -> V_172 << V_173 ) ;
if ( ! F_2 ( V_2 ) )
V_54 |= V_174 ;
F_75 ( V_13 , V_99 , V_54 ) ;
F_75 ( V_13 , V_175 , V_13 -> V_164 ) ;
F_80 ( V_13 , V_176 , V_13 -> V_177 ) ;
F_80 ( V_13 , V_178 , V_13 -> V_156 - 1 ) ;
F_75 ( V_13 , V_162 , ( V_25 ) V_13 -> V_154 . V_3 ) ;
F_75 ( V_13 , V_163 , F_14 ( V_13 -> V_154 . V_3 ) ) ;
if ( V_2 -> V_179 [ 0 ] != V_180 ||
V_2 -> V_179 [ 1 ] != V_180 ) {
if ( ! ( F_40 ( V_2 , V_110 ) & V_181 ) )
F_13 ( V_2 , V_110 ,
( V_25 ) V_2 -> V_111 . V_3 | V_181 ) ;
}
F_75 ( V_13 , V_99 ,
F_79 ( V_13 , V_99 ) | V_100 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_49 = ( V_3 << 28 ) | ( V_182 << 20 ) |
( V_183 << 8 ) | V_184 ;
unsigned int V_51 ;
F_82 ( & V_2 -> V_53 -> V_185 ) ;
V_2 -> V_72 = 1 ;
F_47 ( V_2 -> V_53 , V_49 ) ;
V_51 = F_48 ( V_2 -> V_53 , V_3 ) ;
V_2 -> V_72 = 0 ;
F_83 ( & V_2 -> V_53 -> V_185 ) ;
if ( V_51 == - 1 )
return - V_83 ;
F_36 ( V_68 L_24 , V_3 ) ;
return 0 ;
}
static void F_84 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
V_53 -> V_75 = 1 ;
F_85 ( V_2 ) ;
F_58 ( V_2 , 1 ) ;
#ifdef F_86
if ( V_2 -> V_109 ) {
int V_97 ;
for ( V_97 = 0 ; V_97 < V_186 ; V_97 ++ )
F_87 ( V_2 -> V_187 [ V_97 ] ) ;
F_88 ( V_2 -> V_53 ) ;
F_89 ( V_2 -> V_53 ) ;
}
#endif
V_53 -> V_75 = 0 ;
}
static int T_5 F_90 ( struct V_1 * V_2 , const char * V_188 )
{
struct V_189 V_190 ;
int V_191 , V_192 , V_19 ;
int V_193 ;
memset ( & V_190 , 0 , sizeof( V_190 ) ) ;
V_190 . V_55 = V_2 ;
V_190 . V_194 = V_188 ;
V_190 . V_21 = V_2 -> V_21 ;
V_190 . V_195 . V_196 = F_47 ;
V_190 . V_195 . V_197 = F_48 ;
V_190 . V_195 . V_198 = V_199 ;
V_190 . V_195 . V_200 = F_84 ;
#ifdef F_91
V_190 . V_201 = & V_201 ;
V_190 . V_195 . V_202 = V_203 ;
#endif
V_19 = F_92 ( V_2 -> V_204 , & V_190 , & V_2 -> V_53 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_2 -> V_43 & V_205 ) {
F_44 ( V_68 L_25 ) ;
V_2 -> V_53 -> V_67 = 1 ;
}
V_192 = 0 ;
V_193 = V_206 [ V_2 -> V_118 ] ;
if ( ! V_193 )
V_193 = V_207 ;
for ( V_191 = 0 ; V_191 < V_193 ; V_191 ++ ) {
if ( ( V_2 -> V_93 & ( 1 << V_191 ) ) & V_2 -> V_208 ) {
if ( F_81 ( V_2 , V_191 ) < 0 ) {
F_10 (KERN_WARNING SFX
L_26
L_27 , c) ;
V_2 -> V_93 &= ~ ( 1 << V_191 ) ;
F_85 ( V_2 ) ;
F_58 ( V_2 , 1 ) ;
}
}
}
if ( V_2 -> V_43 & V_209 ) {
F_44 ( V_68 L_28 ) ;
V_2 -> V_53 -> V_210 = 1 ;
V_2 -> V_53 -> V_73 = 1 ;
}
for ( V_191 = 0 ; V_191 < V_193 ; V_191 ++ ) {
if ( ( V_2 -> V_93 & ( 1 << V_191 ) ) & V_2 -> V_208 ) {
struct V_211 * V_212 ;
V_19 = F_93 ( V_2 -> V_53 , V_191 , & V_212 ) ;
if ( V_19 < 0 )
continue;
V_212 -> V_213 = V_2 -> V_213 ;
V_192 ++ ;
}
}
if ( ! V_192 ) {
F_10 (KERN_ERR SFX L_29 ) ;
return - V_214 ;
}
return 0 ;
}
static int T_5 F_94 ( struct V_1 * V_2 )
{
struct V_211 * V_212 ;
F_95 (codec, &chip->bus->codec_list, list) {
F_96 ( V_212 ) ;
}
return 0 ;
}
static inline struct V_13 *
F_97 ( struct V_1 * V_2 , struct V_150 * V_141 )
{
int V_215 , V_97 , V_216 ;
struct V_13 * V_51 = NULL ;
int V_217 = ( V_141 -> V_187 -> V_218 << 16 ) | ( V_141 -> V_219 << 2 ) |
( V_141 -> V_220 + 1 ) ;
if ( V_141 -> V_220 == V_221 ) {
V_215 = V_2 -> V_222 ;
V_216 = V_2 -> V_223 ;
} else {
V_215 = V_2 -> V_224 ;
V_216 = V_2 -> V_225 ;
}
for ( V_97 = 0 ; V_97 < V_216 ; V_97 ++ , V_215 ++ )
if ( ! V_2 -> V_13 [ V_215 ] . V_226 ) {
V_51 = & V_2 -> V_13 [ V_215 ] ;
if ( V_51 -> V_227 == V_217 )
break;
}
if ( V_51 ) {
V_51 -> V_226 = 1 ;
V_51 -> V_227 = V_217 ;
}
return V_51 ;
}
static inline void F_98 ( struct V_13 * V_13 )
{
V_13 -> V_226 = 0 ;
}
static int F_99 ( struct V_150 * V_141 )
{
struct V_228 * V_229 = F_100 ( V_141 ) ;
struct V_230 * V_231 = V_229 -> V_231 [ V_141 -> V_220 ] ;
struct V_1 * V_2 = V_229 -> V_2 ;
struct V_13 * V_13 ;
struct V_14 * V_15 = V_141 -> V_15 ;
unsigned long V_232 ;
int V_19 ;
int V_233 ;
F_82 ( & V_2 -> V_234 ) ;
V_13 = F_97 ( V_2 , V_141 ) ;
if ( V_13 == NULL ) {
F_83 ( & V_2 -> V_234 ) ;
return - V_92 ;
}
V_15 -> V_235 = V_236 ;
V_15 -> V_235 . V_237 = V_231 -> V_237 ;
V_15 -> V_235 . V_238 = V_231 -> V_238 ;
V_15 -> V_235 . V_239 = V_231 -> V_239 ;
V_15 -> V_235 . V_240 = V_231 -> V_240 ;
F_101 ( V_15 ) ;
F_102 ( V_15 , V_241 ) ;
if ( V_242 )
V_233 = 128 ;
else
V_233 = 4 ;
F_103 ( V_15 , 0 , V_243 ,
V_233 ) ;
F_103 ( V_15 , 0 , V_244 ,
V_233 ) ;
F_104 ( V_229 -> V_212 ) ;
V_19 = V_231 -> V_195 . V_245 ( V_231 , V_229 -> V_212 , V_141 ) ;
if ( V_19 < 0 ) {
F_98 ( V_13 ) ;
F_105 ( V_229 -> V_212 ) ;
F_83 ( & V_2 -> V_234 ) ;
return V_19 ;
}
F_101 ( V_15 ) ;
if ( F_106 ( ! V_15 -> V_235 . V_237 ) ||
F_106 ( ! V_15 -> V_235 . V_238 ) ||
F_106 ( ! V_15 -> V_235 . V_239 ) ||
F_106 ( ! V_15 -> V_235 . V_240 ) ) {
F_98 ( V_13 ) ;
V_231 -> V_195 . V_246 ( V_231 , V_229 -> V_212 , V_141 ) ;
F_105 ( V_229 -> V_212 ) ;
F_83 ( & V_2 -> V_234 ) ;
return - V_158 ;
}
F_107 ( & V_2 -> V_23 , V_232 ) ;
V_13 -> V_141 = V_141 ;
V_13 -> V_142 = 0 ;
F_108 ( & V_2 -> V_23 , V_232 ) ;
V_15 -> V_55 = V_13 ;
F_109 ( V_141 ) ;
F_83 ( & V_2 -> V_234 ) ;
return 0 ;
}
static int F_110 ( struct V_150 * V_141 )
{
struct V_228 * V_229 = F_100 ( V_141 ) ;
struct V_230 * V_231 = V_229 -> V_231 [ V_141 -> V_220 ] ;
struct V_1 * V_2 = V_229 -> V_2 ;
struct V_13 * V_13 = F_111 ( V_141 ) ;
unsigned long V_232 ;
F_82 ( & V_2 -> V_234 ) ;
F_107 ( & V_2 -> V_23 , V_232 ) ;
V_13 -> V_141 = NULL ;
V_13 -> V_142 = 0 ;
F_108 ( & V_2 -> V_23 , V_232 ) ;
F_98 ( V_13 ) ;
V_231 -> V_195 . V_246 ( V_231 , V_229 -> V_212 , V_141 ) ;
F_105 ( V_229 -> V_212 ) ;
F_83 ( & V_2 -> V_234 ) ;
return 0 ;
}
static int F_112 ( struct V_150 * V_141 ,
struct V_247 * V_248 )
{
struct V_228 * V_229 = F_100 ( V_141 ) ;
struct V_1 * V_2 = V_229 -> V_2 ;
struct V_14 * V_15 = V_141 -> V_15 ;
struct V_13 * V_13 = F_111 ( V_141 ) ;
int V_249 ;
F_6 ( V_2 , V_13 , V_15 , false ) ;
V_13 -> V_164 = 0 ;
V_13 -> V_160 = 0 ;
V_13 -> V_177 = 0 ;
V_249 = F_113 ( V_141 ,
F_114 ( V_248 ) ) ;
if ( V_249 < 0 )
return V_249 ;
F_6 ( V_2 , V_13 , V_15 , true ) ;
return V_249 ;
}
static int F_115 ( struct V_150 * V_141 )
{
struct V_228 * V_229 = F_100 ( V_141 ) ;
struct V_13 * V_13 = F_111 ( V_141 ) ;
struct V_1 * V_2 = V_229 -> V_2 ;
struct V_14 * V_15 = V_141 -> V_15 ;
struct V_230 * V_231 = V_229 -> V_231 [ V_141 -> V_220 ] ;
F_75 ( V_13 , V_162 , 0 ) ;
F_75 ( V_13 , V_163 , 0 ) ;
F_75 ( V_13 , V_99 , 0 ) ;
V_13 -> V_164 = 0 ;
V_13 -> V_160 = 0 ;
V_13 -> V_177 = 0 ;
F_116 ( V_229 -> V_212 , V_231 , V_141 ) ;
F_6 ( V_2 , V_13 , V_15 , false ) ;
return F_117 ( V_141 ) ;
}
static int F_118 ( struct V_150 * V_141 )
{
struct V_228 * V_229 = F_100 ( V_141 ) ;
struct V_1 * V_2 = V_229 -> V_2 ;
struct V_13 * V_13 = F_111 ( V_141 ) ;
struct V_230 * V_231 = V_229 -> V_231 [ V_141 -> V_220 ] ;
struct V_14 * V_15 = V_141 -> V_15 ;
unsigned int V_164 , V_160 , V_177 , V_172 ;
int V_19 ;
struct V_250 * V_251 =
F_119 ( V_229 -> V_212 , V_231 -> V_252 ) ;
unsigned short V_253 = V_251 ? V_251 -> V_253 : 0 ;
F_77 ( V_2 , V_13 ) ;
V_177 = F_120 ( V_15 -> V_168 ,
V_15 -> V_254 ,
V_15 -> V_255 ,
V_231 -> V_256 ,
V_253 ) ;
if ( ! V_177 ) {
F_10 (KERN_ERR SFX
L_30 ,
runtime->rate, runtime->channels, runtime->format) ;
return - V_158 ;
}
V_164 = F_121 ( V_141 ) ;
V_160 = F_122 ( V_141 ) ;
F_36 ( V_68 L_31 ,
V_164 , V_177 ) ;
if ( V_164 != V_13 -> V_164 ||
V_160 != V_13 -> V_160 ||
V_177 != V_13 -> V_177 ) {
V_13 -> V_164 = V_164 ;
V_13 -> V_160 = V_160 ;
V_13 -> V_177 = V_177 ;
V_19 = F_74 ( V_2 , V_141 , V_13 ) ;
if ( V_19 < 0 )
return V_19 ;
}
V_13 -> V_257 = ( ( ( V_15 -> V_258 * 24000 ) /
V_15 -> V_168 ) * 1000 ) ;
F_78 ( V_2 , V_13 ) ;
if ( V_141 -> V_220 == V_221 )
V_13 -> V_259 = F_123 ( V_13 , V_260 ) + 1 ;
else
V_13 -> V_259 = 0 ;
V_172 = V_13 -> V_172 ;
if ( ( V_2 -> V_43 & V_44 ) &&
V_172 > V_2 -> V_225 )
V_172 -= V_2 -> V_225 ;
return F_124 ( V_229 -> V_212 , V_231 , V_172 ,
V_13 -> V_177 , V_141 ) ;
}
static int F_125 ( struct V_150 * V_141 , int V_49 )
{
struct V_228 * V_229 = F_100 ( V_141 ) ;
struct V_1 * V_2 = V_229 -> V_2 ;
struct V_13 * V_13 ;
struct V_150 * V_261 ;
int V_262 = 0 , V_263 , V_264 = 0 , V_265 = 0 ;
int V_266 , V_60 ;
switch ( V_49 ) {
case V_267 :
V_262 = 1 ;
case V_268 :
case V_269 :
V_263 = 1 ;
break;
case V_270 :
case V_271 :
case V_272 :
V_263 = 0 ;
break;
default:
return - V_158 ;
}
F_126 (s, substream) {
if ( V_261 -> V_187 -> V_204 != V_141 -> V_187 -> V_204 )
continue;
V_13 = F_111 ( V_261 ) ;
V_265 |= 1 << V_13 -> V_107 ;
V_264 ++ ;
F_127 ( V_261 , V_141 ) ;
}
F_66 ( & V_2 -> V_23 ) ;
if ( V_264 > 1 ) {
if ( V_2 -> V_43 & V_273 )
F_13 ( V_2 , V_274 ,
F_40 ( V_2 , V_274 ) | V_265 ) ;
else
F_13 ( V_2 , V_275 , F_40 ( V_2 , V_275 ) | V_265 ) ;
}
F_126 (s, substream) {
if ( V_261 -> V_187 -> V_204 != V_141 -> V_187 -> V_204 )
continue;
V_13 = F_111 ( V_261 ) ;
if ( V_263 ) {
V_13 -> V_276 = F_40 ( V_2 , V_277 ) ;
if ( ! V_262 )
V_13 -> V_276 -=
V_13 -> V_257 ;
F_55 ( V_2 , V_13 ) ;
} else {
F_57 ( V_2 , V_13 ) ;
}
V_13 -> V_142 = V_263 ;
}
F_67 ( & V_2 -> V_23 ) ;
if ( V_263 ) {
if ( V_264 == 1 )
return 0 ;
for ( V_60 = 5000 ; V_60 ; V_60 -- ) {
V_266 = 0 ;
F_126 (s, substream) {
if ( V_261 -> V_187 -> V_204 != V_141 -> V_187 -> V_204 )
continue;
V_13 = F_111 ( V_261 ) ;
if ( ! ( F_53 ( V_13 , V_101 ) &
V_278 ) )
V_266 ++ ;
}
if ( ! V_266 )
break;
F_128 () ;
}
} else {
for ( V_60 = 5000 ; V_60 ; V_60 -- ) {
V_266 = 0 ;
F_126 (s, substream) {
if ( V_261 -> V_187 -> V_204 != V_141 -> V_187 -> V_204 )
continue;
V_13 = F_111 ( V_261 ) ;
if ( F_53 ( V_13 , V_99 ) &
V_108 )
V_266 ++ ;
}
if ( ! V_266 )
break;
F_128 () ;
}
}
if ( V_264 > 1 ) {
F_66 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_43 & V_273 )
F_13 ( V_2 , V_274 ,
F_40 ( V_2 , V_274 ) & ~ V_265 ) ;
else
F_13 ( V_2 , V_275 , F_40 ( V_2 , V_275 ) & ~ V_265 ) ;
F_67 ( & V_2 -> V_23 ) ;
}
return 0 ;
}
static unsigned int F_129 ( struct V_1 * V_2 ,
struct V_13 * V_13 )
{
unsigned int V_279 , V_280 , V_281 ;
unsigned int V_282 , V_283 , V_284 ;
unsigned int V_259 ;
V_279 = F_79 ( V_13 , V_285 ) ;
if ( V_13 -> V_141 -> V_220 == V_221 ) {
return V_279 ;
}
V_283 = F_26 ( * V_13 -> V_111 ) ;
V_283 %= V_13 -> V_160 ;
V_259 = F_130 ( V_2 -> V_286 + V_287 ) ;
if ( V_13 -> V_106 ) {
if ( V_279 <= V_259 )
return 0 ;
V_13 -> V_106 = 0 ;
}
if ( V_279 <= V_259 )
V_280 = V_13 -> V_164 + V_279 - V_259 ;
else
V_280 = V_279 - V_259 ;
V_284 = V_280 % V_13 -> V_160 ;
V_282 = V_279 % V_13 -> V_160 ;
if ( V_282 >= V_259 )
V_281 = V_279 - V_282 ;
else if ( V_283 >= V_284 )
V_281 = V_280 - V_284 ;
else {
V_281 = V_280 - V_284 + V_13 -> V_160 ;
if ( V_281 >= V_13 -> V_164 )
V_281 = 0 ;
}
return V_281 + V_283 ;
}
static unsigned int F_131 ( struct V_1 * V_2 ,
struct V_13 * V_13 ,
bool V_288 )
{
unsigned int V_289 ;
int V_220 = V_13 -> V_141 -> V_220 ;
switch ( V_2 -> V_179 [ V_220 ] ) {
case V_180 :
V_289 = F_79 ( V_13 , V_285 ) ;
break;
case V_290 :
V_289 = F_129 ( V_2 , V_13 ) ;
break;
default:
V_289 = F_26 ( * V_13 -> V_111 ) ;
if ( V_288 && V_2 -> V_179 [ V_220 ] == V_291 ) {
if ( ! V_289 || V_289 == ( V_25 ) - 1 ) {
F_132 ( V_292
L_32
L_33 ) ;
V_2 -> V_179 [ V_220 ] = V_180 ;
V_289 = F_79 ( V_13 , V_285 ) ;
} else
V_2 -> V_179 [ V_220 ] = V_293 ;
}
break;
}
if ( V_289 >= V_13 -> V_164 )
V_289 = 0 ;
return V_289 ;
}
static T_6 F_133 ( struct V_150 * V_141 )
{
struct V_228 * V_229 = F_100 ( V_141 ) ;
struct V_1 * V_2 = V_229 -> V_2 ;
struct V_13 * V_13 = F_111 ( V_141 ) ;
return F_134 ( V_141 -> V_15 ,
F_131 ( V_2 , V_13 , false ) ) ;
}
static int F_68 ( struct V_1 * V_2 , struct V_13 * V_13 )
{
V_25 V_294 ;
unsigned int V_289 ;
int V_220 ;
V_294 = F_40 ( V_2 , V_277 ) - V_13 -> V_276 ;
if ( V_294 < ( V_13 -> V_257 * 2 ) / 3 )
return - 1 ;
V_220 = V_13 -> V_141 -> V_220 ;
V_289 = F_131 ( V_2 , V_13 , true ) ;
if ( F_135 ( ! V_13 -> V_160 ,
L_34 ) )
return - 1 ;
if ( V_294 < ( V_13 -> V_257 * 5 ) / 4 &&
V_289 % V_13 -> V_160 > V_13 -> V_160 / 2 )
return V_165 [ V_2 -> V_166 ] ? 0 : - 1 ;
V_13 -> V_276 += V_294 ;
return 1 ;
}
static void F_136 ( struct V_295 * V_296 )
{
struct V_1 * V_2 = F_137 ( V_296 , struct V_1 , V_146 ) ;
int V_97 , V_297 , V_138 ;
if ( ! V_2 -> V_298 ) {
F_132 ( V_292
L_35
L_36 ,
V_2 -> V_204 -> V_219 ) ;
V_2 -> V_298 = 1 ;
}
for (; ; ) {
V_297 = 0 ;
F_12 ( & V_2 -> V_23 ) ;
for ( V_97 = 0 ; V_97 < V_2 -> V_98 ; V_97 ++ ) {
struct V_13 * V_13 = & V_2 -> V_13 [ V_97 ] ;
if ( ! V_13 -> V_144 ||
! V_13 -> V_141 ||
! V_13 -> V_142 )
continue;
V_138 = F_68 ( V_2 , V_13 ) ;
if ( V_138 > 0 ) {
V_13 -> V_144 = 0 ;
F_67 ( & V_2 -> V_23 ) ;
F_69 ( V_13 -> V_141 ) ;
F_66 ( & V_2 -> V_23 ) ;
} else if ( V_138 < 0 ) {
V_297 = 0 ;
} else
V_297 ++ ;
}
F_17 ( & V_2 -> V_23 ) ;
if ( ! V_297 )
return;
F_33 ( 1 ) ;
}
}
static void F_138 ( struct V_1 * V_2 )
{
int V_97 ;
F_12 ( & V_2 -> V_23 ) ;
for ( V_97 = 0 ; V_97 < V_2 -> V_98 ; V_97 ++ )
V_2 -> V_13 [ V_97 ] . V_144 = 0 ;
F_17 ( & V_2 -> V_23 ) ;
}
static int F_139 ( struct V_150 * V_141 ,
struct V_299 * V_11 )
{
struct V_228 * V_229 = F_100 ( V_141 ) ;
struct V_1 * V_2 = V_229 -> V_2 ;
if ( ! F_2 ( V_2 ) )
V_11 -> V_300 = F_140 ( V_11 -> V_300 ) ;
return F_141 ( V_141 , V_11 ) ;
}
static void F_142 ( struct V_301 * V_187 )
{
struct V_228 * V_229 = V_187 -> V_55 ;
if ( V_229 ) {
V_229 -> V_2 -> V_187 [ V_187 -> V_218 ] = NULL ;
F_143 ( V_229 ) ;
}
}
static int
V_199 ( struct V_52 * V_53 , struct V_211 * V_212 ,
struct V_302 * V_303 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_301 * V_187 ;
struct V_228 * V_229 ;
int V_304 = V_303 -> V_218 ;
unsigned int V_4 ;
int V_261 , V_19 ;
if ( V_304 >= V_186 ) {
F_10 (KERN_ERR SFX L_37 ,
pcm_dev) ;
return - V_158 ;
}
if ( V_2 -> V_187 [ V_304 ] ) {
F_10 (KERN_ERR SFX L_38 , pcm_dev) ;
return - V_92 ;
}
V_19 = F_144 ( V_2 -> V_204 , V_303 -> V_305 , V_304 ,
V_303 -> V_220 [ V_221 ] . V_306 ,
V_303 -> V_220 [ V_307 ] . V_306 ,
& V_187 ) ;
if ( V_19 < 0 )
return V_19 ;
F_145 ( V_187 -> V_305 , V_303 -> V_305 , sizeof( V_187 -> V_305 ) ) ;
V_229 = F_146 ( sizeof( * V_229 ) , V_308 ) ;
if ( V_229 == NULL )
return - V_309 ;
V_229 -> V_2 = V_2 ;
V_229 -> V_212 = V_212 ;
V_187 -> V_55 = V_229 ;
V_187 -> V_310 = F_142 ;
if ( V_303 -> V_311 == V_312 )
V_187 -> V_313 = V_314 ;
V_2 -> V_187 [ V_304 ] = V_187 ;
V_303 -> V_187 = V_187 ;
for ( V_261 = 0 ; V_261 < 2 ; V_261 ++ ) {
V_229 -> V_231 [ V_261 ] = & V_303 -> V_220 [ V_261 ] ;
if ( V_303 -> V_220 [ V_261 ] . V_306 )
F_147 ( V_187 , V_261 , & V_315 ) ;
}
V_4 = V_316 * 1024 ;
if ( V_4 > V_317 )
V_4 = V_317 ;
F_148 ( V_187 , V_318 ,
F_9 ( V_2 -> V_21 ) ,
V_4 , V_317 ) ;
return 0 ;
}
static int T_5 F_149 ( struct V_1 * V_2 )
{
return F_150 ( V_2 -> V_53 ) ;
}
static int T_5 F_151 ( struct V_1 * V_2 )
{
int V_97 ;
for ( V_97 = 0 ; V_97 < V_2 -> V_98 ; V_97 ++ ) {
struct V_13 * V_13 = & V_2 -> V_13 [ V_97 ] ;
V_13 -> V_111 = ( V_25 V_319 * ) ( V_2 -> V_111 . V_11 + V_97 * 8 ) ;
V_13 -> V_320 = V_2 -> V_286 + ( 0x20 * V_97 + 0x80 ) ;
V_13 -> V_140 = 1 << V_97 ;
V_13 -> V_107 = V_97 ;
V_13 -> V_172 = V_97 + 1 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , int V_321 )
{
if ( F_152 ( V_2 -> V_21 -> V_71 , F_65 ,
V_2 -> V_70 ? 0 : V_322 ,
V_323 , V_2 ) ) {
F_132 ( V_76 L_39
L_40 , V_2 -> V_21 -> V_71 ) ;
if ( V_321 )
F_153 ( V_2 -> V_204 ) ;
return - 1 ;
}
V_2 -> V_71 = V_2 -> V_21 -> V_71 ;
F_154 ( V_2 -> V_21 , ! V_2 -> V_70 ) ;
return 0 ;
}
static void F_85 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_109 )
return;
F_51 ( V_2 ) ;
F_54 ( V_2 ) ;
F_18 ( V_2 ) ;
F_13 ( V_2 , V_110 , 0 ) ;
F_13 ( V_2 , V_112 , 0 ) ;
V_2 -> V_109 = 0 ;
}
static void V_203 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_211 * V_191 ;
int V_324 = 0 ;
F_95 (c, &bus->codec_list, list) {
if ( V_191 -> V_324 ) {
V_324 = 1 ;
break;
}
}
if ( V_324 )
F_58 ( V_2 , 1 ) ;
else if ( V_2 -> V_142 && V_325 &&
! V_53 -> V_326 )
F_85 ( V_2 ) ;
}
static int F_155 ( struct V_52 * V_53 )
{
struct V_211 * V_212 ;
F_95 (codec, &bus->codec_list, list) {
if ( F_156 ( V_212 ) )
return 1 ;
}
return 0 ;
}
static int F_157 ( struct V_113 * V_21 , T_7 V_327 )
{
struct V_328 * V_204 = F_158 ( V_21 ) ;
struct V_1 * V_2 = V_204 -> V_55 ;
int V_97 ;
F_159 ( V_204 , V_329 ) ;
F_138 ( V_2 ) ;
for ( V_97 = 0 ; V_97 < V_186 ; V_97 ++ )
F_87 ( V_2 -> V_187 [ V_97 ] ) ;
if ( V_2 -> V_109 )
F_88 ( V_2 -> V_53 ) ;
F_85 ( V_2 ) ;
if ( V_2 -> V_71 >= 0 ) {
F_37 ( V_2 -> V_71 , V_2 ) ;
V_2 -> V_71 = - 1 ;
}
if ( V_2 -> V_70 )
F_38 ( V_2 -> V_21 ) ;
F_160 ( V_21 ) ;
F_161 ( V_21 ) ;
F_162 ( V_21 , F_163 ( V_21 , V_327 ) ) ;
return 0 ;
}
static int F_164 ( struct V_113 * V_21 )
{
struct V_328 * V_204 = F_158 ( V_21 ) ;
struct V_1 * V_2 = V_204 -> V_55 ;
F_162 ( V_21 , V_330 ) ;
F_165 ( V_21 ) ;
if ( F_166 ( V_21 ) < 0 ) {
F_132 ( V_76 L_41
L_40 ) ;
F_153 ( V_204 ) ;
return - V_83 ;
}
F_167 ( V_21 ) ;
if ( V_2 -> V_70 )
if ( F_168 ( V_21 ) < 0 )
V_2 -> V_70 = 0 ;
if ( F_39 ( V_2 , 1 ) < 0 )
return - V_83 ;
F_62 ( V_2 ) ;
if ( F_155 ( V_2 -> V_53 ) )
F_58 ( V_2 , 1 ) ;
F_89 ( V_2 -> V_53 ) ;
F_159 ( V_204 , V_331 ) ;
return 0 ;
}
static int F_169 ( struct V_332 * V_333 , unsigned long V_334 , void * V_10 )
{
struct V_1 * V_2 = F_137 ( V_333 , struct V_1 , V_335 ) ;
F_170 ( V_2 -> V_53 ) ;
F_85 ( V_2 ) ;
return V_336 ;
}
static void F_171 ( struct V_1 * V_2 )
{
V_2 -> V_335 . V_337 = F_169 ;
F_172 ( & V_2 -> V_335 ) ;
}
static void F_173 ( struct V_1 * V_2 )
{
if ( V_2 -> V_335 . V_337 )
F_174 ( & V_2 -> V_335 ) ;
}
static int F_175 ( struct V_1 * V_2 )
{
int V_97 ;
F_173 ( V_2 ) ;
if ( V_2 -> V_109 ) {
F_138 ( V_2 ) ;
for ( V_97 = 0 ; V_97 < V_2 -> V_98 ; V_97 ++ )
F_57 ( V_2 , & V_2 -> V_13 [ V_97 ] ) ;
F_85 ( V_2 ) ;
}
if ( V_2 -> V_71 >= 0 )
F_37 ( V_2 -> V_71 , ( void * ) V_2 ) ;
if ( V_2 -> V_70 )
F_38 ( V_2 -> V_21 ) ;
if ( V_2 -> V_286 )
F_176 ( V_2 -> V_286 ) ;
if ( V_2 -> V_13 ) {
for ( V_97 = 0 ; V_97 < V_2 -> V_98 ; V_97 ++ )
if ( V_2 -> V_13 [ V_97 ] . V_154 . V_11 ) {
F_5 ( V_2 , & V_2 -> V_13 [ V_97 ] . V_154 , false ) ;
F_177 ( & V_2 -> V_13 [ V_97 ] . V_154 ) ;
}
}
if ( V_2 -> V_22 . V_11 ) {
F_5 ( V_2 , & V_2 -> V_22 , false ) ;
F_177 ( & V_2 -> V_22 ) ;
}
if ( V_2 -> V_111 . V_11 ) {
F_5 ( V_2 , & V_2 -> V_111 , false ) ;
F_177 ( & V_2 -> V_111 ) ;
}
F_178 ( V_2 -> V_21 ) ;
F_160 ( V_2 -> V_21 ) ;
F_143 ( V_2 -> V_13 ) ;
F_143 ( V_2 ) ;
return 0 ;
}
static int F_179 ( struct V_338 * V_218 )
{
return F_175 ( V_218 -> V_339 ) ;
}
static int T_5 F_180 ( struct V_1 * V_2 , int V_340 )
{
const struct V_341 * V_342 ;
switch ( V_340 ) {
case V_180 :
case V_293 :
case V_290 :
return V_340 ;
}
V_342 = F_181 ( V_2 -> V_21 , V_343 ) ;
if ( V_342 ) {
F_132 ( V_344
L_42
L_43 ,
V_342 -> V_345 , V_342 -> V_346 , V_342 -> V_347 ) ;
return V_342 -> V_345 ;
}
if ( V_2 -> V_43 & V_348 ) {
F_44 ( V_68 L_44 ) ;
return V_290 ;
}
if ( V_2 -> V_43 & V_349 ) {
F_44 ( V_68 L_45 ) ;
return V_180 ;
}
return V_291 ;
}
static void T_5 F_182 ( struct V_1 * V_2 , int V_215 )
{
const struct V_341 * V_342 ;
V_2 -> V_208 = V_350 [ V_215 ] ;
if ( V_2 -> V_208 == - 1 ) {
V_342 = F_181 ( V_2 -> V_21 , V_351 ) ;
if ( V_342 ) {
F_132 ( V_344
L_46
L_43 ,
V_342 -> V_345 , V_342 -> V_346 , V_342 -> V_347 ) ;
V_2 -> V_208 = V_342 -> V_345 ;
}
}
if ( V_2 -> V_208 != - 1 &&
( V_2 -> V_208 & V_352 ) ) {
V_2 -> V_93 = V_2 -> V_208 & 0xff ;
F_132 ( V_344 L_47 ,
V_2 -> V_93 ) ;
}
}
static void T_5 F_183 ( struct V_1 * V_2 )
{
const struct V_341 * V_342 ;
if ( V_353 >= 0 ) {
V_2 -> V_70 = ! ! V_353 ;
return;
}
V_2 -> V_70 = 1 ;
V_342 = F_181 ( V_2 -> V_21 , V_354 ) ;
if ( V_342 ) {
F_132 ( V_344
L_48 ,
V_342 -> V_346 , V_342 -> V_347 , V_342 -> V_345 ) ;
V_2 -> V_70 = V_342 -> V_345 ;
return;
}
if ( V_2 -> V_43 & V_355 ) {
F_132 ( V_344 L_49 ) ;
V_2 -> V_70 = 0 ;
}
}
static int T_5 F_184 ( struct V_328 * V_204 , struct V_113 * V_21 ,
int V_215 , unsigned int V_43 ,
struct V_1 * * V_356 )
{
struct V_1 * V_2 ;
int V_97 , V_19 ;
unsigned short V_357 ;
static struct V_358 V_195 = {
. V_359 = F_179 ,
} ;
* V_356 = NULL ;
V_19 = F_166 ( V_21 ) ;
if ( V_19 < 0 )
return V_19 ;
V_2 = F_146 ( sizeof( * V_2 ) , V_308 ) ;
if ( ! V_2 ) {
F_10 (KERN_ERR SFX L_50 ) ;
F_160 ( V_21 ) ;
return - V_309 ;
}
F_185 ( & V_2 -> V_23 ) ;
F_186 ( & V_2 -> V_234 ) ;
V_2 -> V_204 = V_204 ;
V_2 -> V_21 = V_21 ;
V_2 -> V_71 = - 1 ;
V_2 -> V_43 = V_43 ;
V_2 -> V_118 = V_43 & 0xff ;
F_183 ( V_2 ) ;
V_2 -> V_166 = V_215 ;
F_187 ( & V_2 -> V_146 , F_136 ) ;
V_2 -> V_179 [ 0 ] = V_2 -> V_179 [ 1 ] =
F_180 ( V_2 , V_179 [ V_215 ] ) ;
F_182 ( V_2 , V_215 ) ;
V_2 -> V_77 = V_77 ;
V_2 -> V_117 = V_360 ;
if ( V_165 [ V_215 ] < 0 ) {
switch ( V_2 -> V_118 ) {
case V_361 :
case V_362 :
V_165 [ V_215 ] = 1 ;
break;
default:
V_165 [ V_215 ] = 32 ;
break;
}
}
#if V_363 != 64
if ( V_2 -> V_118 == V_364 ) {
T_8 V_365 ;
F_63 ( V_21 , 0x40 , & V_365 ) ;
F_64 ( V_21 , 0x40 , V_365 | 0x10 ) ;
F_188 ( V_21 , V_366 , 0 ) ;
}
#endif
V_19 = F_189 ( V_21 , L_51 ) ;
if ( V_19 < 0 ) {
F_143 ( V_2 ) ;
F_160 ( V_21 ) ;
return V_19 ;
}
V_2 -> V_3 = F_190 ( V_21 , 0 ) ;
V_2 -> V_286 = F_191 ( V_21 , 0 ) ;
if ( V_2 -> V_286 == NULL ) {
F_10 (KERN_ERR SFX L_52 ) ;
V_19 = - V_214 ;
goto V_367;
}
if ( V_2 -> V_70 )
if ( F_168 ( V_21 ) < 0 )
V_2 -> V_70 = 0 ;
if ( F_39 ( V_2 , 0 ) < 0 ) {
V_19 = - V_92 ;
goto V_367;
}
F_167 ( V_21 ) ;
F_192 ( V_2 -> V_71 ) ;
V_357 = F_42 ( V_2 , V_368 ) ;
F_36 ( V_68 L_53 , V_357 ) ;
if ( V_2 -> V_21 -> V_369 == V_370 ) {
struct V_113 * V_371 ;
V_371 = F_193 ( V_370 ,
V_372 ,
NULL ) ;
if ( V_371 ) {
if ( V_371 -> V_120 < 0x30 )
V_357 &= ~ V_373 ;
F_194 ( V_371 ) ;
}
}
if ( V_2 -> V_43 & V_374 ) {
F_44 ( V_68 L_54 ) ;
V_357 &= ~ V_373 ;
}
if ( V_2 -> V_43 & V_375 )
V_242 = 0 ;
if ( ( V_357 & V_373 ) && ! F_195 ( V_21 , F_196 ( 64 ) ) )
F_197 ( V_21 , F_196 ( 64 ) ) ;
else {
F_195 ( V_21 , F_196 ( 32 ) ) ;
F_197 ( V_21 , F_196 ( 32 ) ) ;
}
V_2 -> V_225 = ( V_357 >> 8 ) & 0x0f ;
V_2 -> V_223 = ( V_357 >> 12 ) & 0x0f ;
if ( ! V_2 -> V_223 && ! V_2 -> V_225 ) {
switch ( V_2 -> V_118 ) {
case V_364 :
V_2 -> V_223 = V_376 ;
V_2 -> V_225 = V_377 ;
break;
case V_378 :
V_2 -> V_223 = V_379 ;
V_2 -> V_225 = V_380 ;
break;
case V_381 :
default:
V_2 -> V_223 = V_382 ;
V_2 -> V_225 = V_383 ;
break;
}
}
V_2 -> V_224 = 0 ;
V_2 -> V_222 = V_2 -> V_225 ;
V_2 -> V_98 = V_2 -> V_223 + V_2 -> V_225 ;
V_2 -> V_13 = F_198 ( V_2 -> V_98 , sizeof( * V_2 -> V_13 ) ,
V_308 ) ;
if ( ! V_2 -> V_13 ) {
F_10 (KERN_ERR SFX L_55 ) ;
goto V_367;
}
for ( V_97 = 0 ; V_97 < V_2 -> V_98 ; V_97 ++ ) {
V_19 = F_8 ( V_20 ,
F_9 ( V_2 -> V_21 ) ,
V_384 , & V_2 -> V_13 [ V_97 ] . V_154 ) ;
if ( V_19 < 0 ) {
F_10 (KERN_ERR SFX L_56 ) ;
goto V_367;
}
F_5 ( V_2 , & V_2 -> V_13 [ V_97 ] . V_154 , true ) ;
}
V_19 = F_8 ( V_20 ,
F_9 ( V_2 -> V_21 ) ,
V_2 -> V_98 * 8 , & V_2 -> V_111 ) ;
if ( V_19 < 0 ) {
F_10 (KERN_ERR SFX L_57 ) ;
goto V_367;
}
F_5 ( V_2 , & V_2 -> V_111 , true ) ;
V_19 = F_7 ( V_2 ) ;
if ( V_19 < 0 )
goto V_367;
F_151 ( V_2 ) ;
F_62 ( V_2 ) ;
F_58 ( V_2 , ( V_385 [ V_215 ] & 2 ) == 0 ) ;
if ( ! V_2 -> V_93 ) {
F_10 (KERN_ERR SFX L_58 ) ;
V_19 = - V_386 ;
goto V_367;
}
V_19 = F_199 ( V_204 , V_387 , V_2 , & V_195 ) ;
if ( V_19 < 0 ) {
F_10 (KERN_ERR SFX L_59 ) ;
goto V_367;
}
strcpy ( V_204 -> V_388 , L_60 ) ;
F_145 ( V_204 -> V_389 , V_390 [ V_2 -> V_118 ] ,
sizeof( V_204 -> V_389 ) ) ;
snprintf ( V_204 -> V_391 , sizeof( V_204 -> V_391 ) ,
L_61 ,
V_204 -> V_389 , V_2 -> V_3 , V_2 -> V_71 ) ;
* V_356 = V_2 ;
return 0 ;
V_367:
F_175 ( V_2 ) ;
return V_19 ;
}
static void F_200 ( struct V_1 * V_2 )
{
#ifdef F_91
struct V_211 * V_212 ;
F_95 (codec, &chip->bus->codec_list, list) {
F_105 ( V_212 ) ;
}
#endif
}
static int T_5 F_201 ( struct V_113 * V_21 ,
const struct V_392 * V_393 )
{
static int V_215 ;
struct V_328 * V_204 ;
struct V_1 * V_2 ;
int V_19 ;
if ( V_215 >= V_394 )
return - V_386 ;
if ( ! V_395 [ V_215 ] ) {
V_215 ++ ;
return - V_396 ;
}
V_19 = F_202 ( V_107 [ V_215 ] , V_397 [ V_215 ] , V_398 , 0 , & V_204 ) ;
if ( V_19 < 0 ) {
F_10 (KERN_ERR SFX L_62 ) ;
return V_19 ;
}
F_203 ( V_204 , & V_21 -> V_215 ) ;
V_19 = F_184 ( V_204 , V_21 , V_215 , V_393 -> V_399 , & V_2 ) ;
if ( V_19 < 0 )
goto V_400;
V_204 -> V_55 = V_2 ;
#ifdef F_204
V_2 -> V_213 = V_213 [ V_215 ] ;
#endif
V_19 = F_90 ( V_2 , V_188 [ V_215 ] ) ;
if ( V_19 < 0 )
goto V_400;
#ifdef F_205
if ( V_401 [ V_215 ] && * V_401 [ V_215 ] ) {
F_10 (KERN_ERR SFX L_63 ,
patch[dev]) ;
V_19 = F_206 ( V_2 -> V_53 , V_401 [ V_215 ] ) ;
if ( V_19 < 0 )
goto V_400;
}
#endif
if ( ( V_385 [ V_215 ] & 1 ) == 0 ) {
V_19 = F_94 ( V_2 ) ;
if ( V_19 < 0 )
goto V_400;
}
V_19 = F_207 ( V_2 -> V_53 ) ;
if ( V_19 < 0 )
goto V_400;
V_19 = F_149 ( V_2 ) ;
if ( V_19 < 0 )
goto V_400;
V_19 = F_208 ( V_204 ) ;
if ( V_19 < 0 )
goto V_400;
F_209 ( V_21 , V_204 ) ;
V_2 -> V_142 = 1 ;
F_200 ( V_2 ) ;
F_171 ( V_2 ) ;
V_215 ++ ;
return V_19 ;
V_400:
F_210 ( V_204 ) ;
return V_19 ;
}
static void T_9 F_211 ( struct V_113 * V_21 )
{
F_210 ( F_158 ( V_21 ) ) ;
F_209 ( V_21 , NULL ) ;
}
static int T_10 F_212 ( void )
{
return F_213 ( & V_388 ) ;
}
static void T_11 F_214 ( void )
{
F_215 ( & V_388 ) ;
}
