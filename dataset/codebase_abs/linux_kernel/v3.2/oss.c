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
}
static void F_3 ( unsigned int V_11 , struct V_12 * V_13 )
{
int V_14 ;
V_14 = V_3 -> V_15 & ( V_16 | V_17 ) ;
if ( ! V_14 )
return;
#ifdef F_4
if ( ( V_18 == 10 ) && ! ( V_14 & V_17 ) ) {
F_5 ( L_1 , V_11 ,
( int ) V_3 -> V_15 ) ;
}
#endif
if ( V_14 & V_16 ) {
V_3 -> V_15 &= ~ V_16 ;
} else if ( V_14 & V_17 ) {
V_3 -> V_15 &= ~ V_17 ;
F_6 ( V_19 ) ;
} else {
}
}
static void F_7 ( unsigned int V_11 , struct V_12 * V_13 )
{
int V_14 , V_20 , V_1 ;
V_14 = V_3 -> V_15 & V_21 ;
if ( ! V_14 )
return;
#ifdef F_8
if ( V_18 > 7 ) {
F_5 ( L_2 , V_14 ) ;
}
#endif
V_1 = 6 ;
V_20 = 0x40 ;
do {
-- V_1 ;
V_20 >>= 1 ;
if ( V_14 & V_20 ) {
V_3 -> V_15 &= ~ V_20 ;
F_6 ( V_22 + V_1 ) ;
}
} while( V_14 & ( V_20 - 1 ) );
}
void T_1 F_9 ( void )
{
F_10 ( V_23 , F_3 ) ;
F_10 ( V_24 , F_7 ) ;
F_10 ( V_25 , F_3 ) ;
F_10 ( V_10 , V_26 ) ;
}
void F_11 ( int V_11 ) {
#ifdef F_12
F_5 ( L_3 , V_11 ) ;
#endif
switch( V_11 ) {
case V_27 :
V_3 -> V_7 [ V_28 ] = V_29 ;
break;
case V_30 :
V_3 -> V_7 [ V_31 ] = V_32 ;
break;
case V_19 :
V_3 -> V_7 [ V_33 ] = V_23 ;
break;
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
V_11 -= V_22 ;
V_3 -> V_7 [ V_11 ] = V_24 ;
break;
#ifdef F_12
default:
F_5 ( L_4 , V_40 , V_11 ) ;
break;
#endif
}
}
void F_13 ( int V_11 ) {
#ifdef F_12
F_5 ( L_5 , V_11 ) ;
#endif
switch( V_11 ) {
case V_27 :
V_3 -> V_7 [ V_28 ] = V_8 ;
break;
case V_30 :
V_3 -> V_7 [ V_31 ] = V_8 ;
break;
case V_19 :
V_3 -> V_7 [ V_33 ] = V_8 ;
break;
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
V_11 -= V_22 ;
V_3 -> V_7 [ V_11 ] = V_8 ;
break;
#ifdef F_12
default:
F_5 ( L_4 , V_40 , V_11 ) ;
break;
#endif
}
}
void F_14 ( int V_11 ) {
switch( V_11 ) {
case V_27 :
V_3 -> V_15 &= ~ V_41 ;
break;
case V_30 :
V_3 -> V_15 &= ~ V_42 ;
break;
case V_19 :
V_3 -> V_15 &= ~ V_17 ;
break;
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
V_11 -= V_22 ;
V_3 -> V_15 &= ~ ( 1 << V_11 ) ;
break;
}
}
int F_15 ( int V_11 )
{
switch( V_11 ) {
case V_27 :
return V_3 -> V_15 & V_41 ;
break;
case V_30 :
return V_3 -> V_15 & V_42 ;
break;
case V_19 :
return V_3 -> V_15 & V_17 ;
break;
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
V_11 -= V_22 ;
return V_3 -> V_15 & ( 1 << V_11 ) ;
break;
}
return 0 ;
}
