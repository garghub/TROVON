static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
V_4 = F_2 ( V_2 , struct V_3 , V_7 ) ;
V_6 = & V_4 -> V_8 -> V_9 ;
F_3 ( & V_6 -> V_10 , V_4 -> V_11 ) ;
F_4 ( V_4 ) ;
}
int F_5 ( struct V_12 * V_13 , struct V_14 * V_8 , T_1 * V_11 , T_1 V_15 )
{
int V_16 ;
struct V_3 * V_4 ;
struct V_5 * V_6 = & V_8 -> V_9 ;
V_4 = F_6 ( sizeof( * V_4 ) , V_17 ) ;
if ( ! V_4 )
return - V_18 ;
F_7 ( & V_6 -> V_19 ) ;
V_16 = F_8 ( & V_6 -> V_10 , V_4 , 0 , 0 , V_17 ) ;
if ( V_16 < 0 ) {
F_9 ( & V_6 -> V_19 ) ;
F_4 ( V_4 ) ;
return V_16 ;
}
* V_11 = ( T_1 ) V_16 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_11 = * V_11 ;
V_4 -> V_8 = V_8 ;
F_10 ( & V_4 -> V_7 ) ;
F_9 ( & V_6 -> V_19 ) ;
return 0 ;
}
int F_11 ( struct V_12 * V_13 , struct V_14 * V_8 , T_1 V_11 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = & V_8 -> V_9 ;
F_7 ( & V_6 -> V_19 ) ;
V_4 = F_12 ( & V_6 -> V_10 , V_11 ) ;
if ( V_4 ) {
F_13 ( & V_4 -> V_7 , F_1 ) ;
F_9 ( & V_6 -> V_19 ) ;
return 0 ;
}
F_9 ( & V_6 -> V_19 ) ;
return - V_20 ;
}
static int F_14 ( struct V_12 * V_13 ,
struct V_14 * V_8 , T_1 V_11 ,
union V_21 * V_22 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = & V_8 -> V_9 ;
unsigned V_23 ;
F_7 ( & V_6 -> V_19 ) ;
V_4 = F_12 ( & V_6 -> V_10 , V_11 ) ;
if ( ! V_4 ) {
F_9 ( & V_6 -> V_19 ) ;
return - V_20 ;
}
V_22 -> V_24 . V_15 = V_4 -> V_24 . V_15 ;
V_22 -> V_24 . V_25 = V_4 -> V_24 . V_25 ;
V_23 = F_15 ( & V_13 -> V_26 ) ;
if ( V_4 -> V_23 == V_23 )
V_22 -> V_24 . V_27 = V_28 ;
else
V_22 -> V_24 . V_27 = V_29 ;
V_4 -> V_23 = V_23 ;
F_9 ( & V_6 -> V_19 ) ;
return 0 ;
}
void F_16 ( struct V_14 * V_8 )
{
struct V_30 * V_31 ;
struct V_3 * V_4 ;
T_1 V_11 ;
struct V_5 * V_6 = & V_8 -> V_9 ;
V_31 = & V_6 -> V_10 ;
F_17 (idp,ctx,id) {
if ( F_13 ( & V_4 -> V_7 , F_1 ) != 1 )
F_18 ( L_1 , V_4 -> V_11 ) ;
}
F_19 ( & V_6 -> V_19 ) ;
}
int F_20 ( struct V_32 * V_33 , void * V_34 ,
struct V_35 * V_36 )
{
int V_16 ;
T_1 V_11 ;
T_1 V_15 ;
union V_37 * args = V_34 ;
struct V_12 * V_13 = V_33 -> V_38 ;
struct V_14 * V_8 = V_36 -> V_39 ;
V_16 = 0 ;
V_11 = args -> V_40 . V_41 ;
V_15 = args -> V_40 . V_15 ;
switch ( args -> V_40 . V_42 ) {
case V_43 :
V_16 = F_5 ( V_13 , V_8 , & V_11 , V_15 ) ;
args -> V_22 . V_44 . V_41 = V_11 ;
break;
case V_45 :
V_16 = F_11 ( V_13 , V_8 , V_11 ) ;
break;
case V_46 :
V_16 = F_14 ( V_13 , V_8 , V_11 , & args -> V_22 ) ;
break;
default:
return - V_20 ;
}
return V_16 ;
}
struct V_3 * F_21 ( struct V_14 * V_8 , T_1 V_11 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = & V_8 -> V_9 ;
F_7 ( & V_6 -> V_19 ) ;
V_4 = F_12 ( & V_6 -> V_10 , V_11 ) ;
if ( V_4 )
F_22 ( & V_4 -> V_7 ) ;
F_9 ( & V_6 -> V_19 ) ;
return V_4 ;
}
int F_23 ( struct V_3 * V_4 )
{
struct V_14 * V_8 ;
struct V_5 * V_6 ;
if ( V_4 == NULL )
return - V_20 ;
V_8 = V_4 -> V_8 ;
V_6 = & V_8 -> V_9 ;
F_7 ( & V_6 -> V_19 ) ;
F_13 ( & V_4 -> V_7 , F_1 ) ;
F_9 ( & V_6 -> V_19 ) ;
return 0 ;
}
