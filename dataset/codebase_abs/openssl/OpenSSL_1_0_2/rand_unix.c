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
memset ( V_19 , 0 , sizeof( V_19 ) ) ;
return 1 ;
}
int F_1 ( void )
{
unsigned long V_20 ;
T_2 V_3 = F_6 () ;
# if F_11 ( V_21 ) || F_11 ( V_22 )
unsigned char V_23 [ V_15 ] ;
int V_24 = 0 ;
# endif
# ifdef V_21
static const char * V_25 [] = { V_21 } ;
struct V_26 V_27 [ sizeof( V_25 ) / sizeof( V_25 [ 0 ] ) ] ;
int V_28 ;
unsigned int V_5 ;
# endif
# ifdef V_22
static const char * V_29 [] = { V_22 , NULL } ;
const char * * V_30 = NULL ;
# endif
# ifdef V_21
memset ( V_27 , 0 , sizeof( V_27 ) ) ;
for ( V_5 = 0 ; ( V_5 < sizeof( V_25 ) / sizeof( V_25 [ 0 ] ) ) &&
( V_24 < V_15 ) ; V_5 ++ ) {
if ( ( V_28 = F_12 ( V_25 [ V_5 ] , V_31
# ifdef F_13
| F_13
# endif
# ifdef F_14
| F_14
# endif
# ifdef F_15
| F_15
# endif
) ) >= 0 ) {
int V_32 = 10 * 1000 ;
int V_33 ;
unsigned int V_34 ;
struct V_26 * V_35 = & V_27 [ V_5 ] ;
if ( F_16 ( V_28 , V_35 ) != 0 ) {
F_17 ( V_28 ) ;
continue;
}
for ( V_34 = 0 ; V_34 < V_5 ; V_34 ++ ) {
if ( V_27 [ V_34 ] . V_36 == V_35 -> V_36 &&
V_27 [ V_34 ] . V_37 == V_35 -> V_37 )
break;
}
if ( V_34 < V_5 ) {
F_17 ( V_28 ) ;
continue;
}
do {
int V_38 = 0 ;
# if F_11 ( V_39 )
V_38 = 1 ;
# elif F_11 ( V_40 )
struct V_41 V_42 ;
V_42 . V_28 = V_28 ;
V_42 . V_43 = V_44 ;
V_42 . V_45 = 0 ;
if ( F_18 ( & V_42 , 1 , V_32 / 1000 ) < 0 )
V_32 = 0 ;
else
V_38 = ( V_42 . V_45 & V_44 ) != 0 ;
# else
T_5 V_46 ;
struct V_47 V_48 ;
V_48 . V_49 = 0 ;
V_48 . V_50 = V_32 ;
if ( V_51 > 0 && ( unsigned ) V_28 >= V_51 ) {
V_38 = 1 ;
} else {
F_19 ( & V_46 ) ;
F_20 ( V_28 , & V_46 ) ;
if ( F_21 ( V_28 + 1 , & V_46 , NULL , NULL , & V_48 ) >= 0 ) {
V_32 = V_48 . V_50 ;
if ( F_22 ( V_28 , & V_46 ) )
V_38 = 1 ;
} else
V_32 = 0 ;
}
# endif
if ( V_38 ) {
V_33 = F_23 ( V_28 , ( unsigned char * ) V_23 + V_24 ,
V_15 - V_24 ) ;
if ( V_33 > 0 )
V_24 += V_33 ;
# if F_11 ( V_39 )
if ( V_33 == 0 )
F_24 ( V_48 . V_50 ) ;
# endif
} else
V_33 = - 1 ;
if ( V_32 == 10 * 1000 )
V_32 = 0 ;
}
while ( ( V_33 > 0 ||
( V_52 == V_53 || V_52 == V_54 ) ) && V_32 != 0
&& V_24 < V_15 );
F_17 ( V_28 ) ;
}
}
# endif
# ifdef V_22
for ( V_30 = V_29 ; * V_30 && V_24 < V_15 ;
V_30 ++ ) {
int V_33 ;
V_33 = F_25 ( * V_30 , ( unsigned char * ) V_23 + V_24 ,
V_15 - V_24 ) ;
if ( V_33 > 0 )
V_24 += V_33 ;
}
# endif
# if F_11 ( V_21 ) || F_11 ( V_22 )
if ( V_24 > 0 ) {
F_5 ( V_23 , sizeof V_23 , ( double ) V_24 ) ;
F_26 ( V_23 , V_24 ) ;
}
# endif
V_20 = V_3 ;
F_5 ( & V_20 , sizeof( V_20 ) , 0.0 ) ;
V_20 = F_7 () ;
F_5 ( & V_20 , sizeof( V_20 ) , 0.0 ) ;
V_20 = time ( NULL ) ;
F_5 ( & V_20 , sizeof( V_20 ) , 0.0 ) ;
# if F_11 ( V_55 )
{
T_6 V_56 ;
F_27 ( & V_56 ) ;
F_5 ( & V_56 , sizeof( V_56 ) , 0 ) ;
}
# endif
# if F_11 ( V_21 ) || F_11 ( V_22 )
return 1 ;
# else
return 0 ;
# endif
}
int F_1 ( void )
{
return 0 ;
}
