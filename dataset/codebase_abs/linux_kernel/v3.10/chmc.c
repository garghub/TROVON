static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_3 ( V_2 , & V_4 ) ;
F_4 ( & V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_6 ( V_2 ) ;
F_4 ( & V_3 ) ;
}
static int F_7 ( int V_5 )
{
if ( V_5 < 128 )
V_5 += 16 ;
else if ( V_5 < 128 + 9 )
V_5 -= ( 128 - 7 ) ;
else if ( V_5 < ( 128 + 9 + 3 ) )
V_5 -= ( 128 + 9 - 4 ) ;
else
V_5 -= ( 128 + 9 + 3 ) ;
return V_5 ;
}
static void F_8 ( int V_5 , unsigned long V_6 ,
int * V_7 , char * * V_8 , void * V_9 ,
int V_10 )
{
int V_11 = F_7 ( V_5 ) ;
int V_12 ;
int V_13 ;
int V_14 ;
int V_15 ;
if ( V_16 == V_17 ) {
struct V_18 * V_19 = V_9 ;
V_12 = V_11 ;
V_13 = ( V_20 - V_12 ) ;
V_14 = V_13 / 8 ;
V_15 = V_19 -> V_21 . V_22 [ V_14 ] ;
V_15 = ( ( V_15 >> ( ( 7 - ( V_13 & 7 ) ) ) ) & 1 ) ;
* V_8 = V_19 -> V_23 [ V_10 + V_15 ] ;
* V_7 = V_19 -> V_21 . V_24 [ V_12 ] ;
} else {
struct V_25 * V_19 = V_9 ;
struct V_26 * V_27 ;
int V_28 ;
if ( V_19 -> V_29 )
V_27 = & V_19 -> V_21 [ 0 ] ;
else
V_27 = & V_19 -> V_21 [ 1 ] ;
V_28 = ( V_6 & V_30 ) / V_31 ;
V_12 = ( ( 3 - V_28 ) * V_32 ) + V_11 ;
V_13 = ( V_33 - V_12 ) ;
V_14 = V_13 >> 2 ;
V_15 = V_27 -> V_22 [ V_14 ] ;
V_15 = ( ( V_15 >> ( ( 3 - ( V_13 & 3 ) ) << 1 ) ) & 0x3 ) ;
* V_8 = V_19 -> V_23 [ V_10 + V_15 ] ;
* V_7 = V_27 -> V_24 [ V_12 ] ;
}
}
static struct V_34 * F_9 ( unsigned long V_35 )
{
struct V_36 * V_19 ;
F_10 (p, &mctrl_list, list) {
int V_37 ;
for ( V_37 = 0 ; V_37 < V_19 -> V_38 ; V_37 ++ ) {
struct V_34 * V_39 = & V_19 -> V_40 [ V_37 ] ;
if ( V_35 < V_39 -> V_41 ||
( V_39 -> V_41 + V_39 -> V_42 ) <= V_35 )
continue;
return V_39 ;
}
}
return NULL ;
}
static int F_11 ( int V_5 ,
unsigned long V_35 ,
char * V_43 , int V_44 )
{
struct V_18 * V_45 ;
struct V_34 * V_39 ;
struct V_36 * V_19 ;
int V_46 ;
V_39 = F_9 ( V_35 ) ;
if ( V_39 == NULL ||
V_5 < V_47 ||
V_5 > V_48 ) {
V_43 [ 0 ] = '?' ;
V_43 [ 1 ] = '?' ;
V_43 [ 2 ] = '?' ;
V_43 [ 3 ] = '\0' ;
return 0 ;
}
V_19 = V_39 -> V_49 ;
V_45 = & V_19 -> V_50 ;
V_46 = V_39 -> V_51 * V_52 ;
if ( V_5 != V_47 ) {
char * V_53 ;
int V_54 ;
F_8 ( V_5 , V_35 , & V_54 ,
& V_53 , V_45 , V_46 ) ;
sprintf ( V_43 , L_1 , V_53 , V_54 ) ;
} else {
int V_55 ;
for ( V_55 = 0 ; V_55 < V_52 ; V_55 ++ ) {
sprintf ( V_43 , L_2 ,
V_45 -> V_23 [ V_46 + V_55 ] ) ;
V_43 += strlen ( V_43 ) ;
}
}
return 0 ;
}
static T_1 F_12 ( T_1 V_56 ,
const struct V_57 * V_58 ,
int V_59 )
{
T_1 V_60 = V_56 + ( 8UL * 1024 * 1024 * 1024 ) ;
T_1 V_61 = V_56 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_59 ; V_37 ++ ) {
const struct V_57 * V_62 ;
T_1 V_63 ;
T_1 V_64 ;
V_62 = & V_58 [ V_37 ] ;
V_63 = V_62 -> V_35 ;
V_64 = V_63 + V_62 -> V_65 ;
if ( V_56 < V_63 || V_56 >= V_64 )
continue;
if ( V_64 > V_60 )
V_64 = V_60 ;
if ( V_64 > V_61 )
V_61 = V_64 ;
}
return V_61 - V_56 ;
}
static void F_13 ( struct V_36 * V_19 ,
unsigned long V_51 ,
const struct V_57 * V_58 ,
int V_59 )
{
struct V_34 * V_39 = & V_19 -> V_40 [ V_51 ] ;
V_39 -> V_49 = V_19 ;
V_39 -> V_51 = V_51 ;
V_39 -> V_41 = ( V_19 -> V_66 * ( 64UL * 1024 * 1024 * 1024 ) ) ;
V_39 -> V_41 += ( V_51 * ( 8UL * 1024 * 1024 * 1024 ) ) ;
V_39 -> V_42 = F_12 ( V_39 -> V_41 , V_58 , V_59 ) ;
}
static void F_14 ( struct V_36 * V_19 ,
const struct V_57 * V_58 ,
int V_59 )
{
if ( V_19 -> V_67 & V_68 ) {
F_13 ( V_19 , 0 , V_58 , V_59 ) ;
V_19 -> V_38 ++ ;
}
if ( V_19 -> V_67 & V_69 ) {
F_13 ( V_19 , 1 , V_58 , V_59 ) ;
V_19 -> V_38 ++ ;
}
}
static int F_15 ( struct V_70 * V_71 )
{
const struct V_57 * V_58 ;
struct V_72 * V_73 ;
int V_74 , V_75 , V_59 ;
struct V_36 * V_19 ;
const T_2 * V_45 ;
const void * V_76 ;
V_74 = - V_77 ;
V_73 = F_16 ( L_3 ) ;
if ( ! V_73 ) {
F_17 (KERN_ERR PFX L_4 ) ;
goto V_78;
}
V_58 = F_18 ( V_73 , L_5 , & V_75 ) ;
if ( ! V_58 ) {
F_17 (KERN_ERR PFX L_6 ) ;
goto V_78;
}
V_59 = V_75 / sizeof( * V_58 ) ;
V_74 = - V_79 ;
V_19 = F_19 ( sizeof( * V_19 ) , V_80 ) ;
if ( ! V_19 ) {
F_17 (KERN_ERR PFX L_7 ) ;
goto V_78;
}
F_20 ( & V_19 -> V_2 ) ;
V_74 = - V_77 ;
V_45 = F_18 ( V_71 -> V_81 . V_82 , L_8 , & V_75 ) ;
if ( ! V_45 || V_75 != 4 ) {
F_17 (KERN_ERR PFX L_9 ) ;
goto V_83;
}
V_19 -> V_66 = * V_45 ;
V_45 = F_18 ( V_71 -> V_81 . V_82 , L_10 , & V_75 ) ;
if ( ! V_45 || V_75 != 8 ) {
F_17 (KERN_ERR PFX L_11 ) ;
goto V_83;
}
V_19 -> V_67 = ( ( T_1 ) V_45 [ 0 ] << 32 ) | ( T_1 ) V_45 [ 1 ] ;
V_74 = - V_79 ;
V_19 -> V_84 = F_21 ( & V_71 -> V_85 [ 0 ] , 0 , V_86 , L_12 ) ;
if ( ! V_19 -> V_84 ) {
F_17 (KERN_ERR PFX L_13 ) ;
goto V_83;
}
V_74 = - V_77 ;
V_76 = F_18 ( V_71 -> V_81 . V_82 , L_14 , & V_19 -> V_87 ) ;
if ( ! V_76 ) {
F_17 (KERN_ERR PFX L_15 ) ;
goto V_88;
}
if ( V_19 -> V_87 > sizeof( V_19 -> V_50 ) ) {
F_17 (KERN_ERR PFX L_16 ,
p->layout_len) ;
goto V_88;
}
memcpy ( & V_19 -> V_50 , V_76 , V_19 -> V_87 ) ;
F_14 ( V_19 , V_58 , V_59 ) ;
F_1 ( & V_19 -> V_2 ) ;
F_17 (KERN_INFO PFX L_17 ,
op->dev.of_node->full_name) ;
F_22 ( & V_71 -> V_81 , V_19 ) ;
V_74 = 0 ;
V_78:
return V_74 ;
V_88:
F_23 ( & V_71 -> V_85 [ 0 ] , V_19 -> V_84 , V_86 ) ;
V_83:
F_24 ( V_19 ) ;
goto V_78;
}
static int F_25 ( struct V_89 * V_90 , unsigned long V_35 )
{
unsigned long V_91 = ( V_35 & V_92 ) >> V_93 ;
unsigned long V_94 = ( V_35 & V_95 ) >> V_96 ;
if ( V_90 -> V_97 == 0 )
return 0 ;
V_91 ^= V_90 -> V_98 ;
V_91 = ~ V_91 ;
V_91 |= V_90 -> V_99 ;
V_91 = ~ V_91 ;
if ( V_91 )
return 0 ;
V_94 ^= V_90 -> V_100 ;
V_94 = ~ V_94 ;
V_94 |= V_90 -> V_101 ;
V_94 = ~ V_94 ;
if ( V_94 )
return 0 ;
return 1 ;
}
static struct V_89 * F_26 ( unsigned long V_35 )
{
struct V_102 * V_19 ;
F_10 (p, &mctrl_list, list) {
int V_103 ;
for ( V_103 = 0 ; V_103 < V_104 ; V_103 ++ ) {
struct V_89 * V_90 ;
V_90 = & V_19 -> V_105 [ V_103 ] ;
if ( F_25 ( V_90 , V_35 ) )
return V_90 ;
}
}
return NULL ;
}
static int F_27 ( int V_5 ,
unsigned long V_35 ,
char * V_43 , int V_44 )
{
struct V_89 * V_90 ;
struct V_25 * V_45 ;
int V_106 , V_46 ;
V_90 = F_26 ( V_35 ) ;
if ( V_90 == NULL ||
V_5 < V_47 ||
V_5 > V_48 ) {
V_43 [ 0 ] = '?' ;
V_43 [ 1 ] = '?' ;
V_43 [ 2 ] = '?' ;
V_43 [ 3 ] = '\0' ;
return 0 ;
}
V_45 = & V_90 -> V_19 -> V_107 ;
V_106 = V_90 -> V_108 & ( V_104 - 1 ) ;
V_46 = ( V_106 & ( V_109 - 1 ) ) ;
V_46 *= V_110 ;
if ( V_5 != V_47 ) {
char * V_53 ;
int V_54 ;
F_8 ( V_5 , V_35 , & V_54 ,
& V_53 , V_45 , V_46 ) ;
sprintf ( V_43 , L_1 , V_53 , V_54 ) ;
} else {
int V_55 ;
for ( V_55 = 0 ; V_55 < V_110 ; V_55 ++ ) {
sprintf ( V_43 , L_2 ,
V_45 -> V_23 [ V_46 + V_55 ] ) ;
V_43 += strlen ( V_43 ) ;
}
}
return 0 ;
}
static T_1 F_28 ( struct V_102 * V_19 , unsigned long V_111 )
{
unsigned long V_112 , V_113 ;
F_29 () ;
V_113 = F_30 () ;
if ( V_19 -> V_66 == V_113 ) {
__asm__ __volatile__("ldxa [%1] %2, %0"
: "=r" (ret)
: "r" (offset), "i" (ASI_MCU_CTRL_REG));
} else {
__asm__ __volatile__("ldxa [%1] %2, %0"
: "=r" (ret)
: "r" (p->regs + offset),
"i" (ASI_PHYS_BYPASS_EC_E));
}
F_31 () ;
return V_112 ;
}
static void F_32 ( struct V_102 * V_19 , int V_114 , T_1 V_115 )
{
struct V_89 * V_90 = & V_19 -> V_105 [ V_114 ] ;
V_90 -> V_19 = V_19 ;
V_90 -> V_108 = ( V_104 * V_19 -> V_66 ) + V_114 ;
V_90 -> V_116 = V_115 ;
V_90 -> V_97 = ( V_115 & V_117 ) >> V_118 ;
V_90 -> V_99 = ( V_115 & V_119 ) >> V_120 ;
V_90 -> V_98 = ( V_115 & V_121 ) >> V_122 ;
V_90 -> V_101 = ( V_115 & V_123 ) >> V_124 ;
V_90 -> V_100 = ( V_115 & V_125 ) >> V_126 ;
V_90 -> V_56 = ( V_90 -> V_98 ) ;
V_90 -> V_56 &= ~ ( V_90 -> V_99 ) ;
V_90 -> V_56 <<= V_93 ;
switch( V_90 -> V_101 ) {
case 0xf :
default:
V_90 -> V_127 = 1 ;
break;
case 0xe :
V_90 -> V_127 = 2 ;
break;
case 0xc :
V_90 -> V_127 = 4 ;
break;
case 0x8 :
V_90 -> V_127 = 8 ;
break;
case 0x0 :
V_90 -> V_127 = 16 ;
break;
}
V_90 -> V_42 = ( ( ( unsigned long ) V_90 -> V_99 &
( ( 1UL << 10UL ) - 1UL ) ) + 1UL ) << V_93 ;
V_90 -> V_42 /= V_90 -> V_127 ;
}
static void F_33 ( struct V_102 * V_19 )
{
if ( V_19 -> V_128 == 0 )
return;
F_32 ( V_19 , 0 ,
F_28 ( V_19 , V_129 ) ) ;
F_32 ( V_19 , 1 ,
F_28 ( V_19 , V_130 ) ) ;
F_32 ( V_19 , 2 ,
F_28 ( V_19 , V_131 ) ) ;
F_32 ( V_19 , 3 ,
F_28 ( V_19 , V_132 ) ) ;
}
static int F_34 ( struct V_70 * V_71 )
{
struct V_72 * V_39 = V_71 -> V_81 . V_82 ;
unsigned long V_133 ;
const void * V_134 ;
int V_75 , V_66 ;
struct V_102 * V_19 ;
int V_74 ;
V_74 = - V_77 ;
__asm__ ("rdpr %%ver, %0" : "=r" (ver));
if ( ( V_133 >> 32UL ) == V_135 ||
( V_133 >> 32UL ) == V_136 )
goto V_78;
V_66 = F_35 ( V_39 , L_8 , - 1 ) ;
if ( V_66 == - 1 )
goto V_78;
V_134 = F_18 ( V_39 , L_14 , & V_75 ) ;
if ( V_134 && V_75 > sizeof( V_19 -> V_107 ) ) {
F_17 (KERN_ERR PFX L_18
L_19 , len) ;
goto V_78;
}
V_74 = - V_79 ;
V_19 = F_19 ( sizeof( * V_19 ) , V_80 ) ;
if ( ! V_19 ) {
F_17 (KERN_ERR PFX L_20 ) ;
goto V_78;
}
V_19 -> V_66 = V_66 ;
V_19 -> V_128 = V_75 ;
if ( ! V_134 )
V_19 -> V_128 = 0 ;
else
memcpy ( & V_19 -> V_107 , V_134 , V_75 ) ;
V_19 -> V_84 = F_21 ( & V_71 -> V_85 [ 0 ] , 0 , 0x48 , L_21 ) ;
if ( ! V_19 -> V_84 ) {
F_17 (KERN_ERR PFX L_22 ) ;
goto V_83;
}
if ( V_19 -> V_128 != 0UL ) {
V_19 -> V_137 = F_28 ( V_19 , V_138 ) ;
V_19 -> V_139 = F_28 ( V_19 , V_140 ) ;
V_19 -> V_141 = F_28 ( V_19 , V_142 ) ;
V_19 -> V_143 = F_28 ( V_19 , V_144 ) ;
V_19 -> V_145 = F_28 ( V_19 , V_146 ) ;
}
F_33 ( V_19 ) ;
F_1 ( & V_19 -> V_2 ) ;
F_17 (KERN_INFO PFX L_23 ,
dp->full_name,
(p->layout_size ? L_24 : L_25)) ;
F_22 ( & V_71 -> V_81 , V_19 ) ;
V_74 = 0 ;
V_78:
return V_74 ;
V_83:
F_24 ( V_19 ) ;
goto V_78;
}
static int F_36 ( struct V_70 * V_71 )
{
if ( V_16 == V_147 )
return F_34 ( V_71 ) ;
else if ( V_16 == V_17 )
return F_15 ( V_71 ) ;
return - V_77 ;
}
static void F_37 ( struct V_70 * V_71 , struct V_102 * V_19 )
{
F_38 ( & V_19 -> V_2 ) ;
F_23 ( & V_71 -> V_85 [ 0 ] , V_19 -> V_84 , 0x48 ) ;
F_24 ( V_19 ) ;
}
static void F_39 ( struct V_70 * V_71 , struct V_36 * V_19 )
{
F_5 ( & V_19 -> V_2 ) ;
F_23 ( & V_71 -> V_85 [ 0 ] , V_19 -> V_84 , V_86 ) ;
F_24 ( V_19 ) ;
}
static int F_40 ( struct V_70 * V_71 )
{
void * V_19 = F_41 ( & V_71 -> V_81 ) ;
if ( V_19 ) {
if ( V_16 == V_147 )
F_37 ( V_71 , V_19 ) ;
else if ( V_16 == V_17 )
F_39 ( V_71 , V_19 ) ;
}
return 0 ;
}
static inline bool F_42 ( void )
{
if ( V_148 == V_149 || V_148 == V_150 )
return true ;
return false ;
}
static int T_3 F_43 ( void )
{
unsigned long V_133 ;
int V_112 ;
if ( ! F_42 () )
return - V_77 ;
__asm__ __volatile__("rdpr %%ver, %0" : "=r" (ver));
if ( ( V_133 >> 32UL ) == V_135 ||
( V_133 >> 32UL ) == V_136 ) {
V_16 = V_17 ;
V_151 = F_11 ;
} else {
V_16 = V_147 ;
V_151 = F_27 ;
}
V_112 = F_44 ( V_151 ) ;
if ( ! V_112 ) {
V_112 = F_45 ( & V_152 ) ;
if ( V_112 )
F_46 ( V_151 ) ;
}
return V_112 ;
}
static void T_4 F_47 ( void )
{
if ( F_42 () ) {
F_46 ( V_151 ) ;
F_48 ( & V_152 ) ;
}
}
