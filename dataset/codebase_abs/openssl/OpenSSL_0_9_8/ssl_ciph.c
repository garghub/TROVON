static void F_1 ( void )
{
V_1 [ V_2 ] =
F_2 ( V_3 ) ;
V_1 [ V_4 ] =
F_2 ( V_5 ) ;
V_1 [ V_6 ] =
F_2 ( V_7 ) ;
V_1 [ V_8 ] =
F_2 ( V_9 ) ;
#ifndef F_3
V_1 [ V_10 ] =
F_2 ( V_11 ) ;
#else
V_1 [ V_10 ] = NULL ;
#endif
V_1 [ V_12 ] =
F_2 ( V_13 ) ;
V_1 [ V_14 ] =
F_2 ( V_15 ) ;
V_16 [ V_17 ] =
F_4 ( V_18 ) ;
V_16 [ V_19 ] =
F_4 ( V_20 ) ;
V_21 = 0 ;
}
static int F_5 ( const T_1 * const * V_22 ,
const T_1 * const * V_23 )
{
return ( ( * V_22 ) -> V_24 - ( * V_23 ) -> V_24 ) ;
}
static void F_6 ( void )
{
if ( V_25 != NULL )
return;
F_7 ( V_26 ) ;
if ( V_25 == NULL )
{
T_1 * V_27 = NULL ;
F_8 () ;
V_25 = F_9 ( F_5 ) ;
if ( V_25 != NULL )
{
V_27 = ( T_1 * ) F_10 ( sizeof( T_1 ) ) ;
if ( V_27 != NULL )
{
V_27 -> V_28 = F_11 () ;
if ( V_27 -> V_28
&& V_27 -> V_28 -> type == V_29 )
F_12 ( V_27 ) ;
else
{
V_27 -> V_24 = V_30 ;
V_27 -> V_31 = V_27 -> V_28 -> V_31 ;
F_13 ( V_25 , V_27 ) ;
}
}
}
F_14 () ;
}
F_15 ( V_26 ) ;
}
int F_16 ( const T_2 * V_32 , const T_3 * * V_33 ,
const T_4 * * V_34 , T_1 * * V_27 )
{
int V_35 ;
T_5 * V_36 ;
V_36 = V_32 -> V_37 ;
if ( V_36 == NULL ) return ( 0 ) ;
if ( V_27 != NULL )
{
T_1 V_38 ;
F_6 () ;
* V_27 = NULL ;
V_38 . V_24 = V_32 -> V_39 ;
if ( V_25 != NULL )
{
V_35 = F_17 ( V_25 , & V_38 ) ;
if ( V_35 >= 0 )
* V_27 = F_18 ( V_25 , V_35 ) ;
else
* V_27 = NULL ;
}
}
if ( ( V_33 == NULL ) || ( V_34 == NULL ) ) return ( 0 ) ;
switch ( V_36 -> V_40 & V_41 )
{
case V_42 :
V_35 = V_2 ;
break;
case V_43 :
V_35 = V_4 ;
break;
case V_44 :
V_35 = V_6 ;
break;
case V_45 :
V_35 = V_8 ;
break;
case V_46 :
V_35 = V_10 ;
break;
case V_47 :
V_35 = V_48 ;
break;
case V_49 :
switch( V_36 -> V_50 )
{
case 128 : V_35 = V_12 ; break;
case 256 : V_35 = V_14 ; break;
default: V_35 = - 1 ; break;
}
break;
default:
V_35 = - 1 ;
break;
}
if ( ( V_35 < 0 ) || ( V_35 > V_51 ) )
* V_33 = NULL ;
else
{
if ( V_35 == V_48 )
* V_33 = F_19 () ;
else
* V_33 = V_1 [ V_35 ] ;
}
switch ( V_36 -> V_40 & V_52 )
{
case V_53 :
V_35 = V_17 ;
break;
case V_54 :
V_35 = V_19 ;
break;
default:
V_35 = - 1 ;
break;
}
if ( ( V_35 < 0 ) || ( V_35 > V_55 ) )
* V_34 = NULL ;
else
* V_34 = V_16 [ V_35 ] ;
if ( ( * V_33 != NULL ) && ( * V_34 != NULL ) )
return ( 1 ) ;
else
return ( 0 ) ;
}
static void F_20 ( T_6 * * V_56 , T_6 * V_57 ,
T_6 * * V_58 )
{
if ( V_57 == * V_58 ) return;
if ( V_57 == * V_56 )
* V_56 = V_57 -> V_59 ;
if ( V_57 -> V_60 != NULL )
V_57 -> V_60 -> V_59 = V_57 -> V_59 ;
if ( V_57 -> V_59 != NULL )
V_57 -> V_59 -> V_60 = V_57 -> V_60 ;
( * V_58 ) -> V_59 = V_57 ;
V_57 -> V_60 = * V_58 ;
V_57 -> V_59 = NULL ;
* V_58 = V_57 ;
}
static unsigned long F_21 ( void )
{
unsigned long V_61 ;
V_61 = V_62 ;
#ifdef F_22
V_61 |= V_63 | V_64 ;
#endif
#ifdef F_23
V_61 |= V_65 ;
#endif
#ifdef F_24
V_61 |= V_66 | V_67 | V_68 | V_69 ;
#endif
#ifdef F_25
V_61 |= V_70 | V_71 ;
#endif
#ifdef F_26
V_61 |= V_72 | V_73 ;
#endif
#ifdef F_27
V_61 |= V_47 ;
#endif
V_61 |= ( V_1 [ V_2 ] == NULL ) ? V_42 : 0 ;
V_61 |= ( V_1 [ V_4 ] == NULL ) ? V_43 : 0 ;
V_61 |= ( V_1 [ V_6 ] == NULL ) ? V_44 : 0 ;
V_61 |= ( V_1 [ V_8 ] == NULL ) ? V_45 : 0 ;
V_61 |= ( V_1 [ V_10 ] == NULL ) ? V_46 : 0 ;
V_61 |= ( V_1 [ V_74 ] == NULL ) ? V_75 : 0 ;
V_61 |= ( V_1 [ V_12 ] == NULL ) ? V_49 : 0 ;
V_61 |= ( V_16 [ V_17 ] == NULL ) ? V_53 : 0 ;
V_61 |= ( V_16 [ V_19 ] == NULL ) ? V_54 : 0 ;
return ( V_61 ) ;
}
static void F_28 ( const T_7 * V_76 ,
int V_77 , unsigned long V_61 , T_6 * V_78 ,
T_6 * * V_79 , T_6 * * V_80 )
{
int V_35 , V_81 ;
T_5 * V_36 ;
V_81 = 0 ;
for ( V_35 = 0 ; V_35 < V_77 ; V_35 ++ )
{
V_36 = V_76 -> V_82 ( V_35 ) ;
if ( ( V_36 != NULL ) && V_36 -> V_83 && ! ( V_36 -> V_40 & V_61 ) )
{
V_78 [ V_81 ] . V_37 = V_36 ;
V_78 [ V_81 ] . V_59 = NULL ;
V_78 [ V_81 ] . V_60 = NULL ;
V_78 [ V_81 ] . V_84 = 0 ;
V_81 ++ ;
#ifdef F_29
printf ( L_1 , V_35 , V_36 -> V_31 , V_36 -> V_24 , V_36 -> V_40 ) ;
#endif
}
}
for ( V_35 = 1 ; V_35 < V_81 - 1 ; V_35 ++ )
{
V_78 [ V_35 ] . V_60 = & ( V_78 [ V_35 - 1 ] ) ;
V_78 [ V_35 ] . V_59 = & ( V_78 [ V_35 + 1 ] ) ;
}
if ( V_81 > 0 )
{
( * V_79 ) = & ( V_78 [ 0 ] ) ;
( * V_79 ) -> V_60 = NULL ;
( * V_79 ) -> V_59 = & ( V_78 [ 1 ] ) ;
( * V_80 ) = & ( V_78 [ V_81 - 1 ] ) ;
( * V_80 ) -> V_60 = & ( V_78 [ V_81 - 2 ] ) ;
( * V_80 ) -> V_59 = NULL ;
}
}
static void F_30 ( T_5 * * V_85 ,
int V_86 , unsigned long V_61 ,
T_6 * V_56 )
{
T_6 * V_87 ;
T_5 * * V_88 ;
int V_35 ;
V_87 = V_56 ;
V_88 = V_85 ;
while ( V_87 != NULL )
{
* V_88 = V_87 -> V_37 ;
V_88 ++ ;
V_87 = V_87 -> V_59 ;
}
for ( V_35 = 0 ; V_35 < V_86 ; V_35 ++ )
{
if ( ( V_35 == 0 ) ||
! ( V_89 [ V_35 ] . V_40 & V_61 ) )
{
* V_88 = ( T_5 * ) ( V_89 + V_35 ) ;
V_88 ++ ;
}
}
* V_88 = NULL ;
}
static void F_31 ( unsigned long V_40 , unsigned long V_61 ,
unsigned long V_90 , unsigned long V_91 ,
int V_92 , int V_93 , T_6 * V_78 ,
T_6 * * V_79 , T_6 * * V_80 )
{
T_6 * V_56 , * V_58 , * V_57 , * V_94 , * V_95 ;
T_5 * V_96 ;
unsigned long V_97 , V_98 ;
#ifdef F_32
printf ( L_2 ,
V_92 , V_40 , V_61 , V_90 , V_91 ,
V_93 ) ;
#endif
V_57 = V_56 = * V_79 ;
V_94 = V_56 ;
V_95 = V_58 = * V_80 ;
for (; ; )
{
if ( ( V_57 == NULL ) || ( V_57 == V_95 ) ) break;
V_57 = V_94 ;
V_94 = V_57 -> V_59 ;
V_96 = V_57 -> V_37 ;
if ( V_93 == - 1 )
{
V_97 = V_61 & V_96 -> V_40 ;
V_98 = V_91 & V_96 -> V_90 ;
#ifdef F_32
printf ( L_3 , V_96 -> V_31 , V_96 -> V_40 , V_96 -> V_90 , V_61 , V_91 ) ;
printf ( L_4 , V_97 , V_98 , V_97 & V_40 , V_98 & V_90 ) ;
#endif
if ( ( ( V_97 == 0 ) && ( V_98 == 0 ) ) ||
( ( V_97 & V_40 ) != V_97 ) ||
( ( V_98 & V_90 ) != V_98 ) )
continue;
}
else if ( V_93 != V_96 -> V_93 )
continue;
#ifdef F_32
printf ( L_5 , V_92 ) ;
#endif
if ( V_92 == V_99 )
{
if ( ! V_57 -> V_84 )
{
F_20 ( & V_56 , V_57 , & V_58 ) ;
V_57 -> V_84 = 1 ;
}
}
else if ( V_92 == V_100 )
{
if ( V_57 -> V_84 )
{
F_20 ( & V_56 , V_57 , & V_58 ) ;
}
}
else if ( V_92 == V_101 )
V_57 -> V_84 = 0 ;
else if ( V_92 == V_102 )
{
if ( V_56 == V_57 )
V_56 = V_57 -> V_59 ;
else
V_57 -> V_60 -> V_59 = V_57 -> V_59 ;
if ( V_58 == V_57 )
V_58 = V_57 -> V_60 ;
V_57 -> V_84 = 0 ;
if ( V_57 -> V_59 != NULL )
V_57 -> V_59 -> V_60 = V_57 -> V_60 ;
if ( V_57 -> V_60 != NULL )
V_57 -> V_60 -> V_59 = V_57 -> V_59 ;
V_57 -> V_59 = NULL ;
V_57 -> V_60 = NULL ;
}
}
* V_79 = V_56 ;
* V_80 = V_58 ;
}
static int F_33 ( T_6 * V_78 ,
T_6 * * V_79 ,
T_6 * * V_80 )
{
int V_103 , V_35 , * V_104 ;
T_6 * V_57 ;
V_103 = 0 ;
V_57 = * V_79 ;
while ( V_57 != NULL )
{
if ( V_57 -> V_84 &&
( V_57 -> V_37 -> V_93 > V_103 ) )
V_103 = V_57 -> V_37 -> V_93 ;
V_57 = V_57 -> V_59 ;
}
V_104 = F_10 ( ( V_103 + 1 ) * sizeof( int ) ) ;
if ( ! V_104 )
{
F_34 ( V_105 , V_106 ) ;
return ( 0 ) ;
}
memset ( V_104 , 0 , ( V_103 + 1 ) * sizeof( int ) ) ;
V_57 = * V_79 ;
while ( V_57 != NULL )
{
if ( V_57 -> V_84 )
V_104 [ V_57 -> V_37 -> V_93 ] ++ ;
V_57 = V_57 -> V_59 ;
}
for ( V_35 = V_103 ; V_35 >= 0 ; V_35 -- )
if ( V_104 [ V_35 ] > 0 )
F_31 ( 0 , 0 , 0 , 0 , V_100 , V_35 ,
V_78 , V_79 , V_80 ) ;
F_12 ( V_104 ) ;
return ( 1 ) ;
}
static int F_35 ( const char * V_107 ,
T_6 * V_78 , T_6 * * V_79 ,
T_6 * * V_80 , T_5 * * V_85 )
{
unsigned long V_40 , V_61 , V_90 , V_91 ;
const char * V_108 , * V_109 , * V_110 ;
int V_111 , V_112 , V_113 , V_92 , V_114 , V_115 , V_116 ;
char V_117 ;
V_114 = 1 ;
V_108 = V_107 ;
for (; ; )
{
V_117 = * V_108 ;
if ( V_117 == '\0' )
break;
if ( V_117 == '-' )
{ V_92 = V_101 ; V_108 ++ ; }
else if ( V_117 == '+' )
{ V_92 = V_100 ; V_108 ++ ; }
else if ( V_117 == '!' )
{ V_92 = V_102 ; V_108 ++ ; }
else if ( V_117 == '@' )
{ V_92 = V_118 ; V_108 ++ ; }
else
{ V_92 = V_99 ; }
if ( F_36 ( V_117 ) )
{
V_108 ++ ;
continue;
}
V_40 = V_61 = V_90 = V_91 = 0 ;
V_109 = V_108 ;
for (; ; )
{
V_117 = * V_108 ;
V_110 = V_108 ;
V_116 = 0 ;
#ifndef F_37
while ( ( ( V_117 >= 'A' ) && ( V_117 <= 'Z' ) ) ||
( ( V_117 >= '0' ) && ( V_117 <= '9' ) ) ||
( ( V_117 >= 'a' ) && ( V_117 <= 'z' ) ) ||
( V_117 == '-' ) )
#else
while ( isalnum ( V_117 ) || ( V_117 == '-' ) )
#endif
{
V_117 = * ( ++ V_108 ) ;
V_116 ++ ;
}
if ( V_116 == 0 )
{
F_34 ( V_119 ,
V_120 ) ;
V_114 = V_113 = 0 ;
V_108 ++ ;
break;
}
if ( V_92 == V_118 )
{
V_113 = 0 ;
break;
}
if ( V_117 == '+' )
{
V_112 = 1 ;
V_108 ++ ;
}
else
V_112 = 0 ;
V_111 = V_113 = 0 ;
while ( V_85 [ V_111 ] )
{
if ( ! strncmp ( V_110 , V_85 [ V_111 ] -> V_31 , V_116 ) &&
( V_85 [ V_111 ] -> V_31 [ V_116 ] == '\0' ) )
{
V_113 = 1 ;
break;
}
else
V_111 ++ ;
}
if ( ! V_113 )
break;
V_40 = ( V_40 & ~ V_85 [ V_111 ] -> V_61 ) |
( V_85 [ V_111 ] -> V_40 & ~ V_61 ) |
( V_40 & V_85 [ V_111 ] -> V_40 ) ;
V_61 |= V_85 [ V_111 ] -> V_61 ;
V_90 = ( V_90 & ~ V_85 [ V_111 ] -> V_91 ) |
( V_85 [ V_111 ] -> V_90 & ~ V_91 ) |
( V_90 & V_85 [ V_111 ] -> V_90 ) ;
V_91 |= V_85 [ V_111 ] -> V_91 ;
if ( ! V_112 ) break;
}
if ( V_92 == V_118 )
{
V_115 = 0 ;
if ( ( V_116 == 8 ) &&
! strncmp ( V_110 , L_6 , 8 ) )
V_115 = F_33 ( V_78 ,
V_79 , V_80 ) ;
else
F_34 ( V_119 ,
V_120 ) ;
if ( V_115 == 0 )
V_114 = 0 ;
while ( ( * V_108 != '\0' ) && F_36 ( * V_108 ) )
V_108 ++ ;
}
else if ( V_113 )
{
F_31 ( V_40 , V_61 ,
V_90 , V_91 , V_92 , - 1 ,
V_78 , V_79 , V_80 ) ;
}
else
{
while ( ( * V_108 != '\0' ) && F_36 ( * V_108 ) )
V_108 ++ ;
}
if ( * V_108 == '\0' ) break;
}
return ( V_114 ) ;
}
