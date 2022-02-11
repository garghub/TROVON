static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
int V_6 ;
if ( F_3 ( V_2 ) )
return 0 ;
V_6 = V_5 -> V_7 . V_8 -> V_9 ( V_5 , V_2 ) ;
if ( V_6 )
return V_6 ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
if ( ! F_3 ( V_2 ) )
return;
V_5 -> V_7 . V_8 -> V_10 ( V_5 , V_2 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
int V_6 ;
if ( ! F_3 ( V_2 ) )
return - V_11 ;
if ( F_6 ( V_2 ) )
return 0 ;
if ( V_4 -> V_12 )
V_5 -> V_7 . V_8 -> V_13 ( V_5 , V_4 -> V_12 ) ;
V_5 -> V_7 . V_8 -> V_14 ( V_5 , & V_4 -> V_15 ) ;
if ( V_4 -> V_16 ) {
V_6 = F_7 ( V_4 -> V_16 ) ;
if ( V_6 != 0 )
return V_6 ;
}
V_6 = V_5 -> V_7 . V_8 -> V_17 ( V_5 ) ;
if ( V_6 ) {
F_8 ( V_4 -> V_16 ) ;
return V_6 ;
}
F_9 ( 50 ) ;
if ( V_4 -> V_18 )
F_10 ( V_4 -> V_18 , 1 ) ;
if ( V_4 -> V_19 )
F_10 ( V_4 -> V_19 , 1 ) ;
V_2 -> V_20 = V_21 ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
if ( ! F_6 ( V_2 ) )
return;
if ( V_4 -> V_19 )
F_10 ( V_4 -> V_19 , 0 ) ;
if ( V_4 -> V_18 )
F_10 ( V_4 -> V_18 , 0 ) ;
F_9 ( 100 ) ;
V_5 -> V_7 . V_8 -> V_22 ( V_5 ) ;
if ( V_4 -> V_16 )
F_8 ( V_4 -> V_16 ) ;
V_2 -> V_20 = V_23 ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
V_4 -> V_15 = * V_25 ;
V_2 -> V_26 . V_25 = * V_25 ;
V_5 -> V_7 . V_8 -> V_14 ( V_5 , V_25 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_25 = V_4 -> V_15 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
return V_5 -> V_7 . V_8 -> V_27 ( V_5 , V_25 ) ;
}
static int F_15 ( struct V_28 * V_29 , int V_30 , unsigned long V_31 ,
char * V_32 , struct V_33 * * V_34 )
{
struct V_33 * V_35 ;
int V_6 ;
* V_34 = NULL ;
V_6 = F_16 ( V_29 , V_30 , V_31 , V_32 ) ;
if ( V_6 )
return V_6 == - V_36 ? 0 : V_6 ;
V_35 = F_17 ( V_30 ) ;
if ( F_18 ( V_35 ) )
return F_19 ( V_35 ) == - V_36 ? 0 : F_19 ( V_35 ) ;
* V_34 = V_35 ;
return 0 ;
}
static int F_20 ( struct V_37 * V_38 )
{
const struct V_39 * V_40 ;
struct V_3 * V_4 = F_21 ( V_38 ) ;
struct V_1 * V_2 , * V_5 ;
int V_6 ;
V_40 = F_22 ( & V_38 -> V_29 ) ;
V_5 = F_23 ( V_40 -> V_41 ) ;
if ( V_5 == NULL ) {
F_24 ( & V_38 -> V_29 , L_1 ,
V_40 -> V_41 ) ;
return - V_42 ;
}
V_4 -> V_5 = V_5 ;
V_4 -> V_12 = V_40 -> V_12 ;
V_2 = & V_4 -> V_2 ;
V_2 -> V_43 = V_40 -> V_43 ;
V_6 = F_15 ( & V_38 -> V_29 , V_40 -> V_44 , V_45 ,
L_2 , & V_4 -> V_44 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_15 ( & V_38 -> V_29 , V_40 -> V_46 , V_47 ,
L_3 , & V_4 -> V_46 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_15 ( & V_38 -> V_29 , V_40 -> V_48 , V_47 ,
L_4 , & V_4 -> V_48 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_15 ( & V_38 -> V_29 , V_40 -> V_18 , V_45 ,
L_5 , & V_4 -> V_18 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_15 ( & V_38 -> V_29 , V_40 -> V_19 , V_45 ,
L_6 , & V_4 -> V_19 ) ;
if ( V_6 )
return V_6 ;
return 0 ;
}
static int F_25 ( struct V_28 * V_29 , int V_49 , int V_50 ,
const char * V_32 , struct V_33 * * V_34 )
{
struct V_33 * V_35 ;
int V_6 ;
* V_34 = NULL ;
V_35 = F_26 ( V_29 , V_32 , V_49 ) ;
if ( F_18 ( V_35 ) )
return F_19 ( V_35 ) == - V_36 ? 0 : F_19 ( V_35 ) ;
V_6 = F_27 ( V_35 , V_50 ) ;
if ( V_6 )
return V_6 ;
* V_34 = V_35 ;
return 0 ;
}
static int F_28 ( struct V_37 * V_38 )
{
struct V_3 * V_4 = F_21 ( V_38 ) ;
struct V_51 * V_52 = V_38 -> V_29 . V_53 ;
struct V_1 * V_5 ;
int V_6 ;
V_4 -> V_16 = F_29 ( & V_38 -> V_29 , L_7 ) ;
if ( F_18 ( V_4 -> V_16 ) ) {
F_24 ( & V_38 -> V_29 , L_8 ) ;
return F_19 ( V_4 -> V_16 ) ;
}
V_6 = F_25 ( & V_38 -> V_29 , 0 , 0 , L_9 , & V_4 -> V_19 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_25 ( & V_38 -> V_29 , 0 , 0 , L_10 , & V_4 -> V_18 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_25 ( & V_38 -> V_29 , 0 , 0 , L_11 , & V_4 -> V_44 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_25 ( & V_38 -> V_29 , 1 , 1 , L_11 , & V_4 -> V_46 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_25 ( & V_38 -> V_29 , 2 , 1 , L_11 , & V_4 -> V_48 ) ;
if ( V_6 )
return V_6 ;
V_5 = F_30 ( V_52 ) ;
if ( F_18 ( V_5 ) ) {
F_24 ( & V_38 -> V_29 , L_12 ) ;
return F_19 ( V_5 ) ;
}
V_4 -> V_5 = V_5 ;
return 0 ;
}
static int F_31 ( struct V_37 * V_38 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_6 ;
V_4 = F_32 ( & V_38 -> V_29 , sizeof( * V_4 ) , V_54 ) ;
if ( V_4 == NULL )
return - V_55 ;
F_33 ( V_38 , V_4 ) ;
if ( F_22 ( & V_38 -> V_29 ) ) {
V_6 = F_20 ( V_38 ) ;
if ( V_6 )
return V_6 ;
} else if ( V_38 -> V_29 . V_53 ) {
V_6 = F_28 ( V_38 ) ;
if ( V_6 )
return V_6 ;
} else {
return - V_11 ;
}
V_4 -> V_15 = V_56 ;
V_2 = & V_4 -> V_2 ;
V_2 -> V_29 = & V_38 -> V_29 ;
V_2 -> V_57 = & V_58 ;
V_2 -> type = V_59 ;
V_2 -> V_60 = V_61 ;
V_2 -> V_26 . V_25 = V_4 -> V_15 ;
V_2 -> V_62 . V_8 . V_12 = V_4 -> V_12 ;
V_6 = F_34 ( V_2 ) ;
if ( V_6 ) {
F_24 ( & V_38 -> V_29 , L_13 ) ;
goto V_63;
}
return 0 ;
V_63:
F_35 ( V_4 -> V_5 ) ;
return V_6 ;
}
static int T_1 F_36 ( struct V_37 * V_38 )
{
struct V_3 * V_4 = F_21 ( V_38 ) ;
struct V_1 * V_2 = & V_4 -> V_2 ;
struct V_1 * V_5 = V_4 -> V_5 ;
F_37 ( V_2 ) ;
F_11 ( V_2 ) ;
F_4 ( V_2 ) ;
F_35 ( V_5 ) ;
return 0 ;
}
