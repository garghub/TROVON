static void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
int V_3 ;
V_4 = 0 ;
for ( V_3 = 0 , V_2 = V_5 ; V_3 < V_6 ; V_3 ++ , V_2 ++ ) {
struct V_7 * V_8 = F_2 ( 1 ) ;
if ( ! V_8 )
continue;
V_8 -> V_9 = F_3 ( V_10 , & V_11 ) ;
if ( ! V_8 -> V_9 ) {
F_4 ( V_8 ) ;
return;
}
F_5 ( V_8 -> V_9 , V_12 ) ;
F_6 ( V_8 -> V_9 , V_13 ) ;
V_2 -> V_8 = V_8 ;
V_2 -> V_14 = & V_2 -> V_15 ;
V_2 -> V_16 = V_17 ;
V_2 -> V_18 = ( * V_19 [ V_3 ] ) [ V_20 ] ;
V_2 -> V_21 = ( * V_19 [ V_3 ] ) [ V_22 ] ;
snprintf ( V_2 -> V_23 , V_24 , L_1 , V_23 , V_3 ) ;
V_8 -> V_25 = V_25 ;
V_8 -> V_26 = V_3 ;
strcpy ( V_8 -> V_27 , V_2 -> V_23 ) ;
V_8 -> V_28 = & V_29 ;
if ( ! ( * V_19 [ V_3 ] ) [ V_30 ] )
V_4 ++ ;
}
}
static int F_7 ( struct V_31 * V_32 , T_2 V_33 )
{
struct V_1 * V_2 = V_32 -> V_34 -> V_35 ;
int V_36 ;
F_8 ( & V_37 ) ;
F_9 ( V_2 ) ;
V_36 = - V_38 ;
if ( V_2 -> V_16 == V_17 )
goto V_39;
V_36 = - V_40 ;
if ( ( V_2 -> V_16 == V_41 ) && ( V_33 & V_42 ) )
goto V_39;
V_36 = 0 ;
V_2 -> V_43 ++ ;
if ( V_2 -> V_44 )
F_10 ( V_2 , 1 ) ;
V_39:
F_11 ( & V_37 ) ;
return V_36 ;
}
static int F_12 ( struct V_31 * V_32 , struct V_45 * V_46 )
{
struct V_1 * V_2 = V_32 -> V_34 -> V_35 ;
T_3 V_47 = F_13 ( V_2 -> V_8 ) ;
if ( V_47 < V_48 ) {
V_46 -> V_49 = F_14 ( V_47 , V_50 * V_51 ) ;
V_46 -> V_52 = V_50 ;
V_46 -> V_53 = V_51 ;
} else {
V_46 -> V_49 = F_14 ( V_47 , V_54 * V_55 ) ;
V_46 -> V_52 = V_54 ;
V_46 -> V_53 = V_55 ;
}
return 0 ;
}
static int F_15 ( struct V_31 * V_32 , T_2 V_33 , unsigned int V_56 , unsigned long V_57 )
{
struct V_1 * V_2 = V_32 -> V_34 -> V_35 ;
if ( V_56 != V_58 )
return - V_59 ;
if ( V_2 -> V_43 != 1 )
return - V_60 ;
F_8 ( & V_37 ) ;
F_16 ( V_2 ) ;
F_11 ( & V_37 ) ;
return 0 ;
}
static void F_17 ( struct V_7 * V_8 , T_2 V_33 )
{
struct V_1 * V_2 = V_8 -> V_35 ;
F_8 ( & V_37 ) ;
if ( V_2 -> V_43 <= 0 ) {
F_11 ( & V_37 ) ;
F_18 ( 1 ) ;
return;
}
V_2 -> V_43 -- ;
if ( ! V_2 -> V_43 && V_2 -> V_44 )
F_10 ( V_2 , 0 ) ;
F_11 ( & V_37 ) ;
}
static unsigned int F_19 ( struct V_7 * V_8 , unsigned int V_61 )
{
return V_62 ;
}
static inline int F_20 ( struct V_1 * V_2 )
{
return F_21 ( V_2 -> V_14 , 1 , 6 ) ;
}
static inline int F_22 ( struct V_1 * V_2 , int V_63 )
{
return F_21 ( V_2 -> V_14 , 0 , V_63 ) ;
}
static inline void F_23 ( struct V_1 * V_2 , int V_63 , int V_64 )
{
F_24 ( V_2 -> V_14 , 0 , V_63 , V_64 ) ;
}
static int F_25 ( struct V_1 * V_2 , int V_65 , int V_66 , char * V_67 , char * V_68 )
{
int V_69 , V_70 , V_71 , V_72 , V_73 ;
V_69 = 0 ;
while ( ( ( ( V_70 = F_20 ( V_2 ) ) & V_65 ) || ( V_66 && ( ! ( V_70 & V_66 ) ) ) )
&& ( V_69 ++ < V_74 ) )
F_26 ( V_75 ) ;
if ( ( V_70 & ( V_76 & V_66 ) ) || ( V_69 > V_74 ) ) {
V_72 = F_22 ( V_2 , 7 ) ;
V_71 = F_22 ( V_2 , 1 ) ;
V_73 = F_22 ( V_2 , 2 ) ;
if ( V_69 > V_74 )
V_71 |= 0x100 ;
if ( V_67 )
F_27 ( L_2
L_3 ,
V_2 -> V_23 , V_67 , V_68 , V_70 , V_72 , V_71 , V_69 , V_73 ) ;
return ( V_71 << 8 ) + V_72 ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , char * V_56 , int V_77 , char * V_67 )
{
F_29 ( V_2 -> V_14 ) ;
F_23 ( V_2 , 6 , 0xa0 + 0x10 * V_2 -> V_18 ) ;
if ( F_25 ( V_2 , V_78 | V_79 , 0 , V_67 , L_4 ) ) {
F_30 ( V_2 -> V_14 ) ;
return - 1 ;
}
F_23 ( V_2 , 4 , V_77 % 256 ) ;
F_23 ( V_2 , 5 , V_77 / 256 ) ;
F_23 ( V_2 , 7 , 0xa0 ) ;
if ( F_25 ( V_2 , V_78 , V_79 , V_67 , L_5 ) ) {
F_30 ( V_2 -> V_14 ) ;
return - 1 ;
}
if ( F_22 ( V_2 , 2 ) != 1 ) {
F_27 ( L_6 , V_2 -> V_23 , V_67 ) ;
F_30 ( V_2 -> V_14 ) ;
return - 1 ;
}
F_31 ( V_2 -> V_14 , V_56 , 12 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , char * V_80 , char * V_67 )
{
int V_70 , V_72 , V_81 ;
V_70 = F_25 ( V_2 , V_78 , V_79 | V_82 | V_76 ,
V_67 , L_7 ) ;
if ( ( F_22 ( V_2 , 2 ) & 2 ) && ( F_22 ( V_2 , 7 ) & V_79 ) ) {
V_81 = ( ( ( F_22 ( V_2 , 4 ) + 256 * F_22 ( V_2 , 5 ) ) +
3 ) & 0xfffc ) ;
F_33 ( V_2 -> V_14 , V_80 , V_81 ) ;
}
V_72 = F_25 ( V_2 , V_78 , V_82 | V_76 , V_67 , L_8 ) ;
F_30 ( V_2 -> V_14 ) ;
return ( V_70 ? V_70 : V_72 ) ;
}
static void F_34 ( struct V_1 * V_2 , int V_83 )
{
char V_84 [ 12 ] =
{ V_85 , V_2 -> V_21 << 5 , 0 , 0 , 16 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
char V_80 [ 16 ] ;
int V_70 ;
V_70 = F_28 ( V_2 , V_84 , 16 , L_9 ) ;
F_35 ( 1 ) ;
if ( ! V_70 )
F_32 ( V_2 , V_80 , L_9 ) ;
if ( ( ! V_70 ) && ( ! V_83 ) )
F_27 ( L_10 ,
V_2 -> V_23 , V_80 [ 2 ] & 0xf , V_80 [ 12 ] , V_80 [ 13 ] ) ;
}
static int F_36 ( struct V_1 * V_2 , char * V_56 , int V_77 , char * V_80 , char * V_67 )
{
int V_70 ;
V_70 = F_28 ( V_2 , V_56 , V_77 , V_67 ) ;
F_35 ( 1 ) ;
if ( ! V_70 )
V_70 = F_32 ( V_2 , V_80 , V_67 ) ;
if ( V_70 )
F_34 ( V_2 , ! V_67 ) ;
return V_70 ;
}
static void F_10 ( struct V_1 * V_2 , int V_86 )
{
char V_87 [ 12 ] = { V_88 , V_2 -> V_21 << 5 , 0 , 0 , V_86 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
F_36 ( V_2 , V_87 , 0 , V_89 , V_86 ? L_11 : L_12 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
char V_90 [ 12 ] = { V_91 , V_2 -> V_21 << 5 , 0 , 0 , 2 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
F_10 ( V_2 , 0 ) ;
F_36 ( V_2 , V_90 , 0 , V_89 , L_13 ) ;
}
static void F_37 ( int V_92 )
{
F_38 ( V_92 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
int V_93 , V_94 , V_95 ;
int V_96 [ 5 ] = { 1 , 1 , 1 , 0x14 , 0xeb } ;
F_29 ( V_2 -> V_14 ) ;
F_23 ( V_2 , 6 , 0xa0 + 0x10 * V_2 -> V_18 ) ;
F_23 ( V_2 , 7 , 8 ) ;
F_37 ( 20 * V_97 / 1000 ) ;
V_94 = 0 ;
while ( ( V_94 ++ < V_98 ) && ( F_20 ( V_2 ) & V_78 ) )
F_37 ( V_97 / 10 ) ;
V_95 = 1 ;
for ( V_93 = 0 ; V_93 < 5 ; V_93 ++ )
V_95 &= ( F_22 ( V_2 , V_93 + 1 ) == V_96 [ V_93 ] ) ;
if ( V_99 ) {
F_27 ( L_14 , V_2 -> V_23 , V_94 ) ;
for ( V_93 = 0 ; V_93 < 5 ; V_93 ++ )
F_27 ( L_15 , F_22 ( V_2 , V_93 + 1 ) ) ;
if ( ! V_95 )
F_27 ( L_16 ) ;
F_27 ( L_17 ) ;
}
F_30 ( V_2 -> V_14 ) ;
return V_95 - 1 ;
}
static void F_40 ( struct V_1 * V_2 )
{
char V_100 [ 12 ] =
{ V_101 , V_2 -> V_21 << 5 , 0 , 0 , 0 , 0 , 0 , 0 , 8 , 0 , 0 , 0 } ;
char V_80 [ 8 ] ;
F_36 ( V_2 , V_100 , 8 , V_80 , L_18 ) ;
V_2 -> V_16 = V_102 ;
if ( V_80 [ 3 ] & 0x80 )
V_2 -> V_16 = V_41 ;
}
static void F_41 ( char * V_80 , char * V_103 , int V_104 , int V_105 )
{
int V_69 , V_94 , V_106 ;
V_69 = 0 ;
V_106 = 0 ;
for ( V_94 = 0 ; V_94 < V_105 ; V_94 ++ )
if ( ( V_80 [ V_94 + V_104 ] != 0x20 ) || ( V_80 [ V_94 + V_104 ] != V_106 ) )
V_106 = V_103 [ V_69 ++ ] = V_80 [ V_94 + V_104 ] ;
if ( V_106 == 0x20 )
V_69 -- ;
V_103 [ V_69 ] = 0 ;
}
static int F_42 ( char * V_80 , int V_104 )
{
int V_107 , V_94 ;
V_107 = 0 ;
for ( V_94 = 0 ; V_94 < 4 ; V_94 ++ )
V_107 = V_107 * 256 + ( V_80 [ V_94 + V_104 ] & 0xff ) ;
return V_107 ;
}
static void F_43 ( struct V_1 * V_2 )
{
char V_108 [ 12 ] = { V_109 , V_2 -> V_21 << 5 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
char V_80 [ 8 ] ;
int V_110 ;
if ( F_36 ( V_2 , V_108 , 8 , V_80 , L_19 ) ) {
V_2 -> V_16 = V_17 ;
return;
}
F_44 ( V_2 -> V_8 , F_42 ( V_80 , 0 ) + 1 ) ;
V_110 = F_42 ( V_80 , 4 ) ;
if ( V_110 != 512 ) {
F_44 ( V_2 -> V_8 , 0 ) ;
if ( V_99 )
F_27 ( L_20
L_21 ,
V_2 -> V_23 , V_2 -> V_18 , V_2 -> V_21 , V_110 ) ;
}
}
static int F_9 ( struct V_1 * V_2 )
{
int V_111 , V_72 ;
char * V_112 [ 2 ] = { L_22 , L_23 } ;
char V_113 [ 10 ] , V_114 [ 18 ] ;
char V_115 [ 12 ] =
{ V_116 , V_2 -> V_21 << 5 , 0 , 0 , 36 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
char V_80 [ 36 ] ;
V_72 = F_36 ( V_2 , V_115 , 36 , V_80 , L_24 ) ;
if ( V_72 )
return - 1 ;
V_111 = V_80 [ 0 ] & 0x1f ;
if ( ( V_111 != 0 ) && ( V_111 != 7 ) ) {
if ( V_99 )
F_27 ( L_25 ,
V_2 -> V_23 , V_2 -> V_18 , V_2 -> V_21 , V_111 ) ;
return - 1 ;
}
F_41 ( V_80 , V_113 , 8 , 8 ) ;
F_41 ( V_80 , V_114 , 16 , 16 ) ;
V_2 -> V_44 = ( V_80 [ 1 ] & 0x80 ) ;
F_40 ( V_2 ) ;
F_40 ( V_2 ) ;
F_40 ( V_2 ) ;
F_43 ( V_2 ) ;
F_27 ( L_26 ,
V_2 -> V_23 , V_113 , V_114 , V_112 [ V_2 -> V_18 ] , V_2 -> V_21 , V_111 ) ;
if ( V_2 -> V_44 )
F_27 ( L_27 ) ;
if ( V_2 -> V_16 == V_17 )
F_27 ( L_28 ) ;
else {
if ( V_2 -> V_16 == V_41 )
F_27 ( L_29 ) ;
F_27 ( L_30 ,
( unsigned long long ) F_13 ( V_2 -> V_8 ) ) ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
if ( V_2 -> V_18 == - 1 ) {
for ( V_2 -> V_18 = 0 ; V_2 -> V_18 <= 1 ; V_2 -> V_18 ++ )
if ( ! F_39 ( V_2 ) ) {
if ( V_2 -> V_21 != - 1 )
return F_9 ( V_2 ) ;
else
for ( V_2 -> V_21 = 0 ; V_2 -> V_21 < 8 ; V_2 -> V_21 ++ )
if ( ! F_9 ( V_2 ) )
return 0 ;
}
} else {
if ( F_39 ( V_2 ) )
return - 1 ;
if ( V_2 -> V_21 != - 1 )
return F_9 ( V_2 ) ;
for ( V_2 -> V_21 = 0 ; V_2 -> V_21 < 8 ; V_2 -> V_21 ++ )
if ( ! F_9 ( V_2 ) )
return 0 ;
}
return - 1 ;
}
static int F_46 ( void )
{
struct V_1 * V_2 = V_5 ;
int V_94 , V_3 ;
F_27 ( L_31 ,
V_23 , V_23 , V_117 , V_25 , V_12 , V_118 ) ;
V_119 = F_47 ( V_23 ) ;
if ( ! V_119 ) {
F_48 ( L_32 , V_23 ) ;
return - 1 ;
}
V_94 = 0 ;
if ( V_4 == 0 ) {
if ( F_49 ( V_2 -> V_14 , 1 , - 1 , - 1 , - 1 , - 1 , - 1 , V_89 , V_120 ,
V_99 , V_2 -> V_23 ) ) {
if ( ! F_45 ( V_2 ) && V_2 -> V_8 ) {
V_2 -> V_121 = 1 ;
V_94 ++ ;
} else
F_50 ( V_2 -> V_14 ) ;
}
} else
for ( V_3 = 0 ; V_3 < V_6 ; V_3 ++ , V_2 ++ ) {
int * V_122 = * V_19 [ V_3 ] ;
if ( ! V_122 [ V_30 ] )
continue;
if ( F_49 ( V_2 -> V_14 , 0 , V_122 [ V_30 ] , V_122 [ V_123 ] ,
V_122 [ V_124 ] , V_122 [ V_125 ] , V_122 [ V_126 ] ,
V_89 , V_120 , V_99 , V_2 -> V_23 ) ) {
if ( V_2 -> V_8 && ! F_45 ( V_2 ) ) {
V_2 -> V_121 = 1 ;
V_94 ++ ;
} else
F_50 ( V_2 -> V_14 ) ;
}
}
if ( V_94 )
return 0 ;
F_27 ( L_33 , V_23 ) ;
for ( V_2 = V_5 , V_3 = 0 ; V_3 < V_6 ; V_2 ++ , V_3 ++ )
F_4 ( V_2 -> V_8 ) ;
F_51 ( V_119 ) ;
return - 1 ;
}
static int F_52 ( struct V_1 * V_2 , int V_56 , int V_127 , int V_128 )
{
int V_93 ;
char V_129 [ 12 ] = { V_56 , V_2 -> V_21 << 5 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
for ( V_93 = 0 ; V_93 < 4 ; V_93 ++ ) {
V_129 [ 5 - V_93 ] = V_127 & 0xff ;
V_127 = V_127 >> 8 ;
}
V_129 [ 8 ] = V_128 & 0xff ;
V_129 [ 7 ] = ( V_128 >> 8 ) & 0xff ;
V_93 = F_28 ( V_2 , V_129 , V_128 * 512 , L_34 ) ;
F_35 ( 1 ) ;
return V_93 ;
}
static int F_53 ( void )
{
return ( ( ( F_20 ( V_130 ) & ( V_78 | V_131 ) ) == V_131 ) ) ;
}
static int F_54 ( void )
{
struct V_1 * V_2 ;
struct V_132 * V_133 ;
int V_134 = V_135 ;
do {
V_2 = & V_5 [ V_135 ] ;
V_133 = V_2 -> V_121 ? V_2 -> V_8 -> V_9 : NULL ;
if ( ++ V_135 == V_6 )
V_135 = 0 ;
if ( V_133 ) {
V_136 = F_55 ( V_133 ) ;
if ( V_136 )
break;
}
} while ( V_135 != V_134 );
return V_136 != NULL ;
}
static void F_56 ( T_4 V_137 )
{
if ( V_136 && ! F_57 ( V_136 , V_137 ) )
V_136 = NULL ;
}
static void F_58 ( void )
{
if ( V_138 )
return;
V_139:
if ( ! V_136 && ! F_54 () )
return;
V_130 = V_136 -> V_140 -> V_35 ;
V_141 = F_59 ( V_136 ) ;
V_142 = F_60 ( V_136 ) ;
V_143 = F_61 ( V_136 ) ;
if ( V_141 + V_143 > F_13 ( V_136 -> V_140 ) ) {
F_56 ( V_144 ) ;
goto V_139;
}
V_145 = F_62 ( V_136 ) ;
V_146 = F_63 ( V_136 -> V_147 ) ;
V_148 = 0 ;
V_138 = 1 ;
if ( V_145 == V_149 )
F_64 ( V_130 -> V_14 , V_150 ) ;
else if ( V_145 == V_151 )
F_64 ( V_130 -> V_14 , V_152 ) ;
else {
V_138 = 0 ;
F_56 ( V_144 ) ;
goto V_139;
}
}
static void V_10 ( struct V_132 * V_133 )
{
F_58 () ;
}
static int F_65 ( void )
{
unsigned long V_153 ;
V_143 -- ;
V_142 -- ;
V_146 += 512 ;
V_141 ++ ;
if ( ! V_142 )
return 1 ;
if ( ! V_143 ) {
F_66 ( & V_11 , V_153 ) ;
F_56 ( 0 ) ;
F_67 ( & V_11 , V_153 ) ;
if ( ! V_136 )
return 1 ;
V_143 = F_61 ( V_136 ) ;
V_146 = F_63 ( V_136 -> V_147 ) ;
}
return 0 ;
}
static inline void F_68 ( T_4 V_137 )
{
unsigned long V_153 ;
F_66 ( & V_11 , V_153 ) ;
F_56 ( V_137 ) ;
V_138 = 0 ;
F_58 () ;
F_67 ( & V_11 , V_153 ) ;
}
static void V_150 ( void )
{
F_69 ( V_154 , NULL , 0 , V_118 ) ;
}
static void V_154 ( void )
{
V_138 = 1 ;
if ( F_52 ( V_130 , V_155 , V_141 , V_142 ) ) {
F_30 ( V_130 -> V_14 ) ;
if ( V_148 < V_156 ) {
V_148 ++ ;
F_64 ( V_130 -> V_14 , V_154 ) ;
return;
}
F_68 ( V_144 ) ;
return;
}
V_131 = V_79 ;
F_69 ( V_157 , F_53 , V_158 , V_118 ) ;
}
static void V_157 ( void )
{
while ( 1 ) {
if ( F_25 ( V_130 , V_78 , V_79 | V_76 ,
L_35 , L_7 ) & V_76 ) {
F_30 ( V_130 -> V_14 ) ;
if ( V_148 < V_156 ) {
F_34 ( V_130 , 0 ) ;
V_148 ++ ;
F_64 ( V_130 -> V_14 , V_154 ) ;
return;
}
F_68 ( V_144 ) ;
return;
}
F_33 ( V_130 -> V_14 , V_146 , 512 ) ;
if ( F_65 () )
break;
}
F_30 ( V_130 -> V_14 ) ;
F_68 ( 0 ) ;
}
static void V_152 ( void )
{
F_69 ( V_159 , NULL , 0 , V_118 ) ;
}
static void V_159 ( void )
{
V_138 = 1 ;
if ( F_52 ( V_130 , V_160 , V_141 , V_142 ) ) {
F_30 ( V_130 -> V_14 ) ;
if ( V_148 < V_156 ) {
V_148 ++ ;
F_64 ( V_130 -> V_14 , V_159 ) ;
return;
}
F_68 ( V_144 ) ;
return;
}
while ( 1 ) {
if ( F_25 ( V_130 , V_78 , V_79 | V_76 ,
L_36 , L_37 ) & V_76 ) {
F_30 ( V_130 -> V_14 ) ;
if ( V_148 < V_156 ) {
V_148 ++ ;
F_64 ( V_130 -> V_14 , V_159 ) ;
return;
}
F_68 ( V_144 ) ;
return;
}
F_31 ( V_130 -> V_14 , V_146 , 512 ) ;
if ( F_65 () )
break;
}
V_131 = 0 ;
F_69 ( V_161 , F_53 , V_158 , V_118 ) ;
}
static void V_161 ( void )
{
if ( F_25 ( V_130 , V_78 , 0 , L_36 , L_38 ) & V_76 ) {
F_30 ( V_130 -> V_14 ) ;
if ( V_148 < V_156 ) {
V_148 ++ ;
F_64 ( V_130 -> V_14 , V_159 ) ;
return;
}
F_68 ( V_144 ) ;
return;
}
F_30 ( V_130 -> V_14 ) ;
F_68 ( 0 ) ;
}
static int T_1 F_70 ( void )
{
struct V_1 * V_2 ;
int V_3 ;
if ( V_162 )
return - V_59 ;
F_1 () ;
if ( F_46 () )
return - V_38 ;
V_138 = 0 ;
if ( F_71 ( V_25 , V_23 ) ) {
for ( V_2 = V_5 , V_3 = 0 ; V_3 < V_6 ; V_2 ++ , V_3 ++ )
F_4 ( V_2 -> V_8 ) ;
return - V_60 ;
}
for ( V_2 = V_5 , V_3 = 0 ; V_3 < V_6 ; V_2 ++ , V_3 ++ ) {
struct V_7 * V_8 = V_2 -> V_8 ;
if ( ! V_2 -> V_121 )
continue;
V_8 -> V_35 = V_2 ;
F_72 ( V_8 ) ;
}
return 0 ;
}
static void T_5 F_73 ( void )
{
struct V_1 * V_2 ;
int V_3 ;
F_74 ( V_25 , V_23 ) ;
for ( V_2 = V_5 , V_3 = 0 ; V_3 < V_6 ; V_2 ++ , V_3 ++ ) {
if ( ! V_2 -> V_121 )
continue;
F_75 ( V_2 -> V_8 ) ;
F_76 ( V_2 -> V_8 -> V_9 ) ;
F_4 ( V_2 -> V_8 ) ;
F_50 ( V_2 -> V_14 ) ;
}
}
