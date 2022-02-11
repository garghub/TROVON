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
struct V_65 * V_66 [ V_6 ] ;
unsigned int V_67 , V_68 = 0 ;
T_3 V_69 ;
int V_70 ;
for ( V_67 = 0 ; V_67 < V_2 -> V_71 ; V_67 ++ ) {
V_69 = F_41 ( V_2 , V_67 ) ;
if ( V_69 == V_72 )
continue;
F_42 ( & V_64 [ V_68 ] , F_2 ( V_2 , V_67 ) ,
V_73 , V_69 ) ;
F_41 ( V_2 , V_67 ) = V_72 ;
V_66 [ V_68 ] = F_43 ( F_2 ( V_2 , V_67 ) ) ;
V_68 ++ ;
}
V_70 = F_44 ( V_64 , V_66 , V_68 , false ) ;
F_45 ( V_70 ) ;
}
static int F_46 ( struct V_74 * V_2 ,
struct V_1 * V_1 ,
struct V_75 V_3 [] )
{
struct V_76 V_77 [ V_6 ] ;
int V_67 ;
int V_78 = V_2 -> V_79 . V_80 . V_81 ;
int V_70 = 0 ;
for ( V_67 = 0 ; V_67 < V_78 ; V_67 ++ ) {
T_4 V_9 ;
V_9 = V_73 ;
if ( V_1 -> V_19 != V_82 )
V_9 |= V_83 ;
F_47 ( & V_77 [ V_67 ] , F_2 ( V_1 , V_67 ) , V_9 ,
V_2 -> V_79 . V_80 . V_3 [ V_67 ] . V_84 ,
V_1 -> V_18 -> V_40 ) ;
}
V_70 = F_48 ( V_77 , NULL , & V_4 -> V_8 ( V_1 , 0 ) , V_78 ) ;
F_45 ( V_70 ) ;
for ( V_67 = 0 ; V_67 < V_78 ; V_67 ++ ) {
if ( F_16 ( V_77 [ V_67 ] . V_85 != 0 ) ) {
F_49 ( V_39 L_13 ) ;
V_77 [ V_67 ] . V_69 = V_72 ;
V_70 |= 1 ;
}
F_41 ( V_1 , V_67 ) = V_77 [ V_67 ] . V_69 ;
if ( V_70 )
continue;
V_3 [ V_67 ] . V_86 = V_77 [ V_67 ] . V_87 |
( V_2 -> V_79 . V_80 . V_3 [ V_67 ] . V_88 << 9 ) ;
}
return V_70 ;
}
static int F_50 ( struct V_17 * V_18 ,
struct V_74 * V_2 )
{
int V_35 = 0 ;
int V_85 = V_89 ;
struct V_90 * V_32 = V_18 -> V_21 . V_32 ;
unsigned long V_91 ;
V_18 -> V_57 ++ ;
F_32 ( V_18 ) ;
V_91 = ( V_18 -> V_21 . V_92 &&
( V_2 -> V_79 . V_93 . V_94 & V_95 ) ) ?
V_96 : 0 ;
V_35 = F_51 ( V_32 , V_2 -> V_79 . V_93 . V_29 ,
V_2 -> V_79 . V_93 . V_97 ,
V_98 , V_91 ) ;
if ( V_35 == - V_99 ) {
F_49 ( V_39 L_14 ) ;
V_85 = V_100 ;
} else if ( V_35 )
V_85 = V_101 ;
F_52 ( V_18 , V_2 -> V_79 . V_93 . V_102 , V_2 -> V_19 , V_85 ) ;
F_39 ( V_18 ) ;
return V_35 ;
}
static void F_53 ( struct V_17 * V_18 )
{
F_54 ( & V_18 -> V_103 , 1 ) ;
do {
if ( F_55 ( & V_18 -> V_104 ) <= 2 )
break;
F_56 (
& V_18 -> V_105 , V_106 ) ;
if ( ! F_55 ( & V_18 -> V_103 ) )
break;
} while ( ! F_33 () );
F_54 ( & V_18 -> V_103 , 0 ) ;
}
static void F_57 ( struct V_1 * V_1 , int error )
{
if ( ( V_1 -> V_19 == V_107 ) &&
( error == - V_99 ) ) {
F_49 ( V_39 L_15 ) ;
F_58 ( V_108 , V_1 -> V_18 -> V_37 , 0 ) ;
V_1 -> V_85 = V_100 ;
} else if ( ( V_1 -> V_19 == V_109 ) &&
( error == - V_99 ) ) {
F_49 ( V_39 L_16 ) ;
F_59 ( V_108 , V_1 -> V_18 -> V_37 , 0 ) ;
V_1 -> V_85 = V_100 ;
} else if ( error ) {
F_49 ( V_39 L_17
L_18 , error ) ;
V_1 -> V_85 = V_101 ;
}
if ( F_60 ( & V_1 -> V_110 ) ) {
F_40 ( V_1 ) ;
F_52 ( V_1 -> V_18 , V_1 -> V_102 ,
V_1 -> V_19 , V_1 -> V_85 ) ;
F_39 ( V_1 -> V_18 ) ;
if ( F_55 ( & V_1 -> V_18 -> V_104 ) <= 2 ) {
if ( F_55 ( & V_1 -> V_18 -> V_103 ) )
F_61 ( & V_1 -> V_18 -> V_105 ) ;
}
F_11 ( V_1 ) ;
}
}
static void F_62 ( struct V_111 * V_111 , int error )
{
F_57 ( V_111 -> V_112 , error ) ;
F_63 ( V_111 ) ;
}
static int
F_64 ( struct V_17 * V_18 )
{
union V_113 * V_114 = & V_18 -> V_114 ;
struct V_74 V_2 ;
struct V_1 * V_1 ;
T_5 V_22 , V_115 ;
int V_116 = 0 ;
V_22 = V_114 -> V_117 . V_118 ;
V_115 = V_114 -> V_117 . V_119 -> V_120 ;
F_65 () ;
while ( V_22 != V_115 ) {
if ( F_66 ( & V_114 -> V_117 , V_22 ) )
break;
if ( F_33 () ) {
V_116 = 1 ;
break;
}
V_1 = F_5 () ;
if ( NULL == V_1 ) {
V_18 -> V_53 ++ ;
V_116 = 1 ;
break;
}
switch ( V_18 -> V_121 ) {
case V_122 :
memcpy ( & V_2 , F_67 ( & V_114 -> V_123 , V_22 ) , sizeof( V_2 ) ) ;
break;
case V_124 :
F_68 ( & V_2 , F_67 ( & V_114 -> V_125 , V_22 ) ) ;
break;
case V_126 :
F_69 ( & V_2 , F_67 ( & V_114 -> V_127 , V_22 ) ) ;
break;
default:
F_70 () ;
}
V_114 -> V_117 . V_118 = ++ V_22 ;
F_71 () ;
if ( F_16 ( V_2 . V_19 == V_128 ) ) {
F_11 ( V_1 ) ;
if ( F_50 ( V_18 , & V_2 ) )
break;
} else if ( F_72 ( V_18 , & V_2 , V_1 ) )
break;
F_73 () ;
}
return V_116 ;
}
static int
F_37 ( struct V_17 * V_18 )
{
union V_113 * V_114 = & V_18 -> V_114 ;
int V_116 ;
do {
V_116 = F_64 ( V_18 ) ;
if ( V_116 )
break;
F_74 ( & V_114 -> V_117 , V_116 ) ;
} while ( V_116 );
return V_116 ;
}
static int F_72 ( struct V_17 * V_18 ,
struct V_74 * V_2 ,
struct V_1 * V_1 )
{
struct V_16 V_129 ;
struct V_75 V_3 [ V_6 ] ;
unsigned int V_78 ;
struct V_111 * V_111 = NULL ;
struct V_111 * V_130 [ V_6 ] ;
int V_67 , V_131 = 0 ;
int V_19 ;
struct V_132 V_133 ;
bool V_103 = false ;
switch ( V_2 -> V_19 ) {
case V_82 :
V_18 -> V_54 ++ ;
V_19 = V_24 ;
break;
case V_134 :
V_18 -> V_55 ++ ;
V_19 = V_135 ;
break;
case V_109 :
V_103 = true ;
case V_107 :
V_18 -> V_56 ++ ;
V_19 = V_136 ;
break;
default:
V_19 = 0 ;
goto V_137;
break;
}
V_78 = V_2 -> V_79 . V_80 . V_81 ;
if ( F_16 ( V_78 == 0 && V_19 != V_136 ) ||
F_16 ( V_78 > V_6 ) ) {
F_49 ( V_39 L_19 ,
V_78 ) ;
goto V_137;
}
V_129 . V_30 = V_2 -> V_79 . V_80 . V_69 ;
V_129 . V_29 = V_2 -> V_79 . V_80 . V_29 ;
V_129 . V_27 = 0 ;
V_1 -> V_18 = V_18 ;
V_1 -> V_102 = V_2 -> V_79 . V_80 . V_102 ;
V_1 -> V_19 = V_2 -> V_19 ;
V_1 -> V_85 = V_89 ;
V_1 -> V_71 = V_78 ;
for ( V_67 = 0 ; V_67 < V_78 ; V_67 ++ ) {
V_3 [ V_67 ] . V_138 = V_2 -> V_79 . V_80 . V_3 [ V_67 ] . V_139 -
V_2 -> V_79 . V_80 . V_3 [ V_67 ] . V_88 + 1 ;
if ( ( V_2 -> V_79 . V_80 . V_3 [ V_67 ] . V_139 >= ( V_140 >> 9 ) ) ||
( V_2 -> V_79 . V_80 . V_3 [ V_67 ] . V_139 < V_2 -> V_79 . V_80 . V_3 [ V_67 ] . V_88 ) )
goto V_137;
V_129 . V_27 += V_3 [ V_67 ] . V_138 ;
}
if ( F_14 ( & V_129 , V_18 , V_19 ) != 0 ) {
F_49 ( V_39 L_20 ,
V_19 == V_24 ? L_21 : L_22 ,
V_129 . V_29 ,
V_129 . V_29 + V_129 . V_27 , V_129 . V_30 ) ;
goto V_137;
}
for ( V_67 = 0 ; V_67 < V_78 ; V_67 ++ ) {
if ( ( ( int ) V_129 . V_29 | ( int ) V_3 [ V_67 ] . V_138 ) &
( ( F_75 ( V_129 . V_32 ) >> 9 ) - 1 ) ) {
F_49 ( V_39 L_23 ,
V_18 -> V_40 ) ;
goto V_137;
}
}
if ( V_103 )
F_53 ( V_1 -> V_18 ) ;
if ( F_46 ( V_2 , V_1 , V_3 ) )
goto V_141;
F_32 ( V_18 ) ;
for ( V_67 = 0 ; V_67 < V_78 ; V_67 ++ ) {
while ( ( V_111 == NULL ) ||
( F_76 ( V_111 ,
V_4 -> V_8 ( V_1 , V_67 ) ,
V_3 [ V_67 ] . V_138 << 9 ,
V_3 [ V_67 ] . V_86 & ~ V_142 ) == 0 ) ) {
V_111 = F_77 ( V_98 , V_78 - V_67 ) ;
if ( F_16 ( V_111 == NULL ) )
goto V_143;
V_130 [ V_131 ++ ] = V_111 ;
V_111 -> V_144 = V_129 . V_32 ;
V_111 -> V_112 = V_1 ;
V_111 -> V_145 = F_62 ;
V_111 -> V_146 = V_129 . V_29 ;
}
V_129 . V_29 += V_3 [ V_67 ] . V_138 ;
}
if ( ! V_111 ) {
F_45 ( V_19 != V_136 ) ;
V_111 = F_77 ( V_98 , 0 ) ;
if ( F_16 ( V_111 == NULL ) )
goto V_143;
V_130 [ V_131 ++ ] = V_111 ;
V_111 -> V_144 = V_129 . V_32 ;
V_111 -> V_112 = V_1 ;
V_111 -> V_145 = F_62 ;
}
F_54 ( & V_1 -> V_110 , V_131 ) ;
F_78 ( & V_133 ) ;
for ( V_67 = 0 ; V_67 < V_131 ; V_67 ++ )
F_79 ( V_19 , V_130 [ V_67 ] ) ;
F_80 ( & V_133 ) ;
if ( V_19 == V_24 )
V_18 -> V_147 += V_129 . V_27 ;
else if ( V_19 & V_148 )
V_18 -> V_149 += V_129 . V_27 ;
return 0 ;
V_141:
F_40 ( V_1 ) ;
V_137:
F_52 ( V_18 , V_2 -> V_79 . V_80 . V_102 , V_2 -> V_19 , V_101 ) ;
F_11 ( V_1 ) ;
F_81 ( 1 ) ;
return - V_150 ;
V_143:
for ( V_67 = 0 ; V_67 < V_131 ; V_67 ++ )
F_63 ( V_130 [ V_67 ] ) ;
F_57 ( V_1 , - V_151 ) ;
F_81 ( 1 ) ;
return - V_150 ;
}
static void F_52 ( struct V_17 * V_18 , T_6 V_102 ,
unsigned short V_152 , int V_153 )
{
struct V_154 V_155 ;
unsigned long V_9 ;
union V_113 * V_114 = & V_18 -> V_114 ;
int V_156 ;
V_155 . V_102 = V_102 ;
V_155 . V_19 = V_152 ;
V_155 . V_85 = V_153 ;
F_6 ( & V_18 -> V_157 , V_9 ) ;
switch ( V_18 -> V_121 ) {
case V_122 :
memcpy ( F_82 ( & V_114 -> V_123 , V_114 -> V_123 . V_158 ) ,
& V_155 , sizeof( V_155 ) ) ;
break;
case V_124 :
memcpy ( F_82 ( & V_114 -> V_125 , V_114 -> V_125 . V_158 ) ,
& V_155 , sizeof( V_155 ) ) ;
break;
case V_126 :
memcpy ( F_82 ( & V_114 -> V_127 , V_114 -> V_127 . V_158 ) ,
& V_155 , sizeof( V_155 ) ) ;
break;
default:
F_70 () ;
}
V_114 -> V_117 . V_158 ++ ;
F_83 ( & V_114 -> V_117 , V_156 ) ;
F_10 ( & V_18 -> V_157 , V_9 ) ;
if ( V_156 )
F_84 ( V_18 -> V_48 ) ;
}
static int T_7 F_85 ( void )
{
int V_67 , V_159 ;
int V_22 = 0 ;
if ( ! F_86 () )
return - V_160 ;
V_4 = F_87 ( sizeof( struct V_161 ) , V_98 ) ;
if ( ! V_4 ) {
F_88 ( V_39 L_24 , V_162 ) ;
return - V_163 ;
}
V_159 = V_164 * V_6 ;
V_4 -> V_5 = F_87 ( sizeof( V_4 -> V_5 [ 0 ] ) *
V_164 , V_98 ) ;
V_4 -> V_165 = F_89 ( sizeof( V_4 -> V_165 [ 0 ] ) *
V_159 , V_98 ) ;
V_4 -> V_166 = F_87 ( sizeof( V_4 -> V_166 [ 0 ] ) *
V_159 , V_98 ) ;
if ( ! V_4 -> V_5 || ! V_4 -> V_165 ||
! V_4 -> V_166 ) {
V_22 = - V_163 ;
goto V_167;
}
for ( V_67 = 0 ; V_67 < V_159 ; V_67 ++ ) {
V_4 -> V_165 [ V_67 ] = V_72 ;
V_4 -> V_166 [ V_67 ] = F_90 ( V_98 ) ;
if ( V_4 -> V_166 [ V_67 ] == NULL ) {
V_22 = - V_163 ;
goto V_167;
}
}
V_22 = F_91 () ;
if ( V_22 )
goto V_168;
F_92 ( & V_4 -> V_11 ) ;
F_93 ( & V_4 -> V_10 ) ;
F_94 ( & V_4 -> V_15 ) ;
for ( V_67 = 0 ; V_67 < V_164 ; V_67 ++ )
F_95 ( & V_4 -> V_5 [ V_67 ] . V_13 ,
& V_4 -> V_11 ) ;
V_22 = F_96 () ;
if ( V_22 )
goto V_168;
return 0 ;
V_167:
F_88 ( V_39 L_25 , V_162 ) ;
V_168:
F_97 ( V_4 -> V_5 ) ;
F_97 ( V_4 -> V_165 ) ;
if ( V_4 -> V_166 ) {
for ( V_67 = 0 ; V_67 < V_159 ; V_67 ++ ) {
if ( V_4 -> V_166 [ V_67 ] )
F_98 ( V_4 -> V_166 [ V_67 ] ) ;
}
F_97 ( V_4 -> V_166 ) ;
}
F_97 ( V_4 ) ;
V_4 = NULL ;
return V_22 ;
}
