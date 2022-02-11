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
static bool F_8 ( struct V_8 * V_9 )
{
return ++ V_9 -> V_10 == 1 ;
}
static bool F_9 ( struct V_8 * V_9 )
{
F_10 ( V_9 -> V_10 < 1 ) ;
return -- V_9 -> V_10 == 0 ;
}
static bool F_11 ( struct V_8 * V_9 )
{
return V_9 -> V_10 > 0 ;
}
static void F_12 ( void T_4 * V_11 )
{
F_13 ( V_12 , V_11 + V_13 ) ;
}
static unsigned int F_14 ( struct V_8 * V_9 )
{
return F_15 ( F_16 ( V_9 -> V_11 + V_14 ) ) ;
}
static bool F_17 ( void T_4 * V_11 )
{
int V_15 = 120 ;
F_13 ( V_16 , V_11 + V_13 ) ;
while ( ( V_15 > 0 ) && ! ( F_16 ( V_11 + V_17 ) & 1 ) )
-- V_15 ;
if ( ! ( F_16 ( V_11 + V_17 ) & 1 ) ) {
F_12 ( V_11 ) ;
return false ;
}
return true ;
}
static void F_18 ( void T_4 * V_11 )
{
F_13 ( 0x1 , V_11 + V_18 ) ;
}
static void F_19 ( void T_4 * V_11 ,
T_2 V_1 , unsigned int V_19 )
{
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < V_19 ; V_15 ++ ) {
F_13 ( ( V_1 & V_20 ) | 1 ,
V_11 + V_21 ) ;
V_1 += V_22 ;
}
}
static void F_20 ( void T_4 * V_11 ,
T_5 V_23 )
{
F_13 ( V_23 , V_11 + V_24 ) ;
F_18 ( V_11 ) ;
}
static void F_21 ( const char * V_25 ,
enum V_26 V_27 ,
T_5 V_28 , T_2 V_29 )
{
T_3 * V_30 ;
if ( ( V_27 >= V_31 ) || ( V_27 < V_32 ) )
V_27 = V_33 ;
F_22 ( L_1 ,
V_34 [ V_27 ] , V_29 , V_25 , & V_28 ) ;
V_30 = F_4 ( F_6 ( V_28 ) , V_29 ) ;
F_22 ( L_2 , * V_30 ) ;
if ( F_23 ( V_30 ) ) {
V_30 = F_5 ( V_30 , V_29 ) ;
F_22 ( L_3 , * V_30 ) ;
}
}
static T_6 F_24 ( int V_35 , void * V_36 )
{
struct V_8 * V_9 = V_36 ;
enum V_26 V_27 ;
T_2 V_37 = - 1 ;
int V_38 = - V_39 ;
F_25 ( ! F_11 ( V_9 ) ) ;
F_26 ( & V_9 -> V_40 ) ;
if ( ! F_27 ( V_9 -> V_41 ) )
F_28 ( V_9 -> V_41 ) ;
V_27 = (enum V_26 )
F_29 ( F_16 ( V_9 -> V_11 + V_42 ) ) ;
if ( F_25 ( ! ( ( V_27 >= 0 ) && ( V_27 < V_33 ) ) ) )
V_27 = V_33 ;
else
V_37 = F_16 ( V_9 -> V_11 + V_43 [ V_27 ] ) ;
if ( V_27 == V_33 ) {
F_22 ( L_4 ,
V_44 , F_30 ( V_9 -> V_45 ) ) ;
F_22 ( L_5 ,
V_44 ) ;
F_31 () ;
} else {
unsigned int V_46 =
F_16 ( V_9 -> V_11 + V_24 ) ;
F_21 ( F_30 ( V_9 -> V_45 ) ,
V_27 , V_46 , V_37 ) ;
if ( V_9 -> V_47 )
V_38 = F_32 ( V_9 -> V_47 ,
V_9 -> V_48 , V_37 , V_27 ) ;
}
F_10 ( V_38 != 0 ) ;
F_13 ( 1 << V_27 , V_9 -> V_11 + V_49 ) ;
F_12 ( V_9 -> V_11 ) ;
if ( ! F_27 ( V_9 -> V_41 ) )
F_33 ( V_9 -> V_41 ) ;
F_34 ( & V_9 -> V_40 ) ;
return V_50 ;
}
static void F_35 ( struct V_8 * V_9 )
{
if ( ! F_27 ( V_9 -> V_41 ) )
F_28 ( V_9 -> V_41 ) ;
F_13 ( V_51 , V_9 -> V_11 + V_13 ) ;
F_13 ( 0 , V_9 -> V_11 + V_52 ) ;
F_33 ( V_9 -> V_53 ) ;
if ( ! F_27 ( V_9 -> V_41 ) )
F_33 ( V_9 -> V_41 ) ;
}
static bool F_36 ( struct V_8 * V_9 )
{
bool V_54 ;
unsigned long V_55 ;
F_37 ( & V_9 -> V_40 , V_55 ) ;
V_54 = F_9 ( V_9 ) ;
if ( V_54 ) {
V_9 -> V_6 = 0 ;
V_9 -> V_47 = NULL ;
F_35 ( V_9 ) ;
F_38 ( V_9 -> V_45 , L_6 ) ;
} else {
F_38 ( V_9 -> V_45 , L_7 ,
V_9 -> V_10 ) ;
}
F_39 ( & V_9 -> V_40 , V_55 ) ;
return V_54 ;
}
static void F_40 ( struct V_8 * V_9 )
{
unsigned int V_56 = V_57 | F_41 ( 15 ) ;
unsigned int V_58 ;
V_58 = F_14 ( V_9 ) ;
if ( F_42 ( V_58 ) == 3 ) {
if ( F_43 ( V_58 ) >= 2 ) {
V_56 |= V_59 ;
if ( F_43 ( V_58 ) == 3 ) {
V_56 |= V_60 ;
V_56 &= ~ V_57 ;
} else {
V_56 |= V_61 ;
}
}
}
F_13 ( V_56 , V_9 -> V_11 + V_52 ) ;
}
static void F_44 ( struct V_8 * V_9 )
{
if ( ! F_27 ( V_9 -> V_41 ) )
F_28 ( V_9 -> V_41 ) ;
F_28 ( V_9 -> V_53 ) ;
F_13 ( V_16 , V_9 -> V_11 + V_13 ) ;
F_40 ( V_9 ) ;
F_20 ( V_9 -> V_11 , V_9 -> V_6 ) ;
F_13 ( V_12 , V_9 -> V_11 + V_13 ) ;
if ( ! F_27 ( V_9 -> V_41 ) )
F_33 ( V_9 -> V_41 ) ;
}
static int F_45 ( struct V_8 * V_9 ,
T_5 V_6 , struct V_62 * V_47 )
{
int V_38 = 0 ;
unsigned long V_55 ;
F_37 ( & V_9 -> V_40 , V_55 ) ;
if ( F_8 ( V_9 ) ) {
V_9 -> V_6 = V_6 ;
V_9 -> V_47 = V_47 ;
F_44 ( V_9 ) ;
F_38 ( V_9 -> V_45 , L_8 ) ;
} else {
V_38 = ( V_6 == V_9 -> V_6 ) ? 1 : - V_63 ;
F_38 ( V_9 -> V_45 , L_9 ) ;
}
if ( F_25 ( V_38 < 0 ) )
F_9 ( V_9 ) ;
F_39 ( & V_9 -> V_40 , V_55 ) ;
return V_38 ;
}
static int F_46 ( struct V_64 * V_65 , T_5 V_6 ,
struct V_62 * V_47 )
{
int V_38 = 0 ;
unsigned long V_55 ;
struct V_66 * V_67 = V_65 -> V_68 . V_69 ;
struct V_8 * V_9 ;
F_10 ( ! F_47 ( V_65 ) ) ;
F_37 ( & V_67 -> V_40 , V_55 ) ;
V_9 = F_48 ( V_67 -> V_45 ) ;
V_38 = F_45 ( V_9 , V_6 , V_47 ) ;
if ( V_38 >= 0 )
V_9 -> V_48 = V_65 ;
F_39 ( & V_67 -> V_40 , V_55 ) ;
return V_38 ;
}
int F_49 ( struct V_64 * V_65 , T_5 V_6 )
{
F_10 ( ! F_50 ( V_6 ) ) ;
return F_46 ( V_65 , V_6 , NULL ) ;
}
static bool F_51 ( struct V_64 * V_65 )
{
unsigned long V_55 ;
bool V_54 = true ;
struct V_66 * V_67 = V_65 -> V_68 . V_69 ;
struct V_8 * V_9 ;
F_10 ( ! F_47 ( V_65 ) ) ;
F_37 ( & V_67 -> V_40 , V_55 ) ;
V_9 = F_48 ( V_67 -> V_45 ) ;
V_54 = F_36 ( V_9 ) ;
if ( V_54 )
V_9 -> V_48 = NULL ;
F_39 ( & V_67 -> V_40 , V_55 ) ;
return V_54 ;
}
static void F_52 ( struct V_8 * V_9 ,
T_2 V_1 )
{
if ( F_14 ( V_9 ) == F_53 ( 3 , 3 ) )
F_13 ( V_1 | 0x1 , V_9 -> V_11 + V_21 ) ;
}
static void F_54 ( struct V_64 * V_65 ,
T_2 V_1 )
{
unsigned long V_55 ;
struct V_66 * V_67 = V_65 -> V_68 . V_69 ;
struct V_8 * V_9 = F_48 ( V_67 -> V_45 ) ;
if ( ! F_27 ( V_9 -> V_41 ) )
F_28 ( V_9 -> V_41 ) ;
F_37 ( & V_9 -> V_40 , V_55 ) ;
if ( F_11 ( V_9 ) )
F_52 ( V_9 , V_1 ) ;
F_39 ( & V_9 -> V_40 , V_55 ) ;
if ( ! F_27 ( V_9 -> V_41 ) )
F_33 ( V_9 -> V_41 ) ;
}
static void F_55 ( struct V_64 * V_65 , T_2 V_1 ,
T_7 V_2 )
{
struct V_66 * V_67 = V_65 -> V_68 . V_69 ;
unsigned long V_55 ;
struct V_8 * V_9 ;
V_9 = F_48 ( V_67 -> V_45 ) ;
F_37 ( & V_9 -> V_40 , V_55 ) ;
if ( F_11 ( V_9 ) ) {
unsigned int V_19 = 1 ;
if ( ! F_27 ( V_9 -> V_41 ) )
F_28 ( V_9 -> V_41 ) ;
if ( F_42 ( F_14 ( V_9 ) ) == 2 )
V_19 = F_56 (unsigned int, size / PAGE_SIZE, 64 ) ;
if ( F_17 ( V_9 -> V_11 ) ) {
F_19 (
V_9 -> V_11 , V_1 , V_19 ) ;
F_12 ( V_9 -> V_11 ) ;
}
if ( ! F_27 ( V_9 -> V_41 ) )
F_33 ( V_9 -> V_41 ) ;
} else {
F_38 ( V_65 , L_10 ,
V_1 ) ;
}
F_39 ( & V_9 -> V_40 , V_55 ) ;
}
void F_57 ( struct V_64 * V_65 )
{
struct V_66 * V_67 = V_65 -> V_68 . V_69 ;
unsigned long V_55 ;
struct V_8 * V_9 ;
V_9 = F_48 ( V_67 -> V_45 ) ;
F_37 ( & V_9 -> V_40 , V_55 ) ;
if ( F_11 ( V_9 ) ) {
if ( ! F_27 ( V_9 -> V_41 ) )
F_28 ( V_9 -> V_41 ) ;
if ( F_17 ( V_9 -> V_11 ) ) {
F_18 ( V_9 -> V_11 ) ;
F_12 ( V_9 -> V_11 ) ;
}
if ( ! F_27 ( V_9 -> V_41 ) )
F_33 ( V_9 -> V_41 ) ;
} else {
F_38 ( V_65 , L_11 ) ;
}
F_39 ( & V_9 -> V_40 , V_55 ) ;
}
static int T_8 F_58 ( struct V_70 * V_71 )
{
int V_35 , V_38 ;
struct V_64 * V_65 = & V_71 -> V_65 ;
struct V_8 * V_9 ;
struct V_72 * V_73 ;
V_9 = F_59 ( V_65 , sizeof( * V_9 ) , V_74 ) ;
if ( ! V_9 )
return - V_75 ;
V_73 = F_60 ( V_71 , V_76 , 0 ) ;
V_9 -> V_11 = F_61 ( V_65 , V_73 ) ;
if ( F_27 ( V_9 -> V_11 ) )
return F_62 ( V_9 -> V_11 ) ;
V_35 = F_63 ( V_71 , 0 ) ;
if ( V_35 <= 0 ) {
F_64 ( V_65 , L_12 ) ;
return V_35 ;
}
V_38 = F_65 ( V_65 , V_35 , F_24 , 0 ,
F_30 ( V_65 ) , V_9 ) ;
if ( V_38 ) {
F_64 ( V_65 , L_13 , V_35 ) ;
return V_38 ;
}
V_9 -> V_53 = F_66 ( V_65 , L_14 ) ;
if ( F_27 ( V_9 -> V_53 ) ) {
F_64 ( V_65 , L_15 ) ;
return F_62 ( V_9 -> V_53 ) ;
} else {
V_38 = F_67 ( V_9 -> V_53 ) ;
if ( V_38 ) {
F_64 ( V_65 , L_16 ) ;
return V_38 ;
}
}
V_9 -> V_41 = F_66 ( V_65 , L_17 ) ;
if ( ! F_27 ( V_9 -> V_41 ) ) {
V_38 = F_67 ( V_9 -> V_41 ) ;
if ( V_38 ) {
F_68 ( V_9 -> V_53 ) ;
F_64 ( V_65 , L_18 ) ;
return V_38 ;
}
}
V_9 -> V_45 = V_65 ;
F_69 ( & V_9 -> V_40 ) ;
F_70 ( V_71 , V_9 ) ;
F_71 ( V_65 ) ;
return 0 ;
}
static inline void F_72 ( void * V_77 , void * V_78 )
{
F_73 ( V_77 , V_78 ) ;
F_74 ( F_75 ( V_77 ) ,
F_75 ( V_78 ) ) ;
}
static int F_76 ( struct V_62 * V_47 )
{
struct V_79 * V_80 ;
int V_15 ;
V_80 = F_77 ( sizeof( * V_80 ) , V_74 ) ;
if ( ! V_80 )
return - V_75 ;
V_80 -> V_6 = ( T_3 * ) F_78 ( V_74 , 2 ) ;
if ( ! V_80 -> V_6 )
goto V_81;
V_80 -> V_82 = ( short * ) F_78 ( V_74 | V_83 , 1 ) ;
if ( ! V_80 -> V_82 )
goto V_84;
for ( V_15 = 0 ; V_15 < V_85 ; V_15 += 8 ) {
V_80 -> V_6 [ V_15 + 0 ] = V_86 ;
V_80 -> V_6 [ V_15 + 1 ] = V_86 ;
V_80 -> V_6 [ V_15 + 2 ] = V_86 ;
V_80 -> V_6 [ V_15 + 3 ] = V_86 ;
V_80 -> V_6 [ V_15 + 4 ] = V_86 ;
V_80 -> V_6 [ V_15 + 5 ] = V_86 ;
V_80 -> V_6 [ V_15 + 6 ] = V_86 ;
V_80 -> V_6 [ V_15 + 7 ] = V_86 ;
}
F_72 ( V_80 -> V_6 , V_80 -> V_6 + V_85 ) ;
F_69 ( & V_80 -> V_40 ) ;
F_69 ( & V_80 -> V_87 ) ;
F_79 ( & V_80 -> V_88 ) ;
V_47 -> V_89 . V_90 = 0 ;
V_47 -> V_89 . V_91 = ~ 0UL ;
V_47 -> V_89 . V_92 = true ;
V_47 -> V_80 = V_80 ;
return 0 ;
V_84:
F_80 ( ( unsigned long ) V_80 -> V_6 , 2 ) ;
V_81:
F_81 ( V_80 ) ;
return - V_75 ;
}
static void F_82 ( struct V_62 * V_47 )
{
struct V_79 * V_80 = V_47 -> V_80 ;
struct V_66 * V_67 ;
unsigned long V_55 ;
int V_15 ;
F_25 ( ! F_83 ( & V_80 -> V_88 ) ) ;
F_37 ( & V_80 -> V_40 , V_55 ) ;
F_84 (owner, &priv->clients, client) {
while ( ! F_51 ( V_67 -> V_65 ) )
;
}
while ( ! F_83 ( & V_80 -> V_88 ) )
F_85 ( V_80 -> V_88 . V_93 ) ;
F_39 ( & V_80 -> V_40 , V_55 ) ;
for ( V_15 = 0 ; V_15 < V_85 ; V_15 ++ )
if ( F_23 ( V_80 -> V_6 + V_15 ) )
F_86 ( V_94 ,
F_6 ( F_7 ( V_80 -> V_6 + V_15 ) ) ) ;
F_80 ( ( unsigned long ) V_80 -> V_6 , 2 ) ;
F_80 ( ( unsigned long ) V_80 -> V_82 , 1 ) ;
F_81 ( V_47 -> V_80 ) ;
V_47 -> V_80 = NULL ;
}
static int F_87 ( struct V_62 * V_47 ,
struct V_64 * V_65 )
{
struct V_66 * V_67 = V_65 -> V_68 . V_69 ;
struct V_79 * V_80 = V_47 -> V_80 ;
T_5 V_95 = F_75 ( V_80 -> V_6 ) ;
unsigned long V_55 ;
int V_38 ;
F_37 ( & V_80 -> V_40 , V_55 ) ;
V_38 = F_46 ( V_65 , V_95 , V_47 ) ;
if ( V_38 == 0 ) {
F_88 ( & V_67 -> V_96 , & V_80 -> V_88 ) ;
V_67 -> V_47 = V_47 ;
}
F_39 ( & V_80 -> V_40 , V_55 ) ;
if ( V_38 < 0 ) {
F_64 ( V_65 , L_19 ,
V_44 , & V_95 ) ;
return V_38 ;
}
F_38 ( V_65 , L_20 ,
V_44 , & V_95 , ( V_38 == 0 ) ? L_21 : L_22 ) ;
return V_38 ;
}
static void F_89 ( struct V_62 * V_47 ,
struct V_64 * V_65 )
{
struct V_66 * V_67 ;
struct V_79 * V_80 = V_47 -> V_80 ;
T_5 V_95 = F_75 ( V_80 -> V_6 ) ;
unsigned long V_55 ;
F_37 ( & V_80 -> V_40 , V_55 ) ;
F_84 (owner, &priv->clients, client) {
if ( V_67 == V_65 -> V_68 . V_69 ) {
if ( F_51 ( V_65 ) ) {
F_85 ( & V_67 -> V_96 ) ;
V_67 -> V_47 = NULL ;
}
break;
}
}
F_39 ( & V_80 -> V_40 , V_55 ) ;
if ( V_67 == V_65 -> V_68 . V_69 )
F_38 ( V_65 , L_23 ,
V_44 , & V_95 ) ;
else
F_64 ( V_65 , L_24 , V_44 ) ;
}
static T_3 * F_90 ( struct V_79 * V_80 ,
T_3 * V_7 , T_2 V_1 , short * V_97 )
{
if ( F_91 ( V_7 ) ) {
F_92 ( 1 , L_25 , V_1 ) ;
return F_93 ( - V_98 ) ;
}
if ( F_94 ( V_7 ) ) {
T_3 * V_99 ;
bool V_100 = F_95 ( V_7 ) ;
V_99 = F_96 ( V_94 , V_101 ) ;
F_10 ( ( unsigned int ) V_99 & ( V_102 - 1 ) ) ;
if ( ! V_99 )
return F_93 ( - V_75 ) ;
* V_7 = F_97 ( F_75 ( V_99 ) ) ;
* V_97 = V_5 ;
F_72 ( V_99 , V_99 + V_5 ) ;
F_72 ( V_7 , V_7 + 1 ) ;
if ( V_100 ) {
struct V_66 * V_67 ;
F_26 ( & V_80 -> V_40 ) ;
F_84 (owner, &priv->clients, client)
F_54 (
V_67 -> V_65 , V_1 ) ;
F_34 ( & V_80 -> V_40 ) ;
}
}
return F_5 ( V_7 , V_1 ) ;
}
static int F_98 ( struct V_79 * V_80 ,
T_3 * V_7 , T_2 V_1 ,
T_5 V_103 , short * V_104 )
{
if ( F_91 ( V_7 ) ) {
F_92 ( 1 , L_26 ,
V_1 ) ;
return - V_98 ;
}
if ( F_23 ( V_7 ) ) {
if ( * V_104 != V_5 ) {
F_92 ( 1 , L_26 ,
V_1 ) ;
return - V_98 ;
}
F_86 ( V_94 , F_5 ( V_7 , 0 ) ) ;
* V_104 = 0 ;
}
* V_7 = F_99 ( V_103 ) ;
F_72 ( V_7 , V_7 + 1 ) ;
F_26 ( & V_80 -> V_40 ) ;
if ( F_100 ( V_7 ) ) {
struct V_66 * V_67 ;
F_84 (owner, &priv->clients, client)
F_54 ( V_67 -> V_65 , V_1 ) ;
}
F_34 ( & V_80 -> V_40 ) ;
return 0 ;
}
static int F_101 ( T_3 * V_99 , T_5 V_103 , T_7 V_2 ,
short * V_104 )
{
if ( V_2 == V_22 ) {
if ( F_25 ( ! F_102 ( V_99 ) ) )
return - V_98 ;
* V_99 = F_103 ( V_103 ) ;
F_72 ( V_99 , V_99 + 1 ) ;
* V_104 -= 1 ;
} else {
int V_15 ;
for ( V_15 = 0 ; V_15 < V_105 ; V_15 ++ , V_99 ++ ) {
if ( F_25 ( ! F_102 ( V_99 ) ) ) {
if ( V_15 > 0 )
memset ( V_99 - V_15 , 0 , sizeof( * V_99 ) * V_15 ) ;
return - V_98 ;
}
* V_99 = F_104 ( V_103 ) ;
}
F_72 ( V_99 - V_105 , V_99 ) ;
* V_104 -= V_105 ;
}
return 0 ;
}
static int F_105 ( struct V_62 * V_47 , unsigned long V_106 ,
T_5 V_103 , T_7 V_2 , int V_107 )
{
struct V_79 * V_80 = V_47 -> V_80 ;
T_3 * V_108 ;
T_2 V_1 = ( T_2 ) V_106 ;
unsigned long V_55 ;
int V_38 = - V_75 ;
F_10 ( V_80 -> V_6 == NULL ) ;
F_37 ( & V_80 -> V_87 , V_55 ) ;
V_108 = F_4 ( V_80 -> V_6 , V_1 ) ;
if ( V_2 == V_109 ) {
V_38 = F_98 ( V_80 , V_108 , V_1 , V_103 ,
& V_80 -> V_82 [ F_2 ( V_1 ) ] ) ;
} else {
T_3 * V_99 ;
V_99 = F_90 ( V_80 , V_108 , V_1 ,
& V_80 -> V_82 [ F_2 ( V_1 ) ] ) ;
if ( F_27 ( V_99 ) )
V_38 = F_62 ( V_99 ) ;
else
V_38 = F_101 ( V_99 , V_103 , V_2 ,
& V_80 -> V_82 [ F_2 ( V_1 ) ] ) ;
}
if ( V_38 )
F_22 ( L_27 ,
V_44 , V_38 , V_2 , V_1 ) ;
F_39 ( & V_80 -> V_87 , V_55 ) ;
return V_38 ;
}
static void F_106 ( struct V_79 * V_80 ,
T_2 V_1 , T_7 V_2 )
{
struct V_66 * V_67 ;
unsigned long V_55 ;
F_37 ( & V_80 -> V_40 , V_55 ) ;
F_84 (owner, &priv->clients, client)
F_55 ( V_67 -> V_65 , V_1 , V_2 ) ;
F_39 ( & V_80 -> V_40 , V_55 ) ;
}
static T_7 F_107 ( struct V_62 * V_47 ,
unsigned long V_106 , T_7 V_2 )
{
struct V_79 * V_80 = V_47 -> V_80 ;
T_2 V_1 = ( T_2 ) V_106 ;
T_3 * V_30 ;
T_7 V_110 ;
unsigned long V_55 ;
F_10 ( V_80 -> V_6 == NULL ) ;
F_37 ( & V_80 -> V_87 , V_55 ) ;
V_30 = F_4 ( V_80 -> V_6 , V_1 ) ;
if ( F_91 ( V_30 ) ) {
if ( F_25 ( V_2 < V_109 ) ) {
V_110 = V_109 ;
goto V_111;
}
* V_30 = V_86 ;
F_72 ( V_30 , V_30 + 1 ) ;
V_2 = V_109 ;
goto V_112;
}
if ( F_108 ( F_94 ( V_30 ) ) ) {
if ( V_2 > V_109 )
V_2 = V_109 ;
goto V_112;
}
V_30 = F_5 ( V_30 , V_1 ) ;
if ( F_108 ( F_102 ( V_30 ) ) ) {
V_2 = V_22 ;
goto V_112;
}
if ( F_109 ( V_30 ) ) {
* V_30 = 0 ;
V_2 = V_22 ;
F_72 ( V_30 , V_30 + 1 ) ;
V_80 -> V_82 [ F_2 ( V_1 ) ] += 1 ;
goto V_112;
}
if ( F_25 ( V_2 < V_113 ) ) {
V_110 = V_113 ;
goto V_111;
}
memset ( V_30 , 0 , sizeof( * V_30 ) * V_105 ) ;
F_72 ( V_30 , V_30 + V_105 ) ;
V_2 = V_113 ;
V_80 -> V_82 [ F_2 ( V_1 ) ] += V_105 ;
V_112:
F_39 ( & V_80 -> V_87 , V_55 ) ;
F_106 ( V_80 , V_1 , V_2 ) ;
return V_2 ;
V_111:
F_39 ( & V_80 -> V_87 , V_55 ) ;
F_22 ( L_28 ,
V_44 , V_2 , V_1 , V_110 ) ;
return 0 ;
}
static T_5 F_110 ( struct V_62 * V_47 ,
T_9 V_1 )
{
struct V_79 * V_80 = V_47 -> V_80 ;
T_3 * V_108 ;
unsigned long V_55 ;
T_5 V_114 = 0 ;
F_37 ( & V_80 -> V_87 , V_55 ) ;
V_108 = F_4 ( V_80 -> V_6 , V_1 ) ;
if ( F_91 ( V_108 ) ) {
V_114 = F_111 ( V_108 ) + F_112 ( V_1 ) ;
} else if ( F_23 ( V_108 ) ) {
V_108 = F_5 ( V_108 , V_1 ) ;
if ( F_113 ( V_108 ) )
V_114 = F_114 ( V_108 ) + F_115 ( V_1 ) ;
else if ( F_109 ( V_108 ) )
V_114 = F_116 ( V_108 ) + F_117 ( V_1 ) ;
}
F_39 ( & V_80 -> V_87 , V_55 ) ;
return V_114 ;
}
static int F_118 ( struct V_64 * V_65 )
{
struct V_115 * V_116 ;
int V_38 ;
V_116 = F_119 ( V_65 ) ;
if ( ! V_116 ) {
V_116 = F_120 () ;
if ( F_27 ( V_116 ) ) {
F_64 ( V_65 , L_29 ) ;
return F_62 ( V_116 ) ;
}
}
V_38 = F_121 ( V_116 , V_65 ) ;
F_122 ( V_116 ) ;
return V_38 ;
}
static void F_123 ( struct V_64 * V_65 )
{
F_124 ( V_65 ) ;
}
static int T_8 F_125 ( void )
{
struct V_117 * V_118 ;
int V_38 ;
V_118 = F_126 ( NULL , V_119 ) ;
if ( ! V_118 )
return 0 ;
F_127 ( V_118 ) ;
V_94 = F_128 ( L_30 ,
V_102 , V_102 , 0 , NULL ) ;
if ( ! V_94 ) {
F_22 ( L_31 , V_44 ) ;
return - V_75 ;
}
V_38 = F_129 ( & V_120 ) ;
if ( V_38 ) {
F_22 ( L_32 , V_44 ) ;
goto V_121;
}
V_122 = F_96 ( V_94 , V_74 ) ;
if ( V_122 == NULL ) {
F_22 ( L_33 ,
V_44 ) ;
V_38 = - V_75 ;
goto V_123;
}
V_38 = F_130 ( & V_124 , & V_125 ) ;
if ( V_38 ) {
F_22 ( L_34 ,
V_44 ) ;
goto V_126;
}
return 0 ;
V_126:
F_86 ( V_94 , V_122 ) ;
V_123:
F_131 ( & V_120 ) ;
V_121:
F_132 ( V_94 ) ;
return V_38 ;
}
