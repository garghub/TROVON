void F_1 ( void ) {
V_1 = F_2 () ;
}
T_1 * F_3 ( const char * V_2 ,
T_2 V_3 ,
const char * V_4 ,
T_3 V_5 ,
void * * V_6 ,
T_4 * V_7 ,
T_4 V_8 ,
const char * V_9 ,
T_5 V_10 ,
T_6 V_11 ,
T_7 V_12 ,
T_8 V_13 ,
T_9 * V_14 ) {
T_1 * V_15 = ( T_1 * ) F_4 ( sizeof( T_1 ) ) ;
T_4 V_16 ;
if ( ! V_1 )
V_1 = F_2 () ;
F_5 ( V_1 , V_15 ) ;
F_6 ( V_2 && V_3 && V_4 && V_6 && V_7 ) ;
V_15 -> V_2 = F_7 ( V_2 ) ;
V_15 -> V_17 = V_3 ;
V_15 -> V_4 = F_7 ( V_4 ) ;
V_15 -> V_5 = V_5 ;
V_15 -> V_18 = V_6 ;
V_15 -> V_19 = V_7 ;
V_15 -> V_10 = V_10 ;
V_15 -> V_11 = V_11 ;
V_15 -> V_12 = V_12 ;
V_15 -> V_13 = V_13 ;
V_15 -> V_20 = V_14 ;
V_15 -> V_21 = F_8 ( FALSE , FALSE , ( T_4 ) V_15 -> V_17 ) ;
V_15 -> V_22 = F_8 ( FALSE , FALSE , ( T_4 ) V_15 -> V_17 ) ;
V_15 -> V_23 = F_8 ( FALSE , FALSE , sizeof( T_3 ) ) ;
V_15 -> V_24 = FALSE ;
V_15 -> V_25 = FALSE ;
V_15 -> V_26 = FALSE ;
V_15 -> V_27 = NULL ;
V_15 -> V_28 = NULL ;
V_15 -> V_9 = V_9 ;
V_15 -> V_8 = V_8 ;
for ( V_16 = 0 ; V_14 [ V_16 ] . V_29 ; V_16 ++ ) {
T_10 * V_30 = ( T_10 * ) F_4 ( sizeof( T_10 ) ) ;
V_30 -> V_31 = V_16 + 1 ;
V_30 -> V_27 = NULL ;
V_30 -> V_28 = NULL ;
V_14 [ V_16 ] . V_32 = V_30 ;
}
V_15 -> V_33 = V_16 ;
* V_6 = NULL ;
* V_7 = 0 ;
return V_15 ;
}
void * F_9 ( T_1 * V_15 , const void * V_34 , T_3 V_35 ) {
void * V_36 ;
T_3 * V_37 ;
F_10 ( V_15 -> V_22 , V_34 , 1 ) ;
V_36 = V_15 -> V_22 -> V_34 + ( V_15 -> V_17 * ( V_15 -> V_22 -> V_38 - 1 ) ) ;
if ( V_15 -> V_10 ) {
V_15 -> V_10 ( V_36 , V_34 , ( unsigned int ) V_15 -> V_17 ) ;
}
if ( V_35 ) {
F_10 ( V_15 -> V_21 , V_34 , 1 ) ;
V_36 = V_15 -> V_21 -> V_34 + ( V_15 -> V_17 * ( V_15 -> V_21 -> V_38 - 1 ) ) ;
if ( V_15 -> V_10 ) {
V_15 -> V_10 ( V_36 , V_34 , ( unsigned int ) V_15 -> V_17 ) ;
}
F_11 ( V_15 ) ;
} else {
V_36 = NULL ;
}
F_10 ( V_15 -> V_23 , & V_35 , 1 ) ;
V_37 = ( T_3 * ) ( V_15 -> V_23 -> V_34 + ( sizeof( T_3 ) * ( V_15 -> V_23 -> V_38 - 1 ) ) ) ;
* V_37 = V_35 ;
return V_36 ;
}
void F_12 ( T_1 * V_15 , T_4 V_39 , T_4 V_40 ) {
T_2 V_41 = V_15 -> V_17 ;
void * V_42 = F_13 ( V_41 ) ;
T_3 V_43 ;
F_6 ( V_39 < V_15 -> V_22 -> V_38 && V_40 < V_15 -> V_22 -> V_38 ) ;
if ( V_39 == V_40 ) return;
memcpy ( V_42 , F_14 ( V_15 , V_39 ) , V_41 ) ;
memcpy ( F_14 ( V_15 , V_39 ) , F_14 ( V_15 , V_40 ) , V_41 ) ;
memcpy ( F_14 ( V_15 , V_40 ) , V_42 , V_41 ) ;
V_43 = * ( T_3 * ) ( V_15 -> V_23 -> V_34 + ( sizeof( T_3 ) * ( V_39 ) ) ) ;
* ( T_3 * ) ( V_15 -> V_23 -> V_34 + ( sizeof( T_3 ) * ( V_39 ) ) ) = * ( T_3 * ) ( V_15 -> V_23 -> V_34 + ( sizeof( T_3 ) * ( V_40 ) ) ) ;
* ( T_3 * ) ( V_15 -> V_23 -> V_34 + ( sizeof( T_3 ) * ( V_40 ) ) ) = V_43 ;
}
void F_15 ( T_1 * V_15 , T_4 V_44 ) {
F_6 ( V_44 < V_15 -> V_22 -> V_38 ) ;
if ( V_15 -> V_12 ) {
V_15 -> V_12 ( F_14 ( V_15 , V_44 ) ) ;
}
F_16 ( V_15 -> V_22 , V_44 ) ;
F_16 ( V_15 -> V_23 , V_44 ) ;
}
T_11 * F_17 ( T_1 * V_15 , T_3 V_45 ) {
T_11 * V_46 = NULL ;
if ( ! V_15 -> V_26 ) {
V_46 = F_18 ( V_15 -> V_4 , V_15 -> V_5 ) ;
}
if ( ( ! V_45 ) && ( ! F_19 ( V_46 ) ) ) {
T_11 * V_47 = F_20 ( V_15 -> V_4 ) ;
if ( F_19 ( V_47 ) ) {
F_21 ( V_46 ) ;
return V_47 ;
}
F_21 ( V_47 ) ;
F_21 ( V_46 ) ;
return NULL ;
}
return V_46 ;
}
T_1 * F_22 ( const char * V_2 ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_1 -> V_38 ; V_16 ++ ) {
T_1 * V_48 = ( T_1 * ) F_23 ( V_1 , V_16 ) ;
if ( F_24 ( V_48 -> V_2 , V_2 ) ) {
return ( V_48 ) ;
}
}
return NULL ;
}
static void F_25 ( T_12 * V_49 , void * V_36 , T_9 * V_30 ) {
T_4 V_50 ;
const char * V_51 ;
V_30 -> V_52 . V_53 ( V_36 , & V_51 , & V_50 , V_30 -> V_54 . V_53 , V_30 -> V_55 ) ;
switch( V_30 -> V_56 ) {
case V_57 :
case V_58 :
case V_59 :
case V_60 : {
T_4 V_16 ;
putc ( '"' , V_49 ) ;
for( V_16 = 0 ; V_16 < V_50 ; V_16 ++ ) {
char V_61 = V_51 [ V_16 ] ;
if ( V_61 == '"' || V_61 == '\\' || ! isprint ( ( V_62 ) V_61 ) ) {
fprintf ( V_49 , L_1 , V_61 ) ;
} else {
putc ( V_61 , V_49 ) ;
}
}
putc ( '"' , V_49 ) ;
return;
}
case V_63 : {
T_4 V_16 ;
for( V_16 = 0 ; V_16 < V_50 ; V_16 ++ ) {
fprintf ( V_49 , L_2 , ( ( V_64 * ) V_51 ) [ V_16 ] ) ;
}
return;
}
default:
F_26 () ;
}
}
T_3 F_27 ( T_1 * V_15 , const char * * error ) {
T_4 V_16 ;
T_11 * V_65 = F_17 ( V_15 , TRUE ) ;
T_12 * V_49 ;
if ( ! V_65 ) return FALSE ;
V_49 = F_28 ( V_65 , L_3 ) ;
if ( ! V_49 && V_66 == V_67 ) {
T_11 * V_68 = NULL ;
if ( F_29 ( & V_68 ) != 0 ) {
* error = F_30 ( L_4 , V_68 ) ;
F_21 ( V_68 ) ;
return FALSE ;
}
V_49 = F_28 ( V_65 , L_3 ) ;
}
if ( ! V_49 ) {
* error = F_30 ( L_5 , V_65 , F_31 ( V_66 ) ) ;
return FALSE ;
}
* error = NULL ;
F_21 ( V_65 ) ;
for ( V_16 = 0 ; V_16 < V_15 -> V_21 -> V_38 ; V_16 ++ ) {
if ( V_15 -> V_12 ) {
V_15 -> V_12 ( F_32 ( V_15 , V_16 ) ) ;
}
}
F_33 ( V_15 -> V_21 , 0 ) ;
* ( ( V_15 ) -> V_18 ) = NULL ;
* ( ( V_15 ) -> V_19 ) = 0 ;
for ( V_16 = 0 ; V_16 < V_15 -> V_22 -> V_38 ; V_16 ++ ) {
void * V_36 = V_15 -> V_22 -> V_34 + ( V_15 -> V_17 * V_16 ) ;
T_3 * V_37 = ( T_3 * ) ( V_15 -> V_23 -> V_34 + sizeof( T_3 ) * V_16 ) ;
if ( * V_37 ) {
F_10 ( V_15 -> V_21 , V_36 , 1 ) ;
if ( V_15 -> V_10 ) {
V_15 -> V_10 ( F_32 ( V_15 , V_16 ) , V_36 , ( unsigned int ) V_15 -> V_17 ) ;
}
F_11 ( V_15 ) ;
}
}
fprintf ( V_49 , L_6 ) ;
for ( V_16 = 0 ; V_16 < V_15 -> V_21 -> V_38 ; V_16 ++ ) {
void * V_36 = V_15 -> V_21 -> V_34 + ( V_15 -> V_17 * V_16 ) ;
T_9 * V_30 ;
T_4 V_69 ;
V_30 = V_15 -> V_20 ;
for( V_69 = 0 ; V_69 < V_15 -> V_33 ; V_69 ++ ) {
F_25 ( V_49 , V_36 , & ( V_30 [ V_69 ] ) ) ;
fputs ( ( V_69 == V_15 -> V_33 - 1 ) ? L_7 : L_8 , V_49 ) ;
}
}
fclose ( V_49 ) ;
V_15 -> V_24 = FALSE ;
return TRUE ;
}
void F_34 ( T_1 * V_15 ) {
F_35 ( V_1 , V_15 ) ;
}
T_1 * F_36 ( T_11 * V_2 ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_1 -> V_38 ; V_16 ++ ) {
T_1 * V_48 = ( T_1 * ) F_23 ( V_1 , V_16 ) ;
if ( strcmp ( V_48 -> V_2 , V_2 ) == 0 || strcmp ( V_48 -> V_4 , V_2 ) == 0 ) {
return V_48 ;
}
}
return NULL ;
}
void F_37 ( T_1 * V_15 ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_15 -> V_21 -> V_38 ; V_16 ++ ) {
if ( V_15 -> V_12 ) {
V_15 -> V_12 ( F_32 ( V_15 , V_16 ) ) ;
}
}
for ( V_16 = 0 ; V_16 < V_15 -> V_22 -> V_38 ; V_16 ++ ) {
if ( V_15 -> V_12 ) {
V_15 -> V_12 ( F_14 ( V_15 , V_16 ) ) ;
}
}
F_33 ( V_15 -> V_22 , 0 ) ;
F_33 ( V_15 -> V_21 , 0 ) ;
F_33 ( V_15 -> V_23 , 0 ) ;
* ( ( V_15 ) -> V_18 ) = NULL ;
* ( ( V_15 ) -> V_19 ) = 0 ;
}
void * F_38 ( T_1 * V_15 , T_4 * V_70 ) {
T_4 V_3 = ( T_4 ) ( V_15 -> V_17 * V_15 -> V_21 -> V_38 ) ;
* V_70 = V_3 ;
return V_3 ? F_39 ( V_15 -> V_21 -> V_34 , V_3 ) : NULL ;
}
void * F_40 ( T_1 * V_15 , T_4 * V_70 ) {
T_4 V_3 = ( T_4 ) ( V_15 -> V_17 * V_15 -> V_21 -> V_38 ) ;
* V_70 = ( T_4 ) V_3 ;
return V_3 ? F_41 ( V_15 -> V_21 -> V_34 , V_3 ) : NULL ;
}
void F_42 ( void ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_1 -> V_38 ; V_16 ++ ) {
T_1 * V_48 = ( T_1 * ) F_23 ( V_1 , V_16 ) ;
if ( V_48 -> V_5 ) {
F_37 ( V_48 ) ;
V_48 -> V_25 = FALSE ;
}
}
}
void F_43 ( void ) {
while( V_1 -> V_38 ) {
F_34 ( ( T_1 * ) V_1 -> V_71 ) ;
}
F_44 ( V_1 , TRUE ) ;
}
void F_45 ( T_13 V_52 , void * V_21 ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_1 -> V_38 ; V_16 ++ )
V_52 ( F_23 ( V_1 , V_16 ) , V_21 ) ;
}
void F_46 ( void ) {
T_4 V_16 ;
const T_11 * V_72 ;
for ( V_16 = 0 ; V_16 < V_1 -> V_38 ; V_16 ++ ) {
T_1 * V_48 = ( T_1 * ) F_23 ( V_1 , V_16 ) ;
V_72 = NULL ;
if ( ! V_48 -> V_25 )
F_47 ( V_48 , & V_72 ) ;
if ( V_72 ) {
F_48 ( L_9 , V_48 -> V_2 , V_72 ) ;
}
}
}
T_3 F_49 ( void * T_14 V_73 , const char * V_74 , T_4 V_38 V_73 , const void * T_15 V_73 , const void * T_16 V_73 , const char * * V_72 ) {
if ( V_74 == NULL ) {
* V_72 = L_10 ;
return FALSE ;
}
* V_72 = NULL ;
return TRUE ;
}
T_3 F_50 ( void * T_14 V_73 , const char * V_74 , T_4 V_38 , const void * T_15 V_73 , const void * T_16 V_73 , const char * * V_72 ) {
unsigned int V_16 ;
* V_72 = NULL ;
if ( V_74 == NULL ) {
* V_72 = L_10 ;
return FALSE ;
}
for( V_16 = 0 ; V_16 < V_38 ; V_16 ++ )
if( ! ( isdigit ( V_74 [ V_16 ] ) || V_74 [ V_16 ] == '.' ) ) {
* V_72 = L_11 ;
break;
}
if( V_74 [ V_38 - 1 ] == '.' )
* V_72 = L_12 ;
if( ! ( ( * V_74 == '0' || * V_74 == '1' || * V_74 == '2' ) && ( V_38 > 1 && V_74 [ 1 ] == '.' ) ) )
* V_72 = L_13 ;
return * V_72 == NULL ;
}
T_3 F_51 ( void * T_14 V_73 , const char * V_74 , T_4 V_38 , const void * T_15 V_73 , const void * T_16 V_73 , const char * * V_72 ) {
if ( V_38 ) {
char * V_2 = F_52 ( V_74 , V_38 ) ;
F_53 ( V_2 ) ;
F_54 ( V_2 ) ;
if ( F_55 ( V_2 ) ) {
* V_72 = NULL ;
return TRUE ;
} else {
* V_72 = L_14 ;
return FALSE ;
}
} else {
* V_72 = NULL ;
return TRUE ;
}
}
T_3 F_56 ( void * T_14 V_73 , const char * V_74 , T_4 V_38 , const void * T_15 V_73 , const void * T_16 V_73 , const char * * V_72 ) {
if ( V_38 > 0 ) {
char * V_75 = F_52 ( V_74 , V_38 ) ;
long V_16 = strtol ( V_75 , & V_75 , 10 ) ;
if ( ( V_16 == 0 ) && ( V_66 == V_76 || V_66 == V_77 ) ) {
* V_72 = F_31 ( V_66 ) ;
return FALSE ;
}
}
* V_72 = NULL ;
return TRUE ;
}
T_3 F_57 ( void * T_14 V_73 , const char * V_74 , T_4 V_38 , const void * T_15 V_73 , const void * T_16 V_73 , const char * * V_72 ) {
if ( V_38 > 0 ) {
char * V_75 = F_52 ( V_74 , V_38 ) ;
long V_16 = strtol ( V_75 , & V_75 , 16 ) ;
if ( ( V_16 == 0 ) && ( V_66 == V_76 || V_66 == V_77 ) ) {
* V_72 = F_31 ( V_66 ) ;
return FALSE ;
}
}
* V_72 = NULL ;
return TRUE ;
}
T_3 F_58 ( void * T_14 V_73 , const char * V_74 , T_4 V_38 , const void * V_78 , const void * T_16 V_73 , const char * * V_72 ) {
char * V_75 = F_52 ( V_74 , V_38 ) ;
T_4 V_16 ;
const T_17 * V_79 = ( const T_17 * ) V_78 ;
for( V_16 = 0 ; V_79 [ V_16 ] . V_74 ; V_16 ++ ) {
if ( F_24 ( V_79 [ V_16 ] . V_74 , V_75 ) ) {
* V_72 = NULL ;
return TRUE ;
}
}
* V_72 = F_30 ( L_15 , V_75 ) ;
return FALSE ;
}
T_3 F_59 ( void * T_14 V_73 , const char * V_74 , T_4 V_38 , const void * V_78 V_73 , const void * T_16 , const char * * V_72 ) {
char * V_75 = F_52 ( V_74 , V_38 ) ;
T_18 * V_80 = NULL ;
T_19 V_81 = F_60 ( & V_80 , V_75 , F_61 ( T_16 ) ) ;
switch ( V_81 ) {
case V_82 :
* V_72 = NULL ;
return TRUE ;
case V_83 :
* V_72 = F_30 ( L_16 , V_75 ) ;
return FALSE ;
case V_84 :
* V_72 = F_30 ( L_17 , V_75 , F_61 ( T_16 ) ) ;
return FALSE ;
default:
* V_72 = L_18 ;
return FALSE ;
}
}
static int F_62 ( char V_85 ) {
switch( V_85 ) {
case '0' : return 0 ;
case '1' : return 1 ;
case '2' : return 2 ;
case '3' : return 3 ;
case '4' : return 4 ;
case '5' : return 5 ;
case '6' : return 6 ;
case '7' : return 7 ;
case '8' : return 8 ;
case '9' : return 9 ;
case 'a' : case 'A' : return 10 ;
case 'b' : case 'B' : return 11 ;
case 'c' : case 'C' : return 12 ;
case 'd' : case 'D' : return 13 ;
case 'e' : case 'E' : return 14 ;
case 'f' : case 'F' : return 15 ;
default: return - 1 ;
}
}
char * F_63 ( const char * V_86 , T_4 V_87 , T_4 * V_70 ) {
V_64 * V_88 ;
T_4 V_38 = V_87 / 2 ;
int V_16 = 0 ;
int V_89 , V_90 ;
if ( V_87 % 2 ) {
return NULL ;
}
V_88 = ( V_64 * ) F_64 ( V_38 + 1 ) ;
if ( V_70 ) * V_70 = V_38 ;
while( V_87 ) {
V_90 = F_62 ( * ( V_86 ++ ) ) ;
V_89 = F_62 ( * ( V_86 ++ ) ) ;
V_88 [ V_16 ++ ] = ( V_90 * 16 ) + V_89 ;
V_87 -= 2 ;
}
return ( char * ) V_88 ;
}
char * F_65 ( const char * V_86 , T_4 V_87 , T_4 * V_70 ) {
char * V_88 = ( char * ) F_64 ( V_87 + 1 ) ;
char * V_91 = V_88 ;
T_4 V_38 = 0 ;
const char * V_41 ;
const char * V_92 = V_86 + V_87 ;
for ( V_41 = ( const char * ) V_86 ; V_41 < V_92 ; V_41 ++ ) {
switch( * V_41 ) {
case '\\' :
switch( * ( ++ V_41 ) ) {
case 'a' : * ( V_91 ++ ) = '\a' ; V_38 ++ ; break;
case 'b' : * ( V_91 ++ ) = '\b' ; V_38 ++ ; break;
case 'e' : * ( V_91 ++ ) = '\033' ; V_38 ++ ; break;
case 'f' : * ( V_91 ++ ) = '\f' ; V_38 ++ ; break;
case 'n' : * ( V_91 ++ ) = '\n' ; V_38 ++ ; break;
case 'r' : * ( V_91 ++ ) = '\r' ; V_38 ++ ; break;
case 't' : * ( V_91 ++ ) = '\t' ; V_38 ++ ; break;
case 'v' : * ( V_91 ++ ) = '\v' ; V_38 ++ ; break;
case '0' :
case '1' :
case '2' :
case '3' :
case '4' :
case '5' :
case '6' :
case '7' :
{
int V_93 = 0 ;
int V_94 = 0 ;
int V_95 = 0 ;
int V_61 = 0 ;
V_93 = ( * V_41 ) - '0' ;
if ( V_41 [ 1 ] >= '0' && V_41 [ 1 ] <= '7' ) {
V_94 = V_93 ;
V_93 = ( * ++ V_41 ) - '0' ;
if ( V_41 [ 1 ] >= '0' && V_41 [ 1 ] <= '7' ) {
V_95 = V_94 ;
V_94 = V_93 ;
V_93 = ( * ++ V_41 ) - '0' ;
}
}
V_61 = ( 64 * V_95 ) + ( 8 * V_94 ) + V_93 ;
* ( V_91 ++ ) = ( char ) ( V_61 > 255 ? 255 : V_61 ) ;
V_38 ++ ;
break;
}
case 'x' :
{
char V_94 = * ( V_41 + 1 ) ;
char V_93 = * ( V_41 + 2 ) ;
if ( isxdigit ( ( V_62 ) V_94 ) && isxdigit ( ( V_62 ) V_93 ) ) {
* ( V_91 ++ ) = ( F_62 ( V_94 ) * 0x10 ) + F_62 ( V_93 ) ;
V_41 += 2 ;
} else {
* ( V_91 ++ ) = * V_41 ;
}
V_38 ++ ;
break;
}
default:
* V_91 ++ = * V_41 ;
break;
}
break;
default:
* ( V_91 ++ ) = * V_41 ;
V_38 ++ ;
break;
}
}
if ( V_70 ) * V_70 = V_38 ;
return V_88 ;
}
char * F_66 ( const char * V_86 , T_4 V_87 , T_4 * V_70 ) {
return F_65 ( V_86 + 1 , V_87 - 2 , V_70 ) ;
}
char * F_67 ( const char * V_88 , T_4 V_38 ) {
const V_64 * V_96 = ( ( V_64 * ) V_88 ) + V_38 ;
char * V_97 = ( char * ) F_68 ( ( 4 * V_38 ) + 1 ) ;
const V_64 * V_40 ;
char * V_41 = V_97 ;
for ( V_40 = ( V_64 * ) V_88 ; V_40 < V_96 ; V_40 ++ ) {
if ( isprint ( * V_40 ) ) {
* ( V_41 ++ ) = ( * V_40 ) ;
} else {
F_69 ( V_41 , 5 , L_1 , ( ( T_4 ) * V_40 ) ) ;
V_41 += 4 ;
}
}
return V_97 ;
}
