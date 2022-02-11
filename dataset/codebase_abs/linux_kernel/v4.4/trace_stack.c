void F_1 ( void )
{
long V_1 ;
int V_2 ;
F_2 ( L_1
L_2 ,
V_3 . V_4 ) ;
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
void __weak
F_3 ( unsigned long V_8 , unsigned long * V_9 )
{
unsigned long V_10 , V_11 ; unsigned long * V_12 , * V_13 , * V_14 ;
static int V_15 ;
int V_16 = F_4 ( V_15 ) ;
int V_1 , V_17 ;
V_10 = ( ( unsigned long ) V_9 ) & ( V_18 - 1 ) ;
V_10 = V_18 - V_10 ;
V_10 -= V_16 ;
if ( V_10 <= V_19 )
return;
if ( ! F_5 ( V_9 ) )
return;
if ( F_6 () )
return;
F_7 ( V_11 ) ;
F_8 ( & V_20 ) ;
F_9 () ;
if ( F_10 ( ! V_16 ) )
V_10 -= V_15 ;
if ( V_10 <= V_19 )
goto V_21;
V_19 = V_10 ;
V_3 . V_4 = 0 ;
V_3 . V_22 = 3 ;
F_11 ( & V_3 ) ;
for ( V_1 = 0 ; V_1 < V_3 . V_4 ; V_1 ++ ) {
if ( V_5 [ V_1 ] == V_8 )
break;
}
V_17 = 0 ;
V_14 = V_9 ;
V_13 = ( unsigned long * )
( ( ( unsigned long ) V_14 & ~ ( V_18 - 1 ) ) + V_18 ) ;
while ( V_1 < V_3 . V_4 ) {
int V_23 = 0 ;
V_7 [ V_17 ] = V_10 ;
V_12 = V_14 ;
for (; V_12 < V_13 && V_1 < V_3 . V_4 ; V_12 ++ ) {
if ( V_5 [ V_1 ] == V_6 )
break;
if ( * V_12 == V_5 [ V_1 ] ) {
V_5 [ V_17 ] = V_5 [ V_1 ++ ] ;
V_10 = V_7 [ V_17 ++ ] =
( V_13 - V_12 ) * sizeof( unsigned long ) ;
V_23 = 1 ;
V_14 = V_12 + 1 ;
if ( F_10 ( ! V_15 ) ) {
V_15 = ( V_12 - V_9 ) *
sizeof( unsigned long ) ;
V_19 -= V_15 ;
}
}
}
if ( ! V_23 )
V_1 ++ ;
}
V_3 . V_4 = V_17 ;
for (; V_17 < V_1 ; V_17 ++ )
V_5 [ V_17 ] = V_6 ;
if ( F_12 ( V_24 ) ) {
F_1 () ;
F_13 () ;
}
V_21:
F_14 () ;
F_15 ( & V_20 ) ;
F_16 ( V_11 ) ;
}
static void
F_17 ( unsigned long V_8 , unsigned long V_25 ,
struct V_26 * V_27 , struct V_28 * V_28 )
{
unsigned long V_9 ;
int V_29 ;
F_18 () ;
V_29 = F_19 () ;
if ( F_20 ( V_30 , V_29 ) ++ != 0 )
goto V_21;
V_8 += V_31 ;
F_3 ( V_8 , & V_9 ) ;
V_21:
F_20 ( V_30 , V_29 ) -- ;
F_21 () ;
}
static T_1
F_22 ( struct V_32 * V_33 , char T_2 * V_34 ,
T_3 V_35 , T_4 * V_36 )
{
unsigned long * V_37 = V_33 -> V_38 ;
char V_39 [ 64 ] ;
int V_40 ;
V_40 = snprintf ( V_39 , sizeof( V_39 ) , L_4 , * V_37 ) ;
if ( V_40 > sizeof( V_39 ) )
V_40 = sizeof( V_39 ) ;
return F_23 ( V_34 , V_35 , V_36 , V_39 , V_40 ) ;
}
static T_1
F_24 ( struct V_32 * V_33 , const char T_2 * V_34 ,
T_3 V_35 , T_4 * V_36 )
{
long * V_37 = V_33 -> V_38 ;
unsigned long V_41 , V_11 ;
int V_42 ;
int V_29 ;
V_42 = F_25 ( V_34 , V_35 , 10 , & V_41 ) ;
if ( V_42 )
return V_42 ;
F_7 ( V_11 ) ;
V_29 = F_26 () ;
F_20 ( V_30 , V_29 ) ++ ;
F_8 ( & V_20 ) ;
* V_37 = V_41 ;
F_15 ( & V_20 ) ;
F_20 ( V_30 , V_29 ) -- ;
F_16 ( V_11 ) ;
return V_35 ;
}
static void *
F_27 ( struct V_43 * V_44 , T_4 * V_45 )
{
long V_46 = * V_45 - 1 ;
if ( V_46 > V_3 . V_4 || V_5 [ V_46 ] == V_6 )
return NULL ;
V_44 -> V_47 = ( void * ) V_46 ;
return & V_44 -> V_47 ;
}
static void *
F_28 ( struct V_43 * V_44 , void * V_48 , T_4 * V_45 )
{
( * V_45 ) ++ ;
return F_27 ( V_44 , V_45 ) ;
}
static void * F_29 ( struct V_43 * V_44 , T_4 * V_45 )
{
int V_29 ;
F_30 () ;
V_29 = F_26 () ;
F_20 ( V_30 , V_29 ) ++ ;
F_8 ( & V_20 ) ;
if ( * V_45 == 0 )
return V_49 ;
return F_27 ( V_44 , V_45 ) ;
}
static void F_31 ( struct V_43 * V_44 , void * V_12 )
{
int V_29 ;
F_15 ( & V_20 ) ;
V_29 = F_26 () ;
F_20 ( V_30 , V_29 ) -- ;
F_32 () ;
}
static void F_33 ( struct V_43 * V_44 , long V_1 )
{
unsigned long V_50 = V_5 [ V_1 ] ;
F_34 ( V_44 , L_5 , ( void * ) V_50 ) ;
}
static void F_35 ( struct V_43 * V_44 )
{
F_36 ( V_44 , L_6
L_7
L_6
L_8
L_9
L_10
L_6 ) ;
}
static int F_37 ( struct V_43 * V_44 , void * V_48 )
{
long V_1 ;
int V_2 ;
if ( V_48 == V_49 ) {
F_34 ( V_44 , L_11
L_12
L_2 ,
V_3 . V_4 ) ;
if ( ! V_51 && ! V_19 )
F_35 ( V_44 ) ;
return 0 ;
}
V_1 = * ( long * ) V_48 ;
if ( V_1 >= V_3 . V_4 ||
V_5 [ V_1 ] == V_6 )
return 0 ;
if ( V_1 + 1 == V_3 . V_4 ||
V_5 [ V_1 + 1 ] == V_6 )
V_2 = V_7 [ V_1 ] ;
else
V_2 = V_7 [ V_1 ] - V_7 [ V_1 + 1 ] ;
F_34 ( V_44 , L_13 , V_1 , V_7 [ V_1 ] , V_2 ) ;
F_33 ( V_44 , V_1 ) ;
return 0 ;
}
static int F_38 ( struct V_52 * V_52 , struct V_32 * V_32 )
{
return F_39 ( V_32 , & V_53 ) ;
}
static int
F_40 ( struct V_52 * V_52 , struct V_32 * V_32 )
{
return F_41 ( & V_54 , V_55 ,
V_52 , V_32 ) ;
}
int
F_42 ( struct V_56 * V_57 , int V_58 ,
void T_2 * V_59 , T_3 * V_60 ,
T_4 * V_36 )
{
int V_42 ;
F_43 ( & V_61 ) ;
V_42 = F_44 ( V_57 , V_58 , V_59 , V_60 , V_36 ) ;
if ( V_42 || ! V_58 ||
( V_62 == ! ! V_51 ) )
goto V_21;
V_62 = ! ! V_51 ;
if ( V_51 )
F_45 ( & V_54 ) ;
else
F_46 ( & V_54 ) ;
V_21:
F_47 ( & V_61 ) ;
return V_42 ;
}
static T_5 int F_48 ( char * V_63 )
{
if ( strncmp ( V_63 , L_14 , 8 ) == 0 )
strncpy ( V_64 , V_63 + 8 , V_65 ) ;
V_51 = 1 ;
V_62 = 1 ;
return 1 ;
}
static T_5 int F_49 ( void )
{
struct V_66 * V_67 ;
V_67 = F_50 () ;
if ( F_51 ( V_67 ) )
return 0 ;
F_52 ( L_15 , 0644 , V_67 ,
& V_19 , & V_68 ) ;
F_52 ( L_16 , 0444 , V_67 ,
NULL , & V_69 ) ;
F_52 ( L_17 , 0444 , V_67 ,
NULL , & V_70 ) ;
if ( V_64 [ 0 ] )
F_53 ( & V_54 , V_64 , 1 ) ;
if ( V_51 )
F_45 ( & V_54 ) ;
return 0 ;
}
