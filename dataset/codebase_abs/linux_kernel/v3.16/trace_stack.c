static inline void F_1 ( void )
{
long V_1 ;
int V_2 ;
F_2 ( L_1
L_2 ,
V_3 . V_4 - 1 ) ;
for ( V_1 = 0 ; V_1 < V_3 . V_4 ; V_1 ++ ) {
if ( V_5 [ V_1 ] == V_6 )
break;
if ( V_1 + 1 == V_3 . V_4 ||
V_5 [ V_1 + 1 ] == V_6 )
V_2 = V_7 [ V_1 ] ;
else
V_2 = V_7 [ V_1 ] - V_7 [ V_1 + 1 ] ;
F_2 ( L_3 , V_1 , V_7 [ V_1 ] ,
V_2 , ( void * ) V_5 [ V_1 ] ) ;
}
}
static inline void
F_3 ( unsigned long V_8 , unsigned long * V_9 )
{
unsigned long V_10 , V_11 ; unsigned long * V_12 , * V_13 , * V_14 ;
static int V_15 ;
int V_16 = F_4 ( V_15 ) ;
int V_1 ;
V_10 = ( ( unsigned long ) V_9 ) & ( V_17 - 1 ) ;
V_10 = V_17 - V_10 ;
V_10 -= V_16 ;
if ( V_10 <= V_18 )
return;
if ( ! F_5 ( V_9 ) )
return;
F_6 ( V_11 ) ;
F_7 ( & V_19 ) ;
if ( F_8 ( ! V_16 ) )
V_10 -= V_15 ;
if ( V_10 <= V_18 )
goto V_20;
V_18 = V_10 ;
V_3 . V_4 = 0 ;
if ( F_9 () )
V_3 . V_21 = 4 ;
else
V_3 . V_21 = 3 ;
F_10 ( & V_3 ) ;
V_5 [ 0 ] = V_8 ;
V_3 . V_4 ++ ;
V_1 = 0 ;
V_14 = V_9 ;
V_13 = ( unsigned long * )
( ( ( unsigned long ) V_14 & ~ ( V_17 - 1 ) ) + V_17 ) ;
while ( V_1 < V_3 . V_4 ) {
int V_22 = 0 ;
V_7 [ V_1 ] = V_10 ;
V_12 = V_14 ;
for (; V_12 < V_13 && V_1 < V_3 . V_4 ; V_12 ++ ) {
if ( * V_12 == V_5 [ V_1 ] ) {
V_10 = V_7 [ V_1 ++ ] =
( V_13 - V_12 ) * sizeof( unsigned long ) ;
V_22 = 1 ;
V_14 = V_12 + 1 ;
if ( F_8 ( ! V_15 ) && V_1 == 1 ) {
V_15 = ( V_12 - V_9 ) *
sizeof( unsigned long ) ;
V_18 -= V_15 ;
}
}
}
if ( ! V_22 )
V_1 ++ ;
}
if ( ( V_23 != & V_24 &&
* ( F_11 ( V_23 ) ) != V_25 ) ) {
F_1 () ;
F_12 () ;
}
V_20:
F_13 ( & V_19 ) ;
F_14 ( V_11 ) ;
}
static void
F_15 ( unsigned long V_8 , unsigned long V_26 ,
struct V_27 * V_28 , struct V_29 * V_29 )
{
unsigned long V_9 ;
int V_30 ;
F_16 () ;
V_30 = F_17 () ;
if ( F_18 ( V_31 , V_30 ) ++ != 0 )
goto V_20;
if ( V_32 )
V_8 = V_26 ;
else
V_8 += V_33 ;
F_3 ( V_8 , & V_9 ) ;
V_20:
F_18 ( V_31 , V_30 ) -- ;
F_19 () ;
}
static T_1
F_20 ( struct V_34 * V_35 , char T_2 * V_36 ,
T_3 V_37 , T_4 * V_38 )
{
unsigned long * V_39 = V_35 -> V_40 ;
char V_41 [ 64 ] ;
int V_42 ;
V_42 = snprintf ( V_41 , sizeof( V_41 ) , L_4 , * V_39 ) ;
if ( V_42 > sizeof( V_41 ) )
V_42 = sizeof( V_41 ) ;
return F_21 ( V_36 , V_37 , V_38 , V_41 , V_42 ) ;
}
static T_1
F_22 ( struct V_34 * V_35 , const char T_2 * V_36 ,
T_3 V_37 , T_4 * V_38 )
{
long * V_39 = V_35 -> V_40 ;
unsigned long V_43 , V_11 ;
int V_44 ;
int V_30 ;
V_44 = F_23 ( V_36 , V_37 , 10 , & V_43 ) ;
if ( V_44 )
return V_44 ;
F_6 ( V_11 ) ;
V_30 = F_24 () ;
F_18 ( V_31 , V_30 ) ++ ;
F_7 ( & V_19 ) ;
* V_39 = V_43 ;
F_13 ( & V_19 ) ;
F_18 ( V_31 , V_30 ) -- ;
F_14 ( V_11 ) ;
return V_37 ;
}
static void *
F_25 ( struct V_45 * V_46 , T_4 * V_47 )
{
long V_48 = * V_47 - 1 ;
if ( V_48 >= V_3 . V_4 || V_5 [ V_48 ] == V_6 )
return NULL ;
V_46 -> V_49 = ( void * ) V_48 ;
return & V_46 -> V_49 ;
}
static void *
F_26 ( struct V_45 * V_46 , void * V_50 , T_4 * V_47 )
{
( * V_47 ) ++ ;
return F_25 ( V_46 , V_47 ) ;
}
static void * F_27 ( struct V_45 * V_46 , T_4 * V_47 )
{
int V_30 ;
F_28 () ;
V_30 = F_24 () ;
F_18 ( V_31 , V_30 ) ++ ;
F_7 ( & V_19 ) ;
if ( * V_47 == 0 )
return V_51 ;
return F_25 ( V_46 , V_47 ) ;
}
static void F_29 ( struct V_45 * V_46 , void * V_12 )
{
int V_30 ;
F_13 ( & V_19 ) ;
V_30 = F_24 () ;
F_18 ( V_31 , V_30 ) -- ;
F_30 () ;
}
static int F_31 ( struct V_45 * V_46 , long V_1 )
{
unsigned long V_52 = V_5 [ V_1 ] ;
return F_32 ( V_46 , L_5 , ( void * ) V_52 ) ;
}
static void F_33 ( struct V_45 * V_46 )
{
F_34 ( V_46 , L_6
L_7
L_6
L_8
L_9
L_10
L_6 ) ;
}
static int F_35 ( struct V_45 * V_46 , void * V_50 )
{
long V_1 ;
int V_2 ;
if ( V_50 == V_51 ) {
F_32 ( V_46 , L_11
L_12
L_2 ,
V_3 . V_4 - 1 ) ;
if ( ! V_53 && ! V_18 )
F_33 ( V_46 ) ;
return 0 ;
}
V_1 = * ( long * ) V_50 ;
if ( V_1 >= V_3 . V_4 ||
V_5 [ V_1 ] == V_6 )
return 0 ;
if ( V_1 + 1 == V_3 . V_4 ||
V_5 [ V_1 + 1 ] == V_6 )
V_2 = V_7 [ V_1 ] ;
else
V_2 = V_7 [ V_1 ] - V_7 [ V_1 + 1 ] ;
F_32 ( V_46 , L_13 , V_1 , V_7 [ V_1 ] , V_2 ) ;
F_31 ( V_46 , V_1 ) ;
return 0 ;
}
static int F_36 ( struct V_54 * V_54 , struct V_34 * V_34 )
{
return F_37 ( V_34 , & V_55 ) ;
}
static int
F_38 ( struct V_54 * V_54 , struct V_34 * V_34 )
{
return F_39 ( & V_56 , V_57 ,
V_54 , V_34 ) ;
}
int
F_40 ( struct V_58 * V_59 , int V_60 ,
void T_2 * V_61 , T_3 * V_62 ,
T_4 * V_38 )
{
int V_44 ;
F_41 ( & V_63 ) ;
V_44 = F_42 ( V_59 , V_60 , V_61 , V_62 , V_38 ) ;
if ( V_44 || ! V_60 ||
( V_64 == ! ! V_53 ) )
goto V_20;
V_64 = ! ! V_53 ;
if ( V_53 )
F_43 ( & V_56 ) ;
else
F_44 ( & V_56 ) ;
V_20:
F_45 ( & V_63 ) ;
return V_44 ;
}
static T_5 int F_46 ( char * V_65 )
{
if ( strncmp ( V_65 , L_14 , 8 ) == 0 )
strncpy ( V_66 , V_65 + 8 , V_67 ) ;
V_53 = 1 ;
V_64 = 1 ;
return 1 ;
}
static T_5 int F_47 ( void )
{
struct V_68 * V_69 ;
V_69 = F_48 () ;
if ( ! V_69 )
return 0 ;
F_49 ( L_15 , 0644 , V_69 ,
& V_18 , & V_70 ) ;
F_49 ( L_16 , 0444 , V_69 ,
NULL , & V_71 ) ;
F_49 ( L_17 , 0444 , V_69 ,
NULL , & V_72 ) ;
if ( V_66 [ 0 ] )
F_50 ( & V_56 , V_66 , 1 ) ;
if ( V_53 )
F_43 ( & V_56 ) ;
return 0 ;
}
