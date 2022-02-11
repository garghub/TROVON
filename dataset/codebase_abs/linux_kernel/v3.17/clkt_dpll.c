static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 ;
long V_6 , V_7 , V_8 ;
int V_9 = 0 ;
V_5 = V_2 -> V_4 ;
V_6 = F_2 ( F_3 ( V_2 -> V_10 . V_2 ) ) / V_3 ;
if ( V_5 -> V_11 & V_12 ) {
V_7 = V_13 ;
V_8 = V_14 ;
} else {
V_7 = V_15 . V_7 ;
V_8 = V_15 . V_8 ;
}
if ( ! V_7 || ! V_8 ) {
F_4 ( 1 , L_1 ) ;
return V_16 ;
}
if ( V_6 < V_15 . V_7 ) {
F_5 ( L_2 ,
V_3 ) ;
V_5 -> V_17 = V_3 ;
V_9 = V_18 ;
} else if ( V_6 > V_15 . V_8 ) {
F_5 ( L_3 ,
V_3 ) ;
V_5 -> V_19 = V_3 ;
V_9 = V_16 ;
} else if ( V_6 > V_15 . V_20 &&
V_6 < V_15 . V_21 ) {
F_5 ( L_4 , V_3 ) ;
V_9 = V_16 ;
}
return V_9 ;
}
static unsigned long F_6 ( unsigned long V_22 ,
unsigned int V_23 , unsigned int V_3 )
{
unsigned long long V_24 ;
V_24 = ( unsigned long long ) V_22 * V_23 ;
F_7 ( V_24 , V_3 ) ;
return V_24 ;
}
static int F_8 ( int * V_23 , int V_3 , unsigned long * V_25 ,
unsigned long V_26 ,
unsigned long V_22 )
{
int V_27 = 0 , V_28 = 0 ;
if ( * V_23 % V_29 >= V_30 )
V_28 = 1 ;
* V_23 = ( * V_23 / V_29 ) + V_28 ;
* V_25 = F_6 ( V_22 , * V_23 , V_3 ) ;
if ( * V_25 > V_26 ) {
( * V_23 ) -- ;
* V_25 = 0 ;
}
if ( * V_23 < V_31 ) {
* V_23 = V_31 ;
* V_25 = 0 ;
V_27 = V_32 ;
}
if ( * V_25 == 0 )
* V_25 = F_6 ( V_22 , * V_23 , V_3 ) ;
return V_27 ;
}
static int F_9 ( T_1 V_33 )
{
T_2 V_34 , V_35 ;
V_34 = V_15 . V_36 ;
while ( V_34 ) {
V_35 = F_10 ( V_34 ) ;
V_34 ^= ( 1 << V_35 ) ;
if ( V_33 == V_35 )
return 1 ;
}
return 0 ;
}
T_2 F_11 ( struct V_37 * V_10 )
{
struct V_1 * V_2 = F_12 ( V_10 ) ;
T_1 V_33 ;
struct V_4 * V_5 ;
V_5 = V_2 -> V_4 ;
if ( ! V_5 )
return - V_38 ;
V_33 = F_13 ( V_2 , V_5 -> V_39 ) ;
V_33 &= V_5 -> V_40 ;
V_33 >>= F_10 ( V_5 -> V_40 ) ;
if ( F_9 ( V_33 ) )
return 1 ;
return 0 ;
}
unsigned long F_14 ( struct V_1 * V_2 )
{
long long V_41 ;
T_1 V_42 , V_43 , V_33 ;
struct V_4 * V_5 ;
V_5 = V_2 -> V_4 ;
if ( ! V_5 )
return 0 ;
V_33 = F_13 ( V_2 , V_5 -> V_39 ) ;
V_33 &= V_5 -> V_40 ;
V_33 >>= F_10 ( V_5 -> V_40 ) ;
if ( F_9 ( V_33 ) )
return F_2 ( V_5 -> V_44 ) ;
V_33 = F_13 ( V_2 , V_5 -> V_45 ) ;
V_42 = V_33 & V_5 -> V_46 ;
V_42 >>= F_10 ( V_5 -> V_46 ) ;
V_43 = V_33 & V_5 -> V_47 ;
V_43 >>= F_10 ( V_5 -> V_47 ) ;
V_41 = ( long long ) F_2 ( V_5 -> V_48 ) * V_42 ;
F_7 ( V_41 , V_43 + 1 ) ;
return V_41 ;
}
long F_15 ( struct V_37 * V_10 , unsigned long V_26 ,
unsigned long * V_22 )
{
struct V_1 * V_2 = F_12 ( V_10 ) ;
int V_23 , V_3 , V_27 , V_49 ;
int V_50 = V_51 , V_52 = V_51 ;
unsigned long V_53 ;
unsigned long V_25 = 0 ;
struct V_4 * V_5 ;
unsigned long V_54 ;
long V_55 ;
long V_56 = V_57 ;
const char * V_58 ;
if ( ! V_2 || ! V_2 -> V_4 )
return ~ 0 ;
V_5 = V_2 -> V_4 ;
V_54 = F_2 ( V_5 -> V_48 ) ;
V_58 = F_16 ( V_10 -> V_2 ) ;
F_5 ( L_5 ,
V_58 , V_26 ) ;
V_53 = V_26 / ( V_54 / V_29 ) ;
V_49 = V_5 -> V_59 * V_29 ;
V_5 -> V_60 = 0 ;
for ( V_3 = V_5 -> V_19 ; V_3 <= V_5 -> V_17 ; V_3 ++ ) {
V_27 = F_1 ( V_2 , V_3 ) ;
if ( V_27 == V_18 )
break;
else if ( V_27 == V_16 )
continue;
V_23 = V_53 * V_3 ;
if ( V_23 > V_49 )
break;
V_27 = F_8 ( & V_23 , V_3 , & V_25 , V_26 ,
V_54 ) ;
if ( V_27 == V_32 )
continue;
V_55 = V_26 - V_25 ;
if ( V_55 < 0 )
continue;
if ( V_55 < V_56 ) {
V_56 = V_55 ;
V_50 = V_23 ;
V_52 = V_3 ;
}
F_5 ( L_6 ,
V_58 , V_23 , V_3 , V_25 ) ;
if ( V_55 == 0 )
break;
}
if ( V_56 == V_57 ) {
F_5 ( L_7 ,
V_58 , V_26 ) ;
return ~ 0 ;
}
V_5 -> V_61 = V_50 ;
V_5 -> V_62 = V_52 ;
V_5 -> V_60 = V_26 - V_56 ;
return V_5 -> V_60 ;
}
