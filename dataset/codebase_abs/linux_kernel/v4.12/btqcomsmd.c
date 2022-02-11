static int F_1 ( struct V_1 * V_2 , unsigned int type ,
const void * V_3 , T_1 V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_4 , V_7 ) ;
if ( ! V_6 ) {
V_2 -> V_8 . V_9 ++ ;
return - V_10 ;
}
F_3 ( V_6 ) = type ;
memcpy ( F_4 ( V_6 , V_4 ) , V_3 , V_4 ) ;
return F_5 ( V_2 , V_6 ) ;
}
static int F_6 ( struct V_11 * V_12 , void * V_3 ,
int V_4 , void * V_13 , T_2 V_14 )
{
struct V_15 * V_16 = V_13 ;
V_16 -> V_2 -> V_8 . V_17 += V_4 ;
return F_1 ( V_16 -> V_2 , V_18 , V_3 , V_4 ) ;
}
static int F_7 ( struct V_11 * V_12 , void * V_3 ,
int V_4 , void * V_13 , T_2 V_14 )
{
struct V_15 * V_16 = V_13 ;
return F_1 ( V_16 -> V_2 , V_19 , V_3 , V_4 ) ;
}
static int F_8 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_15 * V_16 = F_9 ( V_2 ) ;
int V_20 ;
switch ( F_3 ( V_6 ) ) {
case V_18 :
V_20 = F_10 ( V_16 -> V_21 , V_6 -> V_3 , V_6 -> V_22 ) ;
V_2 -> V_8 . V_23 ++ ;
V_2 -> V_8 . V_24 += V_6 -> V_22 ;
break;
case V_25 :
V_20 = F_10 ( V_16 -> V_26 , V_6 -> V_3 , V_6 -> V_22 ) ;
V_2 -> V_8 . V_27 ++ ;
break;
default:
V_20 = - V_28 ;
break;
}
F_11 ( V_6 ) ;
return V_20 ;
}
static int F_12 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_14 ( struct V_29 * V_30 )
{
struct V_15 * V_16 ;
struct V_1 * V_2 ;
void * V_31 ;
int V_20 ;
V_16 = F_15 ( & V_30 -> V_32 , sizeof( * V_16 ) , V_33 ) ;
if ( ! V_16 )
return - V_10 ;
V_31 = F_16 ( V_30 -> V_32 . V_34 ) ;
V_16 -> V_21 = F_17 ( V_31 , L_1 ,
F_6 , V_16 ) ;
if ( F_18 ( V_16 -> V_21 ) )
return F_19 ( V_16 -> V_21 ) ;
V_16 -> V_26 = F_17 ( V_31 , L_2 ,
F_7 , V_16 ) ;
if ( F_18 ( V_16 -> V_26 ) )
return F_19 ( V_16 -> V_26 ) ;
V_2 = F_20 () ;
if ( ! V_2 )
return - V_10 ;
F_21 ( V_2 , V_16 ) ;
V_16 -> V_2 = V_2 ;
F_22 ( V_2 , & V_30 -> V_32 ) ;
V_2 -> V_35 = V_36 ;
V_2 -> V_37 = F_12 ;
V_2 -> V_38 = F_13 ;
V_2 -> V_39 = F_8 ;
V_2 -> V_40 = V_41 ;
V_20 = F_23 ( V_2 ) ;
if ( V_20 < 0 ) {
F_24 ( V_2 ) ;
return V_20 ;
}
F_25 ( V_30 , V_16 ) ;
return 0 ;
}
static int F_26 ( struct V_29 * V_30 )
{
struct V_15 * V_16 = F_27 ( V_30 ) ;
F_28 ( V_16 -> V_2 ) ;
F_24 ( V_16 -> V_2 ) ;
F_29 ( V_16 -> V_26 ) ;
F_29 ( V_16 -> V_21 ) ;
return 0 ;
}
