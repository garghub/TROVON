static int T_1
F_1 ( const T_2 * V_1 )
{
return V_1 [ 1 ] > 3 && F_2 ( V_1 + 2 ) == ( ( V_2 << 24 ) | V_3 ) ;
}
static int T_1
F_3 ( const T_2 * V_1 )
{
return V_1 [ 1 ] > 3 && F_2 ( V_1 + 2 ) == ( ( V_4 << 24 ) | V_5 ) ;
}
static int T_1
F_4 ( const T_2 * V_1 )
{
return V_1 [ 1 ] > 3 && F_2 ( V_1 + 2 ) == ( ( V_6 << 24 ) | V_7 ) ;
}
static int T_1
F_5 ( const T_2 * V_1 )
{
return V_1 [ 1 ] > 3 && F_2 ( V_1 + 2 ) == ( ( 0x04 << 24 ) | V_3 ) ;
}
int
F_6 ( T_2 * V_8 , int V_9 , struct V_10 * V_11 )
{
T_2 * V_1 , * V_12 ;
T_2 V_13 = false ;
V_1 = V_8 ;
V_12 = ( T_2 * ) ( V_1 + V_9 ) ;
F_7 ( V_12 - V_1 , 12 ) ;
F_8 ( V_11 , sizeof( * V_11 ) ) ;
V_11 -> V_14 = V_1 ; V_1 += 8 ;
V_11 -> V_15 = F_9 ( * ( V_16 * ) V_1 ) ; V_1 += 2 ;
V_11 -> V_17 = F_9 ( * ( V_16 * ) V_1 ) ; V_1 += 2 ;
V_11 -> V_18 = 0 ;
while ( V_1 < V_12 ) {
switch ( * V_1 ) {
case V_19 :
if ( ! V_13 ) {
V_11 -> V_20 = V_1 ;
V_13 = true ;
}
break;
case V_21 :
V_11 -> V_22 = V_1 ;
break;
case V_23 :
V_11 -> V_24 = V_1 ;
break;
case V_25 :
break;
case V_26 :
V_11 -> V_18 = V_1 [ 2 ] ;
break;
case V_27 :
V_11 -> V_28 = V_1 ;
break;
case V_29 :
break;
case V_30 :
V_11 -> V_31 = V_1 ;
break;
case V_32 :
if ( V_1 [ 1 ] != 1 ) {
return V_33 ;
}
V_11 -> V_34 = V_1 [ 2 ] ;
break;
case V_35 :
V_11 -> V_36 = V_1 ;
break;
case V_37 :
V_11 -> V_38 = V_1 ;
break;
case V_39 :
V_11 -> V_40 = V_1 ;
break;
#ifdef F_10
case V_41 :
V_11 -> V_42 = V_1 ;
break;
#endif
case V_43 :
if ( F_1 ( V_1 ) ) {
V_11 -> V_44 = V_1 ;
} else if ( F_3 ( V_1 ) ) {
V_11 -> V_45 = V_1 ;
} else if ( F_4 ( V_1 ) ) {
V_11 -> V_46 = V_1 ;
} else if( F_5 ( V_1 ) ) {
V_11 -> V_47 = V_1 ;
}
break;
default:
break;
}
V_1 += V_1 [ 1 ] + 2 ;
}
F_11 ( V_11 -> V_22 , V_48 ) ;
F_11 ( V_11 -> V_20 , V_49 ) ;
return 0 ;
}
