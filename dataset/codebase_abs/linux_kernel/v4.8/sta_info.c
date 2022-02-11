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
struct V_14 * V_14 = & V_2 -> V_14 ;
struct V_15 * V_16 ;
if ( F_4 ( V_4 , V_17 ) ||
F_4 ( V_4 , V_18 ) ||
F_4 ( V_4 , V_19 ) ) {
if ( V_4 -> V_13 -> V_20 . type == V_21 ||
V_4 -> V_13 -> V_20 . type == V_22 )
V_16 = & V_13 -> V_23 -> V_16 ;
else if ( F_5 ( & V_13 -> V_20 ) )
V_16 = & V_13 -> V_24 . V_25 . V_16 ;
else
return;
F_6 ( V_4 , V_17 ) ;
F_6 ( V_4 , V_18 ) ;
F_6 ( V_4 , V_19 ) ;
F_7 ( & V_16 -> V_26 ) ;
}
if ( V_4 -> V_4 . V_27 [ 0 ] ) {
for ( V_9 = 0 ; V_9 < F_8 ( V_4 -> V_4 . V_27 ) ; V_9 ++ ) {
struct V_28 * V_29 = F_9 ( V_4 -> V_4 . V_27 [ V_9 ] ) ;
F_10 ( & V_14 -> V_30 ) ;
F_11 ( V_2 , V_29 ) ;
F_12 ( & V_14 -> V_30 ) ;
}
}
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ ) {
V_2 -> V_32 -= F_13 ( & V_4 -> V_33 [ V_8 ] ) ;
F_14 ( & V_2 -> V_34 , & V_4 -> V_33 [ V_8 ] ) ;
F_14 ( & V_2 -> V_34 , & V_4 -> V_35 [ V_8 ] ) ;
}
if ( F_5 ( & V_13 -> V_20 ) )
F_15 ( V_4 ) ;
F_16 ( & V_4 -> V_36 ) ;
for ( V_9 = 0 ; V_9 < V_37 ; V_9 ++ ) {
F_17 ( V_4 -> V_38 . V_39 [ V_9 ] ) ;
V_11 = F_18 ( V_4 -> V_38 . V_11 [ V_9 ] ) ;
if ( ! V_11 )
continue;
F_14 ( & V_2 -> V_34 , & V_11 -> V_40 ) ;
F_17 ( V_11 ) ;
}
}
static void F_19 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
F_3 ( V_4 ) ;
F_20 ( V_2 , V_4 ) ;
}
struct V_3 * F_21 ( struct V_12 * V_13 ,
const T_1 * V_41 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 ;
struct V_42 * V_43 ;
const struct V_44 * V_45 ;
F_22 () ;
V_45 = F_23 ( V_2 -> V_5 . V_45 , & V_2 -> V_5 ) ;
F_24 (local, tbl, addr, sta, tmp) {
if ( V_4 -> V_13 == V_13 ) {
F_25 () ;
return V_4 ;
}
}
F_25 () ;
return NULL ;
}
struct V_3 * F_26 ( struct V_12 * V_13 ,
const T_1 * V_41 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 ;
struct V_42 * V_43 ;
const struct V_44 * V_45 ;
F_22 () ;
V_45 = F_23 ( V_2 -> V_5 . V_45 , & V_2 -> V_5 ) ;
F_24 (local, tbl, addr, sta, tmp) {
if ( V_4 -> V_13 == V_13 ||
( V_4 -> V_13 -> V_23 && V_4 -> V_13 -> V_23 == V_13 -> V_23 ) ) {
F_25 () ;
return V_4 ;
}
}
F_25 () ;
return NULL ;
}
struct V_3 * F_27 ( struct V_12 * V_13 ,
int V_46 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 ;
int V_9 = 0 ;
F_28 (sta, &local->sta_list, list) {
if ( V_13 != V_4 -> V_13 )
continue;
if ( V_9 < V_46 ) {
++ V_9 ;
continue;
}
return V_4 ;
}
return NULL ;
}
void F_20 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_47 )
F_29 ( V_4 ) ;
F_30 ( V_4 -> V_13 , L_1 , V_4 -> V_4 . V_41 ) ;
if ( V_4 -> V_4 . V_27 [ 0 ] )
F_17 ( F_9 ( V_4 -> V_4 . V_27 [ 0 ] ) ) ;
F_17 ( F_18 ( V_4 -> V_4 . V_48 ) ) ;
#ifdef F_31
F_17 ( V_4 -> V_25 ) ;
#endif
F_32 ( V_4 -> V_49 ) ;
F_17 ( V_4 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return F_34 ( & V_2 -> V_5 , & V_4 -> V_6 ,
V_7 ) ;
}
static void F_35 ( struct V_50 * V_51 )
{
struct V_3 * V_4 ;
V_4 = F_36 ( V_51 , struct V_3 , V_36 ) ;
if ( V_4 -> V_52 )
return;
F_37 () ;
if ( ! F_4 ( V_4 , V_17 ) )
F_38 ( V_4 ) ;
else if ( F_39 ( V_4 , V_53 ) )
F_40 ( V_4 ) ;
else if ( F_39 ( V_4 , V_54 ) )
F_41 ( V_4 ) ;
F_42 () ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 V_55 )
{
if ( F_44 ( & V_2 -> V_34 , V_56 ) )
return 0 ;
V_4 -> V_47 = V_2 -> V_47 ;
V_4 -> V_57 = F_45 ( V_4 -> V_47 ,
V_4 , V_55 ) ;
if ( ! V_4 -> V_57 )
return - V_58 ;
return 0 ;
}
struct V_3 * F_46 ( struct V_12 * V_13 ,
const T_1 * V_41 , T_2 V_55 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_59 * V_34 = & V_2 -> V_34 ;
struct V_3 * V_4 ;
int V_9 ;
V_4 = F_47 ( sizeof( * V_4 ) + V_34 -> V_60 , V_55 ) ;
if ( ! V_4 )
return NULL ;
if ( F_44 ( V_34 , V_61 ) ) {
V_4 -> V_49 =
F_48 ( struct V_62 ) ;
if ( ! V_4 -> V_49 )
goto free;
}
F_49 ( & V_4 -> V_30 ) ;
F_49 ( & V_4 -> V_63 ) ;
F_50 ( & V_4 -> V_36 , F_35 ) ;
F_50 ( & V_4 -> V_38 . V_64 , V_65 ) ;
F_51 ( & V_4 -> V_38 . V_66 ) ;
#ifdef F_31
if ( F_5 ( & V_13 -> V_20 ) ) {
V_4 -> V_25 = F_47 ( sizeof( * V_4 -> V_25 ) , V_55 ) ;
if ( ! V_4 -> V_25 )
goto free;
F_49 ( & V_4 -> V_25 -> V_67 ) ;
if ( F_5 ( & V_13 -> V_20 ) &&
! V_13 -> V_24 . V_25 . V_68 )
F_52 ( & V_4 -> V_25 -> V_69 ) ;
V_4 -> V_25 -> V_70 = V_71 ;
}
#endif
memcpy ( V_4 -> V_41 , V_41 , V_72 ) ;
memcpy ( V_4 -> V_4 . V_41 , V_41 , V_72 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_13 = V_13 ;
V_4 -> V_73 . V_74 = V_75 ;
F_53 ( & V_4 -> V_73 . V_76 ) ;
V_4 -> V_77 = V_78 ;
V_4 -> V_79 = V_80 ;
V_4 -> V_81 = F_54 () ;
F_55 ( & V_4 -> V_82 . signal ) ;
for ( V_9 = 0 ; V_9 < F_8 ( V_4 -> V_82 . V_83 ) ; V_9 ++ )
F_55 ( & V_4 -> V_82 . V_83 [ V_9 ] ) ;
if ( V_2 -> V_84 -> V_85 ) {
void * V_86 ;
int V_87 = sizeof( struct V_28 ) +
F_56 ( V_34 -> V_88 , sizeof( void * ) ) ;
V_86 = F_57 ( F_8 ( V_4 -> V_4 . V_27 ) , V_87 , V_55 ) ;
if ( ! V_86 )
goto free;
for ( V_9 = 0 ; V_9 < F_8 ( V_4 -> V_4 . V_27 ) ; V_9 ++ ) {
struct V_28 * V_27 = V_86 + V_9 * V_87 ;
F_58 ( V_13 , V_4 , V_27 , V_9 ) ;
}
}
if ( F_43 ( V_2 , V_4 , V_55 ) )
goto V_89;
for ( V_9 = 0 ; V_9 < V_37 ; V_9 ++ ) {
V_4 -> V_90 [ V_9 ] = V_9 ;
}
for ( V_9 = 0 ; V_9 < V_31 ; V_9 ++ ) {
F_59 ( & V_4 -> V_33 [ V_9 ] ) ;
F_59 ( & V_4 -> V_35 [ V_9 ] ) ;
}
for ( V_9 = 0 ; V_9 < V_37 ; V_9 ++ )
V_4 -> V_91 [ V_9 ] = F_60 ( V_92 ) ;
V_4 -> V_4 . V_93 = V_94 ;
if ( V_13 -> V_20 . type == V_21 ||
V_13 -> V_20 . type == V_22 ) {
struct V_95 * V_96 =
V_34 -> V_97 -> V_98 [ F_61 ( V_13 ) ] ;
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
F_62 ( 1 ) ;
}
}
V_4 -> V_4 . V_110 = V_111 ;
F_30 ( V_13 , L_2 , V_4 -> V_4 . V_41 ) ;
return V_4 ;
V_89:
if ( V_4 -> V_4 . V_27 [ 0 ] )
F_17 ( F_9 ( V_4 -> V_4 . V_27 [ 0 ] ) ) ;
free:
#ifdef F_31
F_17 ( V_4 -> V_25 ) ;
#endif
F_17 ( V_4 ) ;
return NULL ;
}
static int F_63 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
if ( F_64 ( ! F_65 ( V_13 ) ) )
return - V_112 ;
if ( F_62 ( F_66 ( V_4 -> V_4 . V_41 , V_13 -> V_20 . V_41 ) ||
F_67 ( V_4 -> V_4 . V_41 ) ) )
return - V_113 ;
F_22 () ;
F_68 ( & V_13 -> V_2 -> V_114 ) ;
if ( F_44 ( & V_13 -> V_2 -> V_34 , V_115 ) &&
F_69 ( & V_13 -> V_2 -> V_34 , V_4 -> V_41 , NULL ) ) {
F_25 () ;
return - V_116 ;
}
F_25 () ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_3 * V_4 )
{
enum V_117 V_118 ;
int V_119 = 0 ;
for ( V_118 = V_120 ; V_118 < V_4 -> V_77 ; V_118 ++ ) {
V_119 = F_71 ( V_2 , V_13 , V_4 , V_118 , V_118 + 1 ) ;
if ( V_119 )
break;
}
if ( ! V_119 ) {
if ( ! V_2 -> V_84 -> V_121 )
V_4 -> V_122 = true ;
return 0 ;
}
if ( V_13 -> V_20 . type == V_123 ) {
F_72 ( V_13 ,
L_3 ,
V_4 -> V_4 . V_41 , V_118 + 1 , V_119 ) ;
V_119 = 0 ;
}
for (; V_118 > V_120 ; V_118 -- )
F_62 ( F_71 ( V_2 , V_13 , V_4 , V_118 , V_118 - 1 ) ) ;
return V_119 ;
}
static int F_73 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_124 * V_125 ;
int V_119 = 0 ;
F_68 ( & V_2 -> V_114 ) ;
V_125 = F_47 ( sizeof( struct V_124 ) , V_126 ) ;
if ( ! V_125 ) {
V_119 = - V_58 ;
goto V_127;
}
if ( F_26 ( V_13 , V_4 -> V_4 . V_41 ) ) {
V_119 = - V_128 ;
goto V_127;
}
V_2 -> V_129 ++ ;
V_2 -> V_130 ++ ;
F_74 () ;
F_75 ( V_4 , V_131 ) ;
V_119 = F_33 ( V_2 , V_4 ) ;
if ( V_119 )
goto V_132;
F_76 ( & V_4 -> V_133 , & V_2 -> V_134 ) ;
V_119 = F_70 ( V_2 , V_13 , V_4 ) ;
if ( V_119 )
goto V_135;
F_75 ( V_4 , V_136 ) ;
F_6 ( V_4 , V_131 ) ;
F_77 ( V_4 ) ;
F_78 ( V_4 ) ;
V_125 -> V_137 = V_2 -> V_130 ;
F_79 ( V_13 -> V_138 , V_4 -> V_4 . V_41 , V_125 , V_126 ) ;
F_17 ( V_125 ) ;
F_30 ( V_13 , L_4 , V_4 -> V_4 . V_41 ) ;
F_22 () ;
F_80 ( & V_2 -> V_114 ) ;
if ( F_5 ( & V_13 -> V_20 ) )
F_81 ( V_13 ) ;
return 0 ;
V_135:
F_1 ( V_2 , V_4 ) ;
F_82 ( & V_4 -> V_133 ) ;
V_132:
V_2 -> V_129 -- ;
F_83 () ;
F_3 ( V_4 ) ;
V_127:
F_80 ( & V_2 -> V_114 ) ;
F_17 ( V_125 ) ;
F_22 () ;
return V_119 ;
}
int F_84 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_119 ;
F_85 () ;
F_86 ( & V_2 -> V_114 ) ;
V_119 = F_63 ( V_4 ) ;
if ( V_119 ) {
F_80 ( & V_2 -> V_114 ) ;
F_22 () ;
goto V_139;
}
V_119 = F_73 ( V_4 ) ;
if ( V_119 )
goto V_139;
return 0 ;
V_139:
F_20 ( V_2 , V_4 ) ;
return V_119 ;
}
int F_87 ( struct V_3 * V_4 )
{
int V_119 = F_84 ( V_4 ) ;
F_25 () ;
return V_119 ;
}
static inline void F_88 ( T_1 * V_140 , T_4 V_141 )
{
V_140 [ V_141 / 8 ] |= ( 1 << ( V_141 % 8 ) ) ;
}
static inline void F_89 ( T_1 * V_140 , T_4 V_141 )
{
V_140 [ V_141 / 8 ] &= ~ ( 1 << ( V_141 % 8 ) ) ;
}
static inline bool F_90 ( T_1 * V_140 , T_4 V_141 )
{
return V_140 [ V_141 / 8 ] & ( 1 << ( V_141 % 8 ) ) ;
}
static unsigned long F_91 ( int V_8 )
{
switch ( V_8 ) {
case V_142 :
return F_92 ( 6 ) | F_92 ( 7 ) ;
case V_143 :
return F_92 ( 4 ) | F_92 ( 5 ) ;
case V_144 :
return F_92 ( 0 ) | F_92 ( 3 ) ;
case V_145 :
return F_92 ( 1 ) | F_92 ( 2 ) ;
default:
F_62 ( 1 ) ;
return 0 ;
}
}
static void F_93 ( struct V_3 * V_4 , bool V_146 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_15 * V_16 ;
bool V_147 = false ;
T_1 V_148 = V_4 -> V_4 . V_149 ;
int V_8 ;
T_4 V_141 = V_4 -> V_4 . V_150 ;
if ( V_4 -> V_13 -> V_20 . type == V_21 ||
V_4 -> V_13 -> V_20 . type == V_22 ) {
if ( F_94 ( ! V_4 -> V_13 -> V_23 ) )
return;
V_16 = & V_4 -> V_13 -> V_23 -> V_16 ;
#ifdef F_31
} else if ( F_5 ( & V_4 -> V_13 -> V_20 ) ) {
V_16 = & V_4 -> V_13 -> V_24 . V_25 . V_16 ;
#endif
} else {
return;
}
if ( F_44 ( & V_2 -> V_34 , V_151 ) )
return;
if ( V_4 -> V_52 )
goto V_152;
if ( V_148 == F_92 ( V_31 ) - 1 )
V_148 = 0 ;
if ( V_146 )
V_148 = F_92 ( V_31 ) - 1 ;
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ ) {
unsigned long V_153 ;
if ( V_148 & F_92 ( V_8 ) )
continue;
V_147 |= ! F_95 ( & V_4 -> V_35 [ V_8 ] ) ||
! F_95 ( & V_4 -> V_33 [ V_8 ] ) ;
if ( V_147 )
break;
V_153 = F_91 ( V_8 ) ;
V_147 |=
V_4 -> V_154 & V_153 ;
V_147 |=
V_4 -> V_155 & V_153 ;
}
V_152:
F_10 ( & V_2 -> V_156 ) ;
if ( V_147 == F_90 ( V_16 -> V_140 , V_141 ) )
goto V_157;
if ( V_147 )
F_88 ( V_16 -> V_140 , V_141 ) ;
else
F_89 ( V_16 -> V_140 , V_141 ) ;
if ( V_2 -> V_84 -> V_158 && ! F_62 ( V_4 -> V_52 ) ) {
V_2 -> V_159 = true ;
F_96 ( V_2 , & V_4 -> V_4 , V_147 ) ;
V_2 -> V_159 = false ;
}
V_157:
F_12 ( & V_2 -> V_156 ) ;
}
void F_97 ( struct V_3 * V_4 )
{
F_93 ( V_4 , false ) ;
}
static bool F_98 ( struct V_3 * V_4 , struct V_160 * V_161 )
{
struct V_162 * V_163 ;
int V_164 ;
if ( ! V_161 )
return false ;
V_163 = F_99 ( V_161 ) ;
V_164 = ( V_4 -> V_165 *
V_4 -> V_13 -> V_20 . V_166 . V_167 *
32 / 15625 ) * V_168 ;
if ( V_164 < V_169 )
V_164 = V_169 ;
return F_100 ( V_75 , V_163 -> V_170 . V_75 + V_164 ) ;
}
static bool F_101 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_8 )
{
unsigned long V_171 ;
struct V_160 * V_161 ;
for (; ; ) {
F_102 ( & V_4 -> V_35 [ V_8 ] . V_30 , V_171 ) ;
V_161 = F_103 ( & V_4 -> V_35 [ V_8 ] ) ;
if ( F_98 ( V_4 , V_161 ) )
V_161 = F_104 ( & V_4 -> V_35 [ V_8 ] ) ;
else
V_161 = NULL ;
F_105 ( & V_4 -> V_35 [ V_8 ] . V_30 , V_171 ) ;
if ( ! V_161 )
break;
F_106 ( & V_2 -> V_34 , V_161 ) ;
}
for (; ; ) {
F_102 ( & V_4 -> V_33 [ V_8 ] . V_30 , V_171 ) ;
V_161 = F_103 ( & V_4 -> V_33 [ V_8 ] ) ;
if ( F_98 ( V_4 , V_161 ) )
V_161 = F_104 ( & V_4 -> V_33 [ V_8 ] ) ;
else
V_161 = NULL ;
F_105 ( & V_4 -> V_33 [ V_8 ] . V_30 , V_171 ) ;
if ( ! V_161 )
break;
V_2 -> V_32 -- ;
F_107 ( V_4 -> V_13 , L_5 ,
V_4 -> V_4 . V_41 ) ;
F_106 ( & V_2 -> V_34 , V_161 ) ;
}
F_97 ( V_4 ) ;
return ! ( F_95 ( & V_4 -> V_33 [ V_8 ] ) &&
F_95 ( & V_4 -> V_35 [ V_8 ] ) ) ;
}
static bool F_108 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_172 = false ;
int V_8 ;
if ( ! V_4 -> V_13 -> V_23 &&
! F_5 ( & V_4 -> V_13 -> V_20 ) )
return false ;
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ )
V_172 |=
F_101 ( V_2 , V_4 , V_8 ) ;
return V_172 ;
}
static int T_5 F_109 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
int V_173 ;
F_85 () ;
if ( ! V_4 )
return - V_174 ;
V_2 = V_4 -> V_2 ;
V_13 = V_4 -> V_13 ;
F_68 ( & V_2 -> V_114 ) ;
F_75 ( V_4 , V_131 ) ;
F_110 ( V_4 , V_175 ) ;
F_111 ( V_2 , V_4 ) ;
V_173 = F_1 ( V_2 , V_4 ) ;
if ( F_62 ( V_173 ) )
return V_173 ;
if ( F_4 ( V_4 , V_176 ) ) {
F_112 ( V_2 , V_13 , & V_4 -> V_4 ) ;
F_6 ( V_4 , V_176 ) ;
}
F_82 ( & V_4 -> V_133 ) ;
V_4 -> V_177 = true ;
F_113 ( V_2 , V_4 -> V_13 , V_4 ) ;
if ( V_13 -> V_20 . type == V_22 &&
F_114 ( V_13 -> V_24 . V_178 . V_4 ) == V_4 )
F_115 ( V_13 -> V_24 . V_178 . V_4 , NULL ) ;
return 0 ;
}
static void F_116 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_124 * V_125 ;
int V_173 ;
F_85 () ;
F_68 ( & V_2 -> V_114 ) ;
F_117 ( V_2 , V_4 ) ;
F_93 ( V_4 , true ) ;
V_4 -> V_52 = true ;
V_2 -> V_129 -- ;
V_2 -> V_130 ++ ;
while ( V_4 -> V_77 > V_78 ) {
V_173 = F_118 ( V_4 , V_4 -> V_77 - 1 ) ;
if ( V_173 ) {
F_94 ( 1 ) ;
break;
}
}
if ( V_4 -> V_122 ) {
V_173 = F_71 ( V_2 , V_13 , V_4 , V_78 ,
V_120 ) ;
F_94 ( V_173 != 0 ) ;
}
F_30 ( V_13 , L_6 , V_4 -> V_4 . V_41 ) ;
V_125 = F_47 ( sizeof( * V_125 ) , V_126 ) ;
if ( V_125 )
F_119 ( V_4 , V_125 ) ;
F_120 ( V_13 -> V_138 , V_4 -> V_4 . V_41 , V_125 , V_126 ) ;
F_17 ( V_125 ) ;
F_121 ( V_4 ) ;
F_122 ( V_4 ) ;
F_19 ( V_4 ) ;
}
int T_5 F_123 ( struct V_3 * V_4 )
{
int V_119 = F_109 ( V_4 ) ;
if ( V_119 )
return V_119 ;
F_83 () ;
F_116 ( V_4 ) ;
return 0 ;
}
int F_124 ( struct V_12 * V_13 , const T_1 * V_41 )
{
struct V_3 * V_4 ;
int V_173 ;
F_86 ( & V_13 -> V_2 -> V_114 ) ;
V_4 = F_21 ( V_13 , V_41 ) ;
V_173 = F_123 ( V_4 ) ;
F_80 ( & V_13 -> V_2 -> V_114 ) ;
return V_173 ;
}
int F_125 ( struct V_12 * V_13 ,
const T_1 * V_41 )
{
struct V_3 * V_4 ;
int V_173 ;
F_86 ( & V_13 -> V_2 -> V_114 ) ;
V_4 = F_26 ( V_13 , V_41 ) ;
V_173 = F_123 ( V_4 ) ;
F_80 ( & V_13 -> V_2 -> V_114 ) ;
return V_173 ;
}
static void F_126 ( unsigned long V_179 )
{
struct V_1 * V_2 = (struct V_1 * ) V_179 ;
struct V_3 * V_4 ;
bool V_180 = false ;
F_22 () ;
F_28 (sta, &local->sta_list, list)
if ( F_108 ( V_2 , V_4 ) )
V_180 = true ;
F_25 () ;
if ( V_2 -> V_181 )
return;
if ( ! V_180 )
return;
F_127 ( & V_2 -> V_182 ,
F_128 ( V_75 + V_183 ) ) ;
}
T_6 F_129 ( const void * V_184 , T_6 V_185 , T_6 V_186 )
{
return F_130 ( V_184 , V_72 , V_186 ) ;
}
int F_131 ( struct V_1 * V_2 )
{
int V_119 ;
V_119 = F_132 ( & V_2 -> V_5 , & V_7 ) ;
if ( V_119 )
return V_119 ;
F_49 ( & V_2 -> V_156 ) ;
F_51 ( & V_2 -> V_114 ) ;
F_133 ( & V_2 -> V_134 ) ;
F_134 ( & V_2 -> V_182 , F_126 ,
( unsigned long ) V_2 ) ;
return 0 ;
}
void F_135 ( struct V_1 * V_2 )
{
F_136 ( & V_2 -> V_182 ) ;
F_137 ( & V_2 -> V_5 ) ;
}
int F_138 ( struct V_12 * V_13 , bool V_187 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 , * V_43 ;
F_139 ( V_188 ) ;
int V_173 = 0 ;
F_85 () ;
F_62 ( V_187 && V_13 -> V_20 . type != V_21 ) ;
F_62 ( V_187 && ! V_13 -> V_23 ) ;
F_86 ( & V_2 -> V_114 ) ;
F_140 (sta, tmp, &local->sta_list, list) {
if ( V_13 == V_4 -> V_13 ||
( V_187 && V_13 -> V_23 == V_4 -> V_13 -> V_23 ) ) {
if ( ! F_62 ( F_109 ( V_4 ) ) )
F_141 ( & V_4 -> V_188 , & V_188 ) ;
V_173 ++ ;
}
}
if ( ! F_142 ( & V_188 ) ) {
F_83 () ;
F_140 (sta, tmp, &free_list, free_list)
F_116 ( V_4 ) ;
}
F_80 ( & V_2 -> V_114 ) ;
return V_173 ;
}
void F_143 ( struct V_12 * V_13 ,
unsigned long V_189 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 , * V_43 ;
F_86 ( & V_2 -> V_114 ) ;
F_140 (sta, tmp, &local->sta_list, list) {
unsigned long V_190 = F_144 ( V_4 ) ;
if ( V_13 != V_4 -> V_13 )
continue;
if ( F_145 ( V_190 + V_189 ) ) {
F_30 ( V_4 -> V_13 , L_7 ,
V_4 -> V_4 . V_41 ) ;
if ( F_5 ( & V_13 -> V_20 ) &&
F_4 ( V_4 , V_17 ) )
F_7 ( & V_13 -> V_24 . V_25 . V_16 . V_26 ) ;
F_62 ( F_123 ( V_4 ) ) ;
}
}
F_80 ( & V_2 -> V_114 ) ;
}
struct V_191 * F_69 ( struct V_59 * V_34 ,
const T_1 * V_41 ,
const T_1 * V_192 )
{
struct V_1 * V_2 = F_146 ( V_34 ) ;
struct V_3 * V_4 ;
struct V_42 * V_43 ;
const struct V_44 * V_45 ;
V_45 = F_23 ( V_2 -> V_5 . V_45 , & V_2 -> V_5 ) ;
F_24 (local, tbl, addr, sta, tmp) {
if ( V_192 &&
! F_66 ( V_4 -> V_13 -> V_20 . V_41 , V_192 ) )
continue;
if ( ! V_4 -> V_122 )
return NULL ;
return & V_4 -> V_4 ;
}
return NULL ;
}
struct V_191 * F_147 ( struct V_193 * V_20 ,
const T_1 * V_41 )
{
struct V_3 * V_4 ;
if ( ! V_20 )
return NULL ;
V_4 = F_26 ( F_148 ( V_20 ) , V_41 ) ;
if ( ! V_4 )
return NULL ;
if ( ! V_4 -> V_122 )
return NULL ;
return & V_4 -> V_4 ;
}
void F_38 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_194 V_40 ;
int V_195 = 0 , V_196 = 0 , V_8 , V_9 ;
unsigned long V_171 ;
struct V_15 * V_16 ;
if ( V_13 -> V_20 . type == V_22 )
V_13 = F_36 ( V_13 -> V_23 , struct V_12 ,
V_24 . V_197 ) ;
if ( V_13 -> V_20 . type == V_21 )
V_16 = & V_13 -> V_23 -> V_16 ;
else if ( F_5 ( & V_13 -> V_20 ) )
V_16 = & V_13 -> V_24 . V_25 . V_16 ;
else
return;
F_6 ( V_4 , V_198 ) ;
F_149 ( F_150 ( V_37 ) > 1 ) ;
V_4 -> V_154 = 0 ;
V_4 -> V_155 = 0 ;
if ( ! F_44 ( & V_2 -> V_34 , V_151 ) )
F_151 ( V_2 , V_13 , V_199 , & V_4 -> V_4 ) ;
if ( V_4 -> V_4 . V_27 [ 0 ] ) {
for ( V_9 = 0 ; V_9 < F_8 ( V_4 -> V_4 . V_27 ) ; V_9 ++ ) {
struct V_28 * V_29 = F_9 ( V_4 -> V_4 . V_27 [ V_9 ] ) ;
if ( ! V_29 -> V_200 . V_201 )
continue;
F_152 ( V_2 , V_29 ) ;
}
}
F_59 ( & V_40 ) ;
F_153 ( & V_4 -> V_63 ) ;
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ ) {
int V_202 = F_13 ( & V_40 ) , V_43 ;
F_102 ( & V_4 -> V_35 [ V_8 ] . V_30 , V_171 ) ;
F_154 ( & V_4 -> V_35 [ V_8 ] , & V_40 ) ;
F_105 ( & V_4 -> V_35 [ V_8 ] . V_30 , V_171 ) ;
V_43 = F_13 ( & V_40 ) ;
V_195 += V_43 - V_202 ;
V_202 = V_43 ;
F_102 ( & V_4 -> V_33 [ V_8 ] . V_30 , V_171 ) ;
F_154 ( & V_4 -> V_33 [ V_8 ] , & V_40 ) ;
F_105 ( & V_4 -> V_33 [ V_8 ] . V_30 , V_171 ) ;
V_43 = F_13 ( & V_40 ) ;
V_196 += V_43 - V_202 ;
}
F_155 ( V_2 , & V_40 ) ;
F_6 ( V_4 , V_19 ) ;
F_6 ( V_4 , V_53 ) ;
F_6 ( V_4 , V_54 ) ;
F_156 ( & V_4 -> V_63 ) ;
F_7 ( & V_16 -> V_26 ) ;
if ( ! F_5 ( & V_13 -> V_20 ) &&
! F_157 ( V_4 -> V_105 ,
V_13 -> V_93 ) &&
V_4 -> V_105 != V_13 -> V_23 -> V_203 &&
F_158 ( V_4 ) != 1 ) {
F_159 ( V_13 ,
L_8 ,
V_4 -> V_4 . V_41 ) ;
F_160 ( V_13 , V_13 -> V_23 -> V_203 ,
V_4 -> V_4 . V_41 ,
V_13 -> V_20 . V_166 . V_204 ) ;
}
V_2 -> V_32 -= V_196 ;
F_97 ( V_4 ) ;
F_107 ( V_13 ,
L_9 ,
V_4 -> V_4 . V_41 , V_4 -> V_4 . V_150 , V_195 , V_196 ) ;
F_161 ( V_4 ) ;
}
static void F_162 ( struct V_3 * V_4 , int V_205 ,
enum V_206 V_207 ,
bool V_208 , bool V_209 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_210 * V_211 ;
struct V_160 * V_161 ;
int V_87 = sizeof( * V_211 ) ;
T_7 V_212 ;
bool V_213 = V_4 -> V_4 . V_214 ;
struct V_162 * V_163 ;
struct V_215 * V_216 ;
if ( V_213 ) {
V_212 = F_60 ( V_217 |
V_218 |
V_219 ) ;
} else {
V_87 -= 2 ;
V_212 = F_60 ( V_217 |
V_220 |
V_219 ) ;
}
V_161 = F_163 ( V_2 -> V_34 . V_221 + V_87 ) ;
if ( ! V_161 )
return;
F_164 ( V_161 , V_2 -> V_34 . V_221 ) ;
V_211 = ( void * ) F_165 ( V_161 , V_87 ) ;
V_211 -> V_222 = V_212 ;
V_211 -> V_223 = 0 ;
memcpy ( V_211 -> V_224 , V_4 -> V_4 . V_41 , V_72 ) ;
memcpy ( V_211 -> V_225 , V_13 -> V_20 . V_41 , V_72 ) ;
memcpy ( V_211 -> V_226 , V_13 -> V_20 . V_41 , V_72 ) ;
V_211 -> V_227 = 0 ;
V_161 -> V_228 = V_205 ;
F_166 ( V_161 , V_229 [ V_205 ] ) ;
if ( V_213 ) {
V_211 -> V_230 = F_60 ( V_205 ) ;
if ( V_207 == V_231 ) {
V_211 -> V_230 |=
F_60 ( V_232 ) ;
if ( V_209 )
V_211 -> V_222 |=
F_60 ( V_233 ) ;
}
}
V_163 = F_99 ( V_161 ) ;
V_163 -> V_171 |= V_234 |
V_235 |
V_236 ;
V_163 -> V_170 . V_171 |= V_237 ;
if ( V_208 )
F_167 ( V_2 , V_4 , F_92 ( V_205 ) , 1 ,
V_207 , false ) ;
V_161 -> V_138 = V_13 -> V_138 ;
F_22 () ;
V_216 = F_168 ( V_13 -> V_20 . V_216 ) ;
if ( F_62 ( ! V_216 ) ) {
F_25 () ;
F_169 ( V_161 ) ;
return;
}
V_163 -> V_238 = V_216 -> V_239 . V_240 -> V_238 ;
F_170 ( V_13 , V_4 , V_161 ) ;
F_25 () ;
}
static int F_171 ( unsigned long V_153 )
{
if ( V_153 & 0xF8 )
return F_172 ( V_153 ) - 1 ;
if ( V_153 & F_92 ( 0 ) )
return 0 ;
return F_172 ( V_153 ) - 1 ;
}
static bool
F_173 ( struct V_3 * V_4 , T_1 V_241 ,
enum V_206 V_207 ,
unsigned long V_242 )
{
int V_8 ;
if ( V_207 == V_243 &&
F_174 ( V_242 ) > 1 )
return true ;
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ ) {
if ( V_241 & F_92 ( V_8 ) )
continue;
if ( ! F_95 ( & V_4 -> V_35 [ V_8 ] ) ||
! F_95 ( & V_4 -> V_33 [ V_8 ] ) )
return true ;
}
return false ;
}
static void
F_175 ( struct V_3 * V_4 , int V_244 , T_1 V_241 ,
enum V_206 V_207 ,
struct V_194 * V_245 ,
unsigned long * V_242 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ ) {
unsigned long V_153 ;
if ( V_241 & F_92 ( V_8 ) )
continue;
V_153 = F_91 ( V_8 ) ;
if ( F_95 ( V_245 ) ) {
* V_242 |=
V_4 -> V_154 & V_153 ;
* V_242 |= V_4 -> V_155 & V_153 ;
}
if ( ! * V_242 ) {
struct V_160 * V_161 ;
while ( V_244 > 0 ) {
V_161 = F_176 ( & V_4 -> V_35 [ V_8 ] ) ;
if ( ! V_161 ) {
V_161 = F_176 (
& V_4 -> V_33 [ V_8 ] ) ;
if ( V_161 )
V_2 -> V_32 -- ;
}
if ( ! V_161 )
break;
V_244 -- ;
F_177 ( V_245 , V_161 ) ;
}
}
if ( ! F_95 ( & V_4 -> V_35 [ V_8 ] ) ||
! F_95 ( & V_4 -> V_33 [ V_8 ] ) )
break;
}
}
static void
F_178 ( struct V_3 * V_4 ,
int V_244 , T_1 V_241 ,
enum V_206 V_207 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
unsigned long V_242 = 0 ;
struct V_194 V_245 ;
bool V_209 ;
F_75 ( V_4 , V_198 ) ;
F_179 ( & V_245 ) ;
F_175 ( V_4 , V_244 , V_241 , V_207 ,
& V_245 , & V_242 ) ;
V_209 = F_173 ( V_4 , V_241 , V_207 , V_242 ) ;
if ( V_242 && V_207 == V_243 )
V_242 =
F_92 ( F_171 ( V_242 ) ) ;
if ( F_95 ( & V_245 ) && ! V_242 ) {
int V_205 ;
V_205 = 7 - ( ( F_180 ( ~ V_241 ) - 1 ) << 1 ) ;
F_162 ( V_4 , V_205 , V_207 , true , false ) ;
} else if ( ! V_242 ) {
struct V_194 V_40 ;
struct V_160 * V_161 ;
int V_246 = 0 ;
T_4 V_153 = 0 ;
bool V_247 = false ;
F_59 ( & V_40 ) ;
while ( ( V_161 = F_104 ( & V_245 ) ) ) {
struct V_162 * V_163 = F_99 ( V_161 ) ;
struct V_248 * V_249 = ( void * ) V_161 -> V_179 ;
T_1 * V_250 = NULL ;
V_246 ++ ;
V_163 -> V_171 |= V_234 ;
V_163 -> V_170 . V_171 |= V_237 ;
if ( V_209 || ! F_95 ( & V_245 ) )
V_249 -> V_222 |=
F_60 ( V_233 ) ;
else
V_249 -> V_222 &=
F_60 ( ~ V_233 ) ;
if ( F_181 ( V_249 -> V_222 ) ||
F_182 ( V_249 -> V_222 ) )
V_250 = F_183 ( V_249 ) ;
V_153 |= F_92 ( V_161 -> V_228 ) ;
F_177 ( & V_40 , V_161 ) ;
if ( ! F_95 ( & V_245 ) )
continue;
if ( V_207 != V_231 ) {
V_163 -> V_171 |= V_235 |
V_236 ;
break;
}
if ( V_250 ) {
* V_250 |= V_232 ;
V_163 -> V_171 |= V_235 |
V_236 ;
} else {
V_249 -> V_222 |=
F_60 ( V_233 ) ;
V_247 = true ;
V_246 ++ ;
}
break;
}
F_167 ( V_2 , V_4 , V_153 , V_246 ,
V_207 , V_209 ) ;
F_155 ( V_2 , & V_40 ) ;
if ( V_247 )
F_162 (
V_4 , F_171 ( V_153 ) ,
V_207 , false , false ) ;
F_97 ( V_4 ) ;
} else {
int V_205 ;
F_184 ( V_2 , V_4 , V_242 ,
V_244 , V_207 , V_209 ) ;
if ( ! V_4 -> V_4 . V_27 [ 0 ] )
return;
for ( V_205 = 0 ; V_205 < F_8 ( V_4 -> V_4 . V_27 ) ; V_205 ++ ) {
struct V_28 * V_29 = F_9 ( V_4 -> V_4 . V_27 [ V_205 ] ) ;
if ( ! ( V_242 & F_92 ( V_205 ) ) ||
V_29 -> V_200 . V_201 )
continue;
F_97 ( V_4 ) ;
break;
}
}
}
void F_40 ( struct V_3 * V_4 )
{
T_1 V_251 = V_4 -> V_4 . V_149 ;
if ( V_251 == F_92 ( V_31 ) - 1 )
V_251 = 0 ;
F_178 ( V_4 , 1 , V_251 ,
V_243 ) ;
}
void F_41 ( struct V_3 * V_4 )
{
int V_244 = V_4 -> V_4 . V_252 ;
T_1 V_253 = V_4 -> V_4 . V_149 ;
if ( ! V_253 )
return;
switch ( V_4 -> V_4 . V_252 ) {
case 1 :
V_244 = 2 ;
break;
case 2 :
V_244 = 4 ;
break;
case 3 :
V_244 = 6 ;
break;
case 0 :
V_244 = 128 ;
break;
}
F_178 ( V_4 , V_244 , ~ V_253 ,
V_231 ) ;
}
void F_185 ( struct V_59 * V_34 ,
struct V_191 * V_254 , bool V_255 )
{
struct V_3 * V_4 = F_36 ( V_254 , struct V_3 , V_4 ) ;
F_186 ( V_4 -> V_2 , V_254 , V_255 ) ;
if ( V_255 ) {
F_75 ( V_4 , V_18 ) ;
F_187 ( V_4 ) ;
return;
}
if ( ! F_4 ( V_4 , V_18 ) )
return;
if ( ! F_4 ( V_4 , V_17 ) ) {
F_75 ( V_4 , V_19 ) ;
F_6 ( V_4 , V_18 ) ;
F_188 ( V_34 , & V_4 -> V_36 ) ;
} else if ( F_4 ( V_4 , V_53 ) ||
F_4 ( V_4 , V_54 ) ) {
F_6 ( V_4 , V_18 ) ;
F_188 ( V_34 , & V_4 -> V_36 ) ;
} else {
F_6 ( V_4 , V_18 ) ;
F_161 ( V_4 ) ;
}
}
void F_189 ( struct V_191 * V_254 )
{
struct V_3 * V_4 = F_36 ( V_254 , struct V_3 , V_4 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_190 ( V_2 , V_254 ) ;
F_6 ( V_4 , V_198 ) ;
}
void F_191 ( struct V_191 * V_254 , int V_205 )
{
struct V_3 * V_4 = F_36 ( V_254 , struct V_3 , V_4 ) ;
enum V_206 V_207 ;
bool V_209 ;
F_192 ( V_4 -> V_2 , V_254 , V_205 ) ;
V_207 = V_231 ;
V_209 = F_173 ( V_4 , ~ V_4 -> V_4 . V_149 ,
V_207 , 0 ) ;
F_162 ( V_4 , V_205 , V_207 , false , V_209 ) ;
}
void F_193 ( struct V_191 * V_254 ,
T_1 V_205 , bool V_196 )
{
struct V_3 * V_4 = F_36 ( V_254 , struct V_3 , V_4 ) ;
if ( F_62 ( V_205 >= V_37 ) )
return;
F_194 ( V_4 -> V_2 , V_254 , V_205 , V_196 ) ;
if ( V_196 )
F_195 ( V_205 , & V_4 -> V_154 ) ;
else
F_196 ( V_205 , & V_4 -> V_154 ) ;
F_97 ( V_4 ) ;
}
static void
F_197 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
bool V_256 = V_13 -> V_20 . V_257 ;
struct V_3 * V_4 ;
F_22 () ;
F_28 (sta, &local->sta_list, list) {
if ( V_13 != V_4 -> V_13 ||
! F_4 ( V_4 , V_258 ) )
continue;
if ( ! V_4 -> V_4 . V_259 ) {
V_256 = false ;
break;
}
}
F_25 () ;
if ( V_256 != V_13 -> V_20 . V_166 . V_256 ) {
V_13 -> V_20 . V_166 . V_256 = V_256 ;
F_198 ( V_13 , V_260 ) ;
}
}
int F_118 ( struct V_3 * V_4 ,
enum V_117 V_261 )
{
F_85 () ;
if ( V_4 -> V_77 == V_261 )
return 0 ;
switch ( V_261 ) {
case V_78 :
if ( V_4 -> V_77 != V_262 )
return - V_113 ;
break;
case V_262 :
if ( V_4 -> V_77 != V_78 &&
V_4 -> V_77 != V_263 )
return - V_113 ;
break;
case V_263 :
if ( V_4 -> V_77 != V_262 &&
V_4 -> V_77 != V_264 )
return - V_113 ;
break;
case V_264 :
if ( V_4 -> V_77 != V_263 )
return - V_113 ;
break;
default:
F_199 ( 1 , L_10 , V_261 ) ;
return - V_113 ;
}
F_30 ( V_4 -> V_13 , L_11 ,
V_4 -> V_4 . V_41 , V_261 ) ;
if ( F_4 ( V_4 , V_136 ) ) {
int V_119 = F_71 ( V_4 -> V_2 , V_4 -> V_13 , V_4 ,
V_4 -> V_77 , V_261 ) ;
if ( V_119 )
return V_119 ;
}
switch ( V_261 ) {
case V_78 :
if ( V_4 -> V_77 == V_262 )
F_196 ( V_265 , & V_4 -> V_266 ) ;
break;
case V_262 :
if ( V_4 -> V_77 == V_78 ) {
F_195 ( V_265 , & V_4 -> V_266 ) ;
} else if ( V_4 -> V_77 == V_263 ) {
F_196 ( V_258 , & V_4 -> V_266 ) ;
F_200 ( V_4 -> V_13 ) ;
if ( ! V_4 -> V_4 . V_259 )
F_197 ( V_4 -> V_13 ) ;
}
break;
case V_263 :
if ( V_4 -> V_77 == V_262 ) {
F_195 ( V_258 , & V_4 -> V_266 ) ;
F_200 ( V_4 -> V_13 ) ;
if ( ! V_4 -> V_4 . V_259 )
F_197 ( V_4 -> V_13 ) ;
} else if ( V_4 -> V_77 == V_264 ) {
if ( V_4 -> V_13 -> V_20 . type == V_21 ||
( V_4 -> V_13 -> V_20 . type == V_22 &&
! V_4 -> V_13 -> V_24 . V_178 . V_4 ) )
F_7 ( & V_4 -> V_13 -> V_23 -> V_267 ) ;
F_196 ( V_268 , & V_4 -> V_266 ) ;
F_187 ( V_4 ) ;
F_201 ( V_4 ) ;
}
break;
case V_264 :
if ( V_4 -> V_77 == V_263 ) {
if ( V_4 -> V_13 -> V_20 . type == V_21 ||
( V_4 -> V_13 -> V_20 . type == V_22 &&
! V_4 -> V_13 -> V_24 . V_178 . V_4 ) )
F_202 ( & V_4 -> V_13 -> V_23 -> V_267 ) ;
F_195 ( V_268 , & V_4 -> V_266 ) ;
F_161 ( V_4 ) ;
F_203 ( V_4 ) ;
}
break;
default:
break;
}
V_4 -> V_77 = V_261 ;
return 0 ;
}
T_1 F_158 ( struct V_3 * V_4 )
{
struct V_269 * V_100 = & V_4 -> V_4 . V_100 ;
T_1 V_270 ;
if ( ! V_4 -> V_4 . V_100 . V_271 )
return 1 ;
if ( V_4 -> V_4 . V_272 . V_273 ) {
int V_9 ;
T_4 V_274 =
F_204 ( V_4 -> V_4 . V_272 . V_275 . V_274 ) ;
for ( V_9 = 7 ; V_9 >= 0 ; V_9 -- )
if ( ( V_274 & ( 0x3 << ( V_9 * 2 ) ) ) !=
V_276 )
return V_9 + 1 ;
}
if ( V_100 -> V_277 . V_278 [ 3 ] )
V_270 = 4 ;
else if ( V_100 -> V_277 . V_278 [ 2 ] )
V_270 = 3 ;
else if ( V_100 -> V_277 . V_278 [ 1 ] )
V_270 = 2 ;
else
V_270 = 1 ;
if ( ! ( V_100 -> V_277 . V_279 & V_280 ) )
return V_270 ;
return ( ( V_100 -> V_277 . V_279 & V_281 )
>> V_282 ) + 1 ;
}
static struct V_62 *
F_205 ( struct V_3 * V_4 )
{
struct V_62 * V_283 = & V_4 -> V_73 ;
struct V_1 * V_2 = V_4 -> V_2 ;
int V_284 ;
if ( ! F_44 ( & V_2 -> V_34 , V_61 ) )
return V_283 ;
F_206 (cpu) {
struct V_62 * V_285 ;
V_285 = F_207 ( V_4 -> V_49 , V_284 ) ;
if ( F_100 ( V_285 -> V_74 , V_283 -> V_74 ) )
V_283 = V_285 ;
}
return V_283 ;
}
static void F_208 ( struct V_1 * V_2 , T_4 V_286 ,
struct V_287 * V_288 )
{
V_288 -> V_289 = ( V_286 & V_290 ) >>
V_291 ;
if ( V_286 & V_292 ) {
V_288 -> V_171 = V_293 ;
V_288 -> V_277 = V_286 & 0xf ;
V_288 -> V_294 = ( V_286 & 0xf0 ) >> 4 ;
} else if ( V_286 & V_295 ) {
V_288 -> V_171 = V_296 ;
V_288 -> V_277 = V_286 & 0xff ;
} else if ( V_286 & V_297 ) {
struct V_95 * V_96 ;
T_4 V_298 ;
unsigned int V_299 ;
V_96 = V_2 -> V_34 . V_97 -> V_98 [ ( V_286 >> 4 ) & 0xf ] ;
V_298 = V_96 -> V_300 [ V_286 & 0xf ] . V_301 ;
if ( V_288 -> V_289 == V_302 )
V_299 = 2 ;
else if ( V_288 -> V_289 == V_303 )
V_299 = 1 ;
else
V_299 = 0 ;
V_288 -> V_304 = F_209 ( V_298 , 1 << V_299 ) ;
}
if ( V_286 & V_305 )
V_288 -> V_171 |= V_306 ;
}
static void F_210 ( struct V_3 * V_4 , struct V_287 * V_288 )
{
T_4 V_286 = F_211 ( F_205 ( V_4 ) -> V_307 ) ;
if ( V_286 == V_308 )
V_288 -> V_171 = 0 ;
else
F_208 ( V_4 -> V_2 , V_286 , V_288 ) ;
}
static void F_212 ( struct V_3 * V_4 ,
struct V_309 * V_310 ,
int V_205 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( ! ( V_310 -> V_311 & F_92 ( V_312 ) ) ) {
unsigned int V_313 ;
do {
V_313 = F_213 ( & V_4 -> V_73 . V_76 ) ;
V_310 -> V_314 = V_4 -> V_73 . V_315 [ V_205 ] ;
} while ( F_214 ( & V_4 -> V_73 . V_76 , V_313 ) );
V_310 -> V_311 |= F_92 ( V_312 ) ;
}
if ( ! ( V_310 -> V_311 & F_92 ( V_316 ) ) ) {
V_310 -> V_311 |= F_92 ( V_316 ) ;
V_310 -> V_317 = V_4 -> V_318 . V_315 [ V_205 ] ;
}
if ( ! ( V_310 -> V_311 & F_92 ( V_319 ) ) &&
F_44 ( & V_2 -> V_34 , V_320 ) ) {
V_310 -> V_311 |= F_92 ( V_319 ) ;
V_310 -> V_321 = V_4 -> V_322 . V_323 [ V_205 ] ;
}
if ( ! ( V_310 -> V_311 & F_92 ( V_324 ) ) &&
F_44 ( & V_2 -> V_34 , V_320 ) ) {
V_310 -> V_311 |= F_92 ( V_324 ) ;
V_310 -> V_325 = V_4 -> V_322 . V_326 [ V_205 ] ;
}
}
static inline T_8 F_215 ( struct V_62 * V_327 )
{
unsigned int V_313 ;
T_8 V_328 ;
do {
V_313 = F_213 ( & V_327 -> V_76 ) ;
V_328 = V_327 -> V_329 ;
} while ( F_214 ( & V_327 -> V_76 , V_313 ) );
return V_328 ;
}
void F_119 ( struct V_3 * V_4 , struct V_124 * V_125 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_330 * V_331 = NULL ;
T_6 V_332 = 0 ;
int V_9 , V_8 , V_284 ;
struct V_62 * V_333 ;
V_333 = F_205 ( V_4 ) ;
if ( F_4 ( V_4 , V_334 ) )
V_331 = V_2 -> V_47 ;
V_125 -> V_137 = V_13 -> V_2 -> V_130 ;
if ( V_13 -> V_20 . type == V_335 )
V_125 -> V_336 = V_13 -> V_24 . V_337 . V_338 ;
F_216 ( V_2 , V_13 , & V_4 -> V_4 , V_125 ) ;
V_125 -> V_311 |= F_92 ( V_339 ) |
F_92 ( V_340 ) |
F_92 ( V_341 ) |
F_92 ( V_342 ) |
F_92 ( V_343 ) ;
if ( V_13 -> V_20 . type == V_335 ) {
V_125 -> V_344 = V_13 -> V_24 . V_337 . V_344 ;
V_125 -> V_311 |= F_92 ( V_345 ) ;
}
V_125 -> V_346 = F_54 () - V_4 -> V_81 ;
V_125 -> V_347 =
F_217 ( V_75 - F_144 ( V_4 ) ) ;
if ( ! ( V_125 -> V_311 & ( F_92 ( V_348 ) |
F_92 ( V_349 ) ) ) ) {
V_125 -> V_350 = 0 ;
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ )
V_125 -> V_350 += V_4 -> V_318 . V_329 [ V_8 ] ;
V_125 -> V_311 |= F_92 ( V_348 ) ;
}
if ( ! ( V_125 -> V_311 & F_92 ( V_351 ) ) ) {
V_125 -> V_352 = 0 ;
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ )
V_125 -> V_352 += V_4 -> V_318 . V_353 [ V_8 ] ;
V_125 -> V_311 |= F_92 ( V_351 ) ;
}
if ( ! ( V_125 -> V_311 & ( F_92 ( V_354 ) |
F_92 ( V_355 ) ) ) ) {
V_125 -> V_356 += F_215 ( & V_4 -> V_73 ) ;
if ( V_4 -> V_49 ) {
F_206 (cpu) {
struct V_62 * V_357 ;
V_357 = F_207 ( V_4 -> V_49 , V_284 ) ;
V_125 -> V_356 += F_215 ( V_357 ) ;
}
}
V_125 -> V_311 |= F_92 ( V_354 ) ;
}
if ( ! ( V_125 -> V_311 & F_92 ( V_358 ) ) ) {
V_125 -> V_359 = V_4 -> V_73 . V_353 ;
if ( V_4 -> V_49 ) {
F_206 (cpu) {
struct V_62 * V_357 ;
V_357 = F_207 ( V_4 -> V_49 , V_284 ) ;
V_125 -> V_359 += V_357 -> V_353 ;
}
}
V_125 -> V_311 |= F_92 ( V_358 ) ;
}
if ( ! ( V_125 -> V_311 & F_92 ( V_360 ) ) ) {
V_125 -> V_361 = V_4 -> V_322 . V_362 ;
V_125 -> V_311 |= F_92 ( V_360 ) ;
}
if ( ! ( V_125 -> V_311 & F_92 ( V_363 ) ) ) {
V_125 -> V_364 = V_4 -> V_322 . V_365 ;
V_125 -> V_311 |= F_92 ( V_363 ) ;
}
V_125 -> V_366 = V_4 -> V_73 . V_367 ;
if ( V_4 -> V_49 ) {
F_206 (cpu) {
struct V_62 * V_357 ;
V_357 = F_207 ( V_4 -> V_49 , V_284 ) ;
V_125 -> V_359 += V_357 -> V_367 ;
}
}
if ( V_13 -> V_20 . type == V_335 &&
! ( V_13 -> V_20 . V_368 & V_369 ) ) {
V_125 -> V_311 |= F_92 ( V_370 ) |
F_92 ( V_371 ) ;
V_125 -> V_372 = F_218 ( & V_13 -> V_20 ) ;
}
if ( F_44 ( & V_4 -> V_2 -> V_34 , V_373 ) ||
F_44 ( & V_4 -> V_2 -> V_34 , V_374 ) ) {
if ( ! ( V_125 -> V_311 & F_92 ( V_375 ) ) ) {
V_125 -> signal = ( V_376 ) V_333 -> V_377 ;
V_125 -> V_311 |= F_92 ( V_375 ) ;
}
if ( ! V_4 -> V_49 &&
! ( V_125 -> V_311 & F_92 ( V_378 ) ) ) {
V_125 -> V_379 =
- F_219 ( & V_4 -> V_82 . signal ) ;
V_125 -> V_311 |= F_92 ( V_378 ) ;
}
}
if ( V_333 -> V_380 &&
! ( V_125 -> V_311 & ( F_92 ( V_381 ) |
F_92 ( V_382 ) ) ) ) {
V_125 -> V_311 |= F_92 ( V_381 ) ;
if ( ! V_4 -> V_49 )
V_125 -> V_311 |= F_92 ( V_382 ) ;
V_125 -> V_380 = V_333 -> V_380 ;
for ( V_9 = 0 ; V_9 < F_8 ( V_125 -> V_83 ) ; V_9 ++ ) {
V_125 -> V_83 [ V_9 ] =
V_333 -> V_383 [ V_9 ] ;
V_125 -> V_384 [ V_9 ] =
- F_219 ( & V_4 -> V_82 . V_83 [ V_9 ] ) ;
}
}
if ( ! ( V_125 -> V_311 & F_92 ( V_385 ) ) ) {
F_220 ( V_4 , & V_4 -> V_318 . V_307 ,
& V_125 -> V_386 ) ;
V_125 -> V_311 |= F_92 ( V_385 ) ;
}
if ( ! ( V_125 -> V_311 & F_92 ( V_387 ) ) ) {
F_210 ( V_4 , & V_125 -> V_388 ) ;
V_125 -> V_311 |= F_92 ( V_387 ) ;
}
V_125 -> V_311 |= F_92 ( V_389 ) ;
for ( V_9 = 0 ; V_9 < V_37 + 1 ; V_9 ++ ) {
struct V_309 * V_310 = & V_125 -> V_390 [ V_9 ] ;
F_212 ( V_4 , V_310 , V_9 ) ;
}
if ( F_5 ( & V_13 -> V_20 ) ) {
#ifdef F_31
V_125 -> V_311 |= F_92 ( V_391 ) |
F_92 ( V_392 ) |
F_92 ( V_393 ) |
F_92 ( V_394 ) |
F_92 ( V_395 ) |
F_92 ( V_396 ) ;
V_125 -> V_397 = V_4 -> V_25 -> V_397 ;
V_125 -> V_398 = V_4 -> V_25 -> V_398 ;
V_125 -> V_399 = V_4 -> V_25 -> V_399 ;
if ( F_4 ( V_4 , V_400 ) ) {
V_125 -> V_311 |= F_92 ( V_401 ) ;
V_125 -> V_402 = V_4 -> V_25 -> V_402 ;
}
V_125 -> V_403 = V_4 -> V_25 -> V_403 ;
V_125 -> V_404 = V_4 -> V_25 -> V_404 ;
V_125 -> V_70 = V_4 -> V_25 -> V_70 ;
#endif
}
V_125 -> V_405 . V_171 = 0 ;
if ( V_13 -> V_20 . V_166 . V_406 )
V_125 -> V_405 . V_171 |= V_407 ;
if ( V_13 -> V_20 . V_166 . V_408 )
V_125 -> V_405 . V_171 |= V_409 ;
if ( V_13 -> V_20 . V_166 . V_410 )
V_125 -> V_405 . V_171 |= V_411 ;
V_125 -> V_405 . V_412 = V_13 -> V_20 . V_166 . V_412 ;
V_125 -> V_405 . V_413 = V_13 -> V_20 . V_166 . V_167 ;
V_125 -> V_414 . V_415 = 0 ;
V_125 -> V_414 . V_416 = F_92 ( V_417 ) |
F_92 ( V_418 ) |
F_92 ( V_419 ) |
F_92 ( V_420 ) |
F_92 ( V_421 ) |
F_92 ( V_422 ) |
F_92 ( V_423 ) ;
if ( F_4 ( V_4 , V_268 ) )
V_125 -> V_414 . V_415 |= F_92 ( V_417 ) ;
if ( F_4 ( V_4 , V_424 ) )
V_125 -> V_414 . V_415 |= F_92 ( V_418 ) ;
if ( V_4 -> V_4 . V_214 )
V_125 -> V_414 . V_415 |= F_92 ( V_419 ) ;
if ( F_4 ( V_4 , V_425 ) )
V_125 -> V_414 . V_415 |= F_92 ( V_420 ) ;
if ( F_4 ( V_4 , V_265 ) )
V_125 -> V_414 . V_415 |= F_92 ( V_421 ) ;
if ( F_4 ( V_4 , V_258 ) )
V_125 -> V_414 . V_415 |= F_92 ( V_422 ) ;
if ( F_4 ( V_4 , V_426 ) )
V_125 -> V_414 . V_415 |= F_92 ( V_423 ) ;
if ( V_331 && V_331 -> V_84 -> V_427 )
V_332 = V_331 -> V_84 -> V_427 ( V_4 -> V_57 ) ;
else
V_332 = F_221 ( V_2 , & V_4 -> V_4 ) ;
if ( V_332 != 0 ) {
V_125 -> V_311 |= F_92 ( V_428 ) ;
V_125 -> V_429 = V_332 ;
}
}
unsigned long F_144 ( struct V_3 * V_4 )
{
struct V_62 * V_283 = F_205 ( V_4 ) ;
if ( F_100 ( V_283 -> V_74 , V_4 -> V_322 . V_430 ) )
return V_283 -> V_74 ;
return V_4 -> V_322 . V_430 ;
}
