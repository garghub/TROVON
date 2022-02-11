static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
return F_4 ( V_6 , V_3 ) ;
}
static T_1 F_5 ( int V_7 , void * V_8 )
{
struct V_5 * V_6 = V_8 ;
T_2 V_9 ;
int V_10 ;
V_10 = V_6 -> V_11 -> V_12 ( V_6 -> V_13 , V_14 , sizeof( V_9 ) ,
& V_9 ) ;
if ( V_10 < 0 )
return V_15 ;
if ( ! ( V_9 & V_16 ) )
return V_17 ;
F_6 ( V_6 -> V_2 ) ;
return V_15 ;
}
int F_7 ( struct V_5 * V_6 )
{
struct V_4 * V_4 = F_8 ( V_6 ) ;
unsigned long V_18 ;
int V_10 ;
V_18 = F_9 ( F_10 ( V_6 -> V_7 ) ) ;
switch ( V_18 ) {
case V_19 :
case V_20 :
break;
default:
F_11 ( V_6 -> V_13 ,
L_1 ,
V_18 ) ;
V_18 = V_20 ;
break;
}
V_10 = F_12 ( V_6 -> V_13 , V_6 -> V_7 , NULL ,
F_5 ,
V_18 | V_21 ,
V_6 -> V_22 , V_6 ) ;
if ( V_10 ) {
F_13 ( V_6 -> V_13 , L_2 ,
V_6 -> V_7 ) ;
return V_10 ;
}
V_6 -> V_2 = F_14 ( V_6 -> V_13 , L_3 ,
V_4 -> V_22 ) ;
if ( ! V_6 -> V_2 )
return - V_23 ;
F_15 ( V_6 -> V_2 , V_4 ) ;
V_6 -> V_2 -> V_24 = & V_25 ;
V_6 -> V_2 -> V_13 . V_26 = V_6 -> V_13 ;
V_4 -> V_2 = F_16 ( V_6 -> V_2 ) ;
return F_17 ( V_6 -> V_13 , V_6 -> V_2 ) ;
}
static int F_18 ( struct V_4 * V_4 )
{
return F_19 ( F_3 ( V_4 ) ) ;
}
static int F_20 ( struct V_4 * V_4 )
{
return F_21 ( F_3 ( V_4 ) ) ;
}
static T_1 F_22 ( int V_7 , void * V_27 )
{
T_2 V_28 [ F_23 ( 2 * V_29 , sizeof( V_30 ) ) + sizeof( V_30 ) ] ;
struct V_31 * V_32 = V_27 ;
struct V_4 * V_4 = V_32 -> V_33 ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_34 const * V_35 ;
int V_10 ;
V_35 = & V_4 -> V_36 [ V_37 ] ;
V_10 = V_6 -> V_11 -> V_12 ( V_6 -> V_13 , V_35 -> V_38 , V_29 ,
V_28 ) ;
if ( V_10 < 0 )
goto V_39;
V_35 = & V_4 -> V_36 [ V_40 ] ;
V_10 = V_6 -> V_11 -> V_12 ( V_6 -> V_13 , V_35 -> V_38 , V_29 ,
V_28 + V_29 ) ;
if ( V_10 < 0 )
goto V_39;
F_24 ( V_4 , V_28 ,
F_25 ( V_4 ) ) ;
V_39:
F_26 ( V_6 -> V_2 ) ;
return V_15 ;
}
int F_27 ( struct V_5 * V_6 )
{
return F_28 ( V_6 -> V_13 , F_8 ( V_6 ) ,
NULL , F_22 ,
& V_41 ) ;
}
