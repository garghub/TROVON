int F_1 ( const struct V_1 * V_2 )
{
if ( V_3 )
return - V_4 ;
V_3 = V_2 ;
return 0 ;
}
void F_2 ( const struct V_1 * V_2 )
{
if ( V_3 != V_2 )
F_3 ( L_1 , V_5 ) ;
V_3 = NULL ;
}
void F_4 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_5 ( V_7 ) ;
V_3 -> V_10 ( V_9 ) ;
}
void F_6 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_5 ( V_7 ) ;
V_3 -> V_11 ( V_9 ) ;
}
T_1 F_7 ( void )
{
return V_3 -> V_12 ;
}
static int F_8 ( struct V_8 * V_9 )
{
int V_13 ;
if ( ! V_9 )
return - V_14 ;
if ( ! V_3 )
return - V_15 ;
F_9 ( V_9 -> V_16 ) ;
V_13 = V_3 -> V_17 ( V_9 ) ;
F_10 ( V_9 -> V_16 ) ;
return V_13 ;
}
static void F_11 ( struct V_8 * V_9 )
{
if ( ! V_9 )
return;
F_9 ( V_9 -> V_16 ) ;
V_3 -> V_18 ( V_9 ) ;
F_10 ( V_9 -> V_16 ) ;
}
void F_12 ( struct V_19 * V_20 , struct V_21 * V_22 )
{
F_13 ( ! V_20 || ! V_22 ) ;
V_3 -> V_23 ( V_20 , V_22 ) ;
}
static inline int F_14 ( struct V_19 * V_20 )
{
if ( ! V_20 )
return - V_14 ;
return V_3 -> V_24 ( V_20 ) ;
}
static inline struct V_19 * F_15 ( struct V_8 * V_9 ,
struct V_21 * V_22 )
{
if ( ! V_22 )
return NULL ;
return V_3 -> V_25 ( V_9 , V_22 ) ;
}
static T_1 F_16 ( struct V_19 * V_20 )
{
return V_3 -> V_26 ( V_20 ) ;
}
static T_1 F_17 ( struct V_21 * V_22 )
{
return V_3 -> V_27 ( V_22 ) ;
}
static T_1 F_18 ( struct V_8 * V_9 , T_1 * V_28 )
{
return V_3 -> V_29 ( V_9 , V_28 ) ;
}
static void F_19 ( struct V_8 * V_9 , struct V_30 * V_31 )
{
T_1 V_32 ;
V_32 = F_20 ( V_9 , V_33 ) ;
V_31 -> V_34 = F_21 ( V_32 ) ;
V_31 -> V_35 = F_22 ( V_32 ) ;
}
static void F_23 ( struct V_8 * V_9 , struct V_30 * V_31 )
{
T_1 V_32 ;
V_32 = ( V_31 -> V_34 << V_36 ) ;
V_32 |= ( V_31 -> V_35 << V_37 ) ;
F_24 ( V_9 , V_32 , V_33 ) ;
}
static void F_25 ( struct V_8 * V_9 , struct V_19 * V_20 )
{
V_3 -> V_38 ( V_9 , V_20 ) ;
}
static void F_26 ( struct V_8 * V_9 , struct V_19 * V_20 )
{
V_3 -> V_39 ( V_9 , V_20 ) ;
F_24 ( V_9 , 1 , V_40 ) ;
F_24 ( V_9 , 1 , V_41 ) ;
}
static inline T_2 F_27 ( struct V_8 * V_9 , struct V_19 * V_20 ,
char * V_42 )
{
F_13 ( ! V_20 || ! V_42 ) ;
return V_3 -> V_43 ( V_9 , V_20 , V_42 ) ;
}
static struct V_19 F_28 ( struct V_8 * V_9 , int V_44 )
{
struct V_19 V_20 ;
struct V_30 V_31 ;
F_19 ( V_9 , & V_31 ) ;
V_31 . V_35 = V_44 ;
F_23 ( V_9 , & V_31 ) ;
F_25 ( V_9 , & V_20 ) ;
return V_20 ;
}
static int F_29 ( struct V_8 * V_9 , struct V_21 * V_22 )
{
int V_13 = 0 ;
struct V_30 V_31 ;
struct V_19 * V_20 ;
if ( ! V_9 || ! V_9 -> V_45 || ! V_22 )
return - V_14 ;
F_9 ( V_9 -> V_16 ) ;
F_19 ( V_9 , & V_31 ) ;
if ( V_31 . V_34 == V_9 -> V_45 ) {
F_30 ( V_9 -> V_7 , L_2 , V_5 ) ;
V_13 = - V_4 ;
goto V_46;
}
if ( ! V_22 -> V_47 ) {
int V_48 ;
struct V_19 V_49 ;
F_31 (obj, obj->nr_tlb_entries, i, tmp)
if ( ! F_14 ( & V_49 ) )
break;
if ( V_48 == V_9 -> V_45 ) {
F_32 ( V_9 -> V_7 , L_3 , V_5 ) ;
V_13 = - V_4 ;
goto V_46;
}
F_19 ( V_9 , & V_31 ) ;
} else {
V_31 . V_35 = V_31 . V_34 ;
F_23 ( V_9 , & V_31 ) ;
}
V_20 = F_15 ( V_9 , V_22 ) ;
if ( F_33 ( V_20 ) ) {
F_10 ( V_9 -> V_16 ) ;
return F_34 ( V_20 ) ;
}
F_26 ( V_9 , V_20 ) ;
F_35 ( V_20 ) ;
if ( V_22 -> V_47 )
V_31 . V_34 ++ ;
if ( ++ V_31 . V_35 == V_9 -> V_45 )
V_31 . V_35 = V_31 . V_34 ;
F_23 ( V_9 , & V_31 ) ;
V_46:
F_10 ( V_9 -> V_16 ) ;
return V_13 ;
}
static int F_29 ( struct V_8 * V_9 , struct V_21 * V_22 )
{
return 0 ;
}
static int F_36 ( struct V_8 * V_9 , struct V_21 * V_22 )
{
return F_29 ( V_9 , V_22 ) ;
}
static void F_37 ( struct V_8 * V_9 , T_1 V_28 )
{
int V_48 ;
struct V_19 V_20 ;
F_9 ( V_9 -> V_16 ) ;
F_31 (obj, obj->nr_tlb_entries, i, cr) {
T_1 V_50 ;
T_3 V_51 ;
if ( ! F_14 ( & V_20 ) )
continue;
V_50 = F_16 ( & V_20 ) ;
V_51 = F_38 ( V_20 . V_52 & 3 ) ;
if ( ( V_50 <= V_28 ) && ( V_28 < V_50 + V_51 ) ) {
F_32 ( V_9 -> V_7 , L_4 ,
V_5 , V_50 , V_28 , V_51 ) ;
F_26 ( V_9 , & V_20 ) ;
F_24 ( V_9 , 1 , V_40 ) ;
}
}
F_10 ( V_9 -> V_16 ) ;
if ( V_48 == V_9 -> V_45 )
F_32 ( V_9 -> V_7 , L_5 , V_5 , V_28 ) ;
}
static void F_39 ( struct V_8 * V_9 )
{
struct V_30 V_31 ;
F_9 ( V_9 -> V_16 ) ;
V_31 . V_34 = 0 ;
V_31 . V_35 = 0 ;
F_23 ( V_9 , & V_31 ) ;
F_24 ( V_9 , 1 , V_53 ) ;
F_10 ( V_9 -> V_16 ) ;
}
T_2 F_40 ( struct V_8 * V_9 , char * V_42 , T_2 V_51 )
{
if ( ! V_9 || ! V_42 )
return - V_14 ;
F_9 ( V_9 -> V_16 ) ;
V_51 = V_3 -> V_54 ( V_9 , V_42 , V_51 ) ;
F_10 ( V_9 -> V_16 ) ;
return V_51 ;
}
static int
F_41 ( struct V_8 * V_9 , struct V_19 * V_55 , int V_56 )
{
int V_48 ;
struct V_30 V_57 ;
struct V_19 V_49 ;
struct V_19 * V_58 = V_55 ;
F_9 ( V_9 -> V_16 ) ;
F_19 ( V_9 , & V_57 ) ;
F_31 (obj, num, i, tmp) {
if ( ! F_14 ( & V_49 ) )
continue;
* V_58 ++ = V_49 ;
}
F_23 ( V_9 , & V_57 ) ;
F_10 ( V_9 -> V_16 ) ;
return V_58 - V_55 ;
}
T_3 F_42 ( struct V_8 * V_9 , char * V_42 , T_2 V_51 )
{
int V_48 , V_56 ;
struct V_19 * V_20 ;
char * V_58 = V_42 ;
V_56 = V_51 / sizeof( * V_20 ) ;
V_56 = F_43 ( V_9 -> V_45 , V_56 ) ;
V_20 = F_44 ( V_56 , sizeof( * V_20 ) , V_59 ) ;
if ( ! V_20 )
return 0 ;
V_56 = F_41 ( V_9 , V_20 , V_56 ) ;
for ( V_48 = 0 ; V_48 < V_56 ; V_48 ++ )
V_58 += F_27 ( V_9 , V_20 + V_48 , V_58 ) ;
F_35 ( V_20 ) ;
return V_58 - V_42 ;
}
int F_45 ( void * V_60 , int (* F_46)( struct V_6 * , void * ) )
{
return F_47 ( & V_61 . V_62 ,
NULL , V_60 , F_46 ) ;
}
static void F_48 ( T_1 * V_63 , T_1 * V_64 )
{
do {
asm("mcr p15, 0, %0, c7, c10, 1 @ flush_pgd"
: : "r" (first));
V_63 += V_65 / sizeof( * V_63 ) ;
} while ( V_63 <= V_64 );
}
static void F_49 ( T_1 * V_63 , T_1 * V_64 )
{
do {
asm("mcr p15, 0, %0, c7, c10, 1 @ flush_pte"
: : "r" (first));
V_63 += V_65 / sizeof( * V_63 ) ;
} while ( V_63 <= V_64 );
}
static void F_50 ( T_1 * V_66 )
{
F_51 ( V_67 , V_66 ) ;
}
static T_1 * F_52 ( struct V_8 * V_9 , T_1 * V_68 , T_1 V_28 )
{
T_1 * V_66 ;
if ( * V_68 )
goto V_69;
F_53 ( & V_9 -> V_70 ) ;
V_66 = F_54 ( V_67 , V_59 ) ;
F_55 ( & V_9 -> V_70 ) ;
if ( ! * V_68 ) {
if ( ! V_66 )
return F_56 ( - V_71 ) ;
* V_68 = F_57 ( V_66 ) | V_72 ;
F_48 ( V_68 , V_68 ) ;
F_58 ( V_9 -> V_7 , L_6 , V_5 , V_66 ) ;
} else {
F_50 ( V_66 ) ;
}
V_69:
V_66 = F_59 ( V_68 , V_28 ) ;
F_58 ( V_9 -> V_7 ,
L_7 ,
V_5 , V_28 , V_68 , * V_68 , V_66 , * V_66 ) ;
return V_66 ;
}
static int F_60 ( struct V_8 * V_9 , T_1 V_28 , T_1 V_73 , T_1 V_74 )
{
T_1 * V_68 = F_61 ( V_9 , V_28 ) ;
if ( ( V_28 | V_73 ) & ~ V_75 ) {
F_62 ( V_9 -> V_7 , L_8 ,
V_5 , V_28 , V_73 , V_76 ) ;
return - V_14 ;
}
* V_68 = ( V_73 & V_75 ) | V_74 | V_77 ;
F_48 ( V_68 , V_68 ) ;
return 0 ;
}
static int F_63 ( struct V_8 * V_9 , T_1 V_28 , T_1 V_73 , T_1 V_74 )
{
T_1 * V_68 = F_61 ( V_9 , V_28 ) ;
int V_48 ;
if ( ( V_28 | V_73 ) & ~ V_78 ) {
F_62 ( V_9 -> V_7 , L_8 ,
V_5 , V_28 , V_73 , V_79 ) ;
return - V_14 ;
}
for ( V_48 = 0 ; V_48 < 16 ; V_48 ++ )
* ( V_68 + V_48 ) = ( V_73 & V_78 ) | V_74 | V_80 ;
F_48 ( V_68 , V_68 + 15 ) ;
return 0 ;
}
static int F_64 ( struct V_8 * V_9 , T_1 V_28 , T_1 V_73 , T_1 V_74 )
{
T_1 * V_68 = F_61 ( V_9 , V_28 ) ;
T_1 * V_66 = F_52 ( V_9 , V_68 , V_28 ) ;
if ( F_33 ( V_66 ) )
return F_34 ( V_66 ) ;
* V_66 = ( V_73 & V_81 ) | V_74 | V_82 ;
F_49 ( V_66 , V_66 ) ;
F_58 ( V_9 -> V_7 , L_9 ,
V_5 , V_28 , V_73 , V_66 , * V_66 ) ;
return 0 ;
}
static int F_65 ( struct V_8 * V_9 , T_1 V_28 , T_1 V_73 , T_1 V_74 )
{
T_1 * V_68 = F_61 ( V_9 , V_28 ) ;
T_1 * V_66 = F_52 ( V_9 , V_68 , V_28 ) ;
int V_48 ;
if ( ( V_28 | V_73 ) & ~ V_83 ) {
F_62 ( V_9 -> V_7 , L_8 ,
V_5 , V_28 , V_73 , V_84 ) ;
return - V_14 ;
}
if ( F_33 ( V_66 ) )
return F_34 ( V_66 ) ;
for ( V_48 = 0 ; V_48 < 16 ; V_48 ++ )
* ( V_66 + V_48 ) = ( V_73 & V_83 ) | V_74 | V_85 ;
F_49 ( V_66 , V_66 + 15 ) ;
return 0 ;
}
static int
F_66 ( struct V_8 * V_9 , struct V_21 * V_22 )
{
int (* F_46)( struct V_8 * , T_1 , T_1 , T_1 );
T_1 V_74 ;
int V_13 ;
if ( ! V_9 || ! V_22 )
return - V_14 ;
switch ( V_22 -> V_86 ) {
case V_87 :
F_46 = F_63 ;
break;
case V_88 :
F_46 = F_60 ;
break;
case V_89 :
F_46 = F_65 ;
break;
case V_90 :
F_46 = F_64 ;
break;
default:
F_46 = NULL ;
F_67 () ;
break;
}
V_74 = F_17 ( V_22 ) ;
F_55 ( & V_9 -> V_70 ) ;
V_13 = F_46 ( V_9 , V_22 -> V_28 , V_22 -> V_73 , V_74 ) ;
F_53 ( & V_9 -> V_70 ) ;
return V_13 ;
}
int F_68 ( struct V_8 * V_9 , struct V_21 * V_22 )
{
int V_13 ;
F_37 ( V_9 , V_22 -> V_28 ) ;
V_13 = F_66 ( V_9 , V_22 ) ;
if ( ! V_13 )
F_36 ( V_9 , V_22 ) ;
return V_13 ;
}
static void
F_69 ( struct V_8 * V_9 , T_1 V_28 , T_1 * * V_91 , T_1 * * V_92 )
{
T_1 * V_68 , * V_66 = NULL ;
V_68 = F_61 ( V_9 , V_28 ) ;
if ( ! * V_68 )
goto V_46;
if ( F_70 ( * V_68 ) )
V_66 = F_59 ( V_68 , V_28 ) ;
V_46:
* V_91 = V_68 ;
* V_92 = V_66 ;
}
static T_3 F_71 ( struct V_8 * V_9 , T_1 V_28 )
{
T_3 V_51 ;
T_1 * V_68 = F_61 ( V_9 , V_28 ) ;
int V_93 = 1 ;
if ( ! * V_68 )
return 0 ;
if ( F_70 ( * V_68 ) ) {
int V_48 ;
T_1 * V_66 = F_59 ( V_68 , V_28 ) ;
V_51 = V_94 ;
if ( * V_66 & V_85 ) {
V_93 *= 16 ;
V_66 = F_59 ( V_68 , ( V_28 & V_83 ) ) ;
}
V_51 *= V_93 ;
memset ( V_66 , 0 , V_93 * sizeof( * V_66 ) ) ;
F_49 ( V_66 , V_66 + ( V_93 - 1 ) * sizeof( * V_66 ) ) ;
V_66 = F_59 ( V_68 , 0 ) ;
for ( V_48 = 0 ; V_48 < V_95 ; V_48 ++ )
if ( V_66 [ V_48 ] )
goto V_46;
F_50 ( V_66 ) ;
V_93 = 1 ;
} else {
V_51 = V_96 ;
if ( ( * V_68 & V_80 ) == V_80 ) {
V_93 *= 16 ;
V_68 = F_61 ( V_9 , ( V_28 & V_78 ) ) ;
}
V_51 *= V_93 ;
}
memset ( V_68 , 0 , V_93 * sizeof( * V_68 ) ) ;
F_48 ( V_68 , V_68 + ( V_93 - 1 ) * sizeof( * V_68 ) ) ;
V_46:
return V_51 ;
}
static T_3 F_72 ( struct V_8 * V_9 , T_1 V_28 )
{
T_3 V_51 ;
F_55 ( & V_9 -> V_70 ) ;
V_51 = F_71 ( V_9 , V_28 ) ;
F_37 ( V_9 , V_28 ) ;
F_53 ( & V_9 -> V_70 ) ;
return V_51 ;
}
static void F_73 ( struct V_8 * V_9 )
{
int V_48 ;
F_55 ( & V_9 -> V_70 ) ;
for ( V_48 = 0 ; V_48 < V_97 ; V_48 ++ ) {
T_1 V_28 ;
T_1 * V_68 ;
V_28 = V_48 << V_98 ;
V_68 = F_61 ( V_9 , V_28 ) ;
if ( ! * V_68 )
continue;
if ( F_70 ( * V_68 ) )
F_50 ( F_59 ( V_68 , 0 ) ) ;
* V_68 = 0 ;
F_48 ( V_68 , V_68 ) ;
}
F_39 ( V_9 ) ;
F_53 ( & V_9 -> V_70 ) ;
}
static T_4 F_74 ( int V_99 , void * V_60 )
{
T_1 V_28 , V_100 ;
T_1 * V_68 , * V_66 ;
struct V_8 * V_9 = V_60 ;
struct V_101 * V_102 = V_9 -> V_102 ;
if ( ! V_9 -> V_103 )
return V_104 ;
F_9 ( V_9 -> V_16 ) ;
V_100 = F_18 ( V_9 , & V_28 ) ;
F_10 ( V_9 -> V_16 ) ;
if ( V_100 == 0 )
return V_105 ;
if ( ! F_75 ( V_102 , V_9 -> V_7 , V_28 , 0 ) )
return V_105 ;
F_11 ( V_9 ) ;
V_68 = F_61 ( V_9 , V_28 ) ;
if ( ! F_70 ( * V_68 ) ) {
F_62 ( V_9 -> V_7 , L_10
L_11 , V_9 -> V_106 , V_100 , V_28 , V_68 , * V_68 ) ;
return V_104 ;
}
V_66 = F_59 ( V_68 , V_28 ) ;
F_62 ( V_9 -> V_7 , L_12
L_13 , V_9 -> V_106 , V_100 , V_28 , V_68 , * V_68 ,
V_66 , * V_66 ) ;
return V_104 ;
}
static int F_76 ( struct V_6 * V_7 , void * V_60 )
{
struct V_8 * V_9 = F_77 ( V_7 ) ;
const char * V_106 = V_60 ;
F_78 ( L_14 , V_5 , V_9 -> V_106 , V_106 ) ;
return strcmp ( V_9 -> V_106 , V_106 ) == 0 ;
}
static struct V_8 * F_79 ( const char * V_106 , T_1 * V_68 )
{
int V_13 = - V_71 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
V_7 = F_80 ( & V_61 . V_62 , NULL ,
( void * ) V_106 ,
F_76 ) ;
if ( ! V_7 )
return NULL ;
V_9 = F_77 ( V_7 ) ;
F_55 ( & V_9 -> V_107 ) ;
if ( ++ V_9 -> V_103 > 1 ) {
F_62 ( V_7 , L_15 , V_9 -> V_106 ) ;
V_13 = - V_4 ;
goto V_108;
}
V_9 -> V_68 = V_68 ;
V_13 = F_8 ( V_9 ) ;
if ( V_13 )
goto V_108;
F_39 ( V_9 ) ;
if ( ! F_81 ( V_9 -> V_109 ) )
goto V_110;
F_53 ( & V_9 -> V_107 ) ;
F_32 ( V_9 -> V_7 , L_16 , V_5 , V_9 -> V_106 ) ;
return V_9 ;
V_110:
if ( V_9 -> V_103 == 1 )
F_11 ( V_9 ) ;
V_108:
V_9 -> V_103 -- ;
F_53 ( & V_9 -> V_107 ) ;
return F_56 ( V_13 ) ;
}
static void F_82 ( struct V_8 * V_9 )
{
if ( ! V_9 || F_33 ( V_9 ) )
return;
F_55 ( & V_9 -> V_107 ) ;
if ( -- V_9 -> V_103 == 0 )
F_11 ( V_9 ) ;
F_83 ( V_9 -> V_109 ) ;
V_9 -> V_68 = NULL ;
F_53 ( & V_9 -> V_107 ) ;
F_32 ( V_9 -> V_7 , L_16 , V_5 , V_9 -> V_106 ) ;
}
static int T_5 F_84 ( struct V_111 * V_112 )
{
int V_13 = - V_15 ;
int V_99 ;
struct V_8 * V_9 ;
struct V_113 * V_114 ;
struct V_115 * V_116 = V_112 -> V_7 . V_117 ;
if ( V_112 -> V_118 != 2 )
return - V_14 ;
V_9 = F_85 ( sizeof( * V_9 ) + V_119 , V_59 ) ;
if ( ! V_9 )
return - V_71 ;
V_9 -> V_16 = F_86 ( & V_112 -> V_7 , V_116 -> V_120 ) ;
if ( F_33 ( V_9 -> V_16 ) )
goto V_121;
V_9 -> V_45 = V_116 -> V_45 ;
V_9 -> V_106 = V_116 -> V_106 ;
V_9 -> V_7 = & V_112 -> V_7 ;
V_9 -> V_122 = ( void * ) V_9 + sizeof( * V_9 ) ;
V_9 -> V_123 = V_116 -> V_123 ;
V_9 -> V_124 = V_116 -> V_124 ;
F_87 ( & V_9 -> V_107 ) ;
F_88 ( & V_9 -> V_125 ) ;
F_87 ( & V_9 -> V_70 ) ;
F_89 ( & V_9 -> V_126 ) ;
V_114 = F_90 ( V_112 , V_127 , 0 ) ;
if ( ! V_114 ) {
V_13 = - V_15 ;
goto V_128;
}
V_114 = F_91 ( V_114 -> V_50 , F_92 ( V_114 ) ,
F_93 ( & V_112 -> V_7 ) ) ;
if ( ! V_114 ) {
V_13 = - V_129 ;
goto V_128;
}
V_9 -> V_130 = F_94 ( V_114 -> V_50 , F_92 ( V_114 ) ) ;
if ( ! V_9 -> V_130 ) {
V_13 = - V_71 ;
goto V_131;
}
V_99 = F_95 ( V_112 , 0 ) ;
if ( V_99 < 0 ) {
V_13 = - V_15 ;
goto V_132;
}
V_13 = F_96 ( V_99 , F_74 , V_133 ,
F_93 ( & V_112 -> V_7 ) , V_9 ) ;
if ( V_13 < 0 )
goto V_132;
F_97 ( V_112 , V_9 ) ;
F_98 ( & V_112 -> V_7 , L_17 , V_9 -> V_106 ) ;
return 0 ;
V_132:
F_99 ( V_9 -> V_130 ) ;
V_131:
F_100 ( V_114 -> V_50 , F_92 ( V_114 ) ) ;
V_128:
F_101 ( V_9 -> V_16 ) ;
V_121:
F_35 ( V_9 ) ;
return V_13 ;
}
static int T_6 F_102 ( struct V_111 * V_112 )
{
int V_99 ;
struct V_113 * V_114 ;
struct V_8 * V_9 = F_103 ( V_112 ) ;
F_97 ( V_112 , NULL ) ;
F_73 ( V_9 ) ;
V_99 = F_95 ( V_112 , 0 ) ;
F_104 ( V_99 , V_9 ) ;
V_114 = F_90 ( V_112 , V_127 , 0 ) ;
F_100 ( V_114 -> V_50 , F_92 ( V_114 ) ) ;
F_99 ( V_9 -> V_130 ) ;
F_101 ( V_9 -> V_16 ) ;
F_98 ( & V_112 -> V_7 , L_18 , V_9 -> V_106 ) ;
F_35 ( V_9 ) ;
return 0 ;
}
static void F_105 ( void * V_66 )
{
F_106 ( V_66 , V_134 ) ;
}
static int F_107 ( struct V_101 * V_102 , unsigned long V_28 ,
T_7 V_73 , T_3 V_51 , int V_74 )
{
struct V_135 * V_136 = V_102 -> V_137 ;
struct V_8 * V_138 = V_136 -> V_139 ;
struct V_6 * V_7 = V_138 -> V_7 ;
struct V_21 V_22 ;
int V_140 ;
T_1 V_141 , V_142 ;
V_140 = F_108 ( V_51 ) ;
if ( V_140 < 0 ) {
F_62 ( V_7 , L_19 , V_51 ) ;
return - V_14 ;
}
F_32 ( V_7 , L_20 , V_28 , V_73 , V_51 ) ;
V_142 = V_140 | V_74 ;
F_109 ( & V_22 , V_28 , V_73 , V_142 ) ;
V_141 = F_68 ( V_138 , & V_22 ) ;
if ( V_141 )
F_62 ( V_7 , L_21 , V_141 ) ;
return V_141 ;
}
static T_3 F_110 ( struct V_101 * V_102 , unsigned long V_28 ,
T_3 V_143 )
{
struct V_135 * V_136 = V_102 -> V_137 ;
struct V_8 * V_138 = V_136 -> V_139 ;
struct V_6 * V_7 = V_138 -> V_7 ;
F_32 ( V_7 , L_22 , V_28 , V_143 ) ;
return F_72 ( V_138 , V_28 ) ;
}
static int
F_111 ( struct V_101 * V_102 , struct V_6 * V_7 )
{
struct V_135 * V_136 = V_102 -> V_137 ;
struct V_8 * V_138 ;
struct V_144 * V_145 = V_7 -> V_146 . V_147 ;
int V_141 = 0 ;
F_55 ( & V_136 -> V_148 ) ;
if ( V_136 -> V_139 ) {
F_62 ( V_7 , L_23 ) ;
V_141 = - V_4 ;
goto V_46;
}
V_138 = F_79 ( V_145 -> V_106 , V_136 -> V_149 ) ;
if ( F_33 ( V_138 ) ) {
V_141 = F_34 ( V_138 ) ;
F_62 ( V_7 , L_24 , V_141 ) ;
goto V_46;
}
V_136 -> V_139 = V_145 -> V_139 = V_138 ;
V_136 -> V_7 = V_7 ;
V_138 -> V_102 = V_102 ;
V_46:
F_53 ( & V_136 -> V_148 ) ;
return V_141 ;
}
static void F_112 ( struct V_135 * V_136 ,
struct V_6 * V_7 )
{
struct V_8 * V_138 = F_5 ( V_7 ) ;
struct V_144 * V_145 = V_7 -> V_146 . V_147 ;
if ( V_136 -> V_139 != V_138 ) {
F_62 ( V_7 , L_25 ) ;
return;
}
F_73 ( V_138 ) ;
F_82 ( V_138 ) ;
V_136 -> V_139 = V_145 -> V_139 = NULL ;
V_136 -> V_7 = NULL ;
}
static void F_113 ( struct V_101 * V_102 ,
struct V_6 * V_7 )
{
struct V_135 * V_136 = V_102 -> V_137 ;
F_55 ( & V_136 -> V_148 ) ;
F_112 ( V_136 , V_7 ) ;
F_53 ( & V_136 -> V_148 ) ;
}
static int F_114 ( struct V_101 * V_102 )
{
struct V_135 * V_136 ;
V_136 = F_85 ( sizeof( * V_136 ) , V_59 ) ;
if ( ! V_136 ) {
F_3 ( L_26 ) ;
goto V_46;
}
V_136 -> V_149 = F_85 ( V_150 , V_59 ) ;
if ( ! V_136 -> V_149 ) {
F_3 ( L_26 ) ;
goto V_151;
}
F_13 ( ! F_115 ( ( long ) V_136 -> V_149 , V_150 ) ) ;
F_106 ( V_136 -> V_149 , V_150 ) ;
F_87 ( & V_136 -> V_148 ) ;
V_102 -> V_137 = V_136 ;
return 0 ;
V_151:
F_35 ( V_136 ) ;
V_46:
return - V_71 ;
}
static void F_116 ( struct V_101 * V_102 )
{
struct V_135 * V_136 = V_102 -> V_137 ;
V_102 -> V_137 = NULL ;
if ( V_136 -> V_139 )
F_112 ( V_136 , V_136 -> V_7 ) ;
F_35 ( V_136 -> V_149 ) ;
F_35 ( V_136 ) ;
}
static T_7 F_117 ( struct V_101 * V_102 ,
unsigned long V_28 )
{
struct V_135 * V_136 = V_102 -> V_137 ;
struct V_8 * V_138 = V_136 -> V_139 ;
struct V_6 * V_7 = V_138 -> V_7 ;
T_1 * V_152 , * V_153 ;
T_7 V_141 = 0 ;
F_69 ( V_138 , V_28 , & V_152 , & V_153 ) ;
if ( V_153 ) {
if ( F_118 ( * V_153 ) )
V_141 = F_119 ( * V_153 , V_28 , V_154 ) ;
else if ( F_120 ( * V_153 ) )
V_141 = F_119 ( * V_153 , V_28 , V_83 ) ;
else
F_62 ( V_7 , L_27 , * V_153 , V_28 ) ;
} else {
if ( F_121 ( * V_152 ) )
V_141 = F_119 ( * V_152 , V_28 , V_75 ) ;
else if ( F_122 ( * V_152 ) )
V_141 = F_119 ( * V_152 , V_28 , V_78 ) ;
else
F_62 ( V_7 , L_28 , * V_152 , V_28 ) ;
}
return V_141 ;
}
static int F_123 ( struct V_101 * V_102 ,
unsigned long V_155 )
{
return 0 ;
}
static int T_8 F_124 ( void )
{
struct V_156 * V_58 ;
const unsigned long V_142 = V_157 ;
T_3 V_158 = 1 << 10 ;
V_58 = F_125 ( L_29 , V_134 , V_158 , V_142 ,
F_105 ) ;
if ( ! V_58 )
return - V_71 ;
V_67 = V_58 ;
F_126 ( & V_159 , & V_160 ) ;
return F_127 ( & V_61 ) ;
}
static void T_9 F_128 ( void )
{
F_129 ( V_67 ) ;
F_130 ( & V_61 ) ;
}
