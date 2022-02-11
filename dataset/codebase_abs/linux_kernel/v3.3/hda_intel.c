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
if ( ! ( V_2 -> V_43 & V_117 ) ) {
F_36 ( V_68 L_15 ) ;
F_59 ( V_2 -> V_21 , V_118 , 0x07 , 0 ) ;
}
if ( V_2 -> V_43 & V_119 ) {
F_36 ( V_68 L_16 , F_2 ( V_2 ) ) ;
F_59 ( V_2 -> V_21 ,
V_120 , 0x07 ,
F_2 ( V_2 ) ? V_121 : 0 ) ;
}
if ( V_2 -> V_43 & V_122 ) {
F_36 ( V_68 L_17 , F_2 ( V_2 ) ) ;
F_59 ( V_2 -> V_21 ,
V_123 ,
0x0f , V_124 ) ;
F_59 ( V_2 -> V_21 ,
V_125 ,
0x01 , V_126 ) ;
F_59 ( V_2 -> V_21 ,
V_127 ,
0x01 , V_126 ) ;
}
if ( V_2 -> V_43 & V_128 ) {
unsigned short V_129 ;
F_63 ( V_2 -> V_21 , V_130 , & V_129 ) ;
if ( ( ! F_2 ( V_2 ) && ! ( V_129 & V_131 ) ) ||
( F_2 ( V_2 ) && ( V_129 & V_131 ) ) ) {
V_129 &= ~ V_131 ;
if ( ! F_2 ( V_2 ) )
V_129 |= V_131 ;
F_64 ( V_2 -> V_21 , V_130 , V_129 ) ;
F_63 ( V_2 -> V_21 ,
V_130 , & V_129 ) ;
}
F_36 ( V_68 L_18 ,
( V_129 & V_131 )
? L_19 : L_20 ) ;
}
}
static T_2 F_65 ( int V_71 , void * V_132 )
{
struct V_1 * V_2 = V_132 ;
struct V_13 * V_13 ;
V_25 V_133 ;
T_3 V_134 ;
int V_97 , V_135 ;
F_66 ( & V_2 -> V_23 ) ;
V_133 = F_40 ( V_2 , V_104 ) ;
if ( V_133 == 0 ) {
F_67 ( & V_2 -> V_23 ) ;
return V_136 ;
}
for ( V_97 = 0 ; V_97 < V_2 -> V_98 ; V_97 ++ ) {
V_13 = & V_2 -> V_13 [ V_97 ] ;
if ( V_133 & V_13 -> V_137 ) {
V_134 = F_53 ( V_13 , V_101 ) ;
F_52 ( V_13 , V_101 , V_100 ) ;
if ( ! V_13 -> V_138 || ! V_13 -> V_139 ||
! ( V_134 & V_140 ) )
continue;
V_135 = F_68 ( V_2 , V_13 ) ;
if ( V_135 == 1 ) {
V_13 -> V_141 = 0 ;
F_67 ( & V_2 -> V_23 ) ;
F_69 ( V_13 -> V_138 ) ;
F_66 ( & V_2 -> V_23 ) ;
} else if ( V_135 == 0 && V_2 -> V_53 && V_2 -> V_53 -> V_142 ) {
V_13 -> V_141 = 1 ;
F_70 ( V_2 -> V_53 -> V_142 ,
& V_2 -> V_143 ) ;
}
}
}
V_133 = F_23 ( V_2 , V_102 ) ;
if ( V_133 & V_103 ) {
if ( V_133 & V_144 ) {
if ( V_2 -> V_43 & V_145 )
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
return V_146 ;
}
static int F_71 ( struct V_147 * V_138 ,
struct V_13 * V_13 , V_25 * * V_148 ,
int V_149 , int V_4 , int V_150 )
{
V_25 * V_151 = * V_148 ;
while ( V_4 > 0 ) {
T_4 V_3 ;
int V_152 ;
if ( V_13 -> V_153 >= V_154 )
return - V_155 ;
V_3 = F_72 ( V_138 , V_149 ) ;
V_151 [ 0 ] = F_24 ( ( V_25 ) V_3 ) ;
V_151 [ 1 ] = F_24 ( F_14 ( V_3 ) ) ;
V_152 = F_73 ( V_138 , V_149 , V_4 ) ;
V_151 [ 2 ] = F_24 ( V_152 ) ;
V_4 -= V_152 ;
V_151 [ 3 ] = ( V_4 || ! V_150 ) ? 0 : F_24 ( 0x01 ) ;
V_151 += 4 ;
V_13 -> V_153 ++ ;
V_149 += V_152 ;
}
* V_148 = V_151 ;
return V_149 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_147 * V_138 ,
struct V_13 * V_13 )
{
V_25 * V_151 ;
int V_97 , V_149 , V_156 , V_157 ;
int V_158 ;
F_75 ( V_13 , V_159 , 0 ) ;
F_75 ( V_13 , V_160 , 0 ) ;
V_157 = V_13 -> V_157 ;
V_156 = V_13 -> V_161 / V_157 ;
V_151 = ( V_25 * ) V_13 -> V_151 . V_11 ;
V_149 = 0 ;
V_13 -> V_153 = 0 ;
V_158 = V_162 [ V_2 -> V_163 ] ;
if ( V_158 > 0 ) {
struct V_14 * V_15 = V_138 -> V_15 ;
int V_164 = V_158 ;
V_158 = ( V_158 * V_15 -> V_165 + 47999 ) / 48000 ;
if ( ! V_158 )
V_158 = V_164 ;
else
V_158 = ( ( V_158 + V_164 - 1 ) / V_164 ) *
V_164 ;
V_158 = F_76 ( V_15 , V_158 ) ;
if ( V_158 >= V_157 ) {
F_10 (KERN_WARNING SFX L_21 ,
bdl_pos_adj[chip->dev_index]) ;
V_158 = 0 ;
} else {
V_149 = F_71 ( V_138 , V_13 ,
& V_151 , V_149 , V_158 ,
! V_138 -> V_15 -> V_166 ) ;
if ( V_149 < 0 )
goto error;
}
} else
V_158 = 0 ;
for ( V_97 = 0 ; V_97 < V_156 ; V_97 ++ ) {
if ( V_97 == V_156 - 1 && V_158 )
V_149 = F_71 ( V_138 , V_13 , & V_151 , V_149 ,
V_157 - V_158 , 0 ) ;
else
V_149 = F_71 ( V_138 , V_13 , & V_151 , V_149 ,
V_157 ,
! V_138 -> V_15 -> V_166 ) ;
if ( V_149 < 0 )
goto error;
}
return 0 ;
error:
F_10 (KERN_ERR SFX L_22 ,
azx_dev->bufsize, period_bytes) ;
return - V_155 ;
}
static void F_77 ( struct V_1 * V_2 , struct V_13 * V_13 )
{
unsigned char V_54 ;
int V_60 ;
F_56 ( V_2 , V_13 ) ;
F_52 ( V_13 , V_99 , F_53 ( V_13 , V_99 ) |
V_167 ) ;
F_34 ( 3 ) ;
V_60 = 300 ;
while ( ! ( ( V_54 = F_53 ( V_13 , V_99 ) ) & V_167 ) &&
-- V_60 )
;
V_54 &= ~ V_167 ;
F_52 ( V_13 , V_99 , V_54 ) ;
F_34 ( 3 ) ;
V_60 = 300 ;
while ( ( ( V_54 = F_53 ( V_13 , V_99 ) ) & V_167 ) &&
-- V_60 )
;
* V_13 -> V_111 = 0 ;
}
static int F_78 ( struct V_1 * V_2 , struct V_13 * V_13 )
{
unsigned int V_54 ;
F_56 ( V_2 , V_13 ) ;
V_54 = F_79 ( V_13 , V_99 ) ;
V_54 = ( V_54 & ~ V_168 ) |
( V_13 -> V_169 << V_170 ) ;
if ( ! F_2 ( V_2 ) )
V_54 |= V_171 ;
F_75 ( V_13 , V_99 , V_54 ) ;
F_75 ( V_13 , V_172 , V_13 -> V_161 ) ;
F_80 ( V_13 , V_173 , V_13 -> V_174 ) ;
F_80 ( V_13 , V_175 , V_13 -> V_153 - 1 ) ;
F_75 ( V_13 , V_159 , ( V_25 ) V_13 -> V_151 . V_3 ) ;
F_75 ( V_13 , V_160 , F_14 ( V_13 -> V_151 . V_3 ) ) ;
if ( V_2 -> V_176 [ 0 ] != V_177 ||
V_2 -> V_176 [ 1 ] != V_177 ) {
if ( ! ( F_40 ( V_2 , V_110 ) & V_178 ) )
F_13 ( V_2 , V_110 ,
( V_25 ) V_2 -> V_111 . V_3 | V_178 ) ;
}
F_75 ( V_13 , V_99 ,
F_79 ( V_13 , V_99 ) | V_100 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_49 = ( V_3 << 28 ) | ( V_179 << 20 ) |
( V_180 << 8 ) | V_181 ;
unsigned int V_51 ;
F_82 ( & V_2 -> V_53 -> V_182 ) ;
V_2 -> V_72 = 1 ;
F_47 ( V_2 -> V_53 , V_49 ) ;
V_51 = F_48 ( V_2 -> V_53 , V_3 ) ;
V_2 -> V_72 = 0 ;
F_83 ( & V_2 -> V_53 -> V_182 ) ;
if ( V_51 == - 1 )
return - V_83 ;
F_36 ( V_68 L_23 , V_3 ) ;
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
struct V_183 * V_184 ;
F_87 (p, &chip->pcm_list, list)
F_88 ( V_184 -> V_185 ) ;
F_89 ( V_2 -> V_53 ) ;
F_90 ( V_2 -> V_53 ) ;
}
#endif
V_53 -> V_75 = 0 ;
}
static int T_5 F_91 ( struct V_1 * V_2 , const char * V_186 )
{
struct V_187 V_188 ;
int V_189 , V_190 , V_19 ;
int V_191 ;
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
V_188 . V_55 = V_2 ;
V_188 . V_192 = V_186 ;
V_188 . V_21 = V_2 -> V_21 ;
V_188 . V_193 . V_194 = F_47 ;
V_188 . V_193 . V_195 = F_48 ;
V_188 . V_193 . V_196 = V_197 ;
V_188 . V_193 . V_198 = F_84 ;
#ifdef F_92
V_188 . V_199 = & V_199 ;
V_188 . V_193 . V_200 = V_201 ;
#endif
V_19 = F_93 ( V_2 -> V_202 , & V_188 , & V_2 -> V_53 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_2 -> V_43 & V_203 ) {
F_44 ( V_68 L_24 ) ;
V_2 -> V_53 -> V_67 = 1 ;
}
V_190 = 0 ;
V_191 = V_204 [ V_2 -> V_205 ] ;
if ( ! V_191 )
V_191 = V_206 ;
for ( V_189 = 0 ; V_189 < V_191 ; V_189 ++ ) {
if ( ( V_2 -> V_93 & ( 1 << V_189 ) ) & V_2 -> V_207 ) {
if ( F_81 ( V_2 , V_189 ) < 0 ) {
F_10 (KERN_WARNING SFX
L_25
L_26 , c) ;
V_2 -> V_93 &= ~ ( 1 << V_189 ) ;
F_85 ( V_2 ) ;
F_58 ( V_2 , 1 ) ;
}
}
}
if ( V_2 -> V_43 & V_208 ) {
F_44 ( V_68 L_27 ) ;
V_2 -> V_53 -> V_209 = 1 ;
V_2 -> V_53 -> V_73 = 1 ;
}
for ( V_189 = 0 ; V_189 < V_191 ; V_189 ++ ) {
if ( ( V_2 -> V_93 & ( 1 << V_189 ) ) & V_2 -> V_207 ) {
struct V_210 * V_211 ;
V_19 = F_94 ( V_2 -> V_53 , V_189 , & V_211 ) ;
if ( V_19 < 0 )
continue;
V_211 -> V_212 = V_2 -> V_212 ;
V_190 ++ ;
}
}
if ( ! V_190 ) {
F_10 (KERN_ERR SFX L_28 ) ;
return - V_213 ;
}
return 0 ;
}
static int T_5 F_95 ( struct V_1 * V_2 )
{
struct V_210 * V_211 ;
F_87 (codec, &chip->bus->codec_list, list) {
F_96 ( V_211 ) ;
}
return 0 ;
}
static inline struct V_13 *
F_97 ( struct V_1 * V_2 , struct V_147 * V_138 )
{
int V_214 , V_97 , V_215 ;
struct V_13 * V_51 = NULL ;
int V_216 = ( V_138 -> V_185 -> V_217 << 16 ) | ( V_138 -> V_218 << 2 ) |
( V_138 -> V_219 + 1 ) ;
if ( V_138 -> V_219 == V_220 ) {
V_214 = V_2 -> V_221 ;
V_215 = V_2 -> V_222 ;
} else {
V_214 = V_2 -> V_223 ;
V_215 = V_2 -> V_224 ;
}
for ( V_97 = 0 ; V_97 < V_215 ; V_97 ++ , V_214 ++ )
if ( ! V_2 -> V_13 [ V_214 ] . V_225 ) {
V_51 = & V_2 -> V_13 [ V_214 ] ;
if ( V_51 -> V_226 == V_216 )
break;
}
if ( V_51 ) {
V_51 -> V_225 = 1 ;
V_51 -> V_226 = V_216 ;
}
return V_51 ;
}
static inline void F_98 ( struct V_13 * V_13 )
{
V_13 -> V_225 = 0 ;
}
static int F_99 ( struct V_147 * V_138 )
{
struct V_183 * V_227 = F_100 ( V_138 ) ;
struct V_228 * V_229 = V_227 -> V_229 [ V_138 -> V_219 ] ;
struct V_1 * V_2 = V_227 -> V_2 ;
struct V_13 * V_13 ;
struct V_14 * V_15 = V_138 -> V_15 ;
unsigned long V_230 ;
int V_19 ;
int V_231 ;
F_82 ( & V_2 -> V_232 ) ;
V_13 = F_97 ( V_2 , V_138 ) ;
if ( V_13 == NULL ) {
F_83 ( & V_2 -> V_232 ) ;
return - V_92 ;
}
V_15 -> V_233 = V_234 ;
V_15 -> V_233 . V_235 = V_229 -> V_235 ;
V_15 -> V_233 . V_236 = V_229 -> V_236 ;
V_15 -> V_233 . V_237 = V_229 -> V_237 ;
V_15 -> V_233 . V_238 = V_229 -> V_238 ;
F_101 ( V_15 ) ;
F_102 ( V_15 , V_239 ) ;
if ( V_2 -> V_240 )
V_231 = 128 ;
else
V_231 = 4 ;
F_103 ( V_15 , 0 , V_241 ,
V_231 ) ;
F_103 ( V_15 , 0 , V_242 ,
V_231 ) ;
F_104 ( V_227 -> V_211 ) ;
V_19 = V_229 -> V_193 . V_243 ( V_229 , V_227 -> V_211 , V_138 ) ;
if ( V_19 < 0 ) {
F_98 ( V_13 ) ;
F_105 ( V_227 -> V_211 ) ;
F_83 ( & V_2 -> V_232 ) ;
return V_19 ;
}
F_101 ( V_15 ) ;
if ( F_106 ( ! V_15 -> V_233 . V_235 ) ||
F_106 ( ! V_15 -> V_233 . V_236 ) ||
F_106 ( ! V_15 -> V_233 . V_237 ) ||
F_106 ( ! V_15 -> V_233 . V_238 ) ) {
F_98 ( V_13 ) ;
V_229 -> V_193 . V_244 ( V_229 , V_227 -> V_211 , V_138 ) ;
F_105 ( V_227 -> V_211 ) ;
F_83 ( & V_2 -> V_232 ) ;
return - V_155 ;
}
F_107 ( & V_2 -> V_23 , V_230 ) ;
V_13 -> V_138 = V_138 ;
V_13 -> V_139 = 0 ;
F_108 ( & V_2 -> V_23 , V_230 ) ;
V_15 -> V_55 = V_13 ;
F_109 ( V_138 ) ;
F_83 ( & V_2 -> V_232 ) ;
return 0 ;
}
static int F_110 ( struct V_147 * V_138 )
{
struct V_183 * V_227 = F_100 ( V_138 ) ;
struct V_228 * V_229 = V_227 -> V_229 [ V_138 -> V_219 ] ;
struct V_1 * V_2 = V_227 -> V_2 ;
struct V_13 * V_13 = F_111 ( V_138 ) ;
unsigned long V_230 ;
F_82 ( & V_2 -> V_232 ) ;
F_107 ( & V_2 -> V_23 , V_230 ) ;
V_13 -> V_138 = NULL ;
V_13 -> V_139 = 0 ;
F_108 ( & V_2 -> V_23 , V_230 ) ;
F_98 ( V_13 ) ;
V_229 -> V_193 . V_244 ( V_229 , V_227 -> V_211 , V_138 ) ;
F_105 ( V_227 -> V_211 ) ;
F_83 ( & V_2 -> V_232 ) ;
return 0 ;
}
static int F_112 ( struct V_147 * V_138 ,
struct V_245 * V_246 )
{
struct V_183 * V_227 = F_100 ( V_138 ) ;
struct V_1 * V_2 = V_227 -> V_2 ;
struct V_14 * V_15 = V_138 -> V_15 ;
struct V_13 * V_13 = F_111 ( V_138 ) ;
int V_247 ;
F_6 ( V_2 , V_13 , V_15 , false ) ;
V_13 -> V_161 = 0 ;
V_13 -> V_157 = 0 ;
V_13 -> V_174 = 0 ;
V_247 = F_113 ( V_138 ,
F_114 ( V_246 ) ) ;
if ( V_247 < 0 )
return V_247 ;
F_6 ( V_2 , V_13 , V_15 , true ) ;
return V_247 ;
}
static int F_115 ( struct V_147 * V_138 )
{
struct V_183 * V_227 = F_100 ( V_138 ) ;
struct V_13 * V_13 = F_111 ( V_138 ) ;
struct V_1 * V_2 = V_227 -> V_2 ;
struct V_14 * V_15 = V_138 -> V_15 ;
struct V_228 * V_229 = V_227 -> V_229 [ V_138 -> V_219 ] ;
F_75 ( V_13 , V_159 , 0 ) ;
F_75 ( V_13 , V_160 , 0 ) ;
F_75 ( V_13 , V_99 , 0 ) ;
V_13 -> V_161 = 0 ;
V_13 -> V_157 = 0 ;
V_13 -> V_174 = 0 ;
F_116 ( V_227 -> V_211 , V_229 , V_138 ) ;
F_6 ( V_2 , V_13 , V_15 , false ) ;
return F_117 ( V_138 ) ;
}
static int F_118 ( struct V_147 * V_138 )
{
struct V_183 * V_227 = F_100 ( V_138 ) ;
struct V_1 * V_2 = V_227 -> V_2 ;
struct V_13 * V_13 = F_111 ( V_138 ) ;
struct V_228 * V_229 = V_227 -> V_229 [ V_138 -> V_219 ] ;
struct V_14 * V_15 = V_138 -> V_15 ;
unsigned int V_161 , V_157 , V_174 , V_169 ;
int V_19 ;
struct V_248 * V_249 =
F_119 ( V_227 -> V_211 , V_229 -> V_250 ) ;
unsigned short V_251 = V_249 ? V_249 -> V_251 : 0 ;
F_77 ( V_2 , V_13 ) ;
V_174 = F_120 ( V_15 -> V_165 ,
V_15 -> V_252 ,
V_15 -> V_253 ,
V_229 -> V_254 ,
V_251 ) ;
if ( ! V_174 ) {
F_10 (KERN_ERR SFX
L_29 ,
runtime->rate, runtime->channels, runtime->format) ;
return - V_155 ;
}
V_161 = F_121 ( V_138 ) ;
V_157 = F_122 ( V_138 ) ;
F_36 ( V_68 L_30 ,
V_161 , V_174 ) ;
if ( V_161 != V_13 -> V_161 ||
V_157 != V_13 -> V_157 ||
V_174 != V_13 -> V_174 ) {
V_13 -> V_161 = V_161 ;
V_13 -> V_157 = V_157 ;
V_13 -> V_174 = V_174 ;
V_19 = F_74 ( V_2 , V_138 , V_13 ) ;
if ( V_19 < 0 )
return V_19 ;
}
V_13 -> V_255 = ( ( ( V_15 -> V_256 * 24000 ) /
V_15 -> V_165 ) * 1000 ) ;
F_78 ( V_2 , V_13 ) ;
if ( V_138 -> V_219 == V_220 )
V_13 -> V_257 = F_123 ( V_13 , V_258 ) + 1 ;
else
V_13 -> V_257 = 0 ;
V_169 = V_13 -> V_169 ;
if ( ( V_2 -> V_43 & V_44 ) &&
V_169 > V_2 -> V_224 )
V_169 -= V_2 -> V_224 ;
return F_124 ( V_227 -> V_211 , V_229 , V_169 ,
V_13 -> V_174 , V_138 ) ;
}
static int F_125 ( struct V_147 * V_138 , int V_49 )
{
struct V_183 * V_227 = F_100 ( V_138 ) ;
struct V_1 * V_2 = V_227 -> V_2 ;
struct V_13 * V_13 ;
struct V_147 * V_259 ;
int V_260 = 0 , V_261 , V_262 = 0 , V_263 = 0 ;
int V_264 , V_60 ;
switch ( V_49 ) {
case V_265 :
V_260 = 1 ;
case V_266 :
case V_267 :
V_261 = 1 ;
break;
case V_268 :
case V_269 :
case V_270 :
V_261 = 0 ;
break;
default:
return - V_155 ;
}
F_126 (s, substream) {
if ( V_259 -> V_185 -> V_202 != V_138 -> V_185 -> V_202 )
continue;
V_13 = F_111 ( V_259 ) ;
V_263 |= 1 << V_13 -> V_107 ;
V_262 ++ ;
F_127 ( V_259 , V_138 ) ;
}
F_66 ( & V_2 -> V_23 ) ;
if ( V_262 > 1 ) {
if ( V_2 -> V_43 & V_271 )
F_13 ( V_2 , V_272 ,
F_40 ( V_2 , V_272 ) | V_263 ) ;
else
F_13 ( V_2 , V_273 , F_40 ( V_2 , V_273 ) | V_263 ) ;
}
F_126 (s, substream) {
if ( V_259 -> V_185 -> V_202 != V_138 -> V_185 -> V_202 )
continue;
V_13 = F_111 ( V_259 ) ;
if ( V_261 ) {
V_13 -> V_274 = F_40 ( V_2 , V_275 ) ;
if ( ! V_260 )
V_13 -> V_274 -=
V_13 -> V_255 ;
F_55 ( V_2 , V_13 ) ;
} else {
F_57 ( V_2 , V_13 ) ;
}
V_13 -> V_139 = V_261 ;
}
F_67 ( & V_2 -> V_23 ) ;
if ( V_261 ) {
if ( V_262 == 1 )
return 0 ;
for ( V_60 = 5000 ; V_60 ; V_60 -- ) {
V_264 = 0 ;
F_126 (s, substream) {
if ( V_259 -> V_185 -> V_202 != V_138 -> V_185 -> V_202 )
continue;
V_13 = F_111 ( V_259 ) ;
if ( ! ( F_53 ( V_13 , V_101 ) &
V_276 ) )
V_264 ++ ;
}
if ( ! V_264 )
break;
F_128 () ;
}
} else {
for ( V_60 = 5000 ; V_60 ; V_60 -- ) {
V_264 = 0 ;
F_126 (s, substream) {
if ( V_259 -> V_185 -> V_202 != V_138 -> V_185 -> V_202 )
continue;
V_13 = F_111 ( V_259 ) ;
if ( F_53 ( V_13 , V_99 ) &
V_108 )
V_264 ++ ;
}
if ( ! V_264 )
break;
F_128 () ;
}
}
if ( V_262 > 1 ) {
F_66 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_43 & V_271 )
F_13 ( V_2 , V_272 ,
F_40 ( V_2 , V_272 ) & ~ V_263 ) ;
else
F_13 ( V_2 , V_273 , F_40 ( V_2 , V_273 ) & ~ V_263 ) ;
F_67 ( & V_2 -> V_23 ) ;
}
return 0 ;
}
static unsigned int F_129 ( struct V_1 * V_2 ,
struct V_13 * V_13 )
{
unsigned int V_277 , V_278 , V_279 ;
unsigned int V_280 , V_281 , V_282 ;
unsigned int V_257 ;
V_277 = F_79 ( V_13 , V_283 ) ;
if ( V_13 -> V_138 -> V_219 == V_220 ) {
return V_277 ;
}
V_281 = F_26 ( * V_13 -> V_111 ) ;
V_281 %= V_13 -> V_157 ;
V_257 = F_130 ( V_2 -> V_284 + V_285 ) ;
if ( V_13 -> V_106 ) {
if ( V_277 <= V_257 )
return 0 ;
V_13 -> V_106 = 0 ;
}
if ( V_277 <= V_257 )
V_278 = V_13 -> V_161 + V_277 - V_257 ;
else
V_278 = V_277 - V_257 ;
V_282 = V_278 % V_13 -> V_157 ;
V_280 = V_277 % V_13 -> V_157 ;
if ( V_280 >= V_257 )
V_279 = V_277 - V_280 ;
else if ( V_281 >= V_282 )
V_279 = V_278 - V_282 ;
else {
V_279 = V_278 - V_282 + V_13 -> V_157 ;
if ( V_279 >= V_13 -> V_161 )
V_279 = 0 ;
}
return V_279 + V_281 ;
}
static unsigned int F_131 ( struct V_1 * V_2 ,
struct V_13 * V_13 ,
bool V_286 )
{
unsigned int V_287 ;
int V_219 = V_13 -> V_138 -> V_219 ;
switch ( V_2 -> V_176 [ V_219 ] ) {
case V_177 :
V_287 = F_79 ( V_13 , V_283 ) ;
break;
case V_288 :
V_287 = F_129 ( V_2 , V_13 ) ;
break;
default:
V_287 = F_26 ( * V_13 -> V_111 ) ;
if ( V_286 && V_2 -> V_176 [ V_219 ] == V_289 ) {
if ( ! V_287 || V_287 == ( V_25 ) - 1 ) {
F_132 ( V_290
L_31
L_32 ) ;
V_2 -> V_176 [ V_219 ] = V_177 ;
V_287 = F_79 ( V_13 , V_283 ) ;
} else
V_2 -> V_176 [ V_219 ] = V_291 ;
}
break;
}
if ( V_287 >= V_13 -> V_161 )
V_287 = 0 ;
return V_287 ;
}
static T_6 F_133 ( struct V_147 * V_138 )
{
struct V_183 * V_227 = F_100 ( V_138 ) ;
struct V_1 * V_2 = V_227 -> V_2 ;
struct V_13 * V_13 = F_111 ( V_138 ) ;
return F_134 ( V_138 -> V_15 ,
F_131 ( V_2 , V_13 , false ) ) ;
}
static int F_68 ( struct V_1 * V_2 , struct V_13 * V_13 )
{
V_25 V_292 ;
unsigned int V_287 ;
int V_219 ;
V_292 = F_40 ( V_2 , V_275 ) - V_13 -> V_274 ;
if ( V_292 < ( V_13 -> V_255 * 2 ) / 3 )
return - 1 ;
V_219 = V_13 -> V_138 -> V_219 ;
V_287 = F_131 ( V_2 , V_13 , true ) ;
if ( F_135 ( ! V_13 -> V_157 ,
L_33 ) )
return - 1 ;
if ( V_292 < ( V_13 -> V_255 * 5 ) / 4 &&
V_287 % V_13 -> V_157 > V_13 -> V_157 / 2 )
return V_162 [ V_2 -> V_163 ] ? 0 : - 1 ;
V_13 -> V_274 += V_292 ;
return 1 ;
}
static void F_136 ( struct V_293 * V_294 )
{
struct V_1 * V_2 = F_137 ( V_294 , struct V_1 , V_143 ) ;
int V_97 , V_295 , V_135 ;
if ( ! V_2 -> V_296 ) {
F_132 ( V_290
L_34
L_35 ,
V_2 -> V_202 -> V_218 ) ;
V_2 -> V_296 = 1 ;
}
for (; ; ) {
V_295 = 0 ;
F_12 ( & V_2 -> V_23 ) ;
for ( V_97 = 0 ; V_97 < V_2 -> V_98 ; V_97 ++ ) {
struct V_13 * V_13 = & V_2 -> V_13 [ V_97 ] ;
if ( ! V_13 -> V_141 ||
! V_13 -> V_138 ||
! V_13 -> V_139 )
continue;
V_135 = F_68 ( V_2 , V_13 ) ;
if ( V_135 > 0 ) {
V_13 -> V_141 = 0 ;
F_67 ( & V_2 -> V_23 ) ;
F_69 ( V_13 -> V_138 ) ;
F_66 ( & V_2 -> V_23 ) ;
} else if ( V_135 < 0 ) {
V_295 = 0 ;
} else
V_295 ++ ;
}
F_17 ( & V_2 -> V_23 ) ;
if ( ! V_295 )
return;
F_33 ( 1 ) ;
}
}
static void F_138 ( struct V_1 * V_2 )
{
int V_97 ;
F_12 ( & V_2 -> V_23 ) ;
for ( V_97 = 0 ; V_97 < V_2 -> V_98 ; V_97 ++ )
V_2 -> V_13 [ V_97 ] . V_141 = 0 ;
F_17 ( & V_2 -> V_23 ) ;
}
static int F_139 ( struct V_147 * V_138 ,
struct V_297 * V_11 )
{
struct V_183 * V_227 = F_100 ( V_138 ) ;
struct V_1 * V_2 = V_227 -> V_2 ;
if ( ! F_2 ( V_2 ) )
V_11 -> V_298 = F_140 ( V_11 -> V_298 ) ;
return F_141 ( V_138 , V_11 ) ;
}
static void F_142 ( struct V_299 * V_185 )
{
struct V_183 * V_227 = V_185 -> V_55 ;
if ( V_227 ) {
F_143 ( & V_227 -> V_300 ) ;
F_144 ( V_227 ) ;
}
}
static int
V_197 ( struct V_52 * V_53 , struct V_210 * V_211 ,
struct V_301 * V_302 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_299 * V_185 ;
struct V_183 * V_227 ;
int V_303 = V_302 -> V_217 ;
unsigned int V_4 ;
int V_259 , V_19 ;
F_87 (apcm, &chip->pcm_list, list) {
if ( V_227 -> V_185 -> V_217 == V_303 ) {
F_10 (KERN_ERR SFX L_36 , pcm_dev) ;
return - V_92 ;
}
}
V_19 = F_145 ( V_2 -> V_202 , V_302 -> V_304 , V_303 ,
V_302 -> V_219 [ V_220 ] . V_305 ,
V_302 -> V_219 [ V_306 ] . V_305 ,
& V_185 ) ;
if ( V_19 < 0 )
return V_19 ;
F_146 ( V_185 -> V_304 , V_302 -> V_304 , sizeof( V_185 -> V_304 ) ) ;
V_227 = F_147 ( sizeof( * V_227 ) , V_307 ) ;
if ( V_227 == NULL )
return - V_308 ;
V_227 -> V_2 = V_2 ;
V_227 -> V_185 = V_185 ;
V_227 -> V_211 = V_211 ;
V_185 -> V_55 = V_227 ;
V_185 -> V_309 = F_142 ;
if ( V_302 -> V_310 == V_311 )
V_185 -> V_312 = V_313 ;
F_148 ( & V_227 -> V_300 , & V_2 -> V_314 ) ;
V_302 -> V_185 = V_185 ;
for ( V_259 = 0 ; V_259 < 2 ; V_259 ++ ) {
V_227 -> V_229 [ V_259 ] = & V_302 -> V_219 [ V_259 ] ;
if ( V_302 -> V_219 [ V_259 ] . V_305 )
F_149 ( V_185 , V_259 , & V_315 ) ;
}
V_4 = V_316 * 1024 ;
if ( V_4 > V_317 )
V_4 = V_317 ;
F_150 ( V_185 , V_318 ,
F_9 ( V_2 -> V_21 ) ,
V_4 , V_317 ) ;
return 0 ;
}
static int T_5 F_151 ( struct V_1 * V_2 )
{
return F_152 ( V_2 -> V_53 ) ;
}
static int T_5 F_153 ( struct V_1 * V_2 )
{
int V_97 ;
for ( V_97 = 0 ; V_97 < V_2 -> V_98 ; V_97 ++ ) {
struct V_13 * V_13 = & V_2 -> V_13 [ V_97 ] ;
V_13 -> V_111 = ( V_25 V_319 * ) ( V_2 -> V_111 . V_11 + V_97 * 8 ) ;
V_13 -> V_320 = V_2 -> V_284 + ( 0x20 * V_97 + 0x80 ) ;
V_13 -> V_137 = 1 << V_97 ;
V_13 -> V_107 = V_97 ;
V_13 -> V_169 = V_97 + 1 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , int V_321 )
{
if ( F_154 ( V_2 -> V_21 -> V_71 , F_65 ,
V_2 -> V_70 ? 0 : V_322 ,
V_323 , V_2 ) ) {
F_132 ( V_76 L_37
L_38 , V_2 -> V_21 -> V_71 ) ;
if ( V_321 )
F_155 ( V_2 -> V_202 ) ;
return - 1 ;
}
V_2 -> V_71 = V_2 -> V_21 -> V_71 ;
F_156 ( V_2 -> V_21 , ! V_2 -> V_70 ) ;
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
static void V_201 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_210 * V_189 ;
int V_324 = 0 ;
F_87 (c, &bus->codec_list, list) {
if ( V_189 -> V_324 ) {
V_324 = 1 ;
break;
}
}
if ( V_324 )
F_58 ( V_2 , 1 ) ;
else if ( V_2 -> V_139 && V_325 &&
! V_53 -> V_326 )
F_85 ( V_2 ) ;
}
static int F_157 ( struct V_52 * V_53 )
{
struct V_210 * V_211 ;
F_87 (codec, &bus->codec_list, list) {
if ( F_158 ( V_211 ) )
return 1 ;
}
return 0 ;
}
static int F_159 ( struct V_113 * V_21 , T_7 V_327 )
{
struct V_328 * V_202 = F_160 ( V_21 ) ;
struct V_1 * V_2 = V_202 -> V_55 ;
struct V_183 * V_184 ;
F_161 ( V_202 , V_329 ) ;
F_138 ( V_2 ) ;
F_87 (p, &chip->pcm_list, list)
F_88 ( V_184 -> V_185 ) ;
if ( V_2 -> V_109 )
F_89 ( V_2 -> V_53 ) ;
F_85 ( V_2 ) ;
if ( V_2 -> V_71 >= 0 ) {
F_37 ( V_2 -> V_71 , V_2 ) ;
V_2 -> V_71 = - 1 ;
}
if ( V_2 -> V_70 )
F_38 ( V_2 -> V_21 ) ;
F_162 ( V_21 ) ;
F_163 ( V_21 ) ;
F_164 ( V_21 , F_165 ( V_21 , V_327 ) ) ;
return 0 ;
}
static int F_166 ( struct V_113 * V_21 )
{
struct V_328 * V_202 = F_160 ( V_21 ) ;
struct V_1 * V_2 = V_202 -> V_55 ;
F_164 ( V_21 , V_330 ) ;
F_167 ( V_21 ) ;
if ( F_168 ( V_21 ) < 0 ) {
F_132 ( V_76 L_39
L_38 ) ;
F_155 ( V_202 ) ;
return - V_83 ;
}
F_169 ( V_21 ) ;
if ( V_2 -> V_70 )
if ( F_170 ( V_21 ) < 0 )
V_2 -> V_70 = 0 ;
if ( F_39 ( V_2 , 1 ) < 0 )
return - V_83 ;
F_62 ( V_2 ) ;
if ( F_157 ( V_2 -> V_53 ) )
F_58 ( V_2 , 1 ) ;
F_90 ( V_2 -> V_53 ) ;
F_161 ( V_202 , V_331 ) ;
return 0 ;
}
static int F_171 ( struct V_332 * V_333 , unsigned long V_334 , void * V_10 )
{
struct V_1 * V_2 = F_137 ( V_333 , struct V_1 , V_335 ) ;
F_172 ( V_2 -> V_53 ) ;
F_85 ( V_2 ) ;
return V_336 ;
}
static void F_173 ( struct V_1 * V_2 )
{
V_2 -> V_335 . V_337 = F_171 ;
F_174 ( & V_2 -> V_335 ) ;
}
static void F_175 ( struct V_1 * V_2 )
{
if ( V_2 -> V_335 . V_337 )
F_176 ( & V_2 -> V_335 ) ;
}
static int F_177 ( struct V_1 * V_2 )
{
int V_97 ;
F_175 ( V_2 ) ;
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
if ( V_2 -> V_284 )
F_178 ( V_2 -> V_284 ) ;
if ( V_2 -> V_13 ) {
for ( V_97 = 0 ; V_97 < V_2 -> V_98 ; V_97 ++ )
if ( V_2 -> V_13 [ V_97 ] . V_151 . V_11 ) {
F_5 ( V_2 , & V_2 -> V_13 [ V_97 ] . V_151 , false ) ;
F_179 ( & V_2 -> V_13 [ V_97 ] . V_151 ) ;
}
}
if ( V_2 -> V_22 . V_11 ) {
F_5 ( V_2 , & V_2 -> V_22 , false ) ;
F_179 ( & V_2 -> V_22 ) ;
}
if ( V_2 -> V_111 . V_11 ) {
F_5 ( V_2 , & V_2 -> V_111 , false ) ;
F_179 ( & V_2 -> V_111 ) ;
}
F_180 ( V_2 -> V_21 ) ;
F_162 ( V_2 -> V_21 ) ;
F_144 ( V_2 -> V_13 ) ;
F_144 ( V_2 ) ;
return 0 ;
}
static int F_181 ( struct V_338 * V_217 )
{
return F_177 ( V_217 -> V_339 ) ;
}
static int T_5 F_182 ( struct V_1 * V_2 , int V_340 )
{
const struct V_341 * V_342 ;
switch ( V_340 ) {
case V_177 :
case V_291 :
case V_288 :
return V_340 ;
}
V_342 = F_183 ( V_2 -> V_21 , V_343 ) ;
if ( V_342 ) {
F_132 ( V_344
L_40
L_41 ,
V_342 -> V_345 , V_342 -> V_346 , V_342 -> V_347 ) ;
return V_342 -> V_345 ;
}
if ( V_2 -> V_43 & V_348 ) {
F_44 ( V_68 L_42 ) ;
return V_288 ;
}
if ( V_2 -> V_43 & V_349 ) {
F_44 ( V_68 L_43 ) ;
return V_177 ;
}
return V_289 ;
}
static void T_5 F_184 ( struct V_1 * V_2 , int V_214 )
{
const struct V_341 * V_342 ;
V_2 -> V_207 = V_350 [ V_214 ] ;
if ( V_2 -> V_207 == - 1 ) {
V_342 = F_183 ( V_2 -> V_21 , V_351 ) ;
if ( V_342 ) {
F_132 ( V_344
L_44
L_41 ,
V_342 -> V_345 , V_342 -> V_346 , V_342 -> V_347 ) ;
V_2 -> V_207 = V_342 -> V_345 ;
}
}
if ( V_2 -> V_207 != - 1 &&
( V_2 -> V_207 & V_352 ) ) {
V_2 -> V_93 = V_2 -> V_207 & 0xff ;
F_132 ( V_344 L_45 ,
V_2 -> V_93 ) ;
}
}
static void T_5 F_185 ( struct V_1 * V_2 )
{
const struct V_341 * V_342 ;
if ( V_353 >= 0 ) {
V_2 -> V_70 = ! ! V_353 ;
return;
}
V_2 -> V_70 = 1 ;
V_342 = F_183 ( V_2 -> V_21 , V_354 ) ;
if ( V_342 ) {
F_132 ( V_344
L_46 ,
V_342 -> V_346 , V_342 -> V_347 , V_342 -> V_345 ) ;
V_2 -> V_70 = V_342 -> V_345 ;
return;
}
if ( V_2 -> V_43 & V_355 ) {
F_132 ( V_344 L_47 ) ;
V_2 -> V_70 = 0 ;
}
}
static void T_5 F_186 ( struct V_1 * V_2 )
{
bool V_129 = V_2 -> V_129 ;
switch ( V_2 -> V_205 ) {
case V_356 :
if ( V_129 ) {
T_3 V_54 ;
F_60 ( V_2 -> V_21 , 0x42 , & V_54 ) ;
if ( ! ( V_54 & 0x80 ) && V_2 -> V_21 -> V_357 == 0x30 )
V_129 = false ;
}
break;
case V_358 :
V_129 = false ;
break;
}
if ( V_129 != V_2 -> V_129 ) {
F_10 (KERN_INFO SFX L_48 ,
snoop ? L_49 : L_50 ) ;
V_2 -> V_129 = V_129 ;
}
}
static int T_5 F_187 ( struct V_328 * V_202 , struct V_113 * V_21 ,
int V_214 , unsigned int V_43 ,
struct V_1 * * V_359 )
{
struct V_1 * V_2 ;
int V_97 , V_19 ;
unsigned short V_360 ;
static struct V_361 V_193 = {
. V_362 = F_181 ,
} ;
* V_359 = NULL ;
V_19 = F_168 ( V_21 ) ;
if ( V_19 < 0 )
return V_19 ;
V_2 = F_147 ( sizeof( * V_2 ) , V_307 ) ;
if ( ! V_2 ) {
F_10 (KERN_ERR SFX L_51 ) ;
F_162 ( V_21 ) ;
return - V_308 ;
}
F_188 ( & V_2 -> V_23 ) ;
F_189 ( & V_2 -> V_232 ) ;
V_2 -> V_202 = V_202 ;
V_2 -> V_21 = V_21 ;
V_2 -> V_71 = - 1 ;
V_2 -> V_43 = V_43 ;
V_2 -> V_205 = V_43 & 0xff ;
F_185 ( V_2 ) ;
V_2 -> V_163 = V_214 ;
F_190 ( & V_2 -> V_143 , F_136 ) ;
F_191 ( & V_2 -> V_314 ) ;
V_2 -> V_176 [ 0 ] = V_2 -> V_176 [ 1 ] =
F_182 ( V_2 , V_176 [ V_214 ] ) ;
F_184 ( V_2 , V_214 ) ;
V_2 -> V_77 = V_77 ;
V_2 -> V_129 = V_363 ;
F_186 ( V_2 ) ;
if ( V_162 [ V_214 ] < 0 ) {
switch ( V_2 -> V_205 ) {
case V_364 :
case V_365 :
V_162 [ V_214 ] = 1 ;
break;
default:
V_162 [ V_214 ] = 32 ;
break;
}
}
#if V_366 != 64
if ( V_2 -> V_205 == V_367 ) {
T_8 V_368 ;
F_63 ( V_21 , 0x40 , & V_368 ) ;
F_64 ( V_21 , 0x40 , V_368 | 0x10 ) ;
F_192 ( V_21 , V_369 , 0 ) ;
}
#endif
V_19 = F_193 ( V_21 , L_52 ) ;
if ( V_19 < 0 ) {
F_144 ( V_2 ) ;
F_162 ( V_21 ) ;
return V_19 ;
}
V_2 -> V_3 = F_194 ( V_21 , 0 ) ;
V_2 -> V_284 = F_195 ( V_21 , 0 ) ;
if ( V_2 -> V_284 == NULL ) {
F_10 (KERN_ERR SFX L_53 ) ;
V_19 = - V_213 ;
goto V_370;
}
if ( V_2 -> V_70 )
if ( F_170 ( V_21 ) < 0 )
V_2 -> V_70 = 0 ;
if ( F_39 ( V_2 , 0 ) < 0 ) {
V_19 = - V_92 ;
goto V_370;
}
F_169 ( V_21 ) ;
F_196 ( V_2 -> V_71 ) ;
V_360 = F_42 ( V_2 , V_371 ) ;
F_36 ( V_68 L_54 , V_360 ) ;
if ( V_2 -> V_21 -> V_372 == V_373 ) {
struct V_113 * V_374 ;
V_374 = F_197 ( V_373 ,
V_375 ,
NULL ) ;
if ( V_374 ) {
if ( V_374 -> V_357 < 0x30 )
V_360 &= ~ V_376 ;
F_198 ( V_374 ) ;
}
}
if ( V_2 -> V_43 & V_377 ) {
F_44 ( V_68 L_55 ) ;
V_360 &= ~ V_376 ;
}
V_2 -> V_240 = V_240 ;
if ( V_2 -> V_43 & V_378 )
V_2 -> V_240 = 0 ;
if ( ( V_360 & V_376 ) && ! F_199 ( V_21 , F_200 ( 64 ) ) )
F_201 ( V_21 , F_200 ( 64 ) ) ;
else {
F_199 ( V_21 , F_200 ( 32 ) ) ;
F_201 ( V_21 , F_200 ( 32 ) ) ;
}
V_2 -> V_224 = ( V_360 >> 8 ) & 0x0f ;
V_2 -> V_222 = ( V_360 >> 12 ) & 0x0f ;
if ( ! V_2 -> V_222 && ! V_2 -> V_224 ) {
switch ( V_2 -> V_205 ) {
case V_367 :
V_2 -> V_222 = V_379 ;
V_2 -> V_224 = V_380 ;
break;
case V_381 :
case V_358 :
V_2 -> V_222 = V_382 ;
V_2 -> V_224 = V_383 ;
break;
case V_384 :
default:
V_2 -> V_222 = V_385 ;
V_2 -> V_224 = V_386 ;
break;
}
}
V_2 -> V_223 = 0 ;
V_2 -> V_221 = V_2 -> V_224 ;
V_2 -> V_98 = V_2 -> V_222 + V_2 -> V_224 ;
V_2 -> V_13 = F_202 ( V_2 -> V_98 , sizeof( * V_2 -> V_13 ) ,
V_307 ) ;
if ( ! V_2 -> V_13 ) {
F_10 (KERN_ERR SFX L_56 ) ;
goto V_370;
}
for ( V_97 = 0 ; V_97 < V_2 -> V_98 ; V_97 ++ ) {
V_19 = F_8 ( V_20 ,
F_9 ( V_2 -> V_21 ) ,
V_387 , & V_2 -> V_13 [ V_97 ] . V_151 ) ;
if ( V_19 < 0 ) {
F_10 (KERN_ERR SFX L_57 ) ;
goto V_370;
}
F_5 ( V_2 , & V_2 -> V_13 [ V_97 ] . V_151 , true ) ;
}
V_19 = F_8 ( V_20 ,
F_9 ( V_2 -> V_21 ) ,
V_2 -> V_98 * 8 , & V_2 -> V_111 ) ;
if ( V_19 < 0 ) {
F_10 (KERN_ERR SFX L_58 ) ;
goto V_370;
}
F_5 ( V_2 , & V_2 -> V_111 , true ) ;
V_19 = F_7 ( V_2 ) ;
if ( V_19 < 0 )
goto V_370;
F_153 ( V_2 ) ;
F_62 ( V_2 ) ;
F_58 ( V_2 , ( V_388 [ V_214 ] & 2 ) == 0 ) ;
if ( ! V_2 -> V_93 ) {
F_10 (KERN_ERR SFX L_59 ) ;
V_19 = - V_389 ;
goto V_370;
}
V_19 = F_203 ( V_202 , V_390 , V_2 , & V_193 ) ;
if ( V_19 < 0 ) {
F_10 (KERN_ERR SFX L_60 ) ;
goto V_370;
}
strcpy ( V_202 -> V_391 , L_61 ) ;
F_146 ( V_202 -> V_392 , V_393 [ V_2 -> V_205 ] ,
sizeof( V_202 -> V_392 ) ) ;
snprintf ( V_202 -> V_394 , sizeof( V_202 -> V_394 ) ,
L_62 ,
V_202 -> V_392 , V_2 -> V_3 , V_2 -> V_71 ) ;
* V_359 = V_2 ;
return 0 ;
V_370:
F_177 ( V_2 ) ;
return V_19 ;
}
static void F_204 ( struct V_1 * V_2 )
{
#ifdef F_92
struct V_210 * V_211 ;
F_87 (codec, &chip->bus->codec_list, list) {
F_105 ( V_211 ) ;
}
#endif
}
static int T_5 F_205 ( struct V_113 * V_21 ,
const struct V_395 * V_396 )
{
static int V_214 ;
struct V_328 * V_202 ;
struct V_1 * V_2 ;
int V_19 ;
if ( V_214 >= V_397 )
return - V_389 ;
if ( ! V_398 [ V_214 ] ) {
V_214 ++ ;
return - V_399 ;
}
V_19 = F_206 ( V_107 [ V_214 ] , V_400 [ V_214 ] , V_401 , 0 , & V_202 ) ;
if ( V_19 < 0 ) {
F_10 (KERN_ERR SFX L_63 ) ;
return V_19 ;
}
F_207 ( V_202 , & V_21 -> V_214 ) ;
V_19 = F_187 ( V_202 , V_21 , V_214 , V_396 -> V_402 , & V_2 ) ;
if ( V_19 < 0 )
goto V_403;
V_202 -> V_55 = V_2 ;
#ifdef F_208
V_2 -> V_212 = V_212 [ V_214 ] ;
#endif
V_19 = F_91 ( V_2 , V_186 [ V_214 ] ) ;
if ( V_19 < 0 )
goto V_403;
#ifdef F_209
if ( V_404 [ V_214 ] && * V_404 [ V_214 ] ) {
F_10 (KERN_ERR SFX L_64 ,
patch[dev]) ;
V_19 = F_210 ( V_2 -> V_53 , V_404 [ V_214 ] ) ;
if ( V_19 < 0 )
goto V_403;
}
#endif
if ( ( V_388 [ V_214 ] & 1 ) == 0 ) {
V_19 = F_95 ( V_2 ) ;
if ( V_19 < 0 )
goto V_403;
}
V_19 = F_211 ( V_2 -> V_53 ) ;
if ( V_19 < 0 )
goto V_403;
V_19 = F_151 ( V_2 ) ;
if ( V_19 < 0 )
goto V_403;
V_19 = F_212 ( V_202 ) ;
if ( V_19 < 0 )
goto V_403;
F_213 ( V_21 , V_202 ) ;
V_2 -> V_139 = 1 ;
F_204 ( V_2 ) ;
F_173 ( V_2 ) ;
V_214 ++ ;
return V_19 ;
V_403:
F_214 ( V_202 ) ;
return V_19 ;
}
static void T_9 F_215 ( struct V_113 * V_21 )
{
F_214 ( F_160 ( V_21 ) ) ;
F_213 ( V_21 , NULL ) ;
}
static int T_10 F_216 ( void )
{
return F_217 ( & V_391 ) ;
}
static void T_11 F_218 ( void )
{
F_219 ( & V_391 ) ;
}
