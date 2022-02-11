static void * F_1 ( void * V_1 , unsigned long V_2 , T_1 V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( sizeof( * V_5 ) , V_6 | V_3 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_2 = V_2 ;
V_5 -> V_7 = F_3 ( V_5 -> V_2 ) ;
V_5 -> V_8 . V_9 = & V_5 -> V_9 ;
V_5 -> V_8 . V_10 = V_11 ;
V_5 -> V_8 . V_12 = V_5 ;
if ( ! V_5 -> V_7 ) {
F_4 ( L_1 , V_5 -> V_2 ) ;
F_5 ( V_5 ) ;
return NULL ;
}
F_6 ( & V_5 -> V_9 ) ;
return V_5 ;
}
static void V_11 ( void * V_13 )
{
struct V_4 * V_5 = V_13 ;
if ( F_7 ( & V_5 -> V_9 ) ) {
F_8 ( V_5 -> V_7 ) ;
F_5 ( V_5 ) ;
}
}
static void * F_9 ( void * V_1 , unsigned long V_7 ,
unsigned long V_2 , int V_14 )
{
struct V_4 * V_5 ;
unsigned long V_15 , V_16 ;
int V_17 , V_18 ;
struct V_19 * V_20 ;
T_2 V_21 ;
V_5 = F_2 ( sizeof( * V_5 ) , V_6 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_14 = V_14 ;
V_18 = V_7 & ~ V_22 ;
V_5 -> V_2 = V_2 ;
V_20 = F_10 ( V_23 -> V_24 , V_7 ) ;
if ( V_20 && ( V_20 -> V_25 & V_26 ) && ( V_20 -> V_27 ) ) {
if ( F_11 ( V_7 , V_2 , & V_20 , & V_21 ) )
goto V_28;
V_5 -> V_20 = V_20 ;
V_5 -> V_7 = F_12 ( V_21 , V_2 ) ;
if ( ! V_5 -> V_7 )
goto V_28;
} else {
V_15 = V_7 >> V_29 ;
V_16 = ( V_7 + V_2 - 1 ) >> V_29 ;
V_5 -> V_17 = V_16 - V_15 + 1 ;
V_5 -> V_30 = F_2 ( V_5 -> V_17 * sizeof( struct V_31 * ) ,
V_6 ) ;
if ( ! V_5 -> V_30 )
goto V_28;
V_17 = F_13 ( V_23 , V_23 -> V_24 ,
V_7 & V_22 , V_5 -> V_17 ,
V_14 , 1 ,
V_5 -> V_30 , NULL ) ;
if ( V_17 != V_5 -> V_17 )
goto V_32;
V_5 -> V_7 = F_14 ( V_5 -> V_30 , V_5 -> V_17 , - 1 ,
V_33 ) ;
if ( ! V_5 -> V_7 )
goto V_32;
}
V_5 -> V_7 += V_18 ;
return V_5 ;
V_32:
F_4 ( L_2 , V_17 ,
V_5 -> V_17 ) ;
while ( -- V_17 >= 0 )
F_15 ( V_5 -> V_30 [ V_17 ] ) ;
F_5 ( V_5 -> V_30 ) ;
V_28:
F_5 ( V_5 ) ;
return NULL ;
}
static void F_16 ( void * V_13 )
{
struct V_4 * V_5 = V_13 ;
unsigned long V_7 = ( unsigned long ) V_5 -> V_7 & V_22 ;
unsigned int V_34 ;
if ( V_5 -> V_30 ) {
if ( V_7 )
F_17 ( ( void * ) V_7 , V_5 -> V_17 ) ;
for ( V_34 = 0 ; V_34 < V_5 -> V_17 ; ++ V_34 ) {
if ( V_5 -> V_14 )
F_18 ( V_5 -> V_30 [ V_34 ] ) ;
F_15 ( V_5 -> V_30 [ V_34 ] ) ;
}
F_5 ( V_5 -> V_30 ) ;
} else {
if ( V_5 -> V_20 )
F_19 ( V_5 -> V_20 ) ;
F_20 ( V_5 -> V_7 ) ;
}
F_5 ( V_5 ) ;
}
static void * F_21 ( void * V_13 )
{
struct V_4 * V_5 = V_13 ;
if ( ! V_5 -> V_7 ) {
F_22 ( L_3
L_4 ) ;
return NULL ;
}
return V_5 -> V_7 ;
}
static unsigned int F_23 ( void * V_13 )
{
struct V_4 * V_5 = V_13 ;
return F_24 ( & V_5 -> V_9 ) ;
}
static int F_25 ( void * V_13 , struct V_19 * V_20 )
{
struct V_4 * V_5 = V_13 ;
int V_35 ;
if ( ! V_5 ) {
F_22 ( L_5 ) ;
return - V_36 ;
}
V_35 = F_26 ( V_20 , V_5 -> V_7 , 0 ) ;
if ( V_35 ) {
F_22 ( L_6 , V_35 ) ;
return V_35 ;
}
V_20 -> V_25 |= V_37 ;
V_20 -> V_38 = & V_5 -> V_8 ;
V_20 -> V_39 = & V_40 ;
V_20 -> V_39 -> V_41 ( V_20 ) ;
return 0 ;
}
static int F_27 ( void * V_42 )
{
struct V_4 * V_5 = V_42 ;
V_5 -> V_7 = F_28 ( V_5 -> V_43 ) ;
return V_5 -> V_7 ? 0 : - V_44 ;
}
static void F_29 ( void * V_42 )
{
struct V_4 * V_5 = V_42 ;
F_30 ( V_5 -> V_43 , V_5 -> V_7 ) ;
V_5 -> V_7 = NULL ;
}
static void F_31 ( void * V_42 )
{
struct V_4 * V_5 = V_42 ;
if ( V_5 -> V_7 )
F_30 ( V_5 -> V_43 , V_5 -> V_7 ) ;
F_5 ( V_5 ) ;
}
static void * F_32 ( void * V_1 , struct V_45 * V_43 ,
unsigned long V_2 , int V_14 )
{
struct V_4 * V_5 ;
if ( V_43 -> V_2 < V_2 )
return F_33 ( - V_44 ) ;
V_5 = F_2 ( sizeof( * V_5 ) , V_6 ) ;
if ( ! V_5 )
return F_33 ( - V_46 ) ;
V_5 -> V_43 = V_43 ;
V_5 -> V_14 = V_14 ;
V_5 -> V_2 = V_2 ;
return V_5 ;
}
