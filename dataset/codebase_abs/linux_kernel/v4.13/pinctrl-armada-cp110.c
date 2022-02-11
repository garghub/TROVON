static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
struct V_4 * V_5 ;
for ( V_5 = V_2 -> V_6 ; V_5 -> V_7 ; V_5 ++ )
V_5 -> V_3 = V_3 ;
}
static int F_2 ( struct V_8 * V_9 )
{
struct V_10 * V_11 ;
const struct V_12 * V_13 =
F_3 ( V_14 , & V_9 -> V_15 ) ;
int V_16 ;
if ( ! V_9 -> V_15 . V_17 )
return - V_18 ;
V_11 = F_4 ( & V_9 -> V_15 ,
sizeof( struct V_10 ) , V_19 ) ;
if ( ! V_11 )
return - V_20 ;
V_11 -> V_3 = ( unsigned long ) V_13 -> V_21 & 0xff ;
V_11 -> V_22 = V_23 ;
V_11 -> V_24 = F_5 ( V_23 ) ;
V_11 -> V_25 = V_26 ;
V_11 -> V_27 = F_5 ( V_26 ) ;
for ( V_16 = 0 ; V_16 < F_5 ( V_26 ) ; V_16 ++ ) {
struct V_1 * V_2 = & V_26 [ V_16 ] ;
switch ( V_16 ) {
case 0 ... 31 :
F_1 ( V_2 , V_28 ) ;
break;
case 32 ... 38 :
F_1 ( V_2 , V_29 ) ;
break;
case 39 ... 43 :
F_1 ( V_2 , V_30 ) ;
break;
case 44 ... 62 :
F_1 ( V_2 , V_29 ) ;
break;
}
}
V_9 -> V_15 . V_31 = V_11 ;
return F_6 ( V_9 , V_9 -> V_15 . V_17 , 0 ) ;
}
