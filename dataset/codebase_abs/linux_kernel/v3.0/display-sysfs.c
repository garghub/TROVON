static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return snprintf ( V_5 , V_8 , L_1 , V_7 -> V_9 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return snprintf ( V_5 , V_8 , L_1 , V_7 -> type ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_10 = - V_11 ;
F_5 ( & V_7 -> V_12 ) ;
if ( F_6 ( V_7 -> V_13 ) && V_7 -> V_13 -> V_14 )
V_10 = sprintf ( V_5 , L_2 , V_7 -> V_13 -> V_14 ( V_7 ) ) ;
F_7 ( & V_7 -> V_12 ) ;
return V_10 ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_15 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_16 = - V_17 , V_18 ;
int V_19 ;
char * V_20 ;
V_19 = F_9 ( V_5 , & V_20 , 0 ) ;
V_18 = V_20 - V_5 ;
if ( isspace ( * V_20 ) )
V_18 ++ ;
if ( V_18 != V_15 )
return V_16 ;
F_5 ( & V_7 -> V_12 ) ;
if ( F_6 ( V_7 -> V_13 && V_7 -> V_13 -> V_21 ) ) {
F_10 ( L_3 , V_19 ) ;
V_7 -> V_13 -> V_21 ( V_7 , V_19 ) ;
V_16 = V_15 ;
}
F_7 ( & V_7 -> V_12 ) ;
return V_16 ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_10 = - V_11 ;
F_5 ( & V_7 -> V_12 ) ;
if ( F_6 ( V_7 -> V_13 ) )
V_10 = sprintf ( V_5 , L_2 , V_7 -> V_13 -> V_22 ) ;
F_7 ( & V_7 -> V_12 ) ;
return V_10 ;
}
static int F_12 ( struct V_1 * V_2 , T_3 V_23 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_5 ( & V_7 -> V_12 ) ;
if ( F_6 ( V_7 -> V_13 -> V_24 ) )
V_7 -> V_13 -> V_24 ( V_7 , V_23 ) ;
F_7 ( & V_7 -> V_12 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_5 ( & V_7 -> V_12 ) ;
if ( F_6 ( V_7 -> V_13 -> V_25 ) )
V_7 -> V_13 -> V_25 ( V_7 ) ;
F_7 ( & V_7 -> V_12 ) ;
return 0 ;
}
struct V_6 * F_14 ( struct V_26 * V_13 ,
struct V_1 * V_27 , void * V_28 )
{
struct V_6 * V_29 = NULL ;
int V_16 = - V_17 ;
if ( F_15 ( ! V_13 ) )
return F_16 ( V_16 ) ;
F_5 ( & V_30 ) ;
V_16 = F_17 ( & V_31 , V_32 ) ;
F_7 ( & V_30 ) ;
if ( ! V_16 )
return F_16 ( V_16 ) ;
V_29 = F_18 ( sizeof( struct V_6 ) , V_32 ) ;
if ( F_6 ( V_29 ) && F_15 ( V_13 -> V_33 ( V_29 , V_28 ) ) ) {
F_5 ( & V_30 ) ;
V_16 = F_19 ( & V_31 , V_29 , & V_29 -> V_34 ) ;
F_7 ( & V_30 ) ;
if ( ! V_16 ) {
V_29 -> V_2 = F_20 ( V_35 , V_27 ,
F_21 ( 0 , 0 ) , V_29 ,
L_4 , V_29 -> V_34 ) ;
if ( ! F_22 ( V_29 -> V_2 ) ) {
V_29 -> V_27 = V_27 ;
V_29 -> V_13 = V_13 ;
F_23 ( & V_29 -> V_12 ) ;
return V_29 ;
}
F_5 ( & V_30 ) ;
F_24 ( & V_31 , V_29 -> V_34 ) ;
F_7 ( & V_30 ) ;
V_16 = - V_17 ;
}
}
F_25 ( V_29 ) ;
return F_16 ( V_16 ) ;
}
void F_26 ( struct V_6 * V_36 )
{
if ( ! V_36 )
return;
F_5 ( & V_36 -> V_12 ) ;
F_27 ( V_36 -> V_2 ) ;
F_7 ( & V_36 -> V_12 ) ;
F_5 ( & V_30 ) ;
F_24 ( & V_31 , V_36 -> V_34 ) ;
F_7 ( & V_30 ) ;
F_25 ( V_36 ) ;
}
static int T_4 F_28 ( void )
{
V_35 = F_29 ( V_37 , L_5 ) ;
if ( F_22 ( V_35 ) ) {
F_30 ( V_38 L_6 ) ;
V_35 = NULL ;
return - V_17 ;
}
V_35 -> V_39 = V_40 ;
V_35 -> V_24 = F_12 ;
V_35 -> V_25 = F_13 ;
F_23 ( & V_30 ) ;
return 0 ;
}
static void T_5 F_31 ( void )
{
F_32 ( V_35 ) ;
}
