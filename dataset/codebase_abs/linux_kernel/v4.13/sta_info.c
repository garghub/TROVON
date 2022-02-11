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
V_4 -> V_109 . V_110 = V_111 ;
V_4 -> V_109 . V_112 = F_64 ( 20 ) ;
V_4 -> V_109 . V_113 = F_64 ( 100 ) ;
V_4 -> V_109 . V_114 = true ;
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
static int F_65 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
if ( F_66 ( ! F_67 ( V_13 ) ) )
return - V_115 ;
if ( F_63 ( F_68 ( V_4 -> V_4 . V_42 , V_13 -> V_20 . V_42 ) ||
F_69 ( V_4 -> V_4 . V_42 ) ) )
return - V_116 ;
F_24 () ;
F_70 ( & V_13 -> V_2 -> V_117 ) ;
if ( F_45 ( & V_13 -> V_2 -> V_34 , V_118 ) &&
F_71 ( & V_13 -> V_2 -> V_34 , V_4 -> V_42 , NULL ) ) {
F_26 () ;
return - V_119 ;
}
F_26 () ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_3 * V_4 )
{
enum V_120 V_121 ;
int V_122 = 0 ;
for ( V_121 = V_123 ; V_121 < V_4 -> V_76 ; V_121 ++ ) {
V_122 = F_73 ( V_2 , V_13 , V_4 , V_121 , V_121 + 1 ) ;
if ( V_122 )
break;
}
if ( ! V_122 ) {
if ( ! V_2 -> V_83 -> V_124 )
V_4 -> V_125 = true ;
return 0 ;
}
if ( V_13 -> V_20 . type == V_126 ) {
F_74 ( V_13 ,
L_3 ,
V_4 -> V_4 . V_42 , V_121 + 1 , V_122 ) ;
V_122 = 0 ;
}
for (; V_121 > V_123 ; V_121 -- )
F_63 ( F_73 ( V_2 , V_13 , V_4 , V_121 , V_121 - 1 ) ) ;
return V_122 ;
}
static int F_75 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_127 * V_128 = NULL ;
int V_122 = 0 ;
F_70 ( & V_2 -> V_117 ) ;
if ( F_27 ( V_13 , V_4 -> V_4 . V_42 ) ) {
V_122 = - V_129 ;
goto V_130;
}
V_128 = F_48 ( sizeof( struct V_127 ) , V_131 ) ;
if ( ! V_128 ) {
V_122 = - V_56 ;
goto V_130;
}
V_2 -> V_132 ++ ;
V_2 -> V_133 ++ ;
F_76 () ;
F_77 ( V_4 , V_134 ) ;
V_122 = F_34 ( V_2 , V_4 ) ;
if ( V_122 )
goto V_135;
F_78 ( & V_4 -> V_136 , & V_2 -> V_137 ) ;
V_122 = F_72 ( V_2 , V_13 , V_4 ) ;
if ( V_122 )
goto V_138;
F_77 ( V_4 , V_139 ) ;
F_6 ( V_4 , V_134 ) ;
F_79 ( V_4 ) ;
F_80 ( V_4 ) ;
V_128 -> V_140 = V_2 -> V_133 ;
F_81 ( V_13 -> V_141 , V_4 -> V_4 . V_42 , V_128 , V_131 ) ;
F_17 ( V_128 ) ;
F_31 ( V_13 , L_4 , V_4 -> V_4 . V_42 ) ;
F_24 () ;
F_82 ( & V_2 -> V_117 ) ;
if ( F_5 ( & V_13 -> V_20 ) )
F_83 ( V_13 ) ;
return 0 ;
V_138:
F_1 ( V_2 , V_4 ) ;
F_84 ( & V_4 -> V_136 ) ;
V_135:
V_2 -> V_132 -- ;
F_85 () ;
F_3 ( V_4 ) ;
V_130:
F_82 ( & V_2 -> V_117 ) ;
F_17 ( V_128 ) ;
F_24 () ;
return V_122 ;
}
int F_86 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_122 ;
F_87 () ;
F_88 ( & V_2 -> V_117 ) ;
V_122 = F_65 ( V_4 ) ;
if ( V_122 ) {
F_82 ( & V_2 -> V_117 ) ;
F_24 () ;
goto V_142;
}
V_122 = F_75 ( V_4 ) ;
if ( V_122 )
goto V_142;
return 0 ;
V_142:
F_20 ( V_2 , V_4 ) ;
return V_122 ;
}
int F_89 ( struct V_3 * V_4 )
{
int V_122 = F_86 ( V_4 ) ;
F_26 () ;
return V_122 ;
}
static inline void F_90 ( T_1 * V_143 , T_4 V_144 )
{
V_143 [ V_144 / 8 ] |= ( 1 << ( V_144 % 8 ) ) ;
}
static inline void F_91 ( T_1 * V_143 , T_4 V_144 )
{
V_143 [ V_144 / 8 ] &= ~ ( 1 << ( V_144 % 8 ) ) ;
}
static inline bool F_92 ( T_1 * V_143 , T_4 V_144 )
{
return V_143 [ V_144 / 8 ] & ( 1 << ( V_144 % 8 ) ) ;
}
static unsigned long F_93 ( int V_8 )
{
switch ( V_8 ) {
case V_145 :
return F_94 ( 6 ) | F_94 ( 7 ) ;
case V_146 :
return F_94 ( 4 ) | F_94 ( 5 ) ;
case V_147 :
return F_94 ( 0 ) | F_94 ( 3 ) ;
case V_148 :
return F_94 ( 1 ) | F_94 ( 2 ) ;
default:
F_63 ( 1 ) ;
return 0 ;
}
}
static void F_95 ( struct V_3 * V_4 , bool V_149 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_15 * V_16 ;
bool V_150 = false ;
T_1 V_151 = V_4 -> V_4 . V_152 ;
int V_8 ;
T_4 V_144 = V_4 -> V_4 . V_153 ;
if ( V_4 -> V_13 -> V_20 . type == V_21 ||
V_4 -> V_13 -> V_20 . type == V_22 ) {
if ( F_96 ( ! V_4 -> V_13 -> V_23 ) )
return;
V_16 = & V_4 -> V_13 -> V_23 -> V_16 ;
#ifdef F_32
} else if ( F_5 ( & V_4 -> V_13 -> V_20 ) ) {
V_16 = & V_4 -> V_13 -> V_24 . V_25 . V_16 ;
#endif
} else {
return;
}
if ( F_45 ( & V_2 -> V_34 , V_154 ) && ! V_2 -> V_83 -> V_155 )
return;
if ( V_4 -> V_50 )
goto V_156;
if ( V_151 == F_94 ( V_31 ) - 1 )
V_151 = 0 ;
if ( V_149 )
V_151 = F_94 ( V_31 ) - 1 ;
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ ) {
unsigned long V_157 ;
if ( V_151 & V_158 [ V_8 ] )
continue;
V_150 |= ! F_97 ( & V_4 -> V_35 [ V_8 ] ) ||
! F_97 ( & V_4 -> V_33 [ V_8 ] ) ;
if ( V_150 )
break;
V_157 = F_93 ( V_8 ) ;
V_150 |=
V_4 -> V_159 & V_157 ;
V_150 |=
V_4 -> V_160 & V_157 ;
}
V_156:
F_10 ( & V_2 -> V_161 ) ;
if ( V_150 == F_92 ( V_16 -> V_143 , V_144 ) )
goto V_162;
if ( V_150 )
F_90 ( V_16 -> V_143 , V_144 ) ;
else
F_91 ( V_16 -> V_143 , V_144 ) ;
if ( V_2 -> V_83 -> V_155 && ! F_63 ( V_4 -> V_50 ) ) {
V_2 -> V_163 = true ;
F_98 ( V_2 , & V_4 -> V_4 , V_150 ) ;
V_2 -> V_163 = false ;
}
V_162:
F_12 ( & V_2 -> V_161 ) ;
}
void F_99 ( struct V_3 * V_4 )
{
F_95 ( V_4 , false ) ;
}
static bool F_100 ( struct V_3 * V_4 , struct V_164 * V_165 )
{
struct V_166 * V_167 ;
int V_168 ;
if ( ! V_165 )
return false ;
V_167 = F_101 ( V_165 ) ;
V_168 = ( V_4 -> V_169 *
V_4 -> V_13 -> V_20 . V_170 . V_171 *
32 / 15625 ) * V_172 ;
if ( V_168 < V_173 )
V_168 = V_173 ;
return F_102 ( V_74 , V_167 -> V_174 . V_74 + V_168 ) ;
}
static bool F_103 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_8 )
{
unsigned long V_175 ;
struct V_164 * V_165 ;
for (; ; ) {
F_104 ( & V_4 -> V_35 [ V_8 ] . V_30 , V_175 ) ;
V_165 = F_105 ( & V_4 -> V_35 [ V_8 ] ) ;
if ( F_100 ( V_4 , V_165 ) )
V_165 = F_106 ( & V_4 -> V_35 [ V_8 ] ) ;
else
V_165 = NULL ;
F_107 ( & V_4 -> V_35 [ V_8 ] . V_30 , V_175 ) ;
if ( ! V_165 )
break;
F_108 ( & V_2 -> V_34 , V_165 ) ;
}
for (; ; ) {
F_104 ( & V_4 -> V_33 [ V_8 ] . V_30 , V_175 ) ;
V_165 = F_105 ( & V_4 -> V_33 [ V_8 ] ) ;
if ( F_100 ( V_4 , V_165 ) )
V_165 = F_106 ( & V_4 -> V_33 [ V_8 ] ) ;
else
V_165 = NULL ;
F_107 ( & V_4 -> V_33 [ V_8 ] . V_30 , V_175 ) ;
if ( ! V_165 )
break;
V_2 -> V_32 -- ;
F_109 ( V_4 -> V_13 , L_5 ,
V_4 -> V_4 . V_42 ) ;
F_108 ( & V_2 -> V_34 , V_165 ) ;
}
F_99 ( V_4 ) ;
return ! ( F_97 ( & V_4 -> V_33 [ V_8 ] ) &&
F_97 ( & V_4 -> V_35 [ V_8 ] ) ) ;
}
static bool F_110 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_176 = false ;
int V_8 ;
if ( ! V_4 -> V_13 -> V_23 &&
! F_5 ( & V_4 -> V_13 -> V_20 ) )
return false ;
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ )
V_176 |=
F_103 ( V_2 , V_4 , V_8 ) ;
return V_176 ;
}
static int T_5 F_111 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
int V_177 ;
F_87 () ;
if ( ! V_4 )
return - V_178 ;
V_2 = V_4 -> V_2 ;
V_13 = V_4 -> V_13 ;
F_70 ( & V_2 -> V_117 ) ;
F_77 ( V_4 , V_134 ) ;
F_112 ( V_4 , V_179 ) ;
F_113 ( V_2 , V_4 ) ;
V_177 = F_1 ( V_2 , V_4 ) ;
if ( F_63 ( V_177 ) )
return V_177 ;
if ( F_4 ( V_4 , V_180 ) ) {
F_114 ( V_2 , V_13 , & V_4 -> V_4 ) ;
F_6 ( V_4 , V_180 ) ;
}
F_84 ( & V_4 -> V_136 ) ;
V_4 -> V_181 = true ;
F_115 ( V_2 , V_4 -> V_13 , V_4 ) ;
if ( V_13 -> V_20 . type == V_22 &&
F_116 ( V_13 -> V_24 . V_182 . V_4 ) == V_4 )
F_117 ( V_13 -> V_24 . V_182 . V_4 , NULL ) ;
return 0 ;
}
static void F_118 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_127 * V_128 ;
int V_177 ;
F_87 () ;
F_70 ( & V_2 -> V_117 ) ;
F_119 ( V_2 , V_4 ) ;
F_95 ( V_4 , true ) ;
V_4 -> V_50 = true ;
V_2 -> V_132 -- ;
V_2 -> V_133 ++ ;
while ( V_4 -> V_76 > V_77 ) {
V_177 = F_120 ( V_4 , V_4 -> V_76 - 1 ) ;
if ( V_177 ) {
F_96 ( 1 ) ;
break;
}
}
if ( V_4 -> V_125 ) {
V_177 = F_73 ( V_2 , V_13 , V_4 , V_77 ,
V_123 ) ;
F_96 ( V_177 != 0 ) ;
}
F_31 ( V_13 , L_6 , V_4 -> V_4 . V_42 ) ;
V_128 = F_48 ( sizeof( * V_128 ) , V_131 ) ;
if ( V_128 )
F_121 ( V_4 , V_128 ) ;
F_122 ( V_13 -> V_141 , V_4 -> V_4 . V_42 , V_128 , V_131 ) ;
F_17 ( V_128 ) ;
F_123 ( V_4 ) ;
F_124 ( V_4 ) ;
F_19 ( V_4 ) ;
}
int T_5 F_125 ( struct V_3 * V_4 )
{
int V_122 = F_111 ( V_4 ) ;
if ( V_122 )
return V_122 ;
F_85 () ;
F_118 ( V_4 ) ;
return 0 ;
}
int F_126 ( struct V_12 * V_13 , const T_1 * V_42 )
{
struct V_3 * V_4 ;
int V_177 ;
F_88 ( & V_13 -> V_2 -> V_117 ) ;
V_4 = F_23 ( V_13 , V_42 ) ;
V_177 = F_125 ( V_4 ) ;
F_82 ( & V_13 -> V_2 -> V_117 ) ;
return V_177 ;
}
int F_127 ( struct V_12 * V_13 ,
const T_1 * V_42 )
{
struct V_3 * V_4 ;
int V_177 ;
F_88 ( & V_13 -> V_2 -> V_117 ) ;
V_4 = F_27 ( V_13 , V_42 ) ;
V_177 = F_125 ( V_4 ) ;
F_82 ( & V_13 -> V_2 -> V_117 ) ;
return V_177 ;
}
static void F_128 ( unsigned long V_183 )
{
struct V_1 * V_2 = (struct V_1 * ) V_183 ;
struct V_3 * V_4 ;
bool V_184 = false ;
F_24 () ;
F_29 (sta, &local->sta_list, list)
if ( F_110 ( V_2 , V_4 ) )
V_184 = true ;
F_26 () ;
if ( V_2 -> V_185 )
return;
if ( ! V_184 )
return;
F_129 ( & V_2 -> V_186 ,
F_130 ( V_74 + V_187 ) ) ;
}
int F_131 ( struct V_1 * V_2 )
{
int V_122 ;
V_122 = F_132 ( & V_2 -> V_5 , & V_7 ) ;
if ( V_122 )
return V_122 ;
F_50 ( & V_2 -> V_161 ) ;
F_52 ( & V_2 -> V_117 ) ;
F_133 ( & V_2 -> V_137 ) ;
F_134 ( & V_2 -> V_186 , F_128 ,
( unsigned long ) V_2 ) ;
return 0 ;
}
void F_135 ( struct V_1 * V_2 )
{
F_136 ( & V_2 -> V_186 ) ;
F_137 ( & V_2 -> V_5 ) ;
}
int F_138 ( struct V_12 * V_13 , bool V_188 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 , * V_43 ;
F_139 ( V_189 ) ;
int V_177 = 0 ;
F_87 () ;
F_63 ( V_188 && V_13 -> V_20 . type != V_21 ) ;
F_63 ( V_188 && ! V_13 -> V_23 ) ;
F_88 ( & V_2 -> V_117 ) ;
F_140 (sta, tmp, &local->sta_list, list) {
if ( V_13 == V_4 -> V_13 ||
( V_188 && V_13 -> V_23 == V_4 -> V_13 -> V_23 ) ) {
if ( ! F_63 ( F_111 ( V_4 ) ) )
F_141 ( & V_4 -> V_189 , & V_189 ) ;
V_177 ++ ;
}
}
if ( ! F_142 ( & V_189 ) ) {
F_85 () ;
F_140 (sta, tmp, &free_list, free_list)
F_118 ( V_4 ) ;
}
F_82 ( & V_2 -> V_117 ) ;
return V_177 ;
}
void F_143 ( struct V_12 * V_13 ,
unsigned long V_190 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 , * V_43 ;
F_88 ( & V_2 -> V_117 ) ;
F_140 (sta, tmp, &local->sta_list, list) {
unsigned long V_191 = F_144 ( V_4 ) ;
if ( V_13 != V_4 -> V_13 )
continue;
if ( F_145 ( V_191 + V_190 ) ) {
F_31 ( V_4 -> V_13 , L_7 ,
V_4 -> V_4 . V_42 ) ;
if ( F_5 ( & V_13 -> V_20 ) &&
F_4 ( V_4 , V_17 ) )
F_7 ( & V_13 -> V_24 . V_25 . V_16 . V_26 ) ;
F_63 ( F_125 ( V_4 ) ) ;
}
}
F_82 ( & V_2 -> V_117 ) ;
}
struct V_192 * F_71 ( struct V_57 * V_34 ,
const T_1 * V_42 ,
const T_1 * V_193 )
{
struct V_1 * V_2 = F_146 ( V_34 ) ;
struct V_41 * V_43 ;
struct V_3 * V_4 ;
F_25 (local, addr, sta, tmp) {
if ( V_193 &&
! F_68 ( V_4 -> V_13 -> V_20 . V_42 , V_193 ) )
continue;
if ( ! V_4 -> V_125 )
return NULL ;
return & V_4 -> V_4 ;
}
return NULL ;
}
struct V_192 * F_147 ( struct V_194 * V_20 ,
const T_1 * V_42 )
{
struct V_3 * V_4 ;
if ( ! V_20 )
return NULL ;
V_4 = F_27 ( F_148 ( V_20 ) , V_42 ) ;
if ( ! V_4 )
return NULL ;
if ( ! V_4 -> V_125 )
return NULL ;
return & V_4 -> V_4 ;
}
void F_39 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_195 V_40 ;
int V_196 = 0 , V_197 = 0 , V_8 , V_9 ;
unsigned long V_175 ;
struct V_15 * V_16 ;
if ( V_13 -> V_20 . type == V_22 )
V_13 = F_37 ( V_13 -> V_23 , struct V_12 ,
V_24 . V_198 ) ;
if ( V_13 -> V_20 . type == V_21 )
V_16 = & V_13 -> V_23 -> V_16 ;
else if ( F_5 ( & V_13 -> V_20 ) )
V_16 = & V_13 -> V_24 . V_25 . V_16 ;
else
return;
F_6 ( V_4 , V_199 ) ;
F_149 ( F_150 ( V_37 ) > 1 ) ;
V_4 -> V_159 = 0 ;
V_4 -> V_160 = 0 ;
if ( ! F_45 ( & V_2 -> V_34 , V_154 ) )
F_151 ( V_2 , V_13 , V_200 , & V_4 -> V_4 ) ;
if ( V_4 -> V_4 . V_27 [ 0 ] ) {
for ( V_9 = 0 ; V_9 < F_8 ( V_4 -> V_4 . V_27 ) ; V_9 ++ ) {
if ( ! F_152 ( V_4 -> V_4 . V_27 [ V_9 ] ) )
continue;
F_153 ( V_2 , F_9 ( V_4 -> V_4 . V_27 [ V_9 ] ) ) ;
}
}
F_60 ( & V_40 ) ;
F_154 ( & V_4 -> V_61 ) ;
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ ) {
int V_201 = F_13 ( & V_40 ) , V_43 ;
F_104 ( & V_4 -> V_35 [ V_8 ] . V_30 , V_175 ) ;
F_155 ( & V_4 -> V_35 [ V_8 ] , & V_40 ) ;
F_107 ( & V_4 -> V_35 [ V_8 ] . V_30 , V_175 ) ;
V_43 = F_13 ( & V_40 ) ;
V_196 += V_43 - V_201 ;
V_201 = V_43 ;
F_104 ( & V_4 -> V_33 [ V_8 ] . V_30 , V_175 ) ;
F_155 ( & V_4 -> V_33 [ V_8 ] , & V_40 ) ;
F_107 ( & V_4 -> V_33 [ V_8 ] . V_30 , V_175 ) ;
V_43 = F_13 ( & V_40 ) ;
V_197 += V_43 - V_201 ;
}
F_156 ( V_2 , & V_40 ) ;
F_6 ( V_4 , V_19 ) ;
F_6 ( V_4 , V_51 ) ;
F_6 ( V_4 , V_52 ) ;
F_157 ( & V_4 -> V_61 ) ;
F_7 ( & V_16 -> V_26 ) ;
if ( ! F_5 ( & V_13 -> V_20 ) &&
! F_158 ( V_4 -> V_102 ,
V_13 -> V_92 ) &&
V_4 -> V_102 != V_13 -> V_23 -> V_202 &&
F_159 ( V_4 ) != 1 ) {
F_160 ( V_13 ,
L_8 ,
V_4 -> V_4 . V_42 ) ;
F_161 ( V_13 , V_13 -> V_23 -> V_202 ,
V_4 -> V_4 . V_42 ,
V_13 -> V_20 . V_170 . V_203 ) ;
}
V_2 -> V_32 -= V_197 ;
F_99 ( V_4 ) ;
F_109 ( V_13 ,
L_9 ,
V_4 -> V_4 . V_42 , V_4 -> V_4 . V_153 , V_196 , V_197 ) ;
F_162 ( V_4 ) ;
}
static void F_163 ( struct V_3 * V_4 , int V_204 ,
enum V_205 V_206 ,
bool V_207 , bool V_208 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_209 * V_210 ;
struct V_164 * V_165 ;
int V_86 = sizeof( * V_210 ) ;
T_6 V_211 ;
bool V_212 = V_4 -> V_4 . V_213 ;
struct V_166 * V_167 ;
struct V_214 * V_215 ;
if ( V_212 ) {
V_211 = F_61 ( V_216 |
V_217 |
V_218 ) ;
} else {
V_86 -= 2 ;
V_211 = F_61 ( V_216 |
V_219 |
V_218 ) ;
}
V_165 = F_164 ( V_2 -> V_34 . V_220 + V_86 ) ;
if ( ! V_165 )
return;
F_165 ( V_165 , V_2 -> V_34 . V_220 ) ;
V_210 = F_166 ( V_165 , V_86 ) ;
V_210 -> V_221 = V_211 ;
V_210 -> V_222 = 0 ;
memcpy ( V_210 -> V_223 , V_4 -> V_4 . V_42 , V_70 ) ;
memcpy ( V_210 -> V_224 , V_13 -> V_20 . V_42 , V_70 ) ;
memcpy ( V_210 -> V_225 , V_13 -> V_20 . V_42 , V_70 ) ;
V_210 -> V_226 = 0 ;
V_165 -> V_227 = V_204 ;
F_167 ( V_165 , V_228 [ V_204 ] ) ;
if ( V_212 ) {
V_210 -> V_229 = F_61 ( V_204 ) ;
if ( V_206 == V_230 ) {
V_210 -> V_229 |=
F_61 ( V_231 ) ;
if ( V_208 )
V_210 -> V_221 |=
F_61 ( V_232 ) ;
}
}
V_167 = F_101 ( V_165 ) ;
V_167 -> V_175 |= V_233 |
V_234 |
V_235 ;
V_167 -> V_174 . V_175 |= V_236 ;
if ( V_207 )
F_168 ( V_2 , V_4 , F_94 ( V_204 ) , 1 ,
V_206 , false ) ;
V_165 -> V_141 = V_13 -> V_141 ;
F_24 () ;
V_215 = F_169 ( V_13 -> V_20 . V_215 ) ;
if ( F_63 ( ! V_215 ) ) {
F_26 () ;
F_170 ( V_165 ) ;
return;
}
V_167 -> V_237 = V_215 -> V_238 . V_239 -> V_237 ;
F_171 ( V_13 , V_4 , V_165 ) ;
F_26 () ;
}
static int F_172 ( unsigned long V_157 )
{
if ( V_157 & 0xF8 )
return F_173 ( V_157 ) - 1 ;
if ( V_157 & F_94 ( 0 ) )
return 0 ;
return F_173 ( V_157 ) - 1 ;
}
static bool
F_174 ( struct V_3 * V_4 , T_1 V_240 ,
enum V_205 V_206 ,
unsigned long V_241 )
{
int V_8 ;
if ( V_206 == V_242 &&
F_175 ( V_241 ) > 1 )
return true ;
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ ) {
if ( V_240 & V_158 [ V_8 ] )
continue;
if ( ! F_97 ( & V_4 -> V_35 [ V_8 ] ) ||
! F_97 ( & V_4 -> V_33 [ V_8 ] ) )
return true ;
}
return false ;
}
static void
F_176 ( struct V_3 * V_4 , int V_243 , T_1 V_240 ,
enum V_205 V_206 ,
struct V_195 * V_244 ,
unsigned long * V_241 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ ) {
unsigned long V_157 ;
if ( V_240 & V_158 [ V_8 ] )
continue;
V_157 = F_93 ( V_8 ) ;
if ( F_97 ( V_244 ) ) {
* V_241 |=
V_4 -> V_159 & V_157 ;
* V_241 |= V_4 -> V_160 & V_157 ;
}
if ( ! * V_241 ) {
struct V_164 * V_165 ;
while ( V_243 > 0 ) {
V_165 = F_177 ( & V_4 -> V_35 [ V_8 ] ) ;
if ( ! V_165 ) {
V_165 = F_177 (
& V_4 -> V_33 [ V_8 ] ) ;
if ( V_165 )
V_2 -> V_32 -- ;
}
if ( ! V_165 )
break;
V_243 -- ;
F_178 ( V_244 , V_165 ) ;
}
}
if ( ! F_97 ( & V_4 -> V_35 [ V_8 ] ) ||
! F_97 ( & V_4 -> V_33 [ V_8 ] ) )
break;
}
}
static void
F_179 ( struct V_3 * V_4 ,
int V_243 , T_1 V_240 ,
enum V_205 V_206 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
unsigned long V_241 = 0 ;
struct V_195 V_244 ;
bool V_208 ;
F_77 ( V_4 , V_199 ) ;
F_180 ( & V_244 ) ;
F_176 ( V_4 , V_243 , V_240 , V_206 ,
& V_244 , & V_241 ) ;
V_208 = F_174 ( V_4 , V_240 , V_206 , V_241 ) ;
if ( V_241 && V_206 == V_242 )
V_241 =
F_94 ( F_172 ( V_241 ) ) ;
if ( F_97 ( & V_244 ) && ! V_241 ) {
int V_204 , V_8 ;
for ( V_8 = V_145 ; V_8 < V_31 ; V_8 ++ )
if ( ! ( V_240 & V_158 [ V_8 ] ) )
break;
V_204 = 7 - 2 * V_8 ;
F_163 ( V_4 , V_204 , V_206 , true , false ) ;
} else if ( ! V_241 ) {
struct V_195 V_40 ;
struct V_164 * V_165 ;
int V_245 = 0 ;
T_4 V_157 = 0 ;
bool V_246 = false ;
F_60 ( & V_40 ) ;
while ( ( V_165 = F_106 ( & V_244 ) ) ) {
struct V_166 * V_167 = F_101 ( V_165 ) ;
struct V_247 * V_248 = ( void * ) V_165 -> V_183 ;
T_1 * V_249 = NULL ;
V_245 ++ ;
V_167 -> V_175 |= V_233 ;
V_167 -> V_174 . V_175 |= V_236 ;
if ( V_208 || ! F_97 ( & V_244 ) )
V_248 -> V_221 |=
F_61 ( V_232 ) ;
else
V_248 -> V_221 &=
F_61 ( ~ V_232 ) ;
if ( F_181 ( V_248 -> V_221 ) ||
F_182 ( V_248 -> V_221 ) )
V_249 = F_183 ( V_248 ) ;
V_157 |= F_94 ( V_165 -> V_227 ) ;
F_178 ( & V_40 , V_165 ) ;
if ( ! F_97 ( & V_244 ) )
continue;
if ( V_206 != V_230 ) {
V_167 -> V_175 |= V_234 |
V_235 ;
break;
}
if ( V_249 ) {
* V_249 |= V_231 ;
V_167 -> V_175 |= V_234 |
V_235 ;
} else {
V_248 -> V_221 |=
F_61 ( V_232 ) ;
V_246 = true ;
V_245 ++ ;
}
break;
}
F_168 ( V_2 , V_4 , V_157 , V_245 ,
V_206 , V_208 ) ;
F_156 ( V_2 , & V_40 ) ;
if ( V_246 )
F_163 (
V_4 , F_172 ( V_157 ) ,
V_206 , false , false ) ;
F_99 ( V_4 ) ;
} else {
int V_204 ;
F_184 ( V_2 , V_4 , V_241 ,
V_243 , V_206 , V_208 ) ;
if ( ! V_4 -> V_4 . V_27 [ 0 ] )
return;
for ( V_204 = 0 ; V_204 < F_8 ( V_4 -> V_4 . V_27 ) ; V_204 ++ ) {
if ( ! ( V_241 & F_94 ( V_204 ) ) ||
F_152 ( V_4 -> V_4 . V_27 [ V_204 ] ) )
continue;
F_99 ( V_4 ) ;
break;
}
}
}
void F_41 ( struct V_3 * V_4 )
{
T_1 V_250 = V_4 -> V_4 . V_152 ;
if ( V_250 == F_94 ( V_31 ) - 1 )
V_250 = 0 ;
F_179 ( V_4 , 1 , V_250 ,
V_242 ) ;
}
void F_42 ( struct V_3 * V_4 )
{
int V_243 = V_4 -> V_4 . V_251 ;
T_1 V_252 = V_4 -> V_4 . V_152 ;
if ( ! V_252 )
return;
switch ( V_4 -> V_4 . V_251 ) {
case 1 :
V_243 = 2 ;
break;
case 2 :
V_243 = 4 ;
break;
case 3 :
V_243 = 6 ;
break;
case 0 :
V_243 = 128 ;
break;
}
F_179 ( V_4 , V_243 , ~ V_252 ,
V_230 ) ;
}
void F_185 ( struct V_57 * V_34 ,
struct V_192 * V_253 , bool V_254 )
{
struct V_3 * V_4 = F_37 ( V_253 , struct V_3 , V_4 ) ;
F_186 ( V_4 -> V_2 , V_253 , V_254 ) ;
if ( V_254 ) {
F_77 ( V_4 , V_18 ) ;
F_187 ( V_4 ) ;
return;
}
if ( ! F_4 ( V_4 , V_18 ) )
return;
if ( ! F_4 ( V_4 , V_17 ) ) {
F_77 ( V_4 , V_19 ) ;
F_6 ( V_4 , V_18 ) ;
F_188 ( V_34 , & V_4 -> V_36 ) ;
} else if ( F_4 ( V_4 , V_51 ) ||
F_4 ( V_4 , V_52 ) ) {
F_6 ( V_4 , V_18 ) ;
F_188 ( V_34 , & V_4 -> V_36 ) ;
} else {
F_6 ( V_4 , V_18 ) ;
F_162 ( V_4 ) ;
}
}
void F_189 ( struct V_192 * V_253 )
{
struct V_3 * V_4 = F_37 ( V_253 , struct V_3 , V_4 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_190 ( V_2 , V_253 ) ;
F_6 ( V_4 , V_199 ) ;
}
void F_191 ( struct V_192 * V_253 , int V_204 )
{
struct V_3 * V_4 = F_37 ( V_253 , struct V_3 , V_4 ) ;
enum V_205 V_206 ;
bool V_208 ;
F_192 ( V_4 -> V_2 , V_253 , V_204 ) ;
V_206 = V_230 ;
V_208 = F_174 ( V_4 , ~ V_4 -> V_4 . V_152 ,
V_206 , 0 ) ;
F_163 ( V_4 , V_204 , V_206 , false , V_208 ) ;
}
void F_193 ( struct V_192 * V_253 ,
T_1 V_204 , bool V_197 )
{
struct V_3 * V_4 = F_37 ( V_253 , struct V_3 , V_4 ) ;
if ( F_63 ( V_204 >= V_37 ) )
return;
F_194 ( V_4 -> V_2 , V_253 , V_204 , V_197 ) ;
if ( V_197 )
F_195 ( V_204 , & V_4 -> V_159 ) ;
else
F_196 ( V_204 , & V_4 -> V_159 ) ;
F_99 ( V_4 ) ;
}
static void
F_197 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
bool V_255 = V_13 -> V_20 . V_256 ;
struct V_3 * V_4 ;
F_24 () ;
F_29 (sta, &local->sta_list, list) {
if ( V_13 != V_4 -> V_13 ||
! F_4 ( V_4 , V_257 ) )
continue;
if ( ! V_4 -> V_4 . V_258 ) {
V_255 = false ;
break;
}
}
F_26 () ;
if ( V_255 != V_13 -> V_20 . V_170 . V_255 ) {
V_13 -> V_20 . V_170 . V_255 = V_255 ;
F_198 ( V_13 , V_259 ) ;
}
}
int F_120 ( struct V_3 * V_4 ,
enum V_120 V_260 )
{
F_87 () ;
if ( V_4 -> V_76 == V_260 )
return 0 ;
switch ( V_260 ) {
case V_77 :
if ( V_4 -> V_76 != V_261 )
return - V_116 ;
break;
case V_261 :
if ( V_4 -> V_76 != V_77 &&
V_4 -> V_76 != V_262 )
return - V_116 ;
break;
case V_262 :
if ( V_4 -> V_76 != V_261 &&
V_4 -> V_76 != V_263 )
return - V_116 ;
break;
case V_263 :
if ( V_4 -> V_76 != V_262 )
return - V_116 ;
break;
default:
F_199 ( 1 , L_10 , V_260 ) ;
return - V_116 ;
}
F_31 ( V_4 -> V_13 , L_11 ,
V_4 -> V_4 . V_42 , V_260 ) ;
if ( F_4 ( V_4 , V_139 ) ) {
int V_122 = F_73 ( V_4 -> V_2 , V_4 -> V_13 , V_4 ,
V_4 -> V_76 , V_260 ) ;
if ( V_122 )
return V_122 ;
}
switch ( V_260 ) {
case V_77 :
if ( V_4 -> V_76 == V_261 )
F_196 ( V_264 , & V_4 -> V_265 ) ;
break;
case V_261 :
if ( V_4 -> V_76 == V_77 ) {
F_195 ( V_264 , & V_4 -> V_265 ) ;
} else if ( V_4 -> V_76 == V_262 ) {
F_196 ( V_257 , & V_4 -> V_265 ) ;
F_200 ( V_4 -> V_13 ) ;
if ( ! V_4 -> V_4 . V_258 )
F_197 ( V_4 -> V_13 ) ;
}
break;
case V_262 :
if ( V_4 -> V_76 == V_261 ) {
F_195 ( V_257 , & V_4 -> V_265 ) ;
F_200 ( V_4 -> V_13 ) ;
if ( ! V_4 -> V_4 . V_258 )
F_197 ( V_4 -> V_13 ) ;
} else if ( V_4 -> V_76 == V_263 ) {
F_201 ( V_4 -> V_13 ) ;
F_196 ( V_266 , & V_4 -> V_265 ) ;
F_187 ( V_4 ) ;
F_202 ( V_4 ) ;
}
break;
case V_263 :
if ( V_4 -> V_76 == V_262 ) {
F_203 ( V_4 -> V_13 ) ;
F_195 ( V_266 , & V_4 -> V_265 ) ;
F_162 ( V_4 ) ;
F_204 ( V_4 ) ;
}
break;
default:
break;
}
V_4 -> V_76 = V_260 ;
return 0 ;
}
T_1 F_159 ( struct V_3 * V_4 )
{
struct V_267 * V_97 = & V_4 -> V_4 . V_97 ;
T_1 V_268 ;
if ( ! V_4 -> V_4 . V_97 . V_269 )
return 1 ;
if ( V_4 -> V_4 . V_270 . V_271 ) {
int V_9 ;
T_4 V_272 =
F_205 ( V_4 -> V_4 . V_270 . V_273 . V_272 ) ;
for ( V_9 = 7 ; V_9 >= 0 ; V_9 -- )
if ( ( V_272 & ( 0x3 << ( V_9 * 2 ) ) ) !=
V_274 )
return V_9 + 1 ;
}
if ( V_97 -> V_275 . V_276 [ 3 ] )
V_268 = 4 ;
else if ( V_97 -> V_275 . V_276 [ 2 ] )
V_268 = 3 ;
else if ( V_97 -> V_275 . V_276 [ 1 ] )
V_268 = 2 ;
else
V_268 = 1 ;
if ( ! ( V_97 -> V_275 . V_277 & V_278 ) )
return V_268 ;
return ( ( V_97 -> V_275 . V_277 & V_279 )
>> V_280 ) + 1 ;
}
static struct V_60 *
F_206 ( struct V_3 * V_4 )
{
struct V_60 * V_281 = & V_4 -> V_72 ;
struct V_1 * V_2 = V_4 -> V_2 ;
int V_282 ;
if ( ! F_45 ( & V_2 -> V_34 , V_59 ) )
return V_281 ;
F_207 (cpu) {
struct V_60 * V_283 ;
V_283 = F_208 ( V_4 -> V_47 , V_282 ) ;
if ( F_102 ( V_283 -> V_73 , V_281 -> V_73 ) )
V_281 = V_283 ;
}
return V_281 ;
}
static void F_209 ( struct V_1 * V_2 , T_4 V_284 ,
struct V_285 * V_286 )
{
V_286 -> V_287 = F_210 ( V_288 , V_284 ) ;
switch ( F_210 ( TYPE , V_284 ) ) {
case V_289 :
V_286 -> V_175 = V_290 ;
V_286 -> V_275 = F_210 ( V_291 , V_284 ) ;
V_286 -> V_292 = F_210 ( V_293 , V_284 ) ;
if ( F_210 ( V_294 , V_284 ) )
V_286 -> V_175 |= V_295 ;
break;
case V_296 :
V_286 -> V_175 = V_297 ;
V_286 -> V_275 = F_210 ( V_298 , V_284 ) ;
if ( F_210 ( V_294 , V_284 ) )
V_286 -> V_175 |= V_295 ;
break;
case V_299 : {
struct V_94 * V_95 ;
T_4 V_300 ;
unsigned int V_301 ;
int V_237 = F_210 ( V_302 , V_284 ) ;
int V_303 = F_210 ( V_304 , V_284 ) ;
V_286 -> V_175 = 0 ;
V_95 = V_2 -> V_34 . V_305 -> V_306 [ V_237 ] ;
V_300 = V_95 -> V_307 [ V_303 ] . V_308 ;
if ( V_286 -> V_287 == V_309 )
V_301 = 2 ;
else if ( V_286 -> V_287 == V_310 )
V_301 = 1 ;
else
V_301 = 0 ;
V_286 -> V_311 = F_211 ( V_300 , 1 << V_301 ) ;
break;
}
}
}
static int F_212 ( struct V_3 * V_4 , struct V_285 * V_286 )
{
T_4 V_284 = F_213 ( F_206 ( V_4 ) -> V_312 ) ;
if ( V_284 == V_313 )
return - V_116 ;
F_209 ( V_4 -> V_2 , V_284 , V_286 ) ;
return 0 ;
}
static void F_214 ( struct V_3 * V_4 ,
struct V_314 * V_315 ,
int V_204 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( ! ( V_315 -> V_316 & F_94 ( V_317 ) ) ) {
unsigned int V_318 ;
do {
V_318 = F_215 ( & V_4 -> V_72 . V_75 ) ;
V_315 -> V_319 = V_4 -> V_72 . V_320 [ V_204 ] ;
} while ( F_216 ( & V_4 -> V_72 . V_75 , V_318 ) );
V_315 -> V_316 |= F_94 ( V_317 ) ;
}
if ( ! ( V_315 -> V_316 & F_94 ( V_321 ) ) ) {
V_315 -> V_316 |= F_94 ( V_321 ) ;
V_315 -> V_322 = V_4 -> V_323 . V_320 [ V_204 ] ;
}
if ( ! ( V_315 -> V_316 & F_94 ( V_324 ) ) &&
F_45 ( & V_2 -> V_34 , V_325 ) ) {
V_315 -> V_316 |= F_94 ( V_324 ) ;
V_315 -> V_326 = V_4 -> V_327 . V_328 [ V_204 ] ;
}
if ( ! ( V_315 -> V_316 & F_94 ( V_329 ) ) &&
F_45 ( & V_2 -> V_34 , V_325 ) ) {
V_315 -> V_316 |= F_94 ( V_329 ) ;
V_315 -> V_330 = V_4 -> V_327 . V_331 [ V_204 ] ;
}
}
static inline T_7 F_217 ( struct V_60 * V_332 )
{
unsigned int V_318 ;
T_7 V_333 ;
do {
V_318 = F_215 ( & V_332 -> V_75 ) ;
V_333 = V_332 -> V_334 ;
} while ( F_216 ( & V_332 -> V_75 , V_318 ) );
return V_333 ;
}
void F_121 ( struct V_3 * V_4 , struct V_127 * V_128 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
T_8 V_335 = 0 ;
int V_9 , V_8 , V_282 ;
struct V_60 * V_336 ;
V_336 = F_206 ( V_4 ) ;
V_128 -> V_140 = V_13 -> V_2 -> V_133 ;
if ( V_13 -> V_20 . type == V_337 )
V_128 -> V_338 = V_13 -> V_24 . V_339 . V_340 ;
F_218 ( V_2 , V_13 , & V_4 -> V_4 , V_128 ) ;
V_128 -> V_316 |= F_94 ( V_341 ) |
F_94 ( V_342 ) |
F_94 ( V_343 ) |
F_94 ( V_344 ) |
F_94 ( V_345 ) ;
if ( V_13 -> V_20 . type == V_337 ) {
V_128 -> V_346 = V_13 -> V_24 . V_339 . V_346 ;
V_128 -> V_316 |= F_94 ( V_347 ) ;
}
V_128 -> V_348 = F_55 () - V_4 -> V_80 ;
V_128 -> V_349 =
F_219 ( V_74 - F_144 ( V_4 ) ) ;
if ( ! ( V_128 -> V_316 & ( F_94 ( V_350 ) |
F_94 ( V_351 ) ) ) ) {
V_128 -> V_352 = 0 ;
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ )
V_128 -> V_352 += V_4 -> V_323 . V_334 [ V_8 ] ;
V_128 -> V_316 |= F_94 ( V_350 ) ;
}
if ( ! ( V_128 -> V_316 & F_94 ( V_353 ) ) ) {
V_128 -> V_354 = 0 ;
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ )
V_128 -> V_354 += V_4 -> V_323 . V_355 [ V_8 ] ;
V_128 -> V_316 |= F_94 ( V_353 ) ;
}
if ( ! ( V_128 -> V_316 & ( F_94 ( V_356 ) |
F_94 ( V_357 ) ) ) ) {
V_128 -> V_358 += F_217 ( & V_4 -> V_72 ) ;
if ( V_4 -> V_47 ) {
F_207 (cpu) {
struct V_60 * V_359 ;
V_359 = F_208 ( V_4 -> V_47 , V_282 ) ;
V_128 -> V_358 += F_217 ( V_359 ) ;
}
}
V_128 -> V_316 |= F_94 ( V_356 ) ;
}
if ( ! ( V_128 -> V_316 & F_94 ( V_360 ) ) ) {
V_128 -> V_361 = V_4 -> V_72 . V_355 ;
if ( V_4 -> V_47 ) {
F_207 (cpu) {
struct V_60 * V_359 ;
V_359 = F_208 ( V_4 -> V_47 , V_282 ) ;
V_128 -> V_361 += V_359 -> V_355 ;
}
}
V_128 -> V_316 |= F_94 ( V_360 ) ;
}
if ( ! ( V_128 -> V_316 & F_94 ( V_362 ) ) ) {
V_128 -> V_363 = V_4 -> V_327 . V_364 ;
V_128 -> V_316 |= F_94 ( V_362 ) ;
}
if ( ! ( V_128 -> V_316 & F_94 ( V_365 ) ) ) {
V_128 -> V_366 = V_4 -> V_327 . V_367 ;
V_128 -> V_316 |= F_94 ( V_365 ) ;
}
V_128 -> V_368 = V_4 -> V_72 . V_369 ;
if ( V_4 -> V_47 ) {
F_207 (cpu) {
struct V_60 * V_359 ;
V_359 = F_208 ( V_4 -> V_47 , V_282 ) ;
V_128 -> V_368 += V_359 -> V_369 ;
}
}
if ( V_13 -> V_20 . type == V_337 &&
! ( V_13 -> V_20 . V_370 & V_371 ) ) {
V_128 -> V_316 |= F_94 ( V_372 ) |
F_94 ( V_373 ) ;
V_128 -> V_374 = F_220 ( & V_13 -> V_20 ) ;
}
if ( F_45 ( & V_4 -> V_2 -> V_34 , V_375 ) ||
F_45 ( & V_4 -> V_2 -> V_34 , V_376 ) ) {
if ( ! ( V_128 -> V_316 & F_94 ( V_377 ) ) ) {
V_128 -> signal = ( V_378 ) V_336 -> V_379 ;
V_128 -> V_316 |= F_94 ( V_377 ) ;
}
if ( ! V_4 -> V_47 &&
! ( V_128 -> V_316 & F_94 ( V_380 ) ) ) {
V_128 -> V_381 =
- F_221 ( & V_4 -> V_81 . signal ) ;
V_128 -> V_316 |= F_94 ( V_380 ) ;
}
}
if ( V_336 -> V_382 &&
! ( V_128 -> V_316 & ( F_94 ( V_383 ) |
F_94 ( V_384 ) ) ) ) {
V_128 -> V_316 |= F_94 ( V_383 ) ;
if ( ! V_4 -> V_47 )
V_128 -> V_316 |= F_94 ( V_384 ) ;
V_128 -> V_382 = V_336 -> V_382 ;
for ( V_9 = 0 ; V_9 < F_8 ( V_128 -> V_82 ) ; V_9 ++ ) {
V_128 -> V_82 [ V_9 ] =
V_336 -> V_385 [ V_9 ] ;
V_128 -> V_386 [ V_9 ] =
- F_221 ( & V_4 -> V_81 . V_82 [ V_9 ] ) ;
}
}
if ( ! ( V_128 -> V_316 & F_94 ( V_387 ) ) ) {
F_222 ( V_4 , & V_4 -> V_323 . V_312 ,
& V_128 -> V_388 ) ;
V_128 -> V_316 |= F_94 ( V_387 ) ;
}
if ( ! ( V_128 -> V_316 & F_94 ( V_389 ) ) ) {
if ( F_212 ( V_4 , & V_128 -> V_390 ) == 0 )
V_128 -> V_316 |= F_94 ( V_389 ) ;
}
V_128 -> V_316 |= F_94 ( V_391 ) ;
for ( V_9 = 0 ; V_9 < V_37 + 1 ; V_9 ++ ) {
struct V_314 * V_315 = & V_128 -> V_392 [ V_9 ] ;
F_214 ( V_4 , V_315 , V_9 ) ;
}
if ( F_5 ( & V_13 -> V_20 ) ) {
#ifdef F_32
V_128 -> V_316 |= F_94 ( V_393 ) |
F_94 ( V_394 ) |
F_94 ( V_395 ) |
F_94 ( V_396 ) |
F_94 ( V_397 ) |
F_94 ( V_398 ) ;
V_128 -> V_399 = V_4 -> V_25 -> V_399 ;
V_128 -> V_400 = V_4 -> V_25 -> V_400 ;
V_128 -> V_401 = V_4 -> V_25 -> V_401 ;
if ( F_4 ( V_4 , V_402 ) ) {
V_128 -> V_316 |= F_94 ( V_403 ) ;
V_128 -> V_404 = V_4 -> V_25 -> V_404 ;
}
V_128 -> V_405 = V_4 -> V_25 -> V_405 ;
V_128 -> V_406 = V_4 -> V_25 -> V_406 ;
V_128 -> V_68 = V_4 -> V_25 -> V_68 ;
#endif
}
V_128 -> V_407 . V_175 = 0 ;
if ( V_13 -> V_20 . V_170 . V_408 )
V_128 -> V_407 . V_175 |= V_409 ;
if ( V_13 -> V_20 . V_170 . V_410 )
V_128 -> V_407 . V_175 |= V_411 ;
if ( V_13 -> V_20 . V_170 . V_412 )
V_128 -> V_407 . V_175 |= V_413 ;
V_128 -> V_407 . V_414 = V_13 -> V_20 . V_170 . V_414 ;
V_128 -> V_407 . V_415 = V_13 -> V_20 . V_170 . V_171 ;
V_128 -> V_416 . V_417 = 0 ;
V_128 -> V_416 . V_418 = F_94 ( V_419 ) |
F_94 ( V_420 ) |
F_94 ( V_421 ) |
F_94 ( V_422 ) |
F_94 ( V_423 ) |
F_94 ( V_424 ) |
F_94 ( V_425 ) ;
if ( F_4 ( V_4 , V_266 ) )
V_128 -> V_416 . V_417 |= F_94 ( V_419 ) ;
if ( F_4 ( V_4 , V_426 ) )
V_128 -> V_416 . V_417 |= F_94 ( V_420 ) ;
if ( V_4 -> V_4 . V_213 )
V_128 -> V_416 . V_417 |= F_94 ( V_421 ) ;
if ( F_4 ( V_4 , V_427 ) )
V_128 -> V_416 . V_417 |= F_94 ( V_422 ) ;
if ( F_4 ( V_4 , V_264 ) )
V_128 -> V_416 . V_417 |= F_94 ( V_423 ) ;
if ( F_4 ( V_4 , V_257 ) )
V_128 -> V_416 . V_417 |= F_94 ( V_424 ) ;
if ( F_4 ( V_4 , V_428 ) )
V_128 -> V_416 . V_417 |= F_94 ( V_425 ) ;
V_335 = F_223 ( V_4 ) ;
if ( V_335 != 0 ) {
V_128 -> V_316 |= F_94 ( V_429 ) ;
V_128 -> V_430 = V_335 ;
}
}
T_8 F_223 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_431 * V_432 = NULL ;
T_8 V_335 = 0 ;
if ( F_4 ( V_4 , V_433 ) )
V_432 = V_2 -> V_45 ;
if ( V_432 && V_432 -> V_83 -> V_434 )
V_335 = V_432 -> V_83 -> V_434 ( V_4 -> V_55 ) ;
else
V_335 = F_224 ( V_2 , V_4 ) ;
return V_335 ;
}
unsigned long F_144 ( struct V_3 * V_4 )
{
struct V_60 * V_281 = F_206 ( V_4 ) ;
if ( F_102 ( V_281 -> V_73 , V_4 -> V_327 . V_435 ) )
return V_281 -> V_73 ;
return V_4 -> V_327 . V_435 ;
}
static void F_225 ( struct V_3 * V_4 , T_8 V_335 )
{
if ( ! V_4 -> V_13 -> V_2 -> V_83 -> V_84 )
return;
if ( V_335 && V_335 < V_436 * V_4 -> V_2 -> V_132 ) {
V_4 -> V_109 . V_112 = F_64 ( 50 ) ;
V_4 -> V_109 . V_113 = F_64 ( 300 ) ;
V_4 -> V_109 . V_114 = false ;
} else {
V_4 -> V_109 . V_112 = F_64 ( 20 ) ;
V_4 -> V_109 . V_113 = F_64 ( 100 ) ;
V_4 -> V_109 . V_114 = true ;
}
}
void F_226 ( struct V_192 * V_253 ,
T_8 V_335 )
{
struct V_3 * V_4 = F_37 ( V_253 , struct V_3 , V_4 ) ;
F_225 ( V_4 , V_335 ) ;
}
