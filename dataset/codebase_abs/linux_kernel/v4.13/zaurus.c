static struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_1 * V_4 , T_1 V_5 )
{
int V_6 ;
struct V_1 * V_7 ;
V_6 = 2 ;
if ( ! F_2 ( V_4 ) ) {
int V_8 = F_3 ( V_4 ) ;
if ( ( V_6 + 4 ) <= V_8 )
goto V_9;
}
V_7 = F_4 ( V_4 , 0 , 4 + V_6 , V_5 ) ;
F_5 ( V_4 ) ;
V_4 = V_7 ;
if ( V_4 ) {
T_2 V_10 ;
V_9:
V_10 = F_6 ( ~ 0 , V_4 -> V_11 , V_4 -> V_12 ) ;
V_10 = ~ V_10 ;
F_7 ( V_4 , V_10 & 0xff ) ;
F_7 ( V_4 , ( V_10 >> 8 ) & 0xff ) ;
F_7 ( V_4 , ( V_10 >> 16 ) & 0xff ) ;
F_7 ( V_4 , ( V_10 >> 24 ) & 0xff ) ;
}
return V_4 ;
}
static int F_8 ( struct V_2 * V_3 , struct V_13 * V_14 )
{
V_3 -> V_15 -> V_16 += 6 ;
V_3 -> V_17 = V_3 -> V_15 -> V_16 + V_3 -> V_15 -> V_18 ;
return F_9 ( V_3 , V_14 ) ;
}
static int F_10 ( struct V_2 * V_3 )
{
return 0 ;
}
static int F_11 ( struct V_2 * V_3 , struct V_13 * V_14 )
{
T_3 * V_19 = V_14 -> V_20 -> V_21 ;
int V_12 = V_14 -> V_20 -> V_22 ;
struct V_23 * V_24 = NULL ;
struct V_25 * V_26 = NULL ;
while ( V_12 > 3 ) {
if ( V_19 [ 1 ] != V_27 )
goto V_28;
switch ( V_19 [ 2 ] ) {
case V_29 :
if ( V_24 ) {
F_12 ( & V_14 -> V_3 , L_1 ) ;
goto V_30;
}
V_24 = ( void * ) V_19 ;
if ( V_24 -> V_31 != sizeof *V_24 ) {
F_12 ( & V_14 -> V_3 , L_2 ,
V_24 -> V_31 ) ;
goto V_30;
}
if ( memcmp ( & V_24 -> V_32 , V_33 , 16 ) &&
memcmp ( & V_24 -> V_32 , V_34 , 16 ) ) {
F_12 ( & V_14 -> V_3 , L_3 ) ;
goto V_30;
}
break;
case V_35 :
if ( V_26 ) {
F_12 ( & V_14 -> V_3 , L_4 ) ;
goto V_30;
}
V_26 = ( void * ) V_19 ;
switch ( V_26 -> V_36 ) {
case 0 :
if ( V_26 -> V_31 != ( sizeof *V_26 + 2 ) )
goto V_37;
break;
case 1 :
if ( V_26 -> V_31 != ( sizeof *V_26 + 3 ) )
goto V_37;
break;
default:
goto V_37;
}
if ( ( V_26 -> V_38 [ 1 ] & ~ 0x02 ) != 0x01 ) {
V_37:
F_12 ( & V_14 -> V_3 ,
L_5 ,
V_26 -> V_31 ,
V_26 -> V_38 [ 0 ] ,
V_26 -> V_38 [ 2 ] ) ;
goto V_30;
}
V_3 -> V_15 -> V_16 += 6 ;
V_3 -> V_17 = V_3 -> V_15 -> V_16
+ V_3 -> V_15 -> V_18 ;
break;
}
V_28:
V_12 -= V_19 [ 0 ] ;
V_19 += V_19 [ 0 ] ;
}
if ( ! V_24 || ! V_26 ) {
F_12 ( & V_14 -> V_3 , L_6 ,
V_24 ? L_7 : L_8 ,
V_26 ? L_7 : L_9 ) ;
goto V_30;
}
return F_13 ( V_3 , V_14 ) ;
V_30:
F_14 ( & V_3 -> V_39 -> V_3 , L_10 ) ;
return - V_40 ;
}
