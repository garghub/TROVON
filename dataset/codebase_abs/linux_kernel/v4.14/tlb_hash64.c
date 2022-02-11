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
int V_14 , V_24 ;
V_14 = V_9 -> V_15 ;
V_24 = F_16 ( V_9 -> V_2 ) ;
if ( V_14 == 1 )
F_15 ( V_9 -> V_7 [ 0 ] , V_9 -> V_5 [ 0 ] ,
V_9 -> V_11 , V_9 -> V_12 , V_24 ) ;
else
F_19 ( V_14 , V_24 ) ;
V_9 -> V_15 = 0 ;
}
void F_20 ( struct V_25 * V_26 )
{
struct V_8 * V_27 = & F_2 ( V_8 ) ;
if ( V_27 -> V_15 )
F_18 ( V_27 ) ;
F_17 ( V_8 ) ;
}
void F_21 ( struct V_1 * V_2 , unsigned long V_28 ,
unsigned long V_29 )
{
bool V_30 ;
int V_31 ;
unsigned long V_32 ;
V_28 = F_22 ( V_28 , V_33 ) ;
V_29 = F_23 ( V_29 , V_33 ) ;
F_24 ( ! V_2 -> V_34 ) ;
F_25 ( V_32 ) ;
F_26 () ;
for (; V_28 < V_29 ; V_28 += V_33 ) {
T_1 * V_4 = F_27 ( V_2 -> V_34 , V_28 , & V_30 ,
& V_31 ) ;
unsigned long V_5 ;
if ( V_4 == NULL )
continue;
V_5 = F_28 ( * V_4 ) ;
if ( V_30 )
F_29 ( V_28 , V_5 ) ;
if ( ! ( V_5 & V_35 ) )
continue;
if ( F_30 ( V_30 ) )
F_31 ( V_2 , V_28 , ( V_36 * ) V_4 , V_5 ) ;
else
F_1 ( V_2 , V_28 , V_4 , V_5 , V_31 ) ;
}
F_32 () ;
F_33 ( V_32 ) ;
}
void F_34 ( struct V_1 * V_2 , V_36 * V_37 , unsigned long V_3 )
{
T_1 * V_5 ;
T_1 * V_38 ;
unsigned long V_32 ;
V_3 = F_22 ( V_3 , V_39 ) ;
F_25 ( V_32 ) ;
F_26 () ;
V_38 = F_35 ( V_37 , V_3 ) ;
for ( V_5 = V_38 ; V_5 < V_38 + V_40 ; V_5 ++ ) {
unsigned long V_41 = F_28 ( * V_5 ) ;
if ( V_41 & V_35 )
F_1 ( V_2 , V_3 , V_5 , V_41 , 0 ) ;
V_3 += V_33 ;
}
F_32 () ;
F_33 ( V_32 ) ;
}
