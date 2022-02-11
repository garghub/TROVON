void F_1 ( void )
{
const char * V_1 ;
int line ;
if ( F_2 () == 0 )
return;
while ( F_3 ( & V_1 , & line ) ) {}
}
static int F_4 ( char * V_2 , int V_3 , int V_4 , void * V_5 )
{
int V_6 ;
if ( ! V_7 )
return - 1 ;
V_6 = strlen ( V_7 ) ;
if ( V_6 >= V_3 )
return - 1 ;
strcpy ( V_2 , V_7 ) ;
V_7 = NULL ;
return V_6 ;
}
int main ( int V_8 , char * * V_9 )
{
struct V_10 V_11 = { . V_12 = V_13 } ;
char * V_14 = NULL ;
char * V_15 , * V_16 , * V_17 , * V_18 ;
bool V_19 = false , V_20 ;
bool V_21 = false ;
unsigned char V_2 [ 4096 ] ;
unsigned long V_22 , V_23 ;
unsigned int V_24 ;
const T_1 * V_25 ;
T_2 * V_26 ;
#ifndef F_5
T_3 * V_27 ;
unsigned int V_28 = 0 ;
#else
T_4 * V_29 ;
#endif
T_5 * V_30 ;
T_6 * V_31 , * V_32 = NULL , * V_33 ;
int V_34 , V_35 ;
F_6 () ;
F_7 () ;
F_8 () ;
V_7 = getenv ( L_1 ) ;
#ifndef F_5
V_24 = V_36 ;
#else
V_24 = V_37 ;
#endif
do {
V_34 = F_9 ( V_8 , V_9 , L_2 ) ;
switch ( V_34 ) {
case 'p' : V_19 = true ; break;
case 'd' : V_21 = true ; V_19 = true ; break;
#ifndef F_5
case 'k' : V_28 = V_38 ; break;
#endif
case - 1 : break;
default: F_10 () ;
}
} while ( V_34 != - 1 );
V_8 -= V_39 ;
V_9 += V_39 ;
if ( V_8 < 4 || V_8 > 5 )
F_10 () ;
V_14 = V_9 [ 0 ] ;
V_15 = V_9 [ 1 ] ;
V_16 = V_9 [ 2 ] ;
V_17 = V_9 [ 3 ] ;
if ( V_8 == 5 ) {
V_18 = V_9 [ 4 ] ;
V_20 = false ;
} else {
F_11 ( F_12 ( & V_18 , L_3 , V_17 ) < 0 ,
L_4 ) ;
V_20 = true ;
}
#ifdef F_5
if ( strcmp ( V_14 , L_5 ) != 0 ) {
fprintf ( V_40 , L_6 ,
V_41 ) ;
exit ( 3 ) ;
}
#endif
if ( ! strncmp ( V_15 , L_7 , 7 ) ) {
T_7 * V_42 ;
F_13 () ;
F_1 () ;
V_42 = F_14 ( L_8 ) ;
F_11 ( ! V_42 , L_9 ) ;
if ( F_15 ( V_42 ) )
F_1 () ;
else
F_11 ( 1 , L_10 ) ;
if ( V_7 )
F_11 ( ! F_16 ( V_42 , L_11 , V_7 , 0 ) , L_12 ) ;
V_26 = F_17 ( V_42 , V_15 , NULL ,
NULL ) ;
F_11 ( ! V_26 , L_13 , V_15 ) ;
} else {
V_31 = F_18 ( V_15 , L_14 ) ;
F_11 ( ! V_31 , L_13 , V_15 ) ;
V_26 = F_19 ( V_31 , NULL , F_4 , NULL ) ;
F_11 ( ! V_26 , L_13 , V_15 ) ;
F_20 ( V_31 ) ;
}
V_31 = F_18 ( V_16 , L_14 ) ;
F_11 ( ! V_31 , L_13 , V_16 ) ;
V_30 = F_21 ( V_31 , NULL ) ;
if ( ! V_30 ) {
F_11 ( F_22 ( V_31 ) != 1 , L_13 , V_16 ) ;
V_30 = F_23 ( V_31 , NULL , NULL , NULL ) ;
if ( V_30 )
F_1 () ;
}
F_20 ( V_31 ) ;
F_11 ( ! V_30 , L_13 , V_16 ) ;
if ( ! V_21 ) {
V_32 = F_18 ( V_18 , L_15 ) ;
F_11 ( ! V_32 , L_13 , V_18 ) ;
}
F_24 () ;
F_25 ( __LINE__ ) ;
V_25 = F_26 ( V_14 ) ;
F_11 ( ! V_25 , L_16 ) ;
V_33 = F_18 ( V_17 , L_14 ) ;
F_11 ( ! V_33 , L_13 , V_17 ) ;
#ifndef F_5
V_27 = F_27 ( NULL , NULL , NULL , NULL ,
V_43 | V_44 | V_45 | V_46 | V_47 ) ;
F_11 ( ! V_27 , L_17 ) ;
F_11 ( ! F_28 ( V_27 , V_30 , V_26 , V_25 ,
V_43 | V_45 | V_48 |
V_28 | V_24 ) ,
L_18 ) ;
F_11 ( F_29 ( V_27 , V_33 , NULL , V_43 | V_45 ) < 0 ,
L_19 ) ;
#else
V_29 = F_30 ( V_30 , V_26 , NULL , V_33 ,
V_49 | V_50 |
V_51 | V_24 ) ;
F_11 ( ! V_29 , L_20 ) ;
#endif
if ( V_19 ) {
char * V_52 ;
F_11 ( F_12 ( & V_52 , L_21 , V_17 ) < 0 ,
L_4 ) ;
V_31 = F_18 ( V_52 , L_15 ) ;
F_11 ( ! V_31 , L_13 , V_52 ) ;
#ifndef F_5
F_11 ( F_31 ( V_31 , V_27 , NULL , 0 ) < 0 ,
L_13 , V_52 ) ;
#else
F_11 ( F_32 ( V_31 , V_29 ) < 0 ,
L_13 , V_52 ) ;
#endif
F_20 ( V_31 ) ;
}
if ( V_21 )
return 0 ;
F_11 ( F_22 ( V_33 ) < 0 , L_13 , V_17 ) ;
while ( ( V_35 = F_33 ( V_33 , V_2 , sizeof( V_2 ) ) ) ,
V_35 > 0 ) {
F_11 ( F_34 ( V_32 , V_2 , V_35 ) < 0 , L_13 , V_18 ) ;
}
F_11 ( V_35 < 0 , L_13 , V_17 ) ;
V_22 = F_35 ( V_32 ) ;
#ifndef F_5
F_11 ( F_31 ( V_32 , V_27 , NULL , 0 ) < 0 , L_13 , V_18 ) ;
#else
F_11 ( F_32 ( V_32 , V_29 ) < 0 , L_13 , V_18 ) ;
#endif
V_23 = F_35 ( V_32 ) - V_22 ;
V_11 . V_53 = F_36 ( V_23 ) ;
F_11 ( F_34 ( V_32 , & V_11 , sizeof( V_11 ) ) < 0 , L_13 , V_18 ) ;
F_11 ( F_34 ( V_32 , V_54 , sizeof( V_54 ) - 1 ) < 0 , L_13 , V_18 ) ;
F_11 ( F_20 ( V_32 ) < 0 , L_13 , V_18 ) ;
if ( V_20 )
F_11 ( rename ( V_18 , V_17 ) < 0 , L_13 , V_18 ) ;
return 0 ;
}
