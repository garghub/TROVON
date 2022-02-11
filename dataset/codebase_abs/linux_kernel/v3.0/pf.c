static void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
int V_3 ;
V_4 = 0 ;
for ( V_3 = 0 , V_2 = V_5 ; V_3 < V_6 ; V_3 ++ , V_2 ++ ) {
struct V_7 * V_8 = F_2 ( 1 ) ;
if ( ! V_8 )
continue;
V_2 -> V_8 = V_8 ;
V_2 -> V_9 = & V_2 -> V_10 ;
V_2 -> V_11 = V_12 ;
V_2 -> V_13 = ( * V_14 [ V_3 ] ) [ V_15 ] ;
V_2 -> V_16 = ( * V_14 [ V_3 ] ) [ V_17 ] ;
snprintf ( V_2 -> V_18 , V_19 , L_1 , V_18 , V_3 ) ;
V_8 -> V_20 = V_20 ;
V_8 -> V_21 = V_3 ;
strcpy ( V_8 -> V_22 , V_2 -> V_18 ) ;
V_8 -> V_23 = & V_24 ;
if ( ! ( * V_14 [ V_3 ] ) [ V_25 ] )
V_4 ++ ;
}
}
static int F_3 ( struct V_26 * V_27 , T_2 V_28 )
{
struct V_1 * V_2 = V_27 -> V_29 -> V_30 ;
int V_31 ;
F_4 ( & V_32 ) ;
F_5 ( V_2 ) ;
V_31 = - V_33 ;
if ( V_2 -> V_11 == V_12 )
goto V_34;
V_31 = - V_35 ;
if ( ( V_2 -> V_11 == V_36 ) && ( V_28 & V_37 ) )
goto V_34;
V_31 = 0 ;
V_2 -> V_38 ++ ;
if ( V_2 -> V_39 )
F_6 ( V_2 , 1 ) ;
V_34:
F_7 ( & V_32 ) ;
return V_31 ;
}
static int F_8 ( struct V_26 * V_27 , struct V_40 * V_41 )
{
struct V_1 * V_2 = V_27 -> V_29 -> V_30 ;
T_3 V_42 = F_9 ( V_2 -> V_8 ) ;
if ( V_42 < V_43 ) {
V_41 -> V_44 = F_10 ( V_42 , V_45 * V_46 ) ;
V_41 -> V_47 = V_45 ;
V_41 -> V_48 = V_46 ;
} else {
V_41 -> V_44 = F_10 ( V_42 , V_49 * V_50 ) ;
V_41 -> V_47 = V_49 ;
V_41 -> V_48 = V_50 ;
}
return 0 ;
}
static int F_11 ( struct V_26 * V_27 , T_2 V_28 , unsigned int V_51 , unsigned long V_52 )
{
struct V_1 * V_2 = V_27 -> V_29 -> V_30 ;
if ( V_51 != V_53 )
return - V_54 ;
if ( V_2 -> V_38 != 1 )
return - V_55 ;
F_4 ( & V_32 ) ;
F_12 ( V_2 ) ;
F_7 ( & V_32 ) ;
return 0 ;
}
static int F_13 ( struct V_7 * V_8 , T_2 V_28 )
{
struct V_1 * V_2 = V_8 -> V_30 ;
F_4 ( & V_32 ) ;
if ( V_2 -> V_38 <= 0 ) {
F_7 ( & V_32 ) ;
return - V_54 ;
}
V_2 -> V_38 -- ;
if ( ! V_2 -> V_38 && V_2 -> V_39 )
F_6 ( V_2 , 0 ) ;
F_7 ( & V_32 ) ;
return 0 ;
}
static unsigned int F_14 ( struct V_7 * V_8 , unsigned int V_56 )
{
return V_57 ;
}
static inline int F_15 ( struct V_1 * V_2 )
{
return F_16 ( V_2 -> V_9 , 1 , 6 ) ;
}
static inline int F_17 ( struct V_1 * V_2 , int V_58 )
{
return F_16 ( V_2 -> V_9 , 0 , V_58 ) ;
}
static inline void F_18 ( struct V_1 * V_2 , int V_58 , int V_59 )
{
F_19 ( V_2 -> V_9 , 0 , V_58 , V_59 ) ;
}
static int F_20 ( struct V_1 * V_2 , int V_60 , int V_61 , char * V_62 , char * V_63 )
{
int V_64 , V_65 , V_66 , V_67 , V_68 ;
V_64 = 0 ;
while ( ( ( ( V_65 = F_15 ( V_2 ) ) & V_60 ) || ( V_61 && ( ! ( V_65 & V_61 ) ) ) )
&& ( V_64 ++ < V_69 ) )
F_21 ( V_70 ) ;
if ( ( V_65 & ( V_71 & V_61 ) ) || ( V_64 > V_69 ) ) {
V_67 = F_17 ( V_2 , 7 ) ;
V_66 = F_17 ( V_2 , 1 ) ;
V_68 = F_17 ( V_2 , 2 ) ;
if ( V_64 > V_69 )
V_66 |= 0x100 ;
if ( V_62 )
F_22 ( L_2
L_3 ,
V_2 -> V_18 , V_62 , V_63 , V_65 , V_67 , V_66 , V_64 , V_68 ) ;
return ( V_66 << 8 ) + V_67 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , char * V_51 , int V_72 , char * V_62 )
{
F_24 ( V_2 -> V_9 ) ;
F_18 ( V_2 , 6 , 0xa0 + 0x10 * V_2 -> V_13 ) ;
if ( F_20 ( V_2 , V_73 | V_74 , 0 , V_62 , L_4 ) ) {
F_25 ( V_2 -> V_9 ) ;
return - 1 ;
}
F_18 ( V_2 , 4 , V_72 % 256 ) ;
F_18 ( V_2 , 5 , V_72 / 256 ) ;
F_18 ( V_2 , 7 , 0xa0 ) ;
if ( F_20 ( V_2 , V_73 , V_74 , V_62 , L_5 ) ) {
F_25 ( V_2 -> V_9 ) ;
return - 1 ;
}
if ( F_17 ( V_2 , 2 ) != 1 ) {
F_22 ( L_6 , V_2 -> V_18 , V_62 ) ;
F_25 ( V_2 -> V_9 ) ;
return - 1 ;
}
F_26 ( V_2 -> V_9 , V_51 , 12 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , char * V_75 , char * V_62 )
{
int V_65 , V_67 , V_76 ;
V_65 = F_20 ( V_2 , V_73 , V_74 | V_77 | V_71 ,
V_62 , L_7 ) ;
if ( ( F_17 ( V_2 , 2 ) & 2 ) && ( F_17 ( V_2 , 7 ) & V_74 ) ) {
V_76 = ( ( ( F_17 ( V_2 , 4 ) + 256 * F_17 ( V_2 , 5 ) ) +
3 ) & 0xfffc ) ;
F_28 ( V_2 -> V_9 , V_75 , V_76 ) ;
}
V_67 = F_20 ( V_2 , V_73 , V_77 | V_71 , V_62 , L_8 ) ;
F_25 ( V_2 -> V_9 ) ;
return ( V_65 ? V_65 : V_67 ) ;
}
static void F_29 ( struct V_1 * V_2 , int V_78 )
{
char V_79 [ 12 ] =
{ V_80 , V_2 -> V_16 << 5 , 0 , 0 , 16 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
char V_75 [ 16 ] ;
int V_65 ;
V_65 = F_23 ( V_2 , V_79 , 16 , L_9 ) ;
F_30 ( 1 ) ;
if ( ! V_65 )
F_27 ( V_2 , V_75 , L_9 ) ;
if ( ( ! V_65 ) && ( ! V_78 ) )
F_22 ( L_10 ,
V_2 -> V_18 , V_75 [ 2 ] & 0xf , V_75 [ 12 ] , V_75 [ 13 ] ) ;
}
static int F_31 ( struct V_1 * V_2 , char * V_51 , int V_72 , char * V_75 , char * V_62 )
{
int V_65 ;
V_65 = F_23 ( V_2 , V_51 , V_72 , V_62 ) ;
F_30 ( 1 ) ;
if ( ! V_65 )
V_65 = F_27 ( V_2 , V_75 , V_62 ) ;
if ( V_65 )
F_29 ( V_2 , ! V_62 ) ;
return V_65 ;
}
static void F_6 ( struct V_1 * V_2 , int V_81 )
{
char V_82 [ 12 ] = { V_83 , V_2 -> V_16 << 5 , 0 , 0 , V_81 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
F_31 ( V_2 , V_82 , 0 , V_84 , V_81 ? L_11 : L_12 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
char V_85 [ 12 ] = { V_86 , V_2 -> V_16 << 5 , 0 , 0 , 2 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
F_6 ( V_2 , 0 ) ;
F_31 ( V_2 , V_85 , 0 , V_84 , L_13 ) ;
}
static void F_32 ( int V_87 )
{
F_33 ( V_87 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_88 , V_89 , V_90 ;
int V_91 [ 5 ] = { 1 , 1 , 1 , 0x14 , 0xeb } ;
F_24 ( V_2 -> V_9 ) ;
F_18 ( V_2 , 6 , 0xa0 + 0x10 * V_2 -> V_13 ) ;
F_18 ( V_2 , 7 , 8 ) ;
F_32 ( 20 * V_92 / 1000 ) ;
V_89 = 0 ;
while ( ( V_89 ++ < V_93 ) && ( F_15 ( V_2 ) & V_73 ) )
F_32 ( V_92 / 10 ) ;
V_90 = 1 ;
for ( V_88 = 0 ; V_88 < 5 ; V_88 ++ )
V_90 &= ( F_17 ( V_2 , V_88 + 1 ) == V_91 [ V_88 ] ) ;
if ( V_94 ) {
F_22 ( L_14 , V_2 -> V_18 , V_89 ) ;
for ( V_88 = 0 ; V_88 < 5 ; V_88 ++ )
F_22 ( L_15 , F_17 ( V_2 , V_88 + 1 ) ) ;
if ( ! V_90 )
F_22 ( L_16 ) ;
F_22 ( L_17 ) ;
}
F_25 ( V_2 -> V_9 ) ;
return V_90 - 1 ;
}
static void F_35 ( struct V_1 * V_2 )
{
char V_95 [ 12 ] =
{ V_96 , V_2 -> V_16 << 5 , 0 , 0 , 0 , 0 , 0 , 0 , 8 , 0 , 0 , 0 } ;
char V_75 [ 8 ] ;
F_31 ( V_2 , V_95 , 8 , V_75 , L_18 ) ;
V_2 -> V_11 = V_97 ;
if ( V_75 [ 3 ] & 0x80 )
V_2 -> V_11 = V_36 ;
}
static void F_36 ( char * V_75 , char * V_98 , int V_99 , int V_100 )
{
int V_64 , V_89 , V_101 ;
V_64 = 0 ;
V_101 = 0 ;
for ( V_89 = 0 ; V_89 < V_100 ; V_89 ++ )
if ( ( V_75 [ V_89 + V_99 ] != 0x20 ) || ( V_75 [ V_89 + V_99 ] != V_101 ) )
V_101 = V_98 [ V_64 ++ ] = V_75 [ V_89 + V_99 ] ;
if ( V_101 == 0x20 )
V_64 -- ;
V_98 [ V_64 ] = 0 ;
}
static int F_37 ( char * V_75 , int V_99 )
{
int V_102 , V_89 ;
V_102 = 0 ;
for ( V_89 = 0 ; V_89 < 4 ; V_89 ++ )
V_102 = V_102 * 256 + ( V_75 [ V_89 + V_99 ] & 0xff ) ;
return V_102 ;
}
static void F_38 ( struct V_1 * V_2 )
{
char V_103 [ 12 ] = { V_104 , V_2 -> V_16 << 5 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
char V_75 [ 8 ] ;
int V_105 ;
if ( F_31 ( V_2 , V_103 , 8 , V_75 , L_19 ) ) {
V_2 -> V_11 = V_12 ;
return;
}
F_39 ( V_2 -> V_8 , F_37 ( V_75 , 0 ) + 1 ) ;
V_105 = F_37 ( V_75 , 4 ) ;
if ( V_105 != 512 ) {
F_39 ( V_2 -> V_8 , 0 ) ;
if ( V_94 )
F_22 ( L_20
L_21 ,
V_2 -> V_18 , V_2 -> V_13 , V_2 -> V_16 , V_105 ) ;
}
}
static int F_5 ( struct V_1 * V_2 )
{
int V_106 , V_67 ;
char * V_107 [ 2 ] = { L_22 , L_23 } ;
char V_108 [ 10 ] , V_109 [ 18 ] ;
char V_110 [ 12 ] =
{ V_111 , V_2 -> V_16 << 5 , 0 , 0 , 36 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
char V_75 [ 36 ] ;
V_67 = F_31 ( V_2 , V_110 , 36 , V_75 , L_24 ) ;
if ( V_67 )
return - 1 ;
V_106 = V_75 [ 0 ] & 0x1f ;
if ( ( V_106 != 0 ) && ( V_106 != 7 ) ) {
if ( V_94 )
F_22 ( L_25 ,
V_2 -> V_18 , V_2 -> V_13 , V_2 -> V_16 , V_106 ) ;
return - 1 ;
}
F_36 ( V_75 , V_108 , 8 , 8 ) ;
F_36 ( V_75 , V_109 , 16 , 16 ) ;
V_2 -> V_39 = ( V_75 [ 1 ] & 0x80 ) ;
F_35 ( V_2 ) ;
F_35 ( V_2 ) ;
F_35 ( V_2 ) ;
F_38 ( V_2 ) ;
F_22 ( L_26 ,
V_2 -> V_18 , V_108 , V_109 , V_107 [ V_2 -> V_13 ] , V_2 -> V_16 , V_106 ) ;
if ( V_2 -> V_39 )
F_22 ( L_27 ) ;
if ( V_2 -> V_11 == V_12 )
F_22 ( L_28 ) ;
else {
if ( V_2 -> V_11 == V_36 )
F_22 ( L_29 ) ;
F_22 ( L_30 ,
( unsigned long long ) F_9 ( V_2 -> V_8 ) ) ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 == - 1 ) {
for ( V_2 -> V_13 = 0 ; V_2 -> V_13 <= 1 ; V_2 -> V_13 ++ )
if ( ! F_34 ( V_2 ) ) {
if ( V_2 -> V_16 != - 1 )
return F_5 ( V_2 ) ;
else
for ( V_2 -> V_16 = 0 ; V_2 -> V_16 < 8 ; V_2 -> V_16 ++ )
if ( ! F_5 ( V_2 ) )
return 0 ;
}
} else {
if ( F_34 ( V_2 ) )
return - 1 ;
if ( V_2 -> V_16 != - 1 )
return F_5 ( V_2 ) ;
for ( V_2 -> V_16 = 0 ; V_2 -> V_16 < 8 ; V_2 -> V_16 ++ )
if ( ! F_5 ( V_2 ) )
return 0 ;
}
return - 1 ;
}
static int F_41 ( void )
{
struct V_1 * V_2 = V_5 ;
int V_89 , V_3 ;
F_22 ( L_31 ,
V_18 , V_18 , V_112 , V_20 , V_113 , V_114 ) ;
V_89 = 0 ;
if ( V_4 == 0 ) {
if ( F_42 ( V_2 -> V_9 , 1 , - 1 , - 1 , - 1 , - 1 , - 1 , V_84 , V_115 ,
V_94 , V_2 -> V_18 ) ) {
if ( ! F_40 ( V_2 ) && V_2 -> V_8 ) {
V_2 -> V_116 = 1 ;
V_89 ++ ;
} else
F_43 ( V_2 -> V_9 ) ;
}
} else
for ( V_3 = 0 ; V_3 < V_6 ; V_3 ++ , V_2 ++ ) {
int * V_117 = * V_14 [ V_3 ] ;
if ( ! V_117 [ V_25 ] )
continue;
if ( F_42 ( V_2 -> V_9 , 0 , V_117 [ V_25 ] , V_117 [ V_118 ] ,
V_117 [ V_119 ] , V_117 [ V_120 ] , V_117 [ V_121 ] ,
V_84 , V_115 , V_94 , V_2 -> V_18 ) ) {
if ( V_2 -> V_8 && ! F_40 ( V_2 ) ) {
V_2 -> V_116 = 1 ;
V_89 ++ ;
} else
F_43 ( V_2 -> V_9 ) ;
}
}
if ( V_89 )
return 0 ;
F_22 ( L_32 , V_18 ) ;
for ( V_2 = V_5 , V_3 = 0 ; V_3 < V_6 ; V_2 ++ , V_3 ++ )
F_44 ( V_2 -> V_8 ) ;
return - 1 ;
}
static int F_45 ( struct V_1 * V_2 , int V_51 , int V_122 , int V_123 )
{
int V_88 ;
char V_124 [ 12 ] = { V_51 , V_2 -> V_16 << 5 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
for ( V_88 = 0 ; V_88 < 4 ; V_88 ++ ) {
V_124 [ 5 - V_88 ] = V_122 & 0xff ;
V_122 = V_122 >> 8 ;
}
V_124 [ 8 ] = V_123 & 0xff ;
V_124 [ 7 ] = ( V_123 >> 8 ) & 0xff ;
V_88 = F_23 ( V_2 , V_124 , V_123 * 512 , L_33 ) ;
F_30 ( 1 ) ;
return V_88 ;
}
static int F_46 ( void )
{
return ( ( ( F_15 ( V_125 ) & ( V_73 | V_126 ) ) == V_126 ) ) ;
}
static void F_47 ( int V_127 )
{
if ( V_128 && ! F_48 ( V_128 , V_127 ) )
V_128 = NULL ;
}
static void F_49 ( struct V_129 * V_130 )
{
if ( V_131 )
return;
V_132:
if ( ! V_128 ) {
V_128 = F_50 ( V_130 ) ;
if ( ! V_128 )
return;
}
V_125 = V_128 -> V_133 -> V_30 ;
V_134 = F_51 ( V_128 ) ;
V_135 = F_52 ( V_128 ) ;
V_136 = F_53 ( V_128 ) ;
if ( V_134 + V_136 > F_9 ( V_128 -> V_133 ) ) {
F_47 ( - V_137 ) ;
goto V_132;
}
V_138 = F_54 ( V_128 ) ;
V_139 = V_128 -> V_140 ;
V_141 = 0 ;
V_131 = 1 ;
if ( V_138 == V_142 )
F_55 ( V_125 -> V_9 , V_143 ) ;
else if ( V_138 == V_144 )
F_55 ( V_125 -> V_9 , V_145 ) ;
else {
V_131 = 0 ;
F_47 ( - V_137 ) ;
goto V_132;
}
}
static int F_56 ( void )
{
unsigned long V_146 ;
V_136 -- ;
V_135 -- ;
V_139 += 512 ;
V_134 ++ ;
if ( ! V_135 )
return 1 ;
if ( ! V_136 ) {
F_57 ( & V_147 , V_146 ) ;
F_47 ( 0 ) ;
F_58 ( & V_147 , V_146 ) ;
if ( ! V_128 )
return 1 ;
V_136 = F_53 ( V_128 ) ;
V_139 = V_128 -> V_140 ;
}
return 0 ;
}
static inline void F_59 ( int V_127 )
{
unsigned long V_146 ;
F_57 ( & V_147 , V_146 ) ;
F_47 ( V_127 ) ;
V_131 = 0 ;
F_49 ( V_148 ) ;
F_58 ( & V_147 , V_146 ) ;
}
static void V_143 ( void )
{
F_60 ( V_149 , NULL , 0 , V_114 ) ;
}
static void V_149 ( void )
{
V_131 = 1 ;
if ( F_45 ( V_125 , V_150 , V_134 , V_135 ) ) {
F_25 ( V_125 -> V_9 ) ;
if ( V_141 < V_151 ) {
V_141 ++ ;
F_55 ( V_125 -> V_9 , V_149 ) ;
return;
}
F_59 ( - V_137 ) ;
return;
}
V_126 = V_74 ;
F_60 ( V_152 , F_46 , V_153 , V_114 ) ;
}
static void V_152 ( void )
{
while ( 1 ) {
if ( F_20 ( V_125 , V_73 , V_74 | V_71 ,
L_34 , L_7 ) & V_71 ) {
F_25 ( V_125 -> V_9 ) ;
if ( V_141 < V_151 ) {
F_29 ( V_125 , 0 ) ;
V_141 ++ ;
F_55 ( V_125 -> V_9 , V_149 ) ;
return;
}
F_59 ( - V_137 ) ;
return;
}
F_28 ( V_125 -> V_9 , V_139 , 512 ) ;
if ( F_56 () )
break;
}
F_25 ( V_125 -> V_9 ) ;
F_59 ( 0 ) ;
}
static void V_145 ( void )
{
F_60 ( V_154 , NULL , 0 , V_114 ) ;
}
static void V_154 ( void )
{
V_131 = 1 ;
if ( F_45 ( V_125 , V_155 , V_134 , V_135 ) ) {
F_25 ( V_125 -> V_9 ) ;
if ( V_141 < V_151 ) {
V_141 ++ ;
F_55 ( V_125 -> V_9 , V_154 ) ;
return;
}
F_59 ( - V_137 ) ;
return;
}
while ( 1 ) {
if ( F_20 ( V_125 , V_73 , V_74 | V_71 ,
L_35 , L_36 ) & V_71 ) {
F_25 ( V_125 -> V_9 ) ;
if ( V_141 < V_151 ) {
V_141 ++ ;
F_55 ( V_125 -> V_9 , V_154 ) ;
return;
}
F_59 ( - V_137 ) ;
return;
}
F_26 ( V_125 -> V_9 , V_139 , 512 ) ;
if ( F_56 () )
break;
}
V_126 = 0 ;
F_60 ( V_156 , F_46 , V_153 , V_114 ) ;
}
static void V_156 ( void )
{
if ( F_20 ( V_125 , V_73 , 0 , L_35 , L_37 ) & V_71 ) {
F_25 ( V_125 -> V_9 ) ;
if ( V_141 < V_151 ) {
V_141 ++ ;
F_55 ( V_125 -> V_9 , V_154 ) ;
return;
}
F_59 ( - V_137 ) ;
return;
}
F_25 ( V_125 -> V_9 ) ;
F_59 ( 0 ) ;
}
static int T_1 F_61 ( void )
{
struct V_1 * V_2 ;
int V_3 ;
if ( V_157 )
return - V_54 ;
F_1 () ;
if ( F_41 () )
return - V_33 ;
V_131 = 0 ;
if ( F_62 ( V_20 , V_18 ) ) {
for ( V_2 = V_5 , V_3 = 0 ; V_3 < V_6 ; V_2 ++ , V_3 ++ )
F_44 ( V_2 -> V_8 ) ;
return - V_55 ;
}
V_148 = F_63 ( F_49 , & V_147 ) ;
if ( ! V_148 ) {
F_64 ( V_20 , V_18 ) ;
for ( V_2 = V_5 , V_3 = 0 ; V_3 < V_6 ; V_2 ++ , V_3 ++ )
F_44 ( V_2 -> V_8 ) ;
return - V_158 ;
}
F_65 ( V_148 , V_113 ) ;
for ( V_2 = V_5 , V_3 = 0 ; V_3 < V_6 ; V_2 ++ , V_3 ++ ) {
struct V_7 * V_8 = V_2 -> V_8 ;
if ( ! V_2 -> V_116 )
continue;
V_8 -> V_30 = V_2 ;
V_8 -> V_159 = V_148 ;
F_66 ( V_8 ) ;
}
return 0 ;
}
static void T_4 F_67 ( void )
{
struct V_1 * V_2 ;
int V_3 ;
F_64 ( V_20 , V_18 ) ;
for ( V_2 = V_5 , V_3 = 0 ; V_3 < V_6 ; V_2 ++ , V_3 ++ ) {
if ( ! V_2 -> V_116 )
continue;
F_68 ( V_2 -> V_8 ) ;
F_44 ( V_2 -> V_8 ) ;
F_43 ( V_2 -> V_9 ) ;
}
F_69 ( V_148 ) ;
}
