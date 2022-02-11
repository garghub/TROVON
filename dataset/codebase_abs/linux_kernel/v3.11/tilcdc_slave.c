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
static struct V_2 * F_11 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_6 * V_6 ;
struct V_2 * V_5 ;
int V_13 ;
V_6 = F_12 ( sizeof( * V_6 ) , V_14 ) ;
if ( ! V_6 ) {
F_13 ( V_10 -> V_10 , L_1 ) ;
return NULL ;
}
V_6 -> V_12 = V_12 ;
V_5 = & V_6 -> V_15 . V_15 ;
V_5 -> V_16 = 1 ;
V_13 = F_14 ( V_10 , V_5 , & V_17 ,
V_18 ) ;
if ( V_13 )
goto V_19;
F_15 ( V_5 , & V_20 ) ;
V_13 = F_16 ( V_10 , F_2 ( V_5 ) , V_12 -> V_21 , & V_22 ) ;
if ( V_13 )
goto V_19;
return V_5 ;
V_19:
F_3 ( V_5 ) ;
return NULL ;
}
static void F_17 ( struct V_23 * V_24 )
{
struct V_25 * V_25 = F_18 ( V_24 ) ;
F_19 ( V_24 ) ;
F_7 ( V_25 ) ;
}
static enum V_26 F_20 (
struct V_23 * V_24 ,
bool V_27 )
{
struct V_2 * V_5 = F_18 ( V_24 ) -> V_5 ;
return F_1 ( V_5 ) -> F_21 ( V_5 , V_24 ) ;
}
static int F_22 ( struct V_23 * V_24 )
{
struct V_2 * V_5 = F_18 ( V_24 ) -> V_5 ;
return F_1 ( V_5 ) -> F_23 ( V_5 , V_24 ) ;
}
static int F_24 ( struct V_23 * V_24 ,
struct V_28 * V_29 )
{
struct V_2 * V_5 = F_18 ( V_24 ) -> V_5 ;
struct V_30 * V_31 = V_24 -> V_10 -> V_32 ;
int V_13 ;
V_13 = F_25 ( V_31 -> V_7 , V_29 ) ;
if ( V_13 != V_33 )
return V_13 ;
return F_1 ( V_5 ) -> F_26 ( V_5 , V_29 ) ;
}
static struct V_2 * F_27 (
struct V_23 * V_24 )
{
struct V_25 * V_25 = F_18 ( V_24 ) ;
return V_25 -> V_5 ;
}
static int F_28 ( struct V_23 * V_24 ,
struct V_34 * V_35 , T_1 V_36 )
{
struct V_2 * V_5 = F_18 ( V_24 ) -> V_5 ;
return F_1 ( V_5 ) -> F_29 ( V_5 ,
V_24 , V_35 , V_36 ) ;
}
static struct V_23 * F_30 ( struct V_9 * V_10 ,
struct V_11 * V_12 , struct V_2 * V_5 )
{
struct V_25 * V_25 ;
struct V_23 * V_24 ;
int V_13 ;
V_25 = F_12 ( sizeof( * V_25 ) , V_14 ) ;
if ( ! V_25 ) {
F_13 ( V_10 -> V_10 , L_1 ) ;
return NULL ;
}
V_25 -> V_5 = V_5 ;
V_25 -> V_12 = V_12 ;
V_24 = & V_25 -> V_15 ;
F_31 ( V_10 , V_24 , & V_37 ,
V_38 ) ;
F_32 ( V_24 , & V_39 ) ;
V_24 -> V_40 = V_41 |
V_42 ;
V_24 -> V_43 = 0 ;
V_24 -> V_44 = 0 ;
F_1 ( V_5 ) -> F_33 ( V_5 , V_24 ) ;
V_13 = F_34 ( V_24 , V_5 ) ;
if ( V_13 )
goto V_19;
F_35 ( V_24 ) ;
return V_24 ;
V_19:
F_17 ( V_24 ) ;
return NULL ;
}
static int F_36 ( struct V_45 * V_12 , struct V_9 * V_10 )
{
struct V_11 * V_46 = F_37 ( V_12 ) ;
struct V_30 * V_31 = V_10 -> V_32 ;
struct V_2 * V_5 ;
struct V_23 * V_24 ;
V_5 = F_11 ( V_10 , V_46 ) ;
if ( ! V_5 )
return - V_47 ;
V_24 = F_30 ( V_10 , V_46 , V_5 ) ;
if ( ! V_24 )
return - V_47 ;
V_31 -> V_48 [ V_31 -> V_49 ++ ] = V_5 ;
V_31 -> V_50 [ V_31 -> V_51 ++ ] = V_24 ;
return 0 ;
}
static void F_38 ( struct V_45 * V_12 )
{
struct V_11 * V_46 = F_37 ( V_12 ) ;
F_39 ( V_12 ) ;
F_7 ( V_46 ) ;
}
static int F_40 ( struct V_52 * V_53 )
{
struct V_54 * V_55 = V_53 -> V_10 . V_56 ;
struct V_54 * V_57 ;
struct V_11 * V_46 ;
struct V_45 * V_12 ;
struct V_58 * V_58 ;
T_2 V_59 ;
struct V_60 * V_61 ;
int V_13 = - V_62 ;
if ( ! V_55 ) {
F_13 ( & V_53 -> V_10 , L_2 ) ;
return - V_63 ;
}
if ( F_41 ( V_55 , L_3 , & V_59 ) ) {
F_13 ( & V_53 -> V_10 , L_4 ) ;
return V_13 ;
}
V_57 = F_42 ( V_59 ) ;
if ( ! V_57 ) {
F_13 ( & V_53 -> V_10 , L_5 ) ;
return V_13 ;
}
V_61 = F_43 ( V_57 ) ;
F_44 ( V_57 ) ;
if ( ! V_61 ) {
V_13 = - V_64 ;
F_45 ( true ) ;
F_13 ( & V_53 -> V_10 , L_6 ) ;
return V_13 ;
}
V_46 = F_12 ( sizeof( * V_46 ) , V_14 ) ;
if ( ! V_46 )
return - V_47 ;
V_12 = & V_46 -> V_15 ;
V_12 -> V_65 = V_8 . V_66 ;
V_46 -> V_21 = V_61 ;
F_46 ( V_12 , L_7 , & V_67 ) ;
V_58 = F_47 ( & V_53 -> V_10 ) ;
if ( F_48 ( V_58 ) )
F_49 ( & V_53 -> V_10 , L_8 ) ;
F_45 ( false ) ;
return 0 ;
}
static int F_50 ( struct V_52 * V_53 )
{
return 0 ;
}
int T_3 F_51 ( void )
{
return F_52 ( & V_68 ) ;
}
void T_4 F_53 ( void )
{
F_54 ( & V_68 ) ;
}
