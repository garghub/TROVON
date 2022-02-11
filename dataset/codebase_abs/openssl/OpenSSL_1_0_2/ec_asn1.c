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
if ( V_14 -> V_18 != NULL )
F_8 ( V_14 -> V_18 ) ;
if ( V_14 -> V_19 . V_20 != NULL )
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
} else
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
if ( ! V_31 -> V_19 . V_33 ) {
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
if ( ! V_31 -> V_19 . V_34 ) {
F_5 ( V_21 , V_25 ) ;
goto V_23;
}
V_31 -> V_19 . V_34 -> V_10 = ( long ) V_10 ;
V_31 -> V_19 . V_34 -> V_11 = ( long ) V_11 ;
V_31 -> V_19 . V_34 -> V_12 = ( long ) V_12 ;
} else {
V_31 -> V_19 . V_35 = F_20 () ;
if ( ! V_31 -> V_19 . V_35 ) {
F_5 ( V_21 , V_25 ) ;
goto V_23;
}
}
}
#endif
V_15 = 1 ;
V_23: if ( V_17 )
F_21 ( V_17 ) ;
return ( V_15 ) ;
}
static int F_22 ( const T_1 * V_1 , T_5 * V_36 )
{
int V_15 = 0 , V_16 ;
T_3 * V_37 = NULL , * V_38 = NULL ;
unsigned char * V_39 = NULL , * V_40 = NULL ,
* V_41 = NULL , * V_42 = NULL ;
T_6 V_43 , V_44 ;
unsigned char V_45 = 0 ;
if ( ! V_1 || ! V_36 || ! V_36 -> V_46 || ! V_36 -> V_47 )
return 0 ;
if ( ( V_37 = F_11 () ) == NULL || ( V_38 = F_11 () ) == NULL ) {
F_5 ( V_48 , V_25 ) ;
goto V_23;
}
V_16 = F_2 ( F_3 ( V_1 ) ) ;
if ( V_16 == V_24 ) {
if ( ! F_12 ( V_1 , NULL , V_37 , V_38 , NULL ) ) {
F_5 ( V_48 , V_26 ) ;
goto V_23;
}
}
#ifndef F_14
else {
if ( ! F_23 ( V_1 , NULL , V_37 , V_38 , NULL ) ) {
F_5 ( V_48 , V_26 ) ;
goto V_23;
}
}
#endif
V_43 = ( T_6 ) F_24 ( V_37 ) ;
V_44 = ( T_6 ) F_24 ( V_38 ) ;
if ( V_43 == 0 ) {
V_41 = & V_45 ;
V_43 = 1 ;
} else {
if ( ( V_39 = F_25 ( V_43 ) ) == NULL ) {
F_5 ( V_48 , V_25 ) ;
goto V_23;
}
if ( ( V_43 = F_26 ( V_37 , V_39 ) ) == 0 ) {
F_5 ( V_48 , V_49 ) ;
goto V_23;
}
V_41 = V_39 ;
}
if ( V_44 == 0 ) {
V_42 = & V_45 ;
V_44 = 1 ;
} else {
if ( ( V_40 = F_25 ( V_44 ) ) == NULL ) {
F_5 ( V_48 , V_25 ) ;
goto V_23;
}
if ( ( V_44 = F_26 ( V_38 , V_40 ) ) == 0 ) {
F_5 ( V_48 , V_49 ) ;
goto V_23;
}
V_42 = V_40 ;
}
if ( ! F_27 ( V_36 -> V_46 , V_41 , V_43 ) ||
! F_27 ( V_36 -> V_47 , V_42 , V_44 ) ) {
F_5 ( V_48 , V_28 ) ;
goto V_23;
}
if ( V_1 -> V_50 ) {
if ( ! V_36 -> V_50 )
if ( ( V_36 -> V_50 = F_28 () ) == NULL ) {
F_5 ( V_48 , V_25 ) ;
goto V_23;
}
V_36 -> V_50 -> V_51 &= ~ ( V_52 | 0x07 ) ;
V_36 -> V_50 -> V_51 |= V_52 ;
if ( ! F_29 ( V_36 -> V_50 , V_1 -> V_50 ,
( int ) V_1 -> V_53 ) ) {
F_5 ( V_48 , V_28 ) ;
goto V_23;
}
} else {
if ( V_36 -> V_50 ) {
F_30 ( V_36 -> V_50 ) ;
V_36 -> V_50 = NULL ;
}
}
V_15 = 1 ;
V_23: if ( V_39 )
F_31 ( V_39 ) ;
if ( V_40 )
F_31 ( V_40 ) ;
if ( V_37 )
F_21 ( V_37 ) ;
if ( V_38 )
F_21 ( V_38 ) ;
return ( V_15 ) ;
}
static T_7 * F_32 ( const T_1 * V_1 ,
T_7 * V_54 )
{
int V_15 = 0 ;
T_6 V_55 = 0 ;
T_7 * V_56 = NULL ;
T_3 * V_17 = NULL ;
unsigned char * V_57 = NULL ;
const T_8 * V_58 = NULL ;
T_9 V_59 ;
if ( ( V_17 = F_11 () ) == NULL ) {
F_5 ( V_60 , V_25 ) ;
goto V_23;
}
if ( V_54 == NULL ) {
if ( ( V_56 = F_33 () ) == NULL ) {
F_5 ( V_60 , V_25 ) ;
goto V_23;
}
} else
V_56 = V_54 ;
V_56 -> V_61 = ( long ) 0x1 ;
if ( ! F_7 ( V_1 , V_56 -> V_62 ) ) {
F_5 ( V_60 , V_26 ) ;
goto V_23;
}
if ( ! F_22 ( V_1 , V_56 -> V_36 ) ) {
F_5 ( V_60 , V_26 ) ;
goto V_23;
}
if ( ( V_58 = F_34 ( V_1 ) ) == NULL ) {
F_5 ( V_60 , V_63 ) ;
goto V_23;
}
V_59 = F_35 ( V_1 ) ;
V_55 = F_36 ( V_1 , V_58 , V_59 , NULL , V_55 , NULL ) ;
if ( V_55 == 0 ) {
F_5 ( V_60 , V_26 ) ;
goto V_23;
}
if ( ( V_57 = F_25 ( V_55 ) ) == NULL ) {
F_5 ( V_60 , V_25 ) ;
goto V_23;
}
if ( ! F_36 ( V_1 , V_58 , V_59 , V_57 , V_55 , NULL ) ) {
F_5 ( V_60 , V_26 ) ;
goto V_23;
}
if ( V_56 -> V_64 == NULL && ( V_56 -> V_64 = F_37 () ) == NULL ) {
F_5 ( V_60 , V_25 ) ;
goto V_23;
}
if ( ! F_38 ( V_56 -> V_64 , V_57 , V_55 ) ) {
F_5 ( V_60 , V_28 ) ;
goto V_23;
}
if ( ! F_39 ( V_1 , V_17 , NULL ) ) {
F_5 ( V_60 , V_26 ) ;
goto V_23;
}
V_56 -> V_65 = F_13 ( V_17 , V_56 -> V_65 ) ;
if ( V_56 -> V_65 == NULL ) {
F_5 ( V_60 , V_28 ) ;
goto V_23;
}
if ( F_40 ( V_1 , V_17 , NULL ) ) {
V_56 -> V_66 = F_13 ( V_17 , V_56 -> V_66 ) ;
if ( V_56 -> V_66 == NULL ) {
F_5 ( V_60 , V_28 ) ;
goto V_23;
}
}
V_15 = 1 ;
V_23: if ( ! V_15 ) {
if ( V_56 && ! V_54 )
F_41 ( V_56 ) ;
V_56 = NULL ;
}
if ( V_17 )
F_21 ( V_17 ) ;
if ( V_57 )
F_31 ( V_57 ) ;
return ( V_56 ) ;
}
T_10 * F_42 ( const T_1 * V_1 ,
T_10 * V_67 )
{
int V_15 = 1 , V_17 ;
T_10 * V_56 = V_67 ;
if ( V_56 == NULL ) {
if ( ( V_56 = F_43 () ) == NULL ) {
F_5 ( V_68 , V_25 ) ;
return NULL ;
}
} else {
if ( V_56 -> type == 0 && V_56 -> V_69 . V_70 )
F_8 ( V_56 -> V_69 . V_70 ) ;
else if ( V_56 -> type == 1 && V_56 -> V_69 . V_71 )
F_41 ( V_56 -> V_69 . V_71 ) ;
}
if ( F_44 ( V_1 ) ) {
V_17 = F_45 ( V_1 ) ;
if ( V_17 ) {
V_56 -> type = 0 ;
if ( ( V_56 -> V_69 . V_70 = F_10 ( V_17 ) ) == NULL )
V_15 = 0 ;
} else
V_15 = 0 ;
} else {
V_56 -> type = 1 ;
if ( ( V_56 -> V_69 . V_71 =
F_32 ( V_1 , NULL ) ) == NULL )
V_15 = 0 ;
}
if ( ! V_15 ) {
F_46 ( V_56 ) ;
return NULL ;
}
return V_56 ;
}
static T_1 * F_47 ( const T_7 * V_67 )
{
int V_15 = 0 , V_17 ;
T_1 * V_56 = NULL ;
T_3 * V_19 = NULL , * V_46 = NULL , * V_47 = NULL ;
T_8 * V_58 = NULL ;
long V_72 ;
if ( ! V_67 -> V_62 || ! V_67 -> V_62 -> V_18 ||
! V_67 -> V_62 -> V_19 . V_73 ) {
F_5 ( V_74 , V_75 ) ;
goto V_23;
}
if ( ! V_67 -> V_36 || ! V_67 -> V_36 -> V_46 ||
! V_67 -> V_36 -> V_46 -> V_76 || ! V_67 -> V_36 -> V_47 ||
! V_67 -> V_36 -> V_47 -> V_76 ) {
F_5 ( V_74 , V_75 ) ;
goto V_23;
}
V_46 = F_48 ( V_67 -> V_36 -> V_46 -> V_76 , V_67 -> V_36 -> V_46 -> V_77 , NULL ) ;
if ( V_46 == NULL ) {
F_5 ( V_74 , V_49 ) ;
goto V_23;
}
V_47 = F_48 ( V_67 -> V_36 -> V_47 -> V_76 , V_67 -> V_36 -> V_47 -> V_77 , NULL ) ;
if ( V_47 == NULL ) {
F_5 ( V_74 , V_49 ) ;
goto V_23;
}
V_17 = F_49 ( V_67 -> V_62 -> V_18 ) ;
if ( V_17 == V_3 )
#ifdef F_14
{
F_5 ( V_74 , V_29 ) ;
goto V_23;
}
#else
{
T_4 * V_31 ;
V_31 = V_67 -> V_62 -> V_19 . V_31 ;
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
V_56 = F_52 ( V_19 , V_46 , V_47 , NULL ) ;
}
#endif
else if ( V_17 == V_24 ) {
if ( ! V_67 -> V_62 -> V_19 . V_27 ) {
F_5 ( V_74 , V_75 ) ;
goto V_23;
}
V_19 = F_53 ( V_67 -> V_62 -> V_19 . V_27 , NULL ) ;
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
V_56 = F_57 ( V_19 , V_46 , V_47 , NULL ) ;
} else {
F_5 ( V_74 , V_86 ) ;
goto V_23;
}
if ( V_56 == NULL ) {
F_5 ( V_74 , V_26 ) ;
goto V_23;
}
if ( V_67 -> V_36 -> V_50 != NULL ) {
if ( V_56 -> V_50 != NULL )
F_31 ( V_56 -> V_50 ) ;
if ( ! ( V_56 -> V_50 = F_25 ( V_67 -> V_36 -> V_50 -> V_77 ) ) ) {
F_5 ( V_74 , V_25 ) ;
goto V_23;
}
memcpy ( V_56 -> V_50 , V_67 -> V_36 -> V_50 -> V_76 ,
V_67 -> V_36 -> V_50 -> V_77 ) ;
V_56 -> V_53 = V_67 -> V_36 -> V_50 -> V_77 ;
}
if ( ! V_67 -> V_65 || ! V_67 -> V_64 || ! V_67 -> V_64 -> V_76 ) {
F_5 ( V_74 , V_75 ) ;
goto V_23;
}
if ( ( V_58 = F_58 ( V_56 ) ) == NULL )
goto V_23;
F_59 ( V_56 , ( T_9 )
( V_67 -> V_64 -> V_76 [ 0 ] & ~ 0x01 ) ) ;
if ( ! F_60 ( V_56 , V_58 , V_67 -> V_64 -> V_76 ,
V_67 -> V_64 -> V_77 , NULL ) ) {
F_5 ( V_74 , V_26 ) ;
goto V_23;
}
if ( ( V_46 = F_53 ( V_67 -> V_65 , V_46 ) ) == NULL ) {
F_5 ( V_74 , V_28 ) ;
goto V_23;
}
if ( F_54 ( V_46 ) || F_55 ( V_46 ) ) {
F_5 ( V_74 , V_87 ) ;
goto V_23;
}
if ( F_56 ( V_46 ) > ( int ) V_72 + 1 ) {
F_5 ( V_74 , V_87 ) ;
goto V_23;
}
if ( V_67 -> V_66 == NULL ) {
if ( V_47 ) {
F_21 ( V_47 ) ;
V_47 = NULL ;
}
} else if ( ( V_47 = F_53 ( V_67 -> V_66 , V_47 ) ) == NULL ) {
F_5 ( V_74 , V_28 ) ;
goto V_23;
}
if ( ! F_61 ( V_56 , V_58 , V_46 , V_47 ) ) {
F_5 ( V_74 , V_26 ) ;
goto V_23;
}
V_15 = 1 ;
V_23: if ( ! V_15 ) {
if ( V_56 )
F_62 ( V_56 ) ;
V_56 = NULL ;
}
if ( V_19 )
F_21 ( V_19 ) ;
if ( V_46 )
F_21 ( V_46 ) ;
if ( V_47 )
F_21 ( V_47 ) ;
if ( V_58 )
F_63 ( V_58 ) ;
return ( V_56 ) ;
}
T_1 * F_64 ( const T_10 * V_67 )
{
T_1 * V_56 = NULL ;
int V_17 = 0 ;
if ( V_67 == NULL ) {
F_5 ( V_88 , V_89 ) ;
return NULL ;
}
if ( V_67 -> type == 0 ) {
V_17 = F_49 ( V_67 -> V_69 . V_70 ) ;
if ( ( V_56 = F_65 ( V_17 ) ) == NULL ) {
F_5 ( V_88 ,
V_90 ) ;
return NULL ;
}
F_66 ( V_56 , V_91 ) ;
} else if ( V_67 -> type == 1 ) {
V_56 = F_47 ( V_67 -> V_69 . V_71 ) ;
if ( ! V_56 ) {
F_5 ( V_88 , V_26 ) ;
return NULL ;
}
F_66 ( V_56 , 0x0 ) ;
} else if ( V_67 -> type == 2 ) {
return NULL ;
} else {
F_5 ( V_88 , V_75 ) ;
return NULL ;
}
return V_56 ;
}
T_1 * F_67 ( T_1 * * V_46 , const unsigned char * * V_92 , long V_55 )
{
T_1 * V_1 = NULL ;
T_10 * V_67 = NULL ;
if ( ( V_67 = F_68 ( NULL , V_92 , V_55 ) ) == NULL ) {
F_5 ( V_93 , V_94 ) ;
F_46 ( V_67 ) ;
return NULL ;
}
if ( ( V_1 = F_64 ( V_67 ) ) == NULL ) {
F_5 ( V_93 , V_95 ) ;
F_46 ( V_67 ) ;
return NULL ;
}
if ( V_46 && * V_46 )
F_62 ( * V_46 ) ;
if ( V_46 )
* V_46 = V_1 ;
F_46 ( V_67 ) ;
return ( V_1 ) ;
}
int F_69 ( const T_1 * V_46 , unsigned char * * V_96 )
{
int V_56 = 0 ;
T_10 * V_17 = F_42 ( V_46 , NULL ) ;
if ( V_17 == NULL ) {
F_5 ( V_97 , V_98 ) ;
return 0 ;
}
if ( ( V_56 = F_70 ( V_17 , V_96 ) ) == 0 ) {
F_5 ( V_97 , V_99 ) ;
F_46 ( V_17 ) ;
return 0 ;
}
F_46 ( V_17 ) ;
return ( V_56 ) ;
}
T_12 * F_71 ( T_12 * * V_46 , const unsigned char * * V_92 , long V_55 )
{
int V_15 = 0 ;
T_12 * V_56 = NULL ;
T_13 * V_100 = NULL ;
if ( ( V_100 = F_72 () ) == NULL ) {
F_5 ( V_101 , V_25 ) ;
return NULL ;
}
if ( ( V_100 = F_73 ( & V_100 , V_92 , V_55 ) ) == NULL ) {
F_5 ( V_101 , V_26 ) ;
F_74 ( V_100 ) ;
return NULL ;
}
if ( V_46 == NULL || * V_46 == NULL ) {
if ( ( V_56 = F_75 () ) == NULL ) {
F_5 ( V_101 , V_25 ) ;
goto V_23;
}
if ( V_46 )
* V_46 = V_56 ;
} else
V_56 = * V_46 ;
if ( V_100 -> V_71 ) {
if ( V_56 -> V_1 )
F_62 ( V_56 -> V_1 ) ;
V_56 -> V_1 = F_64 ( V_100 -> V_71 ) ;
}
if ( V_56 -> V_1 == NULL ) {
F_5 ( V_101 , V_26 ) ;
goto V_23;
}
V_56 -> V_61 = V_100 -> V_61 ;
if ( V_100 -> V_102 ) {
V_56 -> V_100 = F_48 ( F_76 ( V_100 -> V_102 ) ,
F_77 ( V_100 -> V_102 ) ,
V_56 -> V_100 ) ;
if ( V_56 -> V_100 == NULL ) {
F_5 ( V_101 , V_49 ) ;
goto V_23;
}
} else {
F_5 ( V_101 , V_103 ) ;
goto V_23;
}
if ( V_56 -> V_104 )
F_78 ( V_56 -> V_104 ) ;
V_56 -> V_104 = F_58 ( V_56 -> V_1 ) ;
if ( V_56 -> V_104 == NULL ) {
F_5 ( V_101 , V_26 ) ;
goto V_23;
}
if ( V_100 -> V_105 ) {
const unsigned char * V_106 ;
int V_107 ;
V_106 = F_76 ( V_100 -> V_105 ) ;
V_107 = F_77 ( V_100 -> V_105 ) ;
if ( V_107 <= 0 ) {
F_5 ( V_101 , V_108 ) ;
goto V_23;
}
V_56 -> V_109 = ( T_9 ) ( V_106 [ 0 ] & ~ 0x01 ) ;
if ( ! F_60 ( V_56 -> V_1 , V_56 -> V_104 ,
V_106 , ( T_6 ) ( V_107 ) , NULL ) ) {
F_5 ( V_101 , V_26 ) ;
goto V_23;
}
} else {
if ( ! F_79
( V_56 -> V_1 , V_56 -> V_104 , V_56 -> V_100 , NULL , NULL , NULL ) ) {
F_5 ( V_101 , V_26 ) ;
goto V_23;
}
V_56 -> V_110 |= V_111 ;
}
V_15 = 1 ;
V_23:
if ( ! V_15 ) {
if ( V_56 )
F_80 ( V_56 ) ;
V_56 = NULL ;
}
if ( V_100 )
F_74 ( V_100 ) ;
return ( V_56 ) ;
}
int F_81 ( T_12 * V_46 , unsigned char * * V_96 )
{
int V_56 = 0 , V_15 = 0 ;
unsigned char * V_57 = NULL ;
T_6 V_112 = 0 , V_113 ;
T_13 * V_100 = NULL ;
if ( V_46 == NULL || V_46 -> V_1 == NULL || V_46 -> V_100 == NULL ||
( ! ( V_46 -> V_110 & V_111 ) && V_46 -> V_104 == NULL ) ) {
F_5 ( V_114 , V_115 ) ;
goto V_23;
}
if ( ( V_100 = F_72 () ) == NULL ) {
F_5 ( V_114 , V_25 ) ;
goto V_23;
}
V_100 -> V_61 = V_46 -> V_61 ;
V_112 = ( T_6 ) F_24 ( V_46 -> V_100 ) ;
V_57 = F_25 ( V_112 ) ;
if ( V_57 == NULL ) {
F_5 ( V_114 , V_25 ) ;
goto V_23;
}
if ( ! F_26 ( V_46 -> V_100 , V_57 ) ) {
F_5 ( V_114 , V_49 ) ;
goto V_23;
}
if ( ! F_27 ( V_100 -> V_102 , V_57 , V_112 ) ) {
F_5 ( V_114 , V_28 ) ;
goto V_23;
}
if ( ! ( V_46 -> V_110 & V_116 ) ) {
if ( ( V_100 -> V_71 =
F_42 ( V_46 -> V_1 ,
V_100 -> V_71 ) ) == NULL ) {
F_5 ( V_114 , V_26 ) ;
goto V_23;
}
}
if ( ! ( V_46 -> V_110 & V_111 ) ) {
V_100 -> V_105 = F_82 () ;
if ( V_100 -> V_105 == NULL ) {
F_5 ( V_114 , V_25 ) ;
goto V_23;
}
V_113 = F_36 ( V_46 -> V_1 , V_46 -> V_104 ,
V_46 -> V_109 , NULL , 0 , NULL ) ;
if ( V_113 > V_112 ) {
unsigned char * V_117 = F_83 ( V_57 , V_113 ) ;
if ( ! V_117 ) {
F_5 ( V_114 , V_25 ) ;
goto V_23;
}
V_57 = V_117 ;
V_112 = V_113 ;
}
if ( ! F_36 ( V_46 -> V_1 , V_46 -> V_104 ,
V_46 -> V_109 , V_57 , V_112 , NULL ) ) {
F_5 ( V_114 , V_26 ) ;
goto V_23;
}
V_100 -> V_105 -> V_51 &= ~ ( V_52 | 0x07 ) ;
V_100 -> V_105 -> V_51 |= V_52 ;
if ( ! F_84 ( V_100 -> V_105 , V_57 , V_112 ) ) {
F_5 ( V_114 , V_28 ) ;
goto V_23;
}
}
if ( ( V_56 = F_85 ( V_100 , V_96 ) ) == 0 ) {
F_5 ( V_114 , V_26 ) ;
goto V_23;
}
V_15 = 1 ;
V_23:
if ( V_57 )
F_31 ( V_57 ) ;
if ( V_100 )
F_74 ( V_100 ) ;
return ( V_15 ? V_56 : 0 ) ;
}
int F_86 ( T_12 * V_46 , unsigned char * * V_96 )
{
if ( V_46 == NULL ) {
F_5 ( V_118 , V_115 ) ;
return 0 ;
}
return F_69 ( V_46 -> V_1 , V_96 ) ;
}
T_12 * F_87 ( T_12 * * V_46 , const unsigned char * * V_92 , long V_55 )
{
T_12 * V_56 ;
if ( V_92 == NULL || * V_92 == NULL ) {
F_5 ( V_119 , V_115 ) ;
return NULL ;
}
if ( V_46 == NULL || * V_46 == NULL ) {
if ( ( V_56 = F_75 () ) == NULL ) {
F_5 ( V_119 , V_25 ) ;
return NULL ;
}
if ( V_46 )
* V_46 = V_56 ;
} else
V_56 = * V_46 ;
if ( ! F_67 ( & V_56 -> V_1 , V_92 , V_55 ) ) {
F_5 ( V_119 , V_26 ) ;
return NULL ;
}
return V_56 ;
}
T_12 * F_88 ( T_12 * * V_46 , const unsigned char * * V_92 , long V_55 )
{
T_12 * V_56 = NULL ;
if ( V_46 == NULL || ( * V_46 ) == NULL || ( * V_46 ) -> V_1 == NULL ) {
F_5 ( V_120 , V_115 ) ;
return 0 ;
}
V_56 = * V_46 ;
if ( V_56 -> V_104 == NULL &&
( V_56 -> V_104 = F_58 ( V_56 -> V_1 ) ) == NULL ) {
F_5 ( V_120 , V_25 ) ;
return 0 ;
}
if ( ! F_60 ( V_56 -> V_1 , V_56 -> V_104 , * V_92 , V_55 , NULL ) ) {
F_5 ( V_120 , V_26 ) ;
return 0 ;
}
V_56 -> V_109 = ( T_9 ) ( * V_92 [ 0 ] & ~ 0x01 ) ;
* V_92 += V_55 ;
return V_56 ;
}
int F_89 ( T_12 * V_46 , unsigned char * * V_96 )
{
T_6 V_112 = 0 ;
int V_121 = 0 ;
if ( V_46 == NULL ) {
F_5 ( V_122 , V_115 ) ;
return 0 ;
}
V_112 = F_36 ( V_46 -> V_1 , V_46 -> V_104 ,
V_46 -> V_109 , NULL , 0 , NULL ) ;
if ( V_96 == NULL || V_112 == 0 )
return V_112 ;
if ( * V_96 == NULL ) {
if ( ( * V_96 = F_25 ( V_112 ) ) == NULL ) {
F_5 ( V_122 , V_25 ) ;
return 0 ;
}
V_121 = 1 ;
}
if ( ! F_36 ( V_46 -> V_1 , V_46 -> V_104 , V_46 -> V_109 ,
* V_96 , V_112 , NULL ) ) {
F_5 ( V_122 , V_26 ) ;
if ( V_121 ) {
F_31 ( * V_96 ) ;
* V_96 = NULL ;
}
return 0 ;
}
if ( ! V_121 )
* V_96 += V_112 ;
return V_112 ;
}
