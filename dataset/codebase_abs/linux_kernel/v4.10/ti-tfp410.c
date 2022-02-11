static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_1 *
F_3 ( struct V_4 * V_5 )
{
return F_2 ( V_5 , struct V_1 , V_5 ) ;
}
static int F_4 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_7 * V_7 ;
int V_8 ;
if ( ! V_6 -> V_9 )
goto V_10;
V_7 = F_5 ( V_5 , V_6 -> V_9 ) ;
if ( ! V_7 ) {
F_6 ( L_1 ) ;
goto V_10;
}
F_7 ( V_5 , V_7 ) ;
return F_8 ( V_5 , V_7 ) ;
V_10:
V_8 = F_9 ( V_5 , 1920 , 1200 ) ;
F_10 ( V_5 , 1024 , 768 ) ;
return V_8 ;
}
static enum V_11
F_11 ( struct V_4 * V_5 , bool V_12 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
if ( V_6 -> V_9 ) {
if ( F_12 ( V_6 -> V_9 ) )
return V_13 ;
else
return V_14 ;
}
return V_15 ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_8 ;
if ( ! V_3 -> V_16 ) {
F_14 ( V_6 -> V_17 , L_2 ) ;
return - V_18 ;
}
F_15 ( & V_6 -> V_5 ,
& V_19 ) ;
V_8 = F_16 ( V_3 -> V_17 , & V_6 -> V_5 ,
& V_20 , V_21 ) ;
if ( V_8 ) {
F_14 ( V_6 -> V_17 , L_3 , V_8 ) ;
return V_8 ;
}
F_17 ( & V_6 -> V_5 ,
V_3 -> V_16 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_6 )
{
struct V_22 * V_23 = NULL , * V_24 = NULL ;
struct V_22 * V_25 = NULL ;
int V_8 = 0 ;
V_23 = F_19 ( V_6 -> V_17 -> V_26 , 1 , - 1 ) ;
if ( ! V_23 )
goto V_27;
V_24 = F_20 ( V_23 ) ;
if ( ! V_24 )
goto V_27;
V_25 = F_21 ( V_24 , L_4 , 0 ) ;
if ( ! V_25 )
goto V_27;
V_6 -> V_9 = F_22 ( V_25 ) ;
if ( V_6 -> V_9 )
F_23 ( V_6 -> V_17 , L_5 ) ;
else
V_8 = - V_28 ;
V_27:
F_24 ( V_23 ) ;
F_24 ( V_24 ) ;
F_24 ( V_25 ) ;
return V_8 ;
}
static int F_25 ( struct V_29 * V_17 )
{
struct V_1 * V_6 ;
int V_8 ;
if ( ! V_17 -> V_26 ) {
F_14 ( V_17 , L_6 ) ;
return - V_30 ;
}
V_6 = F_26 ( V_17 , sizeof( * V_6 ) , V_31 ) ;
if ( ! V_6 )
return - V_32 ;
F_27 ( V_17 , V_6 ) ;
V_6 -> V_3 . V_33 = & V_34 ;
V_6 -> V_3 . V_26 = V_17 -> V_26 ;
V_6 -> V_17 = V_17 ;
V_8 = F_18 ( V_6 ) ;
if ( V_8 )
goto V_27;
V_8 = F_28 ( & V_6 -> V_3 ) ;
if ( V_8 ) {
F_14 ( V_17 , L_7 , V_8 ) ;
goto V_27;
}
return 0 ;
V_27:
F_29 ( V_6 -> V_9 ) ;
return V_8 ;
}
static int F_30 ( struct V_29 * V_17 )
{
struct V_1 * V_6 = F_31 ( V_17 ) ;
F_32 ( & V_6 -> V_3 ) ;
if ( V_6 -> V_9 )
F_29 ( V_6 -> V_9 ) ;
return 0 ;
}
static int F_33 ( struct V_35 * V_36 )
{
return F_25 ( & V_36 -> V_17 ) ;
}
static int F_34 ( struct V_35 * V_36 )
{
return F_30 ( & V_36 -> V_17 ) ;
}
static int F_35 ( struct V_37 * V_38 ,
const struct V_39 * V_40 )
{
int V_41 ;
if ( ! V_38 -> V_17 . V_26 ||
F_36 ( V_38 -> V_17 . V_26 , L_8 , & V_41 ) ) {
F_14 ( & V_38 -> V_17 ,
L_9 ) ;
return - V_30 ;
}
return F_25 ( & V_38 -> V_17 ) ;
}
static int F_37 ( struct V_37 * V_38 )
{
return F_30 ( & V_38 -> V_17 ) ;
}
static int T_1 F_38 ( void )
{
int V_8 ;
#if F_39 ( V_42 )
V_8 = F_40 ( & V_43 ) ;
if ( V_8 )
F_41 ( L_10 ,
V_44 , V_8 ) ;
else
V_45 . V_46 = 1 ;
#endif
V_8 = F_42 ( & V_47 ) ;
if ( V_8 )
F_41 ( L_11 ,
V_44 , V_8 ) ;
else
V_45 . V_48 = 1 ;
if ( V_45 . V_46 ||
V_45 . V_48 )
return 0 ;
return V_8 ;
}
static void T_2 F_43 ( void )
{
#if F_39 ( V_42 )
if ( V_45 . V_46 )
F_44 ( & V_43 ) ;
#endif
if ( V_45 . V_48 )
F_45 ( & V_47 ) ;
}
