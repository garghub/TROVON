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
if ( V_4 -> V_12 == V_12 && ! V_4 -> V_13 &&
memcmp ( V_4 -> V_4 . V_7 , V_7 , V_14 ) == 0 )
break;
V_4 = F_8 ( V_4 -> V_10 ,
F_4 ( & V_2 -> V_8 ) ) ;
}
return V_4 ;
}
struct V_3 * F_9 ( struct V_11 * V_12 ,
const T_1 * V_7 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 ;
V_4 = F_8 ( V_2 -> V_6 [ F_3 ( V_7 ) ] ,
F_4 ( & V_2 -> V_8 ) ) ;
while ( V_4 ) {
if ( V_4 -> V_12 == V_12 &&
memcmp ( V_4 -> V_4 . V_7 , V_7 , V_14 ) == 0 )
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
( V_4 -> V_12 -> V_15 && V_4 -> V_12 -> V_15 == V_12 -> V_15 ) ) &&
! V_4 -> V_13 &&
memcmp ( V_4 -> V_4 . V_7 , V_7 , V_14 ) == 0 )
break;
V_4 = F_8 ( V_4 -> V_10 ,
F_4 ( & V_2 -> V_8 ) ) ;
}
return V_4 ;
}
struct V_3 * F_11 ( struct V_11 * V_12 ,
const T_1 * V_7 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 ;
V_4 = F_8 ( V_2 -> V_6 [ F_3 ( V_7 ) ] ,
F_4 ( & V_2 -> V_8 ) ) ;
while ( V_4 ) {
if ( ( V_4 -> V_12 == V_12 ||
( V_4 -> V_12 -> V_15 && V_4 -> V_12 -> V_15 == V_12 -> V_15 ) ) &&
memcmp ( V_4 -> V_4 . V_7 , V_7 , V_14 ) == 0 )
break;
V_4 = F_8 ( V_4 -> V_10 ,
F_4 ( & V_2 -> V_8 ) ) ;
}
return V_4 ;
}
struct V_3 * F_12 ( struct V_11 * V_12 ,
int V_16 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 ;
int V_17 = 0 ;
F_13 (sta, &local->sta_list, list) {
if ( V_12 != V_4 -> V_12 )
continue;
if ( V_17 < V_16 ) {
++ V_17 ;
continue;
}
return V_4 ;
}
return NULL ;
}
void F_14 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_18 ) {
F_15 ( V_4 ) ;
F_16 ( V_4 -> V_18 ) ;
}
#ifdef F_17
F_18 ( V_2 -> V_19 . V_20 , L_1 , V_4 -> V_4 . V_7 ) ;
#endif
F_19 ( V_4 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_21 ( & V_2 -> V_8 ) ;
V_4 -> V_10 = V_2 -> V_6 [ F_3 ( V_4 -> V_4 . V_7 ) ] ;
F_5 ( V_2 -> V_6 [ F_3 ( V_4 -> V_4 . V_7 ) ] , V_4 ) ;
}
static void F_22 ( struct V_21 * V_22 )
{
struct V_3 * V_4 ;
V_4 = F_23 ( V_22 , struct V_3 , V_23 ) ;
if ( V_4 -> V_24 )
return;
if ( ! F_24 ( V_4 , V_25 ) ) {
F_25 () ;
F_26 ( V_4 ) ;
F_27 () ;
} else if ( F_28 ( V_4 , V_26 ) ) {
F_29 ( V_4 , V_27 ) ;
F_25 () ;
F_30 ( V_4 ) ;
F_27 () ;
} else if ( F_28 ( V_4 , V_28 ) ) {
F_29 ( V_4 , V_27 ) ;
F_25 () ;
F_31 ( V_4 ) ;
F_27 () ;
} else
F_29 ( V_4 , V_27 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 V_29 )
{
if ( V_2 -> V_19 . V_30 & V_31 )
return 0 ;
V_4 -> V_18 = F_33 ( V_2 -> V_18 ) ;
V_4 -> V_32 = F_34 ( V_4 -> V_18 ,
& V_4 -> V_4 , V_29 ) ;
if ( ! V_4 -> V_32 ) {
F_16 ( V_4 -> V_18 ) ;
return - V_33 ;
}
return 0 ;
}
struct V_3 * F_35 ( struct V_11 * V_12 ,
const T_1 * V_7 , T_2 V_29 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 ;
struct V_34 V_35 ;
int V_17 ;
V_4 = F_36 ( sizeof( * V_4 ) + V_2 -> V_19 . V_36 , V_29 ) ;
if ( ! V_4 )
return NULL ;
F_37 ( & V_4 -> V_37 ) ;
F_38 ( & V_4 -> V_23 , F_22 ) ;
F_38 ( & V_4 -> V_38 . V_39 , V_40 ) ;
F_39 ( & V_4 -> V_38 . V_41 ) ;
memcpy ( V_4 -> V_4 . V_7 , V_7 , V_14 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_12 = V_12 ;
V_4 -> V_42 = V_43 ;
F_40 ( & V_35 ) ;
V_4 -> V_44 = V_35 . V_45 ;
F_41 ( & V_4 -> V_46 , 1024 , 8 ) ;
if ( F_32 ( V_2 , V_4 , V_29 ) ) {
F_19 ( V_4 ) ;
return NULL ;
}
for ( V_17 = 0 ; V_17 < V_47 ; V_17 ++ ) {
V_4 -> V_48 [ V_17 ] = V_17 ;
}
for ( V_17 = 0 ; V_17 < V_49 ; V_17 ++ ) {
F_42 ( & V_4 -> V_50 [ V_17 ] ) ;
F_42 ( & V_4 -> V_51 [ V_17 ] ) ;
}
for ( V_17 = 0 ; V_17 < V_52 ; V_17 ++ )
V_4 -> V_53 [ V_17 ] = F_43 ( V_54 ) ;
#ifdef F_17
F_18 ( V_2 -> V_19 . V_20 , L_2 , V_4 -> V_4 . V_7 ) ;
#endif
#ifdef F_44
V_4 -> V_55 = V_56 ;
F_45 ( & V_4 -> V_57 ) ;
#endif
return V_4 ;
}
static int F_46 ( struct V_3 * V_4 )
{
struct V_11 * V_12 = V_4 -> V_12 ;
if ( F_47 ( ! F_48 ( V_12 ) ) )
return - V_58 ;
if ( F_49 ( F_50 ( V_4 -> V_4 . V_7 , V_12 -> V_59 . V_7 ) == 0 ||
F_51 ( V_4 -> V_4 . V_7 ) ) )
return - V_60 ;
return 0 ;
}
static int F_52 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_11 * V_12 = V_4 -> V_12 ;
struct V_3 * V_61 ;
bool V_62 = false ;
int V_63 = 0 ;
F_21 ( & V_2 -> V_8 ) ;
V_61 = F_11 ( V_12 , V_4 -> V_4 . V_7 ) ;
if ( V_61 ) {
if ( V_61 == V_4 && V_4 -> V_13 ) {
V_62 = true ;
} else {
V_63 = - V_64 ;
goto V_65;
}
}
if ( ! V_4 -> V_13 || V_62 ) {
V_63 = F_53 ( V_2 , V_12 , & V_4 -> V_4 ) ;
if ( V_63 ) {
if ( V_12 -> V_59 . type != V_66 )
goto V_65;
F_54 ( V_67 L_3
L_4 ,
V_12 -> V_68 , V_4 -> V_4 . V_7 , V_63 ) ;
} else
V_4 -> V_69 = true ;
}
if ( ! V_62 ) {
V_2 -> V_70 ++ ;
V_2 -> V_71 ++ ;
F_55 () ;
F_20 ( V_2 , V_4 ) ;
F_56 ( & V_4 -> V_72 , & V_2 -> V_73 ) ;
} else {
V_4 -> V_13 = false ;
}
if ( ! V_4 -> V_13 ) {
struct V_74 V_75 ;
F_57 ( V_4 ) ;
F_58 ( V_4 ) ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_76 = 0 ;
V_75 . V_77 = V_2 -> V_71 ;
F_59 ( V_12 -> V_78 , V_4 -> V_4 . V_7 , & V_75 , V_79 ) ;
}
#ifdef F_17
F_18 ( V_2 -> V_19 . V_20 , L_5 ,
V_4 -> V_13 ? L_6 : L_7 , V_4 -> V_4 . V_7 ) ;
#endif
F_60 () ;
F_61 ( & V_2 -> V_8 ) ;
if ( F_62 ( & V_12 -> V_59 ) )
F_63 ( V_12 ) ;
return 0 ;
V_65:
F_61 ( & V_2 -> V_8 ) ;
F_60 () ;
return V_63 ;
}
int F_64 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_63 = 0 ;
F_65 () ;
V_63 = F_46 ( V_4 ) ;
if ( V_63 ) {
F_60 () ;
goto V_80;
}
F_66 ( & V_2 -> V_8 ) ;
V_63 = F_52 ( V_4 ) ;
if ( V_63 )
goto V_80;
return 0 ;
V_80:
F_67 ( ! V_63 ) ;
F_14 ( V_2 , V_4 ) ;
return V_63 ;
}
int F_68 ( struct V_3 * V_4 )
{
int V_63 = F_64 ( V_4 ) ;
F_69 () ;
return V_63 ;
}
int F_70 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_63 = 0 ;
V_63 = F_46 ( V_4 ) ;
if ( V_63 ) {
F_61 ( & V_2 -> V_8 ) ;
return V_63 ;
}
F_65 () ;
V_63 = F_52 ( V_4 ) ;
F_69 () ;
return V_63 ;
}
static inline void F_71 ( struct V_81 * V_15 , T_4 V_82 )
{
V_15 -> V_83 [ V_82 / 8 ] |= ( 1 << ( V_82 % 8 ) ) ;
}
static inline void F_72 ( struct V_81 * V_15 , T_4 V_82 )
{
V_15 -> V_83 [ V_82 / 8 ] &= ~ ( 1 << ( V_82 % 8 ) ) ;
}
static unsigned long F_73 ( int V_84 )
{
switch ( V_84 ) {
case V_85 :
return F_74 ( 6 ) | F_74 ( 7 ) ;
case V_86 :
return F_74 ( 4 ) | F_74 ( 5 ) ;
case V_87 :
return F_74 ( 0 ) | F_74 ( 3 ) ;
case V_88 :
return F_74 ( 1 ) | F_74 ( 2 ) ;
default:
F_49 ( 1 ) ;
return 0 ;
}
}
void F_75 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_81 * V_15 = V_4 -> V_12 -> V_15 ;
unsigned long V_30 ;
bool V_89 = false ;
T_1 V_90 = V_4 -> V_4 . V_91 ;
int V_84 ;
if ( F_76 ( ! V_4 -> V_12 -> V_15 ) )
return;
if ( V_2 -> V_19 . V_30 & V_92 )
return;
if ( V_4 -> V_24 )
goto V_93;
if ( V_90 == F_74 ( V_49 ) - 1 )
V_90 = 0 ;
for ( V_84 = 0 ; V_84 < V_49 ; V_84 ++ ) {
unsigned long V_94 ;
if ( V_90 & F_74 ( V_84 ) )
continue;
V_89 |= ! F_77 ( & V_4 -> V_51 [ V_84 ] ) ||
! F_77 ( & V_4 -> V_50 [ V_84 ] ) ;
if ( V_89 )
break;
V_94 = F_73 ( V_84 ) ;
V_89 |=
V_4 -> V_95 & V_94 ;
}
V_93:
F_78 ( & V_2 -> V_96 , V_30 ) ;
if ( V_89 )
F_71 ( V_15 , V_4 -> V_4 . V_82 ) ;
else
F_72 ( V_15 , V_4 -> V_4 . V_82 ) ;
if ( V_2 -> V_97 -> V_98 ) {
V_2 -> V_99 = true ;
F_79 ( V_2 , & V_4 -> V_4 , V_89 ) ;
V_2 -> V_99 = false ;
}
F_80 ( & V_2 -> V_96 , V_30 ) ;
}
static bool F_81 ( struct V_3 * V_4 , struct V_100 * V_101 )
{
struct V_102 * V_103 ;
int V_104 ;
if ( ! V_101 )
return false ;
V_103 = F_82 ( V_101 ) ;
V_104 = ( V_4 -> V_105 *
V_4 -> V_12 -> V_59 . V_106 . V_107 *
32 / 15625 ) * V_108 ;
if ( V_104 < V_109 )
V_104 = V_109 ;
return F_83 ( V_43 , V_103 -> V_110 . V_43 + V_104 ) ;
}
static bool F_84 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_84 )
{
unsigned long V_30 ;
struct V_100 * V_101 ;
for (; ; ) {
F_78 ( & V_4 -> V_51 [ V_84 ] . V_37 , V_30 ) ;
V_101 = F_85 ( & V_4 -> V_51 [ V_84 ] ) ;
if ( F_81 ( V_4 , V_101 ) )
V_101 = F_86 ( & V_4 -> V_51 [ V_84 ] ) ;
else
V_101 = NULL ;
F_80 ( & V_4 -> V_51 [ V_84 ] . V_37 , V_30 ) ;
if ( ! V_101 )
break;
F_87 ( V_101 ) ;
}
for (; ; ) {
F_78 ( & V_4 -> V_50 [ V_84 ] . V_37 , V_30 ) ;
V_101 = F_85 ( & V_4 -> V_50 [ V_84 ] ) ;
if ( F_81 ( V_4 , V_101 ) )
V_101 = F_86 ( & V_4 -> V_50 [ V_84 ] ) ;
else
V_101 = NULL ;
F_80 ( & V_4 -> V_50 [ V_84 ] . V_37 , V_30 ) ;
if ( ! V_101 )
break;
V_2 -> V_111 -- ;
#ifdef F_88
F_54 ( V_67 L_8 ,
V_4 -> V_4 . V_7 ) ;
#endif
F_87 ( V_101 ) ;
}
F_75 ( V_4 ) ;
return ! ( F_77 ( & V_4 -> V_50 [ V_84 ] ) &&
F_77 ( & V_4 -> V_51 [ V_84 ] ) ) ;
}
static bool F_89 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_112 = false ;
int V_84 ;
if ( ! V_4 -> V_12 -> V_15 )
return false ;
for ( V_84 = 0 ; V_84 < V_49 ; V_84 ++ )
V_112 |=
F_84 ( V_2 , V_4 , V_84 ) ;
return V_112 ;
}
static int T_5 F_90 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
int V_113 , V_17 , V_84 ;
struct V_114 * V_115 ;
F_65 () ;
if ( ! V_4 )
return - V_9 ;
V_2 = V_4 -> V_2 ;
V_12 = V_4 -> V_12 ;
F_91 ( V_4 , V_116 ) ;
F_92 ( V_4 , true ) ;
V_113 = F_1 ( V_2 , V_4 ) ;
if ( V_113 )
return V_113 ;
F_93 ( & V_4 -> V_72 ) ;
F_66 ( & V_2 -> V_117 ) ;
for ( V_17 = 0 ; V_17 < V_118 ; V_17 ++ )
F_94 ( F_95 ( V_2 , V_4 -> V_119 [ V_17 ] ) ) ;
if ( V_4 -> V_120 )
F_94 ( F_95 ( V_2 , V_4 -> V_120 ) ) ;
F_61 ( & V_2 -> V_117 ) ;
V_4 -> V_24 = true ;
if ( F_24 ( V_4 , V_25 ) ||
F_24 ( V_4 , V_27 ) ) {
F_67 ( ! V_12 -> V_15 ) ;
F_29 ( V_4 , V_25 ) ;
F_29 ( V_4 , V_27 ) ;
F_96 ( & V_12 -> V_15 -> V_121 ) ;
F_75 ( V_4 ) ;
}
V_2 -> V_70 -- ;
V_2 -> V_71 ++ ;
if ( V_12 -> V_59 . type == V_122 )
F_97 ( V_12 -> V_123 . V_124 . V_4 , NULL ) ;
while ( V_4 -> V_125 > V_126 )
F_98 ( V_4 , V_4 -> V_125 - 1 ) ;
if ( V_4 -> V_69 ) {
if ( V_12 -> V_59 . type == V_122 )
V_12 = F_23 ( V_12 -> V_15 ,
struct V_11 ,
V_123 . V_127 ) ;
F_99 ( V_2 , V_12 , & V_4 -> V_4 ) ;
V_12 = V_4 -> V_12 ;
}
F_100 () ;
for ( V_84 = 0 ; V_84 < V_49 ; V_84 ++ ) {
V_2 -> V_111 -= F_101 ( & V_4 -> V_50 [ V_84 ] ) ;
F_102 ( & V_4 -> V_50 [ V_84 ] ) ;
F_102 ( & V_4 -> V_51 [ V_84 ] ) ;
}
#ifdef F_44
if ( F_62 ( & V_12 -> V_59 ) )
F_63 ( V_12 ) ;
#endif
#ifdef F_17
F_18 ( V_2 -> V_19 . V_20 , L_9 , V_4 -> V_4 . V_7 ) ;
#endif
F_103 ( & V_4 -> V_23 ) ;
F_104 ( V_12 -> V_78 , V_4 -> V_4 . V_7 , V_79 ) ;
F_105 ( V_4 ) ;
F_106 ( V_4 ) ;
#ifdef F_44
if ( F_62 ( & V_4 -> V_12 -> V_59 ) ) {
F_107 ( V_4 ) ;
F_108 ( & V_4 -> V_57 ) ;
}
#endif
F_66 ( & V_4 -> V_38 . V_41 ) ;
for ( V_17 = 0 ; V_17 < V_47 ; V_17 ++ ) {
V_115 = F_109 ( V_4 , V_17 ) ;
if ( ! V_115 )
continue;
if ( F_101 ( & V_115 -> V_128 ) ) {
#ifdef F_110
F_18 ( V_2 -> V_19 . V_20 , L_10
L_11 ,
F_101 ( & V_115 -> V_128 ) , V_17 ) ;
#endif
F_102 ( & V_115 -> V_128 ) ;
}
F_111 ( V_115 , V_129 ) ;
}
F_61 ( & V_4 -> V_38 . V_41 ) ;
F_14 ( V_2 , V_4 ) ;
return 0 ;
}
int F_112 ( struct V_11 * V_12 , const T_1 * V_7 )
{
struct V_3 * V_4 ;
int V_113 ;
F_66 ( & V_12 -> V_2 -> V_8 ) ;
V_4 = F_9 ( V_12 , V_7 ) ;
V_113 = F_90 ( V_4 ) ;
F_61 ( & V_12 -> V_2 -> V_8 ) ;
return V_113 ;
}
int F_113 ( struct V_11 * V_12 ,
const T_1 * V_7 )
{
struct V_3 * V_4 ;
int V_113 ;
F_66 ( & V_12 -> V_2 -> V_8 ) ;
V_4 = F_11 ( V_12 , V_7 ) ;
V_113 = F_90 ( V_4 ) ;
F_61 ( & V_12 -> V_2 -> V_8 ) ;
return V_113 ;
}
static void F_114 ( unsigned long V_130 )
{
struct V_1 * V_2 = (struct V_1 * ) V_130 ;
struct V_3 * V_4 ;
bool V_131 = false ;
F_60 () ;
F_13 (sta, &local->sta_list, list)
if ( F_89 ( V_2 , V_4 ) )
V_131 = true ;
F_69 () ;
if ( V_2 -> V_132 )
return;
if ( ! V_131 )
return;
F_115 ( & V_2 -> V_133 ,
F_116 ( V_43 + V_134 ) ) ;
}
void F_117 ( struct V_1 * V_2 )
{
F_37 ( & V_2 -> V_96 ) ;
F_39 ( & V_2 -> V_8 ) ;
F_118 ( & V_2 -> V_73 ) ;
F_119 ( & V_2 -> V_133 , F_114 ,
( unsigned long ) V_2 ) ;
}
void F_120 ( struct V_1 * V_2 )
{
F_121 ( & V_2 -> V_133 ) ;
F_122 ( V_2 , NULL ) ;
}
int F_122 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_3 * V_4 , * V_135 ;
int V_113 = 0 ;
F_65 () ;
F_66 ( & V_2 -> V_8 ) ;
F_123 (sta, tmp, &local->sta_list, list) {
if ( ! V_12 || V_12 == V_4 -> V_12 )
F_49 ( F_90 ( V_4 ) ) ;
}
F_61 ( & V_2 -> V_8 ) ;
return V_113 ;
}
void F_124 ( struct V_11 * V_12 ,
unsigned long V_136 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 , * V_135 ;
F_66 ( & V_2 -> V_8 ) ;
F_123 (sta, tmp, &local->sta_list, list) {
if ( V_12 != V_4 -> V_12 )
continue;
if ( F_83 ( V_43 , V_4 -> V_42 + V_136 ) ) {
#ifdef F_125
F_54 ( V_67 L_12 ,
V_12 -> V_68 , V_4 -> V_4 . V_7 ) ;
#endif
F_49 ( F_90 ( V_4 ) ) ;
}
}
F_61 ( & V_2 -> V_8 ) ;
}
struct V_137 * F_126 ( struct V_138 * V_19 ,
const T_1 * V_7 ,
const T_1 * V_139 )
{
struct V_3 * V_4 , * V_140 ;
F_127 (hw_to_local(hw), addr, sta, nxt) {
if ( V_139 &&
F_50 ( V_4 -> V_12 -> V_59 . V_7 , V_139 ) != 0 )
continue;
if ( ! V_4 -> V_69 )
return NULL ;
return & V_4 -> V_4 ;
}
return NULL ;
}
struct V_137 * F_128 ( struct V_141 * V_59 ,
const T_1 * V_7 )
{
struct V_3 * V_4 ;
if ( ! V_59 )
return NULL ;
V_4 = F_10 ( F_129 ( V_59 ) , V_7 ) ;
if ( ! V_4 )
return NULL ;
if ( ! V_4 -> V_69 )
return NULL ;
return & V_4 -> V_4 ;
}
static void F_130 ( void * V_142 )
{
struct V_3 * V_4 = V_142 ;
F_29 ( V_4 , V_27 ) ;
F_29 ( V_4 , V_25 ) ;
}
void F_26 ( struct V_3 * V_4 )
{
struct V_11 * V_12 = V_4 -> V_12 ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_143 V_128 ;
int V_144 = 0 , V_145 = 0 , V_84 ;
F_29 ( V_4 , V_146 ) ;
F_131 ( F_132 ( V_47 ) > 1 ) ;
V_4 -> V_95 = 0 ;
if ( ! ( V_2 -> V_19 . V_30 & V_92 ) )
F_133 ( V_2 , V_12 , V_147 , & V_4 -> V_4 ) ;
F_42 ( & V_128 ) ;
for ( V_84 = 0 ; V_84 < V_49 ; V_84 ++ ) {
int V_148 = F_101 ( & V_128 ) , V_135 ;
F_134 ( & V_4 -> V_51 [ V_84 ] , & V_128 ) ;
V_135 = F_101 ( & V_128 ) ;
V_144 += V_135 - V_148 ;
V_148 = V_135 ;
F_134 ( & V_4 -> V_50 [ V_84 ] , & V_128 ) ;
V_135 = F_101 ( & V_128 ) ;
V_145 += V_135 - V_148 ;
}
F_135 ( V_2 , & V_128 , F_130 , V_4 ) ;
V_2 -> V_111 -= V_145 ;
F_75 ( V_4 ) ;
#ifdef F_88
F_54 ( V_67 L_13
L_14 , V_12 -> V_68 ,
V_4 -> V_4 . V_7 , V_4 -> V_4 . V_82 , V_144 , V_145 ) ;
#endif
}
static void F_136 ( struct V_11 * V_12 ,
struct V_3 * V_4 , int V_149 ,
enum V_150 V_151 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_152 * V_153 ;
struct V_100 * V_101 ;
int V_154 = sizeof( * V_153 ) ;
T_6 V_155 ;
bool V_156 = F_24 ( V_4 , V_157 ) ;
struct V_102 * V_103 ;
if ( V_156 ) {
V_155 = F_43 ( V_158 |
V_159 |
V_160 ) ;
} else {
V_154 -= 2 ;
V_155 = F_43 ( V_158 |
V_161 |
V_160 ) ;
}
V_101 = F_137 ( V_2 -> V_19 . V_162 + V_154 ) ;
if ( ! V_101 )
return;
F_138 ( V_101 , V_2 -> V_19 . V_162 ) ;
V_153 = ( void * ) F_139 ( V_101 , V_154 ) ;
V_153 -> V_163 = V_155 ;
V_153 -> V_164 = 0 ;
memcpy ( V_153 -> V_165 , V_4 -> V_4 . V_7 , V_14 ) ;
memcpy ( V_153 -> V_166 , V_12 -> V_59 . V_7 , V_14 ) ;
memcpy ( V_153 -> V_167 , V_12 -> V_59 . V_7 , V_14 ) ;
V_101 -> V_168 = V_149 ;
F_140 ( V_101 , V_169 [ V_149 ] ) ;
if ( V_156 ) {
V_153 -> V_170 = F_43 ( V_149 ) ;
if ( V_151 == V_171 )
V_153 -> V_170 |=
F_43 ( V_172 ) ;
}
V_103 = F_82 ( V_101 ) ;
V_103 -> V_30 |= V_173 |
V_174 |
V_175 ;
F_141 ( V_2 , V_4 , F_74 ( V_149 ) , 1 , V_151 , false ) ;
F_142 ( V_12 , V_101 ) ;
}
static void
F_143 ( struct V_3 * V_4 ,
int V_176 , T_1 V_177 ,
enum V_150 V_151 )
{
struct V_11 * V_12 = V_4 -> V_12 ;
struct V_1 * V_2 = V_12 -> V_2 ;
bool V_178 = false ;
bool V_179 = false ;
int V_84 ;
unsigned long V_180 = 0 ;
struct V_143 V_181 ;
F_91 ( V_4 , V_146 ) ;
F_144 ( & V_181 ) ;
for ( V_84 = 0 ; V_84 < V_49 ; V_84 ++ ) {
unsigned long V_94 ;
if ( V_177 & F_74 ( V_84 ) )
continue;
V_94 = F_73 ( V_84 ) ;
if ( ! V_178 ) {
V_180 = V_4 -> V_95 & V_94 ;
if ( V_180 ) {
V_178 = true ;
} else {
struct V_100 * V_101 ;
while ( V_176 > 0 ) {
V_101 = F_145 ( & V_4 -> V_51 [ V_84 ] ) ;
if ( ! V_101 ) {
V_101 = F_145 (
& V_4 -> V_50 [ V_84 ] ) ;
if ( V_101 )
V_2 -> V_111 -- ;
}
if ( ! V_101 )
break;
V_176 -- ;
V_178 = true ;
F_146 ( & V_181 , V_101 ) ;
}
}
if ( V_151 == V_182 &&
F_147 ( V_180 ) > 1 ) {
V_179 = true ;
V_180 =
F_74 ( F_148 ( V_180 ) - 1 ) ;
break;
}
}
if ( ! F_77 ( & V_4 -> V_51 [ V_84 ] ) ||
! F_77 ( & V_4 -> V_50 [ V_84 ] ) ) {
V_179 = true ;
break;
}
}
if ( ! V_178 ) {
int V_149 ;
V_149 = 7 - ( ( F_148 ( ~ V_177 ) - 1 ) << 1 ) ;
F_136 ( V_12 , V_4 , V_149 , V_151 ) ;
return;
}
if ( ! V_180 ) {
struct V_143 V_128 ;
struct V_100 * V_101 ;
int V_183 = 0 ;
T_4 V_94 = 0 ;
F_42 ( & V_128 ) ;
while ( ( V_101 = F_86 ( & V_181 ) ) ) {
struct V_102 * V_103 = F_82 ( V_101 ) ;
struct V_184 * V_185 = ( void * ) V_101 -> V_130 ;
T_1 * V_186 = NULL ;
V_183 ++ ;
V_103 -> V_30 |= V_173 ;
if ( V_179 || ! F_77 ( & V_181 ) )
V_185 -> V_163 |=
F_43 ( V_187 ) ;
else
V_185 -> V_163 &=
F_43 ( ~ V_187 ) ;
if ( F_149 ( V_185 -> V_163 ) ||
F_150 ( V_185 -> V_163 ) )
V_186 = F_151 ( V_185 ) ;
if ( V_151 == V_171 &&
V_186 && F_77 ( & V_181 ) )
* V_186 |= V_172 ;
V_103 -> V_30 |= V_174 |
V_175 ;
if ( V_186 )
V_94 |= F_74 ( * V_186 & V_188 ) ;
else
V_94 |= F_74 ( 0 ) ;
F_146 ( & V_128 , V_101 ) ;
}
F_141 ( V_2 , V_4 , V_94 , V_183 ,
V_151 , V_179 ) ;
F_152 ( V_2 , & V_128 ) ;
F_75 ( V_4 ) ;
} else {
F_153 ( V_2 , V_4 , V_180 ,
V_176 , V_151 , V_179 ) ;
}
}
void F_30 ( struct V_3 * V_4 )
{
T_1 V_189 = V_4 -> V_4 . V_91 ;
if ( V_189 == F_74 ( V_49 ) - 1 )
V_189 = 0 ;
F_143 ( V_4 , 1 , V_189 ,
V_182 ) ;
}
void F_31 ( struct V_3 * V_4 )
{
int V_176 = V_4 -> V_4 . V_190 ;
T_1 V_191 = V_4 -> V_4 . V_91 ;
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
F_143 ( V_4 , V_176 , ~ V_191 ,
V_171 ) ;
}
void F_154 ( struct V_138 * V_19 ,
struct V_137 * V_192 , bool V_193 )
{
struct V_3 * V_4 = F_23 ( V_192 , struct V_3 , V_4 ) ;
F_155 ( V_4 -> V_2 , V_192 , V_193 ) ;
if ( V_193 )
F_91 ( V_4 , V_27 ) ;
else if ( F_24 ( V_4 , V_27 ) )
F_156 ( V_19 , & V_4 -> V_23 ) ;
}
void F_157 ( struct V_137 * V_192 )
{
struct V_3 * V_4 = F_23 ( V_192 , struct V_3 , V_4 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_100 * V_101 ;
struct V_194 * V_130 ;
F_158 ( V_2 , V_192 ) ;
V_101 = F_159 ( 0 , V_195 ) ;
if ( ! V_101 ) {
F_29 ( V_4 , V_146 ) ;
return;
}
V_130 = ( void * ) V_101 -> V_196 ;
memcpy ( V_130 -> V_4 , V_192 -> V_7 , V_14 ) ;
memcpy ( V_130 -> V_197 , V_4 -> V_12 -> V_59 . V_7 , V_14 ) ;
V_101 -> V_198 = V_199 ;
F_160 ( & V_2 -> V_200 , V_101 ) ;
F_161 ( & V_2 -> V_201 ) ;
}
void F_162 ( struct V_137 * V_192 ,
T_1 V_149 , bool V_145 )
{
struct V_3 * V_4 = F_23 ( V_192 , struct V_3 , V_4 ) ;
if ( F_49 ( V_149 >= V_47 ) )
return;
if ( V_145 )
F_163 ( V_149 , & V_4 -> V_95 ) ;
else
F_164 ( V_149 , & V_4 -> V_95 ) ;
F_75 ( V_4 ) ;
}
int F_165 ( struct V_3 * V_4 ,
enum V_202 V_203 )
{
F_65 () ;
if ( V_4 -> V_125 == V_203 )
return 0 ;
switch ( V_203 ) {
case V_126 :
if ( V_4 -> V_125 == V_204 )
F_164 ( V_205 , & V_4 -> V_206 ) ;
else
return - V_60 ;
break;
case V_204 :
if ( V_4 -> V_125 == V_126 )
F_163 ( V_205 , & V_4 -> V_206 ) ;
else if ( V_4 -> V_125 == V_207 )
F_164 ( V_208 , & V_4 -> V_206 ) ;
else
return - V_60 ;
break;
case V_207 :
if ( V_4 -> V_125 == V_204 ) {
F_163 ( V_208 , & V_4 -> V_206 ) ;
} else if ( V_4 -> V_125 == V_209 ) {
if ( V_4 -> V_12 -> V_59 . type == V_210 )
F_96 ( & V_4 -> V_12 -> V_123 . V_127 . V_211 ) ;
F_164 ( V_212 , & V_4 -> V_206 ) ;
} else
return - V_60 ;
break;
case V_209 :
if ( V_4 -> V_125 == V_207 ) {
if ( V_4 -> V_12 -> V_59 . type == V_210 )
F_166 ( & V_4 -> V_12 -> V_123 . V_127 . V_211 ) ;
F_163 ( V_212 , & V_4 -> V_206 ) ;
} else
return - V_60 ;
break;
default:
F_167 ( 1 , L_15 , V_203 ) ;
return - V_60 ;
}
F_54 ( V_67 L_16 ,
V_4 -> V_12 -> V_68 , V_4 -> V_4 . V_7 , V_203 ) ;
V_4 -> V_125 = V_203 ;
return 0 ;
}
