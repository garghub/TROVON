void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 = V_8 ;
struct V_9 T_1 * V_10 ;
struct V_11 * V_11 = V_8 -> V_12 . V_11 ;
long V_13 = 0 ;
F_2 () ;
if ( ! V_11 || ! V_11 -> V_14 ) {
F_3 ( L_1 ) ;
F_4 ( V_15 ) ;
}
F_5 ( V_2 -> V_16 . V_17 , V_18 , V_19 | V_11 -> V_20 ) ;
V_10 = V_11 -> V_14 ;
if ( ! F_6 ( V_21 , V_10 , V_11 -> V_22 . V_23 ?
sizeof( struct V_9 ) :
sizeof( struct V_24 ) ) ) {
F_3 ( L_2 ) ;
F_4 ( V_15 ) ;
}
F_7 {
F_8 ( V_2 -> V_16 . V_25 , & V_10 -> V_2 . V_26 ) ;
F_8 ( V_2 -> V_16 . V_27 , & V_10 -> V_2 . V_28 ) ;
F_8 ( V_2 -> V_16 . V_29 , & V_10 -> V_2 . V_30 ) ;
F_8 ( V_2 -> V_16 . V_31 , & V_10 -> V_2 . V_32 ) ;
F_8 ( V_2 -> V_16 . V_33 , & V_10 -> V_2 . V_34 ) ;
F_8 ( V_2 -> V_16 . V_35 , & V_10 -> V_2 . V_36 ) ;
F_8 ( V_2 -> V_16 . V_37 , & V_10 -> V_2 . V_38 ) ;
F_8 ( V_2 -> V_16 . V_39 , & V_10 -> V_2 . V_40 ) ;
F_8 ( V_2 -> V_16 . V_41 , & V_10 -> V_2 . V_41 ) ;
F_8 ( V_2 -> V_16 . V_17 , & V_10 -> V_2 . V_42 ) ;
F_8 ( V_2 -> V_16 . V_43 , & V_10 -> V_2 . V_44 ) ;
F_8 ( V_2 -> V_16 . V_45 , & V_10 -> V_2 . V_45 ) ;
F_8 ( V_2 -> V_46 , & V_10 -> V_2 . V_46 ) ;
F_8 ( V_2 -> V_47 , & V_10 -> V_2 . V_47 ) ;
F_8 ( V_2 -> V_48 , & V_10 -> V_2 . V_48 ) ;
F_8 ( V_2 -> V_49 , & V_10 -> V_2 . V_49 ) ;
F_8 ( V_11 -> V_50 , & V_10 -> V_50 ) ;
} F_9 ( V_13 ) ;
if ( V_13 ) {
F_3 ( L_2 ) ;
F_4 ( V_15 ) ;
}
V_5 = & F_10 ( V_51 , F_11 () ) ;
V_7 -> V_12 . V_52 = V_11 -> V_53 ;
V_7 -> V_12 . V_54 = V_55 ;
F_12 ( V_5 , & V_7 -> V_12 ) ;
V_11 -> V_53 = 0 ;
F_13 () ;
memcpy ( & V_2 -> V_16 , & V_11 -> V_56 , sizeof( struct V_57 ) ) ;
F_14 ( V_11 -> V_56 . V_49 ) ;
V_2 -> V_16 . V_37 = V_3 ;
}
static void F_15 ( struct V_58 * V_59 )
{
T_2 * V_60 ;
T_3 * V_61 ;
T_4 * V_62 ;
T_5 * V_63 ;
T_6 * V_64 ;
int V_65 ;
F_16 ( & V_59 -> V_66 ) ;
V_60 = F_17 ( V_59 , 0xA0000 ) ;
if ( F_18 ( V_60 ) )
goto V_67;
V_61 = F_19 ( V_60 , 0xA0000 ) ;
if ( F_20 ( V_61 ) )
goto V_67;
V_62 = F_21 ( V_61 , 0xA0000 ) ;
F_22 ( V_59 , 0xA0000 , V_62 ) ;
if ( F_23 ( V_62 ) )
goto V_67;
V_63 = F_24 ( V_59 , V_62 , 0xA0000 , & V_64 ) ;
for ( V_65 = 0 ; V_65 < 32 ; V_65 ++ ) {
if ( F_25 ( * V_63 ) )
F_26 ( V_63 , F_27 ( * V_63 ) ) ;
V_63 ++ ;
}
F_28 ( V_63 , V_64 ) ;
V_67:
F_29 ( & V_59 -> V_66 ) ;
F_30 () ;
}
static long F_31 ( struct V_9 T_1 * V_14 , bool V_68 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 = V_8 ;
struct V_11 * V_11 = V_7 -> V_12 . V_11 ;
struct V_1 V_69 ;
struct V_57 * V_2 = F_32 () ;
unsigned long V_13 = 0 ;
V_13 = F_33 ( 0 ) ;
if ( V_13 ) {
F_34 ( L_3 ,
V_8 -> V_70 , F_35 ( V_8 ) ,
F_36 ( & V_71 , F_37 () ) ) ;
return - V_72 ;
}
if ( ! V_11 ) {
if ( ! ( V_11 = F_38 ( sizeof( * V_11 ) , V_73 ) ) )
return - V_74 ;
V_7 -> V_12 . V_11 = V_11 ;
}
if ( V_11 -> V_53 )
return - V_72 ;
if ( ! F_6 ( V_75 , V_14 , V_68 ?
sizeof( struct V_24 ) :
sizeof( struct V_9 ) ) )
return - V_76 ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
F_39 {
unsigned short V_77 ;
F_40 ( V_69 . V_16 . V_25 , & V_14 -> V_2 . V_26 ) ;
F_40 ( V_69 . V_16 . V_27 , & V_14 -> V_2 . V_28 ) ;
F_40 ( V_69 . V_16 . V_29 , & V_14 -> V_2 . V_30 ) ;
F_40 ( V_69 . V_16 . V_31 , & V_14 -> V_2 . V_32 ) ;
F_40 ( V_69 . V_16 . V_33 , & V_14 -> V_2 . V_34 ) ;
F_40 ( V_69 . V_16 . V_35 , & V_14 -> V_2 . V_36 ) ;
F_40 ( V_69 . V_16 . V_37 , & V_14 -> V_2 . V_38 ) ;
F_40 ( V_69 . V_16 . V_39 , & V_14 -> V_2 . V_40 ) ;
F_40 ( V_77 , & V_14 -> V_2 . V_41 ) ;
V_69 . V_16 . V_41 = V_77 ;
F_40 ( V_69 . V_16 . V_17 , & V_14 -> V_2 . V_42 ) ;
F_40 ( V_69 . V_16 . V_43 , & V_14 -> V_2 . V_44 ) ;
F_40 ( V_77 , & V_14 -> V_2 . V_45 ) ;
V_69 . V_16 . V_45 = V_77 ;
F_40 ( V_69 . V_46 , & V_14 -> V_2 . V_46 ) ;
F_40 ( V_69 . V_47 , & V_14 -> V_2 . V_47 ) ;
F_40 ( V_69 . V_48 , & V_14 -> V_2 . V_48 ) ;
F_40 ( V_69 . V_49 , & V_14 -> V_2 . V_49 ) ;
F_40 ( V_11 -> V_17 , & V_14 -> V_17 ) ;
F_40 ( V_11 -> V_50 , & V_14 -> V_50 ) ;
F_40 ( V_11 -> V_78 , & V_14 -> V_78 ) ;
} F_41 ( V_13 ) ;
if ( V_13 )
return V_13 ;
if ( F_42 ( & V_11 -> V_79 ,
& V_14 -> V_79 ,
sizeof( struct V_80 ) ) )
return - V_76 ;
if ( F_42 ( & V_11 -> V_81 ,
& V_14 -> V_81 ,
sizeof( struct V_80 ) ) )
return - V_76 ;
if ( V_68 ) {
if ( F_42 ( & V_11 -> V_22 , & V_14 -> V_22 ,
sizeof( struct V_82 ) ) )
return - V_76 ;
V_11 -> V_22 . V_23 = 1 ;
} else
memset ( & V_11 -> V_22 , 0 ,
sizeof( struct V_82 ) ) ;
memcpy ( & V_11 -> V_56 , V_2 , sizeof( struct V_57 ) ) ;
V_11 -> V_14 = V_14 ;
V_18 = V_69 . V_16 . V_17 ;
V_69 . V_16 . V_17 &= V_83 ;
V_69 . V_16 . V_17 |= V_2 -> V_17 & ~ V_83 ;
V_69 . V_16 . V_17 |= V_84 ;
V_69 . V_16 . V_85 = V_2 -> V_85 ;
switch ( V_11 -> V_78 ) {
case V_86 :
V_11 -> V_20 = 0 ;
break;
case V_87 :
V_11 -> V_20 = V_88 | V_89 ;
break;
case V_90 :
V_11 -> V_20 = V_91 | V_88 | V_89 ;
break;
default:
V_11 -> V_20 = V_92 | V_91 | V_88 | V_89 ;
break;
}
V_11 -> V_53 = V_7 -> V_12 . V_52 ;
F_43 ( V_11 -> V_56 . V_49 ) ;
V_5 = & F_10 ( V_51 , F_11 () ) ;
V_7 -> V_12 . V_52 += 16 ;
if ( V_93 )
V_7 -> V_12 . V_54 = 0 ;
F_12 ( V_5 , & V_7 -> V_12 ) ;
F_13 () ;
if ( V_11 -> V_17 & V_94 )
F_15 ( V_7 -> V_59 ) ;
memcpy ( (struct V_1 * ) V_2 , & V_69 , sizeof( V_69 ) ) ;
F_44 () ;
return V_2 -> V_37 ;
}
static inline void F_45 ( struct V_1 * V_2 )
{
V_18 |= V_19 ;
}
static inline void F_46 ( struct V_1 * V_2 )
{
V_18 &= ~ V_19 ;
}
static inline void F_47 ( struct V_1 * V_2 )
{
V_2 -> V_16 . V_17 &= ~ V_95 ;
}
static inline void F_48 ( struct V_1 * V_2 )
{
V_2 -> V_16 . V_17 &= ~ V_91 ;
}
static inline void F_49 ( unsigned long V_17 , struct V_1 * V_2 )
{
F_5 ( V_18 , V_17 , V_8 -> V_12 . V_11 -> V_20 ) ;
F_5 ( V_2 -> V_16 . V_17 , V_17 , V_83 ) ;
if ( V_17 & V_96 )
F_45 ( V_2 ) ;
else
F_46 ( V_2 ) ;
}
static inline void F_50 ( unsigned short V_17 , struct V_1 * V_2 )
{
F_5 ( V_97 , V_17 , V_8 -> V_12 . V_11 -> V_20 ) ;
F_5 ( V_2 -> V_16 . V_17 , V_17 , V_83 ) ;
if ( V_17 & V_96 )
F_45 ( V_2 ) ;
else
F_46 ( V_2 ) ;
}
static inline unsigned long F_51 ( struct V_1 * V_2 )
{
unsigned long V_17 = V_2 -> V_16 . V_17 & V_98 ;
if ( V_18 & V_19 )
V_17 |= V_96 ;
V_17 |= V_89 ;
return V_17 | ( V_18 & V_8 -> V_12 . V_11 -> V_20 ) ;
}
static inline int F_52 ( int V_99 , struct V_80 * V_100 )
{
__asm__ __volatile__("btl %2,%1\n\tsbbl %0,%0"
:"=r" (nr)
:"m" (*bitmap), "r" (nr));
return V_99 ;
}
static void F_53 ( struct V_1 * V_2 , int V_65 ,
unsigned char T_1 * V_101 , unsigned short V_43 )
{
unsigned long T_1 * V_102 ;
unsigned long V_103 ;
struct V_11 * V_11 = V_8 -> V_12 . V_11 ;
if ( V_2 -> V_16 . V_41 == V_104 )
goto V_105;
if ( F_52 ( V_65 , & V_11 -> V_79 ) )
goto V_105;
if ( V_65 == 0x21 && F_52 ( F_54 ( V_2 ) , & V_11 -> V_81 ) )
goto V_105;
V_102 = ( unsigned long T_1 * ) ( V_65 << 2 ) ;
if ( F_55 ( V_103 , V_102 ) )
goto V_105;
if ( ( V_103 >> 16 ) == V_104 )
goto V_105;
F_56 ( V_101 , V_43 , F_51 ( V_2 ) , V_105 ) ;
F_56 ( V_101 , V_43 , V_2 -> V_16 . V_41 , V_105 ) ;
F_56 ( V_101 , V_43 , F_57 ( V_2 ) , V_105 ) ;
V_2 -> V_16 . V_41 = V_103 >> 16 ;
F_58 ( V_2 ) -= 6 ;
F_57 ( V_2 ) = V_103 & 0xffff ;
F_47 ( V_2 ) ;
F_46 ( V_2 ) ;
F_48 ( V_2 ) ;
return;
V_105:
F_1 ( V_2 , V_106 + ( V_65 << 8 ) ) ;
}
int F_59 ( struct V_1 * V_2 , long V_107 , int V_108 )
{
struct V_11 * V_11 = V_8 -> V_12 . V_11 ;
if ( V_11 -> V_22 . V_23 ) {
if ( ( V_108 == 3 ) || ( V_108 == 1 ) ) {
F_1 ( V_2 , V_109 + ( V_108 << 8 ) ) ;
return 0 ;
}
F_53 ( V_2 , V_108 , ( unsigned char T_1 * ) ( V_2 -> V_16 . V_45 << 4 ) , F_58 ( V_2 ) ) ;
return 0 ;
}
if ( V_108 != 1 )
return 1 ;
V_8 -> V_12 . V_110 = V_108 ;
V_8 -> V_12 . V_107 = V_107 ;
F_60 ( V_111 , V_8 ) ;
return 0 ;
}
void F_61 ( struct V_1 * V_2 , long V_107 )
{
unsigned char V_112 ;
unsigned char T_1 * V_113 ;
unsigned char T_1 * V_101 ;
unsigned short V_39 , V_43 , V_114 ;
int V_115 , V_116 ;
struct V_82 * V_117 = & V_8 -> V_12 . V_11 -> V_22 ;
#define F_62 \
if (vmpi->vm86dbg_active && vmpi->vm86dbg_TFpendig) \
newflags |= X86_EFLAGS_TF
V_114 = * ( unsigned short * ) & V_2 -> V_16 . V_17 ;
V_113 = ( unsigned char T_1 * ) ( V_2 -> V_16 . V_41 << 4 ) ;
V_101 = ( unsigned char T_1 * ) ( V_2 -> V_16 . V_45 << 4 ) ;
V_43 = F_58 ( V_2 ) ;
V_39 = F_57 ( V_2 ) ;
V_115 = 0 ;
V_116 = 0 ;
do {
switch ( V_112 = F_63 ( V_113 , V_39 , V_118 ) ) {
case 0x66 : V_115 = 1 ; break;
case 0x67 : break;
case 0x2e : break;
case 0x3e : break;
case 0x26 : break;
case 0x36 : break;
case 0x65 : break;
case 0x64 : break;
case 0xf2 : break;
case 0xf3 : break;
default: V_116 = 1 ;
}
} while ( ! V_116 );
switch ( V_112 ) {
case 0x9c :
if ( V_115 ) {
F_64 ( V_101 , V_43 , F_51 ( V_2 ) , V_118 ) ;
F_58 ( V_2 ) -= 4 ;
} else {
F_56 ( V_101 , V_43 , F_51 ( V_2 ) , V_118 ) ;
F_58 ( V_2 ) -= 2 ;
}
F_57 ( V_2 ) = V_39 ;
goto V_119;
case 0x9d :
{
unsigned long V_120 ;
if ( V_115 ) {
V_120 = F_65 ( V_101 , V_43 , V_118 ) ;
F_58 ( V_2 ) += 4 ;
} else {
V_120 = F_66 ( V_101 , V_43 , V_118 ) ;
F_58 ( V_2 ) += 2 ;
}
F_57 ( V_2 ) = V_39 ;
F_62 ;
if ( V_115 )
F_49 ( V_120 , V_2 ) ;
else
F_50 ( V_120 , V_2 ) ;
goto V_121;
}
case 0xcd : {
int V_122 = F_63 ( V_113 , V_39 , V_118 ) ;
F_57 ( V_2 ) = V_39 ;
if ( V_117 -> V_123 ) {
if ( ( 1 << ( V_122 & 7 ) ) & V_117 -> V_124 [ V_122 >> 3 ] ) {
F_1 ( V_2 , V_106 + ( V_122 << 8 ) ) ;
return;
}
}
F_53 ( V_2 , V_122 , V_101 , V_43 ) ;
return;
}
case 0xcf :
{
unsigned long V_125 ;
unsigned long V_126 ;
unsigned long V_120 ;
if ( V_115 ) {
V_125 = F_65 ( V_101 , V_43 , V_118 ) ;
V_126 = F_65 ( V_101 , V_43 , V_118 ) ;
V_120 = F_65 ( V_101 , V_43 , V_118 ) ;
F_58 ( V_2 ) += 12 ;
} else {
V_125 = F_66 ( V_101 , V_43 , V_118 ) ;
V_126 = F_66 ( V_101 , V_43 , V_118 ) ;
V_120 = F_66 ( V_101 , V_43 , V_118 ) ;
F_58 ( V_2 ) += 6 ;
}
F_57 ( V_2 ) = V_125 ;
V_2 -> V_16 . V_41 = V_126 ;
F_62 ;
if ( V_115 ) {
F_49 ( V_120 , V_2 ) ;
} else {
F_50 ( V_120 , V_2 ) ;
}
goto V_121;
}
case 0xfa :
F_57 ( V_2 ) = V_39 ;
F_46 ( V_2 ) ;
goto V_119;
case 0xfb :
F_57 ( V_2 ) = V_39 ;
F_45 ( V_2 ) ;
goto V_121;
default:
F_1 ( V_2 , V_127 ) ;
}
return;
V_121:
if ( V_18 & V_128 ) {
F_1 ( V_2 , V_129 ) ;
return;
}
V_119:
if ( V_117 -> V_130 && ( V_18 & ( V_96 | V_19 ) ) ) {
F_1 ( V_2 , V_131 ) ;
return;
}
if ( V_114 & V_95 )
F_59 ( V_2 , 0 , V_132 ) ;
return;
V_118:
F_1 ( V_2 , V_127 ) ;
}
static T_7 F_67 ( int V_122 , void * V_133 )
{
int V_134 ;
unsigned long V_17 ;
F_68 ( & V_135 , V_17 ) ;
V_134 = 1 << V_122 ;
if ( ( V_136 & V_134 ) || ! V_137 [ V_122 ] . V_7 )
goto V_67;
V_136 |= V_134 ;
if ( V_137 [ V_122 ] . V_138 )
F_69 ( V_137 [ V_122 ] . V_138 , V_137 [ V_122 ] . V_7 , 1 ) ;
F_70 ( V_122 ) ;
F_71 ( & V_135 , V_17 ) ;
return V_139 ;
V_67:
F_71 ( & V_135 , V_17 ) ;
return V_140 ;
}
static inline void F_72 ( int V_141 )
{
unsigned long V_17 ;
F_73 ( V_141 , NULL ) ;
V_137 [ V_141 ] . V_7 = NULL ;
F_68 ( & V_135 , V_17 ) ;
V_136 &= ~ ( 1 << V_141 ) ;
F_71 ( & V_135 , V_17 ) ;
}
void F_74 ( struct V_6 * V_142 )
{
int V_65 ;
for ( V_65 = V_143 ; V_65 <= V_144 ; V_65 ++ )
if ( V_137 [ V_65 ] . V_7 == V_142 )
F_72 ( V_65 ) ;
}
static inline int F_75 ( int V_141 )
{
int V_145 ;
unsigned long V_17 ;
int V_146 = 0 ;
if ( F_76 ( V_141 ) ) return 0 ;
if ( V_137 [ V_141 ] . V_7 != V_8 ) return 0 ;
F_68 ( & V_135 , V_17 ) ;
V_145 = V_136 & ( 1 << V_141 ) ;
V_136 &= ~ V_145 ;
if ( V_145 ) {
F_77 ( V_141 ) ;
V_146 = 1 ;
}
F_71 ( & V_135 , V_17 ) ;
return V_146 ;
}
static int F_78 ( int V_147 , int V_141 )
{
int V_146 ;
switch ( V_147 ) {
case V_148 : {
return F_75 ( V_141 ) ;
}
case V_149 : {
return V_136 ;
}
case V_150 : {
int V_138 = V_141 >> 8 ;
int V_151 = V_141 & 255 ;
if ( ! F_79 ( V_152 ) ) return - V_72 ;
if ( ! ( ( 1 << V_138 ) & V_153 ) ) return - V_72 ;
if ( F_76 ( V_151 ) ) return - V_72 ;
if ( V_137 [ V_151 ] . V_7 ) return - V_72 ;
V_146 = F_80 ( V_151 , & F_67 , 0 , V_154 , NULL ) ;
if ( V_146 ) return V_146 ;
V_137 [ V_151 ] . V_138 = V_138 ;
V_137 [ V_151 ] . V_7 = V_8 ;
return V_151 ;
}
case V_155 : {
if ( F_76 ( V_141 ) ) return - V_72 ;
if ( ! V_137 [ V_141 ] . V_7 ) return 0 ;
if ( V_137 [ V_141 ] . V_7 != V_8 ) return - V_72 ;
F_72 ( V_141 ) ;
return 0 ;
}
}
return - V_156 ;
}
