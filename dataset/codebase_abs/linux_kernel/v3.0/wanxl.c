static inline T_1 * F_1 ( struct V_1 * V_2 )
{
return ( T_1 * ) F_2 ( V_2 ) -> V_3 ;
}
static inline T_2 * F_3 ( T_1 * V_4 )
{
return & V_4 -> V_5 -> V_6 -> V_7 [ V_4 -> V_8 ] ;
}
static inline T_3 F_4 ( struct V_9 * V_10 , void * V_11 ,
T_4 V_12 , int V_13 )
{
T_3 V_14 = F_5 ( V_10 , V_11 , V_12 , V_13 ) ;
if ( V_14 + V_12 > 0x100000000LL )
F_6 ( V_15 L_1
L_2 , F_7 ( V_10 ) ,
( unsigned long long ) V_14 ) ;
return V_14 ;
}
static inline void F_8 ( T_1 * V_4 )
{
T_5 V_16 = F_3 ( V_4 ) -> V_17 ;
int V_18 = 1 ;
const char * V_17 , * V_19 , * V_20 = L_3 , * V_21 = L_3 , * V_22 = L_3 ;
switch( V_16 & 0x7 ) {
case V_23 : V_17 = L_4 ; break;
case V_24 : V_17 = L_5 ; break;
case V_25 : V_17 = L_6 ; break;
case V_26 : V_17 = L_7 ; break;
case V_27 : V_17 = L_8 ; break;
default: V_17 = L_9 ;
}
switch( ( V_16 >> V_28 ) & 0x7 ) {
case V_23 : V_19 = L_4 ; break;
case V_24 : V_19 = L_5 ; break;
case V_25 : V_19 = L_6 ; break;
case V_26 : V_19 = L_7 ; break;
case V_27 : V_19 = L_10 ; V_18 = 0 ; break;
default: V_19 = L_11 ; V_18 = 0 ;
}
if ( V_18 ) {
if ( ( V_16 & 7 ) == ( ( V_16 >> V_28 ) & 7 ) ) {
V_21 = ( V_16 & V_29 ) ? L_12 :
L_13 ;
V_22 = ( V_16 & V_30 ) ? L_14 :
L_15 ;
}
V_20 = ( V_16 & V_31 ) ? L_16 : L_17 ;
}
F_6 ( V_32 L_18 ,
V_4 -> V_2 -> V_33 , V_19 , V_20 , V_17 , V_21 , V_22 ) ;
if ( V_16 & V_30 )
F_9 ( V_4 -> V_2 ) ;
else
F_10 ( V_4 -> V_2 ) ;
}
static inline void F_11 ( T_1 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
while ( 1 ) {
T_6 * V_34 = & F_3 ( V_4 ) -> V_35 [ V_4 -> V_36 ] ;
struct V_37 * V_38 = V_4 -> V_39 [ V_4 -> V_36 ] ;
switch ( V_34 -> V_40 ) {
case V_41 :
case V_42 :
F_12 ( V_2 ) ;
return;
case V_43 :
V_2 -> V_44 . V_45 ++ ;
V_2 -> V_44 . V_46 ++ ;
break;
default:
V_2 -> V_44 . V_47 ++ ;
V_2 -> V_44 . V_48 += V_38 -> V_49 ;
}
V_34 -> V_40 = V_42 ;
F_13 ( V_4 -> V_5 -> V_10 , V_34 -> V_50 , V_38 -> V_49 ,
V_51 ) ;
F_14 ( V_38 ) ;
V_4 -> V_36 = ( V_4 -> V_36 + 1 ) % V_52 ;
}
}
static inline void F_15 ( T_7 * V_5 )
{
T_6 * V_34 ;
while ( V_34 = & V_5 -> V_6 -> V_53 [ V_5 -> V_54 ] ,
V_34 -> V_40 != V_42 ) {
if ( ( V_34 -> V_40 & V_55 ) > V_5 -> V_56 )
F_6 ( V_15 L_19
L_20 , F_7 ( V_5 -> V_10 ) ) ;
else {
struct V_37 * V_38 = V_5 -> V_57 [ V_5 -> V_54 ] ;
T_1 * V_4 = & V_5 -> V_58 [ V_34 -> V_40 &
V_55 ] ;
struct V_1 * V_2 = V_4 -> V_2 ;
if ( ! V_38 )
V_2 -> V_44 . V_59 ++ ;
else {
F_13 ( V_5 -> V_10 , V_34 -> V_50 ,
V_60 ,
V_61 ) ;
F_16 ( V_38 , V_34 -> V_62 ) ;
#ifdef F_17
F_6 ( V_63 L_21 , V_2 -> V_33 ,
V_38 -> V_49 ) ;
F_18 ( V_38 ) ;
#endif
V_2 -> V_44 . V_64 ++ ;
V_2 -> V_44 . V_65 += V_38 -> V_49 ;
V_38 -> V_66 = F_19 ( V_38 , V_2 ) ;
F_20 ( V_38 ) ;
V_38 = NULL ;
}
if ( ! V_38 ) {
V_38 = F_21 ( V_60 ) ;
V_34 -> V_50 = V_38 ?
F_5 ( V_5 -> V_10 , V_38 -> V_67 ,
V_60 ,
V_61 ) : 0 ;
V_5 -> V_57 [ V_5 -> V_54 ] = V_38 ;
}
}
V_34 -> V_40 = V_42 ;
V_5 -> V_54 = ( V_5 -> V_54 + 1 ) % V_68 ;
}
}
static T_8 F_22 ( int V_69 , void * V_70 )
{
T_7 * V_5 = V_70 ;
int V_71 ;
T_5 V_40 ;
int V_72 = 0 ;
while( ( V_40 = F_23 ( V_5 -> V_73 + V_74 ) ) != 0 ) {
V_72 = 1 ;
F_24 ( V_40 , V_5 -> V_73 + V_74 ) ;
for ( V_71 = 0 ; V_71 < V_5 -> V_56 ; V_71 ++ ) {
if ( V_40 & ( 1 << ( V_75 + V_71 ) ) )
F_11 ( & V_5 -> V_58 [ V_71 ] ) ;
if ( V_40 & ( 1 << ( V_76 + V_71 ) ) )
F_8 ( & V_5 -> V_58 [ V_71 ] ) ;
}
if ( V_40 & ( 1 << V_77 ) )
F_15 ( V_5 ) ;
}
return F_25 ( V_72 ) ;
}
static T_9 F_26 ( struct V_37 * V_38 , struct V_1 * V_2 )
{
T_1 * V_4 = F_1 ( V_2 ) ;
T_6 * V_34 ;
F_27 ( & V_4 -> V_78 ) ;
V_34 = & F_3 ( V_4 ) -> V_35 [ V_4 -> V_79 ] ;
if ( V_34 -> V_40 != V_42 ) {
#ifdef F_17
F_6 ( V_63 L_22 , V_2 -> V_33 ) ;
#endif
F_28 ( V_2 ) ;
F_29 ( & V_4 -> V_78 ) ;
return V_80 ;
}
#ifdef F_17
F_6 ( V_63 L_23 , V_2 -> V_33 , V_38 -> V_49 ) ;
F_18 ( V_38 ) ;
#endif
V_4 -> V_39 [ V_4 -> V_79 ] = V_38 ;
V_34 -> V_50 = F_5 ( V_4 -> V_5 -> V_10 , V_38 -> V_67 , V_38 -> V_49 ,
V_51 ) ;
V_34 -> V_62 = V_38 -> V_49 ;
V_34 -> V_40 = V_41 ;
F_24 ( 1 << ( V_81 + V_4 -> V_8 ) ,
V_4 -> V_5 -> V_73 + V_82 ) ;
V_4 -> V_79 = ( V_4 -> V_79 + 1 ) % V_52 ;
if ( F_3 ( V_4 ) -> V_35 [ V_4 -> V_79 ] . V_40 != V_42 ) {
F_28 ( V_2 ) ;
#ifdef F_17
F_6 ( V_63 L_22 , V_2 -> V_33 ) ;
#endif
}
F_30 ( & V_4 -> V_78 ) ;
return V_83 ;
}
static int F_31 ( struct V_1 * V_2 , unsigned short V_84 ,
unsigned short V_85 )
{
T_1 * V_4 = F_1 ( V_2 ) ;
if ( V_84 != V_86 &&
V_84 != V_87 )
return - V_88 ;
if ( V_85 != V_89 &&
V_85 != V_90 &&
V_85 != V_91 &&
V_85 != V_92 &&
V_85 != V_93 )
return - V_88 ;
F_3 ( V_4 ) -> V_84 = V_84 ;
F_3 ( V_4 ) -> V_85 = V_85 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , struct V_94 * V_95 , int V_96 )
{
const T_4 V_12 = sizeof( V_97 ) ;
V_97 line ;
T_1 * V_4 = F_1 ( V_2 ) ;
if ( V_96 != V_98 )
return F_33 ( V_2 , V_95 , V_96 ) ;
switch ( V_95 -> V_99 . type ) {
case V_100 :
V_95 -> V_99 . type = V_101 ;
if ( V_95 -> V_99 . V_12 < V_12 ) {
V_95 -> V_99 . V_12 = V_12 ;
return - V_102 ;
}
line . V_103 = F_3 ( V_4 ) -> V_104 ;
line . V_105 = 0 ;
line . V_106 = 0 ;
if ( F_34 ( V_95 -> V_99 . V_107 . V_108 , & line , V_12 ) )
return - V_109 ;
return 0 ;
case V_101 :
if ( ! F_35 ( V_110 ) )
return - V_111 ;
if ( V_2 -> V_112 & V_113 )
return - V_114 ;
if ( F_36 ( & line , V_95 -> V_99 . V_107 . V_108 ,
V_12 ) )
return - V_109 ;
if ( line . V_103 != V_115 &&
line . V_103 != V_116 )
return - V_88 ;
if ( line . V_106 != 0 )
return - V_88 ;
F_3 ( V_4 ) -> V_104 = line . V_103 ;
return 0 ;
default:
return F_33 ( V_2 , V_95 , V_96 ) ;
}
}
static int F_37 ( struct V_1 * V_2 )
{
T_1 * V_4 = F_1 ( V_2 ) ;
T_10 T_11 * V_117 = V_4 -> V_5 -> V_73 + V_82 ;
unsigned long V_118 ;
int V_71 ;
if ( F_3 ( V_4 ) -> V_119 ) {
F_6 ( V_120 L_24 , V_2 -> V_33 ) ;
return - V_121 ;
}
if ( ( V_71 = F_38 ( V_2 ) ) != 0 )
return V_71 ;
V_4 -> V_36 = V_4 -> V_79 = 0 ;
for ( V_71 = 0 ; V_71 < V_52 ; V_71 ++ )
F_3 ( V_4 ) -> V_35 [ V_71 ] . V_40 = V_42 ;
F_24 ( 1 << ( V_122 + V_4 -> V_8 ) , V_117 ) ;
V_118 = V_123 + V_124 ;
do {
if ( F_3 ( V_4 ) -> V_119 ) {
F_39 ( V_2 ) ;
return 0 ;
}
} while ( F_40 ( V_118 , V_123 ) );
F_6 ( V_120 L_25 , V_2 -> V_33 ) ;
F_24 ( 1 << ( V_125 + V_4 -> V_8 ) , V_117 ) ;
return - V_109 ;
}
static int F_41 ( struct V_1 * V_2 )
{
T_1 * V_4 = F_1 ( V_2 ) ;
unsigned long V_118 ;
int V_71 ;
F_42 ( V_2 ) ;
F_24 ( 1 << ( V_125 + V_4 -> V_8 ) ,
V_4 -> V_5 -> V_73 + V_82 ) ;
V_118 = V_123 + V_124 ;
do {
if ( ! F_3 ( V_4 ) -> V_119 )
break;
} while ( F_40 ( V_118 , V_123 ) );
if ( F_3 ( V_4 ) -> V_119 )
F_6 ( V_120 L_26 , V_2 -> V_33 ) ;
F_28 ( V_2 ) ;
for ( V_71 = 0 ; V_71 < V_52 ; V_71 ++ ) {
T_6 * V_34 = & F_3 ( V_4 ) -> V_35 [ V_71 ] ;
if ( V_34 -> V_40 != V_42 ) {
V_34 -> V_40 = V_42 ;
F_13 ( V_4 -> V_5 -> V_10 , V_34 -> V_50 ,
V_4 -> V_39 [ V_71 ] -> V_49 ,
V_51 ) ;
F_43 ( V_4 -> V_39 [ V_71 ] ) ;
}
}
return 0 ;
}
static struct V_126 * F_44 ( struct V_1 * V_2 )
{
T_1 * V_4 = F_1 ( V_2 ) ;
V_2 -> V_44 . V_127 = F_3 ( V_4 ) -> V_128 ;
V_2 -> V_44 . V_129 = F_3 ( V_4 ) -> V_129 ;
V_2 -> V_44 . V_130 = V_2 -> V_44 . V_127 +
V_2 -> V_44 . V_129 ;
return & V_2 -> V_44 ;
}
static int F_45 ( T_7 * V_5 , T_5 V_96 )
{
unsigned long V_118 = V_123 + 5 * V_124 ;
F_24 ( V_96 , V_5 -> V_73 + V_131 ) ;
do {
if ( F_23 ( V_5 -> V_73 + V_131 ) == 0 )
return 0 ;
F_46 () ;
}while ( F_40 ( V_118 , V_123 ) );
return - 1 ;
}
static void F_47 ( T_7 * V_5 )
{
T_5 V_132 = F_23 ( V_5 -> V_73 + V_133 ) & ~ V_134 ;
F_24 ( 0x80 , V_5 -> V_73 + V_135 ) ;
F_24 ( V_132 | V_134 , V_5 -> V_73 + V_133 ) ;
F_23 ( V_5 -> V_73 + V_133 ) ;
F_48 ( 1 ) ;
F_24 ( V_132 , V_5 -> V_73 + V_133 ) ;
F_23 ( V_5 -> V_73 + V_133 ) ;
}
static void F_49 ( struct V_9 * V_10 )
{
T_7 * V_5 = F_50 ( V_10 ) ;
int V_71 ;
for ( V_71 = 0 ; V_71 < V_5 -> V_56 ; V_71 ++ ) {
F_51 ( V_5 -> V_58 [ V_71 ] . V_2 ) ;
F_52 ( V_5 -> V_58 [ V_71 ] . V_2 ) ;
}
if ( V_5 -> V_69 )
F_53 ( V_5 -> V_69 , V_5 ) ;
F_47 ( V_5 ) ;
for ( V_71 = 0 ; V_71 < V_68 ; V_71 ++ )
if ( V_5 -> V_57 [ V_71 ] ) {
F_13 ( V_5 -> V_10 ,
V_5 -> V_6 -> V_53 [ V_71 ] . V_50 ,
V_60 , V_61 ) ;
F_43 ( V_5 -> V_57 [ V_71 ] ) ;
}
if ( V_5 -> V_73 )
F_54 ( V_5 -> V_73 ) ;
if ( V_5 -> V_6 )
F_55 ( V_10 , sizeof( V_136 ) ,
V_5 -> V_6 , V_5 -> V_137 ) ;
F_56 ( V_10 ) ;
F_57 ( V_10 ) ;
F_58 ( V_10 , NULL ) ;
F_59 ( V_5 ) ;
}
static int T_12 F_60 ( struct V_9 * V_10 ,
const struct V_138 * V_139 )
{
T_7 * V_5 ;
T_5 V_140 , V_40 ;
unsigned long V_118 ;
T_5 V_141 ;
T_5 V_142 ;
T_10 T_11 * V_143 ;
int V_71 , V_58 , V_144 ;
#ifndef F_61
static int V_145 ;
if ( ! V_145 ) {
V_145 ++ ;
F_6 ( V_32 L_27 , V_146 ) ;
}
#endif
V_71 = F_62 ( V_10 ) ;
if ( V_71 )
return V_71 ;
if ( F_63 ( V_10 , F_64 ( 28 ) ) ||
F_65 ( V_10 , F_64 ( 28 ) ) ) {
F_6 ( V_120 L_28 ) ;
return - V_121 ;
}
V_71 = F_66 ( V_10 , L_29 ) ;
if ( V_71 ) {
F_57 ( V_10 ) ;
return V_71 ;
}
switch ( V_10 -> V_147 ) {
case V_148 : V_58 = 1 ; break;
case V_149 : V_58 = 2 ; break;
default: V_58 = 4 ;
}
V_144 = sizeof( T_7 ) + V_58 * sizeof( T_1 ) ;
V_5 = F_67 ( V_144 , V_150 ) ;
if ( V_5 == NULL ) {
F_6 ( V_120 L_30 ,
F_7 ( V_10 ) ) ;
F_56 ( V_10 ) ;
F_57 ( V_10 ) ;
return - V_102 ;
}
F_58 ( V_10 , V_5 ) ;
V_5 -> V_10 = V_10 ;
V_5 -> V_6 = F_68 ( V_10 , sizeof( V_136 ) ,
& V_5 -> V_137 ) ;
if ( V_5 -> V_6 == NULL ) {
F_49 ( V_10 ) ;
return - V_102 ;
}
#ifdef F_69
F_6 ( V_63 L_31
L_32 , F_7 ( V_10 ) ,
( unsigned long long ) V_5 -> V_137 ) ;
#endif
if ( F_63 ( V_10 , F_64 ( 32 ) ) ||
F_65 ( V_10 , F_64 ( 32 ) ) ) {
F_6 ( V_120 L_28 ) ;
F_49 ( V_10 ) ;
return - V_121 ;
}
V_141 = F_70 ( V_10 , 0 ) ;
V_5 -> V_73 = F_71 ( V_141 , 0x70 ) ;
if ( ! V_5 -> V_73 ) {
F_6 ( V_120 L_33 ) ;
F_49 ( V_10 ) ;
return - V_109 ;
}
#if V_151
F_47 ( V_5 ) ;
#endif
V_118 = V_123 + 20 * V_124 ;
while ( ( V_40 = F_23 ( V_5 -> V_73 + V_135 ) ) != 0 ) {
if ( F_72 ( V_118 , V_123 ) ) {
F_6 ( V_152 L_34
L_35 , F_7 ( V_10 ) ) ;
F_49 ( V_10 ) ;
return - V_153 ;
}
switch( V_40 & 0xC0 ) {
case 0x00 :
case 0x80 :
break;
default:
F_6 ( V_152 L_36
L_37 , F_7 ( V_10 ) , V_40 & 0x30 ) ;
F_49 ( V_10 ) ;
return - V_153 ;
}
F_46 () ;
}
V_140 = F_23 ( V_5 -> V_73 + V_154 ) & V_155 ;
V_142 = F_70 ( V_10 , 2 ) ;
if ( V_140 < V_156 +
( V_52 + V_157 ) * V_60 * V_58 ) {
F_6 ( V_152 L_38
L_39 ,
F_7 ( V_10 ) , V_140 , V_156 +
( V_52 + V_157 ) * V_60 * V_58 ) ;
F_49 ( V_10 ) ;
return - V_153 ;
}
if ( F_45 ( V_5 , V_158 ) ) {
F_6 ( V_152 L_40
L_41 , F_7 ( V_10 ) ) ;
F_49 ( V_10 ) ;
return - V_153 ;
}
for ( V_71 = 0 ; V_71 < V_68 ; V_71 ++ ) {
struct V_37 * V_38 = F_21 ( V_60 ) ;
V_5 -> V_57 [ V_71 ] = V_38 ;
if ( V_38 )
V_5 -> V_6 -> V_53 [ V_71 ] . V_50 =
F_5 ( V_5 -> V_10 , V_38 -> V_67 ,
V_60 ,
V_61 ) ;
}
V_143 = F_71 ( V_142 , V_159 + sizeof( V_160 ) ) ;
if ( ! V_143 ) {
F_6 ( V_120 L_33 ) ;
F_49 ( V_10 ) ;
return - V_109 ;
}
for ( V_71 = 0 ; V_71 < sizeof( V_160 ) ; V_71 += 4 )
F_24 ( F_73 ( * ( V_161 * ) ( V_160 + V_71 ) ) , V_143 + V_159 + V_71 ) ;
for ( V_71 = 0 ; V_71 < V_58 ; V_71 ++ )
F_24 ( V_5 -> V_137 +
( void * ) & V_5 -> V_6 -> V_7 [ V_71 ] -
( void * ) V_5 -> V_6 , V_143 + V_159 + 4 + V_71 * 4 ) ;
F_24 ( V_5 -> V_137 , V_143 + V_159 + 20 ) ;
F_24 ( V_159 , V_143 ) ;
F_54 ( V_143 ) ;
F_24 ( 0 , V_5 -> V_73 + V_162 ) ;
if ( F_45 ( V_5 , V_163 ) ) {
F_6 ( V_152 L_42 ,
F_7 ( V_10 ) ) ;
F_49 ( V_10 ) ;
return - V_153 ;
}
V_40 = 0 ;
V_118 = V_123 + 5 * V_124 ;
do {
if ( ( V_40 = F_23 ( V_5 -> V_73 + V_162 ) ) != 0 )
break;
F_46 () ;
}while ( F_40 ( V_118 , V_123 ) );
if ( ! V_40 ) {
F_6 ( V_152 L_43
L_44 , F_7 ( V_10 ) ) ;
F_49 ( V_10 ) ;
return - V_153 ;
}
#if V_164
V_140 = V_40 ;
#endif
F_6 ( V_32 L_45 ,
F_7 ( V_10 ) , V_141 , V_140 / 1024 , V_142 , V_10 -> V_69 ) ;
if ( F_74 ( V_10 -> V_69 , F_22 , V_165 , L_29 , V_5 ) ) {
F_6 ( V_152 L_46 ,
F_7 ( V_10 ) , V_10 -> V_69 ) ;
F_49 ( V_10 ) ;
return - V_114 ;
}
V_5 -> V_69 = V_10 -> V_69 ;
for ( V_71 = 0 ; V_71 < V_58 ; V_71 ++ ) {
T_13 * V_166 ;
T_1 * V_4 = & V_5 -> V_58 [ V_71 ] ;
struct V_1 * V_2 = F_75 ( V_4 ) ;
if ( ! V_2 ) {
F_6 ( V_120 L_47
L_48 , F_7 ( V_10 ) ) ;
F_49 ( V_10 ) ;
return - V_167 ;
}
V_4 -> V_2 = V_2 ;
V_166 = F_2 ( V_2 ) ;
F_76 ( & V_4 -> V_78 ) ;
V_2 -> V_168 = 50 ;
V_2 -> V_169 = & V_170 ;
V_166 -> V_171 = F_31 ;
V_166 -> V_172 = F_26 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_8 = V_71 ;
F_3 ( V_4 ) -> V_104 = V_115 ;
if ( F_77 ( V_2 ) ) {
F_6 ( V_120 L_49
L_50 , F_7 ( V_10 ) ) ;
F_52 ( V_2 ) ;
F_49 ( V_10 ) ;
return - V_102 ;
}
V_5 -> V_56 ++ ;
}
F_6 ( V_32 L_51 , F_7 ( V_10 ) ) ;
for ( V_71 = 0 ; V_71 < V_58 ; V_71 ++ )
F_6 ( L_52 , V_71 ? L_53 : L_3 , V_71 ,
V_5 -> V_58 [ V_71 ] . V_2 -> V_33 ) ;
F_6 ( L_54 ) ;
for ( V_71 = 0 ; V_71 < V_58 ; V_71 ++ )
F_8 ( & V_5 -> V_58 [ V_71 ] ) ;
return 0 ;
}
static int T_14 F_78 ( void )
{
#ifdef F_61
F_6 ( V_32 L_27 , V_146 ) ;
#endif
return F_79 ( & V_173 ) ;
}
static void T_15 F_80 ( void )
{
F_81 ( & V_173 ) ;
}
