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
V_36 = F_11 ( V_15 , V_15 -> V_22 -> V_38 - 1 ) ;
if ( V_15 -> V_10 ) {
V_15 -> V_10 ( V_36 , V_34 , ( unsigned int ) V_15 -> V_17 ) ;
}
if ( V_35 ) {
F_10 ( V_15 -> V_21 , V_34 , 1 ) ;
V_36 = F_12 ( V_15 , V_15 -> V_21 -> V_38 - 1 ) ;
if ( V_15 -> V_10 ) {
V_15 -> V_10 ( V_36 , V_34 , ( unsigned int ) V_15 -> V_17 ) ;
}
F_13 ( V_15 ) ;
} else {
V_36 = NULL ;
}
F_10 ( V_15 -> V_23 , & V_35 , 1 ) ;
V_37 = & F_14 ( V_15 -> V_23 , T_3 , V_15 -> V_23 -> V_38 - 1 ) ;
* V_37 = V_35 ;
return V_36 ;
}
void F_15 ( T_1 * V_15 , const void * V_34 , T_3 V_35 ) {
T_4 V_39 ;
T_3 * V_37 ;
for ( V_39 = 0 ; V_39 < V_15 -> V_22 -> V_38 ; V_39 ++ ) {
if ( F_11 ( V_15 , V_39 ) == V_34 ) {
break;
}
}
if ( V_39 == V_15 -> V_22 -> V_38 ) {
F_16 () ;
}
V_37 = & F_14 ( V_15 -> V_23 , T_3 , V_39 ) ;
* V_37 = V_35 ;
}
void F_17 ( T_1 * V_15 , T_4 V_40 , T_4 V_41 ) {
T_2 V_42 = V_15 -> V_17 ;
void * V_43 ;
T_3 V_44 ;
F_6 ( V_40 < V_15 -> V_22 -> V_38 && V_41 < V_15 -> V_22 -> V_38 ) ;
if ( V_40 == V_41 ) return;
V_43 = F_4 ( V_42 ) ;
memcpy ( V_43 , F_11 ( V_15 , V_40 ) , V_42 ) ;
memcpy ( F_11 ( V_15 , V_40 ) , F_11 ( V_15 , V_41 ) , V_42 ) ;
memcpy ( F_11 ( V_15 , V_41 ) , V_43 , V_42 ) ;
F_18 ( V_43 ) ;
V_44 = * ( T_3 * ) ( V_15 -> V_23 -> V_34 + ( sizeof( T_3 ) * ( V_40 ) ) ) ;
* ( T_3 * ) ( V_15 -> V_23 -> V_34 + ( sizeof( T_3 ) * ( V_40 ) ) ) = * ( T_3 * ) ( V_15 -> V_23 -> V_34 + ( sizeof( T_3 ) * ( V_41 ) ) ) ;
* ( T_3 * ) ( V_15 -> V_23 -> V_34 + ( sizeof( T_3 ) * ( V_41 ) ) ) = V_44 ;
}
void F_19 ( T_1 * V_15 , T_4 V_45 ) {
F_6 ( V_45 < V_15 -> V_22 -> V_38 ) ;
if ( V_15 -> V_12 ) {
V_15 -> V_12 ( F_11 ( V_15 , V_45 ) ) ;
}
F_20 ( V_15 -> V_22 , V_45 ) ;
F_20 ( V_15 -> V_23 , V_45 ) ;
}
T_11 * F_21 ( T_1 * V_15 , T_3 V_46 ) {
T_11 * V_47 = NULL ;
if ( ! V_15 -> V_26 ) {
V_47 = F_22 ( V_15 -> V_4 , V_15 -> V_5 ) ;
}
if ( ( ! V_46 ) && ( ! F_23 ( V_47 ) ) ) {
T_11 * V_48 = F_24 ( V_15 -> V_4 ) ;
if ( F_23 ( V_48 ) ) {
F_18 ( V_47 ) ;
return V_48 ;
}
F_18 ( V_48 ) ;
F_18 ( V_47 ) ;
return NULL ;
}
return V_47 ;
}
T_1 * F_25 ( const char * V_2 ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_1 -> V_38 ; V_16 ++ ) {
T_1 * V_49 = ( T_1 * ) F_26 ( V_1 , V_16 ) ;
if ( F_27 ( V_49 -> V_2 , V_2 ) ) {
return ( V_49 ) ;
}
}
return NULL ;
}
static void F_28 ( T_12 * V_50 , void * V_36 , T_9 * V_30 ) {
T_4 V_51 ;
char * V_52 ;
V_30 -> V_53 . V_54 ( V_36 , & V_52 , & V_51 , V_30 -> V_55 . V_54 , V_30 -> V_56 ) ;
switch( V_30 -> V_57 ) {
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 : {
T_4 V_16 ;
putc ( '"' , V_50 ) ;
for( V_16 = 0 ; V_16 < V_51 ; V_16 ++ ) {
char V_63 = V_52 [ V_16 ] ;
if ( V_63 == '"' || V_63 == '\\' || ! F_29 ( ( V_64 ) V_63 ) ) {
fprintf ( V_50 , L_1 , ( V_64 ) V_63 ) ;
} else {
putc ( V_63 , V_50 ) ;
}
}
putc ( '"' , V_50 ) ;
break;
}
case V_65 : {
T_4 V_16 ;
for( V_16 = 0 ; V_16 < V_51 ; V_16 ++ ) {
fprintf ( V_50 , L_2 , ( V_64 ) V_52 [ V_16 ] ) ;
}
break;
}
default:
F_16 () ;
}
F_18 ( V_52 ) ;
}
T_3 F_30 ( T_1 * V_15 , char * * error ) {
T_4 V_16 ;
T_11 * V_66 = F_21 ( V_15 , TRUE ) ;
T_12 * V_50 ;
if ( ! V_66 ) return FALSE ;
V_50 = F_31 ( V_66 , L_3 ) ;
if ( ! V_50 && V_67 == V_68 ) {
T_11 * V_69 = NULL ;
if ( F_32 ( & V_69 ) != 0 ) {
* error = F_33 ( L_4 , V_69 ) ;
F_18 ( V_69 ) ;
return FALSE ;
}
V_50 = F_31 ( V_66 , L_3 ) ;
}
if ( ! V_50 ) {
* error = F_33 ( L_5 , V_66 , F_34 ( V_67 ) ) ;
return FALSE ;
}
* error = NULL ;
F_18 ( V_66 ) ;
for ( V_16 = 0 ; V_16 < V_15 -> V_21 -> V_38 ; V_16 ++ ) {
if ( V_15 -> V_12 ) {
V_15 -> V_12 ( F_12 ( V_15 , V_16 ) ) ;
}
}
F_35 ( V_15 -> V_21 , 0 ) ;
* ( ( V_15 ) -> V_18 ) = NULL ;
* ( ( V_15 ) -> V_19 ) = 0 ;
for ( V_16 = 0 ; V_16 < V_15 -> V_22 -> V_38 ; V_16 ++ ) {
void * V_36 = F_11 ( V_15 , V_16 ) ;
T_3 * V_37 = ( T_3 * ) ( V_15 -> V_23 -> V_34 + sizeof( T_3 ) * V_16 ) ;
if ( * V_37 ) {
F_10 ( V_15 -> V_21 , V_36 , 1 ) ;
if ( V_15 -> V_10 ) {
V_15 -> V_10 ( F_12 ( V_15 , V_15 -> V_21 -> V_38 - 1 ) ,
V_36 , ( unsigned int ) V_15 -> V_17 ) ;
}
F_13 ( V_15 ) ;
}
}
fprintf ( V_50 , L_6 ) ;
for ( V_16 = 0 ; V_16 < V_15 -> V_21 -> V_38 ; V_16 ++ ) {
void * V_36 = V_15 -> V_21 -> V_34 + ( V_15 -> V_17 * V_16 ) ;
T_9 * V_30 ;
T_4 V_70 ;
V_30 = V_15 -> V_20 ;
for( V_70 = 0 ; V_70 < V_15 -> V_33 ; V_70 ++ ) {
F_28 ( V_50 , V_36 , & ( V_30 [ V_70 ] ) ) ;
fputs ( ( V_70 == V_15 -> V_33 - 1 ) ? L_7 : L_8 , V_50 ) ;
}
}
fclose ( V_50 ) ;
V_15 -> V_24 = FALSE ;
return TRUE ;
}
void F_36 ( T_1 * V_15 ) {
F_37 ( V_1 , V_15 ) ;
}
T_1 * F_38 ( T_11 * V_2 ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_1 -> V_38 ; V_16 ++ ) {
T_1 * V_49 = ( T_1 * ) F_26 ( V_1 , V_16 ) ;
if ( strcmp ( V_49 -> V_2 , V_2 ) == 0 || strcmp ( V_49 -> V_4 , V_2 ) == 0 ) {
return V_49 ;
}
}
return NULL ;
}
void F_39 ( T_1 * V_15 ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_15 -> V_21 -> V_38 ; V_16 ++ ) {
if ( V_15 -> V_12 ) {
V_15 -> V_12 ( F_12 ( V_15 , V_16 ) ) ;
}
}
for ( V_16 = 0 ; V_16 < V_15 -> V_22 -> V_38 ; V_16 ++ ) {
if ( V_15 -> V_12 ) {
V_15 -> V_12 ( F_11 ( V_15 , V_16 ) ) ;
}
}
F_35 ( V_15 -> V_22 , 0 ) ;
F_35 ( V_15 -> V_21 , 0 ) ;
F_35 ( V_15 -> V_23 , 0 ) ;
* ( ( V_15 ) -> V_18 ) = NULL ;
* ( ( V_15 ) -> V_19 ) = 0 ;
}
void F_40 ( void ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_1 -> V_38 ; V_16 ++ ) {
T_1 * V_49 = ( T_1 * ) F_26 ( V_1 , V_16 ) ;
if ( V_49 -> V_5 ) {
F_39 ( V_49 ) ;
V_49 -> V_25 = FALSE ;
}
}
}
void F_41 ( T_13 V_53 , void * V_21 ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_1 -> V_38 ; V_16 ++ )
V_53 ( F_26 ( V_1 , V_16 ) , V_21 ) ;
}
void F_42 ( void ) {
T_4 V_16 ;
T_11 * V_71 ;
for ( V_16 = 0 ; V_16 < V_1 -> V_38 ; V_16 ++ ) {
T_1 * V_49 = ( T_1 * ) F_26 ( V_1 , V_16 ) ;
if ( ! V_49 -> V_25 ) {
V_71 = NULL ;
if ( ! F_43 ( V_49 , & V_71 ) ) {
F_44 ( L_9 , V_49 -> V_2 , V_71 ) ;
F_18 ( V_71 ) ;
}
}
}
}
T_3 F_45 ( void * T_14 V_72 , const char * V_73 , T_4 V_38 V_72 , const void * T_15 V_72 , const void * T_16 V_72 , char * * V_71 ) {
if ( V_73 == NULL ) {
* V_71 = F_7 ( L_10 ) ;
return FALSE ;
}
* V_71 = NULL ;
return TRUE ;
}
T_3 F_46 ( void * T_14 V_72 , const char * V_73 , T_4 V_38 , const void * T_15 V_72 , const void * T_16 V_72 , char * * V_71 ) {
unsigned int V_16 ;
* V_71 = NULL ;
if ( V_73 == NULL ) {
* V_71 = F_7 ( L_10 ) ;
return FALSE ;
}
if ( V_38 == 0 ) {
* V_71 = F_7 ( L_11 ) ;
return FALSE ;
}
for( V_16 = 0 ; V_16 < V_38 ; V_16 ++ )
if( ! ( F_47 ( V_73 [ V_16 ] ) || V_73 [ V_16 ] == '.' ) ) {
* V_71 = F_7 ( L_12 ) ;
return FALSE ;
}
if( V_73 [ V_38 - 1 ] == '.' ) {
* V_71 = F_7 ( L_13 ) ;
return FALSE ;
}
if( ! ( ( * V_73 == '0' || * V_73 == '1' || * V_73 == '2' ) && ( V_38 > 1 && V_73 [ 1 ] == '.' ) ) ) {
* V_71 = F_7 ( L_14 ) ;
return FALSE ;
}
return * V_71 == NULL ;
}
T_3 F_48 ( void * T_14 V_72 , const char * V_73 , T_4 V_38 , const void * T_15 V_72 , const void * T_16 V_72 , char * * V_71 ) {
if ( V_38 ) {
char * V_2 = F_49 ( V_73 , V_38 ) ;
F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
if ( F_52 ( V_2 ) ) {
* V_71 = NULL ;
F_18 ( V_2 ) ;
return TRUE ;
} else {
* V_71 = F_7 ( L_15 ) ;
F_18 ( V_2 ) ;
return FALSE ;
}
} else {
* V_71 = NULL ;
return TRUE ;
}
}
static T_3 F_53 ( int V_74 , const char * V_73 , T_4 V_38 , char * * V_71 ) {
if ( V_38 > 0 ) {
char * V_75 = F_49 ( V_73 , V_38 ) ;
char * V_76 ;
long V_16 ;
V_67 = 0 ;
V_16 = strtol ( V_75 , & V_76 , V_74 ) ;
if ( ( ( V_16 == V_77 || V_16 == V_78 ) && V_67 == V_79 )
|| ( V_67 != 0 && V_16 == 0 ) ) {
* V_71 = F_7 ( F_34 ( V_67 ) ) ;
F_18 ( V_75 ) ;
return FALSE ;
}
if ( ( * V_76 != '\0' ) && ( * V_76 != ' ' ) ) {
* V_71 = F_7 ( L_16 ) ;
F_18 ( V_75 ) ;
return FALSE ;
}
if ( ( sizeof( long ) > 4 ) && ( ( V_16 < V_80 ) || ( V_16 > V_81 ) ) ) {
* V_71 = F_7 ( L_17 ) ;
F_18 ( V_75 ) ;
return FALSE ;
}
F_18 ( V_75 ) ;
}
* V_71 = NULL ;
return TRUE ;
}
T_3 F_54 ( void * T_14 V_72 , const char * V_73 , T_4 V_38 , const void * T_15 V_72 , const void * T_16 V_72 , char * * V_71 ) {
return F_53 ( 10 , V_73 , V_38 , V_71 ) ;
}
T_3 F_55 ( void * T_14 V_72 , const char * V_73 , T_4 V_38 , const void * T_15 V_72 , const void * T_16 V_72 , char * * V_71 ) {
return F_53 ( 16 , V_73 , V_38 , V_71 ) ;
}
T_3 F_56 ( void * T_14 V_72 , const char * V_73 , T_4 V_38 , const void * V_82 , const void * T_16 V_72 , char * * V_71 ) {
char * V_75 = F_49 ( V_73 , V_38 ) ;
T_4 V_16 ;
const T_17 * V_83 = ( const T_17 * ) V_82 ;
for( V_16 = 0 ; V_83 [ V_16 ] . V_73 ; V_16 ++ ) {
if ( F_27 ( V_83 [ V_16 ] . V_73 , V_75 ) ) {
* V_71 = NULL ;
F_18 ( V_75 ) ;
return TRUE ;
}
}
* V_71 = F_33 ( L_18 , V_75 ) ;
F_18 ( V_75 ) ;
return FALSE ;
}
T_3 F_57 ( void * T_14 V_72 , const char * V_73 , T_4 V_38 , const void * V_82 V_72 , const void * T_16 , char * * V_71 ) {
char * V_75 = F_49 ( V_73 , V_38 ) ;
T_18 * V_84 = NULL ;
T_19 V_85 = F_58 ( & V_84 , V_75 , F_59 ( T_16 ) ) ;
T_3 V_86 = FALSE ;
switch ( V_85 ) {
case V_87 :
* V_71 = NULL ;
V_86 = TRUE ;
break;
case V_88 :
* V_71 = F_33 ( L_19 , V_75 ) ;
V_86 = FALSE ;
break;
case V_89 :
* V_71 = F_33 ( L_20 , V_75 , F_59 ( T_16 ) ) ;
V_86 = FALSE ;
break;
default:
* V_71 = F_7 ( L_21 ) ;
V_86 = FALSE ;
break;
}
F_18 ( V_75 ) ;
return V_86 ;
}
char * F_60 ( const char * V_90 , T_4 V_91 , T_4 * V_92 ) {
T_20 * V_93 ;
T_4 V_38 = V_91 / 2 ;
int V_16 = 0 ;
int V_94 , V_95 ;
if ( V_91 % 2 ) {
return NULL ;
}
V_93 = ( T_20 * ) F_61 ( V_38 + 1 ) ;
if ( V_92 ) * V_92 = V_38 ;
while( V_91 ) {
V_95 = F_62 ( * ( V_90 ++ ) ) ;
V_94 = F_62 ( * ( V_90 ++ ) ) ;
V_93 [ V_16 ++ ] = ( V_95 * 16 ) + V_94 ;
V_91 -= 2 ;
}
return ( char * ) V_93 ;
}
char * F_63 ( const char * V_90 , T_4 V_91 , T_4 * V_92 ) {
char * V_93 = ( char * ) F_61 ( V_91 + 1 ) ;
char * V_96 = V_93 ;
T_4 V_38 = 0 ;
const char * V_42 ;
const char * V_97 = V_90 + V_91 ;
for ( V_42 = ( const char * ) V_90 ; V_42 < V_97 ; V_42 ++ ) {
switch( * V_42 ) {
case '\\' :
switch( * ( ++ V_42 ) ) {
case 'a' : * ( V_96 ++ ) = '\a' ; V_38 ++ ; break;
case 'b' : * ( V_96 ++ ) = '\b' ; V_38 ++ ; break;
case 'e' : * ( V_96 ++ ) = '\033' ; V_38 ++ ; break;
case 'f' : * ( V_96 ++ ) = '\f' ; V_38 ++ ; break;
case 'n' : * ( V_96 ++ ) = '\n' ; V_38 ++ ; break;
case 'r' : * ( V_96 ++ ) = '\r' ; V_38 ++ ; break;
case 't' : * ( V_96 ++ ) = '\t' ; V_38 ++ ; break;
case 'v' : * ( V_96 ++ ) = '\v' ; V_38 ++ ; break;
case '0' :
case '1' :
case '2' :
case '3' :
case '4' :
case '5' :
case '6' :
case '7' :
{
int V_98 = 0 ;
int V_99 = 0 ;
int V_100 = 0 ;
int V_63 = 0 ;
V_98 = ( * V_42 ) - '0' ;
if ( V_42 [ 1 ] >= '0' && V_42 [ 1 ] <= '7' ) {
V_99 = V_98 ;
V_98 = ( * ++ V_42 ) - '0' ;
if ( V_42 [ 1 ] >= '0' && V_42 [ 1 ] <= '7' ) {
V_100 = V_99 ;
V_99 = V_98 ;
V_98 = ( * ++ V_42 ) - '0' ;
}
}
V_63 = ( 64 * V_100 ) + ( 8 * V_99 ) + V_98 ;
* ( V_96 ++ ) = ( char ) ( V_63 > 255 ? 255 : V_63 ) ;
V_38 ++ ;
break;
}
case 'x' :
{
char V_99 = * ( V_42 + 1 ) ;
char V_98 = * ( V_42 + 2 ) ;
if ( F_64 ( V_99 ) && F_64 ( V_98 ) ) {
* ( V_96 ++ ) = ( F_62 ( V_99 ) * 0x10 ) + F_62 ( V_98 ) ;
V_42 += 2 ;
} else {
* ( V_96 ++ ) = * V_42 ;
}
V_38 ++ ;
break;
}
default:
* V_96 ++ = * V_42 ;
break;
}
break;
default:
* ( V_96 ++ ) = * V_42 ;
V_38 ++ ;
break;
}
}
if ( V_92 ) * V_92 = V_38 ;
return V_93 ;
}
char * F_65 ( const char * V_90 , T_4 V_91 , T_4 * V_92 ) {
return F_63 ( V_90 + 1 , V_91 - 2 , V_92 ) ;
}
char * F_66 ( const char * V_93 , T_4 V_38 ) {
const T_20 * V_101 = ( ( const T_20 * ) V_93 ) + V_38 ;
char * V_102 = ( char * ) F_61 ( ( 4 * V_38 ) + 1 ) ;
const T_20 * V_41 ;
char * V_42 = V_102 ;
for ( V_41 = ( const T_20 * ) V_93 ; V_41 < V_101 ; V_41 ++ ) {
if ( * V_41 == '"' || * V_41 == '\\' || ! F_29 ( * V_41 ) ) {
F_67 ( V_42 , 5 , L_1 , ( ( T_4 ) * V_41 ) ) ;
V_42 += 4 ;
} else {
* ( V_42 ++ ) = ( * V_41 ) ;
}
}
return V_102 ;
}
T_3 F_68 ( void * T_14 V_72 , const char * V_73 , T_4 V_38 , const void * T_15 V_72 , const void * T_16 V_72 , char * * V_71 ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_38 ; V_16 ++ ) {
char V_63 = V_73 [ V_16 ] ;
if ( ! F_29 ( V_63 ) ) {
* V_71 = F_33 ( L_22 , V_16 , ( V_64 ) V_63 ) ;
return FALSE ;
}
}
* V_71 = NULL ;
return TRUE ;
}
T_3 F_69 ( void * T_14 V_72 , const char * V_73 , T_4 V_38 , const void * T_15 V_72 , const void * T_16 V_72 , char * * V_71 ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_38 ; V_16 ++ ) {
char V_63 = V_73 [ V_16 ] ;
if ( ! F_70 ( V_63 ) ) {
* V_71 = F_33 ( L_22 , V_16 , ( V_64 ) V_63 ) ;
return FALSE ;
}
}
* V_71 = NULL ;
return TRUE ;
}
T_3 F_71 ( void * T_14 V_72 , const char * V_73 , T_4 V_38 , const void * T_15 V_72 , const void * T_16 V_72 , char * * V_71 ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_38 ; V_16 ++ ) {
char V_63 = V_73 [ V_16 ] ;
if ( ! F_72 ( V_63 ) ) {
* V_71 = F_33 ( L_22 , V_16 , ( V_64 ) V_63 ) ;
return FALSE ;
}
}
* V_71 = NULL ;
return TRUE ;
}
T_3 F_73 ( void * T_14 V_72 , const char * V_73 , T_4 V_38 , const void * T_15 V_72 , const void * T_16 V_72 , char * * V_71 ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_38 ; V_16 ++ ) {
char V_63 = V_73 [ V_16 ] ;
if ( ! F_47 ( V_63 ) ) {
* V_71 = F_33 ( L_22 , V_16 , ( V_64 ) V_63 ) ;
return FALSE ;
}
}
* V_71 = NULL ;
return TRUE ;
}
T_3 F_74 ( void * T_14 V_72 , const char * V_73 , T_4 V_38 , const void * T_15 V_72 , const void * T_16 V_72 , char * * V_71 ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_38 ; V_16 ++ ) {
char V_63 = V_73 [ V_16 ] ;
if ( ! F_64 ( V_63 ) ) {
* V_71 = F_33 ( L_22 , V_16 , ( V_64 ) V_63 ) ;
return FALSE ;
}
}
* V_71 = NULL ;
return TRUE ;
}
