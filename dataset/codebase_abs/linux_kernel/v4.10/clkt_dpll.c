static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 ;
long V_6 , V_7 , V_8 ;
int V_9 = 0 ;
V_5 = V_2 -> V_4 ;
V_6 = F_2 ( F_3 ( & V_2 -> V_10 ) ) / V_3 ;
if ( V_5 -> V_11 & V_12 ) {
V_7 = V_13 ;
V_8 = V_14 ;
} else {
V_7 = F_4 () -> V_7 ;
V_8 = F_4 () -> V_8 ;
}
if ( ! V_7 || ! V_8 ) {
F_5 ( 1 , L_1 ) ;
return V_15 ;
}
if ( V_6 < F_4 () -> V_7 ) {
F_6 ( L_2 ,
V_3 ) ;
V_5 -> V_16 = V_3 ;
V_9 = V_17 ;
} else if ( V_6 > F_4 () -> V_8 ) {
F_6 ( L_3 ,
V_3 ) ;
V_5 -> V_18 = V_3 ;
V_9 = V_15 ;
} else if ( V_6 > F_4 () -> V_19 &&
V_6 < F_4 () -> V_20 ) {
F_6 ( L_4 , V_3 ) ;
V_9 = V_15 ;
}
return V_9 ;
}
static unsigned long F_7 ( unsigned long V_21 ,
unsigned int V_22 , unsigned int V_3 )
{
unsigned long long V_23 ;
V_23 = ( unsigned long long ) V_21 * V_22 ;
F_8 ( V_23 , V_3 ) ;
return V_23 ;
}
static int F_9 ( int * V_22 , int V_3 , unsigned long * V_24 ,
unsigned long V_25 ,
unsigned long V_21 )
{
int V_26 = 0 , V_27 = 0 ;
if ( * V_22 % V_28 >= V_29 )
V_27 = 1 ;
* V_22 = ( * V_22 / V_28 ) + V_27 ;
* V_24 = F_7 ( V_21 , * V_22 , V_3 ) ;
if ( * V_24 > V_25 ) {
( * V_22 ) -- ;
* V_24 = 0 ;
}
if ( * V_22 < V_30 ) {
* V_22 = V_30 ;
* V_24 = 0 ;
V_26 = V_31 ;
}
if ( * V_24 == 0 )
* V_24 = F_7 ( V_21 , * V_22 , V_3 ) ;
return V_26 ;
}
static int F_10 ( T_1 V_32 )
{
T_2 V_33 , V_34 ;
V_33 = F_4 () -> V_35 ;
while ( V_33 ) {
V_34 = F_11 ( V_33 ) ;
V_33 ^= ( 1 << V_34 ) ;
if ( V_32 == V_34 )
return 1 ;
}
return 0 ;
}
T_2 F_12 ( struct V_36 * V_10 )
{
struct V_1 * V_2 = F_13 ( V_10 ) ;
T_1 V_32 ;
struct V_4 * V_5 ;
V_5 = V_2 -> V_4 ;
if ( ! V_5 )
return - V_37 ;
V_32 = V_38 -> V_39 ( V_5 -> V_40 ) ;
V_32 &= V_5 -> V_41 ;
V_32 >>= F_11 ( V_5 -> V_41 ) ;
if ( F_10 ( V_32 ) )
return 1 ;
return 0 ;
}
unsigned long F_14 ( struct V_1 * V_2 )
{
T_3 V_42 ;
T_1 V_43 , V_44 , V_32 ;
struct V_4 * V_5 ;
V_5 = V_2 -> V_4 ;
if ( ! V_5 )
return 0 ;
V_32 = V_38 -> V_39 ( V_5 -> V_40 ) ;
V_32 &= V_5 -> V_41 ;
V_32 >>= F_11 ( V_5 -> V_41 ) ;
if ( F_10 ( V_32 ) )
return F_2 ( V_5 -> V_45 ) ;
V_32 = V_38 -> V_39 ( V_5 -> V_46 ) ;
V_43 = V_32 & V_5 -> V_47 ;
V_43 >>= F_11 ( V_5 -> V_47 ) ;
V_44 = V_32 & V_5 -> V_48 ;
V_44 >>= F_11 ( V_5 -> V_48 ) ;
V_42 = ( T_3 ) F_2 ( V_5 -> V_49 ) * V_43 ;
F_8 ( V_42 , V_44 + 1 ) ;
return V_42 ;
}
long F_15 ( struct V_36 * V_10 , unsigned long V_25 ,
unsigned long * V_21 )
{
struct V_1 * V_2 = F_13 ( V_10 ) ;
int V_22 , V_3 , V_26 , V_50 ;
int V_51 = V_52 , V_53 = V_52 ;
unsigned long V_54 ;
unsigned long V_24 = 0 ;
struct V_4 * V_5 ;
unsigned long V_55 ;
long V_56 ;
long V_57 = V_58 ;
const char * V_59 ;
if ( ! V_2 || ! V_2 -> V_4 )
return ~ 0 ;
V_5 = V_2 -> V_4 ;
if ( V_5 -> V_60 && V_25 > V_5 -> V_60 )
V_25 = V_5 -> V_60 ;
V_55 = F_2 ( V_5 -> V_49 ) ;
V_59 = F_16 ( V_10 ) ;
F_6 ( L_5 ,
V_59 , V_25 ) ;
V_54 = V_25 / ( V_55 / V_28 ) ;
V_50 = V_5 -> V_61 * V_28 ;
V_5 -> V_62 = 0 ;
for ( V_3 = V_5 -> V_18 ; V_3 <= V_5 -> V_16 ; V_3 ++ ) {
V_26 = F_1 ( V_2 , V_3 ) ;
if ( V_26 == V_17 )
break;
else if ( V_26 == V_15 )
continue;
V_22 = V_54 * V_3 ;
if ( V_22 > V_50 )
break;
V_26 = F_9 ( & V_22 , V_3 , & V_24 , V_25 ,
V_55 ) ;
if ( V_26 == V_31 )
continue;
V_56 = V_25 - V_24 ;
if ( V_56 < 0 )
continue;
if ( V_56 < V_57 ) {
V_57 = V_56 ;
V_51 = V_22 ;
V_53 = V_3 ;
}
F_6 ( L_6 ,
V_59 , V_22 , V_3 , V_24 ) ;
if ( V_56 == 0 )
break;
}
if ( V_57 == V_58 ) {
F_6 ( L_7 ,
V_59 , V_25 ) ;
return ~ 0 ;
}
V_5 -> V_63 = V_51 ;
V_5 -> V_64 = V_53 ;
V_5 -> V_62 = V_25 - V_57 ;
return V_5 -> V_62 ;
}
