static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_4 ) ;
return - V_5 ;
}
static void F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 -> V_7 )
V_2 -> V_6 -> V_7 ( V_2 ) ;
F_4 ( V_2 , V_8 , 0 , 0 ) ;
F_5 ( V_9 , V_2 ) ;
F_6 ( V_2 ) ;
}
unsigned long F_7 ( unsigned long V_10 )
{
return V_10 ? ( F_8 () % V_10 ) + ( V_10 >> 1 ) : 0 ;
}
static bool F_9 ( struct V_1 * V_11 , T_1 V_12 ,
struct V_1 T_2 * * V_13 , struct V_14 * V_15 )
{
bool V_16 = false ;
F_10 ( & V_11 -> V_17 ) ;
if ( F_11 ( & V_11 -> V_18 ) == 1 && ! ( V_11 -> V_19 & V_12 ) ) {
struct V_1 * V_2 ;
V_2 = F_12 ( V_11 -> V_20 ,
F_13 ( & V_15 -> V_17 ) ) ;
F_14 ( * V_13 , V_2 ) ;
V_11 -> V_21 = 1 ;
V_16 = true ;
}
F_15 ( & V_11 -> V_17 ) ;
if ( V_16 )
F_3 ( V_11 ) ;
return V_16 ;
}
bool F_16 ( struct V_1 * V_22 , struct V_14 * V_15 )
{
struct V_23 * V_24 ;
void * V_25 = V_22 -> V_26 ;
T_3 V_27 ;
struct V_1 * V_11 ;
struct V_1 T_2 * * V_13 ;
V_24 = F_12 ( V_15 -> V_24 ,
F_13 ( & V_15 -> V_17 ) ) ;
V_27 = V_15 -> V_28 ( V_25 , V_22 -> V_29 , V_24 -> V_30 ) ;
V_27 = V_27 >> ( 32 - V_24 -> V_31 ) ;
V_13 = & V_24 -> V_32 [ V_27 ] ;
while ( ( V_11 = F_12 ( * V_13 ,
F_13 ( & V_15 -> V_17 ) ) ) ) {
if ( V_11 == V_22 )
return F_9 ( V_11 , 0 , V_13 , V_15 ) ;
V_13 = & V_11 -> V_20 ;
}
return false ;
}
static int F_17 ( struct V_14 * V_15 )
{
int V_33 = 0 ;
int V_34 ;
struct V_23 * V_24 ;
F_18 ( V_15 , V_35 ) ;
F_19 ( & V_15 -> V_17 ) ;
V_24 = F_12 ( V_15 -> V_24 ,
F_13 ( & V_15 -> V_17 ) ) ;
for ( V_34 = 0 ; V_34 < ( 1 << V_24 -> V_31 ) ; V_34 ++ ) {
struct V_1 * V_11 ;
struct V_1 T_2 * * V_13 ;
V_13 = & V_24 -> V_32 [ V_34 ] ;
while ( ( V_11 = F_12 ( * V_13 ,
F_13 ( & V_15 -> V_17 ) ) ) != NULL ) {
if ( F_9 ( V_11 , V_36 , V_13 , V_15 ) ) {
V_33 = 1 ;
continue;
}
V_13 = & V_11 -> V_20 ;
}
}
V_15 -> V_37 = V_38 ;
F_20 ( & V_15 -> V_17 ) ;
return V_33 ;
}
static void F_21 ( struct V_1 * V_11 , unsigned long V_39 )
{
F_22 ( V_11 ) ;
if ( F_23 ( F_24 ( & V_11 -> V_40 , V_39 ) ) ) {
F_25 ( L_1 ,
V_11 -> V_19 ) ;
F_26 () ;
}
}
static int F_27 ( struct V_1 * V_11 )
{
if ( ( V_11 -> V_19 & V_41 ) &&
F_28 ( & V_11 -> V_40 ) ) {
F_6 ( V_11 ) ;
return 1 ;
}
return 0 ;
}
static void F_29 ( struct V_42 * V_43 )
{
struct V_3 * V_4 ;
while ( ( V_4 = F_30 ( V_43 ) ) != NULL ) {
F_31 ( V_4 -> V_29 ) ;
F_2 ( V_4 ) ;
}
}
static void F_32 ( struct V_14 * V_15 , struct V_44 * V_29 )
{
int V_34 ;
struct V_23 * V_24 ;
V_24 = F_12 ( V_15 -> V_24 ,
F_13 ( & V_15 -> V_17 ) ) ;
for ( V_34 = 0 ; V_34 < ( 1 << V_24 -> V_31 ) ; V_34 ++ ) {
struct V_1 * V_11 ;
struct V_1 T_2 * * V_13 = & V_24 -> V_32 [ V_34 ] ;
while ( ( V_11 = F_12 ( * V_13 ,
F_13 ( & V_15 -> V_17 ) ) ) != NULL ) {
if ( V_29 && V_11 -> V_29 != V_29 ) {
V_13 = & V_11 -> V_20 ;
continue;
}
F_14 ( * V_13 ,
F_12 ( V_11 -> V_20 ,
F_13 ( & V_15 -> V_17 ) ) ) ;
F_10 ( & V_11 -> V_17 ) ;
F_27 ( V_11 ) ;
V_11 -> V_21 = 1 ;
if ( F_11 ( & V_11 -> V_18 ) != 1 ) {
F_33 ( & V_11 -> V_45 ) ;
V_11 -> V_46 = 0 ;
V_11 -> V_47 = F_1 ;
if ( V_11 -> V_19 & V_48 )
V_11 -> V_19 = V_49 ;
else
V_11 -> V_19 = V_50 ;
F_34 ( 2 , L_2 , V_11 ) ;
}
F_15 ( & V_11 -> V_17 ) ;
F_3 ( V_11 ) ;
}
}
}
void F_35 ( struct V_14 * V_15 , struct V_44 * V_29 )
{
F_19 ( & V_15 -> V_17 ) ;
F_32 ( V_15 , V_29 ) ;
F_20 ( & V_15 -> V_17 ) ;
}
int F_36 ( struct V_14 * V_15 , struct V_44 * V_29 )
{
F_19 ( & V_15 -> V_17 ) ;
F_32 ( V_15 , V_29 ) ;
F_37 ( V_15 , V_29 ) ;
F_20 ( & V_15 -> V_17 ) ;
F_38 ( & V_15 -> V_51 ) ;
F_29 ( & V_15 -> V_52 ) ;
return 0 ;
}
static struct V_1 * F_39 ( struct V_14 * V_15 , struct V_44 * V_29 )
{
struct V_1 * V_11 = NULL ;
unsigned long V_53 = V_38 ;
int V_54 ;
V_54 = F_40 ( & V_15 -> V_54 ) - 1 ;
if ( V_54 >= V_15 -> V_55 ||
( V_54 >= V_15 -> V_56 &&
F_41 ( V_53 , V_15 -> V_37 + 5 * V_57 ) ) ) {
if ( ! F_17 ( V_15 ) &&
V_54 >= V_15 -> V_55 ) {
F_42 ( L_3 ,
V_15 -> V_58 ) ;
F_18 ( V_15 , V_59 ) ;
goto V_60;
}
}
V_11 = F_43 ( V_15 -> V_61 + V_29 -> V_62 , V_63 ) ;
if ( ! V_11 )
goto V_60;
F_44 ( & V_11 -> V_45 ) ;
F_45 ( & V_11 -> V_17 ) ;
F_46 ( & V_11 -> V_64 ) ;
V_11 -> V_65 = V_11 -> V_66 = V_53 ;
V_11 -> V_19 = V_50 ;
V_11 -> V_47 = F_1 ;
F_46 ( & V_11 -> V_67 . V_68 ) ;
V_11 -> V_6 = F_47 ( & V_15 -> V_6 ) ;
F_48 ( & V_11 -> V_40 , V_69 , ( unsigned long ) V_11 ) ;
F_18 ( V_15 , V_70 ) ;
V_11 -> V_15 = V_15 ;
F_49 ( & V_11 -> V_18 , 1 ) ;
V_11 -> V_21 = 1 ;
V_71:
return V_11 ;
V_60:
F_50 ( & V_15 -> V_54 ) ;
goto V_71;
}
static void F_51 ( T_3 * V_72 )
{
* V_72 = F_52 () | 1 ;
}
static struct V_23 * F_53 ( unsigned int V_73 )
{
T_4 V_74 = ( 1 << V_73 ) * sizeof( struct V_1 * ) ;
struct V_23 * V_75 ;
struct V_1 T_2 * * V_76 ;
int V_34 ;
V_75 = F_54 ( sizeof( * V_75 ) , V_63 ) ;
if ( ! V_75 )
return NULL ;
if ( V_74 <= V_77 )
V_76 = F_43 ( V_74 , V_63 ) ;
else
V_76 = (struct V_1 T_2 * * )
F_55 ( V_63 | V_78 ,
F_56 ( V_74 ) ) ;
if ( ! V_76 ) {
F_57 ( V_75 ) ;
return NULL ;
}
V_75 -> V_32 = V_76 ;
V_75 -> V_31 = V_73 ;
for ( V_34 = 0 ; V_34 < V_79 ; V_34 ++ )
F_51 ( & V_75 -> V_30 [ V_34 ] ) ;
return V_75 ;
}
static void F_58 ( struct V_80 * V_81 )
{
struct V_23 * V_24 = F_59 ( V_81 ,
struct V_23 ,
V_82 ) ;
T_4 V_74 = ( 1 << V_24 -> V_31 ) * sizeof( struct V_1 * ) ;
struct V_1 T_2 * * V_76 = V_24 -> V_32 ;
if ( V_74 <= V_77 )
F_57 ( V_76 ) ;
else
F_60 ( ( unsigned long ) V_76 , F_56 ( V_74 ) ) ;
F_57 ( V_24 ) ;
}
static struct V_23 * F_61 ( struct V_14 * V_15 ,
unsigned long V_83 )
{
unsigned int V_34 , V_28 ;
struct V_23 * V_84 , * V_85 ;
F_18 ( V_15 , V_86 ) ;
V_85 = F_12 ( V_15 -> V_24 ,
F_13 ( & V_15 -> V_17 ) ) ;
V_84 = F_53 ( V_83 ) ;
if ( ! V_84 )
return V_85 ;
for ( V_34 = 0 ; V_34 < ( 1 << V_85 -> V_31 ) ; V_34 ++ ) {
struct V_1 * V_11 , * V_20 ;
for ( V_11 = F_12 ( V_85 -> V_32 [ V_34 ] ,
F_13 ( & V_15 -> V_17 ) ) ;
V_11 != NULL ;
V_11 = V_20 ) {
V_28 = V_15 -> V_28 ( V_11 -> V_26 , V_11 -> V_29 ,
V_84 -> V_30 ) ;
V_28 >>= ( 32 - V_84 -> V_31 ) ;
V_20 = F_12 ( V_11 -> V_20 ,
F_13 ( & V_15 -> V_17 ) ) ;
F_14 ( V_11 -> V_20 ,
F_12 (
V_84 -> V_32 [ V_28 ] ,
F_13 ( & V_15 -> V_17 ) ) ) ;
F_14 ( V_84 -> V_32 [ V_28 ] , V_11 ) ;
}
}
F_14 ( V_15 -> V_24 , V_84 ) ;
F_62 ( & V_85 -> V_82 , F_58 ) ;
return V_84 ;
}
struct V_1 * F_63 ( struct V_14 * V_15 , const void * V_25 ,
struct V_44 * V_29 )
{
struct V_1 * V_11 ;
F_18 ( V_15 , V_87 ) ;
F_64 () ;
V_11 = F_65 ( V_15 , V_25 , V_29 ) ;
if ( V_11 ) {
if ( ! F_66 ( & V_11 -> V_18 ) )
V_11 = NULL ;
F_18 ( V_15 , V_88 ) ;
}
F_67 () ;
return V_11 ;
}
struct V_1 * F_68 ( struct V_14 * V_15 , struct V_89 * V_89 ,
const void * V_25 )
{
struct V_1 * V_11 ;
int V_90 = V_15 -> V_90 ;
T_3 V_27 ;
struct V_23 * V_24 ;
F_18 ( V_15 , V_87 ) ;
F_64 () ;
V_24 = F_69 ( V_15 -> V_24 ) ;
V_27 = V_15 -> V_28 ( V_25 , NULL , V_24 -> V_30 ) >> ( 32 - V_24 -> V_31 ) ;
for ( V_11 = F_69 ( V_24 -> V_32 [ V_27 ] ) ;
V_11 != NULL ;
V_11 = F_69 ( V_11 -> V_20 ) ) {
if ( ! memcmp ( V_11 -> V_26 , V_25 , V_90 ) &&
F_70 ( F_71 ( V_11 -> V_29 ) , V_89 ) ) {
if ( ! F_66 ( & V_11 -> V_18 ) )
V_11 = NULL ;
F_18 ( V_15 , V_88 ) ;
break;
}
}
F_67 () ;
return V_11 ;
}
struct V_1 * F_72 ( struct V_14 * V_15 , const void * V_25 ,
struct V_44 * V_29 , bool V_91 )
{
T_3 V_27 ;
int V_90 = V_15 -> V_90 ;
int error ;
struct V_1 * V_92 , * V_93 , * V_11 = F_39 ( V_15 , V_29 ) ;
struct V_23 * V_24 ;
if ( ! V_11 ) {
V_93 = F_73 ( - V_94 ) ;
goto V_71;
}
memcpy ( V_11 -> V_26 , V_25 , V_90 ) ;
V_11 -> V_29 = V_29 ;
F_74 ( V_29 ) ;
if ( V_15 -> V_95 && ( error = V_15 -> V_95 ( V_11 ) ) < 0 ) {
V_93 = F_73 ( error ) ;
goto V_96;
}
if ( V_29 -> V_97 -> V_98 ) {
error = V_29 -> V_97 -> V_98 ( V_29 , V_11 ) ;
if ( error < 0 ) {
V_93 = F_73 ( error ) ;
goto V_96;
}
}
if ( V_11 -> V_6 -> V_99 &&
( error = V_11 -> V_6 -> V_99 ( V_11 ) ) < 0 ) {
V_93 = F_73 ( error ) ;
goto V_96;
}
V_11 -> V_100 = V_38 - ( F_75 ( V_11 -> V_6 , V_101 ) << 1 ) ;
F_19 ( & V_15 -> V_17 ) ;
V_24 = F_12 ( V_15 -> V_24 ,
F_13 ( & V_15 -> V_17 ) ) ;
if ( F_76 ( & V_15 -> V_54 ) > ( 1 << V_24 -> V_31 ) )
V_24 = F_61 ( V_15 , V_24 -> V_31 + 1 ) ;
V_27 = V_15 -> V_28 ( V_25 , V_29 , V_24 -> V_30 ) >> ( 32 - V_24 -> V_31 ) ;
if ( V_11 -> V_6 -> V_21 ) {
V_93 = F_73 ( - V_102 ) ;
goto V_103;
}
for ( V_92 = F_12 ( V_24 -> V_32 [ V_27 ] ,
F_13 ( & V_15 -> V_17 ) ) ;
V_92 != NULL ;
V_92 = F_12 ( V_92 -> V_20 ,
F_13 ( & V_15 -> V_17 ) ) ) {
if ( V_29 == V_92 -> V_29 && ! memcmp ( V_92 -> V_26 , V_25 , V_90 ) ) {
if ( V_91 )
F_22 ( V_92 ) ;
V_93 = V_92 ;
goto V_103;
}
}
V_11 -> V_21 = 0 ;
if ( V_91 )
F_22 ( V_11 ) ;
F_14 ( V_11 -> V_20 ,
F_12 ( V_24 -> V_32 [ V_27 ] ,
F_13 ( & V_15 -> V_17 ) ) ) ;
F_14 ( V_24 -> V_32 [ V_27 ] , V_11 ) ;
F_20 ( & V_15 -> V_17 ) ;
F_34 ( 2 , L_4 , V_11 ) ;
V_93 = V_11 ;
V_71:
return V_93 ;
V_103:
F_20 ( & V_15 -> V_17 ) ;
V_96:
F_6 ( V_11 ) ;
goto V_71;
}
static T_3 F_77 ( const void * V_25 , int V_90 )
{
T_3 V_27 = * ( T_3 * ) ( V_25 + V_90 - 4 ) ;
V_27 ^= ( V_27 >> 16 ) ;
V_27 ^= V_27 >> 8 ;
V_27 ^= V_27 >> 4 ;
V_27 &= V_104 ;
return V_27 ;
}
static struct V_105 * F_78 ( struct V_105 * V_11 ,
struct V_89 * V_89 ,
const void * V_25 ,
int V_90 ,
struct V_44 * V_29 )
{
while ( V_11 ) {
if ( ! memcmp ( V_11 -> V_106 , V_25 , V_90 ) &&
F_70 ( F_79 ( V_11 ) , V_89 ) &&
( V_11 -> V_29 == V_29 || ! V_11 -> V_29 ) )
return V_11 ;
V_11 = V_11 -> V_20 ;
}
return NULL ;
}
struct V_105 * F_80 ( struct V_14 * V_15 ,
struct V_89 * V_89 , const void * V_25 , struct V_44 * V_29 )
{
int V_90 = V_15 -> V_90 ;
T_3 V_27 = F_77 ( V_25 , V_90 ) ;
return F_78 ( V_15 -> V_107 [ V_27 ] ,
V_89 , V_25 , V_90 , V_29 ) ;
}
struct V_105 * F_81 ( struct V_14 * V_15 ,
struct V_89 * V_89 , const void * V_25 ,
struct V_44 * V_29 , int V_108 )
{
struct V_105 * V_11 ;
int V_90 = V_15 -> V_90 ;
T_3 V_27 = F_77 ( V_25 , V_90 ) ;
F_82 ( & V_15 -> V_17 ) ;
V_11 = F_78 ( V_15 -> V_107 [ V_27 ] ,
V_89 , V_25 , V_90 , V_29 ) ;
F_83 ( & V_15 -> V_17 ) ;
if ( V_11 || ! V_108 )
goto V_71;
F_84 () ;
V_11 = F_54 ( sizeof( * V_11 ) + V_90 , V_109 ) ;
if ( ! V_11 )
goto V_71;
F_85 ( & V_11 -> V_89 , V_89 ) ;
memcpy ( V_11 -> V_106 , V_25 , V_90 ) ;
V_11 -> V_29 = V_29 ;
if ( V_29 )
F_74 ( V_29 ) ;
if ( V_15 -> V_110 && V_15 -> V_110 ( V_11 ) ) {
if ( V_29 )
F_31 ( V_29 ) ;
F_57 ( V_11 ) ;
V_11 = NULL ;
goto V_71;
}
F_19 ( & V_15 -> V_17 ) ;
V_11 -> V_20 = V_15 -> V_107 [ V_27 ] ;
V_15 -> V_107 [ V_27 ] = V_11 ;
F_20 ( & V_15 -> V_17 ) ;
V_71:
return V_11 ;
}
int F_86 ( struct V_14 * V_15 , struct V_89 * V_89 , const void * V_25 ,
struct V_44 * V_29 )
{
struct V_105 * V_11 , * * V_13 ;
int V_90 = V_15 -> V_90 ;
T_3 V_27 = F_77 ( V_25 , V_90 ) ;
F_19 ( & V_15 -> V_17 ) ;
for ( V_13 = & V_15 -> V_107 [ V_27 ] ; ( V_11 = * V_13 ) != NULL ;
V_13 = & V_11 -> V_20 ) {
if ( ! memcmp ( V_11 -> V_106 , V_25 , V_90 ) && V_11 -> V_29 == V_29 &&
F_70 ( F_79 ( V_11 ) , V_89 ) ) {
* V_13 = V_11 -> V_20 ;
F_20 ( & V_15 -> V_17 ) ;
if ( V_15 -> V_111 )
V_15 -> V_111 ( V_11 ) ;
if ( V_11 -> V_29 )
F_31 ( V_11 -> V_29 ) ;
F_57 ( V_11 ) ;
return 0 ;
}
}
F_20 ( & V_15 -> V_17 ) ;
return - V_112 ;
}
static int F_37 ( struct V_14 * V_15 , struct V_44 * V_29 )
{
struct V_105 * V_11 , * * V_13 ;
T_3 V_113 ;
for ( V_113 = 0 ; V_113 <= V_104 ; V_113 ++ ) {
V_13 = & V_15 -> V_107 [ V_113 ] ;
while ( ( V_11 = * V_13 ) != NULL ) {
if ( ! V_29 || V_11 -> V_29 == V_29 ) {
* V_13 = V_11 -> V_20 ;
if ( V_15 -> V_111 )
V_15 -> V_111 ( V_11 ) ;
if ( V_11 -> V_29 )
F_31 ( V_11 -> V_29 ) ;
F_57 ( V_11 ) ;
continue;
}
V_13 = & V_11 -> V_20 ;
}
}
return - V_112 ;
}
static inline void F_87 ( struct V_114 * V_6 )
{
if ( F_88 ( & V_6 -> V_18 ) )
F_89 ( V_6 ) ;
}
void F_90 ( struct V_1 * V_2 )
{
struct V_44 * V_29 = V_2 -> V_29 ;
F_18 ( V_2 -> V_15 , V_115 ) ;
if ( ! V_2 -> V_21 ) {
F_91 ( L_5 , V_2 ) ;
F_26 () ;
return;
}
if ( F_27 ( V_2 ) )
F_91 ( L_6 ) ;
F_19 ( & V_2 -> V_17 ) ;
F_33 ( & V_2 -> V_45 ) ;
F_20 ( & V_2 -> V_17 ) ;
V_2 -> V_46 = 0 ;
if ( V_29 -> V_97 -> V_116 )
V_29 -> V_97 -> V_116 ( V_29 , V_2 ) ;
F_31 ( V_29 ) ;
F_87 ( V_2 -> V_6 ) ;
F_34 ( 2 , L_7 , V_2 ) ;
F_50 ( & V_2 -> V_15 -> V_54 ) ;
F_92 ( V_2 , V_82 ) ;
}
static void F_93 ( struct V_1 * V_2 )
{
F_34 ( 2 , L_8 , V_2 ) ;
V_2 -> V_47 = V_2 -> V_117 -> V_47 ;
}
static void F_94 ( struct V_1 * V_2 )
{
F_34 ( 2 , L_9 , V_2 ) ;
V_2 -> V_47 = V_2 -> V_117 -> V_118 ;
}
static void F_95 ( struct V_119 * V_120 )
{
struct V_14 * V_15 = F_59 ( V_120 , struct V_14 , V_121 . V_120 ) ;
struct V_1 * V_11 ;
struct V_1 T_2 * * V_13 ;
unsigned int V_34 ;
struct V_23 * V_24 ;
F_18 ( V_15 , V_122 ) ;
F_19 ( & V_15 -> V_17 ) ;
V_24 = F_12 ( V_15 -> V_24 ,
F_13 ( & V_15 -> V_17 ) ) ;
if ( F_41 ( V_38 , V_15 -> V_123 + 300 * V_57 ) ) {
struct V_114 * V_124 ;
V_15 -> V_123 = V_38 ;
F_96 (p, &tbl->parms_list, list)
V_124 -> V_125 =
F_7 ( F_75 ( V_124 , V_101 ) ) ;
}
if ( F_76 ( & V_15 -> V_54 ) < V_15 -> V_126 )
goto V_71;
for ( V_34 = 0 ; V_34 < ( 1 << V_24 -> V_31 ) ; V_34 ++ ) {
V_13 = & V_24 -> V_32 [ V_34 ] ;
while ( ( V_11 = F_12 ( * V_13 ,
F_13 ( & V_15 -> V_17 ) ) ) != NULL ) {
unsigned int V_12 ;
F_10 ( & V_11 -> V_17 ) ;
V_12 = V_11 -> V_19 ;
if ( V_12 & ( V_36 | V_41 ) ) {
F_15 ( & V_11 -> V_17 ) ;
goto V_127;
}
if ( F_97 ( V_11 -> V_66 , V_11 -> V_100 ) )
V_11 -> V_66 = V_11 -> V_100 ;
if ( F_11 ( & V_11 -> V_18 ) == 1 &&
( V_12 == V_128 ||
F_41 ( V_38 , V_11 -> V_66 + F_75 ( V_11 -> V_6 , V_129 ) ) ) ) {
* V_13 = V_11 -> V_20 ;
V_11 -> V_21 = 1 ;
F_15 ( & V_11 -> V_17 ) ;
F_3 ( V_11 ) ;
continue;
}
F_15 ( & V_11 -> V_17 ) ;
V_127:
V_13 = & V_11 -> V_20 ;
}
F_20 ( & V_15 -> V_17 ) ;
F_98 () ;
F_19 ( & V_15 -> V_17 ) ;
V_24 = F_12 ( V_15 -> V_24 ,
F_13 ( & V_15 -> V_17 ) ) ;
}
V_71:
F_99 ( V_130 , & V_15 -> V_121 ,
F_75 ( & V_15 -> V_6 , V_101 ) >> 1 ) ;
F_20 ( & V_15 -> V_17 ) ;
}
static T_5 int F_100 ( struct V_1 * V_11 )
{
struct V_114 * V_124 = V_11 -> V_6 ;
return F_75 ( V_124 , V_131 ) + F_75 ( V_124 , V_132 ) +
( V_11 -> V_19 & V_133 ? F_75 ( V_124 , V_134 ) :
F_75 ( V_124 , V_135 ) ) ;
}
static void F_101 ( struct V_1 * V_2 )
__releases( V_2 -> V_17 )
__acquires( V_2 -> V_17 )
{
struct V_3 * V_4 ;
F_18 ( V_2 -> V_15 , V_136 ) ;
F_34 ( 2 , L_10 , V_2 ) ;
V_2 -> V_65 = V_38 ;
while ( V_2 -> V_19 == V_128 &&
( V_4 = F_102 ( & V_2 -> V_45 ) ) != NULL ) {
F_15 ( & V_2 -> V_17 ) ;
V_2 -> V_117 -> V_137 ( V_2 , V_4 ) ;
F_10 ( & V_2 -> V_17 ) ;
}
F_33 ( & V_2 -> V_45 ) ;
V_2 -> V_46 = 0 ;
}
static void F_103 ( struct V_1 * V_2 )
__releases( V_2 -> V_17 )
{
struct V_3 * V_4 = F_104 ( & V_2 -> V_45 ) ;
if ( V_4 )
V_4 = F_105 ( V_4 , V_63 ) ;
F_15 ( & V_2 -> V_17 ) ;
if ( V_2 -> V_117 -> V_138 )
V_2 -> V_117 -> V_138 ( V_2 , V_4 ) ;
F_106 ( & V_2 -> V_139 ) ;
F_2 ( V_4 ) ;
}
static void V_69 ( unsigned long V_140 )
{
unsigned long V_53 , V_20 ;
struct V_1 * V_2 = (struct V_1 * ) V_140 ;
unsigned int V_12 ;
int V_141 = 0 ;
F_10 ( & V_2 -> V_17 ) ;
V_12 = V_2 -> V_19 ;
V_53 = V_38 ;
V_20 = V_53 + V_57 ;
if ( ! ( V_12 & V_41 ) )
goto V_71;
if ( V_12 & V_142 ) {
if ( F_107 ( V_53 ,
V_2 -> V_100 + V_2 -> V_6 -> V_125 ) ) {
F_34 ( 2 , L_11 , V_2 ) ;
V_20 = V_2 -> V_100 + V_2 -> V_6 -> V_125 ;
} else if ( F_107 ( V_53 ,
V_2 -> V_66 +
F_75 ( V_2 -> V_6 , V_143 ) ) ) {
F_34 ( 2 , L_12 , V_2 ) ;
V_2 -> V_19 = V_144 ;
V_2 -> V_65 = V_38 ;
F_93 ( V_2 ) ;
V_20 = V_53 + F_75 ( V_2 -> V_6 , V_143 ) ;
} else {
F_34 ( 2 , L_8 , V_2 ) ;
V_2 -> V_19 = V_145 ;
V_2 -> V_65 = V_38 ;
F_93 ( V_2 ) ;
V_141 = 1 ;
}
} else if ( V_12 & V_144 ) {
if ( F_107 ( V_53 ,
V_2 -> V_100 +
F_75 ( V_2 -> V_6 , V_143 ) ) ) {
F_34 ( 2 , L_13 , V_2 ) ;
V_2 -> V_19 = V_142 ;
V_2 -> V_65 = V_38 ;
F_94 ( V_2 ) ;
V_141 = 1 ;
V_20 = V_2 -> V_100 + V_2 -> V_6 -> V_125 ;
} else {
F_34 ( 2 , L_14 , V_2 ) ;
V_2 -> V_19 = V_133 ;
V_2 -> V_65 = V_38 ;
F_108 ( & V_2 -> V_139 , 0 ) ;
V_141 = 1 ;
V_20 = V_53 + F_75 ( V_2 -> V_6 , V_146 ) ;
}
} else {
V_20 = V_53 + F_75 ( V_2 -> V_6 , V_146 ) ;
}
if ( ( V_2 -> V_19 & ( V_147 | V_133 ) ) &&
F_76 ( & V_2 -> V_139 ) >= F_100 ( V_2 ) ) {
V_2 -> V_19 = V_128 ;
V_141 = 1 ;
F_101 ( V_2 ) ;
goto V_71;
}
if ( V_2 -> V_19 & V_41 ) {
if ( F_97 ( V_20 , V_38 + V_57 / 2 ) )
V_20 = V_38 + V_57 / 2 ;
if ( ! F_24 ( & V_2 -> V_40 , V_20 ) )
F_22 ( V_2 ) ;
}
if ( V_2 -> V_19 & ( V_147 | V_133 ) ) {
F_103 ( V_2 ) ;
} else {
V_71:
F_15 ( & V_2 -> V_17 ) ;
}
if ( V_141 )
F_109 ( V_2 , 0 ) ;
F_6 ( V_2 ) ;
}
int F_110 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_93 ;
bool V_148 = false ;
F_19 ( & V_2 -> V_17 ) ;
V_93 = 0 ;
if ( V_2 -> V_19 & ( V_149 | V_144 | V_133 ) )
goto V_150;
if ( V_2 -> V_21 )
goto V_151;
if ( ! ( V_2 -> V_19 & ( V_145 | V_147 ) ) ) {
if ( F_75 ( V_2 -> V_6 , V_135 ) +
F_75 ( V_2 -> V_6 , V_132 ) ) {
unsigned long V_20 , V_53 = V_38 ;
F_108 ( & V_2 -> V_139 ,
F_75 ( V_2 -> V_6 , V_131 ) ) ;
V_2 -> V_19 = V_147 ;
V_2 -> V_65 = V_53 ;
V_20 = V_53 + F_111 ( F_75 ( V_2 -> V_6 , V_146 ) ,
V_57 / 2 ) ;
F_21 ( V_2 , V_20 ) ;
V_148 = true ;
} else {
V_2 -> V_19 = V_128 ;
V_2 -> V_65 = V_38 ;
F_20 ( & V_2 -> V_17 ) ;
F_2 ( V_4 ) ;
return 1 ;
}
} else if ( V_2 -> V_19 & V_145 ) {
F_34 ( 2 , L_12 , V_2 ) ;
V_2 -> V_19 = V_144 ;
V_2 -> V_65 = V_38 ;
F_21 ( V_2 , V_38 +
F_75 ( V_2 -> V_6 , V_143 ) ) ;
}
if ( V_2 -> V_19 == V_147 ) {
if ( V_4 ) {
while ( V_2 -> V_46 + V_4 -> V_152 >
F_75 ( V_2 -> V_6 , V_153 ) ) {
struct V_3 * V_154 ;
V_154 = F_102 ( & V_2 -> V_45 ) ;
if ( ! V_154 )
break;
V_2 -> V_46 -= V_154 -> V_152 ;
F_2 ( V_154 ) ;
F_18 ( V_2 -> V_15 , V_155 ) ;
}
F_112 ( V_4 ) ;
F_113 ( & V_2 -> V_45 , V_4 ) ;
V_2 -> V_46 += V_4 -> V_152 ;
}
V_93 = 1 ;
}
V_150:
if ( V_148 )
F_103 ( V_2 ) ;
else
F_15 ( & V_2 -> V_17 ) ;
F_114 () ;
return V_93 ;
V_151:
if ( V_2 -> V_19 & V_145 )
goto V_150;
F_20 ( & V_2 -> V_17 ) ;
F_2 ( V_4 ) ;
return 1 ;
}
static void F_115 ( struct V_1 * V_2 )
{
struct V_156 * V_67 ;
void (* F_116)( struct V_156 * , const struct V_44 * , const unsigned char * )
= NULL ;
if ( V_2 -> V_29 -> V_157 )
F_116 = V_2 -> V_29 -> V_157 -> V_158 ;
if ( F_116 ) {
V_67 = & V_2 -> V_67 ;
if ( V_67 -> V_159 ) {
F_117 ( & V_67 -> V_68 ) ;
F_116 ( V_67 , V_2 -> V_29 , V_2 -> V_160 ) ;
F_118 ( & V_67 -> V_68 ) ;
}
}
}
int F_119 ( struct V_1 * V_2 , const T_6 * V_161 , T_6 V_162 ,
T_3 V_163 , T_3 V_164 )
{
T_6 V_165 ;
int V_166 ;
int V_141 = 0 ;
struct V_44 * V_29 ;
int V_167 = 0 ;
F_19 ( & V_2 -> V_17 ) ;
V_29 = V_2 -> V_29 ;
V_165 = V_2 -> V_19 ;
V_166 = - V_168 ;
if ( ! ( V_163 & V_169 ) &&
( V_165 & ( V_49 | V_36 ) ) )
goto V_71;
if ( V_2 -> V_21 )
goto V_71;
if ( ! ( V_162 & V_48 ) ) {
F_27 ( V_2 ) ;
if ( V_165 & V_149 )
F_93 ( V_2 ) ;
V_2 -> V_19 = V_162 ;
V_166 = 0 ;
V_141 = V_165 & V_48 ;
if ( ( V_165 & ( V_147 | V_133 ) ) &&
( V_162 & V_128 ) ) {
F_101 ( V_2 ) ;
V_141 = 1 ;
}
goto V_71;
}
if ( ! V_29 -> V_170 ) {
V_161 = V_2 -> V_160 ;
} else if ( V_161 ) {
if ( ( V_165 & V_48 ) &&
! memcmp ( V_161 , V_2 -> V_160 , V_29 -> V_170 ) )
V_161 = V_2 -> V_160 ;
} else {
V_166 = - V_102 ;
if ( ! ( V_165 & V_48 ) )
goto V_71;
V_161 = V_2 -> V_160 ;
}
V_166 = 0 ;
V_167 = V_163 & V_171 ;
if ( V_165 & V_48 ) {
if ( V_161 != V_2 -> V_160 && ! ( V_163 & V_172 ) ) {
V_167 = 0 ;
if ( ( V_163 & V_173 ) &&
( V_165 & V_149 ) ) {
V_161 = V_2 -> V_160 ;
V_162 = V_145 ;
} else
goto V_71;
} else {
if ( V_161 == V_2 -> V_160 && V_162 == V_145 &&
! ( V_163 & V_169 ) )
V_162 = V_165 ;
}
}
if ( V_162 != V_165 || V_161 != V_2 -> V_160 ) {
if ( V_162 & V_149 )
V_2 -> V_100 = V_38 ;
V_2 -> V_65 = V_38 ;
}
if ( V_162 != V_165 ) {
F_27 ( V_2 ) ;
if ( V_162 & V_133 )
F_108 ( & V_2 -> V_139 , 0 ) ;
if ( V_162 & V_41 )
F_21 ( V_2 , ( V_38 +
( ( V_162 & V_142 ) ?
V_2 -> V_6 -> V_125 :
0 ) ) ) ;
V_2 -> V_19 = V_162 ;
V_141 = 1 ;
}
if ( V_161 != V_2 -> V_160 ) {
F_120 ( & V_2 -> V_64 ) ;
memcpy ( & V_2 -> V_160 , V_161 , V_29 -> V_170 ) ;
F_121 ( & V_2 -> V_64 ) ;
F_115 ( V_2 ) ;
if ( ! ( V_162 & V_149 ) )
V_2 -> V_100 = V_38 -
( F_75 ( V_2 -> V_6 , V_101 ) << 1 ) ;
V_141 = 1 ;
}
if ( V_162 == V_165 )
goto V_71;
if ( V_162 & V_149 )
F_94 ( V_2 ) ;
else
F_93 ( V_2 ) ;
if ( ! ( V_165 & V_48 ) ) {
struct V_3 * V_4 ;
while ( V_2 -> V_19 & V_48 &&
( V_4 = F_102 ( & V_2 -> V_45 ) ) != NULL ) {
struct V_174 * V_175 = F_122 ( V_4 ) ;
struct V_1 * V_176 , * V_92 = V_2 ;
F_20 ( & V_2 -> V_17 ) ;
F_123 () ;
V_176 = NULL ;
if ( V_175 ) {
V_176 = F_124 ( V_175 , V_4 ) ;
if ( V_176 )
V_92 = V_176 ;
}
V_92 -> V_47 ( V_92 , V_4 ) ;
if ( V_176 )
F_6 ( V_176 ) ;
F_125 () ;
F_19 ( & V_2 -> V_17 ) ;
}
F_33 ( & V_2 -> V_45 ) ;
V_2 -> V_46 = 0 ;
}
V_71:
if ( V_167 ) {
V_2 -> V_163 = ( V_163 & V_177 ) ?
( V_2 -> V_163 | V_178 ) :
( V_2 -> V_163 & ~ V_178 ) ;
}
F_20 ( & V_2 -> V_17 ) ;
if ( V_141 )
F_109 ( V_2 , V_164 ) ;
return V_166 ;
}
void F_126 ( struct V_1 * V_2 )
{
if ( V_2 -> V_21 )
return;
V_2 -> V_65 = V_38 ;
if ( ! ( V_2 -> V_19 & V_128 ) )
return;
V_2 -> V_19 = V_147 ;
F_108 ( & V_2 -> V_139 , F_100 ( V_2 ) ) ;
F_21 ( V_2 ,
V_38 + F_75 ( V_2 -> V_6 , V_146 ) ) ;
}
struct V_1 * F_127 ( struct V_14 * V_15 ,
T_6 * V_161 , void * V_179 ,
struct V_44 * V_29 )
{
struct V_1 * V_2 = F_128 ( V_15 , V_179 , V_29 ,
V_161 || ! V_29 -> V_170 ) ;
if ( V_2 )
F_119 ( V_2 , V_161 , V_145 ,
V_172 , 0 ) ;
return V_2 ;
}
static void F_129 ( struct V_1 * V_11 )
{
struct V_44 * V_29 = V_11 -> V_29 ;
T_7 V_180 = V_11 -> V_15 -> V_181 ;
struct V_156 * V_67 = & V_11 -> V_67 ;
F_19 ( & V_11 -> V_17 ) ;
if ( ! V_67 -> V_159 )
V_29 -> V_157 -> V_182 ( V_11 , V_67 , V_180 ) ;
F_20 ( & V_11 -> V_17 ) ;
}
int F_130 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_93 = 0 ;
if ( ! F_131 ( V_2 , V_4 ) ) {
int V_166 ;
struct V_44 * V_29 = V_2 -> V_29 ;
unsigned int V_183 ;
if ( V_29 -> V_157 -> V_182 && ! V_2 -> V_67 . V_159 )
F_129 ( V_2 ) ;
do {
F_132 ( V_4 , F_133 ( V_4 ) ) ;
V_183 = F_134 ( & V_2 -> V_64 ) ;
V_166 = F_135 ( V_4 , V_29 , F_136 ( V_4 -> V_181 ) ,
V_2 -> V_160 , NULL , V_4 -> V_184 ) ;
} while ( F_137 ( & V_2 -> V_64 , V_183 ) );
if ( V_166 >= 0 )
V_93 = F_138 ( V_4 ) ;
else
goto V_185;
}
V_71:
return V_93 ;
V_185:
V_93 = - V_102 ;
F_2 ( V_4 ) ;
goto V_71;
}
int F_139 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_44 * V_29 = V_2 -> V_29 ;
unsigned int V_183 ;
int V_166 ;
do {
F_132 ( V_4 , F_133 ( V_4 ) ) ;
V_183 = F_134 ( & V_2 -> V_64 ) ;
V_166 = F_135 ( V_4 , V_29 , F_136 ( V_4 -> V_181 ) ,
V_2 -> V_160 , NULL , V_4 -> V_184 ) ;
} while ( F_137 ( & V_2 -> V_64 , V_183 ) );
if ( V_166 >= 0 )
V_166 = F_138 ( V_4 ) ;
else {
V_166 = - V_102 ;
F_2 ( V_4 ) ;
}
return V_166 ;
}
int F_140 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return F_138 ( V_4 ) ;
}
static void F_141 ( unsigned long V_140 )
{
struct V_14 * V_15 = (struct V_14 * ) V_140 ;
long V_186 = 0 ;
unsigned long V_53 = V_38 ;
struct V_3 * V_4 , * V_11 ;
F_142 ( & V_15 -> V_52 . V_17 ) ;
F_143 (&tbl->proxy_queue, skb, n) {
long V_187 = F_144 ( V_4 ) -> V_186 - V_53 ;
if ( V_187 <= 0 ) {
struct V_44 * V_29 = V_4 -> V_29 ;
F_145 ( V_4 , & V_15 -> V_52 ) ;
if ( V_15 -> V_188 && F_146 ( V_29 ) ) {
F_123 () ;
V_15 -> V_188 ( V_4 ) ;
F_125 () ;
} else {
F_2 ( V_4 ) ;
}
F_31 ( V_29 ) ;
} else if ( ! V_186 || V_187 < V_186 )
V_186 = V_187 ;
}
F_28 ( & V_15 -> V_51 ) ;
if ( V_186 )
F_24 ( & V_15 -> V_51 , V_38 + V_186 ) ;
F_147 ( & V_15 -> V_52 . V_17 ) ;
}
void F_148 ( struct V_14 * V_15 , struct V_114 * V_124 ,
struct V_3 * V_4 )
{
unsigned long V_53 = V_38 ;
unsigned long V_186 = V_53 + ( F_8 () %
F_75 ( V_124 , V_189 ) ) ;
if ( V_15 -> V_52 . V_190 > F_75 ( V_124 , V_191 ) ) {
F_2 ( V_4 ) ;
return;
}
F_144 ( V_4 ) -> V_186 = V_186 ;
F_144 ( V_4 ) -> V_163 |= V_192 ;
F_142 ( & V_15 -> V_52 . V_17 ) ;
if ( F_28 ( & V_15 -> V_51 ) ) {
if ( F_97 ( V_15 -> V_51 . V_193 , V_186 ) )
V_186 = V_15 -> V_51 . V_193 ;
}
F_149 ( V_4 ) ;
F_74 ( V_4 -> V_29 ) ;
F_113 ( & V_15 -> V_52 , V_4 ) ;
F_24 ( & V_15 -> V_51 , V_186 ) ;
F_147 ( & V_15 -> V_52 . V_17 ) ;
}
static inline struct V_114 * F_150 ( struct V_14 * V_15 ,
struct V_89 * V_89 , int V_194 )
{
struct V_114 * V_124 ;
F_96 (p, &tbl->parms_list, list) {
if ( ( V_124 -> V_29 && V_124 -> V_29 -> V_194 == V_194 && F_70 ( F_151 ( V_124 ) , V_89 ) ) ||
( ! V_124 -> V_29 && ! V_194 && F_70 ( V_89 , & V_195 ) ) )
return V_124 ;
}
return NULL ;
}
struct V_114 * F_152 ( struct V_44 * V_29 ,
struct V_14 * V_15 )
{
struct V_114 * V_124 ;
struct V_89 * V_89 = F_71 ( V_29 ) ;
const struct V_196 * V_117 = V_29 -> V_97 ;
V_124 = F_153 ( & V_15 -> V_6 , sizeof( * V_124 ) , V_109 ) ;
if ( V_124 ) {
V_124 -> V_15 = V_15 ;
F_49 ( & V_124 -> V_18 , 1 ) ;
V_124 -> V_125 =
F_7 ( F_75 ( V_124 , V_101 ) ) ;
F_74 ( V_29 ) ;
V_124 -> V_29 = V_29 ;
F_85 ( & V_124 -> V_89 , V_89 ) ;
V_124 -> V_197 = NULL ;
if ( V_117 -> V_198 && V_117 -> V_198 ( V_29 , V_124 ) ) {
F_31 ( V_29 ) ;
F_57 ( V_124 ) ;
return NULL ;
}
F_19 ( & V_15 -> V_17 ) ;
F_154 ( & V_124 -> V_43 , & V_15 -> V_6 . V_43 ) ;
F_20 ( & V_15 -> V_17 ) ;
F_155 ( V_124 ) ;
}
return V_124 ;
}
static void F_156 ( struct V_80 * V_81 )
{
struct V_114 * V_6 =
F_59 ( V_81 , struct V_114 , V_80 ) ;
F_87 ( V_6 ) ;
}
void F_157 ( struct V_14 * V_15 , struct V_114 * V_6 )
{
if ( ! V_6 || V_6 == & V_15 -> V_6 )
return;
F_19 ( & V_15 -> V_17 ) ;
F_158 ( & V_6 -> V_43 ) ;
V_6 -> V_21 = 1 ;
F_20 ( & V_15 -> V_17 ) ;
if ( V_6 -> V_29 )
F_31 ( V_6 -> V_29 ) ;
F_62 ( & V_6 -> V_80 , F_156 ) ;
}
static void F_89 ( struct V_114 * V_6 )
{
F_57 ( V_6 ) ;
}
void F_159 ( int V_199 , struct V_14 * V_15 )
{
unsigned long V_53 = V_38 ;
unsigned long V_200 ;
F_160 ( & V_15 -> V_201 ) ;
F_154 ( & V_15 -> V_6 . V_43 , & V_15 -> V_201 ) ;
F_85 ( & V_15 -> V_6 . V_89 , & V_195 ) ;
F_49 ( & V_15 -> V_6 . V_18 , 1 ) ;
V_15 -> V_6 . V_125 =
F_7 ( F_75 ( & V_15 -> V_6 , V_101 ) ) ;
V_15 -> V_202 = F_161 ( struct V_203 ) ;
if ( ! V_15 -> V_202 )
F_162 ( L_15 ) ;
#ifdef F_163
if ( ! F_164 ( V_15 -> V_58 , 0 , V_195 . V_204 ,
& V_205 , V_15 ) )
F_162 ( L_16 ) ;
#endif
F_165 ( V_15 -> V_24 , F_53 ( 3 ) ) ;
V_200 = ( V_104 + 1 ) * sizeof( struct V_105 * ) ;
V_15 -> V_107 = F_43 ( V_200 , V_109 ) ;
if ( ! V_15 -> V_24 || ! V_15 -> V_107 )
F_162 ( L_17 ) ;
if ( ! V_15 -> V_61 )
V_15 -> V_61 = F_166 ( F_167 ( struct V_1 , V_26 ) +
V_15 -> V_90 , V_206 ) ;
else
F_168 ( V_15 -> V_61 % V_206 ) ;
F_45 ( & V_15 -> V_17 ) ;
F_169 ( & V_15 -> V_121 , F_95 ) ;
F_99 ( V_130 , & V_15 -> V_121 ,
V_15 -> V_6 . V_125 ) ;
F_48 ( & V_15 -> V_51 , F_141 , ( unsigned long ) V_15 ) ;
F_170 ( & V_15 -> V_52 ,
& V_207 ) ;
V_15 -> V_37 = V_53 ;
V_15 -> V_123 = V_53 + V_15 -> V_6 . V_125 * 20 ;
V_208 [ V_199 ] = V_15 ;
}
int F_171 ( int V_199 , struct V_14 * V_15 )
{
V_208 [ V_199 ] = NULL ;
F_172 ( & V_15 -> V_121 ) ;
F_38 ( & V_15 -> V_51 ) ;
F_29 ( & V_15 -> V_52 ) ;
F_36 ( V_15 , NULL ) ;
if ( F_76 ( & V_15 -> V_54 ) )
F_173 ( L_18 ) ;
F_62 ( & F_12 ( V_15 -> V_24 , 1 ) -> V_82 ,
F_58 ) ;
V_15 -> V_24 = NULL ;
F_57 ( V_15 -> V_107 ) ;
V_15 -> V_107 = NULL ;
F_174 ( V_15 -> V_58 , V_195 . V_204 ) ;
F_175 ( V_15 -> V_202 ) ;
V_15 -> V_202 = NULL ;
return 0 ;
}
static struct V_14 * F_176 ( int V_209 )
{
struct V_14 * V_15 = NULL ;
switch ( V_209 ) {
case V_210 :
V_15 = V_208 [ V_211 ] ;
break;
case V_212 :
V_15 = V_208 [ V_213 ] ;
break;
case V_214 :
V_15 = V_208 [ V_215 ] ;
break;
}
return V_15 ;
}
static int F_177 ( struct V_3 * V_4 , struct V_216 * V_217 ,
struct V_218 * V_219 )
{
struct V_89 * V_89 = F_178 ( V_4 -> V_220 ) ;
struct V_221 * V_222 ;
struct V_223 * V_224 ;
struct V_14 * V_15 ;
struct V_1 * V_2 ;
struct V_44 * V_29 = NULL ;
int V_166 = - V_102 ;
F_84 () ;
if ( F_179 ( V_217 ) < sizeof( * V_222 ) )
goto V_71;
V_224 = F_180 ( V_217 , sizeof( * V_222 ) , V_225 ) ;
if ( V_224 == NULL )
goto V_71;
V_222 = F_181 ( V_217 ) ;
if ( V_222 -> V_226 ) {
V_29 = F_182 ( V_89 , V_222 -> V_226 ) ;
if ( V_29 == NULL ) {
V_166 = - V_227 ;
goto V_71;
}
}
V_15 = F_176 ( V_222 -> V_228 ) ;
if ( V_15 == NULL )
return - V_229 ;
if ( F_183 ( V_224 ) < V_15 -> V_90 )
goto V_71;
if ( V_222 -> V_230 & V_231 ) {
V_166 = F_86 ( V_15 , V_89 , F_184 ( V_224 ) , V_29 ) ;
goto V_71;
}
if ( V_29 == NULL )
goto V_71;
V_2 = F_63 ( V_15 , F_184 ( V_224 ) , V_29 ) ;
if ( V_2 == NULL ) {
V_166 = - V_112 ;
goto V_71;
}
V_166 = F_119 ( V_2 , NULL , V_128 ,
V_172 |
V_169 ,
F_185 ( V_4 ) . V_232 ) ;
F_19 ( & V_15 -> V_17 ) ;
F_6 ( V_2 ) ;
F_16 ( V_2 , V_15 ) ;
F_20 ( & V_15 -> V_17 ) ;
V_71:
return V_166 ;
}
static int F_186 ( struct V_3 * V_4 , struct V_216 * V_217 ,
struct V_218 * V_219 )
{
int V_163 = V_169 | V_172 ;
struct V_89 * V_89 = F_178 ( V_4 -> V_220 ) ;
struct V_221 * V_222 ;
struct V_223 * V_233 [ V_234 + 1 ] ;
struct V_14 * V_15 ;
struct V_44 * V_29 = NULL ;
struct V_1 * V_2 ;
void * V_175 , * V_161 ;
int V_166 ;
F_84 () ;
V_166 = F_187 ( V_217 , sizeof( * V_222 ) , V_233 , V_234 , NULL , V_219 ) ;
if ( V_166 < 0 )
goto V_71;
V_166 = - V_102 ;
if ( V_233 [ V_225 ] == NULL )
goto V_71;
V_222 = F_181 ( V_217 ) ;
if ( V_222 -> V_226 ) {
V_29 = F_182 ( V_89 , V_222 -> V_226 ) ;
if ( V_29 == NULL ) {
V_166 = - V_227 ;
goto V_71;
}
if ( V_233 [ V_235 ] && F_183 ( V_233 [ V_235 ] ) < V_29 -> V_170 )
goto V_71;
}
V_15 = F_176 ( V_222 -> V_228 ) ;
if ( V_15 == NULL )
return - V_229 ;
if ( F_183 ( V_233 [ V_225 ] ) < V_15 -> V_90 )
goto V_71;
V_175 = F_184 ( V_233 [ V_225 ] ) ;
V_161 = V_233 [ V_235 ] ? F_184 ( V_233 [ V_235 ] ) : NULL ;
if ( V_222 -> V_230 & V_231 ) {
struct V_105 * V_236 ;
V_166 = - V_94 ;
V_236 = F_81 ( V_15 , V_89 , V_175 , V_29 , 1 ) ;
if ( V_236 ) {
V_236 -> V_163 = V_222 -> V_230 ;
V_166 = 0 ;
}
goto V_71;
}
if ( V_29 == NULL )
goto V_71;
V_2 = F_63 ( V_15 , V_175 , V_29 ) ;
if ( V_2 == NULL ) {
if ( ! ( V_217 -> V_237 & V_238 ) ) {
V_166 = - V_112 ;
goto V_71;
}
V_2 = F_188 ( V_15 , V_175 , V_29 ) ;
if ( F_189 ( V_2 ) ) {
V_166 = F_190 ( V_2 ) ;
goto V_71;
}
} else {
if ( V_217 -> V_237 & V_239 ) {
V_166 = - V_240 ;
F_6 ( V_2 ) ;
goto V_71;
}
if ( ! ( V_217 -> V_237 & V_241 ) )
V_163 &= ~ V_172 ;
}
if ( V_222 -> V_230 & V_242 ) {
F_131 ( V_2 , NULL ) ;
V_166 = 0 ;
} else
V_166 = F_119 ( V_2 , V_161 , V_222 -> V_243 , V_163 ,
F_185 ( V_4 ) . V_232 ) ;
F_6 ( V_2 ) ;
V_71:
return V_166 ;
}
static int F_191 ( struct V_3 * V_4 , struct V_114 * V_6 )
{
struct V_223 * V_244 ;
V_244 = F_192 ( V_4 , V_245 ) ;
if ( V_244 == NULL )
return - V_94 ;
if ( ( V_6 -> V_29 &&
F_193 ( V_4 , V_246 , V_6 -> V_29 -> V_194 ) ) ||
F_193 ( V_4 , V_247 , F_11 ( & V_6 -> V_18 ) ) ||
F_193 ( V_4 , V_248 ,
F_75 ( V_6 , V_153 ) ) ||
F_193 ( V_4 , V_249 ,
F_75 ( V_6 , V_153 ) / F_194 ( V_250 ) ) ||
F_193 ( V_4 , V_251 , F_75 ( V_6 , V_191 ) ) ||
F_193 ( V_4 , V_252 , F_75 ( V_6 , V_132 ) ) ||
F_193 ( V_4 , V_253 ,
F_75 ( V_6 , V_131 ) ) ||
F_193 ( V_4 , V_254 ,
F_75 ( V_6 , V_135 ) ) ||
F_193 ( V_4 , V_255 ,
F_75 ( V_6 , V_134 ) ) ||
F_195 ( V_4 , V_256 , V_6 -> V_125 ,
V_257 ) ||
F_195 ( V_4 , V_258 ,
F_75 ( V_6 , V_101 ) , V_257 ) ||
F_195 ( V_4 , V_259 ,
F_75 ( V_6 , V_129 ) , V_257 ) ||
F_195 ( V_4 , V_260 ,
F_75 ( V_6 , V_143 ) , V_257 ) ||
F_195 ( V_4 , V_261 ,
F_75 ( V_6 , V_146 ) , V_257 ) ||
F_195 ( V_4 , V_262 ,
F_75 ( V_6 , V_263 ) , V_257 ) ||
F_195 ( V_4 , V_264 ,
F_75 ( V_6 , V_189 ) , V_257 ) ||
F_195 ( V_4 , V_265 ,
F_75 ( V_6 , V_266 ) , V_257 ) )
goto V_267;
return F_196 ( V_4 , V_244 ) ;
V_267:
F_197 ( V_4 , V_244 ) ;
return - V_268 ;
}
static int F_198 ( struct V_3 * V_4 , struct V_14 * V_15 ,
T_3 V_269 , T_3 V_183 , int type , int V_163 )
{
struct V_216 * V_217 ;
struct V_270 * V_270 ;
V_217 = F_199 ( V_4 , V_269 , V_183 , type , sizeof( * V_270 ) , V_163 ) ;
if ( V_217 == NULL )
return - V_268 ;
V_270 = F_181 ( V_217 ) ;
F_82 ( & V_15 -> V_17 ) ;
V_270 -> V_271 = V_15 -> V_209 ;
V_270 -> V_272 = 0 ;
V_270 -> V_273 = 0 ;
if ( F_200 ( V_4 , V_274 , V_15 -> V_58 ) ||
F_195 ( V_4 , V_275 , V_15 -> V_276 , V_277 ) ||
F_193 ( V_4 , V_278 , V_15 -> V_126 ) ||
F_193 ( V_4 , V_279 , V_15 -> V_56 ) ||
F_193 ( V_4 , V_280 , V_15 -> V_55 ) )
goto V_267;
{
unsigned long V_53 = V_38 ;
unsigned int V_281 = V_53 - V_15 -> V_37 ;
unsigned int V_282 = V_53 - V_15 -> V_123 ;
struct V_23 * V_24 ;
struct V_283 V_284 = {
. V_285 = V_15 -> V_90 ,
. V_286 = V_15 -> V_61 ,
. V_287 = F_76 ( & V_15 -> V_54 ) ,
. V_288 = F_201 ( V_281 ) ,
. V_289 = F_201 ( V_282 ) ,
. V_290 = V_15 -> V_52 . V_190 ,
} ;
F_64 () ;
V_24 = F_69 ( V_15 -> V_24 ) ;
V_284 . V_291 = V_24 -> V_30 [ 0 ] ;
V_284 . V_292 = ( ( 1 << V_24 -> V_31 ) - 1 ) ;
F_67 () ;
if ( F_202 ( V_4 , V_293 , sizeof( V_284 ) , & V_284 ) )
goto V_267;
}
{
int V_294 ;
struct V_295 V_296 ;
memset ( & V_296 , 0 , sizeof( V_296 ) ) ;
F_203 (cpu) {
struct V_203 * V_297 ;
V_297 = F_204 ( V_15 -> V_202 , V_294 ) ;
V_296 . V_298 += V_297 -> V_70 ;
V_296 . V_299 += V_297 -> V_115 ;
V_296 . V_300 += V_297 -> V_86 ;
V_296 . V_301 += V_297 -> V_136 ;
V_296 . V_302 += V_297 -> V_87 ;
V_296 . V_303 += V_297 -> V_88 ;
V_296 . V_304 += V_297 -> V_305 ;
V_296 . V_306 += V_297 -> V_307 ;
V_296 . V_308 += V_297 -> V_122 ;
V_296 . V_309 += V_297 -> V_35 ;
V_296 . V_310 += V_297 -> V_59 ;
}
if ( F_205 ( V_4 , V_311 , sizeof( V_296 ) , & V_296 ,
V_277 ) )
goto V_267;
}
F_206 ( V_15 -> V_6 . V_29 ) ;
if ( F_191 ( V_4 , & V_15 -> V_6 ) < 0 )
goto V_267;
F_83 ( & V_15 -> V_17 ) ;
F_207 ( V_4 , V_217 ) ;
return 0 ;
V_267:
F_83 ( & V_15 -> V_17 ) ;
F_208 ( V_4 , V_217 ) ;
return - V_268 ;
}
static int F_209 ( struct V_3 * V_4 ,
struct V_14 * V_15 ,
struct V_114 * V_6 ,
T_3 V_269 , T_3 V_183 , int type ,
unsigned int V_163 )
{
struct V_270 * V_270 ;
struct V_216 * V_217 ;
V_217 = F_199 ( V_4 , V_269 , V_183 , type , sizeof( * V_270 ) , V_163 ) ;
if ( V_217 == NULL )
return - V_268 ;
V_270 = F_181 ( V_217 ) ;
F_82 ( & V_15 -> V_17 ) ;
V_270 -> V_271 = V_15 -> V_209 ;
V_270 -> V_272 = 0 ;
V_270 -> V_273 = 0 ;
if ( F_200 ( V_4 , V_274 , V_15 -> V_58 ) < 0 ||
F_191 ( V_4 , V_6 ) < 0 )
goto V_312;
F_83 ( & V_15 -> V_17 ) ;
F_207 ( V_4 , V_217 ) ;
return 0 ;
V_312:
F_83 ( & V_15 -> V_17 ) ;
F_208 ( V_4 , V_217 ) ;
return - V_268 ;
}
static int F_210 ( struct V_3 * V_4 , struct V_216 * V_217 ,
struct V_218 * V_219 )
{
struct V_89 * V_89 = F_178 ( V_4 -> V_220 ) ;
struct V_14 * V_15 ;
struct V_270 * V_270 ;
struct V_223 * V_233 [ V_313 + 1 ] ;
bool V_314 = false ;
int V_166 , V_315 ;
V_166 = F_187 ( V_217 , sizeof( * V_270 ) , V_233 , V_313 ,
V_316 , V_219 ) ;
if ( V_166 < 0 )
goto V_312;
if ( V_233 [ V_274 ] == NULL ) {
V_166 = - V_102 ;
goto V_312;
}
V_270 = F_181 ( V_217 ) ;
for ( V_315 = 0 ; V_315 < V_317 ; V_315 ++ ) {
V_15 = V_208 [ V_315 ] ;
if ( ! V_15 )
continue;
if ( V_270 -> V_271 && V_15 -> V_209 != V_270 -> V_271 )
continue;
if ( F_211 ( V_233 [ V_274 ] , V_15 -> V_58 ) == 0 ) {
V_314 = true ;
break;
}
}
if ( ! V_314 )
return - V_112 ;
F_19 ( & V_15 -> V_17 ) ;
if ( V_233 [ V_245 ] ) {
struct V_223 * V_318 [ V_319 + 1 ] ;
struct V_114 * V_124 ;
int V_34 , V_194 = 0 ;
V_166 = F_212 ( V_318 , V_319 , V_233 [ V_245 ] ,
V_320 , V_219 ) ;
if ( V_166 < 0 )
goto V_321;
if ( V_318 [ V_246 ] )
V_194 = F_213 ( V_318 [ V_246 ] ) ;
V_124 = F_150 ( V_15 , V_89 , V_194 ) ;
if ( V_124 == NULL ) {
V_166 = - V_112 ;
goto V_321;
}
for ( V_34 = 1 ; V_34 <= V_319 ; V_34 ++ ) {
if ( V_318 [ V_34 ] == NULL )
continue;
switch ( V_34 ) {
case V_249 :
F_214 ( V_124 , V_153 ,
F_213 ( V_318 [ V_34 ] ) *
F_194 ( V_250 ) ) ;
break;
case V_248 :
F_214 ( V_124 , V_153 ,
F_213 ( V_318 [ V_34 ] ) ) ;
break;
case V_251 :
F_214 ( V_124 , V_191 ,
F_213 ( V_318 [ V_34 ] ) ) ;
break;
case V_252 :
F_214 ( V_124 , V_132 ,
F_213 ( V_318 [ V_34 ] ) ) ;
break;
case V_253 :
F_214 ( V_124 , V_131 ,
F_213 ( V_318 [ V_34 ] ) ) ;
break;
case V_254 :
F_214 ( V_124 , V_135 ,
F_213 ( V_318 [ V_34 ] ) ) ;
break;
case V_255 :
F_214 ( V_124 , V_134 ,
F_213 ( V_318 [ V_34 ] ) ) ;
break;
case V_258 :
F_214 ( V_124 , V_101 ,
F_215 ( V_318 [ V_34 ] ) ) ;
V_124 -> V_125 =
F_7 ( F_75 ( V_124 , V_101 ) ) ;
break;
case V_259 :
F_214 ( V_124 , V_129 ,
F_215 ( V_318 [ V_34 ] ) ) ;
break;
case V_260 :
F_214 ( V_124 , V_143 ,
F_215 ( V_318 [ V_34 ] ) ) ;
F_5 ( V_322 , V_124 ) ;
break;
case V_261 :
F_214 ( V_124 , V_146 ,
F_215 ( V_318 [ V_34 ] ) ) ;
break;
case V_262 :
F_214 ( V_124 , V_263 ,
F_215 ( V_318 [ V_34 ] ) ) ;
break;
case V_264 :
F_214 ( V_124 , V_189 ,
F_215 ( V_318 [ V_34 ] ) ) ;
break;
case V_265 :
F_214 ( V_124 , V_266 ,
F_215 ( V_318 [ V_34 ] ) ) ;
break;
}
}
}
V_166 = - V_112 ;
if ( ( V_233 [ V_278 ] || V_233 [ V_279 ] ||
V_233 [ V_280 ] || V_233 [ V_275 ] ) &&
! F_70 ( V_89 , & V_195 ) )
goto V_321;
if ( V_233 [ V_278 ] )
V_15 -> V_126 = F_213 ( V_233 [ V_278 ] ) ;
if ( V_233 [ V_279 ] )
V_15 -> V_56 = F_213 ( V_233 [ V_279 ] ) ;
if ( V_233 [ V_280 ] )
V_15 -> V_55 = F_213 ( V_233 [ V_280 ] ) ;
if ( V_233 [ V_275 ] )
V_15 -> V_276 = F_215 ( V_233 [ V_275 ] ) ;
V_166 = 0 ;
V_321:
F_20 ( & V_15 -> V_17 ) ;
V_312:
return V_166 ;
}
static int F_216 ( struct V_3 * V_4 , struct V_323 * V_324 )
{
struct V_89 * V_89 = F_178 ( V_4 -> V_220 ) ;
int V_209 , V_315 , V_325 = 0 ;
int V_326 = V_324 -> args [ 0 ] ;
int V_327 = V_324 -> args [ 1 ] ;
struct V_14 * V_15 ;
V_209 = ( (struct V_328 * ) F_181 ( V_324 -> V_217 ) ) -> V_329 ;
for ( V_315 = 0 ; V_315 < V_317 ; V_315 ++ ) {
struct V_114 * V_124 ;
V_15 = V_208 [ V_315 ] ;
if ( ! V_15 )
continue;
if ( V_315 < V_326 || ( V_209 && V_15 -> V_209 != V_209 ) )
continue;
if ( F_198 ( V_4 , V_15 , F_185 ( V_324 -> V_4 ) . V_232 ,
V_324 -> V_217 -> V_330 , V_331 ,
V_332 ) < 0 )
break;
V_325 = 0 ;
V_124 = F_217 ( & V_15 -> V_6 , V_43 ) ;
F_218 (p, &tbl->parms_list, list) {
if ( ! F_70 ( F_151 ( V_124 ) , V_89 ) )
continue;
if ( V_325 < V_327 )
goto V_20;
if ( F_209 ( V_4 , V_15 , V_124 ,
F_185 ( V_324 -> V_4 ) . V_232 ,
V_324 -> V_217 -> V_330 ,
V_331 ,
V_332 ) < 0 )
goto V_71;
V_20:
V_325 ++ ;
}
V_327 = 0 ;
}
V_71:
V_324 -> args [ 0 ] = V_315 ;
V_324 -> args [ 1 ] = V_325 ;
return V_4 -> V_184 ;
}
static int F_219 ( struct V_3 * V_4 , struct V_1 * V_2 ,
T_3 V_269 , T_3 V_183 , int type , unsigned int V_163 )
{
unsigned long V_53 = V_38 ;
struct V_333 V_334 ;
struct V_216 * V_217 ;
struct V_221 * V_222 ;
V_217 = F_199 ( V_4 , V_269 , V_183 , type , sizeof( * V_222 ) , V_163 ) ;
if ( V_217 == NULL )
return - V_268 ;
V_222 = F_181 ( V_217 ) ;
V_222 -> V_228 = V_2 -> V_117 -> V_209 ;
V_222 -> V_335 = 0 ;
V_222 -> V_336 = 0 ;
V_222 -> V_230 = V_2 -> V_163 ;
V_222 -> V_337 = V_2 -> type ;
V_222 -> V_226 = V_2 -> V_29 -> V_194 ;
if ( F_202 ( V_4 , V_225 , V_2 -> V_15 -> V_90 , V_2 -> V_26 ) )
goto V_267;
F_82 ( & V_2 -> V_17 ) ;
V_222 -> V_243 = V_2 -> V_19 ;
if ( V_2 -> V_19 & V_48 ) {
char V_338 [ V_339 ] ;
F_220 ( V_338 , V_2 , V_2 -> V_29 ) ;
if ( F_202 ( V_4 , V_235 , V_2 -> V_29 -> V_170 , V_338 ) < 0 ) {
F_83 ( & V_2 -> V_17 ) ;
goto V_267;
}
}
V_334 . V_340 = F_221 ( V_53 - V_2 -> V_66 ) ;
V_334 . V_341 = F_221 ( V_53 - V_2 -> V_100 ) ;
V_334 . V_342 = F_221 ( V_53 - V_2 -> V_65 ) ;
V_334 . V_343 = F_11 ( & V_2 -> V_18 ) - 1 ;
F_83 ( & V_2 -> V_17 ) ;
if ( F_193 ( V_4 , V_344 , F_76 ( & V_2 -> V_139 ) ) ||
F_202 ( V_4 , V_345 , sizeof( V_334 ) , & V_334 ) )
goto V_267;
F_207 ( V_4 , V_217 ) ;
return 0 ;
V_267:
F_208 ( V_4 , V_217 ) ;
return - V_268 ;
}
static int F_222 ( struct V_3 * V_4 , struct V_105 * V_236 ,
T_3 V_269 , T_3 V_183 , int type , unsigned int V_163 ,
struct V_14 * V_15 )
{
struct V_216 * V_217 ;
struct V_221 * V_222 ;
V_217 = F_199 ( V_4 , V_269 , V_183 , type , sizeof( * V_222 ) , V_163 ) ;
if ( V_217 == NULL )
return - V_268 ;
V_222 = F_181 ( V_217 ) ;
V_222 -> V_228 = V_15 -> V_209 ;
V_222 -> V_335 = 0 ;
V_222 -> V_336 = 0 ;
V_222 -> V_230 = V_236 -> V_163 | V_231 ;
V_222 -> V_337 = V_346 ;
V_222 -> V_226 = V_236 -> V_29 ? V_236 -> V_29 -> V_194 : 0 ;
V_222 -> V_243 = V_50 ;
if ( F_202 ( V_4 , V_225 , V_15 -> V_90 , V_236 -> V_106 ) )
goto V_267;
F_207 ( V_4 , V_217 ) ;
return 0 ;
V_267:
F_208 ( V_4 , V_217 ) ;
return - V_268 ;
}
static void F_109 ( struct V_1 * V_2 , T_3 V_164 )
{
F_5 ( V_9 , V_2 ) ;
F_4 ( V_2 , V_347 , 0 , V_164 ) ;
}
static bool F_223 ( struct V_44 * V_29 , int V_348 )
{
struct V_44 * V_349 ;
if ( ! V_348 )
return false ;
V_349 = F_224 ( V_29 ) ;
if ( ! V_349 || V_349 -> V_194 != V_348 )
return true ;
return false ;
}
static bool F_225 ( struct V_44 * V_29 , int V_350 )
{
if ( V_350 && V_29 -> V_194 != V_350 )
return true ;
return false ;
}
static int F_226 ( struct V_14 * V_15 , struct V_3 * V_4 ,
struct V_323 * V_324 )
{
struct V_89 * V_89 = F_178 ( V_4 -> V_220 ) ;
const struct V_216 * V_217 = V_324 -> V_217 ;
struct V_223 * V_233 [ V_234 + 1 ] ;
struct V_1 * V_11 ;
int V_93 , V_113 , V_351 = V_324 -> args [ 1 ] ;
int V_352 , V_353 = V_352 = V_324 -> args [ 2 ] ;
struct V_23 * V_24 ;
int V_354 = 0 , V_350 = 0 ;
unsigned int V_163 = V_332 ;
int V_166 ;
V_166 = F_187 ( V_217 , sizeof( struct V_221 ) , V_233 , V_234 , NULL , NULL ) ;
if ( ! V_166 ) {
if ( V_233 [ V_355 ] )
V_350 = F_213 ( V_233 [ V_355 ] ) ;
if ( V_233 [ V_356 ] )
V_354 = F_213 ( V_233 [ V_356 ] ) ;
if ( V_350 || V_354 )
V_163 |= V_357 ;
}
F_64 () ;
V_24 = F_69 ( V_15 -> V_24 ) ;
for ( V_113 = V_351 ; V_113 < ( 1 << V_24 -> V_31 ) ; V_113 ++ ) {
if ( V_113 > V_351 )
V_353 = 0 ;
for ( V_11 = F_69 ( V_24 -> V_32 [ V_113 ] ) , V_352 = 0 ;
V_11 != NULL ;
V_11 = F_69 ( V_11 -> V_20 ) ) {
if ( V_352 < V_353 || ! F_70 ( F_71 ( V_11 -> V_29 ) , V_89 ) )
goto V_20;
if ( F_225 ( V_11 -> V_29 , V_350 ) ||
F_223 ( V_11 -> V_29 , V_354 ) )
goto V_20;
if ( F_219 ( V_4 , V_11 , F_185 ( V_324 -> V_4 ) . V_232 ,
V_324 -> V_217 -> V_330 ,
V_347 ,
V_163 ) < 0 ) {
V_93 = - 1 ;
goto V_71;
}
V_20:
V_352 ++ ;
}
}
V_93 = V_4 -> V_184 ;
V_71:
F_67 () ;
V_324 -> args [ 1 ] = V_113 ;
V_324 -> args [ 2 ] = V_352 ;
return V_93 ;
}
static int F_227 ( struct V_14 * V_15 , struct V_3 * V_4 ,
struct V_323 * V_324 )
{
struct V_105 * V_11 ;
struct V_89 * V_89 = F_178 ( V_4 -> V_220 ) ;
int V_93 , V_113 , V_351 = V_324 -> args [ 3 ] ;
int V_352 , V_353 = V_352 = V_324 -> args [ 4 ] ;
F_82 ( & V_15 -> V_17 ) ;
for ( V_113 = V_351 ; V_113 <= V_104 ; V_113 ++ ) {
if ( V_113 > V_351 )
V_353 = 0 ;
for ( V_11 = V_15 -> V_107 [ V_113 ] , V_352 = 0 ; V_11 ; V_11 = V_11 -> V_20 ) {
if ( V_352 < V_353 || F_79 ( V_11 ) != V_89 )
goto V_20;
if ( F_222 ( V_4 , V_11 , F_185 ( V_324 -> V_4 ) . V_232 ,
V_324 -> V_217 -> V_330 ,
V_347 ,
V_332 , V_15 ) < 0 ) {
F_83 ( & V_15 -> V_17 ) ;
V_93 = - 1 ;
goto V_71;
}
V_20:
V_352 ++ ;
}
}
F_83 ( & V_15 -> V_17 ) ;
V_93 = V_4 -> V_184 ;
V_71:
V_324 -> args [ 3 ] = V_113 ;
V_324 -> args [ 4 ] = V_352 ;
return V_93 ;
}
static int F_228 ( struct V_3 * V_4 , struct V_323 * V_324 )
{
struct V_14 * V_15 ;
int V_358 , V_209 , V_359 ;
int V_360 = 0 ;
int V_166 ;
V_209 = ( (struct V_328 * ) F_181 ( V_324 -> V_217 ) ) -> V_329 ;
if ( F_179 ( V_324 -> V_217 ) >= sizeof( struct V_221 ) &&
( (struct V_221 * ) F_181 ( V_324 -> V_217 ) ) -> V_230 == V_231 )
V_360 = 1 ;
V_359 = V_324 -> args [ 0 ] ;
for ( V_358 = 0 ; V_358 < V_317 ; V_358 ++ ) {
V_15 = V_208 [ V_358 ] ;
if ( ! V_15 )
continue;
if ( V_358 < V_359 || ( V_209 && V_15 -> V_209 != V_209 ) )
continue;
if ( V_358 > V_359 )
memset ( & V_324 -> args [ 1 ] , 0 , sizeof( V_324 -> args ) -
sizeof( V_324 -> args [ 0 ] ) ) ;
if ( V_360 )
V_166 = F_227 ( V_15 , V_4 , V_324 ) ;
else
V_166 = F_226 ( V_15 , V_4 , V_324 ) ;
if ( V_166 < 0 )
break;
}
V_324 -> args [ 0 ] = V_358 ;
return V_4 -> V_184 ;
}
void F_229 ( struct V_14 * V_15 , void (* V_324)( struct V_1 * , void * ) , void * V_361 )
{
int V_362 ;
struct V_23 * V_24 ;
F_64 () ;
V_24 = F_69 ( V_15 -> V_24 ) ;
F_230 ( & V_15 -> V_17 ) ;
for ( V_362 = 0 ; V_362 < ( 1 << V_24 -> V_31 ) ; V_362 ++ ) {
struct V_1 * V_11 ;
for ( V_11 = F_69 ( V_24 -> V_32 [ V_362 ] ) ;
V_11 != NULL ;
V_11 = F_69 ( V_11 -> V_20 ) )
V_324 ( V_11 , V_361 ) ;
}
F_231 ( & V_15 -> V_17 ) ;
F_67 () ;
}
void F_232 ( struct V_14 * V_15 ,
int (* V_324)( struct V_1 * ) )
{
int V_362 ;
struct V_23 * V_24 ;
V_24 = F_12 ( V_15 -> V_24 ,
F_13 ( & V_15 -> V_17 ) ) ;
for ( V_362 = 0 ; V_362 < ( 1 << V_24 -> V_31 ) ; V_362 ++ ) {
struct V_1 * V_11 ;
struct V_1 T_2 * * V_13 ;
V_13 = & V_24 -> V_32 [ V_362 ] ;
while ( ( V_11 = F_12 ( * V_13 ,
F_13 ( & V_15 -> V_17 ) ) ) != NULL ) {
int V_363 ;
F_10 ( & V_11 -> V_17 ) ;
V_363 = V_324 ( V_11 ) ;
if ( V_363 ) {
F_14 ( * V_13 ,
F_12 ( V_11 -> V_20 ,
F_13 ( & V_15 -> V_17 ) ) ) ;
V_11 -> V_21 = 1 ;
} else
V_13 = & V_11 -> V_20 ;
F_15 ( & V_11 -> V_17 ) ;
if ( V_363 )
F_3 ( V_11 ) ;
}
}
}
int F_233 ( int V_199 , struct V_44 * V_29 ,
const void * V_364 , struct V_3 * V_4 )
{
int V_166 = - V_229 ;
if ( F_234 ( V_199 < V_317 ) ) {
struct V_14 * V_15 ;
struct V_1 * V_2 ;
V_15 = V_208 [ V_199 ] ;
if ( ! V_15 )
goto V_71;
F_64 () ;
V_2 = F_65 ( V_15 , V_364 , V_29 ) ;
if ( ! V_2 )
V_2 = F_72 ( V_15 , V_364 , V_29 , false ) ;
V_166 = F_190 ( V_2 ) ;
if ( F_189 ( V_2 ) ) {
F_67 () ;
goto V_185;
}
V_166 = V_2 -> V_47 ( V_2 , V_4 ) ;
F_67 () ;
}
else if ( V_199 == V_365 ) {
V_166 = F_135 ( V_4 , V_29 , F_136 ( V_4 -> V_181 ) ,
V_364 , NULL , V_4 -> V_184 ) ;
if ( V_166 < 0 )
goto V_185;
V_166 = F_138 ( V_4 ) ;
}
V_71:
return V_166 ;
V_185:
F_2 ( V_4 ) ;
goto V_71;
}
static struct V_1 * F_235 ( struct V_366 * V_183 )
{
struct V_367 * V_12 = V_183 -> V_368 ;
struct V_89 * V_89 = F_236 ( V_183 ) ;
struct V_23 * V_24 = V_12 -> V_24 ;
struct V_1 * V_11 = NULL ;
int V_369 = V_12 -> V_369 ;
V_12 -> V_163 &= ~ V_370 ;
for ( V_369 = 0 ; V_369 < ( 1 << V_24 -> V_31 ) ; V_369 ++ ) {
V_11 = F_69 ( V_24 -> V_32 [ V_369 ] ) ;
while ( V_11 ) {
if ( ! F_70 ( F_71 ( V_11 -> V_29 ) , V_89 ) )
goto V_20;
if ( V_12 -> V_371 ) {
T_8 V_372 = 0 ;
void * V_373 ;
V_373 = V_12 -> V_371 ( V_12 , V_11 , & V_372 ) ;
if ( ! V_373 )
goto V_20;
}
if ( ! ( V_12 -> V_163 & V_374 ) )
break;
if ( V_11 -> V_19 & ~ V_49 )
break;
V_20:
V_11 = F_69 ( V_11 -> V_20 ) ;
}
if ( V_11 )
break;
}
V_12 -> V_369 = V_369 ;
return V_11 ;
}
static struct V_1 * F_237 ( struct V_366 * V_183 ,
struct V_1 * V_11 ,
T_8 * V_375 )
{
struct V_367 * V_12 = V_183 -> V_368 ;
struct V_89 * V_89 = F_236 ( V_183 ) ;
struct V_23 * V_24 = V_12 -> V_24 ;
if ( V_12 -> V_371 ) {
void * V_373 = V_12 -> V_371 ( V_12 , V_11 , V_375 ) ;
if ( V_373 )
return V_11 ;
}
V_11 = F_69 ( V_11 -> V_20 ) ;
while ( 1 ) {
while ( V_11 ) {
if ( ! F_70 ( F_71 ( V_11 -> V_29 ) , V_89 ) )
goto V_20;
if ( V_12 -> V_371 ) {
void * V_373 = V_12 -> V_371 ( V_12 , V_11 , V_375 ) ;
if ( V_373 )
return V_11 ;
goto V_20;
}
if ( ! ( V_12 -> V_163 & V_374 ) )
break;
if ( V_11 -> V_19 & ~ V_49 )
break;
V_20:
V_11 = F_69 ( V_11 -> V_20 ) ;
}
if ( V_11 )
break;
if ( ++ V_12 -> V_369 >= ( 1 << V_24 -> V_31 ) )
break;
V_11 = F_69 ( V_24 -> V_32 [ V_12 -> V_369 ] ) ;
}
if ( V_11 && V_375 )
-- ( * V_375 ) ;
return V_11 ;
}
static struct V_1 * F_238 ( struct V_366 * V_183 , T_8 * V_375 )
{
struct V_1 * V_11 = F_235 ( V_183 ) ;
if ( V_11 ) {
-- ( * V_375 ) ;
while ( * V_375 ) {
V_11 = F_237 ( V_183 , V_11 , V_375 ) ;
if ( ! V_11 )
break;
}
}
return * V_375 ? NULL : V_11 ;
}
static struct V_105 * F_239 ( struct V_366 * V_183 )
{
struct V_367 * V_12 = V_183 -> V_368 ;
struct V_89 * V_89 = F_236 ( V_183 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
struct V_105 * V_236 = NULL ;
int V_369 = V_12 -> V_369 ;
V_12 -> V_163 |= V_370 ;
for ( V_369 = 0 ; V_369 <= V_104 ; V_369 ++ ) {
V_236 = V_15 -> V_107 [ V_369 ] ;
while ( V_236 && ! F_70 ( F_79 ( V_236 ) , V_89 ) )
V_236 = V_236 -> V_20 ;
if ( V_236 )
break;
}
V_12 -> V_369 = V_369 ;
return V_236 ;
}
static struct V_105 * F_240 ( struct V_366 * V_183 ,
struct V_105 * V_236 ,
T_8 * V_375 )
{
struct V_367 * V_12 = V_183 -> V_368 ;
struct V_89 * V_89 = F_236 ( V_183 ) ;
struct V_14 * V_15 = V_12 -> V_15 ;
do {
V_236 = V_236 -> V_20 ;
} while ( V_236 && ! F_70 ( F_79 ( V_236 ) , V_89 ) );
while ( ! V_236 ) {
if ( ++ V_12 -> V_369 > V_104 )
break;
V_236 = V_15 -> V_107 [ V_12 -> V_369 ] ;
while ( V_236 && ! F_70 ( F_79 ( V_236 ) , V_89 ) )
V_236 = V_236 -> V_20 ;
if ( V_236 )
break;
}
if ( V_236 && V_375 )
-- ( * V_375 ) ;
return V_236 ;
}
static struct V_105 * F_241 ( struct V_366 * V_183 , T_8 * V_375 )
{
struct V_105 * V_236 = F_239 ( V_183 ) ;
if ( V_236 ) {
-- ( * V_375 ) ;
while ( * V_375 ) {
V_236 = F_240 ( V_183 , V_236 , V_375 ) ;
if ( ! V_236 )
break;
}
}
return * V_375 ? NULL : V_236 ;
}
static void * F_242 ( struct V_366 * V_183 , T_8 * V_375 )
{
struct V_367 * V_12 = V_183 -> V_368 ;
void * V_93 ;
T_8 V_376 = * V_375 ;
V_93 = F_238 ( V_183 , & V_376 ) ;
if ( ! V_93 && ! ( V_12 -> V_163 & V_377 ) )
V_93 = F_241 ( V_183 , & V_376 ) ;
return V_93 ;
}
void * F_243 ( struct V_366 * V_183 , T_8 * V_375 , struct V_14 * V_15 , unsigned int V_378 )
__acquires( T_9 )
{
struct V_367 * V_12 = V_183 -> V_368 ;
V_12 -> V_15 = V_15 ;
V_12 -> V_369 = 0 ;
V_12 -> V_163 = ( V_378 & ~ V_370 ) ;
F_64 () ;
V_12 -> V_24 = F_69 ( V_15 -> V_24 ) ;
return * V_375 ? F_242 ( V_183 , V_375 ) : V_379 ;
}
void * F_244 ( struct V_366 * V_183 , void * V_373 , T_8 * V_375 )
{
struct V_367 * V_12 ;
void * V_93 ;
if ( V_373 == V_379 ) {
V_93 = F_235 ( V_183 ) ;
goto V_71;
}
V_12 = V_183 -> V_368 ;
if ( ! ( V_12 -> V_163 & V_370 ) ) {
V_93 = F_237 ( V_183 , V_373 , NULL ) ;
if ( V_93 )
goto V_71;
if ( ! ( V_12 -> V_163 & V_377 ) )
V_93 = F_239 ( V_183 ) ;
} else {
F_206 ( V_12 -> V_163 & V_377 ) ;
V_93 = F_240 ( V_183 , V_373 , NULL ) ;
}
V_71:
++ ( * V_375 ) ;
return V_93 ;
}
void F_245 ( struct V_366 * V_183 , void * V_373 )
__releases( T_9 )
{
F_67 () ;
}
static void * F_246 ( struct V_366 * V_183 , T_8 * V_375 )
{
struct V_14 * V_15 = V_183 -> V_368 ;
int V_294 ;
if ( * V_375 == 0 )
return V_379 ;
for ( V_294 = * V_375 - 1 ; V_294 < V_380 ; ++ V_294 ) {
if ( ! F_247 ( V_294 ) )
continue;
* V_375 = V_294 + 1 ;
return F_204 ( V_15 -> V_202 , V_294 ) ;
}
return NULL ;
}
static void * F_248 ( struct V_366 * V_183 , void * V_373 , T_8 * V_375 )
{
struct V_14 * V_15 = V_183 -> V_368 ;
int V_294 ;
for ( V_294 = * V_375 ; V_294 < V_380 ; ++ V_294 ) {
if ( ! F_247 ( V_294 ) )
continue;
* V_375 = V_294 + 1 ;
return F_204 ( V_15 -> V_202 , V_294 ) ;
}
return NULL ;
}
static void F_249 ( struct V_366 * V_183 , void * V_373 )
{
}
static int F_250 ( struct V_366 * V_183 , void * V_373 )
{
struct V_14 * V_15 = V_183 -> V_368 ;
struct V_203 * V_297 = V_373 ;
if ( V_373 == V_379 ) {
F_251 ( V_183 , L_19 ) ;
return 0 ;
}
F_251 ( V_183 , L_20
L_21 ,
F_76 ( & V_15 -> V_54 ) ,
V_297 -> V_70 ,
V_297 -> V_115 ,
V_297 -> V_86 ,
V_297 -> V_87 ,
V_297 -> V_88 ,
V_297 -> V_136 ,
V_297 -> V_305 ,
V_297 -> V_307 ,
V_297 -> V_122 ,
V_297 -> V_35 ,
V_297 -> V_155 ,
V_297 -> V_59
) ;
return 0 ;
}
static int F_252 ( struct V_381 * V_381 , struct V_382 * V_382 )
{
int V_75 = F_253 ( V_382 , & V_383 ) ;
if ( ! V_75 ) {
struct V_366 * V_384 = V_382 -> V_385 ;
V_384 -> V_368 = F_254 ( V_381 ) ;
}
return V_75 ;
}
static inline T_4 F_255 ( void )
{
return F_256 ( sizeof( struct V_221 ) )
+ F_257 ( V_339 )
+ F_257 ( V_339 )
+ F_257 ( sizeof( struct V_333 ) )
+ F_257 ( 4 ) ;
}
static void F_4 ( struct V_1 * V_11 , int type , int V_163 ,
T_3 V_269 )
{
struct V_89 * V_89 = F_71 ( V_11 -> V_29 ) ;
struct V_3 * V_4 ;
int V_166 = - V_94 ;
V_4 = F_258 ( F_255 () , V_63 ) ;
if ( V_4 == NULL )
goto V_312;
V_166 = F_219 ( V_4 , V_11 , V_269 , 0 , type , V_163 ) ;
if ( V_166 < 0 ) {
F_168 ( V_166 == - V_268 ) ;
F_2 ( V_4 ) ;
goto V_312;
}
F_259 ( V_4 , V_89 , 0 , V_386 , NULL , V_63 ) ;
return;
V_312:
if ( V_166 < 0 )
F_260 ( V_89 , V_386 , V_166 ) ;
}
void F_261 ( struct V_1 * V_11 )
{
F_4 ( V_11 , V_387 , V_388 , 0 ) ;
}
static int F_262 ( struct V_389 * V_390 , int V_391 ,
void T_10 * V_392 , T_4 * V_393 , T_8 * V_394 )
{
int V_74 , V_75 ;
struct V_389 V_395 = * V_390 ;
V_395 . V_396 = & V_397 ;
V_395 . V_398 = & V_399 ;
V_395 . V_400 = & V_74 ;
V_74 = * ( int * ) V_390 -> V_400 / F_194 ( V_250 ) ;
V_75 = F_263 ( & V_395 , V_391 , V_392 , V_393 , V_394 ) ;
if ( V_391 && ! V_75 )
* ( int * ) V_390 -> V_400 = V_74 * F_194 ( V_250 ) ;
return V_75 ;
}
static struct V_114 * F_264 ( struct V_44 * V_29 ,
int V_209 )
{
switch ( V_209 ) {
case V_210 :
return F_265 ( V_29 ) ;
case V_212 :
return F_266 ( V_29 ) ;
}
return NULL ;
}
static void F_267 ( struct V_89 * V_89 , struct V_114 * V_124 ,
int V_199 )
{
struct V_44 * V_29 ;
int V_209 = F_268 ( V_124 ) ;
F_123 () ;
F_269 (net, dev) {
struct V_114 * V_401 =
F_264 ( V_29 , V_209 ) ;
if ( V_401 && ! F_270 ( V_199 , V_401 -> V_402 ) )
V_401 -> V_400 [ V_199 ] = V_124 -> V_400 [ V_199 ] ;
}
F_125 () ;
}
static void F_271 ( struct V_389 * V_390 , int V_391 )
{
struct V_44 * V_29 = V_390 -> V_396 ;
struct V_114 * V_124 = V_390 -> V_398 ;
struct V_89 * V_89 = F_151 ( V_124 ) ;
int V_199 = ( int * ) V_390 -> V_400 - V_124 -> V_400 ;
if ( ! V_391 )
return;
F_272 ( V_199 , V_124 -> V_402 ) ;
if ( V_199 == V_403 )
F_5 ( V_322 , V_124 ) ;
if ( ! V_29 )
F_267 ( V_89 , V_124 , V_199 ) ;
}
static int F_273 ( struct V_389 * V_390 , int V_391 ,
void T_10 * V_392 ,
T_4 * V_393 , T_8 * V_394 )
{
struct V_389 V_395 = * V_390 ;
int V_75 ;
V_395 . V_396 = & V_397 ;
V_395 . V_398 = & V_404 ;
V_75 = F_263 ( & V_395 , V_391 , V_392 , V_393 , V_394 ) ;
F_271 ( V_390 , V_391 ) ;
return V_75 ;
}
int F_274 ( struct V_389 * V_390 , int V_391 ,
void T_10 * V_392 , T_4 * V_393 , T_8 * V_394 )
{
int V_75 = F_275 ( V_390 , V_391 , V_392 , V_393 , V_394 ) ;
F_271 ( V_390 , V_391 ) ;
return V_75 ;
}
int F_276 ( struct V_389 * V_390 , int V_391 ,
void T_10 * V_392 ,
T_4 * V_393 , T_8 * V_394 )
{
int V_75 = F_277 ( V_390 , V_391 , V_392 , V_393 , V_394 ) ;
F_271 ( V_390 , V_391 ) ;
return V_75 ;
}
static int F_278 ( struct V_389 * V_390 , int V_391 ,
void T_10 * V_392 ,
T_4 * V_393 , T_8 * V_394 )
{
int V_75 = F_279 ( V_390 , V_391 , V_392 , V_393 , V_394 ) ;
F_271 ( V_390 , V_391 ) ;
return V_75 ;
}
int F_280 ( struct V_389 * V_390 , int V_391 ,
void T_10 * V_392 ,
T_4 * V_393 , T_8 * V_394 )
{
int V_75 = F_281 ( V_390 , V_391 , V_392 , V_393 , V_394 ) ;
F_271 ( V_390 , V_391 ) ;
return V_75 ;
}
static int F_282 ( struct V_389 * V_390 , int V_391 ,
void T_10 * V_392 ,
T_4 * V_393 , T_8 * V_394 )
{
int V_75 = F_262 ( V_390 , V_391 , V_392 , V_393 , V_394 ) ;
F_271 ( V_390 , V_391 ) ;
return V_75 ;
}
static int F_283 ( struct V_389 * V_390 , int V_391 ,
void T_10 * V_392 ,
T_4 * V_393 , T_8 * V_394 )
{
struct V_114 * V_124 = V_390 -> V_398 ;
int V_75 ;
if ( strcmp ( V_390 -> V_405 , L_22 ) == 0 )
V_75 = F_276 ( V_390 , V_391 , V_392 , V_393 , V_394 ) ;
else if ( strcmp ( V_390 -> V_405 , L_23 ) == 0 )
V_75 = F_280 ( V_390 , V_391 , V_392 , V_393 , V_394 ) ;
else
V_75 = - 1 ;
if ( V_391 && V_75 == 0 ) {
V_124 -> V_125 =
F_7 ( F_75 ( V_124 , V_101 ) ) ;
}
return V_75 ;
}
int F_284 ( struct V_44 * V_29 , struct V_114 * V_124 ,
T_11 * V_406 )
{
int V_34 ;
struct V_407 * V_358 ;
const char * V_408 ;
char V_409 [ sizeof( L_24 ) + V_410 + V_410 ] ;
char * V_411 ;
V_358 = F_153 ( & V_412 , sizeof( * V_358 ) , V_109 ) ;
if ( ! V_358 )
goto V_166;
for ( V_34 = 0 ; V_34 < V_413 ; V_34 ++ ) {
V_358 -> V_414 [ V_34 ] . V_400 += ( long ) V_124 ;
V_358 -> V_414 [ V_34 ] . V_396 = V_29 ;
V_358 -> V_414 [ V_34 ] . V_398 = V_124 ;
}
if ( V_29 ) {
V_408 = V_29 -> V_415 ;
memset ( & V_358 -> V_414 [ V_413 ] , 0 ,
sizeof( V_358 -> V_414 [ V_413 ] ) ) ;
} else {
struct V_14 * V_15 = V_124 -> V_15 ;
V_408 = L_25 ;
V_358 -> V_414 [ V_413 ] . V_400 = & V_15 -> V_276 ;
V_358 -> V_414 [ V_416 ] . V_400 = & V_15 -> V_126 ;
V_358 -> V_414 [ V_417 ] . V_400 = & V_15 -> V_56 ;
V_358 -> V_414 [ V_418 ] . V_400 = & V_15 -> V_55 ;
}
if ( V_406 ) {
V_358 -> V_414 [ V_419 ] . T_11 = V_406 ;
V_358 -> V_414 [ V_420 ] . T_11 = V_406 ;
V_358 -> V_414 [ V_421 ] . T_11 = V_406 ;
V_358 -> V_414 [ V_422 ] . T_11 = V_406 ;
} else {
V_358 -> V_414 [ V_420 ] . T_11 =
F_283 ;
V_358 -> V_414 [ V_422 ] . T_11 =
F_283 ;
}
if ( F_151 ( V_124 ) -> V_423 != & V_424 )
V_358 -> V_414 [ 0 ] . V_405 = NULL ;
switch ( F_268 ( V_124 ) ) {
case V_210 :
V_411 = L_26 ;
break;
case V_212 :
V_411 = L_27 ;
break;
default:
F_285 () ;
}
snprintf ( V_409 , sizeof( V_409 ) , L_28 ,
V_411 , V_408 ) ;
V_358 -> V_425 =
F_286 ( F_151 ( V_124 ) , V_409 , V_358 -> V_414 ) ;
if ( ! V_358 -> V_425 )
goto free;
V_124 -> V_197 = V_358 ;
return 0 ;
free:
F_57 ( V_358 ) ;
V_166:
return - V_94 ;
}
void F_287 ( struct V_114 * V_124 )
{
if ( V_124 -> V_197 ) {
struct V_407 * V_358 = V_124 -> V_197 ;
V_124 -> V_197 = NULL ;
F_288 ( V_358 -> V_425 ) ;
F_57 ( V_358 ) ;
}
}
static int T_12 F_289 ( void )
{
F_290 ( V_426 , V_347 , F_186 , NULL , 0 ) ;
F_290 ( V_426 , V_8 , F_177 , NULL , 0 ) ;
F_290 ( V_426 , V_387 , NULL , F_228 , 0 ) ;
F_290 ( V_426 , V_427 , NULL , F_216 ,
0 ) ;
F_290 ( V_426 , V_428 , F_210 , NULL , 0 ) ;
return 0 ;
}
