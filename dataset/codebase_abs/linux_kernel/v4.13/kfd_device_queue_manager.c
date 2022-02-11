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
F_5 ( ! V_7 || ! V_7 -> V_12 ) ;
return F_6 ( V_7 -> V_12 -> V_13 . V_16 ,
V_17 ) ;
}
unsigned int F_7 ( struct V_6 * V_7 )
{
F_5 ( ! V_7 || ! V_7 -> V_12 ) ;
return V_7 -> V_12 -> V_13 . V_15 ;
}
unsigned int F_8 ( struct V_6 * V_7 )
{
F_5 ( ! V_7 || ! V_7 -> V_12 ) ;
return V_7 -> V_12 -> V_13 . V_14 ;
}
void F_9 ( struct V_6 * V_7 ,
struct V_18 * V_19 )
{
return V_7 -> V_12 -> V_20 -> F_9 (
V_7 -> V_12 -> V_21 , V_19 -> V_22 ,
V_19 -> V_23 ,
V_19 -> V_24 ,
V_19 -> V_25 ,
V_19 -> V_26 ) ;
}
static int F_10 ( struct V_6 * V_7 ,
struct V_18 * V_19 ,
struct V_27 * V_28 )
{
int V_29 , V_30 ;
if ( V_7 -> V_31 == 0 )
return - V_32 ;
V_29 = F_11 ( ( unsigned long * ) & V_7 -> V_31 , V_33 ) ;
F_12 ( V_29 , ( unsigned long * ) & V_7 -> V_31 ) ;
V_30 = V_29 + V_34 ;
F_13 ( L_1 , V_30 ) ;
V_19 -> V_22 = V_30 ;
V_28 -> V_35 . V_22 = V_30 ;
F_14 ( V_7 , V_28 -> V_36 -> V_37 , V_28 -> V_35 . V_22 ) ;
F_9 ( V_7 , V_19 ) ;
return 0 ;
}
static void F_15 ( struct V_6 * V_7 ,
struct V_18 * V_19 ,
struct V_27 * V_28 )
{
int V_29 = V_19 -> V_22 - V_34 ;
F_14 ( V_7 , 0 , V_19 -> V_22 ) ;
F_16 ( V_29 , ( unsigned long * ) & V_7 -> V_31 ) ;
V_19 -> V_22 = 0 ;
V_28 -> V_35 . V_22 = 0 ;
}
static int F_17 ( struct V_6 * V_7 ,
struct V_27 * V_28 ,
struct V_18 * V_19 ,
int * V_30 )
{
int V_38 ;
F_5 ( ! V_7 || ! V_28 || ! V_19 || ! V_30 ) ;
F_13 ( L_2 , V_39 ) ;
F_18 ( V_28 ) ;
F_19 ( & V_7 -> V_40 ) ;
if ( V_7 -> V_41 >= V_42 ) {
F_20 ( L_3 ,
V_7 -> V_41 ) ;
F_21 ( & V_7 -> V_40 ) ;
return - V_43 ;
}
if ( F_22 ( & V_19 -> V_44 ) ) {
V_38 = F_10 ( V_7 , V_19 , V_28 ) ;
if ( V_38 != 0 ) {
F_21 ( & V_7 -> V_40 ) ;
return V_38 ;
}
}
* V_30 = V_19 -> V_22 ;
V_28 -> V_35 . V_22 = V_19 -> V_22 ;
if ( V_28 -> V_35 . type == V_45 )
V_38 = F_23 ( V_7 , V_28 , V_19 ) ;
if ( V_28 -> V_35 . type == V_3 )
V_38 = F_24 ( V_7 , V_28 , V_19 ) ;
if ( V_38 != 0 ) {
if ( F_22 ( & V_19 -> V_44 ) ) {
F_15 ( V_7 , V_19 , V_28 ) ;
* V_30 = 0 ;
}
F_21 ( & V_7 -> V_40 ) ;
return V_38 ;
}
F_25 ( & V_28 -> V_46 , & V_19 -> V_44 ) ;
if ( V_28 -> V_35 . V_47 )
V_7 -> V_48 ++ ;
if ( V_28 -> V_35 . type == V_3 )
V_7 -> V_49 ++ ;
V_7 -> V_41 ++ ;
F_13 ( L_4 ,
V_7 -> V_41 ) ;
F_21 ( & V_7 -> V_40 ) ;
return 0 ;
}
static int F_26 ( struct V_6 * V_7 , struct V_27 * V_28 )
{
bool V_50 ;
int V_9 , V_29 , V_10 ;
V_50 = false ;
for ( V_9 = V_7 -> V_51 , V_10 = 0 ; V_10 < F_8 ( V_7 ) ;
V_9 = ( ( V_9 + 1 ) % F_8 ( V_7 ) ) , ++ V_10 ) {
if ( ! F_2 ( V_7 , 0 , V_9 ) )
continue;
if ( V_7 -> V_52 [ V_9 ] != 0 ) {
V_29 = F_11 (
( unsigned long * ) & V_7 -> V_52 [ V_9 ] ,
F_7 ( V_7 ) ) ;
F_12 ( V_29 ,
( unsigned long * ) & V_7 -> V_52 [ V_9 ] ) ;
V_28 -> V_9 = V_9 ;
V_28 -> V_27 = V_29 ;
V_50 = true ;
break;
}
}
if ( ! V_50 )
return - V_53 ;
F_13 ( L_5 ,
V_39 , V_28 -> V_9 , V_28 -> V_27 ) ;
V_7 -> V_51 = ( V_9 + 1 ) % F_8 ( V_7 ) ;
return 0 ;
}
static inline void F_27 ( struct V_6 * V_7 ,
struct V_27 * V_28 )
{
F_16 ( V_28 -> V_27 , ( unsigned long * ) & V_7 -> V_52 [ V_28 -> V_9 ] ) ;
}
static int F_23 ( struct V_6 * V_7 ,
struct V_27 * V_28 ,
struct V_18 * V_19 )
{
int V_38 ;
struct V_54 * V_55 ;
F_5 ( ! V_7 || ! V_28 || ! V_19 ) ;
V_55 = V_7 -> V_56 . V_57 ( V_7 , V_58 ) ;
if ( V_55 == NULL )
return - V_32 ;
V_38 = F_26 ( V_7 , V_28 ) ;
if ( V_38 != 0 )
return V_38 ;
V_38 = V_55 -> V_59 ( V_55 , & V_28 -> V_55 , & V_28 -> V_60 ,
& V_28 -> V_61 , & V_28 -> V_35 ) ;
if ( V_38 != 0 ) {
F_27 ( V_7 , V_28 ) ;
return V_38 ;
}
F_13 ( L_6 ,
V_28 -> V_9 ,
V_28 -> V_27 ) ;
V_38 = V_55 -> V_62 ( V_55 , V_28 -> V_55 , V_28 -> V_9 ,
V_28 -> V_27 , ( V_63 V_64 * ) V_28 -> V_35 . V_65 ) ;
if ( V_38 != 0 ) {
F_27 ( V_7 , V_28 ) ;
V_55 -> V_66 ( V_55 , V_28 -> V_55 , V_28 -> V_60 ) ;
return V_38 ;
}
return 0 ;
}
static int F_28 ( struct V_6 * V_7 ,
struct V_18 * V_19 ,
struct V_27 * V_28 )
{
int V_38 ;
struct V_54 * V_55 ;
F_5 ( ! V_7 || ! V_28 || ! V_28 -> V_55 || ! V_19 ) ;
V_38 = 0 ;
F_13 ( L_7 , V_39 ) ;
F_19 ( & V_7 -> V_40 ) ;
if ( V_28 -> V_35 . type == V_45 ) {
V_55 = V_7 -> V_56 . V_57 ( V_7 , V_58 ) ;
if ( V_55 == NULL ) {
V_38 = - V_32 ;
goto V_67;
}
F_27 ( V_7 , V_28 ) ;
} else if ( V_28 -> V_35 . type == V_3 ) {
V_55 = V_7 -> V_56 . V_57 ( V_7 , V_4 ) ;
if ( V_55 == NULL ) {
V_38 = - V_32 ;
goto V_67;
}
V_7 -> V_49 -- ;
F_29 ( V_7 , V_28 -> V_68 ) ;
} else {
F_13 ( L_8 ,
V_28 -> V_35 . type ) ;
V_38 = - V_69 ;
goto V_67;
}
V_38 = V_55 -> V_70 ( V_55 , V_28 -> V_55 ,
V_71 ,
V_72 ,
V_28 -> V_9 , V_28 -> V_27 ) ;
if ( V_38 != 0 )
goto V_67;
V_55 -> V_66 ( V_55 , V_28 -> V_55 , V_28 -> V_60 ) ;
F_30 ( & V_28 -> V_46 ) ;
if ( F_22 ( & V_19 -> V_44 ) )
F_15 ( V_7 , V_19 , V_28 ) ;
if ( V_28 -> V_35 . V_47 )
V_7 -> V_48 -- ;
V_7 -> V_41 -- ;
F_13 ( L_4 ,
V_7 -> V_41 ) ;
V_67:
F_21 ( & V_7 -> V_40 ) ;
return V_38 ;
}
static int F_31 ( struct V_6 * V_7 , struct V_27 * V_28 )
{
int V_38 ;
struct V_54 * V_55 ;
bool V_73 = false ;
F_5 ( ! V_7 || ! V_28 || ! V_28 -> V_55 ) ;
F_19 ( & V_7 -> V_40 ) ;
V_55 = V_7 -> V_56 . V_57 ( V_7 ,
F_1 ( V_28 -> V_35 . type ) ) ;
if ( V_55 == NULL ) {
F_21 ( & V_7 -> V_40 ) ;
return - V_32 ;
}
if ( V_28 -> V_35 . V_47 )
V_73 = true ;
V_38 = V_55 -> V_74 ( V_55 , V_28 -> V_55 , & V_28 -> V_35 ) ;
if ( ( V_28 -> V_35 . V_47 ) && ( ! V_73 ) )
V_7 -> V_48 ++ ;
else if ( ( ! V_28 -> V_35 . V_47 ) && ( V_73 ) )
V_7 -> V_48 -- ;
if ( V_75 != V_76 )
V_38 = F_32 ( V_7 , false ) ;
F_21 ( & V_7 -> V_40 ) ;
return V_38 ;
}
static struct V_54 * F_33 (
struct V_6 * V_7 , enum V_1 type )
{
struct V_54 * V_55 ;
F_5 ( ! V_7 || type >= V_77 ) ;
F_13 ( L_9 , V_39 , type ) ;
V_55 = V_7 -> V_78 [ type ] ;
if ( ! V_55 ) {
V_55 = F_34 ( type , V_7 -> V_12 ) ;
if ( V_55 == NULL )
F_35 ( L_10 ) ;
V_7 -> V_78 [ type ] = V_55 ;
}
return V_55 ;
}
static int F_36 ( struct V_6 * V_7 ,
struct V_18 * V_19 )
{
struct V_79 * V_80 ;
int V_38 ;
F_5 ( ! V_7 || ! V_19 ) ;
F_13 ( L_2 , V_39 ) ;
V_80 = F_37 ( sizeof( struct V_79 ) , V_81 ) ;
if ( ! V_80 )
return - V_32 ;
V_80 -> V_19 = V_19 ;
F_19 ( & V_7 -> V_40 ) ;
F_25 ( & V_80 -> V_46 , & V_7 -> V_82 ) ;
V_38 = V_7 -> V_83 . V_84 ( V_7 , V_19 ) ;
V_7 -> V_85 ++ ;
F_21 ( & V_7 -> V_40 ) ;
return V_38 ;
}
static int F_38 ( struct V_6 * V_7 ,
struct V_18 * V_19 )
{
int V_38 ;
struct V_79 * V_86 , * V_87 ;
F_5 ( ! V_7 || ! V_19 ) ;
F_13 ( L_11 , V_39 ) ;
F_13 ( L_12 ,
F_22 ( & V_19 -> V_44 ) ? L_13 : L_14 ) ;
V_38 = 0 ;
F_19 ( & V_7 -> V_40 ) ;
F_39 (cur, next, &dqm->queues, list) {
if ( V_19 == V_86 -> V_19 ) {
F_30 ( & V_86 -> V_46 ) ;
F_40 ( V_86 ) ;
V_7 -> V_85 -- ;
goto V_67;
}
}
V_38 = 1 ;
V_67:
F_21 ( & V_7 -> V_40 ) ;
return V_38 ;
}
static int
F_14 ( struct V_6 * V_7 , unsigned int V_37 ,
unsigned int V_22 )
{
V_63 V_88 ;
V_88 = ( V_37 == 0 ) ? 0 :
( V_63 ) V_37 |
V_89 ;
return V_7 -> V_12 -> V_20 -> F_14 (
V_7 -> V_12 -> V_21 , V_88 ,
V_22 ) ;
}
static void F_41 ( struct V_6 * V_7 )
{
unsigned int V_10 ;
F_5 ( V_7 == NULL ) ;
for ( V_10 = 0 ; V_10 < F_8 ( V_7 ) ; V_10 ++ )
if ( F_2 ( V_7 , 0 , V_10 ) )
V_7 -> V_12 -> V_20 -> F_41 ( V_7 -> V_12 -> V_21 , V_10 ) ;
}
static int F_42 ( struct V_6 * V_7 )
{
int V_38 = 0 ;
F_5 ( ! V_7 ) ;
F_13 ( L_15 , V_39 ) ;
return V_38 ;
}
static int F_43 ( struct V_6 * V_7 )
{
int V_10 ;
F_5 ( ! V_7 ) ;
F_13 ( L_16 ,
V_39 , F_8 ( V_7 ) ) ;
F_44 ( & V_7 -> V_40 ) ;
F_45 ( & V_7 -> V_82 ) ;
V_7 -> V_48 = V_7 -> V_51 = 0 ;
V_7 -> V_49 = 0 ;
V_7 -> V_52 = F_46 ( F_8 ( V_7 ) ,
sizeof( unsigned int ) , V_81 ) ;
if ( ! V_7 -> V_52 ) {
F_47 ( & V_7 -> V_40 ) ;
return - V_32 ;
}
for ( V_10 = 0 ; V_10 < F_8 ( V_7 ) ; V_10 ++ )
V_7 -> V_52 [ V_10 ] = ( 1 << F_7 ( V_7 ) ) - 1 ;
V_7 -> V_31 = ( 1 << V_90 ) - 1 ;
V_7 -> V_91 = ( 1 << V_92 ) - 1 ;
F_42 ( V_7 ) ;
return 0 ;
}
static void F_48 ( struct V_6 * V_7 )
{
int V_10 ;
F_5 ( ! V_7 ) ;
F_5 ( V_7 -> V_48 > 0 || V_7 -> V_85 > 0 ) ;
F_40 ( V_7 -> V_52 ) ;
for ( V_10 = 0 ; V_10 < V_77 ; V_10 ++ )
F_40 ( V_7 -> V_78 [ V_10 ] ) ;
F_47 ( & V_7 -> V_40 ) ;
F_49 ( V_7 -> V_12 , V_7 -> V_93 ) ;
}
static int F_50 ( struct V_6 * V_7 )
{
F_41 ( V_7 ) ;
return 0 ;
}
static int F_51 ( struct V_6 * V_7 )
{
return 0 ;
}
static int F_52 ( struct V_6 * V_7 ,
unsigned int * V_94 )
{
int V_29 ;
if ( V_7 -> V_91 == 0 )
return - V_32 ;
V_29 = F_11 ( ( unsigned long * ) & V_7 -> V_91 ,
V_92 ) ;
F_12 ( V_29 , ( unsigned long * ) & V_7 -> V_91 ) ;
* V_94 = V_29 ;
return 0 ;
}
static void F_29 ( struct V_6 * V_7 ,
unsigned int V_94 )
{
if ( V_94 >= V_92 )
return;
F_16 ( V_94 , ( unsigned long * ) & V_7 -> V_91 ) ;
}
static int F_24 ( struct V_6 * V_7 ,
struct V_27 * V_28 ,
struct V_18 * V_19 )
{
struct V_54 * V_55 ;
int V_38 ;
V_55 = V_7 -> V_56 . V_57 ( V_7 , V_4 ) ;
if ( ! V_55 )
return - V_32 ;
V_38 = F_52 ( V_7 , & V_28 -> V_68 ) ;
if ( V_38 != 0 )
return V_38 ;
V_28 -> V_35 . V_94 = V_28 -> V_68 % V_95 ;
V_28 -> V_35 . V_96 = V_28 -> V_68 / V_97 ;
F_13 ( L_17 , V_28 -> V_68 ) ;
F_13 ( L_18 , V_28 -> V_35 . V_94 ) ;
F_13 ( L_19 , V_28 -> V_35 . V_96 ) ;
V_7 -> V_83 . V_98 ( V_7 , V_28 , V_19 ) ;
V_38 = V_55 -> V_59 ( V_55 , & V_28 -> V_55 , & V_28 -> V_60 ,
& V_28 -> V_61 , & V_28 -> V_35 ) ;
if ( V_38 != 0 ) {
F_29 ( V_7 , V_28 -> V_68 ) ;
return V_38 ;
}
V_38 = V_55 -> V_62 ( V_55 , V_28 -> V_55 , 0 ,
0 , NULL ) ;
if ( V_38 != 0 ) {
F_29 ( V_7 , V_28 -> V_68 ) ;
V_55 -> V_66 ( V_55 , V_28 -> V_55 , V_28 -> V_60 ) ;
return V_38 ;
}
return 0 ;
}
static int F_53 ( struct V_6 * V_7 )
{
int V_10 , V_8 ;
struct V_99 V_100 ;
F_5 ( ! V_7 ) ;
F_13 ( L_2 , V_39 ) ;
V_100 . V_101 = ( 1 << V_90 ) - 1 ;
V_100 . V_101 <<= V_34 ;
V_100 . V_102 = 0 ;
for ( V_10 = 0 ; V_10 < V_17 ; ++ V_10 ) {
V_8 = ( V_10 / V_7 -> V_12 -> V_13 . V_15 )
/ V_7 -> V_12 -> V_13 . V_14 ;
if ( ! F_3 ( V_10 , V_7 -> V_12 -> V_13 . V_16 ) )
continue;
if ( V_8 > 0 )
continue;
if ( F_54 ( V_10 > ( sizeof( V_100 . V_102 ) * 8 ) ) ) {
F_35 ( L_20 , V_10 ) ;
break;
}
V_100 . V_102 |= ( 1ull << V_10 ) ;
}
V_100 . V_103 = V_100 . V_104 = V_100 . V_105 =
V_100 . V_106 = 0 ;
F_13 ( L_21
L_22
L_23 ,
V_100 . V_101 , V_100 . V_102 ) ;
return F_55 ( & V_7 -> V_107 , & V_100 ) ;
}
static int F_56 ( struct V_6 * V_7 )
{
int V_38 ;
F_5 ( ! V_7 ) ;
F_13 ( L_16 ,
V_39 , F_8 ( V_7 ) ) ;
F_44 ( & V_7 -> V_40 ) ;
F_45 ( & V_7 -> V_82 ) ;
V_7 -> V_48 = V_7 -> V_85 = 0 ;
V_7 -> V_49 = 0 ;
V_7 -> V_108 = false ;
V_38 = V_7 -> V_83 . V_109 ( V_7 ) ;
if ( V_38 != 0 )
goto V_110;
return 0 ;
V_110:
F_47 ( & V_7 -> V_40 ) ;
return V_38 ;
}
static int F_57 ( struct V_6 * V_7 )
{
struct V_79 * V_111 ;
int V_38 ;
F_5 ( ! V_7 ) ;
V_38 = 0 ;
V_38 = F_58 ( & V_7 -> V_107 , V_7 ) ;
if ( V_38 != 0 )
goto V_112;
V_38 = F_53 ( V_7 ) ;
if ( V_38 != 0 )
goto V_113;
F_13 ( L_24 ) ;
V_38 = F_59 ( V_7 -> V_12 , sizeof( * V_7 -> V_114 ) ,
& V_7 -> V_115 ) ;
if ( V_38 != 0 )
goto V_116;
V_7 -> V_114 = V_7 -> V_115 -> V_117 ;
V_7 -> V_118 = V_7 -> V_115 -> V_119 ;
F_41 ( V_7 ) ;
F_60 (node, &dqm->queues, list)
if ( V_111 -> V_19 -> V_120 -> V_36 && V_7 -> V_12 )
F_61 ( V_7 -> V_12 ,
V_111 -> V_19 -> V_120 -> V_36 ) ;
F_32 ( V_7 , true ) ;
return 0 ;
V_116:
V_113:
F_62 ( & V_7 -> V_107 ) ;
V_112:
return V_38 ;
}
static int F_63 ( struct V_6 * V_7 )
{
struct V_79 * V_111 ;
struct V_121 * V_122 ;
F_5 ( ! V_7 ) ;
F_64 ( V_7 , true , true ) ;
F_60 (node, &dqm->queues, list) {
V_122 = F_65 ( V_111 -> V_19 ) ;
V_122 -> V_123 = false ;
}
F_49 ( V_7 -> V_12 , V_7 -> V_115 ) ;
F_62 ( & V_7 -> V_107 ) ;
return 0 ;
}
static int F_66 ( struct V_6 * V_7 ,
struct V_124 * V_125 ,
struct V_18 * V_19 )
{
F_5 ( ! V_7 || ! V_125 || ! V_19 ) ;
F_13 ( L_2 , V_39 ) ;
F_19 ( & V_7 -> V_40 ) ;
if ( V_7 -> V_41 >= V_42 ) {
F_20 ( L_25 ,
V_7 -> V_41 ) ;
F_21 ( & V_7 -> V_40 ) ;
return - V_43 ;
}
V_7 -> V_41 ++ ;
F_13 ( L_4 ,
V_7 -> V_41 ) ;
F_25 ( & V_125 -> V_46 , & V_19 -> V_126 ) ;
V_7 -> V_48 ++ ;
V_19 -> V_127 = true ;
F_32 ( V_7 , false ) ;
F_21 ( & V_7 -> V_40 ) ;
return 0 ;
}
static void F_67 ( struct V_6 * V_7 ,
struct V_124 * V_125 ,
struct V_18 * V_19 )
{
F_5 ( ! V_7 || ! V_125 ) ;
F_13 ( L_15 , V_39 ) ;
F_19 ( & V_7 -> V_40 ) ;
F_64 ( V_7 , true , false ) ;
F_30 ( & V_125 -> V_46 ) ;
V_7 -> V_48 -- ;
V_19 -> V_127 = false ;
F_32 ( V_7 , false ) ;
V_7 -> V_41 -- ;
F_13 ( L_4 ,
V_7 -> V_41 ) ;
F_21 ( & V_7 -> V_40 ) ;
}
static void F_68 ( struct V_27 * V_28 )
{
static int V_68 ;
V_28 -> V_68 = V_68 ;
V_68 = ( V_68 + 1 ) % 2 ;
}
static int F_69 ( struct V_6 * V_7 , struct V_27 * V_28 ,
struct V_18 * V_19 , int * F_10 )
{
int V_38 ;
struct V_54 * V_55 ;
F_5 ( ! V_7 || ! V_28 || ! V_19 ) ;
V_38 = 0 ;
if ( F_10 )
* F_10 = 0 ;
F_19 ( & V_7 -> V_40 ) ;
if ( V_7 -> V_41 >= V_42 ) {
F_20 ( L_3 ,
V_7 -> V_41 ) ;
V_38 = - V_43 ;
goto V_67;
}
if ( V_28 -> V_35 . type == V_3 )
F_68 ( V_28 ) ;
V_55 = V_7 -> V_56 . V_57 ( V_7 ,
F_1 ( V_28 -> V_35 . type ) ) ;
if ( V_55 == NULL ) {
F_21 ( & V_7 -> V_40 ) ;
return - V_32 ;
}
V_7 -> V_83 . V_98 ( V_7 , V_28 , V_19 ) ;
V_38 = V_55 -> V_59 ( V_55 , & V_28 -> V_55 , & V_28 -> V_60 ,
& V_28 -> V_61 , & V_28 -> V_35 ) ;
if ( V_38 != 0 )
goto V_67;
F_25 ( & V_28 -> V_46 , & V_19 -> V_44 ) ;
if ( V_28 -> V_35 . V_47 ) {
V_7 -> V_48 ++ ;
V_38 = F_32 ( V_7 , false ) ;
}
if ( V_28 -> V_35 . type == V_3 )
V_7 -> V_49 ++ ;
V_7 -> V_41 ++ ;
F_13 ( L_4 ,
V_7 -> V_41 ) ;
V_67:
F_21 ( & V_7 -> V_40 ) ;
return V_38 ;
}
int F_70 ( unsigned int * V_114 ,
unsigned int V_128 ,
unsigned long V_129 )
{
F_5 ( ! V_114 ) ;
V_129 += V_130 ;
while ( * V_114 != V_128 ) {
if ( F_71 ( V_130 , V_129 ) ) {
F_35 ( L_26 ) ;
return - V_131 ;
}
F_72 () ;
}
return 0 ;
}
static int F_73 ( struct V_6 * V_7 ,
unsigned int V_132 )
{
return F_74 ( & V_7 -> V_107 , V_3 ,
V_133 , 0 , false ,
V_132 ) ;
}
static int F_64 ( struct V_6 * V_7 ,
bool V_134 , bool V_40 )
{
int V_38 ;
enum V_135 V_136 ;
struct V_121 * V_122 ;
F_5 ( ! V_7 ) ;
V_38 = 0 ;
if ( V_40 )
F_19 ( & V_7 -> V_40 ) ;
if ( ! V_7 -> V_108 )
goto V_67;
F_13 ( L_27 ,
V_7 -> V_49 ) ;
if ( V_7 -> V_49 > 0 ) {
F_73 ( V_7 , 0 ) ;
F_73 ( V_7 , 1 ) ;
}
V_136 = V_134 ?
V_137 :
V_133 ;
V_38 = F_74 ( & V_7 -> V_107 , V_45 ,
V_136 , 0 , false , 0 ) ;
if ( V_38 != 0 )
goto V_67;
* V_7 -> V_114 = V_138 ;
F_75 ( & V_7 -> V_107 , V_7 -> V_118 ,
V_139 ) ;
V_38 = F_70 ( V_7 -> V_114 , V_139 ,
V_72 ) ;
if ( V_38 != 0 ) {
V_122 = F_76 ( V_7 -> V_12 ,
F_77 ( V_140 ) ) ;
V_122 -> V_141 = true ;
goto V_67;
}
F_78 ( & V_7 -> V_107 ) ;
V_7 -> V_108 = false ;
V_67:
if ( V_40 )
F_21 ( & V_7 -> V_40 ) ;
return V_38 ;
}
static int F_32 ( struct V_6 * V_7 , bool V_40 )
{
int V_38 ;
F_5 ( ! V_7 ) ;
if ( V_40 )
F_19 ( & V_7 -> V_40 ) ;
V_38 = F_64 ( V_7 , false , false ) ;
if ( V_38 != 0 ) {
F_35 ( L_28 ) ;
goto V_67;
}
if ( V_7 -> V_48 <= 0 || V_7 -> V_85 <= 0 ) {
V_38 = 0 ;
goto V_67;
}
if ( V_7 -> V_108 ) {
V_38 = 0 ;
goto V_67;
}
V_38 = F_79 ( & V_7 -> V_107 , & V_7 -> V_82 ) ;
if ( V_38 != 0 ) {
F_35 ( L_29 ) ;
goto V_67;
}
V_7 -> V_108 = true ;
V_67:
if ( V_40 )
F_21 ( & V_7 -> V_40 ) ;
return V_38 ;
}
static int F_80 ( struct V_6 * V_7 ,
struct V_18 * V_19 ,
struct V_27 * V_28 )
{
int V_38 ;
struct V_54 * V_55 ;
bool V_142 ;
F_5 ( ! V_7 || ! V_19 || ! V_28 ) ;
V_142 = false ;
V_38 = 0 ;
F_19 ( & V_7 -> V_40 ) ;
if ( V_19 -> V_127 ) {
V_38 = - V_53 ;
goto V_143;
}
V_55 = V_7 -> V_56 . V_57 ( V_7 ,
F_1 ( V_28 -> V_35 . type ) ) ;
if ( ! V_55 ) {
V_38 = - V_32 ;
goto V_144;
}
if ( V_28 -> V_35 . type == V_3 )
V_7 -> V_49 -- ;
F_30 ( & V_28 -> V_46 ) ;
if ( V_28 -> V_35 . V_47 )
V_7 -> V_48 -- ;
F_32 ( V_7 , false ) ;
V_55 -> V_66 ( V_55 , V_28 -> V_55 , V_28 -> V_60 ) ;
V_7 -> V_41 -- ;
F_13 ( L_4 ,
V_7 -> V_41 ) ;
F_21 ( & V_7 -> V_40 ) ;
return 0 ;
V_144:
V_143:
F_21 ( & V_7 -> V_40 ) ;
return V_38 ;
}
static bool F_81 ( struct V_6 * V_7 ,
struct V_18 * V_19 ,
enum V_145 V_146 ,
enum V_145 V_147 ,
void V_64 * V_148 ,
T_1 V_149 )
{
bool V_38 ;
F_13 ( L_2 , V_39 ) ;
F_19 ( & V_7 -> V_40 ) ;
if ( V_149 == 0 ) {
V_19 -> V_24 = 1 ;
V_19 -> V_25 = 0 ;
} else {
T_1 V_150 = ( V_151 ) V_148 ;
T_1 V_152 = V_150 + V_149 - 1 ;
if ( V_152 <= V_150 )
goto V_67;
if ( ( V_150 & V_153 ) != 0 )
goto V_67;
if ( ( V_152 & V_153 ) != V_154 )
goto V_67;
V_19 -> V_24 = V_150 >> 16 ;
V_19 -> V_25 = V_152 >> 16 ;
}
V_38 = V_7 -> V_83 . F_81 (
V_7 ,
V_19 ,
V_146 ,
V_147 ,
V_148 ,
V_149 ) ;
if ( ( V_75 == V_76 ) && ( V_19 -> V_22 != 0 ) )
F_9 ( V_7 , V_19 ) ;
F_13 ( L_30 ,
V_19 -> V_23 , V_19 -> V_24 ,
V_19 -> V_25 ) ;
F_21 ( & V_7 -> V_40 ) ;
return V_38 ;
V_67:
F_21 ( & V_7 -> V_40 ) ;
return false ;
}
struct V_6 * F_82 ( struct V_155 * V_12 )
{
struct V_6 * V_7 ;
F_5 ( ! V_12 ) ;
F_13 ( L_31 ) ;
V_7 = F_37 ( sizeof( struct V_6 ) , V_81 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_12 = V_12 ;
switch ( V_75 ) {
case V_156 :
case V_157 :
V_7 -> V_56 . V_158 = F_69 ;
V_7 -> V_56 . V_109 = F_56 ;
V_7 -> V_56 . V_159 = F_57 ;
V_7 -> V_56 . V_160 = F_63 ;
V_7 -> V_56 . V_161 = F_80 ;
V_7 -> V_56 . F_31 = F_31 ;
V_7 -> V_56 . V_57 = F_33 ;
V_7 -> V_56 . V_84 = F_36 ;
V_7 -> V_56 . V_162 = F_38 ;
V_7 -> V_56 . V_163 = F_48 ;
V_7 -> V_56 . V_164 = F_66 ;
V_7 -> V_56 . V_165 = F_67 ;
V_7 -> V_56 . F_81 = F_81 ;
break;
case V_76 :
V_7 -> V_56 . V_159 = F_50 ;
V_7 -> V_56 . V_160 = F_51 ;
V_7 -> V_56 . V_158 = F_17 ;
V_7 -> V_56 . V_161 = F_28 ;
V_7 -> V_56 . F_31 = F_31 ;
V_7 -> V_56 . V_57 = F_33 ;
V_7 -> V_56 . V_84 = F_36 ;
V_7 -> V_56 . V_162 = F_38 ;
V_7 -> V_56 . V_109 = F_43 ;
V_7 -> V_56 . V_163 = F_48 ;
V_7 -> V_56 . F_81 = F_81 ;
break;
default:
F_83 () ;
break;
}
switch ( V_12 -> V_166 -> V_167 ) {
case V_168 :
F_84 ( & V_7 -> V_83 ) ;
break;
case V_169 :
F_85 ( & V_7 -> V_83 ) ;
break;
}
if ( V_7 -> V_56 . V_109 ( V_7 ) != 0 ) {
F_40 ( V_7 ) ;
return NULL ;
}
return V_7 ;
}
void F_86 ( struct V_6 * V_7 )
{
F_5 ( ! V_7 ) ;
V_7 -> V_56 . V_163 ( V_7 ) ;
F_40 ( V_7 ) ;
}
