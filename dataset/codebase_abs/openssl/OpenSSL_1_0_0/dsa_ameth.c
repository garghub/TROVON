static int F_1 ( T_1 * V_1 , T_2 * V_2 )
{
const unsigned char * V_3 , * V_4 ;
int V_5 , V_6 ;
int V_7 ;
void * V_8 ;
T_3 * V_9 ;
T_4 * V_10 ;
T_5 * V_11 = NULL ;
T_6 * V_12 = NULL ;
if ( ! F_2 ( NULL , & V_3 , & V_5 , & V_10 , V_2 ) )
return 0 ;
F_3 ( NULL , & V_7 , & V_8 , V_10 ) ;
if ( V_7 == V_13 )
{
V_9 = V_8 ;
V_4 = V_9 -> V_14 ;
V_6 = V_9 -> V_15 ;
if ( ! ( V_12 = F_4 ( NULL , & V_4 , V_6 ) ) )
{
F_5 ( V_16 , V_17 ) ;
goto V_18;
}
}
else if ( ( V_7 == V_19 ) || ( V_7 == V_20 ) )
{
if ( ! ( V_12 = F_6 () ) )
{
F_5 ( V_16 , V_21 ) ;
goto V_18;
}
}
else
{
F_5 ( V_16 , V_22 ) ;
goto V_18;
}
if ( ! ( V_11 = F_7 ( NULL , & V_3 , V_5 ) ) )
{
F_5 ( V_16 , V_17 ) ;
goto V_18;
}
if ( ! ( V_12 -> V_23 = F_8 ( V_11 , NULL ) ) )
{
F_5 ( V_16 , V_24 ) ;
goto V_18;
}
F_9 ( V_11 ) ;
F_10 ( V_1 , V_12 ) ;
return 1 ;
V_18:
if ( V_11 )
F_9 ( V_11 ) ;
if ( V_12 )
F_11 ( V_12 ) ;
return 0 ;
}
static int F_12 ( T_2 * V_25 , const T_1 * V_1 )
{
T_6 * V_12 ;
void * V_8 = NULL ;
int V_7 ;
unsigned char * V_26 = NULL ;
int V_27 ;
V_12 = V_1 -> V_1 . V_12 ;
if ( V_1 -> V_28 && V_12 -> V_3 && V_12 -> V_29 && V_12 -> V_30 )
{
T_3 * V_31 ;
V_31 = F_13 () ;
V_31 -> V_15 = F_14 ( V_12 , & V_31 -> V_14 ) ;
if ( V_31 -> V_15 <= 0 )
{
F_5 ( V_32 , V_21 ) ;
goto V_18;
}
V_8 = V_31 ;
V_7 = V_13 ;
}
else
V_7 = V_20 ;
V_12 -> V_33 = 0 ;
V_27 = F_15 ( V_12 , & V_26 ) ;
if ( V_27 <= 0 )
{
F_5 ( V_32 , V_21 ) ;
goto V_18;
}
if ( F_16 ( V_25 , F_17 ( V_34 ) ,
V_7 , V_8 , V_26 , V_27 ) )
return 1 ;
V_18:
if ( V_26 )
F_18 ( V_26 ) ;
if ( V_8 )
F_19 ( V_8 ) ;
return 0 ;
}
static int F_20 ( T_1 * V_1 , T_7 * V_35 )
{
const unsigned char * V_3 , * V_4 ;
int V_5 , V_6 ;
int V_7 ;
void * V_8 ;
T_3 * V_9 ;
T_4 * V_10 ;
T_5 * V_36 = NULL ;
T_8 * V_37 = NULL ;
F_21 ( V_38 ) * V_39 = NULL ;
T_6 * V_12 = NULL ;
if ( ! F_22 ( NULL , & V_3 , & V_5 , & V_10 , V_35 ) )
return 0 ;
F_3 ( NULL , & V_7 , & V_8 , V_10 ) ;
if ( * V_3 == ( V_13 | V_40 ) )
{
V_38 * V_41 , * V_42 ;
if( ! ( V_39 = F_23 ( NULL , & V_3 , V_5 ) ) ) ;
goto V_43;
if ( F_24 ( V_39 ) != 2 )
goto V_43;
V_41 = F_25 ( V_39 , 0 ) ;
V_42 = F_25 ( V_39 , 1 ) ;
if ( V_41 -> type == V_13 )
{
V_35 -> V_44 = V_45 ;
V_8 = V_41 -> V_46 . V_47 ;
}
else if ( V_7 == V_13 )
V_35 -> V_44 = V_48 ;
else
goto V_43;
if ( V_42 -> type != V_49 )
goto V_43;
V_36 = V_42 -> V_46 . integer ;
}
else
{
const unsigned char * V_29 = V_3 ;
if ( ! ( V_36 = F_7 ( NULL , & V_3 , V_5 ) ) )
goto V_43;
if ( V_36 -> type == V_50 )
{
V_35 -> V_44 = V_51 ;
F_9 ( V_36 ) ;
if ( ! ( V_36 = F_26 ( NULL , & V_29 , V_5 ) ) )
goto V_43;
}
if ( V_7 != V_13 )
goto V_43;
}
V_9 = V_8 ;
V_4 = V_9 -> V_14 ;
V_6 = V_9 -> V_15 ;
if ( ! ( V_12 = F_4 ( NULL , & V_4 , V_6 ) ) )
goto V_43;
if ( ! ( V_12 -> V_52 = F_8 ( V_36 , NULL ) ) )
{
F_5 ( V_53 , V_54 ) ;
goto V_55;
}
if ( ! ( V_12 -> V_23 = F_27 () ) )
{
F_5 ( V_53 , V_21 ) ;
goto V_55;
}
if ( ! ( V_37 = F_28 () ) )
{
F_5 ( V_53 , V_21 ) ;
goto V_55;
}
if ( ! F_29 ( V_12 -> V_23 , V_12 -> V_30 , V_12 -> V_52 , V_12 -> V_3 , V_37 ) )
{
F_5 ( V_53 , V_54 ) ;
goto V_55;
}
F_10 ( V_1 , V_12 ) ;
F_30 ( V_37 ) ;
if( V_39 )
F_31 ( V_39 , V_56 ) ;
else
F_9 ( V_36 ) ;
return 1 ;
V_43:
F_5 ( V_53 , V_57 ) ;
V_55:
F_30 ( V_37 ) ;
if ( V_36 )
F_9 ( V_36 ) ;
F_31 ( V_39 , V_56 ) ;
F_11 ( V_12 ) ;
return 0 ;
}
static int F_32 ( T_7 * V_35 , const T_1 * V_1 )
{
T_3 * V_58 = NULL ;
T_5 * V_59 = NULL ;
unsigned char * V_60 = NULL ;
int V_61 ;
V_58 = F_13 () ;
if ( ! V_58 )
{
F_5 ( V_62 , V_21 ) ;
goto V_18;
}
V_58 -> V_15 = F_14 ( V_1 -> V_1 . V_12 , & V_58 -> V_14 ) ;
if ( V_58 -> V_15 <= 0 )
{
F_5 ( V_62 , V_21 ) ;
goto V_18;
}
V_58 -> type = V_13 ;
V_59 = F_33 ( V_1 -> V_1 . V_12 -> V_52 , NULL ) ;
if ( ! V_59 )
{
F_5 ( V_62 , V_54 ) ;
goto V_18;
}
V_61 = F_34 ( V_59 , & V_60 ) ;
F_9 ( V_59 ) ;
if ( ! F_35 ( V_35 , F_17 ( V_63 ) , 0 ,
V_13 , V_58 , V_60 , V_61 ) )
goto V_18;
return 1 ;
V_18:
if ( V_60 != NULL )
F_18 ( V_60 ) ;
if ( V_58 != NULL )
F_19 ( V_58 ) ;
if ( V_59 != NULL )
F_9 ( V_59 ) ;
return 0 ;
}
static int F_36 ( const T_1 * V_1 )
{
return ( F_37 ( V_1 -> V_1 . V_12 ) ) ;
}
static int F_38 ( const T_1 * V_1 )
{
return F_39 ( V_1 -> V_1 . V_12 -> V_3 ) ;
}
static int F_40 ( const T_1 * V_1 )
{
T_6 * V_12 ;
V_12 = V_1 -> V_1 . V_12 ;
if ( ( V_12 -> V_3 == NULL ) || ( V_12 -> V_29 == NULL ) || ( V_12 -> V_30 == NULL ) )
return 1 ;
return 0 ;
}
static int F_41 ( T_1 * V_64 , const T_1 * V_65 )
{
T_9 * V_66 ;
if ( ( V_66 = F_42 ( V_65 -> V_1 . V_12 -> V_3 ) ) == NULL )
return 0 ;
if ( V_64 -> V_1 . V_12 -> V_3 != NULL )
F_43 ( V_64 -> V_1 . V_12 -> V_3 ) ;
V_64 -> V_1 . V_12 -> V_3 = V_66 ;
if ( ( V_66 = F_42 ( V_65 -> V_1 . V_12 -> V_29 ) ) == NULL )
return 0 ;
if ( V_64 -> V_1 . V_12 -> V_29 != NULL )
F_43 ( V_64 -> V_1 . V_12 -> V_29 ) ;
V_64 -> V_1 . V_12 -> V_29 = V_66 ;
if ( ( V_66 = F_42 ( V_65 -> V_1 . V_12 -> V_30 ) ) == NULL )
return 0 ;
if ( V_64 -> V_1 . V_12 -> V_30 != NULL )
F_43 ( V_64 -> V_1 . V_12 -> V_30 ) ;
V_64 -> V_1 . V_12 -> V_30 = V_66 ;
return 1 ;
}
static int F_44 ( const T_1 * V_66 , const T_1 * V_67 )
{
if ( F_45 ( V_66 -> V_1 . V_12 -> V_3 , V_67 -> V_1 . V_12 -> V_3 ) ||
F_45 ( V_66 -> V_1 . V_12 -> V_29 , V_67 -> V_1 . V_12 -> V_29 ) ||
F_45 ( V_66 -> V_1 . V_12 -> V_30 , V_67 -> V_1 . V_12 -> V_30 ) )
return 0 ;
else
return 1 ;
}
static int F_46 ( const T_1 * V_66 , const T_1 * V_67 )
{
if ( F_45 ( V_67 -> V_1 . V_12 -> V_23 , V_66 -> V_1 . V_12 -> V_23 ) != 0 )
return 0 ;
else
return 1 ;
}
static void F_47 ( T_1 * V_1 )
{
F_11 ( V_1 -> V_1 . V_12 ) ;
}
static void F_48 ( const T_9 * V_67 , T_10 * V_68 )
{
T_10 V_69 ;
if ( ! V_67 )
return;
if ( * V_68 < ( V_69 = ( T_10 ) F_49 ( V_67 ) ) )
* V_68 = V_69 ;
}
static int F_50 ( T_11 * V_70 , const T_6 * V_71 , int V_72 , int V_7 )
{
unsigned char * V_73 = NULL ;
int V_74 = 0 ;
T_10 V_75 = 0 ;
const char * V_76 = NULL ;
const T_9 * V_52 , * V_23 ;
if ( V_7 == 2 )
V_52 = V_71 -> V_52 ;
else
V_52 = NULL ;
if ( V_7 > 0 )
V_23 = V_71 -> V_23 ;
else
V_23 = NULL ;
if ( V_7 == 2 )
V_76 = L_1 ;
else if ( V_7 == 1 )
V_76 = L_2 ;
else
V_76 = L_3 ;
F_48 ( V_71 -> V_3 , & V_75 ) ;
F_48 ( V_71 -> V_29 , & V_75 ) ;
F_48 ( V_71 -> V_30 , & V_75 ) ;
F_48 ( V_52 , & V_75 ) ;
F_48 ( V_23 , & V_75 ) ;
V_73 = ( unsigned char * ) F_51 ( V_75 + 10 ) ;
if ( V_73 == NULL )
{
F_5 ( V_77 , V_21 ) ;
goto V_18;
}
if ( V_52 )
{
if( ! F_52 ( V_70 , V_72 , 128 ) )
goto V_18;
if ( F_53 ( V_70 , L_4 , V_76 , F_39 ( V_71 -> V_3 ) )
<= 0 ) goto V_18;
}
if ( ! F_54 ( V_70 , L_5 , V_52 , V_73 , V_72 ) )
goto V_18;
if ( ! F_54 ( V_70 , L_6 , V_23 , V_73 , V_72 ) )
goto V_18;
if ( ! F_54 ( V_70 , L_7 , V_71 -> V_3 , V_73 , V_72 ) ) goto V_18;
if ( ! F_54 ( V_70 , L_8 , V_71 -> V_29 , V_73 , V_72 ) ) goto V_18;
if ( ! F_54 ( V_70 , L_9 , V_71 -> V_30 , V_73 , V_72 ) ) goto V_18;
V_74 = 1 ;
V_18:
if ( V_73 != NULL ) F_18 ( V_73 ) ;
return ( V_74 ) ;
}
static int F_55 ( T_1 * V_1 ,
const unsigned char * * V_78 , int V_79 )
{
T_6 * V_12 ;
if ( ! ( V_12 = F_4 ( NULL , V_78 , V_79 ) ) )
{
F_5 ( V_80 , V_81 ) ;
return 0 ;
}
F_10 ( V_1 , V_12 ) ;
return 1 ;
}
static int F_56 ( const T_1 * V_1 , unsigned char * * V_78 )
{
return F_14 ( V_1 -> V_1 . V_12 , V_78 ) ;
}
static int F_57 ( T_11 * V_70 , const T_1 * V_1 , int V_82 ,
T_12 * V_37 )
{
return F_50 ( V_70 , V_1 -> V_1 . V_12 , V_82 , 0 ) ;
}
static int F_58 ( T_11 * V_70 , const T_1 * V_1 , int V_82 ,
T_12 * V_37 )
{
return F_50 ( V_70 , V_1 -> V_1 . V_12 , V_82 , 1 ) ;
}
static int F_59 ( T_11 * V_70 , const T_1 * V_1 , int V_82 ,
T_12 * V_37 )
{
return F_50 ( V_70 , V_1 -> V_1 . V_12 , V_82 , 2 ) ;
}
static int F_60 ( T_1 * V_1 ,
const unsigned char * * V_78 , int V_79 )
{
T_6 * V_12 ;
if ( ! ( V_12 = F_61 ( NULL , V_78 , V_79 ) ) )
{
F_5 ( V_83 , V_81 ) ;
return 0 ;
}
F_10 ( V_1 , V_12 ) ;
return 1 ;
}
static int F_62 ( const T_1 * V_1 , unsigned char * * V_78 )
{
return F_63 ( V_1 -> V_1 . V_12 , V_78 ) ;
}
static int F_64 ( T_1 * V_1 , int V_84 , long V_85 , void * V_86 )
{
switch ( V_84 )
{
case V_87 :
if ( V_85 == 0 )
{
int V_88 , V_89 ;
T_4 * V_90 , * V_91 ;
F_65 ( V_86 , NULL , & V_90 , & V_91 ) ;
if ( V_90 == NULL || V_90 -> V_92 == NULL )
return - 1 ;
V_89 = F_66 ( V_90 -> V_92 ) ;
if ( V_89 == V_93 )
return - 1 ;
if ( ! F_67 ( & V_88 , V_89 , F_68 ( V_1 ) ) )
return - 1 ;
F_69 ( V_91 , F_17 ( V_88 ) , V_20 , 0 ) ;
}
return 1 ;
#ifndef F_70
case V_94 :
if ( V_85 == 0 )
{
int V_88 , V_89 ;
T_4 * V_90 , * V_91 ;
F_71 ( V_86 , NULL , NULL , & V_90 , & V_91 ) ;
if ( V_90 == NULL || V_90 -> V_92 == NULL )
return - 1 ;
V_89 = F_66 ( V_90 -> V_92 ) ;
if ( V_89 == V_93 )
return - 1 ;
if ( ! F_67 ( & V_88 , V_89 , F_68 ( V_1 ) ) )
return - 1 ;
F_69 ( V_91 , F_17 ( V_88 ) , V_20 , 0 ) ;
}
return 1 ;
#endif
case V_95 :
* ( int * ) V_86 = V_96 ;
return 2 ;
default:
return - 2 ;
}
}
