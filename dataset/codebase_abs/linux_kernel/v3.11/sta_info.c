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
F_39 ( V_16 , L_2 , V_4 -> V_4 . V_7 ) ;
return V_4 ;
}
static int F_63 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
if ( F_64 ( ! F_65 ( V_16 ) ) )
return - V_81 ;
if ( F_66 ( F_34 ( V_4 -> V_4 . V_7 , V_16 -> V_20 . V_7 ) ||
F_67 ( V_4 -> V_4 . V_7 ) ) )
return - V_82 ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_3 * V_4 )
{
enum V_83 V_84 ;
int V_85 = 0 ;
for ( V_84 = V_86 ; V_84 < V_4 -> V_70 ; V_84 ++ ) {
V_85 = F_69 ( V_2 , V_16 , V_4 , V_84 , V_84 + 1 ) ;
if ( V_85 )
break;
}
if ( ! V_85 ) {
if ( ! V_2 -> V_87 -> V_88 )
V_4 -> V_89 = true ;
return 0 ;
}
if ( V_16 -> V_20 . type == V_90 ) {
F_70 ( V_16 ,
L_3 ,
V_4 -> V_4 . V_7 , V_84 + 1 , V_85 ) ;
V_85 = 0 ;
}
for (; V_84 > V_86 ; V_84 -- )
F_66 ( F_69 ( V_2 , V_16 , V_4 , V_84 , V_84 - 1 ) ) ;
return V_85 ;
}
static int F_71 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_91 V_92 ;
int V_85 = 0 ;
F_41 ( & V_2 -> V_8 ) ;
if ( F_35 ( V_16 , V_4 -> V_4 . V_7 ) ) {
V_85 = - V_93 ;
goto V_94;
}
V_85 = F_68 ( V_2 , V_16 , V_4 ) ;
if ( V_85 )
goto V_94;
V_2 -> V_95 ++ ;
V_2 -> V_96 ++ ;
F_72 () ;
F_40 ( V_2 , V_4 ) ;
F_73 ( & V_4 -> V_39 , & V_2 -> V_97 ) ;
F_74 ( V_4 , V_98 ) ;
F_75 ( V_4 ) ;
F_76 ( V_4 ) ;
memset ( & V_92 , 0 , sizeof( V_92 ) ) ;
V_92 . V_99 = 0 ;
V_92 . V_100 = V_2 -> V_96 ;
F_77 ( V_16 -> V_101 , V_4 -> V_4 . V_7 , & V_92 , V_102 ) ;
F_39 ( V_16 , L_4 , V_4 -> V_4 . V_7 ) ;
F_78 () ;
F_79 ( & V_2 -> V_8 ) ;
if ( F_9 ( & V_16 -> V_20 ) )
F_80 ( V_16 ) ;
return 0 ;
V_94:
F_79 ( & V_2 -> V_8 ) ;
F_78 () ;
return V_85 ;
}
int F_81 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_85 = 0 ;
F_82 () ;
V_85 = F_63 ( V_4 ) ;
if ( V_85 ) {
F_78 () ;
goto V_103;
}
F_83 ( & V_2 -> V_8 ) ;
V_85 = F_71 ( V_4 ) ;
if ( V_85 )
goto V_103;
return 0 ;
V_103:
F_84 ( ! V_85 ) ;
F_19 ( V_2 , V_4 ) ;
return V_85 ;
}
int F_85 ( struct V_3 * V_4 )
{
int V_85 = F_81 ( V_4 ) ;
F_86 () ;
return V_85 ;
}
static inline void F_87 ( T_1 * V_104 , T_4 V_105 )
{
V_104 [ V_105 / 8 ] |= ( 1 << ( V_105 % 8 ) ) ;
}
static inline void F_88 ( T_1 * V_104 , T_4 V_105 )
{
V_104 [ V_105 / 8 ] &= ~ ( 1 << ( V_105 % 8 ) ) ;
}
static inline bool F_89 ( T_1 * V_104 , T_4 V_105 )
{
return V_104 [ V_105 / 8 ] & ( 1 << ( V_105 % 8 ) ) ;
}
static unsigned long F_90 ( int V_11 )
{
switch ( V_11 ) {
case V_106 :
return F_91 ( 6 ) | F_91 ( 7 ) ;
case V_107 :
return F_91 ( 4 ) | F_91 ( 5 ) ;
case V_108 :
return F_91 ( 0 ) | F_91 ( 3 ) ;
case V_109 :
return F_91 ( 1 ) | F_91 ( 2 ) ;
default:
F_66 ( 1 ) ;
return 0 ;
}
}
void F_12 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_17 * V_18 ;
bool V_110 = false ;
T_1 V_111 = V_4 -> V_4 . V_112 ;
int V_11 ;
T_4 V_105 ;
if ( V_4 -> V_16 -> V_20 . type == V_21 ||
V_4 -> V_16 -> V_20 . type == V_22 ) {
if ( F_92 ( ! V_4 -> V_16 -> V_23 ) )
return;
V_18 = & V_4 -> V_16 -> V_23 -> V_18 ;
V_105 = V_4 -> V_4 . V_113 ;
#ifdef F_56
} else if ( F_9 ( & V_4 -> V_16 -> V_20 ) ) {
V_18 = & V_4 -> V_16 -> V_24 . V_25 . V_18 ;
V_105 = F_93 ( V_4 -> V_114 ) % V_115 ;
#endif
} else {
return;
}
if ( V_2 -> V_30 . V_52 & V_116 )
return;
if ( V_4 -> V_47 )
goto V_117;
if ( V_111 == F_91 ( V_27 ) - 1 )
V_111 = 0 ;
for ( V_11 = 0 ; V_11 < V_27 ; V_11 ++ ) {
unsigned long V_118 ;
if ( V_111 & F_91 ( V_11 ) )
continue;
V_110 |= ! F_94 ( & V_4 -> V_31 [ V_11 ] ) ||
! F_94 ( & V_4 -> V_29 [ V_11 ] ) ;
if ( V_110 )
break;
V_118 = F_90 ( V_11 ) ;
V_110 |=
V_4 -> V_119 & V_118 ;
}
V_117:
F_21 ( & V_2 -> V_120 ) ;
if ( V_110 == F_89 ( V_18 -> V_104 , V_105 ) )
goto V_121;
if ( V_110 )
F_87 ( V_18 -> V_104 , V_105 ) ;
else
F_88 ( V_18 -> V_104 , V_105 ) ;
if ( V_2 -> V_87 -> V_122 ) {
V_2 -> V_123 = true ;
F_95 ( V_2 , & V_4 -> V_4 , V_110 ) ;
V_2 -> V_123 = false ;
}
V_121:
F_25 ( & V_2 -> V_120 ) ;
}
static bool F_96 ( struct V_3 * V_4 , struct V_124 * V_125 )
{
struct V_126 * V_127 ;
int V_128 ;
if ( ! V_125 )
return false ;
V_127 = F_97 ( V_125 ) ;
V_128 = ( V_4 -> V_129 *
V_4 -> V_16 -> V_20 . V_130 . V_131 *
32 / 15625 ) * V_132 ;
if ( V_128 < V_133 )
V_128 = V_133 ;
return F_98 ( V_69 , V_127 -> V_134 . V_69 + V_128 ) ;
}
static bool F_99 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_11 )
{
unsigned long V_52 ;
struct V_124 * V_125 ;
for (; ; ) {
F_100 ( & V_4 -> V_31 [ V_11 ] . V_59 , V_52 ) ;
V_125 = F_101 ( & V_4 -> V_31 [ V_11 ] ) ;
if ( F_96 ( V_4 , V_125 ) )
V_125 = F_102 ( & V_4 -> V_31 [ V_11 ] ) ;
else
V_125 = NULL ;
F_103 ( & V_4 -> V_31 [ V_11 ] . V_59 , V_52 ) ;
if ( ! V_125 )
break;
F_104 ( & V_2 -> V_30 , V_125 ) ;
}
for (; ; ) {
F_100 ( & V_4 -> V_29 [ V_11 ] . V_59 , V_52 ) ;
V_125 = F_101 ( & V_4 -> V_29 [ V_11 ] ) ;
if ( F_96 ( V_4 , V_125 ) )
V_125 = F_102 ( & V_4 -> V_29 [ V_11 ] ) ;
else
V_125 = NULL ;
F_103 ( & V_4 -> V_29 [ V_11 ] . V_59 , V_52 ) ;
if ( ! V_125 )
break;
V_2 -> V_28 -- ;
F_105 ( V_4 -> V_16 , L_5 ,
V_4 -> V_4 . V_7 ) ;
F_104 ( & V_2 -> V_30 , V_125 ) ;
}
F_12 ( V_4 ) ;
return ! ( F_94 ( & V_4 -> V_29 [ V_11 ] ) &&
F_94 ( & V_4 -> V_31 [ V_11 ] ) ) ;
}
static bool F_106 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_135 = false ;
int V_11 ;
if ( ! V_4 -> V_16 -> V_23 &&
! F_9 ( & V_4 -> V_16 -> V_20 ) )
return false ;
for ( V_11 = 0 ; V_11 < V_27 ; V_11 ++ )
V_135 |=
F_99 ( V_2 , V_4 , V_11 ) ;
return V_135 ;
}
int T_5 F_107 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_15 * V_16 ;
int V_136 ;
F_82 () ;
if ( ! V_4 )
return - V_9 ;
V_2 = V_4 -> V_2 ;
V_16 = V_4 -> V_16 ;
F_41 ( & V_2 -> V_8 ) ;
F_74 ( V_4 , V_137 ) ;
F_108 ( V_4 , V_138 ) ;
V_136 = F_1 ( V_2 , V_4 ) ;
if ( V_136 )
return V_136 ;
F_109 ( & V_4 -> V_39 ) ;
F_110 ( V_2 , V_4 ) ;
V_4 -> V_47 = true ;
V_2 -> V_95 -- ;
V_2 -> V_96 ++ ;
if ( V_16 -> V_20 . type == V_22 )
F_111 ( V_16 -> V_24 . V_139 . V_4 , NULL ) ;
while ( V_4 -> V_70 > V_71 ) {
V_136 = F_112 ( V_4 , V_4 -> V_70 - 1 ) ;
if ( V_136 ) {
F_92 ( 1 ) ;
break;
}
}
if ( V_4 -> V_89 ) {
V_136 = F_69 ( V_2 , V_16 , V_4 , V_71 ,
V_86 ) ;
F_92 ( V_136 != 0 ) ;
}
F_39 ( V_16 , L_6 , V_4 -> V_4 . V_7 ) ;
F_113 ( V_16 -> V_101 , V_4 -> V_4 . V_7 , V_102 ) ;
F_114 ( V_4 ) ;
F_115 ( V_4 ) ;
F_116 ( & V_4 -> V_40 , F_26 ) ;
return 0 ;
}
int F_117 ( struct V_15 * V_16 , const T_1 * V_7 )
{
struct V_3 * V_4 ;
int V_136 ;
F_83 ( & V_16 -> V_2 -> V_8 ) ;
V_4 = F_32 ( V_16 , V_7 ) ;
V_136 = F_107 ( V_4 ) ;
F_79 ( & V_16 -> V_2 -> V_8 ) ;
return V_136 ;
}
int F_118 ( struct V_15 * V_16 ,
const T_1 * V_7 )
{
struct V_3 * V_4 ;
int V_136 ;
F_83 ( & V_16 -> V_2 -> V_8 ) ;
V_4 = F_35 ( V_16 , V_7 ) ;
V_136 = F_107 ( V_4 ) ;
F_79 ( & V_16 -> V_2 -> V_8 ) ;
return V_136 ;
}
static void F_119 ( unsigned long V_140 )
{
struct V_1 * V_2 = (struct V_1 * ) V_140 ;
struct V_3 * V_4 ;
bool V_141 = false ;
F_78 () ;
F_37 (sta, &local->sta_list, list)
if ( F_106 ( V_2 , V_4 ) )
V_141 = true ;
F_86 () ;
if ( V_2 -> V_142 )
return;
if ( ! V_141 )
return;
F_120 ( & V_2 -> V_143 ,
F_121 ( V_69 + V_144 ) ) ;
}
void F_122 ( struct V_1 * V_2 )
{
F_53 ( & V_2 -> V_120 ) ;
F_55 ( & V_2 -> V_8 ) ;
F_123 ( & V_2 -> V_97 ) ;
F_124 ( & V_2 -> V_143 , F_119 ,
( unsigned long ) V_2 ) ;
}
void F_125 ( struct V_1 * V_2 )
{
F_126 ( & V_2 -> V_143 ) ;
}
int F_127 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 , * V_145 ;
int V_136 = 0 ;
F_82 () ;
F_83 ( & V_2 -> V_8 ) ;
F_128 (sta, tmp, &local->sta_list, list) {
if ( V_16 == V_4 -> V_16 ) {
F_66 ( F_107 ( V_4 ) ) ;
V_136 ++ ;
}
}
F_79 ( & V_2 -> V_8 ) ;
return V_136 ;
}
void F_129 ( struct V_15 * V_16 )
{
F_20 ( V_16 ) ;
F_16 ( & V_16 -> V_42 ) ;
}
void F_130 ( struct V_15 * V_16 ,
unsigned long V_146 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 , * V_145 ;
F_83 ( & V_2 -> V_8 ) ;
F_128 (sta, tmp, &local->sta_list, list) {
if ( V_16 != V_4 -> V_16 )
continue;
if ( F_98 ( V_69 , V_4 -> V_68 + V_146 ) ) {
F_39 ( V_4 -> V_16 , L_7 ,
V_4 -> V_4 . V_7 ) ;
if ( F_9 ( & V_16 -> V_20 ) &&
F_8 ( V_4 , V_19 ) )
F_11 ( & V_16 -> V_24 . V_25 . V_18 . V_26 ) ;
F_66 ( F_107 ( V_4 ) ) ;
}
}
F_79 ( & V_2 -> V_8 ) ;
}
struct V_147 * F_131 ( struct V_148 * V_30 ,
const T_1 * V_7 ,
const T_1 * V_149 )
{
struct V_3 * V_4 , * V_150 ;
F_132 (hw_to_local(hw), addr, sta, nxt) {
if ( V_149 &&
! F_34 ( V_4 -> V_16 -> V_20 . V_7 , V_149 ) )
continue;
if ( ! V_4 -> V_89 )
return NULL ;
return & V_4 -> V_4 ;
}
return NULL ;
}
struct V_147 * F_133 ( struct V_151 * V_20 ,
const T_1 * V_7 )
{
struct V_3 * V_4 ;
if ( ! V_20 )
return NULL ;
V_4 = F_35 ( F_134 ( V_20 ) , V_7 ) ;
if ( ! V_4 )
return NULL ;
if ( ! V_4 -> V_89 )
return NULL ;
return & V_4 -> V_4 ;
}
static void F_135 ( void * V_152 )
{
struct V_3 * V_4 = V_152 ;
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
struct V_153 V_36 ;
int V_154 = 0 , V_155 = 0 , V_11 ;
unsigned long V_52 ;
F_10 ( V_4 , V_156 ) ;
F_136 ( F_137 ( V_33 ) > 1 ) ;
V_4 -> V_119 = 0 ;
if ( ! ( V_2 -> V_30 . V_52 & V_116 ) )
F_138 ( V_2 , V_16 , V_157 , & V_4 -> V_4 ) ;
F_61 ( & V_36 ) ;
for ( V_11 = 0 ; V_11 < V_27 ; V_11 ++ ) {
int V_158 = F_13 ( & V_36 ) , V_145 ;
F_100 ( & V_4 -> V_31 [ V_11 ] . V_59 , V_52 ) ;
F_139 ( & V_4 -> V_31 [ V_11 ] , & V_36 ) ;
F_103 ( & V_4 -> V_31 [ V_11 ] . V_59 , V_52 ) ;
V_145 = F_13 ( & V_36 ) ;
V_154 += V_145 - V_158 ;
V_158 = V_145 ;
F_100 ( & V_4 -> V_29 [ V_11 ] . V_59 , V_52 ) ;
F_139 ( & V_4 -> V_29 [ V_11 ] , & V_36 ) ;
F_103 ( & V_4 -> V_29 [ V_11 ] . V_59 , V_52 ) ;
V_145 = F_13 ( & V_36 ) ;
V_155 += V_145 - V_158 ;
}
F_140 ( V_2 , & V_36 , F_135 , V_4 ) ;
V_2 -> V_28 -= V_155 ;
F_12 ( V_4 ) ;
F_105 ( V_16 ,
L_8 ,
V_4 -> V_4 . V_7 , V_4 -> V_4 . V_113 , V_154 , V_155 ) ;
}
static void F_141 ( struct V_15 * V_16 ,
struct V_3 * V_4 , int V_159 ,
enum V_160 V_161 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_162 * V_163 ;
struct V_124 * V_125 ;
int V_164 = sizeof( * V_163 ) ;
T_6 V_165 ;
bool V_166 = F_8 ( V_4 , V_167 ) ;
struct V_126 * V_127 ;
struct V_168 * V_169 ;
if ( V_166 ) {
V_165 = F_62 ( V_170 |
V_171 |
V_172 ) ;
} else {
V_164 -= 2 ;
V_165 = F_62 ( V_170 |
V_173 |
V_172 ) ;
}
V_125 = F_142 ( V_2 -> V_30 . V_174 + V_164 ) ;
if ( ! V_125 )
return;
F_143 ( V_125 , V_2 -> V_30 . V_174 ) ;
V_163 = ( void * ) F_144 ( V_125 , V_164 ) ;
V_163 -> V_175 = V_165 ;
V_163 -> V_176 = 0 ;
memcpy ( V_163 -> V_177 , V_4 -> V_4 . V_7 , V_67 ) ;
memcpy ( V_163 -> V_178 , V_16 -> V_20 . V_7 , V_67 ) ;
memcpy ( V_163 -> V_179 , V_16 -> V_20 . V_7 , V_67 ) ;
V_125 -> V_180 = V_159 ;
F_145 ( V_125 , V_181 [ V_159 ] ) ;
if ( V_166 ) {
V_163 -> V_182 = F_62 ( V_159 ) ;
if ( V_161 == V_183 )
V_163 -> V_182 |=
F_62 ( V_184 ) ;
}
V_127 = F_97 ( V_125 ) ;
V_127 -> V_52 |= V_185 |
V_186 |
V_187 |
V_188 ;
F_146 ( V_2 , V_4 , F_91 ( V_159 ) , 1 , V_161 , false ) ;
V_125 -> V_101 = V_16 -> V_101 ;
F_78 () ;
V_169 = F_147 ( V_16 -> V_20 . V_169 ) ;
if ( F_66 ( ! V_169 ) ) {
F_86 () ;
F_148 ( V_125 ) ;
return;
}
F_149 ( V_16 , V_125 , V_169 -> V_189 . V_190 -> V_191 ) ;
F_86 () ;
}
static void
F_150 ( struct V_3 * V_4 ,
int V_192 , T_1 V_193 ,
enum V_160 V_161 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_2 ;
bool V_194 = false ;
bool V_195 = false ;
int V_11 ;
unsigned long V_196 = 0 ;
struct V_153 V_197 ;
F_74 ( V_4 , V_156 ) ;
F_151 ( & V_197 ) ;
for ( V_11 = 0 ; V_11 < V_27 ; V_11 ++ ) {
unsigned long V_118 ;
if ( V_193 & F_91 ( V_11 ) )
continue;
V_118 = F_90 ( V_11 ) ;
if ( ! V_194 ) {
V_196 = V_4 -> V_119 & V_118 ;
if ( V_196 ) {
V_194 = true ;
} else {
struct V_124 * V_125 ;
while ( V_192 > 0 ) {
V_125 = F_152 ( & V_4 -> V_31 [ V_11 ] ) ;
if ( ! V_125 ) {
V_125 = F_152 (
& V_4 -> V_29 [ V_11 ] ) ;
if ( V_125 )
V_2 -> V_28 -- ;
}
if ( ! V_125 )
break;
V_192 -- ;
V_194 = true ;
F_153 ( & V_197 , V_125 ) ;
}
}
if ( V_161 == V_198 &&
F_154 ( V_196 ) > 1 ) {
V_195 = true ;
V_196 =
F_91 ( F_155 ( V_196 ) - 1 ) ;
break;
}
}
if ( ! F_94 ( & V_4 -> V_31 [ V_11 ] ) ||
! F_94 ( & V_4 -> V_29 [ V_11 ] ) ) {
V_195 = true ;
break;
}
}
if ( ! V_194 ) {
int V_159 ;
V_159 = 7 - ( ( F_155 ( ~ V_193 ) - 1 ) << 1 ) ;
F_141 ( V_16 , V_4 , V_159 , V_161 ) ;
return;
}
if ( ! V_196 ) {
struct V_153 V_36 ;
struct V_124 * V_125 ;
int V_199 = 0 ;
T_4 V_118 = 0 ;
F_61 ( & V_36 ) ;
while ( ( V_125 = F_102 ( & V_197 ) ) ) {
struct V_126 * V_127 = F_97 ( V_125 ) ;
struct V_200 * V_201 = ( void * ) V_125 -> V_140 ;
T_1 * V_202 = NULL ;
V_199 ++ ;
V_127 -> V_52 |= V_185 |
V_186 ;
if ( V_195 || ! F_94 ( & V_197 ) )
V_201 -> V_175 |=
F_62 ( V_203 ) ;
else
V_201 -> V_175 &=
F_62 ( ~ V_203 ) ;
if ( F_156 ( V_201 -> V_175 ) ||
F_157 ( V_201 -> V_175 ) )
V_202 = F_158 ( V_201 ) ;
if ( F_94 ( & V_197 ) ) {
if ( V_161 == V_183 &&
V_202 )
* V_202 |= V_184 ;
V_127 -> V_52 |= V_187 |
V_188 ;
}
if ( V_202 )
V_118 |= F_91 ( * V_202 & V_204 ) ;
else
V_118 |= F_91 ( 0 ) ;
F_153 ( & V_36 , V_125 ) ;
}
F_146 ( V_2 , V_4 , V_118 , V_199 ,
V_161 , V_195 ) ;
F_159 ( V_2 , & V_36 ) ;
F_12 ( V_4 ) ;
} else {
F_160 ( V_2 , V_4 , V_196 ,
V_192 , V_161 , V_195 ) ;
}
}
void F_47 ( struct V_3 * V_4 )
{
T_1 V_205 = V_4 -> V_4 . V_112 ;
if ( V_205 == F_91 ( V_27 ) - 1 )
V_205 = 0 ;
F_150 ( V_4 , 1 , V_205 ,
V_198 ) ;
}
void F_48 ( struct V_3 * V_4 )
{
int V_192 = V_4 -> V_4 . V_206 ;
T_1 V_207 = V_4 -> V_4 . V_112 ;
if ( ! V_207 )
return;
switch ( V_4 -> V_4 . V_206 ) {
case 1 :
V_192 = 2 ;
break;
case 2 :
V_192 = 4 ;
break;
case 3 :
V_192 = 6 ;
break;
case 0 :
V_192 = 8 ;
break;
}
F_150 ( V_4 , V_192 , ~ V_207 ,
V_183 ) ;
}
void F_161 ( struct V_148 * V_30 ,
struct V_147 * V_208 , bool V_209 )
{
struct V_3 * V_4 = F_27 ( V_208 , struct V_3 , V_4 ) ;
F_162 ( V_4 -> V_2 , V_208 , V_209 ) ;
if ( V_209 )
F_74 ( V_4 , V_49 ) ;
else if ( F_8 ( V_4 , V_49 ) )
F_31 ( V_30 , & V_4 -> V_32 ) ;
}
void F_163 ( struct V_147 * V_208 )
{
struct V_3 * V_4 = F_27 ( V_208 , struct V_3 , V_4 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_164 ( V_2 , V_208 ) ;
F_10 ( V_4 , V_156 ) ;
}
void F_165 ( struct V_147 * V_208 ,
T_1 V_159 , bool V_155 )
{
struct V_3 * V_4 = F_27 ( V_208 , struct V_3 , V_4 ) ;
if ( F_66 ( V_159 >= V_33 ) )
return;
if ( V_155 )
F_166 ( V_159 , & V_4 -> V_119 ) ;
else
F_167 ( V_159 , & V_4 -> V_119 ) ;
F_12 ( V_4 ) ;
}
int F_112 ( struct V_3 * V_4 ,
enum V_83 V_210 )
{
F_82 () ;
if ( V_4 -> V_70 == V_210 )
return 0 ;
switch ( V_210 ) {
case V_71 :
if ( V_4 -> V_70 != V_211 )
return - V_82 ;
break;
case V_211 :
if ( V_4 -> V_70 != V_71 &&
V_4 -> V_70 != V_212 )
return - V_82 ;
break;
case V_212 :
if ( V_4 -> V_70 != V_211 &&
V_4 -> V_70 != V_213 )
return - V_82 ;
break;
case V_213 :
if ( V_4 -> V_70 != V_212 )
return - V_82 ;
break;
default:
F_168 ( 1 , L_9 , V_210 ) ;
return - V_82 ;
}
F_39 ( V_4 -> V_16 , L_10 ,
V_4 -> V_4 . V_7 , V_210 ) ;
if ( F_8 ( V_4 , V_98 ) ) {
int V_85 = F_69 ( V_4 -> V_2 , V_4 -> V_16 , V_4 ,
V_4 -> V_70 , V_210 ) ;
if ( V_85 )
return V_85 ;
}
switch ( V_210 ) {
case V_71 :
if ( V_4 -> V_70 == V_211 )
F_167 ( V_214 , & V_4 -> V_215 ) ;
break;
case V_211 :
if ( V_4 -> V_70 == V_71 )
F_166 ( V_214 , & V_4 -> V_215 ) ;
else if ( V_4 -> V_70 == V_212 )
F_167 ( V_216 , & V_4 -> V_215 ) ;
break;
case V_212 :
if ( V_4 -> V_70 == V_211 ) {
F_166 ( V_216 , & V_4 -> V_215 ) ;
} else if ( V_4 -> V_70 == V_213 ) {
if ( V_4 -> V_16 -> V_20 . type == V_21 ||
( V_4 -> V_16 -> V_20 . type == V_22 &&
! V_4 -> V_16 -> V_24 . V_139 . V_4 ) )
F_11 ( & V_4 -> V_16 -> V_23 -> V_217 ) ;
F_167 ( V_218 , & V_4 -> V_215 ) ;
}
break;
case V_213 :
if ( V_4 -> V_70 == V_212 ) {
if ( V_4 -> V_16 -> V_20 . type == V_21 ||
( V_4 -> V_16 -> V_20 . type == V_22 &&
! V_4 -> V_16 -> V_24 . V_139 . V_4 ) )
F_169 ( & V_4 -> V_16 -> V_23 -> V_217 ) ;
F_166 ( V_218 , & V_4 -> V_215 ) ;
}
break;
default:
break;
}
V_4 -> V_70 = V_210 ;
return 0 ;
}
