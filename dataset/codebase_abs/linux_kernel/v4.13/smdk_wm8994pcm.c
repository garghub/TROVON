static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
unsigned long V_11 ;
int V_12 , V_13 ;
switch( F_2 ( V_4 ) ) {
case 8000 :
V_12 = 512 ;
break;
default:
F_3 ( V_10 -> V_14 , L_1 ,
V_15 , __LINE__ , F_2 ( V_4 ) ) ;
return - V_16 ;
}
V_11 = F_2 ( V_4 ) * V_12 ;
V_13 = F_4 ( V_9 , V_17 ,
V_11 , V_18 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_9 , V_19 , V_20 ,
V_21 , V_11 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_4 ( V_10 , V_22 ,
V_11 , V_18 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_6 ( V_10 , V_23 , V_12 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
static int F_7 ( struct V_24 * V_25 )
{
int V_13 = 0 ;
V_26 . V_14 = & V_25 -> V_14 ;
V_13 = F_8 ( & V_25 -> V_14 , & V_26 ) ;
if ( V_13 )
F_3 ( & V_25 -> V_14 , L_2 , V_13 ) ;
return V_13 ;
}
