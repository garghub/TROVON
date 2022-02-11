static inline int F_1 ( void * V_1 , int V_2 )
{
register unsigned long T_1 V_3 ( L_1 ) = ( unsigned long ) V_1 ;
typedef union {
struct V_4 V_5 ;
struct V_6 V_7 ;
} T_2;
int V_8 ;
V_8 = 3 ;
F_2 ( V_9 ) ;
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
F_3 ( struct V_10 * V_11 , unsigned int V_12 ,
T_3 V_13 , T_3 * V_14 )
{
struct V_15 * V_16 ;
struct V_4 * V_17 ;
int V_8 ;
V_16 = (struct V_15 * ) V_11 -> V_16 ;
V_17 = & V_16 -> V_17 ;
memset ( V_17 , 0 , sizeof ( struct V_4 ) ) ;
V_17 -> V_18 = V_16 -> V_19 . V_20 ;
V_17 -> V_21 = V_12 ;
V_17 -> V_13 = V_13 ;
V_17 -> V_22 = V_23 ;
V_8 = F_1 ( V_17 , V_24 ) ;
if ( ( V_8 & 3 ) == 0 && V_14 )
* V_14 = V_17 -> V_14 ;
return V_8 ;
}
static inline int
F_4 ( struct V_10 * V_11 )
{
struct V_15 * V_16 ;
struct V_4 * V_17 ;
int V_8 ;
V_16 = (struct V_15 * ) V_11 -> V_16 ;
V_17 = & V_16 -> V_17 ;
memset ( V_17 , 0 , sizeof ( struct V_4 ) ) ;
V_17 -> V_18 = V_16 -> V_19 . V_20 ;
V_8 = F_1 ( V_17 , V_25 ) ;
return V_8 ;
}
static void
F_5 ( struct V_10 * V_11 )
{
int V_8 ;
F_4 ( V_11 ) ;
V_8 = F_3 ( V_11 , V_11 -> V_26 -> V_27 , 0 , NULL ) ;
if ( V_8 == 4 ) {
if ( ! ( F_6 ( V_28 , & V_11 -> V_29 ) ) )
F_7 ( L_2
L_3 ,
F_8 ( & V_11 -> V_30 -> V_31 ) ) ;
V_8 = 0 ;
}
if ( V_8 )
F_7 ( L_4
L_5 , F_8 ( & V_11 -> V_30 -> V_31 ) , V_8 ) ;
}
static int
F_9 ( struct V_32 * V_33 )
{
struct V_10 * V_11 ;
struct V_15 * V_16 ;
struct V_34 * V_35 ;
int V_8 ;
V_11 = V_33 -> V_36 ;
if ( V_33 -> V_37 < 0 ) {
F_10 ( V_38 , V_11 , L_6
L_7 , V_33 ) ;
V_33 -> V_39 = V_40 ;
return - V_41 ;
}
V_16 = (struct V_15 * ) V_11 -> V_16 ;
V_35 = (struct V_34 * ) V_33 -> V_42 ;
V_16 -> V_1 . V_18 = V_16 -> V_19 . V_20 ;
V_16 -> V_1 . V_43 = 0 ;
V_16 -> V_1 . V_29 = V_44 ;
V_16 -> V_1 . V_45 = V_35 -> V_45 ;
V_16 -> V_1 . V_46 = ( V_47 ) V_33 ;
V_16 -> V_1 . V_48 = V_35 -> V_49 ;
V_16 -> V_1 . V_22 = V_23 ;
V_33 -> V_50 = F_11 () ;
V_33 -> V_51 = V_52 ;
V_33 -> V_37 -- ;
V_8 = F_1 ( & V_16 -> V_1 , V_53 ) ;
switch ( V_8 ) {
case 0 :
V_33 -> V_54 = F_11 () ;
V_33 -> V_39 = V_55 ;
V_8 = - V_56 ;
break;
case 8 :
V_33 -> V_39 = V_57 ;
V_8 = 0 ;
break;
default:
V_33 -> V_39 = V_58 ;
F_10 ( V_59 , V_11 , L_8 , V_8 ) ;
F_5 ( V_11 ) ;
V_8 = - V_41 ;
break;
}
V_33 -> V_60 = V_8 ;
return V_8 ;
}
static int
F_12 ( struct V_32 * V_33 )
{
struct V_10 * V_11 ;
V_11 = V_33 -> V_36 ;
F_4 ( V_11 ) ;
F_3 ( V_11 , V_11 -> V_26 -> V_27 , 0 , NULL ) ;
V_33 -> V_39 = V_61 ;
V_33 -> V_54 = F_11 () ;
F_13 ( V_11 ) ;
return 0 ;
}
static void F_14 ( struct V_62 V_62 ,
unsigned int V_63 , unsigned long V_64 )
{
struct V_32 * V_33 , * V_65 ;
struct V_10 * V_11 ;
unsigned long long V_66 ;
unsigned long V_29 ;
V_47 V_67 ;
int V_8 ;
switch ( V_62 . V_68 >> 8 ) {
case V_69 :
V_67 = ( V_47 ) V_63 ;
break;
case V_70 :
V_67 = ( V_47 ) V_64 ;
break;
default:
return;
}
F_15 ( V_71 ) ;
if ( ! V_67 ) {
F_16 ( V_72 , L_9 , L_10
L_11 ) ;
return;
}
V_33 = (struct V_32 * ) V_67 ;
V_11 = (struct V_10 * ) V_33 -> V_36 ;
if ( strncmp ( V_11 -> V_73 -> V_74 , ( char * ) & V_33 -> V_75 , 4 ) ) {
F_10 ( V_59 , V_11 ,
L_12
L_13 ,
V_33 -> V_75 , * ( int * ) ( & V_11 -> V_73 -> V_76 ) ) ;
return;
}
F_17 ( F_18 ( V_11 -> V_30 ) , V_29 ) ;
if ( V_33 -> V_39 == V_61 ) {
V_33 -> V_39 = V_77 ;
F_19 ( V_11 ) ;
F_13 ( V_11 ) ;
F_20 ( F_18 ( V_11 -> V_30 ) , V_29 ) ;
return;
}
V_33 -> V_54 = F_11 () ;
V_66 = 0 ;
if ( ( V_62 . V_68 & 0xff ) == 0 ) {
V_33 -> V_39 = V_55 ;
if ( ! F_21 ( & V_11 -> V_78 ) ) {
V_65 = F_22 ( V_11 -> V_78 . V_65 ,
struct V_32 , V_79 ) ;
if ( V_65 -> V_39 == V_58 ) {
V_8 = F_9 ( V_65 ) ;
if ( V_8 == 0 )
V_66 = V_65 -> V_66 ;
}
}
} else {
V_33 -> V_39 = V_58 ;
F_10 ( V_80 , V_11 , L_14
L_15 , V_33 ,
V_62 . V_68 & 0xff , V_33 -> V_37 ) ;
F_5 ( V_11 ) ;
}
if ( V_66 != 0 )
F_23 ( V_11 , V_66 ) ;
else
F_19 ( V_11 ) ;
F_13 ( V_11 ) ;
F_20 ( F_18 ( V_11 -> V_30 ) , V_29 ) ;
}
static int
F_24 ( struct V_10 * V_11 )
{
struct V_81 * V_26 ;
struct V_15 * V_16 ;
struct V_82 * V_83 ;
struct V_84 V_49 ;
struct V_85 * V_86 ;
T_3 V_14 ;
unsigned int V_87 , V_88 ;
int V_8 ;
V_16 = (struct V_15 * ) V_11 -> V_16 ;
if ( V_16 == NULL ) {
V_16 = F_25 ( sizeof( struct V_15 ) , V_89 ) ;
if ( V_16 == NULL ) {
F_10 ( V_59 , V_11 , L_9 ,
L_16
L_17 ) ;
return - V_90 ;
}
F_26 ( V_11 -> V_30 , & V_16 -> V_19 ) ;
V_11 -> V_16 = ( void * ) V_16 ;
}
V_26 = F_27 () ;
if ( F_28 ( V_26 ) ) {
F_10 ( V_59 , V_11 , L_9 ,
L_18 ) ;
V_11 -> V_16 = NULL ;
F_29 ( V_16 ) ;
return F_30 ( V_26 ) ;
}
V_11 -> V_26 = V_26 ;
V_26 -> V_91 = V_11 ;
V_83 = ( void * ) & ( V_16 -> V_83 ) ;
V_83 -> V_18 = V_16 -> V_19 . V_20 ;
V_83 -> V_92 = sizeof ( struct V_82 ) ;
V_8 = F_31 ( (struct F_31 * ) V_83 ) ;
if ( V_8 ) {
F_10 ( V_59 , V_11 , L_19
L_20 , V_8 ) ;
V_8 = - V_93 ;
goto V_94;
}
V_11 -> V_95 = V_96 ;
V_11 -> V_97 = V_98 ;
switch ( V_16 -> V_83 . V_99 ) {
case V_100 :
V_16 -> V_101 = 1 ;
break;
case V_102 :
V_16 -> V_101 = 2 ;
break;
default:
F_7 ( L_21
L_22 , F_8 ( & V_11 -> V_30 -> V_31 ) ,
V_16 -> V_83 . V_99 ) ;
V_8 = - V_93 ;
goto V_94;
}
F_10 ( V_103 , V_11 ,
L_23 ,
V_83 -> V_18 ,
V_83 -> V_104 ,
V_83 -> V_105 , V_83 -> V_106 ) ;
F_4 ( V_11 ) ;
V_86 = (struct V_85 * ) F_32 ( V_89 ) ;
if ( V_86 == NULL ) {
F_10 ( V_59 , V_11 , L_9 ,
L_24 ) ;
V_8 = - V_90 ;
goto V_94;
}
V_8 = 0 ;
V_14 = 0 ;
for ( V_88 = 512 ; V_88 <= V_107 ; V_88 <<= 1 ) {
F_3 ( V_11 , V_88 , 0 , & V_14 ) ;
memset ( & V_49 , 0 , sizeof ( struct V_84 ) ) ;
V_49 . type = V_108 ;
V_49 . V_109 = V_16 -> V_101 + 1 ;
V_49 . V_110 = V_86 ;
memset ( & V_16 -> V_1 , 0 , sizeof ( struct V_6 ) ) ;
V_16 -> V_1 . V_18 = V_83 -> V_18 ;
V_16 -> V_1 . V_43 = 0 ;
V_16 -> V_1 . V_29 = 0 ;
V_16 -> V_1 . V_45 = 1 ;
V_16 -> V_1 . V_46 = 0 ;
V_16 -> V_1 . V_48 = & V_49 ;
V_16 -> V_1 . V_22 = V_23 ;
V_8 = F_1 ( & V_16 -> V_1 , V_53 ) ;
if ( V_8 == 3 ) {
F_7 ( L_25 ,
F_8 ( & V_11 -> V_30 -> V_31 ) ) ;
V_8 = - V_93 ;
goto V_111;
}
F_4 ( V_11 ) ;
if ( V_8 == 0 )
break;
}
if ( V_88 > V_107 ) {
F_7 ( L_26
L_27 ,
F_8 ( & V_11 -> V_30 -> V_31 ) , V_8 ) ;
V_8 = - V_41 ;
goto V_111;
}
if ( memcmp ( V_86 -> V_112 , V_113 ,
sizeof( V_113 ) ) == 0 ) {
V_88 = ( unsigned int ) V_86 -> V_21 ;
V_26 -> V_114 = ( unsigned long ) V_86 -> V_45 ;
} else
V_26 -> V_114 = V_14 ;
V_26 -> V_27 = V_88 ;
V_26 -> V_115 = 0 ;
for ( V_87 = 512 ; V_87 < V_88 ; V_87 = V_87 << 1 )
V_26 -> V_115 ++ ;
V_8 = F_3 ( V_11 , V_26 -> V_27 , 0 , NULL ) ;
if ( V_8 && ( V_8 != 4 ) ) {
F_7 ( L_28 ,
F_8 ( & V_11 -> V_30 -> V_31 ) , V_8 ) ;
V_8 = - V_41 ;
} else {
if ( V_8 == 4 )
F_33 ( V_28 , & V_11 -> V_29 ) ;
F_34 ( L_29
L_30 , F_8 ( & V_11 -> V_30 -> V_31 ) ,
( unsigned long ) V_26 -> V_27 ,
( unsigned long ) ( V_26 -> V_114 <<
V_26 -> V_115 ) >> 1 ,
( V_8 == 4 ) ? L_31 : L_32 ) ;
V_8 = 0 ;
}
V_111:
F_35 ( ( long ) V_86 ) ;
V_94:
if ( V_8 ) {
V_11 -> V_26 = NULL ;
F_36 ( V_26 ) ;
V_11 -> V_16 = NULL ;
F_29 ( V_16 ) ;
}
return V_8 ;
}
static int
F_37 ( struct V_81 * V_26 , struct V_116 * V_117 )
{
if ( F_38 ( V_26 -> V_27 ) != 0 )
return - V_118 ;
V_117 -> V_119 = ( V_26 -> V_114 << V_26 -> V_115 ) >> 10 ;
V_117 -> V_120 = 16 ;
V_117 -> V_121 = 128 >> V_26 -> V_115 ;
return 0 ;
}
static T_4
F_39 ( struct V_32 * V_33 )
{
return V_122 ;
}
static T_4
F_40 ( struct V_32 * V_33 )
{
return V_123 ;
}
static struct V_32 * F_41 ( struct V_10 * V_124 ,
struct V_81 * V_26 ,
struct V_125 * V_126 )
{
struct V_32 * V_33 ;
struct V_34 * V_35 ;
struct V_84 * V_127 ;
struct V_128 V_129 ;
struct V_130 V_131 ;
char * V_132 ;
unsigned int V_133 , V_134 ;
T_5 V_135 , V_136 , V_137 ;
unsigned int V_138 , V_139 ;
unsigned char V_140 ;
if ( F_42 ( V_126 ) == V_141 )
V_140 = V_108 ;
else if ( F_42 ( V_126 ) == V_142 )
V_140 = V_143 ;
else
return F_43 ( - V_118 ) ;
V_138 = V_26 -> V_27 ;
V_136 = F_44 ( V_126 ) >> V_26 -> V_115 ;
V_137 =
( F_44 ( V_126 ) + F_45 ( V_126 ) - 1 ) >> V_26 -> V_115 ;
V_133 = 0 ;
F_46 (bv, req, iter) {
if ( V_131 . V_144 & ( V_138 - 1 ) )
return F_43 ( - V_118 ) ;
V_133 += V_131 . V_144 >> ( V_26 -> V_115 + 9 ) ;
}
if ( V_133 != V_137 - V_136 + 1 )
return F_43 ( - V_118 ) ;
V_134 = sizeof( struct V_34 ) +
V_133 * sizeof( struct V_84 ) ;
V_33 = F_47 ( V_145 , 0 , V_134 , V_124 ) ;
if ( F_28 ( V_33 ) )
return V_33 ;
V_35 = (struct V_34 * ) V_33 -> V_42 ;
V_35 -> V_45 = V_133 ;
V_127 = V_35 -> V_49 ;
V_135 = V_136 ;
F_46 (bv, req, iter) {
V_132 = F_48 ( V_131 . V_146 ) + V_131 . V_147 ;
for ( V_139 = 0 ; V_139 < V_131 . V_144 ; V_139 += V_138 ) {
memset ( V_127 , 0 , sizeof ( struct V_84 ) ) ;
V_127 -> type = V_140 ;
V_127 -> V_109 = V_135 + 1 ;
V_127 -> V_110 = V_132 ;
V_127 ++ ;
V_132 += V_138 ;
V_135 ++ ;
}
}
V_33 -> V_37 = V_124 -> V_97 ;
V_33 -> V_148 = F_11 () ;
if ( F_49 ( V_126 ) ||
V_26 -> V_91 -> V_149 & V_150 )
F_33 ( V_151 , & V_33 -> V_29 ) ;
V_33 -> V_36 = V_124 ;
V_33 -> V_124 = V_124 ;
V_33 -> V_26 = V_26 ;
V_33 -> V_66 = V_124 -> V_95 * V_152 ;
V_33 -> V_39 = V_153 ;
return V_33 ;
}
static int
F_50 ( struct V_32 * V_33 , struct V_125 * V_126 )
{
int V_39 ;
V_39 = V_33 -> V_39 == V_154 ;
F_51 ( V_33 , V_33 -> V_124 ) ;
return V_39 ;
}
static void F_52 ( struct V_32 * V_33 )
{
if ( V_33 -> V_37 < 0 )
V_33 -> V_39 = V_155 ;
else
V_33 -> V_39 = V_153 ;
}
static int
F_53 ( struct V_10 * V_11 ,
struct V_156 * V_157 )
{
struct V_15 * V_16 ;
V_16 = (struct V_15 * ) V_11 -> V_16 ;
V_157 -> V_158 = ( unsigned int ) V_16 -> V_101 ;
V_157 -> V_159 = 1 ;
V_157 -> V_160 = V_161 ;
V_157 -> V_162 = sizeof ( struct V_82 ) ;
memcpy ( V_157 -> V_163 ,
& ( (struct V_15 * ) V_11 -> V_16 ) -> V_83 ,
sizeof ( struct V_82 ) ) ;
V_157 -> V_164 = 0 ;
return 0 ;
}
static void
F_54 ( struct V_10 * V_11 , struct V_32 * V_126 ,
struct V_165 * V_166 )
{
F_10 ( V_59 , V_11 , L_9 ,
L_33 ) ;
}
static int T_6
F_55 ( void )
{
if ( ! V_167 ) {
F_34 ( L_34 ,
V_168 . V_76 ) ;
return - V_169 ;
}
F_56 ( V_168 . V_74 , 4 ) ;
F_57 ( V_170 ) ;
F_58 ( V_171 , F_14 ) ;
V_172 = & V_168 ;
return 0 ;
}
static void T_7
F_59 ( void )
{
F_60 ( V_171 , F_14 ) ;
F_61 ( V_170 ) ;
V_172 = NULL ;
}
