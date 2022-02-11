static int F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
int V_7 ;
V_7 = V_6 -> V_8 . V_9 -> V_10 ( V_6 , V_2 ) ;
if ( V_7 )
return V_7 ;
V_3 -> V_11 = V_2 ;
V_2 -> V_3 = V_3 ;
F_3 ( V_5 -> V_12 , 1 ) ;
F_4 ( 300 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
F_6 ( V_3 != V_2 -> V_3 ) ;
if ( V_3 != V_2 -> V_3 )
return;
F_3 ( V_5 -> V_12 , 0 ) ;
V_3 -> V_11 = NULL ;
V_2 -> V_3 = NULL ;
V_6 -> V_8 . V_9 -> V_13 ( V_6 , & V_5 -> V_2 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
int V_7 ;
if ( V_2 -> V_14 == V_15 )
return 0 ;
V_6 -> V_8 . V_9 -> V_16 ( V_6 , & V_5 -> V_17 ) ;
V_7 = V_6 -> V_8 . V_9 -> V_18 ( V_6 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_14 = V_15 ;
return V_7 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
if ( V_2 -> V_14 != V_15 )
return;
V_6 -> V_8 . V_9 -> V_19 ( V_6 ) ;
V_2 -> V_14 = V_20 ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_21 * V_17 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
V_5 -> V_17 = * V_17 ;
V_2 -> V_22 . V_17 = * V_17 ;
V_6 -> V_8 . V_9 -> V_16 ( V_6 , V_17 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_21 * V_17 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
* V_17 = V_5 -> V_17 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_21 * V_17 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
int V_7 ;
V_7 = V_6 -> V_8 . V_9 -> V_23 ( V_6 , V_17 ) ;
return V_7 ;
}
static int F_12 ( struct V_1 * V_2 ,
T_1 * V_24 , int V_25 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
int V_7 ;
if ( ! F_13 ( V_5 -> V_26 ) )
return - V_27 ;
F_3 ( V_5 -> V_28 , 1 ) ;
V_7 = V_6 -> V_8 . V_9 -> V_29 ( V_6 , V_24 , V_25 ) ;
F_3 ( V_5 -> V_28 , 0 ) ;
return V_7 ;
}
static bool F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_13 ( V_5 -> V_26 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
void (* F_16)( void * V_30 ,
enum V_31 V_32 ) ,
void * V_30 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_17 ( & V_5 -> V_33 ) ;
V_5 -> V_34 = F_16 ;
V_5 -> V_35 = V_30 ;
F_18 ( & V_5 -> V_33 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_17 ( & V_5 -> V_33 ) ;
V_5 -> V_34 = NULL ;
V_5 -> V_35 = NULL ;
F_18 ( & V_5 -> V_33 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_17 ( & V_5 -> V_33 ) ;
V_5 -> V_36 = true ;
F_18 ( & V_5 -> V_33 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_17 ( & V_5 -> V_33 ) ;
V_5 -> V_36 = false ;
F_18 ( & V_5 -> V_33 ) ;
}
static int F_22 ( struct V_1 * V_2 ,
const struct V_37 * V_38 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
return V_6 -> V_8 . V_9 -> V_39 ( V_6 , V_38 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
bool V_40 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
return V_6 -> V_8 . V_9 -> V_41 ( V_6 , V_40 ) ;
}
static T_2 F_24 ( int V_42 , void * V_43 )
{
struct V_4 * V_5 = V_43 ;
F_17 ( & V_5 -> V_33 ) ;
if ( V_5 -> V_36 && V_5 -> V_34 ) {
enum V_31 V_32 ;
if ( F_14 ( & V_5 -> V_2 ) )
V_32 = V_44 ;
else
V_32 = V_45 ;
V_5 -> V_34 ( V_5 -> V_35 , V_32 ) ;
}
F_18 ( & V_5 -> V_33 ) ;
return V_46 ;
}
static int F_25 ( struct V_47 * V_48 )
{
struct V_4 * V_5 = F_26 ( V_48 ) ;
struct V_49 * V_50 = V_48 -> V_51 . V_52 ;
struct V_1 * V_6 ;
V_6 = F_27 ( V_50 ) ;
if ( F_28 ( V_6 ) ) {
F_29 ( & V_48 -> V_51 , L_1 ) ;
return F_30 ( V_6 ) ;
}
V_5 -> V_6 = V_6 ;
return 0 ;
}
static int F_31 ( struct V_47 * V_48 )
{
struct V_1 * V_6 , * V_2 ;
struct V_4 * V_5 ;
int V_7 ;
struct V_53 * V_54 ;
V_5 = F_32 ( & V_48 -> V_51 , sizeof( * V_5 ) , V_55 ) ;
if ( ! V_5 )
return - V_56 ;
F_33 ( V_48 , V_5 ) ;
if ( ! V_48 -> V_51 . V_52 )
return - V_27 ;
V_7 = F_25 ( V_48 ) ;
if ( V_7 )
return V_7 ;
V_54 = F_34 ( & V_48 -> V_51 , NULL , 0 ,
V_57 ) ;
if ( F_28 ( V_54 ) ) {
V_7 = F_30 ( V_54 ) ;
goto V_58;
}
V_5 -> V_12 = V_54 ;
V_54 = F_34 ( & V_48 -> V_51 , NULL , 1 ,
V_57 ) ;
if ( F_28 ( V_54 ) ) {
V_7 = F_30 ( V_54 ) ;
goto V_58;
}
V_5 -> V_28 = V_54 ;
V_54 = F_35 ( & V_48 -> V_51 , NULL , 2 ,
V_59 ) ;
if ( F_28 ( V_54 ) ) {
V_7 = F_30 ( V_54 ) ;
goto V_58;
}
V_5 -> V_26 = V_54 ;
F_36 ( & V_5 -> V_33 ) ;
V_7 = F_37 ( & V_48 -> V_51 , F_38 ( V_5 -> V_26 ) ,
NULL , F_24 ,
V_60 | V_61 | V_62 ,
L_2 , V_5 ) ;
if ( V_7 )
goto V_58;
V_2 = & V_5 -> V_2 ;
V_2 -> V_8 . V_9 = & V_63 ;
V_2 -> V_51 = & V_48 -> V_51 ;
V_2 -> type = V_64 ;
V_2 -> V_65 = V_64 ;
V_2 -> V_66 = V_67 ;
V_2 -> V_68 = 1 ;
V_6 = V_5 -> V_6 ;
V_7 = F_39 ( V_2 ) ;
if ( V_7 ) {
F_29 ( & V_48 -> V_51 , L_3 ) ;
goto V_69;
}
return 0 ;
V_69:
V_58:
F_40 ( V_5 -> V_6 ) ;
return V_7 ;
}
static int T_3 F_41 ( struct V_47 * V_48 )
{
struct V_4 * V_5 = F_26 ( V_48 ) ;
struct V_1 * V_2 = & V_5 -> V_2 ;
struct V_1 * V_6 = V_5 -> V_6 ;
F_42 ( & V_5 -> V_2 ) ;
F_6 ( F_43 ( V_2 ) ) ;
if ( F_43 ( V_2 ) )
F_8 ( V_2 ) ;
F_6 ( F_44 ( V_2 ) ) ;
if ( F_44 ( V_2 ) )
F_5 ( V_2 , V_2 -> V_3 ) ;
F_40 ( V_6 ) ;
return 0 ;
}
