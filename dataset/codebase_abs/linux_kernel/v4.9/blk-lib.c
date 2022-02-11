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
T_2 V_18 ;
if ( ! V_13 )
return - V_19 ;
if ( V_10 & V_20 ) {
if ( V_10 & V_21 )
return - V_22 ;
if ( ! F_7 ( V_13 ) )
return - V_22 ;
V_16 = V_23 ;
} else {
if ( ! F_8 ( V_13 ) )
return - V_22 ;
if ( ( V_10 & V_21 ) &&
! V_13 -> V_24 . V_25 )
return - V_22 ;
V_16 = V_26 ;
}
V_18 = ( F_9 ( V_6 ) >> 9 ) - 1 ;
if ( ( V_7 | V_8 ) & V_18 )
return - V_27 ;
V_14 = F_10 ( V_13 -> V_24 . V_28 >> 9 , 1U ) ;
V_17 = ( F_11 ( V_6 ) >> 9 ) % V_14 ;
while ( V_8 ) {
unsigned int V_29 ;
T_2 V_30 , V_31 ;
V_29 = F_12 ( T_2 , V_8 , V_32 >> 9 ) ;
V_30 = V_7 + V_29 ;
V_31 = V_30 ;
if ( V_29 < V_8 &&
F_13 ( V_31 , V_14 ) != V_17 ) {
V_30 = V_30 - V_17 ;
F_13 ( V_30 , V_14 ) ;
V_30 = V_30 * V_14 + V_17 ;
V_29 = V_30 - V_7 ;
}
V_1 = F_1 ( V_1 , 1 , V_9 ) ;
V_1 -> V_33 . V_34 = V_7 ;
V_1 -> V_35 = V_6 ;
F_14 ( V_1 , V_16 , 0 ) ;
V_1 -> V_33 . V_36 = V_29 << 9 ;
V_8 -= V_29 ;
V_7 = V_30 ;
F_15 () ;
}
* V_11 = V_1 ;
return 0 ;
}
int F_16 ( struct V_5 * V_6 , T_2 V_7 ,
T_2 V_8 , T_1 V_9 , unsigned long V_10 )
{
struct V_1 * V_1 = NULL ;
struct V_37 V_38 ;
int V_39 ;
F_17 ( & V_38 ) ;
V_39 = F_5 ( V_6 , V_7 , V_8 , V_9 , V_10 ,
& V_1 ) ;
if ( ! V_39 && V_1 ) {
V_39 = F_18 ( V_1 ) ;
if ( V_39 == - V_22 && ! ( V_10 & V_21 ) )
V_39 = 0 ;
F_19 ( V_1 ) ;
}
F_20 ( & V_38 ) ;
return V_39 ;
}
int F_21 ( struct V_5 * V_6 , T_2 V_7 ,
T_2 V_8 , T_1 V_9 ,
struct V_40 * V_40 )
{
struct V_12 * V_13 = F_6 ( V_6 ) ;
unsigned int V_41 ;
struct V_1 * V_1 = NULL ;
int V_39 = 0 ;
T_2 V_18 ;
if ( ! V_13 )
return - V_19 ;
V_18 = ( F_9 ( V_6 ) >> 9 ) - 1 ;
if ( ( V_7 | V_8 ) & V_18 )
return - V_27 ;
V_41 = V_32 >> 9 ;
while ( V_8 ) {
V_1 = F_1 ( V_1 , 1 , V_9 ) ;
V_1 -> V_33 . V_34 = V_7 ;
V_1 -> V_35 = V_6 ;
V_1 -> V_42 = 1 ;
V_1 -> V_43 -> V_44 = V_40 ;
V_1 -> V_43 -> V_45 = 0 ;
V_1 -> V_43 -> V_46 = F_9 ( V_6 ) ;
F_14 ( V_1 , V_47 , 0 ) ;
if ( V_8 > V_41 ) {
V_1 -> V_33 . V_36 = V_41 << 9 ;
V_8 -= V_41 ;
V_7 += V_41 ;
} else {
V_1 -> V_33 . V_36 = V_8 << 9 ;
V_8 = 0 ;
}
}
if ( V_1 ) {
V_39 = F_18 ( V_1 ) ;
F_19 ( V_1 ) ;
}
return V_39 ;
}
static int F_22 ( struct V_5 * V_6 , T_2 V_7 ,
T_2 V_8 , T_1 V_9 )
{
int V_39 ;
struct V_1 * V_1 = NULL ;
unsigned int V_48 ;
T_2 V_18 ;
V_18 = ( F_9 ( V_6 ) >> 9 ) - 1 ;
if ( ( V_7 | V_8 ) & V_18 )
return - V_27 ;
while ( V_8 != 0 ) {
V_1 = F_1 ( V_1 , F_23 ( V_8 , ( T_2 ) V_49 ) ,
V_9 ) ;
V_1 -> V_33 . V_34 = V_7 ;
V_1 -> V_35 = V_6 ;
F_14 ( V_1 , V_50 , 0 ) ;
while ( V_8 != 0 ) {
V_48 = F_23 ( ( T_2 ) V_51 >> 9 , V_8 ) ;
V_39 = F_24 ( V_1 , F_25 ( 0 ) , V_48 << 9 , 0 ) ;
V_8 -= V_39 >> 9 ;
V_7 += V_39 >> 9 ;
if ( V_39 < ( V_48 << 9 ) )
break;
}
}
if ( V_1 ) {
V_39 = F_18 ( V_1 ) ;
F_19 ( V_1 ) ;
return V_39 ;
}
return 0 ;
}
int F_26 ( struct V_5 * V_6 , T_2 V_7 ,
T_2 V_8 , T_1 V_9 , bool V_52 )
{
if ( V_52 ) {
if ( ! F_16 ( V_6 , V_7 , V_8 , V_9 ,
V_21 ) )
return 0 ;
}
if ( F_27 ( V_6 ) &&
F_21 ( V_6 , V_7 , V_8 , V_9 ,
F_25 ( 0 ) ) == 0 )
return 0 ;
return F_22 ( V_6 , V_7 , V_8 , V_9 ) ;
}
