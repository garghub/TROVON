static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 L_1 ,
F_3 ( V_2 -> V_4 + V_5 ) , F_3 ( V_2 -> V_4 + V_6 ) ) ;
}
static void F_4 ( char * V_7 , void * V_8 , int V_9 )
{
unsigned char * V_10 = V_8 ;
int V_11 ;
F_2 ( V_7 ) ;
for ( V_11 = 0 ; V_11 < V_9 ; V_11 ++ ) {
if ( V_11 % 16 == 0 )
F_2 ( L_2 , V_10 ) ;
F_2 ( L_3 , * ( V_10 ++ ) ) ;
}
F_2 ( L_4 ) ;
}
static int F_5 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
if ( V_15 -> V_17 )
return - V_18 ;
F_6 ( V_19 , V_2 -> V_4 + V_20 ) ;
V_15 -> V_21 = V_22 ;
return 0 ;
}
static enum V_23 F_7 ( int V_24 , void * V_25 )
{
struct V_14 * V_15 = (struct V_14 * ) V_25 ;
struct V_1 * V_2 ;
struct V_12 * V_13 ;
int V_26 = 10000 ;
int V_27 ;
if ( V_15 == NULL ) {
F_2 ( V_28
L_5 , V_24 ) ;
return V_29 ;
}
V_2 = V_15 -> V_2 ;
if ( V_2 == NULL ) {
F_2 ( V_28 L_6 ) ;
return V_29 ;
}
if ( ! V_2 -> V_30 ) {
F_2 ( V_28
L_7 ) ;
return V_29 ;
}
V_13 = V_15 -> V_13 ;
if ( V_13 == NULL ) {
F_2 ( V_28
L_8 ) ;
return V_29 ;
}
if ( (struct V_14 * ) V_13 -> V_16 != V_15 ) {
F_2 ( V_28
L_9 ) ;
return V_29 ;
}
switch ( V_15 -> V_21 ) {
case V_22 :
F_8 ( & V_15 -> V_31 ) ;
break;
case V_32 :
while ( ! ( ( V_27 = F_3 ( V_2 -> V_4 + V_5 ) )
& V_33 ) ) {
short V_34 ;
if ( V_27 & V_35 ) {
V_13 -> V_36 -> V_37 |=
V_38 | V_39 ;
F_2 ( L_10 ) ;
F_5 ( V_2 , V_13 ) ;
break;
}
V_34 = F_3 ( V_2 -> V_4 + V_40 ) ;
V_34 |= F_3 ( V_2 -> V_4 + V_40 ) << 8 ;
V_34 ^= 0x8000 ;
F_9 ( V_13 -> V_36 , V_34 ) ;
if ( V_15 -> V_41 > 0 ) {
V_15 -> V_41 -- ;
if ( V_15 -> V_41 == 0 ) {
F_5 ( V_2 , V_13 ) ;
V_13 -> V_36 -> V_37 |= V_38 ;
break;
}
}
if ( ( V_26 -- ) <= 0 )
break;
}
if ( V_26 <= 0 ) {
F_2 ( V_28
L_11 ) ;
F_5 ( V_2 , V_13 ) ;
V_13 -> V_36 -> V_37 |= V_38 | V_42 ;
}
V_13 -> V_36 -> V_37 |= V_43 ;
F_10 ( V_2 , V_13 ) ;
}
return V_44 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_45 * V_46 , unsigned int * V_34 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
int V_11 ;
int V_47 ;
int V_48 = 10000 ;
if ( V_15 -> V_17 )
return - V_18 ;
F_5 ( V_2 , V_13 ) ;
F_6 ( 0 , V_2 -> V_4 + V_6 ) ;
F_6 ( V_49 , V_2 -> V_4 + V_20 ) ;
V_47 = F_12 ( F_13 ( V_46 -> V_50 ) )
| F_14 ( F_15 ( V_46 -> V_50 ) ) ;
if ( F_16 ( V_46 -> V_50 ) == V_51 )
V_47 |= V_52 ;
V_47 |= V_53 ;
F_6 ( V_47 & 0xff , V_2 -> V_4 + V_54 ) ;
F_6 ( V_47 >> 8 , V_2 -> V_4 + V_54 ) ;
F_6 ( V_55 , V_2 -> V_4 + V_20 ) ;
V_47 = V_56 | V_57
| V_58 | V_59 ;
F_6 ( V_47 , V_2 -> V_4 + V_60 ) ;
while ( -- V_48
&& ( F_3 ( V_2 -> V_4 + V_5 ) & V_61 ) ) ;
if ( ! V_48 ) {
F_2 ( L_12 ) ;
return - 1 ;
}
F_17 ( & V_15 -> V_31 ) ;
V_15 -> V_21 = V_22 ;
V_15 -> V_2 = V_2 ;
V_15 -> V_13 = V_13 ;
for ( V_11 = 0 ; V_11 < V_46 -> V_62 ; V_11 ++ ) {
F_6 ( V_63 | V_64 ,
V_2 -> V_4 + V_20 ) ;
if ( F_18 ( & V_15 -> V_31 ) )
return - V_65 ;
V_34 [ V_11 ] = F_3 ( V_2 -> V_4 + V_40 ) ;
V_34 [ V_11 ] |= F_3 ( V_2 -> V_4 + V_40 ) << 8 ;
V_34 [ V_11 ] ^= 0x8000 ;
}
return V_46 -> V_62 ;
}
static int F_19 ( unsigned int * V_66 , int V_67 )
{
int V_68 ;
V_68 = * V_66 / 200 ;
* V_66 = V_68 * 200 ;
return V_68 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_12 * V_13 , struct V_69 * V_70 )
{
int V_71 = 0 ;
int V_72 ;
V_71 |= F_21 ( & V_70 -> V_73 , V_74 ) ;
V_71 |= F_21 ( & V_70 -> V_75 ,
V_76 | V_77 ) ;
V_71 |= F_21 ( & V_70 -> V_78 ,
V_76 | V_74 ) ;
V_71 |= F_21 ( & V_70 -> V_79 , V_80 ) ;
V_71 |= F_21 ( & V_70 -> V_81 , V_80 | V_82 ) ;
if ( V_71 )
return 1 ;
V_71 |= F_22 ( V_70 -> V_75 ) ;
V_71 |= F_22 ( V_70 -> V_78 ) ;
V_71 |= F_22 ( V_70 -> V_81 ) ;
if ( V_71 )
return 2 ;
if ( V_70 -> V_83 != 0 ) {
V_70 -> V_83 = 0 ;
V_71 ++ ;
}
#define F_23 10000
if ( V_70 -> V_75 == V_76
&& V_70 -> V_84 < F_23 ) {
V_70 -> V_84 = F_23 ;
V_71 ++ ;
}
if ( V_70 -> V_75 == V_76 && V_70 -> V_78 == V_76
&& V_70 -> V_84 != V_70 -> V_85 * V_70 -> V_86 ) {
V_71 ++ ;
}
if ( V_70 -> V_78 == V_76 && V_70 -> V_85 < F_23 ) {
V_70 -> V_85 = F_23 ;
V_71 ++ ;
}
if ( V_70 -> V_86 != V_70 -> V_87 ) {
V_70 -> V_86 = V_70 -> V_87 ;
V_71 ++ ;
}
if ( V_70 -> V_81 == V_80 ) {
if ( V_70 -> V_88 > 0x00ffffff ) {
V_70 -> V_88 = 0x00ffffff ;
V_71 ++ ;
}
} else {
if ( V_70 -> V_88 != 0 ) {
V_70 -> V_88 = 0 ;
V_71 ++ ;
}
}
if ( V_71 )
return 3 ;
if ( V_70 -> V_75 == V_76 ) {
V_72 = V_70 -> V_84 ;
F_19 ( & V_70 -> V_84 ,
V_70 -> V_89 & V_90 ) ;
if ( V_72 != V_70 -> V_84 )
V_71 ++ ;
}
if ( V_70 -> V_78 == V_76 ) {
V_72 = V_70 -> V_85 ;
F_19 ( & V_70 -> V_85 ,
V_70 -> V_89 & V_90 ) ;
if ( V_72 != V_70 -> V_85 )
V_71 ++ ;
}
if ( V_71 )
return 4 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_69 * V_70 = & V_13 -> V_36 -> V_70 ;
int V_48 ;
int V_91 ;
int V_92 ;
int V_11 ;
int V_47 ;
if ( V_15 -> V_17 )
return - V_18 ;
F_5 ( V_2 , V_13 ) ;
F_6 ( 0 , V_2 -> V_4 + V_6 ) ;
F_6 ( V_49 , V_2 -> V_4 + V_20 ) ;
if ( V_70 -> V_78 == V_76 ) {
V_48 = F_19 ( & V_70 -> V_85 ,
V_70 -> V_89 & V_90 ) ;
F_6 ( V_48 & 0xff , V_2 -> V_4 + V_93 ) ;
F_6 ( ( V_48 >> 8 ) & 0xff , V_2 -> V_4 + V_94 ) ;
F_6 ( ( V_48 >> 16 ) & 0xff , V_2 -> V_4 + V_95 ) ;
V_91 = 1 ;
} else {
V_48 = F_19 ( & V_70 -> V_84 ,
V_70 -> V_89 & V_90 ) ;
F_6 ( V_48 & 0xff , V_2 -> V_4 + V_93 ) ;
F_6 ( ( V_48 >> 8 ) & 0xff , V_2 -> V_4 + V_94 ) ;
F_6 ( ( V_48 >> 16 ) & 0xff , V_2 -> V_4 + V_95 ) ;
V_91 = 0 ;
}
for ( V_11 = 0 ; V_11 < V_70 -> V_87 ; V_11 ++ ) {
int V_50 = V_70 -> V_96 [ V_11 ] ;
V_47 = F_12 ( F_13 ( V_50 ) )
| F_14 ( F_15 ( V_50 ) ) ;
if ( F_16 ( V_50 ) == V_51 )
V_47 |= V_52 ;
if ( V_11 == 0 || V_91 )
V_47 |= V_53 ;
F_6 ( V_47 & 0xff , V_2 -> V_4 + V_54 ) ;
F_6 ( V_47 >> 8 , V_2 -> V_4 + V_54 ) ;
}
if ( V_70 -> V_81 == V_80 ) {
V_15 -> V_41 = V_70 -> V_88 * V_70 -> V_86 ;
V_92 = 2 * V_15 -> V_41 ;
while ( V_92 > V_97 * 3 / 4 )
V_92 /= 2 ;
} else {
V_15 -> V_41 = - 1 ;
V_92 = V_97 / 2 ;
}
F_6 ( V_55 , V_2 -> V_4 + V_20 ) ;
F_6 ( 0x00 , V_2 -> V_4 + V_40 ) ;
F_6 ( 0x00 , V_2 -> V_4 + V_40 ) ;
F_6 ( ( V_97 - V_92 ) & 0xff , V_2 -> V_4 + V_40 ) ;
F_6 ( ( V_97 - V_92 ) >> 8 , V_2 -> V_4 + V_40 ) ;
V_47 = V_98 | V_57
| V_99 | V_100 ;
F_6 ( V_47 , V_2 -> V_4 + V_60 ) ;
V_48 = 100 ;
while ( -- V_48
&& ( F_3 ( V_2 -> V_4 + V_5 ) & V_61 ) ) ;
if ( ! V_48 ) {
F_2 ( V_101
L_12 ) ;
return - 1 ;
}
V_15 -> V_21 = V_32 ;
V_15 -> V_2 = V_2 ;
V_15 -> V_13 = V_13 ;
F_6 ( V_63 | V_64 ,
V_2 -> V_4 + V_20 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_45 * V_46 , unsigned int * V_34 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
int V_102 ;
unsigned int V_103 ;
if ( V_15 -> V_17 )
return - V_18 ;
V_103 = F_13 ( V_46 -> V_50 ) ;
V_102 = V_34 [ 0 ] ;
V_102 &= 0x0fff ;
V_102 ^= 0x0800 ;
V_102 |= V_103 << 12 ;
F_6 ( 0 , V_2 -> V_4 + V_6 ) ;
F_26 ( V_102 , V_2 -> V_4 + V_104 ) ;
return 1 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_45 * V_46 , unsigned int * V_34 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
if ( V_15 -> V_17 )
return - V_18 ;
V_34 [ 0 ] = F_3 ( V_2 -> V_4 + V_105 ) ;
return 1 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_45 * V_46 , unsigned int * V_34 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
if ( V_15 -> V_17 )
return - V_18 ;
F_26 ( V_34 [ 0 ] & 0xf , V_2 -> V_4 + V_105 ) ;
return 1 ;
}
static int F_29 ( struct V_1 * V_2 , struct V_106 * V_107 )
{
int V_108 ;
struct V_14 * V_15 = V_109 [ V_107 -> V_110 [ 0 ] ] ;
struct V_12 * V_13 ;
if ( V_107 -> V_110 [ 0 ] < 0 || V_107 -> V_110 [ 0 ] >= V_111 || ! V_15 ) {
F_2 ( L_13 ,
V_2 -> V_112 , V_107 -> V_110 [ 0 ] ) ;
return - V_18 ;
}
strcpy ( V_15 -> V_113 , L_14 ) ;
V_2 -> V_113 = V_15 -> V_113 ;
if ( V_15 -> V_114 -> V_115 [ 2 ] ) {
if ( strncmp ( V_15 -> V_114 -> V_115 [ 2 ] , L_14 , 4 ) == 0 ) {
strncpy ( V_15 -> V_113 , V_15 -> V_114 -> V_115 [ 2 ] ,
sizeof( V_15 -> V_113 ) ) ;
}
}
V_2 -> V_4 = V_15 -> V_114 -> V_116 [ 0 ] -> V_117 ;
V_108 = F_30 ( V_2 , 4 ) ;
if ( V_108 )
return V_108 ;
F_2 ( V_3 L_15 ,
V_2 -> V_112 , V_107 -> V_110 [ 0 ] , V_2 -> V_4 ) ;
V_13 = & V_2 -> V_118 [ 0 ] ;
V_2 -> V_119 = V_13 ;
V_13 -> V_16 = V_15 ;
V_13 -> type = V_120 ;
V_13 -> V_121 = V_122 | V_123 | V_124 | V_125 ;
V_13 -> V_126 = 8 ;
V_13 -> V_127 = 2048 ;
V_13 -> V_128 = 0xffff ;
V_13 -> V_129 = & V_130 ;
V_13 -> V_131 = F_11 ;
V_13 -> V_132 = F_20 ;
V_13 -> V_133 = F_24 ;
V_13 -> V_134 = F_5 ;
V_13 = & V_2 -> V_118 [ 1 ] ;
V_2 -> V_135 = V_13 ;
V_13 -> V_16 = V_15 ;
V_13 -> type = V_136 ;
V_13 -> V_121 = V_137 ;
V_13 -> V_126 = 2 ;
V_13 -> V_127 = 1 ;
V_13 -> V_128 = 0x0fff ;
V_13 -> V_129 = & V_138 ;
V_13 -> V_139 = F_25 ;
V_13 = & V_2 -> V_118 [ 2 ] ;
V_13 -> V_16 = V_15 ;
V_13 -> type = V_140 ;
V_13 -> V_121 = V_122 ;
V_13 -> V_126 = 1 ;
V_13 -> V_127 = 1 ;
V_13 -> V_131 = F_27 ;
V_13 = & V_2 -> V_118 [ 3 ] ;
V_13 -> V_16 = V_15 ;
V_13 -> type = V_141 ;
V_13 -> V_121 = V_137 ;
V_13 -> V_126 = 1 ;
V_13 -> V_127 = 1 ;
V_13 -> V_139 = F_28 ;
return 1 ;
}
static void F_31 ( struct V_1 * V_2 )
{
}
static int F_32 ( struct V_142 * V_114 )
{
struct V_14 * V_15 ;
int V_11 ;
F_33 ( & V_114 -> V_2 , L_16 ) ;
for ( V_11 = 0 ; V_11 < V_111 ; V_11 ++ )
if ( V_109 [ V_11 ] == NULL )
break;
if ( V_11 == V_111 ) {
F_2 ( V_143 L_17 ) ;
return - V_144 ;
}
V_15 = F_34 ( sizeof( struct V_14 ) , V_145 ) ;
if ( ! V_15 )
return - V_146 ;
V_15 -> V_147 = V_11 ;
V_109 [ V_11 ] = V_15 ;
V_15 -> V_114 = V_114 ;
V_114 -> V_148 = V_15 ;
F_35 ( V_114 ) ;
return 0 ;
}
static void F_36 ( struct V_142 * V_114 )
{
struct V_14 * V_2 = V_114 -> V_148 ;
V_2 -> V_17 = 1 ;
F_37 ( V_114 ) ;
V_109 [ V_2 -> V_147 ] = NULL ;
F_38 ( V_2 ) ;
}
static int F_39 ( struct V_142 * V_149 , void * V_150 )
{
if ( V_149 -> V_151 == 0 )
return - V_152 ;
return F_40 ( V_149 ) ;
}
static void F_35 ( struct V_142 * V_114 )
{
int V_108 ;
F_33 ( & V_114 -> V_2 , L_18 ) ;
V_114 -> V_153 |= V_154 | V_155 ;
V_108 = F_41 ( V_114 , F_39 , NULL ) ;
if ( V_108 ) {
F_42 ( & V_114 -> V_2 , L_19 ) ;
goto V_156;
}
V_108 = F_43 ( V_114 , F_7 ) ;
if ( V_108 )
goto V_156;
V_108 = F_44 ( V_114 ) ;
if ( V_108 )
goto V_156;
return;
V_156:
F_37 ( V_114 ) ;
}
static void F_37 ( struct V_142 * V_114 )
{
F_33 ( & V_114 -> V_2 , L_20 ) ;
F_45 ( V_114 ) ;
}
static int F_46 ( struct V_142 * V_114 )
{
struct V_14 * V_15 = V_114 -> V_148 ;
V_15 -> V_17 = 1 ;
return 0 ;
}
static int F_47 ( struct V_142 * V_114 )
{
struct V_14 * V_15 = V_114 -> V_148 ;
V_15 -> V_17 = 0 ;
return 0 ;
}
int T_1 F_48 ( void )
{
F_49 ( & V_157 ) ;
F_50 ( & V_158 ) ;
return 0 ;
}
void T_2 F_51 ( void )
{
F_52 ( & V_158 ) ;
F_53 ( & V_157 ) ;
}
