static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return F_3 ( V_5 ) ;
}
static T_1 F_4 ( struct V_2 * V_3 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
return sprintf ( V_8 , L_1 , V_9 -> V_10 ) ;
}
static T_1 F_5 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
const char * V_8 , T_2 V_11 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
T_3 V_12 ;
int V_13 ;
if ( V_9 -> V_14 )
goto V_15;
if ( F_6 ( V_16 , & V_9 -> V_17 ) )
V_13 = V_18 ;
else
V_13 = V_19 ;
if ( sscanf ( V_8 , L_2 , & V_12 ) > 0 ) {
if ( ( V_12 >= V_20 ) && ( V_12 <= V_13 ) &&
( F_7 ( V_12 ) ) )
V_9 -> V_10 = V_12 ;
}
return V_11 ;
V_15:
F_8 ( V_21 L_3 ) ;
return 0 ;
}
static T_1 F_9 ( struct V_2 * V_3 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
return sprintf ( V_8 , L_1 , V_9 -> V_22 ) ;
}
static T_1 F_10 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
const char * V_8 , T_2 V_11 )
{
T_3 V_12 ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
if ( V_9 -> V_14 )
goto V_15;
if ( sscanf ( V_8 , L_2 , & V_12 ) > 0 ) {
if ( ( V_12 >= V_23 ) &&
( V_12 <= V_24 ) ) {
V_9 -> V_22 = V_12 ;
}
}
return V_11 ;
V_15:
F_8 ( V_21 L_4 ) ;
return 0 ;
}
