static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = NULL ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
V_2 -> V_3 = NULL ;
return 0 ;
}
static inline T_1 F_3 ( unsigned long V_4 ,
unsigned int V_5 , int V_6 )
{
return ( ( T_1 ) V_4 * 100 + V_5 ) * 1000 + V_6 ;
}
static int F_4 ( struct V_7 * V_8 , void * V_3 )
{
T_2 V_9 = V_10 ;
struct V_11 * V_12 = V_3 ;
char V_13 [ V_14 ] , V_15 ;
int V_16 ;
int V_17 ;
unsigned int V_5 ;
unsigned long time , V_18 ;
if ( F_5 ( V_8 -> V_19 . V_20 , V_9 ) )
return 0 ;
for ( V_16 = 0 ; V_16 < V_14 ; V_16 ++ )
V_13 [ V_16 ] = V_8 -> V_19 . V_21 [ V_16 ] ;
if ( sscanf ( V_13 , L_1 ,
V_12 -> type , & V_5 , & V_17 , & time , & V_15 ) == 5 ) {
* V_12 -> V_22 = F_3 ( time , V_5 , V_17 ) ;
* V_12 -> V_6 = V_17 ;
V_12 -> V_23 -> V_24 = time ;
V_12 -> V_23 -> V_25 = 0 ;
if ( V_15 == 'C' )
* V_12 -> V_26 = true ;
else
* V_12 -> V_26 = false ;
* V_12 -> V_27 = 0 ;
} else if ( sscanf ( V_13 , L_2 ,
V_12 -> type , & V_5 , & V_17 , & time ) == 4 ) {
* V_12 -> V_22 = F_3 ( time , V_5 , V_17 ) ;
* V_12 -> V_6 = V_17 ;
V_12 -> V_23 -> V_24 = time ;
V_12 -> V_23 -> V_25 = 0 ;
* V_12 -> V_26 = false ;
* V_12 -> V_27 = 0 ;
} else if ( sscanf ( V_13 , L_3 ,
V_12 -> type , & V_5 , & time ) == 3 ) {
* V_12 -> V_22 = F_3 ( time , V_5 , 0 ) ;
* V_12 -> V_6 = 0 ;
V_12 -> V_23 -> V_24 = time ;
V_12 -> V_23 -> V_25 = 0 ;
* V_12 -> V_26 = false ;
* V_12 -> V_27 = 0 ;
} else
return 0 ;
V_8 -> V_19 . V_28 = 1024 ;
F_6 ( V_8 , & V_8 -> V_19 . V_29 ,
& V_8 -> V_19 . V_28 , V_8 -> V_19 . V_30 ) ;
V_18 = V_8 -> V_19 . V_28 ;
memcpy ( * V_12 -> V_31 , V_8 -> V_19 . V_30 ,
( V_32 ) F_7 (unsigned long, EFIVARS_DATA_SIZE_MAX, size) ) ;
return V_18 ;
}
static void F_8 ( struct V_7 * V_33 ,
struct V_7 * V_34 ,
struct V_35 * V_36 )
{
V_33 -> V_37 = true ;
if ( & V_34 -> V_38 != V_36 )
V_34 -> V_37 = true ;
}
static inline int F_9 ( struct V_7 * V_8 ,
bool V_39 )
{
if ( V_8 -> V_40 ) {
F_10 ( & V_8 -> V_38 ) ;
F_11 () ;
F_12 ( V_8 ) ;
if ( F_13 () )
return - V_41 ;
} else if ( V_39 )
V_8 -> V_37 = false ;
return 0 ;
}
static int F_14 ( struct V_7 * V_33 ,
struct V_7 * V_34 ,
struct V_35 * V_36 , bool V_42 )
{
int V_43 = F_9 ( V_33 , true ) ;
if ( V_43 )
return V_43 ;
if ( V_42 )
V_43 = F_9 ( V_34 , & V_34 -> V_38 != V_36 ) ;
return V_43 ;
}
static int F_15 ( void * V_3 , struct V_7 * * V_33 )
{
struct V_7 * V_8 , * V_44 ;
struct V_35 * V_36 = & V_45 ;
int V_18 = 0 ;
int V_43 ;
if ( ! * V_33 ) {
F_16 (entry, n, head, list) {
F_8 ( V_8 , V_44 , V_36 ) ;
V_18 = F_4 ( V_8 , V_3 ) ;
V_43 = F_14 ( V_8 , V_44 , V_36 ,
V_18 < 0 ) ;
if ( V_43 )
return V_43 ;
if ( V_18 )
break;
}
* V_33 = V_44 ;
return V_18 ;
}
F_17 ((*pos), n, head, list) {
F_8 ( ( * V_33 ) , V_44 , V_36 ) ;
V_18 = F_4 ( ( * V_33 ) , V_3 ) ;
V_43 = F_14 ( ( * V_33 ) , V_44 , V_36 , V_18 < 0 ) ;
if ( V_43 )
return V_43 ;
if ( V_18 )
break;
}
* V_33 = V_44 ;
return V_18 ;
}
static T_3 F_18 ( T_1 * V_22 , enum V_46 * type ,
int * V_6 , struct V_23 * V_23 ,
char * * V_31 , bool * V_26 ,
T_3 * V_27 ,
struct V_1 * V_2 )
{
struct V_11 V_3 ;
T_3 V_18 ;
V_3 . V_22 = V_22 ;
V_3 . type = type ;
V_3 . V_6 = V_6 ;
V_3 . V_23 = V_23 ;
V_3 . V_26 = V_26 ;
V_3 . V_27 = V_27 ;
V_3 . V_31 = V_31 ;
* V_3 . V_31 = F_19 ( V_47 , V_48 ) ;
if ( ! * V_3 . V_31 )
return - V_49 ;
if ( F_13 () ) {
F_20 ( * V_3 . V_31 ) ;
return - V_41 ;
}
V_18 = F_15 ( & V_3 ,
(struct V_7 * * ) & V_2 -> V_3 ) ;
F_11 () ;
if ( V_18 <= 0 )
F_20 ( * V_3 . V_31 ) ;
return V_18 ;
}
static int F_21 ( enum V_46 type ,
enum V_50 V_51 , T_1 * V_22 ,
unsigned int V_5 , int V_6 , bool V_26 , V_32 V_18 ,
struct V_1 * V_2 )
{
char V_13 [ V_14 ] ;
T_4 V_52 [ V_14 ] ;
T_2 V_9 = V_10 ;
int V_16 , V_43 = 0 ;
sprintf ( V_13 , L_1 , type , V_5 , V_6 ,
F_22 () , V_26 ? 'C' : 'D' ) ;
for ( V_16 = 0 ; V_16 < V_14 ; V_16 ++ )
V_52 [ V_16 ] = V_13 [ V_16 ] ;
F_23 ( V_52 , V_9 , V_53 ,
! F_24 ( V_51 ) ,
V_18 , V_2 -> V_31 ) ;
if ( V_51 == V_54 )
F_25 () ;
* V_22 = V_5 ;
return V_43 ;
}
static int F_26 ( struct V_7 * V_8 , void * V_3 )
{
struct V_55 * V_56 = V_3 ;
T_2 V_9 = V_10 ;
T_4 V_57 [ V_14 ] ;
T_4 * V_52 = V_56 -> V_13 ;
unsigned long V_58 = F_27 ( V_56 -> V_13 ) ;
char V_59 [ V_14 ] ;
int V_16 ;
if ( F_5 ( V_8 -> V_19 . V_20 , V_9 ) )
return 0 ;
if ( F_28 ( V_8 -> V_19 . V_21 ,
V_52 , ( V_32 ) V_58 ) ) {
sprintf ( V_59 , L_3 , V_56 -> type ,
( unsigned int ) V_56 -> V_22 , V_56 -> time . V_24 ) ;
for ( V_16 = 0 ; V_16 < V_14 ; V_16 ++ )
V_57 [ V_16 ] = V_59 [ V_16 ] ;
if ( F_28 ( V_8 -> V_19 . V_21 , V_57 ,
F_27 ( V_57 ) ) )
return 0 ;
}
if ( V_8 -> V_37 ) {
V_8 -> V_40 = true ;
} else
F_10 ( & V_8 -> V_38 ) ;
F_29 ( V_8 ) ;
return 1 ;
}
static int F_30 ( enum V_46 type , T_1 V_22 , int V_6 ,
struct V_23 time , struct V_1 * V_2 )
{
struct V_55 V_60 ;
struct V_7 * V_8 = NULL ;
char V_13 [ V_14 ] ;
T_4 V_52 [ V_14 ] ;
int V_61 , V_16 ;
unsigned int V_5 ;
F_31 ( V_22 , 1000 ) ;
V_5 = F_31 ( V_22 , 100 ) ;
sprintf ( V_13 , L_2 , type , V_5 , V_6 , time . V_24 ) ;
for ( V_16 = 0 ; V_16 < V_14 ; V_16 ++ )
V_52 [ V_16 ] = V_13 [ V_16 ] ;
V_60 . V_22 = V_5 ;
V_60 . type = type ;
V_60 . V_6 = V_6 ;
V_60 . time = time ;
V_60 . V_13 = V_52 ;
if ( F_13 () )
return - V_41 ;
V_61 = F_32 ( F_26 , & V_45 , & V_60 , & V_8 ) ;
if ( V_61 && ! V_8 -> V_37 ) {
F_11 () ;
F_12 ( V_8 ) ;
} else
F_11 () ;
return 0 ;
}
static T_5 int F_33 ( void )
{
if ( ! F_34 ( V_62 ) )
return 0 ;
if ( ! F_35 () )
return 0 ;
if ( V_63 )
return 0 ;
V_64 . V_31 = F_36 ( 4096 , V_48 ) ;
if ( ! V_64 . V_31 )
return - V_49 ;
V_64 . V_65 = 1024 ;
F_37 ( & V_64 . V_66 ) ;
if ( F_38 ( & V_64 ) ) {
F_20 ( V_64 . V_31 ) ;
V_64 . V_31 = NULL ;
V_64 . V_65 = 0 ;
}
return 0 ;
}
static T_6 void F_39 ( void )
{
if ( ! V_64 . V_65 )
return;
F_40 ( & V_64 ) ;
F_20 ( V_64 . V_31 ) ;
V_64 . V_31 = NULL ;
V_64 . V_65 = 0 ;
}
