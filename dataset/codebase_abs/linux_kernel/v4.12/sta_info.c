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
struct V_94 * V_95 ;
T_1 V_96 ;
V_95 = F_62 ( V_13 ) ;
if ( ! V_95 )
goto V_88;
V_96 = ( V_95 -> V_97 . V_98 & V_99 ) >>
V_100 ;
switch ( V_96 ) {
case V_101 :
V_4 -> V_102 = V_93 ;
break;
case V_103 :
V_4 -> V_102 = V_104 ;
break;
case V_105 :
V_4 -> V_102 = V_106 ;
break;
default:
F_63 ( 1 ) ;
}
}
V_4 -> V_4 . V_107 = V_108 ;
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
return - V_109 ;
if ( F_63 ( F_67 ( V_4 -> V_4 . V_42 , V_13 -> V_20 . V_42 ) ||
F_68 ( V_4 -> V_4 . V_42 ) ) )
return - V_110 ;
F_24 () ;
F_69 ( & V_13 -> V_2 -> V_111 ) ;
if ( F_45 ( & V_13 -> V_2 -> V_34 , V_112 ) &&
F_70 ( & V_13 -> V_2 -> V_34 , V_4 -> V_42 , NULL ) ) {
F_26 () ;
return - V_113 ;
}
F_26 () ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_3 * V_4 )
{
enum V_114 V_115 ;
int V_116 = 0 ;
for ( V_115 = V_117 ; V_115 < V_4 -> V_76 ; V_115 ++ ) {
V_116 = F_72 ( V_2 , V_13 , V_4 , V_115 , V_115 + 1 ) ;
if ( V_116 )
break;
}
if ( ! V_116 ) {
if ( ! V_2 -> V_83 -> V_118 )
V_4 -> V_119 = true ;
return 0 ;
}
if ( V_13 -> V_20 . type == V_120 ) {
F_73 ( V_13 ,
L_3 ,
V_4 -> V_4 . V_42 , V_115 + 1 , V_116 ) ;
V_116 = 0 ;
}
for (; V_115 > V_117 ; V_115 -- )
F_63 ( F_72 ( V_2 , V_13 , V_4 , V_115 , V_115 - 1 ) ) ;
return V_116 ;
}
static int F_74 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_121 * V_122 = NULL ;
int V_116 = 0 ;
F_69 ( & V_2 -> V_111 ) ;
if ( F_27 ( V_13 , V_4 -> V_4 . V_42 ) ) {
V_116 = - V_123 ;
goto V_124;
}
V_122 = F_48 ( sizeof( struct V_121 ) , V_125 ) ;
if ( ! V_122 ) {
V_116 = - V_56 ;
goto V_124;
}
V_2 -> V_126 ++ ;
V_2 -> V_127 ++ ;
F_75 () ;
F_76 ( V_4 , V_128 ) ;
V_116 = F_34 ( V_2 , V_4 ) ;
if ( V_116 )
goto V_129;
F_77 ( & V_4 -> V_130 , & V_2 -> V_131 ) ;
V_116 = F_71 ( V_2 , V_13 , V_4 ) ;
if ( V_116 )
goto V_132;
F_76 ( V_4 , V_133 ) ;
F_6 ( V_4 , V_128 ) ;
F_78 ( V_4 ) ;
F_79 ( V_4 ) ;
V_122 -> V_134 = V_2 -> V_127 ;
F_80 ( V_13 -> V_135 , V_4 -> V_4 . V_42 , V_122 , V_125 ) ;
F_17 ( V_122 ) ;
F_31 ( V_13 , L_4 , V_4 -> V_4 . V_42 ) ;
F_24 () ;
F_81 ( & V_2 -> V_111 ) ;
if ( F_5 ( & V_13 -> V_20 ) )
F_82 ( V_13 ) ;
return 0 ;
V_132:
F_1 ( V_2 , V_4 ) ;
F_83 ( & V_4 -> V_130 ) ;
V_129:
V_2 -> V_126 -- ;
F_84 () ;
F_3 ( V_4 ) ;
V_124:
F_81 ( & V_2 -> V_111 ) ;
F_17 ( V_122 ) ;
F_24 () ;
return V_116 ;
}
int F_85 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_116 ;
F_86 () ;
F_87 ( & V_2 -> V_111 ) ;
V_116 = F_64 ( V_4 ) ;
if ( V_116 ) {
F_81 ( & V_2 -> V_111 ) ;
F_24 () ;
goto V_136;
}
V_116 = F_74 ( V_4 ) ;
if ( V_116 )
goto V_136;
return 0 ;
V_136:
F_20 ( V_2 , V_4 ) ;
return V_116 ;
}
int F_88 ( struct V_3 * V_4 )
{
int V_116 = F_85 ( V_4 ) ;
F_26 () ;
return V_116 ;
}
static inline void F_89 ( T_1 * V_137 , T_4 V_138 )
{
V_137 [ V_138 / 8 ] |= ( 1 << ( V_138 % 8 ) ) ;
}
static inline void F_90 ( T_1 * V_137 , T_4 V_138 )
{
V_137 [ V_138 / 8 ] &= ~ ( 1 << ( V_138 % 8 ) ) ;
}
static inline bool F_91 ( T_1 * V_137 , T_4 V_138 )
{
return V_137 [ V_138 / 8 ] & ( 1 << ( V_138 % 8 ) ) ;
}
static unsigned long F_92 ( int V_8 )
{
switch ( V_8 ) {
case V_139 :
return F_93 ( 6 ) | F_93 ( 7 ) ;
case V_140 :
return F_93 ( 4 ) | F_93 ( 5 ) ;
case V_141 :
return F_93 ( 0 ) | F_93 ( 3 ) ;
case V_142 :
return F_93 ( 1 ) | F_93 ( 2 ) ;
default:
F_63 ( 1 ) ;
return 0 ;
}
}
static void F_94 ( struct V_3 * V_4 , bool V_143 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_15 * V_16 ;
bool V_144 = false ;
T_1 V_145 = V_4 -> V_4 . V_146 ;
int V_8 ;
T_4 V_138 = V_4 -> V_4 . V_147 ;
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
if ( F_45 ( & V_2 -> V_34 , V_148 ) && ! V_2 -> V_83 -> V_149 )
return;
if ( V_4 -> V_50 )
goto V_150;
if ( V_145 == F_93 ( V_31 ) - 1 )
V_145 = 0 ;
if ( V_143 )
V_145 = F_93 ( V_31 ) - 1 ;
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ ) {
unsigned long V_151 ;
if ( V_145 & V_152 [ V_8 ] )
continue;
V_144 |= ! F_96 ( & V_4 -> V_35 [ V_8 ] ) ||
! F_96 ( & V_4 -> V_33 [ V_8 ] ) ;
if ( V_144 )
break;
V_151 = F_92 ( V_8 ) ;
V_144 |=
V_4 -> V_153 & V_151 ;
V_144 |=
V_4 -> V_154 & V_151 ;
}
V_150:
F_10 ( & V_2 -> V_155 ) ;
if ( V_144 == F_91 ( V_16 -> V_137 , V_138 ) )
goto V_156;
if ( V_144 )
F_89 ( V_16 -> V_137 , V_138 ) ;
else
F_90 ( V_16 -> V_137 , V_138 ) ;
if ( V_2 -> V_83 -> V_149 && ! F_63 ( V_4 -> V_50 ) ) {
V_2 -> V_157 = true ;
F_97 ( V_2 , & V_4 -> V_4 , V_144 ) ;
V_2 -> V_157 = false ;
}
V_156:
F_12 ( & V_2 -> V_155 ) ;
}
void F_98 ( struct V_3 * V_4 )
{
F_94 ( V_4 , false ) ;
}
static bool F_99 ( struct V_3 * V_4 , struct V_158 * V_159 )
{
struct V_160 * V_161 ;
int V_162 ;
if ( ! V_159 )
return false ;
V_161 = F_100 ( V_159 ) ;
V_162 = ( V_4 -> V_163 *
V_4 -> V_13 -> V_20 . V_164 . V_165 *
32 / 15625 ) * V_166 ;
if ( V_162 < V_167 )
V_162 = V_167 ;
return F_101 ( V_74 , V_161 -> V_168 . V_74 + V_162 ) ;
}
static bool F_102 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_8 )
{
unsigned long V_169 ;
struct V_158 * V_159 ;
for (; ; ) {
F_103 ( & V_4 -> V_35 [ V_8 ] . V_30 , V_169 ) ;
V_159 = F_104 ( & V_4 -> V_35 [ V_8 ] ) ;
if ( F_99 ( V_4 , V_159 ) )
V_159 = F_105 ( & V_4 -> V_35 [ V_8 ] ) ;
else
V_159 = NULL ;
F_106 ( & V_4 -> V_35 [ V_8 ] . V_30 , V_169 ) ;
if ( ! V_159 )
break;
F_107 ( & V_2 -> V_34 , V_159 ) ;
}
for (; ; ) {
F_103 ( & V_4 -> V_33 [ V_8 ] . V_30 , V_169 ) ;
V_159 = F_104 ( & V_4 -> V_33 [ V_8 ] ) ;
if ( F_99 ( V_4 , V_159 ) )
V_159 = F_105 ( & V_4 -> V_33 [ V_8 ] ) ;
else
V_159 = NULL ;
F_106 ( & V_4 -> V_33 [ V_8 ] . V_30 , V_169 ) ;
if ( ! V_159 )
break;
V_2 -> V_32 -- ;
F_108 ( V_4 -> V_13 , L_5 ,
V_4 -> V_4 . V_42 ) ;
F_107 ( & V_2 -> V_34 , V_159 ) ;
}
F_98 ( V_4 ) ;
return ! ( F_96 ( & V_4 -> V_33 [ V_8 ] ) &&
F_96 ( & V_4 -> V_35 [ V_8 ] ) ) ;
}
static bool F_109 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_170 = false ;
int V_8 ;
if ( ! V_4 -> V_13 -> V_23 &&
! F_5 ( & V_4 -> V_13 -> V_20 ) )
return false ;
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ )
V_170 |=
F_102 ( V_2 , V_4 , V_8 ) ;
return V_170 ;
}
static int T_5 F_110 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
int V_171 ;
F_86 () ;
if ( ! V_4 )
return - V_172 ;
V_2 = V_4 -> V_2 ;
V_13 = V_4 -> V_13 ;
F_69 ( & V_2 -> V_111 ) ;
F_76 ( V_4 , V_128 ) ;
F_111 ( V_4 , V_173 ) ;
F_112 ( V_2 , V_4 ) ;
V_171 = F_1 ( V_2 , V_4 ) ;
if ( F_63 ( V_171 ) )
return V_171 ;
if ( F_4 ( V_4 , V_174 ) ) {
F_113 ( V_2 , V_13 , & V_4 -> V_4 ) ;
F_6 ( V_4 , V_174 ) ;
}
F_83 ( & V_4 -> V_130 ) ;
V_4 -> V_175 = true ;
F_114 ( V_2 , V_4 -> V_13 , V_4 ) ;
if ( V_13 -> V_20 . type == V_22 &&
F_115 ( V_13 -> V_24 . V_176 . V_4 ) == V_4 )
F_116 ( V_13 -> V_24 . V_176 . V_4 , NULL ) ;
return 0 ;
}
static void F_117 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_121 * V_122 ;
int V_171 ;
F_86 () ;
F_69 ( & V_2 -> V_111 ) ;
F_118 ( V_2 , V_4 ) ;
F_94 ( V_4 , true ) ;
V_4 -> V_50 = true ;
V_2 -> V_126 -- ;
V_2 -> V_127 ++ ;
while ( V_4 -> V_76 > V_77 ) {
V_171 = F_119 ( V_4 , V_4 -> V_76 - 1 ) ;
if ( V_171 ) {
F_95 ( 1 ) ;
break;
}
}
if ( V_4 -> V_119 ) {
V_171 = F_72 ( V_2 , V_13 , V_4 , V_77 ,
V_117 ) ;
F_95 ( V_171 != 0 ) ;
}
F_31 ( V_13 , L_6 , V_4 -> V_4 . V_42 ) ;
V_122 = F_48 ( sizeof( * V_122 ) , V_125 ) ;
if ( V_122 )
F_120 ( V_4 , V_122 ) ;
F_121 ( V_13 -> V_135 , V_4 -> V_4 . V_42 , V_122 , V_125 ) ;
F_17 ( V_122 ) ;
F_122 ( V_4 ) ;
F_123 ( V_4 ) ;
F_19 ( V_4 ) ;
}
int T_5 F_124 ( struct V_3 * V_4 )
{
int V_116 = F_110 ( V_4 ) ;
if ( V_116 )
return V_116 ;
F_84 () ;
F_117 ( V_4 ) ;
return 0 ;
}
int F_125 ( struct V_12 * V_13 , const T_1 * V_42 )
{
struct V_3 * V_4 ;
int V_171 ;
F_87 ( & V_13 -> V_2 -> V_111 ) ;
V_4 = F_23 ( V_13 , V_42 ) ;
V_171 = F_124 ( V_4 ) ;
F_81 ( & V_13 -> V_2 -> V_111 ) ;
return V_171 ;
}
int F_126 ( struct V_12 * V_13 ,
const T_1 * V_42 )
{
struct V_3 * V_4 ;
int V_171 ;
F_87 ( & V_13 -> V_2 -> V_111 ) ;
V_4 = F_27 ( V_13 , V_42 ) ;
V_171 = F_124 ( V_4 ) ;
F_81 ( & V_13 -> V_2 -> V_111 ) ;
return V_171 ;
}
static void F_127 ( unsigned long V_177 )
{
struct V_1 * V_2 = (struct V_1 * ) V_177 ;
struct V_3 * V_4 ;
bool V_178 = false ;
F_24 () ;
F_29 (sta, &local->sta_list, list)
if ( F_109 ( V_2 , V_4 ) )
V_178 = true ;
F_26 () ;
if ( V_2 -> V_179 )
return;
if ( ! V_178 )
return;
F_128 ( & V_2 -> V_180 ,
F_129 ( V_74 + V_181 ) ) ;
}
int F_130 ( struct V_1 * V_2 )
{
int V_116 ;
V_116 = F_131 ( & V_2 -> V_5 , & V_7 ) ;
if ( V_116 )
return V_116 ;
F_50 ( & V_2 -> V_155 ) ;
F_52 ( & V_2 -> V_111 ) ;
F_132 ( & V_2 -> V_131 ) ;
F_133 ( & V_2 -> V_180 , F_127 ,
( unsigned long ) V_2 ) ;
return 0 ;
}
void F_134 ( struct V_1 * V_2 )
{
F_135 ( & V_2 -> V_180 ) ;
F_136 ( & V_2 -> V_5 ) ;
}
int F_137 ( struct V_12 * V_13 , bool V_182 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 , * V_43 ;
F_138 ( V_183 ) ;
int V_171 = 0 ;
F_86 () ;
F_63 ( V_182 && V_13 -> V_20 . type != V_21 ) ;
F_63 ( V_182 && ! V_13 -> V_23 ) ;
F_87 ( & V_2 -> V_111 ) ;
F_139 (sta, tmp, &local->sta_list, list) {
if ( V_13 == V_4 -> V_13 ||
( V_182 && V_13 -> V_23 == V_4 -> V_13 -> V_23 ) ) {
if ( ! F_63 ( F_110 ( V_4 ) ) )
F_140 ( & V_4 -> V_183 , & V_183 ) ;
V_171 ++ ;
}
}
if ( ! F_141 ( & V_183 ) ) {
F_84 () ;
F_139 (sta, tmp, &free_list, free_list)
F_117 ( V_4 ) ;
}
F_81 ( & V_2 -> V_111 ) ;
return V_171 ;
}
void F_142 ( struct V_12 * V_13 ,
unsigned long V_184 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 , * V_43 ;
F_87 ( & V_2 -> V_111 ) ;
F_139 (sta, tmp, &local->sta_list, list) {
unsigned long V_185 = F_143 ( V_4 ) ;
if ( V_13 != V_4 -> V_13 )
continue;
if ( F_144 ( V_185 + V_184 ) ) {
F_31 ( V_4 -> V_13 , L_7 ,
V_4 -> V_4 . V_42 ) ;
if ( F_5 ( & V_13 -> V_20 ) &&
F_4 ( V_4 , V_17 ) )
F_7 ( & V_13 -> V_24 . V_25 . V_16 . V_26 ) ;
F_63 ( F_124 ( V_4 ) ) ;
}
}
F_81 ( & V_2 -> V_111 ) ;
}
struct V_186 * F_70 ( struct V_57 * V_34 ,
const T_1 * V_42 ,
const T_1 * V_187 )
{
struct V_1 * V_2 = F_145 ( V_34 ) ;
struct V_41 * V_43 ;
struct V_3 * V_4 ;
F_25 (local, addr, sta, tmp) {
if ( V_187 &&
! F_67 ( V_4 -> V_13 -> V_20 . V_42 , V_187 ) )
continue;
if ( ! V_4 -> V_119 )
return NULL ;
return & V_4 -> V_4 ;
}
return NULL ;
}
struct V_186 * F_146 ( struct V_188 * V_20 ,
const T_1 * V_42 )
{
struct V_3 * V_4 ;
if ( ! V_20 )
return NULL ;
V_4 = F_27 ( F_147 ( V_20 ) , V_42 ) ;
if ( ! V_4 )
return NULL ;
if ( ! V_4 -> V_119 )
return NULL ;
return & V_4 -> V_4 ;
}
void F_39 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_189 V_40 ;
int V_190 = 0 , V_191 = 0 , V_8 , V_9 ;
unsigned long V_169 ;
struct V_15 * V_16 ;
if ( V_13 -> V_20 . type == V_22 )
V_13 = F_37 ( V_13 -> V_23 , struct V_12 ,
V_24 . V_192 ) ;
if ( V_13 -> V_20 . type == V_21 )
V_16 = & V_13 -> V_23 -> V_16 ;
else if ( F_5 ( & V_13 -> V_20 ) )
V_16 = & V_13 -> V_24 . V_25 . V_16 ;
else
return;
F_6 ( V_4 , V_193 ) ;
F_148 ( F_149 ( V_37 ) > 1 ) ;
V_4 -> V_153 = 0 ;
V_4 -> V_154 = 0 ;
if ( ! F_45 ( & V_2 -> V_34 , V_148 ) )
F_150 ( V_2 , V_13 , V_194 , & V_4 -> V_4 ) ;
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
int V_195 = F_13 ( & V_40 ) , V_43 ;
F_103 ( & V_4 -> V_35 [ V_8 ] . V_30 , V_169 ) ;
F_154 ( & V_4 -> V_35 [ V_8 ] , & V_40 ) ;
F_106 ( & V_4 -> V_35 [ V_8 ] . V_30 , V_169 ) ;
V_43 = F_13 ( & V_40 ) ;
V_190 += V_43 - V_195 ;
V_195 = V_43 ;
F_103 ( & V_4 -> V_33 [ V_8 ] . V_30 , V_169 ) ;
F_154 ( & V_4 -> V_33 [ V_8 ] , & V_40 ) ;
F_106 ( & V_4 -> V_33 [ V_8 ] . V_30 , V_169 ) ;
V_43 = F_13 ( & V_40 ) ;
V_191 += V_43 - V_195 ;
}
F_155 ( V_2 , & V_40 ) ;
F_6 ( V_4 , V_19 ) ;
F_6 ( V_4 , V_51 ) ;
F_6 ( V_4 , V_52 ) ;
F_156 ( & V_4 -> V_61 ) ;
F_7 ( & V_16 -> V_26 ) ;
if ( ! F_5 ( & V_13 -> V_20 ) &&
! F_157 ( V_4 -> V_102 ,
V_13 -> V_92 ) &&
V_4 -> V_102 != V_13 -> V_23 -> V_196 &&
F_158 ( V_4 ) != 1 ) {
F_159 ( V_13 ,
L_8 ,
V_4 -> V_4 . V_42 ) ;
F_160 ( V_13 , V_13 -> V_23 -> V_196 ,
V_4 -> V_4 . V_42 ,
V_13 -> V_20 . V_164 . V_197 ) ;
}
V_2 -> V_32 -= V_191 ;
F_98 ( V_4 ) ;
F_108 ( V_13 ,
L_9 ,
V_4 -> V_4 . V_42 , V_4 -> V_4 . V_147 , V_190 , V_191 ) ;
F_161 ( V_4 ) ;
}
static void F_162 ( struct V_3 * V_4 , int V_198 ,
enum V_199 V_200 ,
bool V_201 , bool V_202 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_203 * V_204 ;
struct V_158 * V_159 ;
int V_86 = sizeof( * V_204 ) ;
T_6 V_205 ;
bool V_206 = V_4 -> V_4 . V_207 ;
struct V_160 * V_161 ;
struct V_208 * V_209 ;
if ( V_206 ) {
V_205 = F_61 ( V_210 |
V_211 |
V_212 ) ;
} else {
V_86 -= 2 ;
V_205 = F_61 ( V_210 |
V_213 |
V_212 ) ;
}
V_159 = F_163 ( V_2 -> V_34 . V_214 + V_86 ) ;
if ( ! V_159 )
return;
F_164 ( V_159 , V_2 -> V_34 . V_214 ) ;
V_204 = ( void * ) F_165 ( V_159 , V_86 ) ;
V_204 -> V_215 = V_205 ;
V_204 -> V_216 = 0 ;
memcpy ( V_204 -> V_217 , V_4 -> V_4 . V_42 , V_70 ) ;
memcpy ( V_204 -> V_218 , V_13 -> V_20 . V_42 , V_70 ) ;
memcpy ( V_204 -> V_219 , V_13 -> V_20 . V_42 , V_70 ) ;
V_204 -> V_220 = 0 ;
V_159 -> V_221 = V_198 ;
F_166 ( V_159 , V_222 [ V_198 ] ) ;
if ( V_206 ) {
V_204 -> V_223 = F_61 ( V_198 ) ;
if ( V_200 == V_224 ) {
V_204 -> V_223 |=
F_61 ( V_225 ) ;
if ( V_202 )
V_204 -> V_215 |=
F_61 ( V_226 ) ;
}
}
V_161 = F_100 ( V_159 ) ;
V_161 -> V_169 |= V_227 |
V_228 |
V_229 ;
V_161 -> V_168 . V_169 |= V_230 ;
if ( V_201 )
F_167 ( V_2 , V_4 , F_93 ( V_198 ) , 1 ,
V_200 , false ) ;
V_159 -> V_135 = V_13 -> V_135 ;
F_24 () ;
V_209 = F_168 ( V_13 -> V_20 . V_209 ) ;
if ( F_63 ( ! V_209 ) ) {
F_26 () ;
F_169 ( V_159 ) ;
return;
}
V_161 -> V_231 = V_209 -> V_232 . V_233 -> V_231 ;
F_170 ( V_13 , V_4 , V_159 ) ;
F_26 () ;
}
static int F_171 ( unsigned long V_151 )
{
if ( V_151 & 0xF8 )
return F_172 ( V_151 ) - 1 ;
if ( V_151 & F_93 ( 0 ) )
return 0 ;
return F_172 ( V_151 ) - 1 ;
}
static bool
F_173 ( struct V_3 * V_4 , T_1 V_234 ,
enum V_199 V_200 ,
unsigned long V_235 )
{
int V_8 ;
if ( V_200 == V_236 &&
F_174 ( V_235 ) > 1 )
return true ;
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ ) {
if ( V_234 & V_152 [ V_8 ] )
continue;
if ( ! F_96 ( & V_4 -> V_35 [ V_8 ] ) ||
! F_96 ( & V_4 -> V_33 [ V_8 ] ) )
return true ;
}
return false ;
}
static void
F_175 ( struct V_3 * V_4 , int V_237 , T_1 V_234 ,
enum V_199 V_200 ,
struct V_189 * V_238 ,
unsigned long * V_235 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ ) {
unsigned long V_151 ;
if ( V_234 & V_152 [ V_8 ] )
continue;
V_151 = F_92 ( V_8 ) ;
if ( F_96 ( V_238 ) ) {
* V_235 |=
V_4 -> V_153 & V_151 ;
* V_235 |= V_4 -> V_154 & V_151 ;
}
if ( ! * V_235 ) {
struct V_158 * V_159 ;
while ( V_237 > 0 ) {
V_159 = F_176 ( & V_4 -> V_35 [ V_8 ] ) ;
if ( ! V_159 ) {
V_159 = F_176 (
& V_4 -> V_33 [ V_8 ] ) ;
if ( V_159 )
V_2 -> V_32 -- ;
}
if ( ! V_159 )
break;
V_237 -- ;
F_177 ( V_238 , V_159 ) ;
}
}
if ( ! F_96 ( & V_4 -> V_35 [ V_8 ] ) ||
! F_96 ( & V_4 -> V_33 [ V_8 ] ) )
break;
}
}
static void
F_178 ( struct V_3 * V_4 ,
int V_237 , T_1 V_234 ,
enum V_199 V_200 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
unsigned long V_235 = 0 ;
struct V_189 V_238 ;
bool V_202 ;
F_76 ( V_4 , V_193 ) ;
F_179 ( & V_238 ) ;
F_175 ( V_4 , V_237 , V_234 , V_200 ,
& V_238 , & V_235 ) ;
V_202 = F_173 ( V_4 , V_234 , V_200 , V_235 ) ;
if ( V_235 && V_200 == V_236 )
V_235 =
F_93 ( F_171 ( V_235 ) ) ;
if ( F_96 ( & V_238 ) && ! V_235 ) {
int V_198 , V_8 ;
for ( V_8 = V_139 ; V_8 < V_31 ; V_8 ++ )
if ( ! ( V_234 & V_152 [ V_8 ] ) )
break;
V_198 = 7 - 2 * V_8 ;
F_162 ( V_4 , V_198 , V_200 , true , false ) ;
} else if ( ! V_235 ) {
struct V_189 V_40 ;
struct V_158 * V_159 ;
int V_239 = 0 ;
T_4 V_151 = 0 ;
bool V_240 = false ;
F_60 ( & V_40 ) ;
while ( ( V_159 = F_105 ( & V_238 ) ) ) {
struct V_160 * V_161 = F_100 ( V_159 ) ;
struct V_241 * V_242 = ( void * ) V_159 -> V_177 ;
T_1 * V_243 = NULL ;
V_239 ++ ;
V_161 -> V_169 |= V_227 ;
V_161 -> V_168 . V_169 |= V_230 ;
if ( V_202 || ! F_96 ( & V_238 ) )
V_242 -> V_215 |=
F_61 ( V_226 ) ;
else
V_242 -> V_215 &=
F_61 ( ~ V_226 ) ;
if ( F_180 ( V_242 -> V_215 ) ||
F_181 ( V_242 -> V_215 ) )
V_243 = F_182 ( V_242 ) ;
V_151 |= F_93 ( V_159 -> V_221 ) ;
F_177 ( & V_40 , V_159 ) ;
if ( ! F_96 ( & V_238 ) )
continue;
if ( V_200 != V_224 ) {
V_161 -> V_169 |= V_228 |
V_229 ;
break;
}
if ( V_243 ) {
* V_243 |= V_225 ;
V_161 -> V_169 |= V_228 |
V_229 ;
} else {
V_242 -> V_215 |=
F_61 ( V_226 ) ;
V_240 = true ;
V_239 ++ ;
}
break;
}
F_167 ( V_2 , V_4 , V_151 , V_239 ,
V_200 , V_202 ) ;
F_155 ( V_2 , & V_40 ) ;
if ( V_240 )
F_162 (
V_4 , F_171 ( V_151 ) ,
V_200 , false , false ) ;
F_98 ( V_4 ) ;
} else {
int V_198 ;
F_183 ( V_2 , V_4 , V_235 ,
V_237 , V_200 , V_202 ) ;
if ( ! V_4 -> V_4 . V_27 [ 0 ] )
return;
for ( V_198 = 0 ; V_198 < F_8 ( V_4 -> V_4 . V_27 ) ; V_198 ++ ) {
if ( ! ( V_235 & F_93 ( V_198 ) ) ||
F_151 ( V_4 -> V_4 . V_27 [ V_198 ] ) )
continue;
F_98 ( V_4 ) ;
break;
}
}
}
void F_41 ( struct V_3 * V_4 )
{
T_1 V_244 = V_4 -> V_4 . V_146 ;
if ( V_244 == F_93 ( V_31 ) - 1 )
V_244 = 0 ;
F_178 ( V_4 , 1 , V_244 ,
V_236 ) ;
}
void F_42 ( struct V_3 * V_4 )
{
int V_237 = V_4 -> V_4 . V_245 ;
T_1 V_246 = V_4 -> V_4 . V_146 ;
if ( ! V_246 )
return;
switch ( V_4 -> V_4 . V_245 ) {
case 1 :
V_237 = 2 ;
break;
case 2 :
V_237 = 4 ;
break;
case 3 :
V_237 = 6 ;
break;
case 0 :
V_237 = 128 ;
break;
}
F_178 ( V_4 , V_237 , ~ V_246 ,
V_224 ) ;
}
void F_184 ( struct V_57 * V_34 ,
struct V_186 * V_247 , bool V_248 )
{
struct V_3 * V_4 = F_37 ( V_247 , struct V_3 , V_4 ) ;
F_185 ( V_4 -> V_2 , V_247 , V_248 ) ;
if ( V_248 ) {
F_76 ( V_4 , V_18 ) ;
F_186 ( V_4 ) ;
return;
}
if ( ! F_4 ( V_4 , V_18 ) )
return;
if ( ! F_4 ( V_4 , V_17 ) ) {
F_76 ( V_4 , V_19 ) ;
F_6 ( V_4 , V_18 ) ;
F_187 ( V_34 , & V_4 -> V_36 ) ;
} else if ( F_4 ( V_4 , V_51 ) ||
F_4 ( V_4 , V_52 ) ) {
F_6 ( V_4 , V_18 ) ;
F_187 ( V_34 , & V_4 -> V_36 ) ;
} else {
F_6 ( V_4 , V_18 ) ;
F_161 ( V_4 ) ;
}
}
void F_188 ( struct V_186 * V_247 )
{
struct V_3 * V_4 = F_37 ( V_247 , struct V_3 , V_4 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_189 ( V_2 , V_247 ) ;
F_6 ( V_4 , V_193 ) ;
}
void F_190 ( struct V_186 * V_247 , int V_198 )
{
struct V_3 * V_4 = F_37 ( V_247 , struct V_3 , V_4 ) ;
enum V_199 V_200 ;
bool V_202 ;
F_191 ( V_4 -> V_2 , V_247 , V_198 ) ;
V_200 = V_224 ;
V_202 = F_173 ( V_4 , ~ V_4 -> V_4 . V_146 ,
V_200 , 0 ) ;
F_162 ( V_4 , V_198 , V_200 , false , V_202 ) ;
}
void F_192 ( struct V_186 * V_247 ,
T_1 V_198 , bool V_191 )
{
struct V_3 * V_4 = F_37 ( V_247 , struct V_3 , V_4 ) ;
if ( F_63 ( V_198 >= V_37 ) )
return;
F_193 ( V_4 -> V_2 , V_247 , V_198 , V_191 ) ;
if ( V_191 )
F_194 ( V_198 , & V_4 -> V_153 ) ;
else
F_195 ( V_198 , & V_4 -> V_153 ) ;
F_98 ( V_4 ) ;
}
static void
F_196 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
bool V_249 = V_13 -> V_20 . V_250 ;
struct V_3 * V_4 ;
F_24 () ;
F_29 (sta, &local->sta_list, list) {
if ( V_13 != V_4 -> V_13 ||
! F_4 ( V_4 , V_251 ) )
continue;
if ( ! V_4 -> V_4 . V_252 ) {
V_249 = false ;
break;
}
}
F_26 () ;
if ( V_249 != V_13 -> V_20 . V_164 . V_249 ) {
V_13 -> V_20 . V_164 . V_249 = V_249 ;
F_197 ( V_13 , V_253 ) ;
}
}
int F_119 ( struct V_3 * V_4 ,
enum V_114 V_254 )
{
F_86 () ;
if ( V_4 -> V_76 == V_254 )
return 0 ;
switch ( V_254 ) {
case V_77 :
if ( V_4 -> V_76 != V_255 )
return - V_110 ;
break;
case V_255 :
if ( V_4 -> V_76 != V_77 &&
V_4 -> V_76 != V_256 )
return - V_110 ;
break;
case V_256 :
if ( V_4 -> V_76 != V_255 &&
V_4 -> V_76 != V_257 )
return - V_110 ;
break;
case V_257 :
if ( V_4 -> V_76 != V_256 )
return - V_110 ;
break;
default:
F_198 ( 1 , L_10 , V_254 ) ;
return - V_110 ;
}
F_31 ( V_4 -> V_13 , L_11 ,
V_4 -> V_4 . V_42 , V_254 ) ;
if ( F_4 ( V_4 , V_133 ) ) {
int V_116 = F_72 ( V_4 -> V_2 , V_4 -> V_13 , V_4 ,
V_4 -> V_76 , V_254 ) ;
if ( V_116 )
return V_116 ;
}
switch ( V_254 ) {
case V_77 :
if ( V_4 -> V_76 == V_255 )
F_195 ( V_258 , & V_4 -> V_259 ) ;
break;
case V_255 :
if ( V_4 -> V_76 == V_77 ) {
F_194 ( V_258 , & V_4 -> V_259 ) ;
} else if ( V_4 -> V_76 == V_256 ) {
F_195 ( V_251 , & V_4 -> V_259 ) ;
F_199 ( V_4 -> V_13 ) ;
if ( ! V_4 -> V_4 . V_252 )
F_196 ( V_4 -> V_13 ) ;
}
break;
case V_256 :
if ( V_4 -> V_76 == V_255 ) {
F_194 ( V_251 , & V_4 -> V_259 ) ;
F_199 ( V_4 -> V_13 ) ;
if ( ! V_4 -> V_4 . V_252 )
F_196 ( V_4 -> V_13 ) ;
} else if ( V_4 -> V_76 == V_257 ) {
F_200 ( V_4 -> V_13 ) ;
F_195 ( V_260 , & V_4 -> V_259 ) ;
F_186 ( V_4 ) ;
F_201 ( V_4 ) ;
}
break;
case V_257 :
if ( V_4 -> V_76 == V_256 ) {
F_202 ( V_4 -> V_13 ) ;
F_194 ( V_260 , & V_4 -> V_259 ) ;
F_161 ( V_4 ) ;
F_203 ( V_4 ) ;
}
break;
default:
break;
}
V_4 -> V_76 = V_254 ;
return 0 ;
}
T_1 F_158 ( struct V_3 * V_4 )
{
struct V_261 * V_97 = & V_4 -> V_4 . V_97 ;
T_1 V_262 ;
if ( ! V_4 -> V_4 . V_97 . V_263 )
return 1 ;
if ( V_4 -> V_4 . V_264 . V_265 ) {
int V_9 ;
T_4 V_266 =
F_204 ( V_4 -> V_4 . V_264 . V_267 . V_266 ) ;
for ( V_9 = 7 ; V_9 >= 0 ; V_9 -- )
if ( ( V_266 & ( 0x3 << ( V_9 * 2 ) ) ) !=
V_268 )
return V_9 + 1 ;
}
if ( V_97 -> V_269 . V_270 [ 3 ] )
V_262 = 4 ;
else if ( V_97 -> V_269 . V_270 [ 2 ] )
V_262 = 3 ;
else if ( V_97 -> V_269 . V_270 [ 1 ] )
V_262 = 2 ;
else
V_262 = 1 ;
if ( ! ( V_97 -> V_269 . V_271 & V_272 ) )
return V_262 ;
return ( ( V_97 -> V_269 . V_271 & V_273 )
>> V_274 ) + 1 ;
}
static struct V_60 *
F_205 ( struct V_3 * V_4 )
{
struct V_60 * V_275 = & V_4 -> V_72 ;
struct V_1 * V_2 = V_4 -> V_2 ;
int V_276 ;
if ( ! F_45 ( & V_2 -> V_34 , V_59 ) )
return V_275 ;
F_206 (cpu) {
struct V_60 * V_277 ;
V_277 = F_207 ( V_4 -> V_47 , V_276 ) ;
if ( F_101 ( V_277 -> V_73 , V_275 -> V_73 ) )
V_275 = V_277 ;
}
return V_275 ;
}
static void F_208 ( struct V_1 * V_2 , T_4 V_278 ,
struct V_279 * V_280 )
{
V_280 -> V_281 = F_209 ( V_282 , V_278 ) ;
switch ( F_209 ( TYPE , V_278 ) ) {
case V_283 :
V_280 -> V_169 = V_284 ;
V_280 -> V_269 = F_209 ( V_285 , V_278 ) ;
V_280 -> V_286 = F_209 ( V_287 , V_278 ) ;
if ( F_209 ( V_288 , V_278 ) )
V_280 -> V_169 |= V_289 ;
break;
case V_290 :
V_280 -> V_169 = V_291 ;
V_280 -> V_269 = F_209 ( V_292 , V_278 ) ;
if ( F_209 ( V_288 , V_278 ) )
V_280 -> V_169 |= V_289 ;
break;
case V_293 : {
struct V_94 * V_95 ;
T_4 V_294 ;
unsigned int V_295 ;
int V_231 = F_209 ( V_296 , V_278 ) ;
int V_297 = F_209 ( V_298 , V_278 ) ;
V_280 -> V_169 = 0 ;
V_95 = V_2 -> V_34 . V_299 -> V_300 [ V_231 ] ;
V_294 = V_95 -> V_301 [ V_297 ] . V_302 ;
if ( V_280 -> V_281 == V_303 )
V_295 = 2 ;
else if ( V_280 -> V_281 == V_304 )
V_295 = 1 ;
else
V_295 = 0 ;
V_280 -> V_305 = F_210 ( V_294 , 1 << V_295 ) ;
break;
}
}
}
static int F_211 ( struct V_3 * V_4 , struct V_279 * V_280 )
{
T_4 V_278 = F_212 ( F_205 ( V_4 ) -> V_306 ) ;
if ( V_278 == V_307 )
return - V_110 ;
F_208 ( V_4 -> V_2 , V_278 , V_280 ) ;
return 0 ;
}
static void F_213 ( struct V_3 * V_4 ,
struct V_308 * V_309 ,
int V_198 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( ! ( V_309 -> V_310 & F_93 ( V_311 ) ) ) {
unsigned int V_312 ;
do {
V_312 = F_214 ( & V_4 -> V_72 . V_75 ) ;
V_309 -> V_313 = V_4 -> V_72 . V_314 [ V_198 ] ;
} while ( F_215 ( & V_4 -> V_72 . V_75 , V_312 ) );
V_309 -> V_310 |= F_93 ( V_311 ) ;
}
if ( ! ( V_309 -> V_310 & F_93 ( V_315 ) ) ) {
V_309 -> V_310 |= F_93 ( V_315 ) ;
V_309 -> V_316 = V_4 -> V_317 . V_314 [ V_198 ] ;
}
if ( ! ( V_309 -> V_310 & F_93 ( V_318 ) ) &&
F_45 ( & V_2 -> V_34 , V_319 ) ) {
V_309 -> V_310 |= F_93 ( V_318 ) ;
V_309 -> V_320 = V_4 -> V_321 . V_322 [ V_198 ] ;
}
if ( ! ( V_309 -> V_310 & F_93 ( V_323 ) ) &&
F_45 ( & V_2 -> V_34 , V_319 ) ) {
V_309 -> V_310 |= F_93 ( V_323 ) ;
V_309 -> V_324 = V_4 -> V_321 . V_325 [ V_198 ] ;
}
}
static inline T_7 F_216 ( struct V_60 * V_326 )
{
unsigned int V_312 ;
T_7 V_327 ;
do {
V_312 = F_214 ( & V_326 -> V_75 ) ;
V_327 = V_326 -> V_328 ;
} while ( F_215 ( & V_326 -> V_75 , V_312 ) );
return V_327 ;
}
void F_120 ( struct V_3 * V_4 , struct V_121 * V_122 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
T_8 V_329 = 0 ;
int V_9 , V_8 , V_276 ;
struct V_60 * V_330 ;
V_330 = F_205 ( V_4 ) ;
V_122 -> V_134 = V_13 -> V_2 -> V_127 ;
if ( V_13 -> V_20 . type == V_331 )
V_122 -> V_332 = V_13 -> V_24 . V_333 . V_334 ;
F_217 ( V_2 , V_13 , & V_4 -> V_4 , V_122 ) ;
V_122 -> V_310 |= F_93 ( V_335 ) |
F_93 ( V_336 ) |
F_93 ( V_337 ) |
F_93 ( V_338 ) |
F_93 ( V_339 ) ;
if ( V_13 -> V_20 . type == V_331 ) {
V_122 -> V_340 = V_13 -> V_24 . V_333 . V_340 ;
V_122 -> V_310 |= F_93 ( V_341 ) ;
}
V_122 -> V_342 = F_55 () - V_4 -> V_80 ;
V_122 -> V_343 =
F_218 ( V_74 - F_143 ( V_4 ) ) ;
if ( ! ( V_122 -> V_310 & ( F_93 ( V_344 ) |
F_93 ( V_345 ) ) ) ) {
V_122 -> V_346 = 0 ;
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ )
V_122 -> V_346 += V_4 -> V_317 . V_328 [ V_8 ] ;
V_122 -> V_310 |= F_93 ( V_344 ) ;
}
if ( ! ( V_122 -> V_310 & F_93 ( V_347 ) ) ) {
V_122 -> V_348 = 0 ;
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ )
V_122 -> V_348 += V_4 -> V_317 . V_349 [ V_8 ] ;
V_122 -> V_310 |= F_93 ( V_347 ) ;
}
if ( ! ( V_122 -> V_310 & ( F_93 ( V_350 ) |
F_93 ( V_351 ) ) ) ) {
V_122 -> V_352 += F_216 ( & V_4 -> V_72 ) ;
if ( V_4 -> V_47 ) {
F_206 (cpu) {
struct V_60 * V_353 ;
V_353 = F_207 ( V_4 -> V_47 , V_276 ) ;
V_122 -> V_352 += F_216 ( V_353 ) ;
}
}
V_122 -> V_310 |= F_93 ( V_350 ) ;
}
if ( ! ( V_122 -> V_310 & F_93 ( V_354 ) ) ) {
V_122 -> V_355 = V_4 -> V_72 . V_349 ;
if ( V_4 -> V_47 ) {
F_206 (cpu) {
struct V_60 * V_353 ;
V_353 = F_207 ( V_4 -> V_47 , V_276 ) ;
V_122 -> V_355 += V_353 -> V_349 ;
}
}
V_122 -> V_310 |= F_93 ( V_354 ) ;
}
if ( ! ( V_122 -> V_310 & F_93 ( V_356 ) ) ) {
V_122 -> V_357 = V_4 -> V_321 . V_358 ;
V_122 -> V_310 |= F_93 ( V_356 ) ;
}
if ( ! ( V_122 -> V_310 & F_93 ( V_359 ) ) ) {
V_122 -> V_360 = V_4 -> V_321 . V_361 ;
V_122 -> V_310 |= F_93 ( V_359 ) ;
}
V_122 -> V_362 = V_4 -> V_72 . V_363 ;
if ( V_4 -> V_47 ) {
F_206 (cpu) {
struct V_60 * V_353 ;
V_353 = F_207 ( V_4 -> V_47 , V_276 ) ;
V_122 -> V_362 += V_353 -> V_363 ;
}
}
if ( V_13 -> V_20 . type == V_331 &&
! ( V_13 -> V_20 . V_364 & V_365 ) ) {
V_122 -> V_310 |= F_93 ( V_366 ) |
F_93 ( V_367 ) ;
V_122 -> V_368 = F_219 ( & V_13 -> V_20 ) ;
}
if ( F_45 ( & V_4 -> V_2 -> V_34 , V_369 ) ||
F_45 ( & V_4 -> V_2 -> V_34 , V_370 ) ) {
if ( ! ( V_122 -> V_310 & F_93 ( V_371 ) ) ) {
V_122 -> signal = ( V_372 ) V_330 -> V_373 ;
V_122 -> V_310 |= F_93 ( V_371 ) ;
}
if ( ! V_4 -> V_47 &&
! ( V_122 -> V_310 & F_93 ( V_374 ) ) ) {
V_122 -> V_375 =
- F_220 ( & V_4 -> V_81 . signal ) ;
V_122 -> V_310 |= F_93 ( V_374 ) ;
}
}
if ( V_330 -> V_376 &&
! ( V_122 -> V_310 & ( F_93 ( V_377 ) |
F_93 ( V_378 ) ) ) ) {
V_122 -> V_310 |= F_93 ( V_377 ) ;
if ( ! V_4 -> V_47 )
V_122 -> V_310 |= F_93 ( V_378 ) ;
V_122 -> V_376 = V_330 -> V_376 ;
for ( V_9 = 0 ; V_9 < F_8 ( V_122 -> V_82 ) ; V_9 ++ ) {
V_122 -> V_82 [ V_9 ] =
V_330 -> V_379 [ V_9 ] ;
V_122 -> V_380 [ V_9 ] =
- F_220 ( & V_4 -> V_81 . V_82 [ V_9 ] ) ;
}
}
if ( ! ( V_122 -> V_310 & F_93 ( V_381 ) ) ) {
F_221 ( V_4 , & V_4 -> V_317 . V_306 ,
& V_122 -> V_382 ) ;
V_122 -> V_310 |= F_93 ( V_381 ) ;
}
if ( ! ( V_122 -> V_310 & F_93 ( V_383 ) ) ) {
if ( F_211 ( V_4 , & V_122 -> V_384 ) == 0 )
V_122 -> V_310 |= F_93 ( V_383 ) ;
}
V_122 -> V_310 |= F_93 ( V_385 ) ;
for ( V_9 = 0 ; V_9 < V_37 + 1 ; V_9 ++ ) {
struct V_308 * V_309 = & V_122 -> V_386 [ V_9 ] ;
F_213 ( V_4 , V_309 , V_9 ) ;
}
if ( F_5 ( & V_13 -> V_20 ) ) {
#ifdef F_32
V_122 -> V_310 |= F_93 ( V_387 ) |
F_93 ( V_388 ) |
F_93 ( V_389 ) |
F_93 ( V_390 ) |
F_93 ( V_391 ) |
F_93 ( V_392 ) ;
V_122 -> V_393 = V_4 -> V_25 -> V_393 ;
V_122 -> V_394 = V_4 -> V_25 -> V_394 ;
V_122 -> V_395 = V_4 -> V_25 -> V_395 ;
if ( F_4 ( V_4 , V_396 ) ) {
V_122 -> V_310 |= F_93 ( V_397 ) ;
V_122 -> V_398 = V_4 -> V_25 -> V_398 ;
}
V_122 -> V_399 = V_4 -> V_25 -> V_399 ;
V_122 -> V_400 = V_4 -> V_25 -> V_400 ;
V_122 -> V_68 = V_4 -> V_25 -> V_68 ;
#endif
}
V_122 -> V_401 . V_169 = 0 ;
if ( V_13 -> V_20 . V_164 . V_402 )
V_122 -> V_401 . V_169 |= V_403 ;
if ( V_13 -> V_20 . V_164 . V_404 )
V_122 -> V_401 . V_169 |= V_405 ;
if ( V_13 -> V_20 . V_164 . V_406 )
V_122 -> V_401 . V_169 |= V_407 ;
V_122 -> V_401 . V_408 = V_13 -> V_20 . V_164 . V_408 ;
V_122 -> V_401 . V_409 = V_13 -> V_20 . V_164 . V_165 ;
V_122 -> V_410 . V_411 = 0 ;
V_122 -> V_410 . V_412 = F_93 ( V_413 ) |
F_93 ( V_414 ) |
F_93 ( V_415 ) |
F_93 ( V_416 ) |
F_93 ( V_417 ) |
F_93 ( V_418 ) |
F_93 ( V_419 ) ;
if ( F_4 ( V_4 , V_260 ) )
V_122 -> V_410 . V_411 |= F_93 ( V_413 ) ;
if ( F_4 ( V_4 , V_420 ) )
V_122 -> V_410 . V_411 |= F_93 ( V_414 ) ;
if ( V_4 -> V_4 . V_207 )
V_122 -> V_410 . V_411 |= F_93 ( V_415 ) ;
if ( F_4 ( V_4 , V_421 ) )
V_122 -> V_410 . V_411 |= F_93 ( V_416 ) ;
if ( F_4 ( V_4 , V_258 ) )
V_122 -> V_410 . V_411 |= F_93 ( V_417 ) ;
if ( F_4 ( V_4 , V_251 ) )
V_122 -> V_410 . V_411 |= F_93 ( V_418 ) ;
if ( F_4 ( V_4 , V_422 ) )
V_122 -> V_410 . V_411 |= F_93 ( V_419 ) ;
V_329 = F_222 ( V_4 ) ;
if ( V_329 != 0 ) {
V_122 -> V_310 |= F_93 ( V_423 ) ;
V_122 -> V_424 = V_329 ;
}
}
T_8 F_222 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_425 * V_426 = NULL ;
T_8 V_329 = 0 ;
if ( F_4 ( V_4 , V_427 ) )
V_426 = V_2 -> V_45 ;
if ( V_426 && V_426 -> V_83 -> V_428 )
V_329 = V_426 -> V_83 -> V_428 ( V_4 -> V_55 ) ;
else
V_329 = F_223 ( V_2 , V_4 ) ;
return V_329 ;
}
unsigned long F_143 ( struct V_3 * V_4 )
{
struct V_60 * V_275 = F_205 ( V_4 ) ;
if ( F_101 ( V_275 -> V_73 , V_4 -> V_321 . V_429 ) )
return V_275 -> V_73 ;
return V_4 -> V_321 . V_429 ;
}
