T_1 F_1 ( const T_2 * V_1 ) {
T_2 * * V_2 ;
if ( ! V_3 )
V_3 = F_2 ( V_4 , V_5 ) ;
V_2 = F_3 ( V_1 , L_1 , 2 ) ;
if ( V_2 [ 0 ] && V_2 [ 1 ] ) {
T_3 * V_6 = F_4 ( V_3 , V_2 [ 0 ] ) ;
if ( V_6 ) {
F_5 ( V_6 , V_2 [ 1 ] ) ;
F_6 ( V_2 [ 0 ] ) ;
} else {
V_6 = F_7 () ;
F_5 ( V_6 , V_2 [ 1 ] ) ;
F_8 ( V_3 , V_2 [ 0 ] , V_6 ) ;
}
F_6 ( V_2 ) ;
return TRUE ;
} else {
F_9 ( V_2 ) ;
return FALSE ;
}
}
T_4 F_10 ( const T_2 * V_7 ) {
T_3 * V_6 ;
if ( ! V_3 )
return 0 ;
V_6 = F_4 ( V_3 , V_7 ) ;
if ( V_6 ) {
return V_6 -> V_8 ;
} else {
return 0 ;
}
}
const T_2 * F_11 ( const T_2 * V_7 , T_5 V_9 ) {
T_3 * V_6 ;
if ( ! V_3 )
return 0 ;
V_6 = F_4 ( V_3 , V_7 ) ;
if ( V_6 ) {
if ( V_6 -> V_8 > V_9 ) {
return F_12 ( V_6 , V_9 ) ;
} else {
return NULL ;
}
} else {
return NULL ;
}
}
extern const T_2 * F_13 ( const T_2 * V_7 ) {
T_3 * V_6 ;
if ( ! V_3 )
return 0 ;
V_6 = F_4 ( V_3 , V_7 ) ;
if ( V_6 ) {
if ( V_6 -> V_8 )
return F_14 ( V_6 , 0 ) ;
else
return NULL ;
} else {
return NULL ;
}
}
