static int F_1 ( int * V_1 , void * * V_2 , T_1 * V_3 )
{
const T_2 * V_4 ;
int V_5 ;
if ( V_3 == NULL || ( V_4 = F_2 ( V_3 ) ) == NULL )
{
F_3 ( V_6 , V_7 ) ;
return 0 ;
}
if ( F_4 ( V_4 )
&& ( V_5 = F_5 ( V_4 ) ) )
{
* V_2 = F_6 ( V_5 ) ;
* V_1 = V_8 ;
}
else
{
T_3 * V_9 = NULL ;
V_9 = F_7 () ;
if ( ! V_9 )
return 0 ;
V_9 -> V_10 = F_8 ( V_3 , & V_9 -> V_11 ) ;
if ( V_9 -> V_10 < 0 )
{
F_9 ( V_9 ) ;
F_3 ( V_6 , V_12 ) ;
return 0 ;
}
* V_2 = V_9 ;
* V_1 = V_13 ;
}
return 1 ;
}
static int F_10 ( T_4 * V_14 , const T_5 * V_15 )
{
T_1 * V_3 = V_15 -> V_15 . V_16 ;
void * V_17 = NULL ;
int V_18 ;
unsigned char * V_19 = NULL , * V_20 ;
int V_21 ;
if ( ! F_1 ( & V_18 , & V_17 , V_3 ) )
{
F_3 ( V_22 , V_12 ) ;
return 0 ;
}
V_21 = F_11 ( V_3 , NULL ) ;
if ( V_21 <= 0 )
goto V_23;
V_19 = F_12 ( V_21 ) ;
if ( ! V_19 )
goto V_23;
V_20 = V_19 ;
V_21 = F_11 ( V_3 , & V_20 ) ;
if ( V_21 <= 0 )
goto V_23;
if ( F_13 ( V_14 , F_6 ( V_24 ) ,
V_18 , V_17 , V_19 , V_21 ) )
return 1 ;
V_23:
if ( V_18 == V_8 )
F_14 ( V_17 ) ;
else
F_9 ( V_17 ) ;
if ( V_19 )
F_15 ( V_19 ) ;
return 0 ;
}
static T_1 * F_16 ( int V_18 , void * V_17 )
{
T_1 * V_25 = NULL ;
if ( V_18 == V_13 )
{
T_3 * V_9 = V_17 ;
const unsigned char * V_26 = NULL ;
int V_27 ;
V_26 = V_9 -> V_11 ;
V_27 = V_9 -> V_10 ;
if ( ! ( V_25 = F_17 ( NULL , & V_26 , V_27 ) ) )
{
F_3 ( V_28 , V_29 ) ;
goto V_30;
}
}
else if ( V_18 == V_8 )
{
T_6 * V_31 = V_17 ;
T_2 * V_4 ;
if ( ( V_25 = F_18 () ) == NULL )
{
F_3 ( V_28 , V_32 ) ;
goto V_30;
}
V_4 = F_19 ( F_20 ( V_31 ) ) ;
if ( V_4 == NULL )
goto V_30;
F_21 ( V_4 , V_33 ) ;
if ( F_22 ( V_25 , V_4 ) == 0 )
goto V_30;
F_23 ( V_4 ) ;
}
else
{
F_3 ( V_28 , V_29 ) ;
goto V_30;
}
return V_25 ;
V_30:
if ( V_25 )
F_24 ( V_25 ) ;
return NULL ;
}
static int F_25 ( T_5 * V_15 , T_4 * V_34 )
{
const unsigned char * V_20 = NULL ;
void * V_17 ;
int V_18 , V_35 ;
T_1 * V_25 = NULL ;
T_7 * V_36 ;
if ( ! F_26 ( NULL , & V_20 , & V_35 , & V_36 , V_34 ) )
return 0 ;
F_27 ( NULL , & V_18 , & V_17 , V_36 ) ;
V_25 = F_16 ( V_18 , V_17 ) ;
if ( ! V_25 )
{
F_3 ( V_37 , V_12 ) ;
return 0 ;
}
if ( ! F_28 ( & V_25 , & V_20 , V_35 ) )
{
F_3 ( V_37 , V_29 ) ;
goto V_30;
}
F_29 ( V_15 , V_25 ) ;
return 1 ;
V_30:
if ( V_25 )
F_24 ( V_25 ) ;
return 0 ;
}
static int F_30 ( const T_5 * V_38 , const T_5 * V_39 )
{
int V_40 ;
const T_2 * V_4 = F_2 ( V_39 -> V_15 . V_16 ) ;
const T_8 * V_41 = F_31 ( V_38 -> V_15 . V_16 ) ,
* V_42 = F_31 ( V_39 -> V_15 . V_16 ) ;
V_40 = F_32 ( V_4 , V_41 , V_42 , NULL ) ;
if ( V_40 == 0 )
return 1 ;
if ( V_40 == 1 )
return 0 ;
return - 2 ;
}
static int F_33 ( T_5 * V_15 , T_9 * V_43 )
{
const unsigned char * V_20 = NULL ;
void * V_17 ;
int V_18 , V_35 ;
T_1 * V_25 = NULL ;
T_7 * V_36 ;
if ( ! F_34 ( NULL , & V_20 , & V_35 , & V_36 , V_43 ) )
return 0 ;
F_27 ( NULL , & V_18 , & V_17 , V_36 ) ;
V_25 = F_16 ( V_18 , V_17 ) ;
if ( ! V_25 )
goto V_44;
if ( ! F_35 ( & V_25 , & V_20 , V_35 ) )
{
F_3 ( V_45 , V_29 ) ;
goto V_30;
}
if ( F_31 ( V_25 ) == NULL )
{
const T_10 * V_46 ;
const T_2 * V_4 ;
T_8 * V_47 ;
V_4 = F_2 ( V_25 ) ;
V_47 = F_36 ( V_4 ) ;
if ( V_47 == NULL )
{
F_3 ( V_45 , V_12 ) ;
goto V_44;
}
if ( ! F_37 ( V_47 , F_38 ( V_4 ) ) )
{
F_39 ( V_47 ) ;
F_3 ( V_45 , V_12 ) ;
goto V_44;
}
V_46 = F_40 ( V_25 ) ;
if ( ! F_41 ( V_4 , V_47 , V_46 , NULL , NULL , NULL ) )
{
F_39 ( V_47 ) ;
F_3 ( V_45 , V_12 ) ;
goto V_44;
}
if ( F_42 ( V_25 , V_47 ) == 0 )
{
F_39 ( V_47 ) ;
F_3 ( V_45 , V_12 ) ;
goto V_44;
}
F_39 ( V_47 ) ;
}
F_29 ( V_15 , V_25 ) ;
return 1 ;
V_44:
F_3 ( V_45 , V_12 ) ;
V_30:
if ( V_25 )
F_24 ( V_25 ) ;
return 0 ;
}
static int F_43 ( T_9 * V_43 , const T_5 * V_15 )
{
T_1 * V_3 ;
unsigned char * V_48 , * V_20 ;
int V_49 , V_18 ;
void * V_17 ;
unsigned int V_50 , V_51 ;
V_3 = V_15 -> V_15 . V_16 ;
if ( ! F_1 ( & V_18 , & V_17 , V_3 ) )
{
F_3 ( V_52 , V_29 ) ;
return 0 ;
}
V_51 = F_44 ( V_3 ) ;
V_50 = V_51 | V_53 ;
F_45 ( V_3 , V_50 ) ;
V_49 = F_46 ( V_3 , NULL ) ;
if ( ! V_49 )
{
F_45 ( V_3 , V_51 ) ;
F_3 ( V_52 , V_12 ) ;
return 0 ;
}
V_48 = ( unsigned char * ) F_12 ( V_49 ) ;
if ( ! V_48 )
{
F_45 ( V_3 , V_51 ) ;
F_3 ( V_52 , V_32 ) ;
return 0 ;
}
V_20 = V_48 ;
if ( ! F_46 ( V_3 , & V_20 ) )
{
F_45 ( V_3 , V_51 ) ;
F_15 ( V_48 ) ;
F_3 ( V_52 , V_12 ) ;
}
F_45 ( V_3 , V_51 ) ;
if ( ! F_47 ( V_43 , F_6 ( V_54 ) , 0 ,
V_18 , V_17 , V_48 , V_49 ) )
return 0 ;
return 1 ;
}
static int F_48 ( const T_5 * V_15 )
{
return F_49 ( V_15 -> V_15 . V_16 ) ;
}
static int F_50 ( const T_5 * V_15 )
{
T_10 * V_55 = F_51 () ;
const T_2 * V_4 ;
int V_56 ;
if ( ! V_55 )
{
F_52 () ;
return 0 ;
}
V_4 = F_2 ( V_15 -> V_15 . V_16 ) ;
if ( ! F_53 ( V_4 , V_55 , NULL ) )
{
F_52 () ;
return 0 ;
}
V_56 = F_54 ( V_55 ) ;
F_55 ( V_55 ) ;
return V_56 ;
}
static int F_56 ( const T_5 * V_15 )
{
if ( F_2 ( V_15 -> V_15 . V_16 ) == NULL )
return 1 ;
return 0 ;
}
static int F_57 ( T_5 * V_57 , const T_5 * V_58 )
{
T_2 * V_4 = F_58 ( F_2 ( V_58 -> V_15 . V_16 ) ) ;
if ( V_4 == NULL )
return 0 ;
if ( F_22 ( V_57 -> V_15 . V_16 , V_4 ) == 0 )
return 0 ;
F_23 ( V_4 ) ;
return 1 ;
}
static int F_59 ( const T_5 * V_38 , const T_5 * V_39 )
{
const T_2 * V_59 = F_2 ( V_38 -> V_15 . V_16 ) ,
* V_60 = F_2 ( V_39 -> V_15 . V_16 ) ;
if ( F_60 ( V_59 , V_60 , NULL ) )
return 0 ;
else
return 1 ;
}
static void F_61 ( T_5 * V_15 )
{
F_24 ( V_15 -> V_15 . V_16 ) ;
}
static int F_62 ( T_11 * V_61 , const T_1 * V_62 , int V_63 , int V_64 )
{
unsigned char * V_65 = NULL ;
const char * V_66 ;
T_12 V_67 = 0 , V_68 ;
int V_56 = 0 , V_69 = V_70 ;
T_10 * V_47 = NULL , * V_55 = NULL ;
T_13 * V_71 = NULL ;
const T_2 * V_4 ;
const T_8 * V_72 ;
const T_10 * V_46 ;
if ( V_62 == NULL || ( V_4 = F_2 ( V_62 ) ) == NULL )
{
V_69 = V_73 ;
goto V_23;
}
V_71 = F_63 () ;
if ( V_71 == NULL )
{
V_69 = V_32 ;
goto V_23;
}
if ( V_64 > 0 )
{
V_72 = F_31 ( V_62 ) ;
if ( ( V_47 = F_64 ( V_4 , V_72 ,
F_65 ( V_62 ) , NULL , V_71 ) ) == NULL )
{
V_69 = V_12 ;
goto V_23;
}
if ( V_47 )
V_67 = ( T_12 ) F_66 ( V_47 ) ;
}
if ( V_64 == 2 )
{
V_46 = F_40 ( V_62 ) ;
if ( V_46 && ( V_68 = ( T_12 ) F_66 ( V_46 ) ) > V_67 )
V_67 = V_68 ;
}
else
V_46 = NULL ;
if ( V_64 > 0 )
{
V_67 += 10 ;
if ( ( V_65 = F_12 ( V_67 ) ) == NULL )
{
V_69 = V_32 ;
goto V_23;
}
}
if ( V_64 == 2 )
V_66 = L_1 ;
else if ( V_64 == 1 )
V_66 = L_2 ;
else
V_66 = L_3 ;
if ( ! F_67 ( V_61 , V_63 , 128 ) )
goto V_23;
if ( ( V_55 = F_51 () ) == NULL )
goto V_23;
if ( ! F_53 ( V_4 , V_55 , NULL ) )
goto V_23;
if ( F_68 ( V_61 , L_4 , V_66 ,
F_54 ( V_55 ) ) <= 0 ) goto V_23;
if ( ( V_46 != NULL ) && ! F_69 ( V_61 , L_5 , V_46 ,
V_65 , V_63 ) )
goto V_23;
if ( ( V_47 != NULL ) && ! F_69 ( V_61 , L_6 , V_47 ,
V_65 , V_63 ) )
goto V_23;
if ( ! F_70 ( V_61 , V_4 , V_63 ) )
goto V_23;
V_56 = 1 ;
V_23:
if ( ! V_56 )
F_3 ( V_74 , V_69 ) ;
if ( V_47 )
F_55 ( V_47 ) ;
if ( V_55 )
F_55 ( V_55 ) ;
if ( V_71 )
F_71 ( V_71 ) ;
if ( V_65 != NULL )
F_15 ( V_65 ) ;
return ( V_56 ) ;
}
static int F_72 ( T_5 * V_15 ,
const unsigned char * * V_75 , int V_76 )
{
T_1 * V_25 ;
if ( ! ( V_25 = F_17 ( NULL , V_75 , V_76 ) ) )
{
F_3 ( V_77 , V_12 ) ;
return 0 ;
}
F_29 ( V_15 , V_25 ) ;
return 1 ;
}
static int F_73 ( const T_5 * V_15 , unsigned char * * V_75 )
{
return F_8 ( V_15 -> V_15 . V_16 , V_75 ) ;
}
static int F_74 ( T_11 * V_61 , const T_5 * V_15 , int V_78 ,
T_14 * V_71 )
{
return F_62 ( V_61 , V_15 -> V_15 . V_16 , V_78 , 0 ) ;
}
static int F_75 ( T_11 * V_61 , const T_5 * V_15 , int V_78 ,
T_14 * V_71 )
{
return F_62 ( V_61 , V_15 -> V_15 . V_16 , V_78 , 1 ) ;
}
static int F_76 ( T_11 * V_61 , const T_5 * V_15 , int V_78 ,
T_14 * V_71 )
{
return F_62 ( V_61 , V_15 -> V_15 . V_16 , V_78 , 2 ) ;
}
static int F_77 ( T_5 * V_15 ,
const unsigned char * * V_75 , int V_76 )
{
T_1 * V_16 ;
if ( ! ( V_16 = F_35 ( NULL , V_75 , V_76 ) ) )
{
F_3 ( V_79 , V_29 ) ;
return 0 ;
}
F_29 ( V_15 , V_16 ) ;
return 1 ;
}
static int F_78 ( const T_5 * V_15 , unsigned char * * V_75 )
{
return F_46 ( V_15 -> V_15 . V_16 , V_75 ) ;
}
static int F_79 ( T_5 * V_15 , int V_80 , long V_81 , void * V_82 )
{
switch ( V_80 )
{
case V_83 :
if ( V_81 == 0 )
{
int V_84 , V_85 ;
T_7 * V_86 , * V_87 ;
F_80 ( V_82 , NULL , & V_86 , & V_87 ) ;
if ( V_86 == NULL || V_86 -> V_88 == NULL )
return - 1 ;
V_85 = F_20 ( V_86 -> V_88 ) ;
if ( V_85 == V_89 )
return - 1 ;
if ( ! F_81 ( & V_84 , V_85 , F_82 ( V_15 ) ) )
return - 1 ;
F_83 ( V_87 , F_6 ( V_84 ) , V_90 , 0 ) ;
}
return 1 ;
#ifndef F_84
case V_91 :
if ( V_81 == 0 )
{
int V_84 , V_85 ;
T_7 * V_86 , * V_87 ;
F_85 ( V_82 , NULL , NULL ,
& V_86 , & V_87 ) ;
if ( V_86 == NULL || V_86 -> V_88 == NULL )
return - 1 ;
V_85 = F_20 ( V_86 -> V_88 ) ;
if ( V_85 == V_89 )
return - 1 ;
if ( ! F_81 ( & V_84 , V_85 , F_82 ( V_15 ) ) )
return - 1 ;
F_83 ( V_87 , F_6 ( V_84 ) , V_90 , 0 ) ;
}
return 1 ;
#endif
case V_92 :
* ( int * ) V_82 = V_93 ;
return 2 ;
default:
return - 2 ;
}
}
