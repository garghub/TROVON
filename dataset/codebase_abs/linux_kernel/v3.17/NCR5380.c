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
if ( ( V_31 & V_64 ) && ( F_22 ( V_24 , & F_20 , 0 , L_9 , NULL ) == 0 ) )
V_65 |= V_31 ;
V_57 = V_16 + ( 250 * V_66 / 1000 ) ;
V_62 = V_67 ;
F_23 ( V_68 , 0 ) ;
F_23 ( V_69 , V_56 -> V_70 ) ;
F_23 ( V_71 , V_56 -> V_70 ) ;
F_23 ( V_28 , V_72 | V_73 | V_74 ) ;
while ( V_62 == V_67 && F_11 ( V_16 , V_57 ) )
F_24 ( 1 ) ;
F_23 ( V_69 , 0 ) ;
F_23 ( V_28 , V_72 ) ;
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
F_15 ( L_19 , V_75 , V_76 ) ;
F_15 ( L_20 , V_77 ) ;
if ( ( (struct V_55 * ) V_9 -> V_56 ) -> V_78 & V_79 ) {
F_15 ( L_21 , V_80 ) ;
}
}
static void F_35 ( struct V_8 * V_9 )
{
F_36 ( V_81 , V_9 ) ;
F_37 ( V_81 , V_9 ) ;
}
static int T_5 F_38 ( struct V_8 * V_9 ,
char * V_3 , int V_7 )
{
#ifdef F_39
V_82 = V_83 = 0 ;
#endif
#ifdef F_40
V_84 = V_85 = 0 ;
#endif
return ( - V_86 ) ;
}
static int T_5 F_41 ( struct V_87 * V_88 ,
struct V_8 * V_9 )
{
struct V_55 * V_56 ;
T_2 * V_5 ;
V_56 = (struct V_55 * ) V_9 -> V_56 ;
SPRINTF ( L_22 , V_77 ) ;
if ( ( (struct V_55 * ) V_9 -> V_56 ) -> V_78 & V_79 )
SPRINTF ( L_23 , V_80 ) ;
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
SPRINTF ( L_28 , ( long ) V_9 -> V_89 ) ;
SPRINTF ( L_29 , ( int ) V_9 -> V_90 ) ;
if ( V_9 -> V_60 == V_67 )
SPRINTF ( L_30 ) ;
else
SPRINTF ( L_31 , V_9 -> V_60 ) ;
#ifdef F_39
SPRINTF ( L_32 , V_82 , V_83 ) ;
#endif
#ifdef F_40
SPRINTF ( L_32 , V_84 , V_85 ) ;
#endif
F_44 ( V_9 -> V_91 ) ;
if ( ! V_56 -> V_92 )
SPRINTF ( L_33 , V_9 -> V_37 ) ;
else
F_45 ( ( T_2 * ) V_56 -> V_92 , V_88 ) ;
SPRINTF ( L_34 , V_9 -> V_37 ) ;
for ( V_5 = ( T_2 * ) V_56 -> V_93 ; V_5 ; V_5 = ( T_2 * ) V_5 -> V_94 )
F_45 ( V_5 , V_88 ) ;
SPRINTF ( L_35 , V_9 -> V_37 ) ;
for ( V_5 = ( T_2 * ) V_56 -> V_95 ; V_5 ; V_5 = ( T_2 * ) V_5 -> V_94 )
F_45 ( V_5 , V_88 ) ;
F_46 ( V_9 -> V_91 ) ;
return 0 ;
}
static void F_45 ( T_2 * V_1 , struct V_87 * V_88 )
{
SPRINTF ( L_36 , V_1 -> V_96 -> V_97 -> V_37 , V_1 -> V_96 -> V_98 , V_1 -> V_96 -> V_99 ) ;
SPRINTF ( L_37 ) ;
F_47 ( V_1 -> V_100 , V_88 ) ;
}
static void F_47 ( unsigned char * V_101 , struct V_87 * V_88 )
{
int V_24 , V_102 ;
F_48 ( V_101 [ 0 ] , V_88 ) ;
for ( V_24 = 1 , V_102 = F_49 ( V_101 [ 0 ] ) ; V_24 < V_102 ; ++ V_24 )
SPRINTF ( L_38 , V_101 [ V_24 ] ) ;
SPRINTF ( L_6 ) ;
}
static void F_48 ( int V_103 , struct V_87 * V_88 )
{
SPRINTF ( L_39 , V_103 , V_103 ) ;
}
static int F_50 ( struct V_8 * V_9 , int V_78 )
{
F_7 () ;
int V_24 , V_104 ;
unsigned long V_57 ;
struct V_55 * V_56 = (struct V_55 * ) V_9 -> V_56 ;
if( F_12 () )
F_15 ( V_105 L_40 ) ;
#ifdef F_51
if ( V_78 & V_79 )
V_9 -> V_106 += V_107 ;
#endif
F_8 ( V_9 ) ;
V_56 -> V_108 = 0 ;
V_56 -> V_70 = 1 << V_9 -> V_109 ;
for ( V_24 = V_56 -> V_70 ; V_24 <= 0x80 ; V_24 <<= 1 )
if ( V_24 > V_56 -> V_70 )
V_56 -> V_110 |= V_24 ;
for ( V_24 = 0 ; V_24 < 8 ; ++ V_24 )
V_56 -> V_111 [ V_24 ] = 0 ;
#ifdef F_30
V_56 -> V_112 = 0 ;
#endif
V_56 -> V_113 = 0 ;
V_56 -> V_92 = NULL ;
V_56 -> V_93 = NULL ;
V_56 -> V_95 = NULL ;
F_52 ( & V_56 -> V_59 , V_114 ) ;
#ifdef F_53
for ( V_24 = 0 ; V_24 < 8 ; ++ V_24 ) {
V_56 -> V_115 [ V_24 ] = 0 ;
V_56 -> V_116 [ V_24 ] = 0 ;
V_56 -> V_117 [ V_24 ] = 0 ;
V_56 -> V_118 [ V_24 ] = 0 ;
}
V_56 -> V_119 = 0 ;
V_56 -> V_120 = 0 ;
V_56 -> V_121 = 0 ;
#endif
if ( V_78 & V_79 )
V_56 -> V_78 = V_122 | V_78 ;
else
V_56 -> V_78 = V_123 | V_78 ;
V_56 -> V_97 = V_9 ;
V_56 -> V_58 = 0 ;
#ifndef F_28
if ( ( V_9 -> V_124 > 1 ) || V_9 -> V_125 > 1 )
F_15 ( V_126 L_41 L_42
L_43 , V_9 -> V_37 ) ;
#endif
F_23 ( V_28 , V_72 ) ;
F_23 ( V_27 , V_127 ) ;
F_23 ( V_68 , 0 ) ;
F_23 ( V_69 , 0 ) ;
#ifdef F_51
if ( V_56 -> V_78 & V_79 ) {
F_23 ( V_128 , V_129 ) ;
}
#endif
for ( V_104 = 1 ; ( F_9 ( V_26 ) & V_130 ) && V_104 <= 6 ; ++ V_104 ) {
switch ( V_104 ) {
case 1 :
case 3 :
case 5 :
F_15 ( V_131 L_44 , V_9 -> V_37 ) ;
V_57 = V_16 + 5 * V_66 ;
F_6 ( V_9 , V_26 , V_130 , 0 , 5 * V_66 ) ;
break;
case 2 :
F_15 ( V_126 L_45 , V_9 -> V_37 ) ;
F_54 ( V_9 ) ;
break;
case 4 :
F_15 ( V_126 L_46 , V_9 -> V_37 ) ;
F_55 ( V_9 ) ;
break;
case 6 :
F_15 ( V_105 L_47 , V_9 -> V_37 ) ;
return - V_132 ;
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
struct V_8 * V_9 = V_1 -> V_96 -> V_97 ;
struct V_55 * V_56 = (struct V_55 * ) V_9 -> V_56 ;
T_2 * V_133 ;
#if ( V_134 & V_135 )
switch ( V_1 -> V_100 [ 0 ] ) {
case V_43 :
case V_46 :
F_15 ( L_48 , V_9 -> V_37 ) ;
V_1 -> V_136 = ( V_137 << 16 ) ;
F_59 ( V_1 ) ;
return 0 ;
}
#endif
#ifdef F_53
switch ( V_1 -> V_100 [ 0 ] ) {
case V_138 :
case V_43 :
case V_46 :
V_56 -> V_116 [ V_1 -> V_96 -> V_98 ] -= ( V_16 - V_56 -> V_119 ) ;
V_56 -> V_118 [ V_1 -> V_96 -> V_98 ] += F_2 ( V_1 ) ;
V_56 -> V_120 ++ ;
break;
case V_139 :
case V_42 :
case V_45 :
V_56 -> V_115 [ V_1 -> V_96 -> V_98 ] -= ( V_16 - V_56 -> V_119 ) ;
V_56 -> V_117 [ V_1 -> V_96 -> V_98 ] += F_2 ( V_1 ) ;
V_56 -> V_121 ++ ;
break;
}
#endif
V_1 -> V_94 = NULL ;
V_1 -> V_140 = F_59 ;
V_1 -> V_136 = 0 ;
if ( ! ( V_56 -> V_93 ) || ( V_1 -> V_100 [ 0 ] == V_141 ) ) {
F_60 ( V_1 , V_56 -> V_93 ) ;
V_1 -> V_94 = ( unsigned char * ) V_56 -> V_93 ;
V_56 -> V_93 = V_1 ;
} else {
for ( V_133 = ( T_2 * ) V_56 -> V_93 ; V_133 -> V_94 ; V_133 = ( T_2 * ) V_133 -> V_94 ) ;
F_60 ( V_1 , V_133 ) ;
V_133 -> V_94 = ( unsigned char * ) V_1 ;
}
F_61 ( V_142 , L_49 , V_9 -> V_37 , ( V_1 -> V_100 [ 0 ] == V_141 ) ? L_50 : L_51 ) ;
F_19 ( & V_56 -> V_59 , 0 ) ;
return 0 ;
}
T_3 F_62 ( int V_143 , void * V_61 )
{
F_7 () ;
struct V_8 * V_9 = V_61 ;
struct V_55 * V_56 = (struct V_55 * ) V_9 -> V_56 ;
int F_59 ;
unsigned char V_21 ;
unsigned long V_78 ;
F_61 ( V_144 , L_52 ,
V_9 -> V_60 ) ;
do {
F_59 = 1 ;
F_63 ( V_9 -> V_91 , V_78 ) ;
F_8 ( V_9 ) ;
V_21 = F_9 ( V_29 ) ;
if ( V_21 & V_145 ) {
F_36 ( V_144 , V_9 ) ;
if ( ( F_9 ( V_26 ) & ( V_146 | V_147 ) ) == ( V_146 | V_147 ) ) {
F_59 = 0 ;
F_61 ( V_144 , L_53 , V_9 -> V_37 ) ;
F_64 ( V_9 ) ;
( void ) F_9 ( V_148 ) ;
} else if ( V_21 & V_149 ) {
F_61 ( V_144 , L_54 , V_9 -> V_37 ) ;
( void ) F_9 ( V_148 ) ;
} else if ( ( F_9 ( V_26 ) & V_150 ) == V_150 ) {
F_61 ( V_144 , L_55 , V_9 -> V_37 ) ;
( void ) F_9 ( V_148 ) ;
} else {
#if F_65 ( F_30 )
if ( ( F_9 ( V_27 ) & V_151 ) && ( ( V_21 & V_152 ) || ! ( V_21 & V_153 ) ) ) {
int V_154 ;
if ( ! V_56 -> V_92 )
F_66 ( L_56 , V_9 -> V_155 ) ;
V_154 = ( V_56 -> V_112 - F_67 ( V_9 ) ) ;
V_56 -> V_92 -> V_2 . V_6 -= V_154 ;
V_56 -> V_92 -> V_2 . V_5 += V_154 ;
V_56 -> V_112 = 0 ;
( void ) F_9 ( V_148 ) ;
F_6 ( V_56 , V_29 , V_156 , 0 , 2 * V_66 ) ;
F_23 ( V_27 , V_127 ) ;
F_23 ( V_28 , V_72 ) ;
}
#else
F_61 ( V_144 , L_57 , V_21 , F_9 ( V_27 ) , F_9 ( V_26 ) ) ;
( void ) F_9 ( V_148 ) ;
#endif
}
}
F_68 ( V_9 -> V_91 , V_78 ) ;
if( ! F_59 )
F_19 ( & V_56 -> V_59 , 0 ) ;
} while ( ! F_59 );
return V_63 ;
}
static void F_69 ( struct V_55 * V_56 , T_2 * V_1 )
{
#ifdef F_53
switch ( V_1 -> V_100 [ 0 ] ) {
case V_138 :
case V_43 :
case V_46 :
V_56 -> V_116 [ F_70 ( V_1 ) ] += ( V_16 - V_56 -> V_119 ) ;
V_56 -> V_120 -- ;
break;
case V_139 :
case V_42 :
case V_45 :
V_56 -> V_115 [ F_70 ( V_1 ) ] += ( V_16 - V_56 -> V_119 ) ;
V_56 -> V_121 -- ;
break;
}
#endif
}
static int F_71 ( struct V_8 * V_9 , T_2 * V_1 , int V_157 )
{
F_7 () ;
struct V_55 * V_56 = (struct V_55 * ) V_9 -> V_56 ;
unsigned char V_133 [ 3 ] , V_158 ;
unsigned char * V_20 ;
int V_159 ;
unsigned long V_57 ;
unsigned char V_39 ;
int V_160 ;
F_8 ( V_9 ) ;
if ( V_56 -> V_161 )
goto V_162;
V_56 -> V_163 = 0 ;
F_36 ( V_164 , V_9 ) ;
F_61 ( V_164 , L_58 , V_9 -> V_37 , V_9 -> V_109 ) ;
F_23 ( V_68 , 0 ) ;
F_23 ( V_71 , V_56 -> V_70 ) ;
F_23 ( V_27 , V_165 ) ;
F_46 ( V_9 -> V_91 ) ;
V_160 = F_6 ( V_9 , V_28 , V_166 , V_166 , 5 * V_66 ) ;
F_44 ( V_9 -> V_91 ) ;
if ( V_160 < 0 ) {
F_15 ( V_167 L_59 , __LINE__ ) ;
F_23 ( V_27 , V_127 ) ;
F_23 ( V_69 , V_56 -> V_70 ) ;
goto V_168;
}
F_61 ( V_164 , L_60 , V_9 -> V_37 ) ;
F_72 ( 3 ) ;
if ( ( F_9 ( V_28 ) & V_169 ) || ( F_9 ( V_25 ) & V_56 -> V_110 ) || ( F_9 ( V_28 ) & V_169 ) ) {
F_23 ( V_27 , V_127 ) ;
F_61 ( V_164 , L_61 , V_9 -> V_37 ) ;
goto V_168;
}
F_23 ( V_28 , V_72 | V_74 ) ;
if ( ! ( V_56 -> V_78 & V_170 ) &&
( F_9 ( V_28 ) & V_169 ) ) {
F_23 ( V_27 , V_127 ) ;
F_23 ( V_28 , V_72 ) ;
F_61 ( V_164 , L_62 , V_9 -> V_37 ) ;
goto V_168;
}
F_72 ( 2 ) ;
F_61 ( V_164 , L_63 , V_9 -> V_37 ) ;
F_23 ( V_71 , ( V_56 -> V_70 | ( 1 << F_70 ( V_1 ) ) ) ) ;
F_23 ( V_28 , ( V_72 | V_171 | V_73 | V_172 | V_74 ) ) ;
F_23 ( V_27 , V_127 ) ;
F_23 ( V_69 , 0 ) ;
F_72 ( 1 ) ;
F_23 ( V_28 , ( V_72 | V_73 | V_172 | V_74 ) ) ;
F_72 ( 1 ) ;
F_61 ( V_173 , L_64 , V_9 -> V_37 , F_70 ( V_1 ) ) ;
V_57 = V_16 + ( 250 * V_66 / 1000 ) ;
V_56 -> V_174 = 0 ;
V_56 -> V_161 = V_1 ;
V_162:
V_39 = F_9 ( V_26 ) & ( V_130 | V_147 ) ;
if ( ! V_39 && ( V_56 -> V_174 < V_66 / 4 ) ) {
V_56 -> V_174 ++ ;
F_18 ( V_56 , 1 ) ;
return 0 ;
}
V_56 -> V_161 = NULL ;
if ( ( F_9 ( V_26 ) & ( V_146 | V_147 ) ) == ( V_146 | V_147 ) ) {
F_23 ( V_28 , V_72 ) ;
F_64 ( V_9 ) ;
F_15 ( L_65 , V_9 -> V_37 ) ;
F_23 ( V_69 , V_56 -> V_70 ) ;
return - 1 ;
}
F_72 ( 1 ) ;
F_23 ( V_28 , V_72 | V_172 ) ;
if ( ! ( F_9 ( V_26 ) & V_130 ) ) {
F_23 ( V_28 , V_72 ) ;
if ( V_56 -> V_113 & ( 1 << F_70 ( V_1 ) ) ) {
F_15 ( V_167 L_66 , V_9 -> V_37 ) ;
if ( V_56 -> V_163 )
F_15 ( V_167 L_67 ) ;
F_36 ( V_173 , V_9 ) ;
F_23 ( V_69 , V_56 -> V_70 ) ;
return - 1 ;
}
V_1 -> V_136 = V_175 << 16 ;
F_69 ( V_56 , V_1 ) ;
V_1 -> V_140 ( V_1 ) ;
F_23 ( V_69 , V_56 -> V_70 ) ;
F_61 ( V_173 , L_68 , V_9 -> V_37 ) ;
F_23 ( V_69 , V_56 -> V_70 ) ;
return 0 ;
}
V_56 -> V_113 |= ( 1 << F_70 ( V_1 ) ) ;
F_46 ( V_9 -> V_91 ) ;
V_160 = F_6 ( V_9 , V_26 , V_36 , V_36 , V_66 ) ;
F_44 ( V_9 -> V_91 ) ;
if( V_160 ) {
F_15 ( V_105 L_69 , V_9 -> V_37 , __LINE__ ) ;
F_23 ( V_69 , V_56 -> V_70 ) ;
goto V_168;
}
F_61 ( V_173 , L_70 , V_9 -> V_37 , V_1 -> V_96 -> V_98 ) ;
V_133 [ 0 ] = F_73 ( ( ( V_9 -> V_60 == V_67 ) ? 0 : 1 ) , V_1 -> V_96 -> V_99 ) ;
V_159 = 1 ;
V_1 -> V_157 = 0 ;
V_20 = V_133 ;
V_158 = V_176 ;
F_74 ( V_9 , & V_158 , & V_159 , & V_20 ) ;
F_61 ( V_173 , L_71 , V_9 -> V_37 ) ;
V_56 -> V_92 = V_1 ;
V_56 -> V_111 [ V_1 -> V_96 -> V_98 ] |= ( 1 << ( V_1 -> V_96 -> V_99 & 0xFF ) ) ;
F_1 ( V_1 ) ;
return 0 ;
V_168:
return - 1 ;
}
static int F_74 ( struct V_8 * V_9 , unsigned char * V_158 , int * V_177 , unsigned char * * V_20 ) {
F_7 () ;
unsigned char V_178 = * V_158 , V_133 ;
int V_179 = * V_177 ;
unsigned char * V_180 = * V_20 ;
int V_181 = 0 ;
struct V_55 * V_56 = (struct V_55 * ) V_9 -> V_56 ;
F_8 ( V_9 ) ;
if ( ! ( V_178 & V_147 ) )
F_61 ( V_182 , L_72 , V_9 -> V_37 , V_179 ) ;
else
F_61 ( V_182 , L_73 , V_9 -> V_37 , V_179 ) ;
F_23 ( V_68 , F_75 ( V_178 ) ) ;
if ( ( V_178 == V_183 ) || ( V_178 == V_184 ) ) {
V_181 = 1 ;
}
do {
while ( ! ( ( V_133 = F_9 ( V_26 ) ) & V_36 ) && ! V_181 ) ;
if ( ! ( V_133 & V_36 ) ) {
F_18 ( V_56 , V_76 ) ;
break;
}
F_61 ( V_185 , L_74 , V_9 -> V_37 ) ;
if ( ( V_133 & V_41 ) != V_178 ) {
F_61 ( V_185 , L_75 , V_9 -> V_37 ) ;
F_37 ( V_185 , V_9 ) ;
break;
}
if ( ! ( V_178 & V_147 ) )
F_23 ( V_71 , * V_180 ) ;
else
* V_180 = F_9 ( V_25 ) ;
++ V_180 ;
if ( ! ( V_178 & V_147 ) ) {
if ( ! ( ( V_178 & V_186 ) && V_179 > 1 ) ) {
F_23 ( V_28 , V_72 | V_73 ) ;
F_36 ( V_182 , V_9 ) ;
F_23 ( V_28 , V_72 | V_73 | V_187 ) ;
} else {
F_23 ( V_28 , V_72 | V_73 | V_172 ) ;
F_36 ( V_182 , V_9 ) ;
F_23 ( V_28 , V_72 | V_73 | V_172 | V_187 ) ;
}
} else {
F_36 ( V_182 , V_9 ) ;
F_23 ( V_28 , V_72 | V_187 ) ;
}
F_6 ( V_9 , V_26 , V_36 , 0 , 5 * V_66 ) ;
F_61 ( V_185 , L_76 , V_9 -> V_37 ) ;
if ( ! ( V_178 == V_188 && V_179 == 1 ) ) {
if ( V_178 == V_176 && V_179 > 1 )
F_23 ( V_28 , V_72 | V_172 ) ;
else
F_23 ( V_28 , V_72 ) ;
}
} while ( -- V_179 );
F_61 ( V_182 , L_77 , V_9 -> V_37 , V_179 ) ;
* V_177 = V_179 ;
* V_20 = V_180 ;
V_133 = F_9 ( V_26 ) ;
if ( V_133 & V_36 )
* V_158 = V_133 & V_41 ;
else
* V_158 = V_40 ;
if ( ! V_179 || ( * V_158 == V_178 ) )
return 0 ;
else
return - 1 ;
}
static void F_55 ( struct V_8 * V_97 ) {
F_7 () ;
F_8 ( V_97 ) ;
F_23 ( V_68 , F_75 ( F_9 ( V_26 ) & V_41 ) ) ;
F_23 ( V_28 , V_72 | V_189 ) ;
F_72 ( 25 ) ;
F_23 ( V_28 , V_72 ) ;
}
static int F_54 ( struct V_8 * V_97 ) {
F_7 () ;
unsigned char * V_190 , V_158 , V_133 ;
int V_159 ;
int V_191 ;
F_8 ( V_97 ) ;
F_23 ( V_28 , V_72 | V_172 ) ;
V_191 = F_6 ( V_97 , V_26 , V_36 , V_36 , 60 * V_66 ) ;
if( V_191 < 0 )
return - 1 ;
V_133 = ( unsigned char ) V_191 ;
F_23 ( V_68 , F_75 ( V_133 ) ) ;
if ( ( V_133 & V_41 ) != V_176 ) {
F_23 ( V_28 , V_72 | V_172 | V_187 ) ;
V_191 = F_6 ( V_97 , V_26 , V_36 , 0 , 3 * V_66 ) ;
F_23 ( V_28 , V_72 | V_172 ) ;
if( V_191 == - 1 )
return - 1 ;
}
V_133 = ABORT ;
V_190 = & V_133 ;
V_159 = 1 ;
V_158 = V_176 ;
F_74 ( V_97 , & V_158 , & V_159 , & V_190 ) ;
return V_159 ? - 1 : 0 ;
}
static int F_76 ( struct V_8 * V_9 , unsigned char * V_158 , int * V_177 , unsigned char * * V_20 ) {
F_7 () ;
register int V_179 = * V_177 ;
register unsigned char V_178 = * V_158 ;
register unsigned char * V_180 = * V_20 ;
unsigned char V_133 ;
int V_192 ;
#if F_65 ( F_31 )
int V_193 , V_194 ;
unsigned char V_195 = 0 , V_196 = 0 , V_197 ;
#endif
struct V_55 * V_56 = (struct V_55 * ) V_9 -> V_56 ;
F_8 ( V_9 ) ;
if ( ( V_133 = ( F_9 ( V_26 ) & V_41 ) ) != V_178 ) {
* V_158 = V_133 ;
return - 1 ;
}
#if F_65 ( F_30 ) || F_65 ( F_31 )
#ifdef F_77
if ( V_178 & V_147 ) {
V_179 -= 2 ;
}
#endif
F_61 ( V_198 , L_78 , V_9 -> V_37 , V_9 -> V_199 , ( V_178 & V_147 ) ? L_79 : L_80 , V_179 , ( V_178 & V_147 ) ? L_81 : L_82 , ( unsigned ) V_180 ) ;
V_56 -> V_200 = ( V_178 & V_147 ) ? F_78 ( V_9 , V_180 , V_179 ) : F_79 ( V_9 , V_180 , V_179 ) ;
#endif
F_23 ( V_68 , F_75 ( V_178 ) ) ;
#ifdef F_30
F_23 ( V_27 , V_127 | V_201 | V_202 | V_203 ) ;
#elif F_65 ( F_31 )
F_23 ( V_27 , V_127 | V_201 ) ;
#else
#if F_65 ( F_33 ) && F_65 ( F_34 )
F_46 ( V_9 -> V_91 ) ;
#endif
if ( V_56 -> V_78 & V_79 )
F_23 ( V_27 , V_127 | V_201 |
V_204 | V_205 |
V_202 | V_203 ) ;
else
F_23 ( V_27 , V_127 | V_201 ) ;
#endif
F_61 ( V_198 , L_83 , V_9 -> V_37 , F_9 ( V_27 ) ) ;
if ( V_178 & V_147 ) {
F_80 ( 1 ) ;
F_23 ( V_206 , 0 ) ;
} else {
F_80 ( 1 ) ;
F_23 ( V_28 , V_72 | V_73 ) ;
F_80 ( 1 ) ;
F_23 ( V_207 , 0 ) ;
F_80 ( 1 ) ;
}
#if F_65 ( F_31 )
do {
V_133 = F_9 ( V_29 ) ;
} while ( ( V_133 & V_153 ) && ! ( V_133 & ( V_208 | V_152 ) ) );
if ( V_178 & V_147 ) {
#ifdef F_77
F_72 ( 10 ) ;
if ( ( ( F_9 ( V_29 ) & ( V_153 | V_156 ) ) == ( V_153 | V_156 ) ) ) {
V_195 = F_9 ( V_209 ) ;
V_196 = 1 ;
}
#endif
} else {
int V_210 = 100 ;
while ( ( ( V_133 = F_9 ( V_29 ) ) & V_156 ) || ( F_9 ( V_26 ) & V_36 ) ) {
if ( ! ( V_133 & V_153 ) )
break;
if ( -- V_210 < 0 )
break;
}
}
F_61 ( V_198 , L_84 , V_9 -> V_37 , V_133 , F_9 ( V_26 ) ) ;
F_23 ( V_27 , V_127 ) ;
F_23 ( V_28 , V_72 ) ;
V_197 = F_67 ( V_9 ) ;
V_179 -= V_197 ;
* V_177 -= V_179 ;
* V_20 += V_179 ;
* V_158 = F_9 ( V_26 ) & V_41 ;
#ifdef F_77
if ( * V_158 == V_178 && ( V_178 & V_147 ) && V_197 == 0 ) {
if ( V_196 ) {
F_61 ( V_198 , L_85 ) ;
* * V_20 = V_195 ;
* V_20 += 1 ;
* V_177 -= 1 ;
V_193 = V_194 = 1 ;
} else {
F_15 ( L_86 ) ;
V_193 = V_194 = 2 ;
}
F_61 ( V_198 , L_87 , V_193 , * V_20 ) ;
F_74 ( V_9 , V_158 , & V_193 , V_20 ) ;
* V_177 -= V_194 - V_193 ;
}
#endif
F_61 ( V_198 , L_88 , * V_20 , * V_177 , * ( * V_20 + * V_177 - 1 ) , * ( * V_20 + * V_177 ) ) ;
return 0 ;
#elif F_65 ( F_30 )
return 0 ;
#else
if ( V_178 & V_147 ) {
#ifdef F_81
V_192 = F_82 ( V_9 , V_180 , V_179 ) ;
#else
int V_211 = 1 ;
if ( V_56 -> V_78 & V_79 ) {
V_211 = 0 ;
}
if ( ! ( V_192 = F_82 ( V_9 , V_180 , V_179 - V_211 ) ) ) {
if ( ! ( V_56 -> V_78 & V_79 ) ) {
while ( ! ( F_9 ( V_29 ) & V_212 ) ) ;
while ( F_9 ( V_26 ) & V_36 ) ;
V_180 [ V_179 - 1 ] = F_9 ( V_213 ) ;
}
}
#endif
} else {
#ifdef F_81
V_192 = F_83 ( V_9 , V_180 , V_179 ) ;
#else
int V_57 ;
F_61 ( V_214 , L_89 , V_179 ) ;
if ( ! ( V_192 = F_83 ( V_9 , V_180 , V_179 ) ) ) {
if ( ! ( V_56 -> V_78 & V_122 ) ) {
V_57 = 20000 ;
while ( ! ( F_9 ( V_29 ) & V_212 ) && ( F_9 ( V_29 ) & V_153 ) ) ;
if ( ! V_57 )
F_61 ( V_215 , L_90 , V_9 -> V_37 ) ;
if ( V_56 -> V_78 & V_123 ) {
V_56 -> V_78 &= ~ V_123 ;
if ( F_9 ( V_68 ) & V_216 ) {
V_56 -> V_78 |= V_122 ;
F_61 ( V_215 , L_91 , V_9 -> V_37 ) ;
}
}
} else {
F_61 ( V_214 , L_92 ) ;
while ( ! ( F_9 ( V_68 ) & V_216 ) ) ;
F_61 ( V_214 , L_93 ) ;
}
}
#endif
}
F_23 ( V_27 , V_127 ) ;
F_23 ( V_28 , V_72 ) ;
if ( ( ! ( V_178 & V_147 ) ) && ( V_56 -> V_78 & V_79 ) ) {
F_61 ( V_214 , L_94 ) ;
if ( F_9 ( V_29 ) & V_145 ) {
F_61 ( V_214 , L_95 ) ;
F_9 ( V_148 ) ;
} else {
F_15 ( L_96 ) ;
}
}
* V_20 = V_180 + V_179 ;
* V_177 = 0 ;
* V_158 = F_9 ( V_26 ) & V_41 ;
#if F_65 ( F_33 ) && F_65 ( F_34 )
F_44 ( V_9 -> V_91 ) ;
#endif
return V_192 ;
#endif
}
static void F_64 ( struct V_8 * V_9 ) {
F_7 () ;
struct V_55 * V_56 = (struct V_55 * )
V_9 -> V_56 ;
unsigned char V_217 ;
unsigned char V_99 , V_158 ;
int V_159 ;
unsigned char V_218 [ 3 ] ;
unsigned char * V_20 ;
T_2 * V_133 = NULL , * V_219 ;
int abort = 0 ;
F_8 ( V_9 ) ;
F_23 ( V_27 , V_127 ) ;
V_56 -> V_163 = 1 ;
V_217 = F_9 ( V_25 ) & ~ ( V_56 -> V_70 ) ;
F_61 ( V_173 , L_97 , V_9 -> V_37 ) ;
F_23 ( V_28 , V_72 | V_171 ) ;
if( F_6 ( V_9 , V_26 , V_146 , 0 , 2 * V_66 ) < 0 )
abort = 1 ;
F_23 ( V_28 , V_72 ) ;
if( F_6 ( V_9 , V_26 , V_36 , V_36 , 2 * V_66 ) )
abort = 1 ;
V_159 = 1 ;
V_20 = V_218 ;
V_158 = V_188 ;
F_74 ( V_9 , & V_158 , & V_159 , & V_20 ) ;
if ( ! ( V_218 [ 0 ] & 0x80 ) ) {
F_15 ( V_105 L_98 , V_9 -> V_37 ) ;
F_84 ( V_218 ) ;
abort = 1 ;
} else {
F_23 ( V_28 , V_72 ) ;
V_99 = ( V_218 [ 0 ] & 0x07 ) ;
for ( V_133 = ( T_2 * ) V_56 -> V_95 , V_219 = NULL ; V_133 ; V_219 = V_133 , V_133 = ( T_2 * ) V_133 -> V_94 )
if ( ( V_217 == ( 1 << V_133 -> V_96 -> V_98 ) ) && ( V_99 == ( V_220 ) V_133 -> V_96 -> V_99 )
) {
if ( V_219 ) {
REMOVE ( V_219 , V_219 -> V_94 , V_133 , V_133 -> V_94 ) ;
V_219 -> V_94 = V_133 -> V_94 ;
} else {
REMOVE ( - 1 , V_56 -> V_95 , V_133 , V_133 -> V_94 ) ;
V_56 -> V_95 = ( T_2 * ) V_133 -> V_94 ;
}
V_133 -> V_94 = NULL ;
break;
}
if ( ! V_133 ) {
F_15 ( V_105 L_99 , V_9 -> V_37 , V_217 , V_99 ) ;
abort = 1 ;
}
}
if ( abort ) {
F_54 ( V_9 ) ;
} else {
V_56 -> V_92 = V_133 ;
F_61 ( V_221 , L_100 , V_9 -> V_37 , V_133 -> V_96 -> V_98 , V_133 -> V_96 -> V_99 , V_133 -> V_157 ) ;
}
}
static void F_85 ( T_6 * V_9 ) {
F_7 () ;
struct V_55 * V_56 = (struct V_55 * ) V_9 -> V_56 ;
int V_154 ;
F_8 ( V_9 ) ;
F_6 ( V_9 , V_29 , V_156 , 0 , 5 * V_66 ) ;
F_23 ( V_27 , V_127 ) ;
F_23 ( V_28 , V_72 ) ;
if ( ! ( V_56 -> V_92 -> V_2 . V_158 & V_222 ) ) {
V_154 = V_9 -> V_112 - F_67 () ;
V_56 -> V_92 -> V_2 . V_6 -= V_154 ;
V_56 -> V_92 -> V_2 . V_5 += V_154 ;
}
}
static int F_86 ( T_2 * V_1 ) {
F_7 () ;
struct V_8 * V_9 = V_1 -> V_96 -> V_97 ;
struct V_55 * V_56 = (struct V_55 * ) V_9 -> V_56 ;
T_2 * V_133 , * * V_219 ;
F_15 ( V_126 L_101 , V_9 -> V_37 ) ;
F_87 ( V_1 ) ;
F_35 ( V_9 ) ;
F_8 ( V_9 ) ;
F_61 ( V_223 , L_102 , V_9 -> V_37 ) ;
F_61 ( V_223 , L_103 , F_9 ( V_29 ) , F_9 ( V_26 ) ) ;
#if 0
if (hostdata->connected == cmd) {
dprintk(NDEBUG_ABORT, "scsi%d : aborting connected command\n", instance->host_no);
hostdata->aborted = 1;
NCR5380_write(INITIATOR_COMMAND_REG, ICR_ASSERT_ATN);
return 0;
}
#endif
F_61 ( V_223 , L_104 , V_9 -> V_37 ) ;
for ( V_219 = ( T_2 * * ) & ( V_56 -> V_93 ) , V_133 = ( T_2 * ) V_56 -> V_93 ; V_133 ; V_219 = ( T_2 * * ) & ( V_133 -> V_94 ) , V_133 = ( T_2 * ) V_133 -> V_94 )
if ( V_1 == V_133 ) {
REMOVE ( 5 , * V_219 , V_133 , V_133 -> V_94 ) ;
( * V_219 ) = ( T_2 * ) V_133 -> V_94 ;
V_133 -> V_94 = NULL ;
V_133 -> V_136 = V_224 << 16 ;
F_61 ( V_223 , L_105 , V_9 -> V_37 ) ;
V_133 -> V_140 ( V_133 ) ;
return V_225 ;
}
#if ( V_134 & V_223 )
else if ( V_219 == V_133 )
F_15 ( V_105 L_106 , V_9 -> V_37 ) ;
#endif
if ( V_56 -> V_92 ) {
F_61 ( V_223 , L_107 , V_9 -> V_37 ) ;
return V_226 ;
}
for ( V_133 = ( T_2 * ) V_56 -> V_95 ; V_133 ; V_133 = ( T_2 * ) V_133 -> V_94 )
if ( V_1 == V_133 ) {
F_61 ( V_223 , L_108 , V_9 -> V_37 ) ;
if ( F_71 ( V_9 , V_1 , ( int ) V_1 -> V_157 ) )
return V_226 ;
F_61 ( V_223 , L_109 , V_9 -> V_37 ) ;
F_54 ( V_9 ) ;
for ( V_219 = ( T_2 * * ) & ( V_56 -> V_95 ) , V_133 = ( T_2 * ) V_56 -> V_95 ; V_133 ; V_219 = ( T_2 * * ) & ( V_133 -> V_94 ) , V_133 = ( T_2 * ) V_133 -> V_94 )
if ( V_1 == V_133 ) {
REMOVE ( 5 , * V_219 , V_133 , V_133 -> V_94 ) ;
* V_219 = ( T_2 * ) V_133 -> V_94 ;
V_133 -> V_94 = NULL ;
V_133 -> V_136 = V_224 << 16 ;
V_133 -> V_140 ( V_133 ) ;
return V_225 ;
}
}
F_15 ( V_126 L_110
L_111 , V_9 -> V_37 ) ;
return V_226 ;
}
static int F_88 ( T_2 * V_1 )
{
struct V_8 * V_9 = V_1 -> V_96 -> V_97 ;
F_7 () ;
F_8 ( V_9 ) ;
F_35 ( V_9 ) ;
F_44 ( V_9 -> V_91 ) ;
F_55 ( V_9 ) ;
F_46 ( V_9 -> V_91 ) ;
return V_225 ;
}
