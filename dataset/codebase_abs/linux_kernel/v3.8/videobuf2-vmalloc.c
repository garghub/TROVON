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
struct V_18 * V_19 ;
T_1 V_20 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_13 = V_13 ;
V_17 = V_6 & ~ V_21 ;
V_4 -> V_2 = V_2 ;
V_19 = F_10 ( V_22 -> V_23 , V_6 ) ;
if ( V_19 && ( V_19 -> V_24 & V_25 ) && ( V_19 -> V_26 ) ) {
if ( F_11 ( V_6 , V_2 , & V_19 , & V_20 ) )
goto V_27;
V_4 -> V_19 = V_19 ;
V_4 -> V_6 = F_12 ( V_20 , V_2 ) ;
if ( ! V_4 -> V_6 )
goto V_27;
} else {
V_14 = V_6 >> V_28 ;
V_15 = ( V_6 + V_2 - 1 ) >> V_28 ;
V_4 -> V_16 = V_15 - V_14 + 1 ;
V_4 -> V_29 = F_2 ( V_4 -> V_16 * sizeof( struct V_30 * ) ,
V_5 ) ;
if ( ! V_4 -> V_29 )
goto V_27;
V_16 = F_13 ( V_22 , V_22 -> V_23 ,
V_6 & V_21 , V_4 -> V_16 ,
V_13 , 1 ,
V_4 -> V_29 , NULL ) ;
if ( V_16 != V_4 -> V_16 )
goto V_31;
V_4 -> V_6 = F_14 ( V_4 -> V_29 , V_4 -> V_16 , - 1 ,
V_32 ) ;
if ( ! V_4 -> V_6 )
goto V_31;
}
V_4 -> V_6 += V_17 ;
return V_4 ;
V_31:
F_4 ( L_2 , V_16 ,
V_4 -> V_16 ) ;
while ( -- V_16 >= 0 )
F_15 ( V_4 -> V_29 [ V_16 ] ) ;
F_5 ( V_4 -> V_29 ) ;
V_27:
F_5 ( V_4 ) ;
return NULL ;
}
static void F_16 ( void * V_12 )
{
struct V_3 * V_4 = V_12 ;
unsigned long V_6 = ( unsigned long ) V_4 -> V_6 & V_21 ;
unsigned int V_33 ;
if ( V_4 -> V_29 ) {
if ( V_6 )
F_17 ( ( void * ) V_6 , V_4 -> V_16 ) ;
for ( V_33 = 0 ; V_33 < V_4 -> V_16 ; ++ V_33 ) {
if ( V_4 -> V_13 )
F_18 ( V_4 -> V_29 [ V_33 ] ) ;
F_15 ( V_4 -> V_29 [ V_33 ] ) ;
}
F_5 ( V_4 -> V_29 ) ;
} else {
if ( V_4 -> V_19 )
F_19 ( V_4 -> V_19 ) ;
F_20 ( V_4 -> V_6 ) ;
}
F_5 ( V_4 ) ;
}
static void * F_21 ( void * V_12 )
{
struct V_3 * V_4 = V_12 ;
if ( ! V_4 -> V_6 ) {
F_22 ( L_3
L_4 ) ;
return NULL ;
}
return V_4 -> V_6 ;
}
static unsigned int F_23 ( void * V_12 )
{
struct V_3 * V_4 = V_12 ;
return F_24 ( & V_4 -> V_8 ) ;
}
static int F_25 ( void * V_12 , struct V_18 * V_19 )
{
struct V_3 * V_4 = V_12 ;
int V_34 ;
if ( ! V_4 ) {
F_22 ( L_5 ) ;
return - V_35 ;
}
V_34 = F_26 ( V_19 , V_4 -> V_6 , 0 ) ;
if ( V_34 ) {
F_22 ( L_6 , V_34 ) ;
return V_34 ;
}
V_19 -> V_24 |= V_36 ;
V_19 -> V_37 = & V_4 -> V_7 ;
V_19 -> V_38 = & V_39 ;
V_19 -> V_38 -> V_40 ( V_19 ) ;
return 0 ;
}
static int F_27 ( void * V_41 )
{
struct V_3 * V_4 = V_41 ;
V_4 -> V_6 = F_28 ( V_4 -> V_42 ) ;
return V_4 -> V_6 ? 0 : - V_43 ;
}
static void F_29 ( void * V_41 )
{
struct V_3 * V_4 = V_41 ;
F_30 ( V_4 -> V_42 , V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
}
static void F_31 ( void * V_41 )
{
struct V_3 * V_4 = V_41 ;
if ( V_4 -> V_6 )
F_30 ( V_4 -> V_42 , V_4 -> V_6 ) ;
F_5 ( V_4 ) ;
}
static void * F_32 ( void * V_1 , struct V_44 * V_42 ,
unsigned long V_2 , int V_13 )
{
struct V_3 * V_4 ;
if ( V_42 -> V_2 < V_2 )
return F_33 ( - V_43 ) ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return F_33 ( - V_45 ) ;
V_4 -> V_42 = V_42 ;
V_4 -> V_13 = V_13 ;
V_4 -> V_2 = V_2 ;
return V_4 ;
}
