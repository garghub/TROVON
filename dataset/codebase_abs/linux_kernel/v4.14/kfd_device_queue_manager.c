static inline
enum V_1 F_1 ( enum V_2 type )
{
if ( type == V_3 )
return V_4 ;
return V_5 ;
}
static bool F_2 ( struct V_6 * V_7 , int V_8 , int V_9 )
{
int V_10 ;
int V_11 = V_8 * V_7 -> V_12 -> V_13 . V_14
+ V_9 * V_7 -> V_12 -> V_13 . V_15 ;
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_13 . V_15 ; ++ V_10 )
if ( F_3 ( V_11 + V_10 ,
V_7 -> V_12 -> V_13 . V_16 ) )
return true ;
return false ;
}
unsigned int F_4 ( struct V_6 * V_7 )
{
return F_5 ( V_7 -> V_12 -> V_13 . V_16 ,
V_17 ) ;
}
unsigned int F_6 ( struct V_6 * V_7 )
{
return V_7 -> V_12 -> V_13 . V_15 ;
}
unsigned int F_7 ( struct V_6 * V_7 )
{
return V_7 -> V_12 -> V_13 . V_14 ;
}
void F_8 ( struct V_6 * V_7 ,
struct V_18 * V_19 )
{
return V_7 -> V_12 -> V_20 -> F_8 (
V_7 -> V_12 -> V_21 , V_19 -> V_22 ,
V_19 -> V_23 ,
V_19 -> V_24 ,
V_19 -> V_25 ,
V_19 -> V_26 ) ;
}
static int F_9 ( struct V_6 * V_7 ,
struct V_18 * V_19 ,
struct V_27 * V_28 )
{
int V_29 , V_30 ;
if ( V_7 -> V_31 == 0 )
return - V_32 ;
V_29 = F_10 ( ( unsigned long * ) & V_7 -> V_31 , V_33 ) ;
F_11 ( V_29 , ( unsigned long * ) & V_7 -> V_31 ) ;
V_30 = V_29 + V_34 ;
F_12 ( L_1 , V_30 ) ;
V_19 -> V_22 = V_30 ;
V_28 -> V_35 . V_22 = V_30 ;
F_13 ( V_7 , V_28 -> V_36 -> V_37 , V_28 -> V_35 . V_22 ) ;
F_8 ( V_7 , V_19 ) ;
return 0 ;
}
static void F_14 ( struct V_6 * V_7 ,
struct V_18 * V_19 ,
struct V_27 * V_28 )
{
int V_29 = V_19 -> V_22 - V_34 ;
F_13 ( V_7 , 0 , V_19 -> V_22 ) ;
F_15 ( V_29 , ( unsigned long * ) & V_7 -> V_31 ) ;
V_19 -> V_22 = 0 ;
V_28 -> V_35 . V_22 = 0 ;
}
static int F_16 ( struct V_6 * V_7 ,
struct V_27 * V_28 ,
struct V_18 * V_19 ,
int * V_30 )
{
int V_38 ;
F_17 ( V_28 ) ;
F_18 ( & V_7 -> V_39 ) ;
if ( V_7 -> V_40 >= V_41 ) {
F_19 ( L_2 ,
V_7 -> V_40 ) ;
V_38 = - V_42 ;
goto V_43;
}
if ( F_20 ( & V_19 -> V_44 ) ) {
V_38 = F_9 ( V_7 , V_19 , V_28 ) ;
if ( V_38 )
goto V_43;
}
* V_30 = V_19 -> V_22 ;
V_28 -> V_35 . V_22 = V_19 -> V_22 ;
if ( V_28 -> V_35 . type == V_45 )
V_38 = F_21 ( V_7 , V_28 , V_19 ) ;
else if ( V_28 -> V_35 . type == V_3 )
V_38 = F_22 ( V_7 , V_28 , V_19 ) ;
else
V_38 = - V_46 ;
if ( V_38 ) {
if ( F_20 ( & V_19 -> V_44 ) ) {
F_14 ( V_7 , V_19 , V_28 ) ;
* V_30 = 0 ;
}
goto V_43;
}
F_23 ( & V_28 -> V_47 , & V_19 -> V_44 ) ;
if ( V_28 -> V_35 . V_48 )
V_7 -> V_49 ++ ;
if ( V_28 -> V_35 . type == V_3 )
V_7 -> V_50 ++ ;
V_7 -> V_40 ++ ;
F_12 ( L_3 ,
V_7 -> V_40 ) ;
V_43:
F_24 ( & V_7 -> V_39 ) ;
return V_38 ;
}
static int F_25 ( struct V_6 * V_7 , struct V_27 * V_28 )
{
bool V_51 ;
int V_9 , V_29 , V_10 ;
V_51 = false ;
for ( V_9 = V_7 -> V_52 , V_10 = 0 ;
V_10 < F_7 ( V_7 ) ;
V_9 = ( ( V_9 + 1 ) % F_7 ( V_7 ) ) , ++ V_10 ) {
if ( ! F_2 ( V_7 , 0 , V_9 ) )
continue;
if ( V_7 -> V_53 [ V_9 ] != 0 ) {
V_29 = F_10 (
( unsigned long * ) & V_7 -> V_53 [ V_9 ] ,
F_6 ( V_7 ) ) ;
F_11 ( V_29 ,
( unsigned long * ) & V_7 -> V_53 [ V_9 ] ) ;
V_28 -> V_9 = V_9 ;
V_28 -> V_27 = V_29 ;
V_51 = true ;
break;
}
}
if ( ! V_51 )
return - V_54 ;
F_12 ( L_4 , V_28 -> V_9 , V_28 -> V_27 ) ;
V_7 -> V_52 = ( V_9 + 1 ) % F_7 ( V_7 ) ;
return 0 ;
}
static inline void F_26 ( struct V_6 * V_7 ,
struct V_27 * V_28 )
{
F_15 ( V_28 -> V_27 , ( unsigned long * ) & V_7 -> V_53 [ V_28 -> V_9 ] ) ;
}
static int F_21 ( struct V_6 * V_7 ,
struct V_27 * V_28 ,
struct V_18 * V_19 )
{
int V_38 ;
struct V_55 * V_56 ;
V_56 = V_7 -> V_57 . V_58 ( V_7 , V_59 ) ;
if ( ! V_56 )
return - V_32 ;
V_38 = F_25 ( V_7 , V_28 ) ;
if ( V_38 )
return V_38 ;
V_38 = V_56 -> V_60 ( V_56 , & V_28 -> V_56 , & V_28 -> V_61 ,
& V_28 -> V_62 , & V_28 -> V_35 ) ;
if ( V_38 )
goto V_63;
F_12 ( L_5 ,
V_28 -> V_9 , V_28 -> V_27 ) ;
V_7 -> V_12 -> V_20 -> V_64 (
V_7 -> V_12 -> V_21 , V_19 -> V_65 , V_19 -> V_22 ) ;
V_38 = V_56 -> V_66 ( V_56 , V_28 -> V_56 , V_28 -> V_9 , V_28 -> V_27 , & V_28 -> V_35 ,
V_28 -> V_36 -> V_67 ) ;
if ( V_38 )
goto V_68;
return 0 ;
V_68:
V_56 -> V_69 ( V_56 , V_28 -> V_56 , V_28 -> V_61 ) ;
V_63:
F_26 ( V_7 , V_28 ) ;
return V_38 ;
}
static int F_27 ( struct V_6 * V_7 ,
struct V_18 * V_19 ,
struct V_27 * V_28 )
{
int V_38 ;
struct V_55 * V_56 ;
V_38 = 0 ;
F_18 ( & V_7 -> V_39 ) ;
if ( V_28 -> V_35 . type == V_45 ) {
V_56 = V_7 -> V_57 . V_58 ( V_7 , V_59 ) ;
if ( V_56 == NULL ) {
V_38 = - V_32 ;
goto V_70;
}
F_26 ( V_7 , V_28 ) ;
} else if ( V_28 -> V_35 . type == V_3 ) {
V_56 = V_7 -> V_57 . V_58 ( V_7 , V_4 ) ;
if ( V_56 == NULL ) {
V_38 = - V_32 ;
goto V_70;
}
V_7 -> V_50 -- ;
F_28 ( V_7 , V_28 -> V_71 ) ;
} else {
F_12 ( L_6 ,
V_28 -> V_35 . type ) ;
V_38 = - V_46 ;
goto V_70;
}
V_38 = V_56 -> V_72 ( V_56 , V_28 -> V_56 ,
V_73 ,
V_74 ,
V_28 -> V_9 , V_28 -> V_27 ) ;
if ( V_38 )
goto V_70;
V_56 -> V_69 ( V_56 , V_28 -> V_56 , V_28 -> V_61 ) ;
F_29 ( & V_28 -> V_47 ) ;
if ( F_20 ( & V_19 -> V_44 ) )
F_14 ( V_7 , V_19 , V_28 ) ;
if ( V_28 -> V_35 . V_48 )
V_7 -> V_49 -- ;
V_7 -> V_40 -- ;
F_12 ( L_3 ,
V_7 -> V_40 ) ;
V_70:
F_24 ( & V_7 -> V_39 ) ;
return V_38 ;
}
static int F_30 ( struct V_6 * V_7 , struct V_27 * V_28 )
{
int V_38 ;
struct V_55 * V_56 ;
bool V_75 = false ;
F_18 ( & V_7 -> V_39 ) ;
V_56 = V_7 -> V_57 . V_58 ( V_7 ,
F_1 ( V_28 -> V_35 . type ) ) ;
if ( ! V_56 ) {
V_38 = - V_32 ;
goto V_43;
}
if ( V_28 -> V_35 . V_48 )
V_75 = true ;
V_38 = V_56 -> V_76 ( V_56 , V_28 -> V_56 , & V_28 -> V_35 ) ;
if ( ( V_28 -> V_35 . V_48 ) && ( ! V_75 ) )
V_7 -> V_49 ++ ;
else if ( ! V_28 -> V_35 . V_48 && V_75 )
V_7 -> V_49 -- ;
if ( V_77 != V_78 )
V_38 = F_31 ( V_7 , false ) ;
V_43:
F_24 ( & V_7 -> V_39 ) ;
return V_38 ;
}
static struct V_55 * F_32 (
struct V_6 * V_7 , enum V_1 type )
{
struct V_55 * V_56 ;
if ( F_33 ( type >= V_79 ) )
return NULL ;
F_12 ( L_7 , type ) ;
V_56 = V_7 -> V_80 [ type ] ;
if ( ! V_56 ) {
V_56 = F_34 ( type , V_7 -> V_12 ) ;
if ( ! V_56 )
F_35 ( L_8 ) ;
V_7 -> V_80 [ type ] = V_56 ;
}
return V_56 ;
}
static int F_36 ( struct V_6 * V_7 ,
struct V_18 * V_19 )
{
struct V_81 * V_82 ;
int V_38 ;
V_82 = F_37 ( sizeof( * V_82 ) , V_83 ) ;
if ( ! V_82 )
return - V_32 ;
V_82 -> V_19 = V_19 ;
F_18 ( & V_7 -> V_39 ) ;
F_23 ( & V_82 -> V_47 , & V_7 -> V_84 ) ;
V_38 = V_7 -> V_85 . V_86 ( V_7 , V_19 ) ;
V_7 -> V_87 ++ ;
F_24 ( & V_7 -> V_39 ) ;
return V_38 ;
}
static int F_38 ( struct V_6 * V_7 ,
struct V_18 * V_19 )
{
int V_38 ;
struct V_81 * V_88 , * V_89 ;
F_12 ( L_9 ,
F_20 ( & V_19 -> V_44 ) ? L_10 : L_11 ) ;
V_38 = 0 ;
F_18 ( & V_7 -> V_39 ) ;
F_39 (cur, next, &dqm->queues, list) {
if ( V_19 == V_88 -> V_19 ) {
F_29 ( & V_88 -> V_47 ) ;
F_40 ( V_88 ) ;
V_7 -> V_87 -- ;
goto V_70;
}
}
V_38 = 1 ;
V_70:
F_24 ( & V_7 -> V_39 ) ;
return V_38 ;
}
static int
F_13 ( struct V_6 * V_7 , unsigned int V_37 ,
unsigned int V_22 )
{
T_1 V_90 ;
V_90 = ( V_37 == 0 ) ? 0 :
( T_1 ) V_37 |
V_91 ;
return V_7 -> V_12 -> V_20 -> F_13 (
V_7 -> V_12 -> V_21 , V_90 ,
V_22 ) ;
}
static void F_41 ( struct V_6 * V_7 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < F_7 ( V_7 ) ; V_10 ++ )
if ( F_2 ( V_7 , 0 , V_10 ) )
V_7 -> V_12 -> V_20 -> F_41 ( V_7 -> V_12 -> V_21 , V_10 ) ;
}
static int F_42 ( struct V_6 * V_7 )
{
int V_9 , V_27 ;
F_12 ( L_12 , F_7 ( V_7 ) ) ;
V_7 -> V_53 = F_43 ( F_7 ( V_7 ) ,
sizeof( unsigned int ) , V_83 ) ;
if ( ! V_7 -> V_53 )
return - V_32 ;
F_44 ( & V_7 -> V_39 ) ;
F_45 ( & V_7 -> V_84 ) ;
V_7 -> V_49 = V_7 -> V_52 = 0 ;
V_7 -> V_50 = 0 ;
for ( V_9 = 0 ; V_9 < F_7 ( V_7 ) ; V_9 ++ ) {
int V_11 = V_9 * F_6 ( V_7 ) ;
for ( V_27 = 0 ; V_27 < F_6 ( V_7 ) ; V_27 ++ )
if ( F_3 ( V_11 + V_27 ,
V_7 -> V_12 -> V_13 . V_16 ) )
V_7 -> V_53 [ V_9 ] |= 1 << V_27 ;
}
V_7 -> V_31 = ( 1 << V_92 ) - 1 ;
V_7 -> V_93 = ( 1 << V_94 ) - 1 ;
return 0 ;
}
static void F_46 ( struct V_6 * V_7 )
{
int V_10 ;
F_33 ( V_7 -> V_49 > 0 || V_7 -> V_87 > 0 ) ;
F_40 ( V_7 -> V_53 ) ;
for ( V_10 = 0 ; V_10 < V_79 ; V_10 ++ )
F_40 ( V_7 -> V_80 [ V_10 ] ) ;
F_47 ( & V_7 -> V_39 ) ;
F_48 ( V_7 -> V_12 , V_7 -> V_95 ) ;
}
static int F_49 ( struct V_6 * V_7 )
{
F_41 ( V_7 ) ;
return 0 ;
}
static int F_50 ( struct V_6 * V_7 )
{
return 0 ;
}
static int F_51 ( struct V_6 * V_7 ,
unsigned int * V_96 )
{
int V_29 ;
if ( V_7 -> V_93 == 0 )
return - V_32 ;
V_29 = F_10 ( ( unsigned long * ) & V_7 -> V_93 ,
V_94 ) ;
F_11 ( V_29 , ( unsigned long * ) & V_7 -> V_93 ) ;
* V_96 = V_29 ;
return 0 ;
}
static void F_28 ( struct V_6 * V_7 ,
unsigned int V_96 )
{
if ( V_96 >= V_94 )
return;
F_15 ( V_96 , ( unsigned long * ) & V_7 -> V_93 ) ;
}
static int F_22 ( struct V_6 * V_7 ,
struct V_27 * V_28 ,
struct V_18 * V_19 )
{
struct V_55 * V_56 ;
int V_38 ;
V_56 = V_7 -> V_57 . V_58 ( V_7 , V_4 ) ;
if ( ! V_56 )
return - V_32 ;
V_38 = F_51 ( V_7 , & V_28 -> V_71 ) ;
if ( V_38 )
return V_38 ;
V_28 -> V_35 . V_96 = V_28 -> V_71 % V_97 ;
V_28 -> V_35 . V_98 = V_28 -> V_71 / V_99 ;
F_12 ( L_13 , V_28 -> V_71 ) ;
F_12 ( L_14 , V_28 -> V_35 . V_96 ) ;
F_12 ( L_15 , V_28 -> V_35 . V_98 ) ;
V_7 -> V_85 . V_100 ( V_7 , V_28 , V_19 ) ;
V_38 = V_56 -> V_60 ( V_56 , & V_28 -> V_56 , & V_28 -> V_61 ,
& V_28 -> V_62 , & V_28 -> V_35 ) ;
if ( V_38 )
goto V_101;
V_38 = V_56 -> V_66 ( V_56 , V_28 -> V_56 , 0 , 0 , & V_28 -> V_35 , NULL ) ;
if ( V_38 )
goto V_68;
return 0 ;
V_68:
V_56 -> V_69 ( V_56 , V_28 -> V_56 , V_28 -> V_61 ) ;
V_101:
F_28 ( V_7 , V_28 -> V_71 ) ;
return V_38 ;
}
static int F_52 ( struct V_6 * V_7 )
{
int V_10 , V_8 ;
struct V_102 V_103 ;
V_103 . V_104 = ( 1 << V_92 ) - 1 ;
V_103 . V_104 <<= V_34 ;
V_103 . V_105 = 0 ;
for ( V_10 = 0 ; V_10 < V_17 ; ++ V_10 ) {
V_8 = ( V_10 / V_7 -> V_12 -> V_13 . V_15 )
/ V_7 -> V_12 -> V_13 . V_14 ;
if ( ! F_3 ( V_10 , V_7 -> V_12 -> V_13 . V_16 ) )
continue;
if ( V_8 > 0 )
continue;
if ( F_33 ( V_10 >= ( sizeof( V_103 . V_105 ) * 8 ) ) ) {
F_35 ( L_16 , V_10 ) ;
break;
}
V_103 . V_105 |= ( 1ull << V_10 ) ;
}
V_103 . V_106 = V_103 . V_107 = V_103 . V_108 =
V_103 . V_109 = 0 ;
F_12 ( L_17
L_18
L_19 ,
V_103 . V_104 , V_103 . V_105 ) ;
return F_53 ( & V_7 -> V_110 , & V_103 ) ;
}
static int F_54 ( struct V_6 * V_7 )
{
int V_38 ;
F_12 ( L_12 , F_7 ( V_7 ) ) ;
F_44 ( & V_7 -> V_39 ) ;
F_45 ( & V_7 -> V_84 ) ;
V_7 -> V_49 = V_7 -> V_87 = 0 ;
V_7 -> V_50 = 0 ;
V_7 -> V_111 = false ;
V_38 = V_7 -> V_85 . V_112 ( V_7 ) ;
if ( V_38 )
F_47 ( & V_7 -> V_39 ) ;
return V_38 ;
}
static int F_55 ( struct V_6 * V_7 )
{
struct V_81 * V_113 ;
int V_38 ;
V_38 = 0 ;
V_38 = F_56 ( & V_7 -> V_110 , V_7 ) ;
if ( V_38 )
goto V_114;
V_38 = F_52 ( V_7 ) ;
if ( V_38 )
goto V_115;
F_12 ( L_20 ) ;
V_38 = F_57 ( V_7 -> V_12 , sizeof( * V_7 -> V_116 ) ,
& V_7 -> V_117 ) ;
if ( V_38 )
goto V_118;
V_7 -> V_116 = V_7 -> V_117 -> V_119 ;
V_7 -> V_120 = V_7 -> V_117 -> V_121 ;
F_41 ( V_7 ) ;
F_58 (node, &dqm->queues, list)
if ( V_113 -> V_19 -> V_122 -> V_36 && V_7 -> V_12 )
F_59 ( V_7 -> V_12 ,
V_113 -> V_19 -> V_122 -> V_36 ) ;
F_31 ( V_7 , true ) ;
return 0 ;
V_118:
V_115:
F_60 ( & V_7 -> V_110 ) ;
V_114:
return V_38 ;
}
static int F_61 ( struct V_6 * V_7 )
{
struct V_81 * V_113 ;
struct V_123 * V_124 ;
F_62 ( V_7 , true , true ) ;
F_58 (node, &dqm->queues, list) {
V_124 = F_63 ( V_113 -> V_19 ) ;
V_124 -> V_125 = false ;
}
F_48 ( V_7 -> V_12 , V_7 -> V_117 ) ;
F_60 ( & V_7 -> V_110 ) ;
return 0 ;
}
static int F_64 ( struct V_6 * V_7 ,
struct V_126 * V_127 ,
struct V_18 * V_19 )
{
F_18 ( & V_7 -> V_39 ) ;
if ( V_7 -> V_40 >= V_41 ) {
F_19 ( L_21 ,
V_7 -> V_40 ) ;
F_24 ( & V_7 -> V_39 ) ;
return - V_42 ;
}
V_7 -> V_40 ++ ;
F_12 ( L_3 ,
V_7 -> V_40 ) ;
F_23 ( & V_127 -> V_47 , & V_19 -> V_128 ) ;
V_7 -> V_49 ++ ;
V_19 -> V_129 = true ;
F_31 ( V_7 , false ) ;
F_24 ( & V_7 -> V_39 ) ;
return 0 ;
}
static void F_65 ( struct V_6 * V_7 ,
struct V_126 * V_127 ,
struct V_18 * V_19 )
{
F_18 ( & V_7 -> V_39 ) ;
F_62 ( V_7 , true , false ) ;
F_29 ( & V_127 -> V_47 ) ;
V_7 -> V_49 -- ;
V_19 -> V_129 = false ;
F_31 ( V_7 , false ) ;
V_7 -> V_40 -- ;
F_12 ( L_3 ,
V_7 -> V_40 ) ;
F_24 ( & V_7 -> V_39 ) ;
}
static void F_66 ( struct V_27 * V_28 )
{
static int V_71 ;
V_28 -> V_71 = V_71 ;
V_71 = ( V_71 + 1 ) % 2 ;
}
static int F_67 ( struct V_6 * V_7 , struct V_27 * V_28 ,
struct V_18 * V_19 , int * F_9 )
{
int V_38 ;
struct V_55 * V_56 ;
V_38 = 0 ;
if ( F_9 )
* F_9 = 0 ;
F_18 ( & V_7 -> V_39 ) ;
if ( V_7 -> V_40 >= V_41 ) {
F_19 ( L_2 ,
V_7 -> V_40 ) ;
V_38 = - V_42 ;
goto V_70;
}
if ( V_28 -> V_35 . type == V_3 )
F_66 ( V_28 ) ;
V_56 = V_7 -> V_57 . V_58 ( V_7 ,
F_1 ( V_28 -> V_35 . type ) ) ;
if ( ! V_56 ) {
V_38 = - V_32 ;
goto V_70;
}
V_7 -> V_85 . V_100 ( V_7 , V_28 , V_19 ) ;
V_38 = V_56 -> V_60 ( V_56 , & V_28 -> V_56 , & V_28 -> V_61 ,
& V_28 -> V_62 , & V_28 -> V_35 ) ;
if ( V_38 )
goto V_70;
F_23 ( & V_28 -> V_47 , & V_19 -> V_44 ) ;
if ( V_28 -> V_35 . V_48 ) {
V_7 -> V_49 ++ ;
V_38 = F_31 ( V_7 , false ) ;
}
if ( V_28 -> V_35 . type == V_3 )
V_7 -> V_50 ++ ;
V_7 -> V_40 ++ ;
F_12 ( L_3 ,
V_7 -> V_40 ) ;
V_70:
F_24 ( & V_7 -> V_39 ) ;
return V_38 ;
}
int F_68 ( unsigned int * V_116 ,
unsigned int V_130 ,
unsigned long V_131 )
{
V_131 += V_132 ;
while ( * V_116 != V_130 ) {
if ( F_69 ( V_132 , V_131 ) ) {
F_35 ( L_22 ) ;
return - V_133 ;
}
F_70 () ;
}
return 0 ;
}
static int F_71 ( struct V_6 * V_7 ,
unsigned int V_134 )
{
return F_72 ( & V_7 -> V_110 , V_3 ,
V_135 , 0 , false ,
V_134 ) ;
}
static int F_62 ( struct V_6 * V_7 ,
bool V_136 , bool V_39 )
{
int V_38 ;
enum V_137 V_138 ;
struct V_123 * V_124 ;
V_38 = 0 ;
if ( V_39 )
F_18 ( & V_7 -> V_39 ) ;
if ( ! V_7 -> V_111 )
goto V_70;
F_12 ( L_23 ,
V_7 -> V_50 ) ;
if ( V_7 -> V_50 > 0 ) {
F_71 ( V_7 , 0 ) ;
F_71 ( V_7 , 1 ) ;
}
V_138 = V_136 ?
V_139 :
V_135 ;
V_38 = F_72 ( & V_7 -> V_110 , V_45 ,
V_138 , 0 , false , 0 ) ;
if ( V_38 )
goto V_70;
* V_7 -> V_116 = V_140 ;
F_73 ( & V_7 -> V_110 , V_7 -> V_120 ,
V_141 ) ;
V_38 = F_68 ( V_7 -> V_116 , V_141 ,
V_74 ) ;
if ( V_38 ) {
V_124 = F_74 ( V_7 -> V_12 ,
F_75 ( V_142 ) ) ;
V_124 -> V_143 = true ;
goto V_70;
}
F_76 ( & V_7 -> V_110 ) ;
V_7 -> V_111 = false ;
V_70:
if ( V_39 )
F_24 ( & V_7 -> V_39 ) ;
return V_38 ;
}
static int F_31 ( struct V_6 * V_7 , bool V_39 )
{
int V_38 ;
if ( V_39 )
F_18 ( & V_7 -> V_39 ) ;
V_38 = F_62 ( V_7 , false , false ) ;
if ( V_38 ) {
F_35 ( L_24 ) ;
goto V_70;
}
if ( V_7 -> V_49 <= 0 || V_7 -> V_87 <= 0 ) {
V_38 = 0 ;
goto V_70;
}
if ( V_7 -> V_111 ) {
V_38 = 0 ;
goto V_70;
}
V_38 = F_77 ( & V_7 -> V_110 , & V_7 -> V_84 ) ;
if ( V_38 ) {
F_35 ( L_25 ) ;
goto V_70;
}
V_7 -> V_111 = true ;
V_70:
if ( V_39 )
F_24 ( & V_7 -> V_39 ) ;
return V_38 ;
}
static int F_78 ( struct V_6 * V_7 ,
struct V_18 * V_19 ,
struct V_27 * V_28 )
{
int V_38 ;
struct V_55 * V_56 ;
bool V_144 ;
V_144 = false ;
V_38 = 0 ;
F_18 ( & V_7 -> V_39 ) ;
if ( V_19 -> V_129 ) {
V_38 = - V_54 ;
goto V_145;
}
V_56 = V_7 -> V_57 . V_58 ( V_7 ,
F_1 ( V_28 -> V_35 . type ) ) ;
if ( ! V_56 ) {
V_38 = - V_32 ;
goto V_146;
}
if ( V_28 -> V_35 . type == V_3 )
V_7 -> V_50 -- ;
F_29 ( & V_28 -> V_47 ) ;
if ( V_28 -> V_35 . V_48 )
V_7 -> V_49 -- ;
F_31 ( V_7 , false ) ;
V_56 -> V_69 ( V_56 , V_28 -> V_56 , V_28 -> V_61 ) ;
V_7 -> V_40 -- ;
F_12 ( L_3 ,
V_7 -> V_40 ) ;
F_24 ( & V_7 -> V_39 ) ;
return 0 ;
V_146:
V_145:
F_24 ( & V_7 -> V_39 ) ;
return V_38 ;
}
static bool F_79 ( struct V_6 * V_7 ,
struct V_18 * V_19 ,
enum V_147 V_148 ,
enum V_147 V_149 ,
void T_2 * V_150 ,
T_3 V_151 )
{
bool V_38 ;
F_18 ( & V_7 -> V_39 ) ;
if ( V_151 == 0 ) {
V_19 -> V_24 = 1 ;
V_19 -> V_25 = 0 ;
} else {
T_3 V_152 = ( V_153 ) V_150 ;
T_3 V_154 = V_152 + V_151 - 1 ;
if ( V_154 <= V_152 || ( V_152 & V_155 ) != 0 ||
( V_154 & V_155 ) != V_156 ) {
V_38 = false ;
goto V_70;
}
V_19 -> V_24 = V_152 >> 16 ;
V_19 -> V_25 = V_154 >> 16 ;
}
V_38 = V_7 -> V_85 . F_79 (
V_7 ,
V_19 ,
V_148 ,
V_149 ,
V_150 ,
V_151 ) ;
if ( ( V_77 == V_78 ) && ( V_19 -> V_22 != 0 ) )
F_8 ( V_7 , V_19 ) ;
F_12 ( L_26 ,
V_19 -> V_23 , V_19 -> V_24 ,
V_19 -> V_25 ) ;
V_70:
F_24 ( & V_7 -> V_39 ) ;
return V_38 ;
}
struct V_6 * F_80 ( struct V_157 * V_12 )
{
struct V_6 * V_7 ;
F_12 ( L_27 ) ;
V_7 = F_37 ( sizeof( * V_7 ) , V_83 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_12 = V_12 ;
switch ( V_77 ) {
case V_158 :
case V_159 :
V_7 -> V_57 . V_160 = F_67 ;
V_7 -> V_57 . V_112 = F_54 ;
V_7 -> V_57 . V_161 = F_55 ;
V_7 -> V_57 . V_162 = F_61 ;
V_7 -> V_57 . V_163 = F_78 ;
V_7 -> V_57 . F_30 = F_30 ;
V_7 -> V_57 . V_58 = F_32 ;
V_7 -> V_57 . V_86 = F_36 ;
V_7 -> V_57 . V_164 = F_38 ;
V_7 -> V_57 . V_165 = F_46 ;
V_7 -> V_57 . V_166 = F_64 ;
V_7 -> V_57 . V_167 = F_65 ;
V_7 -> V_57 . F_79 = F_79 ;
break;
case V_78 :
V_7 -> V_57 . V_161 = F_49 ;
V_7 -> V_57 . V_162 = F_50 ;
V_7 -> V_57 . V_160 = F_16 ;
V_7 -> V_57 . V_163 = F_27 ;
V_7 -> V_57 . F_30 = F_30 ;
V_7 -> V_57 . V_58 = F_32 ;
V_7 -> V_57 . V_86 = F_36 ;
V_7 -> V_57 . V_164 = F_38 ;
V_7 -> V_57 . V_112 = F_42 ;
V_7 -> V_57 . V_165 = F_46 ;
V_7 -> V_57 . F_79 = F_79 ;
break;
default:
F_35 ( L_28 , V_77 ) ;
goto V_168;
}
switch ( V_12 -> V_169 -> V_170 ) {
case V_171 :
F_81 ( & V_7 -> V_85 ) ;
break;
case V_172 :
F_82 ( & V_7 -> V_85 ) ;
break;
}
if ( ! V_7 -> V_57 . V_112 ( V_7 ) )
return V_7 ;
V_168:
F_40 ( V_7 ) ;
return NULL ;
}
void F_83 ( struct V_6 * V_7 )
{
V_7 -> V_57 . V_165 ( V_7 ) ;
F_40 ( V_7 ) ;
}
