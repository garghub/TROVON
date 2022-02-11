int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = ( V_2 == V_5 -> V_8 ) ? V_5 -> V_6
: V_5 -> V_9 ;
unsigned int V_10 ;
int V_11 ;
V_11 = F_3 ( V_7 , V_3 , & V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
else
return ( int ) V_10 ;
}
int F_4 ( struct V_1 * V_2 , int V_3 ,
unsigned char V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = ( V_2 == V_5 -> V_8 ) ? V_5 -> V_6
: V_5 -> V_9 ;
int V_11 ;
V_11 = F_5 ( V_7 , V_3 , V_10 ) ;
return V_11 ;
}
int F_6 ( struct V_1 * V_2 , int V_3 ,
int V_12 , unsigned char * V_13 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = ( V_2 == V_5 -> V_8 ) ? V_5 -> V_6
: V_5 -> V_9 ;
int V_11 ;
V_11 = F_7 ( V_7 , V_3 , V_13 , V_12 ) ;
return V_11 ;
}
int F_8 ( struct V_1 * V_2 , int V_3 ,
int V_12 , unsigned char * V_13 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = ( V_2 == V_5 -> V_8 ) ? V_5 -> V_6
: V_5 -> V_9 ;
int V_11 ;
V_11 = F_9 ( V_7 , V_3 , V_13 , V_12 ) ;
return V_11 ;
}
int F_10 ( struct V_1 * V_2 , int V_3 ,
unsigned char V_14 , unsigned char V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = ( V_2 == V_5 -> V_8 ) ? V_5 -> V_6
: V_5 -> V_9 ;
int V_11 ;
V_11 = F_11 ( V_7 , V_3 , V_14 , V_10 ) ;
return V_11 ;
}
static int F_12 ( struct V_1 * V_2 , int V_3 ,
int V_15 , void * V_16 )
{
unsigned char V_17 [ V_18 + 3 ] ;
unsigned char V_19 [ V_18 + 2 ] ;
struct V_20 * V_21 = V_2 -> V_22 ;
struct V_23 V_24 [ 2 ] = { { V_2 -> V_25 , 0 , 1 , V_17 } ,
{ V_2 -> V_25 , V_26 , 0 , V_19 } ,
} ;
int V_27 = 1 , V_11 = 0 ;
if ( V_16 == NULL )
return - V_28 ;
V_17 [ 0 ] = ( unsigned char ) V_3 ;
V_24 [ 1 ] . V_29 = V_15 ;
if ( V_15 > 0 )
V_27 = 2 ;
V_11 = V_21 -> V_30 -> V_31 ( V_21 , V_24 , V_27 ) ;
memcpy ( V_16 , V_19 , V_15 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , int V_3 ,
int V_15 , void * V_32 )
{
unsigned char V_13 [ V_15 + 1 ] ;
struct V_20 * V_21 = V_2 -> V_22 ;
struct V_23 V_24 ;
int V_11 ;
V_13 [ 0 ] = ( unsigned char ) V_3 ;
memcpy ( & V_13 [ 1 ] , V_32 , V_15 ) ;
V_24 . V_25 = V_2 -> V_25 ;
V_24 . V_33 = 0 ;
V_24 . V_29 = V_15 + 1 ;
V_24 . V_13 = V_13 ;
V_11 = V_21 -> V_30 -> V_31 ( V_21 , & V_24 , 1 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 , int V_3 )
{
unsigned char V_34 = 0 ;
unsigned char V_10 ;
int V_11 ;
F_15 ( V_2 -> V_22 ) ;
F_12 ( V_2 , 0xFA , 0 , & V_34 ) ;
F_12 ( V_2 , 0xFB , 0 , & V_34 ) ;
F_12 ( V_2 , 0xFF , 0 , & V_34 ) ;
V_11 = F_12 ( V_2 , V_3 , 1 , & V_10 ) ;
if ( V_11 >= 0 )
V_11 = ( int ) V_10 ;
F_12 ( V_2 , 0xFE , 0 , & V_34 ) ;
F_12 ( V_2 , 0xFC , 0 , & V_34 ) ;
F_16 ( V_2 -> V_22 ) ;
return V_11 ;
}
int F_17 ( struct V_1 * V_2 , int V_3 ,
unsigned char V_10 )
{
unsigned char V_34 ;
int V_11 ;
F_15 ( V_2 -> V_22 ) ;
F_12 ( V_2 , 0xFA , 0 , & V_34 ) ;
F_12 ( V_2 , 0xFB , 0 , & V_34 ) ;
F_12 ( V_2 , 0xFF , 0 , & V_34 ) ;
V_11 = F_13 ( V_2 , V_3 , 1 , & V_10 ) ;
F_12 ( V_2 , 0xFE , 0 , & V_34 ) ;
F_12 ( V_2 , 0xFC , 0 , & V_34 ) ;
F_16 ( V_2 -> V_22 ) ;
return V_11 ;
}
int F_18 ( struct V_1 * V_2 , int V_3 ,
int V_12 , unsigned char * V_13 )
{
unsigned char V_34 = 0 ;
int V_11 ;
F_15 ( V_2 -> V_22 ) ;
F_12 ( V_2 , 0xfa , 0 , & V_34 ) ;
F_12 ( V_2 , 0xfb , 0 , & V_34 ) ;
F_12 ( V_2 , 0xff , 0 , & V_34 ) ;
V_11 = F_12 ( V_2 , V_3 , V_12 , V_13 ) ;
F_12 ( V_2 , 0xFE , 0 , & V_34 ) ;
F_12 ( V_2 , 0xFC , 0 , & V_34 ) ;
F_16 ( V_2 -> V_22 ) ;
return V_11 ;
}
int F_19 ( struct V_1 * V_2 , int V_3 ,
int V_12 , unsigned char * V_13 )
{
unsigned char V_34 = 0 ;
int V_11 ;
F_15 ( V_2 -> V_22 ) ;
F_12 ( V_2 , 0xFA , 0 , & V_34 ) ;
F_12 ( V_2 , 0xFB , 0 , & V_34 ) ;
F_12 ( V_2 , 0xFF , 0 , & V_34 ) ;
V_11 = F_13 ( V_2 , V_3 , V_12 , V_13 ) ;
F_12 ( V_2 , 0xFE , 0 , & V_34 ) ;
F_12 ( V_2 , 0xFC , 0 , & V_34 ) ;
F_16 ( V_2 -> V_22 ) ;
F_16 ( V_2 -> V_22 ) ;
return V_11 ;
}
int F_20 ( struct V_1 * V_2 , int V_3 ,
unsigned char V_14 , unsigned char V_10 )
{
unsigned char V_34 ;
unsigned char V_35 ;
int V_11 ;
F_15 ( V_2 -> V_22 ) ;
F_12 ( V_2 , 0xFA , 0 , & V_34 ) ;
F_12 ( V_2 , 0xFB , 0 , & V_34 ) ;
F_12 ( V_2 , 0xFF , 0 , & V_34 ) ;
V_11 = F_12 ( V_2 , V_3 , 1 , & V_35 ) ;
if ( V_11 < 0 )
goto V_36;
V_35 &= ~ V_14 ;
V_35 |= V_10 ;
V_11 = F_13 ( V_2 , V_3 , 1 , & V_35 ) ;
V_36:
F_12 ( V_2 , 0xFE , 0 , & V_34 ) ;
F_12 ( V_2 , 0xFC , 0 , & V_34 ) ;
F_16 ( V_2 -> V_22 ) ;
return V_11 ;
}
static int F_21 ( struct V_1 * V_2 )
{
unsigned short V_37 [] = { 0x30 , 0x34 } ;
unsigned short V_38 [] = { 0x10 , 0x11 } ;
int V_39 , V_40 ;
if ( V_2 == NULL )
return 0 ;
V_39 = F_22 ( V_38 ) ;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ ) {
if ( V_2 -> V_25 == * ( V_38 + V_40 ) )
return V_41 ;
}
V_39 = F_22 ( V_37 ) ;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ ) {
if ( V_2 -> V_25 == * ( V_37 + V_40 ) )
return V_42 ;
}
return 0 ;
}
static int T_1 F_23 ( struct V_1 * V_8 ,
const struct V_43 * V_44 )
{
struct V_45 * V_46 = V_8 -> V_47 . V_48 ;
struct V_4 * V_5 ;
int V_11 ;
if ( ! V_46 ) {
F_24 ( L_1 , V_49 ) ;
return - V_28 ;
}
V_5 = F_25 ( sizeof( struct V_4 ) , V_50 ) ;
if ( V_5 == NULL )
return - V_51 ;
V_5 -> V_44 = F_21 ( V_8 ) ;
V_5 -> V_6 = F_26 ( V_8 , & V_52 ) ;
if ( F_27 ( V_5 -> V_6 ) ) {
V_11 = F_28 ( V_5 -> V_6 ) ;
F_29 ( & V_8 -> V_47 , L_2 ,
V_11 ) ;
F_30 ( V_5 ) ;
return V_11 ;
}
V_5 -> V_8 = V_8 ;
F_31 ( V_8 , V_5 ) ;
V_5 -> V_47 = & V_8 -> V_47 ;
F_32 ( V_5 -> V_47 , V_5 ) ;
if ( V_46 -> V_53 && ( V_46 -> V_53 != V_8 -> V_25 ) ) {
V_5 -> V_53 = V_46 -> V_53 ;
V_5 -> V_54 = F_33 ( V_5 -> V_8 -> V_22 ,
V_5 -> V_53 ) ;
V_5 -> V_9 = F_26 ( V_5 -> V_54 ,
& V_52 ) ;
if ( F_27 ( V_5 -> V_9 ) ) {
V_11 = F_28 ( V_5 -> V_9 ) ;
F_29 ( & V_5 -> V_54 -> V_47 ,
L_2 , V_11 ) ;
return V_11 ;
}
F_31 ( V_5 -> V_54 , V_5 ) ;
}
F_34 ( V_5 , V_46 ) ;
return 0 ;
}
static int T_2 F_35 ( struct V_1 * V_8 )
{
struct V_4 * V_5 = F_2 ( V_8 ) ;
F_36 ( V_5 ) ;
if ( V_5 -> V_54 ) {
F_37 ( V_5 -> V_9 ) ;
F_38 ( V_5 -> V_54 ) ;
}
F_37 ( V_5 -> V_6 ) ;
F_30 ( V_5 ) ;
return 0 ;
}
static int T_3 F_39 ( void )
{
int V_11 ;
V_11 = F_40 ( & V_55 ) ;
if ( V_11 != 0 )
F_41 ( L_3 , V_11 ) ;
return V_11 ;
}
static void T_4 F_42 ( void )
{
F_43 ( & V_55 ) ;
}
