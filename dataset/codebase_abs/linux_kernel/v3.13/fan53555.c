static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
if ( V_5 -> V_7 == V_3 )
return 0 ;
V_6 = F_3 ( V_2 , V_3 , V_3 ) ;
if ( V_6 < 0 )
return - V_8 ;
V_6 = F_4 ( V_5 -> V_9 , V_5 -> V_10 ,
V_11 , V_6 ) ;
if ( V_6 < 0 )
return - V_8 ;
V_5 -> V_7 = V_3 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned int V_12 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_12 ) {
case V_13 :
F_4 ( V_5 -> V_9 , V_5 -> V_14 ,
V_15 , V_15 ) ;
break;
case V_16 :
F_4 ( V_5 -> V_9 , V_5 -> V_14 , V_15 , 0 ) ;
break;
default:
return - V_8 ;
}
return 0 ;
}
static unsigned int F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_17 ;
int V_6 = 0 ;
V_6 = F_7 ( V_5 -> V_9 , V_5 -> V_14 , & V_17 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_17 & V_15 )
return V_13 ;
else
return V_16 ;
}
static int F_8 ( struct V_4 * V_5 ,
struct V_18 * V_19 )
{
unsigned int V_20 , V_21 , V_22 ;
switch ( V_19 -> V_23 ) {
case V_24 :
V_5 -> V_10 = V_25 ;
V_5 -> V_14 = V_26 ;
break;
case V_27 :
V_5 -> V_10 = V_26 ;
V_5 -> V_14 = V_25 ;
break;
default:
F_9 ( V_5 -> V_28 , L_1 ) ;
return - V_8 ;
}
switch ( V_5 -> V_29 ) {
case V_30 :
case V_31 :
case V_32 :
case V_33 :
V_5 -> V_34 = 600000 ;
V_5 -> V_35 = 10000 ;
break;
case V_36 :
V_5 -> V_34 = 603000 ;
V_5 -> V_35 = 12826 ;
break;
default:
F_9 ( V_5 -> V_28 ,
L_2 , V_5 -> V_29 ) ;
return - V_8 ;
}
if ( V_19 -> V_37 & 0x7 )
V_5 -> V_37 = V_19 -> V_37 ;
else
V_5 -> V_37 = V_38 ;
V_20 = V_39 ;
V_21 = V_5 -> V_37 << V_40 ;
V_22 = V_41 ;
return F_4 ( V_5 -> V_9 , V_20 , V_22 , V_21 ) ;
}
static int F_10 ( struct V_4 * V_5 ,
struct V_42 * V_43 )
{
struct V_44 * V_45 = & V_5 -> V_46 ;
V_45 -> V_47 = L_3 ;
V_45 -> V_48 = & V_49 ;
V_45 -> type = V_50 ;
V_45 -> V_51 = V_52 ;
V_45 -> V_53 = V_5 -> V_14 ;
V_45 -> V_54 = V_55 ;
V_45 -> V_56 = V_5 -> V_34 ;
V_45 -> V_57 = V_5 -> V_35 ;
V_45 -> V_58 = V_5 -> V_14 ;
V_45 -> V_59 = V_11 ;
V_45 -> V_60 = V_61 ;
V_5 -> V_2 = F_11 ( V_5 -> V_28 , & V_5 -> V_46 , V_43 ) ;
return F_12 ( V_5 -> V_2 ) ;
}
static int F_13 ( struct V_62 * V_63 ,
const struct V_64 * V_65 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
struct V_42 V_43 = { } ;
unsigned int V_17 ;
int V_6 ;
V_19 = F_14 ( & V_63 -> V_28 ) ;
if ( ! V_19 || ! V_19 -> V_66 ) {
F_9 ( & V_63 -> V_28 , L_4 ) ;
return - V_67 ;
}
V_5 = F_15 ( & V_63 -> V_28 , sizeof( struct V_4 ) ,
V_68 ) ;
if ( ! V_5 ) {
F_9 ( & V_63 -> V_28 , L_5 ) ;
return - V_69 ;
}
V_5 -> V_9 = F_16 ( V_63 , & V_70 ) ;
if ( F_17 ( V_5 -> V_9 ) ) {
F_9 ( & V_63 -> V_28 , L_6 ) ;
return F_18 ( V_5 -> V_9 ) ;
}
V_5 -> V_28 = & V_63 -> V_28 ;
V_5 -> V_66 = V_19 -> V_66 ;
F_19 ( V_63 , V_5 ) ;
V_6 = F_7 ( V_5 -> V_9 , V_71 , & V_17 ) ;
if ( V_6 < 0 ) {
F_9 ( & V_63 -> V_28 , L_7 ) ;
return - V_67 ;
}
V_5 -> V_29 = V_17 & V_72 ;
V_6 = F_7 ( V_5 -> V_9 , V_73 , & V_17 ) ;
if ( V_6 < 0 ) {
F_9 ( & V_63 -> V_28 , L_8 ) ;
return - V_67 ;
}
V_5 -> V_74 = V_17 & V_75 ;
F_20 ( & V_63 -> V_28 , L_9 ,
V_5 -> V_29 , V_5 -> V_74 ) ;
V_6 = F_8 ( V_5 , V_19 ) ;
if ( V_6 < 0 ) {
F_9 ( & V_63 -> V_28 , L_10 ) ;
return V_6 ;
}
V_43 . V_28 = V_5 -> V_28 ;
V_43 . V_76 = V_5 -> V_66 ;
V_43 . V_9 = V_5 -> V_9 ;
V_43 . V_77 = V_5 ;
V_6 = F_10 ( V_5 , & V_43 ) ;
if ( V_6 < 0 )
F_9 ( & V_63 -> V_28 , L_11 ) ;
return V_6 ;
}
