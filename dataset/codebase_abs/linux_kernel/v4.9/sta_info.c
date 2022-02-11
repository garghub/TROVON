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
struct V_41 * F_21 ( struct V_1 * V_2 ,
const T_1 * V_42 )
{
return F_22 ( & V_2 -> V_5 , V_42 , V_7 ) ;
}
struct V_3 * F_23 ( struct V_12 * V_13 ,
const T_1 * V_42 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_41 * V_43 ;
struct V_3 * V_4 ;
F_24 () ;
F_25 (local, addr, sta, tmp) {
if ( V_4 -> V_13 == V_13 ) {
F_26 () ;
return V_4 ;
}
}
F_26 () ;
return NULL ;
}
struct V_3 * F_27 ( struct V_12 * V_13 ,
const T_1 * V_42 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_41 * V_43 ;
struct V_3 * V_4 ;
F_24 () ;
F_25 (local, addr, sta, tmp) {
if ( V_4 -> V_13 == V_13 ||
( V_4 -> V_13 -> V_23 && V_4 -> V_13 -> V_23 == V_13 -> V_23 ) ) {
F_26 () ;
return V_4 ;
}
}
F_26 () ;
return NULL ;
}
struct V_3 * F_28 ( struct V_12 * V_13 ,
int V_44 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 ;
int V_9 = 0 ;
F_29 (sta, &local->sta_list, list) {
if ( V_13 != V_4 -> V_13 )
continue;
if ( V_9 < V_44 ) {
++ V_9 ;
continue;
}
return V_4 ;
}
return NULL ;
}
void F_20 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_45 )
F_30 ( V_4 ) ;
F_31 ( V_4 -> V_13 , L_1 , V_4 -> V_4 . V_42 ) ;
if ( V_4 -> V_4 . V_27 [ 0 ] )
F_17 ( F_9 ( V_4 -> V_4 . V_27 [ 0 ] ) ) ;
F_17 ( F_18 ( V_4 -> V_4 . V_46 ) ) ;
#ifdef F_32
F_17 ( V_4 -> V_25 ) ;
#endif
F_33 ( V_4 -> V_47 ) ;
F_17 ( V_4 ) ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return F_35 ( & V_2 -> V_5 , & V_4 -> V_6 ,
V_7 ) ;
}
static void F_36 ( struct V_48 * V_49 )
{
struct V_3 * V_4 ;
V_4 = F_37 ( V_49 , struct V_3 , V_36 ) ;
if ( V_4 -> V_50 )
return;
F_38 () ;
if ( ! F_4 ( V_4 , V_17 ) )
F_39 ( V_4 ) ;
else if ( F_40 ( V_4 , V_51 ) )
F_41 ( V_4 ) ;
else if ( F_40 ( V_4 , V_52 ) )
F_42 ( V_4 ) ;
F_43 () ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 V_53 )
{
if ( F_45 ( & V_2 -> V_34 , V_54 ) )
return 0 ;
V_4 -> V_45 = V_2 -> V_45 ;
V_4 -> V_55 = F_46 ( V_4 -> V_45 ,
V_4 , V_53 ) ;
if ( ! V_4 -> V_55 )
return - V_56 ;
return 0 ;
}
struct V_3 * F_47 ( struct V_12 * V_13 ,
const T_1 * V_42 , T_2 V_53 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_57 * V_34 = & V_2 -> V_34 ;
struct V_3 * V_4 ;
int V_9 ;
V_4 = F_48 ( sizeof( * V_4 ) + V_34 -> V_58 , V_53 ) ;
if ( ! V_4 )
return NULL ;
if ( F_45 ( V_34 , V_59 ) ) {
V_4 -> V_47 =
F_49 ( struct V_60 ) ;
if ( ! V_4 -> V_47 )
goto free;
}
F_50 ( & V_4 -> V_30 ) ;
F_50 ( & V_4 -> V_61 ) ;
F_51 ( & V_4 -> V_36 , F_36 ) ;
F_51 ( & V_4 -> V_38 . V_62 , V_63 ) ;
F_52 ( & V_4 -> V_38 . V_64 ) ;
#ifdef F_32
if ( F_5 ( & V_13 -> V_20 ) ) {
V_4 -> V_25 = F_48 ( sizeof( * V_4 -> V_25 ) , V_53 ) ;
if ( ! V_4 -> V_25 )
goto free;
F_50 ( & V_4 -> V_25 -> V_65 ) ;
if ( F_5 ( & V_13 -> V_20 ) &&
! V_13 -> V_24 . V_25 . V_66 )
F_53 ( & V_4 -> V_25 -> V_67 ) ;
V_4 -> V_25 -> V_68 = V_69 ;
}
#endif
memcpy ( V_4 -> V_42 , V_42 , V_70 ) ;
memcpy ( V_4 -> V_4 . V_42 , V_42 , V_70 ) ;
V_4 -> V_4 . V_71 =
V_2 -> V_34 . V_71 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_13 = V_13 ;
V_4 -> V_72 . V_73 = V_74 ;
F_54 ( & V_4 -> V_72 . V_75 ) ;
V_4 -> V_76 = V_77 ;
V_4 -> V_78 = V_79 ;
V_4 -> V_80 = F_55 () ;
F_56 ( & V_4 -> V_81 . signal ) ;
for ( V_9 = 0 ; V_9 < F_8 ( V_4 -> V_81 . V_82 ) ; V_9 ++ )
F_56 ( & V_4 -> V_81 . V_82 [ V_9 ] ) ;
if ( V_2 -> V_83 -> V_84 ) {
void * V_85 ;
int V_86 = sizeof( struct V_28 ) +
F_57 ( V_34 -> V_87 , sizeof( void * ) ) ;
V_85 = F_58 ( F_8 ( V_4 -> V_4 . V_27 ) , V_86 , V_53 ) ;
if ( ! V_85 )
goto free;
for ( V_9 = 0 ; V_9 < F_8 ( V_4 -> V_4 . V_27 ) ; V_9 ++ ) {
struct V_28 * V_27 = V_85 + V_9 * V_86 ;
F_59 ( V_13 , V_4 , V_27 , V_9 ) ;
}
}
if ( F_44 ( V_2 , V_4 , V_53 ) )
goto V_88;
for ( V_9 = 0 ; V_9 < V_37 ; V_9 ++ ) {
V_4 -> V_89 [ V_9 ] = V_9 ;
}
for ( V_9 = 0 ; V_9 < V_31 ; V_9 ++ ) {
F_60 ( & V_4 -> V_33 [ V_9 ] ) ;
F_60 ( & V_4 -> V_35 [ V_9 ] ) ;
}
for ( V_9 = 0 ; V_9 < V_37 ; V_9 ++ )
V_4 -> V_90 [ V_9 ] = F_61 ( V_91 ) ;
V_4 -> V_4 . V_92 = V_93 ;
if ( V_13 -> V_20 . type == V_21 ||
V_13 -> V_20 . type == V_22 ) {
struct V_94 * V_95 =
V_34 -> V_96 -> V_97 [ F_62 ( V_13 ) ] ;
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
F_63 ( 1 ) ;
}
}
V_4 -> V_4 . V_109 = V_110 ;
F_31 ( V_13 , L_2 , V_4 -> V_4 . V_42 ) ;
return V_4 ;
V_88:
if ( V_4 -> V_4 . V_27 [ 0 ] )
F_17 ( F_9 ( V_4 -> V_4 . V_27 [ 0 ] ) ) ;
free:
#ifdef F_32
F_17 ( V_4 -> V_25 ) ;
#endif
F_17 ( V_4 ) ;
return NULL ;
}
static int F_64 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
if ( F_65 ( ! F_66 ( V_13 ) ) )
return - V_111 ;
if ( F_63 ( F_67 ( V_4 -> V_4 . V_42 , V_13 -> V_20 . V_42 ) ||
F_68 ( V_4 -> V_4 . V_42 ) ) )
return - V_112 ;
F_24 () ;
F_69 ( & V_13 -> V_2 -> V_113 ) ;
if ( F_45 ( & V_13 -> V_2 -> V_34 , V_114 ) &&
F_70 ( & V_13 -> V_2 -> V_34 , V_4 -> V_42 , NULL ) ) {
F_26 () ;
return - V_115 ;
}
F_26 () ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_3 * V_4 )
{
enum V_116 V_117 ;
int V_118 = 0 ;
for ( V_117 = V_119 ; V_117 < V_4 -> V_76 ; V_117 ++ ) {
V_118 = F_72 ( V_2 , V_13 , V_4 , V_117 , V_117 + 1 ) ;
if ( V_118 )
break;
}
if ( ! V_118 ) {
if ( ! V_2 -> V_83 -> V_120 )
V_4 -> V_121 = true ;
return 0 ;
}
if ( V_13 -> V_20 . type == V_122 ) {
F_73 ( V_13 ,
L_3 ,
V_4 -> V_4 . V_42 , V_117 + 1 , V_118 ) ;
V_118 = 0 ;
}
for (; V_117 > V_119 ; V_117 -- )
F_63 ( F_72 ( V_2 , V_13 , V_4 , V_117 , V_117 - 1 ) ) ;
return V_118 ;
}
static int F_74 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_123 * V_124 ;
int V_118 = 0 ;
F_69 ( & V_2 -> V_113 ) ;
V_124 = F_48 ( sizeof( struct V_123 ) , V_125 ) ;
if ( ! V_124 ) {
V_118 = - V_56 ;
goto V_126;
}
if ( F_27 ( V_13 , V_4 -> V_4 . V_42 ) ) {
V_118 = - V_127 ;
goto V_126;
}
V_2 -> V_128 ++ ;
V_2 -> V_129 ++ ;
F_75 () ;
F_76 ( V_4 , V_130 ) ;
V_118 = F_34 ( V_2 , V_4 ) ;
if ( V_118 )
goto V_131;
F_77 ( & V_4 -> V_132 , & V_2 -> V_133 ) ;
V_118 = F_71 ( V_2 , V_13 , V_4 ) ;
if ( V_118 )
goto V_134;
F_76 ( V_4 , V_135 ) ;
F_6 ( V_4 , V_130 ) ;
F_78 ( V_4 ) ;
F_79 ( V_4 ) ;
V_124 -> V_136 = V_2 -> V_129 ;
F_80 ( V_13 -> V_137 , V_4 -> V_4 . V_42 , V_124 , V_125 ) ;
F_17 ( V_124 ) ;
F_31 ( V_13 , L_4 , V_4 -> V_4 . V_42 ) ;
F_24 () ;
F_81 ( & V_2 -> V_113 ) ;
if ( F_5 ( & V_13 -> V_20 ) )
F_82 ( V_13 ) ;
return 0 ;
V_134:
F_1 ( V_2 , V_4 ) ;
F_83 ( & V_4 -> V_132 ) ;
V_131:
V_2 -> V_128 -- ;
F_84 () ;
F_3 ( V_4 ) ;
V_126:
F_81 ( & V_2 -> V_113 ) ;
F_17 ( V_124 ) ;
F_24 () ;
return V_118 ;
}
int F_85 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_118 ;
F_86 () ;
F_87 ( & V_2 -> V_113 ) ;
V_118 = F_64 ( V_4 ) ;
if ( V_118 ) {
F_81 ( & V_2 -> V_113 ) ;
F_24 () ;
goto V_138;
}
V_118 = F_74 ( V_4 ) ;
if ( V_118 )
goto V_138;
return 0 ;
V_138:
F_20 ( V_2 , V_4 ) ;
return V_118 ;
}
int F_88 ( struct V_3 * V_4 )
{
int V_118 = F_85 ( V_4 ) ;
F_26 () ;
return V_118 ;
}
static inline void F_89 ( T_1 * V_139 , T_4 V_140 )
{
V_139 [ V_140 / 8 ] |= ( 1 << ( V_140 % 8 ) ) ;
}
static inline void F_90 ( T_1 * V_139 , T_4 V_140 )
{
V_139 [ V_140 / 8 ] &= ~ ( 1 << ( V_140 % 8 ) ) ;
}
static inline bool F_91 ( T_1 * V_139 , T_4 V_140 )
{
return V_139 [ V_140 / 8 ] & ( 1 << ( V_140 % 8 ) ) ;
}
static unsigned long F_92 ( int V_8 )
{
switch ( V_8 ) {
case V_141 :
return F_93 ( 6 ) | F_93 ( 7 ) ;
case V_142 :
return F_93 ( 4 ) | F_93 ( 5 ) ;
case V_143 :
return F_93 ( 0 ) | F_93 ( 3 ) ;
case V_144 :
return F_93 ( 1 ) | F_93 ( 2 ) ;
default:
F_63 ( 1 ) ;
return 0 ;
}
}
static void F_94 ( struct V_3 * V_4 , bool V_145 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_15 * V_16 ;
bool V_146 = false ;
T_1 V_147 = V_4 -> V_4 . V_148 ;
int V_8 ;
T_4 V_140 = V_4 -> V_4 . V_149 ;
if ( V_4 -> V_13 -> V_20 . type == V_21 ||
V_4 -> V_13 -> V_20 . type == V_22 ) {
if ( F_95 ( ! V_4 -> V_13 -> V_23 ) )
return;
V_16 = & V_4 -> V_13 -> V_23 -> V_16 ;
#ifdef F_32
} else if ( F_5 ( & V_4 -> V_13 -> V_20 ) ) {
V_16 = & V_4 -> V_13 -> V_24 . V_25 . V_16 ;
#endif
} else {
return;
}
if ( F_45 ( & V_2 -> V_34 , V_150 ) )
return;
if ( V_4 -> V_50 )
goto V_151;
if ( V_147 == F_93 ( V_31 ) - 1 )
V_147 = 0 ;
if ( V_145 )
V_147 = F_93 ( V_31 ) - 1 ;
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ ) {
unsigned long V_152 ;
if ( V_147 & F_93 ( V_8 ) )
continue;
V_146 |= ! F_96 ( & V_4 -> V_35 [ V_8 ] ) ||
! F_96 ( & V_4 -> V_33 [ V_8 ] ) ;
if ( V_146 )
break;
V_152 = F_92 ( V_8 ) ;
V_146 |=
V_4 -> V_153 & V_152 ;
V_146 |=
V_4 -> V_154 & V_152 ;
}
V_151:
F_10 ( & V_2 -> V_155 ) ;
if ( V_146 == F_91 ( V_16 -> V_139 , V_140 ) )
goto V_156;
if ( V_146 )
F_89 ( V_16 -> V_139 , V_140 ) ;
else
F_90 ( V_16 -> V_139 , V_140 ) ;
if ( V_2 -> V_83 -> V_157 && ! F_63 ( V_4 -> V_50 ) ) {
V_2 -> V_158 = true ;
F_97 ( V_2 , & V_4 -> V_4 , V_146 ) ;
V_2 -> V_158 = false ;
}
V_156:
F_12 ( & V_2 -> V_155 ) ;
}
void F_98 ( struct V_3 * V_4 )
{
F_94 ( V_4 , false ) ;
}
static bool F_99 ( struct V_3 * V_4 , struct V_159 * V_160 )
{
struct V_161 * V_162 ;
int V_163 ;
if ( ! V_160 )
return false ;
V_162 = F_100 ( V_160 ) ;
V_163 = ( V_4 -> V_164 *
V_4 -> V_13 -> V_20 . V_165 . V_166 *
32 / 15625 ) * V_167 ;
if ( V_163 < V_168 )
V_163 = V_168 ;
return F_101 ( V_74 , V_162 -> V_169 . V_74 + V_163 ) ;
}
static bool F_102 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_8 )
{
unsigned long V_170 ;
struct V_159 * V_160 ;
for (; ; ) {
F_103 ( & V_4 -> V_35 [ V_8 ] . V_30 , V_170 ) ;
V_160 = F_104 ( & V_4 -> V_35 [ V_8 ] ) ;
if ( F_99 ( V_4 , V_160 ) )
V_160 = F_105 ( & V_4 -> V_35 [ V_8 ] ) ;
else
V_160 = NULL ;
F_106 ( & V_4 -> V_35 [ V_8 ] . V_30 , V_170 ) ;
if ( ! V_160 )
break;
F_107 ( & V_2 -> V_34 , V_160 ) ;
}
for (; ; ) {
F_103 ( & V_4 -> V_33 [ V_8 ] . V_30 , V_170 ) ;
V_160 = F_104 ( & V_4 -> V_33 [ V_8 ] ) ;
if ( F_99 ( V_4 , V_160 ) )
V_160 = F_105 ( & V_4 -> V_33 [ V_8 ] ) ;
else
V_160 = NULL ;
F_106 ( & V_4 -> V_33 [ V_8 ] . V_30 , V_170 ) ;
if ( ! V_160 )
break;
V_2 -> V_32 -- ;
F_108 ( V_4 -> V_13 , L_5 ,
V_4 -> V_4 . V_42 ) ;
F_107 ( & V_2 -> V_34 , V_160 ) ;
}
F_98 ( V_4 ) ;
return ! ( F_96 ( & V_4 -> V_33 [ V_8 ] ) &&
F_96 ( & V_4 -> V_35 [ V_8 ] ) ) ;
}
static bool F_109 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_171 = false ;
int V_8 ;
if ( ! V_4 -> V_13 -> V_23 &&
! F_5 ( & V_4 -> V_13 -> V_20 ) )
return false ;
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ )
V_171 |=
F_102 ( V_2 , V_4 , V_8 ) ;
return V_171 ;
}
static int T_5 F_110 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
int V_172 ;
F_86 () ;
if ( ! V_4 )
return - V_173 ;
V_2 = V_4 -> V_2 ;
V_13 = V_4 -> V_13 ;
F_69 ( & V_2 -> V_113 ) ;
F_76 ( V_4 , V_130 ) ;
F_111 ( V_4 , V_174 ) ;
F_112 ( V_2 , V_4 ) ;
V_172 = F_1 ( V_2 , V_4 ) ;
if ( F_63 ( V_172 ) )
return V_172 ;
if ( F_4 ( V_4 , V_175 ) ) {
F_113 ( V_2 , V_13 , & V_4 -> V_4 ) ;
F_6 ( V_4 , V_175 ) ;
}
F_83 ( & V_4 -> V_132 ) ;
V_4 -> V_176 = true ;
F_114 ( V_2 , V_4 -> V_13 , V_4 ) ;
if ( V_13 -> V_20 . type == V_22 &&
F_115 ( V_13 -> V_24 . V_177 . V_4 ) == V_4 )
F_116 ( V_13 -> V_24 . V_177 . V_4 , NULL ) ;
return 0 ;
}
static void F_117 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_123 * V_124 ;
int V_172 ;
F_86 () ;
F_69 ( & V_2 -> V_113 ) ;
F_118 ( V_2 , V_4 ) ;
F_94 ( V_4 , true ) ;
V_4 -> V_50 = true ;
V_2 -> V_128 -- ;
V_2 -> V_129 ++ ;
while ( V_4 -> V_76 > V_77 ) {
V_172 = F_119 ( V_4 , V_4 -> V_76 - 1 ) ;
if ( V_172 ) {
F_95 ( 1 ) ;
break;
}
}
if ( V_4 -> V_121 ) {
V_172 = F_72 ( V_2 , V_13 , V_4 , V_77 ,
V_119 ) ;
F_95 ( V_172 != 0 ) ;
}
F_31 ( V_13 , L_6 , V_4 -> V_4 . V_42 ) ;
V_124 = F_48 ( sizeof( * V_124 ) , V_125 ) ;
if ( V_124 )
F_120 ( V_4 , V_124 ) ;
F_121 ( V_13 -> V_137 , V_4 -> V_4 . V_42 , V_124 , V_125 ) ;
F_17 ( V_124 ) ;
F_122 ( V_4 ) ;
F_123 ( V_4 ) ;
F_19 ( V_4 ) ;
}
int T_5 F_124 ( struct V_3 * V_4 )
{
int V_118 = F_110 ( V_4 ) ;
if ( V_118 )
return V_118 ;
F_84 () ;
F_117 ( V_4 ) ;
return 0 ;
}
int F_125 ( struct V_12 * V_13 , const T_1 * V_42 )
{
struct V_3 * V_4 ;
int V_172 ;
F_87 ( & V_13 -> V_2 -> V_113 ) ;
V_4 = F_23 ( V_13 , V_42 ) ;
V_172 = F_124 ( V_4 ) ;
F_81 ( & V_13 -> V_2 -> V_113 ) ;
return V_172 ;
}
int F_126 ( struct V_12 * V_13 ,
const T_1 * V_42 )
{
struct V_3 * V_4 ;
int V_172 ;
F_87 ( & V_13 -> V_2 -> V_113 ) ;
V_4 = F_27 ( V_13 , V_42 ) ;
V_172 = F_124 ( V_4 ) ;
F_81 ( & V_13 -> V_2 -> V_113 ) ;
return V_172 ;
}
static void F_127 ( unsigned long V_178 )
{
struct V_1 * V_2 = (struct V_1 * ) V_178 ;
struct V_3 * V_4 ;
bool V_179 = false ;
F_24 () ;
F_29 (sta, &local->sta_list, list)
if ( F_109 ( V_2 , V_4 ) )
V_179 = true ;
F_26 () ;
if ( V_2 -> V_180 )
return;
if ( ! V_179 )
return;
F_128 ( & V_2 -> V_181 ,
F_129 ( V_74 + V_182 ) ) ;
}
int F_130 ( struct V_1 * V_2 )
{
int V_118 ;
V_118 = F_131 ( & V_2 -> V_5 , & V_7 ) ;
if ( V_118 )
return V_118 ;
F_50 ( & V_2 -> V_155 ) ;
F_52 ( & V_2 -> V_113 ) ;
F_132 ( & V_2 -> V_133 ) ;
F_133 ( & V_2 -> V_181 , F_127 ,
( unsigned long ) V_2 ) ;
return 0 ;
}
void F_134 ( struct V_1 * V_2 )
{
F_135 ( & V_2 -> V_181 ) ;
F_136 ( & V_2 -> V_5 ) ;
}
int F_137 ( struct V_12 * V_13 , bool V_183 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 , * V_43 ;
F_138 ( V_184 ) ;
int V_172 = 0 ;
F_86 () ;
F_63 ( V_183 && V_13 -> V_20 . type != V_21 ) ;
F_63 ( V_183 && ! V_13 -> V_23 ) ;
F_87 ( & V_2 -> V_113 ) ;
F_139 (sta, tmp, &local->sta_list, list) {
if ( V_13 == V_4 -> V_13 ||
( V_183 && V_13 -> V_23 == V_4 -> V_13 -> V_23 ) ) {
if ( ! F_63 ( F_110 ( V_4 ) ) )
F_140 ( & V_4 -> V_184 , & V_184 ) ;
V_172 ++ ;
}
}
if ( ! F_141 ( & V_184 ) ) {
F_84 () ;
F_139 (sta, tmp, &free_list, free_list)
F_117 ( V_4 ) ;
}
F_81 ( & V_2 -> V_113 ) ;
return V_172 ;
}
void F_142 ( struct V_12 * V_13 ,
unsigned long V_185 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 , * V_43 ;
F_87 ( & V_2 -> V_113 ) ;
F_139 (sta, tmp, &local->sta_list, list) {
unsigned long V_186 = F_143 ( V_4 ) ;
if ( V_13 != V_4 -> V_13 )
continue;
if ( F_144 ( V_186 + V_185 ) ) {
F_31 ( V_4 -> V_13 , L_7 ,
V_4 -> V_4 . V_42 ) ;
if ( F_5 ( & V_13 -> V_20 ) &&
F_4 ( V_4 , V_17 ) )
F_7 ( & V_13 -> V_24 . V_25 . V_16 . V_26 ) ;
F_63 ( F_124 ( V_4 ) ) ;
}
}
F_81 ( & V_2 -> V_113 ) ;
}
struct V_187 * F_70 ( struct V_57 * V_34 ,
const T_1 * V_42 ,
const T_1 * V_188 )
{
struct V_1 * V_2 = F_145 ( V_34 ) ;
struct V_41 * V_43 ;
struct V_3 * V_4 ;
F_25 (local, addr, sta, tmp) {
if ( V_188 &&
! F_67 ( V_4 -> V_13 -> V_20 . V_42 , V_188 ) )
continue;
if ( ! V_4 -> V_121 )
return NULL ;
return & V_4 -> V_4 ;
}
return NULL ;
}
struct V_187 * F_146 ( struct V_189 * V_20 ,
const T_1 * V_42 )
{
struct V_3 * V_4 ;
if ( ! V_20 )
return NULL ;
V_4 = F_27 ( F_147 ( V_20 ) , V_42 ) ;
if ( ! V_4 )
return NULL ;
if ( ! V_4 -> V_121 )
return NULL ;
return & V_4 -> V_4 ;
}
void F_39 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_190 V_40 ;
int V_191 = 0 , V_192 = 0 , V_8 , V_9 ;
unsigned long V_170 ;
struct V_15 * V_16 ;
if ( V_13 -> V_20 . type == V_22 )
V_13 = F_37 ( V_13 -> V_23 , struct V_12 ,
V_24 . V_193 ) ;
if ( V_13 -> V_20 . type == V_21 )
V_16 = & V_13 -> V_23 -> V_16 ;
else if ( F_5 ( & V_13 -> V_20 ) )
V_16 = & V_13 -> V_24 . V_25 . V_16 ;
else
return;
F_6 ( V_4 , V_194 ) ;
F_148 ( F_149 ( V_37 ) > 1 ) ;
V_4 -> V_153 = 0 ;
V_4 -> V_154 = 0 ;
if ( ! F_45 ( & V_2 -> V_34 , V_150 ) )
F_150 ( V_2 , V_13 , V_195 , & V_4 -> V_4 ) ;
if ( V_4 -> V_4 . V_27 [ 0 ] ) {
for ( V_9 = 0 ; V_9 < F_8 ( V_4 -> V_4 . V_27 ) ; V_9 ++ ) {
if ( ! F_151 ( V_4 -> V_4 . V_27 [ V_9 ] ) )
continue;
F_152 ( V_2 , F_9 ( V_4 -> V_4 . V_27 [ V_9 ] ) ) ;
}
}
F_60 ( & V_40 ) ;
F_153 ( & V_4 -> V_61 ) ;
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ ) {
int V_196 = F_13 ( & V_40 ) , V_43 ;
F_103 ( & V_4 -> V_35 [ V_8 ] . V_30 , V_170 ) ;
F_154 ( & V_4 -> V_35 [ V_8 ] , & V_40 ) ;
F_106 ( & V_4 -> V_35 [ V_8 ] . V_30 , V_170 ) ;
V_43 = F_13 ( & V_40 ) ;
V_191 += V_43 - V_196 ;
V_196 = V_43 ;
F_103 ( & V_4 -> V_33 [ V_8 ] . V_30 , V_170 ) ;
F_154 ( & V_4 -> V_33 [ V_8 ] , & V_40 ) ;
F_106 ( & V_4 -> V_33 [ V_8 ] . V_30 , V_170 ) ;
V_43 = F_13 ( & V_40 ) ;
V_192 += V_43 - V_196 ;
}
F_155 ( V_2 , & V_40 ) ;
F_6 ( V_4 , V_19 ) ;
F_6 ( V_4 , V_51 ) ;
F_6 ( V_4 , V_52 ) ;
F_156 ( & V_4 -> V_61 ) ;
F_7 ( & V_16 -> V_26 ) ;
if ( ! F_5 ( & V_13 -> V_20 ) &&
! F_157 ( V_4 -> V_104 ,
V_13 -> V_92 ) &&
V_4 -> V_104 != V_13 -> V_23 -> V_197 &&
F_158 ( V_4 ) != 1 ) {
F_159 ( V_13 ,
L_8 ,
V_4 -> V_4 . V_42 ) ;
F_160 ( V_13 , V_13 -> V_23 -> V_197 ,
V_4 -> V_4 . V_42 ,
V_13 -> V_20 . V_165 . V_198 ) ;
}
V_2 -> V_32 -= V_192 ;
F_98 ( V_4 ) ;
F_108 ( V_13 ,
L_9 ,
V_4 -> V_4 . V_42 , V_4 -> V_4 . V_149 , V_191 , V_192 ) ;
F_161 ( V_4 ) ;
}
static void F_162 ( struct V_3 * V_4 , int V_199 ,
enum V_200 V_201 ,
bool V_202 , bool V_203 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_204 * V_205 ;
struct V_159 * V_160 ;
int V_86 = sizeof( * V_205 ) ;
T_6 V_206 ;
bool V_207 = V_4 -> V_4 . V_208 ;
struct V_161 * V_162 ;
struct V_209 * V_210 ;
if ( V_207 ) {
V_206 = F_61 ( V_211 |
V_212 |
V_213 ) ;
} else {
V_86 -= 2 ;
V_206 = F_61 ( V_211 |
V_214 |
V_213 ) ;
}
V_160 = F_163 ( V_2 -> V_34 . V_215 + V_86 ) ;
if ( ! V_160 )
return;
F_164 ( V_160 , V_2 -> V_34 . V_215 ) ;
V_205 = ( void * ) F_165 ( V_160 , V_86 ) ;
V_205 -> V_216 = V_206 ;
V_205 -> V_217 = 0 ;
memcpy ( V_205 -> V_218 , V_4 -> V_4 . V_42 , V_70 ) ;
memcpy ( V_205 -> V_219 , V_13 -> V_20 . V_42 , V_70 ) ;
memcpy ( V_205 -> V_220 , V_13 -> V_20 . V_42 , V_70 ) ;
V_205 -> V_221 = 0 ;
V_160 -> V_222 = V_199 ;
F_166 ( V_160 , V_223 [ V_199 ] ) ;
if ( V_207 ) {
V_205 -> V_224 = F_61 ( V_199 ) ;
if ( V_201 == V_225 ) {
V_205 -> V_224 |=
F_61 ( V_226 ) ;
if ( V_203 )
V_205 -> V_216 |=
F_61 ( V_227 ) ;
}
}
V_162 = F_100 ( V_160 ) ;
V_162 -> V_170 |= V_228 |
V_229 |
V_230 ;
V_162 -> V_169 . V_170 |= V_231 ;
if ( V_202 )
F_167 ( V_2 , V_4 , F_93 ( V_199 ) , 1 ,
V_201 , false ) ;
V_160 -> V_137 = V_13 -> V_137 ;
F_24 () ;
V_210 = F_168 ( V_13 -> V_20 . V_210 ) ;
if ( F_63 ( ! V_210 ) ) {
F_26 () ;
F_169 ( V_160 ) ;
return;
}
V_162 -> V_232 = V_210 -> V_233 . V_234 -> V_232 ;
F_170 ( V_13 , V_4 , V_160 ) ;
F_26 () ;
}
static int F_171 ( unsigned long V_152 )
{
if ( V_152 & 0xF8 )
return F_172 ( V_152 ) - 1 ;
if ( V_152 & F_93 ( 0 ) )
return 0 ;
return F_172 ( V_152 ) - 1 ;
}
static bool
F_173 ( struct V_3 * V_4 , T_1 V_235 ,
enum V_200 V_201 ,
unsigned long V_236 )
{
int V_8 ;
if ( V_201 == V_237 &&
F_174 ( V_236 ) > 1 )
return true ;
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ ) {
if ( V_235 & F_93 ( V_8 ) )
continue;
if ( ! F_96 ( & V_4 -> V_35 [ V_8 ] ) ||
! F_96 ( & V_4 -> V_33 [ V_8 ] ) )
return true ;
}
return false ;
}
static void
F_175 ( struct V_3 * V_4 , int V_238 , T_1 V_235 ,
enum V_200 V_201 ,
struct V_190 * V_239 ,
unsigned long * V_236 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ ) {
unsigned long V_152 ;
if ( V_235 & F_93 ( V_8 ) )
continue;
V_152 = F_92 ( V_8 ) ;
if ( F_96 ( V_239 ) ) {
* V_236 |=
V_4 -> V_153 & V_152 ;
* V_236 |= V_4 -> V_154 & V_152 ;
}
if ( ! * V_236 ) {
struct V_159 * V_160 ;
while ( V_238 > 0 ) {
V_160 = F_176 ( & V_4 -> V_35 [ V_8 ] ) ;
if ( ! V_160 ) {
V_160 = F_176 (
& V_4 -> V_33 [ V_8 ] ) ;
if ( V_160 )
V_2 -> V_32 -- ;
}
if ( ! V_160 )
break;
V_238 -- ;
F_177 ( V_239 , V_160 ) ;
}
}
if ( ! F_96 ( & V_4 -> V_35 [ V_8 ] ) ||
! F_96 ( & V_4 -> V_33 [ V_8 ] ) )
break;
}
}
static void
F_178 ( struct V_3 * V_4 ,
int V_238 , T_1 V_235 ,
enum V_200 V_201 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
unsigned long V_236 = 0 ;
struct V_190 V_239 ;
bool V_203 ;
F_76 ( V_4 , V_194 ) ;
F_179 ( & V_239 ) ;
F_175 ( V_4 , V_238 , V_235 , V_201 ,
& V_239 , & V_236 ) ;
V_203 = F_173 ( V_4 , V_235 , V_201 , V_236 ) ;
if ( V_236 && V_201 == V_237 )
V_236 =
F_93 ( F_171 ( V_236 ) ) ;
if ( F_96 ( & V_239 ) && ! V_236 ) {
int V_199 ;
V_199 = 7 - ( ( F_180 ( ~ V_235 ) - 1 ) << 1 ) ;
F_162 ( V_4 , V_199 , V_201 , true , false ) ;
} else if ( ! V_236 ) {
struct V_190 V_40 ;
struct V_159 * V_160 ;
int V_240 = 0 ;
T_4 V_152 = 0 ;
bool V_241 = false ;
F_60 ( & V_40 ) ;
while ( ( V_160 = F_105 ( & V_239 ) ) ) {
struct V_161 * V_162 = F_100 ( V_160 ) ;
struct V_242 * V_243 = ( void * ) V_160 -> V_178 ;
T_1 * V_244 = NULL ;
V_240 ++ ;
V_162 -> V_170 |= V_228 ;
V_162 -> V_169 . V_170 |= V_231 ;
if ( V_203 || ! F_96 ( & V_239 ) )
V_243 -> V_216 |=
F_61 ( V_227 ) ;
else
V_243 -> V_216 &=
F_61 ( ~ V_227 ) ;
if ( F_181 ( V_243 -> V_216 ) ||
F_182 ( V_243 -> V_216 ) )
V_244 = F_183 ( V_243 ) ;
V_152 |= F_93 ( V_160 -> V_222 ) ;
F_177 ( & V_40 , V_160 ) ;
if ( ! F_96 ( & V_239 ) )
continue;
if ( V_201 != V_225 ) {
V_162 -> V_170 |= V_229 |
V_230 ;
break;
}
if ( V_244 ) {
* V_244 |= V_226 ;
V_162 -> V_170 |= V_229 |
V_230 ;
} else {
V_243 -> V_216 |=
F_61 ( V_227 ) ;
V_241 = true ;
V_240 ++ ;
}
break;
}
F_167 ( V_2 , V_4 , V_152 , V_240 ,
V_201 , V_203 ) ;
F_155 ( V_2 , & V_40 ) ;
if ( V_241 )
F_162 (
V_4 , F_171 ( V_152 ) ,
V_201 , false , false ) ;
F_98 ( V_4 ) ;
} else {
int V_199 ;
F_184 ( V_2 , V_4 , V_236 ,
V_238 , V_201 , V_203 ) ;
if ( ! V_4 -> V_4 . V_27 [ 0 ] )
return;
for ( V_199 = 0 ; V_199 < F_8 ( V_4 -> V_4 . V_27 ) ; V_199 ++ ) {
if ( ! ( V_236 & F_93 ( V_199 ) ) ||
F_151 ( V_4 -> V_4 . V_27 [ V_199 ] ) )
continue;
F_98 ( V_4 ) ;
break;
}
}
}
void F_41 ( struct V_3 * V_4 )
{
T_1 V_245 = V_4 -> V_4 . V_148 ;
if ( V_245 == F_93 ( V_31 ) - 1 )
V_245 = 0 ;
F_178 ( V_4 , 1 , V_245 ,
V_237 ) ;
}
void F_42 ( struct V_3 * V_4 )
{
int V_238 = V_4 -> V_4 . V_246 ;
T_1 V_247 = V_4 -> V_4 . V_148 ;
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
F_178 ( V_4 , V_238 , ~ V_247 ,
V_225 ) ;
}
void F_185 ( struct V_57 * V_34 ,
struct V_187 * V_248 , bool V_249 )
{
struct V_3 * V_4 = F_37 ( V_248 , struct V_3 , V_4 ) ;
F_186 ( V_4 -> V_2 , V_248 , V_249 ) ;
if ( V_249 ) {
F_76 ( V_4 , V_18 ) ;
F_187 ( V_4 ) ;
return;
}
if ( ! F_4 ( V_4 , V_18 ) )
return;
if ( ! F_4 ( V_4 , V_17 ) ) {
F_76 ( V_4 , V_19 ) ;
F_6 ( V_4 , V_18 ) ;
F_188 ( V_34 , & V_4 -> V_36 ) ;
} else if ( F_4 ( V_4 , V_51 ) ||
F_4 ( V_4 , V_52 ) ) {
F_6 ( V_4 , V_18 ) ;
F_188 ( V_34 , & V_4 -> V_36 ) ;
} else {
F_6 ( V_4 , V_18 ) ;
F_161 ( V_4 ) ;
}
}
void F_189 ( struct V_187 * V_248 )
{
struct V_3 * V_4 = F_37 ( V_248 , struct V_3 , V_4 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_190 ( V_2 , V_248 ) ;
F_6 ( V_4 , V_194 ) ;
}
void F_191 ( struct V_187 * V_248 , int V_199 )
{
struct V_3 * V_4 = F_37 ( V_248 , struct V_3 , V_4 ) ;
enum V_200 V_201 ;
bool V_203 ;
F_192 ( V_4 -> V_2 , V_248 , V_199 ) ;
V_201 = V_225 ;
V_203 = F_173 ( V_4 , ~ V_4 -> V_4 . V_148 ,
V_201 , 0 ) ;
F_162 ( V_4 , V_199 , V_201 , false , V_203 ) ;
}
void F_193 ( struct V_187 * V_248 ,
T_1 V_199 , bool V_192 )
{
struct V_3 * V_4 = F_37 ( V_248 , struct V_3 , V_4 ) ;
if ( F_63 ( V_199 >= V_37 ) )
return;
F_194 ( V_4 -> V_2 , V_248 , V_199 , V_192 ) ;
if ( V_192 )
F_195 ( V_199 , & V_4 -> V_153 ) ;
else
F_196 ( V_199 , & V_4 -> V_153 ) ;
F_98 ( V_4 ) ;
}
static void
F_197 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
bool V_250 = V_13 -> V_20 . V_251 ;
struct V_3 * V_4 ;
F_24 () ;
F_29 (sta, &local->sta_list, list) {
if ( V_13 != V_4 -> V_13 ||
! F_4 ( V_4 , V_252 ) )
continue;
if ( ! V_4 -> V_4 . V_253 ) {
V_250 = false ;
break;
}
}
F_26 () ;
if ( V_250 != V_13 -> V_20 . V_165 . V_250 ) {
V_13 -> V_20 . V_165 . V_250 = V_250 ;
F_198 ( V_13 , V_254 ) ;
}
}
int F_119 ( struct V_3 * V_4 ,
enum V_116 V_255 )
{
F_86 () ;
if ( V_4 -> V_76 == V_255 )
return 0 ;
switch ( V_255 ) {
case V_77 :
if ( V_4 -> V_76 != V_256 )
return - V_112 ;
break;
case V_256 :
if ( V_4 -> V_76 != V_77 &&
V_4 -> V_76 != V_257 )
return - V_112 ;
break;
case V_257 :
if ( V_4 -> V_76 != V_256 &&
V_4 -> V_76 != V_258 )
return - V_112 ;
break;
case V_258 :
if ( V_4 -> V_76 != V_257 )
return - V_112 ;
break;
default:
F_199 ( 1 , L_10 , V_255 ) ;
return - V_112 ;
}
F_31 ( V_4 -> V_13 , L_11 ,
V_4 -> V_4 . V_42 , V_255 ) ;
if ( F_4 ( V_4 , V_135 ) ) {
int V_118 = F_72 ( V_4 -> V_2 , V_4 -> V_13 , V_4 ,
V_4 -> V_76 , V_255 ) ;
if ( V_118 )
return V_118 ;
}
switch ( V_255 ) {
case V_77 :
if ( V_4 -> V_76 == V_256 )
F_196 ( V_259 , & V_4 -> V_260 ) ;
break;
case V_256 :
if ( V_4 -> V_76 == V_77 ) {
F_195 ( V_259 , & V_4 -> V_260 ) ;
} else if ( V_4 -> V_76 == V_257 ) {
F_196 ( V_252 , & V_4 -> V_260 ) ;
F_200 ( V_4 -> V_13 ) ;
if ( ! V_4 -> V_4 . V_253 )
F_197 ( V_4 -> V_13 ) ;
}
break;
case V_257 :
if ( V_4 -> V_76 == V_256 ) {
F_195 ( V_252 , & V_4 -> V_260 ) ;
F_200 ( V_4 -> V_13 ) ;
if ( ! V_4 -> V_4 . V_253 )
F_197 ( V_4 -> V_13 ) ;
} else if ( V_4 -> V_76 == V_258 ) {
if ( V_4 -> V_13 -> V_20 . type == V_21 ||
( V_4 -> V_13 -> V_20 . type == V_22 &&
! V_4 -> V_13 -> V_24 . V_177 . V_4 ) )
F_7 ( & V_4 -> V_13 -> V_23 -> V_261 ) ;
F_196 ( V_262 , & V_4 -> V_260 ) ;
F_187 ( V_4 ) ;
F_201 ( V_4 ) ;
}
break;
case V_258 :
if ( V_4 -> V_76 == V_257 ) {
if ( V_4 -> V_13 -> V_20 . type == V_21 ||
( V_4 -> V_13 -> V_20 . type == V_22 &&
! V_4 -> V_13 -> V_24 . V_177 . V_4 ) )
F_202 ( & V_4 -> V_13 -> V_23 -> V_261 ) ;
F_195 ( V_262 , & V_4 -> V_260 ) ;
F_161 ( V_4 ) ;
F_203 ( V_4 ) ;
}
break;
default:
break;
}
V_4 -> V_76 = V_255 ;
return 0 ;
}
T_1 F_158 ( struct V_3 * V_4 )
{
struct V_263 * V_99 = & V_4 -> V_4 . V_99 ;
T_1 V_264 ;
if ( ! V_4 -> V_4 . V_99 . V_265 )
return 1 ;
if ( V_4 -> V_4 . V_266 . V_267 ) {
int V_9 ;
T_4 V_268 =
F_204 ( V_4 -> V_4 . V_266 . V_269 . V_268 ) ;
for ( V_9 = 7 ; V_9 >= 0 ; V_9 -- )
if ( ( V_268 & ( 0x3 << ( V_9 * 2 ) ) ) !=
V_270 )
return V_9 + 1 ;
}
if ( V_99 -> V_271 . V_272 [ 3 ] )
V_264 = 4 ;
else if ( V_99 -> V_271 . V_272 [ 2 ] )
V_264 = 3 ;
else if ( V_99 -> V_271 . V_272 [ 1 ] )
V_264 = 2 ;
else
V_264 = 1 ;
if ( ! ( V_99 -> V_271 . V_273 & V_274 ) )
return V_264 ;
return ( ( V_99 -> V_271 . V_273 & V_275 )
>> V_276 ) + 1 ;
}
static struct V_60 *
F_205 ( struct V_3 * V_4 )
{
struct V_60 * V_277 = & V_4 -> V_72 ;
struct V_1 * V_2 = V_4 -> V_2 ;
int V_278 ;
if ( ! F_45 ( & V_2 -> V_34 , V_59 ) )
return V_277 ;
F_206 (cpu) {
struct V_60 * V_279 ;
V_279 = F_207 ( V_4 -> V_47 , V_278 ) ;
if ( F_101 ( V_279 -> V_73 , V_277 -> V_73 ) )
V_277 = V_279 ;
}
return V_277 ;
}
static void F_208 ( struct V_1 * V_2 , T_4 V_280 ,
struct V_281 * V_282 )
{
V_282 -> V_283 = ( V_280 & V_284 ) >>
V_285 ;
if ( V_280 & V_286 ) {
V_282 -> V_170 = V_287 ;
V_282 -> V_271 = V_280 & 0xf ;
V_282 -> V_288 = ( V_280 & 0xf0 ) >> 4 ;
} else if ( V_280 & V_289 ) {
V_282 -> V_170 = V_290 ;
V_282 -> V_271 = V_280 & 0xff ;
} else if ( V_280 & V_291 ) {
struct V_94 * V_95 ;
T_4 V_292 ;
unsigned int V_293 ;
V_95 = V_2 -> V_34 . V_96 -> V_97 [ ( V_280 >> 4 ) & 0xf ] ;
V_292 = V_95 -> V_294 [ V_280 & 0xf ] . V_295 ;
if ( V_282 -> V_283 == V_296 )
V_293 = 2 ;
else if ( V_282 -> V_283 == V_297 )
V_293 = 1 ;
else
V_293 = 0 ;
V_282 -> V_298 = F_209 ( V_292 , 1 << V_293 ) ;
}
if ( V_280 & V_299 )
V_282 -> V_170 |= V_300 ;
}
static void F_210 ( struct V_3 * V_4 , struct V_281 * V_282 )
{
T_4 V_280 = F_211 ( F_205 ( V_4 ) -> V_301 ) ;
if ( V_280 == V_302 )
V_282 -> V_170 = 0 ;
else
F_208 ( V_4 -> V_2 , V_280 , V_282 ) ;
}
static void F_212 ( struct V_3 * V_4 ,
struct V_303 * V_304 ,
int V_199 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( ! ( V_304 -> V_305 & F_93 ( V_306 ) ) ) {
unsigned int V_307 ;
do {
V_307 = F_213 ( & V_4 -> V_72 . V_75 ) ;
V_304 -> V_308 = V_4 -> V_72 . V_309 [ V_199 ] ;
} while ( F_214 ( & V_4 -> V_72 . V_75 , V_307 ) );
V_304 -> V_305 |= F_93 ( V_306 ) ;
}
if ( ! ( V_304 -> V_305 & F_93 ( V_310 ) ) ) {
V_304 -> V_305 |= F_93 ( V_310 ) ;
V_304 -> V_311 = V_4 -> V_312 . V_309 [ V_199 ] ;
}
if ( ! ( V_304 -> V_305 & F_93 ( V_313 ) ) &&
F_45 ( & V_2 -> V_34 , V_314 ) ) {
V_304 -> V_305 |= F_93 ( V_313 ) ;
V_304 -> V_315 = V_4 -> V_316 . V_317 [ V_199 ] ;
}
if ( ! ( V_304 -> V_305 & F_93 ( V_318 ) ) &&
F_45 ( & V_2 -> V_34 , V_314 ) ) {
V_304 -> V_305 |= F_93 ( V_318 ) ;
V_304 -> V_319 = V_4 -> V_316 . V_320 [ V_199 ] ;
}
}
static inline T_7 F_215 ( struct V_60 * V_321 )
{
unsigned int V_307 ;
T_7 V_322 ;
do {
V_307 = F_213 ( & V_321 -> V_75 ) ;
V_322 = V_321 -> V_323 ;
} while ( F_214 ( & V_321 -> V_75 , V_307 ) );
return V_322 ;
}
void F_120 ( struct V_3 * V_4 , struct V_123 * V_124 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_324 * V_325 = NULL ;
T_8 V_326 = 0 ;
int V_9 , V_8 , V_278 ;
struct V_60 * V_327 ;
V_327 = F_205 ( V_4 ) ;
if ( F_4 ( V_4 , V_328 ) )
V_325 = V_2 -> V_45 ;
V_124 -> V_136 = V_13 -> V_2 -> V_129 ;
if ( V_13 -> V_20 . type == V_329 )
V_124 -> V_330 = V_13 -> V_24 . V_331 . V_332 ;
F_216 ( V_2 , V_13 , & V_4 -> V_4 , V_124 ) ;
V_124 -> V_305 |= F_93 ( V_333 ) |
F_93 ( V_334 ) |
F_93 ( V_335 ) |
F_93 ( V_336 ) |
F_93 ( V_337 ) ;
if ( V_13 -> V_20 . type == V_329 ) {
V_124 -> V_338 = V_13 -> V_24 . V_331 . V_338 ;
V_124 -> V_305 |= F_93 ( V_339 ) ;
}
V_124 -> V_340 = F_55 () - V_4 -> V_80 ;
V_124 -> V_341 =
F_217 ( V_74 - F_143 ( V_4 ) ) ;
if ( ! ( V_124 -> V_305 & ( F_93 ( V_342 ) |
F_93 ( V_343 ) ) ) ) {
V_124 -> V_344 = 0 ;
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ )
V_124 -> V_344 += V_4 -> V_312 . V_323 [ V_8 ] ;
V_124 -> V_305 |= F_93 ( V_342 ) ;
}
if ( ! ( V_124 -> V_305 & F_93 ( V_345 ) ) ) {
V_124 -> V_346 = 0 ;
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ )
V_124 -> V_346 += V_4 -> V_312 . V_347 [ V_8 ] ;
V_124 -> V_305 |= F_93 ( V_345 ) ;
}
if ( ! ( V_124 -> V_305 & ( F_93 ( V_348 ) |
F_93 ( V_349 ) ) ) ) {
V_124 -> V_350 += F_215 ( & V_4 -> V_72 ) ;
if ( V_4 -> V_47 ) {
F_206 (cpu) {
struct V_60 * V_351 ;
V_351 = F_207 ( V_4 -> V_47 , V_278 ) ;
V_124 -> V_350 += F_215 ( V_351 ) ;
}
}
V_124 -> V_305 |= F_93 ( V_348 ) ;
}
if ( ! ( V_124 -> V_305 & F_93 ( V_352 ) ) ) {
V_124 -> V_353 = V_4 -> V_72 . V_347 ;
if ( V_4 -> V_47 ) {
F_206 (cpu) {
struct V_60 * V_351 ;
V_351 = F_207 ( V_4 -> V_47 , V_278 ) ;
V_124 -> V_353 += V_351 -> V_347 ;
}
}
V_124 -> V_305 |= F_93 ( V_352 ) ;
}
if ( ! ( V_124 -> V_305 & F_93 ( V_354 ) ) ) {
V_124 -> V_355 = V_4 -> V_316 . V_356 ;
V_124 -> V_305 |= F_93 ( V_354 ) ;
}
if ( ! ( V_124 -> V_305 & F_93 ( V_357 ) ) ) {
V_124 -> V_358 = V_4 -> V_316 . V_359 ;
V_124 -> V_305 |= F_93 ( V_357 ) ;
}
V_124 -> V_360 = V_4 -> V_72 . V_361 ;
if ( V_4 -> V_47 ) {
F_206 (cpu) {
struct V_60 * V_351 ;
V_351 = F_207 ( V_4 -> V_47 , V_278 ) ;
V_124 -> V_353 += V_351 -> V_361 ;
}
}
if ( V_13 -> V_20 . type == V_329 &&
! ( V_13 -> V_20 . V_362 & V_363 ) ) {
V_124 -> V_305 |= F_93 ( V_364 ) |
F_93 ( V_365 ) ;
V_124 -> V_366 = F_218 ( & V_13 -> V_20 ) ;
}
if ( F_45 ( & V_4 -> V_2 -> V_34 , V_367 ) ||
F_45 ( & V_4 -> V_2 -> V_34 , V_368 ) ) {
if ( ! ( V_124 -> V_305 & F_93 ( V_369 ) ) ) {
V_124 -> signal = ( V_370 ) V_327 -> V_371 ;
V_124 -> V_305 |= F_93 ( V_369 ) ;
}
if ( ! V_4 -> V_47 &&
! ( V_124 -> V_305 & F_93 ( V_372 ) ) ) {
V_124 -> V_373 =
- F_219 ( & V_4 -> V_81 . signal ) ;
V_124 -> V_305 |= F_93 ( V_372 ) ;
}
}
if ( V_327 -> V_374 &&
! ( V_124 -> V_305 & ( F_93 ( V_375 ) |
F_93 ( V_376 ) ) ) ) {
V_124 -> V_305 |= F_93 ( V_375 ) ;
if ( ! V_4 -> V_47 )
V_124 -> V_305 |= F_93 ( V_376 ) ;
V_124 -> V_374 = V_327 -> V_374 ;
for ( V_9 = 0 ; V_9 < F_8 ( V_124 -> V_82 ) ; V_9 ++ ) {
V_124 -> V_82 [ V_9 ] =
V_327 -> V_377 [ V_9 ] ;
V_124 -> V_378 [ V_9 ] =
- F_219 ( & V_4 -> V_81 . V_82 [ V_9 ] ) ;
}
}
if ( ! ( V_124 -> V_305 & F_93 ( V_379 ) ) ) {
F_220 ( V_4 , & V_4 -> V_312 . V_301 ,
& V_124 -> V_380 ) ;
V_124 -> V_305 |= F_93 ( V_379 ) ;
}
if ( ! ( V_124 -> V_305 & F_93 ( V_381 ) ) ) {
F_210 ( V_4 , & V_124 -> V_382 ) ;
V_124 -> V_305 |= F_93 ( V_381 ) ;
}
V_124 -> V_305 |= F_93 ( V_383 ) ;
for ( V_9 = 0 ; V_9 < V_37 + 1 ; V_9 ++ ) {
struct V_303 * V_304 = & V_124 -> V_384 [ V_9 ] ;
F_212 ( V_4 , V_304 , V_9 ) ;
}
if ( F_5 ( & V_13 -> V_20 ) ) {
#ifdef F_32
V_124 -> V_305 |= F_93 ( V_385 ) |
F_93 ( V_386 ) |
F_93 ( V_387 ) |
F_93 ( V_388 ) |
F_93 ( V_389 ) |
F_93 ( V_390 ) ;
V_124 -> V_391 = V_4 -> V_25 -> V_391 ;
V_124 -> V_392 = V_4 -> V_25 -> V_392 ;
V_124 -> V_393 = V_4 -> V_25 -> V_393 ;
if ( F_4 ( V_4 , V_394 ) ) {
V_124 -> V_305 |= F_93 ( V_395 ) ;
V_124 -> V_396 = V_4 -> V_25 -> V_396 ;
}
V_124 -> V_397 = V_4 -> V_25 -> V_397 ;
V_124 -> V_398 = V_4 -> V_25 -> V_398 ;
V_124 -> V_68 = V_4 -> V_25 -> V_68 ;
#endif
}
V_124 -> V_399 . V_170 = 0 ;
if ( V_13 -> V_20 . V_165 . V_400 )
V_124 -> V_399 . V_170 |= V_401 ;
if ( V_13 -> V_20 . V_165 . V_402 )
V_124 -> V_399 . V_170 |= V_403 ;
if ( V_13 -> V_20 . V_165 . V_404 )
V_124 -> V_399 . V_170 |= V_405 ;
V_124 -> V_399 . V_406 = V_13 -> V_20 . V_165 . V_406 ;
V_124 -> V_399 . V_407 = V_13 -> V_20 . V_165 . V_166 ;
V_124 -> V_408 . V_409 = 0 ;
V_124 -> V_408 . V_410 = F_93 ( V_411 ) |
F_93 ( V_412 ) |
F_93 ( V_413 ) |
F_93 ( V_414 ) |
F_93 ( V_415 ) |
F_93 ( V_416 ) |
F_93 ( V_417 ) ;
if ( F_4 ( V_4 , V_262 ) )
V_124 -> V_408 . V_409 |= F_93 ( V_411 ) ;
if ( F_4 ( V_4 , V_418 ) )
V_124 -> V_408 . V_409 |= F_93 ( V_412 ) ;
if ( V_4 -> V_4 . V_208 )
V_124 -> V_408 . V_409 |= F_93 ( V_413 ) ;
if ( F_4 ( V_4 , V_419 ) )
V_124 -> V_408 . V_409 |= F_93 ( V_414 ) ;
if ( F_4 ( V_4 , V_259 ) )
V_124 -> V_408 . V_409 |= F_93 ( V_415 ) ;
if ( F_4 ( V_4 , V_252 ) )
V_124 -> V_408 . V_409 |= F_93 ( V_416 ) ;
if ( F_4 ( V_4 , V_420 ) )
V_124 -> V_408 . V_409 |= F_93 ( V_417 ) ;
V_326 = F_221 ( V_4 ) ;
if ( V_326 != 0 ) {
V_124 -> V_305 |= F_93 ( V_421 ) ;
V_124 -> V_422 = V_326 ;
}
}
T_8 F_221 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_324 * V_325 = NULL ;
T_8 V_326 = 0 ;
if ( F_4 ( V_4 , V_328 ) )
V_325 = V_2 -> V_45 ;
if ( V_325 && V_325 -> V_83 -> V_423 )
V_326 = V_325 -> V_83 -> V_423 ( V_4 -> V_55 ) ;
else
V_326 = F_222 ( V_2 , V_4 ) ;
return V_326 ;
}
unsigned long F_143 ( struct V_3 * V_4 )
{
struct V_60 * V_277 = F_205 ( V_4 ) ;
if ( F_101 ( V_277 -> V_73 , V_4 -> V_316 . V_424 ) )
return V_277 -> V_73 ;
return V_4 -> V_316 . V_424 ;
}
