static int F_1 ( struct V_1 * V_1 ,
bool V_2 )
{
struct V_3 * V_3 ;
unsigned long V_4 , V_5 ;
struct V_6 V_7 ;
int V_8 ;
int V_9 = - V_10 ;
V_3 = F_2 ( V_1 ) ;
F_3 ( & V_3 -> V_11 , V_4 ) ;
V_5 = F_4 ( V_1 ) ;
V_7 . V_12 = V_5 ;
V_7 . V_13 = V_14 ;
V_7 . V_15 = 0 ;
V_8 = V_6 ( V_16 , & V_7 ) ;
V_8 = F_5 ( V_8 ) ;
if ( V_8 )
goto V_17;
if ( ! F_6 ( V_3 , V_1 , V_7 . V_15 ,
V_2 ) )
V_9 = 0 ;
V_17:
if ( ! V_9 ) {
unsigned long V_13 ;
int V_18 = F_7 ( V_1 ) ;
F_8 ( V_1 , V_19 ) ;
V_3 -> V_20 ++ ;
V_13 = F_9 ( V_3 , V_1 , V_19 ,
NULL ) ;
F_10 ( V_3 , - V_13 , V_18 ) ;
}
F_11 ( & V_3 -> V_11 , V_4 ) ;
if ( ! V_9 )
F_12 ( V_3 ) ;
return V_9 ;
}
static void F_13 ( struct V_1 * V_1 , unsigned V_18 )
{
struct V_3 * V_3 ;
unsigned long V_4 , V_13 ;
bool V_21 = false ;
unsigned int V_22 ;
unsigned long V_5 , V_23 ;
struct V_1 * V_24 ;
V_3 = F_2 ( V_1 ) ;
F_3 ( & V_3 -> V_11 , V_4 ) ;
if ( ! F_14 ( V_1 ) )
goto V_17;
if ( F_15 ( V_1 ) ) {
V_22 = F_16 ( V_1 ) ;
if ( V_22 >= V_25 ) {
V_5 = F_4 ( V_1 ) ;
V_23 = F_17 ( V_5 , V_22 ) ;
V_24 = V_1 + ( V_23 - V_5 ) ;
if ( F_18 ( V_23 ) &&
! F_14 ( V_24 ) ) {
F_19 ( V_1 , V_22 ) ;
V_21 = true ;
}
}
}
if ( ! V_21 ) {
V_13 = F_9 ( V_3 , V_1 , V_18 , NULL ) ;
F_10 ( V_3 , V_13 , V_18 ) ;
}
F_8 ( V_1 , V_18 ) ;
V_3 -> V_20 -- ;
V_17:
F_11 ( & V_3 -> V_11 , V_4 ) ;
if ( V_21 ) {
F_20 ( V_1 , V_22 , V_26 ) ;
F_21 ( V_1 , V_22 ) ;
}
}
static inline struct V_1 *
F_22 ( unsigned long V_5 , unsigned long V_13 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_13 ; V_27 ++ )
if ( F_18 ( V_5 + V_27 ) )
break;
if ( F_23 ( V_27 == V_13 ) )
return NULL ;
return F_24 ( V_5 + V_27 ) ;
}
int F_25 ( unsigned long V_12 , unsigned long V_28 ,
unsigned V_18 , bool V_2 )
{
unsigned long V_5 ;
unsigned long V_29 ;
struct V_1 * V_1 ;
F_26 ( ! F_27 ( V_12 , V_14 ) ) ;
F_26 ( ! F_27 ( V_28 , V_14 ) ) ;
for ( V_5 = V_12 ;
V_5 < V_28 ;
V_5 += V_14 ) {
V_1 = F_22 ( V_5 , V_14 ) ;
if ( V_1 &&
F_1 ( V_1 , V_2 ) ) {
V_29 = V_5 ;
goto V_30;
}
}
return 0 ;
V_30:
for ( V_5 = V_12 ;
V_5 < V_29 ;
V_5 += V_14 )
F_13 ( F_24 ( V_5 ) , V_18 ) ;
return - V_10 ;
}
int F_28 ( unsigned long V_12 , unsigned long V_28 ,
unsigned V_18 )
{
unsigned long V_5 ;
struct V_1 * V_1 ;
F_26 ( ! F_27 ( V_12 , V_14 ) ) ;
F_26 ( ! F_27 ( V_28 , V_14 ) ) ;
for ( V_5 = V_12 ;
V_5 < V_28 ;
V_5 += V_14 ) {
V_1 = F_22 ( V_5 , V_14 ) ;
if ( ! V_1 || ! F_14 ( V_1 ) )
continue;
F_13 ( V_1 , V_18 ) ;
}
return 0 ;
}
static unsigned long
F_29 ( unsigned long V_5 , unsigned long V_28 ,
bool V_2 )
{
struct V_1 * V_1 ;
while ( V_5 < V_28 ) {
if ( ! F_18 ( V_5 ) ) {
V_5 ++ ;
continue;
}
V_1 = F_24 ( V_5 ) ;
if ( F_15 ( V_1 ) )
V_5 += 1 << F_16 ( V_1 ) ;
else if ( V_2 && F_30 ( V_1 ) )
V_5 ++ ;
else
break;
}
return V_5 ;
}
int F_31 ( unsigned long V_12 , unsigned long V_28 ,
bool V_2 )
{
unsigned long V_5 , V_4 ;
struct V_1 * V_1 ;
struct V_3 * V_3 ;
for ( V_5 = V_12 ; V_5 < V_28 ; V_5 += V_14 ) {
V_1 = F_22 ( V_5 , V_14 ) ;
if ( V_1 && ! F_14 ( V_1 ) )
break;
}
V_1 = F_22 ( V_12 , V_28 - V_12 ) ;
if ( ( V_5 < V_28 ) || ! V_1 )
return - V_10 ;
V_3 = F_2 ( V_1 ) ;
F_3 ( & V_3 -> V_11 , V_4 ) ;
V_5 = F_29 ( V_12 , V_28 ,
V_2 ) ;
F_11 ( & V_3 -> V_11 , V_4 ) ;
F_32 ( V_12 , V_28 , V_5 ) ;
return V_5 < V_28 ? - V_10 : 0 ;
}
struct V_1 * F_33 ( struct V_1 * V_1 , unsigned long V_31 ,
int * * V_32 )
{
T_1 V_33 = V_34 | V_26 ;
if ( F_34 ( V_1 ) )
return F_35 ( F_36 ( F_37 ( V_1 ) ) ,
F_38 ( F_39 ( V_1 ) ,
V_35 ) ) ;
if ( F_40 ( V_1 ) )
V_33 |= V_36 ;
return F_41 ( V_33 ) ;
}
