static int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
struct V_5 * V_6 ;
int V_7 ;
memset ( & V_4 , 0x00 , sizeof( V_4 ) ) ;
V_6 = F_2 ( L_1 , V_8 ) ;
if ( ! V_6 )
return - V_9 ;
V_2 -> V_10 = V_6 ;
V_4 . type = V_11 ;
V_4 . V_12 = - 1 ;
V_7 = F_3 ( V_2 -> V_10 , & V_4 , sizeof( V_4 ) ) ;
if ( V_7 )
goto V_13;
V_6 = F_2 ( L_1 , V_8 ) ;
if ( ! V_6 ) {
V_7 = - V_9 ;
goto V_13;
}
V_2 -> V_14 = V_6 ;
V_4 . type = V_15 ;
V_7 = F_3 ( V_2 -> V_14 , & V_4 , sizeof( V_4 ) ) ;
if ( V_7 )
goto V_16;
V_7 = F_4 ( V_2 -> V_10 ) ;
if ( V_7 )
goto V_16;
V_7 = F_4 ( V_2 -> V_14 ) ;
if ( V_7 )
goto V_17;
return 0 ;
V_17:
F_5 ( V_2 -> V_10 ) ;
V_16:
F_6 ( V_2 -> V_14 ) ;
V_13:
F_6 ( V_2 -> V_10 ) ;
return V_7 ;
}
static int F_7 ( struct V_18 * V_19 , void * V_20 )
{
struct V_5 * V_6 = F_8 ( V_19 ) ;
F_9 ( V_6 ) ;
return 0 ;
}
static int F_10 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
struct V_21 * V_21 ;
struct V_18 * V_19 = & V_6 -> V_19 ;
struct V_22 * V_23 = V_19 -> V_24 ;
int V_7 ;
V_2 = F_11 ( V_19 , sizeof( * V_2 ) , V_25 ) ;
if ( ! V_2 )
return - V_9 ;
V_7 = F_12 ( V_19 , F_13 ( 32 ) ) ;
if ( V_7 )
return V_7 ;
F_14 ( V_6 , V_2 ) ;
V_7 = F_1 ( V_2 ) ;
if ( V_7 ) {
F_15 ( V_19 , L_2 ) ;
return V_7 ;
}
V_21 = F_16 ( V_19 , L_3 ) ;
if ( F_17 ( V_21 ) ) {
F_15 ( V_19 , L_4 ) ;
return - V_26 ;
}
V_2 -> V_19 = V_19 ;
V_2 -> V_21 = V_21 ;
F_18 ( V_2 -> V_21 ) ;
V_2 -> V_27 = F_19 ( V_19 , L_5 ) ;
if ( F_17 ( V_2 -> V_27 ) ) {
V_7 = F_20 ( V_2 -> V_27 ) ;
goto V_16;
}
V_7 = F_21 ( V_2 -> V_27 ) ;
if ( V_7 ) {
F_15 ( V_19 , L_6 ) ;
goto V_16;
}
V_2 -> V_28 = F_19 ( V_19 , L_7 ) ;
if ( F_17 ( V_2 -> V_28 ) ) {
V_7 = F_20 ( V_2 -> V_28 ) ;
goto V_17;
}
V_7 = F_21 ( V_2 -> V_28 ) ;
if ( V_7 ) {
F_15 ( V_19 , L_8 ) ;
goto V_17;
}
if ( V_23 ) {
V_7 = F_22 ( V_23 , NULL , NULL , V_19 ) ;
if ( V_7 ) {
F_15 ( V_19 , L_9 ) ;
goto V_29;
}
} else {
F_15 ( V_19 , L_10 ) ;
V_7 = - V_30 ;
goto V_29;
}
return 0 ;
V_29:
F_23 ( V_2 -> V_28 ) ;
V_17:
F_23 ( V_2 -> V_27 ) ;
V_16:
F_24 ( V_21 ) ;
return V_7 ;
}
static int F_25 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_26 ( V_6 ) ;
F_27 ( & V_6 -> V_19 , NULL , F_7 ) ;
F_9 ( V_2 -> V_10 ) ;
F_9 ( V_2 -> V_14 ) ;
F_24 ( V_2 -> V_21 ) ;
F_23 ( V_2 -> V_27 ) ;
F_23 ( V_2 -> V_28 ) ;
return 0 ;
}
static int F_28 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_29 ( V_19 ) ;
F_30 ( V_2 -> V_21 ) ;
F_23 ( V_2 -> V_27 ) ;
F_23 ( V_2 -> V_28 ) ;
return 0 ;
}
static int F_31 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_29 ( V_19 ) ;
int V_7 ;
V_7 = F_21 ( V_2 -> V_27 ) ;
if ( V_7 ) {
F_15 ( V_19 , L_6 ) ;
return V_7 ;
}
V_7 = F_21 ( V_2 -> V_28 ) ;
if ( V_7 ) {
F_15 ( V_19 , L_8 ) ;
return V_7 ;
}
F_32 ( V_2 -> V_21 ) ;
F_33 ( V_19 ) ;
F_34 ( V_19 ) ;
F_35 ( V_19 ) ;
return 0 ;
}
