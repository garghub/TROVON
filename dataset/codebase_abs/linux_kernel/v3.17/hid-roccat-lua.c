static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 , T_2 V_6 , T_3 V_7 ,
T_3 V_8 , T_4 V_9 )
{
struct V_10 * V_11 = F_2 ( V_4 , struct V_10 , V_4 ) ;
struct V_12 * V_13 = F_3 ( F_4 ( V_11 ) ) ;
struct V_14 * V_15 = F_5 ( F_6 ( V_11 ) ) ;
int V_16 ;
if ( V_6 >= V_8 )
return 0 ;
if ( V_6 != 0 || V_7 != V_8 )
return - V_17 ;
F_7 ( & V_13 -> V_18 ) ;
V_16 = F_8 ( V_15 , V_9 , V_5 , V_8 ) ;
F_9 ( & V_13 -> V_18 ) ;
return V_16 ? V_16 : V_8 ;
}
static T_1 F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void const * V_5 , T_2 V_6 , T_3 V_7 ,
T_3 V_8 , T_4 V_9 )
{
struct V_10 * V_11 = F_2 ( V_4 , struct V_10 , V_4 ) ;
struct V_12 * V_13 = F_3 ( F_4 ( V_11 ) ) ;
struct V_14 * V_15 = F_5 ( F_6 ( V_11 ) ) ;
int V_16 ;
if ( V_6 != 0 || V_7 != V_8 )
return - V_17 ;
F_7 ( & V_13 -> V_18 ) ;
V_16 = F_11 ( V_15 , V_9 , V_5 , V_8 ) ;
F_9 ( & V_13 -> V_18 ) ;
return V_16 ? V_16 : V_8 ;
}
static int F_12 ( struct V_19 * V_20 )
{
return F_13 ( & V_20 -> V_11 . V_4 , & V_21 ) ;
}
static void F_14 ( struct V_19 * V_20 )
{
F_15 ( & V_20 -> V_11 . V_4 , & V_21 ) ;
}
static int F_16 ( struct V_14 * V_15 ,
struct V_12 * V_13 )
{
F_17 ( & V_13 -> V_18 ) ;
return 0 ;
}
static int F_18 ( struct V_22 * V_23 )
{
struct V_19 * V_20 = F_6 ( V_23 -> V_11 . V_24 ) ;
struct V_14 * V_15 = F_5 ( V_20 ) ;
struct V_12 * V_13 ;
int V_16 ;
V_13 = F_19 ( sizeof( * V_13 ) , V_25 ) ;
if ( ! V_13 ) {
F_20 ( V_23 , L_1 ) ;
return - V_26 ;
}
F_21 ( V_23 , V_13 ) ;
V_16 = F_16 ( V_15 , V_13 ) ;
if ( V_16 ) {
F_20 ( V_23 , L_2 ) ;
goto exit;
}
V_16 = F_12 ( V_20 ) ;
if ( V_16 ) {
F_20 ( V_23 , L_3 ) ;
goto exit;
}
return 0 ;
exit:
F_22 ( V_13 ) ;
return V_16 ;
}
static void F_23 ( struct V_22 * V_23 )
{
struct V_19 * V_20 = F_6 ( V_23 -> V_11 . V_24 ) ;
struct V_12 * V_13 ;
F_14 ( V_20 ) ;
V_13 = F_3 ( V_23 ) ;
F_22 ( V_13 ) ;
}
static int F_24 ( struct V_22 * V_23 ,
const struct V_27 * V_28 )
{
int V_16 ;
V_16 = F_25 ( V_23 ) ;
if ( V_16 ) {
F_20 ( V_23 , L_4 ) ;
goto exit;
}
V_16 = F_26 ( V_23 , V_29 ) ;
if ( V_16 ) {
F_20 ( V_23 , L_5 ) ;
goto exit;
}
V_16 = F_18 ( V_23 ) ;
if ( V_16 ) {
F_20 ( V_23 , L_6 ) ;
goto V_30;
}
return 0 ;
V_30:
F_27 ( V_23 ) ;
exit:
return V_16 ;
}
static void F_28 ( struct V_22 * V_23 )
{
F_23 ( V_23 ) ;
F_27 ( V_23 ) ;
}
