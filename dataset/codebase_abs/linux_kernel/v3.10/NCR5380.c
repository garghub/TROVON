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
char * V_3 , int V_7 )
{
#ifdef F_39
V_83 = V_84 = 0 ;
#endif
#ifdef F_40
V_85 = V_86 = 0 ;
#endif
return ( - V_87 ) ;
}
static int T_5 F_41 ( struct V_88 * V_89 ,
struct V_8 * V_9 )
{
struct V_55 * V_56 ;
T_2 * V_5 ;
V_56 = (struct V_55 * ) V_9 -> V_56 ;
SPRINTF ( L_22 , V_78 ) ;
if ( ( (struct V_55 * ) V_9 -> V_56 ) -> V_79 & V_80 )
SPRINTF ( L_23 , V_81 ) ;
#ifdef F_39
SPRINTF ( L_24 , F_39 ) ;
#endif
#ifdef F_42
SPRINTF ( L_25 , F_42 ) ;
#endif
#ifdef F_43
SPRINTF ( L_26 , F_43 ) ;
#endif
#ifdef F_40
SPRINTF ( L_27 , F_40 ) ;
#endif
SPRINTF ( L_28 , ( long ) V_9 -> V_90 ) ;
SPRINTF ( L_29 , ( int ) V_9 -> V_91 ) ;
if ( V_9 -> V_60 == V_68 )
SPRINTF ( L_30 ) ;
else
SPRINTF ( L_31 , V_9 -> V_60 ) ;
#ifdef F_39
SPRINTF ( L_32 , V_83 , V_84 ) ;
#endif
#ifdef F_40
SPRINTF ( L_32 , V_85 , V_86 ) ;
#endif
F_44 ( V_9 -> V_92 ) ;
if ( ! V_56 -> V_93 )
SPRINTF ( L_33 , V_9 -> V_37 ) ;
else
F_45 ( ( T_2 * ) V_56 -> V_93 , V_89 ) ;
SPRINTF ( L_34 , V_9 -> V_37 ) ;
for ( V_5 = ( T_2 * ) V_56 -> V_94 ; V_5 ; V_5 = ( T_2 * ) V_5 -> V_95 )
F_45 ( V_5 , V_89 ) ;
SPRINTF ( L_35 , V_9 -> V_37 ) ;
for ( V_5 = ( T_2 * ) V_56 -> V_96 ; V_5 ; V_5 = ( T_2 * ) V_5 -> V_95 )
F_45 ( V_5 , V_89 ) ;
F_46 ( V_9 -> V_92 ) ;
return 0 ;
}
static void F_45 ( T_2 * V_1 , struct V_88 * V_89 )
{
SPRINTF ( L_36 , V_1 -> V_97 -> V_98 -> V_37 , V_1 -> V_97 -> V_99 , V_1 -> V_97 -> V_100 ) ;
SPRINTF ( L_37 ) ;
F_47 ( V_1 -> V_101 , V_89 ) ;
}
static void F_47 ( unsigned char * V_102 , struct V_88 * V_89 )
{
int V_24 , V_103 ;
F_48 ( V_102 [ 0 ] , V_89 ) ;
for ( V_24 = 1 , V_103 = F_49 ( V_102 [ 0 ] ) ; V_24 < V_103 ; ++ V_24 )
SPRINTF ( L_38 , V_102 [ V_24 ] ) ;
SPRINTF ( L_6 ) ;
}
static void F_48 ( int V_104 , struct V_88 * V_89 )
{
SPRINTF ( L_39 , V_104 , V_104 ) ;
}
static int F_50 ( struct V_8 * V_9 , int V_79 )
{
F_7 () ;
int V_24 , V_105 ;
unsigned long V_57 ;
struct V_55 * V_56 = (struct V_55 * ) V_9 -> V_56 ;
if( F_12 () )
F_15 ( V_106 L_40 ) ;
#ifdef F_51
if ( V_79 & V_80 )
V_9 -> V_107 += V_108 ;
#endif
F_8 ( V_9 ) ;
V_56 -> V_109 = 0 ;
V_56 -> V_71 = 1 << V_9 -> V_110 ;
for ( V_24 = V_56 -> V_71 ; V_24 <= 0x80 ; V_24 <<= 1 )
if ( V_24 > V_56 -> V_71 )
V_56 -> V_111 |= V_24 ;
for ( V_24 = 0 ; V_24 < 8 ; ++ V_24 )
V_56 -> V_112 [ V_24 ] = 0 ;
#ifdef F_30
V_56 -> V_113 = 0 ;
#endif
V_56 -> V_114 = 0 ;
V_56 -> V_93 = NULL ;
V_56 -> V_94 = NULL ;
V_56 -> V_96 = NULL ;
F_52 ( & V_56 -> V_59 , V_115 ) ;
#ifdef F_53
for ( V_24 = 0 ; V_24 < 8 ; ++ V_24 ) {
V_56 -> V_116 [ V_24 ] = 0 ;
V_56 -> V_117 [ V_24 ] = 0 ;
V_56 -> V_118 [ V_24 ] = 0 ;
V_56 -> V_119 [ V_24 ] = 0 ;
}
V_56 -> V_120 = 0 ;
V_56 -> V_121 = 0 ;
V_56 -> V_122 = 0 ;
#endif
if ( V_79 & V_80 )
V_56 -> V_79 = V_123 | V_79 ;
else
V_56 -> V_79 = V_124 | V_79 ;
V_56 -> V_98 = V_9 ;
V_56 -> V_58 = 0 ;
#ifndef F_28
if ( ( V_9 -> V_125 > 1 ) || V_9 -> V_126 > 1 )
F_15 ( V_127 L_41 L_42
L_43 , V_9 -> V_37 ) ;
#endif
F_23 ( V_28 , V_73 ) ;
F_23 ( V_27 , V_128 ) ;
F_23 ( V_69 , 0 ) ;
F_23 ( V_70 , 0 ) ;
#ifdef F_51
if ( V_56 -> V_79 & V_80 ) {
F_23 ( V_129 , V_130 ) ;
}
#endif
for ( V_105 = 1 ; ( F_9 ( V_26 ) & V_131 ) && V_105 <= 6 ; ++ V_105 ) {
switch ( V_105 ) {
case 1 :
case 3 :
case 5 :
F_15 ( V_132 L_44 , V_9 -> V_37 ) ;
V_57 = V_16 + 5 * V_67 ;
F_6 ( V_9 , V_26 , V_131 , 0 , 5 * V_67 ) ;
break;
case 2 :
F_15 ( V_127 L_45 , V_9 -> V_37 ) ;
F_54 ( V_9 ) ;
break;
case 4 :
F_15 ( V_127 L_46 , V_9 -> V_37 ) ;
F_55 ( V_9 ) ;
break;
case 6 :
F_15 ( V_106 L_47 , V_9 -> V_37 ) ;
return - V_133 ;
}
}
return 0 ;
}
static void F_56 ( struct V_8 * V_9 )
{
struct V_55 * V_56 = (struct V_55 * ) V_9 -> V_56 ;
F_57 ( & V_56 -> V_59 ) ;
}
static int F_58 ( T_2 * V_1 , void (* F_59) ( T_2 * ) )
{
struct V_8 * V_9 = V_1 -> V_97 -> V_98 ;
struct V_55 * V_56 = (struct V_55 * ) V_9 -> V_56 ;
T_2 * V_134 ;
#if ( V_135 & V_136 )
switch ( V_1 -> V_101 [ 0 ] ) {
case V_43 :
case V_46 :
F_15 ( L_48 , V_9 -> V_37 ) ;
V_1 -> V_137 = ( V_138 << 16 ) ;
F_59 ( V_1 ) ;
return 0 ;
}
#endif
#ifdef F_53
switch ( V_1 -> V_101 [ 0 ] ) {
case V_139 :
case V_43 :
case V_46 :
V_56 -> V_117 [ V_1 -> V_97 -> V_99 ] -= ( V_16 - V_56 -> V_120 ) ;
V_56 -> V_119 [ V_1 -> V_97 -> V_99 ] += F_2 ( V_1 ) ;
V_56 -> V_121 ++ ;
break;
case V_140 :
case V_42 :
case V_45 :
V_56 -> V_116 [ V_1 -> V_97 -> V_99 ] -= ( V_16 - V_56 -> V_120 ) ;
V_56 -> V_118 [ V_1 -> V_97 -> V_99 ] += F_2 ( V_1 ) ;
V_56 -> V_122 ++ ;
break;
}
#endif
V_1 -> V_95 = NULL ;
V_1 -> V_141 = F_59 ;
V_1 -> V_137 = 0 ;
if ( ! ( V_56 -> V_94 ) || ( V_1 -> V_101 [ 0 ] == V_142 ) ) {
F_60 ( V_1 , V_56 -> V_94 ) ;
V_1 -> V_95 = ( unsigned char * ) V_56 -> V_94 ;
V_56 -> V_94 = V_1 ;
} else {
for ( V_134 = ( T_2 * ) V_56 -> V_94 ; V_134 -> V_95 ; V_134 = ( T_2 * ) V_134 -> V_95 ) ;
F_60 ( V_1 , V_134 ) ;
V_134 -> V_95 = ( unsigned char * ) V_1 ;
}
F_61 ( V_143 , ( L_49 , V_9 -> V_37 , ( V_1 -> V_101 [ 0 ] == V_142 ) ? L_50 : L_51 ) ) ;
F_19 ( & V_56 -> V_59 , 0 ) ;
return 0 ;
}
T_3 F_62 ( int V_144 , void * V_61 )
{
F_7 () ;
struct V_8 * V_9 = V_61 ;
struct V_55 * V_56 = (struct V_55 * ) V_9 -> V_56 ;
int F_59 ;
unsigned char V_21 ;
unsigned long V_79 ;
F_61 ( V_145 , ( L_52 ,
V_9 -> V_60 ) ) ;
do {
F_59 = 1 ;
F_63 ( V_9 -> V_92 , V_79 ) ;
F_8 ( V_9 ) ;
V_21 = F_9 ( V_29 ) ;
if ( V_21 & V_146 ) {
F_36 ( V_145 , V_9 ) ;
if ( ( F_9 ( V_26 ) & ( V_147 | V_148 ) ) == ( V_147 | V_148 ) ) {
F_59 = 0 ;
F_61 ( V_145 , ( L_53 , V_9 -> V_37 ) ) ;
F_64 ( V_9 ) ;
( void ) F_9 ( V_149 ) ;
} else if ( V_21 & V_150 ) {
F_61 ( V_145 , ( L_54 , V_9 -> V_37 ) ) ;
( void ) F_9 ( V_149 ) ;
} else if ( ( F_9 ( V_26 ) & V_151 ) == V_151 ) {
F_61 ( V_145 , ( L_55 , V_9 -> V_37 ) ) ;
( void ) F_9 ( V_149 ) ;
} else {
#if F_65 ( F_30 )
if ( ( F_9 ( V_27 ) & V_152 ) && ( ( V_21 & V_153 ) || ! ( V_21 & V_154 ) ) ) {
int V_155 ;
if ( ! V_56 -> V_93 )
F_66 ( L_56 , V_9 -> V_156 ) ;
V_155 = ( V_56 -> V_113 - F_67 ( V_9 ) ) ;
V_56 -> V_93 -> V_2 . V_6 -= V_155 ;
V_56 -> V_93 -> V_2 . V_5 += V_155 ;
V_56 -> V_113 = 0 ;
( void ) F_9 ( V_149 ) ;
F_6 ( V_56 , V_29 , V_157 , 0 , 2 * V_67 ) ;
F_23 ( V_27 , V_128 ) ;
F_23 ( V_28 , V_73 ) ;
}
#else
F_61 ( V_145 , ( L_57 , V_21 , F_9 ( V_27 ) , F_9 ( V_26 ) ) ) ;
( void ) F_9 ( V_149 ) ;
#endif
}
}
F_68 ( V_9 -> V_92 , V_79 ) ;
if( ! F_59 )
F_19 ( & V_56 -> V_59 , 0 ) ;
} while ( ! F_59 );
return V_63 ;
}
static void F_69 ( struct V_55 * V_56 , T_2 * V_1 )
{
#ifdef F_53
switch ( V_1 -> V_101 [ 0 ] ) {
case V_139 :
case V_43 :
case V_46 :
V_56 -> V_117 [ F_70 ( V_1 ) ] += ( V_16 - V_56 -> V_120 ) ;
V_56 -> V_121 -- ;
break;
case V_140 :
case V_42 :
case V_45 :
V_56 -> V_116 [ F_70 ( V_1 ) ] += ( V_16 - V_56 -> V_120 ) ;
V_56 -> V_122 -- ;
break;
}
#endif
}
static int F_71 ( struct V_8 * V_9 , T_2 * V_1 , int V_158 )
{
F_7 () ;
struct V_55 * V_56 = (struct V_55 * ) V_9 -> V_56 ;
unsigned char V_134 [ 3 ] , V_159 ;
unsigned char * V_20 ;
int V_160 ;
unsigned long V_57 ;
unsigned char V_39 ;
int V_161 ;
F_8 ( V_9 ) ;
if ( V_56 -> V_162 )
goto V_163;
V_56 -> V_164 = 0 ;
F_36 ( V_165 , V_9 ) ;
F_61 ( V_165 , ( L_58 , V_9 -> V_37 , V_9 -> V_110 ) ) ;
F_23 ( V_69 , 0 ) ;
F_23 ( V_72 , V_56 -> V_71 ) ;
F_23 ( V_27 , V_166 ) ;
F_46 ( V_9 -> V_92 ) ;
V_161 = F_6 ( V_9 , V_28 , V_167 , V_167 , 5 * V_67 ) ;
F_44 ( V_9 -> V_92 ) ;
if ( V_161 < 0 ) {
F_15 ( V_168 L_59 , __LINE__ ) ;
F_23 ( V_27 , V_128 ) ;
F_23 ( V_70 , V_56 -> V_71 ) ;
goto V_169;
}
F_61 ( V_165 , ( L_60 , V_9 -> V_37 ) ) ;
F_72 ( 3 ) ;
if ( ( F_9 ( V_28 ) & V_170 ) || ( F_9 ( V_25 ) & V_56 -> V_111 ) || ( F_9 ( V_28 ) & V_170 ) ) {
F_23 ( V_27 , V_128 ) ;
F_61 ( V_165 , ( L_61 , V_9 -> V_37 ) ) ;
goto V_169;
}
F_23 ( V_28 , V_73 | V_75 ) ;
if ( ! ( V_56 -> V_79 & V_171 ) &&
( F_9 ( V_28 ) & V_170 ) ) {
F_23 ( V_27 , V_128 ) ;
F_23 ( V_28 , V_73 ) ;
F_61 ( V_165 , ( L_62 , V_9 -> V_37 ) ) ;
goto V_169;
}
F_72 ( 2 ) ;
F_61 ( V_165 , ( L_63 , V_9 -> V_37 ) ) ;
F_23 ( V_72 , ( V_56 -> V_71 | ( 1 << F_70 ( V_1 ) ) ) ) ;
F_23 ( V_28 , ( V_73 | V_172 | V_74 | V_173 | V_75 ) ) ;
F_23 ( V_27 , V_128 ) ;
F_23 ( V_70 , 0 ) ;
F_72 ( 1 ) ;
F_23 ( V_28 , ( V_73 | V_74 | V_173 | V_75 ) ) ;
F_72 ( 1 ) ;
F_61 ( V_174 , ( L_64 , V_9 -> V_37 , F_70 ( V_1 ) ) ) ;
V_57 = V_16 + ( 250 * V_67 / 1000 ) ;
V_56 -> V_175 = 0 ;
V_56 -> V_162 = V_1 ;
V_163:
V_39 = F_9 ( V_26 ) & ( V_131 | V_148 ) ;
if ( ! V_39 && ( V_56 -> V_175 < V_67 / 4 ) ) {
V_56 -> V_175 ++ ;
F_18 ( V_56 , 1 ) ;
return 0 ;
}
V_56 -> V_162 = NULL ;
if ( ( F_9 ( V_26 ) & ( V_147 | V_148 ) ) == ( V_147 | V_148 ) ) {
F_23 ( V_28 , V_73 ) ;
F_64 ( V_9 ) ;
F_15 ( L_65 , V_9 -> V_37 ) ;
F_23 ( V_70 , V_56 -> V_71 ) ;
return - 1 ;
}
F_72 ( 1 ) ;
F_23 ( V_28 , V_73 | V_173 ) ;
if ( ! ( F_9 ( V_26 ) & V_131 ) ) {
F_23 ( V_28 , V_73 ) ;
if ( V_56 -> V_114 & ( 1 << F_70 ( V_1 ) ) ) {
F_15 ( V_168 L_66 , V_9 -> V_37 ) ;
if ( V_56 -> V_164 )
F_15 ( V_168 L_67 ) ;
F_36 ( V_174 , V_9 ) ;
F_23 ( V_70 , V_56 -> V_71 ) ;
return - 1 ;
}
V_1 -> V_137 = V_176 << 16 ;
F_69 ( V_56 , V_1 ) ;
V_1 -> V_141 ( V_1 ) ;
F_23 ( V_70 , V_56 -> V_71 ) ;
F_61 ( V_174 , ( L_68 , V_9 -> V_37 ) ) ;
F_23 ( V_70 , V_56 -> V_71 ) ;
return 0 ;
}
V_56 -> V_114 |= ( 1 << F_70 ( V_1 ) ) ;
F_46 ( V_9 -> V_92 ) ;
V_161 = F_6 ( V_9 , V_26 , V_36 , V_36 , V_67 ) ;
F_44 ( V_9 -> V_92 ) ;
if( V_161 ) {
F_15 ( V_106 L_69 , V_9 -> V_37 , __LINE__ ) ;
F_23 ( V_70 , V_56 -> V_71 ) ;
goto V_169;
}
F_61 ( V_174 , ( L_70 , V_9 -> V_37 , V_1 -> V_97 -> V_99 ) ) ;
V_134 [ 0 ] = F_73 ( ( ( V_9 -> V_60 == V_68 ) ? 0 : 1 ) , V_1 -> V_97 -> V_100 ) ;
V_160 = 1 ;
V_1 -> V_158 = 0 ;
V_20 = V_134 ;
V_159 = V_177 ;
F_74 ( V_9 , & V_159 , & V_160 , & V_20 ) ;
F_61 ( V_174 , ( L_71 , V_9 -> V_37 ) ) ;
V_56 -> V_93 = V_1 ;
V_56 -> V_112 [ V_1 -> V_97 -> V_99 ] |= ( 1 << V_1 -> V_97 -> V_100 ) ;
F_1 ( V_1 ) ;
return 0 ;
V_169:
return - 1 ;
}
static int F_74 ( struct V_8 * V_9 , unsigned char * V_159 , int * V_178 , unsigned char * * V_20 ) {
F_7 () ;
unsigned char V_179 = * V_159 , V_134 ;
int V_180 = * V_178 ;
unsigned char * V_181 = * V_20 ;
int V_182 = 0 ;
struct V_55 * V_56 = (struct V_55 * ) V_9 -> V_56 ;
F_8 ( V_9 ) ;
if ( ! ( V_179 & V_148 ) )
F_61 ( V_183 , ( L_72 , V_9 -> V_37 , V_180 ) ) ;
else
F_61 ( V_183 , ( L_73 , V_9 -> V_37 , V_180 ) ) ;
F_23 ( V_69 , F_75 ( V_179 ) ) ;
if ( ( V_179 == V_184 ) || ( V_179 == V_185 ) ) {
V_182 = 1 ;
}
do {
while ( ! ( ( V_134 = F_9 ( V_26 ) ) & V_36 ) && ! V_182 ) ;
if ( ! ( V_134 & V_36 ) ) {
F_18 ( V_56 , V_77 ) ;
break;
}
F_61 ( V_186 , ( L_74 , V_9 -> V_37 ) ) ;
if ( ( V_134 & V_41 ) != V_179 ) {
F_61 ( V_186 , ( L_75 , V_9 -> V_37 ) ) ;
F_37 ( V_186 , V_9 ) ;
break;
}
if ( ! ( V_179 & V_148 ) )
F_23 ( V_72 , * V_181 ) ;
else
* V_181 = F_9 ( V_25 ) ;
++ V_181 ;
if ( ! ( V_179 & V_148 ) ) {
if ( ! ( ( V_179 & V_187 ) && V_180 > 1 ) ) {
F_23 ( V_28 , V_73 | V_74 ) ;
F_36 ( V_183 , V_9 ) ;
F_23 ( V_28 , V_73 | V_74 | V_188 ) ;
} else {
F_23 ( V_28 , V_73 | V_74 | V_173 ) ;
F_36 ( V_183 , V_9 ) ;
F_23 ( V_28 , V_73 | V_74 | V_173 | V_188 ) ;
}
} else {
F_36 ( V_183 , V_9 ) ;
F_23 ( V_28 , V_73 | V_188 ) ;
}
F_6 ( V_9 , V_26 , V_36 , 0 , 5 * V_67 ) ;
F_61 ( V_186 , ( L_76 , V_9 -> V_37 ) ) ;
if ( ! ( V_179 == V_189 && V_180 == 1 ) ) {
if ( V_179 == V_177 && V_180 > 1 )
F_23 ( V_28 , V_73 | V_173 ) ;
else
F_23 ( V_28 , V_73 ) ;
}
} while ( -- V_180 );
F_61 ( V_183 , ( L_77 , V_9 -> V_37 , V_180 ) ) ;
* V_178 = V_180 ;
* V_20 = V_181 ;
V_134 = F_9 ( V_26 ) ;
if ( V_134 & V_36 )
* V_159 = V_134 & V_41 ;
else
* V_159 = V_40 ;
if ( ! V_180 || ( * V_159 == V_179 ) )
return 0 ;
else
return - 1 ;
}
static void F_55 ( struct V_8 * V_98 ) {
F_7 () ;
F_8 ( V_98 ) ;
F_23 ( V_69 , F_75 ( F_9 ( V_26 ) & V_41 ) ) ;
F_23 ( V_28 , V_73 | V_190 ) ;
F_72 ( 25 ) ;
F_23 ( V_28 , V_73 ) ;
}
static int F_54 ( struct V_8 * V_98 ) {
F_7 () ;
unsigned char * V_191 , V_159 , V_134 ;
int V_160 ;
int V_192 ;
F_8 ( V_98 ) ;
F_23 ( V_28 , V_73 | V_173 ) ;
V_192 = F_6 ( V_98 , V_26 , V_36 , V_36 , 60 * V_67 ) ;
if( V_192 < 0 )
return - 1 ;
V_134 = ( unsigned char ) V_192 ;
F_23 ( V_69 , F_75 ( V_134 ) ) ;
if ( ( V_134 & V_41 ) != V_177 ) {
F_23 ( V_28 , V_73 | V_173 | V_188 ) ;
V_192 = F_6 ( V_98 , V_26 , V_36 , 0 , 3 * V_67 ) ;
F_23 ( V_28 , V_73 | V_173 ) ;
if( V_192 == - 1 )
return - 1 ;
}
V_134 = ABORT ;
V_191 = & V_134 ;
V_160 = 1 ;
V_159 = V_177 ;
F_74 ( V_98 , & V_159 , & V_160 , & V_191 ) ;
return V_160 ? - 1 : 0 ;
}
static int F_76 ( struct V_8 * V_9 , unsigned char * V_159 , int * V_178 , unsigned char * * V_20 ) {
F_7 () ;
register int V_180 = * V_178 ;
register unsigned char V_179 = * V_159 ;
register unsigned char * V_181 = * V_20 ;
unsigned char V_134 ;
int V_193 ;
#if F_65 ( F_31 )
int V_194 , V_195 ;
unsigned char V_196 = 0 , V_197 = 0 , V_198 ;
#endif
struct V_55 * V_56 = (struct V_55 * ) V_9 -> V_56 ;
F_8 ( V_9 ) ;
if ( ( V_134 = ( F_9 ( V_26 ) & V_41 ) ) != V_179 ) {
* V_159 = V_134 ;
return - 1 ;
}
#if F_65 ( F_30 ) || F_65 ( F_31 )
#ifdef F_77
if ( V_179 & V_148 ) {
V_180 -= 2 ;
}
#endif
F_61 ( V_199 , ( L_78 , V_9 -> V_37 , V_9 -> V_200 , ( V_179 & V_148 ) ? L_79 : L_80 , V_180 , ( V_179 & V_148 ) ? L_81 : L_82 , ( unsigned ) V_181 ) ) ;
V_56 -> V_201 = ( V_179 & V_148 ) ? F_78 ( V_9 , V_181 , V_180 ) : F_79 ( V_9 , V_181 , V_180 ) ;
#endif
F_23 ( V_69 , F_75 ( V_179 ) ) ;
#ifdef F_30
F_23 ( V_27 , V_128 | V_202 | V_203 | V_204 ) ;
#elif F_65 ( F_31 )
F_23 ( V_27 , V_128 | V_202 ) ;
#else
#if F_65 ( F_33 ) && F_65 ( F_34 )
F_46 ( V_9 -> V_92 ) ;
#endif
if ( V_56 -> V_79 & V_80 )
F_23 ( V_27 , V_128 | V_202 |
V_205 | V_206 |
V_203 | V_204 ) ;
else
F_23 ( V_27 , V_128 | V_202 ) ;
#endif
F_61 ( V_199 , ( L_83 , V_9 -> V_37 , F_9 ( V_27 ) ) ) ;
if ( V_179 & V_148 ) {
F_80 ( 1 ) ;
F_23 ( V_207 , 0 ) ;
} else {
F_80 ( 1 ) ;
F_23 ( V_28 , V_73 | V_74 ) ;
F_80 ( 1 ) ;
F_23 ( V_208 , 0 ) ;
F_80 ( 1 ) ;
}
#if F_65 ( F_31 )
do {
V_134 = F_9 ( V_29 ) ;
} while ( ( V_134 & V_154 ) && ! ( V_134 & ( V_209 | V_153 ) ) );
if ( V_179 & V_148 ) {
#ifdef F_77
F_72 ( 10 ) ;
if ( ( ( F_9 ( V_29 ) & ( V_154 | V_157 ) ) == ( V_154 | V_157 ) ) ) {
V_196 = F_9 ( V_210 ) ;
V_197 = 1 ;
}
#endif
} else {
int V_211 = 100 ;
while ( ( ( V_134 = F_9 ( V_29 ) ) & V_157 ) || ( F_9 ( V_26 ) & V_36 ) ) {
if ( ! ( V_134 & V_154 ) )
break;
if ( -- V_211 < 0 )
break;
}
}
F_61 ( V_199 , ( L_84 , V_9 -> V_37 , V_134 , F_9 ( V_26 ) ) ) ;
F_23 ( V_27 , V_128 ) ;
F_23 ( V_28 , V_73 ) ;
V_198 = F_67 ( V_9 ) ;
V_180 -= V_198 ;
* V_178 -= V_180 ;
* V_20 += V_180 ;
* V_159 = F_9 ( V_26 ) & V_41 ;
#ifdef F_77
if ( * V_159 == V_179 && ( V_179 & V_148 ) && V_198 == 0 ) {
if ( V_197 ) {
F_61 ( V_199 , ( L_85 ) ) ;
* * V_20 = V_196 ;
* V_20 += 1 ;
* V_178 -= 1 ;
V_194 = V_195 = 1 ;
} else {
F_15 ( L_86 ) ;
V_194 = V_195 = 2 ;
}
F_61 ( V_199 , ( L_87 , V_194 , * V_20 ) ) ;
F_74 ( V_9 , V_159 , & V_194 , V_20 ) ;
* V_178 -= V_195 - V_194 ;
}
#endif
F_61 ( V_199 , ( L_88 , * V_20 , * V_178 , * ( * V_20 + * V_178 - 1 ) , * ( * V_20 + * V_178 ) ) ) ;
return 0 ;
#elif F_65 ( F_30 )
return 0 ;
#else
if ( V_179 & V_148 ) {
#ifdef F_81
V_193 = F_82 ( V_9 , V_181 , V_180 ) ;
#else
int V_212 = 1 ;
if ( V_56 -> V_79 & V_80 ) {
V_212 = 0 ;
}
if ( ! ( V_193 = F_82 ( V_9 , V_181 , V_180 - V_212 ) ) ) {
if ( ! ( V_56 -> V_79 & V_80 ) ) {
while ( ! ( F_9 ( V_29 ) & V_213 ) ) ;
while ( F_9 ( V_26 ) & V_36 ) ;
V_181 [ V_180 - 1 ] = F_9 ( V_214 ) ;
}
}
#endif
} else {
#ifdef F_81
V_193 = F_83 ( V_9 , V_181 , V_180 ) ;
#else
int V_57 ;
F_61 ( V_215 , ( L_89 , V_180 ) ) ;
if ( ! ( V_193 = F_83 ( V_9 , V_181 , V_180 ) ) ) {
if ( ! ( V_56 -> V_79 & V_123 ) ) {
V_57 = 20000 ;
while ( ! ( F_9 ( V_29 ) & V_213 ) && ( F_9 ( V_29 ) & V_154 ) ) ;
if ( ! V_57 )
F_61 ( V_216 , ( L_90 , V_9 -> V_37 ) ) ;
if ( V_56 -> V_79 & V_124 ) {
V_56 -> V_79 &= ~ V_124 ;
if ( F_9 ( V_69 ) & V_217 ) {
V_56 -> V_79 |= V_123 ;
F_61 ( V_218 , ( L_91 , V_9 -> V_37 ) ) ;
}
}
} else {
F_61 ( V_215 , ( L_92 ) ) ;
while ( ! ( F_9 ( V_69 ) & V_217 ) ) ;
F_61 ( V_215 , ( L_93 ) ) ;
}
}
#endif
}
F_23 ( V_27 , V_128 ) ;
F_23 ( V_28 , V_73 ) ;
if ( ( ! ( V_179 & V_148 ) ) && ( V_56 -> V_79 & V_80 ) ) {
F_61 ( V_215 , ( L_94 ) ) ;
if ( F_9 ( V_29 ) & V_146 ) {
F_61 ( V_215 , ( L_95 ) ) ;
F_9 ( V_149 ) ;
} else {
F_15 ( L_96 ) ;
}
}
* V_20 = V_181 + V_180 ;
* V_178 = 0 ;
* V_159 = F_9 ( V_26 ) & V_41 ;
#if F_65 ( F_33 ) && F_65 ( F_34 )
F_44 ( V_9 -> V_92 ) ;
#endif
return V_193 ;
#endif
}
static void F_64 ( struct V_8 * V_9 ) {
F_7 () ;
struct V_55 * V_56 = (struct V_55 * )
V_9 -> V_56 ;
unsigned char V_219 ;
unsigned char V_100 , V_159 ;
int V_160 ;
unsigned char V_220 [ 3 ] ;
unsigned char * V_20 ;
T_2 * V_134 = NULL , * V_221 ;
int abort = 0 ;
F_8 ( V_9 ) ;
F_23 ( V_27 , V_128 ) ;
V_56 -> V_164 = 1 ;
V_219 = F_9 ( V_25 ) & ~ ( V_56 -> V_71 ) ;
F_61 ( V_174 , ( L_97 , V_9 -> V_37 ) ) ;
F_23 ( V_28 , V_73 | V_172 ) ;
if( F_6 ( V_9 , V_26 , V_147 , 0 , 2 * V_67 ) < 0 )
abort = 1 ;
F_23 ( V_28 , V_73 ) ;
if( F_6 ( V_9 , V_26 , V_36 , V_36 , 2 * V_67 ) )
abort = 1 ;
V_160 = 1 ;
V_20 = V_220 ;
V_159 = V_189 ;
F_74 ( V_9 , & V_159 , & V_160 , & V_20 ) ;
if ( ! ( V_220 [ 0 ] & 0x80 ) ) {
F_15 ( V_106 L_98 , V_9 -> V_37 ) ;
F_84 ( V_220 ) ;
abort = 1 ;
} else {
F_23 ( V_28 , V_73 ) ;
V_100 = ( V_220 [ 0 ] & 0x07 ) ;
for ( V_134 = ( T_2 * ) V_56 -> V_96 , V_221 = NULL ; V_134 ; V_221 = V_134 , V_134 = ( T_2 * ) V_134 -> V_95 )
if ( ( V_219 == ( 1 << V_134 -> V_97 -> V_99 ) ) && ( V_100 == V_134 -> V_97 -> V_100 )
) {
if ( V_221 ) {
REMOVE ( V_221 , V_221 -> V_95 , V_134 , V_134 -> V_95 ) ;
V_221 -> V_95 = V_134 -> V_95 ;
} else {
REMOVE ( - 1 , V_56 -> V_96 , V_134 , V_134 -> V_95 ) ;
V_56 -> V_96 = ( T_2 * ) V_134 -> V_95 ;
}
V_134 -> V_95 = NULL ;
break;
}
if ( ! V_134 ) {
F_15 ( V_106 L_99 , V_9 -> V_37 , V_219 , V_100 ) ;
abort = 1 ;
}
}
if ( abort ) {
F_54 ( V_9 ) ;
} else {
V_56 -> V_93 = V_134 ;
F_61 ( V_222 , ( L_100 , V_9 -> V_37 , V_134 -> V_223 , V_134 -> V_100 , V_134 -> V_158 ) ) ;
}
}
static void F_85 ( T_6 * V_9 ) {
F_7 () ;
struct V_55 * V_56 = (struct V_55 * ) V_9 -> V_56 ;
int V_155 ;
F_8 ( V_9 ) ;
F_6 ( V_9 , V_29 , V_157 , 0 , 5 * V_67 ) ;
F_23 ( V_27 , V_128 ) ;
F_23 ( V_28 , V_73 ) ;
if ( ! ( V_56 -> V_93 -> V_2 . V_159 & V_224 ) ) {
V_155 = V_9 -> V_113 - F_67 () ;
V_56 -> V_93 -> V_2 . V_6 -= V_155 ;
V_56 -> V_93 -> V_2 . V_5 += V_155 ;
}
}
static int F_86 ( T_2 * V_1 ) {
F_7 () ;
struct V_8 * V_9 = V_1 -> V_97 -> V_98 ;
struct V_55 * V_56 = (struct V_55 * ) V_9 -> V_56 ;
T_2 * V_134 , * * V_221 ;
F_15 ( V_127 L_101 , V_9 -> V_37 ) ;
F_87 ( V_1 ) ;
F_35 ( V_9 ) ;
F_8 ( V_9 ) ;
F_61 ( V_225 , ( L_102 , V_9 -> V_37 ) ) ;
F_61 ( V_225 , ( L_103 , F_9 ( V_29 ) , F_9 ( V_26 ) ) ) ;
#if 0
if (hostdata->connected == cmd) {
dprintk(NDEBUG_ABORT, ("scsi%d : aborting connected command\n", instance->host_no));
hostdata->aborted = 1;
NCR5380_write(INITIATOR_COMMAND_REG, ICR_ASSERT_ATN);
return 0;
}
#endif
F_61 ( V_225 , ( L_104 , V_9 -> V_37 ) ) ;
for ( V_221 = ( T_2 * * ) & ( V_56 -> V_94 ) , V_134 = ( T_2 * ) V_56 -> V_94 ; V_134 ; V_221 = ( T_2 * * ) & ( V_134 -> V_95 ) , V_134 = ( T_2 * ) V_134 -> V_95 )
if ( V_1 == V_134 ) {
REMOVE ( 5 , * V_221 , V_134 , V_134 -> V_95 ) ;
( * V_221 ) = ( T_2 * ) V_134 -> V_95 ;
V_134 -> V_95 = NULL ;
V_134 -> V_137 = V_226 << 16 ;
F_61 ( V_225 , ( L_105 , V_9 -> V_37 ) ) ;
V_134 -> V_141 ( V_134 ) ;
return V_227 ;
}
#if ( V_135 & V_225 )
else if ( V_221 == V_134 )
F_15 ( V_106 L_106 , V_9 -> V_37 ) ;
#endif
if ( V_56 -> V_93 ) {
F_61 ( V_225 , ( L_107 , V_9 -> V_37 ) ) ;
return V_228 ;
}
for ( V_134 = ( T_2 * ) V_56 -> V_96 ; V_134 ; V_134 = ( T_2 * ) V_134 -> V_95 )
if ( V_1 == V_134 ) {
F_61 ( V_225 , ( L_108 , V_9 -> V_37 ) ) ;
if ( F_71 ( V_9 , V_1 , ( int ) V_1 -> V_158 ) )
return V_228 ;
F_61 ( V_225 , ( L_109 , V_9 -> V_37 ) ) ;
F_54 ( V_9 ) ;
for ( V_221 = ( T_2 * * ) & ( V_56 -> V_96 ) , V_134 = ( T_2 * ) V_56 -> V_96 ; V_134 ; V_221 = ( T_2 * * ) & ( V_134 -> V_95 ) , V_134 = ( T_2 * ) V_134 -> V_95 )
if ( V_1 == V_134 ) {
REMOVE ( 5 , * V_221 , V_134 , V_134 -> V_95 ) ;
* V_221 = ( T_2 * ) V_134 -> V_95 ;
V_134 -> V_95 = NULL ;
V_134 -> V_137 = V_226 << 16 ;
V_134 -> V_141 ( V_134 ) ;
return V_227 ;
}
}
F_15 ( V_127 L_110
L_111 , V_9 -> V_37 ) ;
return V_228 ;
}
static int F_88 ( T_2 * V_1 )
{
struct V_8 * V_9 = V_1 -> V_97 -> V_98 ;
F_7 () ;
F_8 ( V_9 ) ;
F_35 ( V_9 ) ;
F_44 ( V_9 -> V_92 ) ;
F_55 ( V_9 ) ;
F_46 ( V_9 -> V_92 ) ;
return V_227 ;
}
