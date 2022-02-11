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
if ( ! F_7 ( V_13 ) )
return - V_20 ;
V_15 = V_21 ;
} else {
if ( ! F_8 ( V_13 ) )
return - V_20 ;
V_15 = V_22 ;
}
V_17 = ( F_9 ( V_6 ) >> 9 ) - 1 ;
if ( ( V_7 | V_8 ) & V_17 )
return - V_23 ;
V_14 = F_10 ( V_13 -> V_24 . V_25 >> 9 , 1U ) ;
V_16 = ( F_11 ( V_6 ) >> 9 ) % V_14 ;
while ( V_8 ) {
unsigned int V_26 ;
T_2 V_27 , V_28 ;
V_26 = F_12 ( T_2 , V_8 , V_29 >> 9 ) ;
V_27 = V_7 + V_26 ;
V_28 = V_27 ;
if ( V_26 < V_8 &&
F_13 ( V_28 , V_14 ) != V_16 ) {
V_27 = V_27 - V_16 ;
F_13 ( V_27 , V_14 ) ;
V_27 = V_27 * V_14 + V_16 ;
V_26 = V_27 - V_7 ;
}
V_1 = F_1 ( V_1 , 0 , V_9 ) ;
V_1 -> V_30 . V_31 = V_7 ;
V_1 -> V_32 = V_6 ;
F_14 ( V_1 , V_15 , 0 ) ;
V_1 -> V_30 . V_33 = V_26 << 9 ;
V_8 -= V_26 ;
V_7 = V_27 ;
F_15 () ;
}
* V_11 = V_1 ;
return 0 ;
}
int F_16 ( struct V_5 * V_6 , T_2 V_7 ,
T_2 V_8 , T_1 V_9 , unsigned long V_10 )
{
struct V_1 * V_1 = NULL ;
struct V_34 V_35 ;
int V_36 ;
F_17 ( & V_35 ) ;
V_36 = F_5 ( V_6 , V_7 , V_8 , V_9 , V_10 ,
& V_1 ) ;
if ( ! V_36 && V_1 ) {
V_36 = F_18 ( V_1 ) ;
if ( V_36 == - V_20 )
V_36 = 0 ;
F_19 ( V_1 ) ;
}
F_20 ( & V_35 ) ;
return V_36 ;
}
static int F_21 ( struct V_5 * V_6 , T_2 V_7 ,
T_2 V_8 , T_1 V_9 , struct V_37 * V_37 ,
struct V_1 * * V_11 )
{
struct V_12 * V_13 = F_6 ( V_6 ) ;
unsigned int V_38 ;
struct V_1 * V_1 = * V_11 ;
T_2 V_17 ;
if ( ! V_13 )
return - V_18 ;
V_17 = ( F_9 ( V_6 ) >> 9 ) - 1 ;
if ( ( V_7 | V_8 ) & V_17 )
return - V_23 ;
if ( ! F_22 ( V_6 ) )
return - V_20 ;
V_38 = V_29 >> 9 ;
while ( V_8 ) {
V_1 = F_1 ( V_1 , 1 , V_9 ) ;
V_1 -> V_30 . V_31 = V_7 ;
V_1 -> V_32 = V_6 ;
V_1 -> V_39 = 1 ;
V_1 -> V_40 -> V_41 = V_37 ;
V_1 -> V_40 -> V_42 = 0 ;
V_1 -> V_40 -> V_43 = F_9 ( V_6 ) ;
F_14 ( V_1 , V_44 , 0 ) ;
if ( V_8 > V_38 ) {
V_1 -> V_30 . V_33 = V_38 << 9 ;
V_8 -= V_38 ;
V_7 += V_38 ;
} else {
V_1 -> V_30 . V_33 = V_8 << 9 ;
V_8 = 0 ;
}
F_15 () ;
}
* V_11 = V_1 ;
return 0 ;
}
int F_23 ( struct V_5 * V_6 , T_2 V_7 ,
T_2 V_8 , T_1 V_9 ,
struct V_37 * V_37 )
{
struct V_1 * V_1 = NULL ;
struct V_34 V_35 ;
int V_36 ;
F_17 ( & V_35 ) ;
V_36 = F_21 ( V_6 , V_7 , V_8 , V_9 , V_37 ,
& V_1 ) ;
if ( V_36 == 0 && V_1 ) {
V_36 = F_18 ( V_1 ) ;
F_19 ( V_1 ) ;
}
F_20 ( & V_35 ) ;
return V_36 ;
}
static int F_24 ( struct V_5 * V_6 ,
T_2 V_7 , T_2 V_8 , T_1 V_9 ,
struct V_1 * * V_11 , unsigned V_10 )
{
struct V_1 * V_1 = * V_11 ;
unsigned int V_45 ;
struct V_12 * V_13 = F_6 ( V_6 ) ;
if ( ! V_13 )
return - V_18 ;
V_45 = F_25 ( V_6 ) ;
if ( V_45 == 0 )
return - V_20 ;
while ( V_8 ) {
V_1 = F_1 ( V_1 , 0 , V_9 ) ;
V_1 -> V_30 . V_31 = V_7 ;
V_1 -> V_32 = V_6 ;
V_1 -> V_46 = V_47 ;
if ( V_10 & V_48 )
V_1 -> V_46 |= V_49 ;
if ( V_8 > V_45 ) {
V_1 -> V_30 . V_33 = V_45 << 9 ;
V_8 -= V_45 ;
V_7 += V_45 ;
} else {
V_1 -> V_30 . V_33 = V_8 << 9 ;
V_8 = 0 ;
}
F_15 () ;
}
* V_11 = V_1 ;
return 0 ;
}
int F_26 ( struct V_5 * V_6 , T_2 V_7 ,
T_2 V_8 , T_1 V_9 , struct V_1 * * V_11 ,
unsigned V_10 )
{
int V_36 ;
int V_33 = 0 ;
struct V_1 * V_1 = * V_11 ;
unsigned int V_50 ;
T_2 V_17 ;
V_17 = ( F_9 ( V_6 ) >> 9 ) - 1 ;
if ( ( V_7 | V_8 ) & V_17 )
return - V_23 ;
V_36 = F_24 ( V_6 , V_7 , V_8 , V_9 ,
V_11 , V_10 ) ;
if ( V_36 != - V_20 || ( V_10 & V_51 ) )
goto V_52;
V_36 = 0 ;
while ( V_8 != 0 ) {
V_1 = F_1 ( V_1 , F_27 ( V_8 , ( T_2 ) V_53 ) ,
V_9 ) ;
V_1 -> V_30 . V_31 = V_7 ;
V_1 -> V_32 = V_6 ;
F_14 ( V_1 , V_54 , 0 ) ;
while ( V_8 != 0 ) {
V_50 = F_27 ( ( T_2 ) V_55 >> 9 , V_8 ) ;
V_33 = F_28 ( V_1 , F_29 ( 0 ) , V_50 << 9 , 0 ) ;
V_8 -= V_33 >> 9 ;
V_7 += V_33 >> 9 ;
if ( V_33 < ( V_50 << 9 ) )
break;
}
F_15 () ;
}
* V_11 = V_1 ;
V_52:
return V_36 ;
}
int F_30 ( struct V_5 * V_6 , T_2 V_7 ,
T_2 V_8 , T_1 V_9 , unsigned V_10 )
{
int V_36 ;
struct V_1 * V_1 = NULL ;
struct V_34 V_35 ;
F_17 ( & V_35 ) ;
V_36 = F_26 ( V_6 , V_7 , V_8 , V_9 ,
& V_1 , V_10 ) ;
if ( V_36 == 0 && V_1 ) {
V_36 = F_18 ( V_1 ) ;
F_19 ( V_1 ) ;
}
F_20 ( & V_35 ) ;
return V_36 ;
}
