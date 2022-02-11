static inline void F_1 ( int V_1 , void T_1 * V_2 )
{
F_2 ( V_1 , V_2 ) ;
F_3 ( 1 ) ;
}
static inline void F_4 ( int V_1 , void T_1 * V_2 )
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
static int
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
static int
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
static int F_22 ( struct V_3 * V_4 )
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
if ( F_30 ( V_4 -> V_87 , V_88 , 0 , L_10 , V_4 ) )
return - V_89 ;
F_24 ( V_4 ) ;
F_31 ( V_4 ) ;
return 0 ;
}
static int
F_32 ( struct V_3 * V_4 )
{
F_33 ( V_4 ) ;
F_34 ( V_4 -> V_87 ) ;
F_4 ( V_71 | V_72 , V_14 ) ;
F_7 ( V_4 ) -> V_8 . V_12 = 0 ;
while ( F_8 ( V_15 ) & ( V_73 | V_74 ) )
F_25 () ;
F_1 ( 0x80 , V_25 + 4 ) ;
F_4 ( 0 , V_14 ) ;
F_35 ( V_4 -> V_87 , V_4 ) ;
return 0 ;
}
static void F_36 ( struct V_3 * V_4 )
{
F_7 ( V_4 ) -> V_8 . V_9 &= ~ V_61 ;
if ( V_4 -> V_59 & V_60 ) {
F_7 ( V_4 ) -> V_8 . V_9 |= V_61 ;
} else if ( V_4 -> V_59 & V_90 || ! F_37 ( V_4 ) ) {
F_7 ( V_4 ) -> V_8 . V_9 |= V_63 ;
} else
F_7 ( V_4 ) -> V_8 . V_9 |= V_64 ;
F_4 ( F_7 ( V_4 ) -> V_8 . V_9 | V_10 , V_11 ) ;
}
static void F_38 ( struct V_3 * V_4 )
{
unsigned long V_59 ;
F_12 ( & F_7 ( V_4 ) -> V_26 ) ;
F_39 ( V_59 ) ;
F_9 ( V_39 L_11 , V_4 -> V_17 ) ;
F_9 ( V_39 L_12 , V_4 -> V_17 ,
F_8 ( V_15 ) , F_8 ( V_11 ) , F_8 ( V_25 ) ) ;
F_9 ( V_39 L_13 , V_4 -> V_17 ,
F_8 ( V_67 ) , F_8 ( V_69 ) , F_8 ( V_68 ) ) ;
F_9 ( V_39 L_14 , V_4 -> V_17 ,
F_7 ( V_4 ) -> V_75 , F_7 ( V_4 ) -> V_76 ) ;
F_6 ( V_4 , V_19 , F_7 ( V_4 ) -> V_76 ) ;
F_9 ( V_39 L_15 , V_4 -> V_17 , F_40 ( V_4 ) ) ;
F_41 ( V_59 ) ;
F_7 ( V_4 ) -> V_8 . V_23 |= V_24 ;
V_4 -> V_91 . V_92 += 1 ;
F_4 ( F_7 ( V_4 ) -> V_8 . V_23 , V_25 ) ;
F_7 ( V_4 ) -> V_75 = F_7 ( V_4 ) -> V_76 = 0 ;
F_42 ( V_4 ) ;
}
static int
F_43 ( struct V_93 * V_94 , struct V_3 * V_4 )
{
unsigned long V_59 ;
unsigned int V_95 = V_96 < V_94 -> V_97 ? V_94 -> V_97 : V_96 ;
unsigned int V_98 , V_99 ;
if ( F_7 ( V_4 ) -> V_18 ) {
F_44 ( V_94 ) ;
V_4 -> V_91 . V_100 ++ ;
F_31 ( V_4 ) ;
return V_101 ;
}
V_95 = ( V_95 + 1 ) & ~ 1 ;
if ( V_95 != V_94 -> V_97 ) {
if ( F_45 ( V_94 , V_95 ) )
goto V_102;
}
V_99 = ( F_7 ( V_4 ) -> V_75 + 1 ) & 15 ;
F_39 ( V_59 ) ;
if ( F_7 ( V_4 ) -> V_76 == V_99 ) {
F_41 ( V_59 ) ;
return V_103 ;
}
V_98 = 0x600 * F_7 ( V_4 ) -> V_75 ;
F_7 ( V_4 ) -> V_75 = V_99 ;
V_99 *= 0x600 ;
#define F_46 (TXHDR_TRANSMIT|TXHDR_CHAINCONTINUE|TXHDR_DATAFOLLOWS|TXHDR_ENSUCCESS)
F_6 ( V_4 , V_48 , V_99 ) ;
F_23 ( V_4 , 0 ) ;
F_6 ( V_4 , V_48 , V_98 ) ;
F_23 ( V_4 , 0 ) ;
F_19 ( V_4 , V_94 -> V_22 , V_95 ) ;
F_47 ( V_4 , F_48 ( V_99 ) ) ;
F_47 ( V_4 , V_104 >> 16 ) ;
F_6 ( V_4 , V_48 , V_98 ) ;
F_47 ( V_4 , F_48 ( ( V_98 + V_95 + 4 ) ) ) ;
F_47 ( V_4 , F_46 >> 16 ) ;
F_11 ( V_4 ) ;
if ( ! ( F_8 ( V_15 ) & V_74 ) ) {
F_4 ( V_98 , V_68 ) ;
F_4 ( F_7 ( V_4 ) -> V_8 . V_12 | V_105 , V_14 ) ;
}
V_99 = ( F_7 ( V_4 ) -> V_75 + 1 ) & 15 ;
F_41 ( V_59 ) ;
F_44 ( V_94 ) ;
if ( F_7 ( V_4 ) -> V_76 == V_99 )
F_33 ( V_4 ) ;
V_102:
return V_101 ;
}
static T_3
V_88 ( int V_87 , void * V_106 )
{
struct V_3 * V_4 = (struct V_3 * ) V_106 ;
unsigned int V_107 , V_108 = V_109 ;
#if V_110 > 1
if( V_111 & V_112 )
F_9 ( L_16 , V_87 ) ;
#endif
V_107 = F_8 ( V_15 ) ;
if ( V_107 & V_113 ) {
F_4 ( V_114 | F_7 ( V_4 ) -> V_8 . V_12 , V_14 ) ;
F_49 ( V_4 , 12 ) ;
V_108 = V_115 ;
}
if ( V_107 & V_116 ) {
F_4 ( V_117 | F_7 ( V_4 ) -> V_8 . V_12 , V_14 ) ;
F_50 ( V_4 ) ;
V_108 = V_115 ;
}
#if V_110 > 1
if( V_111 & V_112 )
F_9 ( L_17 ) ;
#endif
return V_108 ;
}
static int F_49 ( struct V_3 * V_4 , unsigned int V_118 )
{
unsigned int V_99 = F_7 ( V_4 ) -> V_66 , V_119 = 0 ;
F_11 ( V_4 ) ;
do {
unsigned int V_120 , V_107 ;
unsigned char V_121 [ 16 ] ;
{
unsigned int V_122 ;
F_6 ( V_4 , V_19 , V_99 ) ;
V_122 = F_51 ( V_4 ) ;
V_107 = F_51 ( V_4 ) ;
if ( ( V_107 & ( V_123 | V_124 | V_125 ) ) !=
( V_123 | V_124 ) || ! V_122 )
break;
V_120 = V_99 + 4 ;
V_99 = F_52 ( V_122 ) ;
}
F_6 ( V_4 , V_19 , V_120 ) ;
F_20 ( V_4 , V_121 + 2 , 12 ) ;
if ( V_99 < V_50 || V_99 >= V_43 ) {
int V_38 ;
F_9 ( L_18 , V_4 -> V_17 , F_7 ( V_4 ) -> V_66 ) ;
F_9 ( L_19 , V_99 >> 8 , V_99 & 255 , V_107 & 255 , V_107 >> 8 ) ;
for ( V_38 = 2 ; V_38 < 14 ; V_38 ++ )
F_9 ( L_20 , V_121 [ V_38 ] ) ;
F_9 ( L_5 ) ;
V_99 = F_7 ( V_4 ) -> V_66 ;
break;
}
if ( ! ( * ( unsigned long * ) & V_4 -> V_57 [ 0 ] ^ * ( unsigned long * ) & V_121 [ 2 + 6 ] ) &&
! ( * ( unsigned short * ) & V_4 -> V_57 [ 4 ] ^ * ( unsigned short * ) & V_121 [ 2 + 10 ] ) ) {
V_118 ++ ;
F_4 ( V_99 >> 8 , V_69 ) ;
} else
if ( ! ( V_107 & ( V_126 | V_127 | V_128 | V_129 ) ) ) {
unsigned int V_95 = V_99 - V_120 ;
struct V_93 * V_94 ;
if ( V_99 <= V_120 )
V_95 += V_43 - V_50 ;
V_94 = F_53 ( V_4 , V_95 + 2 ) ;
if ( V_94 ) {
unsigned char * V_130 ;
F_54 ( V_94 , 2 ) ;
V_130 = F_55 ( V_94 , V_95 ) ;
F_20 ( V_4 , V_130 + 12 , V_95 - 12 ) ;
F_4 ( V_99 >> 8 , V_69 ) ;
* ( unsigned short * ) ( V_130 + 0 ) = * ( unsigned short * ) ( V_121 + 2 ) ;
* ( unsigned long * ) ( V_130 + 2 ) = * ( unsigned long * ) ( V_121 + 4 ) ;
* ( unsigned long * ) ( V_130 + 6 ) = * ( unsigned long * ) ( V_121 + 8 ) ;
* ( unsigned short * ) ( V_130 + 10 ) = * ( unsigned short * ) ( V_121 + 12 ) ;
V_94 -> V_131 = F_56 ( V_94 , V_4 ) ;
F_57 ( V_94 ) ;
V_119 ++ ;
} else
goto V_132;
} else {
struct V_133 * V_91 = & V_4 -> V_91 ;
F_4 ( V_99 >> 8 , V_69 ) ;
if ( V_107 & V_126 ) V_91 -> V_134 ++ ;
if ( V_107 & V_127 ) V_91 -> V_135 ++ ;
if ( V_107 & V_128 ) V_91 -> V_136 ++ ;
if ( V_107 & V_129 ) V_91 -> V_137 ++ ;
V_91 -> V_138 ++ ;
}
}
while ( -- V_118 );
V_139:
V_4 -> V_91 . V_140 += V_119 ;
F_7 ( V_4 ) -> V_66 = V_99 ;
if ( ! ( F_8 ( V_15 ) & V_73 ) ) {
V_4 -> V_91 . V_141 ++ ;
F_4 ( V_99 , V_67 ) ;
F_4 ( F_7 ( V_4 ) -> V_8 . V_12 | V_79 , V_14 ) ;
}
return V_118 ;
V_132: {
static unsigned long V_142 ;
F_4 ( V_99 >> 8 , V_69 ) ;
if ( F_58 ( V_28 , V_142 + 10 * V_29 ) ) {
V_142 = V_28 ;
F_9 ( L_21 , V_4 -> V_17 ) ;
}
V_4 -> V_91 . V_141 ++ ;
goto V_139;
}
}
static void F_50 ( struct V_3 * V_4 )
{
unsigned int V_76 = F_7 ( V_4 ) -> V_76 ;
int V_143 = 14 ;
do {
unsigned long V_107 ;
F_6 ( V_4 , V_19 , V_76 * 0x600 ) ;
V_107 = F_40 ( V_4 ) ;
if ( ( V_107 & ( V_144 | V_145 ) ) !=
( V_144 | V_145 ) )
break;
if ( ! ( V_107 & ( V_146 | V_147 ) ) )
V_4 -> V_91 . V_148 ++ ;
else {
V_4 -> V_91 . V_92 ++ ;
if ( V_107 & V_147 )
V_4 -> V_91 . V_149 += 16 ;
if ( V_107 & V_146 )
V_4 -> V_91 . V_150 ++ ;
}
V_76 = ( V_76 + 1 ) & 15 ;
} while ( -- V_143 );
if ( F_7 ( V_4 ) -> V_76 != V_76 ) {
F_7 ( V_4 ) -> V_76 = V_76 ;
F_42 ( V_4 ) ;
}
}
static void F_59 ( void )
{
static unsigned V_151 = 0 ;
if ( V_111 && V_151 ++ == 0 )
F_9 ( V_152 L_22 , V_153 ) ;
}
static int
F_60 ( struct V_32 * V_33 , const struct V_154 * V_155 )
{
const struct V_156 * V_22 = V_155 -> V_22 ;
struct V_3 * V_4 ;
int V_157 , V_45 ;
F_59 () ;
V_45 = F_61 ( V_33 ) ;
if ( V_45 )
goto V_102;
V_4 = F_62 ( sizeof( struct V_158 ) ) ;
if ( ! V_4 ) {
V_45 = - V_159 ;
goto V_160;
}
F_63 ( V_4 , & V_33 -> V_4 ) ;
F_7 ( V_4 ) -> V_161 = F_64 ( V_33 , V_162 , 0 , 0 ) ;
if ( ! F_7 ( V_4 ) -> V_161 ) {
V_45 = - V_159 ;
goto free;
}
V_33 -> V_163 = F_7 ( V_4 ) -> V_161 + V_22 -> V_164 ;
V_33 -> V_165 = 0xf0 ;
F_7 ( V_4 ) -> V_166 = F_7 ( V_4 ) -> V_161 + V_22 -> V_164 ;
V_4 -> V_87 = V_33 -> V_87 ;
F_14 ( V_4 -> V_57 , V_33 ) ;
F_65 ( & F_7 ( V_4 ) -> V_26 ) ;
F_1 ( 0x80 , V_25 + 4 ) ;
V_157 = V_167 ;
F_3 ( 4 ) ;
if ( F_26 ( V_4 , 0x100 ) &&
F_26 ( V_4 , 0x201 ) )
V_157 = V_168 ;
if ( V_157 == V_167 &&
F_28 ( V_4 , 0x101 ) &&
F_28 ( V_4 , 0x201 ) )
V_157 = V_169 ;
switch ( V_157 ) {
case V_167 :
F_9 ( V_39 L_23 , V_4 -> V_17 ) ;
V_45 = - V_40 ;
goto free;
case V_168 :
F_9 ( V_39 L_24
L_25 , V_4 -> V_17 , V_22 -> V_17 ) ;
V_45 = - V_40 ;
goto free;
default:
break;
}
if ( F_22 ( V_4 ) ) {
V_45 = - V_40 ;
goto free;
}
V_4 -> V_170 = & V_171 ;
V_4 -> V_172 = 5 * V_29 / 100 ;
V_45 = F_66 ( V_4 ) ;
if ( V_45 )
goto free;
F_9 ( L_26 ,
V_4 -> V_17 , V_22 -> V_17 , V_33 -> V_173 , V_4 -> V_57 ) ;
F_67 ( V_33 , V_4 ) ;
return 0 ;
free:
F_68 ( V_4 ) ;
V_160:
F_69 ( V_33 ) ;
V_102:
return V_45 ;
}
static void F_70 ( struct V_32 * V_33 )
{
struct V_3 * V_4 = F_71 ( V_33 ) ;
F_67 ( V_33 , NULL ) ;
F_72 ( V_4 ) ;
F_68 ( V_4 ) ;
F_69 ( V_33 ) ;
}
static int T_4 F_73 ( void )
{
return F_74 ( & V_174 ) ;
}
static void T_5 F_75 ( void )
{
F_76 ( & V_174 ) ;
}
