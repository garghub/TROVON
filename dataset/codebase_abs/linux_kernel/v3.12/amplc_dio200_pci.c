static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 ;
if ( F_3 ( V_4 , 0 ) < 0x4000 ) {
F_4 ( V_2 -> V_6 , L_1 ) ;
return - V_7 ;
}
V_5 = F_5 ( V_4 , 0 ) ;
if ( ! V_5 ) {
F_4 ( V_2 -> V_6 , L_2 ) ;
return - V_8 ;
}
F_6 ( 0x80 , V_5 + 0x50 ) ;
F_7 ( V_5 ) ;
F_8 ( V_2 , 1 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
const struct V_10 * V_11 = NULL ;
struct V_12 * V_13 ;
unsigned int V_14 ;
int V_15 ;
if ( V_9 < F_10 ( V_16 ) )
V_11 = & V_16 [ V_9 ] ;
if ( ! V_11 )
return - V_7 ;
V_2 -> V_17 = V_11 ;
V_2 -> V_18 = V_11 -> V_19 ;
F_11 ( V_2 -> V_6 , L_3 ,
V_2 -> V_20 -> V_21 , F_12 ( V_3 ) , V_2 -> V_18 ) ;
V_13 = F_13 ( V_2 , sizeof( * V_13 ) ) ;
if ( ! V_13 )
return - V_8 ;
V_15 = F_14 ( V_2 ) ;
if ( V_15 )
return V_15 ;
V_14 = V_11 -> V_22 ;
if ( F_3 ( V_3 , V_14 ) < V_11 -> V_23 ) {
F_4 ( V_2 -> V_6 , L_4 ) ;
return - V_7 ;
}
if ( F_15 ( V_3 , V_14 ) & V_24 ) {
V_13 -> V_25 . V_26 . V_27 = F_5 ( V_3 , V_14 ) ;
if ( ! V_13 -> V_25 . V_26 . V_27 ) {
F_4 ( V_2 -> V_6 ,
L_5 ) ;
return - V_8 ;
}
V_13 -> V_25 . V_28 = V_29 ;
} else {
V_13 -> V_25 . V_26 . V_30 = F_16 ( V_3 , V_14 ) ;
V_13 -> V_25 . V_28 = V_31 ;
}
switch ( V_9 ) {
case V_32 :
case V_33 :
case V_34 :
V_15 = F_1 ( V_2 ) ;
if ( V_15 < 0 )
return V_15 ;
break;
default:
break;
}
return F_17 ( V_2 , V_3 -> V_35 , V_36 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
const struct V_10 * V_11 = F_19 ( V_2 ) ;
struct V_12 * V_13 = V_2 -> V_37 ;
if ( ! V_11 || ! V_13 )
return;
F_20 ( V_2 ) ;
if ( V_13 -> V_25 . V_28 == V_29 )
F_7 ( V_13 -> V_25 . V_26 . V_27 ) ;
F_21 ( V_2 ) ;
}
static int F_22 ( struct V_3 * V_2 , const struct V_38 * V_39 )
{
return F_23 ( V_2 , & V_40 ,
V_39 -> V_41 ) ;
}
