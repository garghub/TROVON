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
V_28 -> V_33 = 0 ;
}
}
for ( V_8 = 0 ; V_8 < V_34 ; V_8 ++ ) {
V_2 -> V_35 -= F_10 ( & V_4 -> V_36 [ V_8 ] ) ;
F_11 ( & V_2 -> V_31 , & V_4 -> V_36 [ V_8 ] ) ;
F_11 ( & V_2 -> V_31 , & V_4 -> V_37 [ V_8 ] ) ;
}
if ( F_5 ( & V_13 -> V_19 ) )
F_13 ( V_4 ) ;
F_14 ( & V_4 -> V_38 ) ;
for ( V_9 = 0 ; V_9 < V_39 ; V_9 ++ ) {
F_15 ( V_4 -> V_40 . V_41 [ V_9 ] ) ;
V_11 = F_16 ( V_4 -> V_40 . V_11 [ V_9 ] ) ;
if ( ! V_11 )
continue;
F_11 ( & V_2 -> V_31 , & V_11 -> V_42 ) ;
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
const T_1 * V_43 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 ;
struct V_44 * V_45 ;
const struct V_46 * V_47 ;
F_20 () ;
V_47 = F_21 ( V_2 -> V_5 . V_47 , & V_2 -> V_5 ) ;
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
const T_1 * V_43 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 ;
struct V_44 * V_45 ;
const struct V_46 * V_47 ;
F_20 () ;
V_47 = F_21 ( V_2 -> V_5 . V_47 , & V_2 -> V_5 ) ;
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
int V_48 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 ;
int V_9 = 0 ;
F_26 (sta, &local->sta_list, list) {
if ( V_13 != V_4 -> V_13 )
continue;
if ( V_9 < V_48 ) {
++ V_9 ;
continue;
}
return V_4 ;
}
return NULL ;
}
void F_18 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_49 )
F_27 ( V_4 ) ;
F_28 ( V_4 -> V_13 , L_1 , V_4 -> V_4 . V_43 ) ;
if ( V_4 -> V_4 . V_26 [ 0 ] )
F_15 ( F_9 ( V_4 -> V_4 . V_26 [ 0 ] ) ) ;
F_15 ( F_16 ( V_4 -> V_4 . V_50 ) ) ;
#ifdef F_29
F_15 ( V_4 -> V_24 ) ;
#endif
F_30 ( V_4 -> V_51 ) ;
F_15 ( V_4 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return F_32 ( & V_2 -> V_5 , & V_4 -> V_6 ,
V_7 ) ;
}
static void F_33 ( struct V_52 * V_53 )
{
struct V_3 * V_4 ;
V_4 = F_34 ( V_53 , struct V_3 , V_38 ) ;
if ( V_4 -> V_54 )
return;
F_35 () ;
if ( ! F_4 ( V_4 , V_16 ) )
F_36 ( V_4 ) ;
else if ( F_37 ( V_4 , V_55 ) )
F_38 ( V_4 ) ;
else if ( F_37 ( V_4 , V_56 ) )
F_39 ( V_4 ) ;
F_40 () ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 V_57 )
{
if ( F_42 ( & V_2 -> V_31 , V_58 ) )
return 0 ;
V_4 -> V_49 = V_2 -> V_49 ;
V_4 -> V_59 = F_43 ( V_4 -> V_49 ,
V_4 , V_57 ) ;
if ( ! V_4 -> V_59 )
return - V_60 ;
return 0 ;
}
struct V_3 * F_44 ( struct V_12 * V_13 ,
const T_1 * V_43 , T_2 V_57 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_61 * V_31 = & V_2 -> V_31 ;
struct V_3 * V_4 ;
int V_9 ;
V_4 = F_45 ( sizeof( * V_4 ) + V_31 -> V_62 , V_57 ) ;
if ( ! V_4 )
return NULL ;
if ( F_42 ( V_31 , V_63 ) ) {
V_4 -> V_51 =
F_46 ( struct V_64 ) ;
if ( ! V_4 -> V_51 )
goto free;
}
F_47 ( & V_4 -> V_65 ) ;
F_47 ( & V_4 -> V_66 ) ;
F_48 ( & V_4 -> V_38 , F_33 ) ;
F_48 ( & V_4 -> V_40 . V_67 , V_68 ) ;
F_49 ( & V_4 -> V_40 . V_69 ) ;
#ifdef F_29
if ( F_5 ( & V_13 -> V_19 ) ) {
V_4 -> V_24 = F_45 ( sizeof( * V_4 -> V_24 ) , V_57 ) ;
if ( ! V_4 -> V_24 )
goto free;
F_47 ( & V_4 -> V_24 -> V_70 ) ;
if ( F_5 ( & V_13 -> V_19 ) &&
! V_13 -> V_23 . V_24 . V_71 )
F_50 ( & V_4 -> V_24 -> V_72 ) ;
V_4 -> V_24 -> V_73 = V_74 ;
}
#endif
memcpy ( V_4 -> V_43 , V_43 , V_75 ) ;
memcpy ( V_4 -> V_4 . V_43 , V_43 , V_75 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_13 = V_13 ;
V_4 -> V_76 . V_77 = V_78 ;
F_51 ( & V_4 -> V_76 . V_79 ) ;
V_4 -> V_80 = V_81 ;
V_4 -> V_82 = V_83 ;
V_4 -> V_84 = F_52 () ;
F_53 ( & V_4 -> V_85 . signal ) ;
for ( V_9 = 0 ; V_9 < F_8 ( V_4 -> V_85 . V_86 ) ; V_9 ++ )
F_53 ( & V_4 -> V_85 . V_86 [ V_9 ] ) ;
if ( V_2 -> V_87 -> V_88 ) {
void * V_89 ;
int V_90 = sizeof( struct V_27 ) +
F_54 ( V_31 -> V_91 , sizeof( void * ) ) ;
V_89 = F_55 ( F_8 ( V_4 -> V_4 . V_26 ) , V_90 , V_57 ) ;
if ( ! V_89 )
goto free;
for ( V_9 = 0 ; V_9 < F_8 ( V_4 -> V_4 . V_26 ) ; V_9 ++ ) {
struct V_27 * V_26 = V_89 + V_9 * V_90 ;
F_56 ( V_13 , V_4 , V_26 , V_9 ) ;
}
}
if ( F_41 ( V_2 , V_4 , V_57 ) )
goto V_92;
for ( V_9 = 0 ; V_9 < V_39 ; V_9 ++ ) {
V_4 -> V_93 [ V_9 ] = V_9 ;
}
for ( V_9 = 0 ; V_9 < V_34 ; V_9 ++ ) {
F_57 ( & V_4 -> V_36 [ V_9 ] ) ;
F_57 ( & V_4 -> V_37 [ V_9 ] ) ;
}
for ( V_9 = 0 ; V_9 < V_39 ; V_9 ++ )
V_4 -> V_94 [ V_9 ] = F_58 ( V_95 ) ;
V_4 -> V_4 . V_96 = V_97 ;
if ( V_13 -> V_19 . type == V_20 ||
V_13 -> V_19 . type == V_21 ) {
struct V_98 * V_99 =
V_31 -> V_100 -> V_101 [ F_59 ( V_13 ) ] ;
T_1 V_102 = ( V_99 -> V_103 . V_104 & V_105 ) >>
V_106 ;
switch ( V_102 ) {
case V_107 :
V_4 -> V_108 = V_97 ;
break;
case V_109 :
V_4 -> V_108 = V_110 ;
break;
case V_111 :
V_4 -> V_108 = V_112 ;
break;
default:
F_60 ( 1 ) ;
}
}
V_4 -> V_4 . V_113 = V_114 ;
F_28 ( V_13 , L_2 , V_4 -> V_4 . V_43 ) ;
return V_4 ;
V_92:
if ( V_4 -> V_4 . V_26 [ 0 ] )
F_15 ( F_9 ( V_4 -> V_4 . V_26 [ 0 ] ) ) ;
free:
#ifdef F_29
F_15 ( V_4 -> V_24 ) ;
#endif
F_15 ( V_4 ) ;
return NULL ;
}
static int F_61 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
if ( F_62 ( ! F_63 ( V_13 ) ) )
return - V_115 ;
if ( F_60 ( F_64 ( V_4 -> V_4 . V_43 , V_13 -> V_19 . V_43 ) ||
F_65 ( V_4 -> V_4 . V_43 ) ) )
return - V_116 ;
F_20 () ;
F_66 ( & V_13 -> V_2 -> V_117 ) ;
if ( F_42 ( & V_13 -> V_2 -> V_31 , V_118 ) &&
F_67 ( & V_13 -> V_2 -> V_31 , V_4 -> V_43 , NULL ) ) {
F_23 () ;
return - V_119 ;
}
F_23 () ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_3 * V_4 )
{
enum V_120 V_121 ;
int V_122 = 0 ;
for ( V_121 = V_123 ; V_121 < V_4 -> V_80 ; V_121 ++ ) {
V_122 = F_69 ( V_2 , V_13 , V_4 , V_121 , V_121 + 1 ) ;
if ( V_122 )
break;
}
if ( ! V_122 ) {
if ( ! V_2 -> V_87 -> V_124 )
V_4 -> V_125 = true ;
return 0 ;
}
if ( V_13 -> V_19 . type == V_126 ) {
F_70 ( V_13 ,
L_3 ,
V_4 -> V_4 . V_43 , V_121 + 1 , V_122 ) ;
V_122 = 0 ;
}
for (; V_121 > V_123 ; V_121 -- )
F_60 ( F_69 ( V_2 , V_13 , V_4 , V_121 , V_121 - 1 ) ) ;
return V_122 ;
}
static int F_71 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_127 * V_128 ;
int V_122 = 0 ;
F_66 ( & V_2 -> V_117 ) ;
V_128 = F_45 ( sizeof( struct V_127 ) , V_129 ) ;
if ( ! V_128 ) {
V_122 = - V_60 ;
goto V_130;
}
if ( F_24 ( V_13 , V_4 -> V_4 . V_43 ) ) {
V_122 = - V_131 ;
goto V_130;
}
V_2 -> V_132 ++ ;
V_2 -> V_133 ++ ;
F_72 () ;
F_73 ( V_4 , V_134 ) ;
V_122 = F_31 ( V_2 , V_4 ) ;
if ( V_122 )
goto V_135;
F_74 ( & V_4 -> V_136 , & V_2 -> V_137 ) ;
V_122 = F_68 ( V_2 , V_13 , V_4 ) ;
if ( V_122 )
goto V_138;
F_73 ( V_4 , V_139 ) ;
F_6 ( V_4 , V_134 ) ;
F_75 ( V_4 ) ;
F_76 ( V_4 ) ;
V_128 -> V_140 = V_2 -> V_133 ;
F_77 ( V_13 -> V_141 , V_4 -> V_4 . V_43 , V_128 , V_129 ) ;
F_15 ( V_128 ) ;
F_28 ( V_13 , L_4 , V_4 -> V_4 . V_43 ) ;
F_20 () ;
F_78 ( & V_2 -> V_117 ) ;
if ( F_5 ( & V_13 -> V_19 ) )
F_79 ( V_13 ) ;
return 0 ;
V_138:
F_1 ( V_2 , V_4 ) ;
F_80 ( & V_4 -> V_136 ) ;
V_135:
V_2 -> V_132 -- ;
F_81 () ;
F_3 ( V_4 ) ;
V_130:
F_78 ( & V_2 -> V_117 ) ;
F_15 ( V_128 ) ;
F_20 () ;
return V_122 ;
}
int F_82 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_122 ;
F_83 () ;
F_84 ( & V_2 -> V_117 ) ;
V_122 = F_61 ( V_4 ) ;
if ( V_122 ) {
F_78 ( & V_2 -> V_117 ) ;
F_20 () ;
goto V_142;
}
V_122 = F_71 ( V_4 ) ;
if ( V_122 )
goto V_142;
return 0 ;
V_142:
F_18 ( V_2 , V_4 ) ;
return V_122 ;
}
int F_85 ( struct V_3 * V_4 )
{
int V_122 = F_82 ( V_4 ) ;
F_23 () ;
return V_122 ;
}
static inline void F_86 ( T_1 * V_143 , T_4 V_144 )
{
V_143 [ V_144 / 8 ] |= ( 1 << ( V_144 % 8 ) ) ;
}
static inline void F_87 ( T_1 * V_143 , T_4 V_144 )
{
V_143 [ V_144 / 8 ] &= ~ ( 1 << ( V_144 % 8 ) ) ;
}
static inline bool F_88 ( T_1 * V_143 , T_4 V_144 )
{
return V_143 [ V_144 / 8 ] & ( 1 << ( V_144 % 8 ) ) ;
}
static unsigned long F_89 ( int V_8 )
{
switch ( V_8 ) {
case V_145 :
return F_90 ( 6 ) | F_90 ( 7 ) ;
case V_146 :
return F_90 ( 4 ) | F_90 ( 5 ) ;
case V_147 :
return F_90 ( 0 ) | F_90 ( 3 ) ;
case V_148 :
return F_90 ( 1 ) | F_90 ( 2 ) ;
default:
F_60 ( 1 ) ;
return 0 ;
}
}
static void F_91 ( struct V_3 * V_4 , bool V_149 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_14 * V_15 ;
bool V_150 = false ;
T_1 V_151 = V_4 -> V_4 . V_152 ;
int V_8 ;
T_4 V_144 = V_4 -> V_4 . V_153 ;
if ( V_4 -> V_13 -> V_19 . type == V_20 ||
V_4 -> V_13 -> V_19 . type == V_21 ) {
if ( F_92 ( ! V_4 -> V_13 -> V_22 ) )
return;
V_15 = & V_4 -> V_13 -> V_22 -> V_15 ;
#ifdef F_29
} else if ( F_5 ( & V_4 -> V_13 -> V_19 ) ) {
V_15 = & V_4 -> V_13 -> V_23 . V_24 . V_15 ;
#endif
} else {
return;
}
if ( F_42 ( & V_2 -> V_31 , V_154 ) )
return;
if ( V_4 -> V_54 )
goto V_155;
if ( V_151 == F_90 ( V_34 ) - 1 )
V_151 = 0 ;
if ( V_149 )
V_151 = F_90 ( V_34 ) - 1 ;
for ( V_8 = 0 ; V_8 < V_34 ; V_8 ++ ) {
unsigned long V_156 ;
if ( V_151 & F_90 ( V_8 ) )
continue;
V_150 |= ! F_93 ( & V_4 -> V_37 [ V_8 ] ) ||
! F_93 ( & V_4 -> V_36 [ V_8 ] ) ;
if ( V_150 )
break;
V_156 = F_89 ( V_8 ) ;
V_150 |=
V_4 -> V_157 & V_156 ;
V_150 |=
V_4 -> V_158 & V_156 ;
}
V_155:
F_94 ( & V_2 -> V_159 ) ;
if ( V_150 == F_88 ( V_15 -> V_143 , V_144 ) )
goto V_160;
if ( V_150 )
F_86 ( V_15 -> V_143 , V_144 ) ;
else
F_87 ( V_15 -> V_143 , V_144 ) ;
if ( V_2 -> V_87 -> V_161 && ! F_60 ( V_4 -> V_54 ) ) {
V_2 -> V_162 = true ;
F_95 ( V_2 , & V_4 -> V_4 , V_150 ) ;
V_2 -> V_162 = false ;
}
V_160:
F_96 ( & V_2 -> V_159 ) ;
}
void F_97 ( struct V_3 * V_4 )
{
F_91 ( V_4 , false ) ;
}
static bool F_98 ( struct V_3 * V_4 , struct V_163 * V_164 )
{
struct V_165 * V_166 ;
int V_167 ;
if ( ! V_164 )
return false ;
V_166 = F_99 ( V_164 ) ;
V_167 = ( V_4 -> V_168 *
V_4 -> V_13 -> V_19 . V_169 . V_170 *
32 / 15625 ) * V_171 ;
if ( V_167 < V_172 )
V_167 = V_172 ;
return F_100 ( V_78 , V_166 -> V_173 . V_78 + V_167 ) ;
}
static bool F_101 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_8 )
{
unsigned long V_174 ;
struct V_163 * V_164 ;
for (; ; ) {
F_102 ( & V_4 -> V_37 [ V_8 ] . V_65 , V_174 ) ;
V_164 = F_103 ( & V_4 -> V_37 [ V_8 ] ) ;
if ( F_98 ( V_4 , V_164 ) )
V_164 = F_104 ( & V_4 -> V_37 [ V_8 ] ) ;
else
V_164 = NULL ;
F_105 ( & V_4 -> V_37 [ V_8 ] . V_65 , V_174 ) ;
if ( ! V_164 )
break;
F_106 ( & V_2 -> V_31 , V_164 ) ;
}
for (; ; ) {
F_102 ( & V_4 -> V_36 [ V_8 ] . V_65 , V_174 ) ;
V_164 = F_103 ( & V_4 -> V_36 [ V_8 ] ) ;
if ( F_98 ( V_4 , V_164 ) )
V_164 = F_104 ( & V_4 -> V_36 [ V_8 ] ) ;
else
V_164 = NULL ;
F_105 ( & V_4 -> V_36 [ V_8 ] . V_65 , V_174 ) ;
if ( ! V_164 )
break;
V_2 -> V_35 -- ;
F_107 ( V_4 -> V_13 , L_5 ,
V_4 -> V_4 . V_43 ) ;
F_106 ( & V_2 -> V_31 , V_164 ) ;
}
F_97 ( V_4 ) ;
return ! ( F_93 ( & V_4 -> V_36 [ V_8 ] ) &&
F_93 ( & V_4 -> V_37 [ V_8 ] ) ) ;
}
static bool F_108 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_175 = false ;
int V_8 ;
if ( ! V_4 -> V_13 -> V_22 &&
! F_5 ( & V_4 -> V_13 -> V_19 ) )
return false ;
for ( V_8 = 0 ; V_8 < V_34 ; V_8 ++ )
V_175 |=
F_101 ( V_2 , V_4 , V_8 ) ;
return V_175 ;
}
static int T_5 F_109 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
int V_176 ;
F_83 () ;
if ( ! V_4 )
return - V_177 ;
V_2 = V_4 -> V_2 ;
V_13 = V_4 -> V_13 ;
F_66 ( & V_2 -> V_117 ) ;
F_73 ( V_4 , V_134 ) ;
F_110 ( V_4 , V_178 ) ;
F_111 ( V_2 , V_4 ) ;
V_176 = F_1 ( V_2 , V_4 ) ;
if ( F_60 ( V_176 ) )
return V_176 ;
if ( F_4 ( V_4 , V_179 ) ) {
F_112 ( V_2 , V_13 , & V_4 -> V_4 ) ;
F_6 ( V_4 , V_179 ) ;
}
F_80 ( & V_4 -> V_136 ) ;
V_4 -> V_180 = true ;
F_113 ( V_2 , V_4 -> V_13 , V_4 ) ;
if ( V_13 -> V_19 . type == V_21 &&
F_114 ( V_13 -> V_23 . V_181 . V_4 ) == V_4 )
F_115 ( V_13 -> V_23 . V_181 . V_4 , NULL ) ;
return 0 ;
}
static void F_116 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_127 * V_128 ;
int V_176 ;
F_83 () ;
F_66 ( & V_2 -> V_117 ) ;
F_117 ( V_2 , V_4 ) ;
F_91 ( V_4 , true ) ;
V_4 -> V_54 = true ;
V_2 -> V_132 -- ;
V_2 -> V_133 ++ ;
while ( V_4 -> V_80 > V_81 ) {
V_176 = F_118 ( V_4 , V_4 -> V_80 - 1 ) ;
if ( V_176 ) {
F_92 ( 1 ) ;
break;
}
}
if ( V_4 -> V_125 ) {
V_176 = F_69 ( V_2 , V_13 , V_4 , V_81 ,
V_123 ) ;
F_92 ( V_176 != 0 ) ;
}
F_28 ( V_13 , L_6 , V_4 -> V_4 . V_43 ) ;
V_128 = F_45 ( sizeof( * V_128 ) , V_129 ) ;
if ( V_128 )
F_119 ( V_4 , V_128 ) ;
F_120 ( V_13 -> V_141 , V_4 -> V_4 . V_43 , V_128 , V_129 ) ;
F_15 ( V_128 ) ;
F_121 ( V_4 ) ;
F_122 ( V_4 ) ;
F_17 ( V_4 ) ;
}
int T_5 F_123 ( struct V_3 * V_4 )
{
int V_122 = F_109 ( V_4 ) ;
if ( V_122 )
return V_122 ;
F_81 () ;
F_116 ( V_4 ) ;
return 0 ;
}
int F_124 ( struct V_12 * V_13 , const T_1 * V_43 )
{
struct V_3 * V_4 ;
int V_176 ;
F_84 ( & V_13 -> V_2 -> V_117 ) ;
V_4 = F_19 ( V_13 , V_43 ) ;
V_176 = F_123 ( V_4 ) ;
F_78 ( & V_13 -> V_2 -> V_117 ) ;
return V_176 ;
}
int F_125 ( struct V_12 * V_13 ,
const T_1 * V_43 )
{
struct V_3 * V_4 ;
int V_176 ;
F_84 ( & V_13 -> V_2 -> V_117 ) ;
V_4 = F_24 ( V_13 , V_43 ) ;
V_176 = F_123 ( V_4 ) ;
F_78 ( & V_13 -> V_2 -> V_117 ) ;
return V_176 ;
}
static void F_126 ( unsigned long V_182 )
{
struct V_1 * V_2 = (struct V_1 * ) V_182 ;
struct V_3 * V_4 ;
bool V_183 = false ;
F_20 () ;
F_26 (sta, &local->sta_list, list)
if ( F_108 ( V_2 , V_4 ) )
V_183 = true ;
F_23 () ;
if ( V_2 -> V_184 )
return;
if ( ! V_183 )
return;
F_127 ( & V_2 -> V_185 ,
F_128 ( V_78 + V_186 ) ) ;
}
T_6 F_129 ( const void * V_187 , T_6 V_188 , T_6 V_189 )
{
return F_130 ( V_187 , V_75 , V_189 ) ;
}
int F_131 ( struct V_1 * V_2 )
{
int V_122 ;
V_122 = F_132 ( & V_2 -> V_5 , & V_7 ) ;
if ( V_122 )
return V_122 ;
F_47 ( & V_2 -> V_159 ) ;
F_49 ( & V_2 -> V_117 ) ;
F_133 ( & V_2 -> V_137 ) ;
F_134 ( & V_2 -> V_185 , F_126 ,
( unsigned long ) V_2 ) ;
return 0 ;
}
void F_135 ( struct V_1 * V_2 )
{
F_136 ( & V_2 -> V_185 ) ;
F_137 ( & V_2 -> V_5 ) ;
}
int F_138 ( struct V_12 * V_13 , bool V_190 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 , * V_45 ;
F_139 ( V_191 ) ;
int V_176 = 0 ;
F_83 () ;
F_60 ( V_190 && V_13 -> V_19 . type != V_20 ) ;
F_60 ( V_190 && ! V_13 -> V_22 ) ;
F_84 ( & V_2 -> V_117 ) ;
F_140 (sta, tmp, &local->sta_list, list) {
if ( V_13 == V_4 -> V_13 ||
( V_190 && V_13 -> V_22 == V_4 -> V_13 -> V_22 ) ) {
if ( ! F_60 ( F_109 ( V_4 ) ) )
F_141 ( & V_4 -> V_191 , & V_191 ) ;
V_176 ++ ;
}
}
if ( ! F_142 ( & V_191 ) ) {
F_81 () ;
F_140 (sta, tmp, &free_list, free_list)
F_116 ( V_4 ) ;
}
F_78 ( & V_2 -> V_117 ) ;
return V_176 ;
}
void F_143 ( struct V_12 * V_13 ,
unsigned long V_192 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 , * V_45 ;
F_84 ( & V_2 -> V_117 ) ;
F_140 (sta, tmp, &local->sta_list, list) {
unsigned long V_193 = F_144 ( V_4 ) ;
if ( V_13 != V_4 -> V_13 )
continue;
if ( F_145 ( V_193 + V_192 ) ) {
F_28 ( V_4 -> V_13 , L_7 ,
V_4 -> V_4 . V_43 ) ;
if ( F_5 ( & V_13 -> V_19 ) &&
F_4 ( V_4 , V_16 ) )
F_7 ( & V_13 -> V_23 . V_24 . V_15 . V_25 ) ;
F_60 ( F_123 ( V_4 ) ) ;
}
}
F_78 ( & V_2 -> V_117 ) ;
}
struct V_194 * F_67 ( struct V_61 * V_31 ,
const T_1 * V_43 ,
const T_1 * V_195 )
{
struct V_1 * V_2 = F_146 ( V_31 ) ;
struct V_3 * V_4 ;
struct V_44 * V_45 ;
const struct V_46 * V_47 ;
V_47 = F_21 ( V_2 -> V_5 . V_47 , & V_2 -> V_5 ) ;
F_22 (local, tbl, addr, sta, tmp) {
if ( V_195 &&
! F_64 ( V_4 -> V_13 -> V_19 . V_43 , V_195 ) )
continue;
if ( ! V_4 -> V_125 )
return NULL ;
return & V_4 -> V_4 ;
}
return NULL ;
}
struct V_194 * F_147 ( struct V_196 * V_19 ,
const T_1 * V_43 )
{
struct V_3 * V_4 ;
if ( ! V_19 )
return NULL ;
V_4 = F_24 ( F_148 ( V_19 ) , V_43 ) ;
if ( ! V_4 )
return NULL ;
if ( ! V_4 -> V_125 )
return NULL ;
return & V_4 -> V_4 ;
}
void F_36 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_197 V_42 ;
int V_198 = 0 , V_199 = 0 , V_8 , V_9 ;
unsigned long V_174 ;
struct V_14 * V_15 ;
if ( V_13 -> V_19 . type == V_21 )
V_13 = F_34 ( V_13 -> V_22 , struct V_12 ,
V_23 . V_200 ) ;
if ( V_13 -> V_19 . type == V_20 )
V_15 = & V_13 -> V_22 -> V_15 ;
else if ( F_5 ( & V_13 -> V_19 ) )
V_15 = & V_13 -> V_23 . V_24 . V_15 ;
else
return;
F_6 ( V_4 , V_201 ) ;
F_149 ( F_150 ( V_39 ) > 1 ) ;
V_4 -> V_157 = 0 ;
V_4 -> V_158 = 0 ;
if ( ! F_42 ( & V_2 -> V_31 , V_154 ) )
F_151 ( V_2 , V_13 , V_202 , & V_4 -> V_4 ) ;
if ( V_4 -> V_4 . V_26 [ 0 ] ) {
for ( V_9 = 0 ; V_9 < F_8 ( V_4 -> V_4 . V_26 ) ; V_9 ++ ) {
struct V_27 * V_28 = F_9 ( V_4 -> V_4 . V_26 [ V_9 ] ) ;
if ( ! F_10 ( & V_28 -> V_30 ) )
continue;
F_152 ( V_2 , V_28 ) ;
}
}
F_57 ( & V_42 ) ;
F_153 ( & V_4 -> V_66 ) ;
for ( V_8 = 0 ; V_8 < V_34 ; V_8 ++ ) {
int V_203 = F_10 ( & V_42 ) , V_45 ;
F_102 ( & V_4 -> V_37 [ V_8 ] . V_65 , V_174 ) ;
F_154 ( & V_4 -> V_37 [ V_8 ] , & V_42 ) ;
F_105 ( & V_4 -> V_37 [ V_8 ] . V_65 , V_174 ) ;
V_45 = F_10 ( & V_42 ) ;
V_198 += V_45 - V_203 ;
V_203 = V_45 ;
F_102 ( & V_4 -> V_36 [ V_8 ] . V_65 , V_174 ) ;
F_154 ( & V_4 -> V_36 [ V_8 ] , & V_42 ) ;
F_105 ( & V_4 -> V_36 [ V_8 ] . V_65 , V_174 ) ;
V_45 = F_10 ( & V_42 ) ;
V_199 += V_45 - V_203 ;
}
F_155 ( V_2 , & V_42 ) ;
F_6 ( V_4 , V_18 ) ;
F_6 ( V_4 , V_55 ) ;
F_6 ( V_4 , V_56 ) ;
F_156 ( & V_4 -> V_66 ) ;
F_7 ( & V_15 -> V_25 ) ;
if ( ! F_5 ( & V_13 -> V_19 ) &&
! F_157 ( V_4 -> V_108 ,
V_13 -> V_96 ) &&
V_4 -> V_108 != V_13 -> V_22 -> V_204 &&
F_158 ( V_4 ) != 1 ) {
F_159 ( V_13 ,
L_8 ,
V_4 -> V_4 . V_43 ) ;
F_160 ( V_13 , V_13 -> V_22 -> V_204 ,
V_4 -> V_4 . V_43 ,
V_13 -> V_19 . V_169 . V_205 ) ;
}
V_2 -> V_35 -= V_199 ;
F_97 ( V_4 ) ;
F_107 ( V_13 ,
L_9 ,
V_4 -> V_4 . V_43 , V_4 -> V_4 . V_153 , V_198 , V_199 ) ;
F_161 ( V_4 ) ;
}
static void F_162 ( struct V_3 * V_4 , int V_206 ,
enum V_207 V_208 ,
bool V_209 , bool V_210 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_211 * V_212 ;
struct V_163 * V_164 ;
int V_90 = sizeof( * V_212 ) ;
T_7 V_213 ;
bool V_214 = V_4 -> V_4 . V_215 ;
struct V_165 * V_166 ;
struct V_216 * V_217 ;
if ( V_214 ) {
V_213 = F_58 ( V_218 |
V_219 |
V_220 ) ;
} else {
V_90 -= 2 ;
V_213 = F_58 ( V_218 |
V_221 |
V_220 ) ;
}
V_164 = F_163 ( V_2 -> V_31 . V_222 + V_90 ) ;
if ( ! V_164 )
return;
F_164 ( V_164 , V_2 -> V_31 . V_222 ) ;
V_212 = ( void * ) F_165 ( V_164 , V_90 ) ;
V_212 -> V_223 = V_213 ;
V_212 -> V_224 = 0 ;
memcpy ( V_212 -> V_225 , V_4 -> V_4 . V_43 , V_75 ) ;
memcpy ( V_212 -> V_226 , V_13 -> V_19 . V_43 , V_75 ) ;
memcpy ( V_212 -> V_227 , V_13 -> V_19 . V_43 , V_75 ) ;
V_212 -> V_228 = 0 ;
V_164 -> V_229 = V_206 ;
F_166 ( V_164 , V_230 [ V_206 ] ) ;
if ( V_214 ) {
V_212 -> V_231 = F_58 ( V_206 ) ;
if ( V_208 == V_232 ) {
V_212 -> V_231 |=
F_58 ( V_233 ) ;
if ( V_210 )
V_212 -> V_223 |=
F_58 ( V_234 ) ;
}
}
V_166 = F_99 ( V_164 ) ;
V_166 -> V_174 |= V_235 |
V_236 |
V_237 ;
V_166 -> V_173 . V_174 |= V_238 ;
if ( V_209 )
F_167 ( V_2 , V_4 , F_90 ( V_206 ) , 1 ,
V_208 , false ) ;
V_164 -> V_141 = V_13 -> V_141 ;
F_20 () ;
V_217 = F_168 ( V_13 -> V_19 . V_217 ) ;
if ( F_60 ( ! V_217 ) ) {
F_23 () ;
F_169 ( V_164 ) ;
return;
}
V_166 -> V_239 = V_217 -> V_240 . V_241 -> V_239 ;
F_170 ( V_13 , V_4 , V_164 ) ;
F_23 () ;
}
static int F_171 ( unsigned long V_156 )
{
if ( V_156 & 0xF8 )
return F_172 ( V_156 ) - 1 ;
if ( V_156 & F_90 ( 0 ) )
return 0 ;
return F_172 ( V_156 ) - 1 ;
}
static bool
F_173 ( struct V_3 * V_4 , T_1 V_242 ,
enum V_207 V_208 ,
unsigned long V_243 )
{
int V_8 ;
if ( V_208 == V_244 &&
F_174 ( V_243 ) > 1 )
return true ;
for ( V_8 = 0 ; V_8 < V_34 ; V_8 ++ ) {
if ( V_242 & F_90 ( V_8 ) )
continue;
if ( ! F_93 ( & V_4 -> V_37 [ V_8 ] ) ||
! F_93 ( & V_4 -> V_36 [ V_8 ] ) )
return true ;
}
return false ;
}
static void
F_175 ( struct V_3 * V_4 , int V_245 , T_1 V_242 ,
enum V_207 V_208 ,
struct V_197 * V_246 ,
unsigned long * V_243 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_34 ; V_8 ++ ) {
unsigned long V_156 ;
if ( V_242 & F_90 ( V_8 ) )
continue;
V_156 = F_89 ( V_8 ) ;
if ( F_93 ( V_246 ) ) {
* V_243 |=
V_4 -> V_157 & V_156 ;
* V_243 |= V_4 -> V_158 & V_156 ;
}
if ( ! * V_243 ) {
struct V_163 * V_164 ;
while ( V_245 > 0 ) {
V_164 = F_176 ( & V_4 -> V_37 [ V_8 ] ) ;
if ( ! V_164 ) {
V_164 = F_176 (
& V_4 -> V_36 [ V_8 ] ) ;
if ( V_164 )
V_2 -> V_35 -- ;
}
if ( ! V_164 )
break;
V_245 -- ;
F_177 ( V_246 , V_164 ) ;
}
}
if ( ! F_93 ( & V_4 -> V_37 [ V_8 ] ) ||
! F_93 ( & V_4 -> V_36 [ V_8 ] ) )
break;
}
}
static void
F_178 ( struct V_3 * V_4 ,
int V_245 , T_1 V_242 ,
enum V_207 V_208 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
unsigned long V_243 = 0 ;
struct V_197 V_246 ;
bool V_210 ;
F_73 ( V_4 , V_201 ) ;
F_179 ( & V_246 ) ;
F_175 ( V_4 , V_245 , V_242 , V_208 ,
& V_246 , & V_243 ) ;
V_210 = F_173 ( V_4 , V_242 , V_208 , V_243 ) ;
if ( V_243 && V_208 == V_244 )
V_243 =
F_90 ( F_171 ( V_243 ) ) ;
if ( F_93 ( & V_246 ) && ! V_243 ) {
int V_206 ;
V_206 = 7 - ( ( F_180 ( ~ V_242 ) - 1 ) << 1 ) ;
F_162 ( V_4 , V_206 , V_208 , true , false ) ;
} else if ( ! V_243 ) {
struct V_197 V_42 ;
struct V_163 * V_164 ;
int V_247 = 0 ;
T_4 V_156 = 0 ;
bool V_248 = false ;
F_57 ( & V_42 ) ;
while ( ( V_164 = F_104 ( & V_246 ) ) ) {
struct V_165 * V_166 = F_99 ( V_164 ) ;
struct V_249 * V_250 = ( void * ) V_164 -> V_182 ;
T_1 * V_251 = NULL ;
V_247 ++ ;
V_166 -> V_174 |= V_235 ;
V_166 -> V_173 . V_174 |= V_238 ;
if ( V_210 || ! F_93 ( & V_246 ) )
V_250 -> V_223 |=
F_58 ( V_234 ) ;
else
V_250 -> V_223 &=
F_58 ( ~ V_234 ) ;
if ( F_181 ( V_250 -> V_223 ) ||
F_182 ( V_250 -> V_223 ) )
V_251 = F_183 ( V_250 ) ;
V_156 |= F_90 ( V_164 -> V_229 ) ;
F_177 ( & V_42 , V_164 ) ;
if ( ! F_93 ( & V_246 ) )
continue;
if ( V_208 != V_232 ) {
V_166 -> V_174 |= V_236 |
V_237 ;
break;
}
if ( V_251 ) {
* V_251 |= V_233 ;
V_166 -> V_174 |= V_236 |
V_237 ;
} else {
V_250 -> V_223 |=
F_58 ( V_234 ) ;
V_248 = true ;
V_247 ++ ;
}
break;
}
F_167 ( V_2 , V_4 , V_156 , V_247 ,
V_208 , V_210 ) ;
F_155 ( V_2 , & V_42 ) ;
if ( V_248 )
F_162 (
V_4 , F_171 ( V_156 ) ,
V_208 , false , false ) ;
F_97 ( V_4 ) ;
} else {
unsigned long V_156 = V_4 -> V_158 & V_243 ;
int V_206 ;
F_184 ( V_2 , V_4 , V_243 ,
V_245 , V_208 , V_210 ) ;
if ( ! V_4 -> V_4 . V_26 [ 0 ] )
return;
for ( V_206 = 0 ; V_206 < F_8 ( V_4 -> V_4 . V_26 ) ; V_206 ++ ) {
struct V_27 * V_28 = F_9 ( V_4 -> V_4 . V_26 [ V_206 ] ) ;
if ( ! ( V_156 & F_90 ( V_206 ) ) || F_10 ( & V_28 -> V_30 ) )
continue;
F_97 ( V_4 ) ;
break;
}
}
}
void F_38 ( struct V_3 * V_4 )
{
T_1 V_252 = V_4 -> V_4 . V_152 ;
if ( V_252 == F_90 ( V_34 ) - 1 )
V_252 = 0 ;
F_178 ( V_4 , 1 , V_252 ,
V_244 ) ;
}
void F_39 ( struct V_3 * V_4 )
{
int V_245 = V_4 -> V_4 . V_253 ;
T_1 V_254 = V_4 -> V_4 . V_152 ;
if ( ! V_254 )
return;
switch ( V_4 -> V_4 . V_253 ) {
case 1 :
V_245 = 2 ;
break;
case 2 :
V_245 = 4 ;
break;
case 3 :
V_245 = 6 ;
break;
case 0 :
V_245 = 128 ;
break;
}
F_178 ( V_4 , V_245 , ~ V_254 ,
V_232 ) ;
}
void F_185 ( struct V_61 * V_31 ,
struct V_194 * V_255 , bool V_256 )
{
struct V_3 * V_4 = F_34 ( V_255 , struct V_3 , V_4 ) ;
F_186 ( V_4 -> V_2 , V_255 , V_256 ) ;
if ( V_256 ) {
F_73 ( V_4 , V_17 ) ;
F_187 ( V_4 ) ;
return;
}
if ( ! F_4 ( V_4 , V_17 ) )
return;
if ( ! F_4 ( V_4 , V_16 ) ) {
F_73 ( V_4 , V_18 ) ;
F_6 ( V_4 , V_17 ) ;
F_188 ( V_31 , & V_4 -> V_38 ) ;
} else if ( F_4 ( V_4 , V_55 ) ||
F_4 ( V_4 , V_56 ) ) {
F_6 ( V_4 , V_17 ) ;
F_188 ( V_31 , & V_4 -> V_38 ) ;
} else {
F_6 ( V_4 , V_17 ) ;
F_161 ( V_4 ) ;
}
}
void F_189 ( struct V_194 * V_255 )
{
struct V_3 * V_4 = F_34 ( V_255 , struct V_3 , V_4 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_190 ( V_2 , V_255 ) ;
F_6 ( V_4 , V_201 ) ;
}
void F_191 ( struct V_194 * V_255 , int V_206 )
{
struct V_3 * V_4 = F_34 ( V_255 , struct V_3 , V_4 ) ;
enum V_207 V_208 ;
bool V_210 ;
F_192 ( V_4 -> V_2 , V_255 , V_206 ) ;
V_208 = V_232 ;
V_210 = F_173 ( V_4 , ~ V_4 -> V_4 . V_152 ,
V_208 , 0 ) ;
F_162 ( V_4 , V_206 , V_208 , false , V_210 ) ;
}
void F_193 ( struct V_194 * V_255 ,
T_1 V_206 , bool V_199 )
{
struct V_3 * V_4 = F_34 ( V_255 , struct V_3 , V_4 ) ;
if ( F_60 ( V_206 >= V_39 ) )
return;
F_194 ( V_4 -> V_2 , V_255 , V_206 , V_199 ) ;
if ( V_199 )
F_195 ( V_206 , & V_4 -> V_157 ) ;
else
F_196 ( V_206 , & V_4 -> V_157 ) ;
F_97 ( V_4 ) ;
}
static void
F_197 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
bool V_257 = V_13 -> V_19 . V_258 ;
struct V_3 * V_4 ;
F_20 () ;
F_26 (sta, &local->sta_list, list) {
if ( V_13 != V_4 -> V_13 ||
! F_4 ( V_4 , V_259 ) )
continue;
if ( ! V_4 -> V_4 . V_260 ) {
V_257 = false ;
break;
}
}
F_23 () ;
if ( V_257 != V_13 -> V_19 . V_169 . V_257 ) {
V_13 -> V_19 . V_169 . V_257 = V_257 ;
F_198 ( V_13 , V_261 ) ;
}
}
int F_118 ( struct V_3 * V_4 ,
enum V_120 V_262 )
{
F_83 () ;
if ( V_4 -> V_80 == V_262 )
return 0 ;
switch ( V_262 ) {
case V_81 :
if ( V_4 -> V_80 != V_263 )
return - V_116 ;
break;
case V_263 :
if ( V_4 -> V_80 != V_81 &&
V_4 -> V_80 != V_264 )
return - V_116 ;
break;
case V_264 :
if ( V_4 -> V_80 != V_263 &&
V_4 -> V_80 != V_265 )
return - V_116 ;
break;
case V_265 :
if ( V_4 -> V_80 != V_264 )
return - V_116 ;
break;
default:
F_199 ( 1 , L_10 , V_262 ) ;
return - V_116 ;
}
F_28 ( V_4 -> V_13 , L_11 ,
V_4 -> V_4 . V_43 , V_262 ) ;
if ( F_4 ( V_4 , V_139 ) ) {
int V_122 = F_69 ( V_4 -> V_2 , V_4 -> V_13 , V_4 ,
V_4 -> V_80 , V_262 ) ;
if ( V_122 )
return V_122 ;
}
switch ( V_262 ) {
case V_81 :
if ( V_4 -> V_80 == V_263 )
F_196 ( V_266 , & V_4 -> V_267 ) ;
break;
case V_263 :
if ( V_4 -> V_80 == V_81 ) {
F_195 ( V_266 , & V_4 -> V_267 ) ;
} else if ( V_4 -> V_80 == V_264 ) {
F_196 ( V_259 , & V_4 -> V_267 ) ;
F_200 ( V_4 -> V_13 ) ;
if ( ! V_4 -> V_4 . V_260 )
F_197 ( V_4 -> V_13 ) ;
}
break;
case V_264 :
if ( V_4 -> V_80 == V_263 ) {
F_195 ( V_259 , & V_4 -> V_267 ) ;
F_200 ( V_4 -> V_13 ) ;
if ( ! V_4 -> V_4 . V_260 )
F_197 ( V_4 -> V_13 ) ;
} else if ( V_4 -> V_80 == V_265 ) {
if ( V_4 -> V_13 -> V_19 . type == V_20 ||
( V_4 -> V_13 -> V_19 . type == V_21 &&
! V_4 -> V_13 -> V_23 . V_181 . V_4 ) )
F_7 ( & V_4 -> V_13 -> V_22 -> V_268 ) ;
F_196 ( V_269 , & V_4 -> V_267 ) ;
F_187 ( V_4 ) ;
F_201 ( V_4 ) ;
}
break;
case V_265 :
if ( V_4 -> V_80 == V_264 ) {
if ( V_4 -> V_13 -> V_19 . type == V_20 ||
( V_4 -> V_13 -> V_19 . type == V_21 &&
! V_4 -> V_13 -> V_23 . V_181 . V_4 ) )
F_202 ( & V_4 -> V_13 -> V_22 -> V_268 ) ;
F_195 ( V_269 , & V_4 -> V_267 ) ;
F_161 ( V_4 ) ;
F_203 ( V_4 ) ;
}
break;
default:
break;
}
V_4 -> V_80 = V_262 ;
return 0 ;
}
T_1 F_158 ( struct V_3 * V_4 )
{
struct V_270 * V_103 = & V_4 -> V_4 . V_103 ;
T_1 V_271 ;
if ( ! V_4 -> V_4 . V_103 . V_272 )
return 1 ;
if ( V_4 -> V_4 . V_273 . V_274 ) {
int V_9 ;
T_4 V_275 =
F_204 ( V_4 -> V_4 . V_273 . V_276 . V_275 ) ;
for ( V_9 = 7 ; V_9 >= 0 ; V_9 -- )
if ( ( V_275 & ( 0x3 << ( V_9 * 2 ) ) ) !=
V_277 )
return V_9 + 1 ;
}
if ( V_103 -> V_278 . V_279 [ 3 ] )
V_271 = 4 ;
else if ( V_103 -> V_278 . V_279 [ 2 ] )
V_271 = 3 ;
else if ( V_103 -> V_278 . V_279 [ 1 ] )
V_271 = 2 ;
else
V_271 = 1 ;
if ( ! ( V_103 -> V_278 . V_280 & V_281 ) )
return V_271 ;
return ( ( V_103 -> V_278 . V_280 & V_282 )
>> V_283 ) + 1 ;
}
static struct V_64 *
F_205 ( struct V_3 * V_4 )
{
struct V_64 * V_284 = & V_4 -> V_76 ;
struct V_1 * V_2 = V_4 -> V_2 ;
int V_285 ;
if ( ! F_42 ( & V_2 -> V_31 , V_63 ) )
return V_284 ;
F_206 (cpu) {
struct V_64 * V_286 ;
V_286 = F_207 ( V_4 -> V_51 , V_285 ) ;
if ( F_100 ( V_286 -> V_77 , V_284 -> V_77 ) )
V_284 = V_286 ;
}
return V_284 ;
}
static void F_208 ( struct V_1 * V_2 , T_4 V_287 ,
struct V_288 * V_289 )
{
V_289 -> V_290 = ( V_287 & V_291 ) >>
V_292 ;
if ( V_287 & V_293 ) {
V_289 -> V_174 = V_294 ;
V_289 -> V_278 = V_287 & 0xf ;
V_289 -> V_295 = ( V_287 & 0xf0 ) >> 4 ;
} else if ( V_287 & V_296 ) {
V_289 -> V_174 = V_297 ;
V_289 -> V_278 = V_287 & 0xff ;
} else if ( V_287 & V_298 ) {
struct V_98 * V_99 ;
T_4 V_299 ;
unsigned int V_300 ;
V_99 = V_2 -> V_31 . V_100 -> V_101 [ ( V_287 >> 4 ) & 0xf ] ;
V_299 = V_99 -> V_301 [ V_287 & 0xf ] . V_302 ;
if ( V_289 -> V_290 == V_303 )
V_300 = 2 ;
else if ( V_289 -> V_290 == V_304 )
V_300 = 1 ;
else
V_300 = 0 ;
V_289 -> V_305 = F_209 ( V_299 , 1 << V_300 ) ;
}
if ( V_287 & V_306 )
V_289 -> V_174 |= V_307 ;
}
static void F_210 ( struct V_3 * V_4 , struct V_288 * V_289 )
{
T_4 V_287 = F_211 ( F_205 ( V_4 ) -> V_308 ) ;
if ( V_287 == V_309 )
V_289 -> V_174 = 0 ;
else
F_208 ( V_4 -> V_2 , V_287 , V_289 ) ;
}
static void F_212 ( struct V_3 * V_4 ,
struct V_310 * V_311 ,
int V_206 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( ! ( V_311 -> V_312 & F_90 ( V_313 ) ) ) {
unsigned int V_314 ;
do {
V_314 = F_213 ( & V_4 -> V_76 . V_79 ) ;
V_311 -> V_315 = V_4 -> V_76 . V_316 [ V_206 ] ;
} while ( F_214 ( & V_4 -> V_76 . V_79 , V_314 ) );
V_311 -> V_312 |= F_90 ( V_313 ) ;
}
if ( ! ( V_311 -> V_312 & F_90 ( V_317 ) ) ) {
V_311 -> V_312 |= F_90 ( V_317 ) ;
V_311 -> V_318 = V_4 -> V_319 . V_316 [ V_206 ] ;
}
if ( ! ( V_311 -> V_312 & F_90 ( V_320 ) ) &&
F_42 ( & V_2 -> V_31 , V_321 ) ) {
V_311 -> V_312 |= F_90 ( V_320 ) ;
V_311 -> V_322 = V_4 -> V_323 . V_324 [ V_206 ] ;
}
if ( ! ( V_311 -> V_312 & F_90 ( V_325 ) ) &&
F_42 ( & V_2 -> V_31 , V_321 ) ) {
V_311 -> V_312 |= F_90 ( V_325 ) ;
V_311 -> V_326 = V_4 -> V_323 . V_327 [ V_206 ] ;
}
}
static inline T_8 F_215 ( struct V_64 * V_328 )
{
unsigned int V_314 ;
T_8 V_329 ;
do {
V_314 = F_213 ( & V_328 -> V_79 ) ;
V_329 = V_328 -> V_330 ;
} while ( F_214 ( & V_328 -> V_79 , V_314 ) );
return V_329 ;
}
void F_119 ( struct V_3 * V_4 , struct V_127 * V_128 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_331 * V_332 = NULL ;
T_6 V_333 = 0 ;
int V_9 , V_8 , V_285 ;
struct V_64 * V_334 ;
V_334 = F_205 ( V_4 ) ;
if ( F_4 ( V_4 , V_335 ) )
V_332 = V_2 -> V_49 ;
V_128 -> V_140 = V_13 -> V_2 -> V_133 ;
if ( V_13 -> V_19 . type == V_336 )
V_128 -> V_337 = V_13 -> V_23 . V_338 . V_339 ;
F_216 ( V_2 , V_13 , & V_4 -> V_4 , V_128 ) ;
V_128 -> V_312 |= F_90 ( V_340 ) |
F_90 ( V_341 ) |
F_90 ( V_342 ) |
F_90 ( V_343 ) |
F_90 ( V_344 ) ;
if ( V_13 -> V_19 . type == V_336 ) {
V_128 -> V_345 = V_13 -> V_23 . V_338 . V_345 ;
V_128 -> V_312 |= F_90 ( V_346 ) ;
}
V_128 -> V_347 = F_52 () - V_4 -> V_84 ;
V_128 -> V_348 =
F_217 ( V_78 - F_144 ( V_4 ) ) ;
if ( ! ( V_128 -> V_312 & ( F_90 ( V_349 ) |
F_90 ( V_350 ) ) ) ) {
V_128 -> V_351 = 0 ;
for ( V_8 = 0 ; V_8 < V_34 ; V_8 ++ )
V_128 -> V_351 += V_4 -> V_319 . V_330 [ V_8 ] ;
V_128 -> V_312 |= F_90 ( V_349 ) ;
}
if ( ! ( V_128 -> V_312 & F_90 ( V_352 ) ) ) {
V_128 -> V_353 = 0 ;
for ( V_8 = 0 ; V_8 < V_34 ; V_8 ++ )
V_128 -> V_353 += V_4 -> V_319 . V_354 [ V_8 ] ;
V_128 -> V_312 |= F_90 ( V_352 ) ;
}
if ( ! ( V_128 -> V_312 & ( F_90 ( V_355 ) |
F_90 ( V_356 ) ) ) ) {
V_128 -> V_357 += F_215 ( & V_4 -> V_76 ) ;
if ( V_4 -> V_51 ) {
F_206 (cpu) {
struct V_64 * V_358 ;
V_358 = F_207 ( V_4 -> V_51 , V_285 ) ;
V_128 -> V_357 += F_215 ( V_358 ) ;
}
}
V_128 -> V_312 |= F_90 ( V_355 ) ;
}
if ( ! ( V_128 -> V_312 & F_90 ( V_359 ) ) ) {
V_128 -> V_360 = V_4 -> V_76 . V_354 ;
if ( V_4 -> V_51 ) {
F_206 (cpu) {
struct V_64 * V_358 ;
V_358 = F_207 ( V_4 -> V_51 , V_285 ) ;
V_128 -> V_360 += V_358 -> V_354 ;
}
}
V_128 -> V_312 |= F_90 ( V_359 ) ;
}
if ( ! ( V_128 -> V_312 & F_90 ( V_361 ) ) ) {
V_128 -> V_362 = V_4 -> V_323 . V_363 ;
V_128 -> V_312 |= F_90 ( V_361 ) ;
}
if ( ! ( V_128 -> V_312 & F_90 ( V_364 ) ) ) {
V_128 -> V_365 = V_4 -> V_323 . V_366 ;
V_128 -> V_312 |= F_90 ( V_364 ) ;
}
V_128 -> V_367 = V_4 -> V_76 . V_368 ;
if ( V_4 -> V_51 ) {
F_206 (cpu) {
struct V_64 * V_358 ;
V_358 = F_207 ( V_4 -> V_51 , V_285 ) ;
V_128 -> V_360 += V_358 -> V_368 ;
}
}
if ( V_13 -> V_19 . type == V_336 &&
! ( V_13 -> V_19 . V_369 & V_370 ) ) {
V_128 -> V_312 |= F_90 ( V_371 ) |
F_90 ( V_372 ) ;
V_128 -> V_373 = F_218 ( & V_13 -> V_19 ) ;
}
if ( F_42 ( & V_4 -> V_2 -> V_31 , V_374 ) ||
F_42 ( & V_4 -> V_2 -> V_31 , V_375 ) ) {
if ( ! ( V_128 -> V_312 & F_90 ( V_376 ) ) ) {
V_128 -> signal = ( V_377 ) V_334 -> V_378 ;
V_128 -> V_312 |= F_90 ( V_376 ) ;
}
if ( ! V_4 -> V_51 &&
! ( V_128 -> V_312 & F_90 ( V_379 ) ) ) {
V_128 -> V_380 =
- F_219 ( & V_4 -> V_85 . signal ) ;
V_128 -> V_312 |= F_90 ( V_379 ) ;
}
}
if ( V_334 -> V_381 &&
! ( V_128 -> V_312 & ( F_90 ( V_382 ) |
F_90 ( V_383 ) ) ) ) {
V_128 -> V_312 |= F_90 ( V_382 ) ;
if ( ! V_4 -> V_51 )
V_128 -> V_312 |= F_90 ( V_383 ) ;
V_128 -> V_381 = V_334 -> V_381 ;
for ( V_9 = 0 ; V_9 < F_8 ( V_128 -> V_86 ) ; V_9 ++ ) {
V_128 -> V_86 [ V_9 ] =
V_334 -> V_384 [ V_9 ] ;
V_128 -> V_385 [ V_9 ] =
- F_219 ( & V_4 -> V_85 . V_86 [ V_9 ] ) ;
}
}
if ( ! ( V_128 -> V_312 & F_90 ( V_386 ) ) ) {
F_220 ( V_4 , & V_4 -> V_319 . V_308 ,
& V_128 -> V_387 ) ;
V_128 -> V_312 |= F_90 ( V_386 ) ;
}
if ( ! ( V_128 -> V_312 & F_90 ( V_388 ) ) ) {
F_210 ( V_4 , & V_128 -> V_389 ) ;
V_128 -> V_312 |= F_90 ( V_388 ) ;
}
V_128 -> V_312 |= F_90 ( V_390 ) ;
for ( V_9 = 0 ; V_9 < V_39 + 1 ; V_9 ++ ) {
struct V_310 * V_311 = & V_128 -> V_391 [ V_9 ] ;
F_212 ( V_4 , V_311 , V_9 ) ;
}
if ( F_5 ( & V_13 -> V_19 ) ) {
#ifdef F_29
V_128 -> V_312 |= F_90 ( V_392 ) |
F_90 ( V_393 ) |
F_90 ( V_394 ) |
F_90 ( V_395 ) |
F_90 ( V_396 ) |
F_90 ( V_397 ) ;
V_128 -> V_398 = V_4 -> V_24 -> V_398 ;
V_128 -> V_399 = V_4 -> V_24 -> V_399 ;
V_128 -> V_400 = V_4 -> V_24 -> V_400 ;
if ( F_4 ( V_4 , V_401 ) ) {
V_128 -> V_312 |= F_90 ( V_402 ) ;
V_128 -> V_403 = V_4 -> V_24 -> V_403 ;
}
V_128 -> V_404 = V_4 -> V_24 -> V_404 ;
V_128 -> V_405 = V_4 -> V_24 -> V_405 ;
V_128 -> V_73 = V_4 -> V_24 -> V_73 ;
#endif
}
V_128 -> V_406 . V_174 = 0 ;
if ( V_13 -> V_19 . V_169 . V_407 )
V_128 -> V_406 . V_174 |= V_408 ;
if ( V_13 -> V_19 . V_169 . V_409 )
V_128 -> V_406 . V_174 |= V_410 ;
if ( V_13 -> V_19 . V_169 . V_411 )
V_128 -> V_406 . V_174 |= V_412 ;
V_128 -> V_406 . V_413 = V_13 -> V_19 . V_169 . V_413 ;
V_128 -> V_406 . V_414 = V_13 -> V_19 . V_169 . V_170 ;
V_128 -> V_415 . V_416 = 0 ;
V_128 -> V_415 . V_417 = F_90 ( V_418 ) |
F_90 ( V_419 ) |
F_90 ( V_420 ) |
F_90 ( V_421 ) |
F_90 ( V_422 ) |
F_90 ( V_423 ) |
F_90 ( V_424 ) ;
if ( F_4 ( V_4 , V_269 ) )
V_128 -> V_415 . V_416 |= F_90 ( V_418 ) ;
if ( F_4 ( V_4 , V_425 ) )
V_128 -> V_415 . V_416 |= F_90 ( V_419 ) ;
if ( V_4 -> V_4 . V_215 )
V_128 -> V_415 . V_416 |= F_90 ( V_420 ) ;
if ( F_4 ( V_4 , V_426 ) )
V_128 -> V_415 . V_416 |= F_90 ( V_421 ) ;
if ( F_4 ( V_4 , V_266 ) )
V_128 -> V_415 . V_416 |= F_90 ( V_422 ) ;
if ( F_4 ( V_4 , V_259 ) )
V_128 -> V_415 . V_416 |= F_90 ( V_423 ) ;
if ( F_4 ( V_4 , V_427 ) )
V_128 -> V_415 . V_416 |= F_90 ( V_424 ) ;
if ( V_332 && V_332 -> V_87 -> V_428 )
V_333 = V_332 -> V_87 -> V_428 ( V_4 -> V_59 ) ;
else
V_333 = F_221 ( V_2 , & V_4 -> V_4 ) ;
if ( V_333 != 0 ) {
V_128 -> V_312 |= F_90 ( V_429 ) ;
V_128 -> V_430 = V_333 ;
}
}
unsigned long F_144 ( struct V_3 * V_4 )
{
struct V_64 * V_284 = F_205 ( V_4 ) ;
if ( F_100 ( V_284 -> V_77 , V_4 -> V_323 . V_431 ) )
return V_284 -> V_77 ;
return V_4 -> V_323 . V_431 ;
}
