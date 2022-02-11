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
F_20 () ;
F_63 ( & V_13 -> V_2 -> V_110 ) ;
if ( F_41 ( & V_13 -> V_2 -> V_31 , V_111 ) &&
F_64 ( & V_13 -> V_2 -> V_31 , V_4 -> V_42 , NULL ) ) {
F_23 () ;
return - V_112 ;
}
F_23 () ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_3 * V_4 )
{
enum V_113 V_114 ;
int V_115 = 0 ;
for ( V_114 = V_116 ; V_114 < V_4 -> V_75 ; V_114 ++ ) {
V_115 = F_66 ( V_2 , V_13 , V_4 , V_114 , V_114 + 1 ) ;
if ( V_115 )
break;
}
if ( ! V_115 ) {
if ( ! V_2 -> V_82 -> V_117 )
V_4 -> V_118 = true ;
return 0 ;
}
if ( V_13 -> V_19 . type == V_119 ) {
F_67 ( V_13 ,
L_3 ,
V_4 -> V_4 . V_42 , V_114 + 1 , V_115 ) ;
V_115 = 0 ;
}
for (; V_114 > V_116 ; V_114 -- )
F_57 ( F_66 ( V_2 , V_13 , V_4 , V_114 , V_114 - 1 ) ) ;
return V_115 ;
}
static int F_68 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_120 V_121 ;
int V_115 = 0 ;
F_63 ( & V_2 -> V_110 ) ;
if ( F_24 ( V_13 , V_4 -> V_4 . V_42 ) ) {
V_115 = - V_122 ;
goto V_123;
}
V_2 -> V_124 ++ ;
V_2 -> V_125 ++ ;
F_69 () ;
F_70 ( V_4 , V_126 ) ;
F_30 ( V_2 , V_4 ) ;
F_71 ( & V_4 -> V_127 , & V_2 -> V_128 ) ;
V_115 = F_65 ( V_2 , V_13 , V_4 ) ;
if ( V_115 )
goto V_129;
F_70 ( V_4 , V_130 ) ;
F_6 ( V_4 , V_126 ) ;
F_72 ( V_13 ) ;
F_73 ( V_4 ) ;
F_74 ( V_4 ) ;
memset ( & V_121 , 0 , sizeof( V_121 ) ) ;
V_121 . V_131 = 0 ;
V_121 . V_132 = V_2 -> V_125 ;
F_75 ( V_13 -> V_133 , V_4 -> V_4 . V_42 , & V_121 , V_134 ) ;
F_28 ( V_13 , L_4 , V_4 -> V_4 . V_42 ) ;
F_20 () ;
F_76 ( & V_2 -> V_110 ) ;
if ( F_5 ( & V_13 -> V_19 ) )
F_77 ( V_13 ) ;
return 0 ;
V_129:
F_1 ( V_2 , V_4 ) ;
F_78 ( & V_4 -> V_127 ) ;
V_2 -> V_124 -- ;
F_79 () ;
F_3 ( V_4 ) ;
V_123:
F_76 ( & V_2 -> V_110 ) ;
F_20 () ;
return V_115 ;
}
int F_80 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_115 ;
F_81 () ;
F_82 ( & V_2 -> V_110 ) ;
V_115 = F_58 ( V_4 ) ;
if ( V_115 ) {
F_76 ( & V_2 -> V_110 ) ;
F_20 () ;
goto V_135;
}
V_115 = F_68 ( V_4 ) ;
if ( V_115 )
goto V_135;
return 0 ;
V_135:
F_18 ( V_2 , V_4 ) ;
return V_115 ;
}
int F_83 ( struct V_3 * V_4 )
{
int V_115 = F_80 ( V_4 ) ;
F_23 () ;
return V_115 ;
}
static inline void F_84 ( T_1 * V_136 , T_4 V_137 )
{
V_136 [ V_137 / 8 ] |= ( 1 << ( V_137 % 8 ) ) ;
}
static inline void F_85 ( T_1 * V_136 , T_4 V_137 )
{
V_136 [ V_137 / 8 ] &= ~ ( 1 << ( V_137 % 8 ) ) ;
}
static inline bool F_86 ( T_1 * V_136 , T_4 V_137 )
{
return V_136 [ V_137 / 8 ] & ( 1 << ( V_137 % 8 ) ) ;
}
static unsigned long F_87 ( int V_8 )
{
switch ( V_8 ) {
case V_138 :
return F_88 ( 6 ) | F_88 ( 7 ) ;
case V_139 :
return F_88 ( 4 ) | F_88 ( 5 ) ;
case V_140 :
return F_88 ( 0 ) | F_88 ( 3 ) ;
case V_141 :
return F_88 ( 1 ) | F_88 ( 2 ) ;
default:
F_57 ( 1 ) ;
return 0 ;
}
}
static void F_89 ( struct V_3 * V_4 , bool V_142 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_14 * V_15 ;
bool V_143 = false ;
T_1 V_144 = V_4 -> V_4 . V_145 ;
int V_8 ;
T_4 V_137 = V_4 -> V_4 . V_146 ;
if ( V_4 -> V_13 -> V_19 . type == V_20 ||
V_4 -> V_13 -> V_19 . type == V_21 ) {
if ( F_90 ( ! V_4 -> V_13 -> V_22 ) )
return;
V_15 = & V_4 -> V_13 -> V_22 -> V_15 ;
#ifdef F_29
} else if ( F_5 ( & V_4 -> V_13 -> V_19 ) ) {
V_15 = & V_4 -> V_13 -> V_23 . V_24 . V_15 ;
#endif
} else {
return;
}
if ( F_41 ( & V_2 -> V_31 , V_147 ) )
return;
if ( V_4 -> V_52 )
goto V_148;
if ( V_144 == F_88 ( V_33 ) - 1 )
V_144 = 0 ;
if ( V_142 )
V_144 = F_88 ( V_33 ) - 1 ;
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ ) {
unsigned long V_149 ;
if ( V_144 & F_88 ( V_8 ) )
continue;
V_143 |= ! F_91 ( & V_4 -> V_36 [ V_8 ] ) ||
! F_91 ( & V_4 -> V_35 [ V_8 ] ) ;
if ( V_143 )
break;
V_149 = F_87 ( V_8 ) ;
V_143 |=
V_4 -> V_150 & V_149 ;
V_143 |=
V_4 -> V_151 & V_149 ;
}
V_148:
F_92 ( & V_2 -> V_152 ) ;
if ( V_143 == F_86 ( V_15 -> V_136 , V_137 ) )
goto V_153;
if ( V_143 )
F_84 ( V_15 -> V_136 , V_137 ) ;
else
F_85 ( V_15 -> V_136 , V_137 ) ;
if ( V_2 -> V_82 -> V_154 && ! F_57 ( V_4 -> V_52 ) ) {
V_2 -> V_155 = true ;
F_93 ( V_2 , & V_4 -> V_4 , V_143 ) ;
V_2 -> V_155 = false ;
}
V_153:
F_94 ( & V_2 -> V_152 ) ;
}
void F_95 ( struct V_3 * V_4 )
{
F_89 ( V_4 , false ) ;
}
static bool F_96 ( struct V_3 * V_4 , struct V_156 * V_157 )
{
struct V_158 * V_159 ;
int V_160 ;
if ( ! V_157 )
return false ;
V_159 = F_97 ( V_157 ) ;
V_160 = ( V_4 -> V_161 *
V_4 -> V_13 -> V_19 . V_162 . V_163 *
32 / 15625 ) * V_164 ;
if ( V_160 < V_165 )
V_160 = V_165 ;
return F_98 ( V_74 , V_159 -> V_166 . V_74 + V_160 ) ;
}
static bool F_99 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_8 )
{
unsigned long V_167 ;
struct V_156 * V_157 ;
for (; ; ) {
F_100 ( & V_4 -> V_36 [ V_8 ] . V_61 , V_167 ) ;
V_157 = F_101 ( & V_4 -> V_36 [ V_8 ] ) ;
if ( F_96 ( V_4 , V_157 ) )
V_157 = F_102 ( & V_4 -> V_36 [ V_8 ] ) ;
else
V_157 = NULL ;
F_103 ( & V_4 -> V_36 [ V_8 ] . V_61 , V_167 ) ;
if ( ! V_157 )
break;
F_104 ( & V_2 -> V_31 , V_157 ) ;
}
for (; ; ) {
F_100 ( & V_4 -> V_35 [ V_8 ] . V_61 , V_167 ) ;
V_157 = F_101 ( & V_4 -> V_35 [ V_8 ] ) ;
if ( F_96 ( V_4 , V_157 ) )
V_157 = F_102 ( & V_4 -> V_35 [ V_8 ] ) ;
else
V_157 = NULL ;
F_103 ( & V_4 -> V_35 [ V_8 ] . V_61 , V_167 ) ;
if ( ! V_157 )
break;
V_2 -> V_34 -- ;
F_105 ( V_4 -> V_13 , L_5 ,
V_4 -> V_4 . V_42 ) ;
F_104 ( & V_2 -> V_31 , V_157 ) ;
}
F_95 ( V_4 ) ;
return ! ( F_91 ( & V_4 -> V_35 [ V_8 ] ) &&
F_91 ( & V_4 -> V_36 [ V_8 ] ) ) ;
}
static bool F_106 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_168 = false ;
int V_8 ;
if ( ! V_4 -> V_13 -> V_22 &&
! F_5 ( & V_4 -> V_13 -> V_19 ) )
return false ;
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ )
V_168 |=
F_99 ( V_2 , V_4 , V_8 ) ;
return V_168 ;
}
static int T_5 F_107 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
int V_169 ;
F_81 () ;
if ( ! V_4 )
return - V_170 ;
V_2 = V_4 -> V_2 ;
V_13 = V_4 -> V_13 ;
F_63 ( & V_2 -> V_110 ) ;
F_70 ( V_4 , V_126 ) ;
F_108 ( V_4 , V_171 ) ;
V_169 = F_1 ( V_2 , V_4 ) ;
if ( F_57 ( V_169 ) )
return V_169 ;
if ( F_4 ( V_4 , V_172 ) ) {
F_109 ( V_2 , V_13 , & V_4 -> V_4 ) ;
F_6 ( V_4 , V_172 ) ;
}
F_78 ( & V_4 -> V_127 ) ;
V_4 -> V_173 = true ;
F_110 ( V_2 , V_4 -> V_13 , V_4 ) ;
if ( V_13 -> V_19 . type == V_21 &&
F_111 ( V_13 -> V_23 . V_174 . V_4 ) == V_4 )
F_112 ( V_13 -> V_23 . V_174 . V_4 , NULL ) ;
return 0 ;
}
static void F_113 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_120 V_121 = {} ;
int V_169 ;
F_81 () ;
F_63 ( & V_2 -> V_110 ) ;
F_114 ( V_2 , V_4 ) ;
F_89 ( V_4 , true ) ;
V_4 -> V_52 = true ;
V_2 -> V_124 -- ;
V_2 -> V_125 ++ ;
while ( V_4 -> V_75 > V_76 ) {
V_169 = F_115 ( V_4 , V_4 -> V_75 - 1 ) ;
if ( V_169 ) {
F_90 ( 1 ) ;
break;
}
}
if ( V_4 -> V_118 ) {
V_169 = F_66 ( V_2 , V_13 , V_4 , V_76 ,
V_116 ) ;
F_90 ( V_169 != 0 ) ;
}
F_28 ( V_13 , L_6 , V_4 -> V_4 . V_42 ) ;
F_116 ( V_4 , & V_121 ) ;
F_117 ( V_13 -> V_133 , V_4 -> V_4 . V_42 , & V_121 , V_134 ) ;
F_118 ( V_4 ) ;
F_119 ( V_4 ) ;
F_72 ( V_13 ) ;
F_17 ( V_4 ) ;
}
int T_5 F_120 ( struct V_3 * V_4 )
{
int V_115 = F_107 ( V_4 ) ;
if ( V_115 )
return V_115 ;
F_79 () ;
F_113 ( V_4 ) ;
return 0 ;
}
int F_121 ( struct V_12 * V_13 , const T_1 * V_42 )
{
struct V_3 * V_4 ;
int V_169 ;
F_82 ( & V_13 -> V_2 -> V_110 ) ;
V_4 = F_19 ( V_13 , V_42 ) ;
V_169 = F_120 ( V_4 ) ;
F_76 ( & V_13 -> V_2 -> V_110 ) ;
return V_169 ;
}
int F_122 ( struct V_12 * V_13 ,
const T_1 * V_42 )
{
struct V_3 * V_4 ;
int V_169 ;
F_82 ( & V_13 -> V_2 -> V_110 ) ;
V_4 = F_24 ( V_13 , V_42 ) ;
V_169 = F_120 ( V_4 ) ;
F_76 ( & V_13 -> V_2 -> V_110 ) ;
return V_169 ;
}
static void F_123 ( unsigned long V_175 )
{
struct V_1 * V_2 = (struct V_1 * ) V_175 ;
struct V_3 * V_4 ;
bool V_176 = false ;
F_20 () ;
F_26 (sta, &local->sta_list, list)
if ( F_106 ( V_2 , V_4 ) )
V_176 = true ;
F_23 () ;
if ( V_2 -> V_177 )
return;
if ( ! V_176 )
return;
F_124 ( & V_2 -> V_178 ,
F_125 ( V_74 + V_179 ) ) ;
}
T_6 F_126 ( const void * V_180 , T_6 V_181 , T_6 V_182 )
{
return F_127 ( V_180 , V_71 , V_182 ) ;
}
int F_128 ( struct V_1 * V_2 )
{
int V_115 ;
V_115 = F_129 ( & V_2 -> V_5 , & V_7 ) ;
if ( V_115 )
return V_115 ;
F_45 ( & V_2 -> V_152 ) ;
F_47 ( & V_2 -> V_110 ) ;
F_130 ( & V_2 -> V_128 ) ;
F_131 ( & V_2 -> V_178 , F_123 ,
( unsigned long ) V_2 ) ;
return 0 ;
}
void F_132 ( struct V_1 * V_2 )
{
F_133 ( & V_2 -> V_178 ) ;
F_134 ( & V_2 -> V_5 ) ;
}
int F_135 ( struct V_12 * V_13 , bool V_183 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 , * V_44 ;
F_136 ( V_184 ) ;
int V_169 = 0 ;
F_81 () ;
F_57 ( V_183 && V_13 -> V_19 . type != V_20 ) ;
F_57 ( V_183 && ! V_13 -> V_22 ) ;
F_82 ( & V_2 -> V_110 ) ;
F_137 (sta, tmp, &local->sta_list, list) {
if ( V_13 == V_4 -> V_13 ||
( V_183 && V_13 -> V_22 == V_4 -> V_13 -> V_22 ) ) {
if ( ! F_57 ( F_107 ( V_4 ) ) )
F_138 ( & V_4 -> V_184 , & V_184 ) ;
V_169 ++ ;
}
}
if ( ! F_139 ( & V_184 ) ) {
F_79 () ;
F_137 (sta, tmp, &free_list, free_list)
F_113 ( V_4 ) ;
}
F_76 ( & V_2 -> V_110 ) ;
return V_169 ;
}
void F_140 ( struct V_12 * V_13 ,
unsigned long V_185 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 , * V_44 ;
F_82 ( & V_2 -> V_110 ) ;
F_137 (sta, tmp, &local->sta_list, list) {
if ( V_13 != V_4 -> V_13 )
continue;
if ( F_98 ( V_74 , V_4 -> V_72 . V_73 + V_185 ) ) {
F_28 ( V_4 -> V_13 , L_7 ,
V_4 -> V_4 . V_42 ) ;
if ( F_5 ( & V_13 -> V_19 ) &&
F_4 ( V_4 , V_16 ) )
F_7 ( & V_13 -> V_23 . V_24 . V_15 . V_25 ) ;
F_57 ( F_120 ( V_4 ) ) ;
}
}
F_76 ( & V_2 -> V_110 ) ;
}
struct V_186 * F_64 ( struct V_59 * V_31 ,
const T_1 * V_42 ,
const T_1 * V_187 )
{
struct V_1 * V_2 = F_141 ( V_31 ) ;
struct V_3 * V_4 ;
struct V_43 * V_44 ;
const struct V_45 * V_46 ;
V_46 = F_21 ( V_2 -> V_5 . V_46 , & V_2 -> V_5 ) ;
F_22 (local, tbl, addr, sta, tmp) {
if ( V_187 &&
! F_61 ( V_4 -> V_13 -> V_19 . V_42 , V_187 ) )
continue;
if ( ! V_4 -> V_118 )
return NULL ;
return & V_4 -> V_4 ;
}
return NULL ;
}
struct V_186 * F_142 ( struct V_188 * V_19 ,
const T_1 * V_42 )
{
struct V_3 * V_4 ;
if ( ! V_19 )
return NULL ;
V_4 = F_24 ( F_143 ( V_19 ) , V_42 ) ;
if ( ! V_4 )
return NULL ;
if ( ! V_4 -> V_118 )
return NULL ;
return & V_4 -> V_4 ;
}
void F_35 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_189 V_41 ;
int V_190 = 0 , V_191 = 0 , V_8 , V_9 ;
unsigned long V_167 ;
struct V_14 * V_15 ;
if ( V_13 -> V_19 . type == V_21 )
V_13 = F_33 ( V_13 -> V_22 , struct V_12 ,
V_23 . V_192 ) ;
if ( V_13 -> V_19 . type == V_20 )
V_15 = & V_13 -> V_22 -> V_15 ;
else if ( F_5 ( & V_13 -> V_19 ) )
V_15 = & V_13 -> V_23 . V_24 . V_15 ;
else
return;
F_6 ( V_4 , V_193 ) ;
F_144 ( F_145 ( V_38 ) > 1 ) ;
V_4 -> V_150 = 0 ;
V_4 -> V_151 = 0 ;
if ( ! F_41 ( & V_2 -> V_31 , V_147 ) )
F_146 ( V_2 , V_13 , V_194 , & V_4 -> V_4 ) ;
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
int V_195 = F_10 ( & V_41 ) , V_44 ;
F_100 ( & V_4 -> V_36 [ V_8 ] . V_61 , V_167 ) ;
F_149 ( & V_4 -> V_36 [ V_8 ] , & V_41 ) ;
F_103 ( & V_4 -> V_36 [ V_8 ] . V_61 , V_167 ) ;
V_44 = F_10 ( & V_41 ) ;
V_190 += V_44 - V_195 ;
V_195 = V_44 ;
F_100 ( & V_4 -> V_35 [ V_8 ] . V_61 , V_167 ) ;
F_149 ( & V_4 -> V_35 [ V_8 ] , & V_41 ) ;
F_103 ( & V_4 -> V_35 [ V_8 ] . V_61 , V_167 ) ;
V_44 = F_10 ( & V_41 ) ;
V_191 += V_44 - V_195 ;
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
V_4 -> V_103 != V_13 -> V_22 -> V_196 &&
F_153 ( V_4 ) != 1 ) {
F_154 ( V_13 ,
L_8 ,
V_4 -> V_4 . V_42 ) ;
F_155 ( V_13 , V_13 -> V_22 -> V_196 ,
V_4 -> V_4 . V_42 ,
V_13 -> V_19 . V_162 . V_197 ) ;
}
V_2 -> V_34 -= V_191 ;
F_95 ( V_4 ) ;
F_105 ( V_13 ,
L_9 ,
V_4 -> V_4 . V_42 , V_4 -> V_4 . V_146 , V_190 , V_191 ) ;
F_156 ( V_4 ) ;
}
static void F_157 ( struct V_3 * V_4 , int V_198 ,
enum V_199 V_200 ,
bool V_201 , bool V_202 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_203 * V_204 ;
struct V_156 * V_157 ;
int V_85 = sizeof( * V_204 ) ;
T_7 V_205 ;
bool V_206 = V_4 -> V_4 . V_207 ;
struct V_158 * V_159 ;
struct V_208 * V_209 ;
if ( V_206 ) {
V_205 = F_55 ( V_210 |
V_211 |
V_212 ) ;
} else {
V_85 -= 2 ;
V_205 = F_55 ( V_210 |
V_213 |
V_212 ) ;
}
V_157 = F_158 ( V_2 -> V_31 . V_214 + V_85 ) ;
if ( ! V_157 )
return;
F_159 ( V_157 , V_2 -> V_31 . V_214 ) ;
V_204 = ( void * ) F_160 ( V_157 , V_85 ) ;
V_204 -> V_215 = V_205 ;
V_204 -> V_216 = 0 ;
memcpy ( V_204 -> V_217 , V_4 -> V_4 . V_42 , V_71 ) ;
memcpy ( V_204 -> V_218 , V_13 -> V_19 . V_42 , V_71 ) ;
memcpy ( V_204 -> V_219 , V_13 -> V_19 . V_42 , V_71 ) ;
V_204 -> V_220 = 0 ;
V_157 -> V_221 = V_198 ;
F_161 ( V_157 , V_222 [ V_198 ] ) ;
if ( V_206 ) {
V_204 -> V_223 = F_55 ( V_198 ) ;
if ( V_200 == V_224 ) {
V_204 -> V_223 |=
F_55 ( V_225 ) ;
if ( V_202 )
V_204 -> V_215 |=
F_55 ( V_226 ) ;
}
}
V_159 = F_97 ( V_157 ) ;
V_159 -> V_167 |= V_227 |
V_228 |
V_229 ;
V_159 -> V_166 . V_167 |= V_230 ;
if ( V_201 )
F_162 ( V_2 , V_4 , F_88 ( V_198 ) , 1 ,
V_200 , false ) ;
V_157 -> V_133 = V_13 -> V_133 ;
F_20 () ;
V_209 = F_163 ( V_13 -> V_19 . V_209 ) ;
if ( F_57 ( ! V_209 ) ) {
F_23 () ;
F_164 ( V_157 ) ;
return;
}
V_159 -> V_231 = V_209 -> V_232 . V_233 -> V_231 ;
F_165 ( V_13 , V_4 , V_157 ) ;
F_23 () ;
}
static int F_166 ( unsigned long V_149 )
{
if ( V_149 & 0xF8 )
return F_167 ( V_149 ) - 1 ;
if ( V_149 & F_88 ( 0 ) )
return 0 ;
return F_167 ( V_149 ) - 1 ;
}
static bool
F_168 ( struct V_3 * V_4 , T_1 V_234 ,
enum V_199 V_200 ,
unsigned long V_235 )
{
int V_8 ;
if ( V_200 == V_236 &&
F_169 ( V_235 ) > 1 )
return true ;
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ ) {
if ( V_234 & F_88 ( V_8 ) )
continue;
if ( ! F_91 ( & V_4 -> V_36 [ V_8 ] ) ||
! F_91 ( & V_4 -> V_35 [ V_8 ] ) )
return true ;
}
return false ;
}
static void
F_170 ( struct V_3 * V_4 , int V_237 , T_1 V_234 ,
enum V_199 V_200 ,
struct V_189 * V_238 ,
unsigned long * V_235 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ ) {
unsigned long V_149 ;
if ( V_234 & F_88 ( V_8 ) )
continue;
V_149 = F_87 ( V_8 ) ;
if ( F_91 ( V_238 ) ) {
* V_235 |=
V_4 -> V_150 & V_149 ;
* V_235 |= V_4 -> V_151 & V_149 ;
}
if ( ! * V_235 ) {
struct V_156 * V_157 ;
while ( V_237 > 0 ) {
V_157 = F_171 ( & V_4 -> V_36 [ V_8 ] ) ;
if ( ! V_157 ) {
V_157 = F_171 (
& V_4 -> V_35 [ V_8 ] ) ;
if ( V_157 )
V_2 -> V_34 -- ;
}
if ( ! V_157 )
break;
V_237 -- ;
F_172 ( V_238 , V_157 ) ;
}
}
if ( ! F_91 ( & V_4 -> V_36 [ V_8 ] ) ||
! F_91 ( & V_4 -> V_35 [ V_8 ] ) )
break;
}
}
static void
F_173 ( struct V_3 * V_4 ,
int V_237 , T_1 V_234 ,
enum V_199 V_200 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
unsigned long V_235 = 0 ;
struct V_189 V_238 ;
bool V_202 ;
F_70 ( V_4 , V_193 ) ;
F_174 ( & V_238 ) ;
F_170 ( V_4 , V_237 , V_234 , V_200 ,
& V_238 , & V_235 ) ;
V_202 = F_168 ( V_4 , V_234 , V_200 , V_235 ) ;
if ( V_235 && V_200 == V_236 )
V_235 =
F_88 ( F_166 ( V_235 ) ) ;
if ( F_91 ( & V_238 ) && ! V_235 ) {
int V_198 ;
V_198 = 7 - ( ( F_175 ( ~ V_234 ) - 1 ) << 1 ) ;
F_157 ( V_4 , V_198 , V_200 , true , false ) ;
} else if ( ! V_235 ) {
struct V_189 V_41 ;
struct V_156 * V_157 ;
int V_239 = 0 ;
T_4 V_149 = 0 ;
bool V_240 = false ;
F_54 ( & V_41 ) ;
while ( ( V_157 = F_102 ( & V_238 ) ) ) {
struct V_158 * V_159 = F_97 ( V_157 ) ;
struct V_241 * V_242 = ( void * ) V_157 -> V_175 ;
T_1 * V_243 = NULL ;
V_239 ++ ;
V_159 -> V_167 |= V_227 ;
V_159 -> V_166 . V_167 |= V_230 ;
if ( V_202 || ! F_91 ( & V_238 ) )
V_242 -> V_215 |=
F_55 ( V_226 ) ;
else
V_242 -> V_215 &=
F_55 ( ~ V_226 ) ;
if ( F_176 ( V_242 -> V_215 ) ||
F_177 ( V_242 -> V_215 ) )
V_243 = F_178 ( V_242 ) ;
V_149 |= F_88 ( V_157 -> V_221 ) ;
F_172 ( & V_41 , V_157 ) ;
if ( ! F_91 ( & V_238 ) )
continue;
if ( V_200 != V_224 ) {
V_159 -> V_167 |= V_228 |
V_229 ;
break;
}
if ( V_243 ) {
* V_243 |= V_225 ;
V_159 -> V_167 |= V_228 |
V_229 ;
} else {
V_242 -> V_215 |=
F_55 ( V_226 ) ;
V_240 = true ;
V_239 ++ ;
}
break;
}
F_162 ( V_2 , V_4 , V_149 , V_239 ,
V_200 , V_202 ) ;
F_150 ( V_2 , & V_41 ) ;
if ( V_240 )
F_157 (
V_4 , F_166 ( V_149 ) ,
V_200 , false , false ) ;
F_95 ( V_4 ) ;
} else {
unsigned long V_149 = V_4 -> V_151 & V_235 ;
int V_198 ;
F_179 ( V_2 , V_4 , V_235 ,
V_237 , V_200 , V_202 ) ;
if ( ! V_4 -> V_4 . V_26 [ 0 ] )
return;
for ( V_198 = 0 ; V_198 < F_8 ( V_4 -> V_4 . V_26 ) ; V_198 ++ ) {
struct V_27 * V_28 = F_9 ( V_4 -> V_4 . V_26 [ V_198 ] ) ;
if ( ! ( V_149 & F_88 ( V_198 ) ) || F_10 ( & V_28 -> V_30 ) )
continue;
F_95 ( V_4 ) ;
break;
}
}
}
void F_37 ( struct V_3 * V_4 )
{
T_1 V_244 = V_4 -> V_4 . V_145 ;
if ( V_244 == F_88 ( V_33 ) - 1 )
V_244 = 0 ;
F_173 ( V_4 , 1 , V_244 ,
V_236 ) ;
}
void F_38 ( struct V_3 * V_4 )
{
int V_237 = V_4 -> V_4 . V_245 ;
T_1 V_246 = V_4 -> V_4 . V_145 ;
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
F_173 ( V_4 , V_237 , ~ V_246 ,
V_224 ) ;
}
void F_180 ( struct V_59 * V_31 ,
struct V_186 * V_247 , bool V_248 )
{
struct V_3 * V_4 = F_33 ( V_247 , struct V_3 , V_4 ) ;
F_181 ( V_4 -> V_2 , V_247 , V_248 ) ;
if ( V_248 ) {
F_70 ( V_4 , V_17 ) ;
F_182 ( V_4 ) ;
return;
}
if ( ! F_4 ( V_4 , V_17 ) )
return;
if ( ! F_4 ( V_4 , V_16 ) ) {
F_70 ( V_4 , V_18 ) ;
F_6 ( V_4 , V_17 ) ;
F_183 ( V_31 , & V_4 -> V_37 ) ;
} else if ( F_4 ( V_4 , V_53 ) ||
F_4 ( V_4 , V_54 ) ) {
F_6 ( V_4 , V_17 ) ;
F_183 ( V_31 , & V_4 -> V_37 ) ;
} else {
F_6 ( V_4 , V_17 ) ;
F_156 ( V_4 ) ;
}
}
void F_184 ( struct V_186 * V_247 )
{
struct V_3 * V_4 = F_33 ( V_247 , struct V_3 , V_4 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_185 ( V_2 , V_247 ) ;
F_6 ( V_4 , V_193 ) ;
}
void F_186 ( struct V_186 * V_247 , int V_198 )
{
struct V_3 * V_4 = F_33 ( V_247 , struct V_3 , V_4 ) ;
enum V_199 V_200 ;
bool V_202 ;
F_187 ( V_4 -> V_2 , V_247 , V_198 ) ;
V_200 = V_224 ;
V_202 = F_168 ( V_4 , ~ V_4 -> V_4 . V_145 ,
V_200 , 0 ) ;
F_157 ( V_4 , V_198 , V_200 , false , V_202 ) ;
}
void F_188 ( struct V_186 * V_247 ,
T_1 V_198 , bool V_191 )
{
struct V_3 * V_4 = F_33 ( V_247 , struct V_3 , V_4 ) ;
if ( F_57 ( V_198 >= V_38 ) )
return;
F_189 ( V_4 -> V_2 , V_247 , V_198 , V_191 ) ;
if ( V_191 )
F_190 ( V_198 , & V_4 -> V_150 ) ;
else
F_191 ( V_198 , & V_4 -> V_150 ) ;
F_95 ( V_4 ) ;
}
int F_115 ( struct V_3 * V_4 ,
enum V_113 V_249 )
{
F_81 () ;
if ( V_4 -> V_75 == V_249 )
return 0 ;
switch ( V_249 ) {
case V_76 :
if ( V_4 -> V_75 != V_250 )
return - V_109 ;
break;
case V_250 :
if ( V_4 -> V_75 != V_76 &&
V_4 -> V_75 != V_251 )
return - V_109 ;
break;
case V_251 :
if ( V_4 -> V_75 != V_250 &&
V_4 -> V_75 != V_252 )
return - V_109 ;
break;
case V_252 :
if ( V_4 -> V_75 != V_251 )
return - V_109 ;
break;
default:
F_192 ( 1 , L_10 , V_249 ) ;
return - V_109 ;
}
F_28 ( V_4 -> V_13 , L_11 ,
V_4 -> V_4 . V_42 , V_249 ) ;
if ( F_4 ( V_4 , V_130 ) ) {
int V_115 = F_66 ( V_4 -> V_2 , V_4 -> V_13 , V_4 ,
V_4 -> V_75 , V_249 ) ;
if ( V_115 )
return V_115 ;
}
switch ( V_249 ) {
case V_76 :
if ( V_4 -> V_75 == V_250 )
F_191 ( V_253 , & V_4 -> V_254 ) ;
break;
case V_250 :
if ( V_4 -> V_75 == V_76 )
F_190 ( V_253 , & V_4 -> V_254 ) ;
else if ( V_4 -> V_75 == V_251 )
F_191 ( V_255 , & V_4 -> V_254 ) ;
break;
case V_251 :
if ( V_4 -> V_75 == V_250 ) {
F_190 ( V_255 , & V_4 -> V_254 ) ;
} else if ( V_4 -> V_75 == V_252 ) {
if ( V_4 -> V_13 -> V_19 . type == V_20 ||
( V_4 -> V_13 -> V_19 . type == V_21 &&
! V_4 -> V_13 -> V_23 . V_174 . V_4 ) )
F_7 ( & V_4 -> V_13 -> V_22 -> V_256 ) ;
F_191 ( V_257 , & V_4 -> V_254 ) ;
F_182 ( V_4 ) ;
}
break;
case V_252 :
if ( V_4 -> V_75 == V_251 ) {
if ( V_4 -> V_13 -> V_19 . type == V_20 ||
( V_4 -> V_13 -> V_19 . type == V_21 &&
! V_4 -> V_13 -> V_23 . V_174 . V_4 ) )
F_193 ( & V_4 -> V_13 -> V_22 -> V_256 ) ;
F_190 ( V_257 , & V_4 -> V_254 ) ;
F_156 ( V_4 ) ;
}
break;
default:
break;
}
V_4 -> V_75 = V_249 ;
return 0 ;
}
T_1 F_153 ( struct V_3 * V_4 )
{
struct V_258 * V_98 = & V_4 -> V_4 . V_98 ;
T_1 V_259 ;
if ( ! V_4 -> V_4 . V_98 . V_260 )
return 1 ;
if ( V_4 -> V_4 . V_261 . V_262 ) {
int V_9 ;
T_4 V_263 =
F_194 ( V_4 -> V_4 . V_261 . V_264 . V_263 ) ;
for ( V_9 = 7 ; V_9 >= 0 ; V_9 -- )
if ( ( V_263 & ( 0x3 << ( V_9 * 2 ) ) ) !=
V_265 )
return V_9 + 1 ;
}
if ( V_98 -> V_266 . V_267 [ 3 ] )
V_259 = 4 ;
else if ( V_98 -> V_266 . V_267 [ 2 ] )
V_259 = 3 ;
else if ( V_98 -> V_266 . V_267 [ 1 ] )
V_259 = 2 ;
else
V_259 = 1 ;
if ( ! ( V_98 -> V_266 . V_268 & V_269 ) )
return V_259 ;
return ( ( V_98 -> V_266 . V_268 & V_270 )
>> V_271 ) + 1 ;
}
static void F_195 ( struct V_3 * V_4 , struct V_272 * V_273 )
{
V_273 -> V_167 = 0 ;
if ( V_4 -> V_72 . V_274 & V_275 ) {
V_273 -> V_167 |= V_276 ;
V_273 -> V_266 = V_4 -> V_72 . V_277 ;
} else if ( V_4 -> V_72 . V_274 & V_278 ) {
V_273 -> V_167 |= V_279 ;
V_273 -> V_280 = V_4 -> V_72 . V_281 ;
V_273 -> V_266 = V_4 -> V_72 . V_277 ;
} else {
struct V_93 * V_94 ;
int V_282 = F_196 ( & V_4 -> V_13 -> V_19 ) ;
T_4 V_283 ;
V_94 = V_4 -> V_2 -> V_31 . V_95 -> V_96 [
F_56 ( V_4 -> V_13 ) ] ;
V_283 = V_94 -> V_284 [ V_4 -> V_72 . V_277 ] . V_285 ;
V_273 -> V_286 = F_197 ( V_283 , 1 << V_282 ) ;
}
if ( V_4 -> V_72 . V_274 & V_287 )
V_273 -> V_167 |= V_288 ;
if ( V_4 -> V_72 . V_274 & V_289 )
V_273 -> V_290 = V_291 ;
else if ( V_4 -> V_72 . V_274 & V_292 )
V_273 -> V_290 = V_293 ;
else if ( V_4 -> V_72 . V_274 & V_294 )
V_273 -> V_290 = V_295 ;
else if ( V_4 -> V_72 . V_296 & V_297 )
V_273 -> V_290 = V_298 ;
else if ( V_4 -> V_72 . V_296 & V_299 )
V_273 -> V_290 = V_300 ;
else
V_273 -> V_290 = V_301 ;
}
void F_116 ( struct V_3 * V_4 , struct V_120 * V_121 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_302 * V_303 = NULL ;
T_6 V_304 = 0 ;
int V_9 , V_8 ;
if ( F_4 ( V_4 , V_305 ) )
V_303 = V_2 -> V_48 ;
V_121 -> V_132 = V_13 -> V_2 -> V_125 ;
if ( V_13 -> V_19 . type == V_306 )
V_121 -> V_307 = V_13 -> V_23 . V_308 . V_309 ;
F_198 ( V_2 , V_13 , & V_4 -> V_4 , V_121 ) ;
V_121 -> V_131 |= F_88 ( V_310 ) |
F_88 ( V_311 ) |
F_88 ( V_312 ) |
F_88 ( V_313 ) |
F_88 ( V_314 ) ;
if ( V_13 -> V_19 . type == V_306 ) {
V_121 -> V_315 = V_13 -> V_23 . V_308 . V_315 ;
V_121 -> V_131 |= F_88 ( V_316 ) ;
}
V_121 -> V_317 = F_49 () - V_4 -> V_79 ;
V_121 -> V_318 =
F_199 ( V_74 - V_4 -> V_72 . V_73 ) ;
if ( ! ( V_121 -> V_131 & ( F_88 ( V_319 ) |
F_88 ( V_320 ) ) ) ) {
V_121 -> V_321 = 0 ;
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ )
V_121 -> V_321 += V_4 -> V_322 . V_323 [ V_8 ] ;
V_121 -> V_131 |= F_88 ( V_319 ) ;
}
if ( ! ( V_121 -> V_131 & F_88 ( V_324 ) ) ) {
V_121 -> V_325 = 0 ;
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ )
V_121 -> V_325 += V_4 -> V_322 . V_326 [ V_8 ] ;
V_121 -> V_131 |= F_88 ( V_324 ) ;
}
if ( ! ( V_121 -> V_131 & ( F_88 ( V_327 ) |
F_88 ( V_328 ) ) ) ) {
V_121 -> V_329 = V_4 -> V_72 . V_323 ;
V_121 -> V_131 |= F_88 ( V_327 ) ;
}
if ( ! ( V_121 -> V_131 & F_88 ( V_330 ) ) ) {
V_121 -> V_331 = V_4 -> V_72 . V_326 ;
V_121 -> V_131 |= F_88 ( V_330 ) ;
}
if ( ! ( V_121 -> V_131 & F_88 ( V_332 ) ) ) {
V_121 -> V_333 = V_4 -> V_334 . V_335 ;
V_121 -> V_131 |= F_88 ( V_332 ) ;
}
if ( ! ( V_121 -> V_131 & F_88 ( V_336 ) ) ) {
V_121 -> V_337 = V_4 -> V_334 . V_338 ;
V_121 -> V_131 |= F_88 ( V_336 ) ;
}
V_121 -> V_339 = V_4 -> V_72 . V_340 ;
if ( V_13 -> V_19 . type == V_306 &&
! ( V_13 -> V_19 . V_341 & V_342 ) ) {
V_121 -> V_131 |= F_88 ( V_343 ) |
F_88 ( V_344 ) ;
V_121 -> V_345 = F_200 ( & V_13 -> V_19 ) ;
}
if ( F_41 ( & V_4 -> V_2 -> V_31 , V_346 ) ||
F_41 ( & V_4 -> V_2 -> V_31 , V_347 ) ) {
if ( ! ( V_121 -> V_131 & F_88 ( V_348 ) ) ) {
V_121 -> signal = ( V_349 ) V_4 -> V_72 . V_350 ;
V_121 -> V_131 |= F_88 ( V_348 ) ;
}
if ( ! ( V_121 -> V_131 & F_88 ( V_351 ) ) ) {
V_121 -> V_352 =
- F_201 ( & V_4 -> V_72 . V_80 ) ;
V_121 -> V_131 |= F_88 ( V_351 ) ;
}
}
if ( V_4 -> V_72 . V_353 &&
! ( V_121 -> V_131 & ( F_88 ( V_354 ) |
F_88 ( V_355 ) ) ) ) {
V_121 -> V_131 |= F_88 ( V_354 ) |
F_88 ( V_355 ) ;
V_121 -> V_353 = V_4 -> V_72 . V_353 ;
for ( V_9 = 0 ; V_9 < F_8 ( V_121 -> V_356 ) ; V_9 ++ ) {
V_121 -> V_356 [ V_9 ] =
V_4 -> V_72 . V_357 [ V_9 ] ;
V_121 -> V_81 [ V_9 ] =
- F_201 ( & V_4 -> V_72 . V_81 [ V_9 ] ) ;
}
}
if ( ! ( V_121 -> V_131 & F_88 ( V_358 ) ) ) {
F_202 ( V_4 , & V_4 -> V_322 . V_359 ,
& V_121 -> V_360 ) ;
V_121 -> V_131 |= F_88 ( V_358 ) ;
}
if ( ! ( V_121 -> V_131 & F_88 ( V_361 ) ) ) {
F_195 ( V_4 , & V_121 -> V_362 ) ;
V_121 -> V_131 |= F_88 ( V_361 ) ;
}
V_121 -> V_131 |= F_88 ( V_363 ) ;
for ( V_9 = 0 ; V_9 < V_38 + 1 ; V_9 ++ ) {
struct V_364 * V_365 = & V_121 -> V_366 [ V_9 ] ;
if ( ! ( V_365 -> V_131 & F_88 ( V_367 ) ) ) {
V_365 -> V_131 |= F_88 ( V_367 ) ;
V_365 -> V_368 = V_4 -> V_72 . V_369 [ V_9 ] ;
}
if ( ! ( V_365 -> V_131 & F_88 ( V_370 ) ) ) {
V_365 -> V_131 |= F_88 ( V_370 ) ;
V_365 -> V_371 = V_4 -> V_322 . V_369 [ V_9 ] ;
}
if ( ! ( V_365 -> V_131 &
F_88 ( V_372 ) ) &&
F_41 ( & V_2 -> V_31 , V_373 ) ) {
V_365 -> V_131 |=
F_88 ( V_372 ) ;
V_365 -> V_374 =
V_4 -> V_334 . V_375 [ V_9 ] ;
}
if ( ! ( V_365 -> V_131 &
F_88 ( V_376 ) ) &&
F_41 ( & V_2 -> V_31 , V_373 ) ) {
V_365 -> V_131 |=
F_88 ( V_376 ) ;
V_365 -> V_377 =
V_4 -> V_334 . V_378 [ V_9 ] ;
}
}
if ( F_5 ( & V_13 -> V_19 ) ) {
#ifdef F_29
V_121 -> V_131 |= F_88 ( V_379 ) |
F_88 ( V_380 ) |
F_88 ( V_381 ) |
F_88 ( V_382 ) |
F_88 ( V_383 ) |
F_88 ( V_384 ) ;
V_121 -> V_385 = V_4 -> V_24 -> V_385 ;
V_121 -> V_386 = V_4 -> V_24 -> V_386 ;
V_121 -> V_387 = V_4 -> V_24 -> V_387 ;
if ( F_4 ( V_4 , V_388 ) ) {
V_121 -> V_131 |= F_88 ( V_389 ) ;
V_121 -> V_390 = V_4 -> V_24 -> V_390 ;
}
V_121 -> V_391 = V_4 -> V_24 -> V_391 ;
V_121 -> V_392 = V_4 -> V_24 -> V_392 ;
V_121 -> V_69 = V_4 -> V_24 -> V_69 ;
#endif
}
V_121 -> V_393 . V_167 = 0 ;
if ( V_13 -> V_19 . V_162 . V_394 )
V_121 -> V_393 . V_167 |= V_395 ;
if ( V_13 -> V_19 . V_162 . V_396 )
V_121 -> V_393 . V_167 |= V_397 ;
if ( V_13 -> V_19 . V_162 . V_398 )
V_121 -> V_393 . V_167 |= V_399 ;
V_121 -> V_393 . V_400 = V_13 -> V_19 . V_162 . V_400 ;
V_121 -> V_393 . V_401 = V_13 -> V_19 . V_162 . V_163 ;
V_121 -> V_402 . V_403 = 0 ;
V_121 -> V_402 . V_404 = F_88 ( V_405 ) |
F_88 ( V_406 ) |
F_88 ( V_407 ) |
F_88 ( V_408 ) |
F_88 ( V_409 ) |
F_88 ( V_410 ) |
F_88 ( V_411 ) ;
if ( F_4 ( V_4 , V_257 ) )
V_121 -> V_402 . V_403 |= F_88 ( V_405 ) ;
if ( F_4 ( V_4 , V_412 ) )
V_121 -> V_402 . V_403 |= F_88 ( V_406 ) ;
if ( V_4 -> V_4 . V_207 )
V_121 -> V_402 . V_403 |= F_88 ( V_407 ) ;
if ( F_4 ( V_4 , V_413 ) )
V_121 -> V_402 . V_403 |= F_88 ( V_408 ) ;
if ( F_4 ( V_4 , V_253 ) )
V_121 -> V_402 . V_403 |= F_88 ( V_409 ) ;
if ( F_4 ( V_4 , V_255 ) )
V_121 -> V_402 . V_403 |= F_88 ( V_410 ) ;
if ( F_4 ( V_4 , V_414 ) )
V_121 -> V_402 . V_403 |= F_88 ( V_411 ) ;
if ( V_303 && V_303 -> V_82 -> V_415 )
V_304 = V_303 -> V_82 -> V_415 ( V_4 -> V_57 ) ;
else
V_304 = F_203 ( V_2 , & V_4 -> V_4 ) ;
if ( V_304 != 0 ) {
V_121 -> V_131 |= F_88 ( V_416 ) ;
V_121 -> V_417 = V_304 ;
}
}
