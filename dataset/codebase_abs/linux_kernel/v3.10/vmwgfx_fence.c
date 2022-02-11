static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 =
F_2 ( V_1 , struct V_2 , V_1 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned int V_6 ;
F_3 ( & V_3 -> V_7 ) ;
V_6 = -- V_5 -> V_8 ;
F_4 ( & V_5 -> V_9 ) ;
if ( V_3 -> V_10 )
V_3 -> V_10 ( V_3 ) ;
else
F_5 ( V_3 ) ;
F_6 ( & V_5 -> V_9 ) ;
}
static void F_7 ( struct V_11 * V_12 )
{
struct V_4 * V_5 =
F_2 ( V_12 , struct V_4 , V_12 ) ;
struct V_13 V_14 ;
struct V_15 * V_16 , * V_17 ;
bool V_18 ;
do {
F_8 ( & V_14 ) ;
F_9 ( & V_5 -> V_19 ) ;
F_6 ( & V_5 -> V_9 ) ;
F_10 ( & V_5 -> V_20 , & V_14 ) ;
V_18 = V_5 -> V_18 ;
F_4 ( & V_5 -> V_9 ) ;
if ( ! V_18 && V_5 -> V_21 ) {
V_5 -> V_21 = false ;
F_11 ( V_5 -> V_22 ) ;
}
F_12 ( & V_5 -> V_19 ) ;
if ( F_13 ( & V_14 ) )
return;
F_14 (action, next_action, &list, head) {
F_3 ( & V_16 -> V_7 ) ;
if ( V_16 -> V_23 )
V_16 -> V_23 ( V_16 ) ;
}
} while ( 1 );
}
struct V_4 * F_15 ( struct V_24 * V_22 )
{
struct V_4 * V_5 = F_16 ( sizeof( * V_5 ) , V_25 ) ;
if ( F_17 ( V_5 == NULL ) )
return NULL ;
V_5 -> V_22 = V_22 ;
F_18 ( & V_5 -> V_9 ) ;
F_8 ( & V_5 -> V_26 ) ;
F_8 ( & V_5 -> V_20 ) ;
F_19 ( & V_5 -> V_12 , & F_7 ) ;
V_5 -> V_27 = true ;
V_5 -> V_28 = F_20 ( sizeof( struct V_29 ) ) ;
V_5 -> V_30 = F_20 ( sizeof( struct V_2 ) ) ;
V_5 -> V_31 =
F_20 ( sizeof( struct V_32 ) ) ;
F_21 ( & V_5 -> V_19 ) ;
return V_5 ;
}
void F_22 ( struct V_4 * V_5 )
{
unsigned long V_33 ;
bool V_34 ;
( void ) F_23 ( & V_5 -> V_12 ) ;
F_24 ( & V_5 -> V_9 , V_33 ) ;
V_34 = F_13 ( & V_5 -> V_26 ) &&
F_13 ( & V_5 -> V_20 ) ;
F_25 ( & V_5 -> V_9 , V_33 ) ;
F_26 ( ! V_34 ) ;
F_5 ( V_5 ) ;
}
static int F_27 ( struct V_4 * V_5 ,
struct V_2 * V_3 ,
T_1 V_35 ,
T_2 V_36 ,
void (* V_10) ( struct V_2 * V_3 ) )
{
unsigned long V_33 ;
unsigned int V_6 ;
int V_37 = 0 ;
V_3 -> V_35 = V_35 ;
F_8 ( & V_3 -> V_38 ) ;
V_3 -> V_5 = V_5 ;
V_3 -> V_39 = 0 ;
V_3 -> V_40 = V_36 ;
F_28 ( & V_3 -> V_1 ) ;
V_3 -> V_10 = V_10 ;
F_29 ( & V_3 -> V_41 ) ;
F_24 ( & V_5 -> V_9 , V_33 ) ;
if ( F_17 ( V_5 -> V_27 ) ) {
V_37 = - V_42 ;
goto V_43;
}
F_30 ( & V_3 -> V_7 , & V_5 -> V_26 ) ;
V_6 = ++ V_5 -> V_8 ;
V_43:
F_25 ( & V_5 -> V_9 , V_33 ) ;
return V_37 ;
}
struct V_2 * F_31 ( struct V_2 * V_3 )
{
if ( F_17 ( V_3 == NULL ) )
return NULL ;
F_32 ( & V_3 -> V_1 ) ;
return V_3 ;
}
void F_33 ( struct V_2 * * V_44 )
{
struct V_2 * V_3 = * V_44 ;
struct V_4 * V_5 ;
if ( F_17 ( V_3 == NULL ) )
return;
V_5 = V_3 -> V_5 ;
* V_44 = NULL ;
F_6 ( & V_5 -> V_9 ) ;
F_26 ( F_34 ( & V_3 -> V_1 . V_45 ) == 0 ) ;
F_35 ( & V_3 -> V_1 , F_1 ) ;
F_4 ( & V_5 -> V_9 ) ;
}
void F_36 ( struct V_4 * V_5 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 , * V_17 ;
F_14 (action, next_action, list, head) {
F_3 ( & V_16 -> V_7 ) ;
V_5 -> V_46 [ V_16 -> type ] -- ;
if ( V_16 -> V_47 != NULL )
V_16 -> V_47 ( V_16 ) ;
F_30 ( & V_16 -> V_7 , & V_5 -> V_20 ) ;
}
}
static bool F_37 ( struct V_4 * V_5 ,
T_1 V_48 )
{
T_1 V_49 ;
T_3 T_4 * V_50 ;
struct V_2 * V_3 ;
if ( F_38 ( ! V_5 -> V_18 ) )
return false ;
V_50 = V_5 -> V_22 -> V_51 ;
V_49 = F_39 ( V_50 + V_52 ) ;
if ( F_38 ( V_48 - V_49 >= V_53 ) )
return false ;
V_5 -> V_18 = false ;
F_40 (fence, &fman->fence_list, head) {
if ( ! F_13 ( & V_3 -> V_38 ) ) {
V_5 -> V_18 = true ;
F_41 ( V_3 -> V_35 ,
V_50 + V_52 ) ;
break;
}
}
return true ;
}
static bool F_42 ( struct V_2 * V_3 )
{
T_1 V_49 ;
T_3 T_4 * V_50 ;
if ( V_3 -> V_39 & V_54 )
return false ;
V_50 = V_3 -> V_5 -> V_22 -> V_51 ;
V_49 = F_39 ( V_50 + V_52 ) ;
if ( F_38 ( V_3 -> V_5 -> V_18 &&
V_49 - V_3 -> V_35 < V_53 ) )
return false ;
F_41 ( V_3 -> V_35 , V_50 + V_52 ) ;
V_3 -> V_5 -> V_18 = true ;
return true ;
}
void F_43 ( struct V_4 * V_5 )
{
unsigned long V_55 ;
struct V_2 * V_3 , * V_56 ;
struct V_13 V_57 ;
bool V_58 ;
T_2 V_35 , V_59 ;
T_3 T_4 * V_50 = V_5 -> V_22 -> V_51 ;
V_35 = F_39 ( V_50 + V_60 ) ;
V_61:
F_24 ( & V_5 -> V_9 , V_55 ) ;
F_14 (fence, next_fence, &fman->fence_list, head) {
if ( V_35 - V_3 -> V_35 < V_53 ) {
F_3 ( & V_3 -> V_7 ) ;
V_3 -> V_39 |= V_54 ;
F_8 ( & V_57 ) ;
F_10 ( & V_3 -> V_38 ,
& V_57 ) ;
F_36 ( V_5 , & V_57 ) ;
F_44 ( & V_3 -> V_41 ) ;
} else
break;
}
V_58 = F_37 ( V_5 , V_35 ) ;
if ( ! F_13 ( & V_5 -> V_20 ) )
( void ) F_45 ( & V_5 -> V_12 ) ;
F_25 ( & V_5 -> V_9 , V_55 ) ;
if ( F_17 ( V_58 ) ) {
V_59 = F_39 ( V_50 + V_60 ) ;
if ( V_59 != V_35 ) {
V_35 = V_59 ;
goto V_61;
}
}
}
bool F_46 ( struct V_2 * V_3 ,
T_2 V_55 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_33 ;
T_2 V_39 ;
F_24 ( & V_5 -> V_9 , V_33 ) ;
V_39 = V_3 -> V_39 ;
F_25 ( & V_5 -> V_9 , V_33 ) ;
V_55 &= V_3 -> V_40 ;
if ( ( V_39 & V_55 ) == V_55 )
return 1 ;
if ( ( V_39 & V_54 ) == 0 )
F_43 ( V_5 ) ;
F_24 ( & V_5 -> V_9 , V_33 ) ;
V_39 = V_3 -> V_39 ;
F_25 ( & V_5 -> V_9 , V_33 ) ;
return ( ( V_39 & V_55 ) == V_55 ) ;
}
int F_47 ( struct V_2 * V_3 ,
T_2 V_55 , bool V_62 ,
bool V_63 , unsigned long V_64 )
{
struct V_24 * V_22 = V_3 -> V_5 -> V_22 ;
long V_37 ;
if ( F_38 ( F_46 ( V_3 , V_55 ) ) )
return 0 ;
F_48 ( V_22 , V_65 ) ;
F_49 ( V_22 ) ;
if ( V_63 )
V_37 = F_50
( V_3 -> V_41 ,
F_46 ( V_3 , V_55 ) ,
V_64 ) ;
else
V_37 = F_51
( V_3 -> V_41 ,
F_46 ( V_3 , V_55 ) ,
V_64 ) ;
F_52 ( V_22 ) ;
if ( F_17 ( V_37 == 0 ) )
V_37 = - V_42 ;
else if ( F_38 ( V_37 > 0 ) )
V_37 = 0 ;
return V_37 ;
}
void F_53 ( struct V_2 * V_3 )
{
struct V_24 * V_22 = V_3 -> V_5 -> V_22 ;
F_48 ( V_22 , V_65 ) ;
}
static void F_54 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
F_5 ( V_3 ) ;
F_55 ( F_56 ( V_5 -> V_22 ) ,
V_5 -> V_30 ) ;
}
int F_57 ( struct V_4 * V_5 ,
T_2 V_35 ,
T_2 V_36 ,
struct V_2 * * V_66 )
{
struct V_67 * V_68 = F_56 ( V_5 -> V_22 ) ;
struct V_2 * V_3 ;
int V_37 ;
V_37 = F_58 ( V_68 , V_5 -> V_30 ,
false , false ) ;
if ( F_17 ( V_37 != 0 ) )
return V_37 ;
V_3 = F_16 ( sizeof( * V_3 ) , V_25 ) ;
if ( F_17 ( V_3 == NULL ) ) {
V_37 = - V_69 ;
goto V_70;
}
V_37 = F_27 ( V_5 , V_3 , V_35 , V_36 ,
F_54 ) ;
if ( F_17 ( V_37 != 0 ) )
goto V_71;
* V_66 = V_3 ;
return 0 ;
V_71:
F_5 ( V_3 ) ;
V_70:
F_55 ( V_68 , V_5 -> V_30 ) ;
return V_37 ;
}
static void F_59 ( struct V_2 * V_3 )
{
struct V_29 * V_72 =
F_2 ( V_3 , struct V_29 , V_3 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_60 ( V_72 , V_73 ) ;
F_55 ( F_56 ( V_5 -> V_22 ) ,
V_5 -> V_28 ) ;
}
static void F_61 ( struct V_74 * * V_75 )
{
struct V_74 * V_73 = * V_75 ;
struct V_29 * V_72 =
F_2 ( V_73 , struct V_29 , V_73 ) ;
struct V_2 * V_3 = & V_72 -> V_3 ;
* V_75 = NULL ;
F_33 ( & V_3 ) ;
}
int F_62 ( struct V_76 * V_77 ,
struct V_4 * V_5 ,
T_2 V_35 ,
T_2 V_36 ,
struct V_2 * * V_66 ,
T_2 * V_78 )
{
struct V_79 * V_80 = F_63 ( V_77 ) -> V_80 ;
struct V_29 * V_72 ;
struct V_2 * V_81 ;
struct V_67 * V_68 = F_56 ( V_5 -> V_22 ) ;
int V_37 ;
V_37 = F_58 ( V_68 , V_5 -> V_28 ,
false , false ) ;
if ( F_17 ( V_37 != 0 ) )
return V_37 ;
V_72 = F_16 ( sizeof( * V_72 ) , V_25 ) ;
if ( F_17 ( V_72 == NULL ) ) {
V_37 = - V_69 ;
goto V_70;
}
V_37 = F_27 ( V_5 , & V_72 -> V_3 , V_35 ,
V_36 , F_59 ) ;
if ( F_17 ( V_37 != 0 ) ) {
F_5 ( V_72 ) ;
goto V_70;
}
V_81 = F_31 ( & V_72 -> V_3 ) ;
V_37 = F_64 ( V_80 , & V_72 -> V_73 , false ,
V_82 ,
& F_61 , NULL ) ;
if ( F_17 ( V_37 != 0 ) ) {
F_33 ( & V_81 ) ;
goto V_83;
}
* V_66 = & V_72 -> V_3 ;
* V_78 = V_72 -> V_73 . V_84 . V_85 ;
return 0 ;
V_83:
V_81 = & V_72 -> V_3 ;
F_33 ( & V_81 ) ;
V_70:
F_55 ( V_68 , V_5 -> V_28 ) ;
return V_37 ;
}
void F_65 ( struct V_4 * V_5 )
{
unsigned long V_33 ;
struct V_13 V_57 ;
int V_37 ;
F_24 ( & V_5 -> V_9 , V_33 ) ;
V_5 -> V_27 = true ;
while ( ! F_13 ( & V_5 -> V_26 ) ) {
struct V_2 * V_3 =
F_66 ( V_5 -> V_26 . V_86 , struct V_2 ,
V_7 ) ;
F_32 ( & V_3 -> V_1 ) ;
F_4 ( & V_5 -> V_9 ) ;
V_37 = F_47 ( V_3 , V_3 -> V_40 ,
false , false ,
V_87 ) ;
if ( F_17 ( V_37 != 0 ) ) {
F_3 ( & V_3 -> V_7 ) ;
V_3 -> V_39 |= V_54 ;
F_8 ( & V_57 ) ;
F_10 ( & V_3 -> V_38 ,
& V_57 ) ;
F_36 ( V_5 , & V_57 ) ;
F_44 ( & V_3 -> V_41 ) ;
}
F_6 ( & V_5 -> V_9 ) ;
F_26 ( ! F_13 ( & V_3 -> V_7 ) ) ;
F_35 ( & V_3 -> V_1 , F_1 ) ;
}
F_25 ( & V_5 -> V_9 , V_33 ) ;
}
void F_67 ( struct V_4 * V_5 )
{
unsigned long V_33 ;
F_24 ( & V_5 -> V_9 , V_33 ) ;
V_5 -> V_27 = false ;
F_25 ( & V_5 -> V_9 , V_33 ) ;
}
int F_68 ( struct V_88 * V_89 , void * V_90 ,
struct V_76 * V_77 )
{
struct V_91 * V_92 =
(struct V_91 * ) V_90 ;
unsigned long V_64 ;
struct V_74 * V_73 ;
struct V_2 * V_3 ;
struct V_79 * V_80 = F_63 ( V_77 ) -> V_80 ;
int V_37 ;
T_5 V_93 = ( ( T_5 ) V_92 -> V_94 * V_95 ) ;
V_93 = ( V_93 >> 20 ) + ( V_93 >> 24 ) -
( V_93 >> 26 ) ;
if ( ! V_92 -> V_96 ) {
V_92 -> V_96 = 1 ;
V_92 -> V_97 = V_98 + V_93 ;
}
V_73 = F_69 ( V_80 , V_92 -> V_99 ) ;
if ( F_17 ( V_73 == NULL ) ) {
F_70 ( V_100 L_1
L_2 ,
( unsigned long ) V_92 -> V_99 ) ;
return - V_101 ;
}
V_3 = & ( F_2 ( V_73 , struct V_29 , V_73 ) -> V_3 ) ;
V_64 = V_98 ;
if ( F_71 ( V_64 , ( unsigned long ) V_92 -> V_97 ) ) {
V_37 = ( ( F_46 ( V_3 , V_92 -> V_55 ) ) ?
0 : - V_42 ) ;
goto V_102;
}
V_64 = ( unsigned long ) V_92 -> V_97 - V_64 ;
V_37 = F_47 ( V_3 , V_92 -> V_55 , V_92 -> V_62 , true , V_64 ) ;
V_102:
F_72 ( & V_73 ) ;
if ( V_37 == 0 && ( V_92 -> V_103 & V_104 ) )
return F_73 ( V_80 , V_92 -> V_99 ,
V_105 ) ;
return V_37 ;
}
int F_74 ( struct V_88 * V_89 , void * V_90 ,
struct V_76 * V_77 )
{
struct V_106 * V_92 =
(struct V_106 * ) V_90 ;
struct V_74 * V_73 ;
struct V_2 * V_3 ;
struct V_4 * V_5 ;
struct V_79 * V_80 = F_63 ( V_77 ) -> V_80 ;
struct V_24 * V_22 = F_75 ( V_89 ) ;
V_73 = F_69 ( V_80 , V_92 -> V_99 ) ;
if ( F_17 ( V_73 == NULL ) ) {
F_70 ( V_100 L_3
L_2 ,
( unsigned long ) V_92 -> V_99 ) ;
return - V_101 ;
}
V_3 = & ( F_2 ( V_73 , struct V_29 , V_73 ) -> V_3 ) ;
V_5 = V_3 -> V_5 ;
V_92 -> V_39 = F_46 ( V_3 , V_92 -> V_55 ) ;
F_6 ( & V_5 -> V_9 ) ;
V_92 -> V_107 = V_3 -> V_39 ;
V_92 -> V_48 = V_22 -> V_108 ;
F_4 ( & V_5 -> V_9 ) ;
F_72 ( & V_73 ) ;
return 0 ;
}
int F_76 ( struct V_88 * V_89 , void * V_90 ,
struct V_76 * V_77 )
{
struct V_109 * V_92 =
(struct V_109 * ) V_90 ;
return F_73 ( F_63 ( V_77 ) -> V_80 ,
V_92 -> V_99 ,
V_105 ) ;
}
void F_77 ( struct V_4 * V_5 ,
struct V_13 * V_110 )
{
struct V_32 * V_111 ;
struct V_112 * V_113 ;
unsigned long V_33 ;
while ( 1 ) {
F_24 ( & V_5 -> V_9 , V_33 ) ;
if ( F_13 ( V_110 ) )
goto V_43;
V_111 = F_78 ( V_110 ,
struct V_32 ,
V_114 ) ;
F_3 ( & V_111 -> V_114 ) ;
V_113 = V_111 -> V_113 ;
V_111 -> V_113 = NULL ;
F_25 ( & V_5 -> V_9 , V_33 ) ;
V_113 -> V_10 ( V_113 ) ;
}
V_43:
F_25 ( & V_5 -> V_9 , V_33 ) ;
}
static void F_79 ( struct V_15 * V_16 )
{
struct V_32 * V_111 =
F_2 ( V_16 , struct V_32 , V_16 ) ;
struct V_88 * V_89 = V_111 -> V_89 ;
struct V_112 * V_113 = V_111 -> V_113 ;
struct V_76 * V_77 ;
unsigned long V_33 ;
if ( F_17 ( V_113 == NULL ) )
return;
V_77 = V_113 -> V_77 ;
F_24 ( & V_89 -> V_115 , V_33 ) ;
if ( F_38 ( V_111 -> V_116 != NULL ) ) {
struct V_117 V_118 ;
F_80 ( & V_118 ) ;
* V_111 -> V_116 = V_118 . V_116 ;
* V_111 -> V_119 = V_118 . V_119 ;
}
F_3 ( & V_111 -> V_114 ) ;
F_30 ( & V_111 -> V_113 -> V_120 , & V_77 -> V_110 ) ;
V_111 -> V_113 = NULL ;
F_44 ( & V_77 -> V_121 ) ;
F_25 ( & V_89 -> V_115 , V_33 ) ;
}
static void F_81 ( struct V_15 * V_16 )
{
struct V_32 * V_111 =
F_2 ( V_16 , struct V_32 , V_16 ) ;
struct V_4 * V_5 = V_111 -> V_3 -> V_5 ;
unsigned long V_33 ;
F_24 ( & V_5 -> V_9 , V_33 ) ;
F_82 ( & V_111 -> V_114 ) ;
F_25 ( & V_5 -> V_9 , V_33 ) ;
F_33 ( & V_111 -> V_3 ) ;
F_5 ( V_111 ) ;
}
void F_83 ( struct V_2 * V_3 ,
struct V_15 * V_16 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_33 ;
bool V_122 = false ;
F_9 ( & V_5 -> V_19 ) ;
F_24 ( & V_5 -> V_9 , V_33 ) ;
V_5 -> V_46 [ V_16 -> type ] ++ ;
if ( V_3 -> V_39 & V_54 ) {
struct V_13 V_57 ;
F_8 ( & V_57 ) ;
F_30 ( & V_16 -> V_7 , & V_57 ) ;
F_36 ( V_5 , & V_57 ) ;
} else {
F_30 ( & V_16 -> V_7 , & V_3 -> V_38 ) ;
V_122 = F_42 ( V_3 ) ;
}
F_25 ( & V_5 -> V_9 , V_33 ) ;
if ( V_122 ) {
if ( ! V_5 -> V_21 ) {
V_5 -> V_21 = true ;
F_84 ( V_5 -> V_22 ) ;
}
F_43 ( V_5 ) ;
}
F_12 ( & V_5 -> V_19 ) ;
}
int F_85 ( struct V_76 * V_77 ,
struct V_2 * V_3 ,
struct V_112 * V_113 ,
T_2 * V_116 ,
T_2 * V_119 ,
bool V_63 )
{
struct V_32 * V_111 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct F_63 * V_123 = F_63 ( V_77 ) ;
unsigned long V_33 ;
V_111 = F_16 ( sizeof( * V_111 ) , V_25 ) ;
if ( F_17 ( V_111 == NULL ) )
return - V_69 ;
V_111 -> V_113 = V_113 ;
V_111 -> V_16 . V_47 = F_79 ;
V_111 -> V_16 . V_23 = F_81 ;
V_111 -> V_16 . type = V_124 ;
V_111 -> V_3 = F_31 ( V_3 ) ;
V_111 -> V_89 = V_5 -> V_22 -> V_89 ;
V_111 -> V_116 = V_116 ;
V_111 -> V_119 = V_119 ;
F_24 ( & V_5 -> V_9 , V_33 ) ;
F_30 ( & V_111 -> V_114 , & V_123 -> V_125 ) ;
F_25 ( & V_5 -> V_9 , V_33 ) ;
F_83 ( V_3 , & V_111 -> V_16 ) ;
return 0 ;
}
int F_86 ( struct V_76 * V_77 ,
struct V_2 * V_3 ,
T_2 V_55 ,
T_5 V_126 ,
bool V_63 )
{
struct V_127 * V_113 ;
struct V_88 * V_89 = V_3 -> V_5 -> V_22 -> V_89 ;
unsigned long V_33 ;
int V_37 ;
F_24 ( & V_89 -> V_115 , V_33 ) ;
V_37 = ( V_77 -> V_128 < sizeof( V_113 -> V_113 ) ) ? - V_42 : 0 ;
if ( F_38 ( V_37 == 0 ) )
V_77 -> V_128 -= sizeof( V_113 -> V_113 ) ;
F_25 ( & V_89 -> V_115 , V_33 ) ;
if ( F_17 ( V_37 != 0 ) ) {
F_87 ( L_4 ) ;
goto V_129;
}
V_113 = F_16 ( sizeof( * V_113 ) , V_25 ) ;
if ( F_17 ( V_113 == NULL ) ) {
F_87 ( L_5 ) ;
V_37 = - V_69 ;
goto V_130;
}
V_113 -> V_113 . V_73 . type = V_131 ;
V_113 -> V_113 . V_73 . V_132 = sizeof( * V_113 ) ;
V_113 -> V_113 . V_126 = V_126 ;
V_113 -> V_73 . V_113 = & V_113 -> V_113 . V_73 ;
V_113 -> V_73 . V_77 = V_77 ;
V_113 -> V_73 . V_10 = ( void ( * ) ( struct V_112 * ) ) F_5 ;
if ( V_55 & V_133 )
V_37 = F_85 ( V_77 , V_3 ,
& V_113 -> V_73 ,
& V_113 -> V_113 . V_116 ,
& V_113 -> V_113 . V_119 ,
V_63 ) ;
else
V_37 = F_85 ( V_77 , V_3 ,
& V_113 -> V_73 ,
NULL ,
NULL ,
V_63 ) ;
if ( V_37 != 0 )
goto V_134;
V_134:
V_113 -> V_73 . V_10 ( & V_113 -> V_73 ) ;
V_130:
F_24 ( & V_89 -> V_115 , V_33 ) ;
V_77 -> V_128 += sizeof( * V_113 ) ;
F_25 ( & V_89 -> V_115 , V_33 ) ;
V_129:
return V_37 ;
}
int F_88 ( struct V_88 * V_89 , void * V_90 ,
struct V_76 * V_77 )
{
struct V_24 * V_22 = F_75 ( V_89 ) ;
struct V_135 * V_92 =
(struct V_135 * ) V_90 ;
struct V_2 * V_3 = NULL ;
struct F_63 * V_123 = F_63 ( V_77 ) ;
struct V_136 T_6 * V_137 =
(struct V_136 T_6 * ) ( unsigned long )
V_92 -> V_138 ;
T_2 V_99 ;
int V_37 ;
if ( V_92 -> V_99 ) {
struct V_74 * V_73 =
F_69 ( V_123 -> V_80 , V_92 -> V_99 ) ;
if ( F_17 ( V_73 == NULL ) ) {
F_87 ( L_6
L_2 ,
( unsigned long ) V_92 -> V_99 ) ;
return - V_101 ;
}
V_3 = & ( F_2 ( V_73 , struct V_29 ,
V_73 ) -> V_3 ) ;
( void ) F_31 ( V_3 ) ;
if ( V_137 != NULL ) {
bool V_139 ;
V_37 = F_89 ( V_123 -> V_80 , V_73 ,
V_105 , & V_139 ) ;
if ( F_17 ( V_37 != 0 ) ) {
F_87 ( L_7
L_8 ) ;
goto V_140;
}
V_99 = V_73 -> V_84 . V_85 ;
}
F_72 ( & V_73 ) ;
}
if ( ! V_3 ) {
V_37 = F_90 ( V_77 , V_22 ,
& V_3 ,
( V_137 ) ?
& V_99 : NULL ) ;
if ( F_17 ( V_37 != 0 ) ) {
F_87 ( L_9 ) ;
return V_37 ;
}
}
F_26 ( V_3 == NULL ) ;
if ( V_92 -> V_55 & V_133 )
V_37 = F_86 ( V_77 , V_3 ,
V_92 -> V_55 ,
V_92 -> V_126 ,
true ) ;
else
V_37 = F_86 ( V_77 , V_3 ,
V_92 -> V_55 ,
V_92 -> V_126 ,
true ) ;
if ( F_17 ( V_37 != 0 ) ) {
if ( V_37 != - V_141 )
F_87 ( L_10 ) ;
goto V_142;
}
F_91 ( V_22 , V_123 , 0 , V_137 , V_3 ,
V_99 ) ;
F_33 ( & V_3 ) ;
return 0 ;
V_142:
if ( V_137 != NULL )
F_73 ( F_63 ( V_77 ) -> V_80 ,
V_99 , V_105 ) ;
V_140:
F_33 ( & V_3 ) ;
return V_37 ;
}
