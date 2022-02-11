static int F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
void * V_4 )
{
struct V_5 * V_6 = V_4 ;
struct V_7 * V_7 ;
if ( F_2 ( V_6 ) )
V_7 = F_3 ( V_6 ) ;
else
V_7 = F_4 ( V_6 ) ;
if ( ! V_7 )
return V_8 ;
switch ( V_3 ) {
case V_9 :
if ( ! F_2 ( V_6 ) ) {
struct V_10 * V_11 ;
struct V_12 * V_13 = V_7 -> V_13 ;
V_11 = F_5 ( V_7 , 0 , 0 ,
V_14 ) ;
F_6 ( V_7 ) ;
if ( F_7 ( V_11 ) ) {
F_8 ( F_9 ( V_13 ) -> V_15 , 0 ,
V_16 . V_17 ,
F_10 ( V_11 ) ) ;
break;
}
F_11 ( F_9 ( V_13 ) , V_11 , 0 ,
V_16 . V_17 ,
V_18 ) ;
}
break;
}
return V_8 ;
}
