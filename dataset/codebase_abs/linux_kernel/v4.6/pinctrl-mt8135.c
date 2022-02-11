static int F_1 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned char V_3 , bool V_4 , unsigned int V_5 )
{
unsigned int V_6 ;
unsigned int V_7 , V_8 , V_9 ;
unsigned int V_10 , V_11 ;
bool V_12 = false ;
for ( V_6 = 0 ; V_6 < F_2 ( V_13 ) ; V_6 ++ ) {
if ( V_2 == V_13 [ V_6 ] . V_2 ) {
V_12 = true ;
break;
}
}
if ( ! V_12 )
return - V_14 ;
if ( V_4 )
V_7 = V_13 [ V_6 ] . V_15 + V_3 ;
else
V_7 = V_13 [ V_6 ] . V_15 + ( V_3 << 1 ) ;
F_3 ( V_1 , V_7 , V_13 [ V_6 ] . V_16 ) ;
V_8 = V_13 [ V_6 ] . V_17 + V_3 ;
V_10 = V_13 [ V_6 ] . V_17 + ( V_3 << 1 ) ;
V_9 = V_13 [ V_6 ] . V_18 + V_3 ;
V_11 = V_13 [ V_6 ] . V_18 + ( V_3 << 1 ) ;
switch ( V_5 ) {
case V_19 :
F_3 ( V_1 , V_10 , V_13 [ V_6 ] . V_20 ) ;
F_3 ( V_1 , V_11 , V_13 [ V_6 ] . V_21 ) ;
break;
case V_22 :
F_3 ( V_1 , V_8 , V_13 [ V_6 ] . V_20 ) ;
F_3 ( V_1 , V_11 , V_13 [ V_6 ] . V_21 ) ;
break;
case V_23 :
F_3 ( V_1 , V_10 , V_13 [ V_6 ] . V_20 ) ;
F_3 ( V_1 , V_9 , V_13 [ V_6 ] . V_21 ) ;
break;
case V_24 :
F_3 ( V_1 , V_8 , V_13 [ V_6 ] . V_20 ) ;
F_3 ( V_1 , V_9 , V_13 [ V_6 ] . V_21 ) ;
break;
default:
return - V_14 ;
}
return 0 ;
}
static int F_4 ( struct V_25 * V_26 )
{
return F_5 ( V_26 , & V_27 , NULL ) ;
}
static int T_1 F_6 ( void )
{
return F_7 ( & V_28 ) ;
}
