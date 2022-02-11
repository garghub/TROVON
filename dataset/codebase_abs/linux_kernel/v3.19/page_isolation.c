int F_1 ( struct V_1 * V_1 , bool V_2 )
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
V_13 = F_9 ( V_3 , V_1 , V_19 ) ;
F_10 ( V_3 , - V_13 , V_18 ) ;
}
F_11 ( & V_3 -> V_11 , V_4 ) ;
if ( ! V_9 )
F_12 ( V_3 ) ;
return V_9 ;
}
void F_13 ( struct V_1 * V_1 , unsigned V_18 )
{
struct V_3 * V_3 ;
unsigned long V_4 , V_13 ;
struct V_1 * V_21 = NULL ;
unsigned int V_22 ;
unsigned long V_23 , V_24 ;
struct V_1 * V_25 ;
V_3 = F_2 ( V_1 ) ;
F_3 ( & V_3 -> V_11 , V_4 ) ;
if ( F_7 ( V_1 ) != V_19 )
goto V_17;
if ( F_14 ( V_1 ) ) {
V_22 = F_15 ( V_1 ) ;
if ( V_22 >= V_26 ) {
V_23 = F_4 ( V_1 ) & ( ( 1 << V_27 ) - 1 ) ;
V_24 = F_16 ( V_23 , V_22 ) ;
V_25 = V_1 + ( V_24 - V_23 ) ;
if ( ! F_17 ( V_25 ) ) {
F_18 ( V_1 , V_22 ) ;
F_19 ( V_1 ) ;
V_21 = V_1 ;
}
}
}
if ( ! V_21 ) {
V_13 = F_9 ( V_3 , V_1 , V_18 ) ;
F_10 ( V_3 , V_13 , V_18 ) ;
}
F_8 ( V_1 , V_18 ) ;
V_3 -> V_20 -- ;
V_17:
F_11 ( & V_3 -> V_11 , V_4 ) ;
if ( V_21 )
F_20 ( V_21 , V_22 ) ;
}
static inline struct V_1 *
F_21 ( unsigned long V_5 , unsigned long V_13 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_13 ; V_28 ++ )
if ( F_22 ( V_5 + V_28 ) )
break;
if ( F_23 ( V_28 == V_13 ) )
return NULL ;
return F_24 ( V_5 + V_28 ) ;
}
int F_25 ( unsigned long V_12 , unsigned long V_29 ,
unsigned V_18 , bool V_2 )
{
unsigned long V_5 ;
unsigned long V_30 ;
struct V_1 * V_1 ;
F_26 ( ( V_12 ) & ( V_14 - 1 ) ) ;
F_26 ( ( V_29 ) & ( V_14 - 1 ) ) ;
for ( V_5 = V_12 ;
V_5 < V_29 ;
V_5 += V_14 ) {
V_1 = F_21 ( V_5 , V_14 ) ;
if ( V_1 &&
F_1 ( V_1 , V_2 ) ) {
V_30 = V_5 ;
goto V_31;
}
}
return 0 ;
V_31:
for ( V_5 = V_12 ;
V_5 < V_30 ;
V_5 += V_14 )
F_13 ( F_24 ( V_5 ) , V_18 ) ;
return - V_10 ;
}
int F_27 ( unsigned long V_12 , unsigned long V_29 ,
unsigned V_18 )
{
unsigned long V_5 ;
struct V_1 * V_1 ;
F_26 ( ( V_12 ) & ( V_14 - 1 ) ) ;
F_26 ( ( V_29 ) & ( V_14 - 1 ) ) ;
for ( V_5 = V_12 ;
V_5 < V_29 ;
V_5 += V_14 ) {
V_1 = F_21 ( V_5 , V_14 ) ;
if ( ! V_1 || F_7 ( V_1 ) != V_19 )
continue;
F_13 ( V_1 , V_18 ) ;
}
return 0 ;
}
static int
F_28 ( unsigned long V_5 , unsigned long V_29 ,
bool V_2 )
{
struct V_1 * V_1 ;
while ( V_5 < V_29 ) {
if ( ! F_22 ( V_5 ) ) {
V_5 ++ ;
continue;
}
V_1 = F_24 ( V_5 ) ;
if ( F_14 ( V_1 ) ) {
if ( F_29 ( V_1 ) != V_19 ) {
struct V_1 * V_32 ;
V_32 = V_1 + ( 1 << F_15 ( V_1 ) ) - 1 ;
F_30 ( F_2 ( V_1 ) , V_1 , V_32 ,
V_19 ) ;
}
V_5 += 1 << F_15 ( V_1 ) ;
}
else if ( F_31 ( V_1 ) == 0 &&
F_29 ( V_1 ) == V_19 )
V_5 += 1 ;
else if ( V_2 && F_32 ( V_1 ) ) {
V_5 ++ ;
continue;
}
else
break;
}
if ( V_5 < V_29 )
return 0 ;
return 1 ;
}
int F_33 ( unsigned long V_12 , unsigned long V_29 ,
bool V_2 )
{
unsigned long V_5 , V_4 ;
struct V_1 * V_1 ;
struct V_3 * V_3 ;
int V_9 ;
for ( V_5 = V_12 ; V_5 < V_29 ; V_5 += V_14 ) {
V_1 = F_21 ( V_5 , V_14 ) ;
if ( V_1 && F_7 ( V_1 ) != V_19 )
break;
}
V_1 = F_21 ( V_12 , V_29 - V_12 ) ;
if ( ( V_5 < V_29 ) || ! V_1 )
return - V_10 ;
V_3 = F_2 ( V_1 ) ;
F_3 ( & V_3 -> V_11 , V_4 ) ;
V_9 = F_28 ( V_12 , V_29 ,
V_2 ) ;
F_11 ( & V_3 -> V_11 , V_4 ) ;
return V_9 ? 0 : - V_10 ;
}
struct V_1 * F_34 ( struct V_1 * V_1 , unsigned long V_33 ,
int * * V_34 )
{
T_1 V_35 = V_36 | V_37 ;
if ( F_35 ( V_1 ) ) {
T_2 V_38 = F_36 ( F_37 ( V_1 ) ) ;
T_2 V_39 ;
F_38 ( V_39 , V_38 ) ;
return F_39 ( F_40 ( F_41 ( V_1 ) ) ,
F_42 ( F_37 ( V_1 ) , V_39 ) ) ;
}
if ( F_43 ( V_1 ) )
V_35 |= V_40 ;
return F_44 ( V_35 ) ;
}
