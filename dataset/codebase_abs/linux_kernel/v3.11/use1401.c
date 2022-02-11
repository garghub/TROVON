static short F_1 ( short V_1 )
{
if ( ( V_1 < 0 ) || ( V_1 >= V_2 ) )
return V_3 ;
if ( V_4 [ V_1 ] <= 0 )
return V_3 ;
return V_5 ;
}
static short F_2 ( short V_6 , LONG V_7 , T_1 * V_8 )
{
unsigned int V_9 = 0 ;
if ( ( V_6 < 0 ) || ( V_6 >= V_2 ) )
return V_3 ;
#ifndef F_3
if ( ! F_4 ( V_6 ) )
{
if ( F_5 ( V_4 [ V_6 ] , V_7 , NULL , 0 , V_8 , sizeof( T_1 ) , & V_9 , NULL ) )
return ( short ) ( ( V_9 >= sizeof( T_1 ) ) ? V_5 : V_10 ) ;
else
return ( short ) F_6 () ;
}
else
#endif
{
T_2 V_11 ;
V_11 . V_12 = V_10 ;
if ( F_5 ( V_4 [ V_6 ] , V_7 , NULL , 0 , & V_11 , sizeof( T_2 ) , & V_9 , NULL ) &&
( V_9 >= sizeof( T_2 ) ) )
{
* V_8 = V_11 . V_13 ;
return V_11 . V_12 ;
}
}
return V_10 ;
}
static short F_7 ( short V_6 , LONG V_7 , T_1 * V_8 )
{
unsigned int V_9 = 0 ;
if ( ( V_6 < 0 ) || ( V_6 >= V_2 ) )
return V_3 ;
#ifndef F_3
if ( ! F_4 ( V_6 ) )
{
if ( F_5 ( V_4 [ V_6 ] , V_7 , NULL , 0 , V_8 , sizeof( T_1 ) , & V_9 , NULL ) )
return ( short ) ( V_9 >= sizeof( T_1 ) ? V_5 : V_10 ) ;
else
return ( short ) F_6 () ;
}
else
#endif
{
T_2 V_11 ;
V_11 . V_12 = V_10 ;
if ( F_5 ( V_4 [ V_6 ] , V_7 , V_8 , sizeof( T_1 ) , & V_11 , sizeof( T_2 ) , & V_9 , NULL ) &&
( V_9 >= sizeof( T_2 ) ) )
return V_11 . V_12 ;
}
return V_10 ;
}
static long F_8 ()
{
#ifdef F_9
return F_10 () ;
#endif
#ifdef F_11
struct V_14 V_15 ;
F_12 ( & V_15 , NULL ) ;
return ( V_15 . V_16 * 1000 + V_15 . V_17 / 1000 ) ;
#endif
}
static int F_13 ( short V_18 , char * V_19 )
{
V_19 [ 0 ] = 0 ;
switch ( V_18 )
{
case V_20 : strcpy ( V_19 , L_1 ) ; break;
case V_21 : strcpy ( V_19 , L_2 ) ; break;
default:
strcpy ( V_19 , L_3 ) ;
V_19 [ 3 ] = ( char ) ( 'M' + V_18 - V_22 ) ;
if ( V_19 [ 3 ] > 'Z' )
V_19 [ 3 ] = ( char ) ( V_19 [ 3 ] - 26 ) ;
}
return 0 ;
}
static void F_14 ( char * V_23 )
{
int V_24 = 0 ;
while ( V_23 [ V_24 ] )
{
if ( V_23 [ V_24 ] == ',' )
V_23 [ V_24 ] = ' ' ;
++ V_24 ;
}
if ( ( V_24 > 0 ) && ( V_23 [ V_24 - 1 ] == '\n' ) )
V_23 [ V_24 - 1 ] = ( char ) 0 ;
}
static int F_15 ( short V_25 )
{
#ifdef F_9
T_1 V_13 ;
int V_26 = F_2 ( V_25 , V_27 , & V_13 ) ;
if ( V_26 == V_5 )
V_26 = V_13 . V_28 [ 0 ] ;
return V_26 ;
#endif
#ifdef F_11
return F_16 ( V_4 [ V_25 ] ) ;
#endif
}
static short F_17 ( int V_29 , long * V_30 , short * V_31 )
{
short V_32 = V_5 ;
T_3 V_33 = V_34 ;
unsigned int V_35 = 0 ;
int V_36 , V_37 , V_38 = 0 ;
BOOL V_39 = FALSE ;
if ( V_29 == 0 )
{
V_36 = 1 ;
V_37 = V_2 ;
}
else
V_36 = V_37 = V_29 ;
while ( V_33 == V_34 )
{
for ( V_38 = V_36 ; V_38 <= V_37 ; V_38 ++ )
{
char V_40 [ 40 ] ;
sprintf ( V_40 , V_39 ? V_41 : V_42 , V_38 ) ;
V_33 = F_18 ( V_40 , V_43 | V_44 ,
0 , 0 ,
V_45 , V_46 , NULL ) ;
if ( V_33 != V_34 )
{
T_1 V_13 ;
assert ( V_4 [ V_38 - 1 ] == V_34 ) ;
V_4 [ V_38 - 1 ] = V_33 ;
#ifndef F_3
V_47 [ V_38 - 1 ] = ( BOOL ) ( ! V_48 || ! V_39 ) ;
#endif
V_32 = F_2 ( ( short ) ( V_38 - 1 ) , V_49 , & V_13 ) ;
if ( V_32 == V_5 )
{
* V_30 = V_13 . V_50 [ 0 ] ;
if ( V_13 . V_50 [ 0 ] == V_51 )
{
F_19 ( V_33 ) ;
V_33 = V_34 ;
V_4 [ V_38 - 1 ] = V_34 ;
V_32 = V_51 ;
}
else
break;
}
else
{
F_19 ( V_33 ) ;
V_33 = V_34 ;
V_4 [ V_38 - 1 ] = V_34 ;
}
}
else
{
unsigned int V_52 = F_6 () ;
if ( ( V_52 != V_53 ) || ( V_35 == 0 ) )
V_35 = V_52 ;
}
}
if ( ( V_33 == V_34 ) &&
( V_48 ) &&
( V_39 == FALSE ) )
V_39 = TRUE ;
else
break;
}
if ( V_33 != V_34 )
* V_31 = ( short ) ( V_38 - 1 ) ;
else
{
if ( V_35 == V_53 )
V_32 = V_54 ;
else if ( V_35 == V_55 )
V_32 = V_56 ;
else if ( V_35 == V_57 )
V_32 = V_51 ;
else
V_32 = V_10 ;
}
return V_32 ;
}
static short F_17 ( int V_29 , long * V_30 , short * V_31 )
{
short V_32 = V_5 ;
int V_58 = 0 ;
int V_26 = 0 ;
int V_36 , V_37 , V_38 = 0 ;
if ( V_29 == 0 )
{
V_36 = 1 ;
V_37 = V_2 ;
}
else
V_36 = V_37 = V_29 ;
for ( V_38 = V_36 ; V_38 <= V_37 ; V_38 ++ )
{
char V_40 [ 40 ] ;
sprintf ( V_40 , L_4 , V_38 - 1 ) ;
V_58 = F_20 ( V_40 , V_59 ) ;
if ( V_58 > 0 )
{
int V_60 = F_21 ( V_58 ) ;
V_4 [ V_38 - 1 ] = V_58 ;
if ( V_60 >= 0 )
{
* V_30 = V_60 ;
break;
}
else
{
F_22 ( V_58 ) ;
V_58 = 0 ;
V_4 [ V_38 - 1 ] = 0 ;
}
}
else
{
if ( ( ( V_61 != V_62 ) && ( V_61 != V_63 ) ) || ( V_26 == 0 ) )
V_26 = V_61 ;
}
}
if ( V_58 )
* V_31 = ( short ) ( V_38 - 1 ) ;
else
{
if ( ( V_26 == V_62 ) || ( V_26 == V_63 ) )
V_32 = V_54 ;
else if ( V_26 == V_64 )
V_32 = V_51 ;
else
V_32 = V_10 ;
}
return V_32 ;
}
static short F_23 ( short V_25 , BOOL V_65 , char * V_66 ,
unsigned int V_67 , unsigned int V_68 , short V_69 )
{
char V_70 [ V_71 + 1 ] ;
short V_72 = F_24 ( V_25 , 0 , ( void * ) V_66 , V_67 , V_69 ) ;
if ( V_72 == V_5 )
{
sprintf ( V_70 ,
L_5 , V_65 ? L_6 : L_7 , V_68 , V_67 ) ;
F_25 ( V_25 , V_70 ) ;
V_72 = F_26 ( V_25 ) ;
if ( V_72 > 0 )
V_72 = V_73 ;
F_27 ( V_25 , 0 ) ;
}
return V_72 ;
}
static unsigned int F_28 ( void * V_74 , char * V_75 , int V_76 )
{
char V_77 [ 32 ] ;
sprintf ( V_77 , L_8 , F_29 () ) ;
if ( F_30 ( V_77 , V_75 , V_76 ) != - 1 )
{
F_31 ( V_75 ) ;
strcat ( V_75 , L_9 ) ;
return strlen ( V_75 ) ;
}
return 0 ;
}
INT T_4 F_32 ( T_3 V_78 , unsigned int V_79 , T_5 V_80 )
{
int V_81 = 1 ;
switch ( V_79 )
{
case V_82 :
V_81 = F_33 () > 0 ;
++ V_83 ;
break;
case V_84 :
if ( -- V_83 == 0 )
F_34 () ;
break;
}
return V_81 ;
F_35 ( V_80 ) ;
}
