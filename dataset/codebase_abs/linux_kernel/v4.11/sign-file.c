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
unsigned char V_2 [ 2 ] ;
T_4 * V_13 ;
T_3 * V_11 ;
int V_14 ;
V_11 = F_12 ( V_12 , L_8 ) ;
F_8 ( ! V_11 , L_7 , V_12 ) ;
V_14 = F_16 ( V_11 , V_2 , 2 ) ;
if ( V_14 != 2 ) {
if ( F_17 ( V_11 ) ) {
fprintf ( V_15 , L_9 , V_12 ) ;
exit ( 1 ) ;
}
if ( V_14 >= 0 ) {
fprintf ( V_15 , L_10 , V_12 ) ;
exit ( 1 ) ;
}
F_8 ( 1 , L_7 , V_12 ) ;
}
F_8 ( F_18 ( V_11 ) != 0 , L_7 , V_12 ) ;
if ( V_2 [ 0 ] == 0x30 && V_2 [ 1 ] >= 0x81 && V_2 [ 1 ] <= 0x84 )
V_13 = F_19 ( V_11 , NULL ) ;
else
V_13 = F_20 ( V_11 , NULL , NULL , NULL ) ;
F_14 ( V_11 ) ;
F_8 ( ! V_13 , L_7 , V_12 ) ;
return V_13 ;
}
int main ( int V_16 , char * * V_17 )
{
struct V_18 V_19 = { . V_20 = V_21 } ;
char * V_22 = NULL ;
char * V_8 = NULL , * V_23 = NULL ;
char * V_12 , * V_24 , * V_25 ;
bool V_26 = false , V_27 ;
bool V_28 = false ;
bool V_29 = false ;
unsigned char V_2 [ 4096 ] ;
unsigned long V_30 , V_31 ;
unsigned int V_32 ;
const T_5 * V_33 ;
T_1 * V_9 ;
#ifndef F_21
T_6 * V_34 = NULL ;
unsigned int V_35 = 0 ;
#else
T_7 * V_36 = NULL ;
#endif
T_4 * V_13 ;
T_3 * V_37 , * V_38 ;
int V_39 , V_14 ;
F_22 () ;
F_23 () ;
F_24 () ;
V_7 = getenv ( L_11 ) ;
#ifndef F_21
V_32 = V_40 ;
#else
V_32 = V_41 ;
#endif
do {
V_39 = F_25 ( V_16 , V_17 , L_12 ) ;
switch ( V_39 ) {
case 's' : V_29 = true ; break;
case 'p' : V_26 = true ; break;
case 'd' : V_28 = true ; V_26 = true ; break;
#ifndef F_21
case 'k' : V_35 = V_42 ; break;
#endif
case - 1 : break;
default: F_26 () ;
}
} while ( V_39 != - 1 );
V_16 -= V_43 ;
V_17 += V_43 ;
if ( V_16 < 4 || V_16 > 5 )
F_26 () ;
if ( V_29 ) {
V_23 = V_17 [ 0 ] ;
V_22 = V_17 [ 1 ] ;
} else {
V_22 = V_17 [ 0 ] ;
V_8 = V_17 [ 1 ] ;
}
V_12 = V_17 [ 2 ] ;
V_24 = V_17 [ 3 ] ;
if ( V_16 == 5 && strcmp ( V_17 [ 3 ] , V_17 [ 4 ] ) != 0 ) {
V_25 = V_17 [ 4 ] ;
V_27 = false ;
} else {
F_8 ( F_27 ( & V_25 , L_13 , V_24 ) < 0 ,
L_14 ) ;
V_27 = true ;
}
#ifdef F_21
if ( strcmp ( V_22 , L_15 ) != 0 ) {
fprintf ( V_15 , L_16 ,
V_44 ) ;
exit ( 3 ) ;
}
#endif
V_38 = F_12 ( V_24 , L_8 ) ;
F_8 ( ! V_38 , L_7 , V_24 ) ;
if ( ! V_29 ) {
V_9 = F_5 ( V_8 ) ;
V_13 = F_15 ( V_12 ) ;
F_28 () ;
F_29 ( __LINE__ ) ;
V_33 = F_30 ( V_22 ) ;
F_8 ( ! V_33 , L_17 ) ;
#ifndef F_21
V_34 = F_31 ( NULL , NULL , NULL , NULL ,
V_45 | V_46 | V_47 |
V_48 | V_49 ) ;
F_8 ( ! V_34 , L_18 ) ;
F_8 ( ! F_32 ( V_34 , V_13 , V_9 , V_33 ,
V_45 | V_47 |
V_50 | V_35 |
V_32 ) ,
L_19 ) ;
F_8 ( F_33 ( V_34 , V_38 , NULL , V_45 | V_47 ) < 0 ,
L_20 ) ;
#else
V_36 = F_34 ( V_13 , V_9 , NULL , V_38 ,
V_51 | V_52 |
V_53 | V_32 ) ;
F_8 ( ! V_36 , L_21 ) ;
#endif
if ( V_26 ) {
char * V_54 ;
T_3 * V_11 ;
F_8 ( F_27 ( & V_54 , L_22 , V_24 ) < 0 ,
L_14 ) ;
V_11 = F_12 ( V_54 , L_23 ) ;
F_8 ( ! V_11 , L_7 , V_54 ) ;
#ifndef F_21
F_8 ( F_35 ( V_11 , V_34 , NULL , 0 ) < 0 ,
L_7 , V_54 ) ;
#else
F_8 ( F_36 ( V_11 , V_36 ) < 0 ,
L_7 , V_54 ) ;
#endif
F_14 ( V_11 ) ;
}
if ( V_28 ) {
F_14 ( V_38 ) ;
return 0 ;
}
}
V_37 = F_12 ( V_25 , L_23 ) ;
F_8 ( ! V_37 , L_7 , V_25 ) ;
F_8 ( F_18 ( V_38 ) < 0 , L_7 , V_24 ) ;
while ( ( V_14 = F_16 ( V_38 , V_2 , sizeof( V_2 ) ) ) ,
V_14 > 0 ) {
F_8 ( F_37 ( V_37 , V_2 , V_14 ) < 0 , L_7 , V_25 ) ;
}
F_14 ( V_38 ) ;
F_8 ( V_14 < 0 , L_7 , V_24 ) ;
V_30 = F_38 ( V_37 ) ;
if ( ! V_29 ) {
#ifndef F_21
F_8 ( F_35 ( V_37 , V_34 , NULL , 0 ) < 0 , L_7 , V_25 ) ;
#else
F_8 ( F_36 ( V_37 , V_36 ) < 0 , L_7 , V_25 ) ;
#endif
} else {
T_3 * V_11 ;
V_11 = F_12 ( V_23 , L_8 ) ;
F_8 ( ! V_11 , L_7 , V_23 ) ;
while ( ( V_14 = F_16 ( V_11 , V_2 , sizeof( V_2 ) ) ) , V_14 > 0 )
F_8 ( F_37 ( V_37 , V_2 , V_14 ) < 0 , L_7 , V_25 ) ;
F_14 ( V_11 ) ;
}
V_31 = F_38 ( V_37 ) - V_30 ;
V_19 . V_55 = F_39 ( V_31 ) ;
F_8 ( F_37 ( V_37 , & V_19 , sizeof( V_19 ) ) < 0 , L_7 , V_25 ) ;
F_8 ( F_37 ( V_37 , V_56 , sizeof( V_56 ) - 1 ) < 0 , L_7 , V_25 ) ;
F_8 ( F_14 ( V_37 ) < 0 , L_7 , V_25 ) ;
if ( V_27 )
F_8 ( rename ( V_25 , V_24 ) < 0 , L_7 , V_25 ) ;
return 0 ;
}
