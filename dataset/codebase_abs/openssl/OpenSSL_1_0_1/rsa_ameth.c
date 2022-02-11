static int F_1 ( T_1 * V_1 , const T_2 * V_2 )
{
unsigned char * V_3 = NULL ;
int V_4 ;
V_4 = F_2 ( V_2 -> V_2 . V_5 , & V_3 ) ;
if ( V_4 <= 0 )
return 0 ;
if ( F_3 ( V_1 , F_4 ( V_6 ) ,
V_7 , NULL , V_3 , V_4 ) )
return 1 ;
F_5 ( V_3 ) ;
return 0 ;
}
static int F_6 ( T_2 * V_2 , T_1 * V_8 )
{
const unsigned char * V_9 ;
int V_10 ;
T_3 * V_5 = NULL ;
if ( ! F_7 ( NULL , & V_9 , & V_10 , NULL , V_8 ) )
return 0 ;
if ( ! ( V_5 = F_8 ( NULL , & V_9 , V_10 ) ) )
{
F_9 ( V_11 , V_12 ) ;
return 0 ;
}
F_10 ( V_2 , V_5 ) ;
return 1 ;
}
static int F_11 ( const T_2 * V_13 , const T_2 * V_14 )
{
if ( F_12 ( V_14 -> V_2 . V_5 -> V_15 , V_13 -> V_2 . V_5 -> V_15 ) != 0
|| F_12 ( V_14 -> V_2 . V_5 -> V_16 , V_13 -> V_2 . V_5 -> V_16 ) != 0 )
return 0 ;
return 1 ;
}
static int F_13 ( T_2 * V_2 ,
const unsigned char * * V_17 , int V_18 )
{
T_3 * V_5 ;
if ( ! ( V_5 = F_14 ( NULL , V_17 , V_18 ) ) )
{
F_9 ( V_19 , V_12 ) ;
return 0 ;
}
F_10 ( V_2 , V_5 ) ;
return 1 ;
}
static int F_15 ( const T_2 * V_2 , unsigned char * * V_17 )
{
return F_16 ( V_2 -> V_2 . V_5 , V_17 ) ;
}
static int F_17 ( T_4 * V_20 , const T_2 * V_2 )
{
unsigned char * V_21 = NULL ;
int V_22 ;
V_22 = F_16 ( V_2 -> V_2 . V_5 , & V_21 ) ;
if ( V_22 <= 0 )
{
F_9 ( V_23 , V_24 ) ;
return 0 ;
}
if ( ! F_18 ( V_20 , F_4 ( V_25 ) , 0 ,
V_7 , NULL , V_21 , V_22 ) )
{
F_9 ( V_23 , V_24 ) ;
return 0 ;
}
return 1 ;
}
static int F_19 ( T_2 * V_2 , T_4 * V_20 )
{
const unsigned char * V_9 ;
int V_10 ;
if ( ! F_20 ( NULL , & V_9 , & V_10 , NULL , V_20 ) )
return 0 ;
return F_13 ( V_2 , & V_9 , V_10 ) ;
}
static int F_21 ( const T_2 * V_2 )
{
return F_22 ( V_2 -> V_2 . V_5 ) ;
}
static int F_23 ( const T_2 * V_2 )
{
return F_24 ( V_2 -> V_2 . V_5 -> V_15 ) ;
}
static void F_25 ( T_2 * V_2 )
{
F_26 ( V_2 -> V_2 . V_5 ) ;
}
static void F_27 ( const T_5 * V_14 , T_6 * V_26 )
{
T_6 V_27 ;
if ( ! V_14 )
return;
if ( * V_26 < ( V_27 = ( T_6 ) F_28 ( V_14 ) ) )
* V_26 = V_27 ;
}
static int F_29 ( T_7 * V_28 , const T_3 * V_29 , int V_30 , int V_31 )
{
char * V_32 ;
const char * V_33 ;
unsigned char * V_34 = NULL ;
int V_35 = 0 , V_36 = 0 ;
T_6 V_37 = 0 ;
F_27 ( V_29 -> V_15 , & V_37 ) ;
F_27 ( V_29 -> V_16 , & V_37 ) ;
if ( V_31 )
{
F_27 ( V_29 -> V_38 , & V_37 ) ;
F_27 ( V_29 -> V_9 , & V_37 ) ;
F_27 ( V_29 -> V_39 , & V_37 ) ;
F_27 ( V_29 -> V_40 , & V_37 ) ;
F_27 ( V_29 -> V_41 , & V_37 ) ;
F_27 ( V_29 -> V_42 , & V_37 ) ;
}
V_34 = ( unsigned char * ) F_30 ( V_37 + 10 ) ;
if ( V_34 == NULL )
{
F_9 ( V_43 , V_24 ) ;
goto V_44;
}
if ( V_29 -> V_15 != NULL )
V_36 = F_24 ( V_29 -> V_15 ) ;
if( ! F_31 ( V_28 , V_30 , 128 ) )
goto V_44;
if ( V_31 && V_29 -> V_38 )
{
if ( F_32 ( V_28 , L_1 , V_36 )
<= 0 ) goto V_44;
V_32 = L_2 ;
V_33 = L_3 ;
}
else
{
if ( F_32 ( V_28 , L_4 , V_36 )
<= 0 ) goto V_44;
V_32 = L_5 ;
V_33 = L_6 ;
}
if ( ! F_33 ( V_28 , V_32 , V_29 -> V_15 , V_34 , V_30 ) ) goto V_44;
if ( ! F_33 ( V_28 , V_33 , V_29 -> V_16 , V_34 , V_30 ) )
goto V_44;
if ( V_31 )
{
if ( ! F_33 ( V_28 , L_7 , V_29 -> V_38 , V_34 , V_30 ) )
goto V_44;
if ( ! F_33 ( V_28 , L_8 , V_29 -> V_9 , V_34 , V_30 ) )
goto V_44;
if ( ! F_33 ( V_28 , L_9 , V_29 -> V_39 , V_34 , V_30 ) )
goto V_44;
if ( ! F_33 ( V_28 , L_10 , V_29 -> V_40 , V_34 , V_30 ) )
goto V_44;
if ( ! F_33 ( V_28 , L_11 , V_29 -> V_41 , V_34 , V_30 ) )
goto V_44;
if ( ! F_33 ( V_28 , L_12 , V_29 -> V_42 , V_34 , V_30 ) )
goto V_44;
}
V_35 = 1 ;
V_44:
if ( V_34 != NULL ) F_5 ( V_34 ) ;
return ( V_35 ) ;
}
static int F_34 ( T_7 * V_28 , const T_2 * V_2 , int V_45 ,
T_8 * V_46 )
{
return F_29 ( V_28 , V_2 -> V_2 . V_5 , V_45 , 0 ) ;
}
static int F_35 ( T_7 * V_28 , const T_2 * V_2 , int V_45 ,
T_8 * V_46 )
{
return F_29 ( V_28 , V_2 -> V_2 . V_5 , V_45 , 1 ) ;
}
static T_9 * F_36 ( const T_10 * V_47 ,
T_10 * * V_48 )
{
const unsigned char * V_9 ;
int V_49 ;
T_9 * V_50 ;
* V_48 = NULL ;
if ( ! V_47 -> V_51 || V_47 -> V_51 -> type != V_52 )
return NULL ;
V_9 = V_47 -> V_51 -> V_53 . V_54 -> V_55 ;
V_49 = V_47 -> V_51 -> V_53 . V_54 -> V_56 ;
V_50 = F_37 ( NULL , & V_9 , V_49 ) ;
if ( ! V_50 )
return NULL ;
if ( V_50 -> V_57 )
{
T_11 * V_58 = V_50 -> V_57 -> V_51 ;
if ( F_38 ( V_50 -> V_57 -> V_59 ) == V_60
&& V_58 -> type == V_52 )
{
V_9 = V_58 -> V_53 . V_54 -> V_55 ;
V_49 = V_58 -> V_53 . V_54 -> V_56 ;
* V_48 = F_39 ( NULL , & V_9 , V_49 ) ;
}
}
return V_50 ;
}
static int F_40 ( T_7 * V_28 , T_9 * V_50 ,
T_10 * V_61 , int V_45 )
{
int V_62 = 0 ;
if ( ! V_50 )
{
if ( F_41 ( V_28 , L_13 ) <= 0 )
return 0 ;
return 1 ;
}
if ( F_41 ( V_28 , L_14 ) <= 0 )
goto V_44;
if ( ! F_31 ( V_28 , V_45 , 128 ) )
goto V_44;
if ( F_41 ( V_28 , L_15 ) <= 0 )
goto V_44;
if ( V_50 -> V_63 )
{
if ( F_42 ( V_28 , V_50 -> V_63 -> V_59 ) <= 0 )
goto V_44;
}
else if ( F_41 ( V_28 , L_16 ) <= 0 )
goto V_44;
if ( F_41 ( V_28 , L_14 ) <= 0 )
goto V_44;
if ( ! F_31 ( V_28 , V_45 , 128 ) )
goto V_44;
if ( F_41 ( V_28 , L_17 ) <= 0 )
goto V_44;
if ( V_50 -> V_57 )
{
if ( F_42 ( V_28 , V_50 -> V_57 -> V_59 ) <= 0 )
goto V_44;
if ( F_41 ( V_28 , L_18 ) <= 0 )
goto V_44;
if ( V_61 )
{
if ( F_42 ( V_28 , V_61 -> V_59 ) <= 0 )
goto V_44;
}
else if ( F_41 ( V_28 , L_19 ) <= 0 )
goto V_44;
}
else if ( F_41 ( V_28 , L_20 ) <= 0 )
goto V_44;
F_41 ( V_28 , L_14 ) ;
if ( ! F_31 ( V_28 , V_45 , 128 ) )
goto V_44;
if ( F_41 ( V_28 , L_21 ) <= 0 )
goto V_44;
if ( V_50 -> V_64 )
{
if ( F_43 ( V_28 , V_50 -> V_64 ) <= 0 )
goto V_44;
}
else if ( F_41 ( V_28 , L_22 ) <= 0 )
goto V_44;
F_41 ( V_28 , L_14 ) ;
if ( ! F_31 ( V_28 , V_45 , 128 ) )
goto V_44;
if ( F_41 ( V_28 , L_23 ) <= 0 )
goto V_44;
if ( V_50 -> V_65 )
{
if ( F_43 ( V_28 , V_50 -> V_65 ) <= 0 )
goto V_44;
}
else if ( F_41 ( V_28 , L_24 ) <= 0 )
goto V_44;
F_41 ( V_28 , L_14 ) ;
V_62 = 1 ;
V_44:
return V_62 ;
}
static int F_44 ( T_7 * V_28 , const T_10 * V_66 ,
const T_12 * V_67 ,
int V_45 , T_8 * V_68 )
{
if ( F_38 ( V_66 -> V_59 ) == V_69 )
{
int V_62 ;
T_9 * V_50 ;
T_10 * V_61 ;
V_50 = F_36 ( V_66 , & V_61 ) ;
V_62 = F_40 ( V_28 , V_50 , V_61 , V_45 ) ;
if ( V_50 )
F_45 ( V_50 ) ;
if ( V_61 )
F_46 ( V_61 ) ;
if ( ! V_62 )
return 0 ;
}
else if ( ! V_67 && F_41 ( V_28 , L_14 ) <= 0 )
return 0 ;
if ( V_67 )
return F_47 ( V_28 , V_67 , V_45 ) ;
return 1 ;
}
static int F_48 ( T_2 * V_2 , int V_70 , long V_71 , void * V_72 )
{
T_10 * V_47 = NULL ;
switch ( V_70 )
{
case V_73 :
if ( V_71 == 0 )
F_49 ( V_72 , NULL , NULL , & V_47 ) ;
break;
case V_74 :
if ( V_71 == 0 )
F_50 ( V_72 , & V_47 ) ;
break;
#ifndef F_51
case V_75 :
if ( V_71 == 0 )
F_52 ( V_72 , NULL , NULL , NULL , & V_47 ) ;
break;
case V_76 :
if ( V_71 == 0 )
F_53 ( V_72 , NULL , NULL , & V_47 ) ;
break;
#endif
case V_77 :
* ( int * ) V_72 = V_78 ;
return 1 ;
default:
return - 2 ;
}
if ( V_47 )
F_54 ( V_47 , F_4 ( V_25 ) ,
V_7 , 0 ) ;
return 1 ;
}
static int F_55 ( T_13 * V_46 , const T_14 * V_79 , void * V_80 ,
T_10 * V_66 , T_15 * V_67 ,
T_2 * V_2 )
{
int V_62 = - 1 ;
int V_81 ;
const T_16 * V_82 = NULL , * V_83 = NULL ;
T_9 * V_50 ;
T_10 * V_61 ;
T_17 * V_84 ;
if ( F_38 ( V_66 -> V_59 ) != V_69 )
{
F_9 ( V_85 , V_86 ) ;
return - 1 ;
}
V_50 = F_36 ( V_66 , & V_61 ) ;
if ( V_50 == NULL )
{
F_9 ( V_85 , V_87 ) ;
goto V_44;
}
if ( V_50 -> V_57 )
{
if ( F_38 ( V_50 -> V_57 -> V_59 ) != V_60 )
{
F_9 ( V_85 , V_88 ) ;
goto V_44;
}
if ( ! V_61 )
{
F_9 ( V_85 , V_89 ) ;
goto V_44;
}
V_82 = F_56 ( V_61 -> V_59 ) ;
if ( V_82 == NULL )
{
F_9 ( V_85 , V_90 ) ;
goto V_44;
}
}
else
V_82 = F_57 () ;
if ( V_50 -> V_63 )
{
V_83 = F_56 ( V_50 -> V_63 -> V_59 ) ;
if ( V_83 == NULL )
{
F_9 ( V_85 , V_91 ) ;
goto V_44;
}
}
else
V_83 = F_57 () ;
if ( V_50 -> V_64 )
{
V_81 = F_58 ( V_50 -> V_64 ) ;
if ( V_81 < 0 )
{
F_9 ( V_85 , V_92 ) ;
goto V_44;
}
}
else
V_81 = 20 ;
if ( V_50 -> V_65 && F_58 ( V_50 -> V_65 ) != 1 )
{
F_9 ( V_85 , V_93 ) ;
goto V_44;
}
if ( ! F_59 ( V_46 , & V_84 , V_83 , NULL , V_2 ) )
goto V_44;
if ( F_60 ( V_84 , V_94 ) <= 0 )
goto V_44;
if ( F_61 ( V_84 , V_81 ) <= 0 )
goto V_44;
if ( F_62 ( V_84 , V_82 ) <= 0 )
goto V_44;
V_62 = 2 ;
V_44:
F_45 ( V_50 ) ;
if ( V_61 )
F_46 ( V_61 ) ;
return V_62 ;
}
static int F_63 ( T_13 * V_46 , const T_14 * V_79 , void * V_80 ,
T_10 * V_95 , T_10 * V_96 ,
T_15 * V_67 )
{
int V_97 ;
T_17 * V_84 = V_46 -> V_68 ;
if ( F_64 ( V_84 , & V_97 ) <= 0 )
return 0 ;
if ( V_97 == V_98 )
return 2 ;
if ( V_97 == V_94 )
{
const T_16 * V_99 , * V_82 ;
T_9 * V_50 = NULL ;
T_10 * V_100 = NULL ;
T_12 * V_101 = NULL , * V_102 = NULL ;
T_2 * V_1 = F_65 ( V_84 ) ;
int V_81 , V_62 = 0 ;
V_99 = F_66 ( V_46 ) ;
if ( F_67 ( V_84 , & V_82 ) <= 0 )
goto V_44;
if ( ! F_68 ( V_84 , & V_81 ) )
goto V_44;
if ( V_81 == - 1 )
V_81 = F_69 ( V_99 ) ;
else if ( V_81 == - 2 )
{
V_81 = F_70 ( V_1 ) - F_69 ( V_99 ) - 2 ;
if ( ( ( F_71 ( V_1 ) - 1 ) & 0x7 ) == 0 )
V_81 -- ;
}
V_50 = F_72 () ;
if ( ! V_50 )
goto V_44;
if ( V_81 != 20 )
{
V_50 -> V_64 = F_73 () ;
if ( ! V_50 -> V_64 )
goto V_44;
if ( ! F_74 ( V_50 -> V_64 , V_81 ) )
goto V_44;
}
if ( F_75 ( V_99 ) != V_78 )
{
V_50 -> V_63 = F_76 () ;
if ( ! V_50 -> V_63 )
goto V_44;
F_77 ( V_50 -> V_63 , V_99 ) ;
}
if ( F_75 ( V_82 ) != V_78 )
{
T_12 * V_103 = NULL ;
V_100 = F_76 () ;
F_77 ( V_100 , V_82 ) ;
if ( ! F_78 ( V_100 , F_79 ( T_10 ) ,
& V_103 ) )
goto V_44;
V_50 -> V_57 = F_76 () ;
if ( ! V_50 -> V_57 )
goto V_44;
F_54 ( V_50 -> V_57 ,
F_4 ( V_60 ) ,
V_52 , V_103 ) ;
}
if ( ! F_78 ( V_50 , F_79 ( T_9 ) , & V_101 ) )
goto V_44;
if ( V_96 )
{
V_102 = F_80 ( V_101 ) ;
if ( ! V_102 )
goto V_44;
F_54 ( V_96 , F_4 ( V_69 ) ,
V_52 , V_102 ) ;
}
F_54 ( V_95 , F_4 ( V_69 ) ,
V_52 , V_101 ) ;
V_101 = V_102 = NULL ;
V_62 = 3 ;
V_44:
if ( V_100 )
F_46 ( V_100 ) ;
if ( V_50 )
F_45 ( V_50 ) ;
if ( V_101 )
F_81 ( V_101 ) ;
return V_62 ;
}
return 2 ;
}
