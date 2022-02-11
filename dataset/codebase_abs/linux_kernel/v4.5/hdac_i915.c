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
static int F_7 ( T_1 V_15 )
{
return V_15 - 4 ;
}
int F_8 ( struct V_1 * V_2 , T_1 V_16 , int V_17 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 || ! V_5 -> V_7 || ! V_5 -> V_7 -> V_18 )
return - V_8 ;
return V_5 -> V_7 -> V_18 ( V_5 -> V_10 , F_7 ( V_16 ) , V_17 ) ;
}
int F_9 ( struct V_1 * V_2 , T_1 V_16 ,
bool * V_19 , char * V_20 , int V_21 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 || ! V_5 -> V_7 || ! V_5 -> V_7 -> V_22 )
return - V_8 ;
return V_5 -> V_7 -> V_22 ( V_5 -> V_10 , F_7 ( V_16 ) , V_19 ,
V_20 , V_21 ) ;
}
static int F_10 ( struct V_23 * V_10 )
{
struct V_4 * V_5 = V_24 ;
int V_25 ;
V_25 = F_11 ( V_10 , V_5 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( F_5 ( ! ( V_5 -> V_10 && V_5 -> V_7 && V_5 -> V_7 -> V_12 &&
V_5 -> V_7 -> V_13 && V_5 -> V_7 -> V_14 ) ) ) {
V_25 = - V_26 ;
goto V_27;
}
if ( ! F_12 ( V_5 -> V_7 -> V_28 ) ) {
V_25 = - V_8 ;
goto V_27;
}
return 0 ;
V_27:
F_13 ( V_10 , V_5 ) ;
return V_25 ;
}
static void F_14 ( struct V_23 * V_10 )
{
struct V_4 * V_5 = V_24 ;
F_15 ( V_5 -> V_7 -> V_28 ) ;
F_13 ( V_10 , V_5 ) ;
F_5 ( V_5 -> V_7 || V_5 -> V_10 ) ;
}
static int F_16 ( struct V_23 * V_10 , void * V_29 )
{
return ! strcmp ( V_10 -> V_30 -> V_31 , L_6 ) ;
}
int F_17 ( const struct V_32 * V_33 )
{
if ( F_5 ( ! V_24 ) )
return - V_8 ;
V_24 -> V_34 = V_33 ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = NULL ;
struct V_23 * V_10 = V_2 -> V_10 ;
struct V_4 * V_5 ;
int V_25 ;
V_5 = F_19 ( sizeof( * V_5 ) , V_37 ) ;
if ( ! V_5 )
return - V_38 ;
V_2 -> V_6 = V_5 ;
V_24 = V_5 ;
F_20 ( V_10 , & V_36 , F_16 , V_2 ) ;
V_25 = F_21 ( V_10 , & V_39 ,
V_36 ) ;
if ( V_25 < 0 )
goto V_40;
F_22 ( L_6 ) ;
if ( ! V_5 -> V_7 ) {
V_25 = - V_8 ;
goto V_41;
}
F_3 ( V_10 , L_7 ) ;
return 0 ;
V_41:
F_23 ( V_10 , & V_39 ) ;
V_40:
F_24 ( V_5 ) ;
V_2 -> V_6 = NULL ;
F_25 ( V_10 , L_8 , V_25 ) ;
return V_25 ;
}
int F_26 ( struct V_1 * V_2 )
{
struct V_23 * V_10 = V_2 -> V_10 ;
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 )
return 0 ;
F_5 ( V_2 -> V_11 ) ;
if ( V_2 -> V_11 > 0 && V_5 -> V_7 )
V_5 -> V_7 -> V_13 ( V_5 -> V_10 ) ;
F_23 ( V_10 , & V_39 ) ;
F_24 ( V_5 ) ;
V_2 -> V_6 = NULL ;
return 0 ;
}
