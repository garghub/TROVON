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
struct V_9 * V_10 = V_1 -> V_4 -> V_11 ? : & V_1 -> V_12 ;
F_8 ( V_10 ) ;
}
void F_9 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_4 -> V_11 ? : & V_1 -> V_12 ;
F_10 ( V_10 ) ;
}
void F_11 ( struct V_1 * V_1 , int V_13 , int V_3 )
{
if ( V_13 > sizeof( V_1 -> V_14 ) ) {
F_12 ( 1 ) ;
V_13 = sizeof( V_1 -> V_14 ) ;
}
F_7 ( V_1 ) ;
F_2 ( V_1 -> V_4 ) ;
V_1 -> V_6 = V_15 ;
V_1 -> V_16 = V_13 ;
F_3 ( V_1 -> V_4 ) ;
F_5 ( V_1 -> V_8 ,
! ( V_1 -> V_6 & V_15 ) ,
F_6 ( V_3 ) ) ;
F_9 ( V_1 ) ;
}
int F_13 ( char V_17 )
{
static const char V_18 [] = {
0xab ,
0xac ,
0x2b ,
0x5d ,
0x60 ,
0x47 ,
} ;
return memchr ( V_18 , V_17 , sizeof( V_18 ) ) != NULL ;
}
static int F_14 ( struct V_1 * V_1 , int V_19 , int V_3 )
{
switch ( V_19 ) {
case V_20 :
if ( V_3 > F_6 ( 100 ) )
V_3 = F_6 ( 100 ) ;
break;
case V_21 :
if ( V_1 -> V_14 [ 1 ] == 0xaa ) {
F_2 ( V_1 -> V_4 ) ;
V_1 -> V_6 = 0 ;
F_3 ( V_1 -> V_4 ) ;
V_3 = 0 ;
}
if ( ! F_13 ( V_1 -> V_14 [ 1 ] ) ) {
F_2 ( V_1 -> V_4 ) ;
V_1 -> V_6 = V_1 -> V_16 = 0 ;
F_3 ( V_1 -> V_4 ) ;
V_3 = 0 ;
}
break;
default:
break;
}
return V_3 ;
}
int F_15 ( struct V_1 * V_1 , unsigned char * V_22 , int V_19 )
{
int V_3 ;
int V_23 = ( V_19 >> 12 ) & 0xf ;
int V_24 = ( V_19 >> 8 ) & 0xf ;
int V_25 = - 1 ;
int V_26 ;
if ( V_24 > sizeof( V_1 -> V_14 ) ) {
F_12 ( 1 ) ;
return - 1 ;
}
if ( V_23 && ! V_22 ) {
F_12 ( 1 ) ;
return - 1 ;
}
F_2 ( V_1 -> V_4 ) ;
V_1 -> V_6 = V_19 == V_21 ? V_27 : 0 ;
V_1 -> V_16 = V_24 ;
if ( V_24 && V_22 )
for ( V_26 = 0 ; V_26 < V_24 ; V_26 ++ )
V_1 -> V_14 [ ( V_24 - 1 ) - V_26 ] = V_22 [ V_26 ] ;
F_3 ( V_1 -> V_4 ) ;
if ( F_1 ( V_1 , V_19 & 0xff ,
V_19 == V_20 ? 1000 : 200 ) ) {
F_2 ( V_1 -> V_4 ) ;
goto V_28;
}
for ( V_26 = 0 ; V_26 < V_23 ; V_26 ++ ) {
if ( F_1 ( V_1 , V_22 [ V_26 ] , 200 ) ) {
F_2 ( V_1 -> V_4 ) ;
goto V_28;
}
}
V_3 = F_6 ( V_19 == V_20 ? 4000 : 500 ) ;
V_3 = F_5 ( V_1 -> V_8 ,
! ( V_1 -> V_6 & V_29 ) , V_3 ) ;
if ( V_1 -> V_16 && ! ( V_1 -> V_6 & V_29 ) ) {
V_3 = F_14 ( V_1 , V_19 , V_3 ) ;
F_5 ( V_1 -> V_8 ,
! ( V_1 -> V_6 & V_15 ) , V_3 ) ;
}
F_2 ( V_1 -> V_4 ) ;
if ( V_22 )
for ( V_26 = 0 ; V_26 < V_24 ; V_26 ++ )
V_22 [ V_26 ] = V_1 -> V_14 [ ( V_24 - 1 ) - V_26 ] ;
if ( V_1 -> V_16 && ( V_19 != V_20 || V_1 -> V_16 != 1 ) )
goto V_28;
V_25 = 0 ;
V_28:
V_1 -> V_6 = 0 ;
F_3 ( V_1 -> V_4 ) ;
return V_25 ;
}
int F_16 ( struct V_1 * V_1 , unsigned char * V_22 , int V_19 )
{
int V_25 ;
F_7 ( V_1 ) ;
V_25 = F_15 ( V_1 , V_22 , V_19 ) ;
F_9 ( V_1 ) ;
return V_25 ;
}
void F_17 ( struct V_1 * V_1 , struct V_4 * V_4 )
{
F_18 ( & V_1 -> V_12 ) ;
F_19 ( & V_1 -> V_12 , V_4 -> V_30 ) ;
F_20 ( & V_1 -> V_8 ) ;
V_1 -> V_4 = V_4 ;
}
int F_21 ( struct V_1 * V_1 , unsigned char V_31 )
{
switch ( V_31 ) {
case V_32 :
V_1 -> V_5 = 0 ;
break;
case V_33 :
V_1 -> V_6 |= V_34 ;
V_1 -> V_5 = V_33 ;
break;
case V_35 :
if ( V_1 -> V_6 & V_34 ) {
V_1 -> V_6 &= ~ V_34 ;
V_1 -> V_5 = V_35 ;
break;
}
case 0x00 :
case 0x03 :
case 0x04 :
if ( V_1 -> V_6 & V_27 ) {
V_1 -> V_5 = 0 ;
break;
}
default:
return 0 ;
}
if ( ! V_1 -> V_5 ) {
V_1 -> V_6 &= ~ V_34 ;
if ( V_1 -> V_16 )
V_1 -> V_6 |= V_15 | V_29 ;
}
V_1 -> V_6 &= ~ V_7 ;
F_22 ( & V_1 -> V_8 ) ;
if ( V_31 != V_32 )
F_23 ( V_1 , V_31 ) ;
return 1 ;
}
int F_23 ( struct V_1 * V_1 , unsigned char V_31 )
{
if ( V_1 -> V_16 )
V_1 -> V_14 [ -- V_1 -> V_16 ] = V_31 ;
if ( V_1 -> V_6 & V_29 ) {
V_1 -> V_6 &= ~ V_29 ;
if ( V_1 -> V_16 )
F_22 ( & V_1 -> V_8 ) ;
}
if ( ! V_1 -> V_16 ) {
V_1 -> V_6 &= ~ V_15 ;
F_22 ( & V_1 -> V_8 ) ;
}
return 1 ;
}
void F_24 ( struct V_1 * V_1 )
{
if ( V_1 -> V_6 & V_7 )
V_1 -> V_5 = 1 ;
if ( V_1 -> V_6 & ( V_7 | V_15 ) )
F_22 ( & V_1 -> V_8 ) ;
V_1 -> V_6 &= V_34 ;
}
