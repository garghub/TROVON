static inline
enum V_1 F_1 ( enum V_2 type )
{
if ( type == V_3 )
return V_4 ;
return V_5 ;
}
unsigned int F_2 ( struct V_6 * V_7 )
{
F_3 ( ! V_7 || ! V_7 -> V_8 ) ;
return V_7 -> V_8 -> V_9 . V_10 ;
}
unsigned int F_4 ( struct V_6 * V_7 )
{
F_3 ( ! V_7 || ! V_7 -> V_8 ) ;
return V_7 -> V_8 -> V_9 . V_11 ;
}
static inline unsigned int F_5 ( void )
{
return V_12 ;
}
void F_6 ( struct V_6 * V_7 ,
struct V_13 * V_14 )
{
return V_7 -> V_8 -> V_15 -> F_6 (
V_7 -> V_8 -> V_16 , V_14 -> V_17 ,
V_14 -> V_18 ,
V_14 -> V_19 ,
V_14 -> V_20 ,
V_14 -> V_21 ) ;
}
static int F_7 ( struct V_6 * V_7 ,
struct V_13 * V_14 ,
struct V_22 * V_23 )
{
int V_24 , V_25 ;
if ( V_7 -> V_26 == 0 )
return - V_27 ;
V_24 = F_8 ( ( unsigned long * ) & V_7 -> V_26 , V_28 ) ;
F_9 ( V_24 , ( unsigned long * ) & V_7 -> V_26 ) ;
V_25 = V_24 + V_29 ;
F_10 ( L_1 , V_25 ) ;
V_14 -> V_17 = V_25 ;
V_23 -> V_30 . V_17 = V_25 ;
F_11 ( V_7 , V_23 -> V_31 -> V_32 , V_23 -> V_30 . V_17 ) ;
F_6 ( V_7 , V_14 ) ;
return 0 ;
}
static void F_12 ( struct V_6 * V_7 ,
struct V_13 * V_14 ,
struct V_22 * V_23 )
{
int V_24 = V_14 -> V_17 - V_29 ;
F_11 ( V_7 , 0 , V_14 -> V_17 ) ;
F_13 ( V_24 , ( unsigned long * ) & V_7 -> V_26 ) ;
V_14 -> V_17 = 0 ;
V_23 -> V_30 . V_17 = 0 ;
}
static int F_14 ( struct V_6 * V_7 ,
struct V_22 * V_23 ,
struct V_13 * V_14 ,
int * V_25 )
{
int V_33 ;
F_3 ( ! V_7 || ! V_23 || ! V_14 || ! V_25 ) ;
F_10 ( L_2 , V_34 ) ;
F_15 ( V_23 ) ;
F_16 ( & V_7 -> V_35 ) ;
if ( V_7 -> V_36 >= V_37 ) {
F_17 ( L_3 ,
V_7 -> V_36 ) ;
F_18 ( & V_7 -> V_35 ) ;
return - V_38 ;
}
if ( F_19 ( & V_14 -> V_39 ) ) {
V_33 = F_7 ( V_7 , V_14 , V_23 ) ;
if ( V_33 != 0 ) {
F_18 ( & V_7 -> V_35 ) ;
return V_33 ;
}
}
* V_25 = V_14 -> V_17 ;
V_23 -> V_30 . V_17 = V_14 -> V_17 ;
if ( V_23 -> V_30 . type == V_40 )
V_33 = F_20 ( V_7 , V_23 , V_14 ) ;
if ( V_23 -> V_30 . type == V_3 )
V_33 = F_21 ( V_7 , V_23 , V_14 ) ;
if ( V_33 != 0 ) {
if ( F_19 ( & V_14 -> V_39 ) ) {
F_12 ( V_7 , V_14 , V_23 ) ;
* V_25 = 0 ;
}
F_18 ( & V_7 -> V_35 ) ;
return V_33 ;
}
F_22 ( & V_23 -> V_41 , & V_14 -> V_39 ) ;
if ( V_23 -> V_30 . V_42 )
V_7 -> V_43 ++ ;
if ( V_23 -> V_30 . type == V_3 )
V_7 -> V_44 ++ ;
V_7 -> V_36 ++ ;
F_10 ( L_4 ,
V_7 -> V_36 ) ;
F_18 ( & V_7 -> V_35 ) ;
return 0 ;
}
static int F_23 ( struct V_6 * V_7 , struct V_22 * V_23 )
{
bool V_45 ;
int V_46 , V_24 , V_47 ;
V_45 = false ;
for ( V_46 = V_7 -> V_48 , V_47 = 0 ; V_47 < F_4 ( V_7 ) ;
V_46 = ( ( V_46 + 1 ) % F_4 ( V_7 ) ) , ++ V_47 ) {
if ( V_7 -> V_49 [ V_46 ] != 0 ) {
V_24 = F_8 (
( unsigned long * ) & V_7 -> V_49 [ V_46 ] ,
V_50 ) ;
F_9 ( V_24 ,
( unsigned long * ) & V_7 -> V_49 [ V_46 ] ) ;
V_23 -> V_46 = V_46 ;
V_23 -> V_22 = V_24 ;
V_45 = true ;
break;
}
}
if ( V_45 == false )
return - V_51 ;
F_10 ( L_5 ,
V_34 , V_23 -> V_46 , V_23 -> V_22 ) ;
V_7 -> V_48 = ( V_46 + 1 ) % F_4 ( V_7 ) ;
return 0 ;
}
static inline void F_24 ( struct V_6 * V_7 ,
struct V_22 * V_23 )
{
F_13 ( V_23 -> V_22 , ( unsigned long * ) & V_7 -> V_49 [ V_23 -> V_46 ] ) ;
}
static int F_20 ( struct V_6 * V_7 ,
struct V_22 * V_23 ,
struct V_13 * V_14 )
{
int V_33 ;
struct V_52 * V_53 ;
F_3 ( ! V_7 || ! V_23 || ! V_14 ) ;
V_53 = V_7 -> V_54 . V_55 ( V_7 , V_56 ) ;
if ( V_53 == NULL )
return - V_27 ;
V_33 = F_23 ( V_7 , V_23 ) ;
if ( V_33 != 0 )
return V_33 ;
V_33 = V_53 -> V_57 ( V_53 , & V_23 -> V_53 , & V_23 -> V_58 ,
& V_23 -> V_59 , & V_23 -> V_30 ) ;
if ( V_33 != 0 ) {
F_24 ( V_7 , V_23 ) ;
return V_33 ;
}
F_10 ( L_6 ,
V_23 -> V_46 ,
V_23 -> V_22 ) ;
V_33 = V_53 -> V_60 ( V_53 , V_23 -> V_53 , V_23 -> V_46 ,
V_23 -> V_22 , ( V_61 V_62 * ) V_23 -> V_30 . V_63 ) ;
if ( V_33 != 0 ) {
F_24 ( V_7 , V_23 ) ;
V_53 -> V_64 ( V_53 , V_23 -> V_53 , V_23 -> V_58 ) ;
return V_33 ;
}
return 0 ;
}
static int F_25 ( struct V_6 * V_7 ,
struct V_13 * V_14 ,
struct V_22 * V_23 )
{
int V_33 ;
struct V_52 * V_53 ;
F_3 ( ! V_7 || ! V_23 || ! V_23 -> V_53 || ! V_14 ) ;
V_33 = 0 ;
F_10 ( L_7 , V_34 ) ;
F_16 ( & V_7 -> V_35 ) ;
if ( V_23 -> V_30 . type == V_40 ) {
V_53 = V_7 -> V_54 . V_55 ( V_7 , V_56 ) ;
if ( V_53 == NULL ) {
V_33 = - V_27 ;
goto V_65;
}
F_24 ( V_7 , V_23 ) ;
} else if ( V_23 -> V_30 . type == V_3 ) {
V_53 = V_7 -> V_54 . V_55 ( V_7 , V_4 ) ;
if ( V_53 == NULL ) {
V_33 = - V_27 ;
goto V_65;
}
V_7 -> V_44 -- ;
F_26 ( V_7 , V_23 -> V_66 ) ;
} else {
F_10 ( L_8 ,
V_23 -> V_30 . type ) ;
V_33 = - V_67 ;
goto V_65;
}
V_33 = V_53 -> V_68 ( V_53 , V_23 -> V_53 ,
V_69 ,
V_70 ,
V_23 -> V_46 , V_23 -> V_22 ) ;
if ( V_33 != 0 )
goto V_65;
V_53 -> V_64 ( V_53 , V_23 -> V_53 , V_23 -> V_58 ) ;
F_27 ( & V_23 -> V_41 ) ;
if ( F_19 ( & V_14 -> V_39 ) )
F_12 ( V_7 , V_14 , V_23 ) ;
if ( V_23 -> V_30 . V_42 )
V_7 -> V_43 -- ;
V_7 -> V_36 -- ;
F_10 ( L_4 ,
V_7 -> V_36 ) ;
V_65:
F_18 ( & V_7 -> V_35 ) ;
return V_33 ;
}
static int F_28 ( struct V_6 * V_7 , struct V_22 * V_23 )
{
int V_33 ;
struct V_52 * V_53 ;
bool V_71 = false ;
F_3 ( ! V_7 || ! V_23 || ! V_23 -> V_53 ) ;
F_16 ( & V_7 -> V_35 ) ;
V_53 = V_7 -> V_54 . V_55 ( V_7 ,
F_1 ( V_23 -> V_30 . type ) ) ;
if ( V_53 == NULL ) {
F_18 ( & V_7 -> V_35 ) ;
return - V_27 ;
}
if ( V_23 -> V_30 . V_42 == true )
V_71 = true ;
V_33 = V_53 -> V_72 ( V_53 , V_23 -> V_53 , & V_23 -> V_30 ) ;
if ( ( V_23 -> V_30 . V_42 == true ) && ( V_71 == false ) )
V_7 -> V_43 ++ ;
else if ( ( V_23 -> V_30 . V_42 == false ) && ( V_71 == true ) )
V_7 -> V_43 -- ;
if ( V_73 != V_74 )
V_33 = F_29 ( V_7 , false ) ;
F_18 ( & V_7 -> V_35 ) ;
return V_33 ;
}
static struct V_52 * F_30 (
struct V_6 * V_7 , enum V_1 type )
{
struct V_52 * V_53 ;
F_3 ( ! V_7 || type >= V_75 ) ;
F_10 ( L_9 , V_34 , type ) ;
V_53 = V_7 -> V_76 [ type ] ;
if ( ! V_53 ) {
V_53 = F_31 ( type , V_7 -> V_8 ) ;
if ( V_53 == NULL )
F_32 ( L_10 ) ;
V_7 -> V_76 [ type ] = V_53 ;
}
return V_53 ;
}
static int F_33 ( struct V_6 * V_7 ,
struct V_13 * V_14 )
{
struct V_77 * V_78 ;
int V_33 ;
F_3 ( ! V_7 || ! V_14 ) ;
F_10 ( L_2 , V_34 ) ;
V_78 = F_34 ( sizeof( struct V_77 ) , V_79 ) ;
if ( ! V_78 )
return - V_27 ;
V_78 -> V_14 = V_14 ;
F_16 ( & V_7 -> V_35 ) ;
F_22 ( & V_78 -> V_41 , & V_7 -> V_80 ) ;
V_33 = V_7 -> V_81 . V_82 ( V_7 , V_14 ) ;
V_7 -> V_83 ++ ;
F_18 ( & V_7 -> V_35 ) ;
return V_33 ;
}
static int F_35 ( struct V_6 * V_7 ,
struct V_13 * V_14 )
{
int V_33 ;
struct V_77 * V_84 , * V_85 ;
F_3 ( ! V_7 || ! V_14 ) ;
F_10 ( L_11 , V_34 ) ;
F_10 ( L_12 ,
F_19 ( & V_14 -> V_39 ) ? L_13 : L_14 ) ;
V_33 = 0 ;
F_16 ( & V_7 -> V_35 ) ;
F_36 (cur, next, &dqm->queues, list) {
if ( V_14 == V_84 -> V_14 ) {
F_27 ( & V_84 -> V_41 ) ;
F_37 ( V_84 ) ;
V_7 -> V_83 -- ;
goto V_65;
}
}
V_33 = 1 ;
V_65:
F_18 ( & V_7 -> V_35 ) ;
return V_33 ;
}
static int
F_11 ( struct V_6 * V_7 , unsigned int V_32 ,
unsigned int V_17 )
{
V_61 V_86 ;
V_86 = ( V_32 == 0 ) ? 0 :
( V_61 ) V_32 |
V_87 ;
return V_7 -> V_8 -> V_15 -> F_11 (
V_7 -> V_8 -> V_16 , V_86 ,
V_17 ) ;
}
int F_38 ( struct V_6 * V_7 ,
unsigned int V_88 , unsigned int V_89 )
{
void * V_90 ;
struct V_52 * V_53 ;
unsigned int V_47 , V_91 , V_92 ;
T_1 V_93 ;
F_3 ( ! V_7 || ! V_7 -> V_8 ) ;
F_10 ( L_2 , V_34 ) ;
V_91 = F_39 ( V_7 -> V_8 , V_94 * V_88 ,
& V_7 -> V_95 ) ;
if ( V_91 ) {
F_32 ( L_15 ,
V_88 ) ;
return - V_27 ;
}
V_90 = V_7 -> V_95 -> V_96 ;
V_7 -> V_97 = V_7 -> V_95 -> V_98 ;
memset ( V_90 , 0 , V_94 * V_88 ) ;
V_53 = V_7 -> V_54 . V_55 ( V_7 , V_56 ) ;
if ( V_53 == NULL ) {
F_40 ( V_7 -> V_8 , V_7 -> V_95 ) ;
return - V_27 ;
}
for ( V_47 = 0 ; V_47 < V_88 ; V_47 ++ ) {
V_92 = V_47 + V_89 ;
V_93 = V_7 -> V_97 + V_47 * V_94 ;
F_10 ( L_16 , V_93 ) ;
V_7 -> V_8 -> V_15 -> V_99 ( V_7 -> V_8 -> V_16 , V_92 ,
V_100 - 3 , V_93 ) ;
}
return 0 ;
}
static void F_41 ( struct V_6 * V_7 )
{
unsigned int V_47 ;
F_3 ( V_7 == NULL ) ;
for ( V_47 = 0 ; V_47 < F_4 ( V_7 ) ; V_47 ++ )
V_7 -> V_8 -> V_15 -> F_41 ( V_7 -> V_8 -> V_16 ,
V_47 + F_2 ( V_7 ) ) ;
}
static int F_42 ( struct V_6 * V_7 )
{
int V_33 ;
F_3 ( ! V_7 ) ;
F_10 ( L_17 , V_34 ) ;
V_33 = F_38 ( V_7 , F_4 ( V_7 ) , F_2 ( V_7 ) ) ;
return V_33 ;
}
static int F_43 ( struct V_6 * V_7 )
{
int V_47 ;
F_3 ( ! V_7 ) ;
F_10 ( L_18 ,
V_34 , F_4 ( V_7 ) ) ;
F_44 ( & V_7 -> V_35 ) ;
F_45 ( & V_7 -> V_80 ) ;
V_7 -> V_43 = V_7 -> V_48 = 0 ;
V_7 -> V_44 = 0 ;
V_7 -> V_49 = F_46 ( F_4 ( V_7 ) ,
sizeof( unsigned int ) , V_79 ) ;
if ( ! V_7 -> V_49 ) {
F_47 ( & V_7 -> V_35 ) ;
return - V_27 ;
}
for ( V_47 = 0 ; V_47 < F_4 ( V_7 ) ; V_47 ++ )
V_7 -> V_49 [ V_47 ] = ( 1 << V_50 ) - 1 ;
V_7 -> V_26 = ( 1 << V_101 ) - 1 ;
V_7 -> V_102 = ( 1 << V_103 ) - 1 ;
F_42 ( V_7 ) ;
return 0 ;
}
static void F_48 ( struct V_6 * V_7 )
{
int V_47 ;
F_3 ( ! V_7 ) ;
F_3 ( V_7 -> V_43 > 0 || V_7 -> V_83 > 0 ) ;
F_37 ( V_7 -> V_49 ) ;
for ( V_47 = 0 ; V_47 < V_75 ; V_47 ++ )
F_37 ( V_7 -> V_76 [ V_47 ] ) ;
F_47 ( & V_7 -> V_35 ) ;
F_40 ( V_7 -> V_8 , V_7 -> V_95 ) ;
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
unsigned int * V_104 )
{
int V_24 ;
if ( V_7 -> V_102 == 0 )
return - V_27 ;
V_24 = F_8 ( ( unsigned long * ) & V_7 -> V_102 ,
V_103 ) ;
F_9 ( V_24 , ( unsigned long * ) & V_7 -> V_102 ) ;
* V_104 = V_24 ;
return 0 ;
}
static void F_26 ( struct V_6 * V_7 ,
unsigned int V_104 )
{
if ( V_104 >= V_103 )
return;
F_13 ( V_104 , ( unsigned long * ) & V_7 -> V_102 ) ;
}
static int F_21 ( struct V_6 * V_7 ,
struct V_22 * V_23 ,
struct V_13 * V_14 )
{
struct V_52 * V_53 ;
int V_33 ;
V_53 = V_7 -> V_54 . V_55 ( V_7 , V_4 ) ;
if ( ! V_53 )
return - V_27 ;
V_33 = F_51 ( V_7 , & V_23 -> V_66 ) ;
if ( V_33 != 0 )
return V_33 ;
V_23 -> V_30 . V_104 = V_23 -> V_66 % V_105 ;
V_23 -> V_30 . V_106 = V_23 -> V_66 / V_107 ;
F_10 ( L_19 , V_23 -> V_66 ) ;
F_10 ( L_20 , V_23 -> V_30 . V_104 ) ;
F_10 ( L_21 , V_23 -> V_30 . V_106 ) ;
V_7 -> V_81 . V_108 ( V_7 , V_23 , V_14 ) ;
V_33 = V_53 -> V_57 ( V_53 , & V_23 -> V_53 , & V_23 -> V_58 ,
& V_23 -> V_59 , & V_23 -> V_30 ) ;
if ( V_33 != 0 ) {
F_26 ( V_7 , V_23 -> V_66 ) ;
return V_33 ;
}
V_33 = V_53 -> V_60 ( V_53 , V_23 -> V_53 , 0 ,
0 , NULL ) ;
if ( V_33 != 0 ) {
F_26 ( V_7 , V_23 -> V_66 ) ;
V_53 -> V_64 ( V_53 , V_23 -> V_53 , V_23 -> V_58 ) ;
return V_33 ;
}
return 0 ;
}
static int F_52 ( struct V_6 * V_7 )
{
struct V_109 V_110 ;
unsigned int V_111 , V_112 ;
F_3 ( ! V_7 ) ;
F_10 ( L_2 , V_34 ) ;
V_111 = F_5 () * V_50 ;
V_112 = ( 1 << V_111 ) - 1 ;
V_110 . V_113 = ( 1 << V_101 ) - 1 ;
V_110 . V_113 <<= V_29 ;
V_110 . V_112 = V_112 << ( F_2 ( V_7 ) * V_50 ) ;
V_110 . V_114 = V_110 . V_115 = V_110 . V_116 =
V_110 . V_117 = 0 ;
F_10 ( L_22
L_23
L_24 ,
V_110 . V_113 , V_110 . V_112 ) ;
return F_53 ( & V_7 -> V_118 , & V_110 ) ;
}
static int F_54 ( struct V_6 * V_7 )
{
int V_33 ;
F_3 ( ! V_7 ) ;
F_10 ( L_18 ,
V_34 , F_5 () ) ;
F_44 ( & V_7 -> V_35 ) ;
F_45 ( & V_7 -> V_80 ) ;
V_7 -> V_43 = V_7 -> V_83 = 0 ;
V_7 -> V_44 = 0 ;
V_7 -> V_119 = false ;
V_33 = V_7 -> V_81 . V_120 ( V_7 ) ;
if ( V_33 != 0 )
goto V_121;
return 0 ;
V_121:
F_47 ( & V_7 -> V_35 ) ;
return V_33 ;
}
static int F_55 ( struct V_6 * V_7 )
{
struct V_77 * V_122 ;
int V_33 ;
F_3 ( ! V_7 ) ;
V_33 = 0 ;
V_33 = F_56 ( & V_7 -> V_118 , V_7 ) ;
if ( V_33 != 0 )
goto V_123;
V_33 = F_52 ( V_7 ) ;
if ( V_33 != 0 )
goto V_124;
F_10 ( L_25 ) ;
V_33 = F_39 ( V_7 -> V_8 , sizeof( * V_7 -> V_125 ) ,
& V_7 -> V_126 ) ;
if ( V_33 != 0 )
goto V_127;
V_7 -> V_125 = V_7 -> V_126 -> V_96 ;
V_7 -> V_128 = V_7 -> V_126 -> V_98 ;
F_41 ( V_7 ) ;
F_57 (node, &dqm->queues, list)
if ( V_122 -> V_14 -> V_129 -> V_31 && V_7 -> V_8 )
F_58 ( V_7 -> V_8 ,
V_122 -> V_14 -> V_129 -> V_31 ) ;
F_29 ( V_7 , true ) ;
return 0 ;
V_127:
V_124:
F_59 ( & V_7 -> V_118 ) ;
V_123:
return V_33 ;
}
static int F_60 ( struct V_6 * V_7 )
{
struct V_77 * V_122 ;
struct V_130 * V_131 ;
F_3 ( ! V_7 ) ;
F_61 ( V_7 , true , true ) ;
F_57 (node, &dqm->queues, list) {
V_131 = F_62 ( V_122 -> V_14 ) ;
V_131 -> V_132 = false ;
}
F_40 ( V_7 -> V_8 , V_7 -> V_126 ) ;
F_59 ( & V_7 -> V_118 ) ;
return 0 ;
}
static int F_63 ( struct V_6 * V_7 ,
struct V_133 * V_134 ,
struct V_13 * V_14 )
{
F_3 ( ! V_7 || ! V_134 || ! V_14 ) ;
F_10 ( L_2 , V_34 ) ;
F_16 ( & V_7 -> V_35 ) ;
if ( V_7 -> V_36 >= V_37 ) {
F_17 ( L_26 ,
V_7 -> V_36 ) ;
F_18 ( & V_7 -> V_35 ) ;
return - V_38 ;
}
V_7 -> V_36 ++ ;
F_10 ( L_4 ,
V_7 -> V_36 ) ;
F_22 ( & V_134 -> V_41 , & V_14 -> V_135 ) ;
V_7 -> V_43 ++ ;
V_14 -> V_136 = true ;
F_29 ( V_7 , false ) ;
F_18 ( & V_7 -> V_35 ) ;
return 0 ;
}
static void F_64 ( struct V_6 * V_7 ,
struct V_133 * V_134 ,
struct V_13 * V_14 )
{
F_3 ( ! V_7 || ! V_134 ) ;
F_10 ( L_17 , V_34 ) ;
F_16 ( & V_7 -> V_35 ) ;
F_61 ( V_7 , true , false ) ;
F_27 ( & V_134 -> V_41 ) ;
V_7 -> V_43 -- ;
V_14 -> V_136 = false ;
F_29 ( V_7 , false ) ;
V_7 -> V_36 -- ;
F_10 ( L_4 ,
V_7 -> V_36 ) ;
F_18 ( & V_7 -> V_35 ) ;
}
static void F_65 ( struct V_22 * V_23 )
{
static int V_66 ;
V_23 -> V_66 = V_66 ;
V_66 = ( V_66 + 1 ) % 2 ;
}
static int F_66 ( struct V_6 * V_7 , struct V_22 * V_23 ,
struct V_13 * V_14 , int * F_7 )
{
int V_33 ;
struct V_52 * V_53 ;
F_3 ( ! V_7 || ! V_23 || ! V_14 ) ;
V_33 = 0 ;
if ( F_7 )
* F_7 = 0 ;
F_16 ( & V_7 -> V_35 ) ;
if ( V_7 -> V_36 >= V_37 ) {
F_17 ( L_3 ,
V_7 -> V_36 ) ;
V_33 = - V_38 ;
goto V_65;
}
if ( V_23 -> V_30 . type == V_3 )
F_65 ( V_23 ) ;
V_53 = V_7 -> V_54 . V_55 ( V_7 ,
F_1 ( V_23 -> V_30 . type ) ) ;
if ( V_53 == NULL ) {
F_18 ( & V_7 -> V_35 ) ;
return - V_27 ;
}
V_7 -> V_81 . V_108 ( V_7 , V_23 , V_14 ) ;
V_33 = V_53 -> V_57 ( V_53 , & V_23 -> V_53 , & V_23 -> V_58 ,
& V_23 -> V_59 , & V_23 -> V_30 ) ;
if ( V_33 != 0 )
goto V_65;
F_22 ( & V_23 -> V_41 , & V_14 -> V_39 ) ;
if ( V_23 -> V_30 . V_42 ) {
V_7 -> V_43 ++ ;
V_33 = F_29 ( V_7 , false ) ;
}
if ( V_23 -> V_30 . type == V_3 )
V_7 -> V_44 ++ ;
V_7 -> V_36 ++ ;
F_10 ( L_4 ,
V_7 -> V_36 ) ;
V_65:
F_18 ( & V_7 -> V_35 ) ;
return V_33 ;
}
int F_67 ( unsigned int * V_125 ,
unsigned int V_137 ,
unsigned long V_138 )
{
F_3 ( ! V_125 ) ;
V_138 += V_139 ;
while ( * V_125 != V_137 ) {
if ( F_68 ( V_139 , V_138 ) ) {
F_32 ( L_27 ) ;
return - V_140 ;
}
F_69 () ;
}
return 0 ;
}
static int F_70 ( struct V_6 * V_7 ,
unsigned int V_141 )
{
return F_71 ( & V_7 -> V_118 , V_3 ,
V_142 , 0 , false ,
V_141 ) ;
}
static int F_61 ( struct V_6 * V_7 ,
bool V_143 , bool V_35 )
{
int V_33 ;
enum V_144 V_145 ;
struct V_130 * V_131 ;
F_3 ( ! V_7 ) ;
V_33 = 0 ;
if ( V_35 )
F_16 ( & V_7 -> V_35 ) ;
if ( V_7 -> V_119 == false )
goto V_65;
F_10 ( L_28 ,
V_7 -> V_44 ) ;
if ( V_7 -> V_44 > 0 ) {
F_70 ( V_7 , 0 ) ;
F_70 ( V_7 , 1 ) ;
}
V_145 = V_143 ?
V_146 :
V_142 ;
V_33 = F_71 ( & V_7 -> V_118 , V_40 ,
V_145 , 0 , false , 0 ) ;
if ( V_33 != 0 )
goto V_65;
* V_7 -> V_125 = V_147 ;
F_72 ( & V_7 -> V_118 , V_7 -> V_128 ,
V_148 ) ;
V_33 = F_67 ( V_7 -> V_125 , V_148 ,
V_70 ) ;
if ( V_33 != 0 ) {
V_131 = F_73 ( V_7 -> V_8 ,
F_74 ( V_149 ) ) ;
V_131 -> V_150 = true ;
goto V_65;
}
F_75 ( & V_7 -> V_118 ) ;
V_7 -> V_119 = false ;
V_65:
if ( V_35 )
F_18 ( & V_7 -> V_35 ) ;
return V_33 ;
}
static int F_29 ( struct V_6 * V_7 , bool V_35 )
{
int V_33 ;
F_3 ( ! V_7 ) ;
if ( V_35 )
F_16 ( & V_7 -> V_35 ) ;
V_33 = F_61 ( V_7 , false , false ) ;
if ( V_33 != 0 ) {
F_32 ( L_29 ) ;
goto V_65;
}
if ( V_7 -> V_43 <= 0 || V_7 -> V_83 <= 0 ) {
V_33 = 0 ;
goto V_65;
}
if ( V_7 -> V_119 ) {
V_33 = 0 ;
goto V_65;
}
V_33 = F_76 ( & V_7 -> V_118 , & V_7 -> V_80 ) ;
if ( V_33 != 0 ) {
F_32 ( L_30 ) ;
goto V_65;
}
V_7 -> V_119 = true ;
V_65:
if ( V_35 )
F_18 ( & V_7 -> V_35 ) ;
return V_33 ;
}
static int F_77 ( struct V_6 * V_7 ,
struct V_13 * V_14 ,
struct V_22 * V_23 )
{
int V_33 ;
struct V_52 * V_53 ;
bool V_151 ;
F_3 ( ! V_7 || ! V_14 || ! V_23 ) ;
V_151 = false ;
V_33 = 0 ;
F_16 ( & V_7 -> V_35 ) ;
if ( V_14 -> V_136 ) {
V_33 = - V_51 ;
goto V_152;
}
V_53 = V_7 -> V_54 . V_55 ( V_7 ,
F_1 ( V_23 -> V_30 . type ) ) ;
if ( ! V_53 ) {
V_33 = - V_27 ;
goto V_153;
}
if ( V_23 -> V_30 . type == V_3 )
V_7 -> V_44 -- ;
F_27 ( & V_23 -> V_41 ) ;
if ( V_23 -> V_30 . V_42 )
V_7 -> V_43 -- ;
F_29 ( V_7 , false ) ;
V_53 -> V_64 ( V_53 , V_23 -> V_53 , V_23 -> V_58 ) ;
V_7 -> V_36 -- ;
F_10 ( L_4 ,
V_7 -> V_36 ) ;
F_18 ( & V_7 -> V_35 ) ;
return 0 ;
V_153:
V_152:
F_18 ( & V_7 -> V_35 ) ;
return V_33 ;
}
static bool F_78 ( struct V_6 * V_7 ,
struct V_13 * V_14 ,
enum V_154 V_155 ,
enum V_154 V_156 ,
void V_62 * V_157 ,
T_1 V_158 )
{
bool V_33 ;
F_10 ( L_2 , V_34 ) ;
F_16 ( & V_7 -> V_35 ) ;
if ( V_158 == 0 ) {
V_14 -> V_19 = 1 ;
V_14 -> V_20 = 0 ;
} else {
T_1 V_159 = ( V_160 ) V_157 ;
T_1 V_161 = V_159 + V_158 - 1 ;
if ( V_161 <= V_159 )
goto V_65;
if ( ( V_159 & V_162 ) != 0 )
goto V_65;
if ( ( V_161 & V_162 ) != V_163 )
goto V_65;
V_14 -> V_19 = V_159 >> 16 ;
V_14 -> V_20 = V_161 >> 16 ;
}
V_33 = V_7 -> V_81 . F_78 (
V_7 ,
V_14 ,
V_155 ,
V_156 ,
V_157 ,
V_158 ) ;
if ( ( V_73 == V_74 ) && ( V_14 -> V_17 != 0 ) )
F_6 ( V_7 , V_14 ) ;
F_10 ( L_31 ,
V_14 -> V_18 , V_14 -> V_19 ,
V_14 -> V_20 ) ;
F_18 ( & V_7 -> V_35 ) ;
return V_33 ;
V_65:
F_18 ( & V_7 -> V_35 ) ;
return false ;
}
struct V_6 * F_79 ( struct V_164 * V_8 )
{
struct V_6 * V_7 ;
F_3 ( ! V_8 ) ;
F_10 ( L_32 ) ;
V_7 = F_34 ( sizeof( struct V_6 ) , V_79 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_8 = V_8 ;
switch ( V_73 ) {
case V_165 :
case V_166 :
V_7 -> V_54 . V_167 = F_66 ;
V_7 -> V_54 . V_120 = F_54 ;
V_7 -> V_54 . V_168 = F_55 ;
V_7 -> V_54 . V_169 = F_60 ;
V_7 -> V_54 . V_170 = F_77 ;
V_7 -> V_54 . F_28 = F_28 ;
V_7 -> V_54 . V_55 = F_30 ;
V_7 -> V_54 . V_82 = F_33 ;
V_7 -> V_54 . V_171 = F_35 ;
V_7 -> V_54 . V_172 = F_48 ;
V_7 -> V_54 . V_173 = F_63 ;
V_7 -> V_54 . V_174 = F_64 ;
V_7 -> V_54 . F_78 = F_78 ;
break;
case V_74 :
V_7 -> V_54 . V_168 = F_49 ;
V_7 -> V_54 . V_169 = F_50 ;
V_7 -> V_54 . V_167 = F_14 ;
V_7 -> V_54 . V_170 = F_25 ;
V_7 -> V_54 . F_28 = F_28 ;
V_7 -> V_54 . V_55 = F_30 ;
V_7 -> V_54 . V_82 = F_33 ;
V_7 -> V_54 . V_171 = F_35 ;
V_7 -> V_54 . V_120 = F_43 ;
V_7 -> V_54 . V_172 = F_48 ;
V_7 -> V_54 . F_78 = F_78 ;
break;
default:
F_80 () ;
break;
}
switch ( V_8 -> V_175 -> V_176 ) {
case V_177 :
F_81 ( & V_7 -> V_81 ) ;
break;
case V_178 :
F_82 ( & V_7 -> V_81 ) ;
break;
}
if ( V_7 -> V_54 . V_120 ( V_7 ) != 0 ) {
F_37 ( V_7 ) ;
return NULL ;
}
return V_7 ;
}
void F_83 ( struct V_6 * V_7 )
{
F_3 ( ! V_7 ) ;
V_7 -> V_54 . V_172 ( V_7 ) ;
F_37 ( V_7 ) ;
}
