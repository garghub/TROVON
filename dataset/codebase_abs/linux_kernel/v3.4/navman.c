static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
unsigned char * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 ;
int V_9 = V_1 -> V_9 ;
int V_10 ;
switch ( V_9 ) {
case 0 :
break;
case - V_11 :
case - V_12 :
case - V_13 :
F_2 ( L_1 ,
V_14 , V_9 ) ;
return;
default:
F_2 ( L_2 ,
V_14 , V_9 ) ;
goto exit;
}
F_3 ( V_15 , & V_3 -> V_16 , V_14 ,
V_1 -> V_17 , V_5 ) ;
V_8 = F_4 ( & V_3 -> V_3 ) ;
if ( V_8 && V_1 -> V_17 ) {
F_5 ( V_8 , V_5 , V_1 -> V_17 ) ;
F_6 ( V_8 ) ;
}
F_7 ( V_8 ) ;
exit:
V_10 = F_8 ( V_1 , V_18 ) ;
if ( V_10 )
F_9 ( & V_1 -> V_16 -> V_16 ,
L_3 ,
V_14 , V_10 ) ;
}
static int F_10 ( struct V_7 * V_8 , struct V_2 * V_3 )
{
int V_10 = 0 ;
F_2 ( L_4 , V_14 , V_3 -> V_19 ) ;
if ( V_3 -> V_20 ) {
F_2 ( L_5 , V_14 ) ;
V_10 = F_8 ( V_3 -> V_20 , V_21 ) ;
if ( V_10 )
F_9 ( & V_3 -> V_16 ,
L_6 ,
V_14 , V_10 ) ;
}
return V_10 ;
}
static void F_11 ( struct V_2 * V_3 )
{
F_2 ( L_4 , V_14 , V_3 -> V_19 ) ;
F_12 ( V_3 -> V_20 ) ;
}
static int F_13 ( struct V_7 * V_8 , struct V_2 * V_3 ,
const unsigned char * V_22 , int V_23 )
{
F_2 ( L_4 , V_14 , V_3 -> V_19 ) ;
return - V_24 ;
}
