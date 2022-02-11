static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_7 ;
F_2 ( & V_6 -> V_8 ) ;
return V_9 ;
}
static void F_3 ( struct V_10 * V_8 )
{
struct V_5 * V_6 = F_4 ( V_8 ,
struct V_5 , V_8 ) ;
int V_11 ;
if ( ! V_6 -> V_12 )
return;
V_11 = F_5 ( V_6 -> V_12 ) ;
if ( V_6 -> V_13 )
V_11 = ! V_11 ;
if ( V_11 ) {
if ( V_6 -> V_14 )
F_6 ( V_6 -> V_4 ,
V_6 -> V_14 ) ;
else
F_6 ( V_6 -> V_4 , V_15 ) ;
} else {
F_6 ( V_6 -> V_4 , V_16 ) ;
}
}
static T_2 F_7 ( struct V_17 * V_18 ,
struct V_19 * V_20 , char * V_21 )
{
struct V_3 * V_4 = F_8 ( V_18 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
return sprintf ( V_21 , L_1 , V_6 -> V_14 ) ;
}
static T_2 F_9 ( struct V_17 * V_18 ,
struct V_19 * V_20 , const char * V_21 , T_3 V_22 )
{
struct V_3 * V_4 = F_8 ( V_18 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned V_14 ;
int V_23 ;
V_23 = sscanf ( V_21 , L_2 , & V_14 ) ;
if ( V_23 < 1 || V_14 > 255 ) {
F_10 ( V_18 , L_3 ) ;
return - V_24 ;
}
V_6 -> V_14 = V_14 ;
return V_22 ;
}
static T_2 F_11 ( struct V_17 * V_18 ,
struct V_19 * V_20 , char * V_21 )
{
struct V_3 * V_4 = F_8 ( V_18 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
return sprintf ( V_21 , L_1 , V_6 -> V_13 ) ;
}
static T_2 F_12 ( struct V_17 * V_18 ,
struct V_19 * V_20 , const char * V_21 , T_3 V_22 )
{
struct V_3 * V_4 = F_8 ( V_18 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_13 ;
int V_23 ;
V_23 = F_13 ( V_21 , 10 , & V_13 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_13 > 1 )
return - V_24 ;
V_6 -> V_13 = V_13 ;
F_2 ( & V_6 -> V_8 ) ;
return V_22 ;
}
static T_2 F_14 ( struct V_17 * V_18 ,
struct V_19 * V_20 , char * V_21 )
{
struct V_3 * V_4 = F_8 ( V_18 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
return sprintf ( V_21 , L_1 , V_6 -> V_12 ) ;
}
static T_2 F_15 ( struct V_17 * V_18 ,
struct V_19 * V_20 , const char * V_21 , T_3 V_22 )
{
struct V_3 * V_4 = F_8 ( V_18 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned V_12 ;
int V_23 ;
V_23 = sscanf ( V_21 , L_2 , & V_12 ) ;
if ( V_23 < 1 ) {
F_10 ( V_18 , L_4 ) ;
F_16 ( & V_6 -> V_8 ) ;
return - V_24 ;
}
if ( V_6 -> V_12 == V_12 )
return V_22 ;
if ( ! V_12 ) {
if ( V_6 -> V_12 != 0 )
F_17 ( F_18 ( V_6 -> V_12 ) , V_4 ) ;
V_6 -> V_12 = 0 ;
return V_22 ;
}
V_23 = F_19 ( F_18 ( V_12 ) , F_1 ,
V_25 | V_26
| V_27 , L_5 , V_4 ) ;
if ( V_23 ) {
F_10 ( V_18 , L_6 , V_23 ) ;
} else {
if ( V_6 -> V_12 != 0 )
F_17 ( F_18 ( V_6 -> V_12 ) , V_4 ) ;
V_6 -> V_12 = V_12 ;
}
return V_23 ? V_23 : V_22 ;
}
static void F_20 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_23 ;
V_6 = F_21 ( sizeof( * V_6 ) , V_28 ) ;
if ( ! V_6 )
return;
V_23 = F_22 ( V_4 -> V_18 , & V_29 ) ;
if ( V_23 )
goto V_30;
V_23 = F_22 ( V_4 -> V_18 , & V_31 ) ;
if ( V_23 )
goto V_32;
V_23 = F_22 ( V_4 -> V_18 , & V_33 ) ;
if ( V_23 )
goto V_34;
V_6 -> V_4 = V_4 ;
V_4 -> V_7 = V_6 ;
F_23 ( & V_6 -> V_8 , F_3 ) ;
V_4 -> V_35 = true ;
return;
V_34:
F_24 ( V_4 -> V_18 , & V_31 ) ;
V_32:
F_24 ( V_4 -> V_18 , & V_29 ) ;
V_30:
F_25 ( V_6 ) ;
}
static void F_26 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_4 -> V_35 ) {
F_24 ( V_4 -> V_18 , & V_29 ) ;
F_24 ( V_4 -> V_18 , & V_31 ) ;
F_24 ( V_4 -> V_18 , & V_33 ) ;
F_16 ( & V_6 -> V_8 ) ;
if ( V_6 -> V_12 != 0 )
F_17 ( F_18 ( V_6 -> V_12 ) , V_4 ) ;
F_25 ( V_6 ) ;
V_4 -> V_35 = false ;
}
}
static int T_4 F_27 ( void )
{
return F_28 ( & V_36 ) ;
}
static void T_5 F_29 ( void )
{
F_30 ( & V_36 ) ;
}
