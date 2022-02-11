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
if ( F_14 ( V_12 -> V_19 ) < 5 ) {
for ( V_16 = 0 ; V_16 < V_22 ; V_16 ++ ) {
F_10 ( ( V_1 & V_23 ) | 1 ,
V_12 -> V_14 + V_24 ) ;
V_1 += V_25 ;
}
} else {
if ( V_22 == 1 ) {
F_10 ( ( V_1 & V_23 ) | 1 ,
V_12 -> V_14 + V_26 ) ;
} else {
F_10 ( ( V_1 & V_23 ) ,
V_12 -> V_14 + V_27 ) ;
F_10 ( ( V_1 & V_23 ) + ( V_22 - 1 ) * V_25 ,
V_12 -> V_14 + V_28 ) ;
F_10 ( 1 , V_12 -> V_14 + V_29 ) ;
}
}
}
static void F_16 ( struct V_11 * V_12 , T_4 V_30 )
{
if ( F_14 ( V_12 -> V_19 ) < 5 )
F_10 ( V_30 , V_12 -> V_14 + V_31 ) ;
else
F_10 ( V_30 >> V_32 ,
V_12 -> V_14 + V_33 ) ;
F_13 ( V_12 ) ;
}
static void F_17 ( struct V_11 * V_12 )
{
F_18 ( F_19 ( V_12 -> V_34 ) ) ;
F_18 ( F_19 ( V_12 -> V_35 ) ) ;
F_18 ( F_19 ( V_12 -> V_36 ) ) ;
F_18 ( F_19 ( V_12 -> V_37 ) ) ;
}
static void F_20 ( struct V_11 * V_12 )
{
F_21 ( V_12 -> V_37 ) ;
F_21 ( V_12 -> V_36 ) ;
F_21 ( V_12 -> V_35 ) ;
F_21 ( V_12 -> V_34 ) ;
}
static void F_22 ( struct V_11 * V_12 )
{
T_1 V_38 ;
F_17 ( V_12 ) ;
V_38 = F_12 ( V_12 -> V_14 + V_39 ) ;
if ( V_38 == 0x80000001u )
V_12 -> V_19 = F_23 ( 1 , 0 ) ;
else
V_12 -> V_19 = F_24 ( V_38 ) ;
F_25 ( V_12 -> V_40 , L_1 ,
F_14 ( V_12 -> V_19 ) , F_26 ( V_12 -> V_19 ) ) ;
F_20 ( V_12 ) ;
}
static void F_27 ( struct V_11 * V_12 ,
const struct V_41 * V_42 ,
T_2 V_43 )
{
T_3 * V_44 ;
F_28 ( V_12 -> V_40 , L_2 ,
F_29 ( V_12 -> V_45 ) , V_42 -> V_46 , V_43 ) ;
F_25 ( V_12 -> V_40 , L_3 , & V_12 -> V_5 ) ;
V_44 = F_3 ( F_5 ( V_12 -> V_5 ) , V_43 ) ;
F_25 ( V_12 -> V_40 , L_4 , * V_44 ) ;
if ( F_30 ( V_44 ) ) {
V_44 = F_4 ( V_44 , V_43 ) ;
F_25 ( V_12 -> V_40 , L_5 , * V_44 ) ;
}
}
static T_5 F_31 ( int V_47 , void * V_48 )
{
struct V_11 * V_12 = V_48 ;
const struct V_41 * V_42 ;
unsigned int V_16 , V_49 , V_50 ;
T_2 V_43 = - 1 ;
unsigned short V_51 , V_52 ;
int V_53 = - V_54 ;
F_32 ( ! V_12 -> V_55 ) ;
if ( F_14 ( V_12 -> V_19 ) < 5 ) {
V_51 = V_56 ;
V_52 = V_57 ;
V_42 = V_58 ;
V_49 = F_33 ( V_58 ) ;
} else {
V_51 = V_59 ;
V_52 = V_60 ;
V_42 = V_61 ;
V_49 = F_33 ( V_61 ) ;
}
F_34 ( & V_12 -> V_62 ) ;
F_35 ( V_12 -> V_34 ) ;
V_50 = F_36 ( F_12 ( V_12 -> V_14 + V_51 ) ) ;
for ( V_16 = 0 ; V_16 < V_49 ; V_16 ++ , V_42 ++ )
if ( V_42 -> V_63 == V_50 )
break;
F_18 ( V_16 == V_49 ) ;
V_43 = F_12 ( V_12 -> V_14 + V_42 -> V_64 ) ;
F_27 ( V_12 , V_42 , V_43 ) ;
if ( V_12 -> V_10 )
V_53 = F_37 ( & V_12 -> V_10 -> V_10 ,
V_12 -> V_45 , V_43 , V_42 -> type ) ;
F_18 ( V_53 != 0 ) ;
F_10 ( 1 << V_50 , V_12 -> V_14 + V_52 ) ;
F_9 ( V_12 ) ;
F_38 ( V_12 -> V_34 ) ;
F_39 ( & V_12 -> V_62 ) ;
return V_65 ;
}
static void F_40 ( struct V_11 * V_12 )
{
unsigned long V_66 ;
F_35 ( V_12 -> V_34 ) ;
F_41 ( & V_12 -> V_62 , V_66 ) ;
F_10 ( V_67 , V_12 -> V_14 + V_15 ) ;
F_10 ( 0 , V_12 -> V_14 + V_68 ) ;
V_12 -> V_55 = false ;
F_42 ( & V_12 -> V_62 , V_66 ) ;
F_20 ( V_12 ) ;
}
static void F_43 ( struct V_11 * V_12 )
{
unsigned int V_69 ;
if ( V_12 -> V_19 <= F_23 ( 3 , 1 ) )
V_69 = V_70 | F_44 ( 15 ) ;
else if ( V_12 -> V_19 <= F_23 ( 3 , 2 ) )
V_69 = V_70 | F_44 ( 15 ) | V_71 | V_72 ;
else
V_69 = F_44 ( 15 ) | V_71 | V_73 ;
V_69 |= V_74 ;
F_10 ( V_69 , V_12 -> V_14 + V_68 ) ;
}
static void F_45 ( struct V_11 * V_12 )
{
unsigned long V_66 ;
F_17 ( V_12 ) ;
F_41 ( & V_12 -> V_62 , V_66 ) ;
F_10 ( V_17 , V_12 -> V_14 + V_15 ) ;
F_43 ( V_12 ) ;
F_16 ( V_12 , V_12 -> V_5 ) ;
F_10 ( V_13 , V_12 -> V_14 + V_15 ) ;
V_12 -> V_55 = true ;
F_42 ( & V_12 -> V_62 , V_66 ) ;
F_38 ( V_12 -> V_34 ) ;
}
static void F_46 ( struct V_11 * V_12 ,
T_2 V_1 )
{
unsigned long V_66 ;
F_41 ( & V_12 -> V_62 , V_66 ) ;
if ( V_12 -> V_55 && V_12 -> V_19 >= F_23 ( 3 , 3 ) ) {
F_35 ( V_12 -> V_34 ) ;
if ( F_11 ( V_12 ) ) {
if ( V_12 -> V_19 >= F_23 ( 5 , 0 ) )
F_13 ( V_12 ) ;
else
F_15 ( V_12 , V_1 , 1 ) ;
F_9 ( V_12 ) ;
}
F_38 ( V_12 -> V_34 ) ;
}
F_42 ( & V_12 -> V_62 , V_66 ) ;
}
static void F_47 ( struct V_11 * V_12 ,
T_2 V_1 , T_6 V_75 )
{
unsigned long V_66 ;
F_41 ( & V_12 -> V_62 , V_66 ) ;
if ( V_12 -> V_55 ) {
unsigned int V_22 = 1 ;
F_35 ( V_12 -> V_34 ) ;
if ( F_14 ( V_12 -> V_19 ) == 2 )
V_22 = F_48 (unsigned int, size / PAGE_SIZE, 64 ) ;
if ( F_11 ( V_12 ) ) {
F_15 ( V_12 , V_1 , V_22 ) ;
F_9 ( V_12 ) ;
}
F_38 ( V_12 -> V_34 ) ;
}
F_42 ( & V_12 -> V_62 , V_66 ) ;
}
static int T_7 F_49 ( struct V_76 * V_77 )
{
int V_47 , V_53 ;
struct V_78 * V_79 = & V_77 -> V_79 ;
struct V_11 * V_12 ;
struct V_80 * V_81 ;
V_12 = F_50 ( V_79 , sizeof( * V_12 ) , V_82 ) ;
if ( ! V_12 )
return - V_83 ;
V_81 = F_51 ( V_77 , V_84 , 0 ) ;
V_12 -> V_14 = F_52 ( V_79 , V_81 ) ;
if ( F_53 ( V_12 -> V_14 ) )
return F_54 ( V_12 -> V_14 ) ;
V_47 = F_55 ( V_77 , 0 ) ;
if ( V_47 <= 0 ) {
F_28 ( V_79 , L_6 ) ;
return V_47 ;
}
V_53 = F_56 ( V_79 , V_47 , F_31 , 0 ,
F_29 ( V_79 ) , V_12 ) ;
if ( V_53 ) {
F_28 ( V_79 , L_7 , V_47 ) ;
return V_53 ;
}
V_12 -> V_35 = F_57 ( V_79 , L_8 ) ;
if ( F_54 ( V_12 -> V_35 ) == - V_85 )
V_12 -> V_35 = NULL ;
else if ( F_53 ( V_12 -> V_35 ) )
return F_54 ( V_12 -> V_35 ) ;
V_12 -> V_37 = F_57 ( V_79 , L_9 ) ;
if ( F_54 ( V_12 -> V_37 ) == - V_85 )
V_12 -> V_37 = NULL ;
else if ( F_53 ( V_12 -> V_37 ) )
return F_54 ( V_12 -> V_37 ) ;
V_12 -> V_36 = F_57 ( V_79 , L_10 ) ;
if ( F_54 ( V_12 -> V_36 ) == - V_85 )
V_12 -> V_36 = NULL ;
else if ( F_53 ( V_12 -> V_36 ) )
return F_54 ( V_12 -> V_36 ) ;
if ( ! V_12 -> V_35 && ( ! V_12 -> V_37 || ! V_12 -> V_36 ) ) {
F_28 ( V_79 , L_11 ) ;
return - V_54 ;
}
V_12 -> V_34 = F_57 ( V_79 , L_12 ) ;
if ( F_54 ( V_12 -> V_34 ) == - V_85 )
V_12 -> V_34 = NULL ;
else if ( F_53 ( V_12 -> V_34 ) )
return F_54 ( V_12 -> V_34 ) ;
V_12 -> V_40 = V_79 ;
F_58 ( & V_12 -> V_62 ) ;
V_53 = F_59 ( & V_12 -> V_86 , & V_77 -> V_79 , NULL ,
F_29 ( V_12 -> V_40 ) ) ;
if ( V_53 )
return V_53 ;
F_60 ( & V_12 -> V_86 , & V_87 ) ;
F_61 ( & V_12 -> V_86 , & V_79 -> V_88 -> V_89 ) ;
V_53 = F_62 ( & V_12 -> V_86 ) ;
if ( V_53 )
return V_53 ;
F_63 ( V_77 , V_12 ) ;
F_22 ( V_12 ) ;
if ( V_90 < 0 ) {
if ( F_14 ( V_12 -> V_19 ) < 5 ) {
V_90 = V_91 ;
V_92 = V_93 ;
V_94 = V_95 ;
} else {
V_90 = V_96 ;
V_92 = V_97 ;
V_94 = V_98 ;
}
}
if ( ! V_99 )
V_99 = & V_77 -> V_79 ;
F_64 ( V_79 ) ;
return 0 ;
}
static int T_8 F_65 ( struct V_78 * V_79 )
{
struct V_11 * V_12 = F_66 ( V_79 ) ;
struct V_78 * V_45 = V_12 -> V_45 ;
if ( V_45 ) {
struct V_100 * V_101 = V_45 -> V_102 . V_86 ;
F_67 ( & V_101 -> V_103 ) ;
if ( V_12 -> V_10 ) {
F_25 ( V_12 -> V_40 , L_13 ) ;
F_40 ( V_12 ) ;
}
F_68 ( & V_101 -> V_103 ) ;
}
return 0 ;
}
static int T_8 F_69 ( struct V_78 * V_79 )
{
struct V_11 * V_12 = F_66 ( V_79 ) ;
struct V_78 * V_45 = V_12 -> V_45 ;
if ( V_45 ) {
struct V_100 * V_101 = V_45 -> V_102 . V_86 ;
F_67 ( & V_101 -> V_103 ) ;
if ( V_12 -> V_10 ) {
F_25 ( V_12 -> V_40 , L_14 ) ;
F_45 ( V_12 ) ;
}
F_68 ( & V_101 -> V_103 ) ;
}
return 0 ;
}
static inline void F_70 ( T_3 * V_44 , T_3 V_104 )
{
F_71 ( V_99 , F_72 ( V_44 ) , sizeof( * V_44 ) ,
V_105 ) ;
* V_44 = F_73 ( V_104 ) ;
F_74 ( V_99 , F_72 ( V_44 ) , sizeof( * V_44 ) ,
V_105 ) ;
}
static struct V_8 * F_75 ( unsigned type )
{
struct V_7 * V_10 ;
T_9 V_106 ;
int V_16 ;
F_18 ( V_90 < 0 || ! V_99 ) ;
V_10 = F_76 ( sizeof( * V_10 ) , V_82 ) ;
if ( ! V_10 )
return NULL ;
if ( type == V_107 ) {
if ( F_77 ( & V_10 -> V_10 ) != 0 )
goto V_108;
} else if ( type != V_109 ) {
goto V_108;
}
V_10 -> V_5 = ( T_3 * ) F_78 ( V_82 , 2 ) ;
if ( ! V_10 -> V_5 )
goto V_110;
V_10 -> V_111 = ( short * ) F_78 ( V_82 | V_112 , 1 ) ;
if ( ! V_10 -> V_111 )
goto V_113;
for ( V_16 = 0 ; V_16 < V_114 ; V_16 ++ )
V_10 -> V_5 [ V_16 ] = V_115 ;
V_106 = F_79 ( V_99 , V_10 -> V_5 , V_116 ,
V_105 ) ;
F_18 ( V_106 != F_72 ( V_10 -> V_5 ) ) ;
if ( F_80 ( V_99 , V_106 ) )
goto V_117;
F_58 ( & V_10 -> V_62 ) ;
F_58 ( & V_10 -> V_118 ) ;
F_81 ( & V_10 -> V_119 ) ;
V_10 -> V_10 . V_120 . V_121 = 0 ;
V_10 -> V_10 . V_120 . V_122 = ~ 0UL ;
V_10 -> V_10 . V_120 . V_123 = true ;
return & V_10 -> V_10 ;
V_117:
F_82 ( ( unsigned long ) V_10 -> V_111 , 1 ) ;
V_113:
F_82 ( ( unsigned long ) V_10 -> V_5 , 2 ) ;
V_110:
if ( type == V_107 )
F_83 ( & V_10 -> V_10 ) ;
V_108:
F_84 ( V_10 ) ;
return NULL ;
}
static void F_85 ( struct V_8 * V_8 )
{
struct V_7 * V_10 = F_7 ( V_8 ) ;
struct V_11 * V_12 , * V_124 ;
unsigned long V_66 ;
int V_16 ;
F_32 ( ! F_86 ( & V_10 -> V_119 ) ) ;
F_41 ( & V_10 -> V_62 , V_66 ) ;
F_87 (data, next, &domain->clients, domain_node) {
F_34 ( & V_12 -> V_62 ) ;
F_40 ( V_12 ) ;
V_12 -> V_5 = 0 ;
V_12 -> V_10 = NULL ;
F_88 ( & V_12 -> V_125 ) ;
F_39 ( & V_12 -> V_62 ) ;
}
F_42 ( & V_10 -> V_62 , V_66 ) ;
if ( V_8 -> type == V_107 )
F_83 ( V_8 ) ;
F_89 ( V_99 , F_72 ( V_10 -> V_5 ) , V_116 ,
V_105 ) ;
for ( V_16 = 0 ; V_16 < V_114 ; V_16 ++ )
if ( F_30 ( V_10 -> V_5 + V_16 ) ) {
T_4 V_126 = F_6 ( V_10 -> V_5 + V_16 ) ;
F_89 ( V_99 , V_126 , V_127 ,
V_105 ) ;
F_90 ( V_128 ,
F_5 ( V_126 ) ) ;
}
F_82 ( ( unsigned long ) V_10 -> V_5 , 2 ) ;
F_82 ( ( unsigned long ) V_10 -> V_111 , 1 ) ;
F_84 ( V_10 ) ;
}
static void F_91 ( struct V_8 * V_8 ,
struct V_78 * V_79 )
{
struct V_100 * V_101 = V_79 -> V_102 . V_86 ;
struct V_7 * V_10 = F_7 ( V_8 ) ;
T_4 V_129 = F_72 ( V_10 -> V_5 ) ;
struct V_11 * V_12 , * V_124 ;
unsigned long V_66 ;
if ( ! F_92 ( V_79 ) || V_101 -> V_10 != V_8 )
return;
F_67 ( & V_101 -> V_103 ) ;
F_93 (data, &owner->controllers, owner_node) {
F_94 ( V_12 -> V_40 ) ;
if ( F_95 ( V_12 -> V_40 ) )
F_40 ( V_12 ) ;
F_96 ( V_12 -> V_40 ) ;
}
F_41 ( & V_10 -> V_62 , V_66 ) ;
F_87 (data, next, &domain->clients, domain_node) {
F_34 ( & V_12 -> V_62 ) ;
V_12 -> V_5 = 0 ;
V_12 -> V_10 = NULL ;
F_88 ( & V_12 -> V_125 ) ;
F_39 ( & V_12 -> V_62 ) ;
}
V_101 -> V_10 = NULL ;
F_42 ( & V_10 -> V_62 , V_66 ) ;
F_68 ( & V_101 -> V_103 ) ;
F_25 ( V_79 , L_15 , V_130 ,
& V_129 ) ;
}
static int F_97 ( struct V_8 * V_8 ,
struct V_78 * V_79 )
{
struct V_100 * V_101 = V_79 -> V_102 . V_86 ;
struct V_7 * V_10 = F_7 ( V_8 ) ;
struct V_11 * V_12 ;
T_4 V_129 = F_72 ( V_10 -> V_5 ) ;
unsigned long V_66 ;
if ( ! F_92 ( V_79 ) )
return - V_131 ;
if ( V_101 -> V_10 )
F_91 ( V_101 -> V_10 , V_79 ) ;
F_67 ( & V_101 -> V_103 ) ;
F_41 ( & V_10 -> V_62 , V_66 ) ;
F_93 (data, &owner->controllers, owner_node) {
F_34 ( & V_12 -> V_62 ) ;
V_12 -> V_5 = V_129 ;
V_12 -> V_10 = V_10 ;
F_98 ( & V_12 -> V_125 , & V_10 -> V_119 ) ;
F_39 ( & V_12 -> V_62 ) ;
}
V_101 -> V_10 = V_8 ;
F_42 ( & V_10 -> V_62 , V_66 ) ;
F_93 (data, &owner->controllers, owner_node) {
F_94 ( V_12 -> V_40 ) ;
if ( F_95 ( V_12 -> V_40 ) )
F_45 ( V_12 ) ;
F_96 ( V_12 -> V_40 ) ;
}
F_68 ( & V_101 -> V_103 ) ;
F_25 ( V_79 , L_16 , V_130 ,
& V_129 ) ;
return 0 ;
}
static T_3 * F_99 ( struct V_7 * V_10 ,
T_3 * V_6 , T_2 V_1 , short * V_132 )
{
if ( F_100 ( V_6 ) ) {
F_101 ( 1 , L_17 , V_1 ) ;
return F_102 ( - V_133 ) ;
}
if ( F_103 ( V_6 ) ) {
T_9 V_106 ;
T_3 * V_134 ;
bool V_135 = F_104 ( V_6 ) ;
V_134 = F_105 ( V_128 , V_136 ) ;
F_18 ( ( V_137 ) V_134 & ( V_127 - 1 ) ) ;
if ( ! V_134 )
return F_102 ( - V_83 ) ;
F_70 ( V_6 , F_106 ( F_72 ( V_134 ) ) ) ;
F_107 ( V_134 ) ;
* V_132 = V_4 ;
V_106 = F_79 ( V_99 , V_134 , V_127 ,
V_105 ) ;
if ( F_80 ( V_99 , V_106 ) ) {
F_90 ( V_128 , V_134 ) ;
return F_102 ( - V_133 ) ;
}
if ( V_135 ) {
struct V_11 * V_12 ;
F_34 ( & V_10 -> V_62 ) ;
F_93 (data, &domain->clients, domain_node)
F_46 ( V_12 , V_1 ) ;
F_39 ( & V_10 -> V_62 ) ;
}
}
return F_4 ( V_6 , V_1 ) ;
}
static int F_108 ( struct V_7 * V_10 ,
T_3 * V_6 , T_2 V_1 ,
T_4 V_138 , int V_139 , short * V_140 )
{
if ( F_100 ( V_6 ) ) {
F_101 ( 1 , L_18 ,
V_1 ) ;
return - V_133 ;
}
if ( F_30 ( V_6 ) ) {
if ( * V_140 != V_4 ) {
F_101 ( 1 , L_18 ,
V_1 ) ;
return - V_133 ;
}
F_90 ( V_128 , F_4 ( V_6 , 0 ) ) ;
* V_140 = 0 ;
}
F_70 ( V_6 , F_109 ( V_138 , V_139 ) ) ;
F_34 ( & V_10 -> V_62 ) ;
if ( F_110 ( V_6 ) ) {
struct V_11 * V_12 ;
F_93 (data, &domain->clients, domain_node)
F_46 ( V_12 , V_1 ) ;
}
F_39 ( & V_10 -> V_62 ) ;
return 0 ;
}
static int F_111 ( T_3 * V_134 , T_4 V_138 , T_6 V_75 ,
int V_139 , short * V_140 )
{
if ( V_75 == V_25 ) {
if ( F_32 ( ! F_112 ( V_134 ) ) )
return - V_133 ;
F_70 ( V_134 , F_113 ( V_138 , V_139 ) ) ;
* V_140 -= 1 ;
} else {
int V_16 ;
T_9 V_141 = F_72 ( V_134 ) ;
F_71 ( V_99 , V_141 ,
sizeof( * V_134 ) * V_142 ,
V_105 ) ;
for ( V_16 = 0 ; V_16 < V_142 ; V_16 ++ , V_134 ++ ) {
if ( F_32 ( ! F_112 ( V_134 ) ) ) {
if ( V_16 > 0 )
memset ( V_134 - V_16 , 0 , sizeof( * V_134 ) * V_16 ) ;
return - V_133 ;
}
* V_134 = F_114 ( V_138 , V_139 ) ;
}
F_74 ( V_99 , V_141 ,
sizeof( * V_134 ) * V_142 ,
V_105 ) ;
* V_140 -= V_142 ;
}
return 0 ;
}
static int F_115 ( struct V_8 * V_8 ,
unsigned long V_143 , T_4 V_138 , T_6 V_75 ,
int V_139 )
{
struct V_7 * V_10 = F_7 ( V_8 ) ;
T_3 * V_144 ;
T_2 V_1 = ( T_2 ) V_143 ;
unsigned long V_66 ;
int V_53 = - V_83 ;
F_18 ( V_10 -> V_5 == NULL ) ;
V_139 &= V_145 ;
F_41 ( & V_10 -> V_118 , V_66 ) ;
V_144 = F_3 ( V_10 -> V_5 , V_1 ) ;
if ( V_75 == V_146 ) {
V_53 = F_108 ( V_10 , V_144 , V_1 , V_138 , V_139 ,
& V_10 -> V_111 [ F_1 ( V_1 ) ] ) ;
} else {
T_3 * V_134 ;
V_134 = F_99 ( V_10 , V_144 , V_1 ,
& V_10 -> V_111 [ F_1 ( V_1 ) ] ) ;
if ( F_53 ( V_134 ) )
V_53 = F_54 ( V_134 ) ;
else
V_53 = F_111 ( V_134 , V_138 , V_75 , V_139 ,
& V_10 -> V_111 [ F_1 ( V_1 ) ] ) ;
}
if ( V_53 )
F_116 ( L_19 ,
V_130 , V_53 , V_75 , V_1 ) ;
F_42 ( & V_10 -> V_118 , V_66 ) ;
return V_53 ;
}
static void F_117 ( struct V_7 * V_10 ,
T_2 V_1 , T_6 V_75 )
{
struct V_11 * V_12 ;
unsigned long V_66 ;
F_41 ( & V_10 -> V_62 , V_66 ) ;
F_93 (data, &domain->clients, domain_node)
F_47 ( V_12 , V_1 , V_75 ) ;
F_42 ( & V_10 -> V_62 , V_66 ) ;
}
static T_6 F_118 ( struct V_8 * V_8 ,
unsigned long V_143 , T_6 V_75 )
{
struct V_7 * V_10 = F_7 ( V_8 ) ;
T_2 V_1 = ( T_2 ) V_143 ;
T_3 * V_44 ;
T_6 V_147 ;
unsigned long V_66 ;
F_18 ( V_10 -> V_5 == NULL ) ;
F_41 ( & V_10 -> V_118 , V_66 ) ;
V_44 = F_3 ( V_10 -> V_5 , V_1 ) ;
if ( F_100 ( V_44 ) ) {
if ( F_32 ( V_75 < V_146 ) ) {
V_147 = V_146 ;
goto V_148;
}
F_70 ( V_44 , V_115 ) ;
V_75 = V_146 ;
goto V_149;
}
if ( F_119 ( F_103 ( V_44 ) ) ) {
if ( V_75 > V_146 )
V_75 = V_146 ;
goto V_149;
}
V_44 = F_4 ( V_44 , V_1 ) ;
if ( F_119 ( F_112 ( V_44 ) ) ) {
V_75 = V_25 ;
goto V_149;
}
if ( F_120 ( V_44 ) ) {
F_70 ( V_44 , 0 ) ;
V_75 = V_25 ;
V_10 -> V_111 [ F_1 ( V_1 ) ] += 1 ;
goto V_149;
}
if ( F_32 ( V_75 < V_150 ) ) {
V_147 = V_150 ;
goto V_148;
}
F_71 ( V_99 , F_72 ( V_44 ) ,
sizeof( * V_44 ) * V_142 ,
V_105 ) ;
memset ( V_44 , 0 , sizeof( * V_44 ) * V_142 ) ;
F_74 ( V_99 , F_72 ( V_44 ) ,
sizeof( * V_44 ) * V_142 ,
V_105 ) ;
V_75 = V_150 ;
V_10 -> V_111 [ F_1 ( V_1 ) ] += V_142 ;
V_149:
F_42 ( & V_10 -> V_118 , V_66 ) ;
F_117 ( V_10 , V_1 , V_75 ) ;
return V_75 ;
V_148:
F_42 ( & V_10 -> V_118 , V_66 ) ;
F_116 ( L_20 ,
V_130 , V_75 , V_1 , V_147 ) ;
return 0 ;
}
static T_4 F_121 ( struct V_8 * V_8 ,
T_9 V_1 )
{
struct V_7 * V_10 = F_7 ( V_8 ) ;
T_3 * V_144 ;
unsigned long V_66 ;
T_4 V_151 = 0 ;
F_41 ( & V_10 -> V_118 , V_66 ) ;
V_144 = F_3 ( V_10 -> V_5 , V_1 ) ;
if ( F_100 ( V_144 ) ) {
V_151 = F_122 ( V_144 ) + F_123 ( V_1 ) ;
} else if ( F_30 ( V_144 ) ) {
V_144 = F_4 ( V_144 , V_1 ) ;
if ( F_124 ( V_144 ) )
V_151 = F_125 ( V_144 ) + F_126 ( V_1 ) ;
else if ( F_120 ( V_144 ) )
V_151 = F_127 ( V_144 ) + F_128 ( V_1 ) ;
}
F_42 ( & V_10 -> V_118 , V_66 ) ;
return V_151 ;
}
static struct V_152 * F_129 ( struct V_78 * V_79 )
{
struct V_152 * V_153 ;
V_153 = F_130 ( V_79 ) ;
if ( ! V_153 )
V_153 = F_131 () ;
return V_153 ;
}
static int F_132 ( struct V_78 * V_79 )
{
struct V_152 * V_153 ;
if ( ! F_92 ( V_79 ) )
return - V_131 ;
V_153 = F_133 ( V_79 ) ;
if ( F_53 ( V_153 ) )
return F_54 ( V_153 ) ;
F_134 ( V_153 ) ;
return 0 ;
}
static void F_135 ( struct V_78 * V_79 )
{
struct V_100 * V_101 = V_79 -> V_102 . V_86 ;
if ( ! F_92 ( V_79 ) )
return;
if ( V_101 -> V_10 ) {
struct V_152 * V_153 = F_130 ( V_79 ) ;
if ( V_153 ) {
F_32 ( V_101 -> V_10 !=
F_136 ( V_153 ) ) ;
F_91 ( V_101 -> V_10 , V_79 ) ;
F_134 ( V_153 ) ;
}
}
F_137 ( V_79 ) ;
}
static int F_138 ( struct V_78 * V_79 ,
struct V_154 * V_155 )
{
struct V_100 * V_101 = V_79 -> V_102 . V_86 ;
struct V_76 * V_40 = F_139 ( V_155 -> V_156 ) ;
struct V_11 * V_12 , * V_144 ;
if ( ! V_40 )
return - V_131 ;
V_12 = F_140 ( V_40 ) ;
if ( ! V_12 )
return - V_131 ;
if ( ! V_101 ) {
V_101 = F_76 ( sizeof( * V_101 ) , V_82 ) ;
if ( ! V_101 )
return - V_83 ;
F_81 ( & V_101 -> V_157 ) ;
F_141 ( & V_101 -> V_103 ) ;
V_79 -> V_102 . V_86 = V_101 ;
}
F_93 (entry, &owner->controllers, owner_node)
if ( V_144 == V_12 )
return 0 ;
F_98 ( & V_12 -> V_158 , & V_101 -> V_157 ) ;
V_12 -> V_45 = V_79 ;
F_142 ( V_79 , V_12 -> V_40 , V_159 ) ;
return 0 ;
}
static int T_7 F_143 ( void )
{
int V_53 ;
V_128 = F_144 ( L_21 ,
V_127 , V_127 , 0 , NULL ) ;
if ( ! V_128 ) {
F_116 ( L_22 , V_130 ) ;
return - V_83 ;
}
V_53 = F_145 ( & V_160 ) ;
if ( V_53 ) {
F_116 ( L_23 , V_130 ) ;
goto V_161;
}
V_162 = F_105 ( V_128 , V_82 ) ;
if ( V_162 == NULL ) {
F_116 ( L_24 ,
V_130 ) ;
V_53 = - V_83 ;
goto V_163;
}
V_53 = F_146 ( & V_164 , & V_87 ) ;
if ( V_53 ) {
F_116 ( L_25 ,
V_130 ) ;
goto V_165;
}
return 0 ;
V_165:
F_90 ( V_128 , V_162 ) ;
V_163:
F_147 ( & V_160 ) ;
V_161:
F_148 ( V_128 ) ;
return V_53 ;
}
