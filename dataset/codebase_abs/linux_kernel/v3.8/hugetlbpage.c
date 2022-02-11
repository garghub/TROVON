static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 ,
unsigned long V_4 ,
unsigned long V_5 ,
unsigned long V_6 )
{
unsigned long V_7 = V_8 ;
struct V_9 V_10 ;
if ( F_2 ( V_11 ) )
V_7 = V_12 ;
V_10 . V_6 = 0 ;
V_10 . V_13 = V_4 ;
V_10 . V_14 = V_15 ;
V_10 . V_16 = F_3 ( V_7 , V_17 ) ;
V_10 . V_18 = V_19 & ~ V_20 ;
V_10 . V_21 = 0 ;
V_3 = F_4 ( & V_10 ) ;
if ( ( V_3 & ~ V_19 ) && V_7 > V_22 ) {
F_5 ( V_3 != - V_23 ) ;
V_10 . V_14 = V_22 ;
V_10 . V_16 = V_7 ;
V_3 = F_4 ( & V_10 ) ;
}
return V_3 ;
}
static unsigned long
F_6 ( struct V_1 * V_2 , const unsigned long V_24 ,
const unsigned long V_4 ,
const unsigned long V_5 ,
const unsigned long V_6 )
{
struct V_25 * V_26 = V_27 -> V_26 ;
unsigned long V_3 = V_24 ;
struct V_9 V_10 ;
F_7 ( ! F_2 ( V_11 ) ) ;
V_10 . V_6 = V_28 ;
V_10 . V_13 = V_4 ;
V_10 . V_14 = V_29 ;
V_10 . V_16 = V_26 -> V_30 ;
V_10 . V_18 = V_19 & ~ V_20 ;
V_10 . V_21 = 0 ;
V_3 = F_4 ( & V_10 ) ;
if ( V_3 & ~ V_19 ) {
F_5 ( V_3 != - V_23 ) ;
V_10 . V_6 = 0 ;
V_10 . V_14 = V_15 ;
V_10 . V_16 = V_12 ;
V_3 = F_4 ( & V_10 ) ;
}
return V_3 ;
}
unsigned long
F_8 ( struct V_1 * V_1 , unsigned long V_3 ,
unsigned long V_4 , unsigned long V_5 , unsigned long V_6 )
{
struct V_25 * V_26 = V_27 -> V_26 ;
struct V_31 * V_32 ;
unsigned long V_7 = V_8 ;
if ( F_2 ( V_11 ) )
V_7 = V_12 ;
if ( V_4 & ~ V_20 )
return - V_33 ;
if ( V_4 > V_7 )
return - V_23 ;
if ( V_6 & V_34 ) {
if ( F_9 ( V_1 , V_3 , V_4 ) )
return - V_33 ;
return V_3 ;
}
if ( V_3 ) {
V_3 = F_10 ( V_3 , V_35 ) ;
V_32 = F_11 ( V_26 , V_3 ) ;
if ( V_7 - V_4 >= V_3 &&
( ! V_32 || V_3 + V_4 <= V_32 -> V_36 ) )
return V_3 ;
}
if ( V_26 -> V_37 == V_38 )
return F_1 ( V_1 , V_3 , V_4 ,
V_5 , V_6 ) ;
else
return F_6 ( V_1 , V_3 , V_4 ,
V_5 , V_6 ) ;
}
T_1 * F_12 ( struct V_25 * V_26 ,
unsigned long V_3 , unsigned long V_39 )
{
T_2 * V_40 ;
T_3 * V_41 ;
T_4 * V_42 ;
T_1 * V_43 = NULL ;
V_3 &= V_20 ;
V_40 = F_13 ( V_26 , V_3 ) ;
V_41 = F_14 ( V_26 , V_40 , V_3 ) ;
if ( V_41 ) {
V_42 = F_15 ( V_26 , V_41 , V_3 ) ;
if ( V_42 )
V_43 = F_16 ( V_26 , NULL , V_42 , V_3 ) ;
}
return V_43 ;
}
T_1 * F_17 ( struct V_25 * V_26 , unsigned long V_3 )
{
T_2 * V_40 ;
T_3 * V_41 ;
T_4 * V_42 ;
T_1 * V_43 = NULL ;
V_3 &= V_20 ;
V_40 = F_13 ( V_26 , V_3 ) ;
if ( ! F_18 ( * V_40 ) ) {
V_41 = F_19 ( V_40 , V_3 ) ;
if ( ! F_20 ( * V_41 ) ) {
V_42 = F_21 ( V_41 , V_3 ) ;
if ( ! F_22 ( * V_42 ) )
V_43 = F_23 ( V_42 , V_3 ) ;
}
}
return V_43 ;
}
int F_24 ( struct V_25 * V_26 , unsigned long * V_3 , T_1 * V_44 )
{
return 0 ;
}
void F_25 ( struct V_25 * V_26 , unsigned long V_3 ,
T_1 * V_44 , T_1 V_45 )
{
int V_46 ;
if ( ! F_26 ( * V_44 ) && F_26 ( V_45 ) )
V_26 -> V_47 . V_48 ++ ;
V_3 &= V_20 ;
for ( V_46 = 0 ; V_46 < ( 1 << V_49 ) ; V_46 ++ ) {
F_27 ( V_26 , V_3 , V_44 , V_45 ) ;
V_44 ++ ;
V_3 += V_29 ;
F_28 ( V_45 ) += V_29 ;
}
}
T_1 F_29 ( struct V_25 * V_26 , unsigned long V_3 ,
T_1 * V_44 )
{
T_1 V_45 ;
int V_46 ;
V_45 = * V_44 ;
if ( F_26 ( V_45 ) )
V_26 -> V_47 . V_48 -- ;
V_3 &= V_20 ;
for ( V_46 = 0 ; V_46 < ( 1 << V_49 ) ; V_46 ++ ) {
F_30 ( V_26 , V_3 , V_44 ) ;
V_3 += V_29 ;
V_44 ++ ;
}
return V_45 ;
}
struct V_50 * F_31 ( struct V_25 * V_26 ,
unsigned long V_51 , int V_52 )
{
return F_32 ( - V_33 ) ;
}
int F_33 ( T_4 V_42 )
{
return 0 ;
}
int F_34 ( T_3 V_41 )
{
return 0 ;
}
struct V_50 * F_35 ( struct V_25 * V_26 , unsigned long V_51 ,
T_4 * V_42 , int V_52 )
{
return NULL ;
}
