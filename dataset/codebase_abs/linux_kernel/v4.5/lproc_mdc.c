static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
int V_6 ;
struct V_7 * V_8 = F_2 ( V_2 , struct V_7 ,
V_9 ) ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
F_3 ( & V_11 -> V_13 ) ;
V_6 = sprintf ( V_5 , L_1 , V_11 -> V_14 ) ;
F_4 ( & V_11 -> V_13 ) ;
return V_6 ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_15 ,
T_2 V_16 )
{
struct V_7 * V_8 = F_2 ( V_2 , struct V_7 ,
V_9 ) ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
int V_17 ;
unsigned long V_18 ;
V_17 = F_6 ( V_15 , 10 , & V_18 ) ;
if ( V_17 )
return V_17 ;
if ( V_18 < 1 || V_18 > V_19 )
return - V_20 ;
F_3 ( & V_11 -> V_13 ) ;
V_11 -> V_14 = V_18 ;
F_4 ( & V_11 -> V_13 ) ;
return V_16 ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 , struct V_7 ,
V_9 ) ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
return sprintf ( V_5 , L_2 , V_11 -> V_21 ) ;
}
void F_8 ( struct V_22 * V_23 )
{
V_23 -> V_24 = & V_25 ;
V_23 -> V_26 = V_27 ;
}
