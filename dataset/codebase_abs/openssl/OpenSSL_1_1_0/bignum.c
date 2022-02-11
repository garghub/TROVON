int F_1 ( int * V_1 , char * * * V_2 ) {
return 1 ;
}
int F_2 ( const T_1 * V_3 , T_2 V_4 ) {
static T_3 * V_5 ;
static T_4 * V_6 ;
static T_4 * V_7 ;
static T_4 * V_8 ;
static T_4 * V_9 ;
static T_4 * V_10 ;
int V_11 = 0 ;
T_2 V_12 = 0 , V_13 = 0 , V_14 = 0 ;
int V_15 = 0 , V_16 = 0 , V_17 = 0 ;
if ( V_5 == NULL ) {
V_6 = F_3 () ;
V_7 = F_3 () ;
V_8 = F_3 () ;
V_9 = F_3 () ;
V_10 = F_3 () ;
V_5 = F_4 () ;
}
if ( V_4 > 2 ) {
V_4 -= 3 ;
V_12 = ( V_3 [ 0 ] * V_4 ) / 255 ;
++ V_3 ;
V_13 = ( V_3 [ 0 ] * ( V_4 - V_12 ) ) / 255 ;
++ V_3 ;
V_14 = V_4 - V_12 - V_13 ;
V_15 = V_3 [ 0 ] & 1 ;
V_16 = V_3 [ 0 ] & 2 ;
V_17 = V_3 [ 0 ] & 4 ;
++ V_3 ;
}
F_5 ( F_6 ( V_3 , V_12 , V_6 ) == V_6 ) ;
F_7 ( V_6 , V_15 ) ;
F_5 ( F_6 ( V_3 + V_12 , V_13 , V_7 ) == V_7 ) ;
F_7 ( V_7 , V_16 ) ;
F_5 ( F_6 ( V_3 + V_12 + V_13 , V_14 , V_8 ) == V_8 ) ;
F_7 ( V_8 , V_17 ) ;
if ( F_8 ( V_8 ) ) {
V_11 = 1 ;
goto V_18;
}
F_5 ( F_9 ( V_9 , V_6 , V_7 , V_8 , V_5 ) ) ;
F_5 ( F_10 ( V_10 , V_6 , V_7 , V_8 , V_5 ) ) ;
V_11 = F_11 ( V_9 , V_10 ) == 0 ;
if ( ! V_11 ) {
F_12 ( stdout , V_6 ) ;
putchar ( '\n' ) ;
F_12 ( stdout , V_7 ) ;
putchar ( '\n' ) ;
F_12 ( stdout , V_8 ) ;
putchar ( '\n' ) ;
F_12 ( stdout , V_9 ) ;
putchar ( '\n' ) ;
F_12 ( stdout , V_10 ) ;
putchar ( '\n' ) ;
}
V_18:
F_5 ( V_11 ) ;
return 0 ;
}
