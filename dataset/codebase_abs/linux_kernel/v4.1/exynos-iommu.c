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
static unsigned int F_16 ( struct V_12 * V_13 )
{
return F_17 ( F_18 ( V_13 -> V_15 + V_18 ) ) ;
}
static bool F_19 ( void T_4 * V_15 )
{
int V_19 = 120 ;
F_15 ( V_20 , V_15 + V_17 ) ;
while ( ( V_19 > 0 ) && ! ( F_18 ( V_15 + V_21 ) & 1 ) )
-- V_19 ;
if ( ! ( F_18 ( V_15 + V_21 ) & 1 ) ) {
F_14 ( V_15 ) ;
return false ;
}
return true ;
}
static void F_20 ( void T_4 * V_15 )
{
F_15 ( 0x1 , V_15 + V_22 ) ;
}
static void F_21 ( void T_4 * V_15 ,
T_2 V_1 , unsigned int V_23 )
{
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_23 ; V_19 ++ ) {
F_15 ( ( V_1 & V_24 ) | 1 ,
V_15 + V_25 ) ;
V_1 += V_26 ;
}
}
static void F_22 ( void T_4 * V_15 ,
T_5 V_27 )
{
F_15 ( V_27 , V_15 + V_28 ) ;
F_20 ( V_15 ) ;
}
static void F_23 ( const char * V_29 ,
enum V_30 V_31 ,
T_5 V_32 , T_2 V_33 )
{
T_3 * V_34 ;
if ( ( V_31 >= V_35 ) || ( V_31 < V_36 ) )
V_31 = V_37 ;
F_24 ( L_1 ,
V_38 [ V_31 ] , V_33 , V_29 , & V_32 ) ;
V_34 = F_4 ( F_6 ( V_32 ) , V_33 ) ;
F_24 ( L_2 , * V_34 ) ;
if ( F_25 ( V_34 ) ) {
V_34 = F_5 ( V_34 , V_33 ) ;
F_24 ( L_3 , * V_34 ) ;
}
}
static T_6 F_26 ( int V_39 , void * V_40 )
{
struct V_12 * V_13 = V_40 ;
enum V_30 V_31 ;
T_2 V_41 = - 1 ;
int V_42 = - V_43 ;
F_27 ( ! F_13 ( V_13 ) ) ;
F_28 ( & V_13 -> V_44 ) ;
if ( ! F_29 ( V_13 -> V_45 ) )
F_30 ( V_13 -> V_45 ) ;
V_31 = (enum V_30 )
F_31 ( F_18 ( V_13 -> V_15 + V_46 ) ) ;
if ( F_27 ( ! ( ( V_31 >= 0 ) && ( V_31 < V_37 ) ) ) )
V_31 = V_37 ;
else
V_41 = F_18 ( V_13 -> V_15 + V_47 [ V_31 ] ) ;
if ( V_31 == V_37 ) {
F_24 ( L_4 ,
V_48 , F_32 ( V_13 -> V_49 ) ) ;
F_24 ( L_5 ,
V_48 ) ;
F_33 () ;
} else {
unsigned int V_50 =
F_18 ( V_13 -> V_15 + V_28 ) ;
F_23 ( F_32 ( V_13 -> V_49 ) ,
V_31 , V_50 , V_41 ) ;
if ( V_13 -> V_11 )
V_42 = F_34 ( V_13 -> V_11 ,
V_13 -> V_51 , V_41 , V_31 ) ;
}
F_12 ( V_42 != 0 ) ;
F_15 ( 1 << V_31 , V_13 -> V_15 + V_52 ) ;
F_14 ( V_13 -> V_15 ) ;
if ( ! F_29 ( V_13 -> V_45 ) )
F_35 ( V_13 -> V_45 ) ;
F_36 ( & V_13 -> V_44 ) ;
return V_53 ;
}
static void F_37 ( struct V_12 * V_13 )
{
if ( ! F_29 ( V_13 -> V_45 ) )
F_30 ( V_13 -> V_45 ) ;
F_15 ( V_54 , V_13 -> V_15 + V_17 ) ;
F_15 ( 0 , V_13 -> V_15 + V_55 ) ;
F_35 ( V_13 -> V_56 ) ;
if ( ! F_29 ( V_13 -> V_45 ) )
F_35 ( V_13 -> V_45 ) ;
}
static bool F_38 ( struct V_12 * V_13 )
{
bool V_57 ;
unsigned long V_58 ;
F_39 ( & V_13 -> V_44 , V_58 ) ;
V_57 = F_11 ( V_13 ) ;
if ( V_57 ) {
V_13 -> V_6 = 0 ;
V_13 -> V_11 = NULL ;
F_37 ( V_13 ) ;
F_40 ( V_13 -> V_49 , L_6 ) ;
} else {
F_40 ( V_13 -> V_49 , L_7 ,
V_13 -> V_14 ) ;
}
F_41 ( & V_13 -> V_44 , V_58 ) ;
return V_57 ;
}
static void F_42 ( struct V_12 * V_13 )
{
unsigned int V_59 = V_60 | F_43 ( 15 ) ;
unsigned int V_61 ;
V_61 = F_16 ( V_13 ) ;
if ( F_44 ( V_61 ) == 3 ) {
if ( F_45 ( V_61 ) >= 2 ) {
V_59 |= V_62 ;
if ( F_45 ( V_61 ) == 3 ) {
V_59 |= V_63 ;
V_59 &= ~ V_60 ;
} else {
V_59 |= V_64 ;
}
}
}
F_15 ( V_59 , V_13 -> V_15 + V_55 ) ;
}
static void F_46 ( struct V_12 * V_13 )
{
if ( ! F_29 ( V_13 -> V_45 ) )
F_30 ( V_13 -> V_45 ) ;
F_30 ( V_13 -> V_56 ) ;
F_15 ( V_20 , V_13 -> V_15 + V_17 ) ;
F_42 ( V_13 ) ;
F_22 ( V_13 -> V_15 , V_13 -> V_6 ) ;
F_15 ( V_16 , V_13 -> V_15 + V_17 ) ;
if ( ! F_29 ( V_13 -> V_45 ) )
F_35 ( V_13 -> V_45 ) ;
}
static int F_47 ( struct V_12 * V_13 ,
T_5 V_6 , struct V_9 * V_11 )
{
int V_42 = 0 ;
unsigned long V_58 ;
F_39 ( & V_13 -> V_44 , V_58 ) ;
if ( F_10 ( V_13 ) ) {
V_13 -> V_6 = V_6 ;
V_13 -> V_11 = V_11 ;
F_46 ( V_13 ) ;
F_40 ( V_13 -> V_49 , L_8 ) ;
} else {
V_42 = ( V_6 == V_13 -> V_6 ) ? 1 : - V_65 ;
F_40 ( V_13 -> V_49 , L_9 ) ;
}
if ( F_27 ( V_42 < 0 ) )
F_11 ( V_13 ) ;
F_41 ( & V_13 -> V_44 , V_58 ) ;
return V_42 ;
}
static int F_48 ( struct V_66 * V_67 , T_5 V_6 ,
struct V_9 * V_11 )
{
int V_42 = 0 ;
unsigned long V_58 ;
struct V_68 * V_69 = V_67 -> V_70 . V_71 ;
struct V_12 * V_13 ;
F_12 ( ! F_49 ( V_67 ) ) ;
F_39 ( & V_69 -> V_44 , V_58 ) ;
V_13 = F_50 ( V_69 -> V_49 ) ;
V_42 = F_47 ( V_13 , V_6 , V_11 ) ;
if ( V_42 >= 0 )
V_13 -> V_51 = V_67 ;
F_41 ( & V_69 -> V_44 , V_58 ) ;
return V_42 ;
}
int F_51 ( struct V_66 * V_67 , T_5 V_6 )
{
F_12 ( ! F_52 ( V_6 ) ) ;
return F_48 ( V_67 , V_6 , NULL ) ;
}
static bool F_53 ( struct V_66 * V_67 )
{
unsigned long V_58 ;
bool V_57 = true ;
struct V_68 * V_69 = V_67 -> V_70 . V_71 ;
struct V_12 * V_13 ;
F_12 ( ! F_49 ( V_67 ) ) ;
F_39 ( & V_69 -> V_44 , V_58 ) ;
V_13 = F_50 ( V_69 -> V_49 ) ;
V_57 = F_38 ( V_13 ) ;
if ( V_57 )
V_13 -> V_51 = NULL ;
F_41 ( & V_69 -> V_44 , V_58 ) ;
return V_57 ;
}
static void F_54 ( struct V_12 * V_13 ,
T_2 V_1 )
{
if ( F_16 ( V_13 ) == F_55 ( 3 , 3 ) )
F_15 ( V_1 | 0x1 , V_13 -> V_15 + V_25 ) ;
}
static void F_56 ( struct V_66 * V_67 ,
T_2 V_1 )
{
unsigned long V_58 ;
struct V_68 * V_69 = V_67 -> V_70 . V_71 ;
struct V_12 * V_13 = F_50 ( V_69 -> V_49 ) ;
if ( ! F_29 ( V_13 -> V_45 ) )
F_30 ( V_13 -> V_45 ) ;
F_39 ( & V_13 -> V_44 , V_58 ) ;
if ( F_13 ( V_13 ) )
F_54 ( V_13 , V_1 ) ;
F_41 ( & V_13 -> V_44 , V_58 ) ;
if ( ! F_29 ( V_13 -> V_45 ) )
F_35 ( V_13 -> V_45 ) ;
}
static void F_57 ( struct V_66 * V_67 , T_2 V_1 ,
T_7 V_2 )
{
struct V_68 * V_69 = V_67 -> V_70 . V_71 ;
unsigned long V_58 ;
struct V_12 * V_13 ;
V_13 = F_50 ( V_69 -> V_49 ) ;
F_39 ( & V_13 -> V_44 , V_58 ) ;
if ( F_13 ( V_13 ) ) {
unsigned int V_23 = 1 ;
if ( ! F_29 ( V_13 -> V_45 ) )
F_30 ( V_13 -> V_45 ) ;
if ( F_44 ( F_16 ( V_13 ) ) == 2 )
V_23 = F_58 (unsigned int, size / PAGE_SIZE, 64 ) ;
if ( F_19 ( V_13 -> V_15 ) ) {
F_21 (
V_13 -> V_15 , V_1 , V_23 ) ;
F_14 ( V_13 -> V_15 ) ;
}
if ( ! F_29 ( V_13 -> V_45 ) )
F_35 ( V_13 -> V_45 ) ;
} else {
F_40 ( V_67 , L_10 ,
V_1 ) ;
}
F_41 ( & V_13 -> V_44 , V_58 ) ;
}
void F_59 ( struct V_66 * V_67 )
{
struct V_68 * V_69 = V_67 -> V_70 . V_71 ;
unsigned long V_58 ;
struct V_12 * V_13 ;
V_13 = F_50 ( V_69 -> V_49 ) ;
F_39 ( & V_13 -> V_44 , V_58 ) ;
if ( F_13 ( V_13 ) ) {
if ( ! F_29 ( V_13 -> V_45 ) )
F_30 ( V_13 -> V_45 ) ;
if ( F_19 ( V_13 -> V_15 ) ) {
F_20 ( V_13 -> V_15 ) ;
F_14 ( V_13 -> V_15 ) ;
}
if ( ! F_29 ( V_13 -> V_45 ) )
F_35 ( V_13 -> V_45 ) ;
} else {
F_40 ( V_67 , L_11 ) ;
}
F_41 ( & V_13 -> V_44 , V_58 ) ;
}
static int T_8 F_60 ( struct V_72 * V_73 )
{
int V_39 , V_42 ;
struct V_66 * V_67 = & V_73 -> V_67 ;
struct V_12 * V_13 ;
struct V_74 * V_75 ;
V_13 = F_61 ( V_67 , sizeof( * V_13 ) , V_76 ) ;
if ( ! V_13 )
return - V_77 ;
V_75 = F_62 ( V_73 , V_78 , 0 ) ;
V_13 -> V_15 = F_63 ( V_67 , V_75 ) ;
if ( F_29 ( V_13 -> V_15 ) )
return F_64 ( V_13 -> V_15 ) ;
V_39 = F_65 ( V_73 , 0 ) ;
if ( V_39 <= 0 ) {
F_66 ( V_67 , L_12 ) ;
return V_39 ;
}
V_42 = F_67 ( V_67 , V_39 , F_26 , 0 ,
F_32 ( V_67 ) , V_13 ) ;
if ( V_42 ) {
F_66 ( V_67 , L_13 , V_39 ) ;
return V_42 ;
}
V_13 -> V_56 = F_68 ( V_67 , L_14 ) ;
if ( F_29 ( V_13 -> V_56 ) ) {
F_66 ( V_67 , L_15 ) ;
return F_64 ( V_13 -> V_56 ) ;
} else {
V_42 = F_69 ( V_13 -> V_56 ) ;
if ( V_42 ) {
F_66 ( V_67 , L_16 ) ;
return V_42 ;
}
}
V_13 -> V_45 = F_68 ( V_67 , L_17 ) ;
if ( ! F_29 ( V_13 -> V_45 ) ) {
V_42 = F_69 ( V_13 -> V_45 ) ;
if ( V_42 ) {
F_70 ( V_13 -> V_56 ) ;
F_66 ( V_67 , L_18 ) ;
return V_42 ;
}
}
V_13 -> V_49 = V_67 ;
F_71 ( & V_13 -> V_44 ) ;
F_72 ( V_73 , V_13 ) ;
F_73 ( V_67 ) ;
return 0 ;
}
static inline void F_74 ( void * V_79 , void * V_80 )
{
F_75 ( V_79 , V_80 ) ;
F_76 ( F_77 ( V_79 ) ,
F_77 ( V_80 ) ) ;
}
static struct V_9 * F_78 ( unsigned type )
{
struct V_8 * V_81 ;
int V_19 ;
if ( type != V_82 )
return NULL ;
V_81 = F_79 ( sizeof( * V_81 ) , V_76 ) ;
if ( ! V_81 )
return NULL ;
V_81 -> V_6 = ( T_3 * ) F_80 ( V_76 , 2 ) ;
if ( ! V_81 -> V_6 )
goto V_83;
V_81 -> V_84 = ( short * ) F_80 ( V_76 | V_85 , 1 ) ;
if ( ! V_81 -> V_84 )
goto V_86;
for ( V_19 = 0 ; V_19 < V_87 ; V_19 += 8 ) {
V_81 -> V_6 [ V_19 + 0 ] = V_88 ;
V_81 -> V_6 [ V_19 + 1 ] = V_88 ;
V_81 -> V_6 [ V_19 + 2 ] = V_88 ;
V_81 -> V_6 [ V_19 + 3 ] = V_88 ;
V_81 -> V_6 [ V_19 + 4 ] = V_88 ;
V_81 -> V_6 [ V_19 + 5 ] = V_88 ;
V_81 -> V_6 [ V_19 + 6 ] = V_88 ;
V_81 -> V_6 [ V_19 + 7 ] = V_88 ;
}
F_74 ( V_81 -> V_6 , V_81 -> V_6 + V_87 ) ;
F_71 ( & V_81 -> V_44 ) ;
F_71 ( & V_81 -> V_89 ) ;
F_81 ( & V_81 -> V_90 ) ;
V_81 -> V_11 . V_91 . V_92 = 0 ;
V_81 -> V_11 . V_91 . V_93 = ~ 0UL ;
V_81 -> V_11 . V_91 . V_94 = true ;
return & V_81 -> V_11 ;
V_86:
F_82 ( ( unsigned long ) V_81 -> V_6 , 2 ) ;
V_83:
F_83 ( V_81 ) ;
return NULL ;
}
static void F_84 ( struct V_9 * V_11 )
{
struct V_8 * V_95 = F_8 ( V_11 ) ;
struct V_68 * V_69 ;
unsigned long V_58 ;
int V_19 ;
F_27 ( ! F_85 ( & V_95 -> V_90 ) ) ;
F_39 ( & V_95 -> V_44 , V_58 ) ;
F_86 (owner, &priv->clients, client) {
while ( ! F_53 ( V_69 -> V_67 ) )
;
}
while ( ! F_85 ( & V_95 -> V_90 ) )
F_87 ( V_95 -> V_90 . V_96 ) ;
F_41 ( & V_95 -> V_44 , V_58 ) ;
for ( V_19 = 0 ; V_19 < V_87 ; V_19 ++ )
if ( F_25 ( V_95 -> V_6 + V_19 ) )
F_88 ( V_97 ,
F_6 ( F_7 ( V_95 -> V_6 + V_19 ) ) ) ;
F_82 ( ( unsigned long ) V_95 -> V_6 , 2 ) ;
F_82 ( ( unsigned long ) V_95 -> V_84 , 1 ) ;
F_83 ( V_95 ) ;
}
static int F_89 ( struct V_9 * V_11 ,
struct V_66 * V_67 )
{
struct V_68 * V_69 = V_67 -> V_70 . V_71 ;
struct V_8 * V_95 = F_8 ( V_11 ) ;
T_5 V_98 = F_77 ( V_95 -> V_6 ) ;
unsigned long V_58 ;
int V_42 ;
F_39 ( & V_95 -> V_44 , V_58 ) ;
V_42 = F_48 ( V_67 , V_98 , V_11 ) ;
if ( V_42 == 0 ) {
F_90 ( & V_69 -> V_99 , & V_95 -> V_90 ) ;
V_69 -> V_11 = V_11 ;
}
F_41 ( & V_95 -> V_44 , V_58 ) ;
if ( V_42 < 0 ) {
F_66 ( V_67 , L_19 ,
V_48 , & V_98 ) ;
return V_42 ;
}
F_40 ( V_67 , L_20 ,
V_48 , & V_98 , ( V_42 == 0 ) ? L_21 : L_22 ) ;
return V_42 ;
}
static void F_91 ( struct V_9 * V_11 ,
struct V_66 * V_67 )
{
struct V_68 * V_69 ;
struct V_8 * V_95 = F_8 ( V_11 ) ;
T_5 V_98 = F_77 ( V_95 -> V_6 ) ;
unsigned long V_58 ;
F_39 ( & V_95 -> V_44 , V_58 ) ;
F_86 (owner, &priv->clients, client) {
if ( V_69 == V_67 -> V_70 . V_71 ) {
if ( F_53 ( V_67 ) ) {
F_87 ( & V_69 -> V_99 ) ;
V_69 -> V_11 = NULL ;
}
break;
}
}
F_41 ( & V_95 -> V_44 , V_58 ) ;
if ( V_69 == V_67 -> V_70 . V_71 )
F_40 ( V_67 , L_23 ,
V_48 , & V_98 ) ;
else
F_66 ( V_67 , L_24 , V_48 ) ;
}
static T_3 * F_92 ( struct V_8 * V_95 ,
T_3 * V_7 , T_2 V_1 , short * V_100 )
{
if ( F_93 ( V_7 ) ) {
F_94 ( 1 , L_25 , V_1 ) ;
return F_95 ( - V_101 ) ;
}
if ( F_96 ( V_7 ) ) {
T_3 * V_102 ;
bool V_103 = F_97 ( V_7 ) ;
V_102 = F_98 ( V_97 , V_104 ) ;
F_12 ( ( unsigned int ) V_102 & ( V_105 - 1 ) ) ;
if ( ! V_102 )
return F_95 ( - V_77 ) ;
* V_7 = F_99 ( F_77 ( V_102 ) ) ;
* V_100 = V_5 ;
F_74 ( V_102 , V_102 + V_5 ) ;
F_74 ( V_7 , V_7 + 1 ) ;
if ( V_103 ) {
struct V_68 * V_69 ;
F_28 ( & V_95 -> V_44 ) ;
F_86 (owner, &priv->clients, client)
F_56 (
V_69 -> V_67 , V_1 ) ;
F_36 ( & V_95 -> V_44 ) ;
}
}
return F_5 ( V_7 , V_1 ) ;
}
static int F_100 ( struct V_8 * V_95 ,
T_3 * V_7 , T_2 V_1 ,
T_5 V_106 , short * V_107 )
{
if ( F_93 ( V_7 ) ) {
F_94 ( 1 , L_26 ,
V_1 ) ;
return - V_101 ;
}
if ( F_25 ( V_7 ) ) {
if ( * V_107 != V_5 ) {
F_94 ( 1 , L_26 ,
V_1 ) ;
return - V_101 ;
}
F_88 ( V_97 , F_5 ( V_7 , 0 ) ) ;
* V_107 = 0 ;
}
* V_7 = F_101 ( V_106 ) ;
F_74 ( V_7 , V_7 + 1 ) ;
F_28 ( & V_95 -> V_44 ) ;
if ( F_102 ( V_7 ) ) {
struct V_68 * V_69 ;
F_86 (owner, &priv->clients, client)
F_56 ( V_69 -> V_67 , V_1 ) ;
}
F_36 ( & V_95 -> V_44 ) ;
return 0 ;
}
static int F_103 ( T_3 * V_102 , T_5 V_106 , T_7 V_2 ,
short * V_107 )
{
if ( V_2 == V_26 ) {
if ( F_27 ( ! F_104 ( V_102 ) ) )
return - V_101 ;
* V_102 = F_105 ( V_106 ) ;
F_74 ( V_102 , V_102 + 1 ) ;
* V_107 -= 1 ;
} else {
int V_19 ;
for ( V_19 = 0 ; V_19 < V_108 ; V_19 ++ , V_102 ++ ) {
if ( F_27 ( ! F_104 ( V_102 ) ) ) {
if ( V_19 > 0 )
memset ( V_102 - V_19 , 0 , sizeof( * V_102 ) * V_19 ) ;
return - V_101 ;
}
* V_102 = F_106 ( V_106 ) ;
}
F_74 ( V_102 - V_108 , V_102 ) ;
* V_107 -= V_108 ;
}
return 0 ;
}
static int F_107 ( struct V_9 * V_11 , unsigned long V_109 ,
T_5 V_106 , T_7 V_2 , int V_110 )
{
struct V_8 * V_95 = F_8 ( V_11 ) ;
T_3 * V_111 ;
T_2 V_1 = ( T_2 ) V_109 ;
unsigned long V_58 ;
int V_42 = - V_77 ;
F_12 ( V_95 -> V_6 == NULL ) ;
F_39 ( & V_95 -> V_89 , V_58 ) ;
V_111 = F_4 ( V_95 -> V_6 , V_1 ) ;
if ( V_2 == V_112 ) {
V_42 = F_100 ( V_95 , V_111 , V_1 , V_106 ,
& V_95 -> V_84 [ F_2 ( V_1 ) ] ) ;
} else {
T_3 * V_102 ;
V_102 = F_92 ( V_95 , V_111 , V_1 ,
& V_95 -> V_84 [ F_2 ( V_1 ) ] ) ;
if ( F_29 ( V_102 ) )
V_42 = F_64 ( V_102 ) ;
else
V_42 = F_103 ( V_102 , V_106 , V_2 ,
& V_95 -> V_84 [ F_2 ( V_1 ) ] ) ;
}
if ( V_42 )
F_24 ( L_27 ,
V_48 , V_42 , V_2 , V_1 ) ;
F_41 ( & V_95 -> V_89 , V_58 ) ;
return V_42 ;
}
static void F_108 ( struct V_8 * V_95 ,
T_2 V_1 , T_7 V_2 )
{
struct V_68 * V_69 ;
unsigned long V_58 ;
F_39 ( & V_95 -> V_44 , V_58 ) ;
F_86 (owner, &priv->clients, client)
F_57 ( V_69 -> V_67 , V_1 , V_2 ) ;
F_41 ( & V_95 -> V_44 , V_58 ) ;
}
static T_7 F_109 ( struct V_9 * V_11 ,
unsigned long V_109 , T_7 V_2 )
{
struct V_8 * V_95 = F_8 ( V_11 ) ;
T_2 V_1 = ( T_2 ) V_109 ;
T_3 * V_34 ;
T_7 V_113 ;
unsigned long V_58 ;
F_12 ( V_95 -> V_6 == NULL ) ;
F_39 ( & V_95 -> V_89 , V_58 ) ;
V_34 = F_4 ( V_95 -> V_6 , V_1 ) ;
if ( F_93 ( V_34 ) ) {
if ( F_27 ( V_2 < V_112 ) ) {
V_113 = V_112 ;
goto V_114;
}
* V_34 = V_88 ;
F_74 ( V_34 , V_34 + 1 ) ;
V_2 = V_112 ;
goto V_115;
}
if ( F_110 ( F_96 ( V_34 ) ) ) {
if ( V_2 > V_112 )
V_2 = V_112 ;
goto V_115;
}
V_34 = F_5 ( V_34 , V_1 ) ;
if ( F_110 ( F_104 ( V_34 ) ) ) {
V_2 = V_26 ;
goto V_115;
}
if ( F_111 ( V_34 ) ) {
* V_34 = 0 ;
V_2 = V_26 ;
F_74 ( V_34 , V_34 + 1 ) ;
V_95 -> V_84 [ F_2 ( V_1 ) ] += 1 ;
goto V_115;
}
if ( F_27 ( V_2 < V_116 ) ) {
V_113 = V_116 ;
goto V_114;
}
memset ( V_34 , 0 , sizeof( * V_34 ) * V_108 ) ;
F_74 ( V_34 , V_34 + V_108 ) ;
V_2 = V_116 ;
V_95 -> V_84 [ F_2 ( V_1 ) ] += V_108 ;
V_115:
F_41 ( & V_95 -> V_89 , V_58 ) ;
F_108 ( V_95 , V_1 , V_2 ) ;
return V_2 ;
V_114:
F_41 ( & V_95 -> V_89 , V_58 ) ;
F_24 ( L_28 ,
V_48 , V_2 , V_1 , V_113 ) ;
return 0 ;
}
static T_5 F_112 ( struct V_9 * V_11 ,
T_9 V_1 )
{
struct V_8 * V_95 = F_8 ( V_11 ) ;
T_3 * V_111 ;
unsigned long V_58 ;
T_5 V_117 = 0 ;
F_39 ( & V_95 -> V_89 , V_58 ) ;
V_111 = F_4 ( V_95 -> V_6 , V_1 ) ;
if ( F_93 ( V_111 ) ) {
V_117 = F_113 ( V_111 ) + F_114 ( V_1 ) ;
} else if ( F_25 ( V_111 ) ) {
V_111 = F_5 ( V_111 , V_1 ) ;
if ( F_115 ( V_111 ) )
V_117 = F_116 ( V_111 ) + F_117 ( V_1 ) ;
else if ( F_111 ( V_111 ) )
V_117 = F_118 ( V_111 ) + F_119 ( V_1 ) ;
}
F_41 ( & V_95 -> V_89 , V_58 ) ;
return V_117 ;
}
static int F_120 ( struct V_66 * V_67 )
{
struct V_118 * V_119 ;
int V_42 ;
V_119 = F_121 ( V_67 ) ;
if ( ! V_119 ) {
V_119 = F_122 () ;
if ( F_29 ( V_119 ) ) {
F_66 ( V_67 , L_29 ) ;
return F_64 ( V_119 ) ;
}
}
V_42 = F_123 ( V_119 , V_67 ) ;
F_124 ( V_119 ) ;
return V_42 ;
}
static void F_125 ( struct V_66 * V_67 )
{
F_126 ( V_67 ) ;
}
static int T_8 F_127 ( void )
{
struct V_120 * V_121 ;
int V_42 ;
V_121 = F_128 ( NULL , V_122 ) ;
if ( ! V_121 )
return 0 ;
F_129 ( V_121 ) ;
V_97 = F_130 ( L_30 ,
V_105 , V_105 , 0 , NULL ) ;
if ( ! V_97 ) {
F_24 ( L_31 , V_48 ) ;
return - V_77 ;
}
V_42 = F_131 ( & V_123 ) ;
if ( V_42 ) {
F_24 ( L_32 , V_48 ) ;
goto V_124;
}
V_125 = F_98 ( V_97 , V_76 ) ;
if ( V_125 == NULL ) {
F_24 ( L_33 ,
V_48 ) ;
V_42 = - V_77 ;
goto V_126;
}
V_42 = F_132 ( & V_127 , & V_128 ) ;
if ( V_42 ) {
F_24 ( L_34 ,
V_48 ) ;
goto V_129;
}
return 0 ;
V_129:
F_88 ( V_97 , V_125 ) ;
V_126:
F_133 ( & V_123 ) ;
V_124:
F_134 ( V_97 ) ;
return V_42 ;
}
