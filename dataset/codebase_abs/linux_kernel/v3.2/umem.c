static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 , * V_8 ;
int V_9 ;
F_2 (chunk, tmp, &umem->chunk_list, list) {
F_3 ( V_2 , V_7 -> V_10 ,
V_7 -> V_11 , V_12 ) ;
for ( V_9 = 0 ; V_9 < V_7 -> V_11 ; ++ V_9 ) {
struct V_13 * V_13 = F_4 ( & V_7 -> V_10 [ V_9 ] ) ;
if ( V_4 -> V_14 && V_5 )
F_5 ( V_13 ) ;
F_6 ( V_13 ) ;
}
F_7 ( V_7 ) ;
}
}
struct V_3 * F_8 ( struct V_15 * V_16 , unsigned long V_17 ,
T_1 V_18 , int V_19 , int V_20 )
{
struct V_3 * V_4 ;
struct V_13 * * V_10 ;
struct V_21 * * V_22 ;
struct V_6 * V_7 ;
unsigned long V_23 ;
unsigned long V_24 ;
unsigned long V_25 ;
unsigned long V_26 ;
int V_27 ;
int V_28 ;
int V_9 ;
F_9 ( V_29 ) ;
if ( V_20 )
F_10 ( V_30 , & V_29 ) ;
if ( ! F_11 () )
return F_12 ( - V_31 ) ;
V_4 = F_13 ( sizeof *V_4 , V_32 ) ;
if ( ! V_4 )
return F_12 ( - V_33 ) ;
V_4 -> V_16 = V_16 ;
V_4 -> V_34 = V_18 ;
V_4 -> V_35 = V_17 & ~ V_36 ;
V_4 -> V_37 = V_38 ;
V_4 -> V_14 = ! ! ( V_19 & ~ V_39 ) ;
V_4 -> V_40 = 1 ;
F_14 ( & V_4 -> V_41 ) ;
V_10 = (struct V_13 * * ) F_15 ( V_32 ) ;
if ( ! V_10 ) {
F_7 ( V_4 ) ;
return F_12 ( - V_33 ) ;
}
V_22 = (struct V_21 * * ) F_15 ( V_32 ) ;
if ( ! V_22 )
V_4 -> V_40 = 0 ;
V_26 = F_16 ( V_18 + V_4 -> V_35 ) >> V_42 ;
F_17 ( & V_43 -> V_44 -> V_45 ) ;
V_23 = V_26 + V_43 -> V_44 -> V_46 ;
V_24 = F_18 ( V_47 ) >> V_42 ;
if ( ( V_23 > V_24 ) && ! F_19 ( V_48 ) ) {
V_27 = - V_33 ;
goto V_49;
}
V_25 = V_17 & V_36 ;
V_27 = 0 ;
while ( V_26 ) {
V_27 = F_20 ( V_43 , V_43 -> V_44 , V_25 ,
F_21 (unsigned long, npages,
PAGE_SIZE / sizeof (struct page *)) ,
1 , ! V_4 -> V_14 , V_10 , V_22 ) ;
if ( V_27 < 0 )
goto V_49;
V_25 += V_27 * V_38 ;
V_26 -= V_27 ;
V_28 = 0 ;
while ( V_27 ) {
V_7 = F_13 ( sizeof *V_7 + sizeof ( struct V_50 ) *
F_21 ( int , V_27 , V_51 ) ,
V_32 ) ;
if ( ! V_7 ) {
V_27 = - V_33 ;
goto V_49;
}
V_7 -> V_11 = F_21 ( int , V_27 , V_51 ) ;
F_22 ( V_7 -> V_10 , V_7 -> V_11 ) ;
for ( V_9 = 0 ; V_9 < V_7 -> V_11 ; ++ V_9 ) {
if ( V_22 &&
! F_23 ( V_22 [ V_9 + V_28 ] ) )
V_4 -> V_40 = 0 ;
F_24 ( & V_7 -> V_10 [ V_9 ] , V_10 [ V_9 + V_28 ] , V_38 , 0 ) ;
}
V_7 -> V_52 = F_25 ( V_16 -> V_53 ,
& V_7 -> V_10 [ 0 ] ,
V_7 -> V_11 ,
V_12 ,
& V_29 ) ;
if ( V_7 -> V_52 <= 0 ) {
for ( V_9 = 0 ; V_9 < V_7 -> V_11 ; ++ V_9 )
F_6 ( F_4 ( & V_7 -> V_10 [ V_9 ] ) ) ;
F_7 ( V_7 ) ;
V_27 = - V_33 ;
goto V_49;
}
V_27 -= V_7 -> V_11 ;
V_28 += V_7 -> V_11 ;
F_26 ( & V_7 -> V_54 , & V_4 -> V_41 ) ;
}
V_27 = 0 ;
}
V_49:
if ( V_27 < 0 ) {
F_1 ( V_16 -> V_53 , V_4 , 0 ) ;
F_7 ( V_4 ) ;
} else
V_43 -> V_44 -> V_46 = V_23 ;
F_27 ( & V_43 -> V_44 -> V_45 ) ;
if ( V_22 )
F_28 ( ( unsigned long ) V_22 ) ;
F_28 ( ( unsigned long ) V_10 ) ;
return V_27 < 0 ? F_12 ( V_27 ) : V_4 ;
}
static void F_29 ( struct V_55 * V_56 )
{
struct V_3 * V_4 = F_30 ( V_56 , struct V_3 , V_56 ) ;
F_17 ( & V_4 -> V_44 -> V_45 ) ;
V_4 -> V_44 -> V_46 -= V_4 -> V_57 ;
F_27 ( & V_4 -> V_44 -> V_45 ) ;
F_31 ( V_4 -> V_44 ) ;
F_7 ( V_4 ) ;
}
void F_32 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_58 * V_44 ;
unsigned long V_57 ;
F_1 ( V_4 -> V_16 -> V_53 , V_4 , 1 ) ;
V_44 = F_33 ( V_43 ) ;
if ( ! V_44 ) {
F_7 ( V_4 ) ;
return;
}
V_57 = F_16 ( V_4 -> V_34 + V_4 -> V_35 ) >> V_42 ;
if ( V_16 -> V_59 ) {
if ( ! F_34 ( & V_44 -> V_45 ) ) {
F_35 ( & V_4 -> V_56 , F_29 ) ;
V_4 -> V_44 = V_44 ;
V_4 -> V_57 = V_57 ;
F_36 ( V_60 , & V_4 -> V_56 ) ;
return;
}
} else
F_17 ( & V_44 -> V_45 ) ;
V_43 -> V_44 -> V_61 -= V_57 ;
F_27 ( & V_44 -> V_45 ) ;
F_31 ( V_44 ) ;
F_7 ( V_4 ) ;
}
int F_37 ( struct V_3 * V_4 )
{
struct V_6 * V_7 ;
int V_62 ;
int V_9 ;
int V_63 ;
V_62 = F_38 ( V_4 -> V_37 ) ;
V_63 = 0 ;
F_39 (chunk, &umem->chunk_list, list)
for ( V_9 = 0 ; V_9 < V_7 -> V_52 ; ++ V_9 )
V_63 += F_40 ( & V_7 -> V_10 [ V_9 ] ) >> V_62 ;
return V_63 ;
}
