static void F_1 ( void ) {
if( V_1 ) {
F_2 (
( F_3 ( V_1 ) != NULL ) ,
( F_4 ( V_1 ) != NULL ) ) ;
} else {
F_2 ( FALSE , FALSE ) ;
}
}
static void F_5 ( T_1 * V_2 ) {
T_1 * V_3 ;
while( V_2 ) {
V_3 = F_4 ( V_2 ) ;
V_4 = F_6 ( V_4 , V_2 -> V_5 ) ;
V_2 = V_3 ;
}
}
void F_7 ( T_2 V_6 ) {
if( V_6 < 1 ) {
return;
}
if( V_7 ) {
return;
}
if ( V_1 ) {
F_5 ( F_4 ( V_1 ) ) ;
if( F_8 ( V_1 -> V_5 ) == V_6 ) {
F_1 () ;
return;
}
}
V_4 = F_9 ( V_4 , F_10 ( V_6 ) ) ;
V_1 = F_11 ( V_4 ) ;
F_1 () ;
}
void F_12 ( void ) {
F_5 ( V_4 ) ;
V_1 = NULL ;
F_7 ( 0 ) ;
F_1 () ;
}
static void F_13 ( void ) {
T_1 * V_8 ;
if( V_1 ) {
V_8 = F_3 ( V_1 ) ;
if( V_8 ) {
V_1 = V_8 ;
V_7 = TRUE ;
F_14 ( & V_9 , F_8 ( V_8 -> V_5 ) ) ;
V_7 = FALSE ;
}
}
F_1 () ;
}
static void F_15 ( void ) {
T_1 * V_10 ;
if( V_1 ) {
V_10 = F_4 ( V_1 ) ;
if( V_10 ) {
V_1 = V_10 ;
V_7 = TRUE ;
F_14 ( & V_9 , F_8 ( V_10 -> V_5 ) ) ;
V_7 = FALSE ;
}
}
F_1 () ;
}
void F_16 ( T_3 * T_4 V_11 , T_5 V_5 V_11 ) {
F_15 () ;
}
void F_17 ( T_3 * T_4 V_11 , T_5 V_5 V_11 ) {
F_13 () ;
}
