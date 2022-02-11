static int F_1 ( struct V_1 * V_2 ,
unsigned char V_3 , char unsigned V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
V_3 = F_3 ( V_3 & 0x3F ) ;
V_4 = F_3 ( V_4 & 0x3F ) ;
V_6 -> V_8 [ 0 ] = V_4 >> 4 ;
V_6 -> V_8 [ 1 ] = ( V_4 << 4 ) | ( V_3 >> 2 ) ;
V_7 = F_4 ( V_6 -> V_9 , V_6 -> V_8 , F_5 ( V_6 -> V_8 ) ) ;
if ( V_7 < 0 )
F_6 ( & V_2 -> V_10 , L_1 , V_7 ) ;
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_11 const * V_12 ,
int * V_13 ,
int * V_14 ,
long V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
unsigned V_16 ;
F_8 ( & V_2 -> V_17 ) ;
switch ( V_15 ) {
case V_18 :
V_16 = V_6 -> V_19 [ V_12 -> V_20 ] ;
V_16 = V_16 * 253 + 4500 ;
* V_13 = V_16 / 1000 ;
* V_14 = ( V_16 % 1000 ) * 1000 ;
V_7 = V_21 ;
break;
default:
V_7 = - V_22 ;
}
F_9 ( & V_2 -> V_17 ) ;
return V_7 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_11 const * V_12 ,
int V_13 ,
int V_14 ,
long V_23 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned V_16 ;
int V_7 ;
if ( V_13 < 0 || V_14 < 0 )
return - V_22 ;
V_16 = ( ( ( V_24 ) V_13 * 1000 ) + ( ( V_25 ) V_14 / 1000 ) ) ;
if ( V_16 > 20500 || V_16 < 4500 )
return - V_22 ;
V_16 = ( V_16 - 4500 ) / 253 ;
F_8 ( & V_2 -> V_17 ) ;
switch ( V_23 ) {
case V_18 :
V_6 -> V_19 [ V_12 -> V_20 ] = V_16 ;
V_7 = F_1 ( V_2 , V_6 -> V_19 [ 0 ] , V_6 -> V_19 [ 1 ] ) ;
break;
default:
V_7 = - V_22 ;
}
F_9 ( & V_2 -> V_17 ) ;
return V_7 ;
}
static int F_11 ( struct V_26 * V_9 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
int V_7 ;
V_2 = F_12 ( sizeof( * V_6 ) ) ;
if ( V_2 == NULL )
return - V_27 ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_28 = F_13 ( & V_9 -> V_10 , L_2 ) ;
if ( ! F_14 ( V_6 -> V_28 ) ) {
V_7 = F_15 ( V_6 -> V_28 ) ;
if ( V_7 )
goto V_29;
}
F_16 ( V_9 , V_2 ) ;
V_6 -> V_9 = V_9 ;
V_2 -> V_10 . V_30 = & V_9 -> V_10 ;
V_2 -> V_31 = F_17 ( V_9 ) -> V_31 ;
V_2 -> V_32 = & V_33 ;
V_2 -> V_34 = V_35 ;
V_2 -> V_36 = V_37 ;
V_2 -> V_38 = F_5 ( V_37 ) ;
V_7 = F_18 ( V_2 ) ;
if ( V_7 )
goto V_39;
F_1 ( V_2 , 0 , 0 ) ;
return 0 ;
V_39:
if ( ! F_14 ( V_6 -> V_28 ) )
F_19 ( V_6 -> V_28 ) ;
V_29:
if ( ! F_14 ( V_6 -> V_28 ) )
F_20 ( V_6 -> V_28 ) ;
F_21 ( V_2 ) ;
return V_7 ;
}
static int F_22 ( struct V_26 * V_9 )
{
struct V_1 * V_2 = F_23 ( V_9 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_40 * V_28 = V_6 -> V_28 ;
F_24 ( V_2 ) ;
if ( ! F_14 ( V_28 ) ) {
F_19 ( V_28 ) ;
F_20 ( V_28 ) ;
}
F_21 ( V_2 ) ;
return 0 ;
}
