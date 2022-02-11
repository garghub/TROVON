T_1 * F_1 ( const char * V_1 ,
T_2 V_2 ,
const char * V_3 ,
T_3 V_4 ,
void * V_5 ,
T_4 * V_6 ,
T_4 V_7 ,
const char * V_8 ,
T_5 V_9 ,
T_6 V_10 ,
T_7 V_11 ,
T_8 V_12 ,
T_9 V_13 ,
T_10 * V_14 ) {
T_1 * V_15 = ( T_1 * ) F_2 ( sizeof( T_1 ) ) ;
T_4 V_16 ;
if ( ! V_17 )
V_17 = F_3 () ;
F_4 ( V_17 , V_15 ) ;
F_5 ( V_1 && V_2 && V_3 && V_5 && V_6 ) ;
V_15 -> V_1 = F_6 ( V_1 ) ;
V_15 -> V_18 = V_2 ;
V_15 -> V_3 = F_6 ( V_3 ) ;
V_15 -> V_4 = V_4 ;
V_15 -> V_19 = ( void * * ) V_5 ;
V_15 -> V_20 = V_6 ;
V_15 -> V_9 = V_9 ;
V_15 -> V_10 = V_10 ;
V_15 -> V_11 = V_11 ;
V_15 -> V_12 = V_12 ;
V_15 -> V_13 = V_13 ;
V_15 -> V_21 = V_14 ;
V_15 -> V_22 = F_7 ( FALSE , FALSE , ( T_4 ) V_15 -> V_18 ) ;
V_15 -> V_23 = F_7 ( FALSE , FALSE , ( T_4 ) V_15 -> V_18 ) ;
V_15 -> V_24 = F_7 ( FALSE , FALSE , sizeof( T_3 ) ) ;
V_15 -> V_25 = FALSE ;
V_15 -> V_26 = FALSE ;
V_15 -> V_27 = FALSE ;
V_15 -> V_28 = NULL ;
V_15 -> V_29 = NULL ;
V_15 -> V_8 = F_6 ( V_8 ) ;
V_15 -> V_7 = V_7 ;
for ( V_16 = 0 ; V_14 [ V_16 ] . V_30 ; V_16 ++ ) {
T_11 * V_31 = ( T_11 * ) F_2 ( sizeof( T_11 ) ) ;
V_31 -> V_32 = V_16 + 1 ;
V_31 -> V_28 = NULL ;
V_31 -> V_29 = NULL ;
V_14 [ V_16 ] . V_33 = V_31 ;
}
V_15 -> V_34 = V_16 ;
* ( ( void * * ) V_5 ) = NULL ;
* V_6 = 0 ;
return V_15 ;
}
void * F_8 ( T_1 * V_15 , const void * V_35 , T_3 V_36 ) {
void * V_37 ;
T_3 * V_38 ;
F_9 ( V_15 , V_15 -> V_23 -> V_39 , V_35 ) ;
if ( V_36 ) {
F_10 ( V_15 -> V_22 , V_35 , 1 ) ;
V_37 = F_11 ( V_15 , V_15 -> V_22 -> V_39 - 1 ) ;
if ( V_15 -> V_9 ) {
V_15 -> V_9 ( V_37 , V_35 , ( unsigned int ) V_15 -> V_18 ) ;
}
F_12 ( V_15 ) ;
V_38 = & F_13 ( V_15 -> V_24 , T_3 , V_15 -> V_24 -> V_39 - 1 ) ;
* V_38 = V_36 ;
} else {
V_37 = NULL ;
}
return V_37 ;
}
void F_14 ( T_1 * V_15 , const void * V_40 , T_3 V_36 ) {
T_4 V_41 ;
T_3 * V_38 ;
for ( V_41 = 0 ; V_41 < V_15 -> V_23 -> V_39 ; V_41 ++ ) {
if ( F_15 ( V_15 , V_41 ) == V_40 ) {
break;
}
}
if ( V_41 == V_15 -> V_23 -> V_39 ) {
F_16 () ;
}
V_38 = & F_13 ( V_15 -> V_24 , T_3 , V_41 ) ;
* V_38 = V_36 ;
}
void F_17 ( T_1 * V_15 , T_4 V_42 , T_4 V_43 ) {
T_2 V_44 = V_15 -> V_18 ;
void * V_45 ;
T_3 V_46 ;
F_5 ( V_42 < V_15 -> V_23 -> V_39 && V_43 < V_15 -> V_23 -> V_39 ) ;
if ( V_42 == V_43 ) return;
V_45 = F_2 ( V_44 ) ;
memcpy ( V_45 , F_15 ( V_15 , V_42 ) , V_44 ) ;
memcpy ( F_15 ( V_15 , V_42 ) , F_15 ( V_15 , V_43 ) , V_44 ) ;
memcpy ( F_15 ( V_15 , V_43 ) , V_45 , V_44 ) ;
F_18 ( V_45 ) ;
V_46 = * ( T_3 * ) ( V_15 -> V_24 -> V_35 + ( sizeof( T_3 ) * ( V_42 ) ) ) ;
* ( T_3 * ) ( V_15 -> V_24 -> V_35 + ( sizeof( T_3 ) * ( V_42 ) ) ) = * ( T_3 * ) ( V_15 -> V_24 -> V_35 + ( sizeof( T_3 ) * ( V_43 ) ) ) ;
* ( T_3 * ) ( V_15 -> V_24 -> V_35 + ( sizeof( T_3 ) * ( V_43 ) ) ) = V_46 ;
}
void F_9 ( T_1 * V_15 , T_4 V_47 , const void * V_48 ) {
F_5 ( V_47 <= V_15 -> V_23 -> V_39 ) ;
F_19 ( V_15 -> V_23 , V_47 , V_48 , 1 ) ;
void * V_37 = F_15 ( V_15 , V_47 ) ;
if ( V_15 -> V_9 ) {
V_15 -> V_9 ( V_37 , V_48 , ( unsigned int ) V_15 -> V_18 ) ;
} else {
memcpy ( V_37 , V_48 , ( unsigned int ) V_15 -> V_18 ) ;
}
T_3 V_36 = FALSE ;
F_20 ( V_15 -> V_24 , V_47 , V_36 ) ;
}
void F_21 ( T_1 * V_15 , T_4 V_47 ) {
F_5 ( V_47 < V_15 -> V_23 -> V_39 ) ;
if ( V_15 -> V_11 ) {
V_15 -> V_11 ( F_15 ( V_15 , V_47 ) ) ;
}
F_22 ( V_15 -> V_23 , V_47 ) ;
F_22 ( V_15 -> V_24 , V_47 ) ;
}
T_12 * F_23 ( T_1 * V_15 , T_3 V_49 ) {
T_12 * V_50 = NULL ;
if ( ! V_15 -> V_27 ) {
V_50 = F_24 ( V_15 -> V_3 , V_15 -> V_4 ) ;
}
if ( ( ! V_49 ) && ( ! F_25 ( V_50 ) ) ) {
T_12 * V_51 = F_26 ( V_15 -> V_3 ) ;
if ( F_25 ( V_51 ) ) {
F_18 ( V_50 ) ;
return V_51 ;
}
F_18 ( V_51 ) ;
F_18 ( V_50 ) ;
return NULL ;
}
return V_50 ;
}
T_1 * F_27 ( const char * V_1 ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_17 -> V_39 ; V_16 ++ ) {
T_1 * V_52 = ( T_1 * ) F_28 ( V_17 , V_16 ) ;
if ( F_29 ( V_52 -> V_1 , V_1 ) ) {
return ( V_52 ) ;
}
}
return NULL ;
}
char * F_30 ( void * V_37 , T_10 * V_31 ) {
T_4 V_39 ;
char * V_53 ;
char * V_54 ;
V_31 -> V_55 . V_56 ( V_37 , & V_53 , & V_39 , V_31 -> V_57 . V_56 , V_31 -> V_58 ) ;
switch( V_31 -> V_59 ) {
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
V_54 = F_31 ( V_53 , V_39 ) ;
break;
case V_65 : {
T_13 * V_44 = F_32 ( V_39 * 2 + 1 ) ;
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_39 ; V_16 ++ ) F_33 ( V_44 , L_1 , ( ( const V_66 * ) V_53 ) [ V_16 ] ) ;
V_54 = F_6 ( V_44 -> V_67 ) ;
F_34 ( V_44 , TRUE ) ;
break;
}
default:
F_16 () ;
V_54 = NULL ;
break;
}
F_18 ( V_53 ) ;
return V_54 ;
}
static void F_35 ( T_14 * V_68 , void * V_37 , T_10 * V_31 ) {
T_4 V_69 ;
char * V_70 ;
V_31 -> V_55 . V_56 ( V_37 , & V_70 , & V_69 , V_31 -> V_57 . V_56 , V_31 -> V_58 ) ;
switch( V_31 -> V_59 ) {
case V_60 :
case V_62 :
case V_63 :
case V_64 :
case V_61 : {
T_4 V_16 ;
putc ( '"' , V_68 ) ;
for( V_16 = 0 ; V_16 < V_69 ; V_16 ++ ) {
char V_71 = V_70 [ V_16 ] ;
if ( V_71 == '"' || V_71 == '\\' || ! F_36 ( ( V_72 ) V_71 ) ) {
fprintf ( V_68 , L_2 , ( V_72 ) V_71 ) ;
} else {
putc ( V_71 , V_68 ) ;
}
}
putc ( '"' , V_68 ) ;
break;
}
case V_65 : {
T_4 V_16 ;
for( V_16 = 0 ; V_16 < V_69 ; V_16 ++ ) {
fprintf ( V_68 , L_3 , ( V_72 ) V_70 [ V_16 ] ) ;
}
break;
}
default:
F_16 () ;
}
F_18 ( V_70 ) ;
}
T_3 F_37 ( T_1 * V_15 , char * * error ) {
T_4 V_16 ;
T_12 * V_73 = F_23 ( V_15 , TRUE ) ;
T_14 * V_68 ;
if ( ! V_73 ) return FALSE ;
V_68 = F_38 ( V_73 , L_4 ) ;
if ( ! V_68 && V_74 == V_75 ) {
T_12 * V_76 = NULL ;
if ( F_39 ( & V_76 ) != 0 ) {
* error = F_40 ( L_5 , V_76 ) ;
F_18 ( V_76 ) ;
return FALSE ;
}
V_68 = F_38 ( V_73 , L_4 ) ;
}
if ( ! V_68 ) {
* error = F_40 ( L_6 , V_73 , F_41 ( V_74 ) ) ;
return FALSE ;
}
* error = NULL ;
F_18 ( V_73 ) ;
for ( V_16 = 0 ; V_16 < V_15 -> V_22 -> V_39 ; V_16 ++ ) {
if ( V_15 -> V_11 ) {
V_15 -> V_11 ( F_11 ( V_15 , V_16 ) ) ;
}
}
F_42 ( V_15 -> V_22 , 0 ) ;
* ( ( V_15 ) -> V_19 ) = NULL ;
* ( ( V_15 ) -> V_20 ) = 0 ;
for ( V_16 = 0 ; V_16 < V_15 -> V_23 -> V_39 ; V_16 ++ ) {
void * V_37 = F_15 ( V_15 , V_16 ) ;
T_3 V_38 = F_13 ( V_15 -> V_24 , T_3 , V_16 ) ;
if ( V_38 ) {
F_10 ( V_15 -> V_22 , V_37 , 1 ) ;
if ( V_15 -> V_9 ) {
V_15 -> V_9 ( F_11 ( V_15 , V_15 -> V_22 -> V_39 - 1 ) ,
V_37 , ( unsigned int ) V_15 -> V_18 ) ;
}
F_12 ( V_15 ) ;
}
}
fprintf ( V_68 , L_7 ) ;
for ( V_16 = 0 ; V_16 < V_15 -> V_22 -> V_39 ; V_16 ++ ) {
void * V_37 = V_15 -> V_22 -> V_35 + ( V_15 -> V_18 * V_16 ) ;
T_10 * V_31 ;
T_4 V_77 ;
V_31 = V_15 -> V_21 ;
for( V_77 = 0 ; V_77 < V_15 -> V_34 ; V_77 ++ ) {
F_35 ( V_68 , V_37 , & ( V_31 [ V_77 ] ) ) ;
fputs ( ( V_77 == V_15 -> V_34 - 1 ) ? L_8 : L_9 , V_68 ) ;
}
}
fclose ( V_68 ) ;
V_15 -> V_25 = FALSE ;
return TRUE ;
}
T_1 * F_43 ( T_12 * V_1 ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_17 -> V_39 ; V_16 ++ ) {
T_1 * V_52 = ( T_1 * ) F_28 ( V_17 , V_16 ) ;
if ( strcmp ( V_52 -> V_1 , V_1 ) == 0 || strcmp ( V_52 -> V_3 , V_1 ) == 0 ) {
return V_52 ;
}
}
return NULL ;
}
void F_44 ( T_1 * V_15 ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_15 -> V_22 -> V_39 ; V_16 ++ ) {
if ( V_15 -> V_11 ) {
V_15 -> V_11 ( F_11 ( V_15 , V_16 ) ) ;
}
}
for ( V_16 = 0 ; V_16 < V_15 -> V_23 -> V_39 ; V_16 ++ ) {
if ( V_15 -> V_11 ) {
V_15 -> V_11 ( F_15 ( V_15 , V_16 ) ) ;
}
}
F_42 ( V_15 -> V_23 , 0 ) ;
F_42 ( V_15 -> V_22 , 0 ) ;
F_42 ( V_15 -> V_24 , 0 ) ;
* ( ( V_15 ) -> V_19 ) = NULL ;
* ( ( V_15 ) -> V_20 ) = 0 ;
if ( V_15 -> V_13 ) {
V_15 -> V_13 () ;
}
}
void F_45 ( void ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_17 -> V_39 ; V_16 ++ ) {
T_1 * V_52 = ( T_1 * ) F_28 ( V_17 , V_16 ) ;
if ( V_52 -> V_4 ) {
F_44 ( V_52 ) ;
V_52 -> V_26 = FALSE ;
}
}
}
void F_46 ( void ) {
T_4 V_16 ;
T_4 V_77 ;
T_1 * V_15 ;
for ( V_16 = 0 ; V_16 < V_17 -> V_39 ; V_16 ++ ) {
V_15 = ( T_1 * ) F_28 ( V_17 , V_16 ) ;
F_44 ( V_15 ) ;
F_18 ( V_15 -> V_8 ) ;
F_18 ( V_15 -> V_1 ) ;
F_18 ( V_15 -> V_3 ) ;
F_47 ( V_15 -> V_22 , TRUE ) ;
F_47 ( V_15 -> V_23 , TRUE ) ;
F_47 ( V_15 -> V_24 , TRUE ) ;
for ( V_77 = 0 ; V_15 -> V_21 [ V_77 ] . V_30 ; V_77 ++ )
F_18 ( V_15 -> V_21 [ V_77 ] . V_33 ) ;
F_18 ( V_15 ) ;
}
F_48 ( V_17 , TRUE ) ;
}
void F_49 ( T_15 V_55 , void * V_22 ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_17 -> V_39 ; V_16 ++ )
V_55 ( F_28 ( V_17 , V_16 ) , V_22 ) ;
}
void F_50 ( void ) {
T_4 V_16 ;
T_12 * V_78 ;
for ( V_16 = 0 ; V_16 < V_17 -> V_39 ; V_16 ++ ) {
T_1 * V_52 = ( T_1 * ) F_28 ( V_17 , V_16 ) ;
if ( ! V_52 -> V_26 ) {
V_78 = NULL ;
if ( ! F_51 ( V_52 , & V_78 ) ) {
F_52 ( L_10 , V_52 -> V_1 , V_78 ) ;
F_18 ( V_78 ) ;
}
}
}
}
T_3 F_53 ( void * T_16 V_79 , const char * V_80 , T_4 V_39 V_79 , const void * T_17 V_79 , const void * T_18 V_79 , char * * V_78 ) {
if ( V_80 == NULL ) {
* V_78 = F_6 ( L_11 ) ;
return FALSE ;
}
* V_78 = NULL ;
return TRUE ;
}
T_3 F_54 ( void * T_16 V_79 , const char * V_80 , T_4 V_39 , const void * T_17 V_79 , const void * T_18 V_79 , char * * V_78 ) {
unsigned int V_16 ;
* V_78 = NULL ;
if ( V_80 == NULL ) {
* V_78 = F_6 ( L_11 ) ;
return FALSE ;
}
if ( V_39 == 0 ) {
* V_78 = F_6 ( L_12 ) ;
return FALSE ;
}
for( V_16 = 0 ; V_16 < V_39 ; V_16 ++ )
if( ! ( F_55 ( V_80 [ V_16 ] ) || V_80 [ V_16 ] == '.' ) ) {
* V_78 = F_6 ( L_13 ) ;
return FALSE ;
}
if( V_80 [ V_39 - 1 ] == '.' ) {
* V_78 = F_6 ( L_14 ) ;
return FALSE ;
}
if( ! ( ( * V_80 == '0' || * V_80 == '1' || * V_80 == '2' ) && ( V_39 > 1 && V_80 [ 1 ] == '.' ) ) ) {
* V_78 = F_6 ( L_15 ) ;
return FALSE ;
}
return * V_78 == NULL ;
}
T_3 F_56 ( void * T_16 V_79 , const char * V_80 , T_4 V_39 , const void * T_17 V_79 , const void * T_18 V_79 , char * * V_78 ) {
if ( V_39 ) {
char * V_1 = F_31 ( V_80 , V_39 ) ;
F_57 ( V_1 ) ;
F_58 ( V_1 ) ;
if ( F_59 ( V_1 ) ) {
* V_78 = NULL ;
F_18 ( V_1 ) ;
return TRUE ;
} else {
* V_78 = F_6 ( L_16 ) ;
F_18 ( V_1 ) ;
return FALSE ;
}
} else {
* V_78 = NULL ;
return TRUE ;
}
}
static T_3 F_60 ( int V_81 , const char * V_80 , T_4 V_39 , char * * V_78 ) {
if ( V_39 > 0 ) {
char * V_67 = F_31 ( V_80 , V_39 ) ;
char * V_82 ;
long V_16 ;
V_74 = 0 ;
V_16 = strtol ( V_67 , & V_82 , V_81 ) ;
if ( ( ( V_16 == V_83 || V_16 == V_84 ) && V_74 == V_85 )
|| ( V_74 != 0 && V_16 == 0 ) ) {
* V_78 = F_6 ( F_41 ( V_74 ) ) ;
F_18 ( V_67 ) ;
return FALSE ;
}
if ( ( * V_82 != '\0' ) && ( * V_82 != ' ' ) ) {
* V_78 = F_6 ( L_17 ) ;
F_18 ( V_67 ) ;
return FALSE ;
}
if ( ( sizeof( long ) > 4 ) && ( ( V_16 < V_86 ) || ( V_16 > V_87 ) ) ) {
* V_78 = F_6 ( L_18 ) ;
F_18 ( V_67 ) ;
return FALSE ;
}
F_18 ( V_67 ) ;
}
* V_78 = NULL ;
return TRUE ;
}
T_3 F_61 ( void * T_16 V_79 , const char * V_80 , T_4 V_39 , const void * T_17 V_79 , const void * T_18 V_79 , char * * V_78 ) {
return F_60 ( 10 , V_80 , V_39 , V_78 ) ;
}
T_3 F_62 ( void * T_16 V_79 , const char * V_80 , T_4 V_39 , const void * T_17 V_79 , const void * T_18 V_79 , char * * V_78 ) {
return F_60 ( 16 , V_80 , V_39 , V_78 ) ;
}
T_3 F_63 ( void * T_16 V_79 , const char * V_80 , T_4 V_39 , const void * V_88 , const void * T_18 V_79 , char * * V_78 ) {
char * V_67 = F_31 ( V_80 , V_39 ) ;
T_4 V_16 ;
const T_19 * V_89 = ( const T_19 * ) V_88 ;
for( V_16 = 0 ; V_89 [ V_16 ] . V_80 ; V_16 ++ ) {
if ( F_29 ( V_89 [ V_16 ] . V_80 , V_67 ) ) {
* V_78 = NULL ;
F_18 ( V_67 ) ;
return TRUE ;
}
}
* V_78 = F_40 ( L_19 , V_67 ) ;
F_18 ( V_67 ) ;
return FALSE ;
}
T_3 F_64 ( void * T_16 V_79 , const char * V_80 , T_4 V_39 , const void * V_88 V_79 , const void * T_18 , char * * V_78 ) {
char * V_67 = F_31 ( V_80 , V_39 ) ;
T_20 * V_90 = NULL ;
T_21 V_91 = F_65 ( NULL , & V_90 , V_67 , F_66 ( T_18 ) ) ;
T_3 V_92 = FALSE ;
switch ( V_91 ) {
case V_93 :
* V_78 = NULL ;
V_92 = TRUE ;
break;
case V_94 :
* V_78 = F_40 ( L_20 , V_67 ) ;
V_92 = FALSE ;
break;
case V_95 :
* V_78 = F_40 ( L_21 , V_67 , F_66 ( T_18 ) ) ;
V_92 = FALSE ;
break;
default:
* V_78 = F_6 ( L_22 ) ;
V_92 = FALSE ;
break;
}
F_18 ( V_67 ) ;
F_67 ( NULL , V_90 ) ;
return V_92 ;
}
char * F_68 ( const char * V_96 , T_4 V_97 , T_4 * V_98 ) {
V_66 * V_99 ;
T_4 V_39 = V_97 / 2 ;
int V_16 = 0 ;
int V_100 , V_101 ;
if ( V_97 % 2 ) {
return NULL ;
}
V_99 = ( V_66 * ) F_69 ( V_39 + 1 ) ;
if ( V_98 ) * V_98 = V_39 ;
while( V_97 ) {
V_101 = F_70 ( * ( V_96 ++ ) ) ;
V_100 = F_70 ( * ( V_96 ++ ) ) ;
V_99 [ V_16 ++ ] = ( V_101 * 16 ) + V_100 ;
V_97 -= 2 ;
}
return ( char * ) V_99 ;
}
char * F_71 ( const char * V_96 , T_4 V_97 , T_4 * V_98 ) {
char * V_99 = ( char * ) F_69 ( V_97 + 1 ) ;
char * V_102 = V_99 ;
T_4 V_39 = 0 ;
const char * V_44 ;
const char * V_103 = V_96 + V_97 ;
for ( V_44 = ( const char * ) V_96 ; V_44 < V_103 ; V_44 ++ ) {
switch( * V_44 ) {
case '\\' :
switch( * ( ++ V_44 ) ) {
case 'a' : * ( V_102 ++ ) = '\a' ; V_39 ++ ; break;
case 'b' : * ( V_102 ++ ) = '\b' ; V_39 ++ ; break;
case 'e' : * ( V_102 ++ ) = '\033' ; V_39 ++ ; break;
case 'f' : * ( V_102 ++ ) = '\f' ; V_39 ++ ; break;
case 'n' : * ( V_102 ++ ) = '\n' ; V_39 ++ ; break;
case 'r' : * ( V_102 ++ ) = '\r' ; V_39 ++ ; break;
case 't' : * ( V_102 ++ ) = '\t' ; V_39 ++ ; break;
case 'v' : * ( V_102 ++ ) = '\v' ; V_39 ++ ; break;
case '0' :
case '1' :
case '2' :
case '3' :
case '4' :
case '5' :
case '6' :
case '7' :
{
int V_104 = 0 ;
int V_105 = 0 ;
int V_106 = 0 ;
int V_71 = 0 ;
V_104 = ( * V_44 ) - '0' ;
if ( V_44 [ 1 ] >= '0' && V_44 [ 1 ] <= '7' ) {
V_105 = V_104 ;
V_104 = ( * ++ V_44 ) - '0' ;
if ( V_44 [ 1 ] >= '0' && V_44 [ 1 ] <= '7' ) {
V_106 = V_105 ;
V_105 = V_104 ;
V_104 = ( * ++ V_44 ) - '0' ;
}
}
V_71 = ( 64 * V_106 ) + ( 8 * V_105 ) + V_104 ;
* ( V_102 ++ ) = ( char ) ( V_71 > 255 ? 255 : V_71 ) ;
V_39 ++ ;
break;
}
case 'x' :
{
char V_105 = * ( V_44 + 1 ) ;
char V_104 = * ( V_44 + 2 ) ;
if ( F_72 ( V_105 ) && F_72 ( V_104 ) ) {
* ( V_102 ++ ) = ( F_70 ( V_105 ) * 0x10 ) + F_70 ( V_104 ) ;
V_44 += 2 ;
} else {
* ( V_102 ++ ) = * V_44 ;
}
V_39 ++ ;
break;
}
default:
* V_102 ++ = * V_44 ;
break;
}
break;
default:
* ( V_102 ++ ) = * V_44 ;
V_39 ++ ;
break;
}
}
if ( V_98 ) * V_98 = V_39 ;
return V_99 ;
}
char * F_73 ( const char * V_96 , T_4 V_97 , T_4 * V_98 ) {
return F_71 ( V_96 + 1 , V_97 - 2 , V_98 ) ;
}
char * F_74 ( const char * V_99 , T_4 V_39 ) {
const V_66 * V_107 = ( ( const V_66 * ) V_99 ) + V_39 ;
char * V_54 = ( char * ) F_69 ( ( 4 * V_39 ) + 1 ) ;
const V_66 * V_43 ;
char * V_44 = V_54 ;
for ( V_43 = ( const V_66 * ) V_99 ; V_43 < V_107 ; V_43 ++ ) {
if ( * V_43 == '"' || * V_43 == '\\' || ! F_36 ( * V_43 ) ) {
F_75 ( V_44 , 5 , L_2 , ( ( T_4 ) * V_43 ) ) ;
V_44 += 4 ;
} else {
* ( V_44 ++ ) = ( * V_43 ) ;
}
}
return V_54 ;
}
T_3 F_76 ( void * T_16 V_79 , const char * V_80 , T_4 V_39 , const void * T_17 V_79 , const void * T_18 V_79 , char * * V_78 ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_39 ; V_16 ++ ) {
char V_71 = V_80 [ V_16 ] ;
if ( ! F_36 ( V_71 ) ) {
* V_78 = F_40 ( L_23 , V_16 , ( V_72 ) V_71 ) ;
return FALSE ;
}
}
* V_78 = NULL ;
return TRUE ;
}
T_3 F_77 ( void * T_16 V_79 , const char * V_80 , T_4 V_39 , const void * T_17 V_79 , const void * T_18 V_79 , char * * V_78 ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_39 ; V_16 ++ ) {
char V_71 = V_80 [ V_16 ] ;
if ( ! F_78 ( V_71 ) ) {
* V_78 = F_40 ( L_23 , V_16 , ( V_72 ) V_71 ) ;
return FALSE ;
}
}
* V_78 = NULL ;
return TRUE ;
}
T_3 F_79 ( void * T_16 V_79 , const char * V_80 , T_4 V_39 , const void * T_17 V_79 , const void * T_18 V_79 , char * * V_78 ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_39 ; V_16 ++ ) {
char V_71 = V_80 [ V_16 ] ;
if ( ! F_80 ( V_71 ) ) {
* V_78 = F_40 ( L_23 , V_16 , ( V_72 ) V_71 ) ;
return FALSE ;
}
}
* V_78 = NULL ;
return TRUE ;
}
T_3 F_81 ( void * T_16 V_79 , const char * V_80 , T_4 V_39 , const void * T_17 V_79 , const void * T_18 V_79 , char * * V_78 ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_39 ; V_16 ++ ) {
char V_71 = V_80 [ V_16 ] ;
if ( ! F_55 ( V_71 ) ) {
* V_78 = F_40 ( L_23 , V_16 , ( V_72 ) V_71 ) ;
return FALSE ;
}
}
* V_78 = NULL ;
return TRUE ;
}
T_3 F_82 ( void * T_16 V_79 , const char * V_80 , T_4 V_39 , const void * T_17 V_79 , const void * T_18 V_79 , char * * V_78 ) {
T_4 V_16 ;
for ( V_16 = 0 ; V_16 < V_39 ; V_16 ++ ) {
char V_71 = V_80 [ V_16 ] ;
if ( ! F_72 ( V_71 ) ) {
* V_78 = F_40 ( L_23 , V_16 , ( V_72 ) V_71 ) ;
return FALSE ;
}
}
* V_78 = NULL ;
return TRUE ;
}
