int F_1 ( int V_1 )
{
int V_2 = - 1 ;
V_3 = F_2 ( V_1 ) ;
if ( V_3 != NULL ) {
V_4 = V_1 ;
F_3 ( V_3 ) ;
V_2 = 0 ;
}
return V_2 ;
}
static int F_4 ( struct V_5 * V_6 ,
T_1 V_7 , void * V_8 , void * * V_9 )
{
char * V_10 ;
struct V_11 V_12 ;
int V_13 ;
T_2 V_14 = V_15 ;
T_3 V_16 = F_5 ( V_6 -> V_17 ) ;
bool V_18 = ( V_16 == V_19 ) ;
unsigned long V_20 ;
V_12 = * (struct V_11 * ) V_6 -> V_21 ;
if ( V_12 . V_22 > V_15 )
F_6 () ;
V_10 = V_23 ;
* (struct V_11 * ) V_10 = V_12 ;
V_10 += sizeof( struct V_11 ) ;
F_7 ( V_20 ) ;
V_13 = F_8 ( V_12 . V_24 , V_12 . V_25 , & V_12 . V_26 , V_12 . V_27 ,
V_10 , & V_14 , 1 , V_18 ? 1 : - 1 ) ;
F_9 ( V_20 ) ;
if ( V_13 < 0 ) {
V_14 = 0 ;
}
if ( V_14 > V_15 )
F_6 () ;
* V_9 = V_10 - sizeof( struct V_11 ) ;
F_10 ( V_6 , V_28 , V_29 ) ;
return V_14 + sizeof( struct V_11 ) ;
}
static int F_11 ( struct V_5 * V_6 ,
T_1 V_7 , void * V_8 , void * * V_9 )
{
char * V_30 = ( char * ) V_6 -> V_21 ;
int V_31 = V_7 - sizeof( struct V_5 ) ;
int V_2 = - 1 ;
struct V_11 * V_12 = (struct V_11 * ) V_30 ;
V_30 += sizeof( struct V_11 ) ;
V_31 -= sizeof( struct V_11 ) ;
F_12 ( V_31 < 0 || V_31 > V_32 ) ;
V_2 = F_13 ( V_12 -> V_25 , & V_12 -> V_26 , V_12 -> V_27 ,
V_30 , V_31 , V_12 -> V_33 ) ;
#ifdef F_14
if ( V_2 == - V_34 )
F_15 ( L_1 ) ;
#endif
return V_2 ;
}
int F_16 ( struct V_5 * V_6 ,
T_1 V_7 , void * V_8 , void * * V_9 )
{
struct V_11 * V_12 ;
char * V_35 = ( char * ) V_6 -> V_21 ;
int V_31 = V_7 - sizeof( struct V_5 ) -
sizeof( struct V_11 ) ;
T_3 V_16 = F_5 ( V_6 -> V_17 ) ;
bool V_36 = ( V_16 == V_37 ) ;
unsigned long V_20 ;
int V_2 ;
V_12 = (struct V_11 * ) V_35 ;
V_35 += sizeof( struct V_11 ) ;
F_17 ( V_12 -> V_24 , V_12 -> V_25 , V_36 ) ;
F_7 ( V_20 ) ;
V_2 = F_18 ( V_12 -> V_24 , V_12 -> V_25 , & V_12 -> V_26 , V_12 -> V_27 ,
V_35 , V_31 , 1 , V_36 ? 1 : - 1 ) ;
F_9 ( V_20 ) ;
return V_2 ;
}
int F_19 ( struct V_5 * V_6 ,
T_1 V_7 , void * V_8 , void * * V_9 )
{
struct V_11 * V_12 ;
char * V_35 = ( char * ) V_6 -> V_21 ;
V_12 = (struct V_11 * ) V_35 ;
V_35 += sizeof( struct V_11 ) ;
( void ) F_20 ( V_12 -> V_24 , V_12 -> V_25 , & V_12 -> V_26 , V_12 -> V_27 ) ;
return 0 ;
}
int F_21 ( struct V_5 * V_6 ,
T_1 V_7 , void * V_8 , void * * V_9 )
{
struct V_11 * V_12 ;
char * V_35 = ( char * ) V_6 -> V_21 ;
V_12 = (struct V_11 * ) V_35 ;
V_35 += sizeof( struct V_11 ) ;
( void ) F_22 ( V_12 -> V_24 , V_12 -> V_25 , & V_12 -> V_26 ) ;
return 0 ;
}
int F_23 ( struct V_11 * V_12 , bool free , int V_38 ,
T_2 V_39 , T_4 V_40 ,
void * V_33 )
{
int V_2 = - 1 , V_41 ;
struct V_42 * V_43 = NULL ;
struct V_44 V_45 [ 1 ] ;
T_2 V_46 = 1 ;
T_1 V_17 ;
V_43 = F_2 ( V_38 ) ;
if ( V_43 == NULL )
goto V_47;
V_12 -> V_24 = F_24 () ;
V_12 -> V_48 = V_40 ;
V_12 -> V_22 = V_39 ;
V_12 -> V_33 = V_33 ;
V_45 [ 0 ] . V_49 = sizeof( * V_12 ) ;
V_45 [ 0 ] . V_50 = V_12 ;
if ( free )
V_17 = V_19 ;
else
V_17 = V_51 ;
V_2 = F_25 ( V_17 , V_29 ,
V_45 , V_46 , V_38 , & V_41 ) ;
F_3 ( V_43 ) ;
if ( V_2 < 0 ) {
F_15 ( L_2 ) ;
}
V_2 = V_41 ;
V_47:
return V_2 ;
}
static void F_26 ( void )
{
static int V_52 , V_53 , V_54 ;
int V_55 , V_56 , V_57 ;
V_55 = F_27 () >> V_58 ;
if ( V_55 > V_52 ) {
V_52 = V_55 ;
if ( ! ( V_52 & ( V_52 - 1 ) ) )
F_15 ( L_3 ,
V_52 ) ;
}
V_56 = F_28 () >> V_59 ;
if ( V_56 > V_53 ) {
V_53 = V_56 ;
if ( ! ( V_53 & ( V_53 - 1 ) ) )
F_15 ( L_4 ,
V_53 ) ;
}
V_57 = F_29 () & V_60 ;
if ( V_57 > V_54 ) {
V_54 = V_57 ;
if ( ! ( V_54 & ( V_54 - 1 ) ) )
F_15 ( L_5 ,
V_54 ) ;
}
}
int F_30 ( struct V_11 * V_12 , char * V_8 , T_2 V_14 ,
bool V_36 , int * V_38 )
{
int V_61 , V_2 = - 1 , V_41 ;
struct V_42 * V_43 = NULL ;
struct V_44 V_45 [ 2 ] ;
T_2 V_46 = 2 ;
T_1 V_17 ;
#ifdef F_14
struct V_62 * V_63 ;
#endif
F_12 ( V_14 > V_15 ) ;
V_12 -> V_24 = F_24 () ;
V_45 [ 0 ] . V_49 = sizeof( * V_12 ) ;
V_45 [ 0 ] . V_50 = V_12 ;
V_45 [ 1 ] . V_49 = V_14 ;
V_45 [ 1 ] . V_50 = V_8 ;
V_43 = V_3 ;
if ( ! V_43 )
goto V_47;
V_61 = V_4 ;
F_31 ( V_43 ) ;
#ifdef F_14
V_63 = F_32 ( V_61 ) ;
F_33 ( V_63 -> V_64 || ! V_63 -> V_65 ) ;
#endif
if ( V_36 )
V_17 = V_37 ;
else
V_17 = V_66 ;
#ifdef F_14
F_26 () ;
#endif
V_2 = F_25 ( V_17 , V_29 , V_45 , V_46 ,
V_61 , & V_41 ) ;
#ifdef F_14
if ( V_2 != 0 ) {
static unsigned long V_67 ;
V_67 ++ ;
if ( ! ( V_67 & ( V_67 - 1 ) ) )
F_15 ( L_6
L_7 , V_2 , V_67 ) ;
V_2 = - 1 ;
}
#endif
if ( V_2 < 0 )
V_2 = - 1 ;
else {
V_2 = V_41 ;
* V_38 = V_61 ;
}
F_3 ( V_43 ) ;
V_47:
return V_2 ;
}
int F_34 ( struct V_11 * V_12 , int V_38 )
{
int V_2 = - 1 , V_41 ;
struct V_42 * V_43 = NULL ;
struct V_44 V_45 [ 1 ] ;
T_2 V_46 = 1 ;
V_43 = F_2 ( V_38 ) ;
F_12 ( V_43 == NULL ) ;
V_12 -> V_24 = F_24 () ;
V_45 [ 0 ] . V_49 = sizeof( * V_12 ) ;
V_45 [ 0 ] . V_50 = V_12 ;
F_12 ( F_35 () ) ;
F_12 ( F_36 () ) ;
V_2 = F_25 ( V_68 , V_29 ,
V_45 , V_46 , V_38 , & V_41 ) ;
F_3 ( V_43 ) ;
return V_2 ;
}
int F_37 ( struct V_11 * V_12 , int V_38 )
{
int V_2 = - 1 , V_41 ;
struct V_42 * V_43 = NULL ;
struct V_44 V_45 [ 1 ] ;
T_2 V_46 = 1 ;
V_43 = F_2 ( V_38 ) ;
F_12 ( V_43 == NULL ) ;
V_12 -> V_24 = F_24 () ;
V_45 [ 0 ] . V_49 = sizeof( * V_12 ) ;
V_45 [ 0 ] . V_50 = V_12 ;
V_2 = F_25 ( V_69 , V_29 ,
V_45 , V_46 , V_38 , & V_41 ) ;
F_3 ( V_43 ) ;
return V_2 ;
}
static void F_38 ( void )
{
F_39 ( & V_70 ) ;
}
int F_40 ( void )
{
int V_41 ;
V_41 = F_41 ( V_37 , V_29 ,
V_15 ,
F_16 ,
NULL , NULL , & V_70 ) ;
if ( V_41 )
goto V_71;
V_41 = F_41 ( V_66 , V_29 ,
V_15 ,
F_16 ,
NULL , NULL , & V_70 ) ;
if ( V_41 )
goto V_71;
V_41 = F_41 ( V_51 , V_29 ,
V_15 ,
F_4 ,
NULL , NULL ,
& V_70 ) ;
if ( V_41 )
goto V_71;
V_41 = F_41 ( V_19 ,
V_29 , V_15 ,
F_4 ,
NULL , NULL ,
& V_70 ) ;
if ( V_41 )
goto V_71;
V_41 = F_41 ( V_28 , V_29 ,
V_15 ,
F_11 ,
NULL , NULL ,
& V_70 ) ;
if ( V_41 )
goto V_71;
V_41 = F_41 ( V_68 , V_29 ,
V_15 ,
F_19 ,
NULL , NULL ,
& V_70 ) ;
if ( V_41 )
goto V_71;
V_41 = F_41 ( V_69 , V_29 ,
V_15 ,
F_21 ,
NULL , NULL ,
& V_70 ) ;
if ( V_41 )
goto V_71;
F_42 ( L_8 ) ;
V_71:
if ( V_41 ) {
F_38 () ;
F_15 ( L_9 ) ;
}
return V_41 ;
}
