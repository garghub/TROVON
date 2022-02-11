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
F_6 ( L_1 ,
F_7 ( V_10 ) , ( unsigned long long ) V_14 ) ;
return V_14 ;
}
static inline void F_8 ( T_1 * V_4 )
{
T_5 V_15 = F_3 ( V_4 ) -> V_16 ;
int V_17 = 1 ;
const char * V_16 , * V_18 , * V_19 = L_2 , * V_20 = L_2 , * V_21 = L_2 ;
switch( V_15 & 0x7 ) {
case V_22 : V_16 = L_3 ; break;
case V_23 : V_16 = L_4 ; break;
case V_24 : V_16 = L_5 ; break;
case V_25 : V_16 = L_6 ; break;
case V_26 : V_16 = L_7 ; break;
default: V_16 = L_8 ;
}
switch( ( V_15 >> V_27 ) & 0x7 ) {
case V_22 : V_18 = L_3 ; break;
case V_23 : V_18 = L_4 ; break;
case V_24 : V_18 = L_5 ; break;
case V_25 : V_18 = L_6 ; break;
case V_26 : V_18 = L_9 ; V_17 = 0 ; break;
default: V_18 = L_10 ; V_17 = 0 ;
}
if ( V_17 ) {
if ( ( V_15 & 7 ) == ( ( V_15 >> V_27 ) & 7 ) ) {
V_20 = ( V_15 & V_28 ) ? L_11 :
L_12 ;
V_21 = ( V_15 & V_29 ) ? L_13 :
L_14 ;
}
V_19 = ( V_15 & V_30 ) ? L_15 : L_16 ;
}
F_9 ( V_4 -> V_2 , L_17 ,
V_18 , V_19 , V_16 , V_20 , V_21 ) ;
if ( V_15 & V_29 )
F_10 ( V_4 -> V_2 ) ;
else
F_11 ( V_4 -> V_2 ) ;
}
static inline void F_12 ( T_1 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
while ( 1 ) {
T_6 * V_31 = & F_3 ( V_4 ) -> V_32 [ V_4 -> V_33 ] ;
struct V_34 * V_35 = V_4 -> V_36 [ V_4 -> V_33 ] ;
switch ( V_31 -> V_37 ) {
case V_38 :
case V_39 :
F_13 ( V_2 ) ;
return;
case V_40 :
V_2 -> V_41 . V_42 ++ ;
V_2 -> V_41 . V_43 ++ ;
break;
default:
V_2 -> V_41 . V_44 ++ ;
V_2 -> V_41 . V_45 += V_35 -> V_46 ;
}
V_31 -> V_37 = V_39 ;
F_14 ( V_4 -> V_5 -> V_10 , V_31 -> V_47 , V_35 -> V_46 ,
V_48 ) ;
F_15 ( V_35 ) ;
V_4 -> V_33 = ( V_4 -> V_33 + 1 ) % V_49 ;
}
}
static inline void F_16 ( T_7 * V_5 )
{
T_6 * V_31 ;
while ( V_31 = & V_5 -> V_6 -> V_50 [ V_5 -> V_51 ] ,
V_31 -> V_37 != V_39 ) {
if ( ( V_31 -> V_37 & V_52 ) > V_5 -> V_53 )
F_6 ( L_18 ,
F_7 ( V_5 -> V_10 ) ) ;
else {
struct V_34 * V_35 = V_5 -> V_54 [ V_5 -> V_51 ] ;
T_1 * V_4 = & V_5 -> V_55 [ V_31 -> V_37 &
V_52 ] ;
struct V_1 * V_2 = V_4 -> V_2 ;
if ( ! V_35 )
V_2 -> V_41 . V_56 ++ ;
else {
F_14 ( V_5 -> V_10 , V_31 -> V_47 ,
V_57 ,
V_58 ) ;
F_17 ( V_35 , V_31 -> V_59 ) ;
#ifdef F_18
F_19 ( V_60 L_19 , V_2 -> V_61 ,
V_35 -> V_46 ) ;
F_20 ( V_35 ) ;
#endif
V_2 -> V_41 . V_62 ++ ;
V_2 -> V_41 . V_63 += V_35 -> V_46 ;
V_35 -> V_64 = F_21 ( V_35 , V_2 ) ;
F_22 ( V_35 ) ;
V_35 = NULL ;
}
if ( ! V_35 ) {
V_35 = F_23 ( V_57 ) ;
V_31 -> V_47 = V_35 ?
F_5 ( V_5 -> V_10 , V_35 -> V_65 ,
V_57 ,
V_58 ) : 0 ;
V_5 -> V_54 [ V_5 -> V_51 ] = V_35 ;
}
}
V_31 -> V_37 = V_39 ;
V_5 -> V_51 = ( V_5 -> V_51 + 1 ) % V_66 ;
}
}
static T_8 F_24 ( int V_67 , void * V_68 )
{
T_7 * V_5 = V_68 ;
int V_69 ;
T_5 V_37 ;
int V_70 = 0 ;
while( ( V_37 = F_25 ( V_5 -> V_71 + V_72 ) ) != 0 ) {
V_70 = 1 ;
F_26 ( V_37 , V_5 -> V_71 + V_72 ) ;
for ( V_69 = 0 ; V_69 < V_5 -> V_53 ; V_69 ++ ) {
if ( V_37 & ( 1 << ( V_73 + V_69 ) ) )
F_12 ( & V_5 -> V_55 [ V_69 ] ) ;
if ( V_37 & ( 1 << ( V_74 + V_69 ) ) )
F_8 ( & V_5 -> V_55 [ V_69 ] ) ;
}
if ( V_37 & ( 1 << V_75 ) )
F_16 ( V_5 ) ;
}
return F_27 ( V_70 ) ;
}
static T_9 F_28 ( struct V_34 * V_35 , struct V_1 * V_2 )
{
T_1 * V_4 = F_1 ( V_2 ) ;
T_6 * V_31 ;
F_29 ( & V_4 -> V_76 ) ;
V_31 = & F_3 ( V_4 ) -> V_32 [ V_4 -> V_77 ] ;
if ( V_31 -> V_37 != V_39 ) {
#ifdef F_18
F_19 ( V_60 L_20 , V_2 -> V_61 ) ;
#endif
F_30 ( V_2 ) ;
F_31 ( & V_4 -> V_76 ) ;
return V_78 ;
}
#ifdef F_18
F_19 ( V_60 L_21 , V_2 -> V_61 , V_35 -> V_46 ) ;
F_20 ( V_35 ) ;
#endif
V_4 -> V_36 [ V_4 -> V_77 ] = V_35 ;
V_31 -> V_47 = F_5 ( V_4 -> V_5 -> V_10 , V_35 -> V_65 , V_35 -> V_46 ,
V_48 ) ;
V_31 -> V_59 = V_35 -> V_46 ;
V_31 -> V_37 = V_38 ;
F_26 ( 1 << ( V_79 + V_4 -> V_8 ) ,
V_4 -> V_5 -> V_71 + V_80 ) ;
V_4 -> V_77 = ( V_4 -> V_77 + 1 ) % V_49 ;
if ( F_3 ( V_4 ) -> V_32 [ V_4 -> V_77 ] . V_37 != V_39 ) {
F_30 ( V_2 ) ;
#ifdef F_18
F_19 ( V_60 L_20 , V_2 -> V_61 ) ;
#endif
}
F_31 ( & V_4 -> V_76 ) ;
return V_81 ;
}
static int F_32 ( struct V_1 * V_2 , unsigned short V_82 ,
unsigned short V_83 )
{
T_1 * V_4 = F_1 ( V_2 ) ;
if ( V_82 != V_84 &&
V_82 != V_85 )
return - V_86 ;
if ( V_83 != V_87 &&
V_83 != V_88 &&
V_83 != V_89 &&
V_83 != V_90 &&
V_83 != V_91 )
return - V_86 ;
F_3 ( V_4 ) -> V_82 = V_82 ;
F_3 ( V_4 ) -> V_83 = V_83 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , struct V_92 * V_93 , int V_94 )
{
const T_4 V_12 = sizeof( V_95 ) ;
V_95 line ;
T_1 * V_4 = F_1 ( V_2 ) ;
if ( V_94 != V_96 )
return F_34 ( V_2 , V_93 , V_94 ) ;
switch ( V_93 -> V_97 . type ) {
case V_98 :
V_93 -> V_97 . type = V_99 ;
if ( V_93 -> V_97 . V_12 < V_12 ) {
V_93 -> V_97 . V_12 = V_12 ;
return - V_100 ;
}
line . V_101 = F_3 ( V_4 ) -> V_102 ;
line . V_103 = 0 ;
line . V_104 = 0 ;
if ( F_35 ( V_93 -> V_97 . V_105 . V_106 , & line , V_12 ) )
return - V_107 ;
return 0 ;
case V_99 :
if ( ! F_36 ( V_108 ) )
return - V_109 ;
if ( V_2 -> V_110 & V_111 )
return - V_112 ;
if ( F_37 ( & line , V_93 -> V_97 . V_105 . V_106 ,
V_12 ) )
return - V_107 ;
if ( line . V_101 != V_113 &&
line . V_101 != V_114 )
return - V_86 ;
if ( line . V_104 != 0 )
return - V_86 ;
F_3 ( V_4 ) -> V_102 = line . V_101 ;
return 0 ;
default:
return F_34 ( V_2 , V_93 , V_94 ) ;
}
}
static int F_38 ( struct V_1 * V_2 )
{
T_1 * V_4 = F_1 ( V_2 ) ;
T_10 T_11 * V_115 = V_4 -> V_5 -> V_71 + V_80 ;
unsigned long V_116 ;
int V_69 ;
if ( F_3 ( V_4 ) -> V_117 ) {
F_39 ( V_2 , L_22 ) ;
return - V_118 ;
}
if ( ( V_69 = F_40 ( V_2 ) ) != 0 )
return V_69 ;
V_4 -> V_33 = V_4 -> V_77 = 0 ;
for ( V_69 = 0 ; V_69 < V_49 ; V_69 ++ )
F_3 ( V_4 ) -> V_32 [ V_69 ] . V_37 = V_39 ;
F_26 ( 1 << ( V_119 + V_4 -> V_8 ) , V_115 ) ;
V_116 = V_120 + V_121 ;
do {
if ( F_3 ( V_4 ) -> V_117 ) {
F_41 ( V_2 ) ;
return 0 ;
}
} while ( F_42 ( V_116 , V_120 ) );
F_39 ( V_2 , L_23 ) ;
F_26 ( 1 << ( V_122 + V_4 -> V_8 ) , V_115 ) ;
return - V_107 ;
}
static int F_43 ( struct V_1 * V_2 )
{
T_1 * V_4 = F_1 ( V_2 ) ;
unsigned long V_116 ;
int V_69 ;
F_44 ( V_2 ) ;
F_26 ( 1 << ( V_122 + V_4 -> V_8 ) ,
V_4 -> V_5 -> V_71 + V_80 ) ;
V_116 = V_120 + V_121 ;
do {
if ( ! F_3 ( V_4 ) -> V_117 )
break;
} while ( F_42 ( V_116 , V_120 ) );
if ( F_3 ( V_4 ) -> V_117 )
F_39 ( V_2 , L_24 ) ;
F_30 ( V_2 ) ;
for ( V_69 = 0 ; V_69 < V_49 ; V_69 ++ ) {
T_6 * V_31 = & F_3 ( V_4 ) -> V_32 [ V_69 ] ;
if ( V_31 -> V_37 != V_39 ) {
V_31 -> V_37 = V_39 ;
F_14 ( V_4 -> V_5 -> V_10 , V_31 -> V_47 ,
V_4 -> V_36 [ V_69 ] -> V_46 ,
V_48 ) ;
F_45 ( V_4 -> V_36 [ V_69 ] ) ;
}
}
return 0 ;
}
static struct V_123 * F_46 ( struct V_1 * V_2 )
{
T_1 * V_4 = F_1 ( V_2 ) ;
V_2 -> V_41 . V_124 = F_3 ( V_4 ) -> V_125 ;
V_2 -> V_41 . V_126 = F_3 ( V_4 ) -> V_126 ;
V_2 -> V_41 . V_127 = V_2 -> V_41 . V_124 +
V_2 -> V_41 . V_126 ;
return & V_2 -> V_41 ;
}
static int F_47 ( T_7 * V_5 , T_5 V_94 )
{
unsigned long V_116 = V_120 + 5 * V_121 ;
F_26 ( V_94 , V_5 -> V_71 + V_128 ) ;
do {
if ( F_25 ( V_5 -> V_71 + V_128 ) == 0 )
return 0 ;
F_48 () ;
}while ( F_42 ( V_116 , V_120 ) );
return - 1 ;
}
static void F_49 ( T_7 * V_5 )
{
T_5 V_129 = F_25 ( V_5 -> V_71 + V_130 ) & ~ V_131 ;
F_26 ( 0x80 , V_5 -> V_71 + V_132 ) ;
F_26 ( V_129 | V_131 , V_5 -> V_71 + V_130 ) ;
F_25 ( V_5 -> V_71 + V_130 ) ;
F_50 ( 1 ) ;
F_26 ( V_129 , V_5 -> V_71 + V_130 ) ;
F_25 ( V_5 -> V_71 + V_130 ) ;
}
static void F_51 ( struct V_9 * V_10 )
{
T_7 * V_5 = F_52 ( V_10 ) ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_5 -> V_53 ; V_69 ++ ) {
F_53 ( V_5 -> V_55 [ V_69 ] . V_2 ) ;
F_54 ( V_5 -> V_55 [ V_69 ] . V_2 ) ;
}
if ( V_5 -> V_67 )
F_55 ( V_5 -> V_67 , V_5 ) ;
F_49 ( V_5 ) ;
for ( V_69 = 0 ; V_69 < V_66 ; V_69 ++ )
if ( V_5 -> V_54 [ V_69 ] ) {
F_14 ( V_5 -> V_10 ,
V_5 -> V_6 -> V_50 [ V_69 ] . V_47 ,
V_57 , V_58 ) ;
F_45 ( V_5 -> V_54 [ V_69 ] ) ;
}
if ( V_5 -> V_71 )
F_56 ( V_5 -> V_71 ) ;
if ( V_5 -> V_6 )
F_57 ( V_10 , sizeof( V_133 ) ,
V_5 -> V_6 , V_5 -> V_134 ) ;
F_58 ( V_10 ) ;
F_59 ( V_10 ) ;
F_60 ( V_10 , NULL ) ;
F_61 ( V_5 ) ;
}
static int F_62 ( struct V_9 * V_10 ,
const struct V_135 * V_136 )
{
T_7 * V_5 ;
T_5 V_137 , V_37 ;
unsigned long V_116 ;
T_5 V_138 ;
T_5 V_139 ;
T_10 T_11 * V_140 ;
int V_69 , V_55 , V_141 ;
#ifndef F_63
F_64 ( L_25 , V_142 ) ;
#endif
V_69 = F_65 ( V_10 ) ;
if ( V_69 )
return V_69 ;
if ( F_66 ( V_10 , F_67 ( 28 ) ) ||
F_68 ( V_10 , F_67 ( 28 ) ) ) {
F_69 ( L_26 ) ;
return - V_118 ;
}
V_69 = F_70 ( V_10 , L_27 ) ;
if ( V_69 ) {
F_59 ( V_10 ) ;
return V_69 ;
}
switch ( V_10 -> V_143 ) {
case V_144 : V_55 = 1 ; break;
case V_145 : V_55 = 2 ; break;
default: V_55 = 4 ;
}
V_141 = sizeof( T_7 ) + V_55 * sizeof( T_1 ) ;
V_5 = F_71 ( V_141 , V_146 ) ;
if ( V_5 == NULL ) {
F_58 ( V_10 ) ;
F_59 ( V_10 ) ;
return - V_100 ;
}
F_60 ( V_10 , V_5 ) ;
V_5 -> V_10 = V_10 ;
V_5 -> V_6 = F_72 ( V_10 , sizeof( V_133 ) ,
& V_5 -> V_134 ) ;
if ( V_5 -> V_6 == NULL ) {
F_51 ( V_10 ) ;
return - V_100 ;
}
#ifdef F_73
F_19 ( V_60 L_28
L_29 , F_7 ( V_10 ) ,
( unsigned long long ) V_5 -> V_134 ) ;
#endif
if ( F_66 ( V_10 , F_67 ( 32 ) ) ||
F_68 ( V_10 , F_67 ( 32 ) ) ) {
F_69 ( L_26 ) ;
F_51 ( V_10 ) ;
return - V_118 ;
}
V_138 = F_74 ( V_10 , 0 ) ;
V_5 -> V_71 = F_75 ( V_138 , 0x70 ) ;
if ( ! V_5 -> V_71 ) {
F_69 ( L_30 ) ;
F_51 ( V_10 ) ;
return - V_107 ;
}
#if V_147
F_49 ( V_5 ) ;
#endif
V_116 = V_120 + 20 * V_121 ;
while ( ( V_37 = F_25 ( V_5 -> V_71 + V_132 ) ) != 0 ) {
if ( F_76 ( V_116 , V_120 ) ) {
F_77 ( L_31 ,
F_7 ( V_10 ) ) ;
F_51 ( V_10 ) ;
return - V_148 ;
}
switch( V_37 & 0xC0 ) {
case 0x00 :
case 0x80 :
break;
default:
F_77 ( L_32 ,
F_7 ( V_10 ) , V_37 & 0x30 ) ;
F_51 ( V_10 ) ;
return - V_148 ;
}
F_48 () ;
}
V_137 = F_25 ( V_5 -> V_71 + V_149 ) & V_150 ;
V_139 = F_74 ( V_10 , 2 ) ;
if ( V_137 < V_151 +
( V_49 + V_152 ) * V_57 * V_55 ) {
F_77 ( L_33 ,
F_7 ( V_10 ) , V_137 ,
V_151 +
( V_49 + V_152 ) * V_57 * V_55 ) ;
F_51 ( V_10 ) ;
return - V_148 ;
}
if ( F_47 ( V_5 , V_153 ) ) {
F_77 ( L_34 , F_7 ( V_10 ) ) ;
F_51 ( V_10 ) ;
return - V_148 ;
}
for ( V_69 = 0 ; V_69 < V_66 ; V_69 ++ ) {
struct V_34 * V_35 = F_23 ( V_57 ) ;
V_5 -> V_54 [ V_69 ] = V_35 ;
if ( V_35 )
V_5 -> V_6 -> V_50 [ V_69 ] . V_47 =
F_5 ( V_5 -> V_10 , V_35 -> V_65 ,
V_57 ,
V_58 ) ;
}
V_140 = F_75 ( V_139 , V_154 + sizeof( V_155 ) ) ;
if ( ! V_140 ) {
F_69 ( L_30 ) ;
F_51 ( V_10 ) ;
return - V_107 ;
}
for ( V_69 = 0 ; V_69 < sizeof( V_155 ) ; V_69 += 4 )
F_26 ( F_78 ( * ( V_156 * ) ( V_155 + V_69 ) ) , V_140 + V_154 + V_69 ) ;
for ( V_69 = 0 ; V_69 < V_55 ; V_69 ++ )
F_26 ( V_5 -> V_134 +
( void * ) & V_5 -> V_6 -> V_7 [ V_69 ] -
( void * ) V_5 -> V_6 , V_140 + V_154 + 4 + V_69 * 4 ) ;
F_26 ( V_5 -> V_134 , V_140 + V_154 + 20 ) ;
F_26 ( V_154 , V_140 ) ;
F_56 ( V_140 ) ;
F_26 ( 0 , V_5 -> V_71 + V_157 ) ;
if ( F_47 ( V_5 , V_158 ) ) {
F_77 ( L_35 , F_7 ( V_10 ) ) ;
F_51 ( V_10 ) ;
return - V_148 ;
}
V_37 = 0 ;
V_116 = V_120 + 5 * V_121 ;
do {
if ( ( V_37 = F_25 ( V_5 -> V_71 + V_157 ) ) != 0 )
break;
F_48 () ;
}while ( F_42 ( V_116 , V_120 ) );
if ( ! V_37 ) {
F_77 ( L_36 ,
F_7 ( V_10 ) ) ;
F_51 ( V_10 ) ;
return - V_148 ;
}
#if V_159
V_137 = V_37 ;
#endif
F_79 ( L_37 ,
F_7 ( V_10 ) , V_138 , V_137 / 1024 , V_139 , V_10 -> V_67 ) ;
if ( F_80 ( V_10 -> V_67 , F_24 , V_160 , L_27 , V_5 ) ) {
F_77 ( L_38 ,
F_7 ( V_10 ) , V_10 -> V_67 ) ;
F_51 ( V_10 ) ;
return - V_112 ;
}
V_5 -> V_67 = V_10 -> V_67 ;
for ( V_69 = 0 ; V_69 < V_55 ; V_69 ++ ) {
T_12 * V_161 ;
T_1 * V_4 = & V_5 -> V_55 [ V_69 ] ;
struct V_1 * V_2 = F_81 ( V_4 ) ;
if ( ! V_2 ) {
F_69 ( L_39 ,
F_7 ( V_10 ) ) ;
F_51 ( V_10 ) ;
return - V_162 ;
}
V_4 -> V_2 = V_2 ;
V_161 = F_2 ( V_2 ) ;
F_82 ( & V_4 -> V_76 ) ;
V_2 -> V_163 = 50 ;
V_2 -> V_164 = & V_165 ;
V_161 -> V_166 = F_32 ;
V_161 -> V_167 = F_28 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_8 = V_69 ;
F_3 ( V_4 ) -> V_102 = V_113 ;
if ( F_83 ( V_2 ) ) {
F_69 ( L_40 ,
F_7 ( V_10 ) ) ;
F_54 ( V_2 ) ;
F_51 ( V_10 ) ;
return - V_100 ;
}
V_5 -> V_53 ++ ;
}
F_79 ( L_41 , F_7 ( V_10 ) ) ;
for ( V_69 = 0 ; V_69 < V_55 ; V_69 ++ )
F_84 ( L_42 ,
V_69 ? L_43 : L_2 , V_69 , V_5 -> V_55 [ V_69 ] . V_2 -> V_61 ) ;
F_84 ( L_44 ) ;
for ( V_69 = 0 ; V_69 < V_55 ; V_69 ++ )
F_8 ( & V_5 -> V_55 [ V_69 ] ) ;
return 0 ;
}
static int T_13 F_85 ( void )
{
#ifdef F_63
F_79 ( L_25 , V_142 ) ;
#endif
return F_86 ( & V_168 ) ;
}
static void T_14 F_87 ( void )
{
F_88 ( & V_168 ) ;
}
