static inline void F_1 ( void )
{
unsigned long V_1 , V_2 ;
unsigned long * V_3 , * V_4 , * V_5 ;
int V_6 ;
V_1 = ( ( unsigned long ) & V_1 ) & ( V_7 - 1 ) ;
V_1 = V_7 - V_1 ;
if ( V_1 <= V_8 )
return;
if ( ! F_2 ( & V_1 ) )
return;
F_3 ( V_2 ) ;
F_4 ( & V_9 ) ;
if ( V_1 <= V_8 )
goto V_10;
V_8 = V_1 ;
V_11 . V_12 = 0 ;
V_11 . V_13 = 3 ;
F_5 ( & V_11 ) ;
V_6 = 0 ;
V_5 = & V_1 ;
V_4 = ( unsigned long * )
( ( ( unsigned long ) V_5 & ~ ( V_7 - 1 ) ) + V_7 ) ;
while ( V_6 < V_11 . V_12 ) {
int V_14 = 0 ;
V_15 [ V_6 ] = V_1 ;
V_3 = V_5 ;
for (; V_3 < V_4 && V_6 < V_11 . V_12 ; V_3 ++ ) {
if ( * V_3 == V_16 [ V_6 ] ) {
V_1 = V_15 [ V_6 ++ ] =
( V_4 - V_3 ) * sizeof( unsigned long ) ;
V_14 = 1 ;
V_5 = V_3 + 1 ;
}
}
if ( ! V_14 )
V_6 ++ ;
}
V_10:
F_6 ( & V_9 ) ;
F_7 ( V_2 ) ;
}
static void
F_8 ( unsigned long V_17 , unsigned long V_18 ,
struct V_19 * V_20 , struct V_21 * V_21 )
{
int V_22 ;
F_9 () ;
V_22 = F_10 () ;
if ( F_11 ( V_23 , V_22 ) ++ != 0 )
goto V_10;
F_1 () ;
V_10:
F_11 ( V_23 , V_22 ) -- ;
F_12 () ;
}
static T_1
F_13 ( struct V_24 * V_25 , char T_2 * V_26 ,
T_3 V_27 , T_4 * V_28 )
{
unsigned long * V_29 = V_25 -> V_30 ;
char V_31 [ 64 ] ;
int V_32 ;
V_32 = snprintf ( V_31 , sizeof( V_31 ) , L_1 , * V_29 ) ;
if ( V_32 > sizeof( V_31 ) )
V_32 = sizeof( V_31 ) ;
return F_14 ( V_26 , V_27 , V_28 , V_31 , V_32 ) ;
}
static T_1
F_15 ( struct V_24 * V_25 , const char T_2 * V_26 ,
T_3 V_27 , T_4 * V_28 )
{
long * V_29 = V_25 -> V_30 ;
unsigned long V_33 , V_2 ;
int V_34 ;
int V_22 ;
V_34 = F_16 ( V_26 , V_27 , 10 , & V_33 ) ;
if ( V_34 )
return V_34 ;
F_3 ( V_2 ) ;
V_22 = F_17 () ;
F_11 ( V_23 , V_22 ) ++ ;
F_4 ( & V_9 ) ;
* V_29 = V_33 ;
F_6 ( & V_9 ) ;
F_11 ( V_23 , V_22 ) -- ;
F_7 ( V_2 ) ;
return V_27 ;
}
static void *
F_18 ( struct V_35 * V_36 , T_4 * V_37 )
{
long V_38 = * V_37 - 1 ;
if ( V_38 >= V_11 . V_12 || V_16 [ V_38 ] == V_39 )
return NULL ;
V_36 -> V_40 = ( void * ) V_38 ;
return & V_36 -> V_40 ;
}
static void *
F_19 ( struct V_35 * V_36 , void * V_41 , T_4 * V_37 )
{
( * V_37 ) ++ ;
return F_18 ( V_36 , V_37 ) ;
}
static void * F_20 ( struct V_35 * V_36 , T_4 * V_37 )
{
int V_22 ;
F_21 () ;
V_22 = F_17 () ;
F_11 ( V_23 , V_22 ) ++ ;
F_4 ( & V_9 ) ;
if ( * V_37 == 0 )
return V_42 ;
return F_18 ( V_36 , V_37 ) ;
}
static void F_22 ( struct V_35 * V_36 , void * V_3 )
{
int V_22 ;
F_6 ( & V_9 ) ;
V_22 = F_17 () ;
F_11 ( V_23 , V_22 ) -- ;
F_23 () ;
}
static int F_24 ( struct V_35 * V_36 , long V_6 )
{
unsigned long V_43 = V_16 [ V_6 ] ;
return F_25 ( V_36 , L_2 , ( void * ) V_43 ) ;
}
static void F_26 ( struct V_35 * V_36 )
{
F_27 ( V_36 , L_3
L_4
L_3
L_5
L_6
L_7
L_3 ) ;
}
static int F_28 ( struct V_35 * V_36 , void * V_41 )
{
long V_6 ;
int V_44 ;
if ( V_41 == V_42 ) {
F_25 ( V_36 , L_8
L_9
L_10 ,
V_11 . V_12 - 1 ) ;
if ( ! V_45 && ! V_8 )
F_26 ( V_36 ) ;
return 0 ;
}
V_6 = * ( long * ) V_41 ;
if ( V_6 >= V_11 . V_12 ||
V_16 [ V_6 ] == V_39 )
return 0 ;
if ( V_6 + 1 == V_11 . V_12 ||
V_16 [ V_6 + 1 ] == V_39 )
V_44 = V_15 [ V_6 ] ;
else
V_44 = V_15 [ V_6 ] - V_15 [ V_6 + 1 ] ;
F_25 ( V_36 , L_11 , V_6 , V_15 [ V_6 ] , V_44 ) ;
F_24 ( V_36 , V_6 ) ;
return 0 ;
}
static int F_29 ( struct V_46 * V_46 , struct V_24 * V_24 )
{
return F_30 ( V_24 , & V_47 ) ;
}
static int
F_31 ( struct V_46 * V_46 , struct V_24 * V_24 )
{
return F_32 ( & V_48 , V_49 ,
V_46 , V_24 ) ;
}
int
F_33 ( struct V_50 * V_51 , int V_52 ,
void T_2 * V_53 , T_3 * V_54 ,
T_4 * V_28 )
{
int V_34 ;
F_34 ( & V_55 ) ;
V_34 = F_35 ( V_51 , V_52 , V_53 , V_54 , V_28 ) ;
if ( V_34 || ! V_52 ||
( V_56 == ! ! V_45 ) )
goto V_10;
V_56 = ! ! V_45 ;
if ( V_45 )
F_36 ( & V_48 ) ;
else
F_37 ( & V_48 ) ;
V_10:
F_38 ( & V_55 ) ;
return V_34 ;
}
static T_5 int F_39 ( char * V_57 )
{
if ( strncmp ( V_57 , L_12 , 8 ) == 0 )
strncpy ( V_58 , V_57 + 8 , V_59 ) ;
V_45 = 1 ;
V_56 = 1 ;
return 1 ;
}
static T_5 int F_40 ( void )
{
struct V_60 * V_61 ;
V_61 = F_41 () ;
F_42 ( L_13 , 0644 , V_61 ,
& V_8 , & V_62 ) ;
F_42 ( L_14 , 0444 , V_61 ,
NULL , & V_63 ) ;
F_42 ( L_15 , 0444 , V_61 ,
NULL , & V_64 ) ;
if ( V_58 [ 0 ] )
F_43 ( & V_48 , V_58 , 1 ) ;
if ( V_45 )
F_36 ( & V_48 ) ;
return 0 ;
}
