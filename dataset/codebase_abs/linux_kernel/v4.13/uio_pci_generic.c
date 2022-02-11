static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static T_1 F_3 ( int V_4 , struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( ! F_4 ( V_5 -> V_6 ) )
return V_7 ;
return V_8 ;
}
static int F_5 ( struct V_9 * V_6 ,
const struct V_10 * V_11 )
{
struct V_1 * V_5 ;
int V_12 ;
V_12 = F_6 ( V_6 ) ;
if ( V_12 ) {
F_7 ( & V_6 -> V_13 , L_1 ,
V_14 , V_12 ) ;
return V_12 ;
}
if ( V_6 -> V_4 && ! F_8 ( V_6 ) ) {
V_12 = - V_15 ;
goto V_16;
}
V_5 = F_9 ( sizeof( struct V_1 ) , V_17 ) ;
if ( ! V_5 ) {
V_12 = - V_18 ;
goto V_19;
}
V_5 -> V_3 . V_20 = L_2 ;
V_5 -> V_3 . V_21 = V_22 ;
V_5 -> V_6 = V_6 ;
if ( V_6 -> V_4 ) {
V_5 -> V_3 . V_4 = V_6 -> V_4 ;
V_5 -> V_3 . V_23 = V_24 ;
V_5 -> V_3 . V_25 = F_3 ;
} else {
F_10 ( & V_6 -> V_13 , L_3
L_4 ) ;
}
V_12 = F_11 ( & V_6 -> V_13 , & V_5 -> V_3 ) ;
if ( V_12 )
goto V_26;
F_12 ( V_6 , V_5 ) ;
return 0 ;
V_26:
F_13 ( V_5 ) ;
V_19:
V_16:
F_14 ( V_6 ) ;
return V_12 ;
}
static void remove ( struct V_9 * V_6 )
{
struct V_1 * V_5 = F_15 ( V_6 ) ;
F_16 ( & V_5 -> V_3 ) ;
F_14 ( V_6 ) ;
F_13 ( V_5 ) ;
}
