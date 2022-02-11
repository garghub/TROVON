void
F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
if ( (* V_4 . V_5 )( & V_3 , NULL ) != V_6 ) {
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
return;
}
V_2 -> V_7 = mktime ( V_3 . V_8 , V_3 . V_9 , V_3 . V_10 ,
V_3 . V_11 , V_3 . V_12 , V_3 . V_13 ) ;
V_2 -> V_14 = V_3 . V_15 ;
}
static int
F_2 ( T_2 * V_16 )
{
if ( ! ( V_16 -> V_17 & V_18 ) )
return 0 ;
switch ( V_16 -> type ) {
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
return 1 ;
}
return 0 ;
}
static inline T_3
F_3 ( T_4 * V_24 )
{
return ( V_24 -> V_25 + ( V_24 -> V_26 << V_27 ) ) ;
}
static inline T_3
F_4 ( T_2 * V_16 )
{
return ( V_16 -> V_28 + F_5 ( V_16 ) ) ;
}
static inline int
F_6 ( T_2 * V_16 )
{
return ( V_16 -> V_17 & V_18 ) ;
}
static inline int
F_7 ( T_2 * V_16 )
{
return ( V_16 -> V_17 & V_29 ) ;
}
static void
F_8 ( T_5 V_30 , void * V_31 , T_3 V_32 )
{
T_4 * V_33 ;
T_3 V_25 , V_34 , V_35 ;
V_35 = ( V_32 == V_18 ) ? V_36 : V_37 ;
for ( V_33 = V_38 ; V_33 -> V_25 != ~ 0UL ; V_33 ++ ) {
if ( V_33 -> V_17 != V_32 )
continue;
V_25 = F_9 ( V_33 -> V_25 ) ;
V_34 = ( V_33 -> V_25 + ( V_33 -> V_26 << V_27 ) ) & V_39 ;
if ( V_25 < V_34 )
if ( (* V_30)( V_25 + V_35 , V_34 + V_35 , V_31 ) < 0 )
return;
}
}
void
F_10 ( T_5 V_30 , void * V_31 )
{
F_8 ( V_30 , V_31 , V_18 ) ;
}
void
F_11 ( T_5 V_30 , void * V_31 )
{
F_8 ( V_30 , V_31 , V_29 ) ;
}
void *
F_12 ( void )
{
void * V_40 , * V_41 , * V_42 ;
T_2 * V_16 ;
T_3 V_43 ;
int V_44 = 0 ;
T_3 V_45 , V_46 ;
V_40 = F_13 ( V_47 -> V_48 ) ;
V_41 = V_40 + V_47 -> V_49 ;
V_43 = V_47 -> V_50 ;
for ( V_42 = V_40 ; V_42 < V_41 ; V_42 += V_43 ) {
V_16 = V_42 ;
if ( V_16 -> type != V_51 )
continue;
if ( ++ V_44 > 1 ) {
F_14 ( V_52 L_1
L_2 , V_16 -> V_28 ) ;
continue;
}
V_46 = ~ ( ( 1 << V_53 ) - 1 ) ;
V_45 = V_36 + V_16 -> V_28 ;
if ( ( V_45 & V_46 ) == ( V_54 & V_46 ) ) {
F_14 ( V_55 L_3 ,
V_56 ) ;
continue;
}
if ( F_5 ( V_16 ) > V_57 )
F_15 ( L_4 ) ;
#if V_58
V_46 = ~ ( ( 1 << V_59 ) - 1 ) ;
F_14 ( V_55 L_5
L_6 ,
F_16 () , V_16 -> V_28 ,
V_16 -> V_28 + F_5 ( V_16 ) ,
V_45 & V_46 , ( V_45 & V_46 ) + V_57 ) ;
#endif
return F_13 ( V_16 -> V_28 ) ;
}
F_14 ( V_60 L_7 ,
V_56 ) ;
return NULL ;
}
static T_6 T_7 F_17 ( T_6 * V_61 , T_8 V_62 )
{
T_6 V_63 = 0 ;
T_6 * V_34 = V_61 + V_62 ;
while ( V_61 < V_34 )
V_63 = ( T_6 ) ( V_63 + * ( V_61 ++ ) ) ;
return V_63 ;
}
static void T_7 F_18 ( unsigned long V_64 )
{
struct V_65 * V_66 = F_13 ( V_64 ) ;
T_6 V_67 ;
if ( strncmp ( V_66 -> V_68 , V_69 , sizeof( V_69 ) - 1 ) ) {
F_14 ( V_55 L_8 ) ;
return;
}
V_67 = F_17 ( ( T_6 * ) V_66 , V_66 -> V_62 ) ;
if ( V_67 ) {
F_14 ( V_55 L_9 ) ;
return;
}
F_19 ( V_66 -> V_70 , V_71 ) ;
}
void
F_20 ( void )
{
void * V_72 = F_12 () ;
T_3 V_73 ;
if ( ! V_72 )
return;
V_73 = F_21 () ;
F_22 ( 0x1 , V_74 ,
F_23 ( ( unsigned long ) V_72 ) ,
F_24 ( F_25 ( F_26 ( V_72 ) >> V_75 , V_76 ) ) ,
V_59 ) ;
F_27 () ;
F_28 ( V_73 ) ;
}
void T_7
F_29 ( void )
{
void * V_40 , * V_41 ;
T_9 * V_77 ;
T_10 * V_78 ;
T_3 V_43 ;
char * V_79 , V_80 [ 100 ] = L_10 ;
int V_81 ;
unsigned long V_64 ;
for ( V_79 = V_82 ; * V_79 ; ) {
if ( memcmp ( V_79 , L_11 , 4 ) == 0 ) {
V_83 = F_30 ( V_79 + 4 , & V_79 ) ;
} else if ( memcmp ( V_79 , L_12 , 9 ) == 0 ) {
V_84 = F_23 ( F_30 ( V_79 + 9 , & V_79 ) ) ;
} else if ( memcmp ( V_79 , L_13 , 9 ) == 0 ) {
V_85 = F_23 ( F_30 ( V_79 + 9 , & V_79 ) ) ;
} else {
while ( * V_79 != ' ' && * V_79 )
++ V_79 ;
while ( * V_79 == ' ' )
++ V_79 ;
}
}
if ( V_85 != 0UL )
F_14 ( V_55 L_14 ,
V_85 >> 20 ) ;
if ( V_84 != ~ 0UL )
F_14 ( V_55 L_15 ,
V_84 >> 20 ) ;
V_4 . V_86 = F_13 ( V_47 -> V_87 ) ;
if ( V_4 . V_86 == NULL )
F_15 ( L_16 ) ;
if ( V_4 . V_86 -> V_88 . V_68 != V_89 )
F_15 ( L_17 ) ;
if ( ( V_4 . V_86 -> V_88 . V_90 >> 16 ) == 0 )
F_14 ( V_60 L_18
L_19 ,
V_4 . V_86 -> V_88 . V_90 >> 16 ,
V_4 . V_86 -> V_88 . V_90 & 0xffff ) ;
V_77 = F_13 ( V_4 . V_86 -> V_91 ) ;
V_78 = F_13 ( V_4 . V_86 -> V_92 ) ;
if ( V_78 ) {
for ( V_81 = 0 ; V_81 < ( int ) sizeof( V_80 ) - 1 && * V_78 ; ++ V_81 )
V_80 [ V_81 ] = * V_78 ++ ;
V_80 [ V_81 ] = '\0' ;
}
F_14 ( V_55 L_20 ,
V_4 . V_86 -> V_88 . V_90 >> 16 ,
V_4 . V_86 -> V_88 . V_90 & 0xffff , V_80 ) ;
V_4 . V_93 = V_94 ;
V_4 . V_95 = V_94 ;
V_4 . V_96 = V_94 ;
V_4 . V_97 = V_94 ;
V_4 . V_98 = V_94 ;
V_4 . V_99 = V_94 ;
V_4 . V_100 = V_94 ;
V_4 . V_101 = V_94 ;
V_64 = V_94 ;
for ( V_81 = 0 ; V_81 < ( int ) V_4 . V_86 -> V_102 ; V_81 ++ ) {
if ( F_31 ( V_77 [ V_81 ] . V_103 , V_104 ) == 0 ) {
V_4 . V_93 = V_77 [ V_81 ] . V_105 ;
F_14 ( L_21 , V_77 [ V_81 ] . V_105 ) ;
} else if ( F_31 ( V_77 [ V_81 ] . V_103 , V_106 ) == 0 ) {
V_4 . V_96 = V_77 [ V_81 ] . V_105 ;
F_14 ( L_22 , V_77 [ V_81 ] . V_105 ) ;
} else if ( F_31 ( V_77 [ V_81 ] . V_103 , V_107 ) == 0 ) {
V_4 . V_95 = V_77 [ V_81 ] . V_105 ;
F_14 ( L_23 , V_77 [ V_81 ] . V_105 ) ;
} else if ( F_31 ( V_77 [ V_81 ] . V_103 , V_108 ) == 0 ) {
V_4 . V_97 = V_77 [ V_81 ] . V_105 ;
F_14 ( L_24 , V_77 [ V_81 ] . V_105 ) ;
} else if ( F_31 ( V_77 [ V_81 ] . V_103 , V_109 ) == 0 ) {
V_4 . V_98 = V_77 [ V_81 ] . V_105 ;
F_14 ( L_25 , V_77 [ V_81 ] . V_105 ) ;
} else if ( F_31 ( V_77 [ V_81 ] . V_103 , V_110 ) == 0 ) {
V_4 . V_100 = V_77 [ V_81 ] . V_105 ;
F_14 ( L_26 , V_77 [ V_81 ] . V_105 ) ;
} else if ( F_31 ( V_77 [ V_81 ] . V_103 ,
V_111 ) == 0 ) {
V_64 = V_77 [ V_81 ] . V_105 ;
F_14 ( L_27 , V_77 [ V_81 ] . V_105 ) ;
}
}
F_14 ( L_28 ) ;
if ( V_64 != V_94 )
F_18 ( V_64 ) ;
V_112 = F_13 ( V_4 . V_86 -> V_112 ) ;
V_4 . V_5 = V_113 ;
V_4 . V_114 = V_115 ;
V_4 . V_116 = V_117 ;
V_4 . V_118 = V_119 ;
V_4 . V_120 = V_121 ;
V_4 . V_122 = V_123 ;
V_4 . V_124 = V_125 ;
V_4 . V_126 = V_127 ;
V_4 . V_128 = V_129 ;
V_40 = F_13 ( V_47 -> V_48 ) ;
V_41 = V_40 + V_47 -> V_49 ;
V_43 = V_47 -> V_50 ;
#if V_58
{
T_2 * V_16 ;
void * V_42 ;
for ( V_81 = 0 , V_42 = V_40 ; V_42 < V_41 ;
++ V_81 , V_42 += V_43 )
{
const char * V_130 ;
unsigned long V_131 ;
V_16 = V_42 ;
V_131 = V_16 -> V_26 << V_27 ;
if ( ( V_131 >> 40 ) > 0 ) {
V_131 >>= 40 ;
V_130 = L_29 ;
} else if ( ( V_131 >> 30 ) > 0 ) {
V_131 >>= 30 ;
V_130 = L_30 ;
} else if ( ( V_131 >> 20 ) > 0 ) {
V_131 >>= 20 ;
V_130 = L_31 ;
} else {
V_131 >>= 10 ;
V_130 = L_32 ;
}
F_14 ( L_33
L_34 ,
V_81 , V_16 -> type , V_16 -> V_17 , V_16 -> V_28 ,
V_16 -> V_28 + F_5 ( V_16 ) , V_131 , V_130 ) ;
}
}
#endif
F_20 () ;
F_32 () ;
}
void
F_32 ( void )
{
void * V_40 , * V_41 , * V_42 ;
T_2 * V_16 ;
T_11 V_132 ;
T_3 V_43 ;
V_40 = F_13 ( V_47 -> V_48 ) ;
V_41 = V_40 + V_47 -> V_49 ;
V_43 = V_47 -> V_50 ;
for ( V_42 = V_40 ; V_42 < V_41 ; V_42 += V_43 ) {
V_16 = V_42 ;
if ( V_16 -> V_17 & V_133 ) {
if ( V_16 -> V_17 & V_18 ) {
V_16 -> V_134 = ( T_3 ) F_13 ( V_16 -> V_28 ) ;
} else if ( V_16 -> V_17 & V_29 ) {
V_16 -> V_134 = ( T_3 ) F_33 ( V_16 -> V_28 , 0 ) ;
} else if ( V_16 -> V_17 & V_135 ) {
#if 0
md->virt_addr = ia64_remap(md->phys_addr,
(_PAGE_A |
_PAGE_P |
_PAGE_D |
_PAGE_MA_WC |
_PAGE_PL_0 |
_PAGE_AR_RW));
#else
F_14 ( V_55 L_35 ) ;
V_16 -> V_134 = ( T_3 ) F_33 ( V_16 -> V_28 , 0 ) ;
#endif
} else if ( V_16 -> V_17 & V_136 ) {
#if 0
md->virt_addr = ia64_remap(md->phys_addr,
(_PAGE_A |
_PAGE_P |
_PAGE_D |
_PAGE_MA_WT |
_PAGE_PL_0 |
_PAGE_AR_RW));
#else
F_14 ( V_55 L_36 ) ;
V_16 -> V_134 = ( T_3 ) F_33 ( V_16 -> V_28 , 0 ) ;
#endif
}
}
}
V_132 = F_34 ( F_13 ( V_112 -> V_137 ) ,
V_47 -> V_49 ,
V_43 ,
V_47 -> V_138 ,
V_47 -> V_48 ) ;
if ( V_132 != V_6 ) {
F_14 ( V_60 L_37
L_38 , V_132 ) ;
return;
}
V_4 . V_5 = V_139 ;
V_4 . V_114 = V_140 ;
V_4 . V_116 = V_141 ;
V_4 . V_118 = V_142 ;
V_4 . V_120 = V_143 ;
V_4 . V_122 = V_144 ;
V_4 . V_124 = V_145 ;
V_4 . V_126 = V_146 ;
V_4 . V_128 = V_147 ;
}
T_3
F_35 ( void )
{
void * V_40 , * V_41 , * V_42 ;
T_2 * V_16 ;
T_3 V_43 ;
V_40 = F_13 ( V_47 -> V_48 ) ;
V_41 = V_40 + V_47 -> V_49 ;
V_43 = V_47 -> V_50 ;
for ( V_42 = V_40 ; V_42 < V_41 ; V_42 += V_43 ) {
V_16 = V_42 ;
if ( V_16 -> type == V_148 ) {
if ( V_16 -> V_17 & V_29 )
return V_16 -> V_28 ;
}
}
return 0 ;
}
static struct V_149 *
F_36 ( unsigned long V_28 )
{
struct V_149 * V_16 ;
for ( V_16 = V_38 ; V_16 -> V_25 != ~ 0UL ; V_16 ++ ) {
if ( V_28 - V_16 -> V_25 < ( V_16 -> V_26 << V_27 ) )
return V_16 ;
}
return NULL ;
}
static T_2 *
F_37 ( unsigned long V_28 )
{
void * V_40 , * V_41 , * V_42 ;
T_2 * V_16 ;
T_3 V_43 ;
V_40 = F_13 ( V_47 -> V_48 ) ;
V_41 = V_40 + V_47 -> V_49 ;
V_43 = V_47 -> V_50 ;
for ( V_42 = V_40 ; V_42 < V_41 ; V_42 += V_43 ) {
V_16 = V_42 ;
if ( V_28 - V_16 -> V_28 < F_5 ( V_16 ) )
return V_16 ;
}
return NULL ;
}
static int
F_38 ( unsigned long V_28 , unsigned long V_131 )
{
void * V_40 , * V_41 , * V_42 ;
T_2 * V_16 ;
T_3 V_43 ;
unsigned long V_34 ;
V_40 = F_13 ( V_47 -> V_48 ) ;
V_41 = V_40 + V_47 -> V_49 ;
V_43 = V_47 -> V_50 ;
V_34 = V_28 + V_131 ;
for ( V_42 = V_40 ; V_42 < V_41 ; V_42 += V_43 ) {
V_16 = V_42 ;
if ( V_16 -> V_28 < V_34 && F_4 ( V_16 ) > V_28 )
return 1 ;
}
return 0 ;
}
T_8
F_39 ( unsigned long V_28 )
{
T_2 * V_16 = F_37 ( V_28 ) ;
if ( V_16 )
return V_16 -> type ;
return 0 ;
}
T_3
F_40 ( unsigned long V_28 )
{
T_2 * V_16 = F_37 ( V_28 ) ;
if ( V_16 )
return V_16 -> V_17 ;
return 0 ;
}
T_3
F_41 ( unsigned long V_28 , unsigned long V_131 )
{
unsigned long V_34 = V_28 + V_131 ;
T_2 * V_16 = F_37 ( V_28 ) ;
T_3 V_32 ;
if ( ! V_16 )
return 0 ;
V_32 = V_16 -> V_17 & ~ V_133 ;
do {
unsigned long V_150 = F_4 ( V_16 ) ;
if ( V_34 <= V_150 )
return V_32 ;
V_16 = F_37 ( V_150 ) ;
if ( ! V_16 || ( V_16 -> V_17 & ~ V_133 ) != V_32 )
return 0 ;
} while ( V_16 );
return 0 ;
}
T_3
F_42 ( unsigned long V_28 , unsigned long V_131 )
{
unsigned long V_34 = V_28 + V_131 ;
struct V_149 * V_16 ;
T_3 V_32 ;
if ( ! V_38 ) {
V_32 = F_41 ( V_28 , V_131 ) ;
if ( V_32 & V_18 )
return V_18 ;
return 0 ;
}
V_16 = F_36 ( V_28 ) ;
if ( ! V_16 )
return 0 ;
V_32 = V_16 -> V_17 ;
do {
unsigned long V_150 = F_3 ( V_16 ) ;
if ( V_34 <= V_150 )
return V_32 ;
V_16 = F_36 ( V_150 ) ;
if ( ! V_16 || V_16 -> V_17 != V_32 )
return 0 ;
} while ( V_16 );
return 0 ;
}
int
F_43 ( unsigned long V_28 , unsigned long V_131 )
{
T_3 V_32 ;
V_32 = F_42 ( V_28 , V_131 ) ;
if ( V_32 & V_18 || V_32 & V_29 )
return 1 ;
return 0 ;
}
int
F_44 ( unsigned long V_151 , unsigned long V_131 )
{
unsigned long V_28 = V_151 << V_75 ;
T_3 V_32 ;
V_32 = F_41 ( V_28 , V_131 ) ;
if ( V_32 & V_18 || V_32 & V_29 )
return 1 ;
if ( F_38 ( V_28 , V_131 ) )
return 0 ;
return 1 ;
}
T_12
F_45 ( struct V_152 * V_152 , unsigned long V_151 , unsigned long V_131 ,
T_12 V_153 )
{
unsigned long V_28 = V_151 << V_75 ;
T_3 V_32 ;
V_32 = F_42 ( V_28 , V_131 ) ;
if ( V_32 & V_18 )
return F_46 ( V_153 ) ;
else if ( V_32 & V_29 )
return F_47 ( V_153 ) ;
if ( F_41 ( V_28 , V_131 ) & V_18 )
return F_46 ( V_153 ) ;
return F_47 ( V_153 ) ;
}
int T_7
F_48 ( void )
{
T_11 V_132 ;
char * V_154 , V_155 [] = L_39 ;
T_13 V_103 = V_156 ;
T_10 * V_157 , V_158 [ 32 ] ;
unsigned char V_159 [ 1024 ] ;
unsigned long V_131 = sizeof( V_159 ) ;
struct V_160 * V_88 , * V_161 ;
int V_162 = 0 ;
V_157 = V_158 ;
V_154 = V_155 ;
while ( * V_154 )
* V_157 ++ = * V_154 ++ & 0x7f ;
* V_157 = 0 ;
V_132 = V_4 . V_120 ( V_158 , & V_103 , NULL , & V_131 , V_159 ) ;
if ( V_132 != V_6 ) {
F_14 ( V_52 L_40 , V_155 ) ;
return 0 ;
}
V_88 = (struct V_160 * ) V_159 ;
V_161 = (struct V_160 * ) ( ( T_6 * ) V_159 + V_131 ) ;
while ( V_88 < V_161 ) {
if ( V_88 -> type == V_163 &&
V_88 -> V_164 == V_165 )
V_162 = 1 ;
else if ( V_88 -> type == V_166 ||
V_88 -> type == V_167 ) {
if ( ! V_162 )
return 0 ;
if ( V_88 -> V_164 == V_168 )
return 1 ;
V_162 = 0 ;
}
V_88 = (struct V_160 * ) ( ( T_6 * ) V_88 + V_88 -> V_62 ) ;
}
F_14 ( V_52 L_41 , V_155 ) ;
return 0 ;
}
struct V_149 *
F_49 ( void )
{
T_3 V_169 = 0 , V_170 = 0 ;
T_3 V_171 = 0 , V_172 ;
void * V_40 , * V_41 , * V_42 , * V_173 ;
T_2 * V_16 , * V_174 = NULL , * V_175 ;
T_3 V_176 , V_43 ;
unsigned long V_177 = 0 ;
V_40 = F_13 ( V_47 -> V_48 ) ;
V_41 = V_40 + V_47 -> V_49 ;
V_43 = V_47 -> V_50 ;
V_176 = sizeof( T_4 ) *
( 3 * ( V_47 -> V_49 / V_43 ) + 1 ) ;
for ( V_42 = V_40 ; V_42 < V_41 ; V_174 = V_16 , V_42 += V_43 ) {
V_16 = V_42 ;
if ( ! F_6 ( V_16 ) ) {
continue;
}
if ( V_174 == NULL || ! F_6 ( V_174 ) ||
F_4 ( V_174 ) != V_16 -> V_28 ) {
V_169 = F_50 ( V_16 -> V_28 ) ;
V_170 = F_4 ( V_16 ) ;
for ( V_173 = V_42 + V_43 ; V_173 < V_41 ;
V_173 += V_43 ) {
V_175 = V_173 ;
if ( ! F_6 ( V_175 ) )
break;
if ( V_170 != V_175 -> V_28 )
break;
V_170 = F_4 ( V_175 ) ;
}
V_170 = F_23 ( V_170 ) ;
}
if ( ! F_2 ( V_16 ) || V_16 -> type == V_20 )
continue;
V_171 = F_51 ( V_169 , V_16 -> V_28 ) ;
V_172 = F_52 ( V_170 , F_4 ( V_16 ) ) ;
V_171 = F_51 ( V_171 , V_85 ) ;
V_172 = F_52 ( V_172 , V_84 ) ;
if ( V_172 <= V_171 )
continue;
if ( V_177 + ( V_172 - V_171 ) > V_83 )
V_172 -= V_177 + ( V_172 - V_171 ) - V_83 ;
if ( V_172 <= V_171 )
continue;
if ( V_172 - V_171 > V_176 )
break;
}
if ( V_42 >= V_41 )
F_15 ( L_42 ) ;
return F_13 ( V_171 ) ;
}
unsigned long
F_53 ( T_3 * V_154 , T_3 * V_178 )
{
struct V_149 * V_33 , * V_179 = NULL ;
T_3 V_169 = 0 , V_170 = 0 ;
T_3 V_171 , V_172 , V_180 ;
void * V_40 , * V_41 , * V_42 , * V_173 ;
T_2 * V_16 , * V_174 = NULL , * V_175 ;
T_3 V_43 ;
unsigned long V_177 = 0 ;
V_33 = V_38 = F_49 () ;
V_40 = F_13 ( V_47 -> V_48 ) ;
V_41 = V_40 + V_47 -> V_49 ;
V_43 = V_47 -> V_50 ;
for ( V_42 = V_40 ; V_42 < V_41 ; V_174 = V_16 , V_42 += V_43 ) {
V_16 = V_42 ;
if ( ! F_6 ( V_16 ) ) {
if ( F_7 ( V_16 ) &&
( V_16 -> type == V_23 ||
V_16 -> type == V_22 ) ) {
V_33 -> V_17 = V_29 ;
V_33 -> V_25 = V_16 -> V_28 ;
V_33 -> V_26 = V_16 -> V_26 ;
V_33 ++ ;
}
continue;
}
if ( V_174 == NULL || ! F_6 ( V_174 ) ||
F_4 ( V_174 ) != V_16 -> V_28 ) {
V_169 = F_50 ( V_16 -> V_28 ) ;
V_170 = F_4 ( V_16 ) ;
for ( V_173 = V_42 + V_43 ; V_173 < V_41 ;
V_173 += V_43 ) {
V_175 = V_173 ;
if ( ! F_6 ( V_175 ) )
break;
if ( V_170 != V_175 -> V_28 )
break;
V_170 = F_4 ( V_175 ) ;
}
V_170 = F_23 ( V_170 ) ;
}
if ( ! F_2 ( V_16 ) )
continue;
#ifdef F_54
if ( V_181 < ( F_4 ( V_16 ) >> V_75 ) )
V_181 = ( F_4 ( V_16 ) >> V_75 ) ;
#endif
if ( V_16 -> V_28 < V_169 ) {
V_180 = F_52 ( F_4 ( V_16 ) , V_169 ) ;
if ( F_7 ( V_16 ) ) {
if ( V_33 > V_38 &&
( V_33 - 1 ) -> V_17 == V_29 &&
F_3 ( V_33 - 1 ) == V_16 -> V_28 ) {
( V_33 - 1 ) -> V_26 +=
( V_180 - V_16 -> V_28 )
>> V_27 ;
} else {
V_33 -> V_17 = V_29 ;
V_33 -> V_25 = V_16 -> V_28 ;
V_33 -> V_26 = ( V_180 - V_16 -> V_28 )
>> V_27 ;
V_33 ++ ;
}
}
V_171 = V_169 ;
} else
V_171 = V_16 -> V_28 ;
if ( F_4 ( V_16 ) > V_170 ) {
V_180 = F_51 ( V_16 -> V_28 , V_170 ) ;
if ( F_7 ( V_16 ) ) {
if ( V_180 == V_16 -> V_28 && V_33 > V_38 &&
( V_33 - 1 ) -> V_17 == V_29 &&
F_3 ( V_33 - 1 ) == V_16 -> V_28 ) {
( V_33 - 1 ) -> V_26 += V_16 -> V_26 ;
} else {
V_33 -> V_17 = V_29 ;
V_33 -> V_25 = V_180 ;
V_33 -> V_26 = ( F_4 ( V_16 ) - V_180 )
>> V_27 ;
V_33 ++ ;
}
}
V_172 = V_170 ;
} else
V_172 = F_4 ( V_16 ) ;
V_171 = F_51 ( V_171 , V_85 ) ;
V_172 = F_52 ( V_172 , V_84 ) ;
if ( V_172 <= V_171 )
continue;
if ( V_177 + ( V_172 - V_171 ) > V_83 )
V_172 -= V_177 + ( V_172 - V_171 ) - V_83 ;
if ( V_172 <= V_171 )
continue;
if ( V_179 && F_3 ( V_179 ) == V_16 -> V_28 ) {
V_179 -> V_26 += ( V_172 - V_171 ) >> V_27 ;
V_177 += V_172 - V_171 ;
continue;
}
V_33 -> V_17 = V_18 ;
V_33 -> V_25 = V_171 ;
V_33 -> V_26 = ( V_172 - V_171 ) >> V_27 ;
V_177 += V_172 - V_171 ;
V_179 = V_33 ++ ;
}
V_33 -> V_25 = ~ 0L ;
* V_154 = ( T_3 ) V_38 ;
* V_178 = ( T_3 ) ++ V_33 ;
return V_177 ;
}
void
F_55 ( struct V_182 * V_183 ,
struct V_182 * V_184 ,
struct V_182 * V_185 )
{
struct V_182 * V_186 ;
void * V_40 , * V_41 , * V_42 ;
T_2 * V_16 ;
T_3 V_43 ;
char * V_155 ;
unsigned long V_187 ;
V_40 = F_13 ( V_47 -> V_48 ) ;
V_41 = V_40 + V_47 -> V_49 ;
V_43 = V_47 -> V_50 ;
V_186 = NULL ;
for ( V_42 = V_40 ; V_42 < V_41 ; V_42 += V_43 ) {
V_16 = V_42 ;
if ( V_16 -> V_26 == 0 )
continue;
V_187 = V_188 | V_189 ;
switch ( V_16 -> type ) {
case V_190 :
case V_148 :
continue;
case V_19 :
case V_20 :
case V_22 :
case V_21 :
case V_23 :
if ( V_16 -> V_17 & V_191 ) {
V_155 = L_43 ;
V_187 |= V_192 ;
} else if ( V_16 -> V_17 == V_29 )
V_155 = L_44 ;
else
V_155 = L_45 ;
break;
case V_193 :
V_155 = L_46 ;
break;
case V_194 :
V_155 = L_47 ;
V_187 |= V_195 ;
break;
case V_196 :
case V_197 :
case V_198 :
case V_199 :
default:
V_155 = L_47 ;
break;
}
if ( ( V_186 = F_56 ( sizeof( struct V_182 ) ,
V_200 ) ) == NULL ) {
F_14 ( V_52
L_48 ) ;
return;
}
V_186 -> V_155 = V_155 ;
V_186 -> V_25 = V_16 -> V_28 ;
V_186 -> V_34 = V_16 -> V_28 + F_5 ( V_16 ) - 1 ;
V_186 -> V_187 = V_187 ;
if ( F_57 ( & V_201 , V_186 ) < 0 )
F_58 ( V_186 ) ;
else {
F_57 ( V_186 , V_183 ) ;
F_57 ( V_186 , V_184 ) ;
F_57 ( V_186 , V_185 ) ;
#ifdef F_59
F_57 ( V_186 , & V_202 ) ;
F_57 ( V_186 , & V_203 ) ;
if ( V_204 . V_34 > V_204 . V_25 )
F_57 ( V_186 , & V_204 ) ;
#endif
}
}
}
unsigned long T_7
F_60 ( unsigned long V_131 , struct V_205 * V_206 , int V_207 )
{
int V_81 ;
T_3 V_25 , V_34 ;
T_3 V_208 = 1UL << V_209 ;
void * V_40 , * V_41 , * V_42 ;
T_2 * V_16 ;
T_3 V_43 ;
V_40 = F_13 ( V_47 -> V_48 ) ;
V_41 = V_40 + V_47 -> V_49 ;
V_43 = V_47 -> V_50 ;
for ( V_42 = V_40 ; V_42 < V_41 ; V_42 += V_43 ) {
V_16 = V_42 ;
if ( ! F_6 ( V_16 ) )
continue;
V_25 = F_61 ( V_16 -> V_28 , V_208 ) ;
V_34 = F_4 ( V_16 ) ;
for ( V_81 = 0 ; V_81 < V_207 ; V_81 ++ ) {
if ( F_26 ( V_206 [ V_81 ] . V_25 ) >= V_25 && F_26 ( V_206 [ V_81 ] . V_34 ) < V_34 ) {
if ( F_26 ( V_206 [ V_81 ] . V_25 ) > V_25 + V_131 )
return V_25 ;
V_25 = F_61 ( F_26 ( V_206 [ V_81 ] . V_34 ) , V_208 ) ;
if ( V_81 < V_207 - 1 &&
F_26 ( V_206 [ V_81 + 1 ] . V_25 ) < V_25 + V_131 )
continue;
else
break;
}
}
if ( V_34 > V_25 + V_131 )
return V_25 ;
}
F_14 ( V_60
L_49 , V_131 ) ;
return ~ 0UL ;
}
unsigned long T_7
F_62 ( unsigned long V_210 )
{
void * V_40 , * V_41 , * V_42 ;
T_2 * V_16 ;
T_3 V_43 ;
unsigned long V_211 = 0 ;
V_40 = F_13 ( V_47 -> V_48 ) ;
V_41 = V_40 + V_47 -> V_49 ;
V_43 = V_47 -> V_50 ;
for ( V_42 = V_40 ; V_42 < V_41 ; V_42 += V_43 ) {
V_16 = V_42 ;
if ( F_6 ( V_16 ) && V_16 -> type == V_20
&& V_16 -> V_28 == V_210 ) {
V_211 = F_5 ( V_16 ) ;
break;
}
}
if ( V_211 == 0 )
F_14 ( V_60 L_50 ) ;
return V_211 ;
}
