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
static void F_9 ( struct V_11 * V_12 )
{
F_10 ( V_13 , V_12 -> V_14 + V_15 ) ;
}
static bool F_11 ( struct V_11 * V_12 )
{
int V_16 = 120 ;
F_10 ( V_17 , V_12 -> V_14 + V_15 ) ;
while ( ( V_16 > 0 ) && ! ( F_12 ( V_12 -> V_14 + V_18 ) & 1 ) )
-- V_16 ;
if ( ! ( F_12 ( V_12 -> V_14 + V_18 ) & 1 ) ) {
F_9 ( V_12 ) ;
return false ;
}
return true ;
}
static void F_13 ( struct V_11 * V_12 )
{
if ( F_14 ( V_12 -> V_19 ) < 5 )
F_10 ( 0x1 , V_12 -> V_14 + V_20 ) ;
else
F_10 ( 0x1 , V_12 -> V_14 + V_21 ) ;
}
static void F_15 ( struct V_11 * V_12 ,
T_2 V_1 , unsigned int V_22 )
{
unsigned int V_16 ;
for ( V_16 = 0 ; V_16 < V_22 ; V_16 ++ ) {
if ( F_14 ( V_12 -> V_19 ) < 5 )
F_10 ( ( V_1 & V_23 ) | 1 ,
V_12 -> V_14 + V_24 ) ;
else
F_10 ( ( V_1 & V_23 ) | 1 ,
V_12 -> V_14 + V_25 ) ;
V_1 += V_26 ;
}
}
static void F_16 ( struct V_11 * V_12 , T_4 V_27 )
{
if ( F_14 ( V_12 -> V_19 ) < 5 )
F_10 ( V_27 , V_12 -> V_14 + V_28 ) ;
else
F_10 ( V_27 >> V_29 ,
V_12 -> V_14 + V_30 ) ;
F_13 ( V_12 ) ;
}
static void F_17 ( struct V_11 * V_12 )
{
F_18 ( F_19 ( V_12 -> V_31 ) ) ;
F_18 ( F_19 ( V_12 -> V_32 ) ) ;
F_18 ( F_19 ( V_12 -> V_33 ) ) ;
F_18 ( F_19 ( V_12 -> V_34 ) ) ;
}
static void F_20 ( struct V_11 * V_12 )
{
F_21 ( V_12 -> V_34 ) ;
F_21 ( V_12 -> V_33 ) ;
F_21 ( V_12 -> V_32 ) ;
F_21 ( V_12 -> V_31 ) ;
}
static void F_22 ( struct V_11 * V_12 )
{
T_1 V_35 ;
F_17 ( V_12 ) ;
V_35 = F_12 ( V_12 -> V_14 + V_36 ) ;
if ( V_35 == 0x80000001u )
V_12 -> V_19 = F_23 ( 1 , 0 ) ;
else
V_12 -> V_19 = F_24 ( V_35 ) ;
F_25 ( V_12 -> V_37 , L_1 ,
F_14 ( V_12 -> V_19 ) , F_26 ( V_12 -> V_19 ) ) ;
F_20 ( V_12 ) ;
}
static void F_27 ( struct V_11 * V_12 ,
const struct V_38 * V_39 ,
T_2 V_40 )
{
T_3 * V_41 ;
F_28 ( V_12 -> V_37 , L_2 ,
F_29 ( V_12 -> V_42 ) , V_39 -> V_43 , V_40 ) ;
F_25 ( V_12 -> V_37 , L_3 , & V_12 -> V_5 ) ;
V_41 = F_3 ( F_5 ( V_12 -> V_5 ) , V_40 ) ;
F_25 ( V_12 -> V_37 , L_4 , * V_41 ) ;
if ( F_30 ( V_41 ) ) {
V_41 = F_4 ( V_41 , V_40 ) ;
F_25 ( V_12 -> V_37 , L_5 , * V_41 ) ;
}
}
static T_5 F_31 ( int V_44 , void * V_45 )
{
struct V_11 * V_12 = V_45 ;
const struct V_38 * V_39 ;
unsigned int V_16 , V_46 , V_47 ;
T_2 V_40 = - 1 ;
unsigned short V_48 , V_49 ;
int V_50 = - V_51 ;
F_32 ( ! V_12 -> V_52 ) ;
if ( F_14 ( V_12 -> V_19 ) < 5 ) {
V_48 = V_53 ;
V_49 = V_54 ;
V_39 = V_55 ;
V_46 = F_33 ( V_55 ) ;
} else {
V_48 = V_56 ;
V_49 = V_57 ;
V_39 = V_58 ;
V_46 = F_33 ( V_58 ) ;
}
F_34 ( & V_12 -> V_59 ) ;
F_35 ( V_12 -> V_31 ) ;
V_47 = F_36 ( F_12 ( V_12 -> V_14 + V_48 ) ) ;
for ( V_16 = 0 ; V_16 < V_46 ; V_16 ++ , V_39 ++ )
if ( V_39 -> V_60 == V_47 )
break;
F_18 ( V_16 == V_46 ) ;
V_40 = F_12 ( V_12 -> V_14 + V_39 -> V_61 ) ;
F_27 ( V_12 , V_39 , V_40 ) ;
if ( V_12 -> V_10 )
V_50 = F_37 ( & V_12 -> V_10 -> V_10 ,
V_12 -> V_42 , V_40 , V_39 -> type ) ;
F_18 ( V_50 != 0 ) ;
F_10 ( 1 << V_47 , V_12 -> V_14 + V_49 ) ;
F_9 ( V_12 ) ;
F_38 ( V_12 -> V_31 ) ;
F_39 ( & V_12 -> V_59 ) ;
return V_62 ;
}
static void F_40 ( struct V_11 * V_12 )
{
unsigned long V_63 ;
F_35 ( V_12 -> V_31 ) ;
F_41 ( & V_12 -> V_59 , V_63 ) ;
F_10 ( V_64 , V_12 -> V_14 + V_15 ) ;
F_10 ( 0 , V_12 -> V_14 + V_65 ) ;
V_12 -> V_52 = false ;
F_42 ( & V_12 -> V_59 , V_63 ) ;
F_20 ( V_12 ) ;
}
static void F_43 ( struct V_11 * V_12 )
{
unsigned int V_66 ;
if ( V_12 -> V_19 <= F_23 ( 3 , 1 ) )
V_66 = V_67 | F_44 ( 15 ) ;
else if ( V_12 -> V_19 <= F_23 ( 3 , 2 ) )
V_66 = V_67 | F_44 ( 15 ) | V_68 | V_69 ;
else
V_66 = F_44 ( 15 ) | V_68 | V_70 ;
V_66 |= V_71 ;
F_10 ( V_66 , V_12 -> V_14 + V_65 ) ;
}
static void F_45 ( struct V_11 * V_12 )
{
unsigned long V_63 ;
F_17 ( V_12 ) ;
F_41 ( & V_12 -> V_59 , V_63 ) ;
F_10 ( V_17 , V_12 -> V_14 + V_15 ) ;
F_43 ( V_12 ) ;
F_16 ( V_12 , V_12 -> V_5 ) ;
F_10 ( V_13 , V_12 -> V_14 + V_15 ) ;
V_12 -> V_52 = true ;
F_42 ( & V_12 -> V_59 , V_63 ) ;
F_38 ( V_12 -> V_31 ) ;
}
static void F_46 ( struct V_11 * V_12 ,
T_2 V_1 )
{
unsigned long V_63 ;
F_41 ( & V_12 -> V_59 , V_63 ) ;
if ( V_12 -> V_52 && V_12 -> V_19 >= F_23 ( 3 , 3 ) ) {
F_35 ( V_12 -> V_31 ) ;
if ( F_11 ( V_12 ) ) {
if ( V_12 -> V_19 >= F_23 ( 5 , 0 ) )
F_13 ( V_12 ) ;
else
F_15 ( V_12 , V_1 , 1 ) ;
F_9 ( V_12 ) ;
}
F_38 ( V_12 -> V_31 ) ;
}
F_42 ( & V_12 -> V_59 , V_63 ) ;
}
static void F_47 ( struct V_11 * V_12 ,
T_2 V_1 , T_6 V_72 )
{
unsigned long V_63 ;
F_41 ( & V_12 -> V_59 , V_63 ) ;
if ( V_12 -> V_52 ) {
unsigned int V_22 = 1 ;
F_35 ( V_12 -> V_31 ) ;
if ( F_14 ( V_12 -> V_19 ) == 2 )
V_22 = F_48 (unsigned int, size / PAGE_SIZE, 64 ) ;
if ( F_11 ( V_12 ) ) {
F_15 ( V_12 , V_1 , V_22 ) ;
F_9 ( V_12 ) ;
}
F_38 ( V_12 -> V_31 ) ;
}
F_42 ( & V_12 -> V_59 , V_63 ) ;
}
static int T_7 F_49 ( struct V_73 * V_74 )
{
int V_44 , V_50 ;
struct V_75 * V_76 = & V_74 -> V_76 ;
struct V_11 * V_12 ;
struct V_77 * V_78 ;
V_12 = F_50 ( V_76 , sizeof( * V_12 ) , V_79 ) ;
if ( ! V_12 )
return - V_80 ;
V_78 = F_51 ( V_74 , V_81 , 0 ) ;
V_12 -> V_14 = F_52 ( V_76 , V_78 ) ;
if ( F_53 ( V_12 -> V_14 ) )
return F_54 ( V_12 -> V_14 ) ;
V_44 = F_55 ( V_74 , 0 ) ;
if ( V_44 <= 0 ) {
F_28 ( V_76 , L_6 ) ;
return V_44 ;
}
V_50 = F_56 ( V_76 , V_44 , F_31 , 0 ,
F_29 ( V_76 ) , V_12 ) ;
if ( V_50 ) {
F_28 ( V_76 , L_7 , V_44 ) ;
return V_50 ;
}
V_12 -> V_32 = F_57 ( V_76 , L_8 ) ;
if ( F_54 ( V_12 -> V_32 ) == - V_82 )
V_12 -> V_32 = NULL ;
else if ( F_53 ( V_12 -> V_32 ) )
return F_54 ( V_12 -> V_32 ) ;
V_12 -> V_34 = F_57 ( V_76 , L_9 ) ;
if ( F_54 ( V_12 -> V_34 ) == - V_82 )
V_12 -> V_34 = NULL ;
else if ( F_53 ( V_12 -> V_34 ) )
return F_54 ( V_12 -> V_34 ) ;
V_12 -> V_33 = F_57 ( V_76 , L_10 ) ;
if ( F_54 ( V_12 -> V_33 ) == - V_82 )
V_12 -> V_33 = NULL ;
else if ( F_53 ( V_12 -> V_33 ) )
return F_54 ( V_12 -> V_33 ) ;
if ( ! V_12 -> V_32 && ( ! V_12 -> V_34 || ! V_12 -> V_33 ) ) {
F_28 ( V_76 , L_11 ) ;
return - V_51 ;
}
V_12 -> V_31 = F_57 ( V_76 , L_12 ) ;
if ( F_54 ( V_12 -> V_31 ) == - V_82 )
V_12 -> V_31 = NULL ;
else if ( F_53 ( V_12 -> V_31 ) )
return F_54 ( V_12 -> V_31 ) ;
V_12 -> V_37 = V_76 ;
F_58 ( & V_12 -> V_59 ) ;
V_50 = F_59 ( & V_12 -> V_83 , & V_74 -> V_76 , NULL ,
F_29 ( V_12 -> V_37 ) ) ;
if ( V_50 )
return V_50 ;
F_60 ( & V_12 -> V_83 , & V_84 ) ;
F_61 ( & V_12 -> V_83 , & V_76 -> V_85 -> V_86 ) ;
V_50 = F_62 ( & V_12 -> V_83 ) ;
if ( V_50 )
return V_50 ;
F_63 ( V_74 , V_12 ) ;
F_22 ( V_12 ) ;
if ( V_87 < 0 ) {
if ( F_14 ( V_12 -> V_19 ) < 5 ) {
V_87 = V_88 ;
V_89 = V_90 ;
V_91 = V_92 ;
} else {
V_87 = V_93 ;
V_89 = V_94 ;
V_91 = V_95 ;
}
}
F_64 ( V_76 ) ;
return 0 ;
}
static int T_8 F_65 ( struct V_75 * V_76 )
{
struct V_11 * V_12 = F_66 ( V_76 ) ;
struct V_75 * V_42 = V_12 -> V_42 ;
if ( V_42 ) {
struct V_96 * V_97 = V_42 -> V_98 . V_83 ;
F_67 ( & V_97 -> V_99 ) ;
if ( V_12 -> V_10 ) {
F_25 ( V_12 -> V_37 , L_13 ) ;
F_40 ( V_12 ) ;
}
F_68 ( & V_97 -> V_99 ) ;
}
return 0 ;
}
static int T_8 F_69 ( struct V_75 * V_76 )
{
struct V_11 * V_12 = F_66 ( V_76 ) ;
struct V_75 * V_42 = V_12 -> V_42 ;
if ( V_42 ) {
struct V_96 * V_97 = V_42 -> V_98 . V_83 ;
F_67 ( & V_97 -> V_99 ) ;
if ( V_12 -> V_10 ) {
F_25 ( V_12 -> V_37 , L_14 ) ;
F_45 ( V_12 ) ;
}
F_68 ( & V_97 -> V_99 ) ;
}
return 0 ;
}
static inline void F_70 ( T_3 * V_41 , T_3 V_100 )
{
F_71 ( V_101 , F_72 ( V_41 ) , sizeof( * V_41 ) ,
V_102 ) ;
* V_41 = F_73 ( V_100 ) ;
F_74 ( V_101 , F_72 ( V_41 ) , sizeof( * V_41 ) ,
V_102 ) ;
}
static struct V_8 * F_75 ( unsigned type )
{
struct V_7 * V_10 ;
T_9 V_103 ;
int V_16 ;
F_18 ( V_87 < 0 || ! V_101 ) ;
V_10 = F_76 ( sizeof( * V_10 ) , V_79 ) ;
if ( ! V_10 )
return NULL ;
if ( type == V_104 ) {
if ( F_77 ( & V_10 -> V_10 ) != 0 )
goto V_105;
} else if ( type != V_106 ) {
goto V_105;
}
V_10 -> V_5 = ( T_3 * ) F_78 ( V_79 , 2 ) ;
if ( ! V_10 -> V_5 )
goto V_107;
V_10 -> V_108 = ( short * ) F_78 ( V_79 | V_109 , 1 ) ;
if ( ! V_10 -> V_108 )
goto V_110;
for ( V_16 = 0 ; V_16 < V_111 ; V_16 += 8 ) {
V_10 -> V_5 [ V_16 + 0 ] = V_112 ;
V_10 -> V_5 [ V_16 + 1 ] = V_112 ;
V_10 -> V_5 [ V_16 + 2 ] = V_112 ;
V_10 -> V_5 [ V_16 + 3 ] = V_112 ;
V_10 -> V_5 [ V_16 + 4 ] = V_112 ;
V_10 -> V_5 [ V_16 + 5 ] = V_112 ;
V_10 -> V_5 [ V_16 + 6 ] = V_112 ;
V_10 -> V_5 [ V_16 + 7 ] = V_112 ;
}
V_103 = F_79 ( V_101 , V_10 -> V_5 , V_113 ,
V_102 ) ;
F_18 ( V_103 != F_72 ( V_10 -> V_5 ) ) ;
if ( F_80 ( V_101 , V_103 ) )
goto V_114;
F_58 ( & V_10 -> V_59 ) ;
F_58 ( & V_10 -> V_115 ) ;
F_81 ( & V_10 -> V_116 ) ;
V_10 -> V_10 . V_117 . V_118 = 0 ;
V_10 -> V_10 . V_117 . V_119 = ~ 0UL ;
V_10 -> V_10 . V_117 . V_120 = true ;
return & V_10 -> V_10 ;
V_114:
F_82 ( ( unsigned long ) V_10 -> V_108 , 1 ) ;
V_110:
F_82 ( ( unsigned long ) V_10 -> V_5 , 2 ) ;
V_107:
if ( type == V_104 )
F_83 ( & V_10 -> V_10 ) ;
V_105:
F_84 ( V_10 ) ;
return NULL ;
}
static void F_85 ( struct V_8 * V_8 )
{
struct V_7 * V_10 = F_7 ( V_8 ) ;
struct V_11 * V_12 , * V_121 ;
unsigned long V_63 ;
int V_16 ;
F_32 ( ! F_86 ( & V_10 -> V_116 ) ) ;
F_41 ( & V_10 -> V_59 , V_63 ) ;
F_87 (data, next, &domain->clients, domain_node) {
F_34 ( & V_12 -> V_59 ) ;
F_40 ( V_12 ) ;
V_12 -> V_5 = 0 ;
V_12 -> V_10 = NULL ;
F_88 ( & V_12 -> V_122 ) ;
F_39 ( & V_12 -> V_59 ) ;
}
F_42 ( & V_10 -> V_59 , V_63 ) ;
if ( V_8 -> type == V_104 )
F_83 ( V_8 ) ;
F_89 ( V_101 , F_72 ( V_10 -> V_5 ) , V_113 ,
V_102 ) ;
for ( V_16 = 0 ; V_16 < V_111 ; V_16 ++ )
if ( F_30 ( V_10 -> V_5 + V_16 ) ) {
T_4 V_123 = F_6 ( V_10 -> V_5 + V_16 ) ;
F_89 ( V_101 , V_123 , V_124 ,
V_102 ) ;
F_90 ( V_125 ,
F_5 ( V_123 ) ) ;
}
F_82 ( ( unsigned long ) V_10 -> V_5 , 2 ) ;
F_82 ( ( unsigned long ) V_10 -> V_108 , 1 ) ;
F_84 ( V_10 ) ;
}
static void F_91 ( struct V_8 * V_8 ,
struct V_75 * V_76 )
{
struct V_96 * V_97 = V_76 -> V_98 . V_83 ;
struct V_7 * V_10 = F_7 ( V_8 ) ;
T_4 V_126 = F_72 ( V_10 -> V_5 ) ;
struct V_11 * V_12 , * V_121 ;
unsigned long V_63 ;
if ( ! F_92 ( V_76 ) || V_97 -> V_10 != V_8 )
return;
F_67 ( & V_97 -> V_99 ) ;
F_93 (data, &owner->controllers, owner_node) {
F_94 ( V_12 -> V_37 ) ;
if ( F_95 ( V_12 -> V_37 ) )
F_40 ( V_12 ) ;
F_96 ( V_12 -> V_37 ) ;
}
F_41 ( & V_10 -> V_59 , V_63 ) ;
F_87 (data, next, &domain->clients, domain_node) {
F_34 ( & V_12 -> V_59 ) ;
V_12 -> V_5 = 0 ;
V_12 -> V_10 = NULL ;
F_88 ( & V_12 -> V_122 ) ;
F_39 ( & V_12 -> V_59 ) ;
}
V_97 -> V_10 = NULL ;
F_42 ( & V_10 -> V_59 , V_63 ) ;
F_68 ( & V_97 -> V_99 ) ;
F_25 ( V_76 , L_15 , V_127 ,
& V_126 ) ;
}
static int F_97 ( struct V_8 * V_8 ,
struct V_75 * V_76 )
{
struct V_96 * V_97 = V_76 -> V_98 . V_83 ;
struct V_7 * V_10 = F_7 ( V_8 ) ;
struct V_11 * V_12 ;
T_4 V_126 = F_72 ( V_10 -> V_5 ) ;
unsigned long V_63 ;
if ( ! F_92 ( V_76 ) )
return - V_128 ;
if ( V_97 -> V_10 )
F_91 ( V_97 -> V_10 , V_76 ) ;
F_67 ( & V_97 -> V_99 ) ;
F_41 ( & V_10 -> V_59 , V_63 ) ;
F_93 (data, &owner->controllers, owner_node) {
F_34 ( & V_12 -> V_59 ) ;
V_12 -> V_5 = V_126 ;
V_12 -> V_10 = V_10 ;
F_98 ( & V_12 -> V_122 , & V_10 -> V_116 ) ;
F_39 ( & V_12 -> V_59 ) ;
}
V_97 -> V_10 = V_8 ;
F_42 ( & V_10 -> V_59 , V_63 ) ;
F_93 (data, &owner->controllers, owner_node) {
F_94 ( V_12 -> V_37 ) ;
if ( F_95 ( V_12 -> V_37 ) )
F_45 ( V_12 ) ;
F_96 ( V_12 -> V_37 ) ;
}
F_68 ( & V_97 -> V_99 ) ;
F_25 ( V_76 , L_16 , V_127 ,
& V_126 ) ;
return 0 ;
}
static T_3 * F_99 ( struct V_7 * V_10 ,
T_3 * V_6 , T_2 V_1 , short * V_129 )
{
if ( F_100 ( V_6 ) ) {
F_101 ( 1 , L_17 , V_1 ) ;
return F_102 ( - V_130 ) ;
}
if ( F_103 ( V_6 ) ) {
T_9 V_103 ;
T_3 * V_131 ;
bool V_132 = F_104 ( V_6 ) ;
V_131 = F_105 ( V_125 , V_133 ) ;
F_18 ( ( V_134 ) V_131 & ( V_124 - 1 ) ) ;
if ( ! V_131 )
return F_102 ( - V_80 ) ;
F_70 ( V_6 , F_106 ( F_72 ( V_131 ) ) ) ;
F_107 ( V_131 ) ;
* V_129 = V_4 ;
V_103 = F_79 ( V_101 , V_131 , V_124 ,
V_102 ) ;
if ( F_80 ( V_101 , V_103 ) ) {
F_90 ( V_125 , V_131 ) ;
return F_102 ( - V_130 ) ;
}
if ( V_132 ) {
struct V_11 * V_12 ;
F_34 ( & V_10 -> V_59 ) ;
F_93 (data, &domain->clients, domain_node)
F_46 ( V_12 , V_1 ) ;
F_39 ( & V_10 -> V_59 ) ;
}
}
return F_4 ( V_6 , V_1 ) ;
}
static int F_108 ( struct V_7 * V_10 ,
T_3 * V_6 , T_2 V_1 ,
T_4 V_135 , int V_136 , short * V_137 )
{
if ( F_100 ( V_6 ) ) {
F_101 ( 1 , L_18 ,
V_1 ) ;
return - V_130 ;
}
if ( F_30 ( V_6 ) ) {
if ( * V_137 != V_4 ) {
F_101 ( 1 , L_18 ,
V_1 ) ;
return - V_130 ;
}
F_90 ( V_125 , F_4 ( V_6 , 0 ) ) ;
* V_137 = 0 ;
}
F_70 ( V_6 , F_109 ( V_135 , V_136 ) ) ;
F_34 ( & V_10 -> V_59 ) ;
if ( F_110 ( V_6 ) ) {
struct V_11 * V_12 ;
F_93 (data, &domain->clients, domain_node)
F_46 ( V_12 , V_1 ) ;
}
F_39 ( & V_10 -> V_59 ) ;
return 0 ;
}
static int F_111 ( T_3 * V_131 , T_4 V_135 , T_6 V_72 ,
int V_136 , short * V_137 )
{
if ( V_72 == V_26 ) {
if ( F_32 ( ! F_112 ( V_131 ) ) )
return - V_130 ;
F_70 ( V_131 , F_113 ( V_135 , V_136 ) ) ;
* V_137 -= 1 ;
} else {
int V_16 ;
T_9 V_138 = F_72 ( V_131 ) ;
F_71 ( V_101 , V_138 ,
sizeof( * V_131 ) * V_139 ,
V_102 ) ;
for ( V_16 = 0 ; V_16 < V_139 ; V_16 ++ , V_131 ++ ) {
if ( F_32 ( ! F_112 ( V_131 ) ) ) {
if ( V_16 > 0 )
memset ( V_131 - V_16 , 0 , sizeof( * V_131 ) * V_16 ) ;
return - V_130 ;
}
* V_131 = F_114 ( V_135 , V_136 ) ;
}
F_74 ( V_101 , V_138 ,
sizeof( * V_131 ) * V_139 ,
V_102 ) ;
* V_137 -= V_139 ;
}
return 0 ;
}
static int F_115 ( struct V_8 * V_8 ,
unsigned long V_140 , T_4 V_135 , T_6 V_72 ,
int V_136 )
{
struct V_7 * V_10 = F_7 ( V_8 ) ;
T_3 * V_141 ;
T_2 V_1 = ( T_2 ) V_140 ;
unsigned long V_63 ;
int V_50 = - V_80 ;
F_18 ( V_10 -> V_5 == NULL ) ;
V_136 &= V_142 ;
F_41 ( & V_10 -> V_115 , V_63 ) ;
V_141 = F_3 ( V_10 -> V_5 , V_1 ) ;
if ( V_72 == V_143 ) {
V_50 = F_108 ( V_10 , V_141 , V_1 , V_135 , V_136 ,
& V_10 -> V_108 [ F_1 ( V_1 ) ] ) ;
} else {
T_3 * V_131 ;
V_131 = F_99 ( V_10 , V_141 , V_1 ,
& V_10 -> V_108 [ F_1 ( V_1 ) ] ) ;
if ( F_53 ( V_131 ) )
V_50 = F_54 ( V_131 ) ;
else
V_50 = F_111 ( V_131 , V_135 , V_72 , V_136 ,
& V_10 -> V_108 [ F_1 ( V_1 ) ] ) ;
}
if ( V_50 )
F_116 ( L_19 ,
V_127 , V_50 , V_72 , V_1 ) ;
F_42 ( & V_10 -> V_115 , V_63 ) ;
return V_50 ;
}
static void F_117 ( struct V_7 * V_10 ,
T_2 V_1 , T_6 V_72 )
{
struct V_11 * V_12 ;
unsigned long V_63 ;
F_41 ( & V_10 -> V_59 , V_63 ) ;
F_93 (data, &domain->clients, domain_node)
F_47 ( V_12 , V_1 , V_72 ) ;
F_42 ( & V_10 -> V_59 , V_63 ) ;
}
static T_6 F_118 ( struct V_8 * V_8 ,
unsigned long V_140 , T_6 V_72 )
{
struct V_7 * V_10 = F_7 ( V_8 ) ;
T_2 V_1 = ( T_2 ) V_140 ;
T_3 * V_41 ;
T_6 V_144 ;
unsigned long V_63 ;
F_18 ( V_10 -> V_5 == NULL ) ;
F_41 ( & V_10 -> V_115 , V_63 ) ;
V_41 = F_3 ( V_10 -> V_5 , V_1 ) ;
if ( F_100 ( V_41 ) ) {
if ( F_32 ( V_72 < V_143 ) ) {
V_144 = V_143 ;
goto V_145;
}
F_70 ( V_41 , V_112 ) ;
V_72 = V_143 ;
goto V_146;
}
if ( F_119 ( F_103 ( V_41 ) ) ) {
if ( V_72 > V_143 )
V_72 = V_143 ;
goto V_146;
}
V_41 = F_4 ( V_41 , V_1 ) ;
if ( F_119 ( F_112 ( V_41 ) ) ) {
V_72 = V_26 ;
goto V_146;
}
if ( F_120 ( V_41 ) ) {
F_70 ( V_41 , 0 ) ;
V_72 = V_26 ;
V_10 -> V_108 [ F_1 ( V_1 ) ] += 1 ;
goto V_146;
}
if ( F_32 ( V_72 < V_147 ) ) {
V_144 = V_147 ;
goto V_145;
}
F_71 ( V_101 , F_72 ( V_41 ) ,
sizeof( * V_41 ) * V_139 ,
V_102 ) ;
memset ( V_41 , 0 , sizeof( * V_41 ) * V_139 ) ;
F_74 ( V_101 , F_72 ( V_41 ) ,
sizeof( * V_41 ) * V_139 ,
V_102 ) ;
V_72 = V_147 ;
V_10 -> V_108 [ F_1 ( V_1 ) ] += V_139 ;
V_146:
F_42 ( & V_10 -> V_115 , V_63 ) ;
F_117 ( V_10 , V_1 , V_72 ) ;
return V_72 ;
V_145:
F_42 ( & V_10 -> V_115 , V_63 ) ;
F_116 ( L_20 ,
V_127 , V_72 , V_1 , V_144 ) ;
return 0 ;
}
static T_4 F_121 ( struct V_8 * V_8 ,
T_9 V_1 )
{
struct V_7 * V_10 = F_7 ( V_8 ) ;
T_3 * V_141 ;
unsigned long V_63 ;
T_4 V_148 = 0 ;
F_41 ( & V_10 -> V_115 , V_63 ) ;
V_141 = F_3 ( V_10 -> V_5 , V_1 ) ;
if ( F_100 ( V_141 ) ) {
V_148 = F_122 ( V_141 ) + F_123 ( V_1 ) ;
} else if ( F_30 ( V_141 ) ) {
V_141 = F_4 ( V_141 , V_1 ) ;
if ( F_124 ( V_141 ) )
V_148 = F_125 ( V_141 ) + F_126 ( V_1 ) ;
else if ( F_120 ( V_141 ) )
V_148 = F_127 ( V_141 ) + F_128 ( V_1 ) ;
}
F_42 ( & V_10 -> V_115 , V_63 ) ;
return V_148 ;
}
static struct V_149 * F_129 ( struct V_75 * V_76 )
{
struct V_149 * V_150 ;
V_150 = F_130 ( V_76 ) ;
if ( ! V_150 )
V_150 = F_131 () ;
return V_150 ;
}
static int F_132 ( struct V_75 * V_76 )
{
struct V_149 * V_150 ;
if ( ! F_92 ( V_76 ) )
return - V_128 ;
V_150 = F_133 ( V_76 ) ;
if ( F_53 ( V_150 ) )
return F_54 ( V_150 ) ;
F_134 ( V_150 ) ;
return 0 ;
}
static void F_135 ( struct V_75 * V_76 )
{
struct V_96 * V_97 = V_76 -> V_98 . V_83 ;
if ( ! F_92 ( V_76 ) )
return;
if ( V_97 -> V_10 ) {
struct V_149 * V_150 = F_130 ( V_76 ) ;
if ( V_150 ) {
F_32 ( V_97 -> V_10 !=
F_136 ( V_150 ) ) ;
F_91 ( V_97 -> V_10 , V_76 ) ;
F_134 ( V_150 ) ;
}
}
F_137 ( V_76 ) ;
}
static int F_138 ( struct V_75 * V_76 ,
struct V_151 * V_152 )
{
struct V_96 * V_97 = V_76 -> V_98 . V_83 ;
struct V_73 * V_37 = F_139 ( V_152 -> V_153 ) ;
struct V_11 * V_12 , * V_141 ;
if ( ! V_37 )
return - V_128 ;
V_12 = F_140 ( V_37 ) ;
if ( ! V_12 )
return - V_128 ;
if ( ! V_97 ) {
V_97 = F_76 ( sizeof( * V_97 ) , V_79 ) ;
if ( ! V_97 )
return - V_80 ;
F_81 ( & V_97 -> V_154 ) ;
F_141 ( & V_97 -> V_99 ) ;
V_76 -> V_98 . V_83 = V_97 ;
}
F_93 (entry, &owner->controllers, owner_node)
if ( V_141 == V_12 )
return 0 ;
F_98 ( & V_12 -> V_155 , & V_97 -> V_154 ) ;
V_12 -> V_42 = V_76 ;
F_142 ( V_76 , V_12 -> V_37 , V_156 ) ;
return 0 ;
}
static int T_7 F_143 ( void )
{
int V_50 ;
V_125 = F_144 ( L_21 ,
V_124 , V_124 , 0 , NULL ) ;
if ( ! V_125 ) {
F_116 ( L_22 , V_127 ) ;
return - V_80 ;
}
V_50 = F_145 ( & V_157 ) ;
if ( V_50 ) {
F_116 ( L_23 , V_127 ) ;
goto V_158;
}
V_159 = F_105 ( V_125 , V_79 ) ;
if ( V_159 == NULL ) {
F_116 ( L_24 ,
V_127 ) ;
V_50 = - V_80 ;
goto V_160;
}
V_50 = F_146 ( & V_161 , & V_84 ) ;
if ( V_50 ) {
F_116 ( L_25 ,
V_127 ) ;
goto V_162;
}
V_163 = true ;
return 0 ;
V_162:
F_90 ( V_125 , V_159 ) ;
V_160:
F_147 ( & V_157 ) ;
V_158:
F_148 ( V_125 ) ;
return V_50 ;
}
static int T_7 F_149 ( struct V_164 * V_153 )
{
struct V_73 * V_74 ;
if ( ! V_163 )
F_143 () ;
V_74 = F_150 ( V_153 , NULL , V_161 . V_165 ) ;
if ( ! V_74 )
return - V_128 ;
if ( ! V_101 )
V_101 = & V_74 -> V_76 ;
return 0 ;
}
