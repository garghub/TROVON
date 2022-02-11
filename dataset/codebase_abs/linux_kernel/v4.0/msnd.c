void F_1 ( void * V_1 , int V_2 , int V_3 )
{
F_2 ( F_3 ( V_2 ) , V_1 + V_4 ) ;
F_2 ( F_4 ( V_3 ) - 1 , V_1 + V_5 ) ;
F_2 ( 0 , V_1 + V_6 ) ;
F_2 ( 0 , V_1 + V_7 ) ;
}
static int F_5 ( struct V_8 * V_9 )
{
unsigned int V_10 = V_9 -> V_10 ;
int V_11 = 1000 ;
while ( V_11 -- > 0 )
if ( F_6 ( V_10 + V_12 ) & V_13 )
return 0 ;
return - V_14 ;
}
static int F_7 ( struct V_8 * V_9 )
{
unsigned int V_10 = V_9 -> V_10 ;
int V_11 = 1000 ;
while ( V_11 -- > 0 )
if ( ! ( F_6 ( V_10 + V_15 ) & V_16 ) )
return 0 ;
return - V_14 ;
}
int F_8 ( struct V_8 * V_9 , T_1 V_17 )
{
unsigned long V_18 ;
F_9 ( & V_9 -> V_19 , V_18 ) ;
if ( F_7 ( V_9 ) == 0 ) {
F_10 ( V_17 , V_9 -> V_10 + V_15 ) ;
F_11 ( & V_9 -> V_19 , V_18 ) ;
return 0 ;
}
F_11 ( & V_9 -> V_19 , V_18 ) ;
F_12 (KERN_ERR LOGNAME L_1 ) ;
return - V_14 ;
}
int F_13 ( struct V_8 * V_9 , unsigned char V_20 ,
unsigned char V_21 , unsigned char V_22 )
{
unsigned int V_10 = V_9 -> V_10 ;
if ( F_5 ( V_9 ) == 0 ) {
F_10 ( V_20 , V_10 + V_23 ) ;
F_10 ( V_21 , V_10 + V_24 ) ;
F_10 ( V_22 , V_10 + V_25 ) ;
return 0 ;
}
F_12 (KERN_ERR LOGNAME L_2 ) ;
return - V_14 ;
}
int F_14 ( struct V_8 * V_9 , const T_1 * V_26 , int V_27 )
{
int V_28 ;
if ( V_27 % 3 != 0 ) {
F_15 (KERN_ERR LOGNAME
L_3 ) ;
return - V_29 ;
}
for ( V_28 = 0 ; V_28 < V_27 ; V_28 += 3 )
if ( F_13 ( V_9 , V_26 [ V_28 ] , V_26 [ V_28 + 1 ] , V_26 [ V_28 + 2 ] ) )
return - V_14 ;
F_6 ( V_9 -> V_10 + V_30 ) ;
F_6 ( V_9 -> V_10 + V_15 ) ;
return 0 ;
}
int F_16 ( struct V_8 * V_9 )
{
unsigned long V_18 ;
if ( V_9 -> V_31 ++ )
return 0 ;
F_17 ( V_32 L_4 ) ;
F_9 ( & V_9 -> V_19 , V_18 ) ;
if ( F_5 ( V_9 ) == 0 ) {
F_10 ( F_6 ( V_9 -> V_10 + V_33 ) | V_34 , V_9 -> V_10 + V_33 ) ;
if ( V_9 -> type == V_35 )
F_10 ( V_9 -> V_36 , V_9 -> V_10 + V_37 ) ;
F_10 ( F_6 ( V_9 -> V_10 + V_33 ) & ~ V_34 , V_9 -> V_10 + V_33 ) ;
F_10 ( F_6 ( V_9 -> V_10 + V_33 ) | V_38 , V_9 -> V_10 + V_33 ) ;
F_18 ( V_9 -> V_39 ) ;
F_1 ( V_9 -> V_40 , V_9 -> V_41 ,
V_9 -> V_42 ) ;
F_11 ( & V_9 -> V_19 , V_18 ) ;
return 0 ;
}
F_11 ( & V_9 -> V_19 , V_18 ) ;
F_12 (KERN_ERR LOGNAME L_5 ) ;
return - V_14 ;
}
int F_19 ( struct V_8 * V_9 )
{
unsigned long V_18 ;
if ( -- V_9 -> V_31 > 0 )
return 0 ;
if ( V_9 -> V_31 < 0 )
F_12 (KERN_WARNING LOGNAME L_6 ,
dev->irq_ref) ;
F_17 ( V_32 L_7 ) ;
F_9 ( & V_9 -> V_19 , V_18 ) ;
if ( F_5 ( V_9 ) == 0 ) {
F_10 ( F_6 ( V_9 -> V_10 + V_33 ) & ~ V_38 , V_9 -> V_10 + V_33 ) ;
if ( V_9 -> type == V_35 )
F_10 ( V_43 , V_9 -> V_10 + V_37 ) ;
F_20 ( V_9 -> V_39 ) ;
F_11 ( & V_9 -> V_19 , V_18 ) ;
return 0 ;
}
F_11 ( & V_9 -> V_19 , V_18 ) ;
F_12 (KERN_ERR LOGNAME L_8 ) ;
return - V_14 ;
}
static inline long F_21 ( struct V_8 * V_44 , long V_3 )
{
long V_45 = ( V_3 * V_46 * V_44 -> V_47 ) / 8 ;
return V_45 / ( V_44 -> V_48 * V_44 -> V_49 ) ;
}
static void F_22 ( struct V_8 * V_44 )
{
if ( ! ( V_44 -> V_50 & V_51 ) || ! F_23 ( V_52 , & V_44 -> V_18 ) )
return;
F_24 ( V_53 , & V_44 -> V_18 ) ;
F_25 ( V_53 , & V_44 -> V_18 ) ;
if ( ! F_26 ( V_54 ) )
F_27 (
F_21 ( V_44 , V_44 -> V_55 ) ) ;
F_25 ( V_52 , & V_44 -> V_18 ) ;
}
void F_28 ( struct V_8 * V_44 , struct V_56 * V_56 )
{
if ( ( V_56 ? V_56 -> V_57 : V_44 -> V_50 ) & V_58 ) {
F_25 ( V_59 , & V_44 -> V_18 ) ;
F_8 ( V_44 , V_60 ) ;
F_19 ( V_44 ) ;
if ( V_56 ) {
F_12 (KERN_INFO LOGNAME
L_9 , file) ;
V_44 -> V_50 &= ~ V_58 ;
}
F_25 ( V_61 , & V_44 -> V_18 ) ;
}
if ( ( V_56 ? V_56 -> V_57 : V_44 -> V_50 ) & V_51 ) {
if ( F_23 ( V_52 , & V_44 -> V_18 ) ) {
F_22 ( V_44 ) ;
F_8 ( V_44 , V_62 ) ;
}
F_19 ( V_44 ) ;
if ( V_56 ) {
F_12 (KERN_INFO
LOGNAME L_10 , file) ;
V_44 -> V_50 &= ~ V_51 ;
}
F_25 ( V_63 , & V_44 -> V_18 ) ;
}
}
int F_29 ( struct V_8 * V_44 , int V_64 )
{
int V_11 = 3 ;
T_2 V_65 ;
V_65 = F_30 ( V_44 -> V_66 + V_7 ) + F_4 ( V_67 ) ;
if ( V_65 > F_30 ( V_44 -> V_66 + V_5 ) )
V_65 = 0 ;
while ( V_65 == F_30 ( V_44 -> V_66 + V_6 ) && V_11 -- )
F_31 ( 1 ) ;
if ( V_44 -> V_68 == 2 ) {
void * V_69 = V_44 -> V_70 + V_71 +
V_64 * V_67 + V_72 ;
unsigned short V_73 = 0x3000 + V_44 -> V_74 ;
if ( F_30 ( V_69 ) != F_3 ( 0x3000 ) )
V_73 = 0x3000 ;
F_2 ( F_3 ( V_73 ) , V_69 ) ;
}
F_2 ( V_65 , V_44 -> V_66 + V_7 ) ;
#if 0
DAQD = bank * DAQDS__size + chip->mappedbase + DARQ_DATA_BUFF;
size = readw(DAQD + DAQDS_wSize);
outb(HPBLKSEL_1, chip->io + HP_BLKS);
n = msnd_fifo_write(&chip->DARF,
(char *)(chip->base + bank * DAR_BUFF_SIZE),
size, 0);
if (n <= 0) {
outb(HPBLKSEL_0, chip->io + HP_BLKS);
return n;
}
outb(HPBLKSEL_0, chip->io + HP_BLKS);
#endif
return 1 ;
}
int F_32 ( struct V_8 * V_44 , int V_2 )
{
T_2 V_75 ;
int V_76 = V_2 , V_77 = 0 ;
void * V_78 ;
static int V_79 ;
V_75 = F_30 ( V_44 -> V_80 + V_7 ) ;
while ( V_75 != F_30 ( V_44 -> V_80 + V_6 ) || V_2 ) {
int V_81 = V_75 / F_4 ( V_67 ) ;
if ( V_2 ) {
V_2 = 0 ;
V_79 = 0 ;
}
V_78 = V_81 * V_67 + V_44 -> V_70 +
V_82 ;
F_2 ( V_44 -> V_55 , V_78 + V_83 ) ;
if ( V_79 < 3 )
++ V_79 ;
else if ( V_44 -> V_84 == 2 ) {
unsigned short V_73 = V_44 -> V_55 ;
if ( F_30 ( V_78 + V_72 ) != F_3 ( 0x0 ) )
V_73 = 0 ;
F_2 ( F_3 ( V_73 ) , V_78 + V_72 ) ;
}
++ V_77 ;
V_75 = ( ++ V_81 % 3 ) * F_4 ( V_67 ) ;
F_2 ( V_75 , V_44 -> V_80 + V_7 ) ;
F_8 ( V_44 , V_85 ) ;
if ( V_76 )
if ( 2 == V_81 )
break;
}
return V_77 ;
}
static void F_33 ( struct V_8 * V_44 ,
unsigned int V_86 ,
unsigned int V_87 )
{
int V_88 ;
void * V_69 = V_44 -> V_70 + V_82 ;
V_44 -> V_89 = - 1 ;
V_44 -> V_90 = V_87 * ( V_86 - 1 ) ;
V_44 -> V_84 = V_86 ;
F_2 ( F_4 ( 0 * V_67 ) , V_44 -> V_80 + V_6 ) ;
F_2 ( F_4 ( 0 * V_67 ) , V_44 -> V_80 + V_7 ) ;
V_44 -> V_55 = V_87 ;
for ( V_88 = 0 ; V_88 < V_86 ; ++ V_88 , V_69 += V_67 ) {
F_2 ( F_3 ( ( V_91 ) ( V_87 * V_88 ) ) ,
V_69 + V_72 ) ;
F_2 ( 0 , V_69 + V_83 ) ;
F_2 ( 1 , V_69 + V_92 ) ;
F_2 ( V_44 -> V_47 , V_69 + V_93 ) ;
F_2 ( V_44 -> V_49 , V_69 + V_94 ) ;
F_2 ( V_44 -> V_48 , V_69 + V_95 ) ;
F_2 ( V_96 * 0x100 + V_88 , V_69 + V_97 ) ;
F_2 ( V_88 , V_69 + V_98 ) ;
}
}
static void F_34 ( struct V_8 * V_44 ,
unsigned int V_86 ,
unsigned int V_87 )
{
int V_88 ;
void * V_69 ;
V_44 -> V_99 = 2 ;
V_44 -> V_100 = V_87 * ( V_86 - 1 ) ;
V_44 -> V_68 = V_86 ;
F_2 ( F_4 ( 0 * V_67 ) , V_44 -> V_66 + V_6 ) ;
F_2 ( F_4 ( V_44 -> V_99 * V_67 ) ,
V_44 -> V_66 + V_7 ) ;
#if 0
spin_lock_irqsave(&chip->lock, flags);
outb(HPBLKSEL_1, chip->io + HP_BLKS);
memset_io(chip->mappedbase, 0, DAR_BUFF_SIZE * 3);
outb(HPBLKSEL_0, chip->io + HP_BLKS);
spin_unlock_irqrestore(&chip->lock, flags);
#endif
V_44 -> V_74 = V_87 ;
F_17 ( L_11 , V_87 ) ;
V_69 = V_44 -> V_70 + V_71 ;
for ( V_88 = 0 ; V_88 < V_86 ; ++ V_88 , V_69 += V_67 ) {
V_91 V_45 = V_87 * V_88 ;
F_2 ( F_3 ( V_45 + 0x3000 ) , V_69 + V_72 ) ;
F_2 ( V_87 , V_69 + V_83 ) ;
F_2 ( 1 , V_69 + V_92 ) ;
F_2 ( V_44 -> V_101 , V_69 + V_93 ) ;
F_2 ( V_44 -> V_102 , V_69 + V_94 ) ;
F_2 ( V_44 -> V_103 , V_69 + V_95 ) ;
F_2 ( V_104 * 0x100 + V_88 , V_69 + V_97 ) ;
F_2 ( V_88 , V_69 + V_98 ) ;
}
}
static int F_35 ( struct V_105 * V_106 )
{
struct V_107 * V_108 = V_106 -> V_108 ;
struct V_8 * V_44 = F_36 ( V_106 ) ;
F_24 ( V_63 , & V_44 -> V_18 ) ;
F_25 ( V_52 , & V_44 -> V_18 ) ;
F_16 ( V_44 ) ;
V_108 -> V_109 = V_44 -> V_70 ;
V_108 -> V_110 = 0x3000 ;
V_44 -> V_111 = V_106 ;
V_108 -> V_112 = V_113 ;
return 0 ;
}
static int F_37 ( struct V_105 * V_106 )
{
struct V_8 * V_44 = F_36 ( V_106 ) ;
F_19 ( V_44 ) ;
F_25 ( V_63 , & V_44 -> V_18 ) ;
return 0 ;
}
static int F_38 ( struct V_105 * V_106 ,
struct V_114 * V_115 )
{
int V_28 ;
struct V_8 * V_44 = F_36 ( V_106 ) ;
void * V_69 = V_44 -> V_70 + V_82 ;
V_44 -> V_47 = F_39 ( F_40 ( V_115 ) ) ;
V_44 -> V_49 = F_41 ( V_115 ) ;
V_44 -> V_48 = F_42 ( V_115 ) ;
for ( V_28 = 0 ; V_28 < 3 ; ++ V_28 , V_69 += V_67 ) {
F_2 ( V_44 -> V_47 , V_69 + V_93 ) ;
F_2 ( V_44 -> V_49 , V_69 + V_94 ) ;
F_2 ( V_44 -> V_48 , V_69 + V_95 ) ;
}
return 0 ;
}
static int F_43 ( struct V_105 * V_106 )
{
struct V_8 * V_44 = F_36 ( V_106 ) ;
unsigned int V_116 = F_44 ( V_106 ) ;
unsigned int V_87 = F_45 ( V_106 ) ;
unsigned int V_86 = V_116 / V_87 ;
F_33 ( V_44 , V_86 , V_87 ) ;
V_44 -> V_117 = 0 ;
return 0 ;
}
static int F_46 ( struct V_105 * V_106 ,
int V_17 )
{
struct V_8 * V_44 = F_36 ( V_106 ) ;
int V_118 = 0 ;
if ( V_17 == V_119 ) {
F_17 ( L_12 ) ;
V_44 -> V_120 = 0 ;
F_24 ( V_52 , & V_44 -> V_18 ) ;
F_32 ( V_44 , 1 ) ;
} else if ( V_17 == V_121 ) {
F_17 ( L_13 ) ;
F_25 ( V_52 , & V_44 -> V_18 ) ;
F_8 ( V_44 , V_62 ) ;
} else {
F_12 ( V_122 L_14 ) ;
V_118 = - V_29 ;
}
F_17 ( L_15 ) ;
return V_118 ;
}
static T_3
F_47 ( struct V_105 * V_106 )
{
struct V_8 * V_44 = F_36 ( V_106 ) ;
return F_48 ( V_106 -> V_108 , V_44 -> V_117 ) ;
}
static int F_49 ( struct V_105 * V_106 )
{
struct V_107 * V_108 = V_106 -> V_108 ;
struct V_8 * V_44 = F_36 ( V_106 ) ;
F_24 ( V_61 , & V_44 -> V_18 ) ;
F_16 ( V_44 ) ;
V_108 -> V_109 = V_44 -> V_70 + 0x3000 ;
V_108 -> V_110 = 0x3000 ;
memset ( V_108 -> V_109 , 0 , V_108 -> V_110 ) ;
V_44 -> V_123 = V_106 ;
V_108 -> V_112 = V_124 ;
return 0 ;
}
static int F_50 ( struct V_105 * V_106 )
{
struct V_8 * V_44 = F_36 ( V_106 ) ;
F_19 ( V_44 ) ;
F_25 ( V_61 , & V_44 -> V_18 ) ;
return 0 ;
}
static int F_51 ( struct V_105 * V_106 )
{
struct V_8 * V_44 = F_36 ( V_106 ) ;
unsigned int V_116 = F_44 ( V_106 ) ;
unsigned int V_87 = F_45 ( V_106 ) ;
unsigned int V_86 = V_116 / V_87 ;
F_34 ( V_44 , V_86 , V_87 ) ;
V_44 -> V_125 = 0 ;
return 0 ;
}
static int F_52 ( struct V_105 * V_106 ,
int V_17 )
{
struct V_8 * V_44 = F_36 ( V_106 ) ;
if ( V_17 == V_119 ) {
V_44 -> V_99 = - 1 ;
F_24 ( V_59 , & V_44 -> V_18 ) ;
if ( F_8 ( V_44 , V_126 ) == 0 )
return 0 ;
F_25 ( V_59 , & V_44 -> V_18 ) ;
} else if ( V_17 == V_121 ) {
F_25 ( V_59 , & V_44 -> V_18 ) ;
F_8 ( V_44 , V_60 ) ;
return 0 ;
}
return - V_29 ;
}
static T_3
F_53 ( struct V_105 * V_106 )
{
struct V_107 * V_108 = V_106 -> V_108 ;
struct V_8 * V_44 = F_36 ( V_106 ) ;
return F_48 ( V_108 , V_44 -> V_125 ) ;
}
static int F_54 ( struct V_105 * V_106 ,
struct V_114 * V_115 )
{
int V_28 ;
struct V_8 * V_44 = F_36 ( V_106 ) ;
void * V_69 = V_44 -> V_70 + V_71 ;
V_44 -> V_101 = F_39 ( F_40 ( V_115 ) ) ;
V_44 -> V_102 = F_41 ( V_115 ) ;
V_44 -> V_103 = F_42 ( V_115 ) ;
for ( V_28 = 0 ; V_28 < 3 ; ++ V_28 , V_69 += V_67 ) {
F_2 ( V_44 -> V_101 , V_69 + V_93 ) ;
F_2 ( V_44 -> V_102 , V_69 + V_94 ) ;
F_2 ( V_44 -> V_103 , V_69 + V_95 ) ;
}
return 0 ;
}
int F_55 ( struct V_127 * V_128 , int V_129 )
{
struct V_8 * V_44 = V_128 -> V_130 ;
struct V_131 * V_132 ;
int V_133 ;
V_133 = F_56 ( V_128 , L_16 , V_129 , 1 , 1 , & V_132 ) ;
if ( V_133 < 0 )
return V_133 ;
F_57 ( V_132 , V_134 , & V_135 ) ;
F_57 ( V_132 , V_136 , & V_137 ) ;
V_132 -> V_130 = V_44 ;
strcpy ( V_132 -> V_138 , L_17 ) ;
return 0 ;
}
