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
static void F_3 ( struct V_8 * V_9 )
{
int V_10 = V_3 -> V_11 &
( V_12 | V_13 | V_14 ) ;
#ifdef F_4
if ( ( V_15 == 10 ) && ! ( V_10 & V_13 ) ) {
unsigned int V_16 = F_5 ( V_9 ) ;
F_6 ( L_1 , V_16 ,
( int ) V_3 -> V_11 ) ;
}
#endif
if ( V_10 & V_12 ) {
V_3 -> V_11 &= ~ V_12 ;
F_7 ( V_17 ) ;
}
if ( V_10 & V_13 ) {
V_3 -> V_11 &= ~ V_13 ;
F_7 ( V_18 ) ;
}
if ( V_10 & V_14 ) {
V_3 -> V_11 &= ~ V_14 ;
F_7 ( V_19 ) ;
}
}
static void F_8 ( struct V_8 * V_9 )
{
int V_10 , V_20 , V_1 ;
V_10 = V_3 -> V_11 & V_21 ;
if ( ! V_10 )
return;
#ifdef F_9
if ( V_15 > 7 ) {
F_6 ( L_2 , V_10 ) ;
}
#endif
V_1 = 6 ;
V_20 = 0x40 ;
do {
-- V_1 ;
V_20 >>= 1 ;
if ( V_10 & V_20 ) {
V_3 -> V_11 &= ~ V_20 ;
F_7 ( V_22 + V_1 ) ;
}
} while( V_10 & ( V_20 - 1 ) );
}
void T_1 F_10 ( void )
{
F_11 ( V_23 , F_3 ) ;
F_11 ( V_24 , F_3 ) ;
F_11 ( V_25 , F_8 ) ;
F_11 ( V_26 , F_3 ) ;
F_11 ( V_27 , V_28 ) ;
V_3 -> V_7 [ V_29 ] = V_30 ;
}
void F_12 ( int V_16 ) {
#ifdef F_13
F_6 ( L_3 , V_16 ) ;
#endif
switch( V_16 ) {
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
V_16 -= V_22 ;
V_3 -> V_7 [ V_16 ] = V_25 ;
return;
}
if ( F_14 ( V_16 ) == 1 )
F_15 ( V_16 ) ;
}
void F_16 ( int V_16 ) {
#ifdef F_13
F_6 ( L_4 , V_16 ) ;
#endif
switch( V_16 ) {
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
V_16 -= V_22 ;
V_3 -> V_7 [ V_16 ] = 0 ;
return;
}
if ( F_14 ( V_16 ) == 1 )
F_17 ( V_16 ) ;
}
