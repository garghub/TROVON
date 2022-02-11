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
static T_1 * F_5 ( const char * V_8 )
{
T_1 * V_9 ;
if ( ! strncmp ( V_8 , L_1 , 7 ) ) {
T_2 * V_10 ;
F_6 () ;
F_1 () ;
V_10 = F_7 ( L_2 ) ;
F_8 ( ! V_10 , L_3 ) ;
if ( F_9 ( V_10 ) )
F_1 () ;
else
F_8 ( 1 , L_4 ) ;
if ( V_7 )
F_8 ( ! F_10 ( V_10 , L_5 , V_7 , 0 ) ,
L_6 ) ;
V_9 = F_11 ( V_10 , V_8 ,
NULL , NULL ) ;
F_8 ( ! V_9 , L_7 , V_8 ) ;
} else {
T_3 * V_11 ;
V_11 = F_12 ( V_8 , L_8 ) ;
F_8 ( ! V_11 , L_7 , V_8 ) ;
V_9 = F_13 ( V_11 , NULL , F_4 ,
NULL ) ;
F_8 ( ! V_9 , L_7 , V_8 ) ;
F_14 ( V_11 ) ;
}
return V_9 ;
}
static T_4 * F_15 ( const char * V_12 )
{
T_4 * V_13 ;
T_3 * V_11 ;
V_11 = F_12 ( V_12 , L_8 ) ;
F_8 ( ! V_11 , L_7 , V_12 ) ;
V_13 = F_16 ( V_11 , NULL ) ;
if ( ! V_13 ) {
F_8 ( F_17 ( V_11 ) != 1 , L_7 , V_12 ) ;
V_13 = F_18 ( V_11 , NULL , NULL ,
NULL ) ;
if ( V_13 )
F_1 () ;
}
F_14 ( V_11 ) ;
F_8 ( ! V_13 , L_7 , V_12 ) ;
return V_13 ;
}
int main ( int V_14 , char * * V_15 )
{
struct V_16 V_17 = { . V_18 = V_19 } ;
char * V_20 = NULL ;
char * V_8 = NULL , * V_21 = NULL ;
char * V_12 , * V_22 , * V_23 ;
bool V_24 = false , V_25 ;
bool V_26 = false ;
bool V_27 = false ;
unsigned char V_2 [ 4096 ] ;
unsigned long V_28 , V_29 ;
unsigned int V_30 ;
const T_5 * V_31 ;
T_1 * V_9 ;
#ifndef F_19
T_6 * V_32 = NULL ;
unsigned int V_33 = 0 ;
#else
T_7 * V_34 = NULL ;
#endif
T_4 * V_13 ;
T_3 * V_35 , * V_36 ;
int V_37 , V_38 ;
F_20 () ;
F_21 () ;
F_22 () ;
V_7 = getenv ( L_9 ) ;
#ifndef F_19
V_30 = V_39 ;
#else
V_30 = V_40 ;
#endif
do {
V_37 = F_23 ( V_14 , V_15 , L_10 ) ;
switch ( V_37 ) {
case 's' : V_27 = true ; break;
case 'p' : V_24 = true ; break;
case 'd' : V_26 = true ; V_24 = true ; break;
#ifndef F_19
case 'k' : V_33 = V_41 ; break;
#endif
case - 1 : break;
default: F_24 () ;
}
} while ( V_37 != - 1 );
V_14 -= V_42 ;
V_15 += V_42 ;
if ( V_14 < 4 || V_14 > 5 )
F_24 () ;
if ( V_27 ) {
V_21 = V_15 [ 0 ] ;
V_20 = V_15 [ 1 ] ;
} else {
V_20 = V_15 [ 0 ] ;
V_8 = V_15 [ 1 ] ;
}
V_12 = V_15 [ 2 ] ;
V_22 = V_15 [ 3 ] ;
if ( V_14 == 5 ) {
V_23 = V_15 [ 4 ] ;
V_25 = false ;
} else {
F_8 ( F_25 ( & V_23 , L_11 , V_22 ) < 0 ,
L_12 ) ;
V_25 = true ;
}
#ifdef F_19
if ( strcmp ( V_20 , L_13 ) != 0 ) {
fprintf ( V_43 , L_14 ,
V_44 ) ;
exit ( 3 ) ;
}
#endif
V_36 = F_12 ( V_22 , L_8 ) ;
F_8 ( ! V_36 , L_7 , V_22 ) ;
if ( ! V_27 ) {
V_9 = F_5 ( V_8 ) ;
V_13 = F_15 ( V_12 ) ;
F_26 () ;
F_27 ( __LINE__ ) ;
V_31 = F_28 ( V_20 ) ;
F_8 ( ! V_31 , L_15 ) ;
#ifndef F_19
V_32 = F_29 ( NULL , NULL , NULL , NULL ,
V_45 | V_46 | V_47 |
V_48 | V_49 ) ;
F_8 ( ! V_32 , L_16 ) ;
F_8 ( ! F_30 ( V_32 , V_13 , V_9 , V_31 ,
V_45 | V_47 |
V_50 | V_33 |
V_30 ) ,
L_17 ) ;
F_8 ( F_31 ( V_32 , V_36 , NULL , V_45 | V_47 ) < 0 ,
L_18 ) ;
#else
V_34 = F_32 ( V_13 , V_9 , NULL , V_36 ,
V_51 | V_52 |
V_53 | V_30 ) ;
F_8 ( ! V_34 , L_19 ) ;
#endif
if ( V_24 ) {
char * V_54 ;
T_3 * V_11 ;
F_8 ( F_25 ( & V_54 , L_20 , V_22 ) < 0 ,
L_12 ) ;
V_11 = F_12 ( V_54 , L_21 ) ;
F_8 ( ! V_11 , L_7 , V_54 ) ;
#ifndef F_19
F_8 ( F_33 ( V_11 , V_32 , NULL , 0 ) < 0 ,
L_7 , V_54 ) ;
#else
F_8 ( F_34 ( V_11 , V_34 ) < 0 ,
L_7 , V_54 ) ;
#endif
F_14 ( V_11 ) ;
}
if ( V_26 ) {
F_14 ( V_36 ) ;
return 0 ;
}
}
V_35 = F_12 ( V_23 , L_21 ) ;
F_8 ( ! V_35 , L_7 , V_23 ) ;
F_8 ( F_17 ( V_36 ) < 0 , L_7 , V_22 ) ;
while ( ( V_38 = F_35 ( V_36 , V_2 , sizeof( V_2 ) ) ) ,
V_38 > 0 ) {
F_8 ( F_36 ( V_35 , V_2 , V_38 ) < 0 , L_7 , V_23 ) ;
}
F_14 ( V_36 ) ;
F_8 ( V_38 < 0 , L_7 , V_22 ) ;
V_28 = F_37 ( V_35 ) ;
if ( ! V_27 ) {
#ifndef F_19
F_8 ( F_33 ( V_35 , V_32 , NULL , 0 ) < 0 , L_7 , V_23 ) ;
#else
F_8 ( F_34 ( V_35 , V_34 ) < 0 , L_7 , V_23 ) ;
#endif
} else {
T_3 * V_11 ;
V_11 = F_12 ( V_21 , L_8 ) ;
F_8 ( ! V_11 , L_7 , V_21 ) ;
while ( ( V_38 = F_35 ( V_11 , V_2 , sizeof( V_2 ) ) ) , V_38 > 0 )
F_8 ( F_36 ( V_35 , V_2 , V_38 ) < 0 , L_7 , V_23 ) ;
F_14 ( V_11 ) ;
}
V_29 = F_37 ( V_35 ) - V_28 ;
V_17 . V_55 = F_38 ( V_29 ) ;
F_8 ( F_36 ( V_35 , & V_17 , sizeof( V_17 ) ) < 0 , L_7 , V_23 ) ;
F_8 ( F_36 ( V_35 , V_56 , sizeof( V_56 ) - 1 ) < 0 , L_7 , V_23 ) ;
F_8 ( F_14 ( V_35 ) < 0 , L_7 , V_23 ) ;
if ( V_25 )
F_8 ( rename ( V_23 , V_22 ) < 0 , L_7 , V_23 ) ;
return 0 ;
}
