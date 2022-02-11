static int F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
struct V_3 * V_4 ;
long V_5 ;
int V_6 = 0 ;
V_4 = V_1 -> V_3 ;
V_5 = V_1 -> V_7 -> V_8 / V_2 ;
if ( V_5 < V_9 ) {
F_2 ( L_1
L_2 , V_2 ) ;
V_4 -> V_10 = V_2 ;
V_6 = V_11 ;
} else if ( V_5 > V_12 &&
V_5 < V_13 ) {
F_2 ( L_3 , V_2 ) ;
V_6 = V_14 ;
} else if ( V_5 > V_15 ) {
F_2 ( L_1
L_4 , V_2 ) ;
V_4 -> V_16 = V_2 ;
V_6 = V_14 ;
}
return V_6 ;
}
static unsigned long F_3 ( unsigned long V_17 ,
unsigned int V_18 , unsigned int V_2 )
{
unsigned long long V_19 ;
V_19 = ( unsigned long long ) V_17 * V_18 ;
F_4 ( V_19 , V_2 ) ;
return V_19 ;
}
static int F_5 ( int * V_18 , int V_2 , unsigned long * V_20 ,
unsigned long V_21 ,
unsigned long V_17 )
{
int V_22 = 0 , V_23 = 0 ;
if ( * V_18 % V_24 >= V_25 )
V_23 = 1 ;
* V_18 = ( * V_18 / V_24 ) + V_23 ;
* V_20 = F_3 ( V_17 , * V_18 , V_2 ) ;
if ( * V_20 > V_21 ) {
( * V_18 ) -- ;
* V_20 = 0 ;
}
if ( * V_18 < V_26 ) {
* V_18 = V_26 ;
* V_20 = 0 ;
V_22 = V_27 ;
}
if ( * V_20 == 0 )
* V_20 = F_3 ( V_17 , * V_18 , V_2 ) ;
return V_22 ;
}
void F_6 ( struct V_1 * V_1 )
{
T_2 V_28 ;
struct V_3 * V_4 ;
V_4 = V_1 -> V_3 ;
if ( ! V_4 )
return;
V_28 = F_7 ( V_4 -> V_29 ) ;
V_28 &= V_4 -> V_30 ;
V_28 >>= F_8 ( V_4 -> V_30 ) ;
if ( F_9 () ) {
if ( V_28 == V_31 ||
V_28 == V_32 )
F_10 ( V_1 , V_4 -> V_33 ) ;
} else if ( F_11 () ) {
if ( V_28 == V_34 ||
V_28 == V_35 )
F_10 ( V_1 , V_4 -> V_33 ) ;
} else if ( F_12 () ) {
if ( V_28 == V_36 ||
V_28 == V_37 ||
V_28 == V_38 )
F_10 ( V_1 , V_4 -> V_33 ) ;
}
return;
}
T_2 F_13 ( struct V_1 * V_1 )
{
long long V_39 ;
T_2 V_40 , V_41 , V_28 ;
struct V_3 * V_4 ;
V_4 = V_1 -> V_3 ;
if ( ! V_4 )
return 0 ;
V_28 = F_7 ( V_4 -> V_29 ) ;
V_28 &= V_4 -> V_30 ;
V_28 >>= F_8 ( V_4 -> V_30 ) ;
if ( F_9 () ) {
if ( V_28 == V_31 ||
V_28 == V_32 )
return V_4 -> V_33 -> V_8 ;
} else if ( F_11 () ) {
if ( V_28 == V_34 ||
V_28 == V_35 )
return V_4 -> V_33 -> V_8 ;
} else if ( F_12 () ) {
if ( V_28 == V_36 ||
V_28 == V_37 ||
V_28 == V_38 )
return V_4 -> V_33 -> V_8 ;
}
V_28 = F_7 ( V_4 -> V_42 ) ;
V_40 = V_28 & V_4 -> V_43 ;
V_40 >>= F_8 ( V_4 -> V_43 ) ;
V_41 = V_28 & V_4 -> V_44 ;
V_41 >>= F_8 ( V_4 -> V_44 ) ;
V_39 = ( long long ) V_4 -> V_45 -> V_8 * V_40 ;
F_4 ( V_39 , V_41 + 1 ) ;
return V_39 ;
}
long F_14 ( struct V_1 * V_1 , unsigned long V_21 )
{
int V_18 , V_2 , V_22 , V_46 ;
unsigned long V_47 ;
unsigned long V_20 = 0 ;
struct V_3 * V_4 ;
if ( ! V_1 || ! V_1 -> V_3 )
return ~ 0 ;
V_4 = V_1 -> V_3 ;
F_2 ( L_5 ,
V_1 -> V_48 , V_21 ) ;
V_47 = V_21 / ( V_4 -> V_45 -> V_8 / V_24 ) ;
V_46 = V_4 -> V_49 * V_24 ;
V_4 -> V_50 = 0 ;
for ( V_2 = V_4 -> V_16 ; V_2 <= V_4 -> V_10 ; V_2 ++ ) {
V_22 = F_1 ( V_1 , V_2 ) ;
if ( V_22 == V_11 )
break;
else if ( V_22 == V_14 )
continue;
V_18 = V_47 * V_2 ;
if ( V_18 > V_46 )
break;
V_22 = F_5 ( & V_18 , V_2 , & V_20 , V_21 ,
V_4 -> V_45 -> V_8 ) ;
if ( V_22 == V_27 )
continue;
F_2 ( L_6 ,
V_1 -> V_48 , V_18 , V_2 , V_20 ) ;
if ( V_21 == V_20 ) {
V_4 -> V_51 = V_18 ;
V_4 -> V_52 = V_2 ;
V_4 -> V_50 = V_21 ;
break;
}
}
if ( V_21 != V_20 ) {
F_2 ( L_7 , V_1 -> V_48 ,
V_21 ) ;
return ~ 0 ;
}
return V_21 ;
}
