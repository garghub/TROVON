static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return F_2 ( & V_2 -> V_5 , & V_4 -> V_6 ,
V_7 ) ;
}
static void F_3 ( struct V_3 * V_4 )
{
int V_8 , V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_14 * V_15 ;
if ( F_4 ( V_4 , V_16 ) ||
F_4 ( V_4 , V_17 ) ||
F_4 ( V_4 , V_18 ) ) {
if ( V_4 -> V_13 -> V_19 . type == V_20 ||
V_4 -> V_13 -> V_19 . type == V_21 )
V_15 = & V_13 -> V_22 -> V_15 ;
else if ( F_5 ( & V_13 -> V_19 ) )
V_15 = & V_13 -> V_23 . V_24 . V_15 ;
else
return;
F_6 ( V_4 , V_16 ) ;
F_6 ( V_4 , V_17 ) ;
F_6 ( V_4 , V_18 ) ;
F_7 ( & V_15 -> V_25 ) ;
}
if ( V_4 -> V_4 . V_26 [ 0 ] ) {
for ( V_9 = 0 ; V_9 < F_8 ( V_4 -> V_4 . V_26 ) ; V_9 ++ ) {
struct V_27 * V_28 = F_9 ( V_4 -> V_4 . V_26 [ V_9 ] ) ;
int V_29 = F_10 ( & V_28 -> V_30 ) ;
F_11 ( & V_2 -> V_31 , & V_28 -> V_30 ) ;
F_12 ( V_29 , & V_13 -> V_32 [ V_28 -> V_26 . V_8 ] ) ;
}
}
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ ) {
V_2 -> V_34 -= F_10 ( & V_4 -> V_35 [ V_8 ] ) ;
F_11 ( & V_2 -> V_31 , & V_4 -> V_35 [ V_8 ] ) ;
F_11 ( & V_2 -> V_31 , & V_4 -> V_36 [ V_8 ] ) ;
}
if ( F_5 ( & V_13 -> V_19 ) )
F_13 ( V_4 ) ;
F_14 ( & V_4 -> V_37 ) ;
for ( V_9 = 0 ; V_9 < V_38 ; V_9 ++ ) {
F_15 ( V_4 -> V_39 . V_40 [ V_9 ] ) ;
V_11 = F_16 ( V_4 -> V_39 . V_11 [ V_9 ] ) ;
if ( ! V_11 )
continue;
F_11 ( & V_2 -> V_31 , & V_11 -> V_41 ) ;
F_15 ( V_11 ) ;
}
}
static void F_17 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
F_3 ( V_4 ) ;
F_18 ( V_2 , V_4 ) ;
}
struct V_3 * F_19 ( struct V_12 * V_13 ,
const T_1 * V_42 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 ;
struct V_43 * V_44 ;
const struct V_45 * V_46 ;
F_20 () ;
V_46 = F_21 ( V_2 -> V_5 . V_46 , & V_2 -> V_5 ) ;
F_22 (local, tbl, addr, sta, tmp) {
if ( V_4 -> V_13 == V_13 ) {
F_23 () ;
return V_4 ;
}
}
F_23 () ;
return NULL ;
}
struct V_3 * F_24 ( struct V_12 * V_13 ,
const T_1 * V_42 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 ;
struct V_43 * V_44 ;
const struct V_45 * V_46 ;
F_20 () ;
V_46 = F_21 ( V_2 -> V_5 . V_46 , & V_2 -> V_5 ) ;
F_22 (local, tbl, addr, sta, tmp) {
if ( V_4 -> V_13 == V_13 ||
( V_4 -> V_13 -> V_22 && V_4 -> V_13 -> V_22 == V_13 -> V_22 ) ) {
F_23 () ;
return V_4 ;
}
}
F_23 () ;
return NULL ;
}
struct V_3 * F_25 ( struct V_12 * V_13 ,
int V_47 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 ;
int V_9 = 0 ;
F_26 (sta, &local->sta_list, list) {
if ( V_13 != V_4 -> V_13 )
continue;
if ( V_9 < V_47 ) {
++ V_9 ;
continue;
}
return V_4 ;
}
return NULL ;
}
void F_18 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_48 )
F_27 ( V_4 ) ;
F_28 ( V_4 -> V_13 , L_1 , V_4 -> V_4 . V_42 ) ;
if ( V_4 -> V_4 . V_26 [ 0 ] )
F_15 ( F_9 ( V_4 -> V_4 . V_26 [ 0 ] ) ) ;
F_15 ( F_16 ( V_4 -> V_4 . V_49 ) ) ;
#ifdef F_29
F_15 ( V_4 -> V_24 ) ;
#endif
F_15 ( V_4 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_31 ( & V_2 -> V_5 , & V_4 -> V_6 ,
V_7 ) ;
}
static void F_32 ( struct V_50 * V_51 )
{
struct V_3 * V_4 ;
V_4 = F_33 ( V_51 , struct V_3 , V_37 ) ;
if ( V_4 -> V_52 )
return;
F_34 () ;
if ( ! F_4 ( V_4 , V_16 ) )
F_35 ( V_4 ) ;
else if ( F_36 ( V_4 , V_53 ) )
F_37 ( V_4 ) ;
else if ( F_36 ( V_4 , V_54 ) )
F_38 ( V_4 ) ;
F_39 () ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 V_55 )
{
if ( F_41 ( & V_2 -> V_31 , V_56 ) )
return 0 ;
V_4 -> V_48 = V_2 -> V_48 ;
V_4 -> V_57 = F_42 ( V_4 -> V_48 ,
V_4 , V_55 ) ;
if ( ! V_4 -> V_57 )
return - V_58 ;
return 0 ;
}
struct V_3 * F_43 ( struct V_12 * V_13 ,
const T_1 * V_42 , T_2 V_55 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_59 * V_31 = & V_2 -> V_31 ;
struct V_3 * V_4 ;
int V_9 ;
V_4 = F_44 ( sizeof( * V_4 ) + V_31 -> V_60 , V_55 ) ;
if ( ! V_4 )
return NULL ;
F_45 ( & V_4 -> V_61 ) ;
F_45 ( & V_4 -> V_62 ) ;
F_46 ( & V_4 -> V_37 , F_32 ) ;
F_46 ( & V_4 -> V_39 . V_63 , V_64 ) ;
F_47 ( & V_4 -> V_39 . V_65 ) ;
#ifdef F_29
if ( F_5 ( & V_13 -> V_19 ) ) {
V_4 -> V_24 = F_44 ( sizeof( * V_4 -> V_24 ) , V_55 ) ;
if ( ! V_4 -> V_24 )
goto free;
F_45 ( & V_4 -> V_24 -> V_66 ) ;
if ( F_5 ( & V_13 -> V_19 ) &&
! V_13 -> V_23 . V_24 . V_67 )
F_48 ( & V_4 -> V_24 -> V_68 ) ;
V_4 -> V_24 -> V_69 = V_70 ;
}
#endif
memcpy ( V_4 -> V_42 , V_42 , V_71 ) ;
memcpy ( V_4 -> V_4 . V_42 , V_42 , V_71 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_13 = V_13 ;
V_4 -> V_72 . V_73 = V_74 ;
V_4 -> V_75 = V_76 ;
V_4 -> V_77 = V_78 ;
V_4 -> V_79 = F_49 () ;
F_50 ( & V_4 -> V_72 . V_80 ) ;
for ( V_9 = 0 ; V_9 < F_8 ( V_4 -> V_72 . V_81 ) ; V_9 ++ )
F_50 ( & V_4 -> V_72 . V_81 [ V_9 ] ) ;
if ( V_2 -> V_82 -> V_83 ) {
void * V_84 ;
int V_85 = sizeof( struct V_27 ) +
F_51 ( V_31 -> V_86 , sizeof( void * ) ) ;
V_84 = F_52 ( F_8 ( V_4 -> V_4 . V_26 ) , V_85 , V_55 ) ;
if ( ! V_84 )
goto free;
for ( V_9 = 0 ; V_9 < F_8 ( V_4 -> V_4 . V_26 ) ; V_9 ++ ) {
struct V_27 * V_26 = V_84 + V_9 * V_85 ;
F_53 ( V_13 , V_4 , V_26 , V_9 ) ;
}
}
if ( F_40 ( V_2 , V_4 , V_55 ) )
goto V_87;
for ( V_9 = 0 ; V_9 < V_38 ; V_9 ++ ) {
V_4 -> V_88 [ V_9 ] = V_9 ;
}
for ( V_9 = 0 ; V_9 < V_33 ; V_9 ++ ) {
F_54 ( & V_4 -> V_35 [ V_9 ] ) ;
F_54 ( & V_4 -> V_36 [ V_9 ] ) ;
}
for ( V_9 = 0 ; V_9 < V_38 ; V_9 ++ )
V_4 -> V_89 [ V_9 ] = F_55 ( V_90 ) ;
V_4 -> V_4 . V_91 = V_92 ;
if ( V_13 -> V_19 . type == V_20 ||
V_13 -> V_19 . type == V_21 ) {
struct V_93 * V_94 =
V_31 -> V_95 -> V_96 [ F_56 ( V_13 ) ] ;
T_1 V_97 = ( V_94 -> V_98 . V_99 & V_100 ) >>
V_101 ;
switch ( V_97 ) {
case V_102 :
V_4 -> V_103 = V_92 ;
break;
case V_104 :
V_4 -> V_103 = V_105 ;
break;
case V_106 :
V_4 -> V_103 = V_107 ;
break;
default:
F_57 ( 1 ) ;
}
}
F_28 ( V_13 , L_2 , V_4 -> V_4 . V_42 ) ;
return V_4 ;
V_87:
if ( V_4 -> V_4 . V_26 [ 0 ] )
F_15 ( F_9 ( V_4 -> V_4 . V_26 [ 0 ] ) ) ;
free:
#ifdef F_29
F_15 ( V_4 -> V_24 ) ;
#endif
F_15 ( V_4 ) ;
return NULL ;
}
static int F_58 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
if ( F_59 ( ! F_60 ( V_13 ) ) )
return - V_108 ;
if ( F_57 ( F_61 ( V_4 -> V_4 . V_42 , V_13 -> V_19 . V_42 ) ||
F_62 ( V_4 -> V_4 . V_42 ) ) )
return - V_109 ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_3 * V_4 )
{
enum V_110 V_111 ;
int V_112 = 0 ;
for ( V_111 = V_113 ; V_111 < V_4 -> V_75 ; V_111 ++ ) {
V_112 = F_64 ( V_2 , V_13 , V_4 , V_111 , V_111 + 1 ) ;
if ( V_112 )
break;
}
if ( ! V_112 ) {
if ( ! V_2 -> V_82 -> V_114 )
V_4 -> V_115 = true ;
return 0 ;
}
if ( V_13 -> V_19 . type == V_116 ) {
F_65 ( V_13 ,
L_3 ,
V_4 -> V_4 . V_42 , V_111 + 1 , V_112 ) ;
V_112 = 0 ;
}
for (; V_111 > V_113 ; V_111 -- )
F_57 ( F_64 ( V_2 , V_13 , V_4 , V_111 , V_111 - 1 ) ) ;
return V_112 ;
}
static int F_66 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_117 V_118 ;
int V_112 = 0 ;
F_67 ( & V_2 -> V_119 ) ;
if ( F_24 ( V_13 , V_4 -> V_4 . V_42 ) ) {
V_112 = - V_120 ;
goto V_121;
}
V_2 -> V_122 ++ ;
V_2 -> V_123 ++ ;
F_68 () ;
F_69 ( V_4 , V_124 ) ;
F_30 ( V_2 , V_4 ) ;
F_70 ( & V_4 -> V_125 , & V_2 -> V_126 ) ;
V_112 = F_63 ( V_2 , V_13 , V_4 ) ;
if ( V_112 )
goto V_127;
F_69 ( V_4 , V_128 ) ;
F_6 ( V_4 , V_124 ) ;
F_71 ( V_13 ) ;
F_72 ( V_4 ) ;
F_73 ( V_4 ) ;
memset ( & V_118 , 0 , sizeof( V_118 ) ) ;
V_118 . V_129 = 0 ;
V_118 . V_130 = V_2 -> V_123 ;
F_74 ( V_13 -> V_131 , V_4 -> V_4 . V_42 , & V_118 , V_132 ) ;
F_28 ( V_13 , L_4 , V_4 -> V_4 . V_42 ) ;
F_20 () ;
F_75 ( & V_2 -> V_119 ) ;
if ( F_5 ( & V_13 -> V_19 ) )
F_76 ( V_13 ) ;
return 0 ;
V_127:
F_1 ( V_2 , V_4 ) ;
F_77 ( & V_4 -> V_125 ) ;
V_2 -> V_122 -- ;
F_78 () ;
F_3 ( V_4 ) ;
V_121:
F_75 ( & V_2 -> V_119 ) ;
F_20 () ;
return V_112 ;
}
int F_79 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_112 ;
F_80 () ;
V_112 = F_58 ( V_4 ) ;
if ( V_112 ) {
F_20 () ;
goto V_133;
}
F_81 ( & V_2 -> V_119 ) ;
V_112 = F_66 ( V_4 ) ;
if ( V_112 )
goto V_133;
return 0 ;
V_133:
F_18 ( V_2 , V_4 ) ;
return V_112 ;
}
int F_82 ( struct V_3 * V_4 )
{
int V_112 = F_79 ( V_4 ) ;
F_23 () ;
return V_112 ;
}
static inline void F_83 ( T_1 * V_134 , T_4 V_135 )
{
V_134 [ V_135 / 8 ] |= ( 1 << ( V_135 % 8 ) ) ;
}
static inline void F_84 ( T_1 * V_134 , T_4 V_135 )
{
V_134 [ V_135 / 8 ] &= ~ ( 1 << ( V_135 % 8 ) ) ;
}
static inline bool F_85 ( T_1 * V_134 , T_4 V_135 )
{
return V_134 [ V_135 / 8 ] & ( 1 << ( V_135 % 8 ) ) ;
}
static unsigned long F_86 ( int V_8 )
{
switch ( V_8 ) {
case V_136 :
return F_87 ( 6 ) | F_87 ( 7 ) ;
case V_137 :
return F_87 ( 4 ) | F_87 ( 5 ) ;
case V_138 :
return F_87 ( 0 ) | F_87 ( 3 ) ;
case V_139 :
return F_87 ( 1 ) | F_87 ( 2 ) ;
default:
F_57 ( 1 ) ;
return 0 ;
}
}
static void F_88 ( struct V_3 * V_4 , bool V_140 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_14 * V_15 ;
bool V_141 = false ;
T_1 V_142 = V_4 -> V_4 . V_143 ;
int V_8 ;
T_4 V_135 = V_4 -> V_4 . V_144 ;
if ( V_4 -> V_13 -> V_19 . type == V_20 ||
V_4 -> V_13 -> V_19 . type == V_21 ) {
if ( F_89 ( ! V_4 -> V_13 -> V_22 ) )
return;
V_15 = & V_4 -> V_13 -> V_22 -> V_15 ;
#ifdef F_29
} else if ( F_5 ( & V_4 -> V_13 -> V_19 ) ) {
V_15 = & V_4 -> V_13 -> V_23 . V_24 . V_15 ;
#endif
} else {
return;
}
if ( F_41 ( & V_2 -> V_31 , V_145 ) )
return;
if ( V_4 -> V_52 )
goto V_146;
if ( V_142 == F_87 ( V_33 ) - 1 )
V_142 = 0 ;
if ( V_140 )
V_142 = F_87 ( V_33 ) - 1 ;
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ ) {
unsigned long V_147 ;
if ( V_142 & F_87 ( V_8 ) )
continue;
V_141 |= ! F_90 ( & V_4 -> V_36 [ V_8 ] ) ||
! F_90 ( & V_4 -> V_35 [ V_8 ] ) ;
if ( V_141 )
break;
V_147 = F_86 ( V_8 ) ;
V_141 |=
V_4 -> V_148 & V_147 ;
V_141 |=
V_4 -> V_149 & V_147 ;
}
V_146:
F_91 ( & V_2 -> V_150 ) ;
if ( V_141 == F_85 ( V_15 -> V_134 , V_135 ) )
goto V_151;
if ( V_141 )
F_83 ( V_15 -> V_134 , V_135 ) ;
else
F_84 ( V_15 -> V_134 , V_135 ) ;
if ( V_2 -> V_82 -> V_152 && ! F_57 ( V_4 -> V_52 ) ) {
V_2 -> V_153 = true ;
F_92 ( V_2 , & V_4 -> V_4 , V_141 ) ;
V_2 -> V_153 = false ;
}
V_151:
F_93 ( & V_2 -> V_150 ) ;
}
void F_94 ( struct V_3 * V_4 )
{
F_88 ( V_4 , false ) ;
}
static bool F_95 ( struct V_3 * V_4 , struct V_154 * V_155 )
{
struct V_156 * V_157 ;
int V_158 ;
if ( ! V_155 )
return false ;
V_157 = F_96 ( V_155 ) ;
V_158 = ( V_4 -> V_159 *
V_4 -> V_13 -> V_19 . V_160 . V_161 *
32 / 15625 ) * V_162 ;
if ( V_158 < V_163 )
V_158 = V_163 ;
return F_97 ( V_74 , V_157 -> V_164 . V_74 + V_158 ) ;
}
static bool F_98 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_8 )
{
unsigned long V_165 ;
struct V_154 * V_155 ;
for (; ; ) {
F_99 ( & V_4 -> V_36 [ V_8 ] . V_61 , V_165 ) ;
V_155 = F_100 ( & V_4 -> V_36 [ V_8 ] ) ;
if ( F_95 ( V_4 , V_155 ) )
V_155 = F_101 ( & V_4 -> V_36 [ V_8 ] ) ;
else
V_155 = NULL ;
F_102 ( & V_4 -> V_36 [ V_8 ] . V_61 , V_165 ) ;
if ( ! V_155 )
break;
F_103 ( & V_2 -> V_31 , V_155 ) ;
}
for (; ; ) {
F_99 ( & V_4 -> V_35 [ V_8 ] . V_61 , V_165 ) ;
V_155 = F_100 ( & V_4 -> V_35 [ V_8 ] ) ;
if ( F_95 ( V_4 , V_155 ) )
V_155 = F_101 ( & V_4 -> V_35 [ V_8 ] ) ;
else
V_155 = NULL ;
F_102 ( & V_4 -> V_35 [ V_8 ] . V_61 , V_165 ) ;
if ( ! V_155 )
break;
V_2 -> V_34 -- ;
F_104 ( V_4 -> V_13 , L_5 ,
V_4 -> V_4 . V_42 ) ;
F_103 ( & V_2 -> V_31 , V_155 ) ;
}
F_94 ( V_4 ) ;
return ! ( F_90 ( & V_4 -> V_35 [ V_8 ] ) &&
F_90 ( & V_4 -> V_36 [ V_8 ] ) ) ;
}
static bool F_105 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_166 = false ;
int V_8 ;
if ( ! V_4 -> V_13 -> V_22 &&
! F_5 ( & V_4 -> V_13 -> V_19 ) )
return false ;
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ )
V_166 |=
F_98 ( V_2 , V_4 , V_8 ) ;
return V_166 ;
}
static int T_5 F_106 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
int V_167 ;
F_80 () ;
if ( ! V_4 )
return - V_168 ;
V_2 = V_4 -> V_2 ;
V_13 = V_4 -> V_13 ;
F_67 ( & V_2 -> V_119 ) ;
F_69 ( V_4 , V_124 ) ;
F_107 ( V_4 , V_169 ) ;
V_167 = F_1 ( V_2 , V_4 ) ;
if ( F_57 ( V_167 ) )
return V_167 ;
if ( F_4 ( V_4 , V_170 ) ) {
F_108 ( V_2 , V_13 , & V_4 -> V_4 ) ;
F_6 ( V_4 , V_170 ) ;
}
F_77 ( & V_4 -> V_125 ) ;
F_109 ( V_2 , V_4 -> V_13 , V_4 ) ;
if ( V_13 -> V_19 . type == V_21 &&
F_110 ( V_13 -> V_23 . V_171 . V_4 ) == V_4 )
F_111 ( V_13 -> V_23 . V_171 . V_4 , NULL ) ;
return 0 ;
}
static void F_112 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_117 V_118 = {} ;
int V_167 ;
F_80 () ;
F_67 ( & V_2 -> V_119 ) ;
F_113 ( V_2 , V_4 ) ;
F_88 ( V_4 , true ) ;
V_4 -> V_52 = true ;
V_2 -> V_122 -- ;
V_2 -> V_123 ++ ;
while ( V_4 -> V_75 > V_76 ) {
V_167 = F_114 ( V_4 , V_4 -> V_75 - 1 ) ;
if ( V_167 ) {
F_89 ( 1 ) ;
break;
}
}
if ( V_4 -> V_115 ) {
V_167 = F_64 ( V_2 , V_13 , V_4 , V_76 ,
V_113 ) ;
F_89 ( V_167 != 0 ) ;
}
F_28 ( V_13 , L_6 , V_4 -> V_4 . V_42 ) ;
F_115 ( V_4 , & V_118 ) ;
F_116 ( V_13 -> V_131 , V_4 -> V_4 . V_42 , & V_118 , V_132 ) ;
F_117 ( V_4 ) ;
F_118 ( V_4 ) ;
F_71 ( V_13 ) ;
F_17 ( V_4 ) ;
}
int T_5 F_119 ( struct V_3 * V_4 )
{
int V_112 = F_106 ( V_4 ) ;
if ( V_112 )
return V_112 ;
F_78 () ;
F_112 ( V_4 ) ;
return 0 ;
}
int F_120 ( struct V_12 * V_13 , const T_1 * V_42 )
{
struct V_3 * V_4 ;
int V_167 ;
F_81 ( & V_13 -> V_2 -> V_119 ) ;
V_4 = F_19 ( V_13 , V_42 ) ;
V_167 = F_119 ( V_4 ) ;
F_75 ( & V_13 -> V_2 -> V_119 ) ;
return V_167 ;
}
int F_121 ( struct V_12 * V_13 ,
const T_1 * V_42 )
{
struct V_3 * V_4 ;
int V_167 ;
F_81 ( & V_13 -> V_2 -> V_119 ) ;
V_4 = F_24 ( V_13 , V_42 ) ;
V_167 = F_119 ( V_4 ) ;
F_75 ( & V_13 -> V_2 -> V_119 ) ;
return V_167 ;
}
static void F_122 ( unsigned long V_172 )
{
struct V_1 * V_2 = (struct V_1 * ) V_172 ;
struct V_3 * V_4 ;
bool V_173 = false ;
F_20 () ;
F_26 (sta, &local->sta_list, list)
if ( F_105 ( V_2 , V_4 ) )
V_173 = true ;
F_23 () ;
if ( V_2 -> V_174 )
return;
if ( ! V_173 )
return;
F_123 ( & V_2 -> V_175 ,
F_124 ( V_74 + V_176 ) ) ;
}
T_6 F_125 ( const void * V_177 , T_6 V_178 , T_6 V_179 )
{
return F_126 ( V_177 , V_71 , V_179 ) ;
}
int F_127 ( struct V_1 * V_2 )
{
int V_112 ;
V_112 = F_128 ( & V_2 -> V_5 , & V_7 ) ;
if ( V_112 )
return V_112 ;
F_45 ( & V_2 -> V_150 ) ;
F_47 ( & V_2 -> V_119 ) ;
F_129 ( & V_2 -> V_126 ) ;
F_130 ( & V_2 -> V_175 , F_122 ,
( unsigned long ) V_2 ) ;
return 0 ;
}
void F_131 ( struct V_1 * V_2 )
{
F_132 ( & V_2 -> V_175 ) ;
F_133 ( & V_2 -> V_5 ) ;
}
int F_134 ( struct V_12 * V_13 , bool V_180 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 , * V_44 ;
F_135 ( V_181 ) ;
int V_167 = 0 ;
F_80 () ;
F_57 ( V_180 && V_13 -> V_19 . type != V_20 ) ;
F_57 ( V_180 && ! V_13 -> V_22 ) ;
F_81 ( & V_2 -> V_119 ) ;
F_136 (sta, tmp, &local->sta_list, list) {
if ( V_13 == V_4 -> V_13 ||
( V_180 && V_13 -> V_22 == V_4 -> V_13 -> V_22 ) ) {
if ( ! F_57 ( F_106 ( V_4 ) ) )
F_137 ( & V_4 -> V_181 , & V_181 ) ;
V_167 ++ ;
}
}
if ( ! F_138 ( & V_181 ) ) {
F_78 () ;
F_136 (sta, tmp, &free_list, free_list)
F_112 ( V_4 ) ;
}
F_75 ( & V_2 -> V_119 ) ;
return V_167 ;
}
void F_139 ( struct V_12 * V_13 ,
unsigned long V_182 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 , * V_44 ;
F_81 ( & V_2 -> V_119 ) ;
F_136 (sta, tmp, &local->sta_list, list) {
if ( V_13 != V_4 -> V_13 )
continue;
if ( F_97 ( V_74 , V_4 -> V_72 . V_73 + V_182 ) ) {
F_28 ( V_4 -> V_13 , L_7 ,
V_4 -> V_4 . V_42 ) ;
if ( F_5 ( & V_13 -> V_19 ) &&
F_4 ( V_4 , V_16 ) )
F_7 ( & V_13 -> V_23 . V_24 . V_15 . V_25 ) ;
F_57 ( F_119 ( V_4 ) ) ;
}
}
F_75 ( & V_2 -> V_119 ) ;
}
struct V_183 * F_140 ( struct V_59 * V_31 ,
const T_1 * V_42 ,
const T_1 * V_184 )
{
struct V_1 * V_2 = F_141 ( V_31 ) ;
struct V_3 * V_4 ;
struct V_43 * V_44 ;
const struct V_45 * V_46 ;
V_46 = F_21 ( V_2 -> V_5 . V_46 , & V_2 -> V_5 ) ;
F_22 (local, tbl, addr, sta, tmp) {
if ( V_184 &&
! F_61 ( V_4 -> V_13 -> V_19 . V_42 , V_184 ) )
continue;
if ( ! V_4 -> V_115 )
return NULL ;
return & V_4 -> V_4 ;
}
return NULL ;
}
struct V_183 * F_142 ( struct V_185 * V_19 ,
const T_1 * V_42 )
{
struct V_3 * V_4 ;
if ( ! V_19 )
return NULL ;
V_4 = F_24 ( F_143 ( V_19 ) , V_42 ) ;
if ( ! V_4 )
return NULL ;
if ( ! V_4 -> V_115 )
return NULL ;
return & V_4 -> V_4 ;
}
void F_35 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_186 V_41 ;
int V_187 = 0 , V_188 = 0 , V_8 , V_9 ;
unsigned long V_165 ;
struct V_14 * V_15 ;
if ( V_13 -> V_19 . type == V_21 )
V_13 = F_33 ( V_13 -> V_22 , struct V_12 ,
V_23 . V_189 ) ;
if ( V_13 -> V_19 . type == V_20 )
V_15 = & V_13 -> V_22 -> V_15 ;
else if ( F_5 ( & V_13 -> V_19 ) )
V_15 = & V_13 -> V_23 . V_24 . V_15 ;
else
return;
F_6 ( V_4 , V_190 ) ;
F_144 ( F_145 ( V_38 ) > 1 ) ;
V_4 -> V_148 = 0 ;
V_4 -> V_149 = 0 ;
if ( ! F_41 ( & V_2 -> V_31 , V_145 ) )
F_146 ( V_2 , V_13 , V_191 , & V_4 -> V_4 ) ;
if ( V_4 -> V_4 . V_26 [ 0 ] ) {
for ( V_9 = 0 ; V_9 < F_8 ( V_4 -> V_4 . V_26 ) ; V_9 ++ ) {
struct V_27 * V_28 = F_9 ( V_4 -> V_4 . V_26 [ V_9 ] ) ;
if ( ! F_10 ( & V_28 -> V_30 ) )
continue;
F_147 ( V_2 , V_28 ) ;
}
}
F_54 ( & V_41 ) ;
F_148 ( & V_4 -> V_62 ) ;
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ ) {
int V_192 = F_10 ( & V_41 ) , V_44 ;
F_99 ( & V_4 -> V_36 [ V_8 ] . V_61 , V_165 ) ;
F_149 ( & V_4 -> V_36 [ V_8 ] , & V_41 ) ;
F_102 ( & V_4 -> V_36 [ V_8 ] . V_61 , V_165 ) ;
V_44 = F_10 ( & V_41 ) ;
V_187 += V_44 - V_192 ;
V_192 = V_44 ;
F_99 ( & V_4 -> V_35 [ V_8 ] . V_61 , V_165 ) ;
F_149 ( & V_4 -> V_35 [ V_8 ] , & V_41 ) ;
F_102 ( & V_4 -> V_35 [ V_8 ] . V_61 , V_165 ) ;
V_44 = F_10 ( & V_41 ) ;
V_188 += V_44 - V_192 ;
}
F_150 ( V_2 , & V_41 ) ;
F_6 ( V_4 , V_18 ) ;
F_6 ( V_4 , V_53 ) ;
F_6 ( V_4 , V_54 ) ;
F_151 ( & V_4 -> V_62 ) ;
F_7 ( & V_15 -> V_25 ) ;
if ( ! F_5 ( & V_13 -> V_19 ) &&
! F_152 ( V_4 -> V_103 ,
V_13 -> V_91 ) &&
V_4 -> V_103 != V_13 -> V_22 -> V_193 &&
F_153 ( V_4 ) != 1 ) {
F_154 ( V_13 ,
L_8 ,
V_4 -> V_4 . V_42 ) ;
F_155 ( V_13 , V_13 -> V_22 -> V_193 ,
V_4 -> V_4 . V_42 ,
V_13 -> V_19 . V_160 . V_194 ) ;
}
V_2 -> V_34 -= V_188 ;
F_94 ( V_4 ) ;
F_104 ( V_13 ,
L_9 ,
V_4 -> V_4 . V_42 , V_4 -> V_4 . V_144 , V_187 , V_188 ) ;
F_156 ( V_4 ) ;
}
static void F_157 ( struct V_12 * V_13 ,
struct V_3 * V_4 , int V_195 ,
enum V_196 V_197 ,
bool V_198 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_199 * V_200 ;
struct V_154 * V_155 ;
int V_85 = sizeof( * V_200 ) ;
T_7 V_201 ;
bool V_202 = V_4 -> V_4 . V_203 ;
struct V_156 * V_157 ;
struct V_204 * V_205 ;
if ( V_202 ) {
V_201 = F_55 ( V_206 |
V_207 |
V_208 ) ;
} else {
V_85 -= 2 ;
V_201 = F_55 ( V_206 |
V_209 |
V_208 ) ;
}
V_155 = F_158 ( V_2 -> V_31 . V_210 + V_85 ) ;
if ( ! V_155 )
return;
F_159 ( V_155 , V_2 -> V_31 . V_210 ) ;
V_200 = ( void * ) F_160 ( V_155 , V_85 ) ;
V_200 -> V_211 = V_201 ;
V_200 -> V_212 = 0 ;
memcpy ( V_200 -> V_213 , V_4 -> V_4 . V_42 , V_71 ) ;
memcpy ( V_200 -> V_214 , V_13 -> V_19 . V_42 , V_71 ) ;
memcpy ( V_200 -> V_215 , V_13 -> V_19 . V_42 , V_71 ) ;
V_200 -> V_216 = 0 ;
V_155 -> V_217 = V_195 ;
F_161 ( V_155 , V_218 [ V_195 ] ) ;
if ( V_202 ) {
V_200 -> V_219 = F_55 ( V_195 ) ;
if ( V_197 == V_220 )
V_200 -> V_219 |=
F_55 ( V_221 ) ;
}
V_157 = F_96 ( V_155 ) ;
V_157 -> V_165 |= V_222 |
V_223 |
V_224 ;
V_157 -> V_164 . V_165 |= V_225 ;
if ( V_198 )
F_162 ( V_2 , V_4 , F_87 ( V_195 ) , 1 ,
V_197 , false ) ;
V_155 -> V_131 = V_13 -> V_131 ;
F_20 () ;
V_205 = F_163 ( V_13 -> V_19 . V_205 ) ;
if ( F_57 ( ! V_205 ) ) {
F_23 () ;
F_164 ( V_155 ) ;
return;
}
V_157 -> V_226 = V_205 -> V_227 . V_228 -> V_226 ;
F_165 ( V_13 , V_4 , V_155 ) ;
F_23 () ;
}
static int F_166 ( unsigned long V_147 )
{
if ( V_147 & 0xF8 )
return F_167 ( V_147 ) - 1 ;
if ( V_147 & F_87 ( 0 ) )
return 0 ;
return F_167 ( V_147 ) - 1 ;
}
static void
F_168 ( struct V_3 * V_4 ,
int V_229 , T_1 V_230 ,
enum V_196 V_197 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
bool V_231 = false ;
int V_8 ;
unsigned long V_232 = 0 ;
struct V_186 V_233 ;
F_69 ( V_4 , V_190 ) ;
F_169 ( & V_233 ) ;
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ ) {
unsigned long V_147 ;
if ( V_230 & F_87 ( V_8 ) )
continue;
V_147 = F_86 ( V_8 ) ;
if ( F_90 ( & V_233 ) ) {
V_232 |= V_4 -> V_148 & V_147 ;
V_232 |= V_4 -> V_149 & V_147 ;
}
if ( V_232 ) {
if ( V_197 == V_234 &&
F_170 ( V_232 ) > 1 ) {
V_231 = true ;
V_232 =
F_87 ( F_166 (
V_232 ) ) ;
break;
}
} else {
struct V_154 * V_155 ;
while ( V_229 > 0 ) {
V_155 = F_171 ( & V_4 -> V_36 [ V_8 ] ) ;
if ( ! V_155 ) {
V_155 = F_171 (
& V_4 -> V_35 [ V_8 ] ) ;
if ( V_155 )
V_2 -> V_34 -- ;
}
if ( ! V_155 )
break;
V_229 -- ;
F_172 ( & V_233 , V_155 ) ;
}
}
if ( ! F_90 ( & V_4 -> V_36 [ V_8 ] ) ||
! F_90 ( & V_4 -> V_35 [ V_8 ] ) ) {
V_231 = true ;
break;
}
}
if ( F_90 ( & V_233 ) && ! V_232 ) {
int V_195 ;
V_195 = 7 - ( ( F_173 ( ~ V_230 ) - 1 ) << 1 ) ;
F_157 ( V_13 , V_4 , V_195 , V_197 , true ) ;
} else if ( ! V_232 ) {
struct V_186 V_41 ;
struct V_154 * V_155 ;
int V_235 = 0 ;
T_4 V_147 = 0 ;
bool V_236 = false ;
F_54 ( & V_41 ) ;
while ( ( V_155 = F_101 ( & V_233 ) ) ) {
struct V_156 * V_157 = F_96 ( V_155 ) ;
struct V_237 * V_238 = ( void * ) V_155 -> V_172 ;
T_1 * V_239 = NULL ;
V_235 ++ ;
V_157 -> V_165 |= V_222 ;
V_157 -> V_164 . V_165 |= V_225 ;
if ( V_231 || ! F_90 ( & V_233 ) )
V_238 -> V_211 |=
F_55 ( V_240 ) ;
else
V_238 -> V_211 &=
F_55 ( ~ V_240 ) ;
if ( F_174 ( V_238 -> V_211 ) ||
F_175 ( V_238 -> V_211 ) )
V_239 = F_176 ( V_238 ) ;
V_147 |= F_87 ( V_155 -> V_217 ) ;
F_172 ( & V_41 , V_155 ) ;
if ( ! F_90 ( & V_233 ) )
continue;
if ( V_197 != V_220 ) {
V_157 -> V_165 |= V_223 |
V_224 ;
break;
}
if ( V_239 ) {
* V_239 |= V_221 ;
V_157 -> V_165 |= V_223 |
V_224 ;
} else {
V_238 -> V_211 |=
F_55 ( V_240 ) ;
V_236 = true ;
V_235 ++ ;
}
break;
}
F_162 ( V_2 , V_4 , V_147 , V_235 ,
V_197 , V_231 ) ;
F_150 ( V_2 , & V_41 ) ;
if ( V_236 )
F_157 (
V_13 , V_4 , F_166 ( V_147 ) ,
V_197 , false ) ;
F_94 ( V_4 ) ;
} else {
unsigned long V_147 = V_4 -> V_149 & V_232 ;
int V_195 ;
F_177 ( V_2 , V_4 , V_232 ,
V_229 , V_197 , V_231 ) ;
if ( ! V_4 -> V_4 . V_26 [ 0 ] )
return;
for ( V_195 = 0 ; V_195 < F_8 ( V_4 -> V_4 . V_26 ) ; V_195 ++ ) {
struct V_27 * V_28 = F_9 ( V_4 -> V_4 . V_26 [ V_195 ] ) ;
if ( ! ( V_147 & F_87 ( V_195 ) ) || F_10 ( & V_28 -> V_30 ) )
continue;
F_94 ( V_4 ) ;
break;
}
}
}
void F_37 ( struct V_3 * V_4 )
{
T_1 V_241 = V_4 -> V_4 . V_143 ;
if ( V_241 == F_87 ( V_33 ) - 1 )
V_241 = 0 ;
F_168 ( V_4 , 1 , V_241 ,
V_234 ) ;
}
void F_38 ( struct V_3 * V_4 )
{
int V_229 = V_4 -> V_4 . V_242 ;
T_1 V_243 = V_4 -> V_4 . V_143 ;
if ( ! V_243 )
return;
switch ( V_4 -> V_4 . V_242 ) {
case 1 :
V_229 = 2 ;
break;
case 2 :
V_229 = 4 ;
break;
case 3 :
V_229 = 6 ;
break;
case 0 :
V_229 = 128 ;
break;
}
F_168 ( V_4 , V_229 , ~ V_243 ,
V_220 ) ;
}
void F_178 ( struct V_59 * V_31 ,
struct V_183 * V_244 , bool V_245 )
{
struct V_3 * V_4 = F_33 ( V_244 , struct V_3 , V_4 ) ;
F_179 ( V_4 -> V_2 , V_244 , V_245 ) ;
if ( V_245 ) {
F_69 ( V_4 , V_17 ) ;
F_180 ( V_4 ) ;
return;
}
if ( ! F_4 ( V_4 , V_17 ) )
return;
if ( ! F_4 ( V_4 , V_16 ) ) {
F_69 ( V_4 , V_18 ) ;
F_6 ( V_4 , V_17 ) ;
F_181 ( V_31 , & V_4 -> V_37 ) ;
} else if ( F_4 ( V_4 , V_53 ) ||
F_4 ( V_4 , V_54 ) ) {
F_6 ( V_4 , V_17 ) ;
F_181 ( V_31 , & V_4 -> V_37 ) ;
} else {
F_6 ( V_4 , V_17 ) ;
F_156 ( V_4 ) ;
}
}
void F_182 ( struct V_183 * V_244 )
{
struct V_3 * V_4 = F_33 ( V_244 , struct V_3 , V_4 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_183 ( V_2 , V_244 ) ;
F_6 ( V_4 , V_190 ) ;
}
void F_184 ( struct V_183 * V_244 ,
T_1 V_195 , bool V_188 )
{
struct V_3 * V_4 = F_33 ( V_244 , struct V_3 , V_4 ) ;
if ( F_57 ( V_195 >= V_38 ) )
return;
F_185 ( V_4 -> V_2 , V_244 , V_195 , V_188 ) ;
if ( V_188 )
F_186 ( V_195 , & V_4 -> V_148 ) ;
else
F_187 ( V_195 , & V_4 -> V_148 ) ;
F_94 ( V_4 ) ;
}
int F_114 ( struct V_3 * V_4 ,
enum V_110 V_246 )
{
F_80 () ;
if ( V_4 -> V_75 == V_246 )
return 0 ;
switch ( V_246 ) {
case V_76 :
if ( V_4 -> V_75 != V_247 )
return - V_109 ;
break;
case V_247 :
if ( V_4 -> V_75 != V_76 &&
V_4 -> V_75 != V_248 )
return - V_109 ;
break;
case V_248 :
if ( V_4 -> V_75 != V_247 &&
V_4 -> V_75 != V_249 )
return - V_109 ;
break;
case V_249 :
if ( V_4 -> V_75 != V_248 )
return - V_109 ;
break;
default:
F_188 ( 1 , L_10 , V_246 ) ;
return - V_109 ;
}
F_28 ( V_4 -> V_13 , L_11 ,
V_4 -> V_4 . V_42 , V_246 ) ;
if ( F_4 ( V_4 , V_128 ) ) {
int V_112 = F_64 ( V_4 -> V_2 , V_4 -> V_13 , V_4 ,
V_4 -> V_75 , V_246 ) ;
if ( V_112 )
return V_112 ;
}
switch ( V_246 ) {
case V_76 :
if ( V_4 -> V_75 == V_247 )
F_187 ( V_250 , & V_4 -> V_251 ) ;
break;
case V_247 :
if ( V_4 -> V_75 == V_76 )
F_186 ( V_250 , & V_4 -> V_251 ) ;
else if ( V_4 -> V_75 == V_248 )
F_187 ( V_252 , & V_4 -> V_251 ) ;
break;
case V_248 :
if ( V_4 -> V_75 == V_247 ) {
F_186 ( V_252 , & V_4 -> V_251 ) ;
} else if ( V_4 -> V_75 == V_249 ) {
if ( V_4 -> V_13 -> V_19 . type == V_20 ||
( V_4 -> V_13 -> V_19 . type == V_21 &&
! V_4 -> V_13 -> V_23 . V_171 . V_4 ) )
F_7 ( & V_4 -> V_13 -> V_22 -> V_253 ) ;
F_187 ( V_254 , & V_4 -> V_251 ) ;
F_180 ( V_4 ) ;
}
break;
case V_249 :
if ( V_4 -> V_75 == V_248 ) {
if ( V_4 -> V_13 -> V_19 . type == V_20 ||
( V_4 -> V_13 -> V_19 . type == V_21 &&
! V_4 -> V_13 -> V_23 . V_171 . V_4 ) )
F_189 ( & V_4 -> V_13 -> V_22 -> V_253 ) ;
F_186 ( V_254 , & V_4 -> V_251 ) ;
F_156 ( V_4 ) ;
}
break;
default:
break;
}
V_4 -> V_75 = V_246 ;
return 0 ;
}
T_1 F_153 ( struct V_3 * V_4 )
{
struct V_255 * V_98 = & V_4 -> V_4 . V_98 ;
T_1 V_256 ;
if ( ! V_4 -> V_4 . V_98 . V_257 )
return 1 ;
if ( V_4 -> V_4 . V_258 . V_259 ) {
int V_9 ;
T_4 V_260 =
F_190 ( V_4 -> V_4 . V_258 . V_261 . V_260 ) ;
for ( V_9 = 7 ; V_9 >= 0 ; V_9 -- )
if ( ( V_260 & ( 0x3 << ( V_9 * 2 ) ) ) !=
V_262 )
return V_9 + 1 ;
}
if ( V_98 -> V_263 . V_264 [ 3 ] )
V_256 = 4 ;
else if ( V_98 -> V_263 . V_264 [ 2 ] )
V_256 = 3 ;
else if ( V_98 -> V_263 . V_264 [ 1 ] )
V_256 = 2 ;
else
V_256 = 1 ;
if ( ! ( V_98 -> V_263 . V_265 & V_266 ) )
return V_256 ;
return ( ( V_98 -> V_263 . V_265 & V_267 )
>> V_268 ) + 1 ;
}
static void F_191 ( struct V_3 * V_4 , struct V_269 * V_270 )
{
V_270 -> V_165 = 0 ;
if ( V_4 -> V_72 . V_271 & V_272 ) {
V_270 -> V_165 |= V_273 ;
V_270 -> V_263 = V_4 -> V_72 . V_274 ;
} else if ( V_4 -> V_72 . V_271 & V_275 ) {
V_270 -> V_165 |= V_276 ;
V_270 -> V_277 = V_4 -> V_72 . V_278 ;
V_270 -> V_263 = V_4 -> V_72 . V_274 ;
} else {
struct V_93 * V_94 ;
int V_279 = F_192 ( & V_4 -> V_13 -> V_19 ) ;
T_4 V_280 ;
V_94 = V_4 -> V_2 -> V_31 . V_95 -> V_96 [
F_56 ( V_4 -> V_13 ) ] ;
V_280 = V_94 -> V_281 [ V_4 -> V_72 . V_274 ] . V_282 ;
V_270 -> V_283 = F_193 ( V_280 , 1 << V_279 ) ;
}
if ( V_4 -> V_72 . V_271 & V_284 )
V_270 -> V_165 |= V_285 ;
if ( V_4 -> V_72 . V_271 & V_286 )
V_270 -> V_287 = V_288 ;
else if ( V_4 -> V_72 . V_271 & V_289 )
V_270 -> V_287 = V_290 ;
else if ( V_4 -> V_72 . V_271 & V_291 )
V_270 -> V_287 = V_292 ;
else if ( V_4 -> V_72 . V_293 & V_294 )
V_270 -> V_287 = V_295 ;
else if ( V_4 -> V_72 . V_293 & V_296 )
V_270 -> V_287 = V_297 ;
else
V_270 -> V_287 = V_298 ;
}
void F_115 ( struct V_3 * V_4 , struct V_117 * V_118 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_299 * V_300 = NULL ;
T_6 V_301 = 0 ;
int V_9 , V_8 ;
if ( F_4 ( V_4 , V_302 ) )
V_300 = V_2 -> V_48 ;
V_118 -> V_130 = V_13 -> V_2 -> V_123 ;
if ( V_13 -> V_19 . type == V_303 )
V_118 -> V_304 = V_13 -> V_23 . V_305 . V_306 ;
F_194 ( V_2 , V_13 , & V_4 -> V_4 , V_118 ) ;
V_118 -> V_129 |= F_87 ( V_307 ) |
F_87 ( V_308 ) |
F_87 ( V_309 ) |
F_87 ( V_310 ) |
F_87 ( V_311 ) ;
if ( V_13 -> V_19 . type == V_303 ) {
V_118 -> V_312 = V_13 -> V_23 . V_305 . V_312 ;
V_118 -> V_129 |= F_87 ( V_313 ) ;
}
V_118 -> V_314 = F_49 () - V_4 -> V_79 ;
V_118 -> V_315 =
F_195 ( V_74 - V_4 -> V_72 . V_73 ) ;
if ( ! ( V_118 -> V_129 & ( F_87 ( V_316 ) |
F_87 ( V_317 ) ) ) ) {
V_118 -> V_318 = 0 ;
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ )
V_118 -> V_318 += V_4 -> V_319 . V_320 [ V_8 ] ;
V_118 -> V_129 |= F_87 ( V_316 ) ;
}
if ( ! ( V_118 -> V_129 & F_87 ( V_321 ) ) ) {
V_118 -> V_322 = 0 ;
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ )
V_118 -> V_322 += V_4 -> V_319 . V_323 [ V_8 ] ;
V_118 -> V_129 |= F_87 ( V_321 ) ;
}
if ( ! ( V_118 -> V_129 & ( F_87 ( V_324 ) |
F_87 ( V_325 ) ) ) ) {
V_118 -> V_326 = V_4 -> V_72 . V_320 ;
V_118 -> V_129 |= F_87 ( V_324 ) ;
}
if ( ! ( V_118 -> V_129 & F_87 ( V_327 ) ) ) {
V_118 -> V_328 = V_4 -> V_72 . V_323 ;
V_118 -> V_129 |= F_87 ( V_327 ) ;
}
if ( ! ( V_118 -> V_129 & F_87 ( V_329 ) ) ) {
V_118 -> V_330 = V_4 -> V_331 . V_332 ;
V_118 -> V_129 |= F_87 ( V_329 ) ;
}
if ( ! ( V_118 -> V_129 & F_87 ( V_333 ) ) ) {
V_118 -> V_334 = V_4 -> V_331 . V_335 ;
V_118 -> V_129 |= F_87 ( V_333 ) ;
}
V_118 -> V_336 = V_4 -> V_72 . V_337 ;
if ( V_13 -> V_19 . type == V_303 &&
! ( V_13 -> V_19 . V_338 & V_339 ) ) {
V_118 -> V_129 |= F_87 ( V_340 ) |
F_87 ( V_341 ) ;
V_118 -> V_342 = F_196 ( & V_13 -> V_19 ) ;
}
if ( F_41 ( & V_4 -> V_2 -> V_31 , V_343 ) ||
F_41 ( & V_4 -> V_2 -> V_31 , V_344 ) ) {
if ( ! ( V_118 -> V_129 & F_87 ( V_345 ) ) ) {
V_118 -> signal = ( V_346 ) V_4 -> V_72 . V_347 ;
V_118 -> V_129 |= F_87 ( V_345 ) ;
}
if ( ! ( V_118 -> V_129 & F_87 ( V_348 ) ) ) {
V_118 -> V_349 =
- F_197 ( & V_4 -> V_72 . V_80 ) ;
V_118 -> V_129 |= F_87 ( V_348 ) ;
}
}
if ( V_4 -> V_72 . V_350 &&
! ( V_118 -> V_129 & ( F_87 ( V_351 ) |
F_87 ( V_352 ) ) ) ) {
V_118 -> V_129 |= F_87 ( V_351 ) |
F_87 ( V_352 ) ;
V_118 -> V_350 = V_4 -> V_72 . V_350 ;
for ( V_9 = 0 ; V_9 < F_8 ( V_118 -> V_353 ) ; V_9 ++ ) {
V_118 -> V_353 [ V_9 ] =
V_4 -> V_72 . V_354 [ V_9 ] ;
V_118 -> V_81 [ V_9 ] =
- F_197 ( & V_4 -> V_72 . V_81 [ V_9 ] ) ;
}
}
if ( ! ( V_118 -> V_129 & F_87 ( V_355 ) ) ) {
F_198 ( V_4 , & V_4 -> V_319 . V_356 ,
& V_118 -> V_357 ) ;
V_118 -> V_129 |= F_87 ( V_355 ) ;
}
if ( ! ( V_118 -> V_129 & F_87 ( V_358 ) ) ) {
F_191 ( V_4 , & V_118 -> V_359 ) ;
V_118 -> V_129 |= F_87 ( V_358 ) ;
}
V_118 -> V_129 |= F_87 ( V_360 ) ;
for ( V_9 = 0 ; V_9 < V_38 + 1 ; V_9 ++ ) {
struct V_361 * V_362 = & V_118 -> V_363 [ V_9 ] ;
if ( ! ( V_362 -> V_129 & F_87 ( V_364 ) ) ) {
V_362 -> V_129 |= F_87 ( V_364 ) ;
V_362 -> V_365 = V_4 -> V_72 . V_366 [ V_9 ] ;
}
if ( ! ( V_362 -> V_129 & F_87 ( V_367 ) ) ) {
V_362 -> V_129 |= F_87 ( V_367 ) ;
V_362 -> V_368 = V_4 -> V_319 . V_366 [ V_9 ] ;
}
if ( ! ( V_362 -> V_129 &
F_87 ( V_369 ) ) &&
F_41 ( & V_2 -> V_31 , V_370 ) ) {
V_362 -> V_129 |=
F_87 ( V_369 ) ;
V_362 -> V_371 =
V_4 -> V_331 . V_372 [ V_9 ] ;
}
if ( ! ( V_362 -> V_129 &
F_87 ( V_373 ) ) &&
F_41 ( & V_2 -> V_31 , V_370 ) ) {
V_362 -> V_129 |=
F_87 ( V_373 ) ;
V_362 -> V_374 =
V_4 -> V_331 . V_375 [ V_9 ] ;
}
}
if ( F_5 ( & V_13 -> V_19 ) ) {
#ifdef F_29
V_118 -> V_129 |= F_87 ( V_376 ) |
F_87 ( V_377 ) |
F_87 ( V_378 ) |
F_87 ( V_379 ) |
F_87 ( V_380 ) |
F_87 ( V_381 ) ;
V_118 -> V_382 = V_4 -> V_24 -> V_382 ;
V_118 -> V_383 = V_4 -> V_24 -> V_383 ;
V_118 -> V_384 = V_4 -> V_24 -> V_384 ;
if ( F_4 ( V_4 , V_385 ) ) {
V_118 -> V_129 |= F_87 ( V_386 ) ;
V_118 -> V_387 = V_4 -> V_24 -> V_387 ;
}
V_118 -> V_388 = V_4 -> V_24 -> V_388 ;
V_118 -> V_389 = V_4 -> V_24 -> V_389 ;
V_118 -> V_69 = V_4 -> V_24 -> V_69 ;
#endif
}
V_118 -> V_390 . V_165 = 0 ;
if ( V_13 -> V_19 . V_160 . V_391 )
V_118 -> V_390 . V_165 |= V_392 ;
if ( V_13 -> V_19 . V_160 . V_393 )
V_118 -> V_390 . V_165 |= V_394 ;
if ( V_13 -> V_19 . V_160 . V_395 )
V_118 -> V_390 . V_165 |= V_396 ;
V_118 -> V_390 . V_397 = V_13 -> V_19 . V_160 . V_397 ;
V_118 -> V_390 . V_398 = V_13 -> V_19 . V_160 . V_161 ;
V_118 -> V_399 . V_400 = 0 ;
V_118 -> V_399 . V_401 = F_87 ( V_402 ) |
F_87 ( V_403 ) |
F_87 ( V_404 ) |
F_87 ( V_405 ) |
F_87 ( V_406 ) |
F_87 ( V_407 ) |
F_87 ( V_408 ) ;
if ( F_4 ( V_4 , V_254 ) )
V_118 -> V_399 . V_400 |= F_87 ( V_402 ) ;
if ( F_4 ( V_4 , V_409 ) )
V_118 -> V_399 . V_400 |= F_87 ( V_403 ) ;
if ( V_4 -> V_4 . V_203 )
V_118 -> V_399 . V_400 |= F_87 ( V_404 ) ;
if ( F_4 ( V_4 , V_410 ) )
V_118 -> V_399 . V_400 |= F_87 ( V_405 ) ;
if ( F_4 ( V_4 , V_250 ) )
V_118 -> V_399 . V_400 |= F_87 ( V_406 ) ;
if ( F_4 ( V_4 , V_252 ) )
V_118 -> V_399 . V_400 |= F_87 ( V_407 ) ;
if ( F_4 ( V_4 , V_411 ) )
V_118 -> V_399 . V_400 |= F_87 ( V_408 ) ;
if ( V_300 && V_300 -> V_82 -> V_412 )
V_301 = V_300 -> V_82 -> V_412 ( V_4 -> V_57 ) ;
else
V_301 = F_199 ( V_2 , & V_4 -> V_4 ) ;
if ( V_301 != 0 ) {
V_118 -> V_129 |= F_87 ( V_413 ) ;
V_118 -> V_414 = V_301 ;
}
}
