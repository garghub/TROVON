int F_1 ( void )
{
short int V_1 ;
T_1 V_2 ;
T_2 V_3 ;
T_3 V_4 ;
int V_5 , V_6 ;
struct V_7 V_8 ;
unsigned char V_9 ;
# ifdef F_2
long V_10 ;
extern void V_11 ( long * V_12 , short int * V_13 ) ;
# else
# ifdef F_3
long long V_10 ;
extern void V_14 ( long long * V_12 , short int * V_13 ) ;
# else
# error "Unsupported Platform."
# endif
# endif
V_2 = F_4 () ;
F_5 ( & V_2 , sizeof V_2 , 1 ) ;
V_2 = 0 ;
V_3 = F_6 () ;
F_5 ( & V_3 , sizeof V_3 , 1 ) ;
V_3 = 0 ;
V_4 = F_7 () ;
F_5 ( & V_4 , sizeof V_4 , 1 ) ;
V_4 = 0 ;
for ( V_5 = 0 ; V_5 < ( V_15 * 4 ) ; V_5 ++ ) {
for ( V_6 = 0 ; V_6 < 99 ; V_6 ++ )
V_8 . V_16 = F_8 () ;
# ifdef F_2
V_10 = 1 ;
V_11 ( & V_10 , & V_1 ) ;
# else
# ifdef F_3
V_10 = 1 ;
V_14 ( & V_10 , & V_1 ) ;
# endif
# endif
F_9 ( V_17 , & V_8 ) ;
V_9 = ( unsigned char ) ( V_8 . V_16 % 256 ) ;
F_5 ( & V_9 , sizeof V_9 , 1 ) ;
V_9 = 0 ;
}
return 1 ;
}
int F_1 ( void )
{
T_4 V_18 = 0 , V_5 ;
unsigned char V_19 [ V_15 ] ;
for ( V_5 = 0 ; V_5 < sizeof( V_19 ) ; V_5 ++ ) {
if ( V_5 % 4 == 0 )
V_18 = F_10 () ;
V_19 [ V_5 ] = V_18 ;
V_18 >>= 8 ;
}
F_5 ( V_19 , sizeof( V_19 ) , V_15 ) ;
F_11 ( V_19 , sizeof( V_19 ) ) ;
return 1 ;
}
int F_1 ( void )
{
unsigned long V_20 ;
T_2 V_3 = F_6 () ;
# if F_12 ( V_21 ) || ( ! F_12 ( V_22 ) && F_12 ( V_23 ) )
unsigned char V_24 [ V_15 ] ;
int V_25 = 0 ;
# endif
# ifdef V_21
static const char * V_26 [] = { V_21 } ;
struct V_27 V_28 [ F_13 ( V_26 ) ] ;
int V_29 ;
unsigned int V_5 ;
# endif
# if ! F_12 ( V_30 ) && F_12 ( V_23 )
static const char * V_31 [] = { V_23 , NULL } ;
const char * * V_32 = NULL ;
# endif
# ifdef V_21
memset ( V_28 , 0 , sizeof( V_28 ) ) ;
for ( V_5 = 0 ; ( V_5 < F_13 ( V_26 ) ) && ( V_25 < V_15 ) ; V_5 ++ ) {
if ( ( V_29 = F_14 ( V_26 [ V_5 ] , V_33
# ifdef F_15
| F_15
# endif
# ifdef F_16
| F_16
# endif
# ifdef F_17
| F_17
# endif
) ) >= 0 ) {
int V_34 = 10 * 1000 ;
int V_35 ;
unsigned int V_36 ;
struct V_27 * V_37 = & V_28 [ V_5 ] ;
if ( F_18 ( V_29 , V_37 ) != 0 ) {
F_19 ( V_29 ) ;
continue;
}
for ( V_36 = 0 ; V_36 < V_5 ; V_36 ++ ) {
if ( V_28 [ V_36 ] . V_38 == V_37 -> V_38 &&
V_28 [ V_36 ] . V_39 == V_37 -> V_39 )
break;
}
if ( V_36 < V_5 ) {
F_19 ( V_29 ) ;
continue;
}
do {
int V_40 = 0 ;
# if F_12 ( V_41 )
struct V_42 V_43 ;
V_43 . V_29 = V_29 ;
V_43 . V_44 = V_45 ;
V_43 . V_46 = 0 ;
if ( F_20 ( & V_43 , 1 , V_34 / 1000 ) < 0 )
V_34 = 0 ;
else
V_40 = ( V_43 . V_46 & V_45 ) != 0 ;
# else
T_5 V_47 ;
struct V_48 V_49 ;
V_49 . V_50 = 0 ;
V_49 . V_51 = V_34 ;
if ( V_52 > 0 && ( unsigned ) V_29 >= V_52 ) {
V_40 = 1 ;
} else {
F_21 ( & V_47 ) ;
F_22 ( V_29 , & V_47 ) ;
if ( F_23 ( V_29 + 1 , & V_47 , NULL , NULL , & V_49 ) >= 0 ) {
V_34 = V_49 . V_51 ;
if ( F_24 ( V_29 , & V_47 ) )
V_40 = 1 ;
} else
V_34 = 0 ;
}
# endif
if ( V_40 ) {
V_35 = F_25 ( V_29 , ( unsigned char * ) V_24 + V_25 ,
V_15 - V_25 ) ;
if ( V_35 > 0 )
V_25 += V_35 ;
} else
V_35 = - 1 ;
if ( V_34 == 10 * 1000 )
V_34 = 0 ;
}
while ( ( V_35 > 0 ||
( V_53 == V_54 || V_53 == V_55 ) ) && V_34 != 0
&& V_25 < V_15 );
F_19 ( V_29 ) ;
}
}
# endif
# if ! F_12 ( V_30 ) && F_12 ( V_23 )
for ( V_32 = V_31 ; * V_32 && V_25 < V_15 ;
V_32 ++ ) {
int V_35 ;
V_35 = F_26 ( * V_32 , ( unsigned char * ) V_24 + V_25 ,
V_15 - V_25 ) ;
if ( V_35 > 0 )
V_25 += V_35 ;
}
# endif
# if F_12 ( V_21 ) || ( ! F_12 ( V_30 ) && F_12 ( V_23 ) )
if ( V_25 > 0 ) {
F_5 ( V_24 , sizeof V_24 , ( double ) V_25 ) ;
F_11 ( V_24 , V_25 ) ;
}
# endif
V_20 = V_3 ;
F_5 ( & V_20 , sizeof( V_20 ) , 0.0 ) ;
V_20 = F_7 () ;
F_5 ( & V_20 , sizeof( V_20 ) , 0.0 ) ;
V_20 = time ( NULL ) ;
F_5 ( & V_20 , sizeof( V_20 ) , 0.0 ) ;
# if F_12 ( V_21 ) || ( ! F_12 ( V_30 ) && F_12 ( V_23 ) )
return 1 ;
# else
return 0 ;
# endif
}
int F_1 ( void )
{
return 0 ;
}
