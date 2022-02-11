int F_1 ( struct V_1 * V_1 , unsigned char V_2 , int V_3 )
{
F_2 ( V_1 -> V_4 ) ;
V_1 -> V_5 = 1 ;
V_1 -> V_6 |= V_7 ;
F_3 ( V_1 -> V_4 ) ;
if ( F_4 ( V_1 -> V_4 , V_2 ) == 0 )
F_5 ( V_1 -> V_8 ,
! ( V_1 -> V_6 & V_7 ) ,
F_6 ( V_3 ) ) ;
F_2 ( V_1 -> V_4 ) ;
V_1 -> V_6 &= ~ V_7 ;
F_3 ( V_1 -> V_4 ) ;
return - V_1 -> V_5 ;
}
void F_7 ( struct V_1 * V_1 )
{
F_8 ( & V_1 -> V_9 ) ;
if ( F_9 ( V_1 -> V_4 ) )
F_10 () ;
}
void F_11 ( struct V_1 * V_1 )
{
if ( F_9 ( V_1 -> V_4 ) )
F_12 () ;
F_13 ( & V_1 -> V_9 ) ;
}
void F_14 ( struct V_1 * V_1 , int V_10 , int V_3 )
{
if ( V_10 > sizeof( V_1 -> V_11 ) ) {
F_15 ( 1 ) ;
V_10 = sizeof( V_1 -> V_11 ) ;
}
F_7 ( V_1 ) ;
F_2 ( V_1 -> V_4 ) ;
V_1 -> V_6 = V_12 ;
V_1 -> V_13 = V_10 ;
F_3 ( V_1 -> V_4 ) ;
F_5 ( V_1 -> V_8 ,
! ( V_1 -> V_6 & V_12 ) ,
F_6 ( V_3 ) ) ;
F_11 ( V_1 ) ;
}
int F_16 ( char V_14 )
{
static const char V_15 [] = {
0xab ,
0xac ,
0x2b ,
0x5d ,
0x60 ,
0x47 ,
} ;
return memchr ( V_15 , V_14 , sizeof( V_15 ) ) != NULL ;
}
static int F_17 ( struct V_1 * V_1 , int V_16 , int V_3 )
{
switch ( V_16 ) {
case V_17 :
if ( V_3 > F_6 ( 100 ) )
V_3 = F_6 ( 100 ) ;
break;
case V_18 :
if ( V_1 -> V_11 [ 1 ] == 0xaa ) {
F_2 ( V_1 -> V_4 ) ;
V_1 -> V_6 = 0 ;
F_3 ( V_1 -> V_4 ) ;
V_3 = 0 ;
}
if ( ! F_16 ( V_1 -> V_11 [ 1 ] ) ) {
F_2 ( V_1 -> V_4 ) ;
V_1 -> V_6 = V_1 -> V_13 = 0 ;
F_3 ( V_1 -> V_4 ) ;
V_3 = 0 ;
}
break;
default:
break;
}
return V_3 ;
}
int F_18 ( struct V_1 * V_1 , unsigned char * V_19 , int V_16 )
{
int V_3 ;
int V_20 = ( V_16 >> 12 ) & 0xf ;
int V_21 = ( V_16 >> 8 ) & 0xf ;
int V_22 = - 1 ;
int V_23 ;
if ( V_21 > sizeof( V_1 -> V_11 ) ) {
F_15 ( 1 ) ;
return - 1 ;
}
if ( V_20 && ! V_19 ) {
F_15 ( 1 ) ;
return - 1 ;
}
F_2 ( V_1 -> V_4 ) ;
V_1 -> V_6 = V_16 == V_18 ? V_24 : 0 ;
V_1 -> V_13 = V_21 ;
if ( V_21 && V_19 )
for ( V_23 = 0 ; V_23 < V_21 ; V_23 ++ )
V_1 -> V_11 [ ( V_21 - 1 ) - V_23 ] = V_19 [ V_23 ] ;
F_3 ( V_1 -> V_4 ) ;
if ( F_1 ( V_1 , V_16 & 0xff ,
V_16 == V_17 ? 1000 : 200 ) )
goto V_25;
for ( V_23 = 0 ; V_23 < V_20 ; V_23 ++ )
if ( F_1 ( V_1 , V_19 [ V_23 ] , 200 ) )
goto V_25;
V_3 = F_6 ( V_16 == V_17 ? 4000 : 500 ) ;
V_3 = F_5 ( V_1 -> V_8 ,
! ( V_1 -> V_6 & V_26 ) , V_3 ) ;
if ( V_1 -> V_13 && ! ( V_1 -> V_6 & V_26 ) ) {
V_3 = F_17 ( V_1 , V_16 , V_3 ) ;
F_5 ( V_1 -> V_8 ,
! ( V_1 -> V_6 & V_12 ) , V_3 ) ;
}
if ( V_19 )
for ( V_23 = 0 ; V_23 < V_21 ; V_23 ++ )
V_19 [ V_23 ] = V_1 -> V_11 [ ( V_21 - 1 ) - V_23 ] ;
if ( V_1 -> V_13 && ( V_16 != V_17 || V_1 -> V_13 != 1 ) )
goto V_25;
V_22 = 0 ;
V_25:
F_2 ( V_1 -> V_4 ) ;
V_1 -> V_6 = 0 ;
F_3 ( V_1 -> V_4 ) ;
return V_22 ;
}
int F_19 ( struct V_1 * V_1 , unsigned char * V_19 , int V_16 )
{
int V_22 ;
F_7 ( V_1 ) ;
V_22 = F_18 ( V_1 , V_19 , V_16 ) ;
F_11 ( V_1 ) ;
return V_22 ;
}
void F_20 ( struct V_1 * V_1 , struct V_4 * V_4 )
{
F_21 ( & V_1 -> V_9 ) ;
F_22 ( & V_1 -> V_9 , V_4 -> V_27 ) ;
F_23 ( & V_1 -> V_8 ) ;
V_1 -> V_4 = V_4 ;
}
int F_24 ( struct V_1 * V_1 , unsigned char V_28 )
{
switch ( V_28 ) {
case V_29 :
V_1 -> V_5 = 0 ;
break;
case V_30 :
V_1 -> V_6 |= V_31 ;
V_1 -> V_5 = V_30 ;
break;
case V_32 :
if ( V_1 -> V_6 & V_31 ) {
V_1 -> V_6 &= ~ V_31 ;
V_1 -> V_5 = V_32 ;
break;
}
case 0x00 :
case 0x03 :
case 0x04 :
if ( V_1 -> V_6 & V_24 ) {
V_1 -> V_5 = 0 ;
break;
}
default:
return 0 ;
}
if ( ! V_1 -> V_5 ) {
V_1 -> V_6 &= ~ V_31 ;
if ( V_1 -> V_13 )
V_1 -> V_6 |= V_12 | V_26 ;
}
V_1 -> V_6 &= ~ V_7 ;
F_25 ( & V_1 -> V_8 ) ;
if ( V_28 != V_29 )
F_26 ( V_1 , V_28 ) ;
return 1 ;
}
int F_26 ( struct V_1 * V_1 , unsigned char V_28 )
{
if ( V_1 -> V_13 )
V_1 -> V_11 [ -- V_1 -> V_13 ] = V_28 ;
if ( V_1 -> V_6 & V_26 ) {
V_1 -> V_6 &= ~ V_26 ;
if ( V_1 -> V_13 )
F_25 ( & V_1 -> V_8 ) ;
}
if ( ! V_1 -> V_13 ) {
V_1 -> V_6 &= ~ V_12 ;
F_25 ( & V_1 -> V_8 ) ;
}
return 1 ;
}
void F_27 ( struct V_1 * V_1 )
{
if ( V_1 -> V_6 & V_7 )
V_1 -> V_5 = 1 ;
if ( V_1 -> V_6 & ( V_7 | V_12 ) )
F_25 ( & V_1 -> V_8 ) ;
V_1 -> V_6 &= V_31 ;
}
