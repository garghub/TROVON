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
F_17 ( F_18 ( V_4 -> V_4 . V_42 ) ) ;
F_17 ( V_4 ) ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_30 ( & V_2 -> V_8 ) ;
V_4 -> V_10 = V_2 -> V_6 [ F_3 ( V_4 -> V_4 . V_7 ) ] ;
F_5 ( V_2 -> V_6 [ F_3 ( V_4 -> V_4 . V_7 ) ] , V_4 ) ;
}
static void F_31 ( struct V_43 * V_44 )
{
struct V_3 * V_4 ;
V_4 = F_32 ( V_44 , struct V_3 , V_33 ) ;
if ( V_4 -> V_45 )
return;
if ( ! F_8 ( V_4 , V_19 ) ) {
F_33 () ;
F_34 ( V_4 ) ;
F_35 () ;
} else if ( F_36 ( V_4 , V_46 ) ) {
F_10 ( V_4 , V_20 ) ;
F_33 () ;
F_37 ( V_4 ) ;
F_35 () ;
} else if ( F_36 ( V_4 , V_47 ) ) {
F_10 ( V_4 , V_20 ) ;
F_33 () ;
F_38 ( V_4 ) ;
F_35 () ;
} else
F_10 ( V_4 , V_20 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 V_48 )
{
if ( V_2 -> V_31 . V_49 & V_50 )
return 0 ;
V_4 -> V_39 = V_2 -> V_39 ;
V_4 -> V_51 = F_40 ( V_4 -> V_39 ,
& V_4 -> V_4 , V_48 ) ;
if ( ! V_4 -> V_51 )
return - V_52 ;
return 0 ;
}
struct V_3 * F_41 ( struct V_15 * V_16 ,
const T_1 * V_7 , T_2 V_48 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 ;
struct V_53 V_54 ;
struct V_55 * V_56 ;
int V_12 ;
V_4 = F_42 ( sizeof( * V_4 ) + V_2 -> V_31 . V_57 , V_48 ) ;
if ( ! V_4 )
return NULL ;
F_43 () ;
V_56 = F_44 ( V_2 -> V_56 ) ;
if ( V_56 ) {
V_4 -> V_40 = F_42 ( V_34 *
sizeof( struct V_58 ) ,
V_59 ) ;
if ( ! V_4 -> V_40 ) {
F_45 () ;
goto free;
}
if ( V_56 -> V_60 ) {
for ( V_12 = 0 ; V_12 < V_34 ; V_12 ++ ) {
V_4 -> V_40 [ V_12 ] . V_61 =
V_56 -> V_60 + 1 ;
V_4 -> V_40 [ V_12 ] . V_41 =
F_46 ( V_4 -> V_40 [ V_12 ] . V_61 ,
sizeof( V_62 ) , V_59 ) ;
if ( ! V_4 -> V_40 [ V_12 ] . V_41 ) {
F_45 () ;
goto free;
}
}
}
}
F_45 () ;
F_47 ( & V_4 -> V_63 ) ;
F_47 ( & V_4 -> V_64 ) ;
F_48 ( & V_4 -> V_33 , F_31 ) ;
F_48 ( & V_4 -> V_35 . V_65 , V_66 ) ;
F_49 ( & V_4 -> V_35 . V_67 ) ;
#ifdef F_50
if ( F_9 ( & V_16 -> V_21 ) &&
! V_16 -> V_25 . V_26 . V_68 )
F_51 ( & V_4 -> V_69 ) ;
V_4 -> V_70 = V_71 ;
#endif
memcpy ( V_4 -> V_4 . V_7 , V_7 , V_72 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_16 = V_16 ;
V_4 -> V_73 = V_74 ;
V_4 -> V_75 = V_76 ;
F_52 ( & V_54 ) ;
V_4 -> V_77 = V_54 . V_78 ;
F_53 ( & V_4 -> V_79 , 1024 , 8 ) ;
for ( V_12 = 0 ; V_12 < F_54 ( V_4 -> V_80 ) ; V_12 ++ )
F_53 ( & V_4 -> V_80 [ V_12 ] , 1024 , 8 ) ;
if ( F_39 ( V_2 , V_4 , V_48 ) )
goto free;
for ( V_12 = 0 ; V_12 < V_34 ; V_12 ++ ) {
V_4 -> V_81 [ V_12 ] = V_12 ;
}
for ( V_12 = 0 ; V_12 < V_28 ; V_12 ++ ) {
F_55 ( & V_4 -> V_30 [ V_12 ] ) ;
F_55 ( & V_4 -> V_32 [ V_12 ] ) ;
}
for ( V_12 = 0 ; V_12 < V_34 ; V_12 ++ )
V_4 -> V_82 [ V_12 ] = F_56 ( V_83 ) ;
V_4 -> V_4 . V_84 = V_85 ;
if ( V_16 -> V_21 . type == V_22 ||
V_16 -> V_21 . type == V_23 ) {
struct V_86 * V_87 =
V_2 -> V_31 . V_88 -> V_89 [ F_57 ( V_16 ) ] ;
T_1 V_90 = ( V_87 -> V_91 . V_92 & V_93 ) >>
V_94 ;
switch ( V_90 ) {
case V_95 :
V_4 -> V_96 = V_85 ;
break;
case V_97 :
V_4 -> V_96 = V_98 ;
break;
case V_99 :
V_4 -> V_96 = V_100 ;
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
return - V_101 ;
if ( F_58 ( F_23 ( V_4 -> V_4 . V_7 , V_16 -> V_21 . V_7 ) ||
F_62 ( V_4 -> V_4 . V_7 ) ) )
return - V_102 ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_3 * V_4 )
{
enum V_103 V_104 ;
int V_105 = 0 ;
for ( V_104 = V_106 ; V_104 < V_4 -> V_75 ; V_104 ++ ) {
V_105 = F_64 ( V_2 , V_16 , V_4 , V_104 , V_104 + 1 ) ;
if ( V_105 )
break;
}
if ( ! V_105 ) {
if ( ! V_2 -> V_107 -> V_108 )
V_4 -> V_109 = true ;
return 0 ;
}
if ( V_16 -> V_21 . type == V_110 ) {
F_65 ( V_16 ,
L_3 ,
V_4 -> V_4 . V_7 , V_104 + 1 , V_105 ) ;
V_105 = 0 ;
}
for (; V_104 > V_106 ; V_104 -- )
F_58 ( F_64 ( V_2 , V_16 , V_4 , V_104 , V_104 - 1 ) ) ;
return V_105 ;
}
static int F_66 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_111 V_112 ;
int V_105 = 0 ;
F_30 ( & V_2 -> V_8 ) ;
if ( F_24 ( V_16 , V_4 -> V_4 . V_7 ) ) {
V_105 = - V_113 ;
goto V_114;
}
V_2 -> V_115 ++ ;
V_2 -> V_116 ++ ;
F_67 () ;
F_68 ( V_4 , V_117 ) ;
F_29 ( V_2 , V_4 ) ;
F_69 ( & V_4 -> V_118 , & V_2 -> V_119 ) ;
V_105 = F_63 ( V_2 , V_16 , V_4 ) ;
if ( V_105 )
goto V_120;
F_68 ( V_4 , V_121 ) ;
F_10 ( V_4 , V_117 ) ;
F_70 ( V_16 ) ;
F_71 ( V_4 ) ;
F_72 ( V_4 ) ;
memset ( & V_112 , 0 , sizeof( V_112 ) ) ;
V_112 . V_122 = 0 ;
V_112 . V_123 = V_2 -> V_116 ;
F_73 ( V_16 -> V_124 , V_4 -> V_4 . V_7 , & V_112 , V_125 ) ;
F_28 ( V_16 , L_4 , V_4 -> V_4 . V_7 ) ;
F_43 () ;
F_74 ( & V_2 -> V_8 ) ;
if ( F_9 ( & V_16 -> V_21 ) )
F_75 ( V_16 ) ;
return 0 ;
V_120:
F_1 ( V_2 , V_4 ) ;
F_76 ( & V_4 -> V_118 ) ;
V_2 -> V_115 -- ;
F_77 () ;
F_7 ( V_4 ) ;
V_114:
F_74 ( & V_2 -> V_8 ) ;
F_43 () ;
return V_105 ;
}
int F_78 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_105 ;
F_79 () ;
V_105 = F_59 ( V_4 ) ;
if ( V_105 ) {
F_43 () ;
goto V_126;
}
F_80 ( & V_2 -> V_8 ) ;
V_105 = F_66 ( V_4 ) ;
if ( V_105 )
goto V_126;
return 0 ;
V_126:
F_20 ( V_2 , V_4 ) ;
return V_105 ;
}
int F_81 ( struct V_3 * V_4 )
{
int V_105 = F_78 ( V_4 ) ;
F_45 () ;
return V_105 ;
}
static inline void F_82 ( T_1 * V_127 , T_4 V_128 )
{
V_127 [ V_128 / 8 ] |= ( 1 << ( V_128 % 8 ) ) ;
}
static inline void F_83 ( T_1 * V_127 , T_4 V_128 )
{
V_127 [ V_128 / 8 ] &= ~ ( 1 << ( V_128 % 8 ) ) ;
}
static inline bool F_84 ( T_1 * V_127 , T_4 V_128 )
{
return V_127 [ V_128 / 8 ] & ( 1 << ( V_128 % 8 ) ) ;
}
static unsigned long F_85 ( int V_11 )
{
switch ( V_11 ) {
case V_129 :
return F_86 ( 6 ) | F_86 ( 7 ) ;
case V_130 :
return F_86 ( 4 ) | F_86 ( 5 ) ;
case V_131 :
return F_86 ( 0 ) | F_86 ( 3 ) ;
case V_132 :
return F_86 ( 1 ) | F_86 ( 2 ) ;
default:
F_58 ( 1 ) ;
return 0 ;
}
}
void F_12 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_17 * V_18 ;
bool V_133 = false ;
T_1 V_134 = V_4 -> V_4 . V_135 ;
int V_11 ;
T_4 V_128 ;
if ( V_4 -> V_16 -> V_21 . type == V_22 ||
V_4 -> V_16 -> V_21 . type == V_23 ) {
if ( F_87 ( ! V_4 -> V_16 -> V_24 ) )
return;
V_18 = & V_4 -> V_16 -> V_24 -> V_18 ;
V_128 = V_4 -> V_4 . V_136 ;
#ifdef F_50
} else if ( F_9 ( & V_4 -> V_16 -> V_21 ) ) {
V_18 = & V_4 -> V_16 -> V_25 . V_26 . V_18 ;
V_128 = V_4 -> V_137 % ( V_138 + 1 ) ;
#endif
} else {
return;
}
if ( V_2 -> V_31 . V_49 & V_139 )
return;
if ( V_4 -> V_45 )
goto V_140;
if ( V_134 == F_86 ( V_28 ) - 1 )
V_134 = 0 ;
for ( V_11 = 0 ; V_11 < V_28 ; V_11 ++ ) {
unsigned long V_141 ;
if ( V_134 & F_86 ( V_11 ) )
continue;
V_133 |= ! F_88 ( & V_4 -> V_32 [ V_11 ] ) ||
! F_88 ( & V_4 -> V_30 [ V_11 ] ) ;
if ( V_133 )
break;
V_141 = F_85 ( V_11 ) ;
V_133 |=
V_4 -> V_142 & V_141 ;
}
V_140:
F_89 ( & V_2 -> V_143 ) ;
if ( V_133 == F_84 ( V_18 -> V_127 , V_128 ) )
goto V_144;
if ( V_133 )
F_82 ( V_18 -> V_127 , V_128 ) ;
else
F_83 ( V_18 -> V_127 , V_128 ) ;
if ( V_2 -> V_107 -> V_145 ) {
V_2 -> V_146 = true ;
F_90 ( V_2 , & V_4 -> V_4 , V_133 ) ;
V_2 -> V_146 = false ;
}
V_144:
F_91 ( & V_2 -> V_143 ) ;
}
static bool F_92 ( struct V_3 * V_4 , struct V_147 * V_148 )
{
struct V_149 * V_150 ;
int V_151 ;
if ( ! V_148 )
return false ;
V_150 = F_93 ( V_148 ) ;
V_151 = ( V_4 -> V_152 *
V_4 -> V_16 -> V_21 . V_153 . V_154 *
32 / 15625 ) * V_155 ;
if ( V_151 < V_156 )
V_151 = V_156 ;
return F_94 ( V_74 , V_150 -> V_157 . V_74 + V_151 ) ;
}
static bool F_95 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_11 )
{
unsigned long V_49 ;
struct V_147 * V_148 ;
for (; ; ) {
F_96 ( & V_4 -> V_32 [ V_11 ] . V_63 , V_49 ) ;
V_148 = F_97 ( & V_4 -> V_32 [ V_11 ] ) ;
if ( F_92 ( V_4 , V_148 ) )
V_148 = F_98 ( & V_4 -> V_32 [ V_11 ] ) ;
else
V_148 = NULL ;
F_99 ( & V_4 -> V_32 [ V_11 ] . V_63 , V_49 ) ;
if ( ! V_148 )
break;
F_100 ( & V_2 -> V_31 , V_148 ) ;
}
for (; ; ) {
F_96 ( & V_4 -> V_30 [ V_11 ] . V_63 , V_49 ) ;
V_148 = F_97 ( & V_4 -> V_30 [ V_11 ] ) ;
if ( F_92 ( V_4 , V_148 ) )
V_148 = F_98 ( & V_4 -> V_30 [ V_11 ] ) ;
else
V_148 = NULL ;
F_99 ( & V_4 -> V_30 [ V_11 ] . V_63 , V_49 ) ;
if ( ! V_148 )
break;
V_2 -> V_29 -- ;
F_101 ( V_4 -> V_16 , L_5 ,
V_4 -> V_4 . V_7 ) ;
F_100 ( & V_2 -> V_31 , V_148 ) ;
}
F_12 ( V_4 ) ;
return ! ( F_88 ( & V_4 -> V_30 [ V_11 ] ) &&
F_88 ( & V_4 -> V_32 [ V_11 ] ) ) ;
}
static bool F_102 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_158 = false ;
int V_11 ;
if ( ! V_4 -> V_16 -> V_24 &&
! F_9 ( & V_4 -> V_16 -> V_21 ) )
return false ;
for ( V_11 = 0 ; V_11 < V_28 ; V_11 ++ )
V_158 |=
F_95 ( V_2 , V_4 , V_11 ) ;
return V_158 ;
}
static int T_5 F_103 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_15 * V_16 ;
int V_159 ;
F_79 () ;
if ( ! V_4 )
return - V_9 ;
V_2 = V_4 -> V_2 ;
V_16 = V_4 -> V_16 ;
F_30 ( & V_2 -> V_8 ) ;
F_68 ( V_4 , V_117 ) ;
F_104 ( V_4 , V_160 ) ;
V_159 = F_1 ( V_2 , V_4 ) ;
if ( F_58 ( V_159 ) )
return V_159 ;
F_76 ( & V_4 -> V_118 ) ;
F_105 ( V_2 , V_4 -> V_16 , V_4 ) ;
if ( V_16 -> V_21 . type == V_23 &&
F_6 ( V_16 -> V_25 . V_161 . V_4 ) == V_4 )
F_106 ( V_16 -> V_25 . V_161 . V_4 , NULL ) ;
return 0 ;
}
static void F_107 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_15 * V_16 = V_4 -> V_16 ;
int V_159 ;
F_79 () ;
F_30 ( & V_2 -> V_8 ) ;
F_108 ( V_2 , V_4 ) ;
V_4 -> V_45 = true ;
V_2 -> V_115 -- ;
V_2 -> V_116 ++ ;
while ( V_4 -> V_75 > V_76 ) {
V_159 = F_109 ( V_4 , V_4 -> V_75 - 1 ) ;
if ( V_159 ) {
F_87 ( 1 ) ;
break;
}
}
if ( V_4 -> V_109 ) {
V_159 = F_64 ( V_2 , V_16 , V_4 , V_76 ,
V_106 ) ;
F_87 ( V_159 != 0 ) ;
}
F_28 ( V_16 , L_6 , V_4 -> V_4 . V_7 ) ;
F_110 ( V_16 -> V_124 , V_4 -> V_4 . V_7 , V_125 ) ;
F_111 ( V_4 ) ;
F_112 ( V_4 ) ;
F_70 ( V_16 ) ;
F_19 ( V_4 ) ;
}
int T_5 F_113 ( struct V_3 * V_4 )
{
int V_105 = F_103 ( V_4 ) ;
if ( V_105 )
return V_105 ;
F_77 () ;
F_107 ( V_4 ) ;
return 0 ;
}
int F_114 ( struct V_15 * V_16 , const T_1 * V_7 )
{
struct V_3 * V_4 ;
int V_159 ;
F_80 ( & V_16 -> V_2 -> V_8 ) ;
V_4 = F_21 ( V_16 , V_7 ) ;
V_159 = F_113 ( V_4 ) ;
F_74 ( & V_16 -> V_2 -> V_8 ) ;
return V_159 ;
}
int F_115 ( struct V_15 * V_16 ,
const T_1 * V_7 )
{
struct V_3 * V_4 ;
int V_159 ;
F_80 ( & V_16 -> V_2 -> V_8 ) ;
V_4 = F_24 ( V_16 , V_7 ) ;
V_159 = F_113 ( V_4 ) ;
F_74 ( & V_16 -> V_2 -> V_8 ) ;
return V_159 ;
}
static void F_116 ( unsigned long V_162 )
{
struct V_1 * V_2 = (struct V_1 * ) V_162 ;
struct V_3 * V_4 ;
bool V_163 = false ;
F_43 () ;
F_26 (sta, &local->sta_list, list)
if ( F_102 ( V_2 , V_4 ) )
V_163 = true ;
F_45 () ;
if ( V_2 -> V_164 )
return;
if ( ! V_163 )
return;
F_117 ( & V_2 -> V_165 ,
F_118 ( V_74 + V_166 ) ) ;
}
void F_119 ( struct V_1 * V_2 )
{
F_47 ( & V_2 -> V_143 ) ;
F_49 ( & V_2 -> V_8 ) ;
F_120 ( & V_2 -> V_119 ) ;
F_121 ( & V_2 -> V_165 , F_116 ,
( unsigned long ) V_2 ) ;
}
void F_122 ( struct V_1 * V_2 )
{
F_123 ( & V_2 -> V_165 ) ;
}
int F_124 ( struct V_15 * V_16 , bool V_167 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 , * V_168 ;
F_125 ( V_169 ) ;
int V_159 = 0 ;
F_79 () ;
F_58 ( V_167 && V_16 -> V_21 . type != V_22 ) ;
F_58 ( V_167 && ! V_16 -> V_24 ) ;
F_80 ( & V_2 -> V_8 ) ;
F_126 (sta, tmp, &local->sta_list, list) {
if ( V_16 == V_4 -> V_16 ||
( V_167 && V_16 -> V_24 == V_4 -> V_16 -> V_24 ) ) {
if ( ! F_58 ( F_103 ( V_4 ) ) )
F_127 ( & V_4 -> V_169 , & V_169 ) ;
V_159 ++ ;
}
}
if ( ! F_128 ( & V_169 ) ) {
F_77 () ;
F_126 (sta, tmp, &free_list, free_list)
F_107 ( V_4 ) ;
}
F_74 ( & V_2 -> V_8 ) ;
return V_159 ;
}
void F_129 ( struct V_15 * V_16 ,
unsigned long V_170 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 , * V_168 ;
F_80 ( & V_2 -> V_8 ) ;
F_126 (sta, tmp, &local->sta_list, list) {
if ( V_16 != V_4 -> V_16 )
continue;
if ( F_94 ( V_74 , V_4 -> V_73 + V_170 ) ) {
F_28 ( V_4 -> V_16 , L_7 ,
V_4 -> V_4 . V_7 ) ;
if ( F_9 ( & V_16 -> V_21 ) &&
F_8 ( V_4 , V_19 ) )
F_11 ( & V_16 -> V_25 . V_26 . V_18 . V_27 ) ;
F_58 ( F_113 ( V_4 ) ) ;
}
}
F_74 ( & V_2 -> V_8 ) ;
}
struct V_171 * F_130 ( struct V_172 * V_31 ,
const T_1 * V_7 ,
const T_1 * V_173 )
{
struct V_3 * V_4 , * V_174 ;
F_131 (hw_to_local(hw), addr, sta, nxt) {
if ( V_173 &&
! F_23 ( V_4 -> V_16 -> V_21 . V_7 , V_173 ) )
continue;
if ( ! V_4 -> V_109 )
return NULL ;
return & V_4 -> V_4 ;
}
return NULL ;
}
struct V_171 * F_132 ( struct V_175 * V_21 ,
const T_1 * V_7 )
{
struct V_3 * V_4 ;
if ( ! V_21 )
return NULL ;
V_4 = F_24 ( F_133 ( V_21 ) , V_7 ) ;
if ( ! V_4 )
return NULL ;
if ( ! V_4 -> V_109 )
return NULL ;
return & V_4 -> V_4 ;
}
void F_34 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_176 V_37 ;
int V_177 = 0 , V_178 = 0 , V_11 ;
unsigned long V_49 ;
struct V_17 * V_18 ;
if ( V_16 -> V_21 . type == V_22 ||
V_16 -> V_21 . type == V_23 )
V_18 = & V_16 -> V_24 -> V_18 ;
else if ( F_9 ( & V_16 -> V_21 ) )
V_18 = & V_16 -> V_25 . V_26 . V_18 ;
else
return;
F_10 ( V_4 , V_179 ) ;
F_134 ( F_135 ( V_34 ) > 1 ) ;
V_4 -> V_142 = 0 ;
if ( ! ( V_2 -> V_31 . V_49 & V_139 ) )
F_136 ( V_2 , V_16 , V_180 , & V_4 -> V_4 ) ;
F_55 ( & V_37 ) ;
F_137 ( & V_4 -> V_64 ) ;
for ( V_11 = 0 ; V_11 < V_28 ; V_11 ++ ) {
int V_181 = F_13 ( & V_37 ) , V_168 ;
F_96 ( & V_4 -> V_32 [ V_11 ] . V_63 , V_49 ) ;
F_138 ( & V_4 -> V_32 [ V_11 ] , & V_37 ) ;
F_99 ( & V_4 -> V_32 [ V_11 ] . V_63 , V_49 ) ;
V_168 = F_13 ( & V_37 ) ;
V_177 += V_168 - V_181 ;
V_181 = V_168 ;
F_96 ( & V_4 -> V_30 [ V_11 ] . V_63 , V_49 ) ;
F_138 ( & V_4 -> V_30 [ V_11 ] , & V_37 ) ;
F_99 ( & V_4 -> V_30 [ V_11 ] . V_63 , V_49 ) ;
V_168 = F_13 ( & V_37 ) ;
V_178 += V_168 - V_181 ;
}
F_139 ( V_2 , & V_37 ) ;
F_10 ( V_4 , V_20 ) ;
F_10 ( V_4 , V_19 ) ;
F_140 ( & V_4 -> V_64 ) ;
F_11 ( & V_18 -> V_27 ) ;
if ( ! F_9 ( & V_16 -> V_21 ) &&
! F_141 ( V_4 -> V_96 ,
V_16 -> V_84 ) &&
V_4 -> V_96 != V_16 -> V_24 -> V_182 &&
F_142 ( V_4 ) != 1 ) {
F_143 ( V_16 ,
L_8 ,
V_4 -> V_4 . V_7 ) ;
F_144 ( V_16 , V_16 -> V_24 -> V_182 ,
V_4 -> V_4 . V_7 ,
V_16 -> V_21 . V_153 . V_183 ) ;
}
V_2 -> V_29 -= V_178 ;
F_12 ( V_4 ) ;
F_101 ( V_16 ,
L_9 ,
V_4 -> V_4 . V_7 , V_4 -> V_4 . V_136 , V_177 , V_178 ) ;
}
static void F_145 ( struct V_15 * V_16 ,
struct V_3 * V_4 , int V_184 ,
enum V_185 V_186 ,
bool V_187 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_188 * V_189 ;
struct V_147 * V_148 ;
int V_190 = sizeof( * V_189 ) ;
T_6 V_191 ;
bool V_192 = F_8 ( V_4 , V_193 ) ;
struct V_149 * V_150 ;
struct V_194 * V_195 ;
if ( V_192 ) {
V_191 = F_56 ( V_196 |
V_197 |
V_198 ) ;
} else {
V_190 -= 2 ;
V_191 = F_56 ( V_196 |
V_199 |
V_198 ) ;
}
V_148 = F_146 ( V_2 -> V_31 . V_200 + V_190 ) ;
if ( ! V_148 )
return;
F_147 ( V_148 , V_2 -> V_31 . V_200 ) ;
V_189 = ( void * ) F_148 ( V_148 , V_190 ) ;
V_189 -> V_201 = V_191 ;
V_189 -> V_202 = 0 ;
memcpy ( V_189 -> V_203 , V_4 -> V_4 . V_7 , V_72 ) ;
memcpy ( V_189 -> V_204 , V_16 -> V_21 . V_7 , V_72 ) ;
memcpy ( V_189 -> V_205 , V_16 -> V_21 . V_7 , V_72 ) ;
V_189 -> V_206 = 0 ;
V_148 -> V_207 = V_184 ;
F_149 ( V_148 , V_208 [ V_184 ] ) ;
if ( V_192 ) {
V_189 -> V_209 = F_56 ( V_184 ) ;
if ( V_186 == V_210 )
V_189 -> V_209 |=
F_56 ( V_211 ) ;
}
V_150 = F_93 ( V_148 ) ;
V_150 -> V_49 |= V_212 |
V_213 |
V_214 |
V_215 ;
if ( V_187 )
F_150 ( V_2 , V_4 , F_86 ( V_184 ) , 1 ,
V_186 , false ) ;
V_148 -> V_124 = V_16 -> V_124 ;
F_43 () ;
V_195 = F_44 ( V_16 -> V_21 . V_195 ) ;
if ( F_58 ( ! V_195 ) ) {
F_45 () ;
F_151 ( V_148 ) ;
return;
}
F_152 ( V_16 , V_148 , V_195 -> V_216 . V_217 -> V_218 ) ;
F_45 () ;
}
static int F_153 ( unsigned long V_141 )
{
if ( V_141 & 0xF8 )
return F_154 ( V_141 ) - 1 ;
if ( V_141 & F_86 ( 0 ) )
return 0 ;
return F_154 ( V_141 ) - 1 ;
}
static void
F_155 ( struct V_3 * V_4 ,
int V_219 , T_1 V_220 ,
enum V_185 V_186 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_2 ;
bool V_221 = false ;
int V_11 ;
unsigned long V_222 = 0 ;
struct V_176 V_223 ;
F_68 ( V_4 , V_179 ) ;
F_156 ( & V_223 ) ;
for ( V_11 = 0 ; V_11 < V_28 ; V_11 ++ ) {
unsigned long V_141 ;
if ( V_220 & F_86 ( V_11 ) )
continue;
V_141 = F_85 ( V_11 ) ;
if ( F_88 ( & V_223 ) )
V_222 |= V_4 -> V_142 & V_141 ;
if ( V_222 ) {
if ( V_186 == V_224 &&
F_157 ( V_222 ) > 1 ) {
V_221 = true ;
V_222 =
F_86 ( F_153 (
V_222 ) ) ;
break;
}
} else {
struct V_147 * V_148 ;
while ( V_219 > 0 ) {
V_148 = F_158 ( & V_4 -> V_32 [ V_11 ] ) ;
if ( ! V_148 ) {
V_148 = F_158 (
& V_4 -> V_30 [ V_11 ] ) ;
if ( V_148 )
V_2 -> V_29 -- ;
}
if ( ! V_148 )
break;
V_219 -- ;
F_159 ( & V_223 , V_148 ) ;
}
}
if ( ! F_88 ( & V_4 -> V_32 [ V_11 ] ) ||
! F_88 ( & V_4 -> V_30 [ V_11 ] ) ) {
V_221 = true ;
break;
}
}
if ( F_88 ( & V_223 ) && ! V_222 ) {
int V_184 ;
V_184 = 7 - ( ( F_160 ( ~ V_220 ) - 1 ) << 1 ) ;
F_145 ( V_16 , V_4 , V_184 , V_186 , true ) ;
} else if ( ! V_222 ) {
struct V_176 V_37 ;
struct V_147 * V_148 ;
int V_225 = 0 ;
T_4 V_141 = 0 ;
bool V_226 = false ;
F_55 ( & V_37 ) ;
while ( ( V_148 = F_98 ( & V_223 ) ) ) {
struct V_149 * V_150 = F_93 ( V_148 ) ;
struct V_227 * V_228 = ( void * ) V_148 -> V_162 ;
T_1 * V_229 = NULL ;
V_225 ++ ;
V_150 -> V_49 |= V_212 |
V_213 ;
if ( V_221 || ! F_88 ( & V_223 ) )
V_228 -> V_201 |=
F_56 ( V_230 ) ;
else
V_228 -> V_201 &=
F_56 ( ~ V_230 ) ;
if ( F_161 ( V_228 -> V_201 ) ||
F_162 ( V_228 -> V_201 ) )
V_229 = F_163 ( V_228 ) ;
V_141 |= F_86 ( V_148 -> V_207 ) ;
F_159 ( & V_37 , V_148 ) ;
if ( ! F_88 ( & V_223 ) )
continue;
if ( V_186 != V_210 ) {
V_150 -> V_49 |= V_214 |
V_215 ;
break;
}
if ( V_229 ) {
* V_229 |= V_211 ;
V_150 -> V_49 |= V_214 |
V_215 ;
} else {
V_228 -> V_201 |=
F_56 ( V_230 ) ;
V_226 = true ;
V_225 ++ ;
}
break;
}
F_150 ( V_2 , V_4 , V_141 , V_225 ,
V_186 , V_221 ) ;
F_139 ( V_2 , & V_37 ) ;
if ( V_226 )
F_145 (
V_16 , V_4 , F_153 ( V_141 ) ,
V_186 , false ) ;
F_12 ( V_4 ) ;
} else {
F_164 ( V_2 , V_4 , V_222 ,
V_219 , V_186 , V_221 ) ;
}
}
void F_37 ( struct V_3 * V_4 )
{
T_1 V_231 = V_4 -> V_4 . V_135 ;
if ( V_231 == F_86 ( V_28 ) - 1 )
V_231 = 0 ;
F_155 ( V_4 , 1 , V_231 ,
V_224 ) ;
}
void F_38 ( struct V_3 * V_4 )
{
int V_219 = V_4 -> V_4 . V_232 ;
T_1 V_233 = V_4 -> V_4 . V_135 ;
if ( ! V_233 )
return;
switch ( V_4 -> V_4 . V_232 ) {
case 1 :
V_219 = 2 ;
break;
case 2 :
V_219 = 4 ;
break;
case 3 :
V_219 = 6 ;
break;
case 0 :
V_219 = 8 ;
break;
}
F_155 ( V_4 , V_219 , ~ V_233 ,
V_210 ) ;
}
void F_165 ( struct V_172 * V_31 ,
struct V_171 * V_234 , bool V_235 )
{
struct V_3 * V_4 = F_32 ( V_234 , struct V_3 , V_4 ) ;
F_166 ( V_4 -> V_2 , V_234 , V_235 ) ;
if ( V_235 )
F_68 ( V_4 , V_20 ) ;
else if ( F_8 ( V_4 , V_20 ) )
F_167 ( V_31 , & V_4 -> V_33 ) ;
}
void F_168 ( struct V_171 * V_234 )
{
struct V_3 * V_4 = F_32 ( V_234 , struct V_3 , V_4 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_169 ( V_2 , V_234 ) ;
F_10 ( V_4 , V_179 ) ;
}
void F_170 ( struct V_171 * V_234 ,
T_1 V_184 , bool V_178 )
{
struct V_3 * V_4 = F_32 ( V_234 , struct V_3 , V_4 ) ;
if ( F_58 ( V_184 >= V_34 ) )
return;
F_171 ( V_4 -> V_2 , V_234 , V_184 , V_178 ) ;
if ( V_178 )
F_172 ( V_184 , & V_4 -> V_142 ) ;
else
F_173 ( V_184 , & V_4 -> V_142 ) ;
F_12 ( V_4 ) ;
}
int F_109 ( struct V_3 * V_4 ,
enum V_103 V_236 )
{
F_79 () ;
if ( V_4 -> V_75 == V_236 )
return 0 ;
switch ( V_236 ) {
case V_76 :
if ( V_4 -> V_75 != V_237 )
return - V_102 ;
break;
case V_237 :
if ( V_4 -> V_75 != V_76 &&
V_4 -> V_75 != V_238 )
return - V_102 ;
break;
case V_238 :
if ( V_4 -> V_75 != V_237 &&
V_4 -> V_75 != V_239 )
return - V_102 ;
break;
case V_239 :
if ( V_4 -> V_75 != V_238 )
return - V_102 ;
break;
default:
F_174 ( 1 , L_10 , V_236 ) ;
return - V_102 ;
}
F_28 ( V_4 -> V_16 , L_11 ,
V_4 -> V_4 . V_7 , V_236 ) ;
if ( F_8 ( V_4 , V_121 ) ) {
int V_105 = F_64 ( V_4 -> V_2 , V_4 -> V_16 , V_4 ,
V_4 -> V_75 , V_236 ) ;
if ( V_105 )
return V_105 ;
}
switch ( V_236 ) {
case V_76 :
if ( V_4 -> V_75 == V_237 )
F_173 ( V_240 , & V_4 -> V_241 ) ;
break;
case V_237 :
if ( V_4 -> V_75 == V_76 )
F_172 ( V_240 , & V_4 -> V_241 ) ;
else if ( V_4 -> V_75 == V_238 )
F_173 ( V_242 , & V_4 -> V_241 ) ;
break;
case V_238 :
if ( V_4 -> V_75 == V_237 ) {
F_172 ( V_242 , & V_4 -> V_241 ) ;
} else if ( V_4 -> V_75 == V_239 ) {
if ( V_4 -> V_16 -> V_21 . type == V_22 ||
( V_4 -> V_16 -> V_21 . type == V_23 &&
! V_4 -> V_16 -> V_25 . V_161 . V_4 ) )
F_11 ( & V_4 -> V_16 -> V_24 -> V_243 ) ;
F_173 ( V_244 , & V_4 -> V_241 ) ;
}
break;
case V_239 :
if ( V_4 -> V_75 == V_238 ) {
if ( V_4 -> V_16 -> V_21 . type == V_22 ||
( V_4 -> V_16 -> V_21 . type == V_23 &&
! V_4 -> V_16 -> V_25 . V_161 . V_4 ) )
F_175 ( & V_4 -> V_16 -> V_24 -> V_243 ) ;
F_172 ( V_244 , & V_4 -> V_241 ) ;
}
break;
default:
break;
}
V_4 -> V_75 = V_236 ;
return 0 ;
}
T_1 F_142 ( struct V_3 * V_4 )
{
struct V_245 * V_91 = & V_4 -> V_4 . V_91 ;
T_1 V_246 ;
if ( ! V_4 -> V_4 . V_91 . V_247 )
return 1 ;
if ( V_4 -> V_4 . V_248 . V_249 ) {
int V_12 ;
T_4 V_250 =
F_176 ( V_4 -> V_4 . V_248 . V_251 . V_250 ) ;
for ( V_12 = 7 ; V_12 >= 0 ; V_12 -- )
if ( ( V_250 & ( 0x3 << ( V_12 * 2 ) ) ) !=
V_252 )
return V_12 + 1 ;
}
if ( V_91 -> V_253 . V_254 [ 3 ] )
V_246 = 4 ;
else if ( V_91 -> V_253 . V_254 [ 2 ] )
V_246 = 3 ;
else if ( V_91 -> V_253 . V_254 [ 1 ] )
V_246 = 2 ;
else
V_246 = 1 ;
if ( ! ( V_91 -> V_253 . V_255 & V_256 ) )
return V_246 ;
return ( ( V_91 -> V_253 . V_255 & V_257 )
>> V_258 ) + 1 ;
}
