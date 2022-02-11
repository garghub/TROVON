static void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
switch ( V_3 ) {
case V_5 :
F_2 ( V_4 , V_2 -> V_6 ) ;
break;
case V_7 :
case V_8 :
case V_9 :
case V_10 :
F_3 ( V_4 , V_2 -> V_6 + ( ( V_3 + 1 ) << 2 ) ) ;
break;
case V_11 :
V_4 &= 0x0f ;
case V_12 :
case V_13 :
F_3 ( V_4 , V_2 -> V_6 + ( V_3 << 2 ) ) ;
}
}
static unsigned int F_4 ( struct V_1 * V_2 , int V_3 )
{
switch ( V_3 ) {
case V_14 :
return F_5 ( V_2 -> V_6 ) ;
case V_9 :
case V_15 :
case V_16 :
case V_10 :
return F_6 ( V_2 -> V_6 + ( ( V_3 + 1 ) << 2 ) ) ;
case V_11 :
case V_17 :
case V_12 :
case V_13 :
return F_6 ( V_2 -> V_6 + ( V_3 << 2 ) ) ;
}
return 0 ;
}
static int F_7 ( struct V_18 * V_19 )
{
return F_8 ( V_19 , V_12 ) | F_8 ( V_19 , V_13 ) << 8 ;
}
static void F_9 ( struct V_18 * V_19 , int V_4 )
{
F_10 ( V_19 , V_12 , V_4 & 0xff ) ;
F_10 ( V_19 , V_13 , V_4 >> 8 & 0xff ) ;
}
static int F_11 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_12 ( V_21 , V_24 , 0 ) ;
struct V_22 * V_25 = F_12 ( V_21 , V_26 , 0 ) ;
struct V_27 * V_28 ;
struct V_18 V_19 ;
int V_29 ;
if ( ! V_23 || ! V_25 ) {
F_13 ( & V_21 -> V_30 , L_1 ) ;
return - V_31 ;
}
V_28 = F_14 ( & V_21 -> V_30 , sizeof( * V_28 ) , V_32 ) ;
if ( ! V_28 )
return - V_33 ;
V_28 -> V_34 = F_15 ( & V_21 -> V_30 , L_2 ) ;
if ( F_16 ( V_28 -> V_34 ) ) {
F_13 ( & V_21 -> V_30 , L_3 ) ;
return F_17 ( V_28 -> V_34 ) ;
}
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_35 . V_36 = V_23 -> V_37 ;
V_19 . V_35 . V_25 = V_25 -> V_37 ;
V_19 . V_35 . type = V_38 ;
V_19 . V_35 . V_39 = V_40 | V_41 | V_42 ;
V_19 . V_35 . V_30 = & V_21 -> V_30 ;
V_19 . V_35 . V_43 = V_28 ;
F_18 ( V_28 -> V_34 ) ;
V_19 . V_35 . V_44 = F_19 ( V_28 -> V_34 ) ;
V_19 . V_35 . V_45 = V_46 ;
V_19 . V_35 . F_8 = F_4 ;
V_19 . V_35 . F_10 = F_1 ;
V_19 . V_47 = F_7 ;
V_19 . V_48 = F_9 ;
V_29 = F_20 ( & V_19 ) ;
if ( V_29 < 0 ) {
F_13 ( & V_21 -> V_30 , L_4 ) ;
F_21 ( V_28 -> V_34 ) ;
return V_29 ;
}
V_28 -> line = V_29 ;
F_22 ( V_21 , V_28 ) ;
return 0 ;
}
static int F_23 ( struct V_20 * V_21 )
{
struct V_27 * V_28 = F_24 ( V_21 ) ;
F_25 ( V_28 -> line ) ;
F_21 ( V_28 -> V_34 ) ;
return 0 ;
}
