void T_1 F_1 ( void )
{
int V_1 ;
if ( ! V_2 ) return;
V_3 = (struct V_4 * ) V_5 ;
for ( V_1 = 0 ; V_1 < V_6 ; V_1 ++ )
V_3 -> V_7 [ V_1 ] = 0 ;
}
void T_1 F_2 ( void )
{
}
static void F_3 ( unsigned int V_8 , struct V_9 * V_10 )
{
int V_11 = V_3 -> V_12 &
( V_13 | V_14 | V_15 ) ;
#ifdef F_4
if ( ( V_16 == 10 ) && ! ( V_11 & V_14 ) ) {
F_5 ( L_1 , V_8 ,
( int ) V_3 -> V_12 ) ;
}
#endif
if ( V_11 & V_13 ) {
V_3 -> V_12 &= ~ V_13 ;
F_6 ( V_17 ) ;
}
if ( V_11 & V_14 ) {
V_3 -> V_12 &= ~ V_14 ;
F_6 ( V_18 ) ;
}
if ( V_11 & V_15 ) {
V_3 -> V_12 &= ~ V_15 ;
F_6 ( V_19 ) ;
}
}
static void F_7 ( unsigned int V_8 , struct V_9 * V_10 )
{
int V_11 , V_20 , V_1 ;
V_11 = V_3 -> V_12 & V_21 ;
if ( ! V_11 )
return;
#ifdef F_8
if ( V_16 > 7 ) {
F_5 ( L_2 , V_11 ) ;
}
#endif
V_1 = 6 ;
V_20 = 0x40 ;
do {
-- V_1 ;
V_20 >>= 1 ;
if ( V_11 & V_20 ) {
V_3 -> V_12 &= ~ V_20 ;
F_6 ( V_22 + V_1 ) ;
}
} while( V_11 & ( V_20 - 1 ) );
}
void T_1 F_9 ( void )
{
F_10 ( V_23 , F_3 ) ;
F_10 ( V_24 , F_3 ) ;
F_10 ( V_25 , F_7 ) ;
F_10 ( V_26 , F_3 ) ;
F_10 ( V_27 , V_28 ) ;
V_3 -> V_7 [ V_29 ] = V_30 ;
}
void F_11 ( int V_8 ) {
#ifdef F_12
F_5 ( L_3 , V_8 ) ;
#endif
switch( V_8 ) {
case V_17 :
V_3 -> V_7 [ V_31 ] = V_26 ;
return;
case V_19 :
V_3 -> V_7 [ V_32 ] = V_23 ;
return;
case V_18 :
V_3 -> V_7 [ V_33 ] = V_24 ;
return;
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
V_8 -= V_22 ;
V_3 -> V_7 [ V_8 ] = V_25 ;
return;
}
if ( F_13 ( V_8 ) == 1 )
F_14 ( V_8 ) ;
}
void F_15 ( int V_8 ) {
#ifdef F_12
F_5 ( L_4 , V_8 ) ;
#endif
switch( V_8 ) {
case V_17 :
V_3 -> V_7 [ V_31 ] = 0 ;
return;
case V_19 :
V_3 -> V_7 [ V_32 ] = 0 ;
return;
case V_18 :
V_3 -> V_7 [ V_33 ] = 0 ;
return;
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
V_8 -= V_22 ;
V_3 -> V_7 [ V_8 ] = 0 ;
return;
}
if ( F_13 ( V_8 ) == 1 )
F_16 ( V_8 ) ;
}
