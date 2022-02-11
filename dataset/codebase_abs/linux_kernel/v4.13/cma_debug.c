static int F_1 ( void * V_1 , T_1 * V_2 )
{
unsigned long * V_3 = V_1 ;
* V_2 = * V_3 ;
return 0 ;
}
static int F_2 ( void * V_1 , T_1 * V_2 )
{
struct V_4 * V_4 = V_1 ;
unsigned long V_5 ;
F_3 ( & V_4 -> V_6 ) ;
V_5 = F_4 ( V_4 -> V_7 , ( int ) F_5 ( V_4 ) ) ;
F_6 ( & V_4 -> V_6 ) ;
* V_2 = ( T_1 ) V_5 << V_4 -> V_8 ;
return 0 ;
}
static int F_7 ( void * V_1 , T_1 * V_2 )
{
struct V_4 * V_4 = V_1 ;
unsigned long V_9 = 0 ;
unsigned long V_10 , V_11 = 0 ;
unsigned long V_12 = F_5 ( V_4 ) ;
F_3 ( & V_4 -> V_6 ) ;
for (; ; ) {
V_10 = F_8 ( V_4 -> V_7 , V_12 , V_11 ) ;
if ( V_10 >= V_4 -> V_13 )
break;
V_11 = F_9 ( V_4 -> V_7 , V_12 , V_10 ) ;
V_9 = F_10 ( V_11 - V_10 , V_9 ) ;
}
F_6 ( & V_4 -> V_6 ) ;
* V_2 = ( T_1 ) V_9 << V_4 -> V_8 ;
return 0 ;
}
static void F_11 ( struct V_4 * V_4 , struct V_14 * V_15 )
{
F_12 ( & V_4 -> V_16 ) ;
F_13 ( & V_15 -> V_17 , & V_4 -> V_18 ) ;
F_14 ( & V_4 -> V_16 ) ;
}
static struct V_14 * F_15 ( struct V_4 * V_4 )
{
struct V_14 * V_15 = NULL ;
F_12 ( & V_4 -> V_16 ) ;
if ( ! F_16 ( & V_4 -> V_18 ) ) {
V_15 = F_17 ( V_4 -> V_18 . V_19 , struct V_14 , V_17 ) ;
F_18 ( & V_15 -> V_17 ) ;
}
F_14 ( & V_4 -> V_16 ) ;
return V_15 ;
}
static int F_19 ( struct V_4 * V_4 , int V_13 )
{
struct V_14 * V_15 = NULL ;
while ( V_13 ) {
V_15 = F_15 ( V_4 ) ;
if ( V_15 == NULL )
return 0 ;
if ( V_15 -> V_20 <= V_13 ) {
F_20 ( V_4 , V_15 -> V_3 , V_15 -> V_20 ) ;
V_13 -= V_15 -> V_20 ;
F_21 ( V_15 ) ;
} else if ( V_4 -> V_8 == 0 ) {
F_20 ( V_4 , V_15 -> V_3 , V_13 ) ;
V_15 -> V_3 += V_13 ;
V_15 -> V_20 -= V_13 ;
V_13 = 0 ;
F_11 ( V_4 , V_15 ) ;
} else {
F_22 ( L_1 ) ;
F_11 ( V_4 , V_15 ) ;
break;
}
}
return 0 ;
}
static int F_23 ( void * V_1 , T_1 V_2 )
{
int V_21 = V_2 ;
struct V_4 * V_4 = V_1 ;
return F_19 ( V_4 , V_21 ) ;
}
static int F_24 ( struct V_4 * V_4 , int V_13 )
{
struct V_14 * V_15 ;
struct V_22 * V_3 ;
V_15 = F_25 ( sizeof( * V_15 ) , V_23 ) ;
if ( ! V_15 )
return - V_24 ;
V_3 = F_26 ( V_4 , V_13 , 0 , V_23 ) ;
if ( ! V_3 ) {
F_21 ( V_15 ) ;
return - V_24 ;
}
V_15 -> V_3 = V_3 ;
V_15 -> V_20 = V_13 ;
F_11 ( V_4 , V_15 ) ;
return 0 ;
}
static int F_27 ( void * V_1 , T_1 V_2 )
{
int V_21 = V_2 ;
struct V_4 * V_4 = V_1 ;
return F_24 ( V_4 , V_21 ) ;
}
static void F_28 ( struct V_4 * V_4 , int V_25 )
{
struct V_26 * V_27 ;
char V_28 [ 16 ] ;
int V_29 ;
F_29 ( V_28 , sizeof( V_28 ) , L_2 , V_4 -> V_28 ) ;
V_27 = F_30 ( V_28 , V_30 ) ;
F_31 ( L_3 , V_31 , V_27 , V_4 ,
& V_32 ) ;
F_31 ( L_4 , V_31 , V_27 , V_4 ,
& V_33 ) ;
F_31 ( L_5 , V_34 , V_27 ,
& V_4 -> V_35 , & V_36 ) ;
F_31 ( L_6 , V_34 , V_27 ,
& V_4 -> V_13 , & V_36 ) ;
F_31 ( L_7 , V_34 , V_27 ,
& V_4 -> V_8 , & V_36 ) ;
F_31 ( L_8 , V_34 , V_27 , V_4 , & V_37 ) ;
F_31 ( L_9 , V_34 , V_27 , V_4 , & V_38 ) ;
V_29 = F_32 ( F_5 ( V_4 ) , V_39 * sizeof( V_40 ) ) ;
F_33 ( L_10 , V_34 , V_27 , ( V_40 * ) V_4 -> V_7 , V_29 ) ;
}
static int T_2 F_34 ( void )
{
int V_41 ;
V_30 = F_30 ( L_11 , NULL ) ;
if ( ! V_30 )
return - V_24 ;
for ( V_41 = 0 ; V_41 < V_42 ; V_41 ++ )
F_28 ( & V_43 [ V_41 ] , V_41 ) ;
return 0 ;
}
