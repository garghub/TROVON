static inline int F_1 ( void * V_1 , int V_2 )
{
register unsigned long T_1 V_3 ( L_1 ) = ( unsigned long ) V_1 ;
typedef union {
struct V_4 V_5 ;
struct V_6 V_7 ;
} T_2;
int V_8 ;
V_8 = 3 ;
asm volatile(
" diag 2,%2,0x250\n"
"0: ipm %0\n"
" srl %0,28\n"
" or %0,3\n"
"1:\n"
EX_TABLE(0b,1b)
: "+d" (rc), "=m" (*(addr_type *) iob)
: "d" (cmd), "d" (reg2), "m" (*(addr_type *) iob)
: "3", "cc");
return V_8 ;
}
static inline int
F_2 ( struct V_9 * V_10 , unsigned int V_11 ,
T_3 V_12 , T_3 * V_13 )
{
struct V_14 * V_15 ;
struct V_4 * V_16 ;
int V_8 ;
V_15 = (struct V_14 * ) V_10 -> V_15 ;
V_16 = & V_15 -> V_16 ;
memset ( V_16 , 0 , sizeof ( struct V_4 ) ) ;
V_16 -> V_17 = V_15 -> V_18 . V_19 ;
V_16 -> V_20 = V_11 ;
V_16 -> V_12 = V_12 ;
V_16 -> V_21 = V_22 ;
V_8 = F_1 ( V_16 , V_23 ) ;
if ( ( V_8 & 3 ) == 0 && V_13 )
* V_13 = V_16 -> V_13 ;
return V_8 ;
}
static inline int
F_3 ( struct V_9 * V_10 )
{
struct V_14 * V_15 ;
struct V_4 * V_16 ;
int V_8 ;
V_15 = (struct V_14 * ) V_10 -> V_15 ;
V_16 = & V_15 -> V_16 ;
memset ( V_16 , 0 , sizeof ( struct V_4 ) ) ;
V_16 -> V_17 = V_15 -> V_18 . V_19 ;
V_8 = F_1 ( V_16 , V_24 ) ;
return V_8 ;
}
static void
F_4 ( struct V_9 * V_10 )
{
int V_8 ;
F_3 ( V_10 ) ;
V_8 = F_2 ( V_10 , V_10 -> V_25 -> V_26 , 0 , NULL ) ;
if ( V_8 == 4 ) {
if ( ! ( F_5 ( V_27 , & V_10 -> V_28 ) ) )
F_6 ( L_2
L_3 ,
F_7 ( & V_10 -> V_29 -> V_30 ) ) ;
V_8 = 0 ;
}
if ( V_8 )
F_6 ( L_4
L_5 , F_7 ( & V_10 -> V_29 -> V_30 ) , V_8 ) ;
}
static int
F_8 ( struct V_31 * V_32 )
{
struct V_9 * V_10 ;
struct V_14 * V_15 ;
struct V_33 * V_34 ;
int V_8 ;
V_10 = V_32 -> V_35 ;
if ( V_32 -> V_36 < 0 ) {
F_9 ( V_37 , V_10 , L_6
L_7 , V_32 ) ;
V_32 -> V_38 = V_39 ;
return - V_40 ;
}
V_15 = (struct V_14 * ) V_10 -> V_15 ;
V_34 = (struct V_33 * ) V_32 -> V_41 ;
V_15 -> V_1 . V_17 = V_15 -> V_18 . V_19 ;
V_15 -> V_1 . V_42 = 0 ;
V_15 -> V_1 . V_28 = V_43 ;
V_15 -> V_1 . V_44 = V_34 -> V_44 ;
V_15 -> V_1 . V_45 = ( V_46 ) V_32 ;
V_15 -> V_1 . V_47 = V_34 -> V_48 ;
V_15 -> V_1 . V_21 = V_22 ;
V_32 -> V_49 = F_10 () ;
V_32 -> V_50 = V_51 ;
V_32 -> V_36 -- ;
V_8 = F_1 ( & V_15 -> V_1 , V_52 ) ;
switch ( V_8 ) {
case 0 :
V_32 -> V_53 = F_10 () ;
V_32 -> V_38 = V_54 ;
V_8 = - V_55 ;
break;
case 8 :
V_32 -> V_38 = V_56 ;
V_8 = 0 ;
break;
default:
V_32 -> V_38 = V_57 ;
F_9 ( V_58 , V_10 , L_8 , V_8 ) ;
F_4 ( V_10 ) ;
V_8 = - V_40 ;
break;
}
V_32 -> V_59 = V_8 ;
return V_8 ;
}
static int
F_11 ( struct V_31 * V_32 )
{
struct V_9 * V_10 ;
V_10 = V_32 -> V_35 ;
F_3 ( V_10 ) ;
F_2 ( V_10 , V_10 -> V_25 -> V_26 , 0 , NULL ) ;
V_32 -> V_38 = V_60 ;
V_32 -> V_53 = F_10 () ;
F_12 ( V_10 ) ;
return 0 ;
}
static void F_13 ( struct V_61 V_61 ,
unsigned int V_62 , unsigned long V_63 )
{
struct V_31 * V_32 , * V_64 ;
struct V_9 * V_10 ;
unsigned long long V_65 ;
unsigned long V_28 ;
V_46 V_66 ;
int V_8 ;
switch ( V_61 . V_67 >> 8 ) {
case V_68 :
V_66 = ( V_46 ) V_62 ;
break;
case V_69 :
V_66 = ( V_46 ) V_63 ;
break;
default:
return;
}
F_14 ( F_15 () ) . V_70 [ V_71 ] ++ ;
if ( ! V_66 ) {
F_16 ( V_72 , L_9 , L_10
L_11 ) ;
return;
}
V_32 = (struct V_31 * ) V_66 ;
V_10 = (struct V_9 * ) V_32 -> V_35 ;
if ( strncmp ( V_10 -> V_73 -> V_74 , ( char * ) & V_32 -> V_75 , 4 ) ) {
F_9 ( V_58 , V_10 ,
L_12
L_13 ,
V_32 -> V_75 , * ( int * ) ( & V_10 -> V_73 -> V_76 ) ) ;
return;
}
F_17 ( F_18 ( V_10 -> V_29 ) , V_28 ) ;
if ( V_32 -> V_38 == V_60 ) {
V_32 -> V_38 = V_77 ;
F_19 ( V_10 ) ;
F_12 ( V_10 ) ;
F_20 ( F_18 ( V_10 -> V_29 ) , V_28 ) ;
return;
}
V_32 -> V_53 = F_10 () ;
V_65 = 0 ;
if ( ( V_61 . V_67 & 0xff ) == 0 ) {
V_32 -> V_38 = V_54 ;
if ( ! F_21 ( & V_10 -> V_78 ) ) {
V_64 = F_22 ( V_10 -> V_78 . V_64 ,
struct V_31 , V_79 ) ;
if ( V_64 -> V_38 == V_57 ) {
V_8 = F_8 ( V_64 ) ;
if ( V_8 == 0 )
V_65 = V_64 -> V_65 ;
}
}
} else {
V_32 -> V_38 = V_57 ;
F_9 ( V_80 , V_10 , L_14
L_15 , V_32 ,
V_61 . V_67 & 0xff , V_32 -> V_36 ) ;
F_4 ( V_10 ) ;
}
if ( V_65 != 0 )
F_23 ( V_10 , V_65 ) ;
else
F_19 ( V_10 ) ;
F_12 ( V_10 ) ;
F_20 ( F_18 ( V_10 -> V_29 ) , V_28 ) ;
}
static int
F_24 ( struct V_9 * V_10 )
{
struct V_81 * V_25 ;
struct V_14 * V_15 ;
struct V_82 * V_83 ;
struct V_84 V_48 ;
struct V_85 * V_86 ;
T_3 V_13 ;
unsigned int V_87 , V_88 ;
int V_8 ;
V_15 = (struct V_14 * ) V_10 -> V_15 ;
if ( V_15 == NULL ) {
V_15 = F_25 ( sizeof( struct V_14 ) , V_89 ) ;
if ( V_15 == NULL ) {
F_9 ( V_58 , V_10 , L_9 ,
L_16
L_17 ) ;
return - V_90 ;
}
F_26 ( V_10 -> V_29 , & V_15 -> V_18 ) ;
V_10 -> V_15 = ( void * ) V_15 ;
}
V_25 = F_27 () ;
if ( F_28 ( V_25 ) ) {
F_9 ( V_58 , V_10 , L_9 ,
L_18 ) ;
V_10 -> V_15 = NULL ;
F_29 ( V_15 ) ;
return F_30 ( V_25 ) ;
}
V_10 -> V_25 = V_25 ;
V_25 -> V_91 = V_10 ;
V_83 = ( void * ) & ( V_15 -> V_83 ) ;
V_83 -> V_17 = V_15 -> V_18 . V_19 ;
V_83 -> V_92 = sizeof ( struct V_82 ) ;
V_8 = F_31 ( (struct F_31 * ) V_83 ) ;
if ( V_8 ) {
F_9 ( V_58 , V_10 , L_19
L_20 , V_8 ) ;
V_8 = - V_93 ;
goto V_94;
}
V_10 -> V_95 = V_96 ;
switch ( V_15 -> V_83 . V_97 ) {
case V_98 :
V_15 -> V_99 = 1 ;
break;
case V_100 :
V_15 -> V_99 = 2 ;
break;
default:
F_6 ( L_21
L_22 , F_7 ( & V_10 -> V_29 -> V_30 ) ,
V_15 -> V_83 . V_97 ) ;
V_8 = - V_93 ;
goto V_94;
}
F_9 ( V_101 , V_10 ,
L_23 ,
V_83 -> V_17 ,
V_83 -> V_102 ,
V_83 -> V_103 , V_83 -> V_104 ) ;
F_3 ( V_10 ) ;
V_86 = (struct V_85 * ) F_32 ( V_89 ) ;
if ( V_86 == NULL ) {
F_9 ( V_58 , V_10 , L_9 ,
L_24 ) ;
V_8 = - V_90 ;
goto V_94;
}
V_8 = 0 ;
V_13 = 0 ;
for ( V_88 = 512 ; V_88 <= V_105 ; V_88 <<= 1 ) {
F_2 ( V_10 , V_88 , 0 , & V_13 ) ;
memset ( & V_48 , 0 , sizeof ( struct V_84 ) ) ;
V_48 . type = V_106 ;
V_48 . V_107 = V_15 -> V_99 + 1 ;
V_48 . V_108 = V_86 ;
memset ( & V_15 -> V_1 , 0 , sizeof ( struct V_6 ) ) ;
V_15 -> V_1 . V_17 = V_83 -> V_17 ;
V_15 -> V_1 . V_42 = 0 ;
V_15 -> V_1 . V_28 = 0 ;
V_15 -> V_1 . V_44 = 1 ;
V_15 -> V_1 . V_45 = 0 ;
V_15 -> V_1 . V_47 = & V_48 ;
V_15 -> V_1 . V_21 = V_22 ;
V_8 = F_1 ( & V_15 -> V_1 , V_52 ) ;
if ( V_8 == 3 ) {
F_6 ( L_25 ,
F_7 ( & V_10 -> V_29 -> V_30 ) ) ;
V_8 = - V_93 ;
goto V_109;
}
F_3 ( V_10 ) ;
if ( V_8 == 0 )
break;
}
if ( V_88 > V_105 ) {
F_6 ( L_26
L_27 ,
F_7 ( & V_10 -> V_29 -> V_30 ) , V_8 ) ;
V_8 = - V_40 ;
goto V_109;
}
if ( memcmp ( V_86 -> V_110 , V_111 ,
sizeof( V_111 ) ) == 0 ) {
V_88 = ( unsigned int ) V_86 -> V_20 ;
V_25 -> V_112 = ( unsigned long ) V_86 -> V_44 ;
} else
V_25 -> V_112 = V_13 ;
V_25 -> V_26 = V_88 ;
V_25 -> V_113 = 0 ;
for ( V_87 = 512 ; V_87 < V_88 ; V_87 = V_87 << 1 )
V_25 -> V_113 ++ ;
V_8 = F_2 ( V_10 , V_25 -> V_26 , 0 , NULL ) ;
if ( V_8 && ( V_8 != 4 ) ) {
F_6 ( L_28 ,
F_7 ( & V_10 -> V_29 -> V_30 ) , V_8 ) ;
V_8 = - V_40 ;
} else {
if ( V_8 == 4 )
F_33 ( V_27 , & V_10 -> V_28 ) ;
F_34 ( L_29
L_30 , F_7 ( & V_10 -> V_29 -> V_30 ) ,
( unsigned long ) V_25 -> V_26 ,
( unsigned long ) ( V_25 -> V_112 <<
V_25 -> V_113 ) >> 1 ,
( V_8 == 4 ) ? L_31 : L_32 ) ;
V_8 = 0 ;
}
V_109:
F_35 ( ( long ) V_86 ) ;
V_94:
if ( V_8 ) {
V_10 -> V_25 = NULL ;
F_36 ( V_25 ) ;
V_10 -> V_15 = NULL ;
F_29 ( V_15 ) ;
}
return V_8 ;
}
static int
F_37 ( struct V_81 * V_25 , struct V_114 * V_115 )
{
if ( F_38 ( V_25 -> V_26 ) != 0 )
return - V_116 ;
V_115 -> V_117 = ( V_25 -> V_112 << V_25 -> V_113 ) >> 10 ;
V_115 -> V_118 = 16 ;
V_115 -> V_119 = 128 >> V_25 -> V_113 ;
return 0 ;
}
static T_4
F_39 ( struct V_31 * V_32 )
{
return V_120 ;
}
static T_4
F_40 ( struct V_31 * V_32 )
{
return V_121 ;
}
static struct V_31 * F_41 ( struct V_9 * V_122 ,
struct V_81 * V_25 ,
struct V_123 * V_124 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 ;
struct V_84 * V_125 ;
struct V_126 V_127 ;
struct V_128 * V_129 ;
char * V_130 ;
unsigned int V_131 , V_132 ;
T_5 V_133 , V_134 , V_135 ;
unsigned int V_136 , V_137 ;
unsigned char V_138 ;
if ( F_42 ( V_124 ) == V_139 )
V_138 = V_106 ;
else if ( F_42 ( V_124 ) == V_140 )
V_138 = V_141 ;
else
return F_43 ( - V_116 ) ;
V_136 = V_25 -> V_26 ;
V_134 = F_44 ( V_124 ) >> V_25 -> V_113 ;
V_135 =
( F_44 ( V_124 ) + F_45 ( V_124 ) - 1 ) >> V_25 -> V_113 ;
V_131 = 0 ;
F_46 (bv, req, iter) {
if ( V_129 -> V_142 & ( V_136 - 1 ) )
return F_43 ( - V_116 ) ;
V_131 += V_129 -> V_142 >> ( V_25 -> V_113 + 9 ) ;
}
if ( V_131 != V_135 - V_134 + 1 )
return F_43 ( - V_116 ) ;
V_132 = sizeof( struct V_33 ) +
V_131 * sizeof( struct V_84 ) ;
V_32 = F_47 ( V_143 , 0 , V_132 , V_122 ) ;
if ( F_28 ( V_32 ) )
return V_32 ;
V_34 = (struct V_33 * ) V_32 -> V_41 ;
V_34 -> V_44 = V_131 ;
V_125 = V_34 -> V_48 ;
V_133 = V_134 ;
F_46 (bv, req, iter) {
V_130 = F_48 ( V_129 -> V_144 ) + V_129 -> V_145 ;
for ( V_137 = 0 ; V_137 < V_129 -> V_142 ; V_137 += V_136 ) {
memset ( V_125 , 0 , sizeof ( struct V_84 ) ) ;
V_125 -> type = V_138 ;
V_125 -> V_107 = V_133 + 1 ;
V_125 -> V_108 = V_130 ;
V_125 ++ ;
V_130 += V_136 ;
V_133 ++ ;
}
}
V_32 -> V_36 = V_146 ;
V_32 -> V_147 = F_10 () ;
if ( F_49 ( V_124 ) ||
V_25 -> V_91 -> V_148 & V_149 )
F_33 ( V_150 , & V_32 -> V_28 ) ;
V_32 -> V_35 = V_122 ;
V_32 -> V_122 = V_122 ;
V_32 -> V_25 = V_25 ;
V_32 -> V_65 = V_122 -> V_95 * V_151 ;
V_32 -> V_38 = V_152 ;
return V_32 ;
}
static int
F_50 ( struct V_31 * V_32 , struct V_123 * V_124 )
{
int V_38 ;
V_38 = V_32 -> V_38 == V_153 ;
F_51 ( V_32 , V_32 -> V_122 ) ;
return V_38 ;
}
static void F_52 ( struct V_31 * V_32 )
{
V_32 -> V_38 = V_152 ;
}
static int
F_53 ( struct V_9 * V_10 ,
struct V_154 * V_155 )
{
struct V_14 * V_15 ;
V_15 = (struct V_14 * ) V_10 -> V_15 ;
V_155 -> V_156 = ( unsigned int ) V_15 -> V_99 ;
V_155 -> V_157 = 1 ;
V_155 -> V_158 = V_159 ;
V_155 -> V_160 = sizeof ( struct V_82 ) ;
memcpy ( V_155 -> V_161 ,
& ( (struct V_14 * ) V_10 -> V_15 ) -> V_83 ,
sizeof ( struct V_82 ) ) ;
V_155 -> V_162 = 0 ;
return 0 ;
}
static void
F_54 ( struct V_9 * V_10 , struct V_31 * V_124 ,
struct V_163 * V_164 )
{
F_9 ( V_58 , V_10 , L_9 ,
L_33 ) ;
}
static int T_6
F_55 ( void )
{
if ( ! V_165 ) {
F_34 ( L_34 ,
V_166 . V_76 ) ;
return - V_167 ;
}
F_56 ( V_166 . V_74 , 4 ) ;
F_57 () ;
F_58 ( 0x2603 , F_13 ) ;
V_168 = & V_166 ;
return 0 ;
}
static void T_7
F_59 ( void )
{
F_60 ( 0x2603 , F_13 ) ;
F_61 () ;
V_168 = NULL ;
}
