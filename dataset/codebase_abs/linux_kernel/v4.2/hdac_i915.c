int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 || ! V_5 -> V_7 )
return - V_8 ;
if ( ! V_5 -> V_7 -> V_9 ) {
F_2 ( V_2 -> V_10 ,
L_1 ) ;
return 0 ;
}
F_3 ( V_2 -> V_10 , L_2 ,
V_3 ? L_3 : L_4 ) ;
V_5 -> V_7 -> V_9 ( V_5 -> V_10 , V_3 ) ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 || ! V_5 -> V_7 )
return - V_8 ;
F_3 ( V_2 -> V_10 , L_5 ,
V_3 ? L_3 : L_4 ) ;
if ( V_3 ) {
if ( ! V_2 -> V_11 ++ ) {
V_5 -> V_7 -> V_12 ( V_5 -> V_10 ) ;
F_1 ( V_2 , true ) ;
F_1 ( V_2 , false ) ;
}
} else {
F_5 ( ! V_2 -> V_11 ) ;
if ( ! -- V_2 -> V_11 )
V_5 -> V_7 -> V_13 ( V_5 -> V_10 ) ;
}
return 0 ;
}
int F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 || ! V_5 -> V_7 )
return - V_8 ;
return V_5 -> V_7 -> V_14 ( V_5 -> V_10 ) ;
}
static int F_7 ( struct V_15 * V_10 )
{
struct V_4 * V_5 = V_16 ;
int V_17 ;
V_17 = F_8 ( V_10 , V_5 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( F_5 ( ! ( V_5 -> V_10 && V_5 -> V_7 && V_5 -> V_7 -> V_12 &&
V_5 -> V_7 -> V_13 && V_5 -> V_7 -> V_14 ) ) ) {
V_17 = - V_18 ;
goto V_19;
}
if ( ! F_9 ( V_5 -> V_7 -> V_20 ) ) {
V_17 = - V_8 ;
goto V_19;
}
return 0 ;
V_19:
F_10 ( V_10 , V_5 ) ;
return V_17 ;
}
static void F_11 ( struct V_15 * V_10 )
{
struct V_4 * V_5 = V_16 ;
F_12 ( V_5 -> V_7 -> V_20 ) ;
F_10 ( V_10 , V_5 ) ;
F_5 ( V_5 -> V_7 || V_5 -> V_10 ) ;
}
static int F_13 ( struct V_15 * V_10 , void * V_21 )
{
return ! strcmp ( V_10 -> V_22 -> V_23 , L_6 ) ;
}
int F_14 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = NULL ;
struct V_15 * V_10 = V_2 -> V_10 ;
struct V_4 * V_5 ;
int V_17 ;
V_5 = F_15 ( sizeof( * V_5 ) , V_26 ) ;
if ( ! V_5 )
return - V_27 ;
V_2 -> V_6 = V_5 ;
V_16 = V_5 ;
F_16 ( V_10 , & V_25 , F_13 , V_2 ) ;
V_17 = F_17 ( V_10 , & V_28 ,
V_25 ) ;
if ( V_17 < 0 )
goto V_29;
F_18 ( L_6 ) ;
if ( ! V_5 -> V_7 ) {
V_17 = - V_8 ;
goto V_30;
}
F_3 ( V_10 , L_7 ) ;
return 0 ;
V_30:
F_19 ( V_10 , & V_28 ) ;
V_29:
F_20 ( V_5 ) ;
V_2 -> V_6 = NULL ;
F_21 ( V_10 , L_8 , V_17 ) ;
return V_17 ;
}
int F_22 ( struct V_1 * V_2 )
{
struct V_15 * V_10 = V_2 -> V_10 ;
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 )
return 0 ;
F_5 ( V_2 -> V_11 ) ;
if ( V_2 -> V_11 > 0 && V_5 -> V_7 )
V_5 -> V_7 -> V_13 ( V_5 -> V_10 ) ;
F_19 ( V_10 , & V_28 ) ;
F_20 ( V_5 ) ;
V_2 -> V_6 = NULL ;
return 0 ;
}
