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
{
int V_31 ;
T_4 * V_32 ;
V_16 -> V_21 . V_32 = F_14 () ;
V_32 = V_16 -> V_21 . V_32 ;
if ( V_32 == NULL )
{
F_5 ( V_23 , V_27 ) ;
goto V_25;
}
V_32 -> V_33 = ( long ) F_15 ( V_1 ) ;
V_31 = F_1 ( V_1 ) ;
if ( V_31 == 0 )
{
F_5 ( V_23 , V_28 ) ;
goto V_25;
}
if ( ( V_32 -> type = F_10 ( V_31 ) ) == NULL )
{
F_5 ( V_23 , V_24 ) ;
goto V_25;
}
if ( V_31 == V_6 )
{
unsigned int V_7 ;
if ( ! F_4 ( V_1 , & V_7 ) )
goto V_25;
V_32 -> V_21 . V_34 = F_16 () ;
if ( ! V_32 -> V_21 . V_34 )
{
F_5 ( V_23 , V_27 ) ;
goto V_25;
}
if ( ! F_17 ( V_32 -> V_21 . V_34 , ( long ) V_7 ) )
{
F_5 ( V_23 ,
V_30 ) ;
goto V_25;
}
}
else if ( V_31 == V_5 )
{
unsigned int V_12 , V_13 , V_14 ;
if ( ! F_6 ( V_1 , & V_12 , & V_13 , & V_14 ) )
goto V_25;
V_32 -> V_21 . V_35 = F_18 () ;
if ( ! V_32 -> V_21 . V_35 )
{
F_5 ( V_23 , V_27 ) ;
goto V_25;
}
V_32 -> V_21 . V_35 -> V_12 = ( long ) V_12 ;
V_32 -> V_21 . V_35 -> V_13 = ( long ) V_13 ;
V_32 -> V_21 . V_35 -> V_14 = ( long ) V_14 ;
}
else
{
V_32 -> V_21 . V_36 = F_19 () ;
if ( ! V_32 -> V_21 . V_36 )
{
F_5 ( V_23 , V_27 ) ;
goto V_25;
}
}
}
V_17 = 1 ;
V_25 : if ( V_19 )
F_20 ( V_19 ) ;
return ( V_17 ) ;
}
static int F_21 ( const T_1 * V_1 , T_5 * V_37 )
{
int V_17 = 0 , V_18 ;
T_3 * V_38 = NULL , * V_39 = NULL ;
unsigned char * V_40 = NULL , * V_41 = NULL ,
* V_42 = NULL , * V_43 = NULL ;
T_6 V_44 , V_45 ;
unsigned char V_46 = 0 ;
if ( ! V_1 || ! V_37 || ! V_37 -> V_47 || ! V_37 -> V_48 )
return 0 ;
if ( ( V_38 = F_11 () ) == NULL || ( V_39 = F_11 () ) == NULL )
{
F_5 ( V_49 , V_27 ) ;
goto V_25;
}
V_18 = F_2 ( F_3 ( V_1 ) ) ;
if ( V_18 == V_26 )
{
if ( ! F_12 ( V_1 , NULL , V_38 , V_39 , NULL ) )
{
F_5 ( V_49 , V_28 ) ;
goto V_25;
}
}
else
{
if ( ! F_22 ( V_1 , NULL , V_38 , V_39 , NULL ) )
{
F_5 ( V_49 , V_28 ) ;
goto V_25;
}
}
V_44 = ( T_6 ) F_23 ( V_38 ) ;
V_45 = ( T_6 ) F_23 ( V_39 ) ;
if ( V_44 == 0 )
{
V_42 = & V_46 ;
V_44 = 1 ;
}
else
{
if ( ( V_40 = F_24 ( V_44 ) ) == NULL )
{
F_5 ( V_49 ,
V_27 ) ;
goto V_25;
}
if ( ( V_44 = F_25 ( V_38 , V_40 ) ) == 0 )
{
F_5 ( V_49 , V_50 ) ;
goto V_25;
}
V_42 = V_40 ;
}
if ( V_45 == 0 )
{
V_43 = & V_46 ;
V_45 = 1 ;
}
else
{
if ( ( V_41 = F_24 ( V_45 ) ) == NULL )
{
F_5 ( V_49 ,
V_27 ) ;
goto V_25;
}
if ( ( V_45 = F_25 ( V_39 , V_41 ) ) == 0 )
{
F_5 ( V_49 , V_50 ) ;
goto V_25;
}
V_43 = V_41 ;
}
if ( ! F_26 ( V_37 -> V_47 , V_42 , V_44 ) ||
! F_26 ( V_37 -> V_48 , V_43 , V_45 ) )
{
F_5 ( V_49 , V_30 ) ;
goto V_25;
}
if ( V_1 -> V_51 )
{
if ( ! V_37 -> V_51 )
if ( ( V_37 -> V_51 = F_27 () ) == NULL )
{
F_5 ( V_49 , V_27 ) ;
goto V_25;
}
V_37 -> V_51 -> V_52 &= ~ ( V_53 | 0x07 ) ;
V_37 -> V_51 -> V_52 |= V_53 ;
if ( ! F_28 ( V_37 -> V_51 , V_1 -> V_51 ,
( int ) V_1 -> V_54 ) )
{
F_5 ( V_49 , V_30 ) ;
goto V_25;
}
}
else
{
if ( V_37 -> V_51 )
{
F_29 ( V_37 -> V_51 ) ;
V_37 -> V_51 = NULL ;
}
}
V_17 = 1 ;
V_25: if ( V_40 )
F_30 ( V_40 ) ;
if ( V_41 )
F_30 ( V_41 ) ;
if ( V_38 )
F_20 ( V_38 ) ;
if ( V_39 )
F_20 ( V_39 ) ;
return ( V_17 ) ;
}
static T_7 * F_31 ( const T_1 * V_1 ,
T_7 * V_55 )
{
int V_17 = 0 ;
T_6 V_56 = 0 ;
T_7 * V_57 = NULL ;
T_3 * V_19 = NULL ;
unsigned char * V_58 = NULL ;
const T_8 * V_59 = NULL ;
T_9 V_60 ;
if ( ( V_19 = F_11 () ) == NULL )
{
F_5 ( V_61 , V_27 ) ;
goto V_25;
}
if ( V_55 == NULL )
{
if ( ( V_57 = F_32 () ) == NULL )
{
F_5 ( V_61 ,
V_27 ) ;
goto V_25;
}
}
else
V_57 = V_55 ;
V_57 -> V_62 = ( long ) 0x1 ;
if ( ! F_7 ( V_1 , V_57 -> V_63 ) )
{
F_5 ( V_61 , V_28 ) ;
goto V_25;
}
if ( ! F_21 ( V_1 , V_57 -> V_37 ) )
{
F_5 ( V_61 , V_28 ) ;
goto V_25;
}
if ( ( V_59 = F_33 ( V_1 ) ) == NULL )
{
F_5 ( V_61 , V_64 ) ;
goto V_25;
}
V_60 = F_34 ( V_1 ) ;
V_56 = F_35 ( V_1 , V_59 , V_60 , NULL , V_56 , NULL ) ;
if ( V_56 == 0 )
{
F_5 ( V_61 , V_28 ) ;
goto V_25;
}
if ( ( V_58 = F_24 ( V_56 ) ) == NULL )
{
F_5 ( V_61 , V_27 ) ;
goto V_25;
}
if ( ! F_35 ( V_1 , V_59 , V_60 , V_58 , V_56 , NULL ) )
{
F_5 ( V_61 , V_28 ) ;
goto V_25;
}
if ( V_57 -> V_65 == NULL && ( V_57 -> V_65 = F_36 () ) == NULL )
{
F_5 ( V_61 , V_27 ) ;
goto V_25;
}
if ( ! F_37 ( V_57 -> V_65 , V_58 , V_56 ) )
{
F_5 ( V_61 , V_30 ) ;
goto V_25;
}
if ( ! F_38 ( V_1 , V_19 , NULL ) )
{
F_5 ( V_61 , V_28 ) ;
goto V_25;
}
V_57 -> V_66 = F_13 ( V_19 , V_57 -> V_66 ) ;
if ( V_57 -> V_66 == NULL )
{
F_5 ( V_61 , V_30 ) ;
goto V_25;
}
if ( F_39 ( V_1 , V_19 , NULL ) )
{
V_57 -> V_67 = F_13 ( V_19 , V_57 -> V_67 ) ;
if ( V_57 -> V_67 == NULL )
{
F_5 ( V_61 , V_30 ) ;
goto V_25;
}
}
V_17 = 1 ;
V_25 : if( ! V_17 )
{
if ( V_57 && ! V_55 )
F_40 ( V_57 ) ;
V_57 = NULL ;
}
if ( V_19 )
F_20 ( V_19 ) ;
if ( V_58 )
F_30 ( V_58 ) ;
return ( V_57 ) ;
}
T_10 * F_41 ( const T_1 * V_1 ,
T_10 * V_68 )
{
int V_17 = 1 , V_19 ;
T_10 * V_57 = V_68 ;
if ( V_57 == NULL )
{
if ( ( V_57 = F_42 () ) == NULL )
{
F_5 ( V_69 ,
V_27 ) ;
return NULL ;
}
}
else
{
if ( V_57 -> type == 0 && V_57 -> V_70 . V_71 )
F_8 ( V_57 -> V_70 . V_71 ) ;
else if ( V_57 -> type == 1 && V_57 -> V_70 . V_72 )
F_40 ( V_57 -> V_70 . V_72 ) ;
}
if ( F_43 ( V_1 ) )
{
V_19 = F_44 ( V_1 ) ;
if ( V_19 )
{
V_57 -> type = 0 ;
if ( ( V_57 -> V_70 . V_71 = F_10 ( V_19 ) ) == NULL )
V_17 = 0 ;
}
else
V_17 = 0 ;
}
else
{
V_57 -> type = 1 ;
if ( ( V_57 -> V_70 . V_72 = F_31 (
V_1 , NULL ) ) == NULL )
V_17 = 0 ;
}
if ( ! V_17 )
{
F_45 ( V_57 ) ;
return NULL ;
}
return V_57 ;
}
static T_1 * F_46 ( const T_7 * V_68 )
{
int V_17 = 0 , V_19 ;
T_1 * V_57 = NULL ;
T_3 * V_21 = NULL , * V_47 = NULL , * V_48 = NULL ;
T_8 * V_59 = NULL ;
long V_73 ;
if ( ! V_68 -> V_63 || ! V_68 -> V_63 -> V_20 ||
! V_68 -> V_63 -> V_21 . V_74 )
{
F_5 ( V_75 , V_76 ) ;
goto V_25;
}
if ( ! V_68 -> V_37 || ! V_68 -> V_37 -> V_47 ||
! V_68 -> V_37 -> V_47 -> V_77 || ! V_68 -> V_37 -> V_48 ||
! V_68 -> V_37 -> V_48 -> V_77 )
{
F_5 ( V_75 , V_76 ) ;
goto V_25;
}
V_47 = F_47 ( V_68 -> V_37 -> V_47 -> V_77 , V_68 -> V_37 -> V_47 -> V_78 , NULL ) ;
if ( V_47 == NULL )
{
F_5 ( V_75 , V_50 ) ;
goto V_25;
}
V_48 = F_47 ( V_68 -> V_37 -> V_48 -> V_77 , V_68 -> V_37 -> V_48 -> V_78 , NULL ) ;
if ( V_48 == NULL )
{
F_5 ( V_75 , V_50 ) ;
goto V_25;
}
V_19 = F_48 ( V_68 -> V_63 -> V_20 ) ;
if ( V_19 == V_3 )
{
T_4 * V_32 ;
V_32 = V_68 -> V_63 -> V_21 . V_32 ;
V_73 = V_32 -> V_33 ;
if ( V_73 > V_79 )
{
F_5 ( V_75 , V_80 ) ;
goto V_25;
}
if ( ( V_21 = F_11 () ) == NULL )
{
F_5 ( V_75 , V_27 ) ;
goto V_25;
}
V_19 = F_48 ( V_32 -> type ) ;
if ( V_19 == V_6 )
{
long V_81 ;
if ( ! V_32 -> V_21 . V_34 )
{
F_5 ( V_75 , V_76 ) ;
goto V_25;
}
V_81 = F_49 ( V_32 -> V_21 . V_34 ) ;
if ( ! ( V_32 -> V_33 > V_81 && V_81 > 0 ) )
{
F_5 ( V_75 , V_82 ) ;
goto V_25;
}
if ( ! F_50 ( V_21 , ( int ) V_32 -> V_33 ) )
goto V_25;
if ( ! F_50 ( V_21 , ( int ) V_81 ) )
goto V_25;
if ( ! F_50 ( V_21 , 0 ) )
goto V_25;
}
else if ( V_19 == V_5 )
{
T_11 * V_83 ;
V_83 = V_32 -> V_21 . V_35 ;
if ( ! V_83 )
{
F_5 ( V_75 , V_76 ) ;
goto V_25;
}
if ( ! ( V_32 -> V_33 > V_83 -> V_14 && V_83 -> V_14 > V_83 -> V_13 && V_83 -> V_13 > V_83 -> V_12 && V_83 -> V_12 > 0 ) )
{
F_5 ( V_75 , V_84 ) ;
goto V_25;
}
if ( ! F_50 ( V_21 , ( int ) V_32 -> V_33 ) ) goto V_25;
if ( ! F_50 ( V_21 , ( int ) V_83 -> V_12 ) ) goto V_25;
if ( ! F_50 ( V_21 , ( int ) V_83 -> V_13 ) ) goto V_25;
if ( ! F_50 ( V_21 , ( int ) V_83 -> V_14 ) ) goto V_25;
if ( ! F_50 ( V_21 , 0 ) ) goto V_25;
}
else if ( V_19 == V_85 )
{
F_5 ( V_75 , V_86 ) ;
goto V_25;
}
else
{
F_5 ( V_75 , V_76 ) ;
goto V_25;
}
V_57 = F_51 ( V_21 , V_47 , V_48 , NULL ) ;
}
else if ( V_19 == V_26 )
{
if ( ! V_68 -> V_63 -> V_21 . V_29 )
{
F_5 ( V_75 , V_76 ) ;
goto V_25;
}
V_21 = F_52 ( V_68 -> V_63 -> V_21 . V_29 , NULL ) ;
if ( V_21 == NULL )
{
F_5 ( V_75 , V_30 ) ;
goto V_25;
}
if ( F_53 ( V_21 ) || F_54 ( V_21 ) )
{
F_5 ( V_75 , V_87 ) ;
goto V_25;
}
V_73 = F_55 ( V_21 ) ;
if ( V_73 > V_79 )
{
F_5 ( V_75 , V_80 ) ;
goto V_25;
}
V_57 = F_56 ( V_21 , V_47 , V_48 , NULL ) ;
}
else
{
F_5 ( V_75 , V_87 ) ;
goto V_25;
}
if ( V_57 == NULL )
{
F_5 ( V_75 , V_28 ) ;
goto V_25;
}
if ( V_68 -> V_37 -> V_51 != NULL )
{
if ( V_57 -> V_51 != NULL )
F_30 ( V_57 -> V_51 ) ;
if ( ! ( V_57 -> V_51 = F_24 ( V_68 -> V_37 -> V_51 -> V_78 ) ) )
{
F_5 ( V_75 ,
V_27 ) ;
goto V_25;
}
memcpy ( V_57 -> V_51 , V_68 -> V_37 -> V_51 -> V_77 ,
V_68 -> V_37 -> V_51 -> V_78 ) ;
V_57 -> V_54 = V_68 -> V_37 -> V_51 -> V_78 ;
}
if ( ! V_68 -> V_66 || ! V_68 -> V_65 || ! V_68 -> V_65 -> V_77 )
{
F_5 ( V_75 , V_76 ) ;
goto V_25;
}
if ( ( V_59 = F_57 ( V_57 ) ) == NULL ) goto V_25;
F_58 ( V_57 , ( T_9 )
( V_68 -> V_65 -> V_77 [ 0 ] & ~ 0x01 ) ) ;
if ( ! F_59 ( V_57 , V_59 , V_68 -> V_65 -> V_77 ,
V_68 -> V_65 -> V_78 , NULL ) )
{
F_5 ( V_75 , V_28 ) ;
goto V_25;
}
if ( ( V_47 = F_52 ( V_68 -> V_66 , V_47 ) ) == NULL )
{
F_5 ( V_75 , V_30 ) ;
goto V_25;
}
if ( F_53 ( V_47 ) || F_54 ( V_47 ) )
{
F_5 ( V_75 , V_88 ) ;
goto V_25;
}
if ( F_55 ( V_47 ) > ( int ) V_73 + 1 )
{
F_5 ( V_75 , V_88 ) ;
goto V_25;
}
if ( V_68 -> V_67 == NULL )
{
if ( V_48 )
{
F_20 ( V_48 ) ;
V_48 = NULL ;
}
}
else
if ( ( V_48 = F_52 ( V_68 -> V_67 , V_48 ) ) == NULL )
{
F_5 ( V_75 , V_30 ) ;
goto V_25;
}
if ( ! F_60 ( V_57 , V_59 , V_47 , V_48 ) )
{
F_5 ( V_75 , V_28 ) ;
goto V_25;
}
V_17 = 1 ;
V_25: if ( ! V_17 )
{
if ( V_57 )
F_61 ( V_57 ) ;
V_57 = NULL ;
}
if ( V_21 )
F_20 ( V_21 ) ;
if ( V_47 )
F_20 ( V_47 ) ;
if ( V_48 )
F_20 ( V_48 ) ;
if ( V_59 )
F_62 ( V_59 ) ;
return ( V_57 ) ;
}
T_1 * F_63 ( const T_10 * V_68 )
{
T_1 * V_57 = NULL ;
int V_19 = 0 ;
if ( V_68 == NULL )
{
F_5 ( V_89 ,
V_90 ) ;
return NULL ;
}
if ( V_68 -> type == 0 )
{
V_19 = F_48 ( V_68 -> V_70 . V_71 ) ;
if ( ( V_57 = F_64 ( V_19 ) ) == NULL )
{
F_5 ( V_89 ,
V_91 ) ;
return NULL ;
}
F_65 ( V_57 , V_92 ) ;
}
else if ( V_68 -> type == 1 )
{
V_57 = F_46 ( V_68 -> V_70 . V_72 ) ;
if ( ! V_57 )
{
F_5 ( V_89 , V_28 ) ;
return NULL ;
}
F_65 ( V_57 , 0x0 ) ;
}
else if ( V_68 -> type == 2 )
{
return NULL ;
}
else
{
F_5 ( V_89 , V_76 ) ;
return NULL ;
}
return V_57 ;
}
T_1 * F_66 ( T_1 * * V_47 , const unsigned char * * V_93 , long V_56 )
{
T_1 * V_1 = NULL ;
T_10 * V_68 = NULL ;
if ( ( V_68 = F_67 ( NULL , V_93 , V_56 ) ) == NULL )
{
F_5 ( V_94 , V_95 ) ;
F_45 ( V_68 ) ;
return NULL ;
}
if ( ( V_1 = F_63 ( V_68 ) ) == NULL )
{
F_5 ( V_94 , V_96 ) ;
return NULL ;
}
if ( V_47 && * V_47 )
F_61 ( * V_47 ) ;
if ( V_47 )
* V_47 = V_1 ;
F_45 ( V_68 ) ;
return ( V_1 ) ;
}
int F_68 ( const T_1 * V_47 , unsigned char * * V_97 )
{
int V_57 = 0 ;
T_10 * V_19 = F_41 ( V_47 , NULL ) ;
if ( V_19 == NULL )
{
F_5 ( V_98 , V_99 ) ;
return 0 ;
}
if ( ( V_57 = F_69 ( V_19 , V_97 ) ) == 0 )
{
F_5 ( V_98 , V_100 ) ;
F_45 ( V_19 ) ;
return 0 ;
}
F_45 ( V_19 ) ;
return ( V_57 ) ;
}
T_12 * F_70 ( T_12 * * V_47 , const unsigned char * * V_93 , long V_56 )
{
int V_17 = 0 ;
T_12 * V_57 = NULL ;
T_13 * V_101 = NULL ;
if ( ( V_101 = F_71 () ) == NULL )
{
F_5 ( V_102 , V_27 ) ;
return NULL ;
}
if ( ( V_101 = F_72 ( & V_101 , V_93 , V_56 ) ) == NULL )
{
F_5 ( V_102 , V_28 ) ;
F_73 ( V_101 ) ;
return NULL ;
}
if ( V_47 == NULL || * V_47 == NULL )
{
if ( ( V_57 = F_74 () ) == NULL )
{
F_5 ( V_102 ,
V_27 ) ;
goto V_25;
}
if ( V_47 )
* V_47 = V_57 ;
}
else
V_57 = * V_47 ;
if ( V_101 -> V_72 )
{
if ( V_57 -> V_1 )
F_61 ( V_57 -> V_1 ) ;
V_57 -> V_1 = F_63 ( V_101 -> V_72 ) ;
}
if ( V_57 -> V_1 == NULL )
{
F_5 ( V_102 , V_28 ) ;
goto V_25;
}
V_57 -> V_62 = V_101 -> V_62 ;
if ( V_101 -> V_103 )
{
V_57 -> V_101 = F_47 (
F_75 ( V_101 -> V_103 ) ,
F_76 ( V_101 -> V_103 ) ,
V_57 -> V_101 ) ;
if ( V_57 -> V_101 == NULL )
{
F_5 ( V_102 ,
V_50 ) ;
goto V_25;
}
}
else
{
F_5 ( V_102 ,
V_104 ) ;
goto V_25;
}
if ( V_101 -> V_105 )
{
const unsigned char * V_106 ;
T_6 V_107 ;
if ( V_57 -> V_108 )
F_77 ( V_57 -> V_108 ) ;
V_57 -> V_108 = F_57 ( V_57 -> V_1 ) ;
if ( V_57 -> V_108 == NULL )
{
F_5 ( V_102 , V_28 ) ;
goto V_25;
}
V_106 = F_75 ( V_101 -> V_105 ) ;
V_107 = F_76 ( V_101 -> V_105 ) ;
V_57 -> V_109 = ( T_9 ) ( V_106 [ 0 ] & ~ 0x01 ) ;
if ( ! F_59 ( V_57 -> V_1 , V_57 -> V_108 ,
V_106 , V_107 , NULL ) )
{
F_5 ( V_102 , V_28 ) ;
goto V_25;
}
}
V_17 = 1 ;
V_25:
if ( ! V_17 )
{
if ( V_57 )
F_78 ( V_57 ) ;
V_57 = NULL ;
}
if ( V_101 )
F_73 ( V_101 ) ;
return ( V_57 ) ;
}
int F_79 ( T_12 * V_47 , unsigned char * * V_97 )
{
int V_57 = 0 , V_17 = 0 ;
unsigned char * V_58 = NULL ;
T_6 V_110 = 0 , V_111 ;
T_13 * V_101 = NULL ;
if ( V_47 == NULL || V_47 -> V_1 == NULL || V_47 -> V_101 == NULL )
{
F_5 ( V_112 ,
V_113 ) ;
goto V_25;
}
if ( ( V_101 = F_71 () ) == NULL )
{
F_5 ( V_112 ,
V_27 ) ;
goto V_25;
}
V_101 -> V_62 = V_47 -> V_62 ;
V_110 = ( T_6 ) F_23 ( V_47 -> V_101 ) ;
V_58 = F_24 ( V_110 ) ;
if ( V_58 == NULL )
{
F_5 ( V_112 ,
V_27 ) ;
goto V_25;
}
if ( ! F_25 ( V_47 -> V_101 , V_58 ) )
{
F_5 ( V_112 , V_50 ) ;
goto V_25;
}
if ( ! F_26 ( V_101 -> V_103 , V_58 , V_110 ) )
{
F_5 ( V_112 , V_30 ) ;
goto V_25;
}
if ( ! ( V_47 -> V_114 & V_115 ) )
{
if ( ( V_101 -> V_72 = F_41 (
V_47 -> V_1 , V_101 -> V_72 ) ) == NULL )
{
F_5 ( V_112 , V_28 ) ;
goto V_25;
}
}
if ( ! ( V_47 -> V_114 & V_116 ) )
{
V_101 -> V_105 = F_80 () ;
if ( V_101 -> V_105 == NULL )
{
F_5 ( V_112 ,
V_27 ) ;
goto V_25;
}
V_111 = F_35 ( V_47 -> V_1 , V_47 -> V_108 ,
V_47 -> V_109 , NULL , 0 , NULL ) ;
if ( V_111 > V_110 )
{
unsigned char * V_117 = F_81 ( V_58 , V_111 ) ;
if ( ! V_117 )
{
F_5 ( V_112 , V_27 ) ;
goto V_25;
}
V_58 = V_117 ;
V_110 = V_111 ;
}
if ( ! F_35 ( V_47 -> V_1 , V_47 -> V_108 ,
V_47 -> V_109 , V_58 , V_110 , NULL ) )
{
F_5 ( V_112 , V_28 ) ;
goto V_25;
}
V_101 -> V_105 -> V_52 &= ~ ( V_53 | 0x07 ) ;
V_101 -> V_105 -> V_52 |= V_53 ;
if ( ! F_82 ( V_101 -> V_105 , V_58 ,
V_110 ) )
{
F_5 ( V_112 , V_30 ) ;
goto V_25;
}
}
if ( ( V_57 = F_83 ( V_101 , V_97 ) ) == 0 )
{
F_5 ( V_112 , V_28 ) ;
goto V_25;
}
V_17 = 1 ;
V_25:
if ( V_58 )
F_30 ( V_58 ) ;
if ( V_101 )
F_73 ( V_101 ) ;
return ( V_17 ? V_57 : 0 ) ;
}
int F_84 ( T_12 * V_47 , unsigned char * * V_97 )
{
if ( V_47 == NULL )
{
F_5 ( V_118 , V_113 ) ;
return 0 ;
}
return F_68 ( V_47 -> V_1 , V_97 ) ;
}
T_12 * F_85 ( T_12 * * V_47 , const unsigned char * * V_93 , long V_56 )
{
T_12 * V_57 ;
if ( V_93 == NULL || * V_93 == NULL )
{
F_5 ( V_119 , V_113 ) ;
return NULL ;
}
if ( V_47 == NULL || * V_47 == NULL )
{
if ( ( V_57 = F_74 () ) == NULL )
{
F_5 ( V_119 , V_27 ) ;
return NULL ;
}
if ( V_47 )
* V_47 = V_57 ;
}
else
V_57 = * V_47 ;
if ( ! F_66 ( & V_57 -> V_1 , V_93 , V_56 ) )
{
F_5 ( V_119 , V_28 ) ;
return NULL ;
}
return V_57 ;
}
T_12 * F_86 ( T_12 * * V_47 , const unsigned char * * V_93 , long V_56 )
{
T_12 * V_57 = NULL ;
if ( V_47 == NULL || ( * V_47 ) == NULL || ( * V_47 ) -> V_1 == NULL )
{
F_5 ( V_120 , V_113 ) ;
return 0 ;
}
V_57 = * V_47 ;
if ( V_57 -> V_108 == NULL &&
( V_57 -> V_108 = F_57 ( V_57 -> V_1 ) ) == NULL )
{
F_5 ( V_120 , V_27 ) ;
return 0 ;
}
if ( ! F_59 ( V_57 -> V_1 , V_57 -> V_108 , * V_93 , V_56 , NULL ) )
{
F_5 ( V_120 , V_28 ) ;
return 0 ;
}
V_57 -> V_109 = ( T_9 ) ( * V_93 [ 0 ] & ~ 0x01 ) ;
* V_93 += V_56 ;
return V_57 ;
}
int F_87 ( T_12 * V_47 , unsigned char * * V_97 )
{
T_6 V_110 = 0 ;
int V_121 = 0 ;
if ( V_47 == NULL )
{
F_5 ( V_122 , V_113 ) ;
return 0 ;
}
V_110 = F_35 ( V_47 -> V_1 , V_47 -> V_108 ,
V_47 -> V_109 , NULL , 0 , NULL ) ;
if ( V_97 == NULL || V_110 == 0 )
return V_110 ;
if ( * V_97 == NULL )
{
if ( ( * V_97 = F_24 ( V_110 ) ) == NULL )
{
F_5 ( V_122 , V_27 ) ;
return 0 ;
}
V_121 = 1 ;
}
if ( ! F_35 ( V_47 -> V_1 , V_47 -> V_108 , V_47 -> V_109 ,
* V_97 , V_110 , NULL ) )
{
F_5 ( V_122 , V_28 ) ;
F_30 ( * V_97 ) ;
* V_97 = NULL ;
return 0 ;
}
if ( ! V_121 )
* V_97 += V_110 ;
return V_110 ;
}
