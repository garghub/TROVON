static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
}
static T_1 void F_3 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_3 ) ;
}
static T_1 void F_5 ( struct V_1 * V_2 )
{
if ( F_6 ( & V_2 -> V_3 ) )
F_1 ( V_2 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 . V_5 ) {
F_8 ( & V_2 -> V_4 ) ;
F_5 ( V_2 ) ;
}
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_4 , & V_6 ) ;
F_3 ( V_2 ) ;
}
static struct V_1 * F_11 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 , * V_11 = NULL ;
F_12 (entry, &lapb_list) {
V_2 = F_13 ( V_10 , struct V_1 , V_4 ) ;
if ( V_2 -> V_8 == V_8 ) {
V_11 = V_2 ;
break;
}
}
if ( V_11 )
F_3 ( V_11 ) ;
return V_11 ;
}
static struct V_1 * F_14 ( struct V_7 * V_8 )
{
struct V_1 * V_12 ;
F_15 ( & V_13 ) ;
V_12 = F_11 ( V_8 ) ;
F_16 ( & V_13 ) ;
return V_12 ;
}
static struct V_1 * F_17 ( void )
{
struct V_1 * V_2 = F_18 ( sizeof( * V_2 ) , V_14 ) ;
if ( ! V_2 )
goto V_15;
F_19 ( & V_2 -> V_16 ) ;
F_19 ( & V_2 -> V_17 ) ;
F_20 ( & V_2 -> V_18 ) ;
F_20 ( & V_2 -> V_19 ) ;
V_2 -> V_20 = V_21 ;
V_2 -> V_22 = V_23 ;
V_2 -> V_24 = V_25 ;
V_2 -> V_26 = V_27 ;
V_2 -> V_28 = V_29 ;
V_2 -> V_30 = V_31 ;
F_21 ( & V_2 -> V_3 , 1 ) ;
V_15:
return V_2 ;
}
int F_22 ( struct V_7 * V_8 ,
const struct V_32 * V_33 )
{
struct V_1 * V_2 ;
int V_12 = V_34 ;
F_23 ( & V_13 ) ;
V_2 = F_11 ( V_8 ) ;
if ( V_2 ) {
F_5 ( V_2 ) ;
goto V_15;
}
V_2 = F_17 () ;
V_12 = V_35 ;
if ( ! V_2 )
goto V_15;
V_2 -> V_8 = V_8 ;
V_2 -> V_33 = V_33 ;
F_9 ( V_2 ) ;
F_24 ( V_2 ) ;
V_12 = V_36 ;
V_15:
F_25 ( & V_13 ) ;
return V_12 ;
}
int F_26 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_12 = V_34 ;
F_23 ( & V_13 ) ;
V_2 = F_11 ( V_8 ) ;
if ( ! V_2 )
goto V_15;
F_27 ( V_2 ) ;
F_28 ( V_2 ) ;
F_29 ( V_2 ) ;
F_7 ( V_2 ) ;
F_5 ( V_2 ) ;
V_12 = V_36 ;
V_15:
F_25 ( & V_13 ) ;
return V_12 ;
}
int F_30 ( struct V_7 * V_8 , struct V_37 * V_38 )
{
int V_12 = V_34 ;
struct V_1 * V_2 = F_14 ( V_8 ) ;
if ( ! V_2 )
goto V_15;
V_38 -> V_20 = V_2 -> V_20 / V_39 ;
V_38 -> V_22 = V_2 -> V_22 / V_39 ;
V_38 -> V_24 = V_2 -> V_24 ;
V_38 -> V_40 = V_2 -> V_40 ;
V_38 -> V_30 = V_2 -> V_30 ;
V_38 -> V_28 = V_2 -> V_28 ;
V_38 -> V_26 = V_2 -> V_26 ;
if ( ! F_31 ( & V_2 -> V_18 ) )
V_38 -> V_18 = 0 ;
else
V_38 -> V_18 = ( V_2 -> V_18 . V_41 - V_42 ) / V_39 ;
if ( ! F_31 ( & V_2 -> V_19 ) )
V_38 -> V_19 = 0 ;
else
V_38 -> V_19 = ( V_2 -> V_19 . V_41 - V_42 ) / V_39 ;
F_5 ( V_2 ) ;
V_12 = V_36 ;
V_15:
return V_12 ;
}
int F_32 ( struct V_7 * V_8 , struct V_37 * V_38 )
{
int V_12 = V_34 ;
struct V_1 * V_2 = F_14 ( V_8 ) ;
if ( ! V_2 )
goto V_15;
V_12 = V_43 ;
if ( V_38 -> V_20 < 1 || V_38 -> V_22 < 1 || V_38 -> V_24 < 1 )
goto V_44;
if ( V_2 -> V_30 == V_31 ) {
if ( V_38 -> V_26 & V_45 ) {
if ( V_38 -> V_28 < 1 || V_38 -> V_28 > 127 )
goto V_44;
} else {
if ( V_38 -> V_28 < 1 || V_38 -> V_28 > 7 )
goto V_44;
}
V_2 -> V_26 = V_38 -> V_26 ;
V_2 -> V_28 = V_38 -> V_28 ;
}
V_2 -> V_20 = V_38 -> V_20 * V_39 ;
V_2 -> V_22 = V_38 -> V_22 * V_39 ;
V_2 -> V_24 = V_38 -> V_24 ;
V_12 = V_36 ;
V_44:
F_5 ( V_2 ) ;
V_15:
return V_12 ;
}
int F_33 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_14 ( V_8 ) ;
int V_12 = V_34 ;
if ( ! V_2 )
goto V_15;
V_12 = V_36 ;
if ( V_2 -> V_30 == V_46 )
goto V_44;
V_12 = V_47 ;
if ( V_2 -> V_30 == V_48 || V_2 -> V_30 == V_49 )
goto V_44;
F_34 ( V_2 ) ;
F_35 ( 0 , L_1 , V_2 -> V_8 ) ;
V_2 -> V_30 = V_46 ;
V_12 = V_36 ;
V_44:
F_5 ( V_2 ) ;
V_15:
return V_12 ;
}
int F_36 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_14 ( V_8 ) ;
int V_12 = V_34 ;
if ( ! V_2 )
goto V_15;
switch ( V_2 -> V_30 ) {
case V_31 :
V_12 = V_50 ;
goto V_44;
case V_46 :
F_35 ( 1 , L_2 , V_2 -> V_8 ) ;
F_35 ( 0 , L_3 , V_2 -> V_8 ) ;
F_37 ( V_2 , V_51 , V_52 , V_53 ) ;
V_2 -> V_30 = V_31 ;
F_24 ( V_2 ) ;
V_12 = V_50 ;
goto V_44;
case V_54 :
V_12 = V_36 ;
goto V_44;
}
F_29 ( V_2 ) ;
V_2 -> V_40 = 0 ;
F_37 ( V_2 , V_51 , V_52 , V_53 ) ;
F_24 ( V_2 ) ;
F_28 ( V_2 ) ;
V_2 -> V_30 = V_54 ;
F_35 ( 1 , L_4 , V_2 -> V_8 ) ;
F_35 ( 0 , L_5 , V_2 -> V_8 ) ;
V_12 = V_36 ;
V_44:
F_5 ( V_2 ) ;
V_15:
return V_12 ;
}
int F_38 ( struct V_7 * V_8 , struct V_55 * V_56 )
{
struct V_1 * V_2 = F_14 ( V_8 ) ;
int V_12 = V_34 ;
if ( ! V_2 )
goto V_15;
V_12 = V_50 ;
if ( V_2 -> V_30 != V_48 && V_2 -> V_30 != V_49 )
goto V_44;
F_39 ( & V_2 -> V_16 , V_56 ) ;
F_40 ( V_2 ) ;
V_12 = V_36 ;
V_44:
F_5 ( V_2 ) ;
V_15:
return V_12 ;
}
int F_41 ( struct V_7 * V_8 , struct V_55 * V_56 )
{
struct V_1 * V_2 = F_14 ( V_8 ) ;
int V_12 = V_34 ;
if ( V_2 ) {
F_42 ( V_2 , V_56 ) ;
F_5 ( V_2 ) ;
V_12 = V_36 ;
}
return V_12 ;
}
void F_43 ( struct V_1 * V_2 , int V_57 )
{
if ( V_2 -> V_33 -> V_58 )
V_2 -> V_33 -> V_58 ( V_2 -> V_8 , V_57 ) ;
}
void F_44 ( struct V_1 * V_2 , int V_57 )
{
if ( V_2 -> V_33 -> V_59 )
V_2 -> V_33 -> V_59 ( V_2 -> V_8 , V_57 ) ;
}
void F_45 ( struct V_1 * V_2 , int V_57 )
{
if ( V_2 -> V_33 -> V_60 )
V_2 -> V_33 -> V_60 ( V_2 -> V_8 , V_57 ) ;
}
void F_46 ( struct V_1 * V_2 , int V_57 )
{
if ( V_2 -> V_33 -> V_61 )
V_2 -> V_33 -> V_61 ( V_2 -> V_8 , V_57 ) ;
}
int F_47 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
if ( V_2 -> V_33 -> V_62 )
return V_2 -> V_33 -> V_62 ( V_2 -> V_8 , V_56 ) ;
F_48 ( V_56 ) ;
return V_63 ;
}
int F_49 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
int V_64 = 0 ;
if ( V_2 -> V_33 -> V_65 ) {
V_2 -> V_33 -> V_65 ( V_2 -> V_8 , V_56 ) ;
V_64 = 1 ;
}
return V_64 ;
}
static int T_2 F_50 ( void )
{
return 0 ;
}
static void T_3 F_51 ( void )
{
F_52 ( ! F_53 ( & V_6 ) ) ;
}
