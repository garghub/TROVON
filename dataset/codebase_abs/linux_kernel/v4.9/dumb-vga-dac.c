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
if ( F_5 ( V_6 -> V_9 ) )
goto V_10;
V_7 = F_6 ( V_5 , V_6 -> V_9 ) ;
if ( ! V_7 ) {
F_7 ( L_1 ) ;
goto V_10;
}
F_8 ( V_5 , V_7 ) ;
return F_9 ( V_5 , V_7 ) ;
V_10:
V_8 = F_10 ( V_5 , 1920 , 1200 ) ;
F_11 ( V_5 , 1024 , 768 ) ;
return V_8 ;
}
static enum V_11
F_12 ( struct V_4 * V_5 , bool V_12 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
if ( ! F_5 ( V_6 -> V_9 ) && F_13 ( V_6 -> V_9 ) )
return V_13 ;
return V_14 ;
}
static int F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_8 ;
if ( ! V_3 -> V_15 ) {
F_15 ( L_2 ) ;
return - V_16 ;
}
F_16 ( & V_6 -> V_5 ,
& V_17 ) ;
V_8 = F_17 ( V_3 -> V_18 , & V_6 -> V_5 ,
& V_19 , V_20 ) ;
if ( V_8 ) {
F_15 ( L_3 ) ;
return V_8 ;
}
F_18 ( & V_6 -> V_5 ,
V_3 -> V_15 ) ;
return 0 ;
}
static struct V_21 * F_19 ( struct V_22 * V_18 )
{
struct V_23 * V_24 , * V_25 , * V_26 ;
struct V_21 * V_9 ;
V_24 = F_20 ( V_18 -> V_27 , 1 , - 1 ) ;
if ( ! V_24 ) {
F_21 ( V_18 , L_4 ) ;
return F_22 ( - V_16 ) ;
}
V_26 = F_23 ( V_24 ) ;
F_24 ( V_24 ) ;
if ( ! V_26 ) {
F_21 ( V_18 , L_5 ) ;
return F_22 ( - V_28 ) ;
}
V_25 = F_25 ( V_26 , L_6 , 0 ) ;
F_24 ( V_26 ) ;
if ( ! V_25 )
return F_22 ( - V_16 ) ;
V_9 = F_26 ( V_25 ) ;
F_24 ( V_25 ) ;
if ( ! V_9 )
return F_22 ( - V_29 ) ;
return V_9 ;
}
static int F_27 ( struct V_30 * V_31 )
{
struct V_1 * V_6 ;
int V_8 ;
V_6 = F_28 ( & V_31 -> V_18 , sizeof( * V_6 ) , V_32 ) ;
if ( ! V_6 )
return - V_33 ;
F_29 ( V_31 , V_6 ) ;
V_6 -> V_9 = F_19 ( & V_31 -> V_18 ) ;
if ( F_5 ( V_6 -> V_9 ) ) {
if ( F_30 ( V_6 -> V_9 ) == - V_16 ) {
F_31 ( & V_31 -> V_18 ,
L_7 ) ;
} else {
F_21 ( & V_31 -> V_18 , L_8 ) ;
return F_30 ( V_6 -> V_9 ) ;
}
}
V_6 -> V_3 . V_34 = & V_35 ;
V_6 -> V_3 . V_27 = V_31 -> V_18 . V_27 ;
V_8 = F_32 ( & V_6 -> V_3 ) ;
if ( V_8 && ! F_5 ( V_6 -> V_9 ) )
F_33 ( V_6 -> V_9 ) ;
return V_8 ;
}
static int F_34 ( struct V_30 * V_31 )
{
struct V_1 * V_6 = F_35 ( V_31 ) ;
F_36 ( & V_6 -> V_3 ) ;
if ( ! F_5 ( V_6 -> V_9 ) )
F_33 ( V_6 -> V_9 ) ;
return 0 ;
}
