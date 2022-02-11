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
F_5 ( ( L_4 ) ) ;
V_9 = F_6 (
F_7 ( V_8 -> V_6 ) ,
V_17 , FALSE ,
& V_8 -> V_18 ) ;
if ( V_9 ) {
F_8 ( V_8 -> V_6 ) ;
V_8 -> V_6 = NULL ;
}
return V_9 ;
}
static inline struct V_5 * F_9 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 , struct V_7 , V_2 ) ;
if ( ! V_8 -> V_6 )
F_3 ( L_5 ) ;
return V_8 -> V_6 ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
void * V_3 , T_2 V_4 )
{
struct V_5 * V_19 = F_9 ( V_2 ) ;
if ( ! V_19 )
return - V_12 ;
if ( V_3 )
memcpy ( V_3 , V_19 , V_19 -> V_11 ) ;
return V_19 -> V_11 ;
}
T_1 F_11 ( struct V_1 * V_2 , char * V_20 )
{
struct V_5 * V_19 = F_9 ( V_2 ) ;
if ( ! V_19 )
return - V_12 ;
return sprintf ( V_20 , L_6 , V_21 , V_19 -> V_13 ) ;
}
T_1 F_12 ( struct V_1 * V_2 , char * V_20 )
{
struct V_5 * V_19 = F_9 ( V_2 ) ;
if ( ! V_19 )
return - V_12 ;
return sprintf ( V_20 , L_7 , V_19 -> V_11 ) ;
}
T_1 F_13 ( struct V_1 * V_2 , char * V_20 )
{
struct V_5 * V_19 = F_9 ( V_2 ) ;
if ( ! V_19 )
return - V_12 ;
return sprintf ( V_20 , L_7 , V_19 -> V_22 ) ;
}
T_1 F_14 ( struct V_1 * V_2 , char * V_20 )
{
struct V_5 * V_19 = F_9 ( V_2 ) ;
if ( ! V_19 )
return - V_12 ;
return sprintf ( V_20 , L_6 , V_23 , V_19 -> V_24 ) ;
}
T_1 F_15 ( struct V_1 * V_2 , char * V_20 )
{
struct V_5 * V_19 = F_9 ( V_2 ) ;
if ( ! V_19 )
return - V_12 ;
return sprintf ( V_20 , L_6 , V_25 , V_19 -> V_26 ) ;
}
T_1 F_16 ( struct V_1 * V_2 , char * V_20 )
{
struct V_5 * V_19 = F_9 ( V_2 ) ;
if ( ! V_19 )
return - V_12 ;
return sprintf ( V_20 , L_7 , V_19 -> V_27 ) ;
}
T_1 F_17 ( struct V_1 * V_2 , char * V_20 )
{
struct V_5 * V_19 = F_9 ( V_2 ) ;
if ( ! V_19 )
return - V_12 ;
return sprintf ( V_20 , L_6 , V_21 , V_19 -> V_28 ) ;
}
T_1 F_18 ( struct V_1 * V_2 ,
char * V_20 )
{
struct V_5 * V_19 = F_9 ( V_2 ) ;
if ( ! V_19 )
return - V_12 ;
return sprintf ( V_20 , L_7 , V_19 -> V_29 ) ;
}
static struct V_1 * F_19 ( struct V_30 * V_31 ,
const char * V_32 )
{
struct V_7 * V_8 ;
V_8 = F_20 ( sizeof( * V_8 ) , V_15 ) ;
if ( ! V_8 )
return F_21 ( - V_16 ) ;
F_22 ( & V_8 -> V_2 , V_32 , & V_33 ) ;
return & V_8 -> V_2 ;
}
static void F_23 ( struct V_30 * V_31 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 , struct V_7 , V_2 ) ;
F_5 ( ( L_8 ) ) ;
F_24 ( V_8 -> V_18 ) ;
}
static int T_3 F_25 ( void )
{
int V_9 ;
struct V_30 * V_34 = & V_35 . V_36 ;
F_26 ( V_34 ) ;
V_9 = F_27 ( & V_35 ) ;
if ( V_9 )
return V_9 ;
V_37 = F_28 ( V_34 , L_9 ,
& V_38 ) ;
return F_29 ( V_37 ) ;
}
static void T_4 F_30 ( void )
{
F_31 ( V_37 ) ;
F_32 ( & V_35 ) ;
}
