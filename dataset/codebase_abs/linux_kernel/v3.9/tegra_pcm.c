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
static int F_14 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_35 * V_36 = V_2 -> V_36 ;
return F_15 ( V_2 -> V_37 -> V_38 -> V_7 , V_34 ,
V_36 -> V_39 ,
V_36 -> V_40 ,
V_36 -> V_41 ) ;
}
static int F_16 ( struct V_42 * V_37 , int V_20 )
{
struct V_1 * V_2 = V_37 -> V_43 [ V_20 ] . V_2 ;
struct V_44 * V_45 = & V_2 -> V_32 ;
T_1 V_46 = V_10 . V_47 ;
V_45 -> V_48 = F_17 ( V_37 -> V_38 -> V_7 , V_46 ,
& V_45 -> V_25 , V_49 ) ;
if ( ! V_45 -> V_48 )
return - V_50 ;
V_45 -> V_7 . type = V_51 ;
V_45 -> V_7 . V_7 = V_37 -> V_38 -> V_7 ;
V_45 -> V_5 = NULL ;
V_45 -> V_52 = V_46 ;
return 0 ;
}
static void F_18 ( struct V_42 * V_37 , int V_20 )
{
struct V_1 * V_2 ;
struct V_44 * V_45 ;
V_2 = V_37 -> V_43 [ V_20 ] . V_2 ;
if ( ! V_2 )
return;
V_45 = & V_2 -> V_32 ;
if ( ! V_45 -> V_48 )
return;
F_19 ( V_37 -> V_38 -> V_7 , V_45 -> V_52 ,
V_45 -> V_48 , V_45 -> V_25 ) ;
V_45 -> V_48 = NULL ;
}
static int F_20 ( struct V_3 * V_4 )
{
struct V_53 * V_38 = V_4 -> V_38 -> V_53 ;
struct V_42 * V_37 = V_4 -> V_37 ;
int V_9 = 0 ;
if ( ! V_38 -> V_7 -> V_54 )
V_38 -> V_7 -> V_54 = & V_55 ;
if ( ! V_38 -> V_7 -> V_56 )
V_38 -> V_7 -> V_56 = F_21 ( 32 ) ;
if ( V_37 -> V_43 [ V_21 ] . V_2 ) {
V_9 = F_16 ( V_37 ,
V_21 ) ;
if ( V_9 )
goto V_57;
}
if ( V_37 -> V_43 [ V_58 ] . V_2 ) {
V_9 = F_16 ( V_37 ,
V_58 ) ;
if ( V_9 )
goto V_59;
}
return 0 ;
V_59:
F_18 ( V_37 , V_21 ) ;
V_57:
return V_9 ;
}
static void F_22 ( struct V_42 * V_37 )
{
F_18 ( V_37 , V_58 ) ;
F_18 ( V_37 , V_21 ) ;
}
int F_23 ( struct V_6 * V_7 )
{
return F_24 ( V_7 , & V_60 ) ;
}
void F_25 ( struct V_6 * V_7 )
{
F_26 ( V_7 ) ;
}
