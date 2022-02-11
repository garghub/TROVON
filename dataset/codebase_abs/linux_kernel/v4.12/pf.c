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
V_2 -> V_8 = V_8 ;
V_2 -> V_13 = & V_2 -> V_14 ;
V_2 -> V_15 = V_16 ;
V_2 -> V_17 = ( * V_18 [ V_3 ] ) [ V_19 ] ;
V_2 -> V_20 = ( * V_18 [ V_3 ] ) [ V_21 ] ;
snprintf ( V_2 -> V_22 , V_23 , L_1 , V_22 , V_3 ) ;
V_8 -> V_24 = V_24 ;
V_8 -> V_25 = V_3 ;
strcpy ( V_8 -> V_26 , V_2 -> V_22 ) ;
V_8 -> V_27 = & V_28 ;
if ( ! ( * V_18 [ V_3 ] ) [ V_29 ] )
V_4 ++ ;
}
}
static int F_6 ( struct V_30 * V_31 , T_2 V_32 )
{
struct V_1 * V_2 = V_31 -> V_33 -> V_34 ;
int V_35 ;
F_7 ( & V_36 ) ;
F_8 ( V_2 ) ;
V_35 = - V_37 ;
if ( V_2 -> V_15 == V_16 )
goto V_38;
V_35 = - V_39 ;
if ( ( V_2 -> V_15 == V_40 ) && ( V_32 & V_41 ) )
goto V_38;
V_35 = 0 ;
V_2 -> V_42 ++ ;
if ( V_2 -> V_43 )
F_9 ( V_2 , 1 ) ;
V_38:
F_10 ( & V_36 ) ;
return V_35 ;
}
static int F_11 ( struct V_30 * V_31 , struct V_44 * V_45 )
{
struct V_1 * V_2 = V_31 -> V_33 -> V_34 ;
T_3 V_46 = F_12 ( V_2 -> V_8 ) ;
if ( V_46 < V_47 ) {
V_45 -> V_48 = F_13 ( V_46 , V_49 * V_50 ) ;
V_45 -> V_51 = V_49 ;
V_45 -> V_52 = V_50 ;
} else {
V_45 -> V_48 = F_13 ( V_46 , V_53 * V_54 ) ;
V_45 -> V_51 = V_53 ;
V_45 -> V_52 = V_54 ;
}
return 0 ;
}
static int F_14 ( struct V_30 * V_31 , T_2 V_32 , unsigned int V_55 , unsigned long V_56 )
{
struct V_1 * V_2 = V_31 -> V_33 -> V_34 ;
if ( V_55 != V_57 )
return - V_58 ;
if ( V_2 -> V_42 != 1 )
return - V_59 ;
F_7 ( & V_36 ) ;
F_15 ( V_2 ) ;
F_10 ( & V_36 ) ;
return 0 ;
}
static void F_16 ( struct V_7 * V_8 , T_2 V_32 )
{
struct V_1 * V_2 = V_8 -> V_34 ;
F_7 ( & V_36 ) ;
if ( V_2 -> V_42 <= 0 ) {
F_10 ( & V_36 ) ;
F_17 ( 1 ) ;
return;
}
V_2 -> V_42 -- ;
if ( ! V_2 -> V_42 && V_2 -> V_43 )
F_9 ( V_2 , 0 ) ;
F_10 ( & V_36 ) ;
}
static unsigned int F_18 ( struct V_7 * V_8 , unsigned int V_60 )
{
return V_61 ;
}
static inline int F_19 ( struct V_1 * V_2 )
{
return F_20 ( V_2 -> V_13 , 1 , 6 ) ;
}
static inline int F_21 ( struct V_1 * V_2 , int V_62 )
{
return F_20 ( V_2 -> V_13 , 0 , V_62 ) ;
}
static inline void F_22 ( struct V_1 * V_2 , int V_62 , int V_63 )
{
F_23 ( V_2 -> V_13 , 0 , V_62 , V_63 ) ;
}
static int F_24 ( struct V_1 * V_2 , int V_64 , int V_65 , char * V_66 , char * V_67 )
{
int V_68 , V_69 , V_70 , V_71 , V_72 ;
V_68 = 0 ;
while ( ( ( ( V_69 = F_19 ( V_2 ) ) & V_64 ) || ( V_65 && ( ! ( V_69 & V_65 ) ) ) )
&& ( V_68 ++ < V_73 ) )
F_25 ( V_74 ) ;
if ( ( V_69 & ( V_75 & V_65 ) ) || ( V_68 > V_73 ) ) {
V_71 = F_21 ( V_2 , 7 ) ;
V_70 = F_21 ( V_2 , 1 ) ;
V_72 = F_21 ( V_2 , 2 ) ;
if ( V_68 > V_73 )
V_70 |= 0x100 ;
if ( V_66 )
F_26 ( L_2
L_3 ,
V_2 -> V_22 , V_66 , V_67 , V_69 , V_71 , V_70 , V_68 , V_72 ) ;
return ( V_70 << 8 ) + V_71 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , char * V_55 , int V_76 , char * V_66 )
{
F_28 ( V_2 -> V_13 ) ;
F_22 ( V_2 , 6 , 0xa0 + 0x10 * V_2 -> V_17 ) ;
if ( F_24 ( V_2 , V_77 | V_78 , 0 , V_66 , L_4 ) ) {
F_29 ( V_2 -> V_13 ) ;
return - 1 ;
}
F_22 ( V_2 , 4 , V_76 % 256 ) ;
F_22 ( V_2 , 5 , V_76 / 256 ) ;
F_22 ( V_2 , 7 , 0xa0 ) ;
if ( F_24 ( V_2 , V_77 , V_78 , V_66 , L_5 ) ) {
F_29 ( V_2 -> V_13 ) ;
return - 1 ;
}
if ( F_21 ( V_2 , 2 ) != 1 ) {
F_26 ( L_6 , V_2 -> V_22 , V_66 ) ;
F_29 ( V_2 -> V_13 ) ;
return - 1 ;
}
F_30 ( V_2 -> V_13 , V_55 , 12 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , char * V_79 , char * V_66 )
{
int V_69 , V_71 , V_80 ;
V_69 = F_24 ( V_2 , V_77 , V_78 | V_81 | V_75 ,
V_66 , L_7 ) ;
if ( ( F_21 ( V_2 , 2 ) & 2 ) && ( F_21 ( V_2 , 7 ) & V_78 ) ) {
V_80 = ( ( ( F_21 ( V_2 , 4 ) + 256 * F_21 ( V_2 , 5 ) ) +
3 ) & 0xfffc ) ;
F_32 ( V_2 -> V_13 , V_79 , V_80 ) ;
}
V_71 = F_24 ( V_2 , V_77 , V_81 | V_75 , V_66 , L_8 ) ;
F_29 ( V_2 -> V_13 ) ;
return ( V_69 ? V_69 : V_71 ) ;
}
static void F_33 ( struct V_1 * V_2 , int V_82 )
{
char V_83 [ 12 ] =
{ V_84 , V_2 -> V_20 << 5 , 0 , 0 , 16 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
char V_79 [ 16 ] ;
int V_69 ;
V_69 = F_27 ( V_2 , V_83 , 16 , L_9 ) ;
F_34 ( 1 ) ;
if ( ! V_69 )
F_31 ( V_2 , V_79 , L_9 ) ;
if ( ( ! V_69 ) && ( ! V_82 ) )
F_26 ( L_10 ,
V_2 -> V_22 , V_79 [ 2 ] & 0xf , V_79 [ 12 ] , V_79 [ 13 ] ) ;
}
static int F_35 ( struct V_1 * V_2 , char * V_55 , int V_76 , char * V_79 , char * V_66 )
{
int V_69 ;
V_69 = F_27 ( V_2 , V_55 , V_76 , V_66 ) ;
F_34 ( 1 ) ;
if ( ! V_69 )
V_69 = F_31 ( V_2 , V_79 , V_66 ) ;
if ( V_69 )
F_33 ( V_2 , ! V_66 ) ;
return V_69 ;
}
static void F_9 ( struct V_1 * V_2 , int V_85 )
{
char V_86 [ 12 ] = { V_87 , V_2 -> V_20 << 5 , 0 , 0 , V_85 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
F_35 ( V_2 , V_86 , 0 , V_88 , V_85 ? L_11 : L_12 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
char V_89 [ 12 ] = { V_90 , V_2 -> V_20 << 5 , 0 , 0 , 2 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
F_9 ( V_2 , 0 ) ;
F_35 ( V_2 , V_89 , 0 , V_88 , L_13 ) ;
}
static void F_36 ( int V_91 )
{
F_37 ( V_91 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
int V_92 , V_93 , V_94 ;
int V_95 [ 5 ] = { 1 , 1 , 1 , 0x14 , 0xeb } ;
F_28 ( V_2 -> V_13 ) ;
F_22 ( V_2 , 6 , 0xa0 + 0x10 * V_2 -> V_17 ) ;
F_22 ( V_2 , 7 , 8 ) ;
F_36 ( 20 * V_96 / 1000 ) ;
V_93 = 0 ;
while ( ( V_93 ++ < V_97 ) && ( F_19 ( V_2 ) & V_77 ) )
F_36 ( V_96 / 10 ) ;
V_94 = 1 ;
for ( V_92 = 0 ; V_92 < 5 ; V_92 ++ )
V_94 &= ( F_21 ( V_2 , V_92 + 1 ) == V_95 [ V_92 ] ) ;
if ( V_98 ) {
F_26 ( L_14 , V_2 -> V_22 , V_93 ) ;
for ( V_92 = 0 ; V_92 < 5 ; V_92 ++ )
F_26 ( L_15 , F_21 ( V_2 , V_92 + 1 ) ) ;
if ( ! V_94 )
F_26 ( L_16 ) ;
F_26 ( L_17 ) ;
}
F_29 ( V_2 -> V_13 ) ;
return V_94 - 1 ;
}
static void F_39 ( struct V_1 * V_2 )
{
char V_99 [ 12 ] =
{ V_100 , V_2 -> V_20 << 5 , 0 , 0 , 0 , 0 , 0 , 0 , 8 , 0 , 0 , 0 } ;
char V_79 [ 8 ] ;
F_35 ( V_2 , V_99 , 8 , V_79 , L_18 ) ;
V_2 -> V_15 = V_101 ;
if ( V_79 [ 3 ] & 0x80 )
V_2 -> V_15 = V_40 ;
}
static void F_40 ( char * V_79 , char * V_102 , int V_103 , int V_104 )
{
int V_68 , V_93 , V_105 ;
V_68 = 0 ;
V_105 = 0 ;
for ( V_93 = 0 ; V_93 < V_104 ; V_93 ++ )
if ( ( V_79 [ V_93 + V_103 ] != 0x20 ) || ( V_79 [ V_93 + V_103 ] != V_105 ) )
V_105 = V_102 [ V_68 ++ ] = V_79 [ V_93 + V_103 ] ;
if ( V_105 == 0x20 )
V_68 -- ;
V_102 [ V_68 ] = 0 ;
}
static int F_41 ( char * V_79 , int V_103 )
{
int V_106 , V_93 ;
V_106 = 0 ;
for ( V_93 = 0 ; V_93 < 4 ; V_93 ++ )
V_106 = V_106 * 256 + ( V_79 [ V_93 + V_103 ] & 0xff ) ;
return V_106 ;
}
static void F_42 ( struct V_1 * V_2 )
{
char V_107 [ 12 ] = { V_108 , V_2 -> V_20 << 5 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
char V_79 [ 8 ] ;
int V_109 ;
if ( F_35 ( V_2 , V_107 , 8 , V_79 , L_19 ) ) {
V_2 -> V_15 = V_16 ;
return;
}
F_43 ( V_2 -> V_8 , F_41 ( V_79 , 0 ) + 1 ) ;
V_109 = F_41 ( V_79 , 4 ) ;
if ( V_109 != 512 ) {
F_43 ( V_2 -> V_8 , 0 ) ;
if ( V_98 )
F_26 ( L_20
L_21 ,
V_2 -> V_22 , V_2 -> V_17 , V_2 -> V_20 , V_109 ) ;
}
}
static int F_8 ( struct V_1 * V_2 )
{
int V_110 , V_71 ;
char * V_111 [ 2 ] = { L_22 , L_23 } ;
char V_112 [ 10 ] , V_113 [ 18 ] ;
char V_114 [ 12 ] =
{ V_115 , V_2 -> V_20 << 5 , 0 , 0 , 36 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
char V_79 [ 36 ] ;
V_71 = F_35 ( V_2 , V_114 , 36 , V_79 , L_24 ) ;
if ( V_71 )
return - 1 ;
V_110 = V_79 [ 0 ] & 0x1f ;
if ( ( V_110 != 0 ) && ( V_110 != 7 ) ) {
if ( V_98 )
F_26 ( L_25 ,
V_2 -> V_22 , V_2 -> V_17 , V_2 -> V_20 , V_110 ) ;
return - 1 ;
}
F_40 ( V_79 , V_112 , 8 , 8 ) ;
F_40 ( V_79 , V_113 , 16 , 16 ) ;
V_2 -> V_43 = ( V_79 [ 1 ] & 0x80 ) ;
F_39 ( V_2 ) ;
F_39 ( V_2 ) ;
F_39 ( V_2 ) ;
F_42 ( V_2 ) ;
F_26 ( L_26 ,
V_2 -> V_22 , V_112 , V_113 , V_111 [ V_2 -> V_17 ] , V_2 -> V_20 , V_110 ) ;
if ( V_2 -> V_43 )
F_26 ( L_27 ) ;
if ( V_2 -> V_15 == V_16 )
F_26 ( L_28 ) ;
else {
if ( V_2 -> V_15 == V_40 )
F_26 ( L_29 ) ;
F_26 ( L_30 ,
( unsigned long long ) F_12 ( V_2 -> V_8 ) ) ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
if ( V_2 -> V_17 == - 1 ) {
for ( V_2 -> V_17 = 0 ; V_2 -> V_17 <= 1 ; V_2 -> V_17 ++ )
if ( ! F_38 ( V_2 ) ) {
if ( V_2 -> V_20 != - 1 )
return F_8 ( V_2 ) ;
else
for ( V_2 -> V_20 = 0 ; V_2 -> V_20 < 8 ; V_2 -> V_20 ++ )
if ( ! F_8 ( V_2 ) )
return 0 ;
}
} else {
if ( F_38 ( V_2 ) )
return - 1 ;
if ( V_2 -> V_20 != - 1 )
return F_8 ( V_2 ) ;
for ( V_2 -> V_20 = 0 ; V_2 -> V_20 < 8 ; V_2 -> V_20 ++ )
if ( ! F_8 ( V_2 ) )
return 0 ;
}
return - 1 ;
}
static int F_45 ( void )
{
struct V_1 * V_2 = V_5 ;
int V_93 , V_3 ;
F_26 ( L_31 ,
V_22 , V_22 , V_116 , V_24 , V_12 , V_117 ) ;
V_118 = F_46 ( V_22 ) ;
if ( ! V_118 ) {
F_47 ( L_32 , V_22 ) ;
return - 1 ;
}
V_93 = 0 ;
if ( V_4 == 0 ) {
if ( F_48 ( V_2 -> V_13 , 1 , - 1 , - 1 , - 1 , - 1 , - 1 , V_88 , V_119 ,
V_98 , V_2 -> V_22 ) ) {
if ( ! F_44 ( V_2 ) && V_2 -> V_8 ) {
V_2 -> V_120 = 1 ;
V_93 ++ ;
} else
F_49 ( V_2 -> V_13 ) ;
}
} else
for ( V_3 = 0 ; V_3 < V_6 ; V_3 ++ , V_2 ++ ) {
int * V_121 = * V_18 [ V_3 ] ;
if ( ! V_121 [ V_29 ] )
continue;
if ( F_48 ( V_2 -> V_13 , 0 , V_121 [ V_29 ] , V_121 [ V_122 ] ,
V_121 [ V_123 ] , V_121 [ V_124 ] , V_121 [ V_125 ] ,
V_88 , V_119 , V_98 , V_2 -> V_22 ) ) {
if ( V_2 -> V_8 && ! F_44 ( V_2 ) ) {
V_2 -> V_120 = 1 ;
V_93 ++ ;
} else
F_49 ( V_2 -> V_13 ) ;
}
}
if ( V_93 )
return 0 ;
F_26 ( L_33 , V_22 ) ;
for ( V_2 = V_5 , V_3 = 0 ; V_3 < V_6 ; V_2 ++ , V_3 ++ )
F_4 ( V_2 -> V_8 ) ;
F_50 ( V_118 ) ;
return - 1 ;
}
static int F_51 ( struct V_1 * V_2 , int V_55 , int V_126 , int V_127 )
{
int V_92 ;
char V_128 [ 12 ] = { V_55 , V_2 -> V_20 << 5 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
for ( V_92 = 0 ; V_92 < 4 ; V_92 ++ ) {
V_128 [ 5 - V_92 ] = V_126 & 0xff ;
V_126 = V_126 >> 8 ;
}
V_128 [ 8 ] = V_127 & 0xff ;
V_128 [ 7 ] = ( V_127 >> 8 ) & 0xff ;
V_92 = F_27 ( V_2 , V_128 , V_127 * 512 , L_34 ) ;
F_34 ( 1 ) ;
return V_92 ;
}
static int F_52 ( void )
{
return ( ( ( F_19 ( V_129 ) & ( V_77 | V_130 ) ) == V_130 ) ) ;
}
static int F_53 ( void )
{
struct V_1 * V_2 ;
struct V_131 * V_132 ;
int V_133 = V_134 ;
do {
V_2 = & V_5 [ V_134 ] ;
V_132 = V_2 -> V_120 ? V_2 -> V_8 -> V_9 : NULL ;
if ( ++ V_134 == V_6 )
V_134 = 0 ;
if ( V_132 ) {
V_135 = F_54 ( V_132 ) ;
if ( V_135 )
break;
}
} while ( V_134 != V_133 );
return V_135 != NULL ;
}
static void F_55 ( int V_136 )
{
if ( V_135 && ! F_56 ( V_135 , V_136 ) )
V_135 = NULL ;
}
static void F_57 ( void )
{
if ( V_137 )
return;
V_138:
if ( ! V_135 && ! F_53 () )
return;
V_129 = V_135 -> V_139 -> V_34 ;
V_140 = F_58 ( V_135 ) ;
V_141 = F_59 ( V_135 ) ;
V_142 = F_60 ( V_135 ) ;
if ( V_140 + V_142 > F_12 ( V_135 -> V_139 ) ) {
F_55 ( - V_143 ) ;
goto V_138;
}
V_144 = F_61 ( V_135 ) ;
V_145 = F_62 ( V_135 -> V_146 ) ;
V_147 = 0 ;
V_137 = 1 ;
if ( V_144 == V_148 )
F_63 ( V_129 -> V_13 , V_149 ) ;
else if ( V_144 == V_150 )
F_63 ( V_129 -> V_13 , V_151 ) ;
else {
V_137 = 0 ;
F_55 ( - V_143 ) ;
goto V_138;
}
}
static void V_10 ( struct V_131 * V_132 )
{
F_57 () ;
}
static int F_64 ( void )
{
unsigned long V_152 ;
V_142 -- ;
V_141 -- ;
V_145 += 512 ;
V_140 ++ ;
if ( ! V_141 )
return 1 ;
if ( ! V_142 ) {
F_65 ( & V_11 , V_152 ) ;
F_55 ( 0 ) ;
F_66 ( & V_11 , V_152 ) ;
if ( ! V_135 )
return 1 ;
V_142 = F_60 ( V_135 ) ;
V_145 = F_62 ( V_135 -> V_146 ) ;
}
return 0 ;
}
static inline void F_67 ( int V_136 )
{
unsigned long V_152 ;
F_65 ( & V_11 , V_152 ) ;
F_55 ( V_136 ) ;
V_137 = 0 ;
F_57 () ;
F_66 ( & V_11 , V_152 ) ;
}
static void V_149 ( void )
{
F_68 ( V_153 , NULL , 0 , V_117 ) ;
}
static void V_153 ( void )
{
V_137 = 1 ;
if ( F_51 ( V_129 , V_154 , V_140 , V_141 ) ) {
F_29 ( V_129 -> V_13 ) ;
if ( V_147 < V_155 ) {
V_147 ++ ;
F_63 ( V_129 -> V_13 , V_153 ) ;
return;
}
F_67 ( - V_143 ) ;
return;
}
V_130 = V_78 ;
F_68 ( V_156 , F_52 , V_157 , V_117 ) ;
}
static void V_156 ( void )
{
while ( 1 ) {
if ( F_24 ( V_129 , V_77 , V_78 | V_75 ,
L_35 , L_7 ) & V_75 ) {
F_29 ( V_129 -> V_13 ) ;
if ( V_147 < V_155 ) {
F_33 ( V_129 , 0 ) ;
V_147 ++ ;
F_63 ( V_129 -> V_13 , V_153 ) ;
return;
}
F_67 ( - V_143 ) ;
return;
}
F_32 ( V_129 -> V_13 , V_145 , 512 ) ;
if ( F_64 () )
break;
}
F_29 ( V_129 -> V_13 ) ;
F_67 ( 0 ) ;
}
static void V_151 ( void )
{
F_68 ( V_158 , NULL , 0 , V_117 ) ;
}
static void V_158 ( void )
{
V_137 = 1 ;
if ( F_51 ( V_129 , V_159 , V_140 , V_141 ) ) {
F_29 ( V_129 -> V_13 ) ;
if ( V_147 < V_155 ) {
V_147 ++ ;
F_63 ( V_129 -> V_13 , V_158 ) ;
return;
}
F_67 ( - V_143 ) ;
return;
}
while ( 1 ) {
if ( F_24 ( V_129 , V_77 , V_78 | V_75 ,
L_36 , L_37 ) & V_75 ) {
F_29 ( V_129 -> V_13 ) ;
if ( V_147 < V_155 ) {
V_147 ++ ;
F_63 ( V_129 -> V_13 , V_158 ) ;
return;
}
F_67 ( - V_143 ) ;
return;
}
F_30 ( V_129 -> V_13 , V_145 , 512 ) ;
if ( F_64 () )
break;
}
V_130 = 0 ;
F_68 ( V_160 , F_52 , V_157 , V_117 ) ;
}
static void V_160 ( void )
{
if ( F_24 ( V_129 , V_77 , 0 , L_36 , L_38 ) & V_75 ) {
F_29 ( V_129 -> V_13 ) ;
if ( V_147 < V_155 ) {
V_147 ++ ;
F_63 ( V_129 -> V_13 , V_158 ) ;
return;
}
F_67 ( - V_143 ) ;
return;
}
F_29 ( V_129 -> V_13 ) ;
F_67 ( 0 ) ;
}
static int T_1 F_69 ( void )
{
struct V_1 * V_2 ;
int V_3 ;
if ( V_161 )
return - V_58 ;
F_1 () ;
if ( F_45 () )
return - V_37 ;
V_137 = 0 ;
if ( F_70 ( V_24 , V_22 ) ) {
for ( V_2 = V_5 , V_3 = 0 ; V_3 < V_6 ; V_2 ++ , V_3 ++ )
F_4 ( V_2 -> V_8 ) ;
return - V_59 ;
}
for ( V_2 = V_5 , V_3 = 0 ; V_3 < V_6 ; V_2 ++ , V_3 ++ ) {
struct V_7 * V_8 = V_2 -> V_8 ;
if ( ! V_2 -> V_120 )
continue;
V_8 -> V_34 = V_2 ;
F_71 ( V_8 ) ;
}
return 0 ;
}
static void T_4 F_72 ( void )
{
struct V_1 * V_2 ;
int V_3 ;
F_73 ( V_24 , V_22 ) ;
for ( V_2 = V_5 , V_3 = 0 ; V_3 < V_6 ; V_2 ++ , V_3 ++ ) {
if ( ! V_2 -> V_120 )
continue;
F_74 ( V_2 -> V_8 ) ;
F_75 ( V_2 -> V_8 -> V_9 ) ;
F_4 ( V_2 -> V_8 ) ;
F_49 ( V_2 -> V_13 ) ;
}
}
