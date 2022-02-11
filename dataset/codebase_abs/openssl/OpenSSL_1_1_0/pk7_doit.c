static int F_1 ( T_1 * V_1 )
{
int V_2 = 1 ;
int V_3 = F_2 ( V_1 -> type ) ;
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
V_2 = 0 ;
break;
default:
V_2 = 1 ;
}
return V_2 ;
}
static T_2 * F_3 ( T_1 * V_1 )
{
if ( F_4 ( V_1 ) )
return V_1 -> V_10 . V_11 ;
if ( F_1 ( V_1 ) && V_1 -> V_10 . V_12
&& ( V_1 -> V_10 . V_12 -> type == V_13 ) )
return V_1 -> V_10 . V_12 -> V_14 . V_15 ;
return NULL ;
}
static int F_5 ( T_3 * * V_16 , T_4 * V_17 )
{
T_3 * V_18 ;
const T_5 * V_19 ;
if ( ( V_18 = F_6 ( F_7 () ) ) == NULL ) {
F_8 ( V_20 , V_21 ) ;
goto V_22;
}
V_19 = F_9 ( V_17 -> V_23 ) ;
if ( V_19 == NULL ) {
F_8 ( V_20 , V_24 ) ;
goto V_22;
}
F_10 ( V_18 , V_19 ) ;
if ( * V_16 == NULL )
* V_16 = V_18 ;
else if ( ! F_11 ( * V_16 , V_18 ) ) {
F_8 ( V_20 , V_21 ) ;
goto V_22;
}
V_18 = NULL ;
return 1 ;
V_22:
F_12 ( V_18 ) ;
return 0 ;
}
static int F_13 ( T_6 * V_25 ,
unsigned char * V_26 , int V_27 )
{
T_7 * V_28 = NULL ;
T_8 * V_29 = NULL ;
unsigned char * V_30 = NULL ;
int V_31 = 0 ;
T_9 V_32 ;
V_29 = F_14 ( V_25 -> V_33 ) ;
if ( ! V_29 )
return 0 ;
V_28 = F_15 ( V_29 , NULL ) ;
if ( ! V_28 )
return 0 ;
if ( F_16 ( V_28 ) <= 0 )
goto V_22;
if ( F_17 ( V_28 , - 1 , V_34 ,
V_35 , 0 , V_25 ) <= 0 ) {
F_8 ( V_36 , V_37 ) ;
goto V_22;
}
if ( F_18 ( V_28 , NULL , & V_32 , V_26 , V_27 ) <= 0 )
goto V_22;
V_30 = F_19 ( V_32 ) ;
if ( V_30 == NULL ) {
F_8 ( V_36 , V_38 ) ;
goto V_22;
}
if ( F_18 ( V_28 , V_30 , & V_32 , V_26 , V_27 ) <= 0 )
goto V_22;
F_20 ( V_25 -> V_39 , V_30 , V_32 ) ;
V_30 = NULL ;
V_31 = 1 ;
V_22:
F_21 ( V_28 ) ;
F_22 ( V_30 ) ;
return V_31 ;
}
static int F_23 ( unsigned char * * V_40 , int * V_41 ,
T_6 * V_25 , T_8 * V_29 )
{
T_7 * V_28 = NULL ;
unsigned char * V_30 = NULL ;
T_9 V_32 ;
int V_31 = - 1 ;
V_28 = F_15 ( V_29 , NULL ) ;
if ( ! V_28 )
return - 1 ;
if ( F_24 ( V_28 ) <= 0 )
goto V_22;
if ( F_17 ( V_28 , - 1 , V_42 ,
V_43 , 0 , V_25 ) <= 0 ) {
F_8 ( V_44 , V_37 ) ;
goto V_22;
}
if ( F_25 ( V_28 , NULL , & V_32 ,
V_25 -> V_39 -> V_11 , V_25 -> V_39 -> V_45 ) <= 0 )
goto V_22;
V_30 = F_19 ( V_32 ) ;
if ( V_30 == NULL ) {
F_8 ( V_44 , V_38 ) ;
goto V_22;
}
if ( F_25 ( V_28 , V_30 , & V_32 ,
V_25 -> V_39 -> V_11 , V_25 -> V_39 -> V_45 ) <= 0 ) {
V_31 = 0 ;
F_8 ( V_44 , V_46 ) ;
goto V_22;
}
V_31 = 1 ;
F_26 ( * V_40 , * V_41 ) ;
* V_40 = V_30 ;
* V_41 = V_32 ;
V_22:
F_21 ( V_28 ) ;
if ( ! V_31 )
F_22 ( V_30 ) ;
return V_31 ;
}
T_3 * F_27 ( T_1 * V_1 , T_3 * V_47 )
{
int V_48 ;
T_3 * V_49 = NULL , * V_18 = NULL ;
T_4 * V_50 = NULL ;
const T_10 * V_51 = NULL ;
F_28 ( T_4 ) * V_52 = NULL ;
F_28 ( T_6 ) * V_53 = NULL ;
T_4 * V_54 = NULL ;
T_6 * V_25 = NULL ;
T_2 * V_55 = NULL ;
if ( V_1 == NULL ) {
F_8 ( V_56 , V_57 ) ;
return NULL ;
}
if ( V_1 -> V_10 . V_58 == NULL ) {
F_8 ( V_56 , V_59 ) ;
return NULL ;
}
V_48 = F_2 ( V_1 -> type ) ;
V_1 -> V_60 = V_61 ;
switch ( V_48 ) {
case V_5 :
V_52 = V_1 -> V_10 . V_62 -> V_63 ;
V_55 = F_3 ( V_1 -> V_10 . V_62 -> V_64 ) ;
break;
case V_7 :
V_53 = V_1 -> V_10 . V_65 -> V_66 ;
V_52 = V_1 -> V_10 . V_65 -> V_63 ;
V_54 = V_1 -> V_10 . V_65 -> V_67 -> V_23 ;
V_51 = V_1 -> V_10 . V_65 -> V_67 -> V_68 ;
if ( V_51 == NULL ) {
F_8 ( V_56 , V_69 ) ;
goto V_22;
}
break;
case V_6 :
V_53 = V_1 -> V_10 . V_70 -> V_66 ;
V_54 = V_1 -> V_10 . V_70 -> V_67 -> V_23 ;
V_51 = V_1 -> V_10 . V_70 -> V_67 -> V_68 ;
if ( V_51 == NULL ) {
F_8 ( V_56 , V_69 ) ;
goto V_22;
}
break;
case V_8 :
V_50 = V_1 -> V_10 . V_71 -> V_19 ;
V_55 = F_3 ( V_1 -> V_10 . V_71 -> V_64 ) ;
break;
case V_4 :
break;
default:
F_8 ( V_56 , V_72 ) ;
goto V_22;
}
for ( V_48 = 0 ; V_48 < F_29 ( V_52 ) ; V_48 ++ )
if ( ! F_5 ( & V_49 , F_30 ( V_52 , V_48 ) ) )
goto V_22;
if ( V_50 && ! F_5 ( & V_49 , V_50 ) )
goto V_22;
if ( V_51 != NULL ) {
unsigned char V_26 [ V_73 ] ;
unsigned char V_74 [ V_75 ] ;
int V_27 , V_76 ;
T_11 * V_77 ;
if ( ( V_18 = F_6 ( F_31 () ) ) == NULL ) {
F_8 ( V_56 , V_21 ) ;
goto V_22;
}
F_32 ( V_18 , & V_77 ) ;
V_27 = F_33 ( V_51 ) ;
V_76 = F_34 ( V_51 ) ;
V_54 -> V_23 = F_35 ( F_36 ( V_51 ) ) ;
if ( V_76 > 0 )
if ( F_37 ( V_74 , V_76 ) <= 0 )
goto V_22;
if ( F_38 ( V_77 , V_51 , NULL , NULL , NULL , 1 ) <= 0 )
goto V_22;
if ( F_39 ( V_77 , V_26 ) <= 0 )
goto V_22;
if ( F_38 ( V_77 , NULL , NULL , V_26 , V_74 , 1 ) <= 0 )
goto V_22;
if ( V_76 > 0 ) {
if ( V_54 -> V_78 == NULL ) {
V_54 -> V_78 = F_40 () ;
if ( V_54 -> V_78 == NULL )
goto V_22;
}
if ( F_41 ( V_77 , V_54 -> V_78 ) < 0 )
goto V_22;
}
for ( V_48 = 0 ; V_48 < F_42 ( V_53 ) ; V_48 ++ ) {
V_25 = F_43 ( V_53 , V_48 ) ;
if ( F_13 ( V_25 , V_26 , V_27 ) <= 0 )
goto V_22;
}
F_44 ( V_26 , V_27 ) ;
if ( V_49 == NULL )
V_49 = V_18 ;
else
F_11 ( V_49 , V_18 ) ;
V_18 = NULL ;
}
if ( V_47 == NULL ) {
if ( F_45 ( V_1 ) )
V_47 = F_6 ( F_46 () ) ;
else if ( V_55 && V_55 -> V_45 > 0 )
V_47 = F_47 ( V_55 -> V_11 , V_55 -> V_45 ) ;
if ( V_47 == NULL ) {
V_47 = F_6 ( F_48 () ) ;
if ( V_47 == NULL )
goto V_22;
F_49 ( V_47 , 0 ) ;
}
}
if ( V_49 )
F_11 ( V_49 , V_47 ) ;
else
V_49 = V_47 ;
return V_49 ;
V_22:
F_50 ( V_49 ) ;
F_50 ( V_18 ) ;
return NULL ;
}
static int F_51 ( T_6 * V_25 , T_12 * V_79 )
{
int V_31 ;
V_31 = F_52 ( V_25 -> V_80 -> V_81 ,
F_53 ( V_79 ) ) ;
if ( V_31 )
return V_31 ;
return F_54 ( F_55 ( V_79 ) ,
V_25 -> V_80 -> V_82 ) ;
}
T_3 * F_56 ( T_1 * V_1 , T_8 * V_29 , T_3 * V_83 , T_12 * V_79 )
{
int V_48 , V_84 ;
T_3 * V_49 = NULL , * V_18 = NULL , * V_85 = NULL , * V_47 = NULL ;
T_4 * V_50 ;
T_2 * V_86 = NULL ;
const T_5 * V_87 ;
const T_10 * V_51 = NULL ;
T_11 * V_88 = NULL ;
T_4 * V_89 = NULL ;
F_28 ( T_4 ) * V_52 = NULL ;
F_28 ( T_6 ) * V_53 = NULL ;
T_6 * V_25 = NULL ;
unsigned char * V_30 = NULL , * V_90 = NULL ;
int V_32 = 0 , V_91 = 0 ;
if ( V_1 == NULL ) {
F_8 ( V_92 , V_57 ) ;
return NULL ;
}
if ( V_1 -> V_10 . V_58 == NULL ) {
F_8 ( V_92 , V_59 ) ;
return NULL ;
}
V_48 = F_2 ( V_1 -> type ) ;
V_1 -> V_60 = V_61 ;
switch ( V_48 ) {
case V_5 :
V_86 = F_3 ( V_1 -> V_10 . V_62 -> V_64 ) ;
if ( ! F_45 ( V_1 ) && V_86 == NULL ) {
F_8 ( V_92 ,
V_93 ) ;
goto V_22;
}
V_52 = V_1 -> V_10 . V_62 -> V_63 ;
break;
case V_7 :
V_53 = V_1 -> V_10 . V_65 -> V_66 ;
V_52 = V_1 -> V_10 . V_65 -> V_63 ;
V_86 = V_1 -> V_10 . V_65 -> V_67 -> V_67 ;
V_89 = V_1 -> V_10 . V_65 -> V_67 -> V_23 ;
V_51 = F_57 ( V_89 -> V_23 ) ;
if ( V_51 == NULL ) {
F_8 ( V_92 ,
V_94 ) ;
goto V_22;
}
break;
case V_6 :
V_53 = V_1 -> V_10 . V_70 -> V_66 ;
V_89 = V_1 -> V_10 . V_70 -> V_67 -> V_23 ;
V_86 = V_1 -> V_10 . V_70 -> V_67 -> V_67 ;
V_51 = F_57 ( V_89 -> V_23 ) ;
if ( V_51 == NULL ) {
F_8 ( V_92 ,
V_94 ) ;
goto V_22;
}
break;
default:
F_8 ( V_92 , V_72 ) ;
goto V_22;
}
if ( V_86 == NULL && V_83 == NULL ) {
F_8 ( V_92 , V_59 ) ;
goto V_22;
}
if ( V_52 != NULL ) {
for ( V_48 = 0 ; V_48 < F_29 ( V_52 ) ; V_48 ++ ) {
V_50 = F_30 ( V_52 , V_48 ) ;
if ( ( V_18 = F_6 ( F_7 () ) ) == NULL ) {
F_8 ( V_92 , V_21 ) ;
goto V_22;
}
V_84 = F_2 ( V_50 -> V_23 ) ;
V_87 = F_58 ( V_84 ) ;
if ( V_87 == NULL ) {
F_8 ( V_92 ,
V_24 ) ;
goto V_22;
}
F_10 ( V_18 , V_87 ) ;
if ( V_49 == NULL )
V_49 = V_18 ;
else
F_11 ( V_49 , V_18 ) ;
V_18 = NULL ;
}
}
if ( V_51 != NULL ) {
if ( ( V_85 = F_6 ( F_31 () ) ) == NULL ) {
F_8 ( V_92 , V_21 ) ;
goto V_22;
}
if ( V_79 ) {
for ( V_48 = 0 ; V_48 < F_42 ( V_53 ) ; V_48 ++ ) {
V_25 = F_43 ( V_53 , V_48 ) ;
if ( ! F_51 ( V_25 , V_79 ) )
break;
V_25 = NULL ;
}
if ( V_25 == NULL ) {
F_8 ( V_92 ,
V_95 ) ;
goto V_22;
}
}
if ( V_79 == NULL ) {
for ( V_48 = 0 ; V_48 < F_42 ( V_53 ) ; V_48 ++ ) {
V_25 = F_43 ( V_53 , V_48 ) ;
if ( F_23 ( & V_30 , & V_32 , V_25 , V_29 ) < 0 )
goto V_22;
F_59 () ;
}
} else {
if ( F_23 ( & V_30 , & V_32 , V_25 , V_29 ) < 0 )
goto V_22;
F_59 () ;
}
V_88 = NULL ;
F_32 ( V_85 , & V_88 ) ;
if ( F_38 ( V_88 , V_51 , NULL , NULL , NULL , 0 ) <= 0 )
goto V_22;
if ( F_60 ( V_88 , V_89 -> V_78 ) < 0 )
goto V_22;
V_91 = F_61 ( V_88 ) ;
V_90 = F_19 ( V_91 ) ;
if ( V_90 == NULL )
goto V_22;
if ( F_39 ( V_88 , V_90 ) <= 0 )
goto V_22;
if ( V_30 == NULL ) {
V_30 = V_90 ;
V_32 = V_91 ;
V_90 = NULL ;
}
if ( V_32 != F_61 ( V_88 ) ) {
if ( ! F_62 ( V_88 , V_32 ) ) {
F_26 ( V_30 , V_32 ) ;
V_30 = V_90 ;
V_32 = V_91 ;
V_90 = NULL ;
}
}
F_59 () ;
if ( F_38 ( V_88 , NULL , NULL , V_30 , NULL , 0 ) <= 0 )
goto V_22;
F_26 ( V_30 , V_32 ) ;
V_30 = NULL ;
F_26 ( V_90 , V_91 ) ;
V_90 = NULL ;
if ( V_49 == NULL )
V_49 = V_85 ;
else
F_11 ( V_49 , V_85 ) ;
V_85 = NULL ;
}
if ( V_83 != NULL ) {
V_47 = V_83 ;
} else {
if ( V_86 -> V_45 > 0 )
V_47 = F_47 ( V_86 -> V_11 , V_86 -> V_45 ) ;
else {
V_47 = F_6 ( F_48 () ) ;
if ( V_47 == NULL )
goto V_22;
F_49 ( V_47 , 0 ) ;
}
if ( V_47 == NULL )
goto V_22;
}
F_11 ( V_49 , V_47 ) ;
V_47 = NULL ;
return V_49 ;
V_22:
F_26 ( V_30 , V_32 ) ;
F_26 ( V_90 , V_91 ) ;
F_50 ( V_49 ) ;
F_50 ( V_18 ) ;
F_50 ( V_85 ) ;
F_50 ( V_47 ) ;
return NULL ;
}
static T_3 * F_63 ( T_13 * * V_96 , T_3 * V_47 , int V_3 )
{
for (; ; ) {
V_47 = F_64 ( V_47 , V_97 ) ;
if ( V_47 == NULL ) {
F_8 ( V_98 ,
V_99 ) ;
return NULL ;
}
F_65 ( V_47 , V_96 ) ;
if ( * V_96 == NULL ) {
F_8 ( V_98 , V_100 ) ;
return NULL ;
}
if ( F_66 ( * V_96 ) == V_3 )
return V_47 ;
V_47 = F_67 ( V_47 ) ;
}
return NULL ;
}
static int F_68 ( T_14 * V_101 , T_13 * V_102 )
{
unsigned char V_103 [ V_104 ] ;
unsigned int V_105 ;
if ( ! F_69 ( V_101 , V_106 ) ) {
if ( ! F_70 ( V_101 , NULL ) ) {
F_8 ( V_107 , V_38 ) ;
return 0 ;
}
}
if ( ! F_71 ( V_102 , V_103 , & V_105 ) ) {
F_8 ( V_107 , V_46 ) ;
return 0 ;
}
if ( ! F_72 ( V_101 , V_103 , V_105 ) ) {
F_8 ( V_107 , V_38 ) ;
return 0 ;
}
if ( ! F_73 ( V_101 ) )
return 0 ;
return 1 ;
}
int F_74 ( T_1 * V_1 , T_3 * V_47 )
{
int V_31 = 0 ;
int V_48 , V_84 ;
T_3 * V_18 ;
T_14 * V_101 ;
T_13 * V_108 , * V_109 ;
F_28 ( V_110 ) * V_111 ;
F_28 ( T_14 ) * V_112 = NULL ;
T_2 * V_55 = NULL ;
if ( V_1 == NULL ) {
F_8 ( V_113 , V_57 ) ;
return 0 ;
}
if ( V_1 -> V_10 . V_58 == NULL ) {
F_8 ( V_113 , V_59 ) ;
return 0 ;
}
V_109 = F_75 () ;
if ( V_109 == NULL ) {
F_8 ( V_113 , V_38 ) ;
return 0 ;
}
V_48 = F_2 ( V_1 -> type ) ;
V_1 -> V_60 = V_61 ;
switch ( V_48 ) {
case V_4 :
V_55 = V_1 -> V_10 . V_11 ;
break;
case V_7 :
V_112 = V_1 -> V_10 . V_65 -> V_114 ;
V_55 = V_1 -> V_10 . V_65 -> V_67 -> V_67 ;
if ( V_55 == NULL ) {
V_55 = F_76 () ;
if ( V_55 == NULL ) {
F_8 ( V_113 , V_38 ) ;
goto V_22;
}
V_1 -> V_10 . V_65 -> V_67 -> V_67 = V_55 ;
}
break;
case V_6 :
V_55 = V_1 -> V_10 . V_70 -> V_67 -> V_67 ;
if ( V_55 == NULL ) {
V_55 = F_76 () ;
if ( V_55 == NULL ) {
F_8 ( V_113 , V_38 ) ;
goto V_22;
}
V_1 -> V_10 . V_70 -> V_67 -> V_67 = V_55 ;
}
break;
case V_5 :
V_112 = V_1 -> V_10 . V_62 -> V_114 ;
V_55 = F_3 ( V_1 -> V_10 . V_62 -> V_64 ) ;
if ( F_4 ( V_1 -> V_10 . V_62 -> V_64 ) && V_1 -> V_115 ) {
F_77 ( V_55 ) ;
V_55 = NULL ;
V_1 -> V_10 . V_62 -> V_64 -> V_10 . V_11 = NULL ;
}
break;
case V_8 :
V_55 = F_3 ( V_1 -> V_10 . V_71 -> V_64 ) ;
if ( F_4 ( V_1 -> V_10 . V_71 -> V_64 ) && V_1 -> V_115 ) {
F_77 ( V_55 ) ;
V_55 = NULL ;
V_1 -> V_10 . V_71 -> V_64 -> V_10 . V_11 = NULL ;
}
break;
default:
F_8 ( V_113 , V_72 ) ;
goto V_22;
}
if ( V_112 != NULL ) {
for ( V_48 = 0 ; V_48 < F_78 ( V_112 ) ; V_48 ++ ) {
V_101 = F_79 ( V_112 , V_48 ) ;
if ( V_101 -> V_29 == NULL )
continue;
V_84 = F_2 ( V_101 -> V_116 -> V_23 ) ;
V_18 = V_47 ;
V_18 = F_63 ( & V_108 , V_18 , V_84 ) ;
if ( V_18 == NULL )
goto V_22;
if ( ! F_80 ( V_109 , V_108 ) )
goto V_22;
V_111 = V_101 -> V_117 ;
if ( F_81 ( V_111 ) > 0 ) {
if ( ! F_68 ( V_101 , V_109 ) )
goto V_22;
} else {
unsigned char * V_118 = NULL ;
unsigned int V_119 ;
V_119 = F_82 ( V_101 -> V_29 ) ;
V_118 = F_19 ( V_119 ) ;
if ( V_118 == NULL )
goto V_22;
if ( ! F_83 ( V_109 , V_118 , & V_119 , V_101 -> V_29 ) ) {
F_22 ( V_118 ) ;
F_8 ( V_113 , V_46 ) ;
goto V_22;
}
F_20 ( V_101 -> V_120 , V_118 , V_119 ) ;
}
}
} else if ( V_48 == V_8 ) {
unsigned char V_103 [ V_104 ] ;
unsigned int V_105 ;
if ( ! F_63 ( & V_108 , V_47 ,
F_2 ( V_1 -> V_10 . V_71 -> V_19 -> V_23 ) ) )
goto V_22;
if ( ! F_71 ( V_108 , V_103 , & V_105 ) )
goto V_22;
if ( ! F_84 ( V_1 -> V_10 . V_71 -> V_71 , V_103 , V_105 ) )
goto V_22;
}
if ( ! F_45 ( V_1 ) ) {
if ( V_55 == NULL )
goto V_22;
if ( ! ( V_55 -> V_121 & V_122 ) ) {
char * V_123 ;
long V_124 ;
V_18 = F_64 ( V_47 , V_125 ) ;
if ( V_18 == NULL ) {
F_8 ( V_113 , V_126 ) ;
goto V_22;
}
V_124 = F_85 ( V_18 , & V_123 ) ;
F_86 ( V_18 , V_127 ) ;
F_49 ( V_18 , 0 ) ;
F_20 ( V_55 , ( unsigned char * ) V_123 , V_124 ) ;
}
}
V_31 = 1 ;
V_22:
F_87 ( V_109 ) ;
return ( V_31 ) ;
}
int F_73 ( T_14 * V_101 )
{
T_13 * V_102 ;
T_7 * V_28 ;
unsigned char * V_118 = NULL ;
int V_128 ;
T_9 V_129 ;
const T_5 * V_19 = NULL ;
V_19 = F_9 ( V_101 -> V_116 -> V_23 ) ;
if ( V_19 == NULL )
return 0 ;
V_102 = F_75 () ;
if ( V_102 == NULL ) {
F_8 ( V_130 , V_38 ) ;
goto V_22;
}
if ( F_88 ( V_102 , & V_28 , V_19 , NULL , V_101 -> V_29 ) <= 0 )
goto V_22;
if ( F_17 ( V_28 , - 1 , V_131 ,
V_132 , 0 , V_101 ) <= 0 ) {
F_8 ( V_130 , V_37 ) ;
goto V_22;
}
V_128 = F_89 ( ( V_133 * ) V_101 -> V_117 , & V_118 ,
F_90 ( V_134 ) ) ;
if ( ! V_118 )
goto V_22;
if ( F_91 ( V_102 , V_118 , V_128 ) <= 0 )
goto V_22;
F_22 ( V_118 ) ;
V_118 = NULL ;
if ( F_92 ( V_102 , NULL , & V_129 ) <= 0 )
goto V_22;
V_118 = F_19 ( V_129 ) ;
if ( V_118 == NULL )
goto V_22;
if ( F_92 ( V_102 , V_118 , & V_129 ) <= 0 )
goto V_22;
if ( F_17 ( V_28 , - 1 , V_131 ,
V_132 , 1 , V_101 ) <= 0 ) {
F_8 ( V_130 , V_37 ) ;
goto V_22;
}
F_87 ( V_102 ) ;
F_20 ( V_101 -> V_120 , V_118 , V_129 ) ;
return 1 ;
V_22:
F_22 ( V_118 ) ;
F_87 ( V_102 ) ;
return 0 ;
}
int F_93 ( T_15 * V_135 , T_16 * V_77 , T_3 * V_47 ,
T_1 * V_1 , T_14 * V_101 )
{
T_17 * V_136 ;
int V_31 = 0 , V_48 ;
F_28 ( T_12 ) * V_33 ;
T_12 * V_137 ;
if ( V_1 == NULL ) {
F_8 ( V_138 , V_57 ) ;
return 0 ;
}
if ( V_1 -> V_10 . V_58 == NULL ) {
F_8 ( V_138 , V_59 ) ;
return 0 ;
}
if ( F_94 ( V_1 ) ) {
V_33 = V_1 -> V_10 . V_62 -> V_33 ;
} else if ( F_95 ( V_1 ) ) {
V_33 = V_1 -> V_10 . V_65 -> V_33 ;
} else {
F_8 ( V_138 , V_139 ) ;
goto V_22;
}
V_136 = V_101 -> V_80 ;
V_137 = F_96 ( V_33 , V_136 -> V_81 , V_136 -> V_82 ) ;
if ( V_137 == NULL ) {
F_8 ( V_138 ,
V_140 ) ;
goto V_22;
}
if ( ! F_97 ( V_77 , V_135 , V_137 , V_33 ) ) {
F_8 ( V_138 , V_141 ) ;
goto V_22;
}
F_98 ( V_77 , V_142 ) ;
V_48 = F_99 ( V_77 ) ;
if ( V_48 <= 0 ) {
F_8 ( V_138 , V_141 ) ;
F_100 ( V_77 ) ;
goto V_22;
}
F_100 ( V_77 ) ;
return F_101 ( V_47 , V_1 , V_101 , V_137 ) ;
V_22:
return V_31 ;
}
int F_101 ( T_3 * V_47 , T_1 * V_1 , T_14 * V_101 ,
T_12 * V_137 )
{
T_2 * V_55 ;
T_13 * V_143 , * V_108 ;
int V_31 = 0 , V_48 ;
int V_144 ;
F_28 ( V_110 ) * V_111 ;
T_3 * V_18 ;
T_8 * V_29 ;
V_143 = F_75 () ;
if ( V_143 == NULL ) {
F_8 ( V_145 , V_38 ) ;
goto V_22;
}
if ( ! F_94 ( V_1 ) && ! F_95 ( V_1 ) ) {
F_8 ( V_145 , V_139 ) ;
goto V_22;
}
V_144 = F_2 ( V_101 -> V_116 -> V_23 ) ;
V_18 = V_47 ;
for (; ; ) {
if ( ( V_18 == NULL ) ||
( ( V_18 = F_64 ( V_18 , V_97 ) ) == NULL ) ) {
F_8 ( V_145 ,
V_99 ) ;
goto V_22;
}
F_65 ( V_18 , & V_108 ) ;
if ( V_108 == NULL ) {
F_8 ( V_145 , V_100 ) ;
goto V_22;
}
if ( F_66 ( V_108 ) == V_144 )
break;
if ( F_102 ( F_103 ( V_108 ) ) == V_144 )
break;
V_18 = F_67 ( V_18 ) ;
}
if ( ! F_80 ( V_143 , V_108 ) )
goto V_22;
V_111 = V_101 -> V_117 ;
if ( ( V_111 != NULL ) && ( F_81 ( V_111 ) != 0 ) ) {
unsigned char V_146 [ V_104 ] , * V_118 = NULL ;
unsigned int V_105 ;
int V_128 ;
T_2 * V_147 ;
if ( ! F_71 ( V_143 , V_146 , & V_105 ) )
goto V_22;
V_147 = F_104 ( V_111 ) ;
if ( ! V_147 ) {
F_8 ( V_145 ,
V_99 ) ;
goto V_22;
}
if ( ( V_147 -> V_45 != ( int ) V_105 ) ||
( memcmp ( V_147 -> V_11 , V_146 , V_105 ) ) ) {
F_8 ( V_145 , V_148 ) ;
V_31 = - 1 ;
goto V_22;
}
if ( ! F_105 ( V_143 , F_58 ( V_144 ) , NULL ) )
goto V_22;
V_128 = F_89 ( ( V_133 * ) V_111 , & V_118 ,
F_90 ( V_149 ) ) ;
if ( V_128 <= 0 ) {
F_8 ( V_145 , V_150 ) ;
V_31 = - 1 ;
goto V_22;
}
if ( ! F_106 ( V_143 , V_118 , V_128 ) )
goto V_22;
F_22 ( V_118 ) ;
}
V_55 = V_101 -> V_120 ;
V_29 = F_14 ( V_137 ) ;
if ( ! V_29 ) {
V_31 = - 1 ;
goto V_22;
}
V_48 = F_107 ( V_143 , V_55 -> V_11 , V_55 -> V_45 , V_29 ) ;
if ( V_48 <= 0 ) {
F_8 ( V_145 , V_151 ) ;
V_31 = - 1 ;
goto V_22;
}
V_31 = 1 ;
V_22:
F_87 ( V_143 ) ;
return ( V_31 ) ;
}
T_17 * F_108 ( T_1 * V_1 , int V_152 )
{
F_28 ( T_6 ) * V_53 ;
T_6 * V_25 ;
int V_48 ;
V_48 = F_2 ( V_1 -> type ) ;
if ( V_48 != V_7 )
return NULL ;
if ( V_1 -> V_10 . V_65 == NULL )
return NULL ;
V_53 = V_1 -> V_10 . V_65 -> V_66 ;
if ( V_53 == NULL )
return NULL ;
if ( F_42 ( V_53 ) <= V_152 )
return ( NULL ) ;
V_25 = F_43 ( V_53 , V_152 ) ;
return ( V_25 -> V_80 ) ;
}
T_18 * F_69 ( T_14 * V_101 , int V_3 )
{
return ( F_109 ( V_101 -> V_117 , V_3 ) ) ;
}
T_18 * F_110 ( T_14 * V_101 , int V_3 )
{
return ( F_109 ( V_101 -> V_153 , V_3 ) ) ;
}
int F_111 ( T_14 * V_154 , int V_3 , int V_155 ,
void * V_14 )
{
return ( F_112 ( & ( V_154 -> V_117 ) , V_3 , V_155 , V_14 ) ) ;
}
int F_113 ( T_14 * V_154 , int V_3 , int V_155 ,
void * V_14 )
{
return ( F_112 ( & ( V_154 -> V_153 ) , V_3 , V_155 , V_14 ) ) ;
}
