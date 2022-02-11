static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 == V_3 )
return;
if ( V_3 == V_6 ) {
F_3 ( L_1 ) ;
F_4 ( V_4 -> V_7 -> V_8 , 1 ) ;
} else {
F_3 ( L_2 ) ;
F_4 ( V_4 -> V_7 -> V_8 , 0 ) ;
}
V_4 -> V_5 = V_3 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_9 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_6 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_10 * V_3 ,
struct V_10 * V_11 )
{
}
static struct V_1 * F_8 ( struct V_12 * V_13 ,
struct V_14 * V_7 )
{
struct V_4 * V_4 ;
struct V_1 * V_2 ;
int V_15 ;
V_4 = F_9 ( V_13 -> V_13 , sizeof( * V_4 ) ,
V_16 ) ;
if ( ! V_4 ) {
F_10 ( V_13 -> V_13 , L_3 ) ;
return NULL ;
}
V_4 -> V_5 = V_9 ;
V_4 -> V_7 = V_7 ;
V_2 = & V_4 -> V_17 ;
V_2 -> V_18 = 1 ;
V_15 = F_11 ( V_13 , V_2 , & V_19 ,
V_20 , NULL ) ;
if ( V_15 < 0 )
goto V_21;
F_12 ( V_2 , & V_22 ) ;
return V_2 ;
V_21:
F_13 ( V_2 ) ;
return NULL ;
}
static void F_14 ( struct V_23 * V_24 )
{
F_15 ( V_24 ) ;
F_16 ( V_24 ) ;
}
static enum V_25 F_17 (
struct V_23 * V_24 ,
bool V_26 )
{
struct V_27 * V_27 = F_18 ( V_24 ) ;
if ( F_19 ( V_27 -> V_7 -> V_28 ) )
return V_29 ;
return V_30 ;
}
static int F_20 ( struct V_23 * V_24 )
{
struct V_27 * V_27 = F_18 ( V_24 ) ;
struct V_31 * V_31 ;
int V_15 = 0 ;
V_31 = F_21 ( V_24 , V_27 -> V_7 -> V_28 ) ;
F_22 ( V_24 , V_31 ) ;
if ( V_31 ) {
V_15 = F_23 ( V_24 , V_31 ) ;
F_24 ( V_31 ) ;
}
return V_15 ;
}
static int F_25 ( struct V_23 * V_24 ,
struct V_10 * V_3 )
{
struct V_32 * V_33 = V_24 -> V_13 -> V_34 ;
return F_26 ( V_33 -> V_35 , V_3 ) ;
}
static struct V_1 * F_27 (
struct V_23 * V_24 )
{
struct V_27 * V_27 = F_18 ( V_24 ) ;
return V_27 -> V_2 ;
}
static struct V_23 * F_28 ( struct V_12 * V_13 ,
struct V_14 * V_7 , struct V_1 * V_2 )
{
struct V_27 * V_27 ;
struct V_23 * V_24 ;
int V_15 ;
V_27 = F_9 ( V_13 -> V_13 , sizeof( * V_27 ) ,
V_16 ) ;
if ( ! V_27 ) {
F_10 ( V_13 -> V_13 , L_3 ) ;
return NULL ;
}
V_27 -> V_2 = V_2 ;
V_27 -> V_7 = V_7 ;
V_24 = & V_27 -> V_17 ;
F_29 ( V_13 , V_24 , & V_36 ,
V_37 ) ;
F_30 ( V_24 , & V_38 ) ;
V_24 -> V_39 = V_40 |
V_41 ;
V_24 -> V_42 = 0 ;
V_24 -> V_43 = 0 ;
V_15 = F_31 ( V_24 , V_2 ) ;
if ( V_15 )
goto V_21;
F_32 ( V_24 ) ;
return V_24 ;
V_21:
F_14 ( V_24 ) ;
return NULL ;
}
static int F_33 ( struct V_44 * V_7 , struct V_12 * V_13 )
{
struct V_14 * V_45 = F_34 ( V_7 ) ;
struct V_32 * V_33 = V_13 -> V_34 ;
struct V_1 * V_2 ;
struct V_23 * V_24 ;
V_2 = F_8 ( V_13 , V_45 ) ;
if ( ! V_2 )
return - V_46 ;
V_24 = F_28 ( V_13 , V_45 , V_2 ) ;
if ( ! V_24 )
return - V_46 ;
V_33 -> V_47 [ V_33 -> V_48 ++ ] = V_2 ;
V_33 -> V_49 [ V_33 -> V_50 ++ ] = V_24 ;
F_35 ( V_33 -> V_35 , & V_51 ) ;
return 0 ;
}
static int F_36 ( struct V_52 * V_53 )
{
struct V_54 * V_55 = V_53 -> V_13 . V_56 ;
struct V_54 * V_57 ;
struct V_14 * V_45 ;
struct V_44 * V_7 ;
struct V_58 * V_58 ;
T_1 V_59 ;
int V_15 = - V_60 ;
if ( ! V_55 ) {
F_10 ( & V_53 -> V_13 , L_4 ) ;
return - V_61 ;
}
V_45 = F_9 ( & V_53 -> V_13 , sizeof( * V_45 ) , V_16 ) ;
if ( ! V_45 )
return - V_46 ;
V_7 = & V_45 -> V_17 ;
V_53 -> V_13 . V_62 = V_7 ;
F_37 ( V_7 , L_5 , & V_63 ) ;
V_58 = F_38 ( & V_53 -> V_13 ) ;
if ( F_39 ( V_58 ) )
F_40 ( & V_53 -> V_13 , L_6 ) ;
if ( F_41 ( V_55 , L_7 , & V_59 ) ) {
F_10 ( & V_53 -> V_13 , L_8 ) ;
goto V_21;
}
V_57 = F_42 ( V_59 ) ;
if ( ! V_57 ) {
F_10 ( & V_53 -> V_13 , L_9 ) ;
goto V_21;
}
V_45 -> V_28 = F_43 ( V_57 ) ;
if ( ! V_45 -> V_28 ) {
F_10 ( & V_53 -> V_13 , L_10 ) ;
F_44 ( V_57 ) ;
goto V_21;
}
F_44 ( V_57 ) ;
V_45 -> V_8 = F_45 ( V_55 , L_11 ,
0 , NULL ) ;
if ( V_45 -> V_8 < 0 ) {
F_40 ( & V_53 -> V_13 , L_12 ) ;
} else {
V_15 = F_46 ( V_45 -> V_8 , L_13 ) ;
if ( V_15 ) {
F_10 ( & V_53 -> V_13 , L_14 ) ;
goto V_64;
}
}
return 0 ;
V_64:
F_47 ( V_45 -> V_28 ) ;
V_21:
F_48 ( V_7 ) ;
return V_15 ;
}
static int F_49 ( struct V_52 * V_53 )
{
struct V_44 * V_7 = F_50 ( & V_53 -> V_13 ) ;
struct V_14 * V_45 = F_34 ( V_7 ) ;
F_47 ( V_45 -> V_28 ) ;
F_51 ( V_45 -> V_8 ) ;
F_48 ( V_7 ) ;
return 0 ;
}
int T_2 F_52 ( void )
{
return F_53 ( & V_65 ) ;
}
void T_3 F_54 ( void )
{
F_55 ( & V_65 ) ;
}
