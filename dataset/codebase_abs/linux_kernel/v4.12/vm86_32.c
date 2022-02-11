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
struct V_60 * V_61 ;
T_2 * V_62 ;
T_3 * V_63 ;
T_4 * V_64 ;
T_5 * V_65 ;
T_6 * V_66 ;
T_7 * V_67 ;
int V_68 ;
F_16 ( & V_59 -> V_69 ) ;
V_63 = F_17 ( V_59 , 0xA0000 ) ;
if ( F_18 ( V_63 ) )
goto V_70;
V_64 = F_19 ( V_63 , 0xA0000 ) ;
if ( F_20 ( V_64 ) )
goto V_70;
V_65 = F_21 ( V_64 , 0xA0000 ) ;
if ( F_22 ( V_65 ) )
goto V_70;
V_66 = F_23 ( V_65 , 0xA0000 ) ;
if ( F_24 ( * V_66 ) ) {
V_61 = F_25 ( V_59 , 0xA0000 ) ;
F_26 ( V_61 , V_66 , 0xA0000 ) ;
}
if ( F_27 ( V_66 ) )
goto V_70;
V_67 = F_28 ( V_59 , V_66 , 0xA0000 , & V_62 ) ;
for ( V_68 = 0 ; V_68 < 32 ; V_68 ++ ) {
if ( F_29 ( * V_67 ) )
F_30 ( V_67 , F_31 ( * V_67 ) ) ;
V_67 ++ ;
}
F_32 ( V_67 , V_62 ) ;
V_70:
F_33 ( & V_59 -> V_69 ) ;
F_34 ( V_59 , 0xA0000 , 0xA0000 + 32 * V_71 , 0UL ) ;
}
static long F_35 ( struct V_9 T_1 * V_14 , bool V_72 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 = V_8 ;
struct V_11 * V_11 = V_7 -> V_12 . V_11 ;
struct V_1 V_73 ;
struct V_57 * V_2 = F_36 () ;
unsigned long V_13 = 0 ;
V_13 = F_37 ( 0 ) ;
if ( V_13 ) {
F_38 ( L_3 ,
V_8 -> V_74 , F_39 ( V_8 ) ,
F_40 ( & V_75 , F_41 () ) ) ;
return - V_76 ;
}
if ( ! V_11 ) {
if ( ! ( V_11 = F_42 ( sizeof( * V_11 ) , V_77 ) ) )
return - V_78 ;
V_7 -> V_12 . V_11 = V_11 ;
}
if ( V_11 -> V_53 )
return - V_76 ;
if ( ! F_6 ( V_79 , V_14 , V_72 ?
sizeof( struct V_24 ) :
sizeof( struct V_9 ) ) )
return - V_80 ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
F_43 {
unsigned short V_81 ;
F_44 ( V_73 . V_16 . V_25 , & V_14 -> V_2 . V_26 ) ;
F_44 ( V_73 . V_16 . V_27 , & V_14 -> V_2 . V_28 ) ;
F_44 ( V_73 . V_16 . V_29 , & V_14 -> V_2 . V_30 ) ;
F_44 ( V_73 . V_16 . V_31 , & V_14 -> V_2 . V_32 ) ;
F_44 ( V_73 . V_16 . V_33 , & V_14 -> V_2 . V_34 ) ;
F_44 ( V_73 . V_16 . V_35 , & V_14 -> V_2 . V_36 ) ;
F_44 ( V_73 . V_16 . V_37 , & V_14 -> V_2 . V_38 ) ;
F_44 ( V_73 . V_16 . V_39 , & V_14 -> V_2 . V_40 ) ;
F_44 ( V_81 , & V_14 -> V_2 . V_41 ) ;
V_73 . V_16 . V_41 = V_81 ;
F_44 ( V_73 . V_16 . V_17 , & V_14 -> V_2 . V_42 ) ;
F_44 ( V_73 . V_16 . V_43 , & V_14 -> V_2 . V_44 ) ;
F_44 ( V_81 , & V_14 -> V_2 . V_45 ) ;
V_73 . V_16 . V_45 = V_81 ;
F_44 ( V_73 . V_46 , & V_14 -> V_2 . V_46 ) ;
F_44 ( V_73 . V_47 , & V_14 -> V_2 . V_47 ) ;
F_44 ( V_73 . V_48 , & V_14 -> V_2 . V_48 ) ;
F_44 ( V_73 . V_49 , & V_14 -> V_2 . V_49 ) ;
F_44 ( V_11 -> V_17 , & V_14 -> V_17 ) ;
F_44 ( V_11 -> V_50 , & V_14 -> V_50 ) ;
F_44 ( V_11 -> V_82 , & V_14 -> V_82 ) ;
} F_45 ( V_13 ) ;
if ( V_13 )
return V_13 ;
if ( F_46 ( & V_11 -> V_83 ,
& V_14 -> V_83 ,
sizeof( struct V_84 ) ) )
return - V_80 ;
if ( F_46 ( & V_11 -> V_85 ,
& V_14 -> V_85 ,
sizeof( struct V_84 ) ) )
return - V_80 ;
if ( V_72 ) {
if ( F_46 ( & V_11 -> V_22 , & V_14 -> V_22 ,
sizeof( struct V_86 ) ) )
return - V_80 ;
V_11 -> V_22 . V_23 = 1 ;
} else
memset ( & V_11 -> V_22 , 0 ,
sizeof( struct V_86 ) ) ;
memcpy ( & V_11 -> V_56 , V_2 , sizeof( struct V_57 ) ) ;
V_11 -> V_14 = V_14 ;
V_18 = V_73 . V_16 . V_17 ;
V_73 . V_16 . V_17 &= V_87 ;
V_73 . V_16 . V_17 |= V_2 -> V_17 & ~ V_87 ;
V_73 . V_16 . V_17 |= V_88 ;
V_73 . V_16 . V_89 = V_2 -> V_89 ;
switch ( V_11 -> V_82 ) {
case V_90 :
V_11 -> V_20 = 0 ;
break;
case V_91 :
V_11 -> V_20 = V_92 | V_93 ;
break;
case V_94 :
V_11 -> V_20 = V_95 | V_92 | V_93 ;
break;
default:
V_11 -> V_20 = V_96 | V_95 | V_92 | V_93 ;
break;
}
V_11 -> V_53 = V_7 -> V_12 . V_52 ;
F_47 ( V_11 -> V_56 . V_49 ) ;
V_5 = & F_10 ( V_51 , F_11 () ) ;
V_7 -> V_12 . V_52 += 16 ;
if ( F_48 ( V_97 ) )
V_7 -> V_12 . V_54 = 0 ;
F_12 ( V_5 , & V_7 -> V_12 ) ;
F_13 () ;
if ( V_11 -> V_17 & V_98 )
F_15 ( V_7 -> V_59 ) ;
memcpy ( (struct V_1 * ) V_2 , & V_73 , sizeof( V_73 ) ) ;
F_49 () ;
return V_2 -> V_37 ;
}
static inline void F_50 ( struct V_1 * V_2 )
{
V_18 |= V_19 ;
}
static inline void F_51 ( struct V_1 * V_2 )
{
V_18 &= ~ V_19 ;
}
static inline void F_52 ( struct V_1 * V_2 )
{
V_2 -> V_16 . V_17 &= ~ V_99 ;
}
static inline void F_53 ( struct V_1 * V_2 )
{
V_2 -> V_16 . V_17 &= ~ V_95 ;
}
static inline void F_54 ( unsigned long V_17 , struct V_1 * V_2 )
{
F_5 ( V_18 , V_17 , V_8 -> V_12 . V_11 -> V_20 ) ;
F_5 ( V_2 -> V_16 . V_17 , V_17 , V_87 ) ;
if ( V_17 & V_100 )
F_50 ( V_2 ) ;
else
F_51 ( V_2 ) ;
}
static inline void F_55 ( unsigned short V_17 , struct V_1 * V_2 )
{
F_5 ( V_101 , V_17 , V_8 -> V_12 . V_11 -> V_20 ) ;
F_5 ( V_2 -> V_16 . V_17 , V_17 , V_87 ) ;
if ( V_17 & V_100 )
F_50 ( V_2 ) ;
else
F_51 ( V_2 ) ;
}
static inline unsigned long F_56 ( struct V_1 * V_2 )
{
unsigned long V_17 = V_2 -> V_16 . V_17 & V_102 ;
if ( V_18 & V_19 )
V_17 |= V_100 ;
V_17 |= V_93 ;
return V_17 | ( V_18 & V_8 -> V_12 . V_11 -> V_20 ) ;
}
static inline int F_57 ( int V_103 , struct V_84 * V_104 )
{
return F_58 ( V_103 , V_104 -> V_105 ) ;
}
static void F_59 ( struct V_1 * V_2 , int V_68 ,
unsigned char T_1 * V_106 , unsigned short V_43 )
{
unsigned long T_1 * V_107 ;
unsigned long V_108 ;
struct V_11 * V_11 = V_8 -> V_12 . V_11 ;
if ( V_2 -> V_16 . V_41 == V_109 )
goto V_110;
if ( F_57 ( V_68 , & V_11 -> V_83 ) )
goto V_110;
if ( V_68 == 0x21 && F_57 ( F_60 ( V_2 ) , & V_11 -> V_85 ) )
goto V_110;
V_107 = ( unsigned long T_1 * ) ( V_68 << 2 ) ;
if ( F_61 ( V_108 , V_107 ) )
goto V_110;
if ( ( V_108 >> 16 ) == V_109 )
goto V_110;
F_62 ( V_106 , V_43 , F_56 ( V_2 ) , V_110 ) ;
F_62 ( V_106 , V_43 , V_2 -> V_16 . V_41 , V_110 ) ;
F_62 ( V_106 , V_43 , F_63 ( V_2 ) , V_110 ) ;
V_2 -> V_16 . V_41 = V_108 >> 16 ;
F_64 ( V_2 ) -= 6 ;
F_63 ( V_2 ) = V_108 & 0xffff ;
F_52 ( V_2 ) ;
F_51 ( V_2 ) ;
F_53 ( V_2 ) ;
return;
V_110:
F_1 ( V_2 , V_111 + ( V_68 << 8 ) ) ;
}
int F_65 ( struct V_1 * V_2 , long V_112 , int V_113 )
{
struct V_11 * V_11 = V_8 -> V_12 . V_11 ;
if ( V_11 -> V_22 . V_23 ) {
if ( ( V_113 == 3 ) || ( V_113 == 1 ) ) {
F_1 ( V_2 , V_114 + ( V_113 << 8 ) ) ;
return 0 ;
}
F_59 ( V_2 , V_113 , ( unsigned char T_1 * ) ( V_2 -> V_16 . V_45 << 4 ) , F_64 ( V_2 ) ) ;
return 0 ;
}
if ( V_113 != 1 )
return 1 ;
V_8 -> V_12 . V_115 = V_113 ;
V_8 -> V_12 . V_112 = V_112 ;
F_66 ( V_116 , V_8 ) ;
return 0 ;
}
void F_67 ( struct V_1 * V_2 , long V_112 )
{
unsigned char V_117 ;
unsigned char T_1 * V_118 ;
unsigned char T_1 * V_106 ;
unsigned short V_39 , V_43 , V_119 ;
int V_120 , V_121 ;
struct V_86 * V_122 = & V_8 -> V_12 . V_11 -> V_22 ;
#define F_68 \
if (vmpi->vm86dbg_active && vmpi->vm86dbg_TFpendig) \
newflags |= X86_EFLAGS_TF
V_119 = * ( unsigned short * ) & V_2 -> V_16 . V_17 ;
V_118 = ( unsigned char T_1 * ) ( V_2 -> V_16 . V_41 << 4 ) ;
V_106 = ( unsigned char T_1 * ) ( V_2 -> V_16 . V_45 << 4 ) ;
V_43 = F_64 ( V_2 ) ;
V_39 = F_63 ( V_2 ) ;
V_120 = 0 ;
V_121 = 0 ;
do {
switch ( V_117 = F_69 ( V_118 , V_39 , V_123 ) ) {
case 0x66 : V_120 = 1 ; break;
case 0x67 : break;
case 0x2e : break;
case 0x3e : break;
case 0x26 : break;
case 0x36 : break;
case 0x65 : break;
case 0x64 : break;
case 0xf2 : break;
case 0xf3 : break;
default: V_121 = 1 ;
}
} while ( ! V_121 );
switch ( V_117 ) {
case 0x9c :
if ( V_120 ) {
F_70 ( V_106 , V_43 , F_56 ( V_2 ) , V_123 ) ;
F_64 ( V_2 ) -= 4 ;
} else {
F_62 ( V_106 , V_43 , F_56 ( V_2 ) , V_123 ) ;
F_64 ( V_2 ) -= 2 ;
}
F_63 ( V_2 ) = V_39 ;
goto V_124;
case 0x9d :
{
unsigned long V_125 ;
if ( V_120 ) {
V_125 = F_71 ( V_106 , V_43 , V_123 ) ;
F_64 ( V_2 ) += 4 ;
} else {
V_125 = F_72 ( V_106 , V_43 , V_123 ) ;
F_64 ( V_2 ) += 2 ;
}
F_63 ( V_2 ) = V_39 ;
F_68 ;
if ( V_120 )
F_54 ( V_125 , V_2 ) ;
else
F_55 ( V_125 , V_2 ) ;
goto V_126;
}
case 0xcd : {
int V_127 = F_69 ( V_118 , V_39 , V_123 ) ;
F_63 ( V_2 ) = V_39 ;
if ( V_122 -> V_128 ) {
if ( ( 1 << ( V_127 & 7 ) ) & V_122 -> V_129 [ V_127 >> 3 ] ) {
F_1 ( V_2 , V_111 + ( V_127 << 8 ) ) ;
return;
}
}
F_59 ( V_2 , V_127 , V_106 , V_43 ) ;
return;
}
case 0xcf :
{
unsigned long V_130 ;
unsigned long V_131 ;
unsigned long V_125 ;
if ( V_120 ) {
V_130 = F_71 ( V_106 , V_43 , V_123 ) ;
V_131 = F_71 ( V_106 , V_43 , V_123 ) ;
V_125 = F_71 ( V_106 , V_43 , V_123 ) ;
F_64 ( V_2 ) += 12 ;
} else {
V_130 = F_72 ( V_106 , V_43 , V_123 ) ;
V_131 = F_72 ( V_106 , V_43 , V_123 ) ;
V_125 = F_72 ( V_106 , V_43 , V_123 ) ;
F_64 ( V_2 ) += 6 ;
}
F_63 ( V_2 ) = V_130 ;
V_2 -> V_16 . V_41 = V_131 ;
F_68 ;
if ( V_120 ) {
F_54 ( V_125 , V_2 ) ;
} else {
F_55 ( V_125 , V_2 ) ;
}
goto V_126;
}
case 0xfa :
F_63 ( V_2 ) = V_39 ;
F_51 ( V_2 ) ;
goto V_124;
case 0xfb :
F_63 ( V_2 ) = V_39 ;
F_50 ( V_2 ) ;
goto V_126;
default:
F_1 ( V_2 , V_132 ) ;
}
return;
V_126:
if ( V_18 & V_133 ) {
F_1 ( V_2 , V_134 ) ;
return;
}
V_124:
if ( V_122 -> V_135 && ( V_18 & ( V_100 | V_19 ) ) ) {
F_1 ( V_2 , V_136 ) ;
return;
}
if ( V_119 & V_99 )
F_65 ( V_2 , 0 , V_137 ) ;
return;
V_123:
F_1 ( V_2 , V_132 ) ;
}
static T_8 F_73 ( int V_127 , void * V_138 )
{
int V_139 ;
unsigned long V_17 ;
F_74 ( & V_140 , V_17 ) ;
V_139 = 1 << V_127 ;
if ( ( V_141 & V_139 ) || ! V_142 [ V_127 ] . V_7 )
goto V_70;
V_141 |= V_139 ;
if ( V_142 [ V_127 ] . V_143 )
F_75 ( V_142 [ V_127 ] . V_143 , V_142 [ V_127 ] . V_7 , 1 ) ;
F_76 ( V_127 ) ;
F_77 ( & V_140 , V_17 ) ;
return V_144 ;
V_70:
F_77 ( & V_140 , V_17 ) ;
return V_145 ;
}
static inline void F_78 ( int V_146 )
{
unsigned long V_17 ;
F_79 ( V_146 , NULL ) ;
V_142 [ V_146 ] . V_7 = NULL ;
F_74 ( & V_140 , V_17 ) ;
V_141 &= ~ ( 1 << V_146 ) ;
F_77 ( & V_140 , V_17 ) ;
}
void F_80 ( struct V_6 * V_147 )
{
int V_68 ;
for ( V_68 = V_148 ; V_68 <= V_149 ; V_68 ++ )
if ( V_142 [ V_68 ] . V_7 == V_147 )
F_78 ( V_68 ) ;
}
static inline int F_81 ( int V_146 )
{
int V_150 ;
unsigned long V_17 ;
int V_151 = 0 ;
if ( F_82 ( V_146 ) ) return 0 ;
if ( V_142 [ V_146 ] . V_7 != V_8 ) return 0 ;
F_74 ( & V_140 , V_17 ) ;
V_150 = V_141 & ( 1 << V_146 ) ;
V_141 &= ~ V_150 ;
if ( V_150 ) {
F_83 ( V_146 ) ;
V_151 = 1 ;
}
F_77 ( & V_140 , V_17 ) ;
return V_151 ;
}
static int F_84 ( int V_152 , int V_146 )
{
int V_151 ;
switch ( V_152 ) {
case V_153 : {
return F_81 ( V_146 ) ;
}
case V_154 : {
return V_141 ;
}
case V_155 : {
int V_143 = V_146 >> 8 ;
int V_156 = V_146 & 255 ;
if ( ! F_85 ( V_157 ) ) return - V_76 ;
if ( ! ( ( 1 << V_143 ) & V_158 ) ) return - V_76 ;
if ( F_82 ( V_156 ) ) return - V_76 ;
if ( V_142 [ V_156 ] . V_7 ) return - V_76 ;
V_151 = F_86 ( V_156 , & F_73 , 0 , V_159 , NULL ) ;
if ( V_151 ) return V_151 ;
V_142 [ V_156 ] . V_143 = V_143 ;
V_142 [ V_156 ] . V_7 = V_8 ;
return V_156 ;
}
case V_160 : {
if ( F_82 ( V_146 ) ) return - V_76 ;
if ( ! V_142 [ V_146 ] . V_7 ) return 0 ;
if ( V_142 [ V_146 ] . V_7 != V_8 ) return - V_76 ;
F_78 ( V_146 ) ;
return 0 ;
}
}
return - V_161 ;
}
