static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_4 ) ;
return - V_5 ;
}
static void F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 -> V_7 )
V_2 -> V_6 -> V_7 ( V_2 ) ;
F_4 ( V_2 , V_8 , 0 ) ;
F_5 ( V_9 , V_2 ) ;
F_6 ( V_2 ) ;
}
unsigned long F_7 ( unsigned long V_10 )
{
return V_10 ? ( F_8 () % V_10 ) + ( V_10 >> 1 ) : 0 ;
}
static int F_9 ( struct V_11 * V_12 )
{
int V_13 = 0 ;
int V_14 ;
struct V_15 * V_16 ;
F_10 ( V_12 , V_17 ) ;
F_11 ( & V_12 -> V_18 ) ;
V_16 = F_12 ( V_12 -> V_16 ,
F_13 ( & V_12 -> V_18 ) ) ;
for ( V_14 = 0 ; V_14 < ( 1 << V_16 -> V_19 ) ; V_14 ++ ) {
struct V_1 * V_20 ;
struct V_1 T_1 * * V_21 ;
V_21 = & V_16 -> V_22 [ V_14 ] ;
while ( ( V_20 = F_12 ( * V_21 ,
F_13 ( & V_12 -> V_18 ) ) ) != NULL ) {
F_14 ( & V_20 -> V_18 ) ;
if ( F_15 ( & V_20 -> V_23 ) == 1 &&
! ( V_20 -> V_24 & V_25 ) ) {
F_16 ( * V_21 ,
F_12 ( V_20 -> V_26 ,
F_13 ( & V_12 -> V_18 ) ) ) ;
V_20 -> V_27 = 1 ;
V_13 = 1 ;
F_17 ( & V_20 -> V_18 ) ;
F_3 ( V_20 ) ;
continue;
}
F_17 ( & V_20 -> V_18 ) ;
V_21 = & V_20 -> V_26 ;
}
}
V_12 -> V_28 = V_29 ;
F_18 ( & V_12 -> V_18 ) ;
return V_13 ;
}
static void F_19 ( struct V_1 * V_20 , unsigned long V_30 )
{
F_20 ( V_20 ) ;
if ( F_21 ( F_22 ( & V_20 -> V_31 , V_30 ) ) ) {
F_23 ( L_1 ,
V_20 -> V_24 ) ;
F_24 () ;
}
}
static int F_25 ( struct V_1 * V_20 )
{
if ( ( V_20 -> V_24 & V_32 ) &&
F_26 ( & V_20 -> V_31 ) ) {
F_6 ( V_20 ) ;
return 1 ;
}
return 0 ;
}
static void F_27 ( struct V_33 * V_34 )
{
struct V_3 * V_4 ;
while ( ( V_4 = F_28 ( V_34 ) ) != NULL ) {
F_29 ( V_4 -> V_35 ) ;
F_2 ( V_4 ) ;
}
}
static void F_30 ( struct V_11 * V_12 , struct V_36 * V_35 )
{
int V_14 ;
struct V_15 * V_16 ;
V_16 = F_12 ( V_12 -> V_16 ,
F_13 ( & V_12 -> V_18 ) ) ;
for ( V_14 = 0 ; V_14 < ( 1 << V_16 -> V_19 ) ; V_14 ++ ) {
struct V_1 * V_20 ;
struct V_1 T_1 * * V_21 = & V_16 -> V_22 [ V_14 ] ;
while ( ( V_20 = F_12 ( * V_21 ,
F_13 ( & V_12 -> V_18 ) ) ) != NULL ) {
if ( V_35 && V_20 -> V_35 != V_35 ) {
V_21 = & V_20 -> V_26 ;
continue;
}
F_16 ( * V_21 ,
F_12 ( V_20 -> V_26 ,
F_13 ( & V_12 -> V_18 ) ) ) ;
F_14 ( & V_20 -> V_18 ) ;
F_25 ( V_20 ) ;
V_20 -> V_27 = 1 ;
if ( F_15 ( & V_20 -> V_23 ) != 1 ) {
F_31 ( & V_20 -> V_37 ) ;
V_20 -> V_38 = 0 ;
V_20 -> V_39 = F_1 ;
if ( V_20 -> V_24 & V_40 )
V_20 -> V_24 = V_41 ;
else
V_20 -> V_24 = V_42 ;
F_32 ( 2 , L_2 , V_20 ) ;
}
F_17 ( & V_20 -> V_18 ) ;
F_3 ( V_20 ) ;
}
}
}
void F_33 ( struct V_11 * V_12 , struct V_36 * V_35 )
{
F_11 ( & V_12 -> V_18 ) ;
F_30 ( V_12 , V_35 ) ;
F_18 ( & V_12 -> V_18 ) ;
}
int F_34 ( struct V_11 * V_12 , struct V_36 * V_35 )
{
F_11 ( & V_12 -> V_18 ) ;
F_30 ( V_12 , V_35 ) ;
F_35 ( V_12 , V_35 ) ;
F_18 ( & V_12 -> V_18 ) ;
F_36 ( & V_12 -> V_43 ) ;
F_27 ( & V_12 -> V_44 ) ;
return 0 ;
}
static struct V_1 * F_37 ( struct V_11 * V_12 , struct V_36 * V_35 )
{
struct V_1 * V_20 = NULL ;
unsigned long V_45 = V_29 ;
int V_46 ;
V_46 = F_38 ( & V_12 -> V_46 ) - 1 ;
if ( V_46 >= V_12 -> V_47 ||
( V_46 >= V_12 -> V_48 &&
F_39 ( V_45 , V_12 -> V_28 + 5 * V_49 ) ) ) {
if ( ! F_9 ( V_12 ) &&
V_46 >= V_12 -> V_47 ) {
F_40 ( L_3 ,
V_12 -> V_50 ) ;
F_10 ( V_12 , V_51 ) ;
goto V_52;
}
}
V_20 = F_41 ( V_12 -> V_53 + V_35 -> V_54 , V_55 ) ;
if ( ! V_20 )
goto V_52;
F_42 ( & V_20 -> V_37 ) ;
F_43 ( & V_20 -> V_18 ) ;
F_44 ( & V_20 -> V_56 ) ;
V_20 -> V_57 = V_20 -> V_58 = V_45 ;
V_20 -> V_24 = V_42 ;
V_20 -> V_39 = F_1 ;
F_44 ( & V_20 -> V_59 . V_60 ) ;
V_20 -> V_6 = F_45 ( & V_12 -> V_6 ) ;
F_46 ( & V_20 -> V_31 , V_61 , ( unsigned long ) V_20 ) ;
F_10 ( V_12 , V_62 ) ;
V_20 -> V_12 = V_12 ;
F_47 ( & V_20 -> V_23 , 1 ) ;
V_20 -> V_27 = 1 ;
V_63:
return V_20 ;
V_52:
F_48 ( & V_12 -> V_46 ) ;
goto V_63;
}
static void F_49 ( T_2 * V_64 )
{
F_50 ( V_64 , sizeof( * V_64 ) ) ;
* V_64 |= 1 ;
}
static struct V_15 * F_51 ( unsigned int V_65 )
{
T_3 V_66 = ( 1 << V_65 ) * sizeof( struct V_1 * ) ;
struct V_15 * V_67 ;
struct V_1 T_1 * * V_68 ;
int V_14 ;
V_67 = F_52 ( sizeof( * V_67 ) , V_55 ) ;
if ( ! V_67 )
return NULL ;
if ( V_66 <= V_69 )
V_68 = F_41 ( V_66 , V_55 ) ;
else
V_68 = (struct V_1 T_1 * * )
F_53 ( V_55 | V_70 ,
F_54 ( V_66 ) ) ;
if ( ! V_68 ) {
F_55 ( V_67 ) ;
return NULL ;
}
V_67 -> V_22 = V_68 ;
V_67 -> V_19 = V_65 ;
for ( V_14 = 0 ; V_14 < V_71 ; V_14 ++ )
F_49 ( & V_67 -> V_72 [ V_14 ] ) ;
return V_67 ;
}
static void F_56 ( struct V_73 * V_74 )
{
struct V_15 * V_16 = F_57 ( V_74 ,
struct V_15 ,
V_75 ) ;
T_3 V_66 = ( 1 << V_16 -> V_19 ) * sizeof( struct V_1 * ) ;
struct V_1 T_1 * * V_68 = V_16 -> V_22 ;
if ( V_66 <= V_69 )
F_55 ( V_68 ) ;
else
F_58 ( ( unsigned long ) V_68 , F_54 ( V_66 ) ) ;
F_55 ( V_16 ) ;
}
static struct V_15 * F_59 ( struct V_11 * V_12 ,
unsigned long V_76 )
{
unsigned int V_14 , V_77 ;
struct V_15 * V_78 , * V_79 ;
F_10 ( V_12 , V_80 ) ;
V_79 = F_12 ( V_12 -> V_16 ,
F_13 ( & V_12 -> V_18 ) ) ;
V_78 = F_51 ( V_76 ) ;
if ( ! V_78 )
return V_79 ;
for ( V_14 = 0 ; V_14 < ( 1 << V_79 -> V_19 ) ; V_14 ++ ) {
struct V_1 * V_20 , * V_26 ;
for ( V_20 = F_12 ( V_79 -> V_22 [ V_14 ] ,
F_13 ( & V_12 -> V_18 ) ) ;
V_20 != NULL ;
V_20 = V_26 ) {
V_77 = V_12 -> V_77 ( V_20 -> V_81 , V_20 -> V_35 ,
V_78 -> V_72 ) ;
V_77 >>= ( 32 - V_78 -> V_19 ) ;
V_26 = F_12 ( V_20 -> V_26 ,
F_13 ( & V_12 -> V_18 ) ) ;
F_16 ( V_20 -> V_26 ,
F_12 (
V_78 -> V_22 [ V_77 ] ,
F_13 ( & V_12 -> V_18 ) ) ) ;
F_16 ( V_78 -> V_22 [ V_77 ] , V_20 ) ;
}
}
F_16 ( V_12 -> V_16 , V_78 ) ;
F_60 ( & V_79 -> V_75 , F_56 ) ;
return V_78 ;
}
struct V_1 * F_61 ( struct V_11 * V_12 , const void * V_82 ,
struct V_36 * V_35 )
{
struct V_1 * V_20 ;
F_10 ( V_12 , V_83 ) ;
F_62 () ;
V_20 = F_63 ( V_12 , V_82 , V_35 ) ;
if ( V_20 ) {
if ( ! F_64 ( & V_20 -> V_23 ) )
V_20 = NULL ;
F_10 ( V_12 , V_84 ) ;
}
F_65 () ;
return V_20 ;
}
struct V_1 * F_66 ( struct V_11 * V_12 , struct V_85 * V_85 ,
const void * V_82 )
{
struct V_1 * V_20 ;
int V_86 = V_12 -> V_86 ;
T_2 V_87 ;
struct V_15 * V_16 ;
F_10 ( V_12 , V_83 ) ;
F_62 () ;
V_16 = F_67 ( V_12 -> V_16 ) ;
V_87 = V_12 -> V_77 ( V_82 , NULL , V_16 -> V_72 ) >> ( 32 - V_16 -> V_19 ) ;
for ( V_20 = F_67 ( V_16 -> V_22 [ V_87 ] ) ;
V_20 != NULL ;
V_20 = F_67 ( V_20 -> V_26 ) ) {
if ( ! memcmp ( V_20 -> V_81 , V_82 , V_86 ) &&
F_68 ( F_69 ( V_20 -> V_35 ) , V_85 ) ) {
if ( ! F_64 ( & V_20 -> V_23 ) )
V_20 = NULL ;
F_10 ( V_12 , V_84 ) ;
break;
}
}
F_65 () ;
return V_20 ;
}
struct V_1 * F_70 ( struct V_11 * V_12 , const void * V_82 ,
struct V_36 * V_35 , bool V_88 )
{
T_2 V_87 ;
int V_86 = V_12 -> V_86 ;
int error ;
struct V_1 * V_89 , * V_90 , * V_20 = F_37 ( V_12 , V_35 ) ;
struct V_15 * V_16 ;
if ( ! V_20 ) {
V_90 = F_71 ( - V_91 ) ;
goto V_63;
}
memcpy ( V_20 -> V_81 , V_82 , V_86 ) ;
V_20 -> V_35 = V_35 ;
F_72 ( V_35 ) ;
if ( V_12 -> V_92 && ( error = V_12 -> V_92 ( V_20 ) ) < 0 ) {
V_90 = F_71 ( error ) ;
goto V_93;
}
if ( V_35 -> V_94 -> V_95 ) {
error = V_35 -> V_94 -> V_95 ( V_35 , V_20 ) ;
if ( error < 0 ) {
V_90 = F_71 ( error ) ;
goto V_93;
}
}
if ( V_20 -> V_6 -> V_96 &&
( error = V_20 -> V_6 -> V_96 ( V_20 ) ) < 0 ) {
V_90 = F_71 ( error ) ;
goto V_93;
}
V_20 -> V_97 = V_29 - ( F_73 ( V_20 -> V_6 , V_98 ) << 1 ) ;
F_11 ( & V_12 -> V_18 ) ;
V_16 = F_12 ( V_12 -> V_16 ,
F_13 ( & V_12 -> V_18 ) ) ;
if ( F_15 ( & V_12 -> V_46 ) > ( 1 << V_16 -> V_19 ) )
V_16 = F_59 ( V_12 , V_16 -> V_19 + 1 ) ;
V_87 = V_12 -> V_77 ( V_82 , V_35 , V_16 -> V_72 ) >> ( 32 - V_16 -> V_19 ) ;
if ( V_20 -> V_6 -> V_27 ) {
V_90 = F_71 ( - V_99 ) ;
goto V_100;
}
for ( V_89 = F_12 ( V_16 -> V_22 [ V_87 ] ,
F_13 ( & V_12 -> V_18 ) ) ;
V_89 != NULL ;
V_89 = F_12 ( V_89 -> V_26 ,
F_13 ( & V_12 -> V_18 ) ) ) {
if ( V_35 == V_89 -> V_35 && ! memcmp ( V_89 -> V_81 , V_82 , V_86 ) ) {
if ( V_88 )
F_20 ( V_89 ) ;
V_90 = V_89 ;
goto V_100;
}
}
V_20 -> V_27 = 0 ;
if ( V_88 )
F_20 ( V_20 ) ;
F_16 ( V_20 -> V_26 ,
F_12 ( V_16 -> V_22 [ V_87 ] ,
F_13 ( & V_12 -> V_18 ) ) ) ;
F_16 ( V_16 -> V_22 [ V_87 ] , V_20 ) ;
F_18 ( & V_12 -> V_18 ) ;
F_32 ( 2 , L_4 , V_20 ) ;
V_90 = V_20 ;
V_63:
return V_90 ;
V_100:
F_18 ( & V_12 -> V_18 ) ;
V_93:
F_6 ( V_20 ) ;
goto V_63;
}
static T_2 F_74 ( const void * V_82 , int V_86 )
{
T_2 V_87 = * ( T_2 * ) ( V_82 + V_86 - 4 ) ;
V_87 ^= ( V_87 >> 16 ) ;
V_87 ^= V_87 >> 8 ;
V_87 ^= V_87 >> 4 ;
V_87 &= V_101 ;
return V_87 ;
}
static struct V_102 * F_75 ( struct V_102 * V_20 ,
struct V_85 * V_85 ,
const void * V_82 ,
int V_86 ,
struct V_36 * V_35 )
{
while ( V_20 ) {
if ( ! memcmp ( V_20 -> V_103 , V_82 , V_86 ) &&
F_68 ( F_76 ( V_20 ) , V_85 ) &&
( V_20 -> V_35 == V_35 || ! V_20 -> V_35 ) )
return V_20 ;
V_20 = V_20 -> V_26 ;
}
return NULL ;
}
struct V_102 * F_77 ( struct V_11 * V_12 ,
struct V_85 * V_85 , const void * V_82 , struct V_36 * V_35 )
{
int V_86 = V_12 -> V_86 ;
T_2 V_87 = F_74 ( V_82 , V_86 ) ;
return F_75 ( V_12 -> V_104 [ V_87 ] ,
V_85 , V_82 , V_86 , V_35 ) ;
}
struct V_102 * F_78 ( struct V_11 * V_12 ,
struct V_85 * V_85 , const void * V_82 ,
struct V_36 * V_35 , int V_105 )
{
struct V_102 * V_20 ;
int V_86 = V_12 -> V_86 ;
T_2 V_87 = F_74 ( V_82 , V_86 ) ;
F_79 ( & V_12 -> V_18 ) ;
V_20 = F_75 ( V_12 -> V_104 [ V_87 ] ,
V_85 , V_82 , V_86 , V_35 ) ;
F_80 ( & V_12 -> V_18 ) ;
if ( V_20 || ! V_105 )
goto V_63;
F_81 () ;
V_20 = F_52 ( sizeof( * V_20 ) + V_86 , V_106 ) ;
if ( ! V_20 )
goto V_63;
F_82 ( & V_20 -> V_85 , V_85 ) ;
memcpy ( V_20 -> V_103 , V_82 , V_86 ) ;
V_20 -> V_35 = V_35 ;
if ( V_35 )
F_72 ( V_35 ) ;
if ( V_12 -> V_107 && V_12 -> V_107 ( V_20 ) ) {
if ( V_35 )
F_29 ( V_35 ) ;
F_55 ( V_20 ) ;
V_20 = NULL ;
goto V_63;
}
F_11 ( & V_12 -> V_18 ) ;
V_20 -> V_26 = V_12 -> V_104 [ V_87 ] ;
V_12 -> V_104 [ V_87 ] = V_20 ;
F_18 ( & V_12 -> V_18 ) ;
V_63:
return V_20 ;
}
int F_83 ( struct V_11 * V_12 , struct V_85 * V_85 , const void * V_82 ,
struct V_36 * V_35 )
{
struct V_102 * V_20 , * * V_21 ;
int V_86 = V_12 -> V_86 ;
T_2 V_87 = F_74 ( V_82 , V_86 ) ;
F_11 ( & V_12 -> V_18 ) ;
for ( V_21 = & V_12 -> V_104 [ V_87 ] ; ( V_20 = * V_21 ) != NULL ;
V_21 = & V_20 -> V_26 ) {
if ( ! memcmp ( V_20 -> V_103 , V_82 , V_86 ) && V_20 -> V_35 == V_35 &&
F_68 ( F_76 ( V_20 ) , V_85 ) ) {
* V_21 = V_20 -> V_26 ;
F_18 ( & V_12 -> V_18 ) ;
if ( V_12 -> V_108 )
V_12 -> V_108 ( V_20 ) ;
if ( V_20 -> V_35 )
F_29 ( V_20 -> V_35 ) ;
F_55 ( V_20 ) ;
return 0 ;
}
}
F_18 ( & V_12 -> V_18 ) ;
return - V_109 ;
}
static int F_35 ( struct V_11 * V_12 , struct V_36 * V_35 )
{
struct V_102 * V_20 , * * V_21 ;
T_2 V_110 ;
for ( V_110 = 0 ; V_110 <= V_101 ; V_110 ++ ) {
V_21 = & V_12 -> V_104 [ V_110 ] ;
while ( ( V_20 = * V_21 ) != NULL ) {
if ( ! V_35 || V_20 -> V_35 == V_35 ) {
* V_21 = V_20 -> V_26 ;
if ( V_12 -> V_108 )
V_12 -> V_108 ( V_20 ) ;
if ( V_20 -> V_35 )
F_29 ( V_20 -> V_35 ) ;
F_55 ( V_20 ) ;
continue;
}
V_21 = & V_20 -> V_26 ;
}
}
return - V_109 ;
}
static inline void F_84 ( struct V_111 * V_6 )
{
if ( F_85 ( & V_6 -> V_23 ) )
F_86 ( V_6 ) ;
}
void F_87 ( struct V_1 * V_2 )
{
struct V_36 * V_35 = V_2 -> V_35 ;
F_10 ( V_2 -> V_12 , V_112 ) ;
if ( ! V_2 -> V_27 ) {
F_88 ( L_5 , V_2 ) ;
F_24 () ;
return;
}
if ( F_25 ( V_2 ) )
F_88 ( L_6 ) ;
F_11 ( & V_2 -> V_18 ) ;
F_31 ( & V_2 -> V_37 ) ;
F_18 ( & V_2 -> V_18 ) ;
V_2 -> V_38 = 0 ;
if ( V_35 -> V_94 -> V_113 )
V_35 -> V_94 -> V_113 ( V_35 , V_2 ) ;
F_29 ( V_35 ) ;
F_84 ( V_2 -> V_6 ) ;
F_32 ( 2 , L_7 , V_2 ) ;
F_48 ( & V_2 -> V_12 -> V_46 ) ;
F_89 ( V_2 , V_75 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
F_32 ( 2 , L_8 , V_2 ) ;
V_2 -> V_39 = V_2 -> V_114 -> V_39 ;
}
static void F_91 ( struct V_1 * V_2 )
{
F_32 ( 2 , L_9 , V_2 ) ;
V_2 -> V_39 = V_2 -> V_114 -> V_115 ;
}
static void F_92 ( struct V_116 * V_117 )
{
struct V_11 * V_12 = F_57 ( V_117 , struct V_11 , V_118 . V_117 ) ;
struct V_1 * V_20 ;
struct V_1 T_1 * * V_21 ;
unsigned int V_14 ;
struct V_15 * V_16 ;
F_10 ( V_12 , V_119 ) ;
F_11 ( & V_12 -> V_18 ) ;
V_16 = F_12 ( V_12 -> V_16 ,
F_13 ( & V_12 -> V_18 ) ) ;
if ( F_39 ( V_29 , V_12 -> V_120 + 300 * V_49 ) ) {
struct V_111 * V_121 ;
V_12 -> V_120 = V_29 ;
F_93 (p, &tbl->parms_list, list)
V_121 -> V_122 =
F_7 ( F_73 ( V_121 , V_98 ) ) ;
}
if ( F_15 ( & V_12 -> V_46 ) < V_12 -> V_123 )
goto V_63;
for ( V_14 = 0 ; V_14 < ( 1 << V_16 -> V_19 ) ; V_14 ++ ) {
V_21 = & V_16 -> V_22 [ V_14 ] ;
while ( ( V_20 = F_12 ( * V_21 ,
F_13 ( & V_12 -> V_18 ) ) ) != NULL ) {
unsigned int V_124 ;
F_14 ( & V_20 -> V_18 ) ;
V_124 = V_20 -> V_24 ;
if ( V_124 & ( V_25 | V_32 ) ) {
F_17 ( & V_20 -> V_18 ) ;
goto V_125;
}
if ( F_94 ( V_20 -> V_58 , V_20 -> V_97 ) )
V_20 -> V_58 = V_20 -> V_97 ;
if ( F_15 ( & V_20 -> V_23 ) == 1 &&
( V_124 == V_126 ||
F_39 ( V_29 , V_20 -> V_58 + F_73 ( V_20 -> V_6 , V_127 ) ) ) ) {
* V_21 = V_20 -> V_26 ;
V_20 -> V_27 = 1 ;
F_17 ( & V_20 -> V_18 ) ;
F_3 ( V_20 ) ;
continue;
}
F_17 ( & V_20 -> V_18 ) ;
V_125:
V_21 = & V_20 -> V_26 ;
}
F_18 ( & V_12 -> V_18 ) ;
F_95 () ;
F_11 ( & V_12 -> V_18 ) ;
V_16 = F_12 ( V_12 -> V_16 ,
F_13 ( & V_12 -> V_18 ) ) ;
}
V_63:
F_96 ( V_128 , & V_12 -> V_118 ,
F_73 ( & V_12 -> V_6 , V_98 ) >> 1 ) ;
F_18 ( & V_12 -> V_18 ) ;
}
static T_4 int F_97 ( struct V_1 * V_20 )
{
struct V_111 * V_121 = V_20 -> V_6 ;
return F_73 ( V_121 , V_129 ) + F_73 ( V_121 , V_130 ) +
( V_20 -> V_24 & V_131 ? F_73 ( V_121 , V_132 ) :
F_73 ( V_121 , V_133 ) ) ;
}
static void F_98 ( struct V_1 * V_2 )
__releases( V_2 -> V_18 )
__acquires( V_2 -> V_18 )
{
struct V_3 * V_4 ;
F_10 ( V_2 -> V_12 , V_134 ) ;
F_32 ( 2 , L_10 , V_2 ) ;
V_2 -> V_57 = V_29 ;
while ( V_2 -> V_24 == V_126 &&
( V_4 = F_99 ( & V_2 -> V_37 ) ) != NULL ) {
F_17 ( & V_2 -> V_18 ) ;
V_2 -> V_114 -> V_135 ( V_2 , V_4 ) ;
F_14 ( & V_2 -> V_18 ) ;
}
F_31 ( & V_2 -> V_37 ) ;
V_2 -> V_38 = 0 ;
}
static void F_100 ( struct V_1 * V_2 )
__releases( V_2 -> V_18 )
{
struct V_3 * V_4 = F_101 ( & V_2 -> V_37 ) ;
if ( V_4 )
V_4 = F_102 ( V_4 , V_55 ) ;
F_17 ( & V_2 -> V_18 ) ;
if ( V_2 -> V_114 -> V_136 )
V_2 -> V_114 -> V_136 ( V_2 , V_4 ) ;
F_103 ( & V_2 -> V_137 ) ;
F_2 ( V_4 ) ;
}
static void V_61 ( unsigned long V_138 )
{
unsigned long V_45 , V_26 ;
struct V_1 * V_2 = (struct V_1 * ) V_138 ;
unsigned int V_124 ;
int V_139 = 0 ;
F_14 ( & V_2 -> V_18 ) ;
V_124 = V_2 -> V_24 ;
V_45 = V_29 ;
V_26 = V_45 + V_49 ;
if ( ! ( V_124 & V_32 ) )
goto V_63;
if ( V_124 & V_140 ) {
if ( F_104 ( V_45 ,
V_2 -> V_97 + V_2 -> V_6 -> V_122 ) ) {
F_32 ( 2 , L_11 , V_2 ) ;
V_26 = V_2 -> V_97 + V_2 -> V_6 -> V_122 ;
} else if ( F_104 ( V_45 ,
V_2 -> V_58 +
F_73 ( V_2 -> V_6 , V_141 ) ) ) {
F_32 ( 2 , L_12 , V_2 ) ;
V_2 -> V_24 = V_142 ;
V_2 -> V_57 = V_29 ;
F_90 ( V_2 ) ;
V_26 = V_45 + F_73 ( V_2 -> V_6 , V_141 ) ;
} else {
F_32 ( 2 , L_8 , V_2 ) ;
V_2 -> V_24 = V_143 ;
V_2 -> V_57 = V_29 ;
F_90 ( V_2 ) ;
V_139 = 1 ;
}
} else if ( V_124 & V_142 ) {
if ( F_104 ( V_45 ,
V_2 -> V_97 +
F_73 ( V_2 -> V_6 , V_141 ) ) ) {
F_32 ( 2 , L_13 , V_2 ) ;
V_2 -> V_24 = V_140 ;
V_2 -> V_57 = V_29 ;
F_91 ( V_2 ) ;
V_139 = 1 ;
V_26 = V_2 -> V_97 + V_2 -> V_6 -> V_122 ;
} else {
F_32 ( 2 , L_14 , V_2 ) ;
V_2 -> V_24 = V_131 ;
V_2 -> V_57 = V_29 ;
F_47 ( & V_2 -> V_137 , 0 ) ;
V_139 = 1 ;
V_26 = V_45 + F_73 ( V_2 -> V_6 , V_144 ) ;
}
} else {
V_26 = V_45 + F_73 ( V_2 -> V_6 , V_144 ) ;
}
if ( ( V_2 -> V_24 & ( V_145 | V_131 ) ) &&
F_15 ( & V_2 -> V_137 ) >= F_97 ( V_2 ) ) {
V_2 -> V_24 = V_126 ;
V_139 = 1 ;
F_98 ( V_2 ) ;
goto V_63;
}
if ( V_2 -> V_24 & V_32 ) {
if ( F_94 ( V_26 , V_29 + V_49 / 2 ) )
V_26 = V_29 + V_49 / 2 ;
if ( ! F_22 ( & V_2 -> V_31 , V_26 ) )
F_20 ( V_2 ) ;
}
if ( V_2 -> V_24 & ( V_145 | V_131 ) ) {
F_100 ( V_2 ) ;
} else {
V_63:
F_17 ( & V_2 -> V_18 ) ;
}
if ( V_139 )
F_105 ( V_2 ) ;
F_6 ( V_2 ) ;
}
int F_106 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_90 ;
bool V_146 = false ;
F_11 ( & V_2 -> V_18 ) ;
V_90 = 0 ;
if ( V_2 -> V_24 & ( V_147 | V_142 | V_131 ) )
goto V_148;
if ( V_2 -> V_27 )
goto V_149;
if ( ! ( V_2 -> V_24 & ( V_143 | V_145 ) ) ) {
if ( F_73 ( V_2 -> V_6 , V_133 ) +
F_73 ( V_2 -> V_6 , V_130 ) ) {
unsigned long V_26 , V_45 = V_29 ;
F_47 ( & V_2 -> V_137 ,
F_73 ( V_2 -> V_6 , V_129 ) ) ;
V_2 -> V_24 = V_145 ;
V_2 -> V_57 = V_45 ;
V_26 = V_45 + F_107 ( F_73 ( V_2 -> V_6 , V_144 ) ,
V_49 / 2 ) ;
F_19 ( V_2 , V_26 ) ;
V_146 = true ;
} else {
V_2 -> V_24 = V_126 ;
V_2 -> V_57 = V_29 ;
F_18 ( & V_2 -> V_18 ) ;
F_2 ( V_4 ) ;
return 1 ;
}
} else if ( V_2 -> V_24 & V_143 ) {
F_32 ( 2 , L_12 , V_2 ) ;
V_2 -> V_24 = V_142 ;
V_2 -> V_57 = V_29 ;
F_19 ( V_2 , V_29 +
F_73 ( V_2 -> V_6 , V_141 ) ) ;
}
if ( V_2 -> V_24 == V_145 ) {
if ( V_4 ) {
while ( V_2 -> V_38 + V_4 -> V_150 >
F_73 ( V_2 -> V_6 , V_151 ) ) {
struct V_3 * V_152 ;
V_152 = F_99 ( & V_2 -> V_37 ) ;
if ( ! V_152 )
break;
V_2 -> V_38 -= V_152 -> V_150 ;
F_2 ( V_152 ) ;
F_10 ( V_2 -> V_12 , V_153 ) ;
}
F_108 ( V_4 ) ;
F_109 ( & V_2 -> V_37 , V_4 ) ;
V_2 -> V_38 += V_4 -> V_150 ;
}
V_90 = 1 ;
}
V_148:
if ( V_146 )
F_100 ( V_2 ) ;
else
F_17 ( & V_2 -> V_18 ) ;
F_110 () ;
return V_90 ;
V_149:
if ( V_2 -> V_24 & V_143 )
goto V_148;
F_18 ( & V_2 -> V_18 ) ;
F_2 ( V_4 ) ;
return 1 ;
}
static void F_111 ( struct V_1 * V_2 )
{
struct V_154 * V_59 ;
void (* F_112)( struct V_154 * , const struct V_36 * , const unsigned char * )
= NULL ;
if ( V_2 -> V_35 -> V_155 )
F_112 = V_2 -> V_35 -> V_155 -> V_156 ;
if ( F_112 ) {
V_59 = & V_2 -> V_59 ;
if ( V_59 -> V_157 ) {
F_113 ( & V_59 -> V_60 ) ;
F_112 ( V_59 , V_2 -> V_35 , V_2 -> V_158 ) ;
F_114 ( & V_59 -> V_60 ) ;
}
}
}
int F_115 ( struct V_1 * V_2 , const T_5 * V_159 , T_5 V_160 ,
T_2 V_161 )
{
T_5 V_162 ;
int V_163 ;
int V_139 = 0 ;
struct V_36 * V_35 ;
int V_164 = 0 ;
F_11 ( & V_2 -> V_18 ) ;
V_35 = V_2 -> V_35 ;
V_162 = V_2 -> V_24 ;
V_163 = - V_165 ;
if ( ! ( V_161 & V_166 ) &&
( V_162 & ( V_41 | V_25 ) ) )
goto V_63;
if ( V_2 -> V_27 )
goto V_63;
if ( ! ( V_160 & V_40 ) ) {
F_25 ( V_2 ) ;
if ( V_162 & V_147 )
F_90 ( V_2 ) ;
V_2 -> V_24 = V_160 ;
V_163 = 0 ;
V_139 = V_162 & V_40 ;
if ( ( V_162 & ( V_145 | V_131 ) ) &&
( V_160 & V_126 ) ) {
F_98 ( V_2 ) ;
V_139 = 1 ;
}
goto V_63;
}
if ( ! V_35 -> V_167 ) {
V_159 = V_2 -> V_158 ;
} else if ( V_159 ) {
if ( ( V_162 & V_40 ) &&
! memcmp ( V_159 , V_2 -> V_158 , V_35 -> V_167 ) )
V_159 = V_2 -> V_158 ;
} else {
V_163 = - V_99 ;
if ( ! ( V_162 & V_40 ) )
goto V_63;
V_159 = V_2 -> V_158 ;
}
if ( V_160 & V_147 )
V_2 -> V_97 = V_29 ;
V_2 -> V_57 = V_29 ;
V_163 = 0 ;
V_164 = V_161 & V_168 ;
if ( V_162 & V_40 ) {
if ( V_159 != V_2 -> V_158 && ! ( V_161 & V_169 ) ) {
V_164 = 0 ;
if ( ( V_161 & V_170 ) &&
( V_162 & V_147 ) ) {
V_159 = V_2 -> V_158 ;
V_160 = V_143 ;
} else
goto V_63;
} else {
if ( V_159 == V_2 -> V_158 && V_160 == V_143 &&
! ( V_161 & V_166 ) )
V_160 = V_162 ;
}
}
if ( V_160 != V_162 ) {
F_25 ( V_2 ) ;
if ( V_160 & V_131 )
F_47 ( & V_2 -> V_137 , 0 ) ;
if ( V_160 & V_32 )
F_19 ( V_2 , ( V_29 +
( ( V_160 & V_140 ) ?
V_2 -> V_6 -> V_122 :
0 ) ) ) ;
V_2 -> V_24 = V_160 ;
V_139 = 1 ;
}
if ( V_159 != V_2 -> V_158 ) {
F_116 ( & V_2 -> V_56 ) ;
memcpy ( & V_2 -> V_158 , V_159 , V_35 -> V_167 ) ;
F_117 ( & V_2 -> V_56 ) ;
F_111 ( V_2 ) ;
if ( ! ( V_160 & V_147 ) )
V_2 -> V_97 = V_29 -
( F_73 ( V_2 -> V_6 , V_98 ) << 1 ) ;
V_139 = 1 ;
}
if ( V_160 == V_162 )
goto V_63;
if ( V_160 & V_147 )
F_91 ( V_2 ) ;
else
F_90 ( V_2 ) ;
if ( ! ( V_162 & V_40 ) ) {
struct V_3 * V_4 ;
while ( V_2 -> V_24 & V_40 &&
( V_4 = F_99 ( & V_2 -> V_37 ) ) != NULL ) {
struct V_171 * V_172 = F_118 ( V_4 ) ;
struct V_1 * V_173 , * V_89 = V_2 ;
F_18 ( & V_2 -> V_18 ) ;
F_119 () ;
V_173 = NULL ;
if ( V_172 ) {
V_173 = F_120 ( V_172 , V_4 ) ;
if ( V_173 )
V_89 = V_173 ;
}
V_89 -> V_39 ( V_89 , V_4 ) ;
if ( V_173 )
F_6 ( V_173 ) ;
F_121 () ;
F_11 ( & V_2 -> V_18 ) ;
}
F_31 ( & V_2 -> V_37 ) ;
V_2 -> V_38 = 0 ;
}
V_63:
if ( V_164 ) {
V_2 -> V_161 = ( V_161 & V_174 ) ?
( V_2 -> V_161 | V_175 ) :
( V_2 -> V_161 & ~ V_175 ) ;
}
F_18 ( & V_2 -> V_18 ) ;
if ( V_139 )
F_105 ( V_2 ) ;
return V_163 ;
}
void F_122 ( struct V_1 * V_2 )
{
if ( V_2 -> V_27 )
return;
V_2 -> V_57 = V_29 ;
if ( ! ( V_2 -> V_24 & V_126 ) )
return;
V_2 -> V_24 = V_145 ;
F_47 ( & V_2 -> V_137 , F_97 ( V_2 ) ) ;
F_19 ( V_2 ,
V_29 + F_73 ( V_2 -> V_6 , V_144 ) ) ;
}
struct V_1 * F_123 ( struct V_11 * V_12 ,
T_5 * V_159 , void * V_176 ,
struct V_36 * V_35 )
{
struct V_1 * V_2 = F_124 ( V_12 , V_176 , V_35 ,
V_159 || ! V_35 -> V_167 ) ;
if ( V_2 )
F_115 ( V_2 , V_159 , V_143 ,
V_169 ) ;
return V_2 ;
}
static void F_125 ( struct V_1 * V_20 )
{
struct V_36 * V_35 = V_20 -> V_35 ;
T_6 V_177 = V_20 -> V_12 -> V_178 ;
struct V_154 * V_59 = & V_20 -> V_59 ;
F_11 ( & V_20 -> V_18 ) ;
if ( ! V_59 -> V_157 )
V_35 -> V_155 -> V_179 ( V_20 , V_59 , V_177 ) ;
F_18 ( & V_20 -> V_18 ) ;
}
int F_126 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_90 = 0 ;
if ( ! F_127 ( V_2 , V_4 ) ) {
int V_163 ;
struct V_36 * V_35 = V_2 -> V_35 ;
unsigned int V_180 ;
if ( V_35 -> V_155 -> V_179 && ! V_2 -> V_59 . V_157 )
F_125 ( V_2 ) ;
do {
F_128 ( V_4 , F_129 ( V_4 ) ) ;
V_180 = F_130 ( & V_2 -> V_56 ) ;
V_163 = F_131 ( V_4 , V_35 , F_132 ( V_4 -> V_178 ) ,
V_2 -> V_158 , NULL , V_4 -> V_181 ) ;
} while ( F_133 ( & V_2 -> V_56 , V_180 ) );
if ( V_163 >= 0 )
V_90 = F_134 ( V_4 ) ;
else
goto V_182;
}
V_63:
return V_90 ;
V_182:
V_90 = - V_99 ;
F_2 ( V_4 ) ;
goto V_63;
}
int F_135 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_36 * V_35 = V_2 -> V_35 ;
unsigned int V_180 ;
int V_163 ;
do {
F_128 ( V_4 , F_129 ( V_4 ) ) ;
V_180 = F_130 ( & V_2 -> V_56 ) ;
V_163 = F_131 ( V_4 , V_35 , F_132 ( V_4 -> V_178 ) ,
V_2 -> V_158 , NULL , V_4 -> V_181 ) ;
} while ( F_133 ( & V_2 -> V_56 , V_180 ) );
if ( V_163 >= 0 )
V_163 = F_134 ( V_4 ) ;
else {
V_163 = - V_99 ;
F_2 ( V_4 ) ;
}
return V_163 ;
}
int F_136 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return F_134 ( V_4 ) ;
}
static void F_137 ( unsigned long V_138 )
{
struct V_11 * V_12 = (struct V_11 * ) V_138 ;
long V_183 = 0 ;
unsigned long V_45 = V_29 ;
struct V_3 * V_4 , * V_20 ;
F_138 ( & V_12 -> V_44 . V_18 ) ;
F_139 (&tbl->proxy_queue, skb, n) {
long V_184 = F_140 ( V_4 ) -> V_183 - V_45 ;
if ( V_184 <= 0 ) {
struct V_36 * V_35 = V_4 -> V_35 ;
F_141 ( V_4 , & V_12 -> V_44 ) ;
if ( V_12 -> V_185 && F_142 ( V_35 ) ) {
F_119 () ;
V_12 -> V_185 ( V_4 ) ;
F_121 () ;
} else {
F_2 ( V_4 ) ;
}
F_29 ( V_35 ) ;
} else if ( ! V_183 || V_184 < V_183 )
V_183 = V_184 ;
}
F_26 ( & V_12 -> V_43 ) ;
if ( V_183 )
F_22 ( & V_12 -> V_43 , V_29 + V_183 ) ;
F_143 ( & V_12 -> V_44 . V_18 ) ;
}
void F_144 ( struct V_11 * V_12 , struct V_111 * V_121 ,
struct V_3 * V_4 )
{
unsigned long V_45 = V_29 ;
unsigned long V_183 = V_45 + ( F_8 () %
F_73 ( V_121 , V_186 ) ) ;
if ( V_12 -> V_44 . V_187 > F_73 ( V_121 , V_188 ) ) {
F_2 ( V_4 ) ;
return;
}
F_140 ( V_4 ) -> V_183 = V_183 ;
F_140 ( V_4 ) -> V_161 |= V_189 ;
F_138 ( & V_12 -> V_44 . V_18 ) ;
if ( F_26 ( & V_12 -> V_43 ) ) {
if ( F_94 ( V_12 -> V_43 . V_190 , V_183 ) )
V_183 = V_12 -> V_43 . V_190 ;
}
F_145 ( V_4 ) ;
F_72 ( V_4 -> V_35 ) ;
F_109 ( & V_12 -> V_44 , V_4 ) ;
F_22 ( & V_12 -> V_43 , V_183 ) ;
F_143 ( & V_12 -> V_44 . V_18 ) ;
}
static inline struct V_111 * F_146 ( struct V_11 * V_12 ,
struct V_85 * V_85 , int V_191 )
{
struct V_111 * V_121 ;
F_93 (p, &tbl->parms_list, list) {
if ( ( V_121 -> V_35 && V_121 -> V_35 -> V_191 == V_191 && F_68 ( F_147 ( V_121 ) , V_85 ) ) ||
( ! V_121 -> V_35 && ! V_191 && F_68 ( V_85 , & V_192 ) ) )
return V_121 ;
}
return NULL ;
}
struct V_111 * F_148 ( struct V_36 * V_35 ,
struct V_11 * V_12 )
{
struct V_111 * V_121 ;
struct V_85 * V_85 = F_69 ( V_35 ) ;
const struct V_193 * V_114 = V_35 -> V_94 ;
V_121 = F_149 ( & V_12 -> V_6 , sizeof( * V_121 ) , V_106 ) ;
if ( V_121 ) {
V_121 -> V_12 = V_12 ;
F_47 ( & V_121 -> V_23 , 1 ) ;
V_121 -> V_122 =
F_7 ( F_73 ( V_121 , V_98 ) ) ;
F_72 ( V_35 ) ;
V_121 -> V_35 = V_35 ;
F_82 ( & V_121 -> V_85 , V_85 ) ;
V_121 -> V_194 = NULL ;
if ( V_114 -> V_195 && V_114 -> V_195 ( V_35 , V_121 ) ) {
F_29 ( V_35 ) ;
F_55 ( V_121 ) ;
return NULL ;
}
F_11 ( & V_12 -> V_18 ) ;
F_150 ( & V_121 -> V_34 , & V_12 -> V_6 . V_34 ) ;
F_18 ( & V_12 -> V_18 ) ;
F_151 ( V_121 ) ;
}
return V_121 ;
}
static void F_152 ( struct V_73 * V_74 )
{
struct V_111 * V_6 =
F_57 ( V_74 , struct V_111 , V_73 ) ;
F_84 ( V_6 ) ;
}
void F_153 ( struct V_11 * V_12 , struct V_111 * V_6 )
{
if ( ! V_6 || V_6 == & V_12 -> V_6 )
return;
F_11 ( & V_12 -> V_18 ) ;
F_154 ( & V_6 -> V_34 ) ;
V_6 -> V_27 = 1 ;
F_18 ( & V_12 -> V_18 ) ;
if ( V_6 -> V_35 )
F_29 ( V_6 -> V_35 ) ;
F_60 ( & V_6 -> V_73 , F_152 ) ;
}
static void F_86 ( struct V_111 * V_6 )
{
F_55 ( V_6 ) ;
}
void F_155 ( int V_196 , struct V_11 * V_12 )
{
unsigned long V_45 = V_29 ;
unsigned long V_197 ;
F_156 ( & V_12 -> V_198 ) ;
F_150 ( & V_12 -> V_6 . V_34 , & V_12 -> V_198 ) ;
F_82 ( & V_12 -> V_6 . V_85 , & V_192 ) ;
F_47 ( & V_12 -> V_6 . V_23 , 1 ) ;
V_12 -> V_6 . V_122 =
F_7 ( F_73 ( & V_12 -> V_6 , V_98 ) ) ;
V_12 -> V_199 = F_157 ( struct V_200 ) ;
if ( ! V_12 -> V_199 )
F_158 ( L_15 ) ;
#ifdef F_159
if ( ! F_160 ( V_12 -> V_50 , 0 , V_192 . V_201 ,
& V_202 , V_12 ) )
F_158 ( L_16 ) ;
#endif
F_161 ( V_12 -> V_16 , F_51 ( 3 ) ) ;
V_197 = ( V_101 + 1 ) * sizeof( struct V_102 * ) ;
V_12 -> V_104 = F_41 ( V_197 , V_106 ) ;
if ( ! V_12 -> V_16 || ! V_12 -> V_104 )
F_158 ( L_17 ) ;
if ( ! V_12 -> V_53 )
V_12 -> V_53 = F_162 ( F_163 ( struct V_1 , V_81 ) +
V_12 -> V_86 , V_203 ) ;
else
F_164 ( V_12 -> V_53 % V_203 ) ;
F_43 ( & V_12 -> V_18 ) ;
F_165 ( & V_12 -> V_118 , F_92 ) ;
F_96 ( V_128 , & V_12 -> V_118 ,
V_12 -> V_6 . V_122 ) ;
F_46 ( & V_12 -> V_43 , F_137 , ( unsigned long ) V_12 ) ;
F_166 ( & V_12 -> V_44 ,
& V_204 ) ;
V_12 -> V_28 = V_45 ;
V_12 -> V_120 = V_45 + V_12 -> V_6 . V_122 * 20 ;
V_205 [ V_196 ] = V_12 ;
}
int F_167 ( int V_196 , struct V_11 * V_12 )
{
V_205 [ V_196 ] = NULL ;
F_168 ( & V_12 -> V_118 ) ;
F_36 ( & V_12 -> V_43 ) ;
F_27 ( & V_12 -> V_44 ) ;
F_34 ( V_12 , NULL ) ;
if ( F_15 ( & V_12 -> V_46 ) )
F_169 ( L_18 ) ;
F_60 ( & F_12 ( V_12 -> V_16 , 1 ) -> V_75 ,
F_56 ) ;
V_12 -> V_16 = NULL ;
F_55 ( V_12 -> V_104 ) ;
V_12 -> V_104 = NULL ;
F_170 ( V_12 -> V_50 , V_192 . V_201 ) ;
F_171 ( V_12 -> V_199 ) ;
V_12 -> V_199 = NULL ;
return 0 ;
}
static struct V_11 * F_172 ( int V_206 )
{
struct V_11 * V_12 = NULL ;
switch ( V_206 ) {
case V_207 :
V_12 = V_205 [ V_208 ] ;
break;
case V_209 :
V_12 = V_205 [ V_210 ] ;
break;
case V_211 :
V_12 = V_205 [ V_212 ] ;
break;
}
return V_12 ;
}
static int F_173 ( struct V_3 * V_4 , struct V_213 * V_214 )
{
struct V_85 * V_85 = F_174 ( V_4 -> V_215 ) ;
struct V_216 * V_217 ;
struct V_218 * V_219 ;
struct V_11 * V_12 ;
struct V_1 * V_2 ;
struct V_36 * V_35 = NULL ;
int V_163 = - V_99 ;
F_81 () ;
if ( F_175 ( V_214 ) < sizeof( * V_217 ) )
goto V_63;
V_219 = F_176 ( V_214 , sizeof( * V_217 ) , V_220 ) ;
if ( V_219 == NULL )
goto V_63;
V_217 = F_177 ( V_214 ) ;
if ( V_217 -> V_221 ) {
V_35 = F_178 ( V_85 , V_217 -> V_221 ) ;
if ( V_35 == NULL ) {
V_163 = - V_222 ;
goto V_63;
}
}
V_12 = F_172 ( V_217 -> V_223 ) ;
if ( V_12 == NULL )
return - V_224 ;
if ( F_179 ( V_219 ) < V_12 -> V_86 )
goto V_63;
if ( V_217 -> V_225 & V_226 ) {
V_163 = F_83 ( V_12 , V_85 , F_180 ( V_219 ) , V_35 ) ;
goto V_63;
}
if ( V_35 == NULL )
goto V_63;
V_2 = F_61 ( V_12 , F_180 ( V_219 ) , V_35 ) ;
if ( V_2 == NULL ) {
V_163 = - V_109 ;
goto V_63;
}
V_163 = F_115 ( V_2 , NULL , V_126 ,
V_169 |
V_166 ) ;
F_6 ( V_2 ) ;
V_63:
return V_163 ;
}
static int F_181 ( struct V_3 * V_4 , struct V_213 * V_214 )
{
int V_161 = V_166 | V_169 ;
struct V_85 * V_85 = F_174 ( V_4 -> V_215 ) ;
struct V_216 * V_217 ;
struct V_218 * V_227 [ V_228 + 1 ] ;
struct V_11 * V_12 ;
struct V_36 * V_35 = NULL ;
struct V_1 * V_2 ;
void * V_172 , * V_159 ;
int V_163 ;
F_81 () ;
V_163 = F_182 ( V_214 , sizeof( * V_217 ) , V_227 , V_228 , NULL ) ;
if ( V_163 < 0 )
goto V_63;
V_163 = - V_99 ;
if ( V_227 [ V_220 ] == NULL )
goto V_63;
V_217 = F_177 ( V_214 ) ;
if ( V_217 -> V_221 ) {
V_35 = F_178 ( V_85 , V_217 -> V_221 ) ;
if ( V_35 == NULL ) {
V_163 = - V_222 ;
goto V_63;
}
if ( V_227 [ V_229 ] && F_179 ( V_227 [ V_229 ] ) < V_35 -> V_167 )
goto V_63;
}
V_12 = F_172 ( V_217 -> V_223 ) ;
if ( V_12 == NULL )
return - V_224 ;
if ( F_179 ( V_227 [ V_220 ] ) < V_12 -> V_86 )
goto V_63;
V_172 = F_180 ( V_227 [ V_220 ] ) ;
V_159 = V_227 [ V_229 ] ? F_180 ( V_227 [ V_229 ] ) : NULL ;
if ( V_217 -> V_225 & V_226 ) {
struct V_102 * V_230 ;
V_163 = - V_91 ;
V_230 = F_78 ( V_12 , V_85 , V_172 , V_35 , 1 ) ;
if ( V_230 ) {
V_230 -> V_161 = V_217 -> V_225 ;
V_163 = 0 ;
}
goto V_63;
}
if ( V_35 == NULL )
goto V_63;
V_2 = F_61 ( V_12 , V_172 , V_35 ) ;
if ( V_2 == NULL ) {
if ( ! ( V_214 -> V_231 & V_232 ) ) {
V_163 = - V_109 ;
goto V_63;
}
V_2 = F_183 ( V_12 , V_172 , V_35 ) ;
if ( F_184 ( V_2 ) ) {
V_163 = F_185 ( V_2 ) ;
goto V_63;
}
} else {
if ( V_214 -> V_231 & V_233 ) {
V_163 = - V_234 ;
F_6 ( V_2 ) ;
goto V_63;
}
if ( ! ( V_214 -> V_231 & V_235 ) )
V_161 &= ~ V_169 ;
}
if ( V_217 -> V_225 & V_236 ) {
F_127 ( V_2 , NULL ) ;
V_163 = 0 ;
} else
V_163 = F_115 ( V_2 , V_159 , V_217 -> V_237 , V_161 ) ;
F_6 ( V_2 ) ;
V_63:
return V_163 ;
}
static int F_186 ( struct V_3 * V_4 , struct V_111 * V_6 )
{
struct V_218 * V_238 ;
V_238 = F_187 ( V_4 , V_239 ) ;
if ( V_238 == NULL )
return - V_91 ;
if ( ( V_6 -> V_35 &&
F_188 ( V_4 , V_240 , V_6 -> V_35 -> V_191 ) ) ||
F_188 ( V_4 , V_241 , F_15 ( & V_6 -> V_23 ) ) ||
F_188 ( V_4 , V_242 ,
F_73 ( V_6 , V_151 ) ) ||
F_188 ( V_4 , V_243 ,
F_73 ( V_6 , V_151 ) / F_189 ( V_244 ) ) ||
F_188 ( V_4 , V_245 , F_73 ( V_6 , V_188 ) ) ||
F_188 ( V_4 , V_246 , F_73 ( V_6 , V_130 ) ) ||
F_188 ( V_4 , V_247 ,
F_73 ( V_6 , V_129 ) ) ||
F_188 ( V_4 , V_248 ,
F_73 ( V_6 , V_133 ) ) ||
F_188 ( V_4 , V_249 ,
F_73 ( V_6 , V_132 ) ) ||
F_190 ( V_4 , V_250 , V_6 -> V_122 ,
V_251 ) ||
F_190 ( V_4 , V_252 ,
F_73 ( V_6 , V_98 ) , V_251 ) ||
F_190 ( V_4 , V_253 ,
F_73 ( V_6 , V_127 ) , V_251 ) ||
F_190 ( V_4 , V_254 ,
F_73 ( V_6 , V_141 ) , V_251 ) ||
F_190 ( V_4 , V_255 ,
F_73 ( V_6 , V_144 ) , V_251 ) ||
F_190 ( V_4 , V_256 ,
F_73 ( V_6 , V_257 ) , V_251 ) ||
F_190 ( V_4 , V_258 ,
F_73 ( V_6 , V_186 ) , V_251 ) ||
F_190 ( V_4 , V_259 ,
F_73 ( V_6 , V_260 ) , V_251 ) )
goto V_261;
return F_191 ( V_4 , V_238 ) ;
V_261:
F_192 ( V_4 , V_238 ) ;
return - V_262 ;
}
static int F_193 ( struct V_3 * V_4 , struct V_11 * V_12 ,
T_2 V_263 , T_2 V_180 , int type , int V_161 )
{
struct V_213 * V_214 ;
struct V_264 * V_264 ;
V_214 = F_194 ( V_4 , V_263 , V_180 , type , sizeof( * V_264 ) , V_161 ) ;
if ( V_214 == NULL )
return - V_262 ;
V_264 = F_177 ( V_214 ) ;
F_79 ( & V_12 -> V_18 ) ;
V_264 -> V_265 = V_12 -> V_206 ;
V_264 -> V_266 = 0 ;
V_264 -> V_267 = 0 ;
if ( F_195 ( V_4 , V_268 , V_12 -> V_50 ) ||
F_190 ( V_4 , V_269 , V_12 -> V_270 , V_271 ) ||
F_188 ( V_4 , V_272 , V_12 -> V_123 ) ||
F_188 ( V_4 , V_273 , V_12 -> V_48 ) ||
F_188 ( V_4 , V_274 , V_12 -> V_47 ) )
goto V_261;
{
unsigned long V_45 = V_29 ;
unsigned int V_275 = V_45 - V_12 -> V_28 ;
unsigned int V_276 = V_45 - V_12 -> V_120 ;
struct V_15 * V_16 ;
struct V_277 V_278 = {
. V_279 = V_12 -> V_86 ,
. V_280 = V_12 -> V_53 ,
. V_281 = F_15 ( & V_12 -> V_46 ) ,
. V_282 = F_196 ( V_275 ) ,
. V_283 = F_196 ( V_276 ) ,
. V_284 = V_12 -> V_44 . V_187 ,
} ;
F_62 () ;
V_16 = F_67 ( V_12 -> V_16 ) ;
V_278 . V_285 = V_16 -> V_72 [ 0 ] ;
V_278 . V_286 = ( ( 1 << V_16 -> V_19 ) - 1 ) ;
F_65 () ;
if ( F_197 ( V_4 , V_287 , sizeof( V_278 ) , & V_278 ) )
goto V_261;
}
{
int V_288 ;
struct V_289 V_290 ;
memset ( & V_290 , 0 , sizeof( V_290 ) ) ;
F_198 (cpu) {
struct V_200 * V_291 ;
V_291 = F_199 ( V_12 -> V_199 , V_288 ) ;
V_290 . V_292 += V_291 -> V_62 ;
V_290 . V_293 += V_291 -> V_112 ;
V_290 . V_294 += V_291 -> V_80 ;
V_290 . V_295 += V_291 -> V_134 ;
V_290 . V_296 += V_291 -> V_83 ;
V_290 . V_297 += V_291 -> V_84 ;
V_290 . V_298 += V_291 -> V_299 ;
V_290 . V_300 += V_291 -> V_301 ;
V_290 . V_302 += V_291 -> V_119 ;
V_290 . V_303 += V_291 -> V_17 ;
V_290 . V_304 += V_291 -> V_51 ;
}
if ( F_200 ( V_4 , V_305 , sizeof( V_290 ) , & V_290 ,
V_271 ) )
goto V_261;
}
F_201 ( V_12 -> V_6 . V_35 ) ;
if ( F_186 ( V_4 , & V_12 -> V_6 ) < 0 )
goto V_261;
F_80 ( & V_12 -> V_18 ) ;
F_202 ( V_4 , V_214 ) ;
return 0 ;
V_261:
F_80 ( & V_12 -> V_18 ) ;
F_203 ( V_4 , V_214 ) ;
return - V_262 ;
}
static int F_204 ( struct V_3 * V_4 ,
struct V_11 * V_12 ,
struct V_111 * V_6 ,
T_2 V_263 , T_2 V_180 , int type ,
unsigned int V_161 )
{
struct V_264 * V_264 ;
struct V_213 * V_214 ;
V_214 = F_194 ( V_4 , V_263 , V_180 , type , sizeof( * V_264 ) , V_161 ) ;
if ( V_214 == NULL )
return - V_262 ;
V_264 = F_177 ( V_214 ) ;
F_79 ( & V_12 -> V_18 ) ;
V_264 -> V_265 = V_12 -> V_206 ;
V_264 -> V_266 = 0 ;
V_264 -> V_267 = 0 ;
if ( F_195 ( V_4 , V_268 , V_12 -> V_50 ) < 0 ||
F_186 ( V_4 , V_6 ) < 0 )
goto V_306;
F_80 ( & V_12 -> V_18 ) ;
F_202 ( V_4 , V_214 ) ;
return 0 ;
V_306:
F_80 ( & V_12 -> V_18 ) ;
F_203 ( V_4 , V_214 ) ;
return - V_262 ;
}
static int F_205 ( struct V_3 * V_4 , struct V_213 * V_214 )
{
struct V_85 * V_85 = F_174 ( V_4 -> V_215 ) ;
struct V_11 * V_12 ;
struct V_264 * V_264 ;
struct V_218 * V_227 [ V_307 + 1 ] ;
bool V_308 = false ;
int V_163 , V_309 ;
V_163 = F_182 ( V_214 , sizeof( * V_264 ) , V_227 , V_307 ,
V_310 ) ;
if ( V_163 < 0 )
goto V_306;
if ( V_227 [ V_268 ] == NULL ) {
V_163 = - V_99 ;
goto V_306;
}
V_264 = F_177 ( V_214 ) ;
for ( V_309 = 0 ; V_309 < V_311 ; V_309 ++ ) {
V_12 = V_205 [ V_309 ] ;
if ( ! V_12 )
continue;
if ( V_264 -> V_265 && V_12 -> V_206 != V_264 -> V_265 )
continue;
if ( F_206 ( V_227 [ V_268 ] , V_12 -> V_50 ) == 0 ) {
V_308 = true ;
break;
}
}
if ( ! V_308 )
return - V_109 ;
F_11 ( & V_12 -> V_18 ) ;
if ( V_227 [ V_239 ] ) {
struct V_218 * V_312 [ V_313 + 1 ] ;
struct V_111 * V_121 ;
int V_14 , V_191 = 0 ;
V_163 = F_207 ( V_312 , V_313 , V_227 [ V_239 ] ,
V_314 ) ;
if ( V_163 < 0 )
goto V_315;
if ( V_312 [ V_240 ] )
V_191 = F_208 ( V_312 [ V_240 ] ) ;
V_121 = F_146 ( V_12 , V_85 , V_191 ) ;
if ( V_121 == NULL ) {
V_163 = - V_109 ;
goto V_315;
}
for ( V_14 = 1 ; V_14 <= V_313 ; V_14 ++ ) {
if ( V_312 [ V_14 ] == NULL )
continue;
switch ( V_14 ) {
case V_243 :
F_209 ( V_121 , V_151 ,
F_208 ( V_312 [ V_14 ] ) *
F_189 ( V_244 ) ) ;
break;
case V_242 :
F_209 ( V_121 , V_151 ,
F_208 ( V_312 [ V_14 ] ) ) ;
break;
case V_245 :
F_209 ( V_121 , V_188 ,
F_208 ( V_312 [ V_14 ] ) ) ;
break;
case V_246 :
F_209 ( V_121 , V_130 ,
F_208 ( V_312 [ V_14 ] ) ) ;
break;
case V_247 :
F_209 ( V_121 , V_129 ,
F_208 ( V_312 [ V_14 ] ) ) ;
break;
case V_248 :
F_209 ( V_121 , V_133 ,
F_208 ( V_312 [ V_14 ] ) ) ;
break;
case V_249 :
F_209 ( V_121 , V_132 ,
F_208 ( V_312 [ V_14 ] ) ) ;
break;
case V_252 :
F_209 ( V_121 , V_98 ,
F_210 ( V_312 [ V_14 ] ) ) ;
V_121 -> V_122 =
F_7 ( F_73 ( V_121 , V_98 ) ) ;
break;
case V_253 :
F_209 ( V_121 , V_127 ,
F_210 ( V_312 [ V_14 ] ) ) ;
break;
case V_254 :
F_209 ( V_121 , V_141 ,
F_210 ( V_312 [ V_14 ] ) ) ;
F_5 ( V_316 , V_121 ) ;
break;
case V_255 :
F_209 ( V_121 , V_144 ,
F_210 ( V_312 [ V_14 ] ) ) ;
break;
case V_256 :
F_209 ( V_121 , V_257 ,
F_210 ( V_312 [ V_14 ] ) ) ;
break;
case V_258 :
F_209 ( V_121 , V_186 ,
F_210 ( V_312 [ V_14 ] ) ) ;
break;
case V_259 :
F_209 ( V_121 , V_260 ,
F_210 ( V_312 [ V_14 ] ) ) ;
break;
}
}
}
V_163 = - V_109 ;
if ( ( V_227 [ V_272 ] || V_227 [ V_273 ] ||
V_227 [ V_274 ] || V_227 [ V_269 ] ) &&
! F_68 ( V_85 , & V_192 ) )
goto V_315;
if ( V_227 [ V_272 ] )
V_12 -> V_123 = F_208 ( V_227 [ V_272 ] ) ;
if ( V_227 [ V_273 ] )
V_12 -> V_48 = F_208 ( V_227 [ V_273 ] ) ;
if ( V_227 [ V_274 ] )
V_12 -> V_47 = F_208 ( V_227 [ V_274 ] ) ;
if ( V_227 [ V_269 ] )
V_12 -> V_270 = F_210 ( V_227 [ V_269 ] ) ;
V_163 = 0 ;
V_315:
F_18 ( & V_12 -> V_18 ) ;
V_306:
return V_163 ;
}
static int F_211 ( struct V_3 * V_4 , struct V_317 * V_318 )
{
struct V_85 * V_85 = F_174 ( V_4 -> V_215 ) ;
int V_206 , V_309 , V_319 = 0 ;
int V_320 = V_318 -> args [ 0 ] ;
int V_321 = V_318 -> args [ 1 ] ;
struct V_11 * V_12 ;
V_206 = ( (struct V_322 * ) F_177 ( V_318 -> V_214 ) ) -> V_323 ;
for ( V_309 = 0 ; V_309 < V_311 ; V_309 ++ ) {
struct V_111 * V_121 ;
V_12 = V_205 [ V_309 ] ;
if ( ! V_12 )
continue;
if ( V_309 < V_320 || ( V_206 && V_12 -> V_206 != V_206 ) )
continue;
if ( F_193 ( V_4 , V_12 , F_212 ( V_318 -> V_4 ) . V_324 ,
V_318 -> V_214 -> V_325 , V_326 ,
V_327 ) < 0 )
break;
V_319 = 0 ;
V_121 = F_213 ( & V_12 -> V_6 , V_34 ) ;
F_214 (p, &tbl->parms_list, list) {
if ( ! F_68 ( F_147 ( V_121 ) , V_85 ) )
continue;
if ( V_319 < V_321 )
goto V_26;
if ( F_204 ( V_4 , V_12 , V_121 ,
F_212 ( V_318 -> V_4 ) . V_324 ,
V_318 -> V_214 -> V_325 ,
V_326 ,
V_327 ) < 0 )
goto V_63;
V_26:
V_319 ++ ;
}
V_321 = 0 ;
}
V_63:
V_318 -> args [ 0 ] = V_309 ;
V_318 -> args [ 1 ] = V_319 ;
return V_4 -> V_181 ;
}
static int F_215 ( struct V_3 * V_4 , struct V_1 * V_2 ,
T_2 V_263 , T_2 V_180 , int type , unsigned int V_161 )
{
unsigned long V_45 = V_29 ;
struct V_328 V_329 ;
struct V_213 * V_214 ;
struct V_216 * V_217 ;
V_214 = F_194 ( V_4 , V_263 , V_180 , type , sizeof( * V_217 ) , V_161 ) ;
if ( V_214 == NULL )
return - V_262 ;
V_217 = F_177 ( V_214 ) ;
V_217 -> V_223 = V_2 -> V_114 -> V_206 ;
V_217 -> V_330 = 0 ;
V_217 -> V_331 = 0 ;
V_217 -> V_225 = V_2 -> V_161 ;
V_217 -> V_332 = V_2 -> type ;
V_217 -> V_221 = V_2 -> V_35 -> V_191 ;
if ( F_197 ( V_4 , V_220 , V_2 -> V_12 -> V_86 , V_2 -> V_81 ) )
goto V_261;
F_79 ( & V_2 -> V_18 ) ;
V_217 -> V_237 = V_2 -> V_24 ;
if ( V_2 -> V_24 & V_40 ) {
char V_333 [ V_334 ] ;
F_216 ( V_333 , V_2 , V_2 -> V_35 ) ;
if ( F_197 ( V_4 , V_229 , V_2 -> V_35 -> V_167 , V_333 ) < 0 ) {
F_80 ( & V_2 -> V_18 ) ;
goto V_261;
}
}
V_329 . V_335 = F_217 ( V_45 - V_2 -> V_58 ) ;
V_329 . V_336 = F_217 ( V_45 - V_2 -> V_97 ) ;
V_329 . V_337 = F_217 ( V_45 - V_2 -> V_57 ) ;
V_329 . V_338 = F_15 ( & V_2 -> V_23 ) - 1 ;
F_80 ( & V_2 -> V_18 ) ;
if ( F_188 ( V_4 , V_339 , F_15 ( & V_2 -> V_137 ) ) ||
F_197 ( V_4 , V_340 , sizeof( V_329 ) , & V_329 ) )
goto V_261;
F_202 ( V_4 , V_214 ) ;
return 0 ;
V_261:
F_203 ( V_4 , V_214 ) ;
return - V_262 ;
}
static int F_218 ( struct V_3 * V_4 , struct V_102 * V_230 ,
T_2 V_263 , T_2 V_180 , int type , unsigned int V_161 ,
struct V_11 * V_12 )
{
struct V_213 * V_214 ;
struct V_216 * V_217 ;
V_214 = F_194 ( V_4 , V_263 , V_180 , type , sizeof( * V_217 ) , V_161 ) ;
if ( V_214 == NULL )
return - V_262 ;
V_217 = F_177 ( V_214 ) ;
V_217 -> V_223 = V_12 -> V_206 ;
V_217 -> V_330 = 0 ;
V_217 -> V_331 = 0 ;
V_217 -> V_225 = V_230 -> V_161 | V_226 ;
V_217 -> V_332 = V_341 ;
V_217 -> V_221 = V_230 -> V_35 ? V_230 -> V_35 -> V_191 : 0 ;
V_217 -> V_237 = V_42 ;
if ( F_197 ( V_4 , V_220 , V_12 -> V_86 , V_230 -> V_103 ) )
goto V_261;
F_202 ( V_4 , V_214 ) ;
return 0 ;
V_261:
F_203 ( V_4 , V_214 ) ;
return - V_262 ;
}
static void F_105 ( struct V_1 * V_2 )
{
F_5 ( V_9 , V_2 ) ;
F_4 ( V_2 , V_342 , 0 ) ;
}
static bool F_219 ( struct V_36 * V_35 , int V_343 )
{
struct V_36 * V_344 ;
if ( ! V_343 )
return false ;
V_344 = F_220 ( V_35 ) ;
if ( ! V_344 || V_344 -> V_191 != V_343 )
return true ;
return false ;
}
static bool F_221 ( struct V_36 * V_35 , int V_345 )
{
if ( V_345 && V_35 -> V_191 != V_345 )
return true ;
return false ;
}
static int F_222 ( struct V_11 * V_12 , struct V_3 * V_4 ,
struct V_317 * V_318 )
{
struct V_85 * V_85 = F_174 ( V_4 -> V_215 ) ;
const struct V_213 * V_214 = V_318 -> V_214 ;
struct V_218 * V_227 [ V_228 + 1 ] ;
struct V_1 * V_20 ;
int V_90 , V_110 , V_346 = V_318 -> args [ 1 ] ;
int V_347 , V_348 = V_347 = V_318 -> args [ 2 ] ;
struct V_15 * V_16 ;
int V_349 = 0 , V_345 = 0 ;
unsigned int V_161 = V_327 ;
int V_163 ;
V_163 = F_182 ( V_214 , sizeof( struct V_216 ) , V_227 , V_228 , NULL ) ;
if ( ! V_163 ) {
if ( V_227 [ V_350 ] )
V_345 = F_208 ( V_227 [ V_350 ] ) ;
if ( V_227 [ V_351 ] )
V_349 = F_208 ( V_227 [ V_351 ] ) ;
if ( V_345 || V_349 )
V_161 |= V_352 ;
}
F_62 () ;
V_16 = F_67 ( V_12 -> V_16 ) ;
for ( V_110 = V_346 ; V_110 < ( 1 << V_16 -> V_19 ) ; V_110 ++ ) {
if ( V_110 > V_346 )
V_348 = 0 ;
for ( V_20 = F_67 ( V_16 -> V_22 [ V_110 ] ) , V_347 = 0 ;
V_20 != NULL ;
V_20 = F_67 ( V_20 -> V_26 ) ) {
if ( V_347 < V_348 || ! F_68 ( F_69 ( V_20 -> V_35 ) , V_85 ) )
goto V_26;
if ( F_221 ( V_20 -> V_35 , V_345 ) ||
F_219 ( V_20 -> V_35 , V_349 ) )
goto V_26;
if ( F_215 ( V_4 , V_20 , F_212 ( V_318 -> V_4 ) . V_324 ,
V_318 -> V_214 -> V_325 ,
V_342 ,
V_161 ) < 0 ) {
V_90 = - 1 ;
goto V_63;
}
V_26:
V_347 ++ ;
}
}
V_90 = V_4 -> V_181 ;
V_63:
F_65 () ;
V_318 -> args [ 1 ] = V_110 ;
V_318 -> args [ 2 ] = V_347 ;
return V_90 ;
}
static int F_223 ( struct V_11 * V_12 , struct V_3 * V_4 ,
struct V_317 * V_318 )
{
struct V_102 * V_20 ;
struct V_85 * V_85 = F_174 ( V_4 -> V_215 ) ;
int V_90 , V_110 , V_346 = V_318 -> args [ 3 ] ;
int V_347 , V_348 = V_347 = V_318 -> args [ 4 ] ;
F_79 ( & V_12 -> V_18 ) ;
for ( V_110 = V_346 ; V_110 <= V_101 ; V_110 ++ ) {
if ( V_110 > V_346 )
V_348 = 0 ;
for ( V_20 = V_12 -> V_104 [ V_110 ] , V_347 = 0 ; V_20 ; V_20 = V_20 -> V_26 ) {
if ( V_347 < V_348 || F_76 ( V_20 ) != V_85 )
goto V_26;
if ( F_218 ( V_4 , V_20 , F_212 ( V_318 -> V_4 ) . V_324 ,
V_318 -> V_214 -> V_325 ,
V_342 ,
V_327 , V_12 ) < 0 ) {
F_80 ( & V_12 -> V_18 ) ;
V_90 = - 1 ;
goto V_63;
}
V_26:
V_347 ++ ;
}
}
F_80 ( & V_12 -> V_18 ) ;
V_90 = V_4 -> V_181 ;
V_63:
V_318 -> args [ 3 ] = V_110 ;
V_318 -> args [ 4 ] = V_347 ;
return V_90 ;
}
static int F_224 ( struct V_3 * V_4 , struct V_317 * V_318 )
{
struct V_11 * V_12 ;
int V_353 , V_206 , V_354 ;
int V_355 = 0 ;
int V_163 ;
V_206 = ( (struct V_322 * ) F_177 ( V_318 -> V_214 ) ) -> V_323 ;
if ( F_175 ( V_318 -> V_214 ) >= sizeof( struct V_216 ) &&
( (struct V_216 * ) F_177 ( V_318 -> V_214 ) ) -> V_225 == V_226 )
V_355 = 1 ;
V_354 = V_318 -> args [ 0 ] ;
for ( V_353 = 0 ; V_353 < V_311 ; V_353 ++ ) {
V_12 = V_205 [ V_353 ] ;
if ( ! V_12 )
continue;
if ( V_353 < V_354 || ( V_206 && V_12 -> V_206 != V_206 ) )
continue;
if ( V_353 > V_354 )
memset ( & V_318 -> args [ 1 ] , 0 , sizeof( V_318 -> args ) -
sizeof( V_318 -> args [ 0 ] ) ) ;
if ( V_355 )
V_163 = F_223 ( V_12 , V_4 , V_318 ) ;
else
V_163 = F_222 ( V_12 , V_4 , V_318 ) ;
if ( V_163 < 0 )
break;
}
V_318 -> args [ 0 ] = V_353 ;
return V_4 -> V_181 ;
}
void F_225 ( struct V_11 * V_12 , void (* V_318)( struct V_1 * , void * ) , void * V_356 )
{
int V_357 ;
struct V_15 * V_16 ;
F_62 () ;
V_16 = F_67 ( V_12 -> V_16 ) ;
F_226 ( & V_12 -> V_18 ) ;
for ( V_357 = 0 ; V_357 < ( 1 << V_16 -> V_19 ) ; V_357 ++ ) {
struct V_1 * V_20 ;
for ( V_20 = F_67 ( V_16 -> V_22 [ V_357 ] ) ;
V_20 != NULL ;
V_20 = F_67 ( V_20 -> V_26 ) )
V_318 ( V_20 , V_356 ) ;
}
F_227 ( & V_12 -> V_18 ) ;
F_65 () ;
}
void F_228 ( struct V_11 * V_12 ,
int (* V_318)( struct V_1 * ) )
{
int V_357 ;
struct V_15 * V_16 ;
V_16 = F_12 ( V_12 -> V_16 ,
F_13 ( & V_12 -> V_18 ) ) ;
for ( V_357 = 0 ; V_357 < ( 1 << V_16 -> V_19 ) ; V_357 ++ ) {
struct V_1 * V_20 ;
struct V_1 T_1 * * V_21 ;
V_21 = & V_16 -> V_22 [ V_357 ] ;
while ( ( V_20 = F_12 ( * V_21 ,
F_13 ( & V_12 -> V_18 ) ) ) != NULL ) {
int V_358 ;
F_14 ( & V_20 -> V_18 ) ;
V_358 = V_318 ( V_20 ) ;
if ( V_358 ) {
F_16 ( * V_21 ,
F_12 ( V_20 -> V_26 ,
F_13 ( & V_12 -> V_18 ) ) ) ;
V_20 -> V_27 = 1 ;
} else
V_21 = & V_20 -> V_26 ;
F_17 ( & V_20 -> V_18 ) ;
if ( V_358 )
F_3 ( V_20 ) ;
}
}
}
int F_229 ( int V_196 , struct V_36 * V_35 ,
const void * V_359 , struct V_3 * V_4 )
{
int V_163 = - V_224 ;
if ( F_230 ( V_196 < V_311 ) ) {
struct V_11 * V_12 ;
struct V_1 * V_2 ;
V_12 = V_205 [ V_196 ] ;
if ( ! V_12 )
goto V_63;
F_62 () ;
V_2 = F_63 ( V_12 , V_359 , V_35 ) ;
if ( ! V_2 )
V_2 = F_70 ( V_12 , V_359 , V_35 , false ) ;
V_163 = F_185 ( V_2 ) ;
if ( F_184 ( V_2 ) ) {
F_65 () ;
goto V_182;
}
V_163 = V_2 -> V_39 ( V_2 , V_4 ) ;
F_65 () ;
}
else if ( V_196 == V_360 ) {
V_163 = F_131 ( V_4 , V_35 , F_132 ( V_4 -> V_178 ) ,
V_359 , NULL , V_4 -> V_181 ) ;
if ( V_163 < 0 )
goto V_182;
V_163 = F_134 ( V_4 ) ;
}
V_63:
return V_163 ;
V_182:
F_2 ( V_4 ) ;
goto V_63;
}
static struct V_1 * F_231 ( struct V_361 * V_180 )
{
struct V_362 * V_124 = V_180 -> V_363 ;
struct V_85 * V_85 = F_232 ( V_180 ) ;
struct V_15 * V_16 = V_124 -> V_16 ;
struct V_1 * V_20 = NULL ;
int V_364 = V_124 -> V_364 ;
V_124 -> V_161 &= ~ V_365 ;
for ( V_364 = 0 ; V_364 < ( 1 << V_16 -> V_19 ) ; V_364 ++ ) {
V_20 = F_67 ( V_16 -> V_22 [ V_364 ] ) ;
while ( V_20 ) {
if ( ! F_68 ( F_69 ( V_20 -> V_35 ) , V_85 ) )
goto V_26;
if ( V_124 -> V_366 ) {
T_7 V_367 = 0 ;
void * V_368 ;
V_368 = V_124 -> V_366 ( V_124 , V_20 , & V_367 ) ;
if ( ! V_368 )
goto V_26;
}
if ( ! ( V_124 -> V_161 & V_369 ) )
break;
if ( V_20 -> V_24 & ~ V_41 )
break;
V_26:
V_20 = F_67 ( V_20 -> V_26 ) ;
}
if ( V_20 )
break;
}
V_124 -> V_364 = V_364 ;
return V_20 ;
}
static struct V_1 * F_233 ( struct V_361 * V_180 ,
struct V_1 * V_20 ,
T_7 * V_370 )
{
struct V_362 * V_124 = V_180 -> V_363 ;
struct V_85 * V_85 = F_232 ( V_180 ) ;
struct V_15 * V_16 = V_124 -> V_16 ;
if ( V_124 -> V_366 ) {
void * V_368 = V_124 -> V_366 ( V_124 , V_20 , V_370 ) ;
if ( V_368 )
return V_20 ;
}
V_20 = F_67 ( V_20 -> V_26 ) ;
while ( 1 ) {
while ( V_20 ) {
if ( ! F_68 ( F_69 ( V_20 -> V_35 ) , V_85 ) )
goto V_26;
if ( V_124 -> V_366 ) {
void * V_368 = V_124 -> V_366 ( V_124 , V_20 , V_370 ) ;
if ( V_368 )
return V_20 ;
goto V_26;
}
if ( ! ( V_124 -> V_161 & V_369 ) )
break;
if ( V_20 -> V_24 & ~ V_41 )
break;
V_26:
V_20 = F_67 ( V_20 -> V_26 ) ;
}
if ( V_20 )
break;
if ( ++ V_124 -> V_364 >= ( 1 << V_16 -> V_19 ) )
break;
V_20 = F_67 ( V_16 -> V_22 [ V_124 -> V_364 ] ) ;
}
if ( V_20 && V_370 )
-- ( * V_370 ) ;
return V_20 ;
}
static struct V_1 * F_234 ( struct V_361 * V_180 , T_7 * V_370 )
{
struct V_1 * V_20 = F_231 ( V_180 ) ;
if ( V_20 ) {
-- ( * V_370 ) ;
while ( * V_370 ) {
V_20 = F_233 ( V_180 , V_20 , V_370 ) ;
if ( ! V_20 )
break;
}
}
return * V_370 ? NULL : V_20 ;
}
static struct V_102 * F_235 ( struct V_361 * V_180 )
{
struct V_362 * V_124 = V_180 -> V_363 ;
struct V_85 * V_85 = F_232 ( V_180 ) ;
struct V_11 * V_12 = V_124 -> V_12 ;
struct V_102 * V_230 = NULL ;
int V_364 = V_124 -> V_364 ;
V_124 -> V_161 |= V_365 ;
for ( V_364 = 0 ; V_364 <= V_101 ; V_364 ++ ) {
V_230 = V_12 -> V_104 [ V_364 ] ;
while ( V_230 && ! F_68 ( F_76 ( V_230 ) , V_85 ) )
V_230 = V_230 -> V_26 ;
if ( V_230 )
break;
}
V_124 -> V_364 = V_364 ;
return V_230 ;
}
static struct V_102 * F_236 ( struct V_361 * V_180 ,
struct V_102 * V_230 ,
T_7 * V_370 )
{
struct V_362 * V_124 = V_180 -> V_363 ;
struct V_85 * V_85 = F_232 ( V_180 ) ;
struct V_11 * V_12 = V_124 -> V_12 ;
do {
V_230 = V_230 -> V_26 ;
} while ( V_230 && ! F_68 ( F_76 ( V_230 ) , V_85 ) );
while ( ! V_230 ) {
if ( ++ V_124 -> V_364 > V_101 )
break;
V_230 = V_12 -> V_104 [ V_124 -> V_364 ] ;
while ( V_230 && ! F_68 ( F_76 ( V_230 ) , V_85 ) )
V_230 = V_230 -> V_26 ;
if ( V_230 )
break;
}
if ( V_230 && V_370 )
-- ( * V_370 ) ;
return V_230 ;
}
static struct V_102 * F_237 ( struct V_361 * V_180 , T_7 * V_370 )
{
struct V_102 * V_230 = F_235 ( V_180 ) ;
if ( V_230 ) {
-- ( * V_370 ) ;
while ( * V_370 ) {
V_230 = F_236 ( V_180 , V_230 , V_370 ) ;
if ( ! V_230 )
break;
}
}
return * V_370 ? NULL : V_230 ;
}
static void * F_238 ( struct V_361 * V_180 , T_7 * V_370 )
{
struct V_362 * V_124 = V_180 -> V_363 ;
void * V_90 ;
T_7 V_371 = * V_370 ;
V_90 = F_234 ( V_180 , & V_371 ) ;
if ( ! V_90 && ! ( V_124 -> V_161 & V_372 ) )
V_90 = F_237 ( V_180 , & V_371 ) ;
return V_90 ;
}
void * F_239 ( struct V_361 * V_180 , T_7 * V_370 , struct V_11 * V_12 , unsigned int V_373 )
__acquires( T_8 )
{
struct V_362 * V_124 = V_180 -> V_363 ;
V_124 -> V_12 = V_12 ;
V_124 -> V_364 = 0 ;
V_124 -> V_161 = ( V_373 & ~ V_365 ) ;
F_62 () ;
V_124 -> V_16 = F_67 ( V_12 -> V_16 ) ;
return * V_370 ? F_238 ( V_180 , V_370 ) : V_374 ;
}
void * F_240 ( struct V_361 * V_180 , void * V_368 , T_7 * V_370 )
{
struct V_362 * V_124 ;
void * V_90 ;
if ( V_368 == V_374 ) {
V_90 = F_231 ( V_180 ) ;
goto V_63;
}
V_124 = V_180 -> V_363 ;
if ( ! ( V_124 -> V_161 & V_365 ) ) {
V_90 = F_233 ( V_180 , V_368 , NULL ) ;
if ( V_90 )
goto V_63;
if ( ! ( V_124 -> V_161 & V_372 ) )
V_90 = F_235 ( V_180 ) ;
} else {
F_201 ( V_124 -> V_161 & V_372 ) ;
V_90 = F_236 ( V_180 , V_368 , NULL ) ;
}
V_63:
++ ( * V_370 ) ;
return V_90 ;
}
void F_241 ( struct V_361 * V_180 , void * V_368 )
__releases( T_8 )
{
F_65 () ;
}
static void * F_242 ( struct V_361 * V_180 , T_7 * V_370 )
{
struct V_11 * V_12 = V_180 -> V_363 ;
int V_288 ;
if ( * V_370 == 0 )
return V_374 ;
for ( V_288 = * V_370 - 1 ; V_288 < V_375 ; ++ V_288 ) {
if ( ! F_243 ( V_288 ) )
continue;
* V_370 = V_288 + 1 ;
return F_199 ( V_12 -> V_199 , V_288 ) ;
}
return NULL ;
}
static void * F_244 ( struct V_361 * V_180 , void * V_368 , T_7 * V_370 )
{
struct V_11 * V_12 = V_180 -> V_363 ;
int V_288 ;
for ( V_288 = * V_370 ; V_288 < V_375 ; ++ V_288 ) {
if ( ! F_243 ( V_288 ) )
continue;
* V_370 = V_288 + 1 ;
return F_199 ( V_12 -> V_199 , V_288 ) ;
}
return NULL ;
}
static void F_245 ( struct V_361 * V_180 , void * V_368 )
{
}
static int F_246 ( struct V_361 * V_180 , void * V_368 )
{
struct V_11 * V_12 = V_180 -> V_363 ;
struct V_200 * V_291 = V_368 ;
if ( V_368 == V_374 ) {
F_247 ( V_180 , L_19 ) ;
return 0 ;
}
F_247 ( V_180 , L_20
L_21 ,
F_15 ( & V_12 -> V_46 ) ,
V_291 -> V_62 ,
V_291 -> V_112 ,
V_291 -> V_80 ,
V_291 -> V_83 ,
V_291 -> V_84 ,
V_291 -> V_134 ,
V_291 -> V_299 ,
V_291 -> V_301 ,
V_291 -> V_119 ,
V_291 -> V_17 ,
V_291 -> V_153 ,
V_291 -> V_51
) ;
return 0 ;
}
static int F_248 ( struct V_376 * V_376 , struct V_377 * V_377 )
{
int V_67 = F_249 ( V_377 , & V_378 ) ;
if ( ! V_67 ) {
struct V_361 * V_379 = V_377 -> V_380 ;
V_379 -> V_363 = F_250 ( V_376 ) ;
}
return V_67 ;
}
static inline T_3 F_251 ( void )
{
return F_252 ( sizeof( struct V_216 ) )
+ F_253 ( V_334 )
+ F_253 ( V_334 )
+ F_253 ( sizeof( struct V_328 ) )
+ F_253 ( 4 ) ;
}
static void F_4 ( struct V_1 * V_20 , int type , int V_161 )
{
struct V_85 * V_85 = F_69 ( V_20 -> V_35 ) ;
struct V_3 * V_4 ;
int V_163 = - V_91 ;
V_4 = F_254 ( F_251 () , V_55 ) ;
if ( V_4 == NULL )
goto V_306;
V_163 = F_215 ( V_4 , V_20 , 0 , 0 , type , V_161 ) ;
if ( V_163 < 0 ) {
F_164 ( V_163 == - V_262 ) ;
F_2 ( V_4 ) ;
goto V_306;
}
F_255 ( V_4 , V_85 , 0 , V_381 , NULL , V_55 ) ;
return;
V_306:
if ( V_163 < 0 )
F_256 ( V_85 , V_381 , V_163 ) ;
}
void F_257 ( struct V_1 * V_20 )
{
F_4 ( V_20 , V_382 , V_383 ) ;
}
static int F_258 ( struct V_384 * V_385 , int V_386 ,
void T_9 * V_387 , T_3 * V_388 , T_7 * V_389 )
{
int V_66 , V_67 ;
struct V_384 V_390 = * V_385 ;
V_390 . V_391 = & V_392 ;
V_390 . V_393 = & V_394 ;
V_390 . V_395 = & V_66 ;
V_66 = * ( int * ) V_385 -> V_395 / F_189 ( V_244 ) ;
V_67 = F_259 ( & V_390 , V_386 , V_387 , V_388 , V_389 ) ;
if ( V_386 && ! V_67 )
* ( int * ) V_385 -> V_395 = V_66 * F_189 ( V_244 ) ;
return V_67 ;
}
static struct V_111 * F_260 ( struct V_36 * V_35 ,
int V_206 )
{
switch ( V_206 ) {
case V_207 :
return F_261 ( V_35 ) ;
case V_209 :
return F_262 ( V_35 ) ;
}
return NULL ;
}
static void F_263 ( struct V_85 * V_85 , struct V_111 * V_121 ,
int V_196 )
{
struct V_36 * V_35 ;
int V_206 = F_264 ( V_121 ) ;
F_119 () ;
F_265 (net, dev) {
struct V_111 * V_396 =
F_260 ( V_35 , V_206 ) ;
if ( V_396 && ! F_266 ( V_196 , V_396 -> V_397 ) )
V_396 -> V_395 [ V_196 ] = V_121 -> V_395 [ V_196 ] ;
}
F_121 () ;
}
static void F_267 ( struct V_384 * V_385 , int V_386 )
{
struct V_36 * V_35 = V_385 -> V_391 ;
struct V_111 * V_121 = V_385 -> V_393 ;
struct V_85 * V_85 = F_147 ( V_121 ) ;
int V_196 = ( int * ) V_385 -> V_395 - V_121 -> V_395 ;
if ( ! V_386 )
return;
F_268 ( V_196 , V_121 -> V_397 ) ;
if ( V_196 == V_398 )
F_5 ( V_316 , V_121 ) ;
if ( ! V_35 )
F_263 ( V_85 , V_121 , V_196 ) ;
}
static int F_269 ( struct V_384 * V_385 , int V_386 ,
void T_9 * V_387 ,
T_3 * V_388 , T_7 * V_389 )
{
struct V_384 V_390 = * V_385 ;
int V_67 ;
V_390 . V_391 = & V_392 ;
V_390 . V_393 = & V_399 ;
V_67 = F_259 ( & V_390 , V_386 , V_387 , V_388 , V_389 ) ;
F_267 ( V_385 , V_386 ) ;
return V_67 ;
}
int F_270 ( struct V_384 * V_385 , int V_386 ,
void T_9 * V_387 , T_3 * V_388 , T_7 * V_389 )
{
int V_67 = F_271 ( V_385 , V_386 , V_387 , V_388 , V_389 ) ;
F_267 ( V_385 , V_386 ) ;
return V_67 ;
}
int F_272 ( struct V_384 * V_385 , int V_386 ,
void T_9 * V_387 ,
T_3 * V_388 , T_7 * V_389 )
{
int V_67 = F_273 ( V_385 , V_386 , V_387 , V_388 , V_389 ) ;
F_267 ( V_385 , V_386 ) ;
return V_67 ;
}
static int F_274 ( struct V_384 * V_385 , int V_386 ,
void T_9 * V_387 ,
T_3 * V_388 , T_7 * V_389 )
{
int V_67 = F_275 ( V_385 , V_386 , V_387 , V_388 , V_389 ) ;
F_267 ( V_385 , V_386 ) ;
return V_67 ;
}
int F_276 ( struct V_384 * V_385 , int V_386 ,
void T_9 * V_387 ,
T_3 * V_388 , T_7 * V_389 )
{
int V_67 = F_277 ( V_385 , V_386 , V_387 , V_388 , V_389 ) ;
F_267 ( V_385 , V_386 ) ;
return V_67 ;
}
static int F_278 ( struct V_384 * V_385 , int V_386 ,
void T_9 * V_387 ,
T_3 * V_388 , T_7 * V_389 )
{
int V_67 = F_258 ( V_385 , V_386 , V_387 , V_388 , V_389 ) ;
F_267 ( V_385 , V_386 ) ;
return V_67 ;
}
static int F_279 ( struct V_384 * V_385 , int V_386 ,
void T_9 * V_387 ,
T_3 * V_388 , T_7 * V_389 )
{
struct V_111 * V_121 = V_385 -> V_393 ;
int V_67 ;
if ( strcmp ( V_385 -> V_400 , L_22 ) == 0 )
V_67 = F_272 ( V_385 , V_386 , V_387 , V_388 , V_389 ) ;
else if ( strcmp ( V_385 -> V_400 , L_23 ) == 0 )
V_67 = F_276 ( V_385 , V_386 , V_387 , V_388 , V_389 ) ;
else
V_67 = - 1 ;
if ( V_386 && V_67 == 0 ) {
V_121 -> V_122 =
F_7 ( F_73 ( V_121 , V_98 ) ) ;
}
return V_67 ;
}
int F_280 ( struct V_36 * V_35 , struct V_111 * V_121 ,
T_10 * V_401 )
{
int V_14 ;
struct V_402 * V_353 ;
const char * V_403 ;
char V_404 [ sizeof( L_24 ) + V_405 + V_405 ] ;
char * V_406 ;
V_353 = F_149 ( & V_407 , sizeof( * V_353 ) , V_106 ) ;
if ( ! V_353 )
goto V_163;
for ( V_14 = 0 ; V_14 < V_408 ; V_14 ++ ) {
V_353 -> V_409 [ V_14 ] . V_395 += ( long ) V_121 ;
V_353 -> V_409 [ V_14 ] . V_391 = V_35 ;
V_353 -> V_409 [ V_14 ] . V_393 = V_121 ;
}
if ( V_35 ) {
V_403 = V_35 -> V_410 ;
memset ( & V_353 -> V_409 [ V_408 ] , 0 ,
sizeof( V_353 -> V_409 [ V_408 ] ) ) ;
} else {
struct V_11 * V_12 = V_121 -> V_12 ;
V_403 = L_25 ;
V_353 -> V_409 [ V_408 ] . V_395 = & V_12 -> V_270 ;
V_353 -> V_409 [ V_411 ] . V_395 = & V_12 -> V_123 ;
V_353 -> V_409 [ V_412 ] . V_395 = & V_12 -> V_48 ;
V_353 -> V_409 [ V_413 ] . V_395 = & V_12 -> V_47 ;
}
if ( V_401 ) {
V_353 -> V_409 [ V_414 ] . T_10 = V_401 ;
V_353 -> V_409 [ V_415 ] . T_10 = V_401 ;
V_353 -> V_409 [ V_416 ] . T_10 = V_401 ;
V_353 -> V_409 [ V_417 ] . T_10 = V_401 ;
} else {
V_353 -> V_409 [ V_415 ] . T_10 =
F_279 ;
V_353 -> V_409 [ V_417 ] . T_10 =
F_279 ;
}
if ( F_147 ( V_121 ) -> V_418 != & V_419 )
V_353 -> V_409 [ 0 ] . V_400 = NULL ;
switch ( F_264 ( V_121 ) ) {
case V_207 :
V_406 = L_26 ;
break;
case V_209 :
V_406 = L_27 ;
break;
default:
F_281 () ;
}
snprintf ( V_404 , sizeof( V_404 ) , L_28 ,
V_406 , V_403 ) ;
V_353 -> V_420 =
F_282 ( F_147 ( V_121 ) , V_404 , V_353 -> V_409 ) ;
if ( ! V_353 -> V_420 )
goto free;
V_121 -> V_194 = V_353 ;
return 0 ;
free:
F_55 ( V_353 ) ;
V_163:
return - V_91 ;
}
void F_283 ( struct V_111 * V_121 )
{
if ( V_121 -> V_194 ) {
struct V_402 * V_353 = V_121 -> V_194 ;
V_121 -> V_194 = NULL ;
F_284 ( V_353 -> V_420 ) ;
F_55 ( V_353 ) ;
}
}
static int T_11 F_285 ( void )
{
F_286 ( V_421 , V_342 , F_181 , NULL , NULL ) ;
F_286 ( V_421 , V_8 , F_173 , NULL , NULL ) ;
F_286 ( V_421 , V_382 , NULL , F_224 , NULL ) ;
F_286 ( V_421 , V_422 , NULL , F_211 ,
NULL ) ;
F_286 ( V_421 , V_423 , F_205 , NULL , NULL ) ;
return 0 ;
}
