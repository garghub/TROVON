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
F_14 ( V_1 , V_6 ) ;
F_15 ( V_1 , V_15 , 0 ) ;
V_1 -> V_30 . V_32 = V_26 << 9 ;
V_8 -= V_26 ;
V_7 = V_27 ;
F_16 () ;
}
* V_11 = V_1 ;
return 0 ;
}
int F_17 ( struct V_5 * V_6 , T_2 V_7 ,
T_2 V_8 , T_1 V_9 , unsigned long V_10 )
{
struct V_1 * V_1 = NULL ;
struct V_33 V_34 ;
int V_35 ;
F_18 ( & V_34 ) ;
V_35 = F_5 ( V_6 , V_7 , V_8 , V_9 , V_10 ,
& V_1 ) ;
if ( ! V_35 && V_1 ) {
V_35 = F_19 ( V_1 ) ;
if ( V_35 == - V_20 )
V_35 = 0 ;
F_20 ( V_1 ) ;
}
F_21 ( & V_34 ) ;
return V_35 ;
}
static int F_22 ( struct V_5 * V_6 , T_2 V_7 ,
T_2 V_8 , T_1 V_9 , struct V_36 * V_36 ,
struct V_1 * * V_11 )
{
struct V_12 * V_13 = F_6 ( V_6 ) ;
unsigned int V_37 ;
struct V_1 * V_1 = * V_11 ;
T_2 V_17 ;
if ( ! V_13 )
return - V_18 ;
V_17 = ( F_9 ( V_6 ) >> 9 ) - 1 ;
if ( ( V_7 | V_8 ) & V_17 )
return - V_23 ;
if ( ! F_23 ( V_6 ) )
return - V_20 ;
V_37 = V_29 >> 9 ;
while ( V_8 ) {
V_1 = F_1 ( V_1 , 1 , V_9 ) ;
V_1 -> V_30 . V_31 = V_7 ;
F_14 ( V_1 , V_6 ) ;
V_1 -> V_38 = 1 ;
V_1 -> V_39 -> V_40 = V_36 ;
V_1 -> V_39 -> V_41 = 0 ;
V_1 -> V_39 -> V_42 = F_9 ( V_6 ) ;
F_15 ( V_1 , V_43 , 0 ) ;
if ( V_8 > V_37 ) {
V_1 -> V_30 . V_32 = V_37 << 9 ;
V_8 -= V_37 ;
V_7 += V_37 ;
} else {
V_1 -> V_30 . V_32 = V_8 << 9 ;
V_8 = 0 ;
}
F_16 () ;
}
* V_11 = V_1 ;
return 0 ;
}
int F_24 ( struct V_5 * V_6 , T_2 V_7 ,
T_2 V_8 , T_1 V_9 ,
struct V_36 * V_36 )
{
struct V_1 * V_1 = NULL ;
struct V_33 V_34 ;
int V_35 ;
F_18 ( & V_34 ) ;
V_35 = F_22 ( V_6 , V_7 , V_8 , V_9 , V_36 ,
& V_1 ) ;
if ( V_35 == 0 && V_1 ) {
V_35 = F_19 ( V_1 ) ;
F_20 ( V_1 ) ;
}
F_21 ( & V_34 ) ;
return V_35 ;
}
static int F_25 ( struct V_5 * V_6 ,
T_2 V_7 , T_2 V_8 , T_1 V_9 ,
struct V_1 * * V_11 , unsigned V_10 )
{
struct V_1 * V_1 = * V_11 ;
unsigned int V_44 ;
struct V_12 * V_13 = F_6 ( V_6 ) ;
if ( ! V_13 )
return - V_18 ;
V_44 = F_26 ( V_6 ) ;
if ( V_44 == 0 )
return - V_20 ;
while ( V_8 ) {
V_1 = F_1 ( V_1 , 0 , V_9 ) ;
V_1 -> V_30 . V_31 = V_7 ;
F_14 ( V_1 , V_6 ) ;
V_1 -> V_45 = V_46 ;
if ( V_10 & V_47 )
V_1 -> V_45 |= V_48 ;
if ( V_8 > V_44 ) {
V_1 -> V_30 . V_32 = V_44 << 9 ;
V_8 -= V_44 ;
V_7 += V_44 ;
} else {
V_1 -> V_30 . V_32 = V_8 << 9 ;
V_8 = 0 ;
}
F_16 () ;
}
* V_11 = V_1 ;
return 0 ;
}
static unsigned int F_27 ( T_2 V_8 )
{
T_2 V_49 = F_28 ( V_8 , V_50 / 512 ) ;
return F_29 ( V_49 , ( T_2 ) V_51 ) ;
}
int F_30 ( struct V_5 * V_6 , T_2 V_7 ,
T_2 V_8 , T_1 V_9 , struct V_1 * * V_11 ,
unsigned V_10 )
{
int V_35 ;
int V_32 = 0 ;
struct V_1 * V_1 = * V_11 ;
unsigned int V_52 ;
T_2 V_17 ;
V_17 = ( F_9 ( V_6 ) >> 9 ) - 1 ;
if ( ( V_7 | V_8 ) & V_17 )
return - V_23 ;
V_35 = F_25 ( V_6 , V_7 , V_8 , V_9 ,
V_11 , V_10 ) ;
if ( V_35 != - V_20 || ( V_10 & V_53 ) )
goto V_54;
V_35 = 0 ;
while ( V_8 != 0 ) {
V_1 = F_1 ( V_1 , F_27 ( V_8 ) ,
V_9 ) ;
V_1 -> V_30 . V_31 = V_7 ;
F_14 ( V_1 , V_6 ) ;
F_15 ( V_1 , V_55 , 0 ) ;
while ( V_8 != 0 ) {
V_52 = F_29 ( ( T_2 ) V_50 , V_8 << 9 ) ;
V_32 = F_31 ( V_1 , F_32 ( 0 ) , V_52 , 0 ) ;
V_8 -= V_32 >> 9 ;
V_7 += V_32 >> 9 ;
if ( V_32 < V_52 )
break;
}
F_16 () ;
}
* V_11 = V_1 ;
V_54:
return V_35 ;
}
int F_33 ( struct V_5 * V_6 , T_2 V_7 ,
T_2 V_8 , T_1 V_9 , unsigned V_10 )
{
int V_35 ;
struct V_1 * V_1 = NULL ;
struct V_33 V_34 ;
F_18 ( & V_34 ) ;
V_35 = F_30 ( V_6 , V_7 , V_8 , V_9 ,
& V_1 , V_10 ) ;
if ( V_35 == 0 && V_1 ) {
V_35 = F_19 ( V_1 ) ;
F_20 ( V_1 ) ;
}
F_21 ( & V_34 ) ;
return V_35 ;
}
