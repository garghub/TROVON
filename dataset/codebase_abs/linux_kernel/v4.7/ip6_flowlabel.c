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
F_10 ( V_4 -> V_11 ) ;
F_11 ( V_4 , V_12 ) ;
}
}
static void F_12 ( struct V_1 * V_4 )
{
F_13 ( & V_13 ) ;
V_4 -> V_14 = V_15 ;
if ( F_14 ( & V_4 -> V_6 ) ) {
unsigned long V_16 = V_4 -> V_14 + V_4 -> V_17 ;
if ( F_15 ( V_16 , V_4 -> V_18 ) )
V_4 -> V_18 = V_16 ;
V_16 = V_4 -> V_18 ;
if ( V_4 -> V_11 && V_4 -> V_7 == V_19 ) {
struct V_20 * V_11 = V_4 -> V_11 ;
V_4 -> V_11 = NULL ;
F_10 ( V_11 ) ;
}
if ( ! F_16 ( & V_21 ) ||
F_15 ( V_21 . V_18 , V_16 ) )
F_17 ( & V_21 , V_16 ) ;
}
F_18 ( & V_13 ) ;
}
static void F_19 ( unsigned long V_22 )
{
int V_23 ;
unsigned long V_24 = V_15 ;
unsigned long V_25 = 0 ;
F_20 ( & V_13 ) ;
for ( V_23 = 0 ; V_23 <= V_26 ; V_23 ++ ) {
struct V_1 * V_4 ;
struct V_1 T_2 * * V_27 ;
V_27 = & V_28 [ V_23 ] ;
while ( ( V_4 = F_21 ( * V_27 ,
F_22 ( & V_13 ) ) ) != NULL ) {
if ( F_23 ( & V_4 -> V_6 ) == 0 ) {
unsigned long V_16 = V_4 -> V_14 + V_4 -> V_17 ;
if ( F_15 ( V_16 , V_4 -> V_18 ) )
V_4 -> V_18 = V_16 ;
V_16 = V_4 -> V_18 ;
if ( F_24 ( V_24 , V_16 ) ) {
* V_27 = V_4 -> V_29 ;
F_8 ( V_4 ) ;
F_25 ( & V_30 ) ;
continue;
}
if ( ! V_25 || F_26 ( V_16 , V_25 ) )
V_25 = V_16 ;
}
V_27 = & V_4 -> V_29 ;
}
}
if ( ! V_25 && F_23 ( & V_30 ) )
V_25 = V_24 + V_31 ;
if ( V_25 ) {
F_17 ( & V_21 , V_25 ) ;
}
F_27 ( & V_13 ) ;
}
static void T_3 F_28 ( struct V_2 * V_2 )
{
int V_23 ;
F_13 ( & V_13 ) ;
for ( V_23 = 0 ; V_23 <= V_26 ; V_23 ++ ) {
struct V_1 * V_4 ;
struct V_1 T_2 * * V_27 ;
V_27 = & V_28 [ V_23 ] ;
while ( ( V_4 = F_21 ( * V_27 ,
F_22 ( & V_13 ) ) ) != NULL ) {
if ( F_3 ( V_4 -> V_5 , V_2 ) &&
F_23 ( & V_4 -> V_6 ) == 0 ) {
* V_27 = V_4 -> V_29 ;
F_8 ( V_4 ) ;
F_25 ( & V_30 ) ;
continue;
}
V_27 = & V_4 -> V_29 ;
}
}
F_18 ( & V_13 ) ;
}
static struct V_1 * F_29 ( struct V_2 * V_2 ,
struct V_1 * V_4 , T_1 V_3 )
{
struct V_1 * V_32 ;
V_4 -> V_3 = V_3 & V_33 ;
F_13 ( & V_13 ) ;
if ( V_3 == 0 ) {
for (; ; ) {
V_4 -> V_3 = F_30 ( F_31 () ) & V_33 ;
if ( V_4 -> V_3 ) {
V_32 = F_1 ( V_2 , V_4 -> V_3 ) ;
if ( ! V_32 )
break;
}
}
} else {
V_32 = F_1 ( V_2 , V_4 -> V_3 ) ;
if ( V_32 ) {
F_32 ( & V_32 -> V_6 ) ;
F_18 ( & V_13 ) ;
return V_32 ;
}
}
V_4 -> V_14 = V_15 ;
V_4 -> V_29 = V_28 [ F_33 ( V_4 -> V_3 ) ] ;
F_34 ( V_28 [ F_33 ( V_4 -> V_3 ) ] , V_4 ) ;
F_32 ( & V_30 ) ;
F_18 ( & V_13 ) ;
return NULL ;
}
struct V_1 * F_35 ( struct V_34 * V_35 , T_1 V_3 )
{
struct V_36 * V_37 ;
struct V_38 * V_39 = F_36 ( V_35 ) ;
V_3 &= V_33 ;
F_5 () ;
F_37 (np, sfl) {
struct V_1 * V_4 = V_37 -> V_4 ;
if ( V_4 -> V_3 == V_3 ) {
V_4 -> V_14 = V_15 ;
F_32 ( & V_4 -> V_6 ) ;
F_7 () ;
return V_4 ;
}
}
F_7 () ;
return NULL ;
}
void F_38 ( struct V_34 * V_35 )
{
struct V_38 * V_39 = F_36 ( V_35 ) ;
struct V_36 * V_37 ;
if ( ! F_39 ( V_39 -> V_40 ) )
return;
F_13 ( & V_41 ) ;
while ( ( V_37 = F_21 ( V_39 -> V_40 ,
F_22 ( & V_41 ) ) ) != NULL ) {
V_39 -> V_40 = V_37 -> V_29 ;
F_18 ( & V_41 ) ;
F_12 ( V_37 -> V_4 ) ;
F_11 ( V_37 , V_12 ) ;
F_13 ( & V_41 ) ;
}
F_18 ( & V_41 ) ;
}
struct V_20 * F_40 ( struct V_20 * V_42 ,
struct V_1 * V_4 ,
struct V_20 * V_43 )
{
struct V_20 * V_44 = V_4 -> V_11 ;
if ( ! V_43 || V_43 -> V_45 == 0 )
return V_44 ;
if ( V_44 ) {
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
static unsigned long F_41 ( unsigned long V_51 )
{
if ( V_51 < V_52 )
return V_52 * V_53 ;
if ( V_51 > V_31 && ! F_42 ( V_54 ) )
return 0 ;
return V_51 * V_53 ;
}
static int F_43 ( struct V_1 * V_4 , unsigned long V_17 , unsigned long V_18 )
{
V_17 = F_41 ( V_17 ) ;
if ( ! V_17 )
return - V_55 ;
V_18 = F_41 ( V_18 ) ;
if ( ! V_18 )
return - V_55 ;
F_13 ( & V_13 ) ;
V_4 -> V_14 = V_15 ;
if ( F_26 ( V_4 -> V_17 , V_17 ) )
V_4 -> V_17 = V_17 ;
if ( F_26 ( V_18 , V_4 -> V_17 ) )
V_18 = V_4 -> V_17 ;
if ( F_26 ( V_4 -> V_18 , V_4 -> V_14 + V_18 ) )
V_4 -> V_18 = V_4 -> V_14 + V_18 ;
F_18 ( & V_13 ) ;
return 0 ;
}
static struct V_1 *
F_44 ( struct V_2 * V_2 , struct V_34 * V_35 , struct V_56 * V_57 ,
char T_4 * V_58 , int V_59 , int * V_60 )
{
struct V_1 * V_4 = NULL ;
int V_61 ;
int V_62 ;
int V_63 ;
V_61 = V_59 - F_45 ( sizeof( * V_57 ) ) ;
V_63 = - V_64 ;
if ( V_61 > 64 * 1024 )
goto V_65;
V_63 = - V_66 ;
V_4 = F_46 ( sizeof( * V_4 ) , V_67 ) ;
if ( ! V_4 )
goto V_65;
if ( V_61 > 0 ) {
struct V_68 V_69 ;
struct V_70 V_70 ;
struct V_71 V_72 ;
struct V_73 V_74 ;
V_63 = - V_66 ;
V_4 -> V_11 = F_47 ( sizeof( * V_4 -> V_11 ) + V_61 , V_67 ) ;
if ( ! V_4 -> V_11 )
goto V_65;
memset ( V_4 -> V_11 , 0 , sizeof( * V_4 -> V_11 ) ) ;
V_4 -> V_11 -> V_75 = sizeof( * V_4 -> V_11 ) + V_61 ;
V_63 = - V_76 ;
if ( F_48 ( V_4 -> V_11 + 1 , V_58 + F_45 ( sizeof( * V_57 ) ) , V_61 ) )
goto V_65;
V_69 . V_77 = V_61 ;
V_69 . V_78 = ( void * ) ( V_4 -> V_11 + 1 ) ;
memset ( & V_70 , 0 , sizeof( V_70 ) ) ;
V_74 . V_11 = V_4 -> V_11 ;
V_63 = F_49 ( V_2 , V_35 , & V_69 , & V_70 , & V_74 , & V_72 ) ;
if ( V_63 )
goto V_65;
V_63 = - V_64 ;
if ( V_4 -> V_11 -> V_45 )
goto V_65;
if ( V_4 -> V_11 -> V_49 == 0 ) {
F_10 ( V_4 -> V_11 ) ;
V_4 -> V_11 = NULL ;
}
}
V_4 -> V_5 = V_2 ;
V_4 -> V_18 = V_15 ;
V_63 = F_43 ( V_4 , V_57 -> V_79 , V_57 -> V_80 ) ;
if ( V_63 )
goto V_65;
V_4 -> V_7 = V_57 -> V_81 ;
V_62 = F_50 ( & V_57 -> V_82 ) ;
if ( ( V_62 & V_83 ) ||
V_62 == V_84 ) {
V_63 = - V_64 ;
goto V_65;
}
V_4 -> V_85 = V_57 -> V_82 ;
F_51 ( & V_4 -> V_6 , 1 ) ;
switch ( V_4 -> V_7 ) {
case V_19 :
case V_86 :
break;
case V_8 :
V_4 -> V_9 . V_10 = F_52 ( V_87 , V_88 ) ;
break;
case V_89 :
V_4 -> V_9 . V_90 = F_53 () ;
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
static int F_54 ( struct V_34 * V_35 )
{
struct V_38 * V_39 = F_36 ( V_35 ) ;
struct V_36 * V_37 ;
int V_91 = V_92 - F_23 ( & V_30 ) ;
int V_93 = 0 ;
if ( V_91 > V_92 - V_94 )
return 0 ;
F_5 () ;
F_37 (np, sfl)
V_93 ++ ;
F_7 () ;
if ( V_91 <= 0 ||
( ( V_93 >= V_94 ||
( V_93 > 0 && V_91 < V_92 / 2 ) || V_91 < V_92 / 4 ) &&
! F_42 ( V_54 ) ) )
return - V_95 ;
return 0 ;
}
static inline void F_55 ( struct V_38 * V_39 , struct V_36 * V_37 ,
struct V_1 * V_4 )
{
F_13 ( & V_41 ) ;
V_37 -> V_4 = V_4 ;
V_37 -> V_29 = V_39 -> V_40 ;
F_34 ( V_39 -> V_40 , V_37 ) ;
F_18 ( & V_41 ) ;
}
int F_56 ( struct V_34 * V_35 , struct V_56 * V_57 ,
int V_96 )
{
struct V_38 * V_39 = F_36 ( V_35 ) ;
struct V_36 * V_37 ;
if ( V_96 & V_97 ) {
V_57 -> V_98 = V_39 -> V_99 & V_33 ;
return 0 ;
}
if ( V_39 -> V_100 ) {
V_57 -> V_98 = V_39 -> V_101 ;
return 0 ;
}
F_5 () ;
F_37 (np, sfl) {
if ( V_37 -> V_4 -> V_3 == ( V_39 -> V_101 & V_33 ) ) {
F_13 ( & V_13 ) ;
V_57 -> V_98 = V_37 -> V_4 -> V_3 ;
V_57 -> V_82 = V_37 -> V_4 -> V_85 ;
V_57 -> V_81 = V_37 -> V_4 -> V_7 ;
V_57 -> V_80 = ( V_37 -> V_4 -> V_18 - V_15 ) / V_53 ;
V_57 -> V_79 = V_37 -> V_4 -> V_17 / V_53 ;
F_18 ( & V_13 ) ;
F_7 () ;
return 0 ;
}
}
F_7 () ;
return - V_102 ;
}
int F_57 ( struct V_34 * V_35 , char T_4 * V_58 , int V_59 )
{
int V_103 ( V_63 ) ;
struct V_2 * V_2 = F_58 ( V_35 ) ;
struct V_38 * V_39 = F_36 ( V_35 ) ;
struct V_56 V_57 ;
struct V_36 * V_104 = NULL ;
struct V_36 * V_37 ;
struct V_36 T_2 * * V_105 ;
struct V_1 * V_4 , * V_106 = NULL ;
if ( V_59 < sizeof( V_57 ) )
return - V_64 ;
if ( F_48 ( & V_57 , V_58 , sizeof( V_57 ) ) )
return - V_76 ;
switch ( V_57 . V_107 ) {
case V_108 :
if ( V_57 . V_109 & V_110 ) {
if ( V_35 -> V_111 != V_112 )
return - V_113 ;
if ( ! V_39 -> V_100 )
return - V_114 ;
V_39 -> V_101 = 0 ;
V_39 -> V_100 = 0 ;
return 0 ;
}
F_13 ( & V_41 ) ;
for ( V_105 = & V_39 -> V_40 ;
( V_37 = F_21 ( * V_105 ,
F_22 ( & V_41 ) ) ) != NULL ;
V_105 = & V_37 -> V_29 ) {
if ( V_37 -> V_4 -> V_3 == V_57 . V_98 ) {
if ( V_57 . V_98 == ( V_39 -> V_101 & V_33 ) )
V_39 -> V_101 &= ~ V_33 ;
* V_105 = V_37 -> V_29 ;
F_18 ( & V_41 ) ;
F_12 ( V_37 -> V_4 ) ;
F_11 ( V_37 , V_12 ) ;
return 0 ;
}
}
F_18 ( & V_41 ) ;
return - V_114 ;
case V_115 :
F_5 () ;
F_37 (np, sfl) {
if ( V_37 -> V_4 -> V_3 == V_57 . V_98 ) {
V_63 = F_43 ( V_37 -> V_4 , V_57 . V_79 , V_57 . V_80 ) ;
F_7 () ;
return V_63 ;
}
}
F_7 () ;
if ( V_57 . V_81 == V_116 &&
F_59 ( V_2 -> V_117 , V_54 ) ) {
V_4 = F_4 ( V_2 , V_57 . V_98 ) ;
if ( V_4 ) {
V_63 = F_43 ( V_4 , V_57 . V_79 , V_57 . V_80 ) ;
F_12 ( V_4 ) ;
return V_63 ;
}
}
return - V_114 ;
case V_118 :
if ( V_57 . V_109 & V_110 ) {
struct V_2 * V_2 = F_58 ( V_35 ) ;
if ( V_2 -> V_119 . V_120 . V_121 ) {
F_60 ( L_1 ) ;
return - V_55 ;
}
if ( V_35 -> V_111 != V_112 )
return - V_113 ;
V_39 -> V_100 = 1 ;
return 0 ;
}
if ( V_57 . V_98 & ~ V_33 )
return - V_64 ;
if ( V_2 -> V_119 . V_120 . V_122 &&
( V_57 . V_98 & V_123 ) )
return - V_124 ;
V_4 = F_44 ( V_2 , V_35 , & V_57 , V_58 , V_59 , & V_63 ) ;
if ( ! V_4 )
return V_63 ;
V_104 = F_47 ( sizeof( * V_104 ) , V_67 ) ;
if ( V_57 . V_98 ) {
V_63 = - V_125 ;
F_5 () ;
F_37 (np, sfl) {
if ( V_37 -> V_4 -> V_3 == V_57 . V_98 ) {
if ( V_57 . V_109 & V_126 ) {
F_7 () ;
goto V_65;
}
V_106 = V_37 -> V_4 ;
F_32 ( & V_106 -> V_6 ) ;
break;
}
}
F_7 () ;
if ( ! V_106 )
V_106 = F_4 ( V_2 , V_57 . V_98 ) ;
if ( V_106 ) {
V_127:
V_63 = - V_125 ;
if ( V_57 . V_109 & V_126 )
goto V_128;
V_63 = - V_55 ;
if ( V_106 -> V_7 == V_19 ||
V_106 -> V_7 != V_4 -> V_7 ||
( ( V_106 -> V_7 == V_8 ) &&
( V_106 -> V_9 . V_10 == V_4 -> V_9 . V_10 ) ) ||
( ( V_106 -> V_7 == V_89 ) &&
F_61 ( V_106 -> V_9 . V_90 , V_4 -> V_9 . V_90 ) ) )
goto V_128;
V_63 = - V_66 ;
if ( ! V_104 )
goto V_128;
if ( V_4 -> V_17 > V_106 -> V_17 )
V_106 -> V_17 = V_4 -> V_17 ;
if ( ( long ) ( V_4 -> V_18 - V_106 -> V_18 ) > 0 )
V_106 -> V_18 = V_4 -> V_18 ;
F_55 ( V_39 , V_104 , V_106 ) ;
F_8 ( V_4 ) ;
return 0 ;
V_128:
F_12 ( V_106 ) ;
goto V_65;
}
}
V_63 = - V_102 ;
if ( ! ( V_57 . V_109 & V_129 ) )
goto V_65;
V_63 = - V_66 ;
if ( ! V_104 )
goto V_65;
V_63 = F_54 ( V_35 ) ;
if ( V_63 != 0 )
goto V_65;
V_106 = F_29 ( V_2 , V_4 , V_57 . V_98 ) ;
if ( V_106 )
goto V_127;
if ( ! V_57 . V_98 ) {
if ( F_62 ( & ( (struct V_56 T_4 * ) V_58 ) -> V_98 ,
& V_4 -> V_3 , sizeof( V_4 -> V_3 ) ) ) {
}
}
F_55 ( V_39 , V_104 , V_4 ) ;
return 0 ;
default:
return - V_64 ;
}
V_65:
F_8 ( V_4 ) ;
F_10 ( V_104 ) ;
return V_63 ;
}
static struct V_1 * F_63 ( struct V_130 * V_131 )
{
struct V_1 * V_4 = NULL ;
struct V_132 * V_133 = F_64 ( V_131 ) ;
struct V_2 * V_2 = F_65 ( V_131 ) ;
for ( V_133 -> V_134 = 0 ; V_133 -> V_134 <= V_26 ; ++ V_133 -> V_134 ) {
F_2 (state->bucket, fl) {
if ( F_3 ( V_4 -> V_5 , V_2 ) )
goto V_135;
}
}
V_4 = NULL ;
V_135:
return V_4 ;
}
static struct V_1 * F_66 ( struct V_130 * V_131 , struct V_1 * V_4 )
{
struct V_132 * V_133 = F_64 ( V_131 ) ;
struct V_2 * V_2 = F_65 ( V_131 ) ;
F_67 (fl) {
if ( F_3 ( V_4 -> V_5 , V_2 ) )
goto V_135;
}
V_136:
if ( ++ V_133 -> V_134 <= V_26 ) {
F_2 (state->bucket, fl) {
if ( F_3 ( V_4 -> V_5 , V_2 ) )
goto V_135;
}
goto V_136;
}
V_4 = NULL ;
V_135:
return V_4 ;
}
static struct V_1 * F_68 ( struct V_130 * V_131 , T_5 V_137 )
{
struct V_1 * V_4 = F_63 ( V_131 ) ;
if ( V_4 )
while ( V_137 && ( V_4 = F_66 ( V_131 , V_4 ) ) != NULL )
-- V_137 ;
return V_137 ? NULL : V_4 ;
}
static void * F_69 ( struct V_130 * V_131 , T_5 * V_137 )
__acquires( T_6 )
{
F_5 () ;
return * V_137 ? F_68 ( V_131 , * V_137 - 1 ) : V_138 ;
}
static void * F_70 ( struct V_130 * V_131 , void * V_139 , T_5 * V_137 )
{
struct V_1 * V_4 ;
if ( V_139 == V_138 )
V_4 = F_63 ( V_131 ) ;
else
V_4 = F_66 ( V_131 , V_139 ) ;
++ * V_137 ;
return V_4 ;
}
static void F_71 ( struct V_130 * V_131 , void * V_139 )
__releases( T_6 )
{
F_7 () ;
}
static int F_72 ( struct V_130 * V_131 , void * V_139 )
{
struct V_132 * V_133 = F_64 ( V_131 ) ;
if ( V_139 == V_138 ) {
F_73 ( V_131 , L_2 ) ;
} else {
struct V_1 * V_4 = V_139 ;
F_74 ( V_131 ,
L_3 ,
( unsigned int ) F_75 ( V_4 -> V_3 ) ,
V_4 -> V_7 ,
( ( V_4 -> V_7 == V_8 ) ?
F_76 ( V_4 -> V_9 . V_10 , V_133 -> V_140 ) :
( ( V_4 -> V_7 == V_89 ) ?
F_77 ( F_78 ( V_131 ) , V_4 -> V_9 . V_90 ) :
0 ) ) ,
F_23 ( & V_4 -> V_6 ) ,
V_4 -> V_17 / V_53 ,
( long ) ( V_4 -> V_18 - V_15 ) / V_53 ,
& V_4 -> V_85 ,
V_4 -> V_11 ? V_4 -> V_11 -> V_49 : 0 ) ;
}
return 0 ;
}
static int F_79 ( struct V_141 * V_141 , struct V_142 * V_142 )
{
struct V_130 * V_131 ;
struct V_132 * V_133 ;
int V_63 ;
V_63 = F_80 ( V_141 , V_142 , & V_143 ,
sizeof( struct V_132 ) ) ;
if ( ! V_63 ) {
V_131 = V_142 -> V_144 ;
V_133 = F_64 ( V_131 ) ;
F_81 () ;
V_133 -> V_140 = F_82 ( F_83 ( V_87 ) ) ;
F_84 () ;
}
return V_63 ;
}
static int F_85 ( struct V_141 * V_141 , struct V_142 * V_142 )
{
struct V_130 * V_131 = V_142 -> V_144 ;
struct V_132 * V_133 = F_64 ( V_131 ) ;
F_86 ( V_133 -> V_140 ) ;
return F_87 ( V_141 , V_142 ) ;
}
static int T_7 F_88 ( struct V_2 * V_2 )
{
if ( ! F_89 ( L_4 , V_145 , V_2 -> V_146 ,
& V_147 ) )
return - V_66 ;
return 0 ;
}
static void T_3 F_90 ( struct V_2 * V_2 )
{
F_91 ( L_4 , V_2 -> V_146 ) ;
}
static inline int F_88 ( struct V_2 * V_2 )
{
return 0 ;
}
static inline void F_90 ( struct V_2 * V_2 )
{
}
static void T_3 F_92 ( struct V_2 * V_2 )
{
F_28 ( V_2 ) ;
F_90 ( V_2 ) ;
}
int F_93 ( void )
{
return F_94 ( & V_148 ) ;
}
void F_95 ( void )
{
F_96 ( & V_21 ) ;
F_97 ( & V_148 ) ;
}
