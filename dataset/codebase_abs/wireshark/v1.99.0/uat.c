void F_1 ( void ) {
V_1 = F_2 () ;
}
T_1 * F_3 ( const char * V_2 ,
T_2 V_3 ,
const char * V_4 ,
T_3 V_5 ,
void * V_6 ,
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
V_15 -> V_18 = ( void * * ) V_6 ;
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
* ( ( void * * ) V_6 ) = NULL ;
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
case V_60 :
case V_61 : {
T_4 V_16 ;
putc ( '"' , V_49 ) ;
for( V_16 = 0 ; V_16 < V_50 ; V_16 ++ ) {
char V_62 = V_51 [ V_16 ] ;
if ( V_62 == '"' || V_62 == '\\' || ! F_26 ( ( V_63 ) V_62 ) ) {
fprintf ( V_49 , L_1 , V_62 ) ;
} else {
putc ( V_62 , V_49 ) ;
}
}
putc ( '"' , V_49 ) ;
return;
}
case V_64 : {
T_4 V_16 ;
for( V_16 = 0 ; V_16 < V_50 ; V_16 ++ ) {
fprintf ( V_49 , L_2 , ( ( const V_65 * ) V_51 ) [ V_16 ] ) ;
}
return;
}
default:
F_27 () ;
}
}
T_3 F_28 ( T_1 * V_15 , const char * * error ) {
T_4 V_16 ;
T_11 * V_66 = F_17 ( V_15 , TRUE ) ;
T_12 * V_49 ;
if ( ! V_66 ) return FALSE ;
V_49 = F_29 ( V_66 , L_3 ) ;
if ( ! V_49 && V_67 == V_68 ) {
T_11 * V_69 = NULL ;
if ( F_30 ( & V_69 ) != 0 ) {
* error = F_31 ( L_4 , V_69 ) ;
F_21 ( V_69 ) ;
return FALSE ;
}
V_49 = F_29 ( V_66 , L_3 ) ;
}
if ( ! V_49 ) {
* error = F_31 ( L_5 , V_66 , F_32 ( V_67 ) ) ;
return FALSE ;
}
* error = NULL ;
F_21 ( V_66 ) ;
for ( V_16 = 0 ; V_16 < V_15 -> V_21 -> V_38 ; V_16 ++ ) {
if ( V_15 -> V_12 ) {
V_15 -> V_12 ( F_33 ( V_15 , V_16 ) ) ;
}
}
F_34 ( V_15 -> V_21 , 0 ) ;
* ( ( V_15 ) -> V_18 ) = NULL ;
* ( ( V_15 ) -> V_19 ) = 0 ;
for ( V_16 = 0 ; V_16 < V_15 -> V_22 -> V_38 ; V_16 ++ ) {
void * V_36 = V_15 -> V_22 -> V_34 + ( V_15 -> V_17 * V_16 ) ;
T_3 * V_37 = ( T_3 * ) ( V_15 -> V_23 -> V_34 + sizeof( T_3 ) * V_16 ) ;
if ( * V_37 ) {
F_10 ( V_15 -> V_21 , V_36 , 1 ) ;
if ( V_15 -> V_10 ) {
V_15 -> V_10 ( F_33 ( V_15 , V_16 ) , V_36 , ( unsigned int ) V_15 -> V_17 ) ;
}
F_11 ( V_15 ) ;
}
}
fprintf ( V_49 , L_6 ) ;
for ( V_16 = 0 ; V_16 < V_15 -> V_21 -> V_38 ; V_16 ++ ) {
void * V_36 = V_15 -> V_21 -> V_34 + ( V_15 -> V_17 * V_16 ) ;
T_9 * V_30 ;
T_4 V_70 ;
V_30 = V_15 -> V_20 ;
for( V_70 = 0 ; V_70 < V_15 -> V_33 ; V_70 ++ ) {
F_25 ( V_49 , V_36 , & ( V_30 [ V_70 ] ) ) ;
fputs ( ( V_70 == V_15 -> V_33 - 1 ) ? L_7 : L_8 , V_49 ) ;
}
}
fclose ( V_49 ) ;
V_15 -> V_24 = FALSE ;
return TRUE ;
}
void F_35 ( T_1 * V_15 ) {
F_36 ( V_1 , V_15 ) ;
}
T_1 * F_37 ( T_11 * V_2 ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_1 -> V_38 ; V_16 ++ ) {
T_1 * V_48 = ( T_1 * ) F_23 ( V_1 , V_16 ) ;
if ( strcmp ( V_48 -> V_2 , V_2 ) == 0 || strcmp ( V_48 -> V_4 , V_2 ) == 0 ) {
return V_48 ;
}
}
return NULL ;
}
void F_38 ( T_1 * V_15 ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_15 -> V_21 -> V_38 ; V_16 ++ ) {
if ( V_15 -> V_12 ) {
V_15 -> V_12 ( F_33 ( V_15 , V_16 ) ) ;
}
}
for ( V_16 = 0 ; V_16 < V_15 -> V_22 -> V_38 ; V_16 ++ ) {
if ( V_15 -> V_12 ) {
V_15 -> V_12 ( F_14 ( V_15 , V_16 ) ) ;
}
}
F_34 ( V_15 -> V_22 , 0 ) ;
F_34 ( V_15 -> V_21 , 0 ) ;
F_34 ( V_15 -> V_23 , 0 ) ;
* ( ( V_15 ) -> V_18 ) = NULL ;
* ( ( V_15 ) -> V_19 ) = 0 ;
}
void F_39 ( void ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_1 -> V_38 ; V_16 ++ ) {
T_1 * V_48 = ( T_1 * ) F_23 ( V_1 , V_16 ) ;
if ( V_48 -> V_5 ) {
F_38 ( V_48 ) ;
V_48 -> V_25 = FALSE ;
}
}
}
void F_40 ( T_13 V_52 , void * V_21 ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_1 -> V_38 ; V_16 ++ )
V_52 ( F_23 ( V_1 , V_16 ) , V_21 ) ;
}
void F_41 ( void ) {
T_4 V_16 ;
const T_11 * V_71 ;
for ( V_16 = 0 ; V_16 < V_1 -> V_38 ; V_16 ++ ) {
T_1 * V_48 = ( T_1 * ) F_23 ( V_1 , V_16 ) ;
V_71 = NULL ;
if ( ! V_48 -> V_25 )
F_42 ( V_48 , & V_71 ) ;
if ( V_71 ) {
F_43 ( L_9 , V_48 -> V_2 , V_71 ) ;
}
}
}
T_3 F_44 ( void * T_14 V_72 , const char * V_73 , T_4 V_38 V_72 , const void * T_15 V_72 , const void * T_16 V_72 , const char * * V_71 ) {
if ( V_73 == NULL ) {
* V_71 = L_10 ;
return FALSE ;
}
* V_71 = NULL ;
return TRUE ;
}
T_3 F_45 ( void * T_14 V_72 , const char * V_73 , T_4 V_38 , const void * T_15 V_72 , const void * T_16 V_72 , const char * * V_71 ) {
unsigned int V_16 ;
* V_71 = NULL ;
if ( V_73 == NULL ) {
* V_71 = L_10 ;
return FALSE ;
}
for( V_16 = 0 ; V_16 < V_38 ; V_16 ++ )
if( ! ( isdigit ( V_73 [ V_16 ] ) || V_73 [ V_16 ] == '.' ) ) {
* V_71 = L_11 ;
break;
}
if( V_73 [ V_38 - 1 ] == '.' )
* V_71 = L_12 ;
if( ! ( ( * V_73 == '0' || * V_73 == '1' || * V_73 == '2' ) && ( V_38 > 1 && V_73 [ 1 ] == '.' ) ) )
* V_71 = L_13 ;
return * V_71 == NULL ;
}
T_3 F_46 ( void * T_14 V_72 , const char * V_73 , T_4 V_38 , const void * T_15 V_72 , const void * T_16 V_72 , const char * * V_71 ) {
if ( V_38 ) {
char * V_2 = F_47 ( V_73 , V_38 ) ;
F_48 ( V_2 ) ;
F_49 ( V_2 ) ;
if ( F_50 ( V_2 ) ) {
* V_71 = NULL ;
return TRUE ;
} else {
* V_71 = L_14 ;
return FALSE ;
}
} else {
* V_71 = NULL ;
return TRUE ;
}
}
T_3 F_51 ( void * T_14 V_72 , const char * V_73 , T_4 V_38 , const void * T_15 V_72 , const void * T_16 V_72 , const char * * V_71 ) {
if ( V_38 > 0 ) {
char * V_74 = F_47 ( V_73 , V_38 ) ;
long V_16 = strtol ( V_74 , & V_74 , 10 ) ;
if ( ( V_16 == 0 ) && ( V_67 == V_75 || V_67 == V_76 ) ) {
* V_71 = F_32 ( V_67 ) ;
return FALSE ;
}
}
* V_71 = NULL ;
return TRUE ;
}
T_3 F_52 ( void * T_14 V_72 , const char * V_73 , T_4 V_38 , const void * T_15 V_72 , const void * T_16 V_72 , const char * * V_71 ) {
if ( V_38 > 0 ) {
char * V_74 = F_47 ( V_73 , V_38 ) ;
long V_16 = strtol ( V_74 , & V_74 , 16 ) ;
if ( ( V_16 == 0 ) && ( V_67 == V_75 || V_67 == V_76 ) ) {
* V_71 = F_32 ( V_67 ) ;
return FALSE ;
}
}
* V_71 = NULL ;
return TRUE ;
}
T_3 F_53 ( void * T_14 V_72 , const char * V_73 , T_4 V_38 , const void * V_77 , const void * T_16 V_72 , const char * * V_71 ) {
char * V_74 = F_47 ( V_73 , V_38 ) ;
T_4 V_16 ;
const T_17 * V_78 = ( const T_17 * ) V_77 ;
for( V_16 = 0 ; V_78 [ V_16 ] . V_73 ; V_16 ++ ) {
if ( F_24 ( V_78 [ V_16 ] . V_73 , V_74 ) ) {
* V_71 = NULL ;
return TRUE ;
}
}
* V_71 = F_31 ( L_15 , V_74 ) ;
return FALSE ;
}
T_3 F_54 ( void * T_14 V_72 , const char * V_73 , T_4 V_38 , const void * V_77 V_72 , const void * T_16 , const char * * V_71 ) {
char * V_74 = F_47 ( V_73 , V_38 ) ;
T_18 * V_79 = NULL ;
T_19 V_80 = F_55 ( & V_79 , V_74 , F_56 ( T_16 ) ) ;
switch ( V_80 ) {
case V_81 :
* V_71 = NULL ;
return TRUE ;
case V_82 :
* V_71 = F_31 ( L_16 , V_74 ) ;
return FALSE ;
case V_83 :
* V_71 = F_31 ( L_17 , V_74 , F_56 ( T_16 ) ) ;
return FALSE ;
default:
* V_71 = L_18 ;
return FALSE ;
}
}
char * F_57 ( const char * V_84 , T_4 V_85 , T_4 * V_86 ) {
V_65 * V_87 ;
T_4 V_38 = V_85 / 2 ;
int V_16 = 0 ;
int V_88 , V_89 ;
if ( V_85 % 2 ) {
return NULL ;
}
V_87 = ( V_65 * ) F_58 ( V_38 + 1 ) ;
if ( V_86 ) * V_86 = V_38 ;
while( V_85 ) {
V_89 = F_59 ( * ( V_84 ++ ) ) ;
V_88 = F_59 ( * ( V_84 ++ ) ) ;
V_87 [ V_16 ++ ] = ( V_89 * 16 ) + V_88 ;
V_85 -= 2 ;
}
return ( char * ) V_87 ;
}
char * F_60 ( const char * V_84 , T_4 V_85 , T_4 * V_86 ) {
char * V_87 = ( char * ) F_58 ( V_85 + 1 ) ;
char * V_90 = V_87 ;
T_4 V_38 = 0 ;
const char * V_41 ;
const char * V_91 = V_84 + V_85 ;
for ( V_41 = ( const char * ) V_84 ; V_41 < V_91 ; V_41 ++ ) {
switch( * V_41 ) {
case '\\' :
switch( * ( ++ V_41 ) ) {
case 'a' : * ( V_90 ++ ) = '\a' ; V_38 ++ ; break;
case 'b' : * ( V_90 ++ ) = '\b' ; V_38 ++ ; break;
case 'e' : * ( V_90 ++ ) = '\033' ; V_38 ++ ; break;
case 'f' : * ( V_90 ++ ) = '\f' ; V_38 ++ ; break;
case 'n' : * ( V_90 ++ ) = '\n' ; V_38 ++ ; break;
case 'r' : * ( V_90 ++ ) = '\r' ; V_38 ++ ; break;
case 't' : * ( V_90 ++ ) = '\t' ; V_38 ++ ; break;
case 'v' : * ( V_90 ++ ) = '\v' ; V_38 ++ ; break;
case '0' :
case '1' :
case '2' :
case '3' :
case '4' :
case '5' :
case '6' :
case '7' :
{
int V_92 = 0 ;
int V_93 = 0 ;
int V_94 = 0 ;
int V_62 = 0 ;
V_92 = ( * V_41 ) - '0' ;
if ( V_41 [ 1 ] >= '0' && V_41 [ 1 ] <= '7' ) {
V_93 = V_92 ;
V_92 = ( * ++ V_41 ) - '0' ;
if ( V_41 [ 1 ] >= '0' && V_41 [ 1 ] <= '7' ) {
V_94 = V_93 ;
V_93 = V_92 ;
V_92 = ( * ++ V_41 ) - '0' ;
}
}
V_62 = ( 64 * V_94 ) + ( 8 * V_93 ) + V_92 ;
* ( V_90 ++ ) = ( char ) ( V_62 > 255 ? 255 : V_62 ) ;
V_38 ++ ;
break;
}
case 'x' :
{
char V_93 = * ( V_41 + 1 ) ;
char V_92 = * ( V_41 + 2 ) ;
if ( isxdigit ( ( V_63 ) V_93 ) && isxdigit ( ( V_63 ) V_92 ) ) {
* ( V_90 ++ ) = ( F_59 ( V_93 ) * 0x10 ) + F_59 ( V_92 ) ;
V_41 += 2 ;
} else {
* ( V_90 ++ ) = * V_41 ;
}
V_38 ++ ;
break;
}
default:
* V_90 ++ = * V_41 ;
break;
}
break;
default:
* ( V_90 ++ ) = * V_41 ;
V_38 ++ ;
break;
}
}
if ( V_86 ) * V_86 = V_38 ;
return V_87 ;
}
char * F_61 ( const char * V_84 , T_4 V_85 , T_4 * V_86 ) {
return F_60 ( V_84 + 1 , V_85 - 2 , V_86 ) ;
}
char * F_62 ( const char * V_87 , T_4 V_38 ) {
const V_65 * V_95 = ( ( const V_65 * ) V_87 ) + V_38 ;
char * V_96 = ( char * ) F_63 ( ( 4 * V_38 ) + 1 ) ;
const V_65 * V_40 ;
char * V_41 = V_96 ;
for ( V_40 = ( const V_65 * ) V_87 ; V_40 < V_95 ; V_40 ++ ) {
if ( F_26 ( * V_40 ) ) {
* ( V_41 ++ ) = ( * V_40 ) ;
} else {
F_64 ( V_41 , 5 , L_1 , ( ( T_4 ) * V_40 ) ) ;
V_41 += 4 ;
}
}
return V_96 ;
}
