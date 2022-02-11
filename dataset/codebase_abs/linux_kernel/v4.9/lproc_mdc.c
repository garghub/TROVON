static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
int V_6 ;
struct V_7 * V_8 = F_2 ( V_2 , struct V_7 ,
V_9 ) ;
T_2 V_10 ;
V_10 = F_3 ( & V_8 -> V_11 . V_12 ) ;
V_6 = sprintf ( V_5 , L_1 , V_10 ) ;
return V_6 ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 ,
T_3 V_14 )
{
struct V_7 * V_8 = F_2 ( V_2 , struct V_7 ,
V_9 ) ;
int V_15 ;
unsigned long V_16 ;
V_15 = F_5 ( V_13 , 10 , & V_16 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_6 ( & V_8 -> V_11 . V_12 , V_16 ) ;
if ( V_15 )
V_14 = V_15 ;
return V_14 ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 , struct V_7 ,
V_9 ) ;
struct V_17 * V_12 = & V_8 -> V_11 . V_12 ;
return sprintf ( V_5 , L_2 , V_12 -> V_18 ) ;
}
void F_8 ( struct V_19 * V_20 )
{
V_20 -> V_21 = & V_22 ;
V_20 -> V_23 = V_24 ;
}
