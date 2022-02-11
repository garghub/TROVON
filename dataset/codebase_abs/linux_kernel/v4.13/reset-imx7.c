static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 ,
unsigned long V_4 , bool assert )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
const struct V_6 * signal = & V_7 [ V_4 ] ;
unsigned int V_8 = 0 ;
switch ( V_4 ) {
case V_9 :
if ( ! assert )
F_4 ( 10 ) ;
break;
case V_10 :
V_8 = ( assert ) ? 0 : signal -> V_11 ;
break;
}
return F_5 ( V_5 -> V_12 ,
signal -> V_13 , signal -> V_11 , V_8 ) ;
}
static int F_6 ( struct V_2 * V_3 ,
unsigned long V_4 )
{
return F_3 ( V_3 , V_4 , true ) ;
}
static int F_7 ( struct V_2 * V_3 ,
unsigned long V_4 )
{
return F_3 ( V_3 , V_4 , false ) ;
}
static int F_8 ( struct V_14 * V_15 )
{
struct V_1 * V_5 ;
struct V_16 * V_17 = & V_15 -> V_17 ;
struct V_18 V_19 = { . V_20 = L_1 } ;
V_5 = F_9 ( V_17 , sizeof( * V_5 ) , V_21 ) ;
if ( ! V_5 )
return - V_22 ;
V_5 -> V_12 = F_10 ( V_17 -> V_23 ) ;
if ( F_11 ( V_5 -> V_12 ) ) {
F_12 ( V_17 , L_2 ) ;
return F_13 ( V_5 -> V_12 ) ;
}
F_14 ( V_17 , V_5 -> V_12 , & V_19 ) ;
V_5 -> V_3 . V_24 = V_25 ;
V_5 -> V_3 . V_26 = V_27 ;
V_5 -> V_3 . V_28 = & V_29 ;
V_5 -> V_3 . V_23 = V_17 -> V_23 ;
return F_15 ( V_17 , & V_5 -> V_3 ) ;
}
