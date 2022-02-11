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
int V_33 ;
int V_19 ;
V_33 = F_17 ( V_25 , V_26 , 10 , & V_32 ) ;
if ( V_33 )
return V_33 ;
F_3 ( V_2 ) ;
V_19 = F_18 () ;
F_12 ( V_22 , V_19 ) ++ ;
F_4 ( & V_9 ) ;
* V_28 = V_32 ;
F_6 ( & V_9 ) ;
F_12 ( V_22 , V_19 ) -- ;
F_7 ( V_2 ) ;
return V_26 ;
}
static void *
F_19 ( struct V_34 * V_35 , T_4 * V_36 )
{
long V_37 = * V_36 - 1 ;
if ( V_37 >= V_11 . V_12 || V_16 [ V_37 ] == V_38 )
return NULL ;
V_35 -> V_39 = ( void * ) V_37 ;
return & V_35 -> V_39 ;
}
static void *
F_20 ( struct V_34 * V_35 , void * V_40 , T_4 * V_36 )
{
( * V_36 ) ++ ;
return F_19 ( V_35 , V_36 ) ;
}
static void * F_21 ( struct V_34 * V_35 , T_4 * V_36 )
{
int V_19 ;
F_22 () ;
V_19 = F_18 () ;
F_12 ( V_22 , V_19 ) ++ ;
F_4 ( & V_9 ) ;
if ( * V_36 == 0 )
return V_41 ;
return F_19 ( V_35 , V_36 ) ;
}
static void F_23 ( struct V_34 * V_35 , void * V_3 )
{
int V_19 ;
F_6 ( & V_9 ) ;
V_19 = F_18 () ;
F_12 ( V_22 , V_19 ) -- ;
F_24 () ;
}
static int F_25 ( struct V_34 * V_35 , long V_6 )
{
unsigned long V_42 = V_16 [ V_6 ] ;
return F_26 ( V_35 , L_2 , ( void * ) V_42 ) ;
}
static void F_27 ( struct V_34 * V_35 )
{
F_28 ( V_35 , L_3
L_4
L_3
L_5
L_6
L_7
L_3 ) ;
}
static int F_29 ( struct V_34 * V_35 , void * V_40 )
{
long V_6 ;
int V_43 ;
if ( V_40 == V_41 ) {
F_26 ( V_35 , L_8
L_9
L_10 ,
V_11 . V_12 - 1 ) ;
if ( ! V_44 && ! V_8 )
F_27 ( V_35 ) ;
return 0 ;
}
V_6 = * ( long * ) V_40 ;
if ( V_6 >= V_11 . V_12 ||
V_16 [ V_6 ] == V_38 )
return 0 ;
if ( V_6 + 1 == V_11 . V_12 ||
V_16 [ V_6 + 1 ] == V_38 )
V_43 = V_15 [ V_6 ] ;
else
V_43 = V_15 [ V_6 ] - V_15 [ V_6 + 1 ] ;
F_26 ( V_35 , L_11 , V_6 , V_15 [ V_6 ] , V_43 ) ;
F_25 ( V_35 , V_6 ) ;
return 0 ;
}
static int F_30 ( struct V_45 * V_45 , struct V_23 * V_23 )
{
return F_31 ( V_23 , & V_46 ) ;
}
static int
F_32 ( struct V_45 * V_45 , struct V_23 * V_23 )
{
return F_33 ( & V_47 , V_48 ,
V_45 , V_23 ) ;
}
int
F_34 ( struct V_49 * V_50 , int V_51 ,
void T_2 * V_52 , T_3 * V_53 ,
T_4 * V_27 )
{
int V_33 ;
F_35 ( & V_54 ) ;
V_33 = F_36 ( V_50 , V_51 , V_52 , V_53 , V_27 ) ;
if ( V_33 || ! V_51 ||
( V_55 == ! ! V_44 ) )
goto V_10;
V_55 = ! ! V_44 ;
if ( V_44 )
F_37 ( & V_47 ) ;
else
F_38 ( & V_47 ) ;
V_10:
F_39 ( & V_54 ) ;
return V_33 ;
}
static T_5 int F_40 ( char * V_56 )
{
if ( strncmp ( V_56 , L_12 , 8 ) == 0 )
strncpy ( V_57 , V_56 + 8 , V_58 ) ;
V_44 = 1 ;
V_55 = 1 ;
return 1 ;
}
static T_5 int F_41 ( void )
{
struct V_59 * V_60 ;
V_60 = F_42 () ;
F_43 ( L_13 , 0644 , V_60 ,
& V_8 , & V_61 ) ;
F_43 ( L_14 , 0444 , V_60 ,
NULL , & V_62 ) ;
F_43 ( L_15 , 0444 , V_60 ,
NULL , & V_63 ) ;
if ( V_57 [ 0 ] )
F_44 ( & V_47 , V_57 , 1 ) ;
if ( V_44 )
F_37 ( & V_47 ) ;
return 0 ;
}
