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
V_14 = F_17 ( V_4 -> V_34 . V_14 [ V_12 ] ) ;
if ( ! V_14 )
continue;
F_14 ( & V_2 -> V_30 , & V_14 -> V_35 ) ;
F_18 ( V_14 ) ;
}
F_19 ( V_2 , V_4 ) ;
}
void F_20 ( struct V_15 * V_16 )
{
struct V_3 * V_4 ;
F_21 ( & V_16 -> V_36 ) ;
while ( ! F_22 ( & V_16 -> V_37 ) ) {
V_4 = F_23 ( & V_16 -> V_37 ,
struct V_3 , V_38 ) ;
F_24 ( & V_4 -> V_38 ) ;
F_25 ( & V_16 -> V_36 ) ;
F_7 ( V_4 ) ;
F_21 ( & V_16 -> V_36 ) ;
}
F_25 ( & V_16 -> V_36 ) ;
}
static void F_26 ( struct V_39 * V_40 )
{
struct V_3 * V_4 = F_27 ( V_40 , struct V_3 , V_39 ) ;
struct V_15 * V_16 = V_4 -> V_16 ;
F_28 ( & V_16 -> V_36 ) ;
F_29 ( & V_4 -> V_38 , & V_16 -> V_37 ) ;
F_30 ( & V_16 -> V_36 ) ;
F_31 ( & V_16 -> V_2 -> V_30 , & V_16 -> V_41 ) ;
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
int V_42 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 ;
int V_12 = 0 ;
F_37 (sta, &local->sta_list, list) {
if ( V_16 != V_4 -> V_16 )
continue;
if ( V_12 < V_42 ) {
++ V_12 ;
continue;
}
return V_4 ;
}
return NULL ;
}
void F_19 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_43 )
F_38 ( V_4 ) ;
F_39 ( V_4 -> V_16 , L_1 , V_4 -> V_4 . V_7 ) ;
F_18 ( V_4 ) ;
}
static void F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_41 ( & V_2 -> V_8 ) ;
V_4 -> V_10 = V_2 -> V_6 [ F_3 ( V_4 -> V_4 . V_7 ) ] ;
F_5 ( V_2 -> V_6 [ F_3 ( V_4 -> V_4 . V_7 ) ] , V_4 ) ;
}
static void F_42 ( struct V_44 * V_45 )
{
struct V_3 * V_4 ;
V_4 = F_27 ( V_45 , struct V_3 , V_32 ) ;
if ( V_4 -> V_46 )
return;
if ( ! F_8 ( V_4 , V_19 ) ) {
F_43 () ;
F_44 ( V_4 ) ;
F_45 () ;
} else if ( F_46 ( V_4 , V_47 ) ) {
F_10 ( V_4 , V_48 ) ;
F_43 () ;
F_47 ( V_4 ) ;
F_45 () ;
} else if ( F_46 ( V_4 , V_49 ) ) {
F_10 ( V_4 , V_48 ) ;
F_43 () ;
F_48 ( V_4 ) ;
F_45 () ;
} else
F_10 ( V_4 , V_48 ) ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 V_50 )
{
if ( V_2 -> V_30 . V_51 & V_52 )
return 0 ;
V_4 -> V_43 = V_2 -> V_43 ;
V_4 -> V_53 = F_50 ( V_4 -> V_43 ,
& V_4 -> V_4 , V_50 ) ;
if ( ! V_4 -> V_53 )
return - V_54 ;
return 0 ;
}
struct V_3 * F_51 ( struct V_15 * V_16 ,
const T_1 * V_7 , T_2 V_50 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 ;
struct V_55 V_56 ;
int V_12 ;
V_4 = F_52 ( sizeof( * V_4 ) + V_2 -> V_30 . V_57 , V_50 ) ;
if ( ! V_4 )
return NULL ;
F_53 ( & V_4 -> V_58 ) ;
F_54 ( & V_4 -> V_32 , F_42 ) ;
F_54 ( & V_4 -> V_34 . V_59 , V_60 ) ;
F_55 ( & V_4 -> V_34 . V_61 ) ;
#ifdef F_56
if ( F_9 ( & V_16 -> V_20 ) &&
! V_16 -> V_24 . V_25 . V_62 )
F_57 ( & V_4 -> V_63 ) ;
#endif
memcpy ( V_4 -> V_4 . V_7 , V_7 , V_64 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_16 = V_16 ;
V_4 -> V_65 = V_66 ;
V_4 -> V_67 = V_68 ;
F_58 ( & V_56 ) ;
V_4 -> V_69 = V_56 . V_70 ;
F_59 ( & V_4 -> V_71 , 1024 , 8 ) ;
if ( F_49 ( V_2 , V_4 , V_50 ) ) {
F_18 ( V_4 ) ;
return NULL ;
}
for ( V_12 = 0 ; V_12 < V_33 ; V_12 ++ ) {
V_4 -> V_72 [ V_12 ] = V_12 ;
}
for ( V_12 = 0 ; V_12 < V_27 ; V_12 ++ ) {
F_60 ( & V_4 -> V_29 [ V_12 ] ) ;
F_60 ( & V_4 -> V_31 [ V_12 ] ) ;
}
for ( V_12 = 0 ; V_12 < V_33 ; V_12 ++ )
V_4 -> V_73 [ V_12 ] = F_61 ( V_74 ) ;
V_4 -> V_4 . V_75 = V_76 ;
F_39 ( V_16 , L_2 , V_4 -> V_4 . V_7 ) ;
return V_4 ;
}
static int F_62 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
if ( F_63 ( ! F_64 ( V_16 ) ) )
return - V_77 ;
if ( F_65 ( F_34 ( V_4 -> V_4 . V_7 , V_16 -> V_20 . V_7 ) ||
F_66 ( V_4 -> V_4 . V_7 ) ) )
return - V_78 ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_3 * V_4 )
{
enum V_79 V_80 ;
int V_81 = 0 ;
for ( V_80 = V_82 ; V_80 < V_4 -> V_67 ; V_80 ++ ) {
V_81 = F_68 ( V_2 , V_16 , V_4 , V_80 , V_80 + 1 ) ;
if ( V_81 )
break;
}
if ( ! V_81 ) {
if ( ! V_2 -> V_83 -> V_84 )
V_4 -> V_85 = true ;
return 0 ;
}
if ( V_16 -> V_20 . type == V_86 ) {
F_69 ( V_16 ,
L_3 ,
V_4 -> V_4 . V_7 , V_80 + 1 , V_81 ) ;
V_81 = 0 ;
}
for (; V_80 > V_82 ; V_80 -- )
F_65 ( F_68 ( V_2 , V_16 , V_4 , V_80 , V_80 - 1 ) ) ;
return V_81 ;
}
static int F_70 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_87 V_88 ;
int V_81 = 0 ;
F_41 ( & V_2 -> V_8 ) ;
if ( F_35 ( V_16 , V_4 -> V_4 . V_7 ) ) {
V_81 = - V_89 ;
goto V_90;
}
V_81 = F_67 ( V_2 , V_16 , V_4 ) ;
if ( V_81 )
goto V_90;
V_2 -> V_91 ++ ;
V_2 -> V_92 ++ ;
F_71 () ;
F_40 ( V_2 , V_4 ) ;
F_72 ( & V_4 -> V_38 , & V_2 -> V_93 ) ;
F_73 ( V_4 , V_94 ) ;
F_74 ( V_4 ) ;
F_75 ( V_4 ) ;
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
V_88 . V_95 = 0 ;
V_88 . V_96 = V_2 -> V_92 ;
F_76 ( V_16 -> V_97 , V_4 -> V_4 . V_7 , & V_88 , V_98 ) ;
F_39 ( V_16 , L_4 , V_4 -> V_4 . V_7 ) ;
F_77 () ;
F_78 ( & V_2 -> V_8 ) ;
if ( F_9 ( & V_16 -> V_20 ) )
F_79 ( V_16 ) ;
return 0 ;
V_90:
F_78 ( & V_2 -> V_8 ) ;
F_77 () ;
return V_81 ;
}
int F_80 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_81 = 0 ;
F_81 () ;
V_81 = F_62 ( V_4 ) ;
if ( V_81 ) {
F_77 () ;
goto V_99;
}
F_82 ( & V_2 -> V_8 ) ;
V_81 = F_70 ( V_4 ) ;
if ( V_81 )
goto V_99;
return 0 ;
V_99:
F_83 ( ! V_81 ) ;
F_19 ( V_2 , V_4 ) ;
return V_81 ;
}
int F_84 ( struct V_3 * V_4 )
{
int V_81 = F_80 ( V_4 ) ;
F_85 () ;
return V_81 ;
}
static inline void F_86 ( T_1 * V_100 , T_4 V_101 )
{
V_100 [ V_101 / 8 ] |= ( 1 << ( V_101 % 8 ) ) ;
}
static inline void F_87 ( T_1 * V_100 , T_4 V_101 )
{
V_100 [ V_101 / 8 ] &= ~ ( 1 << ( V_101 % 8 ) ) ;
}
static inline bool F_88 ( T_1 * V_100 , T_4 V_101 )
{
return V_100 [ V_101 / 8 ] & ( 1 << ( V_101 % 8 ) ) ;
}
static unsigned long F_89 ( int V_11 )
{
switch ( V_11 ) {
case V_102 :
return F_90 ( 6 ) | F_90 ( 7 ) ;
case V_103 :
return F_90 ( 4 ) | F_90 ( 5 ) ;
case V_104 :
return F_90 ( 0 ) | F_90 ( 3 ) ;
case V_105 :
return F_90 ( 1 ) | F_90 ( 2 ) ;
default:
F_65 ( 1 ) ;
return 0 ;
}
}
void F_12 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_17 * V_18 ;
bool V_106 = false ;
T_1 V_107 = V_4 -> V_4 . V_108 ;
int V_11 ;
T_4 V_101 ;
if ( V_4 -> V_16 -> V_20 . type == V_21 ||
V_4 -> V_16 -> V_20 . type == V_22 ) {
if ( F_91 ( ! V_4 -> V_16 -> V_23 ) )
return;
V_18 = & V_4 -> V_16 -> V_23 -> V_18 ;
V_101 = V_4 -> V_4 . V_109 ;
#ifdef F_56
} else if ( F_9 ( & V_4 -> V_16 -> V_20 ) ) {
V_18 = & V_4 -> V_16 -> V_24 . V_25 . V_18 ;
V_101 = F_92 ( V_4 -> V_110 ) % V_111 ;
#endif
} else {
return;
}
if ( V_2 -> V_30 . V_51 & V_112 )
return;
if ( V_4 -> V_46 )
goto V_113;
if ( V_107 == F_90 ( V_27 ) - 1 )
V_107 = 0 ;
for ( V_11 = 0 ; V_11 < V_27 ; V_11 ++ ) {
unsigned long V_114 ;
if ( V_107 & F_90 ( V_11 ) )
continue;
V_106 |= ! F_93 ( & V_4 -> V_31 [ V_11 ] ) ||
! F_93 ( & V_4 -> V_29 [ V_11 ] ) ;
if ( V_106 )
break;
V_114 = F_89 ( V_11 ) ;
V_106 |=
V_4 -> V_115 & V_114 ;
}
V_113:
F_21 ( & V_2 -> V_116 ) ;
if ( V_106 == F_88 ( V_18 -> V_100 , V_101 ) )
goto V_117;
if ( V_106 )
F_86 ( V_18 -> V_100 , V_101 ) ;
else
F_87 ( V_18 -> V_100 , V_101 ) ;
if ( V_2 -> V_83 -> V_118 ) {
V_2 -> V_119 = true ;
F_94 ( V_2 , & V_4 -> V_4 , V_106 ) ;
V_2 -> V_119 = false ;
}
V_117:
F_25 ( & V_2 -> V_116 ) ;
}
static bool F_95 ( struct V_3 * V_4 , struct V_120 * V_121 )
{
struct V_122 * V_123 ;
int V_124 ;
if ( ! V_121 )
return false ;
V_123 = F_96 ( V_121 ) ;
V_124 = ( V_4 -> V_125 *
V_4 -> V_16 -> V_20 . V_126 . V_127 *
32 / 15625 ) * V_128 ;
if ( V_124 < V_129 )
V_124 = V_129 ;
return F_97 ( V_66 , V_123 -> V_130 . V_66 + V_124 ) ;
}
static bool F_98 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_11 )
{
unsigned long V_51 ;
struct V_120 * V_121 ;
for (; ; ) {
F_99 ( & V_4 -> V_31 [ V_11 ] . V_58 , V_51 ) ;
V_121 = F_100 ( & V_4 -> V_31 [ V_11 ] ) ;
if ( F_95 ( V_4 , V_121 ) )
V_121 = F_101 ( & V_4 -> V_31 [ V_11 ] ) ;
else
V_121 = NULL ;
F_102 ( & V_4 -> V_31 [ V_11 ] . V_58 , V_51 ) ;
if ( ! V_121 )
break;
F_103 ( & V_2 -> V_30 , V_121 ) ;
}
for (; ; ) {
F_99 ( & V_4 -> V_29 [ V_11 ] . V_58 , V_51 ) ;
V_121 = F_100 ( & V_4 -> V_29 [ V_11 ] ) ;
if ( F_95 ( V_4 , V_121 ) )
V_121 = F_101 ( & V_4 -> V_29 [ V_11 ] ) ;
else
V_121 = NULL ;
F_102 ( & V_4 -> V_29 [ V_11 ] . V_58 , V_51 ) ;
if ( ! V_121 )
break;
V_2 -> V_28 -- ;
F_104 ( V_4 -> V_16 , L_5 ,
V_4 -> V_4 . V_7 ) ;
F_103 ( & V_2 -> V_30 , V_121 ) ;
}
F_12 ( V_4 ) ;
return ! ( F_93 ( & V_4 -> V_29 [ V_11 ] ) &&
F_93 ( & V_4 -> V_31 [ V_11 ] ) ) ;
}
static bool F_105 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_131 = false ;
int V_11 ;
if ( ! V_4 -> V_16 -> V_23 &&
! F_9 ( & V_4 -> V_16 -> V_20 ) )
return false ;
for ( V_11 = 0 ; V_11 < V_27 ; V_11 ++ )
V_131 |=
F_98 ( V_2 , V_4 , V_11 ) ;
return V_131 ;
}
int T_5 F_106 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_15 * V_16 ;
int V_132 ;
F_81 () ;
if ( ! V_4 )
return - V_9 ;
V_2 = V_4 -> V_2 ;
V_16 = V_4 -> V_16 ;
F_41 ( & V_2 -> V_8 ) ;
F_73 ( V_4 , V_133 ) ;
F_107 ( V_4 , V_134 ) ;
V_132 = F_1 ( V_2 , V_4 ) ;
if ( V_132 )
return V_132 ;
F_108 ( & V_4 -> V_38 ) ;
F_109 ( V_2 , V_4 ) ;
V_4 -> V_46 = true ;
V_2 -> V_91 -- ;
V_2 -> V_92 ++ ;
if ( V_16 -> V_20 . type == V_22 )
F_110 ( V_16 -> V_24 . V_135 . V_4 , NULL ) ;
while ( V_4 -> V_67 > V_68 ) {
V_132 = F_111 ( V_4 , V_4 -> V_67 - 1 ) ;
if ( V_132 ) {
F_91 ( 1 ) ;
break;
}
}
if ( V_4 -> V_85 ) {
V_132 = F_68 ( V_2 , V_16 , V_4 , V_68 ,
V_82 ) ;
F_91 ( V_132 != 0 ) ;
}
F_39 ( V_16 , L_6 , V_4 -> V_4 . V_7 ) ;
F_112 ( V_16 -> V_97 , V_4 -> V_4 . V_7 , V_98 ) ;
F_113 ( V_4 ) ;
F_114 ( V_4 ) ;
F_115 ( & V_4 -> V_39 , F_26 ) ;
return 0 ;
}
int F_116 ( struct V_15 * V_16 , const T_1 * V_7 )
{
struct V_3 * V_4 ;
int V_132 ;
F_82 ( & V_16 -> V_2 -> V_8 ) ;
V_4 = F_32 ( V_16 , V_7 ) ;
V_132 = F_106 ( V_4 ) ;
F_78 ( & V_16 -> V_2 -> V_8 ) ;
return V_132 ;
}
int F_117 ( struct V_15 * V_16 ,
const T_1 * V_7 )
{
struct V_3 * V_4 ;
int V_132 ;
F_82 ( & V_16 -> V_2 -> V_8 ) ;
V_4 = F_35 ( V_16 , V_7 ) ;
V_132 = F_106 ( V_4 ) ;
F_78 ( & V_16 -> V_2 -> V_8 ) ;
return V_132 ;
}
static void F_118 ( unsigned long V_136 )
{
struct V_1 * V_2 = (struct V_1 * ) V_136 ;
struct V_3 * V_4 ;
bool V_137 = false ;
F_77 () ;
F_37 (sta, &local->sta_list, list)
if ( F_105 ( V_2 , V_4 ) )
V_137 = true ;
F_85 () ;
if ( V_2 -> V_138 )
return;
if ( ! V_137 )
return;
F_119 ( & V_2 -> V_139 ,
F_120 ( V_66 + V_140 ) ) ;
}
void F_121 ( struct V_1 * V_2 )
{
F_53 ( & V_2 -> V_116 ) ;
F_55 ( & V_2 -> V_8 ) ;
F_122 ( & V_2 -> V_93 ) ;
F_123 ( & V_2 -> V_139 , F_118 ,
( unsigned long ) V_2 ) ;
}
void F_124 ( struct V_1 * V_2 )
{
F_125 ( & V_2 -> V_139 ) ;
}
int F_126 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 , * V_141 ;
int V_132 = 0 ;
F_81 () ;
F_82 ( & V_2 -> V_8 ) ;
F_127 (sta, tmp, &local->sta_list, list) {
if ( V_16 == V_4 -> V_16 ) {
F_65 ( F_106 ( V_4 ) ) ;
V_132 ++ ;
}
}
F_78 ( & V_2 -> V_8 ) ;
return V_132 ;
}
void F_128 ( struct V_15 * V_16 )
{
F_20 ( V_16 ) ;
F_16 ( & V_16 -> V_41 ) ;
}
void F_129 ( struct V_15 * V_16 ,
unsigned long V_142 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 , * V_141 ;
F_82 ( & V_2 -> V_8 ) ;
F_127 (sta, tmp, &local->sta_list, list) {
if ( V_16 != V_4 -> V_16 )
continue;
if ( F_97 ( V_66 , V_4 -> V_65 + V_142 ) ) {
F_39 ( V_4 -> V_16 , L_7 ,
V_4 -> V_4 . V_7 ) ;
if ( F_9 ( & V_16 -> V_20 ) &&
F_8 ( V_4 , V_19 ) )
F_11 ( & V_16 -> V_24 . V_25 . V_18 . V_26 ) ;
F_65 ( F_106 ( V_4 ) ) ;
}
}
F_78 ( & V_2 -> V_8 ) ;
}
struct V_143 * F_130 ( struct V_144 * V_30 ,
const T_1 * V_7 ,
const T_1 * V_145 )
{
struct V_3 * V_4 , * V_146 ;
F_131 (hw_to_local(hw), addr, sta, nxt) {
if ( V_145 &&
! F_34 ( V_4 -> V_16 -> V_20 . V_7 , V_145 ) )
continue;
if ( ! V_4 -> V_85 )
return NULL ;
return & V_4 -> V_4 ;
}
return NULL ;
}
struct V_143 * F_132 ( struct V_147 * V_20 ,
const T_1 * V_7 )
{
struct V_3 * V_4 ;
if ( ! V_20 )
return NULL ;
V_4 = F_35 ( F_133 ( V_20 ) , V_7 ) ;
if ( ! V_4 )
return NULL ;
if ( ! V_4 -> V_85 )
return NULL ;
return & V_4 -> V_4 ;
}
static void F_134 ( void * V_148 )
{
struct V_3 * V_4 = V_148 ;
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_17 * V_18 ;
if ( V_16 -> V_20 . type == V_21 ||
V_16 -> V_20 . type == V_22 )
V_18 = & V_16 -> V_23 -> V_18 ;
else if ( F_9 ( & V_16 -> V_20 ) )
V_18 = & V_16 -> V_24 . V_25 . V_18 ;
else
return;
F_10 ( V_4 , V_48 ) ;
if ( F_46 ( V_4 , V_19 ) )
F_11 ( & V_18 -> V_26 ) ;
}
void F_44 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_149 V_35 ;
int V_150 = 0 , V_151 = 0 , V_11 ;
unsigned long V_51 ;
F_10 ( V_4 , V_152 ) ;
F_135 ( F_136 ( V_33 ) > 1 ) ;
V_4 -> V_115 = 0 ;
if ( ! ( V_2 -> V_30 . V_51 & V_112 ) )
F_137 ( V_2 , V_16 , V_153 , & V_4 -> V_4 ) ;
F_60 ( & V_35 ) ;
for ( V_11 = 0 ; V_11 < V_27 ; V_11 ++ ) {
int V_154 = F_13 ( & V_35 ) , V_141 ;
F_99 ( & V_4 -> V_31 [ V_11 ] . V_58 , V_51 ) ;
F_138 ( & V_4 -> V_31 [ V_11 ] , & V_35 ) ;
F_102 ( & V_4 -> V_31 [ V_11 ] . V_58 , V_51 ) ;
V_141 = F_13 ( & V_35 ) ;
V_150 += V_141 - V_154 ;
V_154 = V_141 ;
F_99 ( & V_4 -> V_29 [ V_11 ] . V_58 , V_51 ) ;
F_138 ( & V_4 -> V_29 [ V_11 ] , & V_35 ) ;
F_102 ( & V_4 -> V_29 [ V_11 ] . V_58 , V_51 ) ;
V_141 = F_13 ( & V_35 ) ;
V_151 += V_141 - V_154 ;
}
F_139 ( V_2 , & V_35 , F_134 , V_4 ) ;
V_2 -> V_28 -= V_151 ;
F_12 ( V_4 ) ;
F_104 ( V_16 ,
L_8 ,
V_4 -> V_4 . V_7 , V_4 -> V_4 . V_109 , V_150 , V_151 ) ;
}
static void F_140 ( struct V_15 * V_16 ,
struct V_3 * V_4 , int V_155 ,
enum V_156 V_157 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_158 * V_159 ;
struct V_120 * V_121 ;
int V_160 = sizeof( * V_159 ) ;
T_6 V_161 ;
bool V_162 = F_8 ( V_4 , V_163 ) ;
struct V_122 * V_123 ;
struct V_164 * V_165 ;
if ( V_162 ) {
V_161 = F_61 ( V_166 |
V_167 |
V_168 ) ;
} else {
V_160 -= 2 ;
V_161 = F_61 ( V_166 |
V_169 |
V_168 ) ;
}
V_121 = F_141 ( V_2 -> V_30 . V_170 + V_160 ) ;
if ( ! V_121 )
return;
F_142 ( V_121 , V_2 -> V_30 . V_170 ) ;
V_159 = ( void * ) F_143 ( V_121 , V_160 ) ;
V_159 -> V_171 = V_161 ;
V_159 -> V_172 = 0 ;
memcpy ( V_159 -> V_173 , V_4 -> V_4 . V_7 , V_64 ) ;
memcpy ( V_159 -> V_174 , V_16 -> V_20 . V_7 , V_64 ) ;
memcpy ( V_159 -> V_175 , V_16 -> V_20 . V_7 , V_64 ) ;
V_121 -> V_176 = V_155 ;
F_144 ( V_121 , V_177 [ V_155 ] ) ;
if ( V_162 ) {
V_159 -> V_178 = F_61 ( V_155 ) ;
if ( V_157 == V_179 )
V_159 -> V_178 |=
F_61 ( V_180 ) ;
}
V_123 = F_96 ( V_121 ) ;
V_123 -> V_51 |= V_181 |
V_182 |
V_183 ;
F_145 ( V_2 , V_4 , F_90 ( V_155 ) , 1 , V_157 , false ) ;
V_121 -> V_97 = V_16 -> V_97 ;
F_77 () ;
V_165 = F_146 ( V_16 -> V_20 . V_165 ) ;
if ( F_65 ( ! V_165 ) ) {
F_85 () ;
F_147 ( V_121 ) ;
return;
}
F_148 ( V_16 , V_121 , V_165 -> V_184 . V_185 -> V_186 ) ;
F_85 () ;
}
static void
F_149 ( struct V_3 * V_4 ,
int V_187 , T_1 V_188 ,
enum V_156 V_157 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_2 ;
bool V_189 = false ;
bool V_190 = false ;
int V_11 ;
unsigned long V_191 = 0 ;
struct V_149 V_192 ;
F_73 ( V_4 , V_152 ) ;
F_150 ( & V_192 ) ;
for ( V_11 = 0 ; V_11 < V_27 ; V_11 ++ ) {
unsigned long V_114 ;
if ( V_188 & F_90 ( V_11 ) )
continue;
V_114 = F_89 ( V_11 ) ;
if ( ! V_189 ) {
V_191 = V_4 -> V_115 & V_114 ;
if ( V_191 ) {
V_189 = true ;
} else {
struct V_120 * V_121 ;
while ( V_187 > 0 ) {
V_121 = F_151 ( & V_4 -> V_31 [ V_11 ] ) ;
if ( ! V_121 ) {
V_121 = F_151 (
& V_4 -> V_29 [ V_11 ] ) ;
if ( V_121 )
V_2 -> V_28 -- ;
}
if ( ! V_121 )
break;
V_187 -- ;
V_189 = true ;
F_152 ( & V_192 , V_121 ) ;
}
}
if ( V_157 == V_193 &&
F_153 ( V_191 ) > 1 ) {
V_190 = true ;
V_191 =
F_90 ( F_154 ( V_191 ) - 1 ) ;
break;
}
}
if ( ! F_93 ( & V_4 -> V_31 [ V_11 ] ) ||
! F_93 ( & V_4 -> V_29 [ V_11 ] ) ) {
V_190 = true ;
break;
}
}
if ( ! V_189 ) {
int V_155 ;
V_155 = 7 - ( ( F_154 ( ~ V_188 ) - 1 ) << 1 ) ;
F_140 ( V_16 , V_4 , V_155 , V_157 ) ;
return;
}
if ( ! V_191 ) {
struct V_149 V_35 ;
struct V_120 * V_121 ;
int V_194 = 0 ;
T_4 V_114 = 0 ;
F_60 ( & V_35 ) ;
while ( ( V_121 = F_101 ( & V_192 ) ) ) {
struct V_122 * V_123 = F_96 ( V_121 ) ;
struct V_195 * V_196 = ( void * ) V_121 -> V_136 ;
T_1 * V_197 = NULL ;
V_194 ++ ;
V_123 -> V_51 |= V_181 ;
if ( V_190 || ! F_93 ( & V_192 ) )
V_196 -> V_171 |=
F_61 ( V_198 ) ;
else
V_196 -> V_171 &=
F_61 ( ~ V_198 ) ;
if ( F_155 ( V_196 -> V_171 ) ||
F_156 ( V_196 -> V_171 ) )
V_197 = F_157 ( V_196 ) ;
if ( F_93 ( & V_192 ) ) {
if ( V_157 == V_179 &&
V_197 )
* V_197 |= V_180 ;
V_123 -> V_51 |= V_182 |
V_183 ;
}
if ( V_197 )
V_114 |= F_90 ( * V_197 & V_199 ) ;
else
V_114 |= F_90 ( 0 ) ;
F_152 ( & V_35 , V_121 ) ;
}
F_145 ( V_2 , V_4 , V_114 , V_194 ,
V_157 , V_190 ) ;
F_158 ( V_2 , & V_35 ) ;
F_12 ( V_4 ) ;
} else {
F_159 ( V_2 , V_4 , V_191 ,
V_187 , V_157 , V_190 ) ;
}
}
void F_47 ( struct V_3 * V_4 )
{
T_1 V_200 = V_4 -> V_4 . V_108 ;
if ( V_200 == F_90 ( V_27 ) - 1 )
V_200 = 0 ;
F_149 ( V_4 , 1 , V_200 ,
V_193 ) ;
}
void F_48 ( struct V_3 * V_4 )
{
int V_187 = V_4 -> V_4 . V_201 ;
T_1 V_202 = V_4 -> V_4 . V_108 ;
if ( ! V_202 )
return;
switch ( V_4 -> V_4 . V_201 ) {
case 1 :
V_187 = 2 ;
break;
case 2 :
V_187 = 4 ;
break;
case 3 :
V_187 = 6 ;
break;
case 0 :
V_187 = 8 ;
break;
}
F_149 ( V_4 , V_187 , ~ V_202 ,
V_179 ) ;
}
void F_160 ( struct V_144 * V_30 ,
struct V_143 * V_203 , bool V_204 )
{
struct V_3 * V_4 = F_27 ( V_203 , struct V_3 , V_4 ) ;
F_161 ( V_4 -> V_2 , V_203 , V_204 ) ;
if ( V_204 )
F_73 ( V_4 , V_48 ) ;
else if ( F_8 ( V_4 , V_48 ) )
F_31 ( V_30 , & V_4 -> V_32 ) ;
}
void F_162 ( struct V_143 * V_203 )
{
struct V_3 * V_4 = F_27 ( V_203 , struct V_3 , V_4 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_163 ( V_2 , V_203 ) ;
F_10 ( V_4 , V_152 ) ;
}
void F_164 ( struct V_143 * V_203 ,
T_1 V_155 , bool V_151 )
{
struct V_3 * V_4 = F_27 ( V_203 , struct V_3 , V_4 ) ;
if ( F_65 ( V_155 >= V_33 ) )
return;
if ( V_151 )
F_165 ( V_155 , & V_4 -> V_115 ) ;
else
F_166 ( V_155 , & V_4 -> V_115 ) ;
F_12 ( V_4 ) ;
}
int F_111 ( struct V_3 * V_4 ,
enum V_79 V_205 )
{
F_81 () ;
if ( V_4 -> V_67 == V_205 )
return 0 ;
switch ( V_205 ) {
case V_68 :
if ( V_4 -> V_67 != V_206 )
return - V_78 ;
break;
case V_206 :
if ( V_4 -> V_67 != V_68 &&
V_4 -> V_67 != V_207 )
return - V_78 ;
break;
case V_207 :
if ( V_4 -> V_67 != V_206 &&
V_4 -> V_67 != V_208 )
return - V_78 ;
break;
case V_208 :
if ( V_4 -> V_67 != V_207 )
return - V_78 ;
break;
default:
F_167 ( 1 , L_9 , V_205 ) ;
return - V_78 ;
}
F_39 ( V_4 -> V_16 , L_10 ,
V_4 -> V_4 . V_7 , V_205 ) ;
if ( F_8 ( V_4 , V_94 ) ) {
int V_81 = F_68 ( V_4 -> V_2 , V_4 -> V_16 , V_4 ,
V_4 -> V_67 , V_205 ) ;
if ( V_81 )
return V_81 ;
}
switch ( V_205 ) {
case V_68 :
if ( V_4 -> V_67 == V_206 )
F_166 ( V_209 , & V_4 -> V_210 ) ;
break;
case V_206 :
if ( V_4 -> V_67 == V_68 )
F_165 ( V_209 , & V_4 -> V_210 ) ;
else if ( V_4 -> V_67 == V_207 )
F_166 ( V_211 , & V_4 -> V_210 ) ;
break;
case V_207 :
if ( V_4 -> V_67 == V_206 ) {
F_165 ( V_211 , & V_4 -> V_210 ) ;
} else if ( V_4 -> V_67 == V_208 ) {
if ( V_4 -> V_16 -> V_20 . type == V_21 ||
( V_4 -> V_16 -> V_20 . type == V_22 &&
! V_4 -> V_16 -> V_24 . V_135 . V_4 ) )
F_11 ( & V_4 -> V_16 -> V_23 -> V_212 ) ;
F_166 ( V_213 , & V_4 -> V_210 ) ;
}
break;
case V_208 :
if ( V_4 -> V_67 == V_207 ) {
if ( V_4 -> V_16 -> V_20 . type == V_21 ||
( V_4 -> V_16 -> V_20 . type == V_22 &&
! V_4 -> V_16 -> V_24 . V_135 . V_4 ) )
F_168 ( & V_4 -> V_16 -> V_23 -> V_212 ) ;
F_165 ( V_213 , & V_4 -> V_210 ) ;
}
break;
default:
break;
}
V_4 -> V_67 = V_205 ;
return 0 ;
}
