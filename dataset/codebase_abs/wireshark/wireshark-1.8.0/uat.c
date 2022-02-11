void F_1 ( void ) {
V_1 = F_2 () ;
}
T_1 * F_3 ( const char * V_2 ,
T_2 V_3 ,
const char * V_4 ,
T_3 V_5 ,
void * * V_6 ,
T_4 * V_7 ,
const char * V_8 ,
const char * V_9 ,
T_5 V_10 ,
T_6 V_11 ,
T_7 V_12 ,
T_8 V_13 ,
T_9 * V_14 ) {
T_1 * V_15 = F_4 ( sizeof( T_1 ) ) ;
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
V_15 -> V_22 = FALSE ;
V_15 -> V_23 = FALSE ;
V_15 -> V_24 = FALSE ;
V_15 -> V_25 = NULL ;
V_15 -> V_26 = NULL ;
V_15 -> V_9 = V_9 ;
V_15 -> V_8 = V_8 ;
for ( V_16 = 0 ; V_14 [ V_16 ] . V_27 ; V_16 ++ ) {
T_10 * V_28 = F_4 ( sizeof( T_10 ) ) ;
V_28 -> V_29 = V_16 + 1 ;
V_28 -> V_25 = NULL ;
V_28 -> V_26 = NULL ;
V_14 [ V_16 ] . V_30 = V_28 ;
}
V_15 -> V_31 = V_16 ;
* V_6 = NULL ;
* V_7 = 0 ;
return V_15 ;
}
void * F_9 ( T_1 * V_15 , const void * V_32 ) {
void * V_33 ;
F_10 ( V_15 -> V_21 , V_32 , 1 ) ;
V_33 = V_15 -> V_21 -> V_32 + ( V_15 -> V_17 * ( V_15 -> V_21 -> V_34 - 1 ) ) ;
if ( V_15 -> V_10 ) {
V_15 -> V_10 ( V_33 , V_32 , ( unsigned int ) V_15 -> V_17 ) ;
}
F_11 ( V_15 ) ;
return V_33 ;
}
void F_12 ( T_1 * V_15 , T_4 V_35 , T_4 V_36 ) {
T_2 V_37 = V_15 -> V_17 ;
void * V_38 = F_13 ( V_37 ) ;
F_6 ( V_35 < V_15 -> V_21 -> V_34 && V_36 < V_15 -> V_21 -> V_34 ) ;
if ( V_35 == V_36 ) return;
memcpy ( V_38 , F_14 ( V_15 , V_35 ) , V_37 ) ;
memcpy ( F_14 ( V_15 , V_35 ) , F_14 ( V_15 , V_36 ) , V_37 ) ;
memcpy ( F_14 ( V_15 , V_36 ) , V_38 , V_37 ) ;
}
void F_15 ( T_1 * V_15 , T_4 V_39 ) {
F_6 ( V_39 < V_15 -> V_21 -> V_34 ) ;
if ( V_15 -> V_12 ) {
V_15 -> V_12 ( F_14 ( V_15 , V_39 ) ) ;
}
F_16 ( V_15 -> V_21 , V_39 ) ;
F_11 ( V_15 ) ;
}
T_11 * F_17 ( T_1 * V_15 , T_3 V_40 ) {
T_11 * V_41 = NULL ;
if ( ! V_15 -> V_24 ) {
V_41 = F_18 ( V_15 -> V_4 , V_15 -> V_5 , V_40 ) ;
}
if ( ( ! V_40 ) && ( ! F_19 ( V_41 ) ) ) {
T_11 * V_42 = F_20 ( V_15 -> V_4 ) ;
if ( F_19 ( V_42 ) ) {
F_21 ( V_41 ) ;
return V_42 ;
}
F_21 ( V_42 ) ;
F_21 ( V_41 ) ;
return NULL ;
}
return V_41 ;
}
T_1 * F_22 ( const char * V_2 ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_1 -> V_34 ; V_16 ++ ) {
T_1 * V_43 = F_23 ( V_1 , V_16 ) ;
if ( F_24 ( V_43 -> V_2 , V_2 ) ) {
return ( V_43 ) ;
}
}
return NULL ;
}
static void F_25 ( T_12 * V_44 , void * V_33 , T_9 * V_28 ) {
T_4 V_45 ;
const char * V_46 ;
V_28 -> V_47 . V_48 ( V_33 , & V_46 , & V_45 , V_28 -> V_49 . V_48 , V_28 -> V_50 ) ;
switch( V_28 -> V_51 ) {
case V_52 :
case V_53 :
case V_54 :
case V_55 : {
T_4 V_16 ;
putc ( '"' , V_44 ) ;
for( V_16 = 0 ; V_16 < V_45 ; V_16 ++ ) {
char V_56 = V_46 [ V_16 ] ;
if ( V_56 == '"' || V_56 == '\\' || ! isprint ( ( V_57 ) V_56 ) ) {
fprintf ( V_44 , L_1 , V_56 ) ;
} else {
putc ( V_56 , V_44 ) ;
}
}
putc ( '"' , V_44 ) ;
return;
}
case V_58 : {
T_4 V_16 ;
for( V_16 = 0 ; V_16 < V_45 ; V_16 ++ ) {
fprintf ( V_44 , L_2 , ( ( V_59 * ) V_46 ) [ V_16 ] ) ;
}
return;
}
default:
F_26 () ;
}
}
T_3 F_27 ( T_1 * V_15 , char * * error ) {
T_4 V_16 ;
T_11 * V_60 = F_17 ( V_15 , TRUE ) ;
T_12 * V_44 ;
if ( ! V_60 ) return FALSE ;
V_44 = F_28 ( V_60 , L_3 ) ;
if ( ! V_44 && V_61 == V_62 ) {
T_11 * V_63 = NULL ;
if ( F_29 ( & V_63 ) != 0 ) {
* error = F_30 ( L_4 , V_63 ) ;
F_21 ( V_63 ) ;
return FALSE ;
}
V_44 = F_28 ( V_60 , L_3 ) ;
}
if ( ! V_44 ) {
* error = F_30 ( L_5 , V_60 , F_31 ( V_61 ) ) ;
return FALSE ;
}
* error = NULL ;
F_21 ( V_60 ) ;
fprintf ( V_44 , L_6 ) ;
for ( V_16 = 0 ; V_16 < V_15 -> V_21 -> V_34 ; V_16 ++ ) {
void * V_33 = V_15 -> V_21 -> V_32 + ( V_15 -> V_17 * V_16 ) ;
T_9 * V_28 ;
T_4 V_64 ;
V_28 = V_15 -> V_20 ;
for( V_64 = 0 ; V_64 < V_15 -> V_31 ; V_64 ++ ) {
F_25 ( V_44 , V_33 , & ( V_28 [ V_64 ] ) ) ;
fputs ( ( V_64 == V_15 -> V_31 - 1 ) ? L_7 : L_8 , V_44 ) ;
}
}
fclose ( V_44 ) ;
V_15 -> V_22 = FALSE ;
return TRUE ;
}
void F_32 ( T_1 * V_15 ) {
F_33 ( V_1 , V_15 ) ;
}
T_1 * F_34 ( T_11 * V_2 ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_1 -> V_34 ; V_16 ++ ) {
T_1 * V_43 = F_23 ( V_1 , V_16 ) ;
if ( strcmp ( V_43 -> V_2 , V_2 ) == 0 || strcmp ( V_43 -> V_4 , V_2 ) == 0 ) {
return V_43 ;
}
}
return NULL ;
}
void F_35 ( T_1 * V_15 ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_15 -> V_21 -> V_34 ; V_16 ++ ) {
if ( V_15 -> V_12 ) {
V_15 -> V_12 ( F_14 ( V_15 , V_16 ) ) ;
}
}
F_36 ( V_15 -> V_21 , 0 ) ;
* ( ( V_15 ) -> V_18 ) = NULL ;
* ( ( V_15 ) -> V_19 ) = 0 ;
}
void * F_37 ( T_1 * V_15 , T_4 * V_65 ) {
T_4 V_3 = ( T_4 ) ( V_15 -> V_17 * V_15 -> V_21 -> V_34 ) ;
* V_65 = V_3 ;
return V_3 ? F_38 ( V_15 -> V_21 -> V_32 , V_3 ) : NULL ;
}
void * F_39 ( T_1 * V_15 , T_4 * V_65 ) {
T_4 V_3 = ( T_4 ) ( V_15 -> V_17 * V_15 -> V_21 -> V_34 ) ;
* V_65 = ( T_4 ) V_3 ;
return V_3 ? F_40 ( V_15 -> V_21 -> V_32 , V_3 ) : NULL ;
}
void F_41 ( void ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_1 -> V_34 ; V_16 ++ ) {
T_1 * V_43 = F_23 ( V_1 , V_16 ) ;
if ( V_43 -> V_5 ) {
F_35 ( V_43 ) ;
V_43 -> V_23 = FALSE ;
}
}
}
void F_42 ( void ) {
while( V_1 -> V_34 ) {
F_32 ( ( T_1 * ) V_1 -> V_66 ) ;
}
F_43 ( V_1 , TRUE ) ;
}
void F_44 ( T_13 V_47 , void * V_21 ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_1 -> V_34 ; V_16 ++ )
V_47 ( F_23 ( V_1 , V_16 ) , V_21 ) ;
}
void F_45 ( void ) {
T_4 V_16 ;
T_11 * V_67 ;
for ( V_16 = 0 ; V_16 < V_1 -> V_34 ; V_16 ++ ) {
T_1 * V_43 = F_23 ( V_1 , V_16 ) ;
V_67 = NULL ;
if ( ! V_43 -> V_23 )
F_46 ( V_43 , & V_67 ) ;
if ( V_67 ) {
F_47 ( L_9 , V_43 -> V_2 , V_67 ) ;
}
}
}
T_3 F_48 ( void * T_14 V_68 , const char * V_69 , unsigned V_34 V_68 , const void * T_15 V_68 , const void * T_16 V_68 , const char * * V_67 ) {
if ( V_69 == NULL ) {
* V_67 = L_10 ;
return FALSE ;
}
* V_67 = NULL ;
return TRUE ;
}
T_3 F_49 ( void * T_14 V_68 , const char * V_69 , unsigned V_34 , const void * T_15 V_68 , const void * T_16 V_68 , const char * * V_67 ) {
unsigned int V_16 ;
* V_67 = NULL ;
if ( V_69 == NULL ) {
* V_67 = L_10 ;
return FALSE ;
}
for( V_16 = 0 ; V_16 < V_34 ; V_16 ++ )
if( ! ( isdigit ( V_69 [ V_16 ] ) || V_69 [ V_16 ] == '.' ) ) {
* V_67 = L_11 ;
break;
}
if( V_69 [ V_34 - 1 ] == '.' )
* V_67 = L_12 ;
if( ! ( ( * V_69 == '0' || * V_69 == '1' || * V_69 == '2' ) && ( V_34 > 1 && V_69 [ 1 ] == '.' ) ) )
* V_67 = L_13 ;
return * V_67 == NULL ;
}
T_3 F_50 ( void * T_14 V_68 , const char * V_69 , unsigned V_34 , const void * T_15 V_68 , const void * T_16 V_68 , const char * * V_67 ) {
if ( V_34 ) {
char * V_2 = F_51 ( V_69 , V_34 ) ;
F_52 ( V_2 ) ;
F_53 ( V_2 ) ;
if ( F_54 ( V_2 ) ) {
* V_67 = NULL ;
return TRUE ;
} else {
* V_67 = L_14 ;
return FALSE ;
}
} else {
* V_67 = NULL ;
return TRUE ;
}
}
T_3 F_55 ( void * T_14 V_68 , const char * V_69 , unsigned V_34 , const void * T_15 V_68 , const void * T_16 V_68 , const char * * V_67 ) {
if ( V_34 > 0 ) {
char * V_70 = F_51 ( V_69 , V_34 ) ;
long V_16 = strtol ( V_70 , & V_70 , 10 ) ;
if ( ( V_16 == 0 ) && ( V_61 == V_71 || V_61 == V_72 ) ) {
* V_67 = F_31 ( V_61 ) ;
return FALSE ;
}
}
* V_67 = NULL ;
return TRUE ;
}
T_3 F_56 ( void * T_14 V_68 , const char * V_69 , unsigned V_34 , const void * T_15 V_68 , const void * T_16 V_68 , const char * * V_67 ) {
if ( V_34 > 0 ) {
char * V_70 = F_51 ( V_69 , V_34 ) ;
long V_16 = strtol ( V_70 , & V_70 , 16 ) ;
if ( ( V_16 == 0 ) && ( V_61 == V_71 || V_61 == V_72 ) ) {
* V_67 = F_31 ( V_61 ) ;
return FALSE ;
}
}
* V_67 = NULL ;
return TRUE ;
}
T_3 F_57 ( void * T_14 V_68 , const char * V_69 , unsigned V_34 , const void * V_73 , const void * T_16 V_68 , const char * * V_67 ) {
char * V_70 = F_51 ( V_69 , V_34 ) ;
T_4 V_16 ;
const T_17 * V_74 = V_73 ;
for( V_16 = 0 ; V_74 [ V_16 ] . V_69 ; V_16 ++ ) {
if ( F_24 ( V_74 [ V_16 ] . V_69 , V_70 ) ) {
* V_67 = NULL ;
return TRUE ;
}
}
* V_67 = F_30 ( L_15 , V_70 ) ;
return FALSE ;
}
T_3 F_58 ( void * T_14 V_68 , const char * V_69 , unsigned V_34 , const void * V_73 V_68 , const void * T_16 , const char * * V_67 ) {
char * V_70 = F_51 ( V_69 , V_34 ) ;
T_18 * V_75 = NULL ;
T_19 V_76 = F_59 ( & V_75 , V_70 , F_60 ( T_16 ) ) ;
switch ( V_76 ) {
case V_77 :
* V_67 = NULL ;
return TRUE ;
case V_78 :
* V_67 = F_30 ( L_16 , V_70 ) ;
return FALSE ;
case V_79 :
* V_67 = F_30 ( L_17 , V_70 , F_60 ( T_16 ) ) ;
return FALSE ;
default:
* V_67 = L_18 ;
return FALSE ;
}
}
static int F_61 ( char V_80 ) {
switch( V_80 ) {
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
char * F_62 ( const char * V_81 , T_4 V_82 , T_4 * V_65 ) {
V_59 * V_83 ;
T_4 V_34 = V_82 / 2 ;
int V_16 = 0 ;
int V_84 , V_85 ;
if ( V_82 % 2 ) {
return NULL ;
}
V_83 = F_63 ( V_34 + 1 ) ;
if ( V_65 ) * V_65 = V_34 ;
while( V_82 ) {
V_85 = F_61 ( * ( V_81 ++ ) ) ;
V_84 = F_61 ( * ( V_81 ++ ) ) ;
V_83 [ V_16 ++ ] = ( V_85 * 16 ) + V_84 ;
V_82 -= 2 ;
}
return ( char * ) V_83 ;
}
char * F_64 ( const char * V_81 , T_4 V_82 , T_4 * V_65 ) {
char * V_83 = F_63 ( V_82 + 1 ) ;
char * V_86 = V_83 ;
T_4 V_34 = 0 ;
const char * V_37 ;
const char * V_87 = V_81 + V_82 ;
for ( V_37 = ( void * ) V_81 ; V_37 < V_87 ; V_37 ++ ) {
switch( * V_37 ) {
case '\\' :
switch( * ( ++ V_37 ) ) {
case 'a' : * ( V_86 ++ ) = '\a' ; V_34 ++ ; break;
case 'b' : * ( V_86 ++ ) = '\b' ; V_34 ++ ; break;
case 'e' : * ( V_86 ++ ) = '\033' ; V_34 ++ ; break;
case 'f' : * ( V_86 ++ ) = '\f' ; V_34 ++ ; break;
case 'n' : * ( V_86 ++ ) = '\n' ; V_34 ++ ; break;
case 'r' : * ( V_86 ++ ) = '\r' ; V_34 ++ ; break;
case 't' : * ( V_86 ++ ) = '\t' ; V_34 ++ ; break;
case 'v' : * ( V_86 ++ ) = '\v' ; V_34 ++ ; break;
case '0' :
case '1' :
case '2' :
case '3' :
case '4' :
case '5' :
case '6' :
case '7' :
{
int V_88 = 0 ;
int V_89 = 0 ;
int V_90 = 0 ;
int V_56 = 0 ;
V_88 = ( * V_37 ) - '0' ;
if ( V_37 [ 1 ] >= '0' && V_37 [ 1 ] <= '7' ) {
V_89 = V_88 ;
V_88 = ( * ++ V_37 ) - '0' ;
if ( V_37 [ 1 ] >= '0' && V_37 [ 1 ] <= '7' ) {
V_90 = V_89 ;
V_89 = V_88 ;
V_88 = ( * ++ V_37 ) - '0' ;
}
}
V_56 = ( 64 * V_90 ) + ( 8 * V_89 ) + V_88 ;
* ( V_86 ++ ) = ( char ) ( V_56 > 255 ? 255 : V_56 ) ;
V_34 ++ ;
break;
}
case 'x' :
{
char V_89 = * ( V_37 + 1 ) ;
char V_88 = * ( V_37 + 2 ) ;
if ( isxdigit ( ( V_57 ) V_89 ) && isxdigit ( ( V_57 ) V_88 ) ) {
* ( V_86 ++ ) = ( F_61 ( V_89 ) * 0x10 ) + F_61 ( V_88 ) ;
V_37 += 2 ;
} else {
* ( V_86 ++ ) = * V_37 ;
}
V_34 ++ ;
break;
}
default:
* V_86 ++ = * V_37 ;
break;
}
break;
default:
* ( V_86 ++ ) = * V_37 ;
V_34 ++ ;
break;
}
}
if ( V_65 ) * V_65 = V_34 ;
return V_83 ;
}
char * F_65 ( const char * V_81 , T_4 V_82 , T_4 * V_65 ) {
return F_64 ( V_81 + 1 , V_82 - 2 , V_65 ) ;
}
char * F_66 ( const char * V_83 , T_4 V_34 ) {
const V_59 * V_91 = ( ( V_59 * ) V_83 ) + V_34 ;
char * V_92 = F_67 ( ( 4 * V_34 ) + 1 ) ;
const V_59 * V_36 ;
char * V_37 = V_92 ;
for ( V_36 = ( void * ) V_83 ; V_36 < V_91 ; V_36 ++ ) {
if ( isprint ( * V_36 ) ) {
* ( V_37 ++ ) = ( * V_36 ) ;
} else {
F_68 ( V_37 , 5 , L_1 , ( ( T_4 ) * V_36 ) ) ;
V_37 += 4 ;
}
}
return V_92 ;
}
