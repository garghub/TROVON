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
V_8 | ~ V_9 ) ;
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
V_10 , F_6 ,
~ F_6 ) ;
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
V_10 , F_10 ,
~ F_10 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_12 ( struct V_16 * V_17 ,
int V_18 ,
struct V_19 * V_20 )
{
int V_21 = V_17 -> V_22 == V_23 ;
struct V_24 * V_12 = V_20 -> V_12 ;
T_1 V_25 = 0 ;
switch ( V_18 ) {
case V_26 :
case V_27 :
case V_28 :
break;
case V_29 :
case V_30 :
case V_31 :
if ( V_21 )
V_25 = V_32 | V_33 ;
break;
default:
return - V_34 ;
}
if ( V_21 )
F_13 ( V_12 , V_35 ,
V_32 | V_33 , V_25 ) ;
return 0 ;
}
static int F_14 ( struct V_24 * V_12 )
{
struct V_36 * V_37 = & V_12 -> V_37 ;
F_15 ( V_12 -> V_13 ) ;
if ( F_16 ( V_12 -> V_13 -> V_38 , L_1 ) ) {
F_17 ( V_37 ,
V_39 ,
F_18 ( V_39 ) ) ;
F_17 ( V_37 ,
& V_40 , 1 ) ;
return F_19 ( V_12 ,
V_41 ,
F_18 ( V_41 ) ) ;
}
if ( F_16 ( V_12 -> V_13 -> V_38 , L_2 ) ) {
F_17 ( V_37 ,
V_42 ,
F_18 ( V_42 ) ) ;
F_17 ( V_37 ,
& V_43 , 1 ) ;
return F_19 ( V_12 ,
V_44 ,
F_18 ( V_44 ) ) ;
}
return - V_34 ;
}
static int F_20 ( struct V_24 * V_12 )
{
F_21 ( V_12 -> V_13 ) ;
return 0 ;
}
static int F_22 ( struct V_45 * V_46 )
{
int V_47 ;
struct V_11 * V_11 ;
void T_2 * V_48 ;
struct V_49 * V_50 ;
const struct V_51 * V_52 ;
V_52 = F_23 ( V_53 , V_46 -> V_13 . V_38 ) ;
V_11 = F_24 ( & V_46 -> V_13 ,
sizeof( struct V_11 ) , V_54 ) ;
if ( ! V_11 )
return - V_55 ;
F_25 ( V_46 , V_11 ) ;
V_50 = F_26 ( V_46 , V_56 , 0 ) ;
V_48 = F_27 ( & V_46 -> V_13 , V_50 ) ;
if ( V_48 == NULL )
return - V_55 ;
V_11 -> V_7 = F_28 ( & V_46 -> V_13 , V_48 ,
& V_57 ) ;
if ( F_29 ( V_11 -> V_7 ) )
return F_30 ( V_11 -> V_7 ) ;
V_11 -> V_58 = F_31 ( & V_46 -> V_13 , NULL ) ;
if ( F_29 ( V_11 -> V_58 ) ) {
F_32 ( & V_46 -> V_13 , L_3 ) ;
return F_30 ( V_11 -> V_58 ) ;
}
V_47 = F_33 ( V_11 -> V_58 ) ;
if ( V_47 ) {
F_32 ( & V_46 -> V_13 , L_4 ) ;
return V_47 ;
}
V_47 = F_34 ( & ( V_46 -> V_13 ) ,
& V_59 ,
& V_60 , 1 ) ;
if ( V_47 ) {
F_32 ( & V_46 -> V_13 , L_5 ) ;
goto V_61;
}
F_4 ( V_11 -> V_7 , V_35 ,
V_62 , V_62 ) ;
if ( F_16 ( V_46 -> V_13 . V_38 , L_2 ) )
F_4 ( V_11 -> V_7 ,
V_35 , V_63 , V_63 ) ;
return 0 ;
V_61:
F_35 ( V_11 -> V_58 ) ;
return V_47 ;
}
static int F_36 ( struct V_45 * V_46 )
{
struct V_11 * V_11 = F_37 ( V_46 ) ;
F_35 ( V_11 -> V_58 ) ;
F_38 ( & ( V_46 -> V_13 ) ) ;
return 0 ;
}
static int F_39 ( struct V_64 * V_13 )
{
struct V_11 * V_11 = F_8 ( V_13 ) ;
F_40 ( V_11 -> V_7 , V_35 ,
& V_11 -> V_65 ) ;
F_40 ( V_11 -> V_7 , V_10 ,
& V_11 -> V_66 ) ;
F_35 ( V_11 -> V_58 ) ;
return 0 ;
}
static int F_41 ( struct V_64 * V_13 )
{
struct V_11 * V_11 = F_8 ( V_13 ) ;
int V_47 ;
V_47 = F_33 ( V_11 -> V_58 ) ;
if ( V_47 )
return V_47 ;
F_42 ( V_11 -> V_7 , V_35 ,
V_11 -> V_65 ) ;
F_42 ( V_11 -> V_7 , V_10 ,
V_11 -> V_66 ) ;
return 0 ;
}
