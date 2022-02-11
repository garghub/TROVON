static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! ( V_7 -> V_8 & V_9 ) )
return - V_10 ;
if ( V_7 -> V_8 & V_11 )
return sprintf ( V_5 , L_1 ) ;
return sprintf ( V_5 , L_2 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! ( V_7 -> V_8 & V_9 ) )
return - V_10 ;
if ( V_7 -> V_12 . V_13 )
return sprintf ( V_5 , L_3 , V_7 -> V_12 . V_13 / 10 ,
V_7 -> V_12 . V_13 % 10 ) ;
return sprintf ( V_5 , L_4 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! ( V_7 -> V_8 & V_9 ) )
return - V_10 ;
return sprintf ( V_5 , L_3 , V_7 -> V_12 . V_14 / 10 , V_7 -> V_12 . V_14 % 10 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! ( V_7 -> V_8 & V_9 ) )
return - V_10 ;
return sprintf ( V_5 , L_3 , V_7 -> V_12 . V_13 / 10 , V_7 -> V_12 . V_13 % 10 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_15 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_15 )
return - V_16 ;
F_7 ( V_7 , V_17 ) ;
return V_15 ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_5 , V_7 -> V_8 & V_18 ? L_6 : L_7 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_15 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_19 = V_15 ;
if ( ! V_15 )
return - V_16 ;
if ( ! strncmp ( V_5 , L_6 , 3 ) )
F_7 ( V_7 , V_20 ) ;
else {
if ( ! strncmp ( V_5 , L_7 , 2 ) )
F_7 ( V_7 , V_21 ) ;
else
V_19 = - V_16 ;
}
return V_19 ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_15 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_15 )
return - V_16 ;
F_7 ( V_7 , V_22 ) ;
return V_15 ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_8 , V_7 -> V_23 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_15 )
{
T_1 V_19 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_3 V_24 ;
if ( ! V_15 )
return - V_16 ;
V_19 = sscanf ( V_5 , L_9 , & V_24 ) ;
if ( V_19 == 1 ) {
F_13 ( & V_7 -> V_25 ) ;
V_7 -> V_23 &= V_24 ;
F_14 ( & V_7 -> V_25 ) ;
V_19 = 0 ;
}
return V_19 ? V_19 : V_15 ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_5 , V_7 -> V_26 ? L_10 : L_11 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_15 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_15 )
return - V_16 ;
F_13 ( & V_7 -> V_25 ) ;
if ( ! V_7 -> V_26 )
V_7 -> V_26 = 1 ;
F_14 ( & V_7 -> V_25 ) ;
F_7 ( V_7 , V_27 ) ;
return V_15 ;
}
int F_17 ( struct V_1 * V_2 )
{
return F_18 ( & V_2 -> V_28 , & V_29 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
F_20 ( & V_2 -> V_28 , & V_29 ) ;
}
