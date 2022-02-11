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
if ( ! F_11 () )
return F_12 ( - V_33 ) ;
V_4 = F_13 ( sizeof *V_4 , V_34 ) ;
if ( ! V_4 )
return F_12 ( - V_35 ) ;
V_4 -> V_16 = V_16 ;
V_4 -> V_36 = V_18 ;
V_4 -> V_37 = V_17 & ~ V_38 ;
V_4 -> V_39 = V_40 ;
V_4 -> V_41 = F_14 ( V_42 , V_43 ) ;
V_4 -> V_14 = ! ! ( V_19 & ~ V_44 ) ;
V_4 -> V_45 = 1 ;
V_21 = (struct V_8 * * ) F_15 ( V_34 ) ;
if ( ! V_21 ) {
F_16 ( V_4 ) ;
return F_12 ( - V_35 ) ;
}
V_23 = (struct V_22 * * ) F_15 ( V_34 ) ;
if ( ! V_23 )
V_4 -> V_45 = 0 ;
V_27 = F_17 ( V_18 + V_4 -> V_37 ) >> V_46 ;
F_18 ( & V_42 -> V_47 -> V_48 ) ;
V_24 = V_27 + V_42 -> V_47 -> V_49 ;
V_25 = F_19 ( V_50 ) >> V_46 ;
if ( ( V_24 > V_25 ) && ! F_20 ( V_51 ) ) {
V_28 = - V_35 ;
goto V_52;
}
V_26 = V_17 & V_38 ;
if ( V_27 == 0 ) {
V_28 = - V_53 ;
goto V_52;
}
V_28 = F_21 ( & V_4 -> V_11 , V_27 , V_34 ) ;
if ( V_28 )
goto V_52;
V_31 = 1 ;
V_30 = V_4 -> V_11 . V_12 ;
while ( V_27 ) {
V_28 = F_22 ( V_42 , V_42 -> V_47 , V_26 ,
F_23 (unsigned long, npages,
PAGE_SIZE / sizeof (struct page *)) ,
1 , ! V_4 -> V_14 , V_21 , V_23 ) ;
if ( V_28 < 0 )
goto V_52;
V_4 -> V_27 += V_28 ;
V_26 += V_28 * V_40 ;
V_27 -= V_28 ;
F_3 (sg_list_start, sg, ret, i) {
if ( V_23 && ! F_24 ( V_23 [ V_9 ] ) )
V_4 -> V_45 = 0 ;
F_25 ( V_7 , V_21 [ V_9 ] , V_40 , 0 ) ;
}
V_30 = V_7 ;
}
V_4 -> V_10 = F_26 ( V_16 -> V_54 ,
V_4 -> V_11 . V_12 ,
V_4 -> V_27 ,
V_13 ,
& V_29 ) ;
if ( V_4 -> V_10 <= 0 ) {
V_28 = - V_35 ;
goto V_52;
}
V_28 = 0 ;
V_52:
if ( V_28 < 0 ) {
if ( V_31 )
F_1 ( V_16 -> V_54 , V_4 , 0 ) ;
F_27 ( V_4 -> V_41 ) ;
F_16 ( V_4 ) ;
} else
V_42 -> V_47 -> V_49 = V_24 ;
F_28 ( & V_42 -> V_47 -> V_48 ) ;
if ( V_23 )
F_29 ( ( unsigned long ) V_23 ) ;
F_29 ( ( unsigned long ) V_21 ) ;
return V_28 < 0 ? F_12 ( V_28 ) : V_4 ;
}
static void F_30 ( struct V_55 * V_56 )
{
struct V_3 * V_4 = F_31 ( V_56 , struct V_3 , V_56 ) ;
F_18 ( & V_4 -> V_47 -> V_48 ) ;
V_4 -> V_47 -> V_49 -= V_4 -> V_57 ;
F_28 ( & V_4 -> V_47 -> V_48 ) ;
F_32 ( V_4 -> V_47 ) ;
F_16 ( V_4 ) ;
}
void F_33 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_58 * V_47 ;
struct V_59 * V_60 ;
unsigned long V_57 ;
F_1 ( V_4 -> V_16 -> V_54 , V_4 , 1 ) ;
V_60 = F_34 ( V_4 -> V_41 , V_43 ) ;
F_27 ( V_4 -> V_41 ) ;
if ( ! V_60 )
goto V_52;
V_47 = F_35 ( V_60 ) ;
F_36 ( V_60 ) ;
if ( ! V_47 )
goto V_52;
V_57 = F_17 ( V_4 -> V_36 + V_4 -> V_37 ) >> V_46 ;
if ( V_16 -> V_61 ) {
if ( ! F_37 ( & V_47 -> V_48 ) ) {
F_38 ( & V_4 -> V_56 , F_30 ) ;
V_4 -> V_47 = V_47 ;
V_4 -> V_57 = V_57 ;
F_39 ( V_62 , & V_4 -> V_56 ) ;
return;
}
} else
F_18 ( & V_47 -> V_48 ) ;
V_47 -> V_49 -= V_57 ;
F_28 ( & V_47 -> V_48 ) ;
F_32 ( V_47 ) ;
V_52:
F_16 ( V_4 ) ;
}
int F_40 ( struct V_3 * V_4 )
{
int V_63 ;
int V_9 ;
int V_64 ;
struct V_6 * V_7 ;
V_63 = F_41 ( V_4 -> V_39 ) ;
V_64 = 0 ;
F_3 (umem->sg_head.sgl, sg, umem->nmap, i)
V_64 += F_42 ( V_7 ) >> V_63 ;
return V_64 ;
}
