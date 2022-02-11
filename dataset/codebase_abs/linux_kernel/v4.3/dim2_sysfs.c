static T_1 F_1 ( struct V_1 * V_2 , char * V_3 )
{
bool V_4 = F_2 () ;
return sprintf ( V_3 , L_1 , V_4 ? L_2 : L_3 ) ;
}
static void F_3 ( struct V_5 * V_6 )
{
}
static T_1 F_4 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_3 )
{
struct V_1 * V_2 =
F_5 ( V_6 , struct V_1 , V_9 ) ;
struct V_10 * V_11 = F_5 ( V_8 , struct V_10 , V_8 ) ;
if ( ! V_11 -> V_12 )
return - V_13 ;
return V_11 -> V_12 ( V_2 , V_3 ) ;
}
static T_1 F_6 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_3 , T_2 V_14 )
{
T_1 V_15 ;
struct V_1 * V_2 =
F_5 ( V_6 , struct V_1 , V_9 ) ;
struct V_10 * V_11 = F_5 ( V_8 , struct V_10 , V_8 ) ;
if ( ! V_11 -> V_16 )
return - V_13 ;
V_15 = V_11 -> V_16 ( V_2 , V_3 , V_14 ) ;
return V_15 ;
}
int F_7 ( struct V_1 * V_2 , struct V_5 * V_17 )
{
int V_18 ;
F_8 ( & V_2 -> V_9 , & V_19 ) ;
V_18 = F_9 ( & V_2 -> V_9 , V_17 , L_4 ) ;
if ( V_18 ) {
F_10 ( L_5 , V_18 ) ;
goto V_20;
}
V_18 = F_11 ( & V_2 -> V_9 , & V_21 ) ;
if ( V_18 ) {
F_10 ( L_6 , V_18 ) ;
goto V_22;
}
return 0 ;
V_22:
F_12 ( & V_2 -> V_9 ) ;
V_20:
return V_18 ;
}
void F_13 ( struct V_1 * V_2 )
{
F_12 ( & V_2 -> V_9 ) ;
}
