static int F_1 ( char * V_1 )
{
if ( V_1 [ 0 ] != '+' && V_1 [ 0 ] != '$' ) {
F_2 ( V_2 ) ;
F_3 ( L_1 , V_1 ) ;
} else {
int V_3 = strlen ( V_1 ) ;
if ( V_3 > 3 && V_1 [ V_3 - 3 ] == '#' ) {
F_4 ( V_1 ) ;
strcpy ( V_1 , L_2 ) ;
F_2 ( V_4 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_5 ( char * V_1 , T_1 V_5 )
{
#define F_6 1000
#define F_7 (2*1000000/ESCAPE_UDELAY)
char V_6 [ 5 ] ;
char * V_7 = V_6 ;
int V_8 = 0 ;
T_2 * V_9 , * V_10 = NULL ;
int V_11 ;
for ( V_9 = & V_12 [ 0 ] ; ; ++ V_9 ) {
if ( * V_9 == NULL ) {
F_8 () ;
V_9 = & V_12 [ 0 ] ;
}
if ( V_8 == 2 ) {
* V_7 = '\0' ;
V_7 = V_6 ;
-- V_8 ;
}
if ( V_8 == 1 ) {
V_11 = * V_7 ++ ;
if ( ! * V_7 )
-- V_8 ;
break;
}
V_11 = (* V_9)() ;
if ( V_11 == - 1 ) {
if ( V_8 ) {
F_9 ( F_6 ) ;
-- V_8 ;
}
continue;
}
if ( V_5 <= 2 ) {
if ( V_11 == '\r' )
V_11 = '\n' ;
* V_1 ++ = V_11 ;
* V_1 = '\0' ;
return - 1 ;
}
if ( V_8 == 0 && V_11 == '\e' ) {
V_8 = F_7 ;
V_7 = V_6 ;
V_10 = V_9 ;
}
if ( V_8 ) {
* V_7 ++ = V_11 ;
if ( V_10 != V_9 ) {
V_8 = 2 ;
continue;
}
if ( V_7 - V_6 == 1 ) {
continue;
} else if ( V_7 - V_6 == 2 ) {
if ( V_11 != '[' )
V_8 = 2 ;
continue;
} else if ( V_7 - V_6 == 3 ) {
int V_13 = 0 ;
switch ( V_11 ) {
case 'A' :
V_13 = 16 ;
break;
case 'B' :
V_13 = 14 ;
break;
case 'C' :
V_13 = 6 ;
break;
case 'D' :
V_13 = 2 ;
break;
case '1' :
case '3' :
case '4' :
V_13 = - 1 ;
break;
}
if ( V_13 != - 1 ) {
if ( V_13 > 0 ) {
V_6 [ 0 ] = V_13 ;
V_6 [ 1 ] = '\0' ;
}
V_8 = 2 ;
}
continue;
} else if ( V_7 - V_6 == 4 ) {
int V_13 = 0 ;
if ( V_11 == '~' ) {
switch ( V_6 [ 2 ] ) {
case '1' :
V_13 = 1 ;
break;
case '3' :
V_13 = 4 ;
break;
case '4' :
V_13 = 5 ;
break;
}
}
if ( V_13 > 0 ) {
V_6 [ 0 ] = V_13 ;
V_6 [ 1 ] = '\0' ;
}
V_8 = 2 ;
continue;
}
}
break;
}
return V_11 ;
}
static char * F_10 ( char * V_1 , T_1 V_5 )
{
char * V_14 = V_1 ;
char * V_15 = V_1 + V_5 - 2 ;
char * V_16 ;
char * V_17 ;
char V_18 ;
static char V_19 [ V_20 ] ;
int V_21 = strlen ( V_1 ) ;
int V_22 ;
int V_23 = 0 ;
int V_24 ;
int V_25 ;
int V_26 , V_27 ;
int V_11 ;
V_26 = F_11 ( L_3 , & V_27 ) ;
if ( V_26 )
V_27 = 30 ;
if ( V_21 > 0 ) {
V_14 += V_21 ;
if ( * ( V_1 + V_21 - 1 ) == '\n' )
V_14 -- ;
}
V_16 = V_14 ;
* V_14 = '\0' ;
F_3 ( L_1 , V_1 ) ;
V_28:
V_11 = F_5 ( V_1 , V_5 ) ;
if ( V_11 == - 1 )
return V_1 ;
if ( V_11 != 9 )
V_23 = 0 ;
switch ( V_11 ) {
case 8 :
if ( V_14 > V_1 ) {
if ( V_14 < V_16 ) {
memcpy ( V_19 , V_14 , V_16 - V_14 ) ;
memcpy ( V_14 - 1 , V_19 , V_16 - V_14 ) ;
}
* ( -- V_16 ) = '\0' ;
-- V_14 ;
F_3 ( L_4 , V_14 ) ;
V_18 = * V_14 ;
* V_14 = '\0' ;
F_3 ( V_29 ) ;
F_3 ( L_1 , V_1 ) ;
* V_14 = V_18 ;
}
break;
case 13 :
* V_16 ++ = '\n' ;
* V_16 ++ = '\0' ;
if ( ! F_12 ( V_2 ) ) {
F_2 ( V_2 ) ;
F_3 ( L_1 , V_1 ) ;
}
F_3 ( L_5 ) ;
return V_1 ;
case 4 :
if ( V_14 < V_16 ) {
memcpy ( V_19 , V_14 + 1 , V_16 - V_14 - 1 ) ;
memcpy ( V_14 , V_19 , V_16 - V_14 - 1 ) ;
* ( -- V_16 ) = '\0' ;
F_3 ( L_6 , V_14 ) ;
V_18 = * V_14 ;
* V_14 = '\0' ;
F_3 ( V_29 ) ;
F_3 ( L_1 , V_1 ) ;
* V_14 = V_18 ;
}
break;
case 1 :
if ( V_14 > V_1 ) {
F_3 ( L_7 ) ;
F_3 ( V_29 ) ;
V_14 = V_1 ;
}
break;
case 5 :
if ( V_14 < V_16 ) {
F_3 ( L_1 , V_14 ) ;
V_14 = V_16 ;
}
break;
case 2 :
if ( V_14 > V_1 ) {
F_3 ( L_8 ) ;
-- V_14 ;
}
break;
case 14 :
memset ( V_19 , ' ' ,
strlen ( V_29 ) + ( V_16 - V_1 ) ) ;
* ( V_19 + strlen ( V_29 ) +
( V_16 - V_1 ) ) = '\0' ;
F_3 ( L_9 , V_19 ) ;
* V_16 = ( char ) V_11 ;
* ( V_16 + 1 ) = '\0' ;
return V_16 ;
case 6 :
if ( V_14 < V_16 ) {
F_3 ( L_10 , * V_14 ) ;
++ V_14 ;
}
break;
case 16 :
memset ( V_19 , ' ' ,
strlen ( V_29 ) + ( V_16 - V_1 ) ) ;
* ( V_19 + strlen ( V_29 ) +
( V_16 - V_1 ) ) = '\0' ;
F_3 ( L_9 , V_19 ) ;
* V_16 = ( char ) V_11 ;
* ( V_16 + 1 ) = '\0' ;
return V_16 ;
case 9 :
if ( V_23 < 2 )
++ V_23 ;
V_17 = V_1 ;
while ( * V_17 == ' ' )
V_17 ++ ;
if ( V_17 > V_14 )
break;
memcpy ( V_19 , V_17 , V_14 - V_17 ) ;
* ( V_19 + ( V_14 - V_17 ) ) = '\0' ;
V_17 = strrchr ( V_19 , ' ' ) ;
if ( V_17 )
++ V_17 ;
else
V_17 = V_19 ;
V_21 = strlen ( V_17 ) ;
V_24 = F_13 ( V_17 ,
sizeof( V_19 ) -
( V_17 - V_19 ) ) ;
if ( V_23 == 2 && V_24 > 0 ) {
F_3 ( L_11 , V_24 ) ;
if ( V_24 > V_27 ) {
V_24 = V_27 ;
F_3 ( L_12
L_13
L_14 ,
V_24 ) ;
}
F_3 ( L_5 ) ;
for ( V_25 = 0 ; V_25 < V_24 ; V_25 ++ ) {
if ( F_14 ( V_17 , V_25 ) < 0 )
break;
F_3 ( L_15 , V_17 ) ;
* ( V_17 + V_21 ) = '\0' ;
}
if ( V_25 >= V_27 )
F_3 ( L_16 ) ;
F_3 ( L_5 ) ;
F_3 ( V_29 ) ;
F_3 ( L_1 , V_1 ) ;
} else if ( V_23 != 2 && V_24 > 0 ) {
V_22 = strlen ( V_17 ) ;
strncpy ( V_17 + V_22 , V_14 , V_16 - V_14 + 1 ) ;
V_22 = strlen ( V_17 ) ;
strncpy ( V_14 , V_17 + V_21 , V_22 - V_21 + 1 ) ;
V_21 = V_22 - V_21 ;
F_3 ( L_1 , V_14 ) ;
V_14 += V_21 ;
V_16 += V_21 ;
}
V_30 = 1 ;
break;
default:
if ( V_11 >= 32 && V_16 < V_15 ) {
if ( V_14 < V_16 ) {
memcpy ( V_19 , V_14 , V_16 - V_14 ) ;
memcpy ( V_14 + 1 , V_19 , V_16 - V_14 ) ;
* ++ V_16 = '\0' ;
* V_14 = V_11 ;
F_3 ( L_17 , V_14 ) ;
++ V_14 ;
V_18 = * V_14 ;
* V_14 = '\0' ;
F_3 ( V_29 ) ;
F_3 ( L_1 , V_1 ) ;
* V_14 = V_18 ;
} else {
* ++ V_16 = '\0' ;
* V_14 ++ = V_11 ;
if ( ! F_12 ( V_2 ) ) {
if ( F_1 ( V_1 ) )
return V_1 ;
} else {
F_3 ( L_10 , V_11 ) ;
}
}
if ( V_16 - V_1 >= 5 &&
strcmp ( V_16 - 5 , L_18 ) == 0 ) {
F_4 ( V_16 - 5 ) ;
strcpy ( V_1 , L_2 ) ;
F_2 ( V_4 ) ;
return V_1 ;
}
if ( V_16 - V_1 >= 11 &&
strcmp ( V_16 - 11 , L_19 ) == 0 ) {
F_4 ( V_16 - 11 ) ;
strcpy ( V_1 , L_2 ) ;
F_2 ( V_4 ) ;
return V_1 ;
}
}
break;
}
goto V_28;
}
char * F_15 ( char * V_1 , T_1 V_5 , const char * V_31 )
{
if ( V_31 && V_29 != V_31 )
strncpy ( V_29 , V_31 , V_20 ) ;
F_3 ( V_29 ) ;
V_30 = 1 ;
return F_10 ( V_1 , V_5 ) ;
}
static void F_16 ( void )
{
T_2 * V_9 ;
int V_32 ;
int V_33 = 1 ;
while ( V_33 ) {
V_33 -- ;
V_34:
F_8 () ;
for ( V_9 = & V_12 [ 0 ] ; * V_9 ; ++ V_9 ) {
V_32 = (* V_9)() ;
if ( V_32 != - 1 ) {
V_33 = 1 ;
goto V_34;
}
}
if ( V_33 )
F_17 ( 1 ) ;
}
}
static int F_18 ( char * V_35 , char * V_36 )
{
char V_37 , * V_14 ;
int V_38 , V_39 ;
V_38 = strlen ( V_35 ) - 1 ;
V_39 = strlen ( V_36 ) ;
if ( V_38 < V_39 )
return 0 ;
if ( V_40 && V_41 && V_38 != V_39 )
return 0 ;
if ( V_40 ) {
if ( ! strncmp ( V_35 , V_36 , V_39 ) )
return 1 ;
} else if ( V_41 ) {
if ( ! strncmp ( V_35 + V_38 - V_39 , V_36 , V_39 ) )
return 1 ;
} else {
V_37 = * V_36 ;
V_14 = V_35 ;
while ( ( V_14 = strchr ( V_14 , V_37 ) ) ) {
if ( ! strncmp ( V_14 , V_36 , V_39 ) )
return 1 ;
V_14 ++ ;
}
}
return 0 ;
}
int F_19 ( enum V_42 V_43 , const char * V_44 , T_3 V_45 )
{
int V_26 ;
int V_46 ;
int V_47 ;
int V_48 , V_49 = 0 ;
int V_50 ;
int V_51 = 0 ;
int V_52 = 0 ;
int V_53 , V_21 ;
char * V_14 , * V_54 , * V_55 = NULL , V_56 = ' ' ;
char * V_57 = L_20 ;
struct V_58 * V_59 = V_60 ;
static F_20 ( V_61 ) ;
unsigned long V_62 ( V_63 ) ;
F_21 () ;
V_50 = V_64 ;
V_64 = 0 ;
if ( ! F_12 ( V_65 ) ) {
F_2 ( V_65 ) ;
F_22 ( & V_61 , V_63 ) ;
V_51 = 1 ;
F_23 ( & V_66 ) ;
} else {
F_24 ( V_61 ) ;
}
V_26 = F_11 ( L_21 , & V_46 ) ;
if ( V_26 || V_46 <= 1 )
V_46 = 24 ;
V_26 = F_11 ( L_22 , & V_47 ) ;
if ( V_26 || V_47 <= 1 )
V_47 = 80 ;
V_26 = F_11 ( L_23 , & V_48 ) ;
if ( V_26 )
V_48 = 0 ;
if ( ! V_67 || V_68 ) {
V_69 = V_70 ;
V_71 = sizeof( V_70 ) ;
}
vsnprintf ( V_69 , V_71 , V_44 , V_45 ) ;
if ( ! V_68 && V_67 ) {
V_14 = strchr ( V_70 , '\n' ) ;
if ( ! V_14 ) {
if ( V_69 == V_70 ) {
V_54 = V_70 ;
V_21 = strlen ( V_29 ) ;
if ( ! strncmp ( V_54 , V_29 , V_21 ) ) {
V_67 = 0 ;
goto V_72;
}
}
V_21 = strlen ( V_70 ) ;
V_69 = V_70 + V_21 ;
V_71 = sizeof( V_70 ) - V_21 ;
goto V_73;
}
V_14 ++ ;
V_56 = * V_14 ;
V_55 = V_14 ;
* V_14 = '\0' ;
V_53 = F_18 ( V_70 , V_74 ) ;
if ( ! V_53 ) {
* V_55 = V_56 ;
strcpy ( V_70 , V_55 ) ;
V_21 = strlen ( V_70 ) ;
V_69 = V_70 + V_21 ;
V_71 = sizeof( V_70 ) - V_21 ;
goto V_73;
}
if ( V_67 >= V_75 )
V_67 = 0 ;
}
V_72:
V_52 = strlen ( V_70 ) ;
V_14 = ( char * ) F_25 ( V_70 ) ;
if ( ! V_76 && V_77 ) {
F_26 ( V_14 , V_52 - ( V_14 - V_70 ) ) ;
} else {
if ( V_78 && ! V_78 -> V_79 ) {
V_21 = V_52 - ( V_14 - V_70 ) ;
V_54 = V_14 ;
while ( V_21 -- ) {
V_78 -> V_80 ( * V_54 ) ;
V_54 ++ ;
}
}
while ( V_59 ) {
V_59 -> V_81 ( V_59 , V_14 , V_52 - ( V_14 - V_70 ) ) ;
F_8 () ;
V_59 = V_59 -> V_82 ;
}
}
if ( V_48 ) {
V_49 = V_83 ;
V_83 = V_84 ;
if ( F_27 ( V_70 ) || V_43 == V_85 )
F_28 ( L_1 , V_70 ) ;
else
F_29 ( L_1 , V_70 ) ;
}
if ( F_12 ( V_86 ) ) {
int V_87 = 0 ;
V_21 = V_52 ;
while ( V_21 -- ) {
if ( V_70 [ V_21 ] == '\n' ) {
V_30 ++ ;
V_87 = 0 ;
} else if ( V_70 [ V_21 ] == '\r' ) {
V_87 = 0 ;
} else {
V_87 ++ ;
}
}
V_30 += V_87 / ( V_47 + 1 ) ;
}
if ( V_30 >= V_46 ) {
char V_88 [ 16 ] = L_24 ;
V_30 = 1 ;
V_57 = F_30 ( L_25 ) ;
if ( V_57 == NULL )
V_57 = L_20 ;
F_16 () ;
V_59 = V_60 ;
if ( V_78 && ! V_78 -> V_79 ) {
V_21 = strlen ( V_57 ) ;
V_14 = V_57 ;
while ( V_21 -- ) {
V_78 -> V_80 ( * V_14 ) ;
V_14 ++ ;
}
}
while ( V_59 ) {
V_59 -> V_81 ( V_59 , V_57 , strlen ( V_57 ) ) ;
F_8 () ;
V_59 = V_59 -> V_82 ;
}
if ( V_48 )
F_28 ( L_1 , V_57 ) ;
F_10 ( V_88 , 2 ) ;
V_30 = 1 ;
V_70 [ 0 ] = '\0' ;
V_69 = V_70 ;
V_71 = sizeof( V_70 ) ;
if ( ( V_88 [ 0 ] == 'q' ) || ( V_88 [ 0 ] == 'Q' ) ) {
F_31 ( V_89 ) ;
F_32 ( V_86 ) ;
V_67 = 0 ;
F_3 ( L_5 ) ;
} else if ( V_88 [ 0 ] == ' ' ) {
F_3 ( L_7 ) ;
V_68 = 1 ;
} else if ( V_88 [ 0 ] == '\n' ) {
V_30 = V_46 - 1 ;
F_3 ( L_7 ) ;
V_68 = 1 ;
} else if ( V_88 [ 0 ] == '/' && ! V_67 ) {
F_3 ( L_7 ) ;
F_15 ( V_74 , V_90 ,
F_30 ( L_26 ) ? : L_27 ) ;
* F_33 ( V_74 , '\n' ) = '\0' ;
V_67 += V_75 ;
V_68 = 1 ;
} else if ( V_88 [ 0 ] && V_88 [ 0 ] != '\n' ) {
V_68 = 1 ;
if ( V_88 [ 0 ] != '/' )
F_3 (
L_28
L_29 ) ;
else
F_3 ( L_30
L_31 ) ;
} else if ( V_67 ) {
V_68 = 1 ;
F_3 ( L_5 ) ;
}
F_16 () ;
}
if ( V_67 && ! V_68 ) {
* V_55 = V_56 ;
strcpy ( V_70 , V_55 ) ;
V_21 = strlen ( V_70 ) ;
V_69 = V_70 + V_21 ;
V_71 = sizeof( V_70 ) - V_21 ;
}
V_73:
V_68 = 0 ;
if ( V_48 )
V_83 = V_49 ;
if ( F_12 ( V_65 ) && V_51 ) {
V_51 = 0 ;
F_34 ( & V_61 , V_63 ) ;
F_32 ( V_65 ) ;
F_35 ( & V_66 ) ;
} else {
F_36 ( V_61 ) ;
}
V_64 = V_50 ;
F_37 () ;
return V_52 ;
}
int F_3 ( const char * V_44 , ... )
{
T_3 V_45 ;
int V_91 ;
va_start ( V_45 , V_44 ) ;
V_91 = F_19 ( V_92 , V_44 , V_45 ) ;
va_end ( V_45 ) ;
return V_91 ;
}
