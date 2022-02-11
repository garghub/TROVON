static void F_1 ( T_1 V_1 )
{
if ( ! F_2 ( V_2 , V_1 ) )
V_2 = NULL ;
}
static inline void F_3 ( void )
{
F_4 ( & V_3 , V_4 + V_5 ) ;
V_6 = 0 ;
}
static inline void F_5 ( void )
{
F_4 ( & V_7 , V_4 + V_8 ) ;
}
static inline void F_6 ( void )
{
F_4 ( & V_9 , V_4 + V_10 ) ;
}
static inline void F_7 ( void )
{
F_8 ( & V_9 ) ;
}
static void F_9 ( int V_11 )
{
unsigned long V_12 ;
F_10 ( V_12 ) ;
V_13 . V_14 = 14 ;
V_13 . V_15 = ( V_11 == 0 ) ? V_13 . V_14 | 0x01 :
V_13 . V_14 & 0xfe ;
F_11 ( V_12 ) ;
}
static void F_12 ( int V_16 )
{
unsigned long V_12 ;
unsigned char V_17 ;
if ( V_16 == V_18 )
return;
F_10 ( V_12 ) ;
V_13 . V_14 = 14 ;
V_17 = V_13 . V_14 ;
V_13 . V_15 = ( V_17 | V_19 ) & ~ ( V_16 == 0 ? V_20 : V_21 ) ;
V_22 = 1 ;
F_11 ( V_12 ) ;
F_13 ( V_23 , V_24 . V_25 ) ;
F_14 ( 25 ) ;
if ( V_26 )
if ( F_15 ( V_27 ) )
V_28 . V_29 = V_26 -> V_29 ;
V_18 = V_16 ;
}
static void F_16 ( void )
{
unsigned long V_12 ;
F_10 ( V_12 ) ;
V_22 = 0 ;
V_13 . V_14 = 14 ;
V_13 . V_15 = ( V_13 . V_14 |
( V_30 ? 3 : 7 ) ) ;
V_18 = - 1 ;
F_11 ( V_12 ) ;
}
static void F_17 ( unsigned long V_31 )
{
unsigned char V_32 ;
if ( V_18 < 0 )
return;
if ( F_18 () )
goto V_33;
V_32 = F_19 ( V_34 ) ;
if ( ! ( V_32 & 0x80 ) ) {
V_35 = 0 ;
F_16 () ;
return;
}
V_33:
F_4 ( & V_3 ,
V_4 + ( V_6 ++ < V_36 ? V_37 / 20 : V_37 / 2 ) ) ;
}
static void F_20 ( unsigned long V_31 )
{
static int V_16 = 0 ;
unsigned long V_12 ;
unsigned char V_38 ;
int V_39 ;
if ( ++ V_16 > 1 || ! V_24 . V_40 )
V_16 = 0 ;
F_10 ( V_12 ) ;
if ( ! F_18 () ) {
V_13 . V_14 = 14 ;
V_38 = V_13 . V_14 ;
V_13 . V_15 = ( V_38 | V_19 ) &
~ ( V_16 == 0 ? V_20 : V_21 ) ;
V_39 = ! ! ( F_19 ( V_34 ) & V_41 ) ;
V_13 . V_15 = V_38 ;
if ( V_39 != V_24 . V_42 ) {
F_21 ( ( L_1 , V_16 , V_39 ) ) ;
V_24 . V_42 = V_39 ;
F_22 ( V_16 , & V_43 ) ;
}
}
F_11 ( V_12 ) ;
F_5 () ;
}
static inline void F_23 ( void )
{
V_44 = V_45 ;
}
static inline int F_24 ( void )
{
int V_17 = V_44 ;
V_44 = 0 ;
return ( V_17 ) ;
}
static inline void F_25 ( void * V_46 , void * V_47 )
{
T_2 * V_48 = ( T_2 * ) V_46 , * V_49 = ( T_2 * ) V_47 ;
int V_50 ;
for ( V_50 = 512 / 4 ; V_50 ; V_50 -- )
* V_49 ++ = * V_48 ++ ;
}
static T_3 F_26 ( int V_51 , void * V_31 )
{
unsigned char V_32 ;
void (* F_27)( int );
F_27 = F_28 ( & V_52 , NULL ) ;
if ( F_27 ) {
F_29 () ;
V_32 = F_19 ( V_34 ) ;
F_21 ( ( L_2 , V_32 , ( unsigned long ) F_27 ) ) ;
F_27 ( V_32 ) ;
}
else {
F_21 ( ( L_3 ) ) ;
}
return V_53 ;
}
static void F_30 ( void )
{
if ( V_54 ) {
V_54 = 0 ;
V_55 = 1 ;
F_31 ( & V_56 ) ;
return;
}
if ( ! V_2 )
return;
V_2 -> V_57 ++ ;
if ( V_2 -> V_57 >= V_58 ) {
F_32 ( V_59 L_4 , V_18 ) ;
F_1 ( V_60 ) ;
}
else if ( V_2 -> V_57 == V_61 ) {
F_32 ( V_62 L_5 , V_18 ) ;
if ( V_18 != - 1 )
V_63 . V_25 = - 1 ;
}
F_33 () ;
}
static int F_34 ( int V_16 , int type , struct V_64 * V_65 )
{
unsigned char * V_66 ;
int V_67 , V_68 ;
unsigned long V_12 ;
F_21 ( ( L_6 ,
V_16 , V_65 -> V_25 , V_65 -> V_69 , V_65 -> V_70 ) ) ;
F_35 ( V_71 , F_36 ( & V_72 , 0 , 1 ) == 0 ) ;
F_10 ( V_12 ) ;
F_37 ( F_26 , NULL ) ;
F_38 ( V_73 ) ;
F_11 ( V_12 ) ;
if ( type ) {
if ( -- type >= V_74 ||
V_75 [ type ] . V_76 > V_77 ) {
F_33 () ;
return - V_78 ;
}
type = V_75 [ type ] . V_79 ;
V_26 = & V_80 [ type ] ;
}
if ( ! V_26 || V_65 -> V_25 >= V_26 -> V_81 / V_26 -> V_82 / 2 || V_65 -> V_69 >= 2 ) {
F_33 () ;
return - V_78 ;
}
V_68 = V_26 -> V_82 ;
V_66 = V_83 ;
V_84 = - 1 ;
F_8 ( & V_3 ) ;
F_39 ( 60 * ( V_68 / 9 ) , 0x4e ) ;
for( V_67 = 0 ; V_67 < V_68 ; ++ V_67 ) {
F_39 ( 12 , 0 ) ;
F_39 ( 3 , 0xf5 ) ;
* V_66 ++ = 0xfe ;
* V_66 ++ = V_65 -> V_25 ;
* V_66 ++ = V_65 -> V_69 ;
* V_66 ++ = ( V_68 + V_67 - V_65 -> V_70 ) % V_68 + 1 ;
* V_66 ++ = 2 ;
* V_66 ++ = 0xf7 ;
F_39 ( 22 , 0x4e ) ;
F_39 ( 12 , 0 ) ;
F_39 ( 3 , 0xf5 ) ;
* V_66 ++ = 0xfb ;
F_39 ( 512 , 0xe5 ) ;
* V_66 ++ = 0xf7 ;
F_39 ( 40 , 0x4e ) ;
}
F_39 ( V_83 + V_85 - V_66 , 0x4e ) ;
V_54 = 1 ;
V_55 = 0 ;
V_86 = V_65 -> V_25 ;
V_87 = V_65 -> V_69 ;
F_40 ( V_16 ) ;
F_41 ( & V_56 ) ;
F_33 () ;
return ( V_55 ? - V_88 : 0 ) ;
}
static void F_40 ( int V_16 )
{
F_21 ( ( L_7 ) ) ;
if ( V_89 && ! V_54 ) {
V_90:
if ( F_42 ( V_16 , V_87 , V_86 ) ) {
if ( V_91 == V_92 ) {
F_25 ( F_43 ( V_93 ) , V_94 ) ;
if ( ++ V_95 < F_44 ( V_2 ) ) {
F_45 ( V_16 ) ;
goto V_90;
}
else {
F_1 ( V_96 ) ;
F_33 () ;
return;
}
}
else {
F_25 ( V_94 , F_43 ( V_93 ) ) ;
}
}
}
if ( V_18 != V_16 )
F_12 ( V_16 ) ;
if ( V_24 . V_25 == - 1 )
F_46 () ;
else if ( V_24 . V_25 != V_86 << V_26 -> V_97 )
F_47 () ;
else if ( V_54 )
F_48 () ;
else
F_49 () ;
}
static void F_46 ( void )
{
if ( V_63 . V_25 >= 0 ) {
F_50 ( 0 ) ;
return;
}
if ( F_15 ( V_27 ) )
V_28 . V_29 = 0 ; ;
F_21 ( ( L_8 ) ) ;
F_51 ( F_50 ) ;
F_13 ( V_98 , V_99 | V_63 . V_100 ) ;
V_101 = 1 ;
V_35 = 1 ;
F_6 () ;
}
static void F_50 ( int V_32 )
{
F_21 ( ( L_9 ) ) ;
F_7 () ;
if ( F_15 ( V_27 ) )
V_28 . V_29 = V_102 -> V_29 ;
if ( V_32 & V_103 ) {
F_32 ( V_59 L_10 , V_18 ) ;
F_30 () ;
}
else {
V_63 . V_25 = 0 ;
F_47 () ;
}
}
static void F_47 ( void )
{
if ( V_63 . V_25 == V_86 << V_102 -> V_97 ) {
F_52 ( 0 ) ;
return;
}
if ( F_15 ( V_27 ) ) {
V_28 . V_29 = 0 ;
F_53 () ;
}
F_21 ( ( L_11 , V_86 ) ) ;
F_13 ( V_104 , V_86 << V_102 -> V_97 ) ;
F_14 ( 25 ) ;
F_51 ( F_52 ) ;
F_13 ( V_98 , V_105 | V_63 . V_100 ) ;
V_35 = 1 ;
F_23 () ;
F_6 () ;
}
static void F_52 ( int V_32 )
{
F_21 ( ( L_12 ) ) ;
F_7 () ;
if ( F_15 ( V_27 ) )
V_28 . V_29 = V_102 -> V_29 ;
if ( V_32 & V_103 ) {
F_32 ( V_59 L_13 ,
V_18 , V_86 ) ;
V_63 . V_25 = - 1 ;
F_30 () ;
}
else {
V_63 . V_25 = V_86 << V_102 -> V_97 ;
V_101 = 0 ;
if ( V_54 )
F_48 () ;
else
F_49 () ;
}
}
static void F_49 ( void )
{
unsigned long V_106 , V_12 ;
unsigned int V_107 , V_108 ;
unsigned int V_25 ;
F_21 ( ( L_14 , V_93 , V_91 == V_109 ? 'w' : 'r' ) ) ;
if ( V_91 == V_109 ) {
if ( F_15 ( V_110 ) ) {
V_106 = F_54 ( V_94 ) ;
}
else {
F_25 ( V_94 , V_111 ) ;
V_106 = V_112 ;
}
F_55 ( V_106 , 512 , 1 ) ;
V_107 = 0x100 ;
}
else {
if ( V_113 )
V_106 = V_114 ;
else
V_106 = F_15 ( V_110 ) ?
F_54 ( V_94 ) : V_112 ;
V_107 = 0 ;
}
F_9 ( V_87 ) ;
F_13 ( V_115 , V_113 ? 1 : V_93 ) ;
F_53 () ;
if ( V_102 -> V_97 ) {
V_25 = F_19 ( V_23 ) ;
F_53 () ;
F_13 ( V_23 , V_25 >> V_102 -> V_97 ) ;
}
F_14 ( 25 ) ;
F_10 ( V_12 ) ;
V_28 . V_116 = ( unsigned char ) V_106 ;
F_53 () ;
V_106 >>= 8 ;
V_28 . V_117 = ( unsigned char ) V_106 ;
F_53 () ;
V_106 >>= 8 ;
if ( F_15 ( V_110 ) )
V_118 = ( unsigned short ) V_106 ;
else
V_28 . V_119 = ( unsigned char ) V_106 ;
F_53 () ;
F_11 ( V_12 ) ;
V_28 . V_120 = 0x90 | V_107 ;
F_53 () ;
V_28 . V_120 = 0x90 | ( V_107 ^ 0x100 ) ;
F_53 () ;
V_28 . V_120 = 0x90 | V_107 ;
F_53 () ;
V_28 . V_121 = V_113 ? V_102 -> V_82 : 1 ;
F_14 ( 25 ) ;
V_28 . V_120 = V_122 | V_107 ;
F_14 ( 25 ) ;
F_51 ( V_123 ) ;
V_28 . V_121 =
( F_24 () |
( V_107 ? V_124 : ( V_125 | ( V_113 ? V_126 : 0 ) ) ) ) ;
V_108 = V_35 ;
V_35 = 1 ;
V_101 = 1 ;
if ( V_113 ) {
V_127 = 1 ;
F_4 ( & V_128 ,
V_4 + V_37 / 5 + ( V_108 ? 0 : V_37 ) ) ;
}
F_6 () ;
}
static void F_56 ( unsigned long V_31 )
{
unsigned long V_12 , V_129 , V_130 ;
F_10 ( V_12 ) ;
if ( ! V_127 ) {
F_11 ( V_12 ) ;
return;
}
V_129 = 0 ;
do {
V_130 = V_129 ;
V_129 = V_28 . V_116 & 0xff ;
F_53 () ;
V_129 |= ( V_28 . V_117 & 0xff ) << 8 ;
F_53 () ;
if ( F_15 ( V_110 ) )
V_129 |= ( V_118 & 0xffff ) << 16 ;
else
V_129 |= ( V_28 . V_119 & 0xff ) << 16 ;
F_53 () ;
} while( V_129 != V_130 );
if ( V_129 >= V_114 + V_102 -> V_82 * 512 ) {
F_51 ( NULL ) ;
V_127 = 0 ;
F_11 ( V_12 ) ;
F_21 ( ( L_15 ) ) ;
F_13 ( V_98 , V_131 ) ;
F_14 ( 25 ) ;
F_57 ( 0 ) ;
}
else {
F_11 ( V_12 ) ;
F_21 ( ( L_16 ) ) ;
F_4 ( & V_128 , V_4 + V_37 / 5 / 10 ) ;
}
}
static void V_123 ( int V_32 )
{
F_21 ( ( L_17 ) ) ;
if ( V_113 ) {
F_8 ( & V_128 ) ;
if ( ! V_127 )
return;
V_127 = 0 ;
}
F_57 ( V_32 ) ;
}
static void F_57 ( int V_32 )
{
unsigned int V_25 ;
F_7 () ;
if ( V_102 -> V_97 ) {
V_25 = F_19 ( V_23 ) ;
F_53 () ;
F_13 ( V_23 , V_25 << V_102 -> V_97 ) ;
}
if ( ! V_89 ) {
V_28 . V_120 = 0x90 ;
F_53 () ;
if ( ! ( V_28 . V_120 & 0x01 ) ) {
F_32 ( V_59 L_18 , V_18 ) ;
goto V_132;
}
}
F_53 () ;
if ( V_91 == V_109 && ( V_32 & V_41 ) ) {
F_32 ( V_133 L_19 , V_18 ) ;
goto V_132;
}
if ( ( V_32 & V_103 ) &&
! ( V_113 && F_19 ( V_115 ) > V_102 -> V_82 ) ) {
if ( V_134 ) {
if ( V_102 > V_80 ) {
if ( V_102 [ - 1 ] . V_81 > V_135 ) {
V_102 -- ;
F_58 ( V_136 [ V_18 ] . V_137 ,
V_102 -> V_81 ) ;
} else
V_134 = 0 ;
}
else {
if ( V_63 . V_12 & V_138 )
F_32 ( V_139 L_20 ,
V_18 , V_102 -> V_140 ) ;
V_134 = 0 ;
}
} else {
if ( V_63 . V_141 ) {
V_102 = V_80 + V_142 [ V_77 ] ;
F_58 ( V_136 [ V_18 ] . V_137 ,
V_102 -> V_81 ) ;
V_134 = 1 ;
}
}
if ( V_134 ) {
if ( F_15 ( V_27 ) ) {
V_28 . V_29 = V_102 -> V_29 ;
F_53 () ;
}
F_45 ( V_18 ) ;
V_84 = - 1 ;
F_40 ( V_18 ) ;
return;
}
F_32 ( V_59 L_21 ,
V_18 , F_19 ( V_115 ) , V_87 , V_86 ) ;
goto V_132;
}
if ( V_32 & V_143 ) {
F_32 ( V_59 L_22 ,
V_18 , V_87 , V_86 , F_19 ( V_115 ) ) ;
goto V_132;
}
if ( V_32 & V_144 ) {
F_32 ( V_59 L_23 ,
V_18 , V_87 , V_86 , F_19 ( V_115 ) ) ;
goto V_132;
}
V_134 = 0 ;
if ( V_91 == V_92 ) {
if ( ! V_113 ) {
void * V_129 ;
V_129 = F_15 ( V_110 ) ? V_94 : V_111 ;
F_55 ( F_54 ( V_129 ) , 512 , 0 ) ;
if ( ! F_15 ( V_110 ) )
F_25 ( V_129 , V_94 ) ;
} else {
F_55 ( V_114 , V_145 [ V_77 ] * 512 , 0 ) ;
V_84 = V_18 ;
V_146 = V_87 ;
V_147 = V_86 ;
F_25 ( F_43 ( V_93 ) , V_94 ) ;
}
}
if ( ++ V_95 < F_44 ( V_2 ) ) {
F_45 ( V_18 ) ;
F_40 ( V_18 ) ;
}
else {
F_1 ( V_96 ) ;
F_33 () ;
}
return;
V_132:
V_84 = - 1 ;
F_30 () ;
}
static void F_48 ( void )
{
unsigned long V_106 , V_12 ;
unsigned int V_25 ;
F_21 ( ( L_24 , V_86 , V_87 ) ) ;
V_106 = V_114 ;
F_55 ( V_106 , V_85 , 1 ) ;
F_9 ( V_87 ) ;
if ( V_102 -> V_97 ) {
V_25 = F_19 ( V_23 ) ;
F_53 () ;
F_13 ( V_23 , V_25 >> V_102 -> V_97 ) ;
}
F_14 ( 40 ) ;
F_10 ( V_12 ) ;
V_28 . V_116 = ( unsigned char ) V_106 ;
F_53 () ;
V_106 >>= 8 ;
V_28 . V_117 = ( unsigned char ) V_106 ;
F_53 () ;
V_106 >>= 8 ;
if ( F_15 ( V_110 ) )
V_118 = ( unsigned short ) V_106 ;
else
V_28 . V_119 = ( unsigned char ) V_106 ;
F_53 () ;
F_11 ( V_12 ) ;
V_28 . V_120 = 0x190 ;
F_53 () ;
V_28 . V_120 = 0x90 ;
F_53 () ;
V_28 . V_120 = 0x190 ;
F_53 () ;
V_28 . V_121 = V_85 / 512 ;
F_14 ( 40 ) ;
V_28 . V_120 = V_122 | 0x100 ;
F_14 ( 40 ) ;
F_51 ( V_148 ) ;
V_28 . V_121 = V_149 | F_24 () ;
V_35 = 1 ;
F_6 () ;
}
static void V_148 ( int V_32 )
{
F_21 ( ( L_25 ) ) ;
F_7 () ;
if ( V_32 & V_41 ) {
F_32 ( V_133 L_19 , V_18 ) ;
goto V_132;
}
if ( V_32 & V_144 ) {
F_32 ( V_59 L_26 ,
V_18 , V_87 , V_86 ) ;
goto V_132;
}
F_31 ( & V_56 ) ;
return;
V_132:
F_30 () ;
}
static void F_59 ( unsigned long V_31 )
{
F_60 ( V_73 ) ;
if ( ! V_52 ) goto V_150;
F_51 ( NULL ) ;
if ( V_89 )
F_8 ( & V_128 ) ;
F_13 ( V_98 , V_131 ) ;
F_14 ( 25 ) ;
F_32 ( V_59 L_27 ) ;
F_30 () ;
V_150:
F_61 ( V_73 ) ;
}
static void F_62 ( void )
{
if ( ! V_101 ) {
F_63 ( 0 ) ;
}
else {
F_21 ( ( L_28 ) ) ;
F_13 ( V_104 , V_63 . V_25 ) ;
F_51 ( F_63 ) ;
F_13 ( V_98 , V_105 ) ;
V_35 = 1 ;
F_6 () ;
}
}
static void F_63 ( int V_31 )
{
unsigned long V_12 ;
F_21 ( ( L_29 ) ) ;
F_7 () ;
V_101 = 0 ;
if ( F_64 ( & V_7 ) && F_65 ( V_7 . V_151 , V_4 + 5 ) )
F_4 ( & V_7 , V_4 + 5 ) ;
else
F_5 () ;
F_3 () ;
F_10 ( V_12 ) ;
F_66 () ;
V_72 = 0 ;
F_67 ( & V_71 ) ;
F_11 ( V_12 ) ;
F_21 ( ( L_30 ) ) ;
}
static unsigned int F_68 ( struct V_152 * V_137 ,
unsigned int V_153 )
{
struct V_154 * V_66 = V_137 -> V_155 ;
unsigned int V_16 = V_66 - V_136 ;
if ( F_69 ( V_16 , & V_156 ) ) {
return V_157 ;
}
if ( F_69 ( V_16 , & V_43 ) ) {
return V_157 ;
}
if ( V_24 . V_42 ) {
return V_157 ;
}
return 0 ;
}
static int F_70 ( struct V_152 * V_137 )
{
struct V_154 * V_66 = V_137 -> V_155 ;
unsigned int V_16 = V_66 - V_136 ;
if ( F_69 ( V_16 , & V_43 ) ||
F_69 ( V_16 , & V_156 ) ||
V_66 -> V_158 == 0 ) {
if ( V_24 . V_12 & V_138 )
F_32 ( V_59 L_31 , V_26 ) ;
V_84 = - 1 ;
F_71 ( V_16 , & V_156 ) ;
F_71 ( V_16 , & V_43 ) ;
if ( V_159 [ V_16 ] . V_81 == 0 )
V_26 = NULL ;
else
V_26 = & V_159 [ V_16 ] ;
}
return 0 ;
}
static void F_45 ( int V_16 )
{
int V_160 = V_135 + V_95 ;
V_86 = V_160 / V_26 -> V_82 ;
V_93 = V_160 - V_86 * V_26 -> V_82 + 1 ;
V_87 = V_86 & 1 ;
V_86 >>= 1 ;
V_94 = V_161 + 512 * V_95 ;
if ( V_89 )
V_113 = ( V_91 == V_92 && V_2 -> V_57 == 0 ) ;
else
V_113 = 0 ;
F_21 ( ( L_32 , V_87 ,
V_86 , V_93 , ( unsigned long ) V_94 ) ) ;
}
static struct V_162 * F_72 ( void )
{
struct V_163 * V_164 ;
int V_165 = V_166 ;
struct V_162 * V_167 = NULL ;
do {
V_164 = V_136 [ V_166 ] . V_137 -> V_168 ;
if ( ++ V_166 == V_169 )
V_166 = 0 ;
if ( V_164 ) {
V_167 = F_73 ( V_164 ) ;
if ( V_167 ) {
V_167 -> V_57 = 0 ;
break;
}
}
} while ( V_166 != V_165 );
return V_167 ;
}
static void F_33 ( void )
{
int V_16 , type ;
struct V_154 * V_170 ;
F_21 ( ( L_33 ,
V_2 , V_2 ? V_2 -> V_171 -> V_172 : L_34 ,
V_2 ? F_74 ( V_2 ) : 0 ) ) ;
V_54 = 0 ;
V_90:
if ( ! V_2 ) {
V_2 = F_72 () ;
if ( ! V_2 )
goto V_173;
}
V_170 = V_2 -> V_171 -> V_155 ;
V_16 = V_170 - V_136 ;
type = V_170 -> type ;
if ( ! V_24 . V_40 ) {
F_32 ( V_59 L_35 , V_16 ) ;
F_1 ( V_60 ) ;
goto V_90;
}
if ( type == 0 ) {
if ( ! V_26 ) {
V_134 = 1 ;
V_26 = V_80 + V_142 [ V_77 ] ;
F_58 ( V_170 -> V_137 , V_26 -> V_81 ) ;
V_24 . V_141 = 1 ;
}
}
else {
if ( -- type >= V_74 ) {
F_32 ( V_62 L_36 , V_16 ) ;
F_1 ( V_60 ) ;
goto V_90;
}
if ( V_75 [ type ] . V_76 > V_77 ) {
F_32 ( V_62 L_37 , V_16 ) ;
F_1 ( V_60 ) ;
goto V_90;
}
type = V_75 [ type ] . V_79 ;
V_26 = & V_80 [ type ] ;
F_58 ( V_170 -> V_137 , V_26 -> V_81 ) ;
V_24 . V_141 = 0 ;
}
if ( F_74 ( V_2 ) + 1 > V_26 -> V_81 ) {
F_1 ( V_60 ) ;
goto V_90;
}
F_8 ( & V_3 ) ;
V_95 = 0 ;
V_91 = F_75 ( V_2 ) ;
V_135 = F_74 ( V_2 ) ;
V_161 = F_76 ( V_2 -> V_174 ) ;
F_45 ( V_16 ) ;
F_40 ( V_16 ) ;
return;
V_173:
F_62 () ;
}
void F_77 ( struct V_163 * V_164 )
{
F_21 ( ( L_38 , V_175 -> V_176 ) ) ;
F_35 ( V_71 , F_36 ( & V_72 , 0 , 1 ) == 0 ) ;
F_37 ( F_26 , NULL ) ;
F_60 ( V_73 ) ;
F_33 () ;
F_61 ( V_73 ) ;
}
static int F_78 ( struct V_177 * V_178 , T_4 V_179 ,
unsigned int V_180 , unsigned long V_181 )
{
struct V_152 * V_137 = V_178 -> V_182 ;
struct V_154 * V_170 = V_137 -> V_155 ;
int V_16 = V_170 - V_136 ;
int type = V_170 -> type ;
struct V_64 V_183 ;
struct V_80 * V_184 ;
struct V_185 V_186 ;
int V_187 ;
struct V_185 V_188 ;
void T_5 * V_189 = ( void T_5 * ) V_181 ;
switch ( V_180 ) {
case V_190 :
if ( type ) {
if ( -- type >= V_74 )
return - V_191 ;
if ( V_75 [ type ] . V_76 > V_77 )
return - V_191 ;
type = V_75 [ type ] . V_79 ;
V_184 = & V_80 [ type ] ;
if ( V_24 . V_12 & V_138 )
F_32 ( V_59 L_39 ,
V_16 , V_184 , V_184 -> V_140 ) ;
}
else {
if ( ! V_26 )
return - V_192 ;
else
V_184 = V_26 ;
}
memset ( ( void * ) & V_186 , 0 , sizeof( V_186 ) ) ;
V_186 . V_193 = V_184 -> V_81 ;
V_186 . V_67 = V_184 -> V_82 ;
V_186 . V_69 = 2 ;
V_186 . V_25 = V_184 -> V_81 / V_184 -> V_82 / 2 ;
V_186 . V_97 = V_184 -> V_97 ;
if ( F_79 ( V_189 , & V_186 , sizeof( V_186 ) ) )
return - V_194 ;
return 0 ;
}
switch ( V_180 ) {
case V_195 :
case V_196 :
if ( V_170 -> V_197 != 1 && V_170 -> V_197 != - 1 )
return - V_198 ;
if ( F_80 ( & V_188 , V_189 , sizeof( V_188 ) ) )
return - V_194 ;
if ( F_68 ( V_137 , 0 ) )
F_70 ( V_137 ) ;
if ( V_24 . V_12 & V_138 )
F_32 ( V_139 L_40 ,
V_16 , V_188 . V_193 , V_188 . V_67 , V_188 . V_97 ) ;
if ( type ) {
F_33 () ;
return - V_78 ;
}
for ( V_187 = 0 ; V_187 < V_74 ; V_187 ++ ) {
int V_199 = 0 ;
if ( V_75 [ V_187 ] . V_76 > V_77 ) {
continue;
}
V_199 = V_75 [ V_187 ] . V_79 ;
V_184 = & V_80 [ V_199 ] ;
if ( V_184 -> V_81 == V_188 . V_193
&& V_184 -> V_82 == V_188 . V_67
&& V_184 -> V_97 == V_188 . V_97 ) {
if ( V_24 . V_12 & V_138 )
F_32 ( V_139 L_41 ,
V_16 , V_184 -> V_140 , V_184 ) ;
V_26 = V_184 ;
F_58 ( V_170 -> V_137 , V_26 -> V_81 ) ;
if ( V_180 == V_196 ) {
V_159 [ V_16 ] . V_140 = V_184 -> V_140 ;
V_159 [ V_16 ] . V_82 = V_184 -> V_82 ;
V_159 [ V_16 ] . V_81 = V_184 -> V_81 ;
V_159 [ V_16 ] . V_29 = V_184 -> V_29 ;
V_159 [ V_16 ] . V_97 = V_184 -> V_97 ;
}
return 0 ;
}
}
if ( V_180 == V_196 ) {
V_184 = & V_159 [ V_16 ] ;
} else
V_184 = & V_200 [ V_16 ] ;
V_184 -> V_140 = L_42 ;
V_184 -> V_81 = V_188 . V_193 ;
V_184 -> V_82 = V_188 . V_67 ;
if ( V_188 . V_67 > 14 )
V_184 -> V_29 = 3 ;
else
V_184 -> V_29 = 0 ;
V_184 -> V_97 = V_188 . V_97 ;
if ( V_24 . V_12 & V_138 )
F_32 ( V_139 L_43 ,
V_16 , V_184 -> V_81 , V_184 -> V_82 , V_184 -> V_97 ) ;
if ( V_188 . V_25 != V_184 -> V_81 / V_184 -> V_82 / 2 ||
V_188 . V_69 != 2 ) {
F_33 () ;
return - V_78 ;
}
V_26 = V_184 ;
F_58 ( V_170 -> V_137 , V_26 -> V_81 ) ;
return 0 ;
case V_201 :
V_24 . V_12 |= V_138 ;
return 0 ;
case V_202 :
V_24 . V_12 &= ~ V_138 ;
return 0 ;
case V_203 :
return - V_78 ;
case V_204 :
return 0 ;
case V_205 :
if ( V_170 -> V_197 != 1 && V_170 -> V_197 != - 1 )
return - V_198 ;
if ( F_80 ( & V_183 , V_189 , sizeof( V_183 ) ) )
return - V_194 ;
return F_34 ( V_16 , type , & V_183 ) ;
case V_206 :
V_26 = NULL ;
V_159 [ V_16 ] . V_81 = 0 ;
F_58 ( V_170 -> V_137 , V_207 * 2 ) ;
case V_208 :
case V_209 :
V_84 = - 1 ;
F_22 ( V_16 , & V_156 ) ;
F_81 ( V_178 ) ;
return 0 ;
default:
return - V_78 ;
}
}
static int F_82 ( struct V_177 * V_178 , T_4 V_179 ,
unsigned int V_180 , unsigned long V_210 )
{
int V_211 ;
F_83 ( & V_212 ) ;
V_211 = F_78 ( V_178 , V_179 , V_180 , V_210 ) ;
F_84 ( & V_212 ) ;
return V_211 ;
}
static void T_6 F_85 ( int V_16 )
{
V_24 . V_40 = 0 ;
V_26 = NULL ;
if ( ! F_86 ( V_16 ) )
return;
V_24 . V_40 = 1 ;
V_24 . V_25 = 0 ;
switch( V_213 [ V_16 ] ) {
case 2 :
V_24 . V_100 = V_214 ;
break;
case 3 :
V_24 . V_100 = V_215 ;
break;
case 6 :
V_24 . V_100 = V_216 ;
break;
case 12 :
V_24 . V_100 = V_217 ;
break;
default:
if ( F_15 ( V_27 ) || V_218 )
V_24 . V_100 = V_215 ;
else
V_24 . V_100 = V_216 ;
break;
}
V_35 = 1 ;
}
static int T_6 F_86 ( int V_16 )
{
unsigned long V_219 ;
unsigned char V_32 ;
int V_220 ;
if ( V_16 >= ( V_30 ? 1 : 2 ) ) return ( 0 ) ;
F_12 ( V_16 ) ;
F_87 ( V_73 ) ;
F_13 ( V_23 , 0xff00 ) ;
F_13 ( V_98 , V_99 | V_221 | V_216 ) ;
V_219 = V_4 + 2 * V_37 + V_37 / 2 ;
while ( F_65 ( V_4 , V_219 ) )
if ( ! ( V_222 . V_223 & 0x20 ) )
break;
V_32 = F_19 ( V_34 ) ;
V_220 = ( V_32 & V_224 ) != 0 ;
F_13 ( V_98 , V_131 ) ;
F_14 ( 500 ) ;
V_32 = F_19 ( V_34 ) ;
F_14 ( 20 ) ;
if ( V_220 ) {
F_13 ( V_104 , 0 ) ;
F_13 ( V_98 , V_105 ) ;
while( V_222 . V_223 & 0x20 )
;
V_32 = F_19 ( V_34 ) ;
}
F_38 ( V_73 ) ;
return ( V_220 ) ;
}
static void T_6 F_88 ( void )
{
int V_16 , V_50 = 0 ;
if ( F_15 ( V_27 ) )
V_28 . V_29 = 0 ;
F_32 ( V_139 L_44 ) ;
for( V_16 = 0 ; V_16 < V_169 ; V_16 ++ ) {
F_85 ( V_16 ) ;
if ( V_24 . V_40 ) {
F_32 ( V_139 L_45 , V_16 ) ;
++ V_50 ;
}
}
if ( F_19 ( V_34 ) & V_225 ) {
F_13 ( V_98 , V_131 ) ;
F_14 ( 500 ) ;
F_19 ( V_34 ) ;
F_14 ( 20 ) ;
}
if ( V_50 > 0 ) {
F_3 () ;
if ( V_50 == 1 ) F_12 ( 0 ) ;
F_5 () ;
}
}
static int F_89 ( struct V_177 * V_178 , T_4 V_179 )
{
struct V_154 * V_66 = V_178 -> V_182 -> V_155 ;
int type = F_90 ( V_178 -> V_226 ) >> 2 ;
F_21 ( ( L_46 , type ) ) ;
if ( V_66 -> V_197 && V_66 -> type != type )
return - V_198 ;
if ( V_66 -> V_197 == - 1 || ( V_66 -> V_197 && V_179 & V_227 ) )
return - V_198 ;
if ( V_179 & V_227 )
V_66 -> V_197 = - 1 ;
else
V_66 -> V_197 ++ ;
V_66 -> type = type ;
if ( V_179 & V_228 )
return 0 ;
if ( V_179 & ( V_229 | V_230 ) ) {
F_81 ( V_178 ) ;
if ( V_179 & V_230 ) {
if ( V_66 -> V_42 ) {
if ( V_66 -> V_197 < 0 )
V_66 -> V_197 = 0 ;
else
V_66 -> V_197 -- ;
return - V_231 ;
}
}
}
return 0 ;
}
static int F_91 ( struct V_177 * V_178 , T_4 V_179 )
{
int V_211 ;
F_83 ( & V_212 ) ;
V_211 = F_89 ( V_178 , V_179 ) ;
F_84 ( & V_212 ) ;
return V_211 ;
}
static void F_92 ( struct V_152 * V_137 , T_4 V_179 )
{
struct V_154 * V_66 = V_137 -> V_155 ;
F_83 ( & V_212 ) ;
if ( V_66 -> V_197 < 0 )
V_66 -> V_197 = 0 ;
else if ( ! V_66 -> V_197 -- ) {
F_32 ( V_59 L_47 ) ;
V_66 -> V_197 = 0 ;
}
F_84 ( & V_212 ) ;
}
static struct V_232 * F_93 ( T_7 V_233 , int * V_234 , void * V_235 )
{
int V_16 = * V_234 & 3 ;
int type = * V_234 >> 2 ;
if ( V_16 >= V_169 || type > V_74 )
return NULL ;
* V_234 = 0 ;
return F_94 ( V_136 [ V_16 ] . V_137 ) ;
}
static int T_6 F_95 ( void )
{
int V_236 ;
if ( ! V_237 )
return - V_191 ;
if ( F_96 ( V_238 , L_48 ) )
return - V_198 ;
for ( V_236 = 0 ; V_236 < V_169 ; V_236 ++ ) {
V_136 [ V_236 ] . V_137 = F_97 ( 1 ) ;
if ( ! V_136 [ V_236 ] . V_137 )
goto V_239;
}
if ( V_89 < 0 )
V_89 = ! V_218 ;
V_18 = - 1 ;
V_84 = - 1 ;
V_111 = F_98 ( V_85 + 512 , L_49 ) ;
if ( ! V_111 ) {
F_32 ( V_59 L_50 ) ;
goto V_239;
}
V_83 = V_111 + 512 ;
V_112 = F_99 ( V_111 ) ;
V_114 = F_54 ( V_83 ) ;
V_84 = V_146 = V_147 = - 1 ;
for ( V_236 = 0 ; V_236 < V_169 ; V_236 ++ ) {
V_136 [ V_236 ] . V_25 = - 1 ;
V_136 [ V_236 ] . V_12 = 0 ;
V_136 [ V_236 ] . V_137 -> V_240 = V_238 ;
V_136 [ V_236 ] . V_137 -> V_241 = V_236 ;
sprintf ( V_136 [ V_236 ] . V_137 -> V_172 , L_51 , V_236 ) ;
V_136 [ V_236 ] . V_137 -> V_242 = & V_243 ;
V_136 [ V_236 ] . V_137 -> V_155 = & V_136 [ V_236 ] ;
V_136 [ V_236 ] . V_137 -> V_168 = F_100 ( F_77 ,
& V_244 ) ;
if ( ! V_136 [ V_236 ] . V_137 -> V_168 )
goto V_239;
F_58 ( V_136 [ V_236 ] . V_137 , V_207 * 2 ) ;
F_101 ( V_136 [ V_236 ] . V_137 ) ;
}
F_102 ( F_103 ( V_238 , 0 ) , 256 , V_245 ,
F_93 , NULL , NULL ) ;
F_32 ( V_139 L_52 ,
V_77 == 0 ? 'D' : V_77 == 1 ? 'H' : 'E' ,
V_89 ? L_34 : L_53 ) ;
F_88 () ;
return 0 ;
V_239:
while ( V_236 -- ) {
struct V_163 * V_164 = V_136 [ V_236 ] . V_137 -> V_168 ;
F_104 ( V_136 [ V_236 ] . V_137 ) ;
if ( V_164 )
F_105 ( V_164 ) ;
}
F_106 ( V_238 , L_48 ) ;
return - V_246 ;
}
static int T_6 F_107 ( char * V_247 )
{
int V_248 [ 3 + V_169 ] ;
int V_236 ;
if ( ! V_237 )
return 0 ;
V_247 = F_108 ( V_247 , 3 + V_169 , V_248 ) ;
if ( V_248 [ 0 ] < 1 ) {
F_32 ( V_59 L_54 ) ;
return 0 ;
}
else if ( V_248 [ 0 ] > 2 + V_169 ) {
F_32 ( V_59 L_55 ) ;
}
if ( V_248 [ 1 ] < 0 || V_248 [ 1 ] > 2 )
F_32 ( V_59 L_56 ) ;
else
V_77 = V_248 [ 1 ] ;
if ( V_248 [ 0 ] >= 2 )
V_89 = ( V_248 [ 2 ] > 0 ) ;
for( V_236 = 3 ; V_236 <= V_248 [ 0 ] && V_236 - 3 < V_169 ; ++ V_236 ) {
if ( V_248 [ V_236 ] != 2 && V_248 [ V_236 ] != 3 && V_248 [ V_236 ] != 6 && V_248 [ V_236 ] != 12 )
F_32 ( V_59 L_57 ) ;
else
V_213 [ V_236 - 3 ] = V_248 [ V_236 ] ;
}
return 1 ;
}
static void T_8 F_109 ( void )
{
int V_236 ;
F_110 ( F_103 ( V_238 , 0 ) , 256 ) ;
for ( V_236 = 0 ; V_236 < V_169 ; V_236 ++ ) {
struct V_163 * V_164 = V_136 [ V_236 ] . V_137 -> V_168 ;
F_111 ( V_136 [ V_236 ] . V_137 ) ;
F_104 ( V_136 [ V_236 ] . V_137 ) ;
F_105 ( V_164 ) ;
}
F_106 ( V_238 , L_48 ) ;
F_112 ( & V_7 ) ;
F_113 ( V_111 ) ;
}
