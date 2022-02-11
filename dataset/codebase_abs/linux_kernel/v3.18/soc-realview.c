static const char * F_1 ( T_1 V_1 )
{
switch ( ( V_1 >> 16 ) & 0xfff ) {
case 0x0147 :
return L_1 ;
default:
return L_2 ;
}
}
static const char * F_2 ( T_1 V_1 )
{
switch ( ( V_1 >> 8 ) & 0xf ) {
case 0x05 :
return L_3 ;
default:
return L_2 ;
}
}
static T_2 F_3 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
char * V_6 )
{
return sprintf ( V_6 , L_4 , V_7 >> 24 ) ;
}
static T_2 F_4 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
char * V_6 )
{
return sprintf ( V_6 , L_5 , F_1 ( V_7 ) ) ;
}
static T_2 F_5 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
char * V_6 )
{
return sprintf ( V_6 , L_5 , F_2 ( V_7 ) ) ;
}
static T_2 F_6 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
char * V_6 )
{
return sprintf ( V_6 , L_4 , ( V_7 & 0xFF ) ) ;
}
static int F_7 ( struct V_8 * V_9 )
{
static struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 = V_9 -> V_3 . V_18 ;
int V_19 ;
V_11 = F_8 ( V_17 , L_6 ) ;
if ( F_9 ( V_11 ) )
return F_10 ( V_11 ) ;
V_15 = F_11 ( sizeof( * V_15 ) , V_20 ) ;
if ( ! V_15 )
return - V_21 ;
V_19 = F_12 ( V_17 , L_7 ,
& V_15 -> V_22 ) ;
if ( V_19 )
return - V_23 ;
V_15 -> V_24 = L_8 ;
V_15 -> V_25 = L_9 ;
V_13 = F_13 ( V_15 ) ;
if ( F_9 ( V_13 ) ) {
F_14 ( V_15 ) ;
return - V_26 ;
}
V_19 = F_15 ( V_11 , V_27 ,
& V_7 ) ;
if ( V_19 )
return - V_26 ;
F_16 ( F_17 ( V_13 ) , & V_28 ) ;
F_16 ( F_17 ( V_13 ) , & V_29 ) ;
F_16 ( F_17 ( V_13 ) , & V_30 ) ;
F_16 ( F_17 ( V_13 ) , & V_31 ) ;
F_18 ( & V_9 -> V_3 , L_10 ,
V_7 ) ;
return 0 ;
}
