static inline unsigned long
F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void
F_3 ( struct V_1 * V_2 , unsigned V_3 , unsigned long V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void
F_5 ( struct V_1 * V_2 )
{
while ( F_1 ( V_2 , V_6 ) & V_7 ) ;
}
static inline void
F_6 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_8 , 1 ) ;
F_7 ( 50 ) ;
F_3 ( V_2 , V_8 , 0 ) ;
}
static void
F_8 ( struct V_1 * V_2 )
{
T_1 V_9 ;
F_5 ( V_2 ) ;
V_9 = F_1 ( V_2 , V_10 ) ;
V_9 &= ~ V_11 ;
F_3 ( V_2 , V_10 , V_9 ) ;
}
static void
F_9 ( struct V_1 * V_2 )
{
T_1 V_9 ;
F_5 ( V_2 ) ;
V_9 = F_1 ( V_2 , V_10 ) ;
V_9 |= V_11 ;
F_3 ( V_2 , V_10 , V_9 ) ;
}
static void
F_10 ( struct V_1 * V_2 )
{
unsigned long V_12 ;
F_11 ( & V_2 -> V_13 , V_12 ) ;
F_5 ( V_2 ) ;
F_3 ( V_2 , V_14 , V_15 ) ;
F_12 ( & V_2 -> V_13 , V_12 ) ;
}
static void
F_13 ( struct V_1 * V_2 )
{
unsigned long V_12 ;
F_11 ( & V_2 -> V_13 , V_12 ) ;
F_5 ( V_2 ) ;
F_3 ( V_2 , V_14 , V_2 -> V_16 . V_17 ) ;
F_12 ( & V_2 -> V_13 , V_12 ) ;
}
static void
F_14 ( struct V_1 * V_2 )
{
T_1 V_18 ;
unsigned long V_12 ;
F_11 ( & V_2 -> V_19 , V_12 ) ;
V_18 = ( V_7 |
( V_2 -> V_16 . V_20 << 6 ) |
( V_2 -> V_16 . V_21 << 5 ) |
( V_2 -> V_16 . V_22 ) ) ;
F_5 ( V_2 ) ;
F_3 ( V_2 , V_6 , V_18 ) ;
F_12 ( & V_2 -> V_19 , V_12 ) ;
}
static T_2
F_15 ( int V_23 , void * V_24 )
{
T_1 V_9 ;
struct V_1 * V_2 = V_24 ;
F_16 ( & V_2 -> V_19 ) ;
F_8 ( V_2 ) ;
F_5 ( V_2 ) ;
V_9 = F_1 ( V_2 , V_10 ) ;
F_17 ( & V_2 -> V_19 ) ;
if ( V_9 & V_25 ) {
if ( V_2 -> V_26 && V_2 -> V_16 . V_27 ) {
F_16 ( & V_2 -> V_19 ) ;
V_2 -> V_28 . V_29 += V_2 -> V_28 . V_30 ;
V_2 -> V_28 . V_29 %= V_2 -> V_28 . V_31 ;
F_3 ( V_2 , V_32 ,
V_2 -> V_28 . V_33 + V_2 -> V_28 . V_29 ) ;
V_2 -> V_34 . V_35 ++ ;
F_17 ( & V_2 -> V_19 ) ;
F_18 ( V_2 -> V_26 ) ;
} else {
F_16 ( & V_2 -> V_19 ) ;
F_3 ( V_2 , V_32 , V_2 -> V_36 . V_33 ) ;
V_2 -> V_34 . V_37 ++ ;
F_17 ( & V_2 -> V_19 ) ;
}
}
if ( V_9 & V_38 ) {
if ( V_2 -> V_39 && V_2 -> V_16 . V_40 ) {
F_16 ( & V_2 -> V_19 ) ;
V_2 -> V_41 . V_29 += V_2 -> V_41 . V_30 ;
V_2 -> V_41 . V_29 %= V_2 -> V_41 . V_31 ;
F_3 ( V_2 , V_42 ,
V_2 -> V_41 . V_33 + V_2 -> V_41 . V_29 ) ;
V_2 -> V_34 . V_43 ++ ;
F_17 ( & V_2 -> V_19 ) ;
F_18 ( V_2 -> V_39 ) ;
} else {
F_16 ( & V_2 -> V_19 ) ;
F_3 ( V_2 , V_42 , V_2 -> V_44 . V_33 ) ;
V_2 -> V_34 . V_45 ++ ;
F_17 ( & V_2 -> V_19 ) ;
}
}
F_16 ( & V_2 -> V_19 ) ;
F_9 ( V_2 ) ;
F_17 ( & V_2 -> V_19 ) ;
return V_46 ;
}
static unsigned int
F_19 ( int V_22 )
{
unsigned int V_47 ;
for ( V_47 = 0 ; V_47 < F_20 ( V_48 ) ; V_47 ++ )
if ( V_48 [ V_47 ] == V_22 )
return V_49 [ V_47 ] ;
return V_50 ;
}
static int
F_21 ( struct V_51 * V_52 , int V_53 )
{
struct V_1 * V_2 = F_22 ( V_52 ) ;
if ( V_2 -> V_16 . V_40 )
return - V_54 ;
F_16 ( & V_2 -> V_19 ) ;
switch ( V_53 ) {
case V_55 :
V_2 -> V_16 . V_27 = 1 ;
F_3 ( V_2 , V_32 , V_2 -> V_28 . V_33 ) ;
F_3 ( V_2 , V_42 , V_2 -> V_44 . V_33 ) ;
F_13 ( V_2 ) ;
F_9 ( V_2 ) ;
break;
case V_56 :
V_2 -> V_16 . V_27 = 0 ;
F_10 ( V_2 ) ;
F_3 ( V_2 , V_32 , V_2 -> V_36 . V_33 ) ;
F_8 ( V_2 ) ;
break;
case V_57 :
case V_58 :
case V_59 :
default:
F_17 ( & V_2 -> V_19 ) ;
F_23 () ;
return - V_60 ;
}
F_17 ( & V_2 -> V_19 ) ;
return 0 ;
}
static int
F_24 ( struct V_51 * V_52 , int V_53 )
{
struct V_1 * V_2 = F_22 ( V_52 ) ;
if ( V_2 -> V_16 . V_27 )
return - V_54 ;
F_16 ( & V_2 -> V_19 ) ;
switch ( V_53 ) {
case V_55 :
V_2 -> V_16 . V_40 = 1 ;
F_3 ( V_2 , V_32 , V_2 -> V_36 . V_33 ) ;
F_3 ( V_2 , V_42 , V_2 -> V_41 . V_33 ) ;
F_13 ( V_2 ) ;
F_9 ( V_2 ) ;
break;
case V_56 :
V_2 -> V_16 . V_40 = 0 ;
F_10 ( V_2 ) ;
F_3 ( V_2 , V_42 , V_2 -> V_44 . V_33 ) ;
F_8 ( V_2 ) ;
break;
case V_57 :
case V_58 :
case V_59 :
default:
F_17 ( & V_2 -> V_19 ) ;
F_23 () ;
return - V_60 ;
}
F_17 ( & V_2 -> V_19 ) ;
return 0 ;
}
static int
F_25 ( struct V_1 * V_2 , int V_61 , int V_62 )
{
int V_63 = V_2 -> V_16 . V_20 ;
int V_64 ;
switch( V_61 ) {
case V_65 :
V_64 = V_66 ;
break;
case V_67 :
V_64 = V_68 ;
break;
case V_69 :
V_64 = V_70 ;
break;
default:
V_64 = V_66 ;
break;
}
if ( V_62 || V_63 != V_64 ) {
F_26 ( V_61 , V_2 -> V_36 . V_71 , V_72 /
( F_27 ( V_61 )
/ 8 ) ) ;
}
return V_64 ;
}
static int
F_28 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = F_22 ( V_52 ) ;
struct V_73 * V_74 = V_52 -> V_75 ;
if ( V_2 -> V_16 . V_40 )
return - V_54 ;
V_2 -> V_28 . V_31 = F_29 ( V_52 ) ;
V_2 -> V_28 . V_30 = F_30 ( V_52 ) ;
if ( V_2 -> V_28 . V_29 >= V_2 -> V_28 . V_31 )
V_2 -> V_28 . V_29 = 0 ;
V_2 -> V_16 . V_27 = 0 ;
V_2 -> V_16 . V_22 = F_19 ( V_74 -> V_22 ) ;
V_2 -> V_16 . V_20 = F_25 ( V_2 , V_74 -> V_20 , 0 ) ;
if ( V_74 -> V_76 == 2 )
V_2 -> V_16 . V_21 = V_77 ;
else
V_2 -> V_16 . V_21 = V_78 ;
F_14 ( V_2 ) ;
V_2 -> V_28 . V_33 = V_74 -> V_79 ;
return 0 ;
}
static int
F_31 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = F_22 ( V_52 ) ;
struct V_73 * V_74 = V_52 -> V_75 ;
if ( V_2 -> V_16 . V_27 )
return - V_54 ;
V_2 -> V_41 . V_31 = F_29 ( V_52 ) ;
V_2 -> V_41 . V_30 = F_30 ( V_52 ) ;
if ( V_2 -> V_41 . V_29 >= V_2 -> V_41 . V_31 )
V_2 -> V_41 . V_29 = 0 ;
V_2 -> V_16 . V_40 = 0 ;
V_2 -> V_16 . V_22 = F_19 ( V_74 -> V_22 ) ;
V_2 -> V_16 . V_20 = F_25 ( V_2 , V_74 -> V_20 , 0 ) ;
if ( V_74 -> V_76 == 2 )
V_2 -> V_16 . V_21 = V_77 ;
else
V_2 -> V_16 . V_21 = V_78 ;
F_14 ( V_2 ) ;
V_2 -> V_41 . V_33 = V_74 -> V_79 ;
return 0 ;
}
static T_3
F_32 ( struct V_51 * V_52 )
{
struct V_73 * V_74 = V_52 -> V_75 ;
struct V_1 * V_2 = F_22 ( V_52 ) ;
unsigned long V_80 ;
unsigned long V_81 ;
if ( ! ( V_2 -> V_16 . V_27 ) || ( V_2 -> V_26 == NULL ) )
return 0 ;
if ( ( V_2 -> V_28 . V_33 == 0 ) || ( V_2 -> V_28 . V_31 == 0 ) )
return 0 ;
V_80 = F_1 ( V_2 , V_82 ) ;
V_81 = V_80 - V_2 -> V_28 . V_33 ;
#ifdef F_33
F_34 (KERN_DEBUG PFX L_1 ,
pcuradd, h->pbuf.addr, played) ;
#endif
if ( V_80 > V_2 -> V_28 . V_33 + V_2 -> V_28 . V_31 ) {
return 0 ;
}
return F_35 ( V_74 , V_81 ) ;
}
static T_3
F_36 ( struct V_51 * V_52 )
{
struct V_73 * V_74 = V_52 -> V_75 ;
struct V_1 * V_2 = F_22 ( V_52 ) ;
unsigned long V_83 ;
unsigned long V_84 ;
if ( ! ( V_2 -> V_16 . V_40 ) || ( V_2 -> V_39 == NULL ) )
return 0 ;
if ( ( V_2 -> V_41 . V_33 == 0 ) || ( V_2 -> V_41 . V_31 == 0 ) )
return 0 ;
V_83 = F_1 ( V_2 , V_85 ) ;
V_84 = V_83 - V_2 -> V_41 . V_33 ;
#ifdef F_33
F_34 (KERN_DEBUG PFX L_2 ,
rcuradd, h->cbuf.addr, caught) ;
#endif
if ( V_83 > V_2 -> V_41 . V_33 + V_2 -> V_41 . V_31 ) {
return 0 ;
}
return F_35 ( V_74 , V_84 ) ;
}
static int
F_37 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = F_22 ( V_52 ) ;
struct V_73 * V_74 = V_52 -> V_75 ;
int V_86 ;
V_2 -> V_26 = V_52 ;
V_74 -> V_87 = V_88 ;
F_38 ( V_74 , 0 , V_89 ,
& V_90 ) ;
V_86 = F_39 ( V_74 , V_91 ) ;
if ( V_86 < 0 )
return V_86 ;
return 0 ;
}
static int
F_40 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = F_22 ( V_52 ) ;
struct V_73 * V_74 = V_52 -> V_75 ;
int V_86 ;
V_2 -> V_39 = V_52 ;
V_74 -> V_87 = V_92 ;
F_38 ( V_74 , 0 , V_89 ,
& V_90 ) ;
V_86 = F_39 ( V_74 , V_91 ) ;
if ( V_86 < 0 )
return V_86 ;
return 0 ;
}
static int
F_41 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = F_22 ( V_52 ) ;
V_2 -> V_26 = NULL ;
return 0 ;
}
static int
F_42 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = F_22 ( V_52 ) ;
V_2 -> V_39 = NULL ;
return 0 ;
}
static int
F_43 ( struct V_51 * V_52 ,
struct V_93 * V_87 )
{
int V_86 ;
struct V_1 * V_2 = F_22 ( V_52 ) ;
V_86 = F_44 ( V_52 , F_45 ( V_87 ) ) ;
if ( V_86 > 0 && V_2 -> V_94 . type == V_95 )
V_52 -> V_75 -> V_79 = F_46 ( V_52 -> V_75 -> V_96 ) ;
return V_86 ;
}
static int
F_47 ( struct V_51 * V_52 )
{
return F_48 ( V_52 ) ;
}
static int
F_49 ( struct V_1 * V_2 )
{
struct V_97 * V_98 ;
int V_86 ;
if ( F_50 ( ! V_2 ) )
return - V_60 ;
F_8 ( V_2 ) ;
V_86 = F_51 ( V_2 -> V_99 , L_3 , 0 , 1 , 1 , & V_98 ) ;
if ( V_86 < 0 )
return V_86 ;
F_52 ( V_98 , V_100 ,
& V_101 ) ;
F_52 ( V_98 , V_102 ,
& V_103 ) ;
V_98 -> V_104 = V_2 ;
V_98 -> V_105 = 0 ;
strcpy ( V_98 -> V_106 , L_3 ) ;
V_2 -> V_98 = V_98 ;
V_2 -> V_26 = NULL ;
V_2 -> V_39 = NULL ;
V_2 -> V_94 . type = V_107 ;
V_2 -> V_94 . V_24 = & V_2 -> V_24 -> V_24 ;
V_86 = F_53 ( V_2 -> V_94 . type ,
V_2 -> V_94 . V_24 ,
V_108 * V_109 ,
& V_2 -> V_44 ) ;
if ( V_86 < 0 ) {
F_34 (KERN_ERR PFX L_4 ) ;
return V_86 ;
}
V_86 = F_53 ( V_2 -> V_94 . type ,
V_2 -> V_94 . V_24 ,
V_108 * V_110 ,
& V_2 -> V_36 ) ;
if ( V_86 < 0 ) {
F_34 (KERN_ERR PFX L_5 ) ;
return V_86 ;
}
V_86 = F_54 ( V_98 , V_2 -> V_94 . type ,
V_2 -> V_94 . V_24 ,
V_111 ,
V_111 ) ;
if ( V_86 < 0 ) {
F_34 (KERN_ERR PFX L_6 , err) ;
return V_86 ;
}
V_2 -> V_16 . V_20 = F_25 ( V_2 ,
V_65 , 1 ) ;
return 0 ;
}
static void
F_55 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
F_3 ( V_2 , V_14 , V_2 -> V_16 . V_17 ) ;
}
static int
F_56 ( struct V_112 * V_113 ,
struct V_114 * V_115 )
{
int V_116 = ( V_113 -> V_117 >> 16 ) & 0xff ;
int V_118 = ( V_113 -> V_117 ) & 0xff ;
int V_119 = ( V_113 -> V_117 >> 8 ) & 0xff ;
V_115 -> type = V_116 == 1 ? V_120 :
V_121 ;
V_115 -> V_30 = V_118 == V_119 ? 1 : 2 ;
V_115 -> V_122 . integer . V_123 = 0 ;
V_115 -> V_122 . integer . V_124 = V_116 ;
return 0 ;
}
static int
F_57 ( struct V_112 * V_113 ,
struct V_125 * V_126 )
{
struct V_1 * V_2 = F_58 ( V_113 ) ;
int V_127 = ( V_113 -> V_117 ) & 0xff ;
int V_128 = ( V_113 -> V_117 >> 8 ) & 0xff ;
int V_116 = ( V_113 -> V_117 >> 16 ) & 0xff ;
int V_129 = ( V_113 -> V_117 >> 24 ) & 0xff ;
int V_130 , V_131 ;
F_59 ( & V_2 -> V_13 ) ;
V_130 = ( V_2 -> V_16 . V_17 >> V_127 ) & V_116 ;
V_131 = ( V_2 -> V_16 . V_17 >> V_128 ) & V_116 ;
if ( V_129 ) {
V_130 = V_116 - V_130 ;
V_131 = V_116 - V_131 ;
}
V_126 -> V_122 . integer . V_122 [ 0 ] = V_130 ;
if ( V_127 != V_128 )
V_126 -> V_122 . integer . V_122 [ 1 ] = V_131 ;
F_60 ( & V_2 -> V_13 ) ;
return 0 ;
}
static int
F_61 ( struct V_112 * V_113 ,
struct V_125 * V_126 )
{
struct V_1 * V_2 = F_58 ( V_113 ) ;
int V_127 = ( V_113 -> V_117 ) & 0xff ;
int V_128 = ( V_113 -> V_117 >> 8 ) & 0xff ;
int V_116 = ( V_113 -> V_117 >> 16 ) & 0xff ;
int V_129 = ( V_113 -> V_117 >> 24 ) & 0xff ;
int V_130 , V_131 ;
int V_132 = V_2 -> V_16 . V_17 ;
F_59 ( & V_2 -> V_13 ) ;
V_130 = V_126 -> V_122 . integer . V_122 [ 0 ] & V_116 ;
if ( V_129 )
V_130 = V_116 - V_130 ;
V_2 -> V_16 . V_17 &= ~ ( ( V_116 << V_127 ) ) ;
V_2 -> V_16 . V_17 |= ( V_130 << V_127 ) ;
if ( V_127 != V_128 ) {
V_131 = V_126 -> V_122 . integer . V_122 [ 1 ] & V_116 ;
if ( V_129 )
V_131 = V_116 - V_131 ;
V_2 -> V_16 . V_17 &= ~ ( ( V_116 << V_128 ) ) ;
V_2 -> V_16 . V_17 |= ( V_131 << V_128 ) ;
}
F_55 ( V_2 ) ;
F_60 ( & V_2 -> V_13 ) ;
return V_2 -> V_16 . V_17 != V_132 ;
}
static int
F_62 ( struct V_112 * V_113 ,
struct V_114 * V_115 )
{
static char * V_133 [ 2 ] = { L_7 , L_8 } ;
V_115 -> type = V_134 ;
V_115 -> V_30 = 1 ;
V_115 -> V_122 . V_135 . V_136 = 2 ;
if ( V_115 -> V_122 . V_135 . V_137 > 1 )
V_115 -> V_122 . V_135 . V_137 = 1 ;
strcpy ( V_115 -> V_122 . V_135 . V_106 ,
V_133 [ V_115 -> V_122 . V_135 . V_137 ] ) ;
return 0 ;
}
static int
F_63 ( struct V_112 * V_113 ,
struct V_125 * V_126 )
{
struct V_1 * V_2 = F_58 ( V_113 ) ;
int V_122 ;
F_59 ( & V_2 -> V_13 ) ;
V_122 = ( V_2 -> V_16 . V_17 >> V_138 ) & 1 ;
V_126 -> V_122 . V_135 . V_137 [ 0 ] = V_122 ;
F_60 ( & V_2 -> V_13 ) ;
return 0 ;
}
static int
F_64 ( struct V_112 * V_113 ,
struct V_125 * V_126 )
{
struct V_1 * V_2 = F_58 ( V_113 ) ;
int V_122 ;
int V_132 = V_2 -> V_16 . V_17 ;
F_59 ( & V_2 -> V_13 ) ;
V_122 = V_126 -> V_122 . V_135 . V_137 [ 0 ] & 1 ;
V_2 -> V_16 . V_17 &= ~ V_139 ;
V_2 -> V_16 . V_17 |= V_122 << V_138 ;
F_55 ( V_2 ) ;
F_60 ( & V_2 -> V_13 ) ;
return V_2 -> V_16 . V_17 != V_132 ;
}
static void T_4
F_65 ( struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
F_6 ( V_2 ) ;
V_2 -> V_16 . V_17 = V_140 ;
F_13 ( V_2 ) ;
}
static int T_4
F_66 ( struct V_1 * V_2 )
{
struct V_141 * V_99 ;
int V_142 , V_86 ;
if ( F_50 ( ! V_2 ) )
return - V_60 ;
V_99 = V_2 -> V_99 ;
strcpy ( V_99 -> V_143 , L_9 ) ;
for ( V_142 = 0 ; V_142 < V_144 ; V_142 ++ ) {
V_86 = F_67 ( V_99 ,
F_68 ( & V_145 [ V_142 ] , V_2 ) ) ;
if ( V_86 < 0 )
return V_86 ;
}
F_65 ( V_2 ) ;
return 0 ;
}
static int
F_69 ( struct V_1 * V_2 )
{
if ( V_2 -> V_44 . V_33 )
F_70 ( & V_2 -> V_44 ) ;
if ( V_2 -> V_36 . V_33 )
F_70 ( & V_2 -> V_36 ) ;
if ( V_2 -> V_23 >= 0 )
F_71 ( V_2 -> V_23 , V_2 ) ;
if ( V_2 -> V_4 )
F_72 ( V_2 -> V_4 ) ;
F_73 ( V_2 -> V_24 , NULL ) ;
F_74 ( V_2 ) ;
return 0 ;
}
static int
F_75 ( struct V_146 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_147 ;
return F_69 ( V_2 ) ;
}
static int T_4
F_76 ( struct V_141 * V_99 ,
struct V_148 * V_149 ,
struct V_1 * * V_150 )
{
int V_86 ;
struct V_1 * V_2 ;
static struct V_151 V_152 = {
. V_153 = F_75 ,
} ;
* V_150 = NULL ;
V_2 = F_77 ( sizeof( * V_2 ) , V_154 ) ;
if ( V_2 == NULL )
return - V_155 ;
V_2 -> V_156 = V_149 -> V_156 . V_157 ;
V_2 -> V_99 = V_99 ;
V_2 -> V_24 = V_149 ;
V_2 -> V_23 = - 1 ;
V_2 -> V_4 = F_78 ( V_149 -> V_156 . V_157 , V_158 ) ;
if ( V_2 -> V_4 == NULL ) {
F_34 (KERN_ERR PFX L_10 ,
(unsigned long)padev->hpa.start) ;
V_86 = - V_54 ;
goto V_159;
}
V_86 = F_79 ( V_149 -> V_23 , F_15 , 0 ,
L_3 , V_2 ) ;
if ( V_86 ) {
F_34 (KERN_ERR PFX L_11 ,
padev->irq) ;
goto V_159;
}
V_2 -> V_23 = V_149 -> V_23 ;
F_80 ( & V_2 -> V_13 ) ;
F_80 ( & V_2 -> V_19 ) ;
if ( ( V_86 = F_81 ( V_99 , V_160 ,
V_2 , & V_152 ) ) < 0 ) {
goto V_159;
}
F_82 ( V_99 , & V_149 -> V_24 ) ;
* V_150 = V_2 ;
return 0 ;
V_159:
F_69 ( V_2 ) ;
return V_86 ;
}
static int T_4
F_83 ( struct V_148 * V_149 )
{
int V_86 ;
struct V_141 * V_99 ;
struct V_1 * V_2 ;
V_86 = F_84 ( V_161 , V_162 , V_163 , 0 , & V_99 ) ;
if ( V_86 < 0 )
return V_86 ;
V_86 = F_76 ( V_99 , V_149 , & V_2 ) ;
if ( V_86 < 0 )
goto V_159;
V_86 = F_49 ( V_2 ) ;
if ( V_86 < 0 )
goto V_159;
V_86 = F_66 ( V_2 ) ;
if ( V_86 < 0 )
goto V_159;
strcpy ( V_99 -> V_164 , L_3 ) ;
strcpy ( V_99 -> V_165 , L_12 ) ;
sprintf ( V_99 -> V_166 , L_13 ,
V_99 -> V_165 , V_2 -> V_156 , V_2 -> V_23 ) ;
V_86 = F_85 ( V_99 ) ;
if ( V_86 < 0 )
goto V_159;
F_73 ( V_149 , V_99 ) ;
return 0 ;
V_159:
F_86 ( V_99 ) ;
return V_86 ;
}
static int T_5
F_87 ( struct V_148 * V_149 )
{
F_86 ( F_88 ( V_149 ) ) ;
F_73 ( V_149 , NULL ) ;
return 0 ;
}
static int T_6
F_89 ( void )
{
return F_90 ( & V_167 ) ;
}
static void T_7
F_91 ( void )
{
F_92 ( & V_167 ) ;
}
