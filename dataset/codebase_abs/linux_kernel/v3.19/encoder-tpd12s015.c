static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
bool V_5 ;
V_5 = F_2 ( V_4 -> V_6 ) ;
F_3 ( V_4 -> V_7 . V_8 , L_1 , V_5 ) ;
if ( F_4 ( V_4 -> V_9 ) ) {
if ( V_5 )
F_5 ( V_4 -> V_9 , 1 ) ;
else
F_5 ( V_4 -> V_9 , 0 ) ;
}
F_6 ( & V_4 -> V_10 ) ;
return V_11 ;
}
static int F_7 ( struct V_12 * V_7 ,
struct V_12 * V_13 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
struct V_12 * V_14 = V_4 -> V_14 ;
int V_15 ;
V_15 = V_14 -> V_16 . V_17 -> V_18 ( V_14 , V_7 ) ;
if ( V_15 )
return V_15 ;
V_13 -> V_19 = V_7 ;
V_7 -> V_13 = V_13 ;
F_9 ( & V_4 -> V_10 ) ;
F_5 ( V_4 -> V_20 , 1 ) ;
F_10 ( 300 ) ;
if ( F_2 ( V_4 -> V_6 ) ) {
unsigned long V_21 ;
V_21 = F_11 ( & V_4 -> V_10 ,
F_12 ( 250 ) ) ;
F_13 ( V_21 == 0 ) ;
}
return 0 ;
}
static void F_14 ( struct V_12 * V_7 ,
struct V_12 * V_13 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
struct V_12 * V_14 = V_4 -> V_14 ;
F_15 ( V_13 != V_7 -> V_13 ) ;
if ( V_13 != V_7 -> V_13 )
return;
F_5 ( V_4 -> V_20 , 0 ) ;
V_13 -> V_19 = NULL ;
V_7 -> V_13 = NULL ;
V_14 -> V_16 . V_17 -> V_22 ( V_14 , & V_4 -> V_7 ) ;
}
static int F_16 ( struct V_12 * V_7 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
struct V_12 * V_14 = V_4 -> V_14 ;
int V_15 ;
if ( V_7 -> V_23 == V_24 )
return 0 ;
V_14 -> V_16 . V_17 -> V_25 ( V_14 , & V_4 -> V_26 ) ;
V_15 = V_14 -> V_16 . V_17 -> V_27 ( V_14 ) ;
if ( V_15 )
return V_15 ;
V_7 -> V_23 = V_24 ;
return V_15 ;
}
static void F_17 ( struct V_12 * V_7 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
struct V_12 * V_14 = V_4 -> V_14 ;
if ( V_7 -> V_23 != V_24 )
return;
V_14 -> V_16 . V_17 -> V_28 ( V_14 ) ;
V_7 -> V_23 = V_29 ;
}
static void F_18 ( struct V_12 * V_7 ,
struct V_30 * V_26 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
struct V_12 * V_14 = V_4 -> V_14 ;
V_4 -> V_26 = * V_26 ;
V_7 -> V_31 . V_26 = * V_26 ;
V_14 -> V_16 . V_17 -> V_25 ( V_14 , V_26 ) ;
}
static void F_19 ( struct V_12 * V_7 ,
struct V_30 * V_26 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
* V_26 = V_4 -> V_26 ;
}
static int F_20 ( struct V_12 * V_7 ,
struct V_30 * V_26 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
struct V_12 * V_14 = V_4 -> V_14 ;
int V_15 ;
V_15 = V_14 -> V_16 . V_17 -> V_32 ( V_14 , V_26 ) ;
return V_15 ;
}
static int F_21 ( struct V_12 * V_7 ,
T_2 * V_33 , int V_34 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
struct V_12 * V_14 = V_4 -> V_14 ;
if ( ! F_2 ( V_4 -> V_6 ) )
return - V_35 ;
return V_14 -> V_16 . V_17 -> V_36 ( V_14 , V_33 , V_34 ) ;
}
static bool F_22 ( struct V_12 * V_7 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
return F_2 ( V_4 -> V_6 ) ;
}
static int F_23 ( struct V_12 * V_7 ,
const struct V_37 * V_38 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
struct V_12 * V_14 = V_4 -> V_14 ;
return V_14 -> V_16 . V_17 -> V_39 ( V_14 , V_38 ) ;
}
static int F_24 ( struct V_12 * V_7 ,
bool V_40 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
struct V_12 * V_14 = V_4 -> V_14 ;
return V_14 -> V_16 . V_17 -> V_41 ( V_14 , V_40 ) ;
}
static int F_25 ( struct V_42 * V_43 )
{
struct V_3 * V_4 = F_26 ( V_43 ) ;
struct V_44 * V_45 ;
struct V_12 * V_7 , * V_14 ;
V_45 = F_27 ( & V_43 -> V_8 ) ;
V_4 -> V_20 = V_45 -> V_20 ;
V_4 -> V_9 = V_45 -> V_9 ;
V_4 -> V_6 = V_45 -> V_6 ;
V_14 = F_28 ( V_45 -> V_46 ) ;
if ( V_14 == NULL ) {
F_29 ( & V_43 -> V_8 , L_2 ) ;
return - V_35 ;
}
V_4 -> V_14 = V_14 ;
V_7 = & V_4 -> V_7 ;
V_7 -> V_47 = V_45 -> V_47 ;
return 0 ;
}
static int F_30 ( struct V_42 * V_43 )
{
struct V_3 * V_4 = F_26 ( V_43 ) ;
struct V_48 * V_49 = V_43 -> V_8 . V_50 ;
struct V_12 * V_14 ;
int V_51 ;
V_51 = F_31 ( V_49 , 0 ) ;
if ( ! F_4 ( V_51 ) ) {
F_29 ( & V_43 -> V_8 , L_3 ) ;
return V_51 ;
}
V_4 -> V_20 = V_51 ;
V_51 = F_31 ( V_49 , 1 ) ;
if ( F_4 ( V_51 ) || V_51 == - V_52 ) {
V_4 -> V_9 = V_51 ;
} else {
F_29 ( & V_43 -> V_8 , L_4 ) ;
return V_51 ;
}
V_51 = F_31 ( V_49 , 2 ) ;
if ( ! F_4 ( V_51 ) ) {
F_29 ( & V_43 -> V_8 , L_5 ) ;
return V_51 ;
}
V_4 -> V_6 = V_51 ;
V_14 = F_32 ( V_49 ) ;
if ( F_33 ( V_14 ) ) {
F_29 ( & V_43 -> V_8 , L_6 ) ;
return F_34 ( V_14 ) ;
}
V_4 -> V_14 = V_14 ;
return 0 ;
}
static int F_35 ( struct V_42 * V_43 )
{
struct V_12 * V_14 , * V_7 ;
struct V_3 * V_4 ;
int V_15 ;
V_4 = F_36 ( & V_43 -> V_8 , sizeof( * V_4 ) , V_53 ) ;
if ( ! V_4 )
return - V_54 ;
F_37 ( V_43 , V_4 ) ;
F_38 ( & V_4 -> V_10 ) ;
if ( F_27 ( & V_43 -> V_8 ) ) {
V_15 = F_25 ( V_43 ) ;
if ( V_15 )
return V_15 ;
} else if ( V_43 -> V_8 . V_50 ) {
V_15 = F_30 ( V_43 ) ;
if ( V_15 )
return V_15 ;
} else {
return - V_35 ;
}
V_15 = F_39 ( & V_43 -> V_8 , V_4 -> V_20 ,
V_55 , L_7 ) ;
if ( V_15 )
goto V_56;
if ( F_4 ( V_4 -> V_9 ) ) {
V_15 = F_39 ( & V_43 -> V_8 , V_4 -> V_9 ,
V_55 , L_8 ) ;
if ( V_15 )
goto V_56;
}
V_15 = F_39 ( & V_43 -> V_8 , V_4 -> V_6 ,
V_57 , L_9 ) ;
if ( V_15 )
goto V_56;
V_15 = F_40 ( & V_43 -> V_8 , F_41 ( V_4 -> V_6 ) ,
NULL , F_1 ,
V_58 | V_59 |
V_60 , L_10 , V_4 ) ;
if ( V_15 )
goto V_61;
V_7 = & V_4 -> V_7 ;
V_7 -> V_16 . V_17 = & V_62 ;
V_7 -> V_8 = & V_43 -> V_8 ;
V_7 -> type = V_63 ;
V_7 -> V_64 = V_63 ;
V_7 -> V_65 = V_66 ;
V_7 -> V_67 = 1 ;
V_14 = V_4 -> V_14 ;
V_15 = F_42 ( V_7 ) ;
if ( V_15 ) {
F_29 ( & V_43 -> V_8 , L_11 ) ;
goto V_68;
}
return 0 ;
V_68:
V_61:
V_56:
F_43 ( V_4 -> V_14 ) ;
return V_15 ;
}
static int T_3 F_44 ( struct V_42 * V_43 )
{
struct V_3 * V_4 = F_26 ( V_43 ) ;
struct V_12 * V_7 = & V_4 -> V_7 ;
struct V_12 * V_14 = V_4 -> V_14 ;
F_45 ( & V_4 -> V_7 ) ;
F_15 ( F_46 ( V_7 ) ) ;
if ( F_46 ( V_7 ) )
F_17 ( V_7 ) ;
F_15 ( F_47 ( V_7 ) ) ;
if ( F_47 ( V_7 ) )
F_14 ( V_7 , V_7 -> V_13 ) ;
F_43 ( V_14 ) ;
return 0 ;
}
