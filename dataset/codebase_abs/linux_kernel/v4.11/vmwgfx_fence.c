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
unsigned long V_9 ;
F_4 ( & V_8 -> V_5 , V_9 ) ;
F_5 ( & V_3 -> V_10 ) ;
-- V_8 -> V_11 ;
F_6 ( & V_8 -> V_5 , V_9 ) ;
V_3 -> V_12 ( V_3 ) ;
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
struct V_13 * V_14 = V_8 -> V_14 ;
T_1 * V_15 = V_14 -> V_16 ;
T_1 V_17 = F_10 ( V_15 + V_18 ) ;
if ( V_17 - V_3 -> V_4 . V_17 < V_19 )
return false ;
F_11 ( V_14 , V_20 ) ;
return true ;
}
static void
F_12 ( struct V_6 * V_3 , struct V_21 * V_22 )
{
struct F_12 * V_23 =
F_2 ( V_22 , struct F_12 , V_4 ) ;
F_13 ( V_23 -> V_24 ) ;
}
static long F_14 ( struct V_6 * V_7 , bool V_25 , signed long V_26 )
{
struct V_2 * V_3 =
F_2 ( V_7 , struct V_2 , V_4 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_13 * V_14 = V_8 -> V_14 ;
struct F_12 V_22 ;
long V_27 = V_26 ;
unsigned long V_9 ;
if ( F_15 ( F_16 ( V_3 ) ) )
return V_26 ;
F_11 ( V_14 , V_20 ) ;
F_17 ( V_14 ) ;
F_4 ( V_7 -> V_5 , V_9 ) ;
if ( V_25 && F_18 ( V_28 ) ) {
V_27 = - V_29 ;
goto V_30;
}
V_22 . V_4 . V_31 = F_12 ;
V_22 . V_24 = V_28 ;
F_19 ( & V_22 . V_4 . V_32 , & V_7 -> V_33 ) ;
while ( V_27 > 0 ) {
F_20 ( V_8 ) ;
if ( F_21 ( V_34 , & V_7 -> V_35 ) )
break;
if ( V_25 )
F_22 ( V_36 ) ;
else
F_22 ( V_37 ) ;
F_6 ( V_7 -> V_5 , V_9 ) ;
V_27 = F_23 ( V_27 ) ;
F_4 ( V_7 -> V_5 , V_9 ) ;
if ( V_27 > 0 && V_25 && F_18 ( V_28 ) )
V_27 = - V_29 ;
}
if ( ! F_24 ( & V_22 . V_4 . V_32 ) )
F_25 ( & V_22 . V_4 . V_32 ) ;
F_22 ( V_38 ) ;
V_30:
F_6 ( V_7 -> V_5 , V_9 ) ;
F_26 ( V_14 ) ;
return V_27 ;
}
static void F_27 ( struct V_39 * V_40 )
{
struct V_1 * V_8 =
F_2 ( V_40 , struct V_1 , V_40 ) ;
struct V_41 V_42 ;
struct V_43 * V_44 , * V_45 ;
bool V_46 ;
do {
F_28 ( & V_42 ) ;
F_29 ( & V_8 -> V_47 ) ;
F_30 ( & V_8 -> V_5 ) ;
F_31 ( & V_8 -> V_48 , & V_42 ) ;
V_46 = V_8 -> V_46 ;
F_32 ( & V_8 -> V_5 ) ;
if ( ! V_46 && V_8 -> V_49 ) {
V_8 -> V_49 = false ;
F_33 ( V_8 -> V_14 ) ;
}
F_34 ( & V_8 -> V_47 ) ;
if ( F_24 ( & V_42 ) )
return;
F_35 (action, next_action, &list, head) {
F_5 ( & V_44 -> V_10 ) ;
if ( V_44 -> V_50 )
V_44 -> V_50 ( V_44 ) ;
}
} while ( 1 );
}
struct V_1 * F_36 ( struct V_13 * V_14 )
{
struct V_1 * V_8 = F_37 ( sizeof( * V_8 ) , V_51 ) ;
if ( F_38 ( V_8 == NULL ) )
return NULL ;
V_8 -> V_14 = V_14 ;
F_39 ( & V_8 -> V_5 ) ;
F_28 ( & V_8 -> V_52 ) ;
F_28 ( & V_8 -> V_48 ) ;
F_40 ( & V_8 -> V_40 , & F_27 ) ;
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
unsigned long V_9 ;
bool V_60 ;
( void ) F_45 ( & V_8 -> V_40 ) ;
F_4 ( & V_8 -> V_5 , V_9 ) ;
V_60 = F_24 ( & V_8 -> V_52 ) &&
F_24 ( & V_8 -> V_48 ) ;
F_6 ( & V_8 -> V_5 , V_9 ) ;
F_46 ( ! V_60 ) ;
F_47 ( V_8 ) ;
}
static int F_48 ( struct V_1 * V_8 ,
struct V_2 * V_3 , T_1 V_17 ,
void (* V_12) ( struct V_2 * V_3 ) )
{
unsigned long V_9 ;
int V_27 = 0 ;
F_49 ( & V_3 -> V_4 , & V_61 , & V_8 -> V_5 ,
V_8 -> V_59 , V_17 ) ;
F_28 ( & V_3 -> V_62 ) ;
V_3 -> V_12 = V_12 ;
F_4 ( & V_8 -> V_5 , V_9 ) ;
if ( F_38 ( V_8 -> V_53 ) ) {
V_27 = - V_63 ;
goto V_64;
}
F_50 ( & V_3 -> V_10 , & V_8 -> V_52 ) ;
++ V_8 -> V_11 ;
V_64:
F_6 ( & V_8 -> V_5 , V_9 ) ;
return V_27 ;
}
static void F_51 ( struct V_1 * V_8 ,
struct V_41 * V_42 )
{
struct V_43 * V_44 , * V_45 ;
F_35 (action, next_action, list, head) {
F_5 ( & V_44 -> V_10 ) ;
V_8 -> V_65 [ V_44 -> type ] -- ;
if ( V_44 -> V_66 != NULL )
V_44 -> V_66 ( V_44 ) ;
F_50 ( & V_44 -> V_10 , & V_8 -> V_48 ) ;
}
}
static bool F_52 ( struct V_1 * V_8 ,
T_1 V_67 )
{
T_1 V_68 ;
T_1 * V_15 ;
struct V_2 * V_3 ;
if ( F_15 ( ! V_8 -> V_46 ) )
return false ;
V_15 = V_8 -> V_14 -> V_16 ;
V_68 = F_10 ( V_15 + V_69 ) ;
if ( F_15 ( V_67 - V_68 >= V_19 ) )
return false ;
V_8 -> V_46 = false ;
F_53 (fence, &fman->fence_list, head) {
if ( ! F_24 ( & V_3 -> V_62 ) ) {
V_8 -> V_46 = true ;
F_54 ( V_3 -> V_4 . V_17 ,
V_15 + V_69 ) ;
break;
}
}
return true ;
}
static bool F_55 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
T_1 V_68 ;
T_1 * V_15 ;
if ( F_56 ( & V_3 -> V_4 ) )
return false ;
V_15 = V_8 -> V_14 -> V_16 ;
V_68 = F_10 ( V_15 + V_69 ) ;
if ( F_15 ( V_8 -> V_46 &&
V_68 - V_3 -> V_4 . V_17 < V_19 ) )
return false ;
F_54 ( V_3 -> V_4 . V_17 , V_15 + V_69 ) ;
V_8 -> V_46 = true ;
return true ;
}
static void F_20 ( struct V_1 * V_8 )
{
struct V_2 * V_3 , * V_70 ;
struct V_41 V_71 ;
bool V_72 ;
T_2 V_17 , V_73 ;
T_1 * V_15 = V_8 -> V_14 -> V_16 ;
V_17 = F_10 ( V_15 + V_18 ) ;
V_74:
F_35 (fence, next_fence, &fman->fence_list, head) {
if ( V_17 - V_3 -> V_4 . V_17 < V_19 ) {
F_5 ( & V_3 -> V_10 ) ;
F_57 ( & V_3 -> V_4 ) ;
F_28 ( & V_71 ) ;
F_31 ( & V_3 -> V_62 ,
& V_71 ) ;
F_51 ( V_8 , & V_71 ) ;
} else
break;
}
V_72 = F_52 ( V_8 , V_17 ) ;
if ( F_38 ( V_72 ) ) {
V_73 = F_10 ( V_15 + V_18 ) ;
if ( V_73 != V_17 ) {
V_17 = V_73 ;
goto V_74;
}
}
if ( ! F_24 ( & V_8 -> V_48 ) )
( void ) F_58 ( & V_8 -> V_40 ) ;
}
void F_59 ( struct V_1 * V_8 )
{
unsigned long V_9 ;
F_4 ( & V_8 -> V_5 , V_9 ) ;
F_20 ( V_8 ) ;
F_6 ( & V_8 -> V_5 , V_9 ) ;
}
bool F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
if ( F_21 ( V_34 , & V_3 -> V_4 . V_35 ) )
return 1 ;
F_59 ( V_8 ) ;
return F_60 ( & V_3 -> V_4 ) ;
}
int F_61 ( struct V_2 * V_3 , bool V_75 ,
bool V_76 , unsigned long V_26 )
{
long V_27 = F_62 ( & V_3 -> V_4 , V_76 , V_26 ) ;
if ( F_15 ( V_27 > 0 ) )
return 0 ;
else if ( V_27 == 0 )
return - V_63 ;
else
return V_27 ;
}
void F_63 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = F_1 ( V_3 ) -> V_14 ;
F_11 ( V_14 , V_20 ) ;
}
static void F_64 ( struct V_2 * V_3 )
{
F_65 ( & V_3 -> V_4 ) ;
}
int F_66 ( struct V_1 * V_8 ,
T_2 V_17 ,
struct V_2 * * V_77 )
{
struct V_2 * V_3 ;
int V_27 ;
V_3 = F_37 ( sizeof( * V_3 ) , V_51 ) ;
if ( F_38 ( V_3 == NULL ) )
return - V_78 ;
V_27 = F_48 ( V_8 , V_3 , V_17 ,
F_64 ) ;
if ( F_38 ( V_27 != 0 ) )
goto V_79;
* V_77 = V_3 ;
return 0 ;
V_79:
F_47 ( V_3 ) ;
return V_27 ;
}
static void F_67 ( struct V_2 * V_3 )
{
struct V_55 * V_80 =
F_2 ( V_3 , struct V_55 , V_3 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
F_68 ( V_80 , V_4 ) ;
F_69 ( F_70 ( V_8 -> V_14 ) ,
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
T_2 V_17 ,
struct V_2 * * V_77 ,
T_2 * V_85 )
{
struct V_86 * V_87 = F_74 ( V_84 ) -> V_87 ;
struct V_55 * V_80 ;
struct V_2 * V_88 ;
struct V_89 * V_90 = F_70 ( V_8 -> V_14 ) ;
int V_27 ;
V_27 = F_75 ( V_90 , V_8 -> V_54 ,
false , false ) ;
if ( F_38 ( V_27 != 0 ) )
return V_27 ;
V_80 = F_37 ( sizeof( * V_80 ) , V_51 ) ;
if ( F_38 ( V_80 == NULL ) ) {
V_27 = - V_78 ;
goto V_91;
}
V_27 = F_48 ( V_8 , & V_80 -> V_3 , V_17 ,
F_67 ) ;
if ( F_38 ( V_27 != 0 ) ) {
F_47 ( V_80 ) ;
goto V_91;
}
V_88 = F_76 ( & V_80 -> V_3 ) ;
V_27 = F_77 ( V_87 , & V_80 -> V_4 , false ,
V_92 ,
& F_71 , NULL ) ;
if ( F_38 ( V_27 != 0 ) ) {
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
return V_27 ;
}
void F_78 ( struct V_1 * V_8 )
{
struct V_41 V_71 ;
int V_27 ;
F_30 ( & V_8 -> V_5 ) ;
V_8 -> V_53 = true ;
while ( ! F_24 ( & V_8 -> V_52 ) ) {
struct V_2 * V_3 =
F_79 ( V_8 -> V_52 . V_96 , struct V_2 ,
V_10 ) ;
F_80 ( & V_3 -> V_4 ) ;
F_32 ( & V_8 -> V_5 ) ;
V_27 = F_61 ( V_3 , false , false ,
V_97 ) ;
if ( F_38 ( V_27 != 0 ) ) {
F_5 ( & V_3 -> V_10 ) ;
F_81 ( & V_3 -> V_4 ) ;
F_28 ( & V_71 ) ;
F_31 ( & V_3 -> V_62 ,
& V_71 ) ;
F_51 ( V_8 , & V_71 ) ;
}
F_46 ( ! F_24 ( & V_3 -> V_10 ) ) ;
F_82 ( & V_3 -> V_4 ) ;
F_30 ( & V_8 -> V_5 ) ;
}
F_32 ( & V_8 -> V_5 ) ;
}
void F_83 ( struct V_1 * V_8 )
{
unsigned long V_9 ;
F_4 ( & V_8 -> V_5 , V_9 ) ;
V_8 -> V_53 = false ;
F_6 ( & V_8 -> V_5 , V_9 ) ;
}
static struct V_81 *
F_84 ( struct V_86 * V_87 , T_1 V_98 )
{
struct V_81 * V_4 = F_85 ( V_87 , V_98 ) ;
if ( ! V_4 ) {
F_86 ( L_3 ,
( unsigned long ) V_98 ) ;
return F_87 ( - V_99 ) ;
}
if ( V_4 -> V_100 != F_71 ) {
F_86 ( L_3 ,
( unsigned long ) V_98 ) ;
F_88 ( & V_4 ) ;
return F_87 ( - V_99 ) ;
}
return V_4 ;
}
int F_89 ( struct V_101 * V_102 , void * V_103 ,
struct V_83 * V_84 )
{
struct V_104 * V_105 =
(struct V_104 * ) V_103 ;
unsigned long V_26 ;
struct V_81 * V_4 ;
struct V_2 * V_3 ;
struct V_86 * V_87 = F_74 ( V_84 ) -> V_87 ;
int V_27 ;
T_3 V_106 = ( ( T_3 ) V_105 -> V_107 * V_108 ) ;
V_106 = ( V_106 >> 20 ) + ( V_106 >> 24 ) -
( V_106 >> 26 ) ;
if ( ! V_105 -> V_109 ) {
V_105 -> V_109 = 1 ;
V_105 -> V_110 = V_111 + V_106 ;
}
V_4 = F_84 ( V_87 , V_105 -> V_98 ) ;
if ( F_90 ( V_4 ) )
return F_91 ( V_4 ) ;
V_3 = & ( F_2 ( V_4 , struct V_55 , V_4 ) -> V_3 ) ;
V_26 = V_111 ;
if ( F_92 ( V_26 , ( unsigned long ) V_105 -> V_110 ) ) {
V_27 = ( ( F_16 ( V_3 ) ) ?
0 : - V_63 ) ;
goto V_30;
}
V_26 = ( unsigned long ) V_105 -> V_110 - V_26 ;
V_27 = F_61 ( V_3 , V_105 -> V_75 , true , V_26 ) ;
V_30:
F_88 ( & V_4 ) ;
if ( V_27 == 0 && ( V_105 -> V_112 & V_113 ) )
return F_93 ( V_87 , V_105 -> V_98 ,
V_114 ) ;
return V_27 ;
}
int F_94 ( struct V_101 * V_102 , void * V_103 ,
struct V_83 * V_84 )
{
struct V_115 * V_105 =
(struct V_115 * ) V_103 ;
struct V_81 * V_4 ;
struct V_2 * V_3 ;
struct V_1 * V_8 ;
struct V_86 * V_87 = F_74 ( V_84 ) -> V_87 ;
struct V_13 * V_14 = F_95 ( V_102 ) ;
V_4 = F_84 ( V_87 , V_105 -> V_98 ) ;
if ( F_90 ( V_4 ) )
return F_91 ( V_4 ) ;
V_3 = & ( F_2 ( V_4 , struct V_55 , V_4 ) -> V_3 ) ;
V_8 = F_1 ( V_3 ) ;
V_105 -> V_116 = F_16 ( V_3 ) ;
V_105 -> V_117 = V_105 -> V_35 ;
F_30 ( & V_8 -> V_5 ) ;
V_105 -> V_67 = V_14 -> V_118 ;
F_32 ( & V_8 -> V_5 ) ;
F_88 ( & V_4 ) ;
return 0 ;
}
int F_96 ( struct V_101 * V_102 , void * V_103 ,
struct V_83 * V_84 )
{
struct V_119 * V_105 =
(struct V_119 * ) V_103 ;
return F_93 ( F_74 ( V_84 ) -> V_87 ,
V_105 -> V_98 ,
V_114 ) ;
}
static void F_97 ( struct V_43 * V_44 )
{
struct V_58 * V_120 =
F_2 ( V_44 , struct V_58 , V_44 ) ;
struct V_101 * V_102 = V_120 -> V_102 ;
struct V_121 * V_122 = V_120 -> V_122 ;
struct V_83 * V_84 ;
unsigned long V_9 ;
if ( F_38 ( V_122 == NULL ) )
return;
V_84 = V_122 -> V_84 ;
F_4 ( & V_102 -> V_123 , V_9 ) ;
if ( F_15 ( V_120 -> V_124 != NULL ) ) {
struct V_125 V_126 ;
F_98 ( & V_126 ) ;
* V_120 -> V_124 = V_126 . V_124 ;
* V_120 -> V_127 = V_126 . V_127 ;
}
F_99 ( V_102 , V_120 -> V_122 ) ;
V_120 -> V_122 = NULL ;
F_6 ( & V_102 -> V_123 , V_9 ) ;
}
static void F_100 ( struct V_43 * V_44 )
{
struct V_58 * V_120 =
F_2 ( V_44 , struct V_58 , V_44 ) ;
F_72 ( & V_120 -> V_3 ) ;
F_47 ( V_120 ) ;
}
static void F_101 ( struct V_2 * V_3 ,
struct V_43 * V_44 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
unsigned long V_9 ;
bool V_128 = false ;
F_29 ( & V_8 -> V_47 ) ;
F_4 ( & V_8 -> V_5 , V_9 ) ;
V_8 -> V_65 [ V_44 -> type ] ++ ;
if ( F_56 ( & V_3 -> V_4 ) ) {
struct V_41 V_71 ;
F_28 ( & V_71 ) ;
F_50 ( & V_44 -> V_10 , & V_71 ) ;
F_51 ( V_8 , & V_71 ) ;
} else {
F_50 ( & V_44 -> V_10 , & V_3 -> V_62 ) ;
V_128 = F_55 ( V_3 ) ;
}
F_6 ( & V_8 -> V_5 , V_9 ) ;
if ( V_128 ) {
if ( ! V_8 -> V_49 ) {
V_8 -> V_49 = true ;
F_102 ( V_8 -> V_14 ) ;
}
F_59 ( V_8 ) ;
}
F_34 ( & V_8 -> V_47 ) ;
}
int F_103 ( struct V_83 * V_84 ,
struct V_2 * V_3 ,
struct V_121 * V_122 ,
T_2 * V_124 ,
T_2 * V_127 ,
bool V_76 )
{
struct V_58 * V_120 ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
V_120 = F_37 ( sizeof( * V_120 ) , V_51 ) ;
if ( F_38 ( V_120 == NULL ) )
return - V_78 ;
V_120 -> V_122 = V_122 ;
V_120 -> V_44 . V_66 = F_97 ;
V_120 -> V_44 . V_50 = F_100 ;
V_120 -> V_44 . type = V_129 ;
V_120 -> V_3 = F_76 ( V_3 ) ;
V_120 -> V_102 = V_8 -> V_14 -> V_102 ;
V_120 -> V_124 = V_124 ;
V_120 -> V_127 = V_127 ;
F_101 ( V_3 , & V_120 -> V_44 ) ;
return 0 ;
}
static int F_104 ( struct V_83 * V_84 ,
struct V_2 * V_3 ,
T_2 V_35 ,
T_3 V_130 ,
bool V_76 )
{
struct V_131 * V_122 ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_101 * V_102 = V_8 -> V_14 -> V_102 ;
int V_27 ;
V_122 = F_37 ( sizeof( * V_122 ) , V_51 ) ;
if ( F_38 ( V_122 == NULL ) ) {
F_105 ( L_4 ) ;
V_27 = - V_78 ;
goto V_132;
}
V_122 -> V_122 . V_4 . type = V_133 ;
V_122 -> V_122 . V_4 . V_134 = sizeof( * V_122 ) ;
V_122 -> V_122 . V_130 = V_130 ;
V_27 = F_106 ( V_102 , V_84 , & V_122 -> V_4 , & V_122 -> V_122 . V_4 ) ;
if ( F_38 ( V_27 != 0 ) ) {
F_105 ( L_5 ) ;
F_47 ( V_122 ) ;
goto V_132;
}
if ( V_35 & V_135 )
V_27 = F_103 ( V_84 , V_3 ,
& V_122 -> V_4 ,
& V_122 -> V_122 . V_124 ,
& V_122 -> V_122 . V_127 ,
V_76 ) ;
else
V_27 = F_103 ( V_84 , V_3 ,
& V_122 -> V_4 ,
NULL ,
NULL ,
V_76 ) ;
if ( V_27 != 0 )
goto V_136;
return 0 ;
V_136:
F_107 ( V_102 , & V_122 -> V_4 ) ;
V_132:
return V_27 ;
}
int F_108 ( struct V_101 * V_102 , void * V_103 ,
struct V_83 * V_84 )
{
struct V_13 * V_14 = F_95 ( V_102 ) ;
struct V_137 * V_105 =
(struct V_137 * ) V_103 ;
struct V_2 * V_3 = NULL ;
struct F_74 * V_138 = F_74 ( V_84 ) ;
struct V_86 * V_87 = V_138 -> V_87 ;
struct V_139 T_4 * V_140 =
(struct V_139 T_4 * ) ( unsigned long )
V_105 -> V_141 ;
T_2 V_98 ;
int V_27 ;
if ( V_105 -> V_98 ) {
struct V_81 * V_4 =
F_84 ( V_87 , V_105 -> V_98 ) ;
if ( F_90 ( V_4 ) )
return F_91 ( V_4 ) ;
V_3 = & ( F_2 ( V_4 , struct V_55 ,
V_4 ) -> V_3 ) ;
( void ) F_76 ( V_3 ) ;
if ( V_140 != NULL ) {
V_27 = F_109 ( V_138 -> V_87 , V_4 ,
V_114 , NULL , false ) ;
if ( F_38 ( V_27 != 0 ) ) {
F_105 ( L_6
L_7 ) ;
goto V_142;
}
V_98 = V_4 -> V_94 . V_95 ;
}
F_88 ( & V_4 ) ;
}
if ( ! V_3 ) {
V_27 = F_110 ( V_84 , V_14 ,
& V_3 ,
( V_140 ) ?
& V_98 : NULL ) ;
if ( F_38 ( V_27 != 0 ) ) {
F_105 ( L_8 ) ;
return V_27 ;
}
}
F_46 ( V_3 == NULL ) ;
V_27 = F_104 ( V_84 , V_3 ,
V_105 -> V_35 ,
V_105 -> V_130 ,
true ) ;
if ( F_38 ( V_27 != 0 ) ) {
if ( V_27 != - V_29 )
F_105 ( L_9 ) ;
goto V_143;
}
F_111 ( V_14 , V_138 , 0 , V_140 , V_3 ,
V_98 ) ;
F_72 ( & V_3 ) ;
return 0 ;
V_143:
if ( V_140 != NULL )
F_93 ( V_87 , V_98 , V_114 ) ;
V_142:
F_72 ( & V_3 ) ;
return V_27 ;
}
