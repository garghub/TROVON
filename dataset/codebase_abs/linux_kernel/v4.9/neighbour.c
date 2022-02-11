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
V_45 >= V_11 -> V_46 ) {
F_39 ( L_3 ,
V_11 -> V_49 ) ;
F_9 ( V_11 , V_50 ) ;
goto V_51;
}
}
V_19 = F_40 ( V_11 -> V_52 + V_34 -> V_53 , V_54 ) ;
if ( ! V_19 )
goto V_51;
F_41 ( & V_19 -> V_36 ) ;
F_42 ( & V_19 -> V_17 ) ;
F_43 ( & V_19 -> V_55 ) ;
V_19 -> V_56 = V_19 -> V_57 = V_44 ;
V_19 -> V_23 = V_41 ;
V_19 -> V_38 = F_1 ;
F_43 ( & V_19 -> V_58 . V_59 ) ;
V_19 -> V_6 = F_44 ( & V_11 -> V_6 ) ;
F_45 ( & V_19 -> V_30 , V_60 , ( unsigned long ) V_19 ) ;
F_9 ( V_11 , V_61 ) ;
V_19 -> V_11 = V_11 ;
F_46 ( & V_19 -> V_22 , 1 ) ;
V_19 -> V_26 = 1 ;
V_62:
return V_19 ;
V_51:
F_47 ( & V_11 -> V_45 ) ;
goto V_62;
}
static void F_48 ( T_2 * V_63 )
{
F_49 ( V_63 , sizeof( * V_63 ) ) ;
* V_63 |= 1 ;
}
static struct V_14 * F_50 ( unsigned int V_64 )
{
T_3 V_65 = ( 1 << V_64 ) * sizeof( struct V_1 * ) ;
struct V_14 * V_66 ;
struct V_1 T_1 * * V_67 ;
int V_13 ;
V_66 = F_51 ( sizeof( * V_66 ) , V_54 ) ;
if ( ! V_66 )
return NULL ;
if ( V_65 <= V_68 )
V_67 = F_40 ( V_65 , V_54 ) ;
else
V_67 = (struct V_1 T_1 * * )
F_52 ( V_54 | V_69 ,
F_53 ( V_65 ) ) ;
if ( ! V_67 ) {
F_54 ( V_66 ) ;
return NULL ;
}
V_66 -> V_21 = V_67 ;
V_66 -> V_18 = V_64 ;
for ( V_13 = 0 ; V_13 < V_70 ; V_13 ++ )
F_48 ( & V_66 -> V_71 [ V_13 ] ) ;
return V_66 ;
}
static void F_55 ( struct V_72 * V_73 )
{
struct V_14 * V_15 = F_56 ( V_73 ,
struct V_14 ,
V_74 ) ;
T_3 V_65 = ( 1 << V_15 -> V_18 ) * sizeof( struct V_1 * ) ;
struct V_1 T_1 * * V_67 = V_15 -> V_21 ;
if ( V_65 <= V_68 )
F_54 ( V_67 ) ;
else
F_57 ( ( unsigned long ) V_67 , F_53 ( V_65 ) ) ;
F_54 ( V_15 ) ;
}
static struct V_14 * F_58 ( struct V_10 * V_11 ,
unsigned long V_75 )
{
unsigned int V_13 , V_76 ;
struct V_14 * V_77 , * V_78 ;
F_9 ( V_11 , V_79 ) ;
V_78 = F_11 ( V_11 -> V_15 ,
F_12 ( & V_11 -> V_17 ) ) ;
V_77 = F_50 ( V_75 ) ;
if ( ! V_77 )
return V_78 ;
for ( V_13 = 0 ; V_13 < ( 1 << V_78 -> V_18 ) ; V_13 ++ ) {
struct V_1 * V_19 , * V_25 ;
for ( V_19 = F_11 ( V_78 -> V_21 [ V_13 ] ,
F_12 ( & V_11 -> V_17 ) ) ;
V_19 != NULL ;
V_19 = V_25 ) {
V_76 = V_11 -> V_76 ( V_19 -> V_80 , V_19 -> V_34 ,
V_77 -> V_71 ) ;
V_76 >>= ( 32 - V_77 -> V_18 ) ;
V_25 = F_11 ( V_19 -> V_25 ,
F_12 ( & V_11 -> V_17 ) ) ;
F_15 ( V_19 -> V_25 ,
F_11 (
V_77 -> V_21 [ V_76 ] ,
F_12 ( & V_11 -> V_17 ) ) ) ;
F_15 ( V_77 -> V_21 [ V_76 ] , V_19 ) ;
}
}
F_15 ( V_11 -> V_15 , V_77 ) ;
F_59 ( & V_78 -> V_74 , F_55 ) ;
return V_77 ;
}
struct V_1 * F_60 ( struct V_10 * V_11 , const void * V_81 ,
struct V_35 * V_34 )
{
struct V_1 * V_19 ;
F_9 ( V_11 , V_82 ) ;
F_61 () ;
V_19 = F_62 ( V_11 , V_81 , V_34 ) ;
if ( V_19 ) {
if ( ! F_63 ( & V_19 -> V_22 ) )
V_19 = NULL ;
F_9 ( V_11 , V_83 ) ;
}
F_64 () ;
return V_19 ;
}
struct V_1 * F_65 ( struct V_10 * V_11 , struct V_84 * V_84 ,
const void * V_81 )
{
struct V_1 * V_19 ;
int V_85 = V_11 -> V_85 ;
T_2 V_86 ;
struct V_14 * V_15 ;
F_9 ( V_11 , V_82 ) ;
F_61 () ;
V_15 = F_66 ( V_11 -> V_15 ) ;
V_86 = V_11 -> V_76 ( V_81 , NULL , V_15 -> V_71 ) >> ( 32 - V_15 -> V_18 ) ;
for ( V_19 = F_66 ( V_15 -> V_21 [ V_86 ] ) ;
V_19 != NULL ;
V_19 = F_66 ( V_19 -> V_25 ) ) {
if ( ! memcmp ( V_19 -> V_80 , V_81 , V_85 ) &&
F_67 ( F_68 ( V_19 -> V_34 ) , V_84 ) ) {
if ( ! F_63 ( & V_19 -> V_22 ) )
V_19 = NULL ;
F_9 ( V_11 , V_83 ) ;
break;
}
}
F_64 () ;
return V_19 ;
}
struct V_1 * F_69 ( struct V_10 * V_11 , const void * V_81 ,
struct V_35 * V_34 , bool V_87 )
{
T_2 V_86 ;
int V_85 = V_11 -> V_85 ;
int error ;
struct V_1 * V_88 , * V_89 , * V_19 = F_36 ( V_11 , V_34 ) ;
struct V_14 * V_15 ;
if ( ! V_19 ) {
V_89 = F_70 ( - V_90 ) ;
goto V_62;
}
memcpy ( V_19 -> V_80 , V_81 , V_85 ) ;
V_19 -> V_34 = V_34 ;
F_71 ( V_34 ) ;
if ( V_11 -> V_91 && ( error = V_11 -> V_91 ( V_19 ) ) < 0 ) {
V_89 = F_70 ( error ) ;
goto V_92;
}
if ( V_34 -> V_93 -> V_94 ) {
error = V_34 -> V_93 -> V_94 ( V_34 , V_19 ) ;
if ( error < 0 ) {
V_89 = F_70 ( error ) ;
goto V_92;
}
}
if ( V_19 -> V_6 -> V_95 &&
( error = V_19 -> V_6 -> V_95 ( V_19 ) ) < 0 ) {
V_89 = F_70 ( error ) ;
goto V_92;
}
V_19 -> V_96 = V_28 - ( F_72 ( V_19 -> V_6 , V_97 ) << 1 ) ;
F_10 ( & V_11 -> V_17 ) ;
V_15 = F_11 ( V_11 -> V_15 ,
F_12 ( & V_11 -> V_17 ) ) ;
if ( F_14 ( & V_11 -> V_45 ) > ( 1 << V_15 -> V_18 ) )
V_15 = F_58 ( V_11 , V_15 -> V_18 + 1 ) ;
V_86 = V_11 -> V_76 ( V_81 , V_34 , V_15 -> V_71 ) >> ( 32 - V_15 -> V_18 ) ;
if ( V_19 -> V_6 -> V_26 ) {
V_89 = F_70 ( - V_98 ) ;
goto V_99;
}
for ( V_88 = F_11 ( V_15 -> V_21 [ V_86 ] ,
F_12 ( & V_11 -> V_17 ) ) ;
V_88 != NULL ;
V_88 = F_11 ( V_88 -> V_25 ,
F_12 ( & V_11 -> V_17 ) ) ) {
if ( V_34 == V_88 -> V_34 && ! memcmp ( V_88 -> V_80 , V_81 , V_85 ) ) {
if ( V_87 )
F_19 ( V_88 ) ;
V_89 = V_88 ;
goto V_99;
}
}
V_19 -> V_26 = 0 ;
if ( V_87 )
F_19 ( V_19 ) ;
F_15 ( V_19 -> V_25 ,
F_11 ( V_15 -> V_21 [ V_86 ] ,
F_12 ( & V_11 -> V_17 ) ) ) ;
F_15 ( V_15 -> V_21 [ V_86 ] , V_19 ) ;
F_17 ( & V_11 -> V_17 ) ;
F_31 ( 2 , L_4 , V_19 ) ;
V_89 = V_19 ;
V_62:
return V_89 ;
V_99:
F_17 ( & V_11 -> V_17 ) ;
V_92:
F_5 ( V_19 ) ;
goto V_62;
}
static T_2 F_73 ( const void * V_81 , int V_85 )
{
T_2 V_86 = * ( T_2 * ) ( V_81 + V_85 - 4 ) ;
V_86 ^= ( V_86 >> 16 ) ;
V_86 ^= V_86 >> 8 ;
V_86 ^= V_86 >> 4 ;
V_86 &= V_100 ;
return V_86 ;
}
static struct V_101 * F_74 ( struct V_101 * V_19 ,
struct V_84 * V_84 ,
const void * V_81 ,
int V_85 ,
struct V_35 * V_34 )
{
while ( V_19 ) {
if ( ! memcmp ( V_19 -> V_102 , V_81 , V_85 ) &&
F_67 ( F_75 ( V_19 ) , V_84 ) &&
( V_19 -> V_34 == V_34 || ! V_19 -> V_34 ) )
return V_19 ;
V_19 = V_19 -> V_25 ;
}
return NULL ;
}
struct V_101 * F_76 ( struct V_10 * V_11 ,
struct V_84 * V_84 , const void * V_81 , struct V_35 * V_34 )
{
int V_85 = V_11 -> V_85 ;
T_2 V_86 = F_73 ( V_81 , V_85 ) ;
return F_74 ( V_11 -> V_103 [ V_86 ] ,
V_84 , V_81 , V_85 , V_34 ) ;
}
struct V_101 * F_77 ( struct V_10 * V_11 ,
struct V_84 * V_84 , const void * V_81 ,
struct V_35 * V_34 , int V_104 )
{
struct V_101 * V_19 ;
int V_85 = V_11 -> V_85 ;
T_2 V_86 = F_73 ( V_81 , V_85 ) ;
F_78 ( & V_11 -> V_17 ) ;
V_19 = F_74 ( V_11 -> V_103 [ V_86 ] ,
V_84 , V_81 , V_85 , V_34 ) ;
F_79 ( & V_11 -> V_17 ) ;
if ( V_19 || ! V_104 )
goto V_62;
F_80 () ;
V_19 = F_51 ( sizeof( * V_19 ) + V_85 , V_105 ) ;
if ( ! V_19 )
goto V_62;
F_81 ( & V_19 -> V_84 , V_84 ) ;
memcpy ( V_19 -> V_102 , V_81 , V_85 ) ;
V_19 -> V_34 = V_34 ;
if ( V_34 )
F_71 ( V_34 ) ;
if ( V_11 -> V_106 && V_11 -> V_106 ( V_19 ) ) {
if ( V_34 )
F_28 ( V_34 ) ;
F_54 ( V_19 ) ;
V_19 = NULL ;
goto V_62;
}
F_10 ( & V_11 -> V_17 ) ;
V_19 -> V_25 = V_11 -> V_103 [ V_86 ] ;
V_11 -> V_103 [ V_86 ] = V_19 ;
F_17 ( & V_11 -> V_17 ) ;
V_62:
return V_19 ;
}
int F_82 ( struct V_10 * V_11 , struct V_84 * V_84 , const void * V_81 ,
struct V_35 * V_34 )
{
struct V_101 * V_19 , * * V_20 ;
int V_85 = V_11 -> V_85 ;
T_2 V_86 = F_73 ( V_81 , V_85 ) ;
F_10 ( & V_11 -> V_17 ) ;
for ( V_20 = & V_11 -> V_103 [ V_86 ] ; ( V_19 = * V_20 ) != NULL ;
V_20 = & V_19 -> V_25 ) {
if ( ! memcmp ( V_19 -> V_102 , V_81 , V_85 ) && V_19 -> V_34 == V_34 &&
F_67 ( F_75 ( V_19 ) , V_84 ) ) {
* V_20 = V_19 -> V_25 ;
F_17 ( & V_11 -> V_17 ) ;
if ( V_11 -> V_107 )
V_11 -> V_107 ( V_19 ) ;
if ( V_19 -> V_34 )
F_28 ( V_19 -> V_34 ) ;
F_54 ( V_19 ) ;
return 0 ;
}
}
F_17 ( & V_11 -> V_17 ) ;
return - V_108 ;
}
static int F_34 ( struct V_10 * V_11 , struct V_35 * V_34 )
{
struct V_101 * V_19 , * * V_20 ;
T_2 V_109 ;
for ( V_109 = 0 ; V_109 <= V_100 ; V_109 ++ ) {
V_20 = & V_11 -> V_103 [ V_109 ] ;
while ( ( V_19 = * V_20 ) != NULL ) {
if ( ! V_34 || V_19 -> V_34 == V_34 ) {
* V_20 = V_19 -> V_25 ;
if ( V_11 -> V_107 )
V_11 -> V_107 ( V_19 ) ;
if ( V_19 -> V_34 )
F_28 ( V_19 -> V_34 ) ;
F_54 ( V_19 ) ;
continue;
}
V_20 = & V_19 -> V_25 ;
}
}
return - V_108 ;
}
static inline void F_83 ( struct V_110 * V_6 )
{
if ( F_84 ( & V_6 -> V_22 ) )
F_85 ( V_6 ) ;
}
void F_86 ( struct V_1 * V_2 )
{
struct V_35 * V_34 = V_2 -> V_34 ;
F_9 ( V_2 -> V_11 , V_111 ) ;
if ( ! V_2 -> V_26 ) {
F_87 ( L_5 , V_2 ) ;
F_23 () ;
return;
}
if ( F_24 ( V_2 ) )
F_87 ( L_6 ) ;
F_10 ( & V_2 -> V_17 ) ;
F_30 ( & V_2 -> V_36 ) ;
F_17 ( & V_2 -> V_17 ) ;
V_2 -> V_37 = 0 ;
if ( V_34 -> V_93 -> V_112 )
V_34 -> V_93 -> V_112 ( V_34 , V_2 ) ;
F_28 ( V_34 ) ;
F_83 ( V_2 -> V_6 ) ;
F_31 ( 2 , L_7 , V_2 ) ;
F_47 ( & V_2 -> V_11 -> V_45 ) ;
F_88 ( V_2 , V_74 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
F_31 ( 2 , L_8 , V_2 ) ;
V_2 -> V_38 = V_2 -> V_113 -> V_38 ;
}
static void F_90 ( struct V_1 * V_2 )
{
F_31 ( 2 , L_9 , V_2 ) ;
V_2 -> V_38 = V_2 -> V_113 -> V_114 ;
}
static void F_91 ( struct V_115 * V_116 )
{
struct V_10 * V_11 = F_56 ( V_116 , struct V_10 , V_117 . V_116 ) ;
struct V_1 * V_19 ;
struct V_1 T_1 * * V_20 ;
unsigned int V_13 ;
struct V_14 * V_15 ;
F_9 ( V_11 , V_118 ) ;
F_10 ( & V_11 -> V_17 ) ;
V_15 = F_11 ( V_11 -> V_15 ,
F_12 ( & V_11 -> V_17 ) ) ;
if ( F_38 ( V_28 , V_11 -> V_119 + 300 * V_48 ) ) {
struct V_110 * V_120 ;
V_11 -> V_119 = V_28 ;
F_92 (p, &tbl->parms_list, list)
V_120 -> V_121 =
F_6 ( F_72 ( V_120 , V_97 ) ) ;
}
if ( F_14 ( & V_11 -> V_45 ) < V_11 -> V_122 )
goto V_62;
for ( V_13 = 0 ; V_13 < ( 1 << V_15 -> V_18 ) ; V_13 ++ ) {
V_20 = & V_15 -> V_21 [ V_13 ] ;
while ( ( V_19 = F_11 ( * V_20 ,
F_12 ( & V_11 -> V_17 ) ) ) != NULL ) {
unsigned int V_123 ;
F_13 ( & V_19 -> V_17 ) ;
V_123 = V_19 -> V_23 ;
if ( V_123 & ( V_24 | V_31 ) ) {
F_16 ( & V_19 -> V_17 ) ;
goto V_124;
}
if ( F_93 ( V_19 -> V_57 , V_19 -> V_96 ) )
V_19 -> V_57 = V_19 -> V_96 ;
if ( F_14 ( & V_19 -> V_22 ) == 1 &&
( V_123 == V_125 ||
F_38 ( V_28 , V_19 -> V_57 + F_72 ( V_19 -> V_6 , V_126 ) ) ) ) {
* V_20 = V_19 -> V_25 ;
V_19 -> V_26 = 1 ;
F_16 ( & V_19 -> V_17 ) ;
F_3 ( V_19 ) ;
continue;
}
F_16 ( & V_19 -> V_17 ) ;
V_124:
V_20 = & V_19 -> V_25 ;
}
F_17 ( & V_11 -> V_17 ) ;
F_94 () ;
F_10 ( & V_11 -> V_17 ) ;
V_15 = F_11 ( V_11 -> V_15 ,
F_12 ( & V_11 -> V_17 ) ) ;
}
V_62:
F_95 ( V_127 , & V_11 -> V_117 ,
F_72 ( & V_11 -> V_6 , V_97 ) >> 1 ) ;
F_17 ( & V_11 -> V_17 ) ;
}
static T_4 int F_96 ( struct V_1 * V_19 )
{
struct V_110 * V_120 = V_19 -> V_6 ;
return F_72 ( V_120 , V_128 ) + F_72 ( V_120 , V_129 ) +
( V_19 -> V_23 & V_130 ? F_72 ( V_120 , V_131 ) :
F_72 ( V_120 , V_132 ) ) ;
}
static void F_97 ( struct V_1 * V_2 )
__releases( V_2 -> V_17 )
__acquires( V_2 -> V_17 )
{
struct V_3 * V_4 ;
F_9 ( V_2 -> V_11 , V_133 ) ;
F_31 ( 2 , L_10 , V_2 ) ;
V_2 -> V_56 = V_28 ;
while ( V_2 -> V_23 == V_125 &&
( V_4 = F_98 ( & V_2 -> V_36 ) ) != NULL ) {
F_16 ( & V_2 -> V_17 ) ;
V_2 -> V_113 -> V_134 ( V_2 , V_4 ) ;
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
V_4 = F_101 ( V_4 , V_54 ) ;
F_16 ( & V_2 -> V_17 ) ;
V_2 -> V_113 -> V_135 ( V_2 , V_4 ) ;
F_102 ( & V_2 -> V_136 ) ;
F_2 ( V_4 ) ;
}
static void V_60 ( unsigned long V_137 )
{
unsigned long V_44 , V_25 ;
struct V_1 * V_2 = (struct V_1 * ) V_137 ;
unsigned int V_123 ;
int V_138 = 0 ;
F_13 ( & V_2 -> V_17 ) ;
V_123 = V_2 -> V_23 ;
V_44 = V_28 ;
V_25 = V_44 + V_48 ;
if ( ! ( V_123 & V_31 ) )
goto V_62;
if ( V_123 & V_139 ) {
if ( F_103 ( V_44 ,
V_2 -> V_96 + V_2 -> V_6 -> V_121 ) ) {
F_31 ( 2 , L_11 , V_2 ) ;
V_25 = V_2 -> V_96 + V_2 -> V_6 -> V_121 ;
} else if ( F_103 ( V_44 ,
V_2 -> V_57 +
F_72 ( V_2 -> V_6 , V_140 ) ) ) {
F_31 ( 2 , L_12 , V_2 ) ;
V_2 -> V_23 = V_141 ;
V_2 -> V_56 = V_28 ;
F_89 ( V_2 ) ;
V_25 = V_44 + F_72 ( V_2 -> V_6 , V_140 ) ;
} else {
F_31 ( 2 , L_8 , V_2 ) ;
V_2 -> V_23 = V_142 ;
V_2 -> V_56 = V_28 ;
F_89 ( V_2 ) ;
V_138 = 1 ;
}
} else if ( V_123 & V_141 ) {
if ( F_103 ( V_44 ,
V_2 -> V_96 +
F_72 ( V_2 -> V_6 , V_140 ) ) ) {
F_31 ( 2 , L_13 , V_2 ) ;
V_2 -> V_23 = V_139 ;
V_2 -> V_56 = V_28 ;
F_90 ( V_2 ) ;
V_138 = 1 ;
V_25 = V_2 -> V_96 + V_2 -> V_6 -> V_121 ;
} else {
F_31 ( 2 , L_14 , V_2 ) ;
V_2 -> V_23 = V_130 ;
V_2 -> V_56 = V_28 ;
F_46 ( & V_2 -> V_136 , 0 ) ;
V_138 = 1 ;
V_25 = V_44 + F_72 ( V_2 -> V_6 , V_143 ) ;
}
} else {
V_25 = V_44 + F_72 ( V_2 -> V_6 , V_143 ) ;
}
if ( ( V_2 -> V_23 & ( V_144 | V_130 ) ) &&
F_14 ( & V_2 -> V_136 ) >= F_96 ( V_2 ) ) {
V_2 -> V_23 = V_125 ;
V_138 = 1 ;
F_97 ( V_2 ) ;
goto V_62;
}
if ( V_2 -> V_23 & V_31 ) {
if ( F_93 ( V_25 , V_28 + V_48 / 2 ) )
V_25 = V_28 + V_48 / 2 ;
if ( ! F_21 ( & V_2 -> V_30 , V_25 ) )
F_19 ( V_2 ) ;
}
if ( V_2 -> V_23 & ( V_144 | V_130 ) ) {
F_99 ( V_2 ) ;
} else {
V_62:
F_16 ( & V_2 -> V_17 ) ;
}
if ( V_138 )
F_104 ( V_2 ) ;
F_5 ( V_2 ) ;
}
int F_105 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_89 ;
bool V_145 = false ;
F_10 ( & V_2 -> V_17 ) ;
V_89 = 0 ;
if ( V_2 -> V_23 & ( V_146 | V_141 | V_130 ) )
goto V_147;
if ( V_2 -> V_26 )
goto V_148;
if ( ! ( V_2 -> V_23 & ( V_142 | V_144 ) ) ) {
if ( F_72 ( V_2 -> V_6 , V_132 ) +
F_72 ( V_2 -> V_6 , V_129 ) ) {
unsigned long V_25 , V_44 = V_28 ;
F_46 ( & V_2 -> V_136 ,
F_72 ( V_2 -> V_6 , V_128 ) ) ;
V_2 -> V_23 = V_144 ;
V_2 -> V_56 = V_44 ;
V_25 = V_44 + F_106 ( F_72 ( V_2 -> V_6 , V_143 ) ,
V_48 / 2 ) ;
F_18 ( V_2 , V_25 ) ;
V_145 = true ;
} else {
V_2 -> V_23 = V_125 ;
V_2 -> V_56 = V_28 ;
F_17 ( & V_2 -> V_17 ) ;
F_2 ( V_4 ) ;
return 1 ;
}
} else if ( V_2 -> V_23 & V_142 ) {
F_31 ( 2 , L_12 , V_2 ) ;
V_2 -> V_23 = V_141 ;
V_2 -> V_56 = V_28 ;
F_18 ( V_2 , V_28 +
F_72 ( V_2 -> V_6 , V_140 ) ) ;
}
if ( V_2 -> V_23 == V_144 ) {
if ( V_4 ) {
while ( V_2 -> V_37 + V_4 -> V_149 >
F_72 ( V_2 -> V_6 , V_150 ) ) {
struct V_3 * V_151 ;
V_151 = F_98 ( & V_2 -> V_36 ) ;
if ( ! V_151 )
break;
V_2 -> V_37 -= V_151 -> V_149 ;
F_2 ( V_151 ) ;
F_9 ( V_2 -> V_11 , V_152 ) ;
}
F_107 ( V_4 ) ;
F_108 ( & V_2 -> V_36 , V_4 ) ;
V_2 -> V_37 += V_4 -> V_149 ;
}
V_89 = 1 ;
}
V_147:
if ( V_145 )
F_99 ( V_2 ) ;
else
F_16 ( & V_2 -> V_17 ) ;
F_109 () ;
return V_89 ;
V_148:
if ( V_2 -> V_23 & V_142 )
goto V_147;
F_17 ( & V_2 -> V_17 ) ;
F_2 ( V_4 ) ;
return 1 ;
}
static void F_110 ( struct V_1 * V_2 )
{
struct V_153 * V_58 ;
void (* F_111)( struct V_153 * , const struct V_35 * , const unsigned char * )
= NULL ;
if ( V_2 -> V_34 -> V_154 )
F_111 = V_2 -> V_34 -> V_154 -> V_155 ;
if ( F_111 ) {
V_58 = & V_2 -> V_58 ;
if ( V_58 -> V_156 ) {
F_112 ( & V_58 -> V_59 ) ;
F_111 ( V_58 , V_2 -> V_34 , V_2 -> V_157 ) ;
F_113 ( & V_58 -> V_59 ) ;
}
}
}
int F_114 ( struct V_1 * V_2 , const T_5 * V_158 , T_5 V_159 ,
T_2 V_160 )
{
T_5 V_161 ;
int V_162 ;
int V_138 = 0 ;
struct V_35 * V_34 ;
int V_163 = 0 ;
F_10 ( & V_2 -> V_17 ) ;
V_34 = V_2 -> V_34 ;
V_161 = V_2 -> V_23 ;
V_162 = - V_164 ;
if ( ! ( V_160 & V_165 ) &&
( V_161 & ( V_40 | V_24 ) ) )
goto V_62;
if ( V_2 -> V_26 )
goto V_62;
if ( ! ( V_159 & V_39 ) ) {
F_24 ( V_2 ) ;
if ( V_161 & V_146 )
F_89 ( V_2 ) ;
V_2 -> V_23 = V_159 ;
V_162 = 0 ;
V_138 = V_161 & V_39 ;
if ( ( V_161 & ( V_144 | V_130 ) ) &&
( V_159 & V_125 ) ) {
F_97 ( V_2 ) ;
V_138 = 1 ;
}
goto V_62;
}
if ( ! V_34 -> V_166 ) {
V_158 = V_2 -> V_157 ;
} else if ( V_158 ) {
if ( ( V_161 & V_39 ) &&
! memcmp ( V_158 , V_2 -> V_157 , V_34 -> V_166 ) )
V_158 = V_2 -> V_157 ;
} else {
V_162 = - V_98 ;
if ( ! ( V_161 & V_39 ) )
goto V_62;
V_158 = V_2 -> V_157 ;
}
if ( V_159 & V_146 )
V_2 -> V_96 = V_28 ;
V_2 -> V_56 = V_28 ;
V_162 = 0 ;
V_163 = V_160 & V_167 ;
if ( V_161 & V_39 ) {
if ( V_158 != V_2 -> V_157 && ! ( V_160 & V_168 ) ) {
V_163 = 0 ;
if ( ( V_160 & V_169 ) &&
( V_161 & V_146 ) ) {
V_158 = V_2 -> V_157 ;
V_159 = V_142 ;
} else
goto V_62;
} else {
if ( V_158 == V_2 -> V_157 && V_159 == V_142 &&
! ( V_160 & V_165 ) )
V_159 = V_161 ;
}
}
if ( V_159 != V_161 ) {
F_24 ( V_2 ) ;
if ( V_159 & V_130 )
F_46 ( & V_2 -> V_136 , 0 ) ;
if ( V_159 & V_31 )
F_18 ( V_2 , ( V_28 +
( ( V_159 & V_139 ) ?
V_2 -> V_6 -> V_121 :
0 ) ) ) ;
V_2 -> V_23 = V_159 ;
V_138 = 1 ;
}
if ( V_158 != V_2 -> V_157 ) {
F_115 ( & V_2 -> V_55 ) ;
memcpy ( & V_2 -> V_157 , V_158 , V_34 -> V_166 ) ;
F_116 ( & V_2 -> V_55 ) ;
F_110 ( V_2 ) ;
if ( ! ( V_159 & V_146 ) )
V_2 -> V_96 = V_28 -
( F_72 ( V_2 -> V_6 , V_97 ) << 1 ) ;
V_138 = 1 ;
}
if ( V_159 == V_161 )
goto V_62;
if ( V_159 & V_146 )
F_90 ( V_2 ) ;
else
F_89 ( V_2 ) ;
if ( ! ( V_161 & V_39 ) ) {
struct V_3 * V_4 ;
while ( V_2 -> V_23 & V_39 &&
( V_4 = F_98 ( & V_2 -> V_36 ) ) != NULL ) {
struct V_170 * V_171 = F_117 ( V_4 ) ;
struct V_1 * V_172 , * V_88 = V_2 ;
F_17 ( & V_2 -> V_17 ) ;
F_118 () ;
V_172 = NULL ;
if ( V_171 ) {
V_172 = F_119 ( V_171 , V_4 ) ;
if ( V_172 )
V_88 = V_172 ;
}
V_88 -> V_38 ( V_88 , V_4 ) ;
if ( V_172 )
F_5 ( V_172 ) ;
F_120 () ;
F_10 ( & V_2 -> V_17 ) ;
}
F_30 ( & V_2 -> V_36 ) ;
V_2 -> V_37 = 0 ;
}
V_62:
if ( V_163 ) {
V_2 -> V_160 = ( V_160 & V_173 ) ?
( V_2 -> V_160 | V_174 ) :
( V_2 -> V_160 & ~ V_174 ) ;
}
F_17 ( & V_2 -> V_17 ) ;
if ( V_138 )
F_104 ( V_2 ) ;
return V_162 ;
}
void F_121 ( struct V_1 * V_2 )
{
if ( V_2 -> V_26 )
return;
V_2 -> V_56 = V_28 ;
if ( ! ( V_2 -> V_23 & V_125 ) )
return;
V_2 -> V_23 = V_144 ;
F_46 ( & V_2 -> V_136 , F_96 ( V_2 ) ) ;
F_18 ( V_2 ,
V_28 + F_72 ( V_2 -> V_6 , V_143 ) ) ;
}
struct V_1 * F_122 ( struct V_10 * V_11 ,
T_5 * V_158 , void * V_175 ,
struct V_35 * V_34 )
{
struct V_1 * V_2 = F_123 ( V_11 , V_175 , V_34 ,
V_158 || ! V_34 -> V_166 ) ;
if ( V_2 )
F_114 ( V_2 , V_158 , V_142 ,
V_168 ) ;
return V_2 ;
}
static void F_124 ( struct V_1 * V_19 )
{
struct V_35 * V_34 = V_19 -> V_34 ;
T_6 V_176 = V_19 -> V_11 -> V_177 ;
struct V_153 * V_58 = & V_19 -> V_58 ;
F_10 ( & V_19 -> V_17 ) ;
if ( ! V_58 -> V_156 )
V_34 -> V_154 -> V_178 ( V_19 , V_58 , V_176 ) ;
F_17 ( & V_19 -> V_17 ) ;
}
int F_125 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_89 = 0 ;
if ( ! F_126 ( V_2 , V_4 ) ) {
int V_162 ;
struct V_35 * V_34 = V_2 -> V_34 ;
unsigned int V_179 ;
if ( V_34 -> V_154 -> V_178 && ! V_2 -> V_58 . V_156 )
F_124 ( V_2 ) ;
do {
F_127 ( V_4 , F_128 ( V_4 ) ) ;
V_179 = F_129 ( & V_2 -> V_55 ) ;
V_162 = F_130 ( V_4 , V_34 , F_131 ( V_4 -> V_177 ) ,
V_2 -> V_157 , NULL , V_4 -> V_180 ) ;
} while ( F_132 ( & V_2 -> V_55 , V_179 ) );
if ( V_162 >= 0 )
V_89 = F_133 ( V_4 ) ;
else
goto V_181;
}
V_62:
return V_89 ;
V_181:
V_89 = - V_98 ;
F_2 ( V_4 ) ;
goto V_62;
}
int F_134 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_35 * V_34 = V_2 -> V_34 ;
unsigned int V_179 ;
int V_162 ;
do {
F_127 ( V_4 , F_128 ( V_4 ) ) ;
V_179 = F_129 ( & V_2 -> V_55 ) ;
V_162 = F_130 ( V_4 , V_34 , F_131 ( V_4 -> V_177 ) ,
V_2 -> V_157 , NULL , V_4 -> V_180 ) ;
} while ( F_132 ( & V_2 -> V_55 , V_179 ) );
if ( V_162 >= 0 )
V_162 = F_133 ( V_4 ) ;
else {
V_162 = - V_98 ;
F_2 ( V_4 ) ;
}
return V_162 ;
}
int F_135 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return F_133 ( V_4 ) ;
}
static void F_136 ( unsigned long V_137 )
{
struct V_10 * V_11 = (struct V_10 * ) V_137 ;
long V_182 = 0 ;
unsigned long V_44 = V_28 ;
struct V_3 * V_4 , * V_19 ;
F_137 ( & V_11 -> V_43 . V_17 ) ;
F_138 (&tbl->proxy_queue, skb, n) {
long V_183 = F_139 ( V_4 ) -> V_182 - V_44 ;
if ( V_183 <= 0 ) {
struct V_35 * V_34 = V_4 -> V_34 ;
F_140 ( V_4 , & V_11 -> V_43 ) ;
if ( V_11 -> V_184 && F_141 ( V_34 ) ) {
F_118 () ;
V_11 -> V_184 ( V_4 ) ;
F_120 () ;
} else {
F_2 ( V_4 ) ;
}
F_28 ( V_34 ) ;
} else if ( ! V_182 || V_183 < V_182 )
V_182 = V_183 ;
}
F_25 ( & V_11 -> V_42 ) ;
if ( V_182 )
F_21 ( & V_11 -> V_42 , V_28 + V_182 ) ;
F_142 ( & V_11 -> V_43 . V_17 ) ;
}
void F_143 ( struct V_10 * V_11 , struct V_110 * V_120 ,
struct V_3 * V_4 )
{
unsigned long V_44 = V_28 ;
unsigned long V_182 = V_44 + ( F_7 () %
F_72 ( V_120 , V_185 ) ) ;
if ( V_11 -> V_43 . V_186 > F_72 ( V_120 , V_187 ) ) {
F_2 ( V_4 ) ;
return;
}
F_139 ( V_4 ) -> V_182 = V_182 ;
F_139 ( V_4 ) -> V_160 |= V_188 ;
F_137 ( & V_11 -> V_43 . V_17 ) ;
if ( F_25 ( & V_11 -> V_42 ) ) {
if ( F_93 ( V_11 -> V_42 . V_189 , V_182 ) )
V_182 = V_11 -> V_42 . V_189 ;
}
F_144 ( V_4 ) ;
F_71 ( V_4 -> V_34 ) ;
F_108 ( & V_11 -> V_43 , V_4 ) ;
F_21 ( & V_11 -> V_42 , V_182 ) ;
F_142 ( & V_11 -> V_43 . V_17 ) ;
}
static inline struct V_110 * F_145 ( struct V_10 * V_11 ,
struct V_84 * V_84 , int V_190 )
{
struct V_110 * V_120 ;
F_92 (p, &tbl->parms_list, list) {
if ( ( V_120 -> V_34 && V_120 -> V_34 -> V_190 == V_190 && F_67 ( F_146 ( V_120 ) , V_84 ) ) ||
( ! V_120 -> V_34 && ! V_190 && F_67 ( V_84 , & V_191 ) ) )
return V_120 ;
}
return NULL ;
}
struct V_110 * F_147 ( struct V_35 * V_34 ,
struct V_10 * V_11 )
{
struct V_110 * V_120 ;
struct V_84 * V_84 = F_68 ( V_34 ) ;
const struct V_192 * V_113 = V_34 -> V_93 ;
V_120 = F_148 ( & V_11 -> V_6 , sizeof( * V_120 ) , V_105 ) ;
if ( V_120 ) {
V_120 -> V_11 = V_11 ;
F_46 ( & V_120 -> V_22 , 1 ) ;
V_120 -> V_121 =
F_6 ( F_72 ( V_120 , V_97 ) ) ;
F_71 ( V_34 ) ;
V_120 -> V_34 = V_34 ;
F_81 ( & V_120 -> V_84 , V_84 ) ;
V_120 -> V_193 = NULL ;
if ( V_113 -> V_194 && V_113 -> V_194 ( V_34 , V_120 ) ) {
F_28 ( V_34 ) ;
F_54 ( V_120 ) ;
return NULL ;
}
F_10 ( & V_11 -> V_17 ) ;
F_149 ( & V_120 -> V_33 , & V_11 -> V_6 . V_33 ) ;
F_17 ( & V_11 -> V_17 ) ;
F_150 ( V_120 ) ;
}
return V_120 ;
}
static void F_151 ( struct V_72 * V_73 )
{
struct V_110 * V_6 =
F_56 ( V_73 , struct V_110 , V_72 ) ;
F_83 ( V_6 ) ;
}
void F_152 ( struct V_10 * V_11 , struct V_110 * V_6 )
{
if ( ! V_6 || V_6 == & V_11 -> V_6 )
return;
F_10 ( & V_11 -> V_17 ) ;
F_153 ( & V_6 -> V_33 ) ;
V_6 -> V_26 = 1 ;
F_17 ( & V_11 -> V_17 ) ;
if ( V_6 -> V_34 )
F_28 ( V_6 -> V_34 ) ;
F_59 ( & V_6 -> V_72 , F_151 ) ;
}
static void F_85 ( struct V_110 * V_6 )
{
F_54 ( V_6 ) ;
}
void F_154 ( int V_195 , struct V_10 * V_11 )
{
unsigned long V_44 = V_28 ;
unsigned long V_196 ;
F_155 ( & V_11 -> V_197 ) ;
F_149 ( & V_11 -> V_6 . V_33 , & V_11 -> V_197 ) ;
F_81 ( & V_11 -> V_6 . V_84 , & V_191 ) ;
F_46 ( & V_11 -> V_6 . V_22 , 1 ) ;
V_11 -> V_6 . V_121 =
F_6 ( F_72 ( & V_11 -> V_6 , V_97 ) ) ;
V_11 -> V_198 = F_156 ( struct V_199 ) ;
if ( ! V_11 -> V_198 )
F_157 ( L_15 ) ;
#ifdef F_158
if ( ! F_159 ( V_11 -> V_49 , 0 , V_191 . V_200 ,
& V_201 , V_11 ) )
F_157 ( L_16 ) ;
#endif
F_160 ( V_11 -> V_15 , F_50 ( 3 ) ) ;
V_196 = ( V_100 + 1 ) * sizeof( struct V_101 * ) ;
V_11 -> V_103 = F_40 ( V_196 , V_105 ) ;
if ( ! V_11 -> V_15 || ! V_11 -> V_103 )
F_157 ( L_17 ) ;
if ( ! V_11 -> V_52 )
V_11 -> V_52 = F_161 ( F_162 ( struct V_1 , V_80 ) +
V_11 -> V_85 , V_202 ) ;
else
F_163 ( V_11 -> V_52 % V_202 ) ;
F_42 ( & V_11 -> V_17 ) ;
F_164 ( & V_11 -> V_117 , F_91 ) ;
F_95 ( V_127 , & V_11 -> V_117 ,
V_11 -> V_6 . V_121 ) ;
F_45 ( & V_11 -> V_42 , F_136 , ( unsigned long ) V_11 ) ;
F_165 ( & V_11 -> V_43 ,
& V_203 ) ;
V_11 -> V_27 = V_44 ;
V_11 -> V_119 = V_44 + V_11 -> V_6 . V_121 * 20 ;
V_204 [ V_195 ] = V_11 ;
}
int F_166 ( int V_195 , struct V_10 * V_11 )
{
V_204 [ V_195 ] = NULL ;
F_167 ( & V_11 -> V_117 ) ;
F_35 ( & V_11 -> V_42 ) ;
F_26 ( & V_11 -> V_43 ) ;
F_33 ( V_11 , NULL ) ;
if ( F_14 ( & V_11 -> V_45 ) )
F_168 ( L_18 ) ;
F_59 ( & F_11 ( V_11 -> V_15 , 1 ) -> V_74 ,
F_55 ) ;
V_11 -> V_15 = NULL ;
F_54 ( V_11 -> V_103 ) ;
V_11 -> V_103 = NULL ;
F_169 ( V_11 -> V_49 , V_191 . V_200 ) ;
F_170 ( V_11 -> V_198 ) ;
V_11 -> V_198 = NULL ;
return 0 ;
}
static struct V_10 * F_171 ( int V_205 )
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
static int F_172 ( struct V_3 * V_4 , struct V_212 * V_213 )
{
struct V_84 * V_84 = F_173 ( V_4 -> V_214 ) ;
struct V_215 * V_216 ;
struct V_217 * V_218 ;
struct V_10 * V_11 ;
struct V_1 * V_2 ;
struct V_35 * V_34 = NULL ;
int V_162 = - V_98 ;
F_80 () ;
if ( F_174 ( V_213 ) < sizeof( * V_216 ) )
goto V_62;
V_218 = F_175 ( V_213 , sizeof( * V_216 ) , V_219 ) ;
if ( V_218 == NULL )
goto V_62;
V_216 = F_176 ( V_213 ) ;
if ( V_216 -> V_220 ) {
V_34 = F_177 ( V_84 , V_216 -> V_220 ) ;
if ( V_34 == NULL ) {
V_162 = - V_221 ;
goto V_62;
}
}
V_11 = F_171 ( V_216 -> V_222 ) ;
if ( V_11 == NULL )
return - V_223 ;
if ( F_178 ( V_218 ) < V_11 -> V_85 )
goto V_62;
if ( V_216 -> V_224 & V_225 ) {
V_162 = F_82 ( V_11 , V_84 , F_179 ( V_218 ) , V_34 ) ;
goto V_62;
}
if ( V_34 == NULL )
goto V_62;
V_2 = F_60 ( V_11 , F_179 ( V_218 ) , V_34 ) ;
if ( V_2 == NULL ) {
V_162 = - V_108 ;
goto V_62;
}
V_162 = F_114 ( V_2 , NULL , V_125 ,
V_168 |
V_165 ) ;
F_5 ( V_2 ) ;
V_62:
return V_162 ;
}
static int F_180 ( struct V_3 * V_4 , struct V_212 * V_213 )
{
int V_160 = V_165 | V_168 ;
struct V_84 * V_84 = F_173 ( V_4 -> V_214 ) ;
struct V_215 * V_216 ;
struct V_217 * V_226 [ V_227 + 1 ] ;
struct V_10 * V_11 ;
struct V_35 * V_34 = NULL ;
struct V_1 * V_2 ;
void * V_171 , * V_158 ;
int V_162 ;
F_80 () ;
V_162 = F_181 ( V_213 , sizeof( * V_216 ) , V_226 , V_227 , NULL ) ;
if ( V_162 < 0 )
goto V_62;
V_162 = - V_98 ;
if ( V_226 [ V_219 ] == NULL )
goto V_62;
V_216 = F_176 ( V_213 ) ;
if ( V_216 -> V_220 ) {
V_34 = F_177 ( V_84 , V_216 -> V_220 ) ;
if ( V_34 == NULL ) {
V_162 = - V_221 ;
goto V_62;
}
if ( V_226 [ V_228 ] && F_178 ( V_226 [ V_228 ] ) < V_34 -> V_166 )
goto V_62;
}
V_11 = F_171 ( V_216 -> V_222 ) ;
if ( V_11 == NULL )
return - V_223 ;
if ( F_178 ( V_226 [ V_219 ] ) < V_11 -> V_85 )
goto V_62;
V_171 = F_179 ( V_226 [ V_219 ] ) ;
V_158 = V_226 [ V_228 ] ? F_179 ( V_226 [ V_228 ] ) : NULL ;
if ( V_216 -> V_224 & V_225 ) {
struct V_101 * V_229 ;
V_162 = - V_90 ;
V_229 = F_77 ( V_11 , V_84 , V_171 , V_34 , 1 ) ;
if ( V_229 ) {
V_229 -> V_160 = V_216 -> V_224 ;
V_162 = 0 ;
}
goto V_62;
}
if ( V_34 == NULL )
goto V_62;
V_2 = F_60 ( V_11 , V_171 , V_34 ) ;
if ( V_2 == NULL ) {
if ( ! ( V_213 -> V_230 & V_231 ) ) {
V_162 = - V_108 ;
goto V_62;
}
V_2 = F_182 ( V_11 , V_171 , V_34 ) ;
if ( F_183 ( V_2 ) ) {
V_162 = F_184 ( V_2 ) ;
goto V_62;
}
} else {
if ( V_213 -> V_230 & V_232 ) {
V_162 = - V_233 ;
F_5 ( V_2 ) ;
goto V_62;
}
if ( ! ( V_213 -> V_230 & V_234 ) )
V_160 &= ~ V_168 ;
}
if ( V_216 -> V_224 & V_235 ) {
F_126 ( V_2 , NULL ) ;
V_162 = 0 ;
} else
V_162 = F_114 ( V_2 , V_158 , V_216 -> V_236 , V_160 ) ;
F_5 ( V_2 ) ;
V_62:
return V_162 ;
}
static int F_185 ( struct V_3 * V_4 , struct V_110 * V_6 )
{
struct V_217 * V_237 ;
V_237 = F_186 ( V_4 , V_238 ) ;
if ( V_237 == NULL )
return - V_90 ;
if ( ( V_6 -> V_34 &&
F_187 ( V_4 , V_239 , V_6 -> V_34 -> V_190 ) ) ||
F_187 ( V_4 , V_240 , F_14 ( & V_6 -> V_22 ) ) ||
F_187 ( V_4 , V_241 ,
F_72 ( V_6 , V_150 ) ) ||
F_187 ( V_4 , V_242 ,
F_72 ( V_6 , V_150 ) / F_188 ( V_243 ) ) ||
F_187 ( V_4 , V_244 , F_72 ( V_6 , V_187 ) ) ||
F_187 ( V_4 , V_245 , F_72 ( V_6 , V_129 ) ) ||
F_187 ( V_4 , V_246 ,
F_72 ( V_6 , V_128 ) ) ||
F_187 ( V_4 , V_247 ,
F_72 ( V_6 , V_132 ) ) ||
F_187 ( V_4 , V_248 ,
F_72 ( V_6 , V_131 ) ) ||
F_189 ( V_4 , V_249 , V_6 -> V_121 ,
V_250 ) ||
F_189 ( V_4 , V_251 ,
F_72 ( V_6 , V_97 ) , V_250 ) ||
F_189 ( V_4 , V_252 ,
F_72 ( V_6 , V_126 ) , V_250 ) ||
F_189 ( V_4 , V_253 ,
F_72 ( V_6 , V_140 ) , V_250 ) ||
F_189 ( V_4 , V_254 ,
F_72 ( V_6 , V_143 ) , V_250 ) ||
F_189 ( V_4 , V_255 ,
F_72 ( V_6 , V_256 ) , V_250 ) ||
F_189 ( V_4 , V_257 ,
F_72 ( V_6 , V_185 ) , V_250 ) ||
F_189 ( V_4 , V_258 ,
F_72 ( V_6 , V_259 ) , V_250 ) )
goto V_260;
return F_190 ( V_4 , V_237 ) ;
V_260:
F_191 ( V_4 , V_237 ) ;
return - V_261 ;
}
static int F_192 ( struct V_3 * V_4 , struct V_10 * V_11 ,
T_2 V_262 , T_2 V_179 , int type , int V_160 )
{
struct V_212 * V_213 ;
struct V_263 * V_263 ;
V_213 = F_193 ( V_4 , V_262 , V_179 , type , sizeof( * V_263 ) , V_160 ) ;
if ( V_213 == NULL )
return - V_261 ;
V_263 = F_176 ( V_213 ) ;
F_78 ( & V_11 -> V_17 ) ;
V_263 -> V_264 = V_11 -> V_205 ;
V_263 -> V_265 = 0 ;
V_263 -> V_266 = 0 ;
if ( F_194 ( V_4 , V_267 , V_11 -> V_49 ) ||
F_189 ( V_4 , V_268 , V_11 -> V_269 , V_270 ) ||
F_187 ( V_4 , V_271 , V_11 -> V_122 ) ||
F_187 ( V_4 , V_272 , V_11 -> V_47 ) ||
F_187 ( V_4 , V_273 , V_11 -> V_46 ) )
goto V_260;
{
unsigned long V_44 = V_28 ;
unsigned int V_274 = V_44 - V_11 -> V_27 ;
unsigned int V_275 = V_44 - V_11 -> V_119 ;
struct V_14 * V_15 ;
struct V_276 V_277 = {
. V_278 = V_11 -> V_85 ,
. V_279 = V_11 -> V_52 ,
. V_280 = F_14 ( & V_11 -> V_45 ) ,
. V_281 = F_195 ( V_274 ) ,
. V_282 = F_195 ( V_275 ) ,
. V_283 = V_11 -> V_43 . V_186 ,
} ;
F_61 () ;
V_15 = F_66 ( V_11 -> V_15 ) ;
V_277 . V_284 = V_15 -> V_71 [ 0 ] ;
V_277 . V_285 = ( ( 1 << V_15 -> V_18 ) - 1 ) ;
F_64 () ;
if ( F_196 ( V_4 , V_286 , sizeof( V_277 ) , & V_277 ) )
goto V_260;
}
{
int V_287 ;
struct V_288 V_289 ;
memset ( & V_289 , 0 , sizeof( V_289 ) ) ;
F_197 (cpu) {
struct V_199 * V_290 ;
V_290 = F_198 ( V_11 -> V_198 , V_287 ) ;
V_289 . V_291 += V_290 -> V_61 ;
V_289 . V_292 += V_290 -> V_111 ;
V_289 . V_293 += V_290 -> V_79 ;
V_289 . V_294 += V_290 -> V_133 ;
V_289 . V_295 += V_290 -> V_82 ;
V_289 . V_296 += V_290 -> V_83 ;
V_289 . V_297 += V_290 -> V_298 ;
V_289 . V_299 += V_290 -> V_300 ;
V_289 . V_301 += V_290 -> V_118 ;
V_289 . V_302 += V_290 -> V_16 ;
V_289 . V_303 += V_290 -> V_50 ;
}
if ( F_199 ( V_4 , V_304 , sizeof( V_289 ) , & V_289 ,
V_270 ) )
goto V_260;
}
F_200 ( V_11 -> V_6 . V_34 ) ;
if ( F_185 ( V_4 , & V_11 -> V_6 ) < 0 )
goto V_260;
F_79 ( & V_11 -> V_17 ) ;
F_201 ( V_4 , V_213 ) ;
return 0 ;
V_260:
F_79 ( & V_11 -> V_17 ) ;
F_202 ( V_4 , V_213 ) ;
return - V_261 ;
}
static int F_203 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
struct V_110 * V_6 ,
T_2 V_262 , T_2 V_179 , int type ,
unsigned int V_160 )
{
struct V_263 * V_263 ;
struct V_212 * V_213 ;
V_213 = F_193 ( V_4 , V_262 , V_179 , type , sizeof( * V_263 ) , V_160 ) ;
if ( V_213 == NULL )
return - V_261 ;
V_263 = F_176 ( V_213 ) ;
F_78 ( & V_11 -> V_17 ) ;
V_263 -> V_264 = V_11 -> V_205 ;
V_263 -> V_265 = 0 ;
V_263 -> V_266 = 0 ;
if ( F_194 ( V_4 , V_267 , V_11 -> V_49 ) < 0 ||
F_185 ( V_4 , V_6 ) < 0 )
goto V_305;
F_79 ( & V_11 -> V_17 ) ;
F_201 ( V_4 , V_213 ) ;
return 0 ;
V_305:
F_79 ( & V_11 -> V_17 ) ;
F_202 ( V_4 , V_213 ) ;
return - V_261 ;
}
static int F_204 ( struct V_3 * V_4 , struct V_212 * V_213 )
{
struct V_84 * V_84 = F_173 ( V_4 -> V_214 ) ;
struct V_10 * V_11 ;
struct V_263 * V_263 ;
struct V_217 * V_226 [ V_306 + 1 ] ;
bool V_307 = false ;
int V_162 , V_308 ;
V_162 = F_181 ( V_213 , sizeof( * V_263 ) , V_226 , V_306 ,
V_309 ) ;
if ( V_162 < 0 )
goto V_305;
if ( V_226 [ V_267 ] == NULL ) {
V_162 = - V_98 ;
goto V_305;
}
V_263 = F_176 ( V_213 ) ;
for ( V_308 = 0 ; V_308 < V_310 ; V_308 ++ ) {
V_11 = V_204 [ V_308 ] ;
if ( ! V_11 )
continue;
if ( V_263 -> V_264 && V_11 -> V_205 != V_263 -> V_264 )
continue;
if ( F_205 ( V_226 [ V_267 ] , V_11 -> V_49 ) == 0 ) {
V_307 = true ;
break;
}
}
if ( ! V_307 )
return - V_108 ;
F_10 ( & V_11 -> V_17 ) ;
if ( V_226 [ V_238 ] ) {
struct V_217 * V_311 [ V_312 + 1 ] ;
struct V_110 * V_120 ;
int V_13 , V_190 = 0 ;
V_162 = F_206 ( V_311 , V_312 , V_226 [ V_238 ] ,
V_313 ) ;
if ( V_162 < 0 )
goto V_314;
if ( V_311 [ V_239 ] )
V_190 = F_207 ( V_311 [ V_239 ] ) ;
V_120 = F_145 ( V_11 , V_84 , V_190 ) ;
if ( V_120 == NULL ) {
V_162 = - V_108 ;
goto V_314;
}
for ( V_13 = 1 ; V_13 <= V_312 ; V_13 ++ ) {
if ( V_311 [ V_13 ] == NULL )
continue;
switch ( V_13 ) {
case V_242 :
F_208 ( V_120 , V_150 ,
F_207 ( V_311 [ V_13 ] ) *
F_188 ( V_243 ) ) ;
break;
case V_241 :
F_208 ( V_120 , V_150 ,
F_207 ( V_311 [ V_13 ] ) ) ;
break;
case V_244 :
F_208 ( V_120 , V_187 ,
F_207 ( V_311 [ V_13 ] ) ) ;
break;
case V_245 :
F_208 ( V_120 , V_129 ,
F_207 ( V_311 [ V_13 ] ) ) ;
break;
case V_246 :
F_208 ( V_120 , V_128 ,
F_207 ( V_311 [ V_13 ] ) ) ;
break;
case V_247 :
F_208 ( V_120 , V_132 ,
F_207 ( V_311 [ V_13 ] ) ) ;
break;
case V_248 :
F_208 ( V_120 , V_131 ,
F_207 ( V_311 [ V_13 ] ) ) ;
break;
case V_251 :
F_208 ( V_120 , V_97 ,
F_209 ( V_311 [ V_13 ] ) ) ;
V_120 -> V_121 =
F_6 ( F_72 ( V_120 , V_97 ) ) ;
break;
case V_252 :
F_208 ( V_120 , V_126 ,
F_209 ( V_311 [ V_13 ] ) ) ;
break;
case V_253 :
F_208 ( V_120 , V_140 ,
F_209 ( V_311 [ V_13 ] ) ) ;
F_210 ( V_315 , V_120 ) ;
break;
case V_254 :
F_208 ( V_120 , V_143 ,
F_209 ( V_311 [ V_13 ] ) ) ;
break;
case V_255 :
F_208 ( V_120 , V_256 ,
F_209 ( V_311 [ V_13 ] ) ) ;
break;
case V_257 :
F_208 ( V_120 , V_185 ,
F_209 ( V_311 [ V_13 ] ) ) ;
break;
case V_258 :
F_208 ( V_120 , V_259 ,
F_209 ( V_311 [ V_13 ] ) ) ;
break;
}
}
}
V_162 = - V_108 ;
if ( ( V_226 [ V_271 ] || V_226 [ V_272 ] ||
V_226 [ V_273 ] || V_226 [ V_268 ] ) &&
! F_67 ( V_84 , & V_191 ) )
goto V_314;
if ( V_226 [ V_271 ] )
V_11 -> V_122 = F_207 ( V_226 [ V_271 ] ) ;
if ( V_226 [ V_272 ] )
V_11 -> V_47 = F_207 ( V_226 [ V_272 ] ) ;
if ( V_226 [ V_273 ] )
V_11 -> V_46 = F_207 ( V_226 [ V_273 ] ) ;
if ( V_226 [ V_268 ] )
V_11 -> V_269 = F_209 ( V_226 [ V_268 ] ) ;
V_162 = 0 ;
V_314:
F_17 ( & V_11 -> V_17 ) ;
V_305:
return V_162 ;
}
static int F_211 ( struct V_3 * V_4 , struct V_316 * V_317 )
{
struct V_84 * V_84 = F_173 ( V_4 -> V_214 ) ;
int V_205 , V_308 , V_318 = 0 ;
int V_319 = V_317 -> args [ 0 ] ;
int V_320 = V_317 -> args [ 1 ] ;
struct V_10 * V_11 ;
V_205 = ( (struct V_321 * ) F_176 ( V_317 -> V_213 ) ) -> V_322 ;
for ( V_308 = 0 ; V_308 < V_310 ; V_308 ++ ) {
struct V_110 * V_120 ;
V_11 = V_204 [ V_308 ] ;
if ( ! V_11 )
continue;
if ( V_308 < V_319 || ( V_205 && V_11 -> V_205 != V_205 ) )
continue;
if ( F_192 ( V_4 , V_11 , F_212 ( V_317 -> V_4 ) . V_323 ,
V_317 -> V_213 -> V_324 , V_325 ,
V_326 ) < 0 )
break;
V_318 = 0 ;
V_120 = F_213 ( & V_11 -> V_6 , V_33 ) ;
F_214 (p, &tbl->parms_list, list) {
if ( ! F_67 ( F_146 ( V_120 ) , V_84 ) )
continue;
if ( V_318 < V_320 )
goto V_25;
if ( F_203 ( V_4 , V_11 , V_120 ,
F_212 ( V_317 -> V_4 ) . V_323 ,
V_317 -> V_213 -> V_324 ,
V_325 ,
V_326 ) < 0 )
goto V_62;
V_25:
V_318 ++ ;
}
V_320 = 0 ;
}
V_62:
V_317 -> args [ 0 ] = V_308 ;
V_317 -> args [ 1 ] = V_318 ;
return V_4 -> V_180 ;
}
static int F_215 ( struct V_3 * V_4 , struct V_1 * V_2 ,
T_2 V_262 , T_2 V_179 , int type , unsigned int V_160 )
{
unsigned long V_44 = V_28 ;
struct V_327 V_328 ;
struct V_212 * V_213 ;
struct V_215 * V_216 ;
V_213 = F_193 ( V_4 , V_262 , V_179 , type , sizeof( * V_216 ) , V_160 ) ;
if ( V_213 == NULL )
return - V_261 ;
V_216 = F_176 ( V_213 ) ;
V_216 -> V_222 = V_2 -> V_113 -> V_205 ;
V_216 -> V_329 = 0 ;
V_216 -> V_330 = 0 ;
V_216 -> V_224 = V_2 -> V_160 ;
V_216 -> V_331 = V_2 -> type ;
V_216 -> V_220 = V_2 -> V_34 -> V_190 ;
if ( F_196 ( V_4 , V_219 , V_2 -> V_11 -> V_85 , V_2 -> V_80 ) )
goto V_260;
F_78 ( & V_2 -> V_17 ) ;
V_216 -> V_236 = V_2 -> V_23 ;
if ( V_2 -> V_23 & V_39 ) {
char V_332 [ V_333 ] ;
F_216 ( V_332 , V_2 , V_2 -> V_34 ) ;
if ( F_196 ( V_4 , V_228 , V_2 -> V_34 -> V_166 , V_332 ) < 0 ) {
F_79 ( & V_2 -> V_17 ) ;
goto V_260;
}
}
V_328 . V_334 = F_217 ( V_44 - V_2 -> V_57 ) ;
V_328 . V_335 = F_217 ( V_44 - V_2 -> V_96 ) ;
V_328 . V_336 = F_217 ( V_44 - V_2 -> V_56 ) ;
V_328 . V_337 = F_14 ( & V_2 -> V_22 ) - 1 ;
F_79 ( & V_2 -> V_17 ) ;
if ( F_187 ( V_4 , V_338 , F_14 ( & V_2 -> V_136 ) ) ||
F_196 ( V_4 , V_339 , sizeof( V_328 ) , & V_328 ) )
goto V_260;
F_201 ( V_4 , V_213 ) ;
return 0 ;
V_260:
F_202 ( V_4 , V_213 ) ;
return - V_261 ;
}
static int F_218 ( struct V_3 * V_4 , struct V_101 * V_229 ,
T_2 V_262 , T_2 V_179 , int type , unsigned int V_160 ,
struct V_10 * V_11 )
{
struct V_212 * V_213 ;
struct V_215 * V_216 ;
V_213 = F_193 ( V_4 , V_262 , V_179 , type , sizeof( * V_216 ) , V_160 ) ;
if ( V_213 == NULL )
return - V_261 ;
V_216 = F_176 ( V_213 ) ;
V_216 -> V_222 = V_11 -> V_205 ;
V_216 -> V_329 = 0 ;
V_216 -> V_330 = 0 ;
V_216 -> V_224 = V_229 -> V_160 | V_225 ;
V_216 -> V_331 = V_340 ;
V_216 -> V_220 = V_229 -> V_34 ? V_229 -> V_34 -> V_190 : 0 ;
V_216 -> V_236 = V_41 ;
if ( F_196 ( V_4 , V_219 , V_11 -> V_85 , V_229 -> V_102 ) )
goto V_260;
F_201 ( V_4 , V_213 ) ;
return 0 ;
V_260:
F_202 ( V_4 , V_213 ) ;
return - V_261 ;
}
static void F_104 ( struct V_1 * V_2 )
{
F_210 ( V_341 , V_2 ) ;
F_4 ( V_2 , V_342 , 0 ) ;
}
static bool F_219 ( struct V_35 * V_34 , int V_343 )
{
struct V_35 * V_344 ;
if ( ! V_343 )
return false ;
V_344 = F_220 ( V_34 ) ;
if ( ! V_344 || V_344 -> V_190 != V_343 )
return true ;
return false ;
}
static bool F_221 ( struct V_35 * V_34 , int V_345 )
{
if ( V_345 && V_34 -> V_190 != V_345 )
return true ;
return false ;
}
static int F_222 ( struct V_10 * V_11 , struct V_3 * V_4 ,
struct V_316 * V_317 )
{
struct V_84 * V_84 = F_173 ( V_4 -> V_214 ) ;
const struct V_212 * V_213 = V_317 -> V_213 ;
struct V_217 * V_226 [ V_227 + 1 ] ;
struct V_1 * V_19 ;
int V_89 , V_109 , V_346 = V_317 -> args [ 1 ] ;
int V_347 , V_348 = V_347 = V_317 -> args [ 2 ] ;
struct V_14 * V_15 ;
int V_349 = 0 , V_345 = 0 ;
unsigned int V_160 = V_326 ;
int V_162 ;
V_162 = F_181 ( V_213 , sizeof( struct V_215 ) , V_226 , V_227 , NULL ) ;
if ( ! V_162 ) {
if ( V_226 [ V_350 ] )
V_345 = F_207 ( V_226 [ V_350 ] ) ;
if ( V_226 [ V_351 ] )
V_349 = F_207 ( V_226 [ V_351 ] ) ;
if ( V_345 || V_349 )
V_160 |= V_352 ;
}
F_61 () ;
V_15 = F_66 ( V_11 -> V_15 ) ;
for ( V_109 = V_346 ; V_109 < ( 1 << V_15 -> V_18 ) ; V_109 ++ ) {
if ( V_109 > V_346 )
V_348 = 0 ;
for ( V_19 = F_66 ( V_15 -> V_21 [ V_109 ] ) , V_347 = 0 ;
V_19 != NULL ;
V_19 = F_66 ( V_19 -> V_25 ) ) {
if ( ! F_67 ( F_68 ( V_19 -> V_34 ) , V_84 ) )
continue;
if ( F_221 ( V_19 -> V_34 , V_345 ) )
continue;
if ( F_219 ( V_19 -> V_34 , V_349 ) )
continue;
if ( V_347 < V_348 )
goto V_25;
if ( F_215 ( V_4 , V_19 , F_212 ( V_317 -> V_4 ) . V_323 ,
V_317 -> V_213 -> V_324 ,
V_342 ,
V_160 ) < 0 ) {
V_89 = - 1 ;
goto V_62;
}
V_25:
V_347 ++ ;
}
}
V_89 = V_4 -> V_180 ;
V_62:
F_64 () ;
V_317 -> args [ 1 ] = V_109 ;
V_317 -> args [ 2 ] = V_347 ;
return V_89 ;
}
static int F_223 ( struct V_10 * V_11 , struct V_3 * V_4 ,
struct V_316 * V_317 )
{
struct V_101 * V_19 ;
struct V_84 * V_84 = F_173 ( V_4 -> V_214 ) ;
int V_89 , V_109 , V_346 = V_317 -> args [ 3 ] ;
int V_347 , V_348 = V_347 = V_317 -> args [ 4 ] ;
F_78 ( & V_11 -> V_17 ) ;
for ( V_109 = V_346 ; V_109 <= V_100 ; V_109 ++ ) {
if ( V_109 > V_346 )
V_348 = 0 ;
for ( V_19 = V_11 -> V_103 [ V_109 ] , V_347 = 0 ; V_19 ; V_19 = V_19 -> V_25 ) {
if ( F_75 ( V_19 ) != V_84 )
continue;
if ( V_347 < V_348 )
goto V_25;
if ( F_218 ( V_4 , V_19 , F_212 ( V_317 -> V_4 ) . V_323 ,
V_317 -> V_213 -> V_324 ,
V_342 ,
V_326 , V_11 ) < 0 ) {
F_79 ( & V_11 -> V_17 ) ;
V_89 = - 1 ;
goto V_62;
}
V_25:
V_347 ++ ;
}
}
F_79 ( & V_11 -> V_17 ) ;
V_89 = V_4 -> V_180 ;
V_62:
V_317 -> args [ 3 ] = V_109 ;
V_317 -> args [ 4 ] = V_347 ;
return V_89 ;
}
static int F_224 ( struct V_3 * V_4 , struct V_316 * V_317 )
{
struct V_10 * V_11 ;
int V_353 , V_205 , V_354 ;
int V_355 = 0 ;
int V_162 ;
V_205 = ( (struct V_321 * ) F_176 ( V_317 -> V_213 ) ) -> V_322 ;
if ( F_174 ( V_317 -> V_213 ) >= sizeof( struct V_215 ) &&
( (struct V_215 * ) F_176 ( V_317 -> V_213 ) ) -> V_224 == V_225 )
V_355 = 1 ;
V_354 = V_317 -> args [ 0 ] ;
for ( V_353 = 0 ; V_353 < V_310 ; V_353 ++ ) {
V_11 = V_204 [ V_353 ] ;
if ( ! V_11 )
continue;
if ( V_353 < V_354 || ( V_205 && V_11 -> V_205 != V_205 ) )
continue;
if ( V_353 > V_354 )
memset ( & V_317 -> args [ 1 ] , 0 , sizeof( V_317 -> args ) -
sizeof( V_317 -> args [ 0 ] ) ) ;
if ( V_355 )
V_162 = F_223 ( V_11 , V_4 , V_317 ) ;
else
V_162 = F_222 ( V_11 , V_4 , V_317 ) ;
if ( V_162 < 0 )
break;
}
V_317 -> args [ 0 ] = V_353 ;
return V_4 -> V_180 ;
}
void F_225 ( struct V_10 * V_11 , void (* V_317)( struct V_1 * , void * ) , void * V_356 )
{
int V_357 ;
struct V_14 * V_15 ;
F_61 () ;
V_15 = F_66 ( V_11 -> V_15 ) ;
F_226 ( & V_11 -> V_17 ) ;
for ( V_357 = 0 ; V_357 < ( 1 << V_15 -> V_18 ) ; V_357 ++ ) {
struct V_1 * V_19 ;
for ( V_19 = F_66 ( V_15 -> V_21 [ V_357 ] ) ;
V_19 != NULL ;
V_19 = F_66 ( V_19 -> V_25 ) )
V_317 ( V_19 , V_356 ) ;
}
F_227 ( & V_11 -> V_17 ) ;
F_64 () ;
}
void F_228 ( struct V_10 * V_11 ,
int (* V_317)( struct V_1 * ) )
{
int V_357 ;
struct V_14 * V_15 ;
V_15 = F_11 ( V_11 -> V_15 ,
F_12 ( & V_11 -> V_17 ) ) ;
for ( V_357 = 0 ; V_357 < ( 1 << V_15 -> V_18 ) ; V_357 ++ ) {
struct V_1 * V_19 ;
struct V_1 T_1 * * V_20 ;
V_20 = & V_15 -> V_21 [ V_357 ] ;
while ( ( V_19 = F_11 ( * V_20 ,
F_12 ( & V_11 -> V_17 ) ) ) != NULL ) {
int V_358 ;
F_13 ( & V_19 -> V_17 ) ;
V_358 = V_317 ( V_19 ) ;
if ( V_358 ) {
F_15 ( * V_20 ,
F_11 ( V_19 -> V_25 ,
F_12 ( & V_11 -> V_17 ) ) ) ;
V_19 -> V_26 = 1 ;
} else
V_20 = & V_19 -> V_25 ;
F_16 ( & V_19 -> V_17 ) ;
if ( V_358 )
F_3 ( V_19 ) ;
}
}
}
int F_229 ( int V_195 , struct V_35 * V_34 ,
const void * V_359 , struct V_3 * V_4 )
{
int V_162 = - V_223 ;
if ( F_230 ( V_195 < V_310 ) ) {
struct V_10 * V_11 ;
struct V_1 * V_2 ;
V_11 = V_204 [ V_195 ] ;
if ( ! V_11 )
goto V_62;
F_61 () ;
V_2 = F_62 ( V_11 , V_359 , V_34 ) ;
if ( ! V_2 )
V_2 = F_69 ( V_11 , V_359 , V_34 , false ) ;
V_162 = F_184 ( V_2 ) ;
if ( F_183 ( V_2 ) ) {
F_64 () ;
goto V_181;
}
V_162 = V_2 -> V_38 ( V_2 , V_4 ) ;
F_64 () ;
}
else if ( V_195 == V_360 ) {
V_162 = F_130 ( V_4 , V_34 , F_131 ( V_4 -> V_177 ) ,
V_359 , NULL , V_4 -> V_180 ) ;
if ( V_162 < 0 )
goto V_181;
V_162 = F_133 ( V_4 ) ;
}
V_62:
return V_162 ;
V_181:
F_2 ( V_4 ) ;
goto V_62;
}
static struct V_1 * F_231 ( struct V_361 * V_179 )
{
struct V_362 * V_123 = V_179 -> V_363 ;
struct V_84 * V_84 = F_232 ( V_179 ) ;
struct V_14 * V_15 = V_123 -> V_15 ;
struct V_1 * V_19 = NULL ;
int V_364 = V_123 -> V_364 ;
V_123 -> V_160 &= ~ V_365 ;
for ( V_364 = 0 ; V_364 < ( 1 << V_15 -> V_18 ) ; V_364 ++ ) {
V_19 = F_66 ( V_15 -> V_21 [ V_364 ] ) ;
while ( V_19 ) {
if ( ! F_67 ( F_68 ( V_19 -> V_34 ) , V_84 ) )
goto V_25;
if ( V_123 -> V_366 ) {
T_7 V_367 = 0 ;
void * V_368 ;
V_368 = V_123 -> V_366 ( V_123 , V_19 , & V_367 ) ;
if ( ! V_368 )
goto V_25;
}
if ( ! ( V_123 -> V_160 & V_369 ) )
break;
if ( V_19 -> V_23 & ~ V_40 )
break;
V_25:
V_19 = F_66 ( V_19 -> V_25 ) ;
}
if ( V_19 )
break;
}
V_123 -> V_364 = V_364 ;
return V_19 ;
}
static struct V_1 * F_233 ( struct V_361 * V_179 ,
struct V_1 * V_19 ,
T_7 * V_370 )
{
struct V_362 * V_123 = V_179 -> V_363 ;
struct V_84 * V_84 = F_232 ( V_179 ) ;
struct V_14 * V_15 = V_123 -> V_15 ;
if ( V_123 -> V_366 ) {
void * V_368 = V_123 -> V_366 ( V_123 , V_19 , V_370 ) ;
if ( V_368 )
return V_19 ;
}
V_19 = F_66 ( V_19 -> V_25 ) ;
while ( 1 ) {
while ( V_19 ) {
if ( ! F_67 ( F_68 ( V_19 -> V_34 ) , V_84 ) )
goto V_25;
if ( V_123 -> V_366 ) {
void * V_368 = V_123 -> V_366 ( V_123 , V_19 , V_370 ) ;
if ( V_368 )
return V_19 ;
goto V_25;
}
if ( ! ( V_123 -> V_160 & V_369 ) )
break;
if ( V_19 -> V_23 & ~ V_40 )
break;
V_25:
V_19 = F_66 ( V_19 -> V_25 ) ;
}
if ( V_19 )
break;
if ( ++ V_123 -> V_364 >= ( 1 << V_15 -> V_18 ) )
break;
V_19 = F_66 ( V_15 -> V_21 [ V_123 -> V_364 ] ) ;
}
if ( V_19 && V_370 )
-- ( * V_370 ) ;
return V_19 ;
}
static struct V_1 * F_234 ( struct V_361 * V_179 , T_7 * V_370 )
{
struct V_1 * V_19 = F_231 ( V_179 ) ;
if ( V_19 ) {
-- ( * V_370 ) ;
while ( * V_370 ) {
V_19 = F_233 ( V_179 , V_19 , V_370 ) ;
if ( ! V_19 )
break;
}
}
return * V_370 ? NULL : V_19 ;
}
static struct V_101 * F_235 ( struct V_361 * V_179 )
{
struct V_362 * V_123 = V_179 -> V_363 ;
struct V_84 * V_84 = F_232 ( V_179 ) ;
struct V_10 * V_11 = V_123 -> V_11 ;
struct V_101 * V_229 = NULL ;
int V_364 = V_123 -> V_364 ;
V_123 -> V_160 |= V_365 ;
for ( V_364 = 0 ; V_364 <= V_100 ; V_364 ++ ) {
V_229 = V_11 -> V_103 [ V_364 ] ;
while ( V_229 && ! F_67 ( F_75 ( V_229 ) , V_84 ) )
V_229 = V_229 -> V_25 ;
if ( V_229 )
break;
}
V_123 -> V_364 = V_364 ;
return V_229 ;
}
static struct V_101 * F_236 ( struct V_361 * V_179 ,
struct V_101 * V_229 ,
T_7 * V_370 )
{
struct V_362 * V_123 = V_179 -> V_363 ;
struct V_84 * V_84 = F_232 ( V_179 ) ;
struct V_10 * V_11 = V_123 -> V_11 ;
do {
V_229 = V_229 -> V_25 ;
} while ( V_229 && ! F_67 ( F_75 ( V_229 ) , V_84 ) );
while ( ! V_229 ) {
if ( ++ V_123 -> V_364 > V_100 )
break;
V_229 = V_11 -> V_103 [ V_123 -> V_364 ] ;
while ( V_229 && ! F_67 ( F_75 ( V_229 ) , V_84 ) )
V_229 = V_229 -> V_25 ;
if ( V_229 )
break;
}
if ( V_229 && V_370 )
-- ( * V_370 ) ;
return V_229 ;
}
static struct V_101 * F_237 ( struct V_361 * V_179 , T_7 * V_370 )
{
struct V_101 * V_229 = F_235 ( V_179 ) ;
if ( V_229 ) {
-- ( * V_370 ) ;
while ( * V_370 ) {
V_229 = F_236 ( V_179 , V_229 , V_370 ) ;
if ( ! V_229 )
break;
}
}
return * V_370 ? NULL : V_229 ;
}
static void * F_238 ( struct V_361 * V_179 , T_7 * V_370 )
{
struct V_362 * V_123 = V_179 -> V_363 ;
void * V_89 ;
T_7 V_371 = * V_370 ;
V_89 = F_234 ( V_179 , & V_371 ) ;
if ( ! V_89 && ! ( V_123 -> V_160 & V_372 ) )
V_89 = F_237 ( V_179 , & V_371 ) ;
return V_89 ;
}
void * F_239 ( struct V_361 * V_179 , T_7 * V_370 , struct V_10 * V_11 , unsigned int V_373 )
__acquires( T_8 )
{
struct V_362 * V_123 = V_179 -> V_363 ;
V_123 -> V_11 = V_11 ;
V_123 -> V_364 = 0 ;
V_123 -> V_160 = ( V_373 & ~ V_365 ) ;
F_61 () ;
V_123 -> V_15 = F_66 ( V_11 -> V_15 ) ;
return * V_370 ? F_238 ( V_179 , V_370 ) : V_374 ;
}
void * F_240 ( struct V_361 * V_179 , void * V_368 , T_7 * V_370 )
{
struct V_362 * V_123 ;
void * V_89 ;
if ( V_368 == V_374 ) {
V_89 = F_231 ( V_179 ) ;
goto V_62;
}
V_123 = V_179 -> V_363 ;
if ( ! ( V_123 -> V_160 & V_365 ) ) {
V_89 = F_233 ( V_179 , V_368 , NULL ) ;
if ( V_89 )
goto V_62;
if ( ! ( V_123 -> V_160 & V_372 ) )
V_89 = F_235 ( V_179 ) ;
} else {
F_200 ( V_123 -> V_160 & V_372 ) ;
V_89 = F_236 ( V_179 , V_368 , NULL ) ;
}
V_62:
++ ( * V_370 ) ;
return V_89 ;
}
void F_241 ( struct V_361 * V_179 , void * V_368 )
__releases( T_8 )
{
F_64 () ;
}
static void * F_242 ( struct V_361 * V_179 , T_7 * V_370 )
{
struct V_10 * V_11 = V_179 -> V_363 ;
int V_287 ;
if ( * V_370 == 0 )
return V_374 ;
for ( V_287 = * V_370 - 1 ; V_287 < V_375 ; ++ V_287 ) {
if ( ! F_243 ( V_287 ) )
continue;
* V_370 = V_287 + 1 ;
return F_198 ( V_11 -> V_198 , V_287 ) ;
}
return NULL ;
}
static void * F_244 ( struct V_361 * V_179 , void * V_368 , T_7 * V_370 )
{
struct V_10 * V_11 = V_179 -> V_363 ;
int V_287 ;
for ( V_287 = * V_370 ; V_287 < V_375 ; ++ V_287 ) {
if ( ! F_243 ( V_287 ) )
continue;
* V_370 = V_287 + 1 ;
return F_198 ( V_11 -> V_198 , V_287 ) ;
}
return NULL ;
}
static void F_245 ( struct V_361 * V_179 , void * V_368 )
{
}
static int F_246 ( struct V_361 * V_179 , void * V_368 )
{
struct V_10 * V_11 = V_179 -> V_363 ;
struct V_199 * V_290 = V_368 ;
if ( V_368 == V_374 ) {
F_247 ( V_179 , L_19 ) ;
return 0 ;
}
F_247 ( V_179 , L_20
L_21 ,
F_14 ( & V_11 -> V_45 ) ,
V_290 -> V_61 ,
V_290 -> V_111 ,
V_290 -> V_79 ,
V_290 -> V_82 ,
V_290 -> V_83 ,
V_290 -> V_133 ,
V_290 -> V_298 ,
V_290 -> V_300 ,
V_290 -> V_118 ,
V_290 -> V_16 ,
V_290 -> V_152 ,
V_290 -> V_50
) ;
return 0 ;
}
static int F_248 ( struct V_376 * V_376 , struct V_377 * V_377 )
{
int V_66 = F_249 ( V_377 , & V_378 ) ;
if ( ! V_66 ) {
struct V_361 * V_379 = V_377 -> V_380 ;
V_379 -> V_363 = F_250 ( V_376 ) ;
}
return V_66 ;
}
static inline T_3 F_251 ( void )
{
return F_252 ( sizeof( struct V_215 ) )
+ F_253 ( V_333 )
+ F_253 ( V_333 )
+ F_253 ( sizeof( struct V_327 ) )
+ F_253 ( 4 ) ;
}
static void F_4 ( struct V_1 * V_19 , int type , int V_160 )
{
struct V_84 * V_84 = F_68 ( V_19 -> V_34 ) ;
struct V_3 * V_4 ;
int V_162 = - V_90 ;
V_4 = F_254 ( F_251 () , V_54 ) ;
if ( V_4 == NULL )
goto V_305;
V_162 = F_215 ( V_4 , V_19 , 0 , 0 , type , V_160 ) ;
if ( V_162 < 0 ) {
F_163 ( V_162 == - V_261 ) ;
F_2 ( V_4 ) ;
goto V_305;
}
F_255 ( V_4 , V_84 , 0 , V_381 , NULL , V_54 ) ;
return;
V_305:
if ( V_162 < 0 )
F_256 ( V_84 , V_381 , V_162 ) ;
}
void F_257 ( struct V_1 * V_19 )
{
F_4 ( V_19 , V_382 , V_383 ) ;
}
static int F_258 ( struct V_384 * V_385 , int V_386 ,
void T_9 * V_387 , T_3 * V_388 , T_7 * V_389 )
{
int V_65 , V_66 ;
struct V_384 V_390 = * V_385 ;
V_390 . V_391 = & V_392 ;
V_390 . V_393 = & V_394 ;
V_390 . V_395 = & V_65 ;
V_65 = * ( int * ) V_385 -> V_395 / F_188 ( V_243 ) ;
V_66 = F_259 ( & V_390 , V_386 , V_387 , V_388 , V_389 ) ;
if ( V_386 && ! V_66 )
* ( int * ) V_385 -> V_395 = V_65 * F_188 ( V_243 ) ;
return V_66 ;
}
static struct V_110 * F_260 ( struct V_35 * V_34 ,
int V_205 )
{
switch ( V_205 ) {
case V_206 :
return F_261 ( V_34 ) ;
case V_208 :
return F_262 ( V_34 ) ;
}
return NULL ;
}
static void F_263 ( struct V_84 * V_84 , struct V_110 * V_120 ,
int V_195 )
{
struct V_35 * V_34 ;
int V_205 = F_264 ( V_120 ) ;
F_118 () ;
F_265 (net, dev) {
struct V_110 * V_396 =
F_260 ( V_34 , V_205 ) ;
if ( V_396 && ! F_266 ( V_195 , V_396 -> V_397 ) )
V_396 -> V_395 [ V_195 ] = V_120 -> V_395 [ V_195 ] ;
}
F_120 () ;
}
static void F_267 ( struct V_384 * V_385 , int V_386 )
{
struct V_35 * V_34 = V_385 -> V_391 ;
struct V_110 * V_120 = V_385 -> V_393 ;
struct V_84 * V_84 = F_146 ( V_120 ) ;
int V_195 = ( int * ) V_385 -> V_395 - V_120 -> V_395 ;
if ( ! V_386 )
return;
F_268 ( V_195 , V_120 -> V_397 ) ;
F_210 ( V_315 , V_120 ) ;
if ( ! V_34 )
F_263 ( V_84 , V_120 , V_195 ) ;
}
static int F_269 ( struct V_384 * V_385 , int V_386 ,
void T_9 * V_387 ,
T_3 * V_388 , T_7 * V_389 )
{
struct V_384 V_390 = * V_385 ;
int V_66 ;
V_390 . V_391 = & V_392 ;
V_390 . V_393 = & V_398 ;
V_66 = F_259 ( & V_390 , V_386 , V_387 , V_388 , V_389 ) ;
F_267 ( V_385 , V_386 ) ;
return V_66 ;
}
int F_270 ( struct V_384 * V_385 , int V_386 ,
void T_9 * V_387 , T_3 * V_388 , T_7 * V_389 )
{
int V_66 = F_271 ( V_385 , V_386 , V_387 , V_388 , V_389 ) ;
F_267 ( V_385 , V_386 ) ;
return V_66 ;
}
int F_272 ( struct V_384 * V_385 , int V_386 ,
void T_9 * V_387 ,
T_3 * V_388 , T_7 * V_389 )
{
int V_66 = F_273 ( V_385 , V_386 , V_387 , V_388 , V_389 ) ;
F_267 ( V_385 , V_386 ) ;
return V_66 ;
}
static int F_274 ( struct V_384 * V_385 , int V_386 ,
void T_9 * V_387 ,
T_3 * V_388 , T_7 * V_389 )
{
int V_66 = F_275 ( V_385 , V_386 , V_387 , V_388 , V_389 ) ;
F_267 ( V_385 , V_386 ) ;
return V_66 ;
}
int F_276 ( struct V_384 * V_385 , int V_386 ,
void T_9 * V_387 ,
T_3 * V_388 , T_7 * V_389 )
{
int V_66 = F_277 ( V_385 , V_386 , V_387 , V_388 , V_389 ) ;
F_267 ( V_385 , V_386 ) ;
return V_66 ;
}
static int F_278 ( struct V_384 * V_385 , int V_386 ,
void T_9 * V_387 ,
T_3 * V_388 , T_7 * V_389 )
{
int V_66 = F_258 ( V_385 , V_386 , V_387 , V_388 , V_389 ) ;
F_267 ( V_385 , V_386 ) ;
return V_66 ;
}
static int F_279 ( struct V_384 * V_385 , int V_386 ,
void T_9 * V_387 ,
T_3 * V_388 , T_7 * V_389 )
{
struct V_110 * V_120 = V_385 -> V_393 ;
int V_66 ;
if ( strcmp ( V_385 -> V_399 , L_22 ) == 0 )
V_66 = F_272 ( V_385 , V_386 , V_387 , V_388 , V_389 ) ;
else if ( strcmp ( V_385 -> V_399 , L_23 ) == 0 )
V_66 = F_276 ( V_385 , V_386 , V_387 , V_388 , V_389 ) ;
else
V_66 = - 1 ;
if ( V_386 && V_66 == 0 ) {
V_120 -> V_121 =
F_6 ( F_72 ( V_120 , V_97 ) ) ;
}
return V_66 ;
}
int F_280 ( struct V_35 * V_34 , struct V_110 * V_120 ,
T_10 * V_400 )
{
int V_13 ;
struct V_401 * V_353 ;
const char * V_402 ;
char V_403 [ sizeof( L_24 ) + V_404 + V_404 ] ;
char * V_405 ;
V_353 = F_148 ( & V_406 , sizeof( * V_353 ) , V_105 ) ;
if ( ! V_353 )
goto V_162;
for ( V_13 = 0 ; V_13 < V_407 ; V_13 ++ ) {
V_353 -> V_408 [ V_13 ] . V_395 += ( long ) V_120 ;
V_353 -> V_408 [ V_13 ] . V_391 = V_34 ;
V_353 -> V_408 [ V_13 ] . V_393 = V_120 ;
}
if ( V_34 ) {
V_402 = V_34 -> V_409 ;
memset ( & V_353 -> V_408 [ V_407 ] , 0 ,
sizeof( V_353 -> V_408 [ V_407 ] ) ) ;
} else {
struct V_10 * V_11 = V_120 -> V_11 ;
V_402 = L_25 ;
V_353 -> V_408 [ V_407 ] . V_395 = & V_11 -> V_269 ;
V_353 -> V_408 [ V_410 ] . V_395 = & V_11 -> V_122 ;
V_353 -> V_408 [ V_411 ] . V_395 = & V_11 -> V_47 ;
V_353 -> V_408 [ V_412 ] . V_395 = & V_11 -> V_46 ;
}
if ( V_400 ) {
V_353 -> V_408 [ V_413 ] . T_10 = V_400 ;
V_353 -> V_408 [ V_414 ] . T_10 = V_400 ;
V_353 -> V_408 [ V_415 ] . T_10 = V_400 ;
V_353 -> V_408 [ V_416 ] . T_10 = V_400 ;
} else {
V_353 -> V_408 [ V_414 ] . T_10 =
F_279 ;
V_353 -> V_408 [ V_416 ] . T_10 =
F_279 ;
}
if ( F_146 ( V_120 ) -> V_417 != & V_418 )
V_353 -> V_408 [ 0 ] . V_399 = NULL ;
switch ( F_264 ( V_120 ) ) {
case V_206 :
V_405 = L_26 ;
break;
case V_208 :
V_405 = L_27 ;
break;
default:
F_281 () ;
}
snprintf ( V_403 , sizeof( V_403 ) , L_28 ,
V_405 , V_402 ) ;
V_353 -> V_419 =
F_282 ( F_146 ( V_120 ) , V_403 , V_353 -> V_408 ) ;
if ( ! V_353 -> V_419 )
goto free;
V_120 -> V_193 = V_353 ;
return 0 ;
free:
F_54 ( V_353 ) ;
V_162:
return - V_90 ;
}
void F_283 ( struct V_110 * V_120 )
{
if ( V_120 -> V_193 ) {
struct V_401 * V_353 = V_120 -> V_193 ;
V_120 -> V_193 = NULL ;
F_284 ( V_353 -> V_419 ) ;
F_54 ( V_353 ) ;
}
}
static int T_11 F_285 ( void )
{
F_286 ( V_420 , V_342 , F_180 , NULL , NULL ) ;
F_286 ( V_420 , V_8 , F_172 , NULL , NULL ) ;
F_286 ( V_420 , V_382 , NULL , F_224 , NULL ) ;
F_286 ( V_420 , V_421 , NULL , F_211 ,
NULL ) ;
F_286 ( V_420 , V_422 , F_204 , NULL , NULL ) ;
return 0 ;
}
