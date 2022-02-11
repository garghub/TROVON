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
struct V_20 * V_21 = V_17 -> V_21 ;
struct V_22 * V_23 = V_17 -> V_24 ;
struct V_1 * V_2 = V_23 -> V_2 ;
int V_3 ;
T_1 V_25 ;
V_25 = F_1 ( V_2 , V_26 ) ;
F_3 ( V_2 , V_26 , V_25 | 0x1 ) ;
if ( V_17 -> V_27 == V_28 )
V_3 = V_29 ;
else
V_3 = V_30 ;
return F_3 ( V_2 , V_3 , V_21 -> V_31 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
if ( V_9 . V_32 ) {
V_9 . V_32 ( V_2 -> V_11 ) ;
if ( F_1 ( V_2 , 0 ) == V_12 [ 0 ] )
return 0 ;
}
return - V_13 ;
}
static int F_6 ( struct V_1 * V_2 , T_2 V_33 )
{
V_9 . V_15 ( V_2 -> V_11 , V_34 , 0xffff ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_35 , V_36 ;
T_1 * V_4 = V_2 -> V_5 ;
V_36 = F_5 ( V_2 ) ;
if ( V_36 < 0 ) {
F_8 ( V_37 L_1 ) ;
return V_36 ;
}
for ( V_35 = 2 ; V_35 < F_2 ( V_12 ) << 1 ; V_35 += 2 ) {
V_9 . V_15 ( V_2 -> V_11 , V_35 , V_4 [ V_35 >> 1 ] ) ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_36 = 0 ;
F_8 ( V_38 L_2 ) ;
V_36 = F_10 ( V_2 , & V_9 , 0 ) ;
if ( V_36 < 0 ) {
F_8 ( V_37 L_3 ) ;
return V_36 ;
}
V_36 = F_5 ( V_2 ) ;
if ( V_36 )
goto V_39;
F_11 ( V_2 , V_40 ,
F_2 ( V_40 ) ) ;
return 0 ;
V_39:
F_12 ( V_2 ) ;
return V_36 ;
}
static int F_13 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
return 0 ;
}
static T_3 int F_14 ( struct V_41 * V_42 )
{
return F_15 ( & V_42 -> V_43 ,
& V_44 , V_45 , F_2 ( V_45 ) ) ;
}
static int T_4 F_16 ( struct V_41 * V_42 )
{
F_17 ( & V_42 -> V_43 ) ;
return 0 ;
}
static int T_5 F_18 ( void )
{
return F_19 ( & V_46 ) ;
}
static void T_6 F_20 ( void )
{
F_21 ( & V_46 ) ;
}
