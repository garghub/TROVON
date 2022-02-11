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
struct V_60 V_61 ;
int V_9 ;
V_4 = F_44 ( sizeof( * V_4 ) + V_31 -> V_62 , V_55 ) ;
if ( ! V_4 )
return NULL ;
F_45 ( & V_4 -> V_63 ) ;
F_45 ( & V_4 -> V_64 ) ;
F_46 ( & V_4 -> V_37 , F_32 ) ;
F_46 ( & V_4 -> V_39 . V_65 , V_66 ) ;
F_47 ( & V_4 -> V_39 . V_67 ) ;
#ifdef F_29
if ( F_5 ( & V_13 -> V_19 ) ) {
V_4 -> V_24 = F_44 ( sizeof( * V_4 -> V_24 ) , V_55 ) ;
if ( ! V_4 -> V_24 )
goto free;
F_45 ( & V_4 -> V_24 -> V_68 ) ;
if ( F_5 ( & V_13 -> V_19 ) &&
! V_13 -> V_23 . V_24 . V_69 )
F_48 ( & V_4 -> V_24 -> V_70 ) ;
V_4 -> V_24 -> V_71 = V_72 ;
}
#endif
memcpy ( V_4 -> V_42 , V_42 , V_73 ) ;
memcpy ( V_4 -> V_4 . V_42 , V_42 , V_73 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_13 = V_13 ;
V_4 -> V_74 = V_75 ;
V_4 -> V_76 = V_77 ;
V_4 -> V_78 = V_79 ;
F_49 ( & V_61 ) ;
V_4 -> V_80 = V_61 . V_81 ;
F_50 ( & V_4 -> V_82 ) ;
for ( V_9 = 0 ; V_9 < F_8 ( V_4 -> V_83 ) ; V_9 ++ )
F_50 ( & V_4 -> V_83 [ V_9 ] ) ;
if ( V_2 -> V_84 -> V_85 ) {
void * V_86 ;
int V_87 = sizeof( struct V_27 ) +
F_51 ( V_31 -> V_88 , sizeof( void * ) ) ;
V_86 = F_52 ( F_8 ( V_4 -> V_4 . V_26 ) , V_87 , V_55 ) ;
if ( ! V_86 )
goto free;
for ( V_9 = 0 ; V_9 < F_8 ( V_4 -> V_4 . V_26 ) ; V_9 ++ ) {
struct V_27 * V_26 = V_86 + V_9 * V_87 ;
F_53 ( V_13 , V_4 , V_26 , V_9 ) ;
}
}
if ( F_40 ( V_2 , V_4 , V_55 ) )
goto V_89;
for ( V_9 = 0 ; V_9 < V_38 ; V_9 ++ ) {
V_4 -> V_90 [ V_9 ] = V_9 ;
}
for ( V_9 = 0 ; V_9 < V_33 ; V_9 ++ ) {
F_54 ( & V_4 -> V_35 [ V_9 ] ) ;
F_54 ( & V_4 -> V_36 [ V_9 ] ) ;
}
for ( V_9 = 0 ; V_9 < V_38 ; V_9 ++ )
V_4 -> V_91 [ V_9 ] = F_55 ( V_92 ) ;
V_4 -> V_4 . V_93 = V_94 ;
if ( V_13 -> V_19 . type == V_20 ||
V_13 -> V_19 . type == V_21 ) {
struct V_95 * V_96 =
V_31 -> V_97 -> V_98 [ F_56 ( V_13 ) ] ;
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
F_57 ( 1 ) ;
}
}
F_28 ( V_13 , L_2 , V_4 -> V_4 . V_42 ) ;
return V_4 ;
V_89:
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
return - V_110 ;
if ( F_57 ( F_61 ( V_4 -> V_4 . V_42 , V_13 -> V_19 . V_42 ) ||
F_62 ( V_4 -> V_4 . V_42 ) ) )
return - V_111 ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_3 * V_4 )
{
enum V_112 V_113 ;
int V_114 = 0 ;
for ( V_113 = V_115 ; V_113 < V_4 -> V_76 ; V_113 ++ ) {
V_114 = F_64 ( V_2 , V_13 , V_4 , V_113 , V_113 + 1 ) ;
if ( V_114 )
break;
}
if ( ! V_114 ) {
if ( ! V_2 -> V_84 -> V_116 )
V_4 -> V_117 = true ;
return 0 ;
}
if ( V_13 -> V_19 . type == V_118 ) {
F_65 ( V_13 ,
L_3 ,
V_4 -> V_4 . V_42 , V_113 + 1 , V_114 ) ;
V_114 = 0 ;
}
for (; V_113 > V_115 ; V_113 -- )
F_57 ( F_64 ( V_2 , V_13 , V_4 , V_113 , V_113 - 1 ) ) ;
return V_114 ;
}
static int F_66 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_119 V_120 ;
int V_114 = 0 ;
F_67 ( & V_2 -> V_121 ) ;
if ( F_24 ( V_13 , V_4 -> V_4 . V_42 ) ) {
V_114 = - V_122 ;
goto V_123;
}
V_2 -> V_124 ++ ;
V_2 -> V_125 ++ ;
F_68 () ;
F_69 ( V_4 , V_126 ) ;
F_30 ( V_2 , V_4 ) ;
F_70 ( & V_4 -> V_127 , & V_2 -> V_128 ) ;
V_114 = F_63 ( V_2 , V_13 , V_4 ) ;
if ( V_114 )
goto V_129;
F_69 ( V_4 , V_130 ) ;
F_6 ( V_4 , V_126 ) ;
F_71 ( V_13 ) ;
F_72 ( V_4 ) ;
F_73 ( V_4 ) ;
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
V_120 . V_131 = 0 ;
V_120 . V_132 = V_2 -> V_125 ;
F_74 ( V_13 -> V_133 , V_4 -> V_4 . V_42 , & V_120 , V_134 ) ;
F_28 ( V_13 , L_4 , V_4 -> V_4 . V_42 ) ;
F_20 () ;
F_75 ( & V_2 -> V_121 ) ;
if ( F_5 ( & V_13 -> V_19 ) )
F_76 ( V_13 ) ;
return 0 ;
V_129:
F_1 ( V_2 , V_4 ) ;
F_77 ( & V_4 -> V_127 ) ;
V_2 -> V_124 -- ;
F_78 () ;
F_3 ( V_4 ) ;
V_123:
F_75 ( & V_2 -> V_121 ) ;
F_20 () ;
return V_114 ;
}
int F_79 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_114 ;
F_80 () ;
V_114 = F_58 ( V_4 ) ;
if ( V_114 ) {
F_20 () ;
goto V_135;
}
F_81 ( & V_2 -> V_121 ) ;
V_114 = F_66 ( V_4 ) ;
if ( V_114 )
goto V_135;
return 0 ;
V_135:
F_18 ( V_2 , V_4 ) ;
return V_114 ;
}
int F_82 ( struct V_3 * V_4 )
{
int V_114 = F_79 ( V_4 ) ;
F_23 () ;
return V_114 ;
}
static inline void F_83 ( T_1 * V_136 , T_4 V_137 )
{
V_136 [ V_137 / 8 ] |= ( 1 << ( V_137 % 8 ) ) ;
}
static inline void F_84 ( T_1 * V_136 , T_4 V_137 )
{
V_136 [ V_137 / 8 ] &= ~ ( 1 << ( V_137 % 8 ) ) ;
}
static inline bool F_85 ( T_1 * V_136 , T_4 V_137 )
{
return V_136 [ V_137 / 8 ] & ( 1 << ( V_137 % 8 ) ) ;
}
static unsigned long F_86 ( int V_8 )
{
switch ( V_8 ) {
case V_138 :
return F_87 ( 6 ) | F_87 ( 7 ) ;
case V_139 :
return F_87 ( 4 ) | F_87 ( 5 ) ;
case V_140 :
return F_87 ( 0 ) | F_87 ( 3 ) ;
case V_141 :
return F_87 ( 1 ) | F_87 ( 2 ) ;
default:
F_57 ( 1 ) ;
return 0 ;
}
}
static void F_88 ( struct V_3 * V_4 , bool V_142 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_14 * V_15 ;
bool V_143 = false ;
T_1 V_144 = V_4 -> V_4 . V_145 ;
int V_8 ;
T_4 V_137 = V_4 -> V_4 . V_146 ;
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
if ( F_41 ( & V_2 -> V_31 , V_147 ) )
return;
if ( V_4 -> V_52 )
goto V_148;
if ( V_144 == F_87 ( V_33 ) - 1 )
V_144 = 0 ;
if ( V_142 )
V_144 = F_87 ( V_33 ) - 1 ;
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ ) {
unsigned long V_149 ;
if ( V_144 & F_87 ( V_8 ) )
continue;
V_143 |= ! F_90 ( & V_4 -> V_36 [ V_8 ] ) ||
! F_90 ( & V_4 -> V_35 [ V_8 ] ) ;
if ( V_143 )
break;
V_149 = F_86 ( V_8 ) ;
V_143 |=
V_4 -> V_150 & V_149 ;
V_143 |=
V_4 -> V_151 & V_149 ;
}
V_148:
F_91 ( & V_2 -> V_152 ) ;
if ( V_143 == F_85 ( V_15 -> V_136 , V_137 ) )
goto V_153;
if ( V_143 )
F_83 ( V_15 -> V_136 , V_137 ) ;
else
F_84 ( V_15 -> V_136 , V_137 ) ;
if ( V_2 -> V_84 -> V_154 && ! F_57 ( V_4 -> V_52 ) ) {
V_2 -> V_155 = true ;
F_92 ( V_2 , & V_4 -> V_4 , V_143 ) ;
V_2 -> V_155 = false ;
}
V_153:
F_93 ( & V_2 -> V_152 ) ;
}
void F_94 ( struct V_3 * V_4 )
{
F_88 ( V_4 , false ) ;
}
static bool F_95 ( struct V_3 * V_4 , struct V_156 * V_157 )
{
struct V_158 * V_159 ;
int V_160 ;
if ( ! V_157 )
return false ;
V_159 = F_96 ( V_157 ) ;
V_160 = ( V_4 -> V_161 *
V_4 -> V_13 -> V_19 . V_162 . V_163 *
32 / 15625 ) * V_164 ;
if ( V_160 < V_165 )
V_160 = V_165 ;
return F_97 ( V_75 , V_159 -> V_166 . V_75 + V_160 ) ;
}
static bool F_98 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_8 )
{
unsigned long V_167 ;
struct V_156 * V_157 ;
for (; ; ) {
F_99 ( & V_4 -> V_36 [ V_8 ] . V_63 , V_167 ) ;
V_157 = F_100 ( & V_4 -> V_36 [ V_8 ] ) ;
if ( F_95 ( V_4 , V_157 ) )
V_157 = F_101 ( & V_4 -> V_36 [ V_8 ] ) ;
else
V_157 = NULL ;
F_102 ( & V_4 -> V_36 [ V_8 ] . V_63 , V_167 ) ;
if ( ! V_157 )
break;
F_103 ( & V_2 -> V_31 , V_157 ) ;
}
for (; ; ) {
F_99 ( & V_4 -> V_35 [ V_8 ] . V_63 , V_167 ) ;
V_157 = F_100 ( & V_4 -> V_35 [ V_8 ] ) ;
if ( F_95 ( V_4 , V_157 ) )
V_157 = F_101 ( & V_4 -> V_35 [ V_8 ] ) ;
else
V_157 = NULL ;
F_102 ( & V_4 -> V_35 [ V_8 ] . V_63 , V_167 ) ;
if ( ! V_157 )
break;
V_2 -> V_34 -- ;
F_104 ( V_4 -> V_13 , L_5 ,
V_4 -> V_4 . V_42 ) ;
F_103 ( & V_2 -> V_31 , V_157 ) ;
}
F_94 ( V_4 ) ;
return ! ( F_90 ( & V_4 -> V_35 [ V_8 ] ) &&
F_90 ( & V_4 -> V_36 [ V_8 ] ) ) ;
}
static bool F_105 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_168 = false ;
int V_8 ;
if ( ! V_4 -> V_13 -> V_22 &&
! F_5 ( & V_4 -> V_13 -> V_19 ) )
return false ;
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ )
V_168 |=
F_98 ( V_2 , V_4 , V_8 ) ;
return V_168 ;
}
static int T_5 F_106 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
int V_169 ;
F_80 () ;
if ( ! V_4 )
return - V_170 ;
V_2 = V_4 -> V_2 ;
V_13 = V_4 -> V_13 ;
F_67 ( & V_2 -> V_121 ) ;
F_69 ( V_4 , V_126 ) ;
F_107 ( V_4 , V_171 ) ;
V_169 = F_1 ( V_2 , V_4 ) ;
if ( F_57 ( V_169 ) )
return V_169 ;
if ( F_4 ( V_4 , V_172 ) ) {
F_108 ( V_2 , V_13 , & V_4 -> V_4 ) ;
F_6 ( V_4 , V_172 ) ;
}
F_77 ( & V_4 -> V_127 ) ;
F_109 ( V_2 , V_4 -> V_13 , V_4 ) ;
if ( V_13 -> V_19 . type == V_21 &&
F_110 ( V_13 -> V_23 . V_173 . V_4 ) == V_4 )
F_111 ( V_13 -> V_23 . V_173 . V_4 , NULL ) ;
return 0 ;
}
static void F_112 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_119 V_120 = {} ;
int V_169 ;
F_80 () ;
F_67 ( & V_2 -> V_121 ) ;
F_113 ( V_2 , V_4 ) ;
F_88 ( V_4 , true ) ;
V_4 -> V_52 = true ;
V_2 -> V_124 -- ;
V_2 -> V_125 ++ ;
while ( V_4 -> V_76 > V_77 ) {
V_169 = F_114 ( V_4 , V_4 -> V_76 - 1 ) ;
if ( V_169 ) {
F_89 ( 1 ) ;
break;
}
}
if ( V_4 -> V_117 ) {
V_169 = F_64 ( V_2 , V_13 , V_4 , V_77 ,
V_115 ) ;
F_89 ( V_169 != 0 ) ;
}
F_28 ( V_13 , L_6 , V_4 -> V_4 . V_42 ) ;
F_115 ( V_4 , & V_120 ) ;
F_116 ( V_13 -> V_133 , V_4 -> V_4 . V_42 , & V_120 , V_134 ) ;
F_117 ( V_4 ) ;
F_118 ( V_4 ) ;
F_71 ( V_13 ) ;
F_17 ( V_4 ) ;
}
int T_5 F_119 ( struct V_3 * V_4 )
{
int V_114 = F_106 ( V_4 ) ;
if ( V_114 )
return V_114 ;
F_78 () ;
F_112 ( V_4 ) ;
return 0 ;
}
int F_120 ( struct V_12 * V_13 , const T_1 * V_42 )
{
struct V_3 * V_4 ;
int V_169 ;
F_81 ( & V_13 -> V_2 -> V_121 ) ;
V_4 = F_19 ( V_13 , V_42 ) ;
V_169 = F_119 ( V_4 ) ;
F_75 ( & V_13 -> V_2 -> V_121 ) ;
return V_169 ;
}
int F_121 ( struct V_12 * V_13 ,
const T_1 * V_42 )
{
struct V_3 * V_4 ;
int V_169 ;
F_81 ( & V_13 -> V_2 -> V_121 ) ;
V_4 = F_24 ( V_13 , V_42 ) ;
V_169 = F_119 ( V_4 ) ;
F_75 ( & V_13 -> V_2 -> V_121 ) ;
return V_169 ;
}
static void F_122 ( unsigned long V_174 )
{
struct V_1 * V_2 = (struct V_1 * ) V_174 ;
struct V_3 * V_4 ;
bool V_175 = false ;
F_20 () ;
F_26 (sta, &local->sta_list, list)
if ( F_105 ( V_2 , V_4 ) )
V_175 = true ;
F_23 () ;
if ( V_2 -> V_176 )
return;
if ( ! V_175 )
return;
F_123 ( & V_2 -> V_177 ,
F_124 ( V_75 + V_178 ) ) ;
}
T_6 F_125 ( const void * V_179 , T_6 V_180 , T_6 V_181 )
{
return F_126 ( V_179 , V_73 , V_181 ) ;
}
int F_127 ( struct V_1 * V_2 )
{
int V_114 ;
V_114 = F_128 ( & V_2 -> V_5 , & V_7 ) ;
if ( V_114 )
return V_114 ;
F_45 ( & V_2 -> V_152 ) ;
F_47 ( & V_2 -> V_121 ) ;
F_129 ( & V_2 -> V_128 ) ;
F_130 ( & V_2 -> V_177 , F_122 ,
( unsigned long ) V_2 ) ;
return 0 ;
}
void F_131 ( struct V_1 * V_2 )
{
F_132 ( & V_2 -> V_177 ) ;
F_133 ( & V_2 -> V_5 ) ;
}
int F_134 ( struct V_12 * V_13 , bool V_182 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 , * V_44 ;
F_135 ( V_183 ) ;
int V_169 = 0 ;
F_80 () ;
F_57 ( V_182 && V_13 -> V_19 . type != V_20 ) ;
F_57 ( V_182 && ! V_13 -> V_22 ) ;
F_81 ( & V_2 -> V_121 ) ;
F_136 (sta, tmp, &local->sta_list, list) {
if ( V_13 == V_4 -> V_13 ||
( V_182 && V_13 -> V_22 == V_4 -> V_13 -> V_22 ) ) {
if ( ! F_57 ( F_106 ( V_4 ) ) )
F_137 ( & V_4 -> V_183 , & V_183 ) ;
V_169 ++ ;
}
}
if ( ! F_138 ( & V_183 ) ) {
F_78 () ;
F_136 (sta, tmp, &free_list, free_list)
F_112 ( V_4 ) ;
}
F_75 ( & V_2 -> V_121 ) ;
return V_169 ;
}
void F_139 ( struct V_12 * V_13 ,
unsigned long V_184 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 , * V_44 ;
F_81 ( & V_2 -> V_121 ) ;
F_136 (sta, tmp, &local->sta_list, list) {
if ( V_13 != V_4 -> V_13 )
continue;
if ( F_97 ( V_75 , V_4 -> V_74 + V_184 ) ) {
F_28 ( V_4 -> V_13 , L_7 ,
V_4 -> V_4 . V_42 ) ;
if ( F_5 ( & V_13 -> V_19 ) &&
F_4 ( V_4 , V_16 ) )
F_7 ( & V_13 -> V_23 . V_24 . V_15 . V_25 ) ;
F_57 ( F_119 ( V_4 ) ) ;
}
}
F_75 ( & V_2 -> V_121 ) ;
}
struct V_185 * F_140 ( struct V_59 * V_31 ,
const T_1 * V_42 ,
const T_1 * V_186 )
{
struct V_1 * V_2 = F_141 ( V_31 ) ;
struct V_3 * V_4 ;
struct V_43 * V_44 ;
const struct V_45 * V_46 ;
V_46 = F_21 ( V_2 -> V_5 . V_46 , & V_2 -> V_5 ) ;
F_22 (local, tbl, addr, sta, tmp) {
if ( V_186 &&
! F_61 ( V_4 -> V_13 -> V_19 . V_42 , V_186 ) )
continue;
if ( ! V_4 -> V_117 )
return NULL ;
return & V_4 -> V_4 ;
}
return NULL ;
}
struct V_185 * F_142 ( struct V_187 * V_19 ,
const T_1 * V_42 )
{
struct V_3 * V_4 ;
if ( ! V_19 )
return NULL ;
V_4 = F_24 ( F_143 ( V_19 ) , V_42 ) ;
if ( ! V_4 )
return NULL ;
if ( ! V_4 -> V_117 )
return NULL ;
return & V_4 -> V_4 ;
}
void F_35 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_188 V_41 ;
int V_189 = 0 , V_190 = 0 , V_8 , V_9 ;
unsigned long V_167 ;
struct V_14 * V_15 ;
if ( V_13 -> V_19 . type == V_21 )
V_13 = F_33 ( V_13 -> V_22 , struct V_12 ,
V_23 . V_191 ) ;
if ( V_13 -> V_19 . type == V_20 )
V_15 = & V_13 -> V_22 -> V_15 ;
else if ( F_5 ( & V_13 -> V_19 ) )
V_15 = & V_13 -> V_23 . V_24 . V_15 ;
else
return;
F_6 ( V_4 , V_192 ) ;
F_144 ( F_145 ( V_38 ) > 1 ) ;
V_4 -> V_150 = 0 ;
V_4 -> V_151 = 0 ;
if ( ! F_41 ( & V_2 -> V_31 , V_147 ) )
F_146 ( V_2 , V_13 , V_193 , & V_4 -> V_4 ) ;
if ( V_4 -> V_4 . V_26 [ 0 ] ) {
for ( V_9 = 0 ; V_9 < F_8 ( V_4 -> V_4 . V_26 ) ; V_9 ++ ) {
struct V_27 * V_28 = F_9 ( V_4 -> V_4 . V_26 [ V_9 ] ) ;
if ( ! F_10 ( & V_28 -> V_30 ) )
continue;
F_147 ( V_2 , V_28 ) ;
}
}
F_54 ( & V_41 ) ;
F_148 ( & V_4 -> V_64 ) ;
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ ) {
int V_194 = F_10 ( & V_41 ) , V_44 ;
F_99 ( & V_4 -> V_36 [ V_8 ] . V_63 , V_167 ) ;
F_149 ( & V_4 -> V_36 [ V_8 ] , & V_41 ) ;
F_102 ( & V_4 -> V_36 [ V_8 ] . V_63 , V_167 ) ;
V_44 = F_10 ( & V_41 ) ;
V_189 += V_44 - V_194 ;
V_194 = V_44 ;
F_99 ( & V_4 -> V_35 [ V_8 ] . V_63 , V_167 ) ;
F_149 ( & V_4 -> V_35 [ V_8 ] , & V_41 ) ;
F_102 ( & V_4 -> V_35 [ V_8 ] . V_63 , V_167 ) ;
V_44 = F_10 ( & V_41 ) ;
V_190 += V_44 - V_194 ;
}
F_150 ( V_2 , & V_41 ) ;
F_6 ( V_4 , V_18 ) ;
F_6 ( V_4 , V_53 ) ;
F_6 ( V_4 , V_54 ) ;
F_151 ( & V_4 -> V_64 ) ;
F_7 ( & V_15 -> V_25 ) ;
if ( ! F_5 ( & V_13 -> V_19 ) &&
! F_152 ( V_4 -> V_105 ,
V_13 -> V_93 ) &&
V_4 -> V_105 != V_13 -> V_22 -> V_195 &&
F_153 ( V_4 ) != 1 ) {
F_154 ( V_13 ,
L_8 ,
V_4 -> V_4 . V_42 ) ;
F_155 ( V_13 , V_13 -> V_22 -> V_195 ,
V_4 -> V_4 . V_42 ,
V_13 -> V_19 . V_162 . V_196 ) ;
}
V_2 -> V_34 -= V_190 ;
F_94 ( V_4 ) ;
F_104 ( V_13 ,
L_9 ,
V_4 -> V_4 . V_42 , V_4 -> V_4 . V_146 , V_189 , V_190 ) ;
F_156 ( V_4 ) ;
}
static void F_157 ( struct V_12 * V_13 ,
struct V_3 * V_4 , int V_197 ,
enum V_198 V_199 ,
bool V_200 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_201 * V_202 ;
struct V_156 * V_157 ;
int V_87 = sizeof( * V_202 ) ;
T_7 V_203 ;
bool V_204 = V_4 -> V_4 . V_205 ;
struct V_158 * V_159 ;
struct V_206 * V_207 ;
if ( V_204 ) {
V_203 = F_55 ( V_208 |
V_209 |
V_210 ) ;
} else {
V_87 -= 2 ;
V_203 = F_55 ( V_208 |
V_211 |
V_210 ) ;
}
V_157 = F_158 ( V_2 -> V_31 . V_212 + V_87 ) ;
if ( ! V_157 )
return;
F_159 ( V_157 , V_2 -> V_31 . V_212 ) ;
V_202 = ( void * ) F_160 ( V_157 , V_87 ) ;
V_202 -> V_213 = V_203 ;
V_202 -> V_214 = 0 ;
memcpy ( V_202 -> V_215 , V_4 -> V_4 . V_42 , V_73 ) ;
memcpy ( V_202 -> V_216 , V_13 -> V_19 . V_42 , V_73 ) ;
memcpy ( V_202 -> V_217 , V_13 -> V_19 . V_42 , V_73 ) ;
V_202 -> V_218 = 0 ;
V_157 -> V_219 = V_197 ;
F_161 ( V_157 , V_220 [ V_197 ] ) ;
if ( V_204 ) {
V_202 -> V_221 = F_55 ( V_197 ) ;
if ( V_199 == V_222 )
V_202 -> V_221 |=
F_55 ( V_223 ) ;
}
V_159 = F_96 ( V_157 ) ;
V_159 -> V_167 |= V_224 |
V_225 |
V_226 ;
V_159 -> V_166 . V_167 |= V_227 ;
if ( V_200 )
F_162 ( V_2 , V_4 , F_87 ( V_197 ) , 1 ,
V_199 , false ) ;
V_157 -> V_133 = V_13 -> V_133 ;
F_20 () ;
V_207 = F_163 ( V_13 -> V_19 . V_207 ) ;
if ( F_57 ( ! V_207 ) ) {
F_23 () ;
F_164 ( V_157 ) ;
return;
}
V_159 -> V_228 = V_207 -> V_229 . V_230 -> V_228 ;
F_165 ( V_13 , V_4 , V_157 ) ;
F_23 () ;
}
static int F_166 ( unsigned long V_149 )
{
if ( V_149 & 0xF8 )
return F_167 ( V_149 ) - 1 ;
if ( V_149 & F_87 ( 0 ) )
return 0 ;
return F_167 ( V_149 ) - 1 ;
}
static void
F_168 ( struct V_3 * V_4 ,
int V_231 , T_1 V_232 ,
enum V_198 V_199 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
bool V_233 = false ;
int V_8 ;
unsigned long V_234 = 0 ;
struct V_188 V_235 ;
F_69 ( V_4 , V_192 ) ;
F_169 ( & V_235 ) ;
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ ) {
unsigned long V_149 ;
if ( V_232 & F_87 ( V_8 ) )
continue;
V_149 = F_86 ( V_8 ) ;
if ( F_90 ( & V_235 ) ) {
V_234 |= V_4 -> V_150 & V_149 ;
V_234 |= V_4 -> V_151 & V_149 ;
}
if ( V_234 ) {
if ( V_199 == V_236 &&
F_170 ( V_234 ) > 1 ) {
V_233 = true ;
V_234 =
F_87 ( F_166 (
V_234 ) ) ;
break;
}
} else {
struct V_156 * V_157 ;
while ( V_231 > 0 ) {
V_157 = F_171 ( & V_4 -> V_36 [ V_8 ] ) ;
if ( ! V_157 ) {
V_157 = F_171 (
& V_4 -> V_35 [ V_8 ] ) ;
if ( V_157 )
V_2 -> V_34 -- ;
}
if ( ! V_157 )
break;
V_231 -- ;
F_172 ( & V_235 , V_157 ) ;
}
}
if ( ! F_90 ( & V_4 -> V_36 [ V_8 ] ) ||
! F_90 ( & V_4 -> V_35 [ V_8 ] ) ) {
V_233 = true ;
break;
}
}
if ( F_90 ( & V_235 ) && ! V_234 ) {
int V_197 ;
V_197 = 7 - ( ( F_173 ( ~ V_232 ) - 1 ) << 1 ) ;
F_157 ( V_13 , V_4 , V_197 , V_199 , true ) ;
} else if ( ! V_234 ) {
struct V_188 V_41 ;
struct V_156 * V_157 ;
int V_237 = 0 ;
T_4 V_149 = 0 ;
bool V_238 = false ;
F_54 ( & V_41 ) ;
while ( ( V_157 = F_101 ( & V_235 ) ) ) {
struct V_158 * V_159 = F_96 ( V_157 ) ;
struct V_239 * V_240 = ( void * ) V_157 -> V_174 ;
T_1 * V_241 = NULL ;
V_237 ++ ;
V_159 -> V_167 |= V_224 ;
V_159 -> V_166 . V_167 |= V_227 ;
if ( V_233 || ! F_90 ( & V_235 ) )
V_240 -> V_213 |=
F_55 ( V_242 ) ;
else
V_240 -> V_213 &=
F_55 ( ~ V_242 ) ;
if ( F_174 ( V_240 -> V_213 ) ||
F_175 ( V_240 -> V_213 ) )
V_241 = F_176 ( V_240 ) ;
V_149 |= F_87 ( V_157 -> V_219 ) ;
F_172 ( & V_41 , V_157 ) ;
if ( ! F_90 ( & V_235 ) )
continue;
if ( V_199 != V_222 ) {
V_159 -> V_167 |= V_225 |
V_226 ;
break;
}
if ( V_241 ) {
* V_241 |= V_223 ;
V_159 -> V_167 |= V_225 |
V_226 ;
} else {
V_240 -> V_213 |=
F_55 ( V_242 ) ;
V_238 = true ;
V_237 ++ ;
}
break;
}
F_162 ( V_2 , V_4 , V_149 , V_237 ,
V_199 , V_233 ) ;
F_150 ( V_2 , & V_41 ) ;
if ( V_238 )
F_157 (
V_13 , V_4 , F_166 ( V_149 ) ,
V_199 , false ) ;
F_94 ( V_4 ) ;
} else {
unsigned long V_149 = V_4 -> V_151 & V_234 ;
int V_197 ;
F_177 ( V_2 , V_4 , V_234 ,
V_231 , V_199 , V_233 ) ;
if ( ! V_4 -> V_4 . V_26 [ 0 ] )
return;
for ( V_197 = 0 ; V_197 < F_8 ( V_4 -> V_4 . V_26 ) ; V_197 ++ ) {
struct V_27 * V_28 = F_9 ( V_4 -> V_4 . V_26 [ V_197 ] ) ;
if ( ! ( V_149 & F_87 ( V_197 ) ) || F_10 ( & V_28 -> V_30 ) )
continue;
F_94 ( V_4 ) ;
break;
}
}
}
void F_37 ( struct V_3 * V_4 )
{
T_1 V_243 = V_4 -> V_4 . V_145 ;
if ( V_243 == F_87 ( V_33 ) - 1 )
V_243 = 0 ;
F_168 ( V_4 , 1 , V_243 ,
V_236 ) ;
}
void F_38 ( struct V_3 * V_4 )
{
int V_231 = V_4 -> V_4 . V_244 ;
T_1 V_245 = V_4 -> V_4 . V_145 ;
if ( ! V_245 )
return;
switch ( V_4 -> V_4 . V_244 ) {
case 1 :
V_231 = 2 ;
break;
case 2 :
V_231 = 4 ;
break;
case 3 :
V_231 = 6 ;
break;
case 0 :
V_231 = 128 ;
break;
}
F_168 ( V_4 , V_231 , ~ V_245 ,
V_222 ) ;
}
void F_178 ( struct V_59 * V_31 ,
struct V_185 * V_246 , bool V_247 )
{
struct V_3 * V_4 = F_33 ( V_246 , struct V_3 , V_4 ) ;
F_179 ( V_4 -> V_2 , V_246 , V_247 ) ;
if ( V_247 ) {
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
void F_182 ( struct V_185 * V_246 )
{
struct V_3 * V_4 = F_33 ( V_246 , struct V_3 , V_4 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_183 ( V_2 , V_246 ) ;
F_6 ( V_4 , V_192 ) ;
}
void F_184 ( struct V_185 * V_246 ,
T_1 V_197 , bool V_190 )
{
struct V_3 * V_4 = F_33 ( V_246 , struct V_3 , V_4 ) ;
if ( F_57 ( V_197 >= V_38 ) )
return;
F_185 ( V_4 -> V_2 , V_246 , V_197 , V_190 ) ;
if ( V_190 )
F_186 ( V_197 , & V_4 -> V_150 ) ;
else
F_187 ( V_197 , & V_4 -> V_150 ) ;
F_94 ( V_4 ) ;
}
int F_114 ( struct V_3 * V_4 ,
enum V_112 V_248 )
{
F_80 () ;
if ( V_4 -> V_76 == V_248 )
return 0 ;
switch ( V_248 ) {
case V_77 :
if ( V_4 -> V_76 != V_249 )
return - V_111 ;
break;
case V_249 :
if ( V_4 -> V_76 != V_77 &&
V_4 -> V_76 != V_250 )
return - V_111 ;
break;
case V_250 :
if ( V_4 -> V_76 != V_249 &&
V_4 -> V_76 != V_251 )
return - V_111 ;
break;
case V_251 :
if ( V_4 -> V_76 != V_250 )
return - V_111 ;
break;
default:
F_188 ( 1 , L_10 , V_248 ) ;
return - V_111 ;
}
F_28 ( V_4 -> V_13 , L_11 ,
V_4 -> V_4 . V_42 , V_248 ) ;
if ( F_4 ( V_4 , V_130 ) ) {
int V_114 = F_64 ( V_4 -> V_2 , V_4 -> V_13 , V_4 ,
V_4 -> V_76 , V_248 ) ;
if ( V_114 )
return V_114 ;
}
switch ( V_248 ) {
case V_77 :
if ( V_4 -> V_76 == V_249 )
F_187 ( V_252 , & V_4 -> V_253 ) ;
break;
case V_249 :
if ( V_4 -> V_76 == V_77 )
F_186 ( V_252 , & V_4 -> V_253 ) ;
else if ( V_4 -> V_76 == V_250 )
F_187 ( V_254 , & V_4 -> V_253 ) ;
break;
case V_250 :
if ( V_4 -> V_76 == V_249 ) {
F_186 ( V_254 , & V_4 -> V_253 ) ;
} else if ( V_4 -> V_76 == V_251 ) {
if ( V_4 -> V_13 -> V_19 . type == V_20 ||
( V_4 -> V_13 -> V_19 . type == V_21 &&
! V_4 -> V_13 -> V_23 . V_173 . V_4 ) )
F_7 ( & V_4 -> V_13 -> V_22 -> V_255 ) ;
F_187 ( V_256 , & V_4 -> V_253 ) ;
F_180 ( V_4 ) ;
}
break;
case V_251 :
if ( V_4 -> V_76 == V_250 ) {
if ( V_4 -> V_13 -> V_19 . type == V_20 ||
( V_4 -> V_13 -> V_19 . type == V_21 &&
! V_4 -> V_13 -> V_23 . V_173 . V_4 ) )
F_189 ( & V_4 -> V_13 -> V_22 -> V_255 ) ;
F_186 ( V_256 , & V_4 -> V_253 ) ;
F_156 ( V_4 ) ;
}
break;
default:
break;
}
V_4 -> V_76 = V_248 ;
return 0 ;
}
T_1 F_153 ( struct V_3 * V_4 )
{
struct V_257 * V_100 = & V_4 -> V_4 . V_100 ;
T_1 V_258 ;
if ( ! V_4 -> V_4 . V_100 . V_259 )
return 1 ;
if ( V_4 -> V_4 . V_260 . V_261 ) {
int V_9 ;
T_4 V_262 =
F_190 ( V_4 -> V_4 . V_260 . V_263 . V_262 ) ;
for ( V_9 = 7 ; V_9 >= 0 ; V_9 -- )
if ( ( V_262 & ( 0x3 << ( V_9 * 2 ) ) ) !=
V_264 )
return V_9 + 1 ;
}
if ( V_100 -> V_265 . V_266 [ 3 ] )
V_258 = 4 ;
else if ( V_100 -> V_265 . V_266 [ 2 ] )
V_258 = 3 ;
else if ( V_100 -> V_265 . V_266 [ 1 ] )
V_258 = 2 ;
else
V_258 = 1 ;
if ( ! ( V_100 -> V_265 . V_267 & V_268 ) )
return V_258 ;
return ( ( V_100 -> V_265 . V_267 & V_269 )
>> V_270 ) + 1 ;
}
void F_115 ( struct V_3 * V_4 , struct V_119 * V_120 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_271 * V_272 = NULL ;
struct V_60 V_61 ;
T_6 V_273 = 0 ;
int V_9 , V_8 ;
if ( F_4 ( V_4 , V_274 ) )
V_272 = V_2 -> V_48 ;
V_120 -> V_132 = V_13 -> V_2 -> V_125 ;
if ( V_13 -> V_19 . type == V_275 )
V_120 -> V_276 = V_13 -> V_23 . V_277 . V_278 ;
F_191 ( V_2 , V_13 , & V_4 -> V_4 , V_120 ) ;
V_120 -> V_131 |= F_87 ( V_279 ) |
F_87 ( V_280 ) |
F_87 ( V_281 ) |
F_87 ( V_282 ) |
F_87 ( V_283 ) |
F_87 ( V_284 ) ;
F_49 ( & V_61 ) ;
V_120 -> V_285 = V_61 . V_81 - V_4 -> V_80 ;
V_120 -> V_286 = F_192 ( V_75 - V_4 -> V_74 ) ;
if ( ! ( V_120 -> V_131 & ( F_87 ( V_287 ) |
F_87 ( V_288 ) ) ) ) {
V_120 -> V_289 = 0 ;
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ )
V_120 -> V_289 += V_4 -> V_289 [ V_8 ] ;
V_120 -> V_131 |= F_87 ( V_287 ) ;
}
if ( ! ( V_120 -> V_131 & F_87 ( V_290 ) ) ) {
V_120 -> V_291 = 0 ;
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ )
V_120 -> V_291 += V_4 -> V_291 [ V_8 ] ;
V_120 -> V_131 |= F_87 ( V_290 ) ;
}
if ( ! ( V_120 -> V_131 & ( F_87 ( V_292 ) |
F_87 ( V_293 ) ) ) ) {
V_120 -> V_294 = V_4 -> V_294 ;
V_120 -> V_131 |= F_87 ( V_292 ) ;
}
if ( ! ( V_120 -> V_131 & F_87 ( V_295 ) ) ) {
V_120 -> V_296 = V_4 -> V_296 ;
V_120 -> V_131 |= F_87 ( V_295 ) ;
}
if ( ! ( V_120 -> V_131 & F_87 ( V_297 ) ) ) {
V_120 -> V_298 = V_4 -> V_299 ;
V_120 -> V_131 |= F_87 ( V_297 ) ;
}
if ( ! ( V_120 -> V_131 & F_87 ( V_300 ) ) ) {
V_120 -> V_301 = V_4 -> V_302 ;
V_120 -> V_131 |= F_87 ( V_300 ) ;
}
V_120 -> V_303 = V_4 -> V_304 ;
V_120 -> V_305 = V_4 -> V_305 ;
if ( V_13 -> V_19 . type == V_275 &&
! ( V_13 -> V_19 . V_306 & V_307 ) ) {
V_120 -> V_131 |= F_87 ( V_308 ) |
F_87 ( V_309 ) ;
V_120 -> V_310 = F_193 ( & V_13 -> V_19 ) ;
}
if ( F_41 ( & V_4 -> V_2 -> V_31 , V_311 ) ||
F_41 ( & V_4 -> V_2 -> V_31 , V_312 ) ) {
if ( ! ( V_120 -> V_131 & F_87 ( V_313 ) ) ) {
V_120 -> signal = ( V_314 ) V_4 -> V_315 ;
V_120 -> V_131 |= F_87 ( V_313 ) ;
}
if ( ! ( V_120 -> V_131 & F_87 ( V_316 ) ) ) {
V_120 -> V_317 =
( V_314 ) - F_194 ( & V_4 -> V_82 ) ;
V_120 -> V_131 |= F_87 ( V_316 ) ;
}
}
if ( V_4 -> V_318 &&
! ( V_120 -> V_131 & ( F_87 ( V_319 ) |
F_87 ( V_320 ) ) ) ) {
V_120 -> V_131 |= F_87 ( V_319 ) |
F_87 ( V_320 ) ;
V_120 -> V_318 = V_4 -> V_318 ;
for ( V_9 = 0 ; V_9 < F_8 ( V_120 -> V_321 ) ; V_9 ++ ) {
V_120 -> V_321 [ V_9 ] = V_4 -> V_322 [ V_9 ] ;
V_120 -> V_83 [ V_9 ] =
( V_314 ) - F_194 ( & V_4 -> V_83 [ V_9 ] ) ;
}
}
if ( ! ( V_120 -> V_131 & F_87 ( V_323 ) ) ) {
F_195 ( V_4 , & V_4 -> V_324 , & V_120 -> V_325 ) ;
V_120 -> V_131 |= F_87 ( V_323 ) ;
}
if ( ! ( V_120 -> V_131 & F_87 ( V_326 ) ) ) {
F_196 ( V_4 , & V_120 -> V_327 ) ;
V_120 -> V_131 |= F_87 ( V_326 ) ;
}
V_120 -> V_131 |= F_87 ( V_328 ) ;
for ( V_9 = 0 ; V_9 < V_38 + 1 ; V_9 ++ ) {
struct V_329 * V_330 = & V_120 -> V_331 [ V_9 ] ;
if ( ! ( V_330 -> V_131 & F_87 ( V_332 ) ) ) {
V_330 -> V_131 |= F_87 ( V_332 ) ;
V_330 -> V_333 = V_4 -> V_333 [ V_9 ] ;
}
if ( ! ( V_330 -> V_131 & F_87 ( V_334 ) ) ) {
V_330 -> V_131 |= F_87 ( V_334 ) ;
V_330 -> V_335 = V_4 -> V_335 [ V_9 ] ;
}
if ( ! ( V_330 -> V_131 &
F_87 ( V_336 ) ) &&
F_41 ( & V_2 -> V_31 , V_337 ) ) {
V_330 -> V_131 |=
F_87 ( V_336 ) ;
V_330 -> V_338 = V_4 -> V_338 [ V_9 ] ;
}
if ( ! ( V_330 -> V_131 &
F_87 ( V_339 ) ) &&
F_41 ( & V_2 -> V_31 , V_337 ) ) {
V_330 -> V_131 |=
F_87 ( V_339 ) ;
V_330 -> V_340 = V_4 -> V_340 [ V_9 ] ;
}
}
if ( F_5 ( & V_13 -> V_19 ) ) {
#ifdef F_29
V_120 -> V_131 |= F_87 ( V_341 ) |
F_87 ( V_342 ) |
F_87 ( V_343 ) |
F_87 ( V_344 ) |
F_87 ( V_345 ) |
F_87 ( V_346 ) ;
V_120 -> V_347 = V_4 -> V_24 -> V_347 ;
V_120 -> V_348 = V_4 -> V_24 -> V_348 ;
V_120 -> V_349 = V_4 -> V_24 -> V_349 ;
if ( F_4 ( V_4 , V_350 ) ) {
V_120 -> V_131 |= F_87 ( V_351 ) ;
V_120 -> V_352 = V_4 -> V_24 -> V_352 ;
}
V_120 -> V_353 = V_4 -> V_24 -> V_353 ;
V_120 -> V_354 = V_4 -> V_24 -> V_354 ;
V_120 -> V_71 = V_4 -> V_24 -> V_71 ;
#endif
}
V_120 -> V_355 . V_167 = 0 ;
if ( V_13 -> V_19 . V_162 . V_356 )
V_120 -> V_355 . V_167 |= V_357 ;
if ( V_13 -> V_19 . V_162 . V_358 )
V_120 -> V_355 . V_167 |= V_359 ;
if ( V_13 -> V_19 . V_162 . V_360 )
V_120 -> V_355 . V_167 |= V_361 ;
V_120 -> V_355 . V_362 = V_13 -> V_19 . V_162 . V_362 ;
V_120 -> V_355 . V_363 = V_13 -> V_19 . V_162 . V_163 ;
V_120 -> V_364 . V_365 = 0 ;
V_120 -> V_364 . V_366 = F_87 ( V_367 ) |
F_87 ( V_368 ) |
F_87 ( V_369 ) |
F_87 ( V_370 ) |
F_87 ( V_371 ) |
F_87 ( V_372 ) |
F_87 ( V_373 ) ;
if ( F_4 ( V_4 , V_256 ) )
V_120 -> V_364 . V_365 |= F_87 ( V_367 ) ;
if ( F_4 ( V_4 , V_374 ) )
V_120 -> V_364 . V_365 |= F_87 ( V_368 ) ;
if ( V_4 -> V_4 . V_205 )
V_120 -> V_364 . V_365 |= F_87 ( V_369 ) ;
if ( F_4 ( V_4 , V_375 ) )
V_120 -> V_364 . V_365 |= F_87 ( V_370 ) ;
if ( F_4 ( V_4 , V_252 ) )
V_120 -> V_364 . V_365 |= F_87 ( V_371 ) ;
if ( F_4 ( V_4 , V_254 ) )
V_120 -> V_364 . V_365 |= F_87 ( V_372 ) ;
if ( F_4 ( V_4 , V_376 ) )
V_120 -> V_364 . V_365 |= F_87 ( V_373 ) ;
if ( V_272 && V_272 -> V_84 -> V_377 )
V_273 = V_272 -> V_84 -> V_377 ( V_4 -> V_57 ) ;
else
V_273 = F_197 ( V_2 , & V_4 -> V_4 ) ;
if ( V_273 != 0 ) {
V_120 -> V_131 |= F_87 ( V_378 ) ;
V_120 -> V_379 = V_273 ;
}
}
