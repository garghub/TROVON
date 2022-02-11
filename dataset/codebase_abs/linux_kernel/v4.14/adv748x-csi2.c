static bool F_1 ( struct V_1 * V_2 )
{
return V_2 == & V_2 -> V_3 -> V_4 ;
}
static int F_2 ( struct V_1 * V_2 ,
unsigned int V_5 )
{
return F_3 ( V_2 , V_6 , V_5 << V_7 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
unsigned int V_12 )
{
int V_13 = V_14 ;
int V_15 ;
V_13 |= V_16 ;
if ( ! V_11 -> V_9 ) {
V_15 = F_5 ( V_9 , V_11 ) ;
if ( V_15 )
return V_15 ;
}
return F_6 ( & V_11 -> V_17 , V_12 ,
& V_2 -> V_18 . V_17 , V_19 ,
V_13 ) ;
}
static int F_7 ( struct V_10 * V_18 )
{
struct V_1 * V_2 = F_8 ( V_18 ) ;
struct V_20 * V_3 = V_2 -> V_3 ;
F_9 ( V_3 , L_1 , F_1 ( V_2 ) ? L_2 : L_3 ,
V_18 -> V_21 ) ;
if ( F_1 ( V_2 ) ) {
return F_4 ( V_2 , V_18 -> V_9 ,
& V_3 -> V_22 . V_18 ,
V_23 ) ;
} else {
return F_4 ( V_2 , V_18 -> V_9 ,
& V_3 -> V_24 . V_18 ,
V_25 ) ;
}
}
static int F_10 ( struct V_10 * V_18 , int V_26 )
{
struct V_1 * V_2 = F_8 ( V_18 ) ;
struct V_10 * V_11 ;
V_11 = F_11 ( & V_2 -> V_27 [ V_19 ] ) ;
if ( ! V_11 )
return - V_28 ;
return F_12 ( V_11 , V_29 , V_30 , V_26 ) ;
}
static struct V_31 *
F_13 ( struct V_10 * V_18 ,
struct V_32 * V_33 ,
unsigned int V_34 , T_1 V_35 )
{
struct V_1 * V_2 = F_8 ( V_18 ) ;
if ( V_35 == V_36 )
return F_14 ( V_18 , V_33 , V_34 ) ;
return & V_2 -> V_37 ;
}
static int F_15 ( struct V_10 * V_18 ,
struct V_32 * V_33 ,
struct V_38 * V_39 )
{
struct V_1 * V_2 = F_8 ( V_18 ) ;
struct V_20 * V_3 = V_2 -> V_3 ;
struct V_31 * V_40 ;
V_40 = F_13 ( V_18 , V_33 , V_39 -> V_34 ,
V_39 -> V_35 ) ;
if ( ! V_40 )
return - V_41 ;
F_16 ( & V_3 -> V_42 ) ;
V_39 -> V_37 = * V_40 ;
F_17 ( & V_3 -> V_42 ) ;
return 0 ;
}
static int F_18 ( struct V_10 * V_18 ,
struct V_32 * V_33 ,
struct V_38 * V_39 )
{
struct V_1 * V_2 = F_8 ( V_18 ) ;
struct V_20 * V_3 = V_2 -> V_3 ;
struct V_31 * V_40 ;
int V_15 = 0 ;
V_40 = F_13 ( V_18 , V_33 , V_39 -> V_34 ,
V_39 -> V_35 ) ;
if ( ! V_40 )
return - V_41 ;
F_16 ( & V_3 -> V_42 ) ;
if ( V_39 -> V_34 == V_43 ) {
const struct V_31 * V_44 ;
V_44 = F_13 ( V_18 , V_33 ,
V_19 ,
V_39 -> V_35 ) ;
if ( ! V_44 ) {
V_15 = - V_41 ;
goto V_45;
}
V_39 -> V_37 = * V_44 ;
}
* V_40 = V_39 -> V_37 ;
V_45:
F_17 ( & V_3 -> V_42 ) ;
return V_15 ;
}
int F_19 ( struct V_10 * V_18 , T_2 V_46 )
{
struct V_47 * V_48 ;
V_48 = F_20 ( V_18 -> V_49 , V_50 ) ;
if ( ! V_48 )
return - V_41 ;
return F_21 ( V_48 , V_46 ) ;
}
static int F_22 ( struct V_47 * V_48 )
{
switch ( V_48 -> V_51 ) {
case V_50 :
return 0 ;
default:
return - V_41 ;
}
}
static int F_23 ( struct V_1 * V_2 )
{
F_24 ( & V_2 -> V_52 , 1 ) ;
F_25 ( & V_2 -> V_52 , & V_53 ,
V_50 , 1 , V_54 , 1 , 1 ) ;
V_2 -> V_18 . V_49 = & V_2 -> V_52 ;
if ( V_2 -> V_52 . error ) {
F_26 ( & V_2 -> V_52 ) ;
return V_2 -> V_52 . error ;
}
return F_27 ( & V_2 -> V_52 ) ;
}
int F_28 ( struct V_20 * V_3 , struct V_1 * V_2 )
{
struct V_55 * V_56 ;
int V_15 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_57 = F_1 ( V_2 ) ? V_58 : V_59 ;
V_56 = V_3 -> V_60 [ F_1 ( V_2 ) ? V_61 : V_62 ] ;
if ( ! V_56 ) {
F_29 ( V_3 , L_4 ,
F_1 ( V_2 ) ? L_5 : L_6 ) ;
return - V_63 ;
}
F_2 ( V_2 , 0 ) ;
F_30 ( & V_2 -> V_18 , V_3 , & V_64 ,
V_65 ,
F_1 ( V_2 ) ? L_5 : L_6 ) ;
V_2 -> V_18 . V_66 = F_31 ( V_56 ) ;
V_2 -> V_18 . V_67 = & V_68 ;
V_2 -> V_27 [ V_19 ] . V_69 = V_70 ;
V_2 -> V_27 [ V_43 ] . V_69 = V_71 ;
V_15 = F_32 ( & V_2 -> V_18 . V_17 , V_72 ,
V_2 -> V_27 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_23 ( V_2 ) ;
if ( V_15 )
goto V_73;
V_15 = F_33 ( & V_2 -> V_18 ) ;
if ( V_15 )
goto V_74;
return 0 ;
V_74:
F_26 ( & V_2 -> V_52 ) ;
V_73:
F_34 ( & V_2 -> V_18 . V_17 ) ;
return V_15 ;
}
void F_35 ( struct V_1 * V_2 )
{
F_36 ( & V_2 -> V_18 ) ;
F_34 ( & V_2 -> V_18 . V_17 ) ;
F_26 ( & V_2 -> V_52 ) ;
}
