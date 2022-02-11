int F_1 ( struct V_1 * V_1 , T_1 V_2 , int V_3 ,
void * V_4 , T_2 V_5 , T_2 V_6 )
{
T_3 V_7 ;
int V_8 ;
F_2 ( ! V_6 ) ;
F_3 ( V_2 >= V_9 ) ;
if ( ! V_6 )
return - V_10 ;
V_7 = F_4 ( V_1 -> V_11 , V_4 , V_6 ,
V_3 ? V_12 : V_13 ) ;
V_8 = F_5 ( V_1 , V_2 , V_3 , V_7 , V_5 , V_6 ) ;
F_6 ( V_1 -> V_11 , V_7 , V_6 ,
V_3 ? V_12 : V_13 ) ;
return V_8 ;
}
int F_5 ( struct V_1 * V_1 , T_1 V_2 , int V_3 ,
T_3 V_7 , T_2 V_5 , T_2 V_6 )
{
struct V_14 * V_15 = F_7 ( sizeof( * V_15 ) * 2 , V_16 ) ;
int V_8 ;
if ( V_15 == NULL )
return - V_17 ;
F_8 ( & V_15 [ 1 ] , V_3 , V_7 , V_5 , V_6 , 0 , 0 ) ;
V_8 = F_9 ( V_1 , V_2 , V_15 , 2 ) ;
F_10 ( V_15 ) ;
return V_8 ;
}
void F_8 ( struct V_14 * V_15 , int V_3 , T_3 V_7 ,
T_2 V_5 , T_2 V_6 , int V_18 , T_2 V_19 )
{
V_15 -> V_20 = F_11 ( V_7 ) ;
V_15 -> V_21 = F_11 ( V_5 ) ;
V_15 -> V_22 = F_11 ( F_12 ( V_6 >> 2 ) ) ;
V_15 -> V_23 = F_11 ( F_13 ( V_24 ) |
( V_3 ? V_25 : 0 ) | V_26 ) ;
if ( V_18 ) {
V_15 -> V_22 |= F_11 ( F_14 ( V_19 >> 2 ) ) ;
V_15 -> V_23 |= F_11 ( F_15 ( V_6 >> 2 ) |
F_16 ( V_18 ) ) ;
}
}
int F_9 ( struct V_1 * V_1 , T_1 V_2 ,
struct V_14 * V_15 , int V_27 )
{
struct V_28 * V_29 ;
unsigned int V_30 ;
int V_8 = 0 ;
T_2 V_31 = 0 ;
T_3 V_32 = 0 ;
F_3 ( V_2 >= V_9 ) ;
F_3 ( ! V_27 || V_27 > V_33 ) ;
V_29 = & V_1 -> V_29 [ V_2 ] ;
F_17 ( & V_29 -> V_34 ) ;
F_18 ( V_1 , F_19 ( V_2 ) , 0 ) ;
F_20 ( V_29 -> V_35 ) ;
V_29 -> error = 0 ;
V_31 = F_21 ( V_1 , F_22 ( V_2 ) ) ;
V_32 = F_4 ( V_1 -> V_11 , V_15 ,
V_27 * sizeof( * V_15 ) ,
V_12 ) ;
F_18 ( V_1 , F_23 ( V_2 ) , V_32 ) ;
F_18 ( V_1 , F_24 ( V_2 ) , V_27 - 1 ) ;
F_18 ( V_1 , F_22 ( V_2 ) , V_31 |
V_36 ) ;
V_30 = F_25 ( & V_29 -> V_35 , V_37 ) ;
F_18 ( V_1 , F_19 ( V_2 ) , 0 ) ;
F_18 ( V_1 , F_22 ( V_2 ) , V_31 ) ;
F_18 ( V_1 , F_24 ( V_2 ) , 0 ) ;
F_18 ( V_1 , F_23 ( V_2 ) , 0 ) ;
F_6 ( V_1 -> V_11 , V_32 ,
V_27 * sizeof( * V_15 ) ,
V_12 ) ;
if ( V_29 -> error )
V_8 = - V_38 ;
else if ( V_30 == 0 )
V_8 = - V_39 ;
F_26 ( & V_29 -> V_34 ) ;
F_27 ( V_8 ) ;
return V_8 ;
}
int F_28 ( struct V_1 * V_1 , T_1 V_2 ,
struct V_14 * V_40 , int V_3 ,
struct V_41 * V_42 , T_2 V_43 ,
T_2 V_5 , T_2 V_6 )
{
int V_44 ;
int V_45 ;
F_3 ( V_2 >= V_9 ) ;
if ( F_27 ( ! V_6 ) )
return - V_10 ;
memset ( V_40 , 0 , sizeof( * V_40 ) ) ;
for ( V_44 = 0 , V_45 = 1 ; V_45 < V_33 && V_42 && V_6 > 0 ;
V_44 ++ , V_42 = F_29 ( V_42 ) ) {
struct V_14 * V_15 = & V_40 [ V_45 ] ;
T_2 V_46 = F_30 ( V_42 ) ;
T_2 V_47 ;
if ( V_43 >= V_46 ) {
V_43 -= V_46 ;
continue;
}
V_46 -= V_43 ;
V_47 = F_31 ( V_46 , V_6 ) ;
F_8 ( V_15 , V_3 , F_32 ( V_42 ) + V_43 ,
V_5 , V_47 , 0 , 0 ) ;
V_6 -= V_47 ;
V_5 += V_47 ;
V_45 ++ ;
V_43 = 0 ;
}
F_27 ( V_6 || V_44 >= V_33 ) ;
return F_9 ( V_1 , V_2 , V_40 , V_45 ) ;
}
static unsigned long long F_33 ( struct V_1 * V_1 , T_1 V_2 ,
T_2 V_48 , int V_6 )
{
T_1 * V_49 ;
T_1 * V_50 ;
int V_44 ;
unsigned long long V_51 = 0 ;
V_49 = F_34 ( V_6 , V_52 ) ;
if ( ! V_49 ) {
F_35 ( V_53 L_1 ) ;
return V_6 ;
}
V_50 = F_34 ( V_6 , V_52 ) ;
if ( ! V_50 ) {
F_35 ( V_53 L_1 ) ;
F_10 ( V_49 ) ;
return V_6 ;
}
memset ( V_49 , V_54 , V_6 ) ;
memset ( V_50 , V_54 + 1 , V_6 ) ;
F_1 ( V_1 , V_2 , 1 , V_49 , V_48 , V_6 ) ;
F_1 ( V_1 , V_2 , 0 , V_50 , V_48 , V_6 ) ;
for ( V_44 = 0 ; V_44 < V_6 ; V_44 ++ )
if ( V_49 [ V_44 ] != V_50 [ V_44 ] )
V_51 ++ ;
F_10 ( V_49 ) ;
F_10 ( V_50 ) ;
return V_51 ;
}
static void F_36 ( struct V_1 * V_1 )
{
unsigned long long V_55 = 0 ;
T_2 V_6 = F_37 ( V_1 ) + F_38 ( V_1 ) ;
int V_44 , V_56 ;
F_39 ( & V_1 -> V_11 -> V_57 , L_2 ,
V_6 ) ;
for ( V_44 = 0 ; V_44 < V_6 ; V_44 += V_58 )
for ( V_56 = 0 ; V_56 < 4 ; V_56 ++ )
V_55 += F_33 ( V_1 , V_56 , V_44 , V_58 ) ;
F_39 ( & V_1 -> V_11 -> V_57 , L_3 ,
V_55 ) ;
return;
}
void F_40 ( struct V_1 * V_1 , int V_2 )
{
struct V_28 * V_29 = & V_1 -> V_29 [ V_2 ] ;
F_18 ( V_1 , V_59 , F_41 ( V_2 ) ) ;
F_42 ( & V_29 -> V_35 ) ;
}
void F_43 ( struct V_1 * V_1 , T_2 V_60 )
{
struct V_28 * V_29 ;
int V_44 ;
if ( ! ( V_60 & V_61 ) )
return;
for ( V_44 = 0 ; V_44 < V_9 ; V_44 ++ ) {
V_29 = & V_1 -> V_29 [ V_44 ] ;
V_29 -> error = 1 ;
F_18 ( V_1 , F_19 ( V_44 ) , 0 ) ;
F_42 ( & V_29 -> V_35 ) ;
}
}
void F_44 ( struct V_1 * V_1 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_9 ; V_44 ++ )
F_45 ( V_1 , F_41 ( V_44 ) ) ;
}
int F_46 ( struct V_1 * V_1 )
{
struct V_28 * V_29 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_9 ; V_44 ++ ) {
V_29 = & V_1 -> V_29 [ V_44 ] ;
F_47 ( & V_29 -> V_34 ) ;
F_48 ( & V_29 -> V_35 ) ;
F_18 ( V_1 , F_19 ( V_44 ) , 0 ) ;
F_18 ( V_1 , F_22 ( V_44 ) ,
V_62 |
F_49 ( 3 ) |
V_63 |
V_64 ) ;
F_50 ( V_1 , F_41 ( V_44 ) ) ;
}
F_36 ( V_1 ) ;
return 0 ;
}
