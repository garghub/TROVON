static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 ;
switch ( V_3 ) {
case V_7 :
case V_8 :
case V_9 :
V_6 = F_2 ( V_2 , struct V_5 , V_10 ) ;
F_3 ( V_6 ) ;
break;
default:
break;
}
return V_11 ;
}
int F_4 ( struct V_5 * V_6 )
{
int V_12 ;
memset ( & V_6 -> V_10 , 0 , sizeof( V_6 -> V_10 ) ) ;
V_6 -> V_10 . V_13 = F_1 ;
V_6 -> V_10 . V_14 = V_15 ;
V_12 = F_5 ( & V_16 , & V_6 -> V_10 ) ;
if ( ! V_12 )
V_6 -> V_17 = 1 ;
return V_12 ;
}
int F_6 ( struct V_5 * V_6 )
{
int V_12 ;
memset ( & V_6 -> V_10 , 0 , sizeof( V_6 -> V_10 ) ) ;
V_6 -> V_10 . V_13 = F_1 ;
V_6 -> V_10 . V_14 = V_15 ;
V_12 = F_7 ( & V_16 ,
& V_6 -> V_10 ) ;
if ( ! V_12 )
V_6 -> V_17 = 1 ;
return V_12 ;
}
void F_8 ( struct V_5 * V_6 )
{
F_9 ( & V_16 , & V_6 -> V_10 ) ;
V_6 -> V_17 = 0 ;
}
int F_10 ( unsigned long V_18 )
{
return F_11 ( & V_16 , V_18 , NULL ) ;
}
