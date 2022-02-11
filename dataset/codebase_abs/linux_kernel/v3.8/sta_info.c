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
else
return;
F_9 ( V_4 , V_19 ) ;
F_10 ( & V_18 -> V_24 ) ;
F_11 ( V_4 ) ;
}
for ( V_11 = 0 ; V_11 < V_25 ; V_11 ++ ) {
V_2 -> V_26 -= F_12 ( & V_4 -> V_27 [ V_11 ] ) ;
F_13 ( & V_2 -> V_28 , & V_4 -> V_27 [ V_11 ] ) ;
F_13 ( & V_2 -> V_28 , & V_4 -> V_29 [ V_11 ] ) ;
}
#ifdef F_14
if ( F_15 ( & V_16 -> V_20 ) ) {
F_16 ( V_16 ) ;
F_17 ( V_4 ) ;
F_18 ( & V_4 -> V_30 ) ;
}
#endif
F_19 ( & V_4 -> V_31 ) ;
for ( V_12 = 0 ; V_12 < V_32 ; V_12 ++ ) {
V_14 = F_20 ( V_4 -> V_33 . V_14 [ V_12 ] ) ;
if ( ! V_14 )
continue;
F_13 ( & V_2 -> V_28 , & V_14 -> V_34 ) ;
F_21 ( V_14 ) ;
}
F_22 ( V_2 , V_4 ) ;
}
void F_23 ( struct V_15 * V_16 )
{
struct V_3 * V_4 ;
F_24 ( & V_16 -> V_35 ) ;
while ( ! F_25 ( & V_16 -> V_36 ) ) {
V_4 = F_26 ( & V_16 -> V_36 ,
struct V_3 , V_37 ) ;
F_27 ( & V_4 -> V_37 ) ;
F_28 ( & V_16 -> V_35 ) ;
F_7 ( V_4 ) ;
F_24 ( & V_16 -> V_35 ) ;
}
F_28 ( & V_16 -> V_35 ) ;
}
static void F_29 ( struct V_38 * V_39 )
{
struct V_3 * V_4 = F_30 ( V_39 , struct V_3 , V_38 ) ;
struct V_15 * V_16 = V_4 -> V_16 ;
F_31 ( & V_16 -> V_35 ) ;
F_32 ( & V_4 -> V_37 , & V_16 -> V_36 ) ;
F_33 ( & V_16 -> V_35 ) ;
F_34 ( & V_16 -> V_2 -> V_28 , & V_16 -> V_40 ) ;
}
struct V_3 * F_35 ( struct V_15 * V_16 ,
const T_1 * V_7 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 ;
V_4 = F_36 ( V_2 -> V_6 [ F_3 ( V_7 ) ] ,
F_4 ( & V_2 -> V_8 ) ) ;
while ( V_4 ) {
if ( V_4 -> V_16 == V_16 &&
F_37 ( V_4 -> V_4 . V_7 , V_7 ) )
break;
V_4 = F_36 ( V_4 -> V_10 ,
F_4 ( & V_2 -> V_8 ) ) ;
}
return V_4 ;
}
struct V_3 * F_38 ( struct V_15 * V_16 ,
const T_1 * V_7 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 ;
V_4 = F_36 ( V_2 -> V_6 [ F_3 ( V_7 ) ] ,
F_4 ( & V_2 -> V_8 ) ) ;
while ( V_4 ) {
if ( ( V_4 -> V_16 == V_16 ||
( V_4 -> V_16 -> V_23 && V_4 -> V_16 -> V_23 == V_16 -> V_23 ) ) &&
F_37 ( V_4 -> V_4 . V_7 , V_7 ) )
break;
V_4 = F_36 ( V_4 -> V_10 ,
F_4 ( & V_2 -> V_8 ) ) ;
}
return V_4 ;
}
struct V_3 * F_39 ( struct V_15 * V_16 ,
int V_41 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 ;
int V_12 = 0 ;
F_40 (sta, &local->sta_list, list) {
if ( V_16 != V_4 -> V_16 )
continue;
if ( V_12 < V_41 ) {
++ V_12 ;
continue;
}
return V_4 ;
}
return NULL ;
}
void F_22 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_42 )
F_41 ( V_4 ) ;
F_42 ( V_4 -> V_16 , L_1 , V_4 -> V_4 . V_7 ) ;
F_21 ( V_4 ) ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_44 ( & V_2 -> V_8 ) ;
V_4 -> V_10 = V_2 -> V_6 [ F_3 ( V_4 -> V_4 . V_7 ) ] ;
F_5 ( V_2 -> V_6 [ F_3 ( V_4 -> V_4 . V_7 ) ] , V_4 ) ;
}
static void F_45 ( struct V_43 * V_44 )
{
struct V_3 * V_4 ;
V_4 = F_30 ( V_44 , struct V_3 , V_31 ) ;
if ( V_4 -> V_45 )
return;
if ( ! F_8 ( V_4 , V_19 ) ) {
F_46 () ;
F_47 ( V_4 ) ;
F_48 () ;
} else if ( F_49 ( V_4 , V_46 ) ) {
F_9 ( V_4 , V_47 ) ;
F_46 () ;
F_50 ( V_4 ) ;
F_48 () ;
} else if ( F_49 ( V_4 , V_48 ) ) {
F_9 ( V_4 , V_47 ) ;
F_46 () ;
F_51 ( V_4 ) ;
F_48 () ;
} else
F_9 ( V_4 , V_47 ) ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 V_49 )
{
if ( V_2 -> V_28 . V_50 & V_51 )
return 0 ;
V_4 -> V_42 = V_2 -> V_42 ;
V_4 -> V_52 = F_53 ( V_4 -> V_42 ,
& V_4 -> V_4 , V_49 ) ;
if ( ! V_4 -> V_52 )
return - V_53 ;
return 0 ;
}
struct V_3 * F_54 ( struct V_15 * V_16 ,
const T_1 * V_7 , T_2 V_49 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 ;
struct V_54 V_55 ;
int V_12 ;
V_4 = F_55 ( sizeof( * V_4 ) + V_2 -> V_28 . V_56 , V_49 ) ;
if ( ! V_4 )
return NULL ;
F_56 ( & V_4 -> V_57 ) ;
F_57 ( & V_4 -> V_31 , F_45 ) ;
F_57 ( & V_4 -> V_33 . V_58 , V_59 ) ;
F_58 ( & V_4 -> V_33 . V_60 ) ;
memcpy ( V_4 -> V_4 . V_7 , V_7 , V_61 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_16 = V_16 ;
V_4 -> V_62 = V_63 ;
V_4 -> V_64 = V_65 ;
F_59 ( & V_55 ) ;
V_4 -> V_66 = V_55 . V_67 ;
F_60 ( & V_4 -> V_68 , 1024 , 8 ) ;
if ( F_52 ( V_2 , V_4 , V_49 ) ) {
F_21 ( V_4 ) ;
return NULL ;
}
for ( V_12 = 0 ; V_12 < V_32 ; V_12 ++ ) {
V_4 -> V_69 [ V_12 ] = V_12 ;
}
for ( V_12 = 0 ; V_12 < V_25 ; V_12 ++ ) {
F_61 ( & V_4 -> V_27 [ V_12 ] ) ;
F_61 ( & V_4 -> V_29 [ V_12 ] ) ;
}
for ( V_12 = 0 ; V_12 < V_32 ; V_12 ++ )
V_4 -> V_70 [ V_12 ] = F_62 ( V_71 ) ;
F_42 ( V_16 , L_2 , V_4 -> V_4 . V_7 ) ;
#ifdef F_14
V_4 -> V_72 = V_73 ;
F_63 ( & V_4 -> V_30 ) ;
#endif
return V_4 ;
}
static int F_64 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
if ( F_65 ( ! F_66 ( V_16 ) ) )
return - V_74 ;
if ( F_67 ( F_37 ( V_4 -> V_4 . V_7 , V_16 -> V_20 . V_7 ) ||
F_68 ( V_4 -> V_4 . V_7 ) ) )
return - V_75 ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_3 * V_4 )
{
enum V_76 V_77 ;
int V_78 = 0 ;
for ( V_77 = V_79 ; V_77 < V_4 -> V_64 ; V_77 ++ ) {
V_78 = F_70 ( V_2 , V_16 , V_4 , V_77 , V_77 + 1 ) ;
if ( V_78 )
break;
}
if ( ! V_78 ) {
if ( ! V_2 -> V_80 -> V_81 )
V_4 -> V_82 = true ;
return 0 ;
}
if ( V_16 -> V_20 . type == V_83 ) {
F_71 ( V_16 ,
L_3 ,
V_4 -> V_4 . V_7 , V_77 + 1 , V_78 ) ;
V_78 = 0 ;
}
for (; V_77 > V_79 ; V_77 -- )
F_67 ( F_70 ( V_2 , V_16 , V_4 , V_77 , V_77 - 1 ) ) ;
return V_78 ;
}
static int F_72 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_84 V_85 ;
int V_78 = 0 ;
F_44 ( & V_2 -> V_8 ) ;
if ( F_38 ( V_16 , V_4 -> V_4 . V_7 ) ) {
V_78 = - V_86 ;
goto V_87;
}
V_78 = F_69 ( V_2 , V_16 , V_4 ) ;
if ( V_78 )
goto V_87;
V_2 -> V_88 ++ ;
V_2 -> V_89 ++ ;
F_73 () ;
F_43 ( V_2 , V_4 ) ;
F_74 ( & V_4 -> V_37 , & V_2 -> V_90 ) ;
F_75 ( V_4 , V_91 ) ;
F_76 ( V_4 ) ;
F_77 ( V_4 ) ;
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
V_85 . V_92 = 0 ;
V_85 . V_93 = V_2 -> V_89 ;
F_78 ( V_16 -> V_94 , V_4 -> V_4 . V_7 , & V_85 , V_95 ) ;
F_42 ( V_16 , L_4 , V_4 -> V_4 . V_7 ) ;
F_79 () ;
F_80 ( & V_2 -> V_8 ) ;
if ( F_15 ( & V_16 -> V_20 ) )
F_16 ( V_16 ) ;
return 0 ;
V_87:
F_80 ( & V_2 -> V_8 ) ;
F_79 () ;
return V_78 ;
}
int F_81 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_78 = 0 ;
F_82 () ;
V_78 = F_64 ( V_4 ) ;
if ( V_78 ) {
F_79 () ;
goto V_96;
}
F_83 ( & V_2 -> V_8 ) ;
V_78 = F_72 ( V_4 ) ;
if ( V_78 )
goto V_96;
return 0 ;
V_96:
F_84 ( ! V_78 ) ;
F_22 ( V_2 , V_4 ) ;
return V_78 ;
}
int F_85 ( struct V_3 * V_4 )
{
int V_78 = F_81 ( V_4 ) ;
F_86 () ;
return V_78 ;
}
static inline void F_87 ( T_1 * V_97 , T_4 V_98 )
{
V_97 [ V_98 / 8 ] |= ( 1 << ( V_98 % 8 ) ) ;
}
static inline void F_88 ( T_1 * V_97 , T_4 V_98 )
{
V_97 [ V_98 / 8 ] &= ~ ( 1 << ( V_98 % 8 ) ) ;
}
static unsigned long F_89 ( int V_11 )
{
switch ( V_11 ) {
case V_99 :
return F_90 ( 6 ) | F_90 ( 7 ) ;
case V_100 :
return F_90 ( 4 ) | F_90 ( 5 ) ;
case V_101 :
return F_90 ( 0 ) | F_90 ( 3 ) ;
case V_102 :
return F_90 ( 1 ) | F_90 ( 2 ) ;
default:
F_67 ( 1 ) ;
return 0 ;
}
}
void F_11 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_17 * V_18 ;
unsigned long V_50 ;
bool V_103 = false ;
T_1 V_104 = V_4 -> V_4 . V_105 ;
int V_11 ;
T_4 V_98 ;
if ( V_4 -> V_16 -> V_20 . type == V_21 ||
V_4 -> V_16 -> V_20 . type == V_22 ) {
if ( F_91 ( ! V_4 -> V_16 -> V_23 ) )
return;
V_18 = & V_4 -> V_16 -> V_23 -> V_18 ;
V_98 = V_4 -> V_4 . V_106 ;
} else {
return;
}
if ( V_2 -> V_28 . V_50 & V_107 )
return;
if ( V_4 -> V_45 )
goto V_108;
if ( V_104 == F_90 ( V_25 ) - 1 )
V_104 = 0 ;
for ( V_11 = 0 ; V_11 < V_25 ; V_11 ++ ) {
unsigned long V_109 ;
if ( V_104 & F_90 ( V_11 ) )
continue;
V_103 |= ! F_92 ( & V_4 -> V_29 [ V_11 ] ) ||
! F_92 ( & V_4 -> V_27 [ V_11 ] ) ;
if ( V_103 )
break;
V_109 = F_89 ( V_11 ) ;
V_103 |=
V_4 -> V_110 & V_109 ;
}
V_108:
F_93 ( & V_2 -> V_111 , V_50 ) ;
if ( V_103 )
F_87 ( V_18 -> V_97 , V_98 ) ;
else
F_88 ( V_18 -> V_97 , V_98 ) ;
if ( V_2 -> V_80 -> V_112 ) {
V_2 -> V_113 = true ;
F_94 ( V_2 , & V_4 -> V_4 , V_103 ) ;
V_2 -> V_113 = false ;
}
F_95 ( & V_2 -> V_111 , V_50 ) ;
}
static bool F_96 ( struct V_3 * V_4 , struct V_114 * V_115 )
{
struct V_116 * V_117 ;
int V_118 ;
if ( ! V_115 )
return false ;
V_117 = F_97 ( V_115 ) ;
V_118 = ( V_4 -> V_119 *
V_4 -> V_16 -> V_20 . V_120 . V_121 *
32 / 15625 ) * V_122 ;
if ( V_118 < V_123 )
V_118 = V_123 ;
return F_98 ( V_63 , V_117 -> V_124 . V_63 + V_118 ) ;
}
static bool F_99 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_11 )
{
unsigned long V_50 ;
struct V_114 * V_115 ;
for (; ; ) {
F_93 ( & V_4 -> V_29 [ V_11 ] . V_57 , V_50 ) ;
V_115 = F_100 ( & V_4 -> V_29 [ V_11 ] ) ;
if ( F_96 ( V_4 , V_115 ) )
V_115 = F_101 ( & V_4 -> V_29 [ V_11 ] ) ;
else
V_115 = NULL ;
F_95 ( & V_4 -> V_29 [ V_11 ] . V_57 , V_50 ) ;
if ( ! V_115 )
break;
F_102 ( & V_2 -> V_28 , V_115 ) ;
}
for (; ; ) {
F_93 ( & V_4 -> V_27 [ V_11 ] . V_57 , V_50 ) ;
V_115 = F_100 ( & V_4 -> V_27 [ V_11 ] ) ;
if ( F_96 ( V_4 , V_115 ) )
V_115 = F_101 ( & V_4 -> V_27 [ V_11 ] ) ;
else
V_115 = NULL ;
F_95 ( & V_4 -> V_27 [ V_11 ] . V_57 , V_50 ) ;
if ( ! V_115 )
break;
V_2 -> V_26 -- ;
F_103 ( V_4 -> V_16 , L_5 ,
V_4 -> V_4 . V_7 ) ;
F_102 ( & V_2 -> V_28 , V_115 ) ;
}
F_11 ( V_4 ) ;
return ! ( F_92 ( & V_4 -> V_27 [ V_11 ] ) &&
F_92 ( & V_4 -> V_29 [ V_11 ] ) ) ;
}
static bool F_104 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_125 = false ;
int V_11 ;
if ( ! V_4 -> V_16 -> V_23 )
return false ;
for ( V_11 = 0 ; V_11 < V_25 ; V_11 ++ )
V_125 |=
F_99 ( V_2 , V_4 , V_11 ) ;
return V_125 ;
}
int T_5 F_105 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_15 * V_16 ;
int V_126 , V_12 ;
F_82 () ;
if ( ! V_4 )
return - V_9 ;
V_2 = V_4 -> V_2 ;
V_16 = V_4 -> V_16 ;
F_44 ( & V_2 -> V_8 ) ;
F_75 ( V_4 , V_127 ) ;
F_106 ( V_4 , false ) ;
V_126 = F_1 ( V_2 , V_4 ) ;
if ( V_126 )
return V_126 ;
F_107 ( & V_4 -> V_37 ) ;
F_83 ( & V_2 -> V_128 ) ;
for ( V_12 = 0 ; V_12 < V_129 ; V_12 ++ )
F_108 ( F_109 ( V_2 , V_4 -> V_130 [ V_12 ] ) ) ;
if ( V_4 -> V_131 )
F_108 ( F_109 ( V_2 , V_4 -> V_131 ) ) ;
F_80 ( & V_2 -> V_128 ) ;
V_4 -> V_45 = true ;
V_2 -> V_88 -- ;
V_2 -> V_89 ++ ;
if ( V_16 -> V_20 . type == V_22 )
F_110 ( V_16 -> V_132 . V_133 . V_4 , NULL ) ;
while ( V_4 -> V_64 > V_65 ) {
V_126 = F_111 ( V_4 , V_4 -> V_64 - 1 ) ;
if ( V_126 ) {
F_91 ( 1 ) ;
break;
}
}
if ( V_4 -> V_82 ) {
V_126 = F_70 ( V_2 , V_16 , V_4 , V_65 ,
V_79 ) ;
F_91 ( V_126 != 0 ) ;
}
F_42 ( V_16 , L_6 , V_4 -> V_4 . V_7 ) ;
F_112 ( V_16 -> V_94 , V_4 -> V_4 . V_7 , V_95 ) ;
F_113 ( V_4 ) ;
F_114 ( V_4 ) ;
F_115 ( & V_4 -> V_38 , F_29 ) ;
return 0 ;
}
int F_116 ( struct V_15 * V_16 , const T_1 * V_7 )
{
struct V_3 * V_4 ;
int V_126 ;
F_83 ( & V_16 -> V_2 -> V_8 ) ;
V_4 = F_35 ( V_16 , V_7 ) ;
V_126 = F_105 ( V_4 ) ;
F_80 ( & V_16 -> V_2 -> V_8 ) ;
return V_126 ;
}
int F_117 ( struct V_15 * V_16 ,
const T_1 * V_7 )
{
struct V_3 * V_4 ;
int V_126 ;
F_83 ( & V_16 -> V_2 -> V_8 ) ;
V_4 = F_38 ( V_16 , V_7 ) ;
V_126 = F_105 ( V_4 ) ;
F_80 ( & V_16 -> V_2 -> V_8 ) ;
return V_126 ;
}
static void F_118 ( unsigned long V_134 )
{
struct V_1 * V_2 = (struct V_1 * ) V_134 ;
struct V_3 * V_4 ;
bool V_135 = false ;
F_79 () ;
F_40 (sta, &local->sta_list, list)
if ( F_104 ( V_2 , V_4 ) )
V_135 = true ;
F_86 () ;
if ( V_2 -> V_136 )
return;
if ( ! V_135 )
return;
F_119 ( & V_2 -> V_137 ,
F_120 ( V_63 + V_138 ) ) ;
}
void F_121 ( struct V_1 * V_2 )
{
F_56 ( & V_2 -> V_111 ) ;
F_58 ( & V_2 -> V_8 ) ;
F_122 ( & V_2 -> V_90 ) ;
F_123 ( & V_2 -> V_137 , F_118 ,
( unsigned long ) V_2 ) ;
}
void F_124 ( struct V_1 * V_2 )
{
F_18 ( & V_2 -> V_137 ) ;
F_125 ( V_2 , NULL ) ;
}
int F_125 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_3 * V_4 , * V_139 ;
int V_126 = 0 ;
F_82 () ;
F_83 ( & V_2 -> V_8 ) ;
F_126 (sta, tmp, &local->sta_list, list) {
if ( ! V_16 || V_16 == V_4 -> V_16 ) {
F_67 ( F_105 ( V_4 ) ) ;
V_126 ++ ;
}
}
F_80 ( & V_2 -> V_8 ) ;
F_127 () ;
if ( V_16 ) {
F_23 ( V_16 ) ;
F_19 ( & V_16 -> V_40 ) ;
} else {
F_83 ( & V_2 -> V_140 ) ;
F_128 (sdata, &local->interfaces, list) {
F_23 ( V_16 ) ;
F_19 ( & V_16 -> V_40 ) ;
}
F_80 ( & V_2 -> V_140 ) ;
}
return V_126 ;
}
void F_129 ( struct V_15 * V_16 ,
unsigned long V_141 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 , * V_139 ;
F_83 ( & V_2 -> V_8 ) ;
F_126 (sta, tmp, &local->sta_list, list) {
if ( V_16 != V_4 -> V_16 )
continue;
if ( F_98 ( V_63 , V_4 -> V_62 + V_141 ) ) {
F_42 ( V_4 -> V_16 , L_7 ,
V_4 -> V_4 . V_7 ) ;
F_67 ( F_105 ( V_4 ) ) ;
}
}
F_80 ( & V_2 -> V_8 ) ;
}
struct V_142 * F_130 ( struct V_143 * V_28 ,
const T_1 * V_7 ,
const T_1 * V_144 )
{
struct V_3 * V_4 , * V_145 ;
F_131 (hw_to_local(hw), addr, sta, nxt) {
if ( V_144 &&
! F_37 ( V_4 -> V_16 -> V_20 . V_7 , V_144 ) )
continue;
if ( ! V_4 -> V_82 )
return NULL ;
return & V_4 -> V_4 ;
}
return NULL ;
}
struct V_142 * F_132 ( struct V_146 * V_20 ,
const T_1 * V_7 )
{
struct V_3 * V_4 ;
if ( ! V_20 )
return NULL ;
V_4 = F_38 ( F_133 ( V_20 ) , V_7 ) ;
if ( ! V_4 )
return NULL ;
if ( ! V_4 -> V_82 )
return NULL ;
return & V_4 -> V_4 ;
}
static void F_134 ( void * V_147 )
{
struct V_3 * V_4 = V_147 ;
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_17 * V_18 ;
if ( V_16 -> V_20 . type == V_21 ||
V_16 -> V_20 . type == V_22 )
V_18 = & V_16 -> V_23 -> V_18 ;
else
return;
F_9 ( V_4 , V_47 ) ;
if ( F_49 ( V_4 , V_19 ) )
F_10 ( & V_18 -> V_24 ) ;
}
void F_47 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_148 V_34 ;
int V_149 = 0 , V_150 = 0 , V_11 ;
unsigned long V_50 ;
F_9 ( V_4 , V_151 ) ;
F_135 ( F_136 ( V_32 ) > 1 ) ;
V_4 -> V_110 = 0 ;
if ( ! ( V_2 -> V_28 . V_50 & V_107 ) )
F_137 ( V_2 , V_16 , V_152 , & V_4 -> V_4 ) ;
F_61 ( & V_34 ) ;
for ( V_11 = 0 ; V_11 < V_25 ; V_11 ++ ) {
int V_153 = F_12 ( & V_34 ) , V_139 ;
F_93 ( & V_4 -> V_29 [ V_11 ] . V_57 , V_50 ) ;
F_138 ( & V_4 -> V_29 [ V_11 ] , & V_34 ) ;
F_95 ( & V_4 -> V_29 [ V_11 ] . V_57 , V_50 ) ;
V_139 = F_12 ( & V_34 ) ;
V_149 += V_139 - V_153 ;
V_153 = V_139 ;
F_93 ( & V_4 -> V_27 [ V_11 ] . V_57 , V_50 ) ;
F_138 ( & V_4 -> V_27 [ V_11 ] , & V_34 ) ;
F_95 ( & V_4 -> V_27 [ V_11 ] . V_57 , V_50 ) ;
V_139 = F_12 ( & V_34 ) ;
V_150 += V_139 - V_153 ;
}
F_139 ( V_2 , & V_34 , F_134 , V_4 ) ;
V_2 -> V_26 -= V_150 ;
F_11 ( V_4 ) ;
F_103 ( V_16 ,
L_8 ,
V_4 -> V_4 . V_7 , V_4 -> V_4 . V_106 , V_149 , V_150 ) ;
}
static void F_140 ( struct V_15 * V_16 ,
struct V_3 * V_4 , int V_154 ,
enum V_155 V_156 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_157 * V_158 ;
struct V_114 * V_115 ;
int V_159 = sizeof( * V_158 ) ;
T_6 V_160 ;
bool V_161 = F_8 ( V_4 , V_162 ) ;
struct V_116 * V_117 ;
struct V_163 * V_164 ;
if ( V_161 ) {
V_160 = F_62 ( V_165 |
V_166 |
V_167 ) ;
} else {
V_159 -= 2 ;
V_160 = F_62 ( V_165 |
V_168 |
V_167 ) ;
}
V_115 = F_141 ( V_2 -> V_28 . V_169 + V_159 ) ;
if ( ! V_115 )
return;
F_142 ( V_115 , V_2 -> V_28 . V_169 ) ;
V_158 = ( void * ) F_143 ( V_115 , V_159 ) ;
V_158 -> V_170 = V_160 ;
V_158 -> V_171 = 0 ;
memcpy ( V_158 -> V_172 , V_4 -> V_4 . V_7 , V_61 ) ;
memcpy ( V_158 -> V_173 , V_16 -> V_20 . V_7 , V_61 ) ;
memcpy ( V_158 -> V_174 , V_16 -> V_20 . V_7 , V_61 ) ;
V_115 -> V_175 = V_154 ;
F_144 ( V_115 , V_176 [ V_154 ] ) ;
if ( V_161 ) {
V_158 -> V_177 = F_62 ( V_154 ) ;
if ( V_156 == V_178 )
V_158 -> V_177 |=
F_62 ( V_179 ) ;
}
V_117 = F_97 ( V_115 ) ;
V_117 -> V_50 |= V_180 |
V_181 |
V_182 ;
F_145 ( V_2 , V_4 , F_90 ( V_154 ) , 1 , V_156 , false ) ;
F_79 () ;
V_164 = F_146 ( V_16 -> V_20 . V_164 ) ;
if ( F_67 ( ! V_164 ) ) {
F_86 () ;
F_147 ( V_115 ) ;
return;
}
F_148 ( V_16 , V_115 , V_164 -> V_183 . V_184 -> V_185 ) ;
F_86 () ;
}
static void
F_149 ( struct V_3 * V_4 ,
int V_186 , T_1 V_187 ,
enum V_155 V_156 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_2 ;
bool V_188 = false ;
bool V_189 = false ;
int V_11 ;
unsigned long V_190 = 0 ;
struct V_148 V_191 ;
F_75 ( V_4 , V_151 ) ;
F_150 ( & V_191 ) ;
for ( V_11 = 0 ; V_11 < V_25 ; V_11 ++ ) {
unsigned long V_109 ;
if ( V_187 & F_90 ( V_11 ) )
continue;
V_109 = F_89 ( V_11 ) ;
if ( ! V_188 ) {
V_190 = V_4 -> V_110 & V_109 ;
if ( V_190 ) {
V_188 = true ;
} else {
struct V_114 * V_115 ;
while ( V_186 > 0 ) {
V_115 = F_151 ( & V_4 -> V_29 [ V_11 ] ) ;
if ( ! V_115 ) {
V_115 = F_151 (
& V_4 -> V_27 [ V_11 ] ) ;
if ( V_115 )
V_2 -> V_26 -- ;
}
if ( ! V_115 )
break;
V_186 -- ;
V_188 = true ;
F_152 ( & V_191 , V_115 ) ;
}
}
if ( V_156 == V_192 &&
F_153 ( V_190 ) > 1 ) {
V_189 = true ;
V_190 =
F_90 ( F_154 ( V_190 ) - 1 ) ;
break;
}
}
if ( ! F_92 ( & V_4 -> V_29 [ V_11 ] ) ||
! F_92 ( & V_4 -> V_27 [ V_11 ] ) ) {
V_189 = true ;
break;
}
}
if ( ! V_188 ) {
int V_154 ;
V_154 = 7 - ( ( F_154 ( ~ V_187 ) - 1 ) << 1 ) ;
F_140 ( V_16 , V_4 , V_154 , V_156 ) ;
return;
}
if ( ! V_190 ) {
struct V_148 V_34 ;
struct V_114 * V_115 ;
int V_193 = 0 ;
T_4 V_109 = 0 ;
F_61 ( & V_34 ) ;
while ( ( V_115 = F_101 ( & V_191 ) ) ) {
struct V_116 * V_117 = F_97 ( V_115 ) ;
struct V_194 * V_195 = ( void * ) V_115 -> V_134 ;
T_1 * V_196 = NULL ;
V_193 ++ ;
V_117 -> V_50 |= V_180 ;
if ( V_189 || ! F_92 ( & V_191 ) )
V_195 -> V_170 |=
F_62 ( V_197 ) ;
else
V_195 -> V_170 &=
F_62 ( ~ V_197 ) ;
if ( F_155 ( V_195 -> V_170 ) ||
F_156 ( V_195 -> V_170 ) )
V_196 = F_157 ( V_195 ) ;
if ( F_92 ( & V_191 ) ) {
if ( V_156 == V_178 &&
V_196 )
* V_196 |= V_179 ;
V_117 -> V_50 |= V_181 |
V_182 ;
}
if ( V_196 )
V_109 |= F_90 ( * V_196 & V_198 ) ;
else
V_109 |= F_90 ( 0 ) ;
F_152 ( & V_34 , V_115 ) ;
}
F_145 ( V_2 , V_4 , V_109 , V_193 ,
V_156 , V_189 ) ;
F_158 ( V_2 , & V_34 ) ;
F_11 ( V_4 ) ;
} else {
F_159 ( V_2 , V_4 , V_190 ,
V_186 , V_156 , V_189 ) ;
}
}
void F_50 ( struct V_3 * V_4 )
{
T_1 V_199 = V_4 -> V_4 . V_105 ;
if ( V_199 == F_90 ( V_25 ) - 1 )
V_199 = 0 ;
F_149 ( V_4 , 1 , V_199 ,
V_192 ) ;
}
void F_51 ( struct V_3 * V_4 )
{
int V_186 = V_4 -> V_4 . V_200 ;
T_1 V_201 = V_4 -> V_4 . V_105 ;
if ( ! V_201 )
return;
switch ( V_4 -> V_4 . V_200 ) {
case 1 :
V_186 = 2 ;
break;
case 2 :
V_186 = 4 ;
break;
case 3 :
V_186 = 6 ;
break;
case 0 :
V_186 = 8 ;
break;
}
F_149 ( V_4 , V_186 , ~ V_201 ,
V_178 ) ;
}
void F_160 ( struct V_143 * V_28 ,
struct V_142 * V_202 , bool V_203 )
{
struct V_3 * V_4 = F_30 ( V_202 , struct V_3 , V_4 ) ;
F_161 ( V_4 -> V_2 , V_202 , V_203 ) ;
if ( V_203 )
F_75 ( V_4 , V_47 ) ;
else if ( F_8 ( V_4 , V_47 ) )
F_34 ( V_28 , & V_4 -> V_31 ) ;
}
void F_162 ( struct V_142 * V_202 )
{
struct V_3 * V_4 = F_30 ( V_202 , struct V_3 , V_4 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_114 * V_115 ;
struct V_204 * V_134 ;
F_163 ( V_2 , V_202 ) ;
V_115 = F_164 ( 0 , V_205 ) ;
if ( ! V_115 ) {
F_9 ( V_4 , V_151 ) ;
return;
}
V_134 = ( void * ) V_115 -> V_206 ;
memcpy ( V_134 -> V_4 , V_202 -> V_7 , V_61 ) ;
memcpy ( V_134 -> V_207 , V_4 -> V_16 -> V_20 . V_7 , V_61 ) ;
V_115 -> V_208 = V_209 ;
F_165 ( & V_2 -> V_210 , V_115 ) ;
F_166 ( & V_2 -> V_211 ) ;
}
void F_167 ( struct V_142 * V_202 ,
T_1 V_154 , bool V_150 )
{
struct V_3 * V_4 = F_30 ( V_202 , struct V_3 , V_4 ) ;
if ( F_67 ( V_154 >= V_32 ) )
return;
if ( V_150 )
F_168 ( V_154 , & V_4 -> V_110 ) ;
else
F_169 ( V_154 , & V_4 -> V_110 ) ;
F_11 ( V_4 ) ;
}
int F_111 ( struct V_3 * V_4 ,
enum V_76 V_212 )
{
F_82 () ;
if ( V_4 -> V_64 == V_212 )
return 0 ;
switch ( V_212 ) {
case V_65 :
if ( V_4 -> V_64 != V_213 )
return - V_75 ;
break;
case V_213 :
if ( V_4 -> V_64 != V_65 &&
V_4 -> V_64 != V_214 )
return - V_75 ;
break;
case V_214 :
if ( V_4 -> V_64 != V_213 &&
V_4 -> V_64 != V_215 )
return - V_75 ;
break;
case V_215 :
if ( V_4 -> V_64 != V_214 )
return - V_75 ;
break;
default:
F_170 ( 1 , L_9 , V_212 ) ;
return - V_75 ;
}
F_42 ( V_4 -> V_16 , L_10 ,
V_4 -> V_4 . V_7 , V_212 ) ;
if ( F_8 ( V_4 , V_91 ) ) {
int V_78 = F_70 ( V_4 -> V_2 , V_4 -> V_16 , V_4 ,
V_4 -> V_64 , V_212 ) ;
if ( V_78 )
return V_78 ;
}
switch ( V_212 ) {
case V_65 :
if ( V_4 -> V_64 == V_213 )
F_169 ( V_216 , & V_4 -> V_217 ) ;
break;
case V_213 :
if ( V_4 -> V_64 == V_65 )
F_168 ( V_216 , & V_4 -> V_217 ) ;
else if ( V_4 -> V_64 == V_214 )
F_169 ( V_218 , & V_4 -> V_217 ) ;
break;
case V_214 :
if ( V_4 -> V_64 == V_213 ) {
F_168 ( V_218 , & V_4 -> V_217 ) ;
} else if ( V_4 -> V_64 == V_215 ) {
if ( V_4 -> V_16 -> V_20 . type == V_21 ||
( V_4 -> V_16 -> V_20 . type == V_22 &&
! V_4 -> V_16 -> V_132 . V_133 . V_4 ) )
F_10 ( & V_4 -> V_16 -> V_23 -> V_219 ) ;
F_169 ( V_220 , & V_4 -> V_217 ) ;
}
break;
case V_215 :
if ( V_4 -> V_64 == V_214 ) {
if ( V_4 -> V_16 -> V_20 . type == V_21 ||
( V_4 -> V_16 -> V_20 . type == V_22 &&
! V_4 -> V_16 -> V_132 . V_133 . V_4 ) )
F_171 ( & V_4 -> V_16 -> V_23 -> V_219 ) ;
F_168 ( V_220 , & V_4 -> V_217 ) ;
}
break;
default:
break;
}
V_4 -> V_64 = V_212 ;
return 0 ;
}
