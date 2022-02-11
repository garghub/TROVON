static int F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
struct V_3 * V_4 ;
long V_5 , V_6 , V_7 ;
int V_8 = 0 ;
V_4 = V_1 -> V_3 ;
V_5 = V_1 -> V_9 -> V_10 / V_2 ;
if ( F_2 () ) {
F_3 ( 1 , L_1 ) ;
return V_11 ;
} else if ( F_4 () ) {
V_6 = V_12 ;
V_7 = V_13 ;
} else if ( V_4 -> V_14 & V_15 ) {
V_6 = V_16 ;
V_7 = V_17 ;
} else {
V_6 = V_18 ;
V_7 = V_19 ;
}
if ( V_5 < V_6 ) {
F_5 ( L_2
L_3 , V_2 ) ;
V_4 -> V_20 = V_2 ;
V_8 = V_21 ;
} else if ( V_5 > V_7 ) {
F_5 ( L_2
L_4 , V_2 ) ;
V_4 -> V_22 = V_2 ;
V_8 = V_11 ;
} else if ( F_4 () && V_5 > V_23 &&
V_5 < V_24 ) {
F_5 ( L_5 , V_2 ) ;
V_8 = V_11 ;
}
return V_8 ;
}
static unsigned long F_6 ( unsigned long V_25 ,
unsigned int V_26 , unsigned int V_2 )
{
unsigned long long V_27 ;
V_27 = ( unsigned long long ) V_25 * V_26 ;
F_7 ( V_27 , V_2 ) ;
return V_27 ;
}
static int F_8 ( int * V_26 , int V_2 , unsigned long * V_28 ,
unsigned long V_29 ,
unsigned long V_25 )
{
int V_30 = 0 , V_31 = 0 ;
if ( * V_26 % V_32 >= V_33 )
V_31 = 1 ;
* V_26 = ( * V_26 / V_32 ) + V_31 ;
* V_28 = F_6 ( V_25 , * V_26 , V_2 ) ;
if ( * V_28 > V_29 ) {
( * V_26 ) -- ;
* V_28 = 0 ;
}
if ( * V_26 < V_34 ) {
* V_26 = V_34 ;
* V_28 = 0 ;
V_30 = V_35 ;
}
if ( * V_28 == 0 )
* V_28 = F_6 ( V_25 , * V_26 , V_2 ) ;
return V_30 ;
}
void F_9 ( struct V_1 * V_1 )
{
T_2 V_36 ;
struct V_3 * V_4 ;
V_4 = V_1 -> V_3 ;
if ( ! V_4 )
return;
V_36 = F_10 ( V_4 -> V_37 ) ;
V_36 &= V_4 -> V_38 ;
V_36 >>= F_11 ( V_4 -> V_38 ) ;
if ( F_2 () ) {
if ( V_36 == V_39 ||
V_36 == V_40 )
F_12 ( V_1 , V_4 -> V_41 ) ;
} else if ( F_13 () ) {
if ( V_36 == V_42 ||
V_36 == V_43 )
F_12 ( V_1 , V_4 -> V_41 ) ;
} else if ( F_14 () ) {
if ( V_36 == V_44 ||
V_36 == V_45 ||
V_36 == V_46 )
F_12 ( V_1 , V_4 -> V_41 ) ;
}
return;
}
T_2 F_15 ( struct V_1 * V_1 )
{
long long V_47 ;
T_2 V_48 , V_49 , V_36 ;
struct V_3 * V_4 ;
V_4 = V_1 -> V_3 ;
if ( ! V_4 )
return 0 ;
V_36 = F_10 ( V_4 -> V_37 ) ;
V_36 &= V_4 -> V_38 ;
V_36 >>= F_11 ( V_4 -> V_38 ) ;
if ( F_2 () ) {
if ( V_36 == V_39 ||
V_36 == V_40 )
return V_4 -> V_41 -> V_10 ;
} else if ( F_13 () ) {
if ( V_36 == V_42 ||
V_36 == V_43 )
return V_4 -> V_41 -> V_10 ;
} else if ( F_14 () ) {
if ( V_36 == V_44 ||
V_36 == V_45 ||
V_36 == V_46 )
return V_4 -> V_41 -> V_10 ;
}
V_36 = F_10 ( V_4 -> V_50 ) ;
V_48 = V_36 & V_4 -> V_51 ;
V_48 >>= F_11 ( V_4 -> V_51 ) ;
V_49 = V_36 & V_4 -> V_52 ;
V_49 >>= F_11 ( V_4 -> V_52 ) ;
V_47 = ( long long ) V_4 -> V_53 -> V_10 * V_48 ;
F_7 ( V_47 , V_49 + 1 ) ;
return V_47 ;
}
long F_16 ( struct V_1 * V_1 , unsigned long V_29 )
{
int V_26 , V_2 , V_30 , V_54 ;
unsigned long V_55 ;
unsigned long V_28 = 0 ;
struct V_3 * V_4 ;
if ( ! V_1 || ! V_1 -> V_3 )
return ~ 0 ;
V_4 = V_1 -> V_3 ;
F_5 ( L_6 ,
V_1 -> V_56 , V_29 ) ;
V_55 = V_29 / ( V_4 -> V_53 -> V_10 / V_32 ) ;
V_54 = V_4 -> V_57 * V_32 ;
V_4 -> V_58 = 0 ;
for ( V_2 = V_4 -> V_22 ; V_2 <= V_4 -> V_20 ; V_2 ++ ) {
V_30 = F_1 ( V_1 , V_2 ) ;
if ( V_30 == V_21 )
break;
else if ( V_30 == V_11 )
continue;
V_26 = V_55 * V_2 ;
if ( V_26 > V_54 )
break;
V_30 = F_8 ( & V_26 , V_2 , & V_28 , V_29 ,
V_4 -> V_53 -> V_10 ) ;
if ( V_30 == V_35 )
continue;
F_5 ( L_7 ,
V_1 -> V_56 , V_26 , V_2 , V_28 ) ;
if ( V_29 == V_28 ) {
V_4 -> V_59 = V_26 ;
V_4 -> V_60 = V_2 ;
V_4 -> V_58 = V_29 ;
break;
}
}
if ( V_29 != V_28 ) {
F_5 ( L_8 , V_1 -> V_56 ,
V_29 ) ;
return ~ 0 ;
}
return V_29 ;
}
