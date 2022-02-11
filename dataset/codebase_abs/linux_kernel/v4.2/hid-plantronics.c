static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned long * * V_9 , int * V_10 )
{
unsigned short V_11 ;
unsigned long V_12 = ( unsigned long ) F_2 ( V_2 ) ;
if ( ! ( V_12 & V_13 ) ) {
switch ( V_12 ) {
case V_14 :
if ( V_15 )
goto V_16;
goto V_17;
default:
if ( V_15 )
goto V_16;
}
}
else if ( ( V_12 & V_18 ) >= V_19 &&
( V_12 & V_18 ) != V_20 ) {
if ( V_15 )
goto V_16;
}
else if ( ! ( ( V_6 -> V_21 ^ V_12 ) & V_13 ) ) {
switch ( V_8 -> V_22 ) {
case V_23 :
case V_24 :
V_11 = V_25 ;
goto V_26;
case V_27 :
case V_28 :
V_11 = V_29 ;
goto V_26;
}
}
V_17:
return - 1 ;
V_16:
F_3 ( V_2 , L_1 ,
V_8 -> V_22 , V_6 -> V_21 ) ;
return 0 ;
V_26:
F_4 ( V_4 , V_8 , V_9 , V_10 , V_30 , V_11 ) ;
F_3 ( V_2 , L_2 ,
V_8 -> V_22 , V_6 -> V_21 , V_11 ) ;
return 1 ;
}
static unsigned long F_5 ( struct V_1 * V_2 )
{
unsigned V_31 , V_32 ;
unsigned long V_12 = V_2 -> V_33 ;
if ( V_12 >= V_34 && V_12 <= V_35 )
goto exit;
for ( V_31 = 0 ; V_31 < V_2 -> V_36 ; V_31 ++ ) {
V_32 = V_2 -> V_37 [ V_31 ] . V_8 & V_13 ;
if ( V_32 == V_38 ) {
V_12 = V_2 -> V_37 [ V_31 ] . V_8 ;
break;
}
if ( V_32 == V_39 )
V_12 = V_2 -> V_37 [ V_31 ] . V_8 ;
}
exit:
F_3 ( V_2 , L_3 , V_12 ) ;
return V_12 ;
}
static int F_6 ( struct V_1 * V_2 ,
const struct V_40 * V_41 )
{
int V_42 ;
V_42 = F_7 ( V_2 ) ;
if ( V_42 ) {
F_8 ( V_2 , L_4 ) ;
goto V_43;
}
F_9 ( V_2 , ( void * ) F_5 ( V_2 ) ) ;
V_42 = F_10 ( V_2 , V_44 |
V_45 | V_46 ) ;
if ( V_42 )
F_8 ( V_2 , L_5 ) ;
V_43:
return V_42 ;
}
