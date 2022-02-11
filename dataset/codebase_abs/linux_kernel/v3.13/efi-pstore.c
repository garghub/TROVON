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
return ( V_4 * 100 + V_5 ) * 1000 + V_6 ;
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
} else if ( sscanf ( V_13 , L_2 ,
V_12 -> type , & V_5 , & V_17 , & time ) == 4 ) {
* V_12 -> V_22 = F_3 ( time , V_5 , V_17 ) ;
* V_12 -> V_6 = V_17 ;
V_12 -> V_23 -> V_24 = time ;
V_12 -> V_23 -> V_25 = 0 ;
* V_12 -> V_26 = false ;
} else if ( sscanf ( V_13 , L_3 ,
V_12 -> type , & V_5 , & time ) == 3 ) {
* V_12 -> V_22 = F_3 ( time , V_5 , 0 ) ;
* V_12 -> V_6 = 0 ;
V_12 -> V_23 -> V_24 = time ;
V_12 -> V_23 -> V_25 = 0 ;
* V_12 -> V_26 = false ;
} else
return 0 ;
V_8 -> V_19 . V_27 = 1024 ;
F_6 ( V_8 , & V_8 -> V_19 . V_28 ,
& V_8 -> V_19 . V_27 , V_8 -> V_19 . V_29 ) ;
V_18 = V_8 -> V_19 . V_27 ;
memcpy ( * V_12 -> V_30 , V_8 -> V_19 . V_29 ,
( V_31 ) F_7 (unsigned long, EFIVARS_DATA_SIZE_MAX, size) ) ;
return V_18 ;
}
static void F_8 ( struct V_7 * V_32 ,
struct V_7 * V_33 ,
struct V_34 * V_35 )
{
V_32 -> V_36 = true ;
if ( & V_33 -> V_37 != V_35 )
V_33 -> V_36 = true ;
}
static inline void F_9 ( struct V_7 * V_8 ,
bool V_38 )
{
if ( V_8 -> V_39 ) {
F_10 ( & V_8 -> V_37 ) ;
F_11 () ;
F_12 ( V_8 ) ;
F_13 () ;
} else if ( V_38 )
V_8 -> V_36 = false ;
}
static void F_14 ( struct V_7 * V_32 ,
struct V_7 * V_33 ,
struct V_34 * V_35 , bool V_40 )
{
F_9 ( V_32 , true ) ;
if ( V_40 )
F_9 ( V_33 , & V_33 -> V_37 != V_35 ) ;
}
static int F_15 ( void * V_3 , struct V_7 * * V_32 )
{
struct V_7 * V_8 , * V_41 ;
struct V_34 * V_35 = & V_42 ;
int V_18 = 0 ;
if ( ! * V_32 ) {
F_16 (entry, n, head, list) {
F_8 ( V_8 , V_41 , V_35 ) ;
V_18 = F_4 ( V_8 , V_3 ) ;
F_14 ( V_8 , V_41 , V_35 , V_18 < 0 ) ;
if ( V_18 )
break;
}
* V_32 = V_41 ;
return V_18 ;
}
F_17 ((*pos), n, head, list) {
F_8 ( ( * V_32 ) , V_41 , V_35 ) ;
V_18 = F_4 ( ( * V_32 ) , V_3 ) ;
F_14 ( ( * V_32 ) , V_41 , V_35 , V_18 < 0 ) ;
if ( V_18 )
break;
}
* V_32 = V_41 ;
return V_18 ;
}
static T_3 F_18 ( T_1 * V_22 , enum V_43 * type ,
int * V_6 , struct V_23 * V_23 ,
char * * V_30 , bool * V_26 ,
struct V_1 * V_2 )
{
struct V_11 V_3 ;
T_3 V_18 ;
V_3 . V_22 = V_22 ;
V_3 . type = type ;
V_3 . V_6 = V_6 ;
V_3 . V_23 = V_23 ;
V_3 . V_26 = V_26 ;
V_3 . V_30 = V_30 ;
* V_3 . V_30 = F_19 ( V_44 , V_45 ) ;
if ( ! * V_3 . V_30 )
return - V_46 ;
F_13 () ;
V_18 = F_15 ( & V_3 ,
(struct V_7 * * ) & V_2 -> V_3 ) ;
F_11 () ;
if ( V_18 <= 0 )
F_20 ( * V_3 . V_30 ) ;
return V_18 ;
}
static int F_21 ( enum V_43 type ,
enum V_47 V_48 , T_1 * V_22 ,
unsigned int V_5 , int V_6 , bool V_26 , V_31 V_18 ,
struct V_1 * V_2 )
{
char V_13 [ V_14 ] ;
T_4 V_49 [ V_14 ] ;
T_2 V_9 = V_10 ;
int V_16 , V_50 = 0 ;
sprintf ( V_13 , L_1 , type , V_5 , V_6 ,
F_22 () , V_26 ? 'C' : 'D' ) ;
for ( V_16 = 0 ; V_16 < V_14 ; V_16 ++ )
V_49 [ V_16 ] = V_13 [ V_16 ] ;
F_23 ( V_49 , V_9 , V_51 ,
! F_24 ( V_48 ) ,
V_18 , V_2 -> V_30 ) ;
if ( V_48 == V_52 )
F_25 () ;
* V_22 = V_5 ;
return V_50 ;
}
static int F_26 ( struct V_7 * V_8 , void * V_3 )
{
struct V_53 * V_54 = V_3 ;
T_2 V_9 = V_10 ;
T_4 V_55 [ V_14 ] ;
T_4 * V_49 = V_54 -> V_13 ;
unsigned long V_56 = F_27 ( V_54 -> V_13 ) ;
char V_57 [ V_14 ] ;
int V_16 ;
if ( F_5 ( V_8 -> V_19 . V_20 , V_9 ) )
return 0 ;
if ( F_28 ( V_8 -> V_19 . V_21 ,
V_49 , ( V_31 ) V_56 ) ) {
sprintf ( V_57 , L_3 , V_54 -> type ,
( unsigned int ) V_54 -> V_22 , V_54 -> time . V_24 ) ;
for ( V_16 = 0 ; V_16 < V_14 ; V_16 ++ )
V_55 [ V_16 ] = V_57 [ V_16 ] ;
if ( F_28 ( V_8 -> V_19 . V_21 , V_55 ,
F_27 ( V_55 ) ) )
return 0 ;
}
if ( V_8 -> V_36 ) {
V_8 -> V_39 = true ;
} else
F_10 ( & V_8 -> V_37 ) ;
F_29 ( V_8 ) ;
return 1 ;
}
static int F_30 ( enum V_43 type , T_1 V_22 , int V_6 ,
struct V_23 time , struct V_1 * V_2 )
{
struct V_53 V_58 ;
struct V_7 * V_8 = NULL ;
char V_13 [ V_14 ] ;
T_4 V_49 [ V_14 ] ;
int V_59 , V_16 ;
unsigned int V_5 ;
F_31 ( V_22 , 1000 ) ;
V_5 = F_31 ( V_22 , 100 ) ;
sprintf ( V_13 , L_2 , type , V_5 , V_6 , time . V_24 ) ;
for ( V_16 = 0 ; V_16 < V_14 ; V_16 ++ )
V_49 [ V_16 ] = V_13 [ V_16 ] ;
V_58 . V_22 = V_5 ;
V_58 . type = type ;
V_58 . V_6 = V_6 ;
V_58 . time = time ;
V_58 . V_13 = V_49 ;
F_13 () ;
V_59 = F_32 ( F_26 , & V_42 , & V_58 , & V_8 ) ;
if ( V_59 && ! V_8 -> V_36 ) {
F_11 () ;
F_12 ( V_8 ) ;
} else
F_11 () ;
return 0 ;
}
static T_5 int F_33 ( void )
{
if ( ! F_34 ( V_60 ) )
return 0 ;
if ( ! F_35 () )
return 0 ;
if ( V_61 )
return 0 ;
V_62 . V_30 = F_36 ( 4096 , V_45 ) ;
if ( ! V_62 . V_30 )
return - V_46 ;
V_62 . V_63 = 1024 ;
F_37 ( & V_62 . V_64 ) ;
if ( F_38 ( & V_62 ) ) {
F_20 ( V_62 . V_30 ) ;
V_62 . V_30 = NULL ;
V_62 . V_63 = 0 ;
}
return 0 ;
}
static T_6 void F_39 ( void )
{
}
