static int F_1 ( struct V_1 * V_2 ,
const void * V_3 , void * V_4 , unsigned V_5 , int V_6 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 V_10 ;
struct V_11 V_12 ;
int V_13 ;
F_2 ( & V_10 ) ;
memset ( & V_12 , 0 , sizeof V_12 ) ;
V_12 . V_5 = V_5 ;
V_12 . V_14 = V_3 ;
V_12 . V_15 = V_4 ;
F_3 ( & V_12 , & V_10 ) ;
if ( V_6 )
V_12 . V_16 = V_8 -> V_17 ;
else if ( V_2 -> V_18 )
V_12 . V_16 = V_2 -> V_18 ;
V_13 = F_4 ( V_8 , & V_10 ) ;
return V_13 ;
}
static int F_5 ( struct V_1 * V_2 , const T_1 V_19 )
{
void * V_20 ;
T_1 * V_21 , * V_22 ;
int V_13 ;
V_20 = F_6 ( 8 , V_23 | V_24 ) ;
if ( ! V_20 )
return - V_25 ;
V_21 = V_20 ;
V_22 = V_20 + 4 ;
* V_21 = V_19 ;
V_13 = F_1 ( V_2 , V_21 , V_22 , 2 , 1 ) ;
if ( V_13 ) {
F_7 ( V_26 L_1 ,
V_27 , V_13 , V_19 ) ;
goto exit;
}
F_8 ( V_2 , V_22 , 1 ) ;
exit:
F_9 ( V_20 ) ;
return V_13 ;
}
static int F_10 ( struct V_1 * V_2 )
{
void * V_20 ;
T_1 * V_21 , * V_22 ;
int V_13 , V_28 ;
V_28 = V_29 * sizeof( T_1 ) ;
V_20 = F_6 ( V_28 * 2 , V_23 | V_24 ) ;
if ( ! V_20 ) {
F_7 ( V_26 L_2 , V_27 ) ;
return 0 ;
}
V_21 = V_20 ;
V_22 = V_20 + V_28 ;
if ( F_1 ( V_2 , V_21 , V_22 , V_28 , 1 ) ) {
F_9 ( V_20 ) ;
return 0 ;
}
V_13 = F_8 ( V_2 , V_22 , V_29 ) ;
F_9 ( V_20 ) ;
return V_13 ;
}
static void F_11 ( struct V_30 * V_31 , int V_32 )
{
struct V_1 * V_2 =
F_12 ( V_31 , struct V_1 , V_31 ) ;
struct V_33 * V_34 = & V_2 -> V_35 ;
if ( F_13 ( V_34 ) ) {
V_34 -> V_20 [ V_34 -> V_36 ] = ( char ) V_32 ;
V_34 -> V_36 = ( V_34 -> V_36 + 1 ) & ( V_37 - 1 ) ;
}
}
static void F_14 ( struct V_38 * V_39 ,
const char * V_40 , unsigned int V_41 )
{
if ( ! V_42 )
return;
F_15 ( & V_42 -> V_31 , V_40 , V_41 , F_11 ) ;
if ( ! F_16 ( V_43 , & V_42 -> V_44 ) )
F_17 ( & V_42 -> V_45 ) ;
}
static int T_2
F_18 ( struct V_38 * V_39 , char * V_46 )
{
struct V_1 * V_2 = V_42 ;
int V_18 = 115200 ;
int V_47 = 8 ;
int V_48 = 'n' ;
int V_49 = 'n' ;
F_19 ( V_26 L_3 ) ;
if ( V_39 -> V_50 == - 1 )
V_39 -> V_50 = 0 ;
if ( ! V_2 ) {
F_20 ( V_26 L_4 ) ;
return - V_51 ;
}
if ( V_46 )
F_21 ( V_46 , & V_18 , & V_48 , & V_47 , & V_49 ) ;
return F_22 ( & V_2 -> V_31 , V_39 , V_18 , V_48 , V_47 , V_49 ) ;
}
static struct V_52 * F_23 ( struct V_38 * V_39 ,
int * V_50 )
{
struct V_53 * V_54 = V_39 -> V_55 ;
* V_50 = V_39 -> V_50 ;
return V_54 -> V_52 ;
}
static unsigned int F_24 ( struct V_30 * V_31 )
{
return 1 ;
}
static void F_25 ( struct V_30 * V_31 )
{
return;
}
static void F_26 ( struct V_30 * V_31 )
{
return;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
void * V_20 ;
T_1 * V_21 , * V_22 ;
int V_56 , V_5 , V_28 , V_57 , V_58 , V_13 = 0 ;
V_57 = V_59 * sizeof( T_1 ) * 2 ;
V_20 = F_6 ( V_57 , V_23 | V_24 ) ;
if ( ! V_20 )
return;
V_21 = V_20 ;
V_22 = V_20 + V_57 / 2 ;
while ( ! F_28 ( V_34 ) ) {
V_58 = F_29 ( V_34 ) ;
while ( V_58 ) {
V_5 = F_30 ( V_58 , V_59 ) ;
V_28 = V_5 * sizeof( T_1 ) ;
memset ( V_22 , 0 , V_28 ) ;
for ( V_56 = 0 ; V_56 < V_5 ; V_56 ++ ) {
V_21 [ V_56 ] = ( V_60 ) V_34 -> V_20 [ V_34 -> V_61 ] | V_62 ;
V_34 -> V_61 = ( V_34 -> V_61 + 1 ) &
( V_63 - 1 ) ;
}
V_13 = F_1 ( V_2 , V_21 , V_22 , V_28 , 0 ) ;
if ( V_13 )
F_7 ( V_26 L_5 ,
V_27 , V_13 ) ;
F_8 ( V_2 , V_22 , V_5 ) ;
V_2 -> V_31 . V_64 . V_65 += V_5 ;
V_58 -= V_5 ;
}
}
F_9 ( V_20 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = & V_2 -> V_31 ;
struct V_33 * V_34 = & V_31 -> V_66 -> V_34 ;
if ( F_28 ( V_34 ) || F_32 ( V_31 ) )
return;
F_27 ( V_2 , V_34 ) ;
if ( F_29 ( V_34 ) < V_67 )
F_33 ( V_31 ) ;
if ( F_28 ( V_34 ) )
F_25 ( V_31 ) ;
}
static void F_34 ( struct V_30 * V_31 )
{
struct V_1 * V_2 =
F_12 ( V_31 , struct V_1 , V_31 ) ;
if ( ! F_16 ( V_68 , & V_2 -> V_44 ) )
F_17 ( & V_2 -> V_45 ) ;
}
static int
F_8 ( struct V_1 * V_2 , unsigned short * V_69 , int V_5 )
{
struct V_30 * V_31 = & V_2 -> V_31 ;
struct V_70 * V_71 ;
char V_20 [ V_29 ] ;
int V_72 , V_73 , V_74 ;
if ( ! V_31 -> V_66 )
return 0 ;
V_71 = & V_31 -> V_66 -> V_31 ;
for ( V_72 = 0 , V_73 = 0 ; V_72 < V_5 ; V_72 ++ ) {
if ( V_69 [ V_72 ] & V_75 &&
F_35 ( V_31 ) )
continue;
if ( V_69 [ V_72 ] & V_76 ) {
if ( F_36 ( V_31 , V_69 [ V_72 ] & 0xff ) )
continue;
V_20 [ V_73 ++ ] = V_69 [ V_72 ] & 0xff ;
}
}
if ( ! V_73 )
return 0 ;
for ( V_72 = 0 ; V_73 ; V_72 += V_74 , V_73 -= V_74 ) {
V_74 = F_37 ( V_71 , V_73 ) ;
if ( V_74 ) {
F_38 ( V_71 , V_20 + V_72 , V_74 ) ;
V_31 -> V_64 . V_77 += V_74 ;
}
}
F_39 ( V_71 ) ;
return V_72 ;
}
static void F_40 ( struct V_1 * V_2 )
{
int V_78 = 1 , V_79 ;
do {
V_79 = F_10 ( V_2 ) ;
if ( V_79 ) {
V_78 = 5 ;
}
} while ( -- V_78 );
}
static int F_41 ( void * V_80 )
{
struct V_1 * V_2 = V_80 ;
T_3 * V_45 = & V_2 -> V_45 ;
int V_13 = 0 ;
struct V_33 * V_34 = & V_2 -> V_35 ;
F_19 ( V_26 L_6 ) ;
do {
F_42 ( * V_45 ,
V_2 -> V_44 || F_43 () ) ;
F_44 ( & V_2 -> V_81 ) ;
if ( F_45 ( V_82 , & V_2 -> V_44 ) )
F_40 ( V_2 ) ;
if ( F_45 ( V_43 , & V_2 -> V_44 ) )
F_27 ( V_2 , V_34 ) ;
if ( F_45 ( V_68 , & V_2 -> V_44 ) )
F_31 ( V_2 ) ;
F_46 ( & V_2 -> V_81 ) ;
} while ( ! F_43 () );
return V_13 ;
}
static T_4 F_47 ( int V_83 , void * V_84 )
{
struct V_1 * V_2 = V_84 ;
if ( ! F_16 ( V_82 , & V_2 -> V_44 ) )
F_17 ( & V_2 -> V_45 ) ;
return V_85 ;
}
static int F_48 ( void * V_80 )
{
struct V_1 * V_2 = V_80 ;
F_19 ( V_26 L_7 ) ;
do {
if ( F_49 ( & V_2 -> V_81 ) ) {
F_40 ( V_2 ) ;
F_46 ( & V_2 -> V_81 ) ;
}
F_50 ( V_86 ) ;
F_51 ( V_87 / 20 ) ;
} while ( ! F_43 () );
return 0 ;
}
static int F_52 ( struct V_30 * V_31 )
{
struct V_1 * V_2 =
F_12 ( V_31 , struct V_1 , V_31 ) ;
T_1 V_88 = 0 ;
int V_13 = 0 ;
if ( V_31 -> line != 0 ) {
F_20 ( V_26 L_8 ) ;
return - 1 ;
}
V_88 = V_89 | V_90
| V_91
| V_92
| V_93 ;
V_31 -> V_66 -> V_31 . V_94 = 1 ;
if ( V_2 -> V_83 ) {
V_2 -> V_95 = NULL ;
V_13 = F_53 ( V_2 -> V_83 , F_47 ,
V_96 , L_9 , V_2 ) ;
if ( V_13 ) {
V_2 -> V_83 = 0 ;
F_20 ( V_26 L_10 ) ;
} else {
V_88 |= V_97 ;
}
}
if ( V_2 -> V_83 == 0 ) {
V_2 -> V_95 =
F_54 ( F_48 , V_2 , L_11 ) ;
if ( F_55 ( V_2 -> V_95 ) ) {
V_13 = F_56 ( V_2 -> V_95 ) ;
V_2 -> V_95 = NULL ;
F_20 ( V_26 L_12 ) ;
return V_13 ;
}
}
V_13 = F_5 ( V_2 , V_88 ) ;
if ( V_13 ) {
if ( V_2 -> V_83 )
F_57 ( V_2 -> V_83 , V_2 ) ;
if ( V_2 -> V_95 )
F_58 ( V_2 -> V_95 ) ;
V_2 -> V_95 = NULL ;
return V_13 ;
}
V_2 -> V_98 = V_88 ;
return 0 ;
}
static void F_59 ( struct V_30 * V_31 )
{
struct V_1 * V_2 =
F_12 ( V_31 , struct V_1 , V_31 ) ;
T_1 V_88 ;
if ( V_2 -> V_95 ) {
F_58 ( V_2 -> V_95 ) ;
V_2 -> V_95 = NULL ;
}
if ( V_2 -> V_83 )
F_57 ( V_2 -> V_83 , V_2 ) ;
V_88 = V_89 | V_99 ;
F_5 ( V_2 , V_88 ) ;
}
static void F_60 ( struct V_30 * V_31 )
{
}
static int F_61 ( struct V_30 * V_31 )
{
return 0 ;
}
static void F_62 ( struct V_30 * V_31 , int V_100 )
{
V_31 -> type = V_101 ;
}
static int
F_63 ( struct V_30 * V_31 , struct V_102 * V_103 )
{
return - V_104 ;
}
static const char * F_64 ( struct V_30 * V_31 )
{
struct V_1 * V_2 =
F_12 ( V_31 , struct V_1 , V_31 ) ;
return V_2 -> V_105 ;
}
static void
F_65 ( struct V_30 * V_31 , struct V_106 * V_107 ,
struct V_106 * V_108 )
{
struct V_1 * V_2 =
F_12 ( V_31 , struct V_1 , V_31 ) ;
unsigned char V_109 ;
unsigned int V_18 , V_48 = 0 ;
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
V_111 |= V_92 ;
break;
}
V_18 = F_66 ( V_31 , V_107 , V_108 , 0 , 230400 ) ;
switch ( V_18 ) {
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
V_110 = V_93 ;
break;
case 115200 :
V_110 = V_127 ;
break;
case 230400 :
if ( V_2 -> clock & V_128 )
break;
default:
V_18 = V_2 -> V_18 ;
V_110 = V_2 -> V_98 & V_129 ;
F_67 ( V_107 , V_18 , V_18 ) ;
}
if ( V_2 -> clock & V_128 ) {
V_110 += 1 ;
if ( V_18 == 300 ) {
V_18 = 600 ;
V_110 = V_119 ;
}
if ( V_18 == 230400 )
V_110 = V_127 ;
F_67 ( V_107 , V_18 , V_18 ) ;
}
V_111 = ( V_111 & ~ V_129 ) | V_110 ;
if ( F_68 ( V_107 -> V_112 & V_130 ) )
V_107 -> V_112 &= ~ V_130 ;
if ( V_107 -> V_112 & V_131 )
V_111 |= V_132 ;
else
V_111 &= ~ V_132 ;
if ( V_107 -> V_112 & V_133 ) {
V_111 |= V_134 ;
V_48 |= V_135 ;
} else
V_111 &= ~ V_134 ;
if ( ! ( V_107 -> V_112 & V_136 ) )
V_48 |= V_137 ;
V_2 -> V_48 = V_48 ;
F_69 ( V_31 , V_107 -> V_112 , V_18 ) ;
V_111 |= V_89 ;
if ( V_111 != V_2 -> V_98 ) {
if ( ! F_5 ( V_2 , V_111 ) ) {
V_2 -> V_98 = V_111 ;
V_2 -> V_18 = V_18 ;
}
}
}
static unsigned int F_70 ( struct V_30 * V_31 )
{
return V_138 | V_139 | V_138 ;
}
static void F_71 ( struct V_30 * V_31 , unsigned int V_140 )
{
}
static void F_72 ( struct V_30 * V_31 , int V_141 )
{
}
static void F_73 ( struct V_30 * V_31 , unsigned int V_66 ,
unsigned int V_142 )
{
}
static void F_74 ( struct V_30 * V_31 )
{
}
static int F_75 ( struct V_143 * V_144 )
{
struct V_7 * V_8 = F_76 ( V_144 ) ;
struct V_1 * V_2 = F_77 ( V_8 ) ;
F_78 ( V_2 -> V_83 ) ;
F_79 ( & V_145 , & V_2 -> V_31 ) ;
F_5 ( V_2 , V_2 -> V_98 | V_99 ) ;
return 0 ;
}
static int F_80 ( struct V_143 * V_144 )
{
struct V_7 * V_8 = F_76 ( V_144 ) ;
struct V_1 * V_2 = F_77 ( V_8 ) ;
F_5 ( V_2 , V_2 -> V_98 ) ;
F_81 ( & V_145 , & V_2 -> V_31 ) ;
F_82 ( V_2 -> V_83 ) ;
return 0 ;
}
static int F_83 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
void * V_146 ;
T_1 V_147 ;
int V_13 = 0 ;
V_2 = F_6 ( sizeof( * V_2 ) , V_23 ) ;
if ( ! V_2 )
return - V_25 ;
V_8 -> V_148 = 16 ;
V_2 -> clock = V_128 ;
F_84 ( V_8 ) ;
V_2 -> V_31 . type = V_101 ;
V_2 -> V_31 . V_149 = 2 ;
V_2 -> V_31 . V_150 = & V_151 ;
V_2 -> V_31 . line = 0 ;
V_2 -> V_31 . V_144 = & V_8 -> V_144 ;
V_2 -> V_31 . V_152 = 115200 ;
V_2 -> V_8 = V_8 ;
strcpy ( V_2 -> V_105 , V_8 -> V_153 ) ;
V_2 -> V_83 = ( T_1 ) V_8 -> V_83 ;
F_85 ( & V_2 -> V_81 ) ;
V_2 -> V_154 = 0 ;
V_2 -> V_48 = 0 ;
V_2 -> V_18 = 0 ;
V_2 -> V_98 = 0 ;
V_2 -> V_44 = 0 ;
V_147 = V_155 ;
V_13 = F_1 ( V_2 , ( V_60 * ) & V_147 , ( V_60 * ) & V_147 , 2 , 0 ) ;
if ( V_13 < 0 || V_147 == 0 || V_147 == 0xffff ) {
F_86 ( & V_8 -> V_144 , L_13 ,
V_147 ) ;
V_13 = - V_51 ;
goto V_156;
}
V_146 = ( void * ) F_87 ( V_23 ) ;
if ( ! V_146 ) {
V_13 = - V_25 ;
goto V_156;
}
V_2 -> V_35 . V_20 = V_146 ;
V_2 -> V_35 . V_36 = 0 ;
V_2 -> V_35 . V_61 = 0 ;
F_88 ( & V_2 -> V_45 ) ;
V_2 -> V_157 = F_54 ( F_41 ,
V_2 , L_14 ) ;
if ( F_55 ( V_2 -> V_157 ) ) {
V_13 = F_56 ( V_2 -> V_157 ) ;
goto V_158;
}
F_89 ( V_8 , V_2 ) ;
V_42 = V_2 ;
V_2 -> V_31 . V_159 = ( void * ) 0xff110000 ;
F_90 ( & V_145 , & V_2 -> V_31 ) ;
return 0 ;
V_158:
F_91 ( ( unsigned long ) V_146 ) ;
V_156:
F_9 ( V_2 ) ;
return V_13 ;
}
static int F_92 ( struct V_7 * V_144 )
{
struct V_1 * V_2 = F_77 ( V_144 ) ;
if ( ! V_2 )
return 0 ;
F_93 ( & V_145 , & V_2 -> V_31 ) ;
F_91 ( ( unsigned long ) V_2 -> V_35 . V_20 ) ;
if ( V_2 -> V_157 )
F_58 ( V_2 -> V_157 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static int T_2 F_94 ( void )
{
int V_13 = 0 ;
V_13 = F_95 ( & V_145 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_96 ( & V_160 ) ;
if ( V_13 )
F_97 ( & V_145 ) ;
return V_13 ;
}
static void T_5 F_98 ( void )
{
F_99 ( & V_160 ) ;
F_97 ( & V_145 ) ;
}
