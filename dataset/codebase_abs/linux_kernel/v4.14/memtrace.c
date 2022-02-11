static T_1 F_1 ( struct V_1 * V_2 , char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
return F_2 ( V_3 , V_4 , V_5 , V_7 -> V_9 , V_7 -> V_10 ) ;
}
static bool F_3 ( struct V_6 * V_11 ,
unsigned long V_12 , unsigned long V_10 )
{
if ( ( V_12 >= V_11 -> V_12 ) &&
( ( V_12 + V_10 ) <= ( V_11 -> V_12 + V_11 -> V_10 ) ) )
return true ;
return false ;
}
static int F_4 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
unsigned long V_10 = V_14 -> V_15 - V_14 -> V_16 ;
struct V_6 * V_11 = V_2 -> V_8 ;
if ( ! F_3 ( V_11 , V_14 -> V_17 << V_18 , V_10 ) )
return - V_19 ;
V_14 -> V_20 = F_5 ( V_14 -> V_20 ) ;
if ( F_6 ( V_14 , V_14 -> V_16 ,
V_14 -> V_17 + ( V_11 -> V_12 >> V_18 ) ,
V_10 , V_14 -> V_20 ) )
return - V_21 ;
return 0 ;
}
static void F_7 ( T_5 V_22 , T_5 V_10 )
{
unsigned long V_23 = V_24 . V_25 . V_10 ;
T_5 V_26 = V_22 + V_10 ;
T_5 V_27 ;
V_22 = F_8 ( V_22 , V_23 ) ;
V_26 = F_9 ( V_26 , V_23 ) ;
for ( V_27 = V_22 ; V_27 < V_26 ; V_27 += V_23 )
asm volatile("dcbf 0,%0" : "=r" (addr) :: "memory");
}
static int F_10 ( struct V_28 * V_9 , void * V_29 )
{
if ( V_9 -> V_30 != V_31 )
return - 1 ;
return 0 ;
}
static int F_11 ( struct V_28 * V_9 , void * V_29 )
{
unsigned long V_30 = ( unsigned long ) V_29 ;
V_9 -> V_30 = V_30 ;
return 0 ;
}
static bool F_12 ( T_6 V_32 , T_5 V_33 , T_5 V_34 )
{
T_5 V_35 = V_33 + V_34 - 1 ;
if ( F_13 ( V_33 , V_35 , NULL ,
F_10 ) )
return false ;
F_13 ( V_33 , V_35 , ( void * ) V_36 ,
F_11 ) ;
if ( F_14 ( V_33 , V_34 ) ) {
F_13 ( V_33 , V_35 , ( void * ) V_31 ,
F_11 ) ;
return false ;
}
F_13 ( V_33 , V_35 , ( void * ) V_37 ,
F_11 ) ;
F_7 ( ( T_5 ) F_15 ( V_33 << V_18 ) ,
V_34 << V_18 ) ;
F_16 () ;
F_17 ( V_32 , V_33 << V_18 , V_34 << V_18 ) ;
F_18 () ;
return true ;
}
static T_5 F_19 ( T_6 V_32 , T_5 V_10 )
{
T_5 V_33 , V_35 , V_34 ;
T_5 V_38 ;
if ( ! F_20 ( V_32 ) || ! F_21 ( V_32 ) )
return 0 ;
V_33 = F_22 ( V_32 ) ;
V_35 = F_23 ( V_32 ) ;
V_34 = V_10 >> V_18 ;
V_35 = F_8 ( V_35 - V_34 , V_34 ) ;
for ( V_38 = V_35 ; V_38 > V_33 ; V_38 -= V_34 ) {
if ( F_12 ( V_32 , V_38 , V_34 ) == true )
return V_38 << V_18 ;
}
return 0 ;
}
static int F_24 ( T_5 V_10 )
{
T_6 V_32 ;
T_5 V_39 ;
V_40 = F_25 ( F_26 () ,
sizeof( struct V_6 ) , V_41 ) ;
if ( ! V_40 ) {
F_27 ( L_1 ) ;
return - V_19 ;
}
F_28 (nid) {
V_39 = F_19 ( V_32 , V_10 ) ;
if ( ! V_39 ) {
F_27 ( L_2 , V_32 ) ;
continue;
}
F_29 ( L_3 , V_32 , V_39 ) ;
V_40 [ V_42 ] . V_12 = V_39 ;
V_40 [ V_42 ] . V_10 = V_10 ;
V_40 [ V_42 ] . V_32 = V_32 ;
V_42 ++ ;
}
return 0 ;
}
static int F_30 ( void )
{
int V_43 = 0 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_42 ; V_44 ++ ) {
struct V_45 * V_46 ;
struct V_6 * V_7 = & V_40 [ V_44 ] ;
V_7 -> V_9 = F_31 ( V_7 -> V_12 , V_7 -> V_10 ) ;
if ( ! V_7 -> V_9 ) {
F_27 ( L_4 ,
V_7 -> V_12 ) ;
V_43 = - 1 ;
continue;
}
snprintf ( V_7 -> V_47 , 16 , L_5 , V_7 -> V_32 ) ;
V_46 = F_32 ( V_7 -> V_47 , V_48 ) ;
if ( ! V_46 )
return - 1 ;
V_7 -> V_46 = V_46 ;
F_33 ( L_6 , 0400 , V_46 , V_7 , & V_49 ) ;
F_34 ( L_7 , 0400 , V_46 , & V_7 -> V_12 ) ;
F_34 ( L_8 , 0400 , V_46 , & V_7 -> V_10 ) ;
}
return V_43 ;
}
static int F_35 ( void * V_50 , T_5 V_51 )
{
if ( V_52 )
return - V_19 ;
if ( ! V_51 )
return - V_19 ;
if ( V_51 & ( F_36 () - 1 ) )
return - V_19 ;
if ( F_24 ( V_51 ) )
return - V_19 ;
if ( F_30 () )
return - V_19 ;
V_52 = V_51 ;
return 0 ;
}
static int F_37 ( void * V_50 , T_5 * V_51 )
{
* V_51 = V_52 ;
return 0 ;
}
static int F_38 ( void )
{
V_48 = F_32 ( L_9 ,
V_53 ) ;
if ( ! V_48 )
return - 1 ;
F_33 ( L_10 , 0600 , V_48 ,
NULL , & V_54 ) ;
return 0 ;
}
