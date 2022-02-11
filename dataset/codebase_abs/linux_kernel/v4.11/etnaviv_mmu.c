static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned long V_5 , int V_6 , void * V_7 )
{
F_2 ( L_1 , V_5 , V_6 ) ;
return 0 ;
}
int F_3 ( struct V_8 * V_2 , T_1 V_5 ,
struct V_9 * V_10 , unsigned V_11 , int V_12 )
{
struct V_1 * V_13 = V_2 -> V_13 ;
struct V_14 * V_15 ;
unsigned int V_16 = V_5 ;
unsigned int V_17 , V_18 ;
int V_19 ;
if ( ! V_13 || ! V_10 )
return - V_20 ;
F_4 (sgt->sgl, sg, sgt->nents, i) {
T_1 V_21 = F_5 ( V_15 ) - V_15 -> V_22 ;
T_2 V_23 = F_6 ( V_15 ) + V_15 -> V_22 ;
F_7 ( L_2 , V_17 , V_5 , V_21 , V_23 ) ;
V_19 = F_8 ( V_13 , V_16 , V_21 , V_23 , V_12 ) ;
if ( V_19 )
goto V_24;
V_16 += V_23 ;
}
return 0 ;
V_24:
V_16 = V_5 ;
F_4 (sgt->sgl, sg, i, j) {
T_2 V_23 = F_6 ( V_15 ) + V_15 -> V_22 ;
F_9 ( V_13 , V_16 , V_23 ) ;
V_16 += V_23 ;
}
return V_19 ;
}
int F_10 ( struct V_8 * V_2 , T_1 V_5 ,
struct V_9 * V_10 , unsigned V_11 )
{
struct V_1 * V_13 = V_2 -> V_13 ;
struct V_14 * V_15 ;
unsigned int V_16 = V_5 ;
int V_17 ;
F_4 (sgt->sgl, sg, sgt->nents, i) {
T_2 V_23 = F_6 ( V_15 ) + V_15 -> V_22 ;
T_2 V_25 ;
V_25 = F_9 ( V_13 , V_16 , V_23 ) ;
if ( V_25 < V_23 )
return V_25 ;
F_7 ( L_3 , V_17 , V_5 , V_23 ) ;
F_11 ( ! F_12 ( V_23 ) ) ;
V_16 += V_23 ;
}
return 0 ;
}
static void F_13 ( struct V_8 * V_26 ,
struct V_27 * V_28 )
{
struct V_29 * V_30 = V_28 -> V_31 ;
F_10 ( V_26 , V_28 -> V_32 . V_33 ,
V_30 -> V_10 , V_30 -> V_34 . V_35 ) ;
F_14 ( & V_28 -> V_32 ) ;
}
static int F_15 ( struct V_8 * V_26 ,
struct V_36 * V_37 , T_2 V_35 )
{
struct V_27 * free = NULL ;
enum V_38 V_39 = V_40 ;
int V_19 ;
F_16 ( & V_26 -> V_41 ) ;
while ( 1 ) {
struct V_27 * V_42 , * V_43 ;
struct V_44 V_45 ;
struct V_46 V_47 ;
bool V_48 ;
V_19 = F_17 ( & V_26 -> V_49 , V_37 ,
V_35 , 0 , 0 ,
V_26 -> V_50 , V_51 ,
V_39 ) ;
if ( V_19 != - V_52 )
break;
if ( V_26 -> V_50 ) {
V_26 -> V_50 = 0 ;
V_26 -> V_53 = true ;
continue;
}
F_18 ( & V_45 , & V_26 -> V_49 , V_35 , 0 , 0 , V_39 ) ;
V_48 = 0 ;
F_19 ( & V_47 ) ;
F_20 (free, &mmu->mappings, mmu_node) {
if ( ! free -> V_32 . V_49 )
continue;
if ( free -> V_54 )
continue;
F_21 ( & free -> V_55 , & V_47 ) ;
if ( F_22 ( & V_45 , & free -> V_32 ) ) {
V_48 = true ;
break;
}
}
if ( ! V_48 ) {
F_23 (m, n, &list, scan_node)
F_11 ( F_24 ( & V_45 , & V_42 -> V_32 ) ) ;
break;
}
F_23 (m, n, &list, scan_node)
if ( ! F_24 ( & V_45 , & V_42 -> V_32 ) )
F_25 ( & V_42 -> V_55 ) ;
F_23 (m, n, &list, scan_node) {
F_13 ( V_26 , V_42 ) ;
V_42 -> V_26 = NULL ;
F_25 ( & V_42 -> V_56 ) ;
F_25 ( & V_42 -> V_55 ) ;
}
V_39 = V_57 ;
}
return V_19 ;
}
int F_26 ( struct V_8 * V_26 ,
struct V_29 * V_30 , T_1 V_58 ,
struct V_27 * V_28 )
{
struct V_9 * V_10 = V_30 -> V_10 ;
struct V_36 * V_37 ;
int V_19 ;
F_16 ( & V_30 -> V_41 ) ;
F_27 ( & V_26 -> V_41 ) ;
if ( V_26 -> V_59 == V_60 &&
V_10 -> V_61 == 1 && ! ( V_30 -> V_6 & V_62 ) ) {
T_1 V_5 ;
V_5 = F_5 ( V_10 -> V_63 ) - V_58 ;
if ( V_5 < 0x80000000 - F_6 ( V_10 -> V_63 ) ) {
V_28 -> V_5 = V_5 ;
F_28 ( & V_28 -> V_56 , & V_26 -> V_64 ) ;
F_29 ( & V_26 -> V_41 ) ;
return 0 ;
}
}
V_37 = & V_28 -> V_32 ;
V_19 = F_15 ( V_26 , V_37 , V_30 -> V_34 . V_35 ) ;
if ( V_19 < 0 ) {
F_29 ( & V_26 -> V_41 ) ;
return V_19 ;
}
V_26 -> V_50 = V_37 -> V_33 + V_30 -> V_34 . V_35 ;
V_28 -> V_5 = V_37 -> V_33 ;
V_19 = F_3 ( V_26 , V_37 -> V_33 , V_10 , V_30 -> V_34 . V_35 ,
V_65 | V_66 ) ;
if ( V_19 < 0 ) {
F_14 ( V_37 ) ;
F_29 ( & V_26 -> V_41 ) ;
return V_19 ;
}
F_28 ( & V_28 -> V_56 , & V_26 -> V_64 ) ;
V_26 -> V_53 = true ;
F_29 ( & V_26 -> V_41 ) ;
return V_19 ;
}
void F_30 ( struct V_8 * V_26 ,
struct V_27 * V_28 )
{
F_31 ( V_28 -> V_54 ) ;
F_27 ( & V_26 -> V_41 ) ;
if ( V_28 -> V_32 . V_49 == & V_26 -> V_49 )
F_13 ( V_26 , V_28 ) ;
F_32 ( & V_28 -> V_56 ) ;
V_26 -> V_53 = true ;
F_29 ( & V_26 -> V_41 ) ;
}
void F_33 ( struct V_8 * V_26 )
{
F_34 ( & V_26 -> V_49 ) ;
F_35 ( V_26 -> V_13 ) ;
F_36 ( V_26 ) ;
}
struct V_8 * F_37 ( struct V_67 * V_68 )
{
enum V_69 V_59 ;
struct V_8 * V_26 ;
V_26 = F_38 ( sizeof( * V_26 ) , V_70 ) ;
if ( ! V_26 )
return F_39 ( - V_71 ) ;
if ( ! ( V_68 -> V_72 . V_73 & V_74 ) ) {
V_26 -> V_13 = F_40 ( V_68 ) ;
V_59 = V_60 ;
} else {
V_26 -> V_13 = F_41 ( V_68 ) ;
V_59 = V_75 ;
}
if ( ! V_26 -> V_13 ) {
F_42 ( V_68 -> V_4 , L_4 ) ;
F_36 ( V_26 ) ;
return F_39 ( - V_71 ) ;
}
V_26 -> V_68 = V_68 ;
V_26 -> V_59 = V_59 ;
F_43 ( & V_26 -> V_41 ) ;
F_19 ( & V_26 -> V_64 ) ;
F_44 ( & V_26 -> V_49 , V_26 -> V_13 -> V_76 . V_77 ,
V_26 -> V_13 -> V_76 . V_78 -
V_26 -> V_13 -> V_76 . V_77 + 1 ) ;
F_45 ( V_26 -> V_13 , F_1 , V_68 -> V_4 ) ;
return V_26 ;
}
void F_46 ( struct V_67 * V_68 )
{
if ( V_68 -> V_26 -> V_59 == V_60 )
F_47 ( V_68 ) ;
else
F_48 ( V_68 ) ;
}
int F_49 ( struct V_67 * V_68 , T_3 V_79 ,
struct V_36 * V_32 , T_2 V_35 ,
T_1 * V_5 )
{
struct V_8 * V_26 = V_68 -> V_26 ;
if ( V_26 -> V_59 == V_60 ) {
* V_5 = V_79 - V_68 -> V_58 ;
return 0 ;
} else {
int V_19 ;
F_27 ( & V_26 -> V_41 ) ;
V_19 = F_15 ( V_26 , V_32 , V_35 ) ;
if ( V_19 < 0 ) {
F_29 ( & V_26 -> V_41 ) ;
return V_19 ;
}
V_19 = F_8 ( V_26 -> V_13 , V_32 -> V_33 , V_79 , V_35 ,
V_65 ) ;
if ( V_19 < 0 ) {
F_14 ( V_32 ) ;
F_29 ( & V_26 -> V_41 ) ;
return V_19 ;
}
V_26 -> V_50 = V_32 -> V_33 + V_35 ;
V_68 -> V_26 -> V_53 = true ;
F_29 ( & V_26 -> V_41 ) ;
* V_5 = ( T_1 ) V_32 -> V_33 ;
return 0 ;
}
}
void F_50 ( struct V_67 * V_68 ,
struct V_36 * V_32 , T_2 V_35 ,
T_1 V_5 )
{
struct V_8 * V_26 = V_68 -> V_26 ;
if ( V_26 -> V_59 == V_75 ) {
F_27 ( & V_26 -> V_41 ) ;
F_9 ( V_26 -> V_13 , V_5 , V_35 ) ;
F_14 ( V_32 ) ;
F_29 ( & V_26 -> V_41 ) ;
}
}
T_2 F_51 ( struct V_8 * V_2 )
{
struct V_80 * V_81 ;
V_81 = F_52 ( V_2 -> V_13 -> V_81 , struct V_80 , V_81 ) ;
return V_81 -> V_82 ( V_2 -> V_13 ) ;
}
void F_53 ( struct V_8 * V_2 , void * V_83 )
{
struct V_80 * V_81 ;
V_81 = F_52 ( V_2 -> V_13 -> V_81 , struct V_80 , V_81 ) ;
V_81 -> V_84 ( V_2 -> V_13 , V_83 ) ;
}
