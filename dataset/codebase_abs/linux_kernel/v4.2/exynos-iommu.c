static T_1 F_1 ( T_2 V_1 , T_1 V_2 )
{
return V_1 & ( V_2 - 1 ) ;
}
static T_1 F_2 ( T_2 V_1 )
{
return V_1 >> V_3 ;
}
static T_1 F_3 ( T_2 V_1 )
{
return ( V_1 >> V_4 ) & ( V_5 - 1 ) ;
}
static T_3 * F_4 ( T_3 * V_6 , T_2 V_1 )
{
return V_6 + F_2 ( V_1 ) ;
}
static T_3 * F_5 ( T_3 * V_7 , T_2 V_1 )
{
return ( T_3 * ) F_6 (
F_7 ( V_7 ) ) + F_3 ( V_1 ) ;
}
static struct V_8 * F_8 ( struct V_9 * V_10 )
{
return F_9 ( V_10 , struct V_8 , V_11 ) ;
}
static bool F_10 ( struct V_12 * V_13 )
{
return ++ V_13 -> V_14 == 1 ;
}
static bool F_11 ( struct V_12 * V_13 )
{
F_12 ( V_13 -> V_14 < 1 ) ;
return -- V_13 -> V_14 == 0 ;
}
static bool F_13 ( struct V_12 * V_13 )
{
return V_13 -> V_14 > 0 ;
}
static void F_14 ( void T_4 * V_15 )
{
F_15 ( V_16 , V_15 + V_17 ) ;
}
static bool F_16 ( void T_4 * V_15 )
{
int V_18 = 120 ;
F_15 ( V_19 , V_15 + V_17 ) ;
while ( ( V_18 > 0 ) && ! ( F_17 ( V_15 + V_20 ) & 1 ) )
-- V_18 ;
if ( ! ( F_17 ( V_15 + V_20 ) & 1 ) ) {
F_14 ( V_15 ) ;
return false ;
}
return true ;
}
static void F_18 ( void T_4 * V_15 )
{
F_15 ( 0x1 , V_15 + V_21 ) ;
}
static void F_19 ( void T_4 * V_15 ,
T_2 V_1 , unsigned int V_22 )
{
unsigned int V_18 ;
for ( V_18 = 0 ; V_18 < V_22 ; V_18 ++ ) {
F_15 ( ( V_1 & V_23 ) | 1 ,
V_15 + V_24 ) ;
V_1 += V_25 ;
}
}
static void F_20 ( void T_4 * V_15 ,
T_5 V_26 )
{
F_15 ( V_26 , V_15 + V_27 ) ;
F_18 ( V_15 ) ;
}
static void F_21 ( const char * V_28 ,
enum V_29 V_30 ,
T_5 V_31 , T_2 V_32 )
{
T_3 * V_33 ;
if ( ( V_30 >= V_34 ) || ( V_30 < V_35 ) )
V_30 = V_36 ;
F_22 ( L_1 ,
V_37 [ V_30 ] , V_32 , V_28 , & V_31 ) ;
V_33 = F_4 ( F_6 ( V_31 ) , V_32 ) ;
F_22 ( L_2 , * V_33 ) ;
if ( F_23 ( V_33 ) ) {
V_33 = F_5 ( V_33 , V_32 ) ;
F_22 ( L_3 , * V_33 ) ;
}
}
static T_6 F_24 ( int V_38 , void * V_39 )
{
struct V_12 * V_13 = V_39 ;
enum V_29 V_30 ;
T_2 V_40 = - 1 ;
int V_41 = - V_42 ;
F_25 ( ! F_13 ( V_13 ) ) ;
F_26 ( & V_13 -> V_43 ) ;
if ( ! F_27 ( V_13 -> V_44 ) )
F_28 ( V_13 -> V_44 ) ;
V_30 = (enum V_29 )
F_29 ( F_17 ( V_13 -> V_15 + V_45 ) ) ;
if ( F_25 ( ! ( ( V_30 >= 0 ) && ( V_30 < V_36 ) ) ) )
V_30 = V_36 ;
else
V_40 = F_17 ( V_13 -> V_15 + V_46 [ V_30 ] ) ;
if ( V_30 == V_36 ) {
F_22 ( L_4 ,
V_47 , F_30 ( V_13 -> V_48 ) ) ;
F_22 ( L_5 ,
V_47 ) ;
F_31 () ;
} else {
unsigned int V_49 =
F_17 ( V_13 -> V_15 + V_27 ) ;
F_21 ( F_30 ( V_13 -> V_48 ) ,
V_30 , V_49 , V_40 ) ;
if ( V_13 -> V_11 )
V_41 = F_32 ( & V_13 -> V_11 -> V_11 ,
V_13 -> V_50 , V_40 , V_30 ) ;
}
F_12 ( V_41 != 0 ) ;
F_15 ( 1 << V_30 , V_13 -> V_15 + V_51 ) ;
F_14 ( V_13 -> V_15 ) ;
if ( ! F_27 ( V_13 -> V_44 ) )
F_33 ( V_13 -> V_44 ) ;
F_34 ( & V_13 -> V_43 ) ;
return V_52 ;
}
static void F_35 ( struct V_12 * V_13 )
{
if ( ! F_27 ( V_13 -> V_44 ) )
F_28 ( V_13 -> V_44 ) ;
F_15 ( V_53 , V_13 -> V_15 + V_17 ) ;
F_15 ( 0 , V_13 -> V_15 + V_54 ) ;
F_33 ( V_13 -> V_55 ) ;
if ( ! F_27 ( V_13 -> V_44 ) )
F_33 ( V_13 -> V_44 ) ;
}
static bool F_36 ( struct V_12 * V_13 )
{
bool V_56 ;
unsigned long V_57 ;
F_37 ( & V_13 -> V_43 , V_57 ) ;
V_56 = F_11 ( V_13 ) ;
if ( V_56 ) {
V_13 -> V_6 = 0 ;
V_13 -> V_11 = NULL ;
F_35 ( V_13 ) ;
F_38 ( V_13 -> V_48 , L_6 ) ;
} else {
F_38 ( V_13 -> V_48 , L_7 ,
V_13 -> V_14 ) ;
}
F_39 ( & V_13 -> V_43 , V_57 ) ;
return V_56 ;
}
static void F_40 ( struct V_12 * V_13 )
{
unsigned int V_58 = V_59 | F_41 ( 15 ) ;
unsigned int V_60 ;
V_60 = F_42 ( F_17 ( V_13 -> V_15 + V_61 ) ) ;
if ( F_43 ( V_60 ) == 3 ) {
if ( F_44 ( V_60 ) >= 2 ) {
V_58 |= V_62 ;
if ( F_44 ( V_60 ) == 3 ) {
V_58 |= V_63 ;
V_58 &= ~ V_59 ;
} else {
V_58 |= V_64 ;
}
}
}
F_15 ( V_58 , V_13 -> V_15 + V_54 ) ;
V_13 -> V_65 = V_60 ;
}
static void F_45 ( struct V_12 * V_13 )
{
if ( ! F_27 ( V_13 -> V_44 ) )
F_28 ( V_13 -> V_44 ) ;
F_28 ( V_13 -> V_55 ) ;
F_15 ( V_19 , V_13 -> V_15 + V_17 ) ;
F_40 ( V_13 ) ;
F_20 ( V_13 -> V_15 , V_13 -> V_6 ) ;
F_15 ( V_16 , V_13 -> V_15 + V_17 ) ;
if ( ! F_27 ( V_13 -> V_44 ) )
F_33 ( V_13 -> V_44 ) ;
}
static int F_46 ( struct V_12 * V_13 , T_5 V_6 ,
struct V_8 * V_11 )
{
int V_41 = 0 ;
unsigned long V_57 ;
F_37 ( & V_13 -> V_43 , V_57 ) ;
if ( F_10 ( V_13 ) ) {
V_13 -> V_6 = V_6 ;
V_13 -> V_11 = V_11 ;
F_45 ( V_13 ) ;
F_38 ( V_13 -> V_48 , L_8 ) ;
} else {
V_41 = ( V_6 == V_13 -> V_6 ) ? 1 : - V_66 ;
F_38 ( V_13 -> V_48 , L_9 ) ;
}
if ( F_25 ( V_41 < 0 ) )
F_11 ( V_13 ) ;
F_39 ( & V_13 -> V_43 , V_57 ) ;
return V_41 ;
}
static void F_47 ( struct V_12 * V_13 ,
T_2 V_1 )
{
if ( V_13 -> V_65 == F_48 ( 3 , 3 ) )
F_15 ( V_1 | 0x1 , V_13 -> V_15 + V_24 ) ;
}
static void F_49 ( struct V_12 * V_13 ,
T_2 V_1 )
{
unsigned long V_57 ;
if ( ! F_27 ( V_13 -> V_44 ) )
F_28 ( V_13 -> V_44 ) ;
F_37 ( & V_13 -> V_43 , V_57 ) ;
if ( F_13 ( V_13 ) )
F_47 ( V_13 , V_1 ) ;
F_39 ( & V_13 -> V_43 , V_57 ) ;
if ( ! F_27 ( V_13 -> V_44 ) )
F_33 ( V_13 -> V_44 ) ;
}
static void F_50 ( struct V_12 * V_13 ,
T_2 V_1 , T_7 V_2 )
{
unsigned long V_57 ;
F_37 ( & V_13 -> V_43 , V_57 ) ;
if ( F_13 ( V_13 ) ) {
unsigned int V_22 = 1 ;
if ( ! F_27 ( V_13 -> V_44 ) )
F_28 ( V_13 -> V_44 ) ;
if ( F_43 ( V_13 -> V_65 ) == 2 )
V_22 = F_51 (unsigned int, size / PAGE_SIZE, 64 ) ;
if ( F_16 ( V_13 -> V_15 ) ) {
F_19 (
V_13 -> V_15 , V_1 , V_22 ) ;
F_14 ( V_13 -> V_15 ) ;
}
if ( ! F_27 ( V_13 -> V_44 ) )
F_33 ( V_13 -> V_44 ) ;
} else {
F_38 ( V_13 -> V_50 ,
L_10 , V_1 ) ;
}
F_39 ( & V_13 -> V_43 , V_57 ) ;
}
static int T_8 F_52 ( struct V_67 * V_68 )
{
int V_38 , V_41 ;
struct V_69 * V_70 = & V_68 -> V_70 ;
struct V_12 * V_13 ;
struct V_71 * V_72 ;
V_13 = F_53 ( V_70 , sizeof( * V_13 ) , V_73 ) ;
if ( ! V_13 )
return - V_74 ;
V_72 = F_54 ( V_68 , V_75 , 0 ) ;
V_13 -> V_15 = F_55 ( V_70 , V_72 ) ;
if ( F_27 ( V_13 -> V_15 ) )
return F_56 ( V_13 -> V_15 ) ;
V_38 = F_57 ( V_68 , 0 ) ;
if ( V_38 <= 0 ) {
F_58 ( V_70 , L_11 ) ;
return V_38 ;
}
V_41 = F_59 ( V_70 , V_38 , F_24 , 0 ,
F_30 ( V_70 ) , V_13 ) ;
if ( V_41 ) {
F_58 ( V_70 , L_12 , V_38 ) ;
return V_41 ;
}
V_13 -> V_55 = F_60 ( V_70 , L_13 ) ;
if ( F_27 ( V_13 -> V_55 ) ) {
F_58 ( V_70 , L_14 ) ;
return F_56 ( V_13 -> V_55 ) ;
} else {
V_41 = F_61 ( V_13 -> V_55 ) ;
if ( V_41 ) {
F_58 ( V_70 , L_15 ) ;
return V_41 ;
}
}
V_13 -> V_44 = F_60 ( V_70 , L_16 ) ;
if ( ! F_27 ( V_13 -> V_44 ) ) {
V_41 = F_61 ( V_13 -> V_44 ) ;
if ( V_41 ) {
F_62 ( V_13 -> V_55 ) ;
F_58 ( V_70 , L_17 ) ;
return V_41 ;
}
}
V_13 -> V_48 = V_70 ;
F_63 ( & V_13 -> V_43 ) ;
F_64 ( V_68 , V_13 ) ;
F_65 ( V_70 ) ;
return 0 ;
}
static int F_66 ( struct V_69 * V_70 )
{
struct V_12 * V_13 = F_67 ( V_70 ) ;
F_38 ( V_70 , L_18 ) ;
if ( F_13 ( V_13 ) ) {
F_35 ( V_13 ) ;
F_68 ( V_70 ) ;
}
return 0 ;
}
static int F_69 ( struct V_69 * V_70 )
{
struct V_12 * V_13 = F_67 ( V_70 ) ;
F_38 ( V_70 , L_19 ) ;
if ( F_13 ( V_13 ) ) {
F_70 ( V_70 ) ;
F_45 ( V_13 ) ;
}
return 0 ;
}
static inline void F_71 ( void * V_76 , void * V_77 )
{
F_72 ( V_76 , V_77 ) ;
F_73 ( F_74 ( V_76 ) ,
F_74 ( V_77 ) ) ;
}
static struct V_9 * F_75 ( unsigned type )
{
struct V_8 * V_11 ;
int V_18 ;
if ( type != V_78 )
return NULL ;
V_11 = F_76 ( sizeof( * V_11 ) , V_73 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_6 = ( T_3 * ) F_77 ( V_73 , 2 ) ;
if ( ! V_11 -> V_6 )
goto V_79;
V_11 -> V_80 = ( short * ) F_77 ( V_73 | V_81 , 1 ) ;
if ( ! V_11 -> V_80 )
goto V_82;
for ( V_18 = 0 ; V_18 < V_83 ; V_18 += 8 ) {
V_11 -> V_6 [ V_18 + 0 ] = V_84 ;
V_11 -> V_6 [ V_18 + 1 ] = V_84 ;
V_11 -> V_6 [ V_18 + 2 ] = V_84 ;
V_11 -> V_6 [ V_18 + 3 ] = V_84 ;
V_11 -> V_6 [ V_18 + 4 ] = V_84 ;
V_11 -> V_6 [ V_18 + 5 ] = V_84 ;
V_11 -> V_6 [ V_18 + 6 ] = V_84 ;
V_11 -> V_6 [ V_18 + 7 ] = V_84 ;
}
F_71 ( V_11 -> V_6 , V_11 -> V_6 + V_83 ) ;
F_63 ( & V_11 -> V_43 ) ;
F_63 ( & V_11 -> V_85 ) ;
F_78 ( & V_11 -> V_86 ) ;
V_11 -> V_11 . V_87 . V_88 = 0 ;
V_11 -> V_11 . V_87 . V_89 = ~ 0UL ;
V_11 -> V_11 . V_87 . V_90 = true ;
return & V_11 -> V_11 ;
V_82:
F_79 ( ( unsigned long ) V_11 -> V_6 , 2 ) ;
V_79:
F_80 ( V_11 ) ;
return NULL ;
}
static void F_81 ( struct V_9 * V_9 )
{
struct V_8 * V_11 = F_8 ( V_9 ) ;
struct V_12 * V_13 , * V_91 ;
unsigned long V_57 ;
int V_18 ;
F_25 ( ! F_82 ( & V_11 -> V_86 ) ) ;
F_37 ( & V_11 -> V_43 , V_57 ) ;
F_83 (data, next, &domain->clients, domain_node) {
if ( F_36 ( V_13 ) )
V_13 -> V_50 = NULL ;
F_84 ( & V_13 -> V_92 ) ;
}
F_39 ( & V_11 -> V_43 , V_57 ) ;
for ( V_18 = 0 ; V_18 < V_83 ; V_18 ++ )
if ( F_23 ( V_11 -> V_6 + V_18 ) )
F_85 ( V_93 ,
F_6 ( F_7 ( V_11 -> V_6 + V_18 ) ) ) ;
F_79 ( ( unsigned long ) V_11 -> V_6 , 2 ) ;
F_79 ( ( unsigned long ) V_11 -> V_80 , 1 ) ;
F_80 ( V_11 ) ;
}
static int F_86 ( struct V_9 * V_9 ,
struct V_69 * V_70 )
{
struct V_94 * V_95 = V_70 -> V_96 . V_97 ;
struct V_8 * V_11 = F_8 ( V_9 ) ;
struct V_12 * V_13 ;
T_5 V_98 = F_74 ( V_11 -> V_6 ) ;
unsigned long V_57 ;
int V_41 = - V_99 ;
if ( ! F_87 ( V_70 ) )
return - V_99 ;
F_88 (data, &owner->controllers, owner_node) {
F_70 ( V_13 -> V_48 ) ;
V_41 = F_46 ( V_13 , V_98 , V_11 ) ;
if ( V_41 >= 0 ) {
V_13 -> V_50 = V_70 ;
F_37 ( & V_11 -> V_43 , V_57 ) ;
F_89 ( & V_13 -> V_92 , & V_11 -> V_86 ) ;
F_39 ( & V_11 -> V_43 , V_57 ) ;
}
}
if ( V_41 < 0 ) {
F_58 ( V_70 , L_20 ,
V_47 , & V_98 ) ;
return V_41 ;
}
F_38 ( V_70 , L_21 ,
V_47 , & V_98 , ( V_41 == 0 ) ? L_22 : L_23 ) ;
return V_41 ;
}
static void F_90 ( struct V_9 * V_9 ,
struct V_69 * V_70 )
{
struct V_8 * V_11 = F_8 ( V_9 ) ;
T_5 V_98 = F_74 ( V_11 -> V_6 ) ;
struct V_12 * V_13 , * V_91 ;
unsigned long V_57 ;
bool V_100 = false ;
if ( ! F_87 ( V_70 ) )
return;
F_37 ( & V_11 -> V_43 , V_57 ) ;
F_83 (data, next, &domain->clients, domain_node) {
if ( V_13 -> V_50 == V_70 ) {
if ( F_36 ( V_13 ) ) {
V_13 -> V_50 = NULL ;
F_84 ( & V_13 -> V_92 ) ;
}
F_68 ( V_13 -> V_48 ) ;
V_100 = true ;
}
}
F_39 ( & V_11 -> V_43 , V_57 ) ;
if ( V_100 )
F_38 ( V_70 , L_24 ,
V_47 , & V_98 ) ;
else
F_58 ( V_70 , L_25 , V_47 ) ;
}
static T_3 * F_91 ( struct V_8 * V_11 ,
T_3 * V_7 , T_2 V_1 , short * V_101 )
{
if ( F_92 ( V_7 ) ) {
F_93 ( 1 , L_26 , V_1 ) ;
return F_94 ( - V_102 ) ;
}
if ( F_95 ( V_7 ) ) {
T_3 * V_103 ;
bool V_104 = F_96 ( V_7 ) ;
V_103 = F_97 ( V_93 , V_105 ) ;
F_12 ( ( unsigned int ) V_103 & ( V_106 - 1 ) ) ;
if ( ! V_103 )
return F_94 ( - V_74 ) ;
* V_7 = F_98 ( F_74 ( V_103 ) ) ;
F_99 ( V_103 ) ;
* V_101 = V_5 ;
F_71 ( V_103 , V_103 + V_5 ) ;
F_71 ( V_7 , V_7 + 1 ) ;
if ( V_104 ) {
struct V_12 * V_13 ;
F_26 ( & V_11 -> V_43 ) ;
F_88 (data, &domain->clients, domain_node)
F_49 ( V_13 , V_1 ) ;
F_34 ( & V_11 -> V_43 ) ;
}
}
return F_5 ( V_7 , V_1 ) ;
}
static int F_100 ( struct V_8 * V_11 ,
T_3 * V_7 , T_2 V_1 ,
T_5 V_107 , short * V_108 )
{
if ( F_92 ( V_7 ) ) {
F_93 ( 1 , L_27 ,
V_1 ) ;
return - V_102 ;
}
if ( F_23 ( V_7 ) ) {
if ( * V_108 != V_5 ) {
F_93 ( 1 , L_27 ,
V_1 ) ;
return - V_102 ;
}
F_85 ( V_93 , F_5 ( V_7 , 0 ) ) ;
* V_108 = 0 ;
}
* V_7 = F_101 ( V_107 ) ;
F_71 ( V_7 , V_7 + 1 ) ;
F_26 ( & V_11 -> V_43 ) ;
if ( F_102 ( V_7 ) ) {
struct V_12 * V_13 ;
F_88 (data, &domain->clients, domain_node)
F_49 ( V_13 , V_1 ) ;
}
F_34 ( & V_11 -> V_43 ) ;
return 0 ;
}
static int F_103 ( T_3 * V_103 , T_5 V_107 , T_7 V_2 ,
short * V_108 )
{
if ( V_2 == V_25 ) {
if ( F_25 ( ! F_104 ( V_103 ) ) )
return - V_102 ;
* V_103 = F_105 ( V_107 ) ;
F_71 ( V_103 , V_103 + 1 ) ;
* V_108 -= 1 ;
} else {
int V_18 ;
for ( V_18 = 0 ; V_18 < V_109 ; V_18 ++ , V_103 ++ ) {
if ( F_25 ( ! F_104 ( V_103 ) ) ) {
if ( V_18 > 0 )
memset ( V_103 - V_18 , 0 , sizeof( * V_103 ) * V_18 ) ;
return - V_102 ;
}
* V_103 = F_106 ( V_107 ) ;
}
F_71 ( V_103 - V_109 , V_103 ) ;
* V_108 -= V_109 ;
}
return 0 ;
}
static int F_107 ( struct V_9 * V_9 ,
unsigned long V_110 , T_5 V_107 , T_7 V_2 ,
int V_111 )
{
struct V_8 * V_11 = F_8 ( V_9 ) ;
T_3 * V_112 ;
T_2 V_1 = ( T_2 ) V_110 ;
unsigned long V_57 ;
int V_41 = - V_74 ;
F_12 ( V_11 -> V_6 == NULL ) ;
F_37 ( & V_11 -> V_85 , V_57 ) ;
V_112 = F_4 ( V_11 -> V_6 , V_1 ) ;
if ( V_2 == V_113 ) {
V_41 = F_100 ( V_11 , V_112 , V_1 , V_107 ,
& V_11 -> V_80 [ F_2 ( V_1 ) ] ) ;
} else {
T_3 * V_103 ;
V_103 = F_91 ( V_11 , V_112 , V_1 ,
& V_11 -> V_80 [ F_2 ( V_1 ) ] ) ;
if ( F_27 ( V_103 ) )
V_41 = F_56 ( V_103 ) ;
else
V_41 = F_103 ( V_103 , V_107 , V_2 ,
& V_11 -> V_80 [ F_2 ( V_1 ) ] ) ;
}
if ( V_41 )
F_22 ( L_28 ,
V_47 , V_41 , V_2 , V_1 ) ;
F_39 ( & V_11 -> V_85 , V_57 ) ;
return V_41 ;
}
static void F_108 ( struct V_8 * V_11 ,
T_2 V_1 , T_7 V_2 )
{
struct V_12 * V_13 ;
unsigned long V_57 ;
F_37 ( & V_11 -> V_43 , V_57 ) ;
F_88 (data, &domain->clients, domain_node)
F_50 ( V_13 , V_1 , V_2 ) ;
F_39 ( & V_11 -> V_43 , V_57 ) ;
}
static T_7 F_109 ( struct V_9 * V_9 ,
unsigned long V_110 , T_7 V_2 )
{
struct V_8 * V_11 = F_8 ( V_9 ) ;
T_2 V_1 = ( T_2 ) V_110 ;
T_3 * V_33 ;
T_7 V_114 ;
unsigned long V_57 ;
F_12 ( V_11 -> V_6 == NULL ) ;
F_37 ( & V_11 -> V_85 , V_57 ) ;
V_33 = F_4 ( V_11 -> V_6 , V_1 ) ;
if ( F_92 ( V_33 ) ) {
if ( F_25 ( V_2 < V_113 ) ) {
V_114 = V_113 ;
goto V_115;
}
* V_33 = V_84 ;
F_71 ( V_33 , V_33 + 1 ) ;
V_2 = V_113 ;
goto V_116;
}
if ( F_110 ( F_95 ( V_33 ) ) ) {
if ( V_2 > V_113 )
V_2 = V_113 ;
goto V_116;
}
V_33 = F_5 ( V_33 , V_1 ) ;
if ( F_110 ( F_104 ( V_33 ) ) ) {
V_2 = V_25 ;
goto V_116;
}
if ( F_111 ( V_33 ) ) {
* V_33 = 0 ;
V_2 = V_25 ;
F_71 ( V_33 , V_33 + 1 ) ;
V_11 -> V_80 [ F_2 ( V_1 ) ] += 1 ;
goto V_116;
}
if ( F_25 ( V_2 < V_117 ) ) {
V_114 = V_117 ;
goto V_115;
}
memset ( V_33 , 0 , sizeof( * V_33 ) * V_109 ) ;
F_71 ( V_33 , V_33 + V_109 ) ;
V_2 = V_117 ;
V_11 -> V_80 [ F_2 ( V_1 ) ] += V_109 ;
V_116:
F_39 ( & V_11 -> V_85 , V_57 ) ;
F_108 ( V_11 , V_1 , V_2 ) ;
return V_2 ;
V_115:
F_39 ( & V_11 -> V_85 , V_57 ) ;
F_22 ( L_29 ,
V_47 , V_2 , V_1 , V_114 ) ;
return 0 ;
}
static T_5 F_112 ( struct V_9 * V_9 ,
T_9 V_1 )
{
struct V_8 * V_11 = F_8 ( V_9 ) ;
T_3 * V_112 ;
unsigned long V_57 ;
T_5 V_118 = 0 ;
F_37 ( & V_11 -> V_85 , V_57 ) ;
V_112 = F_4 ( V_11 -> V_6 , V_1 ) ;
if ( F_92 ( V_112 ) ) {
V_118 = F_113 ( V_112 ) + F_114 ( V_1 ) ;
} else if ( F_23 ( V_112 ) ) {
V_112 = F_5 ( V_112 , V_1 ) ;
if ( F_115 ( V_112 ) )
V_118 = F_116 ( V_112 ) + F_117 ( V_1 ) ;
else if ( F_111 ( V_112 ) )
V_118 = F_118 ( V_112 ) + F_119 ( V_1 ) ;
}
F_39 ( & V_11 -> V_85 , V_57 ) ;
return V_118 ;
}
static int F_120 ( struct V_69 * V_70 )
{
struct V_119 * V_120 ;
int V_41 ;
if ( ! F_87 ( V_70 ) )
return - V_99 ;
V_120 = F_121 ( V_70 ) ;
if ( ! V_120 ) {
V_120 = F_122 () ;
if ( F_27 ( V_120 ) ) {
F_58 ( V_70 , L_30 ) ;
return F_56 ( V_120 ) ;
}
}
V_41 = F_123 ( V_120 , V_70 ) ;
F_124 ( V_120 ) ;
return V_41 ;
}
static void F_125 ( struct V_69 * V_70 )
{
if ( ! F_87 ( V_70 ) )
return;
F_126 ( V_70 ) ;
}
static int F_127 ( struct V_69 * V_70 ,
struct V_121 * V_122 )
{
struct V_94 * V_95 = V_70 -> V_96 . V_97 ;
struct V_67 * V_48 = F_128 ( V_122 -> V_123 ) ;
struct V_12 * V_13 ;
if ( ! V_48 )
return - V_99 ;
V_13 = F_129 ( V_48 ) ;
if ( ! V_13 )
return - V_99 ;
if ( ! V_95 ) {
V_95 = F_76 ( sizeof( * V_95 ) , V_73 ) ;
if ( ! V_95 )
return - V_74 ;
F_78 ( & V_95 -> V_124 ) ;
V_70 -> V_96 . V_97 = V_95 ;
}
F_89 ( & V_13 -> V_125 , & V_95 -> V_124 ) ;
return 0 ;
}
static int T_8 F_130 ( void )
{
int V_41 ;
V_93 = F_131 ( L_31 ,
V_106 , V_106 , 0 , NULL ) ;
if ( ! V_93 ) {
F_22 ( L_32 , V_47 ) ;
return - V_74 ;
}
V_41 = F_132 ( & V_126 ) ;
if ( V_41 ) {
F_22 ( L_33 , V_47 ) ;
goto V_127;
}
V_128 = F_97 ( V_93 , V_73 ) ;
if ( V_128 == NULL ) {
F_22 ( L_34 ,
V_47 ) ;
V_41 = - V_74 ;
goto V_129;
}
V_41 = F_133 ( & V_130 , & V_131 ) ;
if ( V_41 ) {
F_22 ( L_35 ,
V_47 ) ;
goto V_132;
}
V_133 = true ;
return 0 ;
V_132:
F_85 ( V_93 , V_128 ) ;
V_129:
F_134 ( & V_126 ) ;
V_127:
F_135 ( V_93 ) ;
return V_41 ;
}
static int T_8 F_136 ( struct V_134 * V_123 )
{
struct V_67 * V_68 ;
if ( ! V_133 )
F_130 () ;
V_68 = F_137 ( V_123 , NULL , V_130 . V_135 ) ;
if ( F_27 ( V_68 ) )
return F_56 ( V_68 ) ;
F_138 ( V_123 , & V_131 ) ;
return 0 ;
}
