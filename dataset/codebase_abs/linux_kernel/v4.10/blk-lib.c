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
unsigned int V_15 ;
int V_16 ;
T_2 V_17 ;
if ( ! V_13 )
return - V_18 ;
if ( V_10 & V_19 ) {
if ( V_10 & V_20 )
return - V_21 ;
if ( ! F_7 ( V_13 ) )
return - V_21 ;
V_15 = V_22 ;
} else {
if ( ! F_8 ( V_13 ) )
return - V_21 ;
if ( ( V_10 & V_20 ) &&
! V_13 -> V_23 . V_24 )
return - V_21 ;
V_15 = V_25 ;
}
V_17 = ( F_9 ( V_6 ) >> 9 ) - 1 ;
if ( ( V_7 | V_8 ) & V_17 )
return - V_26 ;
V_14 = F_10 ( V_13 -> V_23 . V_27 >> 9 , 1U ) ;
V_16 = ( F_11 ( V_6 ) >> 9 ) % V_14 ;
while ( V_8 ) {
unsigned int V_28 ;
T_2 V_29 , V_30 ;
V_28 = F_12 ( T_2 , V_8 , V_31 >> 9 ) ;
V_29 = V_7 + V_28 ;
V_30 = V_29 ;
if ( V_28 < V_8 &&
F_13 ( V_30 , V_14 ) != V_16 ) {
V_29 = V_29 - V_16 ;
F_13 ( V_29 , V_14 ) ;
V_29 = V_29 * V_14 + V_16 ;
V_28 = V_29 - V_7 ;
}
V_1 = F_1 ( V_1 , 0 , V_9 ) ;
V_1 -> V_32 . V_33 = V_7 ;
V_1 -> V_34 = V_6 ;
F_14 ( V_1 , V_15 , 0 ) ;
V_1 -> V_32 . V_35 = V_28 << 9 ;
V_8 -= V_28 ;
V_7 = V_29 ;
F_15 () ;
}
* V_11 = V_1 ;
return 0 ;
}
int F_16 ( struct V_5 * V_6 , T_2 V_7 ,
T_2 V_8 , T_1 V_9 , unsigned long V_10 )
{
struct V_1 * V_1 = NULL ;
struct V_36 V_37 ;
int V_38 ;
F_17 ( & V_37 ) ;
V_38 = F_5 ( V_6 , V_7 , V_8 , V_9 , V_10 ,
& V_1 ) ;
if ( ! V_38 && V_1 ) {
V_38 = F_18 ( V_1 ) ;
if ( V_38 == - V_21 && ! ( V_10 & V_20 ) )
V_38 = 0 ;
F_19 ( V_1 ) ;
}
F_20 ( & V_37 ) ;
return V_38 ;
}
static int F_21 ( struct V_5 * V_6 , T_2 V_7 ,
T_2 V_8 , T_1 V_9 , struct V_39 * V_39 ,
struct V_1 * * V_11 )
{
struct V_12 * V_13 = F_6 ( V_6 ) ;
unsigned int V_40 ;
struct V_1 * V_1 = * V_11 ;
T_2 V_17 ;
if ( ! V_13 )
return - V_18 ;
V_17 = ( F_9 ( V_6 ) >> 9 ) - 1 ;
if ( ( V_7 | V_8 ) & V_17 )
return - V_26 ;
if ( ! F_22 ( V_6 ) )
return - V_21 ;
V_40 = V_31 >> 9 ;
while ( V_8 ) {
V_1 = F_1 ( V_1 , 1 , V_9 ) ;
V_1 -> V_32 . V_33 = V_7 ;
V_1 -> V_34 = V_6 ;
V_1 -> V_41 = 1 ;
V_1 -> V_42 -> V_43 = V_39 ;
V_1 -> V_42 -> V_44 = 0 ;
V_1 -> V_42 -> V_45 = F_9 ( V_6 ) ;
F_14 ( V_1 , V_46 , 0 ) ;
if ( V_8 > V_40 ) {
V_1 -> V_32 . V_35 = V_40 << 9 ;
V_8 -= V_40 ;
V_7 += V_40 ;
} else {
V_1 -> V_32 . V_35 = V_8 << 9 ;
V_8 = 0 ;
}
F_15 () ;
}
* V_11 = V_1 ;
return 0 ;
}
int F_23 ( struct V_5 * V_6 , T_2 V_7 ,
T_2 V_8 , T_1 V_9 ,
struct V_39 * V_39 )
{
struct V_1 * V_1 = NULL ;
struct V_36 V_37 ;
int V_38 ;
F_17 ( & V_37 ) ;
V_38 = F_21 ( V_6 , V_7 , V_8 , V_9 , V_39 ,
& V_1 ) ;
if ( V_38 == 0 && V_1 ) {
V_38 = F_18 ( V_1 ) ;
F_19 ( V_1 ) ;
}
F_20 ( & V_37 ) ;
return V_38 ;
}
static int F_24 ( struct V_5 * V_6 ,
T_2 V_7 , T_2 V_8 , T_1 V_9 ,
struct V_1 * * V_11 )
{
struct V_1 * V_1 = * V_11 ;
unsigned int V_47 ;
struct V_12 * V_13 = F_6 ( V_6 ) ;
if ( ! V_13 )
return - V_18 ;
V_47 = F_25 ( V_6 ) ;
if ( V_47 == 0 )
return - V_21 ;
while ( V_8 ) {
V_1 = F_1 ( V_1 , 0 , V_9 ) ;
V_1 -> V_32 . V_33 = V_7 ;
V_1 -> V_34 = V_6 ;
F_14 ( V_1 , V_48 , 0 ) ;
if ( V_8 > V_47 ) {
V_1 -> V_32 . V_35 = V_47 << 9 ;
V_8 -= V_47 ;
V_7 += V_47 ;
} else {
V_1 -> V_32 . V_35 = V_8 << 9 ;
V_8 = 0 ;
}
F_15 () ;
}
* V_11 = V_1 ;
return 0 ;
}
int F_26 ( struct V_5 * V_6 , T_2 V_7 ,
T_2 V_8 , T_1 V_9 , struct V_1 * * V_11 ,
bool V_49 )
{
int V_38 ;
int V_35 = 0 ;
struct V_1 * V_1 = * V_11 ;
unsigned int V_50 ;
T_2 V_17 ;
V_17 = ( F_9 ( V_6 ) >> 9 ) - 1 ;
if ( ( V_7 | V_8 ) & V_17 )
return - V_26 ;
V_38 = F_24 ( V_6 , V_7 , V_8 , V_9 ,
V_11 ) ;
if ( V_38 == 0 || ( V_38 && V_38 != - V_21 ) )
goto V_51;
V_38 = 0 ;
while ( V_8 != 0 ) {
V_1 = F_1 ( V_1 , F_27 ( V_8 , ( T_2 ) V_52 ) ,
V_9 ) ;
V_1 -> V_32 . V_33 = V_7 ;
V_1 -> V_34 = V_6 ;
F_14 ( V_1 , V_53 , 0 ) ;
while ( V_8 != 0 ) {
V_50 = F_27 ( ( T_2 ) V_54 >> 9 , V_8 ) ;
V_35 = F_28 ( V_1 , F_29 ( 0 ) , V_50 << 9 , 0 ) ;
V_8 -= V_35 >> 9 ;
V_7 += V_35 >> 9 ;
if ( V_35 < ( V_50 << 9 ) )
break;
}
F_15 () ;
}
* V_11 = V_1 ;
V_51:
return V_38 ;
}
int F_30 ( struct V_5 * V_6 , T_2 V_7 ,
T_2 V_8 , T_1 V_9 , bool V_49 )
{
int V_38 ;
struct V_1 * V_1 = NULL ;
struct V_36 V_37 ;
if ( V_49 ) {
if ( ! F_16 ( V_6 , V_7 , V_8 , V_9 ,
V_20 ) )
return 0 ;
}
if ( ! F_23 ( V_6 , V_7 , V_8 , V_9 ,
F_29 ( 0 ) ) )
return 0 ;
F_17 ( & V_37 ) ;
V_38 = F_26 ( V_6 , V_7 , V_8 , V_9 ,
& V_1 , V_49 ) ;
if ( V_38 == 0 && V_1 ) {
V_38 = F_18 ( V_1 ) ;
F_19 ( V_1 ) ;
}
F_20 ( & V_37 ) ;
return V_38 ;
}
