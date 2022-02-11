static void F_1 ( struct V_1 * V_2 , const char * V_3 )
{
int V_4 = - V_5 ;
struct V_6 * V_7 =
F_2 ( V_2 ) ;
if ( V_7 ) {
unsigned long V_8 ;
V_4 = F_3 ( V_7 , 0 , 0 ) ;
V_8 = V_9 + V_10 ;
while ( F_4 ( V_9 , V_8 ) )
F_5 () ;
}
F_6 ( V_2 , L_1 , V_3 , V_4 ) ;
}
static void F_7 ( void )
{
F_1 ( V_11 , L_2 ) ;
}
static void F_8 ( enum V_12 V_12 , const char * V_13 )
{
F_1 ( V_14 , L_3 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_15 * V_16 , char * V_17 )
{
return sprintf ( V_17 , L_4 , V_14 == V_2 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_15 * V_16 , const char * V_17 , T_2 V_18 )
{
long V_19 ;
int V_4 = F_11 ( V_17 , 0 , & V_19 ) ;
if ( ! V_4 && V_19 )
V_14 = V_2 ;
return V_4 ? V_4 : V_18 ;
}
static int F_12 ( struct V_20 * V_21 )
{
enum V_22 V_7 ;
const struct V_23 * V_24 =
F_13 ( V_25 , & V_21 -> V_2 ) ;
if ( V_24 )
V_7 = (enum V_22 ) V_24 -> V_26 ;
else
V_7 = V_21 -> V_27 -> V_28 ;
switch ( V_7 ) {
case V_29 :
V_11 = & V_21 -> V_2 ;
V_30 = F_7 ;
break;
case V_31 :
if ( ! V_14 )
V_14 = & V_21 -> V_2 ;
V_32 = F_8 ;
F_14 ( & V_21 -> V_2 , & V_33 ) ;
break;
case V_34 :
V_14 = & V_21 -> V_2 ;
V_32 = F_8 ;
F_14 ( & V_21 -> V_2 , & V_33 ) ;
break;
} ;
return 0 ;
}
static int T_3 F_15 ( void )
{
return F_16 ( & V_35 ) ;
}
