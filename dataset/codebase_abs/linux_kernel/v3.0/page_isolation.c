static inline struct V_1 *
F_1 ( unsigned long V_2 , unsigned long V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
if ( F_2 ( V_2 + V_4 ) )
break;
if ( F_3 ( V_4 == V_3 ) )
return NULL ;
return F_4 ( V_2 + V_4 ) ;
}
int
F_5 ( unsigned long V_5 , unsigned long V_6 )
{
unsigned long V_2 ;
unsigned long V_7 ;
struct V_1 * V_1 ;
F_6 ( ( V_5 ) & ( V_8 - 1 ) ) ;
F_6 ( ( V_6 ) & ( V_8 - 1 ) ) ;
for ( V_2 = V_5 ;
V_2 < V_6 ;
V_2 += V_8 ) {
V_1 = F_1 ( V_2 , V_8 ) ;
if ( V_1 && F_7 ( V_1 ) ) {
V_7 = V_2 ;
goto V_9;
}
}
return 0 ;
V_9:
for ( V_2 = V_5 ;
V_2 < V_7 ;
V_2 += V_8 )
F_8 ( F_4 ( V_2 ) ) ;
return - V_10 ;
}
int
F_9 ( unsigned long V_5 , unsigned long V_6 )
{
unsigned long V_2 ;
struct V_1 * V_1 ;
F_6 ( ( V_5 ) & ( V_8 - 1 ) ) ;
F_6 ( ( V_6 ) & ( V_8 - 1 ) ) ;
for ( V_2 = V_5 ;
V_2 < V_6 ;
V_2 += V_8 ) {
V_1 = F_1 ( V_2 , V_8 ) ;
if ( ! V_1 || F_10 ( V_1 ) != V_11 )
continue;
F_8 ( V_1 ) ;
}
return 0 ;
}
static int
F_11 ( unsigned long V_2 , unsigned long V_6 )
{
struct V_1 * V_1 ;
while ( V_2 < V_6 ) {
if ( ! F_2 ( V_2 ) ) {
V_2 ++ ;
continue;
}
V_1 = F_4 ( V_2 ) ;
if ( F_12 ( V_1 ) )
V_2 += 1 << F_13 ( V_1 ) ;
else if ( F_14 ( V_1 ) == 0 &&
F_15 ( V_1 ) == V_11 )
V_2 += 1 ;
else
break;
}
if ( V_2 < V_6 )
return 0 ;
return 1 ;
}
int F_16 ( unsigned long V_5 , unsigned long V_6 )
{
unsigned long V_2 , V_12 ;
struct V_1 * V_1 ;
struct V_13 * V_13 ;
int V_14 ;
for ( V_2 = V_5 ; V_2 < V_6 ; V_2 += V_8 ) {
V_1 = F_1 ( V_2 , V_8 ) ;
if ( V_1 && F_10 ( V_1 ) != V_11 )
break;
}
V_1 = F_1 ( V_5 , V_6 - V_5 ) ;
if ( ( V_2 < V_6 ) || ! V_1 )
return - V_10 ;
V_13 = F_17 ( V_1 ) ;
F_18 ( & V_13 -> V_15 , V_12 ) ;
V_14 = F_11 ( V_5 , V_6 ) ;
F_19 ( & V_13 -> V_15 , V_12 ) ;
return V_14 ? 0 : - V_10 ;
}
