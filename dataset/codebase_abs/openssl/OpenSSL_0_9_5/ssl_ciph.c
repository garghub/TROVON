static void F_1 ( void )
{
V_1 = 0 ;
V_2 [ V_3 ] =
F_2 ( V_4 ) ;
V_2 [ V_5 ] =
F_2 ( V_6 ) ;
V_2 [ V_7 ] =
F_2 ( V_8 ) ;
V_2 [ V_9 ] =
F_2 ( V_10 ) ;
V_2 [ V_11 ] =
F_2 ( V_12 ) ;
V_13 [ V_14 ] =
F_3 ( V_15 ) ;
V_13 [ V_16 ] =
F_3 ( V_17 ) ;
}
int F_4 ( T_1 * V_18 , const T_2 * * V_19 ,
const T_3 * * V_20 , T_4 * * V_21 )
{
int V_22 ;
T_5 * V_23 ;
V_23 = V_18 -> V_24 ;
if ( V_23 == NULL ) return ( 0 ) ;
if ( V_21 != NULL )
{
T_4 V_25 ;
if ( V_18 -> V_26 == 0 )
* V_21 = NULL ;
else if ( V_27 == NULL )
{
* V_21 = NULL ;
}
else
{
V_25 . V_28 = V_18 -> V_26 ;
V_22 = F_5 ( V_27 , & V_25 ) ;
if ( V_22 >= 0 )
* V_21 = F_6 ( V_27 , V_22 ) ;
else
* V_21 = NULL ;
}
}
if ( ( V_19 == NULL ) || ( V_20 == NULL ) ) return ( 0 ) ;
switch ( V_23 -> V_29 & V_30 )
{
case V_31 :
V_22 = V_3 ;
break;
case V_32 :
V_22 = V_5 ;
break;
case V_33 :
V_22 = V_7 ;
break;
case V_34 :
V_22 = V_9 ;
break;
case V_35 :
V_22 = V_11 ;
break;
case V_36 :
V_22 = V_37 ;
break;
default:
V_22 = - 1 ;
break;
}
if ( ( V_22 < 0 ) || ( V_22 > V_38 ) )
* V_19 = NULL ;
else
{
if ( V_22 == V_37 )
* V_19 = F_7 () ;
else
* V_19 = V_2 [ V_22 ] ;
}
switch ( V_23 -> V_29 & V_39 )
{
case V_40 :
V_22 = V_14 ;
break;
case V_41 :
V_22 = V_16 ;
break;
default:
V_22 = - 1 ;
break;
}
if ( ( V_22 < 0 ) || ( V_22 > V_42 ) )
* V_20 = NULL ;
else
* V_20 = V_13 [ V_22 ] ;
if ( ( * V_19 != NULL ) && ( * V_20 != NULL ) )
return ( 1 ) ;
else
return ( 0 ) ;
}
static void F_8 ( T_6 * * V_43 , T_6 * V_44 ,
T_6 * * V_45 )
{
if ( V_44 == * V_45 ) return;
if ( V_44 == * V_43 )
* V_43 = V_44 -> V_46 ;
if ( V_44 -> V_47 != NULL )
V_44 -> V_47 -> V_46 = V_44 -> V_46 ;
if ( V_44 -> V_46 != NULL )
V_44 -> V_46 -> V_47 = V_44 -> V_47 ;
( * V_45 ) -> V_46 = V_44 ;
V_44 -> V_47 = * V_45 ;
V_44 -> V_46 = NULL ;
* V_45 = V_44 ;
}
static unsigned long F_9 ( void )
{
unsigned long V_48 ;
V_48 = V_49 ;
#ifdef F_10
V_48 |= V_50 | V_51 ;
#endif
#ifdef F_11
V_48 |= V_52 ;
#endif
#ifdef F_12
V_48 |= V_53 | V_54 | V_55 | V_56 ;
#endif
#ifdef F_13
V_48 |= V_36 ;
#endif
V_48 |= ( V_2 [ V_3 ] == NULL ) ? V_31 : 0 ;
V_48 |= ( V_2 [ V_5 ] == NULL ) ? V_32 : 0 ;
V_48 |= ( V_2 [ V_7 ] == NULL ) ? V_33 : 0 ;
V_48 |= ( V_2 [ V_9 ] == NULL ) ? V_34 : 0 ;
V_48 |= ( V_2 [ V_11 ] == NULL ) ? V_35 : 0 ;
V_48 |= ( V_2 [ V_57 ] == NULL ) ? V_58 : 0 ;
V_48 |= ( V_13 [ V_14 ] == NULL ) ? V_40 : 0 ;
V_48 |= ( V_13 [ V_16 ] == NULL ) ? V_41 : 0 ;
return ( V_48 ) ;
}
static void F_14 ( const T_7 * V_59 ,
int V_60 , unsigned long V_48 , T_6 * V_61 ,
T_6 * * V_62 , T_6 * * V_63 )
{
int V_22 , V_64 ;
T_5 * V_23 ;
V_64 = 0 ;
for ( V_22 = 0 ; V_22 < V_60 ; V_22 ++ )
{
V_23 = V_59 -> V_65 ( V_22 ) ;
if ( ( V_23 != NULL ) && V_23 -> V_66 && ! ( V_23 -> V_29 & V_48 ) )
{
V_61 [ V_64 ] . V_24 = V_23 ;
V_61 [ V_64 ] . V_46 = NULL ;
V_61 [ V_64 ] . V_47 = NULL ;
V_61 [ V_64 ] . V_67 = 0 ;
V_64 ++ ;
}
}
for ( V_22 = 1 ; V_22 < V_64 - 1 ; V_22 ++ )
{
V_61 [ V_22 ] . V_47 = & ( V_61 [ V_22 - 1 ] ) ;
V_61 [ V_22 ] . V_46 = & ( V_61 [ V_22 + 1 ] ) ;
}
if ( V_64 > 0 )
{
( * V_62 ) = & ( V_61 [ 0 ] ) ;
( * V_62 ) -> V_47 = NULL ;
( * V_62 ) -> V_46 = & ( V_61 [ 1 ] ) ;
( * V_63 ) = & ( V_61 [ V_64 - 1 ] ) ;
( * V_63 ) -> V_47 = & ( V_61 [ V_64 - 2 ] ) ;
( * V_63 ) -> V_46 = NULL ;
}
}
static void F_15 ( T_5 * * V_68 ,
int V_69 , unsigned long V_48 ,
T_6 * V_43 )
{
T_6 * V_70 ;
T_5 * * V_71 ;
int V_22 ;
V_70 = V_43 ;
V_71 = V_68 ;
while ( V_70 != NULL )
{
* V_71 = V_70 -> V_24 ;
V_71 ++ ;
V_70 = V_70 -> V_46 ;
}
for ( V_22 = 0 ; V_22 < V_69 ; V_22 ++ )
{
if ( ( V_22 == 0 ) ||
! ( V_72 [ V_22 ] . V_29 & V_48 ) )
{
* V_71 = ( T_5 * ) ( V_72 + V_22 ) ;
V_71 ++ ;
}
}
* V_71 = NULL ;
}
static void F_16 ( unsigned long V_29 , unsigned long V_48 ,
unsigned long V_73 , unsigned long V_74 ,
int V_75 , int V_76 , T_6 * V_61 ,
T_6 * * V_62 , T_6 * * V_63 )
{
T_6 * V_43 , * V_45 , * V_44 , * V_77 , * V_78 ;
T_5 * V_79 ;
unsigned long V_80 , V_81 ;
#ifdef F_17
printf ( L_1 ,
V_75 , V_29 , V_48 , V_73 , V_74 ,
V_76 ) ;
#endif
V_44 = V_43 = * V_62 ;
V_77 = V_43 ;
V_78 = V_45 = * V_63 ;
for (; ; )
{
if ( ( V_44 == NULL ) || ( V_44 == V_78 ) ) break;
V_44 = V_77 ;
V_77 = V_44 -> V_46 ;
V_79 = V_44 -> V_24 ;
if ( V_76 == - 1 )
{
V_80 = V_48 & V_79 -> V_29 ;
V_81 = V_74 & V_79 -> V_73 ;
#ifdef F_17
printf ( L_2 , V_79 -> V_82 , V_79 -> V_29 , V_79 -> V_73 , V_48 , V_74 ) ;
printf ( L_3 , V_80 , V_81 , V_80 & V_29 , V_81 & V_73 ) ;
#endif
if ( ( ( V_80 == 0 ) && ( V_81 == 0 ) ) ||
( ( V_80 & V_29 ) != V_80 ) ||
( ( V_81 & V_73 ) != V_81 ) )
continue;
}
else if ( V_76 != V_79 -> V_76 )
continue;
#ifdef F_17
printf ( L_4 , V_75 ) ;
#endif
if ( V_75 == V_83 )
{
if ( ! V_44 -> V_67 )
{
F_8 ( & V_43 , V_44 , & V_45 ) ;
V_44 -> V_67 = 1 ;
}
}
else if ( V_75 == V_84 )
{
if ( V_44 -> V_67 )
{
F_8 ( & V_43 , V_44 , & V_45 ) ;
}
}
else if ( V_75 == V_85 )
V_44 -> V_67 = 0 ;
else if ( V_75 == V_86 )
{
if ( V_43 == V_44 )
V_43 = V_44 -> V_46 ;
else
V_44 -> V_47 -> V_46 = V_44 -> V_46 ;
if ( V_45 == V_44 )
V_45 = V_44 -> V_47 ;
V_44 -> V_67 = 0 ;
if ( V_44 -> V_46 != NULL )
V_44 -> V_46 -> V_47 = V_44 -> V_47 ;
if ( V_44 -> V_47 != NULL )
V_44 -> V_47 -> V_46 = V_44 -> V_46 ;
V_44 -> V_46 = NULL ;
V_44 -> V_47 = NULL ;
}
}
* V_62 = V_43 ;
* V_63 = V_45 ;
}
static int F_18 ( T_6 * V_61 , T_6 * * V_62 ,
T_6 * * V_63 )
{
int V_87 , V_22 , * V_88 ;
T_6 * V_44 ;
V_87 = 0 ;
V_44 = * V_62 ;
while ( V_44 != NULL )
{
if ( V_44 -> V_67 &&
( V_44 -> V_24 -> V_76 > V_87 ) )
V_87 = V_44 -> V_24 -> V_76 ;
V_44 = V_44 -> V_46 ;
}
V_88 = Malloc ( ( V_87 + 1 ) * sizeof( int ) ) ;
if ( ! V_88 )
{
F_19 ( V_89 , V_90 ) ;
return ( 0 ) ;
}
memset ( V_88 , 0 , ( V_87 + 1 ) * sizeof( int ) ) ;
V_44 = * V_62 ;
while ( V_44 != NULL )
{
if ( V_44 -> V_67 )
V_88 [ V_44 -> V_24 -> V_76 ] ++ ;
V_44 = V_44 -> V_46 ;
}
for ( V_22 = V_87 ; V_22 >= 0 ; V_22 -- )
if ( V_88 [ V_22 ] > 0 )
F_16 ( 0 , 0 , 0 , 0 , V_84 , V_22 ,
V_61 , V_62 , V_63 ) ;
Free ( V_88 ) ;
return ( 1 ) ;
}
static int F_20 ( const char * V_91 ,
T_6 * V_61 , T_6 * * V_62 ,
T_6 * * V_63 , T_5 * * V_68 )
{
unsigned long V_29 , V_48 , V_73 , V_74 ;
const char * V_92 , * V_93 , * V_94 ;
int V_95 , V_96 , V_97 , V_75 , V_98 , V_99 , V_100 ;
char V_101 ;
V_98 = 1 ;
V_92 = V_91 ;
for (; ; )
{
V_101 = * V_92 ;
if ( V_101 == '\0' )
break;
if ( V_101 == '-' )
{ V_75 = V_85 ; V_92 ++ ; }
else if ( V_101 == '+' )
{ V_75 = V_84 ; V_92 ++ ; }
else if ( V_101 == '!' )
{ V_75 = V_86 ; V_92 ++ ; }
else if ( V_101 == '@' )
{ V_75 = V_102 ; V_92 ++ ; }
else
{ V_75 = V_83 ; }
if ( F_21 ( V_101 ) )
{
V_92 ++ ;
continue;
}
V_29 = V_48 = V_73 = V_74 = 0 ;
V_93 = V_92 ;
for (; ; )
{
V_101 = * V_92 ;
V_94 = V_92 ;
V_100 = 0 ;
#ifndef F_22
while ( ( ( V_101 >= 'A' ) && ( V_101 <= 'Z' ) ) ||
( ( V_101 >= '0' ) && ( V_101 <= '9' ) ) ||
( ( V_101 >= 'a' ) && ( V_101 <= 'z' ) ) ||
( V_101 == '-' ) )
#else
while ( isalnum ( V_101 ) || ( V_101 == '-' ) )
#endif
{
V_101 = * ( ++ V_92 ) ;
V_100 ++ ;
}
if ( V_100 == 0 )
{
F_19 ( V_103 ,
V_104 ) ;
V_98 = V_97 = 0 ;
V_92 ++ ;
break;
}
if ( V_75 == V_102 )
{
break;
}
if ( V_101 == '+' )
{
V_96 = 1 ;
V_92 ++ ;
}
else
V_96 = 0 ;
V_95 = V_97 = 0 ;
while ( V_68 [ V_95 ] )
{
if ( ( V_68 [ V_95 ] -> V_82 [ V_100 ] == '\0' ) &&
! strncmp ( V_94 , V_68 [ V_95 ] -> V_82 , V_100 ) )
{
V_97 = 1 ;
break;
}
else
V_95 ++ ;
}
if ( ! V_97 )
break;
V_29 |= V_68 [ V_95 ] -> V_29 ;
V_48 |= V_68 [ V_95 ] -> V_48 ;
V_73 |= V_68 [ V_95 ] -> V_73 ;
V_74 |= V_68 [ V_95 ] -> V_74 ;
if ( ! V_96 ) break;
}
if ( V_75 == V_102 )
{
V_99 = 0 ;
if ( ( V_100 == 8 ) &&
! strncmp ( V_94 , L_5 , 8 ) )
V_99 = F_18 ( V_61 ,
V_62 , V_63 ) ;
else
F_19 ( V_103 ,
V_104 ) ;
if ( V_99 == 0 )
V_98 = 0 ;
while ( ( * V_92 != '\0' ) && F_21 ( * V_92 ) )
V_92 ++ ;
}
else if ( V_97 )
{
F_16 ( V_29 , V_48 ,
V_73 , V_74 , V_75 , - 1 ,
V_61 , V_62 , V_63 ) ;
}
else
{
while ( ( * V_92 != '\0' ) && F_21 ( * V_92 ) )
V_92 ++ ;
}
if ( * V_92 == '\0' ) break;
}
return ( V_98 ) ;
}
char * F_23 ( T_5 * V_23 )
{
if ( V_23 != NULL )
return ( V_23 -> V_82 ) ;
return ( L_6 ) ;
}
int F_24 ( T_5 * V_23 , int * V_105 )
{
int V_106 = 0 ;
if ( V_23 != NULL )
{
if ( V_105 != NULL ) * V_105 = V_23 -> V_105 ;
V_106 = V_23 -> V_76 ;
}
return ( V_106 ) ;
}
static int F_25 ( T_4 * * V_107 , T_4 * * V_108 )
{
return ( ( * V_107 ) -> V_28 - ( * V_108 ) -> V_28 ) ;
}
int F_26 ( int V_28 , T_8 * V_109 )
{
T_4 * V_21 ;
F_27 ( T_4 ) * V_110 ;
V_21 = ( T_4 * ) Malloc ( sizeof( T_4 ) ) ;
V_21 -> V_28 = V_28 ;
V_21 -> V_111 = V_109 ;
if ( V_27 == NULL )
V_110 = V_27 = F_28 ( F_25 ) ;
else
V_110 = V_27 ;
if ( ( V_110 == NULL ) || ! F_29 ( V_110 , V_21 ) )
{
F_19 ( V_112 , V_90 ) ;
return ( 0 ) ;
}
else
return ( 1 ) ;
}
