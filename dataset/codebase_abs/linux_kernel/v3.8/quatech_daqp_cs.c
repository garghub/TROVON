static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , L_1 ,
F_3 ( V_2 -> V_4 + V_5 ) , F_3 ( V_2 -> V_4 + V_6 ) ) ;
}
static void F_4 ( char * V_7 , void * V_8 , int V_9 )
{
unsigned char * V_10 = V_8 ;
int V_11 ;
F_5 ( V_7 ) ;
for ( V_11 = 0 ; V_11 < V_9 ; V_11 ++ ) {
if ( V_11 % 16 == 0 )
F_5 ( L_2 , V_10 ) ;
F_5 ( L_3 , * ( V_10 ++ ) ) ;
}
F_5 ( L_4 ) ;
}
static int F_6 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
if ( V_15 -> V_17 )
return - V_18 ;
F_7 ( V_19 , V_2 -> V_4 + V_20 ) ;
V_15 -> V_21 = V_22 ;
return 0 ;
}
static enum V_23 F_8 ( int V_24 , void * V_25 )
{
struct V_14 * V_15 = (struct V_14 * ) V_25 ;
struct V_1 * V_2 ;
struct V_12 * V_13 ;
int V_26 = 10000 ;
int V_27 ;
if ( V_15 == NULL ) {
F_9 ( L_5 , V_24 ) ;
return V_28 ;
}
V_2 = V_15 -> V_2 ;
if ( V_2 == NULL ) {
F_9 ( L_6 ) ;
return V_28 ;
}
if ( ! V_2 -> V_29 ) {
F_9 ( L_7 ) ;
return V_28 ;
}
V_13 = V_15 -> V_13 ;
if ( V_13 == NULL ) {
F_9 ( L_8 ) ;
return V_28 ;
}
if ( (struct V_14 * ) V_13 -> V_16 != V_15 ) {
F_9 ( L_9 ) ;
return V_28 ;
}
switch ( V_15 -> V_21 ) {
case V_22 :
F_10 ( & V_15 -> V_30 ) ;
break;
case V_31 :
while ( ! ( ( V_27 = F_3 ( V_2 -> V_4 + V_5 ) )
& V_32 ) ) {
short V_33 ;
if ( V_27 & V_34 ) {
V_13 -> V_35 -> V_36 |=
V_37 | V_38 ;
F_11 ( V_2 -> V_3 , L_10 ) ;
F_6 ( V_2 , V_13 ) ;
break;
}
V_33 = F_3 ( V_2 -> V_4 + V_39 ) ;
V_33 |= F_3 ( V_2 -> V_4 + V_39 ) << 8 ;
V_33 ^= 0x8000 ;
F_12 ( V_13 -> V_35 , V_33 ) ;
if ( V_15 -> V_40 > 0 ) {
V_15 -> V_40 -- ;
if ( V_15 -> V_40 == 0 ) {
F_6 ( V_2 , V_13 ) ;
V_13 -> V_35 -> V_36 |= V_37 ;
break;
}
}
if ( ( V_26 -- ) <= 0 )
break;
}
if ( V_26 <= 0 ) {
F_11 ( V_2 -> V_3 ,
L_11 ) ;
F_6 ( V_2 , V_13 ) ;
V_13 -> V_35 -> V_36 |= V_37 | V_41 ;
}
V_13 -> V_35 -> V_36 |= V_42 ;
F_13 ( V_2 , V_13 ) ;
}
return V_43 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_44 * V_45 , unsigned int * V_33 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
int V_11 ;
int V_46 ;
int V_47 = 10000 ;
if ( V_15 -> V_17 )
return - V_18 ;
F_6 ( V_2 , V_13 ) ;
F_7 ( 0 , V_2 -> V_4 + V_6 ) ;
F_7 ( V_48 , V_2 -> V_4 + V_20 ) ;
V_46 = F_15 ( F_16 ( V_45 -> V_49 ) )
| F_17 ( F_18 ( V_45 -> V_49 ) ) ;
if ( F_19 ( V_45 -> V_49 ) == V_50 )
V_46 |= V_51 ;
V_46 |= V_52 ;
F_7 ( V_46 & 0xff , V_2 -> V_4 + V_53 ) ;
F_7 ( V_46 >> 8 , V_2 -> V_4 + V_53 ) ;
F_7 ( V_54 , V_2 -> V_4 + V_20 ) ;
V_46 = V_55 | V_56
| V_57 | V_58 ;
F_7 ( V_46 , V_2 -> V_4 + V_59 ) ;
while ( -- V_47
&& ( F_3 ( V_2 -> V_4 + V_5 ) & V_60 ) )
;
if ( ! V_47 ) {
F_20 ( V_2 -> V_3 ,
L_12 ) ;
return - 1 ;
}
F_21 ( & V_15 -> V_30 ) ;
V_15 -> V_21 = V_22 ;
V_15 -> V_2 = V_2 ;
V_15 -> V_13 = V_13 ;
for ( V_11 = 0 ; V_11 < V_45 -> V_61 ; V_11 ++ ) {
F_7 ( V_62 | V_63 ,
V_2 -> V_4 + V_20 ) ;
if ( F_22 ( & V_15 -> V_30 ) )
return - V_64 ;
V_33 [ V_11 ] = F_3 ( V_2 -> V_4 + V_39 ) ;
V_33 [ V_11 ] |= F_3 ( V_2 -> V_4 + V_39 ) << 8 ;
V_33 [ V_11 ] ^= 0x8000 ;
}
return V_45 -> V_61 ;
}
static int F_23 ( unsigned int * V_65 , int V_66 )
{
int V_67 ;
V_67 = * V_65 / 200 ;
* V_65 = V_67 * 200 ;
return V_67 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_12 * V_13 , struct V_68 * V_69 )
{
int V_70 = 0 ;
int V_71 ;
V_70 |= F_25 ( & V_69 -> V_72 , V_73 ) ;
V_70 |= F_25 ( & V_69 -> V_74 ,
V_75 | V_76 ) ;
V_70 |= F_25 ( & V_69 -> V_77 ,
V_75 | V_73 ) ;
V_70 |= F_25 ( & V_69 -> V_78 , V_79 ) ;
V_70 |= F_25 ( & V_69 -> V_80 , V_79 | V_81 ) ;
if ( V_70 )
return 1 ;
V_70 |= F_26 ( V_69 -> V_74 ) ;
V_70 |= F_26 ( V_69 -> V_77 ) ;
V_70 |= F_26 ( V_69 -> V_80 ) ;
if ( V_70 )
return 2 ;
V_70 |= F_27 ( & V_69 -> V_82 , 0 ) ;
#define F_28 10000
if ( V_69 -> V_74 == V_75 )
V_70 |= F_29 ( & V_69 -> V_83 ,
F_28 ) ;
if ( V_69 -> V_74 == V_75 && V_69 -> V_77 == V_75
&& V_69 -> V_83 != V_69 -> V_84 * V_69 -> V_85 ) {
V_70 |= - V_86 ;
}
if ( V_69 -> V_77 == V_75 )
V_70 |= F_29 ( & V_69 -> V_84 , F_28 ) ;
V_70 |= F_27 ( & V_69 -> V_85 , V_69 -> V_87 ) ;
if ( V_69 -> V_80 == V_79 )
V_70 |= F_30 ( & V_69 -> V_88 , 0x00ffffff ) ;
else
V_70 |= F_27 ( & V_69 -> V_88 , 0 ) ;
if ( V_70 )
return 3 ;
if ( V_69 -> V_74 == V_75 ) {
V_71 = V_69 -> V_83 ;
F_23 ( & V_69 -> V_83 ,
V_69 -> V_89 & V_90 ) ;
if ( V_71 != V_69 -> V_83 )
V_70 ++ ;
}
if ( V_69 -> V_77 == V_75 ) {
V_71 = V_69 -> V_84 ;
F_23 ( & V_69 -> V_84 ,
V_69 -> V_89 & V_90 ) ;
if ( V_71 != V_69 -> V_84 )
V_70 ++ ;
}
if ( V_70 )
return 4 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
struct V_68 * V_69 = & V_13 -> V_35 -> V_69 ;
int V_47 ;
int V_91 ;
int V_92 ;
int V_11 ;
int V_46 ;
if ( V_15 -> V_17 )
return - V_18 ;
F_6 ( V_2 , V_13 ) ;
F_7 ( 0 , V_2 -> V_4 + V_6 ) ;
F_7 ( V_48 , V_2 -> V_4 + V_20 ) ;
if ( V_69 -> V_77 == V_75 ) {
V_47 = F_23 ( & V_69 -> V_84 ,
V_69 -> V_89 & V_90 ) ;
F_7 ( V_47 & 0xff , V_2 -> V_4 + V_93 ) ;
F_7 ( ( V_47 >> 8 ) & 0xff , V_2 -> V_4 + V_94 ) ;
F_7 ( ( V_47 >> 16 ) & 0xff , V_2 -> V_4 + V_95 ) ;
V_91 = 1 ;
} else {
V_47 = F_23 ( & V_69 -> V_83 ,
V_69 -> V_89 & V_90 ) ;
F_7 ( V_47 & 0xff , V_2 -> V_4 + V_93 ) ;
F_7 ( ( V_47 >> 8 ) & 0xff , V_2 -> V_4 + V_94 ) ;
F_7 ( ( V_47 >> 16 ) & 0xff , V_2 -> V_4 + V_95 ) ;
V_91 = 0 ;
}
for ( V_11 = 0 ; V_11 < V_69 -> V_87 ; V_11 ++ ) {
int V_49 = V_69 -> V_96 [ V_11 ] ;
V_46 = F_15 ( F_16 ( V_49 ) )
| F_17 ( F_18 ( V_49 ) ) ;
if ( F_19 ( V_49 ) == V_50 )
V_46 |= V_51 ;
if ( V_11 == 0 || V_91 )
V_46 |= V_52 ;
F_7 ( V_46 & 0xff , V_2 -> V_4 + V_53 ) ;
F_7 ( V_46 >> 8 , V_2 -> V_4 + V_53 ) ;
}
if ( V_69 -> V_80 == V_79 ) {
V_15 -> V_40 = V_69 -> V_88 * V_69 -> V_85 ;
V_92 = 2 * V_15 -> V_40 ;
while ( V_92 > V_97 * 3 / 4 )
V_92 /= 2 ;
} else {
V_15 -> V_40 = - 1 ;
V_92 = V_97 / 2 ;
}
F_7 ( V_54 , V_2 -> V_4 + V_20 ) ;
F_7 ( 0x00 , V_2 -> V_4 + V_39 ) ;
F_7 ( 0x00 , V_2 -> V_4 + V_39 ) ;
F_7 ( ( V_97 - V_92 ) & 0xff , V_2 -> V_4 + V_39 ) ;
F_7 ( ( V_97 - V_92 ) >> 8 , V_2 -> V_4 + V_39 ) ;
V_46 = V_98 | V_56
| V_99 | V_100 ;
F_7 ( V_46 , V_2 -> V_4 + V_59 ) ;
V_47 = 100 ;
while ( -- V_47
&& ( F_3 ( V_2 -> V_4 + V_5 ) & V_60 ) )
;
if ( ! V_47 ) {
F_20 ( V_2 -> V_3 ,
L_12 ) ;
return - 1 ;
}
V_15 -> V_21 = V_31 ;
V_15 -> V_2 = V_2 ;
V_15 -> V_13 = V_13 ;
F_7 ( V_62 | V_63 ,
V_2 -> V_4 + V_20 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_44 * V_45 , unsigned int * V_33 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
int V_101 ;
unsigned int V_102 ;
if ( V_15 -> V_17 )
return - V_18 ;
V_102 = F_16 ( V_45 -> V_49 ) ;
V_101 = V_33 [ 0 ] ;
V_101 &= 0x0fff ;
V_101 ^= 0x0800 ;
V_101 |= V_102 << 12 ;
F_7 ( 0 , V_2 -> V_4 + V_6 ) ;
F_33 ( V_101 , V_2 -> V_4 + V_103 ) ;
return 1 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_44 * V_45 , unsigned int * V_33 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
if ( V_15 -> V_17 )
return - V_18 ;
V_33 [ 0 ] = F_3 ( V_2 -> V_4 + V_104 ) ;
return 1 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_44 * V_45 , unsigned int * V_33 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
if ( V_15 -> V_17 )
return - V_18 ;
F_33 ( V_33 [ 0 ] & 0xf , V_2 -> V_4 + V_104 ) ;
return 1 ;
}
static int F_36 ( struct V_1 * V_2 , struct V_105 * V_106 )
{
int V_107 ;
struct V_14 * V_15 = V_108 [ V_106 -> V_109 [ 0 ] ] ;
struct V_12 * V_13 ;
if ( V_106 -> V_109 [ 0 ] < 0 || V_106 -> V_109 [ 0 ] >= V_110 || ! V_15 ) {
F_20 ( V_2 -> V_3 , L_13 ,
V_106 -> V_109 [ 0 ] ) ;
return - V_18 ;
}
strcpy ( V_15 -> V_111 , L_14 ) ;
V_2 -> V_111 = V_15 -> V_111 ;
if ( V_15 -> V_112 -> V_113 [ 2 ] ) {
if ( strncmp ( V_15 -> V_112 -> V_113 [ 2 ] , L_14 , 4 ) == 0 ) {
strncpy ( V_15 -> V_111 , V_15 -> V_112 -> V_113 [ 2 ] ,
sizeof( V_15 -> V_111 ) ) ;
}
}
V_2 -> V_4 = V_15 -> V_112 -> V_114 [ 0 ] -> V_115 ;
V_107 = F_37 ( V_2 , 4 ) ;
if ( V_107 )
return V_107 ;
F_2 ( V_2 -> V_3 , L_15 ,
V_106 -> V_109 [ 0 ] , V_2 -> V_4 ) ;
V_13 = & V_2 -> V_116 [ 0 ] ;
V_2 -> V_117 = V_13 ;
V_13 -> V_16 = V_15 ;
V_13 -> type = V_118 ;
V_13 -> V_119 = V_120 | V_121 | V_122 | V_123 ;
V_13 -> V_124 = 8 ;
V_13 -> V_125 = 2048 ;
V_13 -> V_126 = 0xffff ;
V_13 -> V_127 = & V_128 ;
V_13 -> V_129 = F_14 ;
V_13 -> V_130 = F_24 ;
V_13 -> V_131 = F_31 ;
V_13 -> V_132 = F_6 ;
V_13 = & V_2 -> V_116 [ 1 ] ;
V_2 -> V_133 = V_13 ;
V_13 -> V_16 = V_15 ;
V_13 -> type = V_134 ;
V_13 -> V_119 = V_135 ;
V_13 -> V_124 = 2 ;
V_13 -> V_125 = 1 ;
V_13 -> V_126 = 0x0fff ;
V_13 -> V_127 = & V_136 ;
V_13 -> V_137 = F_32 ;
V_13 = & V_2 -> V_116 [ 2 ] ;
V_13 -> V_16 = V_15 ;
V_13 -> type = V_138 ;
V_13 -> V_119 = V_120 ;
V_13 -> V_124 = 1 ;
V_13 -> V_125 = 1 ;
V_13 -> V_129 = F_34 ;
V_13 = & V_2 -> V_116 [ 3 ] ;
V_13 -> V_16 = V_15 ;
V_13 -> type = V_139 ;
V_13 -> V_119 = V_135 ;
V_13 -> V_124 = 1 ;
V_13 -> V_125 = 1 ;
V_13 -> V_137 = F_35 ;
return 1 ;
}
static void F_38 ( struct V_1 * V_2 )
{
}
static int F_39 ( struct V_140 * V_112 )
{
struct V_14 * V_15 ;
int V_11 ;
F_40 ( & V_112 -> V_2 , L_16 ) ;
for ( V_11 = 0 ; V_11 < V_110 ; V_11 ++ )
if ( V_108 [ V_11 ] == NULL )
break;
if ( V_11 == V_110 ) {
F_41 ( & V_112 -> V_2 , L_17 ) ;
return - V_141 ;
}
V_15 = F_42 ( sizeof( struct V_14 ) , V_142 ) ;
if ( ! V_15 )
return - V_143 ;
V_15 -> V_144 = V_11 ;
V_108 [ V_11 ] = V_15 ;
V_15 -> V_112 = V_112 ;
V_112 -> V_145 = V_15 ;
F_43 ( V_112 ) ;
return 0 ;
}
static void F_44 ( struct V_140 * V_112 )
{
struct V_14 * V_2 = V_112 -> V_145 ;
V_2 -> V_17 = 1 ;
F_45 ( V_112 ) ;
V_108 [ V_2 -> V_144 ] = NULL ;
F_46 ( V_2 ) ;
}
static int F_47 ( struct V_140 * V_146 , void * V_147 )
{
if ( V_146 -> V_148 == 0 )
return - V_86 ;
return F_48 ( V_146 ) ;
}
static void F_43 ( struct V_140 * V_112 )
{
int V_107 ;
F_40 ( & V_112 -> V_2 , L_18 ) ;
V_112 -> V_149 |= V_150 | V_151 ;
V_107 = F_49 ( V_112 , F_47 , NULL ) ;
if ( V_107 ) {
F_11 ( & V_112 -> V_2 , L_19 ) ;
goto V_152;
}
V_107 = F_50 ( V_112 , F_8 ) ;
if ( V_107 )
goto V_152;
V_107 = F_51 ( V_112 ) ;
if ( V_107 )
goto V_152;
return;
V_152:
F_45 ( V_112 ) ;
}
static void F_45 ( struct V_140 * V_112 )
{
F_40 ( & V_112 -> V_2 , L_20 ) ;
F_52 ( V_112 ) ;
}
static int F_53 ( struct V_140 * V_112 )
{
struct V_14 * V_15 = V_112 -> V_145 ;
V_15 -> V_17 = 1 ;
return 0 ;
}
static int F_54 ( struct V_140 * V_112 )
{
struct V_14 * V_15 = V_112 -> V_145 ;
V_15 -> V_17 = 0 ;
return 0 ;
}
int T_1 F_55 ( void )
{
F_56 ( & V_153 ) ;
F_57 ( & V_154 ) ;
return 0 ;
}
void T_2 F_58 ( void )
{
F_59 ( & V_154 ) ;
F_60 ( & V_153 ) ;
}
