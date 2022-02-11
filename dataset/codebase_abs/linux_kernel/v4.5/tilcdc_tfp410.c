static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_3 ( V_2 ) ;
F_4 ( V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_4 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_3 -> V_5 == V_4 )
return;
if ( V_4 == V_6 ) {
F_6 ( L_1 ) ;
F_7 ( V_3 -> V_7 -> V_8 , 1 ) ;
} else {
F_6 ( L_2 ) ;
F_7 ( V_3 -> V_7 -> V_8 , 0 ) ;
}
V_3 -> V_5 = V_4 ;
}
static bool F_8 ( struct V_1 * V_2 ,
const struct V_9 * V_4 ,
struct V_9 * V_10 )
{
return true ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_11 ) ;
F_10 ( V_2 -> V_12 , & V_13 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_6 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_9 * V_4 ,
struct V_9 * V_10 )
{
}
static struct V_1 * F_13 ( struct V_14 * V_15 ,
struct V_16 * V_7 )
{
struct V_3 * V_3 ;
struct V_1 * V_2 ;
int V_17 ;
V_3 = F_14 ( sizeof( * V_3 ) , V_18 ) ;
if ( ! V_3 ) {
F_15 ( V_15 -> V_15 , L_3 ) ;
return NULL ;
}
V_3 -> V_5 = V_11 ;
V_3 -> V_7 = V_7 ;
V_2 = & V_3 -> V_19 ;
V_2 -> V_20 = 1 ;
V_17 = F_16 ( V_15 , V_2 , & V_21 ,
V_22 , NULL ) ;
if ( V_17 < 0 )
goto V_23;
F_17 ( V_2 , & V_24 ) ;
return V_2 ;
V_23:
F_1 ( V_2 ) ;
return NULL ;
}
static void F_18 ( struct V_25 * V_26 )
{
struct V_27 * V_27 = F_19 ( V_26 ) ;
F_20 ( V_26 ) ;
F_21 ( V_26 ) ;
F_4 ( V_27 ) ;
}
static enum V_28 F_22 (
struct V_25 * V_26 ,
bool V_29 )
{
struct V_27 * V_27 = F_19 ( V_26 ) ;
if ( F_23 ( V_27 -> V_7 -> V_30 ) )
return V_31 ;
return V_32 ;
}
static int F_24 ( struct V_25 * V_26 )
{
struct V_27 * V_27 = F_19 ( V_26 ) ;
struct V_33 * V_33 ;
int V_17 = 0 ;
V_33 = F_25 ( V_26 , V_27 -> V_7 -> V_30 ) ;
F_26 ( V_26 , V_33 ) ;
if ( V_33 ) {
V_17 = F_27 ( V_26 , V_33 ) ;
F_4 ( V_33 ) ;
}
return V_17 ;
}
static int F_28 ( struct V_25 * V_26 ,
struct V_9 * V_4 )
{
struct V_34 * V_35 = V_26 -> V_15 -> V_36 ;
return F_29 ( V_35 -> V_12 , V_4 ) ;
}
static struct V_1 * F_30 (
struct V_25 * V_26 )
{
struct V_27 * V_27 = F_19 ( V_26 ) ;
return V_27 -> V_2 ;
}
static struct V_25 * F_31 ( struct V_14 * V_15 ,
struct V_16 * V_7 , struct V_1 * V_2 )
{
struct V_27 * V_27 ;
struct V_25 * V_26 ;
int V_17 ;
V_27 = F_14 ( sizeof( * V_27 ) , V_18 ) ;
if ( ! V_27 ) {
F_15 ( V_15 -> V_15 , L_3 ) ;
return NULL ;
}
V_27 -> V_2 = V_2 ;
V_27 -> V_7 = V_7 ;
V_26 = & V_27 -> V_19 ;
F_32 ( V_15 , V_26 , & V_37 ,
V_38 ) ;
F_33 ( V_26 , & V_39 ) ;
V_26 -> V_40 = V_41 |
V_42 ;
V_26 -> V_43 = 0 ;
V_26 -> V_44 = 0 ;
V_17 = F_34 ( V_26 , V_2 ) ;
if ( V_17 )
goto V_23;
F_35 ( V_26 ) ;
return V_26 ;
V_23:
F_18 ( V_26 ) ;
return NULL ;
}
static int F_36 ( struct V_45 * V_7 , struct V_14 * V_15 )
{
struct V_16 * V_46 = F_37 ( V_7 ) ;
struct V_34 * V_35 = V_15 -> V_36 ;
struct V_1 * V_2 ;
struct V_25 * V_26 ;
V_2 = F_13 ( V_15 , V_46 ) ;
if ( ! V_2 )
return - V_47 ;
V_26 = F_31 ( V_15 , V_46 , V_2 ) ;
if ( ! V_26 )
return - V_47 ;
V_35 -> V_48 [ V_35 -> V_49 ++ ] = V_2 ;
V_35 -> V_50 [ V_35 -> V_51 ++ ] = V_26 ;
return 0 ;
}
static int F_38 ( struct V_52 * V_53 )
{
struct V_54 * V_55 = V_53 -> V_15 . V_56 ;
struct V_54 * V_57 ;
struct V_16 * V_46 ;
struct V_45 * V_7 ;
struct V_58 * V_58 ;
T_1 V_59 ;
int V_17 = - V_60 ;
if ( ! V_55 ) {
F_15 ( & V_53 -> V_15 , L_4 ) ;
return - V_61 ;
}
V_46 = F_14 ( sizeof( * V_46 ) , V_18 ) ;
if ( ! V_46 )
return - V_47 ;
V_7 = & V_46 -> V_19 ;
V_53 -> V_15 . V_62 = V_7 ;
F_39 ( V_7 , L_5 , & V_63 ) ;
V_58 = F_40 ( & V_53 -> V_15 ) ;
if ( F_41 ( V_58 ) )
F_42 ( & V_53 -> V_15 , L_6 ) ;
if ( F_43 ( V_55 , L_7 , & V_59 ) ) {
F_15 ( & V_53 -> V_15 , L_8 ) ;
goto V_23;
}
V_7 -> V_64 = V_13 . V_65 ;
V_57 = F_44 ( V_59 ) ;
if ( ! V_57 ) {
F_15 ( & V_53 -> V_15 , L_9 ) ;
goto V_23;
}
V_46 -> V_30 = F_45 ( V_57 ) ;
if ( ! V_46 -> V_30 ) {
F_15 ( & V_53 -> V_15 , L_10 ) ;
F_46 ( V_57 ) ;
goto V_23;
}
F_46 ( V_57 ) ;
V_46 -> V_8 = F_47 ( V_55 , L_11 ,
0 , NULL ) ;
if ( F_48 ( V_46 -> V_8 ) ) {
F_42 ( & V_53 -> V_15 , L_12 ) ;
} else {
V_17 = F_49 ( V_46 -> V_8 , L_13 ) ;
if ( V_17 ) {
F_15 ( & V_53 -> V_15 , L_14 ) ;
goto V_66;
}
}
return 0 ;
V_66:
F_50 ( V_46 -> V_30 ) ;
V_23:
F_4 ( V_46 ) ;
F_51 ( V_7 ) ;
return V_17 ;
}
static int F_52 ( struct V_52 * V_53 )
{
struct V_45 * V_7 = F_53 ( & V_53 -> V_15 ) ;
struct V_16 * V_46 = F_37 ( V_7 ) ;
F_50 ( V_46 -> V_30 ) ;
F_54 ( V_46 -> V_8 ) ;
F_51 ( V_7 ) ;
F_4 ( V_46 ) ;
return 0 ;
}
int T_2 F_55 ( void )
{
return F_56 ( & V_67 ) ;
}
void T_3 F_57 ( void )
{
F_58 ( & V_67 ) ;
}
