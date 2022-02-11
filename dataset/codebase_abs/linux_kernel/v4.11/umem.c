static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_8 ;
int V_9 ;
if ( V_4 -> V_10 > 0 )
F_2 ( V_2 , V_4 -> V_11 . V_12 ,
V_4 -> V_13 ,
V_14 ) ;
F_3 (umem->sg_head.sgl, sg, umem->npages, i) {
V_8 = F_4 ( V_7 ) ;
if ( V_4 -> V_15 && V_5 )
F_5 ( V_8 ) ;
F_6 ( V_8 ) ;
}
F_7 ( & V_4 -> V_11 ) ;
return;
}
struct V_3 * F_8 ( struct V_16 * V_17 , unsigned long V_18 ,
T_1 V_19 , int V_20 , int V_21 )
{
struct V_3 * V_4 ;
struct V_8 * * V_22 ;
struct V_23 * * V_24 ;
unsigned long V_25 ;
unsigned long V_26 ;
unsigned long V_27 ;
unsigned long V_13 ;
int V_28 ;
int V_9 ;
unsigned long V_29 = 0 ;
struct V_6 * V_7 , * V_30 ;
int V_31 = 0 ;
unsigned int V_32 = V_33 ;
if ( V_21 )
V_29 |= V_34 ;
if ( ( ( V_18 + V_19 ) < V_18 ) ||
F_9 ( V_18 + V_19 ) < ( V_18 + V_19 ) )
return F_10 ( - V_35 ) ;
if ( ! F_11 () )
return F_10 ( - V_36 ) ;
V_4 = F_12 ( sizeof *V_4 , V_37 ) ;
if ( ! V_4 )
return F_10 ( - V_38 ) ;
V_4 -> V_17 = V_17 ;
V_4 -> V_39 = V_19 ;
V_4 -> V_40 = V_18 ;
V_4 -> V_41 = V_42 ;
V_4 -> V_43 = F_13 ( V_44 , V_45 ) ;
V_4 -> V_15 = ! ! ( V_20 &
( V_46 | V_47 |
V_48 | V_49 ) ) ;
if ( V_20 & V_50 ) {
F_14 ( V_4 -> V_43 ) ;
V_28 = F_15 ( V_17 , V_4 ) ;
if ( V_28 ) {
F_16 ( V_4 ) ;
return F_10 ( V_28 ) ;
}
return V_4 ;
}
V_4 -> V_51 = NULL ;
V_4 -> V_52 = 1 ;
V_22 = (struct V_8 * * ) F_17 ( V_37 ) ;
if ( ! V_22 ) {
F_14 ( V_4 -> V_43 ) ;
F_16 ( V_4 ) ;
return F_10 ( - V_38 ) ;
}
V_24 = (struct V_23 * * ) F_17 ( V_37 ) ;
if ( ! V_24 )
V_4 -> V_52 = 0 ;
V_13 = F_18 ( V_4 ) ;
F_19 ( & V_44 -> V_53 -> V_54 ) ;
V_25 = V_13 + V_44 -> V_53 -> V_55 ;
V_26 = F_20 ( V_56 ) >> V_57 ;
if ( ( V_25 > V_26 ) && ! F_21 ( V_58 ) ) {
V_28 = - V_38 ;
goto V_59;
}
V_27 = V_18 & V_60 ;
if ( V_13 == 0 || V_13 > V_61 ) {
V_28 = - V_35 ;
goto V_59;
}
V_28 = F_22 ( & V_4 -> V_11 , V_13 , V_37 ) ;
if ( V_28 )
goto V_59;
if ( ! V_4 -> V_15 )
V_32 |= V_62 ;
V_31 = 1 ;
V_30 = V_4 -> V_11 . V_12 ;
while ( V_13 ) {
V_28 = F_23 ( V_27 ,
F_24 (unsigned long, npages,
PAGE_SIZE / sizeof (struct page *)) ,
V_32 , V_22 , V_24 ) ;
if ( V_28 < 0 )
goto V_59;
V_4 -> V_13 += V_28 ;
V_27 += V_28 * V_42 ;
V_13 -= V_28 ;
F_3 (sg_list_start, sg, ret, i) {
if ( V_24 && ! F_25 ( V_24 [ V_9 ] ) )
V_4 -> V_52 = 0 ;
F_26 ( V_7 , V_22 [ V_9 ] , V_42 , 0 ) ;
}
V_30 = V_7 ;
}
V_4 -> V_10 = F_27 ( V_17 -> V_63 ,
V_4 -> V_11 . V_12 ,
V_4 -> V_13 ,
V_14 ,
V_29 ) ;
if ( V_4 -> V_10 <= 0 ) {
V_28 = - V_38 ;
goto V_59;
}
V_28 = 0 ;
V_59:
if ( V_28 < 0 ) {
if ( V_31 )
F_1 ( V_17 -> V_63 , V_4 , 0 ) ;
F_14 ( V_4 -> V_43 ) ;
F_16 ( V_4 ) ;
} else
V_44 -> V_53 -> V_55 = V_25 ;
F_28 ( & V_44 -> V_53 -> V_54 ) ;
if ( V_24 )
F_29 ( ( unsigned long ) V_24 ) ;
F_29 ( ( unsigned long ) V_22 ) ;
return V_28 < 0 ? F_10 ( V_28 ) : V_4 ;
}
static void F_30 ( struct V_64 * V_65 )
{
struct V_3 * V_4 = F_31 ( V_65 , struct V_3 , V_65 ) ;
F_19 ( & V_4 -> V_53 -> V_54 ) ;
V_4 -> V_53 -> V_55 -= V_4 -> V_66 ;
F_28 ( & V_4 -> V_53 -> V_54 ) ;
F_32 ( V_4 -> V_53 ) ;
F_16 ( V_4 ) ;
}
void F_33 ( struct V_3 * V_4 )
{
struct V_16 * V_17 = V_4 -> V_17 ;
struct V_67 * V_53 ;
struct V_68 * V_69 ;
unsigned long V_66 ;
if ( V_4 -> V_51 ) {
F_34 ( V_4 ) ;
return;
}
F_1 ( V_4 -> V_17 -> V_63 , V_4 , 1 ) ;
V_69 = F_35 ( V_4 -> V_43 , V_45 ) ;
F_14 ( V_4 -> V_43 ) ;
if ( ! V_69 )
goto V_59;
V_53 = F_36 ( V_69 ) ;
F_37 ( V_69 ) ;
if ( ! V_53 )
goto V_59;
V_66 = F_18 ( V_4 ) ;
if ( V_17 -> V_70 ) {
if ( ! F_38 ( & V_53 -> V_54 ) ) {
F_39 ( & V_4 -> V_65 , F_30 ) ;
V_4 -> V_53 = V_53 ;
V_4 -> V_66 = V_66 ;
F_40 ( V_71 , & V_4 -> V_65 ) ;
return;
}
} else
F_19 ( & V_53 -> V_54 ) ;
V_53 -> V_55 -= V_66 ;
F_28 ( & V_53 -> V_54 ) ;
F_32 ( V_53 ) ;
V_59:
F_16 ( V_4 ) ;
}
int F_41 ( struct V_3 * V_4 )
{
int V_72 ;
int V_9 ;
int V_73 ;
struct V_6 * V_7 ;
if ( V_4 -> V_51 )
return F_18 ( V_4 ) ;
V_72 = F_42 ( V_4 -> V_41 ) ;
V_73 = 0 ;
F_3 (umem->sg_head.sgl, sg, umem->nmap, i)
V_73 += F_43 ( V_7 ) >> V_72 ;
return V_73 ;
}
int F_44 ( void * V_74 , struct V_3 * V_4 , T_1 V_75 ,
T_1 V_39 )
{
T_1 V_76 = V_75 + V_39 ;
int V_28 ;
if ( V_75 > V_4 -> V_39 || V_39 > V_4 -> V_39 - V_75 ) {
F_45 ( L_1 ,
V_75 , V_4 -> V_39 , V_76 ) ;
return - V_35 ;
}
V_28 = F_46 ( V_4 -> V_11 . V_12 , V_4 -> V_10 , V_74 , V_39 ,
V_75 + F_47 ( V_4 ) ) ;
if ( V_28 < 0 )
return V_28 ;
else if ( V_28 != V_39 )
return - V_35 ;
else
return 0 ;
}
