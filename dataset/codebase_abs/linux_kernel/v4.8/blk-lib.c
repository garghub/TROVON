static struct V_1 * F_1 ( struct V_1 * V_1 , unsigned int V_2 ,
T_1 V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 , V_2 ) ;
if ( V_1 ) {
F_3 ( V_1 , V_4 ) ;
F_4 ( V_1 ) ;
}
return V_4 ;
}
int F_5 ( struct V_5 * V_6 , T_2 V_7 ,
T_2 V_8 , T_1 V_9 , int V_10 ,
struct V_1 * * V_11 )
{
struct V_12 * V_13 = F_6 ( V_6 ) ;
struct V_1 * V_1 = * V_11 ;
unsigned int V_14 ;
enum V_15 V_16 ;
int V_17 ;
if ( ! V_13 )
return - V_18 ;
if ( V_10 & V_19 ) {
if ( V_10 & V_20 )
return - V_21 ;
if ( ! F_7 ( V_13 ) )
return - V_21 ;
V_16 = V_22 ;
} else {
if ( ! F_8 ( V_13 ) )
return - V_21 ;
if ( ( V_10 & V_20 ) &&
! V_13 -> V_23 . V_24 )
return - V_21 ;
V_16 = V_25 ;
}
V_14 = F_9 ( V_13 -> V_23 . V_26 >> 9 , 1U ) ;
V_17 = ( F_10 ( V_6 ) >> 9 ) % V_14 ;
while ( V_8 ) {
unsigned int V_27 ;
T_2 V_28 , V_29 ;
V_27 = F_11 ( T_2 , V_8 , V_30 >> 9 ) ;
V_28 = V_7 + V_27 ;
V_29 = V_28 ;
if ( V_27 < V_8 &&
F_12 ( V_29 , V_14 ) != V_17 ) {
V_28 = V_28 - V_17 ;
F_12 ( V_28 , V_14 ) ;
V_28 = V_28 * V_14 + V_17 ;
V_27 = V_28 - V_7 ;
}
V_1 = F_1 ( V_1 , 1 , V_9 ) ;
V_1 -> V_31 . V_32 = V_7 ;
V_1 -> V_33 = V_6 ;
F_13 ( V_1 , V_16 , 0 ) ;
V_1 -> V_31 . V_34 = V_27 << 9 ;
V_8 -= V_27 ;
V_7 = V_28 ;
F_14 () ;
}
* V_11 = V_1 ;
return 0 ;
}
int F_15 ( struct V_5 * V_6 , T_2 V_7 ,
T_2 V_8 , T_1 V_9 , unsigned long V_10 )
{
struct V_1 * V_1 = NULL ;
struct V_35 V_36 ;
int V_37 ;
F_16 ( & V_36 ) ;
V_37 = F_5 ( V_6 , V_7 , V_8 , V_9 , V_10 ,
& V_1 ) ;
if ( ! V_37 && V_1 ) {
V_37 = F_17 ( V_1 ) ;
if ( V_37 == - V_21 && ! ( V_10 & V_20 ) )
V_37 = 0 ;
F_18 ( V_1 ) ;
}
F_19 ( & V_36 ) ;
return V_37 ;
}
int F_20 ( struct V_5 * V_6 , T_2 V_7 ,
T_2 V_8 , T_1 V_9 ,
struct V_38 * V_38 )
{
struct V_12 * V_13 = F_6 ( V_6 ) ;
unsigned int V_39 ;
struct V_1 * V_1 = NULL ;
int V_37 = 0 ;
if ( ! V_13 )
return - V_18 ;
V_39 = V_30 >> 9 ;
while ( V_8 ) {
V_1 = F_1 ( V_1 , 1 , V_9 ) ;
V_1 -> V_31 . V_32 = V_7 ;
V_1 -> V_33 = V_6 ;
V_1 -> V_40 = 1 ;
V_1 -> V_41 -> V_42 = V_38 ;
V_1 -> V_41 -> V_43 = 0 ;
V_1 -> V_41 -> V_44 = F_21 ( V_6 ) ;
F_13 ( V_1 , V_45 , 0 ) ;
if ( V_8 > V_39 ) {
V_1 -> V_31 . V_34 = V_39 << 9 ;
V_8 -= V_39 ;
V_7 += V_39 ;
} else {
V_1 -> V_31 . V_34 = V_8 << 9 ;
V_8 = 0 ;
}
}
if ( V_1 ) {
V_37 = F_17 ( V_1 ) ;
F_18 ( V_1 ) ;
}
return V_37 ;
}
static int F_22 ( struct V_5 * V_6 , T_2 V_7 ,
T_2 V_8 , T_1 V_9 )
{
int V_37 ;
struct V_1 * V_1 = NULL ;
unsigned int V_46 ;
while ( V_8 != 0 ) {
V_1 = F_1 ( V_1 , F_23 ( V_8 , ( T_2 ) V_47 ) ,
V_9 ) ;
V_1 -> V_31 . V_32 = V_7 ;
V_1 -> V_33 = V_6 ;
F_13 ( V_1 , V_48 , 0 ) ;
while ( V_8 != 0 ) {
V_46 = F_23 ( ( T_2 ) V_49 >> 9 , V_8 ) ;
V_37 = F_24 ( V_1 , F_25 ( 0 ) , V_46 << 9 , 0 ) ;
V_8 -= V_37 >> 9 ;
V_7 += V_37 >> 9 ;
if ( V_37 < ( V_46 << 9 ) )
break;
}
}
if ( V_1 ) {
V_37 = F_17 ( V_1 ) ;
F_18 ( V_1 ) ;
return V_37 ;
}
return 0 ;
}
int F_26 ( struct V_5 * V_6 , T_2 V_7 ,
T_2 V_8 , T_1 V_9 , bool V_50 )
{
if ( V_50 ) {
if ( ! F_15 ( V_6 , V_7 , V_8 , V_9 ,
V_20 ) )
return 0 ;
}
if ( F_27 ( V_6 ) &&
F_20 ( V_6 , V_7 , V_8 , V_9 ,
F_25 ( 0 ) ) == 0 )
return 0 ;
return F_22 ( V_6 , V_7 , V_8 , V_9 ) ;
}
