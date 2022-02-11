static unsigned int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 * V_6 = V_2 -> V_7 ;
switch ( V_3 ) {
case V_8 :
case V_9 :
case V_10 :
return V_11 -> V_12 ( V_5 , V_3 ) ;
default:
V_3 = V_3 >> 1 ;
if ( V_3 >= ( F_3 ( V_13 ) ) )
return - V_14 ;
return V_6 [ V_3 ] ;
}
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_15 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 * V_6 = V_2 -> V_7 ;
V_11 -> V_16 ( V_5 , V_3 , V_15 ) ;
V_3 = V_3 >> 1 ;
if ( V_3 < ( F_3 ( V_13 ) ) )
V_6 [ V_3 ] = V_15 ;
return 0 ;
}
static int F_5 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
int V_3 ;
T_1 V_21 ;
V_21 = F_1 ( V_2 , V_22 ) ;
F_4 ( V_2 , V_22 , V_21 | 0x1 ) ;
if ( V_18 -> V_23 == V_24 )
V_3 = V_25 ;
else
V_3 = V_26 ;
return F_4 ( V_2 , V_3 , V_18 -> V_27 -> V_28 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_11 -> V_16 ( V_5 , V_29 , 0xffff ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_30 , V_31 ;
T_1 * V_6 = V_2 -> V_7 ;
V_31 = F_8 ( V_5 , true , V_32 ,
V_33 ) ;
if ( V_31 < 0 )
return V_31 ;
for ( V_30 = 2 ; V_30 < F_3 ( V_13 ) << 1 ; V_30 += 2 ) {
V_11 -> V_16 ( V_5 , V_30 , V_6 [ V_30 >> 1 ] ) ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
V_5 = F_10 ( V_2 , V_32 ,
V_33 ) ;
if ( F_11 ( V_5 ) ) {
F_12 ( V_2 -> V_34 , L_1 ) ;
return F_13 ( V_5 ) ;
}
F_14 ( V_2 , V_5 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_16 ( V_5 ) ;
return 0 ;
}
static int F_17 ( struct V_35 * V_36 )
{
return F_18 ( & V_36 -> V_34 ,
& V_37 , V_38 , F_3 ( V_38 ) ) ;
}
static int F_19 ( struct V_35 * V_36 )
{
F_20 ( & V_36 -> V_34 ) ;
return 0 ;
}
