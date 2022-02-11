void F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
T_1 * V_4 , unsigned long V_5 , int V_6 )
{
unsigned long V_7 ;
struct V_8 * V_9 = & F_2 ( V_8 ) ;
unsigned long V_10 ;
unsigned int V_11 ;
int V_12 ;
T_2 V_13 ;
int V_14 ;
V_14 = V_9 -> V_15 ;
if ( V_6 ) {
#ifdef F_3
V_11 = F_4 ( V_2 , V_3 ) ;
V_3 &= ~ ( ( 1UL << V_16 [ V_11 ] . V_17 ) - 1 ) ;
#else
F_5 () ;
V_11 = F_6 ( V_2 , V_3 , V_5 ) ;
#endif
} else {
V_11 = F_6 ( V_2 , V_3 , V_5 ) ;
V_3 &= V_18 ;
}
if ( ! F_7 ( V_3 ) ) {
V_12 = F_8 ( V_3 ) ;
V_10 = F_9 ( V_2 -> V_19 . V_20 , V_3 , V_12 ) ;
} else {
V_10 = F_10 ( V_3 , V_21 ) ;
V_12 = V_21 ;
}
F_11 ( V_10 == 0 ) ;
V_7 = F_12 ( V_3 , V_10 , V_12 ) ;
V_13 = F_13 ( F_14 ( V_5 ) , V_4 ) ;
if ( ! V_9 -> V_22 ) {
F_15 ( V_7 , V_13 , V_11 , V_12 , F_16 ( V_2 ) ) ;
F_17 ( V_8 ) ;
return;
}
if ( V_14 != 0 && ( V_2 != V_9 -> V_2 || V_9 -> V_11 != V_11 ||
V_9 -> V_12 != V_12 ) ) {
F_18 ( V_9 ) ;
V_14 = 0 ;
}
if ( V_14 == 0 ) {
V_9 -> V_2 = V_2 ;
V_9 -> V_11 = V_11 ;
V_9 -> V_12 = V_12 ;
}
V_9 -> V_5 [ V_14 ] = V_13 ;
V_9 -> V_7 [ V_14 ] = V_7 ;
V_9 -> V_15 = ++ V_14 ;
if ( V_14 >= V_23 )
F_18 ( V_9 ) ;
F_17 ( V_8 ) ;
}
void F_18 ( struct V_8 * V_9 )
{
const struct V_24 * V_25 ;
int V_14 , V_26 = 0 ;
V_14 = V_9 -> V_15 ;
V_25 = F_19 ( F_20 () ) ;
if ( F_21 ( F_22 ( V_9 -> V_2 ) , V_25 ) )
V_26 = 1 ;
if ( V_14 == 1 )
F_15 ( V_9 -> V_7 [ 0 ] , V_9 -> V_5 [ 0 ] ,
V_9 -> V_11 , V_9 -> V_12 , V_26 ) ;
else
F_23 ( V_14 , V_26 ) ;
V_9 -> V_15 = 0 ;
}
void F_24 ( struct V_27 * V_28 )
{
struct V_8 * V_29 = & F_2 ( V_8 ) ;
if ( V_29 -> V_15 )
F_18 ( V_29 ) ;
F_17 ( V_8 ) ;
}
void F_25 ( struct V_1 * V_2 , unsigned long V_30 ,
unsigned long V_31 )
{
bool V_32 ;
int V_33 ;
unsigned long V_34 ;
V_30 = F_26 ( V_30 , V_35 ) ;
V_31 = F_27 ( V_31 , V_35 ) ;
F_28 ( ! V_2 -> V_36 ) ;
F_29 ( V_34 ) ;
F_30 () ;
for (; V_30 < V_31 ; V_30 += V_35 ) {
T_1 * V_4 = F_31 ( V_2 -> V_36 , V_30 , & V_32 ,
& V_33 ) ;
unsigned long V_5 ;
if ( V_4 == NULL )
continue;
V_5 = F_32 ( * V_4 ) ;
if ( V_32 )
F_33 ( V_30 , V_5 ) ;
if ( ! ( V_5 & V_37 ) )
continue;
if ( F_34 ( V_32 ) )
F_35 ( V_2 , V_30 , ( V_38 * ) V_4 , V_5 ) ;
else
F_1 ( V_2 , V_30 , V_4 , V_5 , V_33 ) ;
}
F_36 () ;
F_37 ( V_34 ) ;
}
void F_38 ( struct V_1 * V_2 , V_38 * V_39 , unsigned long V_3 )
{
T_1 * V_5 ;
T_1 * V_40 ;
unsigned long V_34 ;
V_3 = F_26 ( V_3 , V_41 ) ;
F_29 ( V_34 ) ;
F_30 () ;
V_40 = F_39 ( V_39 , V_3 ) ;
for ( V_5 = V_40 ; V_5 < V_40 + V_42 ; V_5 ++ ) {
unsigned long V_43 = F_32 ( * V_5 ) ;
if ( V_43 & V_37 )
F_1 ( V_2 , V_3 , V_5 , V_43 , 0 ) ;
V_3 += V_35 ;
}
F_36 () ;
F_37 ( V_34 ) ;
}
