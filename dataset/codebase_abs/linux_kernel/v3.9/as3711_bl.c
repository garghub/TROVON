static struct V_1 * F_1 ( struct V_2 * V_3 )
{
switch ( V_3 -> type ) {
case V_4 :
return F_2 ( V_3 , struct V_1 , V_5 ) ;
case V_6 :
return F_2 ( V_3 , struct V_1 , V_7 ) ;
}
return NULL ;
}
static int F_3 ( struct V_2 * V_8 ,
unsigned int V_9 )
{
struct V_1 * V_10 = F_1 ( V_8 ) ;
struct V_11 * V_11 = V_10 -> V_11 ;
const struct V_12 * V_13 = V_10 -> V_13 ;
int V_14 = 0 ;
if ( V_13 -> V_15 )
V_14 = F_4 ( V_11 -> V_16 , V_17 ,
V_9 ) ;
if ( ! V_14 && V_13 -> V_18 )
V_14 = F_4 ( V_11 -> V_16 , V_19 ,
V_9 ) ;
if ( ! V_14 && V_13 -> V_20 )
V_14 = F_4 ( V_11 -> V_16 , V_21 ,
V_9 ) ;
return V_14 ;
}
static int F_5 ( struct V_11 * V_11 ,
unsigned int V_9 ,
unsigned int V_22 )
{
if ( V_9 > 31 )
return - V_23 ;
return F_6 ( V_11 -> V_16 , V_22 , 0xf0 ,
V_9 << 4 ) ;
}
static int F_7 ( struct V_1 * V_10 )
{
struct V_11 * V_11 = V_10 -> V_11 ;
int V_14 = F_6 ( V_11 -> V_16 , V_24 ,
3 , V_10 -> V_13 -> V_25 ) ;
if ( ! V_14 )
V_14 = F_6 ( V_11 -> V_16 ,
V_26 , 1 , 0 ) ;
if ( ! V_14 )
V_14 = F_6 ( V_11 -> V_16 ,
V_26 , 1 , 1 ) ;
return V_14 ;
}
static int F_8 ( struct V_27 * V_28 )
{
struct V_2 * V_8 = F_9 ( V_28 ) ;
struct V_1 * V_10 = F_1 ( V_8 ) ;
struct V_11 * V_11 = V_10 -> V_11 ;
int V_9 = V_28 -> V_29 . V_9 ;
int V_14 = 0 ;
F_10 ( & V_28 -> V_30 , L_1 ,
V_31 , V_28 -> V_29 . V_9 , V_28 -> V_29 . V_32 ,
V_28 -> V_29 . V_33 , V_28 -> V_29 . V_34 ) ;
if ( V_28 -> V_29 . V_32 != V_35 ||
V_28 -> V_29 . V_33 != V_35 ||
V_28 -> V_29 . V_34 & ( V_36 | V_37 ) )
V_9 = 0 ;
if ( V_8 -> type == V_4 ) {
V_14 = F_5 ( V_11 , V_9 ,
V_38 ) ;
} else {
const struct V_12 * V_13 = V_10 -> V_13 ;
switch ( V_13 -> V_39 ) {
case V_40 :
V_14 = F_5 ( V_11 , V_9 ,
V_26 ) ;
break;
case V_41 :
V_14 = F_3 ( V_8 , V_9 / 4 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_9 ) {
V_14 = F_7 ( V_10 ) ;
if ( V_14 < 0 )
return V_14 ;
F_11 ( 500 ) ;
V_14 = F_3 ( V_8 , V_9 ) ;
} else {
V_14 = F_6 ( V_11 -> V_16 ,
V_26 , 1 , 0 ) ;
}
break;
case V_42 :
V_14 = F_4 ( V_11 -> V_16 , V_17 ,
V_9 ) ;
break;
case V_43 :
V_14 = F_4 ( V_11 -> V_16 , V_19 ,
V_9 ) ;
break;
case V_44 :
V_14 = F_4 ( V_11 -> V_16 , V_21 ,
V_9 ) ;
break;
default:
V_14 = - V_23 ;
}
}
if ( ! V_14 )
V_8 -> V_9 = V_9 ;
return V_14 ;
}
static int F_12 ( struct V_27 * V_28 )
{
struct V_2 * V_8 = F_9 ( V_28 ) ;
return V_8 -> V_9 ;
}
static int F_13 ( struct V_1 * V_10 )
{
struct V_11 * V_11 = V_10 -> V_11 ;
const struct V_12 * V_13 = V_10 -> V_13 ;
T_1 V_45 = 0 ;
int V_14 ;
F_10 ( V_11 -> V_30 , L_2 , V_31 , V_13 -> V_39 ) ;
V_14 = F_4 ( V_11 -> V_16 , V_26 , 0 ) ;
if ( V_14 < 0 )
return V_14 ;
switch ( V_13 -> V_39 ) {
case V_40 :
V_14 = F_6 ( V_11 -> V_16 , V_46 , 3 , 0 ) ;
break;
case V_42 :
V_45 = 1 ;
V_14 = F_6 ( V_11 -> V_16 , V_46 , 3 , 1 ) ;
break;
case V_43 :
V_45 = 4 ;
V_14 = F_6 ( V_11 -> V_16 , V_46 , 3 , 2 ) ;
break;
case V_44 :
V_45 = 0x10 ;
V_14 = F_6 ( V_11 -> V_16 , V_46 , 3 , 3 ) ;
break;
case V_41 :
if ( V_13 -> V_15 )
V_45 = 2 ;
if ( V_13 -> V_18 )
V_45 |= 8 ;
if ( V_13 -> V_20 )
V_45 |= 0x20 ;
V_14 = 0 ;
break;
default:
return - V_23 ;
}
if ( ! V_14 )
V_14 = F_4 ( V_11 -> V_16 , V_47 , V_45 ) ;
return V_14 ;
}
static int F_14 ( struct V_48 * V_49 ,
unsigned int V_50 , struct V_2 * V_3 )
{
struct V_51 V_29 = { . type = V_52 ,} ;
struct V_27 * V_28 ;
V_29 . V_50 = V_50 ;
V_28 = F_15 ( V_3 -> type == V_4 ?
L_3 : L_4 ,
& V_49 -> V_30 , V_3 ,
& V_53 , & V_29 ) ;
if ( F_16 ( V_28 ) ) {
F_17 ( & V_49 -> V_30 , L_5 ) ;
return F_18 ( V_28 ) ;
}
V_28 -> V_29 . V_9 = V_29 . V_50 ;
F_19 ( V_28 ) ;
V_3 -> V_28 = V_28 ;
return 0 ;
}
static int F_20 ( struct V_48 * V_49 )
{
struct V_12 * V_13 = F_21 ( & V_49 -> V_30 ) ;
struct V_11 * V_11 = F_22 ( V_49 -> V_30 . V_54 ) ;
struct V_1 * V_10 ;
struct V_2 * V_3 ;
unsigned int V_50 ;
int V_14 ;
if ( ! V_13 || ( ! V_13 -> V_55 && ! V_13 -> V_56 ) ) {
F_17 ( & V_49 -> V_30 , L_6 ) ;
return - V_57 ;
}
if ( V_13 -> V_55 ||
V_13 -> V_25 != V_58 ||
V_13 -> V_39 != V_41 ) {
F_23 ( & V_49 -> V_30 ,
L_7
L_8 ) ;
return - V_23 ;
}
V_10 = F_24 ( & V_49 -> V_30 , sizeof( * V_10 ) , V_59 ) ;
if ( ! V_10 )
return - V_60 ;
V_10 -> V_11 = V_11 ;
V_10 -> V_13 = V_13 ;
if ( V_13 -> V_55 ) {
V_3 = & V_10 -> V_5 ;
V_3 -> V_61 = V_13 -> V_55 ;
V_3 -> type = V_4 ;
V_50 = F_25 ( V_13 -> V_62 , 31 ) ;
V_14 = F_14 ( V_49 , V_50 , V_3 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( V_13 -> V_56 ) {
V_3 = & V_10 -> V_7 ;
V_3 -> V_61 = V_13 -> V_56 ;
V_3 -> type = V_6 ;
switch ( V_13 -> V_25 ) {
case V_63 :
case V_64 :
case V_58 :
case V_65 :
break;
default:
V_14 = - V_23 ;
goto V_66;
}
switch ( V_13 -> V_39 ) {
case V_40 :
V_50 = F_25 ( V_13 -> V_67 , 31 ) ;
break;
case V_42 :
case V_43 :
case V_44 :
case V_41 :
V_50 = F_25 ( V_13 -> V_67 / 150 , 255 ) ;
break;
default:
V_14 = - V_23 ;
goto V_66;
}
V_14 = F_13 ( V_10 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_14 ( V_49 , V_50 , V_3 ) ;
if ( V_14 < 0 )
goto V_66;
}
F_26 ( V_49 , V_10 ) ;
return 0 ;
V_66:
F_27 ( V_10 -> V_5 . V_28 ) ;
return V_14 ;
}
static int F_28 ( struct V_48 * V_49 )
{
struct V_1 * V_10 = F_29 ( V_49 ) ;
F_27 ( V_10 -> V_5 . V_28 ) ;
F_27 ( V_10 -> V_7 . V_28 ) ;
return 0 ;
}
