static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 ;
long V_6 , V_7 , V_8 ;
int V_9 = 0 ;
V_5 = V_2 -> V_4 ;
V_6 = F_2 ( F_3 ( V_2 -> V_10 . V_2 ) ) / V_3 ;
if ( F_4 () ) {
F_5 ( 1 , L_1 ) ;
return V_11 ;
} else if ( F_6 () ) {
V_7 = V_12 ;
V_8 = V_13 ;
} else if ( V_5 -> V_14 & V_15 ) {
V_7 = V_16 ;
V_8 = V_17 ;
} else {
V_7 = V_18 ;
V_8 = V_19 ;
}
if ( V_6 < V_7 ) {
F_7 ( L_2 ,
V_3 ) ;
V_5 -> V_20 = V_3 ;
V_9 = V_21 ;
} else if ( V_6 > V_8 ) {
F_7 ( L_3 ,
V_3 ) ;
V_5 -> V_22 = V_3 ;
V_9 = V_11 ;
} else if ( F_6 () && V_6 > V_23 &&
V_6 < V_24 ) {
F_7 ( L_4 , V_3 ) ;
V_9 = V_11 ;
}
return V_9 ;
}
static unsigned long F_8 ( unsigned long V_25 ,
unsigned int V_26 , unsigned int V_3 )
{
unsigned long long V_27 ;
V_27 = ( unsigned long long ) V_25 * V_26 ;
F_9 ( V_27 , V_3 ) ;
return V_27 ;
}
static int F_10 ( int * V_26 , int V_3 , unsigned long * V_28 ,
unsigned long V_29 ,
unsigned long V_25 )
{
int V_30 = 0 , V_31 = 0 ;
if ( * V_26 % V_32 >= V_33 )
V_31 = 1 ;
* V_26 = ( * V_26 / V_32 ) + V_31 ;
* V_28 = F_8 ( V_25 , * V_26 , V_3 ) ;
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
* V_28 = F_8 ( V_25 , * V_26 , V_3 ) ;
return V_30 ;
}
T_1 F_11 ( struct V_36 * V_10 )
{
struct V_1 * V_2 = F_12 ( V_10 ) ;
T_2 V_37 ;
struct V_4 * V_5 ;
V_5 = V_2 -> V_4 ;
if ( ! V_5 )
return - V_38 ;
V_37 = F_13 ( V_2 , V_5 -> V_39 ) ;
V_37 &= V_5 -> V_40 ;
V_37 >>= F_14 ( V_5 -> V_40 ) ;
if ( F_4 () ) {
if ( V_37 == V_41 ||
V_37 == V_42 )
return 1 ;
} else if ( F_15 () ) {
if ( V_37 == V_43 ||
V_37 == V_44 )
return 1 ;
} else if ( F_16 () || F_17 () || F_18 () ) {
if ( V_37 == V_45 ||
V_37 == V_46 ||
V_37 == V_47 )
return 1 ;
}
return 0 ;
}
unsigned long F_19 ( struct V_1 * V_2 )
{
long long V_48 ;
T_2 V_49 , V_50 , V_37 ;
struct V_4 * V_5 ;
V_5 = V_2 -> V_4 ;
if ( ! V_5 )
return 0 ;
V_37 = F_13 ( V_2 , V_5 -> V_39 ) ;
V_37 &= V_5 -> V_40 ;
V_37 >>= F_14 ( V_5 -> V_40 ) ;
if ( F_4 () ) {
if ( V_37 == V_41 ||
V_37 == V_42 )
return F_2 ( V_5 -> V_51 ) ;
} else if ( F_15 () ) {
if ( V_37 == V_43 ||
V_37 == V_44 )
return F_2 ( V_5 -> V_51 ) ;
} else if ( F_16 () || F_17 () || F_18 () ) {
if ( V_37 == V_45 ||
V_37 == V_46 ||
V_37 == V_47 )
return F_2 ( V_5 -> V_51 ) ;
}
V_37 = F_13 ( V_2 , V_5 -> V_52 ) ;
V_49 = V_37 & V_5 -> V_53 ;
V_49 >>= F_14 ( V_5 -> V_53 ) ;
V_50 = V_37 & V_5 -> V_54 ;
V_50 >>= F_14 ( V_5 -> V_54 ) ;
V_48 = ( long long ) F_2 ( V_5 -> V_55 ) * V_49 ;
F_9 ( V_48 , V_50 + 1 ) ;
return V_48 ;
}
long F_20 ( struct V_36 * V_10 , unsigned long V_29 ,
unsigned long * V_25 )
{
struct V_1 * V_2 = F_12 ( V_10 ) ;
int V_26 , V_3 , V_30 , V_56 ;
unsigned long V_57 ;
unsigned long V_28 = 0 ;
struct V_4 * V_5 ;
unsigned long V_58 ;
const char * V_59 ;
if ( ! V_2 || ! V_2 -> V_4 )
return ~ 0 ;
V_5 = V_2 -> V_4 ;
V_58 = F_2 ( V_5 -> V_55 ) ;
V_59 = F_21 ( V_10 -> V_2 ) ;
F_7 ( L_5 ,
V_59 , V_29 ) ;
V_57 = V_29 / ( V_58 / V_32 ) ;
V_56 = V_5 -> V_60 * V_32 ;
V_5 -> V_61 = 0 ;
for ( V_3 = V_5 -> V_22 ; V_3 <= V_5 -> V_20 ; V_3 ++ ) {
V_30 = F_1 ( V_2 , V_3 ) ;
if ( V_30 == V_21 )
break;
else if ( V_30 == V_11 )
continue;
V_26 = V_57 * V_3 ;
if ( V_26 > V_56 )
break;
V_30 = F_10 ( & V_26 , V_3 , & V_28 , V_29 ,
V_58 ) ;
if ( V_30 == V_35 )
continue;
F_7 ( L_6 ,
V_59 , V_26 , V_3 , V_28 ) ;
if ( V_29 == V_28 ) {
V_5 -> V_62 = V_26 ;
V_5 -> V_63 = V_3 ;
V_5 -> V_61 = V_29 ;
break;
}
}
if ( V_29 != V_28 ) {
F_7 ( L_7 ,
V_59 , V_29 ) ;
return ~ 0 ;
}
return V_29 ;
}
