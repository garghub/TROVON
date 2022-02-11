static T_1 F_1 ( const unsigned char * V_1 , unsigned int V_2 )
{
T_1 V_3 = 0 ;
unsigned int V_4 = 1 ;
unsigned char V_5 ;
while ( V_2 ) {
int V_6 ;
V_5 = V_1 [ V_2 - 1 ] ;
V_6 = F_2 ( V_5 ) ;
if ( V_6 >= 0 )
V_3 += V_4 * V_6 ;
V_4 *= 16 ;
-- V_2 ;
}
return V_3 ;
}
static int F_3 ( struct V_7 * V_8 , const unsigned char * V_1 , T_1 V_9 )
{
T_1 V_10 ;
T_1 V_11 ;
T_1 V_12 ;
const unsigned char * V_13 ;
V_12 = F_1 ( & V_1 [ 1 ] , 2 ) ;
V_10 = V_9 + F_1 ( & V_1 [ 3 ] , 4 ) ;
if ( F_4 ( V_8 , 0 , V_10 ) != 0 )
return - V_14 ;
V_13 = V_1 + 9 ;
while ( V_12 ) {
V_11 = F_1 ( V_13 , 8 ) ;
if ( F_5 ( V_8 , 2 ,
( ( V_11 & 0x0f0f0f0f ) << 4 ) | ( ( V_11 & 0xf0f0f0f0 )
>> 4 ) ) )
return - V_14 ;
V_12 -= 4 ;
V_13 += 8 ;
}
return 0 ;
}
static int F_6 ( struct V_7 * V_8 , const unsigned char * V_15 ,
unsigned int V_16 )
{
const unsigned char * V_1 ;
T_1 V_17 , V_18 , V_19 , V_20 ;
int V_21 = 0 ;
V_17 = V_18 = 0 ;
while ( V_16 > 0 && V_21 == 0 ) {
V_1 = V_15 ;
if ( V_1 [ 0 ] == ':' ) {
V_19 = F_1 ( & V_1 [ 7 ] , 2 ) ;
switch ( V_19 ) {
case V_22 :
V_21 = F_3 ( V_8 , V_1 , V_17 + V_18 ) ;
break;
case V_23 :
V_18 = F_1 ( & V_1 [ 9 ] , 4 ) << 4 ;
break;
case V_24 :
V_17 = F_1 ( & V_1 [ 9 ] , 4 ) << 16 ;
break;
case V_25 :
V_20 = F_1 ( & V_1 [ 9 ] , 8 ) ;
if ( F_7 ( V_8 , V_20 ) != 0 )
V_21 = - V_14 ;
break;
case V_26 :
V_16 = 0 ;
break;
default:
break;
}
while ( V_16 > 0 ) {
V_16 -- ;
if ( * V_15 ++ == '\n' )
break;
}
}
}
F_8 ( L_1 , V_21 ) ;
return V_21 ;
}
static void
F_9 ( struct V_7 * V_8 , unsigned char V_27 ,
unsigned char * V_28 , unsigned char * V_29 , unsigned char * V_30 )
{
while ( * V_28 != 0xff ) {
unsigned char V_31 , type ;
V_31 = * V_28 & ( ~ V_32 ) ;
if ( V_31 != V_33 ) {
F_8 ( L_2 , V_27 , V_31 ) ;
F_10 ( V_8 , V_27 , V_31 ) ;
V_27 = V_34 [ V_31 ] [ 0 ] ;
type = V_34 [ V_31 ] [ 1 ] ;
if ( type == V_35 ) {
if ( V_29 )
* V_29 = V_31 - V_36 ;
}
if ( type == V_37 ||
type == V_38 ||
type == V_39 ||
type == V_40 ) {
if ( V_30 ) {
if ( V_30 [ 0 ] != 0xff )
V_30 [ 1 ] = V_31 ;
else
V_30 [ 0 ] = V_31 ;
}
}
}
if ( * V_28 ++ & V_32 ) {
unsigned char * V_41 = V_28 ;
while ( * V_41 != 0xff )
V_41 ++ ;
F_9 ( V_8 , V_27 + 1 , ++ V_41 , V_29 , V_30 ) ;
}
}
}
static void
F_11 ( struct V_7 * V_8 , unsigned char V_27 , unsigned char * V_28 )
{
while ( * V_28 != 0xff ) {
unsigned char V_31 ;
V_31 = * V_28 & ( ~ V_32 ) ;
if ( V_31 != V_33 ) {
F_8 ( L_3 , V_27 , V_31 ) ;
F_12 ( V_8 , V_27 , V_31 ) ;
V_27 = V_34 [ V_31 ] [ 0 ] ;
}
if ( * V_28 ++ & V_32 ) {
unsigned char * V_41 = V_28 ;
while ( * V_41 != 0xff )
V_41 ++ ;
F_11 ( V_8 , V_27 + 1 , ++ V_41 ) ;
}
}
}
static int F_13 ( struct V_7 * V_8 , T_1 V_10 , T_1 V_11 , T_1 V_42 )
{
union V_43 V_44 = V_45 ;
unsigned int V_12 = V_46 ;
int V_47 = 1 ;
F_14 ( V_8 , 0x02 , V_10 , & V_44 ) ;
V_44 . V_48 [ 0 ] &= ( ~ V_42 ) ;
while ( -- V_12 ) {
F_4 ( V_8 , 0x01 , V_10 ) ;
F_5 ( V_8 , 0x02 , ( V_44 . V_48 [ 0 ] | V_11 ) ) ;
F_14 ( V_8 , 0x02 , V_10 , & V_44 ) ;
if ( ( V_44 . V_48 [ 0 ] & V_11 ) == V_11 ) {
V_47 = 0 ;
break;
} else
V_44 . V_48 [ 0 ] &= ~ V_42 ;
}
F_8 ( L_4 , V_10 , V_11 , V_42 ,
V_47 ) ;
return V_47 ;
}
static int F_15 ( struct V_7 * V_8 , T_1 V_49 , T_1 V_50 , T_1 V_51 ,
union V_43 * V_52 )
{
int V_12 , V_53 ;
int V_21 ;
unsigned int time = 0 ;
unsigned long V_54 ;
struct V_55 * V_56 ;
struct V_57 * V_57 = NULL ;
if ( F_16 ( ! V_8 ) )
return - V_58 ;
V_56 = V_8 -> V_56 ;
if ( V_8 -> V_59 > V_60 ) {
if ( V_8 -> V_61 ) {
F_17 ( V_62
L_5 ) ;
if ( F_18 ( V_8 , NULL ) == 0 ) {
V_8 -> V_59 = 0 ;
return - V_63 ;
}
}
F_17 ( V_62 L_6 ) ;
return - V_58 ;
}
if ( V_52 ) {
V_52 -> V_48 [ 0 ] = 0 ;
V_52 -> V_48 [ 1 ] = 0 ;
}
V_12 = 0 ;
F_19 ( & V_8 -> V_64 , V_54 ) ;
while ( V_12 ++ < V_65 && ! F_20 ( V_8 -> V_56 ) )
F_21 ( 10 ) ;
if ( V_12 > V_65 ) {
V_21 = - V_66 ;
goto V_67;
}
V_21 = 0 ;
for ( V_53 = 0 , time = 0 ; time < V_65 ; V_53 ++ , time += 2 ) {
V_57 = & ( V_56 -> V_68 [ V_53 % 2 ] ) ;
if ( F_22 ( V_57 ) ) {
F_23 ( V_57 -> V_69 ) ;
F_23 ( V_57 -> V_70 ) ;
}
if ( F_24 ( V_57 ) ) {
if ( V_49 & V_71 )
F_25 ( V_57 -> V_70 , V_51 ) ;
F_25 ( V_57 -> V_69 , V_50 ) ;
if ( ( V_49 & V_72 ) && V_52 ) {
while ( ! F_22 ( V_57 ) &&
time < V_65 ) {
F_21 ( 10 ) ;
time ++ ;
}
if ( time < V_65 ) {
V_52 -> V_48 [ 0 ] =
F_23 ( V_57 -> V_69 ) ;
V_52 -> V_48 [ 1 ] =
F_23 ( V_57 -> V_70 ) ;
} else {
V_21 = - V_73 ;
goto V_67;
}
}
break;
}
F_21 ( 20 ) ;
}
if ( time == V_65 ) {
V_21 = - V_74 ;
goto V_67;
}
F_26 ( & V_8 -> V_64 , V_54 ) ;
V_8 -> V_75 ++ ;
V_8 -> V_76 += time ;
if ( time > V_8 -> V_77 )
V_8 -> V_77 = time ;
if ( time < V_8 -> V_78 )
V_8 -> V_78 = time ;
if ( ( V_8 -> V_75 ) % 1000 == 0 )
F_8
( L_7 ,
V_8 -> V_75 , V_8 -> V_76 , V_8 -> V_78 ,
V_8 -> V_77 , V_8 -> V_59 ) ;
return 0 ;
V_67:
V_8 -> V_59 ++ ;
F_26 ( & V_8 -> V_64 , V_54 ) ;
F_8
( L_8 ,
V_8 -> V_75 , ( int ) ( ( void * ) & ( V_57 -> V_79 ) - ( void * ) V_56 ) ,
V_49 , V_50 , V_51 , V_52 ? V_52 -> V_48 [ 0 ] : 0 ,
V_52 ? V_52 -> V_48 [ 1 ] : 0 , F_24 ( V_57 ) , F_22 ( V_57 ) ,
V_21 ) ;
return V_21 ;
}
static int
F_27 ( struct V_7 * V_8 , short V_80 , unsigned short V_81 , unsigned short V_82 )
{
union V_43 V_44 = V_45 ;
int V_12 = 0 ;
F_8 ( L_9 , V_80 , V_81 , V_82 ) ;
do {
F_28 ( V_8 , V_80 , V_80 , V_81 , V_82 ) ;
F_29 ( V_8 , V_80 , V_80 , & V_44 ) ;
if ( V_44 . V_83 [ 0 ] == V_82 && V_44 . V_83 [ 1 ] == V_81 )
return 0 ;
} while ( V_12 ++ < V_46 );
F_8 ( L_10 ) ;
return - V_63 ;
}
static int F_30 ( struct V_7 * V_8 , unsigned char * V_84 )
{
unsigned char V_85 [ V_33 ] ;
unsigned char V_31 [ V_33 ] ;
int V_12 , V_53 = 0 ;
for ( V_12 = 0 ; V_12 < V_33 ; V_12 ++ ) {
F_31 ( V_8 , V_12 , V_12 , & V_85 [ V_12 ] , & V_31 [ V_12 ] ) ;
if ( V_31 [ V_12 ] < V_33 ) {
V_84 [ V_53 ++ ] = V_31 [ V_12 ] ;
V_84 [ V_53 ++ ] = V_12 ;
}
}
return V_53 ;
}
static int
F_31 ( struct V_7 * V_8 , unsigned char V_27 , unsigned char V_31 ,
unsigned char * V_86 , unsigned char * V_87 )
{
union V_43 V_44 = V_45 ;
if ( F_32 ( V_8 , V_27 , V_31 , & V_44 ) &&
F_32 ( V_8 , V_27 , V_31 , & V_44 ) )
return - V_63 ;
* V_86 = V_44 . V_88 [ 0 ] ;
* V_87 = V_44 . V_88 [ 1 ] ;
F_8 ( L_11 , * V_86 , * V_87 ) ;
return 0 ;
}
static int
F_33 ( struct V_7 * V_8 , unsigned char * V_89 , unsigned int * V_90 )
{
unsigned char * V_30 ;
unsigned int V_13 [ 2 ] = { 0 , 0 } ;
int V_12 ;
union V_43 V_44 = V_45 ;
V_30 = V_89 ;
for ( V_12 = 0 ; V_12 < 2 ; V_12 ++ ) {
if ( * V_30 != 0xff ) {
if ( F_34 ( V_8 , * V_30 , & V_44 ) &&
F_34 ( V_8 , * V_30 , & V_44 ) )
return - V_63 ;
V_13 [ V_12 ] += V_44 . V_83 [ 1 ] ;
V_13 [ V_12 ] *= V_44 . V_83 [ 2 ] ;
V_13 [ V_12 ] += V_44 . V_83 [ 3 ] ;
V_13 [ V_12 ] /= 65536 ;
}
V_30 ++ ;
}
if ( V_13 [ 0 ] ) {
if ( V_13 [ 1 ] != V_13 [ 0 ] )
F_8 ( L_12 , V_13 [ 0 ] , V_13 [ 1 ] ) ;
* V_90 = ( unsigned int ) V_13 [ 0 ] ;
} else
* V_90 = ( unsigned int ) V_13 [ 1 ] ;
F_8 ( L_13 , V_89 [ 0 ] , V_89 [ 1 ] , * V_90 ) ;
return 0 ;
}
static int
F_35 ( struct V_7 * V_8 ,
unsigned char V_29 , unsigned char V_91 ,
unsigned char V_92 , unsigned char V_93 )
{
unsigned char V_94 , V_95 , V_96 , V_97 ;
F_8
( L_14 ,
V_29 , V_91 , V_92 , V_93 ) ;
V_95 = V_92 == 1 ;
V_94 = F_36 ( V_93 ) == 8 ;
V_96 = F_37 ( V_93 ) != 0 ;
V_97 = F_38 ( V_93 ) != 0 ;
if ( F_39 ( V_8 , V_29 , V_94 , V_95 , V_97 , V_96 , V_91 ) &&
F_39 ( V_8 , V_29 , V_94 , V_95 , V_97 , V_96 , V_91 ) ) {
F_8 ( L_15 ) ;
return - V_63 ;
}
return 0 ;
}
static int
F_40 ( struct V_7 * V_8 , unsigned char * V_89 , unsigned int V_90 )
{
T_1 V_98 , V_99 , V_100 ;
union V_43 V_44 = V_45 ;
int V_12 ;
F_8 ( L_16 , V_89 [ 0 ] ,
V_89 [ 1 ] , V_90 ) ;
V_98 = 48000 ;
V_99 = ( ( V_90 == 48000 ) ? 47999 : V_90 ) * 65536 ;
V_100 = V_99 % V_98 ;
V_99 /= V_98 ;
for ( V_12 = 0 ; V_12 < 2 ; V_12 ++ ) {
if ( * V_89 != 0xff ) {
do {
F_41 ( V_8 , * V_89 , V_98 , V_99 , V_100 ) ;
F_34 ( V_8 , * V_89 , & V_44 ) ;
} while ( V_44 . V_83 [ 1 ] != V_98 &&
V_44 . V_83 [ 2 ] != V_99 &&
V_44 . V_83 [ 3 ] != V_100 &&
V_12 ++ < V_46 );
if ( V_12 > V_46 ) {
F_8 ( L_17 ,
* V_89 , V_90 ) ;
return - V_63 ;
}
}
V_89 ++ ;
}
return 0 ;
}
static int
F_42 ( struct V_7 * V_8 , short V_80 , unsigned short * V_81 ,
unsigned short * V_82 )
{
union V_43 V_44 = V_45 ;
if ( F_29 ( V_8 , V_80 , V_80 , & V_44 ) && F_29 ( V_8 , V_80 , V_80 , & V_44 ) )
return - V_63 ;
* V_81 = V_44 . V_83 [ 0 ] ;
* V_82 = V_44 . V_83 [ 1 ] ;
F_8 ( L_18 , V_80 , * V_81 , * V_82 ) ;
return 0 ;
}
static void F_43 ( unsigned long V_101 )
{
struct V_102 * V_103 = ( void * ) V_101 ;
struct V_7 * V_8 = V_103 -> V_8 ;
struct V_104 * V_105 [ V_106 + 1 ] ;
struct V_107 * V_108 ;
struct V_109 * V_11 = NULL ;
unsigned int V_110 , V_111 ;
struct V_112 * V_5 ;
int V_12 , V_53 ;
unsigned int V_47 ;
if ( ! V_8 )
return;
for ( V_12 = 0 ; V_12 < V_106 ; V_12 ++ )
V_105 [ V_12 ] = V_103 -> V_113 [ V_12 ] ;
V_105 [ V_12 ] = V_103 -> V_114 ;
for ( V_12 = 0 ; V_12 < V_106 + 1 ; V_12 ++ ) {
if ( V_105 [ V_12 ] &&
( V_108 = V_105 [ V_12 ] -> V_108 ) &&
( V_11 = V_108 -> V_115 ) && V_11 -> V_116 != V_117 ) {
V_110 = 0 ;
for ( V_53 = 0 ; V_53 < V_11 -> V_118 ; V_53 ++ ) {
V_5 = & V_11 -> V_119 [ V_53 ] ;
V_47 = F_44 ( V_5 -> V_120 ) ;
if ( V_47 & V_121 )
V_110 += F_44 ( V_5 -> V_122 ) ;
if ( V_47 & V_123 )
V_110 += F_44 ( V_5 -> V_122 ) ;
if ( ( V_47 & V_124 )
&& ( V_11 -> V_116 == V_125 ) ) {
V_11 -> V_116 = V_117 ;
F_17 ( V_62
L_19 ) ;
}
V_5 -> V_120 =
F_45 ( V_47 &
~ ( V_124 | V_121 |
V_123 ) ) ;
}
V_11 -> V_126 += V_110 ;
V_110 += V_11 -> V_127 ;
if ( V_11 -> V_116 != V_117 ) {
V_111 =
F_46 ( V_108 ,
V_108 -> V_128 ) ;
F_8
( L_20 ,
F_47 ( V_8 -> V_56 ) ,
F_48 ( V_108 , V_110 ) ,
V_108 -> V_128 ) ;
V_53 = 0 ;
if ( V_110 >= V_111 ) {
V_53 ++ ;
while ( V_110 >= V_111 )
V_110 -= V_111 ;
}
V_11 -> V_127 = V_110 ;
if ( V_53 > 0 )
F_49 ( V_105 [ V_12 ] ) ;
}
}
}
}
static int F_50 ( struct V_129 * V_130 )
{
struct V_131 * V_132 = F_51 ( V_130 ) ;
struct V_133 * V_134 = F_52 ( V_130 ) ;
struct V_102 * V_103 = V_134 -> V_115 ;
V_103 -> V_135 = 1 ;
F_53 ( V_134 , V_136 ) ;
F_54 ( V_103 -> V_137 ) ;
F_55 ( V_103 -> V_138 ) ;
F_56 ( V_132 ) ;
F_57 ( V_132 ) ;
F_58 ( V_132 , V_139 ) ;
return 0 ;
}
static int F_59 ( struct V_129 * V_130 )
{
struct V_131 * V_132 = F_51 ( V_130 ) ;
struct V_133 * V_134 = F_52 ( V_130 ) ;
struct V_102 * V_103 = V_134 -> V_115 ;
F_58 ( V_132 , V_140 ) ;
F_60 ( V_132 ) ;
if ( F_61 ( V_132 ) < 0 ) {
F_62 ( V_62 L_21
L_22 ) ;
F_63 ( V_134 ) ;
return - V_63 ;
}
F_64 ( V_132 ) ;
F_65 ( V_103 ) ;
F_66 ( V_103 -> V_138 ) ;
F_53 ( V_134 , V_141 ) ;
V_103 -> V_135 = 0 ;
return 0 ;
}
static int F_67 ( struct V_7 * V_8 , struct V_102 * V_103 )
{
union V_142 V_143 = { . V_52 = V_45 } ;
int V_12 , V_144 , V_21 ;
for ( V_12 = 0 ; V_12 < 2 ; V_12 ++ ) {
F_25 ( V_8 -> V_56 -> V_68 [ V_12 ] . V_69 , 0 ) ;
F_25 ( V_8 -> V_56 -> V_68 [ V_12 ] . V_70 , 0 ) ;
}
F_68 ( V_8 -> V_56 ) ;
F_21 ( 100 ) ;
F_69 ( V_8 -> V_56 ) ;
F_21 ( 100 ) ;
for ( V_144 = 100000 ; -- V_144 ; F_21 ( 10 ) ) {
if ( F_20 ( V_8 -> V_56 ) && ! F_70 ( V_8 -> V_56 ) )
break;
}
if ( ! V_144 ) {
F_17 ( V_62
L_23
L_24 ,
F_47 ( V_8 -> V_56 ) ,
F_20 ( V_8 -> V_56 ) , F_70 ( V_8 -> V_56 ) ) ;
return - V_63 ;
} else {
F_8
( L_25 ,
F_47 ( V_8 -> V_56 ) ,
F_20 ( V_8 -> V_56 ) , F_70 ( V_8 -> V_56 ) ) ;
}
F_71 ( V_8 , & V_143 . V_52 ) ;
F_8 ( L_26 ,
V_143 . V_143 . V_145 , V_143 . V_143 . V_146 ,
V_143 . V_143 . V_147 , V_143 . V_143 . V_148 ) ;
if ( ! V_103 )
return 1 ;
for ( V_12 = 0 ; V_12 < V_149 ; V_12 ++ ) {
if ( ! memcmp ( & V_150 [ V_12 ] , & V_143 , sizeof( V_143 ) ) )
return 1 ;
}
F_8 ( L_27 ) ;
if ( ! V_103 -> V_151 ) {
V_21 = F_72 ( & V_103 -> V_151 , L_28 ,
& V_103 -> V_132 -> V_130 ) ;
if ( V_21 ) {
F_17 ( V_62
L_29 , V_21 ) ;
return - V_63 ;
}
}
V_21 = F_6 ( V_8 , V_103 -> V_151 -> V_11 , V_103 -> V_151 -> V_16 ) ;
if ( V_21 ) {
F_17 ( V_62
L_30 , V_21 ) ;
return V_21 ;
}
V_103 -> V_143 = V_143 ;
return 1 ;
}
static int F_18 ( struct V_7 * V_8 , struct V_102 * V_103 )
{
union V_43 V_44 = V_45 ;
int V_21 , V_152 ;
if ( ! V_8 )
return - V_58 ;
V_8 -> V_75 = 0 ;
V_8 -> V_76 = 0 ;
V_8 -> V_77 = 0 ;
V_8 -> V_78 = 0xffffffff ;
V_8 -> V_59 = 0 ;
V_8 -> V_61 = 0 ;
V_152 = V_153 ;
do {
V_21 = F_67 ( V_8 , V_103 ) ;
if ( V_21 < 0 )
return V_21 ;
} while ( ! V_21 && -- V_152 );
F_73 ( V_8 , 0 , V_154 ) ;
F_74 ( V_8 , V_154 , & V_44 ) ;
F_8 ( L_31 , V_44 . V_48 [ 0 ] , V_44 . V_48 [ 1 ] ) ;
F_75 ( V_8 , 0 ) ;
F_76 ( V_8 , 0 ) ;
F_77 ( V_8 , 0 ) ;
F_78 ( V_8 , 0 ) ;
F_79 ( V_8 ) ;
F_13 ( V_8 , 0x301F8 , 1 , 1 ) ;
F_13 ( V_8 , 0x301F4 , 1 , 1 ) ;
F_80 ( V_8 , V_155 , 0 , 0 , V_156 , V_157 ,
V_158 , V_159 ) ;
F_27 ( V_8 , V_159 , 0x7fff , 0x7fff ) ;
F_9 ( V_8 , V_160 , V_161 , NULL , NULL ) ;
F_80 ( V_8 , V_162 , 0 , 0 , V_163 , V_164 , V_165 ,
V_166 ) ;
F_27 ( V_8 , V_166 , 0x7fff , 0x7fff ) ;
F_13 ( V_8 , 0x30648 + V_166 * 4 , 0x01 , 0x00000005 ) ;
F_13 ( V_8 , 0x301A8 , 0x02 , 0x00000002 ) ;
F_13 ( V_8 , 0x30264 , 0x08 , 0xffffffff ) ;
F_9 ( V_8 , V_167 , V_168 , NULL , NULL ) ;
F_41 ( V_8 , V_169 , 48000 ,
( ( T_1 ) V_170 * 65536 ) / 48000 ,
( ( T_1 ) V_170 * 65536 ) % 48000 ) ;
F_80 ( V_8 , V_171 , 0 , 0 , V_169 , V_172 , V_173 ,
V_174 ) ;
F_81 ( V_8 , 1 ) ;
F_9 ( V_8 , V_175 , V_176 , NULL , NULL ) ;
F_9 ( V_8 , V_177 , V_178 , NULL , NULL ) ;
F_9 ( V_8 , V_177 , V_179 , NULL , NULL ) ;
F_82 ( V_8 -> V_56 ) ;
F_83 ( V_8 -> V_56 ) ;
F_82 ( V_8 -> V_56 ) ;
V_8 -> V_61 = 1 ;
return 0 ;
}
static T_2 F_84 ( struct V_104
* V_105 )
{
struct V_102 * V_103 = F_85 ( V_105 ) ;
struct V_107 * V_108 = V_105 -> V_108 ;
struct V_109 * V_11 = F_86 ( V_105 ) ;
struct V_7 * V_8 = V_103 -> V_8 ;
union V_43 V_44 = V_45 ;
T_2 V_52 ;
F_87 ( V_8 , 0 , V_11 -> V_91 , & V_44 ) ;
if ( V_11 -> V_16 && V_108 -> V_128 ) {
F_8
( L_32 ,
V_11 -> V_91 , V_44 . V_48 [ 1 ] , V_44 . V_48 [ 1 ] % V_11 -> V_16 ,
F_48 ( V_108 , V_44 . V_48 [ 1 ] ) ,
F_48 ( V_108 ,
V_44 . V_48 [ 1 ] ) % V_108 -> V_128 ) ;
if ( V_44 . V_48 [ 1 ] > V_11 -> V_126 )
V_52 =
F_48 ( V_108 ,
V_44 . V_48 [ 1 ] % V_11 -> V_16 ) ;
else
V_52 =
F_48 ( V_108 ,
V_11 -> V_126 % V_11 -> V_16 ) ;
} else {
F_8 ( L_33 ,
V_11 -> V_16 , V_108 -> V_128 ) ;
V_52 = F_48 ( V_108 , 0 ) ;
}
return V_52 ;
}
static int F_88 ( struct V_104 * V_105 , int V_50 )
{
int V_12 , V_53 ;
struct V_102 * V_103 = F_85 ( V_105 ) ;
struct V_109 * V_11 = F_86 ( V_105 ) ;
struct V_7 * V_8 = V_103 -> V_8 ;
union V_43 V_44 = V_45 ;
F_89 ( & V_103 -> V_64 ) ;
switch ( V_50 ) {
case V_180 :
case V_181 :
if ( ! ( V_11 -> V_116 & V_125 ) ) {
F_90 ( V_8 , V_11 -> V_91 , V_11 -> V_182 . V_10 ) ;
F_83 ( V_8 -> V_56 ) ;
V_11 -> V_116 = V_125 ;
if ( V_11 -> V_29 != 0xff )
F_27 ( V_8 , V_11 -> V_29 , 0x7fff , 0x7fff ) ;
V_103 -> V_183 ++ ;
V_11 -> V_127 = 0 ;
V_11 -> V_126 = 0 ;
}
break;
case V_184 :
case V_185 :
if ( V_11 -> V_29 != 0xff )
F_27 ( V_8 , V_11 -> V_29 , 0 , 0 ) ;
F_27 ( V_8 , V_11 -> V_29 , 0 , 0 ) ;
F_91 ( V_8 , V_11 -> V_91 ) ;
V_11 -> V_116 = V_117 ;
V_103 -> V_183 -- ;
V_53 = 0 ;
do {
V_12 = V_44 . V_48 [ 1 ] ;
F_87 ( V_8 , 0 , V_11 -> V_91 , & V_44 ) ;
F_21 ( 1 ) ;
} while ( V_12 != V_44 . V_48 [ 1 ] && V_53 ++ < V_46 );
if ( V_53 > V_46 )
F_17 ( V_62 L_34 ) ;
break;
case V_186 :
if ( ! ( V_11 -> V_116 & V_187 ) ) {
F_92 ( V_8 , V_11 -> V_91 ) ;
V_11 -> V_116 |= V_187 ;
V_103 -> V_183 -- ;
}
break;
case V_188 :
if ( V_11 -> V_116 & V_187 ) {
F_90 ( V_8 , V_11 -> V_91 , V_11 -> V_182 . V_10 ) ;
V_11 -> V_116 &= ~ V_187 ;
V_103 -> V_183 ++ ;
}
break;
default:
F_93 ( & V_103 -> V_64 ) ;
return - V_58 ;
}
F_93 ( & V_103 -> V_64 ) ;
return 0 ;
}
static int F_94 ( struct V_104 * V_105 )
{
struct V_102 * V_103 = F_85 ( V_105 ) ;
struct V_107 * V_108 = V_105 -> V_108 ;
struct V_109 * V_11 = F_86 ( V_105 ) ;
struct V_7 * V_8 = V_103 -> V_8 ;
unsigned char * V_189 = NULL ;
unsigned int V_90 , V_92 ;
int V_21 = 0 ;
T_3 V_93 ;
if ( F_16 ( ! V_8 || ! V_11 ) )
return - V_58 ;
F_8 ( L_35 , V_11 -> V_91 ,
V_108 -> V_92 , V_108 -> V_93 , V_108 -> V_90 ) ;
F_95 ( & V_103 -> V_64 ) ;
V_92 = V_108 -> V_92 ;
V_93 = V_108 -> V_93 ;
V_90 = V_108 -> V_90 ;
switch ( V_92 ) {
case 1 :
if ( V_90 == 48000 && V_93 == V_190 )
V_189 = V_11 -> V_191 . V_192 ;
else
V_189 = V_11 -> V_191 . V_193 ;
break;
case 2 :
if ( V_90 == 48000 && V_93 == V_190 )
V_189 = V_11 -> V_191 . V_192 ;
else
V_189 = V_11 -> V_191 . V_194 ;
break;
}
F_8 ( L_36 ,
V_11 -> V_182 . V_195 ) ;
if ( V_11 -> V_182 . V_195 ) {
unsigned int V_12 , V_53 , V_16 , V_118 , V_196 , V_197 , V_198 ;
struct V_112 * V_5 , * V_13 = NULL ;
V_16 = F_46 ( V_108 , V_108 -> V_199 ) ;
V_198 = F_46 ( V_108 , V_108 -> V_128 ) ;
V_196 = V_200 ;
while ( ( V_16 + ( V_196 >> 1 ) - 1 ) <= ( V_196 << 7 ) && ( V_196 << 1 ) > V_198 )
V_196 = V_196 >> 1 ;
V_118 = ( V_16 + V_196 - 1 ) / V_196 ;
V_11 -> V_16 = V_16 ;
V_11 -> V_118 = V_118 ;
F_8
( L_37 ,
V_16 , V_118 , V_196 , V_198 ) ;
V_197 = 0 ;
V_53 = 0 ;
for ( V_12 = 0 ; V_12 < V_118 ; V_12 ++ ) {
unsigned int V_201 , V_10 ;
V_5 = & V_11 -> V_119 [ V_12 ] ;
if ( V_13 )
V_13 -> V_202 = F_45 ( V_11 -> V_182 . V_10 +
( V_12 *
sizeof( struct
V_112 ) ) ) ;
V_5 -> V_202 = F_45 ( V_11 -> V_182 . V_10 ) ;
V_201 = V_53 << V_203 ;
V_10 = F_96 ( V_105 , V_201 ) + V_197 ;
V_5 -> V_204 = F_45 ( V_10 ) ;
V_197 = ( V_197 + V_196 ) % V_200 ;
if ( V_197 == 0 )
V_53 ++ ;
V_5 -> V_122 = F_45 ( V_196 ) ;
V_5 -> V_120 =
F_45 ( V_205 | V_206 |
V_207 ) ;
V_13 = V_5 ;
V_16 -= V_196 ;
}
V_11 -> V_119 [ V_12 ] . V_122 = F_45 ( V_16 ) ;
}
if ( V_189 && V_189 != V_11 -> V_189 ) {
if ( V_11 -> V_189 )
F_11 ( V_8 , V_11 -> V_27 , V_11 -> V_189 ) ;
F_9 ( V_8 , V_11 -> V_27 , V_189 ,
& V_11 -> V_29 , V_11 -> V_89 ) ;
V_11 -> V_189 = V_189 ;
V_11 -> V_90 = 0 ;
}
if ( V_11 -> V_90 != V_90 || V_11 -> V_93 != V_93 ||
V_11 -> V_92 != V_92 ) {
V_11 -> V_90 = V_90 ;
V_11 -> V_93 = V_93 ;
V_11 -> V_92 = V_92 ;
if ( F_35
( V_8 , V_11 -> V_29 , V_11 -> V_91 , V_92 , V_93 )
|| F_40 ( V_8 , V_11 -> V_89 , V_90 ) )
V_21 = - V_63 ;
}
F_97 ( & V_103 -> V_64 ) ;
return V_21 ;
}
static int
F_98 ( struct V_104 * V_105 ,
struct V_208 * V_209 )
{
struct V_102 * V_103 = F_85 ( V_105 ) ;
struct V_109 * V_11 = F_86 ( V_105 ) ;
struct V_210 * V_182 = & V_11 -> V_182 ;
int V_21 ;
F_8 ( L_38 , V_11 -> V_91 ,
V_182 -> V_195 , ( unsigned long ) V_182 -> V_10 ,
( int ) V_182 -> V_211 ) ;
if ( V_182 -> V_195 )
F_99 ( V_182 ) ;
if ( ( V_21 = F_100 ( V_212 ,
F_101 ( V_103 -> V_132 ) ,
sizeof( struct V_112 ) * ( V_213 + 1 ) ,
V_182 ) ) < 0 ) {
F_17 ( V_62 L_39 ,
( int ) sizeof( struct V_112 ) * ( V_213 + 1 ) ) ;
return V_21 ;
}
V_11 -> V_119 = (struct V_112 * ) V_182 -> V_195 ;
return F_102 ( V_105 ,
F_103 ( V_209 ) ) ;
}
static int F_104 ( struct V_104 * V_105 )
{
struct V_102 * V_103 = F_85 ( V_105 ) ;
struct V_109 * V_11 = F_86 ( V_105 ) ;
struct V_7 * V_8 = V_103 -> V_8 ;
if ( V_8 && V_11 ) {
if ( V_11 -> V_189 )
F_11 ( V_8 , V_11 -> V_27 , V_11 -> V_189 ) ;
V_11 -> V_189 = NULL ;
V_11 -> V_27 = 0xff ;
V_11 -> V_89 [ 0 ] = 0xff ;
V_11 -> V_89 [ 1 ] = 0xff ;
if ( V_11 -> V_182 . V_195 ) {
F_99 ( & V_11 -> V_182 ) ;
V_11 -> V_182 . V_195 = NULL ;
}
}
return F_105 ( V_105 ) ;
}
static int F_106 ( struct V_104 * V_105 )
{
struct V_102 * V_103 = F_85 ( V_105 ) ;
struct V_107 * V_108 = V_105 -> V_108 ;
struct V_109 * V_11 ;
int V_214 = V_105 -> V_215 ;
V_103 -> V_113 [ V_214 ] = V_105 ;
V_108 -> V_216 = V_217 ;
V_11 = F_107 ( sizeof( struct V_109 ) , V_218 ) ;
if ( V_11 == NULL )
return - V_219 ;
V_11 -> V_191 = V_220 [ V_214 ] ;
V_11 -> V_91 = V_221 [ V_214 ] ;
V_11 -> V_27 = V_222 [ V_214 ] ;
V_11 -> V_89 [ 0 ] = 0xff ;
V_11 -> V_89 [ 1 ] = 0xff ;
V_11 -> V_116 = V_117 ;
V_108 -> V_115 = V_11 ;
return F_108 ( V_108 ,
V_223 ) ;
}
static int F_109 ( struct V_104 * V_105 )
{
struct V_102 * V_103 = F_85 ( V_105 ) ;
struct V_107 * V_108 = V_105 -> V_108 ;
struct V_109 * V_11 ;
V_103 -> V_114 = V_105 ;
V_108 -> V_216 = V_224 ;
V_11 = F_107 ( sizeof( struct V_109 ) , V_218 ) ;
if ( V_11 == NULL )
return - V_219 ;
V_11 -> V_191 = V_225 ;
V_11 -> V_91 = V_226 ;
V_11 -> V_27 = V_227 ;
V_11 -> V_89 [ 0 ] = 0xff ;
V_11 -> V_89 [ 1 ] = 0xff ;
V_11 -> V_116 = V_117 ;
V_108 -> V_115 = V_11 ;
return F_108 ( V_108 ,
V_223 ) ;
}
static int F_110 ( struct V_104 * V_105 )
{
struct V_102 * V_103 = F_85 ( V_105 ) ;
struct V_109 * V_11 = F_86 ( V_105 ) ;
int V_214 = V_105 -> V_215 ;
V_105 -> V_108 -> V_115 = NULL ;
V_103 -> V_113 [ V_214 ] = NULL ;
F_111 ( V_11 ) ;
return 0 ;
}
static int F_112 ( struct V_104 * V_105 )
{
struct V_102 * V_103 = F_85 ( V_105 ) ;
struct V_109 * V_11 = F_86 ( V_105 ) ;
V_105 -> V_108 -> V_115 = NULL ;
V_103 -> V_114 = NULL ;
F_111 ( V_11 ) ;
return 0 ;
}
static int
F_113 ( struct V_102 * V_103 , int V_129 , struct V_228 * * V_229 )
{
struct V_228 * V_137 ;
int V_21 ;
if ( V_229 )
* V_229 = NULL ;
if ( ( V_21 =
F_114 ( V_103 -> V_134 , L_40 , V_129 , V_106 , 1 ,
& V_137 ) ) < 0 )
return V_21 ;
F_115 ( V_137 , V_230 ,
& V_231 ) ;
F_115 ( V_137 , V_232 ,
& V_233 ) ;
V_137 -> V_115 = V_103 ;
V_137 -> V_234 = 0 ;
strcpy ( V_137 -> V_235 , L_40 ) ;
V_103 -> V_137 = V_137 ;
F_116 ( V_137 , V_236 ,
F_101 ( V_103 -> V_132 ) ,
64 * 1024 , 128 * 1024 ) ;
if ( V_229 )
* V_229 = V_137 ;
return 0 ;
}
static T_4
F_117 ( int V_237 , void * V_101 )
{
struct V_102 * V_103 = V_101 ;
struct V_7 * V_8 = V_103 -> V_8 ;
if ( V_8 ) {
V_103 -> V_238 ++ ;
if ( F_118 ( V_8 -> V_56 ) || F_119 ( V_8 -> V_56 ) ||
F_120 ( V_8 -> V_56 ) ) {
V_103 -> V_239 ++ ;
F_121 ( & V_103 -> V_240 ) ;
}
if ( V_103 -> V_241 && F_122 ( V_8 -> V_56 ) ) {
V_103 -> V_239 ++ ;
F_123 ( V_237 ,
V_103 -> V_241 -> V_115 ) ;
}
F_82 ( V_8 -> V_56 ) ;
}
return V_242 ;
}
static void
F_124 ( struct V_243 * V_138 , unsigned short V_244 ,
unsigned short V_20 )
{
struct V_102 * V_103 = V_138 -> V_115 ;
struct V_7 * V_8 = V_103 -> V_8 ;
union V_43 V_44 = V_45 ;
int V_12 = 0 ;
if ( F_16 ( ! V_8 ) )
return;
F_8 ( L_41 , V_244 , V_20 ) ;
do {
F_73 ( V_8 , V_20 , V_244 ) ;
F_74 ( V_8 , V_244 , & V_44 ) ;
} while ( V_44 . V_83 [ 1 ] != V_20 && V_12 ++ < V_46 );
if ( V_12 > V_46 )
F_8 ( L_42 ) ;
}
static unsigned short F_125 ( struct V_243 * V_138 ,
unsigned short V_244 )
{
struct V_102 * V_103 = V_138 -> V_115 ;
struct V_7 * V_8 = V_103 -> V_8 ;
union V_43 V_44 = V_45 ;
if ( F_16 ( ! V_8 ) )
return 0 ;
if ( F_74 ( V_8 , V_244 , & V_44 ) != 0 )
F_74 ( V_8 , V_244 , & V_44 ) ;
F_8 ( L_43 , V_244 , V_44 . V_83 [ 1 ] ) ;
return V_44 . V_83 [ 1 ] ;
}
static int F_65 ( struct V_102 * V_103 )
{
struct V_7 * V_8 ;
unsigned int V_245 ;
int V_21 ;
if ( F_16 ( ! V_103 ) )
return - V_58 ;
V_8 = V_103 -> V_8 ;
if ( ! V_8 ) {
if ( ( V_8 = F_107 ( sizeof( struct V_7 ) , V_218 ) ) == NULL )
return - V_219 ;
V_8 -> V_56 = (struct V_55 * ) V_103 -> V_68 ;
F_126 ( & V_8 -> V_64 ) ;
V_103 -> V_8 = V_8 ;
}
V_8 -> V_61 = 0 ;
if ( ( V_21 = F_18 ( V_8 , V_103 ) ) != 0 )
return V_21 ;
V_245 = V_103 -> V_245 ;
switch ( V_245 ) {
case 0x4310 :
case 0x4320 :
case 0x4330 :
F_8 ( L_44 ) ;
F_127 ( V_8 ) ;
break;
}
F_8 ( L_45 ) ;
if ( V_103 -> V_241 )
F_128 ( V_8 -> V_56 ) ;
return V_21 ;
}
static int F_129 ( struct V_102 * V_103 )
{
struct V_7 * V_8 ;
if ( ! V_103 )
return 0 ;
if ( ( V_8 = V_103 -> V_8 ) ) {
F_68 ( V_8 -> V_56 ) ;
F_21 ( 100 ) ;
F_69 ( V_8 -> V_56 ) ;
F_111 ( V_103 -> V_8 ) ;
}
if ( V_103 -> V_237 >= 0 )
F_130 ( V_103 -> V_237 , V_103 ) ;
F_131 ( V_103 -> V_151 ) ;
F_132 ( V_103 -> V_246 ) ;
F_111 ( V_103 ) ;
return 0 ;
}
static int F_133 ( struct V_247 * V_129 )
{
struct V_102 * V_103 = V_129 -> V_248 ;
return F_129 ( V_103 ) ;
}
static int
F_134 ( struct V_133 * V_134 , struct V_131 * V_132 ,
struct V_102 * * V_249 )
{
struct V_102 * V_103 ;
struct V_55 * V_56 ;
int V_21 ;
static struct V_250 V_251 = {
. V_252 = F_133 ,
} ;
* V_249 = NULL ;
if ( ( V_21 = F_61 ( V_132 ) ) < 0 )
return V_21 ;
if ( ! ( V_103 = F_107 ( sizeof( struct V_102 ) , V_218 ) ) )
return - V_219 ;
F_126 ( & V_103 -> V_64 ) ;
V_103 -> V_134 = V_134 ;
V_103 -> V_132 = V_132 ;
V_103 -> V_237 = - 1 ;
V_103 -> V_183 = 0 ;
V_103 -> V_68 = F_135 ( V_132 , 0 ) ;
V_103 -> V_238 = 0 ;
V_103 -> V_239 = 0 ;
V_103 -> V_8 = NULL ;
F_136 ( & V_103 -> V_240 , F_43 , ( unsigned long ) V_103 ) ;
if ( ( V_103 -> V_246 =
F_137 ( V_103 -> V_68 , 64 , L_40 ) ) == NULL ) {
F_17 ( V_62
L_46 ,
V_103 -> V_68 , V_103 -> V_68 + 64 - 1 ) ;
F_129 ( V_103 ) ;
return - V_66 ;
}
V_56 = (struct V_55 * ) V_103 -> V_68 ;
F_138 ( V_56 ) ;
if ( F_139 ( V_132 -> V_237 , F_117 , V_253 ,
V_254 , V_103 ) ) {
F_17 ( V_62 L_47 ,
V_132 -> V_237 ) ;
F_129 ( V_103 ) ;
return - V_66 ;
}
V_103 -> V_237 = V_132 -> V_237 ;
V_103 -> V_245 = V_132 -> V_129 ;
F_64 ( V_132 ) ;
if ( ( V_21 = F_65 ( V_103 ) ) < 0 ) {
F_129 ( V_103 ) ;
return V_21 ;
}
if ( ( V_21 = F_140 ( V_134 , V_255 , V_103 , & V_251 ) ) < 0 ) {
F_129 ( V_103 ) ;
return V_21 ;
}
F_141 ( V_134 , & V_132 -> V_130 ) ;
* V_249 = V_103 ;
return 0 ;
}
static void
F_142 ( struct V_256 * V_257 ,
struct V_258 * V_259 )
{
struct V_102 * V_103 = V_257 -> V_115 ;
struct V_109 * V_11 ;
int V_12 ;
struct V_7 * V_8 = NULL ;
unsigned char V_13 [ 256 ] ;
unsigned short V_81 = 0 , V_82 = 0 ;
unsigned int V_90 ;
if ( ! V_103 )
return;
F_143 ( V_259 , L_48 , V_103 -> V_134 -> V_260 ) ;
F_143 ( V_259 , L_49 ,
V_103 -> V_245 , V_103 -> V_239 , V_103 -> V_238 ) ;
for ( V_12 = 0 ; V_12 < 64 ; V_12 += 4 )
F_143 ( V_259 , L_50 ,
( V_12 % 16 ) ? ' ' : '\n' , V_12 , F_144 ( V_103 -> V_68 + V_12 ) ) ;
if ( ( V_8 = V_103 -> V_8 ) ) {
F_143 ( V_259 ,
L_51 ,
V_103 -> V_143 . V_143 . V_145 ,
V_103 -> V_143 . V_143 . V_146 ,
V_103 -> V_143 . V_143 . V_147 ,
V_103 -> V_143 . V_143 . V_148 ) ;
F_143 ( V_259 , L_52 ) ;
for ( V_12 = 0 ; V_12 < 12 ; V_12 ++ ) {
F_42 ( V_8 , V_12 , & V_81 , & V_82 ) ;
F_143 ( V_259 , L_53 , V_12 , V_81 , V_82 ) ;
}
F_143 ( V_259 ,
L_54 ,
V_8 -> V_75 , V_8 -> V_59 ,
V_8 -> V_76 , V_8 -> V_77 , V_8 -> V_78 ) ;
}
F_143 ( V_259 , L_55 , V_103 -> V_183 ) ;
for ( V_12 = 0 ; V_12 < V_106 ; V_12 ++ ) {
if ( V_103 -> V_113 [ V_12 ]
&& V_103 -> V_113 [ V_12 ] -> V_108
&& ( V_11 =
V_103 -> V_113 [ V_12 ] -> V_108 -> V_115 ) ) {
F_143 ( V_259 ,
L_56 ,
V_11 -> V_91 , V_11 -> V_29 , V_11 -> V_27 ,
V_11 -> V_89 [ 0 ] , V_11 -> V_89 [ 1 ] ) ;
if ( ! ( F_33 ( V_8 , V_11 -> V_89 , & V_90 ) ) )
F_143 ( V_259 , L_57 , V_90 ) ;
}
}
if ( V_103 -> V_114
&& V_103 -> V_114 -> V_108
&& ( V_11 = V_103 -> V_114 -> V_108 -> V_115 ) ) {
F_143 ( V_259 ,
L_56 ,
V_11 -> V_91 , V_11 -> V_29 ,
V_11 -> V_27 , V_11 -> V_89 [ 0 ] , V_11 -> V_89 [ 1 ] ) ;
if ( ! ( F_33 ( V_8 , V_11 -> V_89 , & V_90 ) ) )
F_143 ( V_259 , L_57 , V_90 ) ;
}
F_143 ( V_259 , L_58 ) ;
V_12 = F_30 ( V_8 , V_13 ) ;
while ( V_12 >= 2 ) {
V_12 -= 2 ;
F_143 ( V_259 , L_59 , V_13 [ V_12 ] , V_13 [ V_12 + 1 ] ) ;
}
F_143 ( V_259 , L_60 ) ;
}
static void F_145 ( struct V_102 * V_103 )
{
struct V_256 * V_257 ;
if ( ! F_146 ( V_103 -> V_134 , L_61 , & V_257 ) )
F_147 ( V_257 , V_103 , F_142 ) ;
}
static int F_148 ( struct V_102 * V_103 )
{
struct V_261 * V_262 ;
struct V_263 V_138 ;
int V_21 = 0 ;
static struct V_264 V_251 = {
. V_265 = F_124 ,
. V_266 = F_125 ,
} ;
memset ( & V_138 , 0 , sizeof( V_138 ) ) ;
V_138 . V_115 = V_103 ;
V_138 . V_267 = V_268 ;
if ( ( V_21 = V_261 ( V_103 -> V_134 , 0 , & V_251 , V_103 , & V_262 ) ) < 0 )
return V_21 ;
V_103 -> V_269 = V_262 ;
V_138 . V_132 = V_103 -> V_132 ;
if ( ( V_21 = F_149 ( V_262 , & V_138 , & V_103 -> V_138 ) ) < 0 )
return V_21 ;
return V_21 ;
}
static int
F_150 ( struct V_131 * V_132 , const struct V_270 * V_91 )
{
static int V_130 ;
struct V_271 * V_271 ;
if ( V_130 >= V_272 )
return - V_273 ;
if ( ! V_274 [ V_130 ] ) {
V_130 ++ ;
return - V_275 ;
}
if ( ! V_276 [ V_130 ++ ] )
return 0 ;
V_271 = F_151 () ;
if ( ! V_271 )
return - V_219 ;
if ( ! F_137 ( V_276 [ V_130 ] , 8 , L_62 ) ) {
F_17 ( V_277
L_63 ,
V_276 [ V_130 ] ) ;
F_152 ( V_271 ) ;
return - V_66 ;
}
V_271 -> V_278 = V_276 [ V_130 ] ;
F_153 ( V_271 ) ;
F_154 ( V_132 , V_271 ) ;
return 0 ;
}
static void F_155 ( struct V_131 * V_132 )
{
struct V_271 * V_271 = F_156 ( V_132 ) ;
if ( V_271 ) {
F_157 ( V_271 -> V_278 , 8 ) ;
F_158 ( V_271 ) ;
}
}
static int
F_159 ( struct V_131 * V_132 , const struct V_270 * V_279 )
{
static int V_130 ;
struct V_133 * V_134 ;
struct V_102 * V_103 ;
unsigned short V_20 ;
int V_21 ;
if ( V_130 >= V_272 )
return - V_273 ;
if ( ! V_274 [ V_130 ] ) {
V_130 ++ ;
return - V_275 ;
}
V_21 = F_160 ( V_280 [ V_130 ] , V_91 [ V_130 ] , V_281 , 0 , & V_134 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_134 ( V_134 , V_132 , & V_103 ) ;
if ( V_21 < 0 )
goto error;
V_134 -> V_115 = V_103 ;
V_21 = F_113 ( V_103 , 0 , NULL ) ;
if ( V_21 < 0 )
goto error;
V_21 = F_148 ( V_103 ) ;
if ( V_21 < 0 )
goto error;
V_20 = V_282 ;
if ( V_283 [ V_130 ] )
V_20 |= V_284 ;
#ifdef F_161
if ( V_276 [ V_130 ] )
V_20 |= V_285 ;
#endif
if ( V_286 [ V_130 ] )
V_20 |= V_287 | V_288 ;
V_20 |= ( V_103 -> V_237 << 4 ) & 0xf0 ;
F_162 ( V_103 -> V_132 , V_289 , V_20 ) ;
if ( V_286 [ V_130 ] ) {
V_20 = V_286 [ V_130 ] ;
F_162 ( V_103 -> V_132 , V_290 , V_20 ) ;
V_21 = F_163 ( V_134 , 0 , V_291 ,
V_20 , V_292 , - 1 ,
& V_103 -> V_241 ) ;
if ( V_21 < 0 )
F_17 ( V_277
L_64 ,
V_20 ) ;
else
V_103 -> V_293 = V_20 ;
}
if ( V_283 [ V_130 ] ) {
V_20 = V_283 [ V_130 ] ;
F_162 ( V_103 -> V_132 , V_294 , V_20 ) ;
V_21 = F_164 ( V_134 , V_20 , V_20 + 2 ,
V_295 , 0 , & V_103 -> V_296 ) ;
if ( V_21 < 0 )
F_17 ( V_277
L_65 ,
V_20 ) ;
else {
V_103 -> V_297 = V_20 ;
V_21 = F_165 ( V_103 -> V_296 , 0 , 1 , NULL ) ;
if ( V_21 < 0 )
F_17 ( V_277
L_66 ) ;
}
}
#ifdef F_161
if ( V_276 [ V_130 ] ) {
V_20 = V_276 [ V_130 ] ;
F_162 ( V_103 -> V_132 , V_298 , V_20 ) ;
V_103 -> V_299 = V_20 ;
}
#endif
strcpy ( V_134 -> V_300 , L_40 ) ;
strcpy ( V_134 -> V_301 , L_67 ) ;
#ifdef F_161
snprintf ( V_134 -> V_260 , sizeof( V_134 -> V_260 ) ,
L_68 ,
V_134 -> V_301 , V_103 -> V_68 , V_103 -> V_237 , V_103 -> V_293 ,
V_103 -> V_297 , V_103 -> V_299 ) ;
#else
snprintf ( V_134 -> V_260 , sizeof( V_134 -> V_260 ) ,
L_69 ,
V_134 -> V_301 , V_103 -> V_68 , V_103 -> V_237 , V_103 -> V_293 ,
V_103 -> V_297 ) ;
#endif
F_145 ( V_103 ) ;
V_21 = F_166 ( V_134 ) ;
if ( V_21 < 0 )
goto error;
F_154 ( V_132 , V_134 ) ;
V_130 ++ ;
return 0 ;
error:
F_167 ( V_134 ) ;
return V_21 ;
}
static void F_168 ( struct V_131 * V_132 )
{
F_167 ( F_156 ( V_132 ) ) ;
}
static int T_5 F_169 ( void )
{
int V_21 ;
V_21 = F_170 ( & V_300 ) ;
if ( V_21 < 0 )
return V_21 ;
#if F_171 ( F_161 )
V_21 = F_170 ( & V_302 ) ;
if ( V_21 < 0 )
F_172 ( & V_300 ) ;
#endif
return V_21 ;
}
static void T_6 F_173 ( void )
{
F_172 ( & V_300 ) ;
#if F_171 ( F_161 )
F_172 ( & V_302 ) ;
#endif
}
