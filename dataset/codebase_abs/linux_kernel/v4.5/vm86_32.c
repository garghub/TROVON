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
if ( F_22 ( * V_62 ) ) {
struct V_68 * V_69 = F_23 ( V_59 , 0xA0000 ) ;
F_24 ( V_69 , V_62 , 0xA0000 ) ;
}
if ( F_25 ( V_62 ) )
goto V_67;
V_63 = F_26 ( V_59 , V_62 , 0xA0000 , & V_64 ) ;
for ( V_65 = 0 ; V_65 < 32 ; V_65 ++ ) {
if ( F_27 ( * V_63 ) )
F_28 ( V_63 , F_29 ( * V_63 ) ) ;
V_63 ++ ;
}
F_30 ( V_63 , V_64 ) ;
V_67:
F_31 ( & V_59 -> V_66 ) ;
F_32 () ;
}
static long F_33 ( struct V_9 T_1 * V_14 , bool V_70 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 = V_8 ;
struct V_11 * V_11 = V_7 -> V_12 . V_11 ;
struct V_1 V_71 ;
struct V_57 * V_2 = F_34 () ;
unsigned long V_13 = 0 ;
V_13 = F_35 ( 0 ) ;
if ( V_13 ) {
F_36 ( L_3 ,
V_8 -> V_72 , F_37 ( V_8 ) ,
F_38 ( & V_73 , F_39 () ) ) ;
return - V_74 ;
}
if ( ! V_11 ) {
if ( ! ( V_11 = F_40 ( sizeof( * V_11 ) , V_75 ) ) )
return - V_76 ;
V_7 -> V_12 . V_11 = V_11 ;
}
if ( V_11 -> V_53 )
return - V_74 ;
if ( ! F_6 ( V_77 , V_14 , V_70 ?
sizeof( struct V_24 ) :
sizeof( struct V_9 ) ) )
return - V_78 ;
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
F_41 {
unsigned short V_79 ;
F_42 ( V_71 . V_16 . V_25 , & V_14 -> V_2 . V_26 ) ;
F_42 ( V_71 . V_16 . V_27 , & V_14 -> V_2 . V_28 ) ;
F_42 ( V_71 . V_16 . V_29 , & V_14 -> V_2 . V_30 ) ;
F_42 ( V_71 . V_16 . V_31 , & V_14 -> V_2 . V_32 ) ;
F_42 ( V_71 . V_16 . V_33 , & V_14 -> V_2 . V_34 ) ;
F_42 ( V_71 . V_16 . V_35 , & V_14 -> V_2 . V_36 ) ;
F_42 ( V_71 . V_16 . V_37 , & V_14 -> V_2 . V_38 ) ;
F_42 ( V_71 . V_16 . V_39 , & V_14 -> V_2 . V_40 ) ;
F_42 ( V_79 , & V_14 -> V_2 . V_41 ) ;
V_71 . V_16 . V_41 = V_79 ;
F_42 ( V_71 . V_16 . V_17 , & V_14 -> V_2 . V_42 ) ;
F_42 ( V_71 . V_16 . V_43 , & V_14 -> V_2 . V_44 ) ;
F_42 ( V_79 , & V_14 -> V_2 . V_45 ) ;
V_71 . V_16 . V_45 = V_79 ;
F_42 ( V_71 . V_46 , & V_14 -> V_2 . V_46 ) ;
F_42 ( V_71 . V_47 , & V_14 -> V_2 . V_47 ) ;
F_42 ( V_71 . V_48 , & V_14 -> V_2 . V_48 ) ;
F_42 ( V_71 . V_49 , & V_14 -> V_2 . V_49 ) ;
F_42 ( V_11 -> V_17 , & V_14 -> V_17 ) ;
F_42 ( V_11 -> V_50 , & V_14 -> V_50 ) ;
F_42 ( V_11 -> V_80 , & V_14 -> V_80 ) ;
} F_43 ( V_13 ) ;
if ( V_13 )
return V_13 ;
if ( F_44 ( & V_11 -> V_81 ,
& V_14 -> V_81 ,
sizeof( struct V_82 ) ) )
return - V_78 ;
if ( F_44 ( & V_11 -> V_83 ,
& V_14 -> V_83 ,
sizeof( struct V_82 ) ) )
return - V_78 ;
if ( V_70 ) {
if ( F_44 ( & V_11 -> V_22 , & V_14 -> V_22 ,
sizeof( struct V_84 ) ) )
return - V_78 ;
V_11 -> V_22 . V_23 = 1 ;
} else
memset ( & V_11 -> V_22 , 0 ,
sizeof( struct V_84 ) ) ;
memcpy ( & V_11 -> V_56 , V_2 , sizeof( struct V_57 ) ) ;
V_11 -> V_14 = V_14 ;
V_18 = V_71 . V_16 . V_17 ;
V_71 . V_16 . V_17 &= V_85 ;
V_71 . V_16 . V_17 |= V_2 -> V_17 & ~ V_85 ;
V_71 . V_16 . V_17 |= V_86 ;
V_71 . V_16 . V_87 = V_2 -> V_87 ;
switch ( V_11 -> V_80 ) {
case V_88 :
V_11 -> V_20 = 0 ;
break;
case V_89 :
V_11 -> V_20 = V_90 | V_91 ;
break;
case V_92 :
V_11 -> V_20 = V_93 | V_90 | V_91 ;
break;
default:
V_11 -> V_20 = V_94 | V_93 | V_90 | V_91 ;
break;
}
V_11 -> V_53 = V_7 -> V_12 . V_52 ;
F_45 ( V_11 -> V_56 . V_49 ) ;
V_5 = & F_10 ( V_51 , F_11 () ) ;
V_7 -> V_12 . V_52 += 16 ;
if ( F_46 ( V_95 ) )
V_7 -> V_12 . V_54 = 0 ;
F_12 ( V_5 , & V_7 -> V_12 ) ;
F_13 () ;
if ( V_11 -> V_17 & V_96 )
F_15 ( V_7 -> V_59 ) ;
memcpy ( (struct V_1 * ) V_2 , & V_71 , sizeof( V_71 ) ) ;
F_47 () ;
return V_2 -> V_37 ;
}
static inline void F_48 ( struct V_1 * V_2 )
{
V_18 |= V_19 ;
}
static inline void F_49 ( struct V_1 * V_2 )
{
V_18 &= ~ V_19 ;
}
static inline void F_50 ( struct V_1 * V_2 )
{
V_2 -> V_16 . V_17 &= ~ V_97 ;
}
static inline void F_51 ( struct V_1 * V_2 )
{
V_2 -> V_16 . V_17 &= ~ V_93 ;
}
static inline void F_52 ( unsigned long V_17 , struct V_1 * V_2 )
{
F_5 ( V_18 , V_17 , V_8 -> V_12 . V_11 -> V_20 ) ;
F_5 ( V_2 -> V_16 . V_17 , V_17 , V_85 ) ;
if ( V_17 & V_98 )
F_48 ( V_2 ) ;
else
F_49 ( V_2 ) ;
}
static inline void F_53 ( unsigned short V_17 , struct V_1 * V_2 )
{
F_5 ( V_99 , V_17 , V_8 -> V_12 . V_11 -> V_20 ) ;
F_5 ( V_2 -> V_16 . V_17 , V_17 , V_85 ) ;
if ( V_17 & V_98 )
F_48 ( V_2 ) ;
else
F_49 ( V_2 ) ;
}
static inline unsigned long F_54 ( struct V_1 * V_2 )
{
unsigned long V_17 = V_2 -> V_16 . V_17 & V_100 ;
if ( V_18 & V_19 )
V_17 |= V_98 ;
V_17 |= V_91 ;
return V_17 | ( V_18 & V_8 -> V_12 . V_11 -> V_20 ) ;
}
static inline int F_55 ( int V_101 , struct V_82 * V_102 )
{
__asm__ __volatile__("btl %2,%1\n\tsbbl %0,%0"
:"=r" (nr)
:"m" (*bitmap), "r" (nr));
return V_101 ;
}
static void F_56 ( struct V_1 * V_2 , int V_65 ,
unsigned char T_1 * V_103 , unsigned short V_43 )
{
unsigned long T_1 * V_104 ;
unsigned long V_105 ;
struct V_11 * V_11 = V_8 -> V_12 . V_11 ;
if ( V_2 -> V_16 . V_41 == V_106 )
goto V_107;
if ( F_55 ( V_65 , & V_11 -> V_81 ) )
goto V_107;
if ( V_65 == 0x21 && F_55 ( F_57 ( V_2 ) , & V_11 -> V_83 ) )
goto V_107;
V_104 = ( unsigned long T_1 * ) ( V_65 << 2 ) ;
if ( F_58 ( V_105 , V_104 ) )
goto V_107;
if ( ( V_105 >> 16 ) == V_106 )
goto V_107;
F_59 ( V_103 , V_43 , F_54 ( V_2 ) , V_107 ) ;
F_59 ( V_103 , V_43 , V_2 -> V_16 . V_41 , V_107 ) ;
F_59 ( V_103 , V_43 , F_60 ( V_2 ) , V_107 ) ;
V_2 -> V_16 . V_41 = V_105 >> 16 ;
F_61 ( V_2 ) -= 6 ;
F_60 ( V_2 ) = V_105 & 0xffff ;
F_50 ( V_2 ) ;
F_49 ( V_2 ) ;
F_51 ( V_2 ) ;
return;
V_107:
F_1 ( V_2 , V_108 + ( V_65 << 8 ) ) ;
}
int F_62 ( struct V_1 * V_2 , long V_109 , int V_110 )
{
struct V_11 * V_11 = V_8 -> V_12 . V_11 ;
if ( V_11 -> V_22 . V_23 ) {
if ( ( V_110 == 3 ) || ( V_110 == 1 ) ) {
F_1 ( V_2 , V_111 + ( V_110 << 8 ) ) ;
return 0 ;
}
F_56 ( V_2 , V_110 , ( unsigned char T_1 * ) ( V_2 -> V_16 . V_45 << 4 ) , F_61 ( V_2 ) ) ;
return 0 ;
}
if ( V_110 != 1 )
return 1 ;
V_8 -> V_12 . V_112 = V_110 ;
V_8 -> V_12 . V_109 = V_109 ;
F_63 ( V_113 , V_8 ) ;
return 0 ;
}
void F_64 ( struct V_1 * V_2 , long V_109 )
{
unsigned char V_114 ;
unsigned char T_1 * V_115 ;
unsigned char T_1 * V_103 ;
unsigned short V_39 , V_43 , V_116 ;
int V_117 , V_118 ;
struct V_84 * V_119 = & V_8 -> V_12 . V_11 -> V_22 ;
#define F_65 \
if (vmpi->vm86dbg_active && vmpi->vm86dbg_TFpendig) \
newflags |= X86_EFLAGS_TF
V_116 = * ( unsigned short * ) & V_2 -> V_16 . V_17 ;
V_115 = ( unsigned char T_1 * ) ( V_2 -> V_16 . V_41 << 4 ) ;
V_103 = ( unsigned char T_1 * ) ( V_2 -> V_16 . V_45 << 4 ) ;
V_43 = F_61 ( V_2 ) ;
V_39 = F_60 ( V_2 ) ;
V_117 = 0 ;
V_118 = 0 ;
do {
switch ( V_114 = F_66 ( V_115 , V_39 , V_120 ) ) {
case 0x66 : V_117 = 1 ; break;
case 0x67 : break;
case 0x2e : break;
case 0x3e : break;
case 0x26 : break;
case 0x36 : break;
case 0x65 : break;
case 0x64 : break;
case 0xf2 : break;
case 0xf3 : break;
default: V_118 = 1 ;
}
} while ( ! V_118 );
switch ( V_114 ) {
case 0x9c :
if ( V_117 ) {
F_67 ( V_103 , V_43 , F_54 ( V_2 ) , V_120 ) ;
F_61 ( V_2 ) -= 4 ;
} else {
F_59 ( V_103 , V_43 , F_54 ( V_2 ) , V_120 ) ;
F_61 ( V_2 ) -= 2 ;
}
F_60 ( V_2 ) = V_39 ;
goto V_121;
case 0x9d :
{
unsigned long V_122 ;
if ( V_117 ) {
V_122 = F_68 ( V_103 , V_43 , V_120 ) ;
F_61 ( V_2 ) += 4 ;
} else {
V_122 = F_69 ( V_103 , V_43 , V_120 ) ;
F_61 ( V_2 ) += 2 ;
}
F_60 ( V_2 ) = V_39 ;
F_65 ;
if ( V_117 )
F_52 ( V_122 , V_2 ) ;
else
F_53 ( V_122 , V_2 ) ;
goto V_123;
}
case 0xcd : {
int V_124 = F_66 ( V_115 , V_39 , V_120 ) ;
F_60 ( V_2 ) = V_39 ;
if ( V_119 -> V_125 ) {
if ( ( 1 << ( V_124 & 7 ) ) & V_119 -> V_126 [ V_124 >> 3 ] ) {
F_1 ( V_2 , V_108 + ( V_124 << 8 ) ) ;
return;
}
}
F_56 ( V_2 , V_124 , V_103 , V_43 ) ;
return;
}
case 0xcf :
{
unsigned long V_127 ;
unsigned long V_128 ;
unsigned long V_122 ;
if ( V_117 ) {
V_127 = F_68 ( V_103 , V_43 , V_120 ) ;
V_128 = F_68 ( V_103 , V_43 , V_120 ) ;
V_122 = F_68 ( V_103 , V_43 , V_120 ) ;
F_61 ( V_2 ) += 12 ;
} else {
V_127 = F_69 ( V_103 , V_43 , V_120 ) ;
V_128 = F_69 ( V_103 , V_43 , V_120 ) ;
V_122 = F_69 ( V_103 , V_43 , V_120 ) ;
F_61 ( V_2 ) += 6 ;
}
F_60 ( V_2 ) = V_127 ;
V_2 -> V_16 . V_41 = V_128 ;
F_65 ;
if ( V_117 ) {
F_52 ( V_122 , V_2 ) ;
} else {
F_53 ( V_122 , V_2 ) ;
}
goto V_123;
}
case 0xfa :
F_60 ( V_2 ) = V_39 ;
F_49 ( V_2 ) ;
goto V_121;
case 0xfb :
F_60 ( V_2 ) = V_39 ;
F_48 ( V_2 ) ;
goto V_123;
default:
F_1 ( V_2 , V_129 ) ;
}
return;
V_123:
if ( V_18 & V_130 ) {
F_1 ( V_2 , V_131 ) ;
return;
}
V_121:
if ( V_119 -> V_132 && ( V_18 & ( V_98 | V_19 ) ) ) {
F_1 ( V_2 , V_133 ) ;
return;
}
if ( V_116 & V_97 )
F_62 ( V_2 , 0 , V_134 ) ;
return;
V_120:
F_1 ( V_2 , V_129 ) ;
}
static T_7 F_70 ( int V_124 , void * V_135 )
{
int V_136 ;
unsigned long V_17 ;
F_71 ( & V_137 , V_17 ) ;
V_136 = 1 << V_124 ;
if ( ( V_138 & V_136 ) || ! V_139 [ V_124 ] . V_7 )
goto V_67;
V_138 |= V_136 ;
if ( V_139 [ V_124 ] . V_140 )
F_72 ( V_139 [ V_124 ] . V_140 , V_139 [ V_124 ] . V_7 , 1 ) ;
F_73 ( V_124 ) ;
F_74 ( & V_137 , V_17 ) ;
return V_141 ;
V_67:
F_74 ( & V_137 , V_17 ) ;
return V_142 ;
}
static inline void F_75 ( int V_143 )
{
unsigned long V_17 ;
F_76 ( V_143 , NULL ) ;
V_139 [ V_143 ] . V_7 = NULL ;
F_71 ( & V_137 , V_17 ) ;
V_138 &= ~ ( 1 << V_143 ) ;
F_74 ( & V_137 , V_17 ) ;
}
void F_77 ( struct V_6 * V_144 )
{
int V_65 ;
for ( V_65 = V_145 ; V_65 <= V_146 ; V_65 ++ )
if ( V_139 [ V_65 ] . V_7 == V_144 )
F_75 ( V_65 ) ;
}
static inline int F_78 ( int V_143 )
{
int V_147 ;
unsigned long V_17 ;
int V_148 = 0 ;
if ( F_79 ( V_143 ) ) return 0 ;
if ( V_139 [ V_143 ] . V_7 != V_8 ) return 0 ;
F_71 ( & V_137 , V_17 ) ;
V_147 = V_138 & ( 1 << V_143 ) ;
V_138 &= ~ V_147 ;
if ( V_147 ) {
F_80 ( V_143 ) ;
V_148 = 1 ;
}
F_74 ( & V_137 , V_17 ) ;
return V_148 ;
}
static int F_81 ( int V_149 , int V_143 )
{
int V_148 ;
switch ( V_149 ) {
case V_150 : {
return F_78 ( V_143 ) ;
}
case V_151 : {
return V_138 ;
}
case V_152 : {
int V_140 = V_143 >> 8 ;
int V_153 = V_143 & 255 ;
if ( ! F_82 ( V_154 ) ) return - V_74 ;
if ( ! ( ( 1 << V_140 ) & V_155 ) ) return - V_74 ;
if ( F_79 ( V_153 ) ) return - V_74 ;
if ( V_139 [ V_153 ] . V_7 ) return - V_74 ;
V_148 = F_83 ( V_153 , & F_70 , 0 , V_156 , NULL ) ;
if ( V_148 ) return V_148 ;
V_139 [ V_153 ] . V_140 = V_140 ;
V_139 [ V_153 ] . V_7 = V_8 ;
return V_153 ;
}
case V_157 : {
if ( F_79 ( V_143 ) ) return - V_74 ;
if ( ! V_139 [ V_143 ] . V_7 ) return 0 ;
if ( V_139 [ V_143 ] . V_7 != V_8 ) return - V_74 ;
F_75 ( V_143 ) ;
return 0 ;
}
}
return - V_158 ;
}
