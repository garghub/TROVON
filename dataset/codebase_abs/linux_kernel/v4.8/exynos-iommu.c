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
F_11 ( F_22 ( V_12 -> V_32 ) ) ;
F_11 ( F_22 ( V_12 -> V_33 ) ) ;
F_11 ( F_22 ( V_12 -> V_34 ) ) ;
F_11 ( F_22 ( V_12 -> V_35 ) ) ;
}
static void F_23 ( struct V_11 * V_12 )
{
F_24 ( V_12 -> V_35 ) ;
F_24 ( V_12 -> V_34 ) ;
F_24 ( V_12 -> V_33 ) ;
F_24 ( V_12 -> V_32 ) ;
}
static void F_25 ( struct V_11 * V_12 )
{
T_1 V_36 ;
F_21 ( V_12 ) ;
V_36 = F_16 ( V_12 -> V_15 + V_37 ) ;
if ( V_36 == 0x80000001u )
V_12 -> V_20 = F_26 ( 1 , 0 ) ;
else
V_12 -> V_20 = F_27 ( V_36 ) ;
F_28 ( V_12 -> V_38 , L_1 ,
F_18 ( V_12 -> V_20 ) , F_29 ( V_12 -> V_20 ) ) ;
F_23 ( V_12 ) ;
}
static void F_30 ( struct V_11 * V_12 ,
const struct V_39 * V_40 ,
T_2 V_41 )
{
T_3 * V_42 ;
F_31 ( V_12 -> V_38 , L_2 ,
V_40 -> V_43 , V_41 , & V_12 -> V_5 ) ;
V_42 = F_3 ( F_5 ( V_12 -> V_5 ) , V_41 ) ;
F_31 ( V_12 -> V_38 , L_3 , * V_42 ) ;
if ( F_32 ( V_42 ) ) {
V_42 = F_4 ( V_42 , V_41 ) ;
F_31 ( V_12 -> V_38 , L_4 , * V_42 ) ;
}
}
static T_5 F_33 ( int V_44 , void * V_45 )
{
struct V_11 * V_12 = V_45 ;
const struct V_39 * V_40 ;
unsigned int V_17 , V_46 , V_47 ;
T_2 V_41 = - 1 ;
unsigned short V_48 , V_49 ;
int V_50 = - V_51 ;
F_34 ( ! F_12 ( V_12 ) ) ;
if ( F_18 ( V_12 -> V_20 ) < 5 ) {
V_48 = V_52 ;
V_49 = V_53 ;
V_40 = V_54 ;
V_46 = F_35 ( V_54 ) ;
} else {
V_48 = V_55 ;
V_49 = V_56 ;
V_40 = V_57 ;
V_46 = F_35 ( V_57 ) ;
}
F_36 ( & V_12 -> V_58 ) ;
F_37 ( V_12 -> V_32 ) ;
V_47 = F_38 ( F_16 ( V_12 -> V_15 + V_48 ) ) ;
for ( V_17 = 0 ; V_17 < V_46 ; V_17 ++ , V_40 ++ )
if ( V_40 -> V_59 == V_47 )
break;
F_11 ( V_17 == V_46 ) ;
V_41 = F_16 ( V_12 -> V_15 + V_40 -> V_60 ) ;
F_30 ( V_12 , V_40 , V_41 ) ;
if ( V_12 -> V_10 )
V_50 = F_39 ( & V_12 -> V_10 -> V_10 ,
V_12 -> V_61 , V_41 , V_40 -> type ) ;
F_11 ( V_50 != 0 ) ;
F_14 ( 1 << V_47 , V_12 -> V_15 + V_49 ) ;
F_13 ( V_12 ) ;
F_40 ( V_12 -> V_32 ) ;
F_41 ( & V_12 -> V_58 ) ;
return V_62 ;
}
static void F_42 ( struct V_11 * V_12 )
{
F_37 ( V_12 -> V_32 ) ;
F_14 ( V_63 , V_12 -> V_15 + V_16 ) ;
F_14 ( 0 , V_12 -> V_15 + V_64 ) ;
F_23 ( V_12 ) ;
}
static bool F_43 ( struct V_11 * V_12 )
{
bool V_65 ;
unsigned long V_66 ;
F_44 ( & V_12 -> V_58 , V_66 ) ;
V_65 = F_10 ( V_12 ) ;
if ( V_65 ) {
V_12 -> V_5 = 0 ;
V_12 -> V_10 = NULL ;
F_42 ( V_12 ) ;
F_28 ( V_12 -> V_38 , L_5 ) ;
} else {
F_28 ( V_12 -> V_38 , L_6 ,
V_12 -> V_13 ) ;
}
F_45 ( & V_12 -> V_58 , V_66 ) ;
return V_65 ;
}
static void F_46 ( struct V_11 * V_12 )
{
unsigned int V_67 ;
if ( V_12 -> V_20 <= F_26 ( 3 , 1 ) )
V_67 = V_68 | F_47 ( 15 ) ;
else if ( V_12 -> V_20 <= F_26 ( 3 , 2 ) )
V_67 = V_68 | F_47 ( 15 ) | V_69 | V_70 ;
else
V_67 = F_47 ( 15 ) | V_69 | V_71 ;
F_14 ( V_67 , V_12 -> V_15 + V_64 ) ;
}
static void F_48 ( struct V_11 * V_12 )
{
F_21 ( V_12 ) ;
F_14 ( V_18 , V_12 -> V_15 + V_16 ) ;
F_46 ( V_12 ) ;
F_20 ( V_12 , V_12 -> V_5 ) ;
F_14 ( V_14 , V_12 -> V_15 + V_16 ) ;
F_40 ( V_12 -> V_32 ) ;
}
static int F_49 ( struct V_11 * V_12 , T_4 V_5 ,
struct V_7 * V_10 )
{
int V_50 = 0 ;
unsigned long V_66 ;
F_44 ( & V_12 -> V_58 , V_66 ) ;
if ( F_9 ( V_12 ) ) {
V_12 -> V_5 = V_5 ;
V_12 -> V_10 = V_10 ;
F_48 ( V_12 ) ;
F_28 ( V_12 -> V_38 , L_7 ) ;
} else {
V_50 = ( V_5 == V_12 -> V_5 ) ? 1 : - V_72 ;
F_28 ( V_12 -> V_38 , L_8 ) ;
}
if ( F_34 ( V_50 < 0 ) )
F_10 ( V_12 ) ;
F_45 ( & V_12 -> V_58 , V_66 ) ;
return V_50 ;
}
static void F_50 ( struct V_11 * V_12 ,
T_2 V_1 )
{
unsigned long V_66 ;
F_44 ( & V_12 -> V_58 , V_66 ) ;
if ( F_12 ( V_12 ) && V_12 -> V_20 >= F_26 ( 3 , 3 ) ) {
F_37 ( V_12 -> V_32 ) ;
F_19 ( V_12 , V_1 , 1 ) ;
F_40 ( V_12 -> V_32 ) ;
}
F_45 ( & V_12 -> V_58 , V_66 ) ;
}
static void F_51 ( struct V_11 * V_12 ,
T_2 V_1 , T_6 V_73 )
{
unsigned long V_66 ;
F_44 ( & V_12 -> V_58 , V_66 ) ;
if ( F_12 ( V_12 ) ) {
unsigned int V_23 = 1 ;
F_37 ( V_12 -> V_32 ) ;
if ( F_18 ( V_12 -> V_20 ) == 2 )
V_23 = F_52 (unsigned int, size / PAGE_SIZE, 64 ) ;
if ( F_15 ( V_12 ) ) {
F_19 ( V_12 , V_1 , V_23 ) ;
F_13 ( V_12 ) ;
}
F_40 ( V_12 -> V_32 ) ;
} else {
F_28 ( V_12 -> V_61 ,
L_9 , V_1 ) ;
}
F_45 ( & V_12 -> V_58 , V_66 ) ;
}
static int T_7 F_53 ( struct V_74 * V_75 )
{
int V_44 , V_50 ;
struct V_76 * V_77 = & V_75 -> V_77 ;
struct V_11 * V_12 ;
struct V_78 * V_79 ;
V_12 = F_54 ( V_77 , sizeof( * V_12 ) , V_80 ) ;
if ( ! V_12 )
return - V_81 ;
V_79 = F_55 ( V_75 , V_82 , 0 ) ;
V_12 -> V_15 = F_56 ( V_77 , V_79 ) ;
if ( F_57 ( V_12 -> V_15 ) )
return F_58 ( V_12 -> V_15 ) ;
V_44 = F_59 ( V_75 , 0 ) ;
if ( V_44 <= 0 ) {
F_31 ( V_77 , L_10 ) ;
return V_44 ;
}
V_50 = F_60 ( V_77 , V_44 , F_33 , 0 ,
F_61 ( V_77 ) , V_12 ) ;
if ( V_50 ) {
F_31 ( V_77 , L_11 , V_44 ) ;
return V_50 ;
}
V_12 -> V_33 = F_62 ( V_77 , L_12 ) ;
if ( F_58 ( V_12 -> V_33 ) == - V_83 )
V_12 -> V_33 = NULL ;
else if ( F_57 ( V_12 -> V_33 ) )
return F_58 ( V_12 -> V_33 ) ;
V_12 -> V_35 = F_62 ( V_77 , L_13 ) ;
if ( F_58 ( V_12 -> V_35 ) == - V_83 )
V_12 -> V_35 = NULL ;
else if ( F_57 ( V_12 -> V_35 ) )
return F_58 ( V_12 -> V_35 ) ;
V_12 -> V_34 = F_62 ( V_77 , L_14 ) ;
if ( F_58 ( V_12 -> V_34 ) == - V_83 )
V_12 -> V_34 = NULL ;
else if ( F_57 ( V_12 -> V_34 ) )
return F_58 ( V_12 -> V_34 ) ;
if ( ! V_12 -> V_33 && ( ! V_12 -> V_35 || ! V_12 -> V_34 ) ) {
F_31 ( V_77 , L_15 ) ;
return - V_51 ;
}
V_12 -> V_32 = F_62 ( V_77 , L_16 ) ;
if ( F_58 ( V_12 -> V_32 ) == - V_83 )
V_12 -> V_32 = NULL ;
else if ( F_57 ( V_12 -> V_32 ) )
return F_58 ( V_12 -> V_32 ) ;
V_12 -> V_38 = V_77 ;
F_63 ( & V_12 -> V_58 ) ;
F_64 ( V_75 , V_12 ) ;
F_25 ( V_12 ) ;
if ( V_84 < 0 ) {
if ( F_18 ( V_12 -> V_20 ) < 5 )
V_84 = V_85 ;
else
V_84 = V_86 ;
}
F_65 ( V_77 ) ;
F_66 ( V_77 -> V_87 , & V_88 ) ;
return 0 ;
}
static int F_67 ( struct V_76 * V_77 )
{
struct V_11 * V_12 = F_68 ( V_77 ) ;
F_28 ( V_77 , L_17 ) ;
if ( F_12 ( V_12 ) ) {
F_42 ( V_12 ) ;
F_69 ( V_77 ) ;
}
return 0 ;
}
static int F_70 ( struct V_76 * V_77 )
{
struct V_11 * V_12 = F_68 ( V_77 ) ;
F_28 ( V_77 , L_18 ) ;
if ( F_12 ( V_12 ) ) {
F_71 ( V_77 ) ;
F_48 ( V_12 ) ;
}
return 0 ;
}
static inline void F_72 ( T_3 * V_42 , T_3 V_89 )
{
F_73 ( V_90 , F_74 ( V_42 ) , sizeof( * V_42 ) ,
V_91 ) ;
* V_42 = F_75 ( V_89 ) ;
F_76 ( V_90 , F_74 ( V_42 ) , sizeof( * V_42 ) ,
V_91 ) ;
}
static struct V_8 * F_77 ( unsigned type )
{
struct V_7 * V_10 ;
T_8 V_92 ;
int V_17 ;
F_11 ( V_84 < 0 || ! V_90 ) ;
V_10 = F_78 ( sizeof( * V_10 ) , V_80 ) ;
if ( ! V_10 )
return NULL ;
if ( type == V_93 ) {
if ( F_79 ( & V_10 -> V_10 ) != 0 )
goto V_94;
} else if ( type != V_95 ) {
goto V_94;
}
V_10 -> V_5 = ( T_3 * ) F_80 ( V_80 , 2 ) ;
if ( ! V_10 -> V_5 )
goto V_96;
V_10 -> V_97 = ( short * ) F_80 ( V_80 | V_98 , 1 ) ;
if ( ! V_10 -> V_97 )
goto V_99;
for ( V_17 = 0 ; V_17 < V_100 ; V_17 += 8 ) {
V_10 -> V_5 [ V_17 + 0 ] = V_101 ;
V_10 -> V_5 [ V_17 + 1 ] = V_101 ;
V_10 -> V_5 [ V_17 + 2 ] = V_101 ;
V_10 -> V_5 [ V_17 + 3 ] = V_101 ;
V_10 -> V_5 [ V_17 + 4 ] = V_101 ;
V_10 -> V_5 [ V_17 + 5 ] = V_101 ;
V_10 -> V_5 [ V_17 + 6 ] = V_101 ;
V_10 -> V_5 [ V_17 + 7 ] = V_101 ;
}
V_92 = F_81 ( V_90 , V_10 -> V_5 , V_102 ,
V_91 ) ;
F_11 ( V_92 != F_74 ( V_10 -> V_5 ) ) ;
F_63 ( & V_10 -> V_58 ) ;
F_63 ( & V_10 -> V_103 ) ;
F_82 ( & V_10 -> V_104 ) ;
V_10 -> V_10 . V_105 . V_106 = 0 ;
V_10 -> V_10 . V_105 . V_107 = ~ 0UL ;
V_10 -> V_10 . V_105 . V_108 = true ;
return & V_10 -> V_10 ;
V_99:
F_83 ( ( unsigned long ) V_10 -> V_5 , 2 ) ;
V_96:
if ( type == V_93 )
F_84 ( & V_10 -> V_10 ) ;
V_94:
F_85 ( V_10 ) ;
return NULL ;
}
static void F_86 ( struct V_8 * V_8 )
{
struct V_7 * V_10 = F_7 ( V_8 ) ;
struct V_11 * V_12 , * V_109 ;
unsigned long V_66 ;
int V_17 ;
F_34 ( ! F_87 ( & V_10 -> V_104 ) ) ;
F_44 ( & V_10 -> V_58 , V_66 ) ;
F_88 (data, next, &domain->clients, domain_node) {
if ( F_43 ( V_12 ) )
V_12 -> V_61 = NULL ;
F_89 ( & V_12 -> V_110 ) ;
}
F_45 ( & V_10 -> V_58 , V_66 ) ;
if ( V_8 -> type == V_93 )
F_84 ( V_8 ) ;
F_90 ( V_90 , F_74 ( V_10 -> V_5 ) , V_102 ,
V_91 ) ;
for ( V_17 = 0 ; V_17 < V_100 ; V_17 ++ )
if ( F_32 ( V_10 -> V_5 + V_17 ) ) {
T_4 V_111 = F_6 ( V_10 -> V_5 + V_17 ) ;
F_90 ( V_90 , V_111 , V_112 ,
V_91 ) ;
F_91 ( V_113 ,
F_5 ( V_111 ) ) ;
}
F_83 ( ( unsigned long ) V_10 -> V_5 , 2 ) ;
F_83 ( ( unsigned long ) V_10 -> V_97 , 1 ) ;
F_85 ( V_10 ) ;
}
static void F_92 ( struct V_8 * V_8 ,
struct V_76 * V_77 )
{
struct V_114 * V_115 = V_77 -> V_116 . V_117 ;
struct V_7 * V_10 = F_7 ( V_8 ) ;
T_4 V_118 = F_74 ( V_10 -> V_5 ) ;
struct V_11 * V_12 , * V_109 ;
unsigned long V_66 ;
bool V_119 = false ;
if ( ! F_93 ( V_77 ) || V_115 -> V_10 != V_8 )
return;
F_44 ( & V_10 -> V_58 , V_66 ) ;
F_88 (data, next, &domain->clients, domain_node) {
if ( V_12 -> V_61 == V_77 ) {
if ( F_43 ( V_12 ) ) {
V_12 -> V_61 = NULL ;
F_89 ( & V_12 -> V_110 ) ;
}
F_69 ( V_12 -> V_38 ) ;
V_119 = true ;
}
}
F_45 ( & V_10 -> V_58 , V_66 ) ;
V_115 -> V_10 = NULL ;
if ( V_119 )
F_28 ( V_77 , L_19 ,
V_120 , & V_118 ) ;
else
F_31 ( V_77 , L_20 , V_120 ) ;
}
static int F_94 ( struct V_8 * V_8 ,
struct V_76 * V_77 )
{
struct V_114 * V_115 = V_77 -> V_116 . V_117 ;
struct V_7 * V_10 = F_7 ( V_8 ) ;
struct V_11 * V_12 ;
T_4 V_118 = F_74 ( V_10 -> V_5 ) ;
unsigned long V_66 ;
int V_50 = - V_121 ;
if ( ! F_93 ( V_77 ) )
return - V_121 ;
if ( V_115 -> V_10 )
F_92 ( V_115 -> V_10 , V_77 ) ;
F_95 (data, &owner->controllers, owner_node) {
F_71 ( V_12 -> V_38 ) ;
V_50 = F_49 ( V_12 , V_118 , V_10 ) ;
if ( V_50 >= 0 ) {
V_12 -> V_61 = V_77 ;
F_44 ( & V_10 -> V_58 , V_66 ) ;
F_96 ( & V_12 -> V_110 , & V_10 -> V_104 ) ;
F_45 ( & V_10 -> V_58 , V_66 ) ;
}
}
if ( V_50 < 0 ) {
F_31 ( V_77 , L_21 ,
V_120 , & V_118 ) ;
return V_50 ;
}
V_115 -> V_10 = V_8 ;
F_28 ( V_77 , L_22 ,
V_120 , & V_118 , ( V_50 == 0 ) ? L_23 : L_24 ) ;
return V_50 ;
}
static T_3 * F_97 ( struct V_7 * V_10 ,
T_3 * V_6 , T_2 V_1 , short * V_122 )
{
if ( F_98 ( V_6 ) ) {
F_99 ( 1 , L_25 , V_1 ) ;
return F_100 ( - V_123 ) ;
}
if ( F_101 ( V_6 ) ) {
T_3 * V_124 ;
bool V_125 = F_102 ( V_6 ) ;
V_124 = F_103 ( V_113 , V_126 ) ;
F_11 ( ( V_127 ) V_124 & ( V_112 - 1 ) ) ;
if ( ! V_124 )
return F_100 ( - V_81 ) ;
F_72 ( V_6 , F_104 ( F_74 ( V_124 ) ) ) ;
F_105 ( V_124 ) ;
* V_122 = V_4 ;
F_81 ( V_90 , V_124 , V_112 , V_91 ) ;
if ( V_125 ) {
struct V_11 * V_12 ;
F_36 ( & V_10 -> V_58 ) ;
F_95 (data, &domain->clients, domain_node)
F_50 ( V_12 , V_1 ) ;
F_41 ( & V_10 -> V_58 ) ;
}
}
return F_4 ( V_6 , V_1 ) ;
}
static int F_106 ( struct V_7 * V_10 ,
T_3 * V_6 , T_2 V_1 ,
T_4 V_128 , short * V_129 )
{
if ( F_98 ( V_6 ) ) {
F_99 ( 1 , L_26 ,
V_1 ) ;
return - V_123 ;
}
if ( F_32 ( V_6 ) ) {
if ( * V_129 != V_4 ) {
F_99 ( 1 , L_26 ,
V_1 ) ;
return - V_123 ;
}
F_91 ( V_113 , F_4 ( V_6 , 0 ) ) ;
* V_129 = 0 ;
}
F_72 ( V_6 , F_107 ( V_128 ) ) ;
F_36 ( & V_10 -> V_58 ) ;
if ( F_108 ( V_6 ) ) {
struct V_11 * V_12 ;
F_95 (data, &domain->clients, domain_node)
F_50 ( V_12 , V_1 ) ;
}
F_41 ( & V_10 -> V_58 ) ;
return 0 ;
}
static int F_109 ( T_3 * V_124 , T_4 V_128 , T_6 V_73 ,
short * V_129 )
{
if ( V_73 == V_27 ) {
if ( F_34 ( ! F_110 ( V_124 ) ) )
return - V_123 ;
F_72 ( V_124 , F_111 ( V_128 ) ) ;
* V_129 -= 1 ;
} else {
int V_17 ;
T_8 V_130 = F_74 ( V_124 ) ;
F_73 ( V_90 , V_130 ,
sizeof( * V_124 ) * V_131 ,
V_91 ) ;
for ( V_17 = 0 ; V_17 < V_131 ; V_17 ++ , V_124 ++ ) {
if ( F_34 ( ! F_110 ( V_124 ) ) ) {
if ( V_17 > 0 )
memset ( V_124 - V_17 , 0 , sizeof( * V_124 ) * V_17 ) ;
return - V_123 ;
}
* V_124 = F_112 ( V_128 ) ;
}
F_76 ( V_90 , V_130 ,
sizeof( * V_124 ) * V_131 ,
V_91 ) ;
* V_129 -= V_131 ;
}
return 0 ;
}
static int F_113 ( struct V_8 * V_8 ,
unsigned long V_132 , T_4 V_128 , T_6 V_73 ,
int V_133 )
{
struct V_7 * V_10 = F_7 ( V_8 ) ;
T_3 * V_134 ;
T_2 V_1 = ( T_2 ) V_132 ;
unsigned long V_66 ;
int V_50 = - V_81 ;
F_11 ( V_10 -> V_5 == NULL ) ;
F_44 ( & V_10 -> V_103 , V_66 ) ;
V_134 = F_3 ( V_10 -> V_5 , V_1 ) ;
if ( V_73 == V_135 ) {
V_50 = F_106 ( V_10 , V_134 , V_1 , V_128 ,
& V_10 -> V_97 [ F_1 ( V_1 ) ] ) ;
} else {
T_3 * V_124 ;
V_124 = F_97 ( V_10 , V_134 , V_1 ,
& V_10 -> V_97 [ F_1 ( V_1 ) ] ) ;
if ( F_57 ( V_124 ) )
V_50 = F_58 ( V_124 ) ;
else
V_50 = F_109 ( V_124 , V_128 , V_73 ,
& V_10 -> V_97 [ F_1 ( V_1 ) ] ) ;
}
if ( V_50 )
F_114 ( L_27 ,
V_120 , V_50 , V_73 , V_1 ) ;
F_45 ( & V_10 -> V_103 , V_66 ) ;
return V_50 ;
}
static void F_115 ( struct V_7 * V_10 ,
T_2 V_1 , T_6 V_73 )
{
struct V_11 * V_12 ;
unsigned long V_66 ;
F_44 ( & V_10 -> V_58 , V_66 ) ;
F_95 (data, &domain->clients, domain_node)
F_51 ( V_12 , V_1 , V_73 ) ;
F_45 ( & V_10 -> V_58 , V_66 ) ;
}
static T_6 F_116 ( struct V_8 * V_8 ,
unsigned long V_132 , T_6 V_73 )
{
struct V_7 * V_10 = F_7 ( V_8 ) ;
T_2 V_1 = ( T_2 ) V_132 ;
T_3 * V_42 ;
T_6 V_136 ;
unsigned long V_66 ;
F_11 ( V_10 -> V_5 == NULL ) ;
F_44 ( & V_10 -> V_103 , V_66 ) ;
V_42 = F_3 ( V_10 -> V_5 , V_1 ) ;
if ( F_98 ( V_42 ) ) {
if ( F_34 ( V_73 < V_135 ) ) {
V_136 = V_135 ;
goto V_137;
}
F_72 ( V_42 , V_101 ) ;
V_73 = V_135 ;
goto V_138;
}
if ( F_117 ( F_101 ( V_42 ) ) ) {
if ( V_73 > V_135 )
V_73 = V_135 ;
goto V_138;
}
V_42 = F_4 ( V_42 , V_1 ) ;
if ( F_117 ( F_110 ( V_42 ) ) ) {
V_73 = V_27 ;
goto V_138;
}
if ( F_118 ( V_42 ) ) {
F_72 ( V_42 , 0 ) ;
V_73 = V_27 ;
V_10 -> V_97 [ F_1 ( V_1 ) ] += 1 ;
goto V_138;
}
if ( F_34 ( V_73 < V_139 ) ) {
V_136 = V_139 ;
goto V_137;
}
F_73 ( V_90 , F_74 ( V_42 ) ,
sizeof( * V_42 ) * V_131 ,
V_91 ) ;
memset ( V_42 , 0 , sizeof( * V_42 ) * V_131 ) ;
F_76 ( V_90 , F_74 ( V_42 ) ,
sizeof( * V_42 ) * V_131 ,
V_91 ) ;
V_73 = V_139 ;
V_10 -> V_97 [ F_1 ( V_1 ) ] += V_131 ;
V_138:
F_45 ( & V_10 -> V_103 , V_66 ) ;
F_115 ( V_10 , V_1 , V_73 ) ;
return V_73 ;
V_137:
F_45 ( & V_10 -> V_103 , V_66 ) ;
F_114 ( L_28 ,
V_120 , V_73 , V_1 , V_136 ) ;
return 0 ;
}
static T_4 F_119 ( struct V_8 * V_8 ,
T_8 V_1 )
{
struct V_7 * V_10 = F_7 ( V_8 ) ;
T_3 * V_134 ;
unsigned long V_66 ;
T_4 V_140 = 0 ;
F_44 ( & V_10 -> V_103 , V_66 ) ;
V_134 = F_3 ( V_10 -> V_5 , V_1 ) ;
if ( F_98 ( V_134 ) ) {
V_140 = F_120 ( V_134 ) + F_121 ( V_1 ) ;
} else if ( F_32 ( V_134 ) ) {
V_134 = F_4 ( V_134 , V_1 ) ;
if ( F_122 ( V_134 ) )
V_140 = F_123 ( V_134 ) + F_124 ( V_1 ) ;
else if ( F_118 ( V_134 ) )
V_140 = F_125 ( V_134 ) + F_126 ( V_1 ) ;
}
F_45 ( & V_10 -> V_103 , V_66 ) ;
return V_140 ;
}
static struct V_141 * F_127 ( struct V_76 * V_77 )
{
struct V_141 * V_142 ;
V_142 = F_128 ( V_77 ) ;
if ( ! V_142 )
V_142 = F_129 () ;
return V_142 ;
}
static int F_130 ( struct V_76 * V_77 )
{
struct V_141 * V_142 ;
if ( ! F_93 ( V_77 ) )
return - V_121 ;
V_142 = F_131 ( V_77 ) ;
if ( F_57 ( V_142 ) )
return F_58 ( V_142 ) ;
F_132 ( V_142 ) ;
return 0 ;
}
static void F_133 ( struct V_76 * V_77 )
{
if ( ! F_93 ( V_77 ) )
return;
F_134 ( V_77 ) ;
}
static int F_135 ( struct V_76 * V_77 ,
struct V_143 * V_144 )
{
struct V_114 * V_115 = V_77 -> V_116 . V_117 ;
struct V_74 * V_38 = F_136 ( V_144 -> V_145 ) ;
struct V_11 * V_12 ;
if ( ! V_38 )
return - V_121 ;
V_12 = F_137 ( V_38 ) ;
if ( ! V_12 )
return - V_121 ;
if ( ! V_115 ) {
V_115 = F_78 ( sizeof( * V_115 ) , V_80 ) ;
if ( ! V_115 )
return - V_81 ;
F_82 ( & V_115 -> V_146 ) ;
V_77 -> V_116 . V_117 = V_115 ;
}
F_96 ( & V_12 -> V_147 , & V_115 -> V_146 ) ;
return 0 ;
}
static int T_7 F_138 ( void )
{
int V_50 ;
V_113 = F_139 ( L_29 ,
V_112 , V_112 , 0 , NULL ) ;
if ( ! V_113 ) {
F_114 ( L_30 , V_120 ) ;
return - V_81 ;
}
V_50 = F_140 ( & V_148 ) ;
if ( V_50 ) {
F_114 ( L_31 , V_120 ) ;
goto V_149;
}
V_150 = F_103 ( V_113 , V_80 ) ;
if ( V_150 == NULL ) {
F_114 ( L_32 ,
V_120 ) ;
V_50 = - V_81 ;
goto V_151;
}
V_50 = F_141 ( & V_152 , & V_88 ) ;
if ( V_50 ) {
F_114 ( L_33 ,
V_120 ) ;
goto V_153;
}
V_154 = true ;
return 0 ;
V_153:
F_91 ( V_113 , V_150 ) ;
V_151:
F_142 ( & V_148 ) ;
V_149:
F_143 ( V_113 ) ;
return V_50 ;
}
static int T_7 F_144 ( struct V_155 * V_145 )
{
struct V_74 * V_75 ;
if ( ! V_154 )
F_138 () ;
V_75 = F_145 ( V_145 , NULL , V_152 . V_156 ) ;
if ( F_57 ( V_75 ) )
return F_58 ( V_75 ) ;
if ( ! V_90 )
V_90 = & V_75 -> V_77 ;
return 0 ;
}
