T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_2 ( & V_2 -> V_4 ) ;
V_3 = F_3 ( V_2 -> V_5 , V_2 -> V_6 , V_2 -> V_7 ) ;
if ( V_3 >= V_2 -> V_6 ) {
V_2 -> V_8 = ( V_2 -> V_8 + V_2 -> V_6 + V_2 -> V_9 )
& V_2 -> V_10 ;
V_3 = F_4 ( V_2 -> V_5 , V_2 -> V_6 ) ;
}
if ( V_3 < V_2 -> V_6 ) {
F_5 ( V_3 , V_2 -> V_5 ) ;
V_2 -> V_7 = ( V_3 + 1 ) ;
if ( V_2 -> V_7 == V_2 -> V_6 )
V_2 -> V_7 = 0 ;
V_3 |= V_2 -> V_8 ;
} else
V_3 = - 1 ;
if ( V_3 != - 1 )
-- V_2 -> V_11 ;
F_6 ( & V_2 -> V_4 ) ;
return V_3 ;
}
void F_7 ( struct V_1 * V_2 , T_1 V_3 , int V_12 )
{
F_8 ( V_2 , V_3 , 1 , V_12 ) ;
}
static unsigned long F_9 ( unsigned long * V_2 ,
T_1 V_13 , T_1 V_14 ,
int V_15 , int V_16 , T_1 V_17 )
{
unsigned long V_18 , V_19 ;
V_20:
V_13 = F_10 ( V_13 , V_16 ) ;
while ( ( V_13 < V_14 ) && ( F_11 ( V_13 , V_2 ) ||
( V_13 & V_17 ) ) )
V_13 += V_16 ;
if ( V_13 >= V_14 )
return - 1 ;
V_18 = V_13 + V_15 ;
if ( V_18 > V_14 )
return - 1 ;
for ( V_19 = V_13 + 1 ; V_19 < V_18 ; V_19 ++ ) {
if ( F_11 ( V_19 , V_2 ) || ( ( T_1 ) V_19 & V_17 ) ) {
V_13 = V_19 + 1 ;
goto V_20;
}
}
return V_13 ;
}
T_1 F_12 ( struct V_1 * V_2 , int V_21 ,
int V_16 , T_1 V_17 )
{
T_1 V_3 ;
if ( F_13 ( V_21 == 1 && V_16 == 1 && ! V_17 ) )
return F_1 ( V_2 ) ;
F_2 ( & V_2 -> V_4 ) ;
V_3 = F_9 ( V_2 -> V_5 , V_2 -> V_7 ,
V_2 -> V_6 , V_21 , V_16 , V_17 ) ;
if ( V_3 >= V_2 -> V_6 ) {
V_2 -> V_8 = ( V_2 -> V_8 + V_2 -> V_6 + V_2 -> V_9 )
& V_2 -> V_10 ;
V_3 = F_9 ( V_2 -> V_5 , 0 , V_2 -> V_6 ,
V_21 , V_16 , V_17 ) ;
}
if ( V_3 < V_2 -> V_6 ) {
F_14 ( V_2 -> V_5 , V_3 , V_21 ) ;
if ( V_3 == V_2 -> V_7 ) {
V_2 -> V_7 = ( V_3 + V_21 ) ;
if ( V_2 -> V_7 >= V_2 -> V_6 )
V_2 -> V_7 = 0 ;
}
V_3 |= V_2 -> V_8 ;
} else
V_3 = - 1 ;
if ( V_3 != - 1 )
V_2 -> V_11 -= V_21 ;
F_6 ( & V_2 -> V_4 ) ;
return V_3 ;
}
T_1 F_15 ( struct V_1 * V_2 )
{
return V_2 -> V_11 ;
}
static T_1 F_16 ( struct V_1 * V_2 , T_1 V_3 )
{
return V_3 & ( V_2 -> V_6 + V_2 -> V_9 - 1 ) ;
}
void F_8 ( struct V_1 * V_2 , T_1 V_3 , int V_21 ,
int V_12 )
{
V_3 &= V_2 -> V_6 + V_2 -> V_9 - 1 ;
F_2 ( & V_2 -> V_4 ) ;
if ( ! V_12 ) {
V_2 -> V_7 = F_17 ( V_2 -> V_7 , V_3 ) ;
V_2 -> V_8 = ( V_2 -> V_8 + V_2 -> V_6 + V_2 -> V_9 )
& V_2 -> V_10 ;
}
F_18 ( V_2 -> V_5 , V_3 , V_21 ) ;
V_2 -> V_11 += V_21 ;
F_6 ( & V_2 -> V_4 ) ;
}
int F_19 ( struct V_1 * V_2 , T_1 V_22 , T_1 V_10 ,
T_1 V_23 , T_1 V_9 )
{
if ( V_22 != F_20 ( V_22 ) )
return - V_24 ;
V_2 -> V_7 = 0 ;
V_2 -> V_8 = 0 ;
V_2 -> V_6 = V_22 - V_9 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_11 = V_22 - V_9 - V_23 ;
V_2 -> V_25 = V_2 -> V_11 ;
F_21 ( & V_2 -> V_4 ) ;
V_2 -> V_5 = F_22 ( F_23 ( V_2 -> V_6 ) *
sizeof( long ) , V_26 ) ;
if ( ! V_2 -> V_5 )
return - V_27 ;
F_14 ( V_2 -> V_5 , 0 , V_23 ) ;
return 0 ;
}
void F_24 ( struct V_1 * V_2 )
{
F_25 ( V_2 -> V_5 ) ;
}
struct V_28 * F_26 ( enum V_29 V_30 )
{
struct V_28 * V_31 = F_27 ( sizeof( * V_31 ) , V_26 ) ;
if ( NULL == V_31 )
return NULL ;
F_28 ( & V_31 -> V_32 ) ;
F_28 ( & V_31 -> V_33 ) ;
F_21 ( & V_31 -> V_4 ) ;
V_31 -> V_34 = 0 ;
V_31 -> V_10 = 0 ;
V_31 -> V_30 = V_30 ;
return V_31 ;
}
int F_29 ( struct V_28 * V_35 ,
struct V_1 * V_2 ,
T_1 V_30 ,
int V_36 ,
int V_37 ,
T_1 * V_38 )
{
T_1 V_10 = F_16 ( V_2 , ( T_1 ) - 1 ) ;
struct V_39 * V_40 ;
struct V_39 * V_41 = F_27 ( sizeof( * V_41 ) , V_26 ) ;
if ( NULL == V_41 )
return - V_27 ;
V_41 -> V_30 = V_30 ;
V_41 -> V_2 = V_2 ;
V_41 -> V_12 = ( V_30 & V_42 ) ? V_43 : 0 ;
V_41 -> V_36 = V_36 ;
V_41 -> V_37 = V_37 ;
F_2 ( & V_35 -> V_4 ) ;
V_41 -> V_44 = V_35 -> V_34 ++ ;
V_41 -> V_45 = V_35 ;
if ( V_35 -> V_10 < V_10 )
V_35 -> V_10 = V_10 ;
F_30 (it, &zone_alloc->prios, prio_list)
if ( V_40 -> V_36 >= V_36 )
break;
if ( & V_40 -> V_46 == & V_35 -> V_33 || V_40 -> V_36 > V_36 )
F_31 ( & V_41 -> V_46 , & V_40 -> V_46 ) ;
F_31 ( & V_41 -> V_47 , & V_40 -> V_47 ) ;
F_6 ( & V_35 -> V_4 ) ;
* V_38 = V_41 -> V_44 ;
return 0 ;
}
static void F_32 ( struct V_39 * V_48 )
{
struct V_28 * V_35 = V_48 -> V_45 ;
if ( ! F_33 ( & V_48 -> V_46 ) ) {
if ( ! F_34 ( & V_48 -> V_47 , & V_35 -> V_32 ) ) {
struct V_39 * V_49 = F_35 ( & V_48 -> V_47 ,
F_36 ( * V_49 ) ,
V_47 ) ;
if ( V_49 -> V_36 == V_48 -> V_36 )
F_31 ( & V_49 -> V_46 , & V_48 -> V_46 ) ;
}
F_37 ( & V_48 -> V_46 ) ;
}
F_37 ( & V_48 -> V_47 ) ;
if ( V_35 -> V_30 & V_50 ) {
T_1 V_10 = 0 ;
struct V_39 * V_40 ;
F_30 (it, &zone_alloc->prios, prio_list) {
T_1 V_51 = F_16 ( V_40 -> V_2 , ( T_1 ) - 1 ) ;
if ( V_10 < V_51 )
V_10 = V_51 ;
}
V_35 -> V_10 = V_10 ;
}
}
void F_38 ( struct V_28 * V_35 )
{
struct V_39 * V_41 , * V_52 ;
F_2 ( & V_35 -> V_4 ) ;
F_39 (zone, tmp, &zone_alloc->entries, list) {
F_37 ( & V_41 -> V_47 ) ;
F_37 ( & V_41 -> V_46 ) ;
F_25 ( V_41 ) ;
}
F_6 ( & V_35 -> V_4 ) ;
F_25 ( V_35 ) ;
}
static T_1 F_40 ( struct V_39 * V_41 , int V_53 ,
int V_16 , T_1 V_17 , T_1 * V_38 )
{
T_1 V_44 ;
T_1 V_54 ;
struct V_28 * V_35 = V_41 -> V_45 ;
struct V_39 * V_55 ;
V_54 = F_12 ( V_41 -> V_2 , V_53 ,
V_16 , V_17 ) ;
if ( V_54 != ( T_1 ) - 1 ) {
V_54 += V_41 -> V_37 ;
V_44 = V_41 -> V_44 ;
goto V_56;
}
F_30 (curr_node, &zone_alloc->prios, prio_list) {
if ( F_41 ( V_55 -> V_36 == V_41 -> V_36 ) )
break;
}
if ( V_41 -> V_30 & V_57 ) {
struct V_39 * V_40 = V_55 ;
F_42 (it, &zone_alloc->entries, list) {
V_54 = F_12 ( V_40 -> V_2 , V_53 ,
V_16 , V_17 ) ;
if ( V_54 != ( T_1 ) - 1 ) {
V_54 += V_40 -> V_37 ;
V_44 = V_40 -> V_44 ;
goto V_56;
}
}
}
if ( V_41 -> V_30 & V_58 ) {
struct V_39 * V_40 = V_55 ;
F_43 (it, &zone_alloc->entries, list) {
if ( F_41 ( V_40 == V_41 ) )
continue;
if ( F_41 ( V_40 -> V_36 != V_55 -> V_36 ) )
break;
V_54 = F_12 ( V_40 -> V_2 , V_53 ,
V_16 , V_17 ) ;
if ( V_54 != ( T_1 ) - 1 ) {
V_54 += V_40 -> V_37 ;
V_44 = V_40 -> V_44 ;
goto V_56;
}
}
}
if ( V_41 -> V_30 & V_59 ) {
if ( F_34 ( & V_55 -> V_46 , & V_35 -> V_33 ) )
goto V_56;
V_55 = F_35 ( & V_55 -> V_46 ,
F_36 ( * V_55 ) ,
V_46 ) ;
F_43 (curr_node, &zone_alloc->entries, list) {
V_54 = F_12 ( V_55 -> V_2 , V_53 ,
V_16 , V_17 ) ;
if ( V_54 != ( T_1 ) - 1 ) {
V_54 += V_55 -> V_37 ;
V_44 = V_55 -> V_44 ;
goto V_56;
}
}
}
V_56:
if ( NULL != V_38 && V_54 != ( T_1 ) - 1 )
* V_38 = V_44 ;
return V_54 ;
}
static void F_44 ( struct V_39 * V_41 , T_1 V_3 ,
T_1 V_53 )
{
F_8 ( V_41 -> V_2 , V_3 - V_41 -> V_37 , V_53 , V_41 -> V_12 ) ;
}
static struct V_39 * F_45 (
struct V_28 * V_31 , T_1 V_44 )
{
struct V_39 * V_41 ;
F_30 (zone, &zones->entries, list) {
if ( V_41 -> V_44 == V_44 )
return V_41 ;
}
return NULL ;
}
struct V_1 * F_46 ( struct V_28 * V_31 , T_1 V_44 )
{
struct V_39 * V_41 ;
struct V_1 * V_2 ;
F_2 ( & V_31 -> V_4 ) ;
V_41 = F_45 ( V_31 , V_44 ) ;
V_2 = V_41 == NULL ? NULL : V_41 -> V_2 ;
F_6 ( & V_31 -> V_4 ) ;
return V_2 ;
}
int F_47 ( struct V_28 * V_31 , T_1 V_44 )
{
struct V_39 * V_41 ;
int V_54 = 0 ;
F_2 ( & V_31 -> V_4 ) ;
V_41 = F_45 ( V_31 , V_44 ) ;
if ( NULL == V_41 ) {
V_54 = - 1 ;
goto V_56;
}
F_32 ( V_41 ) ;
V_56:
F_6 ( & V_31 -> V_4 ) ;
F_25 ( V_41 ) ;
return V_54 ;
}
static struct V_39 * F_48 (
struct V_28 * V_31 , T_1 V_3 )
{
struct V_39 * V_41 , * V_60 = NULL ;
T_1 V_61 = ( T_1 ) - 1 ;
F_30 (zone, &zones->entries, list) {
if ( V_3 >= V_41 -> V_37 ) {
T_1 V_62 = ( V_3 - V_41 -> V_37 ) & V_31 -> V_10 ;
if ( V_62 < V_41 -> V_2 -> V_6 ) {
T_1 V_63 = V_41 -> V_2 -> V_25 ;
if ( V_63 < V_61 ) {
V_61 = V_63 ;
V_60 = V_41 ;
}
}
}
}
return V_60 ;
}
T_1 F_49 ( struct V_28 * V_31 , T_1 V_44 , int V_53 ,
int V_16 , T_1 V_17 , T_1 * V_38 )
{
struct V_39 * V_41 ;
int V_54 = - 1 ;
F_2 ( & V_31 -> V_4 ) ;
V_41 = F_45 ( V_31 , V_44 ) ;
if ( NULL == V_41 )
goto V_56;
V_54 = F_40 ( V_41 , V_53 , V_16 , V_17 , V_38 ) ;
V_56:
F_6 ( & V_31 -> V_4 ) ;
return V_54 ;
}
T_1 F_50 ( struct V_28 * V_31 , T_1 V_44 , T_1 V_3 , T_1 V_53 )
{
struct V_39 * V_41 ;
int V_54 = 0 ;
F_2 ( & V_31 -> V_4 ) ;
V_41 = F_45 ( V_31 , V_44 ) ;
if ( NULL == V_41 ) {
V_54 = - 1 ;
goto V_56;
}
F_44 ( V_41 , V_3 , V_53 ) ;
V_56:
F_6 ( & V_31 -> V_4 ) ;
return V_54 ;
}
T_1 F_51 ( struct V_28 * V_31 , T_1 V_3 , T_1 V_53 )
{
struct V_39 * V_41 ;
int V_54 ;
if ( ! ( V_31 -> V_30 & V_50 ) )
return - V_64 ;
F_2 ( & V_31 -> V_4 ) ;
V_41 = F_48 ( V_31 , V_3 ) ;
if ( NULL == V_41 ) {
V_54 = - 1 ;
goto V_56;
}
F_44 ( V_41 , V_3 , V_53 ) ;
V_54 = 0 ;
V_56:
F_6 ( & V_31 -> V_4 ) ;
return V_54 ;
}
static int F_52 ( struct V_65 * V_66 , int V_67 ,
struct V_68 * V_69 )
{
T_2 V_70 ;
V_69 -> V_71 = 1 ;
V_69 -> V_72 = 1 ;
V_69 -> V_73 = F_53 ( V_67 ) + V_74 ;
V_69 -> V_75 . V_69 =
F_54 ( & V_66 -> V_76 -> V_77 -> V_66 ,
V_67 , & V_70 , V_26 ) ;
if ( ! V_69 -> V_75 . V_69 )
return - V_27 ;
V_69 -> V_75 . V_78 = V_70 ;
while ( V_70 & ( ( 1 << V_69 -> V_73 ) - 1 ) ) {
-- V_69 -> V_73 ;
V_69 -> V_72 *= 2 ;
}
return 0 ;
}
int F_55 ( struct V_65 * V_66 , int V_67 , int V_79 ,
struct V_68 * V_69 )
{
if ( V_67 <= V_79 ) {
return F_52 ( V_66 , V_67 , V_69 ) ;
} else {
T_2 V_70 ;
int V_19 ;
V_69 -> V_75 . V_69 = NULL ;
V_69 -> V_71 = ( V_67 + V_80 - 1 ) / V_80 ;
V_69 -> V_72 = V_69 -> V_71 ;
V_69 -> V_73 = V_74 ;
V_69 -> V_81 = F_56 ( V_69 -> V_71 , sizeof( * V_69 -> V_81 ) ,
V_26 ) ;
if ( ! V_69 -> V_81 )
return - V_27 ;
for ( V_19 = 0 ; V_19 < V_69 -> V_71 ; ++ V_19 ) {
V_69 -> V_81 [ V_19 ] . V_69 =
F_54 ( & V_66 -> V_76 -> V_77 -> V_66 ,
V_80 , & V_70 , V_26 ) ;
if ( ! V_69 -> V_81 [ V_19 ] . V_69 )
goto V_82;
V_69 -> V_81 [ V_19 ] . V_78 = V_70 ;
}
}
return 0 ;
V_82:
F_57 ( V_66 , V_67 , V_69 ) ;
return - V_27 ;
}
void F_57 ( struct V_65 * V_66 , int V_67 , struct V_68 * V_69 )
{
if ( V_69 -> V_71 == 1 ) {
F_58 ( & V_66 -> V_76 -> V_77 -> V_66 , V_67 ,
V_69 -> V_75 . V_69 , V_69 -> V_75 . V_78 ) ;
} else {
int V_19 ;
for ( V_19 = 0 ; V_19 < V_69 -> V_71 ; ++ V_19 )
if ( V_69 -> V_81 [ V_19 ] . V_69 )
F_58 ( & V_66 -> V_76 -> V_77 -> V_66 ,
V_80 ,
V_69 -> V_81 [ V_19 ] . V_69 ,
V_69 -> V_81 [ V_19 ] . V_78 ) ;
F_25 ( V_69 -> V_81 ) ;
}
}
static struct V_83 * F_59 ( struct V_84 * V_85 )
{
struct V_83 * V_86 ;
V_86 = F_22 ( sizeof( * V_86 ) , V_26 ) ;
if ( ! V_86 )
return NULL ;
F_60 ( V_86 -> V_87 , V_88 / 2 ) ;
V_86 -> V_89 [ 0 ] = V_86 -> V_90 ;
V_86 -> V_89 [ 1 ] = V_86 -> V_87 ;
V_86 -> V_91 = F_61 ( V_85 , V_80 ,
& V_86 -> V_92 , V_26 ) ;
if ( ! V_86 -> V_91 ) {
F_25 ( V_86 ) ;
return NULL ;
}
return V_86 ;
}
static int F_62 ( struct V_83 * V_86 ,
struct V_93 * V_94 , int V_95 )
{
int V_96 ;
int V_19 ;
for ( V_96 = V_95 ; V_96 <= 1 ; ++ V_96 ) {
V_19 = F_63 ( V_86 -> V_89 [ V_96 ] , V_88 >> V_96 ) ;
if ( V_19 < V_88 > > V_96 )
goto V_97;
}
return - V_27 ;
V_97:
F_64 ( V_19 , V_86 -> V_89 [ V_96 ] ) ;
V_19 <<= V_96 ;
if ( V_96 > V_95 )
F_5 ( V_19 ^ 1 , V_86 -> V_89 [ V_95 ] ) ;
V_94 -> V_98 . V_86 = V_86 ;
V_94 -> V_99 = V_19 ;
V_94 -> V_94 = V_86 -> V_91 + V_94 -> V_99 ;
V_94 -> V_100 = V_86 -> V_92 + V_94 -> V_99 * 4 ;
V_94 -> V_95 = V_95 ;
return 0 ;
}
int F_65 ( struct V_65 * V_66 , struct V_93 * V_94 , int V_95 )
{
struct V_101 * V_102 = V_101 ( V_66 ) ;
struct V_83 * V_86 ;
int V_103 = 0 ;
F_66 ( & V_102 -> V_104 ) ;
F_30 (pgdir, &priv->pgdir_list, list)
if ( ! F_62 ( V_86 , V_94 , V_95 ) )
goto V_56;
V_86 = F_59 ( & V_66 -> V_76 -> V_77 -> V_66 ) ;
if ( ! V_86 ) {
V_103 = - V_27 ;
goto V_56;
}
F_67 ( & V_86 -> V_47 , & V_102 -> V_105 ) ;
F_68 ( F_62 ( V_86 , V_94 , V_95 ) ) ;
V_56:
F_69 ( & V_102 -> V_104 ) ;
return V_103 ;
}
void F_70 ( struct V_65 * V_66 , struct V_93 * V_94 )
{
struct V_101 * V_102 = V_101 ( V_66 ) ;
int V_96 ;
int V_19 ;
F_66 ( & V_102 -> V_104 ) ;
V_96 = V_94 -> V_95 ;
V_19 = V_94 -> V_99 ;
if ( V_94 -> V_95 == 0 && F_11 ( V_19 ^ 1 , V_94 -> V_98 . V_86 -> V_90 ) ) {
F_64 ( V_19 ^ 1 , V_94 -> V_98 . V_86 -> V_90 ) ;
++ V_96 ;
}
V_19 >>= V_96 ;
F_5 ( V_19 , V_94 -> V_98 . V_86 -> V_89 [ V_96 ] ) ;
if ( F_71 ( V_94 -> V_98 . V_86 -> V_87 , V_88 / 2 ) ) {
F_58 ( & V_66 -> V_76 -> V_77 -> V_66 , V_80 ,
V_94 -> V_98 . V_86 -> V_91 , V_94 -> V_98 . V_86 -> V_92 ) ;
F_37 ( & V_94 -> V_98 . V_86 -> V_47 ) ;
F_25 ( V_94 -> V_98 . V_86 ) ;
}
F_69 ( & V_102 -> V_104 ) ;
}
int F_72 ( struct V_65 * V_66 , struct V_106 * V_107 ,
int V_67 )
{
int V_108 ;
V_108 = F_65 ( V_66 , & V_107 -> V_94 , 1 ) ;
if ( V_108 )
return V_108 ;
* V_107 -> V_94 . V_94 = 0 ;
V_108 = F_52 ( V_66 , V_67 , & V_107 -> V_69 ) ;
if ( V_108 )
goto V_109;
V_108 = F_73 ( V_66 , V_107 -> V_69 . V_72 , V_107 -> V_69 . V_73 ,
& V_107 -> V_110 ) ;
if ( V_108 )
goto V_111;
V_108 = F_74 ( V_66 , & V_107 -> V_110 , & V_107 -> V_69 ) ;
if ( V_108 )
goto V_112;
return 0 ;
V_112:
F_75 ( V_66 , & V_107 -> V_110 ) ;
V_111:
F_57 ( V_66 , V_67 , & V_107 -> V_69 ) ;
V_109:
F_70 ( V_66 , & V_107 -> V_94 ) ;
return V_108 ;
}
void F_76 ( struct V_65 * V_66 , struct V_106 * V_107 ,
int V_67 )
{
F_75 ( V_66 , & V_107 -> V_110 ) ;
F_57 ( V_66 , V_67 , & V_107 -> V_69 ) ;
F_70 ( V_66 , & V_107 -> V_94 ) ;
}
