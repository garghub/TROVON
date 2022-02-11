static T_1 F_1 ( T_2 V_1 )
{
return V_1 >> V_2 ;
}
static T_1 F_2 ( T_2 V_1 )
{
return ( V_1 >> V_3 ) & ( V_4 - 1 ) ;
}
static T_3 * F_3 ( T_3 * V_5 , T_2 V_1 )
{
return V_5 + F_1 ( V_1 ) ;
}
static T_3 * F_4 ( T_3 * V_6 , T_2 V_1 )
{
return ( T_3 * ) F_5 (
F_6 ( V_6 ) ) + F_2 ( V_1 ) ;
}
static struct V_7 * F_7 ( struct V_8 * V_9 )
{
return F_8 ( V_9 , struct V_7 , V_10 ) ;
}
static bool F_9 ( struct V_11 * V_12 )
{
return ++ V_12 -> V_13 == 1 ;
}
static bool F_10 ( struct V_11 * V_12 )
{
F_11 ( V_12 -> V_13 < 1 ) ;
return -- V_12 -> V_13 == 0 ;
}
static bool F_12 ( struct V_11 * V_12 )
{
return V_12 -> V_13 > 0 ;
}
static void F_13 ( struct V_11 * V_12 )
{
F_14 ( V_14 , V_12 -> V_15 + V_16 ) ;
}
static bool F_15 ( struct V_11 * V_12 )
{
int V_17 = 120 ;
F_14 ( V_18 , V_12 -> V_15 + V_16 ) ;
while ( ( V_17 > 0 ) && ! ( F_16 ( V_12 -> V_15 + V_19 ) & 1 ) )
-- V_17 ;
if ( ! ( F_16 ( V_12 -> V_15 + V_19 ) & 1 ) ) {
F_13 ( V_12 ) ;
return false ;
}
return true ;
}
static void F_17 ( struct V_11 * V_12 )
{
if ( F_18 ( V_12 -> V_20 ) < 5 )
F_14 ( 0x1 , V_12 -> V_15 + V_21 ) ;
else
F_14 ( 0x1 , V_12 -> V_15 + V_22 ) ;
}
static void F_19 ( struct V_11 * V_12 ,
T_2 V_1 , unsigned int V_23 )
{
unsigned int V_17 ;
for ( V_17 = 0 ; V_17 < V_23 ; V_17 ++ ) {
if ( F_18 ( V_12 -> V_20 ) < 5 )
F_14 ( ( V_1 & V_24 ) | 1 ,
V_12 -> V_15 + V_25 ) ;
else
F_14 ( ( V_1 & V_24 ) | 1 ,
V_12 -> V_15 + V_26 ) ;
V_1 += V_27 ;
}
}
static void F_20 ( struct V_11 * V_12 , T_4 V_28 )
{
if ( F_18 ( V_12 -> V_20 ) < 5 )
F_14 ( V_28 , V_12 -> V_15 + V_29 ) ;
else
F_14 ( V_28 >> V_30 ,
V_12 -> V_15 + V_31 ) ;
F_17 ( V_12 ) ;
}
static void F_21 ( struct V_11 * V_12 )
{
T_1 V_32 ;
F_22 ( V_12 -> V_33 ) ;
F_22 ( V_12 -> V_34 ) ;
F_22 ( V_12 -> V_35 ) ;
F_22 ( V_12 -> V_36 ) ;
V_32 = F_16 ( V_12 -> V_15 + V_37 ) ;
if ( V_32 == 0x80000001u )
V_12 -> V_20 = F_23 ( 1 , 0 ) ;
else
V_12 -> V_20 = F_24 ( V_32 ) ;
F_25 ( V_12 -> V_38 , L_1 ,
F_18 ( V_12 -> V_20 ) , F_26 ( V_12 -> V_20 ) ) ;
F_27 ( V_12 -> V_36 ) ;
F_27 ( V_12 -> V_35 ) ;
F_27 ( V_12 -> V_34 ) ;
F_27 ( V_12 -> V_33 ) ;
}
static void F_28 ( struct V_11 * V_12 ,
const struct V_39 * V_40 ,
T_2 V_41 )
{
T_3 * V_42 ;
F_29 ( V_12 -> V_38 , L_2 ,
V_40 -> V_43 , V_41 , & V_12 -> V_5 ) ;
V_42 = F_3 ( F_5 ( V_12 -> V_5 ) , V_41 ) ;
F_29 ( V_12 -> V_38 , L_3 , * V_42 ) ;
if ( F_30 ( V_42 ) ) {
V_42 = F_4 ( V_42 , V_41 ) ;
F_29 ( V_12 -> V_38 , L_4 , * V_42 ) ;
}
}
static T_5 F_31 ( int V_44 , void * V_45 )
{
struct V_11 * V_12 = V_45 ;
const struct V_39 * V_40 ;
unsigned int V_17 , V_46 , V_47 ;
T_2 V_41 = - 1 ;
unsigned short V_48 , V_49 ;
int V_50 = - V_51 ;
F_32 ( ! F_12 ( V_12 ) ) ;
if ( F_18 ( V_12 -> V_20 ) < 5 ) {
V_48 = V_52 ;
V_49 = V_53 ;
V_40 = V_54 ;
V_46 = F_33 ( V_54 ) ;
} else {
V_48 = V_55 ;
V_49 = V_56 ;
V_40 = V_57 ;
V_46 = F_33 ( V_57 ) ;
}
F_34 ( & V_12 -> V_58 ) ;
F_22 ( V_12 -> V_33 ) ;
V_47 = F_35 ( F_16 ( V_12 -> V_15 + V_48 ) ) ;
for ( V_17 = 0 ; V_17 < V_46 ; V_17 ++ , V_40 ++ )
if ( V_40 -> V_59 == V_47 )
break;
F_11 ( V_17 == V_46 ) ;
V_41 = F_16 ( V_12 -> V_15 + V_40 -> V_60 ) ;
F_28 ( V_12 , V_40 , V_41 ) ;
if ( V_12 -> V_10 )
V_50 = F_36 ( & V_12 -> V_10 -> V_10 ,
V_12 -> V_61 , V_41 , V_40 -> type ) ;
F_11 ( V_50 != 0 ) ;
F_14 ( 1 << V_47 , V_12 -> V_15 + V_49 ) ;
F_13 ( V_12 ) ;
F_27 ( V_12 -> V_33 ) ;
F_37 ( & V_12 -> V_58 ) ;
return V_62 ;
}
static void F_38 ( struct V_11 * V_12 )
{
F_22 ( V_12 -> V_33 ) ;
F_14 ( V_63 , V_12 -> V_15 + V_16 ) ;
F_14 ( 0 , V_12 -> V_15 + V_64 ) ;
F_27 ( V_12 -> V_36 ) ;
F_27 ( V_12 -> V_35 ) ;
F_27 ( V_12 -> V_34 ) ;
F_27 ( V_12 -> V_33 ) ;
}
static bool F_39 ( struct V_11 * V_12 )
{
bool V_65 ;
unsigned long V_66 ;
F_40 ( & V_12 -> V_58 , V_66 ) ;
V_65 = F_10 ( V_12 ) ;
if ( V_65 ) {
V_12 -> V_5 = 0 ;
V_12 -> V_10 = NULL ;
F_38 ( V_12 ) ;
F_25 ( V_12 -> V_38 , L_5 ) ;
} else {
F_25 ( V_12 -> V_38 , L_6 ,
V_12 -> V_13 ) ;
}
F_41 ( & V_12 -> V_58 , V_66 ) ;
return V_65 ;
}
static void F_42 ( struct V_11 * V_12 )
{
unsigned int V_67 ;
if ( V_12 -> V_20 <= F_23 ( 3 , 1 ) )
V_67 = V_68 | F_43 ( 15 ) ;
else if ( V_12 -> V_20 <= F_23 ( 3 , 2 ) )
V_67 = V_68 | F_43 ( 15 ) | V_69 | V_70 ;
else
V_67 = F_43 ( 15 ) | V_69 | V_71 ;
F_14 ( V_67 , V_12 -> V_15 + V_64 ) ;
}
static void F_44 ( struct V_11 * V_12 )
{
F_22 ( V_12 -> V_33 ) ;
F_22 ( V_12 -> V_34 ) ;
F_22 ( V_12 -> V_35 ) ;
F_22 ( V_12 -> V_36 ) ;
F_14 ( V_18 , V_12 -> V_15 + V_16 ) ;
F_42 ( V_12 ) ;
F_20 ( V_12 , V_12 -> V_5 ) ;
F_14 ( V_14 , V_12 -> V_15 + V_16 ) ;
F_27 ( V_12 -> V_33 ) ;
}
static int F_45 ( struct V_11 * V_12 , T_4 V_5 ,
struct V_7 * V_10 )
{
int V_50 = 0 ;
unsigned long V_66 ;
F_40 ( & V_12 -> V_58 , V_66 ) ;
if ( F_9 ( V_12 ) ) {
V_12 -> V_5 = V_5 ;
V_12 -> V_10 = V_10 ;
F_44 ( V_12 ) ;
F_25 ( V_12 -> V_38 , L_7 ) ;
} else {
V_50 = ( V_5 == V_12 -> V_5 ) ? 1 : - V_72 ;
F_25 ( V_12 -> V_38 , L_8 ) ;
}
if ( F_32 ( V_50 < 0 ) )
F_10 ( V_12 ) ;
F_41 ( & V_12 -> V_58 , V_66 ) ;
return V_50 ;
}
static void F_46 ( struct V_11 * V_12 ,
T_2 V_1 )
{
unsigned long V_66 ;
F_22 ( V_12 -> V_33 ) ;
F_40 ( & V_12 -> V_58 , V_66 ) ;
if ( F_12 ( V_12 ) ) {
if ( V_12 -> V_20 >= F_23 ( 3 , 3 ) )
F_19 ( V_12 , V_1 , 1 ) ;
}
F_41 ( & V_12 -> V_58 , V_66 ) ;
F_27 ( V_12 -> V_33 ) ;
}
static void F_47 ( struct V_11 * V_12 ,
T_2 V_1 , T_6 V_73 )
{
unsigned long V_66 ;
F_40 ( & V_12 -> V_58 , V_66 ) ;
if ( F_12 ( V_12 ) ) {
unsigned int V_23 = 1 ;
F_22 ( V_12 -> V_33 ) ;
if ( F_18 ( V_12 -> V_20 ) == 2 )
V_23 = F_48 (unsigned int, size / PAGE_SIZE, 64 ) ;
if ( F_15 ( V_12 ) ) {
F_19 ( V_12 , V_1 , V_23 ) ;
F_13 ( V_12 ) ;
}
F_27 ( V_12 -> V_33 ) ;
} else {
F_25 ( V_12 -> V_61 ,
L_9 , V_1 ) ;
}
F_41 ( & V_12 -> V_58 , V_66 ) ;
}
static int T_7 F_49 ( struct V_74 * V_75 )
{
int V_44 , V_50 ;
struct V_76 * V_77 = & V_75 -> V_77 ;
struct V_11 * V_12 ;
struct V_78 * V_79 ;
V_12 = F_50 ( V_77 , sizeof( * V_12 ) , V_80 ) ;
if ( ! V_12 )
return - V_81 ;
V_79 = F_51 ( V_75 , V_82 , 0 ) ;
V_12 -> V_15 = F_52 ( V_77 , V_79 ) ;
if ( F_53 ( V_12 -> V_15 ) )
return F_54 ( V_12 -> V_15 ) ;
V_44 = F_55 ( V_75 , 0 ) ;
if ( V_44 <= 0 ) {
F_29 ( V_77 , L_10 ) ;
return V_44 ;
}
V_50 = F_56 ( V_77 , V_44 , F_31 , 0 ,
F_57 ( V_77 ) , V_12 ) ;
if ( V_50 ) {
F_29 ( V_77 , L_11 , V_44 ) ;
return V_50 ;
}
V_12 -> V_34 = F_58 ( V_77 , L_12 ) ;
if ( ! F_53 ( V_12 -> V_34 ) ) {
V_50 = F_59 ( V_12 -> V_34 ) ;
if ( V_50 ) {
F_29 ( V_77 , L_13 ) ;
return V_50 ;
}
} else {
V_12 -> V_34 = NULL ;
}
V_12 -> V_36 = F_58 ( V_77 , L_14 ) ;
if ( ! F_53 ( V_12 -> V_36 ) ) {
V_50 = F_59 ( V_12 -> V_36 ) ;
if ( V_50 ) {
F_29 ( V_77 , L_15 ) ;
return V_50 ;
}
} else {
V_12 -> V_36 = NULL ;
}
V_12 -> V_35 = F_58 ( V_77 , L_16 ) ;
if ( ! F_53 ( V_12 -> V_35 ) ) {
V_50 = F_59 ( V_12 -> V_35 ) ;
if ( V_50 ) {
F_29 ( V_77 , L_17 ) ;
return V_50 ;
}
} else {
V_12 -> V_35 = NULL ;
}
if ( ! V_12 -> V_34 && ( ! V_12 -> V_36 || ! V_12 -> V_35 ) ) {
F_29 ( V_77 , L_18 ) ;
return - V_51 ;
}
V_12 -> V_33 = F_58 ( V_77 , L_19 ) ;
if ( ! F_53 ( V_12 -> V_33 ) ) {
V_50 = F_59 ( V_12 -> V_33 ) ;
if ( V_50 ) {
F_29 ( V_77 , L_20 ) ;
return V_50 ;
}
} else {
V_12 -> V_33 = NULL ;
}
V_12 -> V_38 = V_77 ;
F_60 ( & V_12 -> V_58 ) ;
F_61 ( V_75 , V_12 ) ;
F_21 ( V_12 ) ;
if ( V_83 < 0 ) {
if ( F_18 ( V_12 -> V_20 ) < 5 )
V_83 = V_84 ;
else
V_83 = V_85 ;
}
F_62 ( V_77 ) ;
return 0 ;
}
static int F_63 ( struct V_76 * V_77 )
{
struct V_11 * V_12 = F_64 ( V_77 ) ;
F_25 ( V_77 , L_21 ) ;
if ( F_12 ( V_12 ) ) {
F_38 ( V_12 ) ;
F_65 ( V_77 ) ;
}
return 0 ;
}
static int F_66 ( struct V_76 * V_77 )
{
struct V_11 * V_12 = F_64 ( V_77 ) ;
F_25 ( V_77 , L_22 ) ;
if ( F_12 ( V_12 ) ) {
F_67 ( V_77 ) ;
F_44 ( V_12 ) ;
}
return 0 ;
}
static inline void F_68 ( T_3 * V_42 , T_3 V_86 )
{
F_69 ( V_87 , F_70 ( V_42 ) , sizeof( * V_42 ) ,
V_88 ) ;
* V_42 = V_86 ;
F_71 ( V_87 , F_70 ( V_42 ) , sizeof( * V_42 ) ,
V_88 ) ;
}
static struct V_8 * F_72 ( unsigned type )
{
struct V_7 * V_10 ;
T_8 V_89 ;
int V_17 ;
F_11 ( V_83 < 0 || ! V_87 ) ;
V_10 = F_73 ( sizeof( * V_10 ) , V_80 ) ;
if ( ! V_10 )
return NULL ;
if ( type == V_90 ) {
if ( F_74 ( & V_10 -> V_10 ) != 0 )
goto V_91;
} else if ( type != V_92 ) {
goto V_91;
}
V_10 -> V_5 = ( T_3 * ) F_75 ( V_80 , 2 ) ;
if ( ! V_10 -> V_5 )
goto V_93;
V_10 -> V_94 = ( short * ) F_75 ( V_80 | V_95 , 1 ) ;
if ( ! V_10 -> V_94 )
goto V_96;
for ( V_17 = 0 ; V_17 < V_97 ; V_17 += 8 ) {
V_10 -> V_5 [ V_17 + 0 ] = V_98 ;
V_10 -> V_5 [ V_17 + 1 ] = V_98 ;
V_10 -> V_5 [ V_17 + 2 ] = V_98 ;
V_10 -> V_5 [ V_17 + 3 ] = V_98 ;
V_10 -> V_5 [ V_17 + 4 ] = V_98 ;
V_10 -> V_5 [ V_17 + 5 ] = V_98 ;
V_10 -> V_5 [ V_17 + 6 ] = V_98 ;
V_10 -> V_5 [ V_17 + 7 ] = V_98 ;
}
V_89 = F_76 ( V_87 , V_10 -> V_5 , V_99 ,
V_88 ) ;
F_11 ( V_89 != F_70 ( V_10 -> V_5 ) ) ;
F_60 ( & V_10 -> V_58 ) ;
F_60 ( & V_10 -> V_100 ) ;
F_77 ( & V_10 -> V_101 ) ;
V_10 -> V_10 . V_102 . V_103 = 0 ;
V_10 -> V_10 . V_102 . V_104 = ~ 0UL ;
V_10 -> V_10 . V_102 . V_105 = true ;
return & V_10 -> V_10 ;
V_96:
F_78 ( ( unsigned long ) V_10 -> V_5 , 2 ) ;
V_93:
if ( type == V_90 )
F_79 ( & V_10 -> V_10 ) ;
V_91:
F_80 ( V_10 ) ;
return NULL ;
}
static void F_81 ( struct V_8 * V_8 )
{
struct V_7 * V_10 = F_7 ( V_8 ) ;
struct V_11 * V_12 , * V_106 ;
unsigned long V_66 ;
int V_17 ;
F_32 ( ! F_82 ( & V_10 -> V_101 ) ) ;
F_40 ( & V_10 -> V_58 , V_66 ) ;
F_83 (data, next, &domain->clients, domain_node) {
if ( F_39 ( V_12 ) )
V_12 -> V_61 = NULL ;
F_84 ( & V_12 -> V_107 ) ;
}
F_41 ( & V_10 -> V_58 , V_66 ) ;
if ( V_8 -> type == V_90 )
F_79 ( V_8 ) ;
F_85 ( V_87 , F_70 ( V_10 -> V_5 ) , V_99 ,
V_88 ) ;
for ( V_17 = 0 ; V_17 < V_97 ; V_17 ++ )
if ( F_30 ( V_10 -> V_5 + V_17 ) ) {
T_4 V_108 = F_6 ( V_10 -> V_5 + V_17 ) ;
F_85 ( V_87 , V_108 , V_109 ,
V_88 ) ;
F_86 ( V_110 ,
F_5 ( V_108 ) ) ;
}
F_78 ( ( unsigned long ) V_10 -> V_5 , 2 ) ;
F_78 ( ( unsigned long ) V_10 -> V_94 , 1 ) ;
F_80 ( V_10 ) ;
}
static void F_87 ( struct V_8 * V_8 ,
struct V_76 * V_77 )
{
struct V_111 * V_112 = V_77 -> V_113 . V_114 ;
struct V_7 * V_10 = F_7 ( V_8 ) ;
T_4 V_115 = F_70 ( V_10 -> V_5 ) ;
struct V_11 * V_12 , * V_106 ;
unsigned long V_66 ;
bool V_116 = false ;
if ( ! F_88 ( V_77 ) || V_112 -> V_10 != V_8 )
return;
F_40 ( & V_10 -> V_58 , V_66 ) ;
F_83 (data, next, &domain->clients, domain_node) {
if ( V_12 -> V_61 == V_77 ) {
if ( F_39 ( V_12 ) ) {
V_12 -> V_61 = NULL ;
F_84 ( & V_12 -> V_107 ) ;
}
F_65 ( V_12 -> V_38 ) ;
V_116 = true ;
}
}
F_41 ( & V_10 -> V_58 , V_66 ) ;
V_112 -> V_10 = NULL ;
if ( V_116 )
F_25 ( V_77 , L_23 ,
V_117 , & V_115 ) ;
else
F_29 ( V_77 , L_24 , V_117 ) ;
}
static int F_89 ( struct V_8 * V_8 ,
struct V_76 * V_77 )
{
struct V_111 * V_112 = V_77 -> V_113 . V_114 ;
struct V_7 * V_10 = F_7 ( V_8 ) ;
struct V_11 * V_12 ;
T_4 V_115 = F_70 ( V_10 -> V_5 ) ;
unsigned long V_66 ;
int V_50 = - V_118 ;
if ( ! F_88 ( V_77 ) )
return - V_118 ;
if ( V_112 -> V_10 )
F_87 ( V_112 -> V_10 , V_77 ) ;
F_90 (data, &owner->controllers, owner_node) {
F_67 ( V_12 -> V_38 ) ;
V_50 = F_45 ( V_12 , V_115 , V_10 ) ;
if ( V_50 >= 0 ) {
V_12 -> V_61 = V_77 ;
F_40 ( & V_10 -> V_58 , V_66 ) ;
F_91 ( & V_12 -> V_107 , & V_10 -> V_101 ) ;
F_41 ( & V_10 -> V_58 , V_66 ) ;
}
}
if ( V_50 < 0 ) {
F_29 ( V_77 , L_25 ,
V_117 , & V_115 ) ;
return V_50 ;
}
V_112 -> V_10 = V_8 ;
F_25 ( V_77 , L_26 ,
V_117 , & V_115 , ( V_50 == 0 ) ? L_27 : L_28 ) ;
return V_50 ;
}
static T_3 * F_92 ( struct V_7 * V_10 ,
T_3 * V_6 , T_2 V_1 , short * V_119 )
{
if ( F_93 ( V_6 ) ) {
F_94 ( 1 , L_29 , V_1 ) ;
return F_95 ( - V_120 ) ;
}
if ( F_96 ( V_6 ) ) {
T_3 * V_121 ;
bool V_122 = F_97 ( V_6 ) ;
V_121 = F_98 ( V_110 , V_123 ) ;
F_11 ( ( V_124 ) V_121 & ( V_109 - 1 ) ) ;
if ( ! V_121 )
return F_95 ( - V_81 ) ;
F_68 ( V_6 , F_99 ( F_70 ( V_121 ) ) ) ;
F_100 ( V_121 ) ;
* V_119 = V_4 ;
F_76 ( V_87 , V_121 , V_109 , V_88 ) ;
if ( V_122 ) {
struct V_11 * V_12 ;
F_34 ( & V_10 -> V_58 ) ;
F_90 (data, &domain->clients, domain_node)
F_46 ( V_12 , V_1 ) ;
F_37 ( & V_10 -> V_58 ) ;
}
}
return F_4 ( V_6 , V_1 ) ;
}
static int F_101 ( struct V_7 * V_10 ,
T_3 * V_6 , T_2 V_1 ,
T_4 V_125 , short * V_126 )
{
if ( F_93 ( V_6 ) ) {
F_94 ( 1 , L_30 ,
V_1 ) ;
return - V_120 ;
}
if ( F_30 ( V_6 ) ) {
if ( * V_126 != V_4 ) {
F_94 ( 1 , L_30 ,
V_1 ) ;
return - V_120 ;
}
F_86 ( V_110 , F_4 ( V_6 , 0 ) ) ;
* V_126 = 0 ;
}
F_68 ( V_6 , F_102 ( V_125 ) ) ;
F_34 ( & V_10 -> V_58 ) ;
if ( F_103 ( V_6 ) ) {
struct V_11 * V_12 ;
F_90 (data, &domain->clients, domain_node)
F_46 ( V_12 , V_1 ) ;
}
F_37 ( & V_10 -> V_58 ) ;
return 0 ;
}
static int F_104 ( T_3 * V_121 , T_4 V_125 , T_6 V_73 ,
short * V_126 )
{
if ( V_73 == V_27 ) {
if ( F_32 ( ! F_105 ( V_121 ) ) )
return - V_120 ;
F_68 ( V_121 , F_106 ( V_125 ) ) ;
* V_126 -= 1 ;
} else {
int V_17 ;
T_8 V_127 = F_70 ( V_121 ) ;
F_69 ( V_87 , V_127 ,
sizeof( * V_121 ) * V_128 ,
V_88 ) ;
for ( V_17 = 0 ; V_17 < V_128 ; V_17 ++ , V_121 ++ ) {
if ( F_32 ( ! F_105 ( V_121 ) ) ) {
if ( V_17 > 0 )
memset ( V_121 - V_17 , 0 , sizeof( * V_121 ) * V_17 ) ;
return - V_120 ;
}
* V_121 = F_107 ( V_125 ) ;
}
F_71 ( V_87 , V_127 ,
sizeof( * V_121 ) * V_128 ,
V_88 ) ;
* V_126 -= V_128 ;
}
return 0 ;
}
static int F_108 ( struct V_8 * V_8 ,
unsigned long V_129 , T_4 V_125 , T_6 V_73 ,
int V_130 )
{
struct V_7 * V_10 = F_7 ( V_8 ) ;
T_3 * V_131 ;
T_2 V_1 = ( T_2 ) V_129 ;
unsigned long V_66 ;
int V_50 = - V_81 ;
F_11 ( V_10 -> V_5 == NULL ) ;
F_40 ( & V_10 -> V_100 , V_66 ) ;
V_131 = F_3 ( V_10 -> V_5 , V_1 ) ;
if ( V_73 == V_132 ) {
V_50 = F_101 ( V_10 , V_131 , V_1 , V_125 ,
& V_10 -> V_94 [ F_1 ( V_1 ) ] ) ;
} else {
T_3 * V_121 ;
V_121 = F_92 ( V_10 , V_131 , V_1 ,
& V_10 -> V_94 [ F_1 ( V_1 ) ] ) ;
if ( F_53 ( V_121 ) )
V_50 = F_54 ( V_121 ) ;
else
V_50 = F_104 ( V_121 , V_125 , V_73 ,
& V_10 -> V_94 [ F_1 ( V_1 ) ] ) ;
}
if ( V_50 )
F_109 ( L_31 ,
V_117 , V_50 , V_73 , V_1 ) ;
F_41 ( & V_10 -> V_100 , V_66 ) ;
return V_50 ;
}
static void F_110 ( struct V_7 * V_10 ,
T_2 V_1 , T_6 V_73 )
{
struct V_11 * V_12 ;
unsigned long V_66 ;
F_40 ( & V_10 -> V_58 , V_66 ) ;
F_90 (data, &domain->clients, domain_node)
F_47 ( V_12 , V_1 , V_73 ) ;
F_41 ( & V_10 -> V_58 , V_66 ) ;
}
static T_6 F_111 ( struct V_8 * V_8 ,
unsigned long V_129 , T_6 V_73 )
{
struct V_7 * V_10 = F_7 ( V_8 ) ;
T_2 V_1 = ( T_2 ) V_129 ;
T_3 * V_42 ;
T_6 V_133 ;
unsigned long V_66 ;
F_11 ( V_10 -> V_5 == NULL ) ;
F_40 ( & V_10 -> V_100 , V_66 ) ;
V_42 = F_3 ( V_10 -> V_5 , V_1 ) ;
if ( F_93 ( V_42 ) ) {
if ( F_32 ( V_73 < V_132 ) ) {
V_133 = V_132 ;
goto V_134;
}
F_68 ( V_42 , V_98 ) ;
V_73 = V_132 ;
goto V_135;
}
if ( F_112 ( F_96 ( V_42 ) ) ) {
if ( V_73 > V_132 )
V_73 = V_132 ;
goto V_135;
}
V_42 = F_4 ( V_42 , V_1 ) ;
if ( F_112 ( F_105 ( V_42 ) ) ) {
V_73 = V_27 ;
goto V_135;
}
if ( F_113 ( V_42 ) ) {
F_68 ( V_42 , 0 ) ;
V_73 = V_27 ;
V_10 -> V_94 [ F_1 ( V_1 ) ] += 1 ;
goto V_135;
}
if ( F_32 ( V_73 < V_136 ) ) {
V_133 = V_136 ;
goto V_134;
}
F_69 ( V_87 , F_70 ( V_42 ) ,
sizeof( * V_42 ) * V_128 ,
V_88 ) ;
memset ( V_42 , 0 , sizeof( * V_42 ) * V_128 ) ;
F_71 ( V_87 , F_70 ( V_42 ) ,
sizeof( * V_42 ) * V_128 ,
V_88 ) ;
V_73 = V_136 ;
V_10 -> V_94 [ F_1 ( V_1 ) ] += V_128 ;
V_135:
F_41 ( & V_10 -> V_100 , V_66 ) ;
F_110 ( V_10 , V_1 , V_73 ) ;
return V_73 ;
V_134:
F_41 ( & V_10 -> V_100 , V_66 ) ;
F_109 ( L_32 ,
V_117 , V_73 , V_1 , V_133 ) ;
return 0 ;
}
static T_4 F_114 ( struct V_8 * V_8 ,
T_8 V_1 )
{
struct V_7 * V_10 = F_7 ( V_8 ) ;
T_3 * V_131 ;
unsigned long V_66 ;
T_4 V_137 = 0 ;
F_40 ( & V_10 -> V_100 , V_66 ) ;
V_131 = F_3 ( V_10 -> V_5 , V_1 ) ;
if ( F_93 ( V_131 ) ) {
V_137 = F_115 ( V_131 ) + F_116 ( V_1 ) ;
} else if ( F_30 ( V_131 ) ) {
V_131 = F_4 ( V_131 , V_1 ) ;
if ( F_117 ( V_131 ) )
V_137 = F_118 ( V_131 ) + F_119 ( V_1 ) ;
else if ( F_113 ( V_131 ) )
V_137 = F_120 ( V_131 ) + F_121 ( V_1 ) ;
}
F_41 ( & V_10 -> V_100 , V_66 ) ;
return V_137 ;
}
static struct V_138 * F_122 ( struct V_76 * V_77 )
{
struct V_138 * V_139 ;
V_139 = F_123 ( V_77 ) ;
if ( ! V_139 )
V_139 = F_124 () ;
return V_139 ;
}
static int F_125 ( struct V_76 * V_77 )
{
struct V_138 * V_139 ;
if ( ! F_88 ( V_77 ) )
return - V_118 ;
V_139 = F_126 ( V_77 ) ;
if ( F_53 ( V_139 ) )
return F_54 ( V_139 ) ;
F_127 ( V_139 ) ;
return 0 ;
}
static void F_128 ( struct V_76 * V_77 )
{
if ( ! F_88 ( V_77 ) )
return;
F_129 ( V_77 ) ;
}
static int F_130 ( struct V_76 * V_77 ,
struct V_140 * V_141 )
{
struct V_111 * V_112 = V_77 -> V_113 . V_114 ;
struct V_74 * V_38 = F_131 ( V_141 -> V_142 ) ;
struct V_11 * V_12 ;
if ( ! V_38 )
return - V_118 ;
V_12 = F_132 ( V_38 ) ;
if ( ! V_12 )
return - V_118 ;
if ( ! V_112 ) {
V_112 = F_73 ( sizeof( * V_112 ) , V_80 ) ;
if ( ! V_112 )
return - V_81 ;
F_77 ( & V_112 -> V_143 ) ;
V_77 -> V_113 . V_114 = V_112 ;
}
F_91 ( & V_12 -> V_144 , & V_112 -> V_143 ) ;
return 0 ;
}
static int T_7 F_133 ( void )
{
int V_50 ;
V_110 = F_134 ( L_33 ,
V_109 , V_109 , 0 , NULL ) ;
if ( ! V_110 ) {
F_109 ( L_34 , V_117 ) ;
return - V_81 ;
}
V_50 = F_135 ( & V_145 ) ;
if ( V_50 ) {
F_109 ( L_35 , V_117 ) ;
goto V_146;
}
V_147 = F_98 ( V_110 , V_80 ) ;
if ( V_147 == NULL ) {
F_109 ( L_36 ,
V_117 ) ;
V_50 = - V_81 ;
goto V_148;
}
V_50 = F_136 ( & V_149 , & V_150 ) ;
if ( V_50 ) {
F_109 ( L_37 ,
V_117 ) ;
goto V_151;
}
V_152 = true ;
return 0 ;
V_151:
F_86 ( V_110 , V_147 ) ;
V_148:
F_137 ( & V_145 ) ;
V_146:
F_138 ( V_110 ) ;
return V_50 ;
}
static int T_7 F_139 ( struct V_153 * V_142 )
{
struct V_74 * V_75 ;
if ( ! V_152 )
F_133 () ;
V_75 = F_140 ( V_142 , NULL , V_149 . V_154 ) ;
if ( F_53 ( V_75 ) )
return F_54 ( V_75 ) ;
if ( ! V_87 )
V_87 = & V_75 -> V_77 ;
F_141 ( V_142 , & V_150 ) ;
return 0 ;
}
