static int F_1 ( struct V_1 * V_2 )
{
F_2 () ;
V_2 -> V_3 = NULL ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
F_4 () ;
V_2 -> V_3 = NULL ;
return 0 ;
}
static int F_5 ( struct V_4 * V_5 , void * V_3 )
{
T_1 V_6 = V_7 ;
struct V_8 * V_9 = V_3 ;
char V_10 [ V_11 ] ;
int V_12 ;
int V_13 ;
unsigned int V_14 ;
unsigned long time , V_15 ;
if ( F_6 ( V_5 -> V_16 . V_17 , V_6 ) )
return 0 ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ )
V_10 [ V_12 ] = V_5 -> V_16 . V_18 [ V_12 ] ;
if ( sscanf ( V_10 , L_1 ,
V_9 -> type , & V_14 , & V_13 , & time ) == 4 ) {
* V_9 -> V_19 = V_14 ;
* V_9 -> V_20 = V_13 ;
V_9 -> V_21 -> V_22 = time ;
V_9 -> V_21 -> V_23 = 0 ;
} else if ( sscanf ( V_10 , L_2 ,
V_9 -> type , & V_14 , & time ) == 3 ) {
* V_9 -> V_19 = V_14 ;
* V_9 -> V_20 = 0 ;
V_9 -> V_21 -> V_22 = time ;
V_9 -> V_21 -> V_23 = 0 ;
} else
return 0 ;
V_5 -> V_16 . V_24 = 1024 ;
F_7 ( V_5 , & V_5 -> V_16 . V_25 ,
& V_5 -> V_16 . V_24 , V_5 -> V_16 . V_26 ) ;
V_15 = V_5 -> V_16 . V_24 ;
* V_9 -> V_27 = F_8 ( V_15 , V_28 ) ;
if ( * V_9 -> V_27 == NULL )
return - V_29 ;
memcpy ( * V_9 -> V_27 , V_5 -> V_16 . V_26 , V_15 ) ;
return V_15 ;
}
static T_2 F_9 ( T_3 * V_19 , enum V_30 * type ,
int * V_20 , struct V_21 * V_21 ,
char * * V_27 , struct V_1 * V_2 )
{
struct V_8 V_3 ;
V_3 . V_19 = V_19 ;
V_3 . type = type ;
V_3 . V_20 = V_20 ;
V_3 . V_21 = V_21 ;
V_3 . V_27 = V_27 ;
return F_10 ( F_5 , & V_31 , & V_3 ,
(struct V_4 * * ) & V_2 -> V_3 ) ;
}
static int F_11 ( enum V_30 type ,
enum V_32 V_33 , T_3 * V_19 ,
unsigned int V_14 , int V_20 , T_4 V_15 ,
struct V_1 * V_2 )
{
char V_10 [ V_11 ] ;
T_5 V_34 [ V_11 ] ;
T_1 V_6 = V_7 ;
int V_12 , V_35 = 0 ;
sprintf ( V_10 , L_1 , type , V_14 , V_20 ,
F_12 () ) ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ )
V_34 [ V_12 ] = V_10 [ V_12 ] ;
F_13 ( V_34 , V_6 , V_36 ,
! F_14 ( V_33 ) ,
V_15 , V_2 -> V_27 ) ;
if ( V_33 == V_37 )
F_15 () ;
* V_19 = V_14 ;
return V_35 ;
}
static int F_16 ( struct V_4 * V_5 , void * V_3 )
{
struct V_38 * V_39 = V_3 ;
T_1 V_6 = V_7 ;
T_5 V_40 [ V_11 ] ;
T_5 * V_34 = V_39 -> V_10 ;
unsigned long V_41 = F_17 ( V_39 -> V_10 ) ;
char V_42 [ V_11 ] ;
int V_12 ;
if ( F_6 ( V_5 -> V_16 . V_17 , V_6 ) )
return 0 ;
if ( F_18 ( V_5 -> V_16 . V_18 ,
V_34 , ( T_4 ) V_41 ) ) {
sprintf ( V_42 , L_2 , V_39 -> type ,
( unsigned int ) V_39 -> V_19 , V_39 -> time . V_22 ) ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ )
V_40 [ V_12 ] = V_42 [ V_12 ] ;
if ( F_18 ( V_5 -> V_16 . V_18 , V_40 ,
F_17 ( V_40 ) ) )
return 0 ;
}
F_19 ( V_5 ) ;
F_20 ( & V_5 -> V_43 ) ;
return 1 ;
}
static int F_21 ( enum V_30 type , T_3 V_19 , int V_20 ,
struct V_21 time , struct V_1 * V_2 )
{
struct V_38 V_44 ;
struct V_4 * V_5 = NULL ;
char V_10 [ V_11 ] ;
T_5 V_34 [ V_11 ] ;
int V_45 , V_12 ;
sprintf ( V_10 , L_1 , type , ( unsigned int ) V_19 , V_20 ,
time . V_22 ) ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ )
V_34 [ V_12 ] = V_10 [ V_12 ] ;
V_44 . V_19 = V_19 ;
V_44 . type = type ;
V_44 . V_20 = V_20 ;
V_44 . time = time ;
V_44 . V_10 = V_34 ;
F_2 () ;
V_45 = F_10 ( F_16 , & V_31 , & V_44 , & V_5 ) ;
F_4 () ;
if ( V_45 )
F_22 ( V_5 ) ;
return 0 ;
}
static T_6 int F_23 ( void )
{
if ( ! F_24 ( V_46 ) )
return 0 ;
if ( ! F_25 () )
return 0 ;
if ( V_47 )
return 0 ;
V_48 . V_27 = F_8 ( 4096 , V_28 ) ;
if ( ! V_48 . V_27 )
return - V_29 ;
V_48 . V_49 = 1024 ;
F_26 ( & V_48 . V_50 ) ;
F_27 ( & V_48 ) ;
return 0 ;
}
static T_7 void F_28 ( void )
{
}
