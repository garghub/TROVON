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
char V_10 [ V_11 ] , V_12 ;
int V_13 ;
int V_14 ;
unsigned int V_15 ;
unsigned long time , V_16 ;
if ( F_6 ( V_5 -> V_17 . V_18 , V_6 ) )
return 0 ;
for ( V_13 = 0 ; V_13 < V_11 ; V_13 ++ )
V_10 [ V_13 ] = V_5 -> V_17 . V_19 [ V_13 ] ;
if ( sscanf ( V_10 , L_1 ,
V_9 -> type , & V_15 , & V_14 , & time , & V_12 ) == 5 ) {
* V_9 -> V_20 = V_15 ;
* V_9 -> V_21 = V_14 ;
V_9 -> V_22 -> V_23 = time ;
V_9 -> V_22 -> V_24 = 0 ;
if ( V_12 == 'C' )
* V_9 -> V_25 = true ;
else
* V_9 -> V_25 = false ;
} else if ( sscanf ( V_10 , L_2 ,
V_9 -> type , & V_15 , & V_14 , & time ) == 4 ) {
* V_9 -> V_20 = V_15 ;
* V_9 -> V_21 = V_14 ;
V_9 -> V_22 -> V_23 = time ;
V_9 -> V_22 -> V_24 = 0 ;
* V_9 -> V_25 = false ;
} else if ( sscanf ( V_10 , L_3 ,
V_9 -> type , & V_15 , & time ) == 3 ) {
* V_9 -> V_20 = V_15 ;
* V_9 -> V_21 = 0 ;
V_9 -> V_22 -> V_23 = time ;
V_9 -> V_22 -> V_24 = 0 ;
* V_9 -> V_25 = false ;
} else
return 0 ;
V_5 -> V_17 . V_26 = 1024 ;
F_7 ( V_5 , & V_5 -> V_17 . V_27 ,
& V_5 -> V_17 . V_26 , V_5 -> V_17 . V_28 ) ;
V_16 = V_5 -> V_17 . V_26 ;
* V_9 -> V_29 = F_8 ( V_5 -> V_17 . V_28 , V_16 , V_30 ) ;
if ( * V_9 -> V_29 == NULL )
return - V_31 ;
return V_16 ;
}
static T_2 F_9 ( T_3 * V_20 , enum V_32 * type ,
int * V_21 , struct V_22 * V_22 ,
char * * V_29 , bool * V_25 ,
struct V_1 * V_2 )
{
struct V_8 V_3 ;
V_3 . V_20 = V_20 ;
V_3 . type = type ;
V_3 . V_21 = V_21 ;
V_3 . V_22 = V_22 ;
V_3 . V_25 = V_25 ;
V_3 . V_29 = V_29 ;
return F_10 ( F_5 , & V_33 , & V_3 ,
(struct V_4 * * ) & V_2 -> V_3 ) ;
}
static int F_11 ( enum V_32 type ,
enum V_34 V_35 , T_3 * V_20 ,
unsigned int V_15 , int V_21 , bool V_25 , T_4 V_16 ,
struct V_1 * V_2 )
{
char V_10 [ V_11 ] ;
T_5 V_36 [ V_11 ] ;
T_1 V_6 = V_7 ;
int V_13 , V_37 = 0 ;
sprintf ( V_10 , L_1 , type , V_15 , V_21 ,
F_12 () , V_25 ? 'C' : 'D' ) ;
for ( V_13 = 0 ; V_13 < V_11 ; V_13 ++ )
V_36 [ V_13 ] = V_10 [ V_13 ] ;
F_13 ( V_36 , V_6 , V_38 ,
! F_14 ( V_35 ) ,
V_16 , V_2 -> V_29 ) ;
if ( V_35 == V_39 )
F_15 () ;
* V_20 = V_15 ;
return V_37 ;
}
static int F_16 ( struct V_4 * V_5 , void * V_3 )
{
struct V_40 * V_41 = V_3 ;
T_1 V_6 = V_7 ;
T_5 V_42 [ V_11 ] ;
T_5 * V_36 = V_41 -> V_10 ;
unsigned long V_43 = F_17 ( V_41 -> V_10 ) ;
char V_44 [ V_11 ] ;
int V_13 ;
if ( F_6 ( V_5 -> V_17 . V_18 , V_6 ) )
return 0 ;
if ( F_18 ( V_5 -> V_17 . V_19 ,
V_36 , ( T_4 ) V_43 ) ) {
sprintf ( V_44 , L_3 , V_41 -> type ,
( unsigned int ) V_41 -> V_20 , V_41 -> time . V_23 ) ;
for ( V_13 = 0 ; V_13 < V_11 ; V_13 ++ )
V_42 [ V_13 ] = V_44 [ V_13 ] ;
if ( F_18 ( V_5 -> V_17 . V_19 , V_42 ,
F_17 ( V_42 ) ) )
return 0 ;
}
F_19 ( V_5 ) ;
F_20 ( & V_5 -> V_45 ) ;
return 1 ;
}
static int F_21 ( enum V_32 type , T_3 V_20 , int V_21 ,
struct V_22 time , struct V_1 * V_2 )
{
struct V_40 V_46 ;
struct V_4 * V_5 = NULL ;
char V_10 [ V_11 ] ;
T_5 V_36 [ V_11 ] ;
int V_47 , V_13 ;
sprintf ( V_10 , L_2 , type , ( unsigned int ) V_20 , V_21 ,
time . V_23 ) ;
for ( V_13 = 0 ; V_13 < V_11 ; V_13 ++ )
V_36 [ V_13 ] = V_10 [ V_13 ] ;
V_46 . V_20 = V_20 ;
V_46 . type = type ;
V_46 . V_21 = V_21 ;
V_46 . time = time ;
V_46 . V_10 = V_36 ;
F_2 () ;
V_47 = F_10 ( F_16 , & V_33 , & V_46 , & V_5 ) ;
F_4 () ;
if ( V_47 )
F_22 ( V_5 ) ;
return 0 ;
}
static T_6 int F_23 ( void )
{
if ( ! F_24 ( V_48 ) )
return 0 ;
if ( ! F_25 () )
return 0 ;
if ( V_49 )
return 0 ;
V_50 . V_29 = F_26 ( 4096 , V_30 ) ;
if ( ! V_50 . V_29 )
return - V_31 ;
V_50 . V_51 = 1024 ;
F_27 ( & V_50 . V_52 ) ;
if ( F_28 ( & V_50 ) ) {
F_29 ( V_50 . V_29 ) ;
V_50 . V_29 = NULL ;
V_50 . V_51 = 0 ;
}
return 0 ;
}
static T_7 void F_30 ( void )
{
}
