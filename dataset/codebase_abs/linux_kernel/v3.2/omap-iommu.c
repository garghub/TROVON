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
V_3 -> V_8 ( V_7 ) ;
}
void F_5 ( struct V_6 * V_7 )
{
V_3 -> V_9 ( V_7 ) ;
}
T_1 F_6 ( void )
{
return V_3 -> V_10 ;
}
static int F_7 ( struct V_6 * V_7 )
{
int V_11 ;
if ( ! V_7 )
return - V_12 ;
if ( ! V_3 )
return - V_13 ;
F_8 ( V_7 -> V_14 ) ;
V_11 = V_3 -> V_15 ( V_7 ) ;
F_9 ( V_7 -> V_14 ) ;
return V_11 ;
}
static void F_10 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_8 ( V_7 -> V_14 ) ;
V_3 -> V_16 ( V_7 ) ;
F_9 ( V_7 -> V_14 ) ;
}
void F_11 ( struct V_17 * V_18 , struct V_19 * V_20 )
{
F_12 ( ! V_18 || ! V_20 ) ;
V_3 -> V_21 ( V_18 , V_20 ) ;
}
static inline int F_13 ( struct V_17 * V_18 )
{
if ( ! V_18 )
return - V_12 ;
return V_3 -> V_22 ( V_18 ) ;
}
static inline struct V_17 * F_14 ( struct V_6 * V_7 ,
struct V_19 * V_20 )
{
if ( ! V_20 )
return NULL ;
return V_3 -> V_23 ( V_7 , V_20 ) ;
}
static T_1 F_15 ( struct V_17 * V_18 )
{
return V_3 -> V_24 ( V_18 ) ;
}
static T_1 F_16 ( struct V_19 * V_20 )
{
return V_3 -> V_25 ( V_20 ) ;
}
static T_1 F_17 ( struct V_6 * V_7 , T_1 * V_26 )
{
return V_3 -> V_27 ( V_7 , V_26 ) ;
}
static void F_18 ( struct V_6 * V_7 , struct V_28 * V_29 )
{
T_1 V_30 ;
V_30 = F_19 ( V_7 , V_31 ) ;
V_29 -> V_32 = F_20 ( V_30 ) ;
V_29 -> V_33 = F_21 ( V_30 ) ;
}
static void F_22 ( struct V_6 * V_7 , struct V_28 * V_29 )
{
T_1 V_30 ;
V_30 = ( V_29 -> V_32 << V_34 ) ;
V_30 |= ( V_29 -> V_33 << V_35 ) ;
F_23 ( V_7 , V_30 , V_31 ) ;
}
static void F_24 ( struct V_6 * V_7 , struct V_17 * V_18 )
{
V_3 -> V_36 ( V_7 , V_18 ) ;
}
static void F_25 ( struct V_6 * V_7 , struct V_17 * V_18 )
{
V_3 -> V_37 ( V_7 , V_18 ) ;
F_23 ( V_7 , 1 , V_38 ) ;
F_23 ( V_7 , 1 , V_39 ) ;
}
static inline T_2 F_26 ( struct V_6 * V_7 , struct V_17 * V_18 ,
char * V_40 )
{
F_12 ( ! V_18 || ! V_40 ) ;
return V_3 -> V_41 ( V_7 , V_18 , V_40 ) ;
}
static struct V_17 F_27 ( struct V_6 * V_7 , int V_42 )
{
struct V_17 V_18 ;
struct V_28 V_29 ;
F_18 ( V_7 , & V_29 ) ;
V_29 . V_33 = V_42 ;
F_22 ( V_7 , & V_29 ) ;
F_24 ( V_7 , & V_18 ) ;
return V_18 ;
}
static int F_28 ( struct V_6 * V_7 , struct V_19 * V_20 )
{
int V_11 = 0 ;
struct V_28 V_29 ;
struct V_17 * V_18 ;
if ( ! V_7 || ! V_7 -> V_43 || ! V_20 )
return - V_12 ;
F_8 ( V_7 -> V_14 ) ;
F_18 ( V_7 , & V_29 ) ;
if ( V_29 . V_32 == V_7 -> V_43 ) {
F_29 ( V_7 -> V_44 , L_2 , V_5 ) ;
V_11 = - V_4 ;
goto V_45;
}
if ( ! V_20 -> V_46 ) {
int V_47 ;
struct V_17 V_48 ;
F_30 (obj, obj->nr_tlb_entries, i, tmp)
if ( ! F_13 ( & V_48 ) )
break;
if ( V_47 == V_7 -> V_43 ) {
F_31 ( V_7 -> V_44 , L_3 , V_5 ) ;
V_11 = - V_4 ;
goto V_45;
}
F_18 ( V_7 , & V_29 ) ;
} else {
V_29 . V_33 = V_29 . V_32 ;
F_22 ( V_7 , & V_29 ) ;
}
V_18 = F_14 ( V_7 , V_20 ) ;
if ( F_32 ( V_18 ) ) {
F_9 ( V_7 -> V_14 ) ;
return F_33 ( V_18 ) ;
}
F_25 ( V_7 , V_18 ) ;
F_34 ( V_18 ) ;
if ( V_20 -> V_46 )
V_29 . V_32 ++ ;
if ( ++ V_29 . V_33 == V_7 -> V_43 )
V_29 . V_33 = V_29 . V_32 ;
F_22 ( V_7 , & V_29 ) ;
V_45:
F_9 ( V_7 -> V_14 ) ;
return V_11 ;
}
static int F_28 ( struct V_6 * V_7 , struct V_19 * V_20 )
{
return 0 ;
}
static int F_35 ( struct V_6 * V_7 , struct V_19 * V_20 )
{
return F_28 ( V_7 , V_20 ) ;
}
static void F_36 ( struct V_6 * V_7 , T_1 V_26 )
{
int V_47 ;
struct V_17 V_18 ;
F_8 ( V_7 -> V_14 ) ;
F_30 (obj, obj->nr_tlb_entries, i, cr) {
T_1 V_49 ;
T_3 V_50 ;
if ( ! F_13 ( & V_18 ) )
continue;
V_49 = F_15 ( & V_18 ) ;
V_50 = F_37 ( V_18 . V_51 & 3 ) ;
if ( ( V_49 <= V_26 ) && ( V_26 < V_49 + V_50 ) ) {
F_31 ( V_7 -> V_44 , L_4 ,
V_5 , V_49 , V_26 , V_50 ) ;
F_25 ( V_7 , & V_18 ) ;
F_23 ( V_7 , 1 , V_38 ) ;
}
}
F_9 ( V_7 -> V_14 ) ;
if ( V_47 == V_7 -> V_43 )
F_31 ( V_7 -> V_44 , L_5 , V_5 , V_26 ) ;
}
static void F_38 ( struct V_6 * V_7 )
{
struct V_28 V_29 ;
F_8 ( V_7 -> V_14 ) ;
V_29 . V_32 = 0 ;
V_29 . V_33 = 0 ;
F_22 ( V_7 , & V_29 ) ;
F_23 ( V_7 , 1 , V_52 ) ;
F_9 ( V_7 -> V_14 ) ;
}
T_2 F_39 ( struct V_6 * V_7 , char * V_40 , T_2 V_50 )
{
if ( ! V_7 || ! V_40 )
return - V_12 ;
F_8 ( V_7 -> V_14 ) ;
V_50 = V_3 -> V_53 ( V_7 , V_40 , V_50 ) ;
F_9 ( V_7 -> V_14 ) ;
return V_50 ;
}
static int
F_40 ( struct V_6 * V_7 , struct V_17 * V_54 , int V_55 )
{
int V_47 ;
struct V_28 V_56 ;
struct V_17 V_48 ;
struct V_17 * V_57 = V_54 ;
F_8 ( V_7 -> V_14 ) ;
F_18 ( V_7 , & V_56 ) ;
F_30 (obj, num, i, tmp) {
if ( ! F_13 ( & V_48 ) )
continue;
* V_57 ++ = V_48 ;
}
F_22 ( V_7 , & V_56 ) ;
F_9 ( V_7 -> V_14 ) ;
return V_57 - V_54 ;
}
T_3 F_41 ( struct V_6 * V_7 , char * V_40 , T_2 V_50 )
{
int V_47 , V_55 ;
struct V_17 * V_18 ;
char * V_57 = V_40 ;
V_55 = V_50 / sizeof( * V_18 ) ;
V_55 = F_42 ( V_7 -> V_43 , V_55 ) ;
V_18 = F_43 ( V_55 , sizeof( * V_18 ) , V_58 ) ;
if ( ! V_18 )
return 0 ;
V_55 = F_40 ( V_7 , V_18 , V_55 ) ;
for ( V_47 = 0 ; V_47 < V_55 ; V_47 ++ )
V_57 += F_26 ( V_7 , V_18 + V_47 , V_57 ) ;
F_34 ( V_18 ) ;
return V_57 - V_40 ;
}
int F_44 ( void * V_59 , int (* F_45)( struct V_60 * , void * ) )
{
return F_46 ( & V_61 . V_62 ,
NULL , V_59 , F_45 ) ;
}
static void F_47 ( T_1 * V_63 , T_1 * V_64 )
{
do {
asm("mcr p15, 0, %0, c7, c10, 1 @ flush_pgd"
: : "r" (first));
V_63 += V_65 / sizeof( * V_63 ) ;
} while ( V_63 <= V_64 );
}
static void F_48 ( T_1 * V_63 , T_1 * V_64 )
{
do {
asm("mcr p15, 0, %0, c7, c10, 1 @ flush_pte"
: : "r" (first));
V_63 += V_65 / sizeof( * V_63 ) ;
} while ( V_63 <= V_64 );
}
static void F_49 ( T_1 * V_66 )
{
F_50 ( V_67 , V_66 ) ;
}
static T_1 * F_51 ( struct V_6 * V_7 , T_1 * V_68 , T_1 V_26 )
{
T_1 * V_66 ;
if ( * V_68 )
goto V_69;
F_52 ( & V_7 -> V_70 ) ;
V_66 = F_53 ( V_67 , V_58 ) ;
F_54 ( & V_7 -> V_70 ) ;
if ( ! * V_68 ) {
if ( ! V_66 )
return F_55 ( - V_71 ) ;
* V_68 = F_56 ( V_66 ) | V_72 ;
F_47 ( V_68 , V_68 ) ;
F_57 ( V_7 -> V_44 , L_6 , V_5 , V_66 ) ;
} else {
F_49 ( V_66 ) ;
}
V_69:
V_66 = F_58 ( V_68 , V_26 ) ;
F_57 ( V_7 -> V_44 ,
L_7 ,
V_5 , V_26 , V_68 , * V_68 , V_66 , * V_66 ) ;
return V_66 ;
}
static int F_59 ( struct V_6 * V_7 , T_1 V_26 , T_1 V_73 , T_1 V_74 )
{
T_1 * V_68 = F_60 ( V_7 , V_26 ) ;
if ( ( V_26 | V_73 ) & ~ V_75 ) {
F_61 ( V_7 -> V_44 , L_8 ,
V_5 , V_26 , V_73 , V_76 ) ;
return - V_12 ;
}
* V_68 = ( V_73 & V_75 ) | V_74 | V_77 ;
F_47 ( V_68 , V_68 ) ;
return 0 ;
}
static int F_62 ( struct V_6 * V_7 , T_1 V_26 , T_1 V_73 , T_1 V_74 )
{
T_1 * V_68 = F_60 ( V_7 , V_26 ) ;
int V_47 ;
if ( ( V_26 | V_73 ) & ~ V_78 ) {
F_61 ( V_7 -> V_44 , L_8 ,
V_5 , V_26 , V_73 , V_79 ) ;
return - V_12 ;
}
for ( V_47 = 0 ; V_47 < 16 ; V_47 ++ )
* ( V_68 + V_47 ) = ( V_73 & V_78 ) | V_74 | V_80 ;
F_47 ( V_68 , V_68 + 15 ) ;
return 0 ;
}
static int F_63 ( struct V_6 * V_7 , T_1 V_26 , T_1 V_73 , T_1 V_74 )
{
T_1 * V_68 = F_60 ( V_7 , V_26 ) ;
T_1 * V_66 = F_51 ( V_7 , V_68 , V_26 ) ;
if ( F_32 ( V_66 ) )
return F_33 ( V_66 ) ;
* V_66 = ( V_73 & V_81 ) | V_74 | V_82 ;
F_48 ( V_66 , V_66 ) ;
F_57 ( V_7 -> V_44 , L_9 ,
V_5 , V_26 , V_73 , V_66 , * V_66 ) ;
return 0 ;
}
static int F_64 ( struct V_6 * V_7 , T_1 V_26 , T_1 V_73 , T_1 V_74 )
{
T_1 * V_68 = F_60 ( V_7 , V_26 ) ;
T_1 * V_66 = F_51 ( V_7 , V_68 , V_26 ) ;
int V_47 ;
if ( ( V_26 | V_73 ) & ~ V_83 ) {
F_61 ( V_7 -> V_44 , L_8 ,
V_5 , V_26 , V_73 , V_84 ) ;
return - V_12 ;
}
if ( F_32 ( V_66 ) )
return F_33 ( V_66 ) ;
for ( V_47 = 0 ; V_47 < 16 ; V_47 ++ )
* ( V_66 + V_47 ) = ( V_73 & V_83 ) | V_74 | V_85 ;
F_48 ( V_66 , V_66 + 15 ) ;
return 0 ;
}
static int
F_65 ( struct V_6 * V_7 , struct V_19 * V_20 )
{
int (* F_45)( struct V_6 * , T_1 , T_1 , T_1 );
T_1 V_74 ;
int V_11 ;
if ( ! V_7 || ! V_20 )
return - V_12 ;
switch ( V_20 -> V_86 ) {
case V_87 :
F_45 = F_62 ;
break;
case V_88 :
F_45 = F_59 ;
break;
case V_89 :
F_45 = F_64 ;
break;
case V_90 :
F_45 = F_63 ;
break;
default:
F_45 = NULL ;
F_66 () ;
break;
}
V_74 = F_16 ( V_20 ) ;
F_54 ( & V_7 -> V_70 ) ;
V_11 = F_45 ( V_7 , V_20 -> V_26 , V_20 -> V_73 , V_74 ) ;
F_52 ( & V_7 -> V_70 ) ;
return V_11 ;
}
int F_67 ( struct V_6 * V_7 , struct V_19 * V_20 )
{
int V_11 ;
F_36 ( V_7 , V_20 -> V_26 ) ;
V_11 = F_65 ( V_7 , V_20 ) ;
if ( ! V_11 )
F_35 ( V_7 , V_20 ) ;
return V_11 ;
}
static void
F_68 ( struct V_6 * V_7 , T_1 V_26 , T_1 * * V_91 , T_1 * * V_92 )
{
T_1 * V_68 , * V_66 = NULL ;
V_68 = F_60 ( V_7 , V_26 ) ;
if ( ! * V_68 )
goto V_45;
if ( F_69 ( * V_68 ) )
V_66 = F_58 ( V_68 , V_26 ) ;
V_45:
* V_91 = V_68 ;
* V_92 = V_66 ;
}
static T_3 F_70 ( struct V_6 * V_7 , T_1 V_26 )
{
T_3 V_50 ;
T_1 * V_68 = F_60 ( V_7 , V_26 ) ;
int V_93 = 1 ;
if ( ! * V_68 )
return 0 ;
if ( F_69 ( * V_68 ) ) {
int V_47 ;
T_1 * V_66 = F_58 ( V_68 , V_26 ) ;
V_50 = V_94 ;
if ( * V_66 & V_85 ) {
V_93 *= 16 ;
V_66 = F_58 ( V_68 , ( V_26 & V_83 ) ) ;
}
V_50 *= V_93 ;
memset ( V_66 , 0 , V_93 * sizeof( * V_66 ) ) ;
F_48 ( V_66 , V_66 + ( V_93 - 1 ) * sizeof( * V_66 ) ) ;
V_66 = F_58 ( V_68 , 0 ) ;
for ( V_47 = 0 ; V_47 < V_95 ; V_47 ++ )
if ( V_66 [ V_47 ] )
goto V_45;
F_49 ( V_66 ) ;
V_93 = 1 ;
} else {
V_50 = V_96 ;
if ( ( * V_68 & V_80 ) == V_80 ) {
V_93 *= 16 ;
V_68 = F_60 ( V_7 , ( V_26 & V_78 ) ) ;
}
V_50 *= V_93 ;
}
memset ( V_68 , 0 , V_93 * sizeof( * V_68 ) ) ;
F_47 ( V_68 , V_68 + ( V_93 - 1 ) * sizeof( * V_68 ) ) ;
V_45:
return V_50 ;
}
static T_3 F_71 ( struct V_6 * V_7 , T_1 V_26 )
{
T_3 V_50 ;
F_54 ( & V_7 -> V_70 ) ;
V_50 = F_70 ( V_7 , V_26 ) ;
F_36 ( V_7 , V_26 ) ;
F_52 ( & V_7 -> V_70 ) ;
return V_50 ;
}
static void F_72 ( struct V_6 * V_7 )
{
int V_47 ;
F_54 ( & V_7 -> V_70 ) ;
for ( V_47 = 0 ; V_47 < V_97 ; V_47 ++ ) {
T_1 V_26 ;
T_1 * V_68 ;
V_26 = V_47 << V_98 ;
V_68 = F_60 ( V_7 , V_26 ) ;
if ( ! * V_68 )
continue;
if ( F_69 ( * V_68 ) )
F_49 ( F_58 ( V_68 , 0 ) ) ;
* V_68 = 0 ;
F_47 ( V_68 , V_68 ) ;
}
F_38 ( V_7 ) ;
F_52 ( & V_7 -> V_70 ) ;
}
static T_4 F_73 ( int V_99 , void * V_59 )
{
T_1 V_26 , V_100 ;
T_1 * V_68 , * V_66 ;
struct V_6 * V_7 = V_59 ;
struct V_101 * V_102 = V_7 -> V_102 ;
if ( ! V_7 -> V_103 )
return V_104 ;
F_8 ( V_7 -> V_14 ) ;
V_100 = F_17 ( V_7 , & V_26 ) ;
F_9 ( V_7 -> V_14 ) ;
if ( V_100 == 0 )
return V_105 ;
if ( ! F_74 ( V_102 , V_7 -> V_44 , V_26 , 0 ) )
return V_105 ;
F_10 ( V_7 ) ;
V_68 = F_60 ( V_7 , V_26 ) ;
if ( ! F_69 ( * V_68 ) ) {
F_61 ( V_7 -> V_44 , L_10
L_11 , V_7 -> V_106 , V_100 , V_26 , V_68 , * V_68 ) ;
return V_104 ;
}
V_66 = F_58 ( V_68 , V_26 ) ;
F_61 ( V_7 -> V_44 , L_12
L_13 , V_7 -> V_106 , V_100 , V_26 , V_68 , * V_68 ,
V_66 , * V_66 ) ;
return V_104 ;
}
static int F_75 ( struct V_60 * V_44 , void * V_59 )
{
struct V_6 * V_7 = F_76 ( V_44 ) ;
const char * V_106 = V_59 ;
F_77 ( L_14 , V_5 , V_7 -> V_106 , V_106 ) ;
return strcmp ( V_7 -> V_106 , V_106 ) == 0 ;
}
struct V_60 * F_78 ( const char * V_106 )
{
return F_79 ( & V_61 . V_62 , NULL ,
( void * ) V_106 ,
F_75 ) ;
}
static struct V_6 * F_80 ( struct V_60 * V_44 , T_1 * V_68 )
{
int V_11 = - V_71 ;
struct V_6 * V_7 = F_76 ( V_44 ) ;
F_54 ( & V_7 -> V_107 ) ;
if ( ++ V_7 -> V_103 > 1 ) {
F_61 ( V_44 , L_15 , V_7 -> V_106 ) ;
V_11 = - V_4 ;
goto V_108;
}
V_7 -> V_68 = V_68 ;
V_11 = F_7 ( V_7 ) ;
if ( V_11 )
goto V_108;
F_38 ( V_7 ) ;
if ( ! F_81 ( V_7 -> V_109 ) )
goto V_110;
F_52 ( & V_7 -> V_107 ) ;
F_31 ( V_7 -> V_44 , L_16 , V_5 , V_7 -> V_106 ) ;
return V_7 ;
V_110:
if ( V_7 -> V_103 == 1 )
F_10 ( V_7 ) ;
V_108:
V_7 -> V_103 -- ;
F_52 ( & V_7 -> V_107 ) ;
return F_55 ( V_11 ) ;
}
static void F_82 ( struct V_6 * V_7 )
{
if ( ! V_7 || F_32 ( V_7 ) )
return;
F_54 ( & V_7 -> V_107 ) ;
if ( -- V_7 -> V_103 == 0 )
F_10 ( V_7 ) ;
F_83 ( V_7 -> V_109 ) ;
V_7 -> V_68 = NULL ;
F_52 ( & V_7 -> V_107 ) ;
F_31 ( V_7 -> V_44 , L_16 , V_5 , V_7 -> V_106 ) ;
}
static int T_5 F_84 ( struct V_111 * V_112 )
{
int V_11 = - V_13 ;
int V_99 ;
struct V_6 * V_7 ;
struct V_113 * V_114 ;
struct V_115 * V_116 = V_112 -> V_44 . V_117 ;
if ( V_112 -> V_118 != 2 )
return - V_12 ;
V_7 = F_85 ( sizeof( * V_7 ) + V_119 , V_58 ) ;
if ( ! V_7 )
return - V_71 ;
V_7 -> V_14 = F_86 ( & V_112 -> V_44 , V_116 -> V_120 ) ;
if ( F_32 ( V_7 -> V_14 ) )
goto V_121;
V_7 -> V_43 = V_116 -> V_43 ;
V_7 -> V_106 = V_116 -> V_106 ;
V_7 -> V_44 = & V_112 -> V_44 ;
V_7 -> V_122 = ( void * ) V_7 + sizeof( * V_7 ) ;
V_7 -> V_123 = V_116 -> V_123 ;
V_7 -> V_124 = V_116 -> V_124 ;
F_87 ( & V_7 -> V_107 ) ;
F_88 ( & V_7 -> V_125 ) ;
F_87 ( & V_7 -> V_70 ) ;
F_89 ( & V_7 -> V_126 ) ;
V_114 = F_90 ( V_112 , V_127 , 0 ) ;
if ( ! V_114 ) {
V_11 = - V_13 ;
goto V_128;
}
V_114 = F_91 ( V_114 -> V_49 , F_92 ( V_114 ) ,
F_93 ( & V_112 -> V_44 ) ) ;
if ( ! V_114 ) {
V_11 = - V_129 ;
goto V_128;
}
V_7 -> V_130 = F_94 ( V_114 -> V_49 , F_92 ( V_114 ) ) ;
if ( ! V_7 -> V_130 ) {
V_11 = - V_71 ;
goto V_131;
}
V_99 = F_95 ( V_112 , 0 ) ;
if ( V_99 < 0 ) {
V_11 = - V_13 ;
goto V_132;
}
V_11 = F_96 ( V_99 , F_73 , V_133 ,
F_93 ( & V_112 -> V_44 ) , V_7 ) ;
if ( V_11 < 0 )
goto V_132;
F_97 ( V_112 , V_7 ) ;
F_98 ( & V_112 -> V_44 , L_17 , V_7 -> V_106 ) ;
return 0 ;
V_132:
F_99 ( V_7 -> V_130 ) ;
V_131:
F_100 ( V_114 -> V_49 , F_92 ( V_114 ) ) ;
V_128:
F_101 ( V_7 -> V_14 ) ;
V_121:
F_34 ( V_7 ) ;
return V_11 ;
}
static int T_6 F_102 ( struct V_111 * V_112 )
{
int V_99 ;
struct V_113 * V_114 ;
struct V_6 * V_7 = F_103 ( V_112 ) ;
F_97 ( V_112 , NULL ) ;
F_72 ( V_7 ) ;
V_99 = F_95 ( V_112 , 0 ) ;
F_104 ( V_99 , V_7 ) ;
V_114 = F_90 ( V_112 , V_127 , 0 ) ;
F_100 ( V_114 -> V_49 , F_92 ( V_114 ) ) ;
F_99 ( V_7 -> V_130 ) ;
F_101 ( V_7 -> V_14 ) ;
F_98 ( & V_112 -> V_44 , L_18 , V_7 -> V_106 ) ;
F_34 ( V_7 ) ;
return 0 ;
}
static void F_105 ( void * V_66 )
{
F_106 ( V_66 , V_134 ) ;
}
static int F_107 ( struct V_101 * V_102 , unsigned long V_26 ,
T_7 V_73 , int V_135 , int V_74 )
{
struct V_136 * V_137 = V_102 -> V_138 ;
struct V_6 * V_139 = V_137 -> V_140 ;
struct V_60 * V_44 = V_139 -> V_44 ;
T_3 V_50 = V_141 << V_135 ;
struct V_19 V_20 ;
int V_142 ;
T_1 V_143 , V_144 ;
V_142 = F_108 ( V_50 ) ;
if ( V_142 < 0 ) {
F_61 ( V_44 , L_19 , V_50 ) ;
return - V_12 ;
}
F_31 ( V_44 , L_20 , V_26 , V_73 , V_50 ) ;
V_144 = V_142 | V_74 ;
F_109 ( & V_20 , V_26 , V_73 , V_144 ) ;
V_143 = F_67 ( V_139 , & V_20 ) ;
if ( V_143 )
F_61 ( V_44 , L_21 , V_143 ) ;
return V_143 ;
}
static int F_110 ( struct V_101 * V_102 , unsigned long V_26 ,
int V_135 )
{
struct V_136 * V_137 = V_102 -> V_138 ;
struct V_6 * V_139 = V_137 -> V_140 ;
struct V_60 * V_44 = V_139 -> V_44 ;
T_3 V_145 ;
F_31 ( V_44 , L_22 , V_26 , V_135 ) ;
V_145 = F_71 ( V_139 , V_26 ) ;
return V_145 ? F_111 ( V_145 ) : - V_12 ;
}
static int
F_112 ( struct V_101 * V_102 , struct V_60 * V_44 )
{
struct V_136 * V_137 = V_102 -> V_138 ;
struct V_6 * V_139 ;
int V_143 = 0 ;
F_54 ( & V_137 -> V_146 ) ;
if ( V_137 -> V_140 ) {
F_61 ( V_44 , L_23 ) ;
V_143 = - V_4 ;
goto V_45;
}
V_139 = F_80 ( V_44 , V_137 -> V_147 ) ;
if ( F_32 ( V_139 ) ) {
V_143 = F_33 ( V_139 ) ;
F_61 ( V_44 , L_24 , V_143 ) ;
goto V_45;
}
V_137 -> V_140 = V_139 ;
V_139 -> V_102 = V_102 ;
V_45:
F_52 ( & V_137 -> V_146 ) ;
return V_143 ;
}
static void F_113 ( struct V_101 * V_102 ,
struct V_60 * V_44 )
{
struct V_136 * V_137 = V_102 -> V_138 ;
struct V_6 * V_139 = F_76 ( V_44 ) ;
F_54 ( & V_137 -> V_146 ) ;
if ( V_137 -> V_140 != V_139 ) {
F_61 ( V_44 , L_25 ) ;
goto V_45;
}
F_72 ( V_139 ) ;
F_82 ( V_139 ) ;
V_137 -> V_140 = NULL ;
V_45:
F_52 ( & V_137 -> V_146 ) ;
}
static int F_114 ( struct V_101 * V_102 )
{
struct V_136 * V_137 ;
V_137 = F_85 ( sizeof( * V_137 ) , V_58 ) ;
if ( ! V_137 ) {
F_3 ( L_26 ) ;
goto V_45;
}
V_137 -> V_147 = F_85 ( V_148 , V_58 ) ;
if ( ! V_137 -> V_147 ) {
F_3 ( L_26 ) ;
goto V_149;
}
F_12 ( ! F_115 ( ( long ) V_137 -> V_147 , V_148 ) ) ;
F_106 ( V_137 -> V_147 , V_148 ) ;
F_87 ( & V_137 -> V_146 ) ;
V_102 -> V_138 = V_137 ;
return 0 ;
V_149:
F_34 ( V_137 ) ;
V_45:
return - V_71 ;
}
static void F_116 ( struct V_101 * V_102 )
{
struct V_136 * V_137 = V_102 -> V_138 ;
V_102 -> V_138 = NULL ;
F_34 ( V_137 -> V_147 ) ;
F_34 ( V_137 ) ;
}
static T_7 F_117 ( struct V_101 * V_102 ,
unsigned long V_26 )
{
struct V_136 * V_137 = V_102 -> V_138 ;
struct V_6 * V_139 = V_137 -> V_140 ;
struct V_60 * V_44 = V_139 -> V_44 ;
T_1 * V_150 , * V_151 ;
T_7 V_143 = 0 ;
F_68 ( V_139 , V_26 , & V_150 , & V_151 ) ;
if ( V_151 ) {
if ( F_118 ( * V_151 ) )
V_143 = F_119 ( * V_151 , V_26 , V_152 ) ;
else if ( F_120 ( * V_151 ) )
V_143 = F_119 ( * V_151 , V_26 , V_83 ) ;
else
F_61 ( V_44 , L_27 , * V_151 ) ;
} else {
if ( F_121 ( * V_150 ) )
V_143 = F_119 ( * V_150 , V_26 , V_75 ) ;
else if ( F_122 ( * V_150 ) )
V_143 = F_119 ( * V_150 , V_26 , V_78 ) ;
else
F_61 ( V_44 , L_28 , * V_150 ) ;
}
return V_143 ;
}
static int F_123 ( struct V_101 * V_102 ,
unsigned long V_153 )
{
return 0 ;
}
static int T_8 F_124 ( void )
{
struct V_154 * V_57 ;
const unsigned long V_144 = V_155 ;
T_3 V_156 = 1 << 10 ;
V_57 = F_125 ( L_29 , V_134 , V_156 , V_144 ,
F_105 ) ;
if ( ! V_57 )
return - V_71 ;
V_67 = V_57 ;
F_126 ( & V_157 , & V_158 ) ;
return F_127 ( & V_61 ) ;
}
static void T_9 F_128 ( void )
{
F_129 ( V_67 ) ;
F_130 ( & V_61 ) ;
}
