static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_4 ,
F_3 ( V_2 -> V_5 ) ,
V_6 , & V_2 -> V_7 ) ;
if ( V_3 < 0 ) {
F_4 (KERN_ERR SFX L_1 ) ;
return V_3 ;
}
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_8 ) ;
V_2 -> V_9 . V_10 = V_2 -> V_7 . V_10 ;
V_2 -> V_9 . V_11 = ( V_12 * ) V_2 -> V_7 . V_13 ;
F_7 ( V_2 , V_14 , ( V_12 ) V_2 -> V_9 . V_10 ) ;
F_7 ( V_2 , V_15 , F_8 ( V_2 -> V_9 . V_10 ) ) ;
F_9 ( V_2 , V_16 , 0x02 ) ;
F_10 ( V_2 , V_17 , 0 ) ;
F_10 ( V_2 , V_18 , V_19 ) ;
F_9 ( V_2 , V_20 , V_21 ) ;
V_2 -> V_22 . V_10 = V_2 -> V_7 . V_10 + 2048 ;
V_2 -> V_22 . V_11 = ( V_12 * ) ( V_2 -> V_7 . V_13 + 2048 ) ;
V_2 -> V_22 . V_23 = V_2 -> V_22 . V_24 = 0 ;
memset ( V_2 -> V_22 . V_25 , 0 , sizeof( V_2 -> V_22 . V_25 ) ) ;
F_7 ( V_2 , V_26 , ( V_12 ) V_2 -> V_22 . V_10 ) ;
F_7 ( V_2 , V_27 , F_8 ( V_2 -> V_22 . V_10 ) ) ;
F_9 ( V_2 , V_28 , 0x02 ) ;
F_10 ( V_2 , V_29 , V_30 ) ;
if ( V_2 -> V_31 & V_32 )
F_10 ( V_2 , V_33 , 0xc0 ) ;
else
F_10 ( V_2 , V_33 , 1 ) ;
F_9 ( V_2 , V_34 , V_35 | V_36 ) ;
F_11 ( & V_2 -> V_8 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_8 ) ;
F_9 ( V_2 , V_34 , 0 ) ;
F_9 ( V_2 , V_20 , 0 ) ;
F_11 ( & V_2 -> V_8 ) ;
}
static unsigned int F_13 ( V_12 V_37 )
{
unsigned int V_10 = V_37 >> 28 ;
if ( V_10 >= V_38 ) {
F_14 () ;
V_10 = 0 ;
}
return V_10 ;
}
static unsigned int F_15 ( V_12 V_39 )
{
unsigned int V_10 = V_39 & 0xf ;
if ( V_10 >= V_38 ) {
F_14 () ;
V_10 = 0 ;
}
return V_10 ;
}
static int F_16 ( struct V_40 * V_41 , V_12 V_42 )
{
struct V_1 * V_2 = V_41 -> V_43 ;
unsigned int V_10 = F_13 ( V_42 ) ;
unsigned int V_23 ;
F_6 ( & V_2 -> V_8 ) ;
V_23 = F_17 ( V_2 , V_17 ) ;
V_23 ++ ;
V_23 %= V_44 ;
V_2 -> V_22 . V_25 [ V_10 ] ++ ;
V_2 -> V_9 . V_11 [ V_23 ] = F_18 ( V_42 ) ;
F_7 ( V_2 , V_17 , V_23 ) ;
F_11 ( & V_2 -> V_8 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
unsigned int V_24 , V_23 ;
unsigned int V_10 ;
V_12 V_39 , V_45 ;
V_23 = F_17 ( V_2 , V_29 ) ;
if ( V_23 == V_2 -> V_22 . V_23 )
return;
V_2 -> V_22 . V_23 = V_23 ;
while ( V_2 -> V_22 . V_24 != V_23 ) {
V_2 -> V_22 . V_24 ++ ;
V_2 -> V_22 . V_24 %= V_46 ;
V_24 = V_2 -> V_22 . V_24 << 1 ;
V_45 = F_20 ( V_2 -> V_22 . V_11 [ V_24 + 1 ] ) ;
V_39 = F_20 ( V_2 -> V_22 . V_11 [ V_24 ] ) ;
V_10 = F_15 ( V_45 ) ;
if ( V_45 & V_47 )
F_21 ( V_2 -> V_41 , V_39 , V_45 ) ;
else if ( V_2 -> V_22 . V_25 [ V_10 ] ) {
V_2 -> V_22 . V_39 [ V_10 ] = V_39 ;
F_22 () ;
V_2 -> V_22 . V_25 [ V_10 ] -- ;
} else
F_4 (KERN_ERR SFX L_2
L_3 ,
res, res_ex,
chip->last_cmd[addr]) ;
}
}
static unsigned int F_23 ( struct V_40 * V_41 ,
unsigned int V_10 )
{
struct V_1 * V_2 = V_41 -> V_43 ;
unsigned long V_48 ;
int V_49 = 0 ;
V_50:
V_48 = V_51 + F_24 ( 1000 ) ;
for (; ; ) {
if ( V_2 -> V_52 || V_49 ) {
F_6 ( & V_2 -> V_8 ) ;
F_19 ( V_2 ) ;
F_11 ( & V_2 -> V_8 ) ;
}
if ( ! V_2 -> V_22 . V_25 [ V_10 ] ) {
F_25 () ;
V_41 -> V_53 = 0 ;
if ( ! V_49 )
V_2 -> V_54 = 0 ;
return V_2 -> V_22 . V_39 [ V_10 ] ;
}
if ( F_26 ( V_51 , V_48 ) )
break;
if ( V_41 -> V_55 )
F_27 ( 2 ) ;
else {
F_28 ( 10 ) ;
F_29 () ;
}
}
if ( ! V_2 -> V_52 && V_2 -> V_54 < 2 ) {
F_30 ( V_56 L_4
L_5 ,
V_2 -> V_57 [ V_10 ] ) ;
V_49 = 1 ;
V_2 -> V_54 ++ ;
goto V_50;
}
if ( ! V_2 -> V_52 ) {
F_4 (KERN_WARNING SFX L_4
L_6 ,
chip->last_cmd[addr]) ;
V_2 -> V_52 = 1 ;
goto V_50;
}
if ( V_2 -> V_58 ) {
F_4 (KERN_WARNING SFX L_7
L_8 ,
chip->last_cmd[addr]) ;
F_31 ( V_2 -> V_59 , V_2 ) ;
V_2 -> V_59 = - 1 ;
F_32 ( V_2 -> V_5 ) ;
V_2 -> V_58 = 0 ;
if ( F_33 ( V_2 , 1 ) < 0 ) {
V_41 -> V_53 = 1 ;
return - 1 ;
}
goto V_50;
}
if ( V_2 -> V_60 ) {
return - 1 ;
}
V_41 -> V_53 = 1 ;
if ( V_41 -> V_61 && ! V_41 -> V_62 && ! V_41 -> V_63 ) {
V_41 -> V_62 = 1 ;
return - 1 ;
}
F_4 ( V_64 L_9
L_10 ,
V_2 -> V_57 [ V_10 ] ) ;
V_2 -> V_65 = 1 ;
V_41 -> V_62 = 0 ;
F_12 ( V_2 ) ;
F_7 ( V_2 , V_66 , F_34 ( V_2 , V_66 ) & ~ V_67 ) ;
return - 1 ;
}
static int F_35 ( struct V_1 * V_2 , unsigned int V_10 )
{
int V_48 = 50 ;
while ( V_48 -- ) {
if ( F_36 ( V_2 , V_68 ) & V_69 ) {
V_2 -> V_22 . V_39 [ V_10 ] = F_34 ( V_2 , V_70 ) ;
return 0 ;
}
F_28 ( 1 ) ;
}
if ( F_37 () )
F_38 ( V_56 L_11 ,
F_36 ( V_2 , V_68 ) ) ;
V_2 -> V_22 . V_39 [ V_10 ] = - 1 ;
return - V_71 ;
}
static int F_39 ( struct V_40 * V_41 , V_12 V_42 )
{
struct V_1 * V_2 = V_41 -> V_43 ;
unsigned int V_10 = F_13 ( V_42 ) ;
int V_48 = 50 ;
V_41 -> V_53 = 0 ;
while ( V_48 -- ) {
if ( ! ( ( F_36 ( V_2 , V_68 ) & V_72 ) ) ) {
F_10 ( V_2 , V_68 , F_36 ( V_2 , V_68 ) |
V_69 ) ;
F_7 ( V_2 , V_73 , V_42 ) ;
F_10 ( V_2 , V_68 , F_36 ( V_2 , V_68 ) |
V_72 ) ;
return F_35 ( V_2 , V_10 ) ;
}
F_28 ( 1 ) ;
}
if ( F_37 () )
F_38 ( V_56 L_12 ,
F_36 ( V_2 , V_68 ) , V_42 ) ;
return - V_71 ;
}
static unsigned int F_40 ( struct V_40 * V_41 ,
unsigned int V_10 )
{
struct V_1 * V_2 = V_41 -> V_43 ;
return V_2 -> V_22 . V_39 [ V_10 ] ;
}
static int F_41 ( struct V_40 * V_41 , unsigned int V_42 )
{
struct V_1 * V_2 = V_41 -> V_43 ;
V_2 -> V_57 [ F_13 ( V_42 ) ] = V_42 ;
if ( V_2 -> V_65 )
return F_39 ( V_41 , V_42 ) ;
else
return F_16 ( V_41 , V_42 ) ;
}
static unsigned int F_42 ( struct V_40 * V_41 ,
unsigned int V_10 )
{
struct V_1 * V_2 = V_41 -> V_43 ;
if ( V_2 -> V_65 )
return F_40 ( V_41 , V_10 ) ;
else
return F_23 ( V_41 , V_10 ) ;
}
static int F_43 ( struct V_1 * V_2 , int V_74 )
{
int V_75 ;
if ( ! V_74 )
goto V_76;
F_9 ( V_2 , V_77 , V_78 ) ;
F_7 ( V_2 , V_66 , F_34 ( V_2 , V_66 ) & ~ V_79 ) ;
V_75 = 50 ;
while ( F_17 ( V_2 , V_66 ) && -- V_75 )
F_27 ( 1 ) ;
F_27 ( 1 ) ;
F_9 ( V_2 , V_66 , F_17 ( V_2 , V_66 ) | V_79 ) ;
V_75 = 50 ;
while ( ! F_17 ( V_2 , V_66 ) && -- V_75 )
F_27 ( 1 ) ;
F_27 ( 1 ) ;
V_76:
if ( ! F_17 ( V_2 , V_66 ) ) {
F_38 ( V_56 L_13 ) ;
return - V_80 ;
}
if ( ! V_2 -> V_65 )
F_7 ( V_2 , V_66 , F_34 ( V_2 , V_66 ) |
V_67 ) ;
if ( ! V_2 -> V_81 ) {
V_2 -> V_81 = F_36 ( V_2 , V_77 ) ;
F_30 ( V_56 L_14 , V_2 -> V_81 ) ;
}
return 0 ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_82 , F_34 ( V_2 , V_82 ) |
V_83 | V_84 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
int V_85 ;
for ( V_85 = 0 ; V_85 < V_2 -> V_86 ; V_85 ++ ) {
struct V_87 * V_87 = & V_2 -> V_87 [ V_85 ] ;
F_46 ( V_87 , V_88 ,
F_47 ( V_87 , V_88 ) & ~ V_89 ) ;
}
F_9 ( V_2 , V_82 , 0 ) ;
F_7 ( V_2 , V_82 , F_34 ( V_2 , V_82 ) &
~ ( V_83 | V_84 ) ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
int V_85 ;
for ( V_85 = 0 ; V_85 < V_2 -> V_86 ; V_85 ++ ) {
struct V_87 * V_87 = & V_2 -> V_87 [ V_85 ] ;
F_46 ( V_87 , V_90 , V_89 ) ;
}
F_9 ( V_2 , V_77 , V_78 ) ;
F_9 ( V_2 , V_91 , V_92 ) ;
F_7 ( V_2 , V_93 , V_83 | V_94 ) ;
}
static void F_49 ( struct V_1 * V_2 , struct V_87 * V_87 )
{
V_87 -> V_95 = 1 ;
F_7 ( V_2 , V_82 ,
F_34 ( V_2 , V_82 ) | ( 1 << V_87 -> V_96 ) ) ;
F_46 ( V_87 , V_88 , F_47 ( V_87 , V_88 ) |
V_97 | V_89 ) ;
}
static void F_50 ( struct V_1 * V_2 , struct V_87 * V_87 )
{
F_46 ( V_87 , V_88 , F_47 ( V_87 , V_88 ) &
~ ( V_97 | V_89 ) ) ;
F_46 ( V_87 , V_90 , V_89 ) ;
}
static void F_51 ( struct V_1 * V_2 , struct V_87 * V_87 )
{
F_50 ( V_2 , V_87 ) ;
F_7 ( V_2 , V_82 ,
F_34 ( V_2 , V_82 ) & ~ ( 1 << V_87 -> V_96 ) ) ;
}
static void F_52 ( struct V_1 * V_2 , int V_74 )
{
if ( V_2 -> V_98 )
return;
F_43 ( V_2 , V_74 ) ;
F_48 ( V_2 ) ;
F_44 ( V_2 ) ;
if ( ! V_2 -> V_65 )
F_5 ( V_2 ) ;
F_7 ( V_2 , V_99 , ( V_12 ) V_2 -> V_100 . V_10 ) ;
F_7 ( V_2 , V_101 , F_8 ( V_2 -> V_100 . V_10 ) ) ;
V_2 -> V_98 = 1 ;
}
static void F_53 ( struct V_102 * V_5 , unsigned int V_103 ,
unsigned char V_104 , unsigned char V_42 )
{
unsigned char V_105 ;
F_54 ( V_5 , V_103 , & V_105 ) ;
V_105 &= ~ V_104 ;
V_105 |= ( V_42 & V_104 ) ;
F_55 ( V_5 , V_103 , V_105 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
unsigned short V_106 ;
if ( ! ( V_2 -> V_31 & V_107 ) ) {
F_30 ( V_56 L_15 ) ;
F_53 ( V_2 -> V_5 , V_108 , 0x07 , 0 ) ;
}
if ( V_2 -> V_31 & V_109 ) {
F_30 ( V_56 L_16 ) ;
F_53 ( V_2 -> V_5 ,
V_110 ,
0x07 , V_111 ) ;
}
if ( V_2 -> V_31 & V_112 ) {
F_30 ( V_56 L_17 ) ;
F_53 ( V_2 -> V_5 ,
V_113 ,
0x0f , V_114 ) ;
F_53 ( V_2 -> V_5 ,
V_115 ,
0x01 , V_116 ) ;
F_53 ( V_2 -> V_5 ,
V_117 ,
0x01 , V_116 ) ;
}
if ( V_2 -> V_31 & V_118 ) {
F_57 ( V_2 -> V_5 , V_119 , & V_106 ) ;
if ( V_106 & V_120 ) {
F_58 ( V_2 -> V_5 , V_119 ,
V_106 & ( ~ V_120 ) ) ;
F_57 ( V_2 -> V_5 ,
V_119 , & V_106 ) ;
F_30 ( V_56 L_18 ,
( V_106 & V_120 )
? L_19 : L_20 ) ;
}
}
}
static T_1 F_59 ( int V_59 , void * V_121 )
{
struct V_1 * V_2 = V_121 ;
struct V_87 * V_87 ;
V_12 V_122 ;
T_2 V_123 ;
int V_85 , V_124 ;
F_60 ( & V_2 -> V_8 ) ;
V_122 = F_34 ( V_2 , V_93 ) ;
if ( V_122 == 0 ) {
F_61 ( & V_2 -> V_8 ) ;
return V_125 ;
}
for ( V_85 = 0 ; V_85 < V_2 -> V_86 ; V_85 ++ ) {
V_87 = & V_2 -> V_87 [ V_85 ] ;
if ( V_122 & V_87 -> V_126 ) {
V_123 = F_47 ( V_87 , V_90 ) ;
F_46 ( V_87 , V_90 , V_89 ) ;
if ( ! V_87 -> V_127 || ! V_87 -> V_128 ||
! ( V_123 & V_129 ) )
continue;
V_124 = F_62 ( V_2 , V_87 ) ;
if ( V_124 == 1 ) {
V_87 -> V_130 = 0 ;
F_61 ( & V_2 -> V_8 ) ;
F_63 ( V_87 -> V_127 ) ;
F_60 ( & V_2 -> V_8 ) ;
} else if ( V_124 == 0 && V_2 -> V_41 && V_2 -> V_41 -> V_131 ) {
V_87 -> V_130 = 1 ;
F_64 ( V_2 -> V_41 -> V_131 ,
& V_2 -> V_132 ) ;
}
}
}
V_122 = F_17 ( V_2 , V_91 ) ;
if ( V_122 & V_92 ) {
if ( V_122 & V_133 ) {
if ( V_2 -> V_31 & V_134 )
F_28 ( 80 ) ;
F_19 ( V_2 ) ;
}
F_9 ( V_2 , V_91 , V_92 ) ;
}
#if 0
if (azx_readb(chip, STATESTS) & 0x04)
azx_writeb(chip, STATESTS, 0x04);
#endif
F_61 ( & V_2 -> V_8 ) ;
return V_135 ;
}
static int F_65 ( struct V_136 * V_127 ,
struct V_87 * V_87 , V_12 * * V_137 ,
int V_138 , int V_139 , int V_140 )
{
V_12 * V_141 = * V_137 ;
while ( V_139 > 0 ) {
T_3 V_10 ;
int V_142 ;
if ( V_87 -> V_143 >= V_144 )
return - V_145 ;
V_10 = F_66 ( V_127 , V_138 ) ;
V_141 [ 0 ] = F_18 ( ( V_12 ) V_10 ) ;
V_141 [ 1 ] = F_18 ( F_8 ( V_10 ) ) ;
V_142 = F_67 ( V_127 , V_138 , V_139 ) ;
V_141 [ 2 ] = F_18 ( V_142 ) ;
V_139 -= V_142 ;
V_141 [ 3 ] = ( V_139 || ! V_140 ) ? 0 : F_18 ( 0x01 ) ;
V_141 += 4 ;
V_87 -> V_143 ++ ;
V_138 += V_142 ;
}
* V_137 = V_141 ;
return V_138 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_136 * V_127 ,
struct V_87 * V_87 )
{
V_12 * V_141 ;
int V_85 , V_138 , V_146 , V_147 ;
int V_148 ;
F_69 ( V_87 , V_149 , 0 ) ;
F_69 ( V_87 , V_150 , 0 ) ;
V_147 = V_87 -> V_147 ;
V_146 = V_87 -> V_151 / V_147 ;
V_141 = ( V_12 * ) V_87 -> V_141 . V_13 ;
V_138 = 0 ;
V_87 -> V_143 = 0 ;
V_148 = V_152 [ V_2 -> V_153 ] ;
if ( V_148 > 0 ) {
struct V_154 * V_155 = V_127 -> V_155 ;
int V_156 = V_148 ;
V_148 = ( V_148 * V_155 -> V_157 + 47999 ) / 48000 ;
if ( ! V_148 )
V_148 = V_156 ;
else
V_148 = ( ( V_148 + V_156 - 1 ) / V_156 ) *
V_156 ;
V_148 = F_70 ( V_155 , V_148 ) ;
if ( V_148 >= V_147 ) {
F_4 (KERN_WARNING SFX L_21 ,
bdl_pos_adj[chip->dev_index]) ;
V_148 = 0 ;
} else {
V_138 = F_65 ( V_127 , V_87 ,
& V_141 , V_138 , V_148 ,
! V_127 -> V_155 -> V_158 ) ;
if ( V_138 < 0 )
goto error;
}
} else
V_148 = 0 ;
for ( V_85 = 0 ; V_85 < V_146 ; V_85 ++ ) {
if ( V_85 == V_146 - 1 && V_148 )
V_138 = F_65 ( V_127 , V_87 , & V_141 , V_138 ,
V_147 - V_148 , 0 ) ;
else
V_138 = F_65 ( V_127 , V_87 , & V_141 , V_138 ,
V_147 ,
! V_127 -> V_155 -> V_158 ) ;
if ( V_138 < 0 )
goto error;
}
return 0 ;
error:
F_4 (KERN_ERR SFX L_22 ,
azx_dev->bufsize, period_bytes) ;
return - V_145 ;
}
static void F_71 ( struct V_1 * V_2 , struct V_87 * V_87 )
{
unsigned char V_42 ;
int V_48 ;
F_50 ( V_2 , V_87 ) ;
F_46 ( V_87 , V_88 , F_47 ( V_87 , V_88 ) |
V_159 ) ;
F_28 ( 3 ) ;
V_48 = 300 ;
while ( ! ( ( V_42 = F_47 ( V_87 , V_88 ) ) & V_159 ) &&
-- V_48 )
;
V_42 &= ~ V_159 ;
F_46 ( V_87 , V_88 , V_42 ) ;
F_28 ( 3 ) ;
V_48 = 300 ;
while ( ( ( V_42 = F_47 ( V_87 , V_88 ) ) & V_159 ) &&
-- V_48 )
;
* V_87 -> V_100 = 0 ;
}
static int F_72 ( struct V_1 * V_2 , struct V_87 * V_87 )
{
F_50 ( V_2 , V_87 ) ;
F_69 ( V_87 , V_88 ,
( F_73 ( V_87 , V_88 ) & ~ V_160 ) |
( V_87 -> V_161 << V_162 ) ) ;
F_69 ( V_87 , V_163 , V_87 -> V_151 ) ;
F_74 ( V_87 , V_164 , V_87 -> V_165 ) ;
F_74 ( V_87 , V_166 , V_87 -> V_143 - 1 ) ;
F_69 ( V_87 , V_149 , ( V_12 ) V_87 -> V_141 . V_10 ) ;
F_69 ( V_87 , V_150 , F_8 ( V_87 -> V_141 . V_10 ) ) ;
if ( V_2 -> V_167 [ 0 ] != V_168 ||
V_2 -> V_167 [ 1 ] != V_168 ) {
if ( ! ( F_34 ( V_2 , V_99 ) & V_169 ) )
F_7 ( V_2 , V_99 ,
( V_12 ) V_2 -> V_100 . V_10 | V_169 ) ;
}
F_69 ( V_87 , V_88 ,
F_73 ( V_87 , V_88 ) | V_89 ) ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 , int V_10 )
{
unsigned int V_37 = ( V_10 << 28 ) | ( V_170 << 20 ) |
( V_171 << 8 ) | V_172 ;
unsigned int V_39 ;
F_76 ( & V_2 -> V_41 -> V_173 ) ;
V_2 -> V_60 = 1 ;
F_41 ( V_2 -> V_41 , V_37 ) ;
V_39 = F_42 ( V_2 -> V_41 , V_10 ) ;
V_2 -> V_60 = 0 ;
F_77 ( & V_2 -> V_41 -> V_173 ) ;
if ( V_39 == - 1 )
return - V_71 ;
F_30 ( V_56 L_23 , V_10 ) ;
return 0 ;
}
static void F_78 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_43 ;
V_41 -> V_63 = 1 ;
F_79 ( V_2 ) ;
F_52 ( V_2 , 1 ) ;
#ifdef F_80
if ( V_2 -> V_98 ) {
int V_85 ;
for ( V_85 = 0 ; V_85 < V_174 ; V_85 ++ )
F_81 ( V_2 -> V_175 [ V_85 ] ) ;
F_82 ( V_2 -> V_41 ) ;
F_83 ( V_2 -> V_41 ) ;
}
#endif
V_41 -> V_63 = 0 ;
}
static int T_4 F_84 ( struct V_1 * V_2 , const char * V_176 )
{
struct V_177 V_178 ;
int V_179 , V_180 , V_3 ;
int V_181 ;
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
V_178 . V_43 = V_2 ;
V_178 . V_182 = V_176 ;
V_178 . V_5 = V_2 -> V_5 ;
V_178 . V_183 . V_184 = F_41 ;
V_178 . V_183 . V_185 = F_42 ;
V_178 . V_183 . V_186 = V_187 ;
V_178 . V_183 . V_188 = F_78 ;
#ifdef F_85
V_178 . V_189 = & V_189 ;
V_178 . V_183 . V_190 = V_191 ;
#endif
V_3 = F_86 ( V_2 -> V_192 , & V_178 , & V_2 -> V_41 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_31 & V_193 ) {
F_38 ( V_56 L_24 ) ;
V_2 -> V_41 -> V_55 = 1 ;
}
V_180 = 0 ;
V_181 = V_194 [ V_2 -> V_195 ] ;
if ( ! V_181 )
V_181 = V_196 ;
for ( V_179 = 0 ; V_179 < V_181 ; V_179 ++ ) {
if ( ( V_2 -> V_81 & ( 1 << V_179 ) ) & V_2 -> V_197 ) {
if ( F_75 ( V_2 , V_179 ) < 0 ) {
F_4 (KERN_WARNING SFX
L_25
L_26 , c) ;
V_2 -> V_81 &= ~ ( 1 << V_179 ) ;
F_79 ( V_2 ) ;
F_52 ( V_2 , 1 ) ;
}
}
}
if ( V_2 -> V_31 & V_198 ) {
F_38 ( V_56 L_27 ) ;
V_2 -> V_41 -> V_199 = 1 ;
V_2 -> V_41 -> V_61 = 1 ;
}
for ( V_179 = 0 ; V_179 < V_181 ; V_179 ++ ) {
if ( ( V_2 -> V_81 & ( 1 << V_179 ) ) & V_2 -> V_197 ) {
struct V_200 * V_201 ;
V_3 = F_87 ( V_2 -> V_41 , V_179 , & V_201 ) ;
if ( V_3 < 0 )
continue;
V_201 -> V_202 = V_2 -> V_202 ;
V_180 ++ ;
}
}
if ( ! V_180 ) {
F_4 (KERN_ERR SFX L_28 ) ;
return - V_203 ;
}
return 0 ;
}
static int T_4 F_88 ( struct V_1 * V_2 )
{
struct V_200 * V_201 ;
F_89 (codec, &chip->bus->codec_list, list) {
F_90 ( V_201 ) ;
}
return 0 ;
}
static inline struct V_87 *
F_91 ( struct V_1 * V_2 , struct V_136 * V_127 )
{
int V_204 , V_85 , V_205 ;
struct V_87 * V_39 = NULL ;
if ( V_127 -> V_206 == V_207 ) {
V_204 = V_2 -> V_208 ;
V_205 = V_2 -> V_209 ;
} else {
V_204 = V_2 -> V_210 ;
V_205 = V_2 -> V_211 ;
}
for ( V_85 = 0 ; V_85 < V_205 ; V_85 ++ , V_204 ++ )
if ( ! V_2 -> V_87 [ V_204 ] . V_212 ) {
V_39 = & V_2 -> V_87 [ V_204 ] ;
if ( V_39 -> V_213 == V_127 -> V_175 -> V_213 )
break;
}
if ( V_39 ) {
V_39 -> V_212 = 1 ;
V_39 -> V_213 = V_127 -> V_175 -> V_213 ;
}
return V_39 ;
}
static inline void F_92 ( struct V_87 * V_87 )
{
V_87 -> V_212 = 0 ;
}
static int F_93 ( struct V_136 * V_127 )
{
struct V_214 * V_215 = F_94 ( V_127 ) ;
struct V_216 * V_217 = V_215 -> V_217 [ V_127 -> V_206 ] ;
struct V_1 * V_2 = V_215 -> V_2 ;
struct V_87 * V_87 ;
struct V_154 * V_155 = V_127 -> V_155 ;
unsigned long V_218 ;
int V_3 ;
F_76 ( & V_2 -> V_219 ) ;
V_87 = F_91 ( V_2 , V_127 ) ;
if ( V_87 == NULL ) {
F_77 ( & V_2 -> V_219 ) ;
return - V_80 ;
}
V_155 -> V_220 = V_221 ;
V_155 -> V_220 . V_222 = V_217 -> V_222 ;
V_155 -> V_220 . V_223 = V_217 -> V_223 ;
V_155 -> V_220 . V_224 = V_217 -> V_224 ;
V_155 -> V_220 . V_225 = V_217 -> V_225 ;
F_95 ( V_155 ) ;
F_96 ( V_155 , V_226 ) ;
F_97 ( V_155 , 0 , V_227 ,
128 ) ;
F_97 ( V_155 , 0 , V_228 ,
128 ) ;
F_98 ( V_215 -> V_201 ) ;
V_3 = V_217 -> V_183 . V_229 ( V_217 , V_215 -> V_201 , V_127 ) ;
if ( V_3 < 0 ) {
F_92 ( V_87 ) ;
F_99 ( V_215 -> V_201 ) ;
F_77 ( & V_2 -> V_219 ) ;
return V_3 ;
}
F_95 ( V_155 ) ;
if ( F_100 ( ! V_155 -> V_220 . V_222 ) ||
F_100 ( ! V_155 -> V_220 . V_223 ) ||
F_100 ( ! V_155 -> V_220 . V_224 ) ||
F_100 ( ! V_155 -> V_220 . V_225 ) ) {
F_92 ( V_87 ) ;
V_217 -> V_183 . V_230 ( V_217 , V_215 -> V_201 , V_127 ) ;
F_99 ( V_215 -> V_201 ) ;
F_77 ( & V_2 -> V_219 ) ;
return - V_145 ;
}
F_101 ( & V_2 -> V_8 , V_218 ) ;
V_87 -> V_127 = V_127 ;
V_87 -> V_128 = 0 ;
F_102 ( & V_2 -> V_8 , V_218 ) ;
V_155 -> V_43 = V_87 ;
F_103 ( V_127 ) ;
F_77 ( & V_2 -> V_219 ) ;
return 0 ;
}
static int F_104 ( struct V_136 * V_127 )
{
struct V_214 * V_215 = F_94 ( V_127 ) ;
struct V_216 * V_217 = V_215 -> V_217 [ V_127 -> V_206 ] ;
struct V_1 * V_2 = V_215 -> V_2 ;
struct V_87 * V_87 = F_105 ( V_127 ) ;
unsigned long V_218 ;
F_76 ( & V_2 -> V_219 ) ;
F_101 ( & V_2 -> V_8 , V_218 ) ;
V_87 -> V_127 = NULL ;
V_87 -> V_128 = 0 ;
F_102 ( & V_2 -> V_8 , V_218 ) ;
F_92 ( V_87 ) ;
V_217 -> V_183 . V_230 ( V_217 , V_215 -> V_201 , V_127 ) ;
F_99 ( V_215 -> V_201 ) ;
F_77 ( & V_2 -> V_219 ) ;
return 0 ;
}
static int F_106 ( struct V_136 * V_127 ,
struct V_231 * V_232 )
{
struct V_87 * V_87 = F_105 ( V_127 ) ;
V_87 -> V_151 = 0 ;
V_87 -> V_147 = 0 ;
V_87 -> V_165 = 0 ;
return F_107 ( V_127 ,
F_108 ( V_232 ) ) ;
}
static int F_109 ( struct V_136 * V_127 )
{
struct V_214 * V_215 = F_94 ( V_127 ) ;
struct V_87 * V_87 = F_105 ( V_127 ) ;
struct V_216 * V_217 = V_215 -> V_217 [ V_127 -> V_206 ] ;
F_69 ( V_87 , V_149 , 0 ) ;
F_69 ( V_87 , V_150 , 0 ) ;
F_69 ( V_87 , V_88 , 0 ) ;
V_87 -> V_151 = 0 ;
V_87 -> V_147 = 0 ;
V_87 -> V_165 = 0 ;
F_110 ( V_215 -> V_201 , V_217 , V_127 ) ;
return F_111 ( V_127 ) ;
}
static int F_112 ( struct V_136 * V_127 )
{
struct V_214 * V_215 = F_94 ( V_127 ) ;
struct V_1 * V_2 = V_215 -> V_2 ;
struct V_87 * V_87 = F_105 ( V_127 ) ;
struct V_216 * V_217 = V_215 -> V_217 [ V_127 -> V_206 ] ;
struct V_154 * V_155 = V_127 -> V_155 ;
unsigned int V_151 , V_147 , V_165 , V_161 ;
int V_3 ;
F_71 ( V_2 , V_87 ) ;
V_165 = F_113 ( V_155 -> V_157 ,
V_155 -> V_233 ,
V_155 -> V_234 ,
V_217 -> V_235 ,
V_215 -> V_201 -> V_236 ) ;
if ( ! V_165 ) {
F_4 (KERN_ERR SFX
L_29 ,
runtime->rate, runtime->channels, runtime->format) ;
return - V_145 ;
}
V_151 = F_114 ( V_127 ) ;
V_147 = F_115 ( V_127 ) ;
F_30 ( V_56 L_30 ,
V_151 , V_165 ) ;
if ( V_151 != V_87 -> V_151 ||
V_147 != V_87 -> V_147 ||
V_165 != V_87 -> V_165 ) {
V_87 -> V_151 = V_151 ;
V_87 -> V_147 = V_147 ;
V_87 -> V_165 = V_165 ;
V_3 = F_68 ( V_2 , V_127 , V_87 ) ;
if ( V_3 < 0 )
return V_3 ;
}
V_87 -> V_237 = ( ( ( V_155 -> V_238 * 24000 ) /
V_155 -> V_157 ) * 1000 ) ;
F_72 ( V_2 , V_87 ) ;
if ( V_127 -> V_206 == V_207 )
V_87 -> V_239 = F_116 ( V_87 , V_240 ) + 1 ;
else
V_87 -> V_239 = 0 ;
V_161 = V_87 -> V_161 ;
if ( ( V_2 -> V_31 & V_32 ) &&
V_161 > V_2 -> V_211 )
V_161 -= V_2 -> V_211 ;
return F_117 ( V_215 -> V_201 , V_217 , V_161 ,
V_87 -> V_165 , V_127 ) ;
}
static int F_118 ( struct V_136 * V_127 , int V_37 )
{
struct V_214 * V_215 = F_94 ( V_127 ) ;
struct V_1 * V_2 = V_215 -> V_2 ;
struct V_87 * V_87 ;
struct V_136 * V_241 ;
int V_242 = 0 , V_243 , V_244 = 0 , V_245 = 0 ;
int V_246 , V_48 ;
switch ( V_37 ) {
case V_247 :
V_242 = 1 ;
case V_248 :
case V_249 :
V_243 = 1 ;
break;
case V_250 :
case V_251 :
case V_252 :
V_243 = 0 ;
break;
default:
return - V_145 ;
}
F_119 (s, substream) {
if ( V_241 -> V_175 -> V_192 != V_127 -> V_175 -> V_192 )
continue;
V_87 = F_105 ( V_241 ) ;
V_245 |= 1 << V_87 -> V_96 ;
V_244 ++ ;
F_120 ( V_241 , V_127 ) ;
}
F_60 ( & V_2 -> V_8 ) ;
if ( V_244 > 1 ) {
F_7 ( V_2 , V_253 , F_34 ( V_2 , V_253 ) | V_245 ) ;
}
F_119 (s, substream) {
if ( V_241 -> V_175 -> V_192 != V_127 -> V_175 -> V_192 )
continue;
V_87 = F_105 ( V_241 ) ;
if ( V_243 ) {
V_87 -> V_254 = F_34 ( V_2 , V_255 ) ;
if ( ! V_242 )
V_87 -> V_254 -=
V_87 -> V_237 ;
F_49 ( V_2 , V_87 ) ;
} else {
F_51 ( V_2 , V_87 ) ;
}
V_87 -> V_128 = V_243 ;
}
F_61 ( & V_2 -> V_8 ) ;
if ( V_243 ) {
if ( V_244 == 1 )
return 0 ;
for ( V_48 = 5000 ; V_48 ; V_48 -- ) {
V_246 = 0 ;
F_119 (s, substream) {
if ( V_241 -> V_175 -> V_192 != V_127 -> V_175 -> V_192 )
continue;
V_87 = F_105 ( V_241 ) ;
if ( ! ( F_47 ( V_87 , V_90 ) &
V_256 ) )
V_246 ++ ;
}
if ( ! V_246 )
break;
F_121 () ;
}
} else {
for ( V_48 = 5000 ; V_48 ; V_48 -- ) {
V_246 = 0 ;
F_119 (s, substream) {
if ( V_241 -> V_175 -> V_192 != V_127 -> V_175 -> V_192 )
continue;
V_87 = F_105 ( V_241 ) ;
if ( F_47 ( V_87 , V_88 ) &
V_97 )
V_246 ++ ;
}
if ( ! V_246 )
break;
F_121 () ;
}
}
if ( V_244 > 1 ) {
F_60 ( & V_2 -> V_8 ) ;
F_7 ( V_2 , V_253 , F_34 ( V_2 , V_253 ) & ~ V_245 ) ;
F_61 ( & V_2 -> V_8 ) ;
}
return 0 ;
}
static unsigned int F_122 ( struct V_1 * V_2 ,
struct V_87 * V_87 )
{
unsigned int V_257 , V_258 , V_259 ;
unsigned int V_260 , V_261 , V_262 ;
unsigned int V_239 ;
V_257 = F_73 ( V_87 , V_263 ) ;
if ( V_87 -> V_96 >= 4 ) {
return V_257 ;
}
V_261 = F_20 ( * V_87 -> V_100 ) ;
V_261 %= V_87 -> V_147 ;
V_239 = F_123 ( V_2 -> V_264 + V_265 ) ;
if ( V_87 -> V_95 ) {
if ( V_257 <= V_239 )
return 0 ;
V_87 -> V_95 = 0 ;
}
if ( V_257 <= V_239 )
V_258 = V_87 -> V_151 + V_257 - V_239 ;
else
V_258 = V_257 - V_239 ;
V_262 = V_258 % V_87 -> V_147 ;
V_260 = V_257 % V_87 -> V_147 ;
if ( V_260 >= V_239 )
V_259 = V_257 - V_260 ;
else if ( V_261 >= V_262 )
V_259 = V_258 - V_262 ;
else {
V_259 = V_258 - V_262 + V_87 -> V_147 ;
if ( V_259 >= V_87 -> V_151 )
V_259 = 0 ;
}
return V_259 + V_261 ;
}
static unsigned int F_124 ( struct V_1 * V_2 ,
struct V_87 * V_87 )
{
unsigned int V_266 ;
int V_206 = V_87 -> V_127 -> V_206 ;
switch ( V_2 -> V_167 [ V_206 ] ) {
case V_168 :
V_266 = F_73 ( V_87 , V_263 ) ;
break;
case V_267 :
V_266 = F_122 ( V_2 , V_87 ) ;
break;
default:
V_266 = F_20 ( * V_87 -> V_100 ) ;
}
if ( V_266 >= V_87 -> V_151 )
V_266 = 0 ;
return V_266 ;
}
static T_5 F_125 ( struct V_136 * V_127 )
{
struct V_214 * V_215 = F_94 ( V_127 ) ;
struct V_1 * V_2 = V_215 -> V_2 ;
struct V_87 * V_87 = F_105 ( V_127 ) ;
return F_126 ( V_127 -> V_155 ,
F_124 ( V_2 , V_87 ) ) ;
}
static int F_62 ( struct V_1 * V_2 , struct V_87 * V_87 )
{
V_12 V_268 ;
unsigned int V_266 ;
int V_206 ;
V_268 = F_34 ( V_2 , V_255 ) - V_87 -> V_254 ;
if ( V_268 < ( V_87 -> V_237 * 2 ) / 3 )
return - 1 ;
V_206 = V_87 -> V_127 -> V_206 ;
V_266 = F_124 ( V_2 , V_87 ) ;
if ( V_2 -> V_167 [ V_206 ] == V_269 ) {
if ( ! V_266 ) {
F_127 ( V_270
L_31
L_32 ) ;
V_2 -> V_167 [ V_206 ] = V_168 ;
V_266 = F_124 ( V_2 , V_87 ) ;
} else
V_2 -> V_167 [ V_206 ] = V_271 ;
}
if ( F_128 ( ! V_87 -> V_147 ,
L_33 ) )
return - 1 ;
if ( V_268 < ( V_87 -> V_237 * 5 ) / 4 &&
V_266 % V_87 -> V_147 > V_87 -> V_147 / 2 )
return V_152 [ V_2 -> V_153 ] ? 0 : - 1 ;
V_87 -> V_254 += V_268 ;
return 1 ;
}
static void F_129 ( struct V_272 * V_273 )
{
struct V_1 * V_2 = F_130 ( V_273 , struct V_1 , V_132 ) ;
int V_85 , V_274 , V_124 ;
if ( ! V_2 -> V_275 ) {
F_127 ( V_270
L_34
L_35 ,
V_2 -> V_192 -> V_276 ) ;
V_2 -> V_275 = 1 ;
}
for (; ; ) {
V_274 = 0 ;
F_6 ( & V_2 -> V_8 ) ;
for ( V_85 = 0 ; V_85 < V_2 -> V_86 ; V_85 ++ ) {
struct V_87 * V_87 = & V_2 -> V_87 [ V_85 ] ;
if ( ! V_87 -> V_130 ||
! V_87 -> V_127 ||
! V_87 -> V_128 )
continue;
V_124 = F_62 ( V_2 , V_87 ) ;
if ( V_124 > 0 ) {
V_87 -> V_130 = 0 ;
F_61 ( & V_2 -> V_8 ) ;
F_63 ( V_87 -> V_127 ) ;
F_60 ( & V_2 -> V_8 ) ;
} else if ( V_124 < 0 ) {
V_274 = 0 ;
} else
V_274 ++ ;
}
F_11 ( & V_2 -> V_8 ) ;
if ( ! V_274 )
return;
F_27 ( 1 ) ;
}
}
static void F_131 ( struct V_1 * V_2 )
{
int V_85 ;
F_6 ( & V_2 -> V_8 ) ;
for ( V_85 = 0 ; V_85 < V_2 -> V_86 ; V_85 ++ )
V_2 -> V_87 [ V_85 ] . V_130 = 0 ;
F_11 ( & V_2 -> V_8 ) ;
}
static void F_132 ( struct V_277 * V_175 )
{
struct V_214 * V_215 = V_175 -> V_43 ;
if ( V_215 ) {
V_215 -> V_2 -> V_175 [ V_175 -> V_213 ] = NULL ;
F_133 ( V_215 ) ;
}
}
static int
V_187 ( struct V_40 * V_41 , struct V_200 * V_201 ,
struct V_278 * V_279 )
{
struct V_1 * V_2 = V_41 -> V_43 ;
struct V_277 * V_175 ;
struct V_214 * V_215 ;
int V_280 = V_279 -> V_213 ;
int V_241 , V_3 ;
if ( V_280 >= V_174 ) {
F_4 (KERN_ERR SFX L_36 ,
pcm_dev) ;
return - V_145 ;
}
if ( V_2 -> V_175 [ V_280 ] ) {
F_4 (KERN_ERR SFX L_37 , pcm_dev) ;
return - V_80 ;
}
V_3 = F_134 ( V_2 -> V_192 , V_279 -> V_281 , V_280 ,
V_279 -> V_206 [ V_207 ] . V_282 ,
V_279 -> V_206 [ V_283 ] . V_282 ,
& V_175 ) ;
if ( V_3 < 0 )
return V_3 ;
F_135 ( V_175 -> V_281 , V_279 -> V_281 , sizeof( V_175 -> V_281 ) ) ;
V_215 = F_136 ( sizeof( * V_215 ) , V_284 ) ;
if ( V_215 == NULL )
return - V_285 ;
V_215 -> V_2 = V_2 ;
V_215 -> V_201 = V_201 ;
V_175 -> V_43 = V_215 ;
V_175 -> V_286 = F_132 ;
if ( V_279 -> V_287 == V_288 )
V_175 -> V_289 = V_290 ;
V_2 -> V_175 [ V_280 ] = V_175 ;
V_279 -> V_175 = V_175 ;
for ( V_241 = 0 ; V_241 < 2 ; V_241 ++ ) {
V_215 -> V_217 [ V_241 ] = & V_279 -> V_206 [ V_241 ] ;
if ( V_279 -> V_206 [ V_241 ] . V_282 )
F_137 ( V_175 , V_241 , & V_291 ) ;
}
F_138 ( V_175 , V_292 ,
F_3 ( V_2 -> V_5 ) ,
1024 * 64 , 32 * 1024 * 1024 ) ;
return 0 ;
}
static int T_4 F_139 ( struct V_1 * V_2 )
{
return F_140 ( V_2 -> V_41 ) ;
}
static int T_4 F_141 ( struct V_1 * V_2 )
{
int V_85 ;
for ( V_85 = 0 ; V_85 < V_2 -> V_86 ; V_85 ++ ) {
struct V_87 * V_87 = & V_2 -> V_87 [ V_85 ] ;
V_87 -> V_100 = ( V_12 V_293 * ) ( V_2 -> V_100 . V_13 + V_85 * 8 ) ;
V_87 -> V_294 = V_2 -> V_264 + ( 0x20 * V_85 + 0x80 ) ;
V_87 -> V_126 = 1 << V_85 ;
V_87 -> V_96 = V_85 ;
V_87 -> V_161 = V_85 + 1 ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , int V_295 )
{
if ( F_142 ( V_2 -> V_5 -> V_59 , F_59 ,
V_2 -> V_58 ? 0 : V_296 ,
L_38 , V_2 ) ) {
F_127 ( V_64 L_39
L_40 , V_2 -> V_5 -> V_59 ) ;
if ( V_295 )
F_143 ( V_2 -> V_192 ) ;
return - 1 ;
}
V_2 -> V_59 = V_2 -> V_5 -> V_59 ;
F_144 ( V_2 -> V_5 , ! V_2 -> V_58 ) ;
return 0 ;
}
static void F_79 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_98 )
return;
F_45 ( V_2 ) ;
F_48 ( V_2 ) ;
F_12 ( V_2 ) ;
F_7 ( V_2 , V_99 , 0 ) ;
F_7 ( V_2 , V_101 , 0 ) ;
V_2 -> V_98 = 0 ;
}
static void V_191 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_43 ;
struct V_200 * V_179 ;
int V_297 = 0 ;
F_89 (c, &bus->codec_list, list) {
if ( V_179 -> V_297 ) {
V_297 = 1 ;
break;
}
}
if ( V_297 )
F_52 ( V_2 , 1 ) ;
else if ( V_2 -> V_128 && V_298 &&
! V_41 -> V_299 )
F_79 ( V_2 ) ;
}
static int F_145 ( struct V_40 * V_41 )
{
struct V_200 * V_201 ;
F_89 (codec, &bus->codec_list, list) {
if ( F_146 ( V_201 ) )
return 1 ;
}
return 0 ;
}
static int F_147 ( struct V_102 * V_5 , T_6 V_300 )
{
struct V_301 * V_192 = F_148 ( V_5 ) ;
struct V_1 * V_2 = V_192 -> V_43 ;
int V_85 ;
F_149 ( V_192 , V_302 ) ;
F_131 ( V_2 ) ;
for ( V_85 = 0 ; V_85 < V_174 ; V_85 ++ )
F_81 ( V_2 -> V_175 [ V_85 ] ) ;
if ( V_2 -> V_98 )
F_82 ( V_2 -> V_41 ) ;
F_79 ( V_2 ) ;
if ( V_2 -> V_59 >= 0 ) {
F_31 ( V_2 -> V_59 , V_2 ) ;
V_2 -> V_59 = - 1 ;
}
if ( V_2 -> V_58 )
F_32 ( V_2 -> V_5 ) ;
F_150 ( V_5 ) ;
F_151 ( V_5 ) ;
F_152 ( V_5 , F_153 ( V_5 , V_300 ) ) ;
return 0 ;
}
static int F_154 ( struct V_102 * V_5 )
{
struct V_301 * V_192 = F_148 ( V_5 ) ;
struct V_1 * V_2 = V_192 -> V_43 ;
F_152 ( V_5 , V_303 ) ;
F_155 ( V_5 ) ;
if ( F_156 ( V_5 ) < 0 ) {
F_127 ( V_64 L_41
L_40 ) ;
F_143 ( V_192 ) ;
return - V_71 ;
}
F_157 ( V_5 ) ;
if ( V_2 -> V_58 )
if ( F_158 ( V_5 ) < 0 )
V_2 -> V_58 = 0 ;
if ( F_33 ( V_2 , 1 ) < 0 )
return - V_71 ;
F_56 ( V_2 ) ;
if ( F_145 ( V_2 -> V_41 ) )
F_52 ( V_2 , 1 ) ;
F_83 ( V_2 -> V_41 ) ;
F_149 ( V_192 , V_304 ) ;
return 0 ;
}
static int F_159 ( struct V_305 * V_306 , unsigned long V_307 , void * V_11 )
{
struct V_1 * V_2 = F_130 ( V_306 , struct V_1 , V_308 ) ;
F_160 ( V_2 -> V_41 ) ;
F_79 ( V_2 ) ;
return V_309 ;
}
static void F_161 ( struct V_1 * V_2 )
{
V_2 -> V_308 . V_310 = F_159 ;
F_162 ( & V_2 -> V_308 ) ;
}
static void F_163 ( struct V_1 * V_2 )
{
if ( V_2 -> V_308 . V_310 )
F_164 ( & V_2 -> V_308 ) ;
}
static int F_165 ( struct V_1 * V_2 )
{
int V_85 ;
F_163 ( V_2 ) ;
if ( V_2 -> V_98 ) {
F_131 ( V_2 ) ;
for ( V_85 = 0 ; V_85 < V_2 -> V_86 ; V_85 ++ )
F_51 ( V_2 , & V_2 -> V_87 [ V_85 ] ) ;
F_79 ( V_2 ) ;
}
if ( V_2 -> V_59 >= 0 )
F_31 ( V_2 -> V_59 , ( void * ) V_2 ) ;
if ( V_2 -> V_58 )
F_32 ( V_2 -> V_5 ) ;
if ( V_2 -> V_264 )
F_166 ( V_2 -> V_264 ) ;
if ( V_2 -> V_87 ) {
for ( V_85 = 0 ; V_85 < V_2 -> V_86 ; V_85 ++ )
if ( V_2 -> V_87 [ V_85 ] . V_141 . V_13 )
F_167 ( & V_2 -> V_87 [ V_85 ] . V_141 ) ;
}
if ( V_2 -> V_7 . V_13 )
F_167 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_100 . V_13 )
F_167 ( & V_2 -> V_100 ) ;
F_168 ( V_2 -> V_5 ) ;
F_150 ( V_2 -> V_5 ) ;
F_133 ( V_2 -> V_87 ) ;
F_133 ( V_2 ) ;
return 0 ;
}
static int F_169 ( struct V_311 * V_213 )
{
return F_165 ( V_213 -> V_312 ) ;
}
static int T_4 F_170 ( struct V_1 * V_2 , int V_313 )
{
const struct V_314 * V_315 ;
switch ( V_313 ) {
case V_168 :
case V_271 :
case V_267 :
return V_313 ;
}
V_315 = F_171 ( V_2 -> V_5 , V_316 ) ;
if ( V_315 ) {
F_127 ( V_317
L_42
L_43 ,
V_315 -> V_318 , V_315 -> V_319 , V_315 -> V_320 ) ;
return V_315 -> V_318 ;
}
if ( V_2 -> V_31 & V_321 ) {
F_38 ( V_56 L_44 ) ;
return V_267 ;
}
if ( V_2 -> V_31 & V_322 ) {
F_38 ( V_56 L_45 ) ;
return V_168 ;
}
return V_269 ;
}
static void T_4 F_172 ( struct V_1 * V_2 , int V_204 )
{
const struct V_314 * V_315 ;
V_2 -> V_197 = V_323 [ V_204 ] ;
if ( V_2 -> V_197 == - 1 ) {
V_315 = F_171 ( V_2 -> V_5 , V_324 ) ;
if ( V_315 ) {
F_127 ( V_317
L_46
L_43 ,
V_315 -> V_318 , V_315 -> V_319 , V_315 -> V_320 ) ;
V_2 -> V_197 = V_315 -> V_318 ;
}
}
if ( V_2 -> V_197 != - 1 &&
( V_2 -> V_197 & V_325 ) ) {
V_2 -> V_81 = V_2 -> V_197 & 0xff ;
F_127 ( V_317 L_47 ,
V_2 -> V_81 ) ;
}
}
static void T_4 F_173 ( struct V_1 * V_2 )
{
const struct V_314 * V_315 ;
if ( V_326 >= 0 ) {
V_2 -> V_58 = ! ! V_326 ;
return;
}
V_2 -> V_58 = 1 ;
V_315 = F_171 ( V_2 -> V_5 , V_327 ) ;
if ( V_315 ) {
F_127 ( V_317
L_48 ,
V_315 -> V_319 , V_315 -> V_320 , V_315 -> V_318 ) ;
V_2 -> V_58 = V_315 -> V_318 ;
return;
}
if ( V_2 -> V_31 & V_328 ) {
F_127 ( V_317 L_49 ) ;
V_2 -> V_58 = 0 ;
}
}
static int T_4 F_174 ( struct V_301 * V_192 , struct V_102 * V_5 ,
int V_204 , unsigned int V_31 ,
struct V_1 * * V_329 )
{
struct V_1 * V_2 ;
int V_85 , V_3 ;
unsigned short V_330 ;
static struct V_331 V_183 = {
. V_332 = F_169 ,
} ;
* V_329 = NULL ;
V_3 = F_156 ( V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 = F_136 ( sizeof( * V_2 ) , V_284 ) ;
if ( ! V_2 ) {
F_4 (KERN_ERR SFX L_50 ) ;
F_150 ( V_5 ) ;
return - V_285 ;
}
F_175 ( & V_2 -> V_8 ) ;
F_176 ( & V_2 -> V_219 ) ;
V_2 -> V_192 = V_192 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_59 = - 1 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_195 = V_31 & 0xff ;
F_173 ( V_2 ) ;
V_2 -> V_153 = V_204 ;
F_177 ( & V_2 -> V_132 , F_129 ) ;
V_2 -> V_167 [ 0 ] = V_2 -> V_167 [ 1 ] =
F_170 ( V_2 , V_167 [ V_204 ] ) ;
F_172 ( V_2 , V_204 ) ;
V_2 -> V_65 = V_65 ;
if ( V_152 [ V_204 ] < 0 ) {
switch ( V_2 -> V_195 ) {
case V_333 :
case V_334 :
V_152 [ V_204 ] = 1 ;
break;
default:
V_152 [ V_204 ] = 32 ;
break;
}
}
#if V_335 != 64
if ( V_2 -> V_195 == V_336 ) {
T_7 V_337 ;
F_57 ( V_5 , 0x40 , & V_337 ) ;
F_58 ( V_5 , 0x40 , V_337 | 0x10 ) ;
F_178 ( V_5 , V_338 , 0 ) ;
}
#endif
V_3 = F_179 ( V_5 , L_51 ) ;
if ( V_3 < 0 ) {
F_133 ( V_2 ) ;
F_150 ( V_5 ) ;
return V_3 ;
}
V_2 -> V_10 = F_180 ( V_5 , 0 ) ;
V_2 -> V_264 = F_181 ( V_5 , 0 ) ;
if ( V_2 -> V_264 == NULL ) {
F_4 (KERN_ERR SFX L_52 ) ;
V_3 = - V_203 ;
goto V_339;
}
if ( V_2 -> V_58 )
if ( F_158 ( V_5 ) < 0 )
V_2 -> V_58 = 0 ;
if ( F_33 ( V_2 , 0 ) < 0 ) {
V_3 = - V_80 ;
goto V_339;
}
F_157 ( V_5 ) ;
F_182 ( V_2 -> V_59 ) ;
V_330 = F_36 ( V_2 , V_340 ) ;
F_30 ( V_56 L_53 , V_330 ) ;
if ( V_2 -> V_5 -> V_341 == V_342 ) {
struct V_102 * V_343 ;
V_343 = F_183 ( V_342 ,
V_344 ,
NULL ) ;
if ( V_343 ) {
if ( V_343 -> V_345 < 0x30 )
V_330 &= ~ V_346 ;
F_184 ( V_343 ) ;
}
}
if ( V_2 -> V_31 & V_347 ) {
F_38 ( V_56 L_54 ) ;
V_330 &= ~ V_346 ;
}
if ( ( V_330 & V_346 ) && ! F_185 ( V_5 , F_186 ( 64 ) ) )
F_187 ( V_5 , F_186 ( 64 ) ) ;
else {
F_185 ( V_5 , F_186 ( 32 ) ) ;
F_187 ( V_5 , F_186 ( 32 ) ) ;
}
V_2 -> V_211 = ( V_330 >> 8 ) & 0x0f ;
V_2 -> V_209 = ( V_330 >> 12 ) & 0x0f ;
if ( ! V_2 -> V_209 && ! V_2 -> V_211 ) {
switch ( V_2 -> V_195 ) {
case V_336 :
V_2 -> V_209 = V_348 ;
V_2 -> V_211 = V_349 ;
break;
case V_350 :
V_2 -> V_209 = V_351 ;
V_2 -> V_211 = V_352 ;
break;
case V_353 :
default:
V_2 -> V_209 = V_354 ;
V_2 -> V_211 = V_355 ;
break;
}
}
V_2 -> V_210 = 0 ;
V_2 -> V_208 = V_2 -> V_211 ;
V_2 -> V_86 = V_2 -> V_209 + V_2 -> V_211 ;
V_2 -> V_87 = F_188 ( V_2 -> V_86 , sizeof( * V_2 -> V_87 ) ,
V_284 ) ;
if ( ! V_2 -> V_87 ) {
F_4 (KERN_ERR SFX L_55 ) ;
goto V_339;
}
for ( V_85 = 0 ; V_85 < V_2 -> V_86 ; V_85 ++ ) {
V_3 = F_2 ( V_4 ,
F_3 ( V_2 -> V_5 ) ,
V_356 , & V_2 -> V_87 [ V_85 ] . V_141 ) ;
if ( V_3 < 0 ) {
F_4 (KERN_ERR SFX L_56 ) ;
goto V_339;
}
}
V_3 = F_2 ( V_4 ,
F_3 ( V_2 -> V_5 ) ,
V_2 -> V_86 * 8 , & V_2 -> V_100 ) ;
if ( V_3 < 0 ) {
F_4 (KERN_ERR SFX L_57 ) ;
goto V_339;
}
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 )
goto V_339;
F_141 ( V_2 ) ;
F_56 ( V_2 ) ;
F_52 ( V_2 , ( V_357 [ V_204 ] & 2 ) == 0 ) ;
if ( ! V_2 -> V_81 ) {
F_4 (KERN_ERR SFX L_58 ) ;
V_3 = - V_358 ;
goto V_339;
}
V_3 = F_189 ( V_192 , V_359 , V_2 , & V_183 ) ;
if ( V_3 < 0 ) {
F_4 (KERN_ERR SFX L_59 ) ;
goto V_339;
}
strcpy ( V_192 -> V_360 , L_60 ) ;
F_135 ( V_192 -> V_361 , V_362 [ V_2 -> V_195 ] ,
sizeof( V_192 -> V_361 ) ) ;
snprintf ( V_192 -> V_363 , sizeof( V_192 -> V_363 ) ,
L_61 ,
V_192 -> V_361 , V_2 -> V_10 , V_2 -> V_59 ) ;
* V_329 = V_2 ;
return 0 ;
V_339:
F_165 ( V_2 ) ;
return V_3 ;
}
static void F_190 ( struct V_1 * V_2 )
{
#ifdef F_85
struct V_200 * V_201 ;
F_89 (codec, &chip->bus->codec_list, list) {
F_99 ( V_201 ) ;
}
#endif
}
static int T_4 F_191 ( struct V_102 * V_5 ,
const struct V_364 * V_365 )
{
static int V_204 ;
struct V_301 * V_192 ;
struct V_1 * V_2 ;
int V_3 ;
if ( V_204 >= V_366 )
return - V_358 ;
if ( ! V_367 [ V_204 ] ) {
V_204 ++ ;
return - V_368 ;
}
V_3 = F_192 ( V_96 [ V_204 ] , V_369 [ V_204 ] , V_370 , 0 , & V_192 ) ;
if ( V_3 < 0 ) {
F_4 (KERN_ERR SFX L_62 ) ;
return V_3 ;
}
F_193 ( V_192 , & V_5 -> V_204 ) ;
V_3 = F_174 ( V_192 , V_5 , V_204 , V_365 -> V_371 , & V_2 ) ;
if ( V_3 < 0 )
goto V_372;
V_192 -> V_43 = V_2 ;
#ifdef F_194
V_2 -> V_202 = V_202 [ V_204 ] ;
#endif
V_3 = F_84 ( V_2 , V_176 [ V_204 ] ) ;
if ( V_3 < 0 )
goto V_372;
#ifdef F_195
if ( V_373 [ V_204 ] && * V_373 [ V_204 ] ) {
F_4 (KERN_ERR SFX L_63 ,
patch[dev]) ;
V_3 = F_196 ( V_2 -> V_41 , V_373 [ V_204 ] ) ;
if ( V_3 < 0 )
goto V_372;
}
#endif
if ( ( V_357 [ V_204 ] & 1 ) == 0 ) {
V_3 = F_88 ( V_2 ) ;
if ( V_3 < 0 )
goto V_372;
}
V_3 = F_197 ( V_2 -> V_41 ) ;
if ( V_3 < 0 )
goto V_372;
V_3 = F_139 ( V_2 ) ;
if ( V_3 < 0 )
goto V_372;
V_3 = F_198 ( V_192 ) ;
if ( V_3 < 0 )
goto V_372;
F_199 ( V_5 , V_192 ) ;
V_2 -> V_128 = 1 ;
F_190 ( V_2 ) ;
F_161 ( V_2 ) ;
V_204 ++ ;
return V_3 ;
V_372:
F_200 ( V_192 ) ;
return V_3 ;
}
static void T_8 F_201 ( struct V_102 * V_5 )
{
F_200 ( F_148 ( V_5 ) ) ;
F_199 ( V_5 , NULL ) ;
}
static int T_9 F_202 ( void )
{
return F_203 ( & V_360 ) ;
}
static void T_10 F_204 ( void )
{
F_205 ( & V_360 ) ;
}
