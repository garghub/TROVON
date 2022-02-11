static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * * V_4 )
{
int V_5 ;
V_6 = 0 ;
F_2 ( L_1 ,
V_2 -> V_7 , V_2 -> V_8 ) ;
switch ( V_2 -> V_7 ) {
case V_9 :
switch ( V_2 -> V_8 ) {
case 0xe1 :
V_5 = F_3 ( V_4 , V_10 ,
V_2 -> V_11 ) ;
break;
case 0xd1 :
case 0xf1 :
V_5 = F_3 ( V_4 , V_12 ,
V_2 -> V_11 ) ;
break;
default:
V_5 = F_3 ( V_4 , V_13 ,
V_2 -> V_11 ) ;
}
break;
case V_14 :
V_5 = F_3 ( V_4 , V_15 , V_2 -> V_11 ) ;
break;
case V_16 :
V_5 = F_3 ( V_4 , V_17 , V_2 -> V_11 ) ;
break;
default:
F_4 ( V_2 -> V_11 , L_2 ) ;
* V_4 = NULL ;
V_5 = - V_18 ;
}
return V_5 ;
}
static void F_5 ( const struct V_3 * V_4 )
{
F_6 ( V_4 ) ;
}
static int F_7 ( struct V_1 * V_2 , struct V_19 * * V_20 ,
const struct V_3 * V_4 , T_1 V_21 )
{
unsigned int V_22 ;
if ( V_6 >= V_4 -> V_23 )
return 0 ;
if ( V_6 + 2 > V_4 -> V_23 ) {
F_4 ( V_2 -> V_11 , L_3 ) ;
return - V_24 ;
}
V_22 = V_4 -> V_25 [ V_6 ++ ] ;
V_22 += V_4 -> V_25 [ V_6 ++ ] << 8 ;
if ( V_22 == 0 )
return 0 ;
if ( V_6 + V_22 > V_4 -> V_23 ) {
F_4 ( V_2 -> V_11 , L_4 ) ;
return - V_24 ;
}
* V_20 = F_8 ( V_22 , V_21 ) ;
if ( ! * V_20 ) {
F_4 ( V_2 -> V_11 , L_5 ) ;
return - V_26 ;
}
memcpy ( F_9 ( * V_20 , V_22 ) , & V_4 -> V_25 [ V_6 ] , V_22 ) ;
V_6 += V_22 ;
return ( * V_20 ) -> V_27 ;
}
int F_10 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
const struct V_3 * V_4 = NULL ;
struct V_19 * V_20 = NULL ;
int V_5 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( V_5 < 0 || ! V_4 )
goto V_30;
while ( ( V_5 = F_7 ( V_2 , & V_20 , V_4 , V_31 ) ) ) {
if ( V_5 < 0 || ! V_20 )
goto V_30;
F_11 ( V_29 , V_20 ) ;
}
V_20 = F_12 ( V_29 ) ;
if ( ! V_20 ) {
V_5 = - V_24 ;
goto V_30;
}
F_13 ( V_20 ) ;
V_20 = F_12 ( V_29 ) ;
if ( ! V_20 ) {
V_5 = - V_24 ;
goto V_30;
}
F_13 ( V_20 ) ;
V_30:
F_5 ( V_4 ) ;
return V_5 ;
}
int F_14 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
int V_5 ;
switch ( V_2 -> V_7 ) {
case V_14 :
V_5 = F_15 ( V_2 , V_29 ) ;
break;
case V_9 :
V_5 = F_16 ( V_2 , V_29 ) ;
break;
case V_16 :
V_5 = F_17 ( V_2 , V_29 ) ;
break;
default:
F_4 ( V_2 -> V_11 , L_6 ) ;
V_5 = - V_18 ;
}
return V_5 ;
}
void F_18 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
switch ( V_2 -> V_7 ) {
case V_14 :
F_19 ( V_2 , V_20 ) ;
break;
case V_9 :
F_20 ( V_2 , V_20 ) ;
break;
case V_16 :
F_21 ( V_2 , V_20 ) ;
break;
default:
F_4 ( V_2 -> V_11 , L_7 ) ;
V_2 -> V_32 = - V_18 ;
}
return;
}
