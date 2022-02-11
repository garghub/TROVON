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
F_15 ( V_4 ) ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_30 ( & V_2 -> V_5 , & V_4 -> V_6 ,
V_7 ) ;
}
static void F_31 ( struct V_50 * V_51 )
{
struct V_3 * V_4 ;
V_4 = F_32 ( V_51 , struct V_3 , V_37 ) ;
if ( V_4 -> V_52 )
return;
F_33 () ;
if ( ! F_4 ( V_4 , V_16 ) )
F_34 ( V_4 ) ;
else if ( F_35 ( V_4 , V_53 ) )
F_36 ( V_4 ) ;
else if ( F_35 ( V_4 , V_54 ) )
F_37 ( V_4 ) ;
F_38 () ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 V_55 )
{
if ( V_2 -> V_31 . V_56 & V_57 )
return 0 ;
V_4 -> V_48 = V_2 -> V_48 ;
V_4 -> V_58 = F_40 ( V_4 -> V_48 ,
& V_4 -> V_4 , V_55 ) ;
if ( ! V_4 -> V_58 )
return - V_59 ;
return 0 ;
}
struct V_3 * F_41 ( struct V_12 * V_13 ,
const T_1 * V_42 , T_2 V_55 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_60 * V_31 = & V_2 -> V_31 ;
struct V_3 * V_4 ;
struct V_61 V_62 ;
int V_9 ;
V_4 = F_42 ( sizeof( * V_4 ) + V_31 -> V_63 , V_55 ) ;
if ( ! V_4 )
return NULL ;
F_43 ( & V_4 -> V_64 ) ;
F_43 ( & V_4 -> V_65 ) ;
F_44 ( & V_4 -> V_37 , F_31 ) ;
F_44 ( & V_4 -> V_39 . V_66 , V_67 ) ;
F_45 ( & V_4 -> V_39 . V_68 ) ;
#ifdef F_46
if ( F_5 ( & V_13 -> V_19 ) &&
! V_13 -> V_23 . V_24 . V_69 )
F_47 ( & V_4 -> V_70 ) ;
V_4 -> V_71 = V_72 ;
#endif
memcpy ( V_4 -> V_4 . V_42 , V_42 , V_73 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_13 = V_13 ;
V_4 -> V_74 = V_75 ;
V_4 -> V_76 = V_77 ;
V_4 -> V_78 = V_79 ;
F_48 ( & V_62 ) ;
V_4 -> V_80 = V_62 . V_81 ;
F_49 ( & V_4 -> V_82 , 1024 , 8 ) ;
for ( V_9 = 0 ; V_9 < F_8 ( V_4 -> V_83 ) ; V_9 ++ )
F_49 ( & V_4 -> V_83 [ V_9 ] , 1024 , 8 ) ;
if ( V_2 -> V_84 -> V_85 ) {
void * V_86 ;
int V_87 = sizeof( struct V_27 ) +
F_50 ( V_31 -> V_88 , sizeof( void * ) ) ;
V_86 = F_51 ( F_8 ( V_4 -> V_4 . V_26 ) , V_87 , V_55 ) ;
if ( ! V_86 )
goto free;
for ( V_9 = 0 ; V_9 < F_8 ( V_4 -> V_4 . V_26 ) ; V_9 ++ ) {
struct V_27 * V_26 = V_86 + V_9 * V_87 ;
F_52 ( V_13 , V_4 , V_26 , V_9 ) ;
}
}
if ( F_39 ( V_2 , V_4 , V_55 ) )
goto V_89;
for ( V_9 = 0 ; V_9 < V_38 ; V_9 ++ ) {
V_4 -> V_90 [ V_9 ] = V_9 ;
}
for ( V_9 = 0 ; V_9 < V_33 ; V_9 ++ ) {
F_53 ( & V_4 -> V_35 [ V_9 ] ) ;
F_53 ( & V_4 -> V_36 [ V_9 ] ) ;
}
for ( V_9 = 0 ; V_9 < V_38 ; V_9 ++ )
V_4 -> V_91 [ V_9 ] = F_54 ( V_92 ) ;
V_4 -> V_4 . V_93 = V_94 ;
if ( V_13 -> V_19 . type == V_20 ||
V_13 -> V_19 . type == V_21 ) {
struct V_95 * V_96 =
V_31 -> V_97 -> V_98 [ F_55 ( V_13 ) ] ;
T_1 V_99 = ( V_96 -> V_100 . V_101 & V_102 ) >>
V_103 ;
switch ( V_99 ) {
case V_104 :
V_4 -> V_105 = V_94 ;
break;
case V_106 :
V_4 -> V_105 = V_107 ;
break;
case V_108 :
V_4 -> V_105 = V_109 ;
break;
default:
F_56 ( 1 ) ;
}
}
F_28 ( V_13 , L_2 , V_4 -> V_4 . V_42 ) ;
return V_4 ;
V_89:
if ( V_4 -> V_4 . V_26 [ 0 ] )
F_15 ( F_9 ( V_4 -> V_4 . V_26 [ 0 ] ) ) ;
free:
F_15 ( V_4 ) ;
return NULL ;
}
static int F_57 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
if ( F_58 ( ! F_59 ( V_13 ) ) )
return - V_110 ;
if ( F_56 ( F_60 ( V_4 -> V_4 . V_42 , V_13 -> V_19 . V_42 ) ||
F_61 ( V_4 -> V_4 . V_42 ) ) )
return - V_111 ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_3 * V_4 )
{
enum V_112 V_113 ;
int V_114 = 0 ;
for ( V_113 = V_115 ; V_113 < V_4 -> V_76 ; V_113 ++ ) {
V_114 = F_63 ( V_2 , V_13 , V_4 , V_113 , V_113 + 1 ) ;
if ( V_114 )
break;
}
if ( ! V_114 ) {
if ( ! V_2 -> V_84 -> V_116 )
V_4 -> V_117 = true ;
return 0 ;
}
if ( V_13 -> V_19 . type == V_118 ) {
F_64 ( V_13 ,
L_3 ,
V_4 -> V_4 . V_42 , V_113 + 1 , V_114 ) ;
V_114 = 0 ;
}
for (; V_113 > V_115 ; V_113 -- )
F_56 ( F_63 ( V_2 , V_13 , V_4 , V_113 , V_113 - 1 ) ) ;
return V_114 ;
}
static int F_65 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_119 V_120 ;
int V_114 = 0 ;
F_66 ( & V_2 -> V_121 ) ;
if ( F_24 ( V_13 , V_4 -> V_4 . V_42 ) ) {
V_114 = - V_122 ;
goto V_123;
}
V_2 -> V_124 ++ ;
V_2 -> V_125 ++ ;
F_67 () ;
F_68 ( V_4 , V_126 ) ;
F_29 ( V_2 , V_4 ) ;
F_69 ( & V_4 -> V_127 , & V_2 -> V_128 ) ;
V_114 = F_62 ( V_2 , V_13 , V_4 ) ;
if ( V_114 )
goto V_129;
F_68 ( V_4 , V_130 ) ;
F_6 ( V_4 , V_126 ) ;
F_70 ( V_13 ) ;
F_71 ( V_4 ) ;
F_72 ( V_4 ) ;
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
V_120 . V_131 = 0 ;
V_120 . V_132 = V_2 -> V_125 ;
F_73 ( V_13 -> V_133 , V_4 -> V_4 . V_42 , & V_120 , V_134 ) ;
F_28 ( V_13 , L_4 , V_4 -> V_4 . V_42 ) ;
F_20 () ;
F_74 ( & V_2 -> V_121 ) ;
if ( F_5 ( & V_13 -> V_19 ) )
F_75 ( V_13 ) ;
return 0 ;
V_129:
F_1 ( V_2 , V_4 ) ;
F_76 ( & V_4 -> V_127 ) ;
V_2 -> V_124 -- ;
F_77 () ;
F_3 ( V_4 ) ;
V_123:
F_74 ( & V_2 -> V_121 ) ;
F_20 () ;
return V_114 ;
}
int F_78 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_114 ;
F_79 () ;
V_114 = F_57 ( V_4 ) ;
if ( V_114 ) {
F_20 () ;
goto V_135;
}
F_80 ( & V_2 -> V_121 ) ;
V_114 = F_65 ( V_4 ) ;
if ( V_114 )
goto V_135;
return 0 ;
V_135:
F_18 ( V_2 , V_4 ) ;
return V_114 ;
}
int F_81 ( struct V_3 * V_4 )
{
int V_114 = F_78 ( V_4 ) ;
F_23 () ;
return V_114 ;
}
static inline void F_82 ( T_1 * V_136 , T_4 V_137 )
{
V_136 [ V_137 / 8 ] |= ( 1 << ( V_137 % 8 ) ) ;
}
static inline void F_83 ( T_1 * V_136 , T_4 V_137 )
{
V_136 [ V_137 / 8 ] &= ~ ( 1 << ( V_137 % 8 ) ) ;
}
static inline bool F_84 ( T_1 * V_136 , T_4 V_137 )
{
return V_136 [ V_137 / 8 ] & ( 1 << ( V_137 % 8 ) ) ;
}
static unsigned long F_85 ( int V_8 )
{
switch ( V_8 ) {
case V_138 :
return F_86 ( 6 ) | F_86 ( 7 ) ;
case V_139 :
return F_86 ( 4 ) | F_86 ( 5 ) ;
case V_140 :
return F_86 ( 0 ) | F_86 ( 3 ) ;
case V_141 :
return F_86 ( 1 ) | F_86 ( 2 ) ;
default:
F_56 ( 1 ) ;
return 0 ;
}
}
static void F_87 ( struct V_3 * V_4 , bool V_142 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_14 * V_15 ;
bool V_143 = false ;
T_1 V_144 = V_4 -> V_4 . V_145 ;
int V_8 ;
T_4 V_137 ;
if ( V_4 -> V_13 -> V_19 . type == V_20 ||
V_4 -> V_13 -> V_19 . type == V_21 ) {
if ( F_88 ( ! V_4 -> V_13 -> V_22 ) )
return;
V_15 = & V_4 -> V_13 -> V_22 -> V_15 ;
V_137 = V_4 -> V_4 . V_146 ;
#ifdef F_46
} else if ( F_5 ( & V_4 -> V_13 -> V_19 ) ) {
V_15 = & V_4 -> V_13 -> V_23 . V_24 . V_15 ;
V_137 = V_4 -> V_147 % ( V_148 + 1 ) ;
#endif
} else {
return;
}
if ( V_2 -> V_31 . V_56 & V_149 )
return;
if ( V_4 -> V_52 )
goto V_150;
if ( V_144 == F_86 ( V_33 ) - 1 )
V_144 = 0 ;
if ( V_142 )
V_144 = F_86 ( V_33 ) - 1 ;
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ ) {
unsigned long V_151 ;
if ( V_144 & F_86 ( V_8 ) )
continue;
V_143 |= ! F_89 ( & V_4 -> V_36 [ V_8 ] ) ||
! F_89 ( & V_4 -> V_35 [ V_8 ] ) ;
if ( V_143 )
break;
V_151 = F_85 ( V_8 ) ;
V_143 |=
V_4 -> V_152 & V_151 ;
V_143 |=
V_4 -> V_153 & V_151 ;
}
V_150:
F_90 ( & V_2 -> V_154 ) ;
if ( V_143 == F_84 ( V_15 -> V_136 , V_137 ) )
goto V_155;
if ( V_143 )
F_82 ( V_15 -> V_136 , V_137 ) ;
else
F_83 ( V_15 -> V_136 , V_137 ) ;
if ( V_2 -> V_84 -> V_156 && ! F_56 ( V_4 -> V_52 ) ) {
V_2 -> V_157 = true ;
F_91 ( V_2 , & V_4 -> V_4 , V_143 ) ;
V_2 -> V_157 = false ;
}
V_155:
F_92 ( & V_2 -> V_154 ) ;
}
void F_93 ( struct V_3 * V_4 )
{
F_87 ( V_4 , false ) ;
}
static bool F_94 ( struct V_3 * V_4 , struct V_158 * V_159 )
{
struct V_160 * V_161 ;
int V_162 ;
if ( ! V_159 )
return false ;
V_161 = F_95 ( V_159 ) ;
V_162 = ( V_4 -> V_163 *
V_4 -> V_13 -> V_19 . V_164 . V_165 *
32 / 15625 ) * V_166 ;
if ( V_162 < V_167 )
V_162 = V_167 ;
return F_96 ( V_75 , V_161 -> V_168 . V_75 + V_162 ) ;
}
static bool F_97 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_8 )
{
unsigned long V_56 ;
struct V_158 * V_159 ;
for (; ; ) {
F_98 ( & V_4 -> V_36 [ V_8 ] . V_64 , V_56 ) ;
V_159 = F_99 ( & V_4 -> V_36 [ V_8 ] ) ;
if ( F_94 ( V_4 , V_159 ) )
V_159 = F_100 ( & V_4 -> V_36 [ V_8 ] ) ;
else
V_159 = NULL ;
F_101 ( & V_4 -> V_36 [ V_8 ] . V_64 , V_56 ) ;
if ( ! V_159 )
break;
F_102 ( & V_2 -> V_31 , V_159 ) ;
}
for (; ; ) {
F_98 ( & V_4 -> V_35 [ V_8 ] . V_64 , V_56 ) ;
V_159 = F_99 ( & V_4 -> V_35 [ V_8 ] ) ;
if ( F_94 ( V_4 , V_159 ) )
V_159 = F_100 ( & V_4 -> V_35 [ V_8 ] ) ;
else
V_159 = NULL ;
F_101 ( & V_4 -> V_35 [ V_8 ] . V_64 , V_56 ) ;
if ( ! V_159 )
break;
V_2 -> V_34 -- ;
F_103 ( V_4 -> V_13 , L_5 ,
V_4 -> V_4 . V_42 ) ;
F_102 ( & V_2 -> V_31 , V_159 ) ;
}
F_93 ( V_4 ) ;
return ! ( F_89 ( & V_4 -> V_35 [ V_8 ] ) &&
F_89 ( & V_4 -> V_36 [ V_8 ] ) ) ;
}
static bool F_104 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_169 = false ;
int V_8 ;
if ( ! V_4 -> V_13 -> V_22 &&
! F_5 ( & V_4 -> V_13 -> V_19 ) )
return false ;
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ )
V_169 |=
F_97 ( V_2 , V_4 , V_8 ) ;
return V_169 ;
}
static int T_5 F_105 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
int V_170 ;
F_79 () ;
if ( ! V_4 )
return - V_171 ;
V_2 = V_4 -> V_2 ;
V_13 = V_4 -> V_13 ;
F_66 ( & V_2 -> V_121 ) ;
F_68 ( V_4 , V_126 ) ;
F_106 ( V_4 , V_172 ) ;
V_170 = F_1 ( V_2 , V_4 ) ;
if ( F_56 ( V_170 ) )
return V_170 ;
if ( F_4 ( V_4 , V_173 ) ) {
F_107 ( V_2 , V_13 , & V_4 -> V_4 ) ;
F_6 ( V_4 , V_173 ) ;
}
F_76 ( & V_4 -> V_127 ) ;
F_108 ( V_2 , V_4 -> V_13 , V_4 ) ;
if ( V_13 -> V_19 . type == V_21 &&
F_109 ( V_13 -> V_23 . V_174 . V_4 ) == V_4 )
F_110 ( V_13 -> V_23 . V_174 . V_4 , NULL ) ;
return 0 ;
}
static void F_111 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_119 V_120 = {} ;
int V_170 ;
F_79 () ;
F_66 ( & V_2 -> V_121 ) ;
F_112 ( V_2 , V_4 ) ;
F_87 ( V_4 , true ) ;
V_4 -> V_52 = true ;
V_2 -> V_124 -- ;
V_2 -> V_125 ++ ;
while ( V_4 -> V_76 > V_77 ) {
V_170 = F_113 ( V_4 , V_4 -> V_76 - 1 ) ;
if ( V_170 ) {
F_88 ( 1 ) ;
break;
}
}
if ( V_4 -> V_117 ) {
V_170 = F_63 ( V_2 , V_13 , V_4 , V_77 ,
V_115 ) ;
F_88 ( V_170 != 0 ) ;
}
F_28 ( V_13 , L_6 , V_4 -> V_4 . V_42 ) ;
F_114 ( V_4 , & V_120 ) ;
F_115 ( V_13 -> V_133 , V_4 -> V_4 . V_42 , & V_120 , V_134 ) ;
F_116 ( V_4 ) ;
F_117 ( V_4 ) ;
F_70 ( V_13 ) ;
F_17 ( V_4 ) ;
}
int T_5 F_118 ( struct V_3 * V_4 )
{
int V_114 = F_105 ( V_4 ) ;
if ( V_114 )
return V_114 ;
F_77 () ;
F_111 ( V_4 ) ;
return 0 ;
}
int F_119 ( struct V_12 * V_13 , const T_1 * V_42 )
{
struct V_3 * V_4 ;
int V_170 ;
F_80 ( & V_13 -> V_2 -> V_121 ) ;
V_4 = F_19 ( V_13 , V_42 ) ;
V_170 = F_118 ( V_4 ) ;
F_74 ( & V_13 -> V_2 -> V_121 ) ;
return V_170 ;
}
int F_120 ( struct V_12 * V_13 ,
const T_1 * V_42 )
{
struct V_3 * V_4 ;
int V_170 ;
F_80 ( & V_13 -> V_2 -> V_121 ) ;
V_4 = F_24 ( V_13 , V_42 ) ;
V_170 = F_118 ( V_4 ) ;
F_74 ( & V_13 -> V_2 -> V_121 ) ;
return V_170 ;
}
static void F_121 ( unsigned long V_175 )
{
struct V_1 * V_2 = (struct V_1 * ) V_175 ;
struct V_3 * V_4 ;
bool V_176 = false ;
F_20 () ;
F_26 (sta, &local->sta_list, list)
if ( F_104 ( V_2 , V_4 ) )
V_176 = true ;
F_23 () ;
if ( V_2 -> V_177 )
return;
if ( ! V_176 )
return;
F_122 ( & V_2 -> V_178 ,
F_123 ( V_75 + V_179 ) ) ;
}
T_6 F_124 ( const void * V_180 , T_6 V_181 , T_6 V_182 )
{
return F_125 ( V_180 , V_73 , V_182 ) ;
}
int F_126 ( struct V_1 * V_2 )
{
int V_114 ;
V_114 = F_127 ( & V_2 -> V_5 , & V_7 ) ;
if ( V_114 )
return V_114 ;
F_43 ( & V_2 -> V_154 ) ;
F_45 ( & V_2 -> V_121 ) ;
F_128 ( & V_2 -> V_128 ) ;
F_129 ( & V_2 -> V_178 , F_121 ,
( unsigned long ) V_2 ) ;
return 0 ;
}
void F_130 ( struct V_1 * V_2 )
{
F_131 ( & V_2 -> V_178 ) ;
F_132 ( & V_2 -> V_5 ) ;
}
int F_133 ( struct V_12 * V_13 , bool V_183 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 , * V_44 ;
F_134 ( V_184 ) ;
int V_170 = 0 ;
F_79 () ;
F_56 ( V_183 && V_13 -> V_19 . type != V_20 ) ;
F_56 ( V_183 && ! V_13 -> V_22 ) ;
F_80 ( & V_2 -> V_121 ) ;
F_135 (sta, tmp, &local->sta_list, list) {
if ( V_13 == V_4 -> V_13 ||
( V_183 && V_13 -> V_22 == V_4 -> V_13 -> V_22 ) ) {
if ( ! F_56 ( F_105 ( V_4 ) ) )
F_136 ( & V_4 -> V_184 , & V_184 ) ;
V_170 ++ ;
}
}
if ( ! F_137 ( & V_184 ) ) {
F_77 () ;
F_135 (sta, tmp, &free_list, free_list)
F_111 ( V_4 ) ;
}
F_74 ( & V_2 -> V_121 ) ;
return V_170 ;
}
void F_138 ( struct V_12 * V_13 ,
unsigned long V_185 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 , * V_44 ;
F_80 ( & V_2 -> V_121 ) ;
F_135 (sta, tmp, &local->sta_list, list) {
if ( V_13 != V_4 -> V_13 )
continue;
if ( F_96 ( V_75 , V_4 -> V_74 + V_185 ) ) {
F_28 ( V_4 -> V_13 , L_7 ,
V_4 -> V_4 . V_42 ) ;
if ( F_5 ( & V_13 -> V_19 ) &&
F_4 ( V_4 , V_16 ) )
F_7 ( & V_13 -> V_23 . V_24 . V_15 . V_25 ) ;
F_56 ( F_118 ( V_4 ) ) ;
}
}
F_74 ( & V_2 -> V_121 ) ;
}
struct V_186 * F_139 ( struct V_60 * V_31 ,
const T_1 * V_42 ,
const T_1 * V_187 )
{
struct V_1 * V_2 = F_140 ( V_31 ) ;
struct V_3 * V_4 ;
struct V_43 * V_44 ;
const struct V_45 * V_46 ;
V_46 = F_21 ( V_2 -> V_5 . V_46 , & V_2 -> V_5 ) ;
F_22 (local, tbl, addr, sta, tmp) {
if ( V_187 &&
! F_60 ( V_4 -> V_13 -> V_19 . V_42 , V_187 ) )
continue;
if ( ! V_4 -> V_117 )
return NULL ;
return & V_4 -> V_4 ;
}
return NULL ;
}
struct V_186 * F_141 ( struct V_188 * V_19 ,
const T_1 * V_42 )
{
struct V_3 * V_4 ;
if ( ! V_19 )
return NULL ;
V_4 = F_24 ( F_142 ( V_19 ) , V_42 ) ;
if ( ! V_4 )
return NULL ;
if ( ! V_4 -> V_117 )
return NULL ;
return & V_4 -> V_4 ;
}
void F_34 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_189 V_41 ;
int V_190 = 0 , V_191 = 0 , V_8 , V_9 ;
unsigned long V_56 ;
struct V_14 * V_15 ;
if ( V_13 -> V_19 . type == V_21 )
V_13 = F_32 ( V_13 -> V_22 , struct V_12 ,
V_23 . V_192 ) ;
if ( V_13 -> V_19 . type == V_20 )
V_15 = & V_13 -> V_22 -> V_15 ;
else if ( F_5 ( & V_13 -> V_19 ) )
V_15 = & V_13 -> V_23 . V_24 . V_15 ;
else
return;
F_6 ( V_4 , V_193 ) ;
F_143 ( F_144 ( V_38 ) > 1 ) ;
V_4 -> V_152 = 0 ;
V_4 -> V_153 = 0 ;
if ( ! ( V_2 -> V_31 . V_56 & V_149 ) )
F_145 ( V_2 , V_13 , V_194 , & V_4 -> V_4 ) ;
if ( V_4 -> V_4 . V_26 [ 0 ] ) {
for ( V_9 = 0 ; V_9 < F_8 ( V_4 -> V_4 . V_26 ) ; V_9 ++ ) {
struct V_27 * V_28 = F_9 ( V_4 -> V_4 . V_26 [ V_9 ] ) ;
if ( ! F_10 ( & V_28 -> V_30 ) )
continue;
F_146 ( V_2 , V_28 ) ;
}
}
F_53 ( & V_41 ) ;
F_147 ( & V_4 -> V_65 ) ;
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ ) {
int V_195 = F_10 ( & V_41 ) , V_44 ;
F_98 ( & V_4 -> V_36 [ V_8 ] . V_64 , V_56 ) ;
F_148 ( & V_4 -> V_36 [ V_8 ] , & V_41 ) ;
F_101 ( & V_4 -> V_36 [ V_8 ] . V_64 , V_56 ) ;
V_44 = F_10 ( & V_41 ) ;
V_190 += V_44 - V_195 ;
V_195 = V_44 ;
F_98 ( & V_4 -> V_35 [ V_8 ] . V_64 , V_56 ) ;
F_148 ( & V_4 -> V_35 [ V_8 ] , & V_41 ) ;
F_101 ( & V_4 -> V_35 [ V_8 ] . V_64 , V_56 ) ;
V_44 = F_10 ( & V_41 ) ;
V_191 += V_44 - V_195 ;
}
F_149 ( V_2 , & V_41 ) ;
F_6 ( V_4 , V_18 ) ;
F_6 ( V_4 , V_53 ) ;
F_6 ( V_4 , V_54 ) ;
F_150 ( & V_4 -> V_65 ) ;
F_7 ( & V_15 -> V_25 ) ;
if ( ! F_5 ( & V_13 -> V_19 ) &&
! F_151 ( V_4 -> V_105 ,
V_13 -> V_93 ) &&
V_4 -> V_105 != V_13 -> V_22 -> V_196 &&
F_152 ( V_4 ) != 1 ) {
F_153 ( V_13 ,
L_8 ,
V_4 -> V_4 . V_42 ) ;
F_154 ( V_13 , V_13 -> V_22 -> V_196 ,
V_4 -> V_4 . V_42 ,
V_13 -> V_19 . V_164 . V_197 ) ;
}
V_2 -> V_34 -= V_191 ;
F_93 ( V_4 ) ;
F_103 ( V_13 ,
L_9 ,
V_4 -> V_4 . V_42 , V_4 -> V_4 . V_146 , V_190 , V_191 ) ;
}
static void F_155 ( struct V_12 * V_13 ,
struct V_3 * V_4 , int V_198 ,
enum V_199 V_200 ,
bool V_201 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_202 * V_203 ;
struct V_158 * V_159 ;
int V_87 = sizeof( * V_203 ) ;
T_7 V_204 ;
bool V_205 = V_4 -> V_4 . V_206 ;
struct V_160 * V_161 ;
struct V_207 * V_208 ;
if ( V_205 ) {
V_204 = F_54 ( V_209 |
V_210 |
V_211 ) ;
} else {
V_87 -= 2 ;
V_204 = F_54 ( V_209 |
V_212 |
V_211 ) ;
}
V_159 = F_156 ( V_2 -> V_31 . V_213 + V_87 ) ;
if ( ! V_159 )
return;
F_157 ( V_159 , V_2 -> V_31 . V_213 ) ;
V_203 = ( void * ) F_158 ( V_159 , V_87 ) ;
V_203 -> V_214 = V_204 ;
V_203 -> V_215 = 0 ;
memcpy ( V_203 -> V_216 , V_4 -> V_4 . V_42 , V_73 ) ;
memcpy ( V_203 -> V_217 , V_13 -> V_19 . V_42 , V_73 ) ;
memcpy ( V_203 -> V_218 , V_13 -> V_19 . V_42 , V_73 ) ;
V_203 -> V_219 = 0 ;
V_159 -> V_220 = V_198 ;
F_159 ( V_159 , V_221 [ V_198 ] ) ;
if ( V_205 ) {
V_203 -> V_222 = F_54 ( V_198 ) ;
if ( V_200 == V_223 )
V_203 -> V_222 |=
F_54 ( V_224 ) ;
}
V_161 = F_95 ( V_159 ) ;
V_161 -> V_56 |= V_225 |
V_226 |
V_227 ;
V_161 -> V_168 . V_56 |= V_228 ;
if ( V_201 )
F_160 ( V_2 , V_4 , F_86 ( V_198 ) , 1 ,
V_200 , false ) ;
V_159 -> V_133 = V_13 -> V_133 ;
F_20 () ;
V_208 = F_161 ( V_13 -> V_19 . V_208 ) ;
if ( F_56 ( ! V_208 ) ) {
F_23 () ;
F_162 ( V_159 ) ;
return;
}
V_161 -> V_229 = V_208 -> V_230 . V_231 -> V_229 ;
F_163 ( V_13 , V_4 , V_159 ) ;
F_23 () ;
}
static int F_164 ( unsigned long V_151 )
{
if ( V_151 & 0xF8 )
return F_165 ( V_151 ) - 1 ;
if ( V_151 & F_86 ( 0 ) )
return 0 ;
return F_165 ( V_151 ) - 1 ;
}
static void
F_166 ( struct V_3 * V_4 ,
int V_232 , T_1 V_233 ,
enum V_199 V_200 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
bool V_234 = false ;
int V_8 ;
unsigned long V_235 = 0 ;
struct V_189 V_236 ;
F_68 ( V_4 , V_193 ) ;
F_167 ( & V_236 ) ;
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ ) {
unsigned long V_151 ;
if ( V_233 & F_86 ( V_8 ) )
continue;
V_151 = F_85 ( V_8 ) ;
if ( F_89 ( & V_236 ) ) {
V_235 |= V_4 -> V_152 & V_151 ;
V_235 |= V_4 -> V_153 & V_151 ;
}
if ( V_235 ) {
if ( V_200 == V_237 &&
F_168 ( V_235 ) > 1 ) {
V_234 = true ;
V_235 =
F_86 ( F_164 (
V_235 ) ) ;
break;
}
} else {
struct V_158 * V_159 ;
while ( V_232 > 0 ) {
V_159 = F_169 ( & V_4 -> V_36 [ V_8 ] ) ;
if ( ! V_159 ) {
V_159 = F_169 (
& V_4 -> V_35 [ V_8 ] ) ;
if ( V_159 )
V_2 -> V_34 -- ;
}
if ( ! V_159 )
break;
V_232 -- ;
F_170 ( & V_236 , V_159 ) ;
}
}
if ( ! F_89 ( & V_4 -> V_36 [ V_8 ] ) ||
! F_89 ( & V_4 -> V_35 [ V_8 ] ) ) {
V_234 = true ;
break;
}
}
if ( F_89 ( & V_236 ) && ! V_235 ) {
int V_198 ;
V_198 = 7 - ( ( F_171 ( ~ V_233 ) - 1 ) << 1 ) ;
F_155 ( V_13 , V_4 , V_198 , V_200 , true ) ;
} else if ( ! V_235 ) {
struct V_189 V_41 ;
struct V_158 * V_159 ;
int V_238 = 0 ;
T_4 V_151 = 0 ;
bool V_239 = false ;
F_53 ( & V_41 ) ;
while ( ( V_159 = F_100 ( & V_236 ) ) ) {
struct V_160 * V_161 = F_95 ( V_159 ) ;
struct V_240 * V_241 = ( void * ) V_159 -> V_175 ;
T_1 * V_242 = NULL ;
V_238 ++ ;
V_161 -> V_56 |= V_225 ;
V_161 -> V_168 . V_56 |= V_228 ;
if ( V_234 || ! F_89 ( & V_236 ) )
V_241 -> V_214 |=
F_54 ( V_243 ) ;
else
V_241 -> V_214 &=
F_54 ( ~ V_243 ) ;
if ( F_172 ( V_241 -> V_214 ) ||
F_173 ( V_241 -> V_214 ) )
V_242 = F_174 ( V_241 ) ;
V_151 |= F_86 ( V_159 -> V_220 ) ;
F_170 ( & V_41 , V_159 ) ;
if ( ! F_89 ( & V_236 ) )
continue;
if ( V_200 != V_223 ) {
V_161 -> V_56 |= V_226 |
V_227 ;
break;
}
if ( V_242 ) {
* V_242 |= V_224 ;
V_161 -> V_56 |= V_226 |
V_227 ;
} else {
V_241 -> V_214 |=
F_54 ( V_243 ) ;
V_239 = true ;
V_238 ++ ;
}
break;
}
F_160 ( V_2 , V_4 , V_151 , V_238 ,
V_200 , V_234 ) ;
F_149 ( V_2 , & V_41 ) ;
if ( V_239 )
F_155 (
V_13 , V_4 , F_164 ( V_151 ) ,
V_200 , false ) ;
F_93 ( V_4 ) ;
} else {
unsigned long V_151 = V_4 -> V_153 & V_235 ;
int V_198 ;
F_175 ( V_2 , V_4 , V_235 ,
V_232 , V_200 , V_234 ) ;
if ( ! V_4 -> V_4 . V_26 [ 0 ] )
return;
for ( V_198 = 0 ; V_198 < F_8 ( V_4 -> V_4 . V_26 ) ; V_198 ++ ) {
struct V_27 * V_28 = F_9 ( V_4 -> V_4 . V_26 [ V_198 ] ) ;
if ( ! ( V_151 & F_86 ( V_198 ) ) || F_10 ( & V_28 -> V_30 ) )
continue;
F_93 ( V_4 ) ;
break;
}
}
}
void F_36 ( struct V_3 * V_4 )
{
T_1 V_244 = V_4 -> V_4 . V_145 ;
if ( V_244 == F_86 ( V_33 ) - 1 )
V_244 = 0 ;
F_166 ( V_4 , 1 , V_244 ,
V_237 ) ;
}
void F_37 ( struct V_3 * V_4 )
{
int V_232 = V_4 -> V_4 . V_245 ;
T_1 V_246 = V_4 -> V_4 . V_145 ;
if ( ! V_246 )
return;
switch ( V_4 -> V_4 . V_245 ) {
case 1 :
V_232 = 2 ;
break;
case 2 :
V_232 = 4 ;
break;
case 3 :
V_232 = 6 ;
break;
case 0 :
V_232 = 128 ;
break;
}
F_166 ( V_4 , V_232 , ~ V_246 ,
V_223 ) ;
}
void F_176 ( struct V_60 * V_31 ,
struct V_186 * V_247 , bool V_248 )
{
struct V_3 * V_4 = F_32 ( V_247 , struct V_3 , V_4 ) ;
F_177 ( V_4 -> V_2 , V_247 , V_248 ) ;
if ( V_248 ) {
F_68 ( V_4 , V_17 ) ;
return;
}
if ( ! F_4 ( V_4 , V_17 ) )
return;
if ( ! F_4 ( V_4 , V_16 ) ) {
F_68 ( V_4 , V_18 ) ;
F_6 ( V_4 , V_17 ) ;
F_178 ( V_31 , & V_4 -> V_37 ) ;
} else if ( F_4 ( V_4 , V_53 ) ||
F_4 ( V_4 , V_54 ) ) {
F_6 ( V_4 , V_17 ) ;
F_178 ( V_31 , & V_4 -> V_37 ) ;
} else {
F_6 ( V_4 , V_17 ) ;
}
}
void F_179 ( struct V_186 * V_247 )
{
struct V_3 * V_4 = F_32 ( V_247 , struct V_3 , V_4 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_180 ( V_2 , V_247 ) ;
F_6 ( V_4 , V_193 ) ;
}
void F_181 ( struct V_186 * V_247 ,
T_1 V_198 , bool V_191 )
{
struct V_3 * V_4 = F_32 ( V_247 , struct V_3 , V_4 ) ;
if ( F_56 ( V_198 >= V_38 ) )
return;
F_182 ( V_4 -> V_2 , V_247 , V_198 , V_191 ) ;
if ( V_191 )
F_183 ( V_198 , & V_4 -> V_152 ) ;
else
F_184 ( V_198 , & V_4 -> V_152 ) ;
F_93 ( V_4 ) ;
}
int F_113 ( struct V_3 * V_4 ,
enum V_112 V_249 )
{
F_79 () ;
if ( V_4 -> V_76 == V_249 )
return 0 ;
switch ( V_249 ) {
case V_77 :
if ( V_4 -> V_76 != V_250 )
return - V_111 ;
break;
case V_250 :
if ( V_4 -> V_76 != V_77 &&
V_4 -> V_76 != V_251 )
return - V_111 ;
break;
case V_251 :
if ( V_4 -> V_76 != V_250 &&
V_4 -> V_76 != V_252 )
return - V_111 ;
break;
case V_252 :
if ( V_4 -> V_76 != V_251 )
return - V_111 ;
break;
default:
F_185 ( 1 , L_10 , V_249 ) ;
return - V_111 ;
}
F_28 ( V_4 -> V_13 , L_11 ,
V_4 -> V_4 . V_42 , V_249 ) ;
if ( F_4 ( V_4 , V_130 ) ) {
int V_114 = F_63 ( V_4 -> V_2 , V_4 -> V_13 , V_4 ,
V_4 -> V_76 , V_249 ) ;
if ( V_114 )
return V_114 ;
}
switch ( V_249 ) {
case V_77 :
if ( V_4 -> V_76 == V_250 )
F_184 ( V_253 , & V_4 -> V_254 ) ;
break;
case V_250 :
if ( V_4 -> V_76 == V_77 )
F_183 ( V_253 , & V_4 -> V_254 ) ;
else if ( V_4 -> V_76 == V_251 )
F_184 ( V_255 , & V_4 -> V_254 ) ;
break;
case V_251 :
if ( V_4 -> V_76 == V_250 ) {
F_183 ( V_255 , & V_4 -> V_254 ) ;
} else if ( V_4 -> V_76 == V_252 ) {
if ( V_4 -> V_13 -> V_19 . type == V_20 ||
( V_4 -> V_13 -> V_19 . type == V_21 &&
! V_4 -> V_13 -> V_23 . V_174 . V_4 ) )
F_7 ( & V_4 -> V_13 -> V_22 -> V_256 ) ;
F_184 ( V_257 , & V_4 -> V_254 ) ;
}
break;
case V_252 :
if ( V_4 -> V_76 == V_251 ) {
if ( V_4 -> V_13 -> V_19 . type == V_20 ||
( V_4 -> V_13 -> V_19 . type == V_21 &&
! V_4 -> V_13 -> V_23 . V_174 . V_4 ) )
F_186 ( & V_4 -> V_13 -> V_22 -> V_256 ) ;
F_183 ( V_257 , & V_4 -> V_254 ) ;
}
break;
default:
break;
}
V_4 -> V_76 = V_249 ;
return 0 ;
}
T_1 F_152 ( struct V_3 * V_4 )
{
struct V_258 * V_100 = & V_4 -> V_4 . V_100 ;
T_1 V_259 ;
if ( ! V_4 -> V_4 . V_100 . V_260 )
return 1 ;
if ( V_4 -> V_4 . V_261 . V_262 ) {
int V_9 ;
T_4 V_263 =
F_187 ( V_4 -> V_4 . V_261 . V_264 . V_263 ) ;
for ( V_9 = 7 ; V_9 >= 0 ; V_9 -- )
if ( ( V_263 & ( 0x3 << ( V_9 * 2 ) ) ) !=
V_265 )
return V_9 + 1 ;
}
if ( V_100 -> V_266 . V_267 [ 3 ] )
V_259 = 4 ;
else if ( V_100 -> V_266 . V_267 [ 2 ] )
V_259 = 3 ;
else if ( V_100 -> V_266 . V_267 [ 1 ] )
V_259 = 2 ;
else
V_259 = 1 ;
if ( ! ( V_100 -> V_266 . V_268 & V_269 ) )
return V_259 ;
return ( ( V_100 -> V_266 . V_268 & V_270 )
>> V_271 ) + 1 ;
}
void F_114 ( struct V_3 * V_4 , struct V_119 * V_120 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_272 * V_273 = NULL ;
struct V_61 V_62 ;
T_6 V_274 = 0 ;
int V_9 , V_8 ;
if ( F_4 ( V_4 , V_275 ) )
V_273 = V_2 -> V_48 ;
V_120 -> V_132 = V_13 -> V_2 -> V_125 ;
if ( V_13 -> V_19 . type == V_276 )
V_120 -> V_277 = V_13 -> V_23 . V_278 . V_279 ;
F_188 ( V_2 , V_13 , & V_4 -> V_4 , V_120 ) ;
V_120 -> V_131 |= F_86 ( V_280 ) |
F_86 ( V_281 ) |
F_86 ( V_282 ) |
F_86 ( V_283 ) |
F_86 ( V_284 ) |
F_86 ( V_285 ) ;
F_48 ( & V_62 ) ;
V_120 -> V_286 = V_62 . V_81 - V_4 -> V_80 ;
V_120 -> V_287 = F_189 ( V_75 - V_4 -> V_74 ) ;
if ( ! ( V_120 -> V_131 & ( F_86 ( V_288 ) |
F_86 ( V_289 ) ) ) ) {
V_120 -> V_290 = 0 ;
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ )
V_120 -> V_290 += V_4 -> V_290 [ V_8 ] ;
V_120 -> V_131 |= F_86 ( V_288 ) ;
}
if ( ! ( V_120 -> V_131 & F_86 ( V_291 ) ) ) {
V_120 -> V_292 = 0 ;
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ )
V_120 -> V_292 += V_4 -> V_292 [ V_8 ] ;
V_120 -> V_131 |= F_86 ( V_291 ) ;
}
if ( ! ( V_120 -> V_131 & ( F_86 ( V_293 ) |
F_86 ( V_294 ) ) ) ) {
V_120 -> V_295 = V_4 -> V_295 ;
V_120 -> V_131 |= F_86 ( V_293 ) ;
}
if ( ! ( V_120 -> V_131 & F_86 ( V_296 ) ) ) {
V_120 -> V_297 = V_4 -> V_297 ;
V_120 -> V_131 |= F_86 ( V_296 ) ;
}
if ( ! ( V_120 -> V_131 & F_86 ( V_298 ) ) ) {
V_120 -> V_299 = V_4 -> V_300 ;
V_120 -> V_131 |= F_86 ( V_298 ) ;
}
if ( ! ( V_120 -> V_131 & F_86 ( V_301 ) ) ) {
V_120 -> V_302 = V_4 -> V_303 ;
V_120 -> V_131 |= F_86 ( V_301 ) ;
}
V_120 -> V_304 = V_4 -> V_305 ;
V_120 -> V_306 = V_4 -> V_306 ;
if ( V_13 -> V_19 . type == V_276 &&
! ( V_13 -> V_19 . V_307 & V_308 ) ) {
V_120 -> V_131 |= F_86 ( V_309 ) |
F_86 ( V_310 ) ;
V_120 -> V_311 = F_190 ( & V_13 -> V_19 ) ;
}
if ( ( V_4 -> V_2 -> V_31 . V_56 & V_312 ) ||
( V_4 -> V_2 -> V_31 . V_56 & V_313 ) ) {
if ( ! ( V_120 -> V_131 & F_86 ( V_314 ) ) ) {
V_120 -> signal = ( V_315 ) V_4 -> V_316 ;
V_120 -> V_131 |= F_86 ( V_314 ) ;
}
if ( ! ( V_120 -> V_131 & F_86 ( V_317 ) ) ) {
V_120 -> V_318 = ( V_315 ) - F_191 ( & V_4 -> V_82 ) ;
V_120 -> V_131 |= F_86 ( V_317 ) ;
}
}
if ( V_4 -> V_319 &&
! ( V_120 -> V_131 & ( F_86 ( V_320 ) |
F_86 ( V_321 ) ) ) ) {
V_120 -> V_131 |= F_86 ( V_320 ) |
F_86 ( V_321 ) ;
V_120 -> V_319 = V_4 -> V_319 ;
for ( V_9 = 0 ; V_9 < F_8 ( V_120 -> V_322 ) ; V_9 ++ ) {
V_120 -> V_322 [ V_9 ] = V_4 -> V_323 [ V_9 ] ;
V_120 -> V_83 [ V_9 ] =
( V_315 ) - F_191 ( & V_4 -> V_83 [ V_9 ] ) ;
}
}
if ( ! ( V_120 -> V_131 & F_86 ( V_324 ) ) ) {
F_192 ( V_4 , & V_4 -> V_325 , & V_120 -> V_326 ) ;
V_120 -> V_131 |= F_86 ( V_324 ) ;
}
if ( ! ( V_120 -> V_131 & F_86 ( V_327 ) ) ) {
F_193 ( V_4 , & V_120 -> V_328 ) ;
V_120 -> V_131 |= F_86 ( V_327 ) ;
}
V_120 -> V_131 |= F_86 ( V_329 ) ;
for ( V_9 = 0 ; V_9 < V_38 + 1 ; V_9 ++ ) {
struct V_330 * V_331 = & V_120 -> V_332 [ V_9 ] ;
if ( ! ( V_331 -> V_131 & F_86 ( V_333 ) ) ) {
V_331 -> V_131 |= F_86 ( V_333 ) ;
V_331 -> V_334 = V_4 -> V_334 [ V_9 ] ;
}
if ( ! ( V_331 -> V_131 & F_86 ( V_335 ) ) ) {
V_331 -> V_131 |= F_86 ( V_335 ) ;
V_331 -> V_336 = V_4 -> V_336 [ V_9 ] ;
}
if ( ! ( V_331 -> V_131 &
F_86 ( V_337 ) ) &&
V_2 -> V_31 . V_56 & V_338 ) {
V_331 -> V_131 |=
F_86 ( V_337 ) ;
V_331 -> V_339 = V_4 -> V_339 [ V_9 ] ;
}
if ( ! ( V_331 -> V_131 &
F_86 ( V_340 ) ) &&
V_2 -> V_31 . V_56 & V_338 ) {
V_331 -> V_131 |=
F_86 ( V_340 ) ;
V_331 -> V_341 = V_4 -> V_341 [ V_9 ] ;
}
}
if ( F_5 ( & V_13 -> V_19 ) ) {
#ifdef F_46
V_120 -> V_131 |= F_86 ( V_342 ) |
F_86 ( V_343 ) |
F_86 ( V_344 ) |
F_86 ( V_345 ) |
F_86 ( V_346 ) |
F_86 ( V_347 ) ;
V_120 -> V_348 = V_4 -> V_348 ;
V_120 -> V_147 = V_4 -> V_147 ;
V_120 -> V_349 = V_4 -> V_349 ;
if ( F_4 ( V_4 , V_350 ) ) {
V_120 -> V_131 |= F_86 ( V_351 ) ;
V_120 -> V_352 = V_4 -> V_352 ;
}
V_120 -> V_353 = V_4 -> V_353 ;
V_120 -> V_354 = V_4 -> V_354 ;
V_120 -> V_71 = V_4 -> V_71 ;
#endif
}
V_120 -> V_355 . V_56 = 0 ;
if ( V_13 -> V_19 . V_164 . V_356 )
V_120 -> V_355 . V_56 |= V_357 ;
if ( V_13 -> V_19 . V_164 . V_358 )
V_120 -> V_355 . V_56 |= V_359 ;
if ( V_13 -> V_19 . V_164 . V_360 )
V_120 -> V_355 . V_56 |= V_361 ;
V_120 -> V_355 . V_362 = V_13 -> V_19 . V_164 . V_362 ;
V_120 -> V_355 . V_363 = V_13 -> V_19 . V_164 . V_165 ;
V_120 -> V_364 . V_365 = 0 ;
V_120 -> V_364 . V_366 = F_86 ( V_367 ) |
F_86 ( V_368 ) |
F_86 ( V_369 ) |
F_86 ( V_370 ) |
F_86 ( V_371 ) |
F_86 ( V_372 ) |
F_86 ( V_373 ) ;
if ( F_4 ( V_4 , V_257 ) )
V_120 -> V_364 . V_365 |= F_86 ( V_367 ) ;
if ( F_4 ( V_4 , V_374 ) )
V_120 -> V_364 . V_365 |= F_86 ( V_368 ) ;
if ( V_4 -> V_4 . V_206 )
V_120 -> V_364 . V_365 |= F_86 ( V_369 ) ;
if ( F_4 ( V_4 , V_375 ) )
V_120 -> V_364 . V_365 |= F_86 ( V_370 ) ;
if ( F_4 ( V_4 , V_253 ) )
V_120 -> V_364 . V_365 |= F_86 ( V_371 ) ;
if ( F_4 ( V_4 , V_255 ) )
V_120 -> V_364 . V_365 |= F_86 ( V_372 ) ;
if ( F_4 ( V_4 , V_376 ) )
V_120 -> V_364 . V_365 |= F_86 ( V_373 ) ;
if ( V_273 && V_273 -> V_84 -> V_377 )
V_274 = V_273 -> V_84 -> V_377 ( V_4 -> V_58 ) ;
else
V_274 = F_194 ( V_2 , & V_4 -> V_4 ) ;
if ( V_274 != 0 ) {
V_120 -> V_131 |= F_86 ( V_378 ) ;
V_120 -> V_379 = V_274 ;
}
}
