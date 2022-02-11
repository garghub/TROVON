T_1 F_1 ( enum V_1 V_2 , T_2 V_3 , T_2 V_4 , T_2 V_5 , T_2 V_6 , T_2 V_7 )
{
struct V_8 * V_9 = & V_8 ;
T_1 V_10 ;
if ( ! V_9 -> V_11 )
return V_12 ;
V_10 = F_2 ( ( void * ) F_3 ( V_9 -> V_11 ) , ( T_2 ) V_2 ,
V_3 , V_4 , V_5 , V_6 , V_7 ) ;
return V_10 ;
}
T_1 F_4 ( enum V_1 V_2 , T_2 V_3 , T_2 V_4 , T_2 V_5 ,
T_2 V_6 , T_2 V_7 )
{
unsigned long V_13 ;
T_1 V_10 ;
F_5 ( V_13 ) ;
V_10 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ) ;
F_6 ( V_13 ) ;
return V_10 ;
}
T_1 F_7 ( enum V_1 V_2 , T_2 V_3 , T_2 V_4 , T_2 V_5 ,
T_2 V_6 , T_2 V_7 )
{
T_1 V_10 ;
F_8 () ;
V_10 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ) ;
F_9 () ;
return V_10 ;
}
T_1 F_10 ( int V_14 , int * V_15 , long * V_16 , long * V_17 ,
long * V_18 , long * V_19 )
{
T_1 V_10 ;
T_2 V_20 , V_21 ;
union V_22 V_23 ;
V_10 = F_4 ( V_24 , V_14 ,
( T_2 ) ( & V_20 ) , ( T_2 ) ( & V_21 ) , 0 , 0 ) ;
if ( V_10 != V_25 )
return V_10 ;
V_23 . V_26 = V_20 ;
if ( V_15 )
* V_15 = V_23 . V_27 ;
if ( V_16 )
* V_16 = V_23 . V_28 ;
if ( V_17 )
* V_17 = V_23 . V_29 ;
if ( V_18 )
* V_18 = V_23 . V_30 ;
if ( V_19 )
* V_19 = V_21 ;
return V_10 ;
}
int
F_11 ( unsigned long V_31 , unsigned int V_32 ,
unsigned long * V_33 )
{
T_2 V_34 ;
T_1 V_10 ;
V_10 = ( int ) F_4 ( V_35 , V_31 ,
V_32 , ( T_2 ) V_33 ,
( T_2 ) & V_34 , 0 ) ;
if ( V_10 < V_25 )
return V_10 ;
return V_34 ;
}
int
F_12 ( int V_36 , int V_37 )
{
return ( int ) F_4 ( V_38 ,
V_36 , V_37 , 0 , 0 , 0 ) ;
}
T_1
F_13 ( T_2 V_39 , T_2 V_40 , enum V_41 V_42 )
{
return F_4 ( V_43 , V_39 , V_40 ,
V_42 , 0 , 0 ) ;
}
T_1
F_14 ( T_2 V_44 , T_2 * V_45 , T_2 * V_31 , T_2 * V_40 )
{
T_1 V_10 ;
V_10 = F_4 ( V_46 , ( T_2 ) V_45 ,
( T_2 ) V_31 , V_44 , ( T_2 ) V_40 , 0 ) ;
return V_10 ;
}
T_1 F_15 ( T_2 V_47 , T_2 * V_48 )
{
return F_1 ( V_49 , V_47 ,
( T_2 ) V_48 , 0 , 0 , 0 ) ;
}
int F_16 ( bool V_50 , int V_51 , int V_52 )
{
return F_1 ( V_53 ,
( T_2 ) V_50 , ( T_2 ) V_51 , ( T_2 ) V_52 , 0 , 0 ) ;
}
void F_17 ( void )
{
struct V_8 * V_9 ;
if ( ( V_54 . V_8 == V_55 ) ||
( V_54 . V_8 == ( unsigned long ) NULL ) ) {
F_18 ( V_56 L_1 ) ;
V_8 . V_11 = ( unsigned long ) NULL ;
return;
}
V_9 = (struct V_8 * ) F_19 ( V_54 . V_8 ,
sizeof( struct V_8 ) ) ;
if ( strncmp ( V_9 -> V_57 , L_2 , 4 ) != 0 )
F_18 ( V_58 L_3 ) ;
memcpy ( & V_8 , V_9 , sizeof( struct V_8 ) ) ;
F_20 ( V_9 ) ;
F_18 ( V_59 L_4 ,
V_8 . V_60 ) ;
}
void F_17 ( void ) { }
