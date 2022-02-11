static int F_1 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned char V_3 , bool V_4 , unsigned int V_5 )
{
unsigned int V_6 ;
unsigned int V_7 , V_8 , V_9 ;
unsigned int V_10 , V_11 , V_12 ;
const struct V_13 * V_14 ;
bool V_15 = false ;
for ( V_6 = 0 ; V_6 < F_2 ( V_16 ) ; V_6 ++ ) {
if ( V_2 == V_16 [ V_6 ] . V_2 ) {
V_15 = true ;
break;
}
}
if ( ! V_15 )
return - V_17 ;
V_14 = V_16 + V_6 ;
V_8 = V_14 -> V_18 + V_3 ;
V_9 = V_14 -> V_18 + ( V_3 << 1 ) ;
if ( V_4 )
V_7 = V_9 ;
else
V_7 = V_8 ;
V_10 = F_3 ( V_14 -> V_19 ) ;
F_4 ( V_1 , V_7 , V_10 ) ;
V_11 = F_3 ( V_14 -> V_20 ) ;
V_12 = F_3 ( V_14 -> V_21 ) ;
switch ( V_5 ) {
case V_22 :
F_4 ( V_1 , V_9 , V_11 ) ;
F_4 ( V_1 , V_9 , V_12 ) ;
break;
case V_23 :
F_4 ( V_1 , V_8 , V_11 ) ;
F_4 ( V_1 , V_9 , V_12 ) ;
break;
case V_24 :
F_4 ( V_1 , V_9 , V_11 ) ;
F_4 ( V_1 , V_8 , V_12 ) ;
break;
case V_25 :
F_4 ( V_1 , V_8 , V_11 ) ;
F_4 ( V_1 , V_8 , V_12 ) ;
break;
default:
return - V_17 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned char V_3 , int V_26 )
{
unsigned int V_6 , V_27 , V_28 ;
bool V_15 = false ;
for ( V_6 = 0 ; V_6 < F_2 ( V_29 ) ; V_6 ++ ) {
if ( V_2 >= V_29 [ V_6 ] . V_30 &&
V_2 <= V_29 [ V_6 ] . V_31 ) {
V_15 = true ;
break;
}
}
if ( ! V_15 )
return - V_17 ;
if ( V_26 )
V_27 = V_29 [ V_6 ] . V_18 + V_3 ;
else
V_27 = V_29 [ V_6 ] . V_18 + ( V_3 << 1 ) ;
V_28 = F_3 ( V_29 [ V_6 ] . V_28 ) ;
F_4 ( V_1 , V_27 , V_28 ) ;
return 0 ;
}
static int F_6 ( struct V_32 * V_33 )
{
return F_7 ( V_33 , & V_34 ) ;
}
static int T_1 F_8 ( void )
{
return F_9 ( & V_35 ) ;
}
