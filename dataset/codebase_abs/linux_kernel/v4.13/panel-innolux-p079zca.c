static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_6 ;
if ( ! V_5 -> V_7 )
return 0 ;
V_5 -> V_8 -> V_9 . V_10 = V_11 ;
F_4 ( V_5 -> V_8 ) ;
V_6 = F_5 ( V_5 -> V_12 ) ;
if ( V_6 < 0 )
F_6 ( V_3 -> V_13 , L_1 ,
V_6 ) ;
V_5 -> V_7 = false ;
return 0 ;
}
static int F_7 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_6 ;
if ( ! V_5 -> V_14 )
return 0 ;
V_6 = F_8 ( V_5 -> V_12 ) ;
if ( V_6 < 0 ) {
F_6 ( V_3 -> V_13 , L_2 ,
V_6 ) ;
return V_6 ;
}
F_9 ( V_5 -> V_15 , 0 ) ;
F_10 ( 80 ) ;
V_6 = F_11 ( V_5 -> V_16 ) ;
if ( V_6 < 0 )
return V_6 ;
V_5 -> V_14 = false ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_6 , V_17 ;
if ( V_5 -> V_14 )
return 0 ;
F_9 ( V_5 -> V_15 , 0 ) ;
V_6 = F_13 ( V_5 -> V_16 ) ;
if ( V_6 < 0 )
return V_6 ;
F_14 ( 15000 , 16000 ) ;
F_9 ( V_5 -> V_15 , 1 ) ;
F_14 ( 15000 , 16000 ) ;
V_6 = F_15 ( V_5 -> V_12 ) ;
if ( V_6 < 0 ) {
F_6 ( V_3 -> V_13 , L_3 ,
V_6 ) ;
goto V_18;
}
F_10 ( 120 ) ;
V_6 = F_16 ( V_5 -> V_12 ) ;
if ( V_6 < 0 ) {
F_6 ( V_3 -> V_13 , L_4 ,
V_6 ) ;
goto V_18;
}
F_14 ( 5000 , 6000 ) ;
V_5 -> V_14 = true ;
return 0 ;
V_18:
V_17 = F_11 ( V_5 -> V_16 ) ;
if ( V_17 )
F_6 ( V_3 -> V_13 , L_5 ,
V_17 ) ;
F_9 ( V_5 -> V_15 , 0 ) ;
return V_6 ;
}
static int F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_19 ;
if ( V_5 -> V_7 )
return 0 ;
V_5 -> V_8 -> V_9 . V_10 = V_20 ;
V_19 = F_4 ( V_5 -> V_8 ) ;
if ( V_19 ) {
F_6 ( V_3 -> V_21 -> V_13 ,
L_6 , V_19 ) ;
return V_19 ;
}
V_5 -> V_7 = true ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 )
{
struct V_22 * V_23 ;
V_23 = F_19 ( V_3 -> V_21 , & V_24 ) ;
if ( ! V_23 ) {
F_6 ( V_3 -> V_21 -> V_13 , L_7 ,
V_24 . V_25 , V_24 . V_26 ,
V_24 . V_27 ) ;
return - V_28 ;
}
F_20 ( V_23 ) ;
F_21 ( V_3 -> V_29 , V_23 ) ;
V_3 -> V_29 -> V_30 . V_31 = 120 ;
V_3 -> V_29 -> V_30 . V_32 = 160 ;
V_3 -> V_29 -> V_30 . V_33 = 8 ;
return 1 ;
}
static int F_22 ( struct V_1 * V_5 )
{
struct V_34 * V_13 = & V_5 -> V_12 -> V_13 ;
struct V_35 * V_36 ;
int V_6 ;
V_5 -> V_16 = F_23 ( V_13 , L_8 ) ;
if ( F_24 ( V_5 -> V_16 ) )
return F_25 ( V_5 -> V_16 ) ;
V_5 -> V_15 = F_26 ( V_13 , L_9 ,
V_37 ) ;
if ( F_24 ( V_5 -> V_15 ) ) {
V_6 = F_25 ( V_5 -> V_15 ) ;
F_27 ( V_13 , L_10 , V_6 ) ;
V_5 -> V_15 = NULL ;
}
V_36 = F_28 ( V_13 -> V_38 , L_11 , 0 ) ;
if ( V_36 ) {
V_5 -> V_8 = F_29 ( V_36 ) ;
F_30 ( V_36 ) ;
if ( ! V_5 -> V_8 )
return - V_39 ;
}
F_31 ( & V_5 -> V_4 ) ;
V_5 -> V_4 . V_40 = & V_41 ;
V_5 -> V_4 . V_13 = & V_5 -> V_12 -> V_13 ;
V_6 = F_32 ( & V_5 -> V_4 ) ;
if ( V_6 < 0 )
goto V_42;
return 0 ;
V_42:
F_33 ( & V_5 -> V_8 -> V_13 ) ;
return V_6 ;
}
static void F_34 ( struct V_1 * V_5 )
{
if ( V_5 -> V_4 . V_13 )
F_35 ( & V_5 -> V_4 ) ;
F_33 ( & V_5 -> V_8 -> V_13 ) ;
}
static int F_36 ( struct V_43 * V_44 )
{
struct V_1 * V_5 ;
int V_6 ;
V_44 -> V_45 = 4 ;
V_44 -> V_46 = V_47 ;
V_44 -> V_48 = V_49 | V_50 |
V_51 ;
V_5 = F_37 ( & V_44 -> V_13 , sizeof( * V_5 ) , V_52 ) ;
if ( ! V_5 )
return - V_28 ;
F_38 ( V_44 , V_5 ) ;
V_5 -> V_12 = V_44 ;
V_6 = F_22 ( V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_39 ( V_44 ) ;
return V_6 ;
}
static int F_40 ( struct V_43 * V_44 )
{
struct V_1 * V_5 = F_41 ( V_44 ) ;
int V_6 ;
V_6 = F_7 ( & V_5 -> V_4 ) ;
if ( V_6 < 0 )
F_6 ( & V_44 -> V_13 , L_12 ,
V_6 ) ;
V_6 = F_3 ( & V_5 -> V_4 ) ;
if ( V_6 < 0 )
F_6 ( & V_44 -> V_13 , L_13 , V_6 ) ;
V_6 = F_42 ( V_44 ) ;
if ( V_6 < 0 )
F_6 ( & V_44 -> V_13 , L_14 ,
V_6 ) ;
F_43 ( & V_5 -> V_4 ) ;
F_34 ( V_5 ) ;
return 0 ;
}
static void F_44 ( struct V_43 * V_44 )
{
struct V_1 * V_5 = F_41 ( V_44 ) ;
F_7 ( & V_5 -> V_4 ) ;
F_3 ( & V_5 -> V_4 ) ;
}
