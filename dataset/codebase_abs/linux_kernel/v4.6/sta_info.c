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
F_15 ( V_4 ) ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return F_31 ( & V_2 -> V_5 , & V_4 -> V_6 ,
V_7 ) ;
}
static void F_32 ( struct V_51 * V_52 )
{
struct V_3 * V_4 ;
V_4 = F_33 ( V_52 , struct V_3 , V_38 ) ;
if ( V_4 -> V_53 )
return;
F_34 () ;
if ( ! F_4 ( V_4 , V_16 ) )
F_35 ( V_4 ) ;
else if ( F_36 ( V_4 , V_54 ) )
F_37 ( V_4 ) ;
else if ( F_36 ( V_4 , V_55 ) )
F_38 ( V_4 ) ;
F_39 () ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 V_56 )
{
if ( F_41 ( & V_2 -> V_31 , V_57 ) )
return 0 ;
V_4 -> V_49 = V_2 -> V_49 ;
V_4 -> V_58 = F_42 ( V_4 -> V_49 ,
V_4 , V_56 ) ;
if ( ! V_4 -> V_58 )
return - V_59 ;
return 0 ;
}
struct V_3 * F_43 ( struct V_12 * V_13 ,
const T_1 * V_43 , T_2 V_56 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_60 * V_31 = & V_2 -> V_31 ;
struct V_3 * V_4 ;
int V_9 ;
V_4 = F_44 ( sizeof( * V_4 ) + V_31 -> V_61 , V_56 ) ;
if ( ! V_4 )
return NULL ;
F_45 ( & V_4 -> V_62 ) ;
F_45 ( & V_4 -> V_63 ) ;
F_46 ( & V_4 -> V_38 , F_32 ) ;
F_46 ( & V_4 -> V_40 . V_64 , V_65 ) ;
F_47 ( & V_4 -> V_40 . V_66 ) ;
#ifdef F_29
if ( F_5 ( & V_13 -> V_19 ) ) {
V_4 -> V_24 = F_44 ( sizeof( * V_4 -> V_24 ) , V_56 ) ;
if ( ! V_4 -> V_24 )
goto free;
F_45 ( & V_4 -> V_24 -> V_67 ) ;
if ( F_5 ( & V_13 -> V_19 ) &&
! V_13 -> V_23 . V_24 . V_68 )
F_48 ( & V_4 -> V_24 -> V_69 ) ;
V_4 -> V_24 -> V_70 = V_71 ;
}
#endif
memcpy ( V_4 -> V_43 , V_43 , V_72 ) ;
memcpy ( V_4 -> V_4 . V_43 , V_43 , V_72 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_13 = V_13 ;
V_4 -> V_73 . V_74 = V_75 ;
V_4 -> V_76 = V_77 ;
V_4 -> V_78 = V_79 ;
V_4 -> V_80 = F_49 () ;
F_50 ( & V_4 -> V_73 . V_81 ) ;
for ( V_9 = 0 ; V_9 < F_8 ( V_4 -> V_73 . V_82 ) ; V_9 ++ )
F_50 ( & V_4 -> V_73 . V_82 [ V_9 ] ) ;
if ( V_2 -> V_83 -> V_84 ) {
void * V_85 ;
int V_86 = sizeof( struct V_27 ) +
F_51 ( V_31 -> V_87 , sizeof( void * ) ) ;
V_85 = F_52 ( F_8 ( V_4 -> V_4 . V_26 ) , V_86 , V_56 ) ;
if ( ! V_85 )
goto free;
for ( V_9 = 0 ; V_9 < F_8 ( V_4 -> V_4 . V_26 ) ; V_9 ++ ) {
struct V_27 * V_26 = V_85 + V_9 * V_86 ;
F_53 ( V_13 , V_4 , V_26 , V_9 ) ;
}
}
if ( F_40 ( V_2 , V_4 , V_56 ) )
goto V_88;
for ( V_9 = 0 ; V_9 < V_39 ; V_9 ++ ) {
V_4 -> V_89 [ V_9 ] = V_9 ;
}
for ( V_9 = 0 ; V_9 < V_34 ; V_9 ++ ) {
F_54 ( & V_4 -> V_36 [ V_9 ] ) ;
F_54 ( & V_4 -> V_37 [ V_9 ] ) ;
}
for ( V_9 = 0 ; V_9 < V_39 ; V_9 ++ )
V_4 -> V_90 [ V_9 ] = F_55 ( V_91 ) ;
V_4 -> V_4 . V_92 = V_93 ;
if ( V_13 -> V_19 . type == V_20 ||
V_13 -> V_19 . type == V_21 ) {
struct V_94 * V_95 =
V_31 -> V_96 -> V_97 [ F_56 ( V_13 ) ] ;
T_1 V_98 = ( V_95 -> V_99 . V_100 & V_101 ) >>
V_102 ;
switch ( V_98 ) {
case V_103 :
V_4 -> V_104 = V_93 ;
break;
case V_105 :
V_4 -> V_104 = V_106 ;
break;
case V_107 :
V_4 -> V_104 = V_108 ;
break;
default:
F_57 ( 1 ) ;
}
}
F_28 ( V_13 , L_2 , V_4 -> V_4 . V_43 ) ;
return V_4 ;
V_88:
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
return - V_109 ;
if ( F_57 ( F_61 ( V_4 -> V_4 . V_43 , V_13 -> V_19 . V_43 ) ||
F_62 ( V_4 -> V_4 . V_43 ) ) )
return - V_110 ;
F_20 () ;
F_63 ( & V_13 -> V_2 -> V_111 ) ;
if ( F_41 ( & V_13 -> V_2 -> V_31 , V_112 ) &&
F_64 ( & V_13 -> V_2 -> V_31 , V_4 -> V_43 , NULL ) ) {
F_23 () ;
return - V_113 ;
}
F_23 () ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_3 * V_4 )
{
enum V_114 V_115 ;
int V_116 = 0 ;
for ( V_115 = V_117 ; V_115 < V_4 -> V_76 ; V_115 ++ ) {
V_116 = F_66 ( V_2 , V_13 , V_4 , V_115 , V_115 + 1 ) ;
if ( V_116 )
break;
}
if ( ! V_116 ) {
if ( ! V_2 -> V_83 -> V_118 )
V_4 -> V_119 = true ;
return 0 ;
}
if ( V_13 -> V_19 . type == V_120 ) {
F_67 ( V_13 ,
L_3 ,
V_4 -> V_4 . V_43 , V_115 + 1 , V_116 ) ;
V_116 = 0 ;
}
for (; V_115 > V_117 ; V_115 -- )
F_57 ( F_66 ( V_2 , V_13 , V_4 , V_115 , V_115 - 1 ) ) ;
return V_116 ;
}
static int F_68 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_121 * V_122 ;
int V_116 = 0 ;
F_63 ( & V_2 -> V_111 ) ;
V_122 = F_44 ( sizeof( struct V_121 ) , V_123 ) ;
if ( ! V_122 ) {
V_116 = - V_59 ;
goto V_124;
}
if ( F_24 ( V_13 , V_4 -> V_4 . V_43 ) ) {
V_116 = - V_125 ;
goto V_124;
}
V_2 -> V_126 ++ ;
V_2 -> V_127 ++ ;
F_69 () ;
F_70 ( V_4 , V_128 ) ;
V_116 = F_30 ( V_2 , V_4 ) ;
if ( V_116 )
goto V_129;
F_71 ( & V_4 -> V_130 , & V_2 -> V_131 ) ;
V_116 = F_65 ( V_2 , V_13 , V_4 ) ;
if ( V_116 )
goto V_132;
F_70 ( V_4 , V_133 ) ;
F_6 ( V_4 , V_128 ) ;
F_72 ( V_4 ) ;
F_73 ( V_4 ) ;
V_122 -> V_134 = V_2 -> V_127 ;
F_74 ( V_13 -> V_135 , V_4 -> V_4 . V_43 , V_122 , V_123 ) ;
F_15 ( V_122 ) ;
F_28 ( V_13 , L_4 , V_4 -> V_4 . V_43 ) ;
F_20 () ;
F_75 ( & V_2 -> V_111 ) ;
if ( F_5 ( & V_13 -> V_19 ) )
F_76 ( V_13 ) ;
return 0 ;
V_132:
F_1 ( V_2 , V_4 ) ;
F_77 ( & V_4 -> V_130 ) ;
V_129:
V_2 -> V_126 -- ;
F_78 () ;
F_3 ( V_4 ) ;
V_124:
F_75 ( & V_2 -> V_111 ) ;
F_15 ( V_122 ) ;
F_20 () ;
return V_116 ;
}
int F_79 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_116 ;
F_80 () ;
F_81 ( & V_2 -> V_111 ) ;
V_116 = F_58 ( V_4 ) ;
if ( V_116 ) {
F_75 ( & V_2 -> V_111 ) ;
F_20 () ;
goto V_136;
}
V_116 = F_68 ( V_4 ) ;
if ( V_116 )
goto V_136;
return 0 ;
V_136:
F_18 ( V_2 , V_4 ) ;
return V_116 ;
}
int F_82 ( struct V_3 * V_4 )
{
int V_116 = F_79 ( V_4 ) ;
F_23 () ;
return V_116 ;
}
static inline void F_83 ( T_1 * V_137 , T_4 V_138 )
{
V_137 [ V_138 / 8 ] |= ( 1 << ( V_138 % 8 ) ) ;
}
static inline void F_84 ( T_1 * V_137 , T_4 V_138 )
{
V_137 [ V_138 / 8 ] &= ~ ( 1 << ( V_138 % 8 ) ) ;
}
static inline bool F_85 ( T_1 * V_137 , T_4 V_138 )
{
return V_137 [ V_138 / 8 ] & ( 1 << ( V_138 % 8 ) ) ;
}
static unsigned long F_86 ( int V_8 )
{
switch ( V_8 ) {
case V_139 :
return F_87 ( 6 ) | F_87 ( 7 ) ;
case V_140 :
return F_87 ( 4 ) | F_87 ( 5 ) ;
case V_141 :
return F_87 ( 0 ) | F_87 ( 3 ) ;
case V_142 :
return F_87 ( 1 ) | F_87 ( 2 ) ;
default:
F_57 ( 1 ) ;
return 0 ;
}
}
static void F_88 ( struct V_3 * V_4 , bool V_143 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_14 * V_15 ;
bool V_144 = false ;
T_1 V_145 = V_4 -> V_4 . V_146 ;
int V_8 ;
T_4 V_138 = V_4 -> V_4 . V_147 ;
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
if ( F_41 ( & V_2 -> V_31 , V_148 ) )
return;
if ( V_4 -> V_53 )
goto V_149;
if ( V_145 == F_87 ( V_34 ) - 1 )
V_145 = 0 ;
if ( V_143 )
V_145 = F_87 ( V_34 ) - 1 ;
for ( V_8 = 0 ; V_8 < V_34 ; V_8 ++ ) {
unsigned long V_150 ;
if ( V_145 & F_87 ( V_8 ) )
continue;
V_144 |= ! F_90 ( & V_4 -> V_37 [ V_8 ] ) ||
! F_90 ( & V_4 -> V_36 [ V_8 ] ) ;
if ( V_144 )
break;
V_150 = F_86 ( V_8 ) ;
V_144 |=
V_4 -> V_151 & V_150 ;
V_144 |=
V_4 -> V_152 & V_150 ;
}
V_149:
F_91 ( & V_2 -> V_153 ) ;
if ( V_144 == F_85 ( V_15 -> V_137 , V_138 ) )
goto V_154;
if ( V_144 )
F_83 ( V_15 -> V_137 , V_138 ) ;
else
F_84 ( V_15 -> V_137 , V_138 ) ;
if ( V_2 -> V_83 -> V_155 && ! F_57 ( V_4 -> V_53 ) ) {
V_2 -> V_156 = true ;
F_92 ( V_2 , & V_4 -> V_4 , V_144 ) ;
V_2 -> V_156 = false ;
}
V_154:
F_93 ( & V_2 -> V_153 ) ;
}
void F_94 ( struct V_3 * V_4 )
{
F_88 ( V_4 , false ) ;
}
static bool F_95 ( struct V_3 * V_4 , struct V_157 * V_158 )
{
struct V_159 * V_160 ;
int V_161 ;
if ( ! V_158 )
return false ;
V_160 = F_96 ( V_158 ) ;
V_161 = ( V_4 -> V_162 *
V_4 -> V_13 -> V_19 . V_163 . V_164 *
32 / 15625 ) * V_165 ;
if ( V_161 < V_166 )
V_161 = V_166 ;
return F_97 ( V_75 , V_160 -> V_167 . V_75 + V_161 ) ;
}
static bool F_98 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_8 )
{
unsigned long V_168 ;
struct V_157 * V_158 ;
for (; ; ) {
F_99 ( & V_4 -> V_37 [ V_8 ] . V_62 , V_168 ) ;
V_158 = F_100 ( & V_4 -> V_37 [ V_8 ] ) ;
if ( F_95 ( V_4 , V_158 ) )
V_158 = F_101 ( & V_4 -> V_37 [ V_8 ] ) ;
else
V_158 = NULL ;
F_102 ( & V_4 -> V_37 [ V_8 ] . V_62 , V_168 ) ;
if ( ! V_158 )
break;
F_103 ( & V_2 -> V_31 , V_158 ) ;
}
for (; ; ) {
F_99 ( & V_4 -> V_36 [ V_8 ] . V_62 , V_168 ) ;
V_158 = F_100 ( & V_4 -> V_36 [ V_8 ] ) ;
if ( F_95 ( V_4 , V_158 ) )
V_158 = F_101 ( & V_4 -> V_36 [ V_8 ] ) ;
else
V_158 = NULL ;
F_102 ( & V_4 -> V_36 [ V_8 ] . V_62 , V_168 ) ;
if ( ! V_158 )
break;
V_2 -> V_35 -- ;
F_104 ( V_4 -> V_13 , L_5 ,
V_4 -> V_4 . V_43 ) ;
F_103 ( & V_2 -> V_31 , V_158 ) ;
}
F_94 ( V_4 ) ;
return ! ( F_90 ( & V_4 -> V_36 [ V_8 ] ) &&
F_90 ( & V_4 -> V_37 [ V_8 ] ) ) ;
}
static bool F_105 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_169 = false ;
int V_8 ;
if ( ! V_4 -> V_13 -> V_22 &&
! F_5 ( & V_4 -> V_13 -> V_19 ) )
return false ;
for ( V_8 = 0 ; V_8 < V_34 ; V_8 ++ )
V_169 |=
F_98 ( V_2 , V_4 , V_8 ) ;
return V_169 ;
}
static int T_5 F_106 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
int V_170 ;
F_80 () ;
if ( ! V_4 )
return - V_171 ;
V_2 = V_4 -> V_2 ;
V_13 = V_4 -> V_13 ;
F_63 ( & V_2 -> V_111 ) ;
F_70 ( V_4 , V_128 ) ;
F_107 ( V_4 , V_172 ) ;
V_170 = F_1 ( V_2 , V_4 ) ;
if ( F_57 ( V_170 ) )
return V_170 ;
if ( F_4 ( V_4 , V_173 ) ) {
F_108 ( V_2 , V_13 , & V_4 -> V_4 ) ;
F_6 ( V_4 , V_173 ) ;
}
F_77 ( & V_4 -> V_130 ) ;
V_4 -> V_174 = true ;
F_109 ( V_2 , V_4 -> V_13 , V_4 ) ;
if ( V_13 -> V_19 . type == V_21 &&
F_110 ( V_13 -> V_23 . V_175 . V_4 ) == V_4 )
F_111 ( V_13 -> V_23 . V_175 . V_4 , NULL ) ;
return 0 ;
}
static void F_112 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_121 * V_122 ;
int V_170 ;
F_80 () ;
F_63 ( & V_2 -> V_111 ) ;
F_113 ( V_2 , V_4 ) ;
F_88 ( V_4 , true ) ;
V_4 -> V_53 = true ;
V_2 -> V_126 -- ;
V_2 -> V_127 ++ ;
while ( V_4 -> V_76 > V_77 ) {
V_170 = F_114 ( V_4 , V_4 -> V_76 - 1 ) ;
if ( V_170 ) {
F_89 ( 1 ) ;
break;
}
}
if ( V_4 -> V_119 ) {
V_170 = F_66 ( V_2 , V_13 , V_4 , V_77 ,
V_117 ) ;
F_89 ( V_170 != 0 ) ;
}
F_28 ( V_13 , L_6 , V_4 -> V_4 . V_43 ) ;
V_122 = F_44 ( sizeof( * V_122 ) , V_123 ) ;
if ( V_122 )
F_115 ( V_4 , V_122 ) ;
F_116 ( V_13 -> V_135 , V_4 -> V_4 . V_43 , V_122 , V_123 ) ;
F_15 ( V_122 ) ;
F_117 ( V_4 ) ;
F_118 ( V_4 ) ;
F_17 ( V_4 ) ;
}
int T_5 F_119 ( struct V_3 * V_4 )
{
int V_116 = F_106 ( V_4 ) ;
if ( V_116 )
return V_116 ;
F_78 () ;
F_112 ( V_4 ) ;
return 0 ;
}
int F_120 ( struct V_12 * V_13 , const T_1 * V_43 )
{
struct V_3 * V_4 ;
int V_170 ;
F_81 ( & V_13 -> V_2 -> V_111 ) ;
V_4 = F_19 ( V_13 , V_43 ) ;
V_170 = F_119 ( V_4 ) ;
F_75 ( & V_13 -> V_2 -> V_111 ) ;
return V_170 ;
}
int F_121 ( struct V_12 * V_13 ,
const T_1 * V_43 )
{
struct V_3 * V_4 ;
int V_170 ;
F_81 ( & V_13 -> V_2 -> V_111 ) ;
V_4 = F_24 ( V_13 , V_43 ) ;
V_170 = F_119 ( V_4 ) ;
F_75 ( & V_13 -> V_2 -> V_111 ) ;
return V_170 ;
}
static void F_122 ( unsigned long V_176 )
{
struct V_1 * V_2 = (struct V_1 * ) V_176 ;
struct V_3 * V_4 ;
bool V_177 = false ;
F_20 () ;
F_26 (sta, &local->sta_list, list)
if ( F_105 ( V_2 , V_4 ) )
V_177 = true ;
F_23 () ;
if ( V_2 -> V_178 )
return;
if ( ! V_177 )
return;
F_123 ( & V_2 -> V_179 ,
F_124 ( V_75 + V_180 ) ) ;
}
T_6 F_125 ( const void * V_181 , T_6 V_182 , T_6 V_183 )
{
return F_126 ( V_181 , V_72 , V_183 ) ;
}
int F_127 ( struct V_1 * V_2 )
{
int V_116 ;
V_116 = F_128 ( & V_2 -> V_5 , & V_7 ) ;
if ( V_116 )
return V_116 ;
F_45 ( & V_2 -> V_153 ) ;
F_47 ( & V_2 -> V_111 ) ;
F_129 ( & V_2 -> V_131 ) ;
F_130 ( & V_2 -> V_179 , F_122 ,
( unsigned long ) V_2 ) ;
return 0 ;
}
void F_131 ( struct V_1 * V_2 )
{
F_132 ( & V_2 -> V_179 ) ;
F_133 ( & V_2 -> V_5 ) ;
}
int F_134 ( struct V_12 * V_13 , bool V_184 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 , * V_45 ;
F_135 ( V_185 ) ;
int V_170 = 0 ;
F_80 () ;
F_57 ( V_184 && V_13 -> V_19 . type != V_20 ) ;
F_57 ( V_184 && ! V_13 -> V_22 ) ;
F_81 ( & V_2 -> V_111 ) ;
F_136 (sta, tmp, &local->sta_list, list) {
if ( V_13 == V_4 -> V_13 ||
( V_184 && V_13 -> V_22 == V_4 -> V_13 -> V_22 ) ) {
if ( ! F_57 ( F_106 ( V_4 ) ) )
F_137 ( & V_4 -> V_185 , & V_185 ) ;
V_170 ++ ;
}
}
if ( ! F_138 ( & V_185 ) ) {
F_78 () ;
F_136 (sta, tmp, &free_list, free_list)
F_112 ( V_4 ) ;
}
F_75 ( & V_2 -> V_111 ) ;
return V_170 ;
}
void F_139 ( struct V_12 * V_13 ,
unsigned long V_186 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 , * V_45 ;
F_81 ( & V_2 -> V_111 ) ;
F_136 (sta, tmp, &local->sta_list, list) {
if ( V_13 != V_4 -> V_13 )
continue;
if ( F_97 ( V_75 , V_4 -> V_73 . V_74 + V_186 ) ) {
F_28 ( V_4 -> V_13 , L_7 ,
V_4 -> V_4 . V_43 ) ;
if ( F_5 ( & V_13 -> V_19 ) &&
F_4 ( V_4 , V_16 ) )
F_7 ( & V_13 -> V_23 . V_24 . V_15 . V_25 ) ;
F_57 ( F_119 ( V_4 ) ) ;
}
}
F_75 ( & V_2 -> V_111 ) ;
}
struct V_187 * F_64 ( struct V_60 * V_31 ,
const T_1 * V_43 ,
const T_1 * V_188 )
{
struct V_1 * V_2 = F_140 ( V_31 ) ;
struct V_3 * V_4 ;
struct V_44 * V_45 ;
const struct V_46 * V_47 ;
V_47 = F_21 ( V_2 -> V_5 . V_47 , & V_2 -> V_5 ) ;
F_22 (local, tbl, addr, sta, tmp) {
if ( V_188 &&
! F_61 ( V_4 -> V_13 -> V_19 . V_43 , V_188 ) )
continue;
if ( ! V_4 -> V_119 )
return NULL ;
return & V_4 -> V_4 ;
}
return NULL ;
}
struct V_187 * F_141 ( struct V_189 * V_19 ,
const T_1 * V_43 )
{
struct V_3 * V_4 ;
if ( ! V_19 )
return NULL ;
V_4 = F_24 ( F_142 ( V_19 ) , V_43 ) ;
if ( ! V_4 )
return NULL ;
if ( ! V_4 -> V_119 )
return NULL ;
return & V_4 -> V_4 ;
}
void F_35 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_190 V_42 ;
int V_191 = 0 , V_192 = 0 , V_8 , V_9 ;
unsigned long V_168 ;
struct V_14 * V_15 ;
if ( V_13 -> V_19 . type == V_21 )
V_13 = F_33 ( V_13 -> V_22 , struct V_12 ,
V_23 . V_193 ) ;
if ( V_13 -> V_19 . type == V_20 )
V_15 = & V_13 -> V_22 -> V_15 ;
else if ( F_5 ( & V_13 -> V_19 ) )
V_15 = & V_13 -> V_23 . V_24 . V_15 ;
else
return;
F_6 ( V_4 , V_194 ) ;
F_143 ( F_144 ( V_39 ) > 1 ) ;
V_4 -> V_151 = 0 ;
V_4 -> V_152 = 0 ;
if ( ! F_41 ( & V_2 -> V_31 , V_148 ) )
F_145 ( V_2 , V_13 , V_195 , & V_4 -> V_4 ) ;
if ( V_4 -> V_4 . V_26 [ 0 ] ) {
for ( V_9 = 0 ; V_9 < F_8 ( V_4 -> V_4 . V_26 ) ; V_9 ++ ) {
struct V_27 * V_28 = F_9 ( V_4 -> V_4 . V_26 [ V_9 ] ) ;
if ( ! F_10 ( & V_28 -> V_30 ) )
continue;
F_146 ( V_2 , V_28 ) ;
}
}
F_54 ( & V_42 ) ;
F_147 ( & V_4 -> V_63 ) ;
for ( V_8 = 0 ; V_8 < V_34 ; V_8 ++ ) {
int V_196 = F_10 ( & V_42 ) , V_45 ;
F_99 ( & V_4 -> V_37 [ V_8 ] . V_62 , V_168 ) ;
F_148 ( & V_4 -> V_37 [ V_8 ] , & V_42 ) ;
F_102 ( & V_4 -> V_37 [ V_8 ] . V_62 , V_168 ) ;
V_45 = F_10 ( & V_42 ) ;
V_191 += V_45 - V_196 ;
V_196 = V_45 ;
F_99 ( & V_4 -> V_36 [ V_8 ] . V_62 , V_168 ) ;
F_148 ( & V_4 -> V_36 [ V_8 ] , & V_42 ) ;
F_102 ( & V_4 -> V_36 [ V_8 ] . V_62 , V_168 ) ;
V_45 = F_10 ( & V_42 ) ;
V_192 += V_45 - V_196 ;
}
F_149 ( V_2 , & V_42 ) ;
F_6 ( V_4 , V_18 ) ;
F_6 ( V_4 , V_54 ) ;
F_6 ( V_4 , V_55 ) ;
F_150 ( & V_4 -> V_63 ) ;
F_7 ( & V_15 -> V_25 ) ;
if ( ! F_5 ( & V_13 -> V_19 ) &&
! F_151 ( V_4 -> V_104 ,
V_13 -> V_92 ) &&
V_4 -> V_104 != V_13 -> V_22 -> V_197 &&
F_152 ( V_4 ) != 1 ) {
F_153 ( V_13 ,
L_8 ,
V_4 -> V_4 . V_43 ) ;
F_154 ( V_13 , V_13 -> V_22 -> V_197 ,
V_4 -> V_4 . V_43 ,
V_13 -> V_19 . V_163 . V_198 ) ;
}
V_2 -> V_35 -= V_192 ;
F_94 ( V_4 ) ;
F_104 ( V_13 ,
L_9 ,
V_4 -> V_4 . V_43 , V_4 -> V_4 . V_147 , V_191 , V_192 ) ;
F_155 ( V_4 ) ;
}
static void F_156 ( struct V_3 * V_4 , int V_199 ,
enum V_200 V_201 ,
bool V_202 , bool V_203 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_204 * V_205 ;
struct V_157 * V_158 ;
int V_86 = sizeof( * V_205 ) ;
T_7 V_206 ;
bool V_207 = V_4 -> V_4 . V_208 ;
struct V_159 * V_160 ;
struct V_209 * V_210 ;
if ( V_207 ) {
V_206 = F_55 ( V_211 |
V_212 |
V_213 ) ;
} else {
V_86 -= 2 ;
V_206 = F_55 ( V_211 |
V_214 |
V_213 ) ;
}
V_158 = F_157 ( V_2 -> V_31 . V_215 + V_86 ) ;
if ( ! V_158 )
return;
F_158 ( V_158 , V_2 -> V_31 . V_215 ) ;
V_205 = ( void * ) F_159 ( V_158 , V_86 ) ;
V_205 -> V_216 = V_206 ;
V_205 -> V_217 = 0 ;
memcpy ( V_205 -> V_218 , V_4 -> V_4 . V_43 , V_72 ) ;
memcpy ( V_205 -> V_219 , V_13 -> V_19 . V_43 , V_72 ) ;
memcpy ( V_205 -> V_220 , V_13 -> V_19 . V_43 , V_72 ) ;
V_205 -> V_221 = 0 ;
V_158 -> V_222 = V_199 ;
F_160 ( V_158 , V_223 [ V_199 ] ) ;
if ( V_207 ) {
V_205 -> V_224 = F_55 ( V_199 ) ;
if ( V_201 == V_225 ) {
V_205 -> V_224 |=
F_55 ( V_226 ) ;
if ( V_203 )
V_205 -> V_216 |=
F_55 ( V_227 ) ;
}
}
V_160 = F_96 ( V_158 ) ;
V_160 -> V_168 |= V_228 |
V_229 |
V_230 ;
V_160 -> V_167 . V_168 |= V_231 ;
if ( V_202 )
F_161 ( V_2 , V_4 , F_87 ( V_199 ) , 1 ,
V_201 , false ) ;
V_158 -> V_135 = V_13 -> V_135 ;
F_20 () ;
V_210 = F_162 ( V_13 -> V_19 . V_210 ) ;
if ( F_57 ( ! V_210 ) ) {
F_23 () ;
F_163 ( V_158 ) ;
return;
}
V_160 -> V_232 = V_210 -> V_233 . V_234 -> V_232 ;
F_164 ( V_13 , V_4 , V_158 ) ;
F_23 () ;
}
static int F_165 ( unsigned long V_150 )
{
if ( V_150 & 0xF8 )
return F_166 ( V_150 ) - 1 ;
if ( V_150 & F_87 ( 0 ) )
return 0 ;
return F_166 ( V_150 ) - 1 ;
}
static bool
F_167 ( struct V_3 * V_4 , T_1 V_235 ,
enum V_200 V_201 ,
unsigned long V_236 )
{
int V_8 ;
if ( V_201 == V_237 &&
F_168 ( V_236 ) > 1 )
return true ;
for ( V_8 = 0 ; V_8 < V_34 ; V_8 ++ ) {
if ( V_235 & F_87 ( V_8 ) )
continue;
if ( ! F_90 ( & V_4 -> V_37 [ V_8 ] ) ||
! F_90 ( & V_4 -> V_36 [ V_8 ] ) )
return true ;
}
return false ;
}
static void
F_169 ( struct V_3 * V_4 , int V_238 , T_1 V_235 ,
enum V_200 V_201 ,
struct V_190 * V_239 ,
unsigned long * V_236 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_34 ; V_8 ++ ) {
unsigned long V_150 ;
if ( V_235 & F_87 ( V_8 ) )
continue;
V_150 = F_86 ( V_8 ) ;
if ( F_90 ( V_239 ) ) {
* V_236 |=
V_4 -> V_151 & V_150 ;
* V_236 |= V_4 -> V_152 & V_150 ;
}
if ( ! * V_236 ) {
struct V_157 * V_158 ;
while ( V_238 > 0 ) {
V_158 = F_170 ( & V_4 -> V_37 [ V_8 ] ) ;
if ( ! V_158 ) {
V_158 = F_170 (
& V_4 -> V_36 [ V_8 ] ) ;
if ( V_158 )
V_2 -> V_35 -- ;
}
if ( ! V_158 )
break;
V_238 -- ;
F_171 ( V_239 , V_158 ) ;
}
}
if ( ! F_90 ( & V_4 -> V_37 [ V_8 ] ) ||
! F_90 ( & V_4 -> V_36 [ V_8 ] ) )
break;
}
}
static void
F_172 ( struct V_3 * V_4 ,
int V_238 , T_1 V_235 ,
enum V_200 V_201 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
unsigned long V_236 = 0 ;
struct V_190 V_239 ;
bool V_203 ;
F_70 ( V_4 , V_194 ) ;
F_173 ( & V_239 ) ;
F_169 ( V_4 , V_238 , V_235 , V_201 ,
& V_239 , & V_236 ) ;
V_203 = F_167 ( V_4 , V_235 , V_201 , V_236 ) ;
if ( V_236 && V_201 == V_237 )
V_236 =
F_87 ( F_165 ( V_236 ) ) ;
if ( F_90 ( & V_239 ) && ! V_236 ) {
int V_199 ;
V_199 = 7 - ( ( F_174 ( ~ V_235 ) - 1 ) << 1 ) ;
F_156 ( V_4 , V_199 , V_201 , true , false ) ;
} else if ( ! V_236 ) {
struct V_190 V_42 ;
struct V_157 * V_158 ;
int V_240 = 0 ;
T_4 V_150 = 0 ;
bool V_241 = false ;
F_54 ( & V_42 ) ;
while ( ( V_158 = F_101 ( & V_239 ) ) ) {
struct V_159 * V_160 = F_96 ( V_158 ) ;
struct V_242 * V_243 = ( void * ) V_158 -> V_176 ;
T_1 * V_244 = NULL ;
V_240 ++ ;
V_160 -> V_168 |= V_228 ;
V_160 -> V_167 . V_168 |= V_231 ;
if ( V_203 || ! F_90 ( & V_239 ) )
V_243 -> V_216 |=
F_55 ( V_227 ) ;
else
V_243 -> V_216 &=
F_55 ( ~ V_227 ) ;
if ( F_175 ( V_243 -> V_216 ) ||
F_176 ( V_243 -> V_216 ) )
V_244 = F_177 ( V_243 ) ;
V_150 |= F_87 ( V_158 -> V_222 ) ;
F_171 ( & V_42 , V_158 ) ;
if ( ! F_90 ( & V_239 ) )
continue;
if ( V_201 != V_225 ) {
V_160 -> V_168 |= V_229 |
V_230 ;
break;
}
if ( V_244 ) {
* V_244 |= V_226 ;
V_160 -> V_168 |= V_229 |
V_230 ;
} else {
V_243 -> V_216 |=
F_55 ( V_227 ) ;
V_241 = true ;
V_240 ++ ;
}
break;
}
F_161 ( V_2 , V_4 , V_150 , V_240 ,
V_201 , V_203 ) ;
F_149 ( V_2 , & V_42 ) ;
if ( V_241 )
F_156 (
V_4 , F_165 ( V_150 ) ,
V_201 , false , false ) ;
F_94 ( V_4 ) ;
} else {
unsigned long V_150 = V_4 -> V_152 & V_236 ;
int V_199 ;
F_178 ( V_2 , V_4 , V_236 ,
V_238 , V_201 , V_203 ) ;
if ( ! V_4 -> V_4 . V_26 [ 0 ] )
return;
for ( V_199 = 0 ; V_199 < F_8 ( V_4 -> V_4 . V_26 ) ; V_199 ++ ) {
struct V_27 * V_28 = F_9 ( V_4 -> V_4 . V_26 [ V_199 ] ) ;
if ( ! ( V_150 & F_87 ( V_199 ) ) || F_10 ( & V_28 -> V_30 ) )
continue;
F_94 ( V_4 ) ;
break;
}
}
}
void F_37 ( struct V_3 * V_4 )
{
T_1 V_245 = V_4 -> V_4 . V_146 ;
if ( V_245 == F_87 ( V_34 ) - 1 )
V_245 = 0 ;
F_172 ( V_4 , 1 , V_245 ,
V_237 ) ;
}
void F_38 ( struct V_3 * V_4 )
{
int V_238 = V_4 -> V_4 . V_246 ;
T_1 V_247 = V_4 -> V_4 . V_146 ;
if ( ! V_247 )
return;
switch ( V_4 -> V_4 . V_246 ) {
case 1 :
V_238 = 2 ;
break;
case 2 :
V_238 = 4 ;
break;
case 3 :
V_238 = 6 ;
break;
case 0 :
V_238 = 128 ;
break;
}
F_172 ( V_4 , V_238 , ~ V_247 ,
V_225 ) ;
}
void F_179 ( struct V_60 * V_31 ,
struct V_187 * V_248 , bool V_249 )
{
struct V_3 * V_4 = F_33 ( V_248 , struct V_3 , V_4 ) ;
F_180 ( V_4 -> V_2 , V_248 , V_249 ) ;
if ( V_249 ) {
F_70 ( V_4 , V_17 ) ;
F_181 ( V_4 ) ;
return;
}
if ( ! F_4 ( V_4 , V_17 ) )
return;
if ( ! F_4 ( V_4 , V_16 ) ) {
F_70 ( V_4 , V_18 ) ;
F_6 ( V_4 , V_17 ) ;
F_182 ( V_31 , & V_4 -> V_38 ) ;
} else if ( F_4 ( V_4 , V_54 ) ||
F_4 ( V_4 , V_55 ) ) {
F_6 ( V_4 , V_17 ) ;
F_182 ( V_31 , & V_4 -> V_38 ) ;
} else {
F_6 ( V_4 , V_17 ) ;
F_155 ( V_4 ) ;
}
}
void F_183 ( struct V_187 * V_248 )
{
struct V_3 * V_4 = F_33 ( V_248 , struct V_3 , V_4 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_184 ( V_2 , V_248 ) ;
F_6 ( V_4 , V_194 ) ;
}
void F_185 ( struct V_187 * V_248 , int V_199 )
{
struct V_3 * V_4 = F_33 ( V_248 , struct V_3 , V_4 ) ;
enum V_200 V_201 ;
bool V_203 ;
F_186 ( V_4 -> V_2 , V_248 , V_199 ) ;
V_201 = V_225 ;
V_203 = F_167 ( V_4 , ~ V_4 -> V_4 . V_146 ,
V_201 , 0 ) ;
F_156 ( V_4 , V_199 , V_201 , false , V_203 ) ;
}
void F_187 ( struct V_187 * V_248 ,
T_1 V_199 , bool V_192 )
{
struct V_3 * V_4 = F_33 ( V_248 , struct V_3 , V_4 ) ;
if ( F_57 ( V_199 >= V_39 ) )
return;
F_188 ( V_4 -> V_2 , V_248 , V_199 , V_192 ) ;
if ( V_192 )
F_189 ( V_199 , & V_4 -> V_151 ) ;
else
F_190 ( V_199 , & V_4 -> V_151 ) ;
F_94 ( V_4 ) ;
}
int F_114 ( struct V_3 * V_4 ,
enum V_114 V_250 )
{
F_80 () ;
if ( V_4 -> V_76 == V_250 )
return 0 ;
switch ( V_250 ) {
case V_77 :
if ( V_4 -> V_76 != V_251 )
return - V_110 ;
break;
case V_251 :
if ( V_4 -> V_76 != V_77 &&
V_4 -> V_76 != V_252 )
return - V_110 ;
break;
case V_252 :
if ( V_4 -> V_76 != V_251 &&
V_4 -> V_76 != V_253 )
return - V_110 ;
break;
case V_253 :
if ( V_4 -> V_76 != V_252 )
return - V_110 ;
break;
default:
F_191 ( 1 , L_10 , V_250 ) ;
return - V_110 ;
}
F_28 ( V_4 -> V_13 , L_11 ,
V_4 -> V_4 . V_43 , V_250 ) ;
if ( F_4 ( V_4 , V_133 ) ) {
int V_116 = F_66 ( V_4 -> V_2 , V_4 -> V_13 , V_4 ,
V_4 -> V_76 , V_250 ) ;
if ( V_116 )
return V_116 ;
}
switch ( V_250 ) {
case V_77 :
if ( V_4 -> V_76 == V_251 )
F_190 ( V_254 , & V_4 -> V_255 ) ;
break;
case V_251 :
if ( V_4 -> V_76 == V_77 ) {
F_189 ( V_254 , & V_4 -> V_255 ) ;
} else if ( V_4 -> V_76 == V_252 ) {
F_190 ( V_256 , & V_4 -> V_255 ) ;
F_192 ( V_4 -> V_13 ) ;
}
break;
case V_252 :
if ( V_4 -> V_76 == V_251 ) {
F_189 ( V_256 , & V_4 -> V_255 ) ;
F_192 ( V_4 -> V_13 ) ;
} else if ( V_4 -> V_76 == V_253 ) {
if ( V_4 -> V_13 -> V_19 . type == V_20 ||
( V_4 -> V_13 -> V_19 . type == V_21 &&
! V_4 -> V_13 -> V_23 . V_175 . V_4 ) )
F_7 ( & V_4 -> V_13 -> V_22 -> V_257 ) ;
F_190 ( V_258 , & V_4 -> V_255 ) ;
F_181 ( V_4 ) ;
}
break;
case V_253 :
if ( V_4 -> V_76 == V_252 ) {
if ( V_4 -> V_13 -> V_19 . type == V_20 ||
( V_4 -> V_13 -> V_19 . type == V_21 &&
! V_4 -> V_13 -> V_23 . V_175 . V_4 ) )
F_193 ( & V_4 -> V_13 -> V_22 -> V_257 ) ;
F_189 ( V_258 , & V_4 -> V_255 ) ;
F_155 ( V_4 ) ;
}
break;
default:
break;
}
V_4 -> V_76 = V_250 ;
return 0 ;
}
T_1 F_152 ( struct V_3 * V_4 )
{
struct V_259 * V_99 = & V_4 -> V_4 . V_99 ;
T_1 V_260 ;
if ( ! V_4 -> V_4 . V_99 . V_261 )
return 1 ;
if ( V_4 -> V_4 . V_262 . V_263 ) {
int V_9 ;
T_4 V_264 =
F_194 ( V_4 -> V_4 . V_262 . V_265 . V_264 ) ;
for ( V_9 = 7 ; V_9 >= 0 ; V_9 -- )
if ( ( V_264 & ( 0x3 << ( V_9 * 2 ) ) ) !=
V_266 )
return V_9 + 1 ;
}
if ( V_99 -> V_267 . V_268 [ 3 ] )
V_260 = 4 ;
else if ( V_99 -> V_267 . V_268 [ 2 ] )
V_260 = 3 ;
else if ( V_99 -> V_267 . V_268 [ 1 ] )
V_260 = 2 ;
else
V_260 = 1 ;
if ( ! ( V_99 -> V_267 . V_269 & V_270 ) )
return V_260 ;
return ( ( V_99 -> V_267 . V_269 & V_271 )
>> V_272 ) + 1 ;
}
static void F_195 ( struct V_3 * V_4 , struct V_273 * V_274 )
{
V_274 -> V_168 = 0 ;
if ( V_4 -> V_73 . V_275 & V_276 ) {
V_274 -> V_168 |= V_277 ;
V_274 -> V_267 = V_4 -> V_73 . V_278 ;
} else if ( V_4 -> V_73 . V_275 & V_279 ) {
V_274 -> V_168 |= V_280 ;
V_274 -> V_281 = V_4 -> V_73 . V_282 ;
V_274 -> V_267 = V_4 -> V_73 . V_278 ;
} else {
struct V_94 * V_95 ;
int V_283 = F_196 ( & V_4 -> V_13 -> V_19 ) ;
T_4 V_284 ;
V_95 = V_4 -> V_2 -> V_31 . V_96 -> V_97 [
F_56 ( V_4 -> V_13 ) ] ;
V_284 = V_95 -> V_285 [ V_4 -> V_73 . V_278 ] . V_286 ;
V_274 -> V_287 = F_197 ( V_284 , 1 << V_283 ) ;
}
if ( V_4 -> V_73 . V_275 & V_288 )
V_274 -> V_168 |= V_289 ;
if ( V_4 -> V_73 . V_275 & V_290 )
V_274 -> V_291 = V_292 ;
else if ( V_4 -> V_73 . V_275 & V_293 )
V_274 -> V_291 = V_294 ;
else if ( V_4 -> V_73 . V_275 & V_295 )
V_274 -> V_291 = V_296 ;
else if ( V_4 -> V_73 . V_297 & V_298 )
V_274 -> V_291 = V_299 ;
else if ( V_4 -> V_73 . V_297 & V_300 )
V_274 -> V_291 = V_301 ;
else
V_274 -> V_291 = V_302 ;
}
void F_115 ( struct V_3 * V_4 , struct V_121 * V_122 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_303 * V_304 = NULL ;
T_6 V_305 = 0 ;
int V_9 , V_8 ;
if ( F_4 ( V_4 , V_306 ) )
V_304 = V_2 -> V_49 ;
V_122 -> V_134 = V_13 -> V_2 -> V_127 ;
if ( V_13 -> V_19 . type == V_307 )
V_122 -> V_308 = V_13 -> V_23 . V_309 . V_310 ;
F_198 ( V_2 , V_13 , & V_4 -> V_4 , V_122 ) ;
V_122 -> V_311 |= F_87 ( V_312 ) |
F_87 ( V_313 ) |
F_87 ( V_314 ) |
F_87 ( V_315 ) |
F_87 ( V_316 ) ;
if ( V_13 -> V_19 . type == V_307 ) {
V_122 -> V_317 = V_13 -> V_23 . V_309 . V_317 ;
V_122 -> V_311 |= F_87 ( V_318 ) ;
}
V_122 -> V_319 = F_49 () - V_4 -> V_80 ;
V_122 -> V_320 =
F_199 ( V_75 - V_4 -> V_73 . V_74 ) ;
if ( ! ( V_122 -> V_311 & ( F_87 ( V_321 ) |
F_87 ( V_322 ) ) ) ) {
V_122 -> V_323 = 0 ;
for ( V_8 = 0 ; V_8 < V_34 ; V_8 ++ )
V_122 -> V_323 += V_4 -> V_324 . V_325 [ V_8 ] ;
V_122 -> V_311 |= F_87 ( V_321 ) ;
}
if ( ! ( V_122 -> V_311 & F_87 ( V_326 ) ) ) {
V_122 -> V_327 = 0 ;
for ( V_8 = 0 ; V_8 < V_34 ; V_8 ++ )
V_122 -> V_327 += V_4 -> V_324 . V_328 [ V_8 ] ;
V_122 -> V_311 |= F_87 ( V_326 ) ;
}
if ( ! ( V_122 -> V_311 & ( F_87 ( V_329 ) |
F_87 ( V_330 ) ) ) ) {
V_122 -> V_331 = V_4 -> V_73 . V_325 ;
V_122 -> V_311 |= F_87 ( V_329 ) ;
}
if ( ! ( V_122 -> V_311 & F_87 ( V_332 ) ) ) {
V_122 -> V_333 = V_4 -> V_73 . V_328 ;
V_122 -> V_311 |= F_87 ( V_332 ) ;
}
if ( ! ( V_122 -> V_311 & F_87 ( V_334 ) ) ) {
V_122 -> V_335 = V_4 -> V_336 . V_337 ;
V_122 -> V_311 |= F_87 ( V_334 ) ;
}
if ( ! ( V_122 -> V_311 & F_87 ( V_338 ) ) ) {
V_122 -> V_339 = V_4 -> V_336 . V_340 ;
V_122 -> V_311 |= F_87 ( V_338 ) ;
}
V_122 -> V_341 = V_4 -> V_73 . V_342 ;
if ( V_13 -> V_19 . type == V_307 &&
! ( V_13 -> V_19 . V_343 & V_344 ) ) {
V_122 -> V_311 |= F_87 ( V_345 ) |
F_87 ( V_346 ) ;
V_122 -> V_347 = F_200 ( & V_13 -> V_19 ) ;
}
if ( F_41 ( & V_4 -> V_2 -> V_31 , V_348 ) ||
F_41 ( & V_4 -> V_2 -> V_31 , V_349 ) ) {
if ( ! ( V_122 -> V_311 & F_87 ( V_350 ) ) ) {
V_122 -> signal = ( V_351 ) V_4 -> V_73 . V_352 ;
V_122 -> V_311 |= F_87 ( V_350 ) ;
}
if ( ! ( V_122 -> V_311 & F_87 ( V_353 ) ) ) {
V_122 -> V_354 =
- F_201 ( & V_4 -> V_73 . V_81 ) ;
V_122 -> V_311 |= F_87 ( V_353 ) ;
}
}
if ( V_4 -> V_73 . V_355 &&
! ( V_122 -> V_311 & ( F_87 ( V_356 ) |
F_87 ( V_357 ) ) ) ) {
V_122 -> V_311 |= F_87 ( V_356 ) |
F_87 ( V_357 ) ;
V_122 -> V_355 = V_4 -> V_73 . V_355 ;
for ( V_9 = 0 ; V_9 < F_8 ( V_122 -> V_358 ) ; V_9 ++ ) {
V_122 -> V_358 [ V_9 ] =
V_4 -> V_73 . V_359 [ V_9 ] ;
V_122 -> V_82 [ V_9 ] =
- F_201 ( & V_4 -> V_73 . V_82 [ V_9 ] ) ;
}
}
if ( ! ( V_122 -> V_311 & F_87 ( V_360 ) ) ) {
F_202 ( V_4 , & V_4 -> V_324 . V_361 ,
& V_122 -> V_362 ) ;
V_122 -> V_311 |= F_87 ( V_360 ) ;
}
if ( ! ( V_122 -> V_311 & F_87 ( V_363 ) ) ) {
F_195 ( V_4 , & V_122 -> V_364 ) ;
V_122 -> V_311 |= F_87 ( V_363 ) ;
}
V_122 -> V_311 |= F_87 ( V_365 ) ;
for ( V_9 = 0 ; V_9 < V_39 + 1 ; V_9 ++ ) {
struct V_366 * V_367 = & V_122 -> V_368 [ V_9 ] ;
if ( ! ( V_367 -> V_311 & F_87 ( V_369 ) ) ) {
V_367 -> V_311 |= F_87 ( V_369 ) ;
V_367 -> V_370 = V_4 -> V_73 . V_371 [ V_9 ] ;
}
if ( ! ( V_367 -> V_311 & F_87 ( V_372 ) ) ) {
V_367 -> V_311 |= F_87 ( V_372 ) ;
V_367 -> V_373 = V_4 -> V_324 . V_371 [ V_9 ] ;
}
if ( ! ( V_367 -> V_311 &
F_87 ( V_374 ) ) &&
F_41 ( & V_2 -> V_31 , V_375 ) ) {
V_367 -> V_311 |=
F_87 ( V_374 ) ;
V_367 -> V_376 =
V_4 -> V_336 . V_377 [ V_9 ] ;
}
if ( ! ( V_367 -> V_311 &
F_87 ( V_378 ) ) &&
F_41 ( & V_2 -> V_31 , V_375 ) ) {
V_367 -> V_311 |=
F_87 ( V_378 ) ;
V_367 -> V_379 =
V_4 -> V_336 . V_380 [ V_9 ] ;
}
}
if ( F_5 ( & V_13 -> V_19 ) ) {
#ifdef F_29
V_122 -> V_311 |= F_87 ( V_381 ) |
F_87 ( V_382 ) |
F_87 ( V_383 ) |
F_87 ( V_384 ) |
F_87 ( V_385 ) |
F_87 ( V_386 ) ;
V_122 -> V_387 = V_4 -> V_24 -> V_387 ;
V_122 -> V_388 = V_4 -> V_24 -> V_388 ;
V_122 -> V_389 = V_4 -> V_24 -> V_389 ;
if ( F_4 ( V_4 , V_390 ) ) {
V_122 -> V_311 |= F_87 ( V_391 ) ;
V_122 -> V_392 = V_4 -> V_24 -> V_392 ;
}
V_122 -> V_393 = V_4 -> V_24 -> V_393 ;
V_122 -> V_394 = V_4 -> V_24 -> V_394 ;
V_122 -> V_70 = V_4 -> V_24 -> V_70 ;
#endif
}
V_122 -> V_395 . V_168 = 0 ;
if ( V_13 -> V_19 . V_163 . V_396 )
V_122 -> V_395 . V_168 |= V_397 ;
if ( V_13 -> V_19 . V_163 . V_398 )
V_122 -> V_395 . V_168 |= V_399 ;
if ( V_13 -> V_19 . V_163 . V_400 )
V_122 -> V_395 . V_168 |= V_401 ;
V_122 -> V_395 . V_402 = V_13 -> V_19 . V_163 . V_402 ;
V_122 -> V_395 . V_403 = V_13 -> V_19 . V_163 . V_164 ;
V_122 -> V_404 . V_405 = 0 ;
V_122 -> V_404 . V_406 = F_87 ( V_407 ) |
F_87 ( V_408 ) |
F_87 ( V_409 ) |
F_87 ( V_410 ) |
F_87 ( V_411 ) |
F_87 ( V_412 ) |
F_87 ( V_413 ) ;
if ( F_4 ( V_4 , V_258 ) )
V_122 -> V_404 . V_405 |= F_87 ( V_407 ) ;
if ( F_4 ( V_4 , V_414 ) )
V_122 -> V_404 . V_405 |= F_87 ( V_408 ) ;
if ( V_4 -> V_4 . V_208 )
V_122 -> V_404 . V_405 |= F_87 ( V_409 ) ;
if ( F_4 ( V_4 , V_415 ) )
V_122 -> V_404 . V_405 |= F_87 ( V_410 ) ;
if ( F_4 ( V_4 , V_254 ) )
V_122 -> V_404 . V_405 |= F_87 ( V_411 ) ;
if ( F_4 ( V_4 , V_256 ) )
V_122 -> V_404 . V_405 |= F_87 ( V_412 ) ;
if ( F_4 ( V_4 , V_416 ) )
V_122 -> V_404 . V_405 |= F_87 ( V_413 ) ;
if ( V_304 && V_304 -> V_83 -> V_417 )
V_305 = V_304 -> V_83 -> V_417 ( V_4 -> V_58 ) ;
else
V_305 = F_203 ( V_2 , & V_4 -> V_4 ) ;
if ( V_305 != 0 ) {
V_122 -> V_311 |= F_87 ( V_418 ) ;
V_122 -> V_419 = V_305 ;
}
}
