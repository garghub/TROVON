void F_1 ( T_1 V_1 , T_2 V_2 , T_3 * V_3 )
{
T_4 V_4 = FALSE ;
T_2 V_5 = 0 ;
T_2 V_6 = 0 ;
T_5 V_7 ;
T_5 V_8 = 0 ;
for (; ; )
{
if ( ! F_2 ( V_1 , NULL , 0 , NULL , & V_8 , NULL ) ) break;
if ( V_8 <= 0 ) break;
V_6 = V_2 - V_5 - 1 ;
V_4 = F_3 ( V_1 , & V_3 [ V_5 ] , V_6 , & V_7 , NULL ) ;
if ( ! V_4 || V_7 == 0 ) break;
V_5 += V_7 ;
if ( ( V_5 + 1 ) >= V_2 ) break;
}
V_3 [ V_5 ] = '\0' ;
}
T_4 F_4 ( T_3 * V_9 , T_3 * V_10 , T_6 V_11 , T_3 * * args , T_3 * * V_12 )
{
T_4 V_13 = FALSE ;
T_4 V_14 = FALSE ;
T_3 * * V_15 = NULL ;
T_6 V_16 = 0 ;
T_3 * V_17 = NULL ;
#ifdef F_5
#define F_6 4096
T_3 V_3 [ F_6 ] ;
T_7 * V_18 = F_7 ( 200 ) ;
T_3 * V_19 ;
T_8 * V_20 ;
T_9 V_21 ;
T_10 V_22 ;
T_11 V_23 ;
T_1 V_24 = NULL ;
T_1 V_25 = NULL ;
T_1 V_26 = NULL ;
T_1 V_27 = NULL ;
const T_3 * V_28 = F_8 ( L_1 ) ;
T_3 * V_29 = NULL ;
#else
T_6 V_30 = 0 ;
#endif
V_15 = ( T_3 * * ) F_9 ( sizeof( T_3 * ) * ( V_11 + 2 ) ) ;
#ifdef F_5
V_29 = F_10 ( L_2 , F_11 ( F_12 () , NULL ) , V_28 ) ;
F_13 ( L_1 , V_29 , TRUE ) ;
V_15 [ 0 ] = F_11 ( V_10 , NULL ) ;
#else
V_15 [ 0 ] = F_14 ( V_10 ) ;
#endif
for ( V_16 = 0 ; V_16 < V_11 ; V_16 ++ )
V_15 [ V_16 + 1 ] = args [ V_16 ] ;
V_15 [ V_11 + 1 ] = NULL ;
#ifdef F_5
V_23 . V_31 = sizeof( T_11 ) ;
V_23 . V_32 = TRUE ;
V_23 . V_33 = NULL ;
if ( ! F_15 ( & V_24 , & V_25 , & V_23 , 0 ) )
{
F_16 ( V_15 [ 0 ] ) ;
F_17 ( V_34 , V_35 , L_3 ) ;
return FALSE ;
}
if ( ! F_15 ( & V_26 , & V_27 , & V_23 , 0 ) )
{
F_18 ( V_24 ) ;
F_18 ( V_25 ) ;
F_16 ( V_15 [ 0 ] ) ;
F_17 ( V_34 , V_35 , L_4 ) ;
return FALSE ;
}
for ( V_16 = 0 ; V_15 [ V_16 ] != 0 ; V_16 ++ ) {
if ( V_16 != 0 ) F_19 ( V_18 , ' ' ) ;
V_19 = F_20 ( V_15 [ V_16 ] ) ;
F_21 ( V_18 , V_19 ) ;
F_16 ( V_19 ) ;
}
V_20 = F_22 ( V_18 -> V_36 , ( V_37 ) V_18 -> V_38 , NULL , NULL , NULL ) ;
memset ( & V_22 , 0 , sizeof( T_10 ) ) ;
memset ( & V_21 , 0 , sizeof( T_9 ) ) ;
V_21 . V_39 = sizeof( T_9 ) ;
V_21 . V_40 = V_27 ;
V_21 . V_41 = V_25 ;
V_21 . V_42 = V_43 | V_44 ;
V_21 . V_45 = V_46 ;
if ( F_23 ( NULL , V_20 , NULL , NULL , TRUE , V_47 , NULL , NULL , & V_21 , & V_22 ) )
{
F_24 ( V_22 . V_48 , V_49 ) ;
F_1 ( V_24 , F_6 , V_3 ) ;
V_17 = F_10 ( L_5 , V_3 ) ;
F_18 ( V_24 ) ;
F_18 ( V_25 ) ;
F_18 ( V_26 ) ;
F_18 ( V_27 ) ;
F_18 ( V_22 . V_48 ) ;
F_18 ( V_22 . V_50 ) ;
V_13 = TRUE ;
}
else
V_13 = FALSE ;
F_13 ( L_1 , V_28 , TRUE ) ;
#else
V_13 = F_25 ( V_9 , V_15 , NULL ,
( V_51 ) 0 , NULL , NULL , & V_17 , NULL , & V_30 , NULL ) ;
if ( V_13 && V_30 != 0 )
V_13 = FALSE ;
#endif
if ( V_13 )
{
if ( V_12 != NULL && V_17 != NULL )
* V_12 = F_14 ( V_17 ) ;
V_14 = TRUE ;
}
F_16 ( V_17 ) ;
F_16 ( V_15 [ 0 ] ) ;
F_16 ( V_15 ) ;
return V_14 ;
}
T_12 F_26 ( T_13 * V_52 , T_14 * args )
{
T_12 V_53 = V_54 ;
#ifdef F_5
T_6 V_16 = 0 ;
T_3 * * V_55 = NULL ;
T_7 * V_18 = F_7 ( 200 ) ;
T_3 * V_19 ;
T_8 * V_20 ;
T_9 V_21 ;
T_10 V_22 ;
T_11 V_23 ;
T_1 V_24 = NULL ;
T_1 V_25 = NULL ;
T_1 V_26 = NULL ;
T_1 V_27 = NULL ;
const T_3 * V_28 = F_8 ( L_1 ) ;
T_3 * V_29 = NULL ;
V_29 = F_10 ( L_2 , F_11 ( F_12 () , NULL ) , V_28 ) ;
F_13 ( L_1 , V_29 , TRUE ) ;
V_23 . V_31 = sizeof( T_11 ) ;
V_23 . V_32 = TRUE ;
V_23 . V_33 = NULL ;
if ( ! F_15 ( & V_24 , & V_25 , & V_23 , 0 ) )
{
F_17 ( V_34 , V_35 , L_3 ) ;
return FALSE ;
}
if ( ! F_15 ( & V_26 , & V_27 , & V_23 , 0 ) )
{
F_18 ( V_24 ) ;
F_18 ( V_25 ) ;
F_17 ( V_34 , V_35 , L_4 ) ;
return FALSE ;
}
for ( V_55 = ( T_3 * * ) args -> V_56 , V_16 = 0 ; * V_55 && * * V_55 ; ++ V_16 , ++ V_55 ) {
if ( V_16 != 0 ) F_19 ( V_18 , ' ' ) ;
V_19 = F_20 ( * V_55 ) ;
F_21 ( V_18 , V_19 ) ;
F_16 ( V_19 ) ;
}
V_20 = F_22 ( V_18 -> V_36 , ( V_37 ) V_18 -> V_38 , NULL , NULL , NULL ) ;
memset ( & V_22 , 0 , sizeof( T_10 ) ) ;
memset ( & V_21 , 0 , sizeof( T_9 ) ) ;
V_21 . V_39 = sizeof( T_9 ) ;
V_21 . V_40 = V_27 ;
V_21 . V_41 = V_25 ;
V_21 . V_42 = V_43 | V_44 ;
V_21 . V_45 = V_46 ;
if ( F_23 ( NULL , V_20 , NULL , NULL , TRUE , V_47 , NULL , NULL , & V_21 , & V_22 ) )
{
V_52 -> V_57 = F_27 ( ( V_58 ) ( V_26 ) , V_59 ) ;
V_52 -> V_60 = F_27 ( ( V_58 ) ( V_24 ) , V_59 ) ;
V_52 -> V_61 = V_22 . V_50 ;
V_53 = V_22 . V_48 ;
}
F_13 ( L_1 , V_28 , TRUE ) ;
#else
F_28 ( NULL , ( T_3 * * ) args -> V_56 , NULL ,
( V_51 ) V_62 , NULL , NULL ,
& V_53 , NULL , & V_52 -> V_60 , & V_52 -> V_57 , NULL ) ;
#endif
V_52 -> V_53 = V_53 ;
return V_53 ;
}
T_4
F_29 ( T_1 V_63 , T_1 V_53 )
{
T_5 V_64 ;
T_1 V_65 [ 2 ] ;
T_15 V_66 ;
T_4 V_67 = FALSE ;
V_66 . V_68 = 0 ;
V_66 . V_69 = F_30 ( NULL , TRUE , FALSE , NULL ) ;
F_31 ( V_63 , & V_66 ) ;
V_65 [ 0 ] = V_66 . V_69 ;
V_65 [ 1 ] = V_53 ;
if ( F_32 () == V_70 )
{
F_17 ( V_34 , V_35 , L_6 ) ;
}
else
{
V_64 = F_33 ( 2 , V_65 , FALSE , 30000 ) ;
if ( V_64 == V_71 )
{
T_5 V_72 ;
V_72 = F_32 () ;
if ( V_72 == V_73 )
{
T_5 V_74 ;
if ( ! F_34 ( V_66 . V_69 , & V_66 , & V_74 , TRUE ) )
{
V_72 = F_32 () ;
}
else
{
V_72 = V_75 ;
V_67 = TRUE ;
}
}
F_17 ( V_34 , V_35 , L_7 , V_72 ) ;
}
else if ( V_64 == ( V_71 + 1 ) )
{
F_17 ( V_34 , V_35 , L_8 ) ;
}
else if ( V_64 == V_76 )
{
F_17 ( V_34 , V_35 , L_9 ) ;
}
else
{
F_17 ( V_34 , V_35 , L_10 , V_64 , F_32 () ) ;
}
}
F_18 ( V_66 . V_69 ) ;
return V_67 ;
}
