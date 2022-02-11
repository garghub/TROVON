static inline struct V_1 * F_1 ( struct V_2 * V_2 , T_1 V_3 )
{
struct V_1 * V_4 ;
F_2 (FL_HASH(label), fl) {
if ( V_4 -> V_3 == V_3 && F_3 ( V_4 -> V_5 , V_2 ) )
return V_4 ;
}
return NULL ;
}
static struct V_1 * F_4 ( struct V_2 * V_2 , T_1 V_3 )
{
struct V_1 * V_4 ;
F_5 () ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 && ! F_6 ( & V_4 -> V_6 ) )
V_4 = NULL ;
F_7 () ;
return V_4 ;
}
static void F_8 ( struct V_1 * V_4 )
{
if ( V_4 ) {
if ( V_4 -> V_7 == V_8 )
F_9 ( V_4 -> V_9 . V_10 ) ;
F_10 ( V_4 -> V_5 ) ;
F_11 ( V_4 -> V_11 ) ;
F_12 ( V_4 , V_12 ) ;
}
}
static void F_13 ( struct V_1 * V_4 )
{
F_14 ( & V_13 ) ;
V_4 -> V_14 = V_15 ;
if ( F_15 ( & V_4 -> V_6 ) ) {
unsigned long V_16 = V_4 -> V_14 + V_4 -> V_17 ;
if ( F_16 ( V_16 , V_4 -> V_18 ) )
V_4 -> V_18 = V_16 ;
V_16 = V_4 -> V_18 ;
if ( V_4 -> V_11 && V_4 -> V_7 == V_19 ) {
struct V_20 * V_11 = V_4 -> V_11 ;
V_4 -> V_11 = NULL ;
F_11 ( V_11 ) ;
}
if ( ! F_17 ( & V_21 ) ||
F_16 ( V_21 . V_18 , V_16 ) )
F_18 ( & V_21 , V_16 ) ;
}
F_19 ( & V_13 ) ;
}
static void F_20 ( unsigned long V_22 )
{
int V_23 ;
unsigned long V_24 = V_15 ;
unsigned long V_25 = 0 ;
F_21 ( & V_13 ) ;
for ( V_23 = 0 ; V_23 <= V_26 ; V_23 ++ ) {
struct V_1 * V_4 , * * V_27 ;
V_27 = & V_28 [ V_23 ] ;
while ( ( V_4 = F_22 ( * V_27 ,
F_23 ( & V_13 ) ) ) != NULL ) {
if ( F_24 ( & V_4 -> V_6 ) == 0 ) {
unsigned long V_16 = V_4 -> V_14 + V_4 -> V_17 ;
if ( F_16 ( V_16 , V_4 -> V_18 ) )
V_4 -> V_18 = V_16 ;
V_16 = V_4 -> V_18 ;
if ( F_25 ( V_24 , V_16 ) ) {
* V_27 = V_4 -> V_29 ;
F_8 ( V_4 ) ;
F_26 ( & V_30 ) ;
continue;
}
if ( ! V_25 || F_27 ( V_16 , V_25 ) )
V_25 = V_16 ;
}
V_27 = & V_4 -> V_29 ;
}
}
if ( ! V_25 && F_24 ( & V_30 ) )
V_25 = V_24 + V_31 ;
if ( V_25 ) {
F_18 ( & V_21 , V_25 ) ;
}
F_28 ( & V_13 ) ;
}
static void T_2 F_29 ( struct V_2 * V_2 )
{
int V_23 ;
F_21 ( & V_13 ) ;
for ( V_23 = 0 ; V_23 <= V_26 ; V_23 ++ ) {
struct V_1 * V_4 , * * V_27 ;
V_27 = & V_28 [ V_23 ] ;
while ( ( V_4 = F_22 ( * V_27 ,
F_23 ( & V_13 ) ) ) != NULL ) {
if ( F_3 ( V_4 -> V_5 , V_2 ) &&
F_24 ( & V_4 -> V_6 ) == 0 ) {
* V_27 = V_4 -> V_29 ;
F_8 ( V_4 ) ;
F_26 ( & V_30 ) ;
continue;
}
V_27 = & V_4 -> V_29 ;
}
}
F_28 ( & V_13 ) ;
}
static struct V_1 * F_30 ( struct V_2 * V_2 ,
struct V_1 * V_4 , T_1 V_3 )
{
struct V_1 * V_32 ;
V_4 -> V_3 = V_3 & V_33 ;
F_14 ( & V_13 ) ;
if ( V_3 == 0 ) {
for (; ; ) {
V_4 -> V_3 = F_31 ( F_32 () ) & V_33 ;
if ( V_4 -> V_3 ) {
V_32 = F_1 ( V_2 , V_4 -> V_3 ) ;
if ( V_32 == NULL )
break;
}
}
} else {
V_32 = F_1 ( V_2 , V_4 -> V_3 ) ;
if ( V_32 != NULL ) {
F_33 ( & V_32 -> V_6 ) ;
F_19 ( & V_13 ) ;
return V_32 ;
}
}
V_4 -> V_14 = V_15 ;
V_4 -> V_29 = V_28 [ F_34 ( V_4 -> V_3 ) ] ;
F_35 ( V_28 [ F_34 ( V_4 -> V_3 ) ] , V_4 ) ;
F_33 ( & V_30 ) ;
F_19 ( & V_13 ) ;
return NULL ;
}
struct V_1 * F_36 ( struct V_34 * V_35 , T_1 V_3 )
{
struct V_36 * V_37 ;
struct V_38 * V_39 = F_37 ( V_35 ) ;
V_3 &= V_33 ;
F_5 () ;
F_38 (np, sfl) {
struct V_1 * V_4 = V_37 -> V_4 ;
if ( V_4 -> V_3 == V_3 ) {
V_4 -> V_14 = V_15 ;
F_33 ( & V_4 -> V_6 ) ;
F_7 () ;
return V_4 ;
}
}
F_7 () ;
return NULL ;
}
void F_39 ( struct V_34 * V_35 )
{
struct V_38 * V_39 = F_37 ( V_35 ) ;
struct V_36 * V_37 ;
if ( ! F_40 ( V_39 -> V_40 ) )
return;
F_14 ( & V_41 ) ;
while ( ( V_37 = F_22 ( V_39 -> V_40 ,
F_23 ( & V_41 ) ) ) != NULL ) {
V_39 -> V_40 = V_37 -> V_29 ;
F_19 ( & V_41 ) ;
F_13 ( V_37 -> V_4 ) ;
F_12 ( V_37 , V_12 ) ;
F_14 ( & V_41 ) ;
}
F_19 ( & V_41 ) ;
}
struct V_20 * F_41 ( struct V_20 * V_42 ,
struct V_1 * V_4 ,
struct V_20 * V_43 )
{
struct V_20 * V_44 = V_4 -> V_11 ;
if ( V_43 == NULL || V_43 -> V_45 == 0 )
return V_44 ;
if ( V_44 != NULL ) {
V_42 -> V_46 = V_44 -> V_46 ;
V_42 -> V_47 = V_44 -> V_47 ;
V_42 -> V_48 = V_44 -> V_48 ;
V_42 -> V_49 = V_44 -> V_49 ;
} else {
if ( V_43 -> V_49 == 0 )
return V_43 ;
V_42 -> V_46 = NULL ;
V_42 -> V_47 = NULL ;
V_42 -> V_48 = NULL ;
V_42 -> V_49 = 0 ;
}
V_42 -> V_50 = V_43 -> V_50 ;
V_42 -> V_45 = V_43 -> V_45 ;
return V_42 ;
}
static unsigned long F_42 ( unsigned long V_51 )
{
if ( V_51 < V_52 )
return V_52 * V_53 ;
if ( V_51 > V_31 && ! F_43 ( V_54 ) )
return 0 ;
return V_51 * V_53 ;
}
static int F_44 ( struct V_1 * V_4 , unsigned long V_17 , unsigned long V_18 )
{
V_17 = F_42 ( V_17 ) ;
if ( ! V_17 )
return - V_55 ;
V_18 = F_42 ( V_18 ) ;
if ( ! V_18 )
return - V_55 ;
V_4 -> V_14 = V_15 ;
if ( F_27 ( V_4 -> V_17 , V_17 ) )
V_4 -> V_17 = V_17 ;
if ( F_27 ( V_18 , V_4 -> V_17 ) )
V_18 = V_4 -> V_17 ;
if ( F_27 ( V_4 -> V_18 , V_4 -> V_14 + V_18 ) )
V_4 -> V_18 = V_4 -> V_14 + V_18 ;
return 0 ;
}
static struct V_1 *
F_45 ( struct V_2 * V_2 , struct V_34 * V_35 , struct V_56 * V_57 ,
char T_3 * V_58 , int V_59 , int * V_60 )
{
struct V_1 * V_4 = NULL ;
int V_61 ;
int V_62 ;
int V_63 ;
V_61 = V_59 - F_46 ( sizeof( * V_57 ) ) ;
V_63 = - V_64 ;
if ( V_61 > 64 * 1024 )
goto V_65;
V_63 = - V_66 ;
V_4 = F_47 ( sizeof( * V_4 ) , V_67 ) ;
if ( V_4 == NULL )
goto V_65;
if ( V_61 > 0 ) {
struct V_68 V_69 ;
struct V_70 V_70 ;
int V_71 ;
V_63 = - V_66 ;
V_4 -> V_11 = F_48 ( sizeof( * V_4 -> V_11 ) + V_61 , V_67 ) ;
if ( V_4 -> V_11 == NULL )
goto V_65;
memset ( V_4 -> V_11 , 0 , sizeof( * V_4 -> V_11 ) ) ;
V_4 -> V_11 -> V_72 = sizeof( * V_4 -> V_11 ) + V_61 ;
V_63 = - V_73 ;
if ( F_49 ( V_4 -> V_11 + 1 , V_58 + F_46 ( sizeof( * V_57 ) ) , V_61 ) )
goto V_65;
V_69 . V_74 = V_61 ;
V_69 . V_75 = ( void * ) ( V_4 -> V_11 + 1 ) ;
memset ( & V_70 , 0 , sizeof( V_70 ) ) ;
V_63 = F_50 ( V_2 , V_35 , & V_69 , & V_70 , V_4 -> V_11 ,
& V_71 , & V_71 , & V_71 ) ;
if ( V_63 )
goto V_65;
V_63 = - V_64 ;
if ( V_4 -> V_11 -> V_45 )
goto V_65;
if ( V_4 -> V_11 -> V_49 == 0 ) {
F_11 ( V_4 -> V_11 ) ;
V_4 -> V_11 = NULL ;
}
}
V_4 -> V_5 = F_51 ( V_2 ) ;
V_4 -> V_18 = V_15 ;
V_63 = F_44 ( V_4 , V_57 -> V_76 , V_57 -> V_77 ) ;
if ( V_63 )
goto V_65;
V_4 -> V_7 = V_57 -> V_78 ;
V_62 = F_52 ( & V_57 -> V_79 ) ;
if ( ( V_62 & V_80 ) ||
V_62 == V_81 ) {
V_63 = - V_64 ;
goto V_65;
}
V_4 -> V_82 = V_57 -> V_79 ;
F_53 ( & V_4 -> V_6 , 1 ) ;
switch ( V_4 -> V_7 ) {
case V_19 :
case V_83 :
break;
case V_8 :
V_4 -> V_9 . V_10 = F_54 ( V_84 , V_85 ) ;
break;
case V_86 :
V_4 -> V_9 . V_87 = F_55 () ;
break;
default:
V_63 = - V_64 ;
goto V_65;
}
return V_4 ;
V_65:
F_8 ( V_4 ) ;
* V_60 = V_63 ;
return NULL ;
}
static int F_56 ( struct V_34 * V_35 )
{
struct V_38 * V_39 = F_37 ( V_35 ) ;
struct V_36 * V_37 ;
int V_88 = V_89 - F_24 ( & V_30 ) ;
int V_90 = 0 ;
if ( V_88 > V_89 - V_91 )
return 0 ;
F_38 (np, sfl)
V_90 ++ ;
if ( V_88 <= 0 ||
( ( V_90 >= V_91 ||
( V_90 > 0 && V_88 < V_89 / 2 ) || V_88 < V_89 / 4 ) &&
! F_43 ( V_54 ) ) )
return - V_92 ;
return 0 ;
}
static bool F_57 ( struct V_93 * V_94 , struct V_93 * V_95 )
{
if ( V_94 == V_95 )
return false ;
if ( V_94 == NULL || V_95 == NULL )
return true ;
if ( V_94 -> V_96 != V_95 -> V_96 )
return true ;
return memcmp ( V_94 + 1 , V_95 + 1 , ( ( V_94 -> V_96 + 1 ) << 3 ) - sizeof( * V_94 ) ) ;
}
static bool F_58 ( struct V_20 * V_97 , struct V_20 * V_98 )
{
if ( V_97 == V_98 )
return false ;
if ( V_97 == NULL || V_98 == NULL )
return true ;
if ( V_97 -> V_49 != V_98 -> V_49 )
return true ;
if ( F_57 ( V_97 -> V_46 , V_98 -> V_46 ) )
return true ;
if ( F_57 ( V_97 -> V_47 , V_98 -> V_47 ) )
return true ;
if ( F_57 ( (struct V_93 * ) V_97 -> V_48 , (struct V_93 * ) V_98 -> V_48 ) )
return true ;
return false ;
}
static inline void F_59 ( struct V_38 * V_39 , struct V_36 * V_37 ,
struct V_1 * V_4 )
{
F_14 ( & V_41 ) ;
V_37 -> V_4 = V_4 ;
V_37 -> V_29 = V_39 -> V_40 ;
F_35 ( V_39 -> V_40 , V_37 ) ;
F_19 ( & V_41 ) ;
}
int F_60 ( struct V_34 * V_35 , char T_3 * V_58 , int V_59 )
{
int V_99 ( V_63 ) ;
struct V_2 * V_2 = F_61 ( V_35 ) ;
struct V_38 * V_39 = F_37 ( V_35 ) ;
struct V_56 V_57 ;
struct V_36 * V_100 = NULL ;
struct V_36 * V_37 , * * V_101 ;
struct V_1 * V_4 , * V_102 = NULL ;
if ( V_59 < sizeof( V_57 ) )
return - V_64 ;
if ( F_49 ( & V_57 , V_58 , sizeof( V_57 ) ) )
return - V_73 ;
switch ( V_57 . V_103 ) {
case V_104 :
F_14 ( & V_41 ) ;
for ( V_101 = & V_39 -> V_40 ;
( V_37 = F_62 ( * V_101 ) ) != NULL ;
V_101 = & V_37 -> V_29 ) {
if ( V_37 -> V_4 -> V_3 == V_57 . V_105 ) {
if ( V_57 . V_105 == ( V_39 -> V_106 & V_33 ) )
V_39 -> V_106 &= ~ V_33 ;
* V_101 = F_62 ( V_37 -> V_29 ) ;
F_19 ( & V_41 ) ;
F_13 ( V_37 -> V_4 ) ;
F_12 ( V_37 , V_12 ) ;
return 0 ;
}
}
F_19 ( & V_41 ) ;
return - V_107 ;
case V_108 :
F_5 () ;
F_38 (np, sfl) {
if ( V_37 -> V_4 -> V_3 == V_57 . V_105 ) {
V_63 = F_44 ( V_37 -> V_4 , V_57 . V_76 , V_57 . V_77 ) ;
F_7 () ;
return V_63 ;
}
}
F_7 () ;
if ( V_57 . V_78 == V_109 &&
F_63 ( V_2 -> V_110 , V_54 ) ) {
V_4 = F_4 ( V_2 , V_57 . V_105 ) ;
if ( V_4 ) {
V_63 = F_44 ( V_4 , V_57 . V_76 , V_57 . V_77 ) ;
F_13 ( V_4 ) ;
return V_63 ;
}
}
return - V_107 ;
case V_111 :
if ( V_57 . V_105 & ~ V_33 )
return - V_64 ;
V_4 = F_45 ( V_2 , V_35 , & V_57 , V_58 , V_59 , & V_63 ) ;
if ( V_4 == NULL )
return V_63 ;
V_100 = F_48 ( sizeof( * V_100 ) , V_67 ) ;
if ( V_57 . V_105 ) {
V_63 = - V_112 ;
F_5 () ;
F_38 (np, sfl) {
if ( V_37 -> V_4 -> V_3 == V_57 . V_105 ) {
if ( V_57 . V_113 & V_114 ) {
F_7 () ;
goto V_65;
}
V_102 = V_37 -> V_4 ;
F_33 ( & V_102 -> V_6 ) ;
break;
}
}
F_7 () ;
if ( V_102 == NULL )
V_102 = F_4 ( V_2 , V_57 . V_105 ) ;
if ( V_102 ) {
V_115:
V_63 = - V_112 ;
if ( V_57 . V_113 & V_114 )
goto V_116;
V_63 = - V_55 ;
if ( V_102 -> V_7 == V_19 ||
V_102 -> V_7 != V_4 -> V_7 ||
( ( V_102 -> V_7 == V_8 ) &&
( V_102 -> V_9 . V_10 == V_4 -> V_9 . V_10 ) ) ||
( ( V_102 -> V_7 == V_86 ) &&
F_64 ( V_102 -> V_9 . V_87 , V_4 -> V_9 . V_87 ) ) )
goto V_116;
V_63 = - V_64 ;
if ( ! F_65 ( & V_102 -> V_82 , & V_4 -> V_82 ) ||
F_58 ( V_102 -> V_11 , V_4 -> V_11 ) )
goto V_116;
V_63 = - V_66 ;
if ( V_100 == NULL )
goto V_116;
if ( V_4 -> V_17 > V_102 -> V_17 )
V_102 -> V_17 = V_4 -> V_17 ;
if ( ( long ) ( V_4 -> V_18 - V_102 -> V_18 ) > 0 )
V_102 -> V_18 = V_4 -> V_18 ;
F_59 ( V_39 , V_100 , V_102 ) ;
F_8 ( V_4 ) ;
return 0 ;
V_116:
F_13 ( V_102 ) ;
goto V_65;
}
}
V_63 = - V_117 ;
if ( ! ( V_57 . V_113 & V_118 ) )
goto V_65;
V_63 = - V_66 ;
if ( V_100 == NULL || ( V_63 = F_56 ( V_35 ) ) != 0 )
goto V_65;
V_102 = F_30 ( V_2 , V_4 , V_57 . V_105 ) ;
if ( V_102 != NULL )
goto V_115;
if ( ! V_57 . V_105 ) {
if ( F_66 ( & ( (struct V_56 T_3 * ) V_58 ) -> V_105 ,
& V_4 -> V_3 , sizeof( V_4 -> V_3 ) ) ) {
}
}
F_59 ( V_39 , V_100 , V_4 ) ;
return 0 ;
default:
return - V_64 ;
}
V_65:
F_8 ( V_4 ) ;
F_11 ( V_100 ) ;
return V_63 ;
}
static struct V_1 * F_67 ( struct V_119 * V_120 )
{
struct V_1 * V_4 = NULL ;
struct V_121 * V_122 = F_68 ( V_120 ) ;
struct V_2 * V_2 = F_69 ( V_120 ) ;
for ( V_122 -> V_123 = 0 ; V_122 -> V_123 <= V_26 ; ++ V_122 -> V_123 ) {
F_2 (state->bucket, fl) {
if ( F_3 ( V_4 -> V_5 , V_2 ) )
goto V_124;
}
}
V_4 = NULL ;
V_124:
return V_4 ;
}
static struct V_1 * F_70 ( struct V_119 * V_120 , struct V_1 * V_4 )
{
struct V_121 * V_122 = F_68 ( V_120 ) ;
struct V_2 * V_2 = F_69 ( V_120 ) ;
F_71 (fl) {
if ( F_3 ( V_4 -> V_5 , V_2 ) )
goto V_124;
}
V_125:
if ( ++ V_122 -> V_123 <= V_26 ) {
F_2 (state->bucket, fl) {
if ( F_3 ( V_4 -> V_5 , V_2 ) )
goto V_124;
}
goto V_125;
}
V_4 = NULL ;
V_124:
return V_4 ;
}
static struct V_1 * F_72 ( struct V_119 * V_120 , T_4 V_126 )
{
struct V_1 * V_4 = F_67 ( V_120 ) ;
if ( V_4 )
while ( V_126 && ( V_4 = F_70 ( V_120 , V_4 ) ) != NULL )
-- V_126 ;
return V_126 ? NULL : V_4 ;
}
static void * F_73 ( struct V_119 * V_120 , T_4 * V_126 )
__acquires( T_5 )
{
F_5 () ;
return * V_126 ? F_72 ( V_120 , * V_126 - 1 ) : V_127 ;
}
static void * F_74 ( struct V_119 * V_120 , void * V_128 , T_4 * V_126 )
{
struct V_1 * V_4 ;
if ( V_128 == V_127 )
V_4 = F_67 ( V_120 ) ;
else
V_4 = F_70 ( V_120 , V_128 ) ;
++ * V_126 ;
return V_4 ;
}
static void F_75 ( struct V_119 * V_120 , void * V_128 )
__releases( T_5 )
{
F_7 () ;
}
static int F_76 ( struct V_119 * V_120 , void * V_128 )
{
struct V_121 * V_122 = F_68 ( V_120 ) ;
if ( V_128 == V_127 )
F_77 ( V_120 , L_1 ,
L_2 , L_3 , L_4 , L_5 , L_6 , L_7 , L_8 , L_9 ) ;
else {
struct V_1 * V_4 = V_128 ;
F_77 ( V_120 ,
L_10 ,
( unsigned int ) F_78 ( V_4 -> V_3 ) ,
V_4 -> V_7 ,
( ( V_4 -> V_7 == V_8 ) ?
F_79 ( V_4 -> V_9 . V_10 , V_122 -> V_129 ) :
( ( V_4 -> V_7 == V_86 ) ?
F_80 ( F_81 ( V_120 ) , V_4 -> V_9 . V_87 ) :
0 ) ) ,
F_24 ( & V_4 -> V_6 ) ,
V_4 -> V_17 / V_53 ,
( long ) ( V_4 -> V_18 - V_15 ) / V_53 ,
& V_4 -> V_82 ,
V_4 -> V_11 ? V_4 -> V_11 -> V_49 : 0 ) ;
}
return 0 ;
}
static int F_82 ( struct V_130 * V_130 , struct V_131 * V_131 )
{
struct V_119 * V_120 ;
struct V_121 * V_122 ;
int V_63 ;
V_63 = F_83 ( V_130 , V_131 , & V_132 ,
sizeof( struct V_121 ) ) ;
if ( ! V_63 ) {
V_120 = V_131 -> V_133 ;
V_122 = F_68 ( V_120 ) ;
F_84 () ;
V_122 -> V_129 = F_85 ( F_86 ( V_84 ) ) ;
F_87 () ;
}
return V_63 ;
}
static int F_88 ( struct V_130 * V_130 , struct V_131 * V_131 )
{
struct V_119 * V_120 = V_131 -> V_133 ;
struct V_121 * V_122 = F_68 ( V_120 ) ;
F_89 ( V_122 -> V_129 ) ;
return F_90 ( V_130 , V_131 ) ;
}
static int T_6 F_91 ( struct V_2 * V_2 )
{
if ( ! F_92 ( L_11 , V_134 , V_2 -> V_135 ,
& V_136 ) )
return - V_66 ;
return 0 ;
}
static void T_2 F_93 ( struct V_2 * V_2 )
{
F_94 ( L_11 , V_2 -> V_135 ) ;
}
static inline int F_91 ( struct V_2 * V_2 )
{
return 0 ;
}
static inline void F_93 ( struct V_2 * V_2 )
{
}
static void T_2 F_95 ( struct V_2 * V_2 )
{
F_29 ( V_2 ) ;
F_93 ( V_2 ) ;
}
int F_96 ( void )
{
return F_97 ( & V_137 ) ;
}
void F_98 ( void )
{
F_99 ( & V_21 ) ;
F_100 ( & V_137 ) ;
}
