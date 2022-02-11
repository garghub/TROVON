static bool F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( ! memcmp ( & V_2 -> V_4 , V_4 , sizeof( * V_4 ) ) )
return true ;
else
return false ;
}
static int F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 = 0 ;
F_3 ( & V_2 -> V_6 ) ;
if ( ( V_2 -> V_7 == V_8 ) && V_2 -> V_9 ) {
if ( V_4 -> V_10 . V_11 . V_12 )
V_5 |= V_13 ;
if ( V_4 -> V_10 . V_11 . V_14 )
V_5 |= V_15 ;
F_4 ( V_5 , & V_2 -> V_9 -> V_16 ) ;
F_4 ( V_17 , & V_2 -> V_9 -> V_18 ) ;
}
if ( V_2 -> V_19 )
F_4 ( V_4 -> V_10 . V_11 . V_20 , & V_2 -> V_19 -> V_21 ) ;
if ( V_2 -> V_22 ) {
V_5 = 0 ;
if ( V_4 -> V_10 . V_23 . V_24 )
V_5 |= V_25 ;
if ( V_4 -> V_10 . V_23 . V_26 )
V_5 |= V_27 ;
if ( V_4 -> V_10 . V_23 . V_28 == V_29 )
V_5 |= V_30 ;
V_5 |= ( V_4 -> V_10 . V_23 . V_31 & V_32 ) << V_33 ;
if ( V_4 -> V_10 . V_23 . V_34 )
V_5 |= V_35 ;
V_5 |= ( V_4 -> V_10 . V_23 . V_36 & V_37 )
<< V_38 ;
V_5 |= V_4 -> V_10 . V_23 . V_39 & V_40 ;
F_4 ( V_5 , & V_2 -> V_22 -> V_18 ) ;
F_4 ( 0 , & V_2 -> V_22 -> V_41 ) ;
F_4 ( 0 , & V_2 -> V_22 -> V_42 ) ;
V_5 = V_4 -> V_10 . V_23 . V_43 [ 0 ] << 16 ;
V_5 |= V_4 -> V_10 . V_23 . V_43 [ 1 ] & V_40 ;
F_4 ( V_5 , & V_2 -> V_22 -> V_44 [ 0 ] ) ;
V_5 = V_4 -> V_10 . V_23 . V_43 [ 2 ] << 16 ;
V_5 |= V_4 -> V_10 . V_23 . V_43 [ 3 ] & V_40 ;
F_4 ( V_5 , & V_2 -> V_22 -> V_44 [ 1 ] ) ;
F_4 ( 0 , & V_2 -> V_22 -> V_45 [ 0 ] ) ;
F_4 ( 0 , & V_2 -> V_22 -> V_45 [ 1 ] ) ;
F_4 ( 0 , & V_2 -> V_22 -> V_45 [ 2 ] ) ;
}
memcpy ( & V_2 -> V_4 , V_4 , sizeof( * V_4 ) ) ;
F_5 ( & V_2 -> V_6 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
unsigned long V_46 , V_47 ;
if ( ! V_2 -> V_9 )
return 0 ;
F_4 ( V_48 , & V_2 -> V_9 -> V_18 ) ;
V_46 = V_49 + F_7 ( V_50 ) ;
do {
V_47 = F_8 ( & V_2 -> V_9 -> V_18 ) ;
if ( ( V_47 & V_17 ) == 0 )
break;
} while ( F_9 ( V_46 , V_49 ) );
if ( F_8 ( & V_2 -> V_9 -> V_18 ) & V_17 ) {
F_10 ( V_51 -> V_52 , L_1 ) ;
return - V_53 ;
}
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_3 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_22 ) {
F_4 ( 0 , & V_2 -> V_22 -> V_44 [ 0 ] ) ;
F_4 ( 0 , & V_2 -> V_22 -> V_44 [ 1 ] ) ;
F_4 ( 0 , & V_2 -> V_22 -> V_45 [ 0 ] ) ;
F_4 ( 0 , & V_2 -> V_22 -> V_45 [ 1 ] ) ;
F_4 ( 0 , & V_2 -> V_22 -> V_45 [ 2 ] ) ;
}
F_6 ( V_2 ) ;
if ( V_2 -> V_22 ) {
F_4 ( 0 , & V_2 -> V_22 -> V_18 ) ;
F_4 ( 0 , & V_2 -> V_22 -> V_41 ) ;
F_4 ( 0 , & V_2 -> V_22 -> V_42 ) ;
}
memset ( & V_2 -> V_4 , 0 , sizeof( struct V_3 ) ) ;
F_5 ( & V_2 -> V_6 ) ;
F_12 ( V_51 -> V_52 , L_2 ) ;
}
static void F_13 ( struct V_54 * V_55 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < V_55 -> V_57 ; V_56 ++ ) {
F_4 ( 0 , & V_55 -> V_58 [ V_56 ] . V_16 ) ;
F_4 ( V_17 , & V_55 -> V_58 [ V_56 ] . V_18 ) ;
}
}
static void F_14 ( struct V_54 * V_55 )
{
unsigned V_5 ;
int V_56 ;
F_3 ( & V_55 -> V_6 ) ;
V_5 = V_55 -> V_59 ? V_60 : 0 ;
F_4 ( V_5 , & V_55 -> V_61 -> V_62 ) ;
V_5 = F_8 ( & V_55 -> V_61 -> V_63 ) ;
V_5 |= ( ( V_55 -> V_64 & V_65 ) << V_66 ) ;
F_4 ( V_5 , & V_55 -> V_61 -> V_63 ) ;
V_5 = ( ( V_55 -> V_67 << V_68 ) |
( V_55 -> V_69 << V_70 ) ) ;
F_4 ( V_5 , & V_55 -> V_61 -> V_71 ) ;
for ( V_56 = 0 ; V_56 < V_55 -> V_72 ; V_56 ++ )
F_4 ( V_17 , & V_55 -> V_73 [ V_56 ] . V_18 ) ;
for ( V_56 = 0 ; V_56 < V_55 -> V_74 ; V_56 ++ )
F_4 ( V_55 -> V_75 [ V_56 ] ,
& V_55 -> V_61 -> V_75 [ V_56 ] ) ;
F_5 ( & V_55 -> V_6 ) ;
}
static void F_15 ( struct V_54 * V_55 )
{
int V_56 ;
unsigned V_5 ;
F_3 ( & V_55 -> V_6 ) ;
V_5 = ~ V_17 & V_76 ;
for ( V_56 = 0 ; V_56 < V_55 -> V_72 ; V_56 ++ )
F_4 ( V_5 , & V_55 -> V_73 [ V_56 ] . V_18 ) ;
for ( V_56 = 0 ; V_56 < V_55 -> V_57 ; V_56 ++ )
F_4 ( V_5 , & V_55 -> V_58 [ V_56 ] . V_18 ) ;
F_5 ( & V_55 -> V_6 ) ;
}
static void F_16 ( struct V_77 * V_78 ,
struct V_1 * V_2 )
{
int V_56 ;
F_17 ( V_78 , L_3 ,
( ( V_2 -> V_7 == V_8 ) ? L_4 : L_5 ) ,
F_18 ( V_2 ) ) ;
if ( V_2 -> V_7 == V_8 ) {
F_17 ( V_78 , L_6 ,
V_2 -> V_4 . V_10 . V_11 . V_14 ,
V_2 -> V_4 . V_10 . V_11 . V_12 ,
V_2 -> V_4 . V_10 . V_11 . V_20 ) ;
} else {
F_17 ( V_78 , L_7 ,
V_2 -> V_4 . V_10 . V_23 . V_24 ,
V_2 -> V_4 . V_10 . V_23 . V_26 ,
V_2 -> V_4 . V_10 . V_23 . V_31 ) ;
F_17 ( V_78 , L_8 ,
V_2 -> V_4 . V_10 . V_23 . V_39 ,
V_2 -> V_4 . V_10 . V_23 . V_45 ) ;
for ( V_56 = 0 ; V_56 < V_79 ; V_56 ++ )
F_17 ( V_78 , L_9 , V_2 -> V_4 . V_10 . V_23 . V_43 [ V_56 ] ) ;
F_17 ( V_78 , L_10 ) ;
}
}
static void F_19 ( struct V_77 * V_78 ,
struct V_54 * V_55 )
{
struct V_1 * V_2 ;
F_20 (chan, &dma->chan_list, list) {
if ( F_21 ( & V_2 -> V_80 ) )
F_16 ( V_78 , V_2 ) ;
}
}
static int F_22 ( struct V_77 * V_78 , void * V_5 )
{
struct V_54 * V_55 ;
F_20 (dma, &kdev->list, list) {
if ( F_21 ( & V_55 -> V_80 ) ) {
F_17 ( V_78 , L_11 ,
V_55 -> V_81 , V_55 -> V_57 , V_55 -> V_82 ) ;
F_19 ( V_78 , V_55 ) ;
}
}
return 0 ;
}
static int F_23 ( struct V_83 * V_83 , struct V_84 * V_84 )
{
return F_24 ( V_84 , F_22 , NULL ) ;
}
static int F_25 ( struct V_85 * V_86 , const char * V_81 ,
const char * * V_87 )
{
struct V_88 args ;
struct V_85 * V_89 ;
int V_90 ;
V_89 = F_26 ( V_86 , L_12 , 0 ) ;
if ( ! V_89 )
return - V_91 ;
* V_87 = V_89 -> V_81 ;
V_90 = F_27 ( V_86 , L_13 , V_81 ) ;
if ( V_90 < 0 ) {
F_10 ( V_51 -> V_52 , L_14 ) ;
return - V_91 ;
}
if ( F_28 ( V_86 , L_12 ,
1 , V_90 , & args ) ) {
F_10 ( V_51 -> V_52 , L_15 , V_81 ) ;
return - V_91 ;
}
if ( args . args [ 0 ] < 0 ) {
F_10 ( V_51 -> V_52 , L_16 , V_81 ) ;
return - V_91 ;
}
return args . args [ 0 ] ;
}
void * F_29 ( struct V_92 * V_52 , const char * V_81 ,
struct V_3 * V_93 )
{
struct V_1 * V_2 ;
struct V_54 * V_55 ;
bool V_94 = false ;
int V_95 = - 1 ;
const char * V_96 ;
if ( ! V_51 ) {
F_30 ( L_17 ) ;
return ( void * ) - V_97 ;
}
V_95 = F_25 ( V_52 -> V_98 , V_81 , & V_96 ) ;
if ( V_95 < 0 ) {
F_10 ( V_51 -> V_52 , L_18 , V_81 ) ;
return ( void * ) - V_97 ;
}
F_12 ( V_51 -> V_52 , L_19 ,
V_93 -> V_7 == V_8 ? L_20 :
V_93 -> V_7 == V_99 ? L_21 :
L_22 , V_95 , V_96 ) ;
if ( V_93 -> V_7 != V_8 &&
V_93 -> V_7 != V_99 ) {
F_10 ( V_51 -> V_52 , L_23 ) ;
return ( void * ) - V_97 ;
}
F_20 (dma, &kdev->list, list) {
if ( ! strcmp ( V_55 -> V_81 , V_96 ) ) {
V_94 = true ;
break;
}
}
if ( ! V_94 ) {
F_10 ( V_51 -> V_52 , L_18 , V_96 ) ;
return ( void * ) - V_97 ;
}
V_94 = false ;
F_20 (chan, &dma->chan_list, list) {
if ( V_93 -> V_7 == V_8 ) {
if ( V_2 -> V_100 == V_95 ) {
V_94 = true ;
break;
}
} else {
if ( V_2 -> V_101 == V_95 ) {
V_94 = true ;
break;
}
}
}
if ( ! V_94 ) {
F_10 ( V_51 -> V_52 , L_24 ,
V_95 , V_96 ) ;
return ( void * ) - V_97 ;
}
if ( F_21 ( & V_2 -> V_80 ) >= 1 ) {
if ( ! F_1 ( V_2 , V_93 ) ) {
F_10 ( V_51 -> V_52 , L_25 ,
V_95 ) ;
return ( void * ) - V_97 ;
}
}
if ( F_31 ( & V_2 -> V_55 -> V_80 ) <= 1 )
F_14 ( V_2 -> V_55 ) ;
if ( F_31 ( & V_2 -> V_80 ) <= 1 )
F_2 ( V_2 , V_93 ) ;
F_12 ( V_51 -> V_52 , L_26 ,
V_95 , V_96 ) ;
return V_2 ;
}
void F_32 ( void * V_100 )
{
struct V_1 * V_2 = V_100 ;
if ( ! V_51 ) {
F_30 ( L_17 ) ;
return;
}
if ( F_33 ( & V_2 -> V_80 ) <= 0 )
F_11 ( V_2 ) ;
if ( F_33 ( & V_2 -> V_55 -> V_80 ) <= 0 )
F_15 ( V_2 -> V_55 ) ;
F_12 ( V_51 -> V_52 , L_27 ,
V_2 -> V_100 , V_2 -> V_101 , V_2 -> V_55 -> V_81 ) ;
}
static void T_2 * F_34 ( struct V_54 * V_55 ,
struct V_85 * V_102 ,
unsigned V_90 , T_3 * V_103 )
{
struct V_92 * V_52 = V_51 -> V_52 ;
struct V_104 V_105 ;
void T_2 * V_106 ;
int V_107 ;
V_107 = F_35 ( V_102 , V_90 , & V_105 ) ;
if ( V_107 ) {
F_10 ( V_52 , L_28 ,
V_102 -> V_81 , V_90 ) ;
return F_36 ( V_107 ) ;
}
V_106 = F_37 ( V_51 -> V_52 , & V_105 ) ;
if ( F_38 ( V_106 ) )
F_10 ( V_52 , L_29 ,
V_90 , V_102 -> V_81 ) ;
if ( V_103 )
* V_103 = F_39 ( & V_105 ) ;
return V_106 ;
}
static int F_40 ( struct V_1 * V_2 , T_1 V_101 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
V_2 -> V_101 = V_101 ;
V_2 -> V_22 = V_55 -> V_22 + V_101 ;
V_2 -> V_100 = V_108 ;
F_12 ( V_51 -> V_52 , L_30 , V_2 -> V_101 , V_2 -> V_22 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , T_1 V_100 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
V_2 -> V_100 = V_100 ;
V_2 -> V_9 = V_55 -> V_58 + V_100 ;
V_2 -> V_19 = V_55 -> V_19 + V_100 ;
V_2 -> V_101 = V_108 ;
F_12 ( V_51 -> V_52 , L_31 , V_2 -> V_100 , V_2 -> V_9 ) ;
return 0 ;
}
static int F_42 ( struct V_54 * V_55 ,
enum V_109 V_110 ,
unsigned V_95 )
{
struct V_92 * V_52 = V_51 -> V_52 ;
struct V_1 * V_2 ;
int V_107 = - V_97 ;
V_2 = F_43 ( V_52 , sizeof( * V_2 ) , V_111 ) ;
if ( ! V_2 )
return - V_112 ;
F_44 ( & V_2 -> V_113 ) ;
V_2 -> V_55 = V_55 ;
V_2 -> V_7 = V_114 ;
F_45 ( & V_2 -> V_80 , 0 ) ;
F_46 ( & V_2 -> V_6 ) ;
if ( V_110 == V_8 ) {
V_2 -> V_7 = V_110 ;
V_107 = F_41 ( V_2 , V_95 ) ;
} else if ( V_110 == V_99 ) {
V_2 -> V_7 = V_110 ;
V_107 = F_40 ( V_2 , V_95 ) ;
} else {
F_10 ( V_52 , L_32 , V_95 ) ;
}
F_47 ( & V_2 -> V_113 , & V_55 -> V_115 ) ;
return V_107 ;
}
static int F_48 ( struct V_85 * V_116 , struct V_85 * V_89 )
{
unsigned V_57 , V_72 , V_82 , V_117 ;
struct V_85 * V_102 = V_89 ;
struct V_54 * V_55 ;
int V_107 , V_118 , V_119 = 0 ;
T_3 V_120 ;
T_1 V_121 ;
T_1 V_56 ;
V_55 = F_43 ( V_51 -> V_52 , sizeof( * V_55 ) , V_111 ) ;
if ( ! V_55 ) {
F_10 ( V_51 -> V_52 , L_33 ) ;
return - V_112 ;
}
F_44 ( & V_55 -> V_113 ) ;
F_44 ( & V_55 -> V_115 ) ;
if ( ! F_49 ( V_116 , L_34 , & V_118 ) ) {
F_10 ( V_51 -> V_52 , L_35 ) ;
return - V_91 ;
}
V_55 -> V_74 = V_118 / sizeof( T_1 ) ;
if ( V_55 -> V_74 > V_122 ) {
F_50 ( V_51 -> V_52 , L_36 ,
V_55 -> V_74 ) ;
V_55 -> V_74 = V_122 ;
}
V_107 = F_51 ( V_116 , L_34 ,
V_55 -> V_75 ,
V_55 -> V_74 ) ;
if ( V_107 ) {
F_10 ( V_51 -> V_52 , L_37 ) ;
return - V_91 ;
}
V_55 -> V_61 = F_34 ( V_55 , V_102 , 0 , & V_120 ) ;
if ( ! V_55 -> V_61 )
return - V_91 ;
if ( V_120 < sizeof( struct V_61 ) ) {
F_10 ( V_51 -> V_52 , L_38 , & V_120 ) ;
return - V_91 ;
}
V_55 -> V_58 = F_34 ( V_55 , V_102 , 1 , & V_120 ) ;
if ( ! V_55 -> V_58 )
return - V_91 ;
V_57 = V_120 / sizeof( struct V_9 ) ;
V_55 -> V_73 = F_34 ( V_55 , V_102 , 2 , & V_120 ) ;
if ( ! V_55 -> V_73 )
return - V_91 ;
V_72 = V_120 / sizeof( struct V_9 ) ;
V_55 -> V_19 = F_34 ( V_55 , V_102 , 3 , & V_120 ) ;
if ( ! V_55 -> V_19 )
return - V_91 ;
V_117 = V_120 / sizeof( struct V_19 ) ;
V_55 -> V_22 = F_34 ( V_55 , V_102 , 4 , & V_120 ) ;
if ( ! V_55 -> V_22 )
return - V_91 ;
V_82 = V_120 / sizeof( struct V_22 ) ;
V_55 -> V_69 = V_123 ;
V_55 -> V_67 = V_123 ;
V_55 -> V_124 = ( F_52 ( V_102 , L_39 , NULL ) != NULL ) ;
V_55 -> V_59 = ( F_52 ( V_102 , L_40 , NULL ) != NULL ) ;
V_107 = F_53 ( V_102 , L_41 , & V_121 ) ;
if ( V_107 < 0 ) {
F_12 ( V_51 -> V_52 , L_42 ,
V_125 ) ;
V_121 = V_125 ;
}
V_55 -> V_64 = V_121 ;
V_55 -> V_72 = V_72 ;
V_55 -> V_82 = V_82 ;
V_55 -> V_57 = F_54 ( V_57 , V_117 ) ;
F_45 ( & V_55 -> V_80 , 0 ) ;
strcpy ( V_55 -> V_81 , V_102 -> V_81 ) ;
F_46 ( & V_55 -> V_6 ) ;
for ( V_56 = 0 ; V_56 < V_55 -> V_57 ; V_56 ++ ) {
if ( F_42 ( V_55 , V_8 , V_56 ) >= 0 )
V_119 ++ ;
}
for ( V_56 = 0 ; V_56 < V_55 -> V_82 ; V_56 ++ ) {
if ( F_42 ( V_55 , V_99 , V_56 ) >= 0 )
V_119 ++ ;
}
F_47 ( & V_55 -> V_113 , & V_51 -> V_113 ) ;
if ( V_55 -> V_124 ) {
F_55 ( & V_55 -> V_80 ) ;
F_14 ( V_55 ) ;
F_13 ( V_55 ) ;
}
F_56 ( V_51 -> V_52 , L_43 ,
V_55 -> V_81 , V_119 , V_55 -> V_82 ,
V_55 -> V_57 , V_55 -> V_72 ,
V_55 -> V_59 ? L_44 : L_45 ) ;
return 0 ;
}
static int F_57 ( struct V_126 * V_127 )
{
struct V_92 * V_52 = & V_127 -> V_52 ;
struct V_85 * V_102 = V_127 -> V_52 . V_98 ;
struct V_85 * V_128 ;
int V_107 = 0 ;
if ( ! V_102 ) {
F_10 ( & V_127 -> V_52 , L_46 ) ;
return - V_97 ;
}
V_51 = F_43 ( V_52 ,
sizeof( struct V_129 ) , V_111 ) ;
if ( ! V_51 ) {
F_10 ( V_52 , L_33 ) ;
return - V_112 ;
}
V_51 -> V_52 = V_52 ;
F_44 ( & V_51 -> V_113 ) ;
F_58 ( V_51 -> V_52 ) ;
V_107 = F_59 ( V_51 -> V_52 ) ;
if ( V_107 < 0 ) {
F_10 ( V_51 -> V_52 , L_47 , V_107 ) ;
return V_107 ;
}
F_60 (node, child) {
V_107 = F_48 ( V_102 , V_128 ) ;
if ( V_107 ) {
F_10 ( & V_127 -> V_52 , L_48 , V_107 ) ;
break;
}
}
if ( F_61 ( & V_51 -> V_113 ) ) {
F_10 ( V_52 , L_49 ) ;
return - V_91 ;
}
F_62 ( L_50 , V_130 | V_131 , NULL , NULL ,
& V_132 ) ;
return V_107 ;
}
static int F_63 ( struct V_126 * V_127 )
{
struct V_54 * V_55 ;
F_20 (dma, &kdev->list, list) {
if ( F_33 ( & V_55 -> V_80 ) == 0 )
F_15 ( V_55 ) ;
}
F_64 ( & V_127 -> V_52 ) ;
F_65 ( & V_127 -> V_52 ) ;
return 0 ;
}
