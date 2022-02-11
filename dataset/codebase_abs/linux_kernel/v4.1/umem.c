static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_8 ;
int V_9 ;
if ( V_4 -> V_10 > 0 )
F_2 ( V_2 , V_4 -> V_11 . V_12 ,
V_4 -> V_10 ,
V_13 ) ;
F_3 (umem->sg_head.sgl, sg, umem->npages, i) {
V_8 = F_4 ( V_7 ) ;
if ( V_4 -> V_14 && V_5 )
F_5 ( V_8 ) ;
F_6 ( V_8 ) ;
}
F_7 ( & V_4 -> V_11 ) ;
return;
}
struct V_3 * F_8 ( struct V_15 * V_16 , unsigned long V_17 ,
T_1 V_18 , int V_19 , int V_20 )
{
struct V_3 * V_4 ;
struct V_8 * * V_21 ;
struct V_22 * * V_23 ;
unsigned long V_24 ;
unsigned long V_25 ;
unsigned long V_26 ;
unsigned long V_27 ;
int V_28 ;
int V_9 ;
F_9 ( V_29 ) ;
struct V_6 * V_7 , * V_30 ;
int V_31 = 0 ;
if ( V_20 )
F_10 ( V_32 , & V_29 ) ;
if ( ! V_18 )
return F_11 ( - V_33 ) ;
if ( ( ( V_17 + V_18 ) < V_17 ) ||
F_12 ( V_17 + V_18 ) < ( V_17 + V_18 ) )
return F_11 ( - V_33 ) ;
if ( ! F_13 () )
return F_11 ( - V_34 ) ;
V_4 = F_14 ( sizeof *V_4 , V_35 ) ;
if ( ! V_4 )
return F_11 ( - V_36 ) ;
V_4 -> V_16 = V_16 ;
V_4 -> V_37 = V_18 ;
V_4 -> V_38 = V_17 ;
V_4 -> V_39 = V_40 ;
V_4 -> V_41 = F_15 ( V_42 , V_43 ) ;
V_4 -> V_14 = ! ! ( V_19 &
( V_44 | V_45 |
V_46 | V_47 ) ) ;
if ( V_19 & V_48 ) {
V_28 = F_16 ( V_16 , V_4 ) ;
if ( V_28 ) {
F_17 ( V_4 ) ;
return F_11 ( V_28 ) ;
}
return V_4 ;
}
V_4 -> V_49 = NULL ;
V_4 -> V_50 = 1 ;
V_21 = (struct V_8 * * ) F_18 ( V_35 ) ;
if ( ! V_21 ) {
F_17 ( V_4 ) ;
return F_11 ( - V_36 ) ;
}
V_23 = (struct V_22 * * ) F_18 ( V_35 ) ;
if ( ! V_23 )
V_4 -> V_50 = 0 ;
V_27 = F_19 ( V_4 ) ;
F_20 ( & V_42 -> V_51 -> V_52 ) ;
V_24 = V_27 + V_42 -> V_51 -> V_53 ;
V_25 = F_21 ( V_54 ) >> V_55 ;
if ( ( V_24 > V_25 ) && ! F_22 ( V_56 ) ) {
V_28 = - V_36 ;
goto V_57;
}
V_26 = V_17 & V_58 ;
if ( V_27 == 0 ) {
V_28 = - V_33 ;
goto V_57;
}
V_28 = F_23 ( & V_4 -> V_11 , V_27 , V_35 ) ;
if ( V_28 )
goto V_57;
V_31 = 1 ;
V_30 = V_4 -> V_11 . V_12 ;
while ( V_27 ) {
V_28 = F_24 ( V_42 , V_42 -> V_51 , V_26 ,
F_25 (unsigned long, npages,
PAGE_SIZE / sizeof (struct page *)) ,
1 , ! V_4 -> V_14 , V_21 , V_23 ) ;
if ( V_28 < 0 )
goto V_57;
V_4 -> V_27 += V_28 ;
V_26 += V_28 * V_40 ;
V_27 -= V_28 ;
F_3 (sg_list_start, sg, ret, i) {
if ( V_23 && ! F_26 ( V_23 [ V_9 ] ) )
V_4 -> V_50 = 0 ;
F_27 ( V_7 , V_21 [ V_9 ] , V_40 , 0 ) ;
}
V_30 = V_7 ;
}
V_4 -> V_10 = F_28 ( V_16 -> V_59 ,
V_4 -> V_11 . V_12 ,
V_4 -> V_27 ,
V_13 ,
& V_29 ) ;
if ( V_4 -> V_10 <= 0 ) {
V_28 = - V_36 ;
goto V_57;
}
V_28 = 0 ;
V_57:
if ( V_28 < 0 ) {
if ( V_31 )
F_1 ( V_16 -> V_59 , V_4 , 0 ) ;
F_29 ( V_4 -> V_41 ) ;
F_17 ( V_4 ) ;
} else
V_42 -> V_51 -> V_53 = V_24 ;
F_30 ( & V_42 -> V_51 -> V_52 ) ;
if ( V_23 )
F_31 ( ( unsigned long ) V_23 ) ;
F_31 ( ( unsigned long ) V_21 ) ;
return V_28 < 0 ? F_11 ( V_28 ) : V_4 ;
}
static void F_32 ( struct V_60 * V_61 )
{
struct V_3 * V_4 = F_33 ( V_61 , struct V_3 , V_61 ) ;
F_20 ( & V_4 -> V_51 -> V_52 ) ;
V_4 -> V_51 -> V_53 -= V_4 -> V_62 ;
F_30 ( & V_4 -> V_51 -> V_52 ) ;
F_34 ( V_4 -> V_51 ) ;
F_17 ( V_4 ) ;
}
void F_35 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_63 * V_51 ;
struct V_64 * V_65 ;
unsigned long V_62 ;
if ( V_4 -> V_49 ) {
F_36 ( V_4 ) ;
return;
}
F_1 ( V_4 -> V_16 -> V_59 , V_4 , 1 ) ;
V_65 = F_37 ( V_4 -> V_41 , V_43 ) ;
F_29 ( V_4 -> V_41 ) ;
if ( ! V_65 )
goto V_57;
V_51 = F_38 ( V_65 ) ;
F_39 ( V_65 ) ;
if ( ! V_51 )
goto V_57;
V_62 = F_19 ( V_4 ) ;
if ( V_16 -> V_66 ) {
if ( ! F_40 ( & V_51 -> V_52 ) ) {
F_41 ( & V_4 -> V_61 , F_32 ) ;
V_4 -> V_51 = V_51 ;
V_4 -> V_62 = V_62 ;
F_42 ( V_67 , & V_4 -> V_61 ) ;
return;
}
} else
F_20 ( & V_51 -> V_52 ) ;
V_51 -> V_53 -= V_62 ;
F_30 ( & V_51 -> V_52 ) ;
F_34 ( V_51 ) ;
V_57:
F_17 ( V_4 ) ;
}
int F_43 ( struct V_3 * V_4 )
{
int V_68 ;
int V_9 ;
int V_69 ;
struct V_6 * V_7 ;
if ( V_4 -> V_49 )
return F_19 ( V_4 ) ;
V_68 = F_44 ( V_4 -> V_39 ) ;
V_69 = 0 ;
F_3 (umem->sg_head.sgl, sg, umem->nmap, i)
V_69 += F_45 ( V_7 ) >> V_68 ;
return V_69 ;
}
int F_46 ( void * V_70 , struct V_3 * V_4 , T_1 V_71 ,
T_1 V_37 )
{
T_1 V_72 = V_71 + V_37 ;
int V_28 ;
if ( V_71 > V_4 -> V_37 || V_37 > V_4 -> V_37 - V_71 ) {
F_47 ( L_1 ,
V_71 , V_4 -> V_37 , V_72 ) ;
return - V_33 ;
}
V_28 = F_48 ( V_4 -> V_11 . V_12 , V_4 -> V_10 , V_70 , V_37 ,
V_71 + F_49 ( V_4 ) ) ;
if ( V_28 < 0 )
return V_28 ;
else if ( V_28 != V_37 )
return - V_33 ;
else
return 0 ;
}
