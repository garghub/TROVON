static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_3 * V_5 ;
V_5 = F_2 ( V_2 -> V_6 [ F_3 ( V_4 -> V_4 . V_7 ) ] ,
F_4 ( & V_2 -> V_8 ) ) ;
if ( ! V_5 )
return - V_9 ;
if ( V_5 == V_4 ) {
F_5 ( V_2 -> V_6 [ F_3 ( V_4 -> V_4 . V_7 ) ] ,
V_5 -> V_10 ) ;
return 0 ;
}
while ( F_6 ( V_5 -> V_10 ) &&
F_6 ( V_5 -> V_10 ) != V_4 )
V_5 = F_2 ( V_5 -> V_10 ,
F_4 ( & V_2 -> V_8 ) ) ;
if ( F_6 ( V_5 -> V_10 ) ) {
F_5 ( V_5 -> V_10 , V_4 -> V_10 ) ;
return 0 ;
}
return - V_9 ;
}
static void F_7 ( struct V_3 * V_4 )
{
int V_11 , V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_17 * V_18 ;
if ( F_8 ( V_4 , V_19 ) ||
F_8 ( V_4 , V_20 ) ||
F_8 ( V_4 , V_21 ) ) {
if ( V_4 -> V_16 -> V_22 . type == V_23 ||
V_4 -> V_16 -> V_22 . type == V_24 )
V_18 = & V_16 -> V_25 -> V_18 ;
else if ( F_9 ( & V_16 -> V_22 ) )
V_18 = & V_16 -> V_26 . V_27 . V_18 ;
else
return;
F_10 ( V_4 , V_19 ) ;
F_10 ( V_4 , V_20 ) ;
F_10 ( V_4 , V_21 ) ;
F_11 ( & V_18 -> V_28 ) ;
F_12 ( V_4 ) ;
}
for ( V_11 = 0 ; V_11 < V_29 ; V_11 ++ ) {
V_2 -> V_30 -= F_13 ( & V_4 -> V_31 [ V_11 ] ) ;
F_14 ( & V_2 -> V_32 , & V_4 -> V_31 [ V_11 ] ) ;
F_14 ( & V_2 -> V_32 , & V_4 -> V_33 [ V_11 ] ) ;
}
if ( F_9 ( & V_16 -> V_22 ) )
F_15 ( V_4 ) ;
F_16 ( & V_4 -> V_34 ) ;
for ( V_12 = 0 ; V_12 < V_35 ; V_12 ++ ) {
F_17 ( V_4 -> V_36 . V_37 [ V_12 ] ) ;
V_14 = F_18 ( V_4 -> V_36 . V_14 [ V_12 ] ) ;
if ( ! V_14 )
continue;
F_14 ( & V_2 -> V_32 , & V_14 -> V_38 ) ;
F_17 ( V_14 ) ;
}
}
static void F_19 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_2 ;
F_7 ( V_4 ) ;
F_20 ( V_2 , V_4 ) ;
}
struct V_3 * F_21 ( struct V_15 * V_16 ,
const T_1 * V_7 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 ;
V_4 = F_22 ( V_2 -> V_6 [ F_3 ( V_7 ) ] ,
F_4 ( & V_2 -> V_8 ) ) ;
while ( V_4 ) {
if ( V_4 -> V_16 == V_16 &&
F_23 ( V_4 -> V_4 . V_7 , V_7 ) )
break;
V_4 = F_22 ( V_4 -> V_10 ,
F_4 ( & V_2 -> V_8 ) ) ;
}
return V_4 ;
}
struct V_3 * F_24 ( struct V_15 * V_16 ,
const T_1 * V_7 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 ;
V_4 = F_22 ( V_2 -> V_6 [ F_3 ( V_7 ) ] ,
F_4 ( & V_2 -> V_8 ) ) ;
while ( V_4 ) {
if ( ( V_4 -> V_16 == V_16 ||
( V_4 -> V_16 -> V_25 && V_4 -> V_16 -> V_25 == V_16 -> V_25 ) ) &&
F_23 ( V_4 -> V_4 . V_7 , V_7 ) )
break;
V_4 = F_22 ( V_4 -> V_10 ,
F_4 ( & V_2 -> V_8 ) ) ;
}
return V_4 ;
}
struct V_3 * F_25 ( struct V_15 * V_16 ,
int V_39 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 ;
int V_12 = 0 ;
F_26 (sta, &local->sta_list, list) {
if ( V_16 != V_4 -> V_16 )
continue;
if ( V_12 < V_39 ) {
++ V_12 ;
continue;
}
return V_4 ;
}
return NULL ;
}
void F_20 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_12 ;
if ( V_4 -> V_40 )
F_27 ( V_4 ) ;
if ( V_4 -> V_41 ) {
for ( V_12 = 0 ; V_12 < V_35 ; V_12 ++ )
F_17 ( V_4 -> V_41 [ V_12 ] . V_42 ) ;
F_17 ( V_4 -> V_41 ) ;
}
F_28 ( V_4 -> V_16 , L_1 , V_4 -> V_4 . V_7 ) ;
F_17 ( F_18 ( V_4 -> V_4 . V_43 ) ) ;
F_17 ( V_4 ) ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_30 ( & V_2 -> V_8 ) ;
V_4 -> V_10 = V_2 -> V_6 [ F_3 ( V_4 -> V_4 . V_7 ) ] ;
F_5 ( V_2 -> V_6 [ F_3 ( V_4 -> V_4 . V_7 ) ] , V_4 ) ;
}
static void F_31 ( struct V_44 * V_45 )
{
struct V_3 * V_4 ;
V_4 = F_32 ( V_45 , struct V_3 , V_34 ) ;
if ( V_4 -> V_46 )
return;
F_33 () ;
if ( ! F_8 ( V_4 , V_19 ) )
F_34 ( V_4 ) ;
else if ( F_35 ( V_4 , V_47 ) )
F_36 ( V_4 ) ;
else if ( F_35 ( V_4 , V_48 ) )
F_37 ( V_4 ) ;
F_38 () ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 V_49 )
{
if ( V_2 -> V_32 . V_50 & V_51 )
return 0 ;
V_4 -> V_40 = V_2 -> V_40 ;
V_4 -> V_52 = F_40 ( V_4 -> V_40 ,
& V_4 -> V_4 , V_49 ) ;
if ( ! V_4 -> V_52 )
return - V_53 ;
return 0 ;
}
struct V_3 * F_41 ( struct V_15 * V_16 ,
const T_1 * V_7 , T_2 V_49 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 ;
struct V_54 V_55 ;
struct V_56 * V_57 ;
int V_12 ;
V_4 = F_42 ( sizeof( * V_4 ) + V_2 -> V_32 . V_58 , V_49 ) ;
if ( ! V_4 )
return NULL ;
F_43 () ;
V_57 = F_44 ( V_2 -> V_57 ) ;
if ( V_57 ) {
V_4 -> V_41 = F_42 ( V_35 *
sizeof( struct V_59 ) ,
V_60 ) ;
if ( ! V_4 -> V_41 ) {
F_45 () ;
goto free;
}
if ( V_57 -> V_61 ) {
for ( V_12 = 0 ; V_12 < V_35 ; V_12 ++ ) {
V_4 -> V_41 [ V_12 ] . V_62 =
V_57 -> V_61 + 1 ;
V_4 -> V_41 [ V_12 ] . V_42 =
F_46 ( V_4 -> V_41 [ V_12 ] . V_62 ,
sizeof( V_63 ) , V_60 ) ;
if ( ! V_4 -> V_41 [ V_12 ] . V_42 ) {
F_45 () ;
goto free;
}
}
}
}
F_45 () ;
F_47 ( & V_4 -> V_64 ) ;
F_47 ( & V_4 -> V_65 ) ;
F_48 ( & V_4 -> V_34 , F_31 ) ;
F_48 ( & V_4 -> V_36 . V_66 , V_67 ) ;
F_49 ( & V_4 -> V_36 . V_68 ) ;
#ifdef F_50
if ( F_9 ( & V_16 -> V_22 ) &&
! V_16 -> V_26 . V_27 . V_69 )
F_51 ( & V_4 -> V_70 ) ;
V_4 -> V_71 = V_72 ;
#endif
memcpy ( V_4 -> V_4 . V_7 , V_7 , V_73 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_16 = V_16 ;
V_4 -> V_74 = V_75 ;
V_4 -> V_76 = V_77 ;
V_4 -> V_78 = V_79 ;
F_52 ( & V_55 ) ;
V_4 -> V_80 = V_55 . V_81 ;
F_53 ( & V_4 -> V_82 , 1024 , 8 ) ;
for ( V_12 = 0 ; V_12 < F_54 ( V_4 -> V_83 ) ; V_12 ++ )
F_53 ( & V_4 -> V_83 [ V_12 ] , 1024 , 8 ) ;
if ( F_39 ( V_2 , V_4 , V_49 ) )
goto free;
for ( V_12 = 0 ; V_12 < V_35 ; V_12 ++ ) {
V_4 -> V_84 [ V_12 ] = V_12 ;
}
for ( V_12 = 0 ; V_12 < V_29 ; V_12 ++ ) {
F_55 ( & V_4 -> V_31 [ V_12 ] ) ;
F_55 ( & V_4 -> V_33 [ V_12 ] ) ;
}
for ( V_12 = 0 ; V_12 < V_35 ; V_12 ++ )
V_4 -> V_85 [ V_12 ] = F_56 ( V_86 ) ;
V_4 -> V_4 . V_87 = V_88 ;
if ( V_16 -> V_22 . type == V_23 ||
V_16 -> V_22 . type == V_24 ) {
struct V_89 * V_90 =
V_2 -> V_32 . V_91 -> V_92 [ F_57 ( V_16 ) ] ;
T_1 V_93 = ( V_90 -> V_94 . V_95 & V_96 ) >>
V_97 ;
switch ( V_93 ) {
case V_98 :
V_4 -> V_99 = V_88 ;
break;
case V_100 :
V_4 -> V_99 = V_101 ;
break;
case V_102 :
V_4 -> V_99 = V_103 ;
break;
default:
F_58 ( 1 ) ;
}
}
F_28 ( V_16 , L_2 , V_4 -> V_4 . V_7 ) ;
return V_4 ;
free:
if ( V_4 -> V_41 ) {
for ( V_12 = 0 ; V_12 < V_35 ; V_12 ++ )
F_17 ( V_4 -> V_41 [ V_12 ] . V_42 ) ;
F_17 ( V_4 -> V_41 ) ;
}
F_17 ( V_4 ) ;
return NULL ;
}
static int F_59 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
if ( F_60 ( ! F_61 ( V_16 ) ) )
return - V_104 ;
if ( F_58 ( F_23 ( V_4 -> V_4 . V_7 , V_16 -> V_22 . V_7 ) ||
F_62 ( V_4 -> V_4 . V_7 ) ) )
return - V_105 ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_3 * V_4 )
{
enum V_106 V_107 ;
int V_108 = 0 ;
for ( V_107 = V_109 ; V_107 < V_4 -> V_76 ; V_107 ++ ) {
V_108 = F_64 ( V_2 , V_16 , V_4 , V_107 , V_107 + 1 ) ;
if ( V_108 )
break;
}
if ( ! V_108 ) {
if ( ! V_2 -> V_110 -> V_111 )
V_4 -> V_112 = true ;
return 0 ;
}
if ( V_16 -> V_22 . type == V_113 ) {
F_65 ( V_16 ,
L_3 ,
V_4 -> V_4 . V_7 , V_107 + 1 , V_108 ) ;
V_108 = 0 ;
}
for (; V_107 > V_109 ; V_107 -- )
F_58 ( F_64 ( V_2 , V_16 , V_4 , V_107 , V_107 - 1 ) ) ;
return V_108 ;
}
static int F_66 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_114 V_115 ;
int V_108 = 0 ;
F_30 ( & V_2 -> V_8 ) ;
if ( F_24 ( V_16 , V_4 -> V_4 . V_7 ) ) {
V_108 = - V_116 ;
goto V_117;
}
V_2 -> V_118 ++ ;
V_2 -> V_119 ++ ;
F_67 () ;
F_68 ( V_4 , V_120 ) ;
F_29 ( V_2 , V_4 ) ;
F_69 ( & V_4 -> V_121 , & V_2 -> V_122 ) ;
V_108 = F_63 ( V_2 , V_16 , V_4 ) ;
if ( V_108 )
goto V_123;
F_68 ( V_4 , V_124 ) ;
F_10 ( V_4 , V_120 ) ;
F_70 ( V_16 ) ;
F_71 ( V_4 ) ;
F_72 ( V_4 ) ;
memset ( & V_115 , 0 , sizeof( V_115 ) ) ;
V_115 . V_125 = 0 ;
V_115 . V_126 = V_2 -> V_119 ;
F_73 ( V_16 -> V_127 , V_4 -> V_4 . V_7 , & V_115 , V_128 ) ;
F_28 ( V_16 , L_4 , V_4 -> V_4 . V_7 ) ;
F_43 () ;
F_74 ( & V_2 -> V_8 ) ;
if ( F_9 ( & V_16 -> V_22 ) )
F_75 ( V_16 ) ;
return 0 ;
V_123:
F_1 ( V_2 , V_4 ) ;
F_76 ( & V_4 -> V_121 ) ;
V_2 -> V_118 -- ;
F_77 () ;
F_7 ( V_4 ) ;
V_117:
F_74 ( & V_2 -> V_8 ) ;
F_43 () ;
return V_108 ;
}
int F_78 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_108 ;
F_79 () ;
V_108 = F_59 ( V_4 ) ;
if ( V_108 ) {
F_43 () ;
goto V_129;
}
F_80 ( & V_2 -> V_8 ) ;
V_108 = F_66 ( V_4 ) ;
if ( V_108 )
goto V_129;
return 0 ;
V_129:
F_20 ( V_2 , V_4 ) ;
return V_108 ;
}
int F_81 ( struct V_3 * V_4 )
{
int V_108 = F_78 ( V_4 ) ;
F_45 () ;
return V_108 ;
}
static inline void F_82 ( T_1 * V_130 , T_4 V_131 )
{
V_130 [ V_131 / 8 ] |= ( 1 << ( V_131 % 8 ) ) ;
}
static inline void F_83 ( T_1 * V_130 , T_4 V_131 )
{
V_130 [ V_131 / 8 ] &= ~ ( 1 << ( V_131 % 8 ) ) ;
}
static inline bool F_84 ( T_1 * V_130 , T_4 V_131 )
{
return V_130 [ V_131 / 8 ] & ( 1 << ( V_131 % 8 ) ) ;
}
static unsigned long F_85 ( int V_11 )
{
switch ( V_11 ) {
case V_132 :
return F_86 ( 6 ) | F_86 ( 7 ) ;
case V_133 :
return F_86 ( 4 ) | F_86 ( 5 ) ;
case V_134 :
return F_86 ( 0 ) | F_86 ( 3 ) ;
case V_135 :
return F_86 ( 1 ) | F_86 ( 2 ) ;
default:
F_58 ( 1 ) ;
return 0 ;
}
}
void F_12 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_17 * V_18 ;
bool V_136 = false ;
T_1 V_137 = V_4 -> V_4 . V_138 ;
int V_11 ;
T_4 V_131 ;
if ( V_4 -> V_16 -> V_22 . type == V_23 ||
V_4 -> V_16 -> V_22 . type == V_24 ) {
if ( F_87 ( ! V_4 -> V_16 -> V_25 ) )
return;
V_18 = & V_4 -> V_16 -> V_25 -> V_18 ;
V_131 = V_4 -> V_4 . V_139 ;
#ifdef F_50
} else if ( F_9 ( & V_4 -> V_16 -> V_22 ) ) {
V_18 = & V_4 -> V_16 -> V_26 . V_27 . V_18 ;
V_131 = V_4 -> V_140 % ( V_141 + 1 ) ;
#endif
} else {
return;
}
if ( V_2 -> V_32 . V_50 & V_142 )
return;
if ( V_4 -> V_46 )
goto V_143;
if ( V_137 == F_86 ( V_29 ) - 1 )
V_137 = 0 ;
for ( V_11 = 0 ; V_11 < V_29 ; V_11 ++ ) {
unsigned long V_144 ;
if ( V_137 & F_86 ( V_11 ) )
continue;
V_136 |= ! F_88 ( & V_4 -> V_33 [ V_11 ] ) ||
! F_88 ( & V_4 -> V_31 [ V_11 ] ) ;
if ( V_136 )
break;
V_144 = F_85 ( V_11 ) ;
V_136 |=
V_4 -> V_145 & V_144 ;
}
V_143:
F_89 ( & V_2 -> V_146 ) ;
if ( V_136 == F_84 ( V_18 -> V_130 , V_131 ) )
goto V_147;
if ( V_136 )
F_82 ( V_18 -> V_130 , V_131 ) ;
else
F_83 ( V_18 -> V_130 , V_131 ) ;
if ( V_2 -> V_110 -> V_148 ) {
V_2 -> V_149 = true ;
F_90 ( V_2 , & V_4 -> V_4 , V_136 ) ;
V_2 -> V_149 = false ;
}
V_147:
F_91 ( & V_2 -> V_146 ) ;
}
static bool F_92 ( struct V_3 * V_4 , struct V_150 * V_151 )
{
struct V_152 * V_153 ;
int V_154 ;
if ( ! V_151 )
return false ;
V_153 = F_93 ( V_151 ) ;
V_154 = ( V_4 -> V_155 *
V_4 -> V_16 -> V_22 . V_156 . V_157 *
32 / 15625 ) * V_158 ;
if ( V_154 < V_159 )
V_154 = V_159 ;
return F_94 ( V_75 , V_153 -> V_160 . V_75 + V_154 ) ;
}
static bool F_95 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_11 )
{
unsigned long V_50 ;
struct V_150 * V_151 ;
for (; ; ) {
F_96 ( & V_4 -> V_33 [ V_11 ] . V_64 , V_50 ) ;
V_151 = F_97 ( & V_4 -> V_33 [ V_11 ] ) ;
if ( F_92 ( V_4 , V_151 ) )
V_151 = F_98 ( & V_4 -> V_33 [ V_11 ] ) ;
else
V_151 = NULL ;
F_99 ( & V_4 -> V_33 [ V_11 ] . V_64 , V_50 ) ;
if ( ! V_151 )
break;
F_100 ( & V_2 -> V_32 , V_151 ) ;
}
for (; ; ) {
F_96 ( & V_4 -> V_31 [ V_11 ] . V_64 , V_50 ) ;
V_151 = F_97 ( & V_4 -> V_31 [ V_11 ] ) ;
if ( F_92 ( V_4 , V_151 ) )
V_151 = F_98 ( & V_4 -> V_31 [ V_11 ] ) ;
else
V_151 = NULL ;
F_99 ( & V_4 -> V_31 [ V_11 ] . V_64 , V_50 ) ;
if ( ! V_151 )
break;
V_2 -> V_30 -- ;
F_101 ( V_4 -> V_16 , L_5 ,
V_4 -> V_4 . V_7 ) ;
F_100 ( & V_2 -> V_32 , V_151 ) ;
}
F_12 ( V_4 ) ;
return ! ( F_88 ( & V_4 -> V_31 [ V_11 ] ) &&
F_88 ( & V_4 -> V_33 [ V_11 ] ) ) ;
}
static bool F_102 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_161 = false ;
int V_11 ;
if ( ! V_4 -> V_16 -> V_25 &&
! F_9 ( & V_4 -> V_16 -> V_22 ) )
return false ;
for ( V_11 = 0 ; V_11 < V_29 ; V_11 ++ )
V_161 |=
F_95 ( V_2 , V_4 , V_11 ) ;
return V_161 ;
}
static int T_5 F_103 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_15 * V_16 ;
int V_162 ;
F_79 () ;
if ( ! V_4 )
return - V_9 ;
V_2 = V_4 -> V_2 ;
V_16 = V_4 -> V_16 ;
F_30 ( & V_2 -> V_8 ) ;
F_68 ( V_4 , V_120 ) ;
F_104 ( V_4 , V_163 ) ;
V_162 = F_1 ( V_2 , V_4 ) ;
if ( F_58 ( V_162 ) )
return V_162 ;
if ( F_8 ( V_4 , V_164 ) ) {
F_105 ( V_2 , V_16 , & V_4 -> V_4 ) ;
F_10 ( V_4 , V_164 ) ;
}
F_76 ( & V_4 -> V_121 ) ;
F_106 ( V_2 , V_4 -> V_16 , V_4 ) ;
if ( V_16 -> V_22 . type == V_24 &&
F_6 ( V_16 -> V_26 . V_165 . V_4 ) == V_4 )
F_107 ( V_16 -> V_26 . V_165 . V_4 , NULL ) ;
return 0 ;
}
static void F_108 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_15 * V_16 = V_4 -> V_16 ;
int V_162 ;
F_79 () ;
F_30 ( & V_2 -> V_8 ) ;
F_109 ( V_2 , V_4 ) ;
V_4 -> V_46 = true ;
V_2 -> V_118 -- ;
V_2 -> V_119 ++ ;
while ( V_4 -> V_76 > V_77 ) {
V_162 = F_110 ( V_4 , V_4 -> V_76 - 1 ) ;
if ( V_162 ) {
F_87 ( 1 ) ;
break;
}
}
if ( V_4 -> V_112 ) {
V_162 = F_64 ( V_2 , V_16 , V_4 , V_77 ,
V_109 ) ;
F_87 ( V_162 != 0 ) ;
}
F_28 ( V_16 , L_6 , V_4 -> V_4 . V_7 ) ;
F_111 ( V_16 -> V_127 , V_4 -> V_4 . V_7 , V_128 ) ;
F_112 ( V_4 ) ;
F_113 ( V_4 ) ;
F_70 ( V_16 ) ;
F_19 ( V_4 ) ;
}
int T_5 F_114 ( struct V_3 * V_4 )
{
int V_108 = F_103 ( V_4 ) ;
if ( V_108 )
return V_108 ;
F_77 () ;
F_108 ( V_4 ) ;
return 0 ;
}
int F_115 ( struct V_15 * V_16 , const T_1 * V_7 )
{
struct V_3 * V_4 ;
int V_162 ;
F_80 ( & V_16 -> V_2 -> V_8 ) ;
V_4 = F_21 ( V_16 , V_7 ) ;
V_162 = F_114 ( V_4 ) ;
F_74 ( & V_16 -> V_2 -> V_8 ) ;
return V_162 ;
}
int F_116 ( struct V_15 * V_16 ,
const T_1 * V_7 )
{
struct V_3 * V_4 ;
int V_162 ;
F_80 ( & V_16 -> V_2 -> V_8 ) ;
V_4 = F_24 ( V_16 , V_7 ) ;
V_162 = F_114 ( V_4 ) ;
F_74 ( & V_16 -> V_2 -> V_8 ) ;
return V_162 ;
}
static void F_117 ( unsigned long V_166 )
{
struct V_1 * V_2 = (struct V_1 * ) V_166 ;
struct V_3 * V_4 ;
bool V_167 = false ;
F_43 () ;
F_26 (sta, &local->sta_list, list)
if ( F_102 ( V_2 , V_4 ) )
V_167 = true ;
F_45 () ;
if ( V_2 -> V_168 )
return;
if ( ! V_167 )
return;
F_118 ( & V_2 -> V_169 ,
F_119 ( V_75 + V_170 ) ) ;
}
void F_120 ( struct V_1 * V_2 )
{
F_47 ( & V_2 -> V_146 ) ;
F_49 ( & V_2 -> V_8 ) ;
F_121 ( & V_2 -> V_122 ) ;
F_122 ( & V_2 -> V_169 , F_117 ,
( unsigned long ) V_2 ) ;
}
void F_123 ( struct V_1 * V_2 )
{
F_124 ( & V_2 -> V_169 ) ;
}
int F_125 ( struct V_15 * V_16 , bool V_171 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 , * V_172 ;
F_126 ( V_173 ) ;
int V_162 = 0 ;
F_79 () ;
F_58 ( V_171 && V_16 -> V_22 . type != V_23 ) ;
F_58 ( V_171 && ! V_16 -> V_25 ) ;
F_80 ( & V_2 -> V_8 ) ;
F_127 (sta, tmp, &local->sta_list, list) {
if ( V_16 == V_4 -> V_16 ||
( V_171 && V_16 -> V_25 == V_4 -> V_16 -> V_25 ) ) {
if ( ! F_58 ( F_103 ( V_4 ) ) )
F_128 ( & V_4 -> V_173 , & V_173 ) ;
V_162 ++ ;
}
}
if ( ! F_129 ( & V_173 ) ) {
F_77 () ;
F_127 (sta, tmp, &free_list, free_list)
F_108 ( V_4 ) ;
}
F_74 ( & V_2 -> V_8 ) ;
return V_162 ;
}
void F_130 ( struct V_15 * V_16 ,
unsigned long V_174 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 , * V_172 ;
F_80 ( & V_2 -> V_8 ) ;
F_127 (sta, tmp, &local->sta_list, list) {
if ( V_16 != V_4 -> V_16 )
continue;
if ( F_94 ( V_75 , V_4 -> V_74 + V_174 ) ) {
F_28 ( V_4 -> V_16 , L_7 ,
V_4 -> V_4 . V_7 ) ;
if ( F_9 ( & V_16 -> V_22 ) &&
F_8 ( V_4 , V_19 ) )
F_11 ( & V_16 -> V_26 . V_27 . V_18 . V_28 ) ;
F_58 ( F_114 ( V_4 ) ) ;
}
}
F_74 ( & V_2 -> V_8 ) ;
}
struct V_175 * F_131 ( struct V_176 * V_32 ,
const T_1 * V_7 ,
const T_1 * V_177 )
{
struct V_3 * V_4 , * V_178 ;
F_132 (hw_to_local(hw), addr, sta, nxt) {
if ( V_177 &&
! F_23 ( V_4 -> V_16 -> V_22 . V_7 , V_177 ) )
continue;
if ( ! V_4 -> V_112 )
return NULL ;
return & V_4 -> V_4 ;
}
return NULL ;
}
struct V_175 * F_133 ( struct V_179 * V_22 ,
const T_1 * V_7 )
{
struct V_3 * V_4 ;
if ( ! V_22 )
return NULL ;
V_4 = F_24 ( F_134 ( V_22 ) , V_7 ) ;
if ( ! V_4 )
return NULL ;
if ( ! V_4 -> V_112 )
return NULL ;
return & V_4 -> V_4 ;
}
void F_34 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_180 V_38 ;
int V_181 = 0 , V_182 = 0 , V_11 ;
unsigned long V_50 ;
struct V_17 * V_18 ;
if ( V_16 -> V_22 . type == V_24 )
V_16 = F_32 ( V_16 -> V_25 , struct V_15 ,
V_26 . V_183 ) ;
if ( V_16 -> V_22 . type == V_23 )
V_18 = & V_16 -> V_25 -> V_18 ;
else if ( F_9 ( & V_16 -> V_22 ) )
V_18 = & V_16 -> V_26 . V_27 . V_18 ;
else
return;
F_10 ( V_4 , V_184 ) ;
F_135 ( F_136 ( V_35 ) > 1 ) ;
V_4 -> V_145 = 0 ;
if ( ! ( V_2 -> V_32 . V_50 & V_142 ) )
F_137 ( V_2 , V_16 , V_185 , & V_4 -> V_4 ) ;
F_55 ( & V_38 ) ;
F_138 ( & V_4 -> V_65 ) ;
for ( V_11 = 0 ; V_11 < V_29 ; V_11 ++ ) {
int V_186 = F_13 ( & V_38 ) , V_172 ;
F_96 ( & V_4 -> V_33 [ V_11 ] . V_64 , V_50 ) ;
F_139 ( & V_4 -> V_33 [ V_11 ] , & V_38 ) ;
F_99 ( & V_4 -> V_33 [ V_11 ] . V_64 , V_50 ) ;
V_172 = F_13 ( & V_38 ) ;
V_181 += V_172 - V_186 ;
V_186 = V_172 ;
F_96 ( & V_4 -> V_31 [ V_11 ] . V_64 , V_50 ) ;
F_139 ( & V_4 -> V_31 [ V_11 ] , & V_38 ) ;
F_99 ( & V_4 -> V_31 [ V_11 ] . V_64 , V_50 ) ;
V_172 = F_13 ( & V_38 ) ;
V_182 += V_172 - V_186 ;
}
F_140 ( V_2 , & V_38 ) ;
F_10 ( V_4 , V_21 ) ;
F_10 ( V_4 , V_47 ) ;
F_10 ( V_4 , V_48 ) ;
F_141 ( & V_4 -> V_65 ) ;
F_11 ( & V_18 -> V_28 ) ;
if ( ! F_9 ( & V_16 -> V_22 ) &&
! F_142 ( V_4 -> V_99 ,
V_16 -> V_87 ) &&
V_4 -> V_99 != V_16 -> V_25 -> V_187 &&
F_143 ( V_4 ) != 1 ) {
F_144 ( V_16 ,
L_8 ,
V_4 -> V_4 . V_7 ) ;
F_145 ( V_16 , V_16 -> V_25 -> V_187 ,
V_4 -> V_4 . V_7 ,
V_16 -> V_22 . V_156 . V_188 ) ;
}
V_2 -> V_30 -= V_182 ;
F_12 ( V_4 ) ;
F_101 ( V_16 ,
L_9 ,
V_4 -> V_4 . V_7 , V_4 -> V_4 . V_139 , V_181 , V_182 ) ;
}
static void F_146 ( struct V_15 * V_16 ,
struct V_3 * V_4 , int V_189 ,
enum V_190 V_191 ,
bool V_192 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_193 * V_194 ;
struct V_150 * V_151 ;
int V_195 = sizeof( * V_194 ) ;
T_6 V_196 ;
bool V_197 = V_4 -> V_4 . V_198 ;
struct V_152 * V_153 ;
struct V_199 * V_200 ;
if ( V_197 ) {
V_196 = F_56 ( V_201 |
V_202 |
V_203 ) ;
} else {
V_195 -= 2 ;
V_196 = F_56 ( V_201 |
V_204 |
V_203 ) ;
}
V_151 = F_147 ( V_2 -> V_32 . V_205 + V_195 ) ;
if ( ! V_151 )
return;
F_148 ( V_151 , V_2 -> V_32 . V_205 ) ;
V_194 = ( void * ) F_149 ( V_151 , V_195 ) ;
V_194 -> V_206 = V_196 ;
V_194 -> V_207 = 0 ;
memcpy ( V_194 -> V_208 , V_4 -> V_4 . V_7 , V_73 ) ;
memcpy ( V_194 -> V_209 , V_16 -> V_22 . V_7 , V_73 ) ;
memcpy ( V_194 -> V_210 , V_16 -> V_22 . V_7 , V_73 ) ;
V_194 -> V_211 = 0 ;
V_151 -> V_212 = V_189 ;
F_150 ( V_151 , V_213 [ V_189 ] ) ;
if ( V_197 ) {
V_194 -> V_214 = F_56 ( V_189 ) ;
if ( V_191 == V_215 )
V_194 -> V_214 |=
F_56 ( V_216 ) ;
}
V_153 = F_93 ( V_151 ) ;
V_153 -> V_50 |= V_217 |
V_218 |
V_219 |
V_220 ;
if ( V_192 )
F_151 ( V_2 , V_4 , F_86 ( V_189 ) , 1 ,
V_191 , false ) ;
V_151 -> V_127 = V_16 -> V_127 ;
F_43 () ;
V_200 = F_44 ( V_16 -> V_22 . V_200 ) ;
if ( F_58 ( ! V_200 ) ) {
F_45 () ;
F_152 ( V_151 ) ;
return;
}
V_153 -> V_221 = V_200 -> V_222 . V_223 -> V_221 ;
F_153 ( V_16 , V_151 ) ;
F_45 () ;
}
static int F_154 ( unsigned long V_144 )
{
if ( V_144 & 0xF8 )
return F_155 ( V_144 ) - 1 ;
if ( V_144 & F_86 ( 0 ) )
return 0 ;
return F_155 ( V_144 ) - 1 ;
}
static void
F_156 ( struct V_3 * V_4 ,
int V_224 , T_1 V_225 ,
enum V_190 V_191 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_2 ;
bool V_226 = false ;
int V_11 ;
unsigned long V_227 = 0 ;
struct V_180 V_228 ;
F_68 ( V_4 , V_184 ) ;
F_157 ( & V_228 ) ;
for ( V_11 = 0 ; V_11 < V_29 ; V_11 ++ ) {
unsigned long V_144 ;
if ( V_225 & F_86 ( V_11 ) )
continue;
V_144 = F_85 ( V_11 ) ;
if ( F_88 ( & V_228 ) )
V_227 |= V_4 -> V_145 & V_144 ;
if ( V_227 ) {
if ( V_191 == V_229 &&
F_158 ( V_227 ) > 1 ) {
V_226 = true ;
V_227 =
F_86 ( F_154 (
V_227 ) ) ;
break;
}
} else {
struct V_150 * V_151 ;
while ( V_224 > 0 ) {
V_151 = F_159 ( & V_4 -> V_33 [ V_11 ] ) ;
if ( ! V_151 ) {
V_151 = F_159 (
& V_4 -> V_31 [ V_11 ] ) ;
if ( V_151 )
V_2 -> V_30 -- ;
}
if ( ! V_151 )
break;
V_224 -- ;
F_160 ( & V_228 , V_151 ) ;
}
}
if ( ! F_88 ( & V_4 -> V_33 [ V_11 ] ) ||
! F_88 ( & V_4 -> V_31 [ V_11 ] ) ) {
V_226 = true ;
break;
}
}
if ( F_88 ( & V_228 ) && ! V_227 ) {
int V_189 ;
V_189 = 7 - ( ( F_161 ( ~ V_225 ) - 1 ) << 1 ) ;
F_146 ( V_16 , V_4 , V_189 , V_191 , true ) ;
} else if ( ! V_227 ) {
struct V_180 V_38 ;
struct V_150 * V_151 ;
int V_230 = 0 ;
T_4 V_144 = 0 ;
bool V_231 = false ;
F_55 ( & V_38 ) ;
while ( ( V_151 = F_98 ( & V_228 ) ) ) {
struct V_152 * V_153 = F_93 ( V_151 ) ;
struct V_232 * V_233 = ( void * ) V_151 -> V_166 ;
T_1 * V_234 = NULL ;
V_230 ++ ;
V_153 -> V_50 |= V_217 |
V_218 ;
if ( V_226 || ! F_88 ( & V_228 ) )
V_233 -> V_206 |=
F_56 ( V_235 ) ;
else
V_233 -> V_206 &=
F_56 ( ~ V_235 ) ;
if ( F_162 ( V_233 -> V_206 ) ||
F_163 ( V_233 -> V_206 ) )
V_234 = F_164 ( V_233 ) ;
V_144 |= F_86 ( V_151 -> V_212 ) ;
F_160 ( & V_38 , V_151 ) ;
if ( ! F_88 ( & V_228 ) )
continue;
if ( V_191 != V_215 ) {
V_153 -> V_50 |= V_219 |
V_220 ;
break;
}
if ( V_234 ) {
* V_234 |= V_216 ;
V_153 -> V_50 |= V_219 |
V_220 ;
} else {
V_233 -> V_206 |=
F_56 ( V_235 ) ;
V_231 = true ;
V_230 ++ ;
}
break;
}
F_151 ( V_2 , V_4 , V_144 , V_230 ,
V_191 , V_226 ) ;
F_140 ( V_2 , & V_38 ) ;
if ( V_231 )
F_146 (
V_16 , V_4 , F_154 ( V_144 ) ,
V_191 , false ) ;
F_12 ( V_4 ) ;
} else {
F_165 ( V_2 , V_4 , V_227 ,
V_224 , V_191 , V_226 ) ;
}
}
void F_36 ( struct V_3 * V_4 )
{
T_1 V_236 = V_4 -> V_4 . V_138 ;
if ( V_236 == F_86 ( V_29 ) - 1 )
V_236 = 0 ;
F_156 ( V_4 , 1 , V_236 ,
V_229 ) ;
}
void F_37 ( struct V_3 * V_4 )
{
int V_224 = V_4 -> V_4 . V_237 ;
T_1 V_238 = V_4 -> V_4 . V_138 ;
if ( ! V_238 )
return;
switch ( V_4 -> V_4 . V_237 ) {
case 1 :
V_224 = 2 ;
break;
case 2 :
V_224 = 4 ;
break;
case 3 :
V_224 = 6 ;
break;
case 0 :
V_224 = 128 ;
break;
}
F_156 ( V_4 , V_224 , ~ V_238 ,
V_215 ) ;
}
void F_166 ( struct V_176 * V_32 ,
struct V_175 * V_239 , bool V_240 )
{
struct V_3 * V_4 = F_32 ( V_239 , struct V_3 , V_4 ) ;
F_167 ( V_4 -> V_2 , V_239 , V_240 ) ;
if ( V_240 ) {
F_68 ( V_4 , V_20 ) ;
return;
}
if ( ! F_8 ( V_4 , V_20 ) )
return;
if ( ! F_8 ( V_4 , V_19 ) ) {
F_68 ( V_4 , V_21 ) ;
F_10 ( V_4 , V_20 ) ;
F_168 ( V_32 , & V_4 -> V_34 ) ;
} else if ( F_8 ( V_4 , V_47 ) ||
F_8 ( V_4 , V_48 ) ) {
F_10 ( V_4 , V_20 ) ;
F_168 ( V_32 , & V_4 -> V_34 ) ;
} else {
F_10 ( V_4 , V_20 ) ;
}
}
void F_169 ( struct V_175 * V_239 )
{
struct V_3 * V_4 = F_32 ( V_239 , struct V_3 , V_4 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_170 ( V_2 , V_239 ) ;
F_10 ( V_4 , V_184 ) ;
}
void F_171 ( struct V_175 * V_239 ,
T_1 V_189 , bool V_182 )
{
struct V_3 * V_4 = F_32 ( V_239 , struct V_3 , V_4 ) ;
if ( F_58 ( V_189 >= V_35 ) )
return;
F_172 ( V_4 -> V_2 , V_239 , V_189 , V_182 ) ;
if ( V_182 )
F_173 ( V_189 , & V_4 -> V_145 ) ;
else
F_174 ( V_189 , & V_4 -> V_145 ) ;
F_12 ( V_4 ) ;
}
int F_110 ( struct V_3 * V_4 ,
enum V_106 V_241 )
{
F_79 () ;
if ( V_4 -> V_76 == V_241 )
return 0 ;
switch ( V_241 ) {
case V_77 :
if ( V_4 -> V_76 != V_242 )
return - V_105 ;
break;
case V_242 :
if ( V_4 -> V_76 != V_77 &&
V_4 -> V_76 != V_243 )
return - V_105 ;
break;
case V_243 :
if ( V_4 -> V_76 != V_242 &&
V_4 -> V_76 != V_244 )
return - V_105 ;
break;
case V_244 :
if ( V_4 -> V_76 != V_243 )
return - V_105 ;
break;
default:
F_175 ( 1 , L_10 , V_241 ) ;
return - V_105 ;
}
F_28 ( V_4 -> V_16 , L_11 ,
V_4 -> V_4 . V_7 , V_241 ) ;
if ( F_8 ( V_4 , V_124 ) ) {
int V_108 = F_64 ( V_4 -> V_2 , V_4 -> V_16 , V_4 ,
V_4 -> V_76 , V_241 ) ;
if ( V_108 )
return V_108 ;
}
switch ( V_241 ) {
case V_77 :
if ( V_4 -> V_76 == V_242 )
F_174 ( V_245 , & V_4 -> V_246 ) ;
break;
case V_242 :
if ( V_4 -> V_76 == V_77 )
F_173 ( V_245 , & V_4 -> V_246 ) ;
else if ( V_4 -> V_76 == V_243 )
F_174 ( V_247 , & V_4 -> V_246 ) ;
break;
case V_243 :
if ( V_4 -> V_76 == V_242 ) {
F_173 ( V_247 , & V_4 -> V_246 ) ;
} else if ( V_4 -> V_76 == V_244 ) {
if ( V_4 -> V_16 -> V_22 . type == V_23 ||
( V_4 -> V_16 -> V_22 . type == V_24 &&
! V_4 -> V_16 -> V_26 . V_165 . V_4 ) )
F_11 ( & V_4 -> V_16 -> V_25 -> V_248 ) ;
F_174 ( V_249 , & V_4 -> V_246 ) ;
}
break;
case V_244 :
if ( V_4 -> V_76 == V_243 ) {
if ( V_4 -> V_16 -> V_22 . type == V_23 ||
( V_4 -> V_16 -> V_22 . type == V_24 &&
! V_4 -> V_16 -> V_26 . V_165 . V_4 ) )
F_176 ( & V_4 -> V_16 -> V_25 -> V_248 ) ;
F_173 ( V_249 , & V_4 -> V_246 ) ;
}
break;
default:
break;
}
V_4 -> V_76 = V_241 ;
return 0 ;
}
T_1 F_143 ( struct V_3 * V_4 )
{
struct V_250 * V_94 = & V_4 -> V_4 . V_94 ;
T_1 V_251 ;
if ( ! V_4 -> V_4 . V_94 . V_252 )
return 1 ;
if ( V_4 -> V_4 . V_253 . V_254 ) {
int V_12 ;
T_4 V_255 =
F_177 ( V_4 -> V_4 . V_253 . V_256 . V_255 ) ;
for ( V_12 = 7 ; V_12 >= 0 ; V_12 -- )
if ( ( V_255 & ( 0x3 << ( V_12 * 2 ) ) ) !=
V_257 )
return V_12 + 1 ;
}
if ( V_94 -> V_258 . V_259 [ 3 ] )
V_251 = 4 ;
else if ( V_94 -> V_258 . V_259 [ 2 ] )
V_251 = 3 ;
else if ( V_94 -> V_258 . V_259 [ 1 ] )
V_251 = 2 ;
else
V_251 = 1 ;
if ( ! ( V_94 -> V_258 . V_260 & V_261 ) )
return V_251 ;
return ( ( V_94 -> V_258 . V_260 & V_262 )
>> V_263 ) + 1 ;
}
void F_178 ( struct V_3 * V_4 , struct V_114 * V_115 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_264 * V_265 = NULL ;
struct V_54 V_55 ;
T_7 V_266 = 0 ;
V_63 V_267 = 0 ;
int V_12 , V_11 ;
if ( F_8 ( V_4 , V_268 ) )
V_265 = V_2 -> V_40 ;
V_115 -> V_126 = V_16 -> V_2 -> V_119 ;
V_115 -> V_125 = V_269 |
V_270 |
V_271 |
V_272 |
V_273 |
V_274 |
V_275 |
V_276 |
V_277 |
V_278 |
V_279 |
V_280 |
V_281 |
V_282 ;
F_52 ( & V_55 ) ;
V_115 -> V_283 = V_55 . V_81 - V_4 -> V_80 ;
V_115 -> V_284 = F_179 ( V_75 - V_4 -> V_74 ) ;
V_115 -> V_285 = 0 ;
for ( V_11 = 0 ; V_11 < V_29 ; V_11 ++ ) {
V_115 -> V_285 += V_4 -> V_285 [ V_11 ] ;
V_266 += V_4 -> V_286 [ V_11 ] ;
}
V_115 -> V_286 = V_266 ;
V_115 -> V_287 = V_4 -> V_287 ;
V_115 -> V_288 = V_4 -> V_288 ;
V_115 -> V_289 = V_4 -> V_290 ;
V_115 -> V_291 = V_4 -> V_292 ;
V_115 -> V_293 = V_4 -> V_294 ;
V_115 -> V_295 = V_4 -> V_295 ;
if ( ( V_4 -> V_2 -> V_32 . V_50 & V_296 ) ||
( V_4 -> V_2 -> V_32 . V_50 & V_297 ) ) {
V_115 -> V_125 |= V_298 | V_299 ;
if ( ! V_2 -> V_110 -> V_300 ||
F_180 ( V_2 , V_16 , & V_4 -> V_4 , & V_115 -> signal ) )
V_115 -> signal = ( V_301 ) V_4 -> V_302 ;
V_115 -> V_303 = ( V_301 ) - F_181 ( & V_4 -> V_82 ) ;
}
if ( V_4 -> V_304 ) {
V_115 -> V_125 |= V_305 |
V_306 ;
V_115 -> V_304 = V_4 -> V_304 ;
for ( V_12 = 0 ; V_12 < F_54 ( V_115 -> V_307 ) ; V_12 ++ ) {
V_115 -> V_307 [ V_12 ] = V_4 -> V_308 [ V_12 ] ;
V_115 -> V_83 [ V_12 ] =
( V_301 ) - F_181 ( & V_4 -> V_83 [ V_12 ] ) ;
}
}
F_182 ( V_4 , & V_4 -> V_309 , & V_115 -> V_310 ) ;
F_183 ( V_4 , & V_115 -> V_311 ) ;
if ( F_9 ( & V_16 -> V_22 ) ) {
#ifdef F_50
V_115 -> V_125 |= V_312 |
V_313 |
V_314 |
V_315 |
V_316 |
V_317 ;
V_115 -> V_318 = V_4 -> V_318 ;
V_115 -> V_140 = V_4 -> V_140 ;
V_115 -> V_319 = V_4 -> V_319 ;
if ( F_8 ( V_4 , V_320 ) ) {
V_115 -> V_125 |= V_321 ;
V_115 -> V_322 = V_4 -> V_322 ;
}
V_115 -> V_323 = V_4 -> V_323 ;
V_115 -> V_324 = V_4 -> V_324 ;
V_115 -> V_71 = V_4 -> V_71 ;
#endif
}
V_115 -> V_325 . V_50 = 0 ;
if ( V_16 -> V_22 . V_156 . V_326 )
V_115 -> V_325 . V_50 |= V_327 ;
if ( V_16 -> V_22 . V_156 . V_328 )
V_115 -> V_325 . V_50 |= V_329 ;
if ( V_16 -> V_22 . V_156 . V_330 )
V_115 -> V_325 . V_50 |= V_331 ;
V_115 -> V_325 . V_332 = V_16 -> V_22 . V_156 . V_332 ;
V_115 -> V_325 . V_333 = V_16 -> V_22 . V_156 . V_157 ;
V_115 -> V_334 . V_335 = 0 ;
V_115 -> V_334 . V_336 = F_86 ( V_337 ) |
F_86 ( V_338 ) |
F_86 ( V_339 ) |
F_86 ( V_340 ) |
F_86 ( V_341 ) |
F_86 ( V_342 ) |
F_86 ( V_343 ) ;
if ( F_8 ( V_4 , V_249 ) )
V_115 -> V_334 . V_335 |= F_86 ( V_337 ) ;
if ( F_8 ( V_4 , V_344 ) )
V_115 -> V_334 . V_335 |= F_86 ( V_338 ) ;
if ( V_4 -> V_4 . V_198 )
V_115 -> V_334 . V_335 |= F_86 ( V_339 ) ;
if ( F_8 ( V_4 , V_345 ) )
V_115 -> V_334 . V_335 |= F_86 ( V_340 ) ;
if ( F_8 ( V_4 , V_245 ) )
V_115 -> V_334 . V_335 |= F_86 ( V_341 ) ;
if ( F_8 ( V_4 , V_247 ) )
V_115 -> V_334 . V_335 |= F_86 ( V_342 ) ;
if ( F_8 ( V_4 , V_346 ) )
V_115 -> V_334 . V_335 |= F_86 ( V_343 ) ;
if ( V_265 && V_265 -> V_110 -> V_347 )
V_267 = V_265 -> V_110 -> V_347 ( V_4 -> V_52 ) ;
else
V_267 = F_184 ( V_2 , & V_4 -> V_4 ) ;
if ( V_267 != 0 ) {
V_115 -> V_125 |= V_348 ;
V_115 -> V_349 = V_267 ;
}
}
