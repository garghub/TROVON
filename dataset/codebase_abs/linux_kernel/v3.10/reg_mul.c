int F_1 ( T_1 const * V_1 , T_2 V_2 , int V_3 , int V_4 )
{
T_1 * V_5 = & F_2 ( V_3 ) ;
T_1 * V_6 = V_5 ;
T_2 V_7 = F_3 ( V_3 ) ;
T_2 V_8 = F_4 ( V_6 ) ;
T_2 V_9 = ( F_4 ( V_5 ) ^ F_4 ( V_1 ) ) ;
int V_10 ;
if ( ! ( V_7 | V_2 ) ) {
V_10 =
F_5 ( V_5 , V_1 , V_6 , V_4 , V_9 ,
F_6 ( V_5 ) + F_6 ( V_1 ) ) ;
if ( V_10 < 0 ) {
F_7 ( V_6 , V_8 ) ;
return V_10 ;
}
F_8 ( V_3 , V_10 ) ;
return V_10 ;
}
if ( V_7 == V_11 )
V_7 = F_9 ( V_5 ) ;
if ( V_2 == V_11 )
V_2 = F_9 ( V_1 ) ;
if ( ( ( V_7 == V_12 ) && ( V_2 == V_13 ) )
|| ( ( V_7 == V_13 ) && ( V_2 == V_12 ) )
|| ( ( V_7 == V_13 ) && ( V_2 == V_13 ) ) ) {
T_1 V_14 , V_15 ;
if ( F_10 () < 0 )
return V_16 ;
F_11 ( V_5 , & V_14 ) ;
F_11 ( V_1 , & V_15 ) ;
V_10 = F_5 ( & V_14 , & V_15 , V_6 , V_4 , V_9 ,
F_12 ( & V_14 ) + F_12 ( & V_15 ) ) ;
if ( V_10 < 0 ) {
F_7 ( V_6 , V_8 ) ;
return V_10 ;
}
F_8 ( V_3 , V_10 ) ;
return V_10 ;
} else if ( ( V_7 <= V_13 ) && ( V_2 <= V_13 ) ) {
if ( ( ( V_2 == V_13 ) || ( V_7 == V_13 ) )
&& ( F_10 () < 0 ) )
return V_16 ;
F_13 ( & V_17 , V_18 , V_3 ) ;
F_7 ( V_6 , V_9 ) ;
return V_18 ;
}
else if ( ( V_7 == V_19 ) || ( V_2 == V_19 ) ) {
return F_14 ( V_1 , V_2 , V_3 , & F_2 ( 0 ) ) ;
} else if ( ( ( V_7 == V_20 ) && ( V_2 == V_18 ) )
|| ( ( V_2 == V_20 ) && ( V_7 == V_18 ) ) ) {
return F_15 ( V_3 ) ;
} else if ( ( ( V_7 == V_13 ) || ( V_2 == V_13 ) )
&& ( F_10 () < 0 ) ) {
return V_16 ;
} else if ( V_7 == V_20 ) {
F_13 ( V_5 , V_11 , V_3 ) ;
F_7 ( V_6 , V_9 ) ;
return V_11 ;
} else if ( V_2 == V_20 ) {
F_13 ( V_1 , V_11 , V_3 ) ;
F_7 ( V_6 , V_9 ) ;
return V_11 ;
}
#ifdef F_16
else {
F_17 ( V_21 | 0x102 ) ;
return V_16 ;
}
#endif
return 0 ;
}
