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
V_7 = F_3 ( V_2 -> V_10 , & V_4 , sizeof( V_4 ) ) ;
if ( V_7 )
goto V_12;
V_6 = F_2 ( L_1 , V_8 ) ;
if ( ! V_6 ) {
V_7 = - V_9 ;
goto V_12;
}
V_2 -> V_13 = V_6 ;
V_4 . type = V_14 ;
V_7 = F_3 ( V_2 -> V_13 , & V_4 , sizeof( V_4 ) ) ;
if ( V_7 )
goto V_15;
V_7 = F_4 ( V_2 -> V_10 ) ;
if ( V_7 )
goto V_15;
V_7 = F_4 ( V_2 -> V_13 ) ;
if ( V_7 )
goto V_16;
return 0 ;
V_16:
F_5 ( V_2 -> V_10 ) ;
V_15:
F_6 ( V_2 -> V_13 ) ;
V_12:
F_6 ( V_2 -> V_10 ) ;
return V_7 ;
}
static int F_7 ( struct V_17 * V_18 , void * V_19 )
{
struct V_5 * V_6 = F_8 ( V_18 ) ;
F_9 ( V_6 ) ;
return 0 ;
}
static int F_10 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
struct V_20 * V_20 ;
struct V_17 * V_18 = & V_6 -> V_18 ;
struct V_21 * V_22 = V_18 -> V_23 ;
int V_7 = - V_9 ;
V_2 = F_11 ( V_18 , sizeof( * V_2 ) , V_24 ) ;
if ( ! V_2 ) {
F_12 ( V_18 , L_2 ) ;
goto V_12;
}
if ( ! V_18 -> V_25 )
V_18 -> V_25 = & V_18 -> V_26 ;
if ( ! V_18 -> V_26 )
V_18 -> V_26 = F_13 ( 32 ) ;
F_14 ( V_6 , V_2 ) ;
V_7 = F_1 ( V_2 ) ;
if ( V_7 ) {
F_12 ( V_18 , L_3 ) ;
goto V_12;
}
V_20 = F_15 ( V_18 , L_4 ) ;
if ( F_16 ( V_20 ) ) {
F_12 ( V_18 , L_5 ) ;
V_7 = - V_27 ;
goto V_12;
}
V_2 -> V_18 = V_18 ;
V_2 -> V_20 = V_20 ;
F_17 ( V_2 -> V_20 ) ;
if ( V_22 ) {
V_7 = F_18 ( V_22 , NULL , NULL , V_18 ) ;
if ( V_7 ) {
F_12 ( V_18 , L_6 ) ;
goto V_15;
}
} else {
F_12 ( V_18 , L_7 ) ;
V_7 = - V_28 ;
goto V_15;
}
return 0 ;
V_15:
F_19 ( V_20 ) ;
V_12:
return V_7 ;
}
static int F_20 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_21 ( V_6 ) ;
F_22 ( & V_6 -> V_18 , NULL , F_7 ) ;
F_9 ( V_2 -> V_10 ) ;
F_9 ( V_2 -> V_13 ) ;
F_19 ( V_2 -> V_20 ) ;
return 0 ;
}
static int F_23 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_24 ( V_18 ) ;
F_25 ( V_2 -> V_20 ) ;
return 0 ;
}
static int F_26 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_24 ( V_18 ) ;
F_27 ( V_2 -> V_20 ) ;
F_28 ( V_18 ) ;
F_29 ( V_18 ) ;
F_30 ( V_18 ) ;
return 0 ;
}
