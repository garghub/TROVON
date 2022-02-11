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
V_11 = F_5 ( V_7 , 0 , 0 ,
V_12 ) ;
F_6 ( V_7 ) ;
if ( F_7 ( V_11 ) ) {
F_8 ( V_13 . V_14 , 0 ,
V_15 . V_16 ,
F_9 ( V_11 ) ) ;
break;
}
F_10 ( V_11 , 0 , V_15 . V_16 ,
V_17 ) ;
}
break;
}
return V_8 ;
}
