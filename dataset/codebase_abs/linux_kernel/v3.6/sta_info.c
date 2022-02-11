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
F_9 ( V_4 -> V_4 . V_7 , V_7 ) )
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
F_9 ( V_4 -> V_4 . V_7 , V_7 ) )
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
F_15 ( V_4 -> V_12 , L_1 , V_4 -> V_4 . V_7 ) ;
F_16 ( V_4 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_18 ( & V_2 -> V_8 ) ;
V_4 -> V_10 = V_2 -> V_6 [ F_3 ( V_4 -> V_4 . V_7 ) ] ;
F_5 ( V_2 -> V_6 [ F_3 ( V_4 -> V_4 . V_7 ) ] , V_4 ) ;
}
static void F_19 ( struct V_17 * V_18 )
{
struct V_3 * V_4 ;
V_4 = F_20 ( V_18 , struct V_3 , V_19 ) ;
if ( V_4 -> V_20 )
return;
if ( ! F_21 ( V_4 , V_21 ) ) {
F_22 () ;
F_23 ( V_4 ) ;
F_24 () ;
} else if ( F_25 ( V_4 , V_22 ) ) {
F_26 ( V_4 , V_23 ) ;
F_22 () ;
F_27 ( V_4 ) ;
F_24 () ;
} else if ( F_25 ( V_4 , V_24 ) ) {
F_26 ( V_4 , V_23 ) ;
F_22 () ;
F_28 ( V_4 ) ;
F_24 () ;
} else
F_26 ( V_4 , V_23 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 V_25 )
{
if ( V_2 -> V_26 . V_27 & V_28 )
return 0 ;
V_4 -> V_16 = V_2 -> V_16 ;
V_4 -> V_29 = F_30 ( V_4 -> V_16 ,
& V_4 -> V_4 , V_25 ) ;
if ( ! V_4 -> V_29 )
return - V_30 ;
return 0 ;
}
struct V_3 * F_31 ( struct V_11 * V_12 ,
const T_1 * V_7 , T_2 V_25 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 ;
struct V_31 V_32 ;
int V_15 ;
V_4 = F_32 ( sizeof( * V_4 ) + V_2 -> V_26 . V_33 , V_25 ) ;
if ( ! V_4 )
return NULL ;
F_33 ( & V_4 -> V_34 ) ;
F_34 ( & V_4 -> V_19 , F_19 ) ;
F_34 ( & V_4 -> V_35 . V_36 , V_37 ) ;
F_35 ( & V_4 -> V_35 . V_38 ) ;
memcpy ( V_4 -> V_4 . V_7 , V_7 , V_39 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_12 = V_12 ;
V_4 -> V_40 = V_41 ;
V_4 -> V_42 = V_43 ;
F_36 ( & V_32 ) ;
V_4 -> V_44 = V_32 . V_45 ;
F_37 ( & V_4 -> V_46 , 1024 , 8 ) ;
if ( F_29 ( V_2 , V_4 , V_25 ) ) {
F_16 ( V_4 ) ;
return NULL ;
}
for ( V_15 = 0 ; V_15 < V_47 ; V_15 ++ ) {
V_4 -> V_48 [ V_15 ] = V_15 ;
}
for ( V_15 = 0 ; V_15 < V_49 ; V_15 ++ ) {
F_38 ( & V_4 -> V_50 [ V_15 ] ) ;
F_38 ( & V_4 -> V_51 [ V_15 ] ) ;
}
for ( V_15 = 0 ; V_15 < V_52 ; V_15 ++ )
V_4 -> V_53 [ V_15 ] = F_39 ( V_54 ) ;
F_15 ( V_12 , L_2 , V_4 -> V_4 . V_7 ) ;
#ifdef F_40
V_4 -> V_55 = V_56 ;
F_41 ( & V_4 -> V_57 ) ;
#endif
return V_4 ;
}
static int F_42 ( struct V_3 * V_4 )
{
struct V_11 * V_12 = V_4 -> V_12 ;
if ( F_43 ( ! F_44 ( V_12 ) ) )
return - V_58 ;
if ( F_45 ( F_9 ( V_4 -> V_4 . V_7 , V_12 -> V_59 . V_7 ) ||
F_46 ( V_4 -> V_4 . V_7 ) ) )
return - V_60 ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_3 * V_4 )
{
enum V_61 V_62 ;
int V_63 = 0 ;
for ( V_62 = V_64 ; V_62 < V_4 -> V_42 ; V_62 ++ ) {
V_63 = F_48 ( V_2 , V_12 , V_4 , V_62 , V_62 + 1 ) ;
if ( V_63 )
break;
}
if ( ! V_63 ) {
if ( ! V_2 -> V_65 -> V_66 )
V_4 -> V_67 = true ;
return 0 ;
}
if ( V_12 -> V_59 . type == V_68 ) {
F_49 ( V_12 ,
L_3 ,
V_4 -> V_4 . V_7 , V_62 + 1 , V_63 ) ;
V_63 = 0 ;
}
for (; V_62 > V_64 ; V_62 -- )
F_45 ( F_48 ( V_2 , V_12 , V_4 , V_62 , V_62 - 1 ) ) ;
return V_63 ;
}
static int F_50 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_11 * V_12 = V_4 -> V_12 ;
struct V_69 V_70 ;
int V_63 = 0 ;
F_18 ( & V_2 -> V_8 ) ;
if ( F_10 ( V_12 , V_4 -> V_4 . V_7 ) ) {
V_63 = - V_71 ;
goto V_72;
}
V_63 = F_47 ( V_2 , V_12 , V_4 ) ;
if ( V_63 )
goto V_72;
V_2 -> V_73 ++ ;
V_2 -> V_74 ++ ;
F_51 () ;
F_17 ( V_2 , V_4 ) ;
F_52 ( & V_4 -> V_75 , & V_2 -> V_76 ) ;
F_53 ( V_4 , V_77 ) ;
F_54 ( V_4 ) ;
F_55 ( V_4 ) ;
memset ( & V_70 , 0 , sizeof( V_70 ) ) ;
V_70 . V_78 = 0 ;
V_70 . V_79 = V_2 -> V_74 ;
F_56 ( V_12 -> V_80 , V_4 -> V_4 . V_7 , & V_70 , V_81 ) ;
F_15 ( V_12 , L_4 , V_4 -> V_4 . V_7 ) ;
F_57 () ;
F_58 ( & V_2 -> V_8 ) ;
if ( F_59 ( & V_12 -> V_59 ) )
F_60 ( V_12 ) ;
return 0 ;
V_72:
F_58 ( & V_2 -> V_8 ) ;
F_57 () ;
return V_63 ;
}
int F_61 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_63 = 0 ;
F_62 () ;
V_63 = F_42 ( V_4 ) ;
if ( V_63 ) {
F_57 () ;
goto V_82;
}
F_63 ( & V_2 -> V_8 ) ;
V_63 = F_50 ( V_4 ) ;
if ( V_63 )
goto V_82;
return 0 ;
V_82:
F_64 ( ! V_63 ) ;
F_13 ( V_2 , V_4 ) ;
return V_63 ;
}
int F_65 ( struct V_3 * V_4 )
{
int V_63 = F_61 ( V_4 ) ;
F_66 () ;
return V_63 ;
}
static inline void F_67 ( struct V_83 * V_13 , T_4 V_84 )
{
V_13 -> V_85 [ V_84 / 8 ] |= ( 1 << ( V_84 % 8 ) ) ;
}
static inline void F_68 ( struct V_83 * V_13 , T_4 V_84 )
{
V_13 -> V_85 [ V_84 / 8 ] &= ~ ( 1 << ( V_84 % 8 ) ) ;
}
static unsigned long F_69 ( int V_86 )
{
switch ( V_86 ) {
case V_87 :
return F_70 ( 6 ) | F_70 ( 7 ) ;
case V_88 :
return F_70 ( 4 ) | F_70 ( 5 ) ;
case V_89 :
return F_70 ( 0 ) | F_70 ( 3 ) ;
case V_90 :
return F_70 ( 1 ) | F_70 ( 2 ) ;
default:
F_45 ( 1 ) ;
return 0 ;
}
}
void F_71 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_83 * V_13 = V_4 -> V_12 -> V_13 ;
unsigned long V_27 ;
bool V_91 = false ;
T_1 V_92 = V_4 -> V_4 . V_93 ;
int V_86 ;
if ( F_72 ( ! V_4 -> V_12 -> V_13 ) )
return;
if ( V_2 -> V_26 . V_27 & V_94 )
return;
if ( V_4 -> V_20 )
goto V_95;
if ( V_92 == F_70 ( V_49 ) - 1 )
V_92 = 0 ;
for ( V_86 = 0 ; V_86 < V_49 ; V_86 ++ ) {
unsigned long V_96 ;
if ( V_92 & F_70 ( V_86 ) )
continue;
V_91 |= ! F_73 ( & V_4 -> V_51 [ V_86 ] ) ||
! F_73 ( & V_4 -> V_50 [ V_86 ] ) ;
if ( V_91 )
break;
V_96 = F_69 ( V_86 ) ;
V_91 |=
V_4 -> V_97 & V_96 ;
}
V_95:
F_74 ( & V_2 -> V_98 , V_27 ) ;
if ( V_91 )
F_67 ( V_13 , V_4 -> V_4 . V_84 ) ;
else
F_68 ( V_13 , V_4 -> V_4 . V_84 ) ;
if ( V_2 -> V_65 -> V_99 ) {
V_2 -> V_100 = true ;
F_75 ( V_2 , & V_4 -> V_4 , V_91 ) ;
V_2 -> V_100 = false ;
}
F_76 ( & V_2 -> V_98 , V_27 ) ;
}
static bool F_77 ( struct V_3 * V_4 , struct V_101 * V_102 )
{
struct V_103 * V_104 ;
int V_105 ;
if ( ! V_102 )
return false ;
V_104 = F_78 ( V_102 ) ;
V_105 = ( V_4 -> V_106 *
V_4 -> V_12 -> V_59 . V_107 . V_108 *
32 / 15625 ) * V_109 ;
if ( V_105 < V_110 )
V_105 = V_110 ;
return F_79 ( V_41 , V_104 -> V_111 . V_41 + V_105 ) ;
}
static bool F_80 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_86 )
{
unsigned long V_27 ;
struct V_101 * V_102 ;
for (; ; ) {
F_74 ( & V_4 -> V_51 [ V_86 ] . V_34 , V_27 ) ;
V_102 = F_81 ( & V_4 -> V_51 [ V_86 ] ) ;
if ( F_77 ( V_4 , V_102 ) )
V_102 = F_82 ( & V_4 -> V_51 [ V_86 ] ) ;
else
V_102 = NULL ;
F_76 ( & V_4 -> V_51 [ V_86 ] . V_34 , V_27 ) ;
if ( ! V_102 )
break;
F_83 ( V_102 ) ;
}
for (; ; ) {
F_74 ( & V_4 -> V_50 [ V_86 ] . V_34 , V_27 ) ;
V_102 = F_81 ( & V_4 -> V_50 [ V_86 ] ) ;
if ( F_77 ( V_4 , V_102 ) )
V_102 = F_82 ( & V_4 -> V_50 [ V_86 ] ) ;
else
V_102 = NULL ;
F_76 ( & V_4 -> V_50 [ V_86 ] . V_34 , V_27 ) ;
if ( ! V_102 )
break;
V_2 -> V_112 -- ;
F_84 ( V_4 -> V_12 , L_5 ,
V_4 -> V_4 . V_7 ) ;
F_83 ( V_102 ) ;
}
F_71 ( V_4 ) ;
return ! ( F_73 ( & V_4 -> V_50 [ V_86 ] ) &&
F_73 ( & V_4 -> V_51 [ V_86 ] ) ) ;
}
static bool F_85 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_113 = false ;
int V_86 ;
if ( ! V_4 -> V_12 -> V_13 )
return false ;
for ( V_86 = 0 ; V_86 < V_49 ; V_86 ++ )
V_113 |=
F_80 ( V_2 , V_4 , V_86 ) ;
return V_113 ;
}
int T_5 F_86 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
int V_114 , V_15 , V_86 ;
struct V_115 * V_116 ;
F_62 () ;
if ( ! V_4 )
return - V_9 ;
V_2 = V_4 -> V_2 ;
V_12 = V_4 -> V_12 ;
F_18 ( & V_2 -> V_8 ) ;
F_53 ( V_4 , V_117 ) ;
F_87 ( V_4 , true ) ;
V_114 = F_1 ( V_2 , V_4 ) ;
if ( V_114 )
return V_114 ;
F_88 ( & V_4 -> V_75 ) ;
F_63 ( & V_2 -> V_118 ) ;
for ( V_15 = 0 ; V_15 < V_119 ; V_15 ++ )
F_89 ( F_90 ( V_2 , V_4 -> V_120 [ V_15 ] ) ) ;
if ( V_4 -> V_121 )
F_89 ( F_90 ( V_2 , V_4 -> V_121 ) ) ;
F_58 ( & V_2 -> V_118 ) ;
V_4 -> V_20 = true ;
V_2 -> V_73 -- ;
V_2 -> V_74 ++ ;
if ( V_12 -> V_59 . type == V_122 )
F_91 ( V_12 -> V_123 . V_124 . V_4 , NULL ) ;
while ( V_4 -> V_42 > V_43 ) {
V_114 = F_92 ( V_4 , V_4 -> V_42 - 1 ) ;
if ( V_114 ) {
F_72 ( 1 ) ;
break;
}
}
if ( V_4 -> V_67 ) {
V_114 = F_48 ( V_2 , V_12 , V_4 , V_43 ,
V_64 ) ;
F_72 ( V_114 != 0 ) ;
}
F_93 () ;
if ( F_21 ( V_4 , V_21 ) ) {
F_64 ( ! V_12 -> V_13 ) ;
F_26 ( V_4 , V_21 ) ;
F_94 ( & V_12 -> V_13 -> V_125 ) ;
F_71 ( V_4 ) ;
}
for ( V_86 = 0 ; V_86 < V_49 ; V_86 ++ ) {
V_2 -> V_112 -= F_95 ( & V_4 -> V_50 [ V_86 ] ) ;
F_96 ( & V_4 -> V_50 [ V_86 ] ) ;
F_96 ( & V_4 -> V_51 [ V_86 ] ) ;
}
#ifdef F_40
if ( F_59 ( & V_12 -> V_59 ) )
F_60 ( V_12 ) ;
#endif
F_15 ( V_12 , L_6 , V_4 -> V_4 . V_7 ) ;
F_97 ( & V_4 -> V_19 ) ;
F_98 ( V_12 -> V_80 , V_4 -> V_4 . V_7 , V_81 ) ;
F_99 ( V_4 ) ;
F_100 ( V_4 ) ;
#ifdef F_40
if ( F_59 ( & V_4 -> V_12 -> V_59 ) ) {
F_101 ( V_4 ) ;
F_102 ( & V_4 -> V_57 ) ;
}
#endif
for ( V_15 = 0 ; V_15 < V_47 ; V_15 ++ ) {
V_116 = F_103 ( V_4 -> V_35 . V_116 [ V_15 ] ) ;
if ( ! V_116 )
continue;
F_96 ( & V_116 -> V_126 ) ;
F_16 ( V_116 ) ;
}
F_13 ( V_2 , V_4 ) ;
return 0 ;
}
int F_104 ( struct V_11 * V_12 , const T_1 * V_7 )
{
struct V_3 * V_4 ;
int V_114 ;
F_63 ( & V_12 -> V_2 -> V_8 ) ;
V_4 = F_7 ( V_12 , V_7 ) ;
V_114 = F_86 ( V_4 ) ;
F_58 ( & V_12 -> V_2 -> V_8 ) ;
return V_114 ;
}
int F_105 ( struct V_11 * V_12 ,
const T_1 * V_7 )
{
struct V_3 * V_4 ;
int V_114 ;
F_63 ( & V_12 -> V_2 -> V_8 ) ;
V_4 = F_10 ( V_12 , V_7 ) ;
V_114 = F_86 ( V_4 ) ;
F_58 ( & V_12 -> V_2 -> V_8 ) ;
return V_114 ;
}
static void F_106 ( unsigned long V_127 )
{
struct V_1 * V_2 = (struct V_1 * ) V_127 ;
struct V_3 * V_4 ;
bool V_128 = false ;
F_57 () ;
F_12 (sta, &local->sta_list, list)
if ( F_85 ( V_2 , V_4 ) )
V_128 = true ;
F_66 () ;
if ( V_2 -> V_129 )
return;
if ( ! V_128 )
return;
F_107 ( & V_2 -> V_130 ,
F_108 ( V_41 + V_131 ) ) ;
}
void F_109 ( struct V_1 * V_2 )
{
F_33 ( & V_2 -> V_98 ) ;
F_35 ( & V_2 -> V_8 ) ;
F_110 ( & V_2 -> V_76 ) ;
F_111 ( & V_2 -> V_130 , F_106 ,
( unsigned long ) V_2 ) ;
}
void F_112 ( struct V_1 * V_2 )
{
F_113 ( & V_2 -> V_130 ) ;
F_114 ( V_2 , NULL ) ;
}
int F_114 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_3 * V_4 , * V_132 ;
int V_114 = 0 ;
F_62 () ;
F_63 ( & V_2 -> V_8 ) ;
F_115 (sta, tmp, &local->sta_list, list) {
if ( ! V_12 || V_12 == V_4 -> V_12 ) {
F_45 ( F_86 ( V_4 ) ) ;
V_114 ++ ;
}
}
F_58 ( & V_2 -> V_8 ) ;
return V_114 ;
}
void F_116 ( struct V_11 * V_12 ,
unsigned long V_133 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 , * V_132 ;
F_63 ( & V_2 -> V_8 ) ;
F_115 (sta, tmp, &local->sta_list, list) {
if ( V_12 != V_4 -> V_12 )
continue;
if ( F_79 ( V_41 , V_4 -> V_40 + V_133 ) ) {
F_117 ( V_12 , L_7 ,
V_4 -> V_4 . V_7 ) ;
F_45 ( F_86 ( V_4 ) ) ;
}
}
F_58 ( & V_2 -> V_8 ) ;
}
struct V_134 * F_118 ( struct V_135 * V_26 ,
const T_1 * V_7 ,
const T_1 * V_136 )
{
struct V_3 * V_4 , * V_137 ;
F_119 (hw_to_local(hw), addr, sta, nxt) {
if ( V_136 &&
! F_9 ( V_4 -> V_12 -> V_59 . V_7 , V_136 ) )
continue;
if ( ! V_4 -> V_67 )
return NULL ;
return & V_4 -> V_4 ;
}
return NULL ;
}
struct V_134 * F_120 ( struct V_138 * V_59 ,
const T_1 * V_7 )
{
struct V_3 * V_4 ;
if ( ! V_59 )
return NULL ;
V_4 = F_10 ( F_121 ( V_59 ) , V_7 ) ;
if ( ! V_4 )
return NULL ;
if ( ! V_4 -> V_67 )
return NULL ;
return & V_4 -> V_4 ;
}
static void F_122 ( void * V_139 )
{
struct V_3 * V_4 = V_139 ;
struct V_11 * V_12 = V_4 -> V_12 ;
F_26 ( V_4 , V_23 ) ;
if ( F_25 ( V_4 , V_21 ) )
F_94 ( & V_12 -> V_13 -> V_125 ) ;
}
void F_23 ( struct V_3 * V_4 )
{
struct V_11 * V_12 = V_4 -> V_12 ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_140 V_126 ;
int V_141 = 0 , V_142 = 0 , V_86 ;
F_26 ( V_4 , V_143 ) ;
F_123 ( F_124 ( V_47 ) > 1 ) ;
V_4 -> V_97 = 0 ;
if ( ! ( V_2 -> V_26 . V_27 & V_94 ) )
F_125 ( V_2 , V_12 , V_144 , & V_4 -> V_4 ) ;
F_38 ( & V_126 ) ;
for ( V_86 = 0 ; V_86 < V_49 ; V_86 ++ ) {
int V_145 = F_95 ( & V_126 ) , V_132 ;
F_126 ( & V_4 -> V_51 [ V_86 ] , & V_126 ) ;
V_132 = F_95 ( & V_126 ) ;
V_141 += V_132 - V_145 ;
V_145 = V_132 ;
F_126 ( & V_4 -> V_50 [ V_86 ] , & V_126 ) ;
V_132 = F_95 ( & V_126 ) ;
V_142 += V_132 - V_145 ;
}
F_127 ( V_2 , & V_126 , F_122 , V_4 ) ;
V_2 -> V_112 -= V_142 ;
F_71 ( V_4 ) ;
F_84 ( V_12 ,
L_8 ,
V_4 -> V_4 . V_7 , V_4 -> V_4 . V_84 , V_141 , V_142 ) ;
}
static void F_128 ( struct V_11 * V_12 ,
struct V_3 * V_4 , int V_146 ,
enum V_147 V_148 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_149 * V_150 ;
struct V_101 * V_102 ;
int V_151 = sizeof( * V_150 ) ;
T_6 V_152 ;
bool V_153 = F_21 ( V_4 , V_154 ) ;
struct V_103 * V_104 ;
if ( V_153 ) {
V_152 = F_39 ( V_155 |
V_156 |
V_157 ) ;
} else {
V_151 -= 2 ;
V_152 = F_39 ( V_155 |
V_158 |
V_157 ) ;
}
V_102 = F_129 ( V_2 -> V_26 . V_159 + V_151 ) ;
if ( ! V_102 )
return;
F_130 ( V_102 , V_2 -> V_26 . V_159 ) ;
V_150 = ( void * ) F_131 ( V_102 , V_151 ) ;
V_150 -> V_160 = V_152 ;
V_150 -> V_161 = 0 ;
memcpy ( V_150 -> V_162 , V_4 -> V_4 . V_7 , V_39 ) ;
memcpy ( V_150 -> V_163 , V_12 -> V_59 . V_7 , V_39 ) ;
memcpy ( V_150 -> V_164 , V_12 -> V_59 . V_7 , V_39 ) ;
V_102 -> V_165 = V_146 ;
F_132 ( V_102 , V_166 [ V_146 ] ) ;
if ( V_153 ) {
V_150 -> V_167 = F_39 ( V_146 ) ;
if ( V_148 == V_168 )
V_150 -> V_167 |=
F_39 ( V_169 ) ;
}
V_104 = F_78 ( V_102 ) ;
V_104 -> V_27 |= V_170 |
V_171 |
V_172 ;
F_133 ( V_2 , V_4 , F_70 ( V_146 ) , 1 , V_148 , false ) ;
F_134 ( V_12 , V_102 ) ;
}
static void
F_135 ( struct V_3 * V_4 ,
int V_173 , T_1 V_174 ,
enum V_147 V_148 )
{
struct V_11 * V_12 = V_4 -> V_12 ;
struct V_1 * V_2 = V_12 -> V_2 ;
bool V_175 = false ;
bool V_176 = false ;
int V_86 ;
unsigned long V_177 = 0 ;
struct V_140 V_178 ;
F_53 ( V_4 , V_143 ) ;
F_136 ( & V_178 ) ;
for ( V_86 = 0 ; V_86 < V_49 ; V_86 ++ ) {
unsigned long V_96 ;
if ( V_174 & F_70 ( V_86 ) )
continue;
V_96 = F_69 ( V_86 ) ;
if ( ! V_175 ) {
V_177 = V_4 -> V_97 & V_96 ;
if ( V_177 ) {
V_175 = true ;
} else {
struct V_101 * V_102 ;
while ( V_173 > 0 ) {
V_102 = F_137 ( & V_4 -> V_51 [ V_86 ] ) ;
if ( ! V_102 ) {
V_102 = F_137 (
& V_4 -> V_50 [ V_86 ] ) ;
if ( V_102 )
V_2 -> V_112 -- ;
}
if ( ! V_102 )
break;
V_173 -- ;
V_175 = true ;
F_138 ( & V_178 , V_102 ) ;
}
}
if ( V_148 == V_179 &&
F_139 ( V_177 ) > 1 ) {
V_176 = true ;
V_177 =
F_70 ( F_140 ( V_177 ) - 1 ) ;
break;
}
}
if ( ! F_73 ( & V_4 -> V_51 [ V_86 ] ) ||
! F_73 ( & V_4 -> V_50 [ V_86 ] ) ) {
V_176 = true ;
break;
}
}
if ( ! V_175 ) {
int V_146 ;
V_146 = 7 - ( ( F_140 ( ~ V_174 ) - 1 ) << 1 ) ;
F_128 ( V_12 , V_4 , V_146 , V_148 ) ;
return;
}
if ( ! V_177 ) {
struct V_140 V_126 ;
struct V_101 * V_102 ;
int V_180 = 0 ;
T_4 V_96 = 0 ;
F_38 ( & V_126 ) ;
while ( ( V_102 = F_82 ( & V_178 ) ) ) {
struct V_103 * V_104 = F_78 ( V_102 ) ;
struct V_181 * V_182 = ( void * ) V_102 -> V_127 ;
T_1 * V_183 = NULL ;
V_180 ++ ;
V_104 -> V_27 |= V_170 ;
if ( V_176 || ! F_73 ( & V_178 ) )
V_182 -> V_160 |=
F_39 ( V_184 ) ;
else
V_182 -> V_160 &=
F_39 ( ~ V_184 ) ;
if ( F_141 ( V_182 -> V_160 ) ||
F_142 ( V_182 -> V_160 ) )
V_183 = F_143 ( V_182 ) ;
if ( F_73 ( & V_178 ) ) {
if ( V_148 == V_168 &&
V_183 )
* V_183 |= V_169 ;
V_104 -> V_27 |= V_171 |
V_172 ;
}
if ( V_183 )
V_96 |= F_70 ( * V_183 & V_185 ) ;
else
V_96 |= F_70 ( 0 ) ;
F_138 ( & V_126 , V_102 ) ;
}
F_133 ( V_2 , V_4 , V_96 , V_180 ,
V_148 , V_176 ) ;
F_144 ( V_2 , & V_126 ) ;
F_71 ( V_4 ) ;
} else {
F_145 ( V_2 , V_4 , V_177 ,
V_173 , V_148 , V_176 ) ;
}
}
void F_27 ( struct V_3 * V_4 )
{
T_1 V_186 = V_4 -> V_4 . V_93 ;
if ( V_186 == F_70 ( V_49 ) - 1 )
V_186 = 0 ;
F_135 ( V_4 , 1 , V_186 ,
V_179 ) ;
}
void F_28 ( struct V_3 * V_4 )
{
int V_173 = V_4 -> V_4 . V_187 ;
T_1 V_188 = V_4 -> V_4 . V_93 ;
if ( ! V_188 )
return;
switch ( V_4 -> V_4 . V_187 ) {
case 1 :
V_173 = 2 ;
break;
case 2 :
V_173 = 4 ;
break;
case 3 :
V_173 = 6 ;
break;
case 0 :
V_173 = 8 ;
break;
}
F_135 ( V_4 , V_173 , ~ V_188 ,
V_168 ) ;
}
void F_146 ( struct V_135 * V_26 ,
struct V_134 * V_189 , bool V_190 )
{
struct V_3 * V_4 = F_20 ( V_189 , struct V_3 , V_4 ) ;
F_147 ( V_4 -> V_2 , V_189 , V_190 ) ;
if ( V_190 )
F_53 ( V_4 , V_23 ) ;
else if ( F_21 ( V_4 , V_23 ) )
F_148 ( V_26 , & V_4 -> V_19 ) ;
}
void F_149 ( struct V_134 * V_189 )
{
struct V_3 * V_4 = F_20 ( V_189 , struct V_3 , V_4 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_101 * V_102 ;
struct V_191 * V_127 ;
F_150 ( V_2 , V_189 ) ;
V_102 = F_151 ( 0 , V_192 ) ;
if ( ! V_102 ) {
F_26 ( V_4 , V_143 ) ;
return;
}
V_127 = ( void * ) V_102 -> V_193 ;
memcpy ( V_127 -> V_4 , V_189 -> V_7 , V_39 ) ;
memcpy ( V_127 -> V_194 , V_4 -> V_12 -> V_59 . V_7 , V_39 ) ;
V_102 -> V_195 = V_196 ;
F_152 ( & V_2 -> V_197 , V_102 ) ;
F_153 ( & V_2 -> V_198 ) ;
}
void F_154 ( struct V_134 * V_189 ,
T_1 V_146 , bool V_142 )
{
struct V_3 * V_4 = F_20 ( V_189 , struct V_3 , V_4 ) ;
if ( F_45 ( V_146 >= V_47 ) )
return;
if ( V_142 )
F_155 ( V_146 , & V_4 -> V_97 ) ;
else
F_156 ( V_146 , & V_4 -> V_97 ) ;
F_71 ( V_4 ) ;
}
int F_92 ( struct V_3 * V_4 ,
enum V_61 V_199 )
{
F_62 () ;
if ( V_4 -> V_42 == V_199 )
return 0 ;
switch ( V_199 ) {
case V_43 :
if ( V_4 -> V_42 != V_200 )
return - V_60 ;
break;
case V_200 :
if ( V_4 -> V_42 != V_43 &&
V_4 -> V_42 != V_201 )
return - V_60 ;
break;
case V_201 :
if ( V_4 -> V_42 != V_200 &&
V_4 -> V_42 != V_202 )
return - V_60 ;
break;
case V_202 :
if ( V_4 -> V_42 != V_201 )
return - V_60 ;
break;
default:
F_157 ( 1 , L_9 , V_199 ) ;
return - V_60 ;
}
F_15 ( V_4 -> V_12 , L_10 ,
V_4 -> V_4 . V_7 , V_199 ) ;
if ( F_21 ( V_4 , V_77 ) ) {
int V_63 = F_48 ( V_4 -> V_2 , V_4 -> V_12 , V_4 ,
V_4 -> V_42 , V_199 ) ;
if ( V_63 )
return V_63 ;
}
switch ( V_199 ) {
case V_43 :
if ( V_4 -> V_42 == V_200 )
F_156 ( V_203 , & V_4 -> V_204 ) ;
break;
case V_200 :
if ( V_4 -> V_42 == V_43 )
F_155 ( V_203 , & V_4 -> V_204 ) ;
else if ( V_4 -> V_42 == V_201 )
F_156 ( V_205 , & V_4 -> V_204 ) ;
break;
case V_201 :
if ( V_4 -> V_42 == V_200 ) {
F_155 ( V_205 , & V_4 -> V_204 ) ;
} else if ( V_4 -> V_42 == V_202 ) {
if ( V_4 -> V_12 -> V_59 . type == V_206 ||
( V_4 -> V_12 -> V_59 . type == V_122 &&
! V_4 -> V_12 -> V_123 . V_124 . V_4 ) )
F_94 ( & V_4 -> V_12 -> V_13 -> V_207 ) ;
F_156 ( V_208 , & V_4 -> V_204 ) ;
}
break;
case V_202 :
if ( V_4 -> V_42 == V_201 ) {
if ( V_4 -> V_12 -> V_59 . type == V_206 ||
( V_4 -> V_12 -> V_59 . type == V_122 &&
! V_4 -> V_12 -> V_123 . V_124 . V_4 ) )
F_158 ( & V_4 -> V_12 -> V_13 -> V_207 ) ;
F_155 ( V_208 , & V_4 -> V_204 ) ;
}
break;
default:
break;
}
V_4 -> V_42 = V_199 ;
return 0 ;
}
