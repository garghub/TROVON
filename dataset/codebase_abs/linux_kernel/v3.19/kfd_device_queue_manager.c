static inline unsigned int F_1 ( struct V_1 * V_2 )
{
F_2 ( ! V_2 || ! V_2 -> V_3 ) ;
return V_2 -> V_3 -> V_4 . V_5 ;
}
static inline unsigned int F_3 ( struct V_1 * V_2 )
{
F_2 ( ! V_2 ) ;
return V_2 -> V_3 -> V_4 . V_6 ;
}
static inline unsigned int F_4 ( void )
{
return V_7 ;
}
static inline unsigned int
F_5 ( struct V_8 * V_9 )
{
T_1 V_10 ;
V_10 = ( V_9 -> V_11 >> 60 ) & 0x0E ;
return V_10 ;
}
static inline unsigned int F_6 ( struct V_8 * V_9 )
{
unsigned int V_12 ;
V_12 = ( V_9 -> V_11 >> 16 ) & 0xFF ;
return V_12 ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_8 * V_9 ;
unsigned int V_15 ;
F_2 ( ! V_2 || ! V_14 ) ;
V_9 = F_8 ( V_14 ) ;
if ( V_14 -> V_16 == 0 ) {
V_14 -> V_16 =
F_9 ( V_17 ) |
F_10 ( V_18 ) |
F_11 ( V_18 ) ;
V_14 -> V_19 = 0 ;
V_14 -> V_20 = 0 ;
}
if ( V_14 -> V_21 -> V_22 -> V_23 ) {
V_15 = F_6 ( V_9 ) ;
V_14 -> V_24 = F_12 ( V_15 ) ;
V_14 -> V_16 |= V_25 ;
} else {
V_15 = F_5 ( V_9 ) ;
V_14 -> V_24 = F_13 ( V_15 ) ;
}
F_14 ( L_1 ,
V_14 -> V_21 -> V_22 -> V_23 , V_15 , V_14 -> V_24 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
return V_26 -> F_15 ( V_2 -> V_3 -> V_27 , V_14 -> V_28 ,
V_14 -> V_16 ,
V_14 -> V_20 ,
V_14 -> V_19 ,
V_14 -> V_24 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_29 * V_30 )
{
int V_31 , V_32 ;
if ( V_2 -> V_33 == 0 )
return - V_34 ;
V_31 = F_17 ( ( unsigned long * ) & V_2 -> V_33 , V_35 ) ;
F_18 ( V_31 , ( unsigned long * ) & V_2 -> V_33 ) ;
V_32 = V_31 + V_36 ;
F_14 ( L_2 , V_32 ) ;
V_14 -> V_28 = V_32 ;
V_30 -> V_37 . V_28 = V_32 ;
F_19 ( V_2 , V_30 -> V_22 -> V_38 , V_30 -> V_37 . V_28 ) ;
F_15 ( V_2 , V_14 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_29 * V_30 )
{
int V_31 = V_14 -> V_28 - V_36 ;
F_19 ( V_2 , 0 , V_14 -> V_28 ) ;
F_21 ( V_31 , ( unsigned long * ) & V_2 -> V_33 ) ;
V_14 -> V_28 = 0 ;
V_30 -> V_37 . V_28 = 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
struct V_13 * V_14 ,
int * V_32 )
{
int V_39 ;
F_2 ( ! V_2 || ! V_30 || ! V_14 || ! V_32 ) ;
F_14 ( L_3 , V_40 ) ;
F_23 ( V_30 ) ;
F_24 ( & V_2 -> V_41 ) ;
if ( V_2 -> V_42 >= V_43 ) {
F_25 ( L_4 ,
V_2 -> V_42 ) ;
F_26 ( & V_2 -> V_41 ) ;
return - V_44 ;
}
if ( F_27 ( & V_14 -> V_45 ) ) {
V_39 = F_16 ( V_2 , V_14 , V_30 ) ;
if ( V_39 != 0 ) {
F_26 ( & V_2 -> V_41 ) ;
return V_39 ;
}
}
* V_32 = V_14 -> V_28 ;
V_30 -> V_37 . V_28 = V_14 -> V_28 ;
V_39 = F_28 ( V_2 , V_30 , V_14 ) ;
if ( V_39 != 0 ) {
if ( F_27 ( & V_14 -> V_45 ) ) {
F_20 ( V_2 , V_14 , V_30 ) ;
* V_32 = 0 ;
}
F_26 ( & V_2 -> V_41 ) ;
return V_39 ;
}
F_29 ( & V_30 -> V_46 , & V_14 -> V_45 ) ;
V_2 -> V_47 ++ ;
V_2 -> V_42 ++ ;
F_14 ( L_5 ,
V_2 -> V_42 ) ;
F_26 ( & V_2 -> V_41 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
bool V_48 ;
int V_49 , V_31 ;
V_48 = false ;
for ( V_49 = V_2 -> V_50 ; V_49 < F_1 ( V_2 ) ;
V_49 = ( V_49 + 1 ) % F_1 ( V_2 ) ) {
if ( V_2 -> V_51 [ V_49 ] != 0 ) {
V_31 = F_17 (
( unsigned long * ) & V_2 -> V_51 [ V_49 ] ,
V_52 ) ;
F_18 ( V_31 ,
( unsigned long * ) & V_2 -> V_51 [ V_49 ] ) ;
V_30 -> V_49 = V_49 ;
V_30 -> V_29 = V_31 ;
V_48 = true ;
break;
}
}
if ( V_48 == false )
return - V_53 ;
F_14 ( L_6 ,
V_40 , V_30 -> V_49 , V_30 -> V_29 ) ;
V_2 -> V_50 = ( V_49 + 1 ) % F_1 ( V_2 ) ;
return 0 ;
}
static inline void F_31 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
F_21 ( V_30 -> V_29 , ( unsigned long * ) & V_2 -> V_51 [ V_30 -> V_49 ] ) ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
struct V_13 * V_14 )
{
int V_39 ;
struct V_54 * V_55 ;
F_2 ( ! V_2 || ! V_30 || ! V_14 ) ;
V_55 = V_2 -> V_56 ( V_2 , V_57 ) ;
if ( V_55 == NULL )
return - V_34 ;
V_39 = F_30 ( V_2 , V_30 ) ;
if ( V_39 != 0 )
return V_39 ;
V_39 = V_55 -> V_58 ( V_55 , & V_30 -> V_55 , & V_30 -> V_59 ,
& V_30 -> V_60 , & V_30 -> V_37 ) ;
if ( V_39 != 0 ) {
F_31 ( V_2 , V_30 ) ;
return V_39 ;
}
F_14 ( L_7 ,
V_30 -> V_49 ,
V_30 -> V_29 ) ;
V_39 = V_55 -> V_61 ( V_55 , V_30 -> V_55 , V_30 -> V_49 ,
V_30 -> V_29 , ( T_1 V_62 * ) V_30 -> V_37 . V_63 ) ;
if ( V_39 != 0 ) {
F_31 ( V_2 , V_30 ) ;
V_55 -> V_64 ( V_55 , V_30 -> V_55 , V_30 -> V_59 ) ;
return V_39 ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_29 * V_30 )
{
int V_39 ;
struct V_54 * V_55 ;
F_2 ( ! V_2 || ! V_30 || ! V_30 -> V_55 || ! V_14 ) ;
V_39 = 0 ;
F_14 ( L_8 , V_40 ) ;
F_24 ( & V_2 -> V_41 ) ;
V_55 = V_2 -> V_56 ( V_2 , V_57 ) ;
if ( V_55 == NULL ) {
V_39 = - V_34 ;
goto V_65;
}
V_39 = V_55 -> V_66 ( V_55 , V_30 -> V_55 ,
V_67 ,
V_68 ,
V_30 -> V_49 , V_30 -> V_29 ) ;
if ( V_39 != 0 )
goto V_65;
F_31 ( V_2 , V_30 ) ;
V_55 -> V_64 ( V_55 , V_30 -> V_55 , V_30 -> V_59 ) ;
F_33 ( & V_30 -> V_46 ) ;
if ( F_27 ( & V_14 -> V_45 ) )
F_20 ( V_2 , V_14 , V_30 ) ;
V_2 -> V_47 -- ;
V_2 -> V_42 -- ;
F_14 ( L_5 ,
V_2 -> V_42 ) ;
V_65:
F_26 ( & V_2 -> V_41 ) ;
return V_39 ;
}
static int F_34 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
int V_39 ;
struct V_54 * V_55 ;
bool V_69 = false ;
F_2 ( ! V_2 || ! V_30 || ! V_30 -> V_55 ) ;
F_24 ( & V_2 -> V_41 ) ;
V_55 = V_2 -> V_56 ( V_2 , V_57 ) ;
if ( V_55 == NULL ) {
F_26 ( & V_2 -> V_41 ) ;
return - V_34 ;
}
if ( V_30 -> V_37 . V_70 == true )
V_69 = true ;
V_39 = V_55 -> V_71 ( V_55 , V_30 -> V_55 , & V_30 -> V_37 ) ;
if ( ( V_30 -> V_37 . V_70 == true ) && ( V_69 == false ) )
V_2 -> V_47 ++ ;
else if ( ( V_30 -> V_37 . V_70 == false ) && ( V_69 == true ) )
V_2 -> V_47 -- ;
if ( V_72 != V_73 )
V_39 = F_35 ( V_2 , false ) ;
F_26 ( & V_2 -> V_41 ) ;
return V_39 ;
}
static struct V_54 * F_36 (
struct V_1 * V_2 , enum V_74 type )
{
struct V_54 * V_55 ;
F_2 ( ! V_2 || type >= V_75 ) ;
F_14 ( L_9 , V_40 , type ) ;
V_55 = V_2 -> V_76 [ type ] ;
if ( ! V_55 ) {
V_55 = F_37 ( type , V_2 -> V_3 ) ;
if ( V_55 == NULL )
F_38 ( L_10 ) ;
V_2 -> V_76 [ type ] = V_55 ;
}
return V_55 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_77 * V_78 ;
F_2 ( ! V_2 || ! V_14 ) ;
F_14 ( L_3 , V_40 ) ;
V_78 = F_40 ( sizeof( struct V_77 ) , V_79 ) ;
if ( ! V_78 )
return - V_34 ;
V_78 -> V_14 = V_14 ;
F_24 ( & V_2 -> V_41 ) ;
F_29 ( & V_78 -> V_46 , & V_2 -> V_80 ) ;
F_7 ( V_2 , V_14 ) ;
V_2 -> V_81 ++ ;
F_26 ( & V_2 -> V_41 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
int V_39 ;
struct V_77 * V_82 , * V_83 ;
F_2 ( ! V_2 || ! V_14 ) ;
F_2 ( ! F_27 ( & V_14 -> V_45 ) ) ;
F_14 ( L_3 , V_40 ) ;
V_39 = 0 ;
F_24 ( & V_2 -> V_41 ) ;
F_42 (cur, next, &dqm->queues, list) {
if ( V_14 == V_82 -> V_14 ) {
F_33 ( & V_82 -> V_46 ) ;
F_43 ( V_82 ) ;
V_2 -> V_81 -- ;
goto V_65;
}
}
V_39 = 1 ;
V_65:
F_26 ( & V_2 -> V_41 ) ;
return V_39 ;
}
static int
F_19 ( struct V_1 * V_2 , unsigned int V_38 ,
unsigned int V_28 )
{
T_1 V_84 ;
V_84 = ( V_38 == 0 ) ? 0 : ( T_1 ) V_38 |
V_85 ;
return V_26 -> F_19 ( V_2 -> V_3 -> V_27 , V_84 ,
V_28 ) ;
}
static T_1 F_13 ( unsigned int V_86 )
{
F_2 ( ( V_86 & 1 ) || V_86 > 0xE ||
V_86 == 0 ) ;
return F_44 ( V_86 << 12 ) |
F_12 ( V_86 << 12 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
int V_87 , V_39 ;
for ( V_87 = 8 ; V_87 < 16 ; V_87 ++ )
F_19 ( V_2 , 0 , V_87 ) ;
V_39 = V_26 -> F_45 ( V_2 -> V_3 -> V_27 ) ;
if ( V_39 == 0 )
V_88 = true ;
return V_39 ;
}
static int F_46 ( struct V_1 * V_2 ,
unsigned int V_89 , unsigned int V_90 )
{
void * V_91 ;
struct V_54 * V_55 ;
unsigned int V_87 , V_92 , V_93 ;
T_2 V_94 ;
F_2 ( ! V_2 || ! V_2 -> V_3 ) ;
F_14 ( L_3 , V_40 ) ;
V_92 = V_26 -> V_95 ( V_2 -> V_3 -> V_27 ,
V_96 * V_89 ,
V_97 ,
V_98 ,
(struct V_99 * * ) & V_2 -> V_100 ) ;
if ( V_92 ) {
F_38 ( L_11 ,
V_89 ) ;
return - V_34 ;
}
V_91 = V_2 -> V_100 -> V_101 ;
V_2 -> V_102 = V_2 -> V_100 -> V_103 ;
memset ( V_91 , 0 , V_96 * V_89 ) ;
V_55 = V_2 -> V_56 ( V_2 , V_57 ) ;
if ( V_55 == NULL ) {
V_26 -> V_104 ( V_2 -> V_3 -> V_27 ,
(struct V_99 * ) V_2 -> V_100 ) ;
return - V_34 ;
}
for ( V_87 = 0 ; V_87 < V_89 ; V_87 ++ ) {
V_93 = V_87 + V_90 ;
V_94 = V_2 -> V_102 + V_87 * V_96 ;
F_14 ( L_12 , V_94 ) ;
V_26 -> V_105 ( V_2 -> V_3 -> V_27 , V_93 ,
V_106 - 3 , V_94 ) ;
}
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
int V_39 ;
F_2 ( ! V_2 ) ;
F_14 ( L_13 , V_40 ) ;
V_39 = F_46 ( V_2 , F_1 ( V_2 ) , F_3 ( V_2 ) ) ;
if ( V_39 != 0 )
return V_39 ;
V_39 = F_45 ( V_2 ) ;
return V_39 ;
}
static int F_48 ( struct V_1 * V_2 )
{
int V_87 ;
F_2 ( ! V_2 ) ;
F_14 ( L_14 ,
V_40 , F_1 ( V_2 ) ) ;
F_49 ( & V_2 -> V_41 ) ;
F_50 ( & V_2 -> V_80 ) ;
V_2 -> V_47 = V_2 -> V_50 = 0 ;
V_2 -> V_51 = F_51 ( F_1 ( V_2 ) ,
sizeof( unsigned int ) , V_79 ) ;
if ( ! V_2 -> V_51 ) {
F_52 ( & V_2 -> V_41 ) ;
return - V_34 ;
}
for ( V_87 = 0 ; V_87 < F_1 ( V_2 ) ; V_87 ++ )
V_2 -> V_51 [ V_87 ] = ( 1 << V_52 ) - 1 ;
V_2 -> V_33 = ( 1 << V_107 ) - 1 ;
F_47 ( V_2 ) ;
return 0 ;
}
static void F_53 ( struct V_1 * V_2 )
{
int V_87 ;
F_2 ( ! V_2 ) ;
F_2 ( V_2 -> V_47 > 0 || V_2 -> V_81 > 0 ) ;
F_43 ( V_2 -> V_51 ) ;
for ( V_87 = 0 ; V_87 < V_75 ; V_87 ++ )
F_43 ( V_2 -> V_76 [ V_87 ] ) ;
F_52 ( & V_2 -> V_41 ) ;
V_26 -> V_104 ( V_2 -> V_3 -> V_27 ,
(struct V_99 * ) V_2 -> V_100 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_108 V_109 ;
unsigned int V_110 , V_111 ;
F_2 ( ! V_2 ) ;
F_14 ( L_3 , V_40 ) ;
V_110 = F_4 () * V_52 ;
V_111 = ( 1 << V_110 ) - 1 ;
V_109 . V_112 = ( 1 << V_107 ) - 1 ;
V_109 . V_112 <<= V_36 ;
V_109 . V_111 = V_111 << ( F_3 ( V_2 ) * V_52 ) ;
V_109 . V_113 = V_109 . V_114 = V_109 . V_115 =
V_109 . V_116 = 0 ;
F_14 ( L_15
L_16
L_17 ,
V_109 . V_112 , V_109 . V_111 ) ;
return F_57 ( & V_2 -> V_117 , & V_109 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
int V_39 ;
F_2 ( ! V_2 ) ;
F_14 ( L_14 ,
V_40 , F_4 () ) ;
F_49 ( & V_2 -> V_41 ) ;
F_50 ( & V_2 -> V_80 ) ;
V_2 -> V_47 = V_2 -> V_81 = 0 ;
V_2 -> V_118 = false ;
V_39 = F_46 ( V_2 , F_1 ( V_2 ) , 0 ) ;
if ( V_39 != 0 )
goto V_119;
return 0 ;
V_119:
F_52 ( & V_2 -> V_41 ) ;
return V_39 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_77 * V_120 ;
int V_39 ;
F_2 ( ! V_2 ) ;
V_39 = 0 ;
V_39 = F_60 ( & V_2 -> V_117 , V_2 ) ;
if ( V_39 != 0 )
goto V_121;
V_39 = F_56 ( V_2 ) ;
if ( V_39 != 0 )
goto V_122;
F_14 ( L_18 ) ;
V_39 = V_26 -> V_95 ( V_2 -> V_3 -> V_27 ,
sizeof( * V_2 -> V_123 ) ,
32 ,
V_98 ,
(struct V_99 * * ) & V_2 -> V_124 ) ;
if ( V_39 != 0 )
goto V_125;
V_2 -> V_123 = V_2 -> V_124 -> V_101 ;
V_2 -> V_126 = V_2 -> V_124 -> V_103 ;
F_61 (node, &dqm->queues, list)
if ( V_120 -> V_14 -> V_21 -> V_22 && V_2 -> V_3 )
F_62 ( V_2 -> V_3 ,
V_120 -> V_14 -> V_21 -> V_22 ) ;
F_35 ( V_2 , true ) ;
return 0 ;
V_125:
V_122:
F_63 ( & V_2 -> V_117 ) ;
V_121:
return V_39 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_77 * V_120 ;
struct V_8 * V_9 ;
F_2 ( ! V_2 ) ;
F_65 ( V_2 , true ) ;
F_61 (node, &dqm->queues, list) {
V_9 = F_8 ( V_120 -> V_14 ) ;
V_9 -> V_127 = false ;
}
V_26 -> V_104 ( V_2 -> V_3 -> V_27 ,
(struct V_99 * ) V_2 -> V_124 ) ;
F_63 ( & V_2 -> V_117 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_128 * V_129 ,
struct V_13 * V_14 )
{
F_2 ( ! V_2 || ! V_129 || ! V_14 ) ;
F_14 ( L_3 , V_40 ) ;
F_24 ( & V_2 -> V_41 ) ;
if ( V_2 -> V_42 >= V_43 ) {
F_25 ( L_19 ,
V_2 -> V_42 ) ;
F_26 ( & V_2 -> V_41 ) ;
return - V_44 ;
}
V_2 -> V_42 ++ ;
F_14 ( L_5 ,
V_2 -> V_42 ) ;
F_29 ( & V_129 -> V_46 , & V_14 -> V_130 ) ;
V_2 -> V_47 ++ ;
V_14 -> V_131 = true ;
F_35 ( V_2 , false ) ;
F_26 ( & V_2 -> V_41 ) ;
return 0 ;
}
static void F_67 ( struct V_1 * V_2 ,
struct V_128 * V_129 ,
struct V_13 * V_14 )
{
F_2 ( ! V_2 || ! V_129 ) ;
F_14 ( L_13 , V_40 ) ;
F_24 ( & V_2 -> V_41 ) ;
F_65 ( V_2 , false ) ;
F_33 ( & V_129 -> V_46 ) ;
V_2 -> V_47 -- ;
V_14 -> V_131 = false ;
F_35 ( V_2 , false ) ;
V_2 -> V_42 -- ;
F_14 ( L_5 ,
V_2 -> V_42 ) ;
F_26 ( & V_2 -> V_41 ) ;
}
static int F_68 ( struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_13 * V_14 , int * F_16 )
{
int V_39 ;
struct V_54 * V_55 ;
F_2 ( ! V_2 || ! V_30 || ! V_14 ) ;
V_39 = 0 ;
if ( F_16 )
* F_16 = 0 ;
F_24 ( & V_2 -> V_41 ) ;
if ( V_2 -> V_42 >= V_43 ) {
F_25 ( L_4 ,
V_2 -> V_42 ) ;
V_39 = - V_44 ;
goto V_65;
}
V_55 = V_2 -> V_56 ( V_2 , V_132 ) ;
if ( V_55 == NULL ) {
F_26 ( & V_2 -> V_41 ) ;
return - V_34 ;
}
V_39 = V_55 -> V_58 ( V_55 , & V_30 -> V_55 , & V_30 -> V_59 ,
& V_30 -> V_60 , & V_30 -> V_37 ) ;
if ( V_39 != 0 )
goto V_65;
F_29 ( & V_30 -> V_46 , & V_14 -> V_45 ) ;
if ( V_30 -> V_37 . V_70 ) {
V_2 -> V_47 ++ ;
V_39 = F_35 ( V_2 , false ) ;
}
V_2 -> V_42 ++ ;
F_14 ( L_5 ,
V_2 -> V_42 ) ;
V_65:
F_26 ( & V_2 -> V_41 ) ;
return V_39 ;
}
static int F_69 ( unsigned int * V_123 ,
unsigned int V_133 ,
unsigned long V_134 )
{
F_2 ( ! V_123 ) ;
V_134 += V_135 ;
while ( * V_123 != V_133 ) {
if ( F_70 ( V_135 , V_134 ) ) {
F_38 ( L_20 ) ;
return - V_136 ;
}
F_71 () ;
}
return 0 ;
}
static int F_65 ( struct V_1 * V_2 , bool V_41 )
{
int V_39 ;
F_2 ( ! V_2 ) ;
V_39 = 0 ;
if ( V_41 )
F_24 ( & V_2 -> V_41 ) ;
if ( V_2 -> V_118 == false )
goto V_65;
V_39 = F_72 ( & V_2 -> V_117 , V_137 ,
V_138 , 0 , false , 0 ) ;
if ( V_39 != 0 )
goto V_65;
* V_2 -> V_123 = V_139 ;
F_73 ( & V_2 -> V_117 , V_2 -> V_126 ,
V_140 ) ;
F_69 ( V_2 -> V_123 , V_140 ,
V_68 ) ;
F_74 ( & V_2 -> V_117 ) ;
V_2 -> V_118 = false ;
V_65:
if ( V_41 )
F_26 ( & V_2 -> V_41 ) ;
return V_39 ;
}
static int F_35 ( struct V_1 * V_2 , bool V_41 )
{
int V_39 ;
F_2 ( ! V_2 ) ;
if ( V_41 )
F_24 ( & V_2 -> V_41 ) ;
V_39 = F_65 ( V_2 , false ) ;
if ( V_39 != 0 ) {
F_38 ( L_21 ) ;
goto V_65;
}
if ( V_2 -> V_47 <= 0 || V_2 -> V_81 <= 0 ) {
V_39 = 0 ;
goto V_65;
}
if ( V_2 -> V_118 ) {
V_39 = 0 ;
goto V_65;
}
V_39 = F_75 ( & V_2 -> V_117 , & V_2 -> V_80 ) ;
if ( V_39 != 0 ) {
F_38 ( L_22 ) ;
goto V_65;
}
V_2 -> V_118 = true ;
V_65:
if ( V_41 )
F_26 ( & V_2 -> V_41 ) ;
return V_39 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_29 * V_30 )
{
int V_39 ;
struct V_54 * V_55 ;
F_2 ( ! V_2 || ! V_14 || ! V_30 ) ;
V_39 = 0 ;
F_24 ( & V_2 -> V_41 ) ;
V_55 = V_2 -> V_56 ( V_2 , V_132 ) ;
if ( ! V_55 ) {
V_39 = - V_34 ;
goto V_141;
}
F_33 ( & V_30 -> V_46 ) ;
V_2 -> V_47 -- ;
F_35 ( V_2 , false ) ;
V_55 -> V_64 ( V_55 , V_30 -> V_55 , V_30 -> V_59 ) ;
V_2 -> V_42 -- ;
F_14 ( L_5 ,
V_2 -> V_42 ) ;
F_26 ( & V_2 -> V_41 ) ;
return 0 ;
V_141:
F_26 ( & V_2 -> V_41 ) ;
return V_39 ;
}
static bool F_77 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
enum V_142 V_143 ,
enum V_142 V_144 ,
void V_62 * V_145 ,
T_2 V_146 )
{
T_1 V_147 ;
T_1 V_148 ;
F_14 ( L_3 , V_40 ) ;
F_24 ( & V_2 -> V_41 ) ;
if ( V_146 == 0 ) {
V_14 -> V_20 = 1 ;
V_14 -> V_19 = 0 ;
} else {
T_2 V_149 = ( V_150 ) V_145 ;
T_2 V_151 = V_149 + V_146 - 1 ;
if ( V_151 <= V_149 )
goto V_65;
if ( ( V_149 & V_152 ) != 0 )
goto V_65;
if ( ( V_151 & V_152 ) != V_153 )
goto V_65;
V_14 -> V_20 = V_149 >> 16 ;
V_14 -> V_19 = V_151 >> 16 ;
}
V_147 = ( V_143 == V_154 ) ?
V_18 :
V_155 ;
V_148 = ( V_144 == V_154 ) ?
V_18 :
V_155 ;
V_14 -> V_16 = ( V_14 -> V_16 & V_25 )
| F_9 ( V_17 )
| F_10 ( V_147 )
| F_11 ( V_148 ) ;
if ( ( V_72 == V_73 ) && ( V_14 -> V_28 != 0 ) )
F_15 ( V_2 , V_14 ) ;
F_14 ( L_23 ,
V_14 -> V_16 , V_14 -> V_20 ,
V_14 -> V_19 ) ;
F_26 ( & V_2 -> V_41 ) ;
return true ;
V_65:
F_26 ( & V_2 -> V_41 ) ;
return false ;
}
struct V_1 * F_78 ( struct V_156 * V_3 )
{
struct V_1 * V_2 ;
F_2 ( ! V_3 ) ;
V_2 = F_40 ( sizeof( struct V_1 ) , V_79 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_3 = V_3 ;
switch ( V_72 ) {
case V_157 :
case V_158 :
V_2 -> V_159 = F_68 ;
V_2 -> V_160 = F_58 ;
V_2 -> V_161 = F_59 ;
V_2 -> V_162 = F_64 ;
V_2 -> V_163 = F_76 ;
V_2 -> F_34 = F_34 ;
V_2 -> V_56 = F_36 ;
V_2 -> V_164 = F_39 ;
V_2 -> V_165 = F_41 ;
V_2 -> V_166 = F_53 ;
V_2 -> V_167 = F_66 ;
V_2 -> V_168 = F_67 ;
V_2 -> F_77 = F_77 ;
break;
case V_73 :
V_2 -> V_161 = F_54 ;
V_2 -> V_162 = F_55 ;
V_2 -> V_159 = F_22 ;
V_2 -> V_163 = F_32 ;
V_2 -> F_34 = F_34 ;
V_2 -> V_56 = F_36 ;
V_2 -> V_164 = F_39 ;
V_2 -> V_165 = F_41 ;
V_2 -> V_160 = F_48 ;
V_2 -> V_166 = F_53 ;
V_2 -> F_77 = F_77 ;
break;
default:
F_79 () ;
break;
}
if ( V_2 -> V_160 ( V_2 ) != 0 ) {
F_43 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
void F_80 ( struct V_1 * V_2 )
{
F_2 ( ! V_2 ) ;
V_2 -> V_166 ( V_2 ) ;
F_43 ( V_2 ) ;
}
