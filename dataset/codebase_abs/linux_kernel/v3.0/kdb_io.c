static void F_1 ( char * V_1 )
{
int V_2 = strlen ( V_1 ) ;
if ( strncmp ( V_1 , L_1 , V_2 ) != 0 &&
strncmp ( V_1 , L_2 , V_2 ) != 0 &&
strncmp ( V_1 , L_3 , V_2 ) != 0 ) {
F_2 ( V_3 ) ;
F_3 ( L_4 , V_1 ) ;
}
}
static int F_4 ( char * V_1 , T_1 V_4 )
{
#define F_5 1000
#define F_6 (2*1000000/ESCAPE_UDELAY)
char V_5 [ 5 ] ;
char * V_6 = V_5 ;
int V_7 = 0 ;
T_2 * V_8 , * V_9 = NULL ;
int V_10 ;
for ( V_8 = & V_11 [ 0 ] ; ; ++ V_8 ) {
if ( * V_8 == NULL ) {
F_7 () ;
V_8 = & V_11 [ 0 ] ;
}
if ( V_7 == 2 ) {
* V_6 = '\0' ;
V_6 = V_5 ;
-- V_7 ;
}
if ( V_7 == 1 ) {
V_10 = * V_6 ++ ;
if ( ! * V_6 )
-- V_7 ;
break;
}
V_10 = (* V_8)() ;
if ( V_10 == - 1 ) {
if ( V_7 ) {
F_8 ( F_5 ) ;
-- V_7 ;
}
continue;
}
if ( V_4 <= 2 ) {
if ( V_10 == '\r' )
V_10 = '\n' ;
* V_1 ++ = V_10 ;
* V_1 = '\0' ;
return - 1 ;
}
if ( V_7 == 0 && V_10 == '\e' ) {
V_7 = F_6 ;
V_6 = V_5 ;
V_9 = V_8 ;
}
if ( V_7 ) {
* V_6 ++ = V_10 ;
if ( V_9 != V_8 ) {
V_7 = 2 ;
continue;
}
if ( V_6 - V_5 == 1 ) {
continue;
} else if ( V_6 - V_5 == 2 ) {
if ( V_10 != '[' )
V_7 = 2 ;
continue;
} else if ( V_6 - V_5 == 3 ) {
int V_12 = 0 ;
switch ( V_10 ) {
case 'A' :
V_12 = 16 ;
break;
case 'B' :
V_12 = 14 ;
break;
case 'C' :
V_12 = 6 ;
break;
case 'D' :
V_12 = 2 ;
break;
case '1' :
case '3' :
case '4' :
V_12 = - 1 ;
break;
}
if ( V_12 != - 1 ) {
if ( V_12 > 0 ) {
V_5 [ 0 ] = V_12 ;
V_5 [ 1 ] = '\0' ;
}
V_7 = 2 ;
}
continue;
} else if ( V_6 - V_5 == 4 ) {
int V_12 = 0 ;
if ( V_10 == '~' ) {
switch ( V_5 [ 2 ] ) {
case '1' :
V_12 = 1 ;
break;
case '3' :
V_12 = 4 ;
break;
case '4' :
V_12 = 5 ;
break;
}
}
if ( V_12 > 0 ) {
V_5 [ 0 ] = V_12 ;
V_5 [ 1 ] = '\0' ;
}
V_7 = 2 ;
continue;
}
}
break;
}
return V_10 ;
}
static char * F_9 ( char * V_1 , T_1 V_4 )
{
char * V_13 = V_1 ;
char * V_14 = V_1 + V_4 - 2 ;
char * V_15 ;
char * V_16 ;
char V_17 ;
static char V_18 [ V_19 ] ;
int V_20 = strlen ( V_1 ) ;
int V_21 ;
int V_22 = 0 ;
int V_23 ;
int V_24 ;
int V_25 , V_26 ;
int V_10 ;
V_25 = F_10 ( L_5 , & V_26 ) ;
if ( V_25 )
V_26 = 30 ;
if ( V_20 > 0 ) {
V_13 += V_20 ;
if ( * ( V_1 + V_20 - 1 ) == '\n' )
V_13 -- ;
}
V_15 = V_13 ;
* V_13 = '\0' ;
F_3 ( L_4 , V_1 ) ;
V_27:
V_10 = F_4 ( V_1 , V_4 ) ;
if ( V_10 == - 1 )
return V_1 ;
if ( V_10 != 9 )
V_22 = 0 ;
switch ( V_10 ) {
case 8 :
if ( V_13 > V_1 ) {
if ( V_13 < V_15 ) {
memcpy ( V_18 , V_13 , V_15 - V_13 ) ;
memcpy ( V_13 - 1 , V_18 , V_15 - V_13 ) ;
}
* ( -- V_15 ) = '\0' ;
-- V_13 ;
F_3 ( L_6 , V_13 ) ;
V_17 = * V_13 ;
* V_13 = '\0' ;
F_3 ( V_28 ) ;
F_3 ( L_4 , V_1 ) ;
* V_13 = V_17 ;
}
break;
case 13 :
* V_15 ++ = '\n' ;
* V_15 ++ = '\0' ;
F_3 ( L_7 ) ;
return V_1 ;
case 4 :
if ( V_13 < V_15 ) {
memcpy ( V_18 , V_13 + 1 , V_15 - V_13 - 1 ) ;
memcpy ( V_13 , V_18 , V_15 - V_13 - 1 ) ;
* ( -- V_15 ) = '\0' ;
F_3 ( L_8 , V_13 ) ;
V_17 = * V_13 ;
* V_13 = '\0' ;
F_3 ( V_28 ) ;
F_3 ( L_4 , V_1 ) ;
* V_13 = V_17 ;
}
break;
case 1 :
if ( V_13 > V_1 ) {
F_3 ( L_9 ) ;
F_3 ( V_28 ) ;
V_13 = V_1 ;
}
break;
case 5 :
if ( V_13 < V_15 ) {
F_3 ( L_4 , V_13 ) ;
V_13 = V_15 ;
}
break;
case 2 :
if ( V_13 > V_1 ) {
F_3 ( L_10 ) ;
-- V_13 ;
}
break;
case 14 :
memset ( V_18 , ' ' ,
strlen ( V_28 ) + ( V_15 - V_1 ) ) ;
* ( V_18 + strlen ( V_28 ) +
( V_15 - V_1 ) ) = '\0' ;
F_3 ( L_11 , V_18 ) ;
* V_15 = ( char ) V_10 ;
* ( V_15 + 1 ) = '\0' ;
return V_15 ;
case 6 :
if ( V_13 < V_15 ) {
F_3 ( L_12 , * V_13 ) ;
++ V_13 ;
}
break;
case 16 :
memset ( V_18 , ' ' ,
strlen ( V_28 ) + ( V_15 - V_1 ) ) ;
* ( V_18 + strlen ( V_28 ) +
( V_15 - V_1 ) ) = '\0' ;
F_3 ( L_11 , V_18 ) ;
* V_15 = ( char ) V_10 ;
* ( V_15 + 1 ) = '\0' ;
return V_15 ;
case 9 :
if ( V_22 < 2 )
++ V_22 ;
V_16 = V_1 ;
while ( * V_16 == ' ' )
V_16 ++ ;
if ( V_16 > V_13 )
break;
memcpy ( V_18 , V_16 , V_13 - V_16 ) ;
* ( V_18 + ( V_13 - V_16 ) ) = '\0' ;
V_16 = strrchr ( V_18 , ' ' ) ;
if ( V_16 )
++ V_16 ;
else
V_16 = V_18 ;
V_20 = strlen ( V_16 ) ;
V_23 = F_11 ( V_16 ,
sizeof( V_18 ) -
( V_16 - V_18 ) ) ;
if ( V_22 == 2 && V_23 > 0 ) {
F_3 ( L_13 , V_23 ) ;
if ( V_23 > V_26 ) {
V_23 = V_26 ;
F_3 ( L_14
L_15
L_16 ,
V_23 ) ;
}
F_3 ( L_7 ) ;
for ( V_24 = 0 ; V_24 < V_23 ; V_24 ++ ) {
if ( F_12 ( V_16 , V_24 ) < 0 )
break;
F_3 ( L_17 , V_16 ) ;
* ( V_16 + V_20 ) = '\0' ;
}
if ( V_24 >= V_26 )
F_3 ( L_18 ) ;
F_3 ( L_7 ) ;
F_3 ( V_28 ) ;
F_3 ( L_4 , V_1 ) ;
} else if ( V_22 != 2 && V_23 > 0 ) {
V_21 = strlen ( V_16 ) ;
strncpy ( V_16 + V_21 , V_13 , V_15 - V_13 + 1 ) ;
V_21 = strlen ( V_16 ) ;
strncpy ( V_13 , V_16 + V_20 , V_21 - V_20 + 1 ) ;
V_20 = V_21 - V_20 ;
F_3 ( L_4 , V_13 ) ;
V_13 += V_20 ;
V_15 += V_20 ;
}
V_29 = 1 ;
break;
default:
if ( V_10 >= 32 && V_15 < V_14 ) {
if ( V_13 < V_15 ) {
memcpy ( V_18 , V_13 , V_15 - V_13 ) ;
memcpy ( V_13 + 1 , V_18 , V_15 - V_13 ) ;
* ++ V_15 = '\0' ;
* V_13 = V_10 ;
F_3 ( L_19 , V_13 ) ;
++ V_13 ;
V_17 = * V_13 ;
* V_13 = '\0' ;
F_3 ( V_28 ) ;
F_3 ( L_4 , V_1 ) ;
* V_13 = V_17 ;
} else {
* ++ V_15 = '\0' ;
* V_13 ++ = V_10 ;
if ( ! F_13 ( V_3 ) )
F_1 ( V_1 ) ;
else
F_3 ( L_12 , V_10 ) ;
}
if ( V_15 - V_1 >= 5 &&
strcmp ( V_15 - 5 , L_1 ) == 0 ) {
strcpy ( V_1 , L_20 ) ;
F_2 ( V_30 ) ;
return V_1 ;
}
if ( V_15 - V_1 >= 14 &&
strcmp ( V_15 - 14 , L_2 ) == 0 ) {
strcpy ( V_1 , L_20 ) ;
F_2 ( V_31 ) ;
return V_1 ;
}
}
break;
}
goto V_27;
}
char * F_14 ( char * V_1 , T_1 V_4 , char * V_32 )
{
if ( V_32 && V_28 != V_32 )
strncpy ( V_28 , V_32 , V_19 ) ;
F_3 ( V_28 ) ;
V_29 = 1 ;
return F_9 ( V_1 , V_4 ) ;
}
static void F_15 ( void )
{
T_2 * V_8 ;
int V_33 ;
int V_34 = 1 ;
while ( V_34 ) {
V_34 -- ;
V_35:
F_7 () ;
for ( V_8 = & V_11 [ 0 ] ; * V_8 ; ++ V_8 ) {
V_33 = (* V_8)() ;
if ( V_33 != - 1 ) {
V_34 = 1 ;
goto V_35;
}
}
if ( V_34 )
F_16 ( 1 ) ;
}
}
static int F_17 ( char * V_36 , char * V_37 )
{
char V_38 , * V_13 ;
int V_39 , V_40 ;
V_39 = strlen ( V_36 ) - 1 ;
V_40 = strlen ( V_37 ) ;
if ( V_39 < V_40 )
return 0 ;
if ( V_41 && V_42 && V_39 != V_40 )
return 0 ;
if ( V_41 ) {
if ( ! strncmp ( V_36 , V_37 , V_40 ) )
return 1 ;
} else if ( V_42 ) {
if ( ! strncmp ( V_36 + V_39 - V_40 , V_37 , V_40 ) )
return 1 ;
} else {
V_38 = * V_37 ;
V_13 = V_36 ;
while ( ( V_13 = strchr ( V_13 , V_38 ) ) ) {
if ( ! strncmp ( V_13 , V_37 , V_40 ) )
return 1 ;
V_13 ++ ;
}
}
return 0 ;
}
int F_18 ( const char * V_43 , T_3 V_44 )
{
int V_25 ;
int V_45 ;
int V_46 , V_47 = 0 ;
int V_48 ;
int V_49 = 0 ;
int V_50 = 0 ;
int V_51 , V_20 ;
char * V_13 , * V_52 , * V_53 = NULL , V_54 = ' ' ;
char * V_55 = L_21 ;
struct V_56 * V_57 = V_58 ;
static F_19 ( V_59 ) ;
unsigned long V_60 ( V_61 ) ;
F_20 () ;
V_48 = V_62 ;
V_62 = 0 ;
if ( ! F_13 ( V_63 ) ) {
F_2 ( V_63 ) ;
F_21 ( & V_59 , V_61 ) ;
V_49 = 1 ;
F_22 ( & V_64 ) ;
} else {
F_23 ( V_59 ) ;
}
V_25 = F_10 ( L_22 , & V_45 ) ;
if ( V_25 || V_45 <= 1 )
V_45 = 24 ;
V_25 = F_10 ( L_23 , & V_46 ) ;
if ( V_25 )
V_46 = 0 ;
if ( ! V_65 || V_66 ) {
V_67 = V_68 ;
V_69 = sizeof( V_68 ) ;
}
vsnprintf ( V_67 , V_69 , V_43 , V_44 ) ;
if ( ! V_66 && V_65 ) {
V_13 = strchr ( V_68 , '\n' ) ;
if ( ! V_13 ) {
if ( V_67 == V_68 ) {
V_52 = V_68 ;
V_20 = strlen ( V_28 ) ;
if ( ! strncmp ( V_52 , V_28 , V_20 ) ) {
V_65 = 0 ;
goto V_70;
}
}
V_20 = strlen ( V_68 ) ;
V_67 = V_68 + V_20 ;
V_69 = sizeof( V_68 ) - V_20 ;
goto V_71;
}
V_13 ++ ;
V_54 = * V_13 ;
V_53 = V_13 ;
* V_13 = '\0' ;
V_51 = F_17 ( V_68 , V_72 ) ;
if ( ! V_51 ) {
* V_53 = V_54 ;
strcpy ( V_68 , V_53 ) ;
V_20 = strlen ( V_68 ) ;
V_67 = V_68 + V_20 ;
V_69 = sizeof( V_68 ) - V_20 ;
goto V_71;
}
}
V_70:
V_50 = strlen ( V_68 ) ;
if ( ! V_73 && V_74 ) {
F_24 ( V_68 , V_50 ) ;
} else {
if ( ! V_75 -> V_76 ) {
V_20 = strlen ( V_68 ) ;
V_13 = V_68 ;
while ( V_20 -- ) {
V_75 -> V_77 ( * V_13 ) ;
V_13 ++ ;
}
}
while ( V_57 ) {
V_57 -> V_78 ( V_57 , V_68 , V_50 ) ;
F_7 () ;
V_57 = V_57 -> V_79 ;
}
}
if ( V_46 ) {
V_47 = V_80 ;
V_80 = 0 ;
F_25 ( V_81 L_4 , V_68 ) ;
}
if ( F_13 ( V_82 ) && strchr ( V_68 , '\n' ) )
V_29 ++ ;
if ( V_29 == V_45 ) {
char V_83 [ 16 ] = L_24 ;
#if F_26 ( V_84 )
char V_85 [ 32 ] ;
#endif
V_29 = 1 ;
V_55 = F_27 ( L_25 ) ;
if ( V_55 == NULL )
V_55 = L_21 ;
#if F_26 ( V_84 )
if ( strchr ( V_55 , '%' ) ) {
sprintf ( V_85 , V_55 , F_28 () ) ;
F_29 () ;
V_55 = V_85 ;
}
#endif
F_15 () ;
V_57 = V_58 ;
if ( ! V_75 -> V_76 ) {
V_20 = strlen ( V_55 ) ;
V_13 = V_55 ;
while ( V_20 -- ) {
V_75 -> V_77 ( * V_13 ) ;
V_13 ++ ;
}
}
while ( V_57 ) {
V_57 -> V_78 ( V_57 , V_55 , strlen ( V_55 ) ) ;
F_7 () ;
V_57 = V_57 -> V_79 ;
}
if ( V_46 )
F_25 ( L_4 , V_55 ) ;
F_9 ( V_83 , 2 ) ;
V_29 = 1 ;
V_68 [ 0 ] = '\0' ;
V_67 = V_68 ;
V_69 = sizeof( V_68 ) ;
if ( ( V_83 [ 0 ] == 'q' ) || ( V_83 [ 0 ] == 'Q' ) ) {
F_30 ( V_86 ) ;
F_31 ( V_82 ) ;
V_65 = 0 ;
F_3 ( L_7 ) ;
} else if ( V_83 [ 0 ] == ' ' ) {
F_3 ( L_7 ) ;
V_66 = 1 ;
} else if ( V_83 [ 0 ] == '\n' ) {
V_29 = V_45 - 1 ;
F_3 ( L_9 ) ;
V_66 = 1 ;
} else if ( V_83 [ 0 ] && V_83 [ 0 ] != '\n' ) {
V_66 = 1 ;
F_3 ( L_26
L_27 ) ;
} else if ( V_65 ) {
V_66 = 1 ;
F_3 ( L_7 ) ;
}
F_15 () ;
}
if ( V_65 && ! V_66 ) {
* V_53 = V_54 ;
strcpy ( V_68 , V_53 ) ;
V_20 = strlen ( V_68 ) ;
V_67 = V_68 + V_20 ;
V_69 = sizeof( V_68 ) - V_20 ;
}
V_71:
V_66 = 0 ;
if ( V_46 )
V_80 = V_47 ;
if ( F_13 ( V_63 ) && V_49 ) {
V_49 = 0 ;
F_32 ( & V_59 , V_61 ) ;
F_31 ( V_63 ) ;
F_33 ( & V_64 ) ;
} else {
F_34 ( V_59 ) ;
}
V_62 = V_48 ;
F_35 () ;
return V_50 ;
}
int F_3 ( const char * V_43 , ... )
{
T_3 V_44 ;
int V_87 ;
va_start ( V_44 , V_43 ) ;
V_87 = F_18 ( V_43 , V_44 ) ;
va_end ( V_44 ) ;
return V_87 ;
}
