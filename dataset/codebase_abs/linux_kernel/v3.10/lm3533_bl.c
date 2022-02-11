static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 ;
}
static int F_2 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_3 ( V_5 ) ;
int V_6 = V_5 -> V_7 . V_6 ;
if ( V_5 -> V_7 . V_8 != V_9 )
V_6 = 0 ;
if ( V_5 -> V_7 . V_10 != V_9 )
V_6 = 0 ;
return F_4 ( & V_2 -> V_11 , ( V_12 ) V_6 ) ;
}
static int F_5 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_3 ( V_5 ) ;
V_12 V_13 ;
int V_14 ;
V_14 = F_6 ( & V_2 -> V_11 , & V_13 ) ;
if ( V_14 )
return V_14 ;
return V_13 ;
}
static T_1 F_7 ( struct V_15 * V_16 ,
struct V_17 * V_18 , char * V_19 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
return F_9 ( V_19 , V_20 , L_1 , V_2 -> V_3 ) ;
}
static T_1 F_10 ( struct V_15 * V_16 ,
struct V_17 * V_18 , char * V_19 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
unsigned V_21 = F_1 ( V_2 ) ;
return F_9 ( V_19 , V_20 , L_2 , V_21 ) ;
}
static T_1 F_11 ( struct V_15 * V_16 ,
struct V_17 * V_18 , char * V_19 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
int V_22 = F_1 ( V_2 ) ;
V_12 V_13 ;
V_12 V_23 ;
bool V_24 ;
int V_14 ;
V_14 = F_12 ( V_2 -> V_25 , V_26 , & V_13 ) ;
if ( V_14 )
return V_14 ;
V_23 = 1 << ( 2 * V_22 ) ;
V_24 = V_13 & V_23 ;
return F_9 ( V_19 , V_20 , L_1 , V_24 ) ;
}
static T_1 F_13 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
const char * V_19 , T_2 V_27 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
int V_22 = F_1 ( V_2 ) ;
int V_24 ;
V_12 V_13 ;
V_12 V_23 ;
int V_14 ;
if ( F_14 ( V_19 , 0 , & V_24 ) )
return - V_28 ;
V_23 = 1 << ( 2 * V_22 ) ;
if ( V_24 )
V_13 = V_23 ;
else
V_13 = 0 ;
V_14 = F_15 ( V_2 -> V_25 , V_26 , V_13 ,
V_23 ) ;
if ( V_14 )
return V_14 ;
return V_27 ;
}
static T_1 F_16 ( struct V_15 * V_16 ,
struct V_17 * V_18 , char * V_19 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
V_12 V_13 ;
V_12 V_23 ;
int V_29 ;
int V_14 ;
V_14 = F_12 ( V_2 -> V_25 , V_26 , & V_13 ) ;
if ( V_14 )
return V_14 ;
V_23 = 1 << ( 2 * F_1 ( V_2 ) + 1 ) ;
if ( V_13 & V_23 )
V_29 = 1 ;
else
V_29 = 0 ;
return F_9 ( V_19 , V_20 , L_3 , V_29 ) ;
}
static T_1 F_17 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
const char * V_19 , T_2 V_27 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
unsigned long V_29 ;
V_12 V_23 ;
V_12 V_13 ;
int V_14 ;
if ( F_18 ( V_19 , 0 , & V_29 ) )
return - V_28 ;
V_23 = 1 << ( 2 * F_1 ( V_2 ) + 1 ) ;
if ( V_29 )
V_13 = V_23 ;
else
V_13 = 0 ;
V_14 = F_15 ( V_2 -> V_25 , V_26 , V_13 ,
V_23 ) ;
if ( V_14 )
return V_14 ;
return V_27 ;
}
static T_1 F_19 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
char * V_19 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
V_12 V_13 ;
int V_14 ;
V_14 = F_20 ( & V_2 -> V_11 , & V_13 ) ;
if ( V_14 )
return V_14 ;
return F_9 ( V_19 , V_20 , L_2 , V_13 ) ;
}
static T_1 F_21 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
const char * V_19 , T_2 V_27 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
V_12 V_13 ;
int V_14 ;
if ( F_22 ( V_19 , 0 , & V_13 ) )
return - V_28 ;
V_14 = F_23 ( & V_2 -> V_11 , V_13 ) ;
if ( V_14 )
return V_14 ;
return V_27 ;
}
static T_3 F_24 ( struct V_30 * V_31 ,
struct V_32 * V_18 , int V_33 )
{
struct V_15 * V_16 = F_25 ( V_31 , struct V_15 , V_31 ) ;
struct V_1 * V_2 = F_8 ( V_16 ) ;
T_3 V_34 = V_18 -> V_34 ;
if ( V_18 == & V_35 . V_18 ||
V_18 == & V_36 . V_18 ) {
if ( ! V_2 -> V_25 -> V_37 )
V_34 = 0 ;
}
return V_34 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_38 * V_39 )
{
int V_14 ;
V_14 = F_27 ( & V_2 -> V_11 , V_39 -> V_40 ) ;
if ( V_14 )
return V_14 ;
return F_23 ( & V_2 -> V_11 , V_39 -> V_41 ) ;
}
static int F_28 ( struct V_42 * V_43 )
{
struct V_25 * V_25 ;
struct V_38 * V_39 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_44 V_7 ;
int V_14 ;
F_29 ( & V_43 -> V_16 , L_4 , V_45 ) ;
V_25 = F_8 ( V_43 -> V_16 . V_46 ) ;
if ( ! V_25 )
return - V_28 ;
V_39 = V_43 -> V_16 . V_47 ;
if ( ! V_39 ) {
F_30 ( & V_43 -> V_16 , L_5 ) ;
return - V_28 ;
}
if ( V_43 -> V_3 < 0 || V_43 -> V_3 >= V_48 ) {
F_30 ( & V_43 -> V_16 , L_6 , V_43 -> V_3 ) ;
return - V_28 ;
}
V_2 = F_31 ( & V_43 -> V_16 , sizeof( * V_2 ) , V_49 ) ;
if ( ! V_2 ) {
F_30 ( & V_43 -> V_16 ,
L_7 ) ;
return - V_50 ;
}
V_2 -> V_25 = V_25 ;
V_2 -> V_3 = V_43 -> V_3 ;
V_2 -> V_11 . V_25 = V_25 ;
V_2 -> V_11 . V_3 = F_1 ( V_2 ) ;
V_2 -> V_11 . V_16 = NULL ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . type = V_51 ;
V_7 . V_52 = V_53 ;
V_7 . V_6 = V_39 -> V_54 ;
V_5 = F_32 ( V_39 -> V_55 , V_43 -> V_16 . V_46 , V_2 ,
& V_56 , & V_7 ) ;
if ( F_33 ( V_5 ) ) {
F_30 ( & V_43 -> V_16 , L_8 ) ;
return F_34 ( V_5 ) ;
}
V_2 -> V_5 = V_5 ;
V_2 -> V_11 . V_16 = & V_2 -> V_5 -> V_16 ;
F_35 ( V_43 , V_2 ) ;
V_14 = F_36 ( & V_5 -> V_16 . V_31 , & V_57 ) ;
if ( V_14 < 0 ) {
F_30 ( & V_43 -> V_16 , L_9 ) ;
goto V_58;
}
F_37 ( V_5 ) ;
V_14 = F_26 ( V_2 , V_39 ) ;
if ( V_14 )
goto V_59;
V_14 = F_38 ( & V_2 -> V_11 ) ;
if ( V_14 )
goto V_59;
return 0 ;
V_59:
F_39 ( & V_5 -> V_16 . V_31 , & V_57 ) ;
V_58:
F_40 ( V_5 ) ;
return V_14 ;
}
static int F_41 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_42 ( V_43 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
F_29 ( & V_5 -> V_16 , L_4 , V_45 ) ;
V_5 -> V_7 . V_8 = V_60 ;
V_5 -> V_7 . V_6 = 0 ;
F_43 ( & V_2 -> V_11 ) ;
F_39 ( & V_5 -> V_16 . V_31 , & V_57 ) ;
F_40 ( V_5 ) ;
return 0 ;
}
static int F_44 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
F_29 ( V_16 , L_4 , V_45 ) ;
return F_43 ( & V_2 -> V_11 ) ;
}
static int F_45 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
F_29 ( V_16 , L_4 , V_45 ) ;
return F_38 ( & V_2 -> V_11 ) ;
}
static void F_46 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_42 ( V_43 ) ;
F_29 ( & V_43 -> V_16 , L_4 , V_45 ) ;
F_43 ( & V_2 -> V_11 ) ;
}
