static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 ,
unsigned long V_4 ,
unsigned long V_5 ,
unsigned long V_6 )
{
struct V_7 * V_8 = V_9 -> V_8 ;
struct V_10 * V_11 ;
unsigned long V_12 = V_13 ;
unsigned long V_14 ;
if ( F_2 ( V_15 ) )
V_12 = V_16 ;
if ( F_3 ( V_4 >= V_17 ) )
return - V_18 ;
if ( V_4 > V_8 -> V_19 ) {
V_14 = V_3 = V_8 -> V_20 ;
} else {
V_14 = V_3 = V_21 ;
V_8 -> V_19 = 0 ;
}
V_12 -= V_4 ;
V_22:
V_3 = F_4 ( V_3 , V_23 ) ;
for ( V_11 = F_5 ( V_8 , V_3 ) ; ; V_11 = V_11 -> V_24 ) {
if ( V_3 < V_17 &&
( V_3 + V_4 ) >= V_17 ) {
V_3 = V_25 ;
V_11 = F_5 ( V_8 , V_25 ) ;
}
if ( F_3 ( V_12 < V_3 ) ) {
if ( V_14 != V_21 ) {
V_14 = V_3 = V_21 ;
V_8 -> V_19 = 0 ;
goto V_22;
}
return - V_18 ;
}
if ( F_6 ( ! V_11 || V_3 + V_4 <= V_11 -> V_26 ) ) {
V_8 -> V_20 = V_3 + V_4 ;
return V_3 ;
}
if ( V_3 + V_8 -> V_19 < V_11 -> V_26 )
V_8 -> V_19 = V_11 -> V_26 - V_3 ;
V_3 = F_4 ( V_11 -> V_27 , V_23 ) ;
}
}
static unsigned long
F_7 ( struct V_1 * V_2 , const unsigned long V_28 ,
const unsigned long V_4 ,
const unsigned long V_5 ,
const unsigned long V_6 )
{
struct V_10 * V_11 ;
struct V_7 * V_8 = V_9 -> V_8 ;
unsigned long V_3 = V_28 ;
F_8 ( ! F_2 ( V_15 ) ) ;
if ( V_4 <= V_8 -> V_19 ) {
V_8 -> V_19 = 0 ;
V_8 -> V_20 = V_8 -> V_29 ;
}
V_3 = V_8 -> V_20 & V_30 ;
if ( F_6 ( V_3 > V_4 ) ) {
V_11 = F_5 ( V_8 , V_3 - V_4 ) ;
if ( ! V_11 || V_3 <= V_11 -> V_26 ) {
return ( V_8 -> V_20 = V_3 - V_4 ) ;
}
}
if ( F_3 ( V_8 -> V_29 < V_4 ) )
goto V_31;
V_3 = ( V_8 -> V_29 - V_4 ) & V_30 ;
do {
V_11 = F_5 ( V_8 , V_3 ) ;
if ( F_6 ( ! V_11 || V_3 + V_4 <= V_11 -> V_26 ) ) {
return ( V_8 -> V_20 = V_3 ) ;
}
if ( V_3 + V_8 -> V_19 < V_11 -> V_26 )
V_8 -> V_19 = V_11 -> V_26 - V_3 ;
V_3 = ( V_11 -> V_26 - V_4 ) & V_30 ;
} while ( F_6 ( V_4 < V_11 -> V_26 ) );
V_31:
V_8 -> V_19 = ~ 0UL ;
V_8 -> V_20 = V_21 ;
V_3 = F_9 ( V_2 , V_28 , V_4 , V_5 , V_6 ) ;
V_8 -> V_20 = V_8 -> V_29 ;
V_8 -> V_19 = ~ 0UL ;
return V_3 ;
}
unsigned long
F_10 ( struct V_1 * V_1 , unsigned long V_3 ,
unsigned long V_4 , unsigned long V_5 , unsigned long V_6 )
{
struct V_7 * V_8 = V_9 -> V_8 ;
struct V_10 * V_11 ;
unsigned long V_12 = V_13 ;
if ( F_2 ( V_15 ) )
V_12 = V_16 ;
if ( V_4 & ~ V_30 )
return - V_32 ;
if ( V_4 > V_12 )
return - V_18 ;
if ( V_6 & V_33 ) {
if ( F_11 ( V_1 , V_3 , V_4 ) )
return - V_32 ;
return V_3 ;
}
if ( V_3 ) {
V_3 = F_4 ( V_3 , V_23 ) ;
V_11 = F_5 ( V_8 , V_3 ) ;
if ( V_12 - V_4 >= V_3 &&
( ! V_11 || V_3 + V_4 <= V_11 -> V_26 ) )
return V_3 ;
}
if ( V_8 -> V_34 == F_9 )
return F_1 ( V_1 , V_3 , V_4 ,
V_5 , V_6 ) ;
else
return F_7 ( V_1 , V_3 , V_4 ,
V_5 , V_6 ) ;
}
T_1 * F_12 ( struct V_7 * V_8 ,
unsigned long V_3 , unsigned long V_35 )
{
T_2 * V_36 ;
T_3 * V_37 ;
T_4 * V_38 ;
T_1 * V_39 = NULL ;
V_3 &= V_30 ;
V_36 = F_13 ( V_8 , V_3 ) ;
V_37 = F_14 ( V_8 , V_36 , V_3 ) ;
if ( V_37 ) {
V_38 = F_15 ( V_8 , V_37 , V_3 ) ;
if ( V_38 )
V_39 = F_16 ( V_8 , NULL , V_38 , V_3 ) ;
}
return V_39 ;
}
T_1 * F_17 ( struct V_7 * V_8 , unsigned long V_3 )
{
T_2 * V_36 ;
T_3 * V_37 ;
T_4 * V_38 ;
T_1 * V_39 = NULL ;
V_3 &= V_30 ;
V_36 = F_13 ( V_8 , V_3 ) ;
if ( ! F_18 ( * V_36 ) ) {
V_37 = F_19 ( V_36 , V_3 ) ;
if ( ! F_20 ( * V_37 ) ) {
V_38 = F_21 ( V_37 , V_3 ) ;
if ( ! F_22 ( * V_38 ) )
V_39 = F_23 ( V_38 , V_3 ) ;
}
}
return V_39 ;
}
int F_24 ( struct V_7 * V_8 , unsigned long * V_3 , T_1 * V_40 )
{
return 0 ;
}
void F_25 ( struct V_7 * V_8 , unsigned long V_3 ,
T_1 * V_40 , T_1 V_41 )
{
int V_42 ;
if ( ! F_26 ( * V_40 ) && F_26 ( V_41 ) )
V_8 -> V_43 . V_44 ++ ;
V_3 &= V_30 ;
for ( V_42 = 0 ; V_42 < ( 1 << V_45 ) ; V_42 ++ ) {
F_27 ( V_8 , V_3 , V_40 , V_41 ) ;
V_40 ++ ;
V_3 += V_46 ;
F_28 ( V_41 ) += V_46 ;
}
}
T_1 F_29 ( struct V_7 * V_8 , unsigned long V_3 ,
T_1 * V_40 )
{
T_1 V_41 ;
int V_42 ;
V_41 = * V_40 ;
if ( F_26 ( V_41 ) )
V_8 -> V_43 . V_44 -- ;
V_3 &= V_30 ;
for ( V_42 = 0 ; V_42 < ( 1 << V_45 ) ; V_42 ++ ) {
F_30 ( V_8 , V_3 , V_40 ) ;
V_3 += V_46 ;
V_40 ++ ;
}
return V_41 ;
}
struct V_47 * F_31 ( struct V_7 * V_8 ,
unsigned long V_48 , int V_49 )
{
return F_32 ( - V_32 ) ;
}
int F_33 ( T_4 V_38 )
{
return 0 ;
}
int F_34 ( T_3 V_37 )
{
return 0 ;
}
struct V_47 * F_35 ( struct V_7 * V_8 , unsigned long V_48 ,
T_4 * V_38 , int V_49 )
{
return NULL ;
}
