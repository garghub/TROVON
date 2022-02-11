static T_1 void F_1 ( T_2 * V_1 )
{
if ( F_2 ( V_1 ) ) {
V_1 -> V_2 . V_3 = F_3 ( V_1 ) ;
V_1 -> V_2 . V_4 = F_4 ( V_1 ) - 1 ;
V_1 -> V_2 . V_5 = F_5 ( V_1 -> V_2 . V_3 ) ;
V_1 -> V_2 . V_6 = V_1 -> V_2 . V_3 -> V_7 ;
} else {
V_1 -> V_2 . V_3 = NULL ;
V_1 -> V_2 . V_4 = 0 ;
V_1 -> V_2 . V_5 = NULL ;
V_1 -> V_2 . V_6 = 0 ;
}
}
static int F_6 ( struct V_8 * V_9 , int V_10 , int V_11 , int V_12 , int V_13 )
{
F_7 () ;
int V_14 = 500 ;
unsigned long V_15 = V_16 + V_13 ;
int V_17 ;
F_8 ( V_9 ) ;
while( V_14 -- > 0 )
{
V_17 = F_9 ( V_10 ) ;
if( ( V_17 & V_11 ) == V_12 )
return 0 ;
F_10 () ;
}
while( F_11 ( V_16 , V_15 ) )
{
V_17 = F_9 ( V_10 ) ;
if( ( V_17 & V_11 ) == V_12 )
return 0 ;
if( ! F_12 () )
F_13 () ;
else
F_10 () ;
}
return - V_18 ;
}
static void F_14 ( struct V_8 * V_9 )
{
F_7 () ;
unsigned char V_19 , V_20 , V_21 , V_22 , V_23 , V_24 ;
F_8 ( V_9 ) ;
V_20 = F_9 ( V_25 ) ;
V_19 = F_9 ( V_26 ) ;
V_22 = F_9 ( V_27 ) ;
V_23 = F_9 ( V_28 ) ;
V_21 = F_9 ( V_29 ) ;
F_15 ( L_1 , V_19 ) ;
for ( V_24 = 0 ; V_30 [ V_24 ] . V_31 ; ++ V_24 )
if ( V_19 & V_30 [ V_24 ] . V_31 )
F_15 ( L_2 , V_30 [ V_24 ] . V_32 ) ;
F_15 ( L_3 , V_21 ) ;
for ( V_24 = 0 ; V_33 [ V_24 ] . V_31 ; ++ V_24 )
if ( V_21 & V_33 [ V_24 ] . V_31 )
F_15 ( L_2 , V_33 [ V_24 ] . V_32 ) ;
F_15 ( L_4 , V_23 ) ;
for ( V_24 = 0 ; V_34 [ V_24 ] . V_31 ; ++ V_24 )
if ( V_23 & V_34 [ V_24 ] . V_31 )
F_15 ( L_2 , V_34 [ V_24 ] . V_32 ) ;
F_15 ( L_5 , V_22 ) ;
for ( V_24 = 0 ; V_35 [ V_24 ] . V_31 ; ++ V_24 )
if ( V_22 & V_35 [ V_24 ] . V_31 )
F_15 ( L_2 , V_35 [ V_24 ] . V_32 ) ;
F_15 ( L_6 ) ;
}
static void F_16 ( struct V_8 * V_9 )
{
F_7 () ;
unsigned char V_19 ;
int V_24 ;
F_8 ( V_9 ) ;
V_19 = F_9 ( V_26 ) ;
if ( ! ( V_19 & V_36 ) )
F_15 ( L_7 , V_9 -> V_37 ) ;
else {
for ( V_24 = 0 ; ( V_38 [ V_24 ] . V_39 != V_40 ) && ( V_38 [ V_24 ] . V_39 != ( V_19 & V_41 ) ) ; ++ V_24 ) ;
F_15 ( L_8 , V_9 -> V_37 , V_38 [ V_24 ] . V_32 ) ;
}
}
static int F_17 ( unsigned char V_1 )
{
switch ( V_1 ) {
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
return V_48 ;
case V_49 :
case V_50 :
case V_51 :
case V_52 :
return V_53 ;
default:
return V_54 ;
}
}
static void F_18 ( struct V_55 * V_56 , unsigned long V_57 )
{
V_56 -> V_58 = V_16 + V_57 ;
F_19 ( & V_56 -> V_59 , V_57 ) ;
}
static T_3 T_4 F_20 ( int V_60 , void * V_61 )
{
V_62 = V_60 ;
return V_63 ;
}
static int T_4 T_5 F_21 ( struct V_8 * V_9 ,
int V_64 )
{
F_7 () ;
struct V_55 * V_56 = (struct V_55 * ) V_9 -> V_56 ;
unsigned long V_57 ;
int V_65 , V_24 , V_31 ;
F_8 ( V_9 ) ;
for ( V_65 = V_24 = 0 , V_31 = 1 ; V_24 < 16 ; ++ V_24 , V_31 <<= 1 )
if ( ( V_31 & V_64 ) && ( F_22 ( V_24 , & F_20 , V_66 , L_9 , NULL ) == 0 ) )
V_65 |= V_31 ;
V_57 = V_16 + ( 250 * V_67 / 1000 ) ;
V_62 = V_68 ;
F_23 ( V_69 , 0 ) ;
F_23 ( V_70 , V_56 -> V_71 ) ;
F_23 ( V_72 , V_56 -> V_71 ) ;
F_23 ( V_28 , V_73 | V_74 | V_75 ) ;
while ( V_62 == V_68 && F_11 ( V_16 , V_57 ) )
F_24 ( 1 ) ;
F_23 ( V_70 , 0 ) ;
F_23 ( V_28 , V_73 ) ;
for ( V_24 = 0 , V_31 = 1 ; V_24 < 16 ; ++ V_24 , V_31 <<= 1 )
if ( V_65 & V_31 )
F_25 ( V_24 , NULL ) ;
return V_62 ;
}
static void T_4 T_5
F_26 ( struct V_8 * V_9 )
{
F_15 ( L_10
#ifdef F_27
L_11
#endif
#ifdef F_28
L_12
#endif
#ifdef F_29
L_13
#endif
#ifdef F_30
L_14
#endif
#ifdef F_31
L_15
#endif
#ifdef F_32
L_16
#endif
#ifdef F_33
L_17
#endif
#ifdef F_34
L_18
#endif
) ;
F_15 ( L_19 , V_76 , V_77 ) ;
F_15 ( L_20 , V_78 ) ;
if ( ( (struct V_55 * ) V_9 -> V_56 ) -> V_79 & V_80 ) {
F_15 ( L_21 , V_81 ) ;
}
}
static void F_35 ( struct V_8 * V_9 )
{
F_36 ( V_82 , V_9 ) ;
F_37 ( V_82 , V_9 ) ;
}
static int T_5 F_38 ( struct V_8 * V_9 ,
char * V_3 , char * * V_83 , T_6 V_84 , int V_7 , int V_85 )
{
char * V_86 = V_3 ;
struct V_55 * V_56 ;
T_2 * V_5 ;
V_56 = (struct V_55 * ) V_9 -> V_56 ;
if ( V_85 ) {
#ifdef F_39
V_87 = V_88 = 0 ;
#endif
#ifdef F_40
V_89 = V_90 = 0 ;
#endif
return ( - V_91 ) ;
}
SPRINTF ( L_22 , V_78 ) ;
if ( ( (struct V_55 * ) V_9 -> V_56 ) -> V_79 & V_80 )
SPRINTF ( L_23 , V_81 ) ;
#ifdef F_39
SPRINTF ( L_24 , F_39 ) ;
#endif
#ifdef F_41
SPRINTF ( L_25 , F_41 ) ;
#endif
#ifdef F_42
SPRINTF ( L_26 , F_42 ) ;
#endif
#ifdef F_40
SPRINTF ( L_27 , F_40 ) ;
#endif
SPRINTF ( L_28 , ( long ) V_9 -> V_92 ) ;
SPRINTF ( L_29 , ( int ) V_9 -> V_93 ) ;
if ( V_9 -> V_60 == V_68 )
SPRINTF ( L_30 ) ;
else
SPRINTF ( L_31 , V_9 -> V_60 ) ;
#ifdef F_39
SPRINTF ( L_32 , V_87 , V_88 ) ;
#endif
#ifdef F_40
SPRINTF ( L_32 , V_89 , V_90 ) ;
#endif
F_43 ( V_9 -> V_94 ) ;
if ( ! V_56 -> V_95 )
SPRINTF ( L_33 , V_9 -> V_37 ) ;
else
V_86 = F_44 ( ( T_2 * ) V_56 -> V_95 , V_86 , V_3 , V_7 ) ;
SPRINTF ( L_34 , V_9 -> V_37 ) ;
for ( V_5 = ( T_2 * ) V_56 -> V_96 ; V_5 ; V_5 = ( T_2 * ) V_5 -> V_97 )
V_86 = F_44 ( V_5 , V_86 , V_3 , V_7 ) ;
SPRINTF ( L_35 , V_9 -> V_37 ) ;
for ( V_5 = ( T_2 * ) V_56 -> V_98 ; V_5 ; V_5 = ( T_2 * ) V_5 -> V_97 )
V_86 = F_44 ( V_5 , V_86 , V_3 , V_7 ) ;
F_45 ( V_9 -> V_94 ) ;
* V_83 = V_3 ;
if ( V_86 - V_3 < V_84 )
return 0 ;
else if ( V_86 - V_3 - V_84 < V_7 )
return V_86 - V_3 - V_84 ;
return V_7 ;
}
static char * F_44 ( T_2 * V_1 , char * V_86 , char * V_3 , int V_7 )
{
SPRINTF ( L_36 , V_1 -> V_99 -> V_100 -> V_37 , V_1 -> V_99 -> V_101 , V_1 -> V_99 -> V_102 ) ;
SPRINTF ( L_37 ) ;
V_86 = F_46 ( V_1 -> V_103 , V_86 , V_3 , V_7 ) ;
return ( V_86 ) ;
}
static char * F_46 ( unsigned char * V_104 , char * V_86 , char * V_3 , int V_7 )
{
int V_24 , V_105 ;
V_86 = F_47 ( V_104 [ 0 ] , V_86 , V_3 , V_7 ) ;
for ( V_24 = 1 , V_105 = F_48 ( V_104 [ 0 ] ) ; V_24 < V_105 ; ++ V_24 )
SPRINTF ( L_38 , V_104 [ V_24 ] ) ;
SPRINTF ( L_6 ) ;
return ( V_86 ) ;
}
static char * F_47 ( int V_106 , char * V_86 , char * V_3 , int V_7 )
{
SPRINTF ( L_39 , V_106 , V_106 ) ;
return ( V_86 ) ;
}
static int T_7 F_49 ( struct V_8 * V_9 , int V_79 )
{
F_7 () ;
int V_24 , V_107 ;
unsigned long V_57 ;
struct V_55 * V_56 = (struct V_55 * ) V_9 -> V_56 ;
if( F_12 () )
F_15 ( V_108 L_40 ) ;
#ifdef F_50
if ( V_79 & V_80 )
V_9 -> V_109 += V_110 ;
#endif
F_8 ( V_9 ) ;
V_56 -> V_111 = 0 ;
V_56 -> V_71 = 1 << V_9 -> V_112 ;
for ( V_24 = V_56 -> V_71 ; V_24 <= 0x80 ; V_24 <<= 1 )
if ( V_24 > V_56 -> V_71 )
V_56 -> V_113 |= V_24 ;
for ( V_24 = 0 ; V_24 < 8 ; ++ V_24 )
V_56 -> V_114 [ V_24 ] = 0 ;
#ifdef F_30
V_56 -> V_115 = 0 ;
#endif
V_56 -> V_116 = 0 ;
V_56 -> V_95 = NULL ;
V_56 -> V_96 = NULL ;
V_56 -> V_98 = NULL ;
F_51 ( & V_56 -> V_59 , V_117 ) ;
#ifdef F_52
for ( V_24 = 0 ; V_24 < 8 ; ++ V_24 ) {
V_56 -> V_118 [ V_24 ] = 0 ;
V_56 -> V_119 [ V_24 ] = 0 ;
V_56 -> V_120 [ V_24 ] = 0 ;
V_56 -> V_121 [ V_24 ] = 0 ;
}
V_56 -> V_122 = 0 ;
V_56 -> V_123 = 0 ;
V_56 -> V_124 = 0 ;
#endif
if ( V_79 & V_80 )
V_56 -> V_79 = V_125 | V_79 ;
else
V_56 -> V_79 = V_126 | V_79 ;
V_56 -> V_100 = V_9 ;
V_56 -> V_58 = 0 ;
#ifndef F_28
if ( ( V_9 -> V_127 > 1 ) || V_9 -> V_128 > 1 )
F_15 ( V_129 L_41 L_42
L_43 , V_9 -> V_37 ) ;
#endif
F_23 ( V_28 , V_73 ) ;
F_23 ( V_27 , V_130 ) ;
F_23 ( V_69 , 0 ) ;
F_23 ( V_70 , 0 ) ;
#ifdef F_50
if ( V_56 -> V_79 & V_80 ) {
F_23 ( V_131 , V_132 ) ;
}
#endif
for ( V_107 = 1 ; ( F_9 ( V_26 ) & V_133 ) && V_107 <= 6 ; ++ V_107 ) {
switch ( V_107 ) {
case 1 :
case 3 :
case 5 :
F_15 ( V_134 L_44 , V_9 -> V_37 ) ;
V_57 = V_16 + 5 * V_67 ;
F_6 ( V_9 , V_26 , V_133 , 0 , 5 * V_67 ) ;
break;
case 2 :
F_15 ( V_129 L_45 , V_9 -> V_37 ) ;
F_53 ( V_9 ) ;
break;
case 4 :
F_15 ( V_129 L_46 , V_9 -> V_37 ) ;
F_54 ( V_9 ) ;
break;
case 6 :
F_15 ( V_108 L_47 , V_9 -> V_37 ) ;
return - V_135 ;
}
}
return 0 ;
}
static void F_55 ( struct V_8 * V_9 )
{
struct V_55 * V_56 = (struct V_55 * ) V_9 -> V_56 ;
F_56 ( & V_56 -> V_59 ) ;
}
static int F_57 ( T_2 * V_1 , void (* F_58) ( T_2 * ) )
{
struct V_8 * V_9 = V_1 -> V_99 -> V_100 ;
struct V_55 * V_56 = (struct V_55 * ) V_9 -> V_56 ;
T_2 * V_136 ;
#if ( V_137 & V_138 )
switch ( V_1 -> V_103 [ 0 ] ) {
case V_43 :
case V_46 :
F_15 ( L_48 , V_9 -> V_37 ) ;
V_1 -> V_139 = ( V_140 << 16 ) ;
F_58 ( V_1 ) ;
return 0 ;
}
#endif
#ifdef F_52
switch ( V_1 -> V_103 [ 0 ] ) {
case V_141 :
case V_43 :
case V_46 :
V_56 -> V_119 [ V_1 -> V_99 -> V_101 ] -= ( V_16 - V_56 -> V_122 ) ;
V_56 -> V_121 [ V_1 -> V_99 -> V_101 ] += F_2 ( V_1 ) ;
V_56 -> V_123 ++ ;
break;
case V_142 :
case V_42 :
case V_45 :
V_56 -> V_118 [ V_1 -> V_99 -> V_101 ] -= ( V_16 - V_56 -> V_122 ) ;
V_56 -> V_120 [ V_1 -> V_99 -> V_101 ] += F_2 ( V_1 ) ;
V_56 -> V_124 ++ ;
break;
}
#endif
V_1 -> V_97 = NULL ;
V_1 -> V_143 = F_58 ;
V_1 -> V_139 = 0 ;
if ( ! ( V_56 -> V_96 ) || ( V_1 -> V_103 [ 0 ] == V_144 ) ) {
F_59 ( V_1 , V_56 -> V_96 ) ;
V_1 -> V_97 = ( unsigned char * ) V_56 -> V_96 ;
V_56 -> V_96 = V_1 ;
} else {
for ( V_136 = ( T_2 * ) V_56 -> V_96 ; V_136 -> V_97 ; V_136 = ( T_2 * ) V_136 -> V_97 ) ;
F_59 ( V_1 , V_136 ) ;
V_136 -> V_97 = ( unsigned char * ) V_1 ;
}
F_60 ( V_145 , ( L_49 , V_9 -> V_37 , ( V_1 -> V_103 [ 0 ] == V_144 ) ? L_50 : L_51 ) ) ;
F_19 ( & V_56 -> V_59 , 0 ) ;
return 0 ;
}
T_3 F_61 ( int V_146 , void * V_61 )
{
F_7 () ;
struct V_8 * V_9 = V_61 ;
struct V_55 * V_56 = (struct V_55 * ) V_9 -> V_56 ;
int F_58 ;
unsigned char V_21 ;
unsigned long V_79 ;
F_60 ( V_147 , ( L_52 ,
V_9 -> V_60 ) ) ;
do {
F_58 = 1 ;
F_62 ( V_9 -> V_94 , V_79 ) ;
F_8 ( V_9 ) ;
V_21 = F_9 ( V_29 ) ;
if ( V_21 & V_148 ) {
F_36 ( V_147 , V_9 ) ;
if ( ( F_9 ( V_26 ) & ( V_149 | V_150 ) ) == ( V_149 | V_150 ) ) {
F_58 = 0 ;
F_60 ( V_147 , ( L_53 , V_9 -> V_37 ) ) ;
F_63 ( V_9 ) ;
( void ) F_9 ( V_151 ) ;
} else if ( V_21 & V_152 ) {
F_60 ( V_147 , ( L_54 , V_9 -> V_37 ) ) ;
( void ) F_9 ( V_151 ) ;
} else if ( ( F_9 ( V_26 ) & V_153 ) == V_153 ) {
F_60 ( V_147 , ( L_55 , V_9 -> V_37 ) ) ;
( void ) F_9 ( V_151 ) ;
} else {
#if F_64 ( F_30 )
if ( ( F_9 ( V_27 ) & V_154 ) && ( ( V_21 & V_155 ) || ! ( V_21 & V_156 ) ) ) {
int V_157 ;
if ( ! V_56 -> V_95 )
F_65 ( L_56 , V_9 -> V_158 ) ;
V_157 = ( V_56 -> V_115 - F_66 ( V_9 ) ) ;
V_56 -> V_95 -> V_2 . V_6 -= V_157 ;
V_56 -> V_95 -> V_2 . V_5 += V_157 ;
V_56 -> V_115 = 0 ;
( void ) F_9 ( V_151 ) ;
F_6 ( V_56 , V_29 , V_159 , 0 , 2 * V_67 ) ;
F_23 ( V_27 , V_130 ) ;
F_23 ( V_28 , V_73 ) ;
}
#else
F_60 ( V_147 , ( L_57 , V_21 , F_9 ( V_27 ) , F_9 ( V_26 ) ) ) ;
( void ) F_9 ( V_151 ) ;
#endif
}
}
F_67 ( V_9 -> V_94 , V_79 ) ;
if( ! F_58 )
F_19 ( & V_56 -> V_59 , 0 ) ;
} while ( ! F_58 );
return V_63 ;
}
static void F_68 ( struct V_55 * V_56 , T_2 * V_1 )
{
#ifdef F_52
switch ( V_1 -> V_103 [ 0 ] ) {
case V_141 :
case V_43 :
case V_46 :
V_56 -> V_119 [ F_69 ( V_1 ) ] += ( V_16 - V_56 -> V_122 ) ;
V_56 -> V_123 -- ;
break;
case V_142 :
case V_42 :
case V_45 :
V_56 -> V_118 [ F_69 ( V_1 ) ] += ( V_16 - V_56 -> V_122 ) ;
V_56 -> V_124 -- ;
break;
}
#endif
}
static int F_70 ( struct V_8 * V_9 , T_2 * V_1 , int V_160 )
{
F_7 () ;
struct V_55 * V_56 = (struct V_55 * ) V_9 -> V_56 ;
unsigned char V_136 [ 3 ] , V_161 ;
unsigned char * V_20 ;
int V_162 ;
unsigned long V_57 ;
unsigned char V_39 ;
int V_163 ;
F_8 ( V_9 ) ;
if ( V_56 -> V_164 )
goto V_165;
V_56 -> V_166 = 0 ;
F_36 ( V_167 , V_9 ) ;
F_60 ( V_167 , ( L_58 , V_9 -> V_37 , V_9 -> V_112 ) ) ;
F_23 ( V_69 , 0 ) ;
F_23 ( V_72 , V_56 -> V_71 ) ;
F_23 ( V_27 , V_168 ) ;
F_45 ( V_9 -> V_94 ) ;
V_163 = F_6 ( V_9 , V_28 , V_169 , V_169 , 5 * V_67 ) ;
F_43 ( V_9 -> V_94 ) ;
if ( V_163 < 0 ) {
F_15 ( V_170 L_59 , __LINE__ ) ;
F_23 ( V_27 , V_130 ) ;
F_23 ( V_70 , V_56 -> V_71 ) ;
goto V_171;
}
F_60 ( V_167 , ( L_60 , V_9 -> V_37 ) ) ;
F_71 ( 3 ) ;
if ( ( F_9 ( V_28 ) & V_172 ) || ( F_9 ( V_25 ) & V_56 -> V_113 ) || ( F_9 ( V_28 ) & V_172 ) ) {
F_23 ( V_27 , V_130 ) ;
F_60 ( V_167 , ( L_61 , V_9 -> V_37 ) ) ;
goto V_171;
}
F_23 ( V_28 , V_73 | V_75 ) ;
if ( ! ( V_56 -> V_79 & V_173 ) &&
( F_9 ( V_28 ) & V_172 ) ) {
F_23 ( V_27 , V_130 ) ;
F_23 ( V_28 , V_73 ) ;
F_60 ( V_167 , ( L_62 , V_9 -> V_37 ) ) ;
goto V_171;
}
F_71 ( 2 ) ;
F_60 ( V_167 , ( L_63 , V_9 -> V_37 ) ) ;
F_23 ( V_72 , ( V_56 -> V_71 | ( 1 << F_69 ( V_1 ) ) ) ) ;
F_23 ( V_28 , ( V_73 | V_174 | V_74 | V_175 | V_75 ) ) ;
F_23 ( V_27 , V_130 ) ;
F_23 ( V_70 , 0 ) ;
F_71 ( 1 ) ;
F_23 ( V_28 , ( V_73 | V_74 | V_175 | V_75 ) ) ;
F_71 ( 1 ) ;
F_60 ( V_176 , ( L_64 , V_9 -> V_37 , F_69 ( V_1 ) ) ) ;
V_57 = V_16 + ( 250 * V_67 / 1000 ) ;
V_56 -> V_177 = 0 ;
V_56 -> V_164 = V_1 ;
V_165:
V_39 = F_9 ( V_26 ) & ( V_133 | V_150 ) ;
if ( ! V_39 && ( V_56 -> V_177 < V_67 / 4 ) ) {
V_56 -> V_177 ++ ;
F_18 ( V_56 , 1 ) ;
return 0 ;
}
V_56 -> V_164 = NULL ;
if ( ( F_9 ( V_26 ) & ( V_149 | V_150 ) ) == ( V_149 | V_150 ) ) {
F_23 ( V_28 , V_73 ) ;
F_63 ( V_9 ) ;
F_15 ( L_65 , V_9 -> V_37 ) ;
F_23 ( V_70 , V_56 -> V_71 ) ;
return - 1 ;
}
F_71 ( 1 ) ;
F_23 ( V_28 , V_73 | V_175 ) ;
if ( ! ( F_9 ( V_26 ) & V_133 ) ) {
F_23 ( V_28 , V_73 ) ;
if ( V_56 -> V_116 & ( 1 << F_69 ( V_1 ) ) ) {
F_15 ( V_170 L_66 , V_9 -> V_37 ) ;
if ( V_56 -> V_166 )
F_15 ( V_170 L_67 ) ;
F_36 ( V_176 , V_9 ) ;
F_23 ( V_70 , V_56 -> V_71 ) ;
return - 1 ;
}
V_1 -> V_139 = V_178 << 16 ;
F_68 ( V_56 , V_1 ) ;
V_1 -> V_143 ( V_1 ) ;
F_23 ( V_70 , V_56 -> V_71 ) ;
F_60 ( V_176 , ( L_68 , V_9 -> V_37 ) ) ;
F_23 ( V_70 , V_56 -> V_71 ) ;
return 0 ;
}
V_56 -> V_116 |= ( 1 << F_69 ( V_1 ) ) ;
F_45 ( V_9 -> V_94 ) ;
V_163 = F_6 ( V_9 , V_26 , V_36 , V_36 , V_67 ) ;
F_43 ( V_9 -> V_94 ) ;
if( V_163 ) {
F_15 ( V_108 L_69 , V_9 -> V_37 , __LINE__ ) ;
F_23 ( V_70 , V_56 -> V_71 ) ;
goto V_171;
}
F_60 ( V_176 , ( L_70 , V_9 -> V_37 , V_1 -> V_99 -> V_101 ) ) ;
V_136 [ 0 ] = F_72 ( ( ( V_9 -> V_60 == V_68 ) ? 0 : 1 ) , V_1 -> V_99 -> V_102 ) ;
V_162 = 1 ;
V_1 -> V_160 = 0 ;
V_20 = V_136 ;
V_161 = V_179 ;
F_73 ( V_9 , & V_161 , & V_162 , & V_20 ) ;
F_60 ( V_176 , ( L_71 , V_9 -> V_37 ) ) ;
V_56 -> V_95 = V_1 ;
V_56 -> V_114 [ V_1 -> V_99 -> V_101 ] |= ( 1 << V_1 -> V_99 -> V_102 ) ;
F_1 ( V_1 ) ;
return 0 ;
V_171:
return - 1 ;
}
static int F_73 ( struct V_8 * V_9 , unsigned char * V_161 , int * V_180 , unsigned char * * V_20 ) {
F_7 () ;
unsigned char V_181 = * V_161 , V_136 ;
int V_182 = * V_180 ;
unsigned char * V_183 = * V_20 ;
int V_184 = 0 ;
struct V_55 * V_56 = (struct V_55 * ) V_9 -> V_56 ;
F_8 ( V_9 ) ;
if ( ! ( V_181 & V_150 ) )
F_60 ( V_185 , ( L_72 , V_9 -> V_37 , V_182 ) ) ;
else
F_60 ( V_185 , ( L_73 , V_9 -> V_37 , V_182 ) ) ;
F_23 ( V_69 , F_74 ( V_181 ) ) ;
if ( ( V_181 == V_186 ) || ( V_181 == V_187 ) ) {
V_184 = 1 ;
}
do {
while ( ! ( ( V_136 = F_9 ( V_26 ) ) & V_36 ) && ! V_184 ) ;
if ( ! ( V_136 & V_36 ) ) {
F_18 ( V_56 , V_77 ) ;
break;
}
F_60 ( V_188 , ( L_74 , V_9 -> V_37 ) ) ;
if ( ( V_136 & V_41 ) != V_181 ) {
F_60 ( V_188 , ( L_75 , V_9 -> V_37 ) ) ;
F_37 ( V_188 , V_9 ) ;
break;
}
if ( ! ( V_181 & V_150 ) )
F_23 ( V_72 , * V_183 ) ;
else
* V_183 = F_9 ( V_25 ) ;
++ V_183 ;
if ( ! ( V_181 & V_150 ) ) {
if ( ! ( ( V_181 & V_189 ) && V_182 > 1 ) ) {
F_23 ( V_28 , V_73 | V_74 ) ;
F_36 ( V_185 , V_9 ) ;
F_23 ( V_28 , V_73 | V_74 | V_190 ) ;
} else {
F_23 ( V_28 , V_73 | V_74 | V_175 ) ;
F_36 ( V_185 , V_9 ) ;
F_23 ( V_28 , V_73 | V_74 | V_175 | V_190 ) ;
}
} else {
F_36 ( V_185 , V_9 ) ;
F_23 ( V_28 , V_73 | V_190 ) ;
}
F_6 ( V_9 , V_26 , V_36 , 0 , 5 * V_67 ) ;
F_60 ( V_188 , ( L_76 , V_9 -> V_37 ) ) ;
if ( ! ( V_181 == V_191 && V_182 == 1 ) ) {
if ( V_181 == V_179 && V_182 > 1 )
F_23 ( V_28 , V_73 | V_175 ) ;
else
F_23 ( V_28 , V_73 ) ;
}
} while ( -- V_182 );
F_60 ( V_185 , ( L_77 , V_9 -> V_37 , V_182 ) ) ;
* V_180 = V_182 ;
* V_20 = V_183 ;
V_136 = F_9 ( V_26 ) ;
if ( V_136 & V_36 )
* V_161 = V_136 & V_41 ;
else
* V_161 = V_40 ;
if ( ! V_182 || ( * V_161 == V_181 ) )
return 0 ;
else
return - 1 ;
}
static void F_54 ( struct V_8 * V_100 ) {
F_7 () ;
F_8 ( V_100 ) ;
F_23 ( V_69 , F_74 ( F_9 ( V_26 ) & V_41 ) ) ;
F_23 ( V_28 , V_73 | V_192 ) ;
F_71 ( 25 ) ;
F_23 ( V_28 , V_73 ) ;
}
static int F_53 ( struct V_8 * V_100 ) {
F_7 () ;
unsigned char * V_193 , V_161 , V_136 ;
int V_162 ;
int V_194 ;
F_8 ( V_100 ) ;
F_23 ( V_28 , V_73 | V_175 ) ;
V_194 = F_6 ( V_100 , V_26 , V_36 , V_36 , 60 * V_67 ) ;
if( V_194 < 0 )
return - 1 ;
V_136 = ( unsigned char ) V_194 ;
F_23 ( V_69 , F_74 ( V_136 ) ) ;
if ( ( V_136 & V_41 ) != V_179 ) {
F_23 ( V_28 , V_73 | V_175 | V_190 ) ;
V_194 = F_6 ( V_100 , V_26 , V_36 , 0 , 3 * V_67 ) ;
F_23 ( V_28 , V_73 | V_175 ) ;
if( V_194 == - 1 )
return - 1 ;
}
V_136 = ABORT ;
V_193 = & V_136 ;
V_162 = 1 ;
V_161 = V_179 ;
F_73 ( V_100 , & V_161 , & V_162 , & V_193 ) ;
return V_162 ? - 1 : 0 ;
}
static int F_75 ( struct V_8 * V_9 , unsigned char * V_161 , int * V_180 , unsigned char * * V_20 ) {
F_7 () ;
register int V_182 = * V_180 ;
register unsigned char V_181 = * V_161 ;
register unsigned char * V_183 = * V_20 ;
unsigned char V_136 ;
int V_195 ;
#if F_64 ( F_31 )
int V_196 , V_197 ;
unsigned char V_198 = 0 , V_199 = 0 , V_200 ;
#endif
struct V_55 * V_56 = (struct V_55 * ) V_9 -> V_56 ;
F_8 ( V_9 ) ;
if ( ( V_136 = ( F_9 ( V_26 ) & V_41 ) ) != V_181 ) {
* V_161 = V_136 ;
return - 1 ;
}
#if F_64 ( F_30 ) || F_64 ( F_31 )
#ifdef F_76
if ( V_181 & V_150 ) {
V_182 -= 2 ;
}
#endif
F_60 ( V_201 , ( L_78 , V_9 -> V_37 , V_9 -> V_202 , ( V_181 & V_150 ) ? L_79 : L_80 , V_182 , ( V_181 & V_150 ) ? L_81 : L_82 , ( unsigned ) V_183 ) ) ;
V_56 -> V_203 = ( V_181 & V_150 ) ? F_77 ( V_9 , V_183 , V_182 ) : F_78 ( V_9 , V_183 , V_182 ) ;
#endif
F_23 ( V_69 , F_74 ( V_181 ) ) ;
#ifdef F_30
F_23 ( V_27 , V_130 | V_204 | V_205 | V_206 ) ;
#elif F_64 ( F_31 )
F_23 ( V_27 , V_130 | V_204 ) ;
#else
#if F_64 ( F_33 ) && F_64 ( F_34 )
F_45 ( V_9 -> V_94 ) ;
#endif
if ( V_56 -> V_79 & V_80 )
F_23 ( V_27 , V_130 | V_204 |
V_207 | V_208 |
V_205 | V_206 ) ;
else
F_23 ( V_27 , V_130 | V_204 ) ;
#endif
F_60 ( V_201 , ( L_83 , V_9 -> V_37 , F_9 ( V_27 ) ) ) ;
if ( V_181 & V_150 ) {
F_79 ( 1 ) ;
F_23 ( V_209 , 0 ) ;
} else {
F_79 ( 1 ) ;
F_23 ( V_28 , V_73 | V_74 ) ;
F_79 ( 1 ) ;
F_23 ( V_210 , 0 ) ;
F_79 ( 1 ) ;
}
#if F_64 ( F_31 )
do {
V_136 = F_9 ( V_29 ) ;
} while ( ( V_136 & V_156 ) && ! ( V_136 & ( V_211 | V_155 ) ) );
if ( V_181 & V_150 ) {
#ifdef F_76
F_71 ( 10 ) ;
if ( ( ( F_9 ( V_29 ) & ( V_156 | V_159 ) ) == ( V_156 | V_159 ) ) ) {
V_198 = F_9 ( V_212 ) ;
V_199 = 1 ;
}
#endif
} else {
int V_213 = 100 ;
while ( ( ( V_136 = F_9 ( V_29 ) ) & V_159 ) || ( F_9 ( V_26 ) & V_36 ) ) {
if ( ! ( V_136 & V_156 ) )
break;
if ( -- V_213 < 0 )
break;
}
}
F_60 ( V_201 , ( L_84 , V_9 -> V_37 , V_136 , F_9 ( V_26 ) ) ) ;
F_23 ( V_27 , V_130 ) ;
F_23 ( V_28 , V_73 ) ;
V_200 = F_66 ( V_9 ) ;
V_182 -= V_200 ;
* V_180 -= V_182 ;
* V_20 += V_182 ;
* V_161 = F_9 ( V_26 ) & V_41 ;
#ifdef F_76
if ( * V_161 == V_181 && ( V_181 & V_150 ) && V_200 == 0 ) {
if ( V_199 ) {
F_60 ( V_201 , ( L_85 ) ) ;
* * V_20 = V_198 ;
* V_20 += 1 ;
* V_180 -= 1 ;
V_196 = V_197 = 1 ;
} else {
F_15 ( L_86 ) ;
V_196 = V_197 = 2 ;
}
F_60 ( V_201 , ( L_87 , V_196 , * V_20 ) ) ;
F_73 ( V_9 , V_161 , & V_196 , V_20 ) ;
* V_180 -= V_197 - V_196 ;
}
#endif
F_60 ( V_201 , ( L_88 , * V_20 , * V_180 , * ( * V_20 + * V_180 - 1 ) , * ( * V_20 + * V_180 ) ) ) ;
return 0 ;
#elif F_64 ( F_30 )
return 0 ;
#else
if ( V_181 & V_150 ) {
#ifdef F_80
V_195 = F_81 ( V_9 , V_183 , V_182 ) ;
#else
int V_214 = 1 ;
if ( V_56 -> V_79 & V_80 ) {
V_214 = 0 ;
}
if ( ! ( V_195 = F_81 ( V_9 , V_183 , V_182 - V_214 ) ) ) {
if ( ! ( V_56 -> V_79 & V_80 ) ) {
while ( ! ( F_9 ( V_29 ) & V_215 ) ) ;
while ( F_9 ( V_26 ) & V_36 ) ;
V_183 [ V_182 - 1 ] = F_9 ( V_216 ) ;
}
}
#endif
} else {
#ifdef F_80
V_195 = F_82 ( V_9 , V_183 , V_182 ) ;
#else
int V_57 ;
F_60 ( V_217 , ( L_89 , V_182 ) ) ;
if ( ! ( V_195 = F_82 ( V_9 , V_183 , V_182 ) ) ) {
if ( ! ( V_56 -> V_79 & V_125 ) ) {
V_57 = 20000 ;
while ( ! ( F_9 ( V_29 ) & V_215 ) && ( F_9 ( V_29 ) & V_156 ) ) ;
if ( ! V_57 )
F_60 ( V_218 , ( L_90 , V_9 -> V_37 ) ) ;
if ( V_56 -> V_79 & V_126 ) {
V_56 -> V_79 &= ~ V_126 ;
if ( F_9 ( V_69 ) & V_219 ) {
V_56 -> V_79 |= V_125 ;
F_60 ( V_220 , ( L_91 , V_9 -> V_37 ) ) ;
}
}
} else {
F_60 ( V_217 , ( L_92 ) ) ;
while ( ! ( F_9 ( V_69 ) & V_219 ) ) ;
F_60 ( V_217 , ( L_93 ) ) ;
}
}
#endif
}
F_23 ( V_27 , V_130 ) ;
F_23 ( V_28 , V_73 ) ;
if ( ( ! ( V_181 & V_150 ) ) && ( V_56 -> V_79 & V_80 ) ) {
F_60 ( V_217 , ( L_94 ) ) ;
if ( F_9 ( V_29 ) & V_148 ) {
F_60 ( V_217 , ( L_95 ) ) ;
F_9 ( V_151 ) ;
} else {
F_15 ( L_96 ) ;
}
}
* V_20 = V_183 + V_182 ;
* V_180 = 0 ;
* V_161 = F_9 ( V_26 ) & V_41 ;
#if F_64 ( F_33 ) && F_64 ( F_34 )
F_43 ( V_9 -> V_94 ) ;
#endif
return V_195 ;
#endif
}
static void F_63 ( struct V_8 * V_9 ) {
F_7 () ;
struct V_55 * V_56 = (struct V_55 * )
V_9 -> V_56 ;
unsigned char V_221 ;
unsigned char V_102 , V_161 ;
int V_162 ;
unsigned char V_222 [ 3 ] ;
unsigned char * V_20 ;
T_2 * V_136 = NULL , * V_223 ;
int abort = 0 ;
F_8 ( V_9 ) ;
F_23 ( V_27 , V_130 ) ;
V_56 -> V_166 = 1 ;
V_221 = F_9 ( V_25 ) & ~ ( V_56 -> V_71 ) ;
F_60 ( V_176 , ( L_97 , V_9 -> V_37 ) ) ;
F_23 ( V_28 , V_73 | V_174 ) ;
if( F_6 ( V_9 , V_26 , V_149 , 0 , 2 * V_67 ) < 0 )
abort = 1 ;
F_23 ( V_28 , V_73 ) ;
if( F_6 ( V_9 , V_26 , V_36 , V_36 , 2 * V_67 ) )
abort = 1 ;
V_162 = 1 ;
V_20 = V_222 ;
V_161 = V_191 ;
F_73 ( V_9 , & V_161 , & V_162 , & V_20 ) ;
if ( ! ( V_222 [ 0 ] & 0x80 ) ) {
F_15 ( V_108 L_98 , V_9 -> V_37 ) ;
F_83 ( V_222 ) ;
abort = 1 ;
} else {
F_23 ( V_28 , V_73 ) ;
V_102 = ( V_222 [ 0 ] & 0x07 ) ;
for ( V_136 = ( T_2 * ) V_56 -> V_98 , V_223 = NULL ; V_136 ; V_223 = V_136 , V_136 = ( T_2 * ) V_136 -> V_97 )
if ( ( V_221 == ( 1 << V_136 -> V_99 -> V_101 ) ) && ( V_102 == V_136 -> V_99 -> V_102 )
) {
if ( V_223 ) {
REMOVE ( V_223 , V_223 -> V_97 , V_136 , V_136 -> V_97 ) ;
V_223 -> V_97 = V_136 -> V_97 ;
} else {
REMOVE ( - 1 , V_56 -> V_98 , V_136 , V_136 -> V_97 ) ;
V_56 -> V_98 = ( T_2 * ) V_136 -> V_97 ;
}
V_136 -> V_97 = NULL ;
break;
}
if ( ! V_136 ) {
F_15 ( V_108 L_99 , V_9 -> V_37 , V_221 , V_102 ) ;
abort = 1 ;
}
}
if ( abort ) {
F_53 ( V_9 ) ;
} else {
V_56 -> V_95 = V_136 ;
F_60 ( V_224 , ( L_100 , V_9 -> V_37 , V_136 -> V_225 , V_136 -> V_102 , V_136 -> V_160 ) ) ;
}
}
static void F_84 ( T_8 * V_9 ) {
F_7 () ;
struct V_55 * V_56 = (struct V_55 * ) V_9 -> V_56 ;
int V_157 ;
F_8 ( V_9 ) ;
F_6 ( V_9 , V_29 , V_159 , 0 , 5 * V_67 ) ;
F_23 ( V_27 , V_130 ) ;
F_23 ( V_28 , V_73 ) ;
if ( ! ( V_56 -> V_95 -> V_2 . V_161 & V_226 ) ) {
V_157 = V_9 -> V_115 - F_66 () ;
V_56 -> V_95 -> V_2 . V_6 -= V_157 ;
V_56 -> V_95 -> V_2 . V_5 += V_157 ;
}
}
static int F_85 ( T_2 * V_1 ) {
F_7 () ;
struct V_8 * V_9 = V_1 -> V_99 -> V_100 ;
struct V_55 * V_56 = (struct V_55 * ) V_9 -> V_56 ;
T_2 * V_136 , * * V_223 ;
F_15 ( V_129 L_101 , V_9 -> V_37 ) ;
F_86 ( V_1 ) ;
F_35 ( V_9 ) ;
F_8 ( V_9 ) ;
F_60 ( V_227 , ( L_102 , V_9 -> V_37 ) ) ;
F_60 ( V_227 , ( L_103 , F_9 ( V_29 ) , F_9 ( V_26 ) ) ) ;
#if 0
if (hostdata->connected == cmd) {
dprintk(NDEBUG_ABORT, ("scsi%d : aborting connected command\n", instance->host_no));
hostdata->aborted = 1;
NCR5380_write(INITIATOR_COMMAND_REG, ICR_ASSERT_ATN);
return 0;
}
#endif
F_60 ( V_227 , ( L_104 , V_9 -> V_37 ) ) ;
for ( V_223 = ( T_2 * * ) & ( V_56 -> V_96 ) , V_136 = ( T_2 * ) V_56 -> V_96 ; V_136 ; V_223 = ( T_2 * * ) & ( V_136 -> V_97 ) , V_136 = ( T_2 * ) V_136 -> V_97 )
if ( V_1 == V_136 ) {
REMOVE ( 5 , * V_223 , V_136 , V_136 -> V_97 ) ;
( * V_223 ) = ( T_2 * ) V_136 -> V_97 ;
V_136 -> V_97 = NULL ;
V_136 -> V_139 = V_228 << 16 ;
F_60 ( V_227 , ( L_105 , V_9 -> V_37 ) ) ;
V_136 -> V_143 ( V_136 ) ;
return V_229 ;
}
#if ( V_137 & V_227 )
else if ( V_223 == V_136 )
F_15 ( V_108 L_106 , V_9 -> V_37 ) ;
#endif
if ( V_56 -> V_95 ) {
F_60 ( V_227 , ( L_107 , V_9 -> V_37 ) ) ;
return V_230 ;
}
for ( V_136 = ( T_2 * ) V_56 -> V_98 ; V_136 ; V_136 = ( T_2 * ) V_136 -> V_97 )
if ( V_1 == V_136 ) {
F_60 ( V_227 , ( L_108 , V_9 -> V_37 ) ) ;
if ( F_70 ( V_9 , V_1 , ( int ) V_1 -> V_160 ) )
return V_230 ;
F_60 ( V_227 , ( L_109 , V_9 -> V_37 ) ) ;
F_53 ( V_9 ) ;
for ( V_223 = ( T_2 * * ) & ( V_56 -> V_98 ) , V_136 = ( T_2 * ) V_56 -> V_98 ; V_136 ; V_223 = ( T_2 * * ) & ( V_136 -> V_97 ) , V_136 = ( T_2 * ) V_136 -> V_97 )
if ( V_1 == V_136 ) {
REMOVE ( 5 , * V_223 , V_136 , V_136 -> V_97 ) ;
* V_223 = ( T_2 * ) V_136 -> V_97 ;
V_136 -> V_97 = NULL ;
V_136 -> V_139 = V_228 << 16 ;
V_136 -> V_143 ( V_136 ) ;
return V_229 ;
}
}
F_15 ( V_129 L_110
L_111 , V_9 -> V_37 ) ;
return V_230 ;
}
static int F_87 ( T_2 * V_1 )
{
struct V_8 * V_9 = V_1 -> V_99 -> V_100 ;
F_7 () ;
F_8 ( V_9 ) ;
F_35 ( V_9 ) ;
F_43 ( V_9 -> V_94 ) ;
F_54 ( V_9 ) ;
F_45 ( V_9 -> V_94 ) ;
return V_229 ;
}
