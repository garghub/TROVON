static unsigned int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 * V_4 = V_2 -> V_5 ;
switch ( V_3 ) {
case V_6 :
case V_7 :
case V_8 :
return V_9 . V_10 ( V_2 -> V_11 , V_3 ) ;
default:
V_3 = V_3 >> 1 ;
if ( V_3 >= ( F_2 ( V_12 ) ) )
return - V_13 ;
return V_4 [ V_3 ] ;
}
}
static int F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_14 )
{
T_1 * V_4 = V_2 -> V_5 ;
V_9 . V_15 ( V_2 -> V_11 , V_3 , V_14 ) ;
V_3 = V_3 >> 1 ;
if ( V_3 < ( F_2 ( V_12 ) ) )
V_4 [ V_3 ] = V_14 ;
return 0 ;
}
static int F_4 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_3 ;
T_1 V_20 ;
V_20 = F_1 ( V_2 , V_21 ) ;
F_3 ( V_2 , V_21 , V_20 | 0x1 ) ;
if ( V_17 -> V_22 == V_23 )
V_3 = V_24 ;
else
V_3 = V_25 ;
return F_3 ( V_2 , V_3 , V_17 -> V_26 -> V_27 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
if ( V_9 . V_28 ) {
V_9 . V_28 ( V_2 -> V_11 ) ;
if ( F_1 ( V_2 , 0 ) == V_12 [ 0 ] )
return 0 ;
}
return - V_13 ;
}
static int F_6 ( struct V_1 * V_2 )
{
V_9 . V_15 ( V_2 -> V_11 , V_29 , 0xffff ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_30 , V_31 ;
T_1 * V_4 = V_2 -> V_5 ;
V_31 = F_5 ( V_2 ) ;
if ( V_31 < 0 ) {
F_8 ( V_32 L_1 ) ;
return V_31 ;
}
for ( V_30 = 2 ; V_30 < F_2 ( V_12 ) << 1 ; V_30 += 2 ) {
V_9 . V_15 ( V_2 -> V_11 , V_30 , V_4 [ V_30 >> 1 ] ) ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_31 = 0 ;
F_8 ( V_33 L_2 ) ;
V_31 = F_10 ( V_2 , & V_9 , 0 ) ;
if ( V_31 < 0 ) {
F_8 ( V_32 L_3 ) ;
return V_31 ;
}
V_31 = F_5 ( V_2 ) ;
if ( V_31 )
goto V_34;
F_11 ( V_2 , V_35 ,
F_2 ( V_35 ) ) ;
return 0 ;
V_34:
F_12 ( V_2 ) ;
return V_31 ;
}
static int F_13 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
return 0 ;
}
static int F_14 ( struct V_36 * V_37 )
{
return F_15 ( & V_37 -> V_38 ,
& V_39 , V_40 , F_2 ( V_40 ) ) ;
}
static int F_16 ( struct V_36 * V_37 )
{
F_17 ( & V_37 -> V_38 ) ;
return 0 ;
}
