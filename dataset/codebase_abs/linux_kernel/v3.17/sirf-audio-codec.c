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
struct V_11 * V_11 = F_8 ( V_2 -> V_12 -> V_13 ) ;
switch ( V_5 ) {
case V_14 :
F_3 ( V_11 -> V_7 ,
F_6 , F_7 ) ;
break;
case V_15 :
F_4 ( V_11 -> V_7 ,
V_10 , F_6 , 0 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
#define F_10 (1 << 27)
#define F_11 (1 << 26)
struct V_11 * V_11 = F_8 ( V_2 -> V_12 -> V_13 ) ;
switch ( V_5 ) {
case V_6 :
F_3 ( V_11 -> V_7 ,
F_10 , F_11 ) ;
break;
case V_15 :
F_4 ( V_11 -> V_7 ,
V_10 , F_10 , 0 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_12 ( struct V_11 * V_11 )
{
F_4 ( V_11 -> V_7 , V_16 ,
V_17 , V_17 ) ;
F_4 ( V_11 -> V_7 , V_16 ,
V_17 , ~ V_17 ) ;
F_13 ( V_11 -> V_7 , V_18 , 0 ) ;
F_13 ( V_11 -> V_7 , V_16 , 0 ) ;
F_4 ( V_11 -> V_7 , V_16 ,
V_19 , V_19 ) ;
F_4 ( V_11 -> V_7 ,
V_20 , V_21 , V_21 ) ;
}
static void F_14 ( struct V_11 * V_11 )
{
F_13 ( V_11 -> V_7 , V_16 , 0 ) ;
F_4 ( V_11 -> V_7 ,
V_20 , V_21 , ~ V_21 ) ;
}
static void F_15 ( struct V_11 * V_11 ,
int V_22 )
{
F_4 ( V_11 -> V_7 , V_23 ,
V_17 , V_17 ) ;
F_4 ( V_11 -> V_7 , V_23 ,
V_17 , ~ V_17 ) ;
F_13 ( V_11 -> V_7 ,
V_24 , 0 ) ;
F_13 ( V_11 -> V_7 , V_23 , 0 ) ;
F_4 ( V_11 -> V_7 , V_23 ,
V_19 , V_19 ) ;
if ( V_22 == 1 )
F_4 ( V_11 -> V_7 ,
V_25 ,
V_26 , V_26 ) ;
else
F_4 ( V_11 -> V_7 ,
V_25 ,
V_27 , V_27 ) ;
}
static void F_16 ( struct V_11 * V_11 )
{
F_4 ( V_11 -> V_7 ,
V_25 ,
V_27 , ~ V_27 ) ;
}
static int F_17 ( struct V_28 * V_29 ,
int V_30 ,
struct V_31 * V_32 )
{
struct V_33 * V_12 = V_32 -> V_12 ;
struct V_11 * V_11 = F_18 ( V_12 ) ;
int V_34 = V_29 -> V_35 == V_36 ;
switch ( V_30 ) {
case V_37 :
case V_38 :
case V_39 :
if ( V_34 ) {
F_19 ( V_12 , V_40 ,
V_41 | V_42 , 0 ) ;
F_14 ( V_11 ) ;
} else
F_16 ( V_11 ) ;
break;
case V_43 :
case V_44 :
case V_45 :
if ( V_34 ) {
F_12 ( V_11 ) ;
F_19 ( V_12 , V_40 ,
V_41 | V_42 , V_41 | V_42 ) ;
} else
F_15 ( V_11 ,
V_29 -> V_46 -> V_22 ) ;
break;
default:
return - V_47 ;
}
return 0 ;
}
static int F_20 ( struct V_33 * V_12 )
{
struct V_48 * V_49 = & V_12 -> V_49 ;
F_21 ( V_12 -> V_13 ) ;
if ( F_22 ( V_12 -> V_13 -> V_50 , L_1 ) ) {
F_23 ( V_49 ,
V_51 ,
F_24 ( V_51 ) ) ;
F_23 ( V_49 ,
& V_52 , 1 ) ;
return F_25 ( V_12 ,
V_53 ,
F_24 ( V_53 ) ) ;
}
if ( F_22 ( V_12 -> V_13 -> V_50 , L_2 ) ) {
F_23 ( V_49 ,
V_54 ,
F_24 ( V_54 ) ) ;
F_23 ( V_49 ,
& V_55 , 1 ) ;
return F_25 ( V_12 ,
V_56 ,
F_24 ( V_56 ) ) ;
}
return - V_47 ;
}
static int F_26 ( struct V_33 * V_12 )
{
F_27 ( V_12 -> V_13 ) ;
return 0 ;
}
static int F_28 ( struct V_57 * V_58 )
{
int V_59 ;
struct V_11 * V_11 ;
void T_2 * V_60 ;
struct V_61 * V_62 ;
const struct V_63 * V_64 ;
V_64 = F_29 ( V_65 , V_58 -> V_13 . V_50 ) ;
V_11 = F_30 ( & V_58 -> V_13 ,
sizeof( struct V_11 ) , V_66 ) ;
if ( ! V_11 )
return - V_67 ;
F_31 ( V_58 , V_11 ) ;
V_62 = F_32 ( V_58 , V_68 , 0 ) ;
V_60 = F_33 ( & V_58 -> V_13 , V_62 ) ;
if ( F_34 ( V_60 ) )
return F_35 ( V_60 ) ;
V_11 -> V_7 = F_36 ( & V_58 -> V_13 , V_60 ,
& V_69 ) ;
if ( F_34 ( V_11 -> V_7 ) )
return F_35 ( V_11 -> V_7 ) ;
V_11 -> V_70 = F_37 ( & V_58 -> V_13 , NULL ) ;
if ( F_34 ( V_11 -> V_70 ) ) {
F_38 ( & V_58 -> V_13 , L_3 ) ;
return F_35 ( V_11 -> V_70 ) ;
}
V_59 = F_39 ( V_11 -> V_70 ) ;
if ( V_59 ) {
F_38 ( & V_58 -> V_13 , L_4 ) ;
return V_59 ;
}
V_59 = F_40 ( & ( V_58 -> V_13 ) ,
& V_71 ,
& V_72 , 1 ) ;
if ( V_59 ) {
F_38 ( & V_58 -> V_13 , L_5 ) ;
goto V_73;
}
F_4 ( V_11 -> V_7 , V_40 ,
V_74 , V_74 ) ;
if ( F_22 ( V_58 -> V_13 . V_50 , L_2 ) )
F_4 ( V_11 -> V_7 ,
V_40 , V_75 , V_75 ) ;
return 0 ;
V_73:
F_41 ( V_11 -> V_70 ) ;
return V_59 ;
}
static int F_42 ( struct V_57 * V_58 )
{
struct V_11 * V_11 = F_43 ( V_58 ) ;
F_41 ( V_11 -> V_70 ) ;
F_44 ( & ( V_58 -> V_13 ) ) ;
return 0 ;
}
static int F_45 ( struct V_76 * V_13 )
{
struct V_11 * V_11 = F_8 ( V_13 ) ;
F_46 ( V_11 -> V_7 , V_40 ,
& V_11 -> V_77 ) ;
F_46 ( V_11 -> V_7 , V_10 ,
& V_11 -> V_78 ) ;
F_41 ( V_11 -> V_70 ) ;
return 0 ;
}
static int F_47 ( struct V_76 * V_13 )
{
struct V_11 * V_11 = F_8 ( V_13 ) ;
int V_59 ;
V_59 = F_39 ( V_11 -> V_70 ) ;
if ( V_59 )
return V_59 ;
F_13 ( V_11 -> V_7 , V_40 ,
V_11 -> V_77 ) ;
F_13 ( V_11 -> V_7 , V_10 ,
V_11 -> V_78 ) ;
return 0 ;
}
