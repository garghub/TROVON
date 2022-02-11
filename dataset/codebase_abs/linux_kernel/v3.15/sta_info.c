static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_3 * V_5 ;
V_5 = F_2 ( V_2 -> V_6 [ F_3 ( V_4 -> V_4 . V_7 ) ] ,
F_4 ( & V_2 -> V_8 ) ) ;
if ( ! V_5 )
return - V_9 ;
if ( V_5 == V_4 ) {
F_5 ( V_2 -> V_6 [ F_3 ( V_4 -> V_4 . V_7 ) ] ,
V_5 -> V_10 ) ;
return 0 ;
}
while ( F_6 ( V_5 -> V_10 ) &&
F_6 ( V_5 -> V_10 ) != V_4 )
V_5 = F_2 ( V_5 -> V_10 ,
F_4 ( & V_2 -> V_8 ) ) ;
if ( F_6 ( V_5 -> V_10 ) ) {
F_5 ( V_5 -> V_10 , V_4 -> V_10 ) ;
return 0 ;
}
return - V_9 ;
}
static void F_7 ( struct V_3 * V_4 )
{
int V_11 , V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_17 * V_18 ;
if ( F_8 ( V_4 , V_19 ) ||
F_8 ( V_4 , V_20 ) ) {
if ( V_4 -> V_16 -> V_21 . type == V_22 ||
V_4 -> V_16 -> V_21 . type == V_23 )
V_18 = & V_16 -> V_24 -> V_18 ;
else if ( F_9 ( & V_16 -> V_21 ) )
V_18 = & V_16 -> V_25 . V_26 . V_18 ;
else
return;
F_10 ( V_4 , V_19 ) ;
F_10 ( V_4 , V_20 ) ;
F_11 ( & V_18 -> V_27 ) ;
F_12 ( V_4 ) ;
}
for ( V_11 = 0 ; V_11 < V_28 ; V_11 ++ ) {
V_2 -> V_29 -= F_13 ( & V_4 -> V_30 [ V_11 ] ) ;
F_14 ( & V_2 -> V_31 , & V_4 -> V_30 [ V_11 ] ) ;
F_14 ( & V_2 -> V_31 , & V_4 -> V_32 [ V_11 ] ) ;
}
if ( F_9 ( & V_16 -> V_21 ) )
F_15 ( V_4 ) ;
F_16 ( & V_4 -> V_33 ) ;
for ( V_12 = 0 ; V_12 < V_34 ; V_12 ++ ) {
F_17 ( V_4 -> V_35 . V_36 [ V_12 ] ) ;
V_14 = F_18 ( V_4 -> V_35 . V_14 [ V_12 ] ) ;
if ( ! V_14 )
continue;
F_14 ( & V_2 -> V_31 , & V_14 -> V_37 ) ;
F_17 ( V_14 ) ;
}
}
static void F_19 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_2 ;
F_7 ( V_4 ) ;
F_20 ( V_2 , V_4 ) ;
}
struct V_3 * F_21 ( struct V_15 * V_16 ,
const T_1 * V_7 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 ;
V_4 = F_22 ( V_2 -> V_6 [ F_3 ( V_7 ) ] ,
F_4 ( & V_2 -> V_8 ) ) ;
while ( V_4 ) {
if ( V_4 -> V_16 == V_16 &&
F_23 ( V_4 -> V_4 . V_7 , V_7 ) )
break;
V_4 = F_22 ( V_4 -> V_10 ,
F_4 ( & V_2 -> V_8 ) ) ;
}
return V_4 ;
}
struct V_3 * F_24 ( struct V_15 * V_16 ,
const T_1 * V_7 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 ;
V_4 = F_22 ( V_2 -> V_6 [ F_3 ( V_7 ) ] ,
F_4 ( & V_2 -> V_8 ) ) ;
while ( V_4 ) {
if ( ( V_4 -> V_16 == V_16 ||
( V_4 -> V_16 -> V_24 && V_4 -> V_16 -> V_24 == V_16 -> V_24 ) ) &&
F_23 ( V_4 -> V_4 . V_7 , V_7 ) )
break;
V_4 = F_22 ( V_4 -> V_10 ,
F_4 ( & V_2 -> V_8 ) ) ;
}
return V_4 ;
}
struct V_3 * F_25 ( struct V_15 * V_16 ,
int V_38 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 ;
int V_12 = 0 ;
F_26 (sta, &local->sta_list, list) {
if ( V_16 != V_4 -> V_16 )
continue;
if ( V_12 < V_38 ) {
++ V_12 ;
continue;
}
return V_4 ;
}
return NULL ;
}
void F_20 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_12 ;
if ( V_4 -> V_39 )
F_27 ( V_4 ) ;
if ( V_4 -> V_40 ) {
for ( V_12 = 0 ; V_12 < V_34 ; V_12 ++ )
F_17 ( V_4 -> V_40 [ V_12 ] . V_41 ) ;
F_17 ( V_4 -> V_40 ) ;
}
F_28 ( V_4 -> V_16 , L_1 , V_4 -> V_4 . V_7 ) ;
F_17 ( V_4 ) ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_30 ( & V_2 -> V_8 ) ;
V_4 -> V_10 = V_2 -> V_6 [ F_3 ( V_4 -> V_4 . V_7 ) ] ;
F_5 ( V_2 -> V_6 [ F_3 ( V_4 -> V_4 . V_7 ) ] , V_4 ) ;
}
static void F_31 ( struct V_42 * V_43 )
{
struct V_3 * V_4 ;
V_4 = F_32 ( V_43 , struct V_3 , V_33 ) ;
if ( V_4 -> V_44 )
return;
if ( ! F_8 ( V_4 , V_19 ) ) {
F_33 () ;
F_34 ( V_4 ) ;
F_35 () ;
} else if ( F_36 ( V_4 , V_45 ) ) {
F_10 ( V_4 , V_20 ) ;
F_33 () ;
F_37 ( V_4 ) ;
F_35 () ;
} else if ( F_36 ( V_4 , V_46 ) ) {
F_10 ( V_4 , V_20 ) ;
F_33 () ;
F_38 ( V_4 ) ;
F_35 () ;
} else
F_10 ( V_4 , V_20 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 V_47 )
{
if ( V_2 -> V_31 . V_48 & V_49 )
return 0 ;
V_4 -> V_39 = V_2 -> V_39 ;
V_4 -> V_50 = F_40 ( V_4 -> V_39 ,
& V_4 -> V_4 , V_47 ) ;
if ( ! V_4 -> V_50 )
return - V_51 ;
return 0 ;
}
struct V_3 * F_41 ( struct V_15 * V_16 ,
const T_1 * V_7 , T_2 V_47 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 ;
struct V_52 V_53 ;
struct V_54 * V_55 ;
int V_12 ;
V_4 = F_42 ( sizeof( * V_4 ) + V_2 -> V_31 . V_56 , V_47 ) ;
if ( ! V_4 )
return NULL ;
F_43 () ;
V_55 = F_44 ( V_2 -> V_55 ) ;
if ( V_55 ) {
V_4 -> V_40 = F_42 ( V_34 *
sizeof( struct V_57 ) ,
V_58 ) ;
if ( ! V_4 -> V_40 ) {
F_45 () ;
goto free;
}
if ( V_55 -> V_59 ) {
for ( V_12 = 0 ; V_12 < V_34 ; V_12 ++ ) {
V_4 -> V_40 [ V_12 ] . V_60 =
V_55 -> V_59 + 1 ;
V_4 -> V_40 [ V_12 ] . V_41 =
F_46 ( V_4 -> V_40 [ V_12 ] . V_60 ,
sizeof( V_61 ) , V_58 ) ;
if ( ! V_4 -> V_40 [ V_12 ] . V_41 ) {
F_45 () ;
goto free;
}
}
}
}
F_45 () ;
F_47 ( & V_4 -> V_62 ) ;
F_47 ( & V_4 -> V_63 ) ;
F_48 ( & V_4 -> V_33 , F_31 ) ;
F_48 ( & V_4 -> V_35 . V_64 , V_65 ) ;
F_49 ( & V_4 -> V_35 . V_66 ) ;
#ifdef F_50
if ( F_9 ( & V_16 -> V_21 ) &&
! V_16 -> V_25 . V_26 . V_67 )
F_51 ( & V_4 -> V_68 ) ;
V_4 -> V_69 = V_70 ;
#endif
memcpy ( V_4 -> V_4 . V_7 , V_7 , V_71 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_16 = V_16 ;
V_4 -> V_72 = V_73 ;
V_4 -> V_74 = V_75 ;
F_52 ( & V_53 ) ;
V_4 -> V_76 = V_53 . V_77 ;
F_53 ( & V_4 -> V_78 , 1024 , 8 ) ;
for ( V_12 = 0 ; V_12 < F_54 ( V_4 -> V_79 ) ; V_12 ++ )
F_53 ( & V_4 -> V_79 [ V_12 ] , 1024 , 8 ) ;
if ( F_39 ( V_2 , V_4 , V_47 ) )
goto free;
for ( V_12 = 0 ; V_12 < V_34 ; V_12 ++ ) {
V_4 -> V_80 [ V_12 ] = V_12 ;
}
for ( V_12 = 0 ; V_12 < V_28 ; V_12 ++ ) {
F_55 ( & V_4 -> V_30 [ V_12 ] ) ;
F_55 ( & V_4 -> V_32 [ V_12 ] ) ;
}
for ( V_12 = 0 ; V_12 < V_34 ; V_12 ++ )
V_4 -> V_81 [ V_12 ] = F_56 ( V_82 ) ;
V_4 -> V_4 . V_83 = V_84 ;
if ( V_16 -> V_21 . type == V_22 ||
V_16 -> V_21 . type == V_23 ) {
struct V_85 * V_86 =
V_2 -> V_31 . V_87 -> V_88 [ F_57 ( V_16 ) ] ;
T_1 V_89 = ( V_86 -> V_90 . V_91 & V_92 ) >>
V_93 ;
switch ( V_89 ) {
case V_94 :
V_4 -> V_95 = V_84 ;
break;
case V_96 :
V_4 -> V_95 = V_97 ;
break;
case V_98 :
V_4 -> V_95 = V_99 ;
break;
default:
F_58 ( 1 ) ;
}
}
F_28 ( V_16 , L_2 , V_4 -> V_4 . V_7 ) ;
return V_4 ;
free:
if ( V_4 -> V_40 ) {
for ( V_12 = 0 ; V_12 < V_34 ; V_12 ++ )
F_17 ( V_4 -> V_40 [ V_12 ] . V_41 ) ;
F_17 ( V_4 -> V_40 ) ;
}
F_17 ( V_4 ) ;
return NULL ;
}
static int F_59 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
if ( F_60 ( ! F_61 ( V_16 ) ) )
return - V_100 ;
if ( F_58 ( F_23 ( V_4 -> V_4 . V_7 , V_16 -> V_21 . V_7 ) ||
F_62 ( V_4 -> V_4 . V_7 ) ) )
return - V_101 ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_3 * V_4 )
{
enum V_102 V_103 ;
int V_104 = 0 ;
for ( V_103 = V_105 ; V_103 < V_4 -> V_74 ; V_103 ++ ) {
V_104 = F_64 ( V_2 , V_16 , V_4 , V_103 , V_103 + 1 ) ;
if ( V_104 )
break;
}
if ( ! V_104 ) {
if ( ! V_2 -> V_106 -> V_107 )
V_4 -> V_108 = true ;
return 0 ;
}
if ( V_16 -> V_21 . type == V_109 ) {
F_65 ( V_16 ,
L_3 ,
V_4 -> V_4 . V_7 , V_103 + 1 , V_104 ) ;
V_104 = 0 ;
}
for (; V_103 > V_105 ; V_103 -- )
F_58 ( F_64 ( V_2 , V_16 , V_4 , V_103 , V_103 - 1 ) ) ;
return V_104 ;
}
static int F_66 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_110 V_111 ;
int V_104 = 0 ;
F_30 ( & V_2 -> V_8 ) ;
if ( F_24 ( V_16 , V_4 -> V_4 . V_7 ) ) {
V_104 = - V_112 ;
goto V_113;
}
V_2 -> V_114 ++ ;
V_2 -> V_115 ++ ;
F_67 () ;
F_68 ( V_4 , V_116 ) ;
F_29 ( V_2 , V_4 ) ;
F_69 ( & V_4 -> V_117 , & V_2 -> V_118 ) ;
V_104 = F_63 ( V_2 , V_16 , V_4 ) ;
if ( V_104 )
goto V_119;
F_68 ( V_4 , V_120 ) ;
F_10 ( V_4 , V_116 ) ;
F_70 ( V_16 ) ;
F_71 ( V_4 ) ;
F_72 ( V_4 ) ;
memset ( & V_111 , 0 , sizeof( V_111 ) ) ;
V_111 . V_121 = 0 ;
V_111 . V_122 = V_2 -> V_115 ;
F_73 ( V_16 -> V_123 , V_4 -> V_4 . V_7 , & V_111 , V_124 ) ;
F_28 ( V_16 , L_4 , V_4 -> V_4 . V_7 ) ;
F_43 () ;
F_74 ( & V_2 -> V_8 ) ;
if ( F_9 ( & V_16 -> V_21 ) )
F_75 ( V_16 ) ;
return 0 ;
V_119:
F_1 ( V_2 , V_4 ) ;
F_76 ( & V_4 -> V_117 ) ;
V_2 -> V_114 -- ;
F_77 () ;
F_7 ( V_4 ) ;
V_113:
F_74 ( & V_2 -> V_8 ) ;
F_43 () ;
return V_104 ;
}
int F_78 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_104 = 0 ;
F_79 () ;
V_104 = F_59 ( V_4 ) ;
if ( V_104 ) {
F_43 () ;
goto V_125;
}
F_80 ( & V_2 -> V_8 ) ;
V_104 = F_66 ( V_4 ) ;
if ( V_104 )
goto V_125;
return 0 ;
V_125:
F_81 ( ! V_104 ) ;
F_20 ( V_2 , V_4 ) ;
return V_104 ;
}
int F_82 ( struct V_3 * V_4 )
{
int V_104 = F_78 ( V_4 ) ;
F_45 () ;
return V_104 ;
}
static inline void F_83 ( T_1 * V_126 , T_4 V_127 )
{
V_126 [ V_127 / 8 ] |= ( 1 << ( V_127 % 8 ) ) ;
}
static inline void F_84 ( T_1 * V_126 , T_4 V_127 )
{
V_126 [ V_127 / 8 ] &= ~ ( 1 << ( V_127 % 8 ) ) ;
}
static inline bool F_85 ( T_1 * V_126 , T_4 V_127 )
{
return V_126 [ V_127 / 8 ] & ( 1 << ( V_127 % 8 ) ) ;
}
static unsigned long F_86 ( int V_11 )
{
switch ( V_11 ) {
case V_128 :
return F_87 ( 6 ) | F_87 ( 7 ) ;
case V_129 :
return F_87 ( 4 ) | F_87 ( 5 ) ;
case V_130 :
return F_87 ( 0 ) | F_87 ( 3 ) ;
case V_131 :
return F_87 ( 1 ) | F_87 ( 2 ) ;
default:
F_58 ( 1 ) ;
return 0 ;
}
}
void F_12 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_17 * V_18 ;
bool V_132 = false ;
T_1 V_133 = V_4 -> V_4 . V_134 ;
int V_11 ;
T_4 V_127 ;
if ( V_4 -> V_16 -> V_21 . type == V_22 ||
V_4 -> V_16 -> V_21 . type == V_23 ) {
if ( F_88 ( ! V_4 -> V_16 -> V_24 ) )
return;
V_18 = & V_4 -> V_16 -> V_24 -> V_18 ;
V_127 = V_4 -> V_4 . V_135 ;
#ifdef F_50
} else if ( F_9 ( & V_4 -> V_16 -> V_21 ) ) {
V_18 = & V_4 -> V_16 -> V_25 . V_26 . V_18 ;
V_127 = V_4 -> V_136 % ( V_137 + 1 ) ;
#endif
} else {
return;
}
if ( V_2 -> V_31 . V_48 & V_138 )
return;
if ( V_4 -> V_44 )
goto V_139;
if ( V_133 == F_87 ( V_28 ) - 1 )
V_133 = 0 ;
for ( V_11 = 0 ; V_11 < V_28 ; V_11 ++ ) {
unsigned long V_140 ;
if ( V_133 & F_87 ( V_11 ) )
continue;
V_132 |= ! F_89 ( & V_4 -> V_32 [ V_11 ] ) ||
! F_89 ( & V_4 -> V_30 [ V_11 ] ) ;
if ( V_132 )
break;
V_140 = F_86 ( V_11 ) ;
V_132 |=
V_4 -> V_141 & V_140 ;
}
V_139:
F_90 ( & V_2 -> V_142 ) ;
if ( V_132 == F_85 ( V_18 -> V_126 , V_127 ) )
goto V_143;
if ( V_132 )
F_83 ( V_18 -> V_126 , V_127 ) ;
else
F_84 ( V_18 -> V_126 , V_127 ) ;
if ( V_2 -> V_106 -> V_144 ) {
V_2 -> V_145 = true ;
F_91 ( V_2 , & V_4 -> V_4 , V_132 ) ;
V_2 -> V_145 = false ;
}
V_143:
F_92 ( & V_2 -> V_142 ) ;
}
static bool F_93 ( struct V_3 * V_4 , struct V_146 * V_147 )
{
struct V_148 * V_149 ;
int V_150 ;
if ( ! V_147 )
return false ;
V_149 = F_94 ( V_147 ) ;
V_150 = ( V_4 -> V_151 *
V_4 -> V_16 -> V_21 . V_152 . V_153 *
32 / 15625 ) * V_154 ;
if ( V_150 < V_155 )
V_150 = V_155 ;
return F_95 ( V_73 , V_149 -> V_156 . V_73 + V_150 ) ;
}
static bool F_96 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_11 )
{
unsigned long V_48 ;
struct V_146 * V_147 ;
for (; ; ) {
F_97 ( & V_4 -> V_32 [ V_11 ] . V_62 , V_48 ) ;
V_147 = F_98 ( & V_4 -> V_32 [ V_11 ] ) ;
if ( F_93 ( V_4 , V_147 ) )
V_147 = F_99 ( & V_4 -> V_32 [ V_11 ] ) ;
else
V_147 = NULL ;
F_100 ( & V_4 -> V_32 [ V_11 ] . V_62 , V_48 ) ;
if ( ! V_147 )
break;
F_101 ( & V_2 -> V_31 , V_147 ) ;
}
for (; ; ) {
F_97 ( & V_4 -> V_30 [ V_11 ] . V_62 , V_48 ) ;
V_147 = F_98 ( & V_4 -> V_30 [ V_11 ] ) ;
if ( F_93 ( V_4 , V_147 ) )
V_147 = F_99 ( & V_4 -> V_30 [ V_11 ] ) ;
else
V_147 = NULL ;
F_100 ( & V_4 -> V_30 [ V_11 ] . V_62 , V_48 ) ;
if ( ! V_147 )
break;
V_2 -> V_29 -- ;
F_102 ( V_4 -> V_16 , L_5 ,
V_4 -> V_4 . V_7 ) ;
F_101 ( & V_2 -> V_31 , V_147 ) ;
}
F_12 ( V_4 ) ;
return ! ( F_89 ( & V_4 -> V_30 [ V_11 ] ) &&
F_89 ( & V_4 -> V_32 [ V_11 ] ) ) ;
}
static bool F_103 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_157 = false ;
int V_11 ;
if ( ! V_4 -> V_16 -> V_24 &&
! F_9 ( & V_4 -> V_16 -> V_21 ) )
return false ;
for ( V_11 = 0 ; V_11 < V_28 ; V_11 ++ )
V_157 |=
F_96 ( V_2 , V_4 , V_11 ) ;
return V_157 ;
}
static int T_5 F_104 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_15 * V_16 ;
int V_158 ;
F_79 () ;
if ( ! V_4 )
return - V_9 ;
V_2 = V_4 -> V_2 ;
V_16 = V_4 -> V_16 ;
F_30 ( & V_2 -> V_8 ) ;
F_68 ( V_4 , V_116 ) ;
F_105 ( V_4 , V_159 ) ;
V_158 = F_1 ( V_2 , V_4 ) ;
if ( F_58 ( V_158 ) )
return V_158 ;
F_76 ( & V_4 -> V_117 ) ;
F_106 ( V_2 , V_4 -> V_16 , V_4 ) ;
if ( V_16 -> V_21 . type == V_23 &&
F_6 ( V_16 -> V_25 . V_160 . V_4 ) == V_4 )
F_107 ( V_16 -> V_25 . V_160 . V_4 , NULL ) ;
return 0 ;
}
static void F_108 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_15 * V_16 = V_4 -> V_16 ;
int V_158 ;
F_79 () ;
F_30 ( & V_2 -> V_8 ) ;
F_109 ( V_2 , V_4 ) ;
V_4 -> V_44 = true ;
V_2 -> V_114 -- ;
V_2 -> V_115 ++ ;
while ( V_4 -> V_74 > V_75 ) {
V_158 = F_110 ( V_4 , V_4 -> V_74 - 1 ) ;
if ( V_158 ) {
F_88 ( 1 ) ;
break;
}
}
if ( V_4 -> V_108 ) {
V_158 = F_64 ( V_2 , V_16 , V_4 , V_75 ,
V_105 ) ;
F_88 ( V_158 != 0 ) ;
}
F_28 ( V_16 , L_6 , V_4 -> V_4 . V_7 ) ;
F_111 ( V_16 -> V_123 , V_4 -> V_4 . V_7 , V_124 ) ;
F_112 ( V_4 ) ;
F_113 ( V_4 ) ;
F_70 ( V_16 ) ;
F_19 ( V_4 ) ;
}
int T_5 F_114 ( struct V_3 * V_4 )
{
int V_104 = F_104 ( V_4 ) ;
if ( V_104 )
return V_104 ;
F_77 () ;
F_108 ( V_4 ) ;
return 0 ;
}
int F_115 ( struct V_15 * V_16 , const T_1 * V_7 )
{
struct V_3 * V_4 ;
int V_158 ;
F_80 ( & V_16 -> V_2 -> V_8 ) ;
V_4 = F_21 ( V_16 , V_7 ) ;
V_158 = F_114 ( V_4 ) ;
F_74 ( & V_16 -> V_2 -> V_8 ) ;
return V_158 ;
}
int F_116 ( struct V_15 * V_16 ,
const T_1 * V_7 )
{
struct V_3 * V_4 ;
int V_158 ;
F_80 ( & V_16 -> V_2 -> V_8 ) ;
V_4 = F_24 ( V_16 , V_7 ) ;
V_158 = F_114 ( V_4 ) ;
F_74 ( & V_16 -> V_2 -> V_8 ) ;
return V_158 ;
}
static void F_117 ( unsigned long V_161 )
{
struct V_1 * V_2 = (struct V_1 * ) V_161 ;
struct V_3 * V_4 ;
bool V_162 = false ;
F_43 () ;
F_26 (sta, &local->sta_list, list)
if ( F_103 ( V_2 , V_4 ) )
V_162 = true ;
F_45 () ;
if ( V_2 -> V_163 )
return;
if ( ! V_162 )
return;
F_118 ( & V_2 -> V_164 ,
F_119 ( V_73 + V_165 ) ) ;
}
void F_120 ( struct V_1 * V_2 )
{
F_47 ( & V_2 -> V_142 ) ;
F_49 ( & V_2 -> V_8 ) ;
F_121 ( & V_2 -> V_118 ) ;
F_122 ( & V_2 -> V_164 , F_117 ,
( unsigned long ) V_2 ) ;
}
void F_123 ( struct V_1 * V_2 )
{
F_124 ( & V_2 -> V_164 ) ;
}
int F_125 ( struct V_15 * V_16 , bool V_166 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 , * V_167 ;
F_126 ( V_168 ) ;
int V_158 = 0 ;
F_79 () ;
F_58 ( V_166 && V_16 -> V_21 . type != V_22 ) ;
F_58 ( V_166 && ! V_16 -> V_24 ) ;
F_80 ( & V_2 -> V_8 ) ;
F_127 (sta, tmp, &local->sta_list, list) {
if ( V_16 == V_4 -> V_16 ||
( V_166 && V_16 -> V_24 == V_4 -> V_16 -> V_24 ) ) {
if ( ! F_58 ( F_104 ( V_4 ) ) )
F_128 ( & V_4 -> V_168 , & V_168 ) ;
V_158 ++ ;
}
}
if ( ! F_129 ( & V_168 ) ) {
F_77 () ;
F_127 (sta, tmp, &free_list, free_list)
F_108 ( V_4 ) ;
}
F_74 ( & V_2 -> V_8 ) ;
return V_158 ;
}
void F_130 ( struct V_15 * V_16 ,
unsigned long V_169 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 , * V_167 ;
F_80 ( & V_2 -> V_8 ) ;
F_127 (sta, tmp, &local->sta_list, list) {
if ( V_16 != V_4 -> V_16 )
continue;
if ( F_95 ( V_73 , V_4 -> V_72 + V_169 ) ) {
F_28 ( V_4 -> V_16 , L_7 ,
V_4 -> V_4 . V_7 ) ;
if ( F_9 ( & V_16 -> V_21 ) &&
F_8 ( V_4 , V_19 ) )
F_11 ( & V_16 -> V_25 . V_26 . V_18 . V_27 ) ;
F_58 ( F_114 ( V_4 ) ) ;
}
}
F_74 ( & V_2 -> V_8 ) ;
}
struct V_170 * F_131 ( struct V_171 * V_31 ,
const T_1 * V_7 ,
const T_1 * V_172 )
{
struct V_3 * V_4 , * V_173 ;
F_132 (hw_to_local(hw), addr, sta, nxt) {
if ( V_172 &&
! F_23 ( V_4 -> V_16 -> V_21 . V_7 , V_172 ) )
continue;
if ( ! V_4 -> V_108 )
return NULL ;
return & V_4 -> V_4 ;
}
return NULL ;
}
struct V_170 * F_133 ( struct V_174 * V_21 ,
const T_1 * V_7 )
{
struct V_3 * V_4 ;
if ( ! V_21 )
return NULL ;
V_4 = F_24 ( F_134 ( V_21 ) , V_7 ) ;
if ( ! V_4 )
return NULL ;
if ( ! V_4 -> V_108 )
return NULL ;
return & V_4 -> V_4 ;
}
void F_34 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_175 V_37 ;
int V_176 = 0 , V_177 = 0 , V_11 ;
unsigned long V_48 ;
struct V_17 * V_18 ;
if ( V_16 -> V_21 . type == V_22 ||
V_16 -> V_21 . type == V_23 )
V_18 = & V_16 -> V_24 -> V_18 ;
else if ( F_9 ( & V_16 -> V_21 ) )
V_18 = & V_16 -> V_25 . V_26 . V_18 ;
else
return;
F_10 ( V_4 , V_178 ) ;
F_135 ( F_136 ( V_34 ) > 1 ) ;
V_4 -> V_141 = 0 ;
if ( ! ( V_2 -> V_31 . V_48 & V_138 ) )
F_137 ( V_2 , V_16 , V_179 , & V_4 -> V_4 ) ;
F_55 ( & V_37 ) ;
F_138 ( & V_4 -> V_63 ) ;
for ( V_11 = 0 ; V_11 < V_28 ; V_11 ++ ) {
int V_180 = F_13 ( & V_37 ) , V_167 ;
F_97 ( & V_4 -> V_32 [ V_11 ] . V_62 , V_48 ) ;
F_139 ( & V_4 -> V_32 [ V_11 ] , & V_37 ) ;
F_100 ( & V_4 -> V_32 [ V_11 ] . V_62 , V_48 ) ;
V_167 = F_13 ( & V_37 ) ;
V_176 += V_167 - V_180 ;
V_180 = V_167 ;
F_97 ( & V_4 -> V_30 [ V_11 ] . V_62 , V_48 ) ;
F_139 ( & V_4 -> V_30 [ V_11 ] , & V_37 ) ;
F_100 ( & V_4 -> V_30 [ V_11 ] . V_62 , V_48 ) ;
V_167 = F_13 ( & V_37 ) ;
V_177 += V_167 - V_180 ;
}
F_140 ( V_2 , & V_37 ) ;
F_10 ( V_4 , V_20 ) ;
F_10 ( V_4 , V_19 ) ;
F_141 ( & V_4 -> V_63 ) ;
F_11 ( & V_18 -> V_27 ) ;
if ( ! F_9 ( & V_16 -> V_21 ) &&
! F_142 ( V_4 -> V_95 ,
V_16 -> V_83 ) &&
V_4 -> V_95 != V_16 -> V_24 -> V_181 &&
F_143 ( V_4 ) != 1 ) {
F_144 ( V_16 ,
L_8 ,
V_4 -> V_4 . V_7 ) ;
F_145 ( V_16 , V_16 -> V_24 -> V_181 ,
V_4 -> V_4 . V_7 ,
V_16 -> V_21 . V_152 . V_182 ) ;
}
V_2 -> V_29 -= V_177 ;
F_12 ( V_4 ) ;
F_102 ( V_16 ,
L_9 ,
V_4 -> V_4 . V_7 , V_4 -> V_4 . V_135 , V_176 , V_177 ) ;
}
static void F_146 ( struct V_15 * V_16 ,
struct V_3 * V_4 , int V_183 ,
enum V_184 V_185 ,
bool V_186 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_187 * V_188 ;
struct V_146 * V_147 ;
int V_189 = sizeof( * V_188 ) ;
T_6 V_190 ;
bool V_191 = F_8 ( V_4 , V_192 ) ;
struct V_148 * V_149 ;
struct V_193 * V_194 ;
if ( V_191 ) {
V_190 = F_56 ( V_195 |
V_196 |
V_197 ) ;
} else {
V_189 -= 2 ;
V_190 = F_56 ( V_195 |
V_198 |
V_197 ) ;
}
V_147 = F_147 ( V_2 -> V_31 . V_199 + V_189 ) ;
if ( ! V_147 )
return;
F_148 ( V_147 , V_2 -> V_31 . V_199 ) ;
V_188 = ( void * ) F_149 ( V_147 , V_189 ) ;
V_188 -> V_200 = V_190 ;
V_188 -> V_201 = 0 ;
memcpy ( V_188 -> V_202 , V_4 -> V_4 . V_7 , V_71 ) ;
memcpy ( V_188 -> V_203 , V_16 -> V_21 . V_7 , V_71 ) ;
memcpy ( V_188 -> V_204 , V_16 -> V_21 . V_7 , V_71 ) ;
V_188 -> V_205 = 0 ;
V_147 -> V_206 = V_183 ;
F_150 ( V_147 , V_207 [ V_183 ] ) ;
if ( V_191 ) {
V_188 -> V_208 = F_56 ( V_183 ) ;
if ( V_185 == V_209 )
V_188 -> V_208 |=
F_56 ( V_210 ) ;
}
V_149 = F_94 ( V_147 ) ;
V_149 -> V_48 |= V_211 |
V_212 |
V_213 |
V_214 ;
if ( V_186 )
F_151 ( V_2 , V_4 , F_87 ( V_183 ) , 1 ,
V_185 , false ) ;
V_147 -> V_123 = V_16 -> V_123 ;
F_43 () ;
V_194 = F_44 ( V_16 -> V_21 . V_194 ) ;
if ( F_58 ( ! V_194 ) ) {
F_45 () ;
F_152 ( V_147 ) ;
return;
}
F_153 ( V_16 , V_147 , V_194 -> V_215 . V_216 -> V_217 ) ;
F_45 () ;
}
static int F_154 ( unsigned long V_140 )
{
if ( V_140 & 0xF8 )
return F_155 ( V_140 ) - 1 ;
if ( V_140 & F_87 ( 0 ) )
return 0 ;
return F_155 ( V_140 ) - 1 ;
}
static void
F_156 ( struct V_3 * V_4 ,
int V_218 , T_1 V_219 ,
enum V_184 V_185 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_2 ;
bool V_220 = false ;
int V_11 ;
unsigned long V_221 = 0 ;
struct V_175 V_222 ;
F_68 ( V_4 , V_178 ) ;
F_157 ( & V_222 ) ;
for ( V_11 = 0 ; V_11 < V_28 ; V_11 ++ ) {
unsigned long V_140 ;
if ( V_219 & F_87 ( V_11 ) )
continue;
V_140 = F_86 ( V_11 ) ;
if ( F_89 ( & V_222 ) )
V_221 |= V_4 -> V_141 & V_140 ;
if ( V_221 ) {
if ( V_185 == V_223 &&
F_158 ( V_221 ) > 1 ) {
V_220 = true ;
V_221 =
F_87 ( F_154 (
V_221 ) ) ;
break;
}
} else {
struct V_146 * V_147 ;
while ( V_218 > 0 ) {
V_147 = F_159 ( & V_4 -> V_32 [ V_11 ] ) ;
if ( ! V_147 ) {
V_147 = F_159 (
& V_4 -> V_30 [ V_11 ] ) ;
if ( V_147 )
V_2 -> V_29 -- ;
}
if ( ! V_147 )
break;
V_218 -- ;
F_160 ( & V_222 , V_147 ) ;
}
}
if ( ! F_89 ( & V_4 -> V_32 [ V_11 ] ) ||
! F_89 ( & V_4 -> V_30 [ V_11 ] ) ) {
V_220 = true ;
break;
}
}
if ( F_89 ( & V_222 ) && ! V_221 ) {
int V_183 ;
V_183 = 7 - ( ( F_161 ( ~ V_219 ) - 1 ) << 1 ) ;
F_146 ( V_16 , V_4 , V_183 , V_185 , true ) ;
} else if ( ! V_221 ) {
struct V_175 V_37 ;
struct V_146 * V_147 ;
int V_224 = 0 ;
T_4 V_140 = 0 ;
bool V_225 = false ;
F_55 ( & V_37 ) ;
while ( ( V_147 = F_99 ( & V_222 ) ) ) {
struct V_148 * V_149 = F_94 ( V_147 ) ;
struct V_226 * V_227 = ( void * ) V_147 -> V_161 ;
T_1 * V_228 = NULL ;
V_224 ++ ;
V_149 -> V_48 |= V_211 |
V_212 ;
if ( V_220 || ! F_89 ( & V_222 ) )
V_227 -> V_200 |=
F_56 ( V_229 ) ;
else
V_227 -> V_200 &=
F_56 ( ~ V_229 ) ;
if ( F_162 ( V_227 -> V_200 ) ||
F_163 ( V_227 -> V_200 ) )
V_228 = F_164 ( V_227 ) ;
V_140 |= F_87 ( V_147 -> V_206 ) ;
F_160 ( & V_37 , V_147 ) ;
if ( ! F_89 ( & V_222 ) )
continue;
if ( V_185 != V_209 ) {
V_149 -> V_48 |= V_213 |
V_214 ;
break;
}
if ( V_228 ) {
* V_228 |= V_210 ;
V_149 -> V_48 |= V_213 |
V_214 ;
} else {
V_227 -> V_200 |=
F_56 ( V_229 ) ;
V_225 = true ;
V_224 ++ ;
}
break;
}
F_151 ( V_2 , V_4 , V_140 , V_224 ,
V_185 , V_220 ) ;
F_140 ( V_2 , & V_37 ) ;
if ( V_225 )
F_146 (
V_16 , V_4 , F_154 ( V_140 ) ,
V_185 , false ) ;
F_12 ( V_4 ) ;
} else {
F_165 ( V_2 , V_4 , V_221 ,
V_218 , V_185 , V_220 ) ;
}
}
void F_37 ( struct V_3 * V_4 )
{
T_1 V_230 = V_4 -> V_4 . V_134 ;
if ( V_230 == F_87 ( V_28 ) - 1 )
V_230 = 0 ;
F_156 ( V_4 , 1 , V_230 ,
V_223 ) ;
}
void F_38 ( struct V_3 * V_4 )
{
int V_218 = V_4 -> V_4 . V_231 ;
T_1 V_232 = V_4 -> V_4 . V_134 ;
if ( ! V_232 )
return;
switch ( V_4 -> V_4 . V_231 ) {
case 1 :
V_218 = 2 ;
break;
case 2 :
V_218 = 4 ;
break;
case 3 :
V_218 = 6 ;
break;
case 0 :
V_218 = 8 ;
break;
}
F_156 ( V_4 , V_218 , ~ V_232 ,
V_209 ) ;
}
void F_166 ( struct V_171 * V_31 ,
struct V_170 * V_233 , bool V_234 )
{
struct V_3 * V_4 = F_32 ( V_233 , struct V_3 , V_4 ) ;
F_167 ( V_4 -> V_2 , V_233 , V_234 ) ;
if ( V_234 )
F_68 ( V_4 , V_20 ) ;
else if ( F_8 ( V_4 , V_20 ) )
F_168 ( V_31 , & V_4 -> V_33 ) ;
}
void F_169 ( struct V_170 * V_233 )
{
struct V_3 * V_4 = F_32 ( V_233 , struct V_3 , V_4 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_170 ( V_2 , V_233 ) ;
F_10 ( V_4 , V_178 ) ;
}
void F_171 ( struct V_170 * V_233 ,
T_1 V_183 , bool V_177 )
{
struct V_3 * V_4 = F_32 ( V_233 , struct V_3 , V_4 ) ;
if ( F_58 ( V_183 >= V_34 ) )
return;
F_172 ( V_4 -> V_2 , V_233 , V_183 , V_177 ) ;
if ( V_177 )
F_173 ( V_183 , & V_4 -> V_141 ) ;
else
F_174 ( V_183 , & V_4 -> V_141 ) ;
F_12 ( V_4 ) ;
}
int F_110 ( struct V_3 * V_4 ,
enum V_102 V_235 )
{
F_79 () ;
if ( V_4 -> V_74 == V_235 )
return 0 ;
switch ( V_235 ) {
case V_75 :
if ( V_4 -> V_74 != V_236 )
return - V_101 ;
break;
case V_236 :
if ( V_4 -> V_74 != V_75 &&
V_4 -> V_74 != V_237 )
return - V_101 ;
break;
case V_237 :
if ( V_4 -> V_74 != V_236 &&
V_4 -> V_74 != V_238 )
return - V_101 ;
break;
case V_238 :
if ( V_4 -> V_74 != V_237 )
return - V_101 ;
break;
default:
F_175 ( 1 , L_10 , V_235 ) ;
return - V_101 ;
}
F_28 ( V_4 -> V_16 , L_11 ,
V_4 -> V_4 . V_7 , V_235 ) ;
if ( F_8 ( V_4 , V_120 ) ) {
int V_104 = F_64 ( V_4 -> V_2 , V_4 -> V_16 , V_4 ,
V_4 -> V_74 , V_235 ) ;
if ( V_104 )
return V_104 ;
}
switch ( V_235 ) {
case V_75 :
if ( V_4 -> V_74 == V_236 )
F_174 ( V_239 , & V_4 -> V_240 ) ;
break;
case V_236 :
if ( V_4 -> V_74 == V_75 )
F_173 ( V_239 , & V_4 -> V_240 ) ;
else if ( V_4 -> V_74 == V_237 )
F_174 ( V_241 , & V_4 -> V_240 ) ;
break;
case V_237 :
if ( V_4 -> V_74 == V_236 ) {
F_173 ( V_241 , & V_4 -> V_240 ) ;
} else if ( V_4 -> V_74 == V_238 ) {
if ( V_4 -> V_16 -> V_21 . type == V_22 ||
( V_4 -> V_16 -> V_21 . type == V_23 &&
! V_4 -> V_16 -> V_25 . V_160 . V_4 ) )
F_11 ( & V_4 -> V_16 -> V_24 -> V_242 ) ;
F_174 ( V_243 , & V_4 -> V_240 ) ;
}
break;
case V_238 :
if ( V_4 -> V_74 == V_237 ) {
if ( V_4 -> V_16 -> V_21 . type == V_22 ||
( V_4 -> V_16 -> V_21 . type == V_23 &&
! V_4 -> V_16 -> V_25 . V_160 . V_4 ) )
F_176 ( & V_4 -> V_16 -> V_24 -> V_242 ) ;
F_173 ( V_243 , & V_4 -> V_240 ) ;
}
break;
default:
break;
}
V_4 -> V_74 = V_235 ;
return 0 ;
}
T_1 F_143 ( struct V_3 * V_4 )
{
struct V_244 * V_90 = & V_4 -> V_4 . V_90 ;
T_1 V_245 ;
if ( ! V_4 -> V_4 . V_90 . V_246 )
return 1 ;
if ( V_4 -> V_4 . V_247 . V_248 ) {
int V_12 ;
T_4 V_249 =
F_177 ( V_4 -> V_4 . V_247 . V_250 . V_249 ) ;
for ( V_12 = 7 ; V_12 >= 0 ; V_12 -- )
if ( ( V_249 & ( 0x3 << ( V_12 * 2 ) ) ) !=
V_251 )
return V_12 + 1 ;
}
if ( V_90 -> V_252 . V_253 [ 3 ] )
V_245 = 4 ;
else if ( V_90 -> V_252 . V_253 [ 2 ] )
V_245 = 3 ;
else if ( V_90 -> V_252 . V_253 [ 1 ] )
V_245 = 2 ;
else
V_245 = 1 ;
if ( ! ( V_90 -> V_252 . V_254 & V_255 ) )
return V_245 ;
return ( ( V_90 -> V_252 . V_254 & V_256 )
>> V_257 ) + 1 ;
}
