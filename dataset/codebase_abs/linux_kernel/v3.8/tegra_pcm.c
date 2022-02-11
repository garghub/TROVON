static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 -> V_7 ;
int V_9 ;
F_2 ( V_2 , & V_10 ) ;
V_9 = F_3 ( V_2 , NULL , NULL ) ;
if ( V_9 ) {
F_4 ( V_7 , L_1 , V_9 ) ;
return V_9 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 -> V_7 ;
struct V_13 * V_14 = F_8 ( V_2 ) ;
struct V_15 * V_16 ;
struct V_17 V_18 ;
int V_9 ;
V_16 = F_9 ( V_4 -> V_19 , V_2 ) ;
V_9 = F_10 ( V_2 , V_12 ,
& V_18 ) ;
if ( V_9 ) {
F_4 ( V_7 , L_2 , V_9 ) ;
return V_9 ;
}
if ( V_2 -> V_20 == V_21 ) {
V_18 . V_22 = V_23 ;
V_18 . V_24 = V_16 -> V_25 ;
V_18 . V_26 = 4 ;
} else {
V_18 . V_27 = V_23 ;
V_18 . V_28 = V_16 -> V_25 ;
V_18 . V_29 = 4 ;
}
V_18 . V_30 = V_16 -> V_31 ;
V_9 = F_11 ( V_14 , & V_18 ) ;
if ( V_9 < 0 ) {
F_4 ( V_7 , L_3 , V_9 ) ;
return V_9 ;
}
F_12 ( V_2 , & V_2 -> V_32 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
F_12 ( V_2 , NULL ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , int V_33 )
{
switch ( V_33 ) {
case V_34 :
case V_35 :
case V_36 :
return F_15 ( V_2 ,
V_34 ) ;
case V_37 :
case V_38 :
case V_39 :
return F_15 ( V_2 ,
V_37 ) ;
default:
return - V_40 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
struct V_43 * V_44 = V_2 -> V_44 ;
return F_17 ( V_2 -> V_45 -> V_46 -> V_7 , V_42 ,
V_44 -> V_47 ,
V_44 -> V_48 ,
V_44 -> V_49 ) ;
}
static int F_18 ( struct V_50 * V_45 , int V_20 )
{
struct V_1 * V_2 = V_45 -> V_51 [ V_20 ] . V_2 ;
struct V_52 * V_53 = & V_2 -> V_32 ;
T_1 V_54 = V_10 . V_55 ;
V_53 -> V_56 = F_19 ( V_45 -> V_46 -> V_7 , V_54 ,
& V_53 -> V_25 , V_57 ) ;
if ( ! V_53 -> V_56 )
return - V_58 ;
V_53 -> V_7 . type = V_59 ;
V_53 -> V_7 . V_7 = V_45 -> V_46 -> V_7 ;
V_53 -> V_5 = NULL ;
V_53 -> V_60 = V_54 ;
return 0 ;
}
static void F_20 ( struct V_50 * V_45 , int V_20 )
{
struct V_1 * V_2 ;
struct V_52 * V_53 ;
V_2 = V_45 -> V_51 [ V_20 ] . V_2 ;
if ( ! V_2 )
return;
V_53 = & V_2 -> V_32 ;
if ( ! V_53 -> V_56 )
return;
F_21 ( V_45 -> V_46 -> V_7 , V_53 -> V_60 ,
V_53 -> V_56 , V_53 -> V_25 ) ;
V_53 -> V_56 = NULL ;
}
static int F_22 ( struct V_3 * V_4 )
{
struct V_61 * V_46 = V_4 -> V_46 -> V_61 ;
struct V_50 * V_45 = V_4 -> V_45 ;
int V_9 = 0 ;
if ( ! V_46 -> V_7 -> V_62 )
V_46 -> V_7 -> V_62 = & V_63 ;
if ( ! V_46 -> V_7 -> V_64 )
V_46 -> V_7 -> V_64 = F_23 ( 32 ) ;
if ( V_45 -> V_51 [ V_21 ] . V_2 ) {
V_9 = F_18 ( V_45 ,
V_21 ) ;
if ( V_9 )
goto V_65;
}
if ( V_45 -> V_51 [ V_66 ] . V_2 ) {
V_9 = F_18 ( V_45 ,
V_66 ) ;
if ( V_9 )
goto V_67;
}
return 0 ;
V_67:
F_20 ( V_45 , V_21 ) ;
V_65:
return V_9 ;
}
static void F_24 ( struct V_50 * V_45 )
{
F_20 ( V_45 , V_66 ) ;
F_20 ( V_45 , V_21 ) ;
}
int F_25 ( struct V_6 * V_7 )
{
return F_26 ( V_7 , & V_68 ) ;
}
void F_27 ( struct V_6 * V_7 )
{
F_28 ( V_7 ) ;
}
