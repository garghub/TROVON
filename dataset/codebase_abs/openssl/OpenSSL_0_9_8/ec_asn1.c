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
if ( ! F_28 ( V_37 -> V_51 , V_1 -> V_51 ,
( int ) V_1 -> V_52 ) )
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
T_7 * V_53 )
{
int V_17 = 0 ;
T_6 V_54 = 0 ;
T_7 * V_55 = NULL ;
T_3 * V_19 = NULL ;
unsigned char * V_56 = NULL ;
const T_8 * V_57 = NULL ;
T_9 V_58 ;
if ( ( V_19 = F_11 () ) == NULL )
{
F_5 ( V_59 , V_27 ) ;
goto V_25;
}
if ( V_53 == NULL )
{
if ( ( V_55 = F_32 () ) == NULL )
{
F_5 ( V_59 ,
V_27 ) ;
goto V_25;
}
}
else
V_55 = V_53 ;
V_55 -> V_60 = ( long ) 0x1 ;
if ( ! F_7 ( V_1 , V_55 -> V_61 ) )
{
F_5 ( V_59 , V_28 ) ;
goto V_25;
}
if ( ! F_21 ( V_1 , V_55 -> V_37 ) )
{
F_5 ( V_59 , V_28 ) ;
goto V_25;
}
if ( ( V_57 = F_33 ( V_1 ) ) == NULL )
{
F_5 ( V_59 , V_62 ) ;
goto V_25;
}
V_58 = F_34 ( V_1 ) ;
V_54 = F_35 ( V_1 , V_57 , V_58 , NULL , V_54 , NULL ) ;
if ( V_54 == 0 )
{
F_5 ( V_59 , V_28 ) ;
goto V_25;
}
if ( ( V_56 = F_24 ( V_54 ) ) == NULL )
{
F_5 ( V_59 , V_27 ) ;
goto V_25;
}
if ( ! F_35 ( V_1 , V_57 , V_58 , V_56 , V_54 , NULL ) )
{
F_5 ( V_59 , V_28 ) ;
goto V_25;
}
if ( V_55 -> V_63 == NULL && ( V_55 -> V_63 = F_36 () ) == NULL )
{
F_5 ( V_59 , V_27 ) ;
goto V_25;
}
if ( ! F_37 ( V_55 -> V_63 , V_56 , V_54 ) )
{
F_5 ( V_59 , V_30 ) ;
goto V_25;
}
if ( ! F_38 ( V_1 , V_19 , NULL ) )
{
F_5 ( V_59 , V_28 ) ;
goto V_25;
}
V_55 -> V_64 = F_13 ( V_19 , V_55 -> V_64 ) ;
if ( V_55 -> V_64 == NULL )
{
F_5 ( V_59 , V_30 ) ;
goto V_25;
}
if ( F_39 ( V_1 , V_19 , NULL ) )
{
V_55 -> V_65 = F_13 ( V_19 , V_55 -> V_65 ) ;
if ( V_55 -> V_65 == NULL )
{
F_5 ( V_59 , V_30 ) ;
goto V_25;
}
}
V_17 = 1 ;
V_25 : if( ! V_17 )
{
if ( V_55 && ! V_53 )
F_40 ( V_55 ) ;
V_55 = NULL ;
}
if ( V_19 )
F_20 ( V_19 ) ;
if ( V_56 )
F_30 ( V_56 ) ;
return ( V_55 ) ;
}
T_10 * F_41 ( const T_1 * V_1 ,
T_10 * V_66 )
{
int V_17 = 1 , V_19 ;
T_10 * V_55 = V_66 ;
if ( V_55 == NULL )
{
if ( ( V_55 = F_42 () ) == NULL )
{
F_5 ( V_67 ,
V_27 ) ;
return NULL ;
}
}
else
{
if ( V_55 -> type == 0 && V_55 -> V_68 . V_69 )
F_8 ( V_55 -> V_68 . V_69 ) ;
else if ( V_55 -> type == 1 && V_55 -> V_68 . V_70 )
F_40 ( V_55 -> V_68 . V_70 ) ;
}
if ( F_43 ( V_1 ) )
{
V_19 = F_44 ( V_1 ) ;
if ( V_19 )
{
V_55 -> type = 0 ;
if ( ( V_55 -> V_68 . V_69 = F_10 ( V_19 ) ) == NULL )
V_17 = 0 ;
}
else
V_17 = 0 ;
}
else
{
V_55 -> type = 1 ;
if ( ( V_55 -> V_68 . V_70 = F_31 (
V_1 , NULL ) ) == NULL )
V_17 = 0 ;
}
if ( ! V_17 )
{
F_45 ( V_55 ) ;
return NULL ;
}
return V_55 ;
}
static T_1 * F_46 ( const T_7 * V_66 )
{
int V_17 = 0 , V_19 ;
T_1 * V_55 = NULL ;
T_3 * V_21 = NULL , * V_47 = NULL , * V_48 = NULL ;
T_8 * V_57 = NULL ;
if ( ! V_66 -> V_61 || ! V_66 -> V_61 -> V_20 ||
! V_66 -> V_61 -> V_21 . V_71 )
{
F_5 ( V_72 , V_73 ) ;
goto V_25;
}
if ( ! V_66 -> V_37 || ! V_66 -> V_37 -> V_47 ||
! V_66 -> V_37 -> V_47 -> V_74 || ! V_66 -> V_37 -> V_48 ||
! V_66 -> V_37 -> V_48 -> V_74 )
{
F_5 ( V_72 , V_73 ) ;
goto V_25;
}
V_47 = F_47 ( V_66 -> V_37 -> V_47 -> V_74 , V_66 -> V_37 -> V_47 -> V_75 , NULL ) ;
if ( V_47 == NULL )
{
F_5 ( V_72 , V_50 ) ;
goto V_25;
}
V_48 = F_47 ( V_66 -> V_37 -> V_48 -> V_74 , V_66 -> V_37 -> V_48 -> V_75 , NULL ) ;
if ( V_48 == NULL )
{
F_5 ( V_72 , V_50 ) ;
goto V_25;
}
V_19 = F_48 ( V_66 -> V_61 -> V_20 ) ;
if ( V_19 == V_3 )
{
T_4 * V_32 ;
V_32 = V_66 -> V_61 -> V_21 . V_32 ;
if ( ( V_21 = F_11 () ) == NULL )
{
F_5 ( V_72 , V_27 ) ;
goto V_25;
}
V_19 = F_48 ( V_32 -> type ) ;
if ( V_19 == V_6 )
{
long V_76 ;
if ( ! V_32 -> V_21 . V_34 )
{
F_5 ( V_72 , V_73 ) ;
goto V_25;
}
V_76 = F_49 ( V_32 -> V_21 . V_34 ) ;
if ( ! F_50 ( V_21 , ( int ) V_32 -> V_33 ) )
goto V_25;
if ( ! F_50 ( V_21 , ( int ) V_76 ) )
goto V_25;
if ( ! F_50 ( V_21 , 0 ) )
goto V_25;
}
else if ( V_19 == V_5 )
{
T_11 * V_77 ;
V_77 = V_32 -> V_21 . V_35 ;
if ( ! V_77 )
{
F_5 ( V_72 , V_73 ) ;
goto V_25;
}
if ( ! F_50 ( V_21 , ( int ) V_32 -> V_33 ) ) goto V_25;
if ( ! F_50 ( V_21 , ( int ) V_77 -> V_12 ) ) goto V_25;
if ( ! F_50 ( V_21 , ( int ) V_77 -> V_13 ) ) goto V_25;
if ( ! F_50 ( V_21 , ( int ) V_77 -> V_14 ) ) goto V_25;
if ( ! F_50 ( V_21 , 0 ) ) goto V_25;
}
else if ( V_19 == V_78 )
{
F_5 ( V_72 , V_79 ) ;
goto V_25;
}
else
{
F_5 ( V_72 , V_73 ) ;
goto V_25;
}
V_55 = F_51 ( V_21 , V_47 , V_48 , NULL ) ;
if ( V_55 == NULL )
{
F_5 ( V_72 , V_28 ) ;
goto V_25;
}
}
else if ( V_19 == V_26 )
{
if ( ! V_66 -> V_61 -> V_21 . V_29 )
{
F_5 ( V_72 , V_73 ) ;
goto V_25;
}
V_21 = F_52 ( V_66 -> V_61 -> V_21 . V_29 , NULL ) ;
if ( V_21 == NULL )
{
F_5 ( V_72 , V_30 ) ;
goto V_25;
}
V_55 = F_53 ( V_21 , V_47 , V_48 , NULL ) ;
if ( V_55 == NULL )
{
F_5 ( V_72 , V_28 ) ;
goto V_25;
}
}
if ( V_66 -> V_37 -> V_51 != NULL )
{
if ( V_55 -> V_51 != NULL )
F_30 ( V_55 -> V_51 ) ;
if ( ! ( V_55 -> V_51 = F_24 ( V_66 -> V_37 -> V_51 -> V_75 ) ) )
{
F_5 ( V_72 ,
V_27 ) ;
goto V_25;
}
memcpy ( V_55 -> V_51 , V_66 -> V_37 -> V_51 -> V_74 ,
V_66 -> V_37 -> V_51 -> V_75 ) ;
V_55 -> V_52 = V_66 -> V_37 -> V_51 -> V_75 ;
}
if ( ! V_66 -> V_64 || ! V_66 -> V_63 || ! V_66 -> V_63 -> V_74 )
{
F_5 ( V_72 , V_73 ) ;
goto V_25;
}
if ( ( V_57 = F_54 ( V_55 ) ) == NULL ) goto V_25;
F_55 ( V_55 , ( T_9 )
( V_66 -> V_63 -> V_74 [ 0 ] & ~ 0x01 ) ) ;
if ( ! F_56 ( V_55 , V_57 , V_66 -> V_63 -> V_74 ,
V_66 -> V_63 -> V_75 , NULL ) )
{
F_5 ( V_72 , V_28 ) ;
goto V_25;
}
if ( ( V_47 = F_52 ( V_66 -> V_64 , V_47 ) ) == NULL )
{
F_5 ( V_72 , V_30 ) ;
goto V_25;
}
if ( V_66 -> V_65 == NULL )
{
if ( V_48 )
{
F_20 ( V_48 ) ;
V_48 = NULL ;
}
}
else
if ( ( V_48 = F_52 ( V_66 -> V_65 , V_48 ) ) == NULL )
{
F_5 ( V_72 , V_30 ) ;
goto V_25;
}
if ( ! F_57 ( V_55 , V_57 , V_47 , V_48 ) )
{
F_5 ( V_72 , V_28 ) ;
goto V_25;
}
V_17 = 1 ;
V_25: if ( ! V_17 )
{
if ( V_55 )
F_58 ( V_55 ) ;
V_55 = NULL ;
}
if ( V_21 )
F_20 ( V_21 ) ;
if ( V_47 )
F_20 ( V_47 ) ;
if ( V_48 )
F_20 ( V_48 ) ;
if ( V_57 )
F_59 ( V_57 ) ;
return ( V_55 ) ;
}
T_1 * F_60 ( const T_10 * V_66 )
{
T_1 * V_55 = NULL ;
int V_19 = 0 ;
if ( V_66 == NULL )
{
F_5 ( V_80 ,
V_81 ) ;
return NULL ;
}
if ( V_66 -> type == 0 )
{
V_19 = F_48 ( V_66 -> V_68 . V_69 ) ;
if ( ( V_55 = F_61 ( V_19 ) ) == NULL )
{
F_5 ( V_80 ,
V_82 ) ;
return NULL ;
}
F_62 ( V_55 , V_83 ) ;
}
else if ( V_66 -> type == 1 )
{
V_55 = F_46 ( V_66 -> V_68 . V_70 ) ;
if ( ! V_55 )
{
F_5 ( V_80 , V_28 ) ;
return NULL ;
}
F_62 ( V_55 , 0x0 ) ;
}
else if ( V_66 -> type == 2 )
{
return NULL ;
}
else
{
F_5 ( V_80 , V_73 ) ;
return NULL ;
}
return V_55 ;
}
T_1 * F_63 ( T_1 * * V_47 , const unsigned char * * V_84 , long V_54 )
{
T_1 * V_1 = NULL ;
T_10 * V_66 = NULL ;
if ( ( V_66 = F_64 ( NULL , V_84 , V_54 ) ) == NULL )
{
F_5 ( V_85 , V_86 ) ;
F_45 ( V_66 ) ;
return NULL ;
}
if ( ( V_1 = F_60 ( V_66 ) ) == NULL )
{
F_5 ( V_85 , V_87 ) ;
return NULL ;
}
if ( V_47 && * V_47 )
F_58 ( * V_47 ) ;
if ( V_47 )
* V_47 = V_1 ;
F_45 ( V_66 ) ;
return ( V_1 ) ;
}
int F_65 ( const T_1 * V_47 , unsigned char * * V_88 )
{
int V_55 = 0 ;
T_10 * V_19 = F_41 ( V_47 , NULL ) ;
if ( V_19 == NULL )
{
F_5 ( V_89 , V_90 ) ;
return 0 ;
}
if ( ( V_55 = F_66 ( V_19 , V_88 ) ) == 0 )
{
F_5 ( V_89 , V_91 ) ;
F_45 ( V_19 ) ;
return 0 ;
}
F_45 ( V_19 ) ;
return ( V_55 ) ;
}
T_12 * F_67 ( T_12 * * V_47 , const unsigned char * * V_84 , long V_54 )
{
int V_17 = 0 ;
T_12 * V_55 = NULL ;
T_13 * V_92 = NULL ;
if ( ( V_92 = F_68 () ) == NULL )
{
F_5 ( V_93 , V_27 ) ;
return NULL ;
}
if ( ( V_92 = F_69 ( & V_92 , V_84 , V_54 ) ) == NULL )
{
F_5 ( V_93 , V_28 ) ;
F_70 ( V_92 ) ;
return NULL ;
}
if ( V_47 == NULL || * V_47 == NULL )
{
if ( ( V_55 = F_71 () ) == NULL )
{
F_5 ( V_93 ,
V_27 ) ;
goto V_25;
}
if ( V_47 )
* V_47 = V_55 ;
}
else
V_55 = * V_47 ;
if ( V_92 -> V_70 )
{
if ( V_55 -> V_1 )
F_58 ( V_55 -> V_1 ) ;
V_55 -> V_1 = F_60 ( V_92 -> V_70 ) ;
}
if ( V_55 -> V_1 == NULL )
{
F_5 ( V_93 , V_28 ) ;
goto V_25;
}
V_55 -> V_60 = V_92 -> V_60 ;
if ( V_92 -> V_94 )
{
V_55 -> V_92 = F_47 (
F_72 ( V_92 -> V_94 ) ,
F_73 ( V_92 -> V_94 ) ,
V_55 -> V_92 ) ;
if ( V_55 -> V_92 == NULL )
{
F_5 ( V_93 ,
V_50 ) ;
goto V_25;
}
}
else
{
F_5 ( V_93 ,
V_95 ) ;
goto V_25;
}
if ( V_92 -> V_96 )
{
const unsigned char * V_97 ;
T_6 V_98 ;
if ( V_55 -> V_99 )
F_74 ( V_55 -> V_99 ) ;
V_55 -> V_99 = F_54 ( V_55 -> V_1 ) ;
if ( V_55 -> V_99 == NULL )
{
F_5 ( V_93 , V_28 ) ;
goto V_25;
}
V_97 = F_72 ( V_92 -> V_96 ) ;
V_98 = F_73 ( V_92 -> V_96 ) ;
V_55 -> V_100 = ( T_9 ) ( V_97 [ 0 ] & ~ 0x01 ) ;
if ( ! F_56 ( V_55 -> V_1 , V_55 -> V_99 ,
V_97 , V_98 , NULL ) )
{
F_5 ( V_93 , V_28 ) ;
goto V_25;
}
}
V_17 = 1 ;
V_25:
if ( ! V_17 )
{
if ( V_55 )
F_75 ( V_55 ) ;
V_55 = NULL ;
}
if ( V_92 )
F_70 ( V_92 ) ;
return ( V_55 ) ;
}
int F_76 ( T_12 * V_47 , unsigned char * * V_88 )
{
int V_55 = 0 , V_17 = 0 ;
unsigned char * V_56 = NULL ;
T_6 V_101 = 0 , V_102 ;
T_13 * V_92 = NULL ;
if ( V_47 == NULL || V_47 -> V_1 == NULL || V_47 -> V_92 == NULL )
{
F_5 ( V_103 ,
V_104 ) ;
goto V_25;
}
if ( ( V_92 = F_68 () ) == NULL )
{
F_5 ( V_103 ,
V_27 ) ;
goto V_25;
}
V_92 -> V_60 = V_47 -> V_60 ;
V_101 = ( T_6 ) F_23 ( V_47 -> V_92 ) ;
V_56 = F_24 ( V_101 ) ;
if ( V_56 == NULL )
{
F_5 ( V_103 ,
V_27 ) ;
goto V_25;
}
if ( ! F_25 ( V_47 -> V_92 , V_56 ) )
{
F_5 ( V_103 , V_50 ) ;
goto V_25;
}
if ( ! F_26 ( V_92 -> V_94 , V_56 , V_101 ) )
{
F_5 ( V_103 , V_30 ) ;
goto V_25;
}
if ( ! ( V_47 -> V_105 & V_106 ) )
{
if ( ( V_92 -> V_70 = F_41 (
V_47 -> V_1 , V_92 -> V_70 ) ) == NULL )
{
F_5 ( V_103 , V_28 ) ;
goto V_25;
}
}
if ( ! ( V_47 -> V_105 & V_107 ) )
{
V_92 -> V_96 = F_77 () ;
if ( V_92 -> V_96 == NULL )
{
F_5 ( V_103 ,
V_27 ) ;
goto V_25;
}
V_102 = F_35 ( V_47 -> V_1 , V_47 -> V_99 ,
V_47 -> V_100 , NULL , 0 , NULL ) ;
if ( V_102 > V_101 )
{
unsigned char * V_108 = F_78 ( V_56 , V_102 ) ;
if ( ! V_108 )
{
F_5 ( V_103 , V_27 ) ;
goto V_25;
}
V_56 = V_108 ;
V_101 = V_102 ;
}
if ( ! F_35 ( V_47 -> V_1 , V_47 -> V_99 ,
V_47 -> V_100 , V_56 , V_101 , NULL ) )
{
F_5 ( V_103 , V_28 ) ;
goto V_25;
}
if ( ! F_79 ( V_92 -> V_96 , V_56 ,
V_101 ) )
{
F_5 ( V_103 , V_30 ) ;
goto V_25;
}
}
if ( ( V_55 = F_80 ( V_92 , V_88 ) ) == 0 )
{
F_5 ( V_103 , V_28 ) ;
goto V_25;
}
V_17 = 1 ;
V_25:
if ( V_56 )
F_30 ( V_56 ) ;
if ( V_92 )
F_70 ( V_92 ) ;
return ( V_17 ? V_55 : 0 ) ;
}
int F_81 ( T_12 * V_47 , unsigned char * * V_88 )
{
if ( V_47 == NULL )
{
F_5 ( V_109 , V_104 ) ;
return 0 ;
}
return F_65 ( V_47 -> V_1 , V_88 ) ;
}
T_12 * F_82 ( T_12 * * V_47 , const unsigned char * * V_84 , long V_54 )
{
T_12 * V_55 ;
if ( V_84 == NULL || * V_84 == NULL )
{
F_5 ( V_110 , V_104 ) ;
return NULL ;
}
if ( V_47 == NULL || * V_47 == NULL )
{
if ( ( V_55 = F_71 () ) == NULL )
{
F_5 ( V_110 , V_27 ) ;
return NULL ;
}
if ( V_47 )
* V_47 = V_55 ;
}
else
V_55 = * V_47 ;
if ( ! F_63 ( & V_55 -> V_1 , V_84 , V_54 ) )
{
F_5 ( V_110 , V_28 ) ;
return NULL ;
}
return V_55 ;
}
T_12 * F_83 ( T_12 * * V_47 , const unsigned char * * V_84 , long V_54 )
{
T_12 * V_55 = NULL ;
if ( V_47 == NULL || ( * V_47 ) == NULL || ( * V_47 ) -> V_1 == NULL )
{
F_5 ( V_111 , V_104 ) ;
return 0 ;
}
V_55 = * V_47 ;
if ( V_55 -> V_99 == NULL &&
( V_55 -> V_99 = F_54 ( V_55 -> V_1 ) ) == NULL )
{
F_5 ( V_111 , V_27 ) ;
return 0 ;
}
if ( ! F_56 ( V_55 -> V_1 , V_55 -> V_99 , * V_84 , V_54 , NULL ) )
{
F_5 ( V_111 , V_28 ) ;
return 0 ;
}
V_55 -> V_100 = ( T_9 ) ( * V_84 [ 0 ] & ~ 0x01 ) ;
* V_84 += V_54 ;
return V_55 ;
}
int F_84 ( T_12 * V_47 , unsigned char * * V_88 )
{
T_6 V_101 = 0 ;
int V_112 = 0 ;
if ( V_47 == NULL )
{
F_5 ( V_113 , V_104 ) ;
return 0 ;
}
V_101 = F_35 ( V_47 -> V_1 , V_47 -> V_99 ,
V_47 -> V_100 , NULL , 0 , NULL ) ;
if ( V_88 == NULL || V_101 == 0 )
return V_101 ;
if ( * V_88 == NULL )
{
if ( ( * V_88 = F_24 ( V_101 ) ) == NULL )
{
F_5 ( V_113 , V_27 ) ;
return 0 ;
}
V_112 = 1 ;
}
if ( ! F_35 ( V_47 -> V_1 , V_47 -> V_99 , V_47 -> V_100 ,
* V_88 , V_101 , NULL ) )
{
F_5 ( V_113 , V_28 ) ;
F_30 ( * V_88 ) ;
* V_88 = NULL ;
return 0 ;
}
if ( ! V_112 )
* V_88 += V_101 ;
return V_101 ;
}
