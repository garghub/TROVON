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
if ( ! ( V_5 = F_8 ( NULL , & V_9 , V_10 ) ) ) {
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
if ( ! ( V_5 = F_14 ( NULL , V_17 , V_18 ) ) ) {
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
if ( V_31 ) {
F_27 ( V_29 -> V_38 , & V_37 ) ;
F_27 ( V_29 -> V_9 , & V_37 ) ;
F_27 ( V_29 -> V_39 , & V_37 ) ;
F_27 ( V_29 -> V_40 , & V_37 ) ;
F_27 ( V_29 -> V_41 , & V_37 ) ;
F_27 ( V_29 -> V_42 , & V_37 ) ;
}
V_34 = ( unsigned char * ) F_30 ( V_37 + 10 ) ;
if ( V_34 == NULL ) {
F_9 ( V_43 , V_24 ) ;
goto V_44;
}
if ( V_29 -> V_15 != NULL )
V_36 = F_24 ( V_29 -> V_15 ) ;
if ( ! F_31 ( V_28 , V_30 , 128 ) )
goto V_44;
if ( V_31 && V_29 -> V_38 ) {
if ( F_32 ( V_28 , L_1 , V_36 )
<= 0 )
goto V_44;
V_32 = L_2 ;
V_33 = L_3 ;
} else {
if ( F_32 ( V_28 , L_4 , V_36 )
<= 0 )
goto V_44;
V_32 = L_5 ;
V_33 = L_6 ;
}
if ( ! F_33 ( V_28 , V_32 , V_29 -> V_15 , V_34 , V_30 ) )
goto V_44;
if ( ! F_33 ( V_28 , V_33 , V_29 -> V_16 , V_34 , V_30 ) )
goto V_44;
if ( V_31 ) {
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
if ( V_34 != NULL )
F_5 ( V_34 ) ;
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
static T_9 * F_36 ( T_9 * V_47 )
{
const unsigned char * V_9 ;
int V_48 ;
if ( V_47 == NULL )
return NULL ;
if ( F_37 ( V_47 -> V_49 ) != V_50 )
return NULL ;
if ( V_47 -> V_51 -> type != V_52 )
return NULL ;
V_9 = V_47 -> V_51 -> V_53 . V_54 -> V_55 ;
V_48 = V_47 -> V_51 -> V_53 . V_54 -> V_56 ;
return F_38 ( NULL , & V_9 , V_48 ) ;
}
static T_10 * F_39 ( const T_9 * V_47 ,
T_9 * * V_57 )
{
const unsigned char * V_9 ;
int V_48 ;
T_10 * V_58 ;
* V_57 = NULL ;
if ( ! V_47 -> V_51 || V_47 -> V_51 -> type != V_52 )
return NULL ;
V_9 = V_47 -> V_51 -> V_53 . V_54 -> V_55 ;
V_48 = V_47 -> V_51 -> V_53 . V_54 -> V_56 ;
V_58 = F_40 ( NULL , & V_9 , V_48 ) ;
if ( ! V_58 )
return NULL ;
* V_57 = F_36 ( V_58 -> V_59 ) ;
return V_58 ;
}
static int F_41 ( T_7 * V_28 , T_10 * V_58 ,
T_9 * V_60 , int V_45 )
{
int V_61 = 0 ;
if ( ! V_58 ) {
if ( F_42 ( V_28 , L_13 ) <= 0 )
return 0 ;
return 1 ;
}
if ( F_42 ( V_28 , L_14 ) <= 0 )
goto V_44;
if ( ! F_31 ( V_28 , V_45 , 128 ) )
goto V_44;
if ( F_42 ( V_28 , L_15 ) <= 0 )
goto V_44;
if ( V_58 -> V_62 ) {
if ( F_43 ( V_28 , V_58 -> V_62 -> V_49 ) <= 0 )
goto V_44;
} else if ( F_42 ( V_28 , L_16 ) <= 0 )
goto V_44;
if ( F_42 ( V_28 , L_14 ) <= 0 )
goto V_44;
if ( ! F_31 ( V_28 , V_45 , 128 ) )
goto V_44;
if ( F_42 ( V_28 , L_17 ) <= 0 )
goto V_44;
if ( V_58 -> V_59 ) {
if ( F_43 ( V_28 , V_58 -> V_59 -> V_49 ) <= 0 )
goto V_44;
if ( F_42 ( V_28 , L_18 ) <= 0 )
goto V_44;
if ( V_60 ) {
if ( F_43 ( V_28 , V_60 -> V_49 ) <= 0 )
goto V_44;
} else if ( F_42 ( V_28 , L_19 ) <= 0 )
goto V_44;
} else if ( F_42 ( V_28 , L_20 ) <= 0 )
goto V_44;
F_42 ( V_28 , L_14 ) ;
if ( ! F_31 ( V_28 , V_45 , 128 ) )
goto V_44;
if ( F_42 ( V_28 , L_21 ) <= 0 )
goto V_44;
if ( V_58 -> V_63 ) {
if ( F_44 ( V_28 , V_58 -> V_63 ) <= 0 )
goto V_44;
} else if ( F_42 ( V_28 , L_22 ) <= 0 )
goto V_44;
F_42 ( V_28 , L_14 ) ;
if ( ! F_31 ( V_28 , V_45 , 128 ) )
goto V_44;
if ( F_42 ( V_28 , L_23 ) <= 0 )
goto V_44;
if ( V_58 -> V_64 ) {
if ( F_44 ( V_28 , V_58 -> V_64 ) <= 0 )
goto V_44;
} else if ( F_42 ( V_28 , L_24 ) <= 0 )
goto V_44;
F_42 ( V_28 , L_14 ) ;
V_61 = 1 ;
V_44:
return V_61 ;
}
static int F_45 ( T_7 * V_28 , const T_9 * V_65 ,
const T_11 * V_66 , int V_45 , T_8 * V_67 )
{
if ( F_37 ( V_65 -> V_49 ) == V_68 ) {
int V_61 ;
T_10 * V_58 ;
T_9 * V_60 ;
V_58 = F_39 ( V_65 , & V_60 ) ;
V_61 = F_41 ( V_28 , V_58 , V_60 , V_45 ) ;
if ( V_58 )
F_46 ( V_58 ) ;
if ( V_60 )
F_47 ( V_60 ) ;
if ( ! V_61 )
return 0 ;
} else if ( ! V_66 && F_42 ( V_28 , L_14 ) <= 0 )
return 0 ;
if ( V_66 )
return F_48 ( V_28 , V_66 , V_45 ) ;
return 1 ;
}
static int F_49 ( T_2 * V_2 , int V_69 , long V_70 , void * V_71 )
{
T_9 * V_47 = NULL ;
switch ( V_69 ) {
case V_72 :
if ( V_70 == 0 )
F_50 ( V_71 , NULL , NULL , & V_47 ) ;
break;
case V_73 :
if ( V_70 == 0 )
F_51 ( V_71 , & V_47 ) ;
break;
#ifndef F_52
case V_74 :
if ( V_70 == 0 )
return F_53 ( V_71 ) ;
else if ( V_70 == 1 )
return F_54 ( V_71 ) ;
break;
case V_75 :
if ( V_70 == 0 )
return F_55 ( V_71 ) ;
else if ( V_70 == 1 )
return F_56 ( V_71 ) ;
break;
case V_76 :
* ( int * ) V_71 = V_77 ;
return 1 ;
#endif
case V_78 :
* ( int * ) V_71 = V_79 ;
return 1 ;
default:
return - 2 ;
}
if ( V_47 )
F_57 ( V_47 , F_4 ( V_25 ) , V_7 , 0 ) ;
return 1 ;
}
static int F_58 ( T_9 * * V_80 , const T_12 * V_81 )
{
if ( F_59 ( V_81 ) == V_82 )
return 1 ;
* V_80 = F_60 () ;
if ( ! * V_80 )
return 0 ;
F_61 ( * V_80 , V_81 ) ;
return 1 ;
}
static int F_62 ( T_9 * * V_80 , const T_12 * V_83 )
{
T_9 * V_84 = NULL ;
T_11 * V_85 = NULL ;
* V_80 = NULL ;
if ( F_59 ( V_83 ) == V_82 )
return 1 ;
if ( ! F_58 ( & V_84 , V_83 ) )
goto V_44;
if ( ! F_63 ( V_84 , F_64 ( T_9 ) , & V_85 ) )
goto V_44;
* V_80 = F_60 () ;
if ( ! * V_80 )
goto V_44;
F_57 ( * V_80 , F_4 ( V_50 ) , V_52 , V_85 ) ;
V_85 = NULL ;
V_44:
if ( V_85 )
F_65 ( V_85 ) ;
if ( V_84 )
F_47 ( V_84 ) ;
if ( * V_80 )
return 1 ;
return 0 ;
}
static const T_12 * F_66 ( T_9 * V_47 )
{
const T_12 * V_81 ;
if ( ! V_47 )
return F_67 () ;
V_81 = F_68 ( V_47 -> V_49 ) ;
if ( V_81 == NULL )
F_9 ( V_86 , V_87 ) ;
return V_81 ;
}
static const T_12 * F_69 ( T_9 * V_47 , T_9 * V_60 )
{
const T_12 * V_81 ;
if ( ! V_47 )
return F_67 () ;
if ( F_37 ( V_47 -> V_49 ) != V_50 ) {
F_9 ( V_88 , V_89 ) ;
return NULL ;
}
if ( ! V_60 ) {
F_9 ( V_88 , V_90 ) ;
return NULL ;
}
V_81 = F_68 ( V_60 -> V_49 ) ;
if ( V_81 == NULL ) {
F_9 ( V_88 , V_91 ) ;
return NULL ;
}
return V_81 ;
}
static T_11 * F_70 ( T_13 * V_92 )
{
const T_12 * V_93 , * V_83 ;
T_10 * V_58 = NULL ;
T_11 * V_94 = NULL ;
T_2 * V_1 = F_71 ( V_92 ) ;
int V_95 , V_61 = 0 ;
if ( F_72 ( V_92 , & V_93 ) <= 0 )
goto V_44;
if ( F_73 ( V_92 , & V_83 ) <= 0 )
goto V_44;
if ( ! F_74 ( V_92 , & V_95 ) )
goto V_44;
if ( V_95 == - 1 )
V_95 = F_75 ( V_93 ) ;
else if ( V_95 == - 2 ) {
V_95 = F_76 ( V_1 ) - F_75 ( V_93 ) - 2 ;
if ( ( ( F_77 ( V_1 ) - 1 ) & 0x7 ) == 0 )
V_95 -- ;
}
V_58 = F_78 () ;
if ( ! V_58 )
goto V_44;
if ( V_95 != 20 ) {
V_58 -> V_63 = F_79 () ;
if ( ! V_58 -> V_63 )
goto V_44;
if ( ! F_80 ( V_58 -> V_63 , V_95 ) )
goto V_44;
}
if ( ! F_58 ( & V_58 -> V_62 , V_93 ) )
goto V_44;
if ( ! F_62 ( & V_58 -> V_59 , V_83 ) )
goto V_44;
if ( ! F_63 ( V_58 , F_64 ( T_10 ) , & V_94 ) )
goto V_44;
V_61 = 1 ;
V_44:
if ( V_58 )
F_46 ( V_58 ) ;
if ( V_61 )
return V_94 ;
if ( V_94 )
F_65 ( V_94 ) ;
return NULL ;
}
static int F_81 ( T_14 * V_46 , T_13 * V_92 ,
T_9 * V_65 , T_2 * V_2 )
{
int V_61 = - 1 ;
int V_95 ;
const T_12 * V_83 = NULL , * V_81 = NULL ;
T_10 * V_58 ;
T_9 * V_60 ;
if ( F_37 ( V_65 -> V_49 ) != V_68 ) {
F_9 ( V_96 , V_97 ) ;
return - 1 ;
}
V_58 = F_39 ( V_65 , & V_60 ) ;
if ( V_58 == NULL ) {
F_9 ( V_96 , V_98 ) ;
goto V_44;
}
V_83 = F_69 ( V_58 -> V_59 , V_60 ) ;
if ( ! V_83 )
goto V_44;
V_81 = F_66 ( V_58 -> V_62 ) ;
if ( ! V_81 )
goto V_44;
if ( V_58 -> V_63 ) {
V_95 = F_82 ( V_58 -> V_63 ) ;
if ( V_95 < 0 ) {
F_9 ( V_96 , V_99 ) ;
goto V_44;
}
} else
V_95 = 20 ;
if ( V_58 -> V_64 && F_82 ( V_58 -> V_64 ) != 1 ) {
F_9 ( V_96 , V_100 ) ;
goto V_44;
}
if ( V_2 ) {
if ( ! F_83 ( V_46 , & V_92 , V_81 , NULL , V_2 ) )
goto V_44;
} else {
const T_12 * V_101 ;
if ( F_72 ( V_92 , & V_101 ) <= 0 )
goto V_44;
if ( F_59 ( V_81 ) != F_59 ( V_101 ) ) {
F_9 ( V_96 , V_102 ) ;
goto V_44;
}
}
if ( F_84 ( V_92 , V_103 ) <= 0 )
goto V_44;
if ( F_85 ( V_92 , V_95 ) <= 0 )
goto V_44;
if ( F_86 ( V_92 , V_83 ) <= 0 )
goto V_44;
V_61 = 1 ;
V_44:
F_46 ( V_58 ) ;
if ( V_60 )
F_47 ( V_60 ) ;
return V_61 ;
}
static int F_54 ( T_15 * V_104 )
{
int V_105 , V_106 ;
T_9 * V_47 ;
T_13 * V_92 = F_87 ( V_104 ) ;
F_88 ( V_104 , NULL , NULL , NULL , & V_47 ) ;
V_105 = F_37 ( V_47 -> V_49 ) ;
if ( V_105 == V_25 )
return 1 ;
if ( V_105 == V_68 )
return F_81 ( NULL , V_92 , V_47 , NULL ) ;
if ( F_89 ( V_105 , NULL , & V_106 ) ) {
if ( V_106 == V_25 )
return 1 ;
}
return 0 ;
}
static int F_90 ( T_14 * V_46 , const T_16 * V_107 , void * V_108 ,
T_9 * V_65 , T_17 * V_66 ,
T_2 * V_2 )
{
if ( F_37 ( V_65 -> V_49 ) != V_68 ) {
F_9 ( V_109 , V_97 ) ;
return - 1 ;
}
if ( F_81 ( V_46 , NULL , V_65 , V_2 ) )
return 2 ;
return - 1 ;
}
static int F_53 ( T_15 * V_104 )
{
int V_110 = V_111 ;
T_9 * V_47 ;
T_13 * V_92 = F_87 ( V_104 ) ;
T_11 * V_94 = NULL ;
F_88 ( V_104 , NULL , NULL , NULL , & V_47 ) ;
if ( V_92 ) {
if ( F_91 ( V_92 , & V_110 ) <= 0 )
return 0 ;
}
if ( V_110 == V_111 ) {
F_57 ( V_47 , F_4 ( V_25 ) , V_7 , 0 ) ;
return 1 ;
}
if ( V_110 != V_103 )
return 0 ;
V_94 = F_70 ( V_92 ) ;
if ( ! V_94 )
return 0 ;
F_57 ( V_47 , F_4 ( V_68 ) , V_52 , V_94 ) ;
return 1 ;
}
static int F_92 ( T_14 * V_46 , const T_16 * V_107 , void * V_108 ,
T_9 * V_112 , T_9 * V_113 ,
T_17 * V_66 )
{
int V_110 ;
T_13 * V_92 = V_46 -> V_67 ;
if ( F_91 ( V_92 , & V_110 ) <= 0 )
return 0 ;
if ( V_110 == V_111 )
return 2 ;
if ( V_110 == V_103 ) {
T_11 * V_114 = NULL ;
V_114 = F_70 ( V_92 ) ;
if ( ! V_114 )
return 0 ;
if ( V_113 ) {
T_11 * V_115 = F_93 ( V_114 ) ;
if ( ! V_115 ) {
F_65 ( V_114 ) ;
return 0 ;
}
F_57 ( V_113 , F_4 ( V_68 ) ,
V_52 , V_115 ) ;
}
F_57 ( V_112 , F_4 ( V_68 ) ,
V_52 , V_114 ) ;
return 3 ;
}
return 2 ;
}
static T_18 * F_94 ( const T_9 * V_47 ,
T_9 * * V_57 )
{
const unsigned char * V_9 ;
int V_48 ;
T_18 * V_58 ;
* V_57 = NULL ;
if ( ! V_47 -> V_51 || V_47 -> V_51 -> type != V_52 )
return NULL ;
V_9 = V_47 -> V_51 -> V_53 . V_54 -> V_55 ;
V_48 = V_47 -> V_51 -> V_53 . V_54 -> V_56 ;
V_58 = F_95 ( NULL , & V_9 , V_48 ) ;
if ( ! V_58 )
return NULL ;
* V_57 = F_36 ( V_58 -> V_116 ) ;
return V_58 ;
}
static int F_56 ( T_19 * V_117 )
{
T_13 * V_92 ;
T_9 * V_118 ;
int V_105 ;
int V_61 = - 1 ;
unsigned char * V_119 = NULL ;
int V_120 = 0 ;
const T_12 * V_83 = NULL , * V_81 = NULL ;
T_18 * V_121 ;
T_9 * V_60 ;
V_92 = F_96 ( V_117 ) ;
if ( ! V_92 )
return 0 ;
if ( ! F_97 ( V_117 , NULL , NULL , & V_118 ) )
return - 1 ;
V_105 = F_37 ( V_118 -> V_49 ) ;
if ( V_105 == V_25 )
return 1 ;
if ( V_105 != V_122 ) {
F_9 ( V_123 , V_124 ) ;
return - 1 ;
}
V_121 = F_94 ( V_118 , & V_60 ) ;
if ( V_121 == NULL ) {
F_9 ( V_123 , V_125 ) ;
goto V_44;
}
V_83 = F_69 ( V_121 -> V_116 , V_60 ) ;
if ( ! V_83 )
goto V_44;
V_81 = F_66 ( V_121 -> V_126 ) ;
if ( ! V_81 )
goto V_44;
if ( V_121 -> V_127 ) {
T_9 * V_128 = V_121 -> V_127 ;
if ( F_37 ( V_128 -> V_49 ) != V_129 ) {
F_9 ( V_123 , V_130 ) ;
goto V_44;
}
if ( V_128 -> V_51 -> type != V_131 ) {
F_9 ( V_123 , V_132 ) ;
goto V_44;
}
V_119 = V_128 -> V_51 -> V_53 . V_133 -> V_55 ;
V_128 -> V_51 -> V_53 . V_133 -> V_55 = NULL ;
V_120 = V_128 -> V_51 -> V_53 . V_133 -> V_56 ;
}
if ( F_84 ( V_92 , V_134 ) <= 0 )
goto V_44;
if ( F_98 ( V_92 , V_81 ) <= 0 )
goto V_44;
if ( F_86 ( V_92 , V_83 ) <= 0 )
goto V_44;
if ( F_99 ( V_92 , V_119 , V_120 ) <= 0 )
goto V_44;
V_61 = 1 ;
V_44:
F_100 ( V_121 ) ;
if ( V_60 )
F_47 ( V_60 ) ;
return V_61 ;
}
static int F_55 ( T_19 * V_117 )
{
const T_12 * V_81 , * V_83 ;
T_18 * V_121 = NULL ;
T_11 * V_94 = NULL ;
T_9 * V_47 ;
T_13 * V_92 = F_96 ( V_117 ) ;
int V_110 = V_111 , V_61 = 0 , V_120 ;
unsigned char * V_119 ;
F_97 ( V_117 , NULL , NULL , & V_47 ) ;
if ( V_92 ) {
if ( F_91 ( V_92 , & V_110 ) <= 0 )
return 0 ;
}
if ( V_110 == V_111 ) {
F_57 ( V_47 , F_4 ( V_25 ) , V_7 , 0 ) ;
return 1 ;
}
if ( V_110 != V_134 )
return 0 ;
if ( F_101 ( V_92 , & V_81 ) <= 0 )
goto V_44;
if ( F_73 ( V_92 , & V_83 ) <= 0 )
goto V_44;
V_120 = F_102 ( V_92 , & V_119 ) ;
if ( V_120 < 0 )
goto V_44;
V_121 = F_103 () ;
if ( ! V_121 )
goto V_44;
if ( ! F_58 ( & V_121 -> V_126 , V_81 ) )
goto V_44;
if ( ! F_62 ( & V_121 -> V_116 , V_83 ) )
goto V_44;
if ( V_120 > 0 ) {
T_20 * V_135 = F_104 () ;
V_121 -> V_127 = F_60 () ;
if ( ! V_121 -> V_127 )
goto V_44;
if ( ! V_135 )
goto V_44;
if ( ! F_105 ( V_135 , V_119 , V_120 ) ) {
F_106 ( V_135 ) ;
goto V_44;
}
F_57 ( V_121 -> V_127 , F_4 ( V_129 ) ,
V_131 , V_135 ) ;
}
if ( ! F_63 ( V_121 , F_64 ( T_18 ) , & V_94 ) )
goto V_44;
F_57 ( V_47 , F_4 ( V_122 ) , V_52 , V_94 ) ;
V_94 = NULL ;
V_61 = 1 ;
V_44:
if ( V_121 )
F_100 ( V_121 ) ;
if ( V_94 )
F_65 ( V_94 ) ;
return V_61 ;
}
