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
if ( V_10 & V_12 ) {
V_3 -> V_11 &= ~ V_12 ;
F_4 ( V_15 ) ;
}
if ( V_10 & V_13 ) {
V_3 -> V_11 &= ~ V_13 ;
F_4 ( V_16 ) ;
}
if ( V_10 & V_14 ) {
V_3 -> V_11 &= ~ V_14 ;
F_4 ( V_17 ) ;
}
}
static void F_5 ( struct V_8 * V_9 )
{
int V_10 , V_18 , V_1 ;
V_10 = V_3 -> V_11 & V_19 ;
if ( ! V_10 )
return;
V_1 = 6 ;
V_18 = 0x40 ;
do {
-- V_1 ;
V_18 >>= 1 ;
if ( V_10 & V_18 ) {
V_3 -> V_11 &= ~ V_18 ;
F_4 ( V_20 + V_1 ) ;
}
} while( V_10 & ( V_18 - 1 ) );
}
void T_1 F_6 ( void )
{
F_7 ( V_21 , F_3 ) ;
F_7 ( V_22 , F_3 ) ;
F_7 ( V_23 , F_5 ) ;
F_7 ( V_24 , F_3 ) ;
F_7 ( V_25 , V_26 ) ;
V_3 -> V_7 [ V_27 ] = V_28 ;
}
void F_8 ( int V_29 ) {
switch( V_29 ) {
case V_15 :
V_3 -> V_7 [ V_30 ] = V_24 ;
return;
case V_17 :
V_3 -> V_7 [ V_31 ] = V_21 ;
return;
case V_16 :
V_3 -> V_7 [ V_32 ] = V_22 ;
return;
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
V_29 -= V_20 ;
V_3 -> V_7 [ V_29 ] = V_23 ;
return;
}
if ( F_9 ( V_29 ) == 1 )
F_10 ( V_29 ) ;
}
void F_11 ( int V_29 ) {
switch( V_29 ) {
case V_15 :
V_3 -> V_7 [ V_30 ] = 0 ;
return;
case V_17 :
V_3 -> V_7 [ V_31 ] = 0 ;
return;
case V_16 :
V_3 -> V_7 [ V_32 ] = 0 ;
return;
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
V_29 -= V_20 ;
V_3 -> V_7 [ V_29 ] = 0 ;
return;
}
if ( F_9 ( V_29 ) == 1 )
F_12 ( V_29 ) ;
}
