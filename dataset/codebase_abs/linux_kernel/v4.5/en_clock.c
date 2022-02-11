void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
T_1 V_6 ;
F_2 ( & V_2 -> V_7 ) ;
V_6 = F_3 ( & V_2 -> clock , V_3 ) ;
F_4 ( & V_2 -> V_7 ) ;
V_5 -> V_8 = F_5 ( V_6 ) ;
}
static T_2 F_6 ( const struct V_9 * V_10 )
{
struct V_1 * V_2 = F_7 ( V_10 , struct V_1 ,
V_11 ) ;
return F_8 ( V_2 -> V_12 ) & V_10 -> V_13 ;
}
static void F_9 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_10 ( V_15 ) ;
struct V_1 * V_2 = F_7 ( V_17 , struct V_1 ,
V_18 ) ;
unsigned long V_19 ;
F_11 ( & V_2 -> V_7 , V_19 ) ;
F_12 ( & V_2 -> clock ) ;
F_13 ( & V_2 -> V_7 , V_19 ) ;
F_14 ( & V_2 -> V_18 , V_2 -> V_20 ) ;
}
int F_15 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_25 * V_26 = F_16 ( V_22 ) ;
struct V_27 V_28 ;
if ( ! F_17 ( V_26 -> V_12 , V_29 ) )
return - V_30 ;
if ( F_18 ( & V_28 , V_24 -> V_31 , sizeof( V_28 ) ) )
return - V_32 ;
switch ( V_28 . V_33 ) {
case V_34 :
case V_35 :
break;
default:
return - V_36 ;
}
switch ( V_28 . V_37 ) {
case V_38 :
break;
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
V_28 . V_37 = V_39 ;
break;
default:
return - V_36 ;
}
memcpy ( & V_26 -> V_2 . V_27 , & V_28 , sizeof( V_28 ) ) ;
return F_19 ( V_24 -> V_31 , & V_28 ,
sizeof( V_28 ) ) ? - V_32 : 0 ;
}
int F_20 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_25 * V_26 = F_16 ( V_22 ) ;
struct V_27 * V_53 = & V_26 -> V_2 . V_27 ;
if ( ! F_17 ( V_26 -> V_12 , V_29 ) )
return - V_30 ;
return F_19 ( V_24 -> V_31 , V_53 , sizeof( * V_53 ) ) ? - V_32 : 0 ;
}
static int F_21 ( struct V_54 * V_55 ,
const struct V_56 * V_57 )
{
struct V_1 * V_2 = F_7 ( V_55 , struct V_1 ,
V_58 ) ;
T_1 V_59 = F_22 ( V_57 ) ;
unsigned long V_19 ;
F_11 ( & V_2 -> V_7 , V_19 ) ;
F_23 ( & V_2 -> clock , & V_2 -> V_11 , V_59 ) ;
F_13 ( & V_2 -> V_7 , V_19 ) ;
return 0 ;
}
static int F_24 ( struct V_54 * V_55 ,
struct V_56 * V_57 )
{
struct V_1 * V_2 = F_7 ( V_55 , struct V_1 ,
V_58 ) ;
T_1 V_59 ;
unsigned long V_19 ;
F_11 ( & V_2 -> V_7 , V_19 ) ;
V_59 = F_12 ( & V_2 -> clock ) ;
F_13 ( & V_2 -> V_7 , V_19 ) ;
* V_57 = F_25 ( V_59 ) ;
return 0 ;
}
static int F_26 ( struct V_54 * V_55 , T_3 V_60 )
{
struct V_1 * V_2 = F_7 ( V_55 , struct V_1 ,
V_58 ) ;
unsigned long V_19 ;
F_11 ( & V_2 -> V_7 , V_19 ) ;
F_27 ( & V_2 -> clock , V_60 ) ;
F_13 ( & V_2 -> V_7 , V_19 ) ;
return 0 ;
}
static int F_28 ( struct V_54 * V_55 , T_4 V_60 )
{
T_1 V_61 ;
T_5 V_62 ;
unsigned long V_19 ;
int V_63 = 0 ;
struct V_1 * V_2 = F_7 ( V_55 , struct V_1 ,
V_58 ) ;
if ( V_60 < 0 ) {
V_63 = 1 ;
V_60 = - V_60 ;
}
V_61 = V_2 -> V_64 ;
V_61 *= V_60 ;
V_62 = F_29 ( V_61 , 1000000000ULL ) ;
F_11 ( & V_2 -> V_7 , V_19 ) ;
F_12 ( & V_2 -> clock ) ;
V_2 -> V_11 . V_65 = V_63 ? V_2 -> V_64 - V_62 :
V_2 -> V_64 + V_62 ;
F_13 ( & V_2 -> V_7 , V_19 ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
V_2 -> V_27 . V_33 = V_34 ;
V_2 -> V_27 . V_37 = V_38 ;
}
void F_31 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = & V_26 -> V_2 ;
T_1 V_59 ;
T_1 V_66 = 0 ;
T_5 V_67 ;
F_30 ( V_2 ) ;
V_67 = F_17 ( V_26 -> V_12 , V_29 ) ;
if ( ! V_67 ) {
F_32 ( V_26 -> V_12 , L_1 ) ;
return;
}
F_33 ( & V_2 -> V_7 ) ;
V_2 -> V_11 . V_68 = F_6 ;
V_2 -> V_11 . V_69 = V_70 ;
V_2 -> V_11 . V_65 = F_34 ( V_67 ,
V_2 -> V_11 . V_69 ) ;
V_2 -> V_64 = V_2 -> V_11 . V_65 ;
V_2 -> V_11 . V_13 = F_35 ( 41 ) ;
V_2 -> V_12 = V_26 -> V_12 ;
F_23 ( & V_2 -> clock , & V_2 -> V_11 ,
F_36 ( F_37 () ) ) ;
V_59 = F_38 ( & V_2 -> V_11 , V_2 -> V_11 . V_13 ,
V_66 , & V_66 ) ;
F_39 ( V_59 , V_71 / 2 / V_72 ) ;
V_2 -> V_20 = V_59 ;
F_40 ( & V_2 -> V_18 , F_9 ) ;
if ( V_2 -> V_20 )
F_14 ( & V_2 -> V_18 , 0 ) ;
else
F_32 ( V_26 -> V_12 , L_2 ) ;
V_2 -> V_58 = V_73 ;
snprintf ( V_2 -> V_58 . V_74 , 16 , L_3 ) ;
V_2 -> V_55 = F_41 ( & V_2 -> V_58 ,
& V_26 -> V_12 -> V_75 -> V_22 ) ;
if ( F_42 ( V_2 -> V_55 ) ) {
F_32 ( V_26 -> V_12 , L_4 ,
F_43 ( V_2 -> V_55 ) ) ;
V_2 -> V_55 = NULL ;
}
}
void F_44 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = & V_26 -> V_2 ;
if ( ! F_17 ( V_26 -> V_12 , V_29 ) )
return;
if ( V_26 -> V_2 . V_55 ) {
F_45 ( V_26 -> V_2 . V_55 ) ;
V_26 -> V_2 . V_55 = NULL ;
}
F_46 ( & V_2 -> V_18 ) ;
}
