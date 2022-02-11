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
F_8 ( V_21 != & V_22 &&
* ( F_9 ( V_21 ) ) != V_23 ) ;
V_14:
F_10 ( & V_13 ) ;
F_11 ( V_4 ) ;
}
static void
F_12 ( unsigned long V_1 , unsigned long V_24 ,
struct V_25 * V_26 , struct V_27 * V_27 )
{
unsigned long V_2 ;
int V_28 ;
F_13 () ;
V_28 = F_14 () ;
if ( F_15 ( V_29 , V_28 ) ++ != 0 )
goto V_14;
if ( V_30 )
V_1 = V_24 ;
else
V_1 += V_31 ;
F_1 ( V_1 , & V_2 ) ;
V_14:
F_15 ( V_29 , V_28 ) -- ;
F_16 () ;
}
static T_1
F_17 ( struct V_32 * V_33 , char T_2 * V_34 ,
T_3 V_35 , T_4 * V_36 )
{
unsigned long * V_37 = V_33 -> V_38 ;
char V_39 [ 64 ] ;
int V_40 ;
V_40 = snprintf ( V_39 , sizeof( V_39 ) , L_1 , * V_37 ) ;
if ( V_40 > sizeof( V_39 ) )
V_40 = sizeof( V_39 ) ;
return F_18 ( V_34 , V_35 , V_36 , V_39 , V_40 ) ;
}
static T_1
F_19 ( struct V_32 * V_33 , const char T_2 * V_34 ,
T_3 V_35 , T_4 * V_36 )
{
long * V_37 = V_33 -> V_38 ;
unsigned long V_41 , V_4 ;
int V_42 ;
int V_28 ;
V_42 = F_20 ( V_34 , V_35 , 10 , & V_41 ) ;
if ( V_42 )
return V_42 ;
F_4 ( V_4 ) ;
V_28 = F_21 () ;
F_15 ( V_29 , V_28 ) ++ ;
F_5 ( & V_13 ) ;
* V_37 = V_41 ;
F_10 ( & V_13 ) ;
F_15 ( V_29 , V_28 ) -- ;
F_11 ( V_4 ) ;
return V_35 ;
}
static void *
F_22 ( struct V_43 * V_44 , T_4 * V_45 )
{
long V_46 = * V_45 - 1 ;
if ( V_46 >= V_15 . V_16 || V_18 [ V_46 ] == V_47 )
return NULL ;
V_44 -> V_48 = ( void * ) V_46 ;
return & V_44 -> V_48 ;
}
static void *
F_23 ( struct V_43 * V_44 , void * V_49 , T_4 * V_45 )
{
( * V_45 ) ++ ;
return F_22 ( V_44 , V_45 ) ;
}
static void * F_24 ( struct V_43 * V_44 , T_4 * V_45 )
{
int V_28 ;
F_25 () ;
V_28 = F_21 () ;
F_15 ( V_29 , V_28 ) ++ ;
F_5 ( & V_13 ) ;
if ( * V_45 == 0 )
return V_50 ;
return F_22 ( V_44 , V_45 ) ;
}
static void F_26 ( struct V_43 * V_44 , void * V_5 )
{
int V_28 ;
F_10 ( & V_13 ) ;
V_28 = F_21 () ;
F_15 ( V_29 , V_28 ) -- ;
F_27 () ;
}
static int F_28 ( struct V_43 * V_44 , long V_10 )
{
unsigned long V_51 = V_18 [ V_10 ] ;
return F_29 ( V_44 , L_2 , ( void * ) V_51 ) ;
}
static void F_30 ( struct V_43 * V_44 )
{
F_31 ( V_44 , L_3
L_4
L_3
L_5
L_6
L_7
L_3 ) ;
}
static int F_32 ( struct V_43 * V_44 , void * V_49 )
{
long V_10 ;
int V_52 ;
if ( V_49 == V_50 ) {
F_29 ( V_44 , L_8
L_9
L_10 ,
V_15 . V_16 - 1 ) ;
if ( ! V_53 && ! V_12 )
F_30 ( V_44 ) ;
return 0 ;
}
V_10 = * ( long * ) V_49 ;
if ( V_10 >= V_15 . V_16 ||
V_18 [ V_10 ] == V_47 )
return 0 ;
if ( V_10 + 1 == V_15 . V_16 ||
V_18 [ V_10 + 1 ] == V_47 )
V_52 = V_20 [ V_10 ] ;
else
V_52 = V_20 [ V_10 ] - V_20 [ V_10 + 1 ] ;
F_29 ( V_44 , L_11 , V_10 , V_20 [ V_10 ] , V_52 ) ;
F_28 ( V_44 , V_10 ) ;
return 0 ;
}
static int F_33 ( struct V_54 * V_54 , struct V_32 * V_32 )
{
return F_34 ( V_32 , & V_55 ) ;
}
static int
F_35 ( struct V_54 * V_54 , struct V_32 * V_32 )
{
return F_36 ( & V_56 , V_57 ,
V_54 , V_32 ) ;
}
int
F_37 ( struct V_58 * V_59 , int V_60 ,
void T_2 * V_61 , T_3 * V_62 ,
T_4 * V_36 )
{
int V_42 ;
F_38 ( & V_63 ) ;
V_42 = F_39 ( V_59 , V_60 , V_61 , V_62 , V_36 ) ;
if ( V_42 || ! V_60 ||
( V_64 == ! ! V_53 ) )
goto V_14;
V_64 = ! ! V_53 ;
if ( V_53 )
F_40 ( & V_56 ) ;
else
F_41 ( & V_56 ) ;
V_14:
F_42 ( & V_63 ) ;
return V_42 ;
}
static T_5 int F_43 ( char * V_65 )
{
if ( strncmp ( V_65 , L_12 , 8 ) == 0 )
strncpy ( V_66 , V_65 + 8 , V_67 ) ;
V_53 = 1 ;
V_64 = 1 ;
return 1 ;
}
static T_5 int F_44 ( void )
{
struct V_68 * V_69 ;
V_69 = F_45 () ;
if ( ! V_69 )
return 0 ;
F_46 ( L_13 , 0644 , V_69 ,
& V_12 , & V_70 ) ;
F_46 ( L_14 , 0444 , V_69 ,
NULL , & V_71 ) ;
F_46 ( L_15 , 0444 , V_69 ,
NULL , & V_72 ) ;
if ( V_66 [ 0 ] )
F_47 ( & V_56 , V_66 , 1 ) ;
if ( V_53 )
F_40 ( & V_56 ) ;
return 0 ;
}
