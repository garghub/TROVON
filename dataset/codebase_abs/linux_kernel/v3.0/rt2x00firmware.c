static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 -> V_4 -> V_5 ) ;
const struct V_6 * V_7 ;
char * V_8 ;
int V_9 ;
V_8 = V_2 -> V_10 -> V_11 -> V_12 ( V_2 ) ;
if ( ! V_8 ) {
ERROR ( V_2 ,
L_1
L_2 , V_13 ) ;
return - V_14 ;
}
F_3 ( V_2 , L_3 , V_8 ) ;
V_9 = F_4 ( & V_7 , V_8 , V_3 ) ;
if ( V_9 ) {
ERROR ( V_2 , L_4 ) ;
return V_9 ;
}
if ( ! V_7 || ! V_7 -> V_15 || ! V_7 -> V_16 ) {
ERROR ( V_2 , L_5 ) ;
F_5 ( V_7 ) ;
return - V_17 ;
}
F_3 ( V_2 , L_6 ,
V_7 -> V_16 [ V_7 -> V_15 - 4 ] , V_7 -> V_16 [ V_7 -> V_15 - 3 ] ) ;
snprintf ( V_2 -> V_4 -> V_5 -> V_18 ,
sizeof( V_2 -> V_4 -> V_5 -> V_18 ) , L_7 ,
V_7 -> V_16 [ V_7 -> V_15 - 4 ] , V_7 -> V_16 [ V_7 -> V_15 - 3 ] ) ;
V_9 = V_2 -> V_10 -> V_11 -> V_19 ( V_2 , V_7 -> V_16 , V_7 -> V_15 ) ;
switch ( V_9 ) {
case V_20 :
break;
case V_21 :
ERROR ( V_2 , L_8 ) ;
goto exit;
case V_22 :
ERROR ( V_2 ,
L_9 , V_7 -> V_15 ) ;
goto exit;
case V_23 :
ERROR ( V_2 ,
L_10 ) ;
goto exit;
}
V_2 -> V_7 = V_7 ;
return 0 ;
exit:
F_5 ( V_7 ) ;
return - V_17 ;
}
int F_6 ( struct V_1 * V_2 )
{
int V_9 ;
if ( ! F_7 ( V_24 , & V_2 -> V_25 ) )
return 0 ;
if ( ! V_2 -> V_7 ) {
V_9 = F_1 ( V_2 ) ;
if ( V_9 )
return V_9 ;
}
V_9 = V_2 -> V_10 -> V_11 -> V_26 ( V_2 ,
V_2 -> V_7 -> V_16 ,
V_2 -> V_7 -> V_15 ) ;
F_8 ( V_2 , false ) ;
return V_9 ;
}
void F_9 ( struct V_1 * V_2 )
{
F_5 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
}
