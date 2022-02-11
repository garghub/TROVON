static void F_1 ( unsigned int V_1 , unsigned int V_2 )
{
V_1 %= V_3 ;
V_2 %= V_3 ;
F_2 ( & V_4 [ V_1 ] ) ;
if ( V_1 != V_2 )
F_2 ( & V_4 [ V_2 ] ) ;
}
static bool F_3 ( struct V_5 * V_5 , unsigned int V_1 ,
unsigned int V_2 , unsigned int V_6 )
{
V_1 %= V_3 ;
V_2 %= V_3 ;
if ( V_1 <= V_2 ) {
F_4 ( & V_4 [ V_1 ] ) ;
if ( V_1 != V_2 )
F_5 ( & V_4 [ V_2 ] ,
V_7 ) ;
} else {
F_4 ( & V_4 [ V_2 ] ) ;
F_5 ( & V_4 [ V_1 ] ,
V_7 ) ;
}
if ( F_6 ( & V_5 -> V_8 . V_9 , V_6 ) ) {
F_1 ( V_1 , V_2 ) ;
return true ;
}
return false ;
}
static void F_7 ( void )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_3 ; V_10 ++ )
F_5 ( & V_4 [ V_10 ] , V_10 ) ;
}
static void F_8 ( void )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_3 ; V_10 ++ )
F_2 ( & V_4 [ V_10 ] ) ;
}
static T_1 F_9 ( const struct V_11 * V_12 )
{
unsigned int V_13 ;
V_13 = ( sizeof( V_12 -> V_14 ) + sizeof( V_12 -> V_15 . V_16 ) ) / sizeof( T_1 ) ;
return F_10 ( ( T_1 * ) V_12 , V_13 , V_17 ^
( ( ( V_18 V_19 ) V_12 -> V_15 . V_20 . V_21 << 16 ) |
V_12 -> V_15 . V_22 ) ) ;
}
static T_1 F_11 ( T_1 V_23 , unsigned int V_24 )
{
return F_12 ( V_23 , V_24 ) ;
}
static T_1 F_13 ( T_1 V_23 , const struct V_5 * V_5 )
{
return F_11 ( V_23 , V_5 -> V_8 . V_25 ) ;
}
static T_2 F_14 ( const struct V_11 * V_12 ,
unsigned int V_24 )
{
return F_11 ( F_9 ( V_12 ) , V_24 ) ;
}
static inline T_2 F_15 ( const struct V_5 * V_5 ,
const struct V_11 * V_12 )
{
return F_14 ( V_12 , V_5 -> V_8 . V_25 ) ;
}
bool
F_16 ( const struct V_26 * V_27 ,
unsigned int V_28 ,
unsigned int V_29 ,
T_3 V_30 ,
T_4 V_22 ,
struct V_5 * V_5 ,
struct V_11 * V_12 ,
const struct V_31 * V_32 ,
const struct V_33 * V_34 )
{
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
V_12 -> V_14 . V_30 = V_30 ;
if ( V_32 -> V_35 ( V_27 , V_28 , V_12 ) == 0 )
return false ;
V_12 -> V_15 . V_22 = V_22 ;
V_12 -> V_15 . V_36 = V_37 ;
return V_34 -> V_35 ( V_27 , V_29 , V_5 , V_12 ) ;
}
bool F_17 ( const struct V_26 * V_27 , unsigned int V_28 ,
T_3 V_30 ,
struct V_5 * V_5 , struct V_11 * V_12 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 ;
unsigned int V_38 ;
T_4 V_22 ;
int V_39 ;
F_18 () ;
V_32 = F_19 ( V_30 ) ;
V_39 = V_32 -> V_40 ( V_27 , V_28 , & V_38 , & V_22 ) ;
if ( V_39 != V_41 ) {
F_20 () ;
return false ;
}
V_34 = F_21 ( V_30 , V_22 ) ;
V_39 = F_16 ( V_27 , V_28 , V_38 , V_30 , V_22 , V_5 , V_12 ,
V_32 , V_34 ) ;
F_20 () ;
return V_39 ;
}
bool
F_22 ( struct V_11 * V_42 ,
const struct V_11 * V_43 ,
const struct V_31 * V_32 ,
const struct V_33 * V_34 )
{
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
V_42 -> V_14 . V_30 = V_43 -> V_14 . V_30 ;
if ( V_32 -> V_44 ( V_42 , V_43 ) == 0 )
return false ;
V_42 -> V_15 . V_36 = ! V_43 -> V_15 . V_36 ;
V_42 -> V_15 . V_22 = V_43 -> V_15 . V_22 ;
return V_34 -> V_44 ( V_42 , V_43 ) ;
}
static void
F_23 ( struct V_45 * V_8 )
{
F_24 ( L_1 , V_8 ) ;
F_25 ( & V_8 -> V_46 [ V_37 ] . V_47 ) ;
F_25 ( & V_8 -> V_46 [ V_48 ] . V_47 ) ;
F_26 ( V_8 ) ;
}
static void F_27 ( struct V_45 * V_8 )
{
struct V_49 * V_50 ;
V_8 -> V_51 = F_28 () ;
V_50 = F_29 ( F_30 ( V_8 ) -> V_8 . V_52 , V_8 -> V_51 ) ;
F_4 ( & V_50 -> V_53 ) ;
F_31 ( & V_8 -> V_46 [ V_37 ] . V_47 ,
& V_50 -> V_54 ) ;
F_2 ( & V_50 -> V_53 ) ;
}
static void F_32 ( struct V_45 * V_8 )
{
struct V_49 * V_50 ;
V_8 -> V_51 = F_28 () ;
V_50 = F_29 ( F_30 ( V_8 ) -> V_8 . V_52 , V_8 -> V_51 ) ;
F_4 ( & V_50 -> V_53 ) ;
F_31 ( & V_8 -> V_46 [ V_37 ] . V_47 ,
& V_50 -> V_55 ) ;
F_2 ( & V_50 -> V_53 ) ;
}
static void F_33 ( struct V_45 * V_8 )
{
struct V_49 * V_50 ;
V_50 = F_29 ( F_30 ( V_8 ) -> V_8 . V_52 , V_8 -> V_51 ) ;
F_4 ( & V_50 -> V_53 ) ;
F_34 ( F_35 ( & V_8 -> V_46 [ V_37 ] . V_47 ) ) ;
F_25 ( & V_8 -> V_46 [ V_37 ] . V_47 ) ;
F_2 ( & V_50 -> V_53 ) ;
}
struct V_45 * F_36 ( struct V_5 * V_5 ,
const struct V_56 * V_57 ,
T_5 V_58 )
{
struct V_45 * V_59 ;
V_59 = F_37 ( sizeof( * V_59 ) , V_58 ) ;
if ( V_59 == NULL )
return NULL ;
V_59 -> V_60 = V_61 ;
F_38 ( & V_59 -> V_62 , V_5 ) ;
if ( F_39 ( V_59 , V_58 , V_57 ) < 0 )
goto V_63;
F_40 ( & V_59 -> V_64 . V_65 , 0 ) ;
return V_59 ;
V_63:
F_41 ( V_59 ) ;
return NULL ;
}
void F_42 ( struct V_45 * V_59 )
{
F_43 ( V_59 ) ;
F_44 ( V_59 ) ;
F_41 ( V_59 ) ;
}
static void
F_45 ( struct V_66 * V_67 )
{
struct V_45 * V_8 = (struct V_45 * ) V_67 ;
struct V_5 * V_5 = F_30 ( V_8 ) ;
struct V_33 * V_34 ;
F_24 ( L_2 , V_8 ) ;
F_46 ( F_47 ( & V_67 -> V_65 ) == 0 ) ;
F_46 ( ! F_48 ( & V_8 -> V_68 ) ) ;
if ( F_49 ( F_50 ( V_8 ) ) ) {
F_42 ( V_8 ) ;
return;
}
F_18 () ;
V_34 = F_21 ( F_51 ( V_8 ) , F_52 ( V_8 ) ) ;
if ( V_34 && V_34 -> V_69 )
V_34 -> V_69 ( V_8 ) ;
F_20 () ;
F_53 () ;
F_26 ( V_8 ) ;
F_33 ( V_8 ) ;
F_54 ( V_5 , V_70 ) ;
F_55 () ;
if ( V_8 -> V_71 )
F_56 ( V_8 -> V_71 ) ;
F_24 ( L_3 , V_8 ) ;
F_57 ( V_8 ) ;
}
static void F_58 ( struct V_45 * V_8 )
{
struct V_5 * V_5 = F_30 ( V_8 ) ;
unsigned int V_23 , V_72 ;
unsigned int V_6 ;
F_59 ( V_8 ) ;
F_53 () ;
do {
V_6 = F_60 ( & V_5 -> V_8 . V_9 ) ;
V_23 = F_15 ( V_5 ,
& V_8 -> V_46 [ V_37 ] . V_12 ) ;
V_72 = F_15 ( V_5 ,
& V_8 -> V_46 [ V_48 ] . V_12 ) ;
} while ( F_3 ( V_5 , V_23 , V_72 , V_6 ) );
F_23 ( V_8 ) ;
F_1 ( V_23 , V_72 ) ;
F_27 ( V_8 ) ;
F_54 ( V_5 , V_73 ) ;
F_55 () ;
}
bool F_61 ( struct V_45 * V_8 , T_1 V_74 , int V_75 )
{
struct V_76 * V_77 ;
V_77 = F_62 ( V_8 ) ;
if ( V_77 && V_77 -> V_78 == 0 )
V_77 -> V_78 = F_63 () ;
if ( F_64 ( V_8 ) )
goto V_70;
if ( F_65 ( V_79 , V_8 ,
V_74 , V_75 ) < 0 ) {
F_58 ( V_8 ) ;
F_66 ( F_30 ( V_8 ) ) ;
return false ;
}
F_67 ( F_30 ( V_8 ) ) ;
F_68 ( V_80 , & V_8 -> V_60 ) ;
V_70:
F_58 ( V_8 ) ;
F_56 ( V_8 ) ;
return true ;
}
static void F_69 ( unsigned long V_81 )
{
F_61 ( (struct V_45 * ) V_81 , 0 , 0 ) ;
}
static inline bool
F_70 ( struct V_82 * V_83 ,
const struct V_11 * V_12 ,
const struct V_56 * V_57 )
{
struct V_45 * V_8 = F_71 ( V_83 ) ;
return F_72 ( V_12 , & V_83 -> V_12 ) &&
F_73 ( V_8 , V_57 , F_74 ( V_83 ) ) &&
F_75 ( V_8 ) ;
}
static struct V_82 *
F_76 ( struct V_5 * V_5 , const struct V_56 * V_57 ,
const struct V_11 * V_12 , T_1 V_23 )
{
struct V_82 * V_83 ;
struct V_84 * V_13 ;
unsigned int V_85 = F_13 ( V_23 , V_5 ) ;
F_53 () ;
V_86:
F_77 (h, n, &net->ct.hash[bucket], hnnode) {
if ( F_70 ( V_83 , V_12 , V_57 ) ) {
F_54 ( V_5 , V_87 ) ;
F_55 () ;
return V_83 ;
}
F_54 ( V_5 , V_88 ) ;
}
if ( F_78 ( V_13 ) != V_85 ) {
F_54 ( V_5 , V_89 ) ;
goto V_86;
}
F_55 () ;
return NULL ;
}
static struct V_82 *
F_79 ( struct V_5 * V_5 , const struct V_56 * V_57 ,
const struct V_11 * V_12 , T_1 V_23 )
{
struct V_82 * V_83 ;
struct V_45 * V_8 ;
F_18 () ;
V_86:
V_83 = F_76 ( V_5 , V_57 , V_12 , V_23 ) ;
if ( V_83 ) {
V_8 = F_71 ( V_83 ) ;
if ( F_49 ( F_64 ( V_8 ) ||
! F_80 ( & V_8 -> V_64 . V_65 ) ) )
V_83 = NULL ;
else {
if ( F_49 ( ! F_70 ( V_83 , V_12 , V_57 ) ) ) {
F_56 ( V_8 ) ;
goto V_86;
}
}
}
F_20 () ;
return V_83 ;
}
struct V_82 *
F_81 ( struct V_5 * V_5 , const struct V_56 * V_57 ,
const struct V_11 * V_12 )
{
return F_79 ( V_5 , V_57 , V_12 ,
F_9 ( V_12 ) ) ;
}
static void F_82 ( struct V_45 * V_8 ,
unsigned int V_23 ,
unsigned int V_72 )
{
struct V_5 * V_5 = F_30 ( V_8 ) ;
F_83 ( & V_8 -> V_46 [ V_37 ] . V_47 ,
& V_5 -> V_8 . V_23 [ V_23 ] ) ;
F_83 ( & V_8 -> V_46 [ V_48 ] . V_47 ,
& V_5 -> V_8 . V_23 [ V_72 ] ) ;
}
int
F_84 ( struct V_45 * V_8 )
{
const struct V_56 * V_57 ;
struct V_5 * V_5 = F_30 ( V_8 ) ;
unsigned int V_23 , V_72 ;
struct V_82 * V_83 ;
struct V_84 * V_13 ;
unsigned int V_6 ;
V_57 = F_85 ( V_8 ) ;
F_53 () ;
do {
V_6 = F_60 ( & V_5 -> V_8 . V_9 ) ;
V_23 = F_15 ( V_5 ,
& V_8 -> V_46 [ V_37 ] . V_12 ) ;
V_72 = F_15 ( V_5 ,
& V_8 -> V_46 [ V_48 ] . V_12 ) ;
} while ( F_3 ( V_5 , V_23 , V_72 , V_6 ) );
F_86 (h, n, &net->ct.hash[hash], hnnode)
if ( F_72 ( & V_8 -> V_46 [ V_37 ] . V_12 ,
& V_83 -> V_12 ) &&
F_73 ( F_71 ( V_83 ) , V_57 ,
F_74 ( V_83 ) ) )
goto V_90;
F_86 (h, n, &net->ct.hash[reply_hash], hnnode)
if ( F_72 ( & V_8 -> V_46 [ V_48 ] . V_12 ,
& V_83 -> V_12 ) &&
F_73 ( F_71 ( V_83 ) , V_57 ,
F_74 ( V_83 ) ) )
goto V_90;
F_87 ( & V_8 -> V_68 ) ;
F_88 () ;
F_40 ( & V_8 -> V_64 . V_65 , 2 ) ;
F_82 ( V_8 , V_23 , V_72 ) ;
F_1 ( V_23 , V_72 ) ;
F_54 ( V_5 , V_91 ) ;
F_55 () ;
return 0 ;
V_90:
F_1 ( V_23 , V_72 ) ;
F_54 ( V_5 , V_92 ) ;
F_55 () ;
return - V_93 ;
}
int
F_89 ( struct V_26 * V_27 )
{
const struct V_56 * V_57 ;
unsigned int V_23 , V_72 ;
struct V_82 * V_83 ;
struct V_45 * V_8 ;
struct V_94 * V_95 ;
struct V_76 * V_77 ;
struct V_84 * V_13 ;
enum V_96 V_97 ;
struct V_5 * V_5 ;
unsigned int V_6 ;
V_8 = F_90 ( V_27 , & V_97 ) ;
V_5 = F_30 ( V_8 ) ;
if ( F_91 ( V_97 ) != V_37 )
return V_41 ;
V_57 = F_85 ( V_8 ) ;
F_53 () ;
do {
V_6 = F_60 ( & V_5 -> V_8 . V_9 ) ;
V_23 = * ( unsigned long * ) & V_8 -> V_46 [ V_48 ] . V_47 . V_98 ;
V_23 = F_13 ( V_23 , V_5 ) ;
V_72 = F_15 ( V_5 ,
& V_8 -> V_46 [ V_48 ] . V_12 ) ;
} while ( F_3 ( V_5 , V_23 , V_72 , V_6 ) );
F_46 ( ! F_75 ( V_8 ) ) ;
F_24 ( L_4 , V_8 ) ;
F_33 ( V_8 ) ;
if ( F_49 ( F_64 ( V_8 ) ) )
goto V_90;
F_86 (h, n, &net->ct.hash[hash], hnnode)
if ( F_72 ( & V_8 -> V_46 [ V_37 ] . V_12 ,
& V_83 -> V_12 ) &&
F_73 ( F_71 ( V_83 ) , V_57 ,
F_74 ( V_83 ) ) )
goto V_90;
F_86 (h, n, &net->ct.hash[reply_hash], hnnode)
if ( F_72 ( & V_8 -> V_46 [ V_48 ] . V_12 ,
& V_83 -> V_12 ) &&
F_73 ( F_71 ( V_83 ) , V_57 ,
F_74 ( V_83 ) ) )
goto V_90;
V_8 -> V_68 . V_99 += V_100 ;
F_87 ( & V_8 -> V_68 ) ;
F_92 ( & V_8 -> V_64 . V_65 ) ;
V_8 -> V_60 |= V_101 ;
V_77 = F_62 ( V_8 ) ;
if ( V_77 ) {
if ( V_27 -> V_77 . V_102 == 0 )
F_93 ( V_27 ) ;
V_77 -> V_103 = F_94 ( V_27 -> V_77 ) ;
}
F_82 ( V_8 , V_23 , V_72 ) ;
F_1 ( V_23 , V_72 ) ;
F_54 ( V_5 , V_91 ) ;
F_55 () ;
V_95 = F_95 ( V_8 ) ;
if ( V_95 && V_95 -> V_104 )
F_96 ( V_105 , V_8 ) ;
F_96 ( F_97 ( V_8 ) ?
V_106 : V_107 , V_8 ) ;
return V_41 ;
V_90:
F_27 ( V_8 ) ;
F_1 ( V_23 , V_72 ) ;
F_54 ( V_5 , V_92 ) ;
F_55 () ;
return V_108 ;
}
int
F_98 ( const struct V_11 * V_12 ,
const struct V_45 * V_109 )
{
struct V_5 * V_5 = F_30 ( V_109 ) ;
const struct V_56 * V_57 ;
struct V_82 * V_83 ;
struct V_84 * V_13 ;
struct V_45 * V_8 ;
unsigned int V_23 ;
V_57 = F_85 ( V_109 ) ;
V_23 = F_15 ( V_5 , V_12 ) ;
F_99 () ;
F_77 (h, n, &net->ct.hash[hash], hnnode) {
V_8 = F_71 ( V_83 ) ;
if ( V_8 != V_109 &&
F_72 ( V_12 , & V_83 -> V_12 ) &&
F_73 ( V_8 , V_57 , F_74 ( V_83 ) ) ) {
F_54 ( V_5 , V_87 ) ;
F_100 () ;
return 1 ;
}
F_54 ( V_5 , V_88 ) ;
}
F_100 () ;
return 0 ;
}
static T_6 int F_101 ( struct V_5 * V_5 , unsigned int V_110 )
{
struct V_82 * V_83 ;
struct V_45 * V_8 = NULL , * V_111 ;
struct V_84 * V_13 ;
unsigned int V_10 = 0 , V_112 = 0 ;
int V_113 = 0 ;
unsigned int V_23 , V_6 ;
T_7 * V_114 ;
F_53 () ;
V_115:
V_6 = F_60 ( & V_5 -> V_8 . V_9 ) ;
V_23 = F_13 ( V_110 , V_5 ) ;
for (; V_10 < V_5 -> V_8 . V_25 ; V_10 ++ ) {
V_114 = & V_4 [ V_23 % V_3 ] ;
F_4 ( V_114 ) ;
if ( F_6 ( & V_5 -> V_8 . V_9 , V_6 ) ) {
F_2 ( V_114 ) ;
goto V_115;
}
F_77 (h, n, &net->ct.hash[hash],
hnnode) {
V_111 = F_71 ( V_83 ) ;
if ( ! F_102 ( V_116 , & V_111 -> V_60 ) &&
! F_64 ( V_111 ) &&
F_80 ( & V_111 -> V_64 . V_65 ) ) {
V_8 = V_111 ;
break;
}
V_112 ++ ;
}
V_23 = ( V_23 + 1 ) % V_5 -> V_8 . V_25 ;
F_2 ( V_114 ) ;
if ( V_8 || V_112 >= V_117 )
break;
}
F_55 () ;
if ( ! V_8 )
return V_113 ;
if ( F_103 ( & V_8 -> V_68 ) ) {
if ( F_61 ( V_8 , 0 , 0 ) ) {
V_113 = 1 ;
F_104 ( V_5 , F_101 ) ;
}
}
F_56 ( V_8 ) ;
return V_113 ;
}
void F_105 ( void )
{
unsigned int rand ;
do {
F_106 ( & rand , sizeof( rand ) ) ;
} while ( ! rand );
F_107 ( & V_17 , 0 , rand ) ;
}
static struct V_45 *
F_108 ( struct V_5 * V_5 ,
const struct V_56 * V_57 ,
const struct V_11 * V_43 ,
const struct V_11 * V_118 ,
T_5 V_119 , T_1 V_23 )
{
struct V_45 * V_8 ;
if ( F_49 ( ! V_17 ) ) {
F_105 () ;
V_23 = F_9 ( V_43 ) ;
}
F_92 ( & V_5 -> V_8 . V_120 ) ;
if ( V_121 &&
F_49 ( F_47 ( & V_5 -> V_8 . V_120 ) > V_121 ) ) {
if ( ! F_101 ( V_5 , V_23 ) ) {
F_109 ( & V_5 -> V_8 . V_120 ) ;
F_110 ( L_5 ) ;
return F_111 ( - V_122 ) ;
}
}
V_8 = F_112 ( V_5 -> V_8 . V_123 , V_119 ) ;
if ( V_8 == NULL )
goto V_90;
F_113 ( & V_8 -> V_53 ) ;
V_8 -> V_46 [ V_37 ] . V_12 = * V_43 ;
V_8 -> V_46 [ V_37 ] . V_47 . V_98 = NULL ;
V_8 -> V_46 [ V_48 ] . V_12 = * V_118 ;
* ( unsigned long * ) ( & V_8 -> V_46 [ V_48 ] . V_47 . V_98 ) = V_23 ;
V_8 -> V_60 = 0 ;
F_114 ( & V_8 -> V_68 , F_69 , ( unsigned long ) V_8 ) ;
F_38 ( & V_8 -> V_62 , V_5 ) ;
memset ( & V_8 -> V_124 [ 0 ] , 0 ,
F_115 ( struct V_45 , V_125 ) -
F_115 ( struct V_45 , V_124 [ 0 ] ) ) ;
if ( V_57 && F_39 ( V_8 , V_126 , V_57 ) < 0 )
goto V_63;
F_40 ( & V_8 -> V_64 . V_65 , 0 ) ;
return V_8 ;
V_63:
F_116 ( V_5 -> V_8 . V_123 , V_8 ) ;
V_90:
F_109 ( & V_5 -> V_8 . V_120 ) ;
return F_111 ( - V_122 ) ;
}
struct V_45 * F_117 ( struct V_5 * V_5 ,
const struct V_56 * V_57 ,
const struct V_11 * V_43 ,
const struct V_11 * V_118 ,
T_5 V_119 )
{
return F_108 ( V_5 , V_57 , V_43 , V_118 , V_119 , 0 ) ;
}
void F_57 ( struct V_45 * V_8 )
{
struct V_5 * V_5 = F_30 ( V_8 ) ;
F_46 ( F_47 ( & V_8 -> V_64 . V_65 ) == 0 ) ;
F_43 ( V_8 ) ;
F_44 ( V_8 ) ;
F_116 ( V_5 -> V_8 . V_123 , V_8 ) ;
F_118 () ;
F_109 ( & V_5 -> V_8 . V_120 ) ;
}
static struct V_82 *
F_119 ( struct V_5 * V_5 , struct V_45 * V_59 ,
const struct V_11 * V_12 ,
struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_26 * V_27 ,
unsigned int V_29 , T_1 V_23 )
{
struct V_45 * V_8 ;
struct V_94 * V_95 ;
struct V_11 V_127 ;
struct V_128 * V_129 ;
struct V_130 * exp = NULL ;
const struct V_56 * V_57 ;
struct V_131 * V_132 ;
struct V_56 V_111 ;
unsigned int * V_133 ;
if ( ! F_22 ( & V_127 , V_12 , V_32 , V_34 ) ) {
F_24 ( L_6 ) ;
return NULL ;
}
V_57 = F_120 ( V_59 , V_27 , & V_111 ) ;
V_8 = F_108 ( V_5 , V_57 , V_12 , & V_127 , V_126 ,
V_23 ) ;
if ( F_121 ( V_8 ) )
return (struct V_82 * ) V_8 ;
if ( V_59 && F_122 ( V_59 ) ) {
F_123 ( V_8 ) ;
F_124 ( V_8 ) ;
}
V_132 = V_59 ? F_125 ( V_59 ) : NULL ;
if ( V_132 ) {
V_133 = F_126 ( V_132 ) ;
if ( F_49 ( ! V_133 ) )
V_133 = V_34 -> V_134 ( V_5 ) ;
} else {
V_133 = V_34 -> V_134 ( V_5 ) ;
}
if ( ! V_34 -> V_135 ( V_8 , V_27 , V_29 , V_133 ) ) {
F_57 ( V_8 ) ;
F_24 ( L_7 ) ;
return NULL ;
}
if ( V_132 )
F_127 ( V_8 , F_128 ( V_132 -> V_68 ) ,
V_126 ) ;
F_129 ( V_8 , V_126 ) ;
F_130 ( V_8 , V_126 ) ;
F_131 ( V_8 ) ;
V_129 = V_59 ? F_132 ( V_59 ) : NULL ;
F_133 ( V_8 , V_129 ? V_129 -> V_136 : 0 ,
V_129 ? V_129 -> V_137 : 0 ,
V_126 ) ;
F_53 () ;
if ( V_5 -> V_8 . V_138 ) {
F_4 ( & V_139 ) ;
exp = F_134 ( V_5 , V_57 , V_12 ) ;
if ( exp ) {
F_24 ( L_8 ,
V_8 , exp ) ;
F_135 ( V_140 , & V_8 -> V_60 ) ;
V_8 -> V_71 = exp -> V_71 ;
if ( exp -> V_104 ) {
V_95 = F_136 ( V_8 , exp -> V_104 ,
V_126 ) ;
if ( V_95 )
F_137 ( V_95 -> V_104 , exp -> V_104 ) ;
}
#ifdef F_138
V_8 -> V_141 = exp -> V_71 -> V_141 ;
#endif
#ifdef F_139
V_8 -> V_142 = exp -> V_71 -> V_142 ;
#endif
F_54 ( V_5 , V_143 ) ;
}
F_2 ( & V_139 ) ;
}
if ( ! exp ) {
F_140 ( V_8 , V_59 , V_126 ) ;
F_54 ( V_5 , V_135 ) ;
}
F_141 ( & V_8 -> V_64 ) ;
F_32 ( V_8 ) ;
F_55 () ;
if ( exp ) {
if ( exp -> V_144 )
exp -> V_144 ( V_8 , exp ) ;
F_142 ( exp ) ;
}
return & V_8 -> V_46 [ V_37 ] ;
}
static inline struct V_45 *
F_143 ( struct V_5 * V_5 , struct V_45 * V_59 ,
struct V_26 * V_27 ,
unsigned int V_29 ,
T_3 V_30 ,
T_4 V_22 ,
struct V_31 * V_32 ,
struct V_33 * V_34 ,
int * V_145 ,
enum V_96 * V_97 )
{
const struct V_56 * V_57 ;
struct V_11 V_12 ;
struct V_82 * V_83 ;
struct V_56 V_111 ;
struct V_45 * V_8 ;
T_1 V_23 ;
if ( ! F_16 ( V_27 , F_144 ( V_27 ) ,
V_29 , V_30 , V_22 , V_5 , & V_12 , V_32 ,
V_34 ) ) {
F_24 ( L_9 ) ;
return NULL ;
}
V_57 = F_120 ( V_59 , V_27 , & V_111 ) ;
V_23 = F_9 ( & V_12 ) ;
V_83 = F_79 ( V_5 , V_57 , & V_12 , V_23 ) ;
if ( ! V_83 ) {
V_83 = F_119 ( V_5 , V_59 , & V_12 , V_32 , V_34 ,
V_27 , V_29 , V_23 ) ;
if ( ! V_83 )
return NULL ;
if ( F_121 ( V_83 ) )
return ( void * ) V_83 ;
}
V_8 = F_71 ( V_83 ) ;
if ( F_74 ( V_83 ) == V_48 ) {
* V_97 = V_146 ;
* V_145 = 1 ;
} else {
if ( F_102 ( V_147 , & V_8 -> V_60 ) ) {
F_24 ( L_10 , V_8 ) ;
* V_97 = V_148 ;
} else if ( F_102 ( V_140 , & V_8 -> V_60 ) ) {
F_24 ( L_11 ,
V_8 ) ;
* V_97 = V_149 ;
} else {
F_24 ( L_12 , V_8 ) ;
* V_97 = V_150 ;
}
* V_145 = 0 ;
}
V_27 -> V_67 = & V_8 -> V_64 ;
V_27 -> V_151 = * V_97 ;
return V_8 ;
}
unsigned int
F_145 ( struct V_5 * V_5 , T_4 V_152 , unsigned int V_153 ,
struct V_26 * V_27 )
{
struct V_45 * V_8 , * V_59 = NULL ;
enum V_96 V_97 ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
unsigned int * V_133 ;
unsigned int V_29 ;
T_4 V_22 ;
int V_145 = 0 ;
int V_39 ;
if ( V_27 -> V_67 ) {
V_59 = (struct V_45 * ) V_27 -> V_67 ;
if ( ! F_50 ( V_59 ) ) {
F_104 ( V_5 , V_154 ) ;
return V_41 ;
}
V_27 -> V_67 = NULL ;
}
V_32 = F_19 ( V_152 ) ;
V_39 = V_32 -> V_40 ( V_27 , F_144 ( V_27 ) ,
& V_29 , & V_22 ) ;
if ( V_39 <= 0 ) {
F_24 ( L_13 ) ;
F_104 ( V_5 , error ) ;
F_104 ( V_5 , V_155 ) ;
V_39 = - V_39 ;
goto V_90;
}
V_34 = F_21 ( V_152 , V_22 ) ;
if ( V_34 -> error != NULL ) {
V_39 = V_34 -> error ( V_5 , V_59 , V_27 , V_29 , & V_97 ,
V_152 , V_153 ) ;
if ( V_39 <= 0 ) {
F_104 ( V_5 , error ) ;
F_104 ( V_5 , V_155 ) ;
V_39 = - V_39 ;
goto V_90;
}
if ( V_27 -> V_67 )
goto V_90;
}
V_8 = F_143 ( V_5 , V_59 , V_27 , V_29 , V_152 , V_22 ,
V_32 , V_34 , & V_145 , & V_97 ) ;
if ( ! V_8 ) {
F_104 ( V_5 , V_155 ) ;
V_39 = V_41 ;
goto V_90;
}
if ( F_121 ( V_8 ) ) {
F_104 ( V_5 , V_156 ) ;
V_39 = V_108 ;
goto V_90;
}
F_46 ( V_27 -> V_67 ) ;
V_133 = F_146 ( V_5 , V_8 , V_34 ) ;
V_39 = V_34 -> V_157 ( V_8 , V_27 , V_29 , V_97 , V_152 , V_153 , V_133 ) ;
if ( V_39 <= 0 ) {
F_24 ( L_14 ) ;
F_147 ( V_27 -> V_67 ) ;
V_27 -> V_67 = NULL ;
F_104 ( V_5 , V_155 ) ;
if ( V_39 == - V_108 )
F_104 ( V_5 , V_156 ) ;
V_39 = - V_39 ;
goto V_90;
}
if ( V_145 && ! F_148 ( V_147 , & V_8 -> V_60 ) )
F_96 ( V_158 , V_8 ) ;
V_90:
if ( V_59 ) {
if ( V_39 == V_159 )
V_27 -> V_67 = (struct V_66 * ) V_59 ;
else
F_56 ( V_59 ) ;
}
return V_39 ;
}
bool F_149 ( struct V_11 * V_42 ,
const struct V_11 * V_43 )
{
bool V_39 ;
F_18 () ;
V_39 = F_22 ( V_42 , V_43 ,
F_19 ( V_43 -> V_14 . V_30 ) ,
F_21 ( V_43 -> V_14 . V_30 ,
V_43 -> V_15 . V_22 ) ) ;
F_20 () ;
return V_39 ;
}
void F_150 ( struct V_45 * V_8 ,
const struct V_11 * V_160 )
{
struct V_94 * V_95 = F_95 ( V_8 ) ;
F_46 ( ! F_75 ( V_8 ) ) ;
F_24 ( L_15 , V_8 ) ;
F_151 ( V_160 ) ;
V_8 -> V_46 [ V_48 ] . V_12 = * V_160 ;
if ( V_8 -> V_71 || ( V_95 && ! F_152 ( & V_95 -> V_161 ) ) )
return;
F_18 () ;
F_140 ( V_8 , NULL , V_126 ) ;
F_20 () ;
}
void F_153 ( struct V_45 * V_8 ,
enum V_96 V_97 ,
const struct V_26 * V_27 ,
unsigned long V_162 ,
int V_163 )
{
F_46 ( V_8 -> V_68 . V_164 == ( unsigned long ) V_8 ) ;
F_46 ( V_27 ) ;
if ( F_102 ( V_165 , & V_8 -> V_60 ) )
goto V_166;
if ( ! F_75 ( V_8 ) ) {
V_8 -> V_68 . V_99 = V_162 ;
} else {
unsigned long V_167 = V_100 + V_162 ;
if ( V_167 - V_8 -> V_68 . V_99 >= V_168 )
F_154 ( & V_8 -> V_68 , V_167 ) ;
}
V_166:
if ( V_163 ) {
struct V_169 * V_166 ;
V_166 = F_155 ( V_8 ) ;
if ( V_166 ) {
struct V_170 * V_171 = V_166 -> V_171 ;
F_156 ( & V_171 [ F_91 ( V_97 ) ] . V_172 ) ;
F_157 ( V_27 -> V_173 , & V_171 [ F_91 ( V_97 ) ] . V_174 ) ;
}
}
}
bool F_158 ( struct V_45 * V_8 ,
enum V_96 V_97 ,
const struct V_26 * V_27 ,
int V_163 )
{
if ( V_163 ) {
struct V_169 * V_166 ;
V_166 = F_155 ( V_8 ) ;
if ( V_166 ) {
struct V_170 * V_171 = V_166 -> V_171 ;
F_156 ( & V_171 [ F_91 ( V_97 ) ] . V_172 ) ;
F_157 ( V_27 -> V_173 - F_144 ( V_27 ) ,
& V_171 [ F_91 ( V_97 ) ] . V_174 ) ;
}
}
if ( F_103 ( & V_8 -> V_68 ) ) {
V_8 -> V_68 . V_175 ( ( unsigned long ) V_8 ) ;
return true ;
}
return false ;
}
int F_159 ( struct V_26 * V_27 ,
const struct V_11 * V_12 )
{
if ( F_160 ( V_27 , V_176 , V_12 -> V_14 . V_20 . V_177 . V_178 ) ||
F_160 ( V_27 , V_179 , V_12 -> V_15 . V_20 . V_177 . V_178 ) )
goto V_180;
return 0 ;
V_180:
return - 1 ;
}
int F_161 ( struct V_181 * V_182 [] ,
struct V_11 * V_183 )
{
if ( ! V_182 [ V_176 ] || ! V_182 [ V_179 ] )
return - V_184 ;
V_183 -> V_14 . V_20 . V_177 . V_178 = F_162 ( V_182 [ V_176 ] ) ;
V_183 -> V_15 . V_20 . V_177 . V_178 = F_162 ( V_182 [ V_179 ] ) ;
return 0 ;
}
int F_163 ( void )
{
return F_164 ( V_185 , V_186 + 1 ) ;
}
static void F_165 ( struct V_26 * V_187 , const struct V_26 * V_27 )
{
struct V_45 * V_8 ;
enum V_96 V_97 ;
V_8 = F_90 ( V_27 , & V_97 ) ;
if ( F_91 ( V_97 ) == V_37 )
V_97 = V_188 ;
else
V_97 = V_149 ;
V_187 -> V_67 = & V_8 -> V_64 ;
V_187 -> V_151 = V_97 ;
F_141 ( V_187 -> V_67 ) ;
}
static struct V_45 *
F_166 ( struct V_5 * V_5 , int (* F_167)( struct V_45 * V_10 , void * V_164 ) ,
void * V_164 , unsigned int * V_85 )
{
struct V_82 * V_83 ;
struct V_45 * V_8 ;
struct V_84 * V_13 ;
int V_51 ;
T_7 * V_114 ;
for (; * V_85 < V_5 -> V_8 . V_25 ; ( * V_85 ) ++ ) {
V_114 = & V_4 [ * V_85 % V_3 ] ;
F_53 () ;
F_4 ( V_114 ) ;
if ( * V_85 < V_5 -> V_8 . V_25 ) {
F_86 (h, n, &net->ct.hash[*bucket], hnnode) {
if ( F_74 ( V_83 ) != V_37 )
continue;
V_8 = F_71 ( V_83 ) ;
if ( F_167 ( V_8 , V_164 ) )
goto V_87;
}
}
F_2 ( V_114 ) ;
F_55 () ;
}
F_168 (cpu) {
struct V_49 * V_50 = F_29 ( V_5 -> V_8 . V_52 , V_51 ) ;
F_169 ( & V_50 -> V_53 ) ;
F_86 (h, n, &pcpu->unconfirmed, hnnode) {
V_8 = F_71 ( V_83 ) ;
if ( F_167 ( V_8 , V_164 ) )
F_68 ( V_80 , & V_8 -> V_60 ) ;
}
F_170 ( & V_50 -> V_53 ) ;
}
return NULL ;
V_87:
F_92 ( & V_8 -> V_64 . V_65 ) ;
F_2 ( V_114 ) ;
F_55 () ;
return V_8 ;
}
void F_171 ( struct V_5 * V_5 ,
int (* F_167)( struct V_45 * V_10 , void * V_164 ) ,
void * V_164 , T_1 V_74 , int V_75 )
{
struct V_45 * V_8 ;
unsigned int V_85 = 0 ;
while ( ( V_8 = F_166 ( V_5 , F_167 , V_164 , & V_85 ) ) != NULL ) {
if ( F_103 ( & V_8 -> V_68 ) )
F_61 ( V_8 , V_74 , V_75 ) ;
F_56 ( V_8 ) ;
}
}
static int F_172 ( struct V_45 * V_10 , void * V_164 )
{
return 1 ;
}
void F_173 ( void * V_23 , unsigned int V_24 )
{
if ( F_174 ( V_23 ) )
F_175 ( V_23 ) ;
else
F_176 ( ( unsigned long ) V_23 ,
F_177 ( sizeof( struct V_189 ) * V_24 ) ) ;
}
static int F_178 ( void )
{
int V_112 = 0 , V_51 ;
F_168 (cpu) {
struct V_45 * V_8 = & F_179 ( V_190 , V_51 ) ;
V_112 += F_47 ( & V_8 -> V_64 . V_65 ) - 1 ;
}
return V_112 ;
}
void F_180 ( void )
{
F_181 ( V_191 , NULL ) ;
}
void F_182 ( void )
{
F_181 ( V_192 , NULL ) ;
while ( F_178 () > 0 )
F_183 () ;
#ifdef F_184
F_185 ( & V_193 ) ;
#endif
F_186 () ;
F_187 () ;
F_188 () ;
F_189 () ;
F_190 () ;
F_191 () ;
F_192 () ;
F_193 () ;
F_194 () ;
}
void F_195 ( struct V_5 * V_5 )
{
F_196 ( V_194 ) ;
F_197 ( & V_5 -> V_195 , & V_194 ) ;
F_198 ( & V_194 ) ;
}
void F_198 ( struct V_196 * V_197 )
{
int V_198 ;
struct V_5 * V_5 ;
F_199 () ;
V_199:
V_198 = 0 ;
F_200 (net, net_exit_list, exit_list) {
F_171 ( V_5 , F_172 , NULL , 0 , 0 ) ;
if ( F_47 ( & V_5 -> V_8 . V_120 ) != 0 )
V_198 = 1 ;
}
if ( V_198 ) {
F_183 () ;
goto V_199;
}
F_200 (net, net_exit_list, exit_list) {
F_173 ( V_5 -> V_8 . V_23 , V_5 -> V_8 . V_25 ) ;
F_201 ( V_5 ) ;
F_202 ( V_5 ) ;
F_203 ( V_5 ) ;
F_204 ( V_5 ) ;
F_205 ( V_5 ) ;
F_206 ( V_5 ) ;
F_207 ( V_5 -> V_8 . V_123 ) ;
F_41 ( V_5 -> V_8 . V_200 ) ;
F_208 ( V_5 -> V_8 . V_201 ) ;
F_208 ( V_5 -> V_8 . V_52 ) ;
}
}
void * F_209 ( unsigned int * V_202 , int V_203 )
{
struct V_204 * V_23 ;
unsigned int V_205 , V_10 ;
T_8 V_206 ;
F_210 ( sizeof( struct V_204 ) != sizeof( struct V_189 ) ) ;
V_205 = * V_202 = F_211 ( * V_202 , V_207 / sizeof( struct V_204 ) ) ;
V_206 = V_205 * sizeof( struct V_204 ) ;
V_23 = ( void * ) F_212 ( V_208 | V_209 | V_210 ,
F_177 ( V_206 ) ) ;
if ( ! V_23 )
V_23 = F_213 ( V_206 ) ;
if ( V_23 && V_203 )
for ( V_10 = 0 ; V_10 < V_205 ; V_10 ++ )
F_214 ( & V_23 [ V_10 ] , V_10 ) ;
return V_23 ;
}
int F_215 ( const char * V_211 , struct V_212 * V_213 )
{
int V_10 , V_85 , V_214 ;
unsigned int V_215 , V_216 ;
struct V_204 * V_23 , * V_217 ;
struct V_82 * V_83 ;
struct V_45 * V_8 ;
if ( V_218 -> V_219 -> V_220 != & V_221 )
return - V_222 ;
if ( ! V_223 )
return F_216 ( V_211 , V_213 ) ;
V_214 = F_217 ( V_211 , 0 , & V_215 ) ;
if ( V_214 )
return V_214 ;
if ( ! V_215 )
return - V_184 ;
V_23 = F_209 ( & V_215 , 1 ) ;
if ( ! V_23 )
return - V_122 ;
F_53 () ;
F_7 () ;
F_218 ( & V_221 . V_8 . V_9 ) ;
for ( V_10 = 0 ; V_10 < V_221 . V_8 . V_25 ; V_10 ++ ) {
while ( ! F_219 ( & V_221 . V_8 . V_23 [ V_10 ] ) ) {
V_83 = F_220 ( V_221 . V_8 . V_23 [ V_10 ] . V_224 ,
struct V_82 , V_47 ) ;
V_8 = F_71 ( V_83 ) ;
F_25 ( & V_83 -> V_47 ) ;
V_85 = F_14 ( & V_83 -> V_12 , V_215 ) ;
F_83 ( & V_83 -> V_47 , & V_23 [ V_85 ] ) ;
}
}
V_216 = V_221 . V_8 . V_25 ;
V_217 = V_221 . V_8 . V_23 ;
V_221 . V_8 . V_25 = V_223 = V_215 ;
V_221 . V_8 . V_23 = V_23 ;
F_221 ( & V_221 . V_8 . V_9 ) ;
F_8 () ;
F_55 () ;
F_173 ( V_217 , V_216 ) ;
return 0 ;
}
void F_222 ( unsigned long V_225 )
{
int V_51 ;
F_168 (cpu)
F_179 ( V_190 , V_51 ) . V_60 |= V_225 ;
}
int F_223 ( void )
{
int V_226 = 8 ;
int V_10 , V_39 , V_51 ;
for ( V_10 = 0 ; V_10 < V_3 ; V_10 ++ )
F_113 ( & V_4 [ V_10 ] ) ;
if ( ! V_223 ) {
V_223
= ( ( ( V_227 << V_228 ) / 16384 )
/ sizeof( struct V_189 ) ) ;
if ( V_227 > ( 4 * ( 1024 * 1024 * 1024 / V_207 ) ) )
V_223 = 65536 ;
else if ( V_227 > ( 1024 * 1024 * 1024 / V_207 ) )
V_223 = 16384 ;
if ( V_223 < 32 )
V_223 = 32 ;
V_226 = 4 ;
}
V_121 = V_226 * V_223 ;
F_224 ( V_229 L_16 ,
V_230 , V_223 ,
V_121 ) ;
V_39 = F_225 () ;
if ( V_39 < 0 )
goto V_231;
V_39 = F_226 () ;
if ( V_39 < 0 )
goto V_232;
V_39 = F_227 () ;
if ( V_39 < 0 )
goto V_233;
V_39 = F_228 () ;
if ( V_39 < 0 )
goto V_234;
V_39 = F_229 () ;
if ( V_39 < 0 )
goto V_235;
V_39 = F_230 () ;
if ( V_39 < 0 )
goto V_236;
V_39 = F_231 () ;
if ( V_39 < 0 )
goto V_237;
V_39 = F_232 () ;
if ( V_39 < 0 )
goto V_238;
#ifdef F_184
V_39 = F_233 ( & V_193 ) ;
if ( V_39 < 0 )
goto V_239;
#endif
V_39 = F_234 () ;
if ( V_39 < 0 )
goto V_240;
F_168 (cpu) {
struct V_45 * V_8 = & F_179 ( V_190 , V_51 ) ;
F_38 ( & V_8 -> V_62 , & V_221 ) ;
F_40 ( & V_8 -> V_64 . V_65 , 1 ) ;
}
F_222 ( V_101 | V_241 ) ;
return 0 ;
V_240:
#ifdef F_184
F_185 ( & V_193 ) ;
V_239:
#endif
F_187 () ;
V_238:
F_188 () ;
V_237:
F_189 () ;
V_236:
F_190 () ;
V_235:
F_191 () ;
V_234:
F_192 () ;
V_233:
F_193 () ;
V_232:
F_194 () ;
V_231:
return V_39 ;
}
void F_235 ( void )
{
F_181 ( V_191 , F_165 ) ;
F_181 ( V_192 , F_45 ) ;
}
int F_236 ( struct V_5 * V_5 )
{
int V_39 = - V_122 ;
int V_51 ;
F_40 ( & V_5 -> V_8 . V_120 , 0 ) ;
F_237 ( & V_5 -> V_8 . V_9 ) ;
V_5 -> V_8 . V_52 = F_238 ( struct V_49 ) ;
if ( ! V_5 -> V_8 . V_52 )
goto V_242;
F_168 (cpu) {
struct V_49 * V_50 = F_29 ( V_5 -> V_8 . V_52 , V_51 ) ;
F_113 ( & V_50 -> V_53 ) ;
F_214 ( & V_50 -> V_55 , V_243 ) ;
F_214 ( & V_50 -> V_54 , V_244 ) ;
}
V_5 -> V_8 . V_201 = F_238 ( struct V_245 ) ;
if ( ! V_5 -> V_8 . V_201 )
goto V_246;
V_5 -> V_8 . V_200 = F_239 ( V_208 , L_17 , V_5 ) ;
if ( ! V_5 -> V_8 . V_200 )
goto V_247;
V_5 -> V_8 . V_123 = F_240 ( V_5 -> V_8 . V_200 ,
sizeof( struct V_45 ) , 0 ,
V_248 , NULL ) ;
if ( ! V_5 -> V_8 . V_123 ) {
F_224 ( V_249 L_18 ) ;
goto V_250;
}
V_5 -> V_8 . V_25 = V_223 ;
V_5 -> V_8 . V_23 = F_209 ( & V_5 -> V_8 . V_25 , 1 ) ;
if ( ! V_5 -> V_8 . V_23 ) {
F_224 ( V_249 L_19 ) ;
goto V_251;
}
V_39 = F_241 ( V_5 ) ;
if ( V_39 < 0 )
goto V_231;
V_39 = F_242 ( V_5 ) ;
if ( V_39 < 0 )
goto V_232;
V_39 = F_243 ( V_5 ) ;
if ( V_39 < 0 )
goto V_233;
V_39 = F_244 ( V_5 ) ;
if ( V_39 < 0 )
goto V_234;
V_39 = F_245 ( V_5 ) ;
if ( V_39 < 0 )
goto V_236;
V_39 = F_246 ( V_5 ) ;
if ( V_39 < 0 )
goto V_240;
return 0 ;
V_240:
F_202 ( V_5 ) ;
V_236:
F_203 ( V_5 ) ;
V_234:
F_204 ( V_5 ) ;
V_233:
F_205 ( V_5 ) ;
V_232:
F_206 ( V_5 ) ;
V_231:
F_173 ( V_5 -> V_8 . V_23 , V_5 -> V_8 . V_25 ) ;
V_251:
F_207 ( V_5 -> V_8 . V_123 ) ;
V_250:
F_41 ( V_5 -> V_8 . V_200 ) ;
V_247:
F_208 ( V_5 -> V_8 . V_201 ) ;
V_246:
F_208 ( V_5 -> V_8 . V_52 ) ;
V_242:
return V_39 ;
}
