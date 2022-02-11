static void F_1 ( struct V_1 * V_1 )
{
if ( F_2 ( V_1 ) == V_2 )
return;
F_3 ( V_1 , V_2 ) ;
F_4 ( V_1 ) -> V_3 ++ ;
}
static void F_5 ( struct V_1 * V_1 , int V_4 )
{
struct V_5 * V_5 = F_4 ( V_1 ) ;
if ( F_6 ( F_2 ( V_1 ) != V_2 ) )
return;
F_7 ( V_5 -> V_3 <= 0 ) ;
F_3 ( V_1 , V_4 ) ;
V_5 -> V_3 -- ;
}
int F_8 ( struct V_1 * V_1 )
{
struct V_5 * V_5 ;
unsigned long V_6 , V_7 ;
struct V_8 V_9 ;
int V_10 ;
int V_11 = - V_12 ;
V_5 = F_4 ( V_1 ) ;
F_9 ( & V_5 -> V_13 , V_6 ) ;
V_7 = F_10 ( V_1 ) ;
V_9 . V_14 = V_7 ;
V_9 . V_15 = V_16 ;
V_9 . V_17 = 0 ;
V_10 = V_8 ( V_18 , & V_9 ) ;
V_10 = F_11 ( V_10 ) ;
if ( V_10 )
goto V_19;
if ( ! F_12 ( V_5 , V_1 , V_9 . V_17 ) )
V_11 = 0 ;
V_19:
if ( ! V_11 ) {
unsigned long V_15 ;
int V_4 = F_2 ( V_1 ) ;
F_1 ( V_1 ) ;
V_15 = F_13 ( V_5 , V_1 , V_2 ) ;
F_14 ( V_5 , - V_15 , V_4 ) ;
}
F_15 ( & V_5 -> V_13 , V_6 ) ;
if ( ! V_11 )
F_16 () ;
return V_11 ;
}
void F_17 ( struct V_1 * V_1 , unsigned V_4 )
{
struct V_5 * V_5 ;
unsigned long V_6 , V_15 ;
V_5 = F_4 ( V_1 ) ;
F_9 ( & V_5 -> V_13 , V_6 ) ;
if ( F_2 ( V_1 ) != V_2 )
goto V_19;
V_15 = F_13 ( V_5 , V_1 , V_4 ) ;
F_14 ( V_5 , V_15 , V_4 ) ;
F_5 ( V_1 , V_4 ) ;
V_19:
F_15 ( & V_5 -> V_13 , V_6 ) ;
}
static inline struct V_1 *
F_18 ( unsigned long V_7 , unsigned long V_15 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_15 ; V_20 ++ )
if ( F_19 ( V_7 + V_20 ) )
break;
if ( F_20 ( V_20 == V_15 ) )
return NULL ;
return F_21 ( V_7 + V_20 ) ;
}
int F_22 ( unsigned long V_14 , unsigned long V_21 ,
unsigned V_4 )
{
unsigned long V_7 ;
unsigned long V_22 ;
struct V_1 * V_1 ;
F_7 ( ( V_14 ) & ( V_16 - 1 ) ) ;
F_7 ( ( V_21 ) & ( V_16 - 1 ) ) ;
for ( V_7 = V_14 ;
V_7 < V_21 ;
V_7 += V_16 ) {
V_1 = F_18 ( V_7 , V_16 ) ;
if ( V_1 && F_8 ( V_1 ) ) {
V_22 = V_7 ;
goto V_23;
}
}
return 0 ;
V_23:
for ( V_7 = V_14 ;
V_7 < V_22 ;
V_7 += V_16 )
F_17 ( F_21 ( V_7 ) , V_4 ) ;
return - V_12 ;
}
int F_23 ( unsigned long V_14 , unsigned long V_21 ,
unsigned V_4 )
{
unsigned long V_7 ;
struct V_1 * V_1 ;
F_7 ( ( V_14 ) & ( V_16 - 1 ) ) ;
F_7 ( ( V_21 ) & ( V_16 - 1 ) ) ;
for ( V_7 = V_14 ;
V_7 < V_21 ;
V_7 += V_16 ) {
V_1 = F_18 ( V_7 , V_16 ) ;
if ( ! V_1 || F_2 ( V_1 ) != V_2 )
continue;
F_17 ( V_1 , V_4 ) ;
}
return 0 ;
}
static int
F_24 ( unsigned long V_7 , unsigned long V_21 )
{
struct V_1 * V_1 ;
while ( V_7 < V_21 ) {
if ( ! F_19 ( V_7 ) ) {
V_7 ++ ;
continue;
}
V_1 = F_21 ( V_7 ) ;
if ( F_25 ( V_1 ) ) {
if ( F_26 ( V_1 ) != V_2 ) {
struct V_1 * V_24 ;
V_24 = V_1 + ( 1 << F_27 ( V_1 ) ) - 1 ;
F_28 ( F_4 ( V_1 ) , V_1 , V_24 ,
V_2 ) ;
}
V_7 += 1 << F_27 ( V_1 ) ;
}
else if ( F_29 ( V_1 ) == 0 &&
F_26 ( V_1 ) == V_2 )
V_7 += 1 ;
else
break;
}
if ( V_7 < V_21 )
return 0 ;
return 1 ;
}
int F_30 ( unsigned long V_14 , unsigned long V_21 )
{
unsigned long V_7 , V_6 ;
struct V_1 * V_1 ;
struct V_5 * V_5 ;
int V_11 ;
for ( V_7 = V_14 ; V_7 < V_21 ; V_7 += V_16 ) {
V_1 = F_18 ( V_7 , V_16 ) ;
if ( V_1 && F_2 ( V_1 ) != V_2 )
break;
}
V_1 = F_18 ( V_14 , V_21 - V_14 ) ;
if ( ( V_7 < V_21 ) || ! V_1 )
return - V_12 ;
V_5 = F_4 ( V_1 ) ;
F_9 ( & V_5 -> V_13 , V_6 ) ;
V_11 = F_24 ( V_14 , V_21 ) ;
F_15 ( & V_5 -> V_13 , V_6 ) ;
return V_11 ? 0 : - V_12 ;
}
struct V_1 * F_31 ( struct V_1 * V_1 , unsigned long V_25 ,
int * * V_26 )
{
T_1 V_27 = V_28 | V_29 ;
if ( F_32 ( V_1 ) )
V_27 |= V_30 ;
return F_33 ( V_27 ) ;
}
