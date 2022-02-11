static int F_1 ( struct V_1 * V_2 , unsigned long * V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_5 -> V_6 ) {
unsigned long V_7 = V_5 -> V_8 ;
if ( V_2 -> V_9 && V_7 > V_2 -> V_9 )
V_7 = V_2 -> V_9 ;
if ( V_2 -> V_10 && V_7 < V_2 -> V_10 )
V_7 = V_2 -> V_10 ;
* V_3 = V_7 ;
} else {
* V_3 = V_2 -> V_11 ;
}
return 0 ;
}
static T_1 F_2 ( struct V_12 * V_13 , struct V_14 * V_15 ,
const char * V_16 , T_2 V_17 )
{
struct V_1 * V_1 = F_3 ( V_13 ) ;
struct V_4 * V_5 ;
unsigned long V_18 ;
int V_19 = 0 ;
F_4 ( & V_1 -> V_20 ) ;
V_5 = V_1 -> V_5 ;
sscanf ( V_16 , L_1 , & V_18 ) ;
V_5 -> V_8 = V_18 ;
V_5 -> V_6 = true ;
V_19 = F_5 ( V_1 ) ;
if ( V_19 == 0 )
V_19 = V_17 ;
F_6 ( & V_1 -> V_20 ) ;
return V_19 ;
}
static T_1 F_7 ( struct V_12 * V_13 , struct V_14 * V_15 ,
char * V_16 )
{
struct V_1 * V_1 = F_3 ( V_13 ) ;
struct V_4 * V_5 ;
int V_19 = 0 ;
F_4 ( & V_1 -> V_20 ) ;
V_5 = V_1 -> V_5 ;
if ( V_5 -> V_6 )
V_19 = sprintf ( V_16 , L_2 , V_5 -> V_8 ) ;
else
V_19 = sprintf ( V_16 , L_3 ) ;
F_6 ( & V_1 -> V_20 ) ;
return V_19 ;
}
static int F_8 ( struct V_1 * V_1 )
{
int V_19 = 0 ;
struct V_4 * V_5 = F_9 ( sizeof( struct V_4 ) ,
V_21 ) ;
if ( ! V_5 ) {
V_19 = - V_22 ;
goto V_23;
}
V_5 -> V_6 = false ;
V_1 -> V_5 = V_5 ;
V_19 = F_10 ( & V_1 -> V_13 . V_24 , & V_25 ) ;
V_23:
return V_19 ;
}
static void F_11 ( struct V_1 * V_1 )
{
if ( V_1 -> V_13 . V_24 . V_26 )
F_12 ( & V_1 -> V_13 . V_24 , & V_25 ) ;
F_13 ( V_1 -> V_5 ) ;
V_1 -> V_5 = NULL ;
}
static int F_14 ( struct V_1 * V_1 ,
unsigned int V_27 , void * V_5 )
{
int V_28 = 0 ;
switch ( V_27 ) {
case V_29 :
V_28 = F_8 ( V_1 ) ;
break;
case V_30 :
F_11 ( V_1 ) ;
break;
default:
break;
}
return V_28 ;
}
static int T_3 F_15 ( void )
{
return F_16 ( & V_31 ) ;
}
static void T_4 F_17 ( void )
{
int V_28 ;
V_28 = F_18 ( & V_31 ) ;
if ( V_28 )
F_19 ( L_4 , V_32 , V_28 ) ;
return;
}
