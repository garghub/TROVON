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
static int F_4 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
T_2 V_11 = V_12 ;
char V_13 [ V_14 ] , V_15 ;
int V_16 ;
int V_17 ;
unsigned int V_5 ;
unsigned long time , V_18 ;
if ( F_5 ( V_8 -> V_19 . V_20 , V_11 ) )
return 0 ;
for ( V_16 = 0 ; V_16 < V_14 ; V_16 ++ )
V_13 [ V_16 ] = V_8 -> V_19 . V_21 [ V_16 ] ;
if ( sscanf ( V_13 , L_1 ,
& V_10 -> type , & V_5 , & V_17 , & time , & V_15 ) == 5 ) {
V_10 -> V_22 = F_3 ( time , V_5 , V_17 ) ;
V_10 -> V_5 = V_5 ;
V_10 -> V_6 = V_17 ;
V_10 -> time . V_23 = time ;
V_10 -> time . V_24 = 0 ;
if ( V_15 == 'C' )
V_10 -> V_25 = true ;
else
V_10 -> V_25 = false ;
V_10 -> V_26 = 0 ;
} else if ( sscanf ( V_13 , L_2 ,
& V_10 -> type , & V_5 , & V_17 , & time ) == 4 ) {
V_10 -> V_22 = F_3 ( time , V_5 , V_17 ) ;
V_10 -> V_5 = V_5 ;
V_10 -> V_6 = V_17 ;
V_10 -> time . V_23 = time ;
V_10 -> time . V_24 = 0 ;
V_10 -> V_25 = false ;
V_10 -> V_26 = 0 ;
} else if ( sscanf ( V_13 , L_3 ,
& V_10 -> type , & V_5 , & time ) == 3 ) {
V_10 -> V_22 = F_3 ( time , V_5 , 0 ) ;
V_10 -> V_5 = V_5 ;
V_10 -> V_6 = 0 ;
V_10 -> time . V_23 = time ;
V_10 -> time . V_24 = 0 ;
V_10 -> V_25 = false ;
V_10 -> V_26 = 0 ;
} else
return 0 ;
V_8 -> V_19 . V_27 = 1024 ;
F_6 ( V_8 , & V_8 -> V_19 . V_28 ,
& V_8 -> V_19 . V_27 , V_8 -> V_19 . V_29 ) ;
V_18 = V_8 -> V_19 . V_27 ;
memcpy ( V_10 -> V_30 , V_8 -> V_19 . V_29 ,
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
static inline int F_9 ( struct V_7 * V_8 ,
bool V_38 )
{
if ( V_8 -> V_39 ) {
F_10 ( & V_8 -> V_37 ) ;
F_11 () ;
F_12 ( V_8 ) ;
if ( F_13 () )
return - V_40 ;
} else if ( V_38 )
V_8 -> V_36 = false ;
return 0 ;
}
static int F_14 ( struct V_7 * V_32 ,
struct V_7 * V_33 ,
struct V_34 * V_35 , bool V_41 )
{
int V_42 = F_9 ( V_32 , true ) ;
if ( V_42 )
return V_42 ;
if ( V_41 )
V_42 = F_9 ( V_33 , & V_33 -> V_37 != V_35 ) ;
return V_42 ;
}
static int F_15 ( struct V_9 * V_10 )
{
struct V_7 * * V_32 = (struct V_7 * * ) & V_10 -> V_2 -> V_3 ;
struct V_7 * V_8 , * V_43 ;
struct V_34 * V_35 = & V_44 ;
int V_18 = 0 ;
int V_42 ;
if ( ! * V_32 ) {
F_16 (entry, n, head, list) {
F_8 ( V_8 , V_43 , V_35 ) ;
V_18 = F_4 ( V_8 , V_10 ) ;
V_42 = F_14 ( V_8 , V_43 , V_35 ,
V_18 < 0 ) ;
if ( V_42 )
return V_42 ;
if ( V_18 )
break;
}
* V_32 = V_43 ;
return V_18 ;
}
F_17 ((*pos), n, head, list) {
F_8 ( ( * V_32 ) , V_43 , V_35 ) ;
V_18 = F_4 ( ( * V_32 ) , V_10 ) ;
V_42 = F_14 ( ( * V_32 ) , V_43 , V_35 , V_18 < 0 ) ;
if ( V_42 )
return V_42 ;
if ( V_18 )
break;
}
* V_32 = V_43 ;
return V_18 ;
}
static T_3 F_18 ( struct V_9 * V_10 )
{
T_3 V_18 ;
V_10 -> V_30 = F_19 ( V_45 , V_46 ) ;
if ( ! V_10 -> V_30 )
return - V_47 ;
if ( F_13 () ) {
V_18 = - V_40 ;
goto V_48;
}
V_18 = F_15 ( V_10 ) ;
F_11 () ;
V_48:
if ( V_18 <= 0 ) {
F_20 ( V_10 -> V_30 ) ;
V_10 -> V_30 = NULL ;
}
return V_18 ;
}
static int F_21 ( struct V_9 * V_10 )
{
char V_13 [ V_14 ] ;
T_4 V_49 [ V_14 ] ;
T_2 V_11 = V_12 ;
int V_16 , V_42 = 0 ;
V_10 -> time . V_23 = F_22 () ;
V_10 -> time . V_24 = 0 ;
V_10 -> V_22 = F_3 ( V_10 -> time . V_23 , V_10 -> V_5 ,
V_10 -> V_6 ) ;
snprintf ( V_13 , sizeof( V_13 ) , L_1 ,
V_10 -> type , V_10 -> V_5 , V_10 -> V_6 ,
V_10 -> time . V_23 , V_10 -> V_25 ? 'C' : 'D' ) ;
for ( V_16 = 0 ; V_16 < V_14 ; V_16 ++ )
V_49 [ V_16 ] = V_13 [ V_16 ] ;
V_42 = F_23 ( V_49 , V_11 , V_50 ,
! F_24 ( V_10 -> V_51 ) ,
V_10 -> V_18 , V_10 -> V_2 -> V_30 ) ;
if ( V_10 -> V_51 == V_52 )
F_25 () ;
return V_42 ;
}
static int F_26 ( struct V_7 * V_8 , void * V_3 )
{
struct V_53 * V_54 = V_3 ;
T_2 V_11 = V_12 ;
T_4 V_55 [ V_14 ] ;
T_4 * V_49 = V_54 -> V_13 ;
unsigned long V_56 = F_27 ( V_54 -> V_13 ) ;
char V_57 [ V_14 ] ;
int V_16 ;
if ( F_5 ( V_8 -> V_19 . V_20 , V_11 ) )
return 0 ;
if ( F_28 ( V_8 -> V_19 . V_21 ,
V_49 , ( V_31 ) V_56 ) ) {
snprintf ( V_57 , sizeof( V_57 ) , L_3 ,
V_54 -> V_10 -> type , V_54 -> V_10 -> V_5 ,
V_54 -> V_10 -> time . V_23 ) ;
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
static int F_30 ( struct V_9 * V_10 )
{
struct V_53 V_58 ;
struct V_7 * V_8 = NULL ;
char V_13 [ V_14 ] ;
T_4 V_49 [ V_14 ] ;
int V_59 , V_16 ;
snprintf ( V_13 , sizeof( V_13 ) , L_2 ,
V_10 -> type , V_10 -> V_5 , V_10 -> V_6 ,
V_10 -> time . V_23 ) ;
for ( V_16 = 0 ; V_16 < V_14 ; V_16 ++ )
V_49 [ V_16 ] = V_13 [ V_16 ] ;
V_58 . V_10 = V_10 ;
V_58 . V_13 = V_49 ;
if ( F_13 () )
return - V_40 ;
V_59 = F_31 ( F_26 , & V_44 , & V_58 , & V_8 ) ;
if ( V_59 && ! V_8 -> V_36 ) {
F_11 () ;
F_12 ( V_8 ) ;
} else
F_11 () ;
return 0 ;
}
static T_5 int F_32 ( void )
{
if ( ! F_33 ( V_60 ) )
return 0 ;
if ( ! F_34 () )
return 0 ;
if ( V_61 )
return 0 ;
V_62 . V_30 = F_35 ( 4096 , V_46 ) ;
if ( ! V_62 . V_30 )
return - V_47 ;
V_62 . V_63 = 1024 ;
F_36 ( & V_62 . V_64 ) ;
if ( F_37 ( & V_62 ) ) {
F_20 ( V_62 . V_30 ) ;
V_62 . V_30 = NULL ;
V_62 . V_63 = 0 ;
}
return 0 ;
}
static T_6 void F_38 ( void )
{
if ( ! V_62 . V_63 )
return;
F_39 ( & V_62 ) ;
F_20 ( V_62 . V_30 ) ;
V_62 . V_30 = NULL ;
V_62 . V_63 = 0 ;
}
