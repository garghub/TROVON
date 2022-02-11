static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) -> V_4 ;
}
static void F_3 ( struct V_2 * V_5 )
{
struct V_6 * V_6 = F_4 ( V_5 ) ;
if ( F_1 ( V_5 ) )
F_1 ( V_5 ) -> F_5 ( V_5 ) ;
F_6 ( V_5 ) ;
F_7 ( V_6 ) ;
}
static void F_8 ( struct V_2 * V_5 )
{
F_9 ( V_5 ) ;
F_10 ( V_5 -> V_7 , & V_8 ) ;
}
static bool F_11 ( struct V_2 * V_5 ,
const struct V_9 * V_10 ,
struct V_9 * V_11 )
{
V_11 -> V_12 = V_10 -> V_13 - V_10 -> V_14 ;
V_11 -> V_15 |= V_16 ;
if ( V_10 -> V_15 & V_17 ) {
V_11 -> V_15 |= V_18 ;
V_11 -> V_15 &= ~ V_17 ;
} else {
V_11 -> V_15 |= V_17 ;
V_11 -> V_15 &= ~ V_18 ;
}
return F_12 ( V_5 , V_10 , V_11 ) ;
}
static struct V_2 * F_13 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_6 * V_6 ;
struct V_2 * V_5 ;
int V_23 ;
V_6 = F_14 ( sizeof( * V_6 ) , V_24 ) ;
if ( ! V_6 ) {
F_15 ( V_20 -> V_20 , L_1 ) ;
return NULL ;
}
V_6 -> V_22 = V_22 ;
V_5 = & V_6 -> V_25 . V_25 ;
V_5 -> V_26 = 1 ;
V_23 = F_16 ( V_20 , V_5 , & V_27 ,
V_28 ) ;
if ( V_23 )
goto V_29;
F_17 ( V_5 , & V_30 ) ;
V_23 = F_18 ( V_20 , F_2 ( V_5 ) , V_22 -> V_31 , & V_32 ) ;
if ( V_23 )
goto V_29;
return V_5 ;
V_29:
F_3 ( V_5 ) ;
return NULL ;
}
static void F_19 ( struct V_33 * V_34 )
{
struct V_35 * V_35 = F_20 ( V_34 ) ;
F_21 ( V_34 ) ;
F_22 ( V_34 ) ;
F_7 ( V_35 ) ;
}
static enum V_36 F_23 (
struct V_33 * V_34 ,
bool V_37 )
{
struct V_2 * V_5 = F_20 ( V_34 ) -> V_5 ;
return F_1 ( V_5 ) -> F_24 ( V_5 , V_34 ) ;
}
static int F_25 ( struct V_33 * V_34 )
{
struct V_2 * V_5 = F_20 ( V_34 ) -> V_5 ;
return F_1 ( V_5 ) -> F_26 ( V_5 , V_34 ) ;
}
static int F_27 ( struct V_33 * V_34 ,
struct V_9 * V_10 )
{
struct V_2 * V_5 = F_20 ( V_34 ) -> V_5 ;
struct V_38 * V_39 = V_34 -> V_20 -> V_40 ;
int V_23 ;
V_23 = F_28 ( V_39 -> V_7 , V_10 ) ;
if ( V_23 != V_41 )
return V_23 ;
return F_1 ( V_5 ) -> F_29 ( V_5 , V_10 ) ;
}
static struct V_2 * F_30 (
struct V_33 * V_34 )
{
struct V_35 * V_35 = F_20 ( V_34 ) ;
return V_35 -> V_5 ;
}
static int F_31 ( struct V_33 * V_34 ,
struct V_42 * V_43 , T_1 V_44 )
{
struct V_2 * V_5 = F_20 ( V_34 ) -> V_5 ;
return F_1 ( V_5 ) -> F_32 ( V_5 ,
V_34 , V_43 , V_44 ) ;
}
static struct V_33 * F_33 ( struct V_19 * V_20 ,
struct V_21 * V_22 , struct V_2 * V_5 )
{
struct V_35 * V_35 ;
struct V_33 * V_34 ;
int V_23 ;
V_35 = F_14 ( sizeof( * V_35 ) , V_24 ) ;
if ( ! V_35 ) {
F_15 ( V_20 -> V_20 , L_1 ) ;
return NULL ;
}
V_35 -> V_5 = V_5 ;
V_35 -> V_22 = V_22 ;
V_34 = & V_35 -> V_25 ;
F_34 ( V_20 , V_34 , & V_45 ,
V_46 ) ;
F_35 ( V_34 , & V_47 ) ;
V_34 -> V_48 = V_49 |
V_50 ;
V_34 -> V_51 = 0 ;
V_34 -> V_52 = 0 ;
F_1 ( V_5 ) -> F_36 ( V_5 , V_34 ) ;
V_23 = F_37 ( V_34 , V_5 ) ;
if ( V_23 )
goto V_29;
F_38 ( V_34 ) ;
return V_34 ;
V_29:
F_19 ( V_34 ) ;
return NULL ;
}
static int F_39 ( struct V_53 * V_22 , struct V_19 * V_20 )
{
struct V_21 * V_54 = F_40 ( V_22 ) ;
struct V_38 * V_39 = V_20 -> V_40 ;
struct V_2 * V_5 ;
struct V_33 * V_34 ;
V_5 = F_13 ( V_20 , V_54 ) ;
if ( ! V_5 )
return - V_55 ;
V_34 = F_33 ( V_20 , V_54 , V_5 ) ;
if ( ! V_34 )
return - V_55 ;
V_39 -> V_56 [ V_39 -> V_57 ++ ] = V_5 ;
V_39 -> V_58 [ V_39 -> V_59 ++ ] = V_34 ;
return 0 ;
}
static int F_41 ( struct V_60 * V_61 )
{
struct V_62 * V_63 = V_61 -> V_20 . V_64 ;
struct V_62 * V_65 ;
struct V_21 * V_54 ;
struct V_53 * V_22 ;
struct V_66 * V_66 ;
T_2 V_67 ;
struct V_68 * V_69 ;
int V_23 = - V_70 ;
if ( ! V_63 ) {
F_15 ( & V_61 -> V_20 , L_2 ) ;
return - V_71 ;
}
if ( F_42 ( V_63 , L_3 , & V_67 ) ) {
F_15 ( & V_61 -> V_20 , L_4 ) ;
return V_23 ;
}
V_65 = F_43 ( V_67 ) ;
if ( ! V_65 ) {
F_15 ( & V_61 -> V_20 , L_5 ) ;
return V_23 ;
}
V_69 = F_44 ( V_65 ) ;
F_45 ( V_65 ) ;
if ( ! V_69 ) {
V_23 = - V_72 ;
F_46 ( true ) ;
F_15 ( & V_61 -> V_20 , L_6 ) ;
return V_23 ;
}
V_54 = F_14 ( sizeof( * V_54 ) , V_24 ) ;
if ( ! V_54 ) {
V_23 = - V_55 ;
goto V_73;
}
V_22 = & V_54 -> V_25 ;
V_61 -> V_20 . V_74 = V_22 ;
V_22 -> V_75 = V_8 . V_76 ;
V_54 -> V_31 = V_69 ;
F_47 ( V_22 , L_7 , & V_77 ) ;
V_66 = F_48 ( & V_61 -> V_20 ) ;
if ( F_49 ( V_66 ) )
F_50 ( & V_61 -> V_20 , L_8 ) ;
F_46 ( false ) ;
return 0 ;
V_73:
F_51 ( V_69 ) ;
return V_23 ;
}
static int F_52 ( struct V_60 * V_61 )
{
struct V_53 * V_22 = F_53 ( & V_61 -> V_20 ) ;
struct V_21 * V_54 = F_40 ( V_22 ) ;
F_54 ( V_22 ) ;
F_7 ( V_54 ) ;
return 0 ;
}
int T_3 F_55 ( void )
{
return F_56 ( & V_78 ) ;
}
void T_4 F_57 ( void )
{
F_58 ( & V_78 ) ;
}
