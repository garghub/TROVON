static inline int F_1 ( struct V_1 * V_2 , int V_3 )
{
return ( V_2 - V_4 -> V_5 ) *
V_6 + V_3 ;
}
static inline unsigned long F_2 ( struct V_1 * V_2 , int V_3 )
{
unsigned long V_7 = F_3 ( V_4 -> V_8 ( V_2 , V_3 ) ) ;
return ( unsigned long ) F_4 ( V_7 ) ;
}
static struct V_1 * F_5 ( void )
{
struct V_1 * V_2 = NULL ;
unsigned long V_9 ;
F_6 ( & V_4 -> V_10 , V_9 ) ;
if ( ! F_7 ( & V_4 -> V_11 ) ) {
V_2 = F_8 ( V_4 -> V_11 . V_12 , struct V_1 ,
V_13 ) ;
F_9 ( & V_2 -> V_13 ) ;
}
F_10 ( & V_4 -> V_10 , V_9 ) ;
return V_2 ;
}
static void F_11 ( struct V_1 * V_2 )
{
unsigned long V_9 ;
int V_14 ;
F_6 ( & V_4 -> V_10 , V_9 ) ;
V_14 = F_7 ( & V_4 -> V_11 ) ;
F_12 ( & V_2 -> V_13 , & V_4 -> V_11 ) ;
F_10 ( & V_4 -> V_10 , V_9 ) ;
if ( V_14 )
F_13 ( & V_4 -> V_15 ) ;
}
static int F_14 ( struct V_16 * V_2 , struct V_17 * V_18 ,
int V_19 )
{
struct V_20 * V_21 = & V_18 -> V_21 ;
int V_22 = - V_23 ;
if ( ( V_19 != V_24 ) && V_21 -> V_25 )
goto V_26;
if ( F_15 ( V_2 -> V_27 ) ) {
T_1 V_28 = V_2 -> V_29 + V_2 -> V_27 ;
if ( F_16 ( V_28 < V_2 -> V_29 ) )
goto V_26;
if ( F_16 ( V_28 > F_17 ( V_21 ) ) )
goto V_26;
}
V_2 -> V_30 = V_21 -> V_31 ;
V_2 -> V_32 = V_21 -> V_32 ;
V_22 = 0 ;
V_26:
return V_22 ;
}
static void F_18 ( struct V_17 * V_18 )
{
struct V_20 * V_21 = & V_18 -> V_21 ;
struct V_33 V_34 ;
int V_35 ;
struct V_36 * V_30 = F_19 ( V_18 -> V_37 ) ;
unsigned long long V_38 = F_17 ( V_21 ) ;
F_20 ( V_39 L_1 ,
V_18 -> V_40 , F_21 ( V_21 -> V_31 ) , F_22 ( V_21 -> V_31 ) ) ;
F_20 ( V_39 L_2 , V_38 ) ;
V_21 -> V_41 = V_38 ;
V_42:
V_35 = F_23 ( & V_34 ) ;
if ( V_35 ) {
F_24 ( V_39 L_3 ) ;
return;
}
V_35 = F_25 ( V_34 , V_30 -> V_43 , L_4 , L_5 ,
( unsigned long long ) F_17 ( V_21 ) ) ;
if ( V_35 ) {
F_24 ( V_39 L_6 ) ;
goto abort;
}
V_35 = F_25 ( V_34 , V_30 -> V_43 , L_7 , L_8 , V_30 -> V_44 ) ;
if ( V_35 ) {
F_24 ( V_39 L_9 ) ;
goto abort;
}
V_35 = F_26 ( V_34 , 0 ) ;
if ( V_35 == - V_45 )
goto V_42;
if ( V_35 )
F_24 ( V_39 L_10 ) ;
return;
abort:
F_26 ( V_34 , 1 ) ;
}
static void F_27 ( struct V_17 * V_18 )
{
V_18 -> V_46 = 1 ;
F_13 ( & V_18 -> V_47 ) ;
}
T_2 F_28 ( int V_48 , void * V_49 )
{
F_27 ( V_49 ) ;
return V_50 ;
}
static void F_29 ( struct V_17 * V_18 )
{
F_20 ( L_11
L_12 ,
V_51 -> V_52 , V_18 -> V_53 ,
V_18 -> V_54 , V_18 -> V_55 ,
V_18 -> V_56 , V_18 -> V_57 ) ;
V_18 -> V_58 = V_59 + F_30 ( 10 * 1000 ) ;
V_18 -> V_54 = 0 ;
V_18 -> V_55 = 0 ;
V_18 -> V_53 = 0 ;
V_18 -> V_57 = 0 ;
}
int F_31 ( void * V_60 )
{
struct V_17 * V_18 = V_60 ;
struct V_20 * V_21 = & V_18 -> V_21 ;
F_32 ( V_18 ) ;
while ( ! F_33 () ) {
if ( F_34 () )
continue;
if ( F_16 ( V_21 -> V_41 != F_17 ( V_21 ) ) )
F_18 ( V_18 ) ;
F_35 (
V_18 -> V_47 ,
V_18 -> V_46 || F_33 () ) ;
F_35 (
V_4 -> V_15 ,
! F_7 ( & V_4 -> V_11 ) ||
F_33 () ) ;
V_18 -> V_46 = 0 ;
F_36 () ;
if ( F_37 ( V_18 ) )
V_18 -> V_46 = 1 ;
if ( V_61 && F_38 ( V_59 , V_18 -> V_58 ) )
F_29 ( V_18 ) ;
}
if ( V_61 )
F_29 ( V_18 ) ;
V_18 -> V_62 = NULL ;
F_39 ( V_18 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_63 V_64 [ V_6 ] ;
unsigned int V_65 , V_66 = 0 ;
T_3 V_67 ;
int V_68 ;
for ( V_65 = 0 ; V_65 < V_2 -> V_69 ; V_65 ++ ) {
V_67 = F_41 ( V_2 , V_65 ) ;
if ( V_67 == V_70 )
continue;
F_42 ( & V_64 [ V_66 ] , F_2 ( V_2 , V_65 ) ,
V_71 , V_67 ) ;
F_41 ( V_2 , V_65 ) = V_70 ;
V_66 ++ ;
}
V_68 = F_43 (
V_72 , V_64 , V_66 ) ;
F_44 ( V_68 ) ;
for ( V_65 = 0 ; V_65 < V_66 ; V_65 ++ ) {
V_68 = F_45 (
F_46 ( V_64 [ V_65 ] . V_73 ) , false ) ;
if ( V_68 ) {
F_47 ( V_39 L_13 ,
( unsigned long ) V_64 [ V_65 ] . V_73 ) ;
continue;
}
}
}
static int F_48 ( struct V_74 * V_2 ,
struct V_1 * V_1 ,
struct V_75 V_3 [] )
{
struct V_76 V_77 [ V_6 ] ;
int V_65 ;
int V_78 = V_2 -> V_79 ;
int V_68 = 0 ;
for ( V_65 = 0 ; V_65 < V_78 ; V_65 ++ ) {
T_4 V_9 ;
V_9 = V_71 ;
if ( V_1 -> V_19 != V_80 )
V_9 |= V_81 ;
F_49 ( & V_77 [ V_65 ] , F_2 ( V_1 , V_65 ) , V_9 ,
V_2 -> V_82 . V_83 . V_3 [ V_65 ] . V_84 ,
V_1 -> V_18 -> V_40 ) ;
}
V_68 = F_43 ( V_85 , V_77 , V_78 ) ;
F_44 ( V_68 ) ;
for ( V_65 = 0 ; V_65 < V_78 ; V_65 ++ ) {
if ( F_16 ( V_77 [ V_65 ] . V_86 != 0 ) ) {
F_50 ( V_39 L_14 ) ;
V_77 [ V_65 ] . V_67 = V_70 ;
V_68 |= 1 ;
}
F_41 ( V_1 , V_65 ) = V_77 [ V_65 ] . V_67 ;
if ( V_68 )
continue;
V_68 = F_51 ( F_52 ( V_77 [ V_65 ] . V_87 ) ,
V_4 -> V_8 ( V_1 , V_65 ) , NULL ) ;
if ( V_68 ) {
F_47 ( V_39 L_15 ,
( unsigned long ) V_77 [ V_65 ] . V_87 , V_68 ) ;
continue;
}
V_3 [ V_65 ] . V_88 = V_77 [ V_65 ] . V_87 |
( V_2 -> V_82 . V_83 . V_3 [ V_65 ] . V_89 << 9 ) ;
}
return V_68 ;
}
static void F_53 ( struct V_17 * V_18 , struct V_74 * V_2 )
{
int V_35 = 0 ;
int V_86 = V_90 ;
struct V_91 * V_32 = V_18 -> V_21 . V_32 ;
if ( V_18 -> V_92 == V_93 )
V_35 = F_54 ( V_32 ,
V_2 -> V_82 . V_94 . V_29 ,
V_2 -> V_82 . V_94 . V_95 ,
V_96 , 0 ) ;
else if ( V_18 -> V_92 == V_97 ) {
struct V_98 * V_99 = V_32 -> V_100 -> V_101 ;
struct V_102 * V_102 = V_99 -> V_103 ;
if ( V_102 -> V_104 -> V_105 )
V_35 = V_102 -> V_104 -> V_105 ( V_102 ,
V_106 | V_107 ,
V_2 -> V_82 . V_94 . V_29 << 9 ,
V_2 -> V_82 . V_94 . V_95 << 9 ) ;
else
V_35 = - V_108 ;
} else
V_35 = - V_108 ;
if ( V_35 == - V_108 ) {
F_50 ( V_39 L_16 ) ;
V_86 = V_109 ;
} else if ( V_35 )
V_86 = V_110 ;
F_55 ( V_18 , V_2 -> V_111 , V_2 -> V_19 , V_86 ) ;
}
static void F_56 ( struct V_17 * V_18 )
{
F_57 ( & V_18 -> V_112 , 1 ) ;
do {
if ( F_58 ( & V_18 -> V_113 ) <= 2 )
break;
F_59 (
& V_18 -> V_114 , V_115 ) ;
if ( ! F_58 ( & V_18 -> V_112 ) )
break;
} while ( ! F_33 () );
F_57 ( & V_18 -> V_112 , 0 ) ;
}
static void F_60 ( struct V_1 * V_1 , int error )
{
if ( ( V_1 -> V_19 == V_116 ) &&
( error == - V_108 ) ) {
F_50 ( V_39 L_17 ) ;
F_61 ( V_117 , V_1 -> V_18 -> V_37 , 0 ) ;
V_1 -> V_86 = V_109 ;
} else if ( ( V_1 -> V_19 == V_118 ) &&
( error == - V_108 ) ) {
F_50 ( V_39 L_18 ) ;
F_62 ( V_117 , V_1 -> V_18 -> V_37 , 0 ) ;
V_1 -> V_86 = V_109 ;
} else if ( error ) {
F_50 ( V_39 L_19
L_20 , error ) ;
V_1 -> V_86 = V_110 ;
}
if ( F_63 ( & V_1 -> V_119 ) ) {
F_40 ( V_1 ) ;
F_55 ( V_1 -> V_18 , V_1 -> V_111 ,
V_1 -> V_19 , V_1 -> V_86 ) ;
F_39 ( V_1 -> V_18 ) ;
if ( F_58 ( & V_1 -> V_18 -> V_113 ) <= 2 ) {
if ( F_58 ( & V_1 -> V_18 -> V_112 ) )
F_64 ( & V_1 -> V_18 -> V_114 ) ;
}
F_11 ( V_1 ) ;
}
}
static void F_65 ( struct V_120 * V_120 , int error )
{
F_60 ( V_120 -> V_121 , error ) ;
F_66 ( V_120 ) ;
}
static int
F_67 ( struct V_17 * V_18 )
{
union V_122 * V_123 = & V_18 -> V_123 ;
struct V_74 V_2 ;
struct V_1 * V_1 ;
T_5 V_22 , V_124 ;
int V_125 = 0 ;
V_22 = V_123 -> V_126 . V_127 ;
V_124 = V_123 -> V_126 . V_128 -> V_129 ;
F_68 () ;
while ( V_22 != V_124 ) {
if ( F_69 ( & V_123 -> V_126 , V_22 ) )
break;
if ( F_33 () ) {
V_125 = 1 ;
break;
}
V_1 = F_5 () ;
if ( NULL == V_1 ) {
V_18 -> V_53 ++ ;
V_125 = 1 ;
break;
}
switch ( V_18 -> V_130 ) {
case V_131 :
memcpy ( & V_2 , F_70 ( & V_123 -> V_132 , V_22 ) , sizeof( V_2 ) ) ;
break;
case V_133 :
F_71 ( & V_2 , F_70 ( & V_123 -> V_134 , V_22 ) ) ;
break;
case V_135 :
F_72 ( & V_2 , F_70 ( & V_123 -> V_136 , V_22 ) ) ;
break;
default:
F_73 () ;
}
V_123 -> V_126 . V_127 = ++ V_22 ;
F_74 () ;
if ( F_75 ( V_18 , & V_2 , V_1 ) )
break;
F_76 () ;
}
return V_125 ;
}
static int
F_37 ( struct V_17 * V_18 )
{
union V_122 * V_123 = & V_18 -> V_123 ;
int V_125 ;
do {
V_125 = F_67 ( V_18 ) ;
if ( V_125 )
break;
F_77 ( & V_123 -> V_126 , V_125 ) ;
} while ( V_125 );
return V_125 ;
}
static int F_75 ( struct V_17 * V_18 ,
struct V_74 * V_2 ,
struct V_1 * V_1 )
{
struct V_16 V_137 ;
struct V_75 V_3 [ V_6 ] ;
unsigned int V_78 ;
struct V_120 * V_120 = NULL ;
struct V_120 * V_138 [ V_6 ] ;
int V_65 , V_139 = 0 ;
int V_19 ;
struct V_140 V_141 ;
bool V_112 = false ;
switch ( V_2 -> V_19 ) {
case V_80 :
V_18 -> V_54 ++ ;
V_19 = V_24 ;
break;
case V_142 :
V_18 -> V_55 ++ ;
V_19 = V_143 ;
break;
case V_118 :
V_112 = true ;
case V_116 :
V_18 -> V_56 ++ ;
V_19 = V_144 ;
break;
case V_145 :
V_18 -> V_57 ++ ;
V_19 = V_146 ;
break;
default:
V_19 = 0 ;
goto V_147;
break;
}
V_78 = V_2 -> V_79 ;
if ( F_16 ( V_78 == 0 && V_19 != V_144 &&
V_19 != V_146 ) ||
F_16 ( V_78 > V_6 ) ) {
F_50 ( V_39 L_21 ,
V_78 ) ;
goto V_147;
}
V_137 . V_30 = V_2 -> V_67 ;
V_137 . V_29 = V_2 -> V_82 . V_83 . V_29 ;
V_137 . V_27 = 0 ;
V_1 -> V_18 = V_18 ;
V_1 -> V_111 = V_2 -> V_111 ;
V_1 -> V_19 = V_2 -> V_19 ;
V_1 -> V_86 = V_90 ;
V_1 -> V_69 = V_78 ;
for ( V_65 = 0 ; V_65 < V_78 ; V_65 ++ ) {
V_3 [ V_65 ] . V_148 = V_2 -> V_82 . V_83 . V_3 [ V_65 ] . V_149 -
V_2 -> V_82 . V_83 . V_3 [ V_65 ] . V_89 + 1 ;
if ( ( V_2 -> V_82 . V_83 . V_3 [ V_65 ] . V_149 >= ( V_150 >> 9 ) ) ||
( V_2 -> V_82 . V_83 . V_3 [ V_65 ] . V_149 < V_2 -> V_82 . V_83 . V_3 [ V_65 ] . V_89 ) )
goto V_147;
V_137 . V_27 += V_3 [ V_65 ] . V_148 ;
}
if ( F_14 ( & V_137 , V_18 , V_19 ) != 0 ) {
F_50 ( V_39 L_22 ,
V_19 == V_24 ? L_23 : L_24 ,
V_137 . V_29 ,
V_137 . V_29 + V_137 . V_27 , V_137 . V_30 ) ;
goto V_147;
}
for ( V_65 = 0 ; V_65 < V_78 ; V_65 ++ ) {
if ( ( ( int ) V_137 . V_29 | ( int ) V_3 [ V_65 ] . V_148 ) &
( ( F_78 ( V_137 . V_32 ) >> 9 ) - 1 ) ) {
F_50 ( V_39 L_25 ,
V_18 -> V_40 ) ;
goto V_147;
}
}
if ( V_112 )
F_56 ( V_1 -> V_18 ) ;
if ( V_19 != V_146 && F_48 ( V_2 , V_1 , V_3 ) )
goto V_151;
F_32 ( V_18 ) ;
for ( V_65 = 0 ; V_65 < V_78 ; V_65 ++ ) {
while ( ( V_120 == NULL ) ||
( F_79 ( V_120 ,
V_4 -> V_8 ( V_1 , V_65 ) ,
V_3 [ V_65 ] . V_148 << 9 ,
V_3 [ V_65 ] . V_88 & ~ V_152 ) == 0 ) ) {
V_120 = F_80 ( V_96 , V_78 - V_65 ) ;
if ( F_16 ( V_120 == NULL ) )
goto V_153;
V_138 [ V_139 ++ ] = V_120 ;
V_120 -> V_154 = V_137 . V_32 ;
V_120 -> V_121 = V_1 ;
V_120 -> V_155 = F_65 ;
V_120 -> V_156 = V_137 . V_29 ;
}
V_137 . V_29 += V_3 [ V_65 ] . V_148 ;
}
if ( ! V_120 ) {
F_44 ( V_19 != V_144 && V_19 != V_146 ) ;
if ( V_19 == V_144 ) {
V_120 = F_80 ( V_96 , 0 ) ;
if ( F_16 ( V_120 == NULL ) )
goto V_153;
V_138 [ V_139 ++ ] = V_120 ;
V_120 -> V_154 = V_137 . V_32 ;
V_120 -> V_121 = V_1 ;
V_120 -> V_155 = F_65 ;
} else if ( V_19 == V_146 ) {
F_53 ( V_18 , V_2 ) ;
F_39 ( V_18 ) ;
F_11 ( V_1 ) ;
return 0 ;
}
}
F_57 ( & V_1 -> V_119 , V_139 ) ;
F_81 ( & V_141 ) ;
for ( V_65 = 0 ; V_65 < V_139 ; V_65 ++ )
F_82 ( V_19 , V_138 [ V_65 ] ) ;
F_83 ( & V_141 ) ;
if ( V_19 == V_24 )
V_18 -> V_157 += V_137 . V_27 ;
else if ( V_19 & V_158 )
V_18 -> V_159 += V_137 . V_27 ;
return 0 ;
V_151:
F_40 ( V_1 ) ;
V_147:
F_55 ( V_18 , V_2 -> V_111 , V_2 -> V_19 , V_110 ) ;
F_11 ( V_1 ) ;
F_84 ( 1 ) ;
return - V_160 ;
V_153:
for ( V_65 = 0 ; V_65 < V_139 ; V_65 ++ )
F_66 ( V_138 [ V_65 ] ) ;
F_60 ( V_1 , - V_161 ) ;
F_84 ( 1 ) ;
return - V_160 ;
}
static void F_55 ( struct V_17 * V_18 , T_6 V_111 ,
unsigned short V_162 , int V_163 )
{
struct V_164 V_165 ;
unsigned long V_9 ;
union V_122 * V_123 = & V_18 -> V_123 ;
int V_166 ;
V_165 . V_111 = V_111 ;
V_165 . V_19 = V_162 ;
V_165 . V_86 = V_163 ;
F_6 ( & V_18 -> V_167 , V_9 ) ;
switch ( V_18 -> V_130 ) {
case V_131 :
memcpy ( F_85 ( & V_123 -> V_132 , V_123 -> V_132 . V_168 ) ,
& V_165 , sizeof( V_165 ) ) ;
break;
case V_133 :
memcpy ( F_85 ( & V_123 -> V_134 , V_123 -> V_134 . V_168 ) ,
& V_165 , sizeof( V_165 ) ) ;
break;
case V_135 :
memcpy ( F_85 ( & V_123 -> V_136 , V_123 -> V_136 . V_168 ) ,
& V_165 , sizeof( V_165 ) ) ;
break;
default:
F_73 () ;
}
V_123 -> V_126 . V_168 ++ ;
F_86 ( & V_123 -> V_126 , V_166 ) ;
F_10 ( & V_18 -> V_167 , V_9 ) ;
if ( V_166 )
F_87 ( V_18 -> V_48 ) ;
}
static int T_7 F_88 ( void )
{
int V_65 , V_169 ;
int V_22 = 0 ;
if ( ! F_89 () )
return - V_170 ;
V_4 = F_90 ( sizeof( struct V_171 ) , V_96 ) ;
if ( ! V_4 ) {
F_47 ( V_39 L_26 , V_172 ) ;
return - V_173 ;
}
V_169 = V_174 * V_6 ;
V_4 -> V_5 = F_90 ( sizeof( V_4 -> V_5 [ 0 ] ) *
V_174 , V_96 ) ;
V_4 -> V_175 = F_91 ( sizeof( V_4 -> V_175 [ 0 ] ) *
V_169 , V_96 ) ;
V_4 -> V_176 = F_90 ( sizeof( V_4 -> V_176 [ 0 ] ) *
V_169 , V_96 ) ;
if ( ! V_4 -> V_5 || ! V_4 -> V_175 ||
! V_4 -> V_176 ) {
V_22 = - V_173 ;
goto V_177;
}
for ( V_65 = 0 ; V_65 < V_169 ; V_65 ++ ) {
V_4 -> V_175 [ V_65 ] = V_70 ;
V_4 -> V_176 [ V_65 ] = F_92 ( V_96 ) ;
if ( V_4 -> V_176 [ V_65 ] == NULL ) {
V_22 = - V_173 ;
goto V_177;
}
}
V_22 = F_93 () ;
if ( V_22 )
goto V_178;
F_94 ( & V_4 -> V_11 ) ;
F_95 ( & V_4 -> V_10 ) ;
F_96 ( & V_4 -> V_15 ) ;
for ( V_65 = 0 ; V_65 < V_174 ; V_65 ++ )
F_97 ( & V_4 -> V_5 [ V_65 ] . V_13 ,
& V_4 -> V_11 ) ;
V_22 = F_98 () ;
if ( V_22 )
goto V_178;
return 0 ;
V_177:
F_47 ( V_39 L_27 , V_172 ) ;
V_178:
F_99 ( V_4 -> V_5 ) ;
F_99 ( V_4 -> V_175 ) ;
if ( V_4 -> V_176 ) {
for ( V_65 = 0 ; V_65 < V_169 ; V_65 ++ ) {
if ( V_4 -> V_176 [ V_65 ] )
F_100 ( V_4 -> V_176 [ V_65 ] ) ;
}
F_99 ( V_4 -> V_176 ) ;
}
F_99 ( V_4 ) ;
V_4 = NULL ;
return V_22 ;
}
