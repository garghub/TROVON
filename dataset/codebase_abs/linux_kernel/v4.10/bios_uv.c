T_1 F_1 ( enum V_1 V_2 , T_2 V_3 , T_2 V_4 , T_2 V_5 , T_2 V_6 , T_2 V_7 )
{
struct V_8 * V_9 = V_8 ;
T_1 V_10 ;
if ( ! V_9 || ! V_9 -> V_11 )
return V_12 ;
if ( F_2 ( F_3 ( V_13 , & V_14 . V_15 ) ) )
V_10 = F_4 ( ( void * ) F_5 ( V_9 -> V_11 ) , ( T_2 ) V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ) ;
else
V_10 = F_6 ( V_9 , V_11 , ( T_2 ) V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ) ;
return V_10 ;
}
T_1 F_7 ( enum V_1 V_2 , T_2 V_3 , T_2 V_4 , T_2 V_5 ,
T_2 V_6 , T_2 V_7 )
{
unsigned long V_16 ;
T_1 V_10 ;
F_8 ( V_16 ) ;
V_10 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ) ;
F_9 ( V_16 ) ;
return V_10 ;
}
T_1 F_10 ( enum V_1 V_2 , T_2 V_3 , T_2 V_4 , T_2 V_5 ,
T_2 V_6 , T_2 V_7 )
{
T_1 V_10 ;
F_11 () ;
V_10 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ) ;
F_12 () ;
return V_10 ;
}
T_1 F_13 ( int V_17 , int * V_18 , long * V_19 , long * V_20 ,
long * V_21 , long * V_22 )
{
T_1 V_10 ;
T_2 V_23 , V_24 ;
union V_25 V_26 ;
V_10 = F_7 ( V_27 , V_17 ,
( T_2 ) ( & V_23 ) , ( T_2 ) ( & V_24 ) , 0 , 0 ) ;
if ( V_10 != V_28 )
return V_10 ;
V_26 . V_29 = V_23 ;
if ( V_18 )
* V_18 = V_26 . V_30 ;
if ( V_19 )
* V_19 = V_26 . V_31 ;
if ( V_20 )
* V_20 = V_26 . V_32 ;
if ( V_21 )
* V_21 = V_26 . V_33 ;
if ( V_22 )
* V_22 = V_24 ;
return V_10 ;
}
int
F_14 ( unsigned long V_34 , unsigned int V_35 ,
unsigned long * V_36 )
{
T_2 V_37 ;
T_1 V_10 ;
V_10 = ( int ) F_7 ( V_38 , V_34 ,
V_35 , ( T_2 ) V_36 ,
( T_2 ) & V_37 , 0 ) ;
if ( V_10 < V_28 )
return V_10 ;
return V_37 ;
}
int
F_15 ( int V_39 , int V_40 )
{
return ( int ) F_7 ( V_41 ,
V_39 , V_40 , 0 , 0 , 0 ) ;
}
T_1
F_16 ( T_2 V_42 , T_2 V_43 , enum V_44 V_45 )
{
return F_7 ( V_46 , V_42 , V_43 ,
V_45 , 0 , 0 ) ;
}
T_1
F_17 ( T_2 V_47 , T_2 * V_48 , T_2 * V_34 , T_2 * V_43 )
{
return F_7 ( V_49 , ( T_2 ) V_48 ,
( T_2 ) V_34 , V_47 , ( T_2 ) V_43 , 0 ) ;
}
T_1 F_18 ( T_2 V_50 , T_2 * V_51 )
{
return F_1 ( V_52 , V_50 ,
( T_2 ) V_51 , 0 , 0 , 0 ) ;
}
int F_19 ( bool V_53 , int V_54 , int V_55 )
{
return F_1 ( V_56 ,
( T_2 ) V_53 , ( T_2 ) V_54 , ( T_2 ) V_55 , 0 , 0 ) ;
}
void F_20 ( void )
{
V_8 = NULL ;
if ( ( V_14 . V_8 == V_57 ) ||
! V_14 . V_8 || F_21 () ) {
F_22 ( L_1 ) ;
return;
}
V_8 = F_23 ( V_14 . V_8 , sizeof( struct V_8 ) ) ;
if ( ! V_8 || strncmp ( V_8 -> V_58 , V_59 , 4 ) ) {
F_24 ( L_2 ) ;
F_25 ( V_8 ) ;
return;
}
if ( V_8 -> V_60 >= V_61 ) {
int V_62 = V_8 -> V_62 ;
F_25 ( V_8 ) ;
V_8 = F_23 ( V_14 . V_8 , V_62 ) ;
if ( ! V_8 ) {
F_24 ( L_3 , V_62 ) ;
return;
}
}
F_26 ( L_4 , V_8 -> V_60 ) ;
}
