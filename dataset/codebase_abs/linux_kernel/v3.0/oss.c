void T_1 F_1 ( void )
{
int V_1 ;
if ( ! V_2 ) return;
V_3 = (struct V_4 * ) V_5 ;
for ( V_1 = 0 ; V_1 <= V_6 ; V_1 ++ ) {
V_3 -> V_7 [ V_1 ] = V_8 ;
}
V_3 -> V_7 [ V_9 ] = V_10 ;
}
void T_1 F_2 ( void )
{
if ( F_3 ( V_11 , V_12 , V_13 ,
L_1 , ( void * ) V_3 ) )
F_4 ( L_2 , L_1 ) ;
if ( F_3 ( V_14 , V_15 , V_13 ,
L_3 , ( void * ) V_3 ) )
F_4 ( L_2 , L_3 ) ;
if ( F_3 ( V_16 , V_12 , V_13 ,
L_4 , ( void * ) V_3 ) )
F_4 ( L_2 , L_4 ) ;
if ( F_3 ( V_10 , V_17 , V_13 ,
L_5 , ( void * ) V_18 ) )
F_4 ( L_2 , L_5 ) ;
}
void T_1 F_5 ( void )
{
}
static T_2 V_12 ( int V_19 , void * V_20 )
{
int V_21 ;
V_21 = V_3 -> V_22 & ( V_23 | V_24 ) ;
if ( ! V_21 )
return V_25 ;
#ifdef F_6
if ( ( V_26 == 10 ) && ! ( V_21 & V_24 ) ) {
F_7 ( L_6 , V_19 ,
( int ) V_3 -> V_22 ) ;
}
#endif
if ( V_21 & V_23 ) {
V_3 -> V_22 &= ~ V_23 ;
} else if ( V_21 & V_24 ) {
V_3 -> V_22 &= ~ V_24 ;
F_8 ( V_27 ) ;
} else {
}
return V_28 ;
}
static T_2 V_15 ( int V_19 , void * V_20 )
{
int V_21 , V_29 , V_1 ;
V_21 = V_3 -> V_22 & V_30 ;
if ( ! V_21 )
return V_25 ;
#ifdef F_9
if ( V_26 > 7 ) {
F_7 ( L_7 , V_21 ) ;
}
#endif
V_1 = 6 ;
V_29 = 0x40 ;
do {
-- V_1 ;
V_29 >>= 1 ;
if ( V_21 & V_29 ) {
V_3 -> V_22 &= ~ V_29 ;
F_8 ( V_31 + V_1 ) ;
}
} while( V_21 & ( V_29 - 1 ) );
return V_28 ;
}
void F_10 ( int V_19 ) {
#ifdef F_11
F_7 ( L_8 , V_19 ) ;
#endif
switch( V_19 ) {
case V_32 :
V_3 -> V_7 [ V_33 ] = V_34 ;
break;
case V_35 :
V_3 -> V_7 [ V_36 ] = V_37 ;
break;
case V_27 :
V_3 -> V_7 [ V_38 ] = V_11 ;
break;
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
V_19 -= V_31 ;
V_3 -> V_7 [ V_19 ] = V_14 ;
break;
#ifdef F_11
default:
F_7 ( L_9 , V_45 , V_19 ) ;
break;
#endif
}
}
void F_12 ( int V_19 ) {
#ifdef F_11
F_7 ( L_10 , V_19 ) ;
#endif
switch( V_19 ) {
case V_32 :
V_3 -> V_7 [ V_33 ] = V_8 ;
break;
case V_35 :
V_3 -> V_7 [ V_36 ] = V_8 ;
break;
case V_27 :
V_3 -> V_7 [ V_38 ] = V_8 ;
break;
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
V_19 -= V_31 ;
V_3 -> V_7 [ V_19 ] = V_8 ;
break;
#ifdef F_11
default:
F_7 ( L_9 , V_45 , V_19 ) ;
break;
#endif
}
}
void F_13 ( int V_19 ) {
switch( V_19 ) {
case V_32 :
V_3 -> V_22 &= ~ V_46 ;
break;
case V_35 :
V_3 -> V_22 &= ~ V_47 ;
break;
case V_27 :
V_3 -> V_22 &= ~ V_24 ;
break;
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
V_19 -= V_31 ;
V_3 -> V_22 &= ~ ( 1 << V_19 ) ;
break;
}
}
int F_14 ( int V_19 )
{
switch( V_19 ) {
case V_32 :
return V_3 -> V_22 & V_46 ;
break;
case V_35 :
return V_3 -> V_22 & V_47 ;
break;
case V_27 :
return V_3 -> V_22 & V_24 ;
break;
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
V_19 -= V_31 ;
return V_3 -> V_22 & ( 1 << V_19 ) ;
break;
}
return 0 ;
}
