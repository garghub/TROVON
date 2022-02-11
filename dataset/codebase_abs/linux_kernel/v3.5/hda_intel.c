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
F_66 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_87 ) {
F_67 ( & V_2 -> V_23 ) ;
return V_138 ;
}
V_135 = F_40 ( V_2 , V_106 ) ;
if ( V_135 == 0 ) {
F_67 ( & V_2 -> V_23 ) ;
return V_138 ;
}
for ( V_99 = 0 ; V_99 < V_2 -> V_100 ; V_99 ++ ) {
V_13 = & V_2 -> V_13 [ V_99 ] ;
if ( V_135 & V_13 -> V_139 ) {
V_136 = F_53 ( V_13 , V_103 ) ;
F_52 ( V_13 , V_103 , V_102 ) ;
if ( ! V_13 -> V_140 || ! V_13 -> V_141 ||
! ( V_136 & V_142 ) )
continue;
V_137 = F_68 ( V_2 , V_13 ) ;
if ( V_137 == 1 ) {
V_13 -> V_143 = 0 ;
F_67 ( & V_2 -> V_23 ) ;
F_69 ( V_13 -> V_140 ) ;
F_66 ( & V_2 -> V_23 ) ;
} else if ( V_137 == 0 && V_2 -> V_53 && V_2 -> V_53 -> V_144 ) {
V_13 -> V_143 = 1 ;
F_70 ( V_2 -> V_53 -> V_144 ,
& V_2 -> V_145 ) ;
}
}
}
V_135 = F_23 ( V_2 , V_104 ) ;
if ( V_135 & V_105 ) {
if ( V_135 & V_146 ) {
if ( V_2 -> V_43 & V_147 )
F_34 ( 80 ) ;
F_25 ( V_2 ) ;
}
F_15 ( V_2 , V_104 , V_105 ) ;
}
#if 0
if (azx_readb(chip, STATESTS) & 0x04)
azx_writeb(chip, STATESTS, 0x04);
#endif
F_67 ( & V_2 -> V_23 ) ;
return V_148 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_149 * V_140 ,
struct V_13 * V_13 , V_25 * * V_150 ,
int V_151 , int V_4 , int V_152 )
{
V_25 * V_153 = * V_150 ;
while ( V_4 > 0 ) {
T_4 V_3 ;
int V_154 ;
if ( V_13 -> V_155 >= V_156 )
return - V_157 ;
V_3 = F_72 ( V_140 , V_151 ) ;
V_153 [ 0 ] = F_24 ( ( V_25 ) V_3 ) ;
V_153 [ 1 ] = F_24 ( F_14 ( V_3 ) ) ;
V_154 = F_73 ( V_140 , V_151 , V_4 ) ;
if ( V_2 -> V_43 & V_158 ) {
V_25 V_159 = 0x1000 - ( V_151 & 0xfff ) ;
if ( V_154 > V_159 )
V_154 = V_159 ;
}
V_153 [ 2 ] = F_24 ( V_154 ) ;
V_4 -= V_154 ;
V_153 [ 3 ] = ( V_4 || ! V_152 ) ? 0 : F_24 ( 0x01 ) ;
V_153 += 4 ;
V_13 -> V_155 ++ ;
V_151 += V_154 ;
}
* V_150 = V_153 ;
return V_151 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_149 * V_140 ,
struct V_13 * V_13 )
{
V_25 * V_153 ;
int V_99 , V_151 , V_160 , V_161 ;
int V_162 ;
F_75 ( V_13 , V_163 , 0 ) ;
F_75 ( V_13 , V_164 , 0 ) ;
V_161 = V_13 -> V_161 ;
V_160 = V_13 -> V_165 / V_161 ;
V_153 = ( V_25 * ) V_13 -> V_153 . V_11 ;
V_151 = 0 ;
V_13 -> V_155 = 0 ;
V_162 = V_166 [ V_2 -> V_167 ] ;
if ( V_162 > 0 ) {
struct V_14 * V_15 = V_140 -> V_15 ;
int V_168 = V_162 ;
V_162 = ( V_162 * V_15 -> V_169 + 47999 ) / 48000 ;
if ( ! V_162 )
V_162 = V_168 ;
else
V_162 = ( ( V_162 + V_168 - 1 ) / V_168 ) *
V_168 ;
V_162 = F_76 ( V_15 , V_162 ) ;
if ( V_162 >= V_161 ) {
F_10 (KERN_WARNING SFX L_21 ,
bdl_pos_adj[chip->dev_index]) ;
V_162 = 0 ;
} else {
V_151 = F_71 ( V_2 , V_140 , V_13 ,
& V_153 , V_151 , V_162 ,
! V_140 -> V_15 -> V_170 ) ;
if ( V_151 < 0 )
goto error;
}
} else
V_162 = 0 ;
for ( V_99 = 0 ; V_99 < V_160 ; V_99 ++ ) {
if ( V_99 == V_160 - 1 && V_162 )
V_151 = F_71 ( V_2 , V_140 , V_13 , & V_153 , V_151 ,
V_161 - V_162 , 0 ) ;
else
V_151 = F_71 ( V_2 , V_140 , V_13 , & V_153 , V_151 ,
V_161 ,
! V_140 -> V_15 -> V_170 ) ;
if ( V_151 < 0 )
goto error;
}
return 0 ;
error:
F_10 (KERN_ERR SFX L_22 ,
azx_dev->bufsize, period_bytes) ;
return - V_157 ;
}
static void F_77 ( struct V_1 * V_2 , struct V_13 * V_13 )
{
unsigned char V_54 ;
int V_60 ;
F_56 ( V_2 , V_13 ) ;
F_52 ( V_13 , V_101 , F_53 ( V_13 , V_101 ) |
V_171 ) ;
F_34 ( 3 ) ;
V_60 = 300 ;
while ( ! ( ( V_54 = F_53 ( V_13 , V_101 ) ) & V_171 ) &&
-- V_60 )
;
V_54 &= ~ V_171 ;
F_52 ( V_13 , V_101 , V_54 ) ;
F_34 ( 3 ) ;
V_60 = 300 ;
while ( ( ( V_54 = F_53 ( V_13 , V_101 ) ) & V_171 ) &&
-- V_60 )
;
* V_13 -> V_113 = 0 ;
}
static int F_78 ( struct V_1 * V_2 , struct V_13 * V_13 )
{
unsigned int V_54 ;
F_56 ( V_2 , V_13 ) ;
V_54 = F_79 ( V_13 , V_101 ) ;
V_54 = ( V_54 & ~ V_172 ) |
( V_13 -> V_173 << V_174 ) ;
if ( ! F_2 ( V_2 ) )
V_54 |= V_175 ;
F_75 ( V_13 , V_101 , V_54 ) ;
F_75 ( V_13 , V_176 , V_13 -> V_165 ) ;
F_80 ( V_13 , V_177 , V_13 -> V_178 ) ;
F_80 ( V_13 , V_179 , V_13 -> V_155 - 1 ) ;
F_75 ( V_13 , V_163 , ( V_25 ) V_13 -> V_153 . V_3 ) ;
F_75 ( V_13 , V_164 , F_14 ( V_13 -> V_153 . V_3 ) ) ;
if ( V_2 -> V_180 [ 0 ] != V_181 ||
V_2 -> V_180 [ 1 ] != V_181 ) {
if ( ! ( F_40 ( V_2 , V_112 ) & V_182 ) )
F_13 ( V_2 , V_112 ,
( V_25 ) V_2 -> V_113 . V_3 | V_182 ) ;
}
F_75 ( V_13 , V_101 ,
F_79 ( V_13 , V_101 ) | V_102 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_49 = ( V_3 << 28 ) | ( V_183 << 20 ) |
( V_184 << 8 ) | V_185 ;
unsigned int V_51 ;
F_82 ( & V_2 -> V_53 -> V_186 ) ;
V_2 -> V_73 = 1 ;
F_47 ( V_2 -> V_53 , V_49 ) ;
V_51 = F_48 ( V_2 -> V_53 , V_3 ) ;
V_2 -> V_73 = 0 ;
F_83 ( & V_2 -> V_53 -> V_186 ) ;
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
if ( V_2 -> V_111 ) {
struct V_187 * V_188 ;
F_87 (p, &chip->pcm_list, list)
F_88 ( V_188 -> V_189 ) ;
F_89 ( V_2 -> V_53 ) ;
F_90 ( V_2 -> V_53 ) ;
}
#endif
V_53 -> V_76 = 0 ;
}
static int T_5 F_91 ( struct V_1 * V_2 , const char * V_190 )
{
struct V_191 V_192 ;
int V_193 , V_194 , V_19 ;
int V_195 ;
memset ( & V_192 , 0 , sizeof( V_192 ) ) ;
V_192 . V_55 = V_2 ;
V_192 . V_196 = V_190 ;
V_192 . V_21 = V_2 -> V_21 ;
V_192 . V_197 . V_198 = F_47 ;
V_192 . V_197 . V_199 = F_48 ;
V_192 . V_197 . V_200 = V_201 ;
V_192 . V_197 . V_202 = F_84 ;
#ifdef F_92
V_192 . V_203 = & V_203 ;
V_192 . V_197 . V_204 = V_205 ;
#endif
V_19 = F_93 ( V_2 -> V_206 , & V_192 , & V_2 -> V_53 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_2 -> V_43 & V_207 ) {
F_44 ( V_69 L_24 ) ;
V_2 -> V_53 -> V_68 = 1 ;
}
V_194 = 0 ;
V_195 = V_208 [ V_2 -> V_209 ] ;
if ( ! V_195 )
V_195 = V_210 ;
for ( V_193 = 0 ; V_193 < V_195 ; V_193 ++ ) {
if ( ( V_2 -> V_95 & ( 1 << V_193 ) ) & V_2 -> V_211 ) {
if ( F_81 ( V_2 , V_193 ) < 0 ) {
F_10 (KERN_WARNING SFX
L_25
L_26 , c) ;
V_2 -> V_95 &= ~ ( 1 << V_193 ) ;
F_85 ( V_2 ) ;
F_58 ( V_2 , 1 ) ;
}
}
}
if ( V_2 -> V_43 & V_212 ) {
F_44 ( V_69 L_27 ) ;
V_2 -> V_53 -> V_213 = 1 ;
V_2 -> V_53 -> V_74 = 1 ;
}
for ( V_193 = 0 ; V_193 < V_195 ; V_193 ++ ) {
if ( ( V_2 -> V_95 & ( 1 << V_193 ) ) & V_2 -> V_211 ) {
struct V_214 * V_215 ;
V_19 = F_94 ( V_2 -> V_53 , V_193 , & V_215 ) ;
if ( V_19 < 0 )
continue;
V_215 -> V_216 = V_2 -> V_216 ;
V_194 ++ ;
}
}
if ( ! V_194 ) {
F_10 (KERN_ERR SFX L_28 ) ;
return - V_217 ;
}
return 0 ;
}
static int T_6 F_95 ( struct V_1 * V_2 )
{
struct V_214 * V_215 ;
F_87 (codec, &chip->bus->codec_list, list) {
F_96 ( V_215 ) ;
}
return 0 ;
}
static inline struct V_13 *
F_97 ( struct V_1 * V_2 , struct V_149 * V_140 )
{
int V_218 , V_99 , V_219 ;
struct V_13 * V_51 = NULL ;
int V_220 = ( V_140 -> V_189 -> V_221 << 16 ) | ( V_140 -> V_222 << 2 ) |
( V_140 -> V_223 + 1 ) ;
if ( V_140 -> V_223 == V_224 ) {
V_218 = V_2 -> V_225 ;
V_219 = V_2 -> V_226 ;
} else {
V_218 = V_2 -> V_227 ;
V_219 = V_2 -> V_228 ;
}
for ( V_99 = 0 ; V_99 < V_219 ; V_99 ++ , V_218 ++ )
if ( ! V_2 -> V_13 [ V_218 ] . V_229 ) {
V_51 = & V_2 -> V_13 [ V_218 ] ;
if ( V_51 -> V_230 == V_220 )
break;
}
if ( V_51 ) {
V_51 -> V_229 = 1 ;
V_51 -> V_230 = V_220 ;
}
return V_51 ;
}
static inline void F_98 ( struct V_13 * V_13 )
{
V_13 -> V_229 = 0 ;
}
static int F_99 ( struct V_149 * V_140 )
{
struct V_187 * V_231 = F_100 ( V_140 ) ;
struct V_232 * V_233 = V_231 -> V_233 [ V_140 -> V_223 ] ;
struct V_1 * V_2 = V_231 -> V_2 ;
struct V_13 * V_13 ;
struct V_14 * V_15 = V_140 -> V_15 ;
unsigned long V_234 ;
int V_19 ;
int V_235 ;
F_82 ( & V_2 -> V_236 ) ;
V_13 = F_97 ( V_2 , V_140 ) ;
if ( V_13 == NULL ) {
F_83 ( & V_2 -> V_236 ) ;
return - V_94 ;
}
V_15 -> V_237 = V_238 ;
V_15 -> V_237 . V_239 = V_233 -> V_239 ;
V_15 -> V_237 . V_240 = V_233 -> V_240 ;
V_15 -> V_237 . V_241 = V_233 -> V_241 ;
V_15 -> V_237 . V_242 = V_233 -> V_242 ;
F_101 ( V_15 ) ;
F_102 ( V_15 , V_243 ) ;
if ( V_2 -> V_244 )
V_235 = 128 ;
else
V_235 = 4 ;
F_103 ( V_15 , 0 , V_245 ,
V_235 ) ;
F_103 ( V_15 , 0 , V_246 ,
V_235 ) ;
F_104 ( V_231 -> V_215 ) ;
V_19 = V_233 -> V_197 . V_247 ( V_233 , V_231 -> V_215 , V_140 ) ;
if ( V_19 < 0 ) {
F_98 ( V_13 ) ;
F_105 ( V_231 -> V_215 ) ;
F_83 ( & V_2 -> V_236 ) ;
return V_19 ;
}
F_101 ( V_15 ) ;
if ( F_106 ( ! V_15 -> V_237 . V_239 ) ||
F_106 ( ! V_15 -> V_237 . V_240 ) ||
F_106 ( ! V_15 -> V_237 . V_241 ) ||
F_106 ( ! V_15 -> V_237 . V_242 ) ) {
F_98 ( V_13 ) ;
V_233 -> V_197 . V_248 ( V_233 , V_231 -> V_215 , V_140 ) ;
F_105 ( V_231 -> V_215 ) ;
F_83 ( & V_2 -> V_236 ) ;
return - V_157 ;
}
F_107 ( & V_2 -> V_23 , V_234 ) ;
V_13 -> V_140 = V_140 ;
V_13 -> V_141 = 0 ;
F_108 ( & V_2 -> V_23 , V_234 ) ;
V_15 -> V_55 = V_13 ;
F_109 ( V_140 ) ;
F_83 ( & V_2 -> V_236 ) ;
return 0 ;
}
static int F_110 ( struct V_149 * V_140 )
{
struct V_187 * V_231 = F_100 ( V_140 ) ;
struct V_232 * V_233 = V_231 -> V_233 [ V_140 -> V_223 ] ;
struct V_1 * V_2 = V_231 -> V_2 ;
struct V_13 * V_13 = F_111 ( V_140 ) ;
unsigned long V_234 ;
F_82 ( & V_2 -> V_236 ) ;
F_107 ( & V_2 -> V_23 , V_234 ) ;
V_13 -> V_140 = NULL ;
V_13 -> V_141 = 0 ;
F_108 ( & V_2 -> V_23 , V_234 ) ;
F_98 ( V_13 ) ;
V_233 -> V_197 . V_248 ( V_233 , V_231 -> V_215 , V_140 ) ;
F_105 ( V_231 -> V_215 ) ;
F_83 ( & V_2 -> V_236 ) ;
return 0 ;
}
static int F_112 ( struct V_149 * V_140 ,
struct V_249 * V_250 )
{
struct V_187 * V_231 = F_100 ( V_140 ) ;
struct V_1 * V_2 = V_231 -> V_2 ;
struct V_14 * V_15 = V_140 -> V_15 ;
struct V_13 * V_13 = F_111 ( V_140 ) ;
int V_251 ;
F_6 ( V_2 , V_13 , V_15 , false ) ;
V_13 -> V_165 = 0 ;
V_13 -> V_161 = 0 ;
V_13 -> V_178 = 0 ;
V_251 = F_113 ( V_140 ,
F_114 ( V_250 ) ) ;
if ( V_251 < 0 )
return V_251 ;
F_6 ( V_2 , V_13 , V_15 , true ) ;
return V_251 ;
}
static int F_115 ( struct V_149 * V_140 )
{
struct V_187 * V_231 = F_100 ( V_140 ) ;
struct V_13 * V_13 = F_111 ( V_140 ) ;
struct V_1 * V_2 = V_231 -> V_2 ;
struct V_14 * V_15 = V_140 -> V_15 ;
struct V_232 * V_233 = V_231 -> V_233 [ V_140 -> V_223 ] ;
F_75 ( V_13 , V_163 , 0 ) ;
F_75 ( V_13 , V_164 , 0 ) ;
F_75 ( V_13 , V_101 , 0 ) ;
V_13 -> V_165 = 0 ;
V_13 -> V_161 = 0 ;
V_13 -> V_178 = 0 ;
F_116 ( V_231 -> V_215 , V_233 , V_140 ) ;
F_6 ( V_2 , V_13 , V_15 , false ) ;
return F_117 ( V_140 ) ;
}
static int F_118 ( struct V_149 * V_140 )
{
struct V_187 * V_231 = F_100 ( V_140 ) ;
struct V_1 * V_2 = V_231 -> V_2 ;
struct V_13 * V_13 = F_111 ( V_140 ) ;
struct V_232 * V_233 = V_231 -> V_233 [ V_140 -> V_223 ] ;
struct V_14 * V_15 = V_140 -> V_15 ;
unsigned int V_165 , V_161 , V_178 , V_173 ;
int V_19 ;
struct V_252 * V_253 =
F_119 ( V_231 -> V_215 , V_233 -> V_254 ) ;
unsigned short V_255 = V_253 ? V_253 -> V_255 : 0 ;
F_77 ( V_2 , V_13 ) ;
V_178 = F_120 ( V_15 -> V_169 ,
V_15 -> V_256 ,
V_15 -> V_257 ,
V_233 -> V_258 ,
V_255 ) ;
if ( ! V_178 ) {
F_10 (KERN_ERR SFX
L_29 ,
runtime->rate, runtime->channels, runtime->format) ;
return - V_157 ;
}
V_165 = F_121 ( V_140 ) ;
V_161 = F_122 ( V_140 ) ;
F_36 ( V_69 L_30 ,
V_165 , V_178 ) ;
if ( V_165 != V_13 -> V_165 ||
V_161 != V_13 -> V_161 ||
V_178 != V_13 -> V_178 ) {
V_13 -> V_165 = V_165 ;
V_13 -> V_161 = V_161 ;
V_13 -> V_178 = V_178 ;
V_19 = F_74 ( V_2 , V_140 , V_13 ) ;
if ( V_19 < 0 )
return V_19 ;
}
V_13 -> V_259 = ( ( ( V_15 -> V_260 * 24000 ) /
V_15 -> V_169 ) * 1000 ) ;
F_78 ( V_2 , V_13 ) ;
if ( V_140 -> V_223 == V_224 )
V_13 -> V_261 = F_123 ( V_13 , V_262 ) + 1 ;
else
V_13 -> V_261 = 0 ;
V_173 = V_13 -> V_173 ;
if ( ( V_2 -> V_43 & V_44 ) &&
V_173 > V_2 -> V_228 )
V_173 -= V_2 -> V_228 ;
return F_124 ( V_231 -> V_215 , V_233 , V_173 ,
V_13 -> V_178 , V_140 ) ;
}
static int F_125 ( struct V_149 * V_140 , int V_49 )
{
struct V_187 * V_231 = F_100 ( V_140 ) ;
struct V_1 * V_2 = V_231 -> V_2 ;
struct V_13 * V_13 ;
struct V_149 * V_263 ;
int V_264 = 0 , V_265 , V_266 = 0 , V_267 = 0 ;
int V_268 , V_60 ;
switch ( V_49 ) {
case V_269 :
V_264 = 1 ;
case V_270 :
case V_271 :
V_265 = 1 ;
break;
case V_272 :
case V_273 :
case V_274 :
V_265 = 0 ;
break;
default:
return - V_157 ;
}
F_126 (s, substream) {
if ( V_263 -> V_189 -> V_206 != V_140 -> V_189 -> V_206 )
continue;
V_13 = F_111 ( V_263 ) ;
V_267 |= 1 << V_13 -> V_109 ;
V_266 ++ ;
F_127 ( V_263 , V_140 ) ;
}
F_66 ( & V_2 -> V_23 ) ;
if ( V_266 > 1 ) {
if ( V_2 -> V_43 & V_275 )
F_13 ( V_2 , V_276 ,
F_40 ( V_2 , V_276 ) | V_267 ) ;
else
F_13 ( V_2 , V_277 , F_40 ( V_2 , V_277 ) | V_267 ) ;
}
F_126 (s, substream) {
if ( V_263 -> V_189 -> V_206 != V_140 -> V_189 -> V_206 )
continue;
V_13 = F_111 ( V_263 ) ;
if ( V_265 ) {
V_13 -> V_278 = F_40 ( V_2 , V_279 ) ;
if ( ! V_264 )
V_13 -> V_278 -=
V_13 -> V_259 ;
F_55 ( V_2 , V_13 ) ;
} else {
F_57 ( V_2 , V_13 ) ;
}
V_13 -> V_141 = V_265 ;
}
F_67 ( & V_2 -> V_23 ) ;
if ( V_265 ) {
if ( V_266 == 1 )
return 0 ;
for ( V_60 = 5000 ; V_60 ; V_60 -- ) {
V_268 = 0 ;
F_126 (s, substream) {
if ( V_263 -> V_189 -> V_206 != V_140 -> V_189 -> V_206 )
continue;
V_13 = F_111 ( V_263 ) ;
if ( ! ( F_53 ( V_13 , V_103 ) &
V_280 ) )
V_268 ++ ;
}
if ( ! V_268 )
break;
F_128 () ;
}
} else {
for ( V_60 = 5000 ; V_60 ; V_60 -- ) {
V_268 = 0 ;
F_126 (s, substream) {
if ( V_263 -> V_189 -> V_206 != V_140 -> V_189 -> V_206 )
continue;
V_13 = F_111 ( V_263 ) ;
if ( F_53 ( V_13 , V_101 ) &
V_110 )
V_268 ++ ;
}
if ( ! V_268 )
break;
F_128 () ;
}
}
if ( V_266 > 1 ) {
F_66 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_43 & V_275 )
F_13 ( V_2 , V_276 ,
F_40 ( V_2 , V_276 ) & ~ V_267 ) ;
else
F_13 ( V_2 , V_277 , F_40 ( V_2 , V_277 ) & ~ V_267 ) ;
F_67 ( & V_2 -> V_23 ) ;
}
return 0 ;
}
static unsigned int F_129 ( struct V_1 * V_2 ,
struct V_13 * V_13 )
{
unsigned int V_281 , V_282 , V_283 ;
unsigned int V_284 , V_285 , V_286 ;
unsigned int V_261 ;
V_281 = F_79 ( V_13 , V_287 ) ;
if ( V_13 -> V_140 -> V_223 == V_224 ) {
return V_281 ;
}
V_285 = F_26 ( * V_13 -> V_113 ) ;
V_285 %= V_13 -> V_161 ;
V_261 = F_130 ( V_2 -> V_288 + V_289 ) ;
if ( V_13 -> V_108 ) {
if ( V_281 <= V_261 )
return 0 ;
V_13 -> V_108 = 0 ;
}
if ( V_281 <= V_261 )
V_282 = V_13 -> V_165 + V_281 - V_261 ;
else
V_282 = V_281 - V_261 ;
V_286 = V_282 % V_13 -> V_161 ;
V_284 = V_281 % V_13 -> V_161 ;
if ( V_284 >= V_261 )
V_283 = V_281 - V_284 ;
else if ( V_285 >= V_286 )
V_283 = V_282 - V_286 ;
else {
V_283 = V_282 - V_286 + V_13 -> V_161 ;
if ( V_283 >= V_13 -> V_165 )
V_283 = 0 ;
}
return V_283 + V_285 ;
}
static unsigned int F_131 ( struct V_1 * V_2 ,
struct V_13 * V_13 ,
bool V_290 )
{
unsigned int V_291 ;
int V_223 = V_13 -> V_140 -> V_223 ;
switch ( V_2 -> V_180 [ V_223 ] ) {
case V_181 :
V_291 = F_79 ( V_13 , V_287 ) ;
break;
case V_292 :
V_291 = F_129 ( V_2 , V_13 ) ;
break;
default:
V_291 = F_26 ( * V_13 -> V_113 ) ;
if ( V_290 && V_2 -> V_180 [ V_223 ] == V_293 ) {
if ( ! V_291 || V_291 == ( V_25 ) - 1 ) {
F_132 ( V_294
L_31
L_32 ) ;
V_2 -> V_180 [ V_223 ] = V_181 ;
V_291 = F_79 ( V_13 , V_287 ) ;
} else
V_2 -> V_180 [ V_223 ] = V_295 ;
}
break;
}
if ( V_291 >= V_13 -> V_165 )
V_291 = 0 ;
return V_291 ;
}
static T_7 F_133 ( struct V_149 * V_140 )
{
struct V_187 * V_231 = F_100 ( V_140 ) ;
struct V_1 * V_2 = V_231 -> V_2 ;
struct V_13 * V_13 = F_111 ( V_140 ) ;
return F_134 ( V_140 -> V_15 ,
F_131 ( V_2 , V_13 , false ) ) ;
}
static int F_68 ( struct V_1 * V_2 , struct V_13 * V_13 )
{
V_25 V_296 ;
unsigned int V_291 ;
int V_223 ;
V_296 = F_40 ( V_2 , V_279 ) - V_13 -> V_278 ;
if ( V_296 < ( V_13 -> V_259 * 2 ) / 3 )
return - 1 ;
V_223 = V_13 -> V_140 -> V_223 ;
V_291 = F_131 ( V_2 , V_13 , true ) ;
if ( F_135 ( ! V_13 -> V_161 ,
L_33 ) )
return - 1 ;
if ( V_296 < ( V_13 -> V_259 * 5 ) / 4 &&
V_291 % V_13 -> V_161 > V_13 -> V_161 / 2 )
return V_166 [ V_2 -> V_167 ] ? 0 : - 1 ;
V_13 -> V_278 += V_296 ;
return 1 ;
}
static void F_136 ( struct V_297 * V_298 )
{
struct V_1 * V_2 = F_137 ( V_298 , struct V_1 , V_145 ) ;
int V_99 , V_299 , V_137 ;
if ( ! V_2 -> V_300 ) {
F_132 ( V_294
L_34
L_35 ,
V_2 -> V_206 -> V_222 ) ;
V_2 -> V_300 = 1 ;
}
for (; ; ) {
V_299 = 0 ;
F_12 ( & V_2 -> V_23 ) ;
for ( V_99 = 0 ; V_99 < V_2 -> V_100 ; V_99 ++ ) {
struct V_13 * V_13 = & V_2 -> V_13 [ V_99 ] ;
if ( ! V_13 -> V_143 ||
! V_13 -> V_140 ||
! V_13 -> V_141 )
continue;
V_137 = F_68 ( V_2 , V_13 ) ;
if ( V_137 > 0 ) {
V_13 -> V_143 = 0 ;
F_67 ( & V_2 -> V_23 ) ;
F_69 ( V_13 -> V_140 ) ;
F_66 ( & V_2 -> V_23 ) ;
} else if ( V_137 < 0 ) {
V_299 = 0 ;
} else
V_299 ++ ;
}
F_17 ( & V_2 -> V_23 ) ;
if ( ! V_299 )
return;
F_33 ( 1 ) ;
}
}
static void F_138 ( struct V_1 * V_2 )
{
int V_99 ;
F_12 ( & V_2 -> V_23 ) ;
for ( V_99 = 0 ; V_99 < V_2 -> V_100 ; V_99 ++ )
V_2 -> V_13 [ V_99 ] . V_143 = 0 ;
F_17 ( & V_2 -> V_23 ) ;
}
static int F_139 ( struct V_149 * V_140 ,
struct V_301 * V_11 )
{
struct V_187 * V_231 = F_100 ( V_140 ) ;
struct V_1 * V_2 = V_231 -> V_2 ;
if ( ! F_2 ( V_2 ) )
V_11 -> V_302 = F_140 ( V_11 -> V_302 ) ;
return F_141 ( V_140 , V_11 ) ;
}
static void F_142 ( struct V_303 * V_189 )
{
struct V_187 * V_231 = V_189 -> V_55 ;
if ( V_231 ) {
F_143 ( & V_231 -> V_304 ) ;
F_144 ( V_231 ) ;
}
}
static int
V_201 ( struct V_52 * V_53 , struct V_214 * V_215 ,
struct V_305 * V_306 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_303 * V_189 ;
struct V_187 * V_231 ;
int V_307 = V_306 -> V_221 ;
unsigned int V_4 ;
int V_263 , V_19 ;
F_87 (apcm, &chip->pcm_list, list) {
if ( V_231 -> V_189 -> V_221 == V_307 ) {
F_10 (KERN_ERR SFX L_36 , pcm_dev) ;
return - V_94 ;
}
}
V_19 = F_145 ( V_2 -> V_206 , V_306 -> V_308 , V_307 ,
V_306 -> V_223 [ V_224 ] . V_309 ,
V_306 -> V_223 [ V_310 ] . V_309 ,
& V_189 ) ;
if ( V_19 < 0 )
return V_19 ;
F_146 ( V_189 -> V_308 , V_306 -> V_308 , sizeof( V_189 -> V_308 ) ) ;
V_231 = F_147 ( sizeof( * V_231 ) , V_311 ) ;
if ( V_231 == NULL )
return - V_312 ;
V_231 -> V_2 = V_2 ;
V_231 -> V_189 = V_189 ;
V_231 -> V_215 = V_215 ;
V_189 -> V_55 = V_231 ;
V_189 -> V_313 = F_142 ;
if ( V_306 -> V_314 == V_315 )
V_189 -> V_316 = V_317 ;
F_148 ( & V_231 -> V_304 , & V_2 -> V_318 ) ;
V_306 -> V_189 = V_189 ;
for ( V_263 = 0 ; V_263 < 2 ; V_263 ++ ) {
V_231 -> V_233 [ V_263 ] = & V_306 -> V_223 [ V_263 ] ;
if ( V_306 -> V_223 [ V_263 ] . V_309 )
F_149 ( V_189 , V_263 , & V_319 ) ;
}
V_4 = V_320 * 1024 ;
if ( V_4 > V_321 )
V_4 = V_321 ;
F_150 ( V_189 , V_322 ,
F_9 ( V_2 -> V_21 ) ,
V_4 , V_321 ) ;
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
V_13 -> V_113 = ( V_25 V_323 * ) ( V_2 -> V_113 . V_11 + V_99 * 8 ) ;
V_13 -> V_324 = V_2 -> V_288 + ( 0x20 * V_99 + 0x80 ) ;
V_13 -> V_139 = 1 << V_99 ;
V_13 -> V_109 = V_99 ;
V_13 -> V_173 = V_99 + 1 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , int V_325 )
{
if ( F_154 ( V_2 -> V_21 -> V_72 , F_65 ,
V_2 -> V_71 ? 0 : V_326 ,
V_327 , V_2 ) ) {
F_132 ( V_77 L_37
L_38 , V_2 -> V_21 -> V_72 ) ;
if ( V_325 )
F_155 ( V_2 -> V_206 ) ;
return - 1 ;
}
V_2 -> V_72 = V_2 -> V_21 -> V_72 ;
F_156 ( V_2 -> V_21 , ! V_2 -> V_71 ) ;
return 0 ;
}
static void F_85 ( struct V_1 * V_2 )
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
static void V_205 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_214 * V_193 ;
int V_328 = 0 ;
F_87 (c, &bus->codec_list, list) {
if ( V_193 -> V_328 ) {
V_328 = 1 ;
break;
}
}
if ( V_328 )
F_58 ( V_2 , 1 ) ;
else if ( V_2 -> V_141 && V_329 &&
! V_53 -> V_330 )
F_85 ( V_2 ) ;
}
static int F_157 ( struct V_115 * V_21 , T_8 V_331 )
{
struct V_332 * V_206 = F_158 ( V_21 ) ;
struct V_1 * V_2 = V_206 -> V_55 ;
struct V_187 * V_188 ;
F_159 ( V_206 , V_333 ) ;
F_138 ( V_2 ) ;
F_87 (p, &chip->pcm_list, list)
F_88 ( V_188 -> V_189 ) ;
if ( V_2 -> V_111 )
F_89 ( V_2 -> V_53 ) ;
F_85 ( V_2 ) ;
if ( V_2 -> V_72 >= 0 ) {
F_37 ( V_2 -> V_72 , V_2 ) ;
V_2 -> V_72 = - 1 ;
}
if ( V_2 -> V_71 )
F_38 ( V_2 -> V_21 ) ;
F_160 ( V_21 ) ;
F_161 ( V_21 ) ;
F_162 ( V_21 , F_163 ( V_21 , V_331 ) ) ;
return 0 ;
}
static int F_164 ( struct V_115 * V_21 )
{
struct V_332 * V_206 = F_158 ( V_21 ) ;
struct V_1 * V_2 = V_206 -> V_55 ;
F_162 ( V_21 , V_334 ) ;
F_165 ( V_21 ) ;
if ( F_166 ( V_21 ) < 0 ) {
F_132 ( V_77 L_39
L_38 ) ;
F_155 ( V_206 ) ;
return - V_84 ;
}
F_167 ( V_21 ) ;
if ( V_2 -> V_71 )
if ( F_168 ( V_21 ) < 0 )
V_2 -> V_71 = 0 ;
if ( F_39 ( V_2 , 1 ) < 0 )
return - V_84 ;
F_62 ( V_2 ) ;
F_58 ( V_2 , 1 ) ;
F_90 ( V_2 -> V_53 ) ;
F_159 ( V_206 , V_335 ) ;
return 0 ;
}
static int F_169 ( struct V_336 * V_337 , unsigned long V_338 , void * V_10 )
{
struct V_1 * V_2 = F_137 ( V_337 , struct V_1 , V_339 ) ;
F_170 ( V_2 -> V_53 ) ;
F_85 ( V_2 ) ;
return V_340 ;
}
static void F_171 ( struct V_1 * V_2 )
{
V_2 -> V_339 . V_341 = F_169 ;
F_172 ( & V_2 -> V_339 ) ;
}
static void F_173 ( struct V_1 * V_2 )
{
if ( V_2 -> V_339 . V_341 )
F_174 ( & V_2 -> V_339 ) ;
}
static void F_175 ( struct V_115 * V_21 ,
enum V_342 V_331 )
{
struct V_332 * V_206 = F_158 ( V_21 ) ;
struct V_1 * V_2 = V_206 -> V_55 ;
bool V_87 ;
if ( V_2 -> V_343 )
return;
V_87 = ( V_331 == V_344 ) ;
if ( V_2 -> V_87 == V_87 )
return;
if ( ! V_2 -> V_53 ) {
V_2 -> V_87 = V_87 ;
if ( ! V_87 ) {
F_10 (KERN_INFO SFX
L_40 ,
pci_name(chip->pci)) ;
if ( F_176 ( V_2 ) < 0 ||
F_177 ( V_2 ) < 0 ) {
F_10 (KERN_ERR SFX
L_41 ,
pci_name(chip->pci)) ;
V_2 -> V_343 = true ;
}
}
} else {
F_10 (KERN_INFO SFX
L_42 ,
disabled ? L_43 : L_44 ,
pci_name(chip->pci)) ;
if ( V_87 ) {
F_157 ( V_21 , V_345 ) ;
V_2 -> V_87 = true ;
F_178 ( V_2 -> V_53 ) ;
} else {
F_179 ( V_2 -> V_53 ) ;
V_2 -> V_87 = false ;
F_164 ( V_21 ) ;
}
}
}
static bool F_180 ( struct V_115 * V_21 )
{
struct V_332 * V_206 = F_158 ( V_21 ) ;
struct V_1 * V_2 = V_206 -> V_55 ;
if ( V_2 -> V_343 )
return false ;
if ( V_2 -> V_87 || ! V_2 -> V_53 )
return true ;
if ( F_178 ( V_2 -> V_53 ) )
return false ;
F_179 ( V_2 -> V_53 ) ;
return true ;
}
static void T_6 F_181 ( struct V_1 * V_2 )
{
struct V_115 * V_188 = F_182 ( V_2 -> V_21 ) ;
if ( V_188 ) {
F_10 (KERN_INFO SFX
L_45 ,
pci_name(chip->pci)) ;
V_2 -> V_346 = 1 ;
F_183 ( V_188 ) ;
}
}
static int T_6 F_184 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_346 )
return 0 ;
return F_185 ( V_2 -> V_21 , & V_347 ,
V_348 ,
V_2 -> V_53 != NULL ) ;
}
static int F_186 ( struct V_1 * V_2 )
{
int V_99 ;
F_173 ( V_2 ) ;
if ( V_346 ( V_2 ) ) {
if ( V_2 -> V_87 && V_2 -> V_53 )
F_179 ( V_2 -> V_53 ) ;
F_187 ( V_2 -> V_21 ) ;
}
if ( V_2 -> V_111 ) {
F_138 ( V_2 ) ;
for ( V_99 = 0 ; V_99 < V_2 -> V_100 ; V_99 ++ )
F_57 ( V_2 , & V_2 -> V_13 [ V_99 ] ) ;
F_85 ( V_2 ) ;
}
if ( V_2 -> V_72 >= 0 )
F_37 ( V_2 -> V_72 , ( void * ) V_2 ) ;
if ( V_2 -> V_71 )
F_38 ( V_2 -> V_21 ) ;
if ( V_2 -> V_288 )
F_188 ( V_2 -> V_288 ) ;
if ( V_2 -> V_13 ) {
for ( V_99 = 0 ; V_99 < V_2 -> V_100 ; V_99 ++ )
if ( V_2 -> V_13 [ V_99 ] . V_153 . V_11 ) {
F_5 ( V_2 , & V_2 -> V_13 [ V_99 ] . V_153 , false ) ;
F_189 ( & V_2 -> V_13 [ V_99 ] . V_153 ) ;
}
}
if ( V_2 -> V_22 . V_11 ) {
F_5 ( V_2 , & V_2 -> V_22 , false ) ;
F_189 ( & V_2 -> V_22 ) ;
}
if ( V_2 -> V_113 . V_11 ) {
F_5 ( V_2 , & V_2 -> V_113 , false ) ;
F_189 ( & V_2 -> V_113 ) ;
}
if ( V_2 -> V_349 )
F_190 ( V_2 -> V_21 ) ;
F_160 ( V_2 -> V_21 ) ;
F_144 ( V_2 -> V_13 ) ;
F_144 ( V_2 ) ;
return 0 ;
}
static int F_191 ( struct V_350 * V_221 )
{
return F_186 ( V_221 -> V_351 ) ;
}
static struct V_115 T_6 * F_182 ( struct V_115 * V_21 )
{
struct V_115 * V_188 ;
switch ( V_21 -> V_352 ) {
case V_353 :
case V_354 :
case V_355 :
if ( V_21 -> V_356 == 1 ) {
V_188 = F_192 ( F_193 ( V_21 -> V_53 ) ,
V_21 -> V_53 -> V_222 , 0 ) ;
if ( V_188 ) {
if ( ( V_188 -> V_357 >> 8 ) == V_358 )
return V_188 ;
F_183 ( V_188 ) ;
}
}
break;
}
return NULL ;
}
static bool T_6 F_194 ( struct V_115 * V_21 )
{
bool V_359 = false ;
struct V_115 * V_188 = F_182 ( V_21 ) ;
if ( V_188 ) {
if ( F_195 ( V_188 ) == V_344 )
V_359 = true ;
F_183 ( V_188 ) ;
}
return V_359 ;
}
static int T_6 F_196 ( struct V_1 * V_2 , int V_360 )
{
const struct V_361 * V_362 ;
switch ( V_360 ) {
case V_181 :
case V_295 :
case V_292 :
case V_363 :
return V_360 ;
}
V_362 = F_197 ( V_2 -> V_21 , V_364 ) ;
if ( V_362 ) {
F_132 ( V_365
L_46
L_47 ,
V_362 -> V_366 , V_362 -> V_367 , V_362 -> V_368 ) ;
return V_362 -> V_366 ;
}
if ( V_2 -> V_43 & V_369 ) {
F_44 ( V_69 L_48 ) ;
return V_292 ;
}
if ( V_2 -> V_43 & V_370 ) {
F_44 ( V_69 L_49 ) ;
return V_181 ;
}
return V_293 ;
}
static void T_6 F_198 ( struct V_1 * V_2 , int V_218 )
{
const struct V_361 * V_362 ;
V_2 -> V_211 = V_371 [ V_218 ] ;
if ( V_2 -> V_211 == - 1 ) {
V_362 = F_197 ( V_2 -> V_21 , V_372 ) ;
if ( V_362 ) {
F_132 ( V_365
L_50
L_47 ,
V_362 -> V_366 , V_362 -> V_367 , V_362 -> V_368 ) ;
V_2 -> V_211 = V_362 -> V_366 ;
}
}
if ( V_2 -> V_211 != - 1 &&
( V_2 -> V_211 & V_373 ) ) {
V_2 -> V_95 = V_2 -> V_211 & 0xff ;
F_132 ( V_365 L_51 ,
V_2 -> V_95 ) ;
}
}
static void T_6 F_199 ( struct V_1 * V_2 )
{
const struct V_361 * V_362 ;
if ( V_374 >= 0 ) {
V_2 -> V_71 = ! ! V_374 ;
return;
}
V_2 -> V_71 = 1 ;
V_362 = F_197 ( V_2 -> V_21 , V_375 ) ;
if ( V_362 ) {
F_132 ( V_365
L_52 ,
V_362 -> V_367 , V_362 -> V_368 , V_362 -> V_366 ) ;
V_2 -> V_71 = V_362 -> V_366 ;
return;
}
if ( V_2 -> V_43 & V_376 ) {
F_132 ( V_365 L_53 ) ;
V_2 -> V_71 = 0 ;
}
}
static void T_6 F_200 ( struct V_1 * V_2 )
{
bool V_131 = V_2 -> V_131 ;
switch ( V_2 -> V_209 ) {
case V_377 :
if ( V_131 ) {
T_3 V_54 ;
F_60 ( V_2 -> V_21 , 0x42 , & V_54 ) ;
if ( ! ( V_54 & 0x80 ) && V_2 -> V_21 -> V_378 == 0x30 )
V_131 = false ;
}
break;
case V_379 :
V_131 = false ;
break;
}
if ( V_131 != V_2 -> V_131 ) {
F_10 (KERN_INFO SFX L_54 ,
snoop ? L_55 : L_56 ) ;
V_2 -> V_131 = V_131 ;
}
}
static int T_6 F_201 ( struct V_332 * V_206 , struct V_115 * V_21 ,
int V_218 , unsigned int V_43 ,
struct V_1 * * V_380 )
{
static struct V_381 V_197 = {
. V_382 = F_191 ,
} ;
struct V_1 * V_2 ;
int V_19 ;
* V_380 = NULL ;
V_19 = F_166 ( V_21 ) ;
if ( V_19 < 0 )
return V_19 ;
V_2 = F_147 ( sizeof( * V_2 ) , V_311 ) ;
if ( ! V_2 ) {
F_10 (KERN_ERR SFX L_57 ) ;
F_160 ( V_21 ) ;
return - V_312 ;
}
F_202 ( & V_2 -> V_23 ) ;
F_203 ( & V_2 -> V_236 ) ;
V_2 -> V_206 = V_206 ;
V_2 -> V_21 = V_21 ;
V_2 -> V_72 = - 1 ;
V_2 -> V_43 = V_43 ;
V_2 -> V_209 = V_43 & 0xff ;
F_199 ( V_2 ) ;
V_2 -> V_167 = V_218 ;
F_204 ( & V_2 -> V_145 , F_136 ) ;
F_205 ( & V_2 -> V_318 ) ;
F_181 ( V_2 ) ;
V_2 -> V_180 [ 0 ] = V_2 -> V_180 [ 1 ] =
F_196 ( V_2 , V_180 [ V_218 ] ) ;
if ( V_2 -> V_180 [ 0 ] == V_363 ) {
V_2 -> V_180 [ 0 ] = V_181 ;
V_2 -> V_180 [ 1 ] = V_293 ;
}
F_198 ( V_2 , V_218 ) ;
V_2 -> V_78 = V_78 ;
V_2 -> V_131 = V_383 ;
F_200 ( V_2 ) ;
if ( V_166 [ V_218 ] < 0 ) {
switch ( V_2 -> V_209 ) {
case V_384 :
case V_385 :
V_166 [ V_218 ] = 1 ;
break;
default:
V_166 [ V_218 ] = 32 ;
break;
}
}
if ( F_194 ( V_21 ) ) {
F_10 (KERN_INFO SFX L_58 ,
pci_name(pci)) ;
if ( V_346 ( V_2 ) ) {
F_10 (KERN_INFO SFX L_59 ) ;
V_2 -> V_87 = true ;
goto V_137;
}
F_144 ( V_2 ) ;
F_160 ( V_21 ) ;
return - V_217 ;
}
V_19 = F_176 ( V_2 ) ;
if ( V_19 < 0 ) {
F_186 ( V_2 ) ;
return V_19 ;
}
V_137:
V_19 = F_184 ( V_2 ) ;
if ( V_19 < 0 ) {
F_10 (KERN_ERR SFX
L_60 ) ;
F_186 ( V_2 ) ;
return V_19 ;
}
V_19 = F_206 ( V_206 , V_386 , V_2 , & V_197 ) ;
if ( V_19 < 0 ) {
F_10 (KERN_ERR SFX L_61 ) ;
F_186 ( V_2 ) ;
return V_19 ;
}
* V_380 = V_2 ;
return 0 ;
}
static int T_5 F_176 ( struct V_1 * V_2 )
{
int V_218 = V_2 -> V_167 ;
struct V_115 * V_21 = V_2 -> V_21 ;
struct V_332 * V_206 = V_2 -> V_206 ;
int V_99 , V_19 ;
unsigned short V_387 ;
#if V_388 != 64
if ( V_2 -> V_209 == V_389 ) {
T_9 V_390 ;
F_63 ( V_21 , 0x40 , & V_390 ) ;
F_64 ( V_21 , 0x40 , V_390 | 0x10 ) ;
F_207 ( V_21 , V_391 , 0 ) ;
}
#endif
V_19 = F_208 ( V_21 , L_62 ) ;
if ( V_19 < 0 )
return V_19 ;
V_2 -> V_349 = 1 ;
V_2 -> V_3 = F_209 ( V_21 , 0 ) ;
V_2 -> V_288 = F_210 ( V_21 , 0 ) ;
if ( V_2 -> V_288 == NULL ) {
F_10 (KERN_ERR SFX L_63 ) ;
return - V_217 ;
}
if ( V_2 -> V_71 )
if ( F_168 ( V_21 ) < 0 )
V_2 -> V_71 = 0 ;
if ( F_39 ( V_2 , 0 ) < 0 )
return - V_94 ;
F_167 ( V_21 ) ;
F_211 ( V_2 -> V_72 ) ;
V_387 = F_42 ( V_2 , V_392 ) ;
F_36 ( V_69 L_64 , V_387 ) ;
if ( V_2 -> V_21 -> V_352 == V_353 ) {
struct V_115 * V_393 ;
V_393 = F_212 ( V_353 ,
V_394 ,
NULL ) ;
if ( V_393 ) {
if ( V_393 -> V_378 < 0x30 )
V_387 &= ~ V_395 ;
F_183 ( V_393 ) ;
}
}
if ( V_2 -> V_43 & V_396 ) {
F_44 ( V_69 L_65 ) ;
V_387 &= ~ V_395 ;
}
if ( V_244 >= 0 )
V_2 -> V_244 = ! ! V_244 ;
else {
if ( V_2 -> V_43 & V_397 )
V_2 -> V_244 = 0 ;
else if ( V_2 -> V_43 & V_398 )
V_2 -> V_244 = 1 ;
else
V_2 -> V_244 = 1 ;
}
if ( ( V_387 & V_395 ) && ! F_213 ( V_21 , F_214 ( 64 ) ) )
F_215 ( V_21 , F_214 ( 64 ) ) ;
else {
F_213 ( V_21 , F_214 ( 32 ) ) ;
F_215 ( V_21 , F_214 ( 32 ) ) ;
}
V_2 -> V_228 = ( V_387 >> 8 ) & 0x0f ;
V_2 -> V_226 = ( V_387 >> 12 ) & 0x0f ;
if ( ! V_2 -> V_226 && ! V_2 -> V_228 ) {
switch ( V_2 -> V_209 ) {
case V_389 :
V_2 -> V_226 = V_399 ;
V_2 -> V_228 = V_400 ;
break;
case V_401 :
case V_379 :
V_2 -> V_226 = V_402 ;
V_2 -> V_228 = V_403 ;
break;
case V_404 :
default:
V_2 -> V_226 = V_405 ;
V_2 -> V_228 = V_406 ;
break;
}
}
V_2 -> V_227 = 0 ;
V_2 -> V_225 = V_2 -> V_228 ;
V_2 -> V_100 = V_2 -> V_226 + V_2 -> V_228 ;
V_2 -> V_13 = F_216 ( V_2 -> V_100 , sizeof( * V_2 -> V_13 ) ,
V_311 ) ;
if ( ! V_2 -> V_13 ) {
F_10 (KERN_ERR SFX L_66 ) ;
return - V_312 ;
}
for ( V_99 = 0 ; V_99 < V_2 -> V_100 ; V_99 ++ ) {
V_19 = F_8 ( V_20 ,
F_9 ( V_2 -> V_21 ) ,
V_407 , & V_2 -> V_13 [ V_99 ] . V_153 ) ;
if ( V_19 < 0 ) {
F_10 (KERN_ERR SFX L_67 ) ;
return - V_312 ;
}
F_5 ( V_2 , & V_2 -> V_13 [ V_99 ] . V_153 , true ) ;
}
V_19 = F_8 ( V_20 ,
F_9 ( V_2 -> V_21 ) ,
V_2 -> V_100 * 8 , & V_2 -> V_113 ) ;
if ( V_19 < 0 ) {
F_10 (KERN_ERR SFX L_68 ) ;
return - V_312 ;
}
F_5 ( V_2 , & V_2 -> V_113 , true ) ;
V_19 = F_7 ( V_2 ) ;
if ( V_19 < 0 )
return V_19 ;
F_153 ( V_2 ) ;
F_62 ( V_2 ) ;
F_58 ( V_2 , ( V_408 [ V_218 ] & 2 ) == 0 ) ;
if ( ! V_2 -> V_95 ) {
F_10 (KERN_ERR SFX L_69 ) ;
return - V_409 ;
}
strcpy ( V_206 -> V_410 , L_70 ) ;
F_146 ( V_206 -> V_411 , V_412 [ V_2 -> V_209 ] ,
sizeof( V_206 -> V_411 ) ) ;
snprintf ( V_206 -> V_413 , sizeof( V_206 -> V_413 ) ,
L_71 ,
V_206 -> V_411 , V_2 -> V_3 , V_2 -> V_72 ) ;
return 0 ;
}
static void F_217 ( struct V_1 * V_2 )
{
#ifdef F_92
struct V_214 * V_215 ;
F_87 (codec, &chip->bus->codec_list, list) {
F_105 ( V_215 ) ;
}
#endif
}
static int T_6 F_218 ( struct V_115 * V_21 ,
const struct V_414 * V_415 )
{
static int V_218 ;
struct V_332 * V_206 ;
struct V_1 * V_2 ;
int V_19 ;
if ( V_218 >= V_416 )
return - V_409 ;
if ( ! V_417 [ V_218 ] ) {
V_218 ++ ;
return - V_418 ;
}
V_19 = F_219 ( V_109 [ V_218 ] , V_419 [ V_218 ] , V_420 , 0 , & V_206 ) ;
if ( V_19 < 0 ) {
F_10 (KERN_ERR SFX L_72 ) ;
return V_19 ;
}
F_220 ( V_206 , & V_21 -> V_218 ) ;
V_19 = F_201 ( V_206 , V_21 , V_218 , V_415 -> V_421 , & V_2 ) ;
if ( V_19 < 0 )
goto V_422;
V_206 -> V_55 = V_2 ;
if ( ! V_2 -> V_87 ) {
V_19 = F_177 ( V_2 ) ;
if ( V_19 < 0 )
goto V_422;
}
F_221 ( V_21 , V_206 ) ;
V_218 ++ ;
return 0 ;
V_422:
F_222 ( V_206 ) ;
return V_19 ;
}
static int T_5 F_177 ( struct V_1 * V_2 )
{
int V_218 = V_2 -> V_167 ;
int V_19 ;
#ifdef F_223
V_2 -> V_216 = V_216 [ V_218 ] ;
#endif
V_19 = F_91 ( V_2 , V_190 [ V_218 ] ) ;
if ( V_19 < 0 )
goto V_422;
#ifdef F_224
if ( V_423 [ V_218 ] && * V_423 [ V_218 ] ) {
F_10 (KERN_ERR SFX L_73 ,
patch[dev]) ;
V_19 = F_225 ( V_2 -> V_53 , V_423 [ V_218 ] ) ;
if ( V_19 < 0 )
goto V_422;
}
#endif
if ( ( V_408 [ V_218 ] & 1 ) == 0 ) {
V_19 = F_95 ( V_2 ) ;
if ( V_19 < 0 )
goto V_422;
}
V_19 = F_226 ( V_2 -> V_53 ) ;
if ( V_19 < 0 )
goto V_422;
V_19 = F_151 ( V_2 ) ;
if ( V_19 < 0 )
goto V_422;
V_19 = F_227 ( V_2 -> V_206 ) ;
if ( V_19 < 0 )
goto V_422;
V_2 -> V_141 = 1 ;
F_217 ( V_2 ) ;
F_171 ( V_2 ) ;
return 0 ;
V_422:
V_2 -> V_343 = 1 ;
return V_19 ;
}
static void T_10 F_228 ( struct V_115 * V_21 )
{
struct V_332 * V_206 = F_158 ( V_21 ) ;
if ( V_206 )
F_222 ( V_206 ) ;
F_221 ( V_21 , NULL ) ;
}
