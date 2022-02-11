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
int V_67 ;
F_16 ( & V_59 -> V_68 ) ;
V_63 = F_17 ( V_59 , 0xA0000 ) ;
if ( F_18 ( V_63 ) )
goto V_69;
V_64 = F_19 ( V_63 , 0xA0000 ) ;
if ( F_20 ( V_64 ) )
goto V_69;
V_65 = F_21 ( V_64 , 0xA0000 ) ;
if ( F_22 ( * V_65 ) ) {
V_61 = F_23 ( V_59 , 0xA0000 ) ;
F_24 ( V_61 , V_65 , 0xA0000 ) ;
}
if ( F_25 ( V_65 ) )
goto V_69;
V_66 = F_26 ( V_59 , V_65 , 0xA0000 , & V_62 ) ;
for ( V_67 = 0 ; V_67 < 32 ; V_67 ++ ) {
if ( F_27 ( * V_66 ) )
F_28 ( V_66 , F_29 ( * V_66 ) ) ;
V_66 ++ ;
}
F_30 ( V_66 , V_62 ) ;
V_69:
F_31 ( & V_59 -> V_68 ) ;
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
return F_56 ( V_101 , V_102 -> V_103 ) ;
}
static void F_57 ( struct V_1 * V_2 , int V_67 ,
unsigned char T_1 * V_104 , unsigned short V_43 )
{
unsigned long T_1 * V_105 ;
unsigned long V_106 ;
struct V_11 * V_11 = V_8 -> V_12 . V_11 ;
if ( V_2 -> V_16 . V_41 == V_107 )
goto V_108;
if ( F_55 ( V_67 , & V_11 -> V_81 ) )
goto V_108;
if ( V_67 == 0x21 && F_55 ( F_58 ( V_2 ) , & V_11 -> V_83 ) )
goto V_108;
V_105 = ( unsigned long T_1 * ) ( V_67 << 2 ) ;
if ( F_59 ( V_106 , V_105 ) )
goto V_108;
if ( ( V_106 >> 16 ) == V_107 )
goto V_108;
F_60 ( V_104 , V_43 , F_54 ( V_2 ) , V_108 ) ;
F_60 ( V_104 , V_43 , V_2 -> V_16 . V_41 , V_108 ) ;
F_60 ( V_104 , V_43 , F_61 ( V_2 ) , V_108 ) ;
V_2 -> V_16 . V_41 = V_106 >> 16 ;
F_62 ( V_2 ) -= 6 ;
F_61 ( V_2 ) = V_106 & 0xffff ;
F_50 ( V_2 ) ;
F_49 ( V_2 ) ;
F_51 ( V_2 ) ;
return;
V_108:
F_1 ( V_2 , V_109 + ( V_67 << 8 ) ) ;
}
int F_63 ( struct V_1 * V_2 , long V_110 , int V_111 )
{
struct V_11 * V_11 = V_8 -> V_12 . V_11 ;
if ( V_11 -> V_22 . V_23 ) {
if ( ( V_111 == 3 ) || ( V_111 == 1 ) ) {
F_1 ( V_2 , V_112 + ( V_111 << 8 ) ) ;
return 0 ;
}
F_57 ( V_2 , V_111 , ( unsigned char T_1 * ) ( V_2 -> V_16 . V_45 << 4 ) , F_62 ( V_2 ) ) ;
return 0 ;
}
if ( V_111 != 1 )
return 1 ;
V_8 -> V_12 . V_113 = V_111 ;
V_8 -> V_12 . V_110 = V_110 ;
F_64 ( V_114 , V_8 ) ;
return 0 ;
}
void F_65 ( struct V_1 * V_2 , long V_110 )
{
unsigned char V_115 ;
unsigned char T_1 * V_116 ;
unsigned char T_1 * V_104 ;
unsigned short V_39 , V_43 , V_117 ;
int V_118 , V_119 ;
struct V_84 * V_120 = & V_8 -> V_12 . V_11 -> V_22 ;
#define F_66 \
if (vmpi->vm86dbg_active && vmpi->vm86dbg_TFpendig) \
newflags |= X86_EFLAGS_TF
V_117 = * ( unsigned short * ) & V_2 -> V_16 . V_17 ;
V_116 = ( unsigned char T_1 * ) ( V_2 -> V_16 . V_41 << 4 ) ;
V_104 = ( unsigned char T_1 * ) ( V_2 -> V_16 . V_45 << 4 ) ;
V_43 = F_62 ( V_2 ) ;
V_39 = F_61 ( V_2 ) ;
V_118 = 0 ;
V_119 = 0 ;
do {
switch ( V_115 = F_67 ( V_116 , V_39 , V_121 ) ) {
case 0x66 : V_118 = 1 ; break;
case 0x67 : break;
case 0x2e : break;
case 0x3e : break;
case 0x26 : break;
case 0x36 : break;
case 0x65 : break;
case 0x64 : break;
case 0xf2 : break;
case 0xf3 : break;
default: V_119 = 1 ;
}
} while ( ! V_119 );
switch ( V_115 ) {
case 0x9c :
if ( V_118 ) {
F_68 ( V_104 , V_43 , F_54 ( V_2 ) , V_121 ) ;
F_62 ( V_2 ) -= 4 ;
} else {
F_60 ( V_104 , V_43 , F_54 ( V_2 ) , V_121 ) ;
F_62 ( V_2 ) -= 2 ;
}
F_61 ( V_2 ) = V_39 ;
goto V_122;
case 0x9d :
{
unsigned long V_123 ;
if ( V_118 ) {
V_123 = F_69 ( V_104 , V_43 , V_121 ) ;
F_62 ( V_2 ) += 4 ;
} else {
V_123 = F_70 ( V_104 , V_43 , V_121 ) ;
F_62 ( V_2 ) += 2 ;
}
F_61 ( V_2 ) = V_39 ;
F_66 ;
if ( V_118 )
F_52 ( V_123 , V_2 ) ;
else
F_53 ( V_123 , V_2 ) ;
goto V_124;
}
case 0xcd : {
int V_125 = F_67 ( V_116 , V_39 , V_121 ) ;
F_61 ( V_2 ) = V_39 ;
if ( V_120 -> V_126 ) {
if ( ( 1 << ( V_125 & 7 ) ) & V_120 -> V_127 [ V_125 >> 3 ] ) {
F_1 ( V_2 , V_109 + ( V_125 << 8 ) ) ;
return;
}
}
F_57 ( V_2 , V_125 , V_104 , V_43 ) ;
return;
}
case 0xcf :
{
unsigned long V_128 ;
unsigned long V_129 ;
unsigned long V_123 ;
if ( V_118 ) {
V_128 = F_69 ( V_104 , V_43 , V_121 ) ;
V_129 = F_69 ( V_104 , V_43 , V_121 ) ;
V_123 = F_69 ( V_104 , V_43 , V_121 ) ;
F_62 ( V_2 ) += 12 ;
} else {
V_128 = F_70 ( V_104 , V_43 , V_121 ) ;
V_129 = F_70 ( V_104 , V_43 , V_121 ) ;
V_123 = F_70 ( V_104 , V_43 , V_121 ) ;
F_62 ( V_2 ) += 6 ;
}
F_61 ( V_2 ) = V_128 ;
V_2 -> V_16 . V_41 = V_129 ;
F_66 ;
if ( V_118 ) {
F_52 ( V_123 , V_2 ) ;
} else {
F_53 ( V_123 , V_2 ) ;
}
goto V_124;
}
case 0xfa :
F_61 ( V_2 ) = V_39 ;
F_49 ( V_2 ) ;
goto V_122;
case 0xfb :
F_61 ( V_2 ) = V_39 ;
F_48 ( V_2 ) ;
goto V_124;
default:
F_1 ( V_2 , V_130 ) ;
}
return;
V_124:
if ( V_18 & V_131 ) {
F_1 ( V_2 , V_132 ) ;
return;
}
V_122:
if ( V_120 -> V_133 && ( V_18 & ( V_98 | V_19 ) ) ) {
F_1 ( V_2 , V_134 ) ;
return;
}
if ( V_117 & V_97 )
F_63 ( V_2 , 0 , V_135 ) ;
return;
V_121:
F_1 ( V_2 , V_130 ) ;
}
static T_7 F_71 ( int V_125 , void * V_136 )
{
int V_137 ;
unsigned long V_17 ;
F_72 ( & V_138 , V_17 ) ;
V_137 = 1 << V_125 ;
if ( ( V_139 & V_137 ) || ! V_140 [ V_125 ] . V_7 )
goto V_69;
V_139 |= V_137 ;
if ( V_140 [ V_125 ] . V_141 )
F_73 ( V_140 [ V_125 ] . V_141 , V_140 [ V_125 ] . V_7 , 1 ) ;
F_74 ( V_125 ) ;
F_75 ( & V_138 , V_17 ) ;
return V_142 ;
V_69:
F_75 ( & V_138 , V_17 ) ;
return V_143 ;
}
static inline void F_76 ( int V_144 )
{
unsigned long V_17 ;
F_77 ( V_144 , NULL ) ;
V_140 [ V_144 ] . V_7 = NULL ;
F_72 ( & V_138 , V_17 ) ;
V_139 &= ~ ( 1 << V_144 ) ;
F_75 ( & V_138 , V_17 ) ;
}
void F_78 ( struct V_6 * V_145 )
{
int V_67 ;
for ( V_67 = V_146 ; V_67 <= V_147 ; V_67 ++ )
if ( V_140 [ V_67 ] . V_7 == V_145 )
F_76 ( V_67 ) ;
}
static inline int F_79 ( int V_144 )
{
int V_148 ;
unsigned long V_17 ;
int V_149 = 0 ;
if ( F_80 ( V_144 ) ) return 0 ;
if ( V_140 [ V_144 ] . V_7 != V_8 ) return 0 ;
F_72 ( & V_138 , V_17 ) ;
V_148 = V_139 & ( 1 << V_144 ) ;
V_139 &= ~ V_148 ;
if ( V_148 ) {
F_81 ( V_144 ) ;
V_149 = 1 ;
}
F_75 ( & V_138 , V_17 ) ;
return V_149 ;
}
static int F_82 ( int V_150 , int V_144 )
{
int V_149 ;
switch ( V_150 ) {
case V_151 : {
return F_79 ( V_144 ) ;
}
case V_152 : {
return V_139 ;
}
case V_153 : {
int V_141 = V_144 >> 8 ;
int V_154 = V_144 & 255 ;
if ( ! F_83 ( V_155 ) ) return - V_74 ;
if ( ! ( ( 1 << V_141 ) & V_156 ) ) return - V_74 ;
if ( F_80 ( V_154 ) ) return - V_74 ;
if ( V_140 [ V_154 ] . V_7 ) return - V_74 ;
V_149 = F_84 ( V_154 , & F_71 , 0 , V_157 , NULL ) ;
if ( V_149 ) return V_149 ;
V_140 [ V_154 ] . V_141 = V_141 ;
V_140 [ V_154 ] . V_7 = V_8 ;
return V_154 ;
}
case V_158 : {
if ( F_80 ( V_144 ) ) return - V_74 ;
if ( ! V_140 [ V_144 ] . V_7 ) return 0 ;
if ( V_140 [ V_144 ] . V_7 != V_8 ) return - V_74 ;
F_76 ( V_144 ) ;
return 0 ;
}
}
return - V_159 ;
}
