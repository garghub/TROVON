static inline void T_1 *
F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
if ( ( V_3 < V_2 -> V_4 ) &&
( V_3 >= V_2 -> V_5 ) )
return ( void T_1 * ) ( V_2 -> V_6 + V_3 ) ;
return NULL ;
}
static void
F_2 ( void )
{
F_3 ( V_7 ) ;
F_3 ( V_8 ) ;
F_3 ( V_9 ) ;
F_3 ( V_10 ) ;
F_3 ( V_11 ) ;
F_3 ( V_12 ) ;
F_3 ( V_13 ) ;
F_3 ( V_14 ) ;
F_3 ( V_15 ) ;
F_3 ( V_16 ) ;
F_3 ( V_17 ) ;
F_3 ( V_18 ) ;
F_3 ( V_19 ) ;
F_3 ( V_20 ) ;
F_3 ( V_21 ) ;
F_3 ( V_22 ) ;
F_3 ( V_23 ) ;
F_3 ( V_24 ) ;
F_3 ( V_25 ) ;
F_3 ( V_26 ) ;
F_3 ( V_27 ) ;
F_3 ( V_28 ) ;
F_3 ( V_29 ) ;
F_3 ( V_30 ) ;
F_3 ( V_31 ) ;
F_3 ( V_32 ) ;
F_3 ( V_33 ) ;
F_3 ( V_34 ) ;
F_3 ( V_35 ) ;
F_3 ( V_36 ) ;
F_3 ( V_37 ) ;
F_3 ( V_38 ) ;
F_3 ( V_39 ) ;
F_3 ( V_40 ) ;
F_3 ( V_41 ) ;
F_3 ( V_42 ) ;
F_3 ( V_43 ) ;
F_3 ( V_44 ) ;
F_3 ( V_45 ) ;
F_3 ( V_46 ) ;
F_3 ( V_47 ) ;
F_3 ( V_48 ) ;
F_3 ( V_49 ) ;
F_3 ( V_50 ) ;
F_3 ( V_51 ) ;
F_3 ( V_52 ) ;
F_3 ( V_53 ) ;
F_3 ( V_54 ) ;
F_3 ( V_55 ) ;
F_3 ( V_56 ) ;
F_3 ( V_57 ) ;
V_58 = 1 ;
}
static void
F_4 ( struct V_1 * V_2 , T_2 * V_3 )
{
T_3 V_59 ;
V_2 -> V_60 = F_5 ( * V_3 ) ;
F_6 ( V_2 -> V_60 ,
( void T_1 * ) ( V_61 + V_2 -> V_6 ) ) ;
V_59 = F_7 ( ( void T_1 * ) ( V_61 + V_2 -> V_6 ) ) ;
if ( V_59 != V_2 -> V_60 ) {
F_8 ( F_9 ( V_62 , V_2 ,
L_1
L_2 , V_63 , V_2 -> V_60 , V_59 , * V_3 ) ) ;
}
* V_3 = ( * V_3 & F_10 ( 16 ) ) + V_64 + V_2 -> V_6 ;
}
void
F_11 ( struct V_1 * V_2 , T_2 V_3 , T_3 V_65 )
{
unsigned long V_66 = 0 ;
int V_67 ;
V_67 = F_12 ( V_2 , & V_3 ) ;
F_13 ( V_67 == - 1 ) ;
if ( V_67 == 1 ) {
F_14 ( & V_2 -> V_68 , V_66 ) ;
F_15 ( V_2 ) ;
F_4 ( V_2 , & V_3 ) ;
}
F_6 ( V_65 , ( void T_1 * ) V_3 ) ;
if ( V_67 == 1 ) {
F_16 ( V_2 ) ;
F_17 ( & V_2 -> V_68 , V_66 ) ;
}
}
int
F_18 ( struct V_1 * V_2 , T_2 V_3 )
{
unsigned long V_66 = 0 ;
int V_67 ;
T_3 V_65 ;
V_67 = F_12 ( V_2 , & V_3 ) ;
F_13 ( V_67 == - 1 ) ;
if ( V_67 == 1 ) {
F_14 ( & V_2 -> V_68 , V_66 ) ;
F_15 ( V_2 ) ;
F_4 ( V_2 , & V_3 ) ;
}
V_65 = F_7 ( ( void T_1 * ) V_3 ) ;
if ( V_67 == 1 ) {
F_16 ( V_2 ) ;
F_17 ( & V_2 -> V_68 , V_66 ) ;
}
return V_65 ;
}
int F_15 ( struct V_1 * V_2 )
{
int V_69 ;
int V_70 = 0 , V_71 = 0 ;
while ( ! V_70 ) {
V_70 = F_18 ( V_2 , F_19 ( V_72 ) ) ;
if ( V_70 == 1 )
break;
if ( V_71 >= V_73 )
return - 1 ;
V_71 ++ ;
if ( ! F_20 () )
F_21 () ;
else {
for ( V_69 = 0 ; V_69 < 20 ; V_69 ++ )
F_22 () ;
}
}
F_11 ( V_2 , V_74 , V_2 -> V_75 ) ;
return 0 ;
}
void F_16 ( struct V_1 * V_2 )
{
F_18 ( V_2 , F_19 ( V_76 ) ) ;
}
int F_23 ( struct V_1 * V_2 )
{
int V_69 ;
int V_70 = 0 , V_71 = 0 ;
while ( ! V_70 ) {
V_70 = F_18 ( V_2 , F_19 ( V_77 ) ) ;
if ( V_70 == 1 )
break;
if ( V_71 >= V_78 )
return - 1 ;
V_71 ++ ;
if ( ! F_20 () )
F_21 () ;
else {
for ( V_69 = 0 ; V_69 < 20 ; V_69 ++ )
F_22 () ;
}
}
return 0 ;
}
void F_24 ( struct V_1 * V_2 )
{
F_18 ( V_2 , F_19 ( V_79 ) ) ;
}
int
F_12 ( struct V_1 * V_2 , T_2 * V_3 )
{
struct V_80 * V_81 ;
if ( * V_3 >= V_82 )
return - 1 ;
if ( * V_3 >= V_83 && ( * V_3 < V_84 ) ) {
* V_3 = ( * V_3 - V_83 ) +
V_85 + V_2 -> V_6 ;
return 0 ;
}
if ( * V_3 < V_86 )
return - 1 ;
* V_3 -= V_86 ;
V_81 = & V_87 [ F_25 ( * V_3 ) ] . V_88 [ F_26 ( * V_3 ) ] ;
if ( V_81 -> V_89 && ( V_81 -> V_90 <= * V_3 ) && ( V_81 -> V_91 > * V_3 ) ) {
* V_3 = * V_3 + V_81 -> V_92 - V_81 -> V_90 + V_2 -> V_6 ;
return 0 ;
}
return 1 ;
}
static unsigned long
F_27 ( struct V_1 * V_2 ,
unsigned long long V_93 , int V_94 )
{
if ( ! F_28 ( V_93 , V_95 ,
V_96 ) ||
! F_28 ( V_93 + V_94 - 1 ,
V_95 , V_96 ) ||
( ( V_94 != 1 ) && ( V_94 != 2 ) && ( V_94 != 4 ) && ( V_94 != 8 ) ) ) {
return 0 ;
}
return 1 ;
}
static unsigned long
F_29 ( struct V_1 * V_2 , unsigned long long V_93 )
{
int V_97 ;
T_3 V_59 ;
if ( F_28 ( V_93 , V_95 ,
V_96 ) ) {
V_97 = F_30 ( V_93 ) ;
V_2 -> V_98 = V_97 ;
F_11 ( V_2 , V_2 -> V_99 |
V_86 , V_97 ) ;
V_59 = F_18 ( V_2 , V_2 -> V_99 |
V_86 ) ;
if ( ( V_59 << 17 ) != V_97 ) {
F_9 ( V_100 , V_2 ,
L_3 ,
V_63 , V_97 , V_59 ) ;
}
V_93 = F_31 ( V_93 ) + V_101 ;
} else if ( F_28 ( V_93 , V_102 ,
V_103 ) ) {
unsigned int V_104 ;
if ( ( V_93 & 0x00ff800 ) == 0xff800 ) {
F_32 ( L_4 , V_63 ) ;
V_93 = - 1UL ;
}
V_97 = F_33 ( V_93 ) ;
V_2 -> V_98 = V_97 ;
F_11 ( V_2 , V_2 -> V_99 |
V_86 , V_97 ) ;
V_59 = F_18 ( V_2 , V_2 -> V_99 |
V_86 ) ;
V_104 = ( ( V_97 & 0x1FF ) << 7 ) |
( ( V_97 & 0x0FFFE0000 ) >> 17 ) ;
if ( V_59 != V_104 ) {
F_32 ( L_5
L_6 , V_63 , V_104 , V_59 ) ;
}
V_93 = F_31 ( V_93 ) + V_105 ;
} else if ( F_28 ( V_93 , V_106 ,
V_107 ) ) {
V_97 = F_34 ( V_93 ) ;
V_2 -> V_108 = V_97 ;
F_11 ( V_2 , V_2 -> V_109 |
V_86 , V_97 ) ;
V_59 = F_18 ( V_2 ,
V_2 -> V_109 | V_86 ) ;
if ( V_59 != V_97 ) {
F_32 ( L_7
L_8 , V_63 , V_97 , V_59 ) ;
}
V_93 = F_31 ( V_93 ) + V_110 ;
} else {
if ( ( V_111 ++ < 8 ) ||
( V_111 % 64 == 0 ) ) {
F_32 ( L_9 ,
V_63 , V_112 ) ;
}
V_93 = - 1UL ;
}
return V_93 ;
}
static int F_35 ( struct V_1 * V_2 ,
unsigned long long V_93 )
{
int V_97 ;
unsigned long long V_113 ;
V_113 = V_107 ;
if ( F_28 ( V_93 , V_95 ,
V_96 ) ) {
F_36 () ;
} else if ( F_28 ( V_93 , V_102 ,
V_103 ) ) {
return 1 ;
} else if ( F_28 ( V_93 , V_114 ,
V_115 ) ) {
return 1 ;
} else if ( F_28 ( V_93 , V_106 ,
V_113 ) ) {
V_97 = ( ( V_93 - V_106 ) >> 22 ) & 0x3f ;
if ( V_2 -> V_108 == V_97 )
return 1 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
T_4 V_3 , void * V_65 , int V_94 )
{
unsigned long V_66 ;
void T_1 * V_93 ;
int V_116 = 0 ;
T_4 V_117 ;
void T_1 * V_118 = NULL ;
unsigned long V_119 ;
unsigned long V_120 ;
F_14 ( & V_2 -> V_68 , V_66 ) ;
V_117 = F_29 ( V_2 , V_3 ) ;
if ( ( V_117 == - 1UL ) ||
( F_35 ( V_2 , V_3 + V_94 - 1 ) == 0 ) ) {
F_17 ( & V_2 -> V_68 , V_66 ) ;
F_32 ( V_121 L_10
L_11 , V_112 , V_3 ) ;
return - 1 ;
}
V_93 = F_1 ( V_2 , V_117 ) ;
if ( ! V_93 ) {
F_17 ( & V_2 -> V_68 , V_66 ) ;
V_119 = F_38 ( V_2 -> V_122 , 0 ) ;
V_120 = V_117 & V_123 ;
if ( V_120 != ( ( V_117 + V_94 - 1 ) & V_123 ) )
V_118 = F_39 ( V_119 + V_120 , V_124 * 2 ) ;
else
V_118 = F_39 ( V_119 + V_120 , V_124 ) ;
if ( V_118 == NULL ) {
* ( V_125 * ) V_65 = 0 ;
return - 1 ;
}
V_93 = V_118 ;
V_93 += V_117 & ( V_124 - 1 ) ;
F_14 ( & V_2 -> V_68 , V_66 ) ;
}
switch ( V_94 ) {
case 1 :
* ( V_125 * ) V_65 = F_40 ( V_93 ) ;
break;
case 2 :
* ( V_126 * ) V_65 = F_41 ( V_93 ) ;
break;
case 4 :
* ( T_3 * ) V_65 = F_7 ( V_93 ) ;
break;
case 8 :
* ( T_4 * ) V_65 = F_42 ( V_93 ) ;
break;
default:
V_116 = - 1 ;
break;
}
F_17 ( & V_2 -> V_68 , V_66 ) ;
if ( V_118 )
F_43 ( V_118 ) ;
return V_116 ;
}
static int
F_44 ( struct V_1 * V_2 , T_4 V_3 ,
void * V_65 , int V_94 )
{
unsigned long V_66 ;
void T_1 * V_93 ;
int V_116 = 0 ;
T_4 V_117 ;
void T_1 * V_118 = NULL ;
unsigned long V_119 ;
unsigned long V_120 ;
F_14 ( & V_2 -> V_68 , V_66 ) ;
V_117 = F_29 ( V_2 , V_3 ) ;
if ( ( V_117 == - 1UL ) ||
( F_35 ( V_2 , V_3 + V_94 - 1 ) == 0 ) ) {
F_17 ( & V_2 -> V_68 , V_66 ) ;
F_32 ( V_121 L_10
L_11 , V_112 , V_3 ) ;
return - 1 ;
}
V_93 = F_1 ( V_2 , V_117 ) ;
if ( ! V_93 ) {
F_17 ( & V_2 -> V_68 , V_66 ) ;
V_119 = F_38 ( V_2 -> V_122 , 0 ) ;
V_120 = V_117 & V_123 ;
if ( V_120 != ( ( V_117 + V_94 - 1 ) & V_123 ) )
V_118 = F_39 ( V_119 + V_120 , V_124 * 2 ) ;
else
V_118 = F_39 ( V_119 + V_120 , V_124 ) ;
if ( V_118 == NULL )
return - 1 ;
V_93 = V_118 ;
V_93 += V_117 & ( V_124 - 1 ) ;
F_14 ( & V_2 -> V_68 , V_66 ) ;
}
switch ( V_94 ) {
case 1 :
F_45 ( * ( V_125 * ) V_65 , V_93 ) ;
break;
case 2 :
F_46 ( * ( V_126 * ) V_65 , V_93 ) ;
break;
case 4 :
F_6 ( * ( T_3 * ) V_65 , V_93 ) ;
break;
case 8 :
F_47 ( * ( T_4 * ) V_65 , V_93 ) ;
break;
default:
V_116 = - 1 ;
break;
}
F_17 ( & V_2 -> V_68 , V_66 ) ;
if ( V_118 )
F_43 ( V_118 ) ;
return V_116 ;
}
static unsigned long
F_48 ( unsigned long V_93 )
{
int V_69 ;
unsigned long V_127 , V_128 , V_129 ;
if ( ! V_58 )
F_2 () ;
V_129 = V_130 ;
V_127 = V_93 & 0xfff00000 ;
V_128 = V_93 & 0x000fffff ;
for ( V_69 = 0 ; V_69 < V_131 ; V_69 ++ ) {
if ( V_132 [ V_69 ] == V_127 ) {
V_129 = V_69 << 20 ;
break;
}
}
if ( V_129 == V_130 )
return V_129 ;
else
return V_129 + V_128 ;
}
static int
F_49 ( struct V_1 * V_2 )
{
int V_69 ;
int V_70 = 0 , V_71 = 0 ;
while ( ! V_70 ) {
V_70 = F_18 ( V_2 , F_19 ( V_133 ) ) ;
if ( V_70 == 1 )
break;
if ( V_71 >= V_134 )
return - 1 ;
V_71 ++ ;
if ( ! F_20 () )
F_21 () ;
else {
for ( V_69 = 0 ; V_69 < 20 ; V_69 ++ )
F_22 () ;
}
}
F_11 ( V_2 , V_135 , V_136 ) ;
return 0 ;
}
static void
F_50 ( struct V_1 * V_2 )
{
F_18 ( V_2 , F_19 ( V_137 ) ) ;
}
static int
F_51 ( struct V_1 * V_2 )
{
long V_71 = 0 ;
long V_70 = 0 ;
while ( V_70 == 0 ) {
V_70 = F_18 ( V_2 , V_138 ) ;
V_70 &= 2 ;
V_71 ++ ;
if ( V_71 >= V_139 ) {
F_32 ( L_12 ,
V_112 ) ;
return - 1 ;
}
}
return 0 ;
}
static int
F_52 ( struct V_1 * V_2 , int V_93 , int * V_140 )
{
F_11 ( V_2 , V_141 , V_93 ) ;
F_11 ( V_2 , V_142 , 0 ) ;
F_11 ( V_2 , V_143 , 3 ) ;
F_11 ( V_2 , V_144 , 0xb ) ;
if ( F_51 ( V_2 ) ) {
F_32 ( L_13 , V_112 ) ;
return - 1 ;
}
F_11 ( V_2 , V_142 , 0 ) ;
F_53 ( 10 ) ;
F_11 ( V_2 , V_143 , 0 ) ;
* V_140 = F_18 ( V_2 , V_145 ) ;
return 0 ;
}
static int
F_54 ( struct V_1 * V_2 , int V_93 , int * V_140 )
{
int V_116 , V_146 = 0 ;
while ( ( F_49 ( V_2 ) != 0 ) && ( V_146 < 50000 ) ) {
F_53 ( 100 ) ;
V_146 ++ ;
}
if ( V_146 >= 50000 ) {
F_32 ( L_14 , V_112 ) ;
return - 1 ;
}
V_116 = F_52 ( V_2 , V_93 , V_140 ) ;
F_50 ( V_2 ) ;
return V_116 ;
}
static int
F_55 ( struct V_1 * V_2 , int V_147 )
{
int V_93 , V_148 ;
int V_69 ;
struct V_149 * V_150 ;
unsigned long V_3 ;
unsigned V_128 , V_151 ;
struct V_149 {
long V_93 ;
long V_65 ;
};
F_49 ( V_2 ) ;
F_11 ( V_2 , V_152 + 0x10 , 0x0 ) ;
F_11 ( V_2 , V_152 + 0x14 , 0x0 ) ;
F_11 ( V_2 , V_152 + 0x18 , 0x0 ) ;
F_11 ( V_2 , V_152 + 0x1c , 0x0 ) ;
F_11 ( V_2 , V_152 + 0x20 , 0x0 ) ;
F_11 ( V_2 , V_152 + 0x24 , 0x0 ) ;
F_11 ( V_2 , V_153 + 0x40 , 0xff ) ;
F_11 ( V_2 , V_153 + 0x70000 , 0x00 ) ;
F_11 ( V_2 , V_153 + 0x80000 , 0x00 ) ;
F_11 ( V_2 , V_153 + 0x90000 , 0x00 ) ;
F_11 ( V_2 , V_153 + 0xa0000 , 0x00 ) ;
F_11 ( V_2 , V_153 + 0xb0000 , 0x00 ) ;
V_148 = F_18 ( V_2 , V_154 + 0x1000 ) ;
F_11 ( V_2 , V_154 + 0x1000 , V_148 & ( ~ ( 0x1 ) ) ) ;
F_11 ( V_2 , V_155 + 0x1300 , 0x1 ) ;
F_11 ( V_2 , V_156 + 0x0 , 0x0 ) ;
F_11 ( V_2 , V_156 + 0x8 , 0x0 ) ;
F_11 ( V_2 , V_156 + 0x10 , 0x0 ) ;
F_11 ( V_2 , V_156 + 0x18 , 0x0 ) ;
F_11 ( V_2 , V_156 + 0x100 , 0x0 ) ;
F_11 ( V_2 , V_156 + 0x200 , 0x0 ) ;
F_11 ( V_2 , V_157 + 0x3c , 1 ) ;
F_11 ( V_2 , V_158 + 0x3c , 1 ) ;
F_11 ( V_2 , V_159 + 0x3c , 1 ) ;
F_11 ( V_2 , V_160 + 0x3c , 1 ) ;
F_11 ( V_2 , V_161 + 0x3c , 1 ) ;
F_56 ( 5 ) ;
if ( F_57 ( V_162 , & V_2 -> V_163 ) )
F_11 ( V_2 , V_164 , 0xfeffffff ) ;
else
F_11 ( V_2 , V_164 , 0xffffffff ) ;
F_50 ( V_2 ) ;
if ( F_54 ( V_2 , 0 , & V_151 ) != 0 || V_151 != 0xcafecafeUL ||
F_54 ( V_2 , 4 , & V_151 ) != 0 ) {
F_9 ( V_100 , V_2 ,
L_15 , V_151 ) ;
return - 1 ;
}
V_128 = V_151 & 0xffffU ;
V_151 = ( V_151 >> 16 ) & 0xffffU ;
if ( V_151 >= 1024 ) {
F_9 ( V_100 , V_2 ,
L_16 ,
V_112 , V_63 , V_151 ) ;
return - 1 ;
}
F_9 ( V_62 , V_2 ,
L_17 , V_112 , V_151 ) ;
V_150 = F_58 ( V_151 * sizeof( struct V_149 ) , V_165 ) ;
if ( V_150 == NULL ) {
F_9 ( V_100 , V_2 ,
L_18 , V_112 ) ;
return - 1 ;
}
for ( V_69 = 0 ; V_69 < V_151 ; V_69 ++ ) {
if ( F_54 ( V_2 , 8 * V_69 + 4 * V_128 , & V_148 ) != 0 ||
F_54 ( V_2 , 8 * V_69 + 4 * V_128 + 4 , & V_93 ) !=
0 ) {
F_59 ( V_150 ) ;
return - 1 ;
}
V_150 [ V_69 ] . V_93 = V_93 ;
V_150 [ V_69 ] . V_65 = V_148 ;
}
for ( V_69 = 0 ; V_69 < V_151 ; V_69 ++ ) {
V_3 = F_48 ( ( unsigned long ) V_150 [ V_69 ] . V_93 ) +
V_86 ;
if ( V_3 & 0x1 ) {
F_8 ( F_9 ( V_100 , V_2 ,
L_19 , V_3 ) ) ;
continue;
}
if ( V_3 == F_60 ( 0x1fc ) )
continue;
if ( V_3 == ( V_166 + 0xbc ) )
continue;
if ( V_3 == ( V_166 + 0xc8 ) )
continue;
if ( V_3 == F_19 ( V_167 ) )
continue;
if ( V_3 == F_19 ( V_168 ) )
continue;
if ( ( V_3 & 0x0ff00000 ) == V_169 )
continue;
if ( ( V_3 & 0x0ff00000 ) == V_170 )
continue;
if ( V_3 == V_130 ) {
F_9 ( V_100 , V_2 ,
L_20 ,
V_112 , V_150 [ V_69 ] . V_93 ) ;
continue;
}
F_11 ( V_2 , V_3 , V_150 [ V_69 ] . V_65 ) ;
if ( V_3 == V_164 )
F_56 ( 1000 ) ;
F_56 ( 1 ) ;
}
F_59 ( V_150 ) ;
F_11 ( V_2 , V_171 + 0xec , 0x1e ) ;
F_11 ( V_2 , V_171 + 0x4c , 8 ) ;
F_11 ( V_2 , V_172 + 0x4c , 8 ) ;
F_11 ( V_2 , V_157 + 0x8 , 0 ) ;
F_11 ( V_2 , V_157 + 0xc , 0 ) ;
F_11 ( V_2 , V_158 + 0x8 , 0 ) ;
F_11 ( V_2 , V_158 + 0xc , 0 ) ;
F_11 ( V_2 , V_159 + 0x8 , 0 ) ;
F_11 ( V_2 , V_159 + 0xc , 0 ) ;
F_11 ( V_2 , V_160 + 0x8 , 0 ) ;
F_11 ( V_2 , V_160 + 0xc , 0 ) ;
return 0 ;
}
static int
F_61 ( struct V_1 * V_2 , T_5 V_173 )
{
int V_69 , V_174 = 0 ;
long V_94 = 0 ;
long V_175 , V_176 ;
T_4 V_65 ;
T_3 V_177 , V_178 ;
V_175 = V_176 = V_2 -> V_179 . V_180 ;
V_94 = ( V_173 - V_175 ) / 8 ;
F_8 ( F_32 ( L_21 ,
V_2 -> V_181 , V_63 , V_175 , V_173 ) ) ;
for ( V_69 = 0 ; V_69 < V_94 ; V_69 ++ ) {
if ( ( F_54 ( V_2 , V_175 , ( int * ) & V_178 ) ) ||
( F_54 ( V_2 , V_175 + 4 ,
( int * ) & V_177 ) ) ) {
V_174 = - 1 ;
goto V_182;
}
V_65 = ( ( T_4 ) V_177 << 32 ) | V_178 ;
V_174 = F_62 ( V_2 , V_176 , & V_65 , 8 ) ;
if ( V_174 )
goto V_182;
V_175 += 8 ;
V_176 += 8 ;
if ( V_69 % 0x1000 == 0 )
F_56 ( 1 ) ;
}
F_53 ( 100 ) ;
F_63 ( & V_2 -> V_68 ) ;
F_11 ( V_2 , V_157 + 0x18 , 0x1020 ) ;
F_11 ( V_2 , V_164 , 0x80001e ) ;
F_64 ( & V_2 -> V_68 ) ;
V_182:
return V_174 ;
}
static int F_65 ( struct V_1 * V_2 , T_5 V_173 )
{
T_3 V_183 ;
F_11 ( V_2 , V_184 , 0 ) ;
if ( F_55 ( V_2 , 0 ) != V_185 ) {
F_32 ( V_100 L_22 ,
V_63 ) ;
return V_186 ;
}
F_53 ( 500 ) ;
V_183 = F_18 ( V_2 , V_164 ) ;
V_183 &= ~ ( 1 << 28 ) ;
F_11 ( V_2 , V_164 , V_183 ) ;
if ( F_61 ( V_2 , V_173 ) ) {
F_32 ( L_23 , V_63 ) ;
return V_186 ;
}
return V_185 ;
}
int
F_66 ( struct V_1 * V_2 ,
T_4 V_3 , void * V_65 , int V_94 )
{
int V_69 , V_187 = 0 , V_188 , V_117 , V_189 , V_190 , V_191 [ 2 ] , V_192 [ 2 ] ;
int V_193 ;
T_5 V_194 ;
T_6 V_195 , V_148 , V_196 , V_197 [ 2 ] = { 0 , 0 } ;
if ( V_3 >= V_106 && V_3 <= V_107 )
V_196 = V_198 ;
else {
V_196 = V_170 ;
if ( F_27 ( V_2 , V_3 , V_94 ) == 0 )
return F_37 ( V_2 ,
V_3 , V_65 , V_94 ) ;
}
V_195 = V_3 & 0xfffffff0 ;
V_192 [ 0 ] = V_3 & 0xf ;
V_191 [ 0 ] = ( V_94 < ( 16 - V_192 [ 0 ] ) ) ? V_94 : ( 16 - V_192 [ 0 ] ) ;
V_193 = 4 ;
V_190 = ( ( V_192 [ 0 ] + V_94 - 1 ) >> V_193 ) + 1 ;
V_192 [ 1 ] = 0 ;
V_191 [ 1 ] = V_94 - V_191 [ 0 ] ;
for ( V_69 = 0 ; V_69 < V_190 ; V_69 ++ ) {
V_194 = V_195 + ( V_69 << V_193 ) ;
F_11 ( V_2 , V_196 + V_199 , V_194 ) ;
V_194 = 0 ;
F_11 ( V_2 , V_196 + V_200 , V_194 ) ;
V_194 = V_201 ;
F_11 ( V_2 , V_196 + V_202 , V_194 ) ;
V_194 = V_203 | V_201 ;
F_11 ( V_2 , V_196 + V_202 , V_194 ) ;
for ( V_187 = 0 ; V_187 < V_204 ; V_187 ++ ) {
V_194 = F_18 ( V_2 , V_196 + V_202 ) ;
if ( ( V_194 & V_205 ) == 0 )
break;
}
if ( V_187 >= V_204 ) {
if ( F_67 () )
F_9 ( V_121 , V_2 ,
L_24 ) ;
break;
}
V_117 = V_192 [ V_69 ] >> 2 ;
V_189 = ( V_192 [ V_69 ] + V_191 [ V_69 ] - 1 ) >> 2 ;
for ( V_188 = V_117 ; V_188 <= V_189 ; V_188 ++ ) {
V_194 = F_18 ( V_2 ,
V_196 + F_68 ( V_188 ) ) ;
V_197 [ V_69 ] |= ( ( T_6 ) V_194 << ( 32 * ( V_188 & 1 ) ) ) ;
}
}
if ( V_187 >= V_204 )
return - 1 ;
if ( ( V_192 [ 0 ] & 7 ) == 0 ) {
V_148 = V_197 [ 0 ] ;
} else {
V_148 = ( ( V_197 [ 0 ] >> ( V_192 [ 0 ] * 8 ) ) & ( ~ ( ~ 0ULL << ( V_191 [ 0 ] * 8 ) ) ) ) |
( ( V_197 [ 1 ] & ( ~ ( ~ 0ULL << ( V_191 [ 1 ] * 8 ) ) ) ) << ( V_191 [ 0 ] * 8 ) ) ;
}
switch ( V_94 ) {
case 1 :
* ( V_206 * ) V_65 = V_148 ;
break;
case 2 :
* ( V_207 * ) V_65 = V_148 ;
break;
case 4 :
* ( T_5 * ) V_65 = V_148 ;
break;
case 8 :
* ( T_6 * ) V_65 = V_148 ;
break;
}
return 0 ;
}
int
F_62 ( struct V_1 * V_2 ,
T_4 V_3 , void * V_65 , int V_94 )
{
int V_69 , V_187 , V_116 = 0 , V_190 , V_191 [ 2 ] , V_192 ;
int V_208 , V_193 , V_209 ;
T_5 V_194 ;
T_6 V_195 , V_196 , V_210 , V_197 [ 2 ] = { 0 , 0 } ;
if ( V_3 >= V_106 && V_3 <= V_107 )
V_196 = V_198 ;
else {
V_196 = V_170 ;
if ( F_27 ( V_2 , V_3 , V_94 ) == 0 )
return F_44 ( V_2 ,
V_3 , V_65 , V_94 ) ;
}
V_192 = V_3 & 0x7 ;
V_191 [ 0 ] = ( V_94 < ( 8 - V_192 ) ) ? V_94 : ( 8 - V_192 ) ;
V_191 [ 1 ] = V_94 - V_191 [ 0 ] ;
V_195 = V_3 & 0xfffffff0 ;
V_190 = ( ( ( V_3 & 0xf ) + V_94 - 1 ) >> 4 ) + 1 ;
V_193 = 4 ;
V_208 = 2 ;
V_209 = ( V_3 & 0xf ) / 8 ;
for ( V_69 = 0 ; V_69 < V_190 ; V_69 ++ ) {
if ( F_66 ( V_2 , V_195 +
( V_69 << V_193 ) , & V_197 [ V_69 * V_208 ] , 8 ) )
return - 1 ;
}
switch ( V_94 ) {
case 1 :
V_210 = * ( ( V_206 * ) V_65 ) ;
break;
case 2 :
V_210 = * ( ( V_207 * ) V_65 ) ;
break;
case 4 :
V_210 = * ( ( T_5 * ) V_65 ) ;
break;
case 8 :
default:
V_210 = * ( ( T_6 * ) V_65 ) ;
break;
}
if ( V_191 [ 0 ] == 8 )
V_197 [ V_209 ] = V_210 ;
else {
V_197 [ V_209 ] &=
~ ( ( ~ ( ~ 0ULL << ( V_191 [ 0 ] * 8 ) ) ) << ( V_192 * 8 ) ) ;
V_197 [ V_209 ] |= V_210 << ( V_192 * 8 ) ;
}
if ( V_191 [ 1 ] != 0 ) {
V_197 [ V_209 + 1 ] &= ~ ( ~ 0ULL << ( V_191 [ 1 ] * 8 ) ) ;
V_197 [ V_209 + 1 ] |= V_210 >> ( V_191 [ 0 ] * 8 ) ;
}
for ( V_69 = 0 ; V_69 < V_190 ; V_69 ++ ) {
V_194 = V_195 + ( V_69 << V_193 ) ;
F_11 ( V_2 , V_196 + V_199 , V_194 ) ;
V_194 = 0 ;
F_11 ( V_2 , V_196 + V_200 , V_194 ) ;
V_194 = V_197 [ V_69 * V_208 ] & 0xffffffff ;
F_11 ( V_2 , V_196 + V_211 , V_194 ) ;
V_194 = ( V_197 [ V_69 * V_208 ] >> 32 ) & 0xffffffff ;
F_11 ( V_2 , V_196 + V_212 , V_194 ) ;
V_194 = V_197 [ V_69 * V_208 + 1 ] & 0xffffffff ;
F_11 ( V_2 , V_196 + V_213 ,
V_194 ) ;
V_194 = ( V_197 [ V_69 * V_208 + 1 ] >> 32 ) & 0xffffffff ;
F_11 ( V_2 , V_196 + V_214 ,
V_194 ) ;
V_194 = V_201 | V_215 ;
F_11 ( V_2 , V_196 + V_202 , V_194 ) ;
V_194 = V_203 | V_201 | V_215 ;
F_11 ( V_2 , V_196 + V_202 , V_194 ) ;
for ( V_187 = 0 ; V_187 < V_204 ; V_187 ++ ) {
V_194 = F_18 ( V_2 , V_196 + V_202 ) ;
if ( ( V_194 & V_205 ) == 0 )
break;
}
if ( V_187 >= V_204 ) {
if ( F_67 () )
F_9 ( V_121 , V_2 ,
L_25 ) ;
V_116 = - 1 ;
break;
}
}
return V_116 ;
}
static int F_69 ( struct V_1 * V_2 , int V_216 )
{
T_3 V_148 = 0 ;
int V_217 = 60 ;
if ( ! V_216 ) {
do {
V_148 = F_18 ( V_2 , V_184 ) ;
if ( ( V_148 == V_218 ) ||
( V_148 == V_219 ) )
return 0 ;
F_70 ( V_220 ) ;
F_71 ( 500 ) ;
} while ( -- V_217 );
if ( ! V_217 ) {
V_216 = F_18 ( V_2 ,
V_221 ) ;
F_32 ( V_100 L_26
L_27 , V_63 , V_216 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_72 ( struct V_1 * V_2 )
{
T_5 V_222 = 0 ;
int V_146 = 0 ;
F_63 ( & V_2 -> V_68 ) ;
V_222 = F_18 ( V_2 , V_223 ) ;
F_64 ( & V_2 -> V_68 ) ;
while ( ( V_222 != V_224 ) && ( V_146 < 30000 ) ) {
F_53 ( 100 ) ;
F_63 ( & V_2 -> V_68 ) ;
V_222 = F_18 ( V_2 , V_223 ) ;
F_64 ( & V_2 -> V_68 ) ;
V_146 ++ ;
}
if ( V_146 >= 30000 ) {
F_8 ( F_9 ( V_62 , V_2 ,
L_28 , V_222 ) ) ;
return V_186 ;
}
return V_185 ;
}
void
F_73 ( struct V_1 * V_2 )
{
T_5 V_225 ;
V_225 = F_18 ( V_2 , V_226 ) ;
V_225 |= ( 1 << ( V_2 -> V_75 * 4 ) ) ;
F_11 ( V_2 , V_226 , V_225 ) ;
}
void
F_74 ( struct V_1 * V_2 )
{
T_5 V_225 ;
V_225 = F_18 ( V_2 , V_226 ) ;
V_225 &= ~ ( 1 << ( V_2 -> V_75 * 4 ) ) ;
F_11 ( V_2 , V_226 , V_225 ) ;
}
static inline int
F_75 ( struct V_1 * V_2 )
{
T_5 V_227 , V_225 ;
int V_174 ;
V_225 = F_18 ( V_2 , V_226 ) ;
V_227 = F_18 ( V_2 , V_228 ) ;
V_174 = V_227 & ( 1 << ( V_2 -> V_75 * 4 ) ) ;
if ( ( F_57 ( V_229 , & V_2 -> V_66 ) ) && V_225 )
V_174 = 1 ;
return V_174 ;
}
static inline void
F_76 ( struct V_1 * V_2 )
{
T_5 V_227 ;
V_227 = F_18 ( V_2 , V_228 ) ;
V_227 |= ( 1 << ( V_2 -> V_75 * 4 ) ) ;
F_11 ( V_2 , V_228 , V_227 ) ;
}
static inline void
F_77 ( struct V_1 * V_2 )
{
T_5 V_227 ;
V_227 = F_18 ( V_2 , V_228 ) ;
V_227 &= ~ ( 1 << ( V_2 -> V_75 * 4 ) ) ;
F_11 ( V_2 , V_228 , V_227 ) ;
}
static inline void
F_78 ( struct V_1 * V_2 )
{
T_5 V_230 ;
V_230 = F_18 ( V_2 , V_228 ) ;
V_230 |= ( 2 << ( V_2 -> V_75 * 4 ) ) ;
F_11 ( V_2 , V_228 , V_230 ) ;
}
static int
F_79 ( struct V_1 * V_2 , T_5 V_173 )
{
int V_231 ;
V_207 V_232 ;
F_11 ( V_2 , V_233 , 0x55555555 ) ;
F_11 ( V_2 , V_184 , 0 ) ;
F_11 ( V_2 , V_223 , 0 ) ;
F_11 ( V_2 , V_234 , 0 ) ;
F_11 ( V_2 , V_235 , 0 ) ;
if ( F_65 ( V_2 , V_173 ) != V_185 ) {
F_32 ( L_29 , V_63 ) ;
return V_186 ;
}
if ( F_69 ( V_2 , 0 ) != V_185 ) {
F_32 ( L_30 , V_63 ) ;
return V_186 ;
}
V_231 = F_80 ( V_2 -> V_122 , V_236 ) ;
F_81 ( V_2 -> V_122 , V_231 + V_237 , & V_232 ) ;
V_2 -> V_238 = ( V_232 >> 4 ) & 0x3f ;
return F_72 ( V_2 ) ;
}
static int
F_82 ( struct V_1 * V_2 )
{
int V_174 = V_186 ;
F_9 ( V_62 , V_2 ,
L_31 ) ;
V_174 = F_83 ( V_2 ) ;
if ( V_174 != V_185 )
return V_174 ;
F_9 ( V_62 , V_2 ,
L_32 ) ;
V_174 = F_79 ( V_2 , V_2 -> V_179 . V_239 ) ;
if ( V_174 != V_185 ) {
F_9 ( V_121 , V_2 , L_33
L_34 ) ;
return V_174 ;
}
return V_174 ;
}
static void F_84 ( struct V_1 * V_2 )
{
if ( F_49 ( V_2 ) ) {
F_85 ( & V_2 -> V_122 -> V_240 , L_35 ) ;
}
F_50 ( V_2 ) ;
}
static int
F_86 ( struct V_1 * V_2 )
{
int V_174 = V_186 ;
int V_69 , V_71 ;
T_5 V_241 , V_242 ;
int V_243 = 0 , V_244 = 1 ;
V_243 = F_75 ( V_2 ) ;
V_241 = F_18 ( V_2 , V_245 ) ;
for ( V_69 = 0 ; V_69 < 10 ; V_69 ++ ) {
V_71 = F_87 ( 200 ) ;
if ( V_71 ) {
F_11 ( V_2 , V_246 ,
V_247 ) ;
return V_174 ;
}
V_242 = F_18 ( V_2 , V_245 ) ;
if ( V_242 != V_241 )
V_244 = 0 ;
}
if ( V_243 ) {
if ( V_244 )
F_84 ( V_2 ) ;
goto V_248;
} else {
if ( V_244 ) {
F_84 ( V_2 ) ;
goto V_248;
} else {
V_174 = V_185 ;
goto V_249;
}
}
V_248:
F_9 ( V_62 , V_2 , L_36 ) ;
F_11 ( V_2 , V_246 , V_250 ) ;
F_11 ( V_2 , V_251 , V_252 ) ;
F_24 ( V_2 ) ;
V_174 = F_82 ( V_2 ) ;
F_23 ( V_2 ) ;
if ( V_174 != V_185 ) {
F_9 ( V_62 , V_2 , L_37 ) ;
F_74 ( V_2 ) ;
F_11 ( V_2 , V_246 , V_247 ) ;
return V_174 ;
}
V_249:
F_9 ( V_62 , V_2 , L_38 ) ;
F_11 ( V_2 , V_246 , V_253 ) ;
return V_174 ;
}
static void
F_88 ( struct V_1 * V_2 )
{
T_5 V_254 , V_227 , V_225 ;
unsigned long V_255 ;
F_9 ( V_62 , V_2 ,
L_39 ) ;
if ( F_89 ( V_256 , & V_2 -> V_66 ) ) {
F_24 ( V_2 ) ;
V_2 -> V_257 -> V_258 ( V_2 ) ;
F_23 ( V_2 ) ;
}
F_76 ( V_2 ) ;
V_255 = V_259 + ( V_2 -> V_260 * V_261 ) ;
V_227 = F_18 ( V_2 , V_228 ) ;
V_225 = F_18 ( V_2 , V_226 ) ;
F_9 ( V_62 , V_2 ,
L_40 ,
V_63 , V_2 -> V_181 , V_227 , V_225 ) ;
while ( V_227 != V_225 ) {
if ( F_90 ( V_259 , V_255 ) ) {
F_32 ( L_41 , V_112 ) ;
break;
}
F_24 ( V_2 ) ;
F_56 ( 1000 ) ;
F_23 ( V_2 ) ;
V_227 = F_18 ( V_2 , V_228 ) ;
V_225 = F_18 ( V_2 , V_226 ) ;
}
V_254 = F_18 ( V_2 , V_246 ) ;
F_9 ( V_62 , V_2 , L_42 , V_254 ,
V_254 < V_262 ? V_263 [ V_254 ] : L_43 ) ;
if ( V_254 != V_250 ) {
F_9 ( V_62 , V_2 , L_44 ) ;
F_11 ( V_2 , V_246 , V_264 ) ;
}
}
void
F_91 ( struct V_1 * V_2 )
{
F_23 ( V_2 ) ;
F_78 ( V_2 ) ;
F_24 ( V_2 ) ;
}
int F_92 ( struct V_1 * V_2 )
{
T_5 V_254 ;
int V_174 = V_185 ;
unsigned long V_265 ;
if ( ! F_57 ( V_266 , & V_2 -> V_66 ) ) {
F_23 ( V_2 ) ;
F_73 ( V_2 ) ;
F_24 ( V_2 ) ;
}
V_254 = F_18 ( V_2 , V_246 ) ;
F_9 ( V_62 , V_2 , L_45 , V_254 ,
V_254 < V_262 ? V_263 [ V_254 ] : L_43 ) ;
V_265 = V_259 + ( V_2 -> V_267 * V_261 ) ;
F_23 ( V_2 ) ;
while ( 1 ) {
if ( F_90 ( V_259 , V_265 ) ) {
F_9 ( V_100 , V_2 , L_46 ) ;
F_11 ( V_2 , V_246 ,
V_247 ) ;
}
V_254 = F_18 ( V_2 , V_246 ) ;
F_9 ( V_62 , V_2 ,
L_47 , V_254 ,
V_254 < V_262 ? V_263 [ V_254 ] : L_43 ) ;
switch ( V_254 ) {
case V_253 :
goto exit;
case V_264 :
V_174 = F_86 ( V_2 ) ;
goto exit;
case V_250 :
F_24 ( V_2 ) ;
F_56 ( 1000 ) ;
F_23 ( V_2 ) ;
break;
case V_268 :
if ( ! V_269 ) {
F_88 ( V_2 ) ;
V_265 = V_259 +
( V_2 -> V_267 * V_261 ) ;
} else {
F_24 ( V_2 ) ;
F_56 ( 1000 ) ;
F_23 ( V_2 ) ;
}
break;
case V_270 :
F_91 ( V_2 ) ;
break;
case V_271 :
F_24 ( V_2 ) ;
F_56 ( 1000 ) ;
F_23 ( V_2 ) ;
break;
case V_247 :
F_24 ( V_2 ) ;
F_93 ( V_2 ) ;
V_174 = V_186 ;
F_23 ( V_2 ) ;
goto exit;
default:
F_24 ( V_2 ) ;
F_93 ( V_2 ) ;
V_174 = V_186 ;
F_23 ( V_2 ) ;
goto exit;
}
}
exit:
F_24 ( V_2 ) ;
return V_174 ;
}
int F_94 ( struct V_1 * V_2 )
{
int V_272 ;
F_6 ( 0 , & V_2 -> V_273 -> V_274 ) ;
F_7 ( & V_2 -> V_273 -> V_274 ) ;
V_272 = F_92 ( V_2 ) ;
if ( V_272 == V_185 && ! F_57 ( V_266 , & V_2 -> V_66 ) )
V_272 = F_95 ( V_2 ) ;
return V_272 ;
}
static inline T_5
F_96 ( struct V_275 * V_179 , T_5 V_276 )
{
return V_179 -> V_277 | V_276 ;
}
static inline T_5
F_97 ( struct V_275 * V_179 , T_5 V_276 )
{
return V_179 -> V_278 | V_276 ;
}
static T_5 *
F_98 ( struct V_1 * V_2 , T_5 * V_279 ,
T_5 V_276 , T_5 V_280 )
{
T_5 V_69 ;
T_5 V_148 ;
int V_146 = 0 ;
while ( ( F_49 ( V_2 ) != 0 ) && ( V_146 < 50000 ) ) {
F_53 ( 100 ) ;
F_99 () ;
V_146 ++ ;
}
if ( V_146 >= 50000 ) {
F_9 ( V_100 , V_2 , L_48 ) ;
return V_279 ;
}
for ( V_69 = 0 ; V_69 < V_280 / 4 ; V_69 ++ , V_276 += 4 ) {
if ( F_52 ( V_2 , V_276 , & V_148 ) ) {
F_9 ( V_100 , V_2 ,
L_49 ) ;
goto V_281;
}
V_279 [ V_69 ] = F_100 ( V_148 ) ;
}
V_281:
F_50 ( V_2 ) ;
return V_279 ;
}
static V_206 *
F_101 ( struct V_1 * V_2 , V_206 * V_150 ,
T_5 V_128 , T_5 V_280 )
{
F_98 ( V_2 , ( T_5 * ) V_150 , V_128 , V_280 ) ;
return V_150 ;
}
static int
F_102 ( struct V_1 * V_2 , T_5 * V_117 )
{
const char * V_282 , * V_283 [] = { L_50 , L_51 } ;
V_282 = V_283 [ 0 ] ;
* V_117 = V_284 ;
F_8 ( F_9 ( V_62 , V_2 , L_52 , V_282 , * V_117 ) ) ;
return V_185 ;
}
static void
F_103 ( struct V_1 * V_2 , T_5 V_285 )
{
const char * V_282 , * V_283 [] = { L_50 , L_53 } ;
V_207 * V_286 ;
V_207 V_287 , V_288 ;
T_5 V_117 ;
struct V_289 * V_290 ;
struct V_291 * V_292 ;
struct V_275 * V_179 = & V_2 -> V_179 ;
V_179 -> V_293 = V_285 ;
V_286 = ( V_207 * ) V_2 -> V_294 ;
V_290 = (struct V_289 * ) V_2 -> V_294 ;
V_292 = (struct V_291 * ) & V_290 [ 1 ] ;
F_101 ( V_2 , ( V_206 * ) V_2 -> V_294 ,
V_285 << 2 , V_295 ) ;
if ( * V_286 == F_104 ( 0xffff ) )
goto V_296;
if ( V_290 -> V_297 != F_104 ( 1 ) ) {
F_8 ( F_9 ( V_62 , V_2 , L_54
L_55 ,
F_105 ( V_290 -> V_297 ) , F_105 ( V_290 -> V_280 ) ,
F_105 ( V_290 -> V_298 ) ) ) ;
goto V_296;
}
V_287 = ( sizeof( struct V_289 ) + F_105 ( V_290 -> V_280 ) ) >> 1 ;
for ( V_288 = 0 ; V_287 ; V_287 -- )
V_288 += F_105 ( * V_286 ++ ) ;
if ( V_288 ) {
F_8 ( F_9 ( V_62 , V_2 , L_56
L_55 ,
F_105 ( V_290 -> V_297 ) , F_105 ( V_290 -> V_280 ) ,
V_288 ) ) ;
goto V_296;
}
V_282 = V_283 [ 1 ] ;
V_287 = F_105 ( V_290 -> V_280 ) / sizeof( struct V_291 ) ;
for ( ; V_287 ; V_287 -- , V_292 ++ ) {
V_117 = F_106 ( V_292 -> V_117 ) >> 2 ;
F_107 ( F_9 ( V_299 , V_2 , L_57
L_58 , F_106 ( V_292 -> V_300 ) , V_117 ,
F_106 ( V_292 -> V_189 ) >> 2 , F_106 ( V_292 -> V_94 ) ) ) ;
switch ( F_106 ( V_292 -> V_300 ) & 0xff ) {
case V_301 :
V_179 -> V_302 = V_117 ;
break;
case V_303 :
V_179 -> V_304 = V_117 ;
break;
case V_305 :
case V_306 :
V_179 -> V_239 = V_117 ;
break;
case V_307 :
V_179 -> V_180 = V_117 ;
break;
case V_308 :
V_179 -> V_309 = V_117 ;
break;
case V_310 :
V_179 -> V_311 = V_117 ;
V_179 -> V_312 = F_106 ( V_292 -> V_94 ) ;
break;
}
}
goto V_70;
V_296:
V_282 = V_283 [ 0 ] ;
V_179 -> V_302 = V_313 ;
V_179 -> V_304 = V_314 ;
V_179 -> V_180 = V_315 ;
V_179 -> V_239 = V_316 ;
V_179 -> V_311 = V_317 ;
V_179 -> V_312 = V_318 ;
V_70:
F_8 ( F_9 ( V_62 , V_2 , L_59
L_60 , V_282 , V_179 -> V_293 ,
V_179 -> V_302 , V_179 -> V_304 , V_179 -> V_180 ,
V_179 -> V_239 ) ) ;
}
static void
F_108 ( struct V_1 * V_2 )
{
#define F_109 0x1000
#define F_110 0x8000
#define F_111 0x10000
const char * V_282 , * V_283 [] = { L_61 , L_62 } ;
V_207 V_287 , V_288 ;
V_207 * V_286 ;
struct V_319 * V_320 ;
V_207 V_321 = 0 ;
V_207 V_322 = 0 ;
struct V_275 * V_179 = & V_2 -> V_179 ;
V_179 -> V_277 = V_323 ;
V_179 -> V_278 = V_324 ;
V_286 = ( V_207 * ) V_2 -> V_294 ;
V_320 = (struct V_319 * ) V_2 -> V_294 ;
F_101 ( V_2 , ( V_206 * ) V_2 -> V_294 ,
V_179 -> V_302 << 2 , V_295 ) ;
if ( * V_286 == F_104 ( 0xffff ) )
goto V_296;
if ( V_320 -> V_325 [ 0 ] != 'Q' || V_320 -> V_325 [ 1 ] != 'L' || V_320 -> V_325 [ 2 ] != 'I' ||
V_320 -> V_325 [ 3 ] != 'D' )
goto V_296;
for ( V_287 = 0 , V_288 = 0 ; V_287 < sizeof( struct V_319 ) >> 1 ;
V_287 ++ )
V_288 += F_105 ( * V_286 ++ ) ;
if ( V_288 ) {
F_8 ( F_9 ( V_62 , V_2 , L_63
L_64 , V_288 , V_320 -> V_325 [ 0 ] ,
F_105 ( V_320 -> V_297 ) ) ) ;
goto V_296;
}
V_282 = V_283 [ 1 ] ;
V_321 = F_105 ( V_320 -> V_326 ) ;
V_322 = F_105 ( V_320 -> V_327 ) ;
V_179 -> V_328 = V_320 -> V_329 ;
V_179 -> V_330 = F_96 ( V_179 , 0x0300 | V_320 -> V_331 ) ;
V_179 -> V_332 = F_106 ( V_320 -> V_333 ) ;
if ( V_320 -> V_334 ) {
V_179 -> V_335 = F_96 ( V_179 , 0x0300 |
V_320 -> V_334 ) ;
V_179 -> V_336 = V_320 -> V_337 ?
F_96 ( V_179 , 0x0300 | V_320 -> V_337 ) :
F_96 ( V_179 , 0x0336 ) ;
}
goto V_70;
V_296:
V_282 = V_283 [ 0 ] ;
V_179 -> V_332 = F_111 ;
V_70:
F_8 ( F_9 ( V_62 , V_2 , L_65
L_66 , V_282 , V_321 , V_322 ,
V_179 -> V_330 , V_179 -> V_336 ,
V_179 -> V_335 , V_179 -> V_328 ,
V_179 -> V_332 ) ) ;
}
static void
F_112 ( struct V_1 * V_2 )
{
#define F_113 0x003e885c
T_5 * V_286 ;
if ( ! F_114 ( V_2 ) )
return;
V_286 = ( T_5 * ) V_2 -> V_294 ;
F_101 ( V_2 , ( V_206 * ) V_2 -> V_294 ,
F_113 , 8 ) ;
if ( * V_286 == F_100 ( 0xffffffff ) ) {
V_2 -> V_267 = V_338 ;
V_2 -> V_260 = V_339 ;
} else {
V_2 -> V_267 = F_106 ( * V_286 ++ ) ;
V_2 -> V_260 = F_106 ( * V_286 ) ;
}
F_8 ( F_9 ( V_299 , V_2 ,
L_67 , V_2 -> V_267 ) ) ;
F_8 ( F_9 ( V_299 , V_2 ,
L_68 , V_2 -> V_260 ) ) ;
return;
}
int
F_83 ( struct V_1 * V_2 )
{
int V_116 ;
T_5 V_285 ;
V_116 = F_102 ( V_2 , & V_285 ) ;
if ( V_116 != V_185 )
return V_116 ;
F_103 ( V_2 , V_285 ) ;
F_108 ( V_2 ) ;
F_112 ( V_2 ) ;
return V_185 ;
}
int
F_115 ( struct V_1 * V_2 )
{
int V_340 ;
T_5 V_341 [ V_342 ] ;
T_5 V_343 [ V_342 ] ;
memset ( & V_341 , 0 , sizeof( V_341 ) ) ;
memset ( & V_343 , 0 , sizeof( V_343 ) ) ;
V_341 [ 0 ] = V_344 ;
V_340 = F_116 ( V_2 , V_342 , 1 ,
& V_341 [ 0 ] , & V_343 [ 0 ] ) ;
F_8 ( F_32 ( L_69 , V_2 -> V_181 ,
V_63 , V_340 ) ) ;
return V_340 ;
}
int
F_117 ( struct V_1 * V_2 )
{
int V_174 ;
T_5 V_254 ;
F_23 ( V_2 ) ;
V_254 = F_18 ( V_2 , V_246 ) ;
if ( V_254 == V_253 ) {
F_9 ( V_62 , V_2 , L_70 ) ;
F_11 ( V_2 , V_246 ,
V_268 ) ;
} else
F_9 ( V_62 , V_2 , L_71 ) ;
F_24 ( V_2 ) ;
V_174 = F_92 ( V_2 ) ;
F_23 ( V_2 ) ;
F_77 ( V_2 ) ;
F_24 ( V_2 ) ;
if ( V_174 == V_185 )
F_118 ( V_345 , & V_2 -> V_66 ) ;
return V_174 ;
}
int F_119 ( struct V_1 * V_2 )
{
T_5 V_341 [ V_342 ] ;
T_5 V_343 [ V_342 ] ;
struct V_346 * V_347 ;
T_7 V_348 ;
int V_340 = V_186 ;
V_347 = F_120 ( & V_2 -> V_122 -> V_240 , sizeof( * V_347 ) ,
& V_348 , V_165 ) ;
if ( V_347 == NULL ) {
F_8 ( F_32 ( L_72 ,
V_2 -> V_181 , V_63 ) ) ;
return V_340 ;
}
memset ( V_347 , 0 , sizeof( * V_347 ) ) ;
memset ( & V_341 , 0 , sizeof( V_341 ) ) ;
memset ( & V_343 , 0 , sizeof( V_343 ) ) ;
V_341 [ 0 ] = V_349 ;
V_341 [ 1 ] = F_121 ( V_348 ) ;
V_341 [ 2 ] = F_122 ( V_348 ) ;
V_341 [ 4 ] = sizeof( * V_347 ) ;
if ( F_116 ( V_2 , V_342 , 6 , & V_341 [ 0 ] ,
& V_343 [ 0 ] ) != V_185 ) {
F_8 ( F_32 ( L_73 ,
V_2 -> V_181 , V_63 ) ) ;
goto V_350;
}
if ( V_343 [ 4 ] < F_123 ( struct V_346 , V_351 ) ) {
F_8 ( F_32 ( L_74
L_75 , V_2 -> V_181 , V_63 , V_343 [ 4 ] ) ) ;
goto V_350;
}
V_2 -> V_352 = V_347 -> V_352 ;
memcpy ( V_2 -> V_353 , & V_347 -> V_354 [ 0 ] ,
F_124 ( sizeof( V_2 -> V_353 ) , sizeof( V_347 -> V_354 ) ) ) ;
memcpy ( V_2 -> V_355 , & V_347 -> V_355 ,
F_124 ( sizeof( V_2 -> V_355 ) , sizeof( V_347 -> V_355 ) ) ) ;
memcpy ( V_2 -> V_356 , & V_347 -> V_357 ,
F_124 ( sizeof( V_2 -> V_356 ) , sizeof( V_347 -> V_357 ) ) ) ;
V_2 -> V_358 = V_347 -> V_359 ;
V_2 -> V_360 = V_347 -> V_352 ;
V_2 -> V_361 = V_347 -> V_361 ;
F_8 ( F_32 ( L_76
L_77
L_78 , V_2 -> V_181 , V_63 ,
V_2 -> V_353 [ 0 ] , V_2 -> V_353 [ 1 ] , V_2 -> V_353 [ 2 ] ,
V_2 -> V_353 [ 3 ] , V_2 -> V_353 [ 4 ] , V_2 -> V_353 [ 5 ] ,
V_2 -> V_355 ) ) ;
V_340 = V_185 ;
V_350:
F_125 ( & V_2 -> V_122 -> V_240 , sizeof( * V_347 ) , V_347 ,
V_348 ) ;
return V_340 ;
}
static int
F_126 ( struct V_1 * V_2 )
{
T_5 V_341 [ V_342 ] ;
T_5 V_343 [ V_342 ] ;
F_8 ( F_9 ( V_62 , V_2 , L_79 , V_63 ) ) ;
memset ( & V_341 , 0 , sizeof( V_341 ) ) ;
memset ( & V_343 , 0 , sizeof( V_343 ) ) ;
V_341 [ 0 ] = V_362 ;
V_341 [ 1 ] = V_363 ;
if ( F_116 ( V_2 , V_342 , 1 , & V_341 [ 0 ] ,
& V_343 [ 0 ] ) != V_185 ) {
F_8 ( F_9 ( V_62 , V_2 ,
L_80 ,
V_63 , V_343 [ 0 ] ) ) ;
return V_186 ;
}
return V_185 ;
}
static int
F_127 ( struct V_1 * V_2 )
{
T_5 V_341 [ V_342 ] ;
T_5 V_343 [ V_342 ] ;
F_8 ( F_9 ( V_62 , V_2 , L_79 , V_63 ) ) ;
memset ( & V_341 , 0 , sizeof( V_341 ) ) ;
memset ( & V_343 , 0 , sizeof( V_343 ) ) ;
V_341 [ 0 ] = V_362 ;
V_341 [ 1 ] = V_364 ;
if ( F_116 ( V_2 , V_342 , 1 , & V_341 [ 0 ] ,
& V_343 [ 0 ] ) != V_185 ) {
F_8 ( F_9 ( V_62 , V_2 ,
L_80 ,
V_63 , V_343 [ 0 ] ) ) ;
return V_186 ;
}
return V_185 ;
}
void
F_128 ( struct V_1 * V_2 )
{
F_126 ( V_2 ) ;
F_129 ( & V_2 -> V_365 ) ;
F_11 ( V_2 , V_2 -> V_366 . V_367 , 0xfbff ) ;
F_130 ( & V_2 -> V_365 ) ;
F_131 ( V_368 , & V_2 -> V_66 ) ;
}
void
F_132 ( struct V_1 * V_2 )
{
if ( F_89 ( V_368 , & V_2 -> V_66 ) )
F_127 ( V_2 ) ;
F_129 ( & V_2 -> V_365 ) ;
F_11 ( V_2 , V_2 -> V_366 . V_367 , 0x0400 ) ;
F_130 ( & V_2 -> V_365 ) ;
}
void
F_133 ( struct V_1 * V_2 )
{
int V_69 ;
struct V_369 * V_370 ;
for ( V_69 = 0 ; V_69 < V_371 ; V_69 ++ ) {
V_370 = & V_2 -> V_372 [ V_373 [ V_69 ] . V_374 ] ;
if ( V_370 -> V_375 ) {
F_134 ( V_370 -> V_376 , V_2 ) ;
F_8 ( F_9 ( V_62 , V_2 , L_81 ,
V_63 , V_373 [ V_69 ] . V_377 ) ) ;
}
}
F_135 ( V_2 -> V_122 ) ;
F_118 ( V_378 , & V_2 -> V_66 ) ;
}
int
F_136 ( struct V_1 * V_2 )
{
int V_69 , V_116 ;
struct V_379 V_380 [ V_371 ] ;
struct V_369 * V_370 ;
for ( V_69 = 0 ; V_69 < V_371 ; V_69 ++ )
V_380 [ V_69 ] . V_381 = V_373 [ V_69 ] . V_381 ;
V_116 = F_137 ( V_2 -> V_122 , V_380 , F_138 ( V_380 ) ) ;
if ( V_116 ) {
F_9 ( V_100 , V_2 ,
L_82 ,
V_371 , V_116 ) ;
goto V_382;
}
F_131 ( V_378 , & V_2 -> V_66 ) ;
for ( V_69 = 0 ; V_69 < V_371 ; V_69 ++ ) {
V_370 = & V_2 -> V_372 [ V_373 [ V_69 ] . V_374 ] ;
V_370 -> V_376 = V_380 [ V_69 ] . V_383 ;
V_370 -> V_379 = V_380 [ V_69 ] . V_381 ;
V_370 -> V_375 = 0 ;
V_116 = F_139 ( V_370 -> V_376 ,
V_373 [ V_69 ] . V_384 , 0 ,
V_373 [ V_69 ] . V_377 , V_2 ) ;
if ( V_116 ) {
F_9 ( V_100 , V_2 ,
L_83 ,
V_373 [ V_69 ] . V_374 , V_116 ) ;
F_133 ( V_2 ) ;
goto V_382;
}
V_370 -> V_375 = 1 ;
F_8 ( F_9 ( V_62 , V_2 , L_81 ,
V_63 , V_373 [ V_69 ] . V_377 ) ) ;
}
V_382:
return V_116 ;
}
