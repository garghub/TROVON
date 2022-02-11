int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 = 0 ;
switch ( V_3 ) {
case V_5 :
V_2 -> V_6 = F_2 () ;
break;
case V_7 :
V_2 -> V_6 = F_3 () ;
break;
default:
return - V_8 ;
}
F_4 ( V_2 ) ;
F_5 ( & V_2 -> V_9 -> V_10 ) ;
V_4 = V_2 -> V_6 -> V_11 ( V_2 , ( unsigned long * ) & V_2 -> V_12 ) ;
F_6 ( & V_2 -> V_9 -> V_10 ) ;
F_7 ( V_2 ) ;
return V_4 ;
}
int F_8 ( struct V_1 * V_2 ,
enum V_13 type , struct V_14 * V_15 )
{
int V_4 = 0 ;
F_4 ( V_2 ) ;
F_5 ( & V_2 -> V_9 -> V_10 ) ;
V_4 = V_2 -> V_6 -> V_16 ( V_2 -> V_12 , type , V_15 ) ;
F_6 ( & V_2 -> V_9 -> V_10 ) ;
F_7 ( V_2 ) ;
return V_4 ;
}
int F_9 ( struct V_1 * V_2 ,
enum V_17 V_18 , struct V_19 * V_20 ,
struct V_21 * V_22 ,
struct V_23 * V_24 )
{
int V_4 = 0 ;
unsigned long V_25 ;
F_4 ( V_2 ) ;
F_10 ( & V_2 -> V_9 -> V_26 , V_25 ) ;
V_2 -> V_9 -> V_27 = V_2 ;
F_11 ( & V_2 -> V_9 -> V_26 , V_25 ) ;
F_5 ( & V_2 -> V_9 -> V_10 ) ;
V_4 = V_2 -> V_6 -> V_28 ( V_2 -> V_12 , V_18 , V_20 ,
V_22 , V_24 ) ;
F_6 ( & V_2 -> V_9 -> V_10 ) ;
F_10 ( & V_2 -> V_9 -> V_26 , V_25 ) ;
V_2 -> V_9 -> V_27 = NULL ;
F_11 ( & V_2 -> V_9 -> V_26 , V_25 ) ;
F_7 ( V_2 ) ;
return V_4 ;
}
int F_12 ( struct V_1 * V_2 )
{
int V_4 = 0 ;
if ( V_2 -> V_12 == 0 )
return 0 ;
F_4 ( V_2 ) ;
F_5 ( & V_2 -> V_9 -> V_10 ) ;
V_4 = V_2 -> V_6 -> V_29 ( V_2 -> V_12 ) ;
F_6 ( & V_2 -> V_9 -> V_10 ) ;
F_7 ( V_2 ) ;
V_2 -> V_12 = 0 ;
return V_4 ;
}
