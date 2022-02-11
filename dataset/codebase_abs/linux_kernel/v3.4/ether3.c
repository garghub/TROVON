static inline void F_1 ( int V_1 , const void T_1 * V_2 )
{
F_2 ( V_1 , V_2 ) ;
F_3 ( 1 ) ;
}
static inline void F_4 ( int V_1 , const void T_1 * V_2 )
{
F_5 ( V_1 , V_2 ) ;
F_3 ( 1 ) ;
}
static int
F_6 ( struct V_3 * V_4 , T_2 V_5 , int V_6 )
{
int V_7 = 1000 ;
F_4 ( F_7 ( V_4 ) -> V_8 . V_9 | V_10 , V_11 ) ;
F_4 ( F_7 ( V_4 ) -> V_8 . V_12 | V_13 , V_14 ) ;
while ( ( F_8 ( V_15 ) & V_16 ) == 0 ) {
if ( ! V_7 -- ) {
F_9 ( L_1 , V_4 -> V_17 ) ;
F_7 ( V_4 ) -> V_18 = 1 ;
return 1 ;
}
F_3 ( 1 ) ;
}
if ( V_5 == V_19 ) {
F_4 ( V_6 , V_20 ) ;
F_4 ( F_7 ( V_4 ) -> V_8 . V_12 | V_21 , V_14 ) ;
} else {
F_4 ( F_7 ( V_4 ) -> V_8 . V_12 | V_13 , V_14 ) ;
F_4 ( V_6 , V_20 ) ;
}
return 0 ;
}
static void F_10 ( unsigned long V_22 )
{
struct V_3 * V_4 = (struct V_3 * ) V_22 ;
F_4 ( F_7 ( V_4 ) -> V_8 . V_23 |= V_24 , V_25 ) ;
}
static inline void F_11 ( struct V_3 * V_4 )
{
F_12 ( & F_7 ( V_4 ) -> V_26 ) ;
F_7 ( V_4 ) -> V_26 . V_27 = V_28 + V_29 / 50 ;
F_7 ( V_4 ) -> V_26 . V_22 = ( unsigned long ) V_4 ;
F_7 ( V_4 ) -> V_26 . V_30 = F_10 ;
F_13 ( & F_7 ( V_4 ) -> V_26 ) ;
if ( F_7 ( V_4 ) -> V_8 . V_23 & V_24 )
F_4 ( F_7 ( V_4 ) -> V_8 . V_23 &= ~ V_24 , V_25 ) ;
}
static int T_3
F_14 ( char * V_31 , struct V_32 * V_33 )
{
struct V_34 V_35 ;
char * V_36 ;
if ( F_15 ( & V_35 , V_33 , 0xf5 , 0 ) && ( V_36 = strchr ( V_35 . V_37 . string , '(' ) ) ) {
int V_38 ;
for ( V_38 = 0 ; V_38 < 6 ; V_38 ++ ) {
V_31 [ V_38 ] = F_16 ( V_36 + 1 , & V_36 , 0x10 ) ;
if ( * V_36 != ( V_38 == 5 ? ')' : ':' ) )
break;
}
if ( V_38 == 6 )
return 0 ;
}
F_9 ( V_39 L_2 ) ;
return - V_40 ;
}
static int T_3
F_17 ( struct V_3 * V_4 , unsigned char V_41 )
{
unsigned char * V_42 = F_18 ( V_43 , V_44 ) ;
int V_38 , V_45 = 0 ;
int V_46 = 4 ;
int V_47 = - 1 ;
if ( ! V_42 )
return 1 ;
memset ( V_42 , V_41 , V_43 ) ;
F_6 ( V_4 , V_48 , 0 ) ;
F_19 ( V_4 , V_42 , V_49 ) ;
F_6 ( V_4 , V_48 , V_50 ) ;
F_19 ( V_4 , V_42 + V_50 , V_51 ) ;
memset ( V_42 , V_41 ^ 0xff , V_43 ) ;
F_6 ( V_4 , V_19 , 0 ) ;
F_20 ( V_4 , V_42 , V_49 ) ;
F_6 ( V_4 , V_19 , V_50 ) ;
F_20 ( V_4 , V_42 + V_50 , V_51 ) ;
for ( V_38 = 0 ; V_38 < V_43 ; V_38 ++ ) {
if ( V_42 [ V_38 ] != V_41 ) {
if ( V_46 > 0 && V_47 != V_42 [ V_38 ] ) {
F_9 ( L_3 ,
V_4 -> V_17 , V_42 [ V_38 ] , V_41 , V_38 ) ;
V_45 = 2 ;
V_46 -- ;
V_47 = V_38 ;
}
} else {
if ( V_47 != - 1 ) {
if ( V_47 != V_38 - 1 )
F_9 ( L_4 , V_38 - 1 ) ;
F_9 ( L_5 ) ;
V_47 = - 1 ;
}
}
}
if ( V_47 != - 1 )
F_9 ( L_6 ) ;
F_21 ( V_42 ) ;
return V_45 ;
}
static int T_3 F_22 ( struct V_3 * V_4 )
{
int V_38 ;
F_7 ( V_4 ) -> V_8 . V_9 = V_52 | V_53 ;
F_7 ( V_4 ) -> V_8 . V_23 = V_24 | V_54 | V_55 ;
F_7 ( V_4 ) -> V_8 . V_12 = 0 ;
F_4 ( F_7 ( V_4 ) -> V_8 . V_9 | V_56 , V_11 ) ;
for ( V_38 = 0 ; V_38 < 6 ; V_38 ++ )
F_1 ( V_4 -> V_57 [ V_38 ] , V_58 ) ;
if ( V_4 -> V_59 & V_60 )
F_7 ( V_4 ) -> V_8 . V_9 |= V_61 ;
else if ( V_4 -> V_59 & V_62 )
F_7 ( V_4 ) -> V_8 . V_9 |= V_63 ;
else
F_7 ( V_4 ) -> V_8 . V_9 |= V_64 ;
F_4 ( F_7 ( V_4 ) -> V_8 . V_9 | V_65 , V_11 ) ;
F_4 ( ( V_49 >> 8 ) - 1 , V_58 ) ;
F_4 ( F_7 ( V_4 ) -> V_66 , V_67 ) ;
F_4 ( 0 , V_68 ) ;
F_4 ( F_7 ( V_4 ) -> V_66 >> 8 , V_69 ) ;
F_4 ( F_7 ( V_4 ) -> V_8 . V_23 , V_25 ) ;
F_4 ( F_7 ( V_4 ) -> V_8 . V_9 | V_10 , V_11 ) ;
F_4 ( F_7 ( V_4 ) -> V_8 . V_12 , V_14 ) ;
V_38 = F_17 ( V_4 , 0x5A ) ;
if( V_38 )
return V_38 ;
V_38 = F_17 ( V_4 , 0x1E ) ;
if( V_38 )
return V_38 ;
F_6 ( V_4 , V_48 , 0 ) ;
F_23 ( V_4 , 0 ) ;
return 0 ;
}
static void
F_24 ( struct V_3 * V_4 )
{
int V_38 ;
F_4 ( V_70 , V_25 ) ;
F_3 ( 4 ) ;
F_7 ( V_4 ) -> V_8 . V_12 = 0 ;
F_4 ( V_71 | V_72 , V_14 ) ;
while ( F_8 ( V_15 ) & ( V_73 | V_74 ) )
F_25 () ;
F_4 ( F_7 ( V_4 ) -> V_8 . V_9 | V_56 , V_11 ) ;
for ( V_38 = 0 ; V_38 < 6 ; V_38 ++ )
F_1 ( V_4 -> V_57 [ V_38 ] , V_58 ) ;
F_7 ( V_4 ) -> V_75 = 0 ;
F_7 ( V_4 ) -> V_76 = 0 ;
F_7 ( V_4 ) -> V_8 . V_23 |= V_24 ;
F_7 ( V_4 ) -> V_66 = V_50 ;
F_4 ( F_7 ( V_4 ) -> V_8 . V_9 | V_65 , V_11 ) ;
F_4 ( ( V_49 >> 8 ) - 1 , V_58 ) ;
F_4 ( F_7 ( V_4 ) -> V_66 , V_67 ) ;
F_4 ( F_7 ( V_4 ) -> V_66 >> 8 , V_69 ) ;
F_4 ( 0 , V_68 ) ;
F_4 ( F_7 ( V_4 ) -> V_8 . V_23 , V_25 ) ;
F_4 ( F_7 ( V_4 ) -> V_8 . V_9 | V_10 , V_11 ) ;
F_6 ( V_4 , V_48 , 0 ) ;
F_23 ( V_4 , 0 ) ;
F_7 ( V_4 ) -> V_8 . V_12 = V_77 | V_78 ;
F_4 ( F_7 ( V_4 ) -> V_8 . V_12 | V_79 , V_14 ) ;
}
static inline int
F_26 ( struct V_3 * V_4 , int V_80 )
{
int V_81 , V_82 , V_83 , V_84 ;
V_81 = V_80 & 255 ;
V_82 = V_80 >> 8 ;
F_9 ( V_85 L_7 , V_82 , V_81 ) ;
F_1 ( V_81 , V_67 ) ;
F_1 ( V_82 , V_67 + 4 ) ;
V_83 = F_27 ( V_67 ) ;
V_84 = F_27 ( V_67 + 4 ) ;
F_9 ( L_8 , V_84 , V_83 ) ;
return V_83 == V_81 && V_84 == V_82 ;
}
static inline int
F_28 ( struct V_3 * V_4 , int V_80 )
{
int V_86 ;
F_4 ( V_80 , V_67 ) ;
V_86 = F_8 ( V_67 ) ;
F_9 ( V_85 L_9 , V_80 , V_86 ) ;
return V_86 == V_80 ;
}
static int
F_29 ( struct V_3 * V_4 )
{
if ( ! F_30 ( V_4 -> V_57 ) ) {
F_9 ( V_87 L_10 ,
V_4 -> V_17 ) ;
return - V_88 ;
}
if ( F_31 ( V_4 -> V_89 , V_90 , 0 , L_11 , V_4 ) )
return - V_91 ;
F_24 ( V_4 ) ;
F_32 ( V_4 ) ;
return 0 ;
}
static int
F_33 ( struct V_3 * V_4 )
{
F_34 ( V_4 ) ;
F_35 ( V_4 -> V_89 ) ;
F_4 ( V_71 | V_72 , V_14 ) ;
F_7 ( V_4 ) -> V_8 . V_12 = 0 ;
while ( F_8 ( V_15 ) & ( V_73 | V_74 ) )
F_25 () ;
F_1 ( 0x80 , V_25 + 4 ) ;
F_4 ( 0 , V_14 ) ;
F_36 ( V_4 -> V_89 , V_4 ) ;
return 0 ;
}
static void F_37 ( struct V_3 * V_4 )
{
F_7 ( V_4 ) -> V_8 . V_9 &= ~ V_61 ;
if ( V_4 -> V_59 & V_60 ) {
F_7 ( V_4 ) -> V_8 . V_9 |= V_61 ;
} else if ( V_4 -> V_59 & V_92 || ! F_38 ( V_4 ) ) {
F_7 ( V_4 ) -> V_8 . V_9 |= V_63 ;
} else
F_7 ( V_4 ) -> V_8 . V_9 |= V_64 ;
F_4 ( F_7 ( V_4 ) -> V_8 . V_9 | V_10 , V_11 ) ;
}
static void F_39 ( struct V_3 * V_4 )
{
unsigned long V_59 ;
F_12 ( & F_7 ( V_4 ) -> V_26 ) ;
F_40 ( V_59 ) ;
F_9 ( V_39 L_12 , V_4 -> V_17 ) ;
F_9 ( V_39 L_13 , V_4 -> V_17 ,
F_8 ( V_15 ) , F_8 ( V_11 ) , F_8 ( V_25 ) ) ;
F_9 ( V_39 L_14 , V_4 -> V_17 ,
F_8 ( V_67 ) , F_8 ( V_69 ) , F_8 ( V_68 ) ) ;
F_9 ( V_39 L_15 , V_4 -> V_17 ,
F_7 ( V_4 ) -> V_75 , F_7 ( V_4 ) -> V_76 ) ;
F_6 ( V_4 , V_19 , F_7 ( V_4 ) -> V_76 ) ;
F_9 ( V_39 L_16 , V_4 -> V_17 , F_41 ( V_4 ) ) ;
F_42 ( V_59 ) ;
F_7 ( V_4 ) -> V_8 . V_23 |= V_24 ;
V_4 -> V_93 . V_94 += 1 ;
F_4 ( F_7 ( V_4 ) -> V_8 . V_23 , V_25 ) ;
F_7 ( V_4 ) -> V_75 = F_7 ( V_4 ) -> V_76 = 0 ;
F_43 ( V_4 ) ;
}
static int
F_44 ( struct V_95 * V_96 , struct V_3 * V_4 )
{
unsigned long V_59 ;
unsigned int V_97 = V_98 < V_96 -> V_99 ? V_96 -> V_99 : V_98 ;
unsigned int V_100 , V_101 ;
if ( F_7 ( V_4 ) -> V_18 ) {
F_45 ( V_96 ) ;
V_4 -> V_93 . V_102 ++ ;
F_32 ( V_4 ) ;
return V_103 ;
}
V_97 = ( V_97 + 1 ) & ~ 1 ;
if ( V_97 != V_96 -> V_99 ) {
if ( F_46 ( V_96 , V_97 ) )
goto V_104;
}
V_101 = ( F_7 ( V_4 ) -> V_75 + 1 ) & 15 ;
F_40 ( V_59 ) ;
if ( F_7 ( V_4 ) -> V_76 == V_101 ) {
F_42 ( V_59 ) ;
return V_105 ;
}
V_100 = 0x600 * F_7 ( V_4 ) -> V_75 ;
F_7 ( V_4 ) -> V_75 = V_101 ;
V_101 *= 0x600 ;
#define F_47 (TXHDR_TRANSMIT|TXHDR_CHAINCONTINUE|TXHDR_DATAFOLLOWS|TXHDR_ENSUCCESS)
F_6 ( V_4 , V_48 , V_101 ) ;
F_23 ( V_4 , 0 ) ;
F_6 ( V_4 , V_48 , V_100 ) ;
F_23 ( V_4 , 0 ) ;
F_19 ( V_4 , V_96 -> V_22 , V_97 ) ;
F_48 ( V_4 , F_49 ( V_101 ) ) ;
F_48 ( V_4 , V_106 >> 16 ) ;
F_6 ( V_4 , V_48 , V_100 ) ;
F_48 ( V_4 , F_49 ( ( V_100 + V_97 + 4 ) ) ) ;
F_48 ( V_4 , F_47 >> 16 ) ;
F_11 ( V_4 ) ;
if ( ! ( F_8 ( V_15 ) & V_74 ) ) {
F_4 ( V_100 , V_68 ) ;
F_4 ( F_7 ( V_4 ) -> V_8 . V_12 | V_107 , V_14 ) ;
}
V_101 = ( F_7 ( V_4 ) -> V_75 + 1 ) & 15 ;
F_42 ( V_59 ) ;
F_45 ( V_96 ) ;
if ( F_7 ( V_4 ) -> V_76 == V_101 )
F_34 ( V_4 ) ;
V_104:
return V_103 ;
}
static T_4
V_90 ( int V_89 , void * V_108 )
{
struct V_3 * V_4 = (struct V_3 * ) V_108 ;
unsigned int V_109 , V_110 = V_111 ;
#if V_112 > 1
if( V_113 & V_114 )
F_9 ( L_17 , V_89 ) ;
#endif
V_109 = F_8 ( V_15 ) ;
if ( V_109 & V_115 ) {
F_4 ( V_116 | F_7 ( V_4 ) -> V_8 . V_12 , V_14 ) ;
F_50 ( V_4 , 12 ) ;
V_110 = V_117 ;
}
if ( V_109 & V_118 ) {
F_4 ( V_119 | F_7 ( V_4 ) -> V_8 . V_12 , V_14 ) ;
F_51 ( V_4 ) ;
V_110 = V_117 ;
}
#if V_112 > 1
if( V_113 & V_114 )
F_9 ( L_18 ) ;
#endif
return V_110 ;
}
static int F_50 ( struct V_3 * V_4 , unsigned int V_120 )
{
unsigned int V_101 = F_7 ( V_4 ) -> V_66 , V_121 = 0 ;
F_11 ( V_4 ) ;
do {
unsigned int V_122 , V_109 ;
unsigned char V_123 [ 16 ] ;
{
unsigned int V_124 ;
F_6 ( V_4 , V_19 , V_101 ) ;
V_124 = F_52 ( V_4 ) ;
V_109 = F_52 ( V_4 ) ;
if ( ( V_109 & ( V_125 | V_126 | V_127 ) ) !=
( V_125 | V_126 ) || ! V_124 )
break;
V_122 = V_101 + 4 ;
V_101 = F_53 ( V_124 ) ;
}
F_6 ( V_4 , V_19 , V_122 ) ;
F_20 ( V_4 , V_123 + 2 , 12 ) ;
if ( V_101 < V_50 || V_101 >= V_43 ) {
int V_38 ;
F_9 ( L_19 , V_4 -> V_17 , F_7 ( V_4 ) -> V_66 ) ;
F_9 ( L_20 , V_101 >> 8 , V_101 & 255 , V_109 & 255 , V_109 >> 8 ) ;
for ( V_38 = 2 ; V_38 < 14 ; V_38 ++ )
F_9 ( L_21 , V_123 [ V_38 ] ) ;
F_9 ( L_5 ) ;
V_101 = F_7 ( V_4 ) -> V_66 ;
break;
}
if ( ! ( * ( unsigned long * ) & V_4 -> V_57 [ 0 ] ^ * ( unsigned long * ) & V_123 [ 2 + 6 ] ) &&
! ( * ( unsigned short * ) & V_4 -> V_57 [ 4 ] ^ * ( unsigned short * ) & V_123 [ 2 + 10 ] ) ) {
V_120 ++ ;
F_4 ( V_101 >> 8 , V_69 ) ;
} else
if ( ! ( V_109 & ( V_128 | V_129 | V_130 | V_131 ) ) ) {
unsigned int V_97 = V_101 - V_122 ;
struct V_95 * V_96 ;
if ( V_101 <= V_122 )
V_97 += V_43 - V_50 ;
V_96 = F_54 ( V_4 , V_97 + 2 ) ;
if ( V_96 ) {
unsigned char * V_132 ;
F_55 ( V_96 , 2 ) ;
V_132 = F_56 ( V_96 , V_97 ) ;
F_20 ( V_4 , V_132 + 12 , V_97 - 12 ) ;
F_4 ( V_101 >> 8 , V_69 ) ;
* ( unsigned short * ) ( V_132 + 0 ) = * ( unsigned short * ) ( V_123 + 2 ) ;
* ( unsigned long * ) ( V_132 + 2 ) = * ( unsigned long * ) ( V_123 + 4 ) ;
* ( unsigned long * ) ( V_132 + 6 ) = * ( unsigned long * ) ( V_123 + 8 ) ;
* ( unsigned short * ) ( V_132 + 10 ) = * ( unsigned short * ) ( V_123 + 12 ) ;
V_96 -> V_133 = F_57 ( V_96 , V_4 ) ;
F_58 ( V_96 ) ;
V_121 ++ ;
} else
goto V_134;
} else {
struct V_135 * V_93 = & V_4 -> V_93 ;
F_4 ( V_101 >> 8 , V_69 ) ;
if ( V_109 & V_128 ) V_93 -> V_136 ++ ;
if ( V_109 & V_129 ) V_93 -> V_137 ++ ;
if ( V_109 & V_130 ) V_93 -> V_138 ++ ;
if ( V_109 & V_131 ) V_93 -> V_139 ++ ;
V_93 -> V_140 ++ ;
}
}
while ( -- V_120 );
V_141:
V_4 -> V_93 . V_142 += V_121 ;
F_7 ( V_4 ) -> V_66 = V_101 ;
if ( ! ( F_8 ( V_15 ) & V_73 ) ) {
V_4 -> V_93 . V_143 ++ ;
F_4 ( V_101 , V_67 ) ;
F_4 ( F_7 ( V_4 ) -> V_8 . V_12 | V_79 , V_14 ) ;
}
return V_120 ;
V_134: {
static unsigned long V_144 ;
F_4 ( V_101 >> 8 , V_69 ) ;
if ( F_59 ( V_28 , V_144 + 10 * V_29 ) ) {
V_144 = V_28 ;
F_9 ( L_22 , V_4 -> V_17 ) ;
}
V_4 -> V_93 . V_143 ++ ;
goto V_141;
}
}
static void F_51 ( struct V_3 * V_4 )
{
unsigned int V_76 = F_7 ( V_4 ) -> V_76 ;
int V_145 = 14 ;
do {
unsigned long V_109 ;
F_6 ( V_4 , V_19 , V_76 * 0x600 ) ;
V_109 = F_41 ( V_4 ) ;
if ( ( V_109 & ( V_146 | V_147 ) ) !=
( V_146 | V_147 ) )
break;
if ( ! ( V_109 & ( V_148 | V_149 ) ) )
V_4 -> V_93 . V_150 ++ ;
else {
V_4 -> V_93 . V_94 ++ ;
if ( V_109 & V_149 )
V_4 -> V_93 . V_151 += 16 ;
if ( V_109 & V_148 )
V_4 -> V_93 . V_152 ++ ;
}
V_76 = ( V_76 + 1 ) & 15 ;
} while ( -- V_145 );
if ( F_7 ( V_4 ) -> V_76 != V_76 ) {
F_7 ( V_4 ) -> V_76 = V_76 ;
F_43 ( V_4 ) ;
}
}
static void T_3 F_60 ( void )
{
static unsigned V_153 = 0 ;
if ( V_113 && V_153 ++ == 0 )
F_9 ( V_154 L_23 , V_155 ) ;
}
static int T_3
F_61 ( struct V_32 * V_33 , const struct V_156 * V_157 )
{
const struct V_158 * V_22 = V_157 -> V_22 ;
struct V_3 * V_4 ;
int V_159 , V_45 ;
F_60 () ;
V_45 = F_62 ( V_33 ) ;
if ( V_45 )
goto V_104;
V_4 = F_63 ( sizeof( struct V_160 ) ) ;
if ( ! V_4 ) {
V_45 = - V_161 ;
goto V_162;
}
F_64 ( V_4 , & V_33 -> V_4 ) ;
F_7 ( V_4 ) -> V_163 = F_65 ( V_33 , V_164 , 0 , 0 ) ;
if ( ! F_7 ( V_4 ) -> V_163 ) {
V_45 = - V_161 ;
goto free;
}
V_33 -> V_165 = F_7 ( V_4 ) -> V_163 + V_22 -> V_166 ;
V_33 -> V_167 = 0xf0 ;
F_7 ( V_4 ) -> V_168 = F_7 ( V_4 ) -> V_163 + V_22 -> V_166 ;
V_4 -> V_89 = V_33 -> V_89 ;
F_14 ( V_4 -> V_57 , V_33 ) ;
F_66 ( & F_7 ( V_4 ) -> V_26 ) ;
F_1 ( 0x80 , V_25 + 4 ) ;
V_159 = V_169 ;
F_3 ( 4 ) ;
if ( F_26 ( V_4 , 0x100 ) &&
F_26 ( V_4 , 0x201 ) )
V_159 = V_170 ;
if ( V_159 == V_169 &&
F_28 ( V_4 , 0x101 ) &&
F_28 ( V_4 , 0x201 ) )
V_159 = V_171 ;
switch ( V_159 ) {
case V_169 :
F_9 ( V_39 L_24 , V_4 -> V_17 ) ;
V_45 = - V_40 ;
goto free;
case V_170 :
F_9 ( V_39 L_25
L_26 , V_4 -> V_17 , V_22 -> V_17 ) ;
V_45 = - V_40 ;
goto free;
default:
break;
}
if ( F_22 ( V_4 ) ) {
V_45 = - V_40 ;
goto free;
}
V_4 -> V_172 = & V_173 ;
V_4 -> V_174 = 5 * V_29 / 100 ;
V_45 = F_67 ( V_4 ) ;
if ( V_45 )
goto free;
F_9 ( L_27 ,
V_4 -> V_17 , V_22 -> V_17 , V_33 -> V_175 , V_4 -> V_57 ) ;
F_68 ( V_33 , V_4 ) ;
return 0 ;
free:
F_69 ( V_4 ) ;
V_162:
F_70 ( V_33 ) ;
V_104:
return V_45 ;
}
static void T_5 F_71 ( struct V_32 * V_33 )
{
struct V_3 * V_4 = F_72 ( V_33 ) ;
F_68 ( V_33 , NULL ) ;
F_73 ( V_4 ) ;
F_69 ( V_4 ) ;
F_70 ( V_33 ) ;
}
static int T_6 F_74 ( void )
{
return F_75 ( & V_176 ) ;
}
static void T_7 F_76 ( void )
{
F_77 ( & V_176 ) ;
}
