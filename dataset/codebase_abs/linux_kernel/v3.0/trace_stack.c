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
F_8 ( unsigned long V_17 , unsigned long V_18 )
{
int V_19 ;
if ( F_9 ( ! V_20 || V_21 ) )
return;
F_10 () ;
V_19 = F_11 () ;
if ( F_12 ( V_22 , V_19 ) ++ != 0 )
goto V_10;
F_1 () ;
V_10:
F_12 ( V_22 , V_19 ) -- ;
F_13 () ;
}
static T_1
F_14 ( struct V_23 * V_24 , char T_2 * V_25 ,
T_3 V_26 , T_4 * V_27 )
{
unsigned long * V_28 = V_24 -> V_29 ;
char V_30 [ 64 ] ;
int V_31 ;
V_31 = snprintf ( V_30 , sizeof( V_30 ) , L_1 , * V_28 ) ;
if ( V_31 > sizeof( V_30 ) )
V_31 = sizeof( V_30 ) ;
return F_15 ( V_25 , V_26 , V_27 , V_30 , V_31 ) ;
}
static T_1
F_16 ( struct V_23 * V_24 , const char T_2 * V_25 ,
T_3 V_26 , T_4 * V_27 )
{
long * V_28 = V_24 -> V_29 ;
unsigned long V_32 , V_2 ;
char V_30 [ 64 ] ;
int V_33 ;
int V_19 ;
if ( V_26 >= sizeof( V_30 ) )
return - V_34 ;
if ( F_17 ( & V_30 , V_25 , V_26 ) )
return - V_35 ;
V_30 [ V_26 ] = 0 ;
V_33 = F_18 ( V_30 , 10 , & V_32 ) ;
if ( V_33 < 0 )
return V_33 ;
F_3 ( V_2 ) ;
V_19 = F_19 () ;
F_12 ( V_22 , V_19 ) ++ ;
F_4 ( & V_9 ) ;
* V_28 = V_32 ;
F_6 ( & V_9 ) ;
F_12 ( V_22 , V_19 ) -- ;
F_7 ( V_2 ) ;
return V_26 ;
}
static void *
F_20 ( struct V_36 * V_37 , T_4 * V_38 )
{
long V_39 = * V_38 - 1 ;
if ( V_39 >= V_11 . V_12 || V_16 [ V_39 ] == V_40 )
return NULL ;
V_37 -> V_41 = ( void * ) V_39 ;
return & V_37 -> V_41 ;
}
static void *
F_21 ( struct V_36 * V_37 , void * V_42 , T_4 * V_38 )
{
( * V_38 ) ++ ;
return F_20 ( V_37 , V_38 ) ;
}
static void * F_22 ( struct V_36 * V_37 , T_4 * V_38 )
{
int V_19 ;
F_23 () ;
V_19 = F_19 () ;
F_12 ( V_22 , V_19 ) ++ ;
F_4 ( & V_9 ) ;
if ( * V_38 == 0 )
return V_43 ;
return F_20 ( V_37 , V_38 ) ;
}
static void F_24 ( struct V_36 * V_37 , void * V_3 )
{
int V_19 ;
F_6 ( & V_9 ) ;
V_19 = F_19 () ;
F_12 ( V_22 , V_19 ) -- ;
F_25 () ;
}
static int F_26 ( struct V_36 * V_37 , long V_6 )
{
unsigned long V_44 = V_16 [ V_6 ] ;
return F_27 ( V_37 , L_2 , ( void * ) V_44 ) ;
}
static void F_28 ( struct V_36 * V_37 )
{
F_29 ( V_37 , L_3
L_4
L_3
L_5
L_6
L_7
L_3 ) ;
}
static int F_30 ( struct V_36 * V_37 , void * V_42 )
{
long V_6 ;
int V_45 ;
if ( V_42 == V_43 ) {
F_27 ( V_37 , L_8
L_9
L_10 ,
V_11 . V_12 - 1 ) ;
if ( ! V_46 && ! V_8 )
F_28 ( V_37 ) ;
return 0 ;
}
V_6 = * ( long * ) V_42 ;
if ( V_6 >= V_11 . V_12 ||
V_16 [ V_6 ] == V_40 )
return 0 ;
if ( V_6 + 1 == V_11 . V_12 ||
V_16 [ V_6 + 1 ] == V_40 )
V_45 = V_15 [ V_6 ] ;
else
V_45 = V_15 [ V_6 ] - V_15 [ V_6 + 1 ] ;
F_27 ( V_37 , L_11 , V_6 , V_15 [ V_6 ] , V_45 ) ;
F_26 ( V_37 , V_6 ) ;
return 0 ;
}
static int F_31 ( struct V_47 * V_47 , struct V_23 * V_23 )
{
return F_32 ( V_23 , & V_48 ) ;
}
int
F_33 ( struct V_49 * V_50 , int V_51 ,
void T_2 * V_52 , T_3 * V_53 ,
T_4 * V_27 )
{
int V_33 ;
F_34 ( & V_54 ) ;
V_33 = F_35 ( V_50 , V_51 , V_52 , V_53 , V_27 ) ;
if ( V_33 || ! V_51 ||
( V_55 == ! ! V_46 ) )
goto V_10;
V_55 = ! ! V_46 ;
if ( V_46 )
F_36 ( & V_56 ) ;
else
F_37 ( & V_56 ) ;
V_10:
F_38 ( & V_54 ) ;
return V_33 ;
}
static T_5 int F_39 ( char * V_57 )
{
V_46 = 1 ;
V_55 = 1 ;
return 1 ;
}
static T_5 int F_40 ( void )
{
struct V_58 * V_59 ;
V_59 = F_41 () ;
F_42 ( L_12 , 0644 , V_59 ,
& V_8 , & V_60 ) ;
F_42 ( L_13 , 0444 , V_59 ,
NULL , & V_61 ) ;
if ( V_46 )
F_36 ( & V_56 ) ;
return 0 ;
}
