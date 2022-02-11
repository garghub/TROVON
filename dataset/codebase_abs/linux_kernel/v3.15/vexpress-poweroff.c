static void F_1 ( struct V_1 * V_2 , const char * V_3 )
{
int V_4 = - V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 ) {
V_4 = F_3 ( V_7 , 0 , 0 ) ;
if ( ! V_4 )
F_4 ( 1000 ) ;
}
F_5 ( V_2 , L_1 , V_3 , V_4 ) ;
}
static void F_6 ( void )
{
F_1 ( V_8 , L_2 ) ;
}
static void F_7 ( enum V_9 V_9 , const char * V_10 )
{
F_1 ( V_11 , L_3 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
return sprintf ( V_14 , L_4 , V_11 == V_2 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_12 * V_13 , const char * V_14 , T_2 V_15 )
{
long V_16 ;
int V_4 = F_10 ( V_14 , 0 , & V_16 ) ;
if ( ! V_4 && V_16 )
V_11 = V_2 ;
return V_4 ? V_4 : V_15 ;
}
static int F_11 ( struct V_17 * V_18 )
{
enum V_19 V_7 ;
const struct V_20 * V_21 =
F_12 ( V_22 , & V_18 -> V_2 ) ;
struct V_6 * V_23 ;
if ( V_21 )
V_7 = (enum V_19 ) V_21 -> V_24 ;
else
V_7 = V_18 -> V_25 -> V_26 ;
V_23 = F_13 ( & V_18 -> V_2 ) ;
if ( ! V_23 )
return - V_27 ;
F_14 ( & V_18 -> V_2 , V_23 ) ;
switch ( V_7 ) {
case V_28 :
V_8 = & V_18 -> V_2 ;
V_29 = F_6 ;
break;
case V_30 :
if ( ! V_11 )
V_11 = & V_18 -> V_2 ;
V_31 = F_7 ;
F_15 ( & V_18 -> V_2 , & V_32 ) ;
break;
case V_33 :
V_11 = & V_18 -> V_2 ;
V_31 = F_7 ;
F_15 ( & V_18 -> V_2 , & V_32 ) ;
break;
} ;
return 0 ;
}
static int T_3 F_16 ( void )
{
return F_17 ( & V_34 ) ;
}
