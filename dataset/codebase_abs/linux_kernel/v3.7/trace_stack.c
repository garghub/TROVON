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
if ( F_9 ( ! V_23 || V_24 ) )
return;
F_10 () ;
V_22 = F_11 () ;
if ( F_12 ( V_25 , V_22 ) ++ != 0 )
goto V_10;
F_1 () ;
V_10:
F_12 ( V_25 , V_22 ) -- ;
F_13 () ;
}
static T_1
F_14 ( struct V_26 * V_27 , char T_2 * V_28 ,
T_3 V_29 , T_4 * V_30 )
{
unsigned long * V_31 = V_27 -> V_32 ;
char V_33 [ 64 ] ;
int V_34 ;
V_34 = snprintf ( V_33 , sizeof( V_33 ) , L_1 , * V_31 ) ;
if ( V_34 > sizeof( V_33 ) )
V_34 = sizeof( V_33 ) ;
return F_15 ( V_28 , V_29 , V_30 , V_33 , V_34 ) ;
}
static T_1
F_16 ( struct V_26 * V_27 , const char T_2 * V_28 ,
T_3 V_29 , T_4 * V_30 )
{
long * V_31 = V_27 -> V_32 ;
unsigned long V_35 , V_2 ;
int V_36 ;
int V_22 ;
V_36 = F_17 ( V_28 , V_29 , 10 , & V_35 ) ;
if ( V_36 )
return V_36 ;
F_3 ( V_2 ) ;
V_22 = F_18 () ;
F_12 ( V_25 , V_22 ) ++ ;
F_4 ( & V_9 ) ;
* V_31 = V_35 ;
F_6 ( & V_9 ) ;
F_12 ( V_25 , V_22 ) -- ;
F_7 ( V_2 ) ;
return V_29 ;
}
static void *
F_19 ( struct V_37 * V_38 , T_4 * V_39 )
{
long V_40 = * V_39 - 1 ;
if ( V_40 >= V_11 . V_12 || V_16 [ V_40 ] == V_41 )
return NULL ;
V_38 -> V_42 = ( void * ) V_40 ;
return & V_38 -> V_42 ;
}
static void *
F_20 ( struct V_37 * V_38 , void * V_43 , T_4 * V_39 )
{
( * V_39 ) ++ ;
return F_19 ( V_38 , V_39 ) ;
}
static void * F_21 ( struct V_37 * V_38 , T_4 * V_39 )
{
int V_22 ;
F_22 () ;
V_22 = F_18 () ;
F_12 ( V_25 , V_22 ) ++ ;
F_4 ( & V_9 ) ;
if ( * V_39 == 0 )
return V_44 ;
return F_19 ( V_38 , V_39 ) ;
}
static void F_23 ( struct V_37 * V_38 , void * V_3 )
{
int V_22 ;
F_6 ( & V_9 ) ;
V_22 = F_18 () ;
F_12 ( V_25 , V_22 ) -- ;
F_24 () ;
}
static int F_25 ( struct V_37 * V_38 , long V_6 )
{
unsigned long V_45 = V_16 [ V_6 ] ;
return F_26 ( V_38 , L_2 , ( void * ) V_45 ) ;
}
static void F_27 ( struct V_37 * V_38 )
{
F_28 ( V_38 , L_3
L_4
L_3
L_5
L_6
L_7
L_3 ) ;
}
static int F_29 ( struct V_37 * V_38 , void * V_43 )
{
long V_6 ;
int V_46 ;
if ( V_43 == V_44 ) {
F_26 ( V_38 , L_8
L_9
L_10 ,
V_11 . V_12 - 1 ) ;
if ( ! V_47 && ! V_8 )
F_27 ( V_38 ) ;
return 0 ;
}
V_6 = * ( long * ) V_43 ;
if ( V_6 >= V_11 . V_12 ||
V_16 [ V_6 ] == V_41 )
return 0 ;
if ( V_6 + 1 == V_11 . V_12 ||
V_16 [ V_6 + 1 ] == V_41 )
V_46 = V_15 [ V_6 ] ;
else
V_46 = V_15 [ V_6 ] - V_15 [ V_6 + 1 ] ;
F_26 ( V_38 , L_11 , V_6 , V_15 [ V_6 ] , V_46 ) ;
F_25 ( V_38 , V_6 ) ;
return 0 ;
}
static int F_30 ( struct V_48 * V_48 , struct V_26 * V_26 )
{
return F_31 ( V_26 , & V_49 ) ;
}
static int
F_32 ( struct V_48 * V_48 , struct V_26 * V_26 )
{
return F_33 ( & V_50 , V_51 ,
V_48 , V_26 ) ;
}
int
F_34 ( struct V_52 * V_53 , int V_54 ,
void T_2 * V_55 , T_3 * V_56 ,
T_4 * V_30 )
{
int V_36 ;
F_35 ( & V_57 ) ;
V_36 = F_36 ( V_53 , V_54 , V_55 , V_56 , V_30 ) ;
if ( V_36 || ! V_54 ||
( V_58 == ! ! V_47 ) )
goto V_10;
V_58 = ! ! V_47 ;
if ( V_47 )
F_37 ( & V_50 ) ;
else
F_38 ( & V_50 ) ;
V_10:
F_39 ( & V_57 ) ;
return V_36 ;
}
static T_5 int F_40 ( char * V_59 )
{
if ( strncmp ( V_59 , L_12 , 8 ) == 0 )
strncpy ( V_60 , V_59 + 8 , V_61 ) ;
V_47 = 1 ;
V_58 = 1 ;
return 1 ;
}
static T_5 int F_41 ( void )
{
struct V_62 * V_63 ;
V_63 = F_42 () ;
F_43 ( L_13 , 0644 , V_63 ,
& V_8 , & V_64 ) ;
F_43 ( L_14 , 0444 , V_63 ,
NULL , & V_65 ) ;
F_43 ( L_15 , 0444 , V_63 ,
NULL , & V_66 ) ;
if ( V_60 [ 0 ] )
F_44 ( & V_50 , V_60 , 1 ) ;
if ( V_47 )
F_37 ( & V_50 ) ;
return 0 ;
}
