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
F_52 ( & V_55 ) ;
V_4 -> V_78 = V_55 . V_79 ;
F_53 ( & V_4 -> V_80 , 1024 , 8 ) ;
for ( V_12 = 0 ; V_12 < F_54 ( V_4 -> V_81 ) ; V_12 ++ )
F_53 ( & V_4 -> V_81 [ V_12 ] , 1024 , 8 ) ;
if ( F_39 ( V_2 , V_4 , V_49 ) )
goto free;
for ( V_12 = 0 ; V_12 < V_35 ; V_12 ++ ) {
V_4 -> V_82 [ V_12 ] = V_12 ;
}
for ( V_12 = 0 ; V_12 < V_29 ; V_12 ++ ) {
F_55 ( & V_4 -> V_31 [ V_12 ] ) ;
F_55 ( & V_4 -> V_33 [ V_12 ] ) ;
}
for ( V_12 = 0 ; V_12 < V_35 ; V_12 ++ )
V_4 -> V_83 [ V_12 ] = F_56 ( V_84 ) ;
V_4 -> V_4 . V_85 = V_86 ;
if ( V_16 -> V_22 . type == V_23 ||
V_16 -> V_22 . type == V_24 ) {
struct V_87 * V_88 =
V_2 -> V_32 . V_89 -> V_90 [ F_57 ( V_16 ) ] ;
T_1 V_91 = ( V_88 -> V_92 . V_93 & V_94 ) >>
V_95 ;
switch ( V_91 ) {
case V_96 :
V_4 -> V_97 = V_86 ;
break;
case V_98 :
V_4 -> V_97 = V_99 ;
break;
case V_100 :
V_4 -> V_97 = V_101 ;
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
return - V_102 ;
if ( F_58 ( F_23 ( V_4 -> V_4 . V_7 , V_16 -> V_22 . V_7 ) ||
F_62 ( V_4 -> V_4 . V_7 ) ) )
return - V_103 ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_3 * V_4 )
{
enum V_104 V_105 ;
int V_106 = 0 ;
for ( V_105 = V_107 ; V_105 < V_4 -> V_76 ; V_105 ++ ) {
V_106 = F_64 ( V_2 , V_16 , V_4 , V_105 , V_105 + 1 ) ;
if ( V_106 )
break;
}
if ( ! V_106 ) {
if ( ! V_2 -> V_108 -> V_109 )
V_4 -> V_110 = true ;
return 0 ;
}
if ( V_16 -> V_22 . type == V_111 ) {
F_65 ( V_16 ,
L_3 ,
V_4 -> V_4 . V_7 , V_105 + 1 , V_106 ) ;
V_106 = 0 ;
}
for (; V_105 > V_107 ; V_105 -- )
F_58 ( F_64 ( V_2 , V_16 , V_4 , V_105 , V_105 - 1 ) ) ;
return V_106 ;
}
static int F_66 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_112 V_113 ;
int V_106 = 0 ;
F_30 ( & V_2 -> V_8 ) ;
if ( F_24 ( V_16 , V_4 -> V_4 . V_7 ) ) {
V_106 = - V_114 ;
goto V_115;
}
V_2 -> V_116 ++ ;
V_2 -> V_117 ++ ;
F_67 () ;
F_68 ( V_4 , V_118 ) ;
F_29 ( V_2 , V_4 ) ;
F_69 ( & V_4 -> V_119 , & V_2 -> V_120 ) ;
V_106 = F_63 ( V_2 , V_16 , V_4 ) ;
if ( V_106 )
goto V_121;
F_68 ( V_4 , V_122 ) ;
F_10 ( V_4 , V_118 ) ;
F_70 ( V_16 ) ;
F_71 ( V_4 ) ;
F_72 ( V_4 ) ;
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
V_113 . V_123 = 0 ;
V_113 . V_124 = V_2 -> V_117 ;
F_73 ( V_16 -> V_125 , V_4 -> V_4 . V_7 , & V_113 , V_126 ) ;
F_28 ( V_16 , L_4 , V_4 -> V_4 . V_7 ) ;
F_43 () ;
F_74 ( & V_2 -> V_8 ) ;
if ( F_9 ( & V_16 -> V_22 ) )
F_75 ( V_16 ) ;
return 0 ;
V_121:
F_1 ( V_2 , V_4 ) ;
F_76 ( & V_4 -> V_119 ) ;
V_2 -> V_116 -- ;
F_77 () ;
F_7 ( V_4 ) ;
V_115:
F_74 ( & V_2 -> V_8 ) ;
F_43 () ;
return V_106 ;
}
int F_78 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_106 ;
F_79 () ;
V_106 = F_59 ( V_4 ) ;
if ( V_106 ) {
F_43 () ;
goto V_127;
}
F_80 ( & V_2 -> V_8 ) ;
V_106 = F_66 ( V_4 ) ;
if ( V_106 )
goto V_127;
return 0 ;
V_127:
F_20 ( V_2 , V_4 ) ;
return V_106 ;
}
int F_81 ( struct V_3 * V_4 )
{
int V_106 = F_78 ( V_4 ) ;
F_45 () ;
return V_106 ;
}
static inline void F_82 ( T_1 * V_128 , T_4 V_129 )
{
V_128 [ V_129 / 8 ] |= ( 1 << ( V_129 % 8 ) ) ;
}
static inline void F_83 ( T_1 * V_128 , T_4 V_129 )
{
V_128 [ V_129 / 8 ] &= ~ ( 1 << ( V_129 % 8 ) ) ;
}
static inline bool F_84 ( T_1 * V_128 , T_4 V_129 )
{
return V_128 [ V_129 / 8 ] & ( 1 << ( V_129 % 8 ) ) ;
}
static unsigned long F_85 ( int V_11 )
{
switch ( V_11 ) {
case V_130 :
return F_86 ( 6 ) | F_86 ( 7 ) ;
case V_131 :
return F_86 ( 4 ) | F_86 ( 5 ) ;
case V_132 :
return F_86 ( 0 ) | F_86 ( 3 ) ;
case V_133 :
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
bool V_134 = false ;
T_1 V_135 = V_4 -> V_4 . V_136 ;
int V_11 ;
T_4 V_129 ;
if ( V_4 -> V_16 -> V_22 . type == V_23 ||
V_4 -> V_16 -> V_22 . type == V_24 ) {
if ( F_87 ( ! V_4 -> V_16 -> V_25 ) )
return;
V_18 = & V_4 -> V_16 -> V_25 -> V_18 ;
V_129 = V_4 -> V_4 . V_137 ;
#ifdef F_50
} else if ( F_9 ( & V_4 -> V_16 -> V_22 ) ) {
V_18 = & V_4 -> V_16 -> V_26 . V_27 . V_18 ;
V_129 = V_4 -> V_138 % ( V_139 + 1 ) ;
#endif
} else {
return;
}
if ( V_2 -> V_32 . V_50 & V_140 )
return;
if ( V_4 -> V_46 )
goto V_141;
if ( V_135 == F_86 ( V_29 ) - 1 )
V_135 = 0 ;
for ( V_11 = 0 ; V_11 < V_29 ; V_11 ++ ) {
unsigned long V_142 ;
if ( V_135 & F_86 ( V_11 ) )
continue;
V_134 |= ! F_88 ( & V_4 -> V_33 [ V_11 ] ) ||
! F_88 ( & V_4 -> V_31 [ V_11 ] ) ;
if ( V_134 )
break;
V_142 = F_85 ( V_11 ) ;
V_134 |=
V_4 -> V_143 & V_142 ;
}
V_141:
F_89 ( & V_2 -> V_144 ) ;
if ( V_134 == F_84 ( V_18 -> V_128 , V_129 ) )
goto V_145;
if ( V_134 )
F_82 ( V_18 -> V_128 , V_129 ) ;
else
F_83 ( V_18 -> V_128 , V_129 ) ;
if ( V_2 -> V_108 -> V_146 ) {
V_2 -> V_147 = true ;
F_90 ( V_2 , & V_4 -> V_4 , V_134 ) ;
V_2 -> V_147 = false ;
}
V_145:
F_91 ( & V_2 -> V_144 ) ;
}
static bool F_92 ( struct V_3 * V_4 , struct V_148 * V_149 )
{
struct V_150 * V_151 ;
int V_152 ;
if ( ! V_149 )
return false ;
V_151 = F_93 ( V_149 ) ;
V_152 = ( V_4 -> V_153 *
V_4 -> V_16 -> V_22 . V_154 . V_155 *
32 / 15625 ) * V_156 ;
if ( V_152 < V_157 )
V_152 = V_157 ;
return F_94 ( V_75 , V_151 -> V_158 . V_75 + V_152 ) ;
}
static bool F_95 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_11 )
{
unsigned long V_50 ;
struct V_148 * V_149 ;
for (; ; ) {
F_96 ( & V_4 -> V_33 [ V_11 ] . V_64 , V_50 ) ;
V_149 = F_97 ( & V_4 -> V_33 [ V_11 ] ) ;
if ( F_92 ( V_4 , V_149 ) )
V_149 = F_98 ( & V_4 -> V_33 [ V_11 ] ) ;
else
V_149 = NULL ;
F_99 ( & V_4 -> V_33 [ V_11 ] . V_64 , V_50 ) ;
if ( ! V_149 )
break;
F_100 ( & V_2 -> V_32 , V_149 ) ;
}
for (; ; ) {
F_96 ( & V_4 -> V_31 [ V_11 ] . V_64 , V_50 ) ;
V_149 = F_97 ( & V_4 -> V_31 [ V_11 ] ) ;
if ( F_92 ( V_4 , V_149 ) )
V_149 = F_98 ( & V_4 -> V_31 [ V_11 ] ) ;
else
V_149 = NULL ;
F_99 ( & V_4 -> V_31 [ V_11 ] . V_64 , V_50 ) ;
if ( ! V_149 )
break;
V_2 -> V_30 -- ;
F_101 ( V_4 -> V_16 , L_5 ,
V_4 -> V_4 . V_7 ) ;
F_100 ( & V_2 -> V_32 , V_149 ) ;
}
F_12 ( V_4 ) ;
return ! ( F_88 ( & V_4 -> V_31 [ V_11 ] ) &&
F_88 ( & V_4 -> V_33 [ V_11 ] ) ) ;
}
static bool F_102 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_159 = false ;
int V_11 ;
if ( ! V_4 -> V_16 -> V_25 &&
! F_9 ( & V_4 -> V_16 -> V_22 ) )
return false ;
for ( V_11 = 0 ; V_11 < V_29 ; V_11 ++ )
V_159 |=
F_95 ( V_2 , V_4 , V_11 ) ;
return V_159 ;
}
static int T_5 F_103 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_15 * V_16 ;
int V_160 ;
F_79 () ;
if ( ! V_4 )
return - V_9 ;
V_2 = V_4 -> V_2 ;
V_16 = V_4 -> V_16 ;
F_30 ( & V_2 -> V_8 ) ;
F_68 ( V_4 , V_118 ) ;
F_104 ( V_4 , V_161 ) ;
V_160 = F_1 ( V_2 , V_4 ) ;
if ( F_58 ( V_160 ) )
return V_160 ;
F_76 ( & V_4 -> V_119 ) ;
F_105 ( V_2 , V_4 -> V_16 , V_4 ) ;
if ( V_16 -> V_22 . type == V_24 &&
F_6 ( V_16 -> V_26 . V_162 . V_4 ) == V_4 )
F_106 ( V_16 -> V_26 . V_162 . V_4 , NULL ) ;
return 0 ;
}
static void F_107 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_15 * V_16 = V_4 -> V_16 ;
int V_160 ;
F_79 () ;
F_30 ( & V_2 -> V_8 ) ;
F_108 ( V_2 , V_4 ) ;
V_4 -> V_46 = true ;
V_2 -> V_116 -- ;
V_2 -> V_117 ++ ;
while ( V_4 -> V_76 > V_77 ) {
V_160 = F_109 ( V_4 , V_4 -> V_76 - 1 ) ;
if ( V_160 ) {
F_87 ( 1 ) ;
break;
}
}
if ( V_4 -> V_110 ) {
V_160 = F_64 ( V_2 , V_16 , V_4 , V_77 ,
V_107 ) ;
F_87 ( V_160 != 0 ) ;
}
F_28 ( V_16 , L_6 , V_4 -> V_4 . V_7 ) ;
F_110 ( V_16 -> V_125 , V_4 -> V_4 . V_7 , V_126 ) ;
F_111 ( V_4 ) ;
F_112 ( V_4 ) ;
F_70 ( V_16 ) ;
F_19 ( V_4 ) ;
}
int T_5 F_113 ( struct V_3 * V_4 )
{
int V_106 = F_103 ( V_4 ) ;
if ( V_106 )
return V_106 ;
F_77 () ;
F_107 ( V_4 ) ;
return 0 ;
}
int F_114 ( struct V_15 * V_16 , const T_1 * V_7 )
{
struct V_3 * V_4 ;
int V_160 ;
F_80 ( & V_16 -> V_2 -> V_8 ) ;
V_4 = F_21 ( V_16 , V_7 ) ;
V_160 = F_113 ( V_4 ) ;
F_74 ( & V_16 -> V_2 -> V_8 ) ;
return V_160 ;
}
int F_115 ( struct V_15 * V_16 ,
const T_1 * V_7 )
{
struct V_3 * V_4 ;
int V_160 ;
F_80 ( & V_16 -> V_2 -> V_8 ) ;
V_4 = F_24 ( V_16 , V_7 ) ;
V_160 = F_113 ( V_4 ) ;
F_74 ( & V_16 -> V_2 -> V_8 ) ;
return V_160 ;
}
static void F_116 ( unsigned long V_163 )
{
struct V_1 * V_2 = (struct V_1 * ) V_163 ;
struct V_3 * V_4 ;
bool V_164 = false ;
F_43 () ;
F_26 (sta, &local->sta_list, list)
if ( F_102 ( V_2 , V_4 ) )
V_164 = true ;
F_45 () ;
if ( V_2 -> V_165 )
return;
if ( ! V_164 )
return;
F_117 ( & V_2 -> V_166 ,
F_118 ( V_75 + V_167 ) ) ;
}
void F_119 ( struct V_1 * V_2 )
{
F_47 ( & V_2 -> V_144 ) ;
F_49 ( & V_2 -> V_8 ) ;
F_120 ( & V_2 -> V_120 ) ;
F_121 ( & V_2 -> V_166 , F_116 ,
( unsigned long ) V_2 ) ;
}
void F_122 ( struct V_1 * V_2 )
{
F_123 ( & V_2 -> V_166 ) ;
}
int F_124 ( struct V_15 * V_16 , bool V_168 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 , * V_169 ;
F_125 ( V_170 ) ;
int V_160 = 0 ;
F_79 () ;
F_58 ( V_168 && V_16 -> V_22 . type != V_23 ) ;
F_58 ( V_168 && ! V_16 -> V_25 ) ;
F_80 ( & V_2 -> V_8 ) ;
F_126 (sta, tmp, &local->sta_list, list) {
if ( V_16 == V_4 -> V_16 ||
( V_168 && V_16 -> V_25 == V_4 -> V_16 -> V_25 ) ) {
if ( ! F_58 ( F_103 ( V_4 ) ) )
F_127 ( & V_4 -> V_170 , & V_170 ) ;
V_160 ++ ;
}
}
if ( ! F_128 ( & V_170 ) ) {
F_77 () ;
F_126 (sta, tmp, &free_list, free_list)
F_107 ( V_4 ) ;
}
F_74 ( & V_2 -> V_8 ) ;
return V_160 ;
}
void F_129 ( struct V_15 * V_16 ,
unsigned long V_171 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 , * V_169 ;
F_80 ( & V_2 -> V_8 ) ;
F_126 (sta, tmp, &local->sta_list, list) {
if ( V_16 != V_4 -> V_16 )
continue;
if ( F_94 ( V_75 , V_4 -> V_74 + V_171 ) ) {
F_28 ( V_4 -> V_16 , L_7 ,
V_4 -> V_4 . V_7 ) ;
if ( F_9 ( & V_16 -> V_22 ) &&
F_8 ( V_4 , V_19 ) )
F_11 ( & V_16 -> V_26 . V_27 . V_18 . V_28 ) ;
F_58 ( F_113 ( V_4 ) ) ;
}
}
F_74 ( & V_2 -> V_8 ) ;
}
struct V_172 * F_130 ( struct V_173 * V_32 ,
const T_1 * V_7 ,
const T_1 * V_174 )
{
struct V_3 * V_4 , * V_175 ;
F_131 (hw_to_local(hw), addr, sta, nxt) {
if ( V_174 &&
! F_23 ( V_4 -> V_16 -> V_22 . V_7 , V_174 ) )
continue;
if ( ! V_4 -> V_110 )
return NULL ;
return & V_4 -> V_4 ;
}
return NULL ;
}
struct V_172 * F_132 ( struct V_176 * V_22 ,
const T_1 * V_7 )
{
struct V_3 * V_4 ;
if ( ! V_22 )
return NULL ;
V_4 = F_24 ( F_133 ( V_22 ) , V_7 ) ;
if ( ! V_4 )
return NULL ;
if ( ! V_4 -> V_110 )
return NULL ;
return & V_4 -> V_4 ;
}
void F_34 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_177 V_38 ;
int V_178 = 0 , V_179 = 0 , V_11 ;
unsigned long V_50 ;
struct V_17 * V_18 ;
if ( V_16 -> V_22 . type == V_24 )
V_16 = F_32 ( V_16 -> V_25 , struct V_15 ,
V_26 . V_180 ) ;
if ( V_16 -> V_22 . type == V_23 )
V_18 = & V_16 -> V_25 -> V_18 ;
else if ( F_9 ( & V_16 -> V_22 ) )
V_18 = & V_16 -> V_26 . V_27 . V_18 ;
else
return;
F_10 ( V_4 , V_181 ) ;
F_134 ( F_135 ( V_35 ) > 1 ) ;
V_4 -> V_143 = 0 ;
if ( ! ( V_2 -> V_32 . V_50 & V_140 ) )
F_136 ( V_2 , V_16 , V_182 , & V_4 -> V_4 ) ;
F_55 ( & V_38 ) ;
F_137 ( & V_4 -> V_65 ) ;
for ( V_11 = 0 ; V_11 < V_29 ; V_11 ++ ) {
int V_183 = F_13 ( & V_38 ) , V_169 ;
F_96 ( & V_4 -> V_33 [ V_11 ] . V_64 , V_50 ) ;
F_138 ( & V_4 -> V_33 [ V_11 ] , & V_38 ) ;
F_99 ( & V_4 -> V_33 [ V_11 ] . V_64 , V_50 ) ;
V_169 = F_13 ( & V_38 ) ;
V_178 += V_169 - V_183 ;
V_183 = V_169 ;
F_96 ( & V_4 -> V_31 [ V_11 ] . V_64 , V_50 ) ;
F_138 ( & V_4 -> V_31 [ V_11 ] , & V_38 ) ;
F_99 ( & V_4 -> V_31 [ V_11 ] . V_64 , V_50 ) ;
V_169 = F_13 ( & V_38 ) ;
V_179 += V_169 - V_183 ;
}
F_139 ( V_2 , & V_38 ) ;
F_10 ( V_4 , V_21 ) ;
F_10 ( V_4 , V_47 ) ;
F_10 ( V_4 , V_48 ) ;
F_140 ( & V_4 -> V_65 ) ;
F_11 ( & V_18 -> V_28 ) ;
if ( ! F_9 ( & V_16 -> V_22 ) &&
! F_141 ( V_4 -> V_97 ,
V_16 -> V_85 ) &&
V_4 -> V_97 != V_16 -> V_25 -> V_184 &&
F_142 ( V_4 ) != 1 ) {
F_143 ( V_16 ,
L_8 ,
V_4 -> V_4 . V_7 ) ;
F_144 ( V_16 , V_16 -> V_25 -> V_184 ,
V_4 -> V_4 . V_7 ,
V_16 -> V_22 . V_154 . V_185 ) ;
}
V_2 -> V_30 -= V_179 ;
F_12 ( V_4 ) ;
F_101 ( V_16 ,
L_9 ,
V_4 -> V_4 . V_7 , V_4 -> V_4 . V_137 , V_178 , V_179 ) ;
}
static void F_145 ( struct V_15 * V_16 ,
struct V_3 * V_4 , int V_186 ,
enum V_187 V_188 ,
bool V_189 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_190 * V_191 ;
struct V_148 * V_149 ;
int V_192 = sizeof( * V_191 ) ;
T_6 V_193 ;
bool V_194 = V_4 -> V_4 . V_195 ;
struct V_150 * V_151 ;
struct V_196 * V_197 ;
if ( V_194 ) {
V_193 = F_56 ( V_198 |
V_199 |
V_200 ) ;
} else {
V_192 -= 2 ;
V_193 = F_56 ( V_198 |
V_201 |
V_200 ) ;
}
V_149 = F_146 ( V_2 -> V_32 . V_202 + V_192 ) ;
if ( ! V_149 )
return;
F_147 ( V_149 , V_2 -> V_32 . V_202 ) ;
V_191 = ( void * ) F_148 ( V_149 , V_192 ) ;
V_191 -> V_203 = V_193 ;
V_191 -> V_204 = 0 ;
memcpy ( V_191 -> V_205 , V_4 -> V_4 . V_7 , V_73 ) ;
memcpy ( V_191 -> V_206 , V_16 -> V_22 . V_7 , V_73 ) ;
memcpy ( V_191 -> V_207 , V_16 -> V_22 . V_7 , V_73 ) ;
V_191 -> V_208 = 0 ;
V_149 -> V_209 = V_186 ;
F_149 ( V_149 , V_210 [ V_186 ] ) ;
if ( V_194 ) {
V_191 -> V_211 = F_56 ( V_186 ) ;
if ( V_188 == V_212 )
V_191 -> V_211 |=
F_56 ( V_213 ) ;
}
V_151 = F_93 ( V_149 ) ;
V_151 -> V_50 |= V_214 |
V_215 |
V_216 |
V_217 ;
if ( V_189 )
F_150 ( V_2 , V_4 , F_86 ( V_186 ) , 1 ,
V_188 , false ) ;
V_149 -> V_125 = V_16 -> V_125 ;
F_43 () ;
V_197 = F_44 ( V_16 -> V_22 . V_197 ) ;
if ( F_58 ( ! V_197 ) ) {
F_45 () ;
F_151 ( V_149 ) ;
return;
}
F_152 ( V_16 , V_149 , V_197 -> V_218 . V_219 -> V_220 ) ;
F_45 () ;
}
static int F_153 ( unsigned long V_142 )
{
if ( V_142 & 0xF8 )
return F_154 ( V_142 ) - 1 ;
if ( V_142 & F_86 ( 0 ) )
return 0 ;
return F_154 ( V_142 ) - 1 ;
}
static void
F_155 ( struct V_3 * V_4 ,
int V_221 , T_1 V_222 ,
enum V_187 V_188 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_2 ;
bool V_223 = false ;
int V_11 ;
unsigned long V_224 = 0 ;
struct V_177 V_225 ;
F_68 ( V_4 , V_181 ) ;
F_156 ( & V_225 ) ;
for ( V_11 = 0 ; V_11 < V_29 ; V_11 ++ ) {
unsigned long V_142 ;
if ( V_222 & F_86 ( V_11 ) )
continue;
V_142 = F_85 ( V_11 ) ;
if ( F_88 ( & V_225 ) )
V_224 |= V_4 -> V_143 & V_142 ;
if ( V_224 ) {
if ( V_188 == V_226 &&
F_157 ( V_224 ) > 1 ) {
V_223 = true ;
V_224 =
F_86 ( F_153 (
V_224 ) ) ;
break;
}
} else {
struct V_148 * V_149 ;
while ( V_221 > 0 ) {
V_149 = F_158 ( & V_4 -> V_33 [ V_11 ] ) ;
if ( ! V_149 ) {
V_149 = F_158 (
& V_4 -> V_31 [ V_11 ] ) ;
if ( V_149 )
V_2 -> V_30 -- ;
}
if ( ! V_149 )
break;
V_221 -- ;
F_159 ( & V_225 , V_149 ) ;
}
}
if ( ! F_88 ( & V_4 -> V_33 [ V_11 ] ) ||
! F_88 ( & V_4 -> V_31 [ V_11 ] ) ) {
V_223 = true ;
break;
}
}
if ( F_88 ( & V_225 ) && ! V_224 ) {
int V_186 ;
V_186 = 7 - ( ( F_160 ( ~ V_222 ) - 1 ) << 1 ) ;
F_145 ( V_16 , V_4 , V_186 , V_188 , true ) ;
} else if ( ! V_224 ) {
struct V_177 V_38 ;
struct V_148 * V_149 ;
int V_227 = 0 ;
T_4 V_142 = 0 ;
bool V_228 = false ;
F_55 ( & V_38 ) ;
while ( ( V_149 = F_98 ( & V_225 ) ) ) {
struct V_150 * V_151 = F_93 ( V_149 ) ;
struct V_229 * V_230 = ( void * ) V_149 -> V_163 ;
T_1 * V_231 = NULL ;
V_227 ++ ;
V_151 -> V_50 |= V_214 |
V_215 ;
if ( V_223 || ! F_88 ( & V_225 ) )
V_230 -> V_203 |=
F_56 ( V_232 ) ;
else
V_230 -> V_203 &=
F_56 ( ~ V_232 ) ;
if ( F_161 ( V_230 -> V_203 ) ||
F_162 ( V_230 -> V_203 ) )
V_231 = F_163 ( V_230 ) ;
V_142 |= F_86 ( V_149 -> V_209 ) ;
F_159 ( & V_38 , V_149 ) ;
if ( ! F_88 ( & V_225 ) )
continue;
if ( V_188 != V_212 ) {
V_151 -> V_50 |= V_216 |
V_217 ;
break;
}
if ( V_231 ) {
* V_231 |= V_213 ;
V_151 -> V_50 |= V_216 |
V_217 ;
} else {
V_230 -> V_203 |=
F_56 ( V_232 ) ;
V_228 = true ;
V_227 ++ ;
}
break;
}
F_150 ( V_2 , V_4 , V_142 , V_227 ,
V_188 , V_223 ) ;
F_139 ( V_2 , & V_38 ) ;
if ( V_228 )
F_145 (
V_16 , V_4 , F_153 ( V_142 ) ,
V_188 , false ) ;
F_12 ( V_4 ) ;
} else {
F_164 ( V_2 , V_4 , V_224 ,
V_221 , V_188 , V_223 ) ;
}
}
void F_36 ( struct V_3 * V_4 )
{
T_1 V_233 = V_4 -> V_4 . V_136 ;
if ( V_233 == F_86 ( V_29 ) - 1 )
V_233 = 0 ;
F_155 ( V_4 , 1 , V_233 ,
V_226 ) ;
}
void F_37 ( struct V_3 * V_4 )
{
int V_221 = V_4 -> V_4 . V_234 ;
T_1 V_235 = V_4 -> V_4 . V_136 ;
if ( ! V_235 )
return;
switch ( V_4 -> V_4 . V_234 ) {
case 1 :
V_221 = 2 ;
break;
case 2 :
V_221 = 4 ;
break;
case 3 :
V_221 = 6 ;
break;
case 0 :
V_221 = 8 ;
break;
}
F_155 ( V_4 , V_221 , ~ V_235 ,
V_212 ) ;
}
void F_165 ( struct V_173 * V_32 ,
struct V_172 * V_236 , bool V_237 )
{
struct V_3 * V_4 = F_32 ( V_236 , struct V_3 , V_4 ) ;
F_166 ( V_4 -> V_2 , V_236 , V_237 ) ;
if ( V_237 ) {
F_68 ( V_4 , V_20 ) ;
return;
}
if ( ! F_8 ( V_4 , V_20 ) )
return;
if ( ! F_8 ( V_4 , V_19 ) ) {
F_68 ( V_4 , V_21 ) ;
F_10 ( V_4 , V_20 ) ;
F_167 ( V_32 , & V_4 -> V_34 ) ;
} else if ( F_8 ( V_4 , V_47 ) ||
F_8 ( V_4 , V_48 ) ) {
F_10 ( V_4 , V_20 ) ;
F_167 ( V_32 , & V_4 -> V_34 ) ;
} else {
F_10 ( V_4 , V_20 ) ;
}
}
void F_168 ( struct V_172 * V_236 )
{
struct V_3 * V_4 = F_32 ( V_236 , struct V_3 , V_4 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_169 ( V_2 , V_236 ) ;
F_10 ( V_4 , V_181 ) ;
}
void F_170 ( struct V_172 * V_236 ,
T_1 V_186 , bool V_179 )
{
struct V_3 * V_4 = F_32 ( V_236 , struct V_3 , V_4 ) ;
if ( F_58 ( V_186 >= V_35 ) )
return;
F_171 ( V_4 -> V_2 , V_236 , V_186 , V_179 ) ;
if ( V_179 )
F_172 ( V_186 , & V_4 -> V_143 ) ;
else
F_173 ( V_186 , & V_4 -> V_143 ) ;
F_12 ( V_4 ) ;
}
int F_109 ( struct V_3 * V_4 ,
enum V_104 V_238 )
{
F_79 () ;
if ( V_4 -> V_76 == V_238 )
return 0 ;
switch ( V_238 ) {
case V_77 :
if ( V_4 -> V_76 != V_239 )
return - V_103 ;
break;
case V_239 :
if ( V_4 -> V_76 != V_77 &&
V_4 -> V_76 != V_240 )
return - V_103 ;
break;
case V_240 :
if ( V_4 -> V_76 != V_239 &&
V_4 -> V_76 != V_241 )
return - V_103 ;
break;
case V_241 :
if ( V_4 -> V_76 != V_240 )
return - V_103 ;
break;
default:
F_174 ( 1 , L_10 , V_238 ) ;
return - V_103 ;
}
F_28 ( V_4 -> V_16 , L_11 ,
V_4 -> V_4 . V_7 , V_238 ) ;
if ( F_8 ( V_4 , V_122 ) ) {
int V_106 = F_64 ( V_4 -> V_2 , V_4 -> V_16 , V_4 ,
V_4 -> V_76 , V_238 ) ;
if ( V_106 )
return V_106 ;
}
switch ( V_238 ) {
case V_77 :
if ( V_4 -> V_76 == V_239 )
F_173 ( V_242 , & V_4 -> V_243 ) ;
break;
case V_239 :
if ( V_4 -> V_76 == V_77 )
F_172 ( V_242 , & V_4 -> V_243 ) ;
else if ( V_4 -> V_76 == V_240 )
F_173 ( V_244 , & V_4 -> V_243 ) ;
break;
case V_240 :
if ( V_4 -> V_76 == V_239 ) {
F_172 ( V_244 , & V_4 -> V_243 ) ;
} else if ( V_4 -> V_76 == V_241 ) {
if ( V_4 -> V_16 -> V_22 . type == V_23 ||
( V_4 -> V_16 -> V_22 . type == V_24 &&
! V_4 -> V_16 -> V_26 . V_162 . V_4 ) )
F_11 ( & V_4 -> V_16 -> V_25 -> V_245 ) ;
F_173 ( V_246 , & V_4 -> V_243 ) ;
}
break;
case V_241 :
if ( V_4 -> V_76 == V_240 ) {
if ( V_4 -> V_16 -> V_22 . type == V_23 ||
( V_4 -> V_16 -> V_22 . type == V_24 &&
! V_4 -> V_16 -> V_26 . V_162 . V_4 ) )
F_175 ( & V_4 -> V_16 -> V_25 -> V_245 ) ;
F_172 ( V_246 , & V_4 -> V_243 ) ;
}
break;
default:
break;
}
V_4 -> V_76 = V_238 ;
return 0 ;
}
T_1 F_142 ( struct V_3 * V_4 )
{
struct V_247 * V_92 = & V_4 -> V_4 . V_92 ;
T_1 V_248 ;
if ( ! V_4 -> V_4 . V_92 . V_249 )
return 1 ;
if ( V_4 -> V_4 . V_250 . V_251 ) {
int V_12 ;
T_4 V_252 =
F_176 ( V_4 -> V_4 . V_250 . V_253 . V_252 ) ;
for ( V_12 = 7 ; V_12 >= 0 ; V_12 -- )
if ( ( V_252 & ( 0x3 << ( V_12 * 2 ) ) ) !=
V_254 )
return V_12 + 1 ;
}
if ( V_92 -> V_255 . V_256 [ 3 ] )
V_248 = 4 ;
else if ( V_92 -> V_255 . V_256 [ 2 ] )
V_248 = 3 ;
else if ( V_92 -> V_255 . V_256 [ 1 ] )
V_248 = 2 ;
else
V_248 = 1 ;
if ( ! ( V_92 -> V_255 . V_257 & V_258 ) )
return V_248 ;
return ( ( V_92 -> V_255 . V_257 & V_259 )
>> V_260 ) + 1 ;
}
void F_177 ( struct V_3 * V_4 , struct V_112 * V_113 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_261 * V_262 = NULL ;
struct V_54 V_55 ;
T_7 V_263 = 0 ;
V_63 V_264 = 0 ;
int V_12 , V_11 ;
if ( F_8 ( V_4 , V_265 ) )
V_262 = V_2 -> V_40 ;
V_113 -> V_124 = V_16 -> V_2 -> V_117 ;
V_113 -> V_123 = V_266 |
V_267 |
V_268 |
V_269 |
V_270 |
V_271 |
V_272 |
V_273 |
V_274 |
V_275 |
V_276 |
V_277 |
V_278 |
V_279 ;
F_52 ( & V_55 ) ;
V_113 -> V_280 = V_55 . V_79 - V_4 -> V_78 ;
V_113 -> V_281 = F_178 ( V_75 - V_4 -> V_74 ) ;
V_113 -> V_282 = 0 ;
for ( V_11 = 0 ; V_11 < V_29 ; V_11 ++ ) {
V_113 -> V_282 += V_4 -> V_282 [ V_11 ] ;
V_263 += V_4 -> V_283 [ V_11 ] ;
}
V_113 -> V_283 = V_263 ;
V_113 -> V_284 = V_4 -> V_284 ;
V_113 -> V_285 = V_4 -> V_285 ;
V_113 -> V_286 = V_4 -> V_287 ;
V_113 -> V_288 = V_4 -> V_289 ;
V_113 -> V_290 = V_4 -> V_291 ;
V_113 -> V_292 = V_4 -> V_292 ;
if ( ( V_4 -> V_2 -> V_32 . V_50 & V_293 ) ||
( V_4 -> V_2 -> V_32 . V_50 & V_294 ) ) {
V_113 -> V_123 |= V_295 | V_296 ;
if ( ! V_2 -> V_108 -> V_297 ||
F_179 ( V_2 , V_16 , & V_4 -> V_4 , & V_113 -> signal ) )
V_113 -> signal = ( V_298 ) V_4 -> V_299 ;
V_113 -> V_300 = ( V_298 ) - F_180 ( & V_4 -> V_80 ) ;
}
if ( V_4 -> V_301 ) {
V_113 -> V_123 |= V_302 |
V_303 ;
V_113 -> V_301 = V_4 -> V_301 ;
for ( V_12 = 0 ; V_12 < F_54 ( V_113 -> V_304 ) ; V_12 ++ ) {
V_113 -> V_304 [ V_12 ] = V_4 -> V_305 [ V_12 ] ;
V_113 -> V_81 [ V_12 ] =
( V_298 ) - F_180 ( & V_4 -> V_81 [ V_12 ] ) ;
}
}
F_181 ( V_4 , & V_4 -> V_306 , & V_113 -> V_307 ) ;
F_182 ( V_4 , & V_113 -> V_308 ) ;
if ( F_9 ( & V_16 -> V_22 ) ) {
#ifdef F_50
V_113 -> V_123 |= V_309 |
V_310 |
V_311 |
V_312 |
V_313 |
V_314 ;
V_113 -> V_315 = V_4 -> V_315 ;
V_113 -> V_138 = V_4 -> V_138 ;
V_113 -> V_316 = V_4 -> V_316 ;
if ( F_8 ( V_4 , V_317 ) ) {
V_113 -> V_123 |= V_318 ;
V_113 -> V_319 = V_4 -> V_319 ;
}
V_113 -> V_320 = V_4 -> V_320 ;
V_113 -> V_321 = V_4 -> V_321 ;
V_113 -> V_71 = V_4 -> V_71 ;
#endif
}
V_113 -> V_322 . V_50 = 0 ;
if ( V_16 -> V_22 . V_154 . V_323 )
V_113 -> V_322 . V_50 |= V_324 ;
if ( V_16 -> V_22 . V_154 . V_325 )
V_113 -> V_322 . V_50 |= V_326 ;
if ( V_16 -> V_22 . V_154 . V_327 )
V_113 -> V_322 . V_50 |= V_328 ;
V_113 -> V_322 . V_329 = V_16 -> V_22 . V_154 . V_329 ;
V_113 -> V_322 . V_330 = V_16 -> V_22 . V_154 . V_155 ;
V_113 -> V_331 . V_332 = 0 ;
V_113 -> V_331 . V_333 = F_86 ( V_334 ) |
F_86 ( V_335 ) |
F_86 ( V_336 ) |
F_86 ( V_337 ) |
F_86 ( V_338 ) |
F_86 ( V_339 ) |
F_86 ( V_340 ) ;
if ( F_8 ( V_4 , V_246 ) )
V_113 -> V_331 . V_332 |= F_86 ( V_334 ) ;
if ( F_8 ( V_4 , V_341 ) )
V_113 -> V_331 . V_332 |= F_86 ( V_335 ) ;
if ( V_4 -> V_4 . V_195 )
V_113 -> V_331 . V_332 |= F_86 ( V_336 ) ;
if ( F_8 ( V_4 , V_342 ) )
V_113 -> V_331 . V_332 |= F_86 ( V_337 ) ;
if ( F_8 ( V_4 , V_242 ) )
V_113 -> V_331 . V_332 |= F_86 ( V_338 ) ;
if ( F_8 ( V_4 , V_244 ) )
V_113 -> V_331 . V_332 |= F_86 ( V_339 ) ;
if ( F_8 ( V_4 , V_343 ) )
V_113 -> V_331 . V_332 |= F_86 ( V_340 ) ;
if ( V_262 && V_262 -> V_108 -> V_344 )
V_264 = V_262 -> V_108 -> V_344 ( V_4 -> V_52 ) ;
else
V_264 = F_183 ( V_2 , & V_4 -> V_4 ) ;
if ( V_264 != 0 ) {
V_113 -> V_123 |= V_345 ;
V_113 -> V_346 = V_264 ;
}
}
