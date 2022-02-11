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
struct V_14 * V_15 = F_9 ( V_9 -> V_7 ) ;
struct V_16 * V_17 = V_15 -> V_7 . V_18 ;
if ( ! V_17 )
return - V_19 ;
if ( ! V_3 )
return - V_20 ;
if ( V_17 -> V_21 ) {
V_13 = V_17 -> V_21 ( V_15 , V_17 -> V_22 ) ;
if ( V_13 ) {
F_10 ( V_9 -> V_7 , L_2 , V_13 ) ;
return V_13 ;
}
}
F_11 ( V_9 -> V_7 ) ;
V_13 = V_3 -> V_23 ( V_9 ) ;
return V_13 ;
}
static void F_12 ( struct V_8 * V_9 )
{
struct V_14 * V_15 = F_9 ( V_9 -> V_7 ) ;
struct V_16 * V_17 = V_15 -> V_7 . V_18 ;
if ( ! V_17 )
return;
V_3 -> V_24 ( V_9 ) ;
F_13 ( V_9 -> V_7 ) ;
if ( V_17 -> V_25 )
V_17 -> V_25 ( V_15 , V_17 -> V_22 ) ;
}
void F_14 ( struct V_26 * V_27 , struct V_28 * V_29 )
{
F_15 ( ! V_27 || ! V_29 ) ;
V_3 -> V_30 ( V_27 , V_29 ) ;
}
static inline int F_16 ( struct V_26 * V_27 )
{
if ( ! V_27 )
return - V_19 ;
return V_3 -> V_31 ( V_27 ) ;
}
static inline struct V_26 * F_17 ( struct V_8 * V_9 ,
struct V_28 * V_29 )
{
if ( ! V_29 )
return NULL ;
return V_3 -> V_32 ( V_9 , V_29 ) ;
}
static T_1 F_18 ( struct V_26 * V_27 )
{
return V_3 -> V_33 ( V_27 ) ;
}
static T_1 F_19 ( struct V_28 * V_29 )
{
return V_3 -> V_34 ( V_29 ) ;
}
static T_1 F_20 ( struct V_8 * V_9 , T_1 * V_35 )
{
return V_3 -> V_36 ( V_9 , V_35 ) ;
}
static void F_21 ( struct V_8 * V_9 , struct V_37 * V_38 )
{
T_1 V_39 ;
V_39 = F_22 ( V_9 , V_40 ) ;
V_38 -> V_41 = F_23 ( V_39 ) ;
V_38 -> V_42 = F_24 ( V_39 ) ;
}
static void F_25 ( struct V_8 * V_9 , struct V_37 * V_38 )
{
T_1 V_39 ;
V_39 = ( V_38 -> V_41 << V_43 ) ;
V_39 |= ( V_38 -> V_42 << V_44 ) ;
F_26 ( V_9 , V_39 , V_40 ) ;
}
static void F_27 ( struct V_8 * V_9 , struct V_26 * V_27 )
{
V_3 -> V_45 ( V_9 , V_27 ) ;
}
static void F_28 ( struct V_8 * V_9 , struct V_26 * V_27 )
{
V_3 -> V_46 ( V_9 , V_27 ) ;
F_26 ( V_9 , 1 , V_47 ) ;
F_26 ( V_9 , 1 , V_48 ) ;
}
static inline T_2 F_29 ( struct V_8 * V_9 , struct V_26 * V_27 ,
char * V_49 )
{
F_15 ( ! V_27 || ! V_49 ) ;
return V_3 -> V_50 ( V_9 , V_27 , V_49 ) ;
}
static struct V_26 F_30 ( struct V_8 * V_9 , int V_51 )
{
struct V_26 V_27 ;
struct V_37 V_38 ;
F_21 ( V_9 , & V_38 ) ;
V_38 . V_42 = V_51 ;
F_25 ( V_9 , & V_38 ) ;
F_27 ( V_9 , & V_27 ) ;
return V_27 ;
}
static int F_31 ( struct V_8 * V_9 , struct V_28 * V_29 )
{
int V_13 = 0 ;
struct V_37 V_38 ;
struct V_26 * V_27 ;
if ( ! V_9 || ! V_9 -> V_52 || ! V_29 )
return - V_19 ;
F_11 ( V_9 -> V_7 ) ;
F_21 ( V_9 , & V_38 ) ;
if ( V_38 . V_41 == V_9 -> V_52 ) {
F_32 ( V_9 -> V_7 , L_3 , V_5 ) ;
V_13 = - V_4 ;
goto V_53;
}
if ( ! V_29 -> V_54 ) {
int V_55 ;
struct V_26 V_56 ;
F_33 (obj, obj->nr_tlb_entries, i, tmp)
if ( ! F_16 ( & V_56 ) )
break;
if ( V_55 == V_9 -> V_52 ) {
F_34 ( V_9 -> V_7 , L_4 , V_5 ) ;
V_13 = - V_4 ;
goto V_53;
}
F_21 ( V_9 , & V_38 ) ;
} else {
V_38 . V_42 = V_38 . V_41 ;
F_25 ( V_9 , & V_38 ) ;
}
V_27 = F_17 ( V_9 , V_29 ) ;
if ( F_35 ( V_27 ) ) {
F_13 ( V_9 -> V_7 ) ;
return F_36 ( V_27 ) ;
}
F_28 ( V_9 , V_27 ) ;
F_37 ( V_27 ) ;
if ( V_29 -> V_54 )
V_38 . V_41 ++ ;
if ( ++ V_38 . V_42 == V_9 -> V_52 )
V_38 . V_42 = V_38 . V_41 ;
F_25 ( V_9 , & V_38 ) ;
V_53:
F_13 ( V_9 -> V_7 ) ;
return V_13 ;
}
static int F_31 ( struct V_8 * V_9 , struct V_28 * V_29 )
{
return 0 ;
}
static int F_38 ( struct V_8 * V_9 , struct V_28 * V_29 )
{
return F_31 ( V_9 , V_29 ) ;
}
static void F_39 ( struct V_8 * V_9 , T_1 V_35 )
{
int V_55 ;
struct V_26 V_27 ;
F_11 ( V_9 -> V_7 ) ;
F_33 (obj, obj->nr_tlb_entries, i, cr) {
T_1 V_57 ;
T_3 V_58 ;
if ( ! F_16 ( & V_27 ) )
continue;
V_57 = F_18 ( & V_27 ) ;
V_58 = F_40 ( V_27 . V_59 & 3 ) ;
if ( ( V_57 <= V_35 ) && ( V_35 < V_57 + V_58 ) ) {
F_34 ( V_9 -> V_7 , L_5 ,
V_5 , V_57 , V_35 , V_58 ) ;
F_28 ( V_9 , & V_27 ) ;
F_26 ( V_9 , 1 , V_47 ) ;
}
}
F_13 ( V_9 -> V_7 ) ;
if ( V_55 == V_9 -> V_52 )
F_34 ( V_9 -> V_7 , L_6 , V_5 , V_35 ) ;
}
static void F_41 ( struct V_8 * V_9 )
{
struct V_37 V_38 ;
F_11 ( V_9 -> V_7 ) ;
V_38 . V_41 = 0 ;
V_38 . V_42 = 0 ;
F_25 ( V_9 , & V_38 ) ;
F_26 ( V_9 , 1 , V_60 ) ;
F_13 ( V_9 -> V_7 ) ;
}
T_2 F_42 ( struct V_8 * V_9 , char * V_49 , T_2 V_58 )
{
if ( ! V_9 || ! V_49 )
return - V_19 ;
F_11 ( V_9 -> V_7 ) ;
V_58 = V_3 -> V_61 ( V_9 , V_49 , V_58 ) ;
F_13 ( V_9 -> V_7 ) ;
return V_58 ;
}
static int
F_43 ( struct V_8 * V_9 , struct V_26 * V_62 , int V_63 )
{
int V_55 ;
struct V_37 V_64 ;
struct V_26 V_56 ;
struct V_26 * V_65 = V_62 ;
F_11 ( V_9 -> V_7 ) ;
F_21 ( V_9 , & V_64 ) ;
F_33 (obj, num, i, tmp) {
if ( ! F_16 ( & V_56 ) )
continue;
* V_65 ++ = V_56 ;
}
F_25 ( V_9 , & V_64 ) ;
F_13 ( V_9 -> V_7 ) ;
return V_65 - V_62 ;
}
T_3 F_44 ( struct V_8 * V_9 , char * V_49 , T_2 V_58 )
{
int V_55 , V_63 ;
struct V_26 * V_27 ;
char * V_65 = V_49 ;
V_63 = V_58 / sizeof( * V_27 ) ;
V_63 = F_45 ( V_9 -> V_52 , V_63 ) ;
V_27 = F_46 ( V_63 , sizeof( * V_27 ) , V_66 ) ;
if ( ! V_27 )
return 0 ;
V_63 = F_43 ( V_9 , V_27 , V_63 ) ;
for ( V_55 = 0 ; V_55 < V_63 ; V_55 ++ )
V_65 += F_29 ( V_9 , V_27 + V_55 , V_65 ) ;
F_37 ( V_27 ) ;
return V_65 - V_49 ;
}
int F_47 ( void * V_67 , int (* F_48)( struct V_6 * , void * ) )
{
return F_49 ( & V_68 . V_69 ,
NULL , V_67 , F_48 ) ;
}
static void F_50 ( T_1 * V_70 , T_1 * V_71 )
{
do {
asm("mcr p15, 0, %0, c7, c10, 1 @ flush_pgd"
: : "r" (first));
V_70 += V_72 / sizeof( * V_70 ) ;
} while ( V_70 <= V_71 );
}
static void F_51 ( T_1 * V_70 , T_1 * V_71 )
{
do {
asm("mcr p15, 0, %0, c7, c10, 1 @ flush_pte"
: : "r" (first));
V_70 += V_72 / sizeof( * V_70 ) ;
} while ( V_70 <= V_71 );
}
static void F_52 ( T_1 * V_73 )
{
F_53 ( V_74 , V_73 ) ;
}
static T_1 * F_54 ( struct V_8 * V_9 , T_1 * V_75 , T_1 V_35 )
{
T_1 * V_73 ;
if ( * V_75 )
goto V_76;
F_55 ( & V_9 -> V_77 ) ;
V_73 = F_56 ( V_74 , V_66 ) ;
F_57 ( & V_9 -> V_77 ) ;
if ( ! * V_75 ) {
if ( ! V_73 )
return F_58 ( - V_78 ) ;
* V_75 = F_59 ( V_73 ) | V_79 ;
F_50 ( V_75 , V_75 ) ;
F_60 ( V_9 -> V_7 , L_7 , V_5 , V_73 ) ;
} else {
F_52 ( V_73 ) ;
}
V_76:
V_73 = F_61 ( V_75 , V_35 ) ;
F_60 ( V_9 -> V_7 ,
L_8 ,
V_5 , V_35 , V_75 , * V_75 , V_73 , * V_73 ) ;
return V_73 ;
}
static int F_62 ( struct V_8 * V_9 , T_1 V_35 , T_1 V_80 , T_1 V_81 )
{
T_1 * V_75 = F_63 ( V_9 , V_35 ) ;
if ( ( V_35 | V_80 ) & ~ V_82 ) {
F_10 ( V_9 -> V_7 , L_9 ,
V_5 , V_35 , V_80 , V_83 ) ;
return - V_19 ;
}
* V_75 = ( V_80 & V_82 ) | V_81 | V_84 ;
F_50 ( V_75 , V_75 ) ;
return 0 ;
}
static int F_64 ( struct V_8 * V_9 , T_1 V_35 , T_1 V_80 , T_1 V_81 )
{
T_1 * V_75 = F_63 ( V_9 , V_35 ) ;
int V_55 ;
if ( ( V_35 | V_80 ) & ~ V_85 ) {
F_10 ( V_9 -> V_7 , L_9 ,
V_5 , V_35 , V_80 , V_86 ) ;
return - V_19 ;
}
for ( V_55 = 0 ; V_55 < 16 ; V_55 ++ )
* ( V_75 + V_55 ) = ( V_80 & V_85 ) | V_81 | V_87 ;
F_50 ( V_75 , V_75 + 15 ) ;
return 0 ;
}
static int F_65 ( struct V_8 * V_9 , T_1 V_35 , T_1 V_80 , T_1 V_81 )
{
T_1 * V_75 = F_63 ( V_9 , V_35 ) ;
T_1 * V_73 = F_54 ( V_9 , V_75 , V_35 ) ;
if ( F_35 ( V_73 ) )
return F_36 ( V_73 ) ;
* V_73 = ( V_80 & V_88 ) | V_81 | V_89 ;
F_51 ( V_73 , V_73 ) ;
F_60 ( V_9 -> V_7 , L_10 ,
V_5 , V_35 , V_80 , V_73 , * V_73 ) ;
return 0 ;
}
static int F_66 ( struct V_8 * V_9 , T_1 V_35 , T_1 V_80 , T_1 V_81 )
{
T_1 * V_75 = F_63 ( V_9 , V_35 ) ;
T_1 * V_73 = F_54 ( V_9 , V_75 , V_35 ) ;
int V_55 ;
if ( ( V_35 | V_80 ) & ~ V_90 ) {
F_10 ( V_9 -> V_7 , L_9 ,
V_5 , V_35 , V_80 , V_91 ) ;
return - V_19 ;
}
if ( F_35 ( V_73 ) )
return F_36 ( V_73 ) ;
for ( V_55 = 0 ; V_55 < 16 ; V_55 ++ )
* ( V_73 + V_55 ) = ( V_80 & V_90 ) | V_81 | V_92 ;
F_51 ( V_73 , V_73 + 15 ) ;
return 0 ;
}
static int
F_67 ( struct V_8 * V_9 , struct V_28 * V_29 )
{
int (* F_48)( struct V_8 * , T_1 , T_1 , T_1 );
T_1 V_81 ;
int V_13 ;
if ( ! V_9 || ! V_29 )
return - V_19 ;
switch ( V_29 -> V_93 ) {
case V_94 :
F_48 = F_64 ;
break;
case V_95 :
F_48 = F_62 ;
break;
case V_96 :
F_48 = F_66 ;
break;
case V_97 :
F_48 = F_65 ;
break;
default:
F_48 = NULL ;
F_68 () ;
break;
}
V_81 = F_19 ( V_29 ) ;
F_57 ( & V_9 -> V_77 ) ;
V_13 = F_48 ( V_9 , V_29 -> V_35 , V_29 -> V_80 , V_81 ) ;
F_55 ( & V_9 -> V_77 ) ;
return V_13 ;
}
int F_69 ( struct V_8 * V_9 , struct V_28 * V_29 )
{
int V_13 ;
F_39 ( V_9 , V_29 -> V_35 ) ;
V_13 = F_67 ( V_9 , V_29 ) ;
if ( ! V_13 )
F_38 ( V_9 , V_29 ) ;
return V_13 ;
}
static void
F_70 ( struct V_8 * V_9 , T_1 V_35 , T_1 * * V_98 , T_1 * * V_99 )
{
T_1 * V_75 , * V_73 = NULL ;
V_75 = F_63 ( V_9 , V_35 ) ;
if ( ! * V_75 )
goto V_53;
if ( F_71 ( * V_75 ) )
V_73 = F_61 ( V_75 , V_35 ) ;
V_53:
* V_98 = V_75 ;
* V_99 = V_73 ;
}
static T_3 F_72 ( struct V_8 * V_9 , T_1 V_35 )
{
T_3 V_58 ;
T_1 * V_75 = F_63 ( V_9 , V_35 ) ;
int V_100 = 1 ;
if ( ! * V_75 )
return 0 ;
if ( F_71 ( * V_75 ) ) {
int V_55 ;
T_1 * V_73 = F_61 ( V_75 , V_35 ) ;
V_58 = V_101 ;
if ( * V_73 & V_92 ) {
V_100 *= 16 ;
V_73 = F_61 ( V_75 , ( V_35 & V_90 ) ) ;
}
V_58 *= V_100 ;
memset ( V_73 , 0 , V_100 * sizeof( * V_73 ) ) ;
F_51 ( V_73 , V_73 + ( V_100 - 1 ) * sizeof( * V_73 ) ) ;
V_73 = F_61 ( V_75 , 0 ) ;
for ( V_55 = 0 ; V_55 < V_102 ; V_55 ++ )
if ( V_73 [ V_55 ] )
goto V_53;
F_52 ( V_73 ) ;
V_100 = 1 ;
} else {
V_58 = V_103 ;
if ( ( * V_75 & V_87 ) == V_87 ) {
V_100 *= 16 ;
V_75 = F_63 ( V_9 , ( V_35 & V_85 ) ) ;
}
V_58 *= V_100 ;
}
memset ( V_75 , 0 , V_100 * sizeof( * V_75 ) ) ;
F_50 ( V_75 , V_75 + ( V_100 - 1 ) * sizeof( * V_75 ) ) ;
V_53:
return V_58 ;
}
static T_3 F_73 ( struct V_8 * V_9 , T_1 V_35 )
{
T_3 V_58 ;
F_57 ( & V_9 -> V_77 ) ;
V_58 = F_72 ( V_9 , V_35 ) ;
F_39 ( V_9 , V_35 ) ;
F_55 ( & V_9 -> V_77 ) ;
return V_58 ;
}
static void F_74 ( struct V_8 * V_9 )
{
int V_55 ;
F_57 ( & V_9 -> V_77 ) ;
for ( V_55 = 0 ; V_55 < V_104 ; V_55 ++ ) {
T_1 V_35 ;
T_1 * V_75 ;
V_35 = V_55 << V_105 ;
V_75 = F_63 ( V_9 , V_35 ) ;
if ( ! * V_75 )
continue;
if ( F_71 ( * V_75 ) )
F_52 ( F_61 ( V_75 , 0 ) ) ;
* V_75 = 0 ;
F_50 ( V_75 , V_75 ) ;
}
F_41 ( V_9 ) ;
F_55 ( & V_9 -> V_77 ) ;
}
static T_4 F_75 ( int V_106 , void * V_67 )
{
T_1 V_35 , V_107 ;
T_1 * V_75 , * V_73 ;
struct V_8 * V_9 = V_67 ;
struct V_108 * V_109 = V_9 -> V_109 ;
if ( ! V_9 -> V_110 )
return V_111 ;
V_107 = F_20 ( V_9 , & V_35 ) ;
if ( V_107 == 0 )
return V_112 ;
if ( ! F_76 ( V_109 , V_9 -> V_7 , V_35 , 0 ) )
return V_112 ;
F_12 ( V_9 ) ;
V_75 = F_63 ( V_9 , V_35 ) ;
if ( ! F_71 ( * V_75 ) ) {
F_10 ( V_9 -> V_7 , L_11
L_12 , V_9 -> V_113 , V_107 , V_35 , V_75 , * V_75 ) ;
return V_111 ;
}
V_73 = F_61 ( V_75 , V_35 ) ;
F_10 ( V_9 -> V_7 , L_13
L_14 , V_9 -> V_113 , V_107 , V_35 , V_75 , * V_75 ,
V_73 , * V_73 ) ;
return V_111 ;
}
static int F_77 ( struct V_6 * V_7 , void * V_67 )
{
struct V_8 * V_9 = F_78 ( V_7 ) ;
const char * V_113 = V_67 ;
F_79 ( L_15 , V_5 , V_9 -> V_113 , V_113 ) ;
return strcmp ( V_9 -> V_113 , V_113 ) == 0 ;
}
static struct V_8 * F_80 ( const char * V_113 , T_1 * V_75 )
{
int V_13 = - V_78 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
V_7 = F_81 ( & V_68 . V_69 , NULL ,
( void * ) V_113 ,
F_77 ) ;
if ( ! V_7 )
return NULL ;
V_9 = F_78 ( V_7 ) ;
F_57 ( & V_9 -> V_114 ) ;
if ( ++ V_9 -> V_110 > 1 ) {
F_10 ( V_7 , L_16 , V_9 -> V_113 ) ;
V_13 = - V_4 ;
goto V_115;
}
V_9 -> V_75 = V_75 ;
V_13 = F_8 ( V_9 ) ;
if ( V_13 )
goto V_115;
F_41 ( V_9 ) ;
if ( ! F_82 ( V_9 -> V_116 ) )
goto V_117;
F_55 ( & V_9 -> V_114 ) ;
F_34 ( V_9 -> V_7 , L_17 , V_5 , V_9 -> V_113 ) ;
return V_9 ;
V_117:
if ( V_9 -> V_110 == 1 )
F_12 ( V_9 ) ;
V_115:
V_9 -> V_110 -- ;
F_55 ( & V_9 -> V_114 ) ;
return F_58 ( V_13 ) ;
}
static void F_83 ( struct V_8 * V_9 )
{
if ( ! V_9 || F_35 ( V_9 ) )
return;
F_57 ( & V_9 -> V_114 ) ;
if ( -- V_9 -> V_110 == 0 )
F_12 ( V_9 ) ;
F_84 ( V_9 -> V_116 ) ;
V_9 -> V_75 = NULL ;
F_55 ( & V_9 -> V_114 ) ;
F_34 ( V_9 -> V_7 , L_17 , V_5 , V_9 -> V_113 ) ;
}
static int F_85 ( struct V_14 * V_15 )
{
int V_13 = - V_20 ;
int V_106 ;
struct V_8 * V_9 ;
struct V_118 * V_119 ;
struct V_16 * V_17 = V_15 -> V_7 . V_18 ;
V_9 = F_86 ( sizeof( * V_9 ) + V_120 , V_66 ) ;
if ( ! V_9 )
return - V_78 ;
V_9 -> V_52 = V_17 -> V_52 ;
V_9 -> V_113 = V_17 -> V_113 ;
V_9 -> V_7 = & V_15 -> V_7 ;
V_9 -> V_121 = ( void * ) V_9 + sizeof( * V_9 ) ;
V_9 -> V_122 = V_17 -> V_122 ;
V_9 -> V_123 = V_17 -> V_123 ;
F_87 ( & V_9 -> V_114 ) ;
F_88 ( & V_9 -> V_124 ) ;
F_87 ( & V_9 -> V_77 ) ;
F_89 ( & V_9 -> V_125 ) ;
V_119 = F_90 ( V_15 , V_126 , 0 ) ;
if ( ! V_119 ) {
V_13 = - V_20 ;
goto V_127;
}
V_119 = F_91 ( V_119 -> V_57 , F_92 ( V_119 ) ,
F_93 ( & V_15 -> V_7 ) ) ;
if ( ! V_119 ) {
V_13 = - V_128 ;
goto V_127;
}
V_9 -> V_129 = F_94 ( V_119 -> V_57 , F_92 ( V_119 ) ) ;
if ( ! V_9 -> V_129 ) {
V_13 = - V_78 ;
goto V_130;
}
V_106 = F_95 ( V_15 , 0 ) ;
if ( V_106 < 0 ) {
V_13 = - V_20 ;
goto V_131;
}
V_13 = F_96 ( V_106 , F_75 , V_132 ,
F_93 ( & V_15 -> V_7 ) , V_9 ) ;
if ( V_13 < 0 )
goto V_131;
F_97 ( V_15 , V_9 ) ;
F_98 ( V_9 -> V_7 ) ;
F_99 ( V_9 -> V_7 ) ;
F_100 ( & V_15 -> V_7 , L_18 , V_9 -> V_113 ) ;
return 0 ;
V_131:
F_101 ( V_9 -> V_129 ) ;
V_130:
F_102 ( V_119 -> V_57 , F_92 ( V_119 ) ) ;
V_127:
F_37 ( V_9 ) ;
return V_13 ;
}
static int F_103 ( struct V_14 * V_15 )
{
int V_106 ;
struct V_118 * V_119 ;
struct V_8 * V_9 = F_104 ( V_15 ) ;
F_97 ( V_15 , NULL ) ;
F_74 ( V_9 ) ;
V_106 = F_95 ( V_15 , 0 ) ;
F_105 ( V_106 , V_9 ) ;
V_119 = F_90 ( V_15 , V_126 , 0 ) ;
F_102 ( V_119 -> V_57 , F_92 ( V_119 ) ) ;
F_101 ( V_9 -> V_129 ) ;
F_106 ( V_9 -> V_7 ) ;
F_100 ( & V_15 -> V_7 , L_19 , V_9 -> V_113 ) ;
F_37 ( V_9 ) ;
return 0 ;
}
static void F_107 ( void * V_73 )
{
F_108 ( V_73 , V_133 ) ;
}
static T_1 F_109 ( struct V_28 * V_29 , T_1 V_35 , T_1 V_80 ,
T_1 V_134 )
{
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_29 -> V_35 = V_35 ;
V_29 -> V_80 = V_80 ;
V_29 -> V_135 = 1 ;
V_29 -> V_93 = V_134 & V_136 ;
V_29 -> V_137 = V_134 & V_138 ;
V_29 -> V_139 = V_134 & V_140 ;
V_29 -> V_141 = V_134 & V_142 ;
return F_40 ( V_29 -> V_93 ) ;
}
static int F_110 ( struct V_108 * V_109 , unsigned long V_35 ,
T_5 V_80 , T_3 V_58 , int V_81 )
{
struct V_143 * V_144 = V_109 -> V_145 ;
struct V_8 * V_146 = V_144 -> V_147 ;
struct V_6 * V_7 = V_146 -> V_7 ;
struct V_28 V_29 ;
int V_148 ;
T_1 V_149 , V_134 ;
V_148 = F_111 ( V_58 ) ;
if ( V_148 < 0 ) {
F_10 ( V_7 , L_20 , V_58 ) ;
return - V_19 ;
}
F_34 ( V_7 , L_21 , V_35 , V_80 , V_58 ) ;
V_134 = V_148 | V_81 ;
F_109 ( & V_29 , V_35 , V_80 , V_134 ) ;
V_149 = F_69 ( V_146 , & V_29 ) ;
if ( V_149 )
F_10 ( V_7 , L_22 , V_149 ) ;
return V_149 ;
}
static T_3 F_112 ( struct V_108 * V_109 , unsigned long V_35 ,
T_3 V_150 )
{
struct V_143 * V_144 = V_109 -> V_145 ;
struct V_8 * V_146 = V_144 -> V_147 ;
struct V_6 * V_7 = V_146 -> V_7 ;
F_34 ( V_7 , L_23 , V_35 , V_150 ) ;
return F_73 ( V_146 , V_35 ) ;
}
static int
F_113 ( struct V_108 * V_109 , struct V_6 * V_7 )
{
struct V_143 * V_144 = V_109 -> V_145 ;
struct V_8 * V_146 ;
struct V_151 * V_152 = V_7 -> V_153 . V_154 ;
int V_149 = 0 ;
F_57 ( & V_144 -> V_155 ) ;
if ( V_144 -> V_147 ) {
F_10 ( V_7 , L_24 ) ;
V_149 = - V_4 ;
goto V_53;
}
V_146 = F_80 ( V_152 -> V_113 , V_144 -> V_156 ) ;
if ( F_35 ( V_146 ) ) {
V_149 = F_36 ( V_146 ) ;
F_10 ( V_7 , L_25 , V_149 ) ;
goto V_53;
}
V_144 -> V_147 = V_152 -> V_147 = V_146 ;
V_144 -> V_7 = V_7 ;
V_146 -> V_109 = V_109 ;
V_53:
F_55 ( & V_144 -> V_155 ) ;
return V_149 ;
}
static void F_114 ( struct V_143 * V_144 ,
struct V_6 * V_7 )
{
struct V_8 * V_146 = F_5 ( V_7 ) ;
struct V_151 * V_152 = V_7 -> V_153 . V_154 ;
if ( V_144 -> V_147 != V_146 ) {
F_10 ( V_7 , L_26 ) ;
return;
}
F_74 ( V_146 ) ;
F_83 ( V_146 ) ;
V_144 -> V_147 = V_152 -> V_147 = NULL ;
V_144 -> V_7 = NULL ;
}
static void F_115 ( struct V_108 * V_109 ,
struct V_6 * V_7 )
{
struct V_143 * V_144 = V_109 -> V_145 ;
F_57 ( & V_144 -> V_155 ) ;
F_114 ( V_144 , V_7 ) ;
F_55 ( & V_144 -> V_155 ) ;
}
static int F_116 ( struct V_108 * V_109 )
{
struct V_143 * V_144 ;
V_144 = F_86 ( sizeof( * V_144 ) , V_66 ) ;
if ( ! V_144 ) {
F_3 ( L_27 ) ;
goto V_53;
}
V_144 -> V_156 = F_86 ( V_157 , V_66 ) ;
if ( ! V_144 -> V_156 ) {
F_3 ( L_27 ) ;
goto V_158;
}
F_15 ( ! F_117 ( ( long ) V_144 -> V_156 , V_157 ) ) ;
F_108 ( V_144 -> V_156 , V_157 ) ;
F_87 ( & V_144 -> V_155 ) ;
V_109 -> V_145 = V_144 ;
V_109 -> V_159 . V_160 = 0 ;
V_109 -> V_159 . V_161 = ( 1ULL << 32 ) - 1 ;
V_109 -> V_159 . V_162 = true ;
return 0 ;
V_158:
F_37 ( V_144 ) ;
V_53:
return - V_78 ;
}
static void F_118 ( struct V_108 * V_109 )
{
struct V_143 * V_144 = V_109 -> V_145 ;
V_109 -> V_145 = NULL ;
if ( V_144 -> V_147 )
F_114 ( V_144 , V_144 -> V_7 ) ;
F_37 ( V_144 -> V_156 ) ;
F_37 ( V_144 ) ;
}
static T_5 F_119 ( struct V_108 * V_109 ,
unsigned long V_35 )
{
struct V_143 * V_144 = V_109 -> V_145 ;
struct V_8 * V_146 = V_144 -> V_147 ;
struct V_6 * V_7 = V_146 -> V_7 ;
T_1 * V_163 , * V_164 ;
T_5 V_149 = 0 ;
F_70 ( V_146 , V_35 , & V_163 , & V_164 ) ;
if ( V_164 ) {
if ( F_120 ( * V_164 ) )
V_149 = F_121 ( * V_164 , V_35 , V_165 ) ;
else if ( F_122 ( * V_164 ) )
V_149 = F_121 ( * V_164 , V_35 , V_90 ) ;
else
F_10 ( V_7 , L_28 , * V_164 , V_35 ) ;
} else {
if ( F_123 ( * V_163 ) )
V_149 = F_121 ( * V_163 , V_35 , V_82 ) ;
else if ( F_124 ( * V_163 ) )
V_149 = F_121 ( * V_163 , V_35 , V_85 ) ;
else
F_10 ( V_7 , L_29 , * V_163 , V_35 ) ;
}
return V_149 ;
}
static int F_125 ( struct V_108 * V_109 ,
unsigned long V_166 )
{
return 0 ;
}
static int T_6 F_126 ( void )
{
struct V_167 * V_65 ;
const unsigned long V_134 = V_168 ;
T_3 V_169 = 1 << 10 ;
V_65 = F_127 ( L_30 , V_133 , V_169 , V_134 ,
F_107 ) ;
if ( ! V_65 )
return - V_78 ;
V_74 = V_65 ;
F_128 ( & V_170 , & V_171 ) ;
return F_129 ( & V_68 ) ;
}
static void T_7 F_130 ( void )
{
F_131 ( V_74 ) ;
F_132 ( & V_68 ) ;
}
