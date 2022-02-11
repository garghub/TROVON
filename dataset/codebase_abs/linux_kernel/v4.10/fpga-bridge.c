static int F_1 ( struct V_1 * V_2 , const void * V_3 )
{
return V_2 -> V_4 == V_3 ;
}
int F_2 ( struct V_5 * V_6 )
{
F_3 ( & V_6 -> V_2 , L_1 ) ;
if ( V_6 -> V_7 && V_6 -> V_7 -> V_8 )
return V_6 -> V_7 -> V_8 ( V_6 , 1 ) ;
return 0 ;
}
int F_4 ( struct V_5 * V_6 )
{
F_3 ( & V_6 -> V_2 , L_2 ) ;
if ( V_6 -> V_7 && V_6 -> V_7 -> V_8 )
return V_6 -> V_7 -> V_8 ( V_6 , 0 ) ;
return 0 ;
}
struct V_5 * F_5 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
int V_13 = - V_14 ;
V_2 = F_6 ( V_15 , NULL , V_10 ,
F_1 ) ;
if ( ! V_2 )
goto V_16;
V_6 = F_7 ( V_2 ) ;
if ( ! V_6 )
goto V_16;
V_6 -> V_12 = V_12 ;
if ( ! F_8 ( & V_6 -> V_17 ) ) {
V_13 = - V_18 ;
goto V_16;
}
if ( ! F_9 ( V_2 -> V_19 -> V_20 -> V_21 ) )
goto V_22;
F_3 ( & V_6 -> V_2 , L_3 ) ;
return V_6 ;
V_22:
F_10 ( & V_6 -> V_17 ) ;
V_16:
F_11 ( V_2 ) ;
return F_12 ( V_13 ) ;
}
void F_13 ( struct V_5 * V_6 )
{
F_3 ( & V_6 -> V_2 , L_4 ) ;
V_6 -> V_12 = NULL ;
F_14 ( V_6 -> V_2 . V_19 -> V_20 -> V_21 ) ;
F_10 ( & V_6 -> V_17 ) ;
F_11 ( & V_6 -> V_2 ) ;
}
int F_15 ( struct V_23 * V_24 )
{
struct V_5 * V_6 ;
struct V_23 * V_25 ;
int V_13 ;
F_16 (node, bridge_list) {
V_6 = F_17 ( V_25 , struct V_5 , V_25 ) ;
V_13 = F_2 ( V_6 ) ;
if ( V_13 )
return V_13 ;
}
return 0 ;
}
int F_18 ( struct V_23 * V_24 )
{
struct V_5 * V_6 ;
struct V_23 * V_25 ;
int V_13 ;
F_16 (node, bridge_list) {
V_6 = F_17 ( V_25 , struct V_5 , V_25 ) ;
V_13 = F_4 ( V_6 ) ;
if ( V_13 )
return V_13 ;
}
return 0 ;
}
void F_19 ( struct V_23 * V_24 )
{
struct V_5 * V_6 ;
struct V_23 * V_25 , * V_26 ;
unsigned long V_27 ;
F_20 (node, next, bridge_list) {
V_6 = F_17 ( V_25 , struct V_5 , V_25 ) ;
F_13 ( V_6 ) ;
F_21 ( & V_28 , V_27 ) ;
F_22 ( & V_6 -> V_25 ) ;
F_23 ( & V_28 , V_27 ) ;
}
}
int F_24 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
struct V_23 * V_24 )
{
struct V_5 * V_6 ;
unsigned long V_27 ;
V_6 = F_5 ( V_10 , V_12 ) ;
if ( F_25 ( V_6 ) )
return F_26 ( V_6 ) ;
F_21 ( & V_28 , V_27 ) ;
F_27 ( & V_6 -> V_25 , V_24 ) ;
F_23 ( & V_28 , V_27 ) ;
return 0 ;
}
static T_1 F_28 ( struct V_1 * V_2 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_5 * V_6 = F_7 ( V_2 ) ;
return sprintf ( V_31 , L_5 , V_6 -> V_32 ) ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_5 * V_6 = F_7 ( V_2 ) ;
int V_33 = 1 ;
if ( V_6 -> V_7 && V_6 -> V_7 -> V_34 )
V_33 = V_6 -> V_7 -> V_34 ( V_6 ) ;
return sprintf ( V_31 , L_5 , V_33 ? L_6 : L_7 ) ;
}
int F_30 ( struct V_1 * V_2 , const char * V_32 ,
const struct V_35 * V_7 , void * V_36 )
{
struct V_5 * V_6 ;
int V_37 , V_13 = 0 ;
if ( ! V_32 || ! strlen ( V_32 ) ) {
F_31 ( V_2 , L_8 ) ;
return - V_38 ;
}
V_6 = F_32 ( sizeof( * V_6 ) , V_39 ) ;
if ( ! V_6 )
return - V_40 ;
V_37 = F_33 ( & V_41 , 0 , 0 , V_39 ) ;
if ( V_37 < 0 ) {
V_13 = V_37 ;
goto V_42;
}
F_34 ( & V_6 -> V_17 ) ;
F_35 ( & V_6 -> V_25 ) ;
V_6 -> V_32 = V_32 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_36 = V_36 ;
F_36 ( & V_6 -> V_2 ) ;
V_6 -> V_2 . V_43 = V_15 ;
V_6 -> V_2 . V_19 = V_2 ;
V_6 -> V_2 . V_4 = V_2 -> V_4 ;
V_6 -> V_2 . V_37 = V_37 ;
F_37 ( V_2 , V_6 ) ;
V_13 = F_38 ( & V_6 -> V_2 , L_9 , V_37 ) ;
if ( V_13 )
goto V_44;
V_13 = F_39 ( & V_6 -> V_2 ) ;
if ( V_13 )
goto V_44;
F_40 ( V_2 -> V_4 , NULL , NULL , V_2 ) ;
F_41 ( V_6 -> V_2 . V_19 , L_10 ,
V_6 -> V_32 ) ;
return 0 ;
V_44:
F_42 ( & V_41 , V_37 ) ;
V_42:
F_43 ( V_6 ) ;
return V_13 ;
}
void F_44 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_45 ( V_2 ) ;
if ( V_6 -> V_7 && V_6 -> V_7 -> V_45 )
V_6 -> V_7 -> V_45 ( V_6 ) ;
F_46 ( & V_6 -> V_2 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_7 ( V_2 ) ;
F_42 ( & V_41 , V_6 -> V_2 . V_37 ) ;
F_43 ( V_6 ) ;
}
static int T_2 F_48 ( void )
{
F_49 ( & V_28 ) ;
V_15 = F_50 ( V_46 , L_11 ) ;
if ( F_25 ( V_15 ) )
return F_26 ( V_15 ) ;
V_15 -> V_47 = V_48 ;
V_15 -> V_49 = F_47 ;
return 0 ;
}
static void T_3 F_51 ( void )
{
F_52 ( V_15 ) ;
F_53 ( & V_41 ) ;
}
