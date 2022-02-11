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
static void F_7 ( struct V_11 * V_12 )
{
struct V_3 * V_4 = F_8 ( V_12 , struct V_3 , V_13 ) ;
int V_14 , V_15 ;
struct V_16 * V_17 ;
struct V_18 * V_19 = V_4 -> V_19 ;
struct V_1 * V_2 = V_19 -> V_2 ;
if ( F_9 ( V_4 , V_20 ) ) {
F_10 ( ! V_19 -> V_21 ) ;
F_11 ( V_4 , V_20 ) ;
F_12 ( & V_19 -> V_21 -> V_22 ) ;
F_13 ( V_4 ) ;
}
for ( V_14 = 0 ; V_14 < V_23 ; V_14 ++ ) {
V_2 -> V_24 -= F_14 ( & V_4 -> V_25 [ V_14 ] ) ;
F_15 ( & V_2 -> V_26 , & V_4 -> V_25 [ V_14 ] ) ;
F_15 ( & V_2 -> V_26 , & V_4 -> V_27 [ V_14 ] ) ;
}
#ifdef F_16
if ( F_17 ( & V_19 -> V_28 ) ) {
F_18 ( V_19 ) ;
F_19 ( V_4 ) ;
F_20 ( & V_4 -> V_29 ) ;
}
#endif
F_21 ( & V_4 -> V_30 ) ;
for ( V_15 = 0 ; V_15 < V_31 ; V_15 ++ ) {
V_17 = F_22 ( V_4 -> V_32 . V_17 [ V_15 ] ) ;
if ( ! V_17 )
continue;
F_15 ( & V_2 -> V_26 , & V_17 -> V_33 ) ;
F_23 ( V_17 ) ;
}
F_24 ( V_2 , V_4 ) ;
}
static void F_25 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_8 ( V_35 , struct V_3 , V_34 ) ;
F_26 ( & V_4 -> V_2 -> V_26 , & V_4 -> V_13 ) ;
}
struct V_3 * F_27 ( struct V_18 * V_19 ,
const T_1 * V_7 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_3 * V_4 ;
V_4 = F_28 ( V_2 -> V_6 [ F_3 ( V_7 ) ] ,
F_4 ( & V_2 -> V_8 ) ) ;
while ( V_4 ) {
if ( V_4 -> V_19 == V_19 &&
F_29 ( V_4 -> V_4 . V_7 , V_7 ) )
break;
V_4 = F_28 ( V_4 -> V_10 ,
F_4 ( & V_2 -> V_8 ) ) ;
}
return V_4 ;
}
struct V_3 * F_30 ( struct V_18 * V_19 ,
const T_1 * V_7 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_3 * V_4 ;
V_4 = F_28 ( V_2 -> V_6 [ F_3 ( V_7 ) ] ,
F_4 ( & V_2 -> V_8 ) ) ;
while ( V_4 ) {
if ( ( V_4 -> V_19 == V_19 ||
( V_4 -> V_19 -> V_21 && V_4 -> V_19 -> V_21 == V_19 -> V_21 ) ) &&
F_29 ( V_4 -> V_4 . V_7 , V_7 ) )
break;
V_4 = F_28 ( V_4 -> V_10 ,
F_4 ( & V_2 -> V_8 ) ) ;
}
return V_4 ;
}
struct V_3 * F_31 ( struct V_18 * V_19 ,
int V_36 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_3 * V_4 ;
int V_15 = 0 ;
F_32 (sta, &local->sta_list, list) {
if ( V_19 != V_4 -> V_19 )
continue;
if ( V_15 < V_36 ) {
++ V_15 ;
continue;
}
return V_4 ;
}
return NULL ;
}
void F_24 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_37 )
F_33 ( V_4 ) ;
F_34 ( V_4 -> V_19 , L_1 , V_4 -> V_4 . V_7 ) ;
F_23 ( V_4 ) ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_36 ( & V_2 -> V_8 ) ;
V_4 -> V_10 = V_2 -> V_6 [ F_3 ( V_4 -> V_4 . V_7 ) ] ;
F_5 ( V_2 -> V_6 [ F_3 ( V_4 -> V_4 . V_7 ) ] , V_4 ) ;
}
static void F_37 ( struct V_11 * V_12 )
{
struct V_3 * V_4 ;
V_4 = F_8 ( V_12 , struct V_3 , V_30 ) ;
if ( V_4 -> V_38 )
return;
if ( ! F_9 ( V_4 , V_20 ) ) {
F_38 () ;
F_39 ( V_4 ) ;
F_40 () ;
} else if ( F_41 ( V_4 , V_39 ) ) {
F_11 ( V_4 , V_40 ) ;
F_38 () ;
F_42 ( V_4 ) ;
F_40 () ;
} else if ( F_41 ( V_4 , V_41 ) ) {
F_11 ( V_4 , V_40 ) ;
F_38 () ;
F_43 ( V_4 ) ;
F_40 () ;
} else
F_11 ( V_4 , V_40 ) ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 V_42 )
{
if ( V_2 -> V_26 . V_43 & V_44 )
return 0 ;
V_4 -> V_37 = V_2 -> V_37 ;
V_4 -> V_45 = F_45 ( V_4 -> V_37 ,
& V_4 -> V_4 , V_42 ) ;
if ( ! V_4 -> V_45 )
return - V_46 ;
return 0 ;
}
struct V_3 * F_46 ( struct V_18 * V_19 ,
const T_1 * V_7 , T_2 V_42 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_3 * V_4 ;
struct V_47 V_48 ;
int V_15 ;
V_4 = F_47 ( sizeof( * V_4 ) + V_2 -> V_26 . V_49 , V_42 ) ;
if ( ! V_4 )
return NULL ;
F_48 ( & V_4 -> V_50 ) ;
F_49 ( & V_4 -> V_30 , F_37 ) ;
F_49 ( & V_4 -> V_13 , F_7 ) ;
F_49 ( & V_4 -> V_32 . V_51 , V_52 ) ;
F_50 ( & V_4 -> V_32 . V_53 ) ;
memcpy ( V_4 -> V_4 . V_7 , V_7 , V_54 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_19 = V_19 ;
V_4 -> V_55 = V_56 ;
V_4 -> V_57 = V_58 ;
F_51 ( & V_48 ) ;
V_4 -> V_59 = V_48 . V_60 ;
F_52 ( & V_4 -> V_61 , 1024 , 8 ) ;
if ( F_44 ( V_2 , V_4 , V_42 ) ) {
F_23 ( V_4 ) ;
return NULL ;
}
for ( V_15 = 0 ; V_15 < V_31 ; V_15 ++ ) {
V_4 -> V_62 [ V_15 ] = V_15 ;
}
for ( V_15 = 0 ; V_15 < V_23 ; V_15 ++ ) {
F_53 ( & V_4 -> V_25 [ V_15 ] ) ;
F_53 ( & V_4 -> V_27 [ V_15 ] ) ;
}
for ( V_15 = 0 ; V_15 < V_63 ; V_15 ++ )
V_4 -> V_64 [ V_15 ] = F_54 ( V_65 ) ;
F_34 ( V_19 , L_2 , V_4 -> V_4 . V_7 ) ;
#ifdef F_16
V_4 -> V_66 = V_67 ;
F_55 ( & V_4 -> V_29 ) ;
#endif
return V_4 ;
}
static int F_56 ( struct V_3 * V_4 )
{
struct V_18 * V_19 = V_4 -> V_19 ;
if ( F_57 ( ! F_58 ( V_19 ) ) )
return - V_68 ;
if ( F_59 ( F_29 ( V_4 -> V_4 . V_7 , V_19 -> V_28 . V_7 ) ||
F_60 ( V_4 -> V_4 . V_7 ) ) )
return - V_69 ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
struct V_3 * V_4 )
{
enum V_70 V_71 ;
int V_72 = 0 ;
for ( V_71 = V_73 ; V_71 < V_4 -> V_57 ; V_71 ++ ) {
V_72 = F_62 ( V_2 , V_19 , V_4 , V_71 , V_71 + 1 ) ;
if ( V_72 )
break;
}
if ( ! V_72 ) {
if ( ! V_2 -> V_74 -> V_75 )
V_4 -> V_76 = true ;
return 0 ;
}
if ( V_19 -> V_28 . type == V_77 ) {
F_63 ( V_19 ,
L_3 ,
V_4 -> V_4 . V_7 , V_71 + 1 , V_72 ) ;
V_72 = 0 ;
}
for (; V_71 > V_73 ; V_71 -- )
F_59 ( F_62 ( V_2 , V_19 , V_4 , V_71 , V_71 - 1 ) ) ;
return V_72 ;
}
static int F_64 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_18 * V_19 = V_4 -> V_19 ;
struct V_78 V_79 ;
int V_72 = 0 ;
F_36 ( & V_2 -> V_8 ) ;
if ( F_30 ( V_19 , V_4 -> V_4 . V_7 ) ) {
V_72 = - V_80 ;
goto V_81;
}
V_72 = F_61 ( V_2 , V_19 , V_4 ) ;
if ( V_72 )
goto V_81;
V_2 -> V_82 ++ ;
V_2 -> V_83 ++ ;
F_65 () ;
F_35 ( V_2 , V_4 ) ;
F_66 ( & V_4 -> V_84 , & V_2 -> V_85 ) ;
F_67 ( V_4 , V_86 ) ;
F_68 ( V_4 ) ;
F_69 ( V_4 ) ;
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_79 . V_87 = 0 ;
V_79 . V_88 = V_2 -> V_83 ;
F_70 ( V_19 -> V_89 , V_4 -> V_4 . V_7 , & V_79 , V_90 ) ;
F_34 ( V_19 , L_4 , V_4 -> V_4 . V_7 ) ;
F_71 () ;
F_72 ( & V_2 -> V_8 ) ;
if ( F_17 ( & V_19 -> V_28 ) )
F_18 ( V_19 ) ;
return 0 ;
V_81:
F_72 ( & V_2 -> V_8 ) ;
F_71 () ;
return V_72 ;
}
int F_73 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_72 = 0 ;
F_74 () ;
V_72 = F_56 ( V_4 ) ;
if ( V_72 ) {
F_71 () ;
goto V_91;
}
F_75 ( & V_2 -> V_8 ) ;
V_72 = F_64 ( V_4 ) ;
if ( V_72 )
goto V_91;
return 0 ;
V_91:
F_10 ( ! V_72 ) ;
F_24 ( V_2 , V_4 ) ;
return V_72 ;
}
int F_76 ( struct V_3 * V_4 )
{
int V_72 = F_73 ( V_4 ) ;
F_77 () ;
return V_72 ;
}
static inline void F_78 ( struct V_92 * V_21 , T_4 V_93 )
{
V_21 -> V_94 [ V_93 / 8 ] |= ( 1 << ( V_93 % 8 ) ) ;
}
static inline void F_79 ( struct V_92 * V_21 , T_4 V_93 )
{
V_21 -> V_94 [ V_93 / 8 ] &= ~ ( 1 << ( V_93 % 8 ) ) ;
}
static unsigned long F_80 ( int V_14 )
{
switch ( V_14 ) {
case V_95 :
return F_81 ( 6 ) | F_81 ( 7 ) ;
case V_96 :
return F_81 ( 4 ) | F_81 ( 5 ) ;
case V_97 :
return F_81 ( 0 ) | F_81 ( 3 ) ;
case V_98 :
return F_81 ( 1 ) | F_81 ( 2 ) ;
default:
F_59 ( 1 ) ;
return 0 ;
}
}
void F_13 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_92 * V_21 = V_4 -> V_19 -> V_21 ;
unsigned long V_43 ;
bool V_99 = false ;
T_1 V_100 = V_4 -> V_4 . V_101 ;
int V_14 ;
if ( F_82 ( ! V_4 -> V_19 -> V_21 ) )
return;
if ( V_2 -> V_26 . V_43 & V_102 )
return;
if ( V_4 -> V_38 )
goto V_103;
if ( V_100 == F_81 ( V_23 ) - 1 )
V_100 = 0 ;
for ( V_14 = 0 ; V_14 < V_23 ; V_14 ++ ) {
unsigned long V_104 ;
if ( V_100 & F_81 ( V_14 ) )
continue;
V_99 |= ! F_83 ( & V_4 -> V_27 [ V_14 ] ) ||
! F_83 ( & V_4 -> V_25 [ V_14 ] ) ;
if ( V_99 )
break;
V_104 = F_80 ( V_14 ) ;
V_99 |=
V_4 -> V_105 & V_104 ;
}
V_103:
F_84 ( & V_2 -> V_106 , V_43 ) ;
if ( V_99 )
F_78 ( V_21 , V_4 -> V_4 . V_93 ) ;
else
F_79 ( V_21 , V_4 -> V_4 . V_93 ) ;
if ( V_2 -> V_74 -> V_107 ) {
V_2 -> V_108 = true ;
F_85 ( V_2 , & V_4 -> V_4 , V_99 ) ;
V_2 -> V_108 = false ;
}
F_86 ( & V_2 -> V_106 , V_43 ) ;
}
static bool F_87 ( struct V_3 * V_4 , struct V_109 * V_110 )
{
struct V_111 * V_112 ;
int V_113 ;
if ( ! V_110 )
return false ;
V_112 = F_88 ( V_110 ) ;
V_113 = ( V_4 -> V_114 *
V_4 -> V_19 -> V_28 . V_115 . V_116 *
32 / 15625 ) * V_117 ;
if ( V_113 < V_118 )
V_113 = V_118 ;
return F_89 ( V_56 , V_112 -> V_119 . V_56 + V_113 ) ;
}
static bool F_90 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_14 )
{
unsigned long V_43 ;
struct V_109 * V_110 ;
for (; ; ) {
F_84 ( & V_4 -> V_27 [ V_14 ] . V_50 , V_43 ) ;
V_110 = F_91 ( & V_4 -> V_27 [ V_14 ] ) ;
if ( F_87 ( V_4 , V_110 ) )
V_110 = F_92 ( & V_4 -> V_27 [ V_14 ] ) ;
else
V_110 = NULL ;
F_86 ( & V_4 -> V_27 [ V_14 ] . V_50 , V_43 ) ;
if ( ! V_110 )
break;
F_93 ( & V_2 -> V_26 , V_110 ) ;
}
for (; ; ) {
F_84 ( & V_4 -> V_25 [ V_14 ] . V_50 , V_43 ) ;
V_110 = F_91 ( & V_4 -> V_25 [ V_14 ] ) ;
if ( F_87 ( V_4 , V_110 ) )
V_110 = F_92 ( & V_4 -> V_25 [ V_14 ] ) ;
else
V_110 = NULL ;
F_86 ( & V_4 -> V_25 [ V_14 ] . V_50 , V_43 ) ;
if ( ! V_110 )
break;
V_2 -> V_24 -- ;
F_94 ( V_4 -> V_19 , L_5 ,
V_4 -> V_4 . V_7 ) ;
F_93 ( & V_2 -> V_26 , V_110 ) ;
}
F_13 ( V_4 ) ;
return ! ( F_83 ( & V_4 -> V_25 [ V_14 ] ) &&
F_83 ( & V_4 -> V_27 [ V_14 ] ) ) ;
}
static bool F_95 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_120 = false ;
int V_14 ;
if ( ! V_4 -> V_19 -> V_21 )
return false ;
for ( V_14 = 0 ; V_14 < V_23 ; V_14 ++ )
V_120 |=
F_90 ( V_2 , V_4 , V_14 ) ;
return V_120 ;
}
int T_5 F_96 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_18 * V_19 ;
int V_121 , V_15 ;
F_74 () ;
if ( ! V_4 )
return - V_9 ;
V_2 = V_4 -> V_2 ;
V_19 = V_4 -> V_19 ;
F_36 ( & V_2 -> V_8 ) ;
F_67 ( V_4 , V_122 ) ;
F_97 ( V_4 , false ) ;
V_121 = F_1 ( V_2 , V_4 ) ;
if ( V_121 )
return V_121 ;
F_98 ( & V_4 -> V_84 ) ;
F_75 ( & V_2 -> V_123 ) ;
for ( V_15 = 0 ; V_15 < V_124 ; V_15 ++ )
F_99 ( F_100 ( V_2 , V_4 -> V_125 [ V_15 ] ) ) ;
if ( V_4 -> V_126 )
F_99 ( F_100 ( V_2 , V_4 -> V_126 ) ) ;
F_72 ( & V_2 -> V_123 ) ;
V_4 -> V_38 = true ;
V_2 -> V_82 -- ;
V_2 -> V_83 ++ ;
if ( V_19 -> V_28 . type == V_127 )
F_101 ( V_19 -> V_128 . V_129 . V_4 , NULL ) ;
while ( V_4 -> V_57 > V_58 ) {
V_121 = F_102 ( V_4 , V_4 -> V_57 - 1 ) ;
if ( V_121 ) {
F_82 ( 1 ) ;
break;
}
}
if ( V_4 -> V_76 ) {
V_121 = F_62 ( V_2 , V_19 , V_4 , V_58 ,
V_73 ) ;
F_82 ( V_121 != 0 ) ;
}
F_34 ( V_19 , L_6 , V_4 -> V_4 . V_7 ) ;
F_103 ( V_19 -> V_89 , V_4 -> V_4 . V_7 , V_90 ) ;
F_104 ( V_4 ) ;
F_105 ( V_4 ) ;
F_106 ( & V_4 -> V_34 , F_25 ) ;
return 0 ;
}
int F_107 ( struct V_18 * V_19 , const T_1 * V_7 )
{
struct V_3 * V_4 ;
int V_121 ;
F_75 ( & V_19 -> V_2 -> V_8 ) ;
V_4 = F_27 ( V_19 , V_7 ) ;
V_121 = F_96 ( V_4 ) ;
F_72 ( & V_19 -> V_2 -> V_8 ) ;
return V_121 ;
}
int F_108 ( struct V_18 * V_19 ,
const T_1 * V_7 )
{
struct V_3 * V_4 ;
int V_121 ;
F_75 ( & V_19 -> V_2 -> V_8 ) ;
V_4 = F_30 ( V_19 , V_7 ) ;
V_121 = F_96 ( V_4 ) ;
F_72 ( & V_19 -> V_2 -> V_8 ) ;
return V_121 ;
}
static void F_109 ( unsigned long V_130 )
{
struct V_1 * V_2 = (struct V_1 * ) V_130 ;
struct V_3 * V_4 ;
bool V_131 = false ;
F_71 () ;
F_32 (sta, &local->sta_list, list)
if ( F_95 ( V_2 , V_4 ) )
V_131 = true ;
F_77 () ;
if ( V_2 -> V_132 )
return;
if ( ! V_131 )
return;
F_110 ( & V_2 -> V_133 ,
F_111 ( V_56 + V_134 ) ) ;
}
void F_112 ( struct V_1 * V_2 )
{
F_48 ( & V_2 -> V_106 ) ;
F_50 ( & V_2 -> V_8 ) ;
F_113 ( & V_2 -> V_85 ) ;
F_114 ( & V_2 -> V_133 , F_109 ,
( unsigned long ) V_2 ) ;
}
void F_115 ( struct V_1 * V_2 )
{
F_116 ( & V_2 -> V_133 ) ;
F_117 ( V_2 , NULL ) ;
}
int F_117 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_3 * V_4 , * V_135 ;
int V_121 = 0 ;
F_74 () ;
F_75 ( & V_2 -> V_8 ) ;
F_118 (sta, tmp, &local->sta_list, list) {
if ( ! V_19 || V_19 == V_4 -> V_19 ) {
F_59 ( F_96 ( V_4 ) ) ;
V_121 ++ ;
}
}
F_72 ( & V_2 -> V_8 ) ;
return V_121 ;
}
void F_119 ( struct V_18 * V_19 ,
unsigned long V_136 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_3 * V_4 , * V_135 ;
F_75 ( & V_2 -> V_8 ) ;
F_118 (sta, tmp, &local->sta_list, list) {
if ( V_19 != V_4 -> V_19 )
continue;
if ( F_89 ( V_56 , V_4 -> V_55 + V_136 ) ) {
F_120 ( V_19 , L_7 ,
V_4 -> V_4 . V_7 ) ;
F_59 ( F_96 ( V_4 ) ) ;
}
}
F_72 ( & V_2 -> V_8 ) ;
}
struct V_137 * F_121 ( struct V_138 * V_26 ,
const T_1 * V_7 ,
const T_1 * V_139 )
{
struct V_3 * V_4 , * V_140 ;
F_122 (hw_to_local(hw), addr, sta, nxt) {
if ( V_139 &&
! F_29 ( V_4 -> V_19 -> V_28 . V_7 , V_139 ) )
continue;
if ( ! V_4 -> V_76 )
return NULL ;
return & V_4 -> V_4 ;
}
return NULL ;
}
struct V_137 * F_123 ( struct V_141 * V_28 ,
const T_1 * V_7 )
{
struct V_3 * V_4 ;
if ( ! V_28 )
return NULL ;
V_4 = F_30 ( F_124 ( V_28 ) , V_7 ) ;
if ( ! V_4 )
return NULL ;
if ( ! V_4 -> V_76 )
return NULL ;
return & V_4 -> V_4 ;
}
static void F_125 ( void * V_142 )
{
struct V_3 * V_4 = V_142 ;
struct V_18 * V_19 = V_4 -> V_19 ;
F_11 ( V_4 , V_40 ) ;
if ( F_41 ( V_4 , V_20 ) )
F_12 ( & V_19 -> V_21 -> V_22 ) ;
}
void F_39 ( struct V_3 * V_4 )
{
struct V_18 * V_19 = V_4 -> V_19 ;
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_143 V_33 ;
int V_144 = 0 , V_145 = 0 , V_14 ;
unsigned long V_43 ;
F_11 ( V_4 , V_146 ) ;
F_126 ( F_127 ( V_31 ) > 1 ) ;
V_4 -> V_105 = 0 ;
if ( ! ( V_2 -> V_26 . V_43 & V_102 ) )
F_128 ( V_2 , V_19 , V_147 , & V_4 -> V_4 ) ;
F_53 ( & V_33 ) ;
for ( V_14 = 0 ; V_14 < V_23 ; V_14 ++ ) {
int V_148 = F_14 ( & V_33 ) , V_135 ;
F_84 ( & V_4 -> V_27 [ V_14 ] . V_50 , V_43 ) ;
F_129 ( & V_4 -> V_27 [ V_14 ] , & V_33 ) ;
F_86 ( & V_4 -> V_27 [ V_14 ] . V_50 , V_43 ) ;
V_135 = F_14 ( & V_33 ) ;
V_144 += V_135 - V_148 ;
V_148 = V_135 ;
F_84 ( & V_4 -> V_25 [ V_14 ] . V_50 , V_43 ) ;
F_129 ( & V_4 -> V_25 [ V_14 ] , & V_33 ) ;
F_86 ( & V_4 -> V_25 [ V_14 ] . V_50 , V_43 ) ;
V_135 = F_14 ( & V_33 ) ;
V_145 += V_135 - V_148 ;
}
F_130 ( V_2 , & V_33 , F_125 , V_4 ) ;
V_2 -> V_24 -= V_145 ;
F_13 ( V_4 ) ;
F_94 ( V_19 ,
L_8 ,
V_4 -> V_4 . V_7 , V_4 -> V_4 . V_93 , V_144 , V_145 ) ;
}
static void F_131 ( struct V_18 * V_19 ,
struct V_3 * V_4 , int V_149 ,
enum V_150 V_151 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_152 * V_153 ;
struct V_109 * V_110 ;
int V_154 = sizeof( * V_153 ) ;
T_6 V_155 ;
bool V_156 = F_9 ( V_4 , V_157 ) ;
struct V_111 * V_112 ;
if ( V_156 ) {
V_155 = F_54 ( V_158 |
V_159 |
V_160 ) ;
} else {
V_154 -= 2 ;
V_155 = F_54 ( V_158 |
V_161 |
V_160 ) ;
}
V_110 = F_132 ( V_2 -> V_26 . V_162 + V_154 ) ;
if ( ! V_110 )
return;
F_133 ( V_110 , V_2 -> V_26 . V_162 ) ;
V_153 = ( void * ) F_134 ( V_110 , V_154 ) ;
V_153 -> V_163 = V_155 ;
V_153 -> V_164 = 0 ;
memcpy ( V_153 -> V_165 , V_4 -> V_4 . V_7 , V_54 ) ;
memcpy ( V_153 -> V_166 , V_19 -> V_28 . V_7 , V_54 ) ;
memcpy ( V_153 -> V_167 , V_19 -> V_28 . V_7 , V_54 ) ;
V_110 -> V_168 = V_149 ;
F_135 ( V_110 , V_169 [ V_149 ] ) ;
if ( V_156 ) {
V_153 -> V_170 = F_54 ( V_149 ) ;
if ( V_151 == V_171 )
V_153 -> V_170 |=
F_54 ( V_172 ) ;
}
V_112 = F_88 ( V_110 ) ;
V_112 -> V_43 |= V_173 |
V_174 |
V_175 ;
F_136 ( V_2 , V_4 , F_81 ( V_149 ) , 1 , V_151 , false ) ;
F_137 ( V_19 , V_110 ) ;
}
static void
F_138 ( struct V_3 * V_4 ,
int V_176 , T_1 V_177 ,
enum V_150 V_151 )
{
struct V_18 * V_19 = V_4 -> V_19 ;
struct V_1 * V_2 = V_19 -> V_2 ;
bool V_178 = false ;
bool V_179 = false ;
int V_14 ;
unsigned long V_180 = 0 ;
struct V_143 V_181 ;
F_67 ( V_4 , V_146 ) ;
F_139 ( & V_181 ) ;
for ( V_14 = 0 ; V_14 < V_23 ; V_14 ++ ) {
unsigned long V_104 ;
if ( V_177 & F_81 ( V_14 ) )
continue;
V_104 = F_80 ( V_14 ) ;
if ( ! V_178 ) {
V_180 = V_4 -> V_105 & V_104 ;
if ( V_180 ) {
V_178 = true ;
} else {
struct V_109 * V_110 ;
while ( V_176 > 0 ) {
V_110 = F_140 ( & V_4 -> V_27 [ V_14 ] ) ;
if ( ! V_110 ) {
V_110 = F_140 (
& V_4 -> V_25 [ V_14 ] ) ;
if ( V_110 )
V_2 -> V_24 -- ;
}
if ( ! V_110 )
break;
V_176 -- ;
V_178 = true ;
F_141 ( & V_181 , V_110 ) ;
}
}
if ( V_151 == V_182 &&
F_142 ( V_180 ) > 1 ) {
V_179 = true ;
V_180 =
F_81 ( F_143 ( V_180 ) - 1 ) ;
break;
}
}
if ( ! F_83 ( & V_4 -> V_27 [ V_14 ] ) ||
! F_83 ( & V_4 -> V_25 [ V_14 ] ) ) {
V_179 = true ;
break;
}
}
if ( ! V_178 ) {
int V_149 ;
V_149 = 7 - ( ( F_143 ( ~ V_177 ) - 1 ) << 1 ) ;
F_131 ( V_19 , V_4 , V_149 , V_151 ) ;
return;
}
if ( ! V_180 ) {
struct V_143 V_33 ;
struct V_109 * V_110 ;
int V_183 = 0 ;
T_4 V_104 = 0 ;
F_53 ( & V_33 ) ;
while ( ( V_110 = F_92 ( & V_181 ) ) ) {
struct V_111 * V_112 = F_88 ( V_110 ) ;
struct V_184 * V_185 = ( void * ) V_110 -> V_130 ;
T_1 * V_186 = NULL ;
V_183 ++ ;
V_112 -> V_43 |= V_173 ;
if ( V_179 || ! F_83 ( & V_181 ) )
V_185 -> V_163 |=
F_54 ( V_187 ) ;
else
V_185 -> V_163 &=
F_54 ( ~ V_187 ) ;
if ( F_144 ( V_185 -> V_163 ) ||
F_145 ( V_185 -> V_163 ) )
V_186 = F_146 ( V_185 ) ;
if ( F_83 ( & V_181 ) ) {
if ( V_151 == V_171 &&
V_186 )
* V_186 |= V_172 ;
V_112 -> V_43 |= V_174 |
V_175 ;
}
if ( V_186 )
V_104 |= F_81 ( * V_186 & V_188 ) ;
else
V_104 |= F_81 ( 0 ) ;
F_141 ( & V_33 , V_110 ) ;
}
F_136 ( V_2 , V_4 , V_104 , V_183 ,
V_151 , V_179 ) ;
F_147 ( V_2 , & V_33 ) ;
F_13 ( V_4 ) ;
} else {
F_148 ( V_2 , V_4 , V_180 ,
V_176 , V_151 , V_179 ) ;
}
}
void F_42 ( struct V_3 * V_4 )
{
T_1 V_189 = V_4 -> V_4 . V_101 ;
if ( V_189 == F_81 ( V_23 ) - 1 )
V_189 = 0 ;
F_138 ( V_4 , 1 , V_189 ,
V_182 ) ;
}
void F_43 ( struct V_3 * V_4 )
{
int V_176 = V_4 -> V_4 . V_190 ;
T_1 V_191 = V_4 -> V_4 . V_101 ;
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
F_138 ( V_4 , V_176 , ~ V_191 ,
V_171 ) ;
}
void F_149 ( struct V_138 * V_26 ,
struct V_137 * V_192 , bool V_193 )
{
struct V_3 * V_4 = F_8 ( V_192 , struct V_3 , V_4 ) ;
F_150 ( V_4 -> V_2 , V_192 , V_193 ) ;
if ( V_193 )
F_67 ( V_4 , V_40 ) ;
else if ( F_9 ( V_4 , V_40 ) )
F_26 ( V_26 , & V_4 -> V_30 ) ;
}
void F_151 ( struct V_137 * V_192 )
{
struct V_3 * V_4 = F_8 ( V_192 , struct V_3 , V_4 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_109 * V_110 ;
struct V_194 * V_130 ;
F_152 ( V_2 , V_192 ) ;
V_110 = F_153 ( 0 , V_195 ) ;
if ( ! V_110 ) {
F_11 ( V_4 , V_146 ) ;
return;
}
V_130 = ( void * ) V_110 -> V_196 ;
memcpy ( V_130 -> V_4 , V_192 -> V_7 , V_54 ) ;
memcpy ( V_130 -> V_197 , V_4 -> V_19 -> V_28 . V_7 , V_54 ) ;
V_110 -> V_198 = V_199 ;
F_154 ( & V_2 -> V_200 , V_110 ) ;
F_155 ( & V_2 -> V_201 ) ;
}
void F_156 ( struct V_137 * V_192 ,
T_1 V_149 , bool V_145 )
{
struct V_3 * V_4 = F_8 ( V_192 , struct V_3 , V_4 ) ;
if ( F_59 ( V_149 >= V_31 ) )
return;
if ( V_145 )
F_157 ( V_149 , & V_4 -> V_105 ) ;
else
F_158 ( V_149 , & V_4 -> V_105 ) ;
F_13 ( V_4 ) ;
}
int F_102 ( struct V_3 * V_4 ,
enum V_70 V_202 )
{
F_74 () ;
if ( V_4 -> V_57 == V_202 )
return 0 ;
switch ( V_202 ) {
case V_58 :
if ( V_4 -> V_57 != V_203 )
return - V_69 ;
break;
case V_203 :
if ( V_4 -> V_57 != V_58 &&
V_4 -> V_57 != V_204 )
return - V_69 ;
break;
case V_204 :
if ( V_4 -> V_57 != V_203 &&
V_4 -> V_57 != V_205 )
return - V_69 ;
break;
case V_205 :
if ( V_4 -> V_57 != V_204 )
return - V_69 ;
break;
default:
F_159 ( 1 , L_9 , V_202 ) ;
return - V_69 ;
}
F_34 ( V_4 -> V_19 , L_10 ,
V_4 -> V_4 . V_7 , V_202 ) ;
if ( F_9 ( V_4 , V_86 ) ) {
int V_72 = F_62 ( V_4 -> V_2 , V_4 -> V_19 , V_4 ,
V_4 -> V_57 , V_202 ) ;
if ( V_72 )
return V_72 ;
}
switch ( V_202 ) {
case V_58 :
if ( V_4 -> V_57 == V_203 )
F_158 ( V_206 , & V_4 -> V_207 ) ;
break;
case V_203 :
if ( V_4 -> V_57 == V_58 )
F_157 ( V_206 , & V_4 -> V_207 ) ;
else if ( V_4 -> V_57 == V_204 )
F_158 ( V_208 , & V_4 -> V_207 ) ;
break;
case V_204 :
if ( V_4 -> V_57 == V_203 ) {
F_157 ( V_208 , & V_4 -> V_207 ) ;
} else if ( V_4 -> V_57 == V_205 ) {
if ( V_4 -> V_19 -> V_28 . type == V_209 ||
( V_4 -> V_19 -> V_28 . type == V_127 &&
! V_4 -> V_19 -> V_128 . V_129 . V_4 ) )
F_12 ( & V_4 -> V_19 -> V_21 -> V_210 ) ;
F_158 ( V_211 , & V_4 -> V_207 ) ;
}
break;
case V_205 :
if ( V_4 -> V_57 == V_204 ) {
if ( V_4 -> V_19 -> V_28 . type == V_209 ||
( V_4 -> V_19 -> V_28 . type == V_127 &&
! V_4 -> V_19 -> V_128 . V_129 . V_4 ) )
F_160 ( & V_4 -> V_19 -> V_21 -> V_210 ) ;
F_157 ( V_211 , & V_4 -> V_207 ) ;
}
break;
default:
break;
}
V_4 -> V_57 = V_202 ;
return 0 ;
}
