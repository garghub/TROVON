static int F_1 ( struct V_1 * V_2 ,
const void * V_3 , void * V_4 , unsigned V_5 , int V_6 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 V_10 ;
struct V_11 V_12 ;
int V_13 ;
F_2 ( & V_2 -> V_14 ) ;
F_3 ( & V_10 ) ;
memset ( & V_12 , 0 , sizeof V_12 ) ;
V_12 . V_5 = V_5 ;
V_12 . V_15 = V_3 ;
V_12 . V_16 = V_4 ;
F_4 ( & V_12 , & V_10 ) ;
if ( V_6 )
V_12 . V_17 = V_8 -> V_18 ;
else if ( V_2 -> V_19 )
V_12 . V_17 = V_2 -> V_19 ;
V_13 = F_5 ( V_8 , & V_10 ) ;
F_6 ( & V_2 -> V_14 ) ;
return V_13 ;
}
static int F_7 ( struct V_1 * V_2 , const T_1 V_20 )
{
void * V_21 ;
T_1 * V_22 , * V_23 ;
int V_13 ;
V_21 = F_8 ( 8 , V_24 | V_25 ) ;
if ( ! V_21 )
return - V_26 ;
V_22 = V_21 ;
V_23 = V_21 + 4 ;
* V_22 = V_20 ;
V_13 = F_1 ( V_2 , V_22 , V_23 , 2 , 1 ) ;
if ( V_13 ) {
F_9 ( L_1 ,
V_27 , V_13 , V_20 ) ;
goto exit;
}
F_10 ( V_2 , V_23 , 1 ) ;
exit:
F_11 ( V_21 ) ;
return V_13 ;
}
static int F_12 ( struct V_1 * V_2 )
{
void * V_21 ;
T_1 * V_22 , * V_23 ;
int V_13 , V_28 ;
V_28 = V_29 * sizeof( T_1 ) ;
V_21 = F_8 ( V_28 * 2 , V_24 | V_25 ) ;
if ( ! V_21 )
return 0 ;
V_22 = V_21 ;
V_23 = V_21 + V_28 ;
if ( F_1 ( V_2 , V_22 , V_23 , V_28 , 1 ) ) {
F_11 ( V_21 ) ;
return 0 ;
}
V_13 = F_10 ( V_2 , V_23 , V_29 ) ;
F_11 ( V_21 ) ;
return V_13 ;
}
static void F_13 ( struct V_30 * V_31 , int V_32 )
{
struct V_1 * V_2 =
F_14 ( V_31 , struct V_1 , V_31 ) ;
struct V_33 * V_34 = & V_2 -> V_35 ;
if ( F_15 ( V_34 ) ) {
V_34 -> V_21 [ V_34 -> V_36 ] = ( char ) V_32 ;
V_34 -> V_36 = ( V_34 -> V_36 + 1 ) & ( V_37 - 1 ) ;
}
}
static void F_16 ( struct V_38 * V_39 ,
const char * V_40 , unsigned int V_41 )
{
if ( ! V_42 )
return;
F_17 ( & V_42 -> V_31 , V_40 , V_41 , F_13 ) ;
if ( ! F_18 ( V_43 , & V_42 -> V_44 ) )
F_19 ( & V_42 -> V_45 ) ;
}
static int T_2
F_20 ( struct V_38 * V_39 , char * V_46 )
{
struct V_1 * V_2 = V_42 ;
int V_19 = 115200 ;
int V_47 = 8 ;
int V_48 = 'n' ;
int V_49 = 'n' ;
F_21 ( L_2 ) ;
if ( V_39 -> V_50 == - 1 )
V_39 -> V_50 = 0 ;
if ( ! V_2 ) {
F_22 ( L_3 ) ;
return - V_51 ;
}
if ( V_46 )
F_23 ( V_46 , & V_19 , & V_48 , & V_47 , & V_49 ) ;
return F_24 ( & V_2 -> V_31 , V_39 , V_19 , V_48 , V_47 , V_49 ) ;
}
static struct V_52 * F_25 ( struct V_38 * V_39 ,
int * V_50 )
{
struct V_53 * V_54 = V_39 -> V_55 ;
* V_50 = V_39 -> V_50 ;
return V_54 -> V_52 ;
}
static unsigned int F_26 ( struct V_30 * V_31 )
{
return 1 ;
}
static void F_27 ( struct V_30 * V_31 )
{
return;
}
static void F_28 ( struct V_30 * V_31 )
{
return;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
void * V_21 ;
T_1 * V_22 , * V_23 ;
int V_56 , V_5 , V_28 , V_57 , V_58 , V_13 = 0 ;
V_57 = V_59 * sizeof( T_1 ) * 2 ;
V_21 = F_8 ( V_57 , V_24 | V_25 ) ;
if ( ! V_21 )
return;
V_22 = V_21 ;
V_23 = V_21 + V_57 / 2 ;
while ( ! F_30 ( V_34 ) ) {
V_58 = F_31 ( V_34 ) ;
while ( V_58 ) {
V_5 = F_32 ( V_58 , V_59 ) ;
V_28 = V_5 * sizeof( T_1 ) ;
memset ( V_23 , 0 , V_28 ) ;
for ( V_56 = 0 ; V_56 < V_5 ; V_56 ++ ) {
V_22 [ V_56 ] = ( V_60 ) V_34 -> V_21 [ V_34 -> V_61 ] | V_62 ;
V_34 -> V_61 = ( V_34 -> V_61 + 1 ) &
( V_63 - 1 ) ;
}
V_13 = F_1 ( V_2 , V_22 , V_23 , V_28 , 0 ) ;
if ( V_13 )
F_9 ( L_4 , V_27 , V_13 ) ;
F_10 ( V_2 , V_23 , V_5 ) ;
V_2 -> V_31 . V_64 . V_65 += V_5 ;
V_58 -= V_5 ;
}
}
F_11 ( V_21 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = & V_2 -> V_31 ;
struct V_33 * V_34 = & V_31 -> V_66 -> V_34 ;
if ( F_30 ( V_34 ) || F_34 ( V_31 ) )
return;
F_29 ( V_2 , V_34 ) ;
if ( F_31 ( V_34 ) < V_67 )
F_35 ( V_31 ) ;
if ( F_30 ( V_34 ) )
F_27 ( V_31 ) ;
}
static void F_36 ( struct V_30 * V_31 )
{
struct V_1 * V_2 =
F_14 ( V_31 , struct V_1 , V_31 ) ;
if ( ! F_18 ( V_68 , & V_2 -> V_44 ) )
F_19 ( & V_2 -> V_45 ) ;
}
static int
F_10 ( struct V_1 * V_2 , unsigned short * V_69 , int V_5 )
{
struct V_30 * V_31 = & V_2 -> V_31 ;
struct V_70 * V_71 ;
char V_21 [ V_29 ] ;
int V_72 , V_73 , V_74 ;
if ( ! V_31 -> V_66 )
return 0 ;
V_71 = & V_31 -> V_66 -> V_31 ;
for ( V_72 = 0 , V_73 = 0 ; V_72 < V_5 ; V_72 ++ ) {
if ( V_69 [ V_72 ] & V_75 &&
F_37 ( V_31 ) )
continue;
if ( V_69 [ V_72 ] & V_76 ) {
if ( F_38 ( V_31 , V_69 [ V_72 ] & 0xff ) )
continue;
V_21 [ V_73 ++ ] = V_69 [ V_72 ] & 0xff ;
}
}
if ( ! V_73 )
return 0 ;
for ( V_72 = 0 ; V_73 ; V_72 += V_74 , V_73 -= V_74 ) {
V_74 = F_39 ( V_71 , V_73 ) ;
if ( V_74 ) {
F_40 ( V_71 , V_21 + V_72 , V_74 ) ;
V_31 -> V_64 . V_77 += V_74 ;
}
}
F_41 ( V_71 ) ;
return V_72 ;
}
static void F_42 ( struct V_1 * V_2 )
{
int V_78 = 1 , V_79 ;
do {
V_79 = F_12 ( V_2 ) ;
if ( V_79 ) {
V_78 = 5 ;
}
} while ( -- V_78 );
}
static int F_43 ( void * V_80 )
{
struct V_1 * V_2 = V_80 ;
T_3 * V_45 = & V_2 -> V_45 ;
int V_13 = 0 ;
struct V_33 * V_34 = & V_2 -> V_35 ;
F_21 ( L_5 ) ;
do {
F_44 ( * V_45 ,
V_2 -> V_44 || F_45 () ) ;
F_2 ( & V_2 -> V_81 ) ;
if ( F_46 ( V_82 , & V_2 -> V_44 ) )
F_42 ( V_2 ) ;
if ( F_46 ( V_43 , & V_2 -> V_44 ) )
F_29 ( V_2 , V_34 ) ;
if ( F_46 ( V_68 , & V_2 -> V_44 ) )
F_33 ( V_2 ) ;
F_6 ( & V_2 -> V_81 ) ;
} while ( ! F_45 () );
return V_13 ;
}
static T_4 F_47 ( int V_83 , void * V_84 )
{
struct V_1 * V_2 = V_84 ;
if ( ! F_18 ( V_82 , & V_2 -> V_44 ) )
F_19 ( & V_2 -> V_45 ) ;
return V_85 ;
}
static int F_48 ( void * V_80 )
{
struct V_1 * V_2 = V_80 ;
F_21 ( L_6 ) ;
do {
if ( F_49 ( & V_2 -> V_81 ) ) {
F_42 ( V_2 ) ;
F_6 ( & V_2 -> V_81 ) ;
}
F_50 ( V_86 ) ;
F_51 ( V_87 / 20 ) ;
} while ( ! F_45 () );
return 0 ;
}
static int F_52 ( struct V_30 * V_31 )
{
struct V_1 * V_2 =
F_14 ( V_31 , struct V_1 , V_31 ) ;
T_1 V_88 = 0 ;
int V_13 = 0 ;
if ( V_31 -> line != 0 ) {
F_22 ( L_7 ) ;
return - 1 ;
}
V_88 = V_89 | V_90
| V_91
| V_92
| V_93 ;
V_31 -> V_66 -> V_31 . V_94 = 1 ;
if ( V_2 -> V_83 ) {
V_88 |= V_95 ;
} else {
V_2 -> V_96 =
F_53 ( F_48 , V_2 , L_8 ) ;
if ( F_54 ( V_2 -> V_96 ) ) {
V_13 = F_55 ( V_2 -> V_96 ) ;
V_2 -> V_96 = NULL ;
F_22 ( L_9 ) ;
return V_13 ;
}
}
V_13 = F_7 ( V_2 , V_88 ) ;
if ( V_13 ) {
if ( V_2 -> V_96 )
F_56 ( V_2 -> V_96 ) ;
V_2 -> V_96 = NULL ;
return V_13 ;
}
V_2 -> V_97 = V_88 ;
return 0 ;
}
static void F_57 ( struct V_30 * V_31 )
{
struct V_1 * V_2 =
F_14 ( V_31 , struct V_1 , V_31 ) ;
T_1 V_88 ;
if ( V_2 -> V_96 ) {
F_56 ( V_2 -> V_96 ) ;
V_2 -> V_96 = NULL ;
}
V_88 = V_89 | V_98 ;
F_7 ( V_2 , V_88 ) ;
}
static void F_58 ( struct V_30 * V_31 )
{
}
static int F_59 ( struct V_30 * V_31 )
{
return 0 ;
}
static void F_60 ( struct V_30 * V_31 , int V_99 )
{
V_31 -> type = V_100 ;
}
static int
F_61 ( struct V_30 * V_31 , struct V_101 * V_102 )
{
return - V_103 ;
}
static const char * F_62 ( struct V_30 * V_31 )
{
struct V_1 * V_2 =
F_14 ( V_31 , struct V_1 , V_31 ) ;
return V_2 -> V_104 ;
}
static void
F_63 ( struct V_30 * V_31 , struct V_105 * V_106 ,
struct V_105 * V_107 )
{
struct V_1 * V_2 =
F_14 ( V_31 , struct V_1 , V_31 ) ;
unsigned char V_108 ;
unsigned int V_19 , V_48 = 0 ;
int V_109 = - 1 ;
T_1 V_110 = V_2 -> V_97 ;
switch ( V_106 -> V_111 & V_112 ) {
case V_113 :
V_108 = V_114 ;
V_110 |= V_115 ;
break;
default:
V_106 -> V_111 &= ~ V_112 ;
V_106 -> V_111 |= V_116 ;
case V_116 :
V_108 = V_117 ;
V_110 |= V_92 ;
break;
}
V_19 = F_64 ( V_31 , V_106 , V_107 , 0 , 230400 ) ;
switch ( V_19 ) {
case 300 :
V_109 = V_118 ;
break;
case 600 :
V_109 = V_119 ;
break;
case 1200 :
V_109 = V_120 ;
break;
case 2400 :
V_109 = V_121 ;
break;
case 4800 :
V_109 = V_122 ;
break;
case 9600 :
V_109 = V_123 ;
break;
case 19200 :
V_109 = V_124 ;
break;
case 38400 :
V_109 = V_125 ;
break;
case 57600 :
V_109 = V_93 ;
break;
case 115200 :
V_109 = V_126 ;
break;
case 230400 :
if ( V_2 -> clock & V_127 )
break;
default:
V_19 = V_2 -> V_19 ;
V_109 = V_2 -> V_97 & V_128 ;
F_65 ( V_106 , V_19 , V_19 ) ;
}
if ( V_2 -> clock & V_127 ) {
V_109 += 1 ;
if ( V_19 == 300 ) {
V_19 = 600 ;
V_109 = V_118 ;
}
if ( V_19 == 230400 )
V_109 = V_126 ;
F_65 ( V_106 , V_19 , V_19 ) ;
}
V_110 = ( V_110 & ~ V_128 ) | V_109 ;
if ( F_66 ( V_106 -> V_111 & V_129 ) )
V_106 -> V_111 &= ~ V_129 ;
if ( V_106 -> V_111 & V_130 )
V_110 |= V_131 ;
else
V_110 &= ~ V_131 ;
if ( V_106 -> V_111 & V_132 ) {
V_110 |= V_133 ;
V_48 |= V_134 ;
} else
V_110 &= ~ V_133 ;
if ( ! ( V_106 -> V_111 & V_135 ) )
V_48 |= V_136 ;
V_2 -> V_48 = V_48 ;
F_67 ( V_31 , V_106 -> V_111 , V_19 ) ;
V_110 |= V_89 ;
if ( V_110 != V_2 -> V_97 ) {
if ( ! F_7 ( V_2 , V_110 ) ) {
V_2 -> V_97 = V_110 ;
V_2 -> V_19 = V_19 ;
}
}
}
static unsigned int F_68 ( struct V_30 * V_31 )
{
return V_137 | V_138 | V_137 ;
}
static void F_69 ( struct V_30 * V_31 , unsigned int V_139 )
{
}
static void F_70 ( struct V_30 * V_31 , int V_140 )
{
}
static void F_71 ( struct V_30 * V_31 , unsigned int V_66 ,
unsigned int V_141 )
{
}
static int F_72 ( struct V_142 * V_143 )
{
struct V_7 * V_8 = F_73 ( V_143 ) ;
struct V_1 * V_2 = F_74 ( V_8 ) ;
if ( V_2 -> V_83 > 0 )
F_75 ( V_2 -> V_83 ) ;
F_76 ( & V_144 , & V_2 -> V_31 ) ;
F_7 ( V_2 , V_2 -> V_97 | V_98 ) ;
return 0 ;
}
static int F_77 ( struct V_142 * V_143 )
{
struct V_7 * V_8 = F_73 ( V_143 ) ;
struct V_1 * V_2 = F_74 ( V_8 ) ;
F_7 ( V_2 , V_2 -> V_97 ) ;
F_78 ( & V_144 , & V_2 -> V_31 ) ;
if ( V_2 -> V_83 > 0 )
F_79 ( V_2 -> V_83 ) ;
return 0 ;
}
static int F_80 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
void * V_145 ;
T_1 V_146 ;
int V_13 = 0 ;
V_2 = F_8 ( sizeof( * V_2 ) , V_24 ) ;
if ( ! V_2 )
return - V_26 ;
V_8 -> V_147 = 16 ;
V_2 -> clock = V_127 ;
F_81 ( V_8 ) ;
V_2 -> V_31 . type = V_100 ;
V_2 -> V_31 . V_148 = 2 ;
V_2 -> V_31 . V_149 = & V_150 ;
V_2 -> V_31 . line = 0 ;
V_2 -> V_31 . V_143 = & V_8 -> V_143 ;
V_2 -> V_31 . V_151 = 115200 ;
V_2 -> V_8 = V_8 ;
strcpy ( V_2 -> V_104 , V_8 -> V_152 ) ;
V_2 -> V_83 = ( T_1 ) V_8 -> V_83 ;
F_82 ( & V_2 -> V_81 ) ;
F_82 ( & V_2 -> V_14 ) ;
V_2 -> V_153 = 0 ;
V_2 -> V_48 = 0 ;
V_2 -> V_19 = 0 ;
V_2 -> V_97 = 0 ;
V_2 -> V_44 = 0 ;
V_146 = V_154 ;
V_13 = F_1 ( V_2 , ( V_60 * ) & V_146 , ( V_60 * ) & V_146 , 2 , 0 ) ;
if ( V_13 < 0 || V_146 == 0 || V_146 == 0xffff ) {
F_83 ( & V_8 -> V_143 , L_10 ,
V_146 ) ;
V_13 = - V_51 ;
goto V_155;
}
V_145 = ( void * ) F_84 ( V_24 ) ;
if ( ! V_145 ) {
V_13 = - V_26 ;
goto V_155;
}
V_2 -> V_35 . V_21 = V_145 ;
V_2 -> V_35 . V_36 = 0 ;
V_2 -> V_35 . V_61 = 0 ;
F_85 ( & V_2 -> V_45 ) ;
V_2 -> V_156 = F_53 ( F_43 ,
V_2 , L_11 ) ;
if ( F_54 ( V_2 -> V_156 ) ) {
V_13 = F_55 ( V_2 -> V_156 ) ;
goto V_157;
}
if ( V_2 -> V_83 ) {
V_13 = F_86 ( V_2 -> V_83 , F_47 ,
V_158 , L_12 , V_2 ) ;
if ( V_13 ) {
V_2 -> V_83 = 0 ;
F_87 ( & V_8 -> V_143 ,
L_13 ) ;
}
}
F_88 ( V_8 , V_2 ) ;
V_42 = V_2 ;
V_2 -> V_31 . V_159 = ( unsigned char V_160 * ) 0xff110000 ;
F_89 ( & V_144 , & V_2 -> V_31 ) ;
return 0 ;
V_157:
F_90 ( ( unsigned long ) V_145 ) ;
V_155:
F_11 ( V_2 ) ;
return V_13 ;
}
static int F_91 ( struct V_7 * V_143 )
{
struct V_1 * V_2 = F_74 ( V_143 ) ;
if ( ! V_2 )
return 0 ;
F_92 ( & V_144 , & V_2 -> V_31 ) ;
F_90 ( ( unsigned long ) V_2 -> V_35 . V_21 ) ;
if ( V_2 -> V_83 )
F_93 ( V_2 -> V_83 , V_2 ) ;
if ( V_2 -> V_156 )
F_56 ( V_2 -> V_156 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int T_2 F_94 ( void )
{
int V_13 = 0 ;
V_13 = F_95 ( & V_144 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_96 ( & V_161 ) ;
if ( V_13 )
F_97 ( & V_144 ) ;
return V_13 ;
}
static void T_5 F_98 ( void )
{
F_99 ( & V_161 ) ;
F_97 ( & V_144 ) ;
}
