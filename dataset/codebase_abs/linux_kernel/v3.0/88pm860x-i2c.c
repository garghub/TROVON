static inline int F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 , void * V_5 )
{
unsigned char V_6 ;
int V_7 ;
V_6 = ( unsigned char ) V_3 ;
V_7 = F_2 ( V_2 , & V_6 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_3 ( V_2 , V_5 , V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static inline int F_4 ( struct V_1 * V_2 ,
int V_3 , int V_4 , void * V_8 )
{
unsigned char V_9 [ V_4 + 1 ] ;
int V_7 ;
V_9 [ 0 ] = ( unsigned char ) V_3 ;
memcpy ( & V_9 [ 1 ] , V_8 , V_4 ) ;
V_7 = F_2 ( V_2 , V_9 , V_4 + 1 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 , int V_3 )
{
struct V_10 * V_11 = F_6 ( V_2 ) ;
unsigned char V_6 ;
int V_7 ;
F_7 ( & V_11 -> V_12 ) ;
V_7 = F_1 ( V_2 , V_3 , 1 , & V_6 ) ;
F_8 ( & V_11 -> V_12 ) ;
if ( V_7 < 0 )
return V_7 ;
else
return ( int ) V_6 ;
}
int F_9 ( struct V_1 * V_2 , int V_3 ,
unsigned char V_6 )
{
struct V_10 * V_11 = F_6 ( V_2 ) ;
int V_7 ;
F_7 ( & V_11 -> V_12 ) ;
V_7 = F_4 ( V_2 , V_3 , 1 , & V_6 ) ;
F_8 ( & V_11 -> V_12 ) ;
return V_7 ;
}
int F_10 ( struct V_1 * V_2 , int V_3 ,
int V_13 , unsigned char * V_9 )
{
struct V_10 * V_11 = F_6 ( V_2 ) ;
int V_7 ;
F_7 ( & V_11 -> V_12 ) ;
V_7 = F_1 ( V_2 , V_3 , V_13 , V_9 ) ;
F_8 ( & V_11 -> V_12 ) ;
return V_7 ;
}
int F_11 ( struct V_1 * V_2 , int V_3 ,
int V_13 , unsigned char * V_9 )
{
struct V_10 * V_11 = F_6 ( V_2 ) ;
int V_7 ;
F_7 ( & V_11 -> V_12 ) ;
V_7 = F_4 ( V_2 , V_3 , V_13 , V_9 ) ;
F_8 ( & V_11 -> V_12 ) ;
return V_7 ;
}
int F_12 ( struct V_1 * V_2 , int V_3 ,
unsigned char V_14 , unsigned char V_6 )
{
struct V_10 * V_11 = F_6 ( V_2 ) ;
unsigned char V_15 ;
int V_7 ;
F_7 ( & V_11 -> V_12 ) ;
V_7 = F_1 ( V_2 , V_3 , 1 , & V_15 ) ;
if ( V_7 < 0 )
goto V_16;
V_15 &= ~ V_14 ;
V_15 |= V_6 ;
V_7 = F_4 ( V_2 , V_3 , 1 , & V_15 ) ;
V_16:
F_8 ( & V_11 -> V_12 ) ;
return V_7 ;
}
int F_13 ( struct V_1 * V_2 , int V_3 )
{
struct V_10 * V_11 = F_6 ( V_2 ) ;
unsigned char V_17 = 0 ;
unsigned char V_6 ;
int V_7 ;
F_7 ( & V_11 -> V_12 ) ;
F_4 ( V_2 , 0xFA , 0 , & V_17 ) ;
F_4 ( V_2 , 0xFB , 0 , & V_17 ) ;
F_4 ( V_2 , 0xFF , 0 , & V_17 ) ;
V_7 = F_1 ( V_2 , V_3 , 1 , & V_6 ) ;
if ( V_7 >= 0 )
V_7 = ( int ) V_6 ;
F_4 ( V_2 , 0xFE , 0 , & V_17 ) ;
F_4 ( V_2 , 0xFC , 0 , & V_17 ) ;
F_8 ( & V_11 -> V_12 ) ;
return V_7 ;
}
int F_14 ( struct V_1 * V_2 , int V_3 ,
unsigned char V_6 )
{
struct V_10 * V_11 = F_6 ( V_2 ) ;
unsigned char V_17 ;
int V_7 ;
F_7 ( & V_11 -> V_12 ) ;
F_4 ( V_2 , 0xFA , 0 , & V_17 ) ;
F_4 ( V_2 , 0xFB , 0 , & V_17 ) ;
F_4 ( V_2 , 0xFF , 0 , & V_17 ) ;
V_7 = F_4 ( V_2 , V_3 , 1 , & V_6 ) ;
F_4 ( V_2 , 0xFE , 0 , & V_17 ) ;
F_4 ( V_2 , 0xFC , 0 , & V_17 ) ;
F_8 ( & V_11 -> V_12 ) ;
return V_7 ;
}
int F_15 ( struct V_1 * V_2 , int V_3 ,
int V_13 , unsigned char * V_9 )
{
struct V_10 * V_11 = F_6 ( V_2 ) ;
unsigned char V_17 = 0 ;
int V_7 ;
F_7 ( & V_11 -> V_12 ) ;
F_4 ( V_2 , 0xFA , 0 , & V_17 ) ;
F_4 ( V_2 , 0xFB , 0 , & V_17 ) ;
F_4 ( V_2 , 0xFF , 0 , & V_17 ) ;
V_7 = F_1 ( V_2 , V_3 , V_13 , V_9 ) ;
F_4 ( V_2 , 0xFE , 0 , & V_17 ) ;
F_4 ( V_2 , 0xFC , 0 , & V_17 ) ;
F_8 ( & V_11 -> V_12 ) ;
return V_7 ;
}
int F_16 ( struct V_1 * V_2 , int V_3 ,
int V_13 , unsigned char * V_9 )
{
struct V_10 * V_11 = F_6 ( V_2 ) ;
unsigned char V_17 = 0 ;
int V_7 ;
F_7 ( & V_11 -> V_12 ) ;
F_4 ( V_2 , 0xFA , 0 , & V_17 ) ;
F_4 ( V_2 , 0xFB , 0 , & V_17 ) ;
F_4 ( V_2 , 0xFF , 0 , & V_17 ) ;
V_7 = F_4 ( V_2 , V_3 , V_13 , V_9 ) ;
F_4 ( V_2 , 0xFE , 0 , & V_17 ) ;
F_4 ( V_2 , 0xFC , 0 , & V_17 ) ;
F_8 ( & V_11 -> V_12 ) ;
return V_7 ;
}
int F_17 ( struct V_1 * V_2 , int V_3 ,
unsigned char V_14 , unsigned char V_6 )
{
struct V_10 * V_11 = F_6 ( V_2 ) ;
unsigned char V_17 ;
unsigned char V_15 ;
int V_7 ;
F_7 ( & V_11 -> V_12 ) ;
F_4 ( V_2 , 0xFA , 0 , & V_17 ) ;
F_4 ( V_2 , 0xFB , 0 , & V_17 ) ;
F_4 ( V_2 , 0xFF , 0 , & V_17 ) ;
V_7 = F_1 ( V_2 , V_3 , 1 , & V_15 ) ;
if ( V_7 < 0 )
goto V_16;
V_15 &= ~ V_14 ;
V_15 |= V_6 ;
V_7 = F_4 ( V_2 , V_3 , 1 , & V_15 ) ;
V_16:
F_4 ( V_2 , 0xFE , 0 , & V_17 ) ;
F_4 ( V_2 , 0xFC , 0 , & V_17 ) ;
F_8 ( & V_11 -> V_12 ) ;
return V_7 ;
}
static int F_18 ( struct V_1 * V_2 )
{
unsigned short V_18 [] = { 0x30 , 0x34 } ;
unsigned short V_19 [] = { 0x10 , 0x11 } ;
int V_20 , V_21 ;
if ( V_2 == NULL )
return 0 ;
V_20 = F_19 ( V_19 ) ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ ) {
if ( V_2 -> V_22 == * ( V_19 + V_21 ) )
return V_23 ;
}
V_20 = F_19 ( V_18 ) ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ ) {
if ( V_2 -> V_22 == * ( V_18 + V_21 ) )
return V_24 ;
}
return 0 ;
}
static int T_1 F_20 ( struct V_1 * V_25 ,
const struct V_26 * V_27 )
{
struct V_28 * V_29 = V_25 -> V_30 . V_31 ;
struct V_10 * V_11 ;
if ( ! V_29 ) {
F_21 ( L_1 , V_32 ) ;
return - V_33 ;
}
V_11 = F_22 ( sizeof( struct V_10 ) , V_34 ) ;
if ( V_11 == NULL )
return - V_35 ;
V_11 -> V_27 = F_18 ( V_25 ) ;
V_11 -> V_25 = V_25 ;
F_23 ( V_25 , V_11 ) ;
V_11 -> V_30 = & V_25 -> V_30 ;
F_24 ( & V_11 -> V_12 ) ;
F_25 ( V_11 -> V_30 , V_11 ) ;
if ( V_29 -> V_36 && ( V_29 -> V_36 != V_25 -> V_22 ) ) {
V_11 -> V_36 = V_29 -> V_36 ;
V_11 -> V_37 = F_26 ( V_11 -> V_25 -> V_38 ,
V_11 -> V_36 ) ;
F_23 ( V_11 -> V_37 , V_11 ) ;
}
F_27 ( V_11 , V_29 ) ;
return 0 ;
}
static int T_2 F_28 ( struct V_1 * V_25 )
{
struct V_10 * V_11 = F_6 ( V_25 ) ;
F_29 ( V_11 ) ;
F_30 ( V_11 -> V_37 ) ;
F_31 ( V_11 ) ;
return 0 ;
}
static int T_3 F_32 ( void )
{
int V_7 ;
V_7 = F_33 ( & V_39 ) ;
if ( V_7 != 0 )
F_34 ( L_2 , V_7 ) ;
return V_7 ;
}
static void T_4 F_35 ( void )
{
F_36 ( & V_39 ) ;
}
