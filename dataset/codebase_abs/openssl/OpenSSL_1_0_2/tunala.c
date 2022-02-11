static T_1 * F_1 ( void )
{
T_1 * V_1 = NULL ;
if ( ( V_1 = F_2 () ) == NULL )
return ( NULL ) ;
V_1 -> V_2 = F_3 ( V_3 , sizeof( V_3 ) , NULL ) ;
V_1 -> V_4 = F_3 ( V_5 , sizeof( V_5 ) , NULL ) ;
if ( ( V_1 -> V_2 == NULL ) || ( V_1 -> V_4 == NULL ) )
return ( NULL ) ;
return ( V_1 ) ;
}
static int F_4 ( const char * V_6 , int V_7 )
{
if ( V_7 )
fprintf ( V_8 , L_1 , V_6 ) ;
else
fprintf ( V_8 , L_2 , V_6 ) ;
fprintf ( V_8 , L_3 , V_9 ) ;
return 1 ;
}
static int F_5 ( const char * V_10 )
{
fprintf ( V_8 , L_3 , V_10 ) ;
return 1 ;
}
static int F_6 ( const char * V_11 , const char * V_12 )
{
fprintf ( V_8 , V_11 , V_12 ) ;
fprintf ( V_8 , L_4 ) ;
return 1 ;
}
static int F_7 ( const char * V_13 , unsigned int * V_14 )
{
unsigned long V_15 ;
if ( ! F_8 ( V_13 , & V_15 ) || ( V_15 < 1 ) || ( V_15 > 1024 ) ) {
fprintf ( V_8 , L_5
L_6 , V_13 ) ;
return 0 ;
}
* V_14 = ( unsigned int ) V_15 ;
return 1 ;
}
static int F_9 ( const char * V_13 , int * V_16 )
{
unsigned long V_15 ;
if ( ! F_8 ( V_13 , & V_15 ) || ( V_15 > 1 ) ) {
fprintf ( V_8 , L_7
L_8 , V_13 ) ;
return 0 ;
}
* V_16 = ( int ) V_15 ;
return 1 ;
}
static int F_10 ( const char * V_13 , const char * * V_17 )
{
if ( ( strcmp ( V_13 , L_9 ) == 0 ) || ( strcmp ( V_13 , L_10 ) == 0 ) ||
( strcmp ( V_13 , L_11 ) == 0 ) ) {
* V_17 = V_13 ;
return 1 ;
}
fprintf ( V_8 , L_12 , V_13 ) ;
return 0 ;
}
static int F_11 ( const char * V_13 , unsigned int * V_18 )
{
unsigned long V_15 ;
if ( ! F_8 ( V_13 , & V_15 ) || ( V_15 > 3 ) ) {
fprintf ( V_8 , L_5
L_13 , V_13 ) ;
return 0 ;
}
* V_18 = ( unsigned int ) V_15 ;
return 1 ;
}
static int F_12 ( const char * V_13 , unsigned int * V_19 )
{
unsigned long V_15 ;
if ( ! F_8 ( V_13 , & V_15 ) || ( V_15 < 1 ) || ( V_15 > 50 ) ) {
fprintf ( V_8 , L_5
L_14 , V_13 ) ;
return 0 ;
}
* V_19 = ( unsigned int ) V_15 ;
return 1 ;
}
int main ( int V_20 , char * V_21 [] )
{
unsigned int V_22 ;
int V_23 ;
T_2 V_24 ;
T_3 * V_25 ;
const char * V_26 ;
unsigned short V_27 ;
const char * V_28 = V_29 ;
const char * V_30 = V_31 ;
unsigned int V_32 = V_33 ;
const char * V_34 = V_35 ;
const char * V_36 = V_37 ;
const char * V_38 = V_39 ;
const char * V_40 = V_41 ;
const char * V_42 = V_43 ;
const char * V_44 = V_45 ;
int V_46 = V_47 ;
int V_48 = V_49 ;
const char * V_50 = V_51 ;
const char * V_52 = V_53 ;
const char * V_17 = V_54 ;
int V_55 = V_56 ;
int V_57 = V_58 ;
int V_59 = V_60 ;
unsigned int V_19 = V_61 ;
int V_62 = V_63 ;
unsigned int V_64 = V_65 ;
int V_66 = V_67 ;
int V_68 = V_69 ;
V_70:
V_20 -- ;
V_21 ++ ;
if ( V_20 > 0 ) {
if ( strcmp ( * V_21 , L_15 ) == 0 ) {
if ( V_20 < 2 )
return F_4 ( L_16 , 0 ) ;
V_20 -- ;
V_21 ++ ;
V_30 = * V_21 ;
goto V_70;
} else if ( strcmp ( * V_21 , L_17 ) == 0 ) {
if ( V_20 < 2 )
return F_4 ( L_18 , 0 ) ;
V_20 -- ;
V_21 ++ ;
V_28 = * V_21 ;
goto V_70;
} else if ( strcmp ( * V_21 , L_19 ) == 0 ) {
if ( V_20 < 2 )
return F_4 ( L_20 , 0 ) ;
V_20 -- ;
V_21 ++ ;
if ( ! F_7 ( * V_21 , & V_32 ) )
return 1 ;
goto V_70;
} else if ( strcmp ( * V_21 , L_21 ) == 0 ) {
if ( V_20 < 2 )
return F_4 ( L_22 , 0 ) ;
V_20 -- ;
V_21 ++ ;
if ( strcmp ( * V_21 , L_9 ) == 0 )
V_34 = NULL ;
else
V_34 = * V_21 ;
goto V_70;
} else if ( strcmp ( * V_21 , L_23 ) == 0 ) {
if ( V_20 < 2 )
return F_4 ( L_24 , 0 ) ;
V_20 -- ;
V_21 ++ ;
if ( strcmp ( * V_21 , L_9 ) == 0 )
V_36 = NULL ;
else
V_36 = * V_21 ;
goto V_70;
} else if ( strcmp ( * V_21 , L_25 ) == 0 ) {
if ( V_20 < 2 )
return F_4 ( L_26 , 0 ) ;
V_20 -- ;
V_21 ++ ;
if ( strcmp ( * V_21 , L_9 ) == 0 )
V_38 = NULL ;
else
V_38 = * V_21 ;
goto V_70;
} else if ( strcmp ( * V_21 , L_27 ) == 0 ) {
if ( V_20 < 2 )
return F_4 ( L_28 , 0 ) ;
V_20 -- ;
V_21 ++ ;
if ( strcmp ( * V_21 , L_9 ) == 0 )
V_40 = NULL ;
else
V_40 = * V_21 ;
goto V_70;
} else if ( strcmp ( * V_21 , L_29 ) == 0 ) {
if ( V_20 < 2 )
return F_4 ( L_30 , 0 ) ;
V_20 -- ;
V_21 ++ ;
if ( strcmp ( * V_21 , L_9 ) == 0 )
V_42 = NULL ;
else
V_42 = * V_21 ;
goto V_70;
} else if ( strcmp ( * V_21 , L_31 ) == 0 ) {
if ( V_20 < 2 )
return F_4 ( L_32 , 0 ) ;
V_20 -- ;
V_21 ++ ;
V_44 = * V_21 ;
goto V_70;
} else if ( strcmp ( * V_21 , L_33 ) == 0 ) {
if ( V_20 < 2 )
return F_4 ( L_34 , 0 ) ;
V_20 -- ;
V_21 ++ ;
if ( ! F_9 ( * V_21 , & V_46 ) )
return 1 ;
goto V_70;
} else if ( strcmp ( * V_21 , L_35 ) == 0 ) {
if ( V_20 < 2 )
return F_4 ( L_36 , 0 ) ;
V_20 -- ;
V_21 ++ ;
if ( ! F_9 ( * V_21 , & V_48 ) )
return 1 ;
goto V_70;
} else if ( strcmp ( * V_21 , L_37 ) == 0 ) {
if ( V_20 < 2 )
return F_4 ( L_38 , 0 ) ;
V_20 -- ;
V_21 ++ ;
V_50 = * V_21 ;
goto V_70;
} else if ( strcmp ( * V_21 , L_39 ) == 0 ) {
if ( V_20 < 2 )
return F_4 ( L_40 , 0 ) ;
if ( V_17 )
return F_4 ( L_41 L_42 , 0 ) ;
V_20 -- ;
V_21 ++ ;
V_52 = * V_21 ;
goto V_70;
} else if ( strcmp ( * V_21 , L_42 ) == 0 ) {
if ( V_20 < 2 )
return F_4 ( L_43 , 0 ) ;
if ( V_52 )
return F_4 ( L_41 L_42 , 0 ) ;
V_20 -- ;
V_21 ++ ;
if ( ! F_10 ( * V_21 , & V_17 ) )
return 1 ;
goto V_70;
} else if ( strcmp ( * V_21 , L_44 ) == 0 ) {
V_55 = 0 ;
goto V_70;
} else if ( strcmp ( * V_21 , L_45 ) == 0 ) {
V_57 |= V_71 ;
goto V_70;
} else if ( strcmp ( * V_21 , L_46 ) == 0 ) {
V_57 |= V_72 ;
goto V_70;
} else if ( strcmp ( * V_21 , L_47 ) == 0 ) {
V_57 |= V_73 ;
goto V_70;
} else if ( strcmp ( * V_21 , L_48 ) == 0 ) {
V_59 |= V_74 ;
goto V_70;
} else if ( strcmp ( * V_21 , L_49 ) == 0 ) {
V_59 |= V_75 ;
goto V_70;
} else if ( strcmp ( * V_21 , L_50 ) == 0 ) {
V_59 |= V_76 ;
goto V_70;
} else if ( strcmp ( * V_21 , L_51 ) == 0 ) {
if ( V_20 < 2 )
return F_4 ( L_52 , 0 ) ;
V_20 -- ;
V_21 ++ ;
if ( ! F_12 ( * V_21 , & V_19 ) )
return 1 ;
goto V_70;
} else if ( strcmp ( * V_21 , L_53 ) == 0 ) {
V_62 = 1 ;
goto V_70;
} else if ( strcmp ( * V_21 , L_54 ) == 0 ) {
if ( V_20 < 2 )
return F_4 ( L_55 , 0 ) ;
V_20 -- ;
V_21 ++ ;
if ( ! F_11 ( * V_21 , & V_64 ) )
return 1 ;
goto V_70;
} else if ( strcmp ( * V_21 , L_56 ) == 0 ) {
V_66 = 1 ;
goto V_70;
} else if ( strcmp ( * V_21 , L_57 ) == 0 ) {
V_68 = 1 ;
goto V_70;
} else if ( ( strcmp ( * V_21 , L_58 ) == 0 ) ||
( strcmp ( * V_21 , L_59 ) == 0 ) ||
( strcmp ( * V_21 , L_60 ) == 0 ) ) {
fprintf ( V_8 , L_3 , V_9 ) ;
return 0 ;
} else
return F_4 ( * V_21 , 1 ) ;
}
if ( ! V_36 && ! V_40 && V_46 )
fprintf ( V_8 , L_61
L_62 ) ;
if ( ! F_13 () )
return F_5 ( L_63 ) ;
if ( ( V_24 . V_77 = F_14 ( V_46 , V_44 ,
V_34 , V_36 , V_38 , V_40 , V_42 ,
V_50 , V_52 , V_17 ,
V_55 , V_57 , V_62 ,
V_64 , V_59 ,
V_19 ) ) == NULL )
return F_6 ( L_64 ,
( V_44 == NULL ) ? L_9 : V_44 ) ;
if ( V_44 )
fprintf ( V_8 , L_65 , V_44 ) ;
if ( ( V_24 . V_78 = F_15 ( V_30 ) ) == - 1 )
return F_6 ( L_66 , V_30 ) ;
fprintf ( V_8 , L_67 , V_30 ) ;
if ( ! F_16 ( V_28 , & V_26 , & V_27 , 0 ) )
return F_6 ( L_68 , V_28 ) ;
fprintf ( V_8 , L_69 , V_28 ,
( int ) V_26 [ 0 ] , ( int ) V_26 [ 1 ] ,
( int ) V_26 [ 2 ] , ( int ) V_26 [ 3 ] , ( int ) V_27 ) ;
fprintf ( V_8 , L_70 , ( int ) V_32 ) ;
fprintf ( V_8 , L_71 ,
( V_46 ? L_72 : L_73 ) ) ;
V_24 . V_79 = V_24 . V_80 = 0 ;
V_24 . V_81 = NULL ;
V_24 . V_46 = V_46 ;
F_17 ( & V_24 . V_82 ) ;
V_83:
if ( V_24 . V_79 < V_32 )
F_18 ( & V_24 . V_82 , V_24 . V_78 ) ;
for ( V_22 = 0 ; V_22 < V_24 . V_79 ; V_22 ++ )
F_19 ( & V_24 . V_82 , V_24 . V_81 + V_22 ) ;
switch ( F_20 ( & V_24 . V_82 ) ) {
case - 1 :
if ( V_84 != V_85 ) {
fprintf ( V_8 , L_74 L_75 ) ;
goto V_86;
}
fprintf ( V_8 , L_76 ) ;
goto V_83;
case 0 :
fprintf ( V_8 , L_77 L_78 ) ;
goto V_83;
default:
break;
}
if ( ( V_24 . V_79 < V_32 )
&& ( F_21 ( & V_24 . V_82 , V_24 . V_78 , & V_23 ) ==
1 ) ) {
if ( ! F_22 ( & V_24 , V_23 , V_26 ,
V_27 , V_48 ) )
fprintf ( V_8 , L_79 ) ;
else if ( V_68 )
fprintf ( V_8 , L_80
L_81 , V_24 . V_79 ) ;
}
V_22 = 0 ;
V_25 = V_24 . V_81 ;
while ( V_22 < V_24 . V_79 ) {
if ( ! F_23 ( & V_24 . V_82 , V_25 ) ) {
if ( ! V_66 )
goto V_87;
fprintf ( V_8 , L_82 ) ;
fprintf ( V_8 , V_88 ,
F_24 ( F_25
( & V_25 -> V_89 , V_90 ) ) ,
F_26 ( F_25
( & V_25 -> V_89 , V_91 ) ) ) ;
fprintf ( V_8 , V_92 ,
F_26 ( F_25
( & V_25 -> V_89 , V_93 ) ) ,
F_24 ( F_25
( & V_25 -> V_89 , V_94 ) ) ) ;
V_87:
F_27 ( & V_24 , V_22 ) ;
if ( V_68 )
fprintf ( V_8 , L_83 ,
V_24 . V_79 ) ;
} else {
V_22 ++ ;
V_25 ++ ;
}
}
goto V_83;
V_86:
abort () ;
return 1 ;
}
static int F_28 ( T_4 * V_95 , const char * V_36 , const char * V_38 )
{
T_5 * V_96 = NULL ;
T_6 * V_97 = NULL ;
T_7 * V_98 = NULL ;
int V_99 = 0 ;
if ( V_36 ) {
if ( ( V_96 = fopen ( V_36 , L_84 ) ) == NULL ) {
fprintf ( V_8 , L_85 , V_36 ) ;
goto V_100;
}
if ( ! F_29 ( V_96 , & V_97 , NULL , NULL ) ) {
fprintf ( V_8 , L_86 , V_36 ) ;
goto V_100;
}
if ( ! F_30 ( V_95 , V_97 ) ) {
fprintf ( V_8 , L_87 , V_36 ) ;
goto V_100;
}
fclose ( V_96 ) ;
V_96 = NULL ;
fprintf ( V_8 , L_88 , V_36 ) ;
if ( ! V_38 )
V_38 = V_36 ;
} else {
if ( V_38 )
fprintf ( V_8 , L_89
L_90 ) ;
else
fprintf ( V_8 , L_91 L_92 ) ;
goto V_100;
}
if ( V_38 ) {
if ( ( V_96 = fopen ( V_38 , L_84 ) ) == NULL ) {
fprintf ( V_8 , L_93 , V_38 ) ;
goto V_100;
}
if ( ! F_31 ( V_96 , & V_98 , NULL , NULL ) ) {
fprintf ( V_8 , L_94 , V_38 ) ;
goto V_100;
}
if ( ! F_32 ( V_95 , V_98 ) ) {
fprintf ( V_8 , L_95 , V_38 ) ;
goto V_100;
}
fprintf ( V_8 , L_96 , V_38 ) ;
} else
fprintf ( V_8 , L_97 ) ;
V_99 = 1 ;
V_100:
if ( V_97 )
F_33 ( V_97 ) ;
if ( V_98 )
F_34 ( V_98 ) ;
if ( V_96 )
fclose ( V_96 ) ;
return V_99 ;
}
static int F_35 ( T_4 * V_95 , const char * V_52 ,
const char * V_17 )
{
T_1 * V_1 = NULL ;
T_5 * V_96 = NULL ;
if ( V_17 ) {
if ( strcmp ( V_17 , L_9 ) == 0 )
return 1 ;
if ( strcmp ( V_17 , L_11 ) == 0 ) {
if ( ( V_1 = F_1 () ) == NULL ) {
fprintf ( V_8 , L_98
L_99 ) ;
return 0 ;
}
fprintf ( V_8 , L_100 ) ;
goto V_101;
}
if ( strcmp ( V_17 , L_10 ) != 0 )
abort () ;
fprintf ( V_8 , L_101 ) ;
fflush ( V_8 ) ;
if ( ! ( V_1 = F_2 () ) || ! F_36 ( V_1 , 512 ,
V_102 ,
NULL ) ) {
fprintf ( V_8 , L_102 ) ;
if ( V_1 )
F_37 ( V_1 ) ;
return 0 ;
}
fprintf ( V_8 , L_103 ) ;
goto V_101;
}
if ( ( V_96 = fopen ( V_52 , L_84 ) ) == NULL ) {
fprintf ( V_8 , L_104 ,
V_52 ) ;
return 0 ;
}
V_1 = F_38 ( V_96 , NULL , NULL , NULL ) ;
fclose ( V_96 ) ;
if ( V_1 == NULL ) {
fprintf ( V_8 , L_105 ,
V_52 ) ;
return 0 ;
}
fprintf ( V_8 , L_106 , V_52 ) ;
V_101:
F_39 ( V_95 , V_1 ) ;
F_37 ( V_1 ) ;
return 1 ;
}
static T_4 * F_14 ( int V_46 , const char * V_44 ,
const char * V_103 , const char * V_36 ,
const char * V_38 , const char * V_40 ,
const char * V_42 , const char * V_50 ,
const char * V_52 ,
const char * V_17 , int V_55 ,
int V_57 , int V_62 ,
int V_64 , int V_59 ,
unsigned int V_19 )
{
T_4 * V_95 = NULL , * V_104 = NULL ;
const T_8 * V_105 ;
T_9 * V_106 = NULL ;
F_40 () ;
F_41 () ;
V_105 = ( V_46 ? F_42 () : F_43 () ) ;
if ( V_105 == NULL )
goto V_100;
if ( V_44 ) {
F_44 () ;
if ( ( V_106 = F_45 ( V_44 ) ) == NULL ) {
fprintf ( V_8 , L_107
L_108 , V_44 ) ;
goto V_100;
}
if ( ! F_46 ( V_106 , V_107 ) ) {
fprintf ( V_8 , L_109
L_108 , V_44 ) ;
goto V_100;
}
F_47 ( V_106 ) ;
}
if ( ( V_95 = F_48 ( V_105 ) ) == NULL )
goto V_100;
if ( V_103 ) {
if ( ! F_49 ( F_50 ( V_95 ) ,
V_103 , NULL ) ) {
fprintf ( V_8 , L_110 , V_103 ) ;
goto V_100;
}
fprintf ( V_8 , L_111 , V_103 ) ;
} else
fprintf ( V_8 , L_112 ) ;
if ( ! F_51 ( V_95 ) ) {
fprintf ( V_8 , L_113 ) ;
goto V_100;
}
if ( ( V_36 || V_38 ) && ! F_28 ( V_95 , V_36 , V_38 ) )
goto V_100;
if ( ( V_40 || V_42 ) && ! F_28 ( V_95 , V_40 , V_42 ) )
goto V_100;
if ( V_55 )
F_52 ( V_95 , V_108 ) ;
if ( V_50 ) {
if ( ! F_53 ( V_95 , V_50 ) ) {
fprintf ( V_8 , L_114 , V_50 ) ;
goto V_100;
}
fprintf ( V_8 , L_115 , V_50 ) ;
} else
fprintf ( V_8 , L_116 ) ;
if ( ( V_52 || V_17 ) && ! F_35 ( V_95 , V_52 , V_17 ) )
goto V_100;
F_54 ( V_95 , V_57 ) ;
if ( V_62 )
F_55 ( V_8 ) ;
if ( V_64 > 0 ) {
F_56 ( V_8 ) ;
F_57 ( V_64 ) ;
}
F_58 ( V_19 ) ;
F_59 ( V_95 , V_109 ) ;
F_60 ( V_95 , V_59 , V_110 ) ;
V_104 = V_95 ;
V_100:
if ( ! V_104 ) {
F_61 ( V_8 ) ;
if ( V_95 )
F_62 ( V_95 ) ;
}
return V_104 ;
}
static void F_63 ( T_10 * V_13 )
{
V_13 -> V_111 = 0 ;
F_64 ( & V_13 -> V_112 ) ;
F_64 ( & V_13 -> V_113 ) ;
F_64 ( & V_13 -> V_114 ) ;
}
static void F_17 ( T_11 * V_82 )
{
F_63 ( & V_82 -> V_115 ) ;
F_63 ( & V_82 -> V_116 ) ;
}
static void F_65 ( T_11 * V_13 , int V_117 , int V_118 )
{
F_66 ( V_117 , & V_13 -> V_116 . V_114 ) ;
if ( V_118 & V_119 )
F_66 ( V_117 , & V_13 -> V_116 . V_112 ) ;
if ( V_118 & V_120 )
F_66 ( V_117 , & V_13 -> V_116 . V_113 ) ;
if ( V_13 -> V_116 . V_111 < ( V_117 + 1 ) )
V_13 -> V_116 . V_111 = V_117 + 1 ;
}
static void F_18 ( T_11 * V_82 , int V_117 )
{
F_65 ( V_82 , V_117 , V_119 ) ;
}
static void F_19 ( T_11 * V_13 , T_3 * V_121 )
{
if ( V_121 -> V_122 != - 1 ) {
F_65 ( V_13 , V_121 -> V_122 ,
( F_67 ( F_25 ( & V_121 -> V_89 ,
V_94 ) )
? V_123 : V_119 ) ) ;
}
if ( V_121 -> V_124 != - 1 ) {
F_65 ( V_13 , V_121 -> V_124 ,
( F_68 ( F_25 ( & V_121 -> V_89 ,
V_93 ) )
? V_123 : V_120 ) ) ;
}
if ( V_121 -> V_125 != - 1 ) {
F_65 ( V_13 , V_121 -> V_125 ,
( F_67 ( F_25 ( & V_121 -> V_89 ,
V_90 ) )
? V_123 : V_119 ) ) ;
}
if ( V_121 -> V_126 != - 1 ) {
F_65 ( V_13 , V_121 -> V_126 ,
( F_68 ( F_25 ( & V_121 -> V_89 ,
V_91 ) )
? V_123 : V_120 ) ) ;
}
}
static int F_20 ( T_11 * V_82 )
{
memcpy ( & V_82 -> V_115 , & V_82 -> V_116 ,
sizeof( T_10 ) ) ;
F_63 ( & V_82 -> V_116 ) ;
return F_69 ( V_82 -> V_115 . V_111 ,
& V_82 -> V_115 . V_112 ,
& V_82 -> V_115 . V_113 ,
& V_82 -> V_115 . V_114 , NULL ) ;
}
static int F_21 ( T_11 * V_82 , int V_117 ,
int * V_23 )
{
if ( F_70 ( V_117 , & V_82 -> V_115 . V_114 ) )
return - 1 ;
if ( ! F_70 ( V_117 , & V_82 -> V_115 . V_112 ) )
return 0 ;
if ( ( * V_23 = F_71 ( V_117 ) ) == - 1 )
return - 1 ;
return 1 ;
}
static int F_72 ( T_2 * V_24 )
{
unsigned int V_127 ;
T_3 * V_128 ;
if ( V_24 -> V_79 < V_24 -> V_80 )
return 1 ;
V_127 = ( V_24 -> V_80 == 0 ? 16 :
( ( V_24 -> V_80 * 3 ) / 2 ) ) ;
if ( ( V_128 = malloc ( V_127 * sizeof( T_3 ) ) ) == NULL )
return 0 ;
memset ( V_128 , 0 , V_127 * sizeof( T_3 ) ) ;
if ( V_24 -> V_79 > 0 )
memcpy ( V_128 , V_24 -> V_81 ,
V_24 -> V_79 * sizeof( T_3 ) ) ;
if ( V_24 -> V_80 > 0 )
free ( V_24 -> V_81 ) ;
V_24 -> V_81 = V_128 ;
V_24 -> V_80 = V_127 ;
return 1 ;
}
static int F_22 ( T_2 * V_24 , int V_117 ,
const char * V_129 , unsigned short V_130 ,
int V_48 )
{
T_3 * V_131 ;
int V_23 ;
T_12 * V_132 = NULL ;
if ( ! F_72 ( V_24 ) )
return 0 ;
if ( ( V_132 = F_73 ( V_24 -> V_77 ) ) == NULL ) {
fprintf ( V_8 , L_117 ) ;
F_61 ( V_8 ) ;
return 0 ;
}
V_131 = V_24 -> V_81 + ( V_24 -> V_79 ++ ) ;
F_74 ( & V_131 -> V_89 ) ;
V_131 -> V_122 = V_131 -> V_124 =
V_131 -> V_125 = V_131 -> V_126 = - 1 ;
if ( ( V_23 = F_75 ( V_129 , V_130 ) ) == - 1 )
goto V_100;
if ( ( V_24 -> V_46 && ! V_48 ) || ( ! V_24 -> V_46 && V_48 ) ) {
V_131 -> V_125 = V_131 -> V_126 = V_117 ;
V_131 -> V_122 = V_131 -> V_124 = V_23 ;
} else {
V_131 -> V_122 = V_131 -> V_124 = V_117 ;
V_131 -> V_125 = V_131 -> V_126 = V_23 ;
}
F_76 ( V_132 , NULL ) ;
if ( ! F_77 ( & V_131 -> V_89 , V_132 , V_24 -> V_46 ) )
goto V_100;
return 1 ;
V_100:
F_27 ( V_24 , V_24 -> V_79 - 1 ) ;
return 0 ;
}
static void F_27 ( T_2 * V_24 , unsigned int V_133 )
{
T_3 * V_131 = V_24 -> V_81 + V_133 ;
if ( V_131 -> V_122 != - 1 )
F_78 ( V_131 -> V_122 ) ;
if ( V_131 -> V_124 != V_131 -> V_122 )
F_78 ( V_131 -> V_124 ) ;
V_131 -> V_122 = V_131 -> V_124 = - 1 ;
if ( V_131 -> V_125 != - 1 )
F_78 ( V_131 -> V_125 ) ;
if ( V_131 -> V_126 != V_131 -> V_125 )
F_78 ( V_131 -> V_126 ) ;
V_131 -> V_125 = V_131 -> V_126 = - 1 ;
F_79 ( & V_131 -> V_89 ) ;
if ( V_133 + 1 < V_24 -> V_79 )
memmove ( V_24 -> V_81 + V_133 ,
V_24 -> V_81 + ( V_133 + 1 ) ,
( V_24 -> V_79 - ( V_133 + 1 ) ) * sizeof( T_3 ) ) ;
V_24 -> V_79 -- ;
}
static int F_23 ( T_11 * V_82 , T_3 * V_131 )
{
int V_134 , V_135 , V_136 , V_137 ;
if ( ( V_131 -> V_122 != - 1 ) && F_70 ( V_131 -> V_122 ,
& V_82 ->
V_115 . V_114 ) )
return 0 ;
if ( ( V_131 -> V_124 != - 1 ) && F_70 ( V_131 -> V_124 ,
& V_82 ->
V_115 . V_114 ) )
return 0 ;
if ( ( V_131 -> V_125 != - 1 ) && F_70 ( V_131 -> V_125 ,
& V_82 ->
V_115 . V_114 ) )
return 0 ;
if ( ( V_131 -> V_126 != - 1 ) && F_70 ( V_131 -> V_126 ,
& V_82 ->
V_115 . V_114 ) )
return 0 ;
V_134 = V_135 = V_136 = V_137 = 0 ;
if ( V_131 -> V_122 != - 1 )
V_134 = F_70 ( V_131 -> V_122 , & V_82 -> V_115 . V_112 ) ;
if ( V_131 -> V_124 != - 1 )
V_135 = F_70 ( V_131 -> V_124 , & V_82 -> V_115 . V_113 ) ;
if ( V_131 -> V_125 != - 1 )
V_136 = F_70 ( V_131 -> V_125 , & V_82 -> V_115 . V_112 ) ;
if ( V_131 -> V_126 != - 1 )
V_137 = F_70 ( V_131 -> V_126 , & V_82 -> V_115 . V_113 ) ;
if ( ! V_134 && ! V_135 && ! V_136 && ! V_137 )
return 1 ;
if ( V_134 )
V_134 = ( F_80 ( F_25 ( & V_131 -> V_89 ,
V_94 ) ,
V_131 -> V_122 ) <= 0 ) ;
if ( V_135 )
V_135 = ( F_81 ( F_25 ( & V_131 -> V_89 ,
V_93 ) ,
V_131 -> V_124 ) <= 0 ) ;
if ( V_136 )
V_136 = ( F_80 ( F_25 ( & V_131 -> V_89 ,
V_90 ) ,
V_131 -> V_125 ) <= 0 ) ;
if ( V_137 )
V_137 = ( F_81 ( F_25 ( & V_131 -> V_89 ,
V_91 ) ,
V_131 -> V_126 ) <= 0 ) ;
if ( V_134 ) {
F_78 ( V_131 -> V_122 ) ;
if ( V_131 -> V_124 == V_131 -> V_122 )
V_131 -> V_124 = - 1 ;
V_131 -> V_122 = - 1 ;
}
if ( V_135 && ( V_131 -> V_124 != - 1 ) ) {
F_78 ( V_131 -> V_124 ) ;
if ( V_131 -> V_124 == V_131 -> V_122 )
V_131 -> V_122 = - 1 ;
V_131 -> V_124 = - 1 ;
}
if ( V_136 ) {
F_78 ( V_131 -> V_125 ) ;
if ( V_131 -> V_126 == V_131 -> V_125 )
V_131 -> V_126 = - 1 ;
V_131 -> V_125 = - 1 ;
}
if ( V_137 && ( V_131 -> V_126 != - 1 ) ) {
F_78 ( V_131 -> V_126 ) ;
if ( V_131 -> V_126 == V_131 -> V_125 )
V_131 -> V_125 = - 1 ;
V_131 -> V_126 = - 1 ;
}
if ( ! F_82 ( & V_131 -> V_89 ) )
return 0 ;
if ( ( ( V_131 -> V_122 == - 1 ) || ( V_131 -> V_124 == - 1 ) ) &&
( ( V_131 -> V_125 == - 1 ) || ( V_131 -> V_126 == - 1 ) ) )
return 0 ;
if ( ( V_131 -> V_122 == - 1 ) || ( V_131 -> V_124 == - 1 ) ) {
if ( ! F_83 ( & V_131 -> V_89 ) )
return 0 ;
}
if ( ( V_131 -> V_125 == - 1 ) || ( V_131 -> V_126 == - 1 ) ) {
if ( ! F_84 ( & V_131 -> V_89 ) )
return 0 ;
}
return 1 ;
}
