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
T_2 V_23 ;
int V_13 ;
V_20 = F_6 ( 8 , V_24 | V_25 ) ;
if ( ! V_20 )
return - V_26 ;
V_21 = V_20 ;
V_22 = V_20 + 4 ;
* V_21 = V_19 ;
V_13 = F_1 ( V_2 , V_21 , V_22 , 2 , 1 ) ;
if ( V_13 ) {
F_7 ( V_27 L_1 ,
V_28 , V_13 , V_19 ) ;
goto exit;
}
if ( * V_22 & V_29 ) {
V_23 = * V_22 & 0xff ;
F_8 ( V_2 , & V_23 , 1 ) ;
}
exit:
F_9 ( V_20 ) ;
return V_13 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 * V_4 )
{
void * V_20 ;
T_1 * V_21 , * V_22 ;
T_2 * V_30 , V_31 [ V_32 ] ;
int V_33 , V_34 , V_35 ;
V_35 = V_32 * sizeof( T_1 ) ;
V_20 = F_6 ( V_35 * 2 , V_24 | V_25 ) ;
if ( ! V_20 ) {
F_7 ( V_27 L_2 , V_28 ) ;
return 0 ;
}
V_21 = V_20 ;
V_22 = V_20 + V_35 ;
if ( F_1 ( V_2 , V_21 , V_22 , V_35 , 1 ) ) {
F_9 ( V_20 ) ;
return 0 ;
}
V_30 = V_4 ? V_4 : V_31 ;
for ( V_33 = 0 , V_34 = 0 ; V_33 < V_32 ; V_33 ++ ) {
if ( V_22 [ V_33 ] & V_29 )
V_30 [ V_34 ++ ] = V_22 [ V_33 ] & 0xff ;
}
if ( V_34 && ( V_30 == V_31 ) )
F_8 ( V_2 , V_31 , V_34 ) ;
F_9 ( V_20 ) ;
return V_34 ;
}
static void F_11 ( struct V_36 * V_37 , int V_23 )
{
struct V_1 * V_2 =
F_12 ( V_37 , struct V_1 , V_37 ) ;
struct V_38 * V_39 = & V_2 -> V_40 ;
if ( F_13 ( V_39 ) ) {
V_39 -> V_20 [ V_39 -> V_41 ] = ( char ) V_23 ;
V_39 -> V_41 = ( V_39 -> V_41 + 1 ) & ( V_42 - 1 ) ;
}
}
static void F_14 ( struct V_43 * V_44 ,
const char * V_45 , unsigned int V_46 )
{
if ( ! V_47 )
return;
F_15 ( & V_47 -> V_37 , V_45 , V_46 , F_11 ) ;
if ( ! F_16 ( V_48 , & V_47 -> V_49 ) )
F_17 ( V_47 -> V_50 ) ;
}
static int T_3
F_18 ( struct V_43 * V_44 , char * V_51 )
{
struct V_1 * V_2 = V_47 ;
int V_18 = 115200 ;
int V_52 = 8 ;
int V_53 = 'n' ;
int V_54 = 'n' ;
F_19 ( V_27 L_3 ) ;
if ( V_44 -> V_55 == - 1 )
V_44 -> V_55 = 0 ;
if ( ! V_2 ) {
F_20 ( V_27 L_4 ) ;
return - V_56 ;
}
if ( V_51 )
F_21 ( V_51 , & V_18 , & V_53 , & V_52 , & V_54 ) ;
return F_22 ( & V_2 -> V_37 , V_44 , V_18 , V_53 , V_52 , V_54 ) ;
}
static struct V_57 * F_23 ( struct V_43 * V_44 ,
int * V_55 )
{
struct V_58 * V_59 = V_44 -> V_60 ;
* V_55 = V_44 -> V_55 ;
return V_59 -> V_57 ;
}
static unsigned int F_24 ( struct V_36 * V_37 )
{
return 1 ;
}
static void F_25 ( struct V_36 * V_37 )
{
return;
}
static void F_26 ( struct V_36 * V_37 )
{
return;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_38 * V_39 )
{
void * V_20 ;
T_1 * V_21 , * V_22 ;
T_2 V_31 [ V_61 ] ;
int V_33 , V_34 , V_5 , V_35 , V_62 , V_63 , V_13 = 0 ;
V_62 = V_61 * sizeof( T_1 ) * 2 ;
V_20 = F_6 ( V_62 , V_24 | V_25 ) ;
if ( ! V_20 )
return;
V_21 = V_20 ;
V_22 = V_20 + V_62 / 2 ;
while ( ! F_28 ( V_39 ) ) {
V_63 = F_29 ( V_39 ) ;
while ( V_63 ) {
V_5 = F_30 ( V_63 , V_61 ) ;
V_35 = V_5 * sizeof( T_1 ) ;
memset ( V_22 , 0 , V_35 ) ;
for ( V_33 = 0 ; V_33 < V_5 ; V_33 ++ ) {
V_21 [ V_33 ] = ( T_2 ) V_39 -> V_20 [ V_39 -> V_64 ] | V_65 ;
V_39 -> V_64 = ( V_39 -> V_64 + 1 ) &
( V_66 - 1 ) ;
}
V_13 = F_1 ( V_2 , V_21 , V_22 , V_35 , 0 ) ;
if ( V_13 )
F_7 ( V_27 L_5 ,
V_28 , V_13 ) ;
for ( V_33 = 0 , V_34 = 0 ; V_33 < V_5 ; V_33 ++ ) {
if ( V_22 [ V_33 ] & V_29 )
V_31 [ V_34 ++ ] = V_22 [ V_33 ] & 0xff ;
}
if ( V_34 )
F_8 ( V_2 , V_31 , V_34 ) ;
V_2 -> V_37 . V_67 . V_68 += V_5 ;
V_63 -= V_5 ;
}
}
F_9 ( V_20 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = & V_2 -> V_37 ;
struct V_38 * V_39 = & V_37 -> V_69 -> V_39 ;
if ( F_28 ( V_39 ) || F_32 ( V_37 ) )
return;
F_27 ( V_2 , V_39 ) ;
if ( F_29 ( V_39 ) < V_70 )
F_33 ( V_37 ) ;
if ( F_28 ( V_39 ) )
F_25 ( V_37 ) ;
}
static void F_34 ( struct V_36 * V_37 )
{
struct V_1 * V_2 =
F_12 ( V_37 , struct V_1 , V_37 ) ;
if ( ! F_16 ( V_71 , & V_2 -> V_49 ) )
F_17 ( V_2 -> V_50 ) ;
}
static void F_8 ( struct V_1 * V_2 , unsigned char * V_72 , int V_5 )
{
struct V_36 * V_37 = & V_2 -> V_37 ;
struct V_73 * V_74 ;
int V_75 ;
if ( ! V_37 -> V_69 )
return;
V_74 = V_37 -> V_69 -> V_37 . V_74 ;
if ( ! V_74 )
return;
while ( V_5 ) {
V_75 = F_35 ( V_74 , V_5 ) ;
if ( V_75 ) {
F_36 ( V_74 , V_72 , V_75 ) ;
V_72 += V_75 ;
V_37 -> V_67 . V_76 += V_75 ;
}
V_5 -= V_75 ;
}
F_37 ( V_74 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
int V_77 = 1 , V_78 , V_79 = 0 ;
T_2 V_80 [ 512 ] , * V_30 ;
V_30 = V_80 ;
do {
V_78 = F_10 ( V_2 , V_30 ) ;
if ( V_78 ) {
V_77 = 5 ;
V_30 += V_78 ;
V_79 += V_78 ;
if ( V_79 >= 504 ) {
F_8 ( V_2 , V_80 , V_79 ) ;
V_30 = V_80 ;
V_79 = 0 ;
}
}
} while ( -- V_77 );
if ( V_79 )
F_8 ( V_2 , V_80 , V_79 ) ;
}
static int F_39 ( void * V_81 )
{
struct V_1 * V_2 = V_81 ;
T_4 * V_82 = & V_2 -> V_82 ;
int V_13 = 0 ;
struct V_38 * V_39 = & V_2 -> V_40 ;
F_19 ( V_27 L_6 ) ;
do {
F_40 ( * V_82 , V_2 -> V_49 || F_41 () ) ;
F_42 ( & V_2 -> V_83 ) ;
if ( F_43 ( V_84 , & V_2 -> V_49 ) )
F_38 ( V_2 ) ;
if ( F_43 ( V_48 , & V_2 -> V_49 ) )
F_27 ( V_2 , V_39 ) ;
if ( F_43 ( V_71 , & V_2 -> V_49 ) )
F_31 ( V_2 ) ;
F_44 ( & V_2 -> V_83 ) ;
} while ( ! F_41 () );
return V_13 ;
}
static T_5 F_45 ( int V_85 , void * V_86 )
{
struct V_1 * V_2 = V_86 ;
if ( ! F_16 ( V_84 , & V_2 -> V_49 ) )
F_17 ( V_2 -> V_50 ) ;
return V_87 ;
}
static int F_46 ( void * V_81 )
{
struct V_1 * V_2 = V_81 ;
F_19 ( V_27 L_7 ) ;
do {
if ( F_47 ( & V_2 -> V_83 ) ) {
F_38 ( V_2 ) ;
F_44 ( & V_2 -> V_83 ) ;
}
F_48 ( V_88 ) ;
F_49 ( V_89 / 20 ) ;
} while ( ! F_41 () );
return 0 ;
}
static int F_50 ( struct V_36 * V_37 )
{
struct V_1 * V_2 =
F_12 ( V_37 , struct V_1 , V_37 ) ;
T_1 V_90 = 0 ;
int V_13 = 0 ;
if ( V_37 -> line != 0 ) {
F_20 ( V_27 L_8 ) ;
return - 1 ;
}
V_90 = V_91 | V_92
| V_93
| V_94
| V_95 ;
V_37 -> V_69 -> V_37 . V_74 -> V_96 = 1 ;
if ( V_2 -> V_85 ) {
V_2 -> V_97 = NULL ;
V_13 = F_51 ( V_2 -> V_85 , F_45 ,
V_98 , L_9 , V_2 ) ;
if ( V_13 ) {
V_2 -> V_85 = 0 ;
F_20 ( V_27 L_10 ) ;
} else {
V_90 |= V_99 ;
}
}
if ( V_2 -> V_85 == 0 ) {
V_2 -> V_97 =
F_52 ( F_46 , V_2 , L_11 ) ;
if ( F_53 ( V_2 -> V_97 ) ) {
V_13 = F_54 ( V_2 -> V_97 ) ;
V_2 -> V_97 = NULL ;
F_20 ( V_27 L_12 ) ;
return V_13 ;
}
}
V_13 = F_5 ( V_2 , V_90 ) ;
if ( V_13 ) {
if ( V_2 -> V_85 )
F_55 ( V_2 -> V_85 , V_2 ) ;
if ( V_2 -> V_97 )
F_56 ( V_2 -> V_97 ) ;
V_2 -> V_97 = NULL ;
return V_13 ;
}
V_2 -> V_100 = V_90 ;
return 0 ;
}
static void F_57 ( struct V_36 * V_37 )
{
struct V_1 * V_2 =
F_12 ( V_37 , struct V_1 , V_37 ) ;
T_1 V_90 ;
if ( V_2 -> V_97 ) {
F_56 ( V_2 -> V_97 ) ;
V_2 -> V_97 = NULL ;
}
if ( V_2 -> V_85 )
F_55 ( V_2 -> V_85 , V_2 ) ;
V_90 = V_91 | V_101 ;
F_5 ( V_2 , V_90 ) ;
}
static void F_58 ( struct V_36 * V_37 )
{
}
static int F_59 ( struct V_36 * V_37 )
{
return 0 ;
}
static void F_60 ( struct V_36 * V_37 , int V_102 )
{
V_37 -> type = V_103 ;
}
static int
F_61 ( struct V_36 * V_37 , struct V_104 * V_105 )
{
return - V_106 ;
}
static const char * F_62 ( struct V_36 * V_37 )
{
struct V_1 * V_2 =
F_12 ( V_37 , struct V_1 , V_37 ) ;
return V_2 -> V_107 ;
}
static void
F_63 ( struct V_36 * V_37 , struct V_108 * V_109 ,
struct V_108 * V_110 )
{
struct V_1 * V_2 =
F_12 ( V_37 , struct V_1 , V_37 ) ;
unsigned char V_111 ;
unsigned int V_18 , V_53 = 0 ;
int V_112 = - 1 ;
T_1 V_113 = V_2 -> V_100 ;
switch ( V_109 -> V_114 & V_115 ) {
case V_116 :
V_111 = V_117 ;
V_113 |= V_118 ;
break;
default:
V_109 -> V_114 &= ~ V_115 ;
V_109 -> V_114 |= V_119 ;
case V_119 :
V_111 = V_120 ;
V_113 |= V_94 ;
break;
}
V_18 = F_64 ( V_37 , V_109 , V_110 , 0 , 230400 ) ;
switch ( V_18 ) {
case 300 :
V_112 = V_121 ;
break;
case 600 :
V_112 = V_122 ;
break;
case 1200 :
V_112 = V_123 ;
break;
case 2400 :
V_112 = V_124 ;
break;
case 4800 :
V_112 = V_125 ;
break;
case 9600 :
V_112 = V_126 ;
break;
case 19200 :
V_112 = V_127 ;
break;
case 38400 :
V_112 = V_128 ;
break;
case 57600 :
V_112 = V_95 ;
break;
case 115200 :
V_112 = V_129 ;
break;
case 230400 :
if ( V_2 -> clock & V_130 )
break;
default:
V_18 = V_2 -> V_18 ;
V_112 = V_2 -> V_100 & V_131 ;
F_65 ( V_109 , V_18 , V_18 ) ;
}
if ( V_2 -> clock & V_130 ) {
V_112 += 1 ;
if ( V_18 == 300 ) {
V_18 = 600 ;
V_112 = V_121 ;
}
if ( V_18 == 230400 )
V_112 = V_129 ;
F_65 ( V_109 , V_18 , V_18 ) ;
}
V_113 = ( V_113 & ~ V_131 ) | V_112 ;
if ( F_66 ( V_109 -> V_114 & V_132 ) )
V_109 -> V_114 &= ~ V_132 ;
if ( V_109 -> V_114 & V_133 )
V_113 |= V_134 ;
else
V_113 &= ~ V_134 ;
if ( V_109 -> V_114 & V_135 ) {
V_113 |= V_136 ;
V_53 |= V_137 ;
} else
V_113 &= ~ V_136 ;
if ( ! ( V_109 -> V_114 & V_138 ) )
V_53 |= V_139 ;
V_2 -> V_53 = V_53 ;
F_67 ( V_37 , V_109 -> V_114 , V_18 ) ;
V_113 |= V_91 ;
if ( V_113 != V_2 -> V_100 ) {
if ( ! F_5 ( V_2 , V_113 ) ) {
V_2 -> V_100 = V_113 ;
V_2 -> V_18 = V_18 ;
}
}
}
static unsigned int F_68 ( struct V_36 * V_37 )
{
return V_140 | V_141 | V_140 ;
}
static void F_69 ( struct V_36 * V_37 , unsigned int V_142 )
{
}
static void F_70 ( struct V_36 * V_37 , int V_143 )
{
}
static void F_71 ( struct V_36 * V_37 , unsigned int V_69 ,
unsigned int V_144 )
{
}
static void F_72 ( struct V_36 * V_37 )
{
}
static int F_73 ( struct V_7 * V_8 , T_6 V_69 )
{
struct V_1 * V_2 = F_74 ( V_8 ) ;
F_75 ( V_2 -> V_85 ) ;
F_76 ( & V_145 , & V_2 -> V_37 ) ;
F_5 ( V_2 , V_2 -> V_100 | V_101 ) ;
return 0 ;
}
static int F_77 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_74 ( V_8 ) ;
F_5 ( V_2 , V_2 -> V_100 ) ;
F_78 ( & V_145 , & V_2 -> V_37 ) ;
F_79 ( V_2 -> V_85 ) ;
return 0 ;
}
static int T_7 F_80 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
void * V_146 ;
T_1 V_147 ;
int V_13 = 0 ;
V_2 = F_6 ( sizeof( * V_2 ) , V_24 ) ;
if ( ! V_2 )
return - V_26 ;
V_8 -> V_148 = 16 ;
V_2 -> clock = V_130 ;
F_81 ( V_8 ) ;
V_2 -> V_37 . type = V_103 ;
V_2 -> V_37 . V_149 = 2 ;
V_2 -> V_37 . V_150 = & V_151 ;
V_2 -> V_37 . line = 0 ;
V_2 -> V_37 . V_152 = & V_8 -> V_152 ;
V_2 -> V_37 . V_153 = 115200 ;
V_2 -> V_8 = V_8 ;
strcpy ( V_2 -> V_107 , V_8 -> V_154 ) ;
V_2 -> V_85 = ( T_1 ) V_8 -> V_85 ;
F_82 ( & V_2 -> V_83 ) ;
V_2 -> V_155 = 0 ;
V_2 -> V_53 = 0 ;
V_2 -> V_18 = 0 ;
V_2 -> V_100 = 0 ;
V_2 -> V_49 = 0 ;
V_147 = V_156 ;
V_13 = F_1 ( V_2 , ( T_2 * ) & V_147 , ( T_2 * ) & V_147 , 2 , 0 ) ;
if ( V_13 < 0 || V_147 == 0 || V_147 == 0xffff ) {
F_83 ( & V_8 -> V_152 , L_13 ,
V_147 ) ;
V_13 = - V_56 ;
goto V_157;
}
V_146 = ( void * ) F_84 ( V_24 ) ;
if ( ! V_146 ) {
V_13 = - V_26 ;
goto V_157;
}
V_2 -> V_40 . V_20 = V_146 ;
V_2 -> V_40 . V_41 = 0 ;
V_2 -> V_40 . V_64 = 0 ;
F_85 ( & V_2 -> V_82 ) ;
V_2 -> V_50 = F_52 ( F_39 ,
V_2 , L_14 ) ;
if ( F_53 ( V_2 -> V_50 ) ) {
V_13 = F_54 ( V_2 -> V_50 ) ;
goto V_158;
}
F_86 ( V_8 , V_2 ) ;
V_47 = V_2 ;
V_2 -> V_37 . V_159 = ( void * ) 0xff110000 ;
F_87 ( & V_145 , & V_2 -> V_37 ) ;
return 0 ;
V_158:
F_88 ( ( unsigned long ) V_146 ) ;
V_157:
F_9 ( V_2 ) ;
return V_13 ;
}
static int T_8 F_89 ( struct V_7 * V_152 )
{
struct V_1 * V_2 = F_74 ( V_152 ) ;
if ( ! V_2 )
return 0 ;
F_90 ( & V_145 , & V_2 -> V_37 ) ;
F_88 ( ( unsigned long ) V_2 -> V_40 . V_20 ) ;
if ( V_2 -> V_50 )
F_56 ( V_2 -> V_50 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static int T_3 F_91 ( void )
{
int V_13 = 0 ;
V_13 = F_92 ( & V_145 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_93 ( & V_160 ) ;
if ( V_13 )
F_94 ( & V_145 ) ;
return V_13 ;
}
static void T_9 F_95 ( void )
{
F_96 ( & V_160 ) ;
F_94 ( & V_145 ) ;
}
