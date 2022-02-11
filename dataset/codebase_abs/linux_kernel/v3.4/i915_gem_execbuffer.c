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
V_6 -> V_20 |= F_4 ( V_2 -> V_4 ) ;
if ( V_7 & V_19 )
V_6 -> V_20 |= F_4 ( V_4 ) ;
}
static struct V_21 *
F_5 ( int V_22 )
{
struct V_21 * V_23 ;
int V_24 = V_25 / sizeof( struct V_26 ) / 2 ;
while ( V_24 > V_22 )
V_24 >>= 1 ;
V_23 = F_6 ( V_24 * sizeof( struct V_26 ) +
sizeof( struct V_21 ) ,
V_27 ) ;
if ( V_23 == NULL )
return V_23 ;
V_23 -> V_28 = V_24 - 1 ;
return V_23 ;
}
static void
F_7 ( struct V_21 * V_23 )
{
memset ( V_23 -> V_29 , 0 , ( V_23 -> V_28 + 1 ) * sizeof( struct V_26 ) ) ;
}
static void
F_8 ( struct V_21 * V_23 , struct V_1 * V_2 )
{
F_9 ( & V_2 -> V_30 ,
& V_23 -> V_29 [ V_2 -> V_31 & V_23 -> V_28 ] ) ;
}
static struct V_1 *
F_10 ( struct V_21 * V_23 , unsigned long V_32 )
{
struct V_26 * V_33 ;
struct V_34 * V_35 ;
struct V_1 * V_2 ;
V_33 = & V_23 -> V_29 [ V_32 & V_23 -> V_28 ] ;
F_11 (node, head) {
V_2 = F_12 ( V_35 , struct V_1 , V_30 ) ;
if ( V_2 -> V_31 == V_32 )
return V_2 ;
}
return NULL ;
}
static void
F_13 ( struct V_21 * V_23 )
{
F_14 ( V_23 ) ;
}
static int
F_15 ( struct V_1 * V_2 ,
struct V_21 * V_23 ,
struct V_36 * V_37 )
{
struct V_38 * V_39 = V_2 -> V_9 . V_39 ;
struct V_40 * V_41 ;
T_1 V_42 ;
int V_43 = - V_44 ;
V_41 = & F_10 ( V_23 , V_37 -> V_45 ) -> V_9 ;
if ( F_16 ( V_41 == NULL ) )
return - V_46 ;
V_42 = F_17 ( V_41 ) -> V_47 ;
if ( F_16 ( V_42 == 0 ) ) {
F_18 ( L_1 ,
V_37 -> V_45 ) ;
return V_43 ;
}
if ( F_16 ( V_37 -> V_13 & ( V_37 -> V_13 - 1 ) ) ) {
F_18 ( L_2
L_3
L_4 ,
V_2 , V_37 -> V_45 ,
( int ) V_37 -> V_48 ,
V_37 -> V_12 ,
V_37 -> V_13 ) ;
return V_43 ;
}
if ( F_16 ( ( V_37 -> V_13 | V_37 -> V_12 )
& ~ V_19 ) ) {
F_18 ( L_5
L_3
L_4 ,
V_2 , V_37 -> V_45 ,
( int ) V_37 -> V_48 ,
V_37 -> V_12 ,
V_37 -> V_13 ) ;
return V_43 ;
}
if ( F_16 ( V_37 -> V_13 && V_41 -> V_10 &&
V_37 -> V_13 != V_41 -> V_10 ) ) {
F_18 ( L_6
L_3
L_7 ,
V_2 , V_37 -> V_45 ,
( int ) V_37 -> V_48 ,
V_37 -> V_13 ,
V_41 -> V_10 ) ;
return V_43 ;
}
V_41 -> V_11 |= V_37 -> V_12 ;
V_41 -> V_10 |= V_37 -> V_13 ;
if ( V_42 == V_37 -> V_49 )
return 0 ;
if ( F_16 ( V_37 -> V_48 > V_2 -> V_9 . V_22 - 4 ) ) {
F_18 ( L_8
L_9 ,
V_2 , V_37 -> V_45 ,
( int ) V_37 -> V_48 ,
( int ) V_2 -> V_9 . V_22 ) ;
return V_43 ;
}
if ( F_16 ( V_37 -> V_48 & 3 ) ) {
F_18 ( L_10
L_11 ,
V_2 , V_37 -> V_45 ,
( int ) V_37 -> V_48 ) ;
return V_43 ;
}
V_37 -> V_50 += V_42 ;
if ( V_2 -> V_9 . V_13 == V_16 ) {
T_1 V_51 = V_37 -> V_48 & ~ V_52 ;
char * V_53 ;
V_53 = F_19 ( V_2 -> V_54 [ V_37 -> V_48 >> V_55 ] ) ;
* ( T_1 * ) ( V_53 + V_51 ) = V_37 -> V_50 ;
F_20 ( V_53 ) ;
} else {
struct V_56 * V_57 = V_39 -> V_58 ;
T_1 T_2 * V_59 ;
void T_2 * V_60 ;
if ( V_2 -> V_61 && F_21 () )
return - V_62 ;
V_43 = F_22 ( V_2 , 1 ) ;
if ( V_43 )
return V_43 ;
V_37 -> V_48 += V_2 -> V_47 ;
V_60 = F_23 ( V_57 -> V_63 . V_64 ,
V_37 -> V_48 & V_52 ) ;
V_59 = ( T_1 T_2 * )
( V_60 + ( V_37 -> V_48 & ~ V_52 ) ) ;
F_24 ( V_37 -> V_50 , V_59 ) ;
F_25 ( V_60 ) ;
}
V_37 -> V_49 = V_42 ;
return 0 ;
}
static int
F_26 ( struct V_1 * V_2 ,
struct V_21 * V_23 )
{
struct V_36 T_3 * V_65 ;
struct V_66 * V_67 = V_2 -> V_68 ;
int V_69 , V_43 ;
V_65 = ( void T_3 * ) ( V_70 ) V_67 -> V_71 ;
for ( V_69 = 0 ; V_69 < V_67 -> V_72 ; V_69 ++ ) {
struct V_36 V_37 ;
if ( F_27 ( & V_37 ,
V_65 + V_69 ,
sizeof( V_37 ) ) )
return - V_62 ;
V_43 = F_15 ( V_2 , V_23 , & V_37 ) ;
if ( V_43 )
return V_43 ;
if ( F_28 ( & V_65 [ V_69 ] . V_49 ,
& V_37 . V_49 ,
sizeof( V_37 . V_49 ) ) )
return - V_62 ;
}
return 0 ;
}
static int
F_29 ( struct V_1 * V_2 ,
struct V_21 * V_23 ,
struct V_36 * V_73 )
{
const struct V_66 * V_67 = V_2 -> V_68 ;
int V_69 , V_43 ;
for ( V_69 = 0 ; V_69 < V_67 -> V_72 ; V_69 ++ ) {
V_43 = F_15 ( V_2 , V_23 , & V_73 [ V_69 ] ) ;
if ( V_43 )
return V_43 ;
}
return 0 ;
}
static int
F_30 ( struct V_38 * V_39 ,
struct V_21 * V_23 ,
struct V_74 * V_75 )
{
struct V_1 * V_2 ;
int V_43 = 0 ;
F_31 () ;
F_32 (obj, objects, exec_list) {
V_43 = F_26 ( V_2 , V_23 ) ;
if ( V_43 )
break;
}
F_33 () ;
return V_43 ;
}
static int
F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_66 * V_67 = V_2 -> V_68 ;
bool V_76 = F_35 ( V_4 -> V_39 ) -> V_77 < 4 ;
bool V_78 , V_79 ;
int V_43 ;
V_78 =
V_76 &&
V_67 -> V_80 & V_81 &&
V_2 -> V_82 != V_83 ;
V_79 =
V_67 -> V_72 ? true : V_78 ;
V_43 = F_36 ( V_2 , V_67 -> V_84 , V_79 ) ;
if ( V_43 )
return V_43 ;
if ( V_76 ) {
if ( V_67 -> V_80 & V_81 ) {
if ( V_2 -> V_82 ) {
V_43 = F_37 ( V_2 , V_4 ) ;
if ( V_43 )
goto V_85;
V_67 -> V_80 |= V_86 ;
F_38 ( V_2 ) ;
} else {
V_43 = F_39 ( V_2 ) ;
if ( V_43 )
goto V_85;
}
V_2 -> V_15 = true ;
}
}
V_67 -> V_48 = V_2 -> V_47 ;
return 0 ;
V_85:
F_40 ( V_2 ) ;
return V_43 ;
}
static int
F_41 ( struct V_3 * V_4 ,
struct V_87 * V_88 ,
struct V_74 * V_75 )
{
T_4 * V_57 = V_4 -> V_39 -> V_58 ;
struct V_1 * V_2 ;
int V_43 , V_89 ;
bool V_76 = F_35 ( V_4 -> V_39 ) -> V_77 < 4 ;
struct V_74 V_90 ;
F_42 ( & V_90 ) ;
while ( ! F_43 ( V_75 ) ) {
struct V_66 * V_67 ;
bool V_78 , V_79 ;
V_2 = F_44 ( V_75 ,
struct V_1 ,
V_91 ) ;
V_67 = V_2 -> V_68 ;
V_78 =
V_76 &&
V_67 -> V_80 & V_81 &&
V_2 -> V_82 != V_83 ;
V_79 =
V_67 -> V_72 ? true : V_78 ;
if ( V_79 )
F_45 ( & V_2 -> V_91 , & V_90 ) ;
else
F_46 ( & V_2 -> V_91 , & V_90 ) ;
V_2 -> V_9 . V_11 = 0 ;
V_2 -> V_9 . V_10 = 0 ;
}
F_47 ( & V_90 , V_75 ) ;
V_89 = 0 ;
do {
V_43 = 0 ;
F_32 (obj, objects, exec_list) {
struct V_66 * V_67 = V_2 -> V_68 ;
bool V_78 , V_79 ;
if ( ! V_2 -> V_92 )
continue;
V_78 =
V_76 &&
V_67 -> V_80 & V_81 &&
V_2 -> V_82 != V_83 ;
V_79 =
V_67 -> V_72 ? true : V_78 ;
if ( ( V_67 -> V_84 && V_2 -> V_47 & ( V_67 -> V_84 - 1 ) ) ||
( V_79 && ! V_2 -> V_93 ) )
V_43 = F_48 ( V_2 ) ;
else
V_43 = F_34 ( V_2 , V_4 ) ;
if ( V_43 )
goto V_94;
}
F_32 (obj, objects, exec_list) {
if ( V_2 -> V_92 )
continue;
V_43 = F_34 ( V_2 , V_4 ) ;
if ( V_43 ) {
int V_95 ;
V_95 = F_48 ( V_2 ) ;
( void ) V_95 ;
F_49 ( V_2 -> V_92 ) ;
break;
}
}
F_32 (obj, objects, exec_list) {
struct V_66 * V_67 ;
if ( ! V_2 -> V_92 )
continue;
V_67 = V_2 -> V_68 ;
if ( V_67 -> V_80 & V_86 ) {
F_50 ( V_2 ) ;
V_67 -> V_80 &= ~ V_86 ;
}
F_40 ( V_2 ) ;
if ( V_57 -> V_63 . V_96 && ! V_2 -> V_97 ) {
F_51 ( V_57 -> V_63 . V_96 ,
V_2 , V_2 -> V_98 ) ;
V_2 -> V_97 = 1 ;
}
}
if ( V_43 != - V_99 || V_89 > 1 )
return V_43 ;
V_43 = F_52 ( V_4 -> V_39 , V_89 == 0 ) ;
if ( V_43 )
return V_43 ;
V_89 ++ ;
} while ( 1 );
V_94:
F_53 (obj, objects, exec_list) {
struct V_66 * V_67 ;
if ( ! V_2 -> V_92 )
continue;
V_67 = V_2 -> V_68 ;
if ( V_67 -> V_80 & V_86 ) {
F_50 ( V_2 ) ;
V_67 -> V_80 &= ~ V_86 ;
}
F_40 ( V_2 ) ;
}
return V_43 ;
}
static int
F_54 ( struct V_38 * V_39 ,
struct V_87 * V_88 ,
struct V_3 * V_4 ,
struct V_74 * V_75 ,
struct V_21 * V_23 ,
struct V_66 * V_100 ,
int V_24 )
{
struct V_36 * V_37 ;
struct V_1 * V_2 ;
int * V_101 ;
int V_69 , V_102 , V_43 ;
while ( ! F_43 ( V_75 ) ) {
V_2 = F_44 ( V_75 ,
struct V_1 ,
V_91 ) ;
F_55 ( & V_2 -> V_91 ) ;
F_56 ( & V_2 -> V_9 ) ;
}
F_57 ( & V_39 -> V_103 ) ;
V_102 = 0 ;
for ( V_69 = 0 ; V_69 < V_24 ; V_69 ++ )
V_102 += V_100 [ V_69 ] . V_72 ;
V_101 = F_58 ( V_24 , sizeof( * V_101 ) ) ;
V_37 = F_58 ( V_102 , sizeof( * V_37 ) ) ;
if ( V_37 == NULL || V_101 == NULL ) {
F_59 ( V_37 ) ;
F_59 ( V_101 ) ;
F_60 ( & V_39 -> V_103 ) ;
return - V_104 ;
}
V_102 = 0 ;
for ( V_69 = 0 ; V_69 < V_24 ; V_69 ++ ) {
struct V_36 T_3 * V_65 ;
V_65 = ( void T_3 * ) ( V_70 ) V_100 [ V_69 ] . V_71 ;
if ( F_61 ( V_37 + V_102 , V_65 ,
V_100 [ V_69 ] . V_72 * sizeof( * V_37 ) ) ) {
V_43 = - V_62 ;
F_60 ( & V_39 -> V_103 ) ;
goto V_94;
}
V_101 [ V_69 ] = V_102 ;
V_102 += V_100 [ V_69 ] . V_72 ;
}
V_43 = F_62 ( V_39 ) ;
if ( V_43 ) {
F_60 ( & V_39 -> V_103 ) ;
goto V_94;
}
F_7 ( V_23 ) ;
for ( V_69 = 0 ; V_69 < V_24 ; V_69 ++ ) {
V_2 = F_17 ( F_63 ( V_39 , V_88 ,
V_100 [ V_69 ] . V_32 ) ) ;
if ( & V_2 -> V_9 == NULL ) {
F_18 ( L_12 ,
V_100 [ V_69 ] . V_32 , V_69 ) ;
V_43 = - V_46 ;
goto V_94;
}
F_64 ( & V_2 -> V_91 , V_75 ) ;
V_2 -> V_31 = V_100 [ V_69 ] . V_32 ;
V_2 -> V_68 = & V_100 [ V_69 ] ;
F_8 ( V_23 , V_2 ) ;
}
V_43 = F_41 ( V_4 , V_88 , V_75 ) ;
if ( V_43 )
goto V_94;
F_32 (obj, objects, exec_list) {
int V_48 = V_2 -> V_68 - V_100 ;
V_43 = F_29 ( V_2 , V_23 ,
V_37 + V_101 [ V_48 ] ) ;
if ( V_43 )
goto V_94;
}
V_94:
F_59 ( V_37 ) ;
F_59 ( V_101 ) ;
return V_43 ;
}
static int
F_65 ( struct V_38 * V_39 ,
T_1 V_7 ,
T_1 V_8 ,
T_1 V_20 )
{
T_4 * V_57 = V_39 -> V_58 ;
int V_69 , V_43 ;
if ( V_8 & V_16 )
F_66 () ;
if ( V_8 & V_105 )
F_67 () ;
if ( ( V_8 | V_7 ) & V_19 ) {
for ( V_69 = 0 ; V_69 < V_106 ; V_69 ++ )
if ( V_20 & ( 1 << V_69 ) ) {
V_43 = F_68 ( & V_57 -> V_4 [ V_69 ] ,
V_7 ,
V_8 ) ;
if ( V_43 )
return V_43 ;
}
}
return 0 ;
}
static bool
F_69 ( struct V_38 * V_39 )
{
if ( F_35 ( V_39 ) -> V_77 < 6 )
return 0 ;
if ( V_107 >= 0 )
return V_107 ;
if ( F_35 ( V_39 ) -> V_77 == 6 )
return 0 ;
return 1 ;
}
static int
F_70 ( struct V_1 * V_2 ,
struct V_3 * V_108 )
{
struct V_3 * V_109 = V_2 -> V_4 ;
T_5 V_110 ;
int V_43 , V_111 ;
if ( V_109 == NULL || V_108 == V_109 )
return 0 ;
if ( ! F_69 ( V_2 -> V_9 . V_39 ) )
return F_71 ( V_2 ) ;
V_111 = F_72 ( V_109 , V_108 ) ;
V_110 = V_2 -> V_112 ;
if ( V_110 <= V_109 -> V_113 [ V_111 ] )
return 0 ;
if ( V_110 == V_109 -> V_114 ) {
struct V_115 * V_116 ;
V_116 = F_6 ( sizeof( * V_116 ) , V_27 ) ;
if ( V_116 == NULL )
return - V_104 ;
V_43 = F_73 ( V_109 , NULL , V_116 ) ;
if ( V_43 ) {
F_14 ( V_116 ) ;
return V_43 ;
}
V_110 = V_116 -> V_110 ;
}
V_109 -> V_113 [ V_111 ] = V_110 ;
return V_108 -> V_117 ( V_108 , V_109 , V_110 - 1 ) ;
}
static int
F_74 ( struct V_3 * V_4 , T_5 V_17 )
{
T_5 V_118 , V_119 ;
int V_43 ;
for ( V_118 = 0 ; V_17 >> V_118 ; V_118 ++ ) {
if ( ( ( V_17 >> V_118 ) & 1 ) == 0 )
continue;
if ( V_118 )
V_119 = V_120 ;
else
V_119 = V_121 ;
V_43 = F_75 ( V_4 , 2 ) ;
if ( V_43 )
return V_43 ;
F_76 ( V_4 , V_122 | V_119 ) ;
F_76 ( V_4 , V_123 ) ;
F_77 ( V_4 ) ;
}
return 0 ;
}
static int
F_78 ( struct V_3 * V_4 ,
struct V_74 * V_75 )
{
struct V_1 * V_2 ;
struct V_5 V_6 ;
int V_43 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
F_32 (obj, objects, exec_list)
F_1 ( V_2 , V_4 , & V_6 ) ;
if ( V_6 . V_7 | V_6 . V_8 ) {
V_43 = F_65 ( V_4 -> V_39 ,
V_6 . V_7 ,
V_6 . V_8 ,
V_6 . V_20 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_6 . V_17 ) {
V_43 = F_74 ( V_4 , V_6 . V_17 ) ;
if ( V_43 )
return V_43 ;
}
F_32 (obj, objects, exec_list) {
V_43 = F_70 ( V_2 , V_4 ) ;
if ( V_43 )
return V_43 ;
}
return 0 ;
}
static bool
F_79 ( struct V_124 * V_100 )
{
return ( ( V_100 -> V_125 | V_100 -> V_126 ) & 0x7 ) == 0 ;
}
static int
F_80 ( struct V_66 * V_100 ,
int V_24 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_24 ; V_69 ++ ) {
char T_3 * V_127 = ( char T_3 * ) ( V_70 ) V_100 [ V_69 ] . V_71 ;
int V_128 ;
if ( V_100 [ V_69 ] . V_72 >
V_129 / sizeof( struct V_36 ) )
return - V_44 ;
V_128 = V_100 [ V_69 ] . V_72 *
sizeof( struct V_36 ) ;
if ( ! F_81 ( V_130 , V_127 , V_128 ) )
return - V_62 ;
if ( ! F_81 ( V_131 , V_127 , V_128 ) )
return - V_62 ;
if ( F_82 ( V_127 , V_128 ) )
return - V_62 ;
}
return 0 ;
}
static void
F_83 ( struct V_74 * V_75 ,
struct V_3 * V_4 ,
T_5 V_110 )
{
struct V_1 * V_2 ;
F_32 (obj, objects, exec_list) {
T_5 V_132 = V_2 -> V_9 . V_12 ;
T_5 V_133 = V_2 -> V_9 . V_13 ;
V_2 -> V_9 . V_12 = V_2 -> V_9 . V_11 ;
V_2 -> V_9 . V_13 = V_2 -> V_9 . V_10 ;
V_2 -> V_14 = V_2 -> V_15 ;
F_84 ( V_2 , V_4 , V_110 ) ;
if ( V_2 -> V_9 . V_13 ) {
V_2 -> V_134 = 1 ;
V_2 -> V_135 = true ;
F_46 ( & V_2 -> V_136 ,
& V_4 -> V_136 ) ;
F_85 ( V_4 -> V_39 , V_2 ) ;
}
F_86 ( V_2 , V_132 , V_133 ) ;
}
}
static void
F_87 ( struct V_38 * V_39 ,
struct V_87 * V_88 ,
struct V_3 * V_4 )
{
struct V_115 * V_116 ;
T_5 V_137 ;
V_137 = V_138 ;
if ( F_35 ( V_39 ) -> V_77 >= 4 )
V_137 |= V_139 ;
if ( V_4 -> V_140 ( V_4 , V_137 , 0 ) ) {
F_88 ( V_4 ) ;
return;
}
V_116 = F_6 ( sizeof( * V_116 ) , V_27 ) ;
if ( V_116 == NULL || F_73 ( V_4 , V_88 , V_116 ) ) {
F_88 ( V_4 ) ;
F_14 ( V_116 ) ;
}
}
static int
F_89 ( struct V_38 * V_39 ,
struct V_3 * V_4 )
{
T_4 * V_57 = V_39 -> V_58 ;
int V_43 , V_69 ;
if ( ! F_90 ( V_39 ) || V_4 != & V_57 -> V_4 [ V_141 ] )
return 0 ;
V_43 = F_75 ( V_4 , 4 * 3 ) ;
if ( V_43 )
return V_43 ;
for ( V_69 = 0 ; V_69 < 4 ; V_69 ++ ) {
F_76 ( V_4 , F_91 ( 1 ) ) ;
F_76 ( V_4 , F_92 ( V_69 ) ) ;
F_76 ( V_4 , 0 ) ;
}
F_77 ( V_4 ) ;
return 0 ;
}
static int
F_93 ( struct V_38 * V_39 , void * V_142 ,
struct V_87 * V_88 ,
struct V_124 * args ,
struct V_66 * V_100 )
{
T_4 * V_57 = V_39 -> V_58 ;
struct V_74 V_75 ;
struct V_21 * V_23 ;
struct V_1 * V_143 ;
struct V_144 * V_145 = NULL ;
struct V_3 * V_4 ;
T_5 V_146 , V_147 ;
T_5 V_110 ;
T_5 V_148 ;
int V_43 , V_149 , V_69 ;
if ( ! F_79 ( args ) ) {
F_18 ( L_13 ) ;
return - V_44 ;
}
V_43 = F_80 ( V_100 , args -> V_150 ) ;
if ( V_43 )
return V_43 ;
switch ( args -> V_80 & V_151 ) {
case V_152 :
case V_153 :
V_4 = & V_57 -> V_4 [ V_141 ] ;
break;
case V_154 :
if ( ! F_94 ( V_39 ) ) {
F_18 ( L_14 ) ;
return - V_44 ;
}
V_4 = & V_57 -> V_4 [ V_155 ] ;
break;
case V_156 :
if ( ! F_95 ( V_39 ) ) {
F_18 ( L_15 ) ;
return - V_44 ;
}
V_4 = & V_57 -> V_4 [ V_157 ] ;
break;
default:
F_18 ( L_16 ,
( int ) ( args -> V_80 & V_151 ) ) ;
return - V_44 ;
}
V_149 = args -> V_80 & V_158 ;
V_148 = V_158 ;
switch ( V_149 ) {
case V_159 :
case V_160 :
case V_161 :
if ( V_4 == & V_57 -> V_4 [ V_141 ] &&
V_149 != V_57 -> V_162 ) {
if ( F_35 ( V_39 ) -> V_77 < 4 )
return - V_44 ;
if ( F_35 ( V_39 ) -> V_77 > 5 &&
V_149 == V_161 )
return - V_44 ;
if ( F_35 ( V_39 ) -> V_77 >= 6 )
V_148 &= ~ V_161 ;
}
break;
default:
F_18 ( L_17 , V_149 ) ;
return - V_44 ;
}
if ( args -> V_150 < 1 ) {
F_18 ( L_18 , args -> V_150 ) ;
return - V_44 ;
}
if ( args -> V_163 != 0 ) {
if ( V_4 != & V_57 -> V_4 [ V_141 ] ) {
F_18 ( L_19 ) ;
return - V_44 ;
}
if ( args -> V_163 > V_164 / sizeof( * V_145 ) ) {
F_18 ( L_20 ,
args -> V_163 ) ;
return - V_44 ;
}
V_145 = F_96 ( args -> V_163 * sizeof( * V_145 ) ,
V_27 ) ;
if ( V_145 == NULL ) {
V_43 = - V_104 ;
goto V_165;
}
if ( F_61 ( V_145 ,
(struct V_144 T_3 * ) ( V_70 )
args -> V_166 ,
sizeof( * V_145 ) * args -> V_163 ) ) {
V_43 = - V_62 ;
goto V_165;
}
}
V_43 = F_62 ( V_39 ) ;
if ( V_43 )
goto V_165;
if ( V_57 -> V_63 . V_167 ) {
F_57 ( & V_39 -> V_103 ) ;
V_43 = - V_168 ;
goto V_165;
}
V_23 = F_5 ( args -> V_150 ) ;
if ( V_23 == NULL ) {
F_57 ( & V_39 -> V_103 ) ;
V_43 = - V_104 ;
goto V_165;
}
F_42 ( & V_75 ) ;
for ( V_69 = 0 ; V_69 < args -> V_150 ; V_69 ++ ) {
struct V_1 * V_2 ;
V_2 = F_17 ( F_63 ( V_39 , V_88 ,
V_100 [ V_69 ] . V_32 ) ) ;
if ( & V_2 -> V_9 == NULL ) {
F_18 ( L_12 ,
V_100 [ V_69 ] . V_32 , V_69 ) ;
V_43 = - V_46 ;
goto V_94;
}
if ( ! F_43 ( & V_2 -> V_91 ) ) {
F_18 ( L_21 ,
V_2 , V_100 [ V_69 ] . V_32 , V_69 ) ;
V_43 = - V_44 ;
goto V_94;
}
F_64 ( & V_2 -> V_91 , & V_75 ) ;
V_2 -> V_31 = V_100 [ V_69 ] . V_32 ;
V_2 -> V_68 = & V_100 [ V_69 ] ;
F_8 ( V_23 , V_2 ) ;
}
V_143 = F_97 ( V_75 . V_169 ,
struct V_1 ,
V_91 ) ;
V_43 = F_41 ( V_4 , V_88 , & V_75 ) ;
if ( V_43 )
goto V_94;
V_43 = F_30 ( V_39 , V_23 , & V_75 ) ;
if ( V_43 ) {
if ( V_43 == - V_62 ) {
V_43 = F_54 ( V_39 , V_88 , V_4 ,
& V_75 , V_23 ,
V_100 ,
args -> V_150 ) ;
F_98 ( ! F_99 ( & V_39 -> V_103 ) ) ;
}
if ( V_43 )
goto V_94;
}
if ( V_143 -> V_9 . V_10 ) {
F_18 ( L_22 ) ;
V_43 = - V_44 ;
goto V_94;
}
V_143 -> V_9 . V_11 |= V_138 ;
V_43 = F_78 ( V_4 , & V_75 ) ;
if ( V_43 )
goto V_94;
V_110 = F_88 ( V_4 ) ;
for ( V_69 = 0 ; V_69 < F_100 ( V_4 -> V_113 ) ; V_69 ++ ) {
if ( V_110 < V_4 -> V_113 [ V_69 ] ) {
V_43 = F_101 ( V_39 , true ) ;
if ( V_43 )
goto V_94;
F_98 ( V_4 -> V_113 [ V_69 ] ) ;
}
}
if ( V_4 == & V_57 -> V_4 [ V_141 ] &&
V_149 != V_57 -> V_162 ) {
V_43 = F_75 ( V_4 , 4 ) ;
if ( V_43 )
goto V_94;
F_76 ( V_4 , V_123 ) ;
F_76 ( V_4 , F_91 ( 1 ) ) ;
F_76 ( V_4 , V_170 ) ;
F_76 ( V_4 , V_148 << 16 | V_149 ) ;
F_77 ( V_4 ) ;
V_57 -> V_162 = V_149 ;
}
if ( args -> V_80 & V_171 ) {
V_43 = F_89 ( V_39 , V_4 ) ;
if ( V_43 )
goto V_94;
}
F_102 ( V_4 , V_110 ) ;
V_146 = V_143 -> V_47 + args -> V_125 ;
V_147 = args -> V_126 ;
if ( V_145 ) {
for ( V_69 = 0 ; V_69 < args -> V_163 ; V_69 ++ ) {
V_43 = F_103 ( V_39 , & V_145 [ V_69 ] ,
args -> V_172 , args -> V_173 ) ;
if ( V_43 )
goto V_94;
V_43 = V_4 -> V_174 ( V_4 ,
V_146 , V_147 ) ;
if ( V_43 )
goto V_94;
}
} else {
V_43 = V_4 -> V_174 ( V_4 , V_146 , V_147 ) ;
if ( V_43 )
goto V_94;
}
F_83 ( & V_75 , V_4 , V_110 ) ;
F_87 ( V_39 , V_88 , V_4 ) ;
V_94:
F_13 ( V_23 ) ;
while ( ! F_43 ( & V_75 ) ) {
struct V_1 * V_2 ;
V_2 = F_44 ( & V_75 ,
struct V_1 ,
V_91 ) ;
F_55 ( & V_2 -> V_91 ) ;
F_56 ( & V_2 -> V_9 ) ;
}
F_57 ( & V_39 -> V_103 ) ;
V_165:
F_14 ( V_145 ) ;
return V_43 ;
}
int
F_104 ( struct V_38 * V_39 , void * V_142 ,
struct V_87 * V_88 )
{
struct V_175 * args = V_142 ;
struct V_124 V_176 ;
struct V_177 * V_91 = NULL ;
struct V_66 * V_178 = NULL ;
int V_43 , V_69 ;
if ( args -> V_150 < 1 ) {
F_18 ( L_18 , args -> V_150 ) ;
return - V_44 ;
}
V_91 = F_58 ( sizeof( * V_91 ) , args -> V_150 ) ;
V_178 = F_58 ( sizeof( * V_178 ) , args -> V_150 ) ;
if ( V_91 == NULL || V_178 == NULL ) {
F_18 ( L_23 ,
args -> V_150 ) ;
F_59 ( V_91 ) ;
F_59 ( V_178 ) ;
return - V_104 ;
}
V_43 = F_61 ( V_91 ,
(struct V_179 T_3 * )
( V_70 ) args -> V_180 ,
sizeof( * V_91 ) * args -> V_150 ) ;
if ( V_43 != 0 ) {
F_18 ( L_24 ,
args -> V_150 , V_43 ) ;
F_59 ( V_91 ) ;
F_59 ( V_178 ) ;
return - V_62 ;
}
for ( V_69 = 0 ; V_69 < args -> V_150 ; V_69 ++ ) {
V_178 [ V_69 ] . V_32 = V_91 [ V_69 ] . V_32 ;
V_178 [ V_69 ] . V_72 = V_91 [ V_69 ] . V_72 ;
V_178 [ V_69 ] . V_71 = V_91 [ V_69 ] . V_71 ;
V_178 [ V_69 ] . V_84 = V_91 [ V_69 ] . V_84 ;
V_178 [ V_69 ] . V_48 = V_91 [ V_69 ] . V_48 ;
if ( F_35 ( V_39 ) -> V_77 < 4 )
V_178 [ V_69 ] . V_80 = V_81 ;
else
V_178 [ V_69 ] . V_80 = 0 ;
}
V_176 . V_180 = args -> V_180 ;
V_176 . V_150 = args -> V_150 ;
V_176 . V_125 = args -> V_125 ;
V_176 . V_126 = args -> V_126 ;
V_176 . V_172 = args -> V_172 ;
V_176 . V_173 = args -> V_173 ;
V_176 . V_163 = args -> V_163 ;
V_176 . V_166 = args -> V_166 ;
V_176 . V_80 = V_153 ;
V_43 = F_93 ( V_39 , V_142 , V_88 , & V_176 , V_178 ) ;
if ( ! V_43 ) {
for ( V_69 = 0 ; V_69 < args -> V_150 ; V_69 ++ )
V_91 [ V_69 ] . V_48 = V_178 [ V_69 ] . V_48 ;
V_43 = F_105 ( (struct V_179 T_3 * )
( V_70 ) args -> V_180 ,
V_91 ,
sizeof( * V_91 ) * args -> V_150 ) ;
if ( V_43 ) {
V_43 = - V_62 ;
F_18 ( L_25
L_26 ,
args -> V_150 , V_43 ) ;
}
}
F_59 ( V_91 ) ;
F_59 ( V_178 ) ;
return V_43 ;
}
int
F_106 ( struct V_38 * V_39 , void * V_142 ,
struct V_87 * V_88 )
{
struct V_124 * args = V_142 ;
struct V_66 * V_178 = NULL ;
int V_43 ;
if ( args -> V_150 < 1 ||
args -> V_150 > V_164 / sizeof( * V_178 ) ) {
F_18 ( L_27 , args -> V_150 ) ;
return - V_44 ;
}
V_178 = F_96 ( sizeof( * V_178 ) * args -> V_150 ,
V_27 | V_181 | V_182 ) ;
if ( V_178 == NULL )
V_178 = F_58 ( sizeof( * V_178 ) ,
args -> V_150 ) ;
if ( V_178 == NULL ) {
F_18 ( L_23 ,
args -> V_150 ) ;
return - V_104 ;
}
V_43 = F_61 ( V_178 ,
(struct V_179 T_3 * )
( V_70 ) args -> V_180 ,
sizeof( * V_178 ) * args -> V_150 ) ;
if ( V_43 != 0 ) {
F_18 ( L_24 ,
args -> V_150 , V_43 ) ;
F_59 ( V_178 ) ;
return - V_62 ;
}
V_43 = F_93 ( V_39 , V_142 , V_88 , args , V_178 ) ;
if ( ! V_43 ) {
V_43 = F_105 ( (struct V_179 T_3 * )
( V_70 ) args -> V_180 ,
V_178 ,
sizeof( * V_178 ) * args -> V_150 ) ;
if ( V_43 ) {
V_43 = - V_62 ;
F_18 ( L_25
L_26 ,
args -> V_150 , V_43 ) ;
}
}
F_59 ( V_178 ) ;
return V_43 ;
}
