static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_2 -> V_5 == V_4 -> V_6 && V_2 -> V_7 -> V_8 )
return V_2 -> V_7 -> V_8 ( V_2 , V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_2 -> V_5 != V_4 -> V_6 )
F_2 ( V_2 -> V_11 , L_1 ,
V_4 -> V_6 , V_4 -> V_9 , F_3 ( V_4 -> V_10 ) ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_2 -> V_5 == V_4 -> V_6 && V_2 -> V_7 -> V_12 )
V_2 -> V_7 -> V_12 ( V_2 , V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_2 -> V_5 != V_4 -> V_6 )
F_2 ( V_2 -> V_11 , L_2 ,
V_4 -> V_6 , V_4 -> V_9 , F_3 ( V_4 -> V_10 ) ) ;
return 0 ;
}
static int F_5 ( struct V_13 * V_14 ,
unsigned long V_15 , void * V_4 )
{
struct V_1 * V_2 = F_6 ( V_14 , struct V_1 , V_14 ) ;
int V_16 ;
switch ( V_15 ) {
case V_17 :
V_16 = F_1 ( V_2 , V_4 ) ;
break;
case V_18 :
V_16 = F_4 ( V_2 , V_4 ) ;
break;
default:
V_16 = - V_19 ;
break;
}
if ( V_16 )
F_2 ( V_2 -> V_11 , L_3 ,
V_15 , V_16 ) ;
return F_7 ( V_16 ) ;
}
int F_8 ( struct V_1 * V_2 )
{
V_2 -> V_14 . V_20 = F_5 ;
return F_9 ( & V_2 -> V_21 -> V_22 , & V_2 -> V_14 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
int V_16 ;
V_16 = F_11 ( & V_2 -> V_21 -> V_22 , & V_2 -> V_14 ) ;
if ( V_16 )
F_12 ( V_2 -> V_11 , L_4 , V_16 ) ;
}
