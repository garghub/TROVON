static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , bool V_5 )
{
int V_6 ;
if ( F_2 ( V_2 ) )
return;
if ( ! V_4 || ! V_4 -> V_7 || ! V_4 -> V_8 )
return;
#ifdef F_3
if ( V_4 -> V_9 . type == V_10 ) {
struct V_11 * V_12 = V_4 -> V_13 ;
if ( V_5 )
F_4 ( V_12 -> V_14 , V_12 -> V_6 ) ;
else
F_5 ( V_12 -> V_14 , V_12 -> V_6 ) ;
return;
}
#endif
V_6 = ( V_4 -> V_8 + V_15 - 1 ) >> V_16 ;
if ( V_5 )
F_6 ( ( unsigned long ) V_4 -> V_7 , V_6 ) ;
else
F_7 ( ( unsigned long ) V_4 -> V_7 , V_6 ) ;
}
static inline void F_8 ( struct V_1 * V_2 , struct V_3 * V_17 ,
bool V_5 )
{
F_1 ( V_2 , V_17 , V_5 ) ;
}
static inline void F_9 ( struct V_1 * V_2 , struct V_18 * V_18 ,
struct V_19 * V_20 , bool V_5 )
{
if ( V_18 -> V_21 != V_5 ) {
F_1 ( V_2 , F_10 ( V_20 ) , V_5 ) ;
V_18 -> V_21 = V_5 ;
}
}
static inline void F_8 ( struct V_1 * V_2 , struct V_3 * V_17 ,
bool V_5 )
{
}
static inline void F_9 ( struct V_1 * V_2 , struct V_18 * V_18 ,
struct V_19 * V_20 , bool V_5 )
{
}
static int F_11 ( struct V_1 * V_2 )
{
int V_22 ;
V_22 = F_12 ( V_23 ,
F_13 ( V_2 -> V_24 ) ,
V_15 , & V_2 -> V_25 ) ;
if ( V_22 < 0 ) {
F_14 (KERN_ERR SFX L_1 , pci_name(chip->pci)) ;
return V_22 ;
}
F_8 ( V_2 , & V_2 -> V_25 , true ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_16 ( & V_2 -> V_26 ) ;
V_2 -> V_27 . V_28 = V_2 -> V_25 . V_28 ;
V_2 -> V_27 . V_17 = ( V_29 * ) V_2 -> V_25 . V_7 ;
F_17 ( V_2 , V_30 , ( V_29 ) V_2 -> V_27 . V_28 ) ;
F_17 ( V_2 , V_31 , F_18 ( V_2 -> V_27 . V_28 ) ) ;
F_19 ( V_2 , V_32 , 0x02 ) ;
F_20 ( V_2 , V_33 , 0 ) ;
F_20 ( V_2 , V_34 , V_35 ) ;
F_19 ( V_2 , V_36 , V_37 ) ;
V_2 -> V_38 . V_28 = V_2 -> V_25 . V_28 + 2048 ;
V_2 -> V_38 . V_17 = ( V_29 * ) ( V_2 -> V_25 . V_7 + 2048 ) ;
V_2 -> V_38 . V_39 = V_2 -> V_38 . V_40 = 0 ;
memset ( V_2 -> V_38 . V_41 , 0 , sizeof( V_2 -> V_38 . V_41 ) ) ;
F_17 ( V_2 , V_42 , ( V_29 ) V_2 -> V_38 . V_28 ) ;
F_17 ( V_2 , V_43 , F_18 ( V_2 -> V_38 . V_28 ) ) ;
F_19 ( V_2 , V_44 , 0x02 ) ;
F_20 ( V_2 , V_45 , V_46 ) ;
if ( V_2 -> V_47 & V_48 )
F_20 ( V_2 , V_49 , 0xc0 ) ;
else
F_20 ( V_2 , V_49 , 1 ) ;
F_19 ( V_2 , V_50 , V_51 | V_52 ) ;
F_21 ( & V_2 -> V_26 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_16 ( & V_2 -> V_26 ) ;
F_19 ( V_2 , V_50 , 0 ) ;
F_19 ( V_2 , V_36 , 0 ) ;
F_21 ( & V_2 -> V_26 ) ;
}
static unsigned int F_23 ( V_29 V_53 )
{
unsigned int V_28 = V_53 >> 28 ;
if ( V_28 >= V_54 ) {
F_24 () ;
V_28 = 0 ;
}
return V_28 ;
}
static unsigned int F_25 ( V_29 V_55 )
{
unsigned int V_28 = V_55 & 0xf ;
if ( V_28 >= V_54 ) {
F_24 () ;
V_28 = 0 ;
}
return V_28 ;
}
static int F_26 ( struct V_56 * V_57 , V_29 V_58 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
unsigned int V_28 = F_23 ( V_58 ) ;
unsigned int V_39 , V_40 ;
F_16 ( & V_2 -> V_26 ) ;
V_39 = F_27 ( V_2 , V_33 ) ;
if ( V_39 == 0xffff ) {
F_21 ( & V_2 -> V_26 ) ;
return - V_59 ;
}
V_39 ++ ;
V_39 %= V_60 ;
V_40 = F_27 ( V_2 , V_34 ) ;
if ( V_39 == V_40 ) {
F_21 ( & V_2 -> V_26 ) ;
return - V_61 ;
}
V_2 -> V_38 . V_41 [ V_28 ] ++ ;
V_2 -> V_27 . V_17 [ V_39 ] = F_28 ( V_58 ) ;
F_17 ( V_2 , V_33 , V_39 ) ;
F_21 ( & V_2 -> V_26 ) ;
return 0 ;
}
static void F_29 ( struct V_1 * V_2 )
{
unsigned int V_40 , V_39 ;
unsigned int V_28 ;
V_29 V_55 , V_62 ;
V_39 = F_27 ( V_2 , V_45 ) ;
if ( V_39 == 0xffff ) {
return;
}
if ( V_39 == V_2 -> V_38 . V_39 )
return;
V_2 -> V_38 . V_39 = V_39 ;
while ( V_2 -> V_38 . V_40 != V_39 ) {
V_2 -> V_38 . V_40 ++ ;
V_2 -> V_38 . V_40 %= V_63 ;
V_40 = V_2 -> V_38 . V_40 << 1 ;
V_62 = F_30 ( V_2 -> V_38 . V_17 [ V_40 + 1 ] ) ;
V_55 = F_30 ( V_2 -> V_38 . V_17 [ V_40 ] ) ;
V_28 = F_25 ( V_62 ) ;
if ( V_62 & V_64 )
F_31 ( V_2 -> V_57 , V_55 , V_62 ) ;
else if ( V_2 -> V_38 . V_41 [ V_28 ] ) {
V_2 -> V_38 . V_55 [ V_28 ] = V_55 ;
F_32 () ;
V_2 -> V_38 . V_41 [ V_28 ] -- ;
} else
F_14 (KERN_ERR SFX L_2
L_3 ,
pci_name(chip->pci),
res, res_ex,
chip->last_cmd[addr]) ;
}
}
static unsigned int F_33 ( struct V_56 * V_57 ,
unsigned int V_28 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
unsigned long V_65 ;
unsigned long V_66 ;
int V_67 = 0 ;
V_68:
V_65 = V_69 + F_34 ( 1000 ) ;
for ( V_66 = 0 ; ; V_66 ++ ) {
if ( V_2 -> V_70 || V_67 ) {
F_16 ( & V_2 -> V_26 ) ;
F_29 ( V_2 ) ;
F_21 ( & V_2 -> V_26 ) ;
}
if ( ! V_2 -> V_38 . V_41 [ V_28 ] ) {
F_35 () ;
V_57 -> V_71 = 0 ;
if ( ! V_67 )
V_2 -> V_72 = 0 ;
return V_2 -> V_38 . V_55 [ V_28 ] ;
}
if ( F_36 ( V_69 , V_65 ) )
break;
if ( V_57 -> V_73 || V_66 > 3000 )
F_37 ( 2 ) ;
else {
F_38 ( 10 ) ;
F_39 () ;
}
}
if ( ! V_57 -> V_74 )
return - 1 ;
if ( ! V_2 -> V_70 && V_2 -> V_72 < 2 ) {
F_40 ( V_75 L_4
L_5 ,
F_41 ( V_2 -> V_24 ) , V_2 -> V_76 [ V_28 ] ) ;
V_67 = 1 ;
V_2 -> V_72 ++ ;
goto V_68;
}
if ( ! V_2 -> V_70 ) {
F_14 (KERN_WARNING SFX L_4
L_6 ,
pci_name(chip->pci), chip->last_cmd[addr]) ;
V_2 -> V_70 = 1 ;
goto V_68;
}
if ( V_2 -> V_77 ) {
F_14 (KERN_WARNING SFX L_7
L_8 ,
pci_name(chip->pci), chip->last_cmd[addr]) ;
F_42 ( V_2 -> V_78 , V_2 ) ;
V_2 -> V_78 = - 1 ;
F_43 ( V_2 -> V_24 ) ;
V_2 -> V_77 = 0 ;
if ( F_44 ( V_2 , 1 ) < 0 ) {
V_57 -> V_71 = 1 ;
return - 1 ;
}
goto V_68;
}
if ( V_2 -> V_79 ) {
return - 1 ;
}
V_57 -> V_71 = 1 ;
if ( V_57 -> V_80 && ! V_57 -> V_81 && ! V_57 -> V_82 ) {
V_57 -> V_81 = 1 ;
return - 1 ;
}
F_14 ( V_83 L_9
L_10 ,
V_2 -> V_76 [ V_28 ] ) ;
V_2 -> V_84 = 1 ;
V_57 -> V_81 = 0 ;
F_22 ( V_2 ) ;
F_17 ( V_2 , V_85 , F_45 ( V_2 , V_85 ) & ~ V_86 ) ;
return - 1 ;
}
static int F_46 ( struct V_1 * V_2 , unsigned int V_28 )
{
int V_65 = 50 ;
while ( V_65 -- ) {
if ( F_27 ( V_2 , V_87 ) & V_88 ) {
V_2 -> V_38 . V_55 [ V_28 ] = F_45 ( V_2 , V_89 ) ;
return 0 ;
}
F_38 ( 1 ) ;
}
if ( F_47 () )
F_48 ( V_75 L_11 ,
F_41 ( V_2 -> V_24 ) , F_27 ( V_2 , V_87 ) ) ;
V_2 -> V_38 . V_55 [ V_28 ] = - 1 ;
return - V_59 ;
}
static int F_49 ( struct V_56 * V_57 , V_29 V_58 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
unsigned int V_28 = F_23 ( V_58 ) ;
int V_65 = 50 ;
V_57 -> V_71 = 0 ;
while ( V_65 -- ) {
if ( ! ( ( F_27 ( V_2 , V_87 ) & V_90 ) ) ) {
F_20 ( V_2 , V_87 , F_27 ( V_2 , V_87 ) |
V_88 ) ;
F_17 ( V_2 , V_91 , V_58 ) ;
F_20 ( V_2 , V_87 , F_27 ( V_2 , V_87 ) |
V_90 ) ;
return F_46 ( V_2 , V_28 ) ;
}
F_38 ( 1 ) ;
}
if ( F_47 () )
F_48 ( V_75 L_12 ,
F_41 ( V_2 -> V_24 ) , F_27 ( V_2 , V_87 ) , V_58 ) ;
return - V_59 ;
}
static unsigned int F_50 ( struct V_56 * V_57 ,
unsigned int V_28 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
return V_2 -> V_38 . V_55 [ V_28 ] ;
}
static int F_51 ( struct V_56 * V_57 , unsigned int V_58 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
if ( V_2 -> V_92 )
return 0 ;
V_2 -> V_76 [ F_23 ( V_58 ) ] = V_58 ;
if ( V_2 -> V_84 )
return F_49 ( V_57 , V_58 ) ;
else
return F_26 ( V_57 , V_58 ) ;
}
static unsigned int F_52 ( struct V_56 * V_57 ,
unsigned int V_28 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
if ( V_2 -> V_92 )
return 0 ;
if ( V_2 -> V_84 )
return F_50 ( V_57 , V_28 ) ;
else
return F_33 ( V_57 , V_28 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
unsigned long V_65 ;
F_17 ( V_2 , V_85 , F_45 ( V_2 , V_85 ) & ~ V_93 ) ;
V_65 = V_69 + F_34 ( 100 ) ;
while ( ( F_54 ( V_2 , V_85 ) & V_93 ) &&
F_55 ( V_69 , V_65 ) )
F_56 ( 500 , 1000 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
unsigned long V_65 ;
F_19 ( V_2 , V_85 , F_54 ( V_2 , V_85 ) | V_93 ) ;
V_65 = V_69 + F_34 ( 100 ) ;
while ( ! F_54 ( V_2 , V_85 ) &&
F_55 ( V_69 , V_65 ) )
F_56 ( 500 , 1000 ) ;
}
static int F_58 ( struct V_1 * V_2 , int V_94 )
{
if ( ! V_94 )
goto V_95;
F_19 ( V_2 , V_96 , V_97 ) ;
F_53 ( V_2 ) ;
F_56 ( 500 , 1000 ) ;
F_57 ( V_2 ) ;
F_56 ( 1000 , 1200 ) ;
V_95:
if ( ! F_54 ( V_2 , V_85 ) ) {
F_48 ( V_75 L_13 , F_41 ( V_2 -> V_24 ) ) ;
return - V_98 ;
}
if ( ! V_2 -> V_84 )
F_17 ( V_2 , V_85 , F_45 ( V_2 , V_85 ) |
V_86 ) ;
if ( ! V_2 -> V_99 ) {
V_2 -> V_99 = F_27 ( V_2 , V_96 ) ;
F_40 ( V_75 L_14 , F_41 ( V_2 -> V_24 ) , V_2 -> V_99 ) ;
}
return 0 ;
}
static void F_59 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_100 , F_45 ( V_2 , V_100 ) |
V_101 | V_102 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
int V_103 ;
for ( V_103 = 0 ; V_103 < V_2 -> V_104 ; V_103 ++ ) {
struct V_18 * V_18 = & V_2 -> V_18 [ V_103 ] ;
F_61 ( V_18 , V_105 ,
F_62 ( V_18 , V_105 ) & ~ V_106 ) ;
}
F_19 ( V_2 , V_100 , 0 ) ;
F_17 ( V_2 , V_100 , F_45 ( V_2 , V_100 ) &
~ ( V_101 | V_102 ) ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
int V_103 ;
for ( V_103 = 0 ; V_103 < V_2 -> V_104 ; V_103 ++ ) {
struct V_18 * V_18 = & V_2 -> V_18 [ V_103 ] ;
F_61 ( V_18 , V_107 , V_106 ) ;
}
F_19 ( V_2 , V_96 , V_97 ) ;
F_19 ( V_2 , V_108 , V_109 ) ;
F_17 ( V_2 , V_110 , V_101 | V_111 ) ;
}
static void F_64 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
V_18 -> V_112 = 1 ;
F_17 ( V_2 , V_100 ,
F_45 ( V_2 , V_100 ) | ( 1 << V_18 -> V_113 ) ) ;
F_61 ( V_18 , V_105 , F_62 ( V_18 , V_105 ) |
V_114 | V_106 ) ;
}
static void F_65 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
F_61 ( V_18 , V_105 , F_62 ( V_18 , V_105 ) &
~ ( V_114 | V_106 ) ) ;
F_61 ( V_18 , V_107 , V_106 ) ;
}
static void F_66 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
F_65 ( V_2 , V_18 ) ;
F_17 ( V_2 , V_100 ,
F_45 ( V_2 , V_100 ) & ~ ( 1 << V_18 -> V_113 ) ) ;
}
static void F_67 ( struct V_1 * V_2 , int V_94 )
{
if ( V_2 -> V_115 )
return;
F_58 ( V_2 , V_94 ) ;
F_63 ( V_2 ) ;
F_59 ( V_2 ) ;
if ( ! V_2 -> V_84 )
F_15 ( V_2 ) ;
F_17 ( V_2 , V_116 , ( V_29 ) V_2 -> V_117 . V_28 ) ;
F_17 ( V_2 , V_118 , F_18 ( V_2 -> V_117 . V_28 ) ) ;
V_2 -> V_115 = 1 ;
}
static void F_68 ( struct V_119 * V_24 , unsigned int V_120 ,
unsigned char V_121 , unsigned char V_58 )
{
unsigned char V_122 ;
F_69 ( V_24 , V_120 , & V_122 ) ;
V_122 &= ~ V_121 ;
V_122 |= ( V_58 & V_121 ) ;
F_70 ( V_24 , V_120 , V_122 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_47 & V_123 ) ) {
F_40 ( V_75 L_15 , F_41 ( V_2 -> V_24 ) ) ;
F_68 ( V_2 -> V_24 , V_124 , 0x07 , 0 ) ;
}
if ( V_2 -> V_47 & V_125 ) {
F_40 ( V_75 L_16 , F_41 ( V_2 -> V_24 ) , F_2 ( V_2 ) ) ;
F_68 ( V_2 -> V_24 ,
V_126 , 0x07 ,
F_2 ( V_2 ) ? V_127 : 0 ) ;
}
if ( V_2 -> V_47 & V_128 ) {
F_40 ( V_75 L_17 , F_41 ( V_2 -> V_24 ) , F_2 ( V_2 ) ) ;
F_68 ( V_2 -> V_24 ,
V_129 ,
0x0f , V_130 ) ;
F_68 ( V_2 -> V_24 ,
V_131 ,
0x01 , V_132 ) ;
F_68 ( V_2 -> V_24 ,
V_133 ,
0x01 , V_132 ) ;
}
if ( V_2 -> V_47 & V_134 ) {
unsigned short V_135 ;
F_72 ( V_2 -> V_24 , V_136 , & V_135 ) ;
if ( ( ! F_2 ( V_2 ) && ! ( V_135 & V_137 ) ) ||
( F_2 ( V_2 ) && ( V_135 & V_137 ) ) ) {
V_135 &= ~ V_137 ;
if ( ! F_2 ( V_2 ) )
V_135 |= V_137 ;
F_73 ( V_2 -> V_24 , V_136 , V_135 ) ;
F_72 ( V_2 -> V_24 ,
V_136 , & V_135 ) ;
}
F_40 ( V_75 L_18 ,
F_41 ( V_2 -> V_24 ) , ( V_135 & V_137 )
? L_19 : L_20 ) ;
}
}
static T_1 F_74 ( int V_78 , void * V_138 )
{
struct V_1 * V_2 = V_138 ;
struct V_18 * V_18 ;
V_29 V_139 ;
T_2 V_140 ;
int V_103 , V_141 ;
#ifdef F_75
if ( V_2 -> V_24 -> V_9 . V_142 . V_143 != V_144 )
return V_145 ;
#endif
F_76 ( & V_2 -> V_26 ) ;
if ( V_2 -> V_92 ) {
F_77 ( & V_2 -> V_26 ) ;
return V_145 ;
}
V_139 = F_45 ( V_2 , V_110 ) ;
if ( V_139 == 0 ) {
F_77 ( & V_2 -> V_26 ) ;
return V_145 ;
}
for ( V_103 = 0 ; V_103 < V_2 -> V_104 ; V_103 ++ ) {
V_18 = & V_2 -> V_18 [ V_103 ] ;
if ( V_139 & V_18 -> V_146 ) {
V_140 = F_62 ( V_18 , V_107 ) ;
F_61 ( V_18 , V_107 , V_106 ) ;
if ( ! V_18 -> V_20 || ! V_18 -> V_147 ||
! ( V_140 & V_148 ) )
continue;
V_141 = F_78 ( V_2 , V_18 ) ;
if ( V_141 == 1 ) {
V_18 -> V_149 = 0 ;
F_77 ( & V_2 -> V_26 ) ;
F_79 ( V_18 -> V_20 ) ;
F_76 ( & V_2 -> V_26 ) ;
} else if ( V_141 == 0 && V_2 -> V_57 && V_2 -> V_57 -> V_150 ) {
V_18 -> V_149 = 1 ;
F_80 ( V_2 -> V_57 -> V_150 ,
& V_2 -> V_151 ) ;
}
}
}
V_139 = F_54 ( V_2 , V_108 ) ;
if ( V_139 & V_109 ) {
if ( V_139 & V_152 ) {
if ( V_2 -> V_47 & V_153 )
F_38 ( 80 ) ;
F_29 ( V_2 ) ;
}
F_19 ( V_2 , V_108 , V_109 ) ;
}
#if 0
if (azx_readb(chip, STATESTS) & 0x04)
azx_writeb(chip, STATESTS, 0x04);
#endif
F_77 ( & V_2 -> V_26 ) ;
return V_154 ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_18 * V_18 , V_29 * * V_155 ,
int V_156 , int V_157 , int V_158 )
{
V_29 * V_159 = * V_155 ;
while ( V_157 > 0 ) {
T_3 V_28 ;
int V_160 ;
if ( V_18 -> V_161 >= V_162 )
return - V_163 ;
V_28 = F_82 ( V_4 , V_156 ) ;
V_159 [ 0 ] = F_28 ( ( V_29 ) V_28 ) ;
V_159 [ 1 ] = F_28 ( F_18 ( V_28 ) ) ;
V_160 = F_83 ( V_4 , V_156 , V_157 ) ;
if ( V_2 -> V_47 & V_164 ) {
V_29 V_165 = 0x1000 - ( V_156 & 0xfff ) ;
if ( V_160 > V_165 )
V_160 = V_165 ;
}
V_159 [ 2 ] = F_28 ( V_160 ) ;
V_157 -= V_160 ;
V_159 [ 3 ] = ( V_157 || ! V_158 ) ? 0 : F_28 ( 0x01 ) ;
V_159 += 4 ;
V_18 -> V_161 ++ ;
V_156 += V_160 ;
}
* V_155 = V_159 ;
return V_156 ;
}
static int F_84 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
struct V_18 * V_18 )
{
V_29 * V_159 ;
int V_103 , V_156 , V_166 , V_167 ;
int V_168 ;
F_85 ( V_18 , V_169 , 0 ) ;
F_85 ( V_18 , V_170 , 0 ) ;
V_167 = V_18 -> V_167 ;
V_166 = V_18 -> V_171 / V_167 ;
V_159 = ( V_29 * ) V_18 -> V_159 . V_7 ;
V_156 = 0 ;
V_18 -> V_161 = 0 ;
V_168 = V_172 [ V_2 -> V_173 ] ;
if ( ! V_18 -> V_174 && V_168 > 0 ) {
struct V_175 * V_176 = V_20 -> V_176 ;
int V_177 = V_168 ;
V_168 = ( V_168 * V_176 -> V_178 + 47999 ) / 48000 ;
if ( ! V_168 )
V_168 = V_177 ;
else
V_168 = ( ( V_168 + V_177 - 1 ) / V_177 ) *
V_177 ;
V_168 = F_86 ( V_176 , V_168 ) ;
if ( V_168 >= V_167 ) {
F_14 (KERN_WARNING SFX L_21 ,
pci_name(chip->pci), bdl_pos_adj[chip->dev_index]) ;
V_168 = 0 ;
} else {
V_156 = F_81 ( V_2 , F_10 ( V_20 ) ,
V_18 ,
& V_159 , V_156 , V_168 , true ) ;
if ( V_156 < 0 )
goto error;
}
} else
V_168 = 0 ;
for ( V_103 = 0 ; V_103 < V_166 ; V_103 ++ ) {
if ( V_103 == V_166 - 1 && V_168 )
V_156 = F_81 ( V_2 , F_10 ( V_20 ) ,
V_18 , & V_159 , V_156 ,
V_167 - V_168 , 0 ) ;
else
V_156 = F_81 ( V_2 , F_10 ( V_20 ) ,
V_18 , & V_159 , V_156 ,
V_167 ,
! V_18 -> V_174 ) ;
if ( V_156 < 0 )
goto error;
}
return 0 ;
error:
F_14 (KERN_ERR SFX L_22 ,
pci_name(chip->pci), azx_dev->bufsize, period_bytes) ;
return - V_163 ;
}
static void F_87 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
unsigned char V_58 ;
int V_65 ;
F_65 ( V_2 , V_18 ) ;
F_61 ( V_18 , V_105 , F_62 ( V_18 , V_105 ) |
V_179 ) ;
F_38 ( 3 ) ;
V_65 = 300 ;
while ( ! ( ( V_58 = F_62 ( V_18 , V_105 ) ) & V_179 ) &&
-- V_65 )
;
V_58 &= ~ V_179 ;
F_61 ( V_18 , V_105 , V_58 ) ;
F_38 ( 3 ) ;
V_65 = 300 ;
while ( ( ( V_58 = F_62 ( V_18 , V_105 ) ) & V_179 ) &&
-- V_65 )
;
* V_18 -> V_117 = 0 ;
}
static int F_88 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
unsigned int V_58 ;
F_65 ( V_2 , V_18 ) ;
V_58 = F_89 ( V_18 , V_105 ) ;
V_58 = ( V_58 & ~ V_180 ) |
( V_18 -> V_181 << V_182 ) ;
if ( ! F_2 ( V_2 ) )
V_58 |= V_183 ;
F_85 ( V_18 , V_105 , V_58 ) ;
F_85 ( V_18 , V_184 , V_18 -> V_171 ) ;
F_90 ( V_18 , V_185 , V_18 -> V_186 ) ;
F_90 ( V_18 , V_187 , V_18 -> V_161 - 1 ) ;
F_85 ( V_18 , V_169 , ( V_29 ) V_18 -> V_159 . V_28 ) ;
F_85 ( V_18 , V_170 , F_18 ( V_18 -> V_159 . V_28 ) ) ;
if ( V_2 -> V_188 [ 0 ] != V_189 ||
V_2 -> V_188 [ 1 ] != V_189 ) {
if ( ! ( F_45 ( V_2 , V_116 ) & V_190 ) )
F_17 ( V_2 , V_116 ,
( V_29 ) V_2 -> V_117 . V_28 | V_190 ) ;
}
F_85 ( V_18 , V_105 ,
F_89 ( V_18 , V_105 ) | V_106 ) ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 , int V_28 )
{
unsigned int V_53 = ( V_28 << 28 ) | ( V_191 << 20 ) |
( V_192 << 8 ) | V_193 ;
unsigned int V_55 ;
F_92 ( & V_2 -> V_57 -> V_194 ) ;
V_2 -> V_79 = 1 ;
F_51 ( V_2 -> V_57 , V_53 ) ;
V_55 = F_52 ( V_2 -> V_57 , V_28 ) ;
V_2 -> V_79 = 0 ;
F_93 ( & V_2 -> V_57 -> V_194 ) ;
if ( V_55 == - 1 )
return - V_59 ;
F_40 ( V_75 L_23 , F_41 ( V_2 -> V_24 ) , V_28 ) ;
return 0 ;
}
static void F_94 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
V_57 -> V_82 = 1 ;
F_95 ( V_2 ) ;
F_67 ( V_2 , 1 ) ;
#ifdef F_96
if ( V_2 -> V_115 ) {
struct V_195 * V_196 ;
F_97 (p, &chip->pcm_list, list)
F_98 ( V_196 -> V_197 ) ;
F_99 ( V_2 -> V_57 ) ;
F_100 ( V_2 -> V_57 ) ;
}
#endif
V_57 -> V_82 = 0 ;
}
static int F_101 ( struct V_1 * V_2 )
{
int V_103 = V_198 [ V_2 -> V_173 ] ;
unsigned int V_199 ;
if ( V_103 == 0 )
return 0 ;
if ( V_103 < 50 || V_103 > 60000 )
V_199 = 0 ;
else
V_199 = F_34 ( V_103 ) ;
if ( V_199 == 0 )
F_14 (KERN_WARNING SFX
L_24 , i) ;
return V_199 ;
}
static int F_102 ( struct V_1 * V_2 , const char * V_200 )
{
struct V_201 V_202 ;
int V_203 , V_204 , V_22 ;
int V_205 ;
memset ( & V_202 , 0 , sizeof( V_202 ) ) ;
V_202 . V_13 = V_2 ;
V_202 . V_206 = V_200 ;
V_202 . V_24 = V_2 -> V_24 ;
V_202 . V_207 . V_208 = F_51 ;
V_202 . V_207 . V_209 = F_52 ;
V_202 . V_207 . V_210 = V_211 ;
V_202 . V_207 . V_212 = F_94 ;
#ifdef F_96
V_202 . V_213 = & V_213 ;
V_202 . V_207 . V_214 = V_215 ;
#endif
#ifdef F_103
V_202 . V_207 . V_216 = V_217 ;
V_202 . V_207 . V_218 = V_219 ;
V_202 . V_207 . V_220 = V_221 ;
#endif
V_22 = F_104 ( V_2 -> V_222 , & V_202 , & V_2 -> V_57 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( V_2 -> V_47 & V_223 ) {
F_48 ( V_75 L_25 , F_41 ( V_2 -> V_24 ) ) ;
V_2 -> V_57 -> V_73 = 1 ;
}
V_204 = 0 ;
V_205 = V_224 [ V_2 -> V_225 ] ;
if ( ! V_205 )
V_205 = V_226 ;
for ( V_203 = 0 ; V_203 < V_205 ; V_203 ++ ) {
if ( ( V_2 -> V_99 & ( 1 << V_203 ) ) & V_2 -> V_227 ) {
if ( F_91 ( V_2 , V_203 ) < 0 ) {
F_14 (KERN_WARNING SFX
L_26
L_27 , pci_name(chip->pci), c) ;
V_2 -> V_99 &= ~ ( 1 << V_203 ) ;
F_95 ( V_2 ) ;
F_67 ( V_2 , 1 ) ;
}
}
}
if ( V_2 -> V_47 & V_228 ) {
F_48 ( V_75 L_28 ,
F_41 ( V_2 -> V_24 ) ) ;
V_2 -> V_57 -> V_229 = 1 ;
V_2 -> V_57 -> V_80 = 1 ;
}
for ( V_203 = 0 ; V_203 < V_205 ; V_203 ++ ) {
if ( ( V_2 -> V_99 & ( 1 << V_203 ) ) & V_2 -> V_227 ) {
struct V_230 * V_231 ;
V_22 = F_105 ( V_2 -> V_57 , V_203 , & V_231 ) ;
if ( V_22 < 0 )
continue;
V_231 -> V_232 = F_101 ( V_2 ) ;
V_231 -> V_233 = V_2 -> V_233 ;
V_204 ++ ;
}
}
if ( ! V_204 ) {
F_14 (KERN_ERR SFX L_29 , pci_name(chip->pci)) ;
return - V_234 ;
}
return 0 ;
}
static int F_106 ( struct V_1 * V_2 )
{
struct V_230 * V_231 ;
F_97 (codec, &chip->bus->codec_list, list) {
F_107 ( V_231 ) ;
}
return 0 ;
}
static inline struct V_18 *
F_108 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
int V_9 , V_103 , V_235 ;
struct V_18 * V_55 = NULL ;
int V_236 = ( V_20 -> V_197 -> V_237 << 16 ) | ( V_20 -> V_238 << 2 ) |
( V_20 -> V_239 + 1 ) ;
if ( V_20 -> V_239 == V_240 ) {
V_9 = V_2 -> V_241 ;
V_235 = V_2 -> V_242 ;
} else {
V_9 = V_2 -> V_243 ;
V_235 = V_2 -> V_244 ;
}
for ( V_103 = 0 ; V_103 < V_235 ; V_103 ++ , V_9 ++ ) {
struct V_18 * V_18 = & V_2 -> V_18 [ V_9 ] ;
F_109 ( V_18 ) ;
if ( ! V_18 -> V_245 && ! F_110 ( V_18 ) ) {
V_55 = V_18 ;
if ( V_55 -> V_246 == V_236 ) {
V_55 -> V_245 = 1 ;
V_55 -> V_246 = V_236 ;
F_111 ( V_18 ) ;
return V_18 ;
}
}
F_111 ( V_18 ) ;
}
if ( V_55 ) {
F_109 ( V_55 ) ;
V_55 -> V_245 = 1 ;
V_55 -> V_246 = V_236 ;
F_111 ( V_55 ) ;
}
return V_55 ;
}
static inline void F_112 ( struct V_18 * V_18 )
{
V_18 -> V_245 = 0 ;
}
static T_4 F_113 ( const struct V_247 * V_248 )
{
struct V_18 * V_18 = F_114 ( V_248 , struct V_18 , V_249 ) ;
struct V_19 * V_20 = V_18 -> V_20 ;
struct V_195 * V_250 = F_115 ( V_20 ) ;
struct V_1 * V_2 = V_250 -> V_2 ;
return F_45 ( V_2 , V_251 ) ;
}
static void F_116 ( struct V_19 * V_20 ,
bool V_252 , T_4 V_253 )
{
struct V_18 * V_18 = F_117 ( V_20 ) ;
struct V_254 * V_255 = & V_18 -> V_256 ;
struct V_247 * V_248 = & V_18 -> V_249 ;
T_5 V_257 ;
V_248 -> V_258 = F_113 ;
V_248 -> V_121 = F_118 ( 32 ) ;
V_248 -> V_259 = 125 ;
V_248 -> V_260 = 0 ;
V_257 = 0 ;
F_119 ( V_255 , V_248 , V_257 ) ;
if ( V_252 )
V_255 -> V_261 = V_253 ;
}
static T_5 F_120 ( struct V_19 * V_20 ,
T_5 V_257 )
{
struct V_195 * V_250 = F_115 ( V_20 ) ;
struct V_262 * V_263 = V_250 -> V_263 [ V_20 -> V_239 ] ;
T_5 V_264 , V_265 ;
if ( ! V_263 -> V_207 . V_266 )
return V_257 ;
V_264 = V_263 -> V_207 . V_266 ( V_263 , V_250 -> V_231 , V_20 ) ;
V_265 = F_121 ( V_264 * 1000000000LL ,
V_20 -> V_176 -> V_178 ) ;
if ( V_20 -> V_239 == V_267 )
return V_257 + V_265 ;
return ( V_257 > V_265 ) ? V_257 - V_265 : 0 ;
}
static int F_122 ( struct V_19 * V_20 ,
struct V_268 * V_269 )
{
struct V_18 * V_18 = F_117 ( V_20 ) ;
T_5 V_257 ;
V_257 = F_123 ( & V_18 -> V_256 ) ;
V_257 = F_121 ( V_257 , 3 ) ;
V_257 = F_120 ( V_20 , V_257 ) ;
* V_269 = F_124 ( V_257 ) ;
return 0 ;
}
static int F_125 ( struct V_19 * V_20 )
{
struct V_195 * V_250 = F_115 ( V_20 ) ;
struct V_262 * V_263 = V_250 -> V_263 [ V_20 -> V_239 ] ;
struct V_1 * V_2 = V_250 -> V_2 ;
struct V_18 * V_18 ;
struct V_175 * V_176 = V_20 -> V_176 ;
unsigned long V_270 ;
int V_22 ;
int V_271 ;
F_92 ( & V_2 -> V_272 ) ;
V_18 = F_108 ( V_2 , V_20 ) ;
if ( V_18 == NULL ) {
F_93 ( & V_2 -> V_272 ) ;
return - V_98 ;
}
V_176 -> V_273 = V_274 ;
V_176 -> V_273 . V_275 = V_263 -> V_275 ;
V_176 -> V_273 . V_276 = V_263 -> V_276 ;
V_176 -> V_273 . V_277 = V_263 -> V_277 ;
V_176 -> V_273 . V_278 = V_263 -> V_278 ;
F_126 ( V_176 ) ;
F_127 ( V_176 , V_279 ) ;
F_128 ( V_176 , V_280 ,
20 ,
178000000 ) ;
if ( V_2 -> V_281 )
V_271 = 128 ;
else
V_271 = 4 ;
F_129 ( V_176 , 0 , V_282 ,
V_271 ) ;
F_129 ( V_176 , 0 , V_283 ,
V_271 ) ;
F_130 ( V_250 -> V_231 ) ;
V_22 = V_263 -> V_207 . V_284 ( V_263 , V_250 -> V_231 , V_20 ) ;
if ( V_22 < 0 ) {
F_112 ( V_18 ) ;
F_131 ( V_250 -> V_231 ) ;
F_93 ( & V_2 -> V_272 ) ;
return V_22 ;
}
F_126 ( V_176 ) ;
if ( F_132 ( ! V_176 -> V_273 . V_275 ) ||
F_132 ( ! V_176 -> V_273 . V_276 ) ||
F_132 ( ! V_176 -> V_273 . V_277 ) ||
F_132 ( ! V_176 -> V_273 . V_278 ) ) {
F_112 ( V_18 ) ;
V_263 -> V_207 . V_285 ( V_263 , V_250 -> V_231 , V_20 ) ;
F_131 ( V_250 -> V_231 ) ;
F_93 ( & V_2 -> V_272 ) ;
return - V_163 ;
}
if ( V_20 -> V_239 == V_267 )
V_176 -> V_273 . V_286 &= ~ V_287 ;
F_133 ( & V_2 -> V_26 , V_270 ) ;
V_18 -> V_20 = V_20 ;
V_18 -> V_147 = 0 ;
F_134 ( & V_2 -> V_26 , V_270 ) ;
V_176 -> V_13 = V_18 ;
F_135 ( V_20 ) ;
F_93 ( & V_2 -> V_272 ) ;
return 0 ;
}
static int F_136 ( struct V_19 * V_20 )
{
struct V_195 * V_250 = F_115 ( V_20 ) ;
struct V_262 * V_263 = V_250 -> V_263 [ V_20 -> V_239 ] ;
struct V_1 * V_2 = V_250 -> V_2 ;
struct V_18 * V_18 = F_117 ( V_20 ) ;
unsigned long V_270 ;
F_92 ( & V_2 -> V_272 ) ;
F_133 ( & V_2 -> V_26 , V_270 ) ;
V_18 -> V_20 = NULL ;
V_18 -> V_147 = 0 ;
F_134 ( & V_2 -> V_26 , V_270 ) ;
F_112 ( V_18 ) ;
V_263 -> V_207 . V_285 ( V_263 , V_250 -> V_231 , V_20 ) ;
F_131 ( V_250 -> V_231 ) ;
F_93 ( & V_2 -> V_272 ) ;
return 0 ;
}
static int F_137 ( struct V_19 * V_20 ,
struct V_288 * V_289 )
{
struct V_195 * V_250 = F_115 ( V_20 ) ;
struct V_1 * V_2 = V_250 -> V_2 ;
struct V_18 * V_18 = F_117 ( V_20 ) ;
int V_290 ;
F_109 ( V_18 ) ;
if ( F_110 ( V_18 ) ) {
V_290 = - V_98 ;
goto V_291;
}
F_9 ( V_2 , V_18 , V_20 , false ) ;
V_18 -> V_171 = 0 ;
V_18 -> V_167 = 0 ;
V_18 -> V_186 = 0 ;
V_290 = F_138 ( V_20 ,
F_139 ( V_289 ) ) ;
if ( V_290 < 0 )
goto V_291;
F_9 ( V_2 , V_18 , V_20 , true ) ;
V_291:
F_111 ( V_18 ) ;
return V_290 ;
}
static int F_140 ( struct V_19 * V_20 )
{
struct V_195 * V_250 = F_115 ( V_20 ) ;
struct V_18 * V_18 = F_117 ( V_20 ) ;
struct V_1 * V_2 = V_250 -> V_2 ;
struct V_262 * V_263 = V_250 -> V_263 [ V_20 -> V_239 ] ;
F_109 ( V_18 ) ;
if ( ! F_110 ( V_18 ) ) {
F_85 ( V_18 , V_169 , 0 ) ;
F_85 ( V_18 , V_170 , 0 ) ;
F_85 ( V_18 , V_105 , 0 ) ;
V_18 -> V_171 = 0 ;
V_18 -> V_167 = 0 ;
V_18 -> V_186 = 0 ;
}
F_141 ( V_250 -> V_231 , V_263 , V_20 ) ;
F_9 ( V_2 , V_18 , V_20 , false ) ;
V_18 -> V_292 = 0 ;
F_111 ( V_18 ) ;
return F_142 ( V_20 ) ;
}
static int F_143 ( struct V_19 * V_20 )
{
struct V_195 * V_250 = F_115 ( V_20 ) ;
struct V_1 * V_2 = V_250 -> V_2 ;
struct V_18 * V_18 = F_117 ( V_20 ) ;
struct V_262 * V_263 = V_250 -> V_263 [ V_20 -> V_239 ] ;
struct V_175 * V_176 = V_20 -> V_176 ;
unsigned int V_171 , V_167 , V_186 , V_181 ;
int V_22 ;
struct V_293 * V_294 =
F_144 ( V_250 -> V_231 , V_263 -> V_295 ) ;
unsigned short V_296 = V_294 ? V_294 -> V_296 : 0 ;
F_109 ( V_18 ) ;
if ( F_110 ( V_18 ) ) {
V_22 = - V_98 ;
goto V_291;
}
F_87 ( V_2 , V_18 ) ;
V_186 = F_145 ( V_176 -> V_178 ,
V_176 -> V_297 ,
V_176 -> V_298 ,
V_263 -> V_299 ,
V_296 ) ;
if ( ! V_186 ) {
F_14 (KERN_ERR SFX
L_30 ,
pci_name(chip->pci), runtime->rate, runtime->channels, runtime->format) ;
V_22 = - V_163 ;
goto V_291;
}
V_171 = F_146 ( V_20 ) ;
V_167 = F_147 ( V_20 ) ;
F_40 ( V_75 L_31 ,
F_41 ( V_2 -> V_24 ) , V_171 , V_186 ) ;
if ( V_171 != V_18 -> V_171 ||
V_167 != V_18 -> V_167 ||
V_186 != V_18 -> V_186 ||
V_176 -> V_174 != V_18 -> V_174 ) {
V_18 -> V_171 = V_171 ;
V_18 -> V_167 = V_167 ;
V_18 -> V_186 = V_186 ;
V_18 -> V_174 = V_176 -> V_174 ;
V_22 = F_84 ( V_2 , V_20 , V_18 ) ;
if ( V_22 < 0 )
goto V_291;
}
V_18 -> V_300 = ( ( ( V_176 -> V_301 * 24000 ) /
V_176 -> V_178 ) * 1000 ) ;
F_88 ( V_2 , V_18 ) ;
if ( V_20 -> V_239 == V_240 )
V_18 -> V_302 = F_148 ( V_18 , V_303 ) + 1 ;
else
V_18 -> V_302 = 0 ;
V_181 = V_18 -> V_181 ;
if ( ( V_2 -> V_47 & V_48 ) &&
V_181 > V_2 -> V_244 )
V_181 -= V_2 -> V_244 ;
V_22 = F_149 ( V_250 -> V_231 , V_263 , V_181 ,
V_18 -> V_186 , V_20 ) ;
V_291:
if ( ! V_22 )
V_18 -> V_292 = 1 ;
F_111 ( V_18 ) ;
return V_22 ;
}
static int F_150 ( struct V_19 * V_20 , int V_53 )
{
struct V_195 * V_250 = F_115 ( V_20 ) ;
struct V_1 * V_2 = V_250 -> V_2 ;
struct V_18 * V_18 ;
struct V_19 * V_304 ;
int V_305 = 0 , V_306 , V_307 = 0 , V_308 = 0 ;
int V_309 , V_65 ;
V_18 = F_117 ( V_20 ) ;
F_151 ( V_2 , V_18 , V_53 ) ;
if ( F_110 ( V_18 ) || ! V_18 -> V_292 )
return - V_310 ;
switch ( V_53 ) {
case V_311 :
V_305 = 1 ;
case V_312 :
case V_313 :
V_306 = 1 ;
break;
case V_314 :
case V_315 :
case V_316 :
V_306 = 0 ;
break;
default:
return - V_163 ;
}
F_152 (s, substream) {
if ( V_304 -> V_197 -> V_222 != V_20 -> V_197 -> V_222 )
continue;
V_18 = F_117 ( V_304 ) ;
V_308 |= 1 << V_18 -> V_113 ;
V_307 ++ ;
F_153 ( V_304 , V_20 ) ;
}
F_76 ( & V_2 -> V_26 ) ;
if ( V_2 -> V_47 & V_317 )
F_17 ( V_2 , V_318 ,
F_45 ( V_2 , V_318 ) | V_308 ) ;
else
F_17 ( V_2 , V_319 , F_45 ( V_2 , V_319 ) | V_308 ) ;
F_152 (s, substream) {
if ( V_304 -> V_197 -> V_222 != V_20 -> V_197 -> V_222 )
continue;
V_18 = F_117 ( V_304 ) ;
if ( V_306 ) {
V_18 -> V_320 = F_45 ( V_2 , V_251 ) ;
if ( ! V_305 )
V_18 -> V_320 -=
V_18 -> V_300 ;
F_64 ( V_2 , V_18 ) ;
} else {
F_66 ( V_2 , V_18 ) ;
}
V_18 -> V_147 = V_306 ;
}
F_77 ( & V_2 -> V_26 ) ;
if ( V_306 ) {
for ( V_65 = 5000 ; V_65 ; V_65 -- ) {
V_309 = 0 ;
F_152 (s, substream) {
if ( V_304 -> V_197 -> V_222 != V_20 -> V_197 -> V_222 )
continue;
V_18 = F_117 ( V_304 ) ;
if ( ! ( F_62 ( V_18 , V_107 ) &
V_321 ) )
V_309 ++ ;
}
if ( ! V_309 )
break;
F_154 () ;
}
} else {
for ( V_65 = 5000 ; V_65 ; V_65 -- ) {
V_309 = 0 ;
F_152 (s, substream) {
if ( V_304 -> V_197 -> V_222 != V_20 -> V_197 -> V_222 )
continue;
V_18 = F_117 ( V_304 ) ;
if ( F_62 ( V_18 , V_105 ) &
V_114 )
V_309 ++ ;
}
if ( ! V_309 )
break;
F_154 () ;
}
}
F_76 ( & V_2 -> V_26 ) ;
if ( V_2 -> V_47 & V_317 )
F_17 ( V_2 , V_318 ,
F_45 ( V_2 , V_318 ) & ~ V_308 ) ;
else
F_17 ( V_2 , V_319 , F_45 ( V_2 , V_319 ) & ~ V_308 ) ;
if ( V_306 ) {
F_116 ( V_20 , 0 , 0 ) ;
if ( V_307 > 1 ) {
T_4 V_261 ;
V_18 = F_117 ( V_20 ) ;
V_261 = V_18 -> V_256 . V_261 ;
F_152 (s, substream) {
if ( V_304 -> V_197 -> V_222 != V_20 -> V_197 -> V_222 )
continue;
F_116 ( V_304 , 1 , V_261 ) ;
}
}
}
F_77 ( & V_2 -> V_26 ) ;
return 0 ;
}
static unsigned int F_155 ( struct V_1 * V_2 ,
struct V_18 * V_18 )
{
unsigned int V_322 , V_323 , V_324 ;
unsigned int V_325 , V_326 , V_327 ;
unsigned int V_302 ;
V_322 = F_89 ( V_18 , V_328 ) ;
if ( V_18 -> V_20 -> V_239 == V_240 ) {
return V_322 ;
}
V_326 = F_30 ( * V_18 -> V_117 ) ;
V_326 %= V_18 -> V_167 ;
V_302 = F_156 ( V_2 -> V_329 + V_330 ) ;
if ( V_18 -> V_112 ) {
if ( V_322 <= V_302 )
return 0 ;
V_18 -> V_112 = 0 ;
}
if ( V_322 <= V_302 )
V_323 = V_18 -> V_171 + V_322 - V_302 ;
else
V_323 = V_322 - V_302 ;
V_327 = V_323 % V_18 -> V_167 ;
V_325 = V_322 % V_18 -> V_167 ;
if ( V_325 >= V_302 )
V_324 = V_322 - V_325 ;
else if ( V_326 >= V_327 )
V_324 = V_323 - V_327 ;
else {
V_324 = V_323 - V_327 + V_18 -> V_167 ;
if ( V_324 >= V_18 -> V_171 )
V_324 = 0 ;
}
return V_324 + V_326 ;
}
static unsigned int F_157 ( struct V_1 * V_2 ,
struct V_18 * V_18 ,
bool V_331 )
{
struct V_19 * V_20 = V_18 -> V_20 ;
struct V_195 * V_250 = F_115 ( V_20 ) ;
unsigned int V_332 ;
int V_239 = V_20 -> V_239 ;
struct V_262 * V_263 = V_250 -> V_263 [ V_239 ] ;
int V_333 = 0 ;
switch ( V_2 -> V_188 [ V_239 ] ) {
case V_189 :
V_332 = F_89 ( V_18 , V_328 ) ;
break;
case V_334 :
V_332 = F_155 ( V_2 , V_18 ) ;
break;
default:
V_332 = F_30 ( * V_18 -> V_117 ) ;
if ( V_331 && V_2 -> V_188 [ V_239 ] == V_335 ) {
if ( ! V_332 || V_332 == ( V_29 ) - 1 ) {
F_158 ( V_336
L_32
L_33 ) ;
V_2 -> V_188 [ V_239 ] = V_189 ;
V_332 = F_89 ( V_18 , V_328 ) ;
} else
V_2 -> V_188 [ V_239 ] = V_337 ;
}
break;
}
if ( V_332 >= V_18 -> V_171 )
V_332 = 0 ;
if ( V_20 -> V_176 &&
V_2 -> V_188 [ V_239 ] == V_337 &&
( V_2 -> V_47 & V_338 ) ) {
unsigned int V_339 = F_89 ( V_18 , V_328 ) ;
if ( V_239 == V_240 )
V_333 = V_332 - V_339 ;
else
V_333 = V_339 - V_332 ;
if ( V_333 < 0 )
V_333 += V_18 -> V_171 ;
if ( V_333 >= V_18 -> V_167 ) {
F_14 (KERN_WARNING SFX
L_34
L_35 ,
pci_name(chip->pci), delay, azx_dev->period_bytes) ;
V_333 = 0 ;
V_2 -> V_47 &= ~ V_338 ;
}
V_333 = F_159 ( V_20 -> V_176 , V_333 ) ;
}
if ( V_20 -> V_176 ) {
if ( V_263 -> V_207 . V_266 )
V_333 += V_263 -> V_207 . V_266 ( V_263 , V_250 -> V_231 ,
V_20 ) ;
V_20 -> V_176 -> V_333 = V_333 ;
}
F_160 ( V_2 , V_18 , V_332 , V_333 ) ;
return V_332 ;
}
static T_6 F_161 ( struct V_19 * V_20 )
{
struct V_195 * V_250 = F_115 ( V_20 ) ;
struct V_1 * V_2 = V_250 -> V_2 ;
struct V_18 * V_18 = F_117 ( V_20 ) ;
return F_159 ( V_20 -> V_176 ,
F_157 ( V_2 , V_18 , false ) ) ;
}
static int F_78 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
V_29 V_340 ;
unsigned int V_332 ;
V_340 = F_45 ( V_2 , V_251 ) - V_18 -> V_320 ;
if ( V_340 < ( V_18 -> V_300 * 2 ) / 3 )
return - 1 ;
V_332 = F_157 ( V_2 , V_18 , true ) ;
if ( F_162 ( ! V_18 -> V_167 ,
L_36 ) )
return - 1 ;
if ( V_340 < ( V_18 -> V_300 * 5 ) / 4 &&
V_332 % V_18 -> V_167 > V_18 -> V_167 / 2 )
return V_172 [ V_2 -> V_173 ] ? 0 : - 1 ;
V_18 -> V_320 += V_340 ;
return 1 ;
}
static void F_163 ( struct V_341 * V_342 )
{
struct V_1 * V_2 = F_114 ( V_342 , struct V_1 , V_151 ) ;
int V_103 , V_343 , V_141 ;
if ( ! V_2 -> V_344 ) {
F_158 ( V_336
L_37
L_38 ,
V_2 -> V_222 -> V_238 ) ;
V_2 -> V_344 = 1 ;
}
for (; ; ) {
V_343 = 0 ;
F_16 ( & V_2 -> V_26 ) ;
for ( V_103 = 0 ; V_103 < V_2 -> V_104 ; V_103 ++ ) {
struct V_18 * V_18 = & V_2 -> V_18 [ V_103 ] ;
if ( ! V_18 -> V_149 ||
! V_18 -> V_20 ||
! V_18 -> V_147 )
continue;
V_141 = F_78 ( V_2 , V_18 ) ;
if ( V_141 > 0 ) {
V_18 -> V_149 = 0 ;
F_77 ( & V_2 -> V_26 ) ;
F_79 ( V_18 -> V_20 ) ;
F_76 ( & V_2 -> V_26 ) ;
} else if ( V_141 < 0 ) {
V_343 = 0 ;
} else
V_343 ++ ;
}
F_21 ( & V_2 -> V_26 ) ;
if ( ! V_343 )
return;
F_37 ( 1 ) ;
}
}
static void F_164 ( struct V_1 * V_2 )
{
int V_103 ;
F_16 ( & V_2 -> V_26 ) ;
for ( V_103 = 0 ; V_103 < V_2 -> V_104 ; V_103 ++ )
V_2 -> V_18 [ V_103 ] . V_149 = 0 ;
F_21 ( & V_2 -> V_26 ) ;
}
static int F_165 ( struct V_19 * V_20 ,
struct V_345 * V_7 )
{
struct V_195 * V_250 = F_115 ( V_20 ) ;
struct V_1 * V_2 = V_250 -> V_2 ;
if ( ! F_2 ( V_2 ) )
V_7 -> V_346 = F_166 ( V_7 -> V_346 ) ;
return F_167 ( V_20 , V_7 ) ;
}
static void F_168 ( struct V_347 * V_197 )
{
struct V_195 * V_250 = V_197 -> V_13 ;
if ( V_250 ) {
F_169 ( & V_250 -> V_348 ) ;
F_170 ( V_250 ) ;
}
}
static int
V_211 ( struct V_56 * V_57 , struct V_230 * V_231 ,
struct V_349 * V_350 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
struct V_347 * V_197 ;
struct V_195 * V_250 ;
int V_351 = V_350 -> V_237 ;
unsigned int V_157 ;
int V_304 , V_22 ;
F_97 (apcm, &chip->pcm_list, list) {
if ( V_250 -> V_197 -> V_237 == V_351 ) {
F_14 (KERN_ERR SFX L_39 ,
pci_name(chip->pci), pcm_dev) ;
return - V_98 ;
}
}
V_22 = F_171 ( V_2 -> V_222 , V_350 -> V_352 , V_351 ,
V_350 -> V_239 [ V_240 ] . V_353 ,
V_350 -> V_239 [ V_267 ] . V_353 ,
& V_197 ) ;
if ( V_22 < 0 )
return V_22 ;
F_172 ( V_197 -> V_352 , V_350 -> V_352 , sizeof( V_197 -> V_352 ) ) ;
V_250 = F_173 ( sizeof( * V_250 ) , V_354 ) ;
if ( V_250 == NULL )
return - V_355 ;
V_250 -> V_2 = V_2 ;
V_250 -> V_197 = V_197 ;
V_250 -> V_231 = V_231 ;
V_197 -> V_13 = V_250 ;
V_197 -> V_356 = F_168 ;
if ( V_350 -> V_357 == V_358 )
V_197 -> V_359 = V_360 ;
F_174 ( & V_250 -> V_348 , & V_2 -> V_361 ) ;
V_350 -> V_197 = V_197 ;
for ( V_304 = 0 ; V_304 < 2 ; V_304 ++ ) {
V_250 -> V_263 [ V_304 ] = & V_350 -> V_239 [ V_304 ] ;
if ( V_350 -> V_239 [ V_304 ] . V_353 )
F_175 ( V_197 , V_304 , & V_362 ) ;
}
V_157 = V_363 * 1024 ;
if ( V_157 > V_364 )
V_157 = V_364 ;
F_176 ( V_197 , V_10 ,
F_13 ( V_2 -> V_24 ) ,
V_157 , V_364 ) ;
return 0 ;
}
static int F_177 ( struct V_1 * V_2 )
{
return F_178 ( V_2 -> V_57 ) ;
}
static int F_179 ( struct V_1 * V_2 )
{
int V_103 ;
for ( V_103 = 0 ; V_103 < V_2 -> V_104 ; V_103 ++ ) {
struct V_18 * V_18 = & V_2 -> V_18 [ V_103 ] ;
V_18 -> V_117 = ( V_29 V_365 * ) ( V_2 -> V_117 . V_7 + V_103 * 8 ) ;
V_18 -> V_366 = V_2 -> V_329 + ( 0x20 * V_103 + 0x80 ) ;
V_18 -> V_146 = 1 << V_103 ;
V_18 -> V_113 = V_103 ;
V_18 -> V_181 = V_103 + 1 ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , int V_367 )
{
if ( F_180 ( V_2 -> V_24 -> V_78 , F_74 ,
V_2 -> V_77 ? 0 : V_368 ,
V_369 , V_2 ) ) {
F_158 ( V_83 L_40
L_41 , V_2 -> V_24 -> V_78 ) ;
if ( V_367 )
F_181 ( V_2 -> V_222 ) ;
return - 1 ;
}
V_2 -> V_78 = V_2 -> V_24 -> V_78 ;
F_182 ( V_2 -> V_24 , ! V_2 -> V_77 ) ;
return 0 ;
}
static void F_95 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_115 )
return;
F_60 ( V_2 ) ;
F_63 ( V_2 ) ;
F_22 ( V_2 ) ;
F_17 ( V_2 , V_116 , 0 ) ;
F_17 ( V_2 , V_118 , 0 ) ;
V_2 -> V_115 = 0 ;
}
static struct V_18 *
F_183 ( struct V_1 * V_2 )
{
return & V_2 -> V_18 [ V_2 -> V_241 ] ;
}
static int V_217 ( struct V_56 * V_57 , unsigned int V_298 ,
unsigned int V_370 ,
struct V_3 * V_371 )
{
V_29 * V_159 ;
struct V_1 * V_2 = V_57 -> V_13 ;
struct V_18 * V_18 ;
int V_22 ;
V_18 = F_183 ( V_2 ) ;
F_109 ( V_18 ) ;
F_16 ( & V_2 -> V_26 ) ;
if ( V_18 -> V_147 || V_18 -> V_372 ) {
F_21 ( & V_2 -> V_26 ) ;
V_22 = - V_98 ;
goto V_291;
}
V_18 -> V_292 = 0 ;
V_2 -> V_373 = * V_18 ;
V_18 -> V_372 = 1 ;
F_21 ( & V_2 -> V_26 ) ;
V_22 = F_12 ( V_10 ,
F_13 ( V_2 -> V_24 ) ,
V_370 , V_371 ) ;
if ( V_22 < 0 )
goto V_374;
F_8 ( V_2 , V_371 , true ) ;
V_18 -> V_171 = V_370 ;
V_18 -> V_167 = V_370 ;
V_18 -> V_186 = V_298 ;
F_87 ( V_2 , V_18 ) ;
F_85 ( V_18 , V_169 , 0 ) ;
F_85 ( V_18 , V_170 , 0 ) ;
V_18 -> V_161 = 0 ;
V_159 = ( V_29 * ) V_18 -> V_159 . V_7 ;
V_22 = F_81 ( V_2 , V_371 , V_18 , & V_159 , 0 , V_370 , 0 ) ;
if ( V_22 < 0 )
goto error;
F_88 ( V_2 , V_18 ) ;
F_111 ( V_18 ) ;
return V_18 -> V_181 ;
error:
F_8 ( V_2 , V_371 , false ) ;
F_184 ( V_371 ) ;
V_374:
F_16 ( & V_2 -> V_26 ) ;
if ( V_18 -> V_245 )
* V_18 = V_2 -> V_373 ;
V_18 -> V_372 = 0 ;
F_21 ( & V_2 -> V_26 ) ;
V_291:
F_111 ( V_18 ) ;
return V_22 ;
}
static void V_219 ( struct V_56 * V_57 , bool V_306 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
struct V_18 * V_18 = F_183 ( V_2 ) ;
if ( V_306 )
F_64 ( V_2 , V_18 ) ;
else
F_66 ( V_2 , V_18 ) ;
V_18 -> V_147 = V_306 ;
}
static void V_221 ( struct V_56 * V_57 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
struct V_18 * V_18 = F_183 ( V_2 ) ;
if ( ! V_4 -> V_7 || ! V_18 -> V_372 )
return;
F_109 ( V_18 ) ;
F_85 ( V_18 , V_169 , 0 ) ;
F_85 ( V_18 , V_170 , 0 ) ;
F_85 ( V_18 , V_105 , 0 ) ;
V_18 -> V_171 = 0 ;
V_18 -> V_167 = 0 ;
V_18 -> V_186 = 0 ;
F_8 ( V_2 , V_4 , false ) ;
F_184 ( V_4 ) ;
V_4 -> V_7 = NULL ;
F_16 ( & V_2 -> V_26 ) ;
if ( V_18 -> V_245 )
* V_18 = V_2 -> V_373 ;
V_18 -> V_372 = 0 ;
F_21 ( & V_2 -> V_26 ) ;
F_111 ( V_18 ) ;
}
static void V_215 ( struct V_56 * V_57 , bool V_375 )
{
struct V_1 * V_2 = V_57 -> V_13 ;
if ( ! ( V_2 -> V_47 & V_376 ) )
return;
if ( V_375 )
F_185 ( & V_2 -> V_24 -> V_9 ) ;
else
F_186 ( & V_2 -> V_24 -> V_9 ) ;
}
static void F_187 ( struct V_1 * V_2 )
{
F_92 ( & V_377 ) ;
F_188 ( & V_2 -> V_348 , & V_378 ) ;
F_93 ( & V_377 ) ;
}
static void F_189 ( struct V_1 * V_2 )
{
F_92 ( & V_377 ) ;
F_190 ( & V_2 -> V_348 ) ;
F_93 ( & V_377 ) ;
}
static int F_191 ( const char * V_58 , const struct V_379 * V_380 )
{
struct V_1 * V_2 ;
struct V_230 * V_203 ;
int V_381 = V_213 ;
int V_290 = F_192 ( V_58 , V_380 ) ;
if ( V_290 || V_381 == V_213 )
return V_290 ;
F_92 ( & V_377 ) ;
F_97 (chip, &card_list, list) {
if ( ! V_2 -> V_57 || V_2 -> V_92 )
continue;
F_97 (c, &chip->bus->codec_list, list)
F_193 ( V_203 ) ;
}
F_93 ( & V_377 ) ;
return 0 ;
}
static int F_194 ( struct V_237 * V_9 )
{
struct V_119 * V_24 = F_195 ( V_9 ) ;
struct V_382 * V_222 = F_196 ( V_9 ) ;
struct V_1 * V_2 = V_222 -> V_13 ;
struct V_195 * V_196 ;
if ( V_2 -> V_92 )
return 0 ;
F_197 ( V_222 , V_383 ) ;
F_164 ( V_2 ) ;
F_97 (p, &chip->pcm_list, list)
F_98 ( V_196 -> V_197 ) ;
if ( V_2 -> V_115 )
F_99 ( V_2 -> V_57 ) ;
F_95 ( V_2 ) ;
F_53 ( V_2 ) ;
if ( V_2 -> V_78 >= 0 ) {
F_42 ( V_2 -> V_78 , V_2 ) ;
V_2 -> V_78 = - 1 ;
}
if ( V_2 -> V_77 )
F_43 ( V_2 -> V_24 ) ;
F_198 ( V_24 ) ;
F_199 ( V_24 ) ;
F_200 ( V_24 , V_384 ) ;
if ( V_2 -> V_47 & V_385 )
F_201 ( false ) ;
return 0 ;
}
static int F_202 ( struct V_237 * V_9 )
{
struct V_119 * V_24 = F_195 ( V_9 ) ;
struct V_382 * V_222 = F_196 ( V_9 ) ;
struct V_1 * V_2 = V_222 -> V_13 ;
if ( V_2 -> V_92 )
return 0 ;
if ( V_2 -> V_47 & V_385 )
F_201 ( true ) ;
F_200 ( V_24 , V_386 ) ;
F_203 ( V_24 ) ;
if ( F_204 ( V_24 ) < 0 ) {
F_158 ( V_83 L_42
L_41 ) ;
F_181 ( V_222 ) ;
return - V_59 ;
}
F_205 ( V_24 ) ;
if ( V_2 -> V_77 )
if ( F_206 ( V_24 ) < 0 )
V_2 -> V_77 = 0 ;
if ( F_44 ( V_2 , 1 ) < 0 )
return - V_59 ;
F_71 ( V_2 ) ;
F_67 ( V_2 , 1 ) ;
F_100 ( V_2 -> V_57 ) ;
F_197 ( V_222 , V_387 ) ;
return 0 ;
}
static int F_207 ( struct V_237 * V_9 )
{
struct V_382 * V_222 = F_196 ( V_9 ) ;
struct V_1 * V_2 = V_222 -> V_13 ;
F_95 ( V_2 ) ;
F_53 ( V_2 ) ;
F_164 ( V_2 ) ;
if ( V_2 -> V_47 & V_385 )
F_201 ( false ) ;
return 0 ;
}
static int F_208 ( struct V_237 * V_9 )
{
struct V_382 * V_222 = F_196 ( V_9 ) ;
struct V_1 * V_2 = V_222 -> V_13 ;
if ( V_2 -> V_47 & V_385 )
F_201 ( true ) ;
F_71 ( V_2 ) ;
F_67 ( V_2 , 1 ) ;
return 0 ;
}
static int F_209 ( struct V_237 * V_9 )
{
struct V_382 * V_222 = F_196 ( V_9 ) ;
struct V_1 * V_2 = V_222 -> V_13 ;
if ( ! V_388 ||
! ( V_2 -> V_47 & V_376 ) )
return - V_98 ;
return 0 ;
}
static int F_210 ( struct V_389 * V_390 , unsigned long V_391 , void * V_17 )
{
struct V_1 * V_2 = F_114 ( V_390 , struct V_1 , V_392 ) ;
F_211 ( V_2 -> V_57 ) ;
F_95 ( V_2 ) ;
return V_393 ;
}
static void F_212 ( struct V_1 * V_2 )
{
V_2 -> V_392 . V_394 = F_210 ;
F_213 ( & V_2 -> V_392 ) ;
}
static void F_214 ( struct V_1 * V_2 )
{
if ( V_2 -> V_392 . V_394 )
F_215 ( & V_2 -> V_392 ) ;
}
static void F_216 ( struct V_119 * V_24 ,
enum V_395 V_396 )
{
struct V_382 * V_222 = F_217 ( V_24 ) ;
struct V_1 * V_2 = V_222 -> V_13 ;
bool V_92 ;
F_218 ( & V_2 -> V_397 ) ;
if ( V_2 -> V_398 )
return;
V_92 = ( V_396 == V_399 ) ;
if ( V_2 -> V_92 == V_92 )
return;
if ( ! V_2 -> V_57 ) {
V_2 -> V_92 = V_92 ;
if ( ! V_92 ) {
F_14 (KERN_INFO SFX
L_43 ,
pci_name(chip->pci)) ;
if ( F_219 ( V_2 ) < 0 ) {
F_14 (KERN_ERR SFX
L_44 ,
pci_name(chip->pci)) ;
V_2 -> V_398 = true ;
}
}
} else {
F_14 (KERN_INFO SFX
L_45 , pci_name(chip->pci),
disabled ? L_46 : L_47 ) ;
if ( V_92 ) {
F_194 ( & V_24 -> V_9 ) ;
V_2 -> V_92 = true ;
if ( F_220 ( V_2 -> V_57 ) )
F_14 (KERN_WARNING SFX L_48 ,
pci_name(chip->pci)) ;
} else {
F_221 ( V_2 -> V_57 ) ;
V_2 -> V_92 = false ;
F_202 ( & V_24 -> V_9 ) ;
}
}
}
static bool F_222 ( struct V_119 * V_24 )
{
struct V_382 * V_222 = F_217 ( V_24 ) ;
struct V_1 * V_2 = V_222 -> V_13 ;
F_218 ( & V_2 -> V_397 ) ;
if ( V_2 -> V_398 )
return false ;
if ( V_2 -> V_92 || ! V_2 -> V_57 )
return true ;
if ( F_220 ( V_2 -> V_57 ) )
return false ;
F_221 ( V_2 -> V_57 ) ;
return true ;
}
static void F_223 ( struct V_1 * V_2 )
{
struct V_119 * V_196 = F_224 ( V_2 -> V_24 ) ;
if ( V_196 ) {
F_14 (KERN_INFO SFX
L_49 ,
pci_name(chip->pci)) ;
V_2 -> V_400 = 1 ;
F_225 ( V_196 ) ;
}
}
static int F_226 ( struct V_1 * V_2 )
{
int V_22 ;
if ( ! V_2 -> V_400 )
return 0 ;
V_22 = F_227 ( V_2 -> V_24 , & V_401 ,
V_402 ,
V_2 -> V_57 != NULL ) ;
if ( V_22 < 0 )
return V_22 ;
V_2 -> V_403 = 1 ;
return 0 ;
}
static int F_228 ( struct V_1 * V_2 )
{
struct V_119 * V_24 = V_2 -> V_24 ;
int V_103 ;
if ( ( V_2 -> V_47 & V_376 )
&& V_2 -> V_147 )
F_229 ( & V_24 -> V_9 ) ;
F_189 ( V_2 ) ;
F_214 ( V_2 ) ;
V_2 -> V_398 = 1 ;
F_230 ( & V_2 -> V_397 ) ;
if ( V_400 ( V_2 ) ) {
if ( V_2 -> V_92 && V_2 -> V_57 )
F_221 ( V_2 -> V_57 ) ;
if ( V_2 -> V_403 )
F_231 ( V_2 -> V_24 ) ;
}
if ( V_2 -> V_115 ) {
F_164 ( V_2 ) ;
for ( V_103 = 0 ; V_103 < V_2 -> V_104 ; V_103 ++ )
F_66 ( V_2 , & V_2 -> V_18 [ V_103 ] ) ;
F_95 ( V_2 ) ;
}
if ( V_2 -> V_78 >= 0 )
F_42 ( V_2 -> V_78 , ( void * ) V_2 ) ;
if ( V_2 -> V_77 )
F_43 ( V_2 -> V_24 ) ;
if ( V_2 -> V_329 )
F_232 ( V_2 -> V_329 ) ;
if ( V_2 -> V_18 ) {
for ( V_103 = 0 ; V_103 < V_2 -> V_104 ; V_103 ++ )
if ( V_2 -> V_18 [ V_103 ] . V_159 . V_7 ) {
F_8 ( V_2 , & V_2 -> V_18 [ V_103 ] . V_159 , false ) ;
F_184 ( & V_2 -> V_18 [ V_103 ] . V_159 ) ;
}
}
if ( V_2 -> V_25 . V_7 ) {
F_8 ( V_2 , & V_2 -> V_25 , false ) ;
F_184 ( & V_2 -> V_25 ) ;
}
if ( V_2 -> V_117 . V_7 ) {
F_8 ( V_2 , & V_2 -> V_117 , false ) ;
F_184 ( & V_2 -> V_117 ) ;
}
if ( V_2 -> V_404 )
F_233 ( V_2 -> V_24 ) ;
F_198 ( V_2 -> V_24 ) ;
F_170 ( V_2 -> V_18 ) ;
#ifdef F_234
if ( V_2 -> V_405 )
F_235 ( V_2 -> V_405 ) ;
#endif
if ( V_2 -> V_47 & V_385 ) {
F_201 ( false ) ;
F_236 () ;
}
F_170 ( V_2 ) ;
return 0 ;
}
static int F_237 ( struct V_406 * V_237 )
{
return F_228 ( V_237 -> V_407 ) ;
}
static struct V_119 * F_224 ( struct V_119 * V_24 )
{
struct V_119 * V_196 ;
switch ( V_24 -> V_408 ) {
case V_409 :
case V_410 :
case V_411 :
if ( V_24 -> V_412 == 1 ) {
V_196 = F_238 ( F_239 ( V_24 -> V_57 ) ,
V_24 -> V_57 -> V_238 , 0 ) ;
if ( V_196 ) {
if ( ( V_196 -> V_413 >> 8 ) == V_414 )
return V_196 ;
F_225 ( V_196 ) ;
}
}
break;
}
return NULL ;
}
static bool F_240 ( struct V_119 * V_24 )
{
bool V_415 = false ;
struct V_119 * V_196 = F_224 ( V_24 ) ;
if ( V_196 ) {
if ( F_241 ( V_196 ) == V_399 )
V_415 = true ;
F_225 ( V_196 ) ;
}
return V_415 ;
}
static int F_242 ( struct V_1 * V_2 , int V_416 )
{
const struct V_417 * V_418 ;
switch ( V_416 ) {
case V_335 :
case V_189 :
case V_337 :
case V_334 :
case V_419 :
return V_416 ;
}
V_418 = F_243 ( V_2 -> V_24 , V_420 ) ;
if ( V_418 ) {
F_158 ( V_421
L_50
L_51 ,
V_418 -> V_422 , V_418 -> V_423 , V_418 -> V_424 ) ;
return V_418 -> V_422 ;
}
if ( V_2 -> V_47 & V_425 ) {
F_48 ( V_75 L_52 , F_41 ( V_2 -> V_24 ) ) ;
return V_334 ;
}
if ( V_2 -> V_47 & V_426 ) {
F_48 ( V_75 L_53 , F_41 ( V_2 -> V_24 ) ) ;
return V_189 ;
}
return V_335 ;
}
static void F_244 ( struct V_1 * V_2 , int V_9 )
{
const struct V_417 * V_418 ;
V_2 -> V_227 = V_427 [ V_9 ] ;
if ( V_2 -> V_227 == - 1 ) {
V_418 = F_243 ( V_2 -> V_24 , V_428 ) ;
if ( V_418 ) {
F_158 ( V_421
L_54
L_51 ,
V_418 -> V_422 , V_418 -> V_423 , V_418 -> V_424 ) ;
V_2 -> V_227 = V_418 -> V_422 ;
}
}
if ( V_2 -> V_227 != - 1 &&
( V_2 -> V_227 & V_429 ) ) {
V_2 -> V_99 = V_2 -> V_227 & 0xff ;
F_158 ( V_421 L_55 ,
V_2 -> V_99 ) ;
}
}
static void F_245 ( struct V_1 * V_2 )
{
const struct V_417 * V_418 ;
if ( V_430 >= 0 ) {
V_2 -> V_77 = ! ! V_430 ;
return;
}
V_2 -> V_77 = 1 ;
V_418 = F_243 ( V_2 -> V_24 , V_431 ) ;
if ( V_418 ) {
F_158 ( V_421
L_56 ,
V_418 -> V_423 , V_418 -> V_424 , V_418 -> V_422 ) ;
V_2 -> V_77 = V_418 -> V_422 ;
return;
}
if ( V_2 -> V_47 & V_432 ) {
F_158 ( V_421 L_57 ) ;
V_2 -> V_77 = 0 ;
}
}
static void F_246 ( struct V_1 * V_2 )
{
bool V_135 = V_2 -> V_135 ;
switch ( V_2 -> V_225 ) {
case V_433 :
if ( V_135 ) {
T_2 V_58 ;
F_69 ( V_2 -> V_24 , 0x42 , & V_58 ) ;
if ( ! ( V_58 & 0x80 ) && V_2 -> V_24 -> V_434 == 0x30 )
V_135 = false ;
}
break;
case V_435 :
V_135 = false ;
break;
case V_436 :
V_135 = false ;
break;
}
if ( V_135 != V_2 -> V_135 ) {
F_14 (KERN_INFO SFX L_58 ,
pci_name(chip->pci), snoop ? L_59 : L_60 ) ;
V_2 -> V_135 = V_135 ;
}
}
static void F_247 ( struct V_341 * V_342 )
{
F_219 ( F_114 ( V_342 , struct V_1 , V_437 ) ) ;
}
static int F_248 ( struct V_382 * V_222 , struct V_119 * V_24 ,
int V_9 , unsigned int V_47 ,
struct V_1 * * V_438 )
{
static struct V_439 V_207 = {
. V_440 = F_237 ,
} ;
struct V_1 * V_2 ;
int V_22 ;
* V_438 = NULL ;
V_22 = F_204 ( V_24 ) ;
if ( V_22 < 0 )
return V_22 ;
V_2 = F_173 ( sizeof( * V_2 ) , V_354 ) ;
if ( ! V_2 ) {
F_14 (KERN_ERR SFX L_61 , pci_name(pci)) ;
F_198 ( V_24 ) ;
return - V_355 ;
}
F_249 ( & V_2 -> V_26 ) ;
F_250 ( & V_2 -> V_272 ) ;
V_2 -> V_222 = V_222 ;
V_2 -> V_24 = V_24 ;
V_2 -> V_78 = - 1 ;
V_2 -> V_47 = V_47 ;
V_2 -> V_225 = V_47 & 0xff ;
F_245 ( V_2 ) ;
V_2 -> V_173 = V_9 ;
F_251 ( & V_2 -> V_151 , F_163 ) ;
F_252 ( & V_2 -> V_361 ) ;
F_252 ( & V_2 -> V_348 ) ;
F_223 ( V_2 ) ;
F_253 ( & V_2 -> V_397 ) ;
V_2 -> V_188 [ 0 ] = V_2 -> V_188 [ 1 ] =
F_242 ( V_2 , V_188 [ V_9 ] ) ;
if ( V_2 -> V_188 [ 0 ] == V_419 ) {
V_2 -> V_188 [ 0 ] = V_189 ;
V_2 -> V_188 [ 1 ] = V_335 ;
}
F_244 ( V_2 , V_9 ) ;
V_2 -> V_84 = V_84 ;
V_2 -> V_135 = V_441 ;
F_246 ( V_2 ) ;
if ( V_172 [ V_9 ] < 0 ) {
switch ( V_2 -> V_225 ) {
case V_442 :
case V_443 :
V_172 [ V_9 ] = 1 ;
break;
default:
V_172 [ V_9 ] = 32 ;
break;
}
}
V_22 = F_254 ( V_222 , V_444 , V_2 , & V_207 ) ;
if ( V_22 < 0 ) {
F_14 (KERN_ERR SFX L_62 ,
pci_name(chip->pci)) ;
F_228 ( V_2 ) ;
return V_22 ;
}
#ifdef F_255
F_251 ( & V_2 -> V_437 , F_247 ) ;
#endif
* V_438 = V_2 ;
return 0 ;
}
static int F_256 ( struct V_1 * V_2 )
{
int V_9 = V_2 -> V_173 ;
struct V_119 * V_24 = V_2 -> V_24 ;
struct V_382 * V_222 = V_2 -> V_222 ;
int V_103 , V_22 ;
unsigned short V_445 ;
#if V_446 != 64
if ( V_2 -> V_225 == V_447 ) {
T_7 V_448 ;
F_72 ( V_24 , 0x40 , & V_448 ) ;
F_73 ( V_24 , 0x40 , V_448 | 0x10 ) ;
F_257 ( V_24 , V_449 , 0 ) ;
}
#endif
V_22 = F_258 ( V_24 , L_63 ) ;
if ( V_22 < 0 )
return V_22 ;
V_2 -> V_404 = 1 ;
V_2 -> V_28 = F_259 ( V_24 , 0 ) ;
V_2 -> V_329 = F_260 ( V_24 , 0 ) ;
if ( V_2 -> V_329 == NULL ) {
F_14 (KERN_ERR SFX L_64 , pci_name(chip->pci)) ;
return - V_234 ;
}
if ( V_2 -> V_77 )
if ( F_206 ( V_24 ) < 0 )
V_2 -> V_77 = 0 ;
if ( F_44 ( V_2 , 0 ) < 0 )
return - V_98 ;
F_205 ( V_24 ) ;
F_261 ( V_2 -> V_78 ) ;
V_445 = F_27 ( V_2 , V_450 ) ;
F_40 ( V_75 L_65 , F_41 ( V_2 -> V_24 ) , V_445 ) ;
if ( V_2 -> V_24 -> V_408 == V_409 ) {
struct V_119 * V_451 ;
V_451 = F_262 ( V_409 ,
V_452 ,
NULL ) ;
if ( V_451 ) {
if ( V_451 -> V_434 < 0x30 )
V_445 &= ~ V_453 ;
F_225 ( V_451 ) ;
}
}
if ( V_2 -> V_47 & V_454 ) {
F_48 ( V_75 L_66 , F_41 ( V_2 -> V_24 ) ) ;
V_445 &= ~ V_453 ;
}
if ( V_281 >= 0 )
V_2 -> V_281 = ! ! V_281 ;
else {
if ( V_2 -> V_47 & V_455 )
V_2 -> V_281 = 0 ;
else if ( V_2 -> V_47 & V_456 )
V_2 -> V_281 = 1 ;
else
V_2 -> V_281 = 1 ;
}
if ( ( V_445 & V_453 ) && ! F_263 ( V_24 , F_264 ( 64 ) ) )
F_265 ( V_24 , F_264 ( 64 ) ) ;
else {
F_263 ( V_24 , F_264 ( 32 ) ) ;
F_265 ( V_24 , F_264 ( 32 ) ) ;
}
V_2 -> V_244 = ( V_445 >> 8 ) & 0x0f ;
V_2 -> V_242 = ( V_445 >> 12 ) & 0x0f ;
if ( ! V_2 -> V_242 && ! V_2 -> V_244 ) {
switch ( V_2 -> V_225 ) {
case V_447 :
V_2 -> V_242 = V_457 ;
V_2 -> V_244 = V_458 ;
break;
case V_459 :
case V_435 :
V_2 -> V_242 = V_460 ;
V_2 -> V_244 = V_461 ;
break;
case V_462 :
default:
V_2 -> V_242 = V_463 ;
V_2 -> V_244 = V_464 ;
break;
}
}
V_2 -> V_243 = 0 ;
V_2 -> V_241 = V_2 -> V_244 ;
V_2 -> V_104 = V_2 -> V_242 + V_2 -> V_244 ;
V_2 -> V_18 = F_266 ( V_2 -> V_104 , sizeof( * V_2 -> V_18 ) ,
V_354 ) ;
if ( ! V_2 -> V_18 ) {
F_14 (KERN_ERR SFX L_67 , pci_name(chip->pci)) ;
return - V_355 ;
}
for ( V_103 = 0 ; V_103 < V_2 -> V_104 ; V_103 ++ ) {
F_267 ( & V_2 -> V_18 [ V_103 ] ) ;
V_22 = F_12 ( V_23 ,
F_13 ( V_2 -> V_24 ) ,
V_465 , & V_2 -> V_18 [ V_103 ] . V_159 ) ;
if ( V_22 < 0 ) {
F_14 (KERN_ERR SFX L_68 , pci_name(chip->pci)) ;
return - V_355 ;
}
F_8 ( V_2 , & V_2 -> V_18 [ V_103 ] . V_159 , true ) ;
}
V_22 = F_12 ( V_23 ,
F_13 ( V_2 -> V_24 ) ,
V_2 -> V_104 * 8 , & V_2 -> V_117 ) ;
if ( V_22 < 0 ) {
F_14 (KERN_ERR SFX L_69 , pci_name(chip->pci)) ;
return - V_355 ;
}
F_8 ( V_2 , & V_2 -> V_117 , true ) ;
V_22 = F_11 ( V_2 ) ;
if ( V_22 < 0 )
return V_22 ;
F_179 ( V_2 ) ;
F_71 ( V_2 ) ;
F_67 ( V_2 , ( V_466 [ V_9 ] & 2 ) == 0 ) ;
if ( ! V_2 -> V_99 ) {
F_14 (KERN_ERR SFX L_70 , pci_name(chip->pci)) ;
return - V_467 ;
}
strcpy ( V_222 -> V_468 , L_71 ) ;
F_172 ( V_222 -> V_469 , V_470 [ V_2 -> V_225 ] ,
sizeof( V_222 -> V_469 ) ) ;
snprintf ( V_222 -> V_471 , sizeof( V_222 -> V_471 ) ,
L_72 ,
V_222 -> V_469 , V_2 -> V_28 , V_2 -> V_78 ) ;
return 0 ;
}
static void F_268 ( struct V_1 * V_2 )
{
#ifdef F_96
struct V_230 * V_231 ;
F_97 (codec, &chip->bus->codec_list, list) {
F_131 ( V_231 ) ;
}
#endif
}
static void F_269 ( const struct V_472 * V_405 , void * V_473 )
{
struct V_382 * V_222 = V_473 ;
struct V_1 * V_2 = V_222 -> V_13 ;
struct V_119 * V_24 = V_2 -> V_24 ;
if ( ! V_405 ) {
F_14 (KERN_ERR SFX L_73 ,
pci_name(chip->pci)) ;
goto error;
}
V_2 -> V_405 = V_405 ;
if ( ! V_2 -> V_92 ) {
if ( F_219 ( V_2 ) )
goto error;
}
return;
error:
F_270 ( V_222 ) ;
F_271 ( V_24 , NULL ) ;
}
static int F_272 ( struct V_119 * V_24 ,
const struct V_474 * V_475 )
{
static int V_9 ;
struct V_382 * V_222 ;
struct V_1 * V_2 ;
bool V_476 ;
int V_22 ;
if ( V_9 >= V_477 )
return - V_467 ;
if ( ! V_478 [ V_9 ] ) {
V_9 ++ ;
return - V_479 ;
}
V_22 = F_273 ( V_113 [ V_9 ] , V_480 [ V_9 ] , V_481 , 0 , & V_222 ) ;
if ( V_22 < 0 ) {
F_14 ( V_83 L_74 ) ;
return V_22 ;
}
F_274 ( V_222 , & V_24 -> V_9 ) ;
V_22 = F_248 ( V_222 , V_24 , V_9 , V_475 -> V_482 , & V_2 ) ;
if ( V_22 < 0 )
goto V_483;
V_222 -> V_13 = V_2 ;
F_271 ( V_24 , V_222 ) ;
V_22 = F_226 ( V_2 ) ;
if ( V_22 < 0 ) {
F_14 (KERN_ERR SFX
L_75 , pci_name(pci)) ;
goto V_483;
}
if ( F_240 ( V_24 ) ) {
F_14 (KERN_INFO SFX L_76 ,
pci_name(pci)) ;
F_14 (KERN_INFO SFX L_77 , pci_name(pci)) ;
V_2 -> V_92 = true ;
}
V_476 = ! V_2 -> V_92 ;
#ifdef F_234
if ( V_484 [ V_9 ] && * V_484 [ V_9 ] ) {
F_14 (KERN_ERR SFX L_78 ,
pci_name(pci), patch[dev]) ;
V_22 = F_275 ( V_481 , true , V_484 [ V_9 ] ,
& V_24 -> V_9 , V_354 , V_222 ,
F_269 ) ;
if ( V_22 < 0 )
goto V_483;
V_476 = false ;
}
#endif
if ( V_476 && ( V_2 -> V_47 & V_385 ) ) {
#ifdef F_255
V_476 = false ;
F_276 ( & V_2 -> V_437 ) ;
#else
F_14 (KERN_ERR SFX L_79 ) ;
#endif
}
if ( V_476 ) {
V_22 = F_219 ( V_2 ) ;
if ( V_22 < 0 )
goto V_483;
}
V_9 ++ ;
F_230 ( & V_2 -> V_397 ) ;
return 0 ;
V_483:
F_270 ( V_222 ) ;
return V_22 ;
}
static int F_219 ( struct V_1 * V_2 )
{
struct V_119 * V_24 = V_2 -> V_24 ;
int V_9 = V_2 -> V_173 ;
int V_22 ;
if ( V_2 -> V_47 & V_385 ) {
V_22 = F_277 () ;
if ( V_22 < 0 ) {
F_14 (KERN_ERR SFX L_80 ) ;
goto V_483;
}
F_201 ( true ) ;
}
V_22 = F_256 ( V_2 ) ;
if ( V_22 < 0 )
goto V_483;
#ifdef F_278
V_2 -> V_233 = V_233 [ V_9 ] ;
#endif
V_22 = F_102 ( V_2 , V_200 [ V_9 ] ) ;
if ( V_22 < 0 )
goto V_483;
#ifdef F_234
if ( V_2 -> V_405 ) {
V_22 = F_279 ( V_2 -> V_57 , V_2 -> V_405 -> V_157 ,
V_2 -> V_405 -> V_122 ) ;
if ( V_22 < 0 )
goto V_483;
#ifndef F_96
F_235 ( V_2 -> V_405 ) ;
V_2 -> V_405 = NULL ;
#endif
}
#endif
if ( ( V_466 [ V_9 ] & 1 ) == 0 ) {
V_22 = F_106 ( V_2 ) ;
if ( V_22 < 0 )
goto V_483;
}
V_22 = F_280 ( V_2 -> V_57 ) ;
if ( V_22 < 0 )
goto V_483;
V_22 = F_177 ( V_2 ) ;
if ( V_22 < 0 )
goto V_483;
V_22 = F_281 ( V_2 -> V_222 ) ;
if ( V_22 < 0 )
goto V_483;
V_2 -> V_147 = 1 ;
F_268 ( V_2 ) ;
F_212 ( V_2 ) ;
F_187 ( V_2 ) ;
if ( V_2 -> V_47 & V_376 )
F_282 ( & V_24 -> V_9 ) ;
return 0 ;
V_483:
V_2 -> V_398 = 1 ;
return V_22 ;
}
static void F_283 ( struct V_119 * V_24 )
{
struct V_382 * V_222 = F_217 ( V_24 ) ;
if ( V_222 )
F_270 ( V_222 ) ;
}
