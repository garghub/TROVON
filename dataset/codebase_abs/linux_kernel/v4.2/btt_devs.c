static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
F_2 ( & V_1 -> V_4 , ! F_3 ( & V_3 -> V_4 . V_5 )
|| V_3 -> V_6 != & V_1 -> V_4 ,
L_1 , V_7 ) ;
V_3 -> V_6 = NULL ;
V_1 -> V_3 = NULL ;
F_4 ( & V_3 -> V_4 ) ;
}
static void F_5 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
if ( ! V_3 )
return;
F_6 ( & V_3 -> V_4 ) ;
F_7 ( & V_3 -> V_4 ) ;
F_1 ( V_1 ) ;
F_8 ( & V_3 -> V_4 ) ;
F_4 ( & V_3 -> V_4 ) ;
}
static bool F_9 ( struct V_1 * V_1 ,
struct V_2 * V_3 )
{
if ( V_3 -> V_6 )
return false ;
F_2 ( & V_1 -> V_4 , ! F_3 ( & V_3 -> V_4 . V_5 )
|| V_1 -> V_3 ,
L_1 , V_7 ) ;
V_3 -> V_6 = & V_1 -> V_4 ;
V_1 -> V_3 = V_3 ;
F_6 ( & V_3 -> V_4 ) ;
return true ;
}
static bool F_10 ( struct V_1 * V_1 ,
struct V_2 * V_3 )
{
bool V_8 ;
F_7 ( & V_3 -> V_4 ) ;
V_8 = F_9 ( V_1 , V_3 ) ;
F_8 ( & V_3 -> V_4 ) ;
return V_8 ;
}
static void F_11 ( struct V_9 * V_4 )
{
struct V_10 * V_10 = F_12 ( V_4 -> V_11 ) ;
struct V_1 * V_1 = F_13 ( V_4 ) ;
F_14 ( V_4 , L_2 , V_7 ) ;
F_5 ( V_1 ) ;
F_15 ( & V_10 -> V_12 , V_1 -> V_13 ) ;
F_16 ( V_1 -> V_14 ) ;
F_16 ( V_1 ) ;
}
bool F_17 ( struct V_9 * V_4 )
{
return V_4 -> type == & V_15 ;
}
struct V_1 * F_13 ( struct V_9 * V_4 )
{
struct V_1 * V_1 = F_18 ( V_4 , struct V_1 , V_4 ) ;
F_19 ( ! F_17 ( V_4 ) ) ;
return V_1 ;
}
static T_1 F_20 ( struct V_9 * V_4 ,
struct V_16 * V_17 , char * V_18 )
{
struct V_1 * V_1 = F_13 ( V_4 ) ;
return F_21 ( V_1 -> V_19 , V_20 , V_18 ) ;
}
static T_1 F_22 ( struct V_9 * V_4 ,
struct V_16 * V_17 , const char * V_18 , T_2 V_21 )
{
struct V_1 * V_1 = F_13 ( V_4 ) ;
T_1 V_22 ;
F_7 ( V_4 ) ;
F_23 ( V_4 ) ;
V_22 = F_24 ( V_4 , V_18 , & V_1 -> V_19 ,
V_20 ) ;
F_14 ( V_4 , L_3 , V_7 ,
V_22 , V_18 , V_18 [ V_21 - 1 ] == '\n' ? L_4 : L_5 ) ;
F_25 ( V_4 ) ;
F_8 ( V_4 ) ;
return V_22 ? V_22 : V_21 ;
}
static T_1 F_26 ( struct V_9 * V_4 ,
struct V_16 * V_17 , char * V_18 )
{
struct V_1 * V_1 = F_13 ( V_4 ) ;
if ( V_1 -> V_14 )
return sprintf ( V_18 , L_6 , V_1 -> V_14 ) ;
return sprintf ( V_18 , L_5 ) ;
}
static T_1 F_27 ( struct V_9 * V_4 ,
struct V_16 * V_17 , const char * V_18 , T_2 V_21 )
{
struct V_1 * V_1 = F_13 ( V_4 ) ;
T_1 V_22 ;
F_7 ( V_4 ) ;
V_22 = F_28 ( V_4 , & V_1 -> V_14 , V_18 , V_21 ) ;
F_14 ( V_4 , L_3 , V_7 ,
V_22 , V_18 , V_18 [ V_21 - 1 ] == '\n' ? L_4 : L_5 ) ;
F_8 ( V_4 ) ;
return V_22 ? V_22 : V_21 ;
}
static T_1 F_29 ( struct V_9 * V_4 ,
struct V_16 * V_17 , char * V_18 )
{
struct V_1 * V_1 = F_13 ( V_4 ) ;
T_1 V_22 ;
F_23 ( V_4 ) ;
V_22 = sprintf ( V_18 , L_2 , V_1 -> V_3
? F_30 ( & V_1 -> V_3 -> V_4 ) : L_4 ) ;
F_25 ( V_4 ) ;
return V_22 ;
}
static int F_31 ( struct V_9 * V_4 , void * V_23 )
{
char * V_24 = V_23 ;
return strcmp ( V_24 , F_30 ( V_4 ) ) == 0 ;
}
static bool F_32 ( struct V_9 * V_4 )
{
struct V_10 * V_10 = F_12 ( V_4 -> V_11 ) ;
struct V_1 * V_1 = F_13 ( V_4 ) ;
if ( V_10 -> V_25 == V_4 || V_1 -> V_3 || V_4 -> V_26 )
return false ;
return true ;
}
static T_1 F_33 ( struct V_9 * V_4 ,
struct V_16 * V_17 , const char * V_18 , T_2 V_21 )
{
struct V_1 * V_1 = F_13 ( V_4 ) ;
struct V_2 * V_3 ;
struct V_9 * V_27 ;
char * V_24 ;
if ( V_4 -> V_26 ) {
F_14 ( V_4 , L_7 , V_7 ) ;
return - V_28 ;
}
V_24 = F_34 ( V_18 , V_21 , V_29 ) ;
if ( ! V_24 )
return - V_30 ;
F_35 ( V_24 ) ;
if ( strncmp ( V_24 , L_8 , 9 ) == 0 || strcmp ( V_24 , L_4 ) == 0 )
;
else {
V_21 = - V_31 ;
goto V_32;
}
V_3 = V_1 -> V_3 ;
if ( strcmp ( V_24 , L_4 ) == 0 ) {
F_5 ( V_1 ) ;
if ( F_32 ( V_4 ) )
F_36 ( V_4 , V_33 ) ;
else {
V_1 -> V_19 = 0 ;
F_16 ( V_1 -> V_14 ) ;
V_1 -> V_14 = NULL ;
}
goto V_32;
} else if ( V_3 ) {
F_14 ( V_4 , L_9 ,
F_30 ( & V_3 -> V_4 ) ) ;
V_21 = - V_28 ;
goto V_32;
}
V_27 = F_37 ( V_4 -> V_11 , V_24 , F_31 ) ;
if ( ! V_27 ) {
F_14 ( V_4 , L_10 , V_24 ,
F_30 ( V_4 -> V_11 ) ) ;
V_21 = - V_34 ;
goto V_32;
}
V_3 = F_38 ( V_27 ) ;
if ( F_39 ( V_3 ) < V_35 ) {
F_14 ( V_4 , L_11 , V_24 ) ;
V_21 = - V_36 ;
goto V_37;
}
F_40 ( ! F_41 ( & V_1 -> V_4 ) ) ;
if ( ! F_10 ( V_1 , V_3 ) ) {
F_14 ( V_4 , L_12 ,
F_30 ( & V_3 -> V_4 ) ) ;
V_21 = - V_28 ;
}
V_37:
F_4 ( & V_3 -> V_4 ) ;
V_32:
F_16 ( V_24 ) ;
return V_21 ;
}
static T_1 F_42 ( struct V_9 * V_4 ,
struct V_16 * V_17 , const char * V_18 , T_2 V_21 )
{
T_1 V_22 ;
F_23 ( V_4 ) ;
F_7 ( V_4 ) ;
V_22 = F_33 ( V_4 , V_17 , V_18 , V_21 ) ;
F_14 ( V_4 , L_3 , V_7 ,
V_22 , V_18 , V_18 [ V_21 - 1 ] == '\n' ? L_4 : L_5 ) ;
F_8 ( V_4 ) ;
F_25 ( V_4 ) ;
return V_22 ;
}
static struct V_9 * F_43 ( struct V_10 * V_10 ,
unsigned long V_19 , T_3 * V_14 ,
struct V_2 * V_3 )
{
struct V_1 * V_1 ;
struct V_9 * V_4 ;
V_1 = F_44 ( sizeof( * V_1 ) , V_29 ) ;
if ( ! V_1 )
return NULL ;
V_1 -> V_13 = F_45 ( & V_10 -> V_12 , 0 , 0 , V_29 ) ;
if ( V_1 -> V_13 < 0 ) {
F_16 ( V_1 ) ;
return NULL ;
}
V_1 -> V_19 = V_19 ;
if ( V_14 )
V_14 = F_46 ( V_14 , 16 , V_29 ) ;
V_1 -> V_14 = V_14 ;
V_4 = & V_1 -> V_4 ;
F_47 ( V_4 , L_13 , V_10 -> V_13 , V_1 -> V_13 ) ;
V_4 -> V_11 = & V_10 -> V_4 ;
V_4 -> type = & V_15 ;
V_4 -> V_38 = V_39 ;
F_48 ( & V_1 -> V_4 ) ;
if ( V_3 && ! F_9 ( V_1 , V_3 ) ) {
F_14 ( & V_3 -> V_4 , L_14 ,
V_7 , F_30 ( V_3 -> V_6 ) ) ;
F_4 ( V_4 ) ;
return NULL ;
}
return V_4 ;
}
struct V_9 * F_49 ( struct V_10 * V_10 )
{
struct V_9 * V_4 = F_43 ( V_10 , 0 , NULL , NULL ) ;
if ( V_4 )
F_50 ( V_4 ) ;
return V_4 ;
}
T_4 F_51 ( struct V_40 * V_40 )
{
T_4 V_41 ;
T_5 V_42 ;
V_42 = V_40 -> V_43 ;
V_40 -> V_43 = 0 ;
V_41 = F_52 ( V_40 , sizeof( * V_40 ) , 1 ) ;
V_40 -> V_43 = V_42 ;
return V_41 ;
}
static int F_53 ( struct V_1 * V_1 ,
struct V_2 * V_3 , struct V_40 * V_40 )
{
T_4 V_43 ;
if ( ! V_40 || ! V_3 || ! V_1 )
return - V_34 ;
if ( F_54 ( V_3 , V_44 , V_40 , sizeof( * V_40 ) ) )
return - V_36 ;
if ( F_55 ( V_3 ) < V_35 )
return - V_36 ;
if ( memcmp ( V_40 -> V_45 , V_46 , V_47 ) != 0 )
return - V_34 ;
V_43 = F_56 ( V_40 -> V_43 ) ;
V_40 -> V_43 = 0 ;
if ( V_43 != F_51 ( V_40 ) )
return - V_34 ;
V_40 -> V_43 = F_57 ( V_43 ) ;
V_1 -> V_19 = F_58 ( V_40 -> V_48 ) ;
V_1 -> V_14 = F_46 ( V_40 -> V_14 , 16 , V_29 ) ;
if ( ! V_1 -> V_14 )
return - V_30 ;
F_50 ( & V_1 -> V_4 ) ;
return 0 ;
}
int F_59 ( struct V_2 * V_3 , void * V_49 )
{
int V_22 ;
struct V_9 * V_4 ;
struct V_40 * V_40 ;
struct V_10 * V_10 = F_12 ( V_3 -> V_4 . V_11 ) ;
if ( V_3 -> V_50 )
return - V_34 ;
F_23 ( & V_3 -> V_4 ) ;
V_4 = F_43 ( V_10 , 0 , NULL , V_3 ) ;
F_25 ( & V_3 -> V_4 ) ;
if ( ! V_4 )
return - V_30 ;
F_60 ( V_4 , V_49 ) ;
V_40 = F_44 ( sizeof( * V_40 ) , V_29 ) ;
V_22 = F_53 ( F_13 ( V_4 ) , V_3 , V_40 ) ;
F_16 ( V_40 ) ;
F_14 ( & V_3 -> V_4 , L_15 , V_7 ,
V_22 == 0 ? F_30 ( V_4 ) : L_16 ) ;
if ( V_22 < 0 ) {
F_1 ( F_13 ( V_4 ) ) ;
F_4 ( V_4 ) ;
}
return V_22 ;
}
