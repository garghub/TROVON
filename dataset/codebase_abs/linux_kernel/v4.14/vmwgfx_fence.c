static struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 . V_5 , struct V_1 , V_5 ) ;
}
static void F_3 ( struct V_6 * V_7 )
{
struct V_2 * V_3 =
F_2 ( V_7 , struct V_2 , V_4 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
F_4 ( & V_8 -> V_5 ) ;
F_5 ( & V_3 -> V_9 ) ;
-- V_8 -> V_10 ;
F_6 ( & V_8 -> V_5 ) ;
V_3 -> V_11 ( V_3 ) ;
}
static const char * F_7 ( struct V_6 * V_7 )
{
return L_1 ;
}
static const char * F_8 ( struct V_6 * V_7 )
{
return L_2 ;
}
static bool F_9 ( struct V_6 * V_7 )
{
struct V_2 * V_3 =
F_2 ( V_7 , struct V_2 , V_4 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_12 * V_13 = V_8 -> V_13 ;
T_1 * V_14 = V_13 -> V_15 ;
T_1 V_16 = F_10 ( V_14 + V_17 ) ;
if ( V_16 - V_3 -> V_4 . V_16 < V_18 )
return false ;
F_11 ( V_13 , V_19 ) ;
return true ;
}
static void
F_12 ( struct V_6 * V_3 , struct V_20 * V_21 )
{
struct F_12 * V_22 =
F_2 ( V_21 , struct F_12 , V_4 ) ;
F_13 ( V_22 -> V_23 ) ;
}
static long F_14 ( struct V_6 * V_7 , bool V_24 , signed long V_25 )
{
struct V_2 * V_3 =
F_2 ( V_7 , struct V_2 , V_4 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_12 * V_13 = V_8 -> V_13 ;
struct F_12 V_21 ;
long V_26 = V_25 ;
unsigned long V_27 ;
if ( F_15 ( F_16 ( V_3 ) ) )
return V_25 ;
F_11 ( V_13 , V_19 ) ;
F_17 ( V_13 ) ;
F_18 ( V_7 -> V_5 , V_27 ) ;
if ( V_24 && F_19 ( V_28 ) ) {
V_26 = - V_29 ;
goto V_30;
}
V_21 . V_4 . V_31 = F_12 ;
V_21 . V_23 = V_28 ;
F_20 ( & V_21 . V_4 . V_32 , & V_7 -> V_33 ) ;
while ( V_26 > 0 ) {
F_21 ( V_8 ) ;
if ( F_22 ( V_34 , & V_7 -> V_35 ) )
break;
if ( V_24 )
F_23 ( V_36 ) ;
else
F_23 ( V_37 ) ;
F_24 ( V_7 -> V_5 , V_27 ) ;
V_26 = F_25 ( V_26 ) ;
F_18 ( V_7 -> V_5 , V_27 ) ;
if ( V_26 > 0 && V_24 && F_19 ( V_28 ) )
V_26 = - V_29 ;
}
if ( ! F_26 ( & V_21 . V_4 . V_32 ) )
F_27 ( & V_21 . V_4 . V_32 ) ;
F_23 ( V_38 ) ;
V_30:
F_24 ( V_7 -> V_5 , V_27 ) ;
F_28 ( V_13 ) ;
return V_26 ;
}
static void F_29 ( struct V_39 * V_40 )
{
struct V_1 * V_8 =
F_2 ( V_40 , struct V_1 , V_40 ) ;
struct V_41 V_42 ;
struct V_43 * V_44 , * V_45 ;
bool V_46 ;
do {
F_30 ( & V_42 ) ;
F_31 ( & V_8 -> V_47 ) ;
F_4 ( & V_8 -> V_5 ) ;
F_32 ( & V_8 -> V_48 , & V_42 ) ;
V_46 = V_8 -> V_46 ;
F_6 ( & V_8 -> V_5 ) ;
if ( ! V_46 && V_8 -> V_49 ) {
V_8 -> V_49 = false ;
F_33 ( V_8 -> V_13 ) ;
}
F_34 ( & V_8 -> V_47 ) ;
if ( F_26 ( & V_42 ) )
return;
F_35 (action, next_action, &list, head) {
F_5 ( & V_44 -> V_9 ) ;
if ( V_44 -> V_50 )
V_44 -> V_50 ( V_44 ) ;
}
} while ( 1 );
}
struct V_1 * F_36 ( struct V_12 * V_13 )
{
struct V_1 * V_8 = F_37 ( sizeof( * V_8 ) , V_51 ) ;
if ( F_38 ( ! V_8 ) )
return NULL ;
V_8 -> V_13 = V_13 ;
F_39 ( & V_8 -> V_5 ) ;
F_30 ( & V_8 -> V_52 ) ;
F_30 ( & V_8 -> V_48 ) ;
F_40 ( & V_8 -> V_40 , & F_29 ) ;
V_8 -> V_53 = true ;
V_8 -> V_54 = F_41 ( sizeof( struct V_55 ) ) ;
V_8 -> V_56 = F_41 ( sizeof( struct V_2 ) ) ;
V_8 -> V_57 =
F_41 ( sizeof( struct V_58 ) ) ;
F_42 ( & V_8 -> V_47 ) ;
V_8 -> V_59 = F_43 ( 1 ) ;
return V_8 ;
}
void F_44 ( struct V_1 * V_8 )
{
bool V_60 ;
( void ) F_45 ( & V_8 -> V_40 ) ;
F_4 ( & V_8 -> V_5 ) ;
V_60 = F_26 ( & V_8 -> V_52 ) &&
F_26 ( & V_8 -> V_48 ) ;
F_6 ( & V_8 -> V_5 ) ;
F_46 ( ! V_60 ) ;
F_47 ( V_8 ) ;
}
static int F_48 ( struct V_1 * V_8 ,
struct V_2 * V_3 , T_1 V_16 ,
void (* V_11) ( struct V_2 * V_3 ) )
{
int V_26 = 0 ;
F_49 ( & V_3 -> V_4 , & V_61 , & V_8 -> V_5 ,
V_8 -> V_59 , V_16 ) ;
F_30 ( & V_3 -> V_62 ) ;
V_3 -> V_11 = V_11 ;
F_4 ( & V_8 -> V_5 ) ;
if ( F_38 ( V_8 -> V_53 ) ) {
V_26 = - V_63 ;
goto V_64;
}
F_50 ( & V_3 -> V_9 , & V_8 -> V_52 ) ;
++ V_8 -> V_10 ;
V_64:
F_6 ( & V_8 -> V_5 ) ;
return V_26 ;
}
static void F_51 ( struct V_1 * V_8 ,
struct V_41 * V_42 )
{
struct V_43 * V_44 , * V_45 ;
F_35 (action, next_action, list, head) {
F_5 ( & V_44 -> V_9 ) ;
V_8 -> V_65 [ V_44 -> type ] -- ;
if ( V_44 -> V_66 != NULL )
V_44 -> V_66 ( V_44 ) ;
F_50 ( & V_44 -> V_9 , & V_8 -> V_48 ) ;
}
}
static bool F_52 ( struct V_1 * V_8 ,
T_1 V_67 )
{
T_1 V_68 ;
T_1 * V_14 ;
struct V_2 * V_3 ;
if ( F_15 ( ! V_8 -> V_46 ) )
return false ;
V_14 = V_8 -> V_13 -> V_15 ;
V_68 = F_10 ( V_14 + V_69 ) ;
if ( F_15 ( V_67 - V_68 >= V_18 ) )
return false ;
V_8 -> V_46 = false ;
F_53 (fence, &fman->fence_list, head) {
if ( ! F_26 ( & V_3 -> V_62 ) ) {
V_8 -> V_46 = true ;
F_54 ( V_3 -> V_4 . V_16 ,
V_14 + V_69 ) ;
break;
}
}
return true ;
}
static bool F_55 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
T_1 V_68 ;
T_1 * V_14 ;
if ( F_56 ( & V_3 -> V_4 ) )
return false ;
V_14 = V_8 -> V_13 -> V_15 ;
V_68 = F_10 ( V_14 + V_69 ) ;
if ( F_15 ( V_8 -> V_46 &&
V_68 - V_3 -> V_4 . V_16 < V_18 ) )
return false ;
F_54 ( V_3 -> V_4 . V_16 , V_14 + V_69 ) ;
V_8 -> V_46 = true ;
return true ;
}
static void F_21 ( struct V_1 * V_8 )
{
struct V_2 * V_3 , * V_70 ;
struct V_41 V_71 ;
bool V_72 ;
T_2 V_16 , V_73 ;
T_1 * V_14 = V_8 -> V_13 -> V_15 ;
V_16 = F_10 ( V_14 + V_17 ) ;
V_74:
F_35 (fence, next_fence, &fman->fence_list, head) {
if ( V_16 - V_3 -> V_4 . V_16 < V_18 ) {
F_5 ( & V_3 -> V_9 ) ;
F_57 ( & V_3 -> V_4 ) ;
F_30 ( & V_71 ) ;
F_32 ( & V_3 -> V_62 ,
& V_71 ) ;
F_51 ( V_8 , & V_71 ) ;
} else
break;
}
V_72 = F_52 ( V_8 , V_16 ) ;
if ( F_38 ( V_72 ) ) {
V_73 = F_10 ( V_14 + V_17 ) ;
if ( V_73 != V_16 ) {
V_16 = V_73 ;
goto V_74;
}
}
if ( ! F_26 ( & V_8 -> V_48 ) )
( void ) F_58 ( & V_8 -> V_40 ) ;
}
void F_59 ( struct V_1 * V_8 )
{
F_4 ( & V_8 -> V_5 ) ;
F_21 ( V_8 ) ;
F_6 ( & V_8 -> V_5 ) ;
}
bool F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
if ( F_22 ( V_34 , & V_3 -> V_4 . V_35 ) )
return 1 ;
F_59 ( V_8 ) ;
return F_60 ( & V_3 -> V_4 ) ;
}
int F_61 ( struct V_2 * V_3 , bool V_75 ,
bool V_76 , unsigned long V_25 )
{
long V_26 = F_62 ( & V_3 -> V_4 , V_76 , V_25 ) ;
if ( F_15 ( V_26 > 0 ) )
return 0 ;
else if ( V_26 == 0 )
return - V_63 ;
else
return V_26 ;
}
void F_63 ( struct V_2 * V_3 )
{
struct V_12 * V_13 = F_1 ( V_3 ) -> V_13 ;
F_11 ( V_13 , V_19 ) ;
}
static void F_64 ( struct V_2 * V_3 )
{
F_65 ( & V_3 -> V_4 ) ;
}
int F_66 ( struct V_1 * V_8 ,
T_2 V_16 ,
struct V_2 * * V_77 )
{
struct V_2 * V_3 ;
int V_26 ;
V_3 = F_37 ( sizeof( * V_3 ) , V_51 ) ;
if ( F_38 ( ! V_3 ) )
return - V_78 ;
V_26 = F_48 ( V_8 , V_3 , V_16 ,
F_64 ) ;
if ( F_38 ( V_26 != 0 ) )
goto V_79;
* V_77 = V_3 ;
return 0 ;
V_79:
F_47 ( V_3 ) ;
return V_26 ;
}
static void F_67 ( struct V_2 * V_3 )
{
struct V_55 * V_80 =
F_2 ( V_3 , struct V_55 , V_3 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
F_68 ( V_80 , V_4 ) ;
F_69 ( F_70 ( V_8 -> V_13 ) ,
V_8 -> V_54 ) ;
}
static void F_71 ( struct V_81 * * V_82 )
{
struct V_81 * V_4 = * V_82 ;
struct V_55 * V_80 =
F_2 ( V_4 , struct V_55 , V_4 ) ;
struct V_2 * V_3 = & V_80 -> V_3 ;
* V_82 = NULL ;
F_72 ( & V_3 ) ;
}
int F_73 ( struct V_83 * V_84 ,
struct V_1 * V_8 ,
T_2 V_16 ,
struct V_2 * * V_77 ,
T_2 * V_85 )
{
struct V_86 * V_87 = F_74 ( V_84 ) -> V_87 ;
struct V_55 * V_80 ;
struct V_2 * V_88 ;
struct V_89 * V_90 = F_70 ( V_8 -> V_13 ) ;
int V_26 ;
V_26 = F_75 ( V_90 , V_8 -> V_54 ,
false , false ) ;
if ( F_38 ( V_26 != 0 ) )
return V_26 ;
V_80 = F_37 ( sizeof( * V_80 ) , V_51 ) ;
if ( F_38 ( ! V_80 ) ) {
V_26 = - V_78 ;
goto V_91;
}
V_26 = F_48 ( V_8 , & V_80 -> V_3 , V_16 ,
F_67 ) ;
if ( F_38 ( V_26 != 0 ) ) {
F_47 ( V_80 ) ;
goto V_91;
}
V_88 = F_76 ( & V_80 -> V_3 ) ;
V_26 = F_77 ( V_87 , & V_80 -> V_4 , false ,
V_92 ,
& F_71 , NULL ) ;
if ( F_38 ( V_26 != 0 ) ) {
F_72 ( & V_88 ) ;
goto V_93;
}
* V_77 = & V_80 -> V_3 ;
* V_85 = V_80 -> V_4 . V_94 . V_95 ;
return 0 ;
V_93:
V_88 = & V_80 -> V_3 ;
F_72 ( & V_88 ) ;
V_91:
F_69 ( V_90 , V_8 -> V_54 ) ;
return V_26 ;
}
int F_78 ( struct V_1 * V_8 ,
struct V_6 * V_3 )
{
struct V_96 * V_97 ;
int V_26 = 0 ;
int V_98 ;
if ( F_60 ( V_3 ) )
return 0 ;
if ( ! F_79 ( V_3 ) )
return F_80 ( V_3 , true ) ;
V_97 = F_81 ( V_3 ) ;
for ( V_98 = 0 ; V_98 < V_97 -> V_99 ; V_98 ++ ) {
struct V_6 * V_100 = V_97 -> V_101 [ V_98 ] ;
V_26 = F_80 ( V_100 , true ) ;
if ( V_26 < 0 )
return V_26 ;
}
return 0 ;
}
void F_82 ( struct V_1 * V_8 )
{
struct V_41 V_71 ;
int V_26 ;
F_4 ( & V_8 -> V_5 ) ;
V_8 -> V_53 = true ;
while ( ! F_26 ( & V_8 -> V_52 ) ) {
struct V_2 * V_3 =
F_83 ( V_8 -> V_52 . V_102 , struct V_2 ,
V_9 ) ;
F_84 ( & V_3 -> V_4 ) ;
F_6 ( & V_8 -> V_5 ) ;
V_26 = F_61 ( V_3 , false , false ,
V_103 ) ;
if ( F_38 ( V_26 != 0 ) ) {
F_5 ( & V_3 -> V_9 ) ;
F_85 ( & V_3 -> V_4 ) ;
F_30 ( & V_71 ) ;
F_32 ( & V_3 -> V_62 ,
& V_71 ) ;
F_51 ( V_8 , & V_71 ) ;
}
F_46 ( ! F_26 ( & V_3 -> V_9 ) ) ;
F_86 ( & V_3 -> V_4 ) ;
F_4 ( & V_8 -> V_5 ) ;
}
F_6 ( & V_8 -> V_5 ) ;
}
void F_87 ( struct V_1 * V_8 )
{
F_4 ( & V_8 -> V_5 ) ;
V_8 -> V_53 = false ;
F_6 ( & V_8 -> V_5 ) ;
}
static struct V_81 *
F_88 ( struct V_86 * V_87 , T_1 V_104 )
{
struct V_81 * V_4 = F_89 ( V_87 , V_104 ) ;
if ( ! V_4 ) {
F_90 ( L_3 ,
( unsigned long ) V_104 ) ;
return F_91 ( - V_105 ) ;
}
if ( V_4 -> V_106 != F_71 ) {
F_90 ( L_3 ,
( unsigned long ) V_104 ) ;
F_92 ( & V_4 ) ;
return F_91 ( - V_105 ) ;
}
return V_4 ;
}
int F_93 ( struct V_107 * V_108 , void * V_109 ,
struct V_83 * V_84 )
{
struct V_110 * V_111 =
(struct V_110 * ) V_109 ;
unsigned long V_25 ;
struct V_81 * V_4 ;
struct V_2 * V_3 ;
struct V_86 * V_87 = F_74 ( V_84 ) -> V_87 ;
int V_26 ;
T_3 V_112 = ( ( T_3 ) V_111 -> V_113 * V_114 ) ;
V_112 = ( V_112 >> 20 ) + ( V_112 >> 24 ) -
( V_112 >> 26 ) ;
if ( ! V_111 -> V_115 ) {
V_111 -> V_115 = 1 ;
V_111 -> V_116 = V_117 + V_112 ;
}
V_4 = F_88 ( V_87 , V_111 -> V_104 ) ;
if ( F_94 ( V_4 ) )
return F_95 ( V_4 ) ;
V_3 = & ( F_2 ( V_4 , struct V_55 , V_4 ) -> V_3 ) ;
V_25 = V_117 ;
if ( F_96 ( V_25 , ( unsigned long ) V_111 -> V_116 ) ) {
V_26 = ( ( F_16 ( V_3 ) ) ?
0 : - V_63 ) ;
goto V_30;
}
V_25 = ( unsigned long ) V_111 -> V_116 - V_25 ;
V_26 = F_61 ( V_3 , V_111 -> V_75 , true , V_25 ) ;
V_30:
F_92 ( & V_4 ) ;
if ( V_26 == 0 && ( V_111 -> V_118 & V_119 ) )
return F_97 ( V_87 , V_111 -> V_104 ,
V_120 ) ;
return V_26 ;
}
int F_98 ( struct V_107 * V_108 , void * V_109 ,
struct V_83 * V_84 )
{
struct V_121 * V_111 =
(struct V_121 * ) V_109 ;
struct V_81 * V_4 ;
struct V_2 * V_3 ;
struct V_1 * V_8 ;
struct V_86 * V_87 = F_74 ( V_84 ) -> V_87 ;
struct V_12 * V_13 = F_99 ( V_108 ) ;
V_4 = F_88 ( V_87 , V_111 -> V_104 ) ;
if ( F_94 ( V_4 ) )
return F_95 ( V_4 ) ;
V_3 = & ( F_2 ( V_4 , struct V_55 , V_4 ) -> V_3 ) ;
V_8 = F_1 ( V_3 ) ;
V_111 -> V_122 = F_16 ( V_3 ) ;
V_111 -> V_123 = V_111 -> V_35 ;
F_4 ( & V_8 -> V_5 ) ;
V_111 -> V_67 = V_13 -> V_124 ;
F_6 ( & V_8 -> V_5 ) ;
F_92 ( & V_4 ) ;
return 0 ;
}
int F_100 ( struct V_107 * V_108 , void * V_109 ,
struct V_83 * V_84 )
{
struct V_125 * V_111 =
(struct V_125 * ) V_109 ;
return F_97 ( F_74 ( V_84 ) -> V_87 ,
V_111 -> V_104 ,
V_120 ) ;
}
static void F_101 ( struct V_43 * V_44 )
{
struct V_58 * V_126 =
F_2 ( V_44 , struct V_58 , V_44 ) ;
struct V_107 * V_108 = V_126 -> V_108 ;
struct V_127 * V_128 = V_126 -> V_128 ;
struct V_83 * V_84 ;
if ( F_38 ( V_128 == NULL ) )
return;
V_84 = V_128 -> V_84 ;
F_102 ( & V_108 -> V_129 ) ;
if ( F_15 ( V_126 -> V_130 != NULL ) ) {
struct V_131 V_132 ;
F_103 ( & V_132 ) ;
* V_126 -> V_130 = V_132 . V_130 ;
* V_126 -> V_133 = V_132 . V_133 ;
}
F_104 ( V_108 , V_126 -> V_128 ) ;
V_126 -> V_128 = NULL ;
F_105 ( & V_108 -> V_129 ) ;
}
static void F_106 ( struct V_43 * V_44 )
{
struct V_58 * V_126 =
F_2 ( V_44 , struct V_58 , V_44 ) ;
F_72 ( & V_126 -> V_3 ) ;
F_47 ( V_126 ) ;
}
static void F_107 ( struct V_2 * V_3 ,
struct V_43 * V_44 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
bool V_134 = false ;
F_31 ( & V_8 -> V_47 ) ;
F_4 ( & V_8 -> V_5 ) ;
V_8 -> V_65 [ V_44 -> type ] ++ ;
if ( F_56 ( & V_3 -> V_4 ) ) {
struct V_41 V_71 ;
F_30 ( & V_71 ) ;
F_50 ( & V_44 -> V_9 , & V_71 ) ;
F_51 ( V_8 , & V_71 ) ;
} else {
F_50 ( & V_44 -> V_9 , & V_3 -> V_62 ) ;
V_134 = F_55 ( V_3 ) ;
}
F_6 ( & V_8 -> V_5 ) ;
if ( V_134 ) {
if ( ! V_8 -> V_49 ) {
V_8 -> V_49 = true ;
F_108 ( V_8 -> V_13 ) ;
}
F_59 ( V_8 ) ;
}
F_34 ( & V_8 -> V_47 ) ;
}
int F_109 ( struct V_83 * V_84 ,
struct V_2 * V_3 ,
struct V_127 * V_128 ,
T_2 * V_130 ,
T_2 * V_133 ,
bool V_76 )
{
struct V_58 * V_126 ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
V_126 = F_37 ( sizeof( * V_126 ) , V_51 ) ;
if ( F_38 ( ! V_126 ) )
return - V_78 ;
V_126 -> V_128 = V_128 ;
V_126 -> V_44 . V_66 = F_101 ;
V_126 -> V_44 . V_50 = F_106 ;
V_126 -> V_44 . type = V_135 ;
V_126 -> V_3 = F_76 ( V_3 ) ;
V_126 -> V_108 = V_8 -> V_13 -> V_108 ;
V_126 -> V_130 = V_130 ;
V_126 -> V_133 = V_133 ;
F_107 ( V_3 , & V_126 -> V_44 ) ;
return 0 ;
}
static int F_110 ( struct V_83 * V_84 ,
struct V_2 * V_3 ,
T_2 V_35 ,
T_3 V_136 ,
bool V_76 )
{
struct V_137 * V_128 ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_107 * V_108 = V_8 -> V_13 -> V_108 ;
int V_26 ;
V_128 = F_37 ( sizeof( * V_128 ) , V_51 ) ;
if ( F_38 ( ! V_128 ) ) {
F_111 ( L_4 ) ;
V_26 = - V_78 ;
goto V_138;
}
V_128 -> V_128 . V_4 . type = V_139 ;
V_128 -> V_128 . V_4 . V_140 = sizeof( * V_128 ) ;
V_128 -> V_128 . V_136 = V_136 ;
V_26 = F_112 ( V_108 , V_84 , & V_128 -> V_4 , & V_128 -> V_128 . V_4 ) ;
if ( F_38 ( V_26 != 0 ) ) {
F_111 ( L_5 ) ;
F_47 ( V_128 ) ;
goto V_138;
}
if ( V_35 & V_141 )
V_26 = F_109 ( V_84 , V_3 ,
& V_128 -> V_4 ,
& V_128 -> V_128 . V_130 ,
& V_128 -> V_128 . V_133 ,
V_76 ) ;
else
V_26 = F_109 ( V_84 , V_3 ,
& V_128 -> V_4 ,
NULL ,
NULL ,
V_76 ) ;
if ( V_26 != 0 )
goto V_142;
return 0 ;
V_142:
F_113 ( V_108 , & V_128 -> V_4 ) ;
V_138:
return V_26 ;
}
int F_114 ( struct V_107 * V_108 , void * V_109 ,
struct V_83 * V_84 )
{
struct V_12 * V_13 = F_99 ( V_108 ) ;
struct V_143 * V_111 =
(struct V_143 * ) V_109 ;
struct V_2 * V_3 = NULL ;
struct F_74 * V_144 = F_74 ( V_84 ) ;
struct V_86 * V_87 = V_144 -> V_87 ;
struct V_145 T_4 * V_146 =
(struct V_145 T_4 * ) ( unsigned long )
V_111 -> V_147 ;
T_2 V_104 ;
int V_26 ;
if ( V_111 -> V_104 ) {
struct V_81 * V_4 =
F_88 ( V_87 , V_111 -> V_104 ) ;
if ( F_94 ( V_4 ) )
return F_95 ( V_4 ) ;
V_3 = & ( F_2 ( V_4 , struct V_55 ,
V_4 ) -> V_3 ) ;
( void ) F_76 ( V_3 ) ;
if ( V_146 != NULL ) {
V_26 = F_115 ( V_144 -> V_87 , V_4 ,
V_120 , NULL , false ) ;
if ( F_38 ( V_26 != 0 ) ) {
F_111 ( L_6
L_7 ) ;
goto V_148;
}
V_104 = V_4 -> V_94 . V_95 ;
}
F_92 ( & V_4 ) ;
}
if ( ! V_3 ) {
V_26 = F_116 ( V_84 , V_13 ,
& V_3 ,
( V_146 ) ?
& V_104 : NULL ) ;
if ( F_38 ( V_26 != 0 ) ) {
F_111 ( L_8 ) ;
return V_26 ;
}
}
F_46 ( V_3 == NULL ) ;
V_26 = F_110 ( V_84 , V_3 ,
V_111 -> V_35 ,
V_111 -> V_136 ,
true ) ;
if ( F_38 ( V_26 != 0 ) ) {
if ( V_26 != - V_29 )
F_111 ( L_9 ) ;
goto V_149;
}
F_117 ( V_13 , V_144 , 0 , V_146 , V_3 ,
V_104 , - 1 , NULL ) ;
F_72 ( & V_3 ) ;
return 0 ;
V_149:
if ( V_146 != NULL )
F_97 ( V_87 , V_104 , V_120 ) ;
V_148:
F_72 ( & V_3 ) ;
return V_26 ;
}
