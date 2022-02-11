static struct V_1 * F_1 ( struct V_1 * V_1 , int V_2 , unsigned int V_3 ,
T_1 V_4 )
{
struct V_1 * V_5 = F_2 ( V_4 , V_3 ) ;
if ( V_1 ) {
F_3 ( V_1 , V_5 ) ;
F_4 ( V_2 , V_1 ) ;
}
return V_5 ;
}
int F_5 ( struct V_6 * V_7 , T_2 V_8 ,
T_2 V_9 , T_1 V_10 , int type , struct V_1 * * V_11 )
{
struct V_12 * V_13 = F_6 ( V_7 ) ;
struct V_1 * V_1 = * V_11 ;
unsigned int V_14 ;
int V_15 ;
if ( ! V_13 )
return - V_16 ;
if ( ! F_7 ( V_13 ) )
return - V_17 ;
if ( ( type & V_18 ) && ! F_8 ( V_13 ) )
return - V_17 ;
V_14 = F_9 ( V_13 -> V_19 . V_20 >> 9 , 1U ) ;
V_15 = ( F_10 ( V_7 ) >> 9 ) % V_14 ;
while ( V_9 ) {
unsigned int V_21 ;
T_2 V_22 , V_23 ;
V_21 = F_11 ( T_2 , V_9 , V_24 >> 9 ) ;
V_22 = V_8 + V_21 ;
V_23 = V_22 ;
if ( V_21 < V_9 &&
F_12 ( V_23 , V_14 ) != V_15 ) {
V_22 = V_22 - V_15 ;
F_12 ( V_22 , V_14 ) ;
V_22 = V_22 * V_14 + V_15 ;
V_21 = V_22 - V_8 ;
}
V_1 = F_1 ( V_1 , type , 1 , V_10 ) ;
V_1 -> V_25 . V_26 = V_8 ;
V_1 -> V_27 = V_7 ;
V_1 -> V_25 . V_28 = V_21 << 9 ;
V_9 -= V_21 ;
V_8 = V_22 ;
F_13 () ;
}
* V_11 = V_1 ;
return 0 ;
}
int F_14 ( struct V_6 * V_7 , T_2 V_8 ,
T_2 V_9 , T_1 V_10 , unsigned long V_29 )
{
int type = V_30 | V_31 ;
struct V_1 * V_1 = NULL ;
struct V_32 V_33 ;
int V_34 ;
if ( V_29 & V_35 )
type |= V_18 ;
F_15 ( & V_33 ) ;
V_34 = F_5 ( V_7 , V_8 , V_9 , V_10 , type ,
& V_1 ) ;
if ( ! V_34 && V_1 ) {
V_34 = F_16 ( type , V_1 ) ;
if ( V_34 == - V_17 )
V_34 = 0 ;
F_17 ( V_1 ) ;
}
F_18 ( & V_33 ) ;
return V_34 ;
}
int F_19 ( struct V_6 * V_7 , T_2 V_8 ,
T_2 V_9 , T_1 V_10 ,
struct V_36 * V_36 )
{
struct V_12 * V_13 = F_6 ( V_7 ) ;
unsigned int V_37 ;
struct V_1 * V_1 = NULL ;
int V_34 = 0 ;
if ( ! V_13 )
return - V_16 ;
V_37 = V_24 >> 9 ;
while ( V_9 ) {
V_1 = F_1 ( V_1 , V_30 | V_38 , 1 , V_10 ) ;
V_1 -> V_25 . V_26 = V_8 ;
V_1 -> V_27 = V_7 ;
V_1 -> V_39 = 1 ;
V_1 -> V_40 -> V_41 = V_36 ;
V_1 -> V_40 -> V_42 = 0 ;
V_1 -> V_40 -> V_43 = F_20 ( V_7 ) ;
if ( V_9 > V_37 ) {
V_1 -> V_25 . V_28 = V_37 << 9 ;
V_9 -= V_37 ;
V_8 += V_37 ;
} else {
V_1 -> V_25 . V_28 = V_9 << 9 ;
V_9 = 0 ;
}
}
if ( V_1 ) {
V_34 = F_16 ( V_30 | V_38 , V_1 ) ;
F_17 ( V_1 ) ;
}
return V_34 != - V_17 ? V_34 : 0 ;
}
static int F_21 ( struct V_6 * V_7 , T_2 V_8 ,
T_2 V_9 , T_1 V_10 )
{
int V_34 ;
struct V_1 * V_1 = NULL ;
unsigned int V_44 ;
while ( V_9 != 0 ) {
V_1 = F_1 ( V_1 , V_45 ,
F_22 ( V_9 , ( T_2 ) V_46 ) ,
V_10 ) ;
V_1 -> V_25 . V_26 = V_8 ;
V_1 -> V_27 = V_7 ;
while ( V_9 != 0 ) {
V_44 = F_22 ( ( T_2 ) V_47 >> 9 , V_9 ) ;
V_34 = F_23 ( V_1 , F_24 ( 0 ) , V_44 << 9 , 0 ) ;
V_9 -= V_34 >> 9 ;
V_8 += V_34 >> 9 ;
if ( V_34 < ( V_44 << 9 ) )
break;
}
}
if ( V_1 ) {
V_34 = F_16 ( V_45 , V_1 ) ;
F_17 ( V_1 ) ;
return V_34 ;
}
return 0 ;
}
int F_25 ( struct V_6 * V_7 , T_2 V_8 ,
T_2 V_9 , T_1 V_10 , bool V_48 )
{
struct V_12 * V_13 = F_6 ( V_7 ) ;
if ( V_48 && F_7 ( V_13 ) && V_13 -> V_19 . V_49 &&
F_14 ( V_7 , V_8 , V_9 , V_10 , 0 ) == 0 )
return 0 ;
if ( F_26 ( V_7 ) &&
F_19 ( V_7 , V_8 , V_9 , V_10 ,
F_24 ( 0 ) ) == 0 )
return 0 ;
return F_21 ( V_7 , V_8 , V_9 , V_10 ) ;
}
