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
int V_71 ;
V_63 = - V_66 ;
V_4 -> V_11 = F_47 ( sizeof( * V_4 -> V_11 ) + V_61 , V_67 ) ;
if ( ! V_4 -> V_11 )
goto V_65;
memset ( V_4 -> V_11 , 0 , sizeof( * V_4 -> V_11 ) ) ;
V_4 -> V_11 -> V_72 = sizeof( * V_4 -> V_11 ) + V_61 ;
V_63 = - V_73 ;
if ( F_48 ( V_4 -> V_11 + 1 , V_58 + F_45 ( sizeof( * V_57 ) ) , V_61 ) )
goto V_65;
V_69 . V_74 = V_61 ;
V_69 . V_75 = ( void * ) ( V_4 -> V_11 + 1 ) ;
memset ( & V_70 , 0 , sizeof( V_70 ) ) ;
V_63 = F_49 ( V_2 , V_35 , & V_69 , & V_70 , V_4 -> V_11 ,
& V_71 , & V_71 , & V_71 ) ;
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
V_63 = F_43 ( V_4 , V_57 -> V_76 , V_57 -> V_77 ) ;
if ( V_63 )
goto V_65;
V_4 -> V_7 = V_57 -> V_78 ;
V_62 = F_50 ( & V_57 -> V_79 ) ;
if ( ( V_62 & V_80 ) ||
V_62 == V_81 ) {
V_63 = - V_64 ;
goto V_65;
}
V_4 -> V_82 = V_57 -> V_79 ;
F_51 ( & V_4 -> V_6 , 1 ) ;
switch ( V_4 -> V_7 ) {
case V_19 :
case V_83 :
break;
case V_8 :
V_4 -> V_9 . V_10 = F_52 ( V_84 , V_85 ) ;
break;
case V_86 :
V_4 -> V_9 . V_87 = F_53 () ;
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
int V_88 = V_89 - F_23 ( & V_30 ) ;
int V_90 = 0 ;
if ( V_88 > V_89 - V_91 )
return 0 ;
F_5 () ;
F_37 (np, sfl)
V_90 ++ ;
F_7 () ;
if ( V_88 <= 0 ||
( ( V_90 >= V_91 ||
( V_90 > 0 && V_88 < V_89 / 2 ) || V_88 < V_89 / 4 ) &&
! F_42 ( V_54 ) ) )
return - V_92 ;
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
int V_93 )
{
struct V_38 * V_39 = F_36 ( V_35 ) ;
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
F_37 (np, sfl) {
if ( V_37 -> V_4 -> V_3 == ( V_39 -> V_98 & V_33 ) ) {
F_13 ( & V_13 ) ;
V_57 -> V_95 = V_37 -> V_4 -> V_3 ;
V_57 -> V_79 = V_37 -> V_4 -> V_82 ;
V_57 -> V_78 = V_37 -> V_4 -> V_7 ;
V_57 -> V_77 = ( V_37 -> V_4 -> V_18 - V_15 ) / V_53 ;
V_57 -> V_76 = V_37 -> V_4 -> V_17 / V_53 ;
F_18 ( & V_13 ) ;
F_7 () ;
return 0 ;
}
}
F_7 () ;
return - V_99 ;
}
int F_57 ( struct V_34 * V_35 , char T_4 * V_58 , int V_59 )
{
int V_100 ( V_63 ) ;
struct V_2 * V_2 = F_58 ( V_35 ) ;
struct V_38 * V_39 = F_36 ( V_35 ) ;
struct V_56 V_57 ;
struct V_36 * V_101 = NULL ;
struct V_36 * V_37 ;
struct V_36 T_2 * * V_102 ;
struct V_1 * V_4 , * V_103 = NULL ;
if ( V_59 < sizeof( V_57 ) )
return - V_64 ;
if ( F_48 ( & V_57 , V_58 , sizeof( V_57 ) ) )
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
F_13 ( & V_41 ) ;
for ( V_102 = & V_39 -> V_40 ;
( V_37 = F_59 ( * V_102 ) ) != NULL ;
V_102 = & V_37 -> V_29 ) {
if ( V_37 -> V_4 -> V_3 == V_57 . V_95 ) {
if ( V_57 . V_95 == ( V_39 -> V_98 & V_33 ) )
V_39 -> V_98 &= ~ V_33 ;
* V_102 = F_59 ( V_37 -> V_29 ) ;
F_18 ( & V_41 ) ;
F_12 ( V_37 -> V_4 ) ;
F_11 ( V_37 , V_12 ) ;
return 0 ;
}
}
F_18 ( & V_41 ) ;
return - V_111 ;
case V_112 :
F_5 () ;
F_37 (np, sfl) {
if ( V_37 -> V_4 -> V_3 == V_57 . V_95 ) {
V_63 = F_43 ( V_37 -> V_4 , V_57 . V_76 , V_57 . V_77 ) ;
F_7 () ;
return V_63 ;
}
}
F_7 () ;
if ( V_57 . V_78 == V_113 &&
F_60 ( V_2 -> V_114 , V_54 ) ) {
V_4 = F_4 ( V_2 , V_57 . V_95 ) ;
if ( V_4 ) {
V_63 = F_43 ( V_4 , V_57 . V_76 , V_57 . V_77 ) ;
F_12 ( V_4 ) ;
return V_63 ;
}
}
return - V_111 ;
case V_115 :
if ( V_57 . V_106 & V_107 ) {
struct V_2 * V_2 = F_58 ( V_35 ) ;
if ( V_2 -> V_116 . V_117 . V_118 ) {
F_61 ( L_1 ) ;
return - V_55 ;
}
if ( V_35 -> V_108 != V_109 )
return - V_110 ;
V_39 -> V_97 = 1 ;
return 0 ;
}
if ( V_57 . V_95 & ~ V_33 )
return - V_64 ;
if ( V_2 -> V_116 . V_117 . V_119 &&
( V_57 . V_95 & V_120 ) )
return - V_121 ;
V_4 = F_44 ( V_2 , V_35 , & V_57 , V_58 , V_59 , & V_63 ) ;
if ( ! V_4 )
return V_63 ;
V_101 = F_47 ( sizeof( * V_101 ) , V_67 ) ;
if ( V_57 . V_95 ) {
V_63 = - V_122 ;
F_5 () ;
F_37 (np, sfl) {
if ( V_37 -> V_4 -> V_3 == V_57 . V_95 ) {
if ( V_57 . V_106 & V_123 ) {
F_7 () ;
goto V_65;
}
V_103 = V_37 -> V_4 ;
F_32 ( & V_103 -> V_6 ) ;
break;
}
}
F_7 () ;
if ( ! V_103 )
V_103 = F_4 ( V_2 , V_57 . V_95 ) ;
if ( V_103 ) {
V_124:
V_63 = - V_122 ;
if ( V_57 . V_106 & V_123 )
goto V_125;
V_63 = - V_55 ;
if ( V_103 -> V_7 == V_19 ||
V_103 -> V_7 != V_4 -> V_7 ||
( ( V_103 -> V_7 == V_8 ) &&
( V_103 -> V_9 . V_10 == V_4 -> V_9 . V_10 ) ) ||
( ( V_103 -> V_7 == V_86 ) &&
F_62 ( V_103 -> V_9 . V_87 , V_4 -> V_9 . V_87 ) ) )
goto V_125;
V_63 = - V_66 ;
if ( ! V_101 )
goto V_125;
if ( V_4 -> V_17 > V_103 -> V_17 )
V_103 -> V_17 = V_4 -> V_17 ;
if ( ( long ) ( V_4 -> V_18 - V_103 -> V_18 ) > 0 )
V_103 -> V_18 = V_4 -> V_18 ;
F_55 ( V_39 , V_101 , V_103 ) ;
F_8 ( V_4 ) ;
return 0 ;
V_125:
F_12 ( V_103 ) ;
goto V_65;
}
}
V_63 = - V_99 ;
if ( ! ( V_57 . V_106 & V_126 ) )
goto V_65;
V_63 = - V_66 ;
if ( ! V_101 )
goto V_65;
V_63 = F_54 ( V_35 ) ;
if ( V_63 != 0 )
goto V_65;
V_103 = F_29 ( V_2 , V_4 , V_57 . V_95 ) ;
if ( V_103 )
goto V_124;
if ( ! V_57 . V_95 ) {
if ( F_63 ( & ( (struct V_56 T_4 * ) V_58 ) -> V_95 ,
& V_4 -> V_3 , sizeof( V_4 -> V_3 ) ) ) {
}
}
F_55 ( V_39 , V_101 , V_4 ) ;
return 0 ;
default:
return - V_64 ;
}
V_65:
F_8 ( V_4 ) ;
F_10 ( V_101 ) ;
return V_63 ;
}
static struct V_1 * F_64 ( struct V_127 * V_128 )
{
struct V_1 * V_4 = NULL ;
struct V_129 * V_130 = F_65 ( V_128 ) ;
struct V_2 * V_2 = F_66 ( V_128 ) ;
for ( V_130 -> V_131 = 0 ; V_130 -> V_131 <= V_26 ; ++ V_130 -> V_131 ) {
F_2 (state->bucket, fl) {
if ( F_3 ( V_4 -> V_5 , V_2 ) )
goto V_132;
}
}
V_4 = NULL ;
V_132:
return V_4 ;
}
static struct V_1 * F_67 ( struct V_127 * V_128 , struct V_1 * V_4 )
{
struct V_129 * V_130 = F_65 ( V_128 ) ;
struct V_2 * V_2 = F_66 ( V_128 ) ;
F_68 (fl) {
if ( F_3 ( V_4 -> V_5 , V_2 ) )
goto V_132;
}
V_133:
if ( ++ V_130 -> V_131 <= V_26 ) {
F_2 (state->bucket, fl) {
if ( F_3 ( V_4 -> V_5 , V_2 ) )
goto V_132;
}
goto V_133;
}
V_4 = NULL ;
V_132:
return V_4 ;
}
static struct V_1 * F_69 ( struct V_127 * V_128 , T_5 V_134 )
{
struct V_1 * V_4 = F_64 ( V_128 ) ;
if ( V_4 )
while ( V_134 && ( V_4 = F_67 ( V_128 , V_4 ) ) != NULL )
-- V_134 ;
return V_134 ? NULL : V_4 ;
}
static void * F_70 ( struct V_127 * V_128 , T_5 * V_134 )
__acquires( T_6 )
{
F_5 () ;
return * V_134 ? F_69 ( V_128 , * V_134 - 1 ) : V_135 ;
}
static void * F_71 ( struct V_127 * V_128 , void * V_136 , T_5 * V_134 )
{
struct V_1 * V_4 ;
if ( V_136 == V_135 )
V_4 = F_64 ( V_128 ) ;
else
V_4 = F_67 ( V_128 , V_136 ) ;
++ * V_134 ;
return V_4 ;
}
static void F_72 ( struct V_127 * V_128 , void * V_136 )
__releases( T_6 )
{
F_7 () ;
}
static int F_73 ( struct V_127 * V_128 , void * V_136 )
{
struct V_129 * V_130 = F_65 ( V_128 ) ;
if ( V_136 == V_135 ) {
F_74 ( V_128 , L_2 ) ;
} else {
struct V_1 * V_4 = V_136 ;
F_75 ( V_128 ,
L_3 ,
( unsigned int ) F_76 ( V_4 -> V_3 ) ,
V_4 -> V_7 ,
( ( V_4 -> V_7 == V_8 ) ?
F_77 ( V_4 -> V_9 . V_10 , V_130 -> V_137 ) :
( ( V_4 -> V_7 == V_86 ) ?
F_78 ( F_79 ( V_128 ) , V_4 -> V_9 . V_87 ) :
0 ) ) ,
F_23 ( & V_4 -> V_6 ) ,
V_4 -> V_17 / V_53 ,
( long ) ( V_4 -> V_18 - V_15 ) / V_53 ,
& V_4 -> V_82 ,
V_4 -> V_11 ? V_4 -> V_11 -> V_49 : 0 ) ;
}
return 0 ;
}
static int F_80 ( struct V_138 * V_138 , struct V_139 * V_139 )
{
struct V_127 * V_128 ;
struct V_129 * V_130 ;
int V_63 ;
V_63 = F_81 ( V_138 , V_139 , & V_140 ,
sizeof( struct V_129 ) ) ;
if ( ! V_63 ) {
V_128 = V_139 -> V_141 ;
V_130 = F_65 ( V_128 ) ;
F_82 () ;
V_130 -> V_137 = F_83 ( F_84 ( V_84 ) ) ;
F_85 () ;
}
return V_63 ;
}
static int F_86 ( struct V_138 * V_138 , struct V_139 * V_139 )
{
struct V_127 * V_128 = V_139 -> V_141 ;
struct V_129 * V_130 = F_65 ( V_128 ) ;
F_87 ( V_130 -> V_137 ) ;
return F_88 ( V_138 , V_139 ) ;
}
static int T_7 F_89 ( struct V_2 * V_2 )
{
if ( ! F_90 ( L_4 , V_142 , V_2 -> V_143 ,
& V_144 ) )
return - V_66 ;
return 0 ;
}
static void T_3 F_91 ( struct V_2 * V_2 )
{
F_92 ( L_4 , V_2 -> V_143 ) ;
}
static inline int F_89 ( struct V_2 * V_2 )
{
return 0 ;
}
static inline void F_91 ( struct V_2 * V_2 )
{
}
static void T_3 F_93 ( struct V_2 * V_2 )
{
F_28 ( V_2 ) ;
F_91 ( V_2 ) ;
}
int F_94 ( void )
{
return F_95 ( & V_145 ) ;
}
void F_96 ( void )
{
F_97 ( & V_21 ) ;
F_98 ( & V_145 ) ;
}
