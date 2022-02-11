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
F_5 ( V_2 ) ;
}
unsigned long F_6 ( unsigned long V_9 )
{
return V_9 ? ( F_7 () % V_9 ) + ( V_9 >> 1 ) : 0 ;
}
static int F_8 ( struct V_10 * V_11 )
{
int V_12 = 0 ;
int V_13 ;
struct V_14 * V_15 ;
F_9 ( V_11 , V_16 ) ;
F_10 ( & V_11 -> V_17 ) ;
V_15 = F_11 ( V_11 -> V_15 ,
F_12 ( & V_11 -> V_17 ) ) ;
for ( V_13 = 0 ; V_13 < ( 1 << V_15 -> V_18 ) ; V_13 ++ ) {
struct V_1 * V_19 ;
struct V_1 T_1 * * V_20 ;
V_20 = & V_15 -> V_21 [ V_13 ] ;
while ( ( V_19 = F_11 ( * V_20 ,
F_12 ( & V_11 -> V_17 ) ) ) != NULL ) {
F_13 ( & V_19 -> V_17 ) ;
if ( F_14 ( & V_19 -> V_22 ) == 1 &&
! ( V_19 -> V_23 & V_24 ) ) {
F_15 ( * V_20 ,
F_11 ( V_19 -> V_25 ,
F_12 ( & V_11 -> V_17 ) ) ) ;
V_19 -> V_26 = 1 ;
V_12 = 1 ;
F_16 ( & V_19 -> V_17 ) ;
F_3 ( V_19 ) ;
continue;
}
F_16 ( & V_19 -> V_17 ) ;
V_20 = & V_19 -> V_25 ;
}
}
V_11 -> V_27 = V_28 ;
F_17 ( & V_11 -> V_17 ) ;
return V_12 ;
}
static void F_18 ( struct V_1 * V_19 , unsigned long V_29 )
{
F_19 ( V_19 ) ;
if ( F_20 ( F_21 ( & V_19 -> V_30 , V_29 ) ) ) {
F_22 ( L_1 ,
V_19 -> V_23 ) ;
F_23 () ;
}
}
static int F_24 ( struct V_1 * V_19 )
{
if ( ( V_19 -> V_23 & V_31 ) &&
F_25 ( & V_19 -> V_30 ) ) {
F_5 ( V_19 ) ;
return 1 ;
}
return 0 ;
}
static void F_26 ( struct V_32 * V_33 )
{
struct V_3 * V_4 ;
while ( ( V_4 = F_27 ( V_33 ) ) != NULL ) {
F_28 ( V_4 -> V_34 ) ;
F_2 ( V_4 ) ;
}
}
static void F_29 ( struct V_10 * V_11 , struct V_35 * V_34 )
{
int V_13 ;
struct V_14 * V_15 ;
V_15 = F_11 ( V_11 -> V_15 ,
F_12 ( & V_11 -> V_17 ) ) ;
for ( V_13 = 0 ; V_13 < ( 1 << V_15 -> V_18 ) ; V_13 ++ ) {
struct V_1 * V_19 ;
struct V_1 T_1 * * V_20 = & V_15 -> V_21 [ V_13 ] ;
while ( ( V_19 = F_11 ( * V_20 ,
F_12 ( & V_11 -> V_17 ) ) ) != NULL ) {
if ( V_34 && V_19 -> V_34 != V_34 ) {
V_20 = & V_19 -> V_25 ;
continue;
}
F_15 ( * V_20 ,
F_11 ( V_19 -> V_25 ,
F_12 ( & V_11 -> V_17 ) ) ) ;
F_13 ( & V_19 -> V_17 ) ;
F_24 ( V_19 ) ;
V_19 -> V_26 = 1 ;
if ( F_14 ( & V_19 -> V_22 ) != 1 ) {
F_30 ( & V_19 -> V_36 ) ;
V_19 -> V_37 = 0 ;
V_19 -> V_38 = F_1 ;
if ( V_19 -> V_23 & V_39 )
V_19 -> V_23 = V_40 ;
else
V_19 -> V_23 = V_41 ;
F_31 ( 2 , L_2 , V_19 ) ;
}
F_16 ( & V_19 -> V_17 ) ;
F_3 ( V_19 ) ;
}
}
}
void F_32 ( struct V_10 * V_11 , struct V_35 * V_34 )
{
F_10 ( & V_11 -> V_17 ) ;
F_29 ( V_11 , V_34 ) ;
F_17 ( & V_11 -> V_17 ) ;
}
int F_33 ( struct V_10 * V_11 , struct V_35 * V_34 )
{
F_10 ( & V_11 -> V_17 ) ;
F_29 ( V_11 , V_34 ) ;
F_34 ( V_11 , V_34 ) ;
F_17 ( & V_11 -> V_17 ) ;
F_35 ( & V_11 -> V_42 ) ;
F_26 ( & V_11 -> V_43 ) ;
return 0 ;
}
static struct V_1 * F_36 ( struct V_10 * V_11 , struct V_35 * V_34 )
{
struct V_1 * V_19 = NULL ;
unsigned long V_44 = V_28 ;
int V_45 ;
V_45 = F_37 ( & V_11 -> V_45 ) - 1 ;
if ( V_45 >= V_11 -> V_46 ||
( V_45 >= V_11 -> V_47 &&
F_38 ( V_44 , V_11 -> V_27 + 5 * V_48 ) ) ) {
if ( ! F_8 ( V_11 ) &&
V_45 >= V_11 -> V_46 )
goto V_49;
}
V_19 = F_39 ( V_11 -> V_50 + V_34 -> V_51 , V_52 ) ;
if ( ! V_19 )
goto V_49;
F_40 ( & V_19 -> V_36 ) ;
F_41 ( & V_19 -> V_17 ) ;
F_42 ( & V_19 -> V_53 ) ;
V_19 -> V_54 = V_19 -> V_55 = V_44 ;
V_19 -> V_23 = V_41 ;
V_19 -> V_38 = F_1 ;
F_42 ( & V_19 -> V_56 . V_57 ) ;
V_19 -> V_6 = F_43 ( & V_11 -> V_6 ) ;
F_44 ( & V_19 -> V_30 , V_58 , ( unsigned long ) V_19 ) ;
F_9 ( V_11 , V_59 ) ;
V_19 -> V_11 = V_11 ;
F_45 ( & V_19 -> V_22 , 1 ) ;
V_19 -> V_26 = 1 ;
V_60:
return V_19 ;
V_49:
F_46 ( & V_11 -> V_45 ) ;
goto V_60;
}
static void F_47 ( T_2 * V_61 )
{
F_48 ( V_61 , sizeof( * V_61 ) ) ;
* V_61 |= 1 ;
}
static struct V_14 * F_49 ( unsigned int V_62 )
{
T_3 V_63 = ( 1 << V_62 ) * sizeof( struct V_1 * ) ;
struct V_14 * V_64 ;
struct V_1 T_1 * * V_65 ;
int V_13 ;
V_64 = F_50 ( sizeof( * V_64 ) , V_52 ) ;
if ( ! V_64 )
return NULL ;
if ( V_63 <= V_66 )
V_65 = F_39 ( V_63 , V_52 ) ;
else
V_65 = (struct V_1 T_1 * * )
F_51 ( V_52 | V_67 ,
F_52 ( V_63 ) ) ;
if ( ! V_65 ) {
F_53 ( V_64 ) ;
return NULL ;
}
V_64 -> V_21 = V_65 ;
V_64 -> V_18 = V_62 ;
for ( V_13 = 0 ; V_13 < V_68 ; V_13 ++ )
F_47 ( & V_64 -> V_69 [ V_13 ] ) ;
return V_64 ;
}
static void F_54 ( struct V_70 * V_71 )
{
struct V_14 * V_15 = F_55 ( V_71 ,
struct V_14 ,
V_72 ) ;
T_3 V_63 = ( 1 << V_15 -> V_18 ) * sizeof( struct V_1 * ) ;
struct V_1 T_1 * * V_65 = V_15 -> V_21 ;
if ( V_63 <= V_66 )
F_53 ( V_65 ) ;
else
F_56 ( ( unsigned long ) V_65 , F_52 ( V_63 ) ) ;
F_53 ( V_15 ) ;
}
static struct V_14 * F_57 ( struct V_10 * V_11 ,
unsigned long V_73 )
{
unsigned int V_13 , V_74 ;
struct V_14 * V_75 , * V_76 ;
F_9 ( V_11 , V_77 ) ;
V_76 = F_11 ( V_11 -> V_15 ,
F_12 ( & V_11 -> V_17 ) ) ;
V_75 = F_49 ( V_73 ) ;
if ( ! V_75 )
return V_76 ;
for ( V_13 = 0 ; V_13 < ( 1 << V_76 -> V_18 ) ; V_13 ++ ) {
struct V_1 * V_19 , * V_25 ;
for ( V_19 = F_11 ( V_76 -> V_21 [ V_13 ] ,
F_12 ( & V_11 -> V_17 ) ) ;
V_19 != NULL ;
V_19 = V_25 ) {
V_74 = V_11 -> V_74 ( V_19 -> V_78 , V_19 -> V_34 ,
V_75 -> V_69 ) ;
V_74 >>= ( 32 - V_75 -> V_18 ) ;
V_25 = F_11 ( V_19 -> V_25 ,
F_12 ( & V_11 -> V_17 ) ) ;
F_15 ( V_19 -> V_25 ,
F_11 (
V_75 -> V_21 [ V_74 ] ,
F_12 ( & V_11 -> V_17 ) ) ) ;
F_15 ( V_75 -> V_21 [ V_74 ] , V_19 ) ;
}
}
F_15 ( V_11 -> V_15 , V_75 ) ;
F_58 ( & V_76 -> V_72 , F_54 ) ;
return V_75 ;
}
struct V_1 * F_59 ( struct V_10 * V_11 , const void * V_79 ,
struct V_35 * V_34 )
{
struct V_1 * V_19 ;
F_9 ( V_11 , V_80 ) ;
F_60 () ;
V_19 = F_61 ( V_11 , V_79 , V_34 ) ;
if ( V_19 ) {
if ( ! F_62 ( & V_19 -> V_22 ) )
V_19 = NULL ;
F_9 ( V_11 , V_81 ) ;
}
F_63 () ;
return V_19 ;
}
struct V_1 * F_64 ( struct V_10 * V_11 , struct V_82 * V_82 ,
const void * V_79 )
{
struct V_1 * V_19 ;
int V_83 = V_11 -> V_83 ;
T_2 V_84 ;
struct V_14 * V_15 ;
F_9 ( V_11 , V_80 ) ;
F_60 () ;
V_15 = F_65 ( V_11 -> V_15 ) ;
V_84 = V_11 -> V_74 ( V_79 , NULL , V_15 -> V_69 ) >> ( 32 - V_15 -> V_18 ) ;
for ( V_19 = F_65 ( V_15 -> V_21 [ V_84 ] ) ;
V_19 != NULL ;
V_19 = F_65 ( V_19 -> V_25 ) ) {
if ( ! memcmp ( V_19 -> V_78 , V_79 , V_83 ) &&
F_66 ( F_67 ( V_19 -> V_34 ) , V_82 ) ) {
if ( ! F_62 ( & V_19 -> V_22 ) )
V_19 = NULL ;
F_9 ( V_11 , V_81 ) ;
break;
}
}
F_63 () ;
return V_19 ;
}
struct V_1 * F_68 ( struct V_10 * V_11 , const void * V_79 ,
struct V_35 * V_34 , bool V_85 )
{
T_2 V_84 ;
int V_83 = V_11 -> V_83 ;
int error ;
struct V_1 * V_86 , * V_87 , * V_19 = F_36 ( V_11 , V_34 ) ;
struct V_14 * V_15 ;
if ( ! V_19 ) {
V_87 = F_69 ( - V_88 ) ;
goto V_60;
}
memcpy ( V_19 -> V_78 , V_79 , V_83 ) ;
V_19 -> V_34 = V_34 ;
F_70 ( V_34 ) ;
if ( V_11 -> V_89 && ( error = V_11 -> V_89 ( V_19 ) ) < 0 ) {
V_87 = F_69 ( error ) ;
goto V_90;
}
if ( V_34 -> V_91 -> V_92 ) {
error = V_34 -> V_91 -> V_92 ( V_19 ) ;
if ( error < 0 ) {
V_87 = F_69 ( error ) ;
goto V_90;
}
}
if ( V_19 -> V_6 -> V_93 &&
( error = V_19 -> V_6 -> V_93 ( V_19 ) ) < 0 ) {
V_87 = F_69 ( error ) ;
goto V_90;
}
V_19 -> V_94 = V_28 - ( F_71 ( V_19 -> V_6 , V_95 ) << 1 ) ;
F_10 ( & V_11 -> V_17 ) ;
V_15 = F_11 ( V_11 -> V_15 ,
F_12 ( & V_11 -> V_17 ) ) ;
if ( F_14 ( & V_11 -> V_45 ) > ( 1 << V_15 -> V_18 ) )
V_15 = F_57 ( V_11 , V_15 -> V_18 + 1 ) ;
V_84 = V_11 -> V_74 ( V_79 , V_34 , V_15 -> V_69 ) >> ( 32 - V_15 -> V_18 ) ;
if ( V_19 -> V_6 -> V_26 ) {
V_87 = F_69 ( - V_96 ) ;
goto V_97;
}
for ( V_86 = F_11 ( V_15 -> V_21 [ V_84 ] ,
F_12 ( & V_11 -> V_17 ) ) ;
V_86 != NULL ;
V_86 = F_11 ( V_86 -> V_25 ,
F_12 ( & V_11 -> V_17 ) ) ) {
if ( V_34 == V_86 -> V_34 && ! memcmp ( V_86 -> V_78 , V_79 , V_83 ) ) {
if ( V_85 )
F_19 ( V_86 ) ;
V_87 = V_86 ;
goto V_97;
}
}
V_19 -> V_26 = 0 ;
if ( V_85 )
F_19 ( V_19 ) ;
F_15 ( V_19 -> V_25 ,
F_11 ( V_15 -> V_21 [ V_84 ] ,
F_12 ( & V_11 -> V_17 ) ) ) ;
F_15 ( V_15 -> V_21 [ V_84 ] , V_19 ) ;
F_17 ( & V_11 -> V_17 ) ;
F_31 ( 2 , L_3 , V_19 ) ;
V_87 = V_19 ;
V_60:
return V_87 ;
V_97:
F_17 ( & V_11 -> V_17 ) ;
V_90:
F_5 ( V_19 ) ;
goto V_60;
}
static T_2 F_72 ( const void * V_79 , int V_83 )
{
T_2 V_84 = * ( T_2 * ) ( V_79 + V_83 - 4 ) ;
V_84 ^= ( V_84 >> 16 ) ;
V_84 ^= V_84 >> 8 ;
V_84 ^= V_84 >> 4 ;
V_84 &= V_98 ;
return V_84 ;
}
static struct V_99 * F_73 ( struct V_99 * V_19 ,
struct V_82 * V_82 ,
const void * V_79 ,
int V_83 ,
struct V_35 * V_34 )
{
while ( V_19 ) {
if ( ! memcmp ( V_19 -> V_100 , V_79 , V_83 ) &&
F_66 ( F_74 ( V_19 ) , V_82 ) &&
( V_19 -> V_34 == V_34 || ! V_19 -> V_34 ) )
return V_19 ;
V_19 = V_19 -> V_25 ;
}
return NULL ;
}
struct V_99 * F_75 ( struct V_10 * V_11 ,
struct V_82 * V_82 , const void * V_79 , struct V_35 * V_34 )
{
int V_83 = V_11 -> V_83 ;
T_2 V_84 = F_72 ( V_79 , V_83 ) ;
return F_73 ( V_11 -> V_101 [ V_84 ] ,
V_82 , V_79 , V_83 , V_34 ) ;
}
struct V_99 * F_76 ( struct V_10 * V_11 ,
struct V_82 * V_82 , const void * V_79 ,
struct V_35 * V_34 , int V_102 )
{
struct V_99 * V_19 ;
int V_83 = V_11 -> V_83 ;
T_2 V_84 = F_72 ( V_79 , V_83 ) ;
F_77 ( & V_11 -> V_17 ) ;
V_19 = F_73 ( V_11 -> V_101 [ V_84 ] ,
V_82 , V_79 , V_83 , V_34 ) ;
F_78 ( & V_11 -> V_17 ) ;
if ( V_19 || ! V_102 )
goto V_60;
F_79 () ;
V_19 = F_50 ( sizeof( * V_19 ) + V_83 , V_103 ) ;
if ( ! V_19 )
goto V_60;
F_80 ( & V_19 -> V_82 , V_82 ) ;
memcpy ( V_19 -> V_100 , V_79 , V_83 ) ;
V_19 -> V_34 = V_34 ;
if ( V_34 )
F_70 ( V_34 ) ;
if ( V_11 -> V_104 && V_11 -> V_104 ( V_19 ) ) {
if ( V_34 )
F_28 ( V_34 ) ;
F_53 ( V_19 ) ;
V_19 = NULL ;
goto V_60;
}
F_10 ( & V_11 -> V_17 ) ;
V_19 -> V_25 = V_11 -> V_101 [ V_84 ] ;
V_11 -> V_101 [ V_84 ] = V_19 ;
F_17 ( & V_11 -> V_17 ) ;
V_60:
return V_19 ;
}
int F_81 ( struct V_10 * V_11 , struct V_82 * V_82 , const void * V_79 ,
struct V_35 * V_34 )
{
struct V_99 * V_19 , * * V_20 ;
int V_83 = V_11 -> V_83 ;
T_2 V_84 = F_72 ( V_79 , V_83 ) ;
F_10 ( & V_11 -> V_17 ) ;
for ( V_20 = & V_11 -> V_101 [ V_84 ] ; ( V_19 = * V_20 ) != NULL ;
V_20 = & V_19 -> V_25 ) {
if ( ! memcmp ( V_19 -> V_100 , V_79 , V_83 ) && V_19 -> V_34 == V_34 &&
F_66 ( F_74 ( V_19 ) , V_82 ) ) {
* V_20 = V_19 -> V_25 ;
F_17 ( & V_11 -> V_17 ) ;
if ( V_11 -> V_105 )
V_11 -> V_105 ( V_19 ) ;
if ( V_19 -> V_34 )
F_28 ( V_19 -> V_34 ) ;
F_53 ( V_19 ) ;
return 0 ;
}
}
F_17 ( & V_11 -> V_17 ) ;
return - V_106 ;
}
static int F_34 ( struct V_10 * V_11 , struct V_35 * V_34 )
{
struct V_99 * V_19 , * * V_20 ;
T_2 V_107 ;
for ( V_107 = 0 ; V_107 <= V_98 ; V_107 ++ ) {
V_20 = & V_11 -> V_101 [ V_107 ] ;
while ( ( V_19 = * V_20 ) != NULL ) {
if ( ! V_34 || V_19 -> V_34 == V_34 ) {
* V_20 = V_19 -> V_25 ;
if ( V_11 -> V_105 )
V_11 -> V_105 ( V_19 ) ;
if ( V_19 -> V_34 )
F_28 ( V_19 -> V_34 ) ;
F_53 ( V_19 ) ;
continue;
}
V_20 = & V_19 -> V_25 ;
}
}
return - V_106 ;
}
static inline void F_82 ( struct V_108 * V_6 )
{
if ( F_83 ( & V_6 -> V_22 ) )
F_84 ( V_6 ) ;
}
void F_85 ( struct V_1 * V_2 )
{
struct V_35 * V_34 = V_2 -> V_34 ;
F_9 ( V_2 -> V_11 , V_109 ) ;
if ( ! V_2 -> V_26 ) {
F_86 ( L_4 , V_2 ) ;
F_23 () ;
return;
}
if ( F_24 ( V_2 ) )
F_86 ( L_5 ) ;
F_10 ( & V_2 -> V_17 ) ;
F_30 ( & V_2 -> V_36 ) ;
F_17 ( & V_2 -> V_17 ) ;
V_2 -> V_37 = 0 ;
if ( V_34 -> V_91 -> V_110 )
V_34 -> V_91 -> V_110 ( V_2 ) ;
F_28 ( V_34 ) ;
F_82 ( V_2 -> V_6 ) ;
F_31 ( 2 , L_6 , V_2 ) ;
F_46 ( & V_2 -> V_11 -> V_45 ) ;
F_87 ( V_2 , V_72 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
F_31 ( 2 , L_7 , V_2 ) ;
V_2 -> V_38 = V_2 -> V_111 -> V_38 ;
}
static void F_89 ( struct V_1 * V_2 )
{
F_31 ( 2 , L_8 , V_2 ) ;
V_2 -> V_38 = V_2 -> V_111 -> V_112 ;
}
static void F_90 ( struct V_113 * V_114 )
{
struct V_10 * V_11 = F_55 ( V_114 , struct V_10 , V_115 . V_114 ) ;
struct V_1 * V_19 ;
struct V_1 T_1 * * V_20 ;
unsigned int V_13 ;
struct V_14 * V_15 ;
F_9 ( V_11 , V_116 ) ;
F_10 ( & V_11 -> V_17 ) ;
V_15 = F_11 ( V_11 -> V_15 ,
F_12 ( & V_11 -> V_17 ) ) ;
if ( F_38 ( V_28 , V_11 -> V_117 + 300 * V_48 ) ) {
struct V_108 * V_118 ;
V_11 -> V_117 = V_28 ;
F_91 (p, &tbl->parms_list, list)
V_118 -> V_119 =
F_6 ( F_71 ( V_118 , V_95 ) ) ;
}
if ( F_14 ( & V_11 -> V_45 ) < V_11 -> V_120 )
goto V_60;
for ( V_13 = 0 ; V_13 < ( 1 << V_15 -> V_18 ) ; V_13 ++ ) {
V_20 = & V_15 -> V_21 [ V_13 ] ;
while ( ( V_19 = F_11 ( * V_20 ,
F_12 ( & V_11 -> V_17 ) ) ) != NULL ) {
unsigned int V_121 ;
F_13 ( & V_19 -> V_17 ) ;
V_121 = V_19 -> V_23 ;
if ( V_121 & ( V_24 | V_31 ) ) {
F_16 ( & V_19 -> V_17 ) ;
goto V_122;
}
if ( F_92 ( V_19 -> V_55 , V_19 -> V_94 ) )
V_19 -> V_55 = V_19 -> V_94 ;
if ( F_14 ( & V_19 -> V_22 ) == 1 &&
( V_121 == V_123 ||
F_38 ( V_28 , V_19 -> V_55 + F_71 ( V_19 -> V_6 , V_124 ) ) ) ) {
* V_20 = V_19 -> V_25 ;
V_19 -> V_26 = 1 ;
F_16 ( & V_19 -> V_17 ) ;
F_3 ( V_19 ) ;
continue;
}
F_16 ( & V_19 -> V_17 ) ;
V_122:
V_20 = & V_19 -> V_25 ;
}
F_17 ( & V_11 -> V_17 ) ;
F_93 () ;
F_10 ( & V_11 -> V_17 ) ;
V_15 = F_11 ( V_11 -> V_15 ,
F_12 ( & V_11 -> V_17 ) ) ;
}
V_60:
F_94 ( V_125 , & V_11 -> V_115 ,
F_71 ( & V_11 -> V_6 , V_95 ) >> 1 ) ;
F_17 ( & V_11 -> V_17 ) ;
}
static T_4 int F_95 ( struct V_1 * V_19 )
{
struct V_108 * V_118 = V_19 -> V_6 ;
return F_71 ( V_118 , V_126 ) + F_71 ( V_118 , V_127 ) +
( V_19 -> V_23 & V_128 ? F_71 ( V_118 , V_129 ) :
F_71 ( V_118 , V_130 ) ) ;
}
static void F_96 ( struct V_1 * V_2 )
__releases( V_2 -> V_17 )
__acquires( V_2 -> V_17 )
{
struct V_3 * V_4 ;
F_9 ( V_2 -> V_11 , V_131 ) ;
F_31 ( 2 , L_9 , V_2 ) ;
V_2 -> V_54 = V_28 ;
while ( V_2 -> V_23 == V_123 &&
( V_4 = F_97 ( & V_2 -> V_36 ) ) != NULL ) {
F_16 ( & V_2 -> V_17 ) ;
V_2 -> V_111 -> V_132 ( V_2 , V_4 ) ;
F_13 ( & V_2 -> V_17 ) ;
}
F_30 ( & V_2 -> V_36 ) ;
V_2 -> V_37 = 0 ;
}
static void F_98 ( struct V_1 * V_2 )
__releases( V_2 -> V_17 )
{
struct V_3 * V_4 = F_99 ( & V_2 -> V_36 ) ;
if ( V_4 )
V_4 = F_100 ( V_4 , V_52 ) ;
F_16 ( & V_2 -> V_17 ) ;
V_2 -> V_111 -> V_133 ( V_2 , V_4 ) ;
F_101 ( & V_2 -> V_134 ) ;
F_2 ( V_4 ) ;
}
static void V_58 ( unsigned long V_135 )
{
unsigned long V_44 , V_25 ;
struct V_1 * V_2 = (struct V_1 * ) V_135 ;
unsigned int V_121 ;
int V_136 = 0 ;
F_13 ( & V_2 -> V_17 ) ;
V_121 = V_2 -> V_23 ;
V_44 = V_28 ;
V_25 = V_44 + V_48 ;
if ( ! ( V_121 & V_31 ) )
goto V_60;
if ( V_121 & V_137 ) {
if ( F_102 ( V_44 ,
V_2 -> V_94 + V_2 -> V_6 -> V_119 ) ) {
F_31 ( 2 , L_10 , V_2 ) ;
V_25 = V_2 -> V_94 + V_2 -> V_6 -> V_119 ;
} else if ( F_102 ( V_44 ,
V_2 -> V_55 +
F_71 ( V_2 -> V_6 , V_138 ) ) ) {
F_31 ( 2 , L_11 , V_2 ) ;
V_2 -> V_23 = V_139 ;
V_2 -> V_54 = V_28 ;
F_88 ( V_2 ) ;
V_25 = V_44 + F_71 ( V_2 -> V_6 , V_138 ) ;
} else {
F_31 ( 2 , L_7 , V_2 ) ;
V_2 -> V_23 = V_140 ;
V_2 -> V_54 = V_28 ;
F_88 ( V_2 ) ;
V_136 = 1 ;
}
} else if ( V_121 & V_139 ) {
if ( F_102 ( V_44 ,
V_2 -> V_94 +
F_71 ( V_2 -> V_6 , V_138 ) ) ) {
F_31 ( 2 , L_12 , V_2 ) ;
V_2 -> V_23 = V_137 ;
V_2 -> V_54 = V_28 ;
F_89 ( V_2 ) ;
V_136 = 1 ;
V_25 = V_2 -> V_94 + V_2 -> V_6 -> V_119 ;
} else {
F_31 ( 2 , L_13 , V_2 ) ;
V_2 -> V_23 = V_128 ;
V_2 -> V_54 = V_28 ;
F_45 ( & V_2 -> V_134 , 0 ) ;
V_136 = 1 ;
V_25 = V_44 + F_71 ( V_2 -> V_6 , V_141 ) ;
}
} else {
V_25 = V_44 + F_71 ( V_2 -> V_6 , V_141 ) ;
}
if ( ( V_2 -> V_23 & ( V_142 | V_128 ) ) &&
F_14 ( & V_2 -> V_134 ) >= F_95 ( V_2 ) ) {
V_2 -> V_23 = V_123 ;
V_136 = 1 ;
F_96 ( V_2 ) ;
goto V_60;
}
if ( V_2 -> V_23 & V_31 ) {
if ( F_92 ( V_25 , V_28 + V_48 / 2 ) )
V_25 = V_28 + V_48 / 2 ;
if ( ! F_21 ( & V_2 -> V_30 , V_25 ) )
F_19 ( V_2 ) ;
}
if ( V_2 -> V_23 & ( V_142 | V_128 ) ) {
F_98 ( V_2 ) ;
} else {
V_60:
F_16 ( & V_2 -> V_17 ) ;
}
if ( V_136 )
F_103 ( V_2 ) ;
F_5 ( V_2 ) ;
}
int F_104 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_87 ;
bool V_143 = false ;
F_10 ( & V_2 -> V_17 ) ;
V_87 = 0 ;
if ( V_2 -> V_23 & ( V_144 | V_139 | V_128 ) )
goto V_145;
if ( V_2 -> V_26 )
goto V_146;
if ( ! ( V_2 -> V_23 & ( V_140 | V_142 ) ) ) {
if ( F_71 ( V_2 -> V_6 , V_130 ) +
F_71 ( V_2 -> V_6 , V_127 ) ) {
unsigned long V_25 , V_44 = V_28 ;
F_45 ( & V_2 -> V_134 ,
F_71 ( V_2 -> V_6 , V_126 ) ) ;
V_2 -> V_23 = V_142 ;
V_2 -> V_54 = V_44 ;
V_25 = V_44 + F_105 ( F_71 ( V_2 -> V_6 , V_141 ) ,
V_48 / 2 ) ;
F_18 ( V_2 , V_25 ) ;
V_143 = true ;
} else {
V_2 -> V_23 = V_123 ;
V_2 -> V_54 = V_28 ;
F_17 ( & V_2 -> V_17 ) ;
F_2 ( V_4 ) ;
return 1 ;
}
} else if ( V_2 -> V_23 & V_140 ) {
F_31 ( 2 , L_11 , V_2 ) ;
V_2 -> V_23 = V_139 ;
V_2 -> V_54 = V_28 ;
F_18 ( V_2 , V_28 +
F_71 ( V_2 -> V_6 , V_138 ) ) ;
}
if ( V_2 -> V_23 == V_142 ) {
if ( V_4 ) {
while ( V_2 -> V_37 + V_4 -> V_147 >
F_71 ( V_2 -> V_6 , V_148 ) ) {
struct V_3 * V_149 ;
V_149 = F_97 ( & V_2 -> V_36 ) ;
if ( ! V_149 )
break;
V_2 -> V_37 -= V_149 -> V_147 ;
F_2 ( V_149 ) ;
F_9 ( V_2 -> V_11 , V_150 ) ;
}
F_106 ( V_4 ) ;
F_107 ( & V_2 -> V_36 , V_4 ) ;
V_2 -> V_37 += V_4 -> V_147 ;
}
V_87 = 1 ;
}
V_145:
if ( V_143 )
F_98 ( V_2 ) ;
else
F_16 ( & V_2 -> V_17 ) ;
F_108 () ;
return V_87 ;
V_146:
if ( V_2 -> V_23 & V_140 )
goto V_145;
F_17 ( & V_2 -> V_17 ) ;
F_2 ( V_4 ) ;
return 1 ;
}
static void F_109 ( struct V_1 * V_2 )
{
struct V_151 * V_56 ;
void (* F_110)( struct V_151 * , const struct V_35 * , const unsigned char * )
= NULL ;
if ( V_2 -> V_34 -> V_152 )
F_110 = V_2 -> V_34 -> V_152 -> V_153 ;
if ( F_110 ) {
V_56 = & V_2 -> V_56 ;
if ( V_56 -> V_154 ) {
F_111 ( & V_56 -> V_57 ) ;
F_110 ( V_56 , V_2 -> V_34 , V_2 -> V_155 ) ;
F_112 ( & V_56 -> V_57 ) ;
}
}
}
int F_113 ( struct V_1 * V_2 , const T_5 * V_156 , T_5 V_157 ,
T_2 V_158 )
{
T_5 V_159 ;
int V_160 ;
int V_136 = 0 ;
struct V_35 * V_34 ;
int V_161 = 0 ;
F_10 ( & V_2 -> V_17 ) ;
V_34 = V_2 -> V_34 ;
V_159 = V_2 -> V_23 ;
V_160 = - V_162 ;
if ( ! ( V_158 & V_163 ) &&
( V_159 & ( V_40 | V_24 ) ) )
goto V_60;
if ( V_2 -> V_26 )
goto V_60;
if ( ! ( V_157 & V_39 ) ) {
F_24 ( V_2 ) ;
if ( V_159 & V_144 )
F_88 ( V_2 ) ;
V_2 -> V_23 = V_157 ;
V_160 = 0 ;
V_136 = V_159 & V_39 ;
if ( ( V_159 & ( V_142 | V_128 ) ) &&
( V_157 & V_123 ) ) {
F_96 ( V_2 ) ;
V_136 = 1 ;
}
goto V_60;
}
if ( ! V_34 -> V_164 ) {
V_156 = V_2 -> V_155 ;
} else if ( V_156 ) {
if ( ( V_159 & V_39 ) &&
! memcmp ( V_156 , V_2 -> V_155 , V_34 -> V_164 ) )
V_156 = V_2 -> V_155 ;
} else {
V_160 = - V_96 ;
if ( ! ( V_159 & V_39 ) )
goto V_60;
V_156 = V_2 -> V_155 ;
}
if ( V_157 & V_144 )
V_2 -> V_94 = V_28 ;
V_2 -> V_54 = V_28 ;
V_160 = 0 ;
V_161 = V_158 & V_165 ;
if ( V_159 & V_39 ) {
if ( V_156 != V_2 -> V_155 && ! ( V_158 & V_166 ) ) {
V_161 = 0 ;
if ( ( V_158 & V_167 ) &&
( V_159 & V_144 ) ) {
V_156 = V_2 -> V_155 ;
V_157 = V_140 ;
} else
goto V_60;
} else {
if ( V_156 == V_2 -> V_155 && V_157 == V_140 &&
( ( V_158 & V_167 ) ||
( V_159 & V_144 ) )
)
V_157 = V_159 ;
}
}
if ( V_157 != V_159 ) {
F_24 ( V_2 ) ;
if ( V_157 & V_128 )
F_45 ( & V_2 -> V_134 , 0 ) ;
if ( V_157 & V_31 )
F_18 ( V_2 , ( V_28 +
( ( V_157 & V_137 ) ?
V_2 -> V_6 -> V_119 :
0 ) ) ) ;
V_2 -> V_23 = V_157 ;
V_136 = 1 ;
}
if ( V_156 != V_2 -> V_155 ) {
F_114 ( & V_2 -> V_53 ) ;
memcpy ( & V_2 -> V_155 , V_156 , V_34 -> V_164 ) ;
F_115 ( & V_2 -> V_53 ) ;
F_109 ( V_2 ) ;
if ( ! ( V_157 & V_144 ) )
V_2 -> V_94 = V_28 -
( F_71 ( V_2 -> V_6 , V_95 ) << 1 ) ;
V_136 = 1 ;
}
if ( V_157 == V_159 )
goto V_60;
if ( V_157 & V_144 )
F_89 ( V_2 ) ;
else
F_88 ( V_2 ) ;
if ( ! ( V_159 & V_39 ) ) {
struct V_3 * V_4 ;
while ( V_2 -> V_23 & V_39 &&
( V_4 = F_97 ( & V_2 -> V_36 ) ) != NULL ) {
struct V_168 * V_169 = F_116 ( V_4 ) ;
struct V_1 * V_170 , * V_86 = V_2 ;
F_17 ( & V_2 -> V_17 ) ;
F_117 () ;
V_170 = NULL ;
if ( V_169 ) {
V_170 = F_118 ( V_169 , V_4 ) ;
if ( V_170 )
V_86 = V_170 ;
}
V_86 -> V_38 ( V_86 , V_4 ) ;
if ( V_170 )
F_5 ( V_170 ) ;
F_119 () ;
F_10 ( & V_2 -> V_17 ) ;
}
F_30 ( & V_2 -> V_36 ) ;
V_2 -> V_37 = 0 ;
}
V_60:
if ( V_161 ) {
V_2 -> V_158 = ( V_158 & V_171 ) ?
( V_2 -> V_158 | V_172 ) :
( V_2 -> V_158 & ~ V_172 ) ;
}
F_17 ( & V_2 -> V_17 ) ;
if ( V_136 )
F_103 ( V_2 ) ;
return V_160 ;
}
void F_120 ( struct V_1 * V_2 )
{
if ( V_2 -> V_26 )
return;
V_2 -> V_54 = V_28 ;
if ( ! ( V_2 -> V_23 & V_123 ) )
return;
V_2 -> V_23 = V_142 ;
F_45 ( & V_2 -> V_134 , F_95 ( V_2 ) ) ;
F_18 ( V_2 ,
V_28 + F_71 ( V_2 -> V_6 , V_141 ) ) ;
}
struct V_1 * F_121 ( struct V_10 * V_11 ,
T_5 * V_156 , void * V_173 ,
struct V_35 * V_34 )
{
struct V_1 * V_2 = F_122 ( V_11 , V_173 , V_34 ,
V_156 || ! V_34 -> V_164 ) ;
if ( V_2 )
F_113 ( V_2 , V_156 , V_140 ,
V_166 ) ;
return V_2 ;
}
static void F_123 ( struct V_1 * V_19 )
{
struct V_35 * V_34 = V_19 -> V_34 ;
T_6 V_174 = V_19 -> V_11 -> V_175 ;
struct V_151 * V_56 = & V_19 -> V_56 ;
F_10 ( & V_19 -> V_17 ) ;
if ( ! V_56 -> V_154 )
V_34 -> V_152 -> V_176 ( V_19 , V_56 , V_174 ) ;
F_17 ( & V_19 -> V_17 ) ;
}
int F_124 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_87 = 0 ;
if ( ! F_125 ( V_2 , V_4 ) ) {
int V_160 ;
struct V_35 * V_34 = V_2 -> V_34 ;
unsigned int V_177 ;
if ( V_34 -> V_152 -> V_176 && ! V_2 -> V_56 . V_154 )
F_123 ( V_2 ) ;
do {
F_126 ( V_4 , F_127 ( V_4 ) ) ;
V_177 = F_128 ( & V_2 -> V_53 ) ;
V_160 = F_129 ( V_4 , V_34 , F_130 ( V_4 -> V_175 ) ,
V_2 -> V_155 , NULL , V_4 -> V_178 ) ;
} while ( F_131 ( & V_2 -> V_53 , V_177 ) );
if ( V_160 >= 0 )
V_87 = F_132 ( V_4 ) ;
else
goto V_179;
}
V_60:
return V_87 ;
V_179:
V_87 = - V_96 ;
F_2 ( V_4 ) ;
goto V_60;
}
int F_133 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_35 * V_34 = V_2 -> V_34 ;
unsigned int V_177 ;
int V_160 ;
do {
F_126 ( V_4 , F_127 ( V_4 ) ) ;
V_177 = F_128 ( & V_2 -> V_53 ) ;
V_160 = F_129 ( V_4 , V_34 , F_130 ( V_4 -> V_175 ) ,
V_2 -> V_155 , NULL , V_4 -> V_178 ) ;
} while ( F_131 ( & V_2 -> V_53 , V_177 ) );
if ( V_160 >= 0 )
V_160 = F_132 ( V_4 ) ;
else {
V_160 = - V_96 ;
F_2 ( V_4 ) ;
}
return V_160 ;
}
int F_134 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return F_132 ( V_4 ) ;
}
static void F_135 ( unsigned long V_135 )
{
struct V_10 * V_11 = (struct V_10 * ) V_135 ;
long V_180 = 0 ;
unsigned long V_44 = V_28 ;
struct V_3 * V_4 , * V_19 ;
F_136 ( & V_11 -> V_43 . V_17 ) ;
F_137 (&tbl->proxy_queue, skb, n) {
long V_181 = F_138 ( V_4 ) -> V_180 - V_44 ;
if ( V_181 <= 0 ) {
struct V_35 * V_34 = V_4 -> V_34 ;
F_139 ( V_4 , & V_11 -> V_43 ) ;
if ( V_11 -> V_182 && F_140 ( V_34 ) ) {
F_117 () ;
V_11 -> V_182 ( V_4 ) ;
F_119 () ;
} else {
F_2 ( V_4 ) ;
}
F_28 ( V_34 ) ;
} else if ( ! V_180 || V_181 < V_180 )
V_180 = V_181 ;
}
F_25 ( & V_11 -> V_42 ) ;
if ( V_180 )
F_21 ( & V_11 -> V_42 , V_28 + V_180 ) ;
F_141 ( & V_11 -> V_43 . V_17 ) ;
}
void F_142 ( struct V_10 * V_11 , struct V_108 * V_118 ,
struct V_3 * V_4 )
{
unsigned long V_44 = V_28 ;
unsigned long V_180 = V_44 + ( F_7 () %
F_71 ( V_118 , V_183 ) ) ;
if ( V_11 -> V_43 . V_184 > F_71 ( V_118 , V_185 ) ) {
F_2 ( V_4 ) ;
return;
}
F_138 ( V_4 ) -> V_180 = V_180 ;
F_138 ( V_4 ) -> V_158 |= V_186 ;
F_136 ( & V_11 -> V_43 . V_17 ) ;
if ( F_25 ( & V_11 -> V_42 ) ) {
if ( F_92 ( V_11 -> V_42 . V_187 , V_180 ) )
V_180 = V_11 -> V_42 . V_187 ;
}
F_143 ( V_4 ) ;
F_70 ( V_4 -> V_34 ) ;
F_107 ( & V_11 -> V_43 , V_4 ) ;
F_21 ( & V_11 -> V_42 , V_180 ) ;
F_141 ( & V_11 -> V_43 . V_17 ) ;
}
static inline struct V_108 * F_144 ( struct V_10 * V_11 ,
struct V_82 * V_82 , int V_188 )
{
struct V_108 * V_118 ;
F_91 (p, &tbl->parms_list, list) {
if ( ( V_118 -> V_34 && V_118 -> V_34 -> V_188 == V_188 && F_66 ( F_145 ( V_118 ) , V_82 ) ) ||
( ! V_118 -> V_34 && ! V_188 && F_66 ( V_82 , & V_189 ) ) )
return V_118 ;
}
return NULL ;
}
struct V_108 * F_146 ( struct V_35 * V_34 ,
struct V_10 * V_11 )
{
struct V_108 * V_118 ;
struct V_82 * V_82 = F_67 ( V_34 ) ;
const struct V_190 * V_111 = V_34 -> V_91 ;
V_118 = F_147 ( & V_11 -> V_6 , sizeof( * V_118 ) , V_103 ) ;
if ( V_118 ) {
V_118 -> V_11 = V_11 ;
F_45 ( & V_118 -> V_22 , 1 ) ;
V_118 -> V_119 =
F_6 ( F_71 ( V_118 , V_95 ) ) ;
F_70 ( V_34 ) ;
V_118 -> V_34 = V_34 ;
F_80 ( & V_118 -> V_82 , V_82 ) ;
V_118 -> V_191 = NULL ;
if ( V_111 -> V_192 && V_111 -> V_192 ( V_34 , V_118 ) ) {
F_28 ( V_34 ) ;
F_53 ( V_118 ) ;
return NULL ;
}
F_10 ( & V_11 -> V_17 ) ;
F_148 ( & V_118 -> V_33 , & V_11 -> V_6 . V_33 ) ;
F_17 ( & V_11 -> V_17 ) ;
F_149 ( V_118 ) ;
}
return V_118 ;
}
static void F_150 ( struct V_70 * V_71 )
{
struct V_108 * V_6 =
F_55 ( V_71 , struct V_108 , V_70 ) ;
F_82 ( V_6 ) ;
}
void F_151 ( struct V_10 * V_11 , struct V_108 * V_6 )
{
if ( ! V_6 || V_6 == & V_11 -> V_6 )
return;
F_10 ( & V_11 -> V_17 ) ;
F_152 ( & V_6 -> V_33 ) ;
V_6 -> V_26 = 1 ;
F_17 ( & V_11 -> V_17 ) ;
if ( V_6 -> V_34 )
F_28 ( V_6 -> V_34 ) ;
F_58 ( & V_6 -> V_70 , F_150 ) ;
}
static void F_84 ( struct V_108 * V_6 )
{
F_53 ( V_6 ) ;
}
void F_153 ( int V_193 , struct V_10 * V_11 )
{
unsigned long V_44 = V_28 ;
unsigned long V_194 ;
F_154 ( & V_11 -> V_195 ) ;
F_148 ( & V_11 -> V_6 . V_33 , & V_11 -> V_195 ) ;
F_80 ( & V_11 -> V_6 . V_82 , & V_189 ) ;
F_45 ( & V_11 -> V_6 . V_22 , 1 ) ;
V_11 -> V_6 . V_119 =
F_6 ( F_71 ( & V_11 -> V_6 , V_95 ) ) ;
V_11 -> V_196 = F_155 ( struct V_197 ) ;
if ( ! V_11 -> V_196 )
F_156 ( L_14 ) ;
#ifdef F_157
if ( ! F_158 ( V_11 -> V_198 , 0 , V_189 . V_199 ,
& V_200 , V_11 ) )
F_156 ( L_15 ) ;
#endif
F_159 ( V_11 -> V_15 , F_49 ( 3 ) ) ;
V_194 = ( V_98 + 1 ) * sizeof( struct V_99 * ) ;
V_11 -> V_101 = F_39 ( V_194 , V_103 ) ;
if ( ! V_11 -> V_15 || ! V_11 -> V_101 )
F_156 ( L_16 ) ;
if ( ! V_11 -> V_50 )
V_11 -> V_50 = F_160 ( F_161 ( struct V_1 , V_78 ) +
V_11 -> V_83 , V_201 ) ;
else
F_162 ( V_11 -> V_50 % V_201 ) ;
F_41 ( & V_11 -> V_17 ) ;
F_163 ( & V_11 -> V_115 , F_90 ) ;
F_94 ( V_125 , & V_11 -> V_115 ,
V_11 -> V_6 . V_119 ) ;
F_44 ( & V_11 -> V_42 , F_135 , ( unsigned long ) V_11 ) ;
F_164 ( & V_11 -> V_43 ,
& V_202 ) ;
V_11 -> V_27 = V_44 ;
V_11 -> V_117 = V_44 + V_11 -> V_6 . V_119 * 20 ;
V_203 [ V_193 ] = V_11 ;
}
int F_165 ( int V_193 , struct V_10 * V_11 )
{
V_203 [ V_193 ] = NULL ;
F_166 ( & V_11 -> V_115 ) ;
F_35 ( & V_11 -> V_42 ) ;
F_26 ( & V_11 -> V_43 ) ;
F_33 ( V_11 , NULL ) ;
if ( F_14 ( & V_11 -> V_45 ) )
F_167 ( L_17 ) ;
F_58 ( & F_11 ( V_11 -> V_15 , 1 ) -> V_72 ,
F_54 ) ;
V_11 -> V_15 = NULL ;
F_53 ( V_11 -> V_101 ) ;
V_11 -> V_101 = NULL ;
F_168 ( V_11 -> V_198 , V_189 . V_199 ) ;
F_169 ( V_11 -> V_196 ) ;
V_11 -> V_196 = NULL ;
return 0 ;
}
static struct V_10 * F_170 ( int V_204 )
{
struct V_10 * V_11 = NULL ;
switch ( V_204 ) {
case V_205 :
V_11 = V_203 [ V_206 ] ;
break;
case V_207 :
V_11 = V_203 [ V_208 ] ;
break;
case V_209 :
V_11 = V_203 [ V_210 ] ;
break;
}
return V_11 ;
}
static int F_171 ( struct V_3 * V_4 , struct V_211 * V_212 )
{
struct V_82 * V_82 = F_172 ( V_4 -> V_213 ) ;
struct V_214 * V_215 ;
struct V_216 * V_217 ;
struct V_10 * V_11 ;
struct V_1 * V_2 ;
struct V_35 * V_34 = NULL ;
int V_160 = - V_96 ;
F_79 () ;
if ( F_173 ( V_212 ) < sizeof( * V_215 ) )
goto V_60;
V_217 = F_174 ( V_212 , sizeof( * V_215 ) , V_218 ) ;
if ( V_217 == NULL )
goto V_60;
V_215 = F_175 ( V_212 ) ;
if ( V_215 -> V_219 ) {
V_34 = F_176 ( V_82 , V_215 -> V_219 ) ;
if ( V_34 == NULL ) {
V_160 = - V_220 ;
goto V_60;
}
}
V_11 = F_170 ( V_215 -> V_221 ) ;
if ( V_11 == NULL )
return - V_222 ;
if ( F_177 ( V_217 ) < V_11 -> V_83 )
goto V_60;
if ( V_215 -> V_223 & V_224 ) {
V_160 = F_81 ( V_11 , V_82 , F_178 ( V_217 ) , V_34 ) ;
goto V_60;
}
if ( V_34 == NULL )
goto V_60;
V_2 = F_59 ( V_11 , F_178 ( V_217 ) , V_34 ) ;
if ( V_2 == NULL ) {
V_160 = - V_106 ;
goto V_60;
}
V_160 = F_113 ( V_2 , NULL , V_123 ,
V_166 |
V_163 ) ;
F_5 ( V_2 ) ;
V_60:
return V_160 ;
}
static int F_179 ( struct V_3 * V_4 , struct V_211 * V_212 )
{
int V_158 = V_163 | V_166 ;
struct V_82 * V_82 = F_172 ( V_4 -> V_213 ) ;
struct V_214 * V_215 ;
struct V_216 * V_225 [ V_226 + 1 ] ;
struct V_10 * V_11 ;
struct V_35 * V_34 = NULL ;
struct V_1 * V_2 ;
void * V_169 , * V_156 ;
int V_160 ;
F_79 () ;
V_160 = F_180 ( V_212 , sizeof( * V_215 ) , V_225 , V_226 , NULL ) ;
if ( V_160 < 0 )
goto V_60;
V_160 = - V_96 ;
if ( V_225 [ V_218 ] == NULL )
goto V_60;
V_215 = F_175 ( V_212 ) ;
if ( V_215 -> V_219 ) {
V_34 = F_176 ( V_82 , V_215 -> V_219 ) ;
if ( V_34 == NULL ) {
V_160 = - V_220 ;
goto V_60;
}
if ( V_225 [ V_227 ] && F_177 ( V_225 [ V_227 ] ) < V_34 -> V_164 )
goto V_60;
}
V_11 = F_170 ( V_215 -> V_221 ) ;
if ( V_11 == NULL )
return - V_222 ;
if ( F_177 ( V_225 [ V_218 ] ) < V_11 -> V_83 )
goto V_60;
V_169 = F_178 ( V_225 [ V_218 ] ) ;
V_156 = V_225 [ V_227 ] ? F_178 ( V_225 [ V_227 ] ) : NULL ;
if ( V_215 -> V_223 & V_224 ) {
struct V_99 * V_228 ;
V_160 = - V_88 ;
V_228 = F_76 ( V_11 , V_82 , V_169 , V_34 , 1 ) ;
if ( V_228 ) {
V_228 -> V_158 = V_215 -> V_223 ;
V_160 = 0 ;
}
goto V_60;
}
if ( V_34 == NULL )
goto V_60;
V_2 = F_59 ( V_11 , V_169 , V_34 ) ;
if ( V_2 == NULL ) {
if ( ! ( V_212 -> V_229 & V_230 ) ) {
V_160 = - V_106 ;
goto V_60;
}
V_2 = F_181 ( V_11 , V_169 , V_34 ) ;
if ( F_182 ( V_2 ) ) {
V_160 = F_183 ( V_2 ) ;
goto V_60;
}
} else {
if ( V_212 -> V_229 & V_231 ) {
V_160 = - V_232 ;
F_5 ( V_2 ) ;
goto V_60;
}
if ( ! ( V_212 -> V_229 & V_233 ) )
V_158 &= ~ V_166 ;
}
if ( V_215 -> V_223 & V_234 ) {
F_125 ( V_2 , NULL ) ;
V_160 = 0 ;
} else
V_160 = F_113 ( V_2 , V_156 , V_215 -> V_235 , V_158 ) ;
F_5 ( V_2 ) ;
V_60:
return V_160 ;
}
static int F_184 ( struct V_3 * V_4 , struct V_108 * V_6 )
{
struct V_216 * V_236 ;
V_236 = F_185 ( V_4 , V_237 ) ;
if ( V_236 == NULL )
return - V_88 ;
if ( ( V_6 -> V_34 &&
F_186 ( V_4 , V_238 , V_6 -> V_34 -> V_188 ) ) ||
F_186 ( V_4 , V_239 , F_14 ( & V_6 -> V_22 ) ) ||
F_186 ( V_4 , V_240 ,
F_71 ( V_6 , V_148 ) ) ||
F_186 ( V_4 , V_241 ,
F_71 ( V_6 , V_148 ) / F_187 ( V_242 ) ) ||
F_186 ( V_4 , V_243 , F_71 ( V_6 , V_185 ) ) ||
F_186 ( V_4 , V_244 , F_71 ( V_6 , V_127 ) ) ||
F_186 ( V_4 , V_245 ,
F_71 ( V_6 , V_126 ) ) ||
F_186 ( V_4 , V_246 ,
F_71 ( V_6 , V_130 ) ) ||
F_186 ( V_4 , V_247 ,
F_71 ( V_6 , V_129 ) ) ||
F_188 ( V_4 , V_248 , V_6 -> V_119 ) ||
F_188 ( V_4 , V_249 ,
F_71 ( V_6 , V_95 ) ) ||
F_188 ( V_4 , V_250 ,
F_71 ( V_6 , V_124 ) ) ||
F_188 ( V_4 , V_251 ,
F_71 ( V_6 , V_138 ) ) ||
F_188 ( V_4 , V_252 ,
F_71 ( V_6 , V_141 ) ) ||
F_188 ( V_4 , V_253 ,
F_71 ( V_6 , V_254 ) ) ||
F_188 ( V_4 , V_255 ,
F_71 ( V_6 , V_183 ) ) ||
F_188 ( V_4 , V_256 ,
F_71 ( V_6 , V_257 ) ) )
goto V_258;
return F_189 ( V_4 , V_236 ) ;
V_258:
F_190 ( V_4 , V_236 ) ;
return - V_259 ;
}
static int F_191 ( struct V_3 * V_4 , struct V_10 * V_11 ,
T_2 V_260 , T_2 V_177 , int type , int V_158 )
{
struct V_211 * V_212 ;
struct V_261 * V_261 ;
V_212 = F_192 ( V_4 , V_260 , V_177 , type , sizeof( * V_261 ) , V_158 ) ;
if ( V_212 == NULL )
return - V_259 ;
V_261 = F_175 ( V_212 ) ;
F_77 ( & V_11 -> V_17 ) ;
V_261 -> V_262 = V_11 -> V_204 ;
V_261 -> V_263 = 0 ;
V_261 -> V_264 = 0 ;
if ( F_193 ( V_4 , V_265 , V_11 -> V_198 ) ||
F_188 ( V_4 , V_266 , V_11 -> V_267 ) ||
F_186 ( V_4 , V_268 , V_11 -> V_120 ) ||
F_186 ( V_4 , V_269 , V_11 -> V_47 ) ||
F_186 ( V_4 , V_270 , V_11 -> V_46 ) )
goto V_258;
{
unsigned long V_44 = V_28 ;
unsigned int V_271 = V_44 - V_11 -> V_27 ;
unsigned int V_272 = V_44 - V_11 -> V_117 ;
struct V_14 * V_15 ;
struct V_273 V_274 = {
. V_275 = V_11 -> V_83 ,
. V_276 = V_11 -> V_50 ,
. V_277 = F_14 ( & V_11 -> V_45 ) ,
. V_278 = F_194 ( V_271 ) ,
. V_279 = F_194 ( V_272 ) ,
. V_280 = V_11 -> V_43 . V_184 ,
} ;
F_60 () ;
V_15 = F_65 ( V_11 -> V_15 ) ;
V_274 . V_281 = V_15 -> V_69 [ 0 ] ;
V_274 . V_282 = ( ( 1 << V_15 -> V_18 ) - 1 ) ;
F_63 () ;
if ( F_195 ( V_4 , V_283 , sizeof( V_274 ) , & V_274 ) )
goto V_258;
}
{
int V_284 ;
struct V_285 V_286 ;
memset ( & V_286 , 0 , sizeof( V_286 ) ) ;
F_196 (cpu) {
struct V_197 * V_287 ;
V_287 = F_197 ( V_11 -> V_196 , V_284 ) ;
V_286 . V_288 += V_287 -> V_59 ;
V_286 . V_289 += V_287 -> V_109 ;
V_286 . V_290 += V_287 -> V_77 ;
V_286 . V_291 += V_287 -> V_131 ;
V_286 . V_292 += V_287 -> V_80 ;
V_286 . V_293 += V_287 -> V_81 ;
V_286 . V_294 += V_287 -> V_295 ;
V_286 . V_296 += V_287 -> V_297 ;
V_286 . V_298 += V_287 -> V_116 ;
V_286 . V_299 += V_287 -> V_16 ;
}
if ( F_195 ( V_4 , V_300 , sizeof( V_286 ) , & V_286 ) )
goto V_258;
}
F_198 ( V_11 -> V_6 . V_34 ) ;
if ( F_184 ( V_4 , & V_11 -> V_6 ) < 0 )
goto V_258;
F_78 ( & V_11 -> V_17 ) ;
F_199 ( V_4 , V_212 ) ;
return 0 ;
V_258:
F_78 ( & V_11 -> V_17 ) ;
F_200 ( V_4 , V_212 ) ;
return - V_259 ;
}
static int F_201 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_108 * V_6 ,
T_2 V_260 , T_2 V_177 , int type ,
unsigned int V_158 )
{
struct V_261 * V_261 ;
struct V_211 * V_212 ;
V_212 = F_192 ( V_4 , V_260 , V_177 , type , sizeof( * V_261 ) , V_158 ) ;
if ( V_212 == NULL )
return - V_259 ;
V_261 = F_175 ( V_212 ) ;
F_77 ( & V_11 -> V_17 ) ;
V_261 -> V_262 = V_11 -> V_204 ;
V_261 -> V_263 = 0 ;
V_261 -> V_264 = 0 ;
if ( F_193 ( V_4 , V_265 , V_11 -> V_198 ) < 0 ||
F_184 ( V_4 , V_6 ) < 0 )
goto V_301;
F_78 ( & V_11 -> V_17 ) ;
F_199 ( V_4 , V_212 ) ;
return 0 ;
V_301:
F_78 ( & V_11 -> V_17 ) ;
F_200 ( V_4 , V_212 ) ;
return - V_259 ;
}
static int F_202 ( struct V_3 * V_4 , struct V_211 * V_212 )
{
struct V_82 * V_82 = F_172 ( V_4 -> V_213 ) ;
struct V_10 * V_11 ;
struct V_261 * V_261 ;
struct V_216 * V_225 [ V_302 + 1 ] ;
bool V_303 = false ;
int V_160 , V_304 ;
V_160 = F_180 ( V_212 , sizeof( * V_261 ) , V_225 , V_302 ,
V_305 ) ;
if ( V_160 < 0 )
goto V_301;
if ( V_225 [ V_265 ] == NULL ) {
V_160 = - V_96 ;
goto V_301;
}
V_261 = F_175 ( V_212 ) ;
for ( V_304 = 0 ; V_304 < V_306 ; V_304 ++ ) {
V_11 = V_203 [ V_304 ] ;
if ( ! V_11 )
continue;
if ( V_261 -> V_262 && V_11 -> V_204 != V_261 -> V_262 )
continue;
if ( F_203 ( V_225 [ V_265 ] , V_11 -> V_198 ) == 0 ) {
V_303 = true ;
break;
}
}
if ( ! V_303 )
return - V_106 ;
F_10 ( & V_11 -> V_17 ) ;
if ( V_225 [ V_237 ] ) {
struct V_216 * V_307 [ V_308 + 1 ] ;
struct V_108 * V_118 ;
int V_13 , V_188 = 0 ;
V_160 = F_204 ( V_307 , V_308 , V_225 [ V_237 ] ,
V_309 ) ;
if ( V_160 < 0 )
goto V_310;
if ( V_307 [ V_238 ] )
V_188 = F_205 ( V_307 [ V_238 ] ) ;
V_118 = F_144 ( V_11 , V_82 , V_188 ) ;
if ( V_118 == NULL ) {
V_160 = - V_106 ;
goto V_310;
}
for ( V_13 = 1 ; V_13 <= V_308 ; V_13 ++ ) {
if ( V_307 [ V_13 ] == NULL )
continue;
switch ( V_13 ) {
case V_241 :
F_206 ( V_118 , V_148 ,
F_205 ( V_307 [ V_13 ] ) *
F_187 ( V_242 ) ) ;
break;
case V_240 :
F_206 ( V_118 , V_148 ,
F_205 ( V_307 [ V_13 ] ) ) ;
break;
case V_243 :
F_206 ( V_118 , V_185 ,
F_205 ( V_307 [ V_13 ] ) ) ;
break;
case V_244 :
F_206 ( V_118 , V_127 ,
F_205 ( V_307 [ V_13 ] ) ) ;
break;
case V_245 :
F_206 ( V_118 , V_126 ,
F_205 ( V_307 [ V_13 ] ) ) ;
break;
case V_246 :
F_206 ( V_118 , V_130 ,
F_205 ( V_307 [ V_13 ] ) ) ;
break;
case V_247 :
F_206 ( V_118 , V_129 ,
F_205 ( V_307 [ V_13 ] ) ) ;
break;
case V_249 :
F_206 ( V_118 , V_95 ,
F_207 ( V_307 [ V_13 ] ) ) ;
V_118 -> V_119 =
F_6 ( F_71 ( V_118 , V_95 ) ) ;
break;
case V_250 :
F_206 ( V_118 , V_124 ,
F_207 ( V_307 [ V_13 ] ) ) ;
break;
case V_251 :
F_206 ( V_118 , V_138 ,
F_207 ( V_307 [ V_13 ] ) ) ;
break;
case V_252 :
F_206 ( V_118 , V_141 ,
F_207 ( V_307 [ V_13 ] ) ) ;
break;
case V_253 :
F_206 ( V_118 , V_254 ,
F_207 ( V_307 [ V_13 ] ) ) ;
break;
case V_255 :
F_206 ( V_118 , V_183 ,
F_207 ( V_307 [ V_13 ] ) ) ;
break;
case V_256 :
F_206 ( V_118 , V_257 ,
F_207 ( V_307 [ V_13 ] ) ) ;
break;
}
}
}
V_160 = - V_106 ;
if ( ( V_225 [ V_268 ] || V_225 [ V_269 ] ||
V_225 [ V_270 ] || V_225 [ V_266 ] ) &&
! F_66 ( V_82 , & V_189 ) )
goto V_310;
if ( V_225 [ V_268 ] )
V_11 -> V_120 = F_205 ( V_225 [ V_268 ] ) ;
if ( V_225 [ V_269 ] )
V_11 -> V_47 = F_205 ( V_225 [ V_269 ] ) ;
if ( V_225 [ V_270 ] )
V_11 -> V_46 = F_205 ( V_225 [ V_270 ] ) ;
if ( V_225 [ V_266 ] )
V_11 -> V_267 = F_207 ( V_225 [ V_266 ] ) ;
V_160 = 0 ;
V_310:
F_17 ( & V_11 -> V_17 ) ;
V_301:
return V_160 ;
}
static int F_208 ( struct V_3 * V_4 , struct V_311 * V_312 )
{
struct V_82 * V_82 = F_172 ( V_4 -> V_213 ) ;
int V_204 , V_304 , V_313 = 0 ;
int V_314 = V_312 -> args [ 0 ] ;
int V_315 = V_312 -> args [ 1 ] ;
struct V_10 * V_11 ;
V_204 = ( (struct V_316 * ) F_175 ( V_312 -> V_212 ) ) -> V_317 ;
for ( V_304 = 0 ; V_304 < V_306 ; V_304 ++ ) {
struct V_108 * V_118 ;
V_11 = V_203 [ V_304 ] ;
if ( ! V_11 )
continue;
if ( V_304 < V_314 || ( V_204 && V_11 -> V_204 != V_204 ) )
continue;
if ( F_191 ( V_4 , V_11 , F_209 ( V_312 -> V_4 ) . V_318 ,
V_312 -> V_212 -> V_319 , V_320 ,
V_321 ) < 0 )
break;
V_313 = 0 ;
V_118 = F_210 ( & V_11 -> V_6 , V_33 ) ;
F_211 (p, &tbl->parms_list, list) {
if ( ! F_66 ( F_145 ( V_118 ) , V_82 ) )
continue;
if ( V_313 < V_315 )
goto V_25;
if ( F_201 ( V_4 , V_11 , V_118 ,
F_209 ( V_312 -> V_4 ) . V_318 ,
V_312 -> V_212 -> V_319 ,
V_320 ,
V_321 ) < 0 )
goto V_60;
V_25:
V_313 ++ ;
}
V_315 = 0 ;
}
V_60:
V_312 -> args [ 0 ] = V_304 ;
V_312 -> args [ 1 ] = V_313 ;
return V_4 -> V_178 ;
}
static int F_212 ( struct V_3 * V_4 , struct V_1 * V_2 ,
T_2 V_260 , T_2 V_177 , int type , unsigned int V_158 )
{
unsigned long V_44 = V_28 ;
struct V_322 V_323 ;
struct V_211 * V_212 ;
struct V_214 * V_215 ;
V_212 = F_192 ( V_4 , V_260 , V_177 , type , sizeof( * V_215 ) , V_158 ) ;
if ( V_212 == NULL )
return - V_259 ;
V_215 = F_175 ( V_212 ) ;
V_215 -> V_221 = V_2 -> V_111 -> V_204 ;
V_215 -> V_324 = 0 ;
V_215 -> V_325 = 0 ;
V_215 -> V_223 = V_2 -> V_158 ;
V_215 -> V_326 = V_2 -> type ;
V_215 -> V_219 = V_2 -> V_34 -> V_188 ;
if ( F_195 ( V_4 , V_218 , V_2 -> V_11 -> V_83 , V_2 -> V_78 ) )
goto V_258;
F_77 ( & V_2 -> V_17 ) ;
V_215 -> V_235 = V_2 -> V_23 ;
if ( V_2 -> V_23 & V_39 ) {
char V_327 [ V_328 ] ;
F_213 ( V_327 , V_2 , V_2 -> V_34 ) ;
if ( F_195 ( V_4 , V_227 , V_2 -> V_34 -> V_164 , V_327 ) < 0 ) {
F_78 ( & V_2 -> V_17 ) ;
goto V_258;
}
}
V_323 . V_329 = F_214 ( V_44 - V_2 -> V_55 ) ;
V_323 . V_330 = F_214 ( V_44 - V_2 -> V_94 ) ;
V_323 . V_331 = F_214 ( V_44 - V_2 -> V_54 ) ;
V_323 . V_332 = F_14 ( & V_2 -> V_22 ) - 1 ;
F_78 ( & V_2 -> V_17 ) ;
if ( F_186 ( V_4 , V_333 , F_14 ( & V_2 -> V_134 ) ) ||
F_195 ( V_4 , V_334 , sizeof( V_323 ) , & V_323 ) )
goto V_258;
F_199 ( V_4 , V_212 ) ;
return 0 ;
V_258:
F_200 ( V_4 , V_212 ) ;
return - V_259 ;
}
static int F_215 ( struct V_3 * V_4 , struct V_99 * V_228 ,
T_2 V_260 , T_2 V_177 , int type , unsigned int V_158 ,
struct V_10 * V_11 )
{
struct V_211 * V_212 ;
struct V_214 * V_215 ;
V_212 = F_192 ( V_4 , V_260 , V_177 , type , sizeof( * V_215 ) , V_158 ) ;
if ( V_212 == NULL )
return - V_259 ;
V_215 = F_175 ( V_212 ) ;
V_215 -> V_221 = V_11 -> V_204 ;
V_215 -> V_324 = 0 ;
V_215 -> V_325 = 0 ;
V_215 -> V_223 = V_228 -> V_158 | V_224 ;
V_215 -> V_326 = V_335 ;
V_215 -> V_219 = V_228 -> V_34 -> V_188 ;
V_215 -> V_235 = V_41 ;
if ( F_195 ( V_4 , V_218 , V_11 -> V_83 , V_228 -> V_100 ) )
goto V_258;
F_199 ( V_4 , V_212 ) ;
return 0 ;
V_258:
F_200 ( V_4 , V_212 ) ;
return - V_259 ;
}
static void F_103 ( struct V_1 * V_2 )
{
F_216 ( V_336 , V_2 ) ;
F_4 ( V_2 , V_337 , 0 ) ;
}
static int F_217 ( struct V_10 * V_11 , struct V_3 * V_4 ,
struct V_311 * V_312 )
{
struct V_82 * V_82 = F_172 ( V_4 -> V_213 ) ;
struct V_1 * V_19 ;
int V_87 , V_107 , V_338 = V_312 -> args [ 1 ] ;
int V_339 , V_340 = V_339 = V_312 -> args [ 2 ] ;
struct V_14 * V_15 ;
F_60 () ;
V_15 = F_65 ( V_11 -> V_15 ) ;
for ( V_107 = V_338 ; V_107 < ( 1 << V_15 -> V_18 ) ; V_107 ++ ) {
if ( V_107 > V_338 )
V_340 = 0 ;
for ( V_19 = F_65 ( V_15 -> V_21 [ V_107 ] ) , V_339 = 0 ;
V_19 != NULL ;
V_19 = F_65 ( V_19 -> V_25 ) ) {
if ( ! F_66 ( F_67 ( V_19 -> V_34 ) , V_82 ) )
continue;
if ( V_339 < V_340 )
goto V_25;
if ( F_212 ( V_4 , V_19 , F_209 ( V_312 -> V_4 ) . V_318 ,
V_312 -> V_212 -> V_319 ,
V_337 ,
V_321 ) < 0 ) {
V_87 = - 1 ;
goto V_60;
}
V_25:
V_339 ++ ;
}
}
V_87 = V_4 -> V_178 ;
V_60:
F_63 () ;
V_312 -> args [ 1 ] = V_107 ;
V_312 -> args [ 2 ] = V_339 ;
return V_87 ;
}
static int F_218 ( struct V_10 * V_11 , struct V_3 * V_4 ,
struct V_311 * V_312 )
{
struct V_99 * V_19 ;
struct V_82 * V_82 = F_172 ( V_4 -> V_213 ) ;
int V_87 , V_107 , V_338 = V_312 -> args [ 3 ] ;
int V_339 , V_340 = V_339 = V_312 -> args [ 4 ] ;
F_77 ( & V_11 -> V_17 ) ;
for ( V_107 = V_338 ; V_107 <= V_98 ; V_107 ++ ) {
if ( V_107 > V_338 )
V_340 = 0 ;
for ( V_19 = V_11 -> V_101 [ V_107 ] , V_339 = 0 ; V_19 ; V_19 = V_19 -> V_25 ) {
if ( F_67 ( V_19 -> V_34 ) != V_82 )
continue;
if ( V_339 < V_340 )
goto V_25;
if ( F_215 ( V_4 , V_19 , F_209 ( V_312 -> V_4 ) . V_318 ,
V_312 -> V_212 -> V_319 ,
V_337 ,
V_321 , V_11 ) < 0 ) {
F_78 ( & V_11 -> V_17 ) ;
V_87 = - 1 ;
goto V_60;
}
V_25:
V_339 ++ ;
}
}
F_78 ( & V_11 -> V_17 ) ;
V_87 = V_4 -> V_178 ;
V_60:
V_312 -> args [ 3 ] = V_107 ;
V_312 -> args [ 4 ] = V_339 ;
return V_87 ;
}
static int F_219 ( struct V_3 * V_4 , struct V_311 * V_312 )
{
struct V_10 * V_11 ;
int V_341 , V_204 , V_342 ;
int V_343 = 0 ;
int V_160 ;
V_204 = ( (struct V_316 * ) F_175 ( V_312 -> V_212 ) ) -> V_317 ;
if ( F_173 ( V_312 -> V_212 ) >= sizeof( struct V_214 ) &&
( (struct V_214 * ) F_175 ( V_312 -> V_212 ) ) -> V_223 == V_224 )
V_343 = 1 ;
V_342 = V_312 -> args [ 0 ] ;
for ( V_341 = 0 ; V_341 < V_306 ; V_341 ++ ) {
V_11 = V_203 [ V_341 ] ;
if ( ! V_11 )
continue;
if ( V_341 < V_342 || ( V_204 && V_11 -> V_204 != V_204 ) )
continue;
if ( V_341 > V_342 )
memset ( & V_312 -> args [ 1 ] , 0 , sizeof( V_312 -> args ) -
sizeof( V_312 -> args [ 0 ] ) ) ;
if ( V_343 )
V_160 = F_218 ( V_11 , V_4 , V_312 ) ;
else
V_160 = F_217 ( V_11 , V_4 , V_312 ) ;
if ( V_160 < 0 )
break;
}
V_312 -> args [ 0 ] = V_341 ;
return V_4 -> V_178 ;
}
void F_220 ( struct V_10 * V_11 , void (* V_312)( struct V_1 * , void * ) , void * V_344 )
{
int V_345 ;
struct V_14 * V_15 ;
F_60 () ;
V_15 = F_65 ( V_11 -> V_15 ) ;
F_221 ( & V_11 -> V_17 ) ;
for ( V_345 = 0 ; V_345 < ( 1 << V_15 -> V_18 ) ; V_345 ++ ) {
struct V_1 * V_19 ;
for ( V_19 = F_65 ( V_15 -> V_21 [ V_345 ] ) ;
V_19 != NULL ;
V_19 = F_65 ( V_19 -> V_25 ) )
V_312 ( V_19 , V_344 ) ;
}
F_222 ( & V_11 -> V_17 ) ;
F_63 () ;
}
void F_223 ( struct V_10 * V_11 ,
int (* V_312)( struct V_1 * ) )
{
int V_345 ;
struct V_14 * V_15 ;
V_15 = F_11 ( V_11 -> V_15 ,
F_12 ( & V_11 -> V_17 ) ) ;
for ( V_345 = 0 ; V_345 < ( 1 << V_15 -> V_18 ) ; V_345 ++ ) {
struct V_1 * V_19 ;
struct V_1 T_1 * * V_20 ;
V_20 = & V_15 -> V_21 [ V_345 ] ;
while ( ( V_19 = F_11 ( * V_20 ,
F_12 ( & V_11 -> V_17 ) ) ) != NULL ) {
int V_346 ;
F_13 ( & V_19 -> V_17 ) ;
V_346 = V_312 ( V_19 ) ;
if ( V_346 ) {
F_15 ( * V_20 ,
F_11 ( V_19 -> V_25 ,
F_12 ( & V_11 -> V_17 ) ) ) ;
V_19 -> V_26 = 1 ;
} else
V_20 = & V_19 -> V_25 ;
F_16 ( & V_19 -> V_17 ) ;
if ( V_346 )
F_3 ( V_19 ) ;
}
}
}
int F_224 ( int V_193 , struct V_35 * V_34 ,
const void * V_347 , struct V_3 * V_4 )
{
int V_160 = - V_222 ;
if ( F_225 ( V_193 < V_306 ) ) {
struct V_10 * V_11 ;
struct V_1 * V_2 ;
V_11 = V_203 [ V_193 ] ;
if ( ! V_11 )
goto V_60;
V_2 = F_61 ( V_11 , V_347 , V_34 ) ;
if ( ! V_2 )
V_2 = F_68 ( V_11 , V_347 , V_34 , false ) ;
V_160 = F_183 ( V_2 ) ;
if ( F_182 ( V_2 ) )
goto V_179;
V_160 = V_2 -> V_38 ( V_2 , V_4 ) ;
}
else if ( V_193 == V_348 ) {
V_160 = F_129 ( V_4 , V_34 , F_130 ( V_4 -> V_175 ) ,
V_347 , NULL , V_4 -> V_178 ) ;
if ( V_160 < 0 )
goto V_179;
V_160 = F_132 ( V_4 ) ;
}
V_60:
return V_160 ;
V_179:
F_2 ( V_4 ) ;
goto V_60;
}
static struct V_1 * F_226 ( struct V_349 * V_177 )
{
struct V_350 * V_121 = V_177 -> V_351 ;
struct V_82 * V_82 = F_227 ( V_177 ) ;
struct V_14 * V_15 = V_121 -> V_15 ;
struct V_1 * V_19 = NULL ;
int V_352 = V_121 -> V_352 ;
V_121 -> V_158 &= ~ V_353 ;
for ( V_352 = 0 ; V_352 < ( 1 << V_15 -> V_18 ) ; V_352 ++ ) {
V_19 = F_65 ( V_15 -> V_21 [ V_352 ] ) ;
while ( V_19 ) {
if ( ! F_66 ( F_67 ( V_19 -> V_34 ) , V_82 ) )
goto V_25;
if ( V_121 -> V_354 ) {
T_7 V_355 = 0 ;
void * V_356 ;
V_356 = V_121 -> V_354 ( V_121 , V_19 , & V_355 ) ;
if ( ! V_356 )
goto V_25;
}
if ( ! ( V_121 -> V_158 & V_357 ) )
break;
if ( V_19 -> V_23 & ~ V_40 )
break;
V_25:
V_19 = F_65 ( V_19 -> V_25 ) ;
}
if ( V_19 )
break;
}
V_121 -> V_352 = V_352 ;
return V_19 ;
}
static struct V_1 * F_228 ( struct V_349 * V_177 ,
struct V_1 * V_19 ,
T_7 * V_358 )
{
struct V_350 * V_121 = V_177 -> V_351 ;
struct V_82 * V_82 = F_227 ( V_177 ) ;
struct V_14 * V_15 = V_121 -> V_15 ;
if ( V_121 -> V_354 ) {
void * V_356 = V_121 -> V_354 ( V_121 , V_19 , V_358 ) ;
if ( V_356 )
return V_19 ;
}
V_19 = F_65 ( V_19 -> V_25 ) ;
while ( 1 ) {
while ( V_19 ) {
if ( ! F_66 ( F_67 ( V_19 -> V_34 ) , V_82 ) )
goto V_25;
if ( V_121 -> V_354 ) {
void * V_356 = V_121 -> V_354 ( V_121 , V_19 , V_358 ) ;
if ( V_356 )
return V_19 ;
goto V_25;
}
if ( ! ( V_121 -> V_158 & V_357 ) )
break;
if ( V_19 -> V_23 & ~ V_40 )
break;
V_25:
V_19 = F_65 ( V_19 -> V_25 ) ;
}
if ( V_19 )
break;
if ( ++ V_121 -> V_352 >= ( 1 << V_15 -> V_18 ) )
break;
V_19 = F_65 ( V_15 -> V_21 [ V_121 -> V_352 ] ) ;
}
if ( V_19 && V_358 )
-- ( * V_358 ) ;
return V_19 ;
}
static struct V_1 * F_229 ( struct V_349 * V_177 , T_7 * V_358 )
{
struct V_1 * V_19 = F_226 ( V_177 ) ;
if ( V_19 ) {
-- ( * V_358 ) ;
while ( * V_358 ) {
V_19 = F_228 ( V_177 , V_19 , V_358 ) ;
if ( ! V_19 )
break;
}
}
return * V_358 ? NULL : V_19 ;
}
static struct V_99 * F_230 ( struct V_349 * V_177 )
{
struct V_350 * V_121 = V_177 -> V_351 ;
struct V_82 * V_82 = F_227 ( V_177 ) ;
struct V_10 * V_11 = V_121 -> V_11 ;
struct V_99 * V_228 = NULL ;
int V_352 = V_121 -> V_352 ;
V_121 -> V_158 |= V_353 ;
for ( V_352 = 0 ; V_352 <= V_98 ; V_352 ++ ) {
V_228 = V_11 -> V_101 [ V_352 ] ;
while ( V_228 && ! F_66 ( F_74 ( V_228 ) , V_82 ) )
V_228 = V_228 -> V_25 ;
if ( V_228 )
break;
}
V_121 -> V_352 = V_352 ;
return V_228 ;
}
static struct V_99 * F_231 ( struct V_349 * V_177 ,
struct V_99 * V_228 ,
T_7 * V_358 )
{
struct V_350 * V_121 = V_177 -> V_351 ;
struct V_82 * V_82 = F_227 ( V_177 ) ;
struct V_10 * V_11 = V_121 -> V_11 ;
do {
V_228 = V_228 -> V_25 ;
} while ( V_228 && ! F_66 ( F_74 ( V_228 ) , V_82 ) );
while ( ! V_228 ) {
if ( ++ V_121 -> V_352 > V_98 )
break;
V_228 = V_11 -> V_101 [ V_121 -> V_352 ] ;
while ( V_228 && ! F_66 ( F_74 ( V_228 ) , V_82 ) )
V_228 = V_228 -> V_25 ;
if ( V_228 )
break;
}
if ( V_228 && V_358 )
-- ( * V_358 ) ;
return V_228 ;
}
static struct V_99 * F_232 ( struct V_349 * V_177 , T_7 * V_358 )
{
struct V_99 * V_228 = F_230 ( V_177 ) ;
if ( V_228 ) {
-- ( * V_358 ) ;
while ( * V_358 ) {
V_228 = F_231 ( V_177 , V_228 , V_358 ) ;
if ( ! V_228 )
break;
}
}
return * V_358 ? NULL : V_228 ;
}
static void * F_233 ( struct V_349 * V_177 , T_7 * V_358 )
{
struct V_350 * V_121 = V_177 -> V_351 ;
void * V_87 ;
T_7 V_359 = * V_358 ;
V_87 = F_229 ( V_177 , & V_359 ) ;
if ( ! V_87 && ! ( V_121 -> V_158 & V_360 ) )
V_87 = F_232 ( V_177 , & V_359 ) ;
return V_87 ;
}
void * F_234 ( struct V_349 * V_177 , T_7 * V_358 , struct V_10 * V_11 , unsigned int V_361 )
__acquires( T_8 )
{
struct V_350 * V_121 = V_177 -> V_351 ;
V_121 -> V_11 = V_11 ;
V_121 -> V_352 = 0 ;
V_121 -> V_158 = ( V_361 & ~ V_353 ) ;
F_60 () ;
V_121 -> V_15 = F_65 ( V_11 -> V_15 ) ;
return * V_358 ? F_233 ( V_177 , V_358 ) : V_362 ;
}
void * F_235 ( struct V_349 * V_177 , void * V_356 , T_7 * V_358 )
{
struct V_350 * V_121 ;
void * V_87 ;
if ( V_356 == V_362 ) {
V_87 = F_226 ( V_177 ) ;
goto V_60;
}
V_121 = V_177 -> V_351 ;
if ( ! ( V_121 -> V_158 & V_353 ) ) {
V_87 = F_228 ( V_177 , V_356 , NULL ) ;
if ( V_87 )
goto V_60;
if ( ! ( V_121 -> V_158 & V_360 ) )
V_87 = F_230 ( V_177 ) ;
} else {
F_198 ( V_121 -> V_158 & V_360 ) ;
V_87 = F_231 ( V_177 , V_356 , NULL ) ;
}
V_60:
++ ( * V_358 ) ;
return V_87 ;
}
void F_236 ( struct V_349 * V_177 , void * V_356 )
__releases( T_8 )
{
F_63 () ;
}
static void * F_237 ( struct V_349 * V_177 , T_7 * V_358 )
{
struct V_10 * V_11 = V_177 -> V_351 ;
int V_284 ;
if ( * V_358 == 0 )
return V_362 ;
for ( V_284 = * V_358 - 1 ; V_284 < V_363 ; ++ V_284 ) {
if ( ! F_238 ( V_284 ) )
continue;
* V_358 = V_284 + 1 ;
return F_197 ( V_11 -> V_196 , V_284 ) ;
}
return NULL ;
}
static void * F_239 ( struct V_349 * V_177 , void * V_356 , T_7 * V_358 )
{
struct V_10 * V_11 = V_177 -> V_351 ;
int V_284 ;
for ( V_284 = * V_358 ; V_284 < V_363 ; ++ V_284 ) {
if ( ! F_238 ( V_284 ) )
continue;
* V_358 = V_284 + 1 ;
return F_197 ( V_11 -> V_196 , V_284 ) ;
}
return NULL ;
}
static void F_240 ( struct V_349 * V_177 , void * V_356 )
{
}
static int F_241 ( struct V_349 * V_177 , void * V_356 )
{
struct V_10 * V_11 = V_177 -> V_351 ;
struct V_197 * V_287 = V_356 ;
if ( V_356 == V_362 ) {
F_242 ( V_177 , L_18 ) ;
return 0 ;
}
F_242 ( V_177 , L_19
L_20 ,
F_14 ( & V_11 -> V_45 ) ,
V_287 -> V_59 ,
V_287 -> V_109 ,
V_287 -> V_77 ,
V_287 -> V_80 ,
V_287 -> V_81 ,
V_287 -> V_131 ,
V_287 -> V_295 ,
V_287 -> V_297 ,
V_287 -> V_116 ,
V_287 -> V_16 ,
V_287 -> V_150
) ;
return 0 ;
}
static int F_243 ( struct V_364 * V_364 , struct V_365 * V_365 )
{
int V_64 = F_244 ( V_365 , & V_366 ) ;
if ( ! V_64 ) {
struct V_349 * V_367 = V_365 -> V_368 ;
V_367 -> V_351 = F_245 ( V_364 ) ;
}
return V_64 ;
}
static inline T_3 F_246 ( void )
{
return F_247 ( sizeof( struct V_214 ) )
+ F_248 ( V_328 )
+ F_248 ( V_328 )
+ F_248 ( sizeof( struct V_322 ) )
+ F_248 ( 4 ) ;
}
static void F_4 ( struct V_1 * V_19 , int type , int V_158 )
{
struct V_82 * V_82 = F_67 ( V_19 -> V_34 ) ;
struct V_3 * V_4 ;
int V_160 = - V_88 ;
V_4 = F_249 ( F_246 () , V_52 ) ;
if ( V_4 == NULL )
goto V_301;
V_160 = F_212 ( V_4 , V_19 , 0 , 0 , type , V_158 ) ;
if ( V_160 < 0 ) {
F_162 ( V_160 == - V_259 ) ;
F_2 ( V_4 ) ;
goto V_301;
}
F_250 ( V_4 , V_82 , 0 , V_369 , NULL , V_52 ) ;
return;
V_301:
if ( V_160 < 0 )
F_251 ( V_82 , V_369 , V_160 ) ;
}
void F_252 ( struct V_1 * V_19 )
{
F_4 ( V_19 , V_370 , V_371 ) ;
}
static int F_253 ( struct V_372 * V_373 , int V_374 ,
void T_9 * V_375 , T_3 * V_376 , T_7 * V_377 )
{
int V_63 , V_64 ;
struct V_372 V_378 = * V_373 ;
V_378 . V_379 = & V_380 ;
V_378 . V_381 = & V_382 ;
V_378 . V_383 = & V_63 ;
V_63 = * ( int * ) V_373 -> V_383 / F_187 ( V_242 ) ;
V_64 = F_254 ( & V_378 , V_374 , V_375 , V_376 , V_377 ) ;
if ( V_374 && ! V_64 )
* ( int * ) V_373 -> V_383 = V_63 * F_187 ( V_242 ) ;
return V_64 ;
}
static struct V_108 * F_255 ( struct V_35 * V_34 ,
int V_204 )
{
switch ( V_204 ) {
case V_205 :
return F_256 ( V_34 ) ;
case V_207 :
return F_257 ( V_34 ) ;
}
return NULL ;
}
static void F_258 ( struct V_82 * V_82 , struct V_108 * V_118 ,
int V_193 )
{
struct V_35 * V_34 ;
int V_204 = F_259 ( V_118 ) ;
F_117 () ;
F_260 (net, dev) {
struct V_108 * V_384 =
F_255 ( V_34 , V_204 ) ;
if ( V_384 && ! F_261 ( V_193 , V_384 -> V_385 ) )
V_384 -> V_383 [ V_193 ] = V_118 -> V_383 [ V_193 ] ;
}
F_119 () ;
}
static void F_262 ( struct V_372 * V_373 , int V_374 )
{
struct V_35 * V_34 = V_373 -> V_379 ;
struct V_108 * V_118 = V_373 -> V_381 ;
struct V_82 * V_82 = F_145 ( V_118 ) ;
int V_193 = ( int * ) V_373 -> V_383 - V_118 -> V_383 ;
if ( ! V_374 )
return;
F_263 ( V_193 , V_118 -> V_385 ) ;
if ( ! V_34 )
F_258 ( V_82 , V_118 , V_193 ) ;
}
static int F_264 ( struct V_372 * V_373 , int V_374 ,
void T_9 * V_375 ,
T_3 * V_376 , T_7 * V_377 )
{
struct V_372 V_378 = * V_373 ;
int V_64 ;
V_378 . V_379 = & V_380 ;
V_378 . V_381 = & V_386 ;
V_64 = F_254 ( & V_378 , V_374 , V_375 , V_376 , V_377 ) ;
F_262 ( V_373 , V_374 ) ;
return V_64 ;
}
int F_265 ( struct V_372 * V_373 , int V_374 ,
void T_9 * V_375 , T_3 * V_376 , T_7 * V_377 )
{
int V_64 = F_266 ( V_373 , V_374 , V_375 , V_376 , V_377 ) ;
F_262 ( V_373 , V_374 ) ;
return V_64 ;
}
int F_267 ( struct V_372 * V_373 , int V_374 ,
void T_9 * V_375 ,
T_3 * V_376 , T_7 * V_377 )
{
int V_64 = F_268 ( V_373 , V_374 , V_375 , V_376 , V_377 ) ;
F_262 ( V_373 , V_374 ) ;
return V_64 ;
}
static int F_269 ( struct V_372 * V_373 , int V_374 ,
void T_9 * V_375 ,
T_3 * V_376 , T_7 * V_377 )
{
int V_64 = F_270 ( V_373 , V_374 , V_375 , V_376 , V_377 ) ;
F_262 ( V_373 , V_374 ) ;
return V_64 ;
}
int F_271 ( struct V_372 * V_373 , int V_374 ,
void T_9 * V_375 ,
T_3 * V_376 , T_7 * V_377 )
{
int V_64 = F_272 ( V_373 , V_374 , V_375 , V_376 , V_377 ) ;
F_262 ( V_373 , V_374 ) ;
return V_64 ;
}
static int F_273 ( struct V_372 * V_373 , int V_374 ,
void T_9 * V_375 ,
T_3 * V_376 , T_7 * V_377 )
{
int V_64 = F_253 ( V_373 , V_374 , V_375 , V_376 , V_377 ) ;
F_262 ( V_373 , V_374 ) ;
return V_64 ;
}
static int F_274 ( struct V_372 * V_373 , int V_374 ,
void T_9 * V_375 ,
T_3 * V_376 , T_7 * V_377 )
{
struct V_108 * V_118 = V_373 -> V_381 ;
int V_64 ;
if ( strcmp ( V_373 -> V_387 , L_21 ) == 0 )
V_64 = F_267 ( V_373 , V_374 , V_375 , V_376 , V_377 ) ;
else if ( strcmp ( V_373 -> V_387 , L_22 ) == 0 )
V_64 = F_271 ( V_373 , V_374 , V_375 , V_376 , V_377 ) ;
else
V_64 = - 1 ;
if ( V_374 && V_64 == 0 ) {
V_118 -> V_119 =
F_6 ( F_71 ( V_118 , V_95 ) ) ;
}
return V_64 ;
}
int F_275 ( struct V_35 * V_34 , struct V_108 * V_118 ,
T_10 * V_388 )
{
int V_13 ;
struct V_389 * V_341 ;
const char * V_390 ;
char V_391 [ sizeof( L_23 ) + V_392 + V_392 ] ;
char * V_393 ;
V_341 = F_147 ( & V_394 , sizeof( * V_341 ) , V_103 ) ;
if ( ! V_341 )
goto V_160;
for ( V_13 = 0 ; V_13 < V_395 ; V_13 ++ ) {
V_341 -> V_396 [ V_13 ] . V_383 += ( long ) V_118 ;
V_341 -> V_396 [ V_13 ] . V_379 = V_34 ;
V_341 -> V_396 [ V_13 ] . V_381 = V_118 ;
}
if ( V_34 ) {
V_390 = V_34 -> V_397 ;
memset ( & V_341 -> V_396 [ V_395 ] , 0 ,
sizeof( V_341 -> V_396 [ V_395 ] ) ) ;
} else {
struct V_10 * V_11 = V_118 -> V_11 ;
V_390 = L_24 ;
V_341 -> V_396 [ V_395 ] . V_383 = & V_11 -> V_267 ;
V_341 -> V_396 [ V_398 ] . V_383 = & V_11 -> V_120 ;
V_341 -> V_396 [ V_399 ] . V_383 = & V_11 -> V_47 ;
V_341 -> V_396 [ V_400 ] . V_383 = & V_11 -> V_46 ;
}
if ( V_388 ) {
V_341 -> V_396 [ V_401 ] . T_10 = V_388 ;
V_341 -> V_396 [ V_402 ] . T_10 = V_388 ;
V_341 -> V_396 [ V_403 ] . T_10 = V_388 ;
V_341 -> V_396 [ V_404 ] . T_10 = V_388 ;
} else {
V_341 -> V_396 [ V_402 ] . T_10 =
F_274 ;
V_341 -> V_396 [ V_404 ] . T_10 =
F_274 ;
}
if ( F_145 ( V_118 ) -> V_405 != & V_406 )
V_341 -> V_396 [ 0 ] . V_387 = NULL ;
switch ( F_259 ( V_118 ) ) {
case V_205 :
V_393 = L_25 ;
break;
case V_207 :
V_393 = L_26 ;
break;
default:
F_276 () ;
}
snprintf ( V_391 , sizeof( V_391 ) , L_27 ,
V_393 , V_390 ) ;
V_341 -> V_407 =
F_277 ( F_145 ( V_118 ) , V_391 , V_341 -> V_396 ) ;
if ( ! V_341 -> V_407 )
goto free;
V_118 -> V_191 = V_341 ;
return 0 ;
free:
F_53 ( V_341 ) ;
V_160:
return - V_88 ;
}
void F_278 ( struct V_108 * V_118 )
{
if ( V_118 -> V_191 ) {
struct V_389 * V_341 = V_118 -> V_191 ;
V_118 -> V_191 = NULL ;
F_279 ( V_341 -> V_407 ) ;
F_53 ( V_341 ) ;
}
}
static int T_11 F_280 ( void )
{
F_281 ( V_408 , V_337 , F_179 , NULL , NULL ) ;
F_281 ( V_408 , V_8 , F_171 , NULL , NULL ) ;
F_281 ( V_408 , V_370 , NULL , F_219 , NULL ) ;
F_281 ( V_408 , V_409 , NULL , F_208 ,
NULL ) ;
F_281 ( V_408 , V_410 , F_202 , NULL , NULL ) ;
return 0 ;
}
