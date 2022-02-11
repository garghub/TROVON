static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned long V_9 , V_10 ;
T_1 V_11 ;
if ( F_3 ( V_5 , 10 , & V_9 ) || V_9 > V_12 )
return - V_13 ;
F_4 ( & V_8 -> V_14 ) ;
if ( V_8 -> V_15 == V_9 )
goto V_16;
if ( V_9 == 0 ) {
F_5 ( V_8 -> V_9 ) ;
goto V_17;
}
V_10 = F_6 ( V_9 * ( V_8 -> V_9 -> V_18 - 1 ) , V_12 ) ;
V_11 = F_7 ( V_8 -> V_9 , V_10 , V_8 -> V_9 -> V_18 ) ;
if ( V_11 )
goto V_19;
if ( V_8 -> V_15 == 0 ) {
V_11 = F_8 ( V_8 -> V_9 ) ;
if ( V_11 )
goto V_19;
}
V_17:
V_8 -> V_15 = V_9 ;
V_16:
V_11 = V_6 ;
V_19:
F_9 ( & V_8 -> V_14 ) ;
return V_11 ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_8 -> V_15 ) ;
}
static int F_11 ( struct V_20 * V_21 )
{
struct V_1 * V_22 ;
struct V_7 * V_8 ;
int V_23 ;
int V_11 ;
V_8 = F_12 ( & V_21 -> V_2 , sizeof( * V_8 ) , V_24 ) ;
if ( ! V_8 )
return - V_25 ;
F_13 ( & V_8 -> V_14 ) ;
V_8 -> V_9 = F_14 ( & V_21 -> V_2 , V_21 -> V_2 . V_26 , NULL ) ;
if ( F_15 ( V_8 -> V_9 ) ) {
F_16 ( & V_21 -> V_2 , L_2 ) ;
return F_17 ( V_8 -> V_9 ) ;
}
F_18 ( V_21 , V_8 ) ;
V_23 = V_8 -> V_9 -> V_18 - 1 ;
V_8 -> V_15 = V_12 ;
V_11 = F_7 ( V_8 -> V_9 , V_23 , V_8 -> V_9 -> V_18 ) ;
if ( V_11 ) {
F_16 ( & V_21 -> V_2 , L_3 ) ;
return V_11 ;
}
V_11 = F_8 ( V_8 -> V_9 ) ;
if ( V_11 ) {
F_16 ( & V_21 -> V_2 , L_4 ) ;
return V_11 ;
}
V_22 = F_19 ( & V_21 -> V_2 , L_5 ,
V_8 , V_27 ) ;
if ( F_15 ( V_22 ) ) {
F_16 ( & V_21 -> V_2 , L_6 ) ;
F_5 ( V_8 -> V_9 ) ;
return F_17 ( V_22 ) ;
}
return 0 ;
}
static int F_20 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = F_21 ( V_21 ) ;
if ( V_8 -> V_15 )
F_5 ( V_8 -> V_9 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_15 )
F_5 ( V_8 -> V_9 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned long V_10 ;
int V_11 ;
if ( V_8 -> V_15 == 0 )
return 0 ;
V_10 = F_6 ( V_8 -> V_15 * ( V_8 -> V_9 -> V_18 - 1 ) , V_12 ) ;
V_11 = F_7 ( V_8 -> V_9 , V_10 , V_8 -> V_9 -> V_18 ) ;
if ( V_11 )
return V_11 ;
return F_8 ( V_8 -> V_9 ) ;
}
