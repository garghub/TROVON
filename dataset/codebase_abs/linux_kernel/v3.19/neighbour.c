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
int V_80 = V_11 -> V_80 ;
T_2 V_81 ;
struct V_14 * V_15 ;
F_9 ( V_11 , V_82 ) ;
F_60 () ;
V_15 = F_61 ( V_11 -> V_15 ) ;
V_81 = V_11 -> V_74 ( V_79 , V_34 , V_15 -> V_69 ) >> ( 32 - V_15 -> V_18 ) ;
for ( V_19 = F_61 ( V_15 -> V_21 [ V_81 ] ) ;
V_19 != NULL ;
V_19 = F_61 ( V_19 -> V_25 ) ) {
if ( V_34 == V_19 -> V_34 && ! memcmp ( V_19 -> V_78 , V_79 , V_80 ) ) {
if ( ! F_62 ( & V_19 -> V_22 ) )
V_19 = NULL ;
F_9 ( V_11 , V_83 ) ;
break;
}
}
F_63 () ;
return V_19 ;
}
struct V_1 * F_64 ( struct V_10 * V_11 , struct V_84 * V_84 ,
const void * V_79 )
{
struct V_1 * V_19 ;
int V_80 = V_11 -> V_80 ;
T_2 V_81 ;
struct V_14 * V_15 ;
F_9 ( V_11 , V_82 ) ;
F_60 () ;
V_15 = F_61 ( V_11 -> V_15 ) ;
V_81 = V_11 -> V_74 ( V_79 , NULL , V_15 -> V_69 ) >> ( 32 - V_15 -> V_18 ) ;
for ( V_19 = F_61 ( V_15 -> V_21 [ V_81 ] ) ;
V_19 != NULL ;
V_19 = F_61 ( V_19 -> V_25 ) ) {
if ( ! memcmp ( V_19 -> V_78 , V_79 , V_80 ) &&
F_65 ( F_66 ( V_19 -> V_34 ) , V_84 ) ) {
if ( ! F_62 ( & V_19 -> V_22 ) )
V_19 = NULL ;
F_9 ( V_11 , V_83 ) ;
break;
}
}
F_63 () ;
return V_19 ;
}
struct V_1 * F_67 ( struct V_10 * V_11 , const void * V_79 ,
struct V_35 * V_34 , bool V_85 )
{
T_2 V_81 ;
int V_80 = V_11 -> V_80 ;
int error ;
struct V_1 * V_86 , * V_87 , * V_19 = F_36 ( V_11 , V_34 ) ;
struct V_14 * V_15 ;
if ( ! V_19 ) {
V_87 = F_68 ( - V_88 ) ;
goto V_60;
}
memcpy ( V_19 -> V_78 , V_79 , V_80 ) ;
V_19 -> V_34 = V_34 ;
F_69 ( V_34 ) ;
if ( V_11 -> V_89 && ( error = V_11 -> V_89 ( V_19 ) ) < 0 ) {
V_87 = F_68 ( error ) ;
goto V_90;
}
if ( V_34 -> V_91 -> V_92 ) {
error = V_34 -> V_91 -> V_92 ( V_19 ) ;
if ( error < 0 ) {
V_87 = F_68 ( error ) ;
goto V_90;
}
}
if ( V_19 -> V_6 -> V_93 &&
( error = V_19 -> V_6 -> V_93 ( V_19 ) ) < 0 ) {
V_87 = F_68 ( error ) ;
goto V_90;
}
V_19 -> V_94 = V_28 - ( F_70 ( V_19 -> V_6 , V_95 ) << 1 ) ;
F_10 ( & V_11 -> V_17 ) ;
V_15 = F_11 ( V_11 -> V_15 ,
F_12 ( & V_11 -> V_17 ) ) ;
if ( F_14 ( & V_11 -> V_45 ) > ( 1 << V_15 -> V_18 ) )
V_15 = F_57 ( V_11 , V_15 -> V_18 + 1 ) ;
V_81 = V_11 -> V_74 ( V_79 , V_34 , V_15 -> V_69 ) >> ( 32 - V_15 -> V_18 ) ;
if ( V_19 -> V_6 -> V_26 ) {
V_87 = F_68 ( - V_96 ) ;
goto V_97;
}
for ( V_86 = F_11 ( V_15 -> V_21 [ V_81 ] ,
F_12 ( & V_11 -> V_17 ) ) ;
V_86 != NULL ;
V_86 = F_11 ( V_86 -> V_25 ,
F_12 ( & V_11 -> V_17 ) ) ) {
if ( V_34 == V_86 -> V_34 && ! memcmp ( V_86 -> V_78 , V_79 , V_80 ) ) {
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
F_11 ( V_15 -> V_21 [ V_81 ] ,
F_12 ( & V_11 -> V_17 ) ) ) ;
F_15 ( V_15 -> V_21 [ V_81 ] , V_19 ) ;
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
static T_2 F_71 ( const void * V_79 , int V_80 )
{
T_2 V_81 = * ( T_2 * ) ( V_79 + V_80 - 4 ) ;
V_81 ^= ( V_81 >> 16 ) ;
V_81 ^= V_81 >> 8 ;
V_81 ^= V_81 >> 4 ;
V_81 &= V_98 ;
return V_81 ;
}
static struct V_99 * F_72 ( struct V_99 * V_19 ,
struct V_84 * V_84 ,
const void * V_79 ,
int V_80 ,
struct V_35 * V_34 )
{
while ( V_19 ) {
if ( ! memcmp ( V_19 -> V_100 , V_79 , V_80 ) &&
F_65 ( F_73 ( V_19 ) , V_84 ) &&
( V_19 -> V_34 == V_34 || ! V_19 -> V_34 ) )
return V_19 ;
V_19 = V_19 -> V_25 ;
}
return NULL ;
}
struct V_99 * F_74 ( struct V_10 * V_11 ,
struct V_84 * V_84 , const void * V_79 , struct V_35 * V_34 )
{
int V_80 = V_11 -> V_80 ;
T_2 V_81 = F_71 ( V_79 , V_80 ) ;
return F_72 ( V_11 -> V_101 [ V_81 ] ,
V_84 , V_79 , V_80 , V_34 ) ;
}
struct V_99 * F_75 ( struct V_10 * V_11 ,
struct V_84 * V_84 , const void * V_79 ,
struct V_35 * V_34 , int V_102 )
{
struct V_99 * V_19 ;
int V_80 = V_11 -> V_80 ;
T_2 V_81 = F_71 ( V_79 , V_80 ) ;
F_76 ( & V_11 -> V_17 ) ;
V_19 = F_72 ( V_11 -> V_101 [ V_81 ] ,
V_84 , V_79 , V_80 , V_34 ) ;
F_77 ( & V_11 -> V_17 ) ;
if ( V_19 || ! V_102 )
goto V_60;
F_78 () ;
V_19 = F_50 ( sizeof( * V_19 ) + V_80 , V_103 ) ;
if ( ! V_19 )
goto V_60;
F_79 ( & V_19 -> V_84 , F_80 ( V_84 ) ) ;
memcpy ( V_19 -> V_100 , V_79 , V_80 ) ;
V_19 -> V_34 = V_34 ;
if ( V_34 )
F_69 ( V_34 ) ;
if ( V_11 -> V_104 && V_11 -> V_104 ( V_19 ) ) {
if ( V_34 )
F_28 ( V_34 ) ;
F_81 ( V_84 ) ;
F_53 ( V_19 ) ;
V_19 = NULL ;
goto V_60;
}
F_10 ( & V_11 -> V_17 ) ;
V_19 -> V_25 = V_11 -> V_101 [ V_81 ] ;
V_11 -> V_101 [ V_81 ] = V_19 ;
F_17 ( & V_11 -> V_17 ) ;
V_60:
return V_19 ;
}
int F_82 ( struct V_10 * V_11 , struct V_84 * V_84 , const void * V_79 ,
struct V_35 * V_34 )
{
struct V_99 * V_19 , * * V_20 ;
int V_80 = V_11 -> V_80 ;
T_2 V_81 = F_71 ( V_79 , V_80 ) ;
F_10 ( & V_11 -> V_17 ) ;
for ( V_20 = & V_11 -> V_101 [ V_81 ] ; ( V_19 = * V_20 ) != NULL ;
V_20 = & V_19 -> V_25 ) {
if ( ! memcmp ( V_19 -> V_100 , V_79 , V_80 ) && V_19 -> V_34 == V_34 &&
F_65 ( F_73 ( V_19 ) , V_84 ) ) {
* V_20 = V_19 -> V_25 ;
F_17 ( & V_11 -> V_17 ) ;
if ( V_11 -> V_105 )
V_11 -> V_105 ( V_19 ) ;
if ( V_19 -> V_34 )
F_28 ( V_19 -> V_34 ) ;
F_81 ( F_73 ( V_19 ) ) ;
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
F_81 ( F_73 ( V_19 ) ) ;
F_53 ( V_19 ) ;
continue;
}
V_20 = & V_19 -> V_25 ;
}
}
return - V_106 ;
}
static inline void F_83 ( struct V_108 * V_6 )
{
if ( F_84 ( & V_6 -> V_22 ) )
F_85 ( V_6 ) ;
}
void F_86 ( struct V_1 * V_2 )
{
struct V_35 * V_34 = V_2 -> V_34 ;
F_9 ( V_2 -> V_11 , V_109 ) ;
if ( ! V_2 -> V_26 ) {
F_87 ( L_4 , V_2 ) ;
F_23 () ;
return;
}
if ( F_24 ( V_2 ) )
F_87 ( L_5 ) ;
F_10 ( & V_2 -> V_17 ) ;
F_30 ( & V_2 -> V_36 ) ;
F_17 ( & V_2 -> V_17 ) ;
V_2 -> V_37 = 0 ;
if ( V_34 -> V_91 -> V_110 )
V_34 -> V_91 -> V_110 ( V_2 ) ;
F_28 ( V_34 ) ;
F_83 ( V_2 -> V_6 ) ;
F_31 ( 2 , L_6 , V_2 ) ;
F_46 ( & V_2 -> V_11 -> V_45 ) ;
F_88 ( V_2 , V_72 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
F_31 ( 2 , L_7 , V_2 ) ;
V_2 -> V_38 = V_2 -> V_111 -> V_38 ;
}
static void F_90 ( struct V_1 * V_2 )
{
F_31 ( 2 , L_8 , V_2 ) ;
V_2 -> V_38 = V_2 -> V_111 -> V_112 ;
}
static void F_91 ( struct V_113 * V_114 )
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
F_92 (p, &tbl->parms_list, list)
V_118 -> V_119 =
F_6 ( F_70 ( V_118 , V_95 ) ) ;
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
if ( F_93 ( V_19 -> V_55 , V_19 -> V_94 ) )
V_19 -> V_55 = V_19 -> V_94 ;
if ( F_14 ( & V_19 -> V_22 ) == 1 &&
( V_121 == V_123 ||
F_38 ( V_28 , V_19 -> V_55 + F_70 ( V_19 -> V_6 , V_124 ) ) ) ) {
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
F_94 () ;
F_10 ( & V_11 -> V_17 ) ;
V_15 = F_11 ( V_11 -> V_15 ,
F_12 ( & V_11 -> V_17 ) ) ;
}
V_60:
F_95 ( V_125 , & V_11 -> V_115 ,
F_70 ( & V_11 -> V_6 , V_95 ) >> 1 ) ;
F_17 ( & V_11 -> V_17 ) ;
}
static T_4 int F_96 ( struct V_1 * V_19 )
{
struct V_108 * V_118 = V_19 -> V_6 ;
int V_126 = F_70 ( V_118 , V_127 ) + F_70 ( V_118 , V_128 ) ;
if ( ! ( V_19 -> V_23 & V_129 ) )
V_126 += F_70 ( V_118 , V_130 ) ;
return V_126 ;
}
static void F_97 ( struct V_1 * V_2 )
__releases( V_2 -> V_17 )
__acquires( V_2 -> V_17 )
{
struct V_3 * V_4 ;
F_9 ( V_2 -> V_11 , V_131 ) ;
F_31 ( 2 , L_9 , V_2 ) ;
V_2 -> V_54 = V_28 ;
while ( V_2 -> V_23 == V_123 &&
( V_4 = F_98 ( & V_2 -> V_36 ) ) != NULL ) {
F_16 ( & V_2 -> V_17 ) ;
V_2 -> V_111 -> V_132 ( V_2 , V_4 ) ;
F_13 ( & V_2 -> V_17 ) ;
}
F_30 ( & V_2 -> V_36 ) ;
V_2 -> V_37 = 0 ;
}
static void F_99 ( struct V_1 * V_2 )
__releases( V_2 -> V_17 )
{
struct V_3 * V_4 = F_100 ( & V_2 -> V_36 ) ;
if ( V_4 )
V_4 = F_101 ( V_4 , V_52 ) ;
F_16 ( & V_2 -> V_17 ) ;
V_2 -> V_111 -> V_133 ( V_2 , V_4 ) ;
F_102 ( & V_2 -> V_134 ) ;
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
if ( F_103 ( V_44 ,
V_2 -> V_94 + V_2 -> V_6 -> V_119 ) ) {
F_31 ( 2 , L_10 , V_2 ) ;
V_25 = V_2 -> V_94 + V_2 -> V_6 -> V_119 ;
} else if ( F_103 ( V_44 ,
V_2 -> V_55 +
F_70 ( V_2 -> V_6 , V_138 ) ) ) {
F_31 ( 2 , L_11 , V_2 ) ;
V_2 -> V_23 = V_139 ;
V_2 -> V_54 = V_28 ;
F_89 ( V_2 ) ;
V_25 = V_44 + F_70 ( V_2 -> V_6 , V_138 ) ;
} else {
F_31 ( 2 , L_7 , V_2 ) ;
V_2 -> V_23 = V_140 ;
V_2 -> V_54 = V_28 ;
F_89 ( V_2 ) ;
V_136 = 1 ;
}
} else if ( V_121 & V_139 ) {
if ( F_103 ( V_44 ,
V_2 -> V_94 +
F_70 ( V_2 -> V_6 , V_138 ) ) ) {
F_31 ( 2 , L_12 , V_2 ) ;
V_2 -> V_23 = V_137 ;
V_2 -> V_54 = V_28 ;
F_90 ( V_2 ) ;
V_136 = 1 ;
V_25 = V_2 -> V_94 + V_2 -> V_6 -> V_119 ;
} else {
F_31 ( 2 , L_13 , V_2 ) ;
V_2 -> V_23 = V_129 ;
V_2 -> V_54 = V_28 ;
F_45 ( & V_2 -> V_134 , 0 ) ;
V_25 = V_44 + F_70 ( V_2 -> V_6 , V_141 ) ;
}
} else {
V_25 = V_44 + F_70 ( V_2 -> V_6 , V_141 ) ;
}
if ( ( V_2 -> V_23 & ( V_142 | V_129 ) ) &&
F_14 ( & V_2 -> V_134 ) >= F_96 ( V_2 ) ) {
V_2 -> V_23 = V_123 ;
V_136 = 1 ;
F_97 ( V_2 ) ;
goto V_60;
}
if ( V_2 -> V_23 & V_31 ) {
if ( F_93 ( V_25 , V_28 + V_48 / 2 ) )
V_25 = V_28 + V_48 / 2 ;
if ( ! F_21 ( & V_2 -> V_30 , V_25 ) )
F_19 ( V_2 ) ;
}
if ( V_2 -> V_23 & ( V_142 | V_129 ) ) {
F_99 ( V_2 ) ;
} else {
V_60:
F_16 ( & V_2 -> V_17 ) ;
}
if ( V_136 )
F_104 ( V_2 ) ;
F_5 ( V_2 ) ;
}
int F_105 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_87 ;
bool V_143 = false ;
F_10 ( & V_2 -> V_17 ) ;
V_87 = 0 ;
if ( V_2 -> V_23 & ( V_144 | V_139 | V_129 ) )
goto V_145;
if ( ! ( V_2 -> V_23 & ( V_140 | V_142 ) ) ) {
if ( F_70 ( V_2 -> V_6 , V_130 ) +
F_70 ( V_2 -> V_6 , V_128 ) ) {
unsigned long V_25 , V_44 = V_28 ;
F_45 ( & V_2 -> V_134 ,
F_70 ( V_2 -> V_6 , V_127 ) ) ;
V_2 -> V_23 = V_142 ;
V_2 -> V_54 = V_44 ;
V_25 = V_44 + F_106 ( F_70 ( V_2 -> V_6 , V_141 ) ,
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
F_70 ( V_2 -> V_6 , V_138 ) ) ;
}
if ( V_2 -> V_23 == V_142 ) {
if ( V_4 ) {
while ( V_2 -> V_37 + V_4 -> V_146 >
F_70 ( V_2 -> V_6 , V_147 ) ) {
struct V_3 * V_148 ;
V_148 = F_98 ( & V_2 -> V_36 ) ;
if ( ! V_148 )
break;
V_2 -> V_37 -= V_148 -> V_146 ;
F_2 ( V_148 ) ;
F_9 ( V_2 -> V_11 , V_149 ) ;
}
F_107 ( V_4 ) ;
F_108 ( & V_2 -> V_36 , V_4 ) ;
V_2 -> V_37 += V_4 -> V_146 ;
}
V_87 = 1 ;
}
V_145:
if ( V_143 )
F_99 ( V_2 ) ;
else
F_16 ( & V_2 -> V_17 ) ;
F_109 () ;
return V_87 ;
}
static void F_110 ( struct V_1 * V_2 )
{
struct V_150 * V_56 ;
void (* F_111)( struct V_150 * , const struct V_35 * , const unsigned char * )
= NULL ;
if ( V_2 -> V_34 -> V_151 )
F_111 = V_2 -> V_34 -> V_151 -> V_152 ;
if ( F_111 ) {
V_56 = & V_2 -> V_56 ;
if ( V_56 -> V_153 ) {
F_112 ( & V_56 -> V_57 ) ;
F_111 ( V_56 , V_2 -> V_34 , V_2 -> V_154 ) ;
F_113 ( & V_56 -> V_57 ) ;
}
}
}
int F_114 ( struct V_1 * V_2 , const T_5 * V_155 , T_5 V_156 ,
T_2 V_157 )
{
T_5 V_158 ;
int V_159 ;
int V_136 = 0 ;
struct V_35 * V_34 ;
int V_160 = 0 ;
F_10 ( & V_2 -> V_17 ) ;
V_34 = V_2 -> V_34 ;
V_158 = V_2 -> V_23 ;
V_159 = - V_161 ;
if ( ! ( V_157 & V_162 ) &&
( V_158 & ( V_40 | V_24 ) ) )
goto V_60;
if ( ! ( V_156 & V_39 ) ) {
F_24 ( V_2 ) ;
if ( V_158 & V_144 )
F_89 ( V_2 ) ;
V_2 -> V_23 = V_156 ;
V_159 = 0 ;
V_136 = V_158 & V_39 ;
if ( ( V_158 & ( V_142 | V_129 ) ) &&
( V_156 & V_123 ) ) {
F_97 ( V_2 ) ;
V_136 = 1 ;
}
goto V_60;
}
if ( ! V_34 -> V_163 ) {
V_155 = V_2 -> V_154 ;
} else if ( V_155 ) {
if ( ( V_158 & V_39 ) &&
! memcmp ( V_155 , V_2 -> V_154 , V_34 -> V_163 ) )
V_155 = V_2 -> V_154 ;
} else {
V_159 = - V_96 ;
if ( ! ( V_158 & V_39 ) )
goto V_60;
V_155 = V_2 -> V_154 ;
}
if ( V_156 & V_144 )
V_2 -> V_94 = V_28 ;
V_2 -> V_54 = V_28 ;
V_159 = 0 ;
V_160 = V_157 & V_164 ;
if ( V_158 & V_39 ) {
if ( V_155 != V_2 -> V_154 && ! ( V_157 & V_165 ) ) {
V_160 = 0 ;
if ( ( V_157 & V_166 ) &&
( V_158 & V_144 ) ) {
V_155 = V_2 -> V_154 ;
V_156 = V_140 ;
} else
goto V_60;
} else {
if ( V_155 == V_2 -> V_154 && V_156 == V_140 &&
( ( V_157 & V_166 ) ||
( V_158 & V_144 ) )
)
V_156 = V_158 ;
}
}
if ( V_156 != V_158 ) {
F_24 ( V_2 ) ;
if ( V_156 & V_31 )
F_18 ( V_2 , ( V_28 +
( ( V_156 & V_137 ) ?
V_2 -> V_6 -> V_119 :
0 ) ) ) ;
V_2 -> V_23 = V_156 ;
V_136 = 1 ;
}
if ( V_155 != V_2 -> V_154 ) {
F_115 ( & V_2 -> V_53 ) ;
memcpy ( & V_2 -> V_154 , V_155 , V_34 -> V_163 ) ;
F_116 ( & V_2 -> V_53 ) ;
F_110 ( V_2 ) ;
if ( ! ( V_156 & V_144 ) )
V_2 -> V_94 = V_28 -
( F_70 ( V_2 -> V_6 , V_95 ) << 1 ) ;
V_136 = 1 ;
}
if ( V_156 == V_158 )
goto V_60;
if ( V_156 & V_144 )
F_90 ( V_2 ) ;
else
F_89 ( V_2 ) ;
if ( ! ( V_158 & V_39 ) ) {
struct V_3 * V_4 ;
while ( V_2 -> V_23 & V_39 &&
( V_4 = F_98 ( & V_2 -> V_36 ) ) != NULL ) {
struct V_167 * V_168 = F_117 ( V_4 ) ;
struct V_1 * V_169 , * V_86 = V_2 ;
F_17 ( & V_2 -> V_17 ) ;
F_118 () ;
V_169 = NULL ;
if ( V_168 ) {
V_169 = F_119 ( V_168 , V_4 ) ;
if ( V_169 )
V_86 = V_169 ;
}
V_86 -> V_38 ( V_86 , V_4 ) ;
if ( V_169 )
F_5 ( V_169 ) ;
F_120 () ;
F_10 ( & V_2 -> V_17 ) ;
}
F_30 ( & V_2 -> V_36 ) ;
V_2 -> V_37 = 0 ;
}
V_60:
if ( V_160 ) {
V_2 -> V_157 = ( V_157 & V_170 ) ?
( V_2 -> V_157 | V_171 ) :
( V_2 -> V_157 & ~ V_171 ) ;
}
F_17 ( & V_2 -> V_17 ) ;
if ( V_136 )
F_104 ( V_2 ) ;
return V_159 ;
}
void F_121 ( struct V_1 * V_2 )
{
V_2 -> V_54 = V_28 ;
if ( ! ( V_2 -> V_23 & V_123 ) )
return;
V_2 -> V_23 = V_142 ;
F_45 ( & V_2 -> V_134 , F_96 ( V_2 ) ) ;
F_18 ( V_2 ,
V_28 + F_70 ( V_2 -> V_6 , V_141 ) ) ;
}
struct V_1 * F_122 ( struct V_10 * V_11 ,
T_5 * V_155 , void * V_172 ,
struct V_35 * V_34 )
{
struct V_1 * V_2 = F_123 ( V_11 , V_172 , V_34 ,
V_155 || ! V_34 -> V_163 ) ;
if ( V_2 )
F_114 ( V_2 , V_155 , V_140 ,
V_165 ) ;
return V_2 ;
}
static void F_124 ( struct V_1 * V_19 , struct V_167 * V_168 )
{
struct V_35 * V_34 = V_168 -> V_34 ;
T_6 V_173 = V_168 -> V_111 -> V_174 ;
struct V_150 * V_56 = & V_19 -> V_56 ;
F_10 ( & V_19 -> V_17 ) ;
if ( ! V_56 -> V_153 )
V_34 -> V_151 -> V_175 ( V_19 , V_56 , V_173 ) ;
F_17 ( & V_19 -> V_17 ) ;
}
int F_125 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_35 * V_34 = V_4 -> V_34 ;
F_126 ( V_4 , F_127 ( V_4 ) ) ;
if ( F_128 ( V_4 , V_34 , F_129 ( V_4 -> V_174 ) , NULL , NULL ,
V_4 -> V_176 ) < 0 &&
F_130 ( V_4 ) )
return 0 ;
return F_131 ( V_4 ) ;
}
int F_132 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_167 * V_168 = F_117 ( V_4 ) ;
int V_87 = 0 ;
if ( ! V_168 )
goto V_177;
if ( ! F_133 ( V_2 , V_4 ) ) {
int V_159 ;
struct V_35 * V_34 = V_2 -> V_34 ;
unsigned int V_178 ;
if ( V_34 -> V_151 -> V_175 && ! V_2 -> V_56 . V_153 )
F_124 ( V_2 , V_168 ) ;
do {
F_126 ( V_4 , F_127 ( V_4 ) ) ;
V_178 = F_134 ( & V_2 -> V_53 ) ;
V_159 = F_128 ( V_4 , V_34 , F_129 ( V_4 -> V_174 ) ,
V_2 -> V_154 , NULL , V_4 -> V_176 ) ;
} while ( F_135 ( & V_2 -> V_53 , V_178 ) );
if ( V_159 >= 0 )
V_87 = F_131 ( V_4 ) ;
else
goto V_179;
}
V_60:
return V_87 ;
V_177:
F_31 ( 1 , L_14 , V_180 , V_168 , V_2 ) ;
V_179:
V_87 = - V_96 ;
F_2 ( V_4 ) ;
goto V_60;
}
int F_136 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_35 * V_34 = V_2 -> V_34 ;
unsigned int V_178 ;
int V_159 ;
do {
F_126 ( V_4 , F_127 ( V_4 ) ) ;
V_178 = F_134 ( & V_2 -> V_53 ) ;
V_159 = F_128 ( V_4 , V_34 , F_129 ( V_4 -> V_174 ) ,
V_2 -> V_154 , NULL , V_4 -> V_176 ) ;
} while ( F_135 ( & V_2 -> V_53 , V_178 ) );
if ( V_159 >= 0 )
V_159 = F_131 ( V_4 ) ;
else {
V_159 = - V_96 ;
F_2 ( V_4 ) ;
}
return V_159 ;
}
int F_137 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return F_131 ( V_4 ) ;
}
static void F_138 ( unsigned long V_135 )
{
struct V_10 * V_11 = (struct V_10 * ) V_135 ;
long V_181 = 0 ;
unsigned long V_44 = V_28 ;
struct V_3 * V_4 , * V_19 ;
F_139 ( & V_11 -> V_43 . V_17 ) ;
F_140 (&tbl->proxy_queue, skb, n) {
long V_182 = F_141 ( V_4 ) -> V_181 - V_44 ;
if ( V_182 <= 0 ) {
struct V_35 * V_34 = V_4 -> V_34 ;
F_142 ( V_4 , & V_11 -> V_43 ) ;
if ( V_11 -> V_183 && F_143 ( V_34 ) ) {
F_118 () ;
V_11 -> V_183 ( V_4 ) ;
F_120 () ;
} else {
F_2 ( V_4 ) ;
}
F_28 ( V_34 ) ;
} else if ( ! V_181 || V_182 < V_181 )
V_181 = V_182 ;
}
F_25 ( & V_11 -> V_42 ) ;
if ( V_181 )
F_21 ( & V_11 -> V_42 , V_28 + V_181 ) ;
F_144 ( & V_11 -> V_43 . V_17 ) ;
}
void F_145 ( struct V_10 * V_11 , struct V_108 * V_118 ,
struct V_3 * V_4 )
{
unsigned long V_44 = V_28 ;
unsigned long V_181 = V_44 + ( F_7 () %
F_70 ( V_118 , V_184 ) ) ;
if ( V_11 -> V_43 . V_185 > F_70 ( V_118 , V_186 ) ) {
F_2 ( V_4 ) ;
return;
}
F_141 ( V_4 ) -> V_181 = V_181 ;
F_141 ( V_4 ) -> V_157 |= V_187 ;
F_139 ( & V_11 -> V_43 . V_17 ) ;
if ( F_25 ( & V_11 -> V_42 ) ) {
if ( F_93 ( V_11 -> V_42 . V_188 , V_181 ) )
V_181 = V_11 -> V_42 . V_188 ;
}
F_146 ( V_4 ) ;
F_69 ( V_4 -> V_34 ) ;
F_108 ( & V_11 -> V_43 , V_4 ) ;
F_21 ( & V_11 -> V_42 , V_181 ) ;
F_144 ( & V_11 -> V_43 . V_17 ) ;
}
static inline struct V_108 * F_147 ( struct V_10 * V_11 ,
struct V_84 * V_84 , int V_189 )
{
struct V_108 * V_118 ;
F_92 (p, &tbl->parms_list, list) {
if ( ( V_118 -> V_34 && V_118 -> V_34 -> V_189 == V_189 && F_65 ( F_148 ( V_118 ) , V_84 ) ) ||
( ! V_118 -> V_34 && ! V_189 && F_65 ( V_84 , & V_190 ) ) )
return V_118 ;
}
return NULL ;
}
struct V_108 * F_149 ( struct V_35 * V_34 ,
struct V_10 * V_11 )
{
struct V_108 * V_118 ;
struct V_84 * V_84 = F_66 ( V_34 ) ;
const struct V_191 * V_111 = V_34 -> V_91 ;
V_118 = F_150 ( & V_11 -> V_6 , sizeof( * V_118 ) , V_103 ) ;
if ( V_118 ) {
V_118 -> V_11 = V_11 ;
F_45 ( & V_118 -> V_22 , 1 ) ;
V_118 -> V_119 =
F_6 ( F_70 ( V_118 , V_95 ) ) ;
F_69 ( V_34 ) ;
V_118 -> V_34 = V_34 ;
F_79 ( & V_118 -> V_84 , F_80 ( V_84 ) ) ;
V_118 -> V_192 = NULL ;
if ( V_111 -> V_193 && V_111 -> V_193 ( V_34 , V_118 ) ) {
F_81 ( V_84 ) ;
F_28 ( V_34 ) ;
F_53 ( V_118 ) ;
return NULL ;
}
F_10 ( & V_11 -> V_17 ) ;
F_151 ( & V_118 -> V_33 , & V_11 -> V_6 . V_33 ) ;
F_17 ( & V_11 -> V_17 ) ;
F_152 ( V_118 ) ;
}
return V_118 ;
}
static void F_153 ( struct V_70 * V_71 )
{
struct V_108 * V_6 =
F_55 ( V_71 , struct V_108 , V_70 ) ;
F_83 ( V_6 ) ;
}
void F_154 ( struct V_10 * V_11 , struct V_108 * V_6 )
{
if ( ! V_6 || V_6 == & V_11 -> V_6 )
return;
F_10 ( & V_11 -> V_17 ) ;
F_155 ( & V_6 -> V_33 ) ;
V_6 -> V_26 = 1 ;
F_17 ( & V_11 -> V_17 ) ;
if ( V_6 -> V_34 )
F_28 ( V_6 -> V_34 ) ;
F_58 ( & V_6 -> V_70 , F_153 ) ;
}
static void F_85 ( struct V_108 * V_6 )
{
F_81 ( F_148 ( V_6 ) ) ;
F_53 ( V_6 ) ;
}
void F_156 ( int V_194 , struct V_10 * V_11 )
{
unsigned long V_44 = V_28 ;
unsigned long V_195 ;
F_157 ( & V_11 -> V_196 ) ;
F_151 ( & V_11 -> V_6 . V_33 , & V_11 -> V_196 ) ;
F_79 ( & V_11 -> V_6 . V_84 , & V_190 ) ;
F_45 ( & V_11 -> V_6 . V_22 , 1 ) ;
V_11 -> V_6 . V_119 =
F_6 ( F_70 ( & V_11 -> V_6 , V_95 ) ) ;
V_11 -> V_197 = F_158 ( struct V_198 ) ;
if ( ! V_11 -> V_197 )
F_159 ( L_15 ) ;
#ifdef F_160
if ( ! F_161 ( V_11 -> V_199 , 0 , V_190 . V_200 ,
& V_201 , V_11 ) )
F_159 ( L_16 ) ;
#endif
F_162 ( V_11 -> V_15 , F_49 ( 3 ) ) ;
V_195 = ( V_98 + 1 ) * sizeof( struct V_99 * ) ;
V_11 -> V_101 = F_39 ( V_195 , V_103 ) ;
if ( ! V_11 -> V_15 || ! V_11 -> V_101 )
F_159 ( L_17 ) ;
if ( ! V_11 -> V_50 )
V_11 -> V_50 = F_163 ( F_164 ( struct V_1 , V_78 ) +
V_11 -> V_80 , V_202 ) ;
else
F_165 ( V_11 -> V_50 % V_202 ) ;
F_41 ( & V_11 -> V_17 ) ;
F_166 ( & V_11 -> V_115 , F_91 ) ;
F_95 ( V_125 , & V_11 -> V_115 ,
V_11 -> V_6 . V_119 ) ;
F_44 ( & V_11 -> V_42 , F_138 , ( unsigned long ) V_11 ) ;
F_167 ( & V_11 -> V_43 ,
& V_203 ) ;
V_11 -> V_27 = V_44 ;
V_11 -> V_117 = V_44 + V_11 -> V_6 . V_119 * 20 ;
V_204 [ V_194 ] = V_11 ;
}
int F_168 ( int V_194 , struct V_10 * V_11 )
{
V_204 [ V_194 ] = NULL ;
F_169 ( & V_11 -> V_115 ) ;
F_35 ( & V_11 -> V_42 ) ;
F_26 ( & V_11 -> V_43 ) ;
F_33 ( V_11 , NULL ) ;
if ( F_14 ( & V_11 -> V_45 ) )
F_170 ( L_18 ) ;
F_58 ( & F_11 ( V_11 -> V_15 , 1 ) -> V_72 ,
F_54 ) ;
V_11 -> V_15 = NULL ;
F_53 ( V_11 -> V_101 ) ;
V_11 -> V_101 = NULL ;
F_171 ( V_11 -> V_199 , V_190 . V_200 ) ;
F_172 ( V_11 -> V_197 ) ;
V_11 -> V_197 = NULL ;
return 0 ;
}
static struct V_10 * F_173 ( int V_205 )
{
struct V_10 * V_11 = NULL ;
switch ( V_205 ) {
case V_206 :
V_11 = V_204 [ V_207 ] ;
break;
case V_208 :
V_11 = V_204 [ V_209 ] ;
break;
case V_210 :
V_11 = V_204 [ V_211 ] ;
break;
}
return V_11 ;
}
static int F_174 ( struct V_3 * V_4 , struct V_212 * V_213 )
{
struct V_84 * V_84 = F_175 ( V_4 -> V_214 ) ;
struct V_215 * V_216 ;
struct V_217 * V_218 ;
struct V_10 * V_11 ;
struct V_1 * V_2 ;
struct V_35 * V_34 = NULL ;
int V_159 = - V_96 ;
F_78 () ;
if ( F_176 ( V_213 ) < sizeof( * V_216 ) )
goto V_60;
V_218 = F_177 ( V_213 , sizeof( * V_216 ) , V_219 ) ;
if ( V_218 == NULL )
goto V_60;
V_216 = F_178 ( V_213 ) ;
if ( V_216 -> V_220 ) {
V_34 = F_179 ( V_84 , V_216 -> V_220 ) ;
if ( V_34 == NULL ) {
V_159 = - V_221 ;
goto V_60;
}
}
V_11 = F_173 ( V_216 -> V_222 ) ;
if ( V_11 == NULL )
return - V_223 ;
if ( F_180 ( V_218 ) < V_11 -> V_80 )
goto V_60;
if ( V_216 -> V_224 & V_225 ) {
V_159 = F_82 ( V_11 , V_84 , F_181 ( V_218 ) , V_34 ) ;
goto V_60;
}
if ( V_34 == NULL )
goto V_60;
V_2 = F_59 ( V_11 , F_181 ( V_218 ) , V_34 ) ;
if ( V_2 == NULL ) {
V_159 = - V_106 ;
goto V_60;
}
V_159 = F_114 ( V_2 , NULL , V_123 ,
V_165 |
V_162 ) ;
F_5 ( V_2 ) ;
V_60:
return V_159 ;
}
static int F_182 ( struct V_3 * V_4 , struct V_212 * V_213 )
{
int V_157 = V_162 | V_165 ;
struct V_84 * V_84 = F_175 ( V_4 -> V_214 ) ;
struct V_215 * V_216 ;
struct V_217 * V_226 [ V_227 + 1 ] ;
struct V_10 * V_11 ;
struct V_35 * V_34 = NULL ;
struct V_1 * V_2 ;
void * V_168 , * V_155 ;
int V_159 ;
F_78 () ;
V_159 = F_183 ( V_213 , sizeof( * V_216 ) , V_226 , V_227 , NULL ) ;
if ( V_159 < 0 )
goto V_60;
V_159 = - V_96 ;
if ( V_226 [ V_219 ] == NULL )
goto V_60;
V_216 = F_178 ( V_213 ) ;
if ( V_216 -> V_220 ) {
V_34 = F_179 ( V_84 , V_216 -> V_220 ) ;
if ( V_34 == NULL ) {
V_159 = - V_221 ;
goto V_60;
}
if ( V_226 [ V_228 ] && F_180 ( V_226 [ V_228 ] ) < V_34 -> V_163 )
goto V_60;
}
V_11 = F_173 ( V_216 -> V_222 ) ;
if ( V_11 == NULL )
return - V_223 ;
if ( F_180 ( V_226 [ V_219 ] ) < V_11 -> V_80 )
goto V_60;
V_168 = F_181 ( V_226 [ V_219 ] ) ;
V_155 = V_226 [ V_228 ] ? F_181 ( V_226 [ V_228 ] ) : NULL ;
if ( V_216 -> V_224 & V_225 ) {
struct V_99 * V_229 ;
V_159 = - V_88 ;
V_229 = F_75 ( V_11 , V_84 , V_168 , V_34 , 1 ) ;
if ( V_229 ) {
V_229 -> V_157 = V_216 -> V_224 ;
V_159 = 0 ;
}
goto V_60;
}
if ( V_34 == NULL )
goto V_60;
V_2 = F_59 ( V_11 , V_168 , V_34 ) ;
if ( V_2 == NULL ) {
if ( ! ( V_213 -> V_230 & V_231 ) ) {
V_159 = - V_106 ;
goto V_60;
}
V_2 = F_184 ( V_11 , V_168 , V_34 ) ;
if ( F_185 ( V_2 ) ) {
V_159 = F_186 ( V_2 ) ;
goto V_60;
}
} else {
if ( V_213 -> V_230 & V_232 ) {
V_159 = - V_233 ;
F_5 ( V_2 ) ;
goto V_60;
}
if ( ! ( V_213 -> V_230 & V_234 ) )
V_157 &= ~ V_165 ;
}
if ( V_216 -> V_224 & V_235 ) {
F_133 ( V_2 , NULL ) ;
V_159 = 0 ;
} else
V_159 = F_114 ( V_2 , V_155 , V_216 -> V_236 , V_157 ) ;
F_5 ( V_2 ) ;
V_60:
return V_159 ;
}
static int F_187 ( struct V_3 * V_4 , struct V_108 * V_6 )
{
struct V_217 * V_237 ;
V_237 = F_188 ( V_4 , V_238 ) ;
if ( V_237 == NULL )
return - V_88 ;
if ( ( V_6 -> V_34 &&
F_189 ( V_4 , V_239 , V_6 -> V_34 -> V_189 ) ) ||
F_189 ( V_4 , V_240 , F_14 ( & V_6 -> V_22 ) ) ||
F_189 ( V_4 , V_241 ,
F_70 ( V_6 , V_147 ) ) ||
F_189 ( V_4 , V_242 ,
F_70 ( V_6 , V_147 ) / F_190 ( V_243 ) ) ||
F_189 ( V_4 , V_244 , F_70 ( V_6 , V_186 ) ) ||
F_189 ( V_4 , V_245 , F_70 ( V_6 , V_128 ) ) ||
F_189 ( V_4 , V_246 ,
F_70 ( V_6 , V_127 ) ) ||
F_189 ( V_4 , V_247 ,
F_70 ( V_6 , V_130 ) ) ||
F_191 ( V_4 , V_248 , V_6 -> V_119 ) ||
F_191 ( V_4 , V_249 ,
F_70 ( V_6 , V_95 ) ) ||
F_191 ( V_4 , V_250 ,
F_70 ( V_6 , V_124 ) ) ||
F_191 ( V_4 , V_251 ,
F_70 ( V_6 , V_138 ) ) ||
F_191 ( V_4 , V_252 ,
F_70 ( V_6 , V_141 ) ) ||
F_191 ( V_4 , V_253 ,
F_70 ( V_6 , V_254 ) ) ||
F_191 ( V_4 , V_255 ,
F_70 ( V_6 , V_184 ) ) ||
F_191 ( V_4 , V_256 ,
F_70 ( V_6 , V_257 ) ) )
goto V_258;
return F_192 ( V_4 , V_237 ) ;
V_258:
F_193 ( V_4 , V_237 ) ;
return - V_259 ;
}
static int F_194 ( struct V_3 * V_4 , struct V_10 * V_11 ,
T_2 V_260 , T_2 V_178 , int type , int V_157 )
{
struct V_212 * V_213 ;
struct V_261 * V_261 ;
V_213 = F_195 ( V_4 , V_260 , V_178 , type , sizeof( * V_261 ) , V_157 ) ;
if ( V_213 == NULL )
return - V_259 ;
V_261 = F_178 ( V_213 ) ;
F_76 ( & V_11 -> V_17 ) ;
V_261 -> V_262 = V_11 -> V_205 ;
V_261 -> V_263 = 0 ;
V_261 -> V_264 = 0 ;
if ( F_196 ( V_4 , V_265 , V_11 -> V_199 ) ||
F_191 ( V_4 , V_266 , V_11 -> V_267 ) ||
F_189 ( V_4 , V_268 , V_11 -> V_120 ) ||
F_189 ( V_4 , V_269 , V_11 -> V_47 ) ||
F_189 ( V_4 , V_270 , V_11 -> V_46 ) )
goto V_258;
{
unsigned long V_44 = V_28 ;
unsigned int V_271 = V_44 - V_11 -> V_27 ;
unsigned int V_272 = V_44 - V_11 -> V_117 ;
struct V_14 * V_15 ;
struct V_273 V_274 = {
. V_275 = V_11 -> V_80 ,
. V_276 = V_11 -> V_50 ,
. V_277 = F_14 ( & V_11 -> V_45 ) ,
. V_278 = F_197 ( V_271 ) ,
. V_279 = F_197 ( V_272 ) ,
. V_280 = V_11 -> V_43 . V_185 ,
} ;
F_60 () ;
V_15 = F_61 ( V_11 -> V_15 ) ;
V_274 . V_281 = V_15 -> V_69 [ 0 ] ;
V_274 . V_282 = ( ( 1 << V_15 -> V_18 ) - 1 ) ;
F_63 () ;
if ( F_198 ( V_4 , V_283 , sizeof( V_274 ) , & V_274 ) )
goto V_258;
}
{
int V_284 ;
struct V_285 V_286 ;
memset ( & V_286 , 0 , sizeof( V_286 ) ) ;
F_199 (cpu) {
struct V_198 * V_287 ;
V_287 = F_200 ( V_11 -> V_197 , V_284 ) ;
V_286 . V_288 += V_287 -> V_59 ;
V_286 . V_289 += V_287 -> V_109 ;
V_286 . V_290 += V_287 -> V_77 ;
V_286 . V_291 += V_287 -> V_131 ;
V_286 . V_292 += V_287 -> V_82 ;
V_286 . V_293 += V_287 -> V_83 ;
V_286 . V_294 += V_287 -> V_295 ;
V_286 . V_296 += V_287 -> V_297 ;
V_286 . V_298 += V_287 -> V_116 ;
V_286 . V_299 += V_287 -> V_16 ;
}
if ( F_198 ( V_4 , V_300 , sizeof( V_286 ) , & V_286 ) )
goto V_258;
}
F_201 ( V_11 -> V_6 . V_34 ) ;
if ( F_187 ( V_4 , & V_11 -> V_6 ) < 0 )
goto V_258;
F_77 ( & V_11 -> V_17 ) ;
return F_202 ( V_4 , V_213 ) ;
V_258:
F_77 ( & V_11 -> V_17 ) ;
F_203 ( V_4 , V_213 ) ;
return - V_259 ;
}
static int F_204 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_108 * V_6 ,
T_2 V_260 , T_2 V_178 , int type ,
unsigned int V_157 )
{
struct V_261 * V_261 ;
struct V_212 * V_213 ;
V_213 = F_195 ( V_4 , V_260 , V_178 , type , sizeof( * V_261 ) , V_157 ) ;
if ( V_213 == NULL )
return - V_259 ;
V_261 = F_178 ( V_213 ) ;
F_76 ( & V_11 -> V_17 ) ;
V_261 -> V_262 = V_11 -> V_205 ;
V_261 -> V_263 = 0 ;
V_261 -> V_264 = 0 ;
if ( F_196 ( V_4 , V_265 , V_11 -> V_199 ) < 0 ||
F_187 ( V_4 , V_6 ) < 0 )
goto V_301;
F_77 ( & V_11 -> V_17 ) ;
return F_202 ( V_4 , V_213 ) ;
V_301:
F_77 ( & V_11 -> V_17 ) ;
F_203 ( V_4 , V_213 ) ;
return - V_259 ;
}
static int F_205 ( struct V_3 * V_4 , struct V_212 * V_213 )
{
struct V_84 * V_84 = F_175 ( V_4 -> V_214 ) ;
struct V_10 * V_11 ;
struct V_261 * V_261 ;
struct V_217 * V_226 [ V_302 + 1 ] ;
bool V_303 = false ;
int V_159 , V_304 ;
V_159 = F_183 ( V_213 , sizeof( * V_261 ) , V_226 , V_302 ,
V_305 ) ;
if ( V_159 < 0 )
goto V_301;
if ( V_226 [ V_265 ] == NULL ) {
V_159 = - V_96 ;
goto V_301;
}
V_261 = F_178 ( V_213 ) ;
for ( V_304 = 0 ; V_304 < V_306 ; V_304 ++ ) {
V_11 = V_204 [ V_304 ] ;
if ( ! V_11 )
continue;
if ( V_261 -> V_262 && V_11 -> V_205 != V_261 -> V_262 )
continue;
if ( F_206 ( V_226 [ V_265 ] , V_11 -> V_199 ) == 0 ) {
V_303 = true ;
break;
}
}
if ( ! V_303 )
return - V_106 ;
F_10 ( & V_11 -> V_17 ) ;
if ( V_226 [ V_238 ] ) {
struct V_217 * V_307 [ V_308 + 1 ] ;
struct V_108 * V_118 ;
int V_13 , V_189 = 0 ;
V_159 = F_207 ( V_307 , V_308 , V_226 [ V_238 ] ,
V_309 ) ;
if ( V_159 < 0 )
goto V_310;
if ( V_307 [ V_239 ] )
V_189 = F_208 ( V_307 [ V_239 ] ) ;
V_118 = F_147 ( V_11 , V_84 , V_189 ) ;
if ( V_118 == NULL ) {
V_159 = - V_106 ;
goto V_310;
}
for ( V_13 = 1 ; V_13 <= V_308 ; V_13 ++ ) {
if ( V_307 [ V_13 ] == NULL )
continue;
switch ( V_13 ) {
case V_242 :
F_209 ( V_118 , V_147 ,
F_208 ( V_307 [ V_13 ] ) *
F_190 ( V_243 ) ) ;
break;
case V_241 :
F_209 ( V_118 , V_147 ,
F_208 ( V_307 [ V_13 ] ) ) ;
break;
case V_244 :
F_209 ( V_118 , V_186 ,
F_208 ( V_307 [ V_13 ] ) ) ;
break;
case V_245 :
F_209 ( V_118 , V_128 ,
F_208 ( V_307 [ V_13 ] ) ) ;
break;
case V_246 :
F_209 ( V_118 , V_127 ,
F_208 ( V_307 [ V_13 ] ) ) ;
break;
case V_247 :
F_209 ( V_118 , V_130 ,
F_208 ( V_307 [ V_13 ] ) ) ;
break;
case V_249 :
F_209 ( V_118 , V_95 ,
F_210 ( V_307 [ V_13 ] ) ) ;
V_118 -> V_119 =
F_6 ( F_70 ( V_118 , V_95 ) ) ;
break;
case V_250 :
F_209 ( V_118 , V_124 ,
F_210 ( V_307 [ V_13 ] ) ) ;
break;
case V_251 :
F_209 ( V_118 , V_138 ,
F_210 ( V_307 [ V_13 ] ) ) ;
break;
case V_252 :
F_209 ( V_118 , V_141 ,
F_210 ( V_307 [ V_13 ] ) ) ;
break;
case V_253 :
F_209 ( V_118 , V_254 ,
F_210 ( V_307 [ V_13 ] ) ) ;
break;
case V_255 :
F_209 ( V_118 , V_184 ,
F_210 ( V_307 [ V_13 ] ) ) ;
break;
case V_256 :
F_209 ( V_118 , V_257 ,
F_210 ( V_307 [ V_13 ] ) ) ;
break;
}
}
}
V_159 = - V_106 ;
if ( ( V_226 [ V_268 ] || V_226 [ V_269 ] ||
V_226 [ V_270 ] || V_226 [ V_266 ] ) &&
! F_65 ( V_84 , & V_190 ) )
goto V_310;
if ( V_226 [ V_268 ] )
V_11 -> V_120 = F_208 ( V_226 [ V_268 ] ) ;
if ( V_226 [ V_269 ] )
V_11 -> V_47 = F_208 ( V_226 [ V_269 ] ) ;
if ( V_226 [ V_270 ] )
V_11 -> V_46 = F_208 ( V_226 [ V_270 ] ) ;
if ( V_226 [ V_266 ] )
V_11 -> V_267 = F_210 ( V_226 [ V_266 ] ) ;
V_159 = 0 ;
V_310:
F_17 ( & V_11 -> V_17 ) ;
V_301:
return V_159 ;
}
static int F_211 ( struct V_3 * V_4 , struct V_311 * V_312 )
{
struct V_84 * V_84 = F_175 ( V_4 -> V_214 ) ;
int V_205 , V_304 , V_313 = 0 ;
int V_314 = V_312 -> args [ 0 ] ;
int V_315 = V_312 -> args [ 1 ] ;
struct V_10 * V_11 ;
V_205 = ( (struct V_316 * ) F_178 ( V_312 -> V_213 ) ) -> V_317 ;
for ( V_304 = 0 ; V_304 < V_306 ; V_304 ++ ) {
struct V_108 * V_118 ;
V_11 = V_204 [ V_304 ] ;
if ( ! V_11 )
continue;
if ( V_304 < V_314 || ( V_205 && V_11 -> V_205 != V_205 ) )
continue;
if ( F_194 ( V_4 , V_11 , F_212 ( V_312 -> V_4 ) . V_318 ,
V_312 -> V_213 -> V_319 , V_320 ,
V_321 ) <= 0 )
break;
V_313 = 0 ;
V_118 = F_213 ( & V_11 -> V_6 , V_33 ) ;
F_214 (p, &tbl->parms_list, list) {
if ( ! F_65 ( F_148 ( V_118 ) , V_84 ) )
continue;
if ( V_313 < V_315 )
goto V_25;
if ( F_204 ( V_4 , V_11 , V_118 ,
F_212 ( V_312 -> V_4 ) . V_318 ,
V_312 -> V_213 -> V_319 ,
V_320 ,
V_321 ) <= 0 )
goto V_60;
V_25:
V_313 ++ ;
}
V_315 = 0 ;
}
V_60:
V_312 -> args [ 0 ] = V_304 ;
V_312 -> args [ 1 ] = V_313 ;
return V_4 -> V_176 ;
}
static int F_215 ( struct V_3 * V_4 , struct V_1 * V_2 ,
T_2 V_260 , T_2 V_178 , int type , unsigned int V_157 )
{
unsigned long V_44 = V_28 ;
struct V_322 V_323 ;
struct V_212 * V_213 ;
struct V_215 * V_216 ;
V_213 = F_195 ( V_4 , V_260 , V_178 , type , sizeof( * V_216 ) , V_157 ) ;
if ( V_213 == NULL )
return - V_259 ;
V_216 = F_178 ( V_213 ) ;
V_216 -> V_222 = V_2 -> V_111 -> V_205 ;
V_216 -> V_324 = 0 ;
V_216 -> V_325 = 0 ;
V_216 -> V_224 = V_2 -> V_157 ;
V_216 -> V_326 = V_2 -> type ;
V_216 -> V_220 = V_2 -> V_34 -> V_189 ;
if ( F_198 ( V_4 , V_219 , V_2 -> V_11 -> V_80 , V_2 -> V_78 ) )
goto V_258;
F_76 ( & V_2 -> V_17 ) ;
V_216 -> V_236 = V_2 -> V_23 ;
if ( V_2 -> V_23 & V_39 ) {
char V_327 [ V_328 ] ;
F_216 ( V_327 , V_2 , V_2 -> V_34 ) ;
if ( F_198 ( V_4 , V_228 , V_2 -> V_34 -> V_163 , V_327 ) < 0 ) {
F_77 ( & V_2 -> V_17 ) ;
goto V_258;
}
}
V_323 . V_329 = F_217 ( V_44 - V_2 -> V_55 ) ;
V_323 . V_330 = F_217 ( V_44 - V_2 -> V_94 ) ;
V_323 . V_331 = F_217 ( V_44 - V_2 -> V_54 ) ;
V_323 . V_332 = F_14 ( & V_2 -> V_22 ) - 1 ;
F_77 ( & V_2 -> V_17 ) ;
if ( F_189 ( V_4 , V_333 , F_14 ( & V_2 -> V_134 ) ) ||
F_198 ( V_4 , V_334 , sizeof( V_323 ) , & V_323 ) )
goto V_258;
return F_202 ( V_4 , V_213 ) ;
V_258:
F_203 ( V_4 , V_213 ) ;
return - V_259 ;
}
static int F_218 ( struct V_3 * V_4 , struct V_99 * V_229 ,
T_2 V_260 , T_2 V_178 , int type , unsigned int V_157 ,
struct V_10 * V_11 )
{
struct V_212 * V_213 ;
struct V_215 * V_216 ;
V_213 = F_195 ( V_4 , V_260 , V_178 , type , sizeof( * V_216 ) , V_157 ) ;
if ( V_213 == NULL )
return - V_259 ;
V_216 = F_178 ( V_213 ) ;
V_216 -> V_222 = V_11 -> V_205 ;
V_216 -> V_324 = 0 ;
V_216 -> V_325 = 0 ;
V_216 -> V_224 = V_229 -> V_157 | V_225 ;
V_216 -> V_326 = V_335 ;
V_216 -> V_220 = V_229 -> V_34 -> V_189 ;
V_216 -> V_236 = V_41 ;
if ( F_198 ( V_4 , V_219 , V_11 -> V_80 , V_229 -> V_100 ) )
goto V_258;
return F_202 ( V_4 , V_213 ) ;
V_258:
F_203 ( V_4 , V_213 ) ;
return - V_259 ;
}
static void F_104 ( struct V_1 * V_2 )
{
F_219 ( V_336 , V_2 ) ;
F_4 ( V_2 , V_337 , 0 ) ;
}
static int F_220 ( struct V_10 * V_11 , struct V_3 * V_4 ,
struct V_311 * V_312 )
{
struct V_84 * V_84 = F_175 ( V_4 -> V_214 ) ;
struct V_1 * V_19 ;
int V_87 , V_107 , V_338 = V_312 -> args [ 1 ] ;
int V_339 , V_340 = V_339 = V_312 -> args [ 2 ] ;
struct V_14 * V_15 ;
F_60 () ;
V_15 = F_61 ( V_11 -> V_15 ) ;
for ( V_107 = V_338 ; V_107 < ( 1 << V_15 -> V_18 ) ; V_107 ++ ) {
if ( V_107 > V_338 )
V_340 = 0 ;
for ( V_19 = F_61 ( V_15 -> V_21 [ V_107 ] ) , V_339 = 0 ;
V_19 != NULL ;
V_19 = F_61 ( V_19 -> V_25 ) ) {
if ( ! F_65 ( F_66 ( V_19 -> V_34 ) , V_84 ) )
continue;
if ( V_339 < V_340 )
goto V_25;
if ( F_215 ( V_4 , V_19 , F_212 ( V_312 -> V_4 ) . V_318 ,
V_312 -> V_213 -> V_319 ,
V_337 ,
V_321 ) <= 0 ) {
V_87 = - 1 ;
goto V_60;
}
V_25:
V_339 ++ ;
}
}
V_87 = V_4 -> V_176 ;
V_60:
F_63 () ;
V_312 -> args [ 1 ] = V_107 ;
V_312 -> args [ 2 ] = V_339 ;
return V_87 ;
}
static int F_221 ( struct V_10 * V_11 , struct V_3 * V_4 ,
struct V_311 * V_312 )
{
struct V_99 * V_19 ;
struct V_84 * V_84 = F_175 ( V_4 -> V_214 ) ;
int V_87 , V_107 , V_338 = V_312 -> args [ 3 ] ;
int V_339 , V_340 = V_339 = V_312 -> args [ 4 ] ;
F_76 ( & V_11 -> V_17 ) ;
for ( V_107 = V_338 ; V_107 <= V_98 ; V_107 ++ ) {
if ( V_107 > V_338 )
V_340 = 0 ;
for ( V_19 = V_11 -> V_101 [ V_107 ] , V_339 = 0 ; V_19 ; V_19 = V_19 -> V_25 ) {
if ( F_66 ( V_19 -> V_34 ) != V_84 )
continue;
if ( V_339 < V_340 )
goto V_25;
if ( F_218 ( V_4 , V_19 , F_212 ( V_312 -> V_4 ) . V_318 ,
V_312 -> V_213 -> V_319 ,
V_337 ,
V_321 , V_11 ) <= 0 ) {
F_77 ( & V_11 -> V_17 ) ;
V_87 = - 1 ;
goto V_60;
}
V_25:
V_339 ++ ;
}
}
F_77 ( & V_11 -> V_17 ) ;
V_87 = V_4 -> V_176 ;
V_60:
V_312 -> args [ 3 ] = V_107 ;
V_312 -> args [ 4 ] = V_339 ;
return V_87 ;
}
static int F_222 ( struct V_3 * V_4 , struct V_311 * V_312 )
{
struct V_10 * V_11 ;
int V_341 , V_205 , V_342 ;
int V_343 = 0 ;
int V_159 ;
V_205 = ( (struct V_316 * ) F_178 ( V_312 -> V_213 ) ) -> V_317 ;
if ( F_176 ( V_312 -> V_213 ) >= sizeof( struct V_215 ) &&
( (struct V_215 * ) F_178 ( V_312 -> V_213 ) ) -> V_224 == V_225 )
V_343 = 1 ;
V_342 = V_312 -> args [ 0 ] ;
for ( V_341 = 0 ; V_341 < V_306 ; V_341 ++ ) {
V_11 = V_204 [ V_341 ] ;
if ( ! V_11 )
continue;
if ( V_341 < V_342 || ( V_205 && V_11 -> V_205 != V_205 ) )
continue;
if ( V_341 > V_342 )
memset ( & V_312 -> args [ 1 ] , 0 , sizeof( V_312 -> args ) -
sizeof( V_312 -> args [ 0 ] ) ) ;
if ( V_343 )
V_159 = F_221 ( V_11 , V_4 , V_312 ) ;
else
V_159 = F_220 ( V_11 , V_4 , V_312 ) ;
if ( V_159 < 0 )
break;
}
V_312 -> args [ 0 ] = V_341 ;
return V_4 -> V_176 ;
}
void F_223 ( struct V_10 * V_11 , void (* V_312)( struct V_1 * , void * ) , void * V_344 )
{
int V_345 ;
struct V_14 * V_15 ;
F_60 () ;
V_15 = F_61 ( V_11 -> V_15 ) ;
F_224 ( & V_11 -> V_17 ) ;
for ( V_345 = 0 ; V_345 < ( 1 << V_15 -> V_18 ) ; V_345 ++ ) {
struct V_1 * V_19 ;
for ( V_19 = F_61 ( V_15 -> V_21 [ V_345 ] ) ;
V_19 != NULL ;
V_19 = F_61 ( V_19 -> V_25 ) )
V_312 ( V_19 , V_344 ) ;
}
F_225 ( & V_11 -> V_17 ) ;
F_63 () ;
}
void F_226 ( struct V_10 * V_11 ,
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
static struct V_1 * F_227 ( struct V_347 * V_178 )
{
struct V_348 * V_121 = V_178 -> V_349 ;
struct V_84 * V_84 = F_228 ( V_178 ) ;
struct V_14 * V_15 = V_121 -> V_15 ;
struct V_1 * V_19 = NULL ;
int V_350 = V_121 -> V_350 ;
V_121 -> V_157 &= ~ V_351 ;
for ( V_350 = 0 ; V_350 < ( 1 << V_15 -> V_18 ) ; V_350 ++ ) {
V_19 = F_61 ( V_15 -> V_21 [ V_350 ] ) ;
while ( V_19 ) {
if ( ! F_65 ( F_66 ( V_19 -> V_34 ) , V_84 ) )
goto V_25;
if ( V_121 -> V_352 ) {
T_7 V_353 = 0 ;
void * V_354 ;
V_354 = V_121 -> V_352 ( V_121 , V_19 , & V_353 ) ;
if ( ! V_354 )
goto V_25;
}
if ( ! ( V_121 -> V_157 & V_355 ) )
break;
if ( V_19 -> V_23 & ~ V_40 )
break;
V_25:
V_19 = F_61 ( V_19 -> V_25 ) ;
}
if ( V_19 )
break;
}
V_121 -> V_350 = V_350 ;
return V_19 ;
}
static struct V_1 * F_229 ( struct V_347 * V_178 ,
struct V_1 * V_19 ,
T_7 * V_356 )
{
struct V_348 * V_121 = V_178 -> V_349 ;
struct V_84 * V_84 = F_228 ( V_178 ) ;
struct V_14 * V_15 = V_121 -> V_15 ;
if ( V_121 -> V_352 ) {
void * V_354 = V_121 -> V_352 ( V_121 , V_19 , V_356 ) ;
if ( V_354 )
return V_19 ;
}
V_19 = F_61 ( V_19 -> V_25 ) ;
while ( 1 ) {
while ( V_19 ) {
if ( ! F_65 ( F_66 ( V_19 -> V_34 ) , V_84 ) )
goto V_25;
if ( V_121 -> V_352 ) {
void * V_354 = V_121 -> V_352 ( V_121 , V_19 , V_356 ) ;
if ( V_354 )
return V_19 ;
goto V_25;
}
if ( ! ( V_121 -> V_157 & V_355 ) )
break;
if ( V_19 -> V_23 & ~ V_40 )
break;
V_25:
V_19 = F_61 ( V_19 -> V_25 ) ;
}
if ( V_19 )
break;
if ( ++ V_121 -> V_350 >= ( 1 << V_15 -> V_18 ) )
break;
V_19 = F_61 ( V_15 -> V_21 [ V_121 -> V_350 ] ) ;
}
if ( V_19 && V_356 )
-- ( * V_356 ) ;
return V_19 ;
}
static struct V_1 * F_230 ( struct V_347 * V_178 , T_7 * V_356 )
{
struct V_1 * V_19 = F_227 ( V_178 ) ;
if ( V_19 ) {
-- ( * V_356 ) ;
while ( * V_356 ) {
V_19 = F_229 ( V_178 , V_19 , V_356 ) ;
if ( ! V_19 )
break;
}
}
return * V_356 ? NULL : V_19 ;
}
static struct V_99 * F_231 ( struct V_347 * V_178 )
{
struct V_348 * V_121 = V_178 -> V_349 ;
struct V_84 * V_84 = F_228 ( V_178 ) ;
struct V_10 * V_11 = V_121 -> V_11 ;
struct V_99 * V_229 = NULL ;
int V_350 = V_121 -> V_350 ;
V_121 -> V_157 |= V_351 ;
for ( V_350 = 0 ; V_350 <= V_98 ; V_350 ++ ) {
V_229 = V_11 -> V_101 [ V_350 ] ;
while ( V_229 && ! F_65 ( F_73 ( V_229 ) , V_84 ) )
V_229 = V_229 -> V_25 ;
if ( V_229 )
break;
}
V_121 -> V_350 = V_350 ;
return V_229 ;
}
static struct V_99 * F_232 ( struct V_347 * V_178 ,
struct V_99 * V_229 ,
T_7 * V_356 )
{
struct V_348 * V_121 = V_178 -> V_349 ;
struct V_84 * V_84 = F_228 ( V_178 ) ;
struct V_10 * V_11 = V_121 -> V_11 ;
do {
V_229 = V_229 -> V_25 ;
} while ( V_229 && ! F_65 ( F_73 ( V_229 ) , V_84 ) );
while ( ! V_229 ) {
if ( ++ V_121 -> V_350 > V_98 )
break;
V_229 = V_11 -> V_101 [ V_121 -> V_350 ] ;
while ( V_229 && ! F_65 ( F_73 ( V_229 ) , V_84 ) )
V_229 = V_229 -> V_25 ;
if ( V_229 )
break;
}
if ( V_229 && V_356 )
-- ( * V_356 ) ;
return V_229 ;
}
static struct V_99 * F_233 ( struct V_347 * V_178 , T_7 * V_356 )
{
struct V_99 * V_229 = F_231 ( V_178 ) ;
if ( V_229 ) {
-- ( * V_356 ) ;
while ( * V_356 ) {
V_229 = F_232 ( V_178 , V_229 , V_356 ) ;
if ( ! V_229 )
break;
}
}
return * V_356 ? NULL : V_229 ;
}
static void * F_234 ( struct V_347 * V_178 , T_7 * V_356 )
{
struct V_348 * V_121 = V_178 -> V_349 ;
void * V_87 ;
T_7 V_357 = * V_356 ;
V_87 = F_230 ( V_178 , & V_357 ) ;
if ( ! V_87 && ! ( V_121 -> V_157 & V_358 ) )
V_87 = F_233 ( V_178 , & V_357 ) ;
return V_87 ;
}
void * F_235 ( struct V_347 * V_178 , T_7 * V_356 , struct V_10 * V_11 , unsigned int V_359 )
__acquires( T_8 )
{
struct V_348 * V_121 = V_178 -> V_349 ;
V_121 -> V_11 = V_11 ;
V_121 -> V_350 = 0 ;
V_121 -> V_157 = ( V_359 & ~ V_351 ) ;
F_60 () ;
V_121 -> V_15 = F_61 ( V_11 -> V_15 ) ;
return * V_356 ? F_234 ( V_178 , V_356 ) : V_360 ;
}
void * F_236 ( struct V_347 * V_178 , void * V_354 , T_7 * V_356 )
{
struct V_348 * V_121 ;
void * V_87 ;
if ( V_354 == V_360 ) {
V_87 = F_227 ( V_178 ) ;
goto V_60;
}
V_121 = V_178 -> V_349 ;
if ( ! ( V_121 -> V_157 & V_351 ) ) {
V_87 = F_229 ( V_178 , V_354 , NULL ) ;
if ( V_87 )
goto V_60;
if ( ! ( V_121 -> V_157 & V_358 ) )
V_87 = F_231 ( V_178 ) ;
} else {
F_201 ( V_121 -> V_157 & V_358 ) ;
V_87 = F_232 ( V_178 , V_354 , NULL ) ;
}
V_60:
++ ( * V_356 ) ;
return V_87 ;
}
void F_237 ( struct V_347 * V_178 , void * V_354 )
__releases( T_8 )
{
F_63 () ;
}
static void * F_238 ( struct V_347 * V_178 , T_7 * V_356 )
{
struct V_10 * V_11 = V_178 -> V_349 ;
int V_284 ;
if ( * V_356 == 0 )
return V_360 ;
for ( V_284 = * V_356 - 1 ; V_284 < V_361 ; ++ V_284 ) {
if ( ! F_239 ( V_284 ) )
continue;
* V_356 = V_284 + 1 ;
return F_200 ( V_11 -> V_197 , V_284 ) ;
}
return NULL ;
}
static void * F_240 ( struct V_347 * V_178 , void * V_354 , T_7 * V_356 )
{
struct V_10 * V_11 = V_178 -> V_349 ;
int V_284 ;
for ( V_284 = * V_356 ; V_284 < V_361 ; ++ V_284 ) {
if ( ! F_239 ( V_284 ) )
continue;
* V_356 = V_284 + 1 ;
return F_200 ( V_11 -> V_197 , V_284 ) ;
}
return NULL ;
}
static void F_241 ( struct V_347 * V_178 , void * V_354 )
{
}
static int F_242 ( struct V_347 * V_178 , void * V_354 )
{
struct V_10 * V_11 = V_178 -> V_349 ;
struct V_198 * V_287 = V_354 ;
if ( V_354 == V_360 ) {
F_243 ( V_178 , L_19 ) ;
return 0 ;
}
F_243 ( V_178 , L_20
L_21 ,
F_14 ( & V_11 -> V_45 ) ,
V_287 -> V_59 ,
V_287 -> V_109 ,
V_287 -> V_77 ,
V_287 -> V_82 ,
V_287 -> V_83 ,
V_287 -> V_131 ,
V_287 -> V_295 ,
V_287 -> V_297 ,
V_287 -> V_116 ,
V_287 -> V_16 ,
V_287 -> V_149
) ;
return 0 ;
}
static int F_244 ( struct V_362 * V_362 , struct V_363 * V_363 )
{
int V_64 = F_245 ( V_363 , & V_364 ) ;
if ( ! V_64 ) {
struct V_347 * V_365 = V_363 -> V_366 ;
V_365 -> V_349 = F_246 ( V_362 ) ;
}
return V_64 ;
}
static inline T_3 F_247 ( void )
{
return F_248 ( sizeof( struct V_215 ) )
+ F_249 ( V_328 )
+ F_249 ( V_328 )
+ F_249 ( sizeof( struct V_322 ) )
+ F_249 ( 4 ) ;
}
static void F_4 ( struct V_1 * V_19 , int type , int V_157 )
{
struct V_84 * V_84 = F_66 ( V_19 -> V_34 ) ;
struct V_3 * V_4 ;
int V_159 = - V_88 ;
V_4 = F_250 ( F_247 () , V_52 ) ;
if ( V_4 == NULL )
goto V_301;
V_159 = F_215 ( V_4 , V_19 , 0 , 0 , type , V_157 ) ;
if ( V_159 < 0 ) {
F_165 ( V_159 == - V_259 ) ;
F_2 ( V_4 ) ;
goto V_301;
}
F_251 ( V_4 , V_84 , 0 , V_367 , NULL , V_52 ) ;
return;
V_301:
if ( V_159 < 0 )
F_252 ( V_84 , V_367 , V_159 ) ;
}
void F_253 ( struct V_1 * V_19 )
{
F_4 ( V_19 , V_368 , V_369 ) ;
}
static int F_254 ( struct V_370 * V_371 , int V_372 ,
void T_9 * V_373 , T_3 * V_374 , T_7 * V_375 )
{
int V_63 , V_64 ;
struct V_370 V_376 = * V_371 ;
V_376 . V_377 = & V_378 ;
V_376 . V_379 = & V_380 ;
V_376 . V_381 = & V_63 ;
V_63 = * ( int * ) V_371 -> V_381 / F_190 ( V_243 ) ;
V_64 = F_255 ( & V_376 , V_372 , V_373 , V_374 , V_375 ) ;
if ( V_372 && ! V_64 )
* ( int * ) V_371 -> V_381 = V_63 * F_190 ( V_243 ) ;
return V_64 ;
}
static struct V_108 * F_256 ( struct V_35 * V_34 ,
int V_205 )
{
switch ( V_205 ) {
case V_206 :
return F_257 ( V_34 ) ;
case V_208 :
return F_258 ( V_34 ) ;
}
return NULL ;
}
static void F_259 ( struct V_84 * V_84 , struct V_108 * V_118 ,
int V_194 )
{
struct V_35 * V_34 ;
int V_205 = F_260 ( V_118 ) ;
F_118 () ;
F_261 (net, dev) {
struct V_108 * V_382 =
F_256 ( V_34 , V_205 ) ;
if ( V_382 && ! F_262 ( V_194 , V_382 -> V_383 ) )
V_382 -> V_381 [ V_194 ] = V_118 -> V_381 [ V_194 ] ;
}
F_120 () ;
}
static void F_263 ( struct V_370 * V_371 , int V_372 )
{
struct V_35 * V_34 = V_371 -> V_377 ;
struct V_108 * V_118 = V_371 -> V_379 ;
struct V_84 * V_84 = F_148 ( V_118 ) ;
int V_194 = ( int * ) V_371 -> V_381 - V_118 -> V_381 ;
if ( ! V_372 )
return;
F_264 ( V_194 , V_118 -> V_383 ) ;
if ( ! V_34 )
F_259 ( V_84 , V_118 , V_194 ) ;
}
static int F_265 ( struct V_370 * V_371 , int V_372 ,
void T_9 * V_373 ,
T_3 * V_374 , T_7 * V_375 )
{
struct V_370 V_376 = * V_371 ;
int V_64 ;
V_376 . V_377 = & V_378 ;
V_376 . V_379 = & V_384 ;
V_64 = F_255 ( & V_376 , V_372 , V_373 , V_374 , V_375 ) ;
F_263 ( V_371 , V_372 ) ;
return V_64 ;
}
int F_266 ( struct V_370 * V_371 , int V_372 ,
void T_9 * V_373 , T_3 * V_374 , T_7 * V_375 )
{
int V_64 = F_267 ( V_371 , V_372 , V_373 , V_374 , V_375 ) ;
F_263 ( V_371 , V_372 ) ;
return V_64 ;
}
int F_268 ( struct V_370 * V_371 , int V_372 ,
void T_9 * V_373 ,
T_3 * V_374 , T_7 * V_375 )
{
int V_64 = F_269 ( V_371 , V_372 , V_373 , V_374 , V_375 ) ;
F_263 ( V_371 , V_372 ) ;
return V_64 ;
}
static int F_270 ( struct V_370 * V_371 , int V_372 ,
void T_9 * V_373 ,
T_3 * V_374 , T_7 * V_375 )
{
int V_64 = F_271 ( V_371 , V_372 , V_373 , V_374 , V_375 ) ;
F_263 ( V_371 , V_372 ) ;
return V_64 ;
}
int F_272 ( struct V_370 * V_371 , int V_372 ,
void T_9 * V_373 ,
T_3 * V_374 , T_7 * V_375 )
{
int V_64 = F_273 ( V_371 , V_372 , V_373 , V_374 , V_375 ) ;
F_263 ( V_371 , V_372 ) ;
return V_64 ;
}
static int F_274 ( struct V_370 * V_371 , int V_372 ,
void T_9 * V_373 ,
T_3 * V_374 , T_7 * V_375 )
{
int V_64 = F_254 ( V_371 , V_372 , V_373 , V_374 , V_375 ) ;
F_263 ( V_371 , V_372 ) ;
return V_64 ;
}
static int F_275 ( struct V_370 * V_371 , int V_372 ,
void T_9 * V_373 ,
T_3 * V_374 , T_7 * V_375 )
{
struct V_108 * V_118 = V_371 -> V_379 ;
int V_64 ;
if ( strcmp ( V_371 -> V_385 , L_22 ) == 0 )
V_64 = F_268 ( V_371 , V_372 , V_373 , V_374 , V_375 ) ;
else if ( strcmp ( V_371 -> V_385 , L_23 ) == 0 )
V_64 = F_272 ( V_371 , V_372 , V_373 , V_374 , V_375 ) ;
else
V_64 = - 1 ;
if ( V_372 && V_64 == 0 ) {
V_118 -> V_119 =
F_6 ( F_70 ( V_118 , V_95 ) ) ;
}
return V_64 ;
}
int F_276 ( struct V_35 * V_34 , struct V_108 * V_118 ,
T_10 * V_386 )
{
int V_13 ;
struct V_387 * V_341 ;
const char * V_388 ;
char V_389 [ sizeof( L_24 ) + V_390 + V_390 ] ;
char * V_391 ;
V_341 = F_150 ( & V_392 , sizeof( * V_341 ) , V_103 ) ;
if ( ! V_341 )
goto V_159;
for ( V_13 = 0 ; V_13 < V_393 ; V_13 ++ ) {
V_341 -> V_394 [ V_13 ] . V_381 += ( long ) V_118 ;
V_341 -> V_394 [ V_13 ] . V_377 = V_34 ;
V_341 -> V_394 [ V_13 ] . V_379 = V_118 ;
}
if ( V_34 ) {
V_388 = V_34 -> V_395 ;
memset ( & V_341 -> V_394 [ V_393 ] , 0 ,
sizeof( V_341 -> V_394 [ V_393 ] ) ) ;
} else {
struct V_10 * V_11 = V_118 -> V_11 ;
V_388 = L_25 ;
V_341 -> V_394 [ V_393 ] . V_381 = & V_11 -> V_267 ;
V_341 -> V_394 [ V_396 ] . V_381 = & V_11 -> V_120 ;
V_341 -> V_394 [ V_397 ] . V_381 = & V_11 -> V_47 ;
V_341 -> V_394 [ V_398 ] . V_381 = & V_11 -> V_46 ;
}
if ( V_386 ) {
V_341 -> V_394 [ V_399 ] . T_10 = V_386 ;
V_341 -> V_394 [ V_400 ] . T_10 = V_386 ;
V_341 -> V_394 [ V_401 ] . T_10 = V_386 ;
V_341 -> V_394 [ V_402 ] . T_10 = V_386 ;
} else {
V_341 -> V_394 [ V_400 ] . T_10 =
F_275 ;
V_341 -> V_394 [ V_402 ] . T_10 =
F_275 ;
}
if ( F_148 ( V_118 ) -> V_403 != & V_404 )
V_341 -> V_394 [ 0 ] . V_385 = NULL ;
switch ( F_260 ( V_118 ) ) {
case V_206 :
V_391 = L_26 ;
break;
case V_208 :
V_391 = L_27 ;
break;
default:
F_277 () ;
}
snprintf ( V_389 , sizeof( V_389 ) , L_28 ,
V_391 , V_388 ) ;
V_341 -> V_405 =
F_278 ( F_148 ( V_118 ) , V_389 , V_341 -> V_394 ) ;
if ( ! V_341 -> V_405 )
goto free;
V_118 -> V_192 = V_341 ;
return 0 ;
free:
F_53 ( V_341 ) ;
V_159:
return - V_88 ;
}
void F_279 ( struct V_108 * V_118 )
{
if ( V_118 -> V_192 ) {
struct V_387 * V_341 = V_118 -> V_192 ;
V_118 -> V_192 = NULL ;
F_280 ( V_341 -> V_405 ) ;
F_53 ( V_341 ) ;
}
}
static int T_11 F_281 ( void )
{
F_282 ( V_406 , V_337 , F_182 , NULL , NULL ) ;
F_282 ( V_406 , V_8 , F_174 , NULL , NULL ) ;
F_282 ( V_406 , V_368 , NULL , F_222 , NULL ) ;
F_282 ( V_406 , V_407 , NULL , F_211 ,
NULL ) ;
F_282 ( V_406 , V_408 , F_205 , NULL , NULL ) ;
return 0 ;
}
