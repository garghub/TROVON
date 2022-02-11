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
V_2 [ V_13 ] =
F_2 ( V_14 ) ;
V_2 [ V_15 ] =
F_2 ( V_16 ) ;
V_17 [ V_18 ] =
F_3 ( V_19 ) ;
V_17 [ V_20 ] =
F_3 ( V_21 ) ;
}
int F_4 ( T_1 * V_22 , const T_2 * * V_23 ,
const T_3 * * V_24 , T_4 * * V_25 )
{
int V_26 ;
T_5 * V_27 ;
V_27 = V_22 -> V_28 ;
if ( V_27 == NULL ) return ( 0 ) ;
if ( V_25 != NULL )
{
T_4 V_29 ;
if ( V_22 -> V_30 == 0 )
* V_25 = NULL ;
else if ( V_31 == NULL )
{
* V_25 = NULL ;
}
else
{
V_29 . V_32 = V_22 -> V_30 ;
V_26 = F_5 ( V_31 , & V_29 ) ;
if ( V_26 >= 0 )
* V_25 = F_6 ( V_31 , V_26 ) ;
else
* V_25 = NULL ;
}
}
if ( ( V_23 == NULL ) || ( V_24 == NULL ) ) return ( 0 ) ;
switch ( V_27 -> V_33 & V_34 )
{
case V_35 :
V_26 = V_3 ;
break;
case V_36 :
V_26 = V_5 ;
break;
case V_37 :
V_26 = V_7 ;
break;
case V_38 :
V_26 = V_9 ;
break;
case V_39 :
V_26 = V_11 ;
break;
case V_40 :
V_26 = V_41 ;
break;
case V_42 :
switch( V_27 -> V_43 )
{
case 128 : V_26 = V_13 ; break;
case 256 : V_26 = V_15 ; break;
default: V_26 = - 1 ; break;
}
break;
default:
V_26 = - 1 ;
break;
}
if ( ( V_26 < 0 ) || ( V_26 > V_44 ) )
* V_23 = NULL ;
else
{
if ( V_26 == V_41 )
* V_23 = F_7 () ;
else
* V_23 = V_2 [ V_26 ] ;
}
switch ( V_27 -> V_33 & V_45 )
{
case V_46 :
V_26 = V_18 ;
break;
case V_47 :
V_26 = V_20 ;
break;
default:
V_26 = - 1 ;
break;
}
if ( ( V_26 < 0 ) || ( V_26 > V_48 ) )
* V_24 = NULL ;
else
* V_24 = V_17 [ V_26 ] ;
if ( ( * V_23 != NULL ) && ( * V_24 != NULL ) )
return ( 1 ) ;
else
return ( 0 ) ;
}
static void F_8 ( T_6 * * V_49 , T_6 * V_50 ,
T_6 * * V_51 )
{
if ( V_50 == * V_51 ) return;
if ( V_50 == * V_49 )
* V_49 = V_50 -> V_52 ;
if ( V_50 -> V_53 != NULL )
V_50 -> V_53 -> V_52 = V_50 -> V_52 ;
if ( V_50 -> V_52 != NULL )
V_50 -> V_52 -> V_53 = V_50 -> V_53 ;
( * V_51 ) -> V_52 = V_50 ;
V_50 -> V_53 = * V_51 ;
V_50 -> V_52 = NULL ;
* V_51 = V_50 ;
}
static unsigned long F_9 ( void )
{
unsigned long V_54 ;
V_54 = V_55 ;
#ifdef F_10
V_54 |= V_56 | V_57 ;
#endif
#ifdef F_11
V_54 |= V_58 ;
#endif
#ifdef F_12
V_54 |= V_59 | V_60 | V_61 | V_62 ;
#endif
#ifdef F_13
V_54 |= V_63 | V_64 ;
#endif
#ifdef F_14
V_54 |= V_40 ;
#endif
V_54 |= ( V_2 [ V_3 ] == NULL ) ? V_35 : 0 ;
V_54 |= ( V_2 [ V_5 ] == NULL ) ? V_36 : 0 ;
V_54 |= ( V_2 [ V_7 ] == NULL ) ? V_37 : 0 ;
V_54 |= ( V_2 [ V_9 ] == NULL ) ? V_38 : 0 ;
V_54 |= ( V_2 [ V_11 ] == NULL ) ? V_39 : 0 ;
V_54 |= ( V_2 [ V_65 ] == NULL ) ? V_66 : 0 ;
V_54 |= ( V_2 [ V_13 ] == NULL ) ? V_42 : 0 ;
V_54 |= ( V_17 [ V_18 ] == NULL ) ? V_46 : 0 ;
V_54 |= ( V_17 [ V_20 ] == NULL ) ? V_47 : 0 ;
return ( V_54 ) ;
}
static void F_15 ( const T_7 * V_67 ,
int V_68 , unsigned long V_54 , T_6 * V_69 ,
T_6 * * V_70 , T_6 * * V_71 )
{
int V_26 , V_72 ;
T_5 * V_27 ;
V_72 = 0 ;
for ( V_26 = 0 ; V_26 < V_68 ; V_26 ++ )
{
V_27 = V_67 -> V_73 ( V_26 ) ;
if ( ( V_27 != NULL ) && V_27 -> V_74 && ! ( V_27 -> V_33 & V_54 ) )
{
V_69 [ V_72 ] . V_28 = V_27 ;
V_69 [ V_72 ] . V_52 = NULL ;
V_69 [ V_72 ] . V_53 = NULL ;
V_69 [ V_72 ] . V_75 = 0 ;
V_72 ++ ;
#ifdef F_16
printf ( L_1 , V_26 , V_27 -> V_76 , V_27 -> V_32 , V_27 -> V_33 ) ;
#endif
}
}
for ( V_26 = 1 ; V_26 < V_72 - 1 ; V_26 ++ )
{
V_69 [ V_26 ] . V_53 = & ( V_69 [ V_26 - 1 ] ) ;
V_69 [ V_26 ] . V_52 = & ( V_69 [ V_26 + 1 ] ) ;
}
if ( V_72 > 0 )
{
( * V_70 ) = & ( V_69 [ 0 ] ) ;
( * V_70 ) -> V_53 = NULL ;
( * V_70 ) -> V_52 = & ( V_69 [ 1 ] ) ;
( * V_71 ) = & ( V_69 [ V_72 - 1 ] ) ;
( * V_71 ) -> V_53 = & ( V_69 [ V_72 - 2 ] ) ;
( * V_71 ) -> V_52 = NULL ;
}
}
static void F_17 ( T_5 * * V_77 ,
int V_78 , unsigned long V_54 ,
T_6 * V_49 )
{
T_6 * V_79 ;
T_5 * * V_80 ;
int V_26 ;
V_79 = V_49 ;
V_80 = V_77 ;
while ( V_79 != NULL )
{
* V_80 = V_79 -> V_28 ;
V_80 ++ ;
V_79 = V_79 -> V_52 ;
}
for ( V_26 = 0 ; V_26 < V_78 ; V_26 ++ )
{
if ( ( V_26 == 0 ) ||
! ( V_81 [ V_26 ] . V_33 & V_54 ) )
{
* V_80 = ( T_5 * ) ( V_81 + V_26 ) ;
V_80 ++ ;
}
}
* V_80 = NULL ;
}
static void F_18 ( unsigned long V_33 , unsigned long V_54 ,
unsigned long V_82 , unsigned long V_83 ,
int V_84 , int V_85 , T_6 * V_69 ,
T_6 * * V_70 , T_6 * * V_71 )
{
T_6 * V_49 , * V_51 , * V_50 , * V_86 , * V_87 ;
T_5 * V_88 ;
unsigned long V_89 , V_90 ;
#ifdef F_19
printf ( L_2 ,
V_84 , V_33 , V_54 , V_82 , V_83 ,
V_85 ) ;
#endif
V_50 = V_49 = * V_70 ;
V_86 = V_49 ;
V_87 = V_51 = * V_71 ;
for (; ; )
{
if ( ( V_50 == NULL ) || ( V_50 == V_87 ) ) break;
V_50 = V_86 ;
V_86 = V_50 -> V_52 ;
V_88 = V_50 -> V_28 ;
if ( V_85 == - 1 )
{
V_89 = V_54 & V_88 -> V_33 ;
V_90 = V_83 & V_88 -> V_82 ;
#ifdef F_19
printf ( L_3 , V_88 -> V_76 , V_88 -> V_33 , V_88 -> V_82 , V_54 , V_83 ) ;
printf ( L_4 , V_89 , V_90 , V_89 & V_33 , V_90 & V_82 ) ;
#endif
if ( ( ( V_89 == 0 ) && ( V_90 == 0 ) ) ||
( ( V_89 & V_33 ) != V_89 ) ||
( ( V_90 & V_82 ) != V_90 ) )
continue;
}
else if ( V_85 != V_88 -> V_85 )
continue;
#ifdef F_19
printf ( L_5 , V_84 ) ;
#endif
if ( V_84 == V_91 )
{
if ( ! V_50 -> V_75 )
{
F_8 ( & V_49 , V_50 , & V_51 ) ;
V_50 -> V_75 = 1 ;
}
}
else if ( V_84 == V_92 )
{
if ( V_50 -> V_75 )
{
F_8 ( & V_49 , V_50 , & V_51 ) ;
}
}
else if ( V_84 == V_93 )
V_50 -> V_75 = 0 ;
else if ( V_84 == V_94 )
{
if ( V_49 == V_50 )
V_49 = V_50 -> V_52 ;
else
V_50 -> V_53 -> V_52 = V_50 -> V_52 ;
if ( V_51 == V_50 )
V_51 = V_50 -> V_53 ;
V_50 -> V_75 = 0 ;
if ( V_50 -> V_52 != NULL )
V_50 -> V_52 -> V_53 = V_50 -> V_53 ;
if ( V_50 -> V_53 != NULL )
V_50 -> V_53 -> V_52 = V_50 -> V_52 ;
V_50 -> V_52 = NULL ;
V_50 -> V_53 = NULL ;
}
}
* V_70 = V_49 ;
* V_71 = V_51 ;
}
static int F_20 ( T_6 * V_69 , T_6 * * V_70 ,
T_6 * * V_71 )
{
int V_95 , V_26 , * V_96 ;
T_6 * V_50 ;
V_95 = 0 ;
V_50 = * V_70 ;
while ( V_50 != NULL )
{
if ( V_50 -> V_75 &&
( V_50 -> V_28 -> V_85 > V_95 ) )
V_95 = V_50 -> V_28 -> V_85 ;
V_50 = V_50 -> V_52 ;
}
V_96 = F_21 ( ( V_95 + 1 ) * sizeof( int ) ) ;
if ( ! V_96 )
{
F_22 ( V_97 , V_98 ) ;
return ( 0 ) ;
}
memset ( V_96 , 0 , ( V_95 + 1 ) * sizeof( int ) ) ;
V_50 = * V_70 ;
while ( V_50 != NULL )
{
if ( V_50 -> V_75 )
V_96 [ V_50 -> V_28 -> V_85 ] ++ ;
V_50 = V_50 -> V_52 ;
}
for ( V_26 = V_95 ; V_26 >= 0 ; V_26 -- )
if ( V_96 [ V_26 ] > 0 )
F_18 ( 0 , 0 , 0 , 0 , V_92 , V_26 ,
V_69 , V_70 , V_71 ) ;
F_23 ( V_96 ) ;
return ( 1 ) ;
}
static int F_24 ( const char * V_99 ,
T_6 * V_69 , T_6 * * V_70 ,
T_6 * * V_71 , T_5 * * V_77 )
{
unsigned long V_33 , V_54 , V_82 , V_83 ;
const char * V_100 , * V_101 , * V_102 ;
int V_103 , V_104 , V_105 , V_84 , V_106 , V_107 , V_108 ;
char V_109 ;
V_106 = 1 ;
V_100 = V_99 ;
for (; ; )
{
V_109 = * V_100 ;
if ( V_109 == '\0' )
break;
if ( V_109 == '-' )
{ V_84 = V_93 ; V_100 ++ ; }
else if ( V_109 == '+' )
{ V_84 = V_92 ; V_100 ++ ; }
else if ( V_109 == '!' )
{ V_84 = V_94 ; V_100 ++ ; }
else if ( V_109 == '@' )
{ V_84 = V_110 ; V_100 ++ ; }
else
{ V_84 = V_91 ; }
if ( F_25 ( V_109 ) )
{
V_100 ++ ;
continue;
}
V_33 = V_54 = V_82 = V_83 = 0 ;
V_101 = V_100 ;
for (; ; )
{
V_109 = * V_100 ;
V_102 = V_100 ;
V_108 = 0 ;
#ifndef F_26
while ( ( ( V_109 >= 'A' ) && ( V_109 <= 'Z' ) ) ||
( ( V_109 >= '0' ) && ( V_109 <= '9' ) ) ||
( ( V_109 >= 'a' ) && ( V_109 <= 'z' ) ) ||
( V_109 == '-' ) )
#else
while ( isalnum ( V_109 ) || ( V_109 == '-' ) )
#endif
{
V_109 = * ( ++ V_100 ) ;
V_108 ++ ;
}
if ( V_108 == 0 )
{
F_22 ( V_111 ,
V_112 ) ;
V_106 = V_105 = 0 ;
V_100 ++ ;
break;
}
if ( V_84 == V_110 )
{
V_105 = 0 ;
break;
}
if ( V_109 == '+' )
{
V_104 = 1 ;
V_100 ++ ;
}
else
V_104 = 0 ;
V_103 = V_105 = 0 ;
while ( V_77 [ V_103 ] )
{
if ( ( V_77 [ V_103 ] -> V_76 [ V_108 ] == '\0' ) &&
! strncmp ( V_102 , V_77 [ V_103 ] -> V_76 , V_108 ) )
{
V_105 = 1 ;
break;
}
else
V_103 ++ ;
}
if ( ! V_105 )
break;
V_33 |= V_77 [ V_103 ] -> V_33 ;
V_54 |= V_77 [ V_103 ] -> V_54 ;
V_82 |= V_77 [ V_103 ] -> V_82 ;
V_83 |= V_77 [ V_103 ] -> V_83 ;
if ( ! V_104 ) break;
}
if ( V_84 == V_110 )
{
V_107 = 0 ;
if ( ( V_108 == 8 ) &&
! strncmp ( V_102 , L_6 , 8 ) )
V_107 = F_20 ( V_69 ,
V_70 , V_71 ) ;
else
F_22 ( V_111 ,
V_112 ) ;
if ( V_107 == 0 )
V_106 = 0 ;
while ( ( * V_100 != '\0' ) && F_25 ( * V_100 ) )
V_100 ++ ;
}
else if ( V_105 )
{
F_18 ( V_33 , V_54 ,
V_82 , V_83 , V_84 , - 1 ,
V_69 , V_70 , V_71 ) ;
}
else
{
while ( ( * V_100 != '\0' ) && F_25 ( * V_100 ) )
V_100 ++ ;
}
if ( * V_100 == '\0' ) break;
}
return ( V_106 ) ;
}
