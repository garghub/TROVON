static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 , V_4 ) ;
}
static inline struct V_5 * F_4 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_5 , V_4 ) ;
}
static T_1 F_5 ( struct V_2 * V_3 , const char * V_6 ,
T_2 V_7 )
{
int V_8 ;
bool V_9 ;
struct V_10 * V_11 ;
struct V_5 * V_12 = F_4 ( V_3 ) ;
V_11 = V_12 -> V_11 ;
V_8 = F_6 ( V_6 , & V_9 ) ;
if ( V_8 )
return V_8 ;
if ( ! V_9 ) {
F_7 ( V_11 ) ;
return V_7 ;
}
V_8 = F_8 ( V_11 ) ;
if ( V_8 ) {
F_9 ( & V_11 -> V_13 , L_1 ) ;
return - V_14 ;
}
V_12 -> V_9 = V_9 ;
return V_7 ;
}
static T_1 F_10 ( struct V_2 * V_3 , char * V_6 )
{
return sprintf ( V_6 , L_2 ,
F_4 ( V_3 ) -> V_9 ) ;
}
static int F_11 ( struct V_2 * V_15 ,
struct V_2 * V_16 )
{
int V_8 ;
T_3 V_17 = 0 ;
struct V_10 * V_11 ;
struct V_18 * V_19 ;
struct V_1 * V_20 = F_1 ( V_16 ) ;
struct V_5 * V_12 = F_4 ( V_15 ) ;
V_11 = V_12 -> V_11 ;
V_19 = V_20 -> V_19 ;
V_8 = F_12 ( V_11 , V_19 ) ;
if ( V_8 )
goto V_21;
V_17 = F_13 ( & V_12 -> V_22 ,
sizeof( V_12 -> V_22 ) ) ;
F_14 ( V_17 , & V_12 -> V_22 ) ;
V_19 -> V_17 = V_17 ;
V_8 = F_15 ( V_19 ) ;
if ( V_8 )
goto V_23;
return 0 ;
V_23:
F_16 ( V_11 , V_19 ) ;
V_21:
F_17 ( V_17 , & V_12 -> V_22 ) ;
return V_8 ;
}
static void F_18 ( struct V_2 * V_15 ,
struct V_2 * V_16 )
{
struct V_10 * V_11 ;
struct V_18 * V_19 ;
struct V_1 * V_20 = F_1 ( V_16 ) ;
struct V_5 * V_12 = F_4 ( V_15 ) ;
F_19 ( V_12 -> V_9 ) ;
V_11 = V_12 -> V_11 ;
V_19 = V_20 -> V_19 ;
F_17 ( V_19 -> V_17 , & V_12 -> V_22 ) ;
F_20 ( V_19 ) ;
F_16 ( V_11 , V_19 ) ;
}
struct V_24 * F_21 ( const char * V_25 )
{
int V_8 ;
struct V_10 * V_11 ;
struct V_24 * V_4 ;
struct V_5 * V_12 ;
V_12 = F_22 ( sizeof( * V_12 ) , V_26 ) ;
if ( ! V_12 ) {
V_8 = - V_27 ;
goto V_28;
}
V_4 = & V_12 -> V_4 ;
F_23 ( V_4 , V_25 , & V_29 ) ;
V_8 = F_24 ( V_30 , V_4 ) ;
if ( V_8 ) {
F_25 ( L_3 , V_25 ) ;
goto V_31;
}
V_11 = F_26 ( V_25 ) ;
if ( F_27 ( V_11 ) ) {
V_8 = F_28 ( V_11 ) ;
goto V_32;
}
V_12 -> V_11 = V_11 ;
return V_4 ;
V_32:
F_29 ( V_4 ) ;
V_31:
F_30 ( V_12 ) ;
V_28:
return F_31 ( V_8 ) ;
}
void F_32 ( struct V_24 * V_4 )
{
struct V_5 * V_12 ;
if ( ! V_4 )
return;
V_12 = F_2 ( V_4 , struct V_5 , V_4 ) ;
F_33 ( V_12 -> V_11 ) ;
F_29 ( & V_12 -> V_4 ) ;
F_30 ( V_12 ) ;
}
static T_1 F_34 ( struct V_2 * V_3 ,
const char * V_6 , T_2 V_7 )
{
T_4 V_33 ;
int V_8 ;
V_8 = F_35 ( V_6 , 0 , & V_33 ) ;
if ( V_8 )
return V_8 ;
F_1 ( V_3 ) -> V_19 -> V_34 = V_33 ;
return V_7 ;
}
static T_1 F_36 ( struct V_2 * V_3 ,
char * V_6 )
{
return sprintf ( V_6 , L_2 ,
F_1 ( V_3 ) -> V_19 -> V_34 ) ;
}
static void F_37 ( struct V_2 * V_3 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
F_38 ( V_20 -> V_19 ) ;
F_30 ( V_20 ) ;
}
static struct V_24 * F_39 ( struct V_24 * V_4 ,
const char * V_25 )
{
struct V_1 * V_20 ;
struct V_18 * V_19 ;
V_20 = F_22 ( sizeof( * V_20 ) , V_26 ) ;
if ( ! V_20 )
return F_31 ( - V_27 ) ;
F_23 ( & V_20 -> V_4 , V_25 , & V_35 ) ;
V_19 = F_40 ( V_4 -> V_36 . V_37 ) ;
if ( F_27 ( V_19 ) ) {
F_25 ( L_4 ) ;
return F_31 ( - V_14 ) ;
}
V_20 -> V_19 = V_19 ;
return & V_20 -> V_4 ;
}
static void F_41 ( struct V_24 * V_4 , struct V_2 * V_3 )
{
F_42 ( V_3 ) ;
}
struct V_24 * F_43 ( const char * V_25 )
{
struct V_24 * V_4 ;
V_4 = F_44 ( V_38 , V_25 ,
& V_39 ) ;
if ( F_27 ( V_4 ) )
F_25 ( L_5 ,
V_25 ) ;
return V_4 ;
}
void F_45 ( struct V_24 * V_4 )
{
if ( F_46 ( V_4 ) )
return;
F_47 ( V_4 ) ;
}
static int T_5 F_48 ( void )
{
int V_8 ;
struct V_24 * V_40 = & V_41 . V_42 ;
F_49 ( V_40 ) ;
V_8 = F_50 ( & V_41 ) ;
if ( V_8 ) {
F_25 ( L_6 ,
V_8 , V_40 -> V_36 . V_43 ) ;
goto V_28;
}
V_38 = F_44 ( V_40 , L_7 ,
& V_44 ) ;
if ( F_27 ( V_38 ) ) {
V_8 = F_28 ( V_38 ) ;
F_25 ( L_8 ,
V_8 ) ;
goto V_45;
}
V_30 =
F_44 ( V_40 , L_9 ,
& V_46 ) ;
if ( F_27 ( V_30 ) ) {
V_8 = F_28 ( V_30 ) ;
F_25 ( L_10 ,
V_8 ) ;
goto V_47;
}
return 0 ;
V_47:
F_47 ( V_38 ) ;
V_45:
F_51 ( & V_41 ) ;
V_28:
return V_8 ;
}
static void T_6 F_52 ( void )
{
F_47 ( V_30 ) ;
F_47 ( V_38 ) ;
F_51 ( & V_41 ) ;
}
