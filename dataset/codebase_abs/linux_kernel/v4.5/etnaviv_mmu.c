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
int F_15 ( struct V_8 * V_26 ,
struct V_29 * V_30 , T_1 V_36 ,
struct V_27 * V_28 )
{
struct V_27 * free = NULL ;
struct V_9 * V_10 = V_30 -> V_10 ;
struct V_37 * V_38 ;
int V_19 ;
F_16 ( & V_30 -> V_39 ) ;
F_17 ( & V_26 -> V_39 ) ;
if ( V_10 -> V_40 == 1 && ! ( V_30 -> V_6 & V_41 ) ) {
T_1 V_5 ;
V_5 = F_5 ( V_10 -> V_42 ) - V_36 ;
if ( V_5 < 0x80000000 - F_6 ( V_10 -> V_42 ) ) {
V_28 -> V_5 = V_5 ;
F_18 ( & V_28 -> V_43 , & V_26 -> V_44 ) ;
F_19 ( & V_26 -> V_39 ) ;
return 0 ;
}
}
V_38 = & V_28 -> V_32 ;
while ( 1 ) {
struct V_27 * V_45 , * V_46 ;
struct V_47 V_48 ;
bool V_49 ;
V_19 = F_20 ( & V_26 -> V_50 , V_38 ,
V_30 -> V_34 . V_35 , 0 , V_26 -> V_51 , ~ 0UL ,
V_52 ) ;
if ( V_19 != - V_53 )
break;
if ( V_26 -> V_51 ) {
V_26 -> V_51 = 0 ;
V_26 -> V_54 = true ;
continue;
}
F_21 ( & V_26 -> V_50 , V_30 -> V_34 . V_35 , 0 , 0 ) ;
V_49 = 0 ;
F_22 ( & V_48 ) ;
F_23 (free, &mmu->mappings, mmu_node) {
if ( ! free -> V_32 . V_50 )
continue;
if ( free -> V_55 )
continue;
F_24 ( & free -> V_56 , & V_48 ) ;
if ( F_25 ( & free -> V_32 ) ) {
V_49 = true ;
break;
}
}
if ( ! V_49 ) {
F_26 (m, n, &list, scan_node)
F_11 ( F_27 ( & V_45 -> V_32 ) ) ;
break;
}
F_26 (m, n, &list, scan_node)
if ( ! F_27 ( & V_45 -> V_32 ) )
F_28 ( & V_45 -> V_56 ) ;
F_26 (m, n, &list, scan_node) {
F_13 ( V_26 , V_45 ) ;
V_45 -> V_26 = NULL ;
F_28 ( & V_45 -> V_43 ) ;
F_28 ( & V_45 -> V_56 ) ;
}
V_26 -> V_54 = true ;
}
if ( V_19 < 0 ) {
F_19 ( & V_26 -> V_39 ) ;
return V_19 ;
}
V_26 -> V_51 = V_38 -> V_33 + V_30 -> V_34 . V_35 ;
V_28 -> V_5 = V_38 -> V_33 ;
V_19 = F_3 ( V_26 , V_38 -> V_33 , V_10 , V_30 -> V_34 . V_35 ,
V_57 | V_58 ) ;
if ( V_19 < 0 ) {
F_14 ( V_38 ) ;
F_19 ( & V_26 -> V_39 ) ;
return V_19 ;
}
F_18 ( & V_28 -> V_43 , & V_26 -> V_44 ) ;
F_19 ( & V_26 -> V_39 ) ;
return V_19 ;
}
void F_29 ( struct V_8 * V_26 ,
struct V_27 * V_28 )
{
F_30 ( V_28 -> V_55 ) ;
F_17 ( & V_26 -> V_39 ) ;
if ( V_28 -> V_32 . V_50 == & V_26 -> V_50 )
F_13 ( V_26 , V_28 ) ;
F_31 ( & V_28 -> V_43 ) ;
F_19 ( & V_26 -> V_39 ) ;
}
void F_32 ( struct V_8 * V_26 )
{
F_33 ( & V_26 -> V_50 ) ;
F_34 ( V_26 -> V_13 ) ;
F_35 ( V_26 ) ;
}
struct V_8 * F_36 ( struct V_59 * V_60 ,
struct V_1 * V_13 , enum V_61 V_62 )
{
struct V_8 * V_26 ;
V_26 = F_37 ( sizeof( * V_26 ) , V_63 ) ;
if ( ! V_26 )
return F_38 ( - V_64 ) ;
V_26 -> V_13 = V_13 ;
V_26 -> V_60 = V_60 ;
V_26 -> V_62 = V_62 ;
F_39 ( & V_26 -> V_39 ) ;
F_22 ( & V_26 -> V_44 ) ;
F_40 ( & V_26 -> V_50 , V_13 -> V_65 . V_66 ,
V_13 -> V_65 . V_67 -
V_13 -> V_65 . V_66 + 1 ) ;
F_41 ( V_13 , F_1 , V_60 -> V_4 ) ;
return V_26 ;
}
T_2 F_42 ( struct V_8 * V_2 )
{
struct V_68 * V_69 ;
V_69 = F_43 ( V_2 -> V_13 -> V_69 , struct V_68 , V_69 ) ;
return V_69 -> V_70 ( V_2 -> V_13 ) ;
}
void F_44 ( struct V_8 * V_2 , void * V_71 )
{
struct V_68 * V_69 ;
V_69 = F_43 ( V_2 -> V_13 -> V_69 , struct V_68 , V_69 ) ;
V_69 -> V_72 ( V_2 -> V_13 , V_71 ) ;
}
