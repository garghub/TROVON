static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
unsigned char * V_5 = V_1 -> V_6 ;
int V_7 = V_1 -> V_7 ;
int V_8 ;
switch ( V_7 ) {
case 0 :
break;
case - V_9 :
case - V_10 :
case - V_11 :
F_2 ( & V_3 -> V_12 , L_1 ,
V_13 , V_7 ) ;
return;
default:
F_2 ( & V_3 -> V_12 , L_2 ,
V_13 , V_7 ) ;
goto exit;
}
F_3 ( & V_3 -> V_12 , V_13 , V_1 -> V_14 , V_5 ) ;
if ( V_1 -> V_14 ) {
F_4 ( & V_3 -> V_3 , V_5 , V_1 -> V_14 ) ;
F_5 ( & V_3 -> V_3 ) ;
}
exit:
V_8 = F_6 ( V_1 , V_15 ) ;
if ( V_8 )
F_7 ( & V_1 -> V_12 -> V_12 ,
L_3 ,
V_13 , V_8 ) ;
}
static int F_8 ( struct V_16 * V_17 , struct V_2 * V_3 )
{
int V_8 = 0 ;
if ( V_3 -> V_18 ) {
F_2 ( & V_3 -> V_12 , L_4 ,
V_13 ) ;
V_8 = F_6 ( V_3 -> V_18 , V_19 ) ;
if ( V_8 )
F_7 ( & V_3 -> V_12 ,
L_5 ,
V_13 , V_8 ) ;
}
return V_8 ;
}
static void F_9 ( struct V_2 * V_3 )
{
F_10 ( V_3 -> V_18 ) ;
}
static int F_11 ( struct V_16 * V_17 , struct V_2 * V_3 ,
const unsigned char * V_20 , int V_21 )
{
return - V_22 ;
}
