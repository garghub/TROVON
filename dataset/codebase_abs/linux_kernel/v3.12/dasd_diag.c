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
F_14 ( V_70 ) ;
if ( ! V_66 ) {
F_15 ( V_71 , L_9 , L_10
L_11 ) ;
return;
}
V_32 = (struct V_31 * ) V_66 ;
V_10 = (struct V_9 * ) V_32 -> V_35 ;
if ( strncmp ( V_10 -> V_72 -> V_73 , ( char * ) & V_32 -> V_74 , 4 ) ) {
F_9 ( V_58 , V_10 ,
L_12
L_13 ,
V_32 -> V_74 , * ( int * ) ( & V_10 -> V_72 -> V_75 ) ) ;
return;
}
F_16 ( F_17 ( V_10 -> V_29 ) , V_28 ) ;
if ( V_32 -> V_38 == V_60 ) {
V_32 -> V_38 = V_76 ;
F_18 ( V_10 ) ;
F_12 ( V_10 ) ;
F_19 ( F_17 ( V_10 -> V_29 ) , V_28 ) ;
return;
}
V_32 -> V_53 = F_10 () ;
V_65 = 0 ;
if ( ( V_61 . V_67 & 0xff ) == 0 ) {
V_32 -> V_38 = V_54 ;
if ( ! F_20 ( & V_10 -> V_77 ) ) {
V_64 = F_21 ( V_10 -> V_77 . V_64 ,
struct V_31 , V_78 ) ;
if ( V_64 -> V_38 == V_57 ) {
V_8 = F_8 ( V_64 ) ;
if ( V_8 == 0 )
V_65 = V_64 -> V_65 ;
}
}
} else {
V_32 -> V_38 = V_57 ;
F_9 ( V_79 , V_10 , L_14
L_15 , V_32 ,
V_61 . V_67 & 0xff , V_32 -> V_36 ) ;
F_4 ( V_10 ) ;
}
if ( V_65 != 0 )
F_22 ( V_10 , V_65 ) ;
else
F_18 ( V_10 ) ;
F_12 ( V_10 ) ;
F_19 ( F_17 ( V_10 -> V_29 ) , V_28 ) ;
}
static int
F_23 ( struct V_9 * V_10 )
{
struct V_80 * V_25 ;
struct V_14 * V_15 ;
struct V_81 * V_82 ;
struct V_83 V_48 ;
struct V_84 * V_85 ;
T_3 V_13 ;
unsigned int V_86 , V_87 ;
int V_8 ;
V_15 = (struct V_14 * ) V_10 -> V_15 ;
if ( V_15 == NULL ) {
V_15 = F_24 ( sizeof( struct V_14 ) , V_88 ) ;
if ( V_15 == NULL ) {
F_9 ( V_58 , V_10 , L_9 ,
L_16
L_17 ) ;
return - V_89 ;
}
F_25 ( V_10 -> V_29 , & V_15 -> V_18 ) ;
V_10 -> V_15 = ( void * ) V_15 ;
}
V_25 = F_26 () ;
if ( F_27 ( V_25 ) ) {
F_9 ( V_58 , V_10 , L_9 ,
L_18 ) ;
V_10 -> V_15 = NULL ;
F_28 ( V_15 ) ;
return F_29 ( V_25 ) ;
}
V_10 -> V_25 = V_25 ;
V_25 -> V_90 = V_10 ;
V_82 = ( void * ) & ( V_15 -> V_82 ) ;
V_82 -> V_17 = V_15 -> V_18 . V_19 ;
V_82 -> V_91 = sizeof ( struct V_81 ) ;
V_8 = F_30 ( (struct F_30 * ) V_82 ) ;
if ( V_8 ) {
F_9 ( V_58 , V_10 , L_19
L_20 , V_8 ) ;
V_8 = - V_92 ;
goto V_93;
}
V_10 -> V_94 = V_95 ;
V_10 -> V_96 = V_97 ;
switch ( V_15 -> V_82 . V_98 ) {
case V_99 :
V_15 -> V_100 = 1 ;
break;
case V_101 :
V_15 -> V_100 = 2 ;
break;
default:
F_6 ( L_21
L_22 , F_7 ( & V_10 -> V_29 -> V_30 ) ,
V_15 -> V_82 . V_98 ) ;
V_8 = - V_92 ;
goto V_93;
}
F_9 ( V_102 , V_10 ,
L_23 ,
V_82 -> V_17 ,
V_82 -> V_103 ,
V_82 -> V_104 , V_82 -> V_105 ) ;
F_3 ( V_10 ) ;
V_85 = (struct V_84 * ) F_31 ( V_88 ) ;
if ( V_85 == NULL ) {
F_9 ( V_58 , V_10 , L_9 ,
L_24 ) ;
V_8 = - V_89 ;
goto V_93;
}
V_8 = 0 ;
V_13 = 0 ;
for ( V_87 = 512 ; V_87 <= V_106 ; V_87 <<= 1 ) {
F_2 ( V_10 , V_87 , 0 , & V_13 ) ;
memset ( & V_48 , 0 , sizeof ( struct V_83 ) ) ;
V_48 . type = V_107 ;
V_48 . V_108 = V_15 -> V_100 + 1 ;
V_48 . V_109 = V_85 ;
memset ( & V_15 -> V_1 , 0 , sizeof ( struct V_6 ) ) ;
V_15 -> V_1 . V_17 = V_82 -> V_17 ;
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
V_8 = - V_92 ;
goto V_110;
}
F_3 ( V_10 ) ;
if ( V_8 == 0 )
break;
}
if ( V_87 > V_106 ) {
F_6 ( L_26
L_27 ,
F_7 ( & V_10 -> V_29 -> V_30 ) , V_8 ) ;
V_8 = - V_40 ;
goto V_110;
}
if ( memcmp ( V_85 -> V_111 , V_112 ,
sizeof( V_112 ) ) == 0 ) {
V_87 = ( unsigned int ) V_85 -> V_20 ;
V_25 -> V_113 = ( unsigned long ) V_85 -> V_44 ;
} else
V_25 -> V_113 = V_13 ;
V_25 -> V_26 = V_87 ;
V_25 -> V_114 = 0 ;
for ( V_86 = 512 ; V_86 < V_87 ; V_86 = V_86 << 1 )
V_25 -> V_114 ++ ;
V_8 = F_2 ( V_10 , V_25 -> V_26 , 0 , NULL ) ;
if ( V_8 && ( V_8 != 4 ) ) {
F_6 ( L_28 ,
F_7 ( & V_10 -> V_29 -> V_30 ) , V_8 ) ;
V_8 = - V_40 ;
} else {
if ( V_8 == 4 )
F_32 ( V_27 , & V_10 -> V_28 ) ;
F_33 ( L_29
L_30 , F_7 ( & V_10 -> V_29 -> V_30 ) ,
( unsigned long ) V_25 -> V_26 ,
( unsigned long ) ( V_25 -> V_113 <<
V_25 -> V_114 ) >> 1 ,
( V_8 == 4 ) ? L_31 : L_32 ) ;
V_8 = 0 ;
}
V_110:
F_34 ( ( long ) V_85 ) ;
V_93:
if ( V_8 ) {
V_10 -> V_25 = NULL ;
F_35 ( V_25 ) ;
V_10 -> V_15 = NULL ;
F_28 ( V_15 ) ;
}
return V_8 ;
}
static int
F_36 ( struct V_80 * V_25 , struct V_115 * V_116 )
{
if ( F_37 ( V_25 -> V_26 ) != 0 )
return - V_117 ;
V_116 -> V_118 = ( V_25 -> V_113 << V_25 -> V_114 ) >> 10 ;
V_116 -> V_119 = 16 ;
V_116 -> V_120 = 128 >> V_25 -> V_114 ;
return 0 ;
}
static T_4
F_38 ( struct V_31 * V_32 )
{
return V_121 ;
}
static T_4
F_39 ( struct V_31 * V_32 )
{
return V_122 ;
}
static struct V_31 * F_40 ( struct V_9 * V_123 ,
struct V_80 * V_25 ,
struct V_124 * V_125 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 ;
struct V_83 * V_126 ;
struct V_127 V_128 ;
struct V_129 * V_130 ;
char * V_131 ;
unsigned int V_132 , V_133 ;
T_5 V_134 , V_135 , V_136 ;
unsigned int V_137 , V_138 ;
unsigned char V_139 ;
if ( F_41 ( V_125 ) == V_140 )
V_139 = V_107 ;
else if ( F_41 ( V_125 ) == V_141 )
V_139 = V_142 ;
else
return F_42 ( - V_117 ) ;
V_137 = V_25 -> V_26 ;
V_135 = F_43 ( V_125 ) >> V_25 -> V_114 ;
V_136 =
( F_43 ( V_125 ) + F_44 ( V_125 ) - 1 ) >> V_25 -> V_114 ;
V_132 = 0 ;
F_45 (bv, req, iter) {
if ( V_130 -> V_143 & ( V_137 - 1 ) )
return F_42 ( - V_117 ) ;
V_132 += V_130 -> V_143 >> ( V_25 -> V_114 + 9 ) ;
}
if ( V_132 != V_136 - V_135 + 1 )
return F_42 ( - V_117 ) ;
V_133 = sizeof( struct V_33 ) +
V_132 * sizeof( struct V_83 ) ;
V_32 = F_46 ( V_144 , 0 , V_133 , V_123 ) ;
if ( F_27 ( V_32 ) )
return V_32 ;
V_34 = (struct V_33 * ) V_32 -> V_41 ;
V_34 -> V_44 = V_132 ;
V_126 = V_34 -> V_48 ;
V_134 = V_135 ;
F_45 (bv, req, iter) {
V_131 = F_47 ( V_130 -> V_145 ) + V_130 -> V_146 ;
for ( V_138 = 0 ; V_138 < V_130 -> V_143 ; V_138 += V_137 ) {
memset ( V_126 , 0 , sizeof ( struct V_83 ) ) ;
V_126 -> type = V_139 ;
V_126 -> V_108 = V_134 + 1 ;
V_126 -> V_109 = V_131 ;
V_126 ++ ;
V_131 += V_137 ;
V_134 ++ ;
}
}
V_32 -> V_36 = V_123 -> V_96 ;
V_32 -> V_147 = F_10 () ;
if ( F_48 ( V_125 ) ||
V_25 -> V_90 -> V_148 & V_149 )
F_32 ( V_150 , & V_32 -> V_28 ) ;
V_32 -> V_35 = V_123 ;
V_32 -> V_123 = V_123 ;
V_32 -> V_25 = V_25 ;
V_32 -> V_65 = V_123 -> V_94 * V_151 ;
V_32 -> V_38 = V_152 ;
return V_32 ;
}
static int
F_49 ( struct V_31 * V_32 , struct V_124 * V_125 )
{
int V_38 ;
V_38 = V_32 -> V_38 == V_153 ;
F_50 ( V_32 , V_32 -> V_123 ) ;
return V_38 ;
}
static void F_51 ( struct V_31 * V_32 )
{
if ( V_32 -> V_36 < 0 )
V_32 -> V_38 = V_154 ;
else
V_32 -> V_38 = V_152 ;
}
static int
F_52 ( struct V_9 * V_10 ,
struct V_155 * V_156 )
{
struct V_14 * V_15 ;
V_15 = (struct V_14 * ) V_10 -> V_15 ;
V_156 -> V_157 = ( unsigned int ) V_15 -> V_100 ;
V_156 -> V_158 = 1 ;
V_156 -> V_159 = V_160 ;
V_156 -> V_161 = sizeof ( struct V_81 ) ;
memcpy ( V_156 -> V_162 ,
& ( (struct V_14 * ) V_10 -> V_15 ) -> V_82 ,
sizeof ( struct V_81 ) ) ;
V_156 -> V_163 = 0 ;
return 0 ;
}
static void
F_53 ( struct V_9 * V_10 , struct V_31 * V_125 ,
struct V_164 * V_165 )
{
F_9 ( V_58 , V_10 , L_9 ,
L_33 ) ;
}
static int T_6
F_54 ( void )
{
if ( ! V_166 ) {
F_33 ( L_34 ,
V_167 . V_75 ) ;
return - V_168 ;
}
F_55 ( V_167 . V_73 , 4 ) ;
F_56 ( V_169 ) ;
F_57 ( 0x2603 , F_13 ) ;
V_170 = & V_167 ;
return 0 ;
}
static void T_7
F_58 ( void )
{
F_59 ( 0x2603 , F_13 ) ;
F_60 ( V_169 ) ;
V_170 = NULL ;
}
