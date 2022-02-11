static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_8 -> V_9 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_4 ( & V_10 , V_7 -> V_11 ) ;
F_5 ( V_7 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_14 * V_8 = V_7 -> V_8 ;
struct V_15 * V_16 = V_7 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_18 ;
struct V_19 * V_20 = V_18 -> V_20 ;
struct V_21 * V_22 = V_18 -> V_22 ;
if ( F_10 ( V_13 , L_2 , V_22 -> V_23 ) )
return - V_24 ;
if ( F_10 ( V_13 , L_3 , V_20 -> V_25 ) )
return - V_24 ;
if ( F_10 ( V_13 , L_4 , V_18 -> V_26 ) )
return - V_24 ;
if ( F_10 ( V_13 , L_5 ,
V_18 -> V_27 , V_18 -> V_28 ) )
return - V_24 ;
if ( F_10 ( V_13 , L_6 , V_7 -> V_16 -> V_11 ) )
return - V_24 ;
if ( F_10 ( V_13 , L_7 , V_16 -> V_29 ) )
return - V_24 ;
if ( F_10 ( V_13 , L_8 , V_7 -> V_11 ) )
return - V_24 ;
if ( F_10 ( V_13 , L_9 , V_8 -> V_9 ) )
return - V_24 ;
return 0 ;
}
static const struct V_30 *
F_11 ( struct V_6 * V_7 , struct V_31 * V_32 )
{
const struct V_30 * V_11 = V_32 -> V_33 ;
if ( ! V_11 )
return NULL ;
for (; V_11 -> V_9 ; V_11 ++ )
if ( V_11 -> V_9 == V_7 -> V_8 -> V_9 )
return V_11 ;
return NULL ;
}
static int F_12 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
struct V_31 * V_32 = F_13 ( V_35 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
const struct V_30 * V_11 ;
V_11 = F_11 ( V_7 , V_32 ) ;
if ( V_11 )
return 1 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = F_13 ( V_2 -> V_36 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
const struct V_30 * V_11 ;
int V_37 ;
V_11 = F_11 ( V_7 , V_32 ) ;
if ( ! V_11 )
return - V_38 ;
V_37 = F_15 ( V_7 -> V_16 ) ;
if ( V_37 < 0 )
return V_37 ;
F_16 ( V_2 , V_39 ) ;
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
V_37 = V_32 -> V_40 ( V_7 , V_11 ) ;
if ( V_37 ) {
F_21 ( V_2 ) ;
F_22 ( V_2 ) ;
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
}
F_25 ( V_7 -> V_16 ) ;
return V_37 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = F_13 ( V_2 -> V_36 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_32 -> remove ( V_7 ) ;
F_21 ( V_2 ) ;
F_22 ( V_2 ) ;
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
return 0 ;
}
int F_27 ( struct V_31 * V_36 ,
struct V_20 * V_41 , const char * V_42 )
{
int V_43 ;
if ( F_28 () )
return - V_38 ;
V_36 -> V_36 . V_44 = & V_45 ;
V_36 -> V_36 . V_46 = V_36 -> V_46 ;
V_36 -> V_36 . V_41 = V_41 ;
V_36 -> V_36 . V_42 = V_42 ;
V_43 = F_29 ( & V_36 -> V_36 ) ;
if ( V_43 )
return V_43 ;
F_30 ( L_10 , V_36 -> V_46 ) ;
return 0 ;
}
void F_31 ( struct V_31 * V_36 )
{
F_32 ( & V_36 -> V_36 ) ;
}
static struct V_6 * F_33 ( struct V_15 * V_16 ,
struct V_14 * V_8 )
{
struct V_6 * V_7 ;
int V_43 ;
int V_11 ;
V_11 = F_34 ( & V_10 , 1 , 0 , V_47 ) ;
if ( V_11 < 0 )
return F_35 ( V_11 ) ;
V_7 = F_36 ( sizeof( * V_7 ) , V_47 ) ;
if ( ! V_7 ) {
F_4 ( & V_10 , V_11 ) ;
return F_35 ( - V_24 ) ;
}
V_7 -> V_11 = V_11 ;
V_7 -> V_16 = V_16 ;
V_7 -> V_8 = V_8 ;
V_7 -> V_2 . V_48 = & V_16 -> V_2 ;
V_7 -> V_2 . V_44 = & V_45 ;
V_7 -> V_2 . type = & V_49 ;
V_7 -> V_2 . V_50 = V_51 ;
V_7 -> V_2 . V_52 = V_16 -> V_2 . V_52 ;
F_37 ( & V_7 -> V_2 , L_11 , V_11 ) ;
V_43 = F_38 ( & V_7 -> V_2 ) ;
if ( V_43 ) {
F_39 ( & V_7 -> V_2 ) ;
return F_35 ( V_43 ) ;
}
return V_7 ;
}
static void F_40 ( struct V_15 * V_16 )
{
struct V_53 * V_53 = F_41 ( V_16 ) ;
struct V_6 * V_7 , * V_54 ;
int V_37 ;
V_37 = F_15 ( V_16 ) ;
if ( V_37 < 0 )
F_42 ( V_16 ) ;
F_43 (gbphy_dev, temp, &gbphy_host->devices, list) {
F_44 ( & V_7 -> V_55 ) ;
F_45 ( & V_7 -> V_2 ) ;
}
F_5 ( V_53 ) ;
}
static int F_46 ( struct V_15 * V_16 ,
const struct V_56 * V_11 )
{
struct V_53 * V_53 ;
struct V_6 * V_7 ;
int V_57 ;
if ( V_16 -> V_58 == 0 )
return - V_38 ;
V_53 = F_36 ( sizeof( * V_53 ) , V_47 ) ;
if ( ! V_53 )
return - V_24 ;
V_53 -> V_16 = V_16 ;
F_47 ( & V_53 -> V_59 ) ;
F_48 ( V_16 , V_53 ) ;
for ( V_57 = 0 ; V_57 < V_16 -> V_58 ; ++ V_57 ) {
V_7 = F_33 ( V_16 , & V_16 -> V_8 [ V_57 ] ) ;
if ( F_49 ( V_7 ) ) {
F_40 ( V_16 ) ;
return F_50 ( V_7 ) ;
}
F_51 ( & V_7 -> V_55 , & V_53 -> V_59 ) ;
}
F_25 ( V_16 ) ;
return 0 ;
}
static int T_2 F_52 ( void )
{
int V_43 ;
V_43 = F_53 ( & V_45 ) ;
if ( V_43 ) {
F_54 ( L_12 , V_43 ) ;
return V_43 ;
}
V_43 = F_55 ( & V_60 ) ;
if ( V_43 ) {
F_54 ( L_13 ) ;
goto V_61;
}
return 0 ;
V_61:
F_56 ( & V_45 ) ;
F_57 ( & V_10 ) ;
return V_43 ;
}
static void T_3 F_58 ( void )
{
F_59 ( & V_60 ) ;
F_56 ( & V_45 ) ;
F_57 ( & V_10 ) ;
}
