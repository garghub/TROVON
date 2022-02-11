int MAIN ( int V_1 , char * * V_2 )
{
int V_3 = 1 ;
char * V_4 = NULL ;
char * V_5 = NULL ;
T_1 * V_6 = NULL ;
enum T_2 {
V_7 , V_8 , V_9 , V_10
} T_2 = V_7 ;
char * V_11 = NULL ;
char * V_12 = NULL ;
const T_3 * V_13 = NULL ;
char * V_14 = NULL ;
char * V_15 = NULL ;
int V_16 = 0 ;
int V_17 = 0 ;
char * V_18 = NULL ;
char * V_19 = NULL ;
int V_20 = 0 ;
char * V_21 = NULL ;
char * V_22 = NULL ;
char * V_23 = NULL ;
char * V_24 = NULL ;
char * V_25 = NULL ;
char * V_26 = NULL ;
char * V_27 = NULL ;
char * V_28 = NULL ;
char * V_29 = NULL ;
char * V_30 = NULL ;
int V_31 = 0 ;
int V_32 = 0 ;
int V_33 = 0 ;
F_1 () ;
F_2 () ;
if ( V_34 == NULL && ( V_34 = F_3 ( F_4 () ) ) != NULL ) {
V_33 = 1 ;
F_5 ( V_34 , V_35 , V_36 | V_37 ) ;
}
if ( ! F_6 ( V_34 , NULL ) )
goto V_38;
for ( V_1 -- , V_2 ++ ; V_1 > 0 ; V_1 -- , V_2 ++ ) {
if ( strcmp ( * V_2 , L_1 ) == 0 ) {
if ( V_1 -- < 1 )
goto V_39;
V_4 = * ++ V_2 ;
} else if ( strcmp ( * V_2 , L_2 ) == 0 ) {
if ( V_1 -- < 1 )
goto V_39;
V_5 = * ++ V_2 ;
} else if ( strcmp ( * V_2 , L_3 ) == 0 ) {
if ( T_2 != V_7 )
goto V_39;
T_2 = V_8 ;
} else if ( strcmp ( * V_2 , L_4 ) == 0 ) {
if ( V_1 -- < 1 )
goto V_39;
V_11 = * ++ V_2 ;
} else if ( strcmp ( * V_2 , L_5 ) == 0 ) {
if ( V_1 -- < 1 )
goto V_39;
V_12 = * ++ V_2 ;
} else if ( strcmp ( * V_2 , L_6 ) == 0 ) {
if ( V_1 -- < 1 )
goto V_39;
V_14 = * ++ V_2 ;
} else if ( strcmp ( * V_2 , L_7 ) == 0 ) {
if ( V_1 -- < 1 )
goto V_39;
V_15 = * ++ V_2 ;
} else if ( strcmp ( * V_2 , L_8 ) == 0 ) {
V_16 = 1 ;
} else if ( strcmp ( * V_2 , L_9 ) == 0 ) {
V_17 = 1 ;
} else if ( strcmp ( * V_2 , L_10 ) == 0 ) {
if ( V_1 -- < 1 )
goto V_39;
V_18 = * ++ V_2 ;
} else if ( strcmp ( * V_2 , L_11 ) == 0 ) {
V_31 = 1 ;
} else if ( strcmp ( * V_2 , L_12 ) == 0 ) {
if ( V_1 -- < 1 )
goto V_39;
V_19 = * ++ V_2 ;
} else if ( strcmp ( * V_2 , L_13 ) == 0 ) {
V_32 = 1 ;
} else if ( strcmp ( * V_2 , L_14 ) == 0 ) {
V_20 = 1 ;
} else if ( strcmp ( * V_2 , L_15 ) == 0 ) {
if ( T_2 != V_7 )
goto V_39;
T_2 = V_9 ;
} else if ( strcmp ( * V_2 , L_16 ) == 0 ) {
if ( V_1 -- < 1 )
goto V_39;
V_21 = * ++ V_2 ;
} else if ( strcmp ( * V_2 , L_17 ) == 0 ) {
if ( V_1 -- < 1 )
goto V_39;
V_22 = * ++ V_2 ;
} else if ( strcmp ( * V_2 , L_18 ) == 0 ) {
if ( V_1 -- < 1 )
goto V_39;
V_24 = * ++ V_2 ;
} else if ( strcmp ( * V_2 , L_19 ) == 0 ) {
if ( V_1 -- < 1 )
goto V_39;
V_25 = * ++ V_2 ;
} else if ( strcmp ( * V_2 , L_20 ) == 0 ) {
if ( V_1 -- < 1 )
goto V_39;
V_26 = * ++ V_2 ;
} else if ( strcmp ( * V_2 , L_21 ) == 0 ) {
if ( T_2 != V_7 )
goto V_39;
T_2 = V_10 ;
} else if ( strcmp ( * V_2 , L_22 ) == 0 ) {
if ( V_1 -- < 1 )
goto V_39;
V_27 = * ++ V_2 ;
} else if ( strcmp ( * V_2 , L_23 ) == 0 ) {
if ( V_1 -- < 1 )
goto V_39;
V_28 = * ++ V_2 ;
} else if ( strcmp ( * V_2 , L_24 ) == 0 ) {
if ( V_1 -- < 1 )
goto V_39;
V_29 = * ++ V_2 ;
} else if ( strcmp ( * V_2 , L_25 ) == 0 ) {
if ( V_1 -- < 1 )
goto V_39;
V_30 = * ++ V_2 ;
} else if ( ( V_13 = F_7 ( * V_2 + 1 ) ) != NULL ) {
} else
goto V_39;
}
if ( T_2 == V_8 && ! V_16 ) {
if ( ! F_8 ( NULL , V_34 , 1 ) && V_14 == NULL )
F_9 ( V_34 , L_26
L_27 ) ;
if ( V_14 != NULL )
F_9 ( V_34 , L_28 ,
F_10 ( V_14 ) ) ;
}
if ( T_2 == V_9 && V_22 &&
! F_11 ( V_34 , V_22 , NULL , & V_23 , NULL ) ) {
F_9 ( V_34 , L_29 ) ;
goto V_38;
}
switch ( T_2 ) {
case V_7 :
goto V_39;
case V_8 :
V_3 = V_11 != NULL && V_12 != NULL ;
if ( V_3 )
goto V_39;
V_6 = F_12 ( V_4 ) ;
V_3 = ! F_13 ( V_11 , V_12 , V_13 , V_15 , V_16 , V_17 ,
V_18 , V_19 , V_20 ) ;
break;
case V_9 :
V_6 = F_12 ( V_4 ) ;
if ( V_18 == NULL ) {
V_3 = ! ( V_21 != NULL && V_6 != NULL && ! V_31 ) ;
if ( V_3 )
goto V_39;
} else {
V_3 = ! ( V_21 == NULL ) ;
if ( V_3 )
goto V_39;
}
V_3 = ! F_14 ( V_6 , V_5 , V_30 , V_21 ,
V_23 , V_24 , V_25 , V_26 , V_15 ,
V_18 , V_31 , V_19 , V_32 , V_20 ) ;
break;
case V_10 :
V_3 = ! ( ( ( V_21 && ! V_11 && ! V_12 )
|| ( ! V_21 && V_11 && ! V_12 )
|| ( ! V_21 && ! V_11 && V_12 ) )
&& V_18 != NULL ) ;
if ( V_3 )
goto V_39;
V_3 = ! F_15 ( V_11 , V_12 , V_21 , V_18 , V_31 ,
V_27 , V_28 , V_29 ) ;
}
goto V_38;
V_39:
F_9 ( V_34 , L_30
L_31
L_32
L_33
L_34
L_35 ,
V_40 , V_40 ) ;
F_9 ( V_34 , L_36
L_37
L_38
L_39
L_40
L_41
L_42 ) ;
F_9 ( V_34 , L_36
L_43
L_44
L_45
L_46
L_47 ) ;
V_38:
F_16 ( NULL , V_34 ) ;
F_17 ( V_6 ) ;
F_18 ( V_23 ) ;
F_19 () ;
if ( V_33 ) {
F_20 ( V_34 ) ;
V_34 = NULL ;
}
F_21 ( V_3 ) ;
}
static T_4 * F_22 ( const char * V_41 )
{
T_4 * V_42 = NULL ;
if ( ! ( V_42 = F_23 ( V_41 , 0 ) ) )
F_9 ( V_34 , L_48 , V_41 ) ;
return V_42 ;
}
static T_1 * F_12 ( const char * V_4 )
{
T_1 * V_6 = NULL ;
long V_43 = - 1 ;
if ( ! V_4 )
V_4 = getenv ( L_49 ) ;
if ( ! V_4 )
V_4 = getenv ( L_50 ) ;
if ( V_4 &&
( ! ( V_6 = F_24 ( NULL ) ) ||
F_25 ( V_6 , V_4 , & V_43 ) <= 0 ) ) {
if ( V_43 <= 0 )
F_9 ( V_34 , L_51
L_52 , V_4 ) ;
else
F_9 ( V_34 , L_53
L_52 , V_43 , V_4 ) ;
}
if ( V_6 != NULL ) {
const char * V_44 ;
F_9 ( V_34 , L_54 , V_4 ) ;
V_44 = F_26 ( V_6 , NULL , V_45 ) ;
if ( V_44 != NULL ) {
T_5 * V_46 = F_27 ( V_44 , L_55 ) ;
if ( ! V_46 )
F_28 ( V_34 ) ;
else {
F_29 ( V_46 ) ;
F_20 ( V_46 ) ;
}
} else
F_30 () ;
if ( ! F_31 ( V_34 , V_6 ) )
F_28 ( V_34 ) ;
}
return V_6 ;
}
static int F_13 ( const char * V_11 , char * V_12 , const T_3 * V_13 ,
const char * V_15 , int V_16 ,
int V_17 , const char * V_18 , const char * V_19 , int V_20 )
{
int V_3 = 0 ;
T_6 * V_47 = NULL ;
T_5 * V_48 = NULL ;
T_5 * V_49 = NULL ;
T_5 * V_50 = NULL ;
if ( V_18 != NULL ) {
if ( ( V_48 = F_27 ( V_18 , L_56 ) ) == NULL )
goto V_51;
V_47 = F_32 ( V_48 , NULL ) ;
} else {
if ( ! V_12 && ! ( V_49 = F_33 ( V_11 , L_56 , V_52 ) ) )
goto V_51;
V_47 = F_34 ( V_49 , V_12 , V_13 , V_15 , V_16 , V_17 ) ;
}
if ( V_47 == NULL )
goto V_51;
if ( ( V_50 = F_33 ( V_19 , L_57 , stdout ) ) == NULL )
goto V_51;
if ( V_20 ) {
if ( ! F_35 ( V_50 , V_47 ) )
goto V_51;
} else {
if ( ! F_36 ( V_50 , V_47 ) )
goto V_51;
}
V_3 = 1 ;
V_51:
F_28 ( V_34 ) ;
F_20 ( V_48 ) ;
F_20 ( V_49 ) ;
F_20 ( V_50 ) ;
F_37 ( V_47 ) ;
return V_3 ;
}
static T_5 * F_33 ( const char * V_53 , const char * T_2 ,
T_7 * V_54 )
{
return V_53 == NULL ? F_38 ( V_54 , V_36 )
: F_27 ( V_53 , T_2 ) ;
}
static T_6 * F_34 ( T_5 * V_49 , char * V_12 , const T_3 * V_13 ,
const char * V_15 , int V_16 , int V_17 )
{
int V_3 = 0 ;
T_6 * V_55 = NULL ;
int V_56 ;
T_8 * V_57 = NULL ;
T_9 * V_58 = NULL ;
unsigned char * V_11 = NULL ;
T_4 * V_59 = NULL ;
T_10 * V_60 = NULL ;
if ( ! V_13 && ! ( V_13 = F_7 ( L_58 ) ) )
goto V_61;
if ( ! ( V_55 = F_39 () ) )
goto V_61;
if ( ! F_40 ( V_55 , 1 ) )
goto V_61;
if ( ! ( V_57 = F_41 () ) )
goto V_61;
if ( ! ( V_58 = F_42 () ) )
goto V_61;
if ( ! ( V_58 -> V_62 = F_43 ( F_44 ( V_13 ) ) ) )
goto V_61;
if ( ! ( V_58 -> V_63 = F_45 () ) )
goto V_61;
V_58 -> V_63 -> type = V_64 ;
if ( ! F_46 ( V_57 , V_58 ) )
goto V_61;
if ( ( V_56 = F_47 ( V_49 , V_12 , V_13 , & V_11 ) ) == 0 )
goto V_61;
if ( ! F_48 ( V_57 , V_11 , V_56 ) )
goto V_61;
if ( ! F_49 ( V_55 , V_57 ) )
goto V_61;
if ( V_15 && ! ( V_59 = F_22 ( V_15 ) ) )
goto V_61;
if ( V_59 && ! F_50 ( V_55 , V_59 ) )
goto V_61;
if ( ! V_16 && ! ( V_60 = F_51 ( V_65 ) ) )
goto V_61;
if ( V_60 && ! F_52 ( V_55 , V_60 ) )
goto V_61;
if ( ! F_53 ( V_55 , V_17 ) )
goto V_61;
V_3 = 1 ;
V_61:
if ( ! V_3 ) {
F_37 ( V_55 ) ;
V_55 = NULL ;
F_9 ( V_34 , L_59 ) ;
}
F_54 ( V_57 ) ;
F_55 ( V_58 ) ;
F_18 ( V_11 ) ;
F_56 ( V_59 ) ;
F_57 ( V_60 ) ;
return V_55 ;
}
static int F_47 ( T_5 * V_66 , char * V_12 , const T_3 * V_13 ,
unsigned char * * V_67 )
{
int V_68 ;
V_68 = F_58 ( V_13 ) ;
if ( V_68 < 0 )
goto V_61;
if ( V_66 ) {
T_11 V_69 ;
unsigned char V_70 [ 4096 ] ;
int V_71 ;
* V_67 = F_59 ( V_68 ) ;
if ( * V_67 == 0 )
goto V_61;
F_60 ( & V_69 , V_13 ) ;
while ( ( V_71 = F_61 ( V_66 , V_70 , sizeof( V_70 ) ) ) > 0 ) {
F_62 ( & V_69 , V_70 , V_71 ) ;
}
F_63 ( & V_69 , * V_67 , NULL ) ;
} else {
long V_72 ;
* V_67 = F_64 ( V_12 , & V_72 ) ;
if ( ! * V_67 || V_68 != V_72 ) {
F_18 ( * V_67 ) ;
* V_67 = NULL ;
F_9 ( V_34 , L_60
L_61 , V_68 ) ;
goto V_61;
}
}
return V_68 ;
V_61:
return 0 ;
}
static T_10 * F_51 ( int V_73 )
{
unsigned char V_74 [ 20 ] ;
T_10 * V_75 = NULL ;
int V_56 = ( V_73 - 1 ) / 8 + 1 ;
int V_76 ;
if ( V_56 > ( int ) sizeof( V_74 ) )
goto V_61;
if ( F_65 ( V_74 , V_56 ) <= 0 )
goto V_61;
for ( V_76 = 0 ; V_76 < V_56 && ! V_74 [ V_76 ] ; ++ V_76 ) ;
if ( ! ( V_75 = F_66 () ) )
goto V_61;
F_18 ( V_75 -> V_11 ) ;
V_75 -> V_71 = V_56 - V_76 ;
if ( ! ( V_75 -> V_11 = F_59 ( V_75 -> V_71 + 1 ) ) )
goto V_61;
memcpy ( V_75 -> V_11 , V_74 + V_76 , V_75 -> V_71 ) ;
return V_75 ;
V_61:
F_9 ( V_34 , L_62 ) ;
F_57 ( V_75 ) ;
return NULL ;
}
static int F_14 ( T_1 * V_6 , char * V_5 , char * V_30 ,
char * V_21 , char * V_22 , char * V_24 ,
char * V_25 , char * V_26 , const char * V_15 ,
char * V_18 , int V_31 ,
char * V_19 , int V_32 , int V_20 )
{
int V_3 = 0 ;
T_12 * V_77 = NULL ;
T_5 * V_48 = NULL ;
T_5 * V_78 = NULL ;
T_5 * V_79 = NULL ;
T_5 * V_80 = NULL ;
T_5 * V_50 = NULL ;
if ( V_18 != NULL ) {
if ( ( V_48 = F_27 ( V_18 , L_56 ) ) == NULL )
goto V_51;
if ( V_31 ) {
V_77 = F_67 ( V_48 ) ;
} else {
V_77 = F_68 ( V_48 , NULL ) ;
}
} else {
V_77 = F_69 ( V_6 , V_5 , V_30 , V_21 ,
V_22 , V_24 , V_25 , V_26 , V_15 ) ;
if ( V_77 )
F_9 ( V_34 , L_63 ) ;
else
F_9 ( V_34 , L_64 ) ;
}
if ( V_77 == NULL )
goto V_51;
if ( ( V_50 = F_33 ( V_19 , L_57 , stdout ) ) == NULL )
goto V_51;
if ( V_20 ) {
if ( V_32 ) {
T_13 * V_81 = F_70 ( V_77 ) ;
if ( ! F_71 ( V_50 , V_81 ) )
goto V_51;
} else {
if ( ! F_72 ( V_50 , V_77 ) )
goto V_51;
}
} else {
if ( V_32 ) {
T_14 * V_82 = F_73 ( V_77 ) ;
if ( ! F_74 ( V_50 , V_82 ) )
goto V_51;
} else {
if ( ! F_75 ( V_50 , V_77 ) )
goto V_51;
}
}
V_3 = 1 ;
V_51:
F_28 ( V_34 ) ;
F_20 ( V_48 ) ;
F_20 ( V_78 ) ;
F_20 ( V_79 ) ;
F_20 ( V_80 ) ;
F_20 ( V_50 ) ;
F_76 ( V_77 ) ;
return V_3 ;
}
static T_12 * F_67 ( T_5 * V_48 )
{
int V_3 = 0 ;
T_14 * V_82 = NULL ;
T_13 * V_81 = NULL ;
T_12 * V_83 = NULL ;
T_15 * V_84 = NULL ;
if ( ! ( V_82 = F_77 ( V_48 , NULL ) ) )
goto V_51;
if ( ! ( V_81 = F_78 ( V_82 ) ) )
goto V_51;
if ( ! ( V_83 = F_79 () ) )
goto V_51;
if ( ! ( V_84 = F_80 () ) )
goto V_51;
if ( ! ( F_81 ( V_84 -> V_85 , V_86 ) ) )
goto V_51;
if ( ! F_82 ( V_83 , V_84 ) )
goto V_51;
F_83 ( V_83 , V_82 , V_81 ) ;
V_82 = NULL ;
V_81 = NULL ;
V_3 = 1 ;
V_51:
F_84 ( V_82 ) ;
F_85 ( V_81 ) ;
if ( ! V_3 ) {
F_76 ( V_83 ) ;
V_83 = NULL ;
}
F_86 ( V_84 ) ;
return V_83 ;
}
static T_12 * F_69 ( T_1 * V_6 , const char * V_5 , char * V_30 ,
char * V_21 , char * V_22 , char * V_24 ,
char * V_25 , char * V_26 , const char * V_15 )
{
int V_3 = 0 ;
T_12 * V_77 = NULL ;
T_5 * V_78 = NULL ;
T_16 * V_87 = NULL ;
if ( ! ( V_78 = F_27 ( V_21 , L_56 ) ) )
goto V_51;
if ( ! ( V_5 = F_87 ( V_6 , V_5 ) ) )
goto V_51;
if ( ! ( V_87 = F_88 () ) )
goto V_51;
if ( ! F_89 ( V_6 , V_5 , V_88 , V_87 ) )
goto V_51;
#ifndef F_90
if ( ! F_91 ( V_6 , V_5 , V_30 ) )
goto V_51;
#endif
if ( ! F_92 ( V_6 , V_5 , V_25 , V_87 ) )
goto V_51;
if ( ! F_93 ( V_6 , V_5 , V_26 , V_87 ) )
goto V_51;
if ( ! F_94 ( V_6 , V_5 , V_24 , V_22 , V_87 ) )
goto V_51;
if ( ! F_95 ( V_6 , V_5 , V_15 , V_87 ) )
goto V_51;
if ( ! F_96 ( V_6 , V_5 , V_87 ) )
goto V_51;
if ( ! F_97 ( V_6 , V_5 , V_87 ) )
goto V_51;
if ( ! F_98 ( V_6 , V_5 , V_87 ) )
goto V_51;
if ( ! F_99 ( V_6 , V_5 , V_87 ) )
goto V_51;
if ( ! F_100 ( V_6 , V_5 , V_87 ) )
goto V_51;
if ( ! F_101 ( V_6 , V_5 , V_87 ) )
goto V_51;
if ( ! F_102 ( V_6 , V_5 , V_87 ) )
goto V_51;
if ( ! ( V_77 = F_103 ( V_87 , V_78 ) ) )
goto V_51;
V_3 = 1 ;
V_51:
if ( ! V_3 ) {
F_76 ( V_77 ) ;
V_77 = NULL ;
}
F_104 ( V_87 ) ;
F_20 ( V_78 ) ;
return V_77 ;
}
static T_10 * T_17 V_88 ( T_16 * V_89 , void * V_11 )
{
const char * V_90 = ( const char * ) V_11 ;
T_10 * V_91 = F_105 ( V_90 ) ;
if ( ! V_91 ) {
F_106 ( V_89 , V_92 ,
L_65
L_66 ) ;
F_107 ( V_89 , V_93 ) ;
} else
F_108 ( V_90 , V_91 ) ;
return V_91 ;
}
static T_10 * F_105 ( const char * V_94 )
{
int V_3 = 0 ;
T_5 * V_18 = NULL ;
T_10 * V_91 = NULL ;
T_18 * V_95 = NULL ;
if ( ! ( V_91 = F_66 () ) )
goto V_61;
if ( ! ( V_18 = F_27 ( V_94 , L_55 ) ) ) {
F_30 () ;
F_9 ( V_34 , L_67
L_68 , V_94 ) ;
if ( ! F_81 ( V_91 , 1 ) )
goto V_61;
} else {
char V_74 [ 1024 ] ;
if ( ! F_109 ( V_18 , V_91 , V_74 , sizeof( V_74 ) ) ) {
F_9 ( V_34 , L_69 ,
V_94 ) ;
goto V_61;
}
if ( ! ( V_95 = F_110 ( V_91 , NULL ) ) )
goto V_61;
F_57 ( V_91 ) ;
V_91 = NULL ;
if ( ! F_111 ( V_95 , 1 ) )
goto V_61;
if ( ! ( V_91 = F_112 ( V_95 , NULL ) ) )
goto V_61;
}
V_3 = 1 ;
V_61:
if ( ! V_3 ) {
F_57 ( V_91 ) ;
V_91 = NULL ;
}
F_20 ( V_18 ) ;
F_113 ( V_95 ) ;
return V_91 ;
}
static int F_108 ( const char * V_94 , T_10 * V_91 )
{
int V_3 = 0 ;
T_5 * V_19 = NULL ;
if ( ! ( V_19 = F_27 ( V_94 , L_70 ) ) )
goto V_61;
if ( F_114 ( V_19 , V_91 ) <= 0 )
goto V_61;
if ( F_115 ( V_19 , L_71 ) <= 0 )
goto V_61;
V_3 = 1 ;
V_61:
if ( ! V_3 )
F_9 ( V_34 , L_72 ,
V_94 ) ;
F_20 ( V_19 ) ;
return V_3 ;
}
static int F_15 ( char * V_11 , char * V_12 , char * V_21 ,
char * V_18 , int V_31 ,
char * V_27 , char * V_28 , char * V_29 )
{
T_5 * V_48 = NULL ;
T_14 * V_82 = NULL ;
T_12 * V_77 = NULL ;
T_19 * V_96 = NULL ;
int V_3 = 0 ;
if ( ! ( V_48 = F_27 ( V_18 , L_56 ) ) )
goto V_51;
if ( V_31 ) {
if ( ! ( V_82 = F_77 ( V_48 , NULL ) ) )
goto V_51;
} else {
if ( ! ( V_77 = F_68 ( V_48 , NULL ) ) )
goto V_51;
}
if ( ! ( V_96 = F_116 ( V_11 , V_12 , V_21 ,
V_27 , V_28 , V_29 ) ) )
goto V_51;
V_3 = V_31 ?
F_117 ( V_96 , V_82 ) :
F_118 ( V_96 , V_77 ) ;
V_51:
printf ( L_73 ) ;
if ( V_3 )
printf ( L_74 ) ;
else {
printf ( L_75 ) ;
F_28 ( V_34 ) ;
}
F_20 ( V_48 ) ;
F_84 ( V_82 ) ;
F_76 ( V_77 ) ;
F_119 ( V_96 ) ;
return V_3 ;
}
static T_19 * F_116 ( char * V_11 , char * V_12 ,
char * V_21 ,
char * V_27 , char * V_28 ,
char * V_29 )
{
T_19 * V_89 = NULL ;
T_5 * V_66 = NULL ;
T_6 * V_97 = NULL ;
int V_3 = 0 ;
if ( V_11 != NULL || V_12 != NULL ) {
if ( ! ( V_89 = F_120 () ) )
goto V_61;
V_89 -> V_98 = V_99 | V_100 ;
if ( V_11 != NULL ) {
V_89 -> V_98 |= V_101 ;
if ( ! ( V_89 -> V_11 = F_27 ( V_11 , L_56 ) ) )
goto V_61;
} else if ( V_12 != NULL ) {
long V_102 ;
V_89 -> V_98 |= V_103 ;
if ( ! ( V_89 -> V_104 = F_64 ( V_12 , & V_102 ) ) ) {
F_9 ( V_34 , L_76 ) ;
goto V_61;
}
V_89 -> V_102 = V_102 ;
}
} else if ( V_21 != NULL ) {
if ( ! ( V_66 = F_27 ( V_21 , L_56 ) ) )
goto V_61;
if ( ! ( V_97 = F_32 ( V_66 , NULL ) ) )
goto V_61;
if ( ! ( V_89 = F_121 ( V_97 , NULL ) ) )
goto V_61;
} else
return NULL ;
V_89 -> V_98 |= V_105 ;
if ( ! ( V_89 -> V_106 = F_122 ( V_27 , V_28 ) ) )
goto V_61;
if ( V_29 && ! ( V_89 -> V_107 = F_123 ( V_29 ) ) )
goto V_61;
V_3 = 1 ;
V_61:
if ( ! V_3 ) {
F_119 ( V_89 ) ;
V_89 = NULL ;
}
F_20 ( V_66 ) ;
F_37 ( V_97 ) ;
return V_89 ;
}
static T_20 * F_122 ( char * V_27 , char * V_28 )
{
T_20 * V_108 = NULL ;
T_21 * V_109 = NULL ;
int V_76 ;
V_108 = F_124 () ;
F_125 ( V_108 , V_110 ) ;
if ( V_27 ) {
V_109 = F_126 ( V_108 , F_127 () ) ;
if ( V_109 == NULL ) {
F_9 ( V_34 , L_77 ) ;
goto V_61;
}
V_76 = F_128 ( V_109 , V_27 , V_111 ) ;
if ( ! V_76 ) {
F_9 ( V_34 , L_78 , V_27 ) ;
goto V_61;
}
}
if ( V_28 ) {
V_109 = F_126 ( V_108 , F_129 () ) ;
if ( V_109 == NULL ) {
F_9 ( V_34 , L_77 ) ;
goto V_61;
}
V_76 = F_130 ( V_109 , V_28 , V_111 ) ;
if ( ! V_76 ) {
F_9 ( V_34 , L_79 , V_28 ) ;
goto V_61;
}
}
return V_108 ;
V_61:
F_131 ( V_108 ) ;
return NULL ;
}
static int T_17 V_110 ( int V_112 , T_22 * V_89 )
{
return V_112 ;
}
