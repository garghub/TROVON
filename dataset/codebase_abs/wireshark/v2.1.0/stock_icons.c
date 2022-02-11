static int F_1 ( const T_1 * V_1 , const T_1 * V_2 ) {
return strcmp ( V_1 -> V_3 , V_2 -> V_3 ) ;
}
T_2 * F_2 ( const T_3 * V_4 ) {
#if ! F_3 ( 3 , V_5 , 0 )
return F_4 ( V_4 ) ;
#else
T_2 * V_2 ;
T_1 * V_6 = NULL ;
if ( NULL != ( V_6 = F_5 ( V_4 , V_7 ) ) ) {
return F_6 ( V_6 -> V_8 ) ;
} else if ( NULL != ( V_6 = F_5 ( V_4 , V_9 ) ) ) {
T_1 * V_10 ;
if ( NULL != ( V_10 = F_5 ( V_6 -> V_11 , V_7 ) ) ) {
V_2 = F_7 ( V_10 -> V_11 , V_12 ) ;
} else {
V_2 = F_7 ( V_6 -> V_11 , V_12 ) ;
}
F_8 ( F_9 ( V_2 ) , V_6 -> V_8 ) ;
F_10 ( F_9 ( V_2 ) , TRUE ) ;
return V_2 ;
}
return NULL ;
#endif
}
T_4 * F_11 ( const T_3 * V_4 ) {
#if ! F_3 ( 3 , V_5 , 0 )
return F_12 ( V_4 ) ;
#else
T_4 * V_2 = NULL ;
T_1 * V_6 = NULL ;
if ( NULL != ( V_6 = F_5 ( V_4 , V_7 ) ) ) {
V_2 = F_13 ( NULL , V_6 -> V_8 ) ;
F_14 ( F_15 ( V_2 ) , TRUE ) ;
F_16 ( F_15 ( V_2 ) , V_6 -> V_11 ) ;
} else if ( NULL != ( V_6 = F_5 ( V_4 , V_9 ) ) ) {
T_1 * V_10 ;
if ( NULL != ( V_10 = F_5 ( V_6 -> V_11 , V_7 ) ) ) {
V_2 = F_13 ( NULL , V_6 -> V_8 ) ;
F_14 ( F_15 ( V_2 ) , TRUE ) ;
F_16 ( F_15 ( V_2 ) , V_10 -> V_11 ) ;
} else {
V_2 = F_13 ( NULL , V_6 -> V_8 ) ;
F_16 ( F_15 ( V_2 ) , V_6 -> V_11 ) ;
}
}
return V_2 ;
#endif
}
T_4 * F_17 ( const T_3 * V_4 ) {
#if ! F_3 ( 3 , V_5 , 0 )
return F_18 ( V_4 ) ;
#else
T_4 * V_2 = NULL ;
T_1 * V_6 = NULL ;
if ( NULL != ( V_6 = F_5 ( V_4 , V_7 ) ) ) {
V_2 = F_19 () ;
F_16 ( F_15 ( V_2 ) , V_6 -> V_11 ) ;
F_20 ( F_15 , V_2 , V_6 ) ;
} else if ( NULL != ( V_6 = F_5 ( V_4 , V_9 ) ) ) {
T_1 * V_10 ;
if ( NULL != ( V_10 = F_5 ( V_6 -> V_11 , V_7 ) ) ) {
V_2 = F_19 () ;
F_16 ( F_15 ( V_2 ) , V_10 -> V_11 ) ;
F_20 ( F_15 , V_2 , V_6 ) ;
} else {
V_2 = F_19 () ;
F_16 ( F_15 ( V_2 ) , V_6 -> V_11 ) ;
F_20 ( F_15 , V_2 , V_6 ) ;
}
}
return V_2 ;
#endif
}
T_2 * F_21 ( const T_3 * V_4 , T_5 V_13 ) {
#if ! F_3 ( 3 , V_5 , 0 )
return F_22 ( V_4 , V_13 ) ;
#else
T_1 * V_6 = NULL ;
if ( NULL != ( V_6 = F_5 ( V_4 , V_7 ) ) ) {
return F_23 ( V_6 -> V_11 , V_13 ) ;
} else if ( NULL != ( V_6 = F_5 ( V_4 , V_9 ) ) ) {
T_1 * V_10 ;
if ( NULL != ( V_10 = F_5 ( V_6 -> V_11 , V_7 ) ) ) {
return F_23 ( V_10 -> V_11 , V_13 ) ;
} else {
return F_23 ( V_6 -> V_11 , V_13 ) ;
}
}
return NULL ;
#endif
}
