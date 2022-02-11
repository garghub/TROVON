static void F_1 ( T_1 * V_1 )
{
T_2 V_2 = FALSE ;
int V_3 ;
V_3 = F_2 ( & ( V_1 -> V_4 ) , & ( V_1 -> V_5 ) ) ;
if ( V_3 > 0 )
{
V_2 = TRUE ;
}
else if ( V_3 == 0 )
{
if ( V_1 -> V_6 > V_1 -> V_7 )
{
V_2 = TRUE ;
}
}
if ( V_2 )
{
T_3 V_8 ;
T_4 V_9 ;
F_3 ( & V_8 , & ( V_1 -> V_4 ) ) ;
F_3 ( & ( V_1 -> V_5 ) , & ( V_1 -> V_4 ) ) ;
F_3 ( & ( V_1 -> V_4 ) , & V_8 ) ;
V_9 = V_1 -> V_7 ;
V_1 -> V_7 = V_1 -> V_6 ;
V_1 -> V_6 = V_9 ;
}
}
static T_1 * F_4 ( const T_3 * V_10 , T_4 V_6 , const T_3 * V_11 , T_4 V_7 , T_5 V_12 )
{
T_1 * V_13 ;
T_6 * V_14 = NULL ;
V_14 = F_5 ( V_12 , V_10 , V_11 , V_15 , V_6 , V_7 , 0 ) ;
if ( V_14 == NULL )
{
V_14 = F_6 ( V_12 , V_10 , V_11 , V_15 , V_6 , V_7 , 0 ) ;
}
V_13 = ( T_1 * ) F_7 ( V_14 , V_16 ) ;
if ( V_13 != NULL )
{
return ( V_13 ) ;
}
V_13 = F_8 ( F_9 () , T_1 ) ;
F_10 ( F_9 () , & ( V_13 -> V_4 ) , V_10 ) ;
V_13 -> V_6 = V_6 ;
F_10 ( F_9 () , & ( V_13 -> V_5 ) , V_11 ) ;
V_13 -> V_7 = V_7 ;
F_1 ( V_13 ) ;
V_13 -> V_17 = F_11 ( V_18 ) ;
F_12 ( V_14 , V_16 , ( void * ) V_13 ) ;
return ( V_13 ) ;
}
static T_2 F_13 ( void * V_19 , char * * V_20 )
{
T_7 * V_21 = ( T_7 * ) V_19 ;
if ( V_21 -> V_22 == NULL )
{
* V_20 = F_14 ( L_1 ) ;
return FALSE ;
}
else
{
F_15 ( V_21 -> V_22 ) ;
if ( V_21 -> V_22 [ 0 ] == 0 )
{
* V_20 = F_14 ( L_1 ) ;
return FALSE ;
}
}
return TRUE ;
}
static void * F_16 ( void * V_23 , const void * V_24 , T_8 T_9 V_25 )
{
const T_7 * V_26 = ( const T_7 * ) V_24 ;
T_7 * V_27 = ( T_7 * ) V_23 ;
V_27 -> V_22 = F_17 ( V_26 -> V_22 ) ;
V_27 -> V_28 = V_26 -> V_28 ;
V_27 -> V_29 = V_26 -> V_29 ;
return ( V_27 ) ;
}
static void F_18 ( void * V_19 )
{
T_7 * V_21 = ( T_7 * ) V_19 ;
if ( V_21 -> V_22 != NULL )
{
F_19 ( V_21 -> V_22 ) ;
V_21 -> V_22 = NULL ;
}
}
static const T_7 * F_20 ( T_10 * V_30 )
{
T_11 V_31 ;
const T_7 * V_21 = NULL ;
if ( ! V_32 )
{
return ( NULL ) ;
}
for ( V_31 = 0 ; V_31 < V_33 ; ++ V_31 )
{
V_21 = & ( V_34 [ V_31 ] ) ;
if ( ( ( V_30 -> V_35 >= V_21 -> V_28 ) && ( V_30 -> V_35 <= V_21 -> V_29 ) )
|| ( ( V_30 -> V_36 >= V_21 -> V_28 ) && ( V_30 -> V_36 <= V_21 -> V_29 ) ) )
{
return ( V_21 ) ;
}
}
return ( NULL ) ;
}
static char * F_21 ( T_10 * V_30 )
{
const T_7 * V_21 = NULL ;
if ( ! V_32 )
{
return ( NULL ) ;
}
V_21 = F_20 ( V_30 ) ;
if ( V_21 != NULL )
{
return V_21 -> V_22 ;
}
return ( NULL ) ;
}
static T_11 F_22 ( T_10 * V_30 V_25 , T_12 * V_37 ,
int V_38 , void * T_13 V_25 )
{
int V_39 ;
int V_40 = 0 ;
V_40 = 0 ;
if ( ! F_23 ( V_37 , V_38 , & V_39 , & V_40 ) )
{
V_40 = 0 ;
}
return ( V_40 ) ;
}
static int F_24 ( T_12 * V_37 , T_10 * V_30 , T_14 * V_41 , void * T_15 V_25 )
{
T_14 * V_42 = NULL ;
T_16 * V_43 = NULL ;
T_1 * V_1 = NULL ;
char * V_44 = NULL ;
T_17 V_17 = V_45 ;
if ( V_32 )
{
V_44 = F_21 ( V_30 ) ;
}
if ( V_44 != NULL )
{
V_43 = F_25 ( V_41 , V_16 , V_37 , 0 , - 1 , L_2 , V_44 ) ;
}
else
{
V_43 = F_25 ( V_41 , V_16 , V_37 , 0 , - 1 , L_3 ) ;
}
V_42 = F_26 ( V_43 , V_46 ) ;
V_1 = F_4 ( & ( V_30 -> V_26 ) , V_30 -> V_35 , & ( V_30 -> V_47 ) , V_30 -> V_36 , V_30 -> V_48 -> V_49 ) ;
if ( V_1 != NULL )
{
V_17 = V_1 -> V_17 ;
}
if ( V_44 != NULL )
{
T_16 * V_50 = NULL ;
V_50 = F_27 ( V_42 , V_51 , V_37 , 0 , 0 , V_44 ) ;
F_28 ( V_50 ) ;
}
if ( V_17 != V_45 )
{
T_16 * V_50 = NULL ;
V_50 = F_29 ( V_42 , V_52 , V_37 , 0 , 0 , V_17 ) ;
F_28 ( V_50 ) ;
}
return ( F_30 ( V_37 , 0 , V_30 , V_41 , V_17 ) ) ;
}
static void F_31 ( T_12 * V_37 , T_10 * V_30 , T_14 * V_41 )
{
char * V_44 = NULL ;
F_32 ( V_30 -> V_53 , V_54 , L_4 ) ;
F_33 ( V_30 -> V_53 , V_55 ) ;
if ( V_32 )
{
V_44 = F_21 ( V_30 ) ;
}
if ( V_44 != NULL )
{
F_34 ( V_30 -> V_53 , V_55 , L_5 , V_44 ) ;
}
F_35 ( V_30 -> V_53 , V_55 ) ;
F_36 ( V_37 , V_30 , V_41 , TRUE , F_37 () ,
F_22 , F_24 , NULL ) ;
}
static T_2 F_38 ( T_12 * V_37 , T_10 * V_30 , T_14 * V_41 , void * T_18 V_25 )
{
int V_39 = 0 ;
int V_40 = 0 ;
if ( V_30 -> V_56 != V_15 )
{
return ( FALSE ) ;
}
if ( ( V_30 -> V_47 . type != V_57 ) || ( V_30 -> V_47 . V_58 != 4 ) )
{
return ( FALSE ) ;
}
if ( ! F_23 ( V_37 , 0 , & V_39 , & V_40 ) )
{
return ( FALSE ) ;
}
if ( V_32 )
{
if ( F_21 ( V_30 ) != NULL )
{
F_31 ( V_37 , V_30 , V_41 ) ;
return ( TRUE ) ;
}
else
{
return ( FALSE ) ;
}
}
if ( ! ( ( ( V_30 -> V_35 >= V_59 ) && ( V_30 -> V_35 <= V_60 ) )
|| ( ( V_30 -> V_36 >= V_59 ) && ( V_30 -> V_36 <= V_60 ) ) ) )
{
return ( FALSE ) ;
}
F_31 ( V_37 , V_30 , V_41 ) ;
return ( TRUE ) ;
}
void F_39 ( void )
{
static T_19 V_61 [] =
{
{ & V_51 ,
{ L_6 , L_7 , V_62 , V_63 , NULL , 0x0 , NULL , V_64 } } ,
{ & V_52 ,
{ L_8 , L_9 , V_65 , V_66 , NULL , 0x0 , NULL , V_64 } } ,
} ;
static T_20 * V_67 [] =
{
& V_46 ,
} ;
T_21 * V_68 ;
T_22 * V_69 ;
V_16 = F_40 ( L_10 , L_4 , L_11 ) ;
F_41 ( V_16 , V_61 , F_42 ( V_61 ) ) ;
F_43 ( V_67 , F_42 ( V_67 ) ) ;
V_68 = F_44 ( L_12 , V_16 , V_70 ) ;
F_45 ( V_68 ,
L_13 ,
L_14 F_46 ( V_71 ) L_15 ,
L_16 ,
10 ,
& V_72 ) ;
F_45 ( V_68 ,
L_17 ,
L_18 F_46 ( V_73 ) L_15 ,
L_19 ,
10 ,
& V_74 ) ;
F_47 ( V_68 ,
L_20 ,
L_21 ,
L_22 ,
& V_75 ) ;
V_69 = F_48 ( L_23 ,
sizeof( T_7 ) ,
L_24 ,
TRUE ,
( void * * ) & V_34 ,
& V_33 ,
V_76 ,
NULL ,
F_16 ,
F_13 ,
F_18 ,
NULL ,
V_77 ) ;
F_49 ( V_68 ,
L_25 ,
L_26 ,
L_27 ,
V_69 ) ;
}
void V_70 ( void )
{
static T_2 V_78 = FALSE ;
if ( ! V_78 )
{
V_79 = F_50 ( F_31 , V_16 ) ;
F_51 ( L_28 , V_79 ) ;
F_52 ( L_29 , F_38 , L_30 , L_11 , V_16 , V_80 ) ;
}
if ( V_72 <= V_74 )
{
V_59 = V_72 ;
V_60 = V_74 ;
}
V_32 = V_75 ;
V_78 = TRUE ;
}
