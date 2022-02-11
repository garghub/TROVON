static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 ;
int V_10 = - V_11 ;
F_2 ( & V_12 ) ;
if ( V_8 && V_8 -> V_13 ) {
V_8 -> V_14 ++ ;
if ( ( V_3 & V_15 ) && V_8 -> V_16 )
V_10 = - V_17 ;
else
V_10 = 0 ;
}
F_3 ( & V_12 ) ;
return V_10 ;
}
static void F_4 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = V_5 -> V_9 ;
int V_18 = F_5 ( F_6 ( V_5 ) ) >> V_19 ;
F_2 ( & V_12 ) ;
if ( V_8 ) {
if ( V_8 -> V_14 )
V_8 -> V_14 -- ;
if ( ! V_8 -> V_14 ) {
F_7 ( V_8 ) ;
V_5 -> V_9 = NULL ;
F_8 ( & V_20 , V_18 ) ;
F_9 ( V_5 ) ;
}
}
F_3 ( & V_12 ) ;
}
static void F_10 ( struct V_4 * V_5 , T_1 V_3 )
{
F_4 ( V_5 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_7 * V_8 = V_2 -> V_6 -> V_9 ;
V_22 -> V_23 = V_8 -> V_23 ;
V_22 -> V_24 = V_8 -> V_25 ;
V_22 -> V_26 = V_8 -> V_26 ;
return 0 ;
}
static struct V_27 * F_12 ( struct V_28 * V_29 )
{
struct V_30 * V_31
= F_13 ( V_29 , struct V_30 , V_29 ) ;
return F_13 ( V_31 , struct V_27 , V_31 ) ;
}
static const char * F_14 ( unsigned char V_32 )
{
switch ( V_32 ) {
case V_33 :
return L_1 ;
case V_34 :
return L_2 ;
case V_35 :
return L_3 ;
case V_36 :
return L_4 ;
case V_37 :
return L_5 ;
case V_38 :
return L_6 ;
case V_39 :
return L_7 ;
case V_40 :
return L_8 ;
default:
return NULL ;
} ;
}
static T_2 F_15 ( struct V_41 * V_42 ,
struct V_30 * V_29 ,
char * V_43 )
{
struct V_27 * V_44 = F_13 ( V_29 ,
struct V_27 ,
V_31 ) ;
T_2 V_45 , V_10 = 0 ;
for ( V_45 = 0 ; V_45 < V_44 -> V_46 ; V_45 ++ ) {
if ( V_45 && ! ( V_45 % 16 ) ) {
if ( V_47 - V_10 )
V_43 [ V_10 ++ ] = '\n' ;
}
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_9 ,
( ( unsigned char * ) V_44 -> V_48 ) [ V_45 ] ) ;
}
return V_10 ;
}
static T_2 F_17 ( struct V_41 * V_42 ,
struct V_30 * V_29 ,
char * V_43 )
{
struct V_27 * V_49 = F_13 ( V_29 ,
struct V_27 ,
V_31 ) ;
struct V_50 * V_51 = V_49 -> V_48 ;
T_2 V_10 = 0 ;
int V_52 = 0 , V_53 = 0 ;
if ( V_51 -> V_54 [ 0 ] > 0x80U ) {
V_52 = ( ~ V_51 -> V_54 [ 0 ] ) + 1 ;
V_53 = V_52 & 3 ;
V_52 >>= 2 ;
V_52 = - V_52 ;
V_53 *= 15 ;
} else if ( V_51 -> V_54 [ 0 ] < 0x80U ) {
V_52 = V_51 -> V_54 [ 0 ] ;
V_53 = V_52 & 3 ;
V_52 >>= 2 ;
V_53 *= 15 ;
}
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_10 ,
V_51 -> V_55 ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_11 ,
F_18 ( V_51 -> V_56 ) ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_12 ,
F_18 ( V_51 -> V_57 ) ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_13 ,
F_18 ( V_51 -> V_58 ) ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_14 ,
F_18 ( V_51 -> V_59 ) ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_15
L_16 ,
V_52 , V_53 ,
F_19 ( ( V_60 * ) & V_51 -> V_54 [ 1 ] ) ,
V_51 -> V_54 [ 3 ] , V_51 -> V_54 [ 4 ] ,
V_51 -> V_54 [ 5 ] , V_51 -> V_54 [ 6 ] ,
V_51 -> V_54 [ 7 ] ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_17 ,
F_20 ( V_51 -> V_61 ) ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 ,
L_18 ,
V_51 -> V_62 ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_19
L_20 , V_51 -> V_63 [ 0 ] ,
V_51 -> V_63 [ 1 ] ,
V_51 -> V_63 [ 2 ] ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_21 ,
F_18 ( V_51 -> V_64 ) ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_22 ,
F_18 ( V_51 -> V_65 ) ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_23 ,
V_51 -> V_66 ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_24 ,
V_51 -> V_67 ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_25 ,
F_18 ( V_51 -> V_68 ) ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 ,
L_26 ,
F_18 ( V_51 -> V_69 ) ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_27 ,
F_18 ( V_51 -> V_70 ) ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_28 ,
F_18 ( V_51 -> V_71 ) ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_29 ,
V_51 -> V_72 ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_30 ,
V_51 -> V_73 ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_31 ,
F_18 ( V_51 -> V_74 ) ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_32 ,
V_51 -> V_75 ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_33 ,
V_51 -> V_76 ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_34 ,
V_51 -> V_77 ) ;
return V_10 ;
}
static T_2 F_21 ( struct V_41 * V_42 ,
struct V_30 * V_29 ,
char * V_43 )
{
struct V_27 * V_44 = F_13 ( V_29 ,
struct V_27 ,
V_31 ) ;
return F_16 ( V_43 , V_47 , L_35 , ( char * ) V_44 -> V_48 ) ;
}
static T_2 F_22 ( struct V_41 * V_42 ,
struct V_30 * V_29 ,
char * V_43 )
{
struct V_27 * V_49 = F_13 ( V_29 ,
struct V_27 ,
V_31 ) ;
struct V_78 * V_79 = V_49 -> V_48 ;
T_2 V_10 = 0 ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_36 ,
V_79 -> V_80 ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_37 ,
V_79 -> V_81 ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_27 ,
V_79 -> V_70 ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_38 ,
V_79 -> V_82 ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_39 ,
V_79 -> V_83 ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_40 ,
V_79 -> V_84 ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_41 ,
V_79 -> V_85 ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_42 ,
V_79 -> V_86 ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_43 ,
V_79 -> V_87 ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 ,
L_44 ,
V_79 -> V_88 ) ;
return V_10 ;
}
static T_2 F_23 ( struct V_41 * V_42 ,
struct V_30 * V_29 ,
char * V_43 )
{
struct V_27 * V_49 = F_13 ( V_29 ,
struct V_27 ,
V_31 ) ;
struct V_89 * V_90 = V_49 -> V_48 ;
char V_91 [ 9 ] , V_92 [ 4 ] ;
T_2 V_10 = 0 ;
memcpy ( V_91 , V_90 -> V_91 , 8 ) ;
V_91 [ 8 ] = 0 ;
memcpy ( V_92 , V_90 -> V_92 , 3 ) ;
V_92 [ 3 ] = 0 ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_45 , V_91 ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_46 , V_92 ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_47 ,
V_90 -> V_29 ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_48 ,
V_90 -> time >> 11 ,
( V_90 -> time >> 5 ) & 0x3f ,
( V_90 -> time & 0x1f ) * 2 ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_49 ,
( V_90 -> V_93 >> 9 ) + 1980 ,
( V_90 -> V_93 >> 5 ) & 0xf ,
V_90 -> V_93 & 0x1f ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_50 ,
V_90 -> V_94 ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_51 ,
V_90 -> V_46 ) ;
return V_10 ;
}
static T_2 F_24 ( struct V_41 * V_42 ,
struct V_30 * V_29 ,
char * V_43 )
{
struct V_27 * V_49 = F_13 ( V_29 ,
struct V_27 ,
V_31 ) ;
struct V_95 * V_96 = V_49 -> V_48 ;
T_2 V_10 = 0 ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_52 ,
F_18 ( V_96 -> V_26 ) ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_53 ,
F_18 ( V_96 -> V_23 ) ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_54 ,
F_18 ( V_96 -> V_97 ) ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_55 ,
F_18 ( V_96 -> V_98 ) ) ;
V_10 += F_16 ( V_43 + V_10 , V_47 - V_10 , L_56 ,
F_18 ( V_96 -> V_25 ) ) ;
return V_10 ;
}
static T_3 F_25 ( unsigned char V_32 )
{
switch ( V_32 ) {
case V_33 :
return F_17 ;
case V_34 :
return F_21 ;
case V_35 :
return F_22 ;
case V_38 :
case V_39 :
return F_23 ;
case V_40 :
return F_24 ;
default:
return F_15 ;
}
}
static int F_26 ( struct V_99 * V_13 ,
struct V_100 * * V_101 )
{
struct V_7 * V_8 = F_27 ( V_13 ) ;
* V_101 = & V_13 -> V_102 ;
V_13 -> V_103 = V_8 -> V_104 ;
return 0 ;
}
static int F_28 ( struct V_99 * V_13 ,
struct V_100 * * V_101 )
{
return F_29 ( V_13 , ( * V_101 ) -> error ) ;
}
static int F_30 ( struct V_99 * V_13 ,
struct V_100 * * V_101 )
{
return - V_11 ;
}
static int F_31 ( struct V_99 * V_13 ,
struct V_100 * * V_101 )
{
struct V_7 * V_8 = F_27 ( V_13 ) ;
if ( ! ( * V_101 ) -> error ) {
if ( ( * V_101 ) -> V_48 [ F_32 ( struct V_105 , V_106 ) ]
& V_107 )
V_8 -> V_16 = 1 ;
else
V_8 -> V_16 = 0 ;
}
return F_29 ( V_13 , ( * V_101 ) -> error ) ;
}
static int F_33 ( struct V_99 * V_13 ,
struct V_100 * * V_101 )
{
F_34 ( & V_13 -> V_42 , L_57 , ( * V_101 ) -> V_48 [ 0 ] ) ;
if ( ! ( * V_101 ) -> error ) {
if ( ( * V_101 ) -> V_48 [ 0 ] & ( V_108 | V_109 ) )
( * V_101 ) -> error = - V_110 ;
else if ( ! ( ( * V_101 ) -> V_48 [ 0 ] & V_111 ) )
return 0 ;
}
return F_29 ( V_13 , ( * V_101 ) -> error ) ;
}
static int F_35 ( struct V_99 * V_13 ,
struct V_100 * * V_101 )
{
struct V_7 * V_8 = F_27 ( V_13 ) ;
unsigned char V_112 = 0 ;
struct V_113 V_114 = { 0 } ;
T_4 V_115 ;
if ( ( * V_101 ) -> error )
return F_29 ( V_13 , ( * V_101 ) -> error ) ;
switch ( ( * V_101 ) -> V_116 ) {
case V_117 :
F_36 ( * V_101 , V_118 , & V_8 -> V_119 , 1 ) ;
( * V_101 ) -> V_120 = 1 ;
return 0 ;
case V_118 :
V_112 = ( * V_101 ) -> V_121 ;
F_36 ( * V_101 , V_122 , NULL , 1 ) ;
if ( V_8 -> V_123 & V_124 )
goto V_125;
return 0 ;
case V_122 :
V_112 = ( * V_101 ) -> V_48 [ 0 ] ;
V_125:
if ( V_112 & ( V_108 | V_109 ) ) {
V_112 = V_126 ;
F_36 ( * V_101 , V_118 , & V_112 , 1 ) ;
V_13 -> V_103 = F_28 ;
return 0 ;
}
if ( V_8 -> V_127
== ( V_8 -> V_128 [ V_8 -> V_129 ] . V_130
/ V_8 -> V_59 ) ) {
V_8 -> V_127 = 0 ;
V_8 -> V_129 ++ ;
if ( V_8 -> V_129 == V_8 -> V_131 ) {
if ( V_112 & V_111 ) {
return F_29 ( V_13 ,
0 ) ;
} else {
V_13 -> V_103
= F_33 ;
F_36 ( * V_101 , V_122 ,
NULL , 1 ) ;
return 0 ;
}
}
}
if ( ! ( V_112 & V_132 ) ) {
F_36 ( * V_101 , V_122 , NULL , 1 ) ;
return 0 ;
}
V_115 = V_8 -> V_128 [ V_8 -> V_129 ] . V_133 ;
V_115 += V_8 -> V_127 * V_8 -> V_59 ;
F_37 ( & V_114 ,
F_38 ( F_39 ( & ( V_8 -> V_128 [ V_8 -> V_129 ] ) ) ,
V_115 >> V_134 ) ,
V_8 -> V_59 , F_40 ( V_115 ) ) ;
F_41 ( * V_101 , V_8 -> V_135 == V_136
? V_137
: V_138 ,
& V_114 ) ;
( * V_101 ) -> V_120 = 1 ;
return 0 ;
case V_137 :
case V_138 :
V_8 -> V_127 ++ ;
if ( V_8 -> V_123 & V_124 ) {
V_112 = ( * V_101 ) -> V_121 ;
goto V_125;
} else {
F_36 ( * V_101 , V_122 , NULL , 1 ) ;
return 0 ;
}
default:
F_42 () ;
}
}
static void F_43 ( struct V_99 * V_13 , T_5 V_133 ,
T_4 V_130 )
{
struct V_7 * V_8 = F_27 ( V_13 ) ;
struct V_139 V_140 = {
. system = V_8 -> system ,
. V_141 = F_44 ( ( V_142 ) ( V_130 / V_8 -> V_59 ) ) ,
. V_143 = 0 ,
. V_144 = 0
} ;
F_45 ( V_133 , V_8 -> V_59 ) ;
V_140 . V_143 = F_46 ( ( V_145 ) V_133 ) ;
V_13 -> V_103 = F_26 ;
V_8 -> V_104 = F_35 ;
F_36 ( & V_13 -> V_102 , V_117 ,
& V_140 , sizeof( V_140 ) ) ;
}
static int F_47 ( struct V_99 * V_13 , int V_146 )
{
struct V_7 * V_8 = F_27 ( V_13 ) ;
T_5 V_147 ;
unsigned int V_148 ;
V_149:
while ( V_146 ) {
V_8 -> V_127 = 0 ;
V_8 -> V_129 = 0 ;
V_8 -> V_131 = F_48 ( V_8 -> V_150 -> V_151 ,
V_8 -> V_150 ,
V_8 -> V_128 ) ;
if ( ! V_8 -> V_131 ) {
V_146 = F_49 ( V_8 -> V_150 , - V_152 ) ;
continue;
}
V_147 = F_50 ( V_8 -> V_150 ) ;
V_147 <<= 9 ;
V_148 = F_51 ( V_8 -> V_150 ) ;
V_8 -> V_153 ( V_13 , V_147 , V_148 ) ;
V_8 -> V_135 = F_52 ( V_8 -> V_150 ) ;
V_8 -> V_119 = V_8 -> V_135 == V_136
? V_154
: V_155 ;
F_53 ( V_13 -> V_156 ) ;
return 0 ;
}
F_34 ( & V_13 -> V_42 , L_58 ) ;
V_8 -> V_150 = F_54 ( V_8 -> V_157 ) ;
if ( ! V_8 -> V_150 ) {
F_34 ( & V_13 -> V_42 , L_59 ) ;
return - V_158 ;
}
F_34 ( & V_13 -> V_42 , L_60 ) ;
V_146 = 1 ;
goto V_149;
}
static int F_29 ( struct V_99 * V_13 , int error )
{
struct V_7 * V_8 = F_27 ( V_13 ) ;
int V_146 , V_45 ;
unsigned int V_159 = 0 ;
unsigned long V_160 ;
F_55 ( & V_8 -> V_161 , V_160 ) ;
F_34 ( & V_13 -> V_42 , L_61 , V_8 -> V_162 ? 1 : 0 ,
error ) ;
if ( V_8 -> V_162 ) {
if ( error == - V_158 )
error = 0 ;
if ( error || ( V_13 -> V_102 . V_116 == V_126 ) ) {
if ( V_8 -> V_135 == V_136 ) {
for ( V_45 = 0 ; V_45 < V_8 -> V_129 ; V_45 ++ ) {
V_159 += V_8 -> V_128 [ V_45 ] . V_130
/ V_8 -> V_59 ;
if ( V_8 -> V_127 )
V_159 += V_8 -> V_127 - 1 ;
V_159 *= V_8 -> V_59 ;
}
}
} else
V_159 = F_51 ( V_8 -> V_150 ) ;
F_34 ( & V_13 -> V_42 , L_62 , V_159 , error ) ;
if ( error && ! V_159 )
V_159 = F_56 ( V_8 -> V_150 ) ;
V_146 = F_57 ( V_8 -> V_150 , error , V_159 ) ;
error = F_47 ( V_13 , V_146 ) ;
if ( ! error )
goto V_163;
else
V_8 -> V_162 = 0 ;
} else {
if ( ! error )
error = - V_158 ;
}
V_13 -> V_103 = F_30 ;
F_58 ( & V_13 -> V_164 ) ;
V_163:
F_59 ( & V_8 -> V_161 , V_160 ) ;
return error ;
}
static void F_60 ( struct V_99 * V_13 )
{
struct V_7 * V_8 = F_27 ( V_13 ) ;
int V_10 = 0 ;
unsigned long V_160 ;
while ( 1 ) {
F_55 ( & V_8 -> V_161 , V_160 ) ;
if ( ! V_8 -> V_162 ) {
F_61 ( V_8 -> V_157 ) ;
V_10 = 1 ;
}
F_59 ( & V_8 -> V_161 , V_160 ) ;
if ( V_10 )
break;
F_62 ( & V_13 -> V_164 ) ;
}
}
static void F_63 ( struct V_99 * V_13 )
{
struct V_7 * V_8 = F_27 ( V_13 ) ;
unsigned long V_160 ;
F_55 ( & V_8 -> V_161 , V_160 ) ;
F_64 ( V_8 -> V_157 ) ;
F_59 ( & V_8 -> V_161 , V_160 ) ;
}
static int F_65 ( struct V_165 * V_151 , struct V_166 * V_167 )
{
if ( V_167 -> V_168 != V_169 &&
V_167 -> V_168 != V_170 ) {
F_66 ( V_167 , L_63 ) ;
return V_171 ;
}
V_167 -> V_172 |= V_173 ;
return V_174 ;
}
static void F_67 ( struct V_165 * V_151 )
{
struct V_99 * V_13 = V_151 -> V_175 ;
struct V_7 * V_8 = F_27 ( V_13 ) ;
struct V_166 * V_167 = NULL ;
if ( V_8 -> V_162 )
return;
if ( V_8 -> V_176 ) {
while ( ( V_167 = F_54 ( V_151 ) ) != NULL )
F_68 ( V_167 , - V_177 ) ;
return;
}
V_8 -> V_162 = 1 ;
if ( F_47 ( V_13 , 0 ) )
V_8 -> V_162 = 0 ;
}
static int F_69 ( struct V_99 * V_13 )
{
struct V_7 * V_8 = F_27 ( V_13 ) ;
V_13 -> V_103 = F_26 ;
V_8 -> V_104 = F_33 ;
F_36 ( & V_13 -> V_102 , V_122 , NULL , 1 ) ;
F_53 ( V_13 -> V_156 ) ;
F_62 ( & V_13 -> V_164 ) ;
return V_13 -> V_102 . error ;
}
static int F_70 ( struct V_99 * V_13 ,
unsigned char V_178 )
{
struct V_179 * V_156 = V_13 -> V_156 ;
struct V_7 * V_8 = F_27 ( V_13 ) ;
struct V_139 V_140 = {
. system = V_178 ,
. V_141 = 0 ,
. V_143 = 0 ,
. V_144 = 0
} ;
V_13 -> V_103 = F_26 ;
V_8 -> V_104 = F_28 ;
F_36 ( & V_13 -> V_102 , V_117 , & V_140 ,
sizeof( V_140 ) ) ;
F_53 ( V_156 ) ;
F_62 ( & V_13 -> V_164 ) ;
return V_13 -> V_102 . error ;
}
static int F_71 ( struct V_99 * V_13 )
{
struct V_179 * V_156 = V_13 -> V_156 ;
struct V_7 * V_8 = F_27 ( V_13 ) ;
int V_10 = 0 ;
V_149:
if ( V_8 -> V_123 & V_180 )
V_10 = F_70 ( V_13 , V_181 ) ;
else
return 0 ;
if ( V_10 ) {
F_72 ( V_182
L_64 ,
F_73 ( & V_13 -> V_42 ) , V_10 ) ;
return 0 ;
}
V_8 -> system = V_181 ;
V_156 -> V_183 ( V_156 , V_184 , V_185 ) ;
F_72 ( V_186 L_65 ,
F_73 ( & V_13 -> V_42 ) ) ;
if ( V_8 -> V_123 & V_187 ) {
V_10 = F_70 ( V_13 , V_188 ) ;
if ( ! V_10 ) {
V_8 -> system = V_188 ;
V_156 -> V_183 ( V_156 , V_184 ,
V_189 ) ;
F_72 ( V_186
L_66 ,
F_73 ( & V_13 -> V_42 ) ) ;
} else
F_72 ( V_182
L_67 ,
F_73 ( & V_13 -> V_42 ) , V_10 ) ;
}
V_13 -> V_103 = F_26 ;
V_8 -> V_104 = F_28 ;
F_36 ( & V_13 -> V_102 , V_122 , NULL , 1 ) ;
F_53 ( V_13 -> V_156 ) ;
F_62 ( & V_13 -> V_164 ) ;
V_10 = V_13 -> V_102 . error ;
if ( V_10 ) {
F_72 ( V_182
L_68 ,
F_73 ( & V_13 -> V_42 ) ) ;
V_8 -> system = V_190 ;
V_156 -> V_183 ( V_156 , V_191 , V_192 ) ;
F_74 ( 10 ) ;
V_156 -> V_183 ( V_156 , V_191 , V_193 ) ;
V_156 -> V_183 ( V_156 , V_184 , V_194 ) ;
V_10 = F_75 ( V_13 ) ;
if ( ! V_10 )
V_10 = F_70 ( V_13 , V_8 -> system ) ;
if ( ! V_10 ) {
F_74 ( 150 ) ;
V_10 = F_69 ( V_13 ) ;
if ( V_10 )
return V_10 ;
if ( V_8 -> V_123 & V_187 ) {
V_8 -> V_123 &= ~ V_187 ;
goto V_149;
}
}
}
return V_10 ;
}
static int F_76 ( struct V_99 * V_13 )
{
struct V_7 * V_8 = F_27 ( V_13 ) ;
struct V_195 * V_29 = NULL ;
struct V_27 * V_44 = NULL ;
unsigned char * V_43 = NULL ;
int V_45 , V_10 , V_196 ;
unsigned int V_197 , V_198 = 0 , V_199 = V_8 -> V_59 ;
V_29 = F_77 ( V_8 -> V_59 , V_200 ) ;
if ( ! V_29 )
return - V_152 ;
F_78 ( & V_8 -> V_128 [ 0 ] , V_29 , V_8 -> V_59 ) ;
V_8 -> V_131 = 1 ;
V_8 -> V_129 = 0 ;
V_8 -> V_127 = 0 ;
V_8 -> V_135 = V_136 ;
V_8 -> V_119 = V_201 ;
V_8 -> V_153 ( V_13 , V_198 , V_199 ) ;
F_53 ( V_13 -> V_156 ) ;
F_62 ( & V_13 -> V_164 ) ;
if ( V_13 -> V_102 . error ) {
V_10 = V_13 -> V_102 . error ;
goto V_202;
}
if ( F_18 ( V_29 -> V_203 ) != V_204 ) {
F_72 ( V_205 L_69 ,
F_73 ( & V_13 -> V_42 ) , F_18 ( V_29 -> V_203 ) ) ;
V_10 = - V_177 ;
goto V_202;
}
if ( V_29 -> V_148 > V_206 ) {
F_72 ( V_182 L_70 ,
F_73 ( & V_13 -> V_42 ) ) ;
V_196 = V_206 ;
} else
V_196 = V_29 -> V_148 ;
V_8 -> V_207 . V_208 = F_79 ( V_196 + 1 ,
sizeof( * V_8 -> V_207 . V_208 ) ,
V_200 ) ;
if ( ! V_8 -> V_207 . V_208 ) {
V_10 = - V_152 ;
goto V_202;
}
V_8 -> V_207 . V_91 = L_71 ;
V_43 = F_77 ( V_199 , V_200 ) ;
if ( ! V_43 ) {
V_10 = - V_152 ;
goto V_202;
}
memcpy ( V_43 , ( char * ) V_29 , V_199 ) ;
for ( V_45 = 0 ; V_45 < V_196 ; ++ V_45 ) {
V_44 = F_80 ( sizeof( struct V_27 ) , V_200 ) ;
if ( ! V_44 ) {
V_10 = - V_152 ;
goto V_209;
}
V_8 -> V_207 . V_208 [ V_45 ] = & V_44 -> V_31 . V_29 ;
V_197 = F_20 ( V_29 -> V_210 [ V_45 ] . V_211 ) ;
V_44 -> V_46 = F_20 ( V_29 -> V_210 [ V_45 ] . V_46 ) ;
F_34 ( & V_13 -> V_42 , L_72
L_73 , V_45 , V_29 -> V_210 [ V_45 ] . V_212 , V_197 ,
V_44 -> V_46 ) ;
V_44 -> V_212 = V_29 -> V_210 [ V_45 ] . V_212 ;
if ( F_14 ( V_44 -> V_212 ) )
snprintf ( V_44 -> V_91 , sizeof( V_44 -> V_91 ) , L_35 ,
F_14 ( V_29 -> V_210 [ V_45 ] . V_212 ) ) ;
else
snprintf ( V_44 -> V_91 , sizeof( V_44 -> V_91 ) ,
L_74 , V_29 -> V_210 [ V_45 ] . V_212 ) ;
F_81 ( & V_44 -> V_31 . V_29 ) ;
V_44 -> V_31 . V_29 . V_91 = V_44 -> V_91 ;
V_44 -> V_31 . V_29 . V_3 = V_213 ;
V_44 -> V_31 . V_214 = F_25 ( V_44 -> V_212 ) ;
if ( ! V_44 -> V_46 )
continue;
V_44 -> V_48 = F_77 ( V_44 -> V_46 , V_200 ) ;
if ( ! V_44 -> V_48 ) {
V_10 = - V_152 ;
goto V_209;
}
if ( ( ( V_197 / V_8 -> V_59 ) == ( V_198 / V_8 -> V_59 ) )
&& ( ( ( V_197 + V_44 -> V_46 - 1 ) / V_8 -> V_59 )
== ( V_198 / V_8 -> V_59 ) ) ) {
memcpy ( V_44 -> V_48 , V_43 + V_197 % V_8 -> V_59 ,
V_44 -> V_46 ) ;
continue;
}
V_198 = ( V_197 / V_8 -> V_59 ) * V_8 -> V_59 ;
if ( ( V_198 + V_199 ) < ( V_197 + V_44 -> V_46 ) ) {
F_7 ( V_43 ) ;
V_199 = ( ( ( V_197 + V_44 -> V_46 ) / V_8 -> V_59 )
+ 1 ) * V_8 -> V_59 - V_198 ;
V_43 = F_77 ( V_199 , V_200 ) ;
if ( ! V_43 ) {
V_10 = - V_152 ;
goto V_202;
}
}
F_78 ( & V_8 -> V_128 [ 0 ] , V_43 , V_199 ) ;
V_8 -> V_131 = 1 ;
V_8 -> V_129 = 0 ;
V_8 -> V_127 = 0 ;
V_8 -> V_135 = V_136 ;
V_8 -> V_119 = V_201 ;
F_34 ( & V_13 -> V_42 , L_75 ,
V_198 , V_199 ) ;
V_8 -> V_153 ( V_13 , V_198 , V_199 ) ;
F_53 ( V_13 -> V_156 ) ;
F_62 ( & V_13 -> V_164 ) ;
if ( V_13 -> V_102 . error ) {
V_10 = V_13 -> V_102 . error ;
goto V_209;
}
memcpy ( V_44 -> V_48 , V_43 + V_197 % V_8 -> V_59 ,
V_44 -> V_46 ) ;
}
V_10 = 0 ;
V_209:
F_7 ( V_43 ) ;
V_202:
F_7 ( V_29 ) ;
return V_10 ;
}
static int F_82 ( struct V_99 * V_13 )
{
struct V_7 * V_8 = F_27 ( V_13 ) ;
struct V_179 * V_156 = V_13 -> V_156 ;
int V_10 = 0 ;
V_8 -> system = V_190 ;
V_8 -> V_153 = F_43 ;
V_13 -> V_215 . V_216 = F_32 ( struct V_217 , V_218 ) ;
V_13 -> V_215 . V_219 = sizeof( struct V_105 ) ;
V_13 -> V_215 . V_220 = F_32 ( struct V_217 , V_140 ) ;
V_13 -> V_215 . V_221 = sizeof( struct V_139 ) ;
if ( F_75 ( V_13 ) )
return - V_222 ;
V_8 -> V_123 = V_156 -> V_123 ;
F_74 ( 150 ) ;
V_10 = F_69 ( V_13 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_71 ( V_13 ) ;
if ( V_10 )
return V_10 ;
F_34 ( & V_13 -> V_42 , L_76 ) ;
if ( V_8 -> system != V_190 )
V_8 -> V_123 |= V_124 ;
V_13 -> V_103 = F_26 ;
V_8 -> V_104 = F_31 ;
F_36 ( & V_13 -> V_102 , V_223 , NULL ,
sizeof( struct V_105 ) ) ;
F_53 ( V_13 -> V_156 ) ;
F_62 ( & V_13 -> V_164 ) ;
if ( V_13 -> V_102 . error )
return V_13 -> V_102 . error ;
F_34 ( & V_13 -> V_42 , L_77 , V_8 -> V_16 ? 0 : 1 ) ;
V_8 -> V_59 = 512 ;
V_10 = F_76 ( V_13 ) ;
if ( V_10 )
return V_10 ;
F_34 ( & V_13 -> V_42 , L_78 ) ;
return 0 ;
}
static int F_83 ( struct V_99 * V_13 )
{
struct V_7 * V_8 = F_27 ( V_13 ) ;
struct V_179 * V_156 = V_13 -> V_156 ;
struct V_95 * V_224 = NULL ;
struct V_50 * V_225 = NULL ;
struct V_27 * V_44 = NULL ;
int V_10 , V_18 ;
T_5 V_226 = V_227 ;
unsigned long V_228 ;
if ( V_156 -> V_42 . V_229 && * ( V_156 -> V_42 . V_229 ) )
V_226 = * ( V_156 -> V_42 . V_229 ) ;
for ( V_10 = 0 ; V_8 -> V_207 . V_208 [ V_10 ] ; ++ V_10 ) {
V_44 = F_12 ( V_8 -> V_207 . V_208 [ V_10 ] ) ;
if ( V_44 -> V_212 == V_40 )
V_224 = V_44 -> V_48 ;
else if ( V_44 -> V_212 == V_33 )
V_225 = V_44 -> V_48 ;
}
if ( ! V_224 || ! V_225 )
return - V_177 ;
V_8 -> V_26 = F_18 ( V_224 -> V_26 ) ;
V_8 -> V_23 = F_18 ( V_224 -> V_23 ) ;
V_8 -> V_25 = F_18 ( V_224 -> V_25 ) ;
V_8 -> V_59 = F_18 ( V_225 -> V_71 ) ;
F_2 ( & V_12 ) ;
V_18 = F_84 ( & V_20 , V_13 , 0 , 256 , V_200 ) ;
F_3 ( & V_12 ) ;
if ( V_18 < 0 )
return V_18 ;
V_8 -> V_5 = F_85 ( 1 << V_19 ) ;
if ( ! V_8 -> V_5 ) {
V_10 = - V_152 ;
goto V_230;
}
V_8 -> V_157 = F_86 ( F_67 , & V_8 -> V_161 ) ;
if ( ! V_8 -> V_157 ) {
V_10 = - V_152 ;
goto V_231;
}
V_8 -> V_157 -> V_175 = V_13 ;
F_87 ( V_8 -> V_157 , F_65 ) ;
F_88 ( V_8 -> V_157 , V_226 ) ;
F_89 ( V_8 -> V_157 , V_232 ) ;
F_90 ( V_8 -> V_157 , V_233 ) ;
F_91 ( V_8 -> V_157 ,
V_232 * V_8 -> V_59 ) ;
V_8 -> V_5 -> V_234 = V_234 ;
V_8 -> V_5 -> V_235 = V_18 << V_19 ;
V_8 -> V_5 -> V_236 = & V_237 ;
V_8 -> V_14 = 1 ;
V_8 -> V_5 -> V_9 = V_8 ;
V_8 -> V_5 -> V_157 = V_8 -> V_157 ;
V_8 -> V_5 -> V_238 = & V_13 -> V_42 ;
sprintf ( V_8 -> V_5 -> V_239 , L_79 , V_18 ) ;
F_92 ( V_8 -> V_157 , V_8 -> V_59 ) ;
V_228 = F_18 ( V_225 -> V_58 ) ;
V_228 *= F_18 ( V_225 -> V_56 ) ;
V_228 *= V_8 -> V_59 >> 9 ;
F_93 ( V_8 -> V_5 , V_228 ) ;
F_34 ( & V_13 -> V_42 , L_80 , V_228 ) ;
F_94 ( V_8 -> V_5 ) ;
V_8 -> V_240 = 1 ;
return 0 ;
V_231:
F_9 ( V_8 -> V_5 ) ;
V_230:
F_2 ( & V_12 ) ;
F_8 ( & V_20 , V_18 ) ;
F_3 ( & V_12 ) ;
return V_10 ;
}
static void F_95 ( struct V_7 * V_8 )
{
int V_45 ;
struct V_27 * V_44 ;
if ( V_8 -> V_207 . V_208 ) {
for ( V_45 = 0 ; V_8 -> V_207 . V_208 [ V_45 ] ; ++ V_45 ) {
V_44 = F_12 ( V_8 -> V_207
. V_208 [ V_45 ] ) ;
F_7 ( V_44 -> V_48 ) ;
F_7 ( V_44 ) ;
}
F_7 ( V_8 -> V_207 . V_208 ) ;
}
V_8 -> V_13 = NULL ;
}
static int F_96 ( struct V_99 * V_13 )
{
struct V_7 * V_8 = F_27 ( V_13 ) ;
return ( V_8 -> V_240 == 1 ) ;
}
static int F_97 ( struct V_99 * V_13 )
{
struct V_7 * V_8 ;
int V_10 = 0 ;
V_8 = F_80 ( sizeof( struct V_7 ) , V_200 ) ;
if ( ! V_8 )
return - V_152 ;
F_98 ( V_13 , V_8 ) ;
V_8 -> V_13 = V_13 ;
F_99 ( & V_8 -> V_161 ) ;
V_10 = F_82 ( V_13 ) ;
if ( V_10 )
goto V_241;
V_10 = F_100 ( & V_13 -> V_42 . V_242 , & V_8 -> V_207 ) ;
if ( V_10 )
goto V_241;
V_10 = F_83 ( V_13 ) ;
if ( ! V_10 ) {
V_13 -> V_243 = F_96 ;
V_13 -> V_244 = F_60 ;
V_13 -> V_245 = F_63 ;
return 0 ;
}
F_101 ( & V_13 -> V_42 . V_242 , & V_8 -> V_207 ) ;
V_241:
F_98 ( V_13 , NULL ) ;
F_95 ( V_8 ) ;
F_7 ( V_8 ) ;
return V_10 ;
}
static void F_102 ( struct V_99 * V_13 )
{
struct V_7 * V_8 = F_27 ( V_13 ) ;
unsigned long V_160 ;
F_55 ( & V_8 -> V_161 , V_160 ) ;
V_8 -> V_176 = 1 ;
F_64 ( V_8 -> V_157 ) ;
F_59 ( & V_8 -> V_161 , V_160 ) ;
F_103 ( V_8 -> V_5 ) ;
F_34 ( & V_13 -> V_42 , L_81 ) ;
F_104 ( V_8 -> V_157 ) ;
V_8 -> V_157 = NULL ;
F_101 ( & V_13 -> V_42 . V_242 , & V_8 -> V_207 ) ;
F_2 ( & V_12 ) ;
F_95 ( V_8 ) ;
F_3 ( & V_12 ) ;
F_4 ( V_8 -> V_5 ) ;
F_98 ( V_13 , NULL ) ;
}
static int F_105 ( struct V_99 * V_13 , T_6 V_246 )
{
struct V_7 * V_8 = F_27 ( V_13 ) ;
unsigned long V_160 ;
F_55 ( & V_8 -> V_161 , V_160 ) ;
F_61 ( V_8 -> V_157 ) ;
V_8 -> V_240 = 0 ;
F_59 ( & V_8 -> V_161 , V_160 ) ;
return 0 ;
}
static int F_106 ( struct V_99 * V_13 )
{
struct V_7 * V_8 = F_27 ( V_13 ) ;
unsigned long V_160 ;
int V_10 = 0 ;
#ifdef F_107
struct V_7 * V_247 ;
struct V_179 * V_156 = V_13 -> V_156 ;
struct V_27 * V_44 , * V_248 ;
unsigned char V_45 ;
F_2 ( & V_156 -> V_249 ) ;
V_247 = F_80 ( sizeof( struct V_7 ) , V_200 ) ;
if ( ! V_247 ) {
V_10 = - V_152 ;
goto V_250;
}
V_247 -> V_13 = V_13 ;
F_98 ( V_13 , V_247 ) ;
if ( F_82 ( V_13 ) )
goto V_241;
for ( V_45 = 0 ; V_247 -> V_207 . V_208 [ V_45 ]
&& V_8 -> V_207 . V_208 [ V_45 ] ; ++ V_45 ) {
V_44 = F_12 ( V_247 -> V_207 . V_208 [ V_45 ] ) ;
V_248 = F_12 ( V_8 -> V_207 . V_208 [ V_45 ] ) ;
if ( V_44 -> V_212 == V_33
&& V_248 -> V_212 == V_44 -> V_212 ) {
if ( memcmp ( V_44 -> V_48 , V_248 -> V_48 , V_44 -> V_46 ) )
break;
V_8 -> V_240 = 1 ;
break;
}
}
V_241:
F_98 ( V_13 , V_8 ) ;
F_95 ( V_247 ) ;
F_7 ( V_247 ) ;
V_250:
F_3 ( & V_156 -> V_249 ) ;
#endif
F_55 ( & V_8 -> V_161 , V_160 ) ;
F_64 ( V_8 -> V_157 ) ;
F_59 ( & V_8 -> V_161 , V_160 ) ;
return V_10 ;
}
static int T_7 F_108 ( void )
{
int V_10 = - V_152 ;
V_10 = F_109 ( V_234 , V_251 ) ;
if ( V_10 < 0 ) {
F_72 (KERN_ERR DRIVER_NAME L_82
L_83 , major, rc) ;
return V_10 ;
}
if ( ! V_234 )
V_234 = V_10 ;
V_10 = F_110 ( & V_252 ) ;
if ( V_10 )
F_111 ( V_234 , V_251 ) ;
return V_10 ;
}
static void T_8 F_112 ( void )
{
F_113 ( & V_252 ) ;
F_111 ( V_234 , V_251 ) ;
F_114 ( & V_20 ) ;
}
