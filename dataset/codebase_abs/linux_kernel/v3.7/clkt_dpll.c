static int F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
struct V_3 * V_4 ;
long V_5 , V_6 , V_7 ;
int V_8 = 0 ;
V_4 = V_1 -> V_3 ;
V_5 = F_2 ( F_3 ( V_1 ) ) / V_2 ;
if ( F_4 () ) {
F_5 ( 1 , L_1 ) ;
return V_9 ;
} else if ( F_6 () ) {
V_6 = V_10 ;
V_7 = V_11 ;
} else if ( V_4 -> V_12 & V_13 ) {
V_6 = V_14 ;
V_7 = V_15 ;
} else {
V_6 = V_16 ;
V_7 = V_17 ;
}
if ( V_5 < V_6 ) {
F_7 ( L_2 ,
V_2 ) ;
V_4 -> V_18 = V_2 ;
V_8 = V_19 ;
} else if ( V_5 > V_7 ) {
F_7 ( L_3 ,
V_2 ) ;
V_4 -> V_20 = V_2 ;
V_8 = V_9 ;
} else if ( F_6 () && V_5 > V_21 &&
V_5 < V_22 ) {
F_7 ( L_4 , V_2 ) ;
V_8 = V_9 ;
}
return V_8 ;
}
static unsigned long F_8 ( unsigned long V_23 ,
unsigned int V_24 , unsigned int V_2 )
{
unsigned long long V_25 ;
V_25 = ( unsigned long long ) V_23 * V_24 ;
F_9 ( V_25 , V_2 ) ;
return V_25 ;
}
static int F_10 ( int * V_24 , int V_2 , unsigned long * V_26 ,
unsigned long V_27 ,
unsigned long V_23 )
{
int V_28 = 0 , V_29 = 0 ;
if ( * V_24 % V_30 >= V_31 )
V_29 = 1 ;
* V_24 = ( * V_24 / V_30 ) + V_29 ;
* V_26 = F_8 ( V_23 , * V_24 , V_2 ) ;
if ( * V_26 > V_27 ) {
( * V_24 ) -- ;
* V_26 = 0 ;
}
if ( * V_24 < V_32 ) {
* V_24 = V_32 ;
* V_26 = 0 ;
V_28 = V_33 ;
}
if ( * V_26 == 0 )
* V_26 = F_8 ( V_23 , * V_24 , V_2 ) ;
return V_28 ;
}
void F_11 ( struct V_1 * V_1 )
{
T_2 V_34 ;
struct V_3 * V_4 ;
V_4 = V_1 -> V_3 ;
if ( ! V_4 )
return;
V_34 = F_12 ( V_4 -> V_35 ) ;
V_34 &= V_4 -> V_36 ;
V_34 >>= F_13 ( V_4 -> V_36 ) ;
if ( F_4 () ) {
if ( V_34 == V_37 ||
V_34 == V_38 )
F_14 ( V_1 , V_4 -> V_39 ) ;
} else if ( F_15 () ) {
if ( V_34 == V_40 ||
V_34 == V_41 )
F_14 ( V_1 , V_4 -> V_39 ) ;
} else if ( F_16 () || F_17 () ) {
if ( V_34 == V_42 ||
V_34 == V_43 ||
V_34 == V_44 )
F_14 ( V_1 , V_4 -> V_39 ) ;
}
return;
}
T_2 F_18 ( struct V_1 * V_1 )
{
long long V_45 ;
T_2 V_46 , V_47 , V_34 ;
struct V_3 * V_4 ;
V_4 = V_1 -> V_3 ;
if ( ! V_4 )
return 0 ;
V_34 = F_12 ( V_4 -> V_35 ) ;
V_34 &= V_4 -> V_36 ;
V_34 >>= F_13 ( V_4 -> V_36 ) ;
if ( F_4 () ) {
if ( V_34 == V_37 ||
V_34 == V_38 )
return F_2 ( V_4 -> V_39 ) ;
} else if ( F_15 () ) {
if ( V_34 == V_40 ||
V_34 == V_41 )
return F_2 ( V_4 -> V_39 ) ;
} else if ( F_16 () || F_17 () ) {
if ( V_34 == V_42 ||
V_34 == V_43 ||
V_34 == V_44 )
return F_2 ( V_4 -> V_39 ) ;
}
V_34 = F_12 ( V_4 -> V_48 ) ;
V_46 = V_34 & V_4 -> V_49 ;
V_46 >>= F_13 ( V_4 -> V_49 ) ;
V_47 = V_34 & V_4 -> V_50 ;
V_47 >>= F_13 ( V_4 -> V_50 ) ;
V_45 = ( long long ) F_2 ( V_4 -> V_51 ) * V_46 ;
F_9 ( V_45 , V_47 + 1 ) ;
return V_45 ;
}
long F_19 ( struct V_1 * V_1 , unsigned long V_27 )
{
int V_24 , V_2 , V_28 , V_52 ;
unsigned long V_53 ;
unsigned long V_26 = 0 ;
struct V_3 * V_4 ;
unsigned long V_54 ;
const char * V_55 ;
if ( ! V_1 || ! V_1 -> V_3 )
return ~ 0 ;
V_4 = V_1 -> V_3 ;
V_54 = F_2 ( V_4 -> V_51 ) ;
V_55 = F_20 ( V_1 ) ;
F_7 ( L_5 ,
V_55 , V_27 ) ;
V_53 = V_27 / ( V_54 / V_30 ) ;
V_52 = V_4 -> V_56 * V_30 ;
V_4 -> V_57 = 0 ;
for ( V_2 = V_4 -> V_20 ; V_2 <= V_4 -> V_18 ; V_2 ++ ) {
V_28 = F_1 ( V_1 , V_2 ) ;
if ( V_28 == V_19 )
break;
else if ( V_28 == V_9 )
continue;
V_24 = V_53 * V_2 ;
if ( V_24 > V_52 )
break;
V_28 = F_10 ( & V_24 , V_2 , & V_26 , V_27 ,
V_54 ) ;
if ( V_28 == V_33 )
continue;
F_7 ( L_6 ,
V_55 , V_24 , V_2 , V_26 ) ;
if ( V_27 == V_26 ) {
V_4 -> V_58 = V_24 ;
V_4 -> V_59 = V_2 ;
V_4 -> V_57 = V_27 ;
break;
}
}
if ( V_27 != V_26 ) {
F_7 ( L_7 ,
V_55 , V_27 ) ;
return ~ 0 ;
}
return V_27 ;
}
