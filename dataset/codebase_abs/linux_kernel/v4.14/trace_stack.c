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
if ( F_9 ( ! V_16 ) )
V_10 -= V_15 ;
if ( V_10 <= V_19 )
goto V_21;
V_19 = V_10 ;
V_3 . V_4 = 0 ;
V_3 . V_22 = 3 ;
F_10 ( & V_3 ) ;
for ( V_1 = 0 ; V_1 < V_3 . V_4 ; V_1 ++ ) {
if ( V_5 [ V_1 ] == V_8 )
break;
}
if ( V_1 == V_3 . V_4 )
V_1 = 0 ;
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
if ( ( F_11 ( * V_12 ) ) == V_5 [ V_1 ] ) {
V_5 [ V_17 ] = V_5 [ V_1 ++ ] ;
V_10 = V_7 [ V_17 ++ ] =
( V_13 - V_12 ) * sizeof( unsigned long ) ;
V_23 = 1 ;
V_14 = V_12 + 1 ;
if ( F_9 ( ! V_15 ) ) {
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
F_14 ( & V_20 ) ;
F_15 ( V_11 ) ;
}
static void
F_16 ( unsigned long V_8 , unsigned long V_25 ,
struct V_26 * V_27 , struct V_28 * V_28 )
{
unsigned long V_9 ;
F_17 () ;
F_18 ( V_29 ) ;
if ( F_19 ( V_29 ) != 1 )
goto V_21;
V_8 += V_30 ;
F_3 ( V_8 , & V_9 ) ;
V_21:
F_20 ( V_29 ) ;
F_21 () ;
}
static T_1
F_22 ( struct V_31 * V_32 , char T_2 * V_33 ,
T_3 V_34 , T_4 * V_35 )
{
unsigned long * V_36 = V_32 -> V_37 ;
char V_38 [ 64 ] ;
int V_39 ;
V_39 = snprintf ( V_38 , sizeof( V_38 ) , L_4 , * V_36 ) ;
if ( V_39 > sizeof( V_38 ) )
V_39 = sizeof( V_38 ) ;
return F_23 ( V_33 , V_34 , V_35 , V_38 , V_39 ) ;
}
static T_1
F_24 ( struct V_31 * V_32 , const char T_2 * V_33 ,
T_3 V_34 , T_4 * V_35 )
{
long * V_36 = V_32 -> V_37 ;
unsigned long V_40 , V_11 ;
int V_41 ;
V_41 = F_25 ( V_33 , V_34 , 10 , & V_40 ) ;
if ( V_41 )
return V_41 ;
F_7 ( V_11 ) ;
F_18 ( V_29 ) ;
F_8 ( & V_20 ) ;
* V_36 = V_40 ;
F_14 ( & V_20 ) ;
F_20 ( V_29 ) ;
F_15 ( V_11 ) ;
return V_34 ;
}
static void *
F_26 ( struct V_42 * V_43 , T_4 * V_44 )
{
long V_45 = * V_44 - 1 ;
if ( V_45 > V_3 . V_4 || V_5 [ V_45 ] == V_6 )
return NULL ;
V_43 -> V_46 = ( void * ) V_45 ;
return & V_43 -> V_46 ;
}
static void *
F_27 ( struct V_42 * V_43 , void * V_47 , T_4 * V_44 )
{
( * V_44 ) ++ ;
return F_26 ( V_43 , V_44 ) ;
}
static void * F_28 ( struct V_42 * V_43 , T_4 * V_44 )
{
F_29 () ;
F_18 ( V_29 ) ;
F_8 ( & V_20 ) ;
if ( * V_44 == 0 )
return V_48 ;
return F_26 ( V_43 , V_44 ) ;
}
static void F_30 ( struct V_42 * V_43 , void * V_12 )
{
F_14 ( & V_20 ) ;
F_20 ( V_29 ) ;
F_31 () ;
}
static void F_32 ( struct V_42 * V_43 , long V_1 )
{
unsigned long V_49 = V_5 [ V_1 ] ;
F_33 ( V_43 , L_5 , ( void * ) V_49 ) ;
}
static void F_34 ( struct V_42 * V_43 )
{
F_35 ( V_43 , L_6
L_7
L_6
L_8
L_9
L_10
L_6 ) ;
}
static int F_36 ( struct V_42 * V_43 , void * V_47 )
{
long V_1 ;
int V_2 ;
if ( V_47 == V_48 ) {
F_33 ( V_43 , L_11
L_12
L_2 ,
V_3 . V_4 ) ;
if ( ! V_50 && ! V_19 )
F_34 ( V_43 ) ;
return 0 ;
}
V_1 = * ( long * ) V_47 ;
if ( V_1 >= V_3 . V_4 ||
V_5 [ V_1 ] == V_6 )
return 0 ;
if ( V_1 + 1 == V_3 . V_4 ||
V_5 [ V_1 + 1 ] == V_6 )
V_2 = V_7 [ V_1 ] ;
else
V_2 = V_7 [ V_1 ] - V_7 [ V_1 + 1 ] ;
F_33 ( V_43 , L_13 , V_1 , V_7 [ V_1 ] , V_2 ) ;
F_32 ( V_43 , V_1 ) ;
return 0 ;
}
static int F_37 ( struct V_51 * V_51 , struct V_31 * V_31 )
{
return F_38 ( V_31 , & V_52 ) ;
}
static int
F_39 ( struct V_51 * V_51 , struct V_31 * V_31 )
{
struct V_26 * V_53 = V_51 -> V_54 ;
return F_40 ( V_53 , V_55 ,
V_51 , V_31 ) ;
}
int
F_41 ( struct V_56 * V_57 , int V_58 ,
void T_2 * V_59 , T_3 * V_60 ,
T_4 * V_35 )
{
int V_41 ;
F_42 ( & V_61 ) ;
V_41 = F_43 ( V_57 , V_58 , V_59 , V_60 , V_35 ) ;
if ( V_41 || ! V_58 ||
( V_62 == ! ! V_50 ) )
goto V_21;
V_62 = ! ! V_50 ;
if ( V_50 )
F_44 ( & V_63 ) ;
else
F_45 ( & V_63 ) ;
V_21:
F_46 ( & V_61 ) ;
return V_41 ;
}
static T_5 int F_47 ( char * V_64 )
{
if ( strncmp ( V_64 , L_14 , 8 ) == 0 )
strncpy ( V_65 , V_64 + 8 , V_66 ) ;
V_50 = 1 ;
V_62 = 1 ;
return 1 ;
}
static T_5 int F_48 ( void )
{
struct V_67 * V_68 ;
V_68 = F_49 () ;
if ( F_50 ( V_68 ) )
return 0 ;
F_51 ( L_15 , 0644 , V_68 ,
& V_19 , & V_69 ) ;
F_51 ( L_16 , 0444 , V_68 ,
NULL , & V_70 ) ;
#ifdef F_52
F_51 ( L_17 , 0444 , V_68 ,
& V_63 , & V_71 ) ;
#endif
if ( V_65 [ 0 ] )
F_53 ( & V_63 , V_65 , 1 ) ;
if ( V_50 )
F_44 ( & V_63 ) ;
return 0 ;
}
