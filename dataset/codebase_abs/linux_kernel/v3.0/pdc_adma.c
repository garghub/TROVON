static int F_1 ( struct V_1 * V_2 )
{
return 1 ;
}
static void F_2 ( struct V_3 * V_4 )
{
void T_1 * V_5 = F_3 ( V_4 ) ;
F_4 ( V_6 | V_7 | V_8 , V_5 + V_9 ) ;
F_5 ( 2 ) ;
F_4 ( V_6 , V_5 + V_9 ) ;
F_5 ( 2 ) ;
}
static void F_6 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = V_4 -> V_12 ;
void T_1 * V_5 = F_3 ( V_4 ) ;
F_7 ( V_13 , V_4 -> V_14 . V_15 ) ;
F_8 ( V_4 ) ;
F_2 ( V_4 ) ;
F_4 ( 0x100 , V_5 + V_16 ) ;
F_9 ( ( V_17 ) V_11 -> V_18 , V_5 + V_19 ) ;
F_4 ( 0x100 , V_5 + V_20 ) ;
F_4 ( 1 , V_5 + V_21 ) ;
F_10 ( V_5 + V_22 ) ;
}
static inline void F_11 ( struct V_3 * V_4 )
{
void T_1 * V_5 = F_3 ( V_4 ) ;
F_4 ( V_6 , V_5 + V_9 ) ;
F_10 ( V_5 + V_22 ) ;
}
static void F_12 ( struct V_3 * V_4 )
{
void T_1 * V_5 = F_3 ( V_4 ) ;
F_7 ( V_13 , V_4 -> V_14 . V_15 ) ;
F_8 ( V_4 ) ;
F_4 ( V_6 | V_7 | V_8 , V_5 + V_9 ) ;
F_5 ( 2 ) ;
F_4 ( V_6 | V_7 , V_5 + V_9 ) ;
F_5 ( 2 ) ;
}
static void F_13 ( struct V_3 * V_4 )
{
F_6 ( V_4 ) ;
}
static int F_14 ( struct V_23 * V_24 , unsigned long V_25 )
{
struct V_3 * V_4 = V_24 -> V_4 ;
struct V_10 * V_11 = V_4 -> V_12 ;
if ( V_11 -> V_26 != V_27 )
V_11 -> V_26 = V_28 ;
F_6 ( V_4 ) ;
return F_15 ( V_24 , V_25 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_29 * V_30 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_10 * V_11 = V_4 -> V_12 ;
T_2 * V_31 = V_11 -> V_32 , * V_33 = NULL ;
int V_34 = ( 2 + V_31 [ 3 ] ) * 8 ;
T_2 V_35 = V_36 | ( ( V_2 -> V_37 . V_38 & V_39 ) ? V_40 : 0 ) ;
unsigned int V_41 ;
F_17 (qc->sg, sg, qc->n_elem, si) {
V_17 V_42 ;
V_17 V_43 ;
V_42 = ( V_17 ) F_18 ( V_30 ) ;
* ( V_44 * ) ( V_31 + V_34 ) = F_19 ( V_42 ) ;
V_34 += 4 ;
V_43 = F_20 ( V_30 ) >> 3 ;
* ( V_44 * ) ( V_31 + V_34 ) = F_19 ( V_43 ) ;
V_34 += 4 ;
V_33 = & V_31 [ V_34 ] ;
V_31 [ V_34 ++ ] = V_35 ;
V_31 [ V_34 ++ ] = V_2 -> V_45 -> V_46 & 0xf ;
V_31 [ V_34 ++ ] = 0 ;
V_31 [ V_34 ++ ] = 0 ;
* ( V_44 * ) ( V_31 + V_34 ) =
( V_35 & V_47 ) ? 0 : F_19 ( V_11 -> V_18 + V_34 + 4 ) ;
V_34 += 4 ;
F_21 ( L_1 , V_34 / 4 ,
( unsigned long ) V_42 , V_43 ) ;
}
if ( F_22 ( V_33 ) )
* V_33 |= V_47 ;
return V_34 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_4 -> V_12 ;
T_2 * V_31 = V_11 -> V_32 ;
V_17 V_18 = ( V_17 ) V_11 -> V_18 ;
int V_34 = 0 ;
F_21 ( L_2 ) ;
F_11 ( V_2 -> V_4 ) ;
if ( V_2 -> V_37 . V_48 != V_49 )
return;
V_31 [ V_34 ++ ] = 0 ;
V_31 [ V_34 ++ ] = 0 ;
V_31 [ V_34 ++ ] = V_50 | V_51 | V_52 ;
V_34 ++ ;
* ( V_44 * ) ( V_31 + V_34 ) = F_19 ( V_18 ) ;
V_34 += 4 ;
V_34 += 4 ;
V_31 [ V_34 ++ ] = 0 ;
V_31 [ V_34 ++ ] = 0 ;
V_31 [ V_34 ++ ] = 0 ;
V_31 [ V_34 ++ ] = 0 ;
V_31 [ V_34 ++ ] = V_2 -> V_37 . V_53 ;
V_31 [ V_34 ++ ] = V_54 ;
if ( ( V_2 -> V_37 . V_38 & V_55 ) ) {
V_31 [ V_34 ++ ] = V_2 -> V_37 . V_56 ;
V_31 [ V_34 ++ ] = V_57 ;
V_31 [ V_34 ++ ] = V_2 -> V_37 . V_58 ;
V_31 [ V_34 ++ ] = V_59 ;
V_31 [ V_34 ++ ] = V_2 -> V_37 . V_60 ;
V_31 [ V_34 ++ ] = V_61 ;
V_31 [ V_34 ++ ] = V_2 -> V_37 . V_62 ;
V_31 [ V_34 ++ ] = V_63 ;
}
V_31 [ V_34 ++ ] = V_2 -> V_37 . V_64 ;
V_31 [ V_34 ++ ] = V_57 ;
V_31 [ V_34 ++ ] = V_2 -> V_37 . V_65 ;
V_31 [ V_34 ++ ] = V_59 ;
V_31 [ V_34 ++ ] = V_2 -> V_37 . V_66 ;
V_31 [ V_34 ++ ] = V_61 ;
V_31 [ V_34 ++ ] = V_2 -> V_37 . V_67 ;
V_31 [ V_34 ++ ] = V_63 ;
V_31 [ V_34 ++ ] = 0 ;
V_31 [ V_34 ++ ] = V_68 ;
V_31 [ V_34 ++ ] = V_69 ;
V_31 [ V_34 ++ ] = 0 ;
V_31 [ V_34 ++ ] = V_2 -> V_37 . V_70 ;
V_31 [ V_34 ++ ] = V_71 | V_72 ;
V_31 [ 3 ] = ( V_34 >> 3 ) - 2 ;
* ( V_44 * ) ( V_31 + 8 ) = F_19 ( V_18 + V_34 ) ;
V_34 = F_16 ( V_2 ) ;
F_24 () ;
#if 0
{
int j, len = 0;
static char obuf[2048];
for (j = 0; j < i; ++j) {
len += sprintf(obuf+len, "%02x ", buf[j]);
if ((j & 7) == 7) {
printk("%s\n", obuf);
len = 0;
}
}
if (len)
printk("%s\n", obuf);
}
#endif
}
static inline void F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
void T_1 * V_5 = F_3 ( V_4 ) ;
F_21 ( L_3 , V_4 ) ;
F_4 ( V_6 | V_73 , V_5 + V_9 ) ;
}
static unsigned int F_26 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_4 -> V_12 ;
switch ( V_2 -> V_37 . V_48 ) {
case V_49 :
V_11 -> V_26 = V_74 ;
F_25 ( V_2 ) ;
return 0 ;
case V_75 :
F_27 () ;
break;
default:
break;
}
V_11 -> V_26 = V_28 ;
return F_28 ( V_2 ) ;
}
static inline unsigned int F_29 ( struct V_76 * V_77 )
{
unsigned int V_78 = 0 , V_79 ;
for ( V_79 = 0 ; V_79 < V_77 -> V_80 ; ++ V_79 ) {
struct V_3 * V_4 = V_77 -> V_81 [ V_79 ] ;
struct V_10 * V_11 ;
struct V_1 * V_2 ;
void T_1 * V_5 = F_3 ( V_4 ) ;
T_2 V_82 = F_10 ( V_5 + V_22 ) ;
if ( V_82 == 0 )
continue;
V_78 = 1 ;
F_11 ( V_4 ) ;
V_11 = V_4 -> V_12 ;
if ( ! V_11 || V_11 -> V_26 != V_74 )
continue;
V_2 = F_30 ( V_4 , V_4 -> V_24 . V_83 ) ;
if ( V_2 && ( ! ( V_2 -> V_37 . V_38 & V_84 ) ) ) {
if ( V_82 & V_85 )
V_2 -> V_86 |= V_87 ;
else if ( ( V_82 & ( V_88 | V_89 ) ) )
V_2 -> V_86 |= V_90 ;
if ( V_11 -> V_32 [ 0 ] & V_91 )
V_2 -> V_86 |= V_92 ;
else if ( V_11 -> V_32 [ 0 ] != V_93 )
V_2 -> V_86 |= V_90 ;
if ( ! V_2 -> V_86 )
F_31 ( V_2 ) ;
else {
struct V_94 * V_95 = & V_4 -> V_24 . V_96 ;
F_32 ( V_95 ) ;
F_33 ( V_95 ,
L_4 , V_82 ) ;
F_33 ( V_95 ,
L_5 , V_11 -> V_32 [ 0 ] ) ;
if ( V_2 -> V_86 == V_92 )
F_34 ( V_4 ) ;
else
F_35 ( V_4 ) ;
}
}
}
return V_78 ;
}
static inline unsigned int F_36 ( struct V_76 * V_77 )
{
unsigned int V_78 = 0 , V_79 ;
for ( V_79 = 0 ; V_79 < V_77 -> V_80 ; ++ V_79 ) {
struct V_3 * V_4 = V_77 -> V_81 [ V_79 ] ;
struct V_10 * V_11 = V_4 -> V_12 ;
struct V_1 * V_2 ;
if ( ! V_11 || V_11 -> V_26 != V_28 )
continue;
V_2 = F_30 ( V_4 , V_4 -> V_24 . V_83 ) ;
if ( V_2 && ( ! ( V_2 -> V_37 . V_38 & V_84 ) ) ) {
T_2 V_82 = F_8 ( V_4 ) ;
if ( ( V_82 & V_97 ) )
continue;
F_37 ( L_6 ,
V_4 -> V_98 , V_2 -> V_37 . V_48 , V_82 ) ;
V_11 -> V_26 = V_27 ;
V_2 -> V_86 |= F_38 ( V_82 ) ;
if ( ! V_2 -> V_86 )
F_31 ( V_2 ) ;
else {
struct V_94 * V_95 = & V_4 -> V_24 . V_96 ;
F_32 ( V_95 ) ;
F_33 ( V_95 , L_7 , V_82 ) ;
if ( V_2 -> V_86 == V_92 )
F_34 ( V_4 ) ;
else
F_35 ( V_4 ) ;
}
V_78 = 1 ;
}
}
return V_78 ;
}
static T_3 F_39 ( int V_99 , void * V_100 )
{
struct V_76 * V_77 = V_100 ;
unsigned int V_78 = 0 ;
F_21 ( L_2 ) ;
F_40 ( & V_77 -> V_101 ) ;
V_78 = F_29 ( V_77 ) | F_36 ( V_77 ) ;
F_41 ( & V_77 -> V_101 ) ;
F_21 ( L_8 ) ;
return F_42 ( V_78 ) ;
}
static void F_43 ( struct V_102 * V_103 , void T_1 * V_104 )
{
V_103 -> V_105 =
V_103 -> V_106 = V_104 + 0x000 ;
V_103 -> V_107 =
V_103 -> V_108 = V_104 + 0x004 ;
V_103 -> V_109 = V_104 + 0x008 ;
V_103 -> V_110 = V_104 + 0x00c ;
V_103 -> V_111 = V_104 + 0x010 ;
V_103 -> V_112 = V_104 + 0x014 ;
V_103 -> V_113 = V_104 + 0x018 ;
V_103 -> V_114 =
V_103 -> V_115 = V_104 + 0x01c ;
V_103 -> V_116 =
V_103 -> V_15 = V_104 + 0x038 ;
}
static int F_44 ( struct V_3 * V_4 )
{
struct V_53 * V_45 = V_4 -> V_77 -> V_45 ;
struct V_10 * V_11 ;
F_11 ( V_4 ) ;
V_11 = F_45 ( V_45 , sizeof( * V_11 ) , V_117 ) ;
if ( ! V_11 )
return - V_118 ;
V_11 -> V_32 = F_46 ( V_45 , V_119 , & V_11 -> V_18 ,
V_117 ) ;
if ( ! V_11 -> V_32 )
return - V_118 ;
if ( ( V_11 -> V_18 & 7 ) != 0 ) {
F_47 ( V_120 L_9 ,
( V_17 ) V_11 -> V_18 ) ;
return - V_118 ;
}
memset ( V_11 -> V_32 , 0 , V_119 ) ;
V_4 -> V_12 = V_11 ;
F_6 ( V_4 ) ;
return 0 ;
}
static void F_48 ( struct V_3 * V_4 )
{
F_2 ( V_4 ) ;
}
static void F_49 ( struct V_76 * V_77 , unsigned int V_121 )
{
unsigned int V_79 ;
F_7 ( 7 , V_77 -> V_122 [ V_123 ] + V_124 ) ;
for ( V_79 = 0 ; V_79 < V_125 ; ++ V_79 )
F_2 ( V_77 -> V_81 [ V_79 ] ) ;
}
static int F_50 ( struct V_126 * V_127 , void T_1 * V_128 )
{
int V_129 ;
V_129 = F_51 ( V_127 , F_52 ( 32 ) ) ;
if ( V_129 ) {
F_53 ( V_120 , & V_127 -> V_45 ,
L_10 ) ;
return V_129 ;
}
V_129 = F_54 ( V_127 , F_52 ( 32 ) ) ;
if ( V_129 ) {
F_53 ( V_120 , & V_127 -> V_45 ,
L_11 ) ;
return V_129 ;
}
return 0 ;
}
static int F_55 ( struct V_126 * V_127 ,
const struct V_130 * V_131 )
{
static int V_132 ;
unsigned int V_133 = ( unsigned int ) V_131 -> V_134 ;
const struct V_135 * V_136 [] = { & V_137 [ V_133 ] , NULL } ;
struct V_76 * V_77 ;
void T_1 * V_128 ;
int V_129 , V_79 ;
if ( ! V_132 ++ )
F_53 ( V_138 , & V_127 -> V_45 , L_12 V_139 L_13 ) ;
V_77 = F_56 ( & V_127 -> V_45 , V_136 , V_125 ) ;
if ( ! V_77 )
return - V_118 ;
V_129 = F_57 ( V_127 ) ;
if ( V_129 )
return V_129 ;
if ( ( F_58 ( V_127 , 4 ) & V_140 ) == 0 )
return - V_141 ;
V_129 = F_59 ( V_127 , 1 << V_123 , V_142 ) ;
if ( V_129 )
return V_129 ;
V_77 -> V_122 = F_60 ( V_127 ) ;
V_128 = V_77 -> V_122 [ V_123 ] ;
V_129 = F_50 ( V_127 , V_128 ) ;
if ( V_129 )
return V_129 ;
for ( V_79 = 0 ; V_79 < V_125 ; ++ V_79 ) {
struct V_3 * V_4 = V_77 -> V_81 [ V_79 ] ;
void T_1 * V_143 = F_61 ( V_128 , V_79 ) ;
unsigned int V_144 = V_143 - V_128 ;
F_43 ( & V_4 -> V_14 , V_143 ) ;
F_62 ( V_4 , V_123 , - 1 , L_14 ) ;
F_62 ( V_4 , V_123 , V_144 , L_15 ) ;
}
F_49 ( V_77 , V_133 ) ;
F_63 ( V_127 ) ;
return F_64 ( V_77 , V_127 -> V_99 , F_39 , V_145 ,
& V_146 ) ;
}
static int T_4 F_65 ( void )
{
return F_66 ( & V_147 ) ;
}
static void T_5 F_67 ( void )
{
F_68 ( & V_147 ) ;
}
