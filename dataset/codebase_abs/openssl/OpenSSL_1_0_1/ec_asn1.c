int F_1 ( const T_1 * V_1 )
{
int V_2 = 0 ;
if ( F_2 ( F_3 ( V_1 ) ) !=
V_3 )
return 0 ;
while ( V_1 -> V_4 [ V_2 ] != 0 )
V_2 ++ ;
if ( V_2 == 4 )
return V_5 ;
else if ( V_2 == 2 )
return V_6 ;
else
return 0 ;
}
int F_4 ( const T_1 * V_1 , unsigned int * V_7 )
{
if ( V_1 == NULL )
return 0 ;
if ( F_3 ( V_1 ) -> V_8 != V_9
|| ! ( ( V_1 -> V_4 [ 0 ] != 0 ) && ( V_1 -> V_4 [ 1 ] != 0 ) && ( V_1 -> V_4 [ 2 ] == 0 ) ) )
{
F_5 ( V_10 , V_11 ) ;
return 0 ;
}
if ( V_7 )
* V_7 = V_1 -> V_4 [ 1 ] ;
return 1 ;
}
int F_6 ( const T_1 * V_1 , unsigned int * V_12 ,
unsigned int * V_13 , unsigned int * V_14 )
{
if ( V_1 == NULL )
return 0 ;
if ( F_3 ( V_1 ) -> V_8 != V_9
|| ! ( ( V_1 -> V_4 [ 0 ] != 0 ) && ( V_1 -> V_4 [ 1 ] != 0 ) && ( V_1 -> V_4 [ 2 ] != 0 ) && ( V_1 -> V_4 [ 3 ] != 0 ) && ( V_1 -> V_4 [ 4 ] == 0 ) ) )
{
F_5 ( V_15 , V_11 ) ;
return 0 ;
}
if ( V_12 )
* V_12 = V_1 -> V_4 [ 3 ] ;
if ( V_13 )
* V_13 = V_1 -> V_4 [ 2 ] ;
if ( V_14 )
* V_14 = V_1 -> V_4 [ 1 ] ;
return 1 ;
}
static int F_7 ( const T_1 * V_1 , T_2 * V_16 )
{
int V_17 = 0 , V_18 ;
T_3 * V_19 = NULL ;
if ( V_1 == NULL || V_16 == NULL )
return 0 ;
if ( V_16 -> V_20 != NULL )
F_8 ( V_16 -> V_20 ) ;
if ( V_16 -> V_21 . V_22 != NULL )
F_9 ( V_16 -> V_21 . V_22 ) ;
V_18 = F_2 ( F_3 ( V_1 ) ) ;
if ( ( V_16 -> V_20 = F_10 ( V_18 ) ) == NULL )
{
F_5 ( V_23 , V_24 ) ;
goto V_25;
}
if ( V_18 == V_26 )
{
if ( ( V_19 = F_11 () ) == NULL )
{
F_5 ( V_23 , V_27 ) ;
goto V_25;
}
if ( ! F_12 ( V_1 , V_19 , NULL , NULL , NULL ) )
{
F_5 ( V_23 , V_28 ) ;
goto V_25;
}
V_16 -> V_21 . V_29 = F_13 ( V_19 , NULL ) ;
if ( V_16 -> V_21 . V_29 == NULL )
{
F_5 ( V_23 , V_30 ) ;
goto V_25;
}
}
else
#ifdef F_14
{
F_5 ( V_23 , V_31 ) ;
goto V_25;
}
#else
{
int V_32 ;
T_4 * V_33 ;
V_16 -> V_21 . V_33 = F_15 () ;
V_33 = V_16 -> V_21 . V_33 ;
if ( V_33 == NULL )
{
F_5 ( V_23 , V_27 ) ;
goto V_25;
}
V_33 -> V_34 = ( long ) F_16 ( V_1 ) ;
V_32 = F_1 ( V_1 ) ;
if ( V_32 == 0 )
{
F_5 ( V_23 , V_28 ) ;
goto V_25;
}
if ( ( V_33 -> type = F_10 ( V_32 ) ) == NULL )
{
F_5 ( V_23 , V_24 ) ;
goto V_25;
}
if ( V_32 == V_6 )
{
unsigned int V_7 ;
if ( ! F_4 ( V_1 , & V_7 ) )
goto V_25;
V_33 -> V_21 . V_35 = F_17 () ;
if ( ! V_33 -> V_21 . V_35 )
{
F_5 ( V_23 , V_27 ) ;
goto V_25;
}
if ( ! F_18 ( V_33 -> V_21 . V_35 , ( long ) V_7 ) )
{
F_5 ( V_23 ,
V_30 ) ;
goto V_25;
}
}
else if ( V_32 == V_5 )
{
unsigned int V_12 , V_13 , V_14 ;
if ( ! F_6 ( V_1 , & V_12 , & V_13 , & V_14 ) )
goto V_25;
V_33 -> V_21 . V_36 = F_19 () ;
if ( ! V_33 -> V_21 . V_36 )
{
F_5 ( V_23 , V_27 ) ;
goto V_25;
}
V_33 -> V_21 . V_36 -> V_12 = ( long ) V_12 ;
V_33 -> V_21 . V_36 -> V_13 = ( long ) V_13 ;
V_33 -> V_21 . V_36 -> V_14 = ( long ) V_14 ;
}
else
{
V_33 -> V_21 . V_37 = F_20 () ;
if ( ! V_33 -> V_21 . V_37 )
{
F_5 ( V_23 , V_27 ) ;
goto V_25;
}
}
}
#endif
V_17 = 1 ;
V_25 : if ( V_19 )
F_21 ( V_19 ) ;
return ( V_17 ) ;
}
static int F_22 ( const T_1 * V_1 , T_5 * V_38 )
{
int V_17 = 0 , V_18 ;
T_3 * V_39 = NULL , * V_40 = NULL ;
unsigned char * V_41 = NULL , * V_42 = NULL ,
* V_43 = NULL , * V_44 = NULL ;
T_6 V_45 , V_46 ;
unsigned char V_47 = 0 ;
if ( ! V_1 || ! V_38 || ! V_38 -> V_48 || ! V_38 -> V_49 )
return 0 ;
if ( ( V_39 = F_11 () ) == NULL || ( V_40 = F_11 () ) == NULL )
{
F_5 ( V_50 , V_27 ) ;
goto V_25;
}
V_18 = F_2 ( F_3 ( V_1 ) ) ;
if ( V_18 == V_26 )
{
if ( ! F_12 ( V_1 , NULL , V_39 , V_40 , NULL ) )
{
F_5 ( V_50 , V_28 ) ;
goto V_25;
}
}
#ifndef F_14
else
{
if ( ! F_23 ( V_1 , NULL , V_39 , V_40 , NULL ) )
{
F_5 ( V_50 , V_28 ) ;
goto V_25;
}
}
#endif
V_45 = ( T_6 ) F_24 ( V_39 ) ;
V_46 = ( T_6 ) F_24 ( V_40 ) ;
if ( V_45 == 0 )
{
V_43 = & V_47 ;
V_45 = 1 ;
}
else
{
if ( ( V_41 = F_25 ( V_45 ) ) == NULL )
{
F_5 ( V_50 ,
V_27 ) ;
goto V_25;
}
if ( ( V_45 = F_26 ( V_39 , V_41 ) ) == 0 )
{
F_5 ( V_50 , V_51 ) ;
goto V_25;
}
V_43 = V_41 ;
}
if ( V_46 == 0 )
{
V_44 = & V_47 ;
V_46 = 1 ;
}
else
{
if ( ( V_42 = F_25 ( V_46 ) ) == NULL )
{
F_5 ( V_50 ,
V_27 ) ;
goto V_25;
}
if ( ( V_46 = F_26 ( V_40 , V_42 ) ) == 0 )
{
F_5 ( V_50 , V_51 ) ;
goto V_25;
}
V_44 = V_42 ;
}
if ( ! F_27 ( V_38 -> V_48 , V_43 , V_45 ) ||
! F_27 ( V_38 -> V_49 , V_44 , V_46 ) )
{
F_5 ( V_50 , V_30 ) ;
goto V_25;
}
if ( V_1 -> V_52 )
{
if ( ! V_38 -> V_52 )
if ( ( V_38 -> V_52 = F_28 () ) == NULL )
{
F_5 ( V_50 , V_27 ) ;
goto V_25;
}
V_38 -> V_52 -> V_53 &= ~ ( V_54 | 0x07 ) ;
V_38 -> V_52 -> V_53 |= V_54 ;
if ( ! F_29 ( V_38 -> V_52 , V_1 -> V_52 ,
( int ) V_1 -> V_55 ) )
{
F_5 ( V_50 , V_30 ) ;
goto V_25;
}
}
else
{
if ( V_38 -> V_52 )
{
F_30 ( V_38 -> V_52 ) ;
V_38 -> V_52 = NULL ;
}
}
V_17 = 1 ;
V_25: if ( V_41 )
F_31 ( V_41 ) ;
if ( V_42 )
F_31 ( V_42 ) ;
if ( V_39 )
F_21 ( V_39 ) ;
if ( V_40 )
F_21 ( V_40 ) ;
return ( V_17 ) ;
}
static T_7 * F_32 ( const T_1 * V_1 ,
T_7 * V_56 )
{
int V_17 = 0 ;
T_6 V_57 = 0 ;
T_7 * V_58 = NULL ;
T_3 * V_19 = NULL ;
unsigned char * V_59 = NULL ;
const T_8 * V_60 = NULL ;
T_9 V_61 ;
if ( ( V_19 = F_11 () ) == NULL )
{
F_5 ( V_62 , V_27 ) ;
goto V_25;
}
if ( V_56 == NULL )
{
if ( ( V_58 = F_33 () ) == NULL )
{
F_5 ( V_62 ,
V_27 ) ;
goto V_25;
}
}
else
V_58 = V_56 ;
V_58 -> V_63 = ( long ) 0x1 ;
if ( ! F_7 ( V_1 , V_58 -> V_64 ) )
{
F_5 ( V_62 , V_28 ) ;
goto V_25;
}
if ( ! F_22 ( V_1 , V_58 -> V_38 ) )
{
F_5 ( V_62 , V_28 ) ;
goto V_25;
}
if ( ( V_60 = F_34 ( V_1 ) ) == NULL )
{
F_5 ( V_62 , V_65 ) ;
goto V_25;
}
V_61 = F_35 ( V_1 ) ;
V_57 = F_36 ( V_1 , V_60 , V_61 , NULL , V_57 , NULL ) ;
if ( V_57 == 0 )
{
F_5 ( V_62 , V_28 ) ;
goto V_25;
}
if ( ( V_59 = F_25 ( V_57 ) ) == NULL )
{
F_5 ( V_62 , V_27 ) ;
goto V_25;
}
if ( ! F_36 ( V_1 , V_60 , V_61 , V_59 , V_57 , NULL ) )
{
F_5 ( V_62 , V_28 ) ;
goto V_25;
}
if ( V_58 -> V_66 == NULL && ( V_58 -> V_66 = F_37 () ) == NULL )
{
F_5 ( V_62 , V_27 ) ;
goto V_25;
}
if ( ! F_38 ( V_58 -> V_66 , V_59 , V_57 ) )
{
F_5 ( V_62 , V_30 ) ;
goto V_25;
}
if ( ! F_39 ( V_1 , V_19 , NULL ) )
{
F_5 ( V_62 , V_28 ) ;
goto V_25;
}
V_58 -> V_67 = F_13 ( V_19 , V_58 -> V_67 ) ;
if ( V_58 -> V_67 == NULL )
{
F_5 ( V_62 , V_30 ) ;
goto V_25;
}
if ( F_40 ( V_1 , V_19 , NULL ) )
{
V_58 -> V_68 = F_13 ( V_19 , V_58 -> V_68 ) ;
if ( V_58 -> V_68 == NULL )
{
F_5 ( V_62 , V_30 ) ;
goto V_25;
}
}
V_17 = 1 ;
V_25 : if( ! V_17 )
{
if ( V_58 && ! V_56 )
F_41 ( V_58 ) ;
V_58 = NULL ;
}
if ( V_19 )
F_21 ( V_19 ) ;
if ( V_59 )
F_31 ( V_59 ) ;
return ( V_58 ) ;
}
T_10 * F_42 ( const T_1 * V_1 ,
T_10 * V_69 )
{
int V_17 = 1 , V_19 ;
T_10 * V_58 = V_69 ;
if ( V_58 == NULL )
{
if ( ( V_58 = F_43 () ) == NULL )
{
F_5 ( V_70 ,
V_27 ) ;
return NULL ;
}
}
else
{
if ( V_58 -> type == 0 && V_58 -> V_71 . V_72 )
F_8 ( V_58 -> V_71 . V_72 ) ;
else if ( V_58 -> type == 1 && V_58 -> V_71 . V_73 )
F_41 ( V_58 -> V_71 . V_73 ) ;
}
if ( F_44 ( V_1 ) )
{
V_19 = F_45 ( V_1 ) ;
if ( V_19 )
{
V_58 -> type = 0 ;
if ( ( V_58 -> V_71 . V_72 = F_10 ( V_19 ) ) == NULL )
V_17 = 0 ;
}
else
V_17 = 0 ;
}
else
{
V_58 -> type = 1 ;
if ( ( V_58 -> V_71 . V_73 = F_32 (
V_1 , NULL ) ) == NULL )
V_17 = 0 ;
}
if ( ! V_17 )
{
F_46 ( V_58 ) ;
return NULL ;
}
return V_58 ;
}
static T_1 * F_47 ( const T_7 * V_69 )
{
int V_17 = 0 , V_19 ;
T_1 * V_58 = NULL ;
T_3 * V_21 = NULL , * V_48 = NULL , * V_49 = NULL ;
T_8 * V_60 = NULL ;
long V_74 ;
if ( ! V_69 -> V_64 || ! V_69 -> V_64 -> V_20 ||
! V_69 -> V_64 -> V_21 . V_75 )
{
F_5 ( V_76 , V_77 ) ;
goto V_25;
}
if ( ! V_69 -> V_38 || ! V_69 -> V_38 -> V_48 ||
! V_69 -> V_38 -> V_48 -> V_78 || ! V_69 -> V_38 -> V_49 ||
! V_69 -> V_38 -> V_49 -> V_78 )
{
F_5 ( V_76 , V_77 ) ;
goto V_25;
}
V_48 = F_48 ( V_69 -> V_38 -> V_48 -> V_78 , V_69 -> V_38 -> V_48 -> V_79 , NULL ) ;
if ( V_48 == NULL )
{
F_5 ( V_76 , V_51 ) ;
goto V_25;
}
V_49 = F_48 ( V_69 -> V_38 -> V_49 -> V_78 , V_69 -> V_38 -> V_49 -> V_79 , NULL ) ;
if ( V_49 == NULL )
{
F_5 ( V_76 , V_51 ) ;
goto V_25;
}
V_19 = F_49 ( V_69 -> V_64 -> V_20 ) ;
if ( V_19 == V_3 )
#ifdef F_14
{
F_5 ( V_76 , V_31 ) ;
goto V_25;
}
#else
{
T_4 * V_33 ;
V_33 = V_69 -> V_64 -> V_21 . V_33 ;
V_74 = V_33 -> V_34 ;
if ( V_74 > V_80 )
{
F_5 ( V_76 , V_81 ) ;
goto V_25;
}
if ( ( V_21 = F_11 () ) == NULL )
{
F_5 ( V_76 , V_27 ) ;
goto V_25;
}
V_19 = F_49 ( V_33 -> type ) ;
if ( V_19 == V_6 )
{
long V_82 ;
if ( ! V_33 -> V_21 . V_35 )
{
F_5 ( V_76 , V_77 ) ;
goto V_25;
}
V_82 = F_50 ( V_33 -> V_21 . V_35 ) ;
if ( ! ( V_33 -> V_34 > V_82 && V_82 > 0 ) )
{
F_5 ( V_76 , V_83 ) ;
goto V_25;
}
if ( ! F_51 ( V_21 , ( int ) V_33 -> V_34 ) )
goto V_25;
if ( ! F_51 ( V_21 , ( int ) V_82 ) )
goto V_25;
if ( ! F_51 ( V_21 , 0 ) )
goto V_25;
}
else if ( V_19 == V_5 )
{
T_11 * V_84 ;
V_84 = V_33 -> V_21 . V_36 ;
if ( ! V_84 )
{
F_5 ( V_76 , V_77 ) ;
goto V_25;
}
if ( ! ( V_33 -> V_34 > V_84 -> V_14 && V_84 -> V_14 > V_84 -> V_13 && V_84 -> V_13 > V_84 -> V_12 && V_84 -> V_12 > 0 ) )
{
F_5 ( V_76 , V_85 ) ;
goto V_25;
}
if ( ! F_51 ( V_21 , ( int ) V_33 -> V_34 ) ) goto V_25;
if ( ! F_51 ( V_21 , ( int ) V_84 -> V_12 ) ) goto V_25;
if ( ! F_51 ( V_21 , ( int ) V_84 -> V_13 ) ) goto V_25;
if ( ! F_51 ( V_21 , ( int ) V_84 -> V_14 ) ) goto V_25;
if ( ! F_51 ( V_21 , 0 ) ) goto V_25;
}
else if ( V_19 == V_86 )
{
F_5 ( V_76 , V_87 ) ;
goto V_25;
}
else
{
F_5 ( V_76 , V_77 ) ;
goto V_25;
}
V_58 = F_52 ( V_21 , V_48 , V_49 , NULL ) ;
}
#endif
else if ( V_19 == V_26 )
{
if ( ! V_69 -> V_64 -> V_21 . V_29 )
{
F_5 ( V_76 , V_77 ) ;
goto V_25;
}
V_21 = F_53 ( V_69 -> V_64 -> V_21 . V_29 , NULL ) ;
if ( V_21 == NULL )
{
F_5 ( V_76 , V_30 ) ;
goto V_25;
}
if ( F_54 ( V_21 ) || F_55 ( V_21 ) )
{
F_5 ( V_76 , V_88 ) ;
goto V_25;
}
V_74 = F_56 ( V_21 ) ;
if ( V_74 > V_80 )
{
F_5 ( V_76 , V_81 ) ;
goto V_25;
}
V_58 = F_57 ( V_21 , V_48 , V_49 , NULL ) ;
}
else
{
F_5 ( V_76 , V_88 ) ;
goto V_25;
}
if ( V_58 == NULL )
{
F_5 ( V_76 , V_28 ) ;
goto V_25;
}
if ( V_69 -> V_38 -> V_52 != NULL )
{
if ( V_58 -> V_52 != NULL )
F_31 ( V_58 -> V_52 ) ;
if ( ! ( V_58 -> V_52 = F_25 ( V_69 -> V_38 -> V_52 -> V_79 ) ) )
{
F_5 ( V_76 ,
V_27 ) ;
goto V_25;
}
memcpy ( V_58 -> V_52 , V_69 -> V_38 -> V_52 -> V_78 ,
V_69 -> V_38 -> V_52 -> V_79 ) ;
V_58 -> V_55 = V_69 -> V_38 -> V_52 -> V_79 ;
}
if ( ! V_69 -> V_67 || ! V_69 -> V_66 || ! V_69 -> V_66 -> V_78 )
{
F_5 ( V_76 , V_77 ) ;
goto V_25;
}
if ( ( V_60 = F_58 ( V_58 ) ) == NULL ) goto V_25;
F_59 ( V_58 , ( T_9 )
( V_69 -> V_66 -> V_78 [ 0 ] & ~ 0x01 ) ) ;
if ( ! F_60 ( V_58 , V_60 , V_69 -> V_66 -> V_78 ,
V_69 -> V_66 -> V_79 , NULL ) )
{
F_5 ( V_76 , V_28 ) ;
goto V_25;
}
if ( ( V_48 = F_53 ( V_69 -> V_67 , V_48 ) ) == NULL )
{
F_5 ( V_76 , V_30 ) ;
goto V_25;
}
if ( F_54 ( V_48 ) || F_55 ( V_48 ) )
{
F_5 ( V_76 , V_89 ) ;
goto V_25;
}
if ( F_56 ( V_48 ) > ( int ) V_74 + 1 )
{
F_5 ( V_76 , V_89 ) ;
goto V_25;
}
if ( V_69 -> V_68 == NULL )
{
if ( V_49 )
{
F_21 ( V_49 ) ;
V_49 = NULL ;
}
}
else
if ( ( V_49 = F_53 ( V_69 -> V_68 , V_49 ) ) == NULL )
{
F_5 ( V_76 , V_30 ) ;
goto V_25;
}
if ( ! F_61 ( V_58 , V_60 , V_48 , V_49 ) )
{
F_5 ( V_76 , V_28 ) ;
goto V_25;
}
V_17 = 1 ;
V_25: if ( ! V_17 )
{
if ( V_58 )
F_62 ( V_58 ) ;
V_58 = NULL ;
}
if ( V_21 )
F_21 ( V_21 ) ;
if ( V_48 )
F_21 ( V_48 ) ;
if ( V_49 )
F_21 ( V_49 ) ;
if ( V_60 )
F_63 ( V_60 ) ;
return ( V_58 ) ;
}
T_1 * F_64 ( const T_10 * V_69 )
{
T_1 * V_58 = NULL ;
int V_19 = 0 ;
if ( V_69 == NULL )
{
F_5 ( V_90 ,
V_91 ) ;
return NULL ;
}
if ( V_69 -> type == 0 )
{
V_19 = F_49 ( V_69 -> V_71 . V_72 ) ;
if ( ( V_58 = F_65 ( V_19 ) ) == NULL )
{
F_5 ( V_90 ,
V_92 ) ;
return NULL ;
}
F_66 ( V_58 , V_93 ) ;
}
else if ( V_69 -> type == 1 )
{
V_58 = F_47 ( V_69 -> V_71 . V_73 ) ;
if ( ! V_58 )
{
F_5 ( V_90 , V_28 ) ;
return NULL ;
}
F_66 ( V_58 , 0x0 ) ;
}
else if ( V_69 -> type == 2 )
{
return NULL ;
}
else
{
F_5 ( V_90 , V_77 ) ;
return NULL ;
}
return V_58 ;
}
T_1 * F_67 ( T_1 * * V_48 , const unsigned char * * V_94 , long V_57 )
{
T_1 * V_1 = NULL ;
T_10 * V_69 = NULL ;
if ( ( V_69 = F_68 ( NULL , V_94 , V_57 ) ) == NULL )
{
F_5 ( V_95 , V_96 ) ;
F_46 ( V_69 ) ;
return NULL ;
}
if ( ( V_1 = F_64 ( V_69 ) ) == NULL )
{
F_5 ( V_95 , V_97 ) ;
F_46 ( V_69 ) ;
return NULL ;
}
if ( V_48 && * V_48 )
F_62 ( * V_48 ) ;
if ( V_48 )
* V_48 = V_1 ;
F_46 ( V_69 ) ;
return ( V_1 ) ;
}
int F_69 ( const T_1 * V_48 , unsigned char * * V_98 )
{
int V_58 = 0 ;
T_10 * V_19 = F_42 ( V_48 , NULL ) ;
if ( V_19 == NULL )
{
F_5 ( V_99 , V_100 ) ;
return 0 ;
}
if ( ( V_58 = F_70 ( V_19 , V_98 ) ) == 0 )
{
F_5 ( V_99 , V_101 ) ;
F_46 ( V_19 ) ;
return 0 ;
}
F_46 ( V_19 ) ;
return ( V_58 ) ;
}
T_12 * F_71 ( T_12 * * V_48 , const unsigned char * * V_94 , long V_57 )
{
int V_17 = 0 ;
T_12 * V_58 = NULL ;
T_13 * V_102 = NULL ;
if ( ( V_102 = F_72 () ) == NULL )
{
F_5 ( V_103 , V_27 ) ;
return NULL ;
}
if ( ( V_102 = F_73 ( & V_102 , V_94 , V_57 ) ) == NULL )
{
F_5 ( V_103 , V_28 ) ;
F_74 ( V_102 ) ;
return NULL ;
}
if ( V_48 == NULL || * V_48 == NULL )
{
if ( ( V_58 = F_75 () ) == NULL )
{
F_5 ( V_103 ,
V_27 ) ;
goto V_25;
}
if ( V_48 )
* V_48 = V_58 ;
}
else
V_58 = * V_48 ;
if ( V_102 -> V_73 )
{
if ( V_58 -> V_1 )
F_62 ( V_58 -> V_1 ) ;
V_58 -> V_1 = F_64 ( V_102 -> V_73 ) ;
}
if ( V_58 -> V_1 == NULL )
{
F_5 ( V_103 , V_28 ) ;
goto V_25;
}
V_58 -> V_63 = V_102 -> V_63 ;
if ( V_102 -> V_104 )
{
V_58 -> V_102 = F_48 (
F_76 ( V_102 -> V_104 ) ,
F_77 ( V_102 -> V_104 ) ,
V_58 -> V_102 ) ;
if ( V_58 -> V_102 == NULL )
{
F_5 ( V_103 ,
V_51 ) ;
goto V_25;
}
}
else
{
F_5 ( V_103 ,
V_105 ) ;
goto V_25;
}
if ( V_102 -> V_106 )
{
const unsigned char * V_107 ;
T_6 V_108 ;
if ( V_58 -> V_109 )
F_78 ( V_58 -> V_109 ) ;
V_58 -> V_109 = F_58 ( V_58 -> V_1 ) ;
if ( V_58 -> V_109 == NULL )
{
F_5 ( V_103 , V_28 ) ;
goto V_25;
}
V_107 = F_76 ( V_102 -> V_106 ) ;
V_108 = F_77 ( V_102 -> V_106 ) ;
V_58 -> V_110 = ( T_9 ) ( V_107 [ 0 ] & ~ 0x01 ) ;
if ( ! F_60 ( V_58 -> V_1 , V_58 -> V_109 ,
V_107 , V_108 , NULL ) )
{
F_5 ( V_103 , V_28 ) ;
goto V_25;
}
}
V_17 = 1 ;
V_25:
if ( ! V_17 )
{
if ( V_58 )
F_79 ( V_58 ) ;
V_58 = NULL ;
}
if ( V_102 )
F_74 ( V_102 ) ;
return ( V_58 ) ;
}
int F_80 ( T_12 * V_48 , unsigned char * * V_98 )
{
int V_58 = 0 , V_17 = 0 ;
unsigned char * V_59 = NULL ;
T_6 V_111 = 0 , V_112 ;
T_13 * V_102 = NULL ;
if ( V_48 == NULL || V_48 -> V_1 == NULL || V_48 -> V_102 == NULL )
{
F_5 ( V_113 ,
V_114 ) ;
goto V_25;
}
if ( ( V_102 = F_72 () ) == NULL )
{
F_5 ( V_113 ,
V_27 ) ;
goto V_25;
}
V_102 -> V_63 = V_48 -> V_63 ;
V_111 = ( T_6 ) F_24 ( V_48 -> V_102 ) ;
V_59 = F_25 ( V_111 ) ;
if ( V_59 == NULL )
{
F_5 ( V_113 ,
V_27 ) ;
goto V_25;
}
if ( ! F_26 ( V_48 -> V_102 , V_59 ) )
{
F_5 ( V_113 , V_51 ) ;
goto V_25;
}
if ( ! F_27 ( V_102 -> V_104 , V_59 , V_111 ) )
{
F_5 ( V_113 , V_30 ) ;
goto V_25;
}
if ( ! ( V_48 -> V_115 & V_116 ) )
{
if ( ( V_102 -> V_73 = F_42 (
V_48 -> V_1 , V_102 -> V_73 ) ) == NULL )
{
F_5 ( V_113 , V_28 ) ;
goto V_25;
}
}
if ( ! ( V_48 -> V_115 & V_117 ) )
{
V_102 -> V_106 = F_81 () ;
if ( V_102 -> V_106 == NULL )
{
F_5 ( V_113 ,
V_27 ) ;
goto V_25;
}
V_112 = F_36 ( V_48 -> V_1 , V_48 -> V_109 ,
V_48 -> V_110 , NULL , 0 , NULL ) ;
if ( V_112 > V_111 )
{
unsigned char * V_118 = F_82 ( V_59 , V_112 ) ;
if ( ! V_118 )
{
F_5 ( V_113 , V_27 ) ;
goto V_25;
}
V_59 = V_118 ;
V_111 = V_112 ;
}
if ( ! F_36 ( V_48 -> V_1 , V_48 -> V_109 ,
V_48 -> V_110 , V_59 , V_111 , NULL ) )
{
F_5 ( V_113 , V_28 ) ;
goto V_25;
}
V_102 -> V_106 -> V_53 &= ~ ( V_54 | 0x07 ) ;
V_102 -> V_106 -> V_53 |= V_54 ;
if ( ! F_83 ( V_102 -> V_106 , V_59 ,
V_111 ) )
{
F_5 ( V_113 , V_30 ) ;
goto V_25;
}
}
if ( ( V_58 = F_84 ( V_102 , V_98 ) ) == 0 )
{
F_5 ( V_113 , V_28 ) ;
goto V_25;
}
V_17 = 1 ;
V_25:
if ( V_59 )
F_31 ( V_59 ) ;
if ( V_102 )
F_74 ( V_102 ) ;
return ( V_17 ? V_58 : 0 ) ;
}
int F_85 ( T_12 * V_48 , unsigned char * * V_98 )
{
if ( V_48 == NULL )
{
F_5 ( V_119 , V_114 ) ;
return 0 ;
}
return F_69 ( V_48 -> V_1 , V_98 ) ;
}
T_12 * F_86 ( T_12 * * V_48 , const unsigned char * * V_94 , long V_57 )
{
T_12 * V_58 ;
if ( V_94 == NULL || * V_94 == NULL )
{
F_5 ( V_120 , V_114 ) ;
return NULL ;
}
if ( V_48 == NULL || * V_48 == NULL )
{
if ( ( V_58 = F_75 () ) == NULL )
{
F_5 ( V_120 , V_27 ) ;
return NULL ;
}
if ( V_48 )
* V_48 = V_58 ;
}
else
V_58 = * V_48 ;
if ( ! F_67 ( & V_58 -> V_1 , V_94 , V_57 ) )
{
F_5 ( V_120 , V_28 ) ;
return NULL ;
}
return V_58 ;
}
T_12 * F_87 ( T_12 * * V_48 , const unsigned char * * V_94 , long V_57 )
{
T_12 * V_58 = NULL ;
if ( V_48 == NULL || ( * V_48 ) == NULL || ( * V_48 ) -> V_1 == NULL )
{
F_5 ( V_121 , V_114 ) ;
return 0 ;
}
V_58 = * V_48 ;
if ( V_58 -> V_109 == NULL &&
( V_58 -> V_109 = F_58 ( V_58 -> V_1 ) ) == NULL )
{
F_5 ( V_121 , V_27 ) ;
return 0 ;
}
if ( ! F_60 ( V_58 -> V_1 , V_58 -> V_109 , * V_94 , V_57 , NULL ) )
{
F_5 ( V_121 , V_28 ) ;
return 0 ;
}
V_58 -> V_110 = ( T_9 ) ( * V_94 [ 0 ] & ~ 0x01 ) ;
* V_94 += V_57 ;
return V_58 ;
}
int F_88 ( T_12 * V_48 , unsigned char * * V_98 )
{
T_6 V_111 = 0 ;
int V_122 = 0 ;
if ( V_48 == NULL )
{
F_5 ( V_123 , V_114 ) ;
return 0 ;
}
V_111 = F_36 ( V_48 -> V_1 , V_48 -> V_109 ,
V_48 -> V_110 , NULL , 0 , NULL ) ;
if ( V_98 == NULL || V_111 == 0 )
return V_111 ;
if ( * V_98 == NULL )
{
if ( ( * V_98 = F_25 ( V_111 ) ) == NULL )
{
F_5 ( V_123 , V_27 ) ;
return 0 ;
}
V_122 = 1 ;
}
if ( ! F_36 ( V_48 -> V_1 , V_48 -> V_109 , V_48 -> V_110 ,
* V_98 , V_111 , NULL ) )
{
F_5 ( V_123 , V_28 ) ;
F_31 ( * V_98 ) ;
* V_98 = NULL ;
return 0 ;
}
if ( ! V_122 )
* V_98 += V_111 ;
return V_111 ;
}
