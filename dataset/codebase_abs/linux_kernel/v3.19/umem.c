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
V_4 -> V_37 = V_17 ;
V_4 -> V_38 = V_39 ;
V_4 -> V_40 = F_14 ( V_41 , V_42 ) ;
V_4 -> V_14 = ! ! ( V_19 &
( V_43 | V_44 |
V_45 | V_46 ) ) ;
if ( V_19 & V_47 ) {
V_28 = F_15 ( V_16 , V_4 ) ;
if ( V_28 ) {
F_16 ( V_4 ) ;
return F_12 ( V_28 ) ;
}
return V_4 ;
}
V_4 -> V_48 = NULL ;
V_4 -> V_49 = 1 ;
V_21 = (struct V_8 * * ) F_17 ( V_34 ) ;
if ( ! V_21 ) {
F_16 ( V_4 ) ;
return F_12 ( - V_35 ) ;
}
V_23 = (struct V_22 * * ) F_17 ( V_34 ) ;
if ( ! V_23 )
V_4 -> V_49 = 0 ;
V_27 = F_18 ( V_4 ) ;
F_19 ( & V_41 -> V_50 -> V_51 ) ;
V_24 = V_27 + V_41 -> V_50 -> V_52 ;
V_25 = F_20 ( V_53 ) >> V_54 ;
if ( ( V_24 > V_25 ) && ! F_21 ( V_55 ) ) {
V_28 = - V_35 ;
goto V_56;
}
V_26 = V_17 & V_57 ;
if ( V_27 == 0 ) {
V_28 = - V_58 ;
goto V_56;
}
V_28 = F_22 ( & V_4 -> V_11 , V_27 , V_34 ) ;
if ( V_28 )
goto V_56;
V_31 = 1 ;
V_30 = V_4 -> V_11 . V_12 ;
while ( V_27 ) {
V_28 = F_23 ( V_41 , V_41 -> V_50 , V_26 ,
F_24 (unsigned long, npages,
PAGE_SIZE / sizeof (struct page *)) ,
1 , ! V_4 -> V_14 , V_21 , V_23 ) ;
if ( V_28 < 0 )
goto V_56;
V_4 -> V_27 += V_28 ;
V_26 += V_28 * V_39 ;
V_27 -= V_28 ;
F_3 (sg_list_start, sg, ret, i) {
if ( V_23 && ! F_25 ( V_23 [ V_9 ] ) )
V_4 -> V_49 = 0 ;
F_26 ( V_7 , V_21 [ V_9 ] , V_39 , 0 ) ;
}
V_30 = V_7 ;
}
V_4 -> V_10 = F_27 ( V_16 -> V_59 ,
V_4 -> V_11 . V_12 ,
V_4 -> V_27 ,
V_13 ,
& V_29 ) ;
if ( V_4 -> V_10 <= 0 ) {
V_28 = - V_35 ;
goto V_56;
}
V_28 = 0 ;
V_56:
if ( V_28 < 0 ) {
if ( V_31 )
F_1 ( V_16 -> V_59 , V_4 , 0 ) ;
F_28 ( V_4 -> V_40 ) ;
F_16 ( V_4 ) ;
} else
V_41 -> V_50 -> V_52 = V_24 ;
F_29 ( & V_41 -> V_50 -> V_51 ) ;
if ( V_23 )
F_30 ( ( unsigned long ) V_23 ) ;
F_30 ( ( unsigned long ) V_21 ) ;
return V_28 < 0 ? F_12 ( V_28 ) : V_4 ;
}
static void F_31 ( struct V_60 * V_61 )
{
struct V_3 * V_4 = F_32 ( V_61 , struct V_3 , V_61 ) ;
F_19 ( & V_4 -> V_50 -> V_51 ) ;
V_4 -> V_50 -> V_52 -= V_4 -> V_62 ;
F_29 ( & V_4 -> V_50 -> V_51 ) ;
F_33 ( V_4 -> V_50 ) ;
F_16 ( V_4 ) ;
}
void F_34 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_63 * V_50 ;
struct V_64 * V_65 ;
unsigned long V_62 ;
if ( V_4 -> V_48 ) {
F_35 ( V_4 ) ;
return;
}
F_1 ( V_4 -> V_16 -> V_59 , V_4 , 1 ) ;
V_65 = F_36 ( V_4 -> V_40 , V_42 ) ;
F_28 ( V_4 -> V_40 ) ;
if ( ! V_65 )
goto V_56;
V_50 = F_37 ( V_65 ) ;
F_38 ( V_65 ) ;
if ( ! V_50 )
goto V_56;
V_62 = F_18 ( V_4 ) ;
if ( V_16 -> V_66 ) {
if ( ! F_39 ( & V_50 -> V_51 ) ) {
F_40 ( & V_4 -> V_61 , F_31 ) ;
V_4 -> V_50 = V_50 ;
V_4 -> V_62 = V_62 ;
F_41 ( V_67 , & V_4 -> V_61 ) ;
return;
}
} else
F_19 ( & V_50 -> V_51 ) ;
V_50 -> V_52 -= V_62 ;
F_29 ( & V_50 -> V_51 ) ;
F_33 ( V_50 ) ;
V_56:
F_16 ( V_4 ) ;
}
int F_42 ( struct V_3 * V_4 )
{
int V_68 ;
int V_9 ;
int V_69 ;
struct V_6 * V_7 ;
if ( V_4 -> V_48 )
return F_18 ( V_4 ) ;
V_68 = F_43 ( V_4 -> V_38 ) ;
V_69 = 0 ;
F_3 (umem->sg_head.sgl, sg, umem->nmap, i)
V_69 += F_44 ( V_7 ) >> V_68 ;
return V_69 ;
}
int F_45 ( void * V_70 , struct V_3 * V_4 , T_1 V_71 ,
T_1 V_36 )
{
T_1 V_72 = V_71 + V_36 ;
int V_28 ;
if ( V_71 > V_4 -> V_36 || V_36 > V_4 -> V_36 - V_71 ) {
F_46 ( L_1 ,
V_71 , V_4 -> V_36 , V_72 ) ;
return - V_58 ;
}
V_28 = F_47 ( V_4 -> V_11 . V_12 , V_4 -> V_10 , V_70 , V_36 ,
V_71 + F_48 ( V_4 ) ) ;
if ( V_28 < 0 )
return V_28 ;
else if ( V_28 != V_36 )
return - V_58 ;
else
return 0 ;
}
