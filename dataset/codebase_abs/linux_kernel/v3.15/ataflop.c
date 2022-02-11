static void F_1 ( int V_1 )
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
T_1 * V_48 = ( T_1 * ) V_46 , * V_49 = ( T_1 * ) V_47 ;
int V_50 ;
for ( V_50 = 512 / 4 ; V_50 ; V_50 -- )
* V_49 ++ = * V_48 ++ ;
}
static T_2 F_26 ( int V_51 , void * V_31 )
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
F_1 ( - V_60 ) ;
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
return ( V_55 ? - V_60 : 0 ) ;
}
static void F_40 ( int V_16 )
{
F_21 ( ( L_7 ) ) ;
if ( V_88 && ! V_54 ) {
V_89:
if ( F_42 ( V_16 , V_87 , V_86 ) ) {
if ( V_90 == V_91 ) {
F_25 ( F_43 ( V_92 ) , V_93 ) ;
if ( ++ V_94 < F_44 ( V_2 ) ) {
F_45 ( V_16 ) ;
goto V_89;
}
else {
F_1 ( 0 ) ;
F_33 () ;
return;
}
}
else {
F_25 ( V_93 , F_43 ( V_92 ) ) ;
}
}
}
if ( V_18 != V_16 )
F_12 ( V_16 ) ;
if ( V_24 . V_25 == - 1 )
F_46 () ;
else if ( V_24 . V_25 != V_86 << V_26 -> V_95 )
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
F_13 ( V_96 , V_97 | V_63 . V_98 ) ;
V_99 = 1 ;
V_35 = 1 ;
F_6 () ;
}
static void F_50 ( int V_32 )
{
F_21 ( ( L_9 ) ) ;
F_7 () ;
if ( F_15 ( V_27 ) )
V_28 . V_29 = V_100 -> V_29 ;
if ( V_32 & V_101 ) {
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
if ( V_63 . V_25 == V_86 << V_100 -> V_95 ) {
F_52 ( 0 ) ;
return;
}
if ( F_15 ( V_27 ) ) {
V_28 . V_29 = 0 ;
F_53 () ;
}
F_21 ( ( L_11 , V_86 ) ) ;
F_13 ( V_102 , V_86 << V_100 -> V_95 ) ;
F_14 ( 25 ) ;
F_51 ( F_52 ) ;
F_13 ( V_96 , V_103 | V_63 . V_98 ) ;
V_35 = 1 ;
F_23 () ;
F_6 () ;
}
static void F_52 ( int V_32 )
{
F_21 ( ( L_12 ) ) ;
F_7 () ;
if ( F_15 ( V_27 ) )
V_28 . V_29 = V_100 -> V_29 ;
if ( V_32 & V_101 ) {
F_32 ( V_59 L_13 ,
V_18 , V_86 ) ;
V_63 . V_25 = - 1 ;
F_30 () ;
}
else {
V_63 . V_25 = V_86 << V_100 -> V_95 ;
V_99 = 0 ;
if ( V_54 )
F_48 () ;
else
F_49 () ;
}
}
static void F_49 ( void )
{
unsigned long V_104 , V_12 ;
unsigned int V_105 , V_106 ;
unsigned int V_25 ;
F_21 ( ( L_14 , V_92 , V_90 == V_107 ? 'w' : 'r' ) ) ;
if ( V_90 == V_107 ) {
if ( F_15 ( V_108 ) ) {
V_104 = F_54 ( V_93 ) ;
}
else {
F_25 ( V_93 , V_109 ) ;
V_104 = V_110 ;
}
F_55 ( V_104 , 512 , 1 ) ;
V_105 = 0x100 ;
}
else {
if ( V_111 )
V_104 = V_112 ;
else
V_104 = F_15 ( V_108 ) ?
F_54 ( V_93 ) : V_110 ;
V_105 = 0 ;
}
F_9 ( V_87 ) ;
F_13 ( V_113 , V_111 ? 1 : V_92 ) ;
F_53 () ;
if ( V_100 -> V_95 ) {
V_25 = F_19 ( V_23 ) ;
F_53 () ;
F_13 ( V_23 , V_25 >> V_100 -> V_95 ) ;
}
F_14 ( 25 ) ;
F_10 ( V_12 ) ;
V_28 . V_114 = ( unsigned char ) V_104 ;
F_53 () ;
V_104 >>= 8 ;
V_28 . V_115 = ( unsigned char ) V_104 ;
F_53 () ;
V_104 >>= 8 ;
if ( F_15 ( V_108 ) )
V_116 = ( unsigned short ) V_104 ;
else
V_28 . V_117 = ( unsigned char ) V_104 ;
F_53 () ;
F_11 ( V_12 ) ;
V_28 . V_118 = 0x90 | V_105 ;
F_53 () ;
V_28 . V_118 = 0x90 | ( V_105 ^ 0x100 ) ;
F_53 () ;
V_28 . V_118 = 0x90 | V_105 ;
F_53 () ;
V_28 . V_119 = V_111 ? V_100 -> V_82 : 1 ;
F_14 ( 25 ) ;
V_28 . V_118 = V_120 | V_105 ;
F_14 ( 25 ) ;
F_51 ( V_121 ) ;
V_28 . V_119 =
( F_24 () |
( V_105 ? V_122 : ( V_123 | ( V_111 ? V_124 : 0 ) ) ) ) ;
V_106 = V_35 ;
V_35 = 1 ;
V_99 = 1 ;
if ( V_111 ) {
V_125 = 1 ;
F_4 ( & V_126 ,
V_4 + V_37 / 5 + ( V_106 ? 0 : V_37 ) ) ;
}
F_6 () ;
}
static void F_56 ( unsigned long V_31 )
{
unsigned long V_12 , V_127 , V_128 ;
F_10 ( V_12 ) ;
if ( ! V_125 ) {
F_11 ( V_12 ) ;
return;
}
V_127 = 0 ;
do {
V_128 = V_127 ;
V_127 = V_28 . V_114 & 0xff ;
F_53 () ;
V_127 |= ( V_28 . V_115 & 0xff ) << 8 ;
F_53 () ;
if ( F_15 ( V_108 ) )
V_127 |= ( V_116 & 0xffff ) << 16 ;
else
V_127 |= ( V_28 . V_117 & 0xff ) << 16 ;
F_53 () ;
} while( V_127 != V_128 );
if ( V_127 >= V_112 + V_100 -> V_82 * 512 ) {
F_51 ( NULL ) ;
V_125 = 0 ;
F_11 ( V_12 ) ;
F_21 ( ( L_15 ) ) ;
F_13 ( V_96 , V_129 ) ;
F_14 ( 25 ) ;
F_57 ( 0 ) ;
}
else {
F_11 ( V_12 ) ;
F_21 ( ( L_16 ) ) ;
F_4 ( & V_126 , V_4 + V_37 / 5 / 10 ) ;
}
}
static void V_121 ( int V_32 )
{
F_21 ( ( L_17 ) ) ;
if ( V_111 ) {
F_8 ( & V_126 ) ;
if ( ! V_125 )
return;
V_125 = 0 ;
}
F_57 ( V_32 ) ;
}
static void F_57 ( int V_32 )
{
unsigned int V_25 ;
F_7 () ;
if ( V_100 -> V_95 ) {
V_25 = F_19 ( V_23 ) ;
F_53 () ;
F_13 ( V_23 , V_25 << V_100 -> V_95 ) ;
}
if ( ! V_88 ) {
V_28 . V_118 = 0x90 ;
F_53 () ;
if ( ! ( V_28 . V_118 & 0x01 ) ) {
F_32 ( V_59 L_18 , V_18 ) ;
goto V_130;
}
}
F_53 () ;
if ( V_90 == V_107 && ( V_32 & V_41 ) ) {
F_32 ( V_131 L_19 , V_18 ) ;
goto V_130;
}
if ( ( V_32 & V_101 ) &&
! ( V_111 && F_19 ( V_113 ) > V_100 -> V_82 ) ) {
if ( V_132 ) {
if ( V_100 > V_80 ) {
if ( V_100 [ - 1 ] . V_81 > V_133 ) {
V_100 -- ;
F_58 ( V_134 [ V_18 ] . V_135 ,
V_100 -> V_81 ) ;
} else
V_132 = 0 ;
}
else {
if ( V_63 . V_12 & V_136 )
F_32 ( V_137 L_20 ,
V_18 , V_100 -> V_138 ) ;
V_132 = 0 ;
}
} else {
if ( V_63 . V_139 ) {
V_100 = V_80 + V_140 [ V_77 ] ;
F_58 ( V_134 [ V_18 ] . V_135 ,
V_100 -> V_81 ) ;
V_132 = 1 ;
}
}
if ( V_132 ) {
if ( F_15 ( V_27 ) ) {
V_28 . V_29 = V_100 -> V_29 ;
F_53 () ;
}
F_45 ( V_18 ) ;
V_84 = - 1 ;
F_40 ( V_18 ) ;
return;
}
F_32 ( V_59 L_21 ,
V_18 , F_19 ( V_113 ) , V_87 , V_86 ) ;
goto V_130;
}
if ( V_32 & V_141 ) {
F_32 ( V_59 L_22 ,
V_18 , V_87 , V_86 , F_19 ( V_113 ) ) ;
goto V_130;
}
if ( V_32 & V_142 ) {
F_32 ( V_59 L_23 ,
V_18 , V_87 , V_86 , F_19 ( V_113 ) ) ;
goto V_130;
}
V_132 = 0 ;
if ( V_90 == V_91 ) {
if ( ! V_111 ) {
void * V_127 ;
V_127 = F_15 ( V_108 ) ? V_93 : V_109 ;
F_55 ( F_54 ( V_127 ) , 512 , 0 ) ;
if ( ! F_15 ( V_108 ) )
F_25 ( V_127 , V_93 ) ;
} else {
F_55 ( V_112 , V_143 [ V_77 ] * 512 , 0 ) ;
V_84 = V_18 ;
V_144 = V_87 ;
V_145 = V_86 ;
F_25 ( F_43 ( V_92 ) , V_93 ) ;
}
}
if ( ++ V_94 < F_44 ( V_2 ) ) {
F_45 ( V_18 ) ;
F_40 ( V_18 ) ;
}
else {
F_1 ( 0 ) ;
F_33 () ;
}
return;
V_130:
V_84 = - 1 ;
F_30 () ;
}
static void F_48 ( void )
{
unsigned long V_104 , V_12 ;
unsigned int V_25 ;
F_21 ( ( L_24 , V_86 , V_87 ) ) ;
V_104 = V_112 ;
F_55 ( V_104 , V_85 , 1 ) ;
F_9 ( V_87 ) ;
if ( V_100 -> V_95 ) {
V_25 = F_19 ( V_23 ) ;
F_53 () ;
F_13 ( V_23 , V_25 >> V_100 -> V_95 ) ;
}
F_14 ( 40 ) ;
F_10 ( V_12 ) ;
V_28 . V_114 = ( unsigned char ) V_104 ;
F_53 () ;
V_104 >>= 8 ;
V_28 . V_115 = ( unsigned char ) V_104 ;
F_53 () ;
V_104 >>= 8 ;
if ( F_15 ( V_108 ) )
V_116 = ( unsigned short ) V_104 ;
else
V_28 . V_117 = ( unsigned char ) V_104 ;
F_53 () ;
F_11 ( V_12 ) ;
V_28 . V_118 = 0x190 ;
F_53 () ;
V_28 . V_118 = 0x90 ;
F_53 () ;
V_28 . V_118 = 0x190 ;
F_53 () ;
V_28 . V_119 = V_85 / 512 ;
F_14 ( 40 ) ;
V_28 . V_118 = V_120 | 0x100 ;
F_14 ( 40 ) ;
F_51 ( V_146 ) ;
V_28 . V_119 = V_147 | F_24 () ;
V_35 = 1 ;
F_6 () ;
}
static void V_146 ( int V_32 )
{
F_21 ( ( L_25 ) ) ;
F_7 () ;
if ( V_32 & V_41 ) {
F_32 ( V_131 L_19 , V_18 ) ;
goto V_130;
}
if ( V_32 & V_142 ) {
F_32 ( V_59 L_26 ,
V_18 , V_87 , V_86 ) ;
goto V_130;
}
F_31 ( & V_56 ) ;
return;
V_130:
F_30 () ;
}
static void F_59 ( unsigned long V_31 )
{
F_60 ( V_73 ) ;
if ( ! V_52 ) goto V_148;
F_51 ( NULL ) ;
if ( V_88 )
F_8 ( & V_126 ) ;
F_13 ( V_96 , V_129 ) ;
F_14 ( 25 ) ;
F_32 ( V_59 L_27 ) ;
F_30 () ;
V_148:
F_61 ( V_73 ) ;
}
static void F_62 ( void )
{
if ( ! V_99 ) {
F_63 ( 0 ) ;
}
else {
F_21 ( ( L_28 ) ) ;
F_13 ( V_102 , V_63 . V_25 ) ;
F_51 ( F_63 ) ;
F_13 ( V_96 , V_103 ) ;
V_35 = 1 ;
F_6 () ;
}
}
static void F_63 ( int V_31 )
{
unsigned long V_12 ;
F_21 ( ( L_29 ) ) ;
F_7 () ;
V_99 = 0 ;
if ( F_64 ( & V_7 ) && F_65 ( V_7 . V_149 , V_4 + 5 ) )
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
static unsigned int F_68 ( struct V_150 * V_135 ,
unsigned int V_151 )
{
struct V_152 * V_66 = V_135 -> V_153 ;
unsigned int V_16 = V_66 - V_134 ;
if ( F_69 ( V_16 , & V_154 ) ) {
return V_155 ;
}
if ( F_69 ( V_16 , & V_43 ) ) {
return V_155 ;
}
if ( V_24 . V_42 ) {
return V_155 ;
}
return 0 ;
}
static int F_70 ( struct V_150 * V_135 )
{
struct V_152 * V_66 = V_135 -> V_153 ;
unsigned int V_16 = V_66 - V_134 ;
if ( F_69 ( V_16 , & V_43 ) ||
F_69 ( V_16 , & V_154 ) ||
V_66 -> V_156 == 0 ) {
if ( V_24 . V_12 & V_136 )
F_32 ( V_59 L_31 , V_26 ) ;
V_84 = - 1 ;
F_71 ( V_16 , & V_154 ) ;
F_71 ( V_16 , & V_43 ) ;
if ( V_157 [ V_16 ] . V_81 == 0 )
V_26 = NULL ;
else
V_26 = & V_157 [ V_16 ] ;
}
return 0 ;
}
static void F_45 ( int V_16 )
{
int V_158 = V_133 + V_94 ;
V_86 = V_158 / V_26 -> V_82 ;
V_92 = V_158 - V_86 * V_26 -> V_82 + 1 ;
V_87 = V_86 & 1 ;
V_86 >>= 1 ;
V_93 = V_159 + 512 * V_94 ;
if ( V_88 )
V_111 = ( V_90 == V_91 && V_2 -> V_57 == 0 ) ;
else
V_111 = 0 ;
F_21 ( ( L_32 , V_87 ,
V_86 , V_92 , ( unsigned long ) V_93 ) ) ;
}
static struct V_160 * F_72 ( void )
{
struct V_161 * V_162 ;
int V_163 = V_164 ;
struct V_160 * V_165 = NULL ;
do {
V_162 = V_134 [ V_164 ] . V_135 -> V_166 ;
if ( ++ V_164 == V_167 )
V_164 = 0 ;
if ( V_162 ) {
V_165 = F_73 ( V_162 ) ;
if ( V_165 )
break;
}
} while ( V_164 != V_163 );
return V_165 ;
}
static void F_33 ( void )
{
int V_16 , type ;
struct V_152 * V_168 ;
F_21 ( ( L_33 ,
V_2 , V_2 ? V_2 -> V_169 -> V_170 : L_34 ,
V_2 ? F_74 ( V_2 ) : 0 ) ) ;
V_54 = 0 ;
V_89:
if ( ! V_2 ) {
V_2 = F_72 () ;
if ( ! V_2 )
goto V_171;
}
V_168 = V_2 -> V_169 -> V_153 ;
V_16 = V_168 - V_134 ;
type = V_168 -> type ;
if ( ! V_24 . V_40 ) {
F_32 ( V_59 L_35 , V_16 ) ;
F_1 ( - V_60 ) ;
goto V_89;
}
if ( type == 0 ) {
if ( ! V_26 ) {
V_132 = 1 ;
V_26 = V_80 + V_140 [ V_77 ] ;
F_58 ( V_168 -> V_135 , V_26 -> V_81 ) ;
V_24 . V_139 = 1 ;
}
}
else {
if ( -- type >= V_74 ) {
F_32 ( V_62 L_36 , V_16 ) ;
F_1 ( - V_60 ) ;
goto V_89;
}
if ( V_75 [ type ] . V_76 > V_77 ) {
F_32 ( V_62 L_37 , V_16 ) ;
F_1 ( - V_60 ) ;
goto V_89;
}
type = V_75 [ type ] . V_79 ;
V_26 = & V_80 [ type ] ;
F_58 ( V_168 -> V_135 , V_26 -> V_81 ) ;
V_24 . V_139 = 0 ;
}
if ( F_74 ( V_2 ) + 1 > V_26 -> V_81 ) {
F_1 ( - V_60 ) ;
goto V_89;
}
F_8 ( & V_3 ) ;
V_94 = 0 ;
V_90 = F_75 ( V_2 ) ;
V_133 = F_74 ( V_2 ) ;
V_159 = V_2 -> V_172 ;
F_45 ( V_16 ) ;
F_40 ( V_16 ) ;
return;
V_171:
F_62 () ;
}
void F_76 ( struct V_161 * V_162 )
{
F_21 ( ( L_38 , V_173 -> V_174 ) ) ;
F_35 ( V_71 , F_36 ( & V_72 , 0 , 1 ) == 0 ) ;
F_37 ( F_26 , NULL ) ;
F_60 ( V_73 ) ;
F_33 () ;
F_61 ( V_73 ) ;
}
static int F_77 ( struct V_175 * V_176 , T_3 V_177 ,
unsigned int V_178 , unsigned long V_179 )
{
struct V_150 * V_135 = V_176 -> V_180 ;
struct V_152 * V_168 = V_135 -> V_153 ;
int V_16 = V_168 - V_134 ;
int type = V_168 -> type ;
struct V_64 V_181 ;
struct V_80 * V_182 ;
struct V_183 V_184 ;
int V_185 ;
struct V_183 V_186 ;
void T_4 * V_187 = ( void T_4 * ) V_179 ;
switch ( V_178 ) {
case V_188 :
if ( type ) {
if ( -- type >= V_74 )
return - V_189 ;
if ( V_75 [ type ] . V_76 > V_77 )
return - V_189 ;
type = V_75 [ type ] . V_79 ;
V_182 = & V_80 [ type ] ;
if ( V_24 . V_12 & V_136 )
F_32 ( V_59 L_39 ,
V_16 , V_182 , V_182 -> V_138 ) ;
}
else {
if ( ! V_26 )
return - V_190 ;
else
V_182 = V_26 ;
}
memset ( ( void * ) & V_184 , 0 , sizeof( V_184 ) ) ;
V_184 . V_191 = V_182 -> V_81 ;
V_184 . V_67 = V_182 -> V_82 ;
V_184 . V_69 = 2 ;
V_184 . V_25 = V_182 -> V_81 / V_182 -> V_82 / 2 ;
V_184 . V_95 = V_182 -> V_95 ;
if ( F_78 ( V_187 , & V_184 , sizeof( V_184 ) ) )
return - V_192 ;
return 0 ;
}
switch ( V_178 ) {
case V_193 :
case V_194 :
if ( V_168 -> V_195 != 1 && V_168 -> V_195 != - 1 )
return - V_196 ;
if ( F_79 ( & V_186 , V_187 , sizeof( V_186 ) ) )
return - V_192 ;
if ( F_68 ( V_135 , 0 ) )
F_70 ( V_135 ) ;
if ( V_24 . V_12 & V_136 )
F_32 ( V_137 L_40 ,
V_16 , V_186 . V_191 , V_186 . V_67 , V_186 . V_95 ) ;
if ( type ) {
F_33 () ;
return - V_78 ;
}
for ( V_185 = 0 ; V_185 < V_74 ; V_185 ++ ) {
int V_197 = 0 ;
if ( V_75 [ V_185 ] . V_76 > V_77 ) {
continue;
}
V_197 = V_75 [ V_185 ] . V_79 ;
V_182 = & V_80 [ V_197 ] ;
if ( V_182 -> V_81 == V_186 . V_191
&& V_182 -> V_82 == V_186 . V_67
&& V_182 -> V_95 == V_186 . V_95 ) {
if ( V_24 . V_12 & V_136 )
F_32 ( V_137 L_41 ,
V_16 , V_182 -> V_138 , V_182 ) ;
V_26 = V_182 ;
F_58 ( V_168 -> V_135 , V_26 -> V_81 ) ;
if ( V_178 == V_194 ) {
V_157 [ V_16 ] . V_138 = V_182 -> V_138 ;
V_157 [ V_16 ] . V_82 = V_182 -> V_82 ;
V_157 [ V_16 ] . V_81 = V_182 -> V_81 ;
V_157 [ V_16 ] . V_29 = V_182 -> V_29 ;
V_157 [ V_16 ] . V_95 = V_182 -> V_95 ;
}
return 0 ;
}
}
if ( V_178 == V_194 ) {
V_182 = & V_157 [ V_16 ] ;
} else
V_182 = & V_198 [ V_16 ] ;
V_182 -> V_138 = L_42 ;
V_182 -> V_81 = V_186 . V_191 ;
V_182 -> V_82 = V_186 . V_67 ;
if ( V_186 . V_67 > 14 )
V_182 -> V_29 = 3 ;
else
V_182 -> V_29 = 0 ;
V_182 -> V_95 = V_186 . V_95 ;
if ( V_24 . V_12 & V_136 )
F_32 ( V_137 L_43 ,
V_16 , V_182 -> V_81 , V_182 -> V_82 , V_182 -> V_95 ) ;
if ( V_186 . V_25 != V_182 -> V_81 / V_182 -> V_82 / 2 ||
V_186 . V_69 != 2 ) {
F_33 () ;
return - V_78 ;
}
V_26 = V_182 ;
F_58 ( V_168 -> V_135 , V_26 -> V_81 ) ;
return 0 ;
case V_199 :
V_24 . V_12 |= V_136 ;
return 0 ;
case V_200 :
V_24 . V_12 &= ~ V_136 ;
return 0 ;
case V_201 :
return - V_78 ;
case V_202 :
return 0 ;
case V_203 :
if ( V_168 -> V_195 != 1 && V_168 -> V_195 != - 1 )
return - V_196 ;
if ( F_79 ( & V_181 , V_187 , sizeof( V_181 ) ) )
return - V_192 ;
return F_34 ( V_16 , type , & V_181 ) ;
case V_204 :
V_26 = NULL ;
V_157 [ V_16 ] . V_81 = 0 ;
F_58 ( V_168 -> V_135 , V_205 * 2 ) ;
case V_206 :
case V_207 :
V_84 = - 1 ;
F_22 ( V_16 , & V_154 ) ;
F_80 ( V_176 ) ;
return 0 ;
default:
return - V_78 ;
}
}
static int F_81 ( struct V_175 * V_176 , T_3 V_177 ,
unsigned int V_178 , unsigned long V_208 )
{
int V_209 ;
F_82 ( & V_210 ) ;
V_209 = F_77 ( V_176 , V_177 , V_178 , V_208 ) ;
F_83 ( & V_210 ) ;
return V_209 ;
}
static void T_5 F_84 ( int V_16 )
{
V_24 . V_40 = 0 ;
V_26 = NULL ;
if ( ! F_85 ( V_16 ) )
return;
V_24 . V_40 = 1 ;
V_24 . V_25 = 0 ;
switch( V_211 [ V_16 ] ) {
case 2 :
V_24 . V_98 = V_212 ;
break;
case 3 :
V_24 . V_98 = V_213 ;
break;
case 6 :
V_24 . V_98 = V_214 ;
break;
case 12 :
V_24 . V_98 = V_215 ;
break;
default:
if ( F_15 ( V_27 ) || V_216 )
V_24 . V_98 = V_213 ;
else
V_24 . V_98 = V_214 ;
break;
}
V_35 = 1 ;
}
static int T_5 F_85 ( int V_16 )
{
unsigned long V_217 ;
unsigned char V_32 ;
int V_218 ;
if ( V_16 >= ( V_30 ? 1 : 2 ) ) return ( 0 ) ;
F_12 ( V_16 ) ;
F_86 ( V_73 ) ;
F_13 ( V_23 , 0xff00 ) ;
F_13 ( V_96 , V_97 | V_219 | V_214 ) ;
V_217 = V_4 + 2 * V_37 + V_37 / 2 ;
while ( F_65 ( V_4 , V_217 ) )
if ( ! ( V_220 . V_221 & 0x20 ) )
break;
V_32 = F_19 ( V_34 ) ;
V_218 = ( V_32 & V_222 ) != 0 ;
F_13 ( V_96 , V_129 ) ;
F_14 ( 500 ) ;
V_32 = F_19 ( V_34 ) ;
F_14 ( 20 ) ;
if ( V_218 ) {
F_13 ( V_102 , 0 ) ;
F_13 ( V_96 , V_103 ) ;
while( V_220 . V_221 & 0x20 )
;
V_32 = F_19 ( V_34 ) ;
}
F_38 ( V_73 ) ;
return ( V_218 ) ;
}
static void T_5 F_87 ( void )
{
int V_16 , V_50 = 0 ;
if ( F_15 ( V_27 ) )
V_28 . V_29 = 0 ;
F_32 ( V_137 L_44 ) ;
for( V_16 = 0 ; V_16 < V_167 ; V_16 ++ ) {
F_84 ( V_16 ) ;
if ( V_24 . V_40 ) {
F_32 ( V_137 L_45 , V_16 ) ;
++ V_50 ;
}
}
if ( F_19 ( V_34 ) & V_223 ) {
F_13 ( V_96 , V_129 ) ;
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
static int F_88 ( struct V_175 * V_176 , T_3 V_177 )
{
struct V_152 * V_66 = V_176 -> V_180 -> V_153 ;
int type = F_89 ( V_176 -> V_224 ) >> 2 ;
F_21 ( ( L_46 , type ) ) ;
if ( V_66 -> V_195 && V_66 -> type != type )
return - V_196 ;
if ( V_66 -> V_195 == - 1 || ( V_66 -> V_195 && V_177 & V_225 ) )
return - V_196 ;
if ( V_177 & V_225 )
V_66 -> V_195 = - 1 ;
else
V_66 -> V_195 ++ ;
V_66 -> type = type ;
if ( V_177 & V_226 )
return 0 ;
if ( V_177 & ( V_227 | V_228 ) ) {
F_80 ( V_176 ) ;
if ( V_177 & V_228 ) {
if ( V_66 -> V_42 ) {
if ( V_66 -> V_195 < 0 )
V_66 -> V_195 = 0 ;
else
V_66 -> V_195 -- ;
return - V_229 ;
}
}
}
return 0 ;
}
static int F_90 ( struct V_175 * V_176 , T_3 V_177 )
{
int V_209 ;
F_82 ( & V_210 ) ;
V_209 = F_88 ( V_176 , V_177 ) ;
F_83 ( & V_210 ) ;
return V_209 ;
}
static void F_91 ( struct V_150 * V_135 , T_3 V_177 )
{
struct V_152 * V_66 = V_135 -> V_153 ;
F_82 ( & V_210 ) ;
if ( V_66 -> V_195 < 0 )
V_66 -> V_195 = 0 ;
else if ( ! V_66 -> V_195 -- ) {
F_32 ( V_59 L_47 ) ;
V_66 -> V_195 = 0 ;
}
F_83 ( & V_210 ) ;
}
static struct V_230 * F_92 ( T_6 V_231 , int * V_232 , void * V_233 )
{
int V_16 = * V_232 & 3 ;
int type = * V_232 >> 2 ;
if ( V_16 >= V_167 || type > V_74 )
return NULL ;
* V_232 = 0 ;
return F_93 ( V_134 [ V_16 ] . V_135 ) ;
}
static int T_5 F_94 ( void )
{
int V_234 ;
if ( ! V_235 )
return - V_189 ;
if ( F_95 ( V_236 , L_48 ) )
return - V_196 ;
for ( V_234 = 0 ; V_234 < V_167 ; V_234 ++ ) {
V_134 [ V_234 ] . V_135 = F_96 ( 1 ) ;
if ( ! V_134 [ V_234 ] . V_135 )
goto V_237;
}
if ( V_88 < 0 )
V_88 = ! V_216 ;
V_18 = - 1 ;
V_84 = - 1 ;
V_109 = F_97 ( V_85 + 512 , L_49 ) ;
if ( ! V_109 ) {
F_32 ( V_59 L_50 ) ;
goto V_237;
}
V_83 = V_109 + 512 ;
V_110 = F_54 ( V_109 ) ;
V_112 = F_54 ( V_83 ) ;
V_84 = V_144 = V_145 = - 1 ;
for ( V_234 = 0 ; V_234 < V_167 ; V_234 ++ ) {
V_134 [ V_234 ] . V_25 = - 1 ;
V_134 [ V_234 ] . V_12 = 0 ;
V_134 [ V_234 ] . V_135 -> V_238 = V_236 ;
V_134 [ V_234 ] . V_135 -> V_239 = V_234 ;
sprintf ( V_134 [ V_234 ] . V_135 -> V_170 , L_51 , V_234 ) ;
V_134 [ V_234 ] . V_135 -> V_240 = & V_241 ;
V_134 [ V_234 ] . V_135 -> V_153 = & V_134 [ V_234 ] ;
V_134 [ V_234 ] . V_135 -> V_166 = F_98 ( F_76 ,
& V_242 ) ;
if ( ! V_134 [ V_234 ] . V_135 -> V_166 )
goto V_237;
F_58 ( V_134 [ V_234 ] . V_135 , V_205 * 2 ) ;
F_99 ( V_134 [ V_234 ] . V_135 ) ;
}
F_100 ( F_101 ( V_236 , 0 ) , 256 , V_243 ,
F_92 , NULL , NULL ) ;
F_32 ( V_137 L_52 ,
V_77 == 0 ? 'D' : V_77 == 1 ? 'H' : 'E' ,
V_88 ? L_34 : L_53 ) ;
F_87 () ;
return 0 ;
V_237:
while ( V_234 -- ) {
struct V_161 * V_162 = V_134 [ V_234 ] . V_135 -> V_166 ;
F_102 ( V_134 [ V_234 ] . V_135 ) ;
if ( V_162 )
F_103 ( V_162 ) ;
}
F_104 ( V_236 , L_48 ) ;
return - V_244 ;
}
static int T_5 F_105 ( char * V_245 )
{
int V_246 [ 3 + V_167 ] ;
int V_234 ;
if ( ! V_235 )
return 0 ;
V_245 = F_106 ( V_245 , 3 + V_167 , V_246 ) ;
if ( V_246 [ 0 ] < 1 ) {
F_32 ( V_59 L_54 ) ;
return 0 ;
}
else if ( V_246 [ 0 ] > 2 + V_167 ) {
F_32 ( V_59 L_55 ) ;
}
if ( V_246 [ 1 ] < 0 || V_246 [ 1 ] > 2 )
F_32 ( V_59 L_56 ) ;
else
V_77 = V_246 [ 1 ] ;
if ( V_246 [ 0 ] >= 2 )
V_88 = ( V_246 [ 2 ] > 0 ) ;
for( V_234 = 3 ; V_234 <= V_246 [ 0 ] && V_234 - 3 < V_167 ; ++ V_234 ) {
if ( V_246 [ V_234 ] != 2 && V_246 [ V_234 ] != 3 && V_246 [ V_234 ] != 6 && V_246 [ V_234 ] != 12 )
F_32 ( V_59 L_57 ) ;
else
V_211 [ V_234 - 3 ] = V_246 [ V_234 ] ;
}
return 1 ;
}
static void T_7 F_107 ( void )
{
int V_234 ;
F_108 ( F_101 ( V_236 , 0 ) , 256 ) ;
for ( V_234 = 0 ; V_234 < V_167 ; V_234 ++ ) {
struct V_161 * V_162 = V_134 [ V_234 ] . V_135 -> V_166 ;
F_109 ( V_134 [ V_234 ] . V_135 ) ;
F_102 ( V_134 [ V_234 ] . V_135 ) ;
F_103 ( V_162 ) ;
}
F_104 ( V_236 , L_48 ) ;
F_110 ( & V_7 ) ;
F_111 ( V_109 ) ;
}
