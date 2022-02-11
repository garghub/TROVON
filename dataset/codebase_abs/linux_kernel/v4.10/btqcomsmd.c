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
static int F_6 ( struct V_11 * V_12 ,
const void * V_3 , T_1 V_4 )
{
struct V_13 * V_14 = F_7 ( V_12 ) ;
V_14 -> V_2 -> V_8 . V_15 += V_4 ;
return F_1 ( V_14 -> V_2 , V_16 , V_3 , V_4 ) ;
}
static int F_8 ( struct V_11 * V_12 ,
const void * V_3 , T_1 V_4 )
{
struct V_13 * V_14 = F_7 ( V_12 ) ;
return F_1 ( V_14 -> V_2 , V_17 , V_3 , V_4 ) ;
}
static int F_9 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_13 * V_14 = F_10 ( V_2 ) ;
int V_18 ;
switch ( F_3 ( V_6 ) ) {
case V_16 :
V_18 = F_11 ( V_14 -> V_19 , V_6 -> V_3 , V_6 -> V_20 ) ;
V_2 -> V_8 . V_21 ++ ;
V_2 -> V_8 . V_22 += V_6 -> V_20 ;
break;
case V_23 :
V_18 = F_11 ( V_14 -> V_24 , V_6 -> V_3 , V_6 -> V_20 ) ;
V_2 -> V_8 . V_25 ++ ;
break;
default:
V_18 = - V_26 ;
break;
}
F_12 ( V_6 ) ;
return V_18 ;
}
static int F_13 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_15 ( struct V_27 * V_28 )
{
struct V_13 * V_14 ;
struct V_1 * V_2 ;
void * V_29 ;
int V_18 ;
V_14 = F_16 ( & V_28 -> V_30 , sizeof( * V_14 ) , V_31 ) ;
if ( ! V_14 )
return - V_10 ;
V_29 = F_17 ( V_28 -> V_30 . V_32 ) ;
V_14 -> V_19 = F_18 ( V_29 , L_1 ,
F_6 ) ;
if ( F_19 ( V_14 -> V_19 ) )
return F_20 ( V_14 -> V_19 ) ;
V_14 -> V_24 = F_18 ( V_29 , L_2 ,
F_8 ) ;
if ( F_19 ( V_14 -> V_24 ) )
return F_20 ( V_14 -> V_24 ) ;
F_21 ( V_14 -> V_19 , V_14 ) ;
F_21 ( V_14 -> V_24 , V_14 ) ;
V_2 = F_22 () ;
if ( ! V_2 )
return - V_10 ;
F_23 ( V_2 , V_14 ) ;
V_14 -> V_2 = V_2 ;
F_24 ( V_2 , & V_28 -> V_30 ) ;
V_2 -> V_33 = V_34 ;
V_2 -> V_35 = F_13 ;
V_2 -> V_36 = F_14 ;
V_2 -> V_37 = F_9 ;
V_2 -> V_38 = V_39 ;
V_18 = F_25 ( V_2 ) ;
if ( V_18 < 0 ) {
F_26 ( V_2 ) ;
return V_18 ;
}
F_27 ( V_28 , V_14 ) ;
return 0 ;
}
static int F_28 ( struct V_27 * V_28 )
{
struct V_13 * V_14 = F_29 ( V_28 ) ;
F_30 ( V_14 -> V_2 ) ;
F_26 ( V_14 -> V_2 ) ;
return 0 ;
}
