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
if ( V_2 -> V_87 )
return 0 ;
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
if ( V_2 -> V_87 )
return 0 ;
if ( V_2 -> V_78 )
return F_46 ( V_53 , V_3 ) ;
else
return F_29 ( V_53 , V_3 ) ;
}
static int F_49 ( struct V_1 * V_2 , int V_88 )
{
int V_89 ;
if ( ! V_88 )
goto V_90;
F_15 ( V_2 , V_91 , V_92 ) ;
F_13 ( V_2 , V_79 , F_40 ( V_2 , V_79 ) & ~ V_93 ) ;
V_89 = 50 ;
while ( F_23 ( V_2 , V_79 ) && -- V_89 )
F_33 ( 1 ) ;
F_33 ( 1 ) ;
F_15 ( V_2 , V_79 , F_23 ( V_2 , V_79 ) | V_93 ) ;
V_89 = 50 ;
while ( ! F_23 ( V_2 , V_79 ) && -- V_89 )
F_33 ( 1 ) ;
F_33 ( 1 ) ;
V_90:
if ( ! F_23 ( V_2 , V_79 ) ) {
F_44 ( V_69 L_13 ) ;
return - V_94 ;
}
if ( ! V_2 -> V_78 )
F_13 ( V_2 , V_79 , F_40 ( V_2 , V_79 ) |
V_80 ) ;
if ( ! V_2 -> V_95 ) {
V_2 -> V_95 = F_42 ( V_2 , V_91 ) ;
F_36 ( V_69 L_14 , V_2 -> V_95 ) ;
}
return 0 ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_13 ( V_2 , V_96 , F_40 ( V_2 , V_96 ) |
V_97 | V_98 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
int V_99 ;
for ( V_99 = 0 ; V_99 < V_2 -> V_100 ; V_99 ++ ) {
struct V_13 * V_13 = & V_2 -> V_13 [ V_99 ] ;
F_52 ( V_13 , V_101 ,
F_53 ( V_13 , V_101 ) & ~ V_102 ) ;
}
F_15 ( V_2 , V_96 , 0 ) ;
F_13 ( V_2 , V_96 , F_40 ( V_2 , V_96 ) &
~ ( V_97 | V_98 ) ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
int V_99 ;
for ( V_99 = 0 ; V_99 < V_2 -> V_100 ; V_99 ++ ) {
struct V_13 * V_13 = & V_2 -> V_13 [ V_99 ] ;
F_52 ( V_13 , V_103 , V_102 ) ;
}
F_15 ( V_2 , V_91 , V_92 ) ;
F_15 ( V_2 , V_104 , V_105 ) ;
F_13 ( V_2 , V_106 , V_97 | V_107 ) ;
}
static void F_55 ( struct V_1 * V_2 , struct V_13 * V_13 )
{
V_13 -> V_108 = 1 ;
F_13 ( V_2 , V_96 ,
F_40 ( V_2 , V_96 ) | ( 1 << V_13 -> V_109 ) ) ;
F_52 ( V_13 , V_101 , F_53 ( V_13 , V_101 ) |
V_110 | V_102 ) ;
}
static void F_56 ( struct V_1 * V_2 , struct V_13 * V_13 )
{
F_52 ( V_13 , V_101 , F_53 ( V_13 , V_101 ) &
~ ( V_110 | V_102 ) ) ;
F_52 ( V_13 , V_103 , V_102 ) ;
}
static void F_57 ( struct V_1 * V_2 , struct V_13 * V_13 )
{
F_56 ( V_2 , V_13 ) ;
F_13 ( V_2 , V_96 ,
F_40 ( V_2 , V_96 ) & ~ ( 1 << V_13 -> V_109 ) ) ;
}
static void F_58 ( struct V_1 * V_2 , int V_88 )
{
if ( V_2 -> V_111 )
return;
F_49 ( V_2 , V_88 ) ;
F_54 ( V_2 ) ;
F_50 ( V_2 ) ;
if ( ! V_2 -> V_78 )
F_11 ( V_2 ) ;
F_13 ( V_2 , V_112 , ( V_25 ) V_2 -> V_113 . V_3 ) ;
F_13 ( V_2 , V_114 , F_14 ( V_2 -> V_113 . V_3 ) ) ;
V_2 -> V_111 = 1 ;
}
static void F_59 ( struct V_115 * V_21 , unsigned int V_116 ,
unsigned char V_117 , unsigned char V_54 )
{
unsigned char V_118 ;
F_60 ( V_21 , V_116 , & V_118 ) ;
V_118 &= ~ V_117 ;
V_118 |= ( V_54 & V_117 ) ;
F_61 ( V_21 , V_116 , V_118 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_43 & V_119 ) ) {
F_36 ( V_69 L_15 ) ;
F_59 ( V_2 -> V_21 , V_120 , 0x07 , 0 ) ;
}
if ( V_2 -> V_43 & V_121 ) {
F_36 ( V_69 L_16 , F_2 ( V_2 ) ) ;
F_59 ( V_2 -> V_21 ,
V_122 , 0x07 ,
F_2 ( V_2 ) ? V_123 : 0 ) ;
}
if ( V_2 -> V_43 & V_124 ) {
F_36 ( V_69 L_17 , F_2 ( V_2 ) ) ;
F_59 ( V_2 -> V_21 ,
V_125 ,
0x0f , V_126 ) ;
F_59 ( V_2 -> V_21 ,
V_127 ,
0x01 , V_128 ) ;
F_59 ( V_2 -> V_21 ,
V_129 ,
0x01 , V_128 ) ;
}
if ( V_2 -> V_43 & V_130 ) {
unsigned short V_131 ;
F_63 ( V_2 -> V_21 , V_132 , & V_131 ) ;
if ( ( ! F_2 ( V_2 ) && ! ( V_131 & V_133 ) ) ||
( F_2 ( V_2 ) && ( V_131 & V_133 ) ) ) {
V_131 &= ~ V_133 ;
if ( ! F_2 ( V_2 ) )
V_131 |= V_133 ;
F_64 ( V_2 -> V_21 , V_132 , V_131 ) ;
F_63 ( V_2 -> V_21 ,
V_132 , & V_131 ) ;
}
F_36 ( V_69 L_18 ,
( V_131 & V_133 )
? L_19 : L_20 ) ;
}
}
static T_2 F_65 ( int V_72 , void * V_134 )
{
struct V_1 * V_2 = V_134 ;
struct V_13 * V_13 ;
V_25 V_135 ;
T_3 V_136 ;
int V_99 , V_137 ;
#ifdef F_66
if ( V_2 -> V_21 -> V_138 . V_139 . V_140 != V_141 )
return V_142 ;
#endif
F_67 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_87 ) {
F_68 ( & V_2 -> V_23 ) ;
return V_142 ;
}
V_135 = F_40 ( V_2 , V_106 ) ;
if ( V_135 == 0 ) {
F_68 ( & V_2 -> V_23 ) ;
return V_142 ;
}
for ( V_99 = 0 ; V_99 < V_2 -> V_100 ; V_99 ++ ) {
V_13 = & V_2 -> V_13 [ V_99 ] ;
if ( V_135 & V_13 -> V_143 ) {
V_136 = F_53 ( V_13 , V_103 ) ;
F_52 ( V_13 , V_103 , V_102 ) ;
if ( ! V_13 -> V_144 || ! V_13 -> V_145 ||
! ( V_136 & V_146 ) )
continue;
V_137 = F_69 ( V_2 , V_13 ) ;
if ( V_137 == 1 ) {
V_13 -> V_147 = 0 ;
F_68 ( & V_2 -> V_23 ) ;
F_70 ( V_13 -> V_144 ) ;
F_67 ( & V_2 -> V_23 ) ;
} else if ( V_137 == 0 && V_2 -> V_53 && V_2 -> V_53 -> V_148 ) {
V_13 -> V_147 = 1 ;
F_71 ( V_2 -> V_53 -> V_148 ,
& V_2 -> V_149 ) ;
}
}
}
V_135 = F_23 ( V_2 , V_104 ) ;
if ( V_135 & V_105 ) {
if ( V_135 & V_150 ) {
if ( V_2 -> V_43 & V_151 )
F_34 ( 80 ) ;
F_25 ( V_2 ) ;
}
F_15 ( V_2 , V_104 , V_105 ) ;
}
#if 0
if (azx_readb(chip, STATESTS) & 0x04)
azx_writeb(chip, STATESTS, 0x04);
#endif
F_68 ( & V_2 -> V_23 ) ;
return V_152 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_153 * V_144 ,
struct V_13 * V_13 , V_25 * * V_154 ,
int V_155 , int V_4 , int V_156 )
{
V_25 * V_157 = * V_154 ;
while ( V_4 > 0 ) {
T_4 V_3 ;
int V_158 ;
if ( V_13 -> V_159 >= V_160 )
return - V_161 ;
V_3 = F_73 ( V_144 , V_155 ) ;
V_157 [ 0 ] = F_24 ( ( V_25 ) V_3 ) ;
V_157 [ 1 ] = F_24 ( F_14 ( V_3 ) ) ;
V_158 = F_74 ( V_144 , V_155 , V_4 ) ;
if ( V_2 -> V_43 & V_162 ) {
V_25 V_163 = 0x1000 - ( V_155 & 0xfff ) ;
if ( V_158 > V_163 )
V_158 = V_163 ;
}
V_157 [ 2 ] = F_24 ( V_158 ) ;
V_4 -= V_158 ;
V_157 [ 3 ] = ( V_4 || ! V_156 ) ? 0 : F_24 ( 0x01 ) ;
V_157 += 4 ;
V_13 -> V_159 ++ ;
V_155 += V_158 ;
}
* V_154 = V_157 ;
return V_155 ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_153 * V_144 ,
struct V_13 * V_13 )
{
V_25 * V_157 ;
int V_99 , V_155 , V_164 , V_165 ;
int V_166 ;
F_76 ( V_13 , V_167 , 0 ) ;
F_76 ( V_13 , V_168 , 0 ) ;
V_165 = V_13 -> V_165 ;
V_164 = V_13 -> V_169 / V_165 ;
V_157 = ( V_25 * ) V_13 -> V_157 . V_11 ;
V_155 = 0 ;
V_13 -> V_159 = 0 ;
V_166 = V_170 [ V_2 -> V_171 ] ;
if ( ! V_13 -> V_172 && V_166 > 0 ) {
struct V_14 * V_15 = V_144 -> V_15 ;
int V_173 = V_166 ;
V_166 = ( V_166 * V_15 -> V_174 + 47999 ) / 48000 ;
if ( ! V_166 )
V_166 = V_173 ;
else
V_166 = ( ( V_166 + V_173 - 1 ) / V_173 ) *
V_173 ;
V_166 = F_77 ( V_15 , V_166 ) ;
if ( V_166 >= V_165 ) {
F_10 (KERN_WARNING SFX L_21 ,
bdl_pos_adj[chip->dev_index]) ;
V_166 = 0 ;
} else {
V_155 = F_72 ( V_2 , V_144 , V_13 ,
& V_157 , V_155 , V_166 , true ) ;
if ( V_155 < 0 )
goto error;
}
} else
V_166 = 0 ;
for ( V_99 = 0 ; V_99 < V_164 ; V_99 ++ ) {
if ( V_99 == V_164 - 1 && V_166 )
V_155 = F_72 ( V_2 , V_144 , V_13 , & V_157 , V_155 ,
V_165 - V_166 , 0 ) ;
else
V_155 = F_72 ( V_2 , V_144 , V_13 , & V_157 , V_155 ,
V_165 ,
! V_13 -> V_172 ) ;
if ( V_155 < 0 )
goto error;
}
return 0 ;
error:
F_10 (KERN_ERR SFX L_22 ,
azx_dev->bufsize, period_bytes) ;
return - V_161 ;
}
static void F_78 ( struct V_1 * V_2 , struct V_13 * V_13 )
{
unsigned char V_54 ;
int V_60 ;
F_56 ( V_2 , V_13 ) ;
F_52 ( V_13 , V_101 , F_53 ( V_13 , V_101 ) |
V_175 ) ;
F_34 ( 3 ) ;
V_60 = 300 ;
while ( ! ( ( V_54 = F_53 ( V_13 , V_101 ) ) & V_175 ) &&
-- V_60 )
;
V_54 &= ~ V_175 ;
F_52 ( V_13 , V_101 , V_54 ) ;
F_34 ( 3 ) ;
V_60 = 300 ;
while ( ( ( V_54 = F_53 ( V_13 , V_101 ) ) & V_175 ) &&
-- V_60 )
;
* V_13 -> V_113 = 0 ;
}
static int F_79 ( struct V_1 * V_2 , struct V_13 * V_13 )
{
unsigned int V_54 ;
F_56 ( V_2 , V_13 ) ;
V_54 = F_80 ( V_13 , V_101 ) ;
V_54 = ( V_54 & ~ V_176 ) |
( V_13 -> V_177 << V_178 ) ;
if ( ! F_2 ( V_2 ) )
V_54 |= V_179 ;
F_76 ( V_13 , V_101 , V_54 ) ;
F_76 ( V_13 , V_180 , V_13 -> V_169 ) ;
F_81 ( V_13 , V_181 , V_13 -> V_182 ) ;
F_81 ( V_13 , V_183 , V_13 -> V_159 - 1 ) ;
F_76 ( V_13 , V_167 , ( V_25 ) V_13 -> V_157 . V_3 ) ;
F_76 ( V_13 , V_168 , F_14 ( V_13 -> V_157 . V_3 ) ) ;
if ( V_2 -> V_184 [ 0 ] != V_185 ||
V_2 -> V_184 [ 1 ] != V_185 ) {
if ( ! ( F_40 ( V_2 , V_112 ) & V_186 ) )
F_13 ( V_2 , V_112 ,
( V_25 ) V_2 -> V_113 . V_3 | V_186 ) ;
}
F_76 ( V_13 , V_101 ,
F_80 ( V_13 , V_101 ) | V_102 ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_49 = ( V_3 << 28 ) | ( V_187 << 20 ) |
( V_188 << 8 ) | V_189 ;
unsigned int V_51 ;
F_83 ( & V_2 -> V_53 -> V_190 ) ;
V_2 -> V_73 = 1 ;
F_47 ( V_2 -> V_53 , V_49 ) ;
V_51 = F_48 ( V_2 -> V_53 , V_3 ) ;
V_2 -> V_73 = 0 ;
F_84 ( & V_2 -> V_53 -> V_190 ) ;
if ( V_51 == - 1 )
return - V_84 ;
F_36 ( V_69 L_23 , V_3 ) ;
return 0 ;
}
static void F_85 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
V_53 -> V_76 = 1 ;
F_86 ( V_2 ) ;
F_58 ( V_2 , 1 ) ;
#ifdef F_87
if ( V_2 -> V_111 ) {
struct V_191 * V_192 ;
F_88 (p, &chip->pcm_list, list)
F_89 ( V_192 -> V_193 ) ;
F_90 ( V_2 -> V_53 ) ;
F_91 ( V_2 -> V_53 ) ;
}
#endif
V_53 -> V_76 = 0 ;
}
static int T_5 F_92 ( struct V_1 * V_2 , const char * V_194 )
{
struct V_195 V_196 ;
int V_197 , V_198 , V_19 ;
int V_199 ;
memset ( & V_196 , 0 , sizeof( V_196 ) ) ;
V_196 . V_55 = V_2 ;
V_196 . V_200 = V_194 ;
V_196 . V_21 = V_2 -> V_21 ;
V_196 . V_201 . V_202 = F_47 ;
V_196 . V_201 . V_203 = F_48 ;
V_196 . V_201 . V_204 = V_205 ;
V_196 . V_201 . V_206 = F_85 ;
#ifdef F_87
V_196 . V_207 = & V_207 ;
V_196 . V_201 . V_208 = V_209 ;
#endif
V_19 = F_93 ( V_2 -> V_210 , & V_196 , & V_2 -> V_53 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_2 -> V_43 & V_211 ) {
F_44 ( V_69 L_24 ) ;
V_2 -> V_53 -> V_68 = 1 ;
}
V_198 = 0 ;
V_199 = V_212 [ V_2 -> V_213 ] ;
if ( ! V_199 )
V_199 = V_214 ;
for ( V_197 = 0 ; V_197 < V_199 ; V_197 ++ ) {
if ( ( V_2 -> V_95 & ( 1 << V_197 ) ) & V_2 -> V_215 ) {
if ( F_82 ( V_2 , V_197 ) < 0 ) {
F_10 (KERN_WARNING SFX
L_25
L_26 , c) ;
V_2 -> V_95 &= ~ ( 1 << V_197 ) ;
F_86 ( V_2 ) ;
F_58 ( V_2 , 1 ) ;
}
}
}
if ( V_2 -> V_43 & V_216 ) {
F_44 ( V_69 L_27 ) ;
V_2 -> V_53 -> V_217 = 1 ;
V_2 -> V_53 -> V_74 = 1 ;
}
for ( V_197 = 0 ; V_197 < V_199 ; V_197 ++ ) {
if ( ( V_2 -> V_95 & ( 1 << V_197 ) ) & V_2 -> V_215 ) {
struct V_218 * V_219 ;
V_19 = F_94 ( V_2 -> V_53 , V_197 , & V_219 ) ;
if ( V_19 < 0 )
continue;
V_219 -> V_220 = V_2 -> V_220 ;
V_198 ++ ;
}
}
if ( ! V_198 ) {
F_10 (KERN_ERR SFX L_28 ) ;
return - V_221 ;
}
return 0 ;
}
static int T_6 F_95 ( struct V_1 * V_2 )
{
struct V_218 * V_219 ;
F_88 (codec, &chip->bus->codec_list, list) {
F_96 ( V_219 ) ;
}
return 0 ;
}
static inline struct V_13 *
F_97 ( struct V_1 * V_2 , struct V_153 * V_144 )
{
int V_138 , V_99 , V_222 ;
struct V_13 * V_51 = NULL ;
int V_223 = ( V_144 -> V_193 -> V_224 << 16 ) | ( V_144 -> V_225 << 2 ) |
( V_144 -> V_226 + 1 ) ;
if ( V_144 -> V_226 == V_227 ) {
V_138 = V_2 -> V_228 ;
V_222 = V_2 -> V_229 ;
} else {
V_138 = V_2 -> V_230 ;
V_222 = V_2 -> V_231 ;
}
for ( V_99 = 0 ; V_99 < V_222 ; V_99 ++ , V_138 ++ )
if ( ! V_2 -> V_13 [ V_138 ] . V_232 ) {
V_51 = & V_2 -> V_13 [ V_138 ] ;
if ( V_51 -> V_233 == V_223 )
break;
}
if ( V_51 ) {
V_51 -> V_232 = 1 ;
V_51 -> V_233 = V_223 ;
}
return V_51 ;
}
static inline void F_98 ( struct V_13 * V_13 )
{
V_13 -> V_232 = 0 ;
}
static int F_99 ( struct V_153 * V_144 )
{
struct V_191 * V_234 = F_100 ( V_144 ) ;
struct V_235 * V_236 = V_234 -> V_236 [ V_144 -> V_226 ] ;
struct V_1 * V_2 = V_234 -> V_2 ;
struct V_13 * V_13 ;
struct V_14 * V_15 = V_144 -> V_15 ;
unsigned long V_237 ;
int V_19 ;
int V_238 ;
F_83 ( & V_2 -> V_239 ) ;
V_13 = F_97 ( V_2 , V_144 ) ;
if ( V_13 == NULL ) {
F_84 ( & V_2 -> V_239 ) ;
return - V_94 ;
}
V_15 -> V_240 = V_241 ;
V_15 -> V_240 . V_242 = V_236 -> V_242 ;
V_15 -> V_240 . V_243 = V_236 -> V_243 ;
V_15 -> V_240 . V_244 = V_236 -> V_244 ;
V_15 -> V_240 . V_245 = V_236 -> V_245 ;
F_101 ( V_15 ) ;
F_102 ( V_15 , V_246 ) ;
if ( V_2 -> V_247 )
V_238 = 128 ;
else
V_238 = 4 ;
F_103 ( V_15 , 0 , V_248 ,
V_238 ) ;
F_103 ( V_15 , 0 , V_249 ,
V_238 ) ;
F_104 ( V_234 -> V_219 ) ;
V_19 = V_236 -> V_201 . V_250 ( V_236 , V_234 -> V_219 , V_144 ) ;
if ( V_19 < 0 ) {
F_98 ( V_13 ) ;
F_105 ( V_234 -> V_219 ) ;
F_84 ( & V_2 -> V_239 ) ;
return V_19 ;
}
F_101 ( V_15 ) ;
if ( F_106 ( ! V_15 -> V_240 . V_242 ) ||
F_106 ( ! V_15 -> V_240 . V_243 ) ||
F_106 ( ! V_15 -> V_240 . V_244 ) ||
F_106 ( ! V_15 -> V_240 . V_245 ) ) {
F_98 ( V_13 ) ;
V_236 -> V_201 . V_251 ( V_236 , V_234 -> V_219 , V_144 ) ;
F_105 ( V_234 -> V_219 ) ;
F_84 ( & V_2 -> V_239 ) ;
return - V_161 ;
}
F_107 ( & V_2 -> V_23 , V_237 ) ;
V_13 -> V_144 = V_144 ;
V_13 -> V_145 = 0 ;
F_108 ( & V_2 -> V_23 , V_237 ) ;
V_15 -> V_55 = V_13 ;
F_109 ( V_144 ) ;
F_84 ( & V_2 -> V_239 ) ;
return 0 ;
}
static int F_110 ( struct V_153 * V_144 )
{
struct V_191 * V_234 = F_100 ( V_144 ) ;
struct V_235 * V_236 = V_234 -> V_236 [ V_144 -> V_226 ] ;
struct V_1 * V_2 = V_234 -> V_2 ;
struct V_13 * V_13 = F_111 ( V_144 ) ;
unsigned long V_237 ;
F_83 ( & V_2 -> V_239 ) ;
F_107 ( & V_2 -> V_23 , V_237 ) ;
V_13 -> V_144 = NULL ;
V_13 -> V_145 = 0 ;
F_108 ( & V_2 -> V_23 , V_237 ) ;
F_98 ( V_13 ) ;
V_236 -> V_201 . V_251 ( V_236 , V_234 -> V_219 , V_144 ) ;
F_105 ( V_234 -> V_219 ) ;
F_84 ( & V_2 -> V_239 ) ;
return 0 ;
}
static int F_112 ( struct V_153 * V_144 ,
struct V_252 * V_253 )
{
struct V_191 * V_234 = F_100 ( V_144 ) ;
struct V_1 * V_2 = V_234 -> V_2 ;
struct V_14 * V_15 = V_144 -> V_15 ;
struct V_13 * V_13 = F_111 ( V_144 ) ;
int V_254 ;
F_6 ( V_2 , V_13 , V_15 , false ) ;
V_13 -> V_169 = 0 ;
V_13 -> V_165 = 0 ;
V_13 -> V_182 = 0 ;
V_254 = F_113 ( V_144 ,
F_114 ( V_253 ) ) ;
if ( V_254 < 0 )
return V_254 ;
F_6 ( V_2 , V_13 , V_15 , true ) ;
return V_254 ;
}
static int F_115 ( struct V_153 * V_144 )
{
struct V_191 * V_234 = F_100 ( V_144 ) ;
struct V_13 * V_13 = F_111 ( V_144 ) ;
struct V_1 * V_2 = V_234 -> V_2 ;
struct V_14 * V_15 = V_144 -> V_15 ;
struct V_235 * V_236 = V_234 -> V_236 [ V_144 -> V_226 ] ;
F_76 ( V_13 , V_167 , 0 ) ;
F_76 ( V_13 , V_168 , 0 ) ;
F_76 ( V_13 , V_101 , 0 ) ;
V_13 -> V_169 = 0 ;
V_13 -> V_165 = 0 ;
V_13 -> V_182 = 0 ;
F_116 ( V_234 -> V_219 , V_236 , V_144 ) ;
F_6 ( V_2 , V_13 , V_15 , false ) ;
return F_117 ( V_144 ) ;
}
static int F_118 ( struct V_153 * V_144 )
{
struct V_191 * V_234 = F_100 ( V_144 ) ;
struct V_1 * V_2 = V_234 -> V_2 ;
struct V_13 * V_13 = F_111 ( V_144 ) ;
struct V_235 * V_236 = V_234 -> V_236 [ V_144 -> V_226 ] ;
struct V_14 * V_15 = V_144 -> V_15 ;
unsigned int V_169 , V_165 , V_182 , V_177 ;
int V_19 ;
struct V_255 * V_256 =
F_119 ( V_234 -> V_219 , V_236 -> V_257 ) ;
unsigned short V_258 = V_256 ? V_256 -> V_258 : 0 ;
F_78 ( V_2 , V_13 ) ;
V_182 = F_120 ( V_15 -> V_174 ,
V_15 -> V_259 ,
V_15 -> V_260 ,
V_236 -> V_261 ,
V_258 ) ;
if ( ! V_182 ) {
F_10 (KERN_ERR SFX
L_29 ,
runtime->rate, runtime->channels, runtime->format) ;
return - V_161 ;
}
V_169 = F_121 ( V_144 ) ;
V_165 = F_122 ( V_144 ) ;
F_36 ( V_69 L_30 ,
V_169 , V_182 ) ;
if ( V_169 != V_13 -> V_169 ||
V_165 != V_13 -> V_165 ||
V_182 != V_13 -> V_182 ||
V_15 -> V_172 != V_13 -> V_172 ) {
V_13 -> V_169 = V_169 ;
V_13 -> V_165 = V_165 ;
V_13 -> V_182 = V_182 ;
V_13 -> V_172 = V_15 -> V_172 ;
V_19 = F_75 ( V_2 , V_144 , V_13 ) ;
if ( V_19 < 0 )
return V_19 ;
}
V_13 -> V_262 = ( ( ( V_15 -> V_263 * 24000 ) /
V_15 -> V_174 ) * 1000 ) ;
F_79 ( V_2 , V_13 ) ;
if ( V_144 -> V_226 == V_227 )
V_13 -> V_264 = F_123 ( V_13 , V_265 ) + 1 ;
else
V_13 -> V_264 = 0 ;
V_177 = V_13 -> V_177 ;
if ( ( V_2 -> V_43 & V_44 ) &&
V_177 > V_2 -> V_231 )
V_177 -= V_2 -> V_231 ;
return F_124 ( V_234 -> V_219 , V_236 , V_177 ,
V_13 -> V_182 , V_144 ) ;
}
static int F_125 ( struct V_153 * V_144 , int V_49 )
{
struct V_191 * V_234 = F_100 ( V_144 ) ;
struct V_1 * V_2 = V_234 -> V_2 ;
struct V_13 * V_13 ;
struct V_153 * V_266 ;
int V_267 = 0 , V_268 , V_269 = 0 , V_270 = 0 ;
int V_271 , V_60 ;
switch ( V_49 ) {
case V_272 :
V_267 = 1 ;
case V_273 :
case V_274 :
V_268 = 1 ;
break;
case V_275 :
case V_276 :
case V_277 :
V_268 = 0 ;
break;
default:
return - V_161 ;
}
F_126 (s, substream) {
if ( V_266 -> V_193 -> V_210 != V_144 -> V_193 -> V_210 )
continue;
V_13 = F_111 ( V_266 ) ;
V_270 |= 1 << V_13 -> V_109 ;
V_269 ++ ;
F_127 ( V_266 , V_144 ) ;
}
F_67 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_43 & V_278 )
F_13 ( V_2 , V_279 ,
F_40 ( V_2 , V_279 ) | V_270 ) ;
else
F_13 ( V_2 , V_280 , F_40 ( V_2 , V_280 ) | V_270 ) ;
F_126 (s, substream) {
if ( V_266 -> V_193 -> V_210 != V_144 -> V_193 -> V_210 )
continue;
V_13 = F_111 ( V_266 ) ;
if ( V_268 ) {
V_13 -> V_281 = F_40 ( V_2 , V_282 ) ;
if ( ! V_267 )
V_13 -> V_281 -=
V_13 -> V_262 ;
F_55 ( V_2 , V_13 ) ;
} else {
F_57 ( V_2 , V_13 ) ;
}
V_13 -> V_145 = V_268 ;
}
F_68 ( & V_2 -> V_23 ) ;
if ( V_268 ) {
for ( V_60 = 5000 ; V_60 ; V_60 -- ) {
V_271 = 0 ;
F_126 (s, substream) {
if ( V_266 -> V_193 -> V_210 != V_144 -> V_193 -> V_210 )
continue;
V_13 = F_111 ( V_266 ) ;
if ( ! ( F_53 ( V_13 , V_103 ) &
V_283 ) )
V_271 ++ ;
}
if ( ! V_271 )
break;
F_128 () ;
}
} else {
for ( V_60 = 5000 ; V_60 ; V_60 -- ) {
V_271 = 0 ;
F_126 (s, substream) {
if ( V_266 -> V_193 -> V_210 != V_144 -> V_193 -> V_210 )
continue;
V_13 = F_111 ( V_266 ) ;
if ( F_53 ( V_13 , V_101 ) &
V_110 )
V_271 ++ ;
}
if ( ! V_271 )
break;
F_128 () ;
}
}
F_67 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_43 & V_278 )
F_13 ( V_2 , V_279 ,
F_40 ( V_2 , V_279 ) & ~ V_270 ) ;
else
F_13 ( V_2 , V_280 , F_40 ( V_2 , V_280 ) & ~ V_270 ) ;
F_68 ( & V_2 -> V_23 ) ;
return 0 ;
}
static unsigned int F_129 ( struct V_1 * V_2 ,
struct V_13 * V_13 )
{
unsigned int V_284 , V_285 , V_286 ;
unsigned int V_287 , V_288 , V_289 ;
unsigned int V_264 ;
V_284 = F_80 ( V_13 , V_290 ) ;
if ( V_13 -> V_144 -> V_226 == V_227 ) {
return V_284 ;
}
V_288 = F_26 ( * V_13 -> V_113 ) ;
V_288 %= V_13 -> V_165 ;
V_264 = F_130 ( V_2 -> V_291 + V_292 ) ;
if ( V_13 -> V_108 ) {
if ( V_284 <= V_264 )
return 0 ;
V_13 -> V_108 = 0 ;
}
if ( V_284 <= V_264 )
V_285 = V_13 -> V_169 + V_284 - V_264 ;
else
V_285 = V_284 - V_264 ;
V_289 = V_285 % V_13 -> V_165 ;
V_287 = V_284 % V_13 -> V_165 ;
if ( V_287 >= V_264 )
V_286 = V_284 - V_287 ;
else if ( V_288 >= V_289 )
V_286 = V_285 - V_289 ;
else {
V_286 = V_285 - V_289 + V_13 -> V_165 ;
if ( V_286 >= V_13 -> V_169 )
V_286 = 0 ;
}
return V_286 + V_288 ;
}
static unsigned int F_131 ( struct V_1 * V_2 ,
struct V_13 * V_13 ,
bool V_293 )
{
unsigned int V_294 ;
int V_226 = V_13 -> V_144 -> V_226 ;
switch ( V_2 -> V_184 [ V_226 ] ) {
case V_185 :
V_294 = F_80 ( V_13 , V_290 ) ;
break;
case V_295 :
V_294 = F_129 ( V_2 , V_13 ) ;
break;
default:
V_294 = F_26 ( * V_13 -> V_113 ) ;
if ( V_293 && V_2 -> V_184 [ V_226 ] == V_296 ) {
if ( ! V_294 || V_294 == ( V_25 ) - 1 ) {
F_132 ( V_297
L_31
L_32 ) ;
V_2 -> V_184 [ V_226 ] = V_185 ;
V_294 = F_80 ( V_13 , V_290 ) ;
} else
V_2 -> V_184 [ V_226 ] = V_298 ;
}
break;
}
if ( V_294 >= V_13 -> V_169 )
V_294 = 0 ;
if ( V_13 -> V_144 -> V_15 &&
V_2 -> V_184 [ V_226 ] == V_298 &&
( V_2 -> V_43 & V_299 ) ) {
unsigned int V_300 = F_80 ( V_13 , V_290 ) ;
int V_301 ;
if ( V_226 == V_227 )
V_301 = V_294 - V_300 ;
else
V_301 = V_300 - V_294 ;
if ( V_301 < 0 )
V_301 += V_13 -> V_169 ;
if ( V_301 >= V_13 -> V_165 ) {
F_10 (KERN_WARNING SFX
L_33
L_34 ,
delay, azx_dev->period_bytes) ;
V_301 = 0 ;
V_2 -> V_43 &= ~ V_299 ;
}
V_13 -> V_144 -> V_15 -> V_301 =
F_133 ( V_13 -> V_144 -> V_15 , V_301 ) ;
}
return V_294 ;
}
static T_7 F_134 ( struct V_153 * V_144 )
{
struct V_191 * V_234 = F_100 ( V_144 ) ;
struct V_1 * V_2 = V_234 -> V_2 ;
struct V_13 * V_13 = F_111 ( V_144 ) ;
return F_133 ( V_144 -> V_15 ,
F_131 ( V_2 , V_13 , false ) ) ;
}
static int F_69 ( struct V_1 * V_2 , struct V_13 * V_13 )
{
V_25 V_302 ;
unsigned int V_294 ;
int V_226 ;
V_302 = F_40 ( V_2 , V_282 ) - V_13 -> V_281 ;
if ( V_302 < ( V_13 -> V_262 * 2 ) / 3 )
return - 1 ;
V_226 = V_13 -> V_144 -> V_226 ;
V_294 = F_131 ( V_2 , V_13 , true ) ;
if ( F_135 ( ! V_13 -> V_165 ,
L_35 ) )
return - 1 ;
if ( V_302 < ( V_13 -> V_262 * 5 ) / 4 &&
V_294 % V_13 -> V_165 > V_13 -> V_165 / 2 )
return V_170 [ V_2 -> V_171 ] ? 0 : - 1 ;
V_13 -> V_281 += V_302 ;
return 1 ;
}
static void F_136 ( struct V_303 * V_304 )
{
struct V_1 * V_2 = F_137 ( V_304 , struct V_1 , V_149 ) ;
int V_99 , V_305 , V_137 ;
if ( ! V_2 -> V_306 ) {
F_132 ( V_297
L_36
L_37 ,
V_2 -> V_210 -> V_225 ) ;
V_2 -> V_306 = 1 ;
}
for (; ; ) {
V_305 = 0 ;
F_12 ( & V_2 -> V_23 ) ;
for ( V_99 = 0 ; V_99 < V_2 -> V_100 ; V_99 ++ ) {
struct V_13 * V_13 = & V_2 -> V_13 [ V_99 ] ;
if ( ! V_13 -> V_147 ||
! V_13 -> V_144 ||
! V_13 -> V_145 )
continue;
V_137 = F_69 ( V_2 , V_13 ) ;
if ( V_137 > 0 ) {
V_13 -> V_147 = 0 ;
F_68 ( & V_2 -> V_23 ) ;
F_70 ( V_13 -> V_144 ) ;
F_67 ( & V_2 -> V_23 ) ;
} else if ( V_137 < 0 ) {
V_305 = 0 ;
} else
V_305 ++ ;
}
F_17 ( & V_2 -> V_23 ) ;
if ( ! V_305 )
return;
F_33 ( 1 ) ;
}
}
static void F_138 ( struct V_1 * V_2 )
{
int V_99 ;
F_12 ( & V_2 -> V_23 ) ;
for ( V_99 = 0 ; V_99 < V_2 -> V_100 ; V_99 ++ )
V_2 -> V_13 [ V_99 ] . V_147 = 0 ;
F_17 ( & V_2 -> V_23 ) ;
}
static int F_139 ( struct V_153 * V_144 ,
struct V_307 * V_11 )
{
struct V_191 * V_234 = F_100 ( V_144 ) ;
struct V_1 * V_2 = V_234 -> V_2 ;
if ( ! F_2 ( V_2 ) )
V_11 -> V_308 = F_140 ( V_11 -> V_308 ) ;
return F_141 ( V_144 , V_11 ) ;
}
static void F_142 ( struct V_309 * V_193 )
{
struct V_191 * V_234 = V_193 -> V_55 ;
if ( V_234 ) {
F_143 ( & V_234 -> V_310 ) ;
F_144 ( V_234 ) ;
}
}
static int
V_205 ( struct V_52 * V_53 , struct V_218 * V_219 ,
struct V_311 * V_312 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_309 * V_193 ;
struct V_191 * V_234 ;
int V_313 = V_312 -> V_224 ;
unsigned int V_4 ;
int V_266 , V_19 ;
F_88 (apcm, &chip->pcm_list, list) {
if ( V_234 -> V_193 -> V_224 == V_313 ) {
F_10 (KERN_ERR SFX L_38 , pcm_dev) ;
return - V_94 ;
}
}
V_19 = F_145 ( V_2 -> V_210 , V_312 -> V_314 , V_313 ,
V_312 -> V_226 [ V_227 ] . V_315 ,
V_312 -> V_226 [ V_316 ] . V_315 ,
& V_193 ) ;
if ( V_19 < 0 )
return V_19 ;
F_146 ( V_193 -> V_314 , V_312 -> V_314 , sizeof( V_193 -> V_314 ) ) ;
V_234 = F_147 ( sizeof( * V_234 ) , V_317 ) ;
if ( V_234 == NULL )
return - V_318 ;
V_234 -> V_2 = V_2 ;
V_234 -> V_193 = V_193 ;
V_234 -> V_219 = V_219 ;
V_193 -> V_55 = V_234 ;
V_193 -> V_319 = F_142 ;
if ( V_312 -> V_320 == V_321 )
V_193 -> V_322 = V_323 ;
F_148 ( & V_234 -> V_310 , & V_2 -> V_324 ) ;
V_312 -> V_193 = V_193 ;
for ( V_266 = 0 ; V_266 < 2 ; V_266 ++ ) {
V_234 -> V_236 [ V_266 ] = & V_312 -> V_226 [ V_266 ] ;
if ( V_312 -> V_226 [ V_266 ] . V_315 )
F_149 ( V_193 , V_266 , & V_325 ) ;
}
V_4 = V_326 * 1024 ;
if ( V_4 > V_327 )
V_4 = V_327 ;
F_150 ( V_193 , V_328 ,
F_9 ( V_2 -> V_21 ) ,
V_4 , V_327 ) ;
return 0 ;
}
static int T_6 F_151 ( struct V_1 * V_2 )
{
return F_152 ( V_2 -> V_53 ) ;
}
static int T_6 F_153 ( struct V_1 * V_2 )
{
int V_99 ;
for ( V_99 = 0 ; V_99 < V_2 -> V_100 ; V_99 ++ ) {
struct V_13 * V_13 = & V_2 -> V_13 [ V_99 ] ;
V_13 -> V_113 = ( V_25 V_329 * ) ( V_2 -> V_113 . V_11 + V_99 * 8 ) ;
V_13 -> V_330 = V_2 -> V_291 + ( 0x20 * V_99 + 0x80 ) ;
V_13 -> V_143 = 1 << V_99 ;
V_13 -> V_109 = V_99 ;
V_13 -> V_177 = V_99 + 1 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , int V_331 )
{
if ( F_154 ( V_2 -> V_21 -> V_72 , F_65 ,
V_2 -> V_71 ? 0 : V_332 ,
V_333 , V_2 ) ) {
F_132 ( V_77 L_39
L_40 , V_2 -> V_21 -> V_72 ) ;
if ( V_331 )
F_155 ( V_2 -> V_210 ) ;
return - 1 ;
}
V_2 -> V_72 = V_2 -> V_21 -> V_72 ;
F_156 ( V_2 -> V_21 , ! V_2 -> V_71 ) ;
return 0 ;
}
static void F_86 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_111 )
return;
F_51 ( V_2 ) ;
F_54 ( V_2 ) ;
F_18 ( V_2 ) ;
F_13 ( V_2 , V_112 , 0 ) ;
F_13 ( V_2 , V_114 , 0 ) ;
V_2 -> V_111 = 0 ;
}
static void V_209 ( struct V_52 * V_53 , bool V_334 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
if ( ! ( V_2 -> V_43 & V_335 ) )
return;
if ( V_334 )
F_157 ( & V_2 -> V_21 -> V_138 ) ;
else
F_158 ( & V_2 -> V_21 -> V_138 ) ;
}
static void F_159 ( struct V_1 * V_2 )
{
F_83 ( & V_336 ) ;
F_160 ( & V_2 -> V_310 , & V_337 ) ;
F_84 ( & V_336 ) ;
}
static void F_161 ( struct V_1 * V_2 )
{
F_83 ( & V_336 ) ;
F_162 ( & V_2 -> V_310 ) ;
F_84 ( & V_336 ) ;
}
static int F_163 ( const char * V_54 , const struct V_338 * V_339 )
{
struct V_1 * V_2 ;
struct V_218 * V_197 ;
int V_340 = V_207 ;
int V_254 = F_164 ( V_54 , V_339 ) ;
if ( V_254 || V_340 == V_207 )
return V_254 ;
F_83 ( & V_336 ) ;
F_88 (chip, &card_list, list) {
if ( ! V_2 -> V_53 || V_2 -> V_87 )
continue;
F_88 (c, &chip->bus->codec_list, list)
F_165 ( V_197 ) ;
}
F_84 ( & V_336 ) ;
return 0 ;
}
static int F_166 ( struct V_224 * V_138 )
{
struct V_115 * V_21 = F_167 ( V_138 ) ;
struct V_341 * V_210 = F_168 ( V_138 ) ;
struct V_1 * V_2 = V_210 -> V_55 ;
struct V_191 * V_192 ;
F_169 ( V_210 , V_342 ) ;
F_138 ( V_2 ) ;
F_88 (p, &chip->pcm_list, list)
F_89 ( V_192 -> V_193 ) ;
if ( V_2 -> V_111 )
F_90 ( V_2 -> V_53 ) ;
F_86 ( V_2 ) ;
if ( V_2 -> V_72 >= 0 ) {
F_37 ( V_2 -> V_72 , V_2 ) ;
V_2 -> V_72 = - 1 ;
}
if ( V_2 -> V_71 )
F_38 ( V_2 -> V_21 ) ;
F_170 ( V_21 ) ;
F_171 ( V_21 ) ;
F_172 ( V_21 , V_343 ) ;
return 0 ;
}
static int F_173 ( struct V_224 * V_138 )
{
struct V_115 * V_21 = F_167 ( V_138 ) ;
struct V_341 * V_210 = F_168 ( V_138 ) ;
struct V_1 * V_2 = V_210 -> V_55 ;
F_172 ( V_21 , V_344 ) ;
F_174 ( V_21 ) ;
if ( F_175 ( V_21 ) < 0 ) {
F_132 ( V_77 L_41
L_40 ) ;
F_155 ( V_210 ) ;
return - V_84 ;
}
F_176 ( V_21 ) ;
if ( V_2 -> V_71 )
if ( F_177 ( V_21 ) < 0 )
V_2 -> V_71 = 0 ;
if ( F_39 ( V_2 , 1 ) < 0 )
return - V_84 ;
F_62 ( V_2 ) ;
F_58 ( V_2 , 1 ) ;
F_91 ( V_2 -> V_53 ) ;
F_169 ( V_210 , V_345 ) ;
return 0 ;
}
static int F_178 ( struct V_224 * V_138 )
{
struct V_341 * V_210 = F_168 ( V_138 ) ;
struct V_1 * V_2 = V_210 -> V_55 ;
if ( ! V_346 ||
! ( V_2 -> V_43 & V_335 ) )
return - V_347 ;
F_86 ( V_2 ) ;
F_138 ( V_2 ) ;
return 0 ;
}
static int F_179 ( struct V_224 * V_138 )
{
struct V_341 * V_210 = F_168 ( V_138 ) ;
struct V_1 * V_2 = V_210 -> V_55 ;
F_62 ( V_2 ) ;
F_58 ( V_2 , 1 ) ;
return 0 ;
}
static int F_180 ( struct V_348 * V_349 , unsigned long V_350 , void * V_10 )
{
struct V_1 * V_2 = F_137 ( V_349 , struct V_1 , V_351 ) ;
F_181 ( V_2 -> V_53 ) ;
F_86 ( V_2 ) ;
return V_352 ;
}
static void F_182 ( struct V_1 * V_2 )
{
V_2 -> V_351 . V_353 = F_180 ;
F_183 ( & V_2 -> V_351 ) ;
}
static void F_184 ( struct V_1 * V_2 )
{
if ( V_2 -> V_351 . V_353 )
F_185 ( & V_2 -> V_351 ) ;
}
static void F_186 ( struct V_115 * V_21 ,
enum V_354 V_355 )
{
struct V_341 * V_210 = F_187 ( V_21 ) ;
struct V_1 * V_2 = V_210 -> V_55 ;
bool V_87 ;
if ( V_2 -> V_356 )
return;
V_87 = ( V_355 == V_357 ) ;
if ( V_2 -> V_87 == V_87 )
return;
if ( ! V_2 -> V_53 ) {
V_2 -> V_87 = V_87 ;
if ( ! V_87 ) {
F_10 (KERN_INFO SFX
L_42 ,
pci_name(chip->pci)) ;
if ( F_188 ( V_2 ) < 0 ||
F_189 ( V_2 ) < 0 ) {
F_10 (KERN_ERR SFX
L_43 ,
pci_name(chip->pci)) ;
V_2 -> V_356 = true ;
}
}
} else {
F_10 (KERN_INFO SFX
L_44 ,
disabled ? L_45 : L_46 ,
pci_name(chip->pci)) ;
if ( V_87 ) {
F_166 ( & V_21 -> V_138 ) ;
V_2 -> V_87 = true ;
if ( F_190 ( V_2 -> V_53 ) )
F_10 (KERN_WARNING SFX
L_47 ) ;
} else {
F_191 ( V_2 -> V_53 ) ;
V_2 -> V_87 = false ;
F_173 ( & V_21 -> V_138 ) ;
}
}
}
static bool F_192 ( struct V_115 * V_21 )
{
struct V_341 * V_210 = F_187 ( V_21 ) ;
struct V_1 * V_2 = V_210 -> V_55 ;
if ( V_2 -> V_356 )
return false ;
if ( V_2 -> V_87 || ! V_2 -> V_53 )
return true ;
if ( F_190 ( V_2 -> V_53 ) )
return false ;
F_191 ( V_2 -> V_53 ) ;
return true ;
}
static void T_6 F_193 ( struct V_1 * V_2 )
{
struct V_115 * V_192 = F_194 ( V_2 -> V_21 ) ;
if ( V_192 ) {
F_10 (KERN_INFO SFX
L_48 ,
pci_name(chip->pci)) ;
V_2 -> V_358 = 1 ;
F_195 ( V_192 ) ;
}
}
static int T_6 F_196 ( struct V_1 * V_2 )
{
int V_19 ;
if ( ! V_2 -> V_358 )
return 0 ;
V_19 = F_197 ( V_2 -> V_21 , & V_359 ,
V_360 ,
V_2 -> V_53 != NULL ) ;
if ( V_19 < 0 )
return V_19 ;
V_2 -> V_361 = 1 ;
return 0 ;
}
static int F_198 ( struct V_1 * V_2 )
{
int V_99 ;
F_161 ( V_2 ) ;
F_184 ( V_2 ) ;
if ( V_358 ( V_2 ) ) {
if ( V_2 -> V_87 && V_2 -> V_53 )
F_191 ( V_2 -> V_53 ) ;
if ( V_2 -> V_361 )
F_199 ( V_2 -> V_21 ) ;
}
if ( V_2 -> V_111 ) {
F_138 ( V_2 ) ;
for ( V_99 = 0 ; V_99 < V_2 -> V_100 ; V_99 ++ )
F_57 ( V_2 , & V_2 -> V_13 [ V_99 ] ) ;
F_86 ( V_2 ) ;
}
if ( V_2 -> V_72 >= 0 )
F_37 ( V_2 -> V_72 , ( void * ) V_2 ) ;
if ( V_2 -> V_71 )
F_38 ( V_2 -> V_21 ) ;
if ( V_2 -> V_291 )
F_200 ( V_2 -> V_291 ) ;
if ( V_2 -> V_13 ) {
for ( V_99 = 0 ; V_99 < V_2 -> V_100 ; V_99 ++ )
if ( V_2 -> V_13 [ V_99 ] . V_157 . V_11 ) {
F_5 ( V_2 , & V_2 -> V_13 [ V_99 ] . V_157 , false ) ;
F_201 ( & V_2 -> V_13 [ V_99 ] . V_157 ) ;
}
}
if ( V_2 -> V_22 . V_11 ) {
F_5 ( V_2 , & V_2 -> V_22 , false ) ;
F_201 ( & V_2 -> V_22 ) ;
}
if ( V_2 -> V_113 . V_11 ) {
F_5 ( V_2 , & V_2 -> V_113 , false ) ;
F_201 ( & V_2 -> V_113 ) ;
}
if ( V_2 -> V_362 )
F_202 ( V_2 -> V_21 ) ;
F_170 ( V_2 -> V_21 ) ;
F_144 ( V_2 -> V_13 ) ;
#ifdef F_203
if ( V_2 -> V_363 )
F_204 ( V_2 -> V_363 ) ;
#endif
F_144 ( V_2 ) ;
return 0 ;
}
static int F_205 ( struct V_364 * V_224 )
{
return F_198 ( V_224 -> V_365 ) ;
}
static struct V_115 T_6 * F_194 ( struct V_115 * V_21 )
{
struct V_115 * V_192 ;
switch ( V_21 -> V_366 ) {
case V_367 :
case V_368 :
case V_369 :
if ( V_21 -> V_370 == 1 ) {
V_192 = F_206 ( F_207 ( V_21 -> V_53 ) ,
V_21 -> V_53 -> V_225 , 0 ) ;
if ( V_192 ) {
if ( ( V_192 -> V_371 >> 8 ) == V_372 )
return V_192 ;
F_195 ( V_192 ) ;
}
}
break;
}
return NULL ;
}
static bool T_6 F_208 ( struct V_115 * V_21 )
{
bool V_373 = false ;
struct V_115 * V_192 = F_194 ( V_21 ) ;
if ( V_192 ) {
if ( F_209 ( V_192 ) == V_357 )
V_373 = true ;
F_195 ( V_192 ) ;
}
return V_373 ;
}
static int T_6 F_210 ( struct V_1 * V_2 , int V_374 )
{
const struct V_375 * V_376 ;
switch ( V_374 ) {
case V_296 :
case V_185 :
case V_298 :
case V_295 :
case V_377 :
return V_374 ;
}
V_376 = F_211 ( V_2 -> V_21 , V_378 ) ;
if ( V_376 ) {
F_132 ( V_379
L_49
L_50 ,
V_376 -> V_380 , V_376 -> V_381 , V_376 -> V_382 ) ;
return V_376 -> V_380 ;
}
if ( V_2 -> V_43 & V_383 ) {
F_44 ( V_69 L_51 ) ;
return V_295 ;
}
if ( V_2 -> V_43 & V_384 ) {
F_44 ( V_69 L_52 ) ;
return V_185 ;
}
return V_296 ;
}
static void T_6 F_212 ( struct V_1 * V_2 , int V_138 )
{
const struct V_375 * V_376 ;
V_2 -> V_215 = V_385 [ V_138 ] ;
if ( V_2 -> V_215 == - 1 ) {
V_376 = F_211 ( V_2 -> V_21 , V_386 ) ;
if ( V_376 ) {
F_132 ( V_379
L_53
L_50 ,
V_376 -> V_380 , V_376 -> V_381 , V_376 -> V_382 ) ;
V_2 -> V_215 = V_376 -> V_380 ;
}
}
if ( V_2 -> V_215 != - 1 &&
( V_2 -> V_215 & V_387 ) ) {
V_2 -> V_95 = V_2 -> V_215 & 0xff ;
F_132 ( V_379 L_54 ,
V_2 -> V_95 ) ;
}
}
static void T_6 F_213 ( struct V_1 * V_2 )
{
const struct V_375 * V_376 ;
if ( V_388 >= 0 ) {
V_2 -> V_71 = ! ! V_388 ;
return;
}
V_2 -> V_71 = 1 ;
V_376 = F_211 ( V_2 -> V_21 , V_389 ) ;
if ( V_376 ) {
F_132 ( V_379
L_55 ,
V_376 -> V_381 , V_376 -> V_382 , V_376 -> V_380 ) ;
V_2 -> V_71 = V_376 -> V_380 ;
return;
}
if ( V_2 -> V_43 & V_390 ) {
F_132 ( V_379 L_56 ) ;
V_2 -> V_71 = 0 ;
}
}
static void T_6 F_214 ( struct V_1 * V_2 )
{
bool V_131 = V_2 -> V_131 ;
switch ( V_2 -> V_213 ) {
case V_391 :
if ( V_131 ) {
T_3 V_54 ;
F_60 ( V_2 -> V_21 , 0x42 , & V_54 ) ;
if ( ! ( V_54 & 0x80 ) && V_2 -> V_21 -> V_392 == 0x30 )
V_131 = false ;
}
break;
case V_393 :
V_131 = false ;
break;
}
if ( V_131 != V_2 -> V_131 ) {
F_10 (KERN_INFO SFX L_57 ,
snoop ? L_58 : L_59 ) ;
V_2 -> V_131 = V_131 ;
}
}
static int T_6 F_215 ( struct V_341 * V_210 , struct V_115 * V_21 ,
int V_138 , unsigned int V_43 ,
struct V_1 * * V_394 )
{
static struct V_395 V_201 = {
. V_396 = F_205 ,
} ;
struct V_1 * V_2 ;
int V_19 ;
* V_394 = NULL ;
V_19 = F_175 ( V_21 ) ;
if ( V_19 < 0 )
return V_19 ;
V_2 = F_147 ( sizeof( * V_2 ) , V_317 ) ;
if ( ! V_2 ) {
F_10 (KERN_ERR SFX L_60 ) ;
F_170 ( V_21 ) ;
return - V_318 ;
}
F_216 ( & V_2 -> V_23 ) ;
F_217 ( & V_2 -> V_239 ) ;
V_2 -> V_210 = V_210 ;
V_2 -> V_21 = V_21 ;
V_2 -> V_72 = - 1 ;
V_2 -> V_43 = V_43 ;
V_2 -> V_213 = V_43 & 0xff ;
F_213 ( V_2 ) ;
V_2 -> V_171 = V_138 ;
F_218 ( & V_2 -> V_149 , F_136 ) ;
F_219 ( & V_2 -> V_324 ) ;
F_219 ( & V_2 -> V_310 ) ;
F_193 ( V_2 ) ;
V_2 -> V_184 [ 0 ] = V_2 -> V_184 [ 1 ] =
F_210 ( V_2 , V_184 [ V_138 ] ) ;
if ( V_2 -> V_184 [ 0 ] == V_377 ) {
V_2 -> V_184 [ 0 ] = V_185 ;
V_2 -> V_184 [ 1 ] = V_296 ;
}
F_212 ( V_2 , V_138 ) ;
V_2 -> V_78 = V_78 ;
V_2 -> V_131 = V_397 ;
F_214 ( V_2 ) ;
if ( V_170 [ V_138 ] < 0 ) {
switch ( V_2 -> V_213 ) {
case V_398 :
case V_399 :
V_170 [ V_138 ] = 1 ;
break;
default:
V_170 [ V_138 ] = 32 ;
break;
}
}
if ( F_208 ( V_21 ) ) {
F_10 (KERN_INFO SFX L_61 ,
pci_name(pci)) ;
if ( V_358 ( V_2 ) ) {
F_10 (KERN_INFO SFX L_62 ) ;
V_2 -> V_87 = true ;
goto V_137;
}
F_144 ( V_2 ) ;
F_170 ( V_21 ) ;
return - V_221 ;
}
V_19 = F_188 ( V_2 ) ;
if ( V_19 < 0 ) {
F_198 ( V_2 ) ;
return V_19 ;
}
V_137:
V_19 = F_220 ( V_210 , V_400 , V_2 , & V_201 ) ;
if ( V_19 < 0 ) {
F_10 (KERN_ERR SFX L_63 ) ;
F_198 ( V_2 ) ;
return V_19 ;
}
* V_394 = V_2 ;
return 0 ;
}
static int T_5 F_188 ( struct V_1 * V_2 )
{
int V_138 = V_2 -> V_171 ;
struct V_115 * V_21 = V_2 -> V_21 ;
struct V_341 * V_210 = V_2 -> V_210 ;
int V_99 , V_19 ;
unsigned short V_401 ;
#if V_402 != 64
if ( V_2 -> V_213 == V_403 ) {
T_8 V_404 ;
F_63 ( V_21 , 0x40 , & V_404 ) ;
F_64 ( V_21 , 0x40 , V_404 | 0x10 ) ;
F_221 ( V_21 , V_405 , 0 ) ;
}
#endif
V_19 = F_222 ( V_21 , L_64 ) ;
if ( V_19 < 0 )
return V_19 ;
V_2 -> V_362 = 1 ;
V_2 -> V_3 = F_223 ( V_21 , 0 ) ;
V_2 -> V_291 = F_224 ( V_21 , 0 ) ;
if ( V_2 -> V_291 == NULL ) {
F_10 (KERN_ERR SFX L_65 ) ;
return - V_221 ;
}
if ( V_2 -> V_71 )
if ( F_177 ( V_21 ) < 0 )
V_2 -> V_71 = 0 ;
if ( F_39 ( V_2 , 0 ) < 0 )
return - V_94 ;
F_176 ( V_21 ) ;
F_225 ( V_2 -> V_72 ) ;
V_401 = F_42 ( V_2 , V_406 ) ;
F_36 ( V_69 L_66 , V_401 ) ;
if ( V_2 -> V_21 -> V_366 == V_367 ) {
struct V_115 * V_407 ;
V_407 = F_226 ( V_367 ,
V_408 ,
NULL ) ;
if ( V_407 ) {
if ( V_407 -> V_392 < 0x30 )
V_401 &= ~ V_409 ;
F_195 ( V_407 ) ;
}
}
if ( V_2 -> V_43 & V_410 ) {
F_44 ( V_69 L_67 ) ;
V_401 &= ~ V_409 ;
}
if ( V_247 >= 0 )
V_2 -> V_247 = ! ! V_247 ;
else {
if ( V_2 -> V_43 & V_411 )
V_2 -> V_247 = 0 ;
else if ( V_2 -> V_43 & V_412 )
V_2 -> V_247 = 1 ;
else
V_2 -> V_247 = 1 ;
}
if ( ( V_401 & V_409 ) && ! F_227 ( V_21 , F_228 ( 64 ) ) )
F_229 ( V_21 , F_228 ( 64 ) ) ;
else {
F_227 ( V_21 , F_228 ( 32 ) ) ;
F_229 ( V_21 , F_228 ( 32 ) ) ;
}
V_2 -> V_231 = ( V_401 >> 8 ) & 0x0f ;
V_2 -> V_229 = ( V_401 >> 12 ) & 0x0f ;
if ( ! V_2 -> V_229 && ! V_2 -> V_231 ) {
switch ( V_2 -> V_213 ) {
case V_403 :
V_2 -> V_229 = V_413 ;
V_2 -> V_231 = V_414 ;
break;
case V_415 :
case V_393 :
V_2 -> V_229 = V_416 ;
V_2 -> V_231 = V_417 ;
break;
case V_418 :
default:
V_2 -> V_229 = V_419 ;
V_2 -> V_231 = V_420 ;
break;
}
}
V_2 -> V_230 = 0 ;
V_2 -> V_228 = V_2 -> V_231 ;
V_2 -> V_100 = V_2 -> V_229 + V_2 -> V_231 ;
V_2 -> V_13 = F_230 ( V_2 -> V_100 , sizeof( * V_2 -> V_13 ) ,
V_317 ) ;
if ( ! V_2 -> V_13 ) {
F_10 (KERN_ERR SFX L_68 ) ;
return - V_318 ;
}
for ( V_99 = 0 ; V_99 < V_2 -> V_100 ; V_99 ++ ) {
V_19 = F_8 ( V_20 ,
F_9 ( V_2 -> V_21 ) ,
V_421 , & V_2 -> V_13 [ V_99 ] . V_157 ) ;
if ( V_19 < 0 ) {
F_10 (KERN_ERR SFX L_69 ) ;
return - V_318 ;
}
F_5 ( V_2 , & V_2 -> V_13 [ V_99 ] . V_157 , true ) ;
}
V_19 = F_8 ( V_20 ,
F_9 ( V_2 -> V_21 ) ,
V_2 -> V_100 * 8 , & V_2 -> V_113 ) ;
if ( V_19 < 0 ) {
F_10 (KERN_ERR SFX L_70 ) ;
return - V_318 ;
}
F_5 ( V_2 , & V_2 -> V_113 , true ) ;
V_19 = F_7 ( V_2 ) ;
if ( V_19 < 0 )
return V_19 ;
F_153 ( V_2 ) ;
F_62 ( V_2 ) ;
F_58 ( V_2 , ( V_422 [ V_138 ] & 2 ) == 0 ) ;
if ( ! V_2 -> V_95 ) {
F_10 (KERN_ERR SFX L_71 ) ;
return - V_423 ;
}
strcpy ( V_210 -> V_424 , L_72 ) ;
F_146 ( V_210 -> V_425 , V_426 [ V_2 -> V_213 ] ,
sizeof( V_210 -> V_425 ) ) ;
snprintf ( V_210 -> V_427 , sizeof( V_210 -> V_427 ) ,
L_73 ,
V_210 -> V_425 , V_2 -> V_3 , V_2 -> V_72 ) ;
return 0 ;
}
static void F_231 ( struct V_1 * V_2 )
{
#ifdef F_87
struct V_218 * V_219 ;
F_88 (codec, &chip->bus->codec_list, list) {
F_105 ( V_219 ) ;
}
#endif
}
static void F_232 ( const struct V_428 * V_363 , void * V_429 )
{
struct V_341 * V_210 = V_429 ;
struct V_1 * V_2 = V_210 -> V_55 ;
struct V_115 * V_21 = V_2 -> V_21 ;
if ( ! V_363 ) {
F_10 (KERN_ERR SFX L_74 ) ;
goto error;
}
V_2 -> V_363 = V_363 ;
if ( ! V_2 -> V_87 ) {
if ( F_189 ( V_2 ) )
goto error;
}
return;
error:
F_233 ( V_210 ) ;
F_234 ( V_21 , NULL ) ;
}
static int T_6 F_235 ( struct V_115 * V_21 ,
const struct V_430 * V_431 )
{
static int V_138 ;
struct V_341 * V_210 ;
struct V_1 * V_2 ;
bool V_432 ;
int V_19 ;
if ( V_138 >= V_433 )
return - V_423 ;
if ( ! V_434 [ V_138 ] ) {
V_138 ++ ;
return - V_435 ;
}
V_19 = F_236 ( V_109 [ V_138 ] , V_436 [ V_138 ] , V_437 , 0 , & V_210 ) ;
if ( V_19 < 0 ) {
F_10 (KERN_ERR SFX L_75 ) ;
return V_19 ;
}
F_237 ( V_210 , & V_21 -> V_138 ) ;
V_19 = F_215 ( V_210 , V_21 , V_138 , V_431 -> V_438 , & V_2 ) ;
if ( V_19 < 0 )
goto V_439;
V_210 -> V_55 = V_2 ;
V_432 = ! V_2 -> V_87 ;
#ifdef F_203
if ( V_440 [ V_138 ] && * V_440 [ V_138 ] ) {
F_10 (KERN_ERR SFX L_76 ,
patch[dev]) ;
V_19 = F_238 ( V_437 , true , V_440 [ V_138 ] ,
& V_21 -> V_138 , V_317 , V_210 ,
F_232 ) ;
if ( V_19 < 0 )
goto V_439;
V_432 = false ;
}
#endif
if ( V_432 ) {
V_19 = F_189 ( V_2 ) ;
if ( V_19 < 0 )
goto V_439;
}
F_234 ( V_21 , V_210 ) ;
if ( F_239 ( V_21 ) )
F_240 ( & V_21 -> V_138 ) ;
V_19 = F_196 ( V_2 ) ;
if ( V_19 < 0 ) {
F_10 (KERN_ERR SFX
L_77 ) ;
goto V_439;
}
V_138 ++ ;
return 0 ;
V_439:
F_233 ( V_210 ) ;
return V_19 ;
}
static int T_5 F_189 ( struct V_1 * V_2 )
{
int V_138 = V_2 -> V_171 ;
int V_19 ;
#ifdef F_241
V_2 -> V_220 = V_220 [ V_138 ] ;
#endif
V_19 = F_92 ( V_2 , V_194 [ V_138 ] ) ;
if ( V_19 < 0 )
goto V_439;
#ifdef F_203
if ( V_2 -> V_363 ) {
V_19 = F_242 ( V_2 -> V_53 , V_2 -> V_363 -> V_4 ,
V_2 -> V_363 -> V_118 ) ;
if ( V_19 < 0 )
goto V_439;
F_204 ( V_2 -> V_363 ) ;
V_2 -> V_363 = NULL ;
}
#endif
if ( ( V_422 [ V_138 ] & 1 ) == 0 ) {
V_19 = F_95 ( V_2 ) ;
if ( V_19 < 0 )
goto V_439;
}
V_19 = F_243 ( V_2 -> V_53 ) ;
if ( V_19 < 0 )
goto V_439;
V_19 = F_151 ( V_2 ) ;
if ( V_19 < 0 )
goto V_439;
V_19 = F_244 ( V_2 -> V_210 ) ;
if ( V_19 < 0 )
goto V_439;
V_2 -> V_145 = 1 ;
F_231 ( V_2 ) ;
F_182 ( V_2 ) ;
F_159 ( V_2 ) ;
return 0 ;
V_439:
V_2 -> V_356 = 1 ;
return V_19 ;
}
static void T_9 F_245 ( struct V_115 * V_21 )
{
struct V_341 * V_210 = F_187 ( V_21 ) ;
if ( F_239 ( V_21 ) )
F_246 ( & V_21 -> V_138 ) ;
if ( V_210 )
F_233 ( V_210 ) ;
F_234 ( V_21 , NULL ) ;
}
