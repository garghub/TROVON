static int F_1 ( void )
{
unsigned int V_1 = V_2 ;
while ( ( F_2 ( V_3 ) & V_4 ) && V_1 > 0 ) V_1 -- ;
return - ( V_1 <= 0 ) ;
}
static int F_3 ( struct V_5 * V_5 , int * V_6 , int * V_7 )
{
struct V_8 * V_8 = V_5 -> V_9 ;
unsigned char V_10 ;
int V_11 , V_12 = - 1 ;
F_4 ( V_13 , V_3 ) ;
F_4 ( V_14 + ( V_8 -> V_15 >> 2 ) , V_3 ) ;
if ( F_2 ( V_3 ) & V_4 ) goto V_16;
F_4 ( V_8 -> V_15 & 3 , V_3 ) ;
if ( F_1 () ) goto V_16;
V_10 = F_2 ( V_3 ) ;
for ( V_11 = 0 ; V_11 < 4 ; V_11 ++ )
if ( V_10 & ( 1 << V_11 ) ) {
if ( F_1 () ) goto V_16;
V_6 [ V_11 ] = F_2 ( V_3 ) ;
if ( V_6 [ V_11 ] > 252 ) V_6 [ V_11 ] = - 1 ;
}
if ( V_10 & 0x10 ) {
if ( F_1 () ) goto V_16;
* V_7 = F_2 ( V_3 ) & 0x0f ;
}
V_12 = 0 ;
V_16: F_4 ( V_13 , V_3 ) ;
return V_12 ;
}
static int F_5 ( struct V_5 * V_5 , int V_17 )
{
struct V_8 * V_8 = V_5 -> V_9 ;
if ( V_8 -> V_15 != 0 && V_17 != V_18 )
return - 1 ;
F_4 ( V_13 , V_3 ) ;
return 0 ;
}
static int F_6 ( int V_15 , int * V_19 )
{
int V_11 , V_12 = - 1 ;
F_4 ( V_13 , V_3 ) ;
F_4 ( V_14 + ( V_15 >> 2 ) , V_3 ) ;
if ( F_2 ( V_3 ) & V_4 )
goto V_20;
F_4 ( V_21 , V_3 ) ;
if ( F_1 () )
goto V_20;
if ( F_2 ( V_3 ) != V_14 + ( V_15 >> 2 ) )
goto V_20;
if ( F_1 () )
goto V_20;
F_4 ( V_15 & 3 , V_3 ) ;
for ( V_11 = 0 ; V_11 < 4 ; V_11 ++ ) {
if ( F_1 () )
goto V_20;
V_19 [ V_11 ] = F_2 ( V_3 ) ;
}
V_12 = 0 ;
V_20: F_4 ( V_13 , V_3 ) ;
return V_12 ;
}
static int F_7 ( int V_15 , int * V_19 )
{
int V_11 , V_12 = - 1 ;
F_4 ( V_13 , V_3 ) ;
F_4 ( V_14 + ( V_15 >> 2 ) , V_3 ) ;
if ( F_2 ( V_3 ) & V_4 )
goto V_20;
F_4 ( V_22 , V_3 ) ;
if ( F_1 () )
goto V_20;
if ( F_2 ( V_3 ) != V_14 + ( V_15 >> 2 ) )
goto V_20;
if ( F_1 () )
goto V_20;
F_4 ( V_15 & 3 , V_3 ) ;
for ( V_11 = 0 ; V_11 < 4 ; V_11 ++ ) {
if ( F_1 () )
goto V_20;
F_4 ( V_19 [ V_11 ] , V_3 ) ;
}
V_12 = 0 ;
V_20: F_4 ( V_13 , V_3 ) ;
return V_12 ;
}
static int F_8 ( struct V_5 * V_5 , int * V_6 , int * V_23 )
{
int V_11 , V_1 ;
int V_19 [ 4 ] ;
struct V_8 * V_8 = V_5 -> V_9 ;
if ( F_6 ( V_8 -> V_15 , V_19 ) )
return - 1 ;
for ( V_11 = 0 ; V_11 < 4 ; V_11 ++ ) {
V_1 = ( V_23 [ V_11 ] * V_19 [ V_11 ] ) / 200 ;
V_1 = ( V_1 < 1 ) ? 1 : ( ( V_1 > 255 ) ? 255 : V_1 ) ;
V_6 [ V_11 ] = ( V_6 [ V_11 ] < 0 ) ? - 1 : ( V_6 [ V_11 ] * V_19 [ V_11 ] ) / V_1 ;
V_6 [ V_11 ] = ( V_6 [ V_11 ] > 252 ) ? 252 : V_6 [ V_11 ] ;
V_19 [ V_11 ] = V_1 ;
}
if ( F_7 ( V_8 -> V_15 , V_19 ) )
return - 1 ;
return 0 ;
}
static int T_1 F_9 ( int V_24 )
{
struct V_8 * V_8 ;
struct V_5 * V_15 ;
int V_11 , V_25 ;
for ( V_11 = 0 ; V_11 < 4 ; V_11 ++ ) {
V_25 = V_24 * 4 + V_11 ;
V_8 = & V_26 [ V_25 ] ;
if ( ! ( V_8 -> V_5 = V_15 = F_10 () ) ) {
F_11 ( V_27 L_1 ) ;
while ( -- V_11 >= 0 ) {
F_12 ( V_8 -> V_5 ) ;
V_8 -> V_5 = NULL ;
}
return - V_28 ;
}
V_8 -> V_15 = V_25 ;
V_15 -> V_9 = V_8 ;
V_15 -> V_29 = F_5 ;
V_15 -> V_30 = F_3 ;
V_15 -> V_31 = F_8 ;
F_13 ( V_15 , L_2 ) ;
F_14 ( V_15 , L_3 , V_3 , V_25 ) ;
if ( V_25 == 0 )
V_15 -> V_32 = V_3 ;
}
return 0 ;
}
static int T_1 F_15 ( int V_24 )
{
int V_19 [ 4 ] = { 255 , 255 , 255 , 255 } ;
int V_11 , V_33 , V_12 ;
struct V_8 * V_8 ;
F_4 ( V_13 , V_3 ) ;
F_4 ( V_14 + V_24 , V_3 ) ;
if ( F_2 ( V_3 ) & V_4 )
return - 1 ;
F_4 ( V_34 , V_3 ) ;
if ( F_1 () )
return - 1 ;
if ( F_2 ( V_3 ) != V_14 + V_24 )
return - 1 ;
if ( F_1 () )
return - 1 ;
if ( F_2 ( V_3 ) != V_35 )
return - 1 ;
if ( F_1 () )
return - 1 ;
V_33 = F_2 ( V_3 ) ;
if ( ! V_33 )
return - 1 ;
V_12 = F_9 ( V_24 ) ;
if ( V_12 )
return V_12 ;
F_11 ( V_36 L_4 ,
V_24 ? L_5 : L_6 , V_33 >> 4 , V_33 , V_3 ) ;
for ( V_11 = 0 ; V_11 < 4 ; V_11 ++ ) {
V_8 = & V_26 [ V_24 * 4 + V_11 ] ;
if ( V_33 > 0x28 )
F_7 ( V_8 -> V_15 , V_19 ) ;
F_16 ( V_8 -> V_5 ) ;
}
return 0 ;
}
static int T_1 F_17 ( void )
{
int V_11 , V_37 = 0 ;
if ( ! F_18 ( V_3 , 1 , L_7 ) )
return - V_38 ;
for ( V_11 = 0 ; V_11 < 2 ; V_11 ++ )
if ( F_15 ( V_11 ) == 0 )
V_37 ++ ;
F_4 ( V_13 , V_3 ) ;
if ( ! V_37 ) {
F_19 ( V_3 , 1 ) ;
return - V_39 ;
}
return 0 ;
}
static void T_2 F_20 ( void )
{
int V_11 ;
int V_19 [ 4 ] = { 59 , 59 , 59 , 59 } ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ )
if ( V_26 [ V_11 ] . V_5 ) {
F_7 ( V_26 [ V_11 ] . V_15 , V_19 ) ;
F_21 ( V_26 [ V_11 ] . V_5 ) ;
}
F_4 ( V_13 , V_3 ) ;
F_19 ( V_3 , 1 ) ;
}
