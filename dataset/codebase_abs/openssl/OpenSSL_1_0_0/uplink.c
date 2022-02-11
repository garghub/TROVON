static void F_1 ( void )
{ F_2 ( sizeof( V_1 ) == sizeof( char ) ? L_1 : L_2 , V_2 ) ;
F_3 ( 1 ) ;
}
void F_4 ( volatile void * * V_3 , int V_4 )
{ static T_1 volatile V_5 = NULL ;
static void * * volatile V_6 = NULL ;
int V_7 ;
void (* F_5)( void ) = F_1 ;
T_2 V_8 ;
void * * V_9 ;
do {
V_7 = F_6 ( V_2 , F_7 ( L_3 ) , V_3 , V_4 ) ;
F_8 ( V_2 + V_7 , F_7 ( L_4 ) ) ;
if ( ( V_8 = V_5 ) == NULL )
{ if ( ( V_8 = F_9 ( NULL ) ) == NULL )
{ V_5 = ( T_1 ) - 1 ;
F_8 ( V_2 + V_7 , F_7 ( L_5 ) ) ;
break;
}
V_5 = V_8 ;
}
if ( ( V_8 = V_5 ) == ( T_1 ) - 1 )
break;
if ( V_6 == NULL )
{ void * * (* F_10)();
F_10 = ( void * * (*)() ) F_11 ( V_8 , L_6 ) ;
if ( F_10 == NULL )
{ V_5 = ( T_1 ) - 1 ;
F_8 ( V_2 + V_7 , F_7 ( L_7 ) ) ;
break;
}
V_9 = (* F_10)() ;
if ( V_9 == NULL )
{ V_5 = ( T_1 ) - 1 ;
F_8 ( V_2 + V_7 , F_7 ( L_8 ) ) ;
break;
}
V_6 = V_9 ;
}
else
V_9 = V_6 ;
if ( V_4 > ( int ) V_9 [ 0 ] )
break;
if ( V_9 [ V_4 ] ) F_5 = V_9 [ V_4 ] ;
} while ( 0 );
V_3 [ V_4 ] = F_5 ;
}
main () { F_12 ( V_10 , L_9 ) ; }
