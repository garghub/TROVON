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
unsigned long V_61 ;
int V_62 = 0 ;
V_63:
V_60 = V_64 + F_30 ( 1000 ) ;
for ( V_61 = 0 ; ; V_61 ++ ) {
if ( V_2 -> V_65 || V_62 ) {
F_12 ( & V_2 -> V_23 ) ;
F_25 ( V_2 ) ;
F_17 ( & V_2 -> V_23 ) ;
}
if ( ! V_2 -> V_34 . V_37 [ V_3 ] ) {
F_31 () ;
V_53 -> V_66 = 0 ;
if ( ! V_62 )
V_2 -> V_67 = 0 ;
return V_2 -> V_34 . V_51 [ V_3 ] ;
}
if ( F_32 ( V_64 , V_60 ) )
break;
if ( V_53 -> V_68 || V_61 > 3000 )
F_33 ( 2 ) ;
else {
F_34 ( 10 ) ;
F_35 () ;
}
}
if ( ! V_2 -> V_65 && V_2 -> V_67 < 2 ) {
F_36 ( V_69 L_4
L_5 ,
V_2 -> V_70 [ V_3 ] ) ;
V_62 = 1 ;
V_2 -> V_67 ++ ;
goto V_63;
}
if ( ! V_2 -> V_65 ) {
F_10 (KERN_WARNING SFX L_4
L_6 ,
chip->last_cmd[addr]) ;
V_2 -> V_65 = 1 ;
goto V_63;
}
if ( V_2 -> V_71 ) {
F_10 (KERN_WARNING SFX L_7
L_8 ,
chip->last_cmd[addr]) ;
F_37 ( V_2 -> V_72 , V_2 ) ;
V_2 -> V_72 = - 1 ;
F_38 ( V_2 -> V_21 ) ;
V_2 -> V_71 = 0 ;
if ( F_39 ( V_2 , 1 ) < 0 ) {
V_53 -> V_66 = 1 ;
return - 1 ;
}
goto V_63;
}
if ( V_2 -> V_73 ) {
return - 1 ;
}
V_53 -> V_66 = 1 ;
if ( V_53 -> V_74 && ! V_53 -> V_75 && ! V_53 -> V_76 ) {
V_53 -> V_75 = 1 ;
return - 1 ;
}
F_10 ( V_77 L_9
L_10 ,
V_2 -> V_70 [ V_3 ] ) ;
V_2 -> V_78 = 1 ;
V_53 -> V_75 = 0 ;
F_18 ( V_2 ) ;
F_13 ( V_2 , V_79 , F_40 ( V_2 , V_79 ) & ~ V_80 ) ;
return - 1 ;
}
static int F_41 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_60 = 50 ;
while ( V_60 -- ) {
if ( F_42 ( V_2 , V_81 ) & V_82 ) {
V_2 -> V_34 . V_51 [ V_3 ] = F_40 ( V_2 , V_83 ) ;
return 0 ;
}
F_34 ( 1 ) ;
}
if ( F_43 () )
F_44 ( V_69 L_11 ,
F_42 ( V_2 , V_81 ) ) ;
V_2 -> V_34 . V_51 [ V_3 ] = - 1 ;
return - V_84 ;
}
static int F_45 ( struct V_52 * V_53 , V_25 V_54 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
unsigned int V_3 = F_19 ( V_54 ) ;
int V_60 = 50 ;
V_53 -> V_66 = 0 ;
while ( V_60 -- ) {
if ( ! ( ( F_42 ( V_2 , V_81 ) & V_85 ) ) ) {
F_16 ( V_2 , V_81 , F_42 ( V_2 , V_81 ) |
V_82 ) ;
F_13 ( V_2 , V_86 , V_54 ) ;
F_16 ( V_2 , V_81 , F_42 ( V_2 , V_81 ) |
V_85 ) ;
return F_41 ( V_2 , V_3 ) ;
}
F_34 ( 1 ) ;
}
if ( F_43 () )
F_44 ( V_69 L_12 ,
F_42 ( V_2 , V_81 ) , V_54 ) ;
return - V_84 ;
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
V_2 -> V_70 [ F_19 ( V_54 ) ] = V_54 ;
if ( V_2 -> V_78 )
return F_45 ( V_53 , V_54 ) ;
else
return F_22 ( V_53 , V_54 ) ;
}
static unsigned int F_48 ( struct V_52 * V_53 ,
unsigned int V_3 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
if ( V_2 -> V_78 )
return F_46 ( V_53 , V_3 ) ;
else
return F_29 ( V_53 , V_3 ) ;
}
static int F_49 ( struct V_1 * V_2 , int V_87 )
{
int V_88 ;
if ( ! V_87 )
goto V_89;
F_15 ( V_2 , V_90 , V_91 ) ;
F_13 ( V_2 , V_79 , F_40 ( V_2 , V_79 ) & ~ V_92 ) ;
V_88 = 50 ;
while ( F_23 ( V_2 , V_79 ) && -- V_88 )
F_33 ( 1 ) ;
F_33 ( 1 ) ;
F_15 ( V_2 , V_79 , F_23 ( V_2 , V_79 ) | V_92 ) ;
V_88 = 50 ;
while ( ! F_23 ( V_2 , V_79 ) && -- V_88 )
F_33 ( 1 ) ;
F_33 ( 1 ) ;
V_89:
if ( ! F_23 ( V_2 , V_79 ) ) {
F_44 ( V_69 L_13 ) ;
return - V_93 ;
}
if ( ! V_2 -> V_78 )
F_13 ( V_2 , V_79 , F_40 ( V_2 , V_79 ) |
V_80 ) ;
if ( ! V_2 -> V_94 ) {
V_2 -> V_94 = F_42 ( V_2 , V_90 ) ;
F_36 ( V_69 L_14 , V_2 -> V_94 ) ;
}
return 0 ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_13 ( V_2 , V_95 , F_40 ( V_2 , V_95 ) |
V_96 | V_97 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
int V_98 ;
for ( V_98 = 0 ; V_98 < V_2 -> V_99 ; V_98 ++ ) {
struct V_13 * V_13 = & V_2 -> V_13 [ V_98 ] ;
F_52 ( V_13 , V_100 ,
F_53 ( V_13 , V_100 ) & ~ V_101 ) ;
}
F_15 ( V_2 , V_95 , 0 ) ;
F_13 ( V_2 , V_95 , F_40 ( V_2 , V_95 ) &
~ ( V_96 | V_97 ) ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
int V_98 ;
for ( V_98 = 0 ; V_98 < V_2 -> V_99 ; V_98 ++ ) {
struct V_13 * V_13 = & V_2 -> V_13 [ V_98 ] ;
F_52 ( V_13 , V_102 , V_101 ) ;
}
F_15 ( V_2 , V_90 , V_91 ) ;
F_15 ( V_2 , V_103 , V_104 ) ;
F_13 ( V_2 , V_105 , V_96 | V_106 ) ;
}
static void F_55 ( struct V_1 * V_2 , struct V_13 * V_13 )
{
V_13 -> V_107 = 1 ;
F_13 ( V_2 , V_95 ,
F_40 ( V_2 , V_95 ) | ( 1 << V_13 -> V_108 ) ) ;
F_52 ( V_13 , V_100 , F_53 ( V_13 , V_100 ) |
V_109 | V_101 ) ;
}
static void F_56 ( struct V_1 * V_2 , struct V_13 * V_13 )
{
F_52 ( V_13 , V_100 , F_53 ( V_13 , V_100 ) &
~ ( V_109 | V_101 ) ) ;
F_52 ( V_13 , V_102 , V_101 ) ;
}
static void F_57 ( struct V_1 * V_2 , struct V_13 * V_13 )
{
F_56 ( V_2 , V_13 ) ;
F_13 ( V_2 , V_95 ,
F_40 ( V_2 , V_95 ) & ~ ( 1 << V_13 -> V_108 ) ) ;
}
static void F_58 ( struct V_1 * V_2 , int V_87 )
{
if ( V_2 -> V_110 )
return;
F_49 ( V_2 , V_87 ) ;
F_54 ( V_2 ) ;
F_50 ( V_2 ) ;
if ( ! V_2 -> V_78 )
F_11 ( V_2 ) ;
F_13 ( V_2 , V_111 , ( V_25 ) V_2 -> V_112 . V_3 ) ;
F_13 ( V_2 , V_113 , F_14 ( V_2 -> V_112 . V_3 ) ) ;
V_2 -> V_110 = 1 ;
}
static void F_59 ( struct V_114 * V_21 , unsigned int V_115 ,
unsigned char V_116 , unsigned char V_54 )
{
unsigned char V_117 ;
F_60 ( V_21 , V_115 , & V_117 ) ;
V_117 &= ~ V_116 ;
V_117 |= ( V_54 & V_116 ) ;
F_61 ( V_21 , V_115 , V_117 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_43 & V_118 ) ) {
F_36 ( V_69 L_15 ) ;
F_59 ( V_2 -> V_21 , V_119 , 0x07 , 0 ) ;
}
if ( V_2 -> V_43 & V_120 ) {
F_36 ( V_69 L_16 , F_2 ( V_2 ) ) ;
F_59 ( V_2 -> V_21 ,
V_121 , 0x07 ,
F_2 ( V_2 ) ? V_122 : 0 ) ;
}
if ( V_2 -> V_43 & V_123 ) {
F_36 ( V_69 L_17 , F_2 ( V_2 ) ) ;
F_59 ( V_2 -> V_21 ,
V_124 ,
0x0f , V_125 ) ;
F_59 ( V_2 -> V_21 ,
V_126 ,
0x01 , V_127 ) ;
F_59 ( V_2 -> V_21 ,
V_128 ,
0x01 , V_127 ) ;
}
if ( V_2 -> V_43 & V_129 ) {
unsigned short V_130 ;
F_63 ( V_2 -> V_21 , V_131 , & V_130 ) ;
if ( ( ! F_2 ( V_2 ) && ! ( V_130 & V_132 ) ) ||
( F_2 ( V_2 ) && ( V_130 & V_132 ) ) ) {
V_130 &= ~ V_132 ;
if ( ! F_2 ( V_2 ) )
V_130 |= V_132 ;
F_64 ( V_2 -> V_21 , V_131 , V_130 ) ;
F_63 ( V_2 -> V_21 ,
V_131 , & V_130 ) ;
}
F_36 ( V_69 L_18 ,
( V_130 & V_132 )
? L_19 : L_20 ) ;
}
}
static T_2 F_65 ( int V_72 , void * V_133 )
{
struct V_1 * V_2 = V_133 ;
struct V_13 * V_13 ;
V_25 V_134 ;
T_3 V_135 ;
int V_98 , V_136 ;
F_66 ( & V_2 -> V_23 ) ;
V_134 = F_40 ( V_2 , V_105 ) ;
if ( V_134 == 0 ) {
F_67 ( & V_2 -> V_23 ) ;
return V_137 ;
}
for ( V_98 = 0 ; V_98 < V_2 -> V_99 ; V_98 ++ ) {
V_13 = & V_2 -> V_13 [ V_98 ] ;
if ( V_134 & V_13 -> V_138 ) {
V_135 = F_53 ( V_13 , V_102 ) ;
F_52 ( V_13 , V_102 , V_101 ) ;
if ( ! V_13 -> V_139 || ! V_13 -> V_140 ||
! ( V_135 & V_141 ) )
continue;
V_136 = F_68 ( V_2 , V_13 ) ;
if ( V_136 == 1 ) {
V_13 -> V_142 = 0 ;
F_67 ( & V_2 -> V_23 ) ;
F_69 ( V_13 -> V_139 ) ;
F_66 ( & V_2 -> V_23 ) ;
} else if ( V_136 == 0 && V_2 -> V_53 && V_2 -> V_53 -> V_143 ) {
V_13 -> V_142 = 1 ;
F_70 ( V_2 -> V_53 -> V_143 ,
& V_2 -> V_144 ) ;
}
}
}
V_134 = F_23 ( V_2 , V_103 ) ;
if ( V_134 & V_104 ) {
if ( V_134 & V_145 ) {
if ( V_2 -> V_43 & V_146 )
F_34 ( 80 ) ;
F_25 ( V_2 ) ;
}
F_15 ( V_2 , V_103 , V_104 ) ;
}
#if 0
if (azx_readb(chip, STATESTS) & 0x04)
azx_writeb(chip, STATESTS, 0x04);
#endif
F_67 ( & V_2 -> V_23 ) ;
return V_147 ;
}
static int F_71 ( struct V_148 * V_139 ,
struct V_13 * V_13 , V_25 * * V_149 ,
int V_150 , int V_4 , int V_151 )
{
V_25 * V_152 = * V_149 ;
while ( V_4 > 0 ) {
T_4 V_3 ;
int V_153 ;
if ( V_13 -> V_154 >= V_155 )
return - V_156 ;
V_3 = F_72 ( V_139 , V_150 ) ;
V_152 [ 0 ] = F_24 ( ( V_25 ) V_3 ) ;
V_152 [ 1 ] = F_24 ( F_14 ( V_3 ) ) ;
V_153 = F_73 ( V_139 , V_150 , V_4 ) ;
V_152 [ 2 ] = F_24 ( V_153 ) ;
V_4 -= V_153 ;
V_152 [ 3 ] = ( V_4 || ! V_151 ) ? 0 : F_24 ( 0x01 ) ;
V_152 += 4 ;
V_13 -> V_154 ++ ;
V_150 += V_153 ;
}
* V_149 = V_152 ;
return V_150 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_148 * V_139 ,
struct V_13 * V_13 )
{
V_25 * V_152 ;
int V_98 , V_150 , V_157 , V_158 ;
int V_159 ;
F_75 ( V_13 , V_160 , 0 ) ;
F_75 ( V_13 , V_161 , 0 ) ;
V_158 = V_13 -> V_158 ;
V_157 = V_13 -> V_162 / V_158 ;
V_152 = ( V_25 * ) V_13 -> V_152 . V_11 ;
V_150 = 0 ;
V_13 -> V_154 = 0 ;
V_159 = V_163 [ V_2 -> V_164 ] ;
if ( V_159 > 0 ) {
struct V_14 * V_15 = V_139 -> V_15 ;
int V_165 = V_159 ;
V_159 = ( V_159 * V_15 -> V_166 + 47999 ) / 48000 ;
if ( ! V_159 )
V_159 = V_165 ;
else
V_159 = ( ( V_159 + V_165 - 1 ) / V_165 ) *
V_165 ;
V_159 = F_76 ( V_15 , V_159 ) ;
if ( V_159 >= V_158 ) {
F_10 (KERN_WARNING SFX L_21 ,
bdl_pos_adj[chip->dev_index]) ;
V_159 = 0 ;
} else {
V_150 = F_71 ( V_139 , V_13 ,
& V_152 , V_150 , V_159 ,
! V_139 -> V_15 -> V_167 ) ;
if ( V_150 < 0 )
goto error;
}
} else
V_159 = 0 ;
for ( V_98 = 0 ; V_98 < V_157 ; V_98 ++ ) {
if ( V_98 == V_157 - 1 && V_159 )
V_150 = F_71 ( V_139 , V_13 , & V_152 , V_150 ,
V_158 - V_159 , 0 ) ;
else
V_150 = F_71 ( V_139 , V_13 , & V_152 , V_150 ,
V_158 ,
! V_139 -> V_15 -> V_167 ) ;
if ( V_150 < 0 )
goto error;
}
return 0 ;
error:
F_10 (KERN_ERR SFX L_22 ,
azx_dev->bufsize, period_bytes) ;
return - V_156 ;
}
static void F_77 ( struct V_1 * V_2 , struct V_13 * V_13 )
{
unsigned char V_54 ;
int V_60 ;
F_56 ( V_2 , V_13 ) ;
F_52 ( V_13 , V_100 , F_53 ( V_13 , V_100 ) |
V_168 ) ;
F_34 ( 3 ) ;
V_60 = 300 ;
while ( ! ( ( V_54 = F_53 ( V_13 , V_100 ) ) & V_168 ) &&
-- V_60 )
;
V_54 &= ~ V_168 ;
F_52 ( V_13 , V_100 , V_54 ) ;
F_34 ( 3 ) ;
V_60 = 300 ;
while ( ( ( V_54 = F_53 ( V_13 , V_100 ) ) & V_168 ) &&
-- V_60 )
;
* V_13 -> V_112 = 0 ;
}
static int F_78 ( struct V_1 * V_2 , struct V_13 * V_13 )
{
unsigned int V_54 ;
F_56 ( V_2 , V_13 ) ;
V_54 = F_79 ( V_13 , V_100 ) ;
V_54 = ( V_54 & ~ V_169 ) |
( V_13 -> V_170 << V_171 ) ;
if ( ! F_2 ( V_2 ) )
V_54 |= V_172 ;
F_75 ( V_13 , V_100 , V_54 ) ;
F_75 ( V_13 , V_173 , V_13 -> V_162 ) ;
F_80 ( V_13 , V_174 , V_13 -> V_175 ) ;
F_80 ( V_13 , V_176 , V_13 -> V_154 - 1 ) ;
F_75 ( V_13 , V_160 , ( V_25 ) V_13 -> V_152 . V_3 ) ;
F_75 ( V_13 , V_161 , F_14 ( V_13 -> V_152 . V_3 ) ) ;
if ( V_2 -> V_177 [ 0 ] != V_178 ||
V_2 -> V_177 [ 1 ] != V_178 ) {
if ( ! ( F_40 ( V_2 , V_111 ) & V_179 ) )
F_13 ( V_2 , V_111 ,
( V_25 ) V_2 -> V_112 . V_3 | V_179 ) ;
}
F_75 ( V_13 , V_100 ,
F_79 ( V_13 , V_100 ) | V_101 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_49 = ( V_3 << 28 ) | ( V_180 << 20 ) |
( V_181 << 8 ) | V_182 ;
unsigned int V_51 ;
F_82 ( & V_2 -> V_53 -> V_183 ) ;
V_2 -> V_73 = 1 ;
F_47 ( V_2 -> V_53 , V_49 ) ;
V_51 = F_48 ( V_2 -> V_53 , V_3 ) ;
V_2 -> V_73 = 0 ;
F_83 ( & V_2 -> V_53 -> V_183 ) ;
if ( V_51 == - 1 )
return - V_84 ;
F_36 ( V_69 L_23 , V_3 ) ;
return 0 ;
}
static void F_84 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
V_53 -> V_76 = 1 ;
F_85 ( V_2 ) ;
F_58 ( V_2 , 1 ) ;
#ifdef F_86
if ( V_2 -> V_110 ) {
struct V_184 * V_185 ;
F_87 (p, &chip->pcm_list, list)
F_88 ( V_185 -> V_186 ) ;
F_89 ( V_2 -> V_53 ) ;
F_90 ( V_2 -> V_53 ) ;
}
#endif
V_53 -> V_76 = 0 ;
}
static int T_5 F_91 ( struct V_1 * V_2 , const char * V_187 )
{
struct V_188 V_189 ;
int V_190 , V_191 , V_19 ;
int V_192 ;
memset ( & V_189 , 0 , sizeof( V_189 ) ) ;
V_189 . V_55 = V_2 ;
V_189 . V_193 = V_187 ;
V_189 . V_21 = V_2 -> V_21 ;
V_189 . V_194 . V_195 = F_47 ;
V_189 . V_194 . V_196 = F_48 ;
V_189 . V_194 . V_197 = V_198 ;
V_189 . V_194 . V_199 = F_84 ;
#ifdef F_92
V_189 . V_200 = & V_200 ;
V_189 . V_194 . V_201 = V_202 ;
#endif
V_19 = F_93 ( V_2 -> V_203 , & V_189 , & V_2 -> V_53 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_2 -> V_43 & V_204 ) {
F_44 ( V_69 L_24 ) ;
V_2 -> V_53 -> V_68 = 1 ;
}
V_191 = 0 ;
V_192 = V_205 [ V_2 -> V_206 ] ;
if ( ! V_192 )
V_192 = V_207 ;
for ( V_190 = 0 ; V_190 < V_192 ; V_190 ++ ) {
if ( ( V_2 -> V_94 & ( 1 << V_190 ) ) & V_2 -> V_208 ) {
if ( F_81 ( V_2 , V_190 ) < 0 ) {
F_10 (KERN_WARNING SFX
L_25
L_26 , c) ;
V_2 -> V_94 &= ~ ( 1 << V_190 ) ;
F_85 ( V_2 ) ;
F_58 ( V_2 , 1 ) ;
}
}
}
if ( V_2 -> V_43 & V_209 ) {
F_44 ( V_69 L_27 ) ;
V_2 -> V_53 -> V_210 = 1 ;
V_2 -> V_53 -> V_74 = 1 ;
}
for ( V_190 = 0 ; V_190 < V_192 ; V_190 ++ ) {
if ( ( V_2 -> V_94 & ( 1 << V_190 ) ) & V_2 -> V_208 ) {
struct V_211 * V_212 ;
V_19 = F_94 ( V_2 -> V_53 , V_190 , & V_212 ) ;
if ( V_19 < 0 )
continue;
V_212 -> V_213 = V_2 -> V_213 ;
V_191 ++ ;
}
}
if ( ! V_191 ) {
F_10 (KERN_ERR SFX L_28 ) ;
return - V_214 ;
}
return 0 ;
}
static int T_5 F_95 ( struct V_1 * V_2 )
{
struct V_211 * V_212 ;
F_87 (codec, &chip->bus->codec_list, list) {
F_96 ( V_212 ) ;
}
return 0 ;
}
static inline struct V_13 *
F_97 ( struct V_1 * V_2 , struct V_148 * V_139 )
{
int V_215 , V_98 , V_216 ;
struct V_13 * V_51 = NULL ;
int V_217 = ( V_139 -> V_186 -> V_218 << 16 ) | ( V_139 -> V_219 << 2 ) |
( V_139 -> V_220 + 1 ) ;
if ( V_139 -> V_220 == V_221 ) {
V_215 = V_2 -> V_222 ;
V_216 = V_2 -> V_223 ;
} else {
V_215 = V_2 -> V_224 ;
V_216 = V_2 -> V_225 ;
}
for ( V_98 = 0 ; V_98 < V_216 ; V_98 ++ , V_215 ++ )
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
static int F_99 ( struct V_148 * V_139 )
{
struct V_184 * V_228 = F_100 ( V_139 ) ;
struct V_229 * V_230 = V_228 -> V_230 [ V_139 -> V_220 ] ;
struct V_1 * V_2 = V_228 -> V_2 ;
struct V_13 * V_13 ;
struct V_14 * V_15 = V_139 -> V_15 ;
unsigned long V_231 ;
int V_19 ;
int V_232 ;
F_82 ( & V_2 -> V_233 ) ;
V_13 = F_97 ( V_2 , V_139 ) ;
if ( V_13 == NULL ) {
F_83 ( & V_2 -> V_233 ) ;
return - V_93 ;
}
V_15 -> V_234 = V_235 ;
V_15 -> V_234 . V_236 = V_230 -> V_236 ;
V_15 -> V_234 . V_237 = V_230 -> V_237 ;
V_15 -> V_234 . V_238 = V_230 -> V_238 ;
V_15 -> V_234 . V_239 = V_230 -> V_239 ;
F_101 ( V_15 ) ;
F_102 ( V_15 , V_240 ) ;
if ( V_2 -> V_241 )
V_232 = 128 ;
else
V_232 = 4 ;
F_103 ( V_15 , 0 , V_242 ,
V_232 ) ;
F_103 ( V_15 , 0 , V_243 ,
V_232 ) ;
F_104 ( V_228 -> V_212 ) ;
V_19 = V_230 -> V_194 . V_244 ( V_230 , V_228 -> V_212 , V_139 ) ;
if ( V_19 < 0 ) {
F_98 ( V_13 ) ;
F_105 ( V_228 -> V_212 ) ;
F_83 ( & V_2 -> V_233 ) ;
return V_19 ;
}
F_101 ( V_15 ) ;
if ( F_106 ( ! V_15 -> V_234 . V_236 ) ||
F_106 ( ! V_15 -> V_234 . V_237 ) ||
F_106 ( ! V_15 -> V_234 . V_238 ) ||
F_106 ( ! V_15 -> V_234 . V_239 ) ) {
F_98 ( V_13 ) ;
V_230 -> V_194 . V_245 ( V_230 , V_228 -> V_212 , V_139 ) ;
F_105 ( V_228 -> V_212 ) ;
F_83 ( & V_2 -> V_233 ) ;
return - V_156 ;
}
F_107 ( & V_2 -> V_23 , V_231 ) ;
V_13 -> V_139 = V_139 ;
V_13 -> V_140 = 0 ;
F_108 ( & V_2 -> V_23 , V_231 ) ;
V_15 -> V_55 = V_13 ;
F_109 ( V_139 ) ;
F_83 ( & V_2 -> V_233 ) ;
return 0 ;
}
static int F_110 ( struct V_148 * V_139 )
{
struct V_184 * V_228 = F_100 ( V_139 ) ;
struct V_229 * V_230 = V_228 -> V_230 [ V_139 -> V_220 ] ;
struct V_1 * V_2 = V_228 -> V_2 ;
struct V_13 * V_13 = F_111 ( V_139 ) ;
unsigned long V_231 ;
F_82 ( & V_2 -> V_233 ) ;
F_107 ( & V_2 -> V_23 , V_231 ) ;
V_13 -> V_139 = NULL ;
V_13 -> V_140 = 0 ;
F_108 ( & V_2 -> V_23 , V_231 ) ;
F_98 ( V_13 ) ;
V_230 -> V_194 . V_245 ( V_230 , V_228 -> V_212 , V_139 ) ;
F_105 ( V_228 -> V_212 ) ;
F_83 ( & V_2 -> V_233 ) ;
return 0 ;
}
static int F_112 ( struct V_148 * V_139 ,
struct V_246 * V_247 )
{
struct V_184 * V_228 = F_100 ( V_139 ) ;
struct V_1 * V_2 = V_228 -> V_2 ;
struct V_14 * V_15 = V_139 -> V_15 ;
struct V_13 * V_13 = F_111 ( V_139 ) ;
int V_248 ;
F_6 ( V_2 , V_13 , V_15 , false ) ;
V_13 -> V_162 = 0 ;
V_13 -> V_158 = 0 ;
V_13 -> V_175 = 0 ;
V_248 = F_113 ( V_139 ,
F_114 ( V_247 ) ) ;
if ( V_248 < 0 )
return V_248 ;
F_6 ( V_2 , V_13 , V_15 , true ) ;
return V_248 ;
}
static int F_115 ( struct V_148 * V_139 )
{
struct V_184 * V_228 = F_100 ( V_139 ) ;
struct V_13 * V_13 = F_111 ( V_139 ) ;
struct V_1 * V_2 = V_228 -> V_2 ;
struct V_14 * V_15 = V_139 -> V_15 ;
struct V_229 * V_230 = V_228 -> V_230 [ V_139 -> V_220 ] ;
F_75 ( V_13 , V_160 , 0 ) ;
F_75 ( V_13 , V_161 , 0 ) ;
F_75 ( V_13 , V_100 , 0 ) ;
V_13 -> V_162 = 0 ;
V_13 -> V_158 = 0 ;
V_13 -> V_175 = 0 ;
F_116 ( V_228 -> V_212 , V_230 , V_139 ) ;
F_6 ( V_2 , V_13 , V_15 , false ) ;
return F_117 ( V_139 ) ;
}
static int F_118 ( struct V_148 * V_139 )
{
struct V_184 * V_228 = F_100 ( V_139 ) ;
struct V_1 * V_2 = V_228 -> V_2 ;
struct V_13 * V_13 = F_111 ( V_139 ) ;
struct V_229 * V_230 = V_228 -> V_230 [ V_139 -> V_220 ] ;
struct V_14 * V_15 = V_139 -> V_15 ;
unsigned int V_162 , V_158 , V_175 , V_170 ;
int V_19 ;
struct V_249 * V_250 =
F_119 ( V_228 -> V_212 , V_230 -> V_251 ) ;
unsigned short V_252 = V_250 ? V_250 -> V_252 : 0 ;
F_77 ( V_2 , V_13 ) ;
V_175 = F_120 ( V_15 -> V_166 ,
V_15 -> V_253 ,
V_15 -> V_254 ,
V_230 -> V_255 ,
V_252 ) ;
if ( ! V_175 ) {
F_10 (KERN_ERR SFX
L_29 ,
runtime->rate, runtime->channels, runtime->format) ;
return - V_156 ;
}
V_162 = F_121 ( V_139 ) ;
V_158 = F_122 ( V_139 ) ;
F_36 ( V_69 L_30 ,
V_162 , V_175 ) ;
if ( V_162 != V_13 -> V_162 ||
V_158 != V_13 -> V_158 ||
V_175 != V_13 -> V_175 ) {
V_13 -> V_162 = V_162 ;
V_13 -> V_158 = V_158 ;
V_13 -> V_175 = V_175 ;
V_19 = F_74 ( V_2 , V_139 , V_13 ) ;
if ( V_19 < 0 )
return V_19 ;
}
V_13 -> V_256 = ( ( ( V_15 -> V_257 * 24000 ) /
V_15 -> V_166 ) * 1000 ) ;
F_78 ( V_2 , V_13 ) ;
if ( V_139 -> V_220 == V_221 )
V_13 -> V_258 = F_123 ( V_13 , V_259 ) + 1 ;
else
V_13 -> V_258 = 0 ;
V_170 = V_13 -> V_170 ;
if ( ( V_2 -> V_43 & V_44 ) &&
V_170 > V_2 -> V_225 )
V_170 -= V_2 -> V_225 ;
return F_124 ( V_228 -> V_212 , V_230 , V_170 ,
V_13 -> V_175 , V_139 ) ;
}
static int F_125 ( struct V_148 * V_139 , int V_49 )
{
struct V_184 * V_228 = F_100 ( V_139 ) ;
struct V_1 * V_2 = V_228 -> V_2 ;
struct V_13 * V_13 ;
struct V_148 * V_260 ;
int V_261 = 0 , V_262 , V_263 = 0 , V_264 = 0 ;
int V_265 , V_60 ;
switch ( V_49 ) {
case V_266 :
V_261 = 1 ;
case V_267 :
case V_268 :
V_262 = 1 ;
break;
case V_269 :
case V_270 :
case V_271 :
V_262 = 0 ;
break;
default:
return - V_156 ;
}
F_126 (s, substream) {
if ( V_260 -> V_186 -> V_203 != V_139 -> V_186 -> V_203 )
continue;
V_13 = F_111 ( V_260 ) ;
V_264 |= 1 << V_13 -> V_108 ;
V_263 ++ ;
F_127 ( V_260 , V_139 ) ;
}
F_66 ( & V_2 -> V_23 ) ;
if ( V_263 > 1 ) {
if ( V_2 -> V_43 & V_272 )
F_13 ( V_2 , V_273 ,
F_40 ( V_2 , V_273 ) | V_264 ) ;
else
F_13 ( V_2 , V_274 , F_40 ( V_2 , V_274 ) | V_264 ) ;
}
F_126 (s, substream) {
if ( V_260 -> V_186 -> V_203 != V_139 -> V_186 -> V_203 )
continue;
V_13 = F_111 ( V_260 ) ;
if ( V_262 ) {
V_13 -> V_275 = F_40 ( V_2 , V_276 ) ;
if ( ! V_261 )
V_13 -> V_275 -=
V_13 -> V_256 ;
F_55 ( V_2 , V_13 ) ;
} else {
F_57 ( V_2 , V_13 ) ;
}
V_13 -> V_140 = V_262 ;
}
F_67 ( & V_2 -> V_23 ) ;
if ( V_262 ) {
if ( V_263 == 1 )
return 0 ;
for ( V_60 = 5000 ; V_60 ; V_60 -- ) {
V_265 = 0 ;
F_126 (s, substream) {
if ( V_260 -> V_186 -> V_203 != V_139 -> V_186 -> V_203 )
continue;
V_13 = F_111 ( V_260 ) ;
if ( ! ( F_53 ( V_13 , V_102 ) &
V_277 ) )
V_265 ++ ;
}
if ( ! V_265 )
break;
F_128 () ;
}
} else {
for ( V_60 = 5000 ; V_60 ; V_60 -- ) {
V_265 = 0 ;
F_126 (s, substream) {
if ( V_260 -> V_186 -> V_203 != V_139 -> V_186 -> V_203 )
continue;
V_13 = F_111 ( V_260 ) ;
if ( F_53 ( V_13 , V_100 ) &
V_109 )
V_265 ++ ;
}
if ( ! V_265 )
break;
F_128 () ;
}
}
if ( V_263 > 1 ) {
F_66 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_43 & V_272 )
F_13 ( V_2 , V_273 ,
F_40 ( V_2 , V_273 ) & ~ V_264 ) ;
else
F_13 ( V_2 , V_274 , F_40 ( V_2 , V_274 ) & ~ V_264 ) ;
F_67 ( & V_2 -> V_23 ) ;
}
return 0 ;
}
static unsigned int F_129 ( struct V_1 * V_2 ,
struct V_13 * V_13 )
{
unsigned int V_278 , V_279 , V_280 ;
unsigned int V_281 , V_282 , V_283 ;
unsigned int V_258 ;
V_278 = F_79 ( V_13 , V_284 ) ;
if ( V_13 -> V_139 -> V_220 == V_221 ) {
return V_278 ;
}
V_282 = F_26 ( * V_13 -> V_112 ) ;
V_282 %= V_13 -> V_158 ;
V_258 = F_130 ( V_2 -> V_285 + V_286 ) ;
if ( V_13 -> V_107 ) {
if ( V_278 <= V_258 )
return 0 ;
V_13 -> V_107 = 0 ;
}
if ( V_278 <= V_258 )
V_279 = V_13 -> V_162 + V_278 - V_258 ;
else
V_279 = V_278 - V_258 ;
V_283 = V_279 % V_13 -> V_158 ;
V_281 = V_278 % V_13 -> V_158 ;
if ( V_281 >= V_258 )
V_280 = V_278 - V_281 ;
else if ( V_282 >= V_283 )
V_280 = V_279 - V_283 ;
else {
V_280 = V_279 - V_283 + V_13 -> V_158 ;
if ( V_280 >= V_13 -> V_162 )
V_280 = 0 ;
}
return V_280 + V_282 ;
}
static unsigned int F_131 ( struct V_1 * V_2 ,
struct V_13 * V_13 ,
bool V_287 )
{
unsigned int V_288 ;
int V_220 = V_13 -> V_139 -> V_220 ;
switch ( V_2 -> V_177 [ V_220 ] ) {
case V_178 :
V_288 = F_79 ( V_13 , V_284 ) ;
break;
case V_289 :
V_288 = F_129 ( V_2 , V_13 ) ;
break;
default:
V_288 = F_26 ( * V_13 -> V_112 ) ;
if ( V_287 && V_2 -> V_177 [ V_220 ] == V_290 ) {
if ( ! V_288 || V_288 == ( V_25 ) - 1 ) {
F_132 ( V_291
L_31
L_32 ) ;
V_2 -> V_177 [ V_220 ] = V_178 ;
V_288 = F_79 ( V_13 , V_284 ) ;
} else
V_2 -> V_177 [ V_220 ] = V_292 ;
}
break;
}
if ( V_288 >= V_13 -> V_162 )
V_288 = 0 ;
return V_288 ;
}
static T_6 F_133 ( struct V_148 * V_139 )
{
struct V_184 * V_228 = F_100 ( V_139 ) ;
struct V_1 * V_2 = V_228 -> V_2 ;
struct V_13 * V_13 = F_111 ( V_139 ) ;
return F_134 ( V_139 -> V_15 ,
F_131 ( V_2 , V_13 , false ) ) ;
}
static int F_68 ( struct V_1 * V_2 , struct V_13 * V_13 )
{
V_25 V_293 ;
unsigned int V_288 ;
int V_220 ;
V_293 = F_40 ( V_2 , V_276 ) - V_13 -> V_275 ;
if ( V_293 < ( V_13 -> V_256 * 2 ) / 3 )
return - 1 ;
V_220 = V_13 -> V_139 -> V_220 ;
V_288 = F_131 ( V_2 , V_13 , true ) ;
if ( F_135 ( ! V_13 -> V_158 ,
L_33 ) )
return - 1 ;
if ( V_293 < ( V_13 -> V_256 * 5 ) / 4 &&
V_288 % V_13 -> V_158 > V_13 -> V_158 / 2 )
return V_163 [ V_2 -> V_164 ] ? 0 : - 1 ;
V_13 -> V_275 += V_293 ;
return 1 ;
}
static void F_136 ( struct V_294 * V_295 )
{
struct V_1 * V_2 = F_137 ( V_295 , struct V_1 , V_144 ) ;
int V_98 , V_296 , V_136 ;
if ( ! V_2 -> V_297 ) {
F_132 ( V_291
L_34
L_35 ,
V_2 -> V_203 -> V_219 ) ;
V_2 -> V_297 = 1 ;
}
for (; ; ) {
V_296 = 0 ;
F_12 ( & V_2 -> V_23 ) ;
for ( V_98 = 0 ; V_98 < V_2 -> V_99 ; V_98 ++ ) {
struct V_13 * V_13 = & V_2 -> V_13 [ V_98 ] ;
if ( ! V_13 -> V_142 ||
! V_13 -> V_139 ||
! V_13 -> V_140 )
continue;
V_136 = F_68 ( V_2 , V_13 ) ;
if ( V_136 > 0 ) {
V_13 -> V_142 = 0 ;
F_67 ( & V_2 -> V_23 ) ;
F_69 ( V_13 -> V_139 ) ;
F_66 ( & V_2 -> V_23 ) ;
} else if ( V_136 < 0 ) {
V_296 = 0 ;
} else
V_296 ++ ;
}
F_17 ( & V_2 -> V_23 ) ;
if ( ! V_296 )
return;
F_33 ( 1 ) ;
}
}
static void F_138 ( struct V_1 * V_2 )
{
int V_98 ;
F_12 ( & V_2 -> V_23 ) ;
for ( V_98 = 0 ; V_98 < V_2 -> V_99 ; V_98 ++ )
V_2 -> V_13 [ V_98 ] . V_142 = 0 ;
F_17 ( & V_2 -> V_23 ) ;
}
static int F_139 ( struct V_148 * V_139 ,
struct V_298 * V_11 )
{
struct V_184 * V_228 = F_100 ( V_139 ) ;
struct V_1 * V_2 = V_228 -> V_2 ;
if ( ! F_2 ( V_2 ) )
V_11 -> V_299 = F_140 ( V_11 -> V_299 ) ;
return F_141 ( V_139 , V_11 ) ;
}
static void F_142 ( struct V_300 * V_186 )
{
struct V_184 * V_228 = V_186 -> V_55 ;
if ( V_228 ) {
F_143 ( & V_228 -> V_301 ) ;
F_144 ( V_228 ) ;
}
}
static int
V_198 ( struct V_52 * V_53 , struct V_211 * V_212 ,
struct V_302 * V_303 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_300 * V_186 ;
struct V_184 * V_228 ;
int V_304 = V_303 -> V_218 ;
unsigned int V_4 ;
int V_260 , V_19 ;
F_87 (apcm, &chip->pcm_list, list) {
if ( V_228 -> V_186 -> V_218 == V_304 ) {
F_10 (KERN_ERR SFX L_36 , pcm_dev) ;
return - V_93 ;
}
}
V_19 = F_145 ( V_2 -> V_203 , V_303 -> V_305 , V_304 ,
V_303 -> V_220 [ V_221 ] . V_306 ,
V_303 -> V_220 [ V_307 ] . V_306 ,
& V_186 ) ;
if ( V_19 < 0 )
return V_19 ;
F_146 ( V_186 -> V_305 , V_303 -> V_305 , sizeof( V_186 -> V_305 ) ) ;
V_228 = F_147 ( sizeof( * V_228 ) , V_308 ) ;
if ( V_228 == NULL )
return - V_309 ;
V_228 -> V_2 = V_2 ;
V_228 -> V_186 = V_186 ;
V_228 -> V_212 = V_212 ;
V_186 -> V_55 = V_228 ;
V_186 -> V_310 = F_142 ;
if ( V_303 -> V_311 == V_312 )
V_186 -> V_313 = V_314 ;
F_148 ( & V_228 -> V_301 , & V_2 -> V_315 ) ;
V_303 -> V_186 = V_186 ;
for ( V_260 = 0 ; V_260 < 2 ; V_260 ++ ) {
V_228 -> V_230 [ V_260 ] = & V_303 -> V_220 [ V_260 ] ;
if ( V_303 -> V_220 [ V_260 ] . V_306 )
F_149 ( V_186 , V_260 , & V_316 ) ;
}
V_4 = V_317 * 1024 ;
if ( V_4 > V_318 )
V_4 = V_318 ;
F_150 ( V_186 , V_319 ,
F_9 ( V_2 -> V_21 ) ,
V_4 , V_318 ) ;
return 0 ;
}
static int T_5 F_151 ( struct V_1 * V_2 )
{
return F_152 ( V_2 -> V_53 ) ;
}
static int T_5 F_153 ( struct V_1 * V_2 )
{
int V_98 ;
for ( V_98 = 0 ; V_98 < V_2 -> V_99 ; V_98 ++ ) {
struct V_13 * V_13 = & V_2 -> V_13 [ V_98 ] ;
V_13 -> V_112 = ( V_25 V_320 * ) ( V_2 -> V_112 . V_11 + V_98 * 8 ) ;
V_13 -> V_321 = V_2 -> V_285 + ( 0x20 * V_98 + 0x80 ) ;
V_13 -> V_138 = 1 << V_98 ;
V_13 -> V_108 = V_98 ;
V_13 -> V_170 = V_98 + 1 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , int V_322 )
{
if ( F_154 ( V_2 -> V_21 -> V_72 , F_65 ,
V_2 -> V_71 ? 0 : V_323 ,
V_324 , V_2 ) ) {
F_132 ( V_77 L_37
L_38 , V_2 -> V_21 -> V_72 ) ;
if ( V_322 )
F_155 ( V_2 -> V_203 ) ;
return - 1 ;
}
V_2 -> V_72 = V_2 -> V_21 -> V_72 ;
F_156 ( V_2 -> V_21 , ! V_2 -> V_71 ) ;
return 0 ;
}
static void F_85 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_110 )
return;
F_51 ( V_2 ) ;
F_54 ( V_2 ) ;
F_18 ( V_2 ) ;
F_13 ( V_2 , V_111 , 0 ) ;
F_13 ( V_2 , V_113 , 0 ) ;
V_2 -> V_110 = 0 ;
}
static void V_202 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_211 * V_190 ;
int V_325 = 0 ;
F_87 (c, &bus->codec_list, list) {
if ( V_190 -> V_325 ) {
V_325 = 1 ;
break;
}
}
if ( V_325 )
F_58 ( V_2 , 1 ) ;
else if ( V_2 -> V_140 && V_326 &&
! V_53 -> V_327 )
F_85 ( V_2 ) ;
}
static int F_157 ( struct V_52 * V_53 )
{
struct V_211 * V_212 ;
F_87 (codec, &bus->codec_list, list) {
if ( F_158 ( V_212 ) )
return 1 ;
}
return 0 ;
}
static int F_159 ( struct V_114 * V_21 , T_7 V_328 )
{
struct V_329 * V_203 = F_160 ( V_21 ) ;
struct V_1 * V_2 = V_203 -> V_55 ;
struct V_184 * V_185 ;
F_161 ( V_203 , V_330 ) ;
F_138 ( V_2 ) ;
F_87 (p, &chip->pcm_list, list)
F_88 ( V_185 -> V_186 ) ;
if ( V_2 -> V_110 )
F_89 ( V_2 -> V_53 ) ;
F_85 ( V_2 ) ;
if ( V_2 -> V_72 >= 0 ) {
F_37 ( V_2 -> V_72 , V_2 ) ;
V_2 -> V_72 = - 1 ;
}
if ( V_2 -> V_71 )
F_38 ( V_2 -> V_21 ) ;
F_162 ( V_21 ) ;
F_163 ( V_21 ) ;
F_164 ( V_21 , F_165 ( V_21 , V_328 ) ) ;
return 0 ;
}
static int F_166 ( struct V_114 * V_21 )
{
struct V_329 * V_203 = F_160 ( V_21 ) ;
struct V_1 * V_2 = V_203 -> V_55 ;
F_164 ( V_21 , V_331 ) ;
F_167 ( V_21 ) ;
if ( F_168 ( V_21 ) < 0 ) {
F_132 ( V_77 L_39
L_38 ) ;
F_155 ( V_203 ) ;
return - V_84 ;
}
F_169 ( V_21 ) ;
if ( V_2 -> V_71 )
if ( F_170 ( V_21 ) < 0 )
V_2 -> V_71 = 0 ;
if ( F_39 ( V_2 , 1 ) < 0 )
return - V_84 ;
F_62 ( V_2 ) ;
if ( F_157 ( V_2 -> V_53 ) )
F_58 ( V_2 , 1 ) ;
F_90 ( V_2 -> V_53 ) ;
F_161 ( V_203 , V_332 ) ;
return 0 ;
}
static int F_171 ( struct V_333 * V_334 , unsigned long V_335 , void * V_10 )
{
struct V_1 * V_2 = F_137 ( V_334 , struct V_1 , V_336 ) ;
F_172 ( V_2 -> V_53 ) ;
F_85 ( V_2 ) ;
return V_337 ;
}
static void F_173 ( struct V_1 * V_2 )
{
V_2 -> V_336 . V_338 = F_171 ;
F_174 ( & V_2 -> V_336 ) ;
}
static void F_175 ( struct V_1 * V_2 )
{
if ( V_2 -> V_336 . V_338 )
F_176 ( & V_2 -> V_336 ) ;
}
static int F_177 ( struct V_1 * V_2 )
{
int V_98 ;
F_175 ( V_2 ) ;
if ( V_2 -> V_110 ) {
F_138 ( V_2 ) ;
for ( V_98 = 0 ; V_98 < V_2 -> V_99 ; V_98 ++ )
F_57 ( V_2 , & V_2 -> V_13 [ V_98 ] ) ;
F_85 ( V_2 ) ;
}
if ( V_2 -> V_72 >= 0 )
F_37 ( V_2 -> V_72 , ( void * ) V_2 ) ;
if ( V_2 -> V_71 )
F_38 ( V_2 -> V_21 ) ;
if ( V_2 -> V_285 )
F_178 ( V_2 -> V_285 ) ;
if ( V_2 -> V_13 ) {
for ( V_98 = 0 ; V_98 < V_2 -> V_99 ; V_98 ++ )
if ( V_2 -> V_13 [ V_98 ] . V_152 . V_11 ) {
F_5 ( V_2 , & V_2 -> V_13 [ V_98 ] . V_152 , false ) ;
F_179 ( & V_2 -> V_13 [ V_98 ] . V_152 ) ;
}
}
if ( V_2 -> V_22 . V_11 ) {
F_5 ( V_2 , & V_2 -> V_22 , false ) ;
F_179 ( & V_2 -> V_22 ) ;
}
if ( V_2 -> V_112 . V_11 ) {
F_5 ( V_2 , & V_2 -> V_112 , false ) ;
F_179 ( & V_2 -> V_112 ) ;
}
F_180 ( V_2 -> V_21 ) ;
F_162 ( V_2 -> V_21 ) ;
F_144 ( V_2 -> V_13 ) ;
F_144 ( V_2 ) ;
return 0 ;
}
static int F_181 ( struct V_339 * V_218 )
{
return F_177 ( V_218 -> V_340 ) ;
}
static int T_5 F_182 ( struct V_1 * V_2 , int V_341 )
{
const struct V_342 * V_343 ;
switch ( V_341 ) {
case V_178 :
case V_292 :
case V_289 :
case V_344 :
return V_341 ;
}
V_343 = F_183 ( V_2 -> V_21 , V_345 ) ;
if ( V_343 ) {
F_132 ( V_346
L_40
L_41 ,
V_343 -> V_347 , V_343 -> V_348 , V_343 -> V_349 ) ;
return V_343 -> V_347 ;
}
if ( V_2 -> V_43 & V_350 ) {
F_44 ( V_69 L_42 ) ;
return V_289 ;
}
if ( V_2 -> V_43 & V_351 ) {
F_44 ( V_69 L_43 ) ;
return V_178 ;
}
return V_290 ;
}
static void T_5 F_184 ( struct V_1 * V_2 , int V_215 )
{
const struct V_342 * V_343 ;
V_2 -> V_208 = V_352 [ V_215 ] ;
if ( V_2 -> V_208 == - 1 ) {
V_343 = F_183 ( V_2 -> V_21 , V_353 ) ;
if ( V_343 ) {
F_132 ( V_346
L_44
L_41 ,
V_343 -> V_347 , V_343 -> V_348 , V_343 -> V_349 ) ;
V_2 -> V_208 = V_343 -> V_347 ;
}
}
if ( V_2 -> V_208 != - 1 &&
( V_2 -> V_208 & V_354 ) ) {
V_2 -> V_94 = V_2 -> V_208 & 0xff ;
F_132 ( V_346 L_45 ,
V_2 -> V_94 ) ;
}
}
static void T_5 F_185 ( struct V_1 * V_2 )
{
const struct V_342 * V_343 ;
if ( V_355 >= 0 ) {
V_2 -> V_71 = ! ! V_355 ;
return;
}
V_2 -> V_71 = 1 ;
V_343 = F_183 ( V_2 -> V_21 , V_356 ) ;
if ( V_343 ) {
F_132 ( V_346
L_46 ,
V_343 -> V_348 , V_343 -> V_349 , V_343 -> V_347 ) ;
V_2 -> V_71 = V_343 -> V_347 ;
return;
}
if ( V_2 -> V_43 & V_357 ) {
F_132 ( V_346 L_47 ) ;
V_2 -> V_71 = 0 ;
}
}
static void T_5 F_186 ( struct V_1 * V_2 )
{
bool V_130 = V_2 -> V_130 ;
switch ( V_2 -> V_206 ) {
case V_358 :
if ( V_130 ) {
T_3 V_54 ;
F_60 ( V_2 -> V_21 , 0x42 , & V_54 ) ;
if ( ! ( V_54 & 0x80 ) && V_2 -> V_21 -> V_359 == 0x30 )
V_130 = false ;
}
break;
case V_360 :
V_130 = false ;
break;
}
if ( V_130 != V_2 -> V_130 ) {
F_10 (KERN_INFO SFX L_48 ,
snoop ? L_49 : L_50 ) ;
V_2 -> V_130 = V_130 ;
}
}
static int T_5 F_187 ( struct V_329 * V_203 , struct V_114 * V_21 ,
int V_215 , unsigned int V_43 ,
struct V_1 * * V_361 )
{
struct V_1 * V_2 ;
int V_98 , V_19 ;
unsigned short V_362 ;
static struct V_363 V_194 = {
. V_364 = F_181 ,
} ;
* V_361 = NULL ;
V_19 = F_168 ( V_21 ) ;
if ( V_19 < 0 )
return V_19 ;
V_2 = F_147 ( sizeof( * V_2 ) , V_308 ) ;
if ( ! V_2 ) {
F_10 (KERN_ERR SFX L_51 ) ;
F_162 ( V_21 ) ;
return - V_309 ;
}
F_188 ( & V_2 -> V_23 ) ;
F_189 ( & V_2 -> V_233 ) ;
V_2 -> V_203 = V_203 ;
V_2 -> V_21 = V_21 ;
V_2 -> V_72 = - 1 ;
V_2 -> V_43 = V_43 ;
V_2 -> V_206 = V_43 & 0xff ;
F_185 ( V_2 ) ;
V_2 -> V_164 = V_215 ;
F_190 ( & V_2 -> V_144 , F_136 ) ;
F_191 ( & V_2 -> V_315 ) ;
V_2 -> V_177 [ 0 ] = V_2 -> V_177 [ 1 ] =
F_182 ( V_2 , V_177 [ V_215 ] ) ;
if ( V_2 -> V_177 [ 0 ] == V_344 ) {
V_2 -> V_177 [ 0 ] = V_178 ;
V_2 -> V_177 [ 1 ] = V_290 ;
}
F_184 ( V_2 , V_215 ) ;
V_2 -> V_78 = V_78 ;
V_2 -> V_130 = V_365 ;
F_186 ( V_2 ) ;
if ( V_163 [ V_215 ] < 0 ) {
switch ( V_2 -> V_206 ) {
case V_366 :
case V_367 :
V_163 [ V_215 ] = 1 ;
break;
default:
V_163 [ V_215 ] = 32 ;
break;
}
}
#if V_368 != 64
if ( V_2 -> V_206 == V_369 ) {
T_8 V_370 ;
F_63 ( V_21 , 0x40 , & V_370 ) ;
F_64 ( V_21 , 0x40 , V_370 | 0x10 ) ;
F_192 ( V_21 , V_371 , 0 ) ;
}
#endif
V_19 = F_193 ( V_21 , L_52 ) ;
if ( V_19 < 0 ) {
F_144 ( V_2 ) ;
F_162 ( V_21 ) ;
return V_19 ;
}
V_2 -> V_3 = F_194 ( V_21 , 0 ) ;
V_2 -> V_285 = F_195 ( V_21 , 0 ) ;
if ( V_2 -> V_285 == NULL ) {
F_10 (KERN_ERR SFX L_53 ) ;
V_19 = - V_214 ;
goto V_372;
}
if ( V_2 -> V_71 )
if ( F_170 ( V_21 ) < 0 )
V_2 -> V_71 = 0 ;
if ( F_39 ( V_2 , 0 ) < 0 ) {
V_19 = - V_93 ;
goto V_372;
}
F_169 ( V_21 ) ;
F_196 ( V_2 -> V_72 ) ;
V_362 = F_42 ( V_2 , V_373 ) ;
F_36 ( V_69 L_54 , V_362 ) ;
if ( V_2 -> V_21 -> V_374 == V_375 ) {
struct V_114 * V_376 ;
V_376 = F_197 ( V_375 ,
V_377 ,
NULL ) ;
if ( V_376 ) {
if ( V_376 -> V_359 < 0x30 )
V_362 &= ~ V_378 ;
F_198 ( V_376 ) ;
}
}
if ( V_2 -> V_43 & V_379 ) {
F_44 ( V_69 L_55 ) ;
V_362 &= ~ V_378 ;
}
if ( V_241 >= 0 )
V_2 -> V_241 = ! ! V_241 ;
else {
if ( V_2 -> V_43 & V_380 )
V_2 -> V_241 = 0 ;
else if ( V_2 -> V_43 & V_381 )
V_2 -> V_241 = 1 ;
else
V_2 -> V_241 = 1 ;
}
if ( ( V_362 & V_378 ) && ! F_199 ( V_21 , F_200 ( 64 ) ) )
F_201 ( V_21 , F_200 ( 64 ) ) ;
else {
F_199 ( V_21 , F_200 ( 32 ) ) ;
F_201 ( V_21 , F_200 ( 32 ) ) ;
}
V_2 -> V_225 = ( V_362 >> 8 ) & 0x0f ;
V_2 -> V_223 = ( V_362 >> 12 ) & 0x0f ;
if ( ! V_2 -> V_223 && ! V_2 -> V_225 ) {
switch ( V_2 -> V_206 ) {
case V_369 :
V_2 -> V_223 = V_382 ;
V_2 -> V_225 = V_383 ;
break;
case V_384 :
case V_360 :
V_2 -> V_223 = V_385 ;
V_2 -> V_225 = V_386 ;
break;
case V_387 :
default:
V_2 -> V_223 = V_388 ;
V_2 -> V_225 = V_389 ;
break;
}
}
V_2 -> V_224 = 0 ;
V_2 -> V_222 = V_2 -> V_225 ;
V_2 -> V_99 = V_2 -> V_223 + V_2 -> V_225 ;
V_2 -> V_13 = F_202 ( V_2 -> V_99 , sizeof( * V_2 -> V_13 ) ,
V_308 ) ;
if ( ! V_2 -> V_13 ) {
F_10 (KERN_ERR SFX L_56 ) ;
goto V_372;
}
for ( V_98 = 0 ; V_98 < V_2 -> V_99 ; V_98 ++ ) {
V_19 = F_8 ( V_20 ,
F_9 ( V_2 -> V_21 ) ,
V_390 , & V_2 -> V_13 [ V_98 ] . V_152 ) ;
if ( V_19 < 0 ) {
F_10 (KERN_ERR SFX L_57 ) ;
goto V_372;
}
F_5 ( V_2 , & V_2 -> V_13 [ V_98 ] . V_152 , true ) ;
}
V_19 = F_8 ( V_20 ,
F_9 ( V_2 -> V_21 ) ,
V_2 -> V_99 * 8 , & V_2 -> V_112 ) ;
if ( V_19 < 0 ) {
F_10 (KERN_ERR SFX L_58 ) ;
goto V_372;
}
F_5 ( V_2 , & V_2 -> V_112 , true ) ;
V_19 = F_7 ( V_2 ) ;
if ( V_19 < 0 )
goto V_372;
F_153 ( V_2 ) ;
F_62 ( V_2 ) ;
F_58 ( V_2 , ( V_391 [ V_215 ] & 2 ) == 0 ) ;
if ( ! V_2 -> V_94 ) {
F_10 (KERN_ERR SFX L_59 ) ;
V_19 = - V_392 ;
goto V_372;
}
V_19 = F_203 ( V_203 , V_393 , V_2 , & V_194 ) ;
if ( V_19 < 0 ) {
F_10 (KERN_ERR SFX L_60 ) ;
goto V_372;
}
strcpy ( V_203 -> V_394 , L_61 ) ;
F_146 ( V_203 -> V_395 , V_396 [ V_2 -> V_206 ] ,
sizeof( V_203 -> V_395 ) ) ;
snprintf ( V_203 -> V_397 , sizeof( V_203 -> V_397 ) ,
L_62 ,
V_203 -> V_395 , V_2 -> V_3 , V_2 -> V_72 ) ;
* V_361 = V_2 ;
return 0 ;
V_372:
F_177 ( V_2 ) ;
return V_19 ;
}
static void F_204 ( struct V_1 * V_2 )
{
#ifdef F_92
struct V_211 * V_212 ;
F_87 (codec, &chip->bus->codec_list, list) {
F_105 ( V_212 ) ;
}
#endif
}
static int T_5 F_205 ( struct V_114 * V_21 ,
const struct V_398 * V_399 )
{
static int V_215 ;
struct V_329 * V_203 ;
struct V_1 * V_2 ;
int V_19 ;
if ( V_215 >= V_400 )
return - V_392 ;
if ( ! V_401 [ V_215 ] ) {
V_215 ++ ;
return - V_402 ;
}
V_19 = F_206 ( V_108 [ V_215 ] , V_403 [ V_215 ] , V_404 , 0 , & V_203 ) ;
if ( V_19 < 0 ) {
F_10 (KERN_ERR SFX L_63 ) ;
return V_19 ;
}
F_207 ( V_203 , & V_21 -> V_215 ) ;
V_19 = F_187 ( V_203 , V_21 , V_215 , V_399 -> V_405 , & V_2 ) ;
if ( V_19 < 0 )
goto V_406;
V_203 -> V_55 = V_2 ;
#ifdef F_208
V_2 -> V_213 = V_213 [ V_215 ] ;
#endif
V_19 = F_91 ( V_2 , V_187 [ V_215 ] ) ;
if ( V_19 < 0 )
goto V_406;
#ifdef F_209
if ( V_407 [ V_215 ] && * V_407 [ V_215 ] ) {
F_10 (KERN_ERR SFX L_64 ,
patch[dev]) ;
V_19 = F_210 ( V_2 -> V_53 , V_407 [ V_215 ] ) ;
if ( V_19 < 0 )
goto V_406;
}
#endif
if ( ( V_391 [ V_215 ] & 1 ) == 0 ) {
V_19 = F_95 ( V_2 ) ;
if ( V_19 < 0 )
goto V_406;
}
V_19 = F_211 ( V_2 -> V_53 ) ;
if ( V_19 < 0 )
goto V_406;
V_19 = F_151 ( V_2 ) ;
if ( V_19 < 0 )
goto V_406;
V_19 = F_212 ( V_203 ) ;
if ( V_19 < 0 )
goto V_406;
F_213 ( V_21 , V_203 ) ;
V_2 -> V_140 = 1 ;
F_204 ( V_2 ) ;
F_173 ( V_2 ) ;
V_215 ++ ;
return V_19 ;
V_406:
F_214 ( V_203 ) ;
return V_19 ;
}
static void T_9 F_215 ( struct V_114 * V_21 )
{
F_214 ( F_160 ( V_21 ) ) ;
F_213 ( V_21 , NULL ) ;
}
static int T_10 F_216 ( void )
{
return F_217 ( & V_394 ) ;
}
static void T_11 F_218 ( void )
{
F_219 ( & V_394 ) ;
}
