static struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 . V_5 , struct V_1 , V_5 ) ;
}
static void F_3 ( struct V_3 * V_6 )
{
struct V_2 * V_3 =
F_2 ( V_6 , struct V_2 , V_4 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned long V_8 ;
F_4 ( & V_7 -> V_5 , V_8 ) ;
F_5 ( & V_3 -> V_9 ) ;
-- V_7 -> V_10 ;
F_6 ( & V_7 -> V_5 , V_8 ) ;
V_3 -> V_11 ( V_3 ) ;
}
static const char * F_7 ( struct V_3 * V_6 )
{
return L_1 ;
}
static const char * F_8 ( struct V_3 * V_6 )
{
return L_2 ;
}
static bool F_9 ( struct V_3 * V_6 )
{
struct V_2 * V_3 =
F_2 ( V_6 , struct V_2 , V_4 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_12 * V_13 = V_7 -> V_13 ;
T_1 T_2 * V_14 = V_13 -> V_15 ;
T_1 V_16 = F_10 ( V_14 + V_17 ) ;
if ( V_16 - V_3 -> V_4 . V_16 < V_18 )
return false ;
F_11 ( V_13 , V_19 ) ;
return true ;
}
static void
F_12 ( struct V_3 * V_3 , struct V_20 * V_21 )
{
struct F_12 * V_22 =
F_2 ( V_21 , struct F_12 , V_4 ) ;
F_13 ( V_22 -> V_23 ) ;
}
static long F_14 ( struct V_3 * V_6 , bool V_24 , signed long V_25 )
{
struct V_2 * V_3 =
F_2 ( V_6 , struct V_2 , V_4 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_12 * V_13 = V_7 -> V_13 ;
struct F_12 V_21 ;
long V_26 = V_25 ;
unsigned long V_8 ;
if ( F_15 ( F_16 ( V_3 ) ) )
return V_25 ;
F_11 ( V_13 , V_19 ) ;
F_17 ( V_13 ) ;
F_4 ( V_6 -> V_5 , V_8 ) ;
if ( V_24 && F_18 ( V_27 ) ) {
V_26 = - V_28 ;
goto V_29;
}
V_21 . V_4 . V_30 = F_12 ;
V_21 . V_23 = V_27 ;
F_19 ( & V_21 . V_4 . V_31 , & V_6 -> V_32 ) ;
while ( V_26 > 0 ) {
F_20 ( V_7 ) ;
if ( F_21 ( V_33 , & V_6 -> V_34 ) )
break;
if ( V_24 )
F_22 ( V_35 ) ;
else
F_22 ( V_36 ) ;
F_6 ( V_6 -> V_5 , V_8 ) ;
V_26 = F_23 ( V_26 ) ;
F_4 ( V_6 -> V_5 , V_8 ) ;
if ( V_26 > 0 && V_24 && F_18 ( V_27 ) )
V_26 = - V_28 ;
}
if ( ! F_24 ( & V_21 . V_4 . V_31 ) )
F_25 ( & V_21 . V_4 . V_31 ) ;
F_22 ( V_37 ) ;
V_29:
F_6 ( V_6 -> V_5 , V_8 ) ;
F_26 ( V_13 ) ;
return V_26 ;
}
static void F_27 ( struct V_38 * V_39 )
{
struct V_1 * V_7 =
F_2 ( V_39 , struct V_1 , V_39 ) ;
struct V_40 V_41 ;
struct V_42 * V_43 , * V_44 ;
bool V_45 ;
do {
F_28 ( & V_41 ) ;
F_29 ( & V_7 -> V_46 ) ;
F_30 ( & V_7 -> V_5 ) ;
F_31 ( & V_7 -> V_47 , & V_41 ) ;
V_45 = V_7 -> V_45 ;
F_32 ( & V_7 -> V_5 ) ;
if ( ! V_45 && V_7 -> V_48 ) {
V_7 -> V_48 = false ;
F_33 ( V_7 -> V_13 ) ;
}
F_34 ( & V_7 -> V_46 ) ;
if ( F_24 ( & V_41 ) )
return;
F_35 (action, next_action, &list, head) {
F_5 ( & V_43 -> V_9 ) ;
if ( V_43 -> V_49 )
V_43 -> V_49 ( V_43 ) ;
}
} while ( 1 );
}
struct V_1 * F_36 ( struct V_12 * V_13 )
{
struct V_1 * V_7 = F_37 ( sizeof( * V_7 ) , V_50 ) ;
if ( F_38 ( V_7 == NULL ) )
return NULL ;
V_7 -> V_13 = V_13 ;
F_39 ( & V_7 -> V_5 ) ;
F_28 ( & V_7 -> V_51 ) ;
F_28 ( & V_7 -> V_47 ) ;
F_40 ( & V_7 -> V_39 , & F_27 ) ;
V_7 -> V_52 = true ;
V_7 -> V_53 = F_41 ( sizeof( struct V_54 ) ) ;
V_7 -> V_55 = F_41 ( sizeof( struct V_2 ) ) ;
V_7 -> V_56 =
F_41 ( sizeof( struct V_57 ) ) ;
F_42 ( & V_7 -> V_46 ) ;
V_7 -> V_58 = F_43 ( 1 ) ;
return V_7 ;
}
void F_44 ( struct V_1 * V_7 )
{
unsigned long V_8 ;
bool V_59 ;
( void ) F_45 ( & V_7 -> V_39 ) ;
F_4 ( & V_7 -> V_5 , V_8 ) ;
V_59 = F_24 ( & V_7 -> V_51 ) &&
F_24 ( & V_7 -> V_47 ) ;
F_6 ( & V_7 -> V_5 , V_8 ) ;
F_46 ( ! V_59 ) ;
F_47 ( V_7 ) ;
}
static int F_48 ( struct V_1 * V_7 ,
struct V_2 * V_3 , T_1 V_16 ,
void (* V_11) ( struct V_2 * V_3 ) )
{
unsigned long V_8 ;
int V_26 = 0 ;
F_49 ( & V_3 -> V_4 , & V_60 , & V_7 -> V_5 ,
V_7 -> V_58 , V_16 ) ;
F_28 ( & V_3 -> V_61 ) ;
V_3 -> V_11 = V_11 ;
F_4 ( & V_7 -> V_5 , V_8 ) ;
if ( F_38 ( V_7 -> V_52 ) ) {
V_26 = - V_62 ;
goto V_63;
}
F_50 ( & V_3 -> V_9 , & V_7 -> V_51 ) ;
++ V_7 -> V_10 ;
V_63:
F_6 ( & V_7 -> V_5 , V_8 ) ;
return V_26 ;
}
static void F_51 ( struct V_1 * V_7 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 , * V_44 ;
F_35 (action, next_action, list, head) {
F_5 ( & V_43 -> V_9 ) ;
V_7 -> V_64 [ V_43 -> type ] -- ;
if ( V_43 -> V_65 != NULL )
V_43 -> V_65 ( V_43 ) ;
F_50 ( & V_43 -> V_9 , & V_7 -> V_47 ) ;
}
}
static bool F_52 ( struct V_1 * V_7 ,
T_1 V_66 )
{
T_1 V_67 ;
T_1 T_2 * V_14 ;
struct V_2 * V_3 ;
if ( F_15 ( ! V_7 -> V_45 ) )
return false ;
V_14 = V_7 -> V_13 -> V_15 ;
V_67 = F_10 ( V_14 + V_68 ) ;
if ( F_15 ( V_66 - V_67 >= V_18 ) )
return false ;
V_7 -> V_45 = false ;
F_53 (fence, &fman->fence_list, head) {
if ( ! F_24 ( & V_3 -> V_61 ) ) {
V_7 -> V_45 = true ;
F_54 ( V_3 -> V_4 . V_16 ,
V_14 + V_68 ) ;
break;
}
}
return true ;
}
static bool F_55 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_1 V_67 ;
T_1 T_2 * V_14 ;
if ( F_56 ( & V_3 -> V_4 ) )
return false ;
V_14 = V_7 -> V_13 -> V_15 ;
V_67 = F_10 ( V_14 + V_68 ) ;
if ( F_15 ( V_7 -> V_45 &&
V_67 - V_3 -> V_4 . V_16 < V_18 ) )
return false ;
F_54 ( V_3 -> V_4 . V_16 , V_14 + V_68 ) ;
V_7 -> V_45 = true ;
return true ;
}
static void F_20 ( struct V_1 * V_7 )
{
struct V_2 * V_3 , * V_69 ;
struct V_40 V_70 ;
bool V_71 ;
T_3 V_16 , V_72 ;
T_1 T_2 * V_14 = V_7 -> V_13 -> V_15 ;
V_16 = F_10 ( V_14 + V_17 ) ;
V_73:
F_35 (fence, next_fence, &fman->fence_list, head) {
if ( V_16 - V_3 -> V_4 . V_16 < V_18 ) {
F_5 ( & V_3 -> V_9 ) ;
F_57 ( & V_3 -> V_4 ) ;
F_28 ( & V_70 ) ;
F_31 ( & V_3 -> V_61 ,
& V_70 ) ;
F_51 ( V_7 , & V_70 ) ;
} else
break;
}
V_71 = F_52 ( V_7 , V_16 ) ;
if ( F_38 ( V_71 ) ) {
V_72 = F_10 ( V_14 + V_17 ) ;
if ( V_72 != V_16 ) {
V_16 = V_72 ;
goto V_73;
}
}
if ( ! F_24 ( & V_7 -> V_47 ) )
( void ) F_58 ( & V_7 -> V_39 ) ;
}
void F_59 ( struct V_1 * V_7 )
{
unsigned long V_8 ;
F_4 ( & V_7 -> V_5 , V_8 ) ;
F_20 ( V_7 ) ;
F_6 ( & V_7 -> V_5 , V_8 ) ;
}
bool F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
if ( F_21 ( V_33 , & V_3 -> V_4 . V_34 ) )
return 1 ;
F_59 ( V_7 ) ;
return F_60 ( & V_3 -> V_4 ) ;
}
int F_61 ( struct V_2 * V_3 , bool V_74 ,
bool V_75 , unsigned long V_25 )
{
long V_26 = F_62 ( & V_3 -> V_4 , V_75 , V_25 ) ;
if ( F_15 ( V_26 > 0 ) )
return 0 ;
else if ( V_26 == 0 )
return - V_62 ;
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
int F_66 ( struct V_1 * V_7 ,
T_3 V_16 ,
struct V_2 * * V_76 )
{
struct V_2 * V_3 ;
int V_26 ;
V_3 = F_37 ( sizeof( * V_3 ) , V_50 ) ;
if ( F_38 ( V_3 == NULL ) )
return - V_77 ;
V_26 = F_48 ( V_7 , V_3 , V_16 ,
F_64 ) ;
if ( F_38 ( V_26 != 0 ) )
goto V_78;
* V_76 = V_3 ;
return 0 ;
V_78:
F_47 ( V_3 ) ;
return V_26 ;
}
static void F_67 ( struct V_2 * V_3 )
{
struct V_54 * V_79 =
F_2 ( V_3 , struct V_54 , V_3 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_68 ( V_79 , V_4 ) ;
F_69 ( F_70 ( V_7 -> V_13 ) ,
V_7 -> V_53 ) ;
}
static void F_71 ( struct V_80 * * V_81 )
{
struct V_80 * V_4 = * V_81 ;
struct V_54 * V_79 =
F_2 ( V_4 , struct V_54 , V_4 ) ;
struct V_2 * V_3 = & V_79 -> V_3 ;
* V_81 = NULL ;
F_72 ( & V_3 ) ;
}
int F_73 ( struct V_82 * V_83 ,
struct V_1 * V_7 ,
T_3 V_16 ,
struct V_2 * * V_76 ,
T_3 * V_84 )
{
struct V_85 * V_86 = F_74 ( V_83 ) -> V_86 ;
struct V_54 * V_79 ;
struct V_2 * V_87 ;
struct V_88 * V_89 = F_70 ( V_7 -> V_13 ) ;
int V_26 ;
V_26 = F_75 ( V_89 , V_7 -> V_53 ,
false , false ) ;
if ( F_38 ( V_26 != 0 ) )
return V_26 ;
V_79 = F_37 ( sizeof( * V_79 ) , V_50 ) ;
if ( F_38 ( V_79 == NULL ) ) {
V_26 = - V_77 ;
goto V_90;
}
V_26 = F_48 ( V_7 , & V_79 -> V_3 , V_16 ,
F_67 ) ;
if ( F_38 ( V_26 != 0 ) ) {
F_47 ( V_79 ) ;
goto V_90;
}
V_87 = F_76 ( & V_79 -> V_3 ) ;
V_26 = F_77 ( V_86 , & V_79 -> V_4 , false ,
V_91 ,
& F_71 , NULL ) ;
if ( F_38 ( V_26 != 0 ) ) {
F_72 ( & V_87 ) ;
goto V_92;
}
* V_76 = & V_79 -> V_3 ;
* V_84 = V_79 -> V_4 . V_93 . V_94 ;
return 0 ;
V_92:
V_87 = & V_79 -> V_3 ;
F_72 ( & V_87 ) ;
V_90:
F_69 ( V_89 , V_7 -> V_53 ) ;
return V_26 ;
}
void F_78 ( struct V_1 * V_7 )
{
struct V_40 V_70 ;
int V_26 ;
F_30 ( & V_7 -> V_5 ) ;
V_7 -> V_52 = true ;
while ( ! F_24 ( & V_7 -> V_51 ) ) {
struct V_2 * V_3 =
F_79 ( V_7 -> V_51 . V_95 , struct V_2 ,
V_9 ) ;
F_80 ( & V_3 -> V_4 ) ;
F_32 ( & V_7 -> V_5 ) ;
V_26 = F_61 ( V_3 , false , false ,
V_96 ) ;
if ( F_38 ( V_26 != 0 ) ) {
F_5 ( & V_3 -> V_9 ) ;
F_81 ( & V_3 -> V_4 ) ;
F_28 ( & V_70 ) ;
F_31 ( & V_3 -> V_61 ,
& V_70 ) ;
F_51 ( V_7 , & V_70 ) ;
}
F_46 ( ! F_24 ( & V_3 -> V_9 ) ) ;
F_82 ( & V_3 -> V_4 ) ;
F_30 ( & V_7 -> V_5 ) ;
}
F_32 ( & V_7 -> V_5 ) ;
}
void F_83 ( struct V_1 * V_7 )
{
unsigned long V_8 ;
F_4 ( & V_7 -> V_5 , V_8 ) ;
V_7 -> V_52 = false ;
F_6 ( & V_7 -> V_5 , V_8 ) ;
}
int F_84 ( struct V_97 * V_98 , void * V_99 ,
struct V_82 * V_83 )
{
struct V_100 * V_101 =
(struct V_100 * ) V_99 ;
unsigned long V_25 ;
struct V_80 * V_4 ;
struct V_2 * V_3 ;
struct V_85 * V_86 = F_74 ( V_83 ) -> V_86 ;
int V_26 ;
T_4 V_102 = ( ( T_4 ) V_101 -> V_103 * V_104 ) ;
V_102 = ( V_102 >> 20 ) + ( V_102 >> 24 ) -
( V_102 >> 26 ) ;
if ( ! V_101 -> V_105 ) {
V_101 -> V_105 = 1 ;
V_101 -> V_106 = V_107 + V_102 ;
}
V_4 = F_85 ( V_86 , V_101 -> V_108 ) ;
if ( F_38 ( V_4 == NULL ) ) {
F_86 ( V_109 L_3
L_4 ,
( unsigned long ) V_101 -> V_108 ) ;
return - V_110 ;
}
V_3 = & ( F_2 ( V_4 , struct V_54 , V_4 ) -> V_3 ) ;
V_25 = V_107 ;
if ( F_87 ( V_25 , ( unsigned long ) V_101 -> V_106 ) ) {
V_26 = ( ( F_16 ( V_3 ) ) ?
0 : - V_62 ) ;
goto V_29;
}
V_25 = ( unsigned long ) V_101 -> V_106 - V_25 ;
V_26 = F_61 ( V_3 , V_101 -> V_74 , true , V_25 ) ;
V_29:
F_88 ( & V_4 ) ;
if ( V_26 == 0 && ( V_101 -> V_111 & V_112 ) )
return F_89 ( V_86 , V_101 -> V_108 ,
V_113 ) ;
return V_26 ;
}
int F_90 ( struct V_97 * V_98 , void * V_99 ,
struct V_82 * V_83 )
{
struct V_114 * V_101 =
(struct V_114 * ) V_99 ;
struct V_80 * V_4 ;
struct V_2 * V_3 ;
struct V_1 * V_7 ;
struct V_85 * V_86 = F_74 ( V_83 ) -> V_86 ;
struct V_12 * V_13 = F_91 ( V_98 ) ;
V_4 = F_85 ( V_86 , V_101 -> V_108 ) ;
if ( F_38 ( V_4 == NULL ) ) {
F_86 ( V_109 L_5
L_4 ,
( unsigned long ) V_101 -> V_108 ) ;
return - V_110 ;
}
V_3 = & ( F_2 ( V_4 , struct V_54 , V_4 ) -> V_3 ) ;
V_7 = F_1 ( V_3 ) ;
V_101 -> V_115 = F_16 ( V_3 ) ;
V_101 -> V_116 = V_101 -> V_34 ;
F_30 ( & V_7 -> V_5 ) ;
V_101 -> V_66 = V_13 -> V_117 ;
F_32 ( & V_7 -> V_5 ) ;
F_88 ( & V_4 ) ;
return 0 ;
}
int F_92 ( struct V_97 * V_98 , void * V_99 ,
struct V_82 * V_83 )
{
struct V_118 * V_101 =
(struct V_118 * ) V_99 ;
return F_89 ( F_74 ( V_83 ) -> V_86 ,
V_101 -> V_108 ,
V_113 ) ;
}
void F_93 ( struct V_1 * V_7 ,
struct V_40 * V_119 )
{
struct V_57 * V_120 ;
struct V_121 * V_122 ;
unsigned long V_8 ;
while ( 1 ) {
F_4 ( & V_7 -> V_5 , V_8 ) ;
if ( F_24 ( V_119 ) )
goto V_63;
V_120 = F_94 ( V_119 ,
struct V_57 ,
V_123 ) ;
F_5 ( & V_120 -> V_123 ) ;
V_122 = V_120 -> V_122 ;
V_120 -> V_122 = NULL ;
F_6 ( & V_7 -> V_5 , V_8 ) ;
V_122 -> V_11 ( V_122 ) ;
}
V_63:
F_6 ( & V_7 -> V_5 , V_8 ) ;
}
static void F_95 ( struct V_42 * V_43 )
{
struct V_57 * V_120 =
F_2 ( V_43 , struct V_57 , V_43 ) ;
struct V_97 * V_98 = V_120 -> V_98 ;
struct V_121 * V_122 = V_120 -> V_122 ;
struct V_82 * V_83 ;
unsigned long V_8 ;
if ( F_38 ( V_122 == NULL ) )
return;
V_83 = V_122 -> V_83 ;
F_4 ( & V_98 -> V_124 , V_8 ) ;
if ( F_15 ( V_120 -> V_125 != NULL ) ) {
struct V_126 V_127 ;
F_96 ( & V_127 ) ;
* V_120 -> V_125 = V_127 . V_125 ;
* V_120 -> V_128 = V_127 . V_128 ;
}
F_5 ( & V_120 -> V_123 ) ;
F_50 ( & V_120 -> V_122 -> V_129 , & V_83 -> V_119 ) ;
V_120 -> V_122 = NULL ;
F_97 ( & V_83 -> V_130 ) ;
F_6 ( & V_98 -> V_124 , V_8 ) ;
}
static void F_98 ( struct V_42 * V_43 )
{
struct V_57 * V_120 =
F_2 ( V_43 , struct V_57 , V_43 ) ;
struct V_1 * V_7 = F_1 ( V_120 -> V_3 ) ;
unsigned long V_8 ;
F_4 ( & V_7 -> V_5 , V_8 ) ;
F_25 ( & V_120 -> V_123 ) ;
F_6 ( & V_7 -> V_5 , V_8 ) ;
F_72 ( & V_120 -> V_3 ) ;
F_47 ( V_120 ) ;
}
static void F_99 ( struct V_2 * V_3 ,
struct V_42 * V_43 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned long V_8 ;
bool V_131 = false ;
F_29 ( & V_7 -> V_46 ) ;
F_4 ( & V_7 -> V_5 , V_8 ) ;
V_7 -> V_64 [ V_43 -> type ] ++ ;
if ( F_56 ( & V_3 -> V_4 ) ) {
struct V_40 V_70 ;
F_28 ( & V_70 ) ;
F_50 ( & V_43 -> V_9 , & V_70 ) ;
F_51 ( V_7 , & V_70 ) ;
} else {
F_50 ( & V_43 -> V_9 , & V_3 -> V_61 ) ;
V_131 = F_55 ( V_3 ) ;
}
F_6 ( & V_7 -> V_5 , V_8 ) ;
if ( V_131 ) {
if ( ! V_7 -> V_48 ) {
V_7 -> V_48 = true ;
F_100 ( V_7 -> V_13 ) ;
}
F_59 ( V_7 ) ;
}
F_34 ( & V_7 -> V_46 ) ;
}
int F_101 ( struct V_82 * V_83 ,
struct V_2 * V_3 ,
struct V_121 * V_122 ,
T_3 * V_125 ,
T_3 * V_128 ,
bool V_75 )
{
struct V_57 * V_120 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct F_74 * V_132 = F_74 ( V_83 ) ;
unsigned long V_8 ;
V_120 = F_37 ( sizeof( * V_120 ) , V_50 ) ;
if ( F_38 ( V_120 == NULL ) )
return - V_77 ;
V_120 -> V_122 = V_122 ;
V_120 -> V_43 . V_65 = F_95 ;
V_120 -> V_43 . V_49 = F_98 ;
V_120 -> V_43 . type = V_133 ;
V_120 -> V_3 = F_76 ( V_3 ) ;
V_120 -> V_98 = V_7 -> V_13 -> V_98 ;
V_120 -> V_125 = V_125 ;
V_120 -> V_128 = V_128 ;
F_4 ( & V_7 -> V_5 , V_8 ) ;
F_50 ( & V_120 -> V_123 , & V_132 -> V_134 ) ;
F_6 ( & V_7 -> V_5 , V_8 ) ;
F_99 ( V_3 , & V_120 -> V_43 ) ;
return 0 ;
}
static int F_102 ( struct V_82 * V_83 ,
struct V_2 * V_3 ,
T_3 V_34 ,
T_4 V_135 ,
bool V_75 )
{
struct V_136 * V_122 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_97 * V_98 = V_7 -> V_13 -> V_98 ;
unsigned long V_8 ;
int V_26 ;
F_4 ( & V_98 -> V_124 , V_8 ) ;
V_26 = ( V_83 -> V_137 < sizeof( V_122 -> V_122 ) ) ? - V_62 : 0 ;
if ( F_15 ( V_26 == 0 ) )
V_83 -> V_137 -= sizeof( V_122 -> V_122 ) ;
F_6 ( & V_98 -> V_124 , V_8 ) ;
if ( F_38 ( V_26 != 0 ) ) {
F_103 ( L_6 ) ;
goto V_138;
}
V_122 = F_37 ( sizeof( * V_122 ) , V_50 ) ;
if ( F_38 ( V_122 == NULL ) ) {
F_103 ( L_7 ) ;
V_26 = - V_77 ;
goto V_139;
}
V_122 -> V_122 . V_4 . type = V_140 ;
V_122 -> V_122 . V_4 . V_141 = sizeof( * V_122 ) ;
V_122 -> V_122 . V_135 = V_135 ;
V_122 -> V_4 . V_122 = & V_122 -> V_122 . V_4 ;
V_122 -> V_4 . V_83 = V_83 ;
V_122 -> V_4 . V_11 = ( void ( * ) ( struct V_121 * ) ) F_47 ;
if ( V_34 & V_142 )
V_26 = F_101 ( V_83 , V_3 ,
& V_122 -> V_4 ,
& V_122 -> V_122 . V_125 ,
& V_122 -> V_122 . V_128 ,
V_75 ) ;
else
V_26 = F_101 ( V_83 , V_3 ,
& V_122 -> V_4 ,
NULL ,
NULL ,
V_75 ) ;
if ( V_26 != 0 )
goto V_143;
return 0 ;
V_143:
V_122 -> V_4 . V_11 ( & V_122 -> V_4 ) ;
V_139:
F_4 ( & V_98 -> V_124 , V_8 ) ;
V_83 -> V_137 += sizeof( * V_122 ) ;
F_6 ( & V_98 -> V_124 , V_8 ) ;
V_138:
return V_26 ;
}
int F_104 ( struct V_97 * V_98 , void * V_99 ,
struct V_82 * V_83 )
{
struct V_12 * V_13 = F_91 ( V_98 ) ;
struct V_144 * V_101 =
(struct V_144 * ) V_99 ;
struct V_2 * V_3 = NULL ;
struct F_74 * V_132 = F_74 ( V_83 ) ;
struct V_145 T_5 * V_146 =
(struct V_145 T_5 * ) ( unsigned long )
V_101 -> V_147 ;
T_3 V_108 ;
int V_26 ;
if ( V_101 -> V_108 ) {
struct V_80 * V_4 =
F_105 ( V_13 -> V_148 ,
V_101 -> V_108 ) ;
if ( F_38 ( V_4 == NULL ) ) {
F_103 ( L_8
L_4 ,
( unsigned long ) V_101 -> V_108 ) ;
return - V_110 ;
}
V_3 = & ( F_2 ( V_4 , struct V_54 ,
V_4 ) -> V_3 ) ;
( void ) F_76 ( V_3 ) ;
if ( V_146 != NULL ) {
bool V_149 ;
V_26 = F_106 ( V_132 -> V_86 , V_4 ,
V_113 , & V_149 ) ;
if ( F_38 ( V_26 != 0 ) ) {
F_103 ( L_9
L_10 ) ;
goto V_150;
}
V_108 = V_4 -> V_93 . V_94 ;
}
F_88 ( & V_4 ) ;
}
if ( ! V_3 ) {
V_26 = F_107 ( V_83 , V_13 ,
& V_3 ,
( V_146 ) ?
& V_108 : NULL ) ;
if ( F_38 ( V_26 != 0 ) ) {
F_103 ( L_11 ) ;
return V_26 ;
}
}
F_46 ( V_3 == NULL ) ;
V_26 = F_102 ( V_83 , V_3 ,
V_101 -> V_34 ,
V_101 -> V_135 ,
true ) ;
if ( F_38 ( V_26 != 0 ) ) {
if ( V_26 != - V_28 )
F_103 ( L_12 ) ;
goto V_151;
}
F_108 ( V_13 , V_132 , 0 , V_146 , V_3 ,
V_108 ) ;
F_72 ( & V_3 ) ;
return 0 ;
V_151:
if ( V_146 != NULL )
F_89 ( F_74 ( V_83 ) -> V_86 ,
V_108 , V_113 ) ;
V_150:
F_72 ( & V_3 ) ;
return V_26 ;
}
