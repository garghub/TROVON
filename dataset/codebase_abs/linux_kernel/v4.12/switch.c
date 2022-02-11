static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_2 -> V_5 == V_4 -> V_6 && V_2 -> V_7 -> V_8 )
return V_2 -> V_7 -> V_8 ( V_2 , V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_2 -> V_5 != V_4 -> V_6 && V_2 -> V_7 -> V_11 )
return V_2 -> V_7 -> V_11 ( V_2 , V_4 -> V_6 ,
V_4 -> V_9 , V_4 -> V_10 ) ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_2 -> V_5 == V_4 -> V_6 && V_2 -> V_7 -> V_12 )
V_2 -> V_7 -> V_12 ( V_2 , V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_2 -> V_5 != V_4 -> V_6 && V_2 -> V_7 -> V_13 )
V_2 -> V_7 -> V_13 ( V_2 , V_4 -> V_6 , V_4 -> V_9 ,
V_4 -> V_10 ) ;
return 0 ;
}
static int F_3 ( struct V_14 * V_15 ,
unsigned long V_16 , void * V_4 )
{
struct V_1 * V_2 = F_4 ( V_15 , struct V_1 , V_15 ) ;
int V_17 ;
switch ( V_16 ) {
case V_18 :
V_17 = F_1 ( V_2 , V_4 ) ;
break;
case V_19 :
V_17 = F_2 ( V_2 , V_4 ) ;
break;
default:
V_17 = - V_20 ;
break;
}
if ( V_17 )
F_5 ( V_2 -> V_21 , L_1 ,
V_16 , V_17 ) ;
return F_6 ( V_17 ) ;
}
int F_7 ( struct V_1 * V_2 )
{
V_2 -> V_15 . V_22 = F_3 ;
return F_8 ( & V_2 -> V_23 -> V_24 , & V_2 -> V_15 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
int V_17 ;
V_17 = F_10 ( & V_2 -> V_23 -> V_24 , & V_2 -> V_15 ) ;
if ( V_17 )
F_11 ( V_2 -> V_21 , L_2 , V_17 ) ;
}
