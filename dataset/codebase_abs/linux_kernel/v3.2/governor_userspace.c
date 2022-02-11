static int F_1 ( struct V_1 * V_2 , unsigned long * V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( ! V_5 -> V_6 )
* V_3 = V_2 -> V_7 ;
else
* V_3 = V_5 -> V_8 ;
return 0 ;
}
static T_1 F_2 ( struct V_9 * V_10 , struct V_11 * V_12 ,
const char * V_13 , T_2 V_14 )
{
struct V_1 * V_1 = F_3 ( V_10 ) ;
struct V_4 * V_5 ;
unsigned long V_15 ;
int V_16 = 0 ;
F_4 ( & V_1 -> V_17 ) ;
V_5 = V_1 -> V_5 ;
sscanf ( V_13 , L_1 , & V_15 ) ;
V_5 -> V_8 = V_15 ;
V_5 -> V_6 = true ;
V_16 = F_5 ( V_1 ) ;
if ( V_16 == 0 )
V_16 = V_14 ;
F_6 ( & V_1 -> V_17 ) ;
return V_16 ;
}
static T_1 F_7 ( struct V_9 * V_10 , struct V_11 * V_12 ,
char * V_13 )
{
struct V_1 * V_1 = F_3 ( V_10 ) ;
struct V_4 * V_5 ;
int V_16 = 0 ;
F_4 ( & V_1 -> V_17 ) ;
V_5 = V_1 -> V_5 ;
if ( V_5 -> V_6 )
V_16 = sprintf ( V_13 , L_2 , V_5 -> V_8 ) ;
else
V_16 = sprintf ( V_13 , L_3 ) ;
F_6 ( & V_1 -> V_17 ) ;
return V_16 ;
}
static int F_8 ( struct V_1 * V_1 )
{
int V_16 = 0 ;
struct V_4 * V_5 = F_9 ( sizeof( struct V_4 ) ,
V_18 ) ;
if ( ! V_5 ) {
V_16 = - V_19 ;
goto V_20;
}
V_5 -> V_6 = false ;
V_1 -> V_5 = V_5 ;
V_16 = F_10 ( & V_1 -> V_10 . V_21 , & V_22 ) ;
V_20:
return V_16 ;
}
static void F_11 ( struct V_1 * V_1 )
{
F_12 ( & V_1 -> V_10 . V_21 , & V_22 ) ;
F_13 ( V_1 -> V_5 ) ;
V_1 -> V_5 = NULL ;
}
