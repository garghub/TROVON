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
V_13 = F_9 ( V_3 , V_1 , V_19 ) ;
F_10 ( V_3 , - V_13 , V_18 ) ;
}
F_11 ( & V_3 -> V_11 , V_4 ) ;
if ( ! V_9 )
F_12 () ;
return V_9 ;
}
void F_13 ( struct V_1 * V_1 , unsigned V_18 )
{
struct V_3 * V_3 ;
unsigned long V_4 , V_13 ;
V_3 = F_2 ( V_1 ) ;
F_3 ( & V_3 -> V_11 , V_4 ) ;
if ( F_7 ( V_1 ) != V_19 )
goto V_17;
V_13 = F_9 ( V_3 , V_1 , V_18 ) ;
F_10 ( V_3 , V_13 , V_18 ) ;
F_8 ( V_1 , V_18 ) ;
V_17:
F_11 ( & V_3 -> V_11 , V_4 ) ;
}
static inline struct V_1 *
F_14 ( unsigned long V_5 , unsigned long V_13 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_13 ; V_20 ++ )
if ( F_15 ( V_5 + V_20 ) )
break;
if ( F_16 ( V_20 == V_13 ) )
return NULL ;
return F_17 ( V_5 + V_20 ) ;
}
int F_18 ( unsigned long V_12 , unsigned long V_21 ,
unsigned V_18 , bool V_2 )
{
unsigned long V_5 ;
unsigned long V_22 ;
struct V_1 * V_1 ;
F_19 ( ( V_12 ) & ( V_14 - 1 ) ) ;
F_19 ( ( V_21 ) & ( V_14 - 1 ) ) ;
for ( V_5 = V_12 ;
V_5 < V_21 ;
V_5 += V_14 ) {
V_1 = F_14 ( V_5 , V_14 ) ;
if ( V_1 &&
F_1 ( V_1 , V_2 ) ) {
V_22 = V_5 ;
goto V_23;
}
}
return 0 ;
V_23:
for ( V_5 = V_12 ;
V_5 < V_22 ;
V_5 += V_14 )
F_13 ( F_17 ( V_5 ) , V_18 ) ;
return - V_10 ;
}
int F_20 ( unsigned long V_12 , unsigned long V_21 ,
unsigned V_18 )
{
unsigned long V_5 ;
struct V_1 * V_1 ;
F_19 ( ( V_12 ) & ( V_14 - 1 ) ) ;
F_19 ( ( V_21 ) & ( V_14 - 1 ) ) ;
for ( V_5 = V_12 ;
V_5 < V_21 ;
V_5 += V_14 ) {
V_1 = F_14 ( V_5 , V_14 ) ;
if ( ! V_1 || F_7 ( V_1 ) != V_19 )
continue;
F_13 ( V_1 , V_18 ) ;
}
return 0 ;
}
static int
F_21 ( unsigned long V_5 , unsigned long V_21 ,
bool V_2 )
{
struct V_1 * V_1 ;
while ( V_5 < V_21 ) {
if ( ! F_15 ( V_5 ) ) {
V_5 ++ ;
continue;
}
V_1 = F_17 ( V_5 ) ;
if ( F_22 ( V_1 ) ) {
if ( F_23 ( V_1 ) != V_19 ) {
struct V_1 * V_24 ;
V_24 = V_1 + ( 1 << F_24 ( V_1 ) ) - 1 ;
F_25 ( F_2 ( V_1 ) , V_1 , V_24 ,
V_19 ) ;
}
V_5 += 1 << F_24 ( V_1 ) ;
}
else if ( F_26 ( V_1 ) == 0 &&
F_23 ( V_1 ) == V_19 )
V_5 += 1 ;
else if ( V_2 && F_27 ( V_1 ) ) {
V_5 ++ ;
continue;
}
else
break;
}
if ( V_5 < V_21 )
return 0 ;
return 1 ;
}
int F_28 ( unsigned long V_12 , unsigned long V_21 ,
bool V_2 )
{
unsigned long V_5 , V_4 ;
struct V_1 * V_1 ;
struct V_3 * V_3 ;
int V_9 ;
for ( V_5 = V_12 ; V_5 < V_21 ; V_5 += V_14 ) {
V_1 = F_14 ( V_5 , V_14 ) ;
if ( V_1 && F_7 ( V_1 ) != V_19 )
break;
}
V_1 = F_14 ( V_12 , V_21 - V_12 ) ;
if ( ( V_5 < V_21 ) || ! V_1 )
return - V_10 ;
V_3 = F_2 ( V_1 ) ;
F_3 ( & V_3 -> V_11 , V_4 ) ;
V_9 = F_21 ( V_12 , V_21 ,
V_2 ) ;
F_11 ( & V_3 -> V_11 , V_4 ) ;
return V_9 ? 0 : - V_10 ;
}
struct V_1 * F_29 ( struct V_1 * V_1 , unsigned long V_25 ,
int * * V_26 )
{
T_1 V_27 = V_28 | V_29 ;
if ( F_30 ( V_1 ) )
V_27 |= V_30 ;
return F_31 ( V_27 ) ;
}
