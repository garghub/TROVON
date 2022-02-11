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
static void F_9 ( struct V_12 * V_13 )
{
struct V_1 * V_7 =
F_2 ( V_13 , struct V_1 , V_14 ) ;
F_10 ( V_7 -> V_15 , V_16 ) ;
}
static bool F_11 ( struct V_3 * V_6 )
{
struct V_2 * V_3 =
F_2 ( V_6 , struct V_2 , V_4 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_17 * V_15 = V_7 -> V_15 ;
T_1 T_2 * V_18 = V_15 -> V_19 ;
T_3 V_20 = F_12 ( V_18 + V_21 ) ;
if ( V_20 - V_3 -> V_4 . V_20 < V_22 )
return false ;
if ( F_13 ( & V_15 -> V_23 ) ) {
F_14 ( V_15 , V_16 ) ;
F_15 ( & V_15 -> V_23 ) ;
} else
F_16 ( & V_7 -> V_14 ) ;
return true ;
}
static void
F_17 ( struct V_3 * V_3 , struct V_24 * V_25 )
{
struct F_17 * V_26 =
F_2 ( V_25 , struct F_17 , V_4 ) ;
F_18 ( V_26 -> V_27 ) ;
}
static long F_19 ( struct V_3 * V_6 , bool V_28 , signed long V_29 )
{
struct V_2 * V_3 =
F_2 ( V_6 , struct V_2 , V_4 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_17 * V_15 = V_7 -> V_15 ;
struct F_17 V_25 ;
long V_30 = V_29 ;
unsigned long V_8 ;
if ( F_20 ( F_21 ( V_3 ) ) )
return V_29 ;
F_10 ( V_15 , V_16 ) ;
F_22 ( V_15 ) ;
F_4 ( V_6 -> V_5 , V_8 ) ;
if ( V_28 && F_23 ( V_31 ) ) {
V_30 = - V_32 ;
goto V_33;
}
V_25 . V_4 . V_34 = F_17 ;
V_25 . V_27 = V_31 ;
F_24 ( & V_25 . V_4 . V_35 , & V_6 -> V_36 ) ;
while ( V_30 > 0 ) {
F_25 ( V_7 ) ;
if ( F_26 ( V_37 , & V_6 -> V_38 ) )
break;
if ( V_28 )
F_27 ( V_39 ) ;
else
F_27 ( V_40 ) ;
F_6 ( V_6 -> V_5 , V_8 ) ;
V_30 = F_28 ( V_30 ) ;
F_4 ( V_6 -> V_5 , V_8 ) ;
if ( V_30 > 0 && V_28 && F_23 ( V_31 ) )
V_30 = - V_32 ;
}
if ( ! F_29 ( & V_25 . V_4 . V_35 ) )
F_30 ( & V_25 . V_4 . V_35 ) ;
F_27 ( V_41 ) ;
V_33:
F_6 ( V_6 -> V_5 , V_8 ) ;
F_31 ( V_15 ) ;
return V_30 ;
}
static void F_32 ( struct V_12 * V_13 )
{
struct V_1 * V_7 =
F_2 ( V_13 , struct V_1 , V_13 ) ;
struct V_42 V_43 ;
struct V_44 * V_45 , * V_46 ;
bool V_47 ;
do {
F_33 ( & V_43 ) ;
F_34 ( & V_7 -> V_48 ) ;
F_35 ( & V_7 -> V_5 ) ;
F_36 ( & V_7 -> V_49 , & V_43 ) ;
V_47 = V_7 -> V_47 ;
F_37 ( & V_7 -> V_5 ) ;
if ( ! V_47 && V_7 -> V_50 ) {
V_7 -> V_50 = false ;
F_38 ( V_7 -> V_15 ) ;
}
F_15 ( & V_7 -> V_48 ) ;
if ( F_29 ( & V_43 ) )
return;
F_39 (action, next_action, &list, head) {
F_5 ( & V_45 -> V_9 ) ;
if ( V_45 -> V_51 )
V_45 -> V_51 ( V_45 ) ;
}
} while ( 1 );
}
struct V_1 * F_40 ( struct V_17 * V_15 )
{
struct V_1 * V_7 = F_41 ( sizeof( * V_7 ) , V_52 ) ;
if ( F_42 ( V_7 == NULL ) )
return NULL ;
V_7 -> V_15 = V_15 ;
F_43 ( & V_7 -> V_5 ) ;
F_33 ( & V_7 -> V_53 ) ;
F_33 ( & V_7 -> V_49 ) ;
F_44 ( & V_7 -> V_13 , & F_32 ) ;
F_44 ( & V_7 -> V_14 , & F_9 ) ;
V_7 -> V_54 = true ;
V_7 -> V_55 = F_45 ( sizeof( struct V_56 ) ) ;
V_7 -> V_57 = F_45 ( sizeof( struct V_2 ) ) ;
V_7 -> V_58 =
F_45 ( sizeof( struct V_59 ) ) ;
F_46 ( & V_7 -> V_48 ) ;
V_7 -> V_60 = F_47 ( 1 ) ;
return V_7 ;
}
void F_48 ( struct V_1 * V_7 )
{
unsigned long V_8 ;
bool V_61 ;
( void ) F_49 ( & V_7 -> V_13 ) ;
( void ) F_49 ( & V_7 -> V_14 ) ;
F_4 ( & V_7 -> V_5 , V_8 ) ;
V_61 = F_29 ( & V_7 -> V_53 ) &&
F_29 ( & V_7 -> V_49 ) ;
F_6 ( & V_7 -> V_5 , V_8 ) ;
F_50 ( ! V_61 ) ;
F_51 ( V_7 ) ;
}
static int F_52 ( struct V_1 * V_7 ,
struct V_2 * V_3 , T_3 V_20 ,
void (* V_11) ( struct V_2 * V_3 ) )
{
unsigned long V_8 ;
int V_30 = 0 ;
F_53 ( & V_3 -> V_4 , & V_62 , & V_7 -> V_5 ,
V_7 -> V_60 , V_20 ) ;
F_33 ( & V_3 -> V_63 ) ;
V_3 -> V_11 = V_11 ;
F_4 ( & V_7 -> V_5 , V_8 ) ;
if ( F_42 ( V_7 -> V_54 ) ) {
V_30 = - V_64 ;
goto V_65;
}
F_54 ( & V_3 -> V_9 , & V_7 -> V_53 ) ;
++ V_7 -> V_10 ;
V_65:
F_6 ( & V_7 -> V_5 , V_8 ) ;
return V_30 ;
}
static void F_55 ( struct V_1 * V_7 ,
struct V_42 * V_43 )
{
struct V_44 * V_45 , * V_46 ;
F_39 (action, next_action, list, head) {
F_5 ( & V_45 -> V_9 ) ;
V_7 -> V_66 [ V_45 -> type ] -- ;
if ( V_45 -> V_67 != NULL )
V_45 -> V_67 ( V_45 ) ;
F_54 ( & V_45 -> V_9 , & V_7 -> V_49 ) ;
}
}
static bool F_56 ( struct V_1 * V_7 ,
T_3 V_68 )
{
T_3 V_69 ;
T_1 T_2 * V_18 ;
struct V_2 * V_3 ;
if ( F_20 ( ! V_7 -> V_47 ) )
return false ;
V_18 = V_7 -> V_15 -> V_19 ;
V_69 = F_12 ( V_18 + V_70 ) ;
if ( F_20 ( V_68 - V_69 >= V_22 ) )
return false ;
V_7 -> V_47 = false ;
F_57 (fence, &fman->fence_list, head) {
if ( ! F_29 ( & V_3 -> V_63 ) ) {
V_7 -> V_47 = true ;
F_58 ( V_3 -> V_4 . V_20 ,
V_18 + V_70 ) ;
break;
}
}
return true ;
}
static bool F_59 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_3 V_69 ;
T_1 T_2 * V_18 ;
if ( F_60 ( & V_3 -> V_4 ) )
return false ;
V_18 = V_7 -> V_15 -> V_19 ;
V_69 = F_12 ( V_18 + V_70 ) ;
if ( F_20 ( V_7 -> V_47 &&
V_69 - V_3 -> V_4 . V_20 < V_22 ) )
return false ;
F_58 ( V_3 -> V_4 . V_20 , V_18 + V_70 ) ;
V_7 -> V_47 = true ;
return true ;
}
static void F_25 ( struct V_1 * V_7 )
{
struct V_2 * V_3 , * V_71 ;
struct V_42 V_72 ;
bool V_73 ;
T_4 V_20 , V_74 ;
T_1 T_2 * V_18 = V_7 -> V_15 -> V_19 ;
V_20 = F_12 ( V_18 + V_21 ) ;
V_75:
F_39 (fence, next_fence, &fman->fence_list, head) {
if ( V_20 - V_3 -> V_4 . V_20 < V_22 ) {
F_5 ( & V_3 -> V_9 ) ;
F_61 ( & V_3 -> V_4 ) ;
F_33 ( & V_72 ) ;
F_36 ( & V_3 -> V_63 ,
& V_72 ) ;
F_55 ( V_7 , & V_72 ) ;
} else
break;
}
V_73 = F_56 ( V_7 , V_20 ) ;
if ( F_42 ( V_73 ) ) {
V_74 = F_12 ( V_18 + V_21 ) ;
if ( V_74 != V_20 ) {
V_20 = V_74 ;
goto V_75;
}
}
if ( ! F_29 ( & V_7 -> V_49 ) )
( void ) F_16 ( & V_7 -> V_13 ) ;
}
void F_62 ( struct V_1 * V_7 )
{
unsigned long V_8 ;
F_4 ( & V_7 -> V_5 , V_8 ) ;
F_25 ( V_7 ) ;
F_6 ( & V_7 -> V_5 , V_8 ) ;
}
bool F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
if ( F_26 ( V_37 , & V_3 -> V_4 . V_38 ) )
return 1 ;
F_62 ( V_7 ) ;
return F_63 ( & V_3 -> V_4 ) ;
}
int F_64 ( struct V_2 * V_3 , bool V_76 ,
bool V_77 , unsigned long V_29 )
{
long V_30 = F_65 ( & V_3 -> V_4 , V_77 , V_29 ) ;
if ( F_20 ( V_30 > 0 ) )
return 0 ;
else if ( V_30 == 0 )
return - V_64 ;
else
return V_30 ;
}
void F_66 ( struct V_2 * V_3 )
{
struct V_17 * V_15 = F_1 ( V_3 ) -> V_15 ;
F_10 ( V_15 , V_16 ) ;
}
static void F_67 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_68 ( & V_3 -> V_4 ) ;
F_69 ( F_70 ( V_7 -> V_15 ) ,
V_7 -> V_57 ) ;
}
int F_71 ( struct V_1 * V_7 ,
T_4 V_20 ,
struct V_2 * * V_78 )
{
struct V_79 * V_80 = F_70 ( V_7 -> V_15 ) ;
struct V_2 * V_3 ;
int V_30 ;
V_30 = F_72 ( V_80 , V_7 -> V_57 ,
false , false ) ;
if ( F_42 ( V_30 != 0 ) )
return V_30 ;
V_3 = F_41 ( sizeof( * V_3 ) , V_52 ) ;
if ( F_42 ( V_3 == NULL ) ) {
V_30 = - V_81 ;
goto V_82;
}
V_30 = F_52 ( V_7 , V_3 , V_20 ,
F_67 ) ;
if ( F_42 ( V_30 != 0 ) )
goto V_83;
* V_78 = V_3 ;
return 0 ;
V_83:
F_51 ( V_3 ) ;
V_82:
F_69 ( V_80 , V_7 -> V_57 ) ;
return V_30 ;
}
static void F_73 ( struct V_2 * V_3 )
{
struct V_56 * V_84 =
F_2 ( V_3 , struct V_56 , V_3 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_74 ( V_84 , V_4 ) ;
F_69 ( F_70 ( V_7 -> V_15 ) ,
V_7 -> V_55 ) ;
}
static void F_75 ( struct V_85 * * V_86 )
{
struct V_85 * V_4 = * V_86 ;
struct V_56 * V_84 =
F_2 ( V_4 , struct V_56 , V_4 ) ;
struct V_2 * V_3 = & V_84 -> V_3 ;
* V_86 = NULL ;
F_76 ( & V_3 ) ;
}
int F_77 ( struct V_87 * V_88 ,
struct V_1 * V_7 ,
T_4 V_20 ,
struct V_2 * * V_78 ,
T_4 * V_89 )
{
struct V_90 * V_91 = F_78 ( V_88 ) -> V_91 ;
struct V_56 * V_84 ;
struct V_2 * V_92 ;
struct V_79 * V_80 = F_70 ( V_7 -> V_15 ) ;
int V_30 ;
V_30 = F_72 ( V_80 , V_7 -> V_55 ,
false , false ) ;
if ( F_42 ( V_30 != 0 ) )
return V_30 ;
V_84 = F_41 ( sizeof( * V_84 ) , V_52 ) ;
if ( F_42 ( V_84 == NULL ) ) {
V_30 = - V_81 ;
goto V_82;
}
V_30 = F_52 ( V_7 , & V_84 -> V_3 , V_20 ,
F_73 ) ;
if ( F_42 ( V_30 != 0 ) ) {
F_51 ( V_84 ) ;
goto V_82;
}
V_92 = F_79 ( & V_84 -> V_3 ) ;
V_30 = F_80 ( V_91 , & V_84 -> V_4 , false ,
V_93 ,
& F_75 , NULL ) ;
if ( F_42 ( V_30 != 0 ) ) {
F_76 ( & V_92 ) ;
goto V_94;
}
* V_78 = & V_84 -> V_3 ;
* V_89 = V_84 -> V_4 . V_95 . V_96 ;
return 0 ;
V_94:
V_92 = & V_84 -> V_3 ;
F_76 ( & V_92 ) ;
V_82:
F_69 ( V_80 , V_7 -> V_55 ) ;
return V_30 ;
}
void F_81 ( struct V_1 * V_7 )
{
struct V_42 V_72 ;
int V_30 ;
F_35 ( & V_7 -> V_5 ) ;
V_7 -> V_54 = true ;
while ( ! F_29 ( & V_7 -> V_53 ) ) {
struct V_2 * V_3 =
F_82 ( V_7 -> V_53 . V_97 , struct V_2 ,
V_9 ) ;
F_83 ( & V_3 -> V_4 ) ;
F_37 ( & V_7 -> V_5 ) ;
V_30 = F_64 ( V_3 , false , false ,
V_98 ) ;
if ( F_42 ( V_30 != 0 ) ) {
F_5 ( & V_3 -> V_9 ) ;
F_84 ( & V_3 -> V_4 ) ;
F_33 ( & V_72 ) ;
F_36 ( & V_3 -> V_63 ,
& V_72 ) ;
F_55 ( V_7 , & V_72 ) ;
}
F_50 ( ! F_29 ( & V_3 -> V_9 ) ) ;
F_85 ( & V_3 -> V_4 ) ;
F_35 ( & V_7 -> V_5 ) ;
}
F_37 ( & V_7 -> V_5 ) ;
}
void F_86 ( struct V_1 * V_7 )
{
unsigned long V_8 ;
F_4 ( & V_7 -> V_5 , V_8 ) ;
V_7 -> V_54 = false ;
F_6 ( & V_7 -> V_5 , V_8 ) ;
}
int F_87 ( struct V_99 * V_100 , void * V_101 ,
struct V_87 * V_88 )
{
struct V_102 * V_103 =
(struct V_102 * ) V_101 ;
unsigned long V_29 ;
struct V_85 * V_4 ;
struct V_2 * V_3 ;
struct V_90 * V_91 = F_78 ( V_88 ) -> V_91 ;
int V_30 ;
T_5 V_104 = ( ( T_5 ) V_103 -> V_105 * V_106 ) ;
V_104 = ( V_104 >> 20 ) + ( V_104 >> 24 ) -
( V_104 >> 26 ) ;
if ( ! V_103 -> V_107 ) {
V_103 -> V_107 = 1 ;
V_103 -> V_108 = V_109 + V_104 ;
}
V_4 = F_88 ( V_91 , V_103 -> V_110 ) ;
if ( F_42 ( V_4 == NULL ) ) {
F_89 ( V_111 L_3
L_4 ,
( unsigned long ) V_103 -> V_110 ) ;
return - V_112 ;
}
V_3 = & ( F_2 ( V_4 , struct V_56 , V_4 ) -> V_3 ) ;
V_29 = V_109 ;
if ( F_90 ( V_29 , ( unsigned long ) V_103 -> V_108 ) ) {
V_30 = ( ( F_21 ( V_3 ) ) ?
0 : - V_64 ) ;
goto V_33;
}
V_29 = ( unsigned long ) V_103 -> V_108 - V_29 ;
V_30 = F_64 ( V_3 , V_103 -> V_76 , true , V_29 ) ;
V_33:
F_91 ( & V_4 ) ;
if ( V_30 == 0 && ( V_103 -> V_113 & V_114 ) )
return F_92 ( V_91 , V_103 -> V_110 ,
V_115 ) ;
return V_30 ;
}
int F_93 ( struct V_99 * V_100 , void * V_101 ,
struct V_87 * V_88 )
{
struct V_116 * V_103 =
(struct V_116 * ) V_101 ;
struct V_85 * V_4 ;
struct V_2 * V_3 ;
struct V_1 * V_7 ;
struct V_90 * V_91 = F_78 ( V_88 ) -> V_91 ;
struct V_17 * V_15 = F_94 ( V_100 ) ;
V_4 = F_88 ( V_91 , V_103 -> V_110 ) ;
if ( F_42 ( V_4 == NULL ) ) {
F_89 ( V_111 L_5
L_4 ,
( unsigned long ) V_103 -> V_110 ) ;
return - V_112 ;
}
V_3 = & ( F_2 ( V_4 , struct V_56 , V_4 ) -> V_3 ) ;
V_7 = F_1 ( V_3 ) ;
V_103 -> V_117 = F_21 ( V_3 ) ;
V_103 -> V_118 = V_103 -> V_38 ;
F_35 ( & V_7 -> V_5 ) ;
V_103 -> V_68 = V_15 -> V_119 ;
F_37 ( & V_7 -> V_5 ) ;
F_91 ( & V_4 ) ;
return 0 ;
}
int F_95 ( struct V_99 * V_100 , void * V_101 ,
struct V_87 * V_88 )
{
struct V_120 * V_103 =
(struct V_120 * ) V_101 ;
return F_92 ( F_78 ( V_88 ) -> V_91 ,
V_103 -> V_110 ,
V_115 ) ;
}
void F_96 ( struct V_1 * V_7 ,
struct V_42 * V_121 )
{
struct V_59 * V_122 ;
struct V_123 * V_124 ;
unsigned long V_8 ;
while ( 1 ) {
F_4 ( & V_7 -> V_5 , V_8 ) ;
if ( F_29 ( V_121 ) )
goto V_65;
V_122 = F_97 ( V_121 ,
struct V_59 ,
V_125 ) ;
F_5 ( & V_122 -> V_125 ) ;
V_124 = V_122 -> V_124 ;
V_122 -> V_124 = NULL ;
F_6 ( & V_7 -> V_5 , V_8 ) ;
V_124 -> V_11 ( V_124 ) ;
}
V_65:
F_6 ( & V_7 -> V_5 , V_8 ) ;
}
static void F_98 ( struct V_44 * V_45 )
{
struct V_59 * V_122 =
F_2 ( V_45 , struct V_59 , V_45 ) ;
struct V_99 * V_100 = V_122 -> V_100 ;
struct V_123 * V_124 = V_122 -> V_124 ;
struct V_87 * V_88 ;
unsigned long V_8 ;
if ( F_42 ( V_124 == NULL ) )
return;
V_88 = V_124 -> V_88 ;
F_4 ( & V_100 -> V_126 , V_8 ) ;
if ( F_20 ( V_122 -> V_127 != NULL ) ) {
struct V_128 V_129 ;
F_99 ( & V_129 ) ;
* V_122 -> V_127 = V_129 . V_127 ;
* V_122 -> V_130 = V_129 . V_130 ;
}
F_5 ( & V_122 -> V_125 ) ;
F_54 ( & V_122 -> V_124 -> V_131 , & V_88 -> V_121 ) ;
V_122 -> V_124 = NULL ;
F_100 ( & V_88 -> V_132 ) ;
F_6 ( & V_100 -> V_126 , V_8 ) ;
}
static void F_101 ( struct V_44 * V_45 )
{
struct V_59 * V_122 =
F_2 ( V_45 , struct V_59 , V_45 ) ;
struct V_1 * V_7 = F_1 ( V_122 -> V_3 ) ;
unsigned long V_8 ;
F_4 ( & V_7 -> V_5 , V_8 ) ;
F_30 ( & V_122 -> V_125 ) ;
F_6 ( & V_7 -> V_5 , V_8 ) ;
F_76 ( & V_122 -> V_3 ) ;
F_51 ( V_122 ) ;
}
static void F_102 ( struct V_2 * V_3 ,
struct V_44 * V_45 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned long V_8 ;
bool V_133 = false ;
F_34 ( & V_7 -> V_48 ) ;
F_4 ( & V_7 -> V_5 , V_8 ) ;
V_7 -> V_66 [ V_45 -> type ] ++ ;
if ( F_60 ( & V_3 -> V_4 ) ) {
struct V_42 V_72 ;
F_33 ( & V_72 ) ;
F_54 ( & V_45 -> V_9 , & V_72 ) ;
F_55 ( V_7 , & V_72 ) ;
} else {
F_54 ( & V_45 -> V_9 , & V_3 -> V_63 ) ;
V_133 = F_59 ( V_3 ) ;
}
F_6 ( & V_7 -> V_5 , V_8 ) ;
if ( V_133 ) {
if ( ! V_7 -> V_50 ) {
V_7 -> V_50 = true ;
F_103 ( V_7 -> V_15 ) ;
}
F_62 ( V_7 ) ;
}
F_15 ( & V_7 -> V_48 ) ;
}
int F_104 ( struct V_87 * V_88 ,
struct V_2 * V_3 ,
struct V_123 * V_124 ,
T_4 * V_127 ,
T_4 * V_130 ,
bool V_77 )
{
struct V_59 * V_122 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct F_78 * V_134 = F_78 ( V_88 ) ;
unsigned long V_8 ;
V_122 = F_41 ( sizeof( * V_122 ) , V_52 ) ;
if ( F_42 ( V_122 == NULL ) )
return - V_81 ;
V_122 -> V_124 = V_124 ;
V_122 -> V_45 . V_67 = F_98 ;
V_122 -> V_45 . V_51 = F_101 ;
V_122 -> V_45 . type = V_135 ;
V_122 -> V_3 = F_79 ( V_3 ) ;
V_122 -> V_100 = V_7 -> V_15 -> V_100 ;
V_122 -> V_127 = V_127 ;
V_122 -> V_130 = V_130 ;
F_4 ( & V_7 -> V_5 , V_8 ) ;
F_54 ( & V_122 -> V_125 , & V_134 -> V_136 ) ;
F_6 ( & V_7 -> V_5 , V_8 ) ;
F_102 ( V_3 , & V_122 -> V_45 ) ;
return 0 ;
}
static int F_105 ( struct V_87 * V_88 ,
struct V_2 * V_3 ,
T_4 V_38 ,
T_5 V_137 ,
bool V_77 )
{
struct V_138 * V_124 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_99 * V_100 = V_7 -> V_15 -> V_100 ;
unsigned long V_8 ;
int V_30 ;
F_4 ( & V_100 -> V_126 , V_8 ) ;
V_30 = ( V_88 -> V_139 < sizeof( V_124 -> V_124 ) ) ? - V_64 : 0 ;
if ( F_20 ( V_30 == 0 ) )
V_88 -> V_139 -= sizeof( V_124 -> V_124 ) ;
F_6 ( & V_100 -> V_126 , V_8 ) ;
if ( F_42 ( V_30 != 0 ) ) {
F_106 ( L_6 ) ;
goto V_140;
}
V_124 = F_41 ( sizeof( * V_124 ) , V_52 ) ;
if ( F_42 ( V_124 == NULL ) ) {
F_106 ( L_7 ) ;
V_30 = - V_81 ;
goto V_141;
}
V_124 -> V_124 . V_4 . type = V_142 ;
V_124 -> V_124 . V_4 . V_143 = sizeof( * V_124 ) ;
V_124 -> V_124 . V_137 = V_137 ;
V_124 -> V_4 . V_124 = & V_124 -> V_124 . V_4 ;
V_124 -> V_4 . V_88 = V_88 ;
V_124 -> V_4 . V_11 = ( void ( * ) ( struct V_123 * ) ) F_51 ;
if ( V_38 & V_144 )
V_30 = F_104 ( V_88 , V_3 ,
& V_124 -> V_4 ,
& V_124 -> V_124 . V_127 ,
& V_124 -> V_124 . V_130 ,
V_77 ) ;
else
V_30 = F_104 ( V_88 , V_3 ,
& V_124 -> V_4 ,
NULL ,
NULL ,
V_77 ) ;
if ( V_30 != 0 )
goto V_145;
V_145:
V_124 -> V_4 . V_11 ( & V_124 -> V_4 ) ;
V_141:
F_4 ( & V_100 -> V_126 , V_8 ) ;
V_88 -> V_139 += sizeof( * V_124 ) ;
F_6 ( & V_100 -> V_126 , V_8 ) ;
V_140:
return V_30 ;
}
int F_107 ( struct V_99 * V_100 , void * V_101 ,
struct V_87 * V_88 )
{
struct V_17 * V_15 = F_94 ( V_100 ) ;
struct V_146 * V_103 =
(struct V_146 * ) V_101 ;
struct V_2 * V_3 = NULL ;
struct F_78 * V_134 = F_78 ( V_88 ) ;
struct V_147 T_6 * V_148 =
(struct V_147 T_6 * ) ( unsigned long )
V_103 -> V_149 ;
T_4 V_110 ;
int V_30 ;
if ( V_103 -> V_110 ) {
struct V_85 * V_4 =
F_108 ( V_15 -> V_150 ,
V_103 -> V_110 ) ;
if ( F_42 ( V_4 == NULL ) ) {
F_106 ( L_8
L_4 ,
( unsigned long ) V_103 -> V_110 ) ;
return - V_112 ;
}
V_3 = & ( F_2 ( V_4 , struct V_56 ,
V_4 ) -> V_3 ) ;
( void ) F_79 ( V_3 ) ;
if ( V_148 != NULL ) {
bool V_151 ;
V_30 = F_109 ( V_134 -> V_91 , V_4 ,
V_115 , & V_151 ) ;
if ( F_42 ( V_30 != 0 ) ) {
F_106 ( L_9
L_10 ) ;
goto V_152;
}
V_110 = V_4 -> V_95 . V_96 ;
}
F_91 ( & V_4 ) ;
}
if ( ! V_3 ) {
V_30 = F_110 ( V_88 , V_15 ,
& V_3 ,
( V_148 ) ?
& V_110 : NULL ) ;
if ( F_42 ( V_30 != 0 ) ) {
F_106 ( L_11 ) ;
return V_30 ;
}
}
F_50 ( V_3 == NULL ) ;
if ( V_103 -> V_38 & V_144 )
V_30 = F_105 ( V_88 , V_3 ,
V_103 -> V_38 ,
V_103 -> V_137 ,
true ) ;
else
V_30 = F_105 ( V_88 , V_3 ,
V_103 -> V_38 ,
V_103 -> V_137 ,
true ) ;
if ( F_42 ( V_30 != 0 ) ) {
if ( V_30 != - V_32 )
F_106 ( L_12 ) ;
goto V_153;
}
F_111 ( V_15 , V_134 , 0 , V_148 , V_3 ,
V_110 ) ;
F_76 ( & V_3 ) ;
return 0 ;
V_153:
if ( V_148 != NULL )
F_92 ( F_78 ( V_88 ) -> V_91 ,
V_110 , V_115 ) ;
V_152:
F_76 ( & V_3 ) ;
return V_30 ;
}
