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
if ( F_8 ( V_4 , V_19 ) ) {
if ( V_4 -> V_16 -> V_20 . type == V_21 ||
V_4 -> V_16 -> V_20 . type == V_22 )
V_18 = & V_16 -> V_23 -> V_18 ;
else if ( F_9 ( & V_16 -> V_20 ) )
V_18 = & V_16 -> V_24 . V_25 . V_18 ;
else
return;
F_10 ( V_4 , V_19 ) ;
F_11 ( & V_18 -> V_26 ) ;
F_12 ( V_4 ) ;
}
for ( V_11 = 0 ; V_11 < V_27 ; V_11 ++ ) {
V_2 -> V_28 -= F_13 ( & V_4 -> V_29 [ V_11 ] ) ;
F_14 ( & V_2 -> V_30 , & V_4 -> V_29 [ V_11 ] ) ;
F_14 ( & V_2 -> V_30 , & V_4 -> V_31 [ V_11 ] ) ;
}
if ( F_9 ( & V_16 -> V_20 ) )
F_15 ( V_4 ) ;
F_16 ( & V_4 -> V_32 ) ;
for ( V_12 = 0 ; V_12 < V_33 ; V_12 ++ ) {
F_17 ( V_4 -> V_34 . V_35 [ V_12 ] ) ;
V_14 = F_18 ( V_4 -> V_34 . V_14 [ V_12 ] ) ;
if ( ! V_14 )
continue;
F_14 ( & V_2 -> V_30 , & V_14 -> V_36 ) ;
F_17 ( V_14 ) ;
}
F_19 ( V_2 , V_4 ) ;
}
void F_20 ( struct V_15 * V_16 )
{
struct V_3 * V_4 ;
F_21 ( & V_16 -> V_37 ) ;
while ( ! F_22 ( & V_16 -> V_38 ) ) {
V_4 = F_23 ( & V_16 -> V_38 ,
struct V_3 , V_39 ) ;
F_24 ( & V_4 -> V_39 ) ;
F_25 ( & V_16 -> V_37 ) ;
F_7 ( V_4 ) ;
F_21 ( & V_16 -> V_37 ) ;
}
F_25 ( & V_16 -> V_37 ) ;
}
static void F_26 ( struct V_40 * V_41 )
{
struct V_3 * V_4 = F_27 ( V_41 , struct V_3 , V_40 ) ;
struct V_15 * V_16 = V_4 -> V_16 ;
F_28 ( & V_16 -> V_37 ) ;
F_29 ( & V_4 -> V_39 , & V_16 -> V_38 ) ;
F_30 ( & V_16 -> V_37 ) ;
F_31 ( & V_16 -> V_2 -> V_30 , & V_16 -> V_42 ) ;
}
struct V_3 * F_32 ( struct V_15 * V_16 ,
const T_1 * V_7 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 ;
V_4 = F_33 ( V_2 -> V_6 [ F_3 ( V_7 ) ] ,
F_4 ( & V_2 -> V_8 ) ) ;
while ( V_4 ) {
if ( V_4 -> V_16 == V_16 &&
F_34 ( V_4 -> V_4 . V_7 , V_7 ) )
break;
V_4 = F_33 ( V_4 -> V_10 ,
F_4 ( & V_2 -> V_8 ) ) ;
}
return V_4 ;
}
struct V_3 * F_35 ( struct V_15 * V_16 ,
const T_1 * V_7 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 ;
V_4 = F_33 ( V_2 -> V_6 [ F_3 ( V_7 ) ] ,
F_4 ( & V_2 -> V_8 ) ) ;
while ( V_4 ) {
if ( ( V_4 -> V_16 == V_16 ||
( V_4 -> V_16 -> V_23 && V_4 -> V_16 -> V_23 == V_16 -> V_23 ) ) &&
F_34 ( V_4 -> V_4 . V_7 , V_7 ) )
break;
V_4 = F_33 ( V_4 -> V_10 ,
F_4 ( & V_2 -> V_8 ) ) ;
}
return V_4 ;
}
struct V_3 * F_36 ( struct V_15 * V_16 ,
int V_43 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 ;
int V_12 = 0 ;
F_37 (sta, &local->sta_list, list) {
if ( V_16 != V_4 -> V_16 )
continue;
if ( V_12 < V_43 ) {
++ V_12 ;
continue;
}
return V_4 ;
}
return NULL ;
}
void F_19 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_44 )
F_38 ( V_4 ) ;
F_39 ( V_4 -> V_16 , L_1 , V_4 -> V_4 . V_7 ) ;
F_17 ( V_4 ) ;
}
static void F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_41 ( & V_2 -> V_8 ) ;
V_4 -> V_10 = V_2 -> V_6 [ F_3 ( V_4 -> V_4 . V_7 ) ] ;
F_5 ( V_2 -> V_6 [ F_3 ( V_4 -> V_4 . V_7 ) ] , V_4 ) ;
}
static void F_42 ( struct V_45 * V_46 )
{
struct V_3 * V_4 ;
V_4 = F_27 ( V_46 , struct V_3 , V_32 ) ;
if ( V_4 -> V_47 )
return;
if ( ! F_8 ( V_4 , V_19 ) ) {
F_43 () ;
F_44 ( V_4 ) ;
F_45 () ;
} else if ( F_46 ( V_4 , V_48 ) ) {
F_10 ( V_4 , V_49 ) ;
F_43 () ;
F_47 ( V_4 ) ;
F_45 () ;
} else if ( F_46 ( V_4 , V_50 ) ) {
F_10 ( V_4 , V_49 ) ;
F_43 () ;
F_48 ( V_4 ) ;
F_45 () ;
} else
F_10 ( V_4 , V_49 ) ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 V_51 )
{
if ( V_2 -> V_30 . V_52 & V_53 )
return 0 ;
V_4 -> V_44 = V_2 -> V_44 ;
V_4 -> V_54 = F_50 ( V_4 -> V_44 ,
& V_4 -> V_4 , V_51 ) ;
if ( ! V_4 -> V_54 )
return - V_55 ;
return 0 ;
}
struct V_3 * F_51 ( struct V_15 * V_16 ,
const T_1 * V_7 , T_2 V_51 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 ;
struct V_56 V_57 ;
int V_12 ;
V_4 = F_52 ( sizeof( * V_4 ) + V_2 -> V_30 . V_58 , V_51 ) ;
if ( ! V_4 )
return NULL ;
F_53 ( & V_4 -> V_59 ) ;
F_54 ( & V_4 -> V_32 , F_42 ) ;
F_54 ( & V_4 -> V_34 . V_60 , V_61 ) ;
F_55 ( & V_4 -> V_34 . V_62 ) ;
#ifdef F_56
if ( F_9 ( & V_16 -> V_20 ) &&
! V_16 -> V_24 . V_25 . V_63 )
F_57 ( & V_4 -> V_64 ) ;
V_4 -> V_65 = V_66 ;
#endif
memcpy ( V_4 -> V_4 . V_7 , V_7 , V_67 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_16 = V_16 ;
V_4 -> V_68 = V_69 ;
V_4 -> V_70 = V_71 ;
F_58 ( & V_57 ) ;
V_4 -> V_72 = V_57 . V_73 ;
F_59 ( & V_4 -> V_74 , 1024 , 8 ) ;
for ( V_12 = 0 ; V_12 < F_60 ( V_4 -> V_75 ) ; V_12 ++ )
F_59 ( & V_4 -> V_75 [ V_12 ] , 1024 , 8 ) ;
if ( F_49 ( V_2 , V_4 , V_51 ) ) {
F_17 ( V_4 ) ;
return NULL ;
}
for ( V_12 = 0 ; V_12 < V_33 ; V_12 ++ ) {
V_4 -> V_76 [ V_12 ] = V_12 ;
}
for ( V_12 = 0 ; V_12 < V_27 ; V_12 ++ ) {
F_61 ( & V_4 -> V_29 [ V_12 ] ) ;
F_61 ( & V_4 -> V_31 [ V_12 ] ) ;
}
for ( V_12 = 0 ; V_12 < V_33 ; V_12 ++ )
V_4 -> V_77 [ V_12 ] = F_62 ( V_78 ) ;
V_4 -> V_4 . V_79 = V_80 ;
if ( V_16 -> V_20 . type == V_21 ||
V_16 -> V_20 . type == V_22 ) {
struct V_81 * V_82 =
V_2 -> V_30 . V_83 -> V_84 [ F_63 ( V_16 ) ] ;
T_1 V_85 = ( V_82 -> V_86 . V_87 & V_88 ) >>
V_89 ;
switch ( V_85 ) {
case V_90 :
V_4 -> V_91 = V_80 ;
break;
case V_92 :
V_4 -> V_91 = V_93 ;
break;
case V_94 :
V_4 -> V_91 = V_95 ;
break;
default:
F_64 ( 1 ) ;
}
}
F_39 ( V_16 , L_2 , V_4 -> V_4 . V_7 ) ;
return V_4 ;
}
static int F_65 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
if ( F_66 ( ! F_67 ( V_16 ) ) )
return - V_96 ;
if ( F_64 ( F_34 ( V_4 -> V_4 . V_7 , V_16 -> V_20 . V_7 ) ||
F_68 ( V_4 -> V_4 . V_7 ) ) )
return - V_97 ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_3 * V_4 )
{
enum V_98 V_99 ;
int V_100 = 0 ;
for ( V_99 = V_101 ; V_99 < V_4 -> V_70 ; V_99 ++ ) {
V_100 = F_70 ( V_2 , V_16 , V_4 , V_99 , V_99 + 1 ) ;
if ( V_100 )
break;
}
if ( ! V_100 ) {
if ( ! V_2 -> V_102 -> V_103 )
V_4 -> V_104 = true ;
return 0 ;
}
if ( V_16 -> V_20 . type == V_105 ) {
F_71 ( V_16 ,
L_3 ,
V_4 -> V_4 . V_7 , V_99 + 1 , V_100 ) ;
V_100 = 0 ;
}
for (; V_99 > V_101 ; V_99 -- )
F_64 ( F_70 ( V_2 , V_16 , V_4 , V_99 , V_99 - 1 ) ) ;
return V_100 ;
}
static int F_72 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_106 V_107 ;
int V_100 = 0 ;
F_41 ( & V_2 -> V_8 ) ;
if ( F_35 ( V_16 , V_4 -> V_4 . V_7 ) ) {
V_100 = - V_108 ;
goto V_109;
}
V_100 = F_69 ( V_2 , V_16 , V_4 ) ;
if ( V_100 )
goto V_109;
V_2 -> V_110 ++ ;
V_2 -> V_111 ++ ;
F_73 () ;
F_40 ( V_2 , V_4 ) ;
F_74 ( & V_4 -> V_39 , & V_2 -> V_112 ) ;
F_75 ( V_4 , V_113 ) ;
F_76 ( V_4 ) ;
F_77 ( V_4 ) ;
memset ( & V_107 , 0 , sizeof( V_107 ) ) ;
V_107 . V_114 = 0 ;
V_107 . V_115 = V_2 -> V_111 ;
F_78 ( V_16 -> V_116 , V_4 -> V_4 . V_7 , & V_107 , V_117 ) ;
F_39 ( V_16 , L_4 , V_4 -> V_4 . V_7 ) ;
F_79 () ;
F_80 ( & V_2 -> V_8 ) ;
if ( F_9 ( & V_16 -> V_20 ) )
F_81 ( V_16 ) ;
return 0 ;
V_109:
F_80 ( & V_2 -> V_8 ) ;
F_79 () ;
return V_100 ;
}
int F_82 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_100 = 0 ;
F_83 () ;
V_100 = F_65 ( V_4 ) ;
if ( V_100 ) {
F_79 () ;
goto V_118;
}
F_84 ( & V_2 -> V_8 ) ;
V_100 = F_72 ( V_4 ) ;
if ( V_100 )
goto V_118;
return 0 ;
V_118:
F_85 ( ! V_100 ) ;
F_19 ( V_2 , V_4 ) ;
return V_100 ;
}
int F_86 ( struct V_3 * V_4 )
{
int V_100 = F_82 ( V_4 ) ;
F_87 () ;
return V_100 ;
}
static inline void F_88 ( T_1 * V_119 , T_4 V_120 )
{
V_119 [ V_120 / 8 ] |= ( 1 << ( V_120 % 8 ) ) ;
}
static inline void F_89 ( T_1 * V_119 , T_4 V_120 )
{
V_119 [ V_120 / 8 ] &= ~ ( 1 << ( V_120 % 8 ) ) ;
}
static inline bool F_90 ( T_1 * V_119 , T_4 V_120 )
{
return V_119 [ V_120 / 8 ] & ( 1 << ( V_120 % 8 ) ) ;
}
static unsigned long F_91 ( int V_11 )
{
switch ( V_11 ) {
case V_121 :
return F_92 ( 6 ) | F_92 ( 7 ) ;
case V_122 :
return F_92 ( 4 ) | F_92 ( 5 ) ;
case V_123 :
return F_92 ( 0 ) | F_92 ( 3 ) ;
case V_124 :
return F_92 ( 1 ) | F_92 ( 2 ) ;
default:
F_64 ( 1 ) ;
return 0 ;
}
}
void F_12 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_17 * V_18 ;
bool V_125 = false ;
T_1 V_126 = V_4 -> V_4 . V_127 ;
int V_11 ;
T_4 V_120 ;
if ( V_4 -> V_16 -> V_20 . type == V_21 ||
V_4 -> V_16 -> V_20 . type == V_22 ) {
if ( F_93 ( ! V_4 -> V_16 -> V_23 ) )
return;
V_18 = & V_4 -> V_16 -> V_23 -> V_18 ;
V_120 = V_4 -> V_4 . V_128 ;
#ifdef F_56
} else if ( F_9 ( & V_4 -> V_16 -> V_20 ) ) {
V_18 = & V_4 -> V_16 -> V_24 . V_25 . V_18 ;
V_120 = F_94 ( V_4 -> V_129 ) % V_130 ;
#endif
} else {
return;
}
if ( V_2 -> V_30 . V_52 & V_131 )
return;
if ( V_4 -> V_47 )
goto V_132;
if ( V_126 == F_92 ( V_27 ) - 1 )
V_126 = 0 ;
for ( V_11 = 0 ; V_11 < V_27 ; V_11 ++ ) {
unsigned long V_133 ;
if ( V_126 & F_92 ( V_11 ) )
continue;
V_125 |= ! F_95 ( & V_4 -> V_31 [ V_11 ] ) ||
! F_95 ( & V_4 -> V_29 [ V_11 ] ) ;
if ( V_125 )
break;
V_133 = F_91 ( V_11 ) ;
V_125 |=
V_4 -> V_134 & V_133 ;
}
V_132:
F_21 ( & V_2 -> V_135 ) ;
if ( V_125 == F_90 ( V_18 -> V_119 , V_120 ) )
goto V_136;
if ( V_125 )
F_88 ( V_18 -> V_119 , V_120 ) ;
else
F_89 ( V_18 -> V_119 , V_120 ) ;
if ( V_2 -> V_102 -> V_137 ) {
V_2 -> V_138 = true ;
F_96 ( V_2 , & V_4 -> V_4 , V_125 ) ;
V_2 -> V_138 = false ;
}
V_136:
F_25 ( & V_2 -> V_135 ) ;
}
static bool F_97 ( struct V_3 * V_4 , struct V_139 * V_140 )
{
struct V_141 * V_142 ;
int V_143 ;
if ( ! V_140 )
return false ;
V_142 = F_98 ( V_140 ) ;
V_143 = ( V_4 -> V_144 *
V_4 -> V_16 -> V_20 . V_145 . V_146 *
32 / 15625 ) * V_147 ;
if ( V_143 < V_148 )
V_143 = V_148 ;
return F_99 ( V_69 , V_142 -> V_149 . V_69 + V_143 ) ;
}
static bool F_100 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_11 )
{
unsigned long V_52 ;
struct V_139 * V_140 ;
for (; ; ) {
F_101 ( & V_4 -> V_31 [ V_11 ] . V_59 , V_52 ) ;
V_140 = F_102 ( & V_4 -> V_31 [ V_11 ] ) ;
if ( F_97 ( V_4 , V_140 ) )
V_140 = F_103 ( & V_4 -> V_31 [ V_11 ] ) ;
else
V_140 = NULL ;
F_104 ( & V_4 -> V_31 [ V_11 ] . V_59 , V_52 ) ;
if ( ! V_140 )
break;
F_105 ( & V_2 -> V_30 , V_140 ) ;
}
for (; ; ) {
F_101 ( & V_4 -> V_29 [ V_11 ] . V_59 , V_52 ) ;
V_140 = F_102 ( & V_4 -> V_29 [ V_11 ] ) ;
if ( F_97 ( V_4 , V_140 ) )
V_140 = F_103 ( & V_4 -> V_29 [ V_11 ] ) ;
else
V_140 = NULL ;
F_104 ( & V_4 -> V_29 [ V_11 ] . V_59 , V_52 ) ;
if ( ! V_140 )
break;
V_2 -> V_28 -- ;
F_106 ( V_4 -> V_16 , L_5 ,
V_4 -> V_4 . V_7 ) ;
F_105 ( & V_2 -> V_30 , V_140 ) ;
}
F_12 ( V_4 ) ;
return ! ( F_95 ( & V_4 -> V_29 [ V_11 ] ) &&
F_95 ( & V_4 -> V_31 [ V_11 ] ) ) ;
}
static bool F_107 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_150 = false ;
int V_11 ;
if ( ! V_4 -> V_16 -> V_23 &&
! F_9 ( & V_4 -> V_16 -> V_20 ) )
return false ;
for ( V_11 = 0 ; V_11 < V_27 ; V_11 ++ )
V_150 |=
F_100 ( V_2 , V_4 , V_11 ) ;
return V_150 ;
}
int T_5 F_108 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_15 * V_16 ;
int V_151 ;
F_83 () ;
if ( ! V_4 )
return - V_9 ;
V_2 = V_4 -> V_2 ;
V_16 = V_4 -> V_16 ;
F_41 ( & V_2 -> V_8 ) ;
F_75 ( V_4 , V_152 ) ;
F_109 ( V_4 , V_153 ) ;
V_151 = F_1 ( V_2 , V_4 ) ;
if ( V_151 )
return V_151 ;
F_110 ( & V_4 -> V_39 ) ;
F_111 ( V_2 , V_4 ) ;
V_4 -> V_47 = true ;
V_2 -> V_110 -- ;
V_2 -> V_111 ++ ;
if ( V_16 -> V_20 . type == V_22 )
F_112 ( V_16 -> V_24 . V_154 . V_4 , NULL ) ;
while ( V_4 -> V_70 > V_71 ) {
V_151 = F_113 ( V_4 , V_4 -> V_70 - 1 ) ;
if ( V_151 ) {
F_93 ( 1 ) ;
break;
}
}
if ( V_4 -> V_104 ) {
V_151 = F_70 ( V_2 , V_16 , V_4 , V_71 ,
V_101 ) ;
F_93 ( V_151 != 0 ) ;
}
F_39 ( V_16 , L_6 , V_4 -> V_4 . V_7 ) ;
F_114 ( V_16 -> V_116 , V_4 -> V_4 . V_7 , V_117 ) ;
F_115 ( V_4 ) ;
F_116 ( V_4 ) ;
F_117 ( & V_4 -> V_40 , F_26 ) ;
return 0 ;
}
int F_118 ( struct V_15 * V_16 , const T_1 * V_7 )
{
struct V_3 * V_4 ;
int V_151 ;
F_84 ( & V_16 -> V_2 -> V_8 ) ;
V_4 = F_32 ( V_16 , V_7 ) ;
V_151 = F_108 ( V_4 ) ;
F_80 ( & V_16 -> V_2 -> V_8 ) ;
return V_151 ;
}
int F_119 ( struct V_15 * V_16 ,
const T_1 * V_7 )
{
struct V_3 * V_4 ;
int V_151 ;
F_84 ( & V_16 -> V_2 -> V_8 ) ;
V_4 = F_35 ( V_16 , V_7 ) ;
V_151 = F_108 ( V_4 ) ;
F_80 ( & V_16 -> V_2 -> V_8 ) ;
return V_151 ;
}
static void F_120 ( unsigned long V_155 )
{
struct V_1 * V_2 = (struct V_1 * ) V_155 ;
struct V_3 * V_4 ;
bool V_156 = false ;
F_79 () ;
F_37 (sta, &local->sta_list, list)
if ( F_107 ( V_2 , V_4 ) )
V_156 = true ;
F_87 () ;
if ( V_2 -> V_157 )
return;
if ( ! V_156 )
return;
F_121 ( & V_2 -> V_158 ,
F_122 ( V_69 + V_159 ) ) ;
}
void F_123 ( struct V_1 * V_2 )
{
F_53 ( & V_2 -> V_135 ) ;
F_55 ( & V_2 -> V_8 ) ;
F_124 ( & V_2 -> V_112 ) ;
F_125 ( & V_2 -> V_158 , F_120 ,
( unsigned long ) V_2 ) ;
}
void F_126 ( struct V_1 * V_2 )
{
F_127 ( & V_2 -> V_158 ) ;
}
int F_128 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 , * V_160 ;
int V_151 = 0 ;
F_83 () ;
F_84 ( & V_2 -> V_8 ) ;
F_129 (sta, tmp, &local->sta_list, list) {
if ( V_16 == V_4 -> V_16 ) {
F_64 ( F_108 ( V_4 ) ) ;
V_151 ++ ;
}
}
F_80 ( & V_2 -> V_8 ) ;
return V_151 ;
}
void F_130 ( struct V_15 * V_16 )
{
F_20 ( V_16 ) ;
F_16 ( & V_16 -> V_42 ) ;
}
void F_131 ( struct V_15 * V_16 ,
unsigned long V_161 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 , * V_160 ;
F_84 ( & V_2 -> V_8 ) ;
F_129 (sta, tmp, &local->sta_list, list) {
if ( V_16 != V_4 -> V_16 )
continue;
if ( F_99 ( V_69 , V_4 -> V_68 + V_161 ) ) {
F_39 ( V_4 -> V_16 , L_7 ,
V_4 -> V_4 . V_7 ) ;
if ( F_9 ( & V_16 -> V_20 ) &&
F_8 ( V_4 , V_19 ) )
F_11 ( & V_16 -> V_24 . V_25 . V_18 . V_26 ) ;
F_64 ( F_108 ( V_4 ) ) ;
}
}
F_80 ( & V_2 -> V_8 ) ;
}
struct V_162 * F_132 ( struct V_163 * V_30 ,
const T_1 * V_7 ,
const T_1 * V_164 )
{
struct V_3 * V_4 , * V_165 ;
F_133 (hw_to_local(hw), addr, sta, nxt) {
if ( V_164 &&
! F_34 ( V_4 -> V_16 -> V_20 . V_7 , V_164 ) )
continue;
if ( ! V_4 -> V_104 )
return NULL ;
return & V_4 -> V_4 ;
}
return NULL ;
}
struct V_162 * F_134 ( struct V_166 * V_20 ,
const T_1 * V_7 )
{
struct V_3 * V_4 ;
if ( ! V_20 )
return NULL ;
V_4 = F_35 ( F_135 ( V_20 ) , V_7 ) ;
if ( ! V_4 )
return NULL ;
if ( ! V_4 -> V_104 )
return NULL ;
return & V_4 -> V_4 ;
}
static void F_136 ( void * V_167 )
{
struct V_3 * V_4 = V_167 ;
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_17 * V_18 ;
if ( V_16 -> V_20 . type == V_21 ||
V_16 -> V_20 . type == V_22 )
V_18 = & V_16 -> V_23 -> V_18 ;
else if ( F_9 ( & V_16 -> V_20 ) )
V_18 = & V_16 -> V_24 . V_25 . V_18 ;
else
return;
F_10 ( V_4 , V_49 ) ;
if ( F_46 ( V_4 , V_19 ) )
F_11 ( & V_18 -> V_26 ) ;
}
void F_44 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_168 V_36 ;
int V_169 = 0 , V_170 = 0 , V_11 ;
unsigned long V_52 ;
F_10 ( V_4 , V_171 ) ;
F_137 ( F_138 ( V_33 ) > 1 ) ;
V_4 -> V_134 = 0 ;
if ( ! ( V_2 -> V_30 . V_52 & V_131 ) )
F_139 ( V_2 , V_16 , V_172 , & V_4 -> V_4 ) ;
F_61 ( & V_36 ) ;
for ( V_11 = 0 ; V_11 < V_27 ; V_11 ++ ) {
int V_173 = F_13 ( & V_36 ) , V_160 ;
F_101 ( & V_4 -> V_31 [ V_11 ] . V_59 , V_52 ) ;
F_140 ( & V_4 -> V_31 [ V_11 ] , & V_36 ) ;
F_104 ( & V_4 -> V_31 [ V_11 ] . V_59 , V_52 ) ;
V_160 = F_13 ( & V_36 ) ;
V_169 += V_160 - V_173 ;
V_173 = V_160 ;
F_101 ( & V_4 -> V_29 [ V_11 ] . V_59 , V_52 ) ;
F_140 ( & V_4 -> V_29 [ V_11 ] , & V_36 ) ;
F_104 ( & V_4 -> V_29 [ V_11 ] . V_59 , V_52 ) ;
V_160 = F_13 ( & V_36 ) ;
V_170 += V_160 - V_173 ;
}
F_141 ( V_2 , & V_36 , F_136 , V_4 ) ;
if ( ! F_142 ( V_4 -> V_91 ,
V_16 -> V_79 ) &&
V_4 -> V_91 != V_16 -> V_23 -> V_174 &&
F_143 ( V_4 ) != 1 ) {
F_144 ( V_16 ,
L_8 ,
V_4 -> V_4 . V_7 ) ;
F_145 ( V_16 , V_16 -> V_23 -> V_174 ,
V_4 -> V_4 . V_7 ,
V_16 -> V_20 . V_145 . V_175 ) ;
}
V_2 -> V_28 -= V_170 ;
F_12 ( V_4 ) ;
F_106 ( V_16 ,
L_9 ,
V_4 -> V_4 . V_7 , V_4 -> V_4 . V_128 , V_169 , V_170 ) ;
}
static void F_146 ( struct V_15 * V_16 ,
struct V_3 * V_4 , int V_176 ,
enum V_177 V_178 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_179 * V_180 ;
struct V_139 * V_140 ;
int V_181 = sizeof( * V_180 ) ;
T_6 V_182 ;
bool V_183 = F_8 ( V_4 , V_184 ) ;
struct V_141 * V_142 ;
struct V_185 * V_186 ;
if ( V_183 ) {
V_182 = F_62 ( V_187 |
V_188 |
V_189 ) ;
} else {
V_181 -= 2 ;
V_182 = F_62 ( V_187 |
V_190 |
V_189 ) ;
}
V_140 = F_147 ( V_2 -> V_30 . V_191 + V_181 ) ;
if ( ! V_140 )
return;
F_148 ( V_140 , V_2 -> V_30 . V_191 ) ;
V_180 = ( void * ) F_149 ( V_140 , V_181 ) ;
V_180 -> V_192 = V_182 ;
V_180 -> V_193 = 0 ;
memcpy ( V_180 -> V_194 , V_4 -> V_4 . V_7 , V_67 ) ;
memcpy ( V_180 -> V_195 , V_16 -> V_20 . V_7 , V_67 ) ;
memcpy ( V_180 -> V_196 , V_16 -> V_20 . V_7 , V_67 ) ;
V_140 -> V_197 = V_176 ;
F_150 ( V_140 , V_198 [ V_176 ] ) ;
if ( V_183 ) {
V_180 -> V_199 = F_62 ( V_176 ) ;
if ( V_178 == V_200 )
V_180 -> V_199 |=
F_62 ( V_201 ) ;
}
V_142 = F_98 ( V_140 ) ;
V_142 -> V_52 |= V_202 |
V_203 |
V_204 |
V_205 ;
F_151 ( V_2 , V_4 , F_92 ( V_176 ) , 1 , V_178 , false ) ;
V_140 -> V_116 = V_16 -> V_116 ;
F_79 () ;
V_186 = F_152 ( V_16 -> V_20 . V_186 ) ;
if ( F_64 ( ! V_186 ) ) {
F_87 () ;
F_153 ( V_140 ) ;
return;
}
F_154 ( V_16 , V_140 , V_186 -> V_206 . V_207 -> V_208 ) ;
F_87 () ;
}
static void
F_155 ( struct V_3 * V_4 ,
int V_209 , T_1 V_210 ,
enum V_177 V_178 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_2 ;
bool V_211 = false ;
bool V_212 = false ;
int V_11 ;
unsigned long V_213 = 0 ;
struct V_168 V_214 ;
F_75 ( V_4 , V_171 ) ;
F_156 ( & V_214 ) ;
for ( V_11 = 0 ; V_11 < V_27 ; V_11 ++ ) {
unsigned long V_133 ;
if ( V_210 & F_92 ( V_11 ) )
continue;
V_133 = F_91 ( V_11 ) ;
if ( ! V_211 ) {
V_213 = V_4 -> V_134 & V_133 ;
if ( V_213 ) {
V_211 = true ;
} else {
struct V_139 * V_140 ;
while ( V_209 > 0 ) {
V_140 = F_157 ( & V_4 -> V_31 [ V_11 ] ) ;
if ( ! V_140 ) {
V_140 = F_157 (
& V_4 -> V_29 [ V_11 ] ) ;
if ( V_140 )
V_2 -> V_28 -- ;
}
if ( ! V_140 )
break;
V_209 -- ;
V_211 = true ;
F_158 ( & V_214 , V_140 ) ;
}
}
if ( V_178 == V_215 &&
F_159 ( V_213 ) > 1 ) {
V_212 = true ;
V_213 =
F_92 ( F_160 ( V_213 ) - 1 ) ;
break;
}
}
if ( ! F_95 ( & V_4 -> V_31 [ V_11 ] ) ||
! F_95 ( & V_4 -> V_29 [ V_11 ] ) ) {
V_212 = true ;
break;
}
}
if ( ! V_211 ) {
int V_176 ;
V_176 = 7 - ( ( F_160 ( ~ V_210 ) - 1 ) << 1 ) ;
F_146 ( V_16 , V_4 , V_176 , V_178 ) ;
return;
}
if ( ! V_213 ) {
struct V_168 V_36 ;
struct V_139 * V_140 ;
int V_216 = 0 ;
T_4 V_133 = 0 ;
F_61 ( & V_36 ) ;
while ( ( V_140 = F_103 ( & V_214 ) ) ) {
struct V_141 * V_142 = F_98 ( V_140 ) ;
struct V_217 * V_218 = ( void * ) V_140 -> V_155 ;
T_1 * V_219 = NULL ;
V_216 ++ ;
V_142 -> V_52 |= V_202 |
V_203 ;
if ( V_212 || ! F_95 ( & V_214 ) )
V_218 -> V_192 |=
F_62 ( V_220 ) ;
else
V_218 -> V_192 &=
F_62 ( ~ V_220 ) ;
if ( F_161 ( V_218 -> V_192 ) ||
F_162 ( V_218 -> V_192 ) )
V_219 = F_163 ( V_218 ) ;
if ( F_95 ( & V_214 ) ) {
if ( V_178 == V_200 &&
V_219 )
* V_219 |= V_201 ;
V_142 -> V_52 |= V_204 |
V_205 ;
}
if ( V_219 )
V_133 |= F_92 ( * V_219 & V_221 ) ;
else
V_133 |= F_92 ( 0 ) ;
F_158 ( & V_36 , V_140 ) ;
}
F_151 ( V_2 , V_4 , V_133 , V_216 ,
V_178 , V_212 ) ;
F_164 ( V_2 , & V_36 ) ;
F_12 ( V_4 ) ;
} else {
F_165 ( V_2 , V_4 , V_213 ,
V_209 , V_178 , V_212 ) ;
}
}
void F_47 ( struct V_3 * V_4 )
{
T_1 V_222 = V_4 -> V_4 . V_127 ;
if ( V_222 == F_92 ( V_27 ) - 1 )
V_222 = 0 ;
F_155 ( V_4 , 1 , V_222 ,
V_215 ) ;
}
void F_48 ( struct V_3 * V_4 )
{
int V_209 = V_4 -> V_4 . V_223 ;
T_1 V_224 = V_4 -> V_4 . V_127 ;
if ( ! V_224 )
return;
switch ( V_4 -> V_4 . V_223 ) {
case 1 :
V_209 = 2 ;
break;
case 2 :
V_209 = 4 ;
break;
case 3 :
V_209 = 6 ;
break;
case 0 :
V_209 = 8 ;
break;
}
F_155 ( V_4 , V_209 , ~ V_224 ,
V_200 ) ;
}
void F_166 ( struct V_163 * V_30 ,
struct V_162 * V_225 , bool V_226 )
{
struct V_3 * V_4 = F_27 ( V_225 , struct V_3 , V_4 ) ;
F_167 ( V_4 -> V_2 , V_225 , V_226 ) ;
if ( V_226 )
F_75 ( V_4 , V_49 ) ;
else if ( F_8 ( V_4 , V_49 ) )
F_31 ( V_30 , & V_4 -> V_32 ) ;
}
void F_168 ( struct V_162 * V_225 )
{
struct V_3 * V_4 = F_27 ( V_225 , struct V_3 , V_4 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_169 ( V_2 , V_225 ) ;
F_10 ( V_4 , V_171 ) ;
}
void F_170 ( struct V_162 * V_225 ,
T_1 V_176 , bool V_170 )
{
struct V_3 * V_4 = F_27 ( V_225 , struct V_3 , V_4 ) ;
if ( F_64 ( V_176 >= V_33 ) )
return;
if ( V_170 )
F_171 ( V_176 , & V_4 -> V_134 ) ;
else
F_172 ( V_176 , & V_4 -> V_134 ) ;
F_12 ( V_4 ) ;
}
int F_113 ( struct V_3 * V_4 ,
enum V_98 V_227 )
{
F_83 () ;
if ( V_4 -> V_70 == V_227 )
return 0 ;
switch ( V_227 ) {
case V_71 :
if ( V_4 -> V_70 != V_228 )
return - V_97 ;
break;
case V_228 :
if ( V_4 -> V_70 != V_71 &&
V_4 -> V_70 != V_229 )
return - V_97 ;
break;
case V_229 :
if ( V_4 -> V_70 != V_228 &&
V_4 -> V_70 != V_230 )
return - V_97 ;
break;
case V_230 :
if ( V_4 -> V_70 != V_229 )
return - V_97 ;
break;
default:
F_173 ( 1 , L_10 , V_227 ) ;
return - V_97 ;
}
F_39 ( V_4 -> V_16 , L_11 ,
V_4 -> V_4 . V_7 , V_227 ) ;
if ( F_8 ( V_4 , V_113 ) ) {
int V_100 = F_70 ( V_4 -> V_2 , V_4 -> V_16 , V_4 ,
V_4 -> V_70 , V_227 ) ;
if ( V_100 )
return V_100 ;
}
switch ( V_227 ) {
case V_71 :
if ( V_4 -> V_70 == V_228 )
F_172 ( V_231 , & V_4 -> V_232 ) ;
break;
case V_228 :
if ( V_4 -> V_70 == V_71 )
F_171 ( V_231 , & V_4 -> V_232 ) ;
else if ( V_4 -> V_70 == V_229 )
F_172 ( V_233 , & V_4 -> V_232 ) ;
break;
case V_229 :
if ( V_4 -> V_70 == V_228 ) {
F_171 ( V_233 , & V_4 -> V_232 ) ;
} else if ( V_4 -> V_70 == V_230 ) {
if ( V_4 -> V_16 -> V_20 . type == V_21 ||
( V_4 -> V_16 -> V_20 . type == V_22 &&
! V_4 -> V_16 -> V_24 . V_154 . V_4 ) )
F_11 ( & V_4 -> V_16 -> V_23 -> V_234 ) ;
F_172 ( V_235 , & V_4 -> V_232 ) ;
}
break;
case V_230 :
if ( V_4 -> V_70 == V_229 ) {
if ( V_4 -> V_16 -> V_20 . type == V_21 ||
( V_4 -> V_16 -> V_20 . type == V_22 &&
! V_4 -> V_16 -> V_24 . V_154 . V_4 ) )
F_174 ( & V_4 -> V_16 -> V_23 -> V_234 ) ;
F_171 ( V_235 , & V_4 -> V_232 ) ;
}
break;
default:
break;
}
V_4 -> V_70 = V_227 ;
return 0 ;
}
T_1 F_143 ( struct V_3 * V_4 )
{
struct V_236 * V_86 = & V_4 -> V_4 . V_86 ;
T_1 V_237 ;
if ( ! V_4 -> V_4 . V_86 . V_238 )
return 1 ;
if ( V_4 -> V_4 . V_239 . V_240 ) {
int V_12 ;
T_4 V_241 =
F_94 ( V_4 -> V_4 . V_239 . V_242 . V_241 ) ;
for ( V_12 = 7 ; V_12 >= 0 ; V_12 -- )
if ( ( V_241 & ( 0x3 << ( V_12 * 2 ) ) ) !=
V_243 )
return V_12 + 1 ;
}
if ( V_86 -> V_244 . V_245 [ 3 ] )
V_237 = 4 ;
else if ( V_86 -> V_244 . V_245 [ 2 ] )
V_237 = 3 ;
else if ( V_86 -> V_244 . V_245 [ 1 ] )
V_237 = 2 ;
else
V_237 = 1 ;
if ( ! ( V_86 -> V_244 . V_246 & V_247 ) )
return V_237 ;
return ( ( V_86 -> V_244 . V_246 & V_248 )
>> V_249 ) + 1 ;
}
