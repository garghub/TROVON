static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 -> V_6 [ 0 ] ;
const char * V_8 ;
int V_9 = 0 ;
char * V_10 ;
switch ( V_6 -> V_7 -> V_11 ) {
case 0 :
V_8 = L_1 ;
break;
case 1 :
case 2 :
V_8 = L_2 ;
V_9 = V_6 -> V_7 -> V_11 ;
break;
case 3 :
case 4 :
V_8 = L_3 ;
V_9 = V_6 -> V_7 -> V_11 - 2 ;
break;
default:
F_2 ( V_2 , L_4 , V_6 -> V_7 -> V_11 ) ;
V_8 = L_5 ;
}
if ( V_9 )
V_10 = F_3 ( & V_2 -> V_12 , V_13 ,
L_6 , V_14 ,
V_8 , V_9 ) ;
else
V_10 = F_3 ( & V_2 -> V_12 , V_13 ,
L_7 , V_14 , V_8 ) ;
if ( ! V_10 )
return - V_15 ;
V_4 -> V_16 -> V_10 = V_10 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
const struct V_17 * V_11 )
{
int V_18 ;
V_2 -> V_19 |= V_20 ;
V_18 = F_5 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_6 ( V_2 , V_21 ) ;
if ( V_18 )
return V_18 ;
return 0 ;
}
