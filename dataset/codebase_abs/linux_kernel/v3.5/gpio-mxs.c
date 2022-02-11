static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_4 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_5 ;
}
static int F_3 ( struct V_6 * V_7 , unsigned int type )
{
T_1 V_8 = F_4 ( V_7 -> V_9 ) ;
T_1 V_10 = 1 << ( V_8 & 31 ) ;
struct V_11 * V_12 = F_5 ( V_7 ) ;
struct V_1 * V_2 = V_12 -> V_13 ;
void T_2 * V_14 ;
int V_15 ;
switch ( type ) {
case V_16 :
V_15 = V_17 ;
break;
case V_18 :
V_15 = V_19 ;
break;
case V_20 :
V_15 = V_21 ;
break;
case V_22 :
V_15 = V_23 ;
break;
default:
return - V_24 ;
}
V_14 = V_2 -> V_25 + F_6 ( V_2 ) ;
if ( V_15 & V_26 )
F_7 ( V_10 , V_14 + V_27 ) ;
else
F_7 ( V_10 , V_14 + V_28 ) ;
V_14 = V_2 -> V_25 + F_8 ( V_2 ) ;
if ( V_15 & V_29 )
F_7 ( V_10 , V_14 + V_27 ) ;
else
F_7 ( V_10 , V_14 + V_28 ) ;
F_7 ( 1 << ( V_8 & 0x1f ) ,
V_2 -> V_25 + F_9 ( V_2 ) + V_28 ) ;
return 0 ;
}
static void F_10 ( T_1 V_9 , struct V_30 * V_31 )
{
T_1 V_32 ;
struct V_1 * V_2 = F_11 ( V_9 ) ;
T_1 V_33 = V_2 -> V_34 ;
V_31 -> V_6 . V_35 -> V_36 ( & V_31 -> V_6 ) ;
V_32 = F_12 ( V_2 -> V_25 + F_9 ( V_2 ) ) &
F_12 ( V_2 -> V_25 + F_13 ( V_2 ) ) ;
while ( V_32 != 0 ) {
int V_37 = F_14 ( V_32 ) - 1 ;
F_15 ( V_33 + V_37 ) ;
V_32 &= ~ ( 1 << V_37 ) ;
}
}
static int F_16 ( struct V_6 * V_7 , unsigned int V_38 )
{
struct V_11 * V_12 = F_5 ( V_7 ) ;
struct V_1 * V_2 = V_12 -> V_13 ;
if ( V_38 )
F_17 ( V_2 -> V_9 ) ;
else
F_18 ( V_2 -> V_9 ) ;
return 0 ;
}
static void T_3 F_19 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_39 * V_40 ;
V_12 = F_20 ( L_1 , 1 , V_2 -> V_34 ,
V_2 -> V_25 , V_41 ) ;
V_12 -> V_13 = V_2 ;
V_40 = V_12 -> V_42 ;
V_40 -> V_35 . V_36 = V_43 ;
V_40 -> V_35 . V_44 = V_45 ;
V_40 -> V_35 . V_46 = V_47 ;
V_40 -> V_35 . V_48 = F_3 ;
V_40 -> V_35 . V_49 = F_16 ;
V_40 -> V_50 . V_51 = F_9 ( V_2 ) + V_28 ;
V_40 -> V_50 . V_52 = F_13 ( V_2 ) ;
F_21 ( V_12 , F_22 ( 32 ) , 0 , V_53 , 0 ) ;
}
static int F_23 ( struct V_54 * V_12 , unsigned V_55 )
{
struct V_56 * V_57 = F_24 ( V_12 ) ;
struct V_1 * V_2 =
F_25 ( V_57 , struct V_1 , V_57 ) ;
return V_2 -> V_34 + V_55 ;
}
static int T_4 F_26 ( struct V_58 * V_59 )
{
const struct V_60 * V_61 =
F_27 ( V_62 , & V_59 -> V_63 ) ;
struct V_64 * V_65 = V_59 -> V_63 . V_66 ;
struct V_64 * V_67 ;
static void T_2 * V_25 ;
struct V_1 * V_2 ;
struct V_68 * V_69 = NULL ;
int V_70 ;
V_2 = F_28 ( & V_59 -> V_63 , sizeof( * V_2 ) , V_71 ) ;
if ( ! V_2 )
return - V_72 ;
if ( V_65 ) {
V_2 -> V_73 = F_29 ( V_65 , L_2 ) ;
if ( V_2 -> V_73 < 0 )
return V_2 -> V_73 ;
V_2 -> V_3 = (enum V_74 ) V_61 -> V_75 ;
} else {
V_2 -> V_73 = V_59 -> V_73 ;
V_2 -> V_3 = V_59 -> V_76 -> V_77 ;
}
V_2 -> V_34 = V_78 + V_2 -> V_73 * 32 ;
V_2 -> V_9 = F_30 ( V_59 , 0 ) ;
if ( V_2 -> V_9 < 0 )
return V_2 -> V_9 ;
if ( ! V_25 ) {
if ( V_65 ) {
V_67 = F_31 ( V_65 ) ;
V_25 = F_32 ( V_67 , 0 ) ;
F_33 ( V_67 ) ;
} else {
V_69 = F_34 ( V_59 , V_79 , 0 ) ;
V_25 = F_35 ( & V_59 -> V_63 , V_69 ) ;
}
if ( ! V_25 )
return - V_80 ;
}
V_2 -> V_25 = V_25 ;
F_7 ( ~ 0U , V_2 -> V_25 + F_36 ( V_2 ) ) ;
F_7 ( 0 , V_2 -> V_25 + F_13 ( V_2 ) ) ;
F_7 ( ~ 0U , V_2 -> V_25 + F_9 ( V_2 ) + V_28 ) ;
F_19 ( V_2 ) ;
F_37 ( V_2 -> V_9 , F_10 ) ;
F_38 ( V_2 -> V_9 , V_2 ) ;
V_70 = F_39 ( & V_2 -> V_57 , & V_59 -> V_63 , 4 ,
V_2 -> V_25 + F_40 ( V_2 ) ,
V_2 -> V_25 + F_41 ( V_2 ) , NULL ,
V_2 -> V_25 + F_42 ( V_2 ) , NULL , 0 ) ;
if ( V_70 )
return V_70 ;
V_2 -> V_57 . V_12 . V_81 = F_23 ;
V_2 -> V_57 . V_12 . V_25 = V_2 -> V_73 * 32 ;
V_70 = F_43 ( & V_2 -> V_57 . V_12 ) ;
if ( V_70 ) {
F_44 ( & V_2 -> V_57 ) ;
return V_70 ;
}
return 0 ;
}
static int T_3 F_45 ( void )
{
return F_46 ( & V_82 ) ;
}
