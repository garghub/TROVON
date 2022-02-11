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
struct V_3 * F_7 ( struct V_11 * V_12 ,
const T_1 * V_7 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 ;
V_4 = F_8 ( V_2 -> V_6 [ F_3 ( V_7 ) ] ,
F_4 ( & V_2 -> V_8 ) ) ;
while ( V_4 ) {
if ( V_4 -> V_12 == V_12 &&
F_9 ( V_4 -> V_4 . V_7 , V_7 ) == 0 )
break;
V_4 = F_8 ( V_4 -> V_10 ,
F_4 ( & V_2 -> V_8 ) ) ;
}
return V_4 ;
}
struct V_3 * F_10 ( struct V_11 * V_12 ,
const T_1 * V_7 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 ;
V_4 = F_8 ( V_2 -> V_6 [ F_3 ( V_7 ) ] ,
F_4 ( & V_2 -> V_8 ) ) ;
while ( V_4 ) {
if ( ( V_4 -> V_12 == V_12 ||
( V_4 -> V_12 -> V_13 && V_4 -> V_12 -> V_13 == V_12 -> V_13 ) ) &&
F_9 ( V_4 -> V_4 . V_7 , V_7 ) == 0 )
break;
V_4 = F_8 ( V_4 -> V_10 ,
F_4 ( & V_2 -> V_8 ) ) ;
}
return V_4 ;
}
struct V_3 * F_11 ( struct V_11 * V_12 ,
int V_14 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 ;
int V_15 = 0 ;
F_12 (sta, &local->sta_list, list) {
if ( V_12 != V_4 -> V_12 )
continue;
if ( V_15 < V_14 ) {
++ V_15 ;
continue;
}
return V_4 ;
}
return NULL ;
}
void F_13 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_16 )
F_14 ( V_4 ) ;
#ifdef F_15
F_16 ( V_2 -> V_17 . V_18 , L_1 , V_4 -> V_4 . V_7 ) ;
#endif
F_17 ( V_4 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_19 ( & V_2 -> V_8 ) ;
V_4 -> V_10 = V_2 -> V_6 [ F_3 ( V_4 -> V_4 . V_7 ) ] ;
F_5 ( V_2 -> V_6 [ F_3 ( V_4 -> V_4 . V_7 ) ] , V_4 ) ;
}
static void F_20 ( struct V_19 * V_20 )
{
struct V_3 * V_4 ;
V_4 = F_21 ( V_20 , struct V_3 , V_21 ) ;
if ( V_4 -> V_22 )
return;
if ( ! F_22 ( V_4 , V_23 ) ) {
F_23 () ;
F_24 ( V_4 ) ;
F_25 () ;
} else if ( F_26 ( V_4 , V_24 ) ) {
F_27 ( V_4 , V_25 ) ;
F_23 () ;
F_28 ( V_4 ) ;
F_25 () ;
} else if ( F_26 ( V_4 , V_26 ) ) {
F_27 ( V_4 , V_25 ) ;
F_23 () ;
F_29 ( V_4 ) ;
F_25 () ;
} else
F_27 ( V_4 , V_25 ) ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 V_27 )
{
if ( V_2 -> V_17 . V_28 & V_29 )
return 0 ;
V_4 -> V_16 = V_2 -> V_16 ;
V_4 -> V_30 = F_31 ( V_4 -> V_16 ,
& V_4 -> V_4 , V_27 ) ;
if ( ! V_4 -> V_30 )
return - V_31 ;
return 0 ;
}
struct V_3 * F_32 ( struct V_11 * V_12 ,
const T_1 * V_7 , T_2 V_27 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 ;
struct V_32 V_33 ;
int V_15 ;
V_4 = F_33 ( sizeof( * V_4 ) + V_2 -> V_17 . V_34 , V_27 ) ;
if ( ! V_4 )
return NULL ;
F_34 ( & V_4 -> V_35 ) ;
F_35 ( & V_4 -> V_21 , F_20 ) ;
F_35 ( & V_4 -> V_36 . V_37 , V_38 ) ;
F_36 ( & V_4 -> V_36 . V_39 ) ;
memcpy ( V_4 -> V_4 . V_7 , V_7 , V_40 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_12 = V_12 ;
V_4 -> V_41 = V_42 ;
V_4 -> V_43 = V_44 ;
F_37 ( & V_33 ) ;
V_4 -> V_45 = V_33 . V_46 ;
F_38 ( & V_4 -> V_47 , 1024 , 8 ) ;
if ( F_30 ( V_2 , V_4 , V_27 ) ) {
F_17 ( V_4 ) ;
return NULL ;
}
for ( V_15 = 0 ; V_15 < V_48 ; V_15 ++ ) {
V_4 -> V_49 [ V_15 ] = V_15 ;
}
for ( V_15 = 0 ; V_15 < V_50 ; V_15 ++ ) {
F_39 ( & V_4 -> V_51 [ V_15 ] ) ;
F_39 ( & V_4 -> V_52 [ V_15 ] ) ;
}
for ( V_15 = 0 ; V_15 < V_53 ; V_15 ++ )
V_4 -> V_54 [ V_15 ] = F_40 ( V_55 ) ;
#ifdef F_15
F_16 ( V_2 -> V_17 . V_18 , L_2 , V_4 -> V_4 . V_7 ) ;
#endif
#ifdef F_41
V_4 -> V_56 = V_57 ;
F_42 ( & V_4 -> V_58 ) ;
#endif
return V_4 ;
}
static int F_43 ( struct V_3 * V_4 )
{
struct V_11 * V_12 = V_4 -> V_12 ;
if ( F_44 ( ! F_45 ( V_12 ) ) )
return - V_59 ;
if ( F_46 ( F_9 ( V_4 -> V_4 . V_7 , V_12 -> V_60 . V_7 ) == 0 ||
F_47 ( V_4 -> V_4 . V_7 ) ) )
return - V_61 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_3 * V_4 )
{
enum V_62 V_63 ;
int V_64 = 0 ;
for ( V_63 = V_65 ; V_63 < V_4 -> V_43 ; V_63 ++ ) {
V_64 = F_49 ( V_2 , V_12 , V_4 , V_63 , V_63 + 1 ) ;
if ( V_64 )
break;
}
if ( ! V_64 ) {
if ( ! V_2 -> V_66 -> V_67 )
V_4 -> V_68 = true ;
return 0 ;
}
if ( V_12 -> V_60 . type == V_69 ) {
F_50 ( V_70
L_3 ,
V_12 -> V_71 , V_4 -> V_4 . V_7 , V_63 + 1 , V_64 ) ;
V_64 = 0 ;
}
for (; V_63 > V_65 ; V_63 -- )
F_46 ( F_49 ( V_2 , V_12 , V_4 , V_63 , V_63 - 1 ) ) ;
return V_64 ;
}
static int F_51 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_11 * V_12 = V_4 -> V_12 ;
struct V_72 V_73 ;
int V_64 = 0 ;
F_19 ( & V_2 -> V_8 ) ;
if ( F_10 ( V_12 , V_4 -> V_4 . V_7 ) ) {
V_64 = - V_74 ;
goto V_75;
}
V_64 = F_48 ( V_2 , V_12 , V_4 ) ;
if ( V_64 )
goto V_75;
V_2 -> V_76 ++ ;
V_2 -> V_77 ++ ;
F_52 () ;
F_18 ( V_2 , V_4 ) ;
F_53 ( & V_4 -> V_78 , & V_2 -> V_79 ) ;
F_54 ( V_4 , V_80 ) ;
F_55 ( V_4 ) ;
F_56 ( V_4 ) ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
V_73 . V_81 = 0 ;
V_73 . V_82 = V_2 -> V_77 ;
F_57 ( V_12 -> V_83 , V_4 -> V_4 . V_7 , & V_73 , V_84 ) ;
#ifdef F_15
F_16 ( V_2 -> V_17 . V_18 , L_4 , V_4 -> V_4 . V_7 ) ;
#endif
F_58 () ;
F_59 ( & V_2 -> V_8 ) ;
if ( F_60 ( & V_12 -> V_60 ) )
F_61 ( V_12 ) ;
return 0 ;
V_75:
F_59 ( & V_2 -> V_8 ) ;
F_58 () ;
return V_64 ;
}
int F_62 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_64 = 0 ;
F_63 () ;
V_64 = F_43 ( V_4 ) ;
if ( V_64 ) {
F_58 () ;
goto V_85;
}
F_64 ( & V_2 -> V_8 ) ;
V_64 = F_51 ( V_4 ) ;
if ( V_64 )
goto V_85;
return 0 ;
V_85:
F_65 ( ! V_64 ) ;
F_13 ( V_2 , V_4 ) ;
return V_64 ;
}
int F_66 ( struct V_3 * V_4 )
{
int V_64 = F_62 ( V_4 ) ;
F_67 () ;
return V_64 ;
}
static inline void F_68 ( struct V_86 * V_13 , T_4 V_87 )
{
V_13 -> V_88 [ V_87 / 8 ] |= ( 1 << ( V_87 % 8 ) ) ;
}
static inline void F_69 ( struct V_86 * V_13 , T_4 V_87 )
{
V_13 -> V_88 [ V_87 / 8 ] &= ~ ( 1 << ( V_87 % 8 ) ) ;
}
static unsigned long F_70 ( int V_89 )
{
switch ( V_89 ) {
case V_90 :
return F_71 ( 6 ) | F_71 ( 7 ) ;
case V_91 :
return F_71 ( 4 ) | F_71 ( 5 ) ;
case V_92 :
return F_71 ( 0 ) | F_71 ( 3 ) ;
case V_93 :
return F_71 ( 1 ) | F_71 ( 2 ) ;
default:
F_46 ( 1 ) ;
return 0 ;
}
}
void F_72 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_86 * V_13 = V_4 -> V_12 -> V_13 ;
unsigned long V_28 ;
bool V_94 = false ;
T_1 V_95 = V_4 -> V_4 . V_96 ;
int V_89 ;
if ( F_73 ( ! V_4 -> V_12 -> V_13 ) )
return;
if ( V_2 -> V_17 . V_28 & V_97 )
return;
if ( V_4 -> V_22 )
goto V_98;
if ( V_95 == F_71 ( V_50 ) - 1 )
V_95 = 0 ;
for ( V_89 = 0 ; V_89 < V_50 ; V_89 ++ ) {
unsigned long V_99 ;
if ( V_95 & F_71 ( V_89 ) )
continue;
V_94 |= ! F_74 ( & V_4 -> V_52 [ V_89 ] ) ||
! F_74 ( & V_4 -> V_51 [ V_89 ] ) ;
if ( V_94 )
break;
V_99 = F_70 ( V_89 ) ;
V_94 |=
V_4 -> V_100 & V_99 ;
}
V_98:
F_75 ( & V_2 -> V_101 , V_28 ) ;
if ( V_94 )
F_68 ( V_13 , V_4 -> V_4 . V_87 ) ;
else
F_69 ( V_13 , V_4 -> V_4 . V_87 ) ;
if ( V_2 -> V_66 -> V_102 ) {
V_2 -> V_103 = true ;
F_76 ( V_2 , & V_4 -> V_4 , V_94 ) ;
V_2 -> V_103 = false ;
}
F_77 ( & V_2 -> V_101 , V_28 ) ;
}
static bool F_78 ( struct V_3 * V_4 , struct V_104 * V_105 )
{
struct V_106 * V_107 ;
int V_108 ;
if ( ! V_105 )
return false ;
V_107 = F_79 ( V_105 ) ;
V_108 = ( V_4 -> V_109 *
V_4 -> V_12 -> V_60 . V_110 . V_111 *
32 / 15625 ) * V_112 ;
if ( V_108 < V_113 )
V_108 = V_113 ;
return F_80 ( V_42 , V_107 -> V_114 . V_42 + V_108 ) ;
}
static bool F_81 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_89 )
{
unsigned long V_28 ;
struct V_104 * V_105 ;
for (; ; ) {
F_75 ( & V_4 -> V_52 [ V_89 ] . V_35 , V_28 ) ;
V_105 = F_82 ( & V_4 -> V_52 [ V_89 ] ) ;
if ( F_78 ( V_4 , V_105 ) )
V_105 = F_83 ( & V_4 -> V_52 [ V_89 ] ) ;
else
V_105 = NULL ;
F_77 ( & V_4 -> V_52 [ V_89 ] . V_35 , V_28 ) ;
if ( ! V_105 )
break;
F_84 ( V_105 ) ;
}
for (; ; ) {
F_75 ( & V_4 -> V_51 [ V_89 ] . V_35 , V_28 ) ;
V_105 = F_82 ( & V_4 -> V_51 [ V_89 ] ) ;
if ( F_78 ( V_4 , V_105 ) )
V_105 = F_83 ( & V_4 -> V_51 [ V_89 ] ) ;
else
V_105 = NULL ;
F_77 ( & V_4 -> V_51 [ V_89 ] . V_35 , V_28 ) ;
if ( ! V_105 )
break;
V_2 -> V_115 -- ;
#ifdef F_85
F_50 ( V_70 L_5 ,
V_4 -> V_4 . V_7 ) ;
#endif
F_84 ( V_105 ) ;
}
F_72 ( V_4 ) ;
return ! ( F_74 ( & V_4 -> V_51 [ V_89 ] ) &&
F_74 ( & V_4 -> V_52 [ V_89 ] ) ) ;
}
static bool F_86 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_116 = false ;
int V_89 ;
if ( ! V_4 -> V_12 -> V_13 )
return false ;
for ( V_89 = 0 ; V_89 < V_50 ; V_89 ++ )
V_116 |=
F_81 ( V_2 , V_4 , V_89 ) ;
return V_116 ;
}
int T_5 F_87 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
int V_117 , V_15 , V_89 ;
struct V_118 * V_119 ;
F_63 () ;
if ( ! V_4 )
return - V_9 ;
V_2 = V_4 -> V_2 ;
V_12 = V_4 -> V_12 ;
F_19 ( & V_2 -> V_8 ) ;
F_54 ( V_4 , V_120 ) ;
F_88 ( V_4 , true ) ;
V_117 = F_1 ( V_2 , V_4 ) ;
if ( V_117 )
return V_117 ;
F_89 ( & V_4 -> V_78 ) ;
F_64 ( & V_2 -> V_121 ) ;
for ( V_15 = 0 ; V_15 < V_122 ; V_15 ++ )
F_90 ( F_91 ( V_2 , V_4 -> V_123 [ V_15 ] ) ) ;
if ( V_4 -> V_124 )
F_90 ( F_91 ( V_2 , V_4 -> V_124 ) ) ;
F_59 ( & V_2 -> V_121 ) ;
V_4 -> V_22 = true ;
V_2 -> V_76 -- ;
V_2 -> V_77 ++ ;
if ( V_12 -> V_60 . type == V_125 )
F_92 ( V_12 -> V_126 . V_127 . V_4 , NULL ) ;
while ( V_4 -> V_43 > V_44 ) {
V_117 = F_93 ( V_4 , V_4 -> V_43 - 1 ) ;
if ( V_117 ) {
F_73 ( 1 ) ;
break;
}
}
if ( V_4 -> V_68 ) {
V_117 = F_49 ( V_2 , V_12 , V_4 , V_44 ,
V_65 ) ;
F_73 ( V_117 != 0 ) ;
}
F_94 () ;
if ( F_22 ( V_4 , V_23 ) ) {
F_65 ( ! V_12 -> V_13 ) ;
F_27 ( V_4 , V_23 ) ;
F_95 ( & V_12 -> V_13 -> V_128 ) ;
F_72 ( V_4 ) ;
}
for ( V_89 = 0 ; V_89 < V_50 ; V_89 ++ ) {
V_2 -> V_115 -= F_96 ( & V_4 -> V_51 [ V_89 ] ) ;
F_97 ( & V_4 -> V_51 [ V_89 ] ) ;
F_97 ( & V_4 -> V_52 [ V_89 ] ) ;
}
#ifdef F_41
if ( F_60 ( & V_12 -> V_60 ) )
F_61 ( V_12 ) ;
#endif
#ifdef F_15
F_16 ( V_2 -> V_17 . V_18 , L_6 , V_4 -> V_4 . V_7 ) ;
#endif
F_98 ( & V_4 -> V_21 ) ;
F_99 ( V_12 -> V_83 , V_4 -> V_4 . V_7 , V_84 ) ;
F_100 ( V_4 ) ;
F_101 ( V_4 ) ;
#ifdef F_41
if ( F_60 ( & V_4 -> V_12 -> V_60 ) ) {
F_102 ( V_4 ) ;
F_103 ( & V_4 -> V_58 ) ;
}
#endif
for ( V_15 = 0 ; V_15 < V_48 ; V_15 ++ ) {
V_119 = F_104 ( V_4 -> V_36 . V_119 [ V_15 ] ) ;
if ( ! V_119 )
continue;
F_97 ( & V_119 -> V_129 ) ;
F_17 ( V_119 ) ;
}
F_13 ( V_2 , V_4 ) ;
return 0 ;
}
int F_105 ( struct V_11 * V_12 , const T_1 * V_7 )
{
struct V_3 * V_4 ;
int V_117 ;
F_64 ( & V_12 -> V_2 -> V_8 ) ;
V_4 = F_7 ( V_12 , V_7 ) ;
V_117 = F_87 ( V_4 ) ;
F_59 ( & V_12 -> V_2 -> V_8 ) ;
return V_117 ;
}
int F_106 ( struct V_11 * V_12 ,
const T_1 * V_7 )
{
struct V_3 * V_4 ;
int V_117 ;
F_64 ( & V_12 -> V_2 -> V_8 ) ;
V_4 = F_10 ( V_12 , V_7 ) ;
V_117 = F_87 ( V_4 ) ;
F_59 ( & V_12 -> V_2 -> V_8 ) ;
return V_117 ;
}
static void F_107 ( unsigned long V_130 )
{
struct V_1 * V_2 = (struct V_1 * ) V_130 ;
struct V_3 * V_4 ;
bool V_131 = false ;
F_58 () ;
F_12 (sta, &local->sta_list, list)
if ( F_86 ( V_2 , V_4 ) )
V_131 = true ;
F_67 () ;
if ( V_2 -> V_132 )
return;
if ( ! V_131 )
return;
F_108 ( & V_2 -> V_133 ,
F_109 ( V_42 + V_134 ) ) ;
}
void F_110 ( struct V_1 * V_2 )
{
F_34 ( & V_2 -> V_101 ) ;
F_36 ( & V_2 -> V_8 ) ;
F_111 ( & V_2 -> V_79 ) ;
F_112 ( & V_2 -> V_133 , F_107 ,
( unsigned long ) V_2 ) ;
}
void F_113 ( struct V_1 * V_2 )
{
F_114 ( & V_2 -> V_133 ) ;
F_115 ( V_2 , NULL ) ;
}
int F_115 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_3 * V_4 , * V_135 ;
int V_117 = 0 ;
F_63 () ;
F_64 ( & V_2 -> V_8 ) ;
F_116 (sta, tmp, &local->sta_list, list) {
if ( ! V_12 || V_12 == V_4 -> V_12 ) {
F_46 ( F_87 ( V_4 ) ) ;
V_117 ++ ;
}
}
F_59 ( & V_2 -> V_8 ) ;
return V_117 ;
}
void F_117 ( struct V_11 * V_12 ,
unsigned long V_136 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 , * V_135 ;
F_64 ( & V_2 -> V_8 ) ;
F_116 (sta, tmp, &local->sta_list, list) {
if ( V_12 != V_4 -> V_12 )
continue;
if ( F_80 ( V_42 , V_4 -> V_41 + V_136 ) ) {
#ifdef F_118
F_50 ( V_70 L_7 ,
V_12 -> V_71 , V_4 -> V_4 . V_7 ) ;
#endif
F_46 ( F_87 ( V_4 ) ) ;
}
}
F_59 ( & V_2 -> V_8 ) ;
}
struct V_137 * F_119 ( struct V_138 * V_17 ,
const T_1 * V_7 ,
const T_1 * V_139 )
{
struct V_3 * V_4 , * V_140 ;
F_120 (hw_to_local(hw), addr, sta, nxt) {
if ( V_139 &&
F_9 ( V_4 -> V_12 -> V_60 . V_7 , V_139 ) != 0 )
continue;
if ( ! V_4 -> V_68 )
return NULL ;
return & V_4 -> V_4 ;
}
return NULL ;
}
struct V_137 * F_121 ( struct V_141 * V_60 ,
const T_1 * V_7 )
{
struct V_3 * V_4 ;
if ( ! V_60 )
return NULL ;
V_4 = F_10 ( F_122 ( V_60 ) , V_7 ) ;
if ( ! V_4 )
return NULL ;
if ( ! V_4 -> V_68 )
return NULL ;
return & V_4 -> V_4 ;
}
static void F_123 ( void * V_142 )
{
struct V_3 * V_4 = V_142 ;
struct V_11 * V_12 = V_4 -> V_12 ;
F_27 ( V_4 , V_25 ) ;
if ( F_26 ( V_4 , V_23 ) )
F_95 ( & V_12 -> V_13 -> V_128 ) ;
}
void F_24 ( struct V_3 * V_4 )
{
struct V_11 * V_12 = V_4 -> V_12 ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_143 V_129 ;
int V_144 = 0 , V_145 = 0 , V_89 ;
F_27 ( V_4 , V_146 ) ;
F_124 ( F_125 ( V_48 ) > 1 ) ;
V_4 -> V_100 = 0 ;
if ( ! ( V_2 -> V_17 . V_28 & V_97 ) )
F_126 ( V_2 , V_12 , V_147 , & V_4 -> V_4 ) ;
F_39 ( & V_129 ) ;
for ( V_89 = 0 ; V_89 < V_50 ; V_89 ++ ) {
int V_148 = F_96 ( & V_129 ) , V_135 ;
F_127 ( & V_4 -> V_52 [ V_89 ] , & V_129 ) ;
V_135 = F_96 ( & V_129 ) ;
V_144 += V_135 - V_148 ;
V_148 = V_135 ;
F_127 ( & V_4 -> V_51 [ V_89 ] , & V_129 ) ;
V_135 = F_96 ( & V_129 ) ;
V_145 += V_135 - V_148 ;
}
F_128 ( V_2 , & V_129 , F_123 , V_4 ) ;
V_2 -> V_115 -= V_145 ;
F_72 ( V_4 ) ;
#ifdef F_85
F_50 ( V_70 L_8
L_9 , V_12 -> V_71 ,
V_4 -> V_4 . V_7 , V_4 -> V_4 . V_87 , V_144 , V_145 ) ;
#endif
}
static void F_129 ( struct V_11 * V_12 ,
struct V_3 * V_4 , int V_149 ,
enum V_150 V_151 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_152 * V_153 ;
struct V_104 * V_105 ;
int V_154 = sizeof( * V_153 ) ;
T_6 V_155 ;
bool V_156 = F_22 ( V_4 , V_157 ) ;
struct V_106 * V_107 ;
if ( V_156 ) {
V_155 = F_40 ( V_158 |
V_159 |
V_160 ) ;
} else {
V_154 -= 2 ;
V_155 = F_40 ( V_158 |
V_161 |
V_160 ) ;
}
V_105 = F_130 ( V_2 -> V_17 . V_162 + V_154 ) ;
if ( ! V_105 )
return;
F_131 ( V_105 , V_2 -> V_17 . V_162 ) ;
V_153 = ( void * ) F_132 ( V_105 , V_154 ) ;
V_153 -> V_163 = V_155 ;
V_153 -> V_164 = 0 ;
memcpy ( V_153 -> V_165 , V_4 -> V_4 . V_7 , V_40 ) ;
memcpy ( V_153 -> V_166 , V_12 -> V_60 . V_7 , V_40 ) ;
memcpy ( V_153 -> V_167 , V_12 -> V_60 . V_7 , V_40 ) ;
V_105 -> V_168 = V_149 ;
F_133 ( V_105 , V_169 [ V_149 ] ) ;
if ( V_156 ) {
V_153 -> V_170 = F_40 ( V_149 ) ;
if ( V_151 == V_171 )
V_153 -> V_170 |=
F_40 ( V_172 ) ;
}
V_107 = F_79 ( V_105 ) ;
V_107 -> V_28 |= V_173 |
V_174 |
V_175 ;
F_134 ( V_2 , V_4 , F_71 ( V_149 ) , 1 , V_151 , false ) ;
F_135 ( V_12 , V_105 ) ;
}
static void
F_136 ( struct V_3 * V_4 ,
int V_176 , T_1 V_177 ,
enum V_150 V_151 )
{
struct V_11 * V_12 = V_4 -> V_12 ;
struct V_1 * V_2 = V_12 -> V_2 ;
bool V_178 = false ;
bool V_179 = false ;
int V_89 ;
unsigned long V_180 = 0 ;
struct V_143 V_181 ;
F_54 ( V_4 , V_146 ) ;
F_137 ( & V_181 ) ;
for ( V_89 = 0 ; V_89 < V_50 ; V_89 ++ ) {
unsigned long V_99 ;
if ( V_177 & F_71 ( V_89 ) )
continue;
V_99 = F_70 ( V_89 ) ;
if ( ! V_178 ) {
V_180 = V_4 -> V_100 & V_99 ;
if ( V_180 ) {
V_178 = true ;
} else {
struct V_104 * V_105 ;
while ( V_176 > 0 ) {
V_105 = F_138 ( & V_4 -> V_52 [ V_89 ] ) ;
if ( ! V_105 ) {
V_105 = F_138 (
& V_4 -> V_51 [ V_89 ] ) ;
if ( V_105 )
V_2 -> V_115 -- ;
}
if ( ! V_105 )
break;
V_176 -- ;
V_178 = true ;
F_139 ( & V_181 , V_105 ) ;
}
}
if ( V_151 == V_182 &&
F_140 ( V_180 ) > 1 ) {
V_179 = true ;
V_180 =
F_71 ( F_141 ( V_180 ) - 1 ) ;
break;
}
}
if ( ! F_74 ( & V_4 -> V_52 [ V_89 ] ) ||
! F_74 ( & V_4 -> V_51 [ V_89 ] ) ) {
V_179 = true ;
break;
}
}
if ( ! V_178 ) {
int V_149 ;
V_149 = 7 - ( ( F_141 ( ~ V_177 ) - 1 ) << 1 ) ;
F_129 ( V_12 , V_4 , V_149 , V_151 ) ;
return;
}
if ( ! V_180 ) {
struct V_143 V_129 ;
struct V_104 * V_105 ;
int V_183 = 0 ;
T_4 V_99 = 0 ;
F_39 ( & V_129 ) ;
while ( ( V_105 = F_83 ( & V_181 ) ) ) {
struct V_106 * V_107 = F_79 ( V_105 ) ;
struct V_184 * V_185 = ( void * ) V_105 -> V_130 ;
T_1 * V_186 = NULL ;
V_183 ++ ;
V_107 -> V_28 |= V_173 ;
if ( V_179 || ! F_74 ( & V_181 ) )
V_185 -> V_163 |=
F_40 ( V_187 ) ;
else
V_185 -> V_163 &=
F_40 ( ~ V_187 ) ;
if ( F_142 ( V_185 -> V_163 ) ||
F_143 ( V_185 -> V_163 ) )
V_186 = F_144 ( V_185 ) ;
if ( V_151 == V_171 &&
V_186 && F_74 ( & V_181 ) )
* V_186 |= V_172 ;
V_107 -> V_28 |= V_174 |
V_175 ;
if ( V_186 )
V_99 |= F_71 ( * V_186 & V_188 ) ;
else
V_99 |= F_71 ( 0 ) ;
F_139 ( & V_129 , V_105 ) ;
}
F_134 ( V_2 , V_4 , V_99 , V_183 ,
V_151 , V_179 ) ;
F_145 ( V_2 , & V_129 ) ;
F_72 ( V_4 ) ;
} else {
F_146 ( V_2 , V_4 , V_180 ,
V_176 , V_151 , V_179 ) ;
}
}
void F_28 ( struct V_3 * V_4 )
{
T_1 V_189 = V_4 -> V_4 . V_96 ;
if ( V_189 == F_71 ( V_50 ) - 1 )
V_189 = 0 ;
F_136 ( V_4 , 1 , V_189 ,
V_182 ) ;
}
void F_29 ( struct V_3 * V_4 )
{
int V_176 = V_4 -> V_4 . V_190 ;
T_1 V_191 = V_4 -> V_4 . V_96 ;
if ( ! V_191 )
return;
switch ( V_4 -> V_4 . V_190 ) {
case 1 :
V_176 = 2 ;
break;
case 2 :
V_176 = 4 ;
break;
case 3 :
V_176 = 6 ;
break;
case 0 :
V_176 = 8 ;
break;
}
F_136 ( V_4 , V_176 , ~ V_191 ,
V_171 ) ;
}
void F_147 ( struct V_138 * V_17 ,
struct V_137 * V_192 , bool V_193 )
{
struct V_3 * V_4 = F_21 ( V_192 , struct V_3 , V_4 ) ;
F_148 ( V_4 -> V_2 , V_192 , V_193 ) ;
if ( V_193 )
F_54 ( V_4 , V_25 ) ;
else if ( F_22 ( V_4 , V_25 ) )
F_149 ( V_17 , & V_4 -> V_21 ) ;
}
void F_150 ( struct V_137 * V_192 )
{
struct V_3 * V_4 = F_21 ( V_192 , struct V_3 , V_4 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_104 * V_105 ;
struct V_194 * V_130 ;
F_151 ( V_2 , V_192 ) ;
V_105 = F_152 ( 0 , V_195 ) ;
if ( ! V_105 ) {
F_27 ( V_4 , V_146 ) ;
return;
}
V_130 = ( void * ) V_105 -> V_196 ;
memcpy ( V_130 -> V_4 , V_192 -> V_7 , V_40 ) ;
memcpy ( V_130 -> V_197 , V_4 -> V_12 -> V_60 . V_7 , V_40 ) ;
V_105 -> V_198 = V_199 ;
F_153 ( & V_2 -> V_200 , V_105 ) ;
F_154 ( & V_2 -> V_201 ) ;
}
void F_155 ( struct V_137 * V_192 ,
T_1 V_149 , bool V_145 )
{
struct V_3 * V_4 = F_21 ( V_192 , struct V_3 , V_4 ) ;
if ( F_46 ( V_149 >= V_48 ) )
return;
if ( V_145 )
F_156 ( V_149 , & V_4 -> V_100 ) ;
else
F_157 ( V_149 , & V_4 -> V_100 ) ;
F_72 ( V_4 ) ;
}
int F_93 ( struct V_3 * V_4 ,
enum V_62 V_202 )
{
F_63 () ;
if ( V_4 -> V_43 == V_202 )
return 0 ;
switch ( V_202 ) {
case V_44 :
if ( V_4 -> V_43 != V_203 )
return - V_61 ;
break;
case V_203 :
if ( V_4 -> V_43 != V_44 &&
V_4 -> V_43 != V_204 )
return - V_61 ;
break;
case V_204 :
if ( V_4 -> V_43 != V_203 &&
V_4 -> V_43 != V_205 )
return - V_61 ;
break;
case V_205 :
if ( V_4 -> V_43 != V_204 )
return - V_61 ;
break;
default:
F_158 ( 1 , L_10 , V_202 ) ;
return - V_61 ;
}
#ifdef F_15
F_50 ( V_70 L_11 ,
V_4 -> V_12 -> V_71 , V_4 -> V_4 . V_7 , V_202 ) ;
#endif
if ( F_22 ( V_4 , V_80 ) ) {
int V_64 = F_49 ( V_4 -> V_2 , V_4 -> V_12 , V_4 ,
V_4 -> V_43 , V_202 ) ;
if ( V_64 )
return V_64 ;
}
switch ( V_202 ) {
case V_44 :
if ( V_4 -> V_43 == V_203 )
F_157 ( V_206 , & V_4 -> V_207 ) ;
break;
case V_203 :
if ( V_4 -> V_43 == V_44 )
F_156 ( V_206 , & V_4 -> V_207 ) ;
else if ( V_4 -> V_43 == V_204 )
F_157 ( V_208 , & V_4 -> V_207 ) ;
break;
case V_204 :
if ( V_4 -> V_43 == V_203 ) {
F_156 ( V_208 , & V_4 -> V_207 ) ;
} else if ( V_4 -> V_43 == V_205 ) {
if ( V_4 -> V_12 -> V_60 . type == V_209 )
F_95 ( & V_4 -> V_12 -> V_126 . V_210 . V_211 ) ;
F_157 ( V_212 , & V_4 -> V_207 ) ;
}
break;
case V_205 :
if ( V_4 -> V_43 == V_204 ) {
if ( V_4 -> V_12 -> V_60 . type == V_209 )
F_159 ( & V_4 -> V_12 -> V_126 . V_210 . V_211 ) ;
F_156 ( V_212 , & V_4 -> V_207 ) ;
}
break;
default:
break;
}
V_4 -> V_43 = V_202 ;
return 0 ;
}
