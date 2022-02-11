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
memcpy ( V_4 -> V_4 . V_7 , V_7 , V_62 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_16 = V_16 ;
V_4 -> V_63 = V_64 ;
V_4 -> V_65 = V_66 ;
F_56 ( & V_56 ) ;
V_4 -> V_67 = V_56 . V_68 ;
F_57 ( & V_4 -> V_69 , 1024 , 8 ) ;
if ( F_49 ( V_2 , V_4 , V_50 ) ) {
F_18 ( V_4 ) ;
return NULL ;
}
for ( V_12 = 0 ; V_12 < V_33 ; V_12 ++ ) {
V_4 -> V_70 [ V_12 ] = V_12 ;
}
for ( V_12 = 0 ; V_12 < V_27 ; V_12 ++ ) {
F_58 ( & V_4 -> V_29 [ V_12 ] ) ;
F_58 ( & V_4 -> V_31 [ V_12 ] ) ;
}
for ( V_12 = 0 ; V_12 < V_33 ; V_12 ++ )
V_4 -> V_71 [ V_12 ] = F_59 ( V_72 ) ;
V_4 -> V_4 . V_73 = V_74 ;
F_39 ( V_16 , L_2 , V_4 -> V_4 . V_7 ) ;
return V_4 ;
}
static int F_60 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
if ( F_61 ( ! F_62 ( V_16 ) ) )
return - V_75 ;
if ( F_63 ( F_34 ( V_4 -> V_4 . V_7 , V_16 -> V_20 . V_7 ) ||
F_64 ( V_4 -> V_4 . V_7 ) ) )
return - V_76 ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_3 * V_4 )
{
enum V_77 V_78 ;
int V_79 = 0 ;
for ( V_78 = V_80 ; V_78 < V_4 -> V_65 ; V_78 ++ ) {
V_79 = F_66 ( V_2 , V_16 , V_4 , V_78 , V_78 + 1 ) ;
if ( V_79 )
break;
}
if ( ! V_79 ) {
if ( ! V_2 -> V_81 -> V_82 )
V_4 -> V_83 = true ;
return 0 ;
}
if ( V_16 -> V_20 . type == V_84 ) {
F_67 ( V_16 ,
L_3 ,
V_4 -> V_4 . V_7 , V_78 + 1 , V_79 ) ;
V_79 = 0 ;
}
for (; V_78 > V_80 ; V_78 -- )
F_63 ( F_66 ( V_2 , V_16 , V_4 , V_78 , V_78 - 1 ) ) ;
return V_79 ;
}
static int F_68 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_85 V_86 ;
int V_79 = 0 ;
F_41 ( & V_2 -> V_8 ) ;
if ( F_35 ( V_16 , V_4 -> V_4 . V_7 ) ) {
V_79 = - V_87 ;
goto V_88;
}
V_79 = F_65 ( V_2 , V_16 , V_4 ) ;
if ( V_79 )
goto V_88;
V_2 -> V_89 ++ ;
V_2 -> V_90 ++ ;
F_69 () ;
F_40 ( V_2 , V_4 ) ;
F_70 ( & V_4 -> V_38 , & V_2 -> V_91 ) ;
F_71 ( V_4 , V_92 ) ;
F_72 ( V_4 ) ;
F_73 ( V_4 ) ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
V_86 . V_93 = 0 ;
V_86 . V_94 = V_2 -> V_90 ;
F_74 ( V_16 -> V_95 , V_4 -> V_4 . V_7 , & V_86 , V_96 ) ;
F_39 ( V_16 , L_4 , V_4 -> V_4 . V_7 ) ;
F_75 () ;
F_76 ( & V_2 -> V_8 ) ;
if ( F_9 ( & V_16 -> V_20 ) )
F_77 ( V_16 ) ;
return 0 ;
V_88:
F_76 ( & V_2 -> V_8 ) ;
F_75 () ;
return V_79 ;
}
int F_78 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_79 = 0 ;
F_79 () ;
V_79 = F_60 ( V_4 ) ;
if ( V_79 ) {
F_75 () ;
goto V_97;
}
F_80 ( & V_2 -> V_8 ) ;
V_79 = F_68 ( V_4 ) ;
if ( V_79 )
goto V_97;
return 0 ;
V_97:
F_81 ( ! V_79 ) ;
F_19 ( V_2 , V_4 ) ;
return V_79 ;
}
int F_82 ( struct V_3 * V_4 )
{
int V_79 = F_78 ( V_4 ) ;
F_83 () ;
return V_79 ;
}
static inline void F_84 ( T_1 * V_98 , T_4 V_99 )
{
V_98 [ V_99 / 8 ] |= ( 1 << ( V_99 % 8 ) ) ;
}
static inline void F_85 ( T_1 * V_98 , T_4 V_99 )
{
V_98 [ V_99 / 8 ] &= ~ ( 1 << ( V_99 % 8 ) ) ;
}
static unsigned long F_86 ( int V_11 )
{
switch ( V_11 ) {
case V_100 :
return F_87 ( 6 ) | F_87 ( 7 ) ;
case V_101 :
return F_87 ( 4 ) | F_87 ( 5 ) ;
case V_102 :
return F_87 ( 0 ) | F_87 ( 3 ) ;
case V_103 :
return F_87 ( 1 ) | F_87 ( 2 ) ;
default:
F_63 ( 1 ) ;
return 0 ;
}
}
void F_12 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_17 * V_18 ;
bool V_104 = false ;
T_1 V_105 = V_4 -> V_4 . V_106 ;
int V_11 ;
T_4 V_99 ;
if ( V_4 -> V_16 -> V_20 . type == V_21 ||
V_4 -> V_16 -> V_20 . type == V_22 ) {
if ( F_88 ( ! V_4 -> V_16 -> V_23 ) )
return;
V_18 = & V_4 -> V_16 -> V_23 -> V_18 ;
V_99 = V_4 -> V_4 . V_107 ;
#ifdef F_89
} else if ( F_9 ( & V_4 -> V_16 -> V_20 ) ) {
V_18 = & V_4 -> V_16 -> V_24 . V_25 . V_18 ;
V_99 = F_90 ( V_4 -> V_108 ) % V_109 ;
#endif
} else {
return;
}
if ( V_2 -> V_30 . V_51 & V_110 )
return;
if ( V_4 -> V_46 )
goto V_111;
if ( V_105 == F_87 ( V_27 ) - 1 )
V_105 = 0 ;
for ( V_11 = 0 ; V_11 < V_27 ; V_11 ++ ) {
unsigned long V_112 ;
if ( V_105 & F_87 ( V_11 ) )
continue;
V_104 |= ! F_91 ( & V_4 -> V_31 [ V_11 ] ) ||
! F_91 ( & V_4 -> V_29 [ V_11 ] ) ;
if ( V_104 )
break;
V_112 = F_86 ( V_11 ) ;
V_104 |=
V_4 -> V_113 & V_112 ;
}
V_111:
F_21 ( & V_2 -> V_114 ) ;
if ( V_104 )
F_84 ( V_18 -> V_98 , V_99 ) ;
else
F_85 ( V_18 -> V_98 , V_99 ) ;
if ( V_2 -> V_81 -> V_115 ) {
V_2 -> V_116 = true ;
F_92 ( V_2 , & V_4 -> V_4 , V_104 ) ;
V_2 -> V_116 = false ;
}
F_25 ( & V_2 -> V_114 ) ;
}
static bool F_93 ( struct V_3 * V_4 , struct V_117 * V_118 )
{
struct V_119 * V_120 ;
int V_121 ;
if ( ! V_118 )
return false ;
V_120 = F_94 ( V_118 ) ;
V_121 = ( V_4 -> V_122 *
V_4 -> V_16 -> V_20 . V_123 . V_124 *
32 / 15625 ) * V_125 ;
if ( V_121 < V_126 )
V_121 = V_126 ;
return F_95 ( V_64 , V_120 -> V_127 . V_64 + V_121 ) ;
}
static bool F_96 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_11 )
{
unsigned long V_51 ;
struct V_117 * V_118 ;
for (; ; ) {
F_97 ( & V_4 -> V_31 [ V_11 ] . V_58 , V_51 ) ;
V_118 = F_98 ( & V_4 -> V_31 [ V_11 ] ) ;
if ( F_93 ( V_4 , V_118 ) )
V_118 = F_99 ( & V_4 -> V_31 [ V_11 ] ) ;
else
V_118 = NULL ;
F_100 ( & V_4 -> V_31 [ V_11 ] . V_58 , V_51 ) ;
if ( ! V_118 )
break;
F_101 ( & V_2 -> V_30 , V_118 ) ;
}
for (; ; ) {
F_97 ( & V_4 -> V_29 [ V_11 ] . V_58 , V_51 ) ;
V_118 = F_98 ( & V_4 -> V_29 [ V_11 ] ) ;
if ( F_93 ( V_4 , V_118 ) )
V_118 = F_99 ( & V_4 -> V_29 [ V_11 ] ) ;
else
V_118 = NULL ;
F_100 ( & V_4 -> V_29 [ V_11 ] . V_58 , V_51 ) ;
if ( ! V_118 )
break;
V_2 -> V_28 -- ;
F_102 ( V_4 -> V_16 , L_5 ,
V_4 -> V_4 . V_7 ) ;
F_101 ( & V_2 -> V_30 , V_118 ) ;
}
F_12 ( V_4 ) ;
return ! ( F_91 ( & V_4 -> V_29 [ V_11 ] ) &&
F_91 ( & V_4 -> V_31 [ V_11 ] ) ) ;
}
static bool F_103 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_128 = false ;
int V_11 ;
if ( ! V_4 -> V_16 -> V_23 &&
! F_9 ( & V_4 -> V_16 -> V_20 ) )
return false ;
for ( V_11 = 0 ; V_11 < V_27 ; V_11 ++ )
V_128 |=
F_96 ( V_2 , V_4 , V_11 ) ;
return V_128 ;
}
int T_5 F_104 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_15 * V_16 ;
int V_129 , V_12 ;
bool V_130 = false ;
F_79 () ;
if ( ! V_4 )
return - V_9 ;
V_2 = V_4 -> V_2 ;
V_16 = V_4 -> V_16 ;
F_41 ( & V_2 -> V_8 ) ;
F_71 ( V_4 , V_131 ) ;
F_105 ( V_4 , V_132 ) ;
V_129 = F_1 ( V_2 , V_4 ) ;
if ( V_129 )
return V_129 ;
F_106 ( & V_4 -> V_38 ) ;
F_80 ( & V_2 -> V_133 ) ;
for ( V_12 = 0 ; V_12 < V_134 ; V_12 ++ ) {
F_107 ( F_108 ( V_2 , V_4 -> V_135 [ V_12 ] ) ) ;
V_130 = true ;
}
if ( V_4 -> V_136 ) {
F_107 ( F_108 ( V_2 , V_4 -> V_136 ) ) ;
V_130 = true ;
}
F_76 ( & V_2 -> V_133 ) ;
if ( ! V_130 )
F_109 () ;
V_4 -> V_46 = true ;
V_2 -> V_89 -- ;
V_2 -> V_90 ++ ;
if ( V_16 -> V_20 . type == V_22 )
F_110 ( V_16 -> V_24 . V_137 . V_4 , NULL ) ;
while ( V_4 -> V_65 > V_66 ) {
V_129 = F_111 ( V_4 , V_4 -> V_65 - 1 ) ;
if ( V_129 ) {
F_88 ( 1 ) ;
break;
}
}
if ( V_4 -> V_83 ) {
V_129 = F_66 ( V_2 , V_16 , V_4 , V_66 ,
V_80 ) ;
F_88 ( V_129 != 0 ) ;
}
F_39 ( V_16 , L_6 , V_4 -> V_4 . V_7 ) ;
F_112 ( V_16 -> V_95 , V_4 -> V_4 . V_7 , V_96 ) ;
F_113 ( V_4 ) ;
F_114 ( V_4 ) ;
F_115 ( & V_4 -> V_39 , F_26 ) ;
return 0 ;
}
int F_116 ( struct V_15 * V_16 , const T_1 * V_7 )
{
struct V_3 * V_4 ;
int V_129 ;
F_80 ( & V_16 -> V_2 -> V_8 ) ;
V_4 = F_32 ( V_16 , V_7 ) ;
V_129 = F_104 ( V_4 ) ;
F_76 ( & V_16 -> V_2 -> V_8 ) ;
return V_129 ;
}
int F_117 ( struct V_15 * V_16 ,
const T_1 * V_7 )
{
struct V_3 * V_4 ;
int V_129 ;
F_80 ( & V_16 -> V_2 -> V_8 ) ;
V_4 = F_35 ( V_16 , V_7 ) ;
V_129 = F_104 ( V_4 ) ;
F_76 ( & V_16 -> V_2 -> V_8 ) ;
return V_129 ;
}
static void F_118 ( unsigned long V_138 )
{
struct V_1 * V_2 = (struct V_1 * ) V_138 ;
struct V_3 * V_4 ;
bool V_139 = false ;
F_75 () ;
F_37 (sta, &local->sta_list, list)
if ( F_103 ( V_2 , V_4 ) )
V_139 = true ;
F_83 () ;
if ( V_2 -> V_140 )
return;
if ( ! V_139 )
return;
F_119 ( & V_2 -> V_141 ,
F_120 ( V_64 + V_142 ) ) ;
}
void F_121 ( struct V_1 * V_2 )
{
F_53 ( & V_2 -> V_114 ) ;
F_55 ( & V_2 -> V_8 ) ;
F_122 ( & V_2 -> V_91 ) ;
F_123 ( & V_2 -> V_141 , F_118 ,
( unsigned long ) V_2 ) ;
}
void F_124 ( struct V_1 * V_2 )
{
F_125 ( & V_2 -> V_141 ) ;
}
int F_126 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 , * V_143 ;
int V_129 = 0 ;
F_79 () ;
F_80 ( & V_2 -> V_8 ) ;
F_127 (sta, tmp, &local->sta_list, list) {
if ( V_16 == V_4 -> V_16 ) {
F_63 ( F_104 ( V_4 ) ) ;
V_129 ++ ;
}
}
F_76 ( & V_2 -> V_8 ) ;
return V_129 ;
}
void F_128 ( struct V_15 * V_16 )
{
F_20 ( V_16 ) ;
F_16 ( & V_16 -> V_41 ) ;
}
void F_129 ( struct V_15 * V_16 ,
unsigned long V_144 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 , * V_143 ;
F_80 ( & V_2 -> V_8 ) ;
F_127 (sta, tmp, &local->sta_list, list) {
if ( V_16 != V_4 -> V_16 )
continue;
if ( F_95 ( V_64 , V_4 -> V_63 + V_144 ) ) {
F_39 ( V_4 -> V_16 , L_7 ,
V_4 -> V_4 . V_7 ) ;
if ( F_9 ( & V_16 -> V_20 ) &&
F_8 ( V_4 , V_19 ) )
F_11 ( & V_16 -> V_24 . V_25 . V_18 . V_26 ) ;
F_63 ( F_104 ( V_4 ) ) ;
}
}
F_76 ( & V_2 -> V_8 ) ;
}
struct V_145 * F_130 ( struct V_146 * V_30 ,
const T_1 * V_7 ,
const T_1 * V_147 )
{
struct V_3 * V_4 , * V_148 ;
F_131 (hw_to_local(hw), addr, sta, nxt) {
if ( V_147 &&
! F_34 ( V_4 -> V_16 -> V_20 . V_7 , V_147 ) )
continue;
if ( ! V_4 -> V_83 )
return NULL ;
return & V_4 -> V_4 ;
}
return NULL ;
}
struct V_145 * F_132 ( struct V_149 * V_20 ,
const T_1 * V_7 )
{
struct V_3 * V_4 ;
if ( ! V_20 )
return NULL ;
V_4 = F_35 ( F_133 ( V_20 ) , V_7 ) ;
if ( ! V_4 )
return NULL ;
if ( ! V_4 -> V_83 )
return NULL ;
return & V_4 -> V_4 ;
}
static void F_134 ( void * V_150 )
{
struct V_3 * V_4 = V_150 ;
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
struct V_151 V_35 ;
int V_152 = 0 , V_153 = 0 , V_11 ;
unsigned long V_51 ;
F_10 ( V_4 , V_154 ) ;
F_135 ( F_136 ( V_33 ) > 1 ) ;
V_4 -> V_113 = 0 ;
if ( ! ( V_2 -> V_30 . V_51 & V_110 ) )
F_137 ( V_2 , V_16 , V_155 , & V_4 -> V_4 ) ;
F_58 ( & V_35 ) ;
for ( V_11 = 0 ; V_11 < V_27 ; V_11 ++ ) {
int V_156 = F_13 ( & V_35 ) , V_143 ;
F_97 ( & V_4 -> V_31 [ V_11 ] . V_58 , V_51 ) ;
F_138 ( & V_4 -> V_31 [ V_11 ] , & V_35 ) ;
F_100 ( & V_4 -> V_31 [ V_11 ] . V_58 , V_51 ) ;
V_143 = F_13 ( & V_35 ) ;
V_152 += V_143 - V_156 ;
V_156 = V_143 ;
F_97 ( & V_4 -> V_29 [ V_11 ] . V_58 , V_51 ) ;
F_138 ( & V_4 -> V_29 [ V_11 ] , & V_35 ) ;
F_100 ( & V_4 -> V_29 [ V_11 ] . V_58 , V_51 ) ;
V_143 = F_13 ( & V_35 ) ;
V_153 += V_143 - V_156 ;
}
F_139 ( V_2 , & V_35 , F_134 , V_4 ) ;
V_2 -> V_28 -= V_153 ;
F_12 ( V_4 ) ;
F_102 ( V_16 ,
L_8 ,
V_4 -> V_4 . V_7 , V_4 -> V_4 . V_107 , V_152 , V_153 ) ;
}
static void F_140 ( struct V_15 * V_16 ,
struct V_3 * V_4 , int V_157 ,
enum V_158 V_159 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_160 * V_161 ;
struct V_117 * V_118 ;
int V_162 = sizeof( * V_161 ) ;
T_6 V_163 ;
bool V_164 = F_8 ( V_4 , V_165 ) ;
struct V_119 * V_120 ;
struct V_166 * V_167 ;
if ( V_164 ) {
V_163 = F_59 ( V_168 |
V_169 |
V_170 ) ;
} else {
V_162 -= 2 ;
V_163 = F_59 ( V_168 |
V_171 |
V_170 ) ;
}
V_118 = F_141 ( V_2 -> V_30 . V_172 + V_162 ) ;
if ( ! V_118 )
return;
F_142 ( V_118 , V_2 -> V_30 . V_172 ) ;
V_161 = ( void * ) F_143 ( V_118 , V_162 ) ;
V_161 -> V_173 = V_163 ;
V_161 -> V_174 = 0 ;
memcpy ( V_161 -> V_175 , V_4 -> V_4 . V_7 , V_62 ) ;
memcpy ( V_161 -> V_176 , V_16 -> V_20 . V_7 , V_62 ) ;
memcpy ( V_161 -> V_177 , V_16 -> V_20 . V_7 , V_62 ) ;
V_118 -> V_178 = V_157 ;
F_144 ( V_118 , V_179 [ V_157 ] ) ;
if ( V_164 ) {
V_161 -> V_180 = F_59 ( V_157 ) ;
if ( V_159 == V_181 )
V_161 -> V_180 |=
F_59 ( V_182 ) ;
}
V_120 = F_94 ( V_118 ) ;
V_120 -> V_51 |= V_183 |
V_184 |
V_185 ;
F_145 ( V_2 , V_4 , F_87 ( V_157 ) , 1 , V_159 , false ) ;
V_118 -> V_95 = V_16 -> V_95 ;
F_75 () ;
V_167 = F_146 ( V_16 -> V_20 . V_167 ) ;
if ( F_63 ( ! V_167 ) ) {
F_83 () ;
F_147 ( V_118 ) ;
return;
}
F_148 ( V_16 , V_118 , V_167 -> V_186 . V_187 -> V_188 ) ;
F_83 () ;
}
static void
F_149 ( struct V_3 * V_4 ,
int V_189 , T_1 V_190 ,
enum V_158 V_159 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_2 ;
bool V_191 = false ;
bool V_192 = false ;
int V_11 ;
unsigned long V_193 = 0 ;
struct V_151 V_194 ;
F_71 ( V_4 , V_154 ) ;
F_150 ( & V_194 ) ;
for ( V_11 = 0 ; V_11 < V_27 ; V_11 ++ ) {
unsigned long V_112 ;
if ( V_190 & F_87 ( V_11 ) )
continue;
V_112 = F_86 ( V_11 ) ;
if ( ! V_191 ) {
V_193 = V_4 -> V_113 & V_112 ;
if ( V_193 ) {
V_191 = true ;
} else {
struct V_117 * V_118 ;
while ( V_189 > 0 ) {
V_118 = F_151 ( & V_4 -> V_31 [ V_11 ] ) ;
if ( ! V_118 ) {
V_118 = F_151 (
& V_4 -> V_29 [ V_11 ] ) ;
if ( V_118 )
V_2 -> V_28 -- ;
}
if ( ! V_118 )
break;
V_189 -- ;
V_191 = true ;
F_152 ( & V_194 , V_118 ) ;
}
}
if ( V_159 == V_195 &&
F_153 ( V_193 ) > 1 ) {
V_192 = true ;
V_193 =
F_87 ( F_154 ( V_193 ) - 1 ) ;
break;
}
}
if ( ! F_91 ( & V_4 -> V_31 [ V_11 ] ) ||
! F_91 ( & V_4 -> V_29 [ V_11 ] ) ) {
V_192 = true ;
break;
}
}
if ( ! V_191 ) {
int V_157 ;
V_157 = 7 - ( ( F_154 ( ~ V_190 ) - 1 ) << 1 ) ;
F_140 ( V_16 , V_4 , V_157 , V_159 ) ;
return;
}
if ( ! V_193 ) {
struct V_151 V_35 ;
struct V_117 * V_118 ;
int V_196 = 0 ;
T_4 V_112 = 0 ;
F_58 ( & V_35 ) ;
while ( ( V_118 = F_99 ( & V_194 ) ) ) {
struct V_119 * V_120 = F_94 ( V_118 ) ;
struct V_197 * V_198 = ( void * ) V_118 -> V_138 ;
T_1 * V_199 = NULL ;
V_196 ++ ;
V_120 -> V_51 |= V_183 ;
if ( V_192 || ! F_91 ( & V_194 ) )
V_198 -> V_173 |=
F_59 ( V_200 ) ;
else
V_198 -> V_173 &=
F_59 ( ~ V_200 ) ;
if ( F_155 ( V_198 -> V_173 ) ||
F_156 ( V_198 -> V_173 ) )
V_199 = F_157 ( V_198 ) ;
if ( F_91 ( & V_194 ) ) {
if ( V_159 == V_181 &&
V_199 )
* V_199 |= V_182 ;
V_120 -> V_51 |= V_184 |
V_185 ;
}
if ( V_199 )
V_112 |= F_87 ( * V_199 & V_201 ) ;
else
V_112 |= F_87 ( 0 ) ;
F_152 ( & V_35 , V_118 ) ;
}
F_145 ( V_2 , V_4 , V_112 , V_196 ,
V_159 , V_192 ) ;
F_158 ( V_2 , & V_35 ) ;
F_12 ( V_4 ) ;
} else {
F_159 ( V_2 , V_4 , V_193 ,
V_189 , V_159 , V_192 ) ;
}
}
void F_47 ( struct V_3 * V_4 )
{
T_1 V_202 = V_4 -> V_4 . V_106 ;
if ( V_202 == F_87 ( V_27 ) - 1 )
V_202 = 0 ;
F_149 ( V_4 , 1 , V_202 ,
V_195 ) ;
}
void F_48 ( struct V_3 * V_4 )
{
int V_189 = V_4 -> V_4 . V_203 ;
T_1 V_204 = V_4 -> V_4 . V_106 ;
if ( ! V_204 )
return;
switch ( V_4 -> V_4 . V_203 ) {
case 1 :
V_189 = 2 ;
break;
case 2 :
V_189 = 4 ;
break;
case 3 :
V_189 = 6 ;
break;
case 0 :
V_189 = 8 ;
break;
}
F_149 ( V_4 , V_189 , ~ V_204 ,
V_181 ) ;
}
void F_160 ( struct V_146 * V_30 ,
struct V_145 * V_205 , bool V_206 )
{
struct V_3 * V_4 = F_27 ( V_205 , struct V_3 , V_4 ) ;
F_161 ( V_4 -> V_2 , V_205 , V_206 ) ;
if ( V_206 )
F_71 ( V_4 , V_48 ) ;
else if ( F_8 ( V_4 , V_48 ) )
F_31 ( V_30 , & V_4 -> V_32 ) ;
}
void F_162 ( struct V_145 * V_205 )
{
struct V_3 * V_4 = F_27 ( V_205 , struct V_3 , V_4 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_117 * V_118 ;
struct V_207 * V_138 ;
F_163 ( V_2 , V_205 ) ;
V_118 = F_164 ( 0 , V_208 ) ;
if ( ! V_118 ) {
F_10 ( V_4 , V_154 ) ;
return;
}
V_138 = ( void * ) V_118 -> V_209 ;
memcpy ( V_138 -> V_4 , V_205 -> V_7 , V_62 ) ;
memcpy ( V_138 -> V_210 , V_4 -> V_16 -> V_20 . V_7 , V_62 ) ;
V_118 -> V_211 = V_212 ;
F_165 ( & V_2 -> V_213 , V_118 ) ;
F_166 ( & V_2 -> V_214 ) ;
}
void F_167 ( struct V_145 * V_205 ,
T_1 V_157 , bool V_153 )
{
struct V_3 * V_4 = F_27 ( V_205 , struct V_3 , V_4 ) ;
if ( F_63 ( V_157 >= V_33 ) )
return;
if ( V_153 )
F_168 ( V_157 , & V_4 -> V_113 ) ;
else
F_169 ( V_157 , & V_4 -> V_113 ) ;
F_12 ( V_4 ) ;
}
int F_111 ( struct V_3 * V_4 ,
enum V_77 V_215 )
{
F_79 () ;
if ( V_4 -> V_65 == V_215 )
return 0 ;
switch ( V_215 ) {
case V_66 :
if ( V_4 -> V_65 != V_216 )
return - V_76 ;
break;
case V_216 :
if ( V_4 -> V_65 != V_66 &&
V_4 -> V_65 != V_217 )
return - V_76 ;
break;
case V_217 :
if ( V_4 -> V_65 != V_216 &&
V_4 -> V_65 != V_218 )
return - V_76 ;
break;
case V_218 :
if ( V_4 -> V_65 != V_217 )
return - V_76 ;
break;
default:
F_170 ( 1 , L_9 , V_215 ) ;
return - V_76 ;
}
F_39 ( V_4 -> V_16 , L_10 ,
V_4 -> V_4 . V_7 , V_215 ) ;
if ( F_8 ( V_4 , V_92 ) ) {
int V_79 = F_66 ( V_4 -> V_2 , V_4 -> V_16 , V_4 ,
V_4 -> V_65 , V_215 ) ;
if ( V_79 )
return V_79 ;
}
switch ( V_215 ) {
case V_66 :
if ( V_4 -> V_65 == V_216 )
F_169 ( V_219 , & V_4 -> V_220 ) ;
break;
case V_216 :
if ( V_4 -> V_65 == V_66 )
F_168 ( V_219 , & V_4 -> V_220 ) ;
else if ( V_4 -> V_65 == V_217 )
F_169 ( V_221 , & V_4 -> V_220 ) ;
break;
case V_217 :
if ( V_4 -> V_65 == V_216 ) {
F_168 ( V_221 , & V_4 -> V_220 ) ;
} else if ( V_4 -> V_65 == V_218 ) {
if ( V_4 -> V_16 -> V_20 . type == V_21 ||
( V_4 -> V_16 -> V_20 . type == V_22 &&
! V_4 -> V_16 -> V_24 . V_137 . V_4 ) )
F_11 ( & V_4 -> V_16 -> V_23 -> V_222 ) ;
F_169 ( V_223 , & V_4 -> V_220 ) ;
}
break;
case V_218 :
if ( V_4 -> V_65 == V_217 ) {
if ( V_4 -> V_16 -> V_20 . type == V_21 ||
( V_4 -> V_16 -> V_20 . type == V_22 &&
! V_4 -> V_16 -> V_24 . V_137 . V_4 ) )
F_171 ( & V_4 -> V_16 -> V_23 -> V_222 ) ;
F_168 ( V_223 , & V_4 -> V_220 ) ;
}
break;
default:
break;
}
V_4 -> V_65 = V_215 ;
return 0 ;
}
