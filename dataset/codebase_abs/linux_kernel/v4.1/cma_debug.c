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
V_5 = F_4 ( V_4 -> V_7 , ( int ) V_4 -> V_8 ) ;
F_5 ( & V_4 -> V_6 ) ;
* V_2 = ( T_1 ) V_5 << V_4 -> V_9 ;
return 0 ;
}
static int F_6 ( void * V_1 , T_1 * V_2 )
{
struct V_4 * V_4 = V_1 ;
unsigned long V_10 = 0 ;
unsigned long V_11 , V_12 = 0 ;
F_3 ( & V_4 -> V_6 ) ;
for (; ; ) {
V_11 = F_7 ( V_4 -> V_7 , V_4 -> V_8 , V_12 ) ;
if ( V_11 >= V_4 -> V_8 )
break;
V_12 = F_8 ( V_4 -> V_7 , V_4 -> V_8 , V_11 ) ;
V_10 = F_9 ( V_12 - V_11 , V_10 ) ;
}
F_5 ( & V_4 -> V_6 ) ;
* V_2 = ( T_1 ) V_10 << V_4 -> V_9 ;
return 0 ;
}
static void F_10 ( struct V_4 * V_4 , struct V_13 * V_14 )
{
F_11 ( & V_4 -> V_15 ) ;
F_12 ( & V_14 -> V_16 , & V_4 -> V_17 ) ;
F_13 ( & V_4 -> V_15 ) ;
}
static struct V_13 * F_14 ( struct V_4 * V_4 )
{
struct V_13 * V_14 = NULL ;
F_11 ( & V_4 -> V_15 ) ;
if ( ! F_15 ( & V_4 -> V_17 ) ) {
V_14 = F_16 ( V_4 -> V_17 . V_18 , struct V_13 , V_16 ) ;
F_17 ( & V_14 -> V_16 ) ;
}
F_13 ( & V_4 -> V_15 ) ;
return V_14 ;
}
static int F_18 ( struct V_4 * V_4 , int V_8 )
{
struct V_13 * V_14 = NULL ;
while ( V_8 ) {
V_14 = F_14 ( V_4 ) ;
if ( V_14 == NULL )
return 0 ;
if ( V_14 -> V_19 <= V_8 ) {
F_19 ( V_4 , V_14 -> V_3 , V_14 -> V_19 ) ;
V_8 -= V_14 -> V_19 ;
F_20 ( V_14 ) ;
} else if ( V_4 -> V_9 == 0 ) {
F_19 ( V_4 , V_14 -> V_3 , V_8 ) ;
V_14 -> V_3 += V_8 ;
V_14 -> V_19 -= V_8 ;
V_8 = 0 ;
F_10 ( V_4 , V_14 ) ;
} else {
F_21 ( L_1 ) ;
F_10 ( V_4 , V_14 ) ;
break;
}
}
return 0 ;
}
static int F_22 ( void * V_1 , T_1 V_2 )
{
int V_20 = V_2 ;
struct V_4 * V_4 = V_1 ;
return F_18 ( V_4 , V_20 ) ;
}
static int F_23 ( struct V_4 * V_4 , int V_8 )
{
struct V_13 * V_14 ;
struct V_21 * V_3 ;
V_14 = F_24 ( sizeof( * V_14 ) , V_22 ) ;
if ( ! V_14 )
return - V_23 ;
V_3 = F_25 ( V_4 , V_8 , 0 ) ;
if ( ! V_3 ) {
F_20 ( V_14 ) ;
return - V_23 ;
}
V_14 -> V_3 = V_3 ;
V_14 -> V_19 = V_8 ;
F_10 ( V_4 , V_14 ) ;
return 0 ;
}
static int F_26 ( void * V_1 , T_1 V_2 )
{
int V_20 = V_2 ;
struct V_4 * V_4 = V_1 ;
return F_23 ( V_4 , V_20 ) ;
}
static void F_27 ( struct V_4 * V_4 , int V_24 )
{
struct V_25 * V_26 ;
char V_27 [ 16 ] ;
int V_28 ;
sprintf ( V_27 , L_2 , V_24 ) ;
V_26 = F_28 ( V_27 , V_29 ) ;
F_29 ( L_3 , V_30 , V_29 , V_4 ,
& V_31 ) ;
F_29 ( L_4 , V_30 , V_29 , V_4 ,
& V_32 ) ;
F_29 ( L_5 , V_33 , V_26 ,
& V_4 -> V_34 , & V_35 ) ;
F_29 ( L_6 , V_33 , V_26 ,
& V_4 -> V_8 , & V_35 ) ;
F_29 ( L_7 , V_33 , V_26 ,
& V_4 -> V_9 , & V_35 ) ;
F_29 ( L_8 , V_33 , V_26 , V_4 , & V_36 ) ;
F_29 ( L_9 , V_33 , V_26 , V_4 , & V_37 ) ;
V_28 = F_30 ( F_31 ( V_4 ) , V_38 * sizeof( V_39 ) ) ;
F_32 ( L_10 , V_33 , V_26 , ( V_39 * ) V_4 -> V_7 , V_28 ) ;
}
static int T_2 F_33 ( void )
{
int V_40 ;
V_29 = F_28 ( L_11 , NULL ) ;
if ( ! V_29 )
return - V_23 ;
for ( V_40 = 0 ; V_40 < V_41 ; V_40 ++ )
F_27 ( & V_42 [ V_40 ] , V_40 ) ;
return 0 ;
}
