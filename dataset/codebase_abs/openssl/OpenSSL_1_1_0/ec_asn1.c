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
if ( F_2 ( F_3 ( V_1 ) ) !=
V_3
|| ! ( ( V_1 -> V_4 [ 0 ] != 0 ) && ( V_1 -> V_4 [ 1 ] != 0 )
&& ( V_1 -> V_4 [ 2 ] == 0 ) ) ) {
F_5 ( V_8 ,
V_9 ) ;
return 0 ;
}
if ( V_7 )
* V_7 = V_1 -> V_4 [ 1 ] ;
return 1 ;
}
int F_6 ( const T_1 * V_1 , unsigned int * V_10 ,
unsigned int * V_11 , unsigned int * V_12 )
{
if ( V_1 == NULL )
return 0 ;
if ( F_2 ( F_3 ( V_1 ) ) !=
V_3
|| ! ( ( V_1 -> V_4 [ 0 ] != 0 ) && ( V_1 -> V_4 [ 1 ] != 0 )
&& ( V_1 -> V_4 [ 2 ] != 0 ) && ( V_1 -> V_4 [ 3 ] != 0 )
&& ( V_1 -> V_4 [ 4 ] == 0 ) ) ) {
F_5 ( V_13 ,
V_9 ) ;
return 0 ;
}
if ( V_10 )
* V_10 = V_1 -> V_4 [ 3 ] ;
if ( V_11 )
* V_11 = V_1 -> V_4 [ 2 ] ;
if ( V_12 )
* V_12 = V_1 -> V_4 [ 1 ] ;
return 1 ;
}
static int F_7 ( const T_1 * V_1 , T_2 * V_14 )
{
int V_15 = 0 , V_16 ;
T_3 * V_17 = NULL ;
if ( V_1 == NULL || V_14 == NULL )
return 0 ;
F_8 ( V_14 -> V_18 ) ;
F_9 ( V_14 -> V_19 . V_20 ) ;
V_16 = F_2 ( F_3 ( V_1 ) ) ;
if ( ( V_14 -> V_18 = F_10 ( V_16 ) ) == NULL ) {
F_5 ( V_21 , V_22 ) ;
goto V_23;
}
if ( V_16 == V_24 ) {
if ( ( V_17 = F_11 () ) == NULL ) {
F_5 ( V_21 , V_25 ) ;
goto V_23;
}
if ( ! F_12 ( V_1 , V_17 , NULL , NULL , NULL ) ) {
F_5 ( V_21 , V_26 ) ;
goto V_23;
}
V_14 -> V_19 . V_27 = F_13 ( V_17 , NULL ) ;
if ( V_14 -> V_19 . V_27 == NULL ) {
F_5 ( V_21 , V_28 ) ;
goto V_23;
}
} else if ( V_16 == V_3 )
#ifdef F_14
{
F_5 ( V_21 , V_29 ) ;
goto V_23;
}
#else
{
int V_30 ;
T_4 * V_31 ;
V_14 -> V_19 . V_31 = F_15 () ;
V_31 = V_14 -> V_19 . V_31 ;
if ( V_31 == NULL ) {
F_5 ( V_21 , V_25 ) ;
goto V_23;
}
V_31 -> V_32 = ( long ) F_16 ( V_1 ) ;
V_30 = F_1 ( V_1 ) ;
if ( V_30 == 0 ) {
F_5 ( V_21 , V_26 ) ;
goto V_23;
}
if ( ( V_31 -> type = F_10 ( V_30 ) ) == NULL ) {
F_5 ( V_21 , V_22 ) ;
goto V_23;
}
if ( V_30 == V_6 ) {
unsigned int V_7 ;
if ( ! F_4 ( V_1 , & V_7 ) )
goto V_23;
V_31 -> V_19 . V_33 = F_17 () ;
if ( V_31 -> V_19 . V_33 == NULL ) {
F_5 ( V_21 , V_25 ) ;
goto V_23;
}
if ( ! F_18 ( V_31 -> V_19 . V_33 , ( long ) V_7 ) ) {
F_5 ( V_21 , V_28 ) ;
goto V_23;
}
} else if ( V_30 == V_5 ) {
unsigned int V_10 , V_11 , V_12 ;
if ( ! F_6 ( V_1 , & V_10 , & V_11 , & V_12 ) )
goto V_23;
V_31 -> V_19 . V_34 = F_19 () ;
if ( V_31 -> V_19 . V_34 == NULL ) {
F_5 ( V_21 , V_25 ) ;
goto V_23;
}
V_31 -> V_19 . V_34 -> V_10 = ( long ) V_10 ;
V_31 -> V_19 . V_34 -> V_11 = ( long ) V_11 ;
V_31 -> V_19 . V_34 -> V_12 = ( long ) V_12 ;
} else {
V_31 -> V_19 . V_35 = F_20 () ;
if ( V_31 -> V_19 . V_35 == NULL ) {
F_5 ( V_21 , V_25 ) ;
goto V_23;
}
}
}
#endif
else {
F_5 ( V_21 , V_36 ) ;
goto V_23;
}
V_15 = 1 ;
V_23:
F_21 ( V_17 ) ;
return ( V_15 ) ;
}
static int F_22 ( const T_1 * V_1 , T_5 * V_37 )
{
int V_15 = 0 , V_16 ;
T_3 * V_38 = NULL , * V_39 = NULL ;
unsigned char * V_40 = NULL , * V_41 = NULL ,
* V_42 = NULL , * V_43 = NULL ;
T_6 V_44 , V_45 ;
unsigned char V_46 = 0 ;
if ( ! V_1 || ! V_37 || ! V_37 -> V_47 || ! V_37 -> V_48 )
return 0 ;
if ( ( V_38 = F_11 () ) == NULL || ( V_39 = F_11 () ) == NULL ) {
F_5 ( V_49 , V_25 ) ;
goto V_23;
}
V_16 = F_2 ( F_3 ( V_1 ) ) ;
if ( V_16 == V_24 ) {
if ( ! F_12 ( V_1 , NULL , V_38 , V_39 , NULL ) ) {
F_5 ( V_49 , V_26 ) ;
goto V_23;
}
}
#ifndef F_14
else {
if ( ! F_23 ( V_1 , NULL , V_38 , V_39 , NULL ) ) {
F_5 ( V_49 , V_26 ) ;
goto V_23;
}
}
#endif
V_44 = ( T_6 ) F_24 ( V_38 ) ;
V_45 = ( T_6 ) F_24 ( V_39 ) ;
if ( V_44 == 0 ) {
V_42 = & V_46 ;
V_44 = 1 ;
} else {
if ( ( V_40 = F_25 ( V_44 ) ) == NULL ) {
F_5 ( V_49 , V_25 ) ;
goto V_23;
}
if ( ( V_44 = F_26 ( V_38 , V_40 ) ) == 0 ) {
F_5 ( V_49 , V_50 ) ;
goto V_23;
}
V_42 = V_40 ;
}
if ( V_45 == 0 ) {
V_43 = & V_46 ;
V_45 = 1 ;
} else {
if ( ( V_41 = F_25 ( V_45 ) ) == NULL ) {
F_5 ( V_49 , V_25 ) ;
goto V_23;
}
if ( ( V_45 = F_26 ( V_39 , V_41 ) ) == 0 ) {
F_5 ( V_49 , V_50 ) ;
goto V_23;
}
V_43 = V_41 ;
}
if ( ! F_27 ( V_37 -> V_47 , V_42 , V_44 ) ||
! F_27 ( V_37 -> V_48 , V_43 , V_45 ) ) {
F_5 ( V_49 , V_28 ) ;
goto V_23;
}
if ( V_1 -> V_51 ) {
if ( ! V_37 -> V_51 )
if ( ( V_37 -> V_51 = F_28 () ) == NULL ) {
F_5 ( V_49 , V_25 ) ;
goto V_23;
}
V_37 -> V_51 -> V_52 &= ~ ( V_53 | 0x07 ) ;
V_37 -> V_51 -> V_52 |= V_53 ;
if ( ! F_29 ( V_37 -> V_51 , V_1 -> V_51 ,
( int ) V_1 -> V_54 ) ) {
F_5 ( V_49 , V_28 ) ;
goto V_23;
}
} else {
F_30 ( V_37 -> V_51 ) ;
V_37 -> V_51 = NULL ;
}
V_15 = 1 ;
V_23:
F_31 ( V_40 ) ;
F_31 ( V_41 ) ;
F_21 ( V_38 ) ;
F_21 ( V_39 ) ;
return ( V_15 ) ;
}
T_7 * F_32 ( const T_1 * V_1 ,
T_7 * V_55 )
{
T_6 V_56 = 0 ;
T_7 * V_57 = NULL ;
const T_3 * V_17 ;
unsigned char * V_58 = NULL ;
const T_8 * V_59 = NULL ;
T_9 V_60 ;
if ( V_55 == NULL ) {
if ( ( V_57 = F_33 () ) == NULL ) {
F_5 ( V_61 , V_25 ) ;
goto V_23;
}
} else
V_57 = V_55 ;
V_57 -> V_62 = ( long ) 0x1 ;
if ( ! F_7 ( V_1 , V_57 -> V_63 ) ) {
F_5 ( V_61 , V_26 ) ;
goto V_23;
}
if ( ! F_22 ( V_1 , V_57 -> V_37 ) ) {
F_5 ( V_61 , V_26 ) ;
goto V_23;
}
if ( ( V_59 = F_34 ( V_1 ) ) == NULL ) {
F_5 ( V_61 , V_64 ) ;
goto V_23;
}
V_60 = F_35 ( V_1 ) ;
V_56 = F_36 ( V_1 , V_59 , V_60 , & V_58 , NULL ) ;
if ( V_56 == 0 ) {
F_5 ( V_61 , V_26 ) ;
goto V_23;
}
if ( V_57 -> V_65 == NULL && ( V_57 -> V_65 = F_37 () ) == NULL ) {
F_31 ( V_58 ) ;
F_5 ( V_61 , V_25 ) ;
goto V_23;
}
F_38 ( V_57 -> V_65 , V_58 , V_56 ) ;
V_17 = F_39 ( V_1 ) ;
if ( V_17 == NULL ) {
F_5 ( V_61 , V_26 ) ;
goto V_23;
}
V_57 -> V_66 = F_13 ( V_17 , V_57 -> V_66 ) ;
if ( V_57 -> V_66 == NULL ) {
F_5 ( V_61 , V_28 ) ;
goto V_23;
}
V_17 = F_40 ( V_1 ) ;
if ( V_17 != NULL ) {
V_57 -> V_67 = F_13 ( V_17 , V_57 -> V_67 ) ;
if ( V_57 -> V_67 == NULL ) {
F_5 ( V_61 , V_28 ) ;
goto V_23;
}
}
return V_57 ;
V_23:
if ( V_55 == NULL )
F_41 ( V_57 ) ;
return NULL ;
}
T_10 * F_42 ( const T_1 * V_1 ,
T_10 * V_55 )
{
int V_15 = 1 , V_17 ;
T_10 * V_57 = V_55 ;
if ( V_57 == NULL ) {
if ( ( V_57 = F_43 () ) == NULL ) {
F_5 ( V_68 , V_25 ) ;
return NULL ;
}
} else {
if ( V_57 -> type == 0 )
F_8 ( V_57 -> V_69 . V_70 ) ;
else if ( V_57 -> type == 1 && V_57 -> V_69 . V_71 )
F_41 ( V_57 -> V_69 . V_71 ) ;
}
if ( F_44 ( V_1 ) ) {
V_17 = F_45 ( V_1 ) ;
if ( V_17 ) {
V_57 -> type = 0 ;
if ( ( V_57 -> V_69 . V_70 = F_10 ( V_17 ) ) == NULL )
V_15 = 0 ;
} else
V_15 = 0 ;
} else {
V_57 -> type = 1 ;
if ( ( V_57 -> V_69 . V_71 =
F_32 ( V_1 , NULL ) ) == NULL )
V_15 = 0 ;
}
if ( ! V_15 ) {
F_46 ( V_57 ) ;
return NULL ;
}
return V_57 ;
}
T_1 * F_47 ( const T_7 * V_55 )
{
int V_15 = 0 , V_17 ;
T_1 * V_57 = NULL ;
T_3 * V_19 = NULL , * V_47 = NULL , * V_48 = NULL ;
T_8 * V_59 = NULL ;
long V_72 ;
if ( ! V_55 -> V_63 || ! V_55 -> V_63 -> V_18 ||
! V_55 -> V_63 -> V_19 . V_73 ) {
F_5 ( V_74 , V_75 ) ;
goto V_23;
}
if ( ! V_55 -> V_37 || ! V_55 -> V_37 -> V_47 ||
! V_55 -> V_37 -> V_47 -> V_76 || ! V_55 -> V_37 -> V_48 ||
! V_55 -> V_37 -> V_48 -> V_76 ) {
F_5 ( V_74 , V_75 ) ;
goto V_23;
}
V_47 = F_48 ( V_55 -> V_37 -> V_47 -> V_76 , V_55 -> V_37 -> V_47 -> V_77 , NULL ) ;
if ( V_47 == NULL ) {
F_5 ( V_74 , V_50 ) ;
goto V_23;
}
V_48 = F_48 ( V_55 -> V_37 -> V_48 -> V_76 , V_55 -> V_37 -> V_48 -> V_77 , NULL ) ;
if ( V_48 == NULL ) {
F_5 ( V_74 , V_50 ) ;
goto V_23;
}
V_17 = F_49 ( V_55 -> V_63 -> V_18 ) ;
if ( V_17 == V_3 )
#ifdef F_14
{
F_5 ( V_74 , V_29 ) ;
goto V_23;
}
#else
{
T_4 * V_31 ;
V_31 = V_55 -> V_63 -> V_19 . V_31 ;
V_72 = V_31 -> V_32 ;
if ( V_72 > V_78 ) {
F_5 ( V_74 , V_79 ) ;
goto V_23;
}
if ( ( V_19 = F_11 () ) == NULL ) {
F_5 ( V_74 , V_25 ) ;
goto V_23;
}
V_17 = F_49 ( V_31 -> type ) ;
if ( V_17 == V_6 ) {
long V_80 ;
if ( ! V_31 -> V_19 . V_33 ) {
F_5 ( V_74 , V_75 ) ;
goto V_23;
}
V_80 = F_50 ( V_31 -> V_19 . V_33 ) ;
if ( ! ( V_31 -> V_32 > V_80 && V_80 > 0 ) ) {
F_5 ( V_74 ,
V_81 ) ;
goto V_23;
}
if ( ! F_51 ( V_19 , ( int ) V_31 -> V_32 ) )
goto V_23;
if ( ! F_51 ( V_19 , ( int ) V_80 ) )
goto V_23;
if ( ! F_51 ( V_19 , 0 ) )
goto V_23;
} else if ( V_17 == V_5 ) {
T_11 * V_82 ;
V_82 = V_31 -> V_19 . V_34 ;
if ( ! V_82 ) {
F_5 ( V_74 , V_75 ) ;
goto V_23;
}
if ( !
( V_31 -> V_32 > V_82 -> V_12 && V_82 -> V_12 > V_82 -> V_11
&& V_82 -> V_11 > V_82 -> V_10 && V_82 -> V_10 > 0 ) ) {
F_5 ( V_74 ,
V_83 ) ;
goto V_23;
}
if ( ! F_51 ( V_19 , ( int ) V_31 -> V_32 ) )
goto V_23;
if ( ! F_51 ( V_19 , ( int ) V_82 -> V_10 ) )
goto V_23;
if ( ! F_51 ( V_19 , ( int ) V_82 -> V_11 ) )
goto V_23;
if ( ! F_51 ( V_19 , ( int ) V_82 -> V_12 ) )
goto V_23;
if ( ! F_51 ( V_19 , 0 ) )
goto V_23;
} else if ( V_17 == V_84 ) {
F_5 ( V_74 , V_85 ) ;
goto V_23;
} else {
F_5 ( V_74 , V_75 ) ;
goto V_23;
}
V_57 = F_52 ( V_19 , V_47 , V_48 , NULL ) ;
}
#endif
else if ( V_17 == V_24 ) {
if ( ! V_55 -> V_63 -> V_19 . V_27 ) {
F_5 ( V_74 , V_75 ) ;
goto V_23;
}
V_19 = F_53 ( V_55 -> V_63 -> V_19 . V_27 , NULL ) ;
if ( V_19 == NULL ) {
F_5 ( V_74 , V_28 ) ;
goto V_23;
}
if ( F_54 ( V_19 ) || F_55 ( V_19 ) ) {
F_5 ( V_74 , V_86 ) ;
goto V_23;
}
V_72 = F_56 ( V_19 ) ;
if ( V_72 > V_78 ) {
F_5 ( V_74 , V_79 ) ;
goto V_23;
}
V_57 = F_57 ( V_19 , V_47 , V_48 , NULL ) ;
} else {
F_5 ( V_74 , V_86 ) ;
goto V_23;
}
if ( V_57 == NULL ) {
F_5 ( V_74 , V_26 ) ;
goto V_23;
}
if ( V_55 -> V_37 -> V_51 != NULL ) {
F_31 ( V_57 -> V_51 ) ;
if ( ( V_57 -> V_51 = F_25 ( V_55 -> V_37 -> V_51 -> V_77 ) ) == NULL ) {
F_5 ( V_74 , V_25 ) ;
goto V_23;
}
memcpy ( V_57 -> V_51 , V_55 -> V_37 -> V_51 -> V_76 ,
V_55 -> V_37 -> V_51 -> V_77 ) ;
V_57 -> V_54 = V_55 -> V_37 -> V_51 -> V_77 ;
}
if ( ! V_55 -> V_66 || ! V_55 -> V_65 || ! V_55 -> V_65 -> V_76 ) {
F_5 ( V_74 , V_75 ) ;
goto V_23;
}
if ( ( V_59 = F_58 ( V_57 ) ) == NULL )
goto V_23;
F_59 ( V_57 , ( T_9 )
( V_55 -> V_65 -> V_76 [ 0 ] & ~ 0x01 ) ) ;
if ( ! F_60 ( V_57 , V_59 , V_55 -> V_65 -> V_76 ,
V_55 -> V_65 -> V_77 , NULL ) ) {
F_5 ( V_74 , V_26 ) ;
goto V_23;
}
if ( ( V_47 = F_53 ( V_55 -> V_66 , V_47 ) ) == NULL ) {
F_5 ( V_74 , V_28 ) ;
goto V_23;
}
if ( F_54 ( V_47 ) || F_55 ( V_47 ) ) {
F_5 ( V_74 , V_87 ) ;
goto V_23;
}
if ( F_56 ( V_47 ) > ( int ) V_72 + 1 ) {
F_5 ( V_74 , V_87 ) ;
goto V_23;
}
if ( V_55 -> V_67 == NULL ) {
F_21 ( V_48 ) ;
V_48 = NULL ;
} else if ( ( V_48 = F_53 ( V_55 -> V_67 , V_48 ) ) == NULL ) {
F_5 ( V_74 , V_28 ) ;
goto V_23;
}
if ( ! F_61 ( V_57 , V_59 , V_47 , V_48 ) ) {
F_5 ( V_74 , V_26 ) ;
goto V_23;
}
V_15 = 1 ;
V_23:
if ( ! V_15 ) {
F_62 ( V_57 ) ;
V_57 = NULL ;
}
F_21 ( V_19 ) ;
F_21 ( V_47 ) ;
F_21 ( V_48 ) ;
F_63 ( V_59 ) ;
return ( V_57 ) ;
}
T_1 * F_64 ( const T_10 * V_55 )
{
T_1 * V_57 = NULL ;
int V_17 = 0 ;
if ( V_55 == NULL ) {
F_5 ( V_88 , V_89 ) ;
return NULL ;
}
if ( V_55 -> type == 0 ) {
V_17 = F_49 ( V_55 -> V_69 . V_70 ) ;
if ( ( V_57 = F_65 ( V_17 ) ) == NULL ) {
F_5 ( V_88 ,
V_90 ) ;
return NULL ;
}
F_66 ( V_57 , V_91 ) ;
} else if ( V_55 -> type == 1 ) {
V_57 = F_47 ( V_55 -> V_69 . V_71 ) ;
if ( ! V_57 ) {
F_5 ( V_88 , V_26 ) ;
return NULL ;
}
F_66 ( V_57 , 0x0 ) ;
} else if ( V_55 -> type == 2 ) {
return NULL ;
} else {
F_5 ( V_88 , V_75 ) ;
return NULL ;
}
return V_57 ;
}
T_1 * F_67 ( T_1 * * V_47 , const unsigned char * * V_92 , long V_56 )
{
T_1 * V_1 = NULL ;
T_10 * V_55 = NULL ;
const unsigned char * V_19 = * V_92 ;
if ( ( V_55 = F_68 ( NULL , & V_19 , V_56 ) ) == NULL ) {
F_5 ( V_93 , V_94 ) ;
F_46 ( V_55 ) ;
return NULL ;
}
if ( ( V_1 = F_64 ( V_55 ) ) == NULL ) {
F_5 ( V_93 , V_95 ) ;
F_46 ( V_55 ) ;
return NULL ;
}
if ( V_47 ) {
F_62 ( * V_47 ) ;
* V_47 = V_1 ;
}
F_46 ( V_55 ) ;
* V_92 = V_19 ;
return ( V_1 ) ;
}
int F_69 ( const T_1 * V_47 , unsigned char * * V_96 )
{
int V_57 = 0 ;
T_10 * V_17 = F_42 ( V_47 , NULL ) ;
if ( V_17 == NULL ) {
F_5 ( V_97 , V_98 ) ;
return 0 ;
}
if ( ( V_57 = F_70 ( V_17 , V_96 ) ) == 0 ) {
F_5 ( V_97 , V_99 ) ;
F_46 ( V_17 ) ;
return 0 ;
}
F_46 ( V_17 ) ;
return ( V_57 ) ;
}
T_12 * F_71 ( T_12 * * V_47 , const unsigned char * * V_92 , long V_56 )
{
T_12 * V_57 = NULL ;
T_13 * V_100 = NULL ;
const unsigned char * V_19 = * V_92 ;
if ( ( V_100 = F_72 ( NULL , & V_19 , V_56 ) ) == NULL ) {
F_5 ( V_101 , V_26 ) ;
return NULL ;
}
if ( V_47 == NULL || * V_47 == NULL ) {
if ( ( V_57 = F_73 () ) == NULL ) {
F_5 ( V_101 , V_25 ) ;
goto V_23;
}
} else
V_57 = * V_47 ;
if ( V_100 -> V_71 ) {
F_62 ( V_57 -> V_1 ) ;
V_57 -> V_1 = F_64 ( V_100 -> V_71 ) ;
}
if ( V_57 -> V_1 == NULL ) {
F_5 ( V_101 , V_26 ) ;
goto V_23;
}
V_57 -> V_62 = V_100 -> V_62 ;
if ( V_100 -> V_102 ) {
T_14 * V_103 = V_100 -> V_102 ;
if ( F_74 ( V_57 , F_75 ( V_103 ) ,
F_76 ( V_103 ) ) == 0 )
goto V_23;
} else {
F_5 ( V_101 , V_104 ) ;
goto V_23;
}
F_77 ( V_57 -> V_105 ) ;
V_57 -> V_105 = F_58 ( V_57 -> V_1 ) ;
if ( V_57 -> V_105 == NULL ) {
F_5 ( V_101 , V_26 ) ;
goto V_23;
}
if ( V_100 -> V_106 ) {
const unsigned char * V_107 ;
int V_108 ;
V_107 = F_75 ( V_100 -> V_106 ) ;
V_108 = F_76 ( V_100 -> V_106 ) ;
if ( ! F_78 ( V_57 , V_107 , V_108 , NULL ) ) {
F_5 ( V_101 , V_26 ) ;
goto V_23;
}
} else {
if ( V_57 -> V_1 -> V_109 -> V_110 == NULL
|| V_57 -> V_1 -> V_109 -> V_110 ( V_57 ) == 0 )
goto V_23;
V_57 -> V_111 |= V_112 ;
}
if ( V_47 )
* V_47 = V_57 ;
F_79 ( V_100 ) ;
* V_92 = V_19 ;
return ( V_57 ) ;
V_23:
if ( V_47 == NULL || * V_47 != V_57 )
F_80 ( V_57 ) ;
F_79 ( V_100 ) ;
return NULL ;
}
int F_81 ( T_12 * V_47 , unsigned char * * V_96 )
{
int V_57 = 0 , V_15 = 0 ;
unsigned char * V_113 = NULL , * V_114 = NULL ;
T_6 V_115 = 0 , V_116 = 0 ;
T_13 * V_100 = NULL ;
if ( V_47 == NULL || V_47 -> V_1 == NULL ||
( ! ( V_47 -> V_111 & V_112 ) && V_47 -> V_105 == NULL ) ) {
F_5 ( V_117 , V_118 ) ;
goto V_23;
}
if ( ( V_100 = F_82 () ) == NULL ) {
F_5 ( V_117 , V_25 ) ;
goto V_23;
}
V_100 -> V_62 = V_47 -> V_62 ;
V_115 = F_83 ( V_47 , & V_113 ) ;
if ( V_115 == 0 ) {
F_5 ( V_117 , V_26 ) ;
goto V_23;
}
F_38 ( V_100 -> V_102 , V_113 , V_115 ) ;
V_113 = NULL ;
if ( ! ( V_47 -> V_111 & V_119 ) ) {
if ( ( V_100 -> V_71 =
F_42 ( V_47 -> V_1 ,
V_100 -> V_71 ) ) == NULL ) {
F_5 ( V_117 , V_26 ) ;
goto V_23;
}
}
if ( ! ( V_47 -> V_111 & V_112 ) ) {
V_100 -> V_106 = F_28 () ;
if ( V_100 -> V_106 == NULL ) {
F_5 ( V_117 , V_25 ) ;
goto V_23;
}
V_116 = F_84 ( V_47 , V_47 -> V_120 , & V_114 , NULL ) ;
if ( V_116 == 0 ) {
F_5 ( V_117 , V_26 ) ;
goto V_23;
}
V_100 -> V_106 -> V_52 &= ~ ( V_53 | 0x07 ) ;
V_100 -> V_106 -> V_52 |= V_53 ;
F_38 ( V_100 -> V_106 , V_114 , V_116 ) ;
V_114 = NULL ;
}
if ( ( V_57 = F_85 ( V_100 , V_96 ) ) == 0 ) {
F_5 ( V_117 , V_26 ) ;
goto V_23;
}
V_15 = 1 ;
V_23:
F_86 ( V_113 , V_115 ) ;
F_31 ( V_114 ) ;
F_79 ( V_100 ) ;
return ( V_15 ? V_57 : 0 ) ;
}
int F_87 ( T_12 * V_47 , unsigned char * * V_96 )
{
if ( V_47 == NULL ) {
F_5 ( V_121 , V_118 ) ;
return 0 ;
}
return F_69 ( V_47 -> V_1 , V_96 ) ;
}
T_12 * F_88 ( T_12 * * V_47 , const unsigned char * * V_92 , long V_56 )
{
T_12 * V_57 ;
if ( V_92 == NULL || * V_92 == NULL ) {
F_5 ( V_122 , V_118 ) ;
return NULL ;
}
if ( V_47 == NULL || * V_47 == NULL ) {
if ( ( V_57 = F_73 () ) == NULL ) {
F_5 ( V_122 , V_25 ) ;
return NULL ;
}
} else
V_57 = * V_47 ;
if ( ! F_67 ( & V_57 -> V_1 , V_92 , V_56 ) ) {
F_5 ( V_122 , V_26 ) ;
if ( V_47 == NULL || * V_47 != V_57 )
F_80 ( V_57 ) ;
return NULL ;
}
if ( V_47 )
* V_47 = V_57 ;
return V_57 ;
}
T_12 * F_89 ( T_12 * * V_47 , const unsigned char * * V_92 , long V_56 )
{
T_12 * V_57 = NULL ;
if ( V_47 == NULL || ( * V_47 ) == NULL || ( * V_47 ) -> V_1 == NULL ) {
F_5 ( V_123 , V_118 ) ;
return 0 ;
}
V_57 = * V_47 ;
if ( ! F_78 ( V_57 , * V_92 , V_56 , NULL ) ) {
F_5 ( V_123 , V_26 ) ;
return 0 ;
}
* V_92 += V_56 ;
return V_57 ;
}
int F_90 ( const T_12 * V_47 , unsigned char * * V_96 )
{
T_6 V_124 = 0 ;
int V_125 = 0 ;
if ( V_47 == NULL ) {
F_5 ( V_126 , V_118 ) ;
return 0 ;
}
V_124 = F_91 ( V_47 -> V_1 , V_47 -> V_105 ,
V_47 -> V_120 , NULL , 0 , NULL ) ;
if ( V_96 == NULL || V_124 == 0 )
return V_124 ;
if ( * V_96 == NULL ) {
if ( ( * V_96 = F_25 ( V_124 ) ) == NULL ) {
F_5 ( V_126 , V_25 ) ;
return 0 ;
}
V_125 = 1 ;
}
if ( ! F_91 ( V_47 -> V_1 , V_47 -> V_105 , V_47 -> V_120 ,
* V_96 , V_124 , NULL ) ) {
F_5 ( V_126 , V_26 ) ;
if ( V_125 ) {
F_31 ( * V_96 ) ;
* V_96 = NULL ;
}
return 0 ;
}
if ( ! V_125 )
* V_96 += V_124 ;
return V_124 ;
}
void F_92 ( const T_15 * V_127 , const T_3 * * V_128 , const T_3 * * V_129 )
{
if ( V_128 != NULL )
* V_128 = V_127 -> V_130 ;
if ( V_129 != NULL )
* V_129 = V_127 -> V_131 ;
}
int F_93 ( T_15 * V_127 , T_3 * V_130 , T_3 * V_131 )
{
if ( V_130 == NULL || V_131 == NULL )
return 0 ;
F_94 ( V_127 -> V_130 ) ;
F_94 ( V_127 -> V_131 ) ;
V_127 -> V_130 = V_130 ;
V_127 -> V_131 = V_131 ;
return 1 ;
}
int F_95 ( const T_12 * V_130 )
{
int V_57 , V_2 ;
T_16 V_132 ;
unsigned char V_133 [ 4 ] ;
const T_1 * V_1 ;
if ( V_130 == NULL )
return 0 ;
V_1 = F_96 ( V_130 ) ;
if ( V_1 == NULL )
return 0 ;
V_2 = F_97 ( V_1 ) ;
if ( V_2 == 0 )
return 0 ;
V_132 . V_77 = ( V_2 + 7 ) / 8 ;
V_132 . V_76 = V_133 ;
V_132 . type = V_134 ;
V_133 [ 0 ] = 0xff ;
V_2 = F_98 ( & V_132 , NULL ) ;
V_2 += V_2 ;
V_57 = F_99 ( 1 , V_2 , V_135 ) ;
return ( V_57 ) ;
}
