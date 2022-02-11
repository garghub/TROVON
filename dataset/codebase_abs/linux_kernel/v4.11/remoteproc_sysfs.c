static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_6 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_6 -> V_7 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_8 )
{
struct V_6 * V_6 = F_2 ( V_2 ) ;
char * V_9 ;
int V_10 , V_11 = V_8 ;
V_10 = F_4 ( & V_6 -> V_12 ) ;
if ( V_10 ) {
F_5 ( V_2 , L_2 , V_6 -> V_13 , V_10 ) ;
return - V_14 ;
}
if ( V_6 -> V_15 != V_16 ) {
F_5 ( V_2 , L_3 ) ;
V_10 = - V_17 ;
goto V_18;
}
V_11 = strcspn ( V_5 , L_4 ) ;
V_9 = F_6 ( V_5 , V_11 , V_19 ) ;
if ( ! V_9 ) {
V_10 = - V_20 ;
goto V_18;
}
F_7 ( V_6 -> V_7 ) ;
V_6 -> V_7 = V_9 ;
V_18:
F_8 ( & V_6 -> V_12 ) ;
return V_10 ? V_10 : V_8 ;
}
static T_1 F_9 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_6 = F_2 ( V_2 ) ;
unsigned int V_15 ;
V_15 = V_6 -> V_15 > V_21 ? V_21 : V_6 -> V_15 ;
return sprintf ( V_5 , L_1 , V_22 [ V_15 ] ) ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_8 )
{
struct V_6 * V_6 = F_2 ( V_2 ) ;
int V_23 = 0 ;
if ( F_11 ( V_5 , L_5 ) ) {
if ( V_6 -> V_15 == V_24 )
return - V_17 ;
V_23 = F_12 ( V_6 ) ;
if ( V_23 )
F_5 ( & V_6 -> V_2 , L_6 , V_23 ) ;
} else if ( F_11 ( V_5 , L_7 ) ) {
if ( V_6 -> V_15 != V_24 )
return - V_14 ;
F_13 ( V_6 ) ;
} else {
F_5 ( & V_6 -> V_2 , L_8 , V_5 ) ;
V_23 = - V_14 ;
}
return V_23 ? V_23 : V_8 ;
}
int T_3 F_14 ( void )
{
int V_10 = F_15 ( & V_25 ) ;
if ( V_10 )
F_16 ( L_9 ) ;
return V_10 ;
}
void T_4 F_17 ( void )
{
F_18 ( & V_25 ) ;
}
