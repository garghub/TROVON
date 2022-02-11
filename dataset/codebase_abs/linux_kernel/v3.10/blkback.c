static inline unsigned int F_1 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_3 :
return F_2 ( V_4 , V_5 ) *
V_6 ;
case V_7 :
return F_2 ( V_8 , V_5 ) *
V_6 ;
case V_9 :
return F_2 ( V_10 , V_5 ) *
V_6 ;
default:
F_3 () ;
}
return 0 ;
}
static inline int F_4 ( struct V_11 * V_12 , int V_13 )
{
return ( V_12 - V_14 -> V_15 ) *
V_6 + V_13 ;
}
static inline unsigned long F_5 ( struct V_11 * V_12 , int V_13 )
{
unsigned long V_16 = F_6 ( V_14 -> V_17 ( V_12 , V_13 ) ) ;
return ( unsigned long ) F_7 ( V_16 ) ;
}
static void F_8 ( struct V_18 * V_19 ,
struct V_20 * V_20 )
{
struct V_21 * * V_22 = & ( V_19 -> V_21 ) , * V_23 = NULL ;
struct V_20 * V_24 ;
while ( * V_22 ) {
V_24 = F_9 ( * V_22 , struct V_20 , V_25 ) ;
V_23 = * V_22 ;
if ( V_20 -> V_26 < V_24 -> V_26 )
V_22 = & ( ( * V_22 ) -> V_27 ) ;
else if ( V_20 -> V_26 > V_24 -> V_26 )
V_22 = & ( ( * V_22 ) -> V_28 ) ;
else {
F_10 ( V_29 L_1 ) ;
F_3 () ;
}
}
F_11 ( & ( V_20 -> V_25 ) , V_23 , V_22 ) ;
F_12 ( & ( V_20 -> V_25 ) , V_19 ) ;
}
static struct V_20 * F_13 ( struct V_18 * V_19 ,
T_1 V_30 )
{
struct V_20 * V_31 ;
struct V_21 * V_25 = V_19 -> V_21 ;
while ( V_25 ) {
V_31 = F_9 ( V_25 , struct V_20 , V_25 ) ;
if ( V_30 < V_31 -> V_26 )
V_25 = V_25 -> V_27 ;
else if ( V_30 > V_31 -> V_26 )
V_25 = V_25 -> V_28 ;
else
return V_31 ;
}
return NULL ;
}
static void F_14 ( struct V_18 * V_19 , unsigned int V_32 )
{
struct V_33 V_34 [ V_6 ] ;
struct V_35 * V_36 [ V_6 ] ;
struct V_20 * V_20 ;
struct V_21 * V_37 ;
int V_38 = 0 ;
int V_39 = 0 ;
F_15 (persistent_gnt, n, root, node) {
F_16 ( V_20 -> V_40 ==
V_41 ) ;
F_17 ( & V_34 [ V_39 ] ,
( unsigned long ) F_7 ( F_6 (
V_20 -> V_35 ) ) ,
V_42 ,
V_20 -> V_40 ) ;
V_36 [ V_39 ] = V_20 -> V_35 ;
if ( ++ V_39 == V_6 ||
! F_18 ( & V_20 -> V_25 ) ) {
V_38 = F_19 ( V_34 , NULL , V_36 ,
V_39 ) ;
F_16 ( V_38 ) ;
F_20 ( V_39 , V_36 ) ;
V_39 = 0 ;
}
F_21 ( & V_20 -> V_25 , V_19 ) ;
F_22 ( V_20 ) ;
V_32 -- ;
}
F_16 ( V_32 != 0 ) ;
}
static struct V_11 * F_23 ( void )
{
struct V_11 * V_12 = NULL ;
unsigned long V_43 ;
F_24 ( & V_14 -> V_44 , V_43 ) ;
if ( ! F_25 ( & V_14 -> V_45 ) ) {
V_12 = F_26 ( V_14 -> V_45 . V_46 , struct V_11 ,
V_47 ) ;
F_27 ( & V_12 -> V_47 ) ;
}
F_28 ( & V_14 -> V_44 , V_43 ) ;
return V_12 ;
}
static void F_29 ( struct V_11 * V_12 )
{
unsigned long V_43 ;
int V_48 ;
F_24 ( & V_14 -> V_44 , V_43 ) ;
V_48 = F_25 ( & V_14 -> V_45 ) ;
F_30 ( & V_12 -> V_47 , & V_14 -> V_45 ) ;
F_28 ( & V_14 -> V_44 , V_43 ) ;
if ( V_48 )
F_31 ( & V_14 -> V_49 ) ;
}
static int F_32 ( struct V_50 * V_12 , struct V_51 * V_4 ,
int V_52 )
{
struct V_53 * V_54 = & V_4 -> V_54 ;
int V_55 = - V_56 ;
if ( ( V_52 != V_57 ) && V_54 -> V_58 )
goto V_59;
if ( F_33 ( V_12 -> V_60 ) ) {
T_2 V_61 = V_12 -> V_62 + V_12 -> V_60 ;
if ( F_34 ( V_61 < V_12 -> V_62 ) )
goto V_59;
if ( F_34 ( V_61 > F_35 ( V_54 ) ) )
goto V_59;
}
V_12 -> V_63 = V_54 -> V_64 ;
V_12 -> V_65 = V_54 -> V_65 ;
V_55 = 0 ;
V_59:
return V_55 ;
}
static void F_36 ( struct V_51 * V_4 )
{
struct V_53 * V_54 = & V_4 -> V_54 ;
struct V_66 V_67 ;
int V_68 ;
struct V_69 * V_63 = F_37 ( V_4 -> V_70 ) ;
unsigned long long V_71 = F_35 ( V_54 ) ;
F_38 ( V_29 L_2 ,
V_4 -> V_72 , F_39 ( V_54 -> V_64 ) , F_40 ( V_54 -> V_64 ) ) ;
F_38 ( V_29 L_3 , V_71 ) ;
V_54 -> V_73 = V_71 ;
V_74:
V_68 = F_41 ( & V_67 ) ;
if ( V_68 ) {
F_42 ( V_29 L_4 ) ;
return;
}
V_68 = F_43 ( V_67 , V_63 -> V_75 , L_5 , L_6 ,
( unsigned long long ) F_35 ( V_54 ) ) ;
if ( V_68 ) {
F_42 ( V_29 L_7 ) ;
goto abort;
}
V_68 = F_43 ( V_67 , V_63 -> V_75 , L_8 , L_9 , V_63 -> V_76 ) ;
if ( V_68 ) {
F_42 ( V_29 L_10 ) ;
goto abort;
}
V_68 = F_44 ( V_67 , 0 ) ;
if ( V_68 == - V_77 )
goto V_74;
if ( V_68 )
F_42 ( V_29 L_11 ) ;
return;
abort:
F_44 ( V_67 , 1 ) ;
}
static void F_45 ( struct V_51 * V_4 )
{
V_4 -> V_78 = 1 ;
F_31 ( & V_4 -> V_79 ) ;
}
T_3 F_46 ( int V_80 , void * V_81 )
{
F_45 ( V_81 ) ;
return V_82 ;
}
static void F_47 ( struct V_51 * V_4 )
{
F_38 ( L_12
L_13 ,
V_83 -> V_84 , V_4 -> V_85 ,
V_4 -> V_86 , V_4 -> V_87 ,
V_4 -> V_88 , V_4 -> V_89 ) ;
V_4 -> V_90 = V_91 + F_48 ( 10 * 1000 ) ;
V_4 -> V_86 = 0 ;
V_4 -> V_87 = 0 ;
V_4 -> V_85 = 0 ;
V_4 -> V_89 = 0 ;
}
int F_49 ( void * V_92 )
{
struct V_51 * V_4 = V_92 ;
struct V_53 * V_54 = & V_4 -> V_54 ;
F_50 ( V_4 ) ;
while ( ! F_51 () ) {
if ( F_52 () )
continue;
if ( F_34 ( V_54 -> V_73 != F_35 ( V_54 ) ) )
F_36 ( V_4 ) ;
F_53 (
V_4 -> V_79 ,
V_4 -> V_78 || F_51 () ) ;
F_53 (
V_14 -> V_49 ,
! F_25 ( & V_14 -> V_45 ) ||
F_51 () ) ;
V_4 -> V_78 = 0 ;
F_54 () ;
if ( F_55 ( V_4 ) )
V_4 -> V_78 = 1 ;
if ( V_93 && F_56 ( V_91 , V_4 -> V_90 ) )
F_47 ( V_4 ) ;
}
if ( ! F_57 ( & V_4 -> V_94 ) )
F_14 ( & V_4 -> V_94 ,
V_4 -> V_95 ) ;
F_16 ( ! F_57 ( & V_4 -> V_94 ) ) ;
V_4 -> V_95 = 0 ;
if ( V_93 )
F_47 ( V_4 ) ;
V_4 -> V_96 = NULL ;
F_58 ( V_4 ) ;
return 0 ;
}
static void F_59 ( struct V_11 * V_12 )
{
struct V_33 V_34 [ V_6 ] ;
struct V_35 * V_36 [ V_6 ] ;
unsigned int V_97 , V_98 = 0 ;
T_4 V_40 ;
int V_38 ;
for ( V_97 = 0 ; V_97 < V_12 -> V_99 ; V_97 ++ ) {
if ( ! F_60 ( V_97 , V_12 -> V_100 ) )
continue;
V_40 = F_61 ( V_12 , V_97 ) ;
if ( V_40 == V_41 )
continue;
F_17 ( & V_34 [ V_98 ] , F_5 ( V_12 , V_97 ) ,
V_42 , V_40 ) ;
F_61 ( V_12 , V_97 ) = V_41 ;
V_36 [ V_98 ] = F_62 ( F_5 ( V_12 , V_97 ) ) ;
V_98 ++ ;
}
V_38 = F_19 ( V_34 , NULL , V_36 , V_98 ) ;
F_16 ( V_38 ) ;
}
static int F_63 ( struct V_101 * V_12 ,
struct V_11 * V_11 ,
struct V_102 V_13 [] ,
struct V_35 * V_36 [] )
{
struct V_103 V_104 [ V_6 ] ;
struct V_20 * V_94 [ V_6 ] ;
struct V_35 * V_105 [ V_6 ] ;
struct V_20 * V_20 = NULL ;
struct V_51 * V_4 = V_11 -> V_4 ;
T_5 V_106 = 0 ;
int V_97 , V_107 ;
bool V_108 ;
int V_109 = V_12 -> V_110 . V_111 . V_112 ;
int V_113 = 0 ;
int V_38 = 0 ;
int V_114 ;
V_114 = ( V_4 -> V_54 . V_115 ) ;
F_16 ( V_4 -> V_95 >
F_1 ( V_11 -> V_4 -> V_116 ) ) ;
for ( V_97 = 0 ; V_97 < V_109 ; V_97 ++ ) {
T_6 V_43 ;
if ( V_114 )
V_20 = F_13 (
& V_4 -> V_94 ,
V_12 -> V_110 . V_111 . V_13 [ V_97 ] . V_30 ) ;
if ( V_20 ) {
V_108 = false ;
} else if ( V_114 &&
V_4 -> V_95 <
F_1 ( V_4 -> V_116 ) ) {
V_108 = true ;
V_20 = F_64 (
sizeof( struct V_20 ) ,
V_117 ) ;
if ( ! V_20 )
return - V_118 ;
if ( F_65 ( 1 , & V_20 -> V_35 ,
false ) ) {
F_22 ( V_20 ) ;
return - V_118 ;
}
V_20 -> V_26 = V_12 -> V_110 . V_111 . V_13 [ V_97 ] . V_30 ;
V_20 -> V_40 = V_41 ;
V_105 [ V_113 ] =
V_20 -> V_35 ;
V_106 = ( unsigned long ) F_7 (
F_6 ( V_20 -> V_35 ) ) ;
F_8 ( & V_4 -> V_94 ,
V_20 ) ;
V_4 -> V_95 ++ ;
F_66 ( V_29 L_14 ,
V_20 -> V_26 , V_4 -> V_95 ,
F_1 ( V_4 -> V_116 ) ) ;
} else {
if ( V_114 &&
! V_4 -> V_54 . V_119 ) {
V_4 -> V_54 . V_119 = 1 ;
F_10 ( V_29 L_15 ,
V_4 -> V_72 , V_4 -> V_54 . V_40 ) ;
}
V_108 = true ;
V_36 [ V_97 ] = V_14 -> V_17 ( V_11 , V_97 ) ;
V_106 = F_5 ( V_11 , V_97 ) ;
V_105 [ V_113 ] =
V_14 -> V_17 ( V_11 , V_97 ) ;
}
if ( V_20 ) {
V_36 [ V_97 ] = V_20 -> V_35 ;
V_94 [ V_97 ] = V_20 ;
} else {
V_94 [ V_97 ] = NULL ;
}
if ( V_108 ) {
V_43 = V_42 ;
if ( ! V_20 &&
( V_11 -> V_52 != V_120 ) )
V_43 |= V_121 ;
F_67 ( & V_104 [ V_113 ++ ] , V_106 ,
V_43 , V_12 -> V_110 . V_111 . V_13 [ V_97 ] . V_30 ,
V_4 -> V_72 ) ;
}
}
if ( V_113 ) {
V_38 = F_68 ( V_104 , NULL , V_105 , V_113 ) ;
F_16 ( V_38 ) ;
}
F_69 ( V_11 -> V_100 , V_6 ) ;
for ( V_97 = 0 , V_107 = 0 ; V_97 < V_109 ; V_97 ++ ) {
if ( ! V_94 [ V_97 ] ||
V_94 [ V_97 ] -> V_40 == V_41 ) {
F_16 ( V_107 >= V_113 ) ;
if ( F_34 ( V_104 [ V_107 ] . V_122 != 0 ) ) {
F_66 ( V_29 L_16 ) ;
V_104 [ V_107 ] . V_40 = V_41 ;
V_38 |= 1 ;
if ( V_94 [ V_97 ] ) {
F_21 ( & V_94 [ V_97 ] -> V_25 ,
& V_4 -> V_94 ) ;
V_4 -> V_95 -- ;
F_22 ( V_94 [ V_97 ] ) ;
V_94 [ V_97 ] = NULL ;
}
}
}
if ( V_94 [ V_97 ] ) {
if ( V_94 [ V_97 ] -> V_40 ==
V_41 ) {
V_94 [ V_97 ] -> V_40 = V_104 [ V_107 ++ ] . V_40 ;
}
F_61 ( V_11 , V_97 ) =
V_94 [ V_97 ] -> V_40 ;
if ( V_38 )
continue;
} else {
F_61 ( V_11 , V_97 ) = V_104 [ V_107 ++ ] . V_40 ;
F_70 ( V_11 -> V_100 , V_97 , 1 ) ;
if ( V_38 )
continue;
}
V_13 [ V_97 ] . V_123 = ( V_12 -> V_110 . V_111 . V_13 [ V_97 ] . V_124 << 9 ) ;
}
return V_38 ;
}
static int F_71 ( struct V_51 * V_4 ,
struct V_101 * V_12 )
{
int V_68 = 0 ;
int V_122 = V_125 ;
struct V_126 * V_65 = V_4 -> V_54 . V_65 ;
unsigned long V_127 ;
V_4 -> V_89 ++ ;
F_50 ( V_4 ) ;
V_127 = ( V_4 -> V_54 . V_128 &&
( V_12 -> V_110 . V_129 . V_130 & V_131 ) ) ?
V_132 : 0 ;
V_68 = F_72 ( V_65 , V_12 -> V_110 . V_129 . V_62 ,
V_12 -> V_110 . V_129 . V_133 ,
V_117 , V_127 ) ;
if ( V_68 == - V_134 ) {
F_66 ( V_29 L_17 ) ;
V_122 = V_135 ;
} else if ( V_68 )
V_122 = V_136 ;
F_73 ( V_4 , V_12 -> V_110 . V_129 . V_137 , V_12 -> V_52 , V_122 ) ;
F_58 ( V_4 ) ;
return V_68 ;
}
static int F_74 ( struct V_51 * V_4 ,
struct V_101 * V_12 ,
struct V_11 * V_11 )
{
F_29 ( V_11 ) ;
F_73 ( V_4 , V_12 -> V_110 . V_138 . V_137 , V_12 -> V_52 ,
V_135 ) ;
return - V_139 ;
}
static void F_75 ( struct V_51 * V_4 )
{
F_76 ( & V_4 -> V_140 , 1 ) ;
do {
if ( F_77 ( & V_4 -> V_141 ) <= 2 )
break;
F_78 (
& V_4 -> V_142 , V_143 ) ;
if ( ! F_77 ( & V_4 -> V_140 ) )
break;
} while ( ! F_51 () );
F_76 ( & V_4 -> V_140 , 0 ) ;
}
static void F_79 ( struct V_11 * V_11 , int error )
{
if ( ( V_11 -> V_52 == V_144 ) &&
( error == - V_134 ) ) {
F_66 ( V_29 L_18 ) ;
F_80 ( V_145 , V_11 -> V_4 -> V_70 , 0 ) ;
V_11 -> V_122 = V_135 ;
} else if ( ( V_11 -> V_52 == V_146 ) &&
( error == - V_134 ) ) {
F_66 ( V_29 L_19 ) ;
F_81 ( V_145 , V_11 -> V_4 -> V_70 , 0 ) ;
V_11 -> V_122 = V_135 ;
} else if ( error ) {
F_66 ( V_29 L_20
L_21 , error ) ;
V_11 -> V_122 = V_136 ;
}
if ( F_82 ( & V_11 -> V_147 ) ) {
F_59 ( V_11 ) ;
F_73 ( V_11 -> V_4 , V_11 -> V_137 ,
V_11 -> V_52 , V_11 -> V_122 ) ;
F_58 ( V_11 -> V_4 ) ;
if ( F_77 ( & V_11 -> V_4 -> V_141 ) <= 2 ) {
if ( F_77 ( & V_11 -> V_4 -> V_140 ) )
F_83 ( & V_11 -> V_4 -> V_142 ) ;
}
F_29 ( V_11 ) ;
}
}
static void F_84 ( struct V_148 * V_148 , int error )
{
F_79 ( V_148 -> V_149 , error ) ;
F_85 ( V_148 ) ;
}
static int
F_86 ( struct V_51 * V_4 )
{
union V_150 * V_151 = & V_4 -> V_151 ;
struct V_101 V_12 ;
struct V_11 * V_11 ;
T_7 V_55 , V_152 ;
int V_153 = 0 ;
V_55 = V_151 -> V_154 . V_155 ;
V_152 = V_151 -> V_154 . V_156 -> V_157 ;
F_87 () ;
while ( V_55 != V_152 ) {
if ( F_88 ( & V_151 -> V_154 , V_55 ) )
break;
if ( F_51 () ) {
V_153 = 1 ;
break;
}
V_11 = F_23 () ;
if ( NULL == V_11 ) {
V_4 -> V_85 ++ ;
V_153 = 1 ;
break;
}
switch ( V_4 -> V_116 ) {
case V_3 :
memcpy ( & V_12 , F_89 ( & V_151 -> V_158 , V_55 ) , sizeof( V_12 ) ) ;
break;
case V_7 :
F_90 ( & V_12 , F_89 ( & V_151 -> V_159 , V_55 ) ) ;
break;
case V_9 :
F_91 ( & V_12 , F_89 ( & V_151 -> V_160 , V_55 ) ) ;
break;
default:
F_3 () ;
}
V_151 -> V_154 . V_155 = ++ V_55 ;
F_92 () ;
switch ( V_12 . V_52 ) {
case V_120 :
case V_161 :
case V_146 :
case V_144 :
if ( F_93 ( V_4 , & V_12 , V_11 ) )
goto V_162;
break;
case V_163 :
F_29 ( V_11 ) ;
if ( F_71 ( V_4 , & V_12 ) )
goto V_162;
break;
default:
if ( F_74 ( V_4 , & V_12 , V_11 ) )
goto V_162;
break;
}
F_94 () ;
}
V_162:
return V_153 ;
}
static int
F_55 ( struct V_51 * V_4 )
{
union V_150 * V_151 = & V_4 -> V_151 ;
int V_153 ;
do {
V_153 = F_86 ( V_4 ) ;
if ( V_153 )
break;
F_95 ( & V_151 -> V_154 , V_153 ) ;
} while ( V_153 );
return V_153 ;
}
static int F_93 ( struct V_51 * V_4 ,
struct V_101 * V_12 ,
struct V_11 * V_11 )
{
struct V_50 V_164 ;
struct V_102 V_13 [ V_6 ] ;
unsigned int V_109 ;
struct V_148 * V_148 = NULL ;
struct V_148 * V_165 [ V_6 ] ;
int V_97 , V_166 = 0 ;
int V_52 ;
struct V_167 V_168 ;
bool V_140 = false ;
struct V_35 * V_36 [ V_6 ] ;
switch ( V_12 -> V_52 ) {
case V_120 :
V_4 -> V_86 ++ ;
V_52 = V_57 ;
break;
case V_161 :
V_4 -> V_87 ++ ;
V_52 = V_169 ;
break;
case V_146 :
V_140 = true ;
case V_144 :
V_4 -> V_88 ++ ;
V_52 = V_170 ;
break;
default:
V_52 = 0 ;
goto V_171;
break;
}
V_109 = V_12 -> V_110 . V_111 . V_112 ;
if ( F_34 ( V_109 == 0 && V_52 != V_170 ) ||
F_34 ( V_109 > V_6 ) ) {
F_66 ( V_29 L_22 ,
V_109 ) ;
goto V_171;
}
V_164 . V_62 = V_12 -> V_110 . V_111 . V_62 ;
V_164 . V_60 = 0 ;
V_11 -> V_4 = V_4 ;
V_11 -> V_137 = V_12 -> V_110 . V_111 . V_137 ;
V_11 -> V_52 = V_12 -> V_52 ;
V_11 -> V_122 = V_125 ;
V_11 -> V_99 = V_109 ;
for ( V_97 = 0 ; V_97 < V_109 ; V_97 ++ ) {
V_13 [ V_97 ] . V_172 = V_12 -> V_110 . V_111 . V_13 [ V_97 ] . V_173 -
V_12 -> V_110 . V_111 . V_13 [ V_97 ] . V_124 + 1 ;
if ( ( V_12 -> V_110 . V_111 . V_13 [ V_97 ] . V_173 >= ( V_5 >> 9 ) ) ||
( V_12 -> V_110 . V_111 . V_13 [ V_97 ] . V_173 < V_12 -> V_110 . V_111 . V_13 [ V_97 ] . V_124 ) )
goto V_171;
V_164 . V_60 += V_13 [ V_97 ] . V_172 ;
}
if ( F_32 ( & V_164 , V_4 , V_52 ) != 0 ) {
F_66 ( V_29 L_23 ,
V_52 == V_57 ? L_24 : L_25 ,
V_164 . V_62 ,
V_164 . V_62 + V_164 . V_60 ,
V_4 -> V_54 . V_64 ) ;
goto V_171;
}
for ( V_97 = 0 ; V_97 < V_109 ; V_97 ++ ) {
if ( ( ( int ) V_164 . V_62 | ( int ) V_13 [ V_97 ] . V_172 ) &
( ( F_96 ( V_164 . V_65 ) >> 9 ) - 1 ) ) {
F_66 ( V_29 L_26 ,
V_4 -> V_72 ) ;
goto V_171;
}
}
if ( V_140 )
F_75 ( V_11 -> V_4 ) ;
if ( F_63 ( V_12 , V_11 , V_13 , V_36 ) )
goto V_174;
F_50 ( V_4 ) ;
for ( V_97 = 0 ; V_97 < V_109 ; V_97 ++ ) {
while ( ( V_148 == NULL ) ||
( F_97 ( V_148 ,
V_36 [ V_97 ] ,
V_13 [ V_97 ] . V_172 << 9 ,
V_13 [ V_97 ] . V_123 ) == 0 ) ) {
V_148 = F_98 ( V_117 , V_109 - V_97 ) ;
if ( F_34 ( V_148 == NULL ) )
goto V_175;
V_165 [ V_166 ++ ] = V_148 ;
V_148 -> V_176 = V_164 . V_65 ;
V_148 -> V_149 = V_11 ;
V_148 -> V_177 = F_84 ;
V_148 -> V_178 = V_164 . V_62 ;
}
V_164 . V_62 += V_13 [ V_97 ] . V_172 ;
}
if ( ! V_148 ) {
F_16 ( V_52 != V_170 ) ;
V_148 = F_98 ( V_117 , 0 ) ;
if ( F_34 ( V_148 == NULL ) )
goto V_175;
V_165 [ V_166 ++ ] = V_148 ;
V_148 -> V_176 = V_164 . V_65 ;
V_148 -> V_149 = V_11 ;
V_148 -> V_177 = F_84 ;
}
F_76 ( & V_11 -> V_147 , V_166 ) ;
F_99 ( & V_168 ) ;
for ( V_97 = 0 ; V_97 < V_166 ; V_97 ++ )
F_100 ( V_52 , V_165 [ V_97 ] ) ;
F_101 ( & V_168 ) ;
if ( V_52 == V_57 )
V_4 -> V_179 += V_164 . V_60 ;
else if ( V_52 & V_180 )
V_4 -> V_181 += V_164 . V_60 ;
return 0 ;
V_174:
F_59 ( V_11 ) ;
V_171:
F_73 ( V_4 , V_12 -> V_110 . V_111 . V_137 , V_12 -> V_52 , V_136 ) ;
F_29 ( V_11 ) ;
F_102 ( 1 ) ;
return - V_139 ;
V_175:
for ( V_97 = 0 ; V_97 < V_166 ; V_97 ++ )
F_85 ( V_165 [ V_97 ] ) ;
F_76 ( & V_11 -> V_147 , 1 ) ;
F_79 ( V_11 , - V_182 ) ;
F_102 ( 1 ) ;
return - V_139 ;
}
static void F_73 ( struct V_51 * V_4 , T_8 V_137 ,
unsigned short V_183 , int V_184 )
{
struct V_185 V_186 ;
unsigned long V_43 ;
union V_150 * V_151 = & V_4 -> V_151 ;
int V_187 ;
V_186 . V_137 = V_137 ;
V_186 . V_52 = V_183 ;
V_186 . V_122 = V_184 ;
F_24 ( & V_4 -> V_188 , V_43 ) ;
switch ( V_4 -> V_116 ) {
case V_3 :
memcpy ( F_103 ( & V_151 -> V_158 , V_151 -> V_158 . V_189 ) ,
& V_186 , sizeof( V_186 ) ) ;
break;
case V_7 :
memcpy ( F_103 ( & V_151 -> V_159 , V_151 -> V_159 . V_189 ) ,
& V_186 , sizeof( V_186 ) ) ;
break;
case V_9 :
memcpy ( F_103 ( & V_151 -> V_160 , V_151 -> V_160 . V_189 ) ,
& V_186 , sizeof( V_186 ) ) ;
break;
default:
F_3 () ;
}
V_151 -> V_154 . V_189 ++ ;
F_104 ( & V_151 -> V_154 , V_187 ) ;
F_28 ( & V_4 -> V_188 , V_43 ) ;
if ( V_187 )
F_105 ( V_4 -> V_80 ) ;
}
static int T_9 F_106 ( void )
{
int V_97 , V_190 ;
int V_55 = 0 ;
if ( ! F_107 () )
return - V_191 ;
V_14 = F_108 ( sizeof( struct V_192 ) , V_117 ) ;
if ( ! V_14 ) {
F_10 ( V_29 L_27 , V_193 ) ;
return - V_118 ;
}
V_190 = V_194 * V_6 ;
V_14 -> V_15 = F_108 ( sizeof( V_14 -> V_15 [ 0 ] ) *
V_194 , V_117 ) ;
V_14 -> V_195 = F_64 ( sizeof( V_14 -> V_195 [ 0 ] ) *
V_190 , V_117 ) ;
V_14 -> V_196 = F_108 ( sizeof( V_14 -> V_196 [ 0 ] ) *
V_190 , V_117 ) ;
if ( ! V_14 -> V_15 || ! V_14 -> V_195 ||
! V_14 -> V_196 ) {
V_55 = - V_118 ;
goto V_197;
}
for ( V_97 = 0 ; V_97 < V_190 ; V_97 ++ ) {
V_14 -> V_195 [ V_97 ] = V_41 ;
V_14 -> V_196 [ V_97 ] = F_109 ( V_117 ) ;
if ( V_14 -> V_196 [ V_97 ] == NULL ) {
V_55 = - V_118 ;
goto V_197;
}
}
V_55 = F_110 () ;
if ( V_55 )
goto V_198;
F_111 ( & V_14 -> V_45 ) ;
F_112 ( & V_14 -> V_44 ) ;
F_113 ( & V_14 -> V_49 ) ;
for ( V_97 = 0 ; V_97 < V_194 ; V_97 ++ )
F_114 ( & V_14 -> V_15 [ V_97 ] . V_47 ,
& V_14 -> V_45 ) ;
V_55 = F_115 () ;
if ( V_55 )
goto V_198;
return 0 ;
V_197:
F_10 ( V_29 L_28 , V_193 ) ;
V_198:
F_22 ( V_14 -> V_15 ) ;
F_22 ( V_14 -> V_195 ) ;
if ( V_14 -> V_196 ) {
for ( V_97 = 0 ; V_97 < V_190 ; V_97 ++ ) {
if ( V_14 -> V_196 [ V_97 ] )
F_116 ( V_14 -> V_196 [ V_97 ] ) ;
}
F_22 ( V_14 -> V_196 ) ;
}
F_22 ( V_14 ) ;
V_14 = NULL ;
return V_55 ;
}
