static T_1 F_1 ( struct V_1 * V_2 ,
const void * V_3 , T_2 V_4 )
{
const struct V_5 * V_6 = V_3 ;
struct V_7 * V_8 ;
int V_9 ;
V_8 = F_2 ( V_2 , struct V_7 , V_2 ) ;
if ( V_8 -> V_6 ) {
F_3 ( L_1 ) ;
return - V_10 ;
}
if ( V_6 -> V_11 != V_4 ) {
F_3 ( L_2 ) ;
return - V_12 ;
}
if ( memcmp ( V_6 -> V_13 , V_14 , 4 ) ) {
F_3 ( L_3 ) ;
return - V_12 ;
}
V_8 = F_2 ( V_2 , struct V_7 , V_2 ) ;
V_8 -> V_6 = F_4 ( V_6 , V_6 -> V_11 , V_15 ) ;
if ( ! V_8 -> V_6 )
return - V_16 ;
V_9 = F_5 ( V_8 -> V_6 ) ;
if ( V_9 ) {
F_6 ( V_8 -> V_6 ) ;
V_8 -> V_6 = NULL ;
}
return V_9 ;
}
static inline struct V_5 * F_7 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 , struct V_7 , V_2 ) ;
if ( ! V_8 -> V_6 )
F_3 ( L_4 ) ;
return V_8 -> V_6 ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
void * V_3 , T_2 V_4 )
{
struct V_5 * V_17 = F_7 ( V_2 ) ;
if ( ! V_17 )
return - V_12 ;
if ( V_3 )
memcpy ( V_3 , V_17 , V_17 -> V_11 ) ;
return V_17 -> V_11 ;
}
T_1 F_9 ( struct V_1 * V_2 , char * V_18 )
{
struct V_5 * V_17 = F_7 ( V_2 ) ;
if ( ! V_17 )
return - V_12 ;
return sprintf ( V_18 , L_5 , V_19 , V_17 -> V_13 ) ;
}
T_1 F_10 ( struct V_1 * V_2 , char * V_18 )
{
struct V_5 * V_17 = F_7 ( V_2 ) ;
if ( ! V_17 )
return - V_12 ;
return sprintf ( V_18 , L_6 , V_17 -> V_11 ) ;
}
T_1 F_11 ( struct V_1 * V_2 , char * V_18 )
{
struct V_5 * V_17 = F_7 ( V_2 ) ;
if ( ! V_17 )
return - V_12 ;
return sprintf ( V_18 , L_6 , V_17 -> V_20 ) ;
}
T_1 F_12 ( struct V_1 * V_2 , char * V_18 )
{
struct V_5 * V_17 = F_7 ( V_2 ) ;
if ( ! V_17 )
return - V_12 ;
return sprintf ( V_18 , L_5 , V_21 , V_17 -> V_22 ) ;
}
T_1 F_13 ( struct V_1 * V_2 , char * V_18 )
{
struct V_5 * V_17 = F_7 ( V_2 ) ;
if ( ! V_17 )
return - V_12 ;
return sprintf ( V_18 , L_5 , V_23 , V_17 -> V_24 ) ;
}
T_1 F_14 ( struct V_1 * V_2 , char * V_18 )
{
struct V_5 * V_17 = F_7 ( V_2 ) ;
if ( ! V_17 )
return - V_12 ;
return sprintf ( V_18 , L_6 , V_17 -> V_25 ) ;
}
T_1 F_15 ( struct V_1 * V_2 , char * V_18 )
{
struct V_5 * V_17 = F_7 ( V_2 ) ;
if ( ! V_17 )
return - V_12 ;
return sprintf ( V_18 , L_5 , V_19 , V_17 -> V_26 ) ;
}
T_1 F_16 ( struct V_1 * V_2 ,
char * V_18 )
{
struct V_5 * V_17 = F_7 ( V_2 ) ;
if ( ! V_17 )
return - V_12 ;
return sprintf ( V_18 , L_6 , V_17 -> V_27 ) ;
}
static struct V_1 * F_17 ( struct V_28 * V_29 ,
const char * V_30 )
{
struct V_7 * V_8 ;
V_8 = F_18 ( sizeof( * V_8 ) , V_15 ) ;
if ( ! V_8 )
return F_19 ( - V_16 ) ;
F_20 ( & V_8 -> V_2 , V_30 , & V_31 ) ;
return & V_8 -> V_2 ;
}
static int T_3 F_21 ( void )
{
int V_9 ;
struct V_28 * V_32 = & V_33 . V_34 ;
F_22 ( V_32 ) ;
V_9 = F_23 ( & V_33 ) ;
if ( V_9 )
return V_9 ;
V_35 = F_24 ( V_32 , L_7 ,
& V_36 ) ;
return F_25 ( V_35 ) ;
}
static void T_4 F_26 ( void )
{
F_27 ( V_35 ) ;
F_28 ( & V_33 ) ;
}
