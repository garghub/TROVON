static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
int V_5 = 1 << ( F_3 ( V_4 -> V_6 ) & 3 ) ;
return V_3 * V_5 ;
}
static long F_4 ( struct V_1 * V_2 , unsigned long V_7 ,
unsigned long * V_8 )
{
int V_9 , V_10 = - 1 ;
long V_11 [ 3 ] ;
if ( V_7 > V_12 )
V_7 = V_12 ;
if ( V_7 < V_13 )
V_7 = V_13 ;
for ( V_9 = 0 ; V_9 < 3 ; V_9 ++ )
V_11 [ V_9 ] = abs ( V_7 - ( * V_8 * ( 1 << V_9 ) ) ) ;
for ( V_9 = 0 ; V_9 < 3 ; V_9 ++ )
if ( V_10 < 0 )
V_10 = V_9 ;
else
V_10 = ( V_11 [ V_9 ] < V_11 [ V_10 ] ) ? V_9 : V_10 ;
return * V_8 * ( 1 << V_10 ) ;
}
static int F_5 ( struct V_1 * V_2 , unsigned long V_7 ,
unsigned long V_3 )
{
int V_14 ;
unsigned char V_15 ;
unsigned long V_16 ;
struct V_4 * V_4 = F_2 ( V_2 ) ;
V_14 = ( ( V_7 / V_3 ) / 2 ) & 0x03 ;
F_6 ( & V_17 , V_16 ) ;
V_15 = F_3 ( V_4 -> V_18 ) ;
V_15 |= 0x08 ;
F_7 ( V_15 , V_4 -> V_18 ) ;
V_15 = F_3 ( V_4 -> V_6 ) ;
V_15 &= ~ 0x03 ;
V_15 |= V_14 ;
F_7 ( V_15 , V_4 -> V_6 ) ;
F_8 ( & V_17 , V_16 ) ;
return 0 ;
}
static void T_1 F_9 ( struct V_19 * V_20 )
{
unsigned int V_21 ;
const char * V_22 = V_20 -> V_23 ;
const char * V_24 ;
struct V_4 * V_4 ;
struct V_25 V_26 ;
int V_27 ;
V_21 = F_10 ( V_20 ) ;
if ( ! V_21 ) {
F_11 ( L_1 , V_22 ) ;
return;
}
V_4 = F_12 ( sizeof( * V_4 ) , V_28 ) ;
if ( ! V_4 )
return;
V_4 -> V_18 = F_13 ( V_20 , 0 ) ;
if ( V_4 -> V_18 == NULL ) {
F_11 ( L_2 , V_22 ) ;
goto V_29;
}
V_4 -> V_6 = F_13 ( V_20 , 1 ) ;
if ( V_4 -> V_6 == NULL ) {
F_11 ( L_3 , V_22 ) ;
goto V_30;
}
V_24 = F_14 ( V_20 , 0 ) ;
V_26 . V_23 = V_22 ;
V_26 . V_31 = & V_32 ;
V_26 . V_16 = V_33 ;
V_26 . V_34 = & V_24 ;
V_26 . V_21 = 1 ;
V_4 -> V_2 . V_26 = & V_26 ;
V_27 = F_15 ( NULL , & V_4 -> V_2 ) ;
if ( V_27 ) {
F_11 ( L_4 ,
V_35 , V_22 , V_27 ) ;
goto V_36;
}
F_16 ( V_20 , V_37 , & V_4 -> V_2 ) ;
return;
V_36:
F_17 ( V_4 -> V_6 ) ;
V_30:
F_17 ( V_4 -> V_18 ) ;
V_29:
F_18 ( V_4 ) ;
}
