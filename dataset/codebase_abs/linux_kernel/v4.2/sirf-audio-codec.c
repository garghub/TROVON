static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
switch ( V_5 ) {
case V_6 :
F_2 ( 200 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_3 ( struct V_7 * V_7 ,
T_1 V_8 , T_1 V_9 )
{
F_4 ( V_7 , V_10 ,
V_8 | V_9 ,
V_8 ) ;
F_2 ( 20 ) ;
F_4 ( V_7 , V_10 ,
V_9 , V_9 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
#define F_6 (1 << 29)
#define F_7 (1 << 28)
struct V_11 * V_12 = F_8 ( V_2 -> V_13 ) ;
struct V_14 * V_14 = F_9 ( V_12 ) ;
switch ( V_5 ) {
case V_15 :
F_3 ( V_14 -> V_7 ,
F_6 , F_7 ) ;
break;
case V_16 :
F_4 ( V_14 -> V_7 ,
V_10 , F_6 , 0 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
#define F_11 (1 << 27)
#define F_12 (1 << 26)
struct V_11 * V_12 = F_8 ( V_2 -> V_13 ) ;
struct V_14 * V_14 = F_9 ( V_12 ) ;
switch ( V_5 ) {
case V_6 :
F_3 ( V_14 -> V_7 ,
F_11 , F_12 ) ;
break;
case V_16 :
F_4 ( V_14 -> V_7 ,
V_10 , F_11 , 0 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_13 ( struct V_14 * V_14 )
{
F_4 ( V_14 -> V_7 , V_17 ,
V_18 , V_18 ) ;
F_4 ( V_14 -> V_7 , V_17 ,
V_18 , ~ V_18 ) ;
F_14 ( V_14 -> V_7 , V_19 , 0 ) ;
F_14 ( V_14 -> V_7 , V_17 , 0 ) ;
F_4 ( V_14 -> V_7 , V_17 ,
V_20 , V_20 ) ;
F_4 ( V_14 -> V_7 ,
V_21 , V_22 , V_22 ) ;
}
static void F_15 ( struct V_14 * V_14 )
{
F_14 ( V_14 -> V_7 , V_17 , 0 ) ;
F_4 ( V_14 -> V_7 ,
V_21 , V_22 , ~ V_22 ) ;
}
static void F_16 ( struct V_14 * V_14 ,
int V_23 )
{
F_4 ( V_14 -> V_7 , V_24 ,
V_18 , V_18 ) ;
F_4 ( V_14 -> V_7 , V_24 ,
V_18 , ~ V_18 ) ;
F_14 ( V_14 -> V_7 ,
V_25 , 0 ) ;
F_14 ( V_14 -> V_7 , V_24 , 0 ) ;
F_4 ( V_14 -> V_7 , V_24 ,
V_20 , V_20 ) ;
if ( V_23 == 1 )
F_4 ( V_14 -> V_7 ,
V_26 ,
V_27 , V_27 ) ;
else
F_4 ( V_14 -> V_7 ,
V_26 ,
V_28 , V_28 ) ;
}
static void F_17 ( struct V_14 * V_14 )
{
F_4 ( V_14 -> V_7 ,
V_26 ,
V_28 , ~ V_28 ) ;
}
static int F_18 ( struct V_29 * V_30 ,
int V_31 ,
struct V_32 * V_33 )
{
struct V_11 * V_12 = V_33 -> V_12 ;
struct V_14 * V_14 = F_9 ( V_12 ) ;
int V_34 = V_30 -> V_35 == V_36 ;
switch ( V_31 ) {
case V_37 :
case V_38 :
case V_39 :
if ( V_34 ) {
F_19 ( V_12 , V_40 ,
V_41 | V_42 , 0 ) ;
F_15 ( V_14 ) ;
} else
F_17 ( V_14 ) ;
break;
case V_43 :
case V_44 :
case V_45 :
if ( V_34 ) {
F_13 ( V_14 ) ;
F_19 ( V_12 , V_40 ,
V_41 | V_42 , V_41 | V_42 ) ;
} else
F_16 ( V_14 ,
V_30 -> V_46 -> V_23 ) ;
break;
default:
return - V_47 ;
}
return 0 ;
}
static int F_20 ( struct V_11 * V_12 )
{
struct V_48 * V_13 = F_21 ( V_12 ) ;
F_22 ( V_12 -> V_49 ) ;
if ( F_23 ( V_12 -> V_49 -> V_50 , L_1 ) ) {
F_24 ( V_13 ,
V_51 ,
F_25 ( V_51 ) ) ;
F_24 ( V_13 ,
& V_52 , 1 ) ;
return F_26 ( V_12 ,
V_53 ,
F_25 ( V_53 ) ) ;
}
if ( F_23 ( V_12 -> V_49 -> V_50 , L_2 ) ) {
F_24 ( V_13 ,
V_54 ,
F_25 ( V_54 ) ) ;
F_24 ( V_13 ,
& V_55 , 1 ) ;
return F_26 ( V_12 ,
V_56 ,
F_25 ( V_56 ) ) ;
}
return - V_47 ;
}
static int F_27 ( struct V_11 * V_12 )
{
F_28 ( V_12 -> V_49 ) ;
return 0 ;
}
static int F_29 ( struct V_57 * V_58 )
{
int V_59 ;
struct V_14 * V_14 ;
void T_2 * V_60 ;
struct V_61 * V_62 ;
const struct V_63 * V_64 ;
V_64 = F_30 ( V_65 , V_58 -> V_49 . V_50 ) ;
V_14 = F_31 ( & V_58 -> V_49 ,
sizeof( struct V_14 ) , V_66 ) ;
if ( ! V_14 )
return - V_67 ;
F_32 ( V_58 , V_14 ) ;
V_62 = F_33 ( V_58 , V_68 , 0 ) ;
V_60 = F_34 ( & V_58 -> V_49 , V_62 ) ;
if ( F_35 ( V_60 ) )
return F_36 ( V_60 ) ;
V_14 -> V_7 = F_37 ( & V_58 -> V_49 , V_60 ,
& V_69 ) ;
if ( F_35 ( V_14 -> V_7 ) )
return F_36 ( V_14 -> V_7 ) ;
V_14 -> V_70 = F_38 ( & V_58 -> V_49 , NULL ) ;
if ( F_35 ( V_14 -> V_70 ) ) {
F_39 ( & V_58 -> V_49 , L_3 ) ;
return F_36 ( V_14 -> V_70 ) ;
}
V_59 = F_40 ( V_14 -> V_70 ) ;
if ( V_59 ) {
F_39 ( & V_58 -> V_49 , L_4 ) ;
return V_59 ;
}
V_59 = F_41 ( & ( V_58 -> V_49 ) ,
& V_71 ,
& V_72 , 1 ) ;
if ( V_59 ) {
F_39 ( & V_58 -> V_49 , L_5 ) ;
goto V_73;
}
F_4 ( V_14 -> V_7 , V_40 ,
V_74 , V_74 ) ;
if ( F_23 ( V_58 -> V_49 . V_50 , L_2 ) )
F_4 ( V_14 -> V_7 ,
V_40 , V_75 , V_75 ) ;
return 0 ;
V_73:
F_42 ( V_14 -> V_70 ) ;
return V_59 ;
}
static int F_43 ( struct V_57 * V_58 )
{
struct V_14 * V_14 = F_44 ( V_58 ) ;
F_42 ( V_14 -> V_70 ) ;
F_45 ( & ( V_58 -> V_49 ) ) ;
return 0 ;
}
static int F_46 ( struct V_76 * V_49 )
{
struct V_14 * V_14 = F_47 ( V_49 ) ;
F_48 ( V_14 -> V_7 , V_40 ,
& V_14 -> V_77 ) ;
F_48 ( V_14 -> V_7 , V_10 ,
& V_14 -> V_78 ) ;
F_42 ( V_14 -> V_70 ) ;
return 0 ;
}
static int F_49 ( struct V_76 * V_49 )
{
struct V_14 * V_14 = F_47 ( V_49 ) ;
int V_59 ;
V_59 = F_40 ( V_14 -> V_70 ) ;
if ( V_59 )
return V_59 ;
F_14 ( V_14 -> V_7 , V_40 ,
V_14 -> V_77 ) ;
F_14 ( V_14 -> V_7 , V_10 ,
V_14 -> V_78 ) ;
return 0 ;
}
