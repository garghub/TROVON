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
V_39 = 0 ;
}
F_20 ( & V_20 -> V_25 , V_19 ) ;
F_21 ( V_20 ) ;
V_32 -- ;
}
F_16 ( V_32 != 0 ) ;
}
static struct V_11 * F_22 ( void )
{
struct V_11 * V_12 = NULL ;
unsigned long V_43 ;
F_23 ( & V_14 -> V_44 , V_43 ) ;
if ( ! F_24 ( & V_14 -> V_45 ) ) {
V_12 = F_25 ( V_14 -> V_45 . V_46 , struct V_11 ,
V_47 ) ;
F_26 ( & V_12 -> V_47 ) ;
}
F_27 ( & V_14 -> V_44 , V_43 ) ;
return V_12 ;
}
static void F_28 ( struct V_11 * V_12 )
{
unsigned long V_43 ;
int V_48 ;
F_23 ( & V_14 -> V_44 , V_43 ) ;
V_48 = F_24 ( & V_14 -> V_45 ) ;
F_29 ( & V_12 -> V_47 , & V_14 -> V_45 ) ;
F_27 ( & V_14 -> V_44 , V_43 ) ;
if ( V_48 )
F_30 ( & V_14 -> V_49 ) ;
}
static int F_31 ( struct V_50 * V_12 , struct V_51 * V_4 ,
int V_52 )
{
struct V_53 * V_54 = & V_4 -> V_54 ;
int V_55 = - V_56 ;
if ( ( V_52 != V_57 ) && V_54 -> V_58 )
goto V_59;
if ( F_32 ( V_12 -> V_60 ) ) {
T_2 V_61 = V_12 -> V_62 + V_12 -> V_60 ;
if ( F_33 ( V_61 < V_12 -> V_62 ) )
goto V_59;
if ( F_33 ( V_61 > F_34 ( V_54 ) ) )
goto V_59;
}
V_12 -> V_63 = V_54 -> V_64 ;
V_12 -> V_65 = V_54 -> V_65 ;
V_55 = 0 ;
V_59:
return V_55 ;
}
static void F_35 ( struct V_51 * V_4 )
{
struct V_53 * V_54 = & V_4 -> V_54 ;
struct V_66 V_67 ;
int V_68 ;
struct V_69 * V_63 = F_36 ( V_4 -> V_70 ) ;
unsigned long long V_71 = F_34 ( V_54 ) ;
F_37 ( V_29 L_2 ,
V_4 -> V_72 , F_38 ( V_54 -> V_64 ) , F_39 ( V_54 -> V_64 ) ) ;
F_37 ( V_29 L_3 , V_71 ) ;
V_54 -> V_73 = V_71 ;
V_74:
V_68 = F_40 ( & V_67 ) ;
if ( V_68 ) {
F_41 ( V_29 L_4 ) ;
return;
}
V_68 = F_42 ( V_67 , V_63 -> V_75 , L_5 , L_6 ,
( unsigned long long ) F_34 ( V_54 ) ) ;
if ( V_68 ) {
F_41 ( V_29 L_7 ) ;
goto abort;
}
V_68 = F_42 ( V_67 , V_63 -> V_75 , L_8 , L_9 , V_63 -> V_76 ) ;
if ( V_68 ) {
F_41 ( V_29 L_10 ) ;
goto abort;
}
V_68 = F_43 ( V_67 , 0 ) ;
if ( V_68 == - V_77 )
goto V_74;
if ( V_68 )
F_41 ( V_29 L_11 ) ;
return;
abort:
F_43 ( V_67 , 1 ) ;
}
static void F_44 ( struct V_51 * V_4 )
{
V_4 -> V_78 = 1 ;
F_30 ( & V_4 -> V_79 ) ;
}
T_3 F_45 ( int V_80 , void * V_81 )
{
F_44 ( V_81 ) ;
return V_82 ;
}
static void F_46 ( struct V_51 * V_4 )
{
F_37 ( L_12
L_13 ,
V_83 -> V_84 , V_4 -> V_85 ,
V_4 -> V_86 , V_4 -> V_87 ,
V_4 -> V_88 , V_4 -> V_89 ) ;
V_4 -> V_90 = V_91 + F_47 ( 10 * 1000 ) ;
V_4 -> V_86 = 0 ;
V_4 -> V_87 = 0 ;
V_4 -> V_85 = 0 ;
V_4 -> V_89 = 0 ;
}
int F_48 ( void * V_92 )
{
struct V_51 * V_4 = V_92 ;
struct V_53 * V_54 = & V_4 -> V_54 ;
F_49 ( V_4 ) ;
while ( ! F_50 () ) {
if ( F_51 () )
continue;
if ( F_33 ( V_54 -> V_73 != F_34 ( V_54 ) ) )
F_35 ( V_4 ) ;
F_52 (
V_4 -> V_79 ,
V_4 -> V_78 || F_50 () ) ;
F_52 (
V_14 -> V_49 ,
! F_24 ( & V_14 -> V_45 ) ||
F_50 () ) ;
V_4 -> V_78 = 0 ;
F_53 () ;
if ( F_54 ( V_4 ) )
V_4 -> V_78 = 1 ;
if ( V_93 && F_55 ( V_91 , V_4 -> V_90 ) )
F_46 ( V_4 ) ;
}
if ( ! F_56 ( & V_4 -> V_94 ) )
F_14 ( & V_4 -> V_94 ,
V_4 -> V_95 ) ;
F_16 ( ! F_56 ( & V_4 -> V_94 ) ) ;
V_4 -> V_95 = 0 ;
if ( V_93 )
F_46 ( V_4 ) ;
V_4 -> V_96 = NULL ;
F_57 ( V_4 ) ;
return 0 ;
}
static void F_58 ( struct V_11 * V_12 )
{
struct V_33 V_34 [ V_6 ] ;
struct V_35 * V_36 [ V_6 ] ;
unsigned int V_97 , V_98 = 0 ;
T_4 V_40 ;
int V_38 ;
for ( V_97 = 0 ; V_97 < V_12 -> V_99 ; V_97 ++ ) {
if ( ! F_59 ( V_97 , V_12 -> V_100 ) )
continue;
V_40 = F_60 ( V_12 , V_97 ) ;
if ( V_40 == V_41 )
continue;
F_17 ( & V_34 [ V_98 ] , F_5 ( V_12 , V_97 ) ,
V_42 , V_40 ) ;
F_60 ( V_12 , V_97 ) = V_41 ;
V_36 [ V_98 ] = F_61 ( F_5 ( V_12 , V_97 ) ) ;
V_98 ++ ;
}
V_38 = F_19 ( V_34 , NULL , V_36 , V_98 ) ;
F_16 ( V_38 ) ;
}
static int F_62 ( struct V_101 * V_12 ,
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
V_20 = F_63 (
sizeof( struct V_20 ) ,
V_117 ) ;
if ( ! V_20 )
return - V_118 ;
V_20 -> V_35 = F_64 ( V_117 ) ;
if ( ! V_20 -> V_35 ) {
F_21 ( V_20 ) ;
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
F_65 ( V_29 L_14 ,
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
F_66 ( & V_104 [ V_113 ++ ] , V_106 ,
V_43 , V_12 -> V_110 . V_111 . V_13 [ V_97 ] . V_30 ,
V_4 -> V_72 ) ;
}
}
if ( V_113 ) {
V_38 = F_67 ( V_104 , NULL , V_105 , V_113 ) ;
F_16 ( V_38 ) ;
}
F_68 ( V_11 -> V_100 , V_6 ) ;
for ( V_97 = 0 , V_107 = 0 ; V_97 < V_109 ; V_97 ++ ) {
if ( ! V_94 [ V_97 ] ||
V_94 [ V_97 ] -> V_40 == V_41 ) {
F_16 ( V_107 >= V_113 ) ;
if ( F_33 ( V_104 [ V_107 ] . V_122 != 0 ) ) {
F_65 ( V_29 L_16 ) ;
V_104 [ V_107 ] . V_40 = V_41 ;
V_38 |= 1 ;
if ( V_94 [ V_97 ] ) {
F_20 ( & V_94 [ V_97 ] -> V_25 ,
& V_4 -> V_94 ) ;
V_4 -> V_95 -- ;
F_21 ( V_94 [ V_97 ] ) ;
V_94 [ V_97 ] = NULL ;
}
}
}
if ( V_94 [ V_97 ] ) {
if ( V_94 [ V_97 ] -> V_40 ==
V_41 ) {
V_94 [ V_97 ] -> V_40 = V_104 [ V_107 ] . V_40 ;
V_94 [ V_97 ] -> V_123 =
V_104 [ V_107 ++ ] . V_123 ;
}
F_60 ( V_11 , V_97 ) =
V_94 [ V_97 ] -> V_40 ;
if ( V_38 )
continue;
V_13 [ V_97 ] . V_124 = V_94 [ V_97 ] -> V_123 |
( V_12 -> V_110 . V_111 . V_13 [ V_97 ] . V_125 << 9 ) ;
} else {
F_60 ( V_11 , V_97 ) = V_104 [ V_107 ] . V_40 ;
F_69 ( V_11 -> V_100 , V_97 , 1 ) ;
if ( V_38 ) {
V_107 ++ ;
continue;
}
V_13 [ V_97 ] . V_124 = V_104 [ V_107 ++ ] . V_123 |
( V_12 -> V_110 . V_111 . V_13 [ V_97 ] . V_125 << 9 ) ;
}
}
return V_38 ;
}
static int F_70 ( struct V_51 * V_4 ,
struct V_101 * V_12 )
{
int V_68 = 0 ;
int V_122 = V_126 ;
struct V_127 * V_65 = V_4 -> V_54 . V_65 ;
unsigned long V_128 ;
V_4 -> V_89 ++ ;
F_49 ( V_4 ) ;
V_128 = ( V_4 -> V_54 . V_129 &&
( V_12 -> V_110 . V_130 . V_131 & V_132 ) ) ?
V_133 : 0 ;
V_68 = F_71 ( V_65 , V_12 -> V_110 . V_130 . V_62 ,
V_12 -> V_110 . V_130 . V_134 ,
V_117 , V_128 ) ;
if ( V_68 == - V_135 ) {
F_65 ( V_29 L_17 ) ;
V_122 = V_136 ;
} else if ( V_68 )
V_122 = V_137 ;
F_72 ( V_4 , V_12 -> V_110 . V_130 . V_138 , V_12 -> V_52 , V_122 ) ;
F_57 ( V_4 ) ;
return V_68 ;
}
static void F_73 ( struct V_51 * V_4 )
{
F_74 ( & V_4 -> V_139 , 1 ) ;
do {
if ( F_75 ( & V_4 -> V_140 ) <= 2 )
break;
F_76 (
& V_4 -> V_141 , V_142 ) ;
if ( ! F_75 ( & V_4 -> V_139 ) )
break;
} while ( ! F_50 () );
F_74 ( & V_4 -> V_139 , 0 ) ;
}
static void F_77 ( struct V_11 * V_11 , int error )
{
if ( ( V_11 -> V_52 == V_143 ) &&
( error == - V_135 ) ) {
F_65 ( V_29 L_18 ) ;
F_78 ( V_144 , V_11 -> V_4 -> V_70 , 0 ) ;
V_11 -> V_122 = V_136 ;
} else if ( ( V_11 -> V_52 == V_145 ) &&
( error == - V_135 ) ) {
F_65 ( V_29 L_19 ) ;
F_79 ( V_144 , V_11 -> V_4 -> V_70 , 0 ) ;
V_11 -> V_122 = V_136 ;
} else if ( error ) {
F_65 ( V_29 L_20
L_21 , error ) ;
V_11 -> V_122 = V_137 ;
}
if ( F_80 ( & V_11 -> V_146 ) ) {
F_58 ( V_11 ) ;
F_72 ( V_11 -> V_4 , V_11 -> V_138 ,
V_11 -> V_52 , V_11 -> V_122 ) ;
F_57 ( V_11 -> V_4 ) ;
if ( F_75 ( & V_11 -> V_4 -> V_140 ) <= 2 ) {
if ( F_75 ( & V_11 -> V_4 -> V_139 ) )
F_81 ( & V_11 -> V_4 -> V_141 ) ;
}
F_28 ( V_11 ) ;
}
}
static void F_82 ( struct V_147 * V_147 , int error )
{
F_77 ( V_147 -> V_148 , error ) ;
F_83 ( V_147 ) ;
}
static int
F_84 ( struct V_51 * V_4 )
{
union V_149 * V_150 = & V_4 -> V_150 ;
struct V_101 V_12 ;
struct V_11 * V_11 ;
T_7 V_55 , V_151 ;
int V_152 = 0 ;
V_55 = V_150 -> V_153 . V_154 ;
V_151 = V_150 -> V_153 . V_155 -> V_156 ;
F_85 () ;
while ( V_55 != V_151 ) {
if ( F_86 ( & V_150 -> V_153 , V_55 ) )
break;
if ( F_50 () ) {
V_152 = 1 ;
break;
}
V_11 = F_22 () ;
if ( NULL == V_11 ) {
V_4 -> V_85 ++ ;
V_152 = 1 ;
break;
}
switch ( V_4 -> V_116 ) {
case V_3 :
memcpy ( & V_12 , F_87 ( & V_150 -> V_157 , V_55 ) , sizeof( V_12 ) ) ;
break;
case V_7 :
F_88 ( & V_12 , F_87 ( & V_150 -> V_158 , V_55 ) ) ;
break;
case V_9 :
F_89 ( & V_12 , F_87 ( & V_150 -> V_159 , V_55 ) ) ;
break;
default:
F_3 () ;
}
V_150 -> V_153 . V_154 = ++ V_55 ;
F_90 () ;
if ( F_33 ( V_12 . V_52 == V_160 ) ) {
F_28 ( V_11 ) ;
if ( F_70 ( V_4 , & V_12 ) )
break;
} else if ( F_91 ( V_4 , & V_12 , V_11 ) )
break;
F_92 () ;
}
return V_152 ;
}
static int
F_54 ( struct V_51 * V_4 )
{
union V_149 * V_150 = & V_4 -> V_150 ;
int V_152 ;
do {
V_152 = F_84 ( V_4 ) ;
if ( V_152 )
break;
F_93 ( & V_150 -> V_153 , V_152 ) ;
} while ( V_152 );
return V_152 ;
}
static int F_91 ( struct V_51 * V_4 ,
struct V_101 * V_12 ,
struct V_11 * V_11 )
{
struct V_50 V_161 ;
struct V_102 V_13 [ V_6 ] ;
unsigned int V_109 ;
struct V_147 * V_147 = NULL ;
struct V_147 * V_162 [ V_6 ] ;
int V_97 , V_163 = 0 ;
int V_52 ;
struct V_164 V_165 ;
bool V_139 = false ;
struct V_35 * V_36 [ V_6 ] ;
switch ( V_12 -> V_52 ) {
case V_120 :
V_4 -> V_86 ++ ;
V_52 = V_57 ;
break;
case V_166 :
V_4 -> V_87 ++ ;
V_52 = V_167 ;
break;
case V_145 :
V_139 = true ;
case V_143 :
V_4 -> V_88 ++ ;
V_52 = V_168 ;
break;
default:
V_52 = 0 ;
goto V_169;
break;
}
V_109 = V_12 -> V_110 . V_111 . V_112 ;
if ( F_33 ( V_109 == 0 && V_52 != V_168 ) ||
F_33 ( V_109 > V_6 ) ) {
F_65 ( V_29 L_22 ,
V_109 ) ;
goto V_169;
}
V_161 . V_63 = V_12 -> V_110 . V_111 . V_40 ;
V_161 . V_62 = V_12 -> V_110 . V_111 . V_62 ;
V_161 . V_60 = 0 ;
V_11 -> V_4 = V_4 ;
V_11 -> V_138 = V_12 -> V_110 . V_111 . V_138 ;
V_11 -> V_52 = V_12 -> V_52 ;
V_11 -> V_122 = V_126 ;
V_11 -> V_99 = V_109 ;
for ( V_97 = 0 ; V_97 < V_109 ; V_97 ++ ) {
V_13 [ V_97 ] . V_170 = V_12 -> V_110 . V_111 . V_13 [ V_97 ] . V_171 -
V_12 -> V_110 . V_111 . V_13 [ V_97 ] . V_125 + 1 ;
if ( ( V_12 -> V_110 . V_111 . V_13 [ V_97 ] . V_171 >= ( V_5 >> 9 ) ) ||
( V_12 -> V_110 . V_111 . V_13 [ V_97 ] . V_171 < V_12 -> V_110 . V_111 . V_13 [ V_97 ] . V_125 ) )
goto V_169;
V_161 . V_60 += V_13 [ V_97 ] . V_170 ;
}
if ( F_31 ( & V_161 , V_4 , V_52 ) != 0 ) {
F_65 ( V_29 L_23 ,
V_52 == V_57 ? L_24 : L_25 ,
V_161 . V_62 ,
V_161 . V_62 + V_161 . V_60 , V_161 . V_63 ) ;
goto V_169;
}
for ( V_97 = 0 ; V_97 < V_109 ; V_97 ++ ) {
if ( ( ( int ) V_161 . V_62 | ( int ) V_13 [ V_97 ] . V_170 ) &
( ( F_94 ( V_161 . V_65 ) >> 9 ) - 1 ) ) {
F_65 ( V_29 L_26 ,
V_4 -> V_72 ) ;
goto V_169;
}
}
if ( V_139 )
F_73 ( V_11 -> V_4 ) ;
if ( F_62 ( V_12 , V_11 , V_13 , V_36 ) )
goto V_172;
F_49 ( V_4 ) ;
for ( V_97 = 0 ; V_97 < V_109 ; V_97 ++ ) {
while ( ( V_147 == NULL ) ||
( F_95 ( V_147 ,
V_36 [ V_97 ] ,
V_13 [ V_97 ] . V_170 << 9 ,
V_13 [ V_97 ] . V_124 & ~ V_173 ) == 0 ) ) {
V_147 = F_96 ( V_117 , V_109 - V_97 ) ;
if ( F_33 ( V_147 == NULL ) )
goto V_174;
V_162 [ V_163 ++ ] = V_147 ;
V_147 -> V_175 = V_161 . V_65 ;
V_147 -> V_148 = V_11 ;
V_147 -> V_176 = F_82 ;
V_147 -> V_177 = V_161 . V_62 ;
}
V_161 . V_62 += V_13 [ V_97 ] . V_170 ;
}
if ( ! V_147 ) {
F_16 ( V_52 != V_168 ) ;
V_147 = F_96 ( V_117 , 0 ) ;
if ( F_33 ( V_147 == NULL ) )
goto V_174;
V_162 [ V_163 ++ ] = V_147 ;
V_147 -> V_175 = V_161 . V_65 ;
V_147 -> V_148 = V_11 ;
V_147 -> V_176 = F_82 ;
}
F_74 ( & V_11 -> V_146 , V_163 ) ;
F_97 ( & V_165 ) ;
for ( V_97 = 0 ; V_97 < V_163 ; V_97 ++ )
F_98 ( V_52 , V_162 [ V_97 ] ) ;
F_99 ( & V_165 ) ;
if ( V_52 == V_57 )
V_4 -> V_178 += V_161 . V_60 ;
else if ( V_52 & V_179 )
V_4 -> V_180 += V_161 . V_60 ;
return 0 ;
V_172:
F_58 ( V_11 ) ;
V_169:
F_72 ( V_4 , V_12 -> V_110 . V_111 . V_138 , V_12 -> V_52 , V_137 ) ;
F_28 ( V_11 ) ;
F_100 ( 1 ) ;
return - V_181 ;
V_174:
for ( V_97 = 0 ; V_97 < V_163 ; V_97 ++ )
F_83 ( V_162 [ V_97 ] ) ;
F_77 ( V_11 , - V_182 ) ;
F_100 ( 1 ) ;
return - V_181 ;
}
static void F_72 ( struct V_51 * V_4 , T_8 V_138 ,
unsigned short V_183 , int V_184 )
{
struct V_185 V_186 ;
unsigned long V_43 ;
union V_149 * V_150 = & V_4 -> V_150 ;
int V_187 ;
V_186 . V_138 = V_138 ;
V_186 . V_52 = V_183 ;
V_186 . V_122 = V_184 ;
F_23 ( & V_4 -> V_188 , V_43 ) ;
switch ( V_4 -> V_116 ) {
case V_3 :
memcpy ( F_101 ( & V_150 -> V_157 , V_150 -> V_157 . V_189 ) ,
& V_186 , sizeof( V_186 ) ) ;
break;
case V_7 :
memcpy ( F_101 ( & V_150 -> V_158 , V_150 -> V_158 . V_189 ) ,
& V_186 , sizeof( V_186 ) ) ;
break;
case V_9 :
memcpy ( F_101 ( & V_150 -> V_159 , V_150 -> V_159 . V_189 ) ,
& V_186 , sizeof( V_186 ) ) ;
break;
default:
F_3 () ;
}
V_150 -> V_153 . V_189 ++ ;
F_102 ( & V_150 -> V_153 , V_187 ) ;
F_27 ( & V_4 -> V_188 , V_43 ) ;
if ( V_187 )
F_103 ( V_4 -> V_80 ) ;
}
static int T_9 F_104 ( void )
{
int V_97 , V_190 ;
int V_55 = 0 ;
if ( ! F_105 () )
return - V_191 ;
V_14 = F_106 ( sizeof( struct V_192 ) , V_117 ) ;
if ( ! V_14 ) {
F_10 ( V_29 L_27 , V_193 ) ;
return - V_118 ;
}
V_190 = V_194 * V_6 ;
V_14 -> V_15 = F_106 ( sizeof( V_14 -> V_15 [ 0 ] ) *
V_194 , V_117 ) ;
V_14 -> V_195 = F_63 ( sizeof( V_14 -> V_195 [ 0 ] ) *
V_190 , V_117 ) ;
V_14 -> V_196 = F_106 ( sizeof( V_14 -> V_196 [ 0 ] ) *
V_190 , V_117 ) ;
if ( ! V_14 -> V_15 || ! V_14 -> V_195 ||
! V_14 -> V_196 ) {
V_55 = - V_118 ;
goto V_197;
}
for ( V_97 = 0 ; V_97 < V_190 ; V_97 ++ ) {
V_14 -> V_195 [ V_97 ] = V_41 ;
V_14 -> V_196 [ V_97 ] = F_64 ( V_117 ) ;
if ( V_14 -> V_196 [ V_97 ] == NULL ) {
V_55 = - V_118 ;
goto V_197;
}
}
V_55 = F_107 () ;
if ( V_55 )
goto V_198;
F_108 ( & V_14 -> V_45 ) ;
F_109 ( & V_14 -> V_44 ) ;
F_110 ( & V_14 -> V_49 ) ;
for ( V_97 = 0 ; V_97 < V_194 ; V_97 ++ )
F_111 ( & V_14 -> V_15 [ V_97 ] . V_47 ,
& V_14 -> V_45 ) ;
V_55 = F_112 () ;
if ( V_55 )
goto V_198;
return 0 ;
V_197:
F_10 ( V_29 L_28 , V_193 ) ;
V_198:
F_21 ( V_14 -> V_15 ) ;
F_21 ( V_14 -> V_195 ) ;
if ( V_14 -> V_196 ) {
for ( V_97 = 0 ; V_97 < V_190 ; V_97 ++ ) {
if ( V_14 -> V_196 [ V_97 ] )
F_113 ( V_14 -> V_196 [ V_97 ] ) ;
}
F_21 ( V_14 -> V_196 ) ;
}
F_21 ( V_14 ) ;
V_14 = NULL ;
return V_55 ;
}
