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
if ( ( V_5 = F_8 ( NULL , & V_9 , V_10 ) ) == NULL ) {
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
if ( ( V_5 = F_14 ( NULL , V_17 , V_18 ) ) == NULL ) {
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
if ( V_22 <= 0 ) {
F_9 ( V_23 , V_24 ) ;
return 0 ;
}
if ( ! F_18 ( V_20 , F_4 ( V_25 ) , 0 ,
V_7 , NULL , V_21 , V_22 ) ) {
F_9 ( V_23 , V_24 ) ;
return 0 ;
}
return 1 ;
}
static int F_19 ( T_2 * V_2 , const T_4 * V_20 )
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
static int F_25 ( const T_2 * V_2 )
{
return F_26 ( V_2 -> V_2 . V_5 ) ;
}
static void F_27 ( T_2 * V_2 )
{
F_28 ( V_2 -> V_2 . V_5 ) ;
}
static int F_29 ( T_5 * V_26 , const T_3 * V_27 , int V_28 , int V_29 )
{
char * V_30 ;
const char * V_31 ;
int V_32 = 0 , V_33 = 0 ;
if ( V_27 -> V_15 != NULL )
V_33 = F_24 ( V_27 -> V_15 ) ;
if ( ! F_30 ( V_26 , V_28 , 128 ) )
goto V_34;
if ( V_29 && V_27 -> V_35 ) {
if ( F_31 ( V_26 , L_1 , V_33 ) <= 0 )
goto V_34;
V_30 = L_2 ;
V_31 = L_3 ;
} else {
if ( F_31 ( V_26 , L_4 , V_33 ) <= 0 )
goto V_34;
V_30 = L_5 ;
V_31 = L_6 ;
}
if ( ! F_32 ( V_26 , V_30 , V_27 -> V_15 , NULL , V_28 ) )
goto V_34;
if ( ! F_32 ( V_26 , V_31 , V_27 -> V_16 , NULL , V_28 ) )
goto V_34;
if ( V_29 ) {
if ( ! F_32 ( V_26 , L_7 , V_27 -> V_35 , NULL , V_28 ) )
goto V_34;
if ( ! F_32 ( V_26 , L_8 , V_27 -> V_9 , NULL , V_28 ) )
goto V_34;
if ( ! F_32 ( V_26 , L_9 , V_27 -> V_36 , NULL , V_28 ) )
goto V_34;
if ( ! F_32 ( V_26 , L_10 , V_27 -> V_37 , NULL , V_28 ) )
goto V_34;
if ( ! F_32 ( V_26 , L_11 , V_27 -> V_38 , NULL , V_28 ) )
goto V_34;
if ( ! F_32 ( V_26 , L_12 , V_27 -> V_39 , NULL , V_28 ) )
goto V_34;
}
V_32 = 1 ;
V_34:
return ( V_32 ) ;
}
static int F_33 ( T_5 * V_26 , const T_2 * V_2 , int V_40 ,
T_6 * V_41 )
{
return F_29 ( V_26 , V_2 -> V_2 . V_5 , V_40 , 0 ) ;
}
static int F_34 ( T_5 * V_26 , const T_2 * V_2 , int V_40 ,
T_6 * V_41 )
{
return F_29 ( V_26 , V_2 -> V_2 . V_5 , V_40 , 1 ) ;
}
static T_7 * F_35 ( T_7 * V_42 )
{
if ( V_42 == NULL )
return NULL ;
if ( F_36 ( V_42 -> V_43 ) != V_44 )
return NULL ;
return F_37 ( F_38 ( T_7 ) ,
V_42 -> V_45 ) ;
}
static T_8 * F_39 ( const T_7 * V_42 ,
T_7 * * V_46 )
{
T_8 * V_47 ;
* V_46 = NULL ;
V_47 = F_37 ( F_38 ( T_8 ) ,
V_42 -> V_45 ) ;
if ( ! V_47 )
return NULL ;
* V_46 = F_35 ( V_47 -> V_48 ) ;
return V_47 ;
}
static int F_40 ( T_5 * V_26 , T_8 * V_47 ,
T_7 * V_49 , int V_40 )
{
int V_50 = 0 ;
if ( ! V_47 ) {
if ( F_41 ( V_26 , L_13 ) <= 0 )
return 0 ;
return 1 ;
}
if ( F_41 ( V_26 , L_14 ) <= 0 )
goto V_34;
if ( ! F_30 ( V_26 , V_40 , 128 ) )
goto V_34;
if ( F_41 ( V_26 , L_15 ) <= 0 )
goto V_34;
if ( V_47 -> V_51 ) {
if ( F_42 ( V_26 , V_47 -> V_51 -> V_43 ) <= 0 )
goto V_34;
} else if ( F_41 ( V_26 , L_16 ) <= 0 )
goto V_34;
if ( F_41 ( V_26 , L_14 ) <= 0 )
goto V_34;
if ( ! F_30 ( V_26 , V_40 , 128 ) )
goto V_34;
if ( F_41 ( V_26 , L_17 ) <= 0 )
goto V_34;
if ( V_47 -> V_48 ) {
if ( F_42 ( V_26 , V_47 -> V_48 -> V_43 ) <= 0 )
goto V_34;
if ( F_41 ( V_26 , L_18 ) <= 0 )
goto V_34;
if ( V_49 ) {
if ( F_42 ( V_26 , V_49 -> V_43 ) <= 0 )
goto V_34;
} else if ( F_41 ( V_26 , L_19 ) <= 0 )
goto V_34;
} else if ( F_41 ( V_26 , L_20 ) <= 0 )
goto V_34;
F_41 ( V_26 , L_14 ) ;
if ( ! F_30 ( V_26 , V_40 , 128 ) )
goto V_34;
if ( F_41 ( V_26 , L_21 ) <= 0 )
goto V_34;
if ( V_47 -> V_52 ) {
if ( F_43 ( V_26 , V_47 -> V_52 ) <= 0 )
goto V_34;
} else if ( F_41 ( V_26 , L_22 ) <= 0 )
goto V_34;
F_41 ( V_26 , L_14 ) ;
if ( ! F_30 ( V_26 , V_40 , 128 ) )
goto V_34;
if ( F_41 ( V_26 , L_23 ) <= 0 )
goto V_34;
if ( V_47 -> V_53 ) {
if ( F_43 ( V_26 , V_47 -> V_53 ) <= 0 )
goto V_34;
} else if ( F_41 ( V_26 , L_24 ) <= 0 )
goto V_34;
F_41 ( V_26 , L_14 ) ;
V_50 = 1 ;
V_34:
return V_50 ;
}
static int F_44 ( T_5 * V_26 , const T_7 * V_54 ,
const T_9 * V_55 , int V_40 , T_6 * V_56 )
{
if ( F_36 ( V_54 -> V_43 ) == V_57 ) {
int V_50 ;
T_8 * V_47 ;
T_7 * V_49 ;
V_47 = F_39 ( V_54 , & V_49 ) ;
V_50 = F_40 ( V_26 , V_47 , V_49 , V_40 ) ;
F_45 ( V_47 ) ;
F_46 ( V_49 ) ;
if ( ! V_50 )
return 0 ;
} else if ( ! V_55 && F_41 ( V_26 , L_14 ) <= 0 )
return 0 ;
if ( V_55 )
return F_47 ( V_26 , V_55 , V_40 ) ;
return 1 ;
}
static int F_48 ( T_2 * V_2 , int V_58 , long V_59 , void * V_60 )
{
T_7 * V_42 = NULL ;
switch ( V_58 ) {
case V_61 :
if ( V_59 == 0 )
F_49 ( V_60 , NULL , NULL , & V_42 ) ;
break;
case V_62 :
if ( V_59 == 0 )
F_50 ( V_60 , & V_42 ) ;
break;
#ifndef F_51
case V_63 :
if ( V_59 == 0 )
return F_52 ( V_60 ) ;
else if ( V_59 == 1 )
return F_53 ( V_60 ) ;
break;
case V_64 :
if ( V_59 == 0 )
return F_54 ( V_60 ) ;
else if ( V_59 == 1 )
return F_55 ( V_60 ) ;
break;
case V_65 :
* ( int * ) V_60 = V_66 ;
return 1 ;
#endif
case V_67 :
* ( int * ) V_60 = V_68 ;
return 1 ;
default:
return - 2 ;
}
if ( V_42 )
F_56 ( V_42 , F_4 ( V_25 ) , V_7 , 0 ) ;
return 1 ;
}
static int F_57 ( T_7 * * V_69 , const T_10 * V_70 )
{
if ( F_58 ( V_70 ) == V_71 )
return 1 ;
* V_69 = F_59 () ;
if ( * V_69 == NULL )
return 0 ;
F_60 ( * V_69 , V_70 ) ;
return 1 ;
}
static int F_61 ( T_7 * * V_69 , const T_10 * V_72 )
{
T_7 * V_73 = NULL ;
T_9 * V_74 = NULL ;
* V_69 = NULL ;
if ( F_58 ( V_72 ) == V_71 )
return 1 ;
if ( ! F_57 ( & V_73 , V_72 ) )
goto V_34;
if ( ! F_62 ( V_73 , F_38 ( T_7 ) , & V_74 ) )
goto V_34;
* V_69 = F_59 () ;
if ( * V_69 == NULL )
goto V_34;
F_56 ( * V_69 , F_4 ( V_44 ) , V_75 , V_74 ) ;
V_74 = NULL ;
V_34:
F_63 ( V_74 ) ;
F_46 ( V_73 ) ;
if ( * V_69 )
return 1 ;
return 0 ;
}
static const T_10 * F_64 ( T_7 * V_42 )
{
const T_10 * V_70 ;
if ( ! V_42 )
return F_65 () ;
V_70 = F_66 ( V_42 -> V_43 ) ;
if ( V_70 == NULL )
F_9 ( V_76 , V_77 ) ;
return V_70 ;
}
static const T_10 * F_67 ( T_7 * V_42 , T_7 * V_49 )
{
const T_10 * V_70 ;
if ( ! V_42 )
return F_65 () ;
if ( F_36 ( V_42 -> V_43 ) != V_44 ) {
F_9 ( V_78 , V_79 ) ;
return NULL ;
}
if ( ! V_49 ) {
F_9 ( V_78 , V_80 ) ;
return NULL ;
}
V_70 = F_66 ( V_49 -> V_43 ) ;
if ( V_70 == NULL ) {
F_9 ( V_78 , V_81 ) ;
return NULL ;
}
return V_70 ;
}
static T_9 * F_68 ( T_11 * V_82 )
{
const T_10 * V_83 , * V_72 ;
T_8 * V_47 = NULL ;
T_9 * V_84 = NULL ;
T_2 * V_1 = F_69 ( V_82 ) ;
int V_85 , V_50 = 0 ;
if ( F_70 ( V_82 , & V_83 ) <= 0 )
goto V_34;
if ( F_71 ( V_82 , & V_72 ) <= 0 )
goto V_34;
if ( ! F_72 ( V_82 , & V_85 ) )
goto V_34;
if ( V_85 == - 1 )
V_85 = F_73 ( V_83 ) ;
else if ( V_85 == - 2 ) {
V_85 = F_74 ( V_1 ) - F_73 ( V_83 ) - 2 ;
if ( ( ( F_75 ( V_1 ) - 1 ) & 0x7 ) == 0 )
V_85 -- ;
}
V_47 = F_76 () ;
if ( V_47 == NULL )
goto V_34;
if ( V_85 != 20 ) {
V_47 -> V_52 = F_77 () ;
if ( V_47 -> V_52 == NULL )
goto V_34;
if ( ! F_78 ( V_47 -> V_52 , V_85 ) )
goto V_34;
}
if ( ! F_57 ( & V_47 -> V_51 , V_83 ) )
goto V_34;
if ( ! F_61 ( & V_47 -> V_48 , V_72 ) )
goto V_34;
if ( ! F_62 ( V_47 , F_38 ( T_8 ) , & V_84 ) )
goto V_34;
V_50 = 1 ;
V_34:
F_45 ( V_47 ) ;
if ( V_50 )
return V_84 ;
F_63 ( V_84 ) ;
return NULL ;
}
static int F_79 ( T_12 * V_41 , T_11 * V_82 ,
T_7 * V_54 , T_2 * V_2 )
{
int V_50 = - 1 ;
int V_85 ;
const T_10 * V_72 = NULL , * V_70 = NULL ;
T_8 * V_47 ;
T_7 * V_49 ;
if ( F_36 ( V_54 -> V_43 ) != V_57 ) {
F_9 ( V_86 , V_87 ) ;
return - 1 ;
}
V_47 = F_39 ( V_54 , & V_49 ) ;
if ( V_47 == NULL ) {
F_9 ( V_86 , V_88 ) ;
goto V_34;
}
V_72 = F_67 ( V_47 -> V_48 , V_49 ) ;
if ( ! V_72 )
goto V_34;
V_70 = F_64 ( V_47 -> V_51 ) ;
if ( ! V_70 )
goto V_34;
if ( V_47 -> V_52 ) {
V_85 = F_80 ( V_47 -> V_52 ) ;
if ( V_85 < 0 ) {
F_9 ( V_86 , V_89 ) ;
goto V_34;
}
} else
V_85 = 20 ;
if ( V_47 -> V_53 && F_80 ( V_47 -> V_53 ) != 1 ) {
F_9 ( V_86 , V_90 ) ;
goto V_34;
}
if ( V_2 ) {
if ( ! F_81 ( V_41 , & V_82 , V_70 , NULL , V_2 ) )
goto V_34;
} else {
const T_10 * V_91 ;
if ( F_70 ( V_82 , & V_91 ) <= 0 )
goto V_34;
if ( F_58 ( V_70 ) != F_58 ( V_91 ) ) {
F_9 ( V_86 , V_92 ) ;
goto V_34;
}
}
if ( F_82 ( V_82 , V_93 ) <= 0 )
goto V_34;
if ( F_83 ( V_82 , V_85 ) <= 0 )
goto V_34;
if ( F_84 ( V_82 , V_72 ) <= 0 )
goto V_34;
V_50 = 1 ;
V_34:
F_45 ( V_47 ) ;
F_46 ( V_49 ) ;
return V_50 ;
}
static int F_53 ( T_13 * V_94 )
{
int V_95 , V_96 ;
T_7 * V_42 ;
T_11 * V_82 = F_85 ( V_94 ) ;
F_86 ( V_94 , NULL , NULL , NULL , & V_42 ) ;
V_95 = F_36 ( V_42 -> V_43 ) ;
if ( V_95 == V_25 )
return 1 ;
if ( V_95 == V_57 )
return F_79 ( NULL , V_82 , V_42 , NULL ) ;
if ( F_87 ( V_95 , NULL , & V_96 ) ) {
if ( V_96 == V_25 )
return 1 ;
}
return 0 ;
}
static int F_88 ( T_12 * V_41 , const T_14 * V_97 , void * V_98 ,
T_7 * V_54 , T_15 * V_55 ,
T_2 * V_2 )
{
if ( F_36 ( V_54 -> V_43 ) != V_57 ) {
F_9 ( V_99 , V_87 ) ;
return - 1 ;
}
if ( F_79 ( V_41 , NULL , V_54 , V_2 ) > 0 ) {
return 2 ;
}
return - 1 ;
}
static int F_52 ( T_13 * V_94 )
{
int V_100 = V_101 ;
T_7 * V_42 ;
T_11 * V_82 = F_85 ( V_94 ) ;
T_9 * V_84 = NULL ;
F_86 ( V_94 , NULL , NULL , NULL , & V_42 ) ;
if ( V_82 ) {
if ( F_89 ( V_82 , & V_100 ) <= 0 )
return 0 ;
}
if ( V_100 == V_101 ) {
F_56 ( V_42 , F_4 ( V_25 ) , V_7 , 0 ) ;
return 1 ;
}
if ( V_100 != V_93 )
return 0 ;
V_84 = F_68 ( V_82 ) ;
if ( ! V_84 )
return 0 ;
F_56 ( V_42 , F_4 ( V_57 ) , V_75 , V_84 ) ;
return 1 ;
}
static int F_90 ( T_12 * V_41 , const T_14 * V_97 , void * V_98 ,
T_7 * V_102 , T_7 * V_103 ,
T_15 * V_55 )
{
int V_100 ;
T_11 * V_82 = F_91 ( V_41 ) ;
if ( F_89 ( V_82 , & V_100 ) <= 0 )
return 0 ;
if ( V_100 == V_101 )
return 2 ;
if ( V_100 == V_93 ) {
T_9 * V_104 = NULL ;
V_104 = F_68 ( V_82 ) ;
if ( ! V_104 )
return 0 ;
if ( V_103 ) {
T_9 * V_105 = F_92 ( V_104 ) ;
if ( ! V_105 ) {
F_63 ( V_104 ) ;
return 0 ;
}
F_56 ( V_103 , F_4 ( V_57 ) ,
V_75 , V_105 ) ;
}
F_56 ( V_102 , F_4 ( V_57 ) ,
V_75 , V_104 ) ;
return 3 ;
}
return 2 ;
}
static T_16 * F_93 ( const T_7 * V_42 ,
T_7 * * V_46 )
{
T_16 * V_47 ;
* V_46 = NULL ;
V_47 = F_37 ( F_38 ( T_16 ) ,
V_42 -> V_45 ) ;
if ( ! V_47 )
return NULL ;
* V_46 = F_35 ( V_47 -> V_106 ) ;
return V_47 ;
}
static int F_55 ( T_17 * V_107 )
{
T_11 * V_82 ;
T_7 * V_108 ;
int V_95 ;
int V_50 = - 1 ;
unsigned char * V_109 = NULL ;
int V_110 = 0 ;
const T_10 * V_72 = NULL , * V_70 = NULL ;
T_16 * V_111 ;
T_7 * V_49 ;
V_82 = F_94 ( V_107 ) ;
if ( ! V_82 )
return 0 ;
if ( ! F_95 ( V_107 , NULL , NULL , & V_108 ) )
return - 1 ;
V_95 = F_36 ( V_108 -> V_43 ) ;
if ( V_95 == V_25 )
return 1 ;
if ( V_95 != V_112 ) {
F_9 ( V_113 , V_114 ) ;
return - 1 ;
}
V_111 = F_93 ( V_108 , & V_49 ) ;
if ( V_111 == NULL ) {
F_9 ( V_113 , V_115 ) ;
goto V_34;
}
V_72 = F_67 ( V_111 -> V_106 , V_49 ) ;
if ( ! V_72 )
goto V_34;
V_70 = F_64 ( V_111 -> V_116 ) ;
if ( ! V_70 )
goto V_34;
if ( V_111 -> V_117 ) {
T_7 * V_118 = V_111 -> V_117 ;
if ( F_36 ( V_118 -> V_43 ) != V_119 ) {
F_9 ( V_113 , V_120 ) ;
goto V_34;
}
if ( V_118 -> V_45 -> type != V_121 ) {
F_9 ( V_113 , V_122 ) ;
goto V_34;
}
V_109 = V_118 -> V_45 -> V_123 . V_124 -> V_125 ;
V_118 -> V_45 -> V_123 . V_124 -> V_125 = NULL ;
V_110 = V_118 -> V_45 -> V_123 . V_124 -> V_126 ;
}
if ( F_82 ( V_82 , V_127 ) <= 0 )
goto V_34;
if ( F_96 ( V_82 , V_70 ) <= 0 )
goto V_34;
if ( F_84 ( V_82 , V_72 ) <= 0 )
goto V_34;
if ( F_97 ( V_82 , V_109 , V_110 ) <= 0 )
goto V_34;
V_50 = 1 ;
V_34:
F_98 ( V_111 ) ;
F_46 ( V_49 ) ;
return V_50 ;
}
static int F_54 ( T_17 * V_107 )
{
const T_10 * V_70 , * V_72 ;
T_16 * V_111 = NULL ;
T_9 * V_84 = NULL ;
T_7 * V_42 ;
T_11 * V_82 = F_94 ( V_107 ) ;
int V_100 = V_101 , V_50 = 0 , V_110 ;
unsigned char * V_109 ;
F_95 ( V_107 , NULL , NULL , & V_42 ) ;
if ( V_82 ) {
if ( F_89 ( V_82 , & V_100 ) <= 0 )
return 0 ;
}
if ( V_100 == V_101 ) {
F_56 ( V_42 , F_4 ( V_25 ) , V_7 , 0 ) ;
return 1 ;
}
if ( V_100 != V_127 )
return 0 ;
if ( F_99 ( V_82 , & V_70 ) <= 0 )
goto V_34;
if ( F_71 ( V_82 , & V_72 ) <= 0 )
goto V_34;
V_110 = F_100 ( V_82 , & V_109 ) ;
if ( V_110 < 0 )
goto V_34;
V_111 = F_101 () ;
if ( V_111 == NULL )
goto V_34;
if ( ! F_57 ( & V_111 -> V_116 , V_70 ) )
goto V_34;
if ( ! F_61 ( & V_111 -> V_106 , V_72 ) )
goto V_34;
if ( V_110 > 0 ) {
T_18 * V_128 ;
V_111 -> V_117 = F_59 () ;
if ( V_111 -> V_117 == NULL )
goto V_34;
V_128 = F_102 () ;
if ( V_128 == NULL )
goto V_34;
if ( ! F_103 ( V_128 , V_109 , V_110 ) ) {
F_104 ( V_128 ) ;
goto V_34;
}
F_56 ( V_111 -> V_117 , F_4 ( V_119 ) ,
V_121 , V_128 ) ;
}
if ( ! F_62 ( V_111 , F_38 ( T_16 ) , & V_84 ) )
goto V_34;
F_56 ( V_42 , F_4 ( V_112 ) , V_75 , V_84 ) ;
V_84 = NULL ;
V_50 = 1 ;
V_34:
F_98 ( V_111 ) ;
F_63 ( V_84 ) ;
return V_50 ;
}
