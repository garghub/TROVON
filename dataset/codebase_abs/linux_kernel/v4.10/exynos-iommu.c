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
V_39 -> V_42 , V_40 , & V_12 -> V_5 ) ;
V_41 = F_3 ( F_5 ( V_12 -> V_5 ) , V_40 ) ;
F_28 ( V_12 -> V_37 , L_3 , * V_41 ) ;
if ( F_29 ( V_41 ) ) {
V_41 = F_4 ( V_41 , V_40 ) ;
F_28 ( V_12 -> V_37 , L_4 , * V_41 ) ;
}
}
static T_5 F_30 ( int V_43 , void * V_44 )
{
struct V_11 * V_12 = V_44 ;
const struct V_38 * V_39 ;
unsigned int V_16 , V_45 , V_46 ;
T_2 V_40 = - 1 ;
unsigned short V_47 , V_48 ;
int V_49 = - V_50 ;
F_31 ( ! V_12 -> V_51 ) ;
if ( F_14 ( V_12 -> V_19 ) < 5 ) {
V_47 = V_52 ;
V_48 = V_53 ;
V_39 = V_54 ;
V_45 = F_32 ( V_54 ) ;
} else {
V_47 = V_55 ;
V_48 = V_56 ;
V_39 = V_57 ;
V_45 = F_32 ( V_57 ) ;
}
F_33 ( & V_12 -> V_58 ) ;
F_34 ( V_12 -> V_31 ) ;
V_46 = F_35 ( F_12 ( V_12 -> V_14 + V_47 ) ) ;
for ( V_16 = 0 ; V_16 < V_45 ; V_16 ++ , V_39 ++ )
if ( V_39 -> V_59 == V_46 )
break;
F_18 ( V_16 == V_45 ) ;
V_40 = F_12 ( V_12 -> V_14 + V_39 -> V_60 ) ;
F_27 ( V_12 , V_39 , V_40 ) ;
if ( V_12 -> V_10 )
V_49 = F_36 ( & V_12 -> V_10 -> V_10 ,
V_12 -> V_61 , V_40 , V_39 -> type ) ;
F_18 ( V_49 != 0 ) ;
F_10 ( 1 << V_46 , V_12 -> V_14 + V_48 ) ;
F_9 ( V_12 ) ;
F_37 ( V_12 -> V_31 ) ;
F_38 ( & V_12 -> V_58 ) ;
return V_62 ;
}
static void F_39 ( struct V_11 * V_12 )
{
unsigned long V_63 ;
F_34 ( V_12 -> V_31 ) ;
F_40 ( & V_12 -> V_58 , V_63 ) ;
F_10 ( V_64 , V_12 -> V_14 + V_15 ) ;
F_10 ( 0 , V_12 -> V_14 + V_65 ) ;
V_12 -> V_51 = false ;
F_41 ( & V_12 -> V_58 , V_63 ) ;
F_20 ( V_12 ) ;
}
static void F_42 ( struct V_11 * V_12 )
{
unsigned int V_66 ;
if ( V_12 -> V_19 <= F_23 ( 3 , 1 ) )
V_66 = V_67 | F_43 ( 15 ) ;
else if ( V_12 -> V_19 <= F_23 ( 3 , 2 ) )
V_66 = V_67 | F_43 ( 15 ) | V_68 | V_69 ;
else
V_66 = F_43 ( 15 ) | V_68 | V_70 ;
V_66 |= V_71 ;
F_10 ( V_66 , V_12 -> V_14 + V_65 ) ;
}
static void F_44 ( struct V_11 * V_12 )
{
unsigned long V_63 ;
F_17 ( V_12 ) ;
F_40 ( & V_12 -> V_58 , V_63 ) ;
F_10 ( V_17 , V_12 -> V_14 + V_15 ) ;
F_42 ( V_12 ) ;
F_16 ( V_12 , V_12 -> V_5 ) ;
F_10 ( V_13 , V_12 -> V_14 + V_15 ) ;
V_12 -> V_51 = true ;
F_41 ( & V_12 -> V_58 , V_63 ) ;
F_37 ( V_12 -> V_31 ) ;
}
static void F_45 ( struct V_11 * V_12 ,
T_2 V_1 )
{
unsigned long V_63 ;
F_40 ( & V_12 -> V_58 , V_63 ) ;
if ( V_12 -> V_51 && V_12 -> V_19 >= F_23 ( 3 , 3 ) ) {
F_34 ( V_12 -> V_31 ) ;
F_15 ( V_12 , V_1 , 1 ) ;
F_37 ( V_12 -> V_31 ) ;
}
F_41 ( & V_12 -> V_58 , V_63 ) ;
}
static void F_46 ( struct V_11 * V_12 ,
T_2 V_1 , T_6 V_72 )
{
unsigned long V_63 ;
F_40 ( & V_12 -> V_58 , V_63 ) ;
if ( V_12 -> V_51 ) {
unsigned int V_22 = 1 ;
F_34 ( V_12 -> V_31 ) ;
if ( F_14 ( V_12 -> V_19 ) == 2 )
V_22 = F_47 (unsigned int, size / PAGE_SIZE, 64 ) ;
if ( F_11 ( V_12 ) ) {
F_15 ( V_12 , V_1 , V_22 ) ;
F_9 ( V_12 ) ;
}
F_37 ( V_12 -> V_31 ) ;
}
F_41 ( & V_12 -> V_58 , V_63 ) ;
}
static int T_7 F_48 ( struct V_73 * V_74 )
{
int V_43 , V_49 ;
struct V_75 * V_76 = & V_74 -> V_76 ;
struct V_11 * V_12 ;
struct V_77 * V_78 ;
V_12 = F_49 ( V_76 , sizeof( * V_12 ) , V_79 ) ;
if ( ! V_12 )
return - V_80 ;
V_78 = F_50 ( V_74 , V_81 , 0 ) ;
V_12 -> V_14 = F_51 ( V_76 , V_78 ) ;
if ( F_52 ( V_12 -> V_14 ) )
return F_53 ( V_12 -> V_14 ) ;
V_43 = F_54 ( V_74 , 0 ) ;
if ( V_43 <= 0 ) {
F_28 ( V_76 , L_5 ) ;
return V_43 ;
}
V_49 = F_55 ( V_76 , V_43 , F_30 , 0 ,
F_56 ( V_76 ) , V_12 ) ;
if ( V_49 ) {
F_28 ( V_76 , L_6 , V_43 ) ;
return V_49 ;
}
V_12 -> V_32 = F_57 ( V_76 , L_7 ) ;
if ( F_53 ( V_12 -> V_32 ) == - V_82 )
V_12 -> V_32 = NULL ;
else if ( F_52 ( V_12 -> V_32 ) )
return F_53 ( V_12 -> V_32 ) ;
V_12 -> V_34 = F_57 ( V_76 , L_8 ) ;
if ( F_53 ( V_12 -> V_34 ) == - V_82 )
V_12 -> V_34 = NULL ;
else if ( F_52 ( V_12 -> V_34 ) )
return F_53 ( V_12 -> V_34 ) ;
V_12 -> V_33 = F_57 ( V_76 , L_9 ) ;
if ( F_53 ( V_12 -> V_33 ) == - V_82 )
V_12 -> V_33 = NULL ;
else if ( F_52 ( V_12 -> V_33 ) )
return F_53 ( V_12 -> V_33 ) ;
if ( ! V_12 -> V_32 && ( ! V_12 -> V_34 || ! V_12 -> V_33 ) ) {
F_28 ( V_76 , L_10 ) ;
return - V_50 ;
}
V_12 -> V_31 = F_57 ( V_76 , L_11 ) ;
if ( F_53 ( V_12 -> V_31 ) == - V_82 )
V_12 -> V_31 = NULL ;
else if ( F_52 ( V_12 -> V_31 ) )
return F_53 ( V_12 -> V_31 ) ;
V_12 -> V_37 = V_76 ;
F_58 ( & V_12 -> V_58 ) ;
F_59 ( V_74 , V_12 ) ;
F_22 ( V_12 ) ;
if ( V_83 < 0 ) {
if ( F_14 ( V_12 -> V_19 ) < 5 ) {
V_83 = V_84 ;
V_85 = V_86 ;
V_87 = V_88 ;
} else {
V_83 = V_89 ;
V_85 = V_90 ;
V_87 = V_91 ;
}
}
F_60 ( V_76 ) ;
F_61 ( V_76 -> V_92 , & V_93 ) ;
return 0 ;
}
static int T_8 F_62 ( struct V_75 * V_76 )
{
struct V_11 * V_12 = F_63 ( V_76 ) ;
struct V_75 * V_61 = V_12 -> V_61 ;
if ( V_61 ) {
struct V_94 * V_95 = V_61 -> V_96 . V_97 ;
F_64 ( & V_95 -> V_98 ) ;
if ( V_12 -> V_10 ) {
F_25 ( V_12 -> V_37 , L_12 ) ;
F_39 ( V_12 ) ;
}
F_65 ( & V_95 -> V_98 ) ;
}
return 0 ;
}
static int T_8 F_66 ( struct V_75 * V_76 )
{
struct V_11 * V_12 = F_63 ( V_76 ) ;
struct V_75 * V_61 = V_12 -> V_61 ;
if ( V_61 ) {
struct V_94 * V_95 = V_61 -> V_96 . V_97 ;
F_64 ( & V_95 -> V_98 ) ;
if ( V_12 -> V_10 ) {
F_25 ( V_12 -> V_37 , L_13 ) ;
F_44 ( V_12 ) ;
}
F_65 ( & V_95 -> V_98 ) ;
}
return 0 ;
}
static inline void F_67 ( T_3 * V_41 , T_3 V_99 )
{
F_68 ( V_100 , F_69 ( V_41 ) , sizeof( * V_41 ) ,
V_101 ) ;
* V_41 = F_70 ( V_99 ) ;
F_71 ( V_100 , F_69 ( V_41 ) , sizeof( * V_41 ) ,
V_101 ) ;
}
static struct V_8 * F_72 ( unsigned type )
{
struct V_7 * V_10 ;
T_9 V_102 ;
int V_16 ;
F_18 ( V_83 < 0 || ! V_100 ) ;
V_10 = F_73 ( sizeof( * V_10 ) , V_79 ) ;
if ( ! V_10 )
return NULL ;
if ( type == V_103 ) {
if ( F_74 ( & V_10 -> V_10 ) != 0 )
goto V_104;
} else if ( type != V_105 ) {
goto V_104;
}
V_10 -> V_5 = ( T_3 * ) F_75 ( V_79 , 2 ) ;
if ( ! V_10 -> V_5 )
goto V_106;
V_10 -> V_107 = ( short * ) F_75 ( V_79 | V_108 , 1 ) ;
if ( ! V_10 -> V_107 )
goto V_109;
for ( V_16 = 0 ; V_16 < V_110 ; V_16 += 8 ) {
V_10 -> V_5 [ V_16 + 0 ] = V_111 ;
V_10 -> V_5 [ V_16 + 1 ] = V_111 ;
V_10 -> V_5 [ V_16 + 2 ] = V_111 ;
V_10 -> V_5 [ V_16 + 3 ] = V_111 ;
V_10 -> V_5 [ V_16 + 4 ] = V_111 ;
V_10 -> V_5 [ V_16 + 5 ] = V_111 ;
V_10 -> V_5 [ V_16 + 6 ] = V_111 ;
V_10 -> V_5 [ V_16 + 7 ] = V_111 ;
}
V_102 = F_76 ( V_100 , V_10 -> V_5 , V_112 ,
V_101 ) ;
F_18 ( V_102 != F_69 ( V_10 -> V_5 ) ) ;
F_58 ( & V_10 -> V_58 ) ;
F_58 ( & V_10 -> V_113 ) ;
F_77 ( & V_10 -> V_114 ) ;
V_10 -> V_10 . V_115 . V_116 = 0 ;
V_10 -> V_10 . V_115 . V_117 = ~ 0UL ;
V_10 -> V_10 . V_115 . V_118 = true ;
return & V_10 -> V_10 ;
V_109:
F_78 ( ( unsigned long ) V_10 -> V_5 , 2 ) ;
V_106:
if ( type == V_103 )
F_79 ( & V_10 -> V_10 ) ;
V_104:
F_80 ( V_10 ) ;
return NULL ;
}
static void F_81 ( struct V_8 * V_8 )
{
struct V_7 * V_10 = F_7 ( V_8 ) ;
struct V_11 * V_12 , * V_119 ;
unsigned long V_63 ;
int V_16 ;
F_31 ( ! F_82 ( & V_10 -> V_114 ) ) ;
F_40 ( & V_10 -> V_58 , V_63 ) ;
F_83 (data, next, &domain->clients, domain_node) {
F_33 ( & V_12 -> V_58 ) ;
F_39 ( V_12 ) ;
V_12 -> V_5 = 0 ;
V_12 -> V_10 = NULL ;
F_84 ( & V_12 -> V_120 ) ;
F_38 ( & V_12 -> V_58 ) ;
}
F_41 ( & V_10 -> V_58 , V_63 ) ;
if ( V_8 -> type == V_103 )
F_79 ( V_8 ) ;
F_85 ( V_100 , F_69 ( V_10 -> V_5 ) , V_112 ,
V_101 ) ;
for ( V_16 = 0 ; V_16 < V_110 ; V_16 ++ )
if ( F_29 ( V_10 -> V_5 + V_16 ) ) {
T_4 V_121 = F_6 ( V_10 -> V_5 + V_16 ) ;
F_85 ( V_100 , V_121 , V_122 ,
V_101 ) ;
F_86 ( V_123 ,
F_5 ( V_121 ) ) ;
}
F_78 ( ( unsigned long ) V_10 -> V_5 , 2 ) ;
F_78 ( ( unsigned long ) V_10 -> V_107 , 1 ) ;
F_80 ( V_10 ) ;
}
static void F_87 ( struct V_8 * V_8 ,
struct V_75 * V_76 )
{
struct V_94 * V_95 = V_76 -> V_96 . V_97 ;
struct V_7 * V_10 = F_7 ( V_8 ) ;
T_4 V_124 = F_69 ( V_10 -> V_5 ) ;
struct V_11 * V_12 , * V_119 ;
unsigned long V_63 ;
if ( ! F_88 ( V_76 ) || V_95 -> V_10 != V_8 )
return;
F_64 ( & V_95 -> V_98 ) ;
F_89 (data, &owner->controllers, owner_node) {
F_90 ( V_12 -> V_37 ) ;
if ( F_91 ( V_12 -> V_37 ) )
F_39 ( V_12 ) ;
F_92 ( V_12 -> V_37 ) ;
}
F_40 ( & V_10 -> V_58 , V_63 ) ;
F_83 (data, next, &domain->clients, domain_node) {
F_33 ( & V_12 -> V_58 ) ;
V_12 -> V_5 = 0 ;
V_12 -> V_10 = NULL ;
F_84 ( & V_12 -> V_120 ) ;
F_38 ( & V_12 -> V_58 ) ;
}
V_95 -> V_10 = NULL ;
F_41 ( & V_10 -> V_58 , V_63 ) ;
F_65 ( & V_95 -> V_98 ) ;
F_25 ( V_76 , L_14 , V_125 ,
& V_124 ) ;
}
static int F_93 ( struct V_8 * V_8 ,
struct V_75 * V_76 )
{
struct V_94 * V_95 = V_76 -> V_96 . V_97 ;
struct V_7 * V_10 = F_7 ( V_8 ) ;
struct V_11 * V_12 ;
T_4 V_124 = F_69 ( V_10 -> V_5 ) ;
unsigned long V_63 ;
if ( ! F_88 ( V_76 ) )
return - V_126 ;
if ( V_95 -> V_10 )
F_87 ( V_95 -> V_10 , V_76 ) ;
F_64 ( & V_95 -> V_98 ) ;
F_40 ( & V_10 -> V_58 , V_63 ) ;
F_89 (data, &owner->controllers, owner_node) {
F_33 ( & V_12 -> V_58 ) ;
V_12 -> V_5 = V_124 ;
V_12 -> V_10 = V_10 ;
F_94 ( & V_12 -> V_120 , & V_10 -> V_114 ) ;
F_38 ( & V_12 -> V_58 ) ;
}
V_95 -> V_10 = V_8 ;
F_41 ( & V_10 -> V_58 , V_63 ) ;
F_89 (data, &owner->controllers, owner_node) {
F_90 ( V_12 -> V_37 ) ;
if ( F_91 ( V_12 -> V_37 ) )
F_44 ( V_12 ) ;
F_92 ( V_12 -> V_37 ) ;
}
F_65 ( & V_95 -> V_98 ) ;
F_25 ( V_76 , L_15 , V_125 ,
& V_124 ) ;
return 0 ;
}
static T_3 * F_95 ( struct V_7 * V_10 ,
T_3 * V_6 , T_2 V_1 , short * V_127 )
{
if ( F_96 ( V_6 ) ) {
F_97 ( 1 , L_16 , V_1 ) ;
return F_98 ( - V_128 ) ;
}
if ( F_99 ( V_6 ) ) {
T_3 * V_129 ;
bool V_130 = F_100 ( V_6 ) ;
V_129 = F_101 ( V_123 , V_131 ) ;
F_18 ( ( V_132 ) V_129 & ( V_122 - 1 ) ) ;
if ( ! V_129 )
return F_98 ( - V_80 ) ;
F_67 ( V_6 , F_102 ( F_69 ( V_129 ) ) ) ;
F_103 ( V_129 ) ;
* V_127 = V_4 ;
F_76 ( V_100 , V_129 , V_122 , V_101 ) ;
if ( V_130 ) {
struct V_11 * V_12 ;
F_33 ( & V_10 -> V_58 ) ;
F_89 (data, &domain->clients, domain_node)
F_45 ( V_12 , V_1 ) ;
F_38 ( & V_10 -> V_58 ) ;
}
}
return F_4 ( V_6 , V_1 ) ;
}
static int F_104 ( struct V_7 * V_10 ,
T_3 * V_6 , T_2 V_1 ,
T_4 V_133 , int V_134 , short * V_135 )
{
if ( F_96 ( V_6 ) ) {
F_97 ( 1 , L_17 ,
V_1 ) ;
return - V_128 ;
}
if ( F_29 ( V_6 ) ) {
if ( * V_135 != V_4 ) {
F_97 ( 1 , L_17 ,
V_1 ) ;
return - V_128 ;
}
F_86 ( V_123 , F_4 ( V_6 , 0 ) ) ;
* V_135 = 0 ;
}
F_67 ( V_6 , F_105 ( V_133 , V_134 ) ) ;
F_33 ( & V_10 -> V_58 ) ;
if ( F_106 ( V_6 ) ) {
struct V_11 * V_12 ;
F_89 (data, &domain->clients, domain_node)
F_45 ( V_12 , V_1 ) ;
}
F_38 ( & V_10 -> V_58 ) ;
return 0 ;
}
static int F_107 ( T_3 * V_129 , T_4 V_133 , T_6 V_72 ,
int V_134 , short * V_135 )
{
if ( V_72 == V_26 ) {
if ( F_31 ( ! F_108 ( V_129 ) ) )
return - V_128 ;
F_67 ( V_129 , F_109 ( V_133 , V_134 ) ) ;
* V_135 -= 1 ;
} else {
int V_16 ;
T_9 V_136 = F_69 ( V_129 ) ;
F_68 ( V_100 , V_136 ,
sizeof( * V_129 ) * V_137 ,
V_101 ) ;
for ( V_16 = 0 ; V_16 < V_137 ; V_16 ++ , V_129 ++ ) {
if ( F_31 ( ! F_108 ( V_129 ) ) ) {
if ( V_16 > 0 )
memset ( V_129 - V_16 , 0 , sizeof( * V_129 ) * V_16 ) ;
return - V_128 ;
}
* V_129 = F_110 ( V_133 , V_134 ) ;
}
F_71 ( V_100 , V_136 ,
sizeof( * V_129 ) * V_137 ,
V_101 ) ;
* V_135 -= V_137 ;
}
return 0 ;
}
static int F_111 ( struct V_8 * V_8 ,
unsigned long V_138 , T_4 V_133 , T_6 V_72 ,
int V_134 )
{
struct V_7 * V_10 = F_7 ( V_8 ) ;
T_3 * V_139 ;
T_2 V_1 = ( T_2 ) V_138 ;
unsigned long V_63 ;
int V_49 = - V_80 ;
F_18 ( V_10 -> V_5 == NULL ) ;
V_134 &= V_140 ;
F_40 ( & V_10 -> V_113 , V_63 ) ;
V_139 = F_3 ( V_10 -> V_5 , V_1 ) ;
if ( V_72 == V_141 ) {
V_49 = F_104 ( V_10 , V_139 , V_1 , V_133 , V_134 ,
& V_10 -> V_107 [ F_1 ( V_1 ) ] ) ;
} else {
T_3 * V_129 ;
V_129 = F_95 ( V_10 , V_139 , V_1 ,
& V_10 -> V_107 [ F_1 ( V_1 ) ] ) ;
if ( F_52 ( V_129 ) )
V_49 = F_53 ( V_129 ) ;
else
V_49 = F_107 ( V_129 , V_133 , V_72 , V_134 ,
& V_10 -> V_107 [ F_1 ( V_1 ) ] ) ;
}
if ( V_49 )
F_112 ( L_18 ,
V_125 , V_49 , V_72 , V_1 ) ;
F_41 ( & V_10 -> V_113 , V_63 ) ;
return V_49 ;
}
static void F_113 ( struct V_7 * V_10 ,
T_2 V_1 , T_6 V_72 )
{
struct V_11 * V_12 ;
unsigned long V_63 ;
F_40 ( & V_10 -> V_58 , V_63 ) ;
F_89 (data, &domain->clients, domain_node)
F_46 ( V_12 , V_1 , V_72 ) ;
F_41 ( & V_10 -> V_58 , V_63 ) ;
}
static T_6 F_114 ( struct V_8 * V_8 ,
unsigned long V_138 , T_6 V_72 )
{
struct V_7 * V_10 = F_7 ( V_8 ) ;
T_2 V_1 = ( T_2 ) V_138 ;
T_3 * V_41 ;
T_6 V_142 ;
unsigned long V_63 ;
F_18 ( V_10 -> V_5 == NULL ) ;
F_40 ( & V_10 -> V_113 , V_63 ) ;
V_41 = F_3 ( V_10 -> V_5 , V_1 ) ;
if ( F_96 ( V_41 ) ) {
if ( F_31 ( V_72 < V_141 ) ) {
V_142 = V_141 ;
goto V_143;
}
F_67 ( V_41 , V_111 ) ;
V_72 = V_141 ;
goto V_144;
}
if ( F_115 ( F_99 ( V_41 ) ) ) {
if ( V_72 > V_141 )
V_72 = V_141 ;
goto V_144;
}
V_41 = F_4 ( V_41 , V_1 ) ;
if ( F_115 ( F_108 ( V_41 ) ) ) {
V_72 = V_26 ;
goto V_144;
}
if ( F_116 ( V_41 ) ) {
F_67 ( V_41 , 0 ) ;
V_72 = V_26 ;
V_10 -> V_107 [ F_1 ( V_1 ) ] += 1 ;
goto V_144;
}
if ( F_31 ( V_72 < V_145 ) ) {
V_142 = V_145 ;
goto V_143;
}
F_68 ( V_100 , F_69 ( V_41 ) ,
sizeof( * V_41 ) * V_137 ,
V_101 ) ;
memset ( V_41 , 0 , sizeof( * V_41 ) * V_137 ) ;
F_71 ( V_100 , F_69 ( V_41 ) ,
sizeof( * V_41 ) * V_137 ,
V_101 ) ;
V_72 = V_145 ;
V_10 -> V_107 [ F_1 ( V_1 ) ] += V_137 ;
V_144:
F_41 ( & V_10 -> V_113 , V_63 ) ;
F_113 ( V_10 , V_1 , V_72 ) ;
return V_72 ;
V_143:
F_41 ( & V_10 -> V_113 , V_63 ) ;
F_112 ( L_19 ,
V_125 , V_72 , V_1 , V_142 ) ;
return 0 ;
}
static T_4 F_117 ( struct V_8 * V_8 ,
T_9 V_1 )
{
struct V_7 * V_10 = F_7 ( V_8 ) ;
T_3 * V_139 ;
unsigned long V_63 ;
T_4 V_146 = 0 ;
F_40 ( & V_10 -> V_113 , V_63 ) ;
V_139 = F_3 ( V_10 -> V_5 , V_1 ) ;
if ( F_96 ( V_139 ) ) {
V_146 = F_118 ( V_139 ) + F_119 ( V_1 ) ;
} else if ( F_29 ( V_139 ) ) {
V_139 = F_4 ( V_139 , V_1 ) ;
if ( F_120 ( V_139 ) )
V_146 = F_121 ( V_139 ) + F_122 ( V_1 ) ;
else if ( F_116 ( V_139 ) )
V_146 = F_123 ( V_139 ) + F_124 ( V_1 ) ;
}
F_41 ( & V_10 -> V_113 , V_63 ) ;
return V_146 ;
}
static struct V_147 * F_125 ( struct V_75 * V_76 )
{
struct V_147 * V_148 ;
V_148 = F_126 ( V_76 ) ;
if ( ! V_148 )
V_148 = F_127 () ;
return V_148 ;
}
static int F_128 ( struct V_75 * V_76 )
{
struct V_147 * V_148 ;
if ( ! F_88 ( V_76 ) )
return - V_126 ;
V_148 = F_129 ( V_76 ) ;
if ( F_52 ( V_148 ) )
return F_53 ( V_148 ) ;
F_130 ( V_148 ) ;
return 0 ;
}
static void F_131 ( struct V_75 * V_76 )
{
if ( ! F_88 ( V_76 ) )
return;
F_132 ( V_76 ) ;
}
static int F_133 ( struct V_75 * V_76 ,
struct V_149 * V_150 )
{
struct V_94 * V_95 = V_76 -> V_96 . V_97 ;
struct V_73 * V_37 = F_134 ( V_150 -> V_151 ) ;
struct V_11 * V_12 ;
if ( ! V_37 )
return - V_126 ;
V_12 = F_135 ( V_37 ) ;
if ( ! V_12 )
return - V_126 ;
if ( ! V_95 ) {
V_95 = F_73 ( sizeof( * V_95 ) , V_79 ) ;
if ( ! V_95 )
return - V_80 ;
F_77 ( & V_95 -> V_152 ) ;
F_136 ( & V_95 -> V_98 ) ;
V_76 -> V_96 . V_97 = V_95 ;
}
F_94 ( & V_12 -> V_153 , & V_95 -> V_152 ) ;
V_12 -> V_61 = V_76 ;
F_137 ( V_76 , V_12 -> V_37 , V_154 ) ;
return 0 ;
}
static int T_7 F_138 ( void )
{
int V_49 ;
V_123 = F_139 ( L_20 ,
V_122 , V_122 , 0 , NULL ) ;
if ( ! V_123 ) {
F_112 ( L_21 , V_125 ) ;
return - V_80 ;
}
V_49 = F_140 ( & V_155 ) ;
if ( V_49 ) {
F_112 ( L_22 , V_125 ) ;
goto V_156;
}
V_157 = F_101 ( V_123 , V_79 ) ;
if ( V_157 == NULL ) {
F_112 ( L_23 ,
V_125 ) ;
V_49 = - V_80 ;
goto V_158;
}
V_49 = F_141 ( & V_159 , & V_93 ) ;
if ( V_49 ) {
F_112 ( L_24 ,
V_125 ) ;
goto V_160;
}
V_161 = true ;
return 0 ;
V_160:
F_86 ( V_123 , V_157 ) ;
V_158:
F_142 ( & V_155 ) ;
V_156:
F_143 ( V_123 ) ;
return V_49 ;
}
static int T_7 F_144 ( struct V_162 * V_151 )
{
struct V_73 * V_74 ;
if ( ! V_161 )
F_138 () ;
V_74 = F_145 ( V_151 , NULL , V_159 . V_163 ) ;
if ( ! V_74 )
return - V_126 ;
if ( ! V_100 )
V_100 = & V_74 -> V_76 ;
return 0 ;
}
