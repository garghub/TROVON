static int F_1 ( void )
{
int V_1 = - 1 , V_2 , V_3 , V_4 , V_5 ;
long long V_6 = 0 , V_7 , V_8 , V_9 ;
V_2 = F_2 ( V_10 , sizeof( V_5 ) , sizeof( V_6 ) ,
256 ) ;
if ( V_2 < 0 ) {
printf ( L_1 , strerror ( V_11 ) ) ;
goto V_12;
}
struct V_13 V_14 [] = {
F_3 ( V_15 , V_16 ) ,
F_4 ( V_17 , V_18 + F_5 ( struct V_19 , V_20 ) ) ,
F_6 ( V_21 , V_22 , V_23 , - 4 ) ,
F_3 ( V_24 , V_22 ) ,
F_7 ( V_25 , V_24 , - 4 ) ,
F_8 ( V_16 , V_2 ) ,
F_9 ( V_26 | V_27 , 0 , 0 , 0 , V_28 ) ,
F_10 ( V_29 , V_23 , 0 , 2 ) ,
F_11 ( V_16 , 1 ) ,
F_9 ( V_30 | V_31 | V_32 , V_23 , V_16 , 0 , 0 ) ,
F_11 ( V_23 , 0 ) ,
F_12 () ,
} ;
V_3 = F_13 ( V_33 , V_14 , sizeof( V_14 ) ,
L_2 ) ;
if ( V_3 < 0 ) {
printf ( L_3 , strerror ( V_11 ) ) ;
goto V_12;
}
V_1 = F_14 ( L_4 ) ;
if ( F_15 ( V_1 , V_34 , V_35 , & V_3 ,
sizeof( V_3 ) ) < 0 ) {
printf ( L_5 , strerror ( V_11 ) ) ;
goto V_12;
}
for ( V_4 = 0 ; V_4 < 10 ; V_4 ++ ) {
V_5 = V_36 ;
assert ( F_16 ( V_2 , & V_5 , & V_7 ) == 0 ) ;
V_5 = V_37 ;
assert ( F_16 ( V_2 , & V_5 , & V_8 ) == 0 ) ;
V_5 = V_38 ;
assert ( F_16 ( V_2 , & V_5 , & V_9 ) == 0 ) ;
printf ( L_6 ,
V_7 , V_8 , V_9 ) ;
F_17 ( 1 ) ;
}
V_12:
return 0 ;
}
int main ( void )
{
T_1 * V_39 ;
V_39 = F_18 ( L_7 , L_8 ) ;
( void ) V_39 ;
return F_1 () ;
}
