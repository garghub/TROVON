static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
int V_10 ;
F_2 ( V_9 , 50 ) ;
V_10 = F_3 ( V_9 , V_11 ,
F_4 ( V_4 ) * 512 ,
V_12 ) ;
if ( V_10 < 0 ) {
F_5 ( V_6 -> V_13 , L_1 , V_10 ) ;
return V_10 ;
}
V_10 = F_6 ( V_9 , 0 , V_14 ,
F_4 ( V_4 ) * 50 ,
F_4 ( V_4 ) * 512 ) ;
if ( V_10 < 0 ) {
F_5 ( V_6 -> V_13 , L_2 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int F_7 ( const struct V_15 * V_16 )
{
V_17 = ( unsigned long ) V_16 -> V_18 ;
return 1 ;
}
static int F_8 ( struct V_5 * V_19 )
{
int V_10 ;
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_22 * V_23 = V_19 -> V_23 ;
const struct V_24 * V_25 ;
int V_26 ;
V_23 -> V_27 . V_28 = true ;
F_9 ( V_21 ,
V_29 |
V_30 ,
V_31 ) ;
V_10 = F_10 ( V_23 , V_32 ,
F_11 ( V_32 ) ) ;
if ( V_10 ) {
F_5 ( V_23 -> V_13 , L_3 ) ;
return V_10 ;
}
F_12 ( V_33 ) ;
switch ( F_13 ( V_17 ) ) {
case V_34 :
V_25 = V_35 ;
V_26 = F_11 ( V_35 ) ;
break;
case V_36 :
V_25 = V_37 ;
V_26 = F_11 ( V_37 ) ;
break;
default:
V_25 = V_38 ;
V_26 = F_11 ( V_38 ) ;
}
V_10 = F_14 ( & V_23 -> V_27 , V_25 , V_26 ) ;
if ( V_10 )
return V_10 ;
if ( V_17 & V_39 ) {
V_10 = F_15 ( V_21 , 0 , 0 ) ;
if ( V_10 )
return V_10 ;
}
F_16 ( & V_23 -> V_27 , L_4 ) ;
F_16 ( & V_23 -> V_27 , L_5 ) ;
return V_10 ;
}
static int F_17 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
struct V_40 * V_41 = F_18 ( V_4 ,
V_42 ) ;
struct V_40 * V_43 = F_18 ( V_4 ,
V_44 ) ;
int V_10 ;
V_41 -> V_45 = V_41 -> V_46 = 48000 ;
V_43 -> V_45 = V_43 -> V_46 = 2 ;
F_19 ( V_4 , V_47 ) ;
V_10 = F_20 ( V_6 -> V_48 ,
V_49 |
V_50 |
V_51
) ;
if ( V_10 < 0 ) {
F_5 ( V_6 -> V_13 , L_6 , V_10 ) ;
return V_10 ;
}
V_10 = F_21 ( V_6 -> V_48 , 0x3 , 0x3 , 2 , 24 ) ;
if ( V_10 < 0 ) {
F_5 ( V_6 -> V_13 , L_7 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
return F_23 ( V_2 -> V_19 ,
V_42 , 48000 ) ;
}
static int F_24 ( struct V_52 * V_53 )
{
int V_54 = 0 ;
struct V_55 * V_56 ;
V_57 . V_13 = & V_53 -> V_13 ;
V_56 = V_57 . V_13 -> V_58 ;
snprintf ( V_59 , sizeof( V_59 ) ,
L_8 , L_9 , V_56 -> V_16 , L_10 ) ;
V_60 [ V_61 + 1 ] . V_62 = V_59 ;
V_54 = F_25 ( & V_53 -> V_13 , & V_57 ) ;
if ( V_54 ) {
F_5 ( & V_53 -> V_13 , L_11 ,
V_54 ) ;
return V_54 ;
}
F_26 ( V_53 , & V_57 ) ;
return V_54 ;
}
