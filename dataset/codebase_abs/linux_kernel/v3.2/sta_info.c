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
F_4 ( & V_2 -> V_8 ) ||
F_4 ( & V_2 -> V_13 ) ) ;
while ( V_4 ) {
if ( V_4 -> V_12 == V_12 && ! V_4 -> V_14 &&
memcmp ( V_4 -> V_4 . V_7 , V_7 , V_15 ) == 0 )
break;
V_4 = F_8 ( V_4 -> V_10 ,
F_4 ( & V_2 -> V_8 ) ||
F_4 ( & V_2 -> V_13 ) ) ;
}
return V_4 ;
}
struct V_3 * F_9 ( struct V_11 * V_12 ,
const T_1 * V_7 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 ;
V_4 = F_8 ( V_2 -> V_6 [ F_3 ( V_7 ) ] ,
F_4 ( & V_2 -> V_8 ) ||
F_4 ( & V_2 -> V_13 ) ) ;
while ( V_4 ) {
if ( V_4 -> V_12 == V_12 &&
memcmp ( V_4 -> V_4 . V_7 , V_7 , V_15 ) == 0 )
break;
V_4 = F_8 ( V_4 -> V_10 ,
F_4 ( & V_2 -> V_8 ) ||
F_4 ( & V_2 -> V_13 ) ) ;
}
return V_4 ;
}
struct V_3 * F_10 ( struct V_11 * V_12 ,
const T_1 * V_7 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 ;
V_4 = F_8 ( V_2 -> V_6 [ F_3 ( V_7 ) ] ,
F_4 ( & V_2 -> V_8 ) ||
F_4 ( & V_2 -> V_13 ) ) ;
while ( V_4 ) {
if ( ( V_4 -> V_12 == V_12 ||
( V_4 -> V_12 -> V_16 && V_4 -> V_12 -> V_16 == V_12 -> V_16 ) ) &&
! V_4 -> V_14 &&
memcmp ( V_4 -> V_4 . V_7 , V_7 , V_15 ) == 0 )
break;
V_4 = F_8 ( V_4 -> V_10 ,
F_4 ( & V_2 -> V_8 ) ||
F_4 ( & V_2 -> V_13 ) ) ;
}
return V_4 ;
}
struct V_3 * F_11 ( struct V_11 * V_12 ,
const T_1 * V_7 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 ;
V_4 = F_8 ( V_2 -> V_6 [ F_3 ( V_7 ) ] ,
F_4 ( & V_2 -> V_8 ) ||
F_4 ( & V_2 -> V_13 ) ) ;
while ( V_4 ) {
if ( ( V_4 -> V_12 == V_12 ||
( V_4 -> V_12 -> V_16 && V_4 -> V_12 -> V_16 == V_12 -> V_16 ) ) &&
memcmp ( V_4 -> V_4 . V_7 , V_7 , V_15 ) == 0 )
break;
V_4 = F_8 ( V_4 -> V_10 ,
F_4 ( & V_2 -> V_8 ) ||
F_4 ( & V_2 -> V_13 ) ) ;
}
return V_4 ;
}
struct V_3 * F_12 ( struct V_11 * V_12 ,
int V_17 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 ;
int V_18 = 0 ;
F_13 (sta, &local->sta_list, list) {
if ( V_12 != V_4 -> V_12 )
continue;
if ( V_18 < V_17 ) {
++ V_18 ;
continue;
}
return V_4 ;
}
return NULL ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_19 ) {
F_15 ( V_4 ) ;
F_16 ( V_4 -> V_19 ) ;
}
#ifdef F_17
F_18 ( V_2 -> V_20 . V_21 , L_1 , V_4 -> V_4 . V_7 ) ;
#endif
F_19 ( V_4 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_10 = V_2 -> V_6 [ F_3 ( V_4 -> V_4 . V_7 ) ] ;
F_5 ( V_2 -> V_6 [ F_3 ( V_4 -> V_4 . V_7 ) ] , V_4 ) ;
}
static void F_21 ( struct V_22 * V_23 )
{
struct V_3 * V_4 ;
V_4 = F_22 ( V_23 , struct V_3 , V_24 ) ;
if ( V_4 -> V_25 )
return;
if ( ! F_23 ( V_4 , V_26 ) )
F_24 ( V_4 ) ;
else if ( F_25 ( V_4 , V_27 ) ) {
F_26 ( V_4 , V_28 ) ;
F_27 () ;
F_28 ( V_4 ) ;
F_29 () ;
} else if ( F_25 ( V_4 , V_29 ) ) {
F_26 ( V_4 , V_28 ) ;
F_27 () ;
F_30 ( V_4 ) ;
F_29 () ;
} else
F_26 ( V_4 , V_28 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 V_30 )
{
if ( V_2 -> V_20 . V_31 & V_32 )
return 0 ;
V_4 -> V_19 = F_32 ( V_2 -> V_19 ) ;
V_4 -> V_33 = F_33 ( V_4 -> V_19 ,
& V_4 -> V_4 , V_30 ) ;
if ( ! V_4 -> V_33 ) {
F_16 ( V_4 -> V_19 ) ;
return - V_34 ;
}
return 0 ;
}
struct V_3 * F_34 ( struct V_11 * V_12 ,
T_1 * V_7 , T_2 V_30 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 ;
struct V_35 V_36 ;
int V_18 ;
V_4 = F_35 ( sizeof( * V_4 ) + V_2 -> V_20 . V_37 , V_30 ) ;
if ( ! V_4 )
return NULL ;
F_36 ( & V_4 -> V_38 ) ;
F_37 ( & V_4 -> V_24 , F_21 ) ;
F_37 ( & V_4 -> V_39 . V_40 , V_41 ) ;
F_38 ( & V_4 -> V_39 . V_42 ) ;
memcpy ( V_4 -> V_4 . V_7 , V_7 , V_15 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_12 = V_12 ;
V_4 -> V_43 = V_44 ;
F_39 ( & V_36 ) ;
V_4 -> V_45 = V_36 . V_46 ;
F_40 ( & V_4 -> V_47 , 1024 , 8 ) ;
if ( F_31 ( V_2 , V_4 , V_30 ) ) {
F_19 ( V_4 ) ;
return NULL ;
}
for ( V_18 = 0 ; V_18 < V_48 ; V_18 ++ ) {
V_4 -> V_49 [ V_18 ] = V_18 ;
}
for ( V_18 = 0 ; V_18 < V_50 ; V_18 ++ ) {
F_41 ( & V_4 -> V_51 [ V_18 ] ) ;
F_41 ( & V_4 -> V_52 [ V_18 ] ) ;
}
for ( V_18 = 0 ; V_18 < V_53 ; V_18 ++ )
V_4 -> V_54 [ V_18 ] = F_42 ( V_55 ) ;
#ifdef F_17
F_18 ( V_2 -> V_20 . V_21 , L_2 , V_4 -> V_4 . V_7 ) ;
#endif
#ifdef F_43
V_4 -> V_56 = V_57 ;
F_44 ( & V_4 -> V_58 ) ;
#endif
return V_4 ;
}
static int F_45 ( struct V_3 * V_4 ,
bool V_59 , bool V_60 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_11 * V_12 = V_4 -> V_12 ;
struct V_61 V_62 ;
unsigned long V_31 ;
int V_63 = 0 ;
F_46 ( & V_2 -> V_13 ) ;
if ( ! V_4 -> V_14 || V_60 ) {
if ( V_12 -> V_64 . type == V_65 )
V_12 = F_22 ( V_12 -> V_16 ,
struct V_11 ,
V_66 . V_67 ) ;
V_63 = F_47 ( V_2 , V_12 , & V_4 -> V_4 ) ;
if ( V_63 ) {
if ( ! V_59 )
return V_63 ;
F_48 ( V_68 L_3
L_4 ,
V_12 -> V_69 , V_4 -> V_4 . V_7 , V_63 ) ;
} else {
V_4 -> V_70 = true ;
#ifdef F_17
if ( V_59 )
F_18 ( V_2 -> V_20 . V_21 ,
L_5 ,
V_4 -> V_4 . V_7 ) ;
#endif
}
V_12 = V_4 -> V_12 ;
}
if ( ! V_60 ) {
if ( ! V_59 ) {
V_2 -> V_71 ++ ;
V_2 -> V_72 ++ ;
F_49 () ;
F_50 ( & V_2 -> V_8 , V_31 ) ;
F_20 ( V_2 , V_4 ) ;
F_51 ( & V_2 -> V_8 , V_31 ) ;
}
F_52 ( & V_4 -> V_73 , & V_2 -> V_74 ) ;
} else {
V_4 -> V_14 = false ;
}
if ( ! V_4 -> V_14 ) {
F_53 ( V_4 ) ;
F_54 ( V_4 ) ;
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
V_62 . V_75 = 0 ;
V_62 . V_76 = V_2 -> V_72 ;
F_55 ( V_12 -> V_77 , V_4 -> V_4 . V_7 , & V_62 , V_78 ) ;
}
return 0 ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_31 ;
F_50 ( & V_2 -> V_8 , V_31 ) ;
while ( ! F_57 ( & V_2 -> V_79 ) ) {
V_4 = F_58 ( & V_2 -> V_79 ,
struct V_3 , V_73 ) ;
F_59 ( & V_4 -> V_73 ) ;
F_51 ( & V_2 -> V_8 , V_31 ) ;
F_45 ( V_4 , true , false ) ;
F_50 ( & V_2 -> V_8 , V_31 ) ;
}
F_51 ( & V_2 -> V_8 , V_31 ) ;
}
static void F_60 ( struct V_22 * V_40 )
{
struct V_1 * V_2 =
F_22 ( V_40 , struct V_1 , V_80 ) ;
F_61 ( & V_2 -> V_13 ) ;
F_56 ( V_2 ) ;
F_62 ( & V_2 -> V_13 ) ;
}
static int F_63 ( struct V_3 * V_4 )
{
struct V_11 * V_12 = V_4 -> V_12 ;
if ( F_64 ( ! F_65 ( V_12 ) ) )
return - V_81 ;
if ( F_66 ( F_67 ( V_4 -> V_4 . V_7 , V_12 -> V_64 . V_7 ) == 0 ||
F_68 ( V_4 -> V_4 . V_7 ) ) )
return - V_82 ;
return 0 ;
}
static int F_69 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_11 * V_12 = V_4 -> V_12 ;
unsigned long V_31 ;
F_50 ( & V_2 -> V_8 , V_31 ) ;
if ( F_11 ( V_12 , V_4 -> V_4 . V_7 ) ) {
F_51 ( & V_2 -> V_8 , V_31 ) ;
F_70 () ;
return - V_83 ;
}
V_2 -> V_71 ++ ;
V_2 -> V_72 ++ ;
F_49 () ;
F_20 ( V_2 , V_4 ) ;
F_71 ( & V_4 -> V_73 , & V_2 -> V_79 ) ;
F_70 () ;
F_51 ( & V_2 -> V_8 , V_31 ) ;
#ifdef F_17
F_18 ( V_2 -> V_20 . V_21 , L_6 ,
V_4 -> V_4 . V_7 ) ;
#endif
F_72 ( & V_2 -> V_20 , & V_2 -> V_80 ) ;
return 0 ;
}
static int F_73 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_11 * V_12 = V_4 -> V_12 ;
unsigned long V_31 ;
struct V_3 * V_84 ;
bool V_60 = false ;
int V_63 = 0 ;
F_46 ( & V_2 -> V_13 ) ;
F_50 ( & V_2 -> V_8 , V_31 ) ;
V_84 = F_11 ( V_12 , V_4 -> V_4 . V_7 ) ;
if ( V_84 ) {
if ( V_84 == V_4 && V_4 -> V_14 ) {
V_60 = true ;
} else {
F_51 ( & V_2 -> V_8 , V_31 ) ;
F_62 ( & V_2 -> V_13 ) ;
F_70 () ;
return - V_83 ;
}
}
F_51 ( & V_2 -> V_8 , V_31 ) ;
V_63 = F_45 ( V_4 , false , V_60 ) ;
if ( V_63 ) {
F_62 ( & V_2 -> V_13 ) ;
F_70 () ;
return V_63 ;
}
#ifdef F_17
F_18 ( V_2 -> V_20 . V_21 , L_7 ,
V_4 -> V_14 ? L_8 : L_9 , V_4 -> V_4 . V_7 ) ;
#endif
F_70 () ;
F_62 ( & V_2 -> V_13 ) ;
if ( F_74 ( & V_12 -> V_64 ) )
F_75 ( V_12 ) ;
return 0 ;
}
int F_76 ( struct V_3 * V_4 ) __acquires( T_3 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_11 * V_12 = V_4 -> V_12 ;
int V_63 = 0 ;
V_63 = F_63 ( V_4 ) ;
if ( V_63 ) {
F_70 () ;
goto V_85;
}
if ( V_12 -> V_64 . type == V_86 ) {
V_63 = F_69 ( V_4 ) ;
if ( V_63 )
goto V_85;
return 0 ;
}
F_77 () ;
F_61 ( & V_2 -> V_13 ) ;
V_63 = F_73 ( V_4 ) ;
if ( V_63 )
goto V_85;
return 0 ;
V_85:
F_78 ( ! V_63 ) ;
F_14 ( V_2 , V_4 ) ;
return V_63 ;
}
int F_79 ( struct V_3 * V_4 )
{
int V_63 = F_76 ( V_4 ) ;
F_80 () ;
return V_63 ;
}
int F_81 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_63 = 0 ;
V_63 = F_63 ( V_4 ) ;
if ( V_63 ) {
F_62 ( & V_2 -> V_13 ) ;
return V_63 ;
}
F_77 () ;
V_63 = F_73 ( V_4 ) ;
F_80 () ;
return V_63 ;
}
static inline void F_82 ( struct V_87 * V_16 , T_4 V_88 )
{
V_16 -> V_89 [ V_88 / 8 ] |= ( 1 << ( V_88 % 8 ) ) ;
}
static inline void F_83 ( struct V_87 * V_16 , T_4 V_88 )
{
V_16 -> V_89 [ V_88 / 8 ] &= ~ ( 1 << ( V_88 % 8 ) ) ;
}
static unsigned long F_84 ( int V_90 )
{
switch ( V_90 ) {
case V_91 :
return F_85 ( 6 ) | F_85 ( 7 ) ;
case V_92 :
return F_85 ( 4 ) | F_85 ( 5 ) ;
case V_93 :
return F_85 ( 0 ) | F_85 ( 3 ) ;
case V_94 :
return F_85 ( 1 ) | F_85 ( 2 ) ;
default:
F_66 ( 1 ) ;
return 0 ;
}
}
void F_86 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_87 * V_16 = V_4 -> V_12 -> V_16 ;
unsigned long V_31 ;
bool V_95 = false ;
T_1 V_96 = V_4 -> V_4 . V_97 ;
int V_90 ;
if ( F_87 ( ! V_4 -> V_12 -> V_16 ) )
return;
if ( V_2 -> V_20 . V_31 & V_98 )
return;
if ( V_4 -> V_25 )
goto V_99;
if ( V_96 == F_85 ( V_50 ) - 1 )
V_96 = 0 ;
for ( V_90 = 0 ; V_90 < V_50 ; V_90 ++ ) {
unsigned long V_100 ;
if ( V_96 & F_85 ( V_90 ) )
continue;
V_95 |= ! F_88 ( & V_4 -> V_52 [ V_90 ] ) ||
! F_88 ( & V_4 -> V_51 [ V_90 ] ) ;
if ( V_95 )
break;
V_100 = F_84 ( V_90 ) ;
V_95 |=
V_4 -> V_101 & V_100 ;
}
V_99:
F_50 ( & V_2 -> V_8 , V_31 ) ;
if ( V_95 )
F_82 ( V_16 , V_4 -> V_4 . V_88 ) ;
else
F_83 ( V_16 , V_4 -> V_4 . V_88 ) ;
if ( V_2 -> V_102 -> V_103 ) {
V_2 -> V_104 = true ;
F_89 ( V_2 , & V_4 -> V_4 , V_95 ) ;
V_2 -> V_104 = false ;
}
F_51 ( & V_2 -> V_8 , V_31 ) ;
}
static bool F_90 ( struct V_3 * V_4 , struct V_105 * V_106 )
{
struct V_107 * V_108 ;
int V_109 ;
if ( ! V_106 )
return false ;
V_108 = F_91 ( V_106 ) ;
V_109 = ( V_4 -> V_110 *
V_4 -> V_12 -> V_64 . V_111 . V_112 *
32 / 15625 ) * V_113 ;
if ( V_109 < V_114 )
V_109 = V_114 ;
return F_92 ( V_44 , V_108 -> V_115 . V_44 + V_109 ) ;
}
static bool F_93 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_90 )
{
unsigned long V_31 ;
struct V_105 * V_106 ;
for (; ; ) {
F_50 ( & V_4 -> V_52 [ V_90 ] . V_38 , V_31 ) ;
V_106 = F_94 ( & V_4 -> V_52 [ V_90 ] ) ;
if ( F_90 ( V_4 , V_106 ) )
V_106 = F_95 ( & V_4 -> V_52 [ V_90 ] ) ;
else
V_106 = NULL ;
F_51 ( & V_4 -> V_52 [ V_90 ] . V_38 , V_31 ) ;
if ( ! V_106 )
break;
F_96 ( V_106 ) ;
}
for (; ; ) {
F_50 ( & V_4 -> V_51 [ V_90 ] . V_38 , V_31 ) ;
V_106 = F_94 ( & V_4 -> V_51 [ V_90 ] ) ;
if ( F_90 ( V_4 , V_106 ) )
V_106 = F_95 ( & V_4 -> V_51 [ V_90 ] ) ;
else
V_106 = NULL ;
F_51 ( & V_4 -> V_51 [ V_90 ] . V_38 , V_31 ) ;
if ( ! V_106 )
break;
V_2 -> V_116 -- ;
#ifdef F_97
F_48 ( V_68 L_10 ,
V_4 -> V_4 . V_7 ) ;
#endif
F_96 ( V_106 ) ;
}
F_86 ( V_4 ) ;
return ! ( F_88 ( & V_4 -> V_51 [ V_90 ] ) &&
F_88 ( & V_4 -> V_52 [ V_90 ] ) ) ;
}
static bool F_98 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_117 = false ;
int V_90 ;
if ( ! V_4 -> V_12 -> V_16 )
return false ;
for ( V_90 = 0 ; V_90 < V_50 ; V_90 ++ )
V_117 |=
F_93 ( V_2 , V_4 , V_90 ) ;
return V_117 ;
}
static int T_5 F_99 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
unsigned long V_31 ;
int V_118 , V_18 , V_90 ;
F_77 () ;
if ( ! V_4 )
return - V_9 ;
V_2 = V_4 -> V_2 ;
V_12 = V_4 -> V_12 ;
F_100 ( V_4 , V_119 ) ;
F_101 ( V_4 , true ) ;
F_50 ( & V_2 -> V_8 , V_31 ) ;
V_118 = F_1 ( V_2 , V_4 ) ;
if ( ! V_118 )
F_59 ( & V_4 -> V_73 ) ;
F_51 ( & V_2 -> V_8 , V_31 ) ;
if ( V_118 )
return V_118 ;
F_61 ( & V_2 -> V_120 ) ;
for ( V_18 = 0 ; V_18 < V_121 ; V_18 ++ )
F_102 ( F_103 ( V_2 , V_4 -> V_122 [ V_18 ] ) ) ;
if ( V_4 -> V_123 )
F_102 ( F_103 ( V_2 , V_4 -> V_123 ) ) ;
F_62 ( & V_2 -> V_120 ) ;
V_4 -> V_25 = true ;
if ( F_23 ( V_4 , V_26 ) ||
F_23 ( V_4 , V_28 ) ) {
F_78 ( ! V_12 -> V_16 ) ;
F_26 ( V_4 , V_26 ) ;
F_26 ( V_4 , V_28 ) ;
F_104 ( & V_12 -> V_16 -> V_124 ) ;
F_86 ( V_4 ) ;
}
V_2 -> V_71 -- ;
V_2 -> V_72 ++ ;
if ( V_12 -> V_64 . type == V_65 )
F_5 ( V_12 -> V_66 . V_125 . V_4 , NULL ) ;
if ( V_4 -> V_70 ) {
if ( V_12 -> V_64 . type == V_65 )
V_12 = F_22 ( V_12 -> V_16 ,
struct V_11 ,
V_66 . V_67 ) ;
F_105 ( V_2 , V_12 , & V_4 -> V_4 ) ;
V_12 = V_4 -> V_12 ;
}
F_106 () ;
for ( V_90 = 0 ; V_90 < V_50 ; V_90 ++ ) {
V_2 -> V_116 -= F_107 ( & V_4 -> V_51 [ V_90 ] ) ;
F_108 ( & V_4 -> V_51 [ V_90 ] ) ;
F_108 ( & V_4 -> V_52 [ V_90 ] ) ;
}
#ifdef F_43
if ( F_74 ( & V_12 -> V_64 ) )
F_75 ( V_12 ) ;
#endif
#ifdef F_17
F_18 ( V_2 -> V_20 . V_21 , L_11 , V_4 -> V_4 . V_7 ) ;
#endif
F_109 ( & V_4 -> V_24 ) ;
F_110 ( V_12 -> V_77 , V_4 -> V_4 . V_7 , V_78 ) ;
F_111 ( V_4 ) ;
F_112 ( V_4 ) ;
#ifdef F_43
if ( F_74 ( & V_4 -> V_12 -> V_64 ) ) {
F_113 ( V_4 ) ;
F_114 ( & V_4 -> V_58 ) ;
}
#endif
F_14 ( V_2 , V_4 ) ;
return 0 ;
}
int F_115 ( struct V_11 * V_12 , const T_1 * V_7 )
{
struct V_3 * V_4 ;
int V_118 ;
F_61 ( & V_12 -> V_2 -> V_13 ) ;
V_4 = F_9 ( V_12 , V_7 ) ;
V_118 = F_99 ( V_4 ) ;
F_62 ( & V_12 -> V_2 -> V_13 ) ;
return V_118 ;
}
int F_116 ( struct V_11 * V_12 ,
const T_1 * V_7 )
{
struct V_3 * V_4 ;
int V_118 ;
F_61 ( & V_12 -> V_2 -> V_13 ) ;
V_4 = F_11 ( V_12 , V_7 ) ;
V_118 = F_99 ( V_4 ) ;
F_62 ( & V_12 -> V_2 -> V_13 ) ;
return V_118 ;
}
static void F_117 ( unsigned long V_126 )
{
struct V_1 * V_2 = (struct V_1 * ) V_126 ;
struct V_3 * V_4 ;
bool V_127 = false ;
F_70 () ;
F_13 (sta, &local->sta_list, list)
if ( F_98 ( V_2 , V_4 ) )
V_127 = true ;
F_80 () ;
if ( V_2 -> V_128 )
return;
if ( ! V_127 )
return;
F_118 ( & V_2 -> V_129 ,
F_119 ( V_44 + V_130 ) ) ;
}
void F_120 ( struct V_1 * V_2 )
{
F_36 ( & V_2 -> V_8 ) ;
F_38 ( & V_2 -> V_13 ) ;
F_121 ( & V_2 -> V_74 ) ;
F_121 ( & V_2 -> V_79 ) ;
F_37 ( & V_2 -> V_80 , F_60 ) ;
F_122 ( & V_2 -> V_129 , F_117 ,
( unsigned long ) V_2 ) ;
}
void F_123 ( struct V_1 * V_2 )
{
F_124 ( & V_2 -> V_129 ) ;
F_125 ( V_2 , NULL ) ;
}
int F_125 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_3 * V_4 , * V_131 ;
int V_118 = 0 ;
F_77 () ;
F_61 ( & V_2 -> V_13 ) ;
F_56 ( V_2 ) ;
F_126 (sta, tmp, &local->sta_list, list) {
if ( ! V_12 || V_12 == V_4 -> V_12 )
F_66 ( F_99 ( V_4 ) ) ;
}
F_62 ( & V_2 -> V_13 ) ;
return V_118 ;
}
void F_127 ( struct V_11 * V_12 ,
unsigned long V_132 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 , * V_131 ;
F_61 ( & V_2 -> V_13 ) ;
F_126 (sta, tmp, &local->sta_list, list)
if ( F_92 ( V_44 , V_4 -> V_43 + V_132 ) ) {
#ifdef F_128
F_48 ( V_68 L_12 ,
V_12 -> V_69 , V_4 -> V_4 . V_7 ) ;
#endif
F_66 ( F_99 ( V_4 ) ) ;
}
F_62 ( & V_2 -> V_13 ) ;
}
struct V_133 * F_129 ( struct V_134 * V_20 ,
const T_1 * V_7 ,
const T_1 * V_135 )
{
struct V_3 * V_4 , * V_136 ;
F_130 (hw_to_local(hw), addr, sta, nxt) {
if ( V_135 &&
F_67 ( V_4 -> V_12 -> V_64 . V_7 , V_135 ) != 0 )
continue;
if ( ! V_4 -> V_70 )
return NULL ;
return & V_4 -> V_4 ;
}
return NULL ;
}
struct V_133 * F_131 ( struct V_137 * V_64 ,
const T_1 * V_7 )
{
struct V_3 * V_4 ;
if ( ! V_64 )
return NULL ;
V_4 = F_10 ( F_132 ( V_64 ) , V_7 ) ;
if ( ! V_4 )
return NULL ;
if ( ! V_4 -> V_70 )
return NULL ;
return & V_4 -> V_4 ;
}
static void F_133 ( void * V_138 )
{
struct V_3 * V_4 = V_138 ;
F_26 ( V_4 , V_28 ) ;
F_26 ( V_4 , V_26 ) ;
}
void F_24 ( struct V_3 * V_4 )
{
struct V_11 * V_12 = V_4 -> V_12 ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_139 V_140 ;
int V_141 = 0 , V_142 = 0 , V_90 ;
F_26 ( V_4 , V_143 ) ;
F_134 ( F_135 ( V_48 ) > 1 ) ;
V_4 -> V_101 = 0 ;
if ( ! ( V_2 -> V_20 . V_31 & V_98 ) )
F_136 ( V_2 , V_12 , V_144 , & V_4 -> V_4 ) ;
F_41 ( & V_140 ) ;
for ( V_90 = 0 ; V_90 < V_50 ; V_90 ++ ) {
int V_145 = F_107 ( & V_140 ) , V_131 ;
F_137 ( & V_4 -> V_52 [ V_90 ] , & V_140 ) ;
V_131 = F_107 ( & V_140 ) ;
V_141 += V_131 - V_145 ;
V_145 = V_131 ;
F_137 ( & V_4 -> V_51 [ V_90 ] , & V_140 ) ;
V_131 = F_107 ( & V_140 ) ;
V_142 += V_131 - V_145 ;
}
F_138 ( V_2 , & V_140 , F_133 , V_4 ) ;
V_2 -> V_116 -= V_142 ;
F_86 ( V_4 ) ;
#ifdef F_97
F_48 ( V_68 L_13
L_14 , V_12 -> V_69 ,
V_4 -> V_4 . V_7 , V_4 -> V_4 . V_88 , V_141 , V_142 ) ;
#endif
}
static void F_139 ( struct V_11 * V_12 ,
struct V_3 * V_4 , int V_146 ,
enum V_147 V_148 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_149 * V_150 ;
struct V_105 * V_106 ;
int V_151 = sizeof( * V_150 ) ;
T_6 V_152 ;
bool V_153 = F_23 ( V_4 , V_154 ) ;
struct V_107 * V_108 ;
if ( V_153 ) {
V_152 = F_42 ( V_155 |
V_156 |
V_157 ) ;
} else {
V_151 -= 2 ;
V_152 = F_42 ( V_155 |
V_158 |
V_157 ) ;
}
V_106 = F_140 ( V_2 -> V_20 . V_159 + V_151 ) ;
if ( ! V_106 )
return;
F_141 ( V_106 , V_2 -> V_20 . V_159 ) ;
V_150 = ( void * ) F_142 ( V_106 , V_151 ) ;
V_150 -> V_160 = V_152 ;
V_150 -> V_161 = 0 ;
memcpy ( V_150 -> V_162 , V_4 -> V_4 . V_7 , V_15 ) ;
memcpy ( V_150 -> V_163 , V_12 -> V_64 . V_7 , V_15 ) ;
memcpy ( V_150 -> V_164 , V_12 -> V_64 . V_7 , V_15 ) ;
V_106 -> V_165 = V_146 ;
F_143 ( V_106 , V_166 [ V_146 ] ) ;
if ( V_153 ) {
V_150 -> V_167 = F_42 ( V_146 ) ;
if ( V_148 == V_168 )
V_150 -> V_167 |=
F_42 ( V_169 ) ;
}
V_108 = F_91 ( V_106 ) ;
V_108 -> V_31 |= V_170 |
V_171 |
V_172 ;
F_144 ( V_2 , V_4 , F_85 ( V_146 ) , 1 , V_148 , false ) ;
F_145 ( V_12 , V_106 ) ;
}
static void
F_146 ( struct V_3 * V_4 ,
int V_173 , T_1 V_174 ,
enum V_147 V_148 )
{
struct V_11 * V_12 = V_4 -> V_12 ;
struct V_1 * V_2 = V_12 -> V_2 ;
bool V_175 = false ;
bool V_176 = false ;
int V_90 ;
unsigned long V_177 = 0 ;
struct V_139 V_178 ;
F_100 ( V_4 , V_143 ) ;
F_147 ( & V_178 ) ;
for ( V_90 = 0 ; V_90 < V_50 ; V_90 ++ ) {
unsigned long V_100 ;
if ( V_174 & F_85 ( V_90 ) )
continue;
V_100 = F_84 ( V_90 ) ;
if ( ! V_175 ) {
V_177 = V_4 -> V_101 & V_100 ;
if ( V_177 ) {
V_175 = true ;
} else {
struct V_105 * V_106 ;
while ( V_173 > 0 ) {
V_106 = F_148 ( & V_4 -> V_52 [ V_90 ] ) ;
if ( ! V_106 ) {
V_106 = F_148 (
& V_4 -> V_51 [ V_90 ] ) ;
if ( V_106 )
V_2 -> V_116 -- ;
}
if ( ! V_106 )
break;
V_173 -- ;
V_175 = true ;
F_149 ( & V_178 , V_106 ) ;
}
}
if ( V_148 == V_179 &&
F_150 ( V_177 ) > 1 ) {
V_176 = true ;
V_177 =
F_85 ( F_151 ( V_177 ) - 1 ) ;
break;
}
}
if ( ! F_88 ( & V_4 -> V_52 [ V_90 ] ) ||
! F_88 ( & V_4 -> V_51 [ V_90 ] ) ) {
V_176 = true ;
break;
}
}
if ( ! V_175 ) {
int V_146 ;
V_146 = 7 - ( ( F_151 ( ~ V_174 ) - 1 ) << 1 ) ;
F_139 ( V_12 , V_4 , V_146 , V_148 ) ;
return;
}
if ( ! V_177 ) {
struct V_139 V_140 ;
struct V_105 * V_106 ;
int V_180 = 0 ;
T_4 V_100 = 0 ;
F_41 ( & V_140 ) ;
while ( ( V_106 = F_95 ( & V_178 ) ) ) {
struct V_107 * V_108 = F_91 ( V_106 ) ;
struct V_181 * V_182 = ( void * ) V_106 -> V_126 ;
T_1 * V_183 = NULL ;
V_180 ++ ;
V_108 -> V_31 |= V_170 ;
if ( V_176 || ! F_88 ( & V_178 ) )
V_182 -> V_160 |=
F_42 ( V_184 ) ;
else
V_182 -> V_160 &=
F_42 ( ~ V_184 ) ;
if ( F_152 ( V_182 -> V_160 ) ||
F_153 ( V_182 -> V_160 ) )
V_183 = F_154 ( V_182 ) ;
if ( V_148 == V_168 &&
V_183 && F_88 ( & V_178 ) )
* V_183 |= V_169 ;
V_108 -> V_31 |= V_171 |
V_172 ;
if ( V_183 )
V_100 |= F_85 ( * V_183 & V_185 ) ;
else
V_100 |= F_85 ( 0 ) ;
F_149 ( & V_140 , V_106 ) ;
}
F_144 ( V_2 , V_4 , V_100 , V_180 ,
V_148 , V_176 ) ;
F_155 ( V_2 , & V_140 ) ;
F_86 ( V_4 ) ;
} else {
F_156 ( V_2 , V_4 , V_177 ,
V_173 , V_148 , V_176 ) ;
}
}
void F_28 ( struct V_3 * V_4 )
{
T_1 V_186 = V_4 -> V_4 . V_97 ;
if ( V_186 == F_85 ( V_50 ) - 1 )
V_186 = 0 ;
F_146 ( V_4 , 1 , V_186 ,
V_179 ) ;
}
void F_30 ( struct V_3 * V_4 )
{
int V_173 = V_4 -> V_4 . V_187 ;
T_1 V_188 = V_4 -> V_4 . V_97 ;
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
F_146 ( V_4 , V_173 , ~ V_188 ,
V_168 ) ;
}
void F_157 ( struct V_134 * V_20 ,
struct V_133 * V_189 , bool V_190 )
{
struct V_3 * V_4 = F_22 ( V_189 , struct V_3 , V_4 ) ;
F_158 ( V_4 -> V_2 , V_189 , V_190 ) ;
if ( V_190 )
F_100 ( V_4 , V_28 ) ;
else if ( F_23 ( V_4 , V_28 ) )
F_72 ( V_20 , & V_4 -> V_24 ) ;
}
void F_159 ( struct V_133 * V_189 )
{
struct V_3 * V_4 = F_22 ( V_189 , struct V_3 , V_4 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_105 * V_106 ;
struct V_191 * V_126 ;
F_160 ( V_2 , V_189 ) ;
V_106 = F_161 ( 0 , V_192 ) ;
if ( ! V_106 ) {
F_26 ( V_4 , V_143 ) ;
return;
}
V_126 = ( void * ) V_106 -> V_193 ;
memcpy ( V_126 -> V_4 , V_189 -> V_7 , V_15 ) ;
memcpy ( V_126 -> V_194 , V_4 -> V_12 -> V_64 . V_7 , V_15 ) ;
V_106 -> V_195 = V_196 ;
F_162 ( & V_2 -> V_197 , V_106 ) ;
F_163 ( & V_2 -> V_198 ) ;
}
void F_164 ( struct V_133 * V_189 ,
T_1 V_146 , bool V_142 )
{
struct V_3 * V_4 = F_22 ( V_189 , struct V_3 , V_4 ) ;
if ( F_66 ( V_146 >= V_48 ) )
return;
if ( V_142 )
F_165 ( V_146 , & V_4 -> V_101 ) ;
else
F_166 ( V_146 , & V_4 -> V_101 ) ;
F_86 ( V_4 ) ;
}
