static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
V_6 -> V_7 ( V_4 -> V_8 , V_2 -> V_9 * V_10 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
V_6 -> V_7 ( V_4 -> V_8 , 0 ) ;
return 0 ;
}
static int V_7 ( struct V_1 * V_2 , unsigned V_11 )
{
V_2 -> V_9 = V_11 ;
return F_1 ( V_2 ) ;
}
static int F_5 ( struct V_12 * V_13 , unsigned long V_14 ,
void * V_15 )
{
switch ( V_14 ) {
case V_16 :
break;
case V_17 :
case V_18 :
F_4 ( & V_19 ) ;
break;
}
return V_20 ;
}
static int F_6 ( struct V_21 * V_22 )
{
int V_23 ;
F_7 ( & V_19 , & V_22 -> V_4 ) ;
V_19 . V_9 = F_8 ( unsigned , V_24 , 1 , V_25 ) ;
V_19 . V_8 = & V_22 -> V_4 ;
V_23 = F_9 ( & V_19 ) ;
if ( V_23 < 0 ) {
F_10 ( & V_22 -> V_4 , L_1 ) ;
return V_23 ;
}
if ( F_11 ( & V_26 ) )
F_12 ( & V_22 -> V_4 , L_2 ) ;
F_13 ( & V_22 -> V_4 , L_3 ,
V_19 . V_9 ) ;
return 0 ;
}
static int F_14 ( struct V_21 * V_22 )
{
F_15 ( & V_26 ) ;
F_16 ( & V_19 ) ;
return 0 ;
}
static int T_1 F_17 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_19 ;
if ( F_18 ( V_2 ) )
return F_4 ( V_2 ) ;
return 0 ;
}
static int T_1 F_19 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_19 ;
if ( F_18 ( V_2 ) )
return F_1 ( V_2 ) ;
return 0 ;
}
