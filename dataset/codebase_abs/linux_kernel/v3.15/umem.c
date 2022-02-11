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
V_4 -> V_14 = ! ! ( V_19 & ~ V_41 ) ;
V_4 -> V_42 = 1 ;
V_21 = (struct V_8 * * ) F_14 ( V_34 ) ;
if ( ! V_21 ) {
F_15 ( V_4 ) ;
return F_12 ( - V_35 ) ;
}
V_23 = (struct V_22 * * ) F_14 ( V_34 ) ;
if ( ! V_23 )
V_4 -> V_42 = 0 ;
V_27 = F_16 ( V_18 + V_4 -> V_37 ) >> V_43 ;
F_17 ( & V_44 -> V_45 -> V_46 ) ;
V_24 = V_27 + V_44 -> V_45 -> V_47 ;
V_25 = F_18 ( V_48 ) >> V_43 ;
if ( ( V_24 > V_25 ) && ! F_19 ( V_49 ) ) {
V_28 = - V_35 ;
goto V_50;
}
V_26 = V_17 & V_38 ;
if ( V_27 == 0 ) {
V_28 = - V_51 ;
goto V_50;
}
V_28 = F_20 ( & V_4 -> V_11 , V_27 , V_34 ) ;
if ( V_28 )
goto V_50;
V_31 = 1 ;
V_30 = V_4 -> V_11 . V_12 ;
while ( V_27 ) {
V_28 = F_21 ( V_44 , V_44 -> V_45 , V_26 ,
F_22 (unsigned long, npages,
PAGE_SIZE / sizeof (struct page *)) ,
1 , ! V_4 -> V_14 , V_21 , V_23 ) ;
if ( V_28 < 0 )
goto V_50;
V_4 -> V_27 += V_28 ;
V_26 += V_28 * V_40 ;
V_27 -= V_28 ;
F_3 (sg_list_start, sg, ret, i) {
if ( V_23 && ! F_23 ( V_23 [ V_9 ] ) )
V_4 -> V_42 = 0 ;
F_24 ( V_7 , V_21 [ V_9 ] , V_40 , 0 ) ;
}
V_30 = V_7 ;
}
V_4 -> V_10 = F_25 ( V_16 -> V_52 ,
V_4 -> V_11 . V_12 ,
V_4 -> V_27 ,
V_13 ,
& V_29 ) ;
if ( V_4 -> V_10 <= 0 ) {
V_28 = - V_35 ;
goto V_50;
}
V_28 = 0 ;
V_50:
if ( V_28 < 0 ) {
if ( V_31 )
F_1 ( V_16 -> V_52 , V_4 , 0 ) ;
F_15 ( V_4 ) ;
} else
V_44 -> V_45 -> V_47 = V_24 ;
F_26 ( & V_44 -> V_45 -> V_46 ) ;
if ( V_23 )
F_27 ( ( unsigned long ) V_23 ) ;
F_27 ( ( unsigned long ) V_21 ) ;
return V_28 < 0 ? F_12 ( V_28 ) : V_4 ;
}
static void F_28 ( struct V_53 * V_54 )
{
struct V_3 * V_4 = F_29 ( V_54 , struct V_3 , V_54 ) ;
F_17 ( & V_4 -> V_45 -> V_46 ) ;
V_4 -> V_45 -> V_47 -= V_4 -> V_55 ;
F_26 ( & V_4 -> V_45 -> V_46 ) ;
F_30 ( V_4 -> V_45 ) ;
F_15 ( V_4 ) ;
}
void F_31 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_56 * V_45 ;
unsigned long V_55 ;
F_1 ( V_4 -> V_16 -> V_52 , V_4 , 1 ) ;
V_45 = F_32 ( V_44 ) ;
if ( ! V_45 ) {
F_15 ( V_4 ) ;
return;
}
V_55 = F_16 ( V_4 -> V_36 + V_4 -> V_37 ) >> V_43 ;
if ( V_16 -> V_57 ) {
if ( ! F_33 ( & V_45 -> V_46 ) ) {
F_34 ( & V_4 -> V_54 , F_28 ) ;
V_4 -> V_45 = V_45 ;
V_4 -> V_55 = V_55 ;
F_35 ( V_58 , & V_4 -> V_54 ) ;
return;
}
} else
F_17 ( & V_45 -> V_46 ) ;
V_44 -> V_45 -> V_47 -= V_55 ;
F_26 ( & V_45 -> V_46 ) ;
F_30 ( V_45 ) ;
F_15 ( V_4 ) ;
}
int F_36 ( struct V_3 * V_4 )
{
int V_59 ;
int V_9 ;
int V_60 ;
struct V_6 * V_7 ;
V_59 = F_37 ( V_4 -> V_39 ) ;
V_60 = 0 ;
F_3 (umem->sg_head.sgl, sg, umem->nmap, i)
V_60 += F_38 ( V_7 ) >> V_59 ;
return V_60 ;
}
