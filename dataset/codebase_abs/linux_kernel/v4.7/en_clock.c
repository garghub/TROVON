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
F_19 ( V_26 , V_26 -> V_39 . V_40 ) ;
break;
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
case V_53 :
case V_54 :
F_19 ( V_26 , false ) ;
V_28 . V_37 = V_41 ;
break;
default:
return - V_36 ;
}
memcpy ( & V_26 -> V_2 . V_27 , & V_28 , sizeof( V_28 ) ) ;
return F_20 ( V_24 -> V_31 , & V_28 ,
sizeof( V_28 ) ) ? - V_32 : 0 ;
}
int F_21 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_25 * V_26 = F_16 ( V_22 ) ;
struct V_27 * V_55 = & V_26 -> V_2 . V_27 ;
if ( ! F_17 ( V_26 -> V_12 , V_29 ) )
return - V_30 ;
return F_20 ( V_24 -> V_31 , V_55 , sizeof( * V_55 ) ) ? - V_32 : 0 ;
}
static int F_22 ( struct V_56 * V_57 ,
const struct V_58 * V_59 )
{
struct V_1 * V_2 = F_7 ( V_57 , struct V_1 ,
V_60 ) ;
T_1 V_61 = F_23 ( V_59 ) ;
unsigned long V_19 ;
F_11 ( & V_2 -> V_7 , V_19 ) ;
F_24 ( & V_2 -> clock , & V_2 -> V_11 , V_61 ) ;
F_13 ( & V_2 -> V_7 , V_19 ) ;
return 0 ;
}
static int F_25 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_7 ( V_57 , struct V_1 ,
V_60 ) ;
T_1 V_61 ;
unsigned long V_19 ;
F_11 ( & V_2 -> V_7 , V_19 ) ;
V_61 = F_12 ( & V_2 -> clock ) ;
F_13 ( & V_2 -> V_7 , V_19 ) ;
* V_59 = F_26 ( V_61 ) ;
return 0 ;
}
static int F_27 ( struct V_56 * V_57 , T_3 V_62 )
{
struct V_1 * V_2 = F_7 ( V_57 , struct V_1 ,
V_60 ) ;
unsigned long V_19 ;
F_11 ( & V_2 -> V_7 , V_19 ) ;
F_28 ( & V_2 -> clock , V_62 ) ;
F_13 ( & V_2 -> V_7 , V_19 ) ;
return 0 ;
}
static int F_29 ( struct V_56 * V_57 , T_4 V_62 )
{
T_1 V_63 ;
T_5 V_64 ;
unsigned long V_19 ;
int V_65 = 0 ;
struct V_1 * V_2 = F_7 ( V_57 , struct V_1 ,
V_60 ) ;
if ( V_62 < 0 ) {
V_65 = 1 ;
V_62 = - V_62 ;
}
V_63 = V_2 -> V_66 ;
V_63 *= V_62 ;
V_64 = F_30 ( V_63 , 1000000000ULL ) ;
F_11 ( & V_2 -> V_7 , V_19 ) ;
F_12 ( & V_2 -> clock ) ;
V_2 -> V_11 . V_67 = V_65 ? V_2 -> V_66 - V_64 :
V_2 -> V_66 + V_64 ;
F_13 ( & V_2 -> V_7 , V_19 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
V_2 -> V_27 . V_33 = V_34 ;
V_2 -> V_27 . V_37 = V_38 ;
}
void F_32 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = & V_26 -> V_2 ;
T_1 V_61 ;
T_1 V_68 = 0 ;
T_5 V_69 ;
F_31 ( V_2 ) ;
V_69 = F_17 ( V_26 -> V_12 , V_29 ) ;
if ( ! V_69 ) {
F_33 ( V_26 -> V_12 , L_1 ) ;
return;
}
F_34 ( & V_2 -> V_7 ) ;
V_2 -> V_11 . V_70 = F_6 ;
V_2 -> V_11 . V_71 = V_72 ;
V_2 -> V_11 . V_67 = F_35 ( V_69 ,
V_2 -> V_11 . V_71 ) ;
V_2 -> V_66 = V_2 -> V_11 . V_67 ;
V_2 -> V_11 . V_13 = F_36 ( 41 ) ;
V_2 -> V_12 = V_26 -> V_12 ;
F_24 ( & V_2 -> clock , & V_2 -> V_11 ,
F_37 ( F_38 () ) ) ;
V_61 = F_39 ( & V_2 -> V_11 , V_2 -> V_11 . V_13 ,
V_68 , & V_68 ) ;
F_40 ( V_61 , V_73 / 2 / V_74 ) ;
V_2 -> V_20 = V_61 ;
F_41 ( & V_2 -> V_18 , F_9 ) ;
if ( V_2 -> V_20 )
F_14 ( & V_2 -> V_18 , 0 ) ;
else
F_33 ( V_26 -> V_12 , L_2 ) ;
V_2 -> V_60 = V_75 ;
snprintf ( V_2 -> V_60 . V_76 , 16 , L_3 ) ;
V_2 -> V_57 = F_42 ( & V_2 -> V_60 ,
& V_26 -> V_12 -> V_77 -> V_22 ) ;
if ( F_43 ( V_2 -> V_57 ) ) {
F_33 ( V_26 -> V_12 , L_4 ,
F_44 ( V_2 -> V_57 ) ) ;
V_2 -> V_57 = NULL ;
}
}
void F_45 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = & V_26 -> V_2 ;
if ( ! F_17 ( V_26 -> V_12 , V_29 ) )
return;
if ( V_26 -> V_2 . V_57 ) {
F_46 ( V_26 -> V_2 . V_57 ) ;
V_26 -> V_2 . V_57 = NULL ;
}
F_47 ( & V_2 -> V_18 ) ;
}
