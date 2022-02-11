static T_1 T_2 F_1 ( unsigned long V_1 )
{
return F_2 ( V_1 , 0 ) ;
}
static T_1 T_2 F_3 ( unsigned long V_1 )
{
unsigned int V_2 = F_4 ( V_1 ) ;
struct V_3 * V_4 = F_5 ( V_5 , V_2 ) ;
if ( ! V_4 )
return 0 ;
return F_6 ( F_7 ( V_4 ) ) ;
}
T_1 T_2 F_8 ( unsigned int V_6 )
{
unsigned long V_1 = V_6 * V_7 . V_8 . V_9 ;
if ( F_9 () )
return F_3 ( V_1 ) ;
return F_1 ( V_1 ) ;
}
static int T_2
F_10 ( struct V_10 * V_11 , bool V_12 )
{
struct V_13 V_14 ;
T_1 V_15 ;
if ( F_11 ( V_16 ) )
return 0 ;
V_15 = V_11 -> V_15 ;
if ( V_12 )
V_14 . V_14 = F_12 ( V_15 , V_11 -> V_1 , V_17 ) ;
else
V_14 . V_14 = F_13 ( V_15 , V_11 -> V_1 ) ;
if ( ! V_14 . V_14 ) {
F_14 ( L_1 ) ;
return - V_18 ;
}
V_14 . V_15 = V_11 -> V_15 ;
V_14 . V_19 = V_11 -> V_1 / V_11 -> V_9 ;
V_14 . V_20 = V_14 . V_14 + V_11 -> V_1 ;
V_14 . V_21 = V_11 -> V_21 ;
V_14 . V_9 = V_11 -> V_9 ;
V_14 . V_12 = V_12 ;
F_15 ( V_22 , & V_7 . V_23 ) ;
V_7 . V_8 = V_14 ;
return 0 ;
}
int T_2 F_16 ( struct V_10 * V_11 )
{
F_17 ( V_7 . V_8 . V_12 ) ;
return F_10 ( V_11 , false ) ;
}
void T_2 F_18 ( void )
{
if ( ! V_7 . V_8 . V_12 ) {
unsigned long V_1 ;
V_1 = V_7 . V_8 . V_9 * V_7 . V_8 . V_19 ;
F_19 ( V_7 . V_8 . V_14 , V_1 ) ;
} else {
F_20 ( V_7 . V_8 . V_14 ) ;
}
V_7 . V_8 . V_14 = NULL ;
F_21 ( V_22 , & V_7 . V_23 ) ;
}
int T_2 F_22 ( T_1 V_24 , unsigned long V_1 )
{
struct V_10 V_11 = {
. V_15 = V_24 ,
. V_1 = V_1 ,
} ;
F_17 ( V_7 . V_8 . V_14 ) ;
F_17 ( V_7 . V_8 . V_12 ) ;
V_11 . V_21 = V_7 . V_8 . V_21 ;
V_11 . V_9 = V_7 . V_8 . V_9 ;
return F_10 ( & V_11 , true ) ;
}
int T_2 F_23 ( T_1 V_24 , unsigned int V_19 )
{
struct V_10 V_11 ;
F_18 () ;
V_11 . V_15 = V_24 ;
V_11 . V_1 = V_7 . V_8 . V_9 * V_19 ;
V_11 . V_21 = V_7 . V_8 . V_21 ;
V_11 . V_9 = V_7 . V_8 . V_9 ;
return F_10 ( & V_11 , V_7 . V_8 . V_12 ) ;
}
int T_2 F_24 ( T_3 * V_25 , struct V_26 * V_26 )
{
T_4 V_27 , V_28 ;
T_4 V_29 , V_30 ;
int V_31 = 0 ;
V_29 = V_25 -> V_32 ;
V_30 = V_29 + ( V_25 -> V_33 << V_34 ) - 1 ;
V_27 = V_26 -> V_29 ;
V_28 = V_26 -> V_30 ;
if ( V_27 <= V_29 ) {
if ( V_29 < V_28 && V_28 < V_30 )
V_31 ++ ;
}
if ( V_29 < V_27 && V_27 < V_30 ) {
if ( V_28 < V_30 )
V_31 += 2 ;
if ( V_30 <= V_28 )
V_31 ++ ;
}
return V_31 ;
}
void T_2 F_25 ( struct V_13 * V_35 , void * V_36 ,
struct V_37 * V_38 )
{
T_4 V_27 , V_28 , V_39 ;
T_3 * V_25 ;
T_4 V_29 , V_30 ;
void * V_40 , * V_41 ;
V_27 = V_38 -> V_26 . V_29 ;
V_28 = V_38 -> V_26 . V_30 ;
V_39 = V_38 -> V_42 ;
if ( ! F_26 ( V_27 , V_43 ) ||
! F_26 ( V_28 + 1 , V_43 ) ) {
F_17 ( 1 ) ;
return;
}
for ( V_40 = V_35 -> V_14 , V_41 = V_36 ;
V_40 < V_35 -> V_20 ;
V_40 += V_35 -> V_9 , V_41 += V_35 -> V_9 ) {
memcpy ( V_41 , V_40 , V_35 -> V_9 ) ;
V_25 = V_41 ;
V_29 = V_25 -> V_32 ;
V_30 = V_25 -> V_32 + ( V_25 -> V_33 << V_34 ) - 1 ;
if ( V_27 <= V_29 && V_30 <= V_28 )
V_25 -> V_42 |= V_39 ;
if ( V_27 <= V_29 &&
( V_29 < V_28 && V_28 < V_30 ) ) {
V_25 -> V_42 |= V_39 ;
V_25 -> V_33 = ( V_28 - V_25 -> V_32 + 1 ) >>
V_34 ;
V_41 += V_35 -> V_9 ;
memcpy ( V_41 , V_40 , V_35 -> V_9 ) ;
V_25 = V_41 ;
V_25 -> V_32 = V_28 + 1 ;
V_25 -> V_33 = ( V_30 - V_25 -> V_32 + 1 ) >>
V_34 ;
}
if ( ( V_29 < V_27 && V_27 < V_30 ) && V_28 < V_30 ) {
V_25 -> V_33 = ( V_27 - V_25 -> V_32 ) >>
V_34 ;
V_41 += V_35 -> V_9 ;
memcpy ( V_41 , V_40 , V_35 -> V_9 ) ;
V_25 = V_41 ;
V_25 -> V_42 |= V_39 ;
V_25 -> V_32 = V_27 ;
V_25 -> V_33 = ( V_28 - V_27 + 1 ) >>
V_34 ;
V_41 += V_35 -> V_9 ;
memcpy ( V_41 , V_40 , V_35 -> V_9 ) ;
V_25 = V_41 ;
V_25 -> V_32 = V_28 + 1 ;
V_25 -> V_33 = ( V_30 - V_28 ) >>
V_34 ;
}
if ( ( V_29 < V_27 && V_27 < V_30 ) &&
( V_30 <= V_28 ) ) {
V_25 -> V_33 = ( V_27 - V_25 -> V_32 ) >>
V_34 ;
V_41 += V_35 -> V_9 ;
memcpy ( V_41 , V_40 , V_35 -> V_9 ) ;
V_25 = V_41 ;
V_25 -> V_32 = V_27 ;
V_25 -> V_33 = ( V_30 - V_25 -> V_32 + 1 ) >>
V_34 ;
V_25 -> V_42 |= V_39 ;
}
}
}
