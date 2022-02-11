static void * F_1 ( void * V_1 , unsigned long V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_2 = V_2 ;
V_4 -> V_6 = F_3 ( V_4 -> V_2 ) ;
V_4 -> V_7 . V_8 = & V_4 -> V_8 ;
V_4 -> V_7 . V_9 = V_10 ;
V_4 -> V_7 . V_11 = V_4 ;
if ( ! V_4 -> V_6 ) {
F_4 ( L_1 , V_4 -> V_2 ) ;
F_5 ( V_4 ) ;
return NULL ;
}
F_6 ( & V_4 -> V_8 ) ;
return V_4 ;
}
static void V_10 ( void * V_12 )
{
struct V_3 * V_4 = V_12 ;
if ( F_7 ( & V_4 -> V_8 ) ) {
F_8 ( V_4 -> V_6 ) ;
F_5 ( V_4 ) ;
}
}
static void * F_9 ( void * V_1 , unsigned long V_6 ,
unsigned long V_2 , int V_13 )
{
struct V_3 * V_4 ;
unsigned long V_14 , V_15 ;
int V_16 , V_17 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_13 = V_13 ;
V_17 = V_6 & ~ V_18 ;
V_4 -> V_2 = V_2 ;
V_14 = V_6 >> V_19 ;
V_15 = ( V_6 + V_2 - 1 ) >> V_19 ;
V_4 -> V_16 = V_15 - V_14 + 1 ;
V_4 -> V_20 = F_2 ( V_4 -> V_16 * sizeof( struct V_21 * ) , V_5 ) ;
if ( ! V_4 -> V_20 )
goto V_22;
V_16 = F_10 ( V_23 , V_23 -> V_24 , V_6 & V_18 ,
V_4 -> V_16 , V_13 , 1 ,
V_4 -> V_20 , NULL ) ;
if ( V_16 != V_4 -> V_16 )
goto V_25;
V_4 -> V_6 = F_11 ( V_4 -> V_20 , V_4 -> V_16 , - 1 , V_26 ) ;
if ( ! V_4 -> V_6 )
goto V_25;
V_4 -> V_6 += V_17 ;
return V_4 ;
V_25:
F_4 ( L_2 , V_16 ,
V_4 -> V_16 ) ;
while ( -- V_16 >= 0 )
F_12 ( V_4 -> V_20 [ V_16 ] ) ;
F_5 ( V_4 -> V_20 ) ;
V_22:
F_5 ( V_4 ) ;
return NULL ;
}
static void F_13 ( void * V_12 )
{
struct V_3 * V_4 = V_12 ;
unsigned long V_6 = ( unsigned long ) V_4 -> V_6 & V_18 ;
unsigned int V_27 ;
if ( V_6 )
F_14 ( ( void * ) V_6 , V_4 -> V_16 ) ;
for ( V_27 = 0 ; V_27 < V_4 -> V_16 ; ++ V_27 ) {
if ( V_4 -> V_13 )
F_15 ( V_4 -> V_20 [ V_27 ] ) ;
F_12 ( V_4 -> V_20 [ V_27 ] ) ;
}
F_5 ( V_4 -> V_20 ) ;
F_5 ( V_4 ) ;
}
static void * F_16 ( void * V_12 )
{
struct V_3 * V_4 = V_12 ;
if ( ! V_4 -> V_6 ) {
F_17 ( L_3
L_4 ) ;
return NULL ;
}
return V_4 -> V_6 ;
}
static unsigned int F_18 ( void * V_12 )
{
struct V_3 * V_4 = V_12 ;
return F_19 ( & V_4 -> V_8 ) ;
}
static int F_20 ( void * V_12 , struct V_28 * V_29 )
{
struct V_3 * V_4 = V_12 ;
int V_30 ;
if ( ! V_4 ) {
F_17 ( L_5 ) ;
return - V_31 ;
}
V_30 = F_21 ( V_29 , V_4 -> V_6 , 0 ) ;
if ( V_30 ) {
F_17 ( L_6 , V_30 ) ;
return V_30 ;
}
V_29 -> V_32 |= V_33 ;
V_29 -> V_34 = & V_4 -> V_7 ;
V_29 -> V_35 = & V_36 ;
V_29 -> V_35 -> V_37 ( V_29 ) ;
return 0 ;
}
