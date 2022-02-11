static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 ) {
int V_5 = 0 ;
if ( V_6 ) {
F_2 ( V_6 , V_1 , V_2 , V_3 ) ;
V_5 += F_3 ( V_1 , V_5 ) ;
}
return V_5 ;
}
static int
F_4 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 ) {
int V_5 = 0 ;
if ( V_7 ) {
F_2 ( V_7 , V_1 , V_2 , V_3 ) ;
V_5 += F_3 ( V_1 , V_5 ) ;
}
return V_5 ;
}
static T_5 * F_5 ( const T_6 * V_8 ) {
T_5 * V_9 = NULL ;
T_5 * V_10 ;
for ( V_10 = V_11 ; V_10 -> V_12 ; V_10 ++ ) {
if ( V_10 -> V_13 && ! strcmp ( V_8 , V_10 -> V_13 ) ) { V_9 = V_10 ; break; }
if ( V_10 -> V_14 && ! strcmp ( V_8 , V_10 -> V_14 ) ) { V_9 = V_10 ; break; }
if ( V_10 -> V_15 && ! strcmp ( V_8 , V_10 -> V_15 ) ) { V_9 = V_10 ; break; }
if ( V_10 -> V_16 && ! strcmp ( V_8 , V_10 -> V_16 ) ) { V_9 = V_10 ; break; }
}
return V_9 ;
}
static int
F_6 ( T_1 * V_1 V_4 , T_2 * V_2 , T_3 * V_3 , void * T_4 ) {
int V_5 = 0 ;
T_7 * V_17 ;
T_5 * V_9 ;
if ( T_4 == NULL )
return 0 ;
V_17 = F_7 ( T_4 ) ;
F_8 ( V_17 ) ;
if ( V_3 ) {
V_9 = F_5 ( V_2 -> V_18 ) ;
if ( V_9 ) {
F_9 ( V_17 -> V_19 , L_1 , V_9 -> V_20 ) ;
F_9 ( F_10 ( F_11 ( V_3 ) ) , L_2 , V_9 -> V_20 ) ;
} else {
F_9 ( V_17 -> V_19 , L_3 , V_2 -> V_18 ) ;
}
}
return V_5 ;
}
void F_12 ( void ) {
T_5 * V_9 ;
static T_8 V_21 [] = {
#include "packet-h460-hfarr.c"
} ;
static T_9 * V_22 [] = {
#include "packet-h460-ettarr.c"
} ;
V_23 = F_13 ( V_24 , V_25 , V_26 ) ;
F_14 ( V_23 , V_21 , F_15 ( V_21 ) ) ;
F_16 ( V_22 , F_15 ( V_22 ) ) ;
for ( V_9 = V_11 ; V_9 -> V_12 ; V_9 ++ ) {
if ( V_9 -> V_27 & V_28 ) V_9 -> V_13 = F_17 ( F_18 () , L_4 , V_9 -> V_12 ) ;
if ( V_9 -> V_27 & V_29 ) V_9 -> V_14 = F_17 ( F_18 () , L_5 , V_9 -> V_12 ) ;
if ( V_9 -> V_27 & V_30 ) V_9 -> V_15 = F_17 ( F_18 () , L_6 , V_9 -> V_12 ) ;
if ( V_9 -> V_27 & V_31 ) V_9 -> V_16 = F_17 ( F_18 () , L_7 , V_9 -> V_12 ) ;
if ( V_9 -> V_32 ) V_9 -> V_33 = F_19 ( V_9 -> V_32 , V_23 ) ;
}
}
void F_20 ( void )
{
T_5 * V_9 ;
T_10 V_34 ;
V_6 = F_21 ( L_8 , V_23 ) ;
V_7 = F_21 ( L_9 , V_23 ) ;
V_34 = F_19 ( F_6 , V_23 ) ;
for ( V_9 = V_11 ; V_9 -> V_12 ; V_9 ++ ) {
if ( V_9 -> V_13 ) F_22 ( L_10 , V_9 -> V_13 , V_34 ) ;
if ( V_9 -> V_14 ) F_22 ( L_10 , V_9 -> V_14 , V_34 ) ;
if ( V_9 -> V_15 ) F_22 ( L_11 , V_9 -> V_15 , V_34 ) ;
if ( V_9 -> V_16 ) F_22 ( L_11 , V_9 -> V_16 , V_34 ) ;
if ( V_9 -> V_33 ) {
if ( V_9 -> V_13 ) F_22 ( L_12 , V_9 -> V_13 , V_9 -> V_33 ) ;
if ( V_9 -> V_14 ) F_22 ( L_12 , V_9 -> V_14 , V_9 -> V_33 ) ;
if ( V_9 -> V_15 ) F_22 ( L_13 , V_9 -> V_15 , V_9 -> V_33 ) ;
if ( V_9 -> V_16 ) F_22 ( L_13 , V_9 -> V_16 , V_9 -> V_33 ) ;
}
}
}
