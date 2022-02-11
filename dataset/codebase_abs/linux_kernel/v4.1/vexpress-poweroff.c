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
static int F_7 ( struct V_9 * V_10 , unsigned long V_11 ,
void * V_12 )
{
F_1 ( V_13 , L_3 ) ;
return V_14 ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_15 * V_16 , char * V_17 )
{
return sprintf ( V_17 , L_4 , V_13 == V_2 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_15 * V_16 , const char * V_17 , T_2 V_18 )
{
long V_19 ;
int V_4 = F_10 ( V_17 , 0 , & V_19 ) ;
if ( ! V_4 && V_19 )
V_13 = V_2 ;
return V_4 ? V_4 : V_18 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_4 ;
V_13 = V_2 ;
V_4 = F_12 ( & V_20 ) ;
if ( V_4 ) {
F_13 ( V_2 , L_5 , V_4 ) ;
return V_4 ;
}
F_14 ( V_2 , & V_21 ) ;
return 0 ;
}
static int F_15 ( struct V_22 * V_23 )
{
const struct V_24 * V_25 =
F_16 ( V_26 , & V_23 -> V_2 ) ;
struct V_6 * V_6 ;
int V_27 = 0 ;
if ( ! V_25 )
return - V_28 ;
V_6 = F_17 ( & V_23 -> V_2 ) ;
if ( F_18 ( V_6 ) )
return F_19 ( V_6 ) ;
F_20 ( & V_23 -> V_2 , V_6 ) ;
switch ( (enum V_29 ) V_25 -> V_30 ) {
case V_31 :
V_8 = & V_23 -> V_2 ;
V_32 = F_6 ;
break;
case V_33 :
if ( ! V_13 )
V_27 = F_11 ( & V_23 -> V_2 ) ;
break;
case V_34 :
V_27 = F_11 ( & V_23 -> V_2 ) ;
break;
} ;
return V_27 ;
}
static int T_3 F_21 ( void )
{
return F_22 ( & V_35 ) ;
}
