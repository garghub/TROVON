static inline void
F_1 ( unsigned long V_1 , unsigned long * V_2 )
{
unsigned long V_3 , V_4 ;
unsigned long * V_5 , * V_6 , * V_7 ;
static int V_8 ;
int V_9 = F_2 ( V_8 ) ;
int V_10 ;
V_3 = ( ( unsigned long ) V_2 ) & ( V_11 - 1 ) ;
V_3 = V_11 - V_3 ;
V_3 -= V_9 ;
if ( V_3 <= V_12 )
return;
if ( ! F_3 ( V_2 ) )
return;
F_4 ( V_4 ) ;
F_5 ( & V_13 ) ;
if ( F_6 ( ! V_9 ) )
V_3 -= V_8 ;
if ( V_3 <= V_12 )
goto V_14;
V_12 = V_3 ;
V_15 . V_16 = 0 ;
V_15 . V_17 = 3 ;
F_7 ( & V_15 ) ;
V_18 [ 0 ] = V_1 ;
V_15 . V_16 ++ ;
V_10 = 0 ;
V_7 = V_2 ;
V_6 = ( unsigned long * )
( ( ( unsigned long ) V_7 & ~ ( V_11 - 1 ) ) + V_11 ) ;
while ( V_10 < V_15 . V_16 ) {
int V_19 = 0 ;
V_20 [ V_10 ] = V_3 ;
V_5 = V_7 ;
for (; V_5 < V_6 && V_10 < V_15 . V_16 ; V_5 ++ ) {
if ( * V_5 == V_18 [ V_10 ] ) {
V_3 = V_20 [ V_10 ++ ] =
( V_6 - V_5 ) * sizeof( unsigned long ) ;
V_19 = 1 ;
V_7 = V_5 + 1 ;
if ( F_6 ( ! V_8 ) && V_10 == 1 ) {
V_8 = ( V_5 - V_2 ) *
sizeof( unsigned long ) ;
V_12 -= V_8 ;
}
}
}
if ( ! V_19 )
V_10 ++ ;
}
V_14:
F_8 ( & V_13 ) ;
F_9 ( V_4 ) ;
}
static void
F_10 ( unsigned long V_1 , unsigned long V_21 ,
struct V_22 * V_23 , struct V_24 * V_24 )
{
unsigned long V_2 ;
int V_25 ;
F_11 () ;
V_25 = F_12 () ;
if ( F_13 ( V_26 , V_25 ) ++ != 0 )
goto V_14;
if ( V_27 )
V_1 = V_21 ;
else
V_1 += V_28 ;
F_1 ( V_1 , & V_2 ) ;
V_14:
F_13 ( V_26 , V_25 ) -- ;
F_14 () ;
}
static T_1
F_15 ( struct V_29 * V_30 , char T_2 * V_31 ,
T_3 V_32 , T_4 * V_33 )
{
unsigned long * V_34 = V_30 -> V_35 ;
char V_36 [ 64 ] ;
int V_37 ;
V_37 = snprintf ( V_36 , sizeof( V_36 ) , L_1 , * V_34 ) ;
if ( V_37 > sizeof( V_36 ) )
V_37 = sizeof( V_36 ) ;
return F_16 ( V_31 , V_32 , V_33 , V_36 , V_37 ) ;
}
static T_1
F_17 ( struct V_29 * V_30 , const char T_2 * V_31 ,
T_3 V_32 , T_4 * V_33 )
{
long * V_34 = V_30 -> V_35 ;
unsigned long V_38 , V_4 ;
int V_39 ;
int V_25 ;
V_39 = F_18 ( V_31 , V_32 , 10 , & V_38 ) ;
if ( V_39 )
return V_39 ;
F_4 ( V_4 ) ;
V_25 = F_19 () ;
F_13 ( V_26 , V_25 ) ++ ;
F_5 ( & V_13 ) ;
* V_34 = V_38 ;
F_8 ( & V_13 ) ;
F_13 ( V_26 , V_25 ) -- ;
F_9 ( V_4 ) ;
return V_32 ;
}
static void *
F_20 ( struct V_40 * V_41 , T_4 * V_42 )
{
long V_43 = * V_42 - 1 ;
if ( V_43 >= V_15 . V_16 || V_18 [ V_43 ] == V_44 )
return NULL ;
V_41 -> V_45 = ( void * ) V_43 ;
return & V_41 -> V_45 ;
}
static void *
F_21 ( struct V_40 * V_41 , void * V_46 , T_4 * V_42 )
{
( * V_42 ) ++ ;
return F_20 ( V_41 , V_42 ) ;
}
static void * F_22 ( struct V_40 * V_41 , T_4 * V_42 )
{
int V_25 ;
F_23 () ;
V_25 = F_19 () ;
F_13 ( V_26 , V_25 ) ++ ;
F_5 ( & V_13 ) ;
if ( * V_42 == 0 )
return V_47 ;
return F_20 ( V_41 , V_42 ) ;
}
static void F_24 ( struct V_40 * V_41 , void * V_5 )
{
int V_25 ;
F_8 ( & V_13 ) ;
V_25 = F_19 () ;
F_13 ( V_26 , V_25 ) -- ;
F_25 () ;
}
static int F_26 ( struct V_40 * V_41 , long V_10 )
{
unsigned long V_48 = V_18 [ V_10 ] ;
return F_27 ( V_41 , L_2 , ( void * ) V_48 ) ;
}
static void F_28 ( struct V_40 * V_41 )
{
F_29 ( V_41 , L_3
L_4
L_3
L_5
L_6
L_7
L_3 ) ;
}
static int F_30 ( struct V_40 * V_41 , void * V_46 )
{
long V_10 ;
int V_49 ;
if ( V_46 == V_47 ) {
F_27 ( V_41 , L_8
L_9
L_10 ,
V_15 . V_16 - 1 ) ;
if ( ! V_50 && ! V_12 )
F_28 ( V_41 ) ;
return 0 ;
}
V_10 = * ( long * ) V_46 ;
if ( V_10 >= V_15 . V_16 ||
V_18 [ V_10 ] == V_44 )
return 0 ;
if ( V_10 + 1 == V_15 . V_16 ||
V_18 [ V_10 + 1 ] == V_44 )
V_49 = V_20 [ V_10 ] ;
else
V_49 = V_20 [ V_10 ] - V_20 [ V_10 + 1 ] ;
F_27 ( V_41 , L_11 , V_10 , V_20 [ V_10 ] , V_49 ) ;
F_26 ( V_41 , V_10 ) ;
return 0 ;
}
static int F_31 ( struct V_51 * V_51 , struct V_29 * V_29 )
{
return F_32 ( V_29 , & V_52 ) ;
}
static int
F_33 ( struct V_51 * V_51 , struct V_29 * V_29 )
{
return F_34 ( & V_53 , V_54 ,
V_51 , V_29 ) ;
}
int
F_35 ( struct V_55 * V_56 , int V_57 ,
void T_2 * V_58 , T_3 * V_59 ,
T_4 * V_33 )
{
int V_39 ;
F_36 ( & V_60 ) ;
V_39 = F_37 ( V_56 , V_57 , V_58 , V_59 , V_33 ) ;
if ( V_39 || ! V_57 ||
( V_61 == ! ! V_50 ) )
goto V_14;
V_61 = ! ! V_50 ;
if ( V_50 )
F_38 ( & V_53 ) ;
else
F_39 ( & V_53 ) ;
V_14:
F_40 ( & V_60 ) ;
return V_39 ;
}
static T_5 int F_41 ( char * V_62 )
{
if ( strncmp ( V_62 , L_12 , 8 ) == 0 )
strncpy ( V_63 , V_62 + 8 , V_64 ) ;
V_50 = 1 ;
V_61 = 1 ;
return 1 ;
}
static T_5 int F_42 ( void )
{
struct V_65 * V_66 ;
V_66 = F_43 () ;
if ( ! V_66 )
return 0 ;
F_44 ( L_13 , 0644 , V_66 ,
& V_12 , & V_67 ) ;
F_44 ( L_14 , 0444 , V_66 ,
NULL , & V_68 ) ;
F_44 ( L_15 , 0444 , V_66 ,
NULL , & V_69 ) ;
if ( V_63 [ 0 ] )
F_45 ( & V_53 , V_63 , 1 ) ;
if ( V_50 )
F_38 ( & V_53 ) ;
return 0 ;
}
