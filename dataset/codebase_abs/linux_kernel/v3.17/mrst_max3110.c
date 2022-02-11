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
F_9 ( V_27 L_1 ,
V_28 , V_13 , V_20 ) ;
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
int V_13 , V_29 ;
V_29 = V_30 * sizeof( T_1 ) ;
V_21 = F_8 ( V_29 * 2 , V_24 | V_25 ) ;
if ( ! V_21 ) {
F_9 ( V_27 L_2 , V_28 ) ;
return 0 ;
}
V_22 = V_21 ;
V_23 = V_21 + V_29 ;
if ( F_1 ( V_2 , V_22 , V_23 , V_29 , 1 ) ) {
F_11 ( V_21 ) ;
return 0 ;
}
V_13 = F_10 ( V_2 , V_23 , V_30 ) ;
F_11 ( V_21 ) ;
return V_13 ;
}
static void F_13 ( struct V_31 * V_32 , int V_33 )
{
struct V_1 * V_2 =
F_14 ( V_32 , struct V_1 , V_32 ) ;
struct V_34 * V_35 = & V_2 -> V_36 ;
if ( F_15 ( V_35 ) ) {
V_35 -> V_21 [ V_35 -> V_37 ] = ( char ) V_33 ;
V_35 -> V_37 = ( V_35 -> V_37 + 1 ) & ( V_38 - 1 ) ;
}
}
static void F_16 ( struct V_39 * V_40 ,
const char * V_41 , unsigned int V_42 )
{
if ( ! V_43 )
return;
F_17 ( & V_43 -> V_32 , V_41 , V_42 , F_13 ) ;
if ( ! F_18 ( V_44 , & V_43 -> V_45 ) )
F_19 ( & V_43 -> V_46 ) ;
}
static int T_2
F_20 ( struct V_39 * V_40 , char * V_47 )
{
struct V_1 * V_2 = V_43 ;
int V_19 = 115200 ;
int V_48 = 8 ;
int V_49 = 'n' ;
int V_50 = 'n' ;
F_21 ( V_27 L_3 ) ;
if ( V_40 -> V_51 == - 1 )
V_40 -> V_51 = 0 ;
if ( ! V_2 ) {
F_22 ( V_27 L_4 ) ;
return - V_52 ;
}
if ( V_47 )
F_23 ( V_47 , & V_19 , & V_49 , & V_48 , & V_50 ) ;
return F_24 ( & V_2 -> V_32 , V_40 , V_19 , V_49 , V_48 , V_50 ) ;
}
static struct V_53 * F_25 ( struct V_39 * V_40 ,
int * V_51 )
{
struct V_54 * V_55 = V_40 -> V_56 ;
* V_51 = V_40 -> V_51 ;
return V_55 -> V_53 ;
}
static unsigned int F_26 ( struct V_31 * V_32 )
{
return 1 ;
}
static void F_27 ( struct V_31 * V_32 )
{
return;
}
static void F_28 ( struct V_31 * V_32 )
{
return;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
void * V_21 ;
T_1 * V_22 , * V_23 ;
int V_57 , V_5 , V_29 , V_58 , V_59 , V_13 = 0 ;
V_58 = V_60 * sizeof( T_1 ) * 2 ;
V_21 = F_8 ( V_58 , V_24 | V_25 ) ;
if ( ! V_21 )
return;
V_22 = V_21 ;
V_23 = V_21 + V_58 / 2 ;
while ( ! F_30 ( V_35 ) ) {
V_59 = F_31 ( V_35 ) ;
while ( V_59 ) {
V_5 = F_32 ( V_59 , V_60 ) ;
V_29 = V_5 * sizeof( T_1 ) ;
memset ( V_23 , 0 , V_29 ) ;
for ( V_57 = 0 ; V_57 < V_5 ; V_57 ++ ) {
V_22 [ V_57 ] = ( V_61 ) V_35 -> V_21 [ V_35 -> V_62 ] | V_63 ;
V_35 -> V_62 = ( V_35 -> V_62 + 1 ) &
( V_64 - 1 ) ;
}
V_13 = F_1 ( V_2 , V_22 , V_23 , V_29 , 0 ) ;
if ( V_13 )
F_9 ( V_27 L_5 ,
V_28 , V_13 ) ;
F_10 ( V_2 , V_23 , V_5 ) ;
V_2 -> V_32 . V_65 . V_66 += V_5 ;
V_59 -= V_5 ;
}
}
F_11 ( V_21 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = & V_2 -> V_32 ;
struct V_34 * V_35 = & V_32 -> V_67 -> V_35 ;
if ( F_30 ( V_35 ) || F_34 ( V_32 ) )
return;
F_29 ( V_2 , V_35 ) ;
if ( F_31 ( V_35 ) < V_68 )
F_35 ( V_32 ) ;
if ( F_30 ( V_35 ) )
F_27 ( V_32 ) ;
}
static void F_36 ( struct V_31 * V_32 )
{
struct V_1 * V_2 =
F_14 ( V_32 , struct V_1 , V_32 ) ;
if ( ! F_18 ( V_69 , & V_2 -> V_45 ) )
F_19 ( & V_2 -> V_46 ) ;
}
static int
F_10 ( struct V_1 * V_2 , unsigned short * V_70 , int V_5 )
{
struct V_31 * V_32 = & V_2 -> V_32 ;
struct V_71 * V_72 ;
char V_21 [ V_30 ] ;
int V_73 , V_74 , V_75 ;
if ( ! V_32 -> V_67 )
return 0 ;
V_72 = & V_32 -> V_67 -> V_32 ;
for ( V_73 = 0 , V_74 = 0 ; V_73 < V_5 ; V_73 ++ ) {
if ( V_70 [ V_73 ] & V_76 &&
F_37 ( V_32 ) )
continue;
if ( V_70 [ V_73 ] & V_77 ) {
if ( F_38 ( V_32 , V_70 [ V_73 ] & 0xff ) )
continue;
V_21 [ V_74 ++ ] = V_70 [ V_73 ] & 0xff ;
}
}
if ( ! V_74 )
return 0 ;
for ( V_73 = 0 ; V_74 ; V_73 += V_75 , V_74 -= V_75 ) {
V_75 = F_39 ( V_72 , V_74 ) ;
if ( V_75 ) {
F_40 ( V_72 , V_21 + V_73 , V_75 ) ;
V_32 -> V_65 . V_78 += V_75 ;
}
}
F_41 ( V_72 ) ;
return V_73 ;
}
static void F_42 ( struct V_1 * V_2 )
{
int V_79 = 1 , V_80 ;
do {
V_80 = F_12 ( V_2 ) ;
if ( V_80 ) {
V_79 = 5 ;
}
} while ( -- V_79 );
}
static int F_43 ( void * V_81 )
{
struct V_1 * V_2 = V_81 ;
T_3 * V_46 = & V_2 -> V_46 ;
int V_13 = 0 ;
struct V_34 * V_35 = & V_2 -> V_36 ;
F_21 ( V_27 L_6 ) ;
do {
F_44 ( * V_46 ,
V_2 -> V_45 || F_45 () ) ;
F_2 ( & V_2 -> V_82 ) ;
if ( F_46 ( V_83 , & V_2 -> V_45 ) )
F_42 ( V_2 ) ;
if ( F_46 ( V_44 , & V_2 -> V_45 ) )
F_29 ( V_2 , V_35 ) ;
if ( F_46 ( V_69 , & V_2 -> V_45 ) )
F_33 ( V_2 ) ;
F_6 ( & V_2 -> V_82 ) ;
} while ( ! F_45 () );
return V_13 ;
}
static T_4 F_47 ( int V_84 , void * V_85 )
{
struct V_1 * V_2 = V_85 ;
if ( ! F_18 ( V_83 , & V_2 -> V_45 ) )
F_19 ( & V_2 -> V_46 ) ;
return V_86 ;
}
static int F_48 ( void * V_81 )
{
struct V_1 * V_2 = V_81 ;
F_21 ( V_27 L_7 ) ;
do {
if ( F_49 ( & V_2 -> V_82 ) ) {
F_42 ( V_2 ) ;
F_6 ( & V_2 -> V_82 ) ;
}
F_50 ( V_87 ) ;
F_51 ( V_88 / 20 ) ;
} while ( ! F_45 () );
return 0 ;
}
static int F_52 ( struct V_31 * V_32 )
{
struct V_1 * V_2 =
F_14 ( V_32 , struct V_1 , V_32 ) ;
T_1 V_89 = 0 ;
int V_13 = 0 ;
if ( V_32 -> line != 0 ) {
F_22 ( V_27 L_8 ) ;
return - 1 ;
}
V_89 = V_90 | V_91
| V_92
| V_93
| V_94 ;
V_32 -> V_67 -> V_32 . V_95 = 1 ;
if ( V_2 -> V_84 ) {
V_89 |= V_96 ;
} else {
V_2 -> V_97 =
F_53 ( F_48 , V_2 , L_9 ) ;
if ( F_54 ( V_2 -> V_97 ) ) {
V_13 = F_55 ( V_2 -> V_97 ) ;
V_2 -> V_97 = NULL ;
F_22 ( V_27 L_10 ) ;
return V_13 ;
}
}
V_13 = F_7 ( V_2 , V_89 ) ;
if ( V_13 ) {
if ( V_2 -> V_97 )
F_56 ( V_2 -> V_97 ) ;
V_2 -> V_97 = NULL ;
return V_13 ;
}
V_2 -> V_98 = V_89 ;
return 0 ;
}
static void F_57 ( struct V_31 * V_32 )
{
struct V_1 * V_2 =
F_14 ( V_32 , struct V_1 , V_32 ) ;
T_1 V_89 ;
if ( V_2 -> V_97 ) {
F_56 ( V_2 -> V_97 ) ;
V_2 -> V_97 = NULL ;
}
V_89 = V_90 | V_99 ;
F_7 ( V_2 , V_89 ) ;
}
static void F_58 ( struct V_31 * V_32 )
{
}
static int F_59 ( struct V_31 * V_32 )
{
return 0 ;
}
static void F_60 ( struct V_31 * V_32 , int V_100 )
{
V_32 -> type = V_101 ;
}
static int
F_61 ( struct V_31 * V_32 , struct V_102 * V_103 )
{
return - V_104 ;
}
static const char * F_62 ( struct V_31 * V_32 )
{
struct V_1 * V_2 =
F_14 ( V_32 , struct V_1 , V_32 ) ;
return V_2 -> V_105 ;
}
static void
F_63 ( struct V_31 * V_32 , struct V_106 * V_107 ,
struct V_106 * V_108 )
{
struct V_1 * V_2 =
F_14 ( V_32 , struct V_1 , V_32 ) ;
unsigned char V_109 ;
unsigned int V_19 , V_49 = 0 ;
int V_110 = - 1 ;
T_1 V_111 = V_2 -> V_98 ;
switch ( V_107 -> V_112 & V_113 ) {
case V_114 :
V_109 = V_115 ;
V_111 |= V_116 ;
break;
default:
V_107 -> V_112 &= ~ V_113 ;
V_107 -> V_112 |= V_117 ;
case V_117 :
V_109 = V_118 ;
V_111 |= V_93 ;
break;
}
V_19 = F_64 ( V_32 , V_107 , V_108 , 0 , 230400 ) ;
switch ( V_19 ) {
case 300 :
V_110 = V_119 ;
break;
case 600 :
V_110 = V_120 ;
break;
case 1200 :
V_110 = V_121 ;
break;
case 2400 :
V_110 = V_122 ;
break;
case 4800 :
V_110 = V_123 ;
break;
case 9600 :
V_110 = V_124 ;
break;
case 19200 :
V_110 = V_125 ;
break;
case 38400 :
V_110 = V_126 ;
break;
case 57600 :
V_110 = V_94 ;
break;
case 115200 :
V_110 = V_127 ;
break;
case 230400 :
if ( V_2 -> clock & V_128 )
break;
default:
V_19 = V_2 -> V_19 ;
V_110 = V_2 -> V_98 & V_129 ;
F_65 ( V_107 , V_19 , V_19 ) ;
}
if ( V_2 -> clock & V_128 ) {
V_110 += 1 ;
if ( V_19 == 300 ) {
V_19 = 600 ;
V_110 = V_119 ;
}
if ( V_19 == 230400 )
V_110 = V_127 ;
F_65 ( V_107 , V_19 , V_19 ) ;
}
V_111 = ( V_111 & ~ V_129 ) | V_110 ;
if ( F_66 ( V_107 -> V_112 & V_130 ) )
V_107 -> V_112 &= ~ V_130 ;
if ( V_107 -> V_112 & V_131 )
V_111 |= V_132 ;
else
V_111 &= ~ V_132 ;
if ( V_107 -> V_112 & V_133 ) {
V_111 |= V_134 ;
V_49 |= V_135 ;
} else
V_111 &= ~ V_134 ;
if ( ! ( V_107 -> V_112 & V_136 ) )
V_49 |= V_137 ;
V_2 -> V_49 = V_49 ;
F_67 ( V_32 , V_107 -> V_112 , V_19 ) ;
V_111 |= V_90 ;
if ( V_111 != V_2 -> V_98 ) {
if ( ! F_7 ( V_2 , V_111 ) ) {
V_2 -> V_98 = V_111 ;
V_2 -> V_19 = V_19 ;
}
}
}
static unsigned int F_68 ( struct V_31 * V_32 )
{
return V_138 | V_139 | V_138 ;
}
static void F_69 ( struct V_31 * V_32 , unsigned int V_140 )
{
}
static void F_70 ( struct V_31 * V_32 , int V_141 )
{
}
static void F_71 ( struct V_31 * V_32 , unsigned int V_67 ,
unsigned int V_142 )
{
}
static int F_72 ( struct V_143 * V_144 )
{
struct V_7 * V_8 = F_73 ( V_144 ) ;
struct V_1 * V_2 = F_74 ( V_8 ) ;
if ( V_2 -> V_84 > 0 )
F_75 ( V_2 -> V_84 ) ;
F_76 ( & V_145 , & V_2 -> V_32 ) ;
F_7 ( V_2 , V_2 -> V_98 | V_99 ) ;
return 0 ;
}
static int F_77 ( struct V_143 * V_144 )
{
struct V_7 * V_8 = F_73 ( V_144 ) ;
struct V_1 * V_2 = F_74 ( V_8 ) ;
F_7 ( V_2 , V_2 -> V_98 ) ;
F_78 ( & V_145 , & V_2 -> V_32 ) ;
if ( V_2 -> V_84 > 0 )
F_79 ( V_2 -> V_84 ) ;
return 0 ;
}
static int F_80 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
void * V_146 ;
T_1 V_147 ;
int V_13 = 0 ;
V_2 = F_8 ( sizeof( * V_2 ) , V_24 ) ;
if ( ! V_2 )
return - V_26 ;
V_8 -> V_148 = 16 ;
V_2 -> clock = V_128 ;
F_81 ( V_8 ) ;
V_2 -> V_32 . type = V_101 ;
V_2 -> V_32 . V_149 = 2 ;
V_2 -> V_32 . V_150 = & V_151 ;
V_2 -> V_32 . line = 0 ;
V_2 -> V_32 . V_144 = & V_8 -> V_144 ;
V_2 -> V_32 . V_152 = 115200 ;
V_2 -> V_8 = V_8 ;
strcpy ( V_2 -> V_105 , V_8 -> V_153 ) ;
V_2 -> V_84 = ( T_1 ) V_8 -> V_84 ;
F_82 ( & V_2 -> V_82 ) ;
F_82 ( & V_2 -> V_14 ) ;
V_2 -> V_154 = 0 ;
V_2 -> V_49 = 0 ;
V_2 -> V_19 = 0 ;
V_2 -> V_98 = 0 ;
V_2 -> V_45 = 0 ;
V_147 = V_155 ;
V_13 = F_1 ( V_2 , ( V_61 * ) & V_147 , ( V_61 * ) & V_147 , 2 , 0 ) ;
if ( V_13 < 0 || V_147 == 0 || V_147 == 0xffff ) {
F_83 ( & V_8 -> V_144 , L_11 ,
V_147 ) ;
V_13 = - V_52 ;
goto V_156;
}
V_146 = ( void * ) F_84 ( V_24 ) ;
if ( ! V_146 ) {
V_13 = - V_26 ;
goto V_156;
}
V_2 -> V_36 . V_21 = V_146 ;
V_2 -> V_36 . V_37 = 0 ;
V_2 -> V_36 . V_62 = 0 ;
F_85 ( & V_2 -> V_46 ) ;
V_2 -> V_157 = F_53 ( F_43 ,
V_2 , L_12 ) ;
if ( F_54 ( V_2 -> V_157 ) ) {
V_13 = F_55 ( V_2 -> V_157 ) ;
goto V_158;
}
if ( V_2 -> V_84 ) {
V_13 = F_86 ( V_2 -> V_84 , F_47 ,
V_159 , L_13 , V_2 ) ;
if ( V_13 ) {
V_2 -> V_84 = 0 ;
F_87 ( & V_8 -> V_144 ,
L_14 ) ;
}
}
F_88 ( V_8 , V_2 ) ;
V_43 = V_2 ;
V_2 -> V_32 . V_160 = ( unsigned char V_161 * ) 0xff110000 ;
F_89 ( & V_145 , & V_2 -> V_32 ) ;
return 0 ;
V_158:
F_90 ( ( unsigned long ) V_146 ) ;
V_156:
F_11 ( V_2 ) ;
return V_13 ;
}
static int F_91 ( struct V_7 * V_144 )
{
struct V_1 * V_2 = F_74 ( V_144 ) ;
if ( ! V_2 )
return 0 ;
F_92 ( & V_145 , & V_2 -> V_32 ) ;
F_90 ( ( unsigned long ) V_2 -> V_36 . V_21 ) ;
if ( V_2 -> V_84 )
F_93 ( V_2 -> V_84 , V_2 ) ;
if ( V_2 -> V_157 )
F_56 ( V_2 -> V_157 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int T_2 F_94 ( void )
{
int V_13 = 0 ;
V_13 = F_95 ( & V_145 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_96 ( & V_162 ) ;
if ( V_13 )
F_97 ( & V_145 ) ;
return V_13 ;
}
static void T_5 F_98 ( void )
{
F_99 ( & V_162 ) ;
F_97 ( & V_145 ) ;
}
