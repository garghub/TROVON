static void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
T_1 V_7 = 0 , V_8 = 0 ;
if ( V_2 -> V_9 . V_10 == 0 )
V_2 -> V_9 . V_11 |= V_2 -> V_9 . V_12 ;
if ( V_2 -> V_9 . V_13 &&
( ( ( V_2 -> V_9 . V_13 != V_2 -> V_9 . V_11 ||
V_2 -> V_4 != V_4 ) ) ||
( V_2 -> V_14 && ! V_2 -> V_15 ) ) ) {
V_8 |= V_2 -> V_9 . V_13 ;
V_7 |=
V_2 -> V_9 . V_11 & ~ V_2 -> V_9 . V_13 ;
}
V_7 |= V_2 -> V_9 . V_11 & ~ V_2 -> V_9 . V_12 ;
if ( ( V_8 | V_7 ) & V_16 )
F_2 ( V_2 ) ;
if ( V_2 -> V_9 . V_10 )
V_6 -> V_17 |= F_3 ( & V_2 -> V_18 ) ;
if ( V_8 == 0 && V_2 -> V_9 . V_10 == 0 )
V_2 -> V_9 . V_10 = V_2 -> V_9 . V_13 ;
V_6 -> V_7 |= V_7 ;
V_6 -> V_8 |= V_8 ;
if ( V_8 & V_19 )
V_6 -> V_20 |= V_2 -> V_4 -> V_21 ;
if ( V_7 & V_19 )
V_6 -> V_20 |= V_4 -> V_21 ;
}
static struct V_22 *
F_4 ( int V_23 )
{
struct V_22 * V_24 ;
int V_25 = V_26 / sizeof( struct V_27 ) / 2 ;
while ( V_25 > V_23 )
V_25 >>= 1 ;
V_24 = F_5 ( V_25 * sizeof( struct V_27 ) +
sizeof( struct V_22 ) ,
V_28 ) ;
if ( V_24 == NULL )
return V_24 ;
V_24 -> V_29 = V_25 - 1 ;
return V_24 ;
}
static void
F_6 ( struct V_22 * V_24 )
{
memset ( V_24 -> V_30 , 0 , ( V_24 -> V_29 + 1 ) * sizeof( struct V_27 ) ) ;
}
static void
F_7 ( struct V_22 * V_24 , struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_31 ,
& V_24 -> V_30 [ V_2 -> V_32 & V_24 -> V_29 ] ) ;
}
static struct V_1 *
F_9 ( struct V_22 * V_24 , unsigned long V_33 )
{
struct V_27 * V_34 ;
struct V_35 * V_36 ;
struct V_1 * V_2 ;
V_34 = & V_24 -> V_30 [ V_33 & V_24 -> V_29 ] ;
F_10 (node, head) {
V_2 = F_11 ( V_36 , struct V_1 , V_31 ) ;
if ( V_2 -> V_32 == V_33 )
return V_2 ;
}
return NULL ;
}
static void
F_12 ( struct V_22 * V_24 )
{
F_13 ( V_24 ) ;
}
static int
F_14 ( struct V_1 * V_2 ,
struct V_22 * V_24 ,
struct V_37 * V_38 )
{
struct V_39 * V_40 = V_2 -> V_9 . V_40 ;
struct V_41 * V_42 ;
T_1 V_43 ;
int V_44 = - V_45 ;
V_42 = & F_9 ( V_24 , V_38 -> V_46 ) -> V_9 ;
if ( F_15 ( V_42 == NULL ) )
return - V_47 ;
V_43 = F_16 ( V_42 ) -> V_48 ;
if ( F_15 ( V_43 == 0 ) ) {
F_17 ( L_1 ,
V_38 -> V_46 ) ;
return V_44 ;
}
if ( F_15 ( V_38 -> V_13 & ( V_38 -> V_13 - 1 ) ) ) {
F_17 ( L_2
L_3
L_4 ,
V_2 , V_38 -> V_46 ,
( int ) V_38 -> V_49 ,
V_38 -> V_12 ,
V_38 -> V_13 ) ;
return V_44 ;
}
if ( F_15 ( ( V_38 -> V_13 | V_38 -> V_12 ) & V_16 ) ) {
F_17 ( L_5
L_3
L_4 ,
V_2 , V_38 -> V_46 ,
( int ) V_38 -> V_49 ,
V_38 -> V_12 ,
V_38 -> V_13 ) ;
return V_44 ;
}
if ( F_15 ( V_38 -> V_13 && V_42 -> V_10 &&
V_38 -> V_13 != V_42 -> V_10 ) ) {
F_17 ( L_6
L_3
L_7 ,
V_2 , V_38 -> V_46 ,
( int ) V_38 -> V_49 ,
V_38 -> V_13 ,
V_42 -> V_10 ) ;
return V_44 ;
}
V_42 -> V_11 |= V_38 -> V_12 ;
V_42 -> V_10 |= V_38 -> V_13 ;
if ( V_43 == V_38 -> V_50 )
return 0 ;
if ( F_15 ( V_38 -> V_49 > V_2 -> V_9 . V_23 - 4 ) ) {
F_17 ( L_8
L_9 ,
V_2 , V_38 -> V_46 ,
( int ) V_38 -> V_49 ,
( int ) V_2 -> V_9 . V_23 ) ;
return V_44 ;
}
if ( F_15 ( V_38 -> V_49 & 3 ) ) {
F_17 ( L_10
L_11 ,
V_2 , V_38 -> V_46 ,
( int ) V_38 -> V_49 ) ;
return V_44 ;
}
V_38 -> V_51 += V_43 ;
if ( V_2 -> V_9 . V_13 == V_16 ) {
T_1 V_52 = V_38 -> V_49 & ~ V_53 ;
char * V_54 ;
V_54 = F_18 ( V_2 -> V_55 [ V_38 -> V_49 >> V_56 ] ) ;
* ( T_1 * ) ( V_54 + V_52 ) = V_38 -> V_51 ;
F_19 ( V_54 ) ;
} else {
struct V_57 * V_58 = V_40 -> V_59 ;
T_1 T_2 * V_60 ;
void T_2 * V_61 ;
if ( V_2 -> V_62 && F_20 () )
return - V_63 ;
V_44 = F_21 ( V_2 , 1 ) ;
if ( V_44 )
return V_44 ;
V_38 -> V_49 += V_2 -> V_48 ;
V_61 = F_22 ( V_58 -> V_64 . V_65 ,
V_38 -> V_49 & V_53 ) ;
V_60 = ( T_1 T_2 * )
( V_61 + ( V_38 -> V_49 & ~ V_53 ) ) ;
F_23 ( V_38 -> V_51 , V_60 ) ;
F_24 ( V_61 ) ;
}
V_38 -> V_50 = V_43 ;
return 0 ;
}
static int
F_25 ( struct V_1 * V_2 ,
struct V_22 * V_24 )
{
struct V_37 T_3 * V_66 ;
struct V_67 * V_68 = V_2 -> V_69 ;
int V_70 , V_44 ;
V_66 = ( void T_3 * ) ( V_71 ) V_68 -> V_72 ;
for ( V_70 = 0 ; V_70 < V_68 -> V_73 ; V_70 ++ ) {
struct V_37 V_38 ;
if ( F_26 ( & V_38 ,
V_66 + V_70 ,
sizeof( V_38 ) ) )
return - V_63 ;
V_44 = F_14 ( V_2 , V_24 , & V_38 ) ;
if ( V_44 )
return V_44 ;
if ( F_27 ( & V_66 [ V_70 ] . V_50 ,
& V_38 . V_50 ,
sizeof( V_38 . V_50 ) ) )
return - V_63 ;
}
return 0 ;
}
static int
F_28 ( struct V_1 * V_2 ,
struct V_22 * V_24 ,
struct V_37 * V_74 )
{
const struct V_67 * V_68 = V_2 -> V_69 ;
int V_70 , V_44 ;
for ( V_70 = 0 ; V_70 < V_68 -> V_73 ; V_70 ++ ) {
V_44 = F_14 ( V_2 , V_24 , & V_74 [ V_70 ] ) ;
if ( V_44 )
return V_44 ;
}
return 0 ;
}
static int
F_29 ( struct V_39 * V_40 ,
struct V_22 * V_24 ,
struct V_75 * V_76 )
{
struct V_1 * V_2 ;
int V_44 = 0 ;
F_30 () ;
F_31 (obj, objects, exec_list) {
V_44 = F_25 ( V_2 , V_24 ) ;
if ( V_44 )
break;
}
F_32 () ;
return V_44 ;
}
static int
F_33 ( struct V_3 * V_4 ,
struct V_77 * V_78 ,
struct V_75 * V_76 )
{
struct V_1 * V_2 ;
int V_44 , V_79 ;
bool V_80 = F_34 ( V_4 -> V_40 ) -> V_81 < 4 ;
struct V_75 V_82 ;
F_35 ( & V_82 ) ;
while ( ! F_36 ( V_76 ) ) {
struct V_67 * V_68 ;
bool V_83 , V_84 ;
V_2 = F_37 ( V_76 ,
struct V_1 ,
V_85 ) ;
V_68 = V_2 -> V_69 ;
V_83 =
V_80 &&
V_68 -> V_86 & V_87 &&
V_2 -> V_88 != V_89 ;
V_84 =
V_68 -> V_73 ? true : V_83 ;
if ( V_84 )
F_38 ( & V_2 -> V_85 , & V_82 ) ;
else
F_39 ( & V_2 -> V_85 , & V_82 ) ;
V_2 -> V_9 . V_11 = 0 ;
V_2 -> V_9 . V_10 = 0 ;
}
F_40 ( & V_82 , V_76 ) ;
V_79 = 0 ;
do {
V_44 = 0 ;
F_31 (obj, objects, exec_list) {
struct V_67 * V_68 = V_2 -> V_69 ;
bool V_83 , V_84 ;
if ( ! V_2 -> V_90 )
continue;
V_83 =
V_80 &&
V_68 -> V_86 & V_87 &&
V_2 -> V_88 != V_89 ;
V_84 =
V_68 -> V_73 ? true : V_83 ;
if ( ( V_68 -> V_91 && V_2 -> V_48 & ( V_68 -> V_91 - 1 ) ) ||
( V_84 && ! V_2 -> V_92 ) )
V_44 = F_41 ( V_2 ) ;
else
V_44 = F_42 ( V_2 ,
V_68 -> V_91 ,
V_84 ) ;
if ( V_44 )
goto V_93;
V_68 ++ ;
}
F_31 (obj, objects, exec_list) {
struct V_67 * V_68 = V_2 -> V_69 ;
bool V_83 ;
V_83 =
V_80 &&
V_68 -> V_86 & V_87 &&
V_2 -> V_88 != V_89 ;
if ( ! V_2 -> V_90 ) {
bool V_84 =
V_68 -> V_73 ? true : V_83 ;
V_44 = F_42 ( V_2 ,
V_68 -> V_91 ,
V_84 ) ;
if ( V_44 )
break;
}
if ( V_80 ) {
if ( V_83 ) {
V_44 = F_43 ( V_2 , V_4 ) ;
if ( V_44 )
break;
} else if ( V_68 -> V_86 & V_87 &&
V_2 -> V_88 == V_89 ) {
V_44 = F_44 ( V_2 ) ;
if ( V_44 )
break;
}
V_2 -> V_15 = V_83 ;
}
V_68 -> V_49 = V_2 -> V_48 ;
}
F_31 (obj, objects, exec_list) {
if ( V_2 -> V_90 )
F_45 ( V_2 ) ;
}
if ( V_44 != - V_94 || V_79 > 1 )
return V_44 ;
V_44 = F_46 ( V_4 -> V_40 , V_79 == 0 ) ;
if ( V_44 )
return V_44 ;
V_79 ++ ;
} while ( 1 );
V_93:
V_2 = F_47 ( V_2 -> V_85 . V_95 ,
struct V_1 ,
V_85 ) ;
while ( V_76 != & V_2 -> V_85 ) {
if ( V_2 -> V_90 )
F_45 ( V_2 ) ;
V_2 = F_47 ( V_2 -> V_85 . V_95 ,
struct V_1 ,
V_85 ) ;
}
return V_44 ;
}
static int
F_48 ( struct V_39 * V_40 ,
struct V_77 * V_78 ,
struct V_3 * V_4 ,
struct V_75 * V_76 ,
struct V_22 * V_24 ,
struct V_67 * V_96 ,
int V_25 )
{
struct V_37 * V_38 ;
struct V_1 * V_2 ;
int * V_97 ;
int V_70 , V_98 , V_44 ;
while ( ! F_36 ( V_76 ) ) {
V_2 = F_37 ( V_76 ,
struct V_1 ,
V_85 ) ;
F_49 ( & V_2 -> V_85 ) ;
F_50 ( & V_2 -> V_9 ) ;
}
F_51 ( & V_40 -> V_99 ) ;
V_98 = 0 ;
for ( V_70 = 0 ; V_70 < V_25 ; V_70 ++ )
V_98 += V_96 [ V_70 ] . V_73 ;
V_97 = F_52 ( V_25 , sizeof( * V_97 ) ) ;
V_38 = F_52 ( V_98 , sizeof( * V_38 ) ) ;
if ( V_38 == NULL || V_97 == NULL ) {
F_53 ( V_38 ) ;
F_53 ( V_97 ) ;
F_54 ( & V_40 -> V_99 ) ;
return - V_100 ;
}
V_98 = 0 ;
for ( V_70 = 0 ; V_70 < V_25 ; V_70 ++ ) {
struct V_37 T_3 * V_66 ;
V_66 = ( void T_3 * ) ( V_71 ) V_96 [ V_70 ] . V_72 ;
if ( F_55 ( V_38 + V_98 , V_66 ,
V_96 [ V_70 ] . V_73 * sizeof( * V_38 ) ) ) {
V_44 = - V_63 ;
F_54 ( & V_40 -> V_99 ) ;
goto V_93;
}
V_97 [ V_70 ] = V_98 ;
V_98 += V_96 [ V_70 ] . V_73 ;
}
V_44 = F_56 ( V_40 ) ;
if ( V_44 ) {
F_54 ( & V_40 -> V_99 ) ;
goto V_93;
}
F_6 ( V_24 ) ;
for ( V_70 = 0 ; V_70 < V_25 ; V_70 ++ ) {
V_2 = F_16 ( F_57 ( V_40 , V_78 ,
V_96 [ V_70 ] . V_33 ) ) ;
if ( & V_2 -> V_9 == NULL ) {
F_17 ( L_12 ,
V_96 [ V_70 ] . V_33 , V_70 ) ;
V_44 = - V_47 ;
goto V_93;
}
F_58 ( & V_2 -> V_85 , V_76 ) ;
V_2 -> V_32 = V_96 [ V_70 ] . V_33 ;
V_2 -> V_69 = & V_96 [ V_70 ] ;
F_7 ( V_24 , V_2 ) ;
}
V_44 = F_33 ( V_4 , V_78 , V_76 ) ;
if ( V_44 )
goto V_93;
F_31 (obj, objects, exec_list) {
int V_49 = V_2 -> V_69 - V_96 ;
V_44 = F_28 ( V_2 , V_24 ,
V_38 + V_97 [ V_49 ] ) ;
if ( V_44 )
goto V_93;
}
V_93:
F_53 ( V_38 ) ;
F_53 ( V_97 ) ;
return V_44 ;
}
static int
F_59 ( struct V_39 * V_40 ,
T_1 V_7 ,
T_1 V_8 ,
T_1 V_20 )
{
T_4 * V_58 = V_40 -> V_59 ;
int V_70 , V_44 ;
if ( V_8 & V_16 )
F_60 () ;
if ( V_8 & V_101 )
F_61 () ;
if ( ( V_8 | V_7 ) & V_19 ) {
for ( V_70 = 0 ; V_70 < V_102 ; V_70 ++ )
if ( V_20 & ( 1 << V_70 ) ) {
V_44 = F_62 ( & V_58 -> V_4 [ V_70 ] ,
V_7 ,
V_8 ) ;
if ( V_44 )
return V_44 ;
}
}
return 0 ;
}
static bool
F_63 ( struct V_39 * V_40 )
{
if ( F_34 ( V_40 ) -> V_81 < 6 )
return 0 ;
if ( V_103 >= 0 )
return V_103 ;
if ( F_34 ( V_40 ) -> V_81 == 6 )
return 0 ;
return 1 ;
}
static int
F_64 ( struct V_1 * V_2 ,
struct V_3 * V_104 )
{
struct V_3 * V_105 = V_2 -> V_4 ;
T_5 V_106 ;
int V_44 , V_107 ;
if ( V_105 == NULL || V_104 == V_105 )
return 0 ;
if ( ! F_63 ( V_2 -> V_9 . V_40 ) )
return F_65 ( V_2 ) ;
V_107 = F_66 ( V_105 , V_104 ) ;
V_106 = V_2 -> V_108 ;
if ( V_106 <= V_105 -> V_109 [ V_107 ] )
return 0 ;
if ( V_106 == V_105 -> V_110 ) {
struct V_111 * V_112 ;
V_112 = F_5 ( sizeof( * V_112 ) , V_28 ) ;
if ( V_112 == NULL )
return - V_100 ;
V_44 = F_67 ( V_105 , NULL , V_112 ) ;
if ( V_44 ) {
F_13 ( V_112 ) ;
return V_44 ;
}
V_106 = V_112 -> V_106 ;
}
V_105 -> V_109 [ V_107 ] = V_106 ;
return V_104 -> V_113 ( V_104 , V_105 , V_106 - 1 ) ;
}
static int
F_68 ( struct V_3 * V_4 , T_5 V_17 )
{
T_5 V_114 , V_115 ;
int V_44 ;
for ( V_114 = 0 ; V_17 >> V_114 ; V_114 ++ ) {
if ( ( ( V_17 >> V_114 ) & 1 ) == 0 )
continue;
if ( V_114 )
V_115 = V_116 ;
else
V_115 = V_117 ;
V_44 = F_69 ( V_4 , 2 ) ;
if ( V_44 )
return V_44 ;
F_70 ( V_4 , V_118 | V_115 ) ;
F_70 ( V_4 , V_119 ) ;
F_71 ( V_4 ) ;
}
return 0 ;
}
static int
F_72 ( struct V_3 * V_4 ,
struct V_75 * V_76 )
{
struct V_1 * V_2 ;
struct V_5 V_6 ;
int V_44 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
F_31 (obj, objects, exec_list)
F_1 ( V_2 , V_4 , & V_6 ) ;
if ( V_6 . V_7 | V_6 . V_8 ) {
V_44 = F_59 ( V_4 -> V_40 ,
V_6 . V_7 ,
V_6 . V_8 ,
V_6 . V_20 ) ;
if ( V_44 )
return V_44 ;
}
if ( V_6 . V_17 ) {
V_44 = F_68 ( V_4 , V_6 . V_17 ) ;
if ( V_44 )
return V_44 ;
}
F_31 (obj, objects, exec_list) {
V_44 = F_64 ( V_2 , V_4 ) ;
if ( V_44 )
return V_44 ;
}
return 0 ;
}
static bool
F_73 ( struct V_120 * V_96 )
{
return ( ( V_96 -> V_121 | V_96 -> V_122 ) & 0x7 ) == 0 ;
}
static int
F_74 ( struct V_67 * V_96 ,
int V_25 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < V_25 ; V_70 ++ ) {
char T_3 * V_123 = ( char T_3 * ) ( V_71 ) V_96 [ V_70 ] . V_72 ;
int V_124 ;
if ( V_96 [ V_70 ] . V_73 >
V_125 / sizeof( struct V_37 ) )
return - V_45 ;
V_124 = V_96 [ V_70 ] . V_73 *
sizeof( struct V_37 ) ;
if ( ! F_75 ( V_126 , V_123 , V_124 ) )
return - V_63 ;
if ( ! F_75 ( V_127 , V_123 , V_124 ) )
return - V_63 ;
if ( F_76 ( V_123 , V_124 ) )
return - V_63 ;
}
return 0 ;
}
static void
F_77 ( struct V_75 * V_76 ,
struct V_3 * V_4 ,
T_5 V_106 )
{
struct V_1 * V_2 ;
F_31 (obj, objects, exec_list) {
T_5 V_128 = V_2 -> V_9 . V_12 ;
T_5 V_129 = V_2 -> V_9 . V_13 ;
V_2 -> V_9 . V_12 = V_2 -> V_9 . V_11 ;
V_2 -> V_9 . V_13 = V_2 -> V_9 . V_10 ;
V_2 -> V_14 = V_2 -> V_15 ;
F_78 ( V_2 , V_4 , V_106 ) ;
if ( V_2 -> V_9 . V_13 ) {
V_2 -> V_130 = 1 ;
V_2 -> V_131 = true ;
F_39 ( & V_2 -> V_132 ,
& V_4 -> V_132 ) ;
F_79 ( V_4 -> V_40 , V_2 ) ;
}
F_80 ( V_2 , V_128 , V_129 ) ;
}
}
static void
F_81 ( struct V_39 * V_40 ,
struct V_77 * V_78 ,
struct V_3 * V_4 )
{
struct V_111 * V_112 ;
T_5 V_133 ;
V_133 = V_134 ;
if ( F_34 ( V_40 ) -> V_81 >= 4 )
V_133 |= V_135 ;
if ( V_4 -> V_136 ( V_4 , V_133 , 0 ) ) {
F_82 ( V_4 ) ;
return;
}
V_112 = F_5 ( sizeof( * V_112 ) , V_28 ) ;
if ( V_112 == NULL || F_67 ( V_4 , V_78 , V_112 ) ) {
F_82 ( V_4 ) ;
F_13 ( V_112 ) ;
}
}
static int
F_83 ( struct V_39 * V_40 ,
struct V_3 * V_4 )
{
T_4 * V_58 = V_40 -> V_59 ;
int V_44 , V_70 ;
if ( ! F_84 ( V_40 ) || V_4 != & V_58 -> V_4 [ V_137 ] )
return 0 ;
V_44 = F_69 ( V_4 , 4 * 3 ) ;
if ( V_44 )
return V_44 ;
for ( V_70 = 0 ; V_70 < 4 ; V_70 ++ ) {
F_70 ( V_4 , F_85 ( 1 ) ) ;
F_70 ( V_4 , F_86 ( V_70 ) ) ;
F_70 ( V_4 , 0 ) ;
}
F_71 ( V_4 ) ;
return 0 ;
}
static int
F_87 ( struct V_39 * V_40 , void * V_138 ,
struct V_77 * V_78 ,
struct V_120 * args ,
struct V_67 * V_96 )
{
T_4 * V_58 = V_40 -> V_59 ;
struct V_75 V_76 ;
struct V_22 * V_24 ;
struct V_1 * V_139 ;
struct V_140 * V_141 = NULL ;
struct V_3 * V_4 ;
T_5 V_142 , V_143 ;
T_5 V_106 ;
T_5 V_144 ;
int V_44 , V_145 , V_70 ;
if ( ! F_73 ( args ) ) {
F_17 ( L_13 ) ;
return - V_45 ;
}
V_44 = F_74 ( V_96 , args -> V_146 ) ;
if ( V_44 )
return V_44 ;
switch ( args -> V_86 & V_147 ) {
case V_148 :
case V_149 :
V_4 = & V_58 -> V_4 [ V_137 ] ;
break;
case V_150 :
if ( ! F_88 ( V_40 ) ) {
F_17 ( L_14 ) ;
return - V_45 ;
}
V_4 = & V_58 -> V_4 [ V_151 ] ;
break;
case V_152 :
if ( ! F_89 ( V_40 ) ) {
F_17 ( L_15 ) ;
return - V_45 ;
}
V_4 = & V_58 -> V_4 [ V_153 ] ;
break;
default:
F_17 ( L_16 ,
( int ) ( args -> V_86 & V_147 ) ) ;
return - V_45 ;
}
V_145 = args -> V_86 & V_154 ;
V_144 = V_154 ;
switch ( V_145 ) {
case V_155 :
case V_156 :
case V_157 :
if ( V_4 == & V_58 -> V_4 [ V_137 ] &&
V_145 != V_58 -> V_158 ) {
if ( F_34 ( V_40 ) -> V_81 < 4 )
return - V_45 ;
if ( F_34 ( V_40 ) -> V_81 > 5 &&
V_145 == V_157 )
return - V_45 ;
if ( F_34 ( V_40 ) -> V_81 >= 6 )
V_144 &= ~ V_157 ;
}
break;
default:
F_17 ( L_17 , V_145 ) ;
return - V_45 ;
}
if ( args -> V_146 < 1 ) {
F_17 ( L_18 , args -> V_146 ) ;
return - V_45 ;
}
if ( args -> V_159 != 0 ) {
if ( V_4 != & V_58 -> V_4 [ V_137 ] ) {
F_17 ( L_19 ) ;
return - V_45 ;
}
V_141 = F_90 ( args -> V_159 * sizeof( * V_141 ) ,
V_28 ) ;
if ( V_141 == NULL ) {
V_44 = - V_100 ;
goto V_160;
}
if ( F_55 ( V_141 ,
(struct V_140 T_3 * ) ( V_71 )
args -> V_161 ,
sizeof( * V_141 ) * args -> V_159 ) ) {
V_44 = - V_63 ;
goto V_160;
}
}
V_44 = F_56 ( V_40 ) ;
if ( V_44 )
goto V_160;
if ( V_58 -> V_64 . V_162 ) {
F_51 ( & V_40 -> V_99 ) ;
V_44 = - V_163 ;
goto V_160;
}
V_24 = F_4 ( args -> V_146 ) ;
if ( V_24 == NULL ) {
F_51 ( & V_40 -> V_99 ) ;
V_44 = - V_100 ;
goto V_160;
}
F_35 ( & V_76 ) ;
for ( V_70 = 0 ; V_70 < args -> V_146 ; V_70 ++ ) {
struct V_1 * V_2 ;
V_2 = F_16 ( F_57 ( V_40 , V_78 ,
V_96 [ V_70 ] . V_33 ) ) ;
if ( & V_2 -> V_9 == NULL ) {
F_17 ( L_12 ,
V_96 [ V_70 ] . V_33 , V_70 ) ;
V_44 = - V_47 ;
goto V_93;
}
if ( ! F_36 ( & V_2 -> V_85 ) ) {
F_17 ( L_20 ,
V_2 , V_96 [ V_70 ] . V_33 , V_70 ) ;
V_44 = - V_45 ;
goto V_93;
}
F_58 ( & V_2 -> V_85 , & V_76 ) ;
V_2 -> V_32 = V_96 [ V_70 ] . V_33 ;
V_2 -> V_69 = & V_96 [ V_70 ] ;
F_7 ( V_24 , V_2 ) ;
}
V_139 = F_47 ( V_76 . V_95 ,
struct V_1 ,
V_85 ) ;
V_44 = F_33 ( V_4 , V_78 , & V_76 ) ;
if ( V_44 )
goto V_93;
V_44 = F_29 ( V_40 , V_24 , & V_76 ) ;
if ( V_44 ) {
if ( V_44 == - V_63 ) {
V_44 = F_48 ( V_40 , V_78 , V_4 ,
& V_76 , V_24 ,
V_96 ,
args -> V_146 ) ;
F_91 ( ! F_92 ( & V_40 -> V_99 ) ) ;
}
if ( V_44 )
goto V_93;
}
if ( V_139 -> V_9 . V_10 ) {
F_17 ( L_21 ) ;
V_44 = - V_45 ;
goto V_93;
}
V_139 -> V_9 . V_11 |= V_134 ;
V_44 = F_72 ( V_4 , & V_76 ) ;
if ( V_44 )
goto V_93;
V_106 = F_82 ( V_4 ) ;
for ( V_70 = 0 ; V_70 < F_93 ( V_4 -> V_109 ) ; V_70 ++ ) {
if ( V_106 < V_4 -> V_109 [ V_70 ] ) {
V_44 = F_94 ( V_40 ) ;
if ( V_44 )
goto V_93;
F_91 ( V_4 -> V_109 [ V_70 ] ) ;
}
}
if ( V_4 == & V_58 -> V_4 [ V_137 ] &&
V_145 != V_58 -> V_158 ) {
V_44 = F_69 ( V_4 , 4 ) ;
if ( V_44 )
goto V_93;
F_70 ( V_4 , V_119 ) ;
F_70 ( V_4 , F_85 ( 1 ) ) ;
F_70 ( V_4 , V_164 ) ;
F_70 ( V_4 , V_144 << 16 | V_145 ) ;
F_71 ( V_4 ) ;
V_58 -> V_158 = V_145 ;
}
if ( args -> V_86 & V_165 ) {
V_44 = F_83 ( V_40 , V_4 ) ;
if ( V_44 )
goto V_93;
}
F_95 ( V_4 , V_106 ) ;
V_142 = V_139 -> V_48 + args -> V_121 ;
V_143 = args -> V_122 ;
if ( V_141 ) {
for ( V_70 = 0 ; V_70 < args -> V_159 ; V_70 ++ ) {
V_44 = F_96 ( V_40 , & V_141 [ V_70 ] ,
args -> V_166 , args -> V_167 ) ;
if ( V_44 )
goto V_93;
V_44 = V_4 -> V_168 ( V_4 ,
V_142 , V_143 ) ;
if ( V_44 )
goto V_93;
}
} else {
V_44 = V_4 -> V_168 ( V_4 , V_142 , V_143 ) ;
if ( V_44 )
goto V_93;
}
F_77 ( & V_76 , V_4 , V_106 ) ;
F_81 ( V_40 , V_78 , V_4 ) ;
V_93:
F_12 ( V_24 ) ;
while ( ! F_36 ( & V_76 ) ) {
struct V_1 * V_2 ;
V_2 = F_37 ( & V_76 ,
struct V_1 ,
V_85 ) ;
F_49 ( & V_2 -> V_85 ) ;
F_50 ( & V_2 -> V_9 ) ;
}
F_51 ( & V_40 -> V_99 ) ;
V_160:
F_13 ( V_141 ) ;
return V_44 ;
}
int
F_97 ( struct V_39 * V_40 , void * V_138 ,
struct V_77 * V_78 )
{
struct V_169 * args = V_138 ;
struct V_120 V_170 ;
struct V_171 * V_85 = NULL ;
struct V_67 * V_172 = NULL ;
int V_44 , V_70 ;
if ( args -> V_146 < 1 ) {
F_17 ( L_18 , args -> V_146 ) ;
return - V_45 ;
}
V_85 = F_52 ( sizeof( * V_85 ) , args -> V_146 ) ;
V_172 = F_52 ( sizeof( * V_172 ) , args -> V_146 ) ;
if ( V_85 == NULL || V_172 == NULL ) {
F_17 ( L_22 ,
args -> V_146 ) ;
F_53 ( V_85 ) ;
F_53 ( V_172 ) ;
return - V_100 ;
}
V_44 = F_55 ( V_85 ,
(struct V_173 T_3 * )
( V_71 ) args -> V_174 ,
sizeof( * V_85 ) * args -> V_146 ) ;
if ( V_44 != 0 ) {
F_17 ( L_23 ,
args -> V_146 , V_44 ) ;
F_53 ( V_85 ) ;
F_53 ( V_172 ) ;
return - V_63 ;
}
for ( V_70 = 0 ; V_70 < args -> V_146 ; V_70 ++ ) {
V_172 [ V_70 ] . V_33 = V_85 [ V_70 ] . V_33 ;
V_172 [ V_70 ] . V_73 = V_85 [ V_70 ] . V_73 ;
V_172 [ V_70 ] . V_72 = V_85 [ V_70 ] . V_72 ;
V_172 [ V_70 ] . V_91 = V_85 [ V_70 ] . V_91 ;
V_172 [ V_70 ] . V_49 = V_85 [ V_70 ] . V_49 ;
if ( F_34 ( V_40 ) -> V_81 < 4 )
V_172 [ V_70 ] . V_86 = V_87 ;
else
V_172 [ V_70 ] . V_86 = 0 ;
}
V_170 . V_174 = args -> V_174 ;
V_170 . V_146 = args -> V_146 ;
V_170 . V_121 = args -> V_121 ;
V_170 . V_122 = args -> V_122 ;
V_170 . V_166 = args -> V_166 ;
V_170 . V_167 = args -> V_167 ;
V_170 . V_159 = args -> V_159 ;
V_170 . V_161 = args -> V_161 ;
V_170 . V_86 = V_149 ;
V_44 = F_87 ( V_40 , V_138 , V_78 , & V_170 , V_172 ) ;
if ( ! V_44 ) {
for ( V_70 = 0 ; V_70 < args -> V_146 ; V_70 ++ )
V_85 [ V_70 ] . V_49 = V_172 [ V_70 ] . V_49 ;
V_44 = F_98 ( (struct V_173 T_3 * )
( V_71 ) args -> V_174 ,
V_85 ,
sizeof( * V_85 ) * args -> V_146 ) ;
if ( V_44 ) {
V_44 = - V_63 ;
F_17 ( L_24
L_25 ,
args -> V_146 , V_44 ) ;
}
}
F_53 ( V_85 ) ;
F_53 ( V_172 ) ;
return V_44 ;
}
int
F_99 ( struct V_39 * V_40 , void * V_138 ,
struct V_77 * V_78 )
{
struct V_120 * args = V_138 ;
struct V_67 * V_172 = NULL ;
int V_44 ;
if ( args -> V_146 < 1 ) {
F_17 ( L_26 , args -> V_146 ) ;
return - V_45 ;
}
V_172 = F_90 ( sizeof( * V_172 ) * args -> V_146 ,
V_28 | V_175 | V_176 ) ;
if ( V_172 == NULL )
V_172 = F_52 ( sizeof( * V_172 ) ,
args -> V_146 ) ;
if ( V_172 == NULL ) {
F_17 ( L_22 ,
args -> V_146 ) ;
return - V_100 ;
}
V_44 = F_55 ( V_172 ,
(struct V_173 T_3 * )
( V_71 ) args -> V_174 ,
sizeof( * V_172 ) * args -> V_146 ) ;
if ( V_44 != 0 ) {
F_17 ( L_23 ,
args -> V_146 , V_44 ) ;
F_53 ( V_172 ) ;
return - V_63 ;
}
V_44 = F_87 ( V_40 , V_138 , V_78 , args , V_172 ) ;
if ( ! V_44 ) {
V_44 = F_98 ( (struct V_173 T_3 * )
( V_71 ) args -> V_174 ,
V_172 ,
sizeof( * V_172 ) * args -> V_146 ) ;
if ( V_44 ) {
V_44 = - V_63 ;
F_17 ( L_24
L_25 ,
args -> V_146 , V_44 ) ;
}
}
F_53 ( V_172 ) ;
return V_44 ;
}
