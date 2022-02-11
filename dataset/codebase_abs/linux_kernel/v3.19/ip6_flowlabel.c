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
struct V_1 * V_4 ;
struct V_1 T_2 * * V_27 ;
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
static void T_3 F_29 ( struct V_2 * V_2 )
{
int V_23 ;
F_21 ( & V_13 ) ;
for ( V_23 = 0 ; V_23 <= V_26 ; V_23 ++ ) {
struct V_1 * V_4 ;
struct V_1 T_2 * * V_27 ;
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
F_14 ( & V_13 ) ;
V_4 -> V_14 = V_15 ;
if ( F_27 ( V_4 -> V_17 , V_17 ) )
V_4 -> V_17 = V_17 ;
if ( F_27 ( V_18 , V_4 -> V_17 ) )
V_18 = V_4 -> V_17 ;
if ( F_27 ( V_4 -> V_18 , V_4 -> V_14 + V_18 ) )
V_4 -> V_18 = V_4 -> V_14 + V_18 ;
F_19 ( & V_13 ) ;
return 0 ;
}
static struct V_1 *
F_45 ( struct V_2 * V_2 , struct V_34 * V_35 , struct V_56 * V_57 ,
char T_4 * V_58 , int V_59 , int * V_60 )
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
F_5 () ;
F_38 (np, sfl)
V_90 ++ ;
F_7 () ;
if ( V_88 <= 0 ||
( ( V_90 >= V_91 ||
( V_90 > 0 && V_88 < V_89 / 2 ) || V_88 < V_89 / 4 ) &&
! F_43 ( V_54 ) ) )
return - V_92 ;
return 0 ;
}
static inline void F_57 ( struct V_38 * V_39 , struct V_36 * V_37 ,
struct V_1 * V_4 )
{
F_14 ( & V_41 ) ;
V_37 -> V_4 = V_4 ;
V_37 -> V_29 = V_39 -> V_40 ;
F_35 ( V_39 -> V_40 , V_37 ) ;
F_19 ( & V_41 ) ;
}
int F_58 ( struct V_34 * V_35 , struct V_56 * V_57 ,
int V_93 )
{
struct V_38 * V_39 = F_37 ( V_35 ) ;
struct V_36 * V_37 ;
if ( V_93 & V_94 ) {
V_57 -> V_95 = V_39 -> V_96 & V_33 ;
return 0 ;
}
if ( V_39 -> V_97 ) {
V_57 -> V_95 = V_39 -> V_98 ;
return 0 ;
}
F_5 () ;
F_38 (np, sfl) {
if ( V_37 -> V_4 -> V_3 == ( V_39 -> V_98 & V_33 ) ) {
F_14 ( & V_13 ) ;
V_57 -> V_95 = V_37 -> V_4 -> V_3 ;
V_57 -> V_79 = V_37 -> V_4 -> V_82 ;
V_57 -> V_78 = V_37 -> V_4 -> V_7 ;
V_57 -> V_77 = ( V_37 -> V_4 -> V_18 - V_15 ) / V_53 ;
V_57 -> V_76 = V_37 -> V_4 -> V_17 / V_53 ;
F_19 ( & V_13 ) ;
F_7 () ;
return 0 ;
}
}
F_7 () ;
return - V_99 ;
}
int F_59 ( struct V_34 * V_35 , char T_4 * V_58 , int V_59 )
{
int V_100 ( V_63 ) ;
struct V_2 * V_2 = F_60 ( V_35 ) ;
struct V_38 * V_39 = F_37 ( V_35 ) ;
struct V_56 V_57 ;
struct V_36 * V_101 = NULL ;
struct V_36 * V_37 ;
struct V_36 T_2 * * V_102 ;
struct V_1 * V_4 , * V_103 = NULL ;
if ( V_59 < sizeof( V_57 ) )
return - V_64 ;
if ( F_49 ( & V_57 , V_58 , sizeof( V_57 ) ) )
return - V_73 ;
switch ( V_57 . V_104 ) {
case V_105 :
if ( V_57 . V_106 & V_107 ) {
if ( V_35 -> V_108 != V_109 )
return - V_110 ;
if ( ! V_39 -> V_97 )
return - V_111 ;
V_39 -> V_98 = 0 ;
V_39 -> V_97 = 0 ;
return 0 ;
}
F_14 ( & V_41 ) ;
for ( V_102 = & V_39 -> V_40 ;
( V_37 = F_61 ( * V_102 ) ) != NULL ;
V_102 = & V_37 -> V_29 ) {
if ( V_37 -> V_4 -> V_3 == V_57 . V_95 ) {
if ( V_57 . V_95 == ( V_39 -> V_98 & V_33 ) )
V_39 -> V_98 &= ~ V_33 ;
* V_102 = F_61 ( V_37 -> V_29 ) ;
F_19 ( & V_41 ) ;
F_13 ( V_37 -> V_4 ) ;
F_12 ( V_37 , V_12 ) ;
return 0 ;
}
}
F_19 ( & V_41 ) ;
return - V_111 ;
case V_112 :
F_5 () ;
F_38 (np, sfl) {
if ( V_37 -> V_4 -> V_3 == V_57 . V_95 ) {
V_63 = F_44 ( V_37 -> V_4 , V_57 . V_76 , V_57 . V_77 ) ;
F_7 () ;
return V_63 ;
}
}
F_7 () ;
if ( V_57 . V_78 == V_113 &&
F_62 ( V_2 -> V_114 , V_54 ) ) {
V_4 = F_4 ( V_2 , V_57 . V_95 ) ;
if ( V_4 ) {
V_63 = F_44 ( V_4 , V_57 . V_76 , V_57 . V_77 ) ;
F_13 ( V_4 ) ;
return V_63 ;
}
}
return - V_111 ;
case V_115 :
if ( V_57 . V_106 & V_107 ) {
struct V_2 * V_2 = F_60 ( V_35 ) ;
if ( V_2 -> V_116 . V_117 . V_118 ) {
F_63 ( L_1 ) ;
return - V_55 ;
}
if ( V_35 -> V_108 != V_109 )
return - V_110 ;
V_39 -> V_97 = 1 ;
return 0 ;
}
if ( V_57 . V_95 & ~ V_33 )
return - V_64 ;
V_4 = F_45 ( V_2 , V_35 , & V_57 , V_58 , V_59 , & V_63 ) ;
if ( V_4 == NULL )
return V_63 ;
V_101 = F_48 ( sizeof( * V_101 ) , V_67 ) ;
if ( V_57 . V_95 ) {
V_63 = - V_119 ;
F_5 () ;
F_38 (np, sfl) {
if ( V_37 -> V_4 -> V_3 == V_57 . V_95 ) {
if ( V_57 . V_106 & V_120 ) {
F_7 () ;
goto V_65;
}
V_103 = V_37 -> V_4 ;
F_33 ( & V_103 -> V_6 ) ;
break;
}
}
F_7 () ;
if ( V_103 == NULL )
V_103 = F_4 ( V_2 , V_57 . V_95 ) ;
if ( V_103 ) {
V_121:
V_63 = - V_119 ;
if ( V_57 . V_106 & V_120 )
goto V_122;
V_63 = - V_55 ;
if ( V_103 -> V_7 == V_19 ||
V_103 -> V_7 != V_4 -> V_7 ||
( ( V_103 -> V_7 == V_8 ) &&
( V_103 -> V_9 . V_10 == V_4 -> V_9 . V_10 ) ) ||
( ( V_103 -> V_7 == V_86 ) &&
F_64 ( V_103 -> V_9 . V_87 , V_4 -> V_9 . V_87 ) ) )
goto V_122;
V_63 = - V_66 ;
if ( V_101 == NULL )
goto V_122;
if ( V_4 -> V_17 > V_103 -> V_17 )
V_103 -> V_17 = V_4 -> V_17 ;
if ( ( long ) ( V_4 -> V_18 - V_103 -> V_18 ) > 0 )
V_103 -> V_18 = V_4 -> V_18 ;
F_57 ( V_39 , V_101 , V_103 ) ;
F_8 ( V_4 ) ;
return 0 ;
V_122:
F_13 ( V_103 ) ;
goto V_65;
}
}
V_63 = - V_99 ;
if ( ! ( V_57 . V_106 & V_123 ) )
goto V_65;
V_63 = - V_66 ;
if ( V_101 == NULL )
goto V_65;
V_63 = F_56 ( V_35 ) ;
if ( V_63 != 0 )
goto V_65;
V_103 = F_30 ( V_2 , V_4 , V_57 . V_95 ) ;
if ( V_103 != NULL )
goto V_121;
if ( ! V_57 . V_95 ) {
if ( F_65 ( & ( (struct V_56 T_4 * ) V_58 ) -> V_95 ,
& V_4 -> V_3 , sizeof( V_4 -> V_3 ) ) ) {
}
}
F_57 ( V_39 , V_101 , V_4 ) ;
return 0 ;
default:
return - V_64 ;
}
V_65:
F_8 ( V_4 ) ;
F_11 ( V_101 ) ;
return V_63 ;
}
static struct V_1 * F_66 ( struct V_124 * V_125 )
{
struct V_1 * V_4 = NULL ;
struct V_126 * V_127 = F_67 ( V_125 ) ;
struct V_2 * V_2 = F_68 ( V_125 ) ;
for ( V_127 -> V_128 = 0 ; V_127 -> V_128 <= V_26 ; ++ V_127 -> V_128 ) {
F_2 (state->bucket, fl) {
if ( F_3 ( V_4 -> V_5 , V_2 ) )
goto V_129;
}
}
V_4 = NULL ;
V_129:
return V_4 ;
}
static struct V_1 * F_69 ( struct V_124 * V_125 , struct V_1 * V_4 )
{
struct V_126 * V_127 = F_67 ( V_125 ) ;
struct V_2 * V_2 = F_68 ( V_125 ) ;
F_70 (fl) {
if ( F_3 ( V_4 -> V_5 , V_2 ) )
goto V_129;
}
V_130:
if ( ++ V_127 -> V_128 <= V_26 ) {
F_2 (state->bucket, fl) {
if ( F_3 ( V_4 -> V_5 , V_2 ) )
goto V_129;
}
goto V_130;
}
V_4 = NULL ;
V_129:
return V_4 ;
}
static struct V_1 * F_71 ( struct V_124 * V_125 , T_5 V_131 )
{
struct V_1 * V_4 = F_66 ( V_125 ) ;
if ( V_4 )
while ( V_131 && ( V_4 = F_69 ( V_125 , V_4 ) ) != NULL )
-- V_131 ;
return V_131 ? NULL : V_4 ;
}
static void * F_72 ( struct V_124 * V_125 , T_5 * V_131 )
__acquires( T_6 )
{
F_5 () ;
return * V_131 ? F_71 ( V_125 , * V_131 - 1 ) : V_132 ;
}
static void * F_73 ( struct V_124 * V_125 , void * V_133 , T_5 * V_131 )
{
struct V_1 * V_4 ;
if ( V_133 == V_132 )
V_4 = F_66 ( V_125 ) ;
else
V_4 = F_69 ( V_125 , V_133 ) ;
++ * V_131 ;
return V_4 ;
}
static void F_74 ( struct V_124 * V_125 , void * V_133 )
__releases( T_6 )
{
F_7 () ;
}
static int F_75 ( struct V_124 * V_125 , void * V_133 )
{
struct V_126 * V_127 = F_67 ( V_125 ) ;
if ( V_133 == V_132 ) {
F_76 ( V_125 , L_2 ) ;
} else {
struct V_1 * V_4 = V_133 ;
F_77 ( V_125 ,
L_3 ,
( unsigned int ) F_78 ( V_4 -> V_3 ) ,
V_4 -> V_7 ,
( ( V_4 -> V_7 == V_8 ) ?
F_79 ( V_4 -> V_9 . V_10 , V_127 -> V_134 ) :
( ( V_4 -> V_7 == V_86 ) ?
F_80 ( F_81 ( V_125 ) , V_4 -> V_9 . V_87 ) :
0 ) ) ,
F_24 ( & V_4 -> V_6 ) ,
V_4 -> V_17 / V_53 ,
( long ) ( V_4 -> V_18 - V_15 ) / V_53 ,
& V_4 -> V_82 ,
V_4 -> V_11 ? V_4 -> V_11 -> V_49 : 0 ) ;
}
return 0 ;
}
static int F_82 ( struct V_135 * V_135 , struct V_136 * V_136 )
{
struct V_124 * V_125 ;
struct V_126 * V_127 ;
int V_63 ;
V_63 = F_83 ( V_135 , V_136 , & V_137 ,
sizeof( struct V_126 ) ) ;
if ( ! V_63 ) {
V_125 = V_136 -> V_138 ;
V_127 = F_67 ( V_125 ) ;
F_84 () ;
V_127 -> V_134 = F_85 ( F_86 ( V_84 ) ) ;
F_87 () ;
}
return V_63 ;
}
static int F_88 ( struct V_135 * V_135 , struct V_136 * V_136 )
{
struct V_124 * V_125 = V_136 -> V_138 ;
struct V_126 * V_127 = F_67 ( V_125 ) ;
F_89 ( V_127 -> V_134 ) ;
return F_90 ( V_135 , V_136 ) ;
}
static int T_7 F_91 ( struct V_2 * V_2 )
{
if ( ! F_92 ( L_4 , V_139 , V_2 -> V_140 ,
& V_141 ) )
return - V_66 ;
return 0 ;
}
static void T_3 F_93 ( struct V_2 * V_2 )
{
F_94 ( L_4 , V_2 -> V_140 ) ;
}
static inline int F_91 ( struct V_2 * V_2 )
{
return 0 ;
}
static inline void F_93 ( struct V_2 * V_2 )
{
}
static void T_3 F_95 ( struct V_2 * V_2 )
{
F_29 ( V_2 ) ;
F_93 ( V_2 ) ;
}
int F_96 ( void )
{
return F_97 ( & V_142 ) ;
}
void F_98 ( void )
{
F_99 ( & V_21 ) ;
F_100 ( & V_142 ) ;
}
